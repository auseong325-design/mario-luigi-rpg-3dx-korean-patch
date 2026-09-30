"""Shared helpers for Mario & Luigi RPG3 DX (3DS) data formats.

- BG4 archives (AlphaDream container used for Msg/FEvent/Lyt/Obj/...)
- MSBT text: self-contained lossless codec. LBL1/ATR1/TSY1 are kept byte-exact;
  only TXT2 is rebuilt, so decode -> encode reproduces the original file.

Text syntax (what translators see):
  plain text + real newlines
  [Ruby base;ruby]        furigana over `base` (drop it in Korean, keep the word)
  [Color #RRGGBB(AA)]     text colour change (keep around the equivalent Korean words)
  [Size N]  [Font HEX]  [Next] (page break)
  [GGGG:TTTT:HEX ...]     any other control tag, copied verbatim
  [/GGGG:TTTT]            closing tag
  [U+XXXX]                a single special character (button icons, literal brackets)
"""

from __future__ import annotations

import json
import re
import struct
import sys
import typing
from dataclasses import dataclass, field
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
ROMFS_BASE = ROOT / "romfs"   # v1.0 base game
ROMFS_UPDATE = ROOT / "romf2"  # v1.2 update (only changed files)
TITLE_ID = "00040000001CA900"
# Advance widths for a checkout without the game files (the cloud copy of this repository has no
# romfs/). `python scripts/lib3dx.py --export-font-metrics` writes them from the real fonts: numbers
# only (no glyph data), and only for the characters merge_ko measures (it counts kana/kanji as 16).
FONT_METRICS = ROOT / "work" / "font_metrics.json"
METRIC_FONTS = ["Msg/JP_ja/font.bffnt"]
_KANA_KANJI = re.compile(r"[\u3040-\u30ff\u4e00-\u9fff]")


def romfs_path(rel: str) -> Path:
    """Resolve a RomFS path the way the game does with update 1.2 installed."""
    upd = ROMFS_UPDATE / rel
    return upd if upd.exists() else ROMFS_BASE / rel


# --------------------------------------------------------------------- BG4
@dataclass
class BG4Entry:
    name: str
    data: bytes          # stored bytes (still BLZ-compressed when `compressed`)
    compressed: bool
    name_hash: int
    size_flag: bool      # bit31 of the size field (set on "(invalid)" padding entries)
    raw_offset: int
    raw_size: int


def read_bg4(data: bytes) -> tuple[int, list[BG4Entry]]:
    if data[:4] != b"BG4\0":
        raise ValueError("not a BG4 archive")
    version, count, _meta = struct.unpack_from("<HHI", data, 4)
    names_base = 16 + count * 14
    entries: list[BG4Entry] = []
    for n in range(count):
        off, size, name_hash, name_off = struct.unpack_from("<IIIH", data, 16 + n * 14)
        end = data.find(b"\0", names_base + name_off)
        name = data[names_base + name_off:end].decode("ascii", "replace") if end >= 0 else f"#{n}"
        start = off & 0x7FFFFFFF
        entries.append(BG4Entry(name, data[start:start + (size & 0x7FFFFFFF)], bool(off >> 31),
                                name_hash, bool(size >> 31), off, size))
    return version, entries


def blz_decompress(data: bytes) -> bytes:
    """Nintendo 'backwards LZ77' (BLZ) as used for BG4 entries flagged compressed."""
    enc_and_hdr, inc_len = struct.unpack_from("<II", data, len(data) - 8)
    hdr_len, enc_len = enc_and_hdr >> 24, enc_and_hdr & 0xFFFFFF
    out = bytearray(data) + bytearray(inc_len)
    src, dst, end = len(data) - hdr_len, len(out), len(data) - enc_len
    while src > end:
        src -= 1
        flags = out[src]
        for _ in range(8):
            if src <= end:
                break
            if flags & 0x80:
                src -= 2
                b1, b2 = out[src + 1], out[src]
                length, disp = (b1 >> 4) + 3, (((b1 & 0x0F) << 8) | b2) + 3
                for _ in range(length):
                    dst -= 1
                    out[dst] = out[dst + disp]
            else:
                src -= 1
                dst -= 1
                out[dst] = out[src]
            flags = (flags << 1) & 0xFF
    return bytes(out)


