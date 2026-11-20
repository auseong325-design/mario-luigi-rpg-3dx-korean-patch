"""GUIDE worker (wave 5): static checks of every Korean-patch file on the guide path.

Read-only. Compares the installed patch (patch/00040000001CA900/romfs) with the original v1.2 files
(romfs_path(): romf2 over romfs) for the archives the guide pages load:
  Lyt/JP/MLyt.dat  MENU_GUIDE_JP_ja (pause-menu guide, bottom screen) and MENU_BG (top screen)
  Lyt/JP/KLyt.dat  KJ_GUIDE_JP_ja   (Bowser Jr. guide)
  Lyt/JP/BLyt.dat  btl_GUIDE_JP_ja  (in-battle guide)
  RO/MainMenu.cro, RO/MenuGuide.cro, RO/KJGuide.cro, Msg/JP_ja/Menu.msbt (page text)

Checks: BG4 container layout/alignment, unchanged-rebuild identity (rebuild_bg4(x, {}) == x), BLZ footers,
SARC header/SFAT/SFNT bytes, per-file offsets/sizes/alignment, BFLIM headers (format, size, flags, align,
data size) and the exact byte ranges that differ.

Usage: .venv\\Scripts\\python.exe work\\review\\guide_20261030\\check_guide_files.py > check_guide_files.txt
"""
from __future__ import annotations

import hashlib
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT / "scripts"))
from lib3dx import bg4_layout, bg4_plain, read_bg4, rebuild_bg4, romfs_path  # noqa: E402
from lytimg import parse_bflim, sarc_list  # noqa: E402

PATCH = ROOT / "patch" / "00040000001CA900" / "romfs"
TARGETS = {"MLyt": ["MENU_GUIDE_JP_ja", "MENU_BG"], "KLyt": ["KJ_GUIDE_JP_ja"], "BLyt": ["btl_GUIDE_JP_ja"]}
problems: list[str] = []


def sha(b: bytes) -> str:
    return hashlib.sha256(b).hexdigest()[:16].upper()


def diff_ranges(a: bytes, b: bytes) -> list[tuple[int, int]]:
    out, i, n = [], 0, min(len(a), len(b))
    while i < n:
        if a[i] != b[i]:
            j = i
            while j < n and a[j] != b[j]:
                j += 1
            out.append((i, j))
            i = j
        else:
            i += 1
    if len(a) != len(b):
        out.append((n, max(len(a), len(b))))
    return out


def merge(ranges, gap=16):
    out = []
    for s, e in ranges:
        if out and s - out[-1][1] <= gap:
            out[-1] = (out[-1][0], e)
        else:
            out.append((s, e))
    return out


def blz_footer(data: bytes):
    enc_and_hdr, inc_len = struct.unpack_from("<II", data, len(data) - 8)
    return enc_and_hdr >> 24, enc_and_hdr & 0xFFFFFF, inc_len


def sarc_meta(b: bytes):
    hdr_len, bom, size, data_off = struct.unpack_from("<HHII", b, 4)
    return {"hdr_len": hdr_len, "bom": bom, "size": size, "data_off": data_off}


