"""Rebuild the 7 message files of 3DX with the Korean translation (LayeredFS output).

  .venv\\Scripts\\python scripts\\build_patch.py --identity   rebuild WITHOUT translation; every file
                                                            must equal the original byte for byte
  .venv\\Scripts\\python scripts\\build_patch.py              apply work/ko_final.json and write
                                                            patch/00040000001CA900/romfs/Msg/JP_ja/*
  .venv\\Scripts\\python scripts\\build_patch.py --fonts      same, then build the Korean fonts
                                                            (scripts/build_font.py, extra args after --)

Files: Msg/JP_ja/FMsg.dat + BMsg.dat (BG4 archives, one MSBT per entry) and HugeBattle, InitLoad,
Item, Menu, MenuKJ .msbt. Message ids are the ones of scripts/extract_3dx_text.py
('FMsg/<entry>#<n>', 'BMsg/b_sys#<n>', 'Menu#<n>', ...). A message without a translation keeps
its original text (the 6 tag-only messages). work/ko_final.json is only read, never written.

After writing, every output file is parsed again and checked against the original: BG4 entry
order / names / hashes / flags / '(invalid)' filler entries, MSBT message count, labels, ATR1,
TSY1, all non-TXT2 sections, and the text of every message against the intended value.
A watchdog aborts the run after 300 s.
"""

from __future__ import annotations

import argparse
import faulthandler
import json
import struct
import sys
import time
from pathlib import Path

from lib3dx import MSG_BG4_FILES, MSG_MSBT_FILES, ROOT, TITLE_ID, read_bg4, read_msbt, romfs_path, write_msbt

faulthandler.dump_traceback_later(300, exit=True)

KO_FINAL = ROOT / "work" / "ko_final.json"
PATCH_ROMFS = ROOT / "patch" / TITLE_ID / "romfs"
ALL_FILES = MSG_BG4_FILES + MSG_MSBT_FILES


def source_id(rel: str, entry: str | None = None) -> str:
    """Same ids as extract_3dx_text.source_id: 'Msg/JP_ja/FMsg.dat', 'o_x' -> 'FMsg/o_x'."""
    stem = rel.rsplit("/", 1)[-1].split(".")[0]
    return f"{stem}/{entry}" if entry else stem


# --------------------------------------------------------------------- BG4 writer
def bg4_layout(orig: bytes) -> tuple[int, list[tuple[int, int]], list[int]]:
    """-> (data start, [(raw offset, raw size)] per table slot, real slots in data order).

    Checks the assumptions the writer relies on: data of the real entries is contiguous in
    offset order, starts at the header's data-start field and ends exactly at the end of file.
    """
    if orig[:4] != b"BG4\0":
        raise ValueError("not a BG4 archive")
    _version, count, data_start = struct.unpack_from("<HHI", orig, 4)
    table = [struct.unpack_from("<II", orig, 16 + n * 14) for n in range(count)]
    real = [n for n, (_o, s) in enumerate(table) if not s >> 31]
    order = sorted(real, key=lambda n: table[n][0] & 0x7FFFFFFF)
    pos = data_start
    for n in order:
        off, size = table[n]
        if off & 0x7FFFFFFF != pos:
            raise ValueError(f"BG4 entry #{n} is not contiguous (0x{off & 0x7FFFFFFF:X} != 0x{pos:X})")
        pos += size & 0x7FFFFFFF
    if pos != len(orig):
        raise ValueError(f"BG4 data ends at 0x{pos:X}, file at 0x{len(orig):X} (unexpected tail)")
    return data_start, table, order


def write_bg4(orig: bytes, replace: dict[int, bytes]) -> bytes:
    """Rebuild a BG4 archive, replacing the data of table slot n by replace[n].

    Header, entry order, names, hashes, flags and the '(invalid)' filler slots are copied from
    the original; only the offset/size fields of real entries change. Data keeps the original
    storage order, packed with no gaps and no tail padding (exactly like the original).
    """
    data_start, table, order = bg4_layout(orig)
    head = bytearray(orig[:data_start])
    body = bytearray()
    for n in order:
        off, size = table[n]
        start, length = off & 0x7FFFFFFF, size & 0x7FFFFFFF
        data = replace.get(n, orig[start:start + length])
        if n in replace and off >> 31:
            raise ValueError(f"BG4 slot #{n} is compressed; replacing it would need BLZ compression")
        if len(data) >= 0x80000000:
            raise ValueError("entry too large")
        struct.pack_into("<II", head, 16 + n * 14, (data_start + len(body)) | (off & 0x80000000),
                         len(data) | (size & 0x80000000))
        body += data
    return bytes(head + body)