def blz_compress(data: bytes) -> bytes:
    """Inverse of blz_decompress (ndspy 'code compression'). Refuses input that does not compress
    (ndspy would then store it raw with a zero footer, which the BG4 'compressed' flag cannot mean)
    and verifies the round trip."""
    from ndspy.codeCompression import compress
    out = compress(bytes(data))
    if len(out) < 8 or struct.unpack_from("<I", out, len(out) - 4)[0] == 0:
        raise ValueError("BLZ: data did not compress")
    if blz_decompress(out) != data:
        raise ValueError("BLZ: round trip failed")
    return out


class BG4Layout(typing.NamedTuple):
    data_start: int
    table: list            # [(raw offset, raw size)] per table slot
    order: list            # real slots in data order
    align: int             # 4 when every entry starts 4-aligned, else 1
    pad: int               # byte used for alignment gaps (0xFF in Obj/JP/FUI.dat)
    tail: bool             # the original ends with alignment padding after the last entry


def bg4_layout(orig: bytes) -> BG4Layout:
    """Describe how a BG4 archive packs its data, and check what rebuild_bg4 relies on: entries in
    offset order, starting at the header's data-start field, separated only by alignment padding
    (one pad byte value), ending at the end of the file or at its alignment padding."""
    if orig[:4] != b"BG4\0":
        raise ValueError("not a BG4 archive")
    _version, count, data_start = struct.unpack_from("<HHI", orig, 4)
    table = [struct.unpack_from("<II", orig, 16 + n * 14) for n in range(count)]
    real = [n for n, (_o, s) in enumerate(table) if not s >> 31]
    order = sorted(real, key=lambda n: table[n][0] & 0x7FFFFFFF)
    align = 4 if data_start % 4 == 0 and all((table[n][0] & 0x7FFFFFFF) % 4 == 0 for n in order) else 1
    pads: set[int] = set()
    pos = data_start
    for n in order:
        off, size = table[n]
        start = off & 0x7FFFFFFF
        if start != pos:
            if not (align > 1 and 0 < start - pos < align):
                raise ValueError(f"BG4 entry #{n} is not contiguous (0x{start:X} != 0x{pos:X})")
            pads.update(orig[pos:start])
        pos = start + (size & 0x7FFFFFFF)
    tail = len(orig) - pos
    if tail:
        if not (align > 1 and tail < align and len(orig) % align == 0):
            raise ValueError(f"BG4 data ends at 0x{pos:X}, file at 0x{len(orig):X} (unexpected tail)")
        pads.update(orig[pos:])
    if len(pads) > 1:
        raise ValueError(f"BG4 alignment padding uses several byte values {sorted(pads)}")
    return BG4Layout(data_start, table, order, align, pads.pop() if pads else 0, bool(tail))


def rebuild_bg4(orig: bytes, replace: dict[int, bytes]) -> bytes:
    """Rebuild a BG4 archive with replace[n] = the new PLAIN (decompressed) data of table slot n.

    Slots flagged compressed are BLZ-compressed again; every other slot keeps its original bytes.
    Header, entry order, names, hashes, flags and the '(invalid)' filler slots are copied from the
    original; only offset/size fields change. Data keeps the original storage order and the
    original packing (contiguous, or 4-aligned with the original pad byte), and a tail pad only when
    the original has one -- so rebuild_bg4(x, {}) == x.
    """
    lay = bg4_layout(orig)
    head = bytearray(orig[:lay.data_start])
    body = bytearray()
    pad = bytes([lay.pad])
    for n in lay.order:
        off, size = lay.table[n]
        start, length = off & 0x7FFFFFFF, size & 0x7FFFFFFF
        if n in replace:
            data = blz_compress(replace[n]) if off >> 31 else bytes(replace[n])
        else:
            data = orig[start:start + length]
        while (lay.data_start + len(body)) % lay.align:
            body += pad
        if len(data) >= 0x80000000:
            raise ValueError("entry too large")
        struct.pack_into("<II", head, 16 + n * 14, (lay.data_start + len(body)) | (off & 0x80000000),
                         len(data) | (size & 0x80000000))
        body += data
    if lay.tail:
        while (lay.data_start + len(body)) % lay.align:
            body += pad
    return bytes(head + body)


