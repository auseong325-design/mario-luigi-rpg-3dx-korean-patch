"""Helpers for the Korean DS release of Mario & Luigi RPG3 (game code CLJK).

Formats follow 8y8x/mlbis-dumper (index.js: unpackSegmentedFile, fonts.standard,
fonts.glyphs2Bit, bisUnicode):

* Segmented files: u32 offset table; the first offset marks where data starts.
* Fonts: u32 charmap_size, then an unsorted offset table whose first segment is the
  charmap (big-endian s16 glyph id per code, -1 = absent; glyph id = table<<8 | index)
  followed by glyph tables. Glyph table: byte0 = (w/4)<<4 | (h/4), byte3 = count/8,
  then widths (nibbles when w <= 16), then 2bpp glyphs in 8x4 column blocks.
* Text: 0xFF introduces a control code; lead bytes 0xF9-0xFE start a 2-byte code that
  indexes the *replacement* font (FE->0x000, FD->0x100 ... F9->0x500); any other byte
  indexes the main font directly.
"""

from __future__ import annotations

import struct
from dataclasses import dataclass
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
STD = ROOT / "work" / "nds_kr" / "data"          # mnltools unpack of the Korean ROM
DATA = STD / "data"
ARM9 = STD / "arm9.dec.bin"
MAIN_FONT_RANGE = (0x43D90, 0x462D8)             # CLJK normal font inside arm9
FEVENT_HEADER_OVERLAY3 = 0xC8AC                  # CLJK (same as US/EU)
KO_TEXT_COLUMN = 66                              # 'CJK' text column in language tables


def overlay(n: int) -> bytes:
    return (STD / "overlay.dec" / f"overlay_{n:04d}.dec.bin").read_bytes()


def segments32(dat: bytes) -> list[bytes]:
    """unpackSegmented32: offsets until the first segment start; last runs to EOF."""
    if not dat:
        return []
    end = struct.unpack_from("<I", dat, 0)[0]
    offs = [struct.unpack_from("<I", dat, o)[0] for o in range(0, end, 4)]
    return [dat[a:b] for a, b in zip(offs, offs[1:] + [len(dat)])]


def segmented_file(header: bytes, header_offset: int, file: bytes) -> list[bytes]:
    """unpackSegmentedFile: size-prefixed offset table stored at header[header_offset]."""
    if len(header) <= header_offset:
        return []
    size = struct.unpack_from("<I", header, header_offset)[0]
    offs = [struct.unpack_from("<I", header, header_offset + o)[0] for o in range(4, size, 4)]
    return [file[a:b] for a, b in zip(offs, offs[1:] + [len(file)])]


# ----------------------------------------------------------------------------- fonts
@dataclass
class Glyph:
    width: int          # cell width
    height: int
    advance: int        # 'actual width' + 1
    pixels: list[int]   # row-major, 0 = empty, 1 = shade, 2 = ink


def _glyphs_2bit(dat: bytes, w: int, h: int, count: int) -> list[list[int]]:
    glyphs, o = [], 0
    for _ in range(count):
        bmp = [0] * (w * h)
        for bx in range(0, w, 8):
            cw = min(8, w - bx)
            for by in range(0, h, 4):
                alpha_o, shade_o = o, o + (cw >> 1)
                o += cw
                bit = 0
                for x in range(cw):
                    for y in range(4):
                        a = dat[alpha_o + (bit >> 3)] & (1 << (bit & 7)) if alpha_o + (bit >> 3) < len(dat) else 0
                        s = dat[shade_o + (bit >> 3)] & (1 << (bit & 7)) if shade_o + (bit >> 3) < len(dat) else 0
                        if by + y < h:
                            bmp[(by + y) * w + bx + x] = (1 if s else 2) if a else 0
                        bit += 1
        glyphs.append(bmp)
    return glyphs


def segments_unsorted(dat: bytes, o: int = 0) -> list[bytes]:
    """unpackSegmentedUnsorted: read offsets until reaching the lowest offset seen."""
    lo, offs = float("inf"), []
    while o < len(dat) and o < lo:
        off = struct.unpack_from("<I", dat, o)[0]
        offs.append(off)
        lo = min(lo, off)
        o += 4
    order = sorted(range(len(offs)), key=lambda k: offs[k])
    until = [len(dat)] * len(offs)
    for a, b in zip(order, order[1:]):
        until[a] = offs[b]
    return [dat[offs[k]:until[k]] for k in range(len(offs))]


def parse_font(dat: bytes) -> dict[int, Glyph]:
    """Return {code: Glyph} for a 'standard' BIS font blob."""
    if len(dat) < 8:
        return {}
    charmap_size = struct.unpack_from("<I", dat, 0)[0]
    segs = segments_unsorted(dat, 4)
    charmap, tables = segs[0], segs[1:]
    by_glyph: dict[int, Glyph] = {}
    for ti, t in enumerate(tables):
        if len(t) < 4:
            continue
        gw, gh, n = (t[0] >> 4) * 4, (t[0] & 0xF) * 4, t[3] * 8
        if gw == 0 or gh == 0:
            continue
        widths, o = [], 4
        if gw <= 16:
            for _ in range(0, n, 2):
                c = t[o]
                o += 1
                widths += [c & 0xF, c >> 4]
        else:
            widths = list(t[o:o + n])
            o += n
        bytes_per_glyph = (gw * gh) // 4
        real_n = min(n, (len(t) - o) // bytes_per_glyph)
        for j, px in enumerate(_glyphs_2bit(t[o:], gw, gh, real_n)):
            by_glyph[(ti << 8) | j] = Glyph(gw, gh, widths[j] + 1, px)
    out: dict[int, Glyph] = {}
    for code in range(min(charmap_size, len(charmap)) // 2):
        gid = struct.unpack_from(">h", charmap, code * 2)[0]
        if gid != -1 and gid in by_glyph:
            out[code] = by_glyph[gid]
    return out


def main_font() -> dict[int, Glyph]:
    a, b = MAIN_FONT_RANGE
    return parse_font(ARM9.read_bytes()[a:b])


# ----------------------------------------------------------------------------- text
LEAD_PAGE = {0xFE: 0x000, 0xFD: 0x100, 0xFC: 0x200, 0xFB: 0x300, 0xFA: 0x400, 0xF9: 0x500}
# control code -> number of argument bytes (bisUnicode/fonts.textbox + byte statistics
# over all Korean FEvent text: 01/0A/0B/0C/10/11/FE take one byte, 0F takes two)
CTRL_ARGS = {0x00: 0, 0x01: 1, 0x0A: 1, 0x0B: 1, 0x0C: 1, 0x0F: 2, 0x10: 1, 0x11: 1, 0xFE: 1}


def tokenize(raw: bytes) -> list[tuple[str, int, bytes]]:
    """Split DS text into tokens: ('main', code), ('rep', code), ('ctrl', code, args)."""
    toks: list[tuple[str, int, bytes]] = []
    i, n = 0, len(raw)
    while i < n:
        b = raw[i]
        i += 1
        if b == 0xFF and i < n:
            c = raw[i]
            i += 1
            k = CTRL_ARGS.get(c, 0)
            toks.append(("ctrl", c, raw[i:i + k]))
            i += k
        elif b in LEAD_PAGE and i < n:
            toks.append(("rep", LEAD_PAGE[b] | raw[i], b""))
            i += 1
        else:
            toks.append(("main", b, b""))
    return toks