# --------------------------------------------------------------------- build
def load_ko() -> dict[str, str]:
    ko = json.loads(KO_FINAL.read_text(encoding="utf-8"))
    if not isinstance(ko, dict):
        raise ValueError("work/ko_final.json must be an object {id: text}")
    return ko


def rebuild_msbt(data: bytes, sid: str, ko: dict[str, str] | None, used: set[str],
                 intended: dict[str, str]) -> bytes:
    doc = read_msbt(data)
    for m in doc.messages:
        mid = f"{sid}#{m.index}"
        if ko is not None and mid in ko:
            m.text = ko[mid]
            used.add(mid)
        intended[mid] = m.text
    return write_msbt(doc)


def build_all(ko: dict[str, str] | None) -> tuple[dict[str, bytes], dict[str, str], set[str]]:
    """-> ({rel path: new bytes}, {message id: intended text}, ids of ko applied)."""
    out: dict[str, bytes] = {}
    intended: dict[str, str] = {}
    used: set[str] = set()
    for rel in MSG_BG4_FILES:
        orig = romfs_path(rel).read_bytes()
        _ver, entries = read_bg4(orig)
        replace: dict[int, bytes] = {}
        for n, e in enumerate(entries):
            if e.size_flag or e.data[:8] != b"MsgStdBn":
                continue
            if e.compressed:
                raise ValueError(f"{rel}:{e.name} is compressed (not expected for Msg)")
            replace[n] = rebuild_msbt(e.data, source_id(rel, e.name), ko, used, intended)
        out[rel] = write_bg4(orig, replace)
    for rel in MSG_MSBT_FILES:
        out[rel] = rebuild_msbt(romfs_path(rel).read_bytes(), source_id(rel), ko, used, intended)
    return out, intended, used


# --------------------------------------------------------------------- verify
def _msbt_sections(data: bytes) -> dict[bytes, bytes]:
    return dict(read_msbt(data).sections)


def verify_msbt(orig: bytes, new: bytes, sid: str, intended: dict[str, str], problems: list[str]) -> int:
    a, b = read_msbt(orig), read_msbt(new)
    tag = sid
    if len(a.messages) != len(b.messages):
        problems.append(f"{tag}: message count {len(b.messages)} != {len(a.messages)}")
        return 0
    if a.header[:0x12] != b.header[:0x12] or a.header[0x16:] != b.header[0x16:]:
        problems.append(f"{tag}: MSBT header differs outside the size field")
    sa, sb = _msbt_sections(orig), _msbt_sections(new)
    if [m for m, _ in a.sections] != [m for m, _ in b.sections]:
        problems.append(f"{tag}: section order differs")
    for magic, body in sa.items():
        if magic != b"TXT2" and sb.get(magic) != body:
            problems.append(f"{tag}: section {magic.decode()} changed")
    for x, y in zip(a.messages, b.messages):
        mid = f"{sid}#{x.index}"
        if (x.label, x.attr, x.style, x.trailer) != (y.label, y.attr, y.style, y.trailer):
            problems.append(f"{mid}: label/ATR1/TSY1/trailer differs")
        if y.text != intended[mid]:
            problems.append(f"{mid}: text read back differs from the intended text")
    return len(b.messages)