def bg4_plain(e: BG4Entry) -> bytes:
    """Decompressed data of a BG4 entry."""
    return blz_decompress(e.data) if e.compressed else e.data


# --------------------------------------------------------------------- MSBT text codec
_TOKEN = re.compile(r"\[([^\[\]]*)\]")


def _is_special(ch: str) -> bool:
    o = ord(ch)
    return ch in "[]" or 0xE000 <= o <= 0xF8FF or (o < 0x20 and ch != "\n")


def decode_text(raw: bytes) -> tuple[str, bytes]:
    """UTF-16LE string (up to NUL) -> (text with tags, trailing bytes after the NUL)."""
    out: list[str] = []
    i, n = 0, len(raw)
    while True:
        if i + 2 > n:
            raise ValueError("unterminated MSBT string")
        (cu,) = struct.unpack_from("<H", raw, i)
        i += 2
        if cu == 0:
            return "".join(out), raw[i:]
        if cu == 0x0E:
            group, tag, size = struct.unpack_from("<HHH", raw, i)
            args = raw[i + 6:i + 6 + size]
            i += 6 + size
            if (group, tag) == (0, 0) and size >= 4:
                base_len, ruby_len = struct.unpack_from("<HH", args, 0)
                base = raw[i:i + base_len]
                if size == 4 + ruby_len and base_len % 2 == 0 and ruby_len % 2 == 0 and i + base_len <= n:
                    base_txt = base.decode("utf-16-le")
                    ruby_txt = args[4:].decode("utf-16-le")
                    if not any(c in base_txt + ruby_txt for c in "[];\x00\x0e\x0f"):
                        out.append(f"[Ruby {base_txt};{ruby_txt}]")
                        i += base_len
                        continue
            if (group, tag) == (0, 3) and size == 4:
                out.append(f"[Color #{args[:3].hex().upper()}]" if args[3] == 0xFF
                           else f"[Color #{args.hex().upper()}]")
                continue
            if (group, tag, size) == (0, 4, 0):
                out.append("[Next]")
                continue
            out.append(f"[{group:04X}:{tag:04X}:{args.hex(' ').upper()}]")
            continue
        if cu == 0x0F:
            group, tag = struct.unpack_from("<HH", raw, i)
            i += 4
            out.append(f"[/{group:04X}:{tag:04X}]")
            continue
        if 0xD800 <= cu <= 0xDBFF:  # surrogate pair
            (lo,) = struct.unpack_from("<H", raw, i)
            i += 2
            out.append(bytes(struct.pack("<HH", cu, lo)).decode("utf-16-le"))
            continue
        ch = chr(cu)
        out.append(f"[U+{cu:04X}]" if _is_special(ch) else ch)


def encode_text(text: str, trailer: bytes = b"") -> bytes:
    """Inverse of decode_text. Raises ValueError on a malformed tag."""
    buf = bytearray()
    pos = 0
    for m in _TOKEN.finditer(text):
        buf += text[pos:m.start()].encode("utf-16-le")
        buf += _encode_tag(m.group(1))
        pos = m.end()
    rest = text[pos:]
    if "[" in rest or "]" in rest:
        raise ValueError(f"unbalanced bracket in text: {rest!r}")
    buf += rest.encode("utf-16-le")
    buf += b"\x00\x00"
    return bytes(buf) + trailer