def check_dat(dat: str, names: list[str]) -> None:
    orig = romfs_path(f"Lyt/JP/{dat}.dat").read_bytes()
    pat = (PATCH / f"Lyt/JP/{dat}.dat").read_bytes()
    print(f"\n=== Lyt/JP/{dat}.dat  orig {len(orig)} B sha {sha(orig)}  patch {len(pat)} B sha {sha(pat)}")
    lo, lp = bg4_layout(orig), bg4_layout(pat)
    print(f"  BG4 layout orig: data_start {lo.data_start:#x} align {lo.align} pad {lo.pad:#04x} tail {lo.tail}"
          f" | patch: data_start {lp.data_start:#x} align {lp.align} pad {lp.pad:#04x} tail {lp.tail}")
    if (lo.data_start, lo.align, lo.pad, lo.tail) != (lp.data_start, lp.align, lp.pad, lp.tail):
        problems.append(f"{dat}: BG4 packing differs")
    ident = rebuild_bg4(orig, {}) == orig
    print(f"  rebuild_bg4(orig, {{}}) == orig: {ident}")
    if not ident:
        problems.append(f"{dat}: unchanged rebuild is not identical")
    # header + name table must be identical except the offset/size words of each slot
    count = struct.unpack_from("<H", orig, 6)[0]
    head_o, head_p = bytearray(orig[:lo.data_start]), bytearray(pat[:lp.data_start])
    for n in range(count):
        for buf in (head_o, head_p):
            buf[16 + n * 14:16 + n * 14 + 8] = b"\0" * 8
    print(f"  header/name table identical apart from offset/size words: {head_o == head_p}")
    if head_o != head_p:
        problems.append(f"{dat}: BG4 header/name table differs")
    _, eo = read_bg4(orig)
    _, ep = read_bg4(pat)
    mis = [n for n in lp.order if (lp.table[n][0] & 0x7FFFFFFF) % 4]
    print(f"  patch entries not 4-aligned: {len(mis)} (orig align {lo.align})")
    if lo.align == 4 and mis:
        problems.append(f"{dat}: misaligned entries {mis}")
    changed = [i for i, (a, b) in enumerate(zip(eo, ep)) if not a.size_flag and bg4_plain(a) != bg4_plain(b)]
    print(f"  entries whose decompressed data changed: {len(changed)} of {sum(not e.size_flag for e in eo)}")
    for name in names:
        i = next(k for k, e in enumerate(eo) if e.name == name)
        a, b = eo[i], ep[i]
        so, sp = bg4_plain(a), bg4_plain(b)
        print(f"\n  -- #{i} {name}: compressed {a.compressed}  stored {len(a.data):#x} -> {len(b.data):#x}"
              f"  plain {len(so):#x} -> {len(sp):#x}  same plain bytes: {so == sp}")
        print(f"     stored offset {a.raw_offset & 0x7FFFFFFF:#x} -> {b.raw_offset & 0x7FFFFFFF:#x}"
              f" (patch offset % 4 = {(b.raw_offset & 0x7FFFFFFF) % 4}, % 0x80 = {(b.raw_offset & 0x7FFFFFFF) % 0x80:#x};"
              f" orig % 0x80 = {(a.raw_offset & 0x7FFFFFFF) % 0x80:#x})")
        if a.compressed:
            fo, fp = blz_footer(a.data), blz_footer(b.data)
            print(f"     BLZ footer (hdr_len, enc_len, inc_len) orig {fo} patch {fp};"
                  f" orig+inc = {len(a.data) + fo[2]:#x}, patch+inc = {len(b.data) + fp[2]:#x}")
            if len(b.data) + fp[2] != len(sp):
                problems.append(f"{name}: BLZ size fields inconsistent")
        if so == sp:
            continue
        mo, mp = sarc_meta(so), sarc_meta(sp)
        print(f"     SARC header orig {mo} patch {mp}")
        if mo != mp:
            problems.append(f"{name}: SARC header differs")
        fo_, fp_ = sarc_list(so), sarc_list(sp)
        same_tab = [(n, s, e) for n, s, e in fo_] == [(n, s, e) for n, s, e in fp_]
        print(f"     SFAT/SFNT region identical: {so[:mo['data_off']] == sp[:mp['data_off']]};"
              f" file names/offsets/sizes identical: {same_tab}; files {len(fo_)}")
        if not same_tab or so[:mo["data_off"]] != sp[:mp["data_off"]]:
            problems.append(f"{name}: SARC tables differ")
        # gaps between files (padding) must be identical
        ends = sorted((s, e) for _, s, e in fo_)
        gaps_same = all(so[e1:s2] == sp[e1:s2] for (s1, e1), (s2, e2) in zip(ends, ends[1:]))
        tail_same = so[ends[-1][1]:] == sp[ends[-1][1]:]
        print(f"     inter-file padding identical: {gaps_same}; tail identical: {tail_same}")
        if not (gaps_same and tail_same):
            problems.append(f"{name}: SARC padding differs")
        minal = min(((s - mo["data_off"]) & -(s - mo["data_off"])) if s > mo["data_off"] else 1 << 16
                    for n, s, e in fo_ if n.endswith(".bflim"))
        print(f"     smallest BFLIM data alignment inside SARC (relative to data start): {minal}")
        dr = merge(diff_ranges(so, sp))
        idx = {n: (s, e) for n, s, e in fo_}
        for n, (s, e) in sorted(idx.items(), key=lambda kv: kv[1][0]):
            if so[s:e] == sp[s:e]:
                continue
            io, ip = parse_bflim(so[s:e]), parse_bflim(sp[s:e])
            fto, ftp = so[s:e][-0x28:], sp[s:e][-0x28:]
            inside = [(a_ - s, b_ - s) for a_, b_ in dr if s <= a_ < e]
            pix_only = all(b_ <= io["dsz"] for _, b_ in inside)
            print(f"     {n:44s} {io['fmt']:6s} {io['w']}x{io['h']} fl{io['flags']} align {io['align']}"
                  f" dsz {io['dsz']:#x} | header(0x28) identical {fto == ftp} | changed bytes only in pixel"
                  f" data: {pix_only} ({sum(b_ - a_ for a_, b_ in inside)} B in {len(inside)} runs)")
            if io != ip or fto != ftp or not pix_only:
                problems.append(f"{name}/{n}: BFLIM header or non-pixel bytes changed")
        outside = [(a_, b_) for a_, b_ in dr if not any(s <= a_ < e for s, e in idx.values())]
        print(f"     differing byte runs outside file data: {len(outside)}")
        if outside:
            problems.append(f"{name}: bytes changed outside file data {outside[:4]}")


def check_plain(rel: str) -> None:
    o = romfs_path(rel).read_bytes()
    p = PATCH / rel
    if not p.exists():
        print(f"\n=== {rel}: not in the patch (original {len(o)} B sha {sha(o)})")
        return
    b = p.read_bytes()
    dr = merge(diff_ranges(o, b), gap=0)
    print(f"\n=== {rel}: orig {len(o)} B sha {sha(o)}  patch {len(b)} B sha {sha(b)}  differing runs {len(dr)}")
    for s, e in dr[:12]:
        print(f"     {s:#08x}-{e:#08x}: {o[s:e].hex()} -> {b[s:e].hex()}")


if __name__ == "__main__":
    for dat, names in TARGETS.items():
        check_dat(dat, names)
    for rel in ["RO/MenuGuide.cro", "RO/KJGuide.cro", "RO/MainMenu.cro"]:
        check_plain(rel)
    print("\nPROBLEMS:", problems if problems else "none")