def verify_all(built: dict[str, bytes], intended: dict[str, str]) -> tuple[list[str], int]:
    problems: list[str] = []
    checked = 0
    for rel in MSG_BG4_FILES:
        orig, new = romfs_path(rel).read_bytes(), built[rel]
        va, ea = read_bg4(orig)
        vb, eb = read_bg4(new)
        if va != vb or len(ea) != len(eb) or orig[4:16] != new[4:16]:
            problems.append(f"{rel}: BG4 header differs")
            continue
        # names region and hashes must be untouched; only offset/size of real entries may move
        data_start = struct.unpack_from("<I", orig, 8)[0]
        for n in range(len(ea)):
            if orig[16 + n * 14 + 8:16 + n * 14 + 14] != new[16 + n * 14 + 8:16 + n * 14 + 14]:
                problems.append(f"{rel}: slot #{n} hash/name changed")
        if orig[16 + len(ea) * 14:data_start] != new[16 + len(eb) * 14:data_start]:
            problems.append(f"{rel}: name table changed")
        for n, (x, y) in enumerate(zip(ea, eb)):
            if (x.name, x.name_hash, x.size_flag, x.compressed) != (y.name, y.name_hash, y.size_flag, y.compressed):
                problems.append(f"{rel}: slot #{n} entry differs")
            if x.size_flag:
                if (x.raw_offset, x.raw_size) != (y.raw_offset, y.raw_size):
                    problems.append(f"{rel}: filler slot #{n} changed")
                continue
            if x.data[:8] == b"MsgStdBn":
                checked += verify_msbt(x.data, y.data, source_id(rel, x.name), intended, problems)
            elif x.data != y.data:
                problems.append(f"{rel}: non-MSBT entry {x.name} changed")
        try:
            bg4_layout(new)
        except ValueError as exc:
            problems.append(f"{rel}: layout {exc}")
    for rel in MSG_MSBT_FILES:
        checked += verify_msbt(romfs_path(rel).read_bytes(), built[rel], source_id(rel), intended, problems)
    return problems, checked


# --------------------------------------------------------------------- commands
def cmd_identity() -> int:
    t0 = time.time()
    built, intended, _ = build_all(None)
    bad = 0
    for rel in ALL_FILES:
        orig = romfs_path(rel).read_bytes()
        same = built[rel] == orig
        bad += not same
        print(f"  {'OK  ' if same else 'DIFF'} {rel}: {len(orig):,} -> {len(built[rel]):,} bytes")
    problems, checked = verify_all(built, intended)
    print(f"identity: {len(ALL_FILES) - bad}/{len(ALL_FILES)} files byte-identical, "
          f"{checked} messages re-parsed, {len(problems)} problems, {time.time() - t0:.1f}s")
    for p in problems[:20]:
        print("   ", p)
    return 0 if not bad and not problems else 1


def cmd_build(out_root: Path) -> int:
    t0 = time.time()
    ko = load_ko()
    built, intended, used = build_all(ko)
    unknown = sorted(set(ko) - used)
    kept = sorted(mid for mid in intended if mid not in ko)
    out_dir = out_root / "Msg" / "JP_ja"
    out_dir.mkdir(parents=True, exist_ok=True)
    for rel in ALL_FILES:
        (out_root / rel).write_bytes(built[rel])
    # verify what is on disk, not what is in memory
    on_disk = {rel: (out_root / rel).read_bytes() for rel in ALL_FILES}
    problems, checked = verify_all(on_disk, intended)
    per_src: dict[str, list[int]] = {}
    for mid in intended:
        s = mid.split("/")[0].split("#")[0]
        c = per_src.setdefault(s, [0, 0])
        c[0] += 1
        c[1] += mid in ko
    print(f"wrote {len(ALL_FILES)} files -> {out_dir}")
    for rel in ALL_FILES:
        print(f"  {rel.rsplit('/', 1)[-1]:16s} {romfs_path(rel).stat().st_size:>10,} -> {len(on_disk[rel]):>10,} bytes")
    print("  messages per source (total / translated):",
          ", ".join(f"{s} {a}/{b}" for s, (a, b) in per_src.items()))
    print(f"ko_final: {len(ko)} ids, applied {len(used)}, unknown ids {len(unknown)}; "
          f"kept original text: {len(kept)} {kept[:8]}")
    print(f"verify: {checked} messages re-parsed from disk, {len(problems)} problems, {time.time() - t0:.1f}s")
    for p in problems[:30]:
        print("   ", p)
    for u in unknown[:10]:
        print("    unknown id:", u)
    return 0 if not problems and not unknown else 1


def main(argv: list[str] | None = None) -> int:
    argv = sys.argv[1:] if argv is None else argv
    font_args: list[str] = []
    if "--" in argv:
        k = argv.index("--")
        argv, font_args = argv[:k], argv[k + 1:]
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--identity", action="store_true", help="rebuild without translation and compare")
    ap.add_argument("--fonts", action="store_true", help="also run scripts/build_font.py")
    ap.add_argument("--out", type=Path, default=PATCH_ROMFS, help="romfs output root")
    a = ap.parse_args(argv)
    a.out = a.out.resolve()
    if a.identity:
        return cmd_identity()
    rc = cmd_build(a.out)
    if a.fonts:
        import build_font
        rc |= build_font.main(font_args + ["--out", str(a.out)])
    return rc


if __name__ == "__main__":
    sys.exit(main())