def _encode_tag(tag: str) -> bytes:
    if tag.startswith("U+"):
        return struct.pack("<H", int(tag[2:], 16))
    if tag.startswith("Ruby "):
        base, ruby = tag[5:].split(";", 1)
        rb, bb = ruby.encode("utf-16-le"), base.encode("utf-16-le")
        return struct.pack("<HHHHHH", 0x0E, 0, 0, 4 + len(rb), len(bb), len(rb)) + rb + bb
    if tag.startswith("Color #"):
        rgba = bytes.fromhex(tag[7:])
        if len(rgba) == 3:
            rgba += b"\xff"
        if len(rgba) != 4:
            raise ValueError(f"bad colour tag [{tag}]")
        return struct.pack("<HHHH", 0x0E, 0, 3, 4) + rgba
    if tag == "Next":
        return struct.pack("<HHHH", 0x0E, 0, 4, 0)
    if tag.startswith("/"):
        g, t = tag[1:].split(":")
        return struct.pack("<HHH", 0x0F, int(g, 16), int(t, 16))
    parts = tag.split(":")
    if len(parts) == 3 and len(parts[0]) == 4 and len(parts[1]) == 4:
        args = bytes.fromhex(parts[2])
        return struct.pack("<HHHH", 0x0E, int(parts[0], 16), int(parts[1], 16), len(args)) + args
    raise ValueError(f"unknown tag [{tag}]")


# --------------------------------------------------------------------- MSBT container
@dataclass
class Message:
    index: int
    label: str | None
    text: str
    attr: str          # ATR1 record, hex
    style: int | None  # TSY1 value
    trailer: bytes = b""


@dataclass
class Msbt:
    header: bytes
    sections: list[tuple[bytes, bytes]]  # (magic, body) in file order; TXT2 body rebuilt on write
    pad_byte: int
    messages: list[Message] = field(default_factory=list)


def read_msbt(data: bytes) -> Msbt:
    if data[:8] != b"MsgStdBn" or data[8:10] != b"\xff\xfe":
        raise ValueError("not a little-endian MSBT")
    n_sec = struct.unpack_from("<H", data, 0x0E)[0]
    p, sections, pad_byte = 0x20, [], 0
    for _ in range(n_sec):
        magic, size = data[p:p + 4], struct.unpack_from("<I", data, p + 4)[0]
        body = data[p + 16:p + 16 + size]
        end = (p + 16 + size + 15) & ~15
        if end > p + 16 + size:
            pad_byte = data[p + 16 + size]
        sections.append((magic, body))
        p = end
    sec = dict(sections)
    txt = sec[b"TXT2"]
    count = struct.unpack_from("<I", txt, 0)[0]
    offs = list(struct.unpack_from(f"<{count}I", txt, 4))
    bounds = sorted(set(offs)) + [len(txt)]
    labels: dict[int, str] = {}
    if b"LBL1" in sec:
        lbl = sec[b"LBL1"]
        for b in range(struct.unpack_from("<I", lbl, 0)[0]):
            cnt, off = struct.unpack_from("<II", lbl, 4 + b * 8)
            for _ in range(cnt):
                ln = lbl[off]
                name = lbl[off + 1:off + 1 + ln].decode("ascii")
                labels[struct.unpack_from("<I", lbl, off + 1 + ln)[0]] = name
                off += 1 + ln + 4
    attrs: list[str] = []
    if b"ATR1" in sec:
        a = sec[b"ATR1"]
        acount, asize = struct.unpack_from("<II", a, 0)
        attrs = [a[8 + k * asize:8 + (k + 1) * asize].hex() for k in range(acount)]
    styles: list[int] = []
    if b"TSY1" in sec:
        t = sec[b"TSY1"]
        styles = list(struct.unpack_from(f"<{len(t) // 4}i", t, 0))
    doc = Msbt(data[:0x20], sections, pad_byte)
    for k, off in enumerate(offs):
        span = txt[off:bounds[bounds.index(off) + 1]]
        text, trailer = decode_text(span)
        doc.messages.append(Message(k, labels.get(k), text, attrs[k] if k < len(attrs) else "",
                                    styles[k] if k < len(styles) else None, trailer))
    return doc


def write_msbt(doc: Msbt) -> bytes:
    count = len(doc.messages)
    table, blob = bytearray(struct.pack("<I", count)), bytearray()
    base = 4 + 4 * count
    for m in doc.messages:
        table += struct.pack("<I", base + len(blob))
        blob += encode_text(m.text, m.trailer)
    txt2 = bytes(table + blob)
    out = bytearray(doc.header)
    for magic, body in doc.sections:
        if magic == b"TXT2":
            body = txt2
        out += magic + struct.pack("<I", len(body)) + b"\x00" * 8 + body
        out += bytes([doc.pad_byte]) * ((-len(out)) % 16)
    struct.pack_into("<I", out, 0x12, len(out))
    return bytes(out)


# All text containers of the game (v1.2 view). BG4 archives hold one MSBT per entry.
MSG_BG4_FILES = ["Msg/JP_ja/FMsg.dat", "Msg/JP_ja/BMsg.dat"]
MSG_MSBT_FILES = ["Msg/JP_ja/HugeBattle.msbt", "Msg/JP_ja/InitLoad.msbt", "Msg/JP_ja/Item.msbt",
                  "Msg/JP_ja/Menu.msbt", "Msg/JP_ja/MenuKJ.msbt"]


def iter_all_msbt() -> typing.Iterator[tuple[str, bytes]]:
    """Yield (source_key, msbt_bytes); key is 'path' or 'path:bg4_entry_name'."""
    for rel in MSG_BG4_FILES:
        _, entries = read_bg4(romfs_path(rel).read_bytes())
        for e in entries:
            if e.data[:8] == b"MsgStdBn":
                yield f"{rel}:{e.name}", e.data
    for rel in MSG_MSBT_FILES:
        yield rel, romfs_path(rel).read_bytes()



# --------------------------------------------------------------------- BFFNT (read-only helpers)
def bffnt_advances(rel: str = "Msg/JP_ja/font.bffnt") -> dict[str, int]:
    """char -> advance width (px) for every character mapped in a 3DS BFFNT.

    Follows FINF pointers (ptrWidth/ptrMap point at section data, i.e. magic + 8)
    through the CWDH and CMAP chains instead of searching for magics.
    Without the game files it falls back to advances_without_romfs().
    """
    path = romfs_path(rel)
    if not path.exists():
        return advances_without_romfs(rel)
    d = path.read_bytes()
    finf = struct.unpack_from("<H", d, 6)[0]  # header size = FINF offset
    if d[finf:finf + 4] != b"FINF":
        raise ValueError("FINF not found")
    # FINF: magic, size, fontType, height, width, ascent, lineFeed(u16), alterChar(u16),
    #       defaultWidth(3), encoding, ptrGlyph @+20, ptrWidth @+24, ptrMap @+28
    ptr_width, ptr_map = struct.unpack_from("<II", d, finf + 24)
    widths: dict[int, int] = {}
    p = ptr_width
    while p:
        start, end, nxt = struct.unpack_from("<HHI", d, p)
        for i in range(end - start + 1):
            _left, _gw, cw = struct.unpack_from("<bBB", d, p + 8 + 3 * i)
            widths[start + i] = cw
        p = nxt
    cmap: dict[int, int] = {}
    p = ptr_map
    while p:
        cs, ce, method, _res, nxt = struct.unpack_from("<HHHHI", d, p)
        body = p + 12
        if method == 0:  # direct
            base = struct.unpack_from("<H", d, body)[0]
            for c in range(cs, ce + 1):
                cmap[c] = base + c - cs
        elif method == 1:  # table
            for i, c in enumerate(range(cs, ce + 1)):
                g = struct.unpack_from("<H", d, body + 2 * i)[0]
                if g != 0xFFFF:
                    cmap[c] = g
        else:  # scan
            n = struct.unpack_from("<H", d, body)[0]
            for i in range(n):
                c, g = struct.unpack_from("<HH", d, body + 2 + 4 * i)
                cmap[c] = g
        p = nxt
    return {chr(c): widths.get(g, 16) for c, g in cmap.items() if not 0xD800 <= c <= 0xDFFF}


# Guessed advances of the ASCII glyphs font.bffnt has (proportional, about 9-14 px; the space's 5 px
# is known). Only used when neither the game files nor work/font_metrics.json are present.
_EST_ASCII = {" ": 5, ".": 5, "'": 4, "(": 7, ")": 7, "[": 7, "]": 7, "{": 7, "}": 7, "/": 9,
              "?": 10, "&": 13, "+": 12, "=": 12,
              **{c: 10 for c in "0123456789"},
              **{c: 12 for c in "ABCDEFGHIJKLNOPQRSTUVXYZ"}, "M": 14, "W": 14,
              **{c: 10 for c in "abcdefghijklnopqrstuvxyz"}, "m": 13, "w": 13}
_estimate_warned: set[str] = set()


def advances_without_romfs(rel: str) -> dict[str, int]:
    """bffnt_advances() for a checkout without the game files.

    Exact when work/font_metrics.json has the font (export it where the game files are). Otherwise
    an estimate, with a warning: every character the Japanese script shows is in the font, the
    full-width ones at 16 px (text/jp's widest lines give the recorded limits 368 px for b_sys style
    13 and 405 px for style 11 this way), ASCII at the guesses above. Line widths near a limit then
    need the exact check on a machine with the game files.
    """
    if FONT_METRICS.exists():
        table = json.loads(FONT_METRICS.read_text(encoding="utf-8")).get("fonts", {}).get(rel)
        if table:
            return dict(table)
    if rel not in _estimate_warned:
        _estimate_warned.add(rel)
        print(f"lib3dx: {rel} is not here and not in {FONT_METRICS.relative_to(ROOT).as_posix()}: "
              "ESTIMATED advance widths (ASCII guessed); re-check line widths where the game files are",
              file=sys.stderr)
    shown: set[str] = set()
    for f in (ROOT / "text" / "jp").glob("*.json"):
        for m in json.loads(f.read_text(encoding="utf-8"))["messages"]:
            shown.update(re.sub(r"\[[^\]]*\]", "", m["jp"]))
    est = {c: 8 if "\uff61" <= c <= "\uff9f" else 16
           for c in shown if c > "\x7f" and not _KANA_KANJI.match(c)}
    est.update(_EST_ASCII)
    return est


def export_font_metrics() -> None:
    """Write FONT_METRICS from the game fonts: {"fonts": {rel: {char: advance}}} without kana/kanji."""
    fonts = {}
    for rel in METRIC_FONTS:
        if not romfs_path(rel).exists():
            raise SystemExit(f"{rel} not found: export the metrics where the game files are")
        fonts[rel] = {c: w for c, w in sorted(bffnt_advances(rel).items()) if not _KANA_KANJI.match(c)}
    FONT_METRICS.write_text(json.dumps({
        "note": "advance widths (px) of the 3DX message fonts for checkouts without the game files; "
                "written by scripts/lib3dx.py --export-font-metrics; kana/kanji left out (merge_ko counts them as 16)",
        "fonts": fonts}, ensure_ascii=False, indent=0), encoding="utf-8")
    print(f"wrote {FONT_METRICS} ({', '.join(f'{r}: {len(t)} chars' for r, t in fonts.items())})")


if __name__ == "__main__":
    import argparse
    ap = argparse.ArgumentParser(description="lib3dx helpers")
    ap.add_argument("--export-font-metrics", action="store_true",
                    help="write work/font_metrics.json from the game fonts (for cloud checkouts)")
    if ap.parse_args().export_font_metrics:
        export_font_metrics()
    else:
        ap.print_help()
