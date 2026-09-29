"""3DS BFFNT ("FFNT" v4.0, as used by Mario & Luigi RPG3 DX) reader/writer + sheet codec.

File layout (all little endian), every section 4-byte aligned:
  header  0x14  'FFNT', BOM FEFF, header size, version, file size, block count(u16), reserved(u16)
  FINF    0x20  fontType, height, width, ascent, lineFeed(u16), alterCharIndex(u16),
                defaultWidth(left s8, glyph u8, char u8), encoding,
                ptrGlyph / ptrWidth / ptrMap  (= target section offset + 8)
  TGLP          cellW, cellH, numSheets(u8), maxCharW, sheetSize(u32), baseline(u16), format(u16),
                cols(u16), rows(u16), sheetW(u16), sheetH(u16), sheetDataOffset(u32, absolute)
                ... padding up to sheetDataOffset, then numSheets * sheetSize bytes of texture
  CWDH*         start(u16), end(u16), next(u32 ptr), (left s8, glyph u8, char u8) * (end-start+1)
  CMAP*         codeBegin(u16), codeEnd(u16), method(u16), reserved(u16), next(u32 ptr), payload
                method 0 direct: base glyph(u16)  | 1 table: glyph(u16) per code, 0xFFFF = none
                method 2 scan: count(u16), (code u16, glyph u16) * count, sorted by code

Glyph g lives on sheet g // (cols*rows), cell c = g % (cols*rows), at column c % cols and
row c // cols; the cell's pixels start at x = col*(cellW+1)+1, y = row*(cellH+1)+1 (1 px grid).

Sheets are native 3DS textures: 8x8 tiles in row order (first tile = top-left of the sheet as
the glyph grid sees it), Morton (Z) order inside a tile. Format 11 = A4 (4-bit alpha, low
nibble = first pixel). decode_sheet/encode_sheet convert to/from a numpy array (h, w) of 0..15
values in which glyph 0 sits at the top-left, upright (verified against the game's fonts).

parse(build(x)) is lossless and build(parse(data)) == data for the game's fonts
(checked by scripts/build_font.py --selftest).
"""

from __future__ import annotations

import struct
from dataclasses import dataclass, field

import numpy as np

GLYPH_NONE = 0xFFFF
FMT_A4 = 11
FMT_NAMES = {0: "RGBA8", 1: "RGB8", 2: "RGBA5551", 3: "RGB565", 4: "RGBA4", 5: "LA8", 6: "HILO8",
             7: "L8", 8: "A8", 9: "LA4", 10: "L4", 11: "A4", 12: "ETC1", 13: "ETC1A4"}


def _align(n: int, a: int) -> int:
    return (n + a - 1) // a * a


# --------------------------------------------------------------------- texture codec
_PERM_CACHE: dict[tuple[int, int], tuple[np.ndarray, np.ndarray]] = {}


def _perm(w: int, h: int) -> tuple[np.ndarray, np.ndarray]:
    """Memory pixel index -> (row in memory order, x)."""
    key = (w, h)
    if key not in _PERM_CACHE:
        if w % 8 or h % 8:
            raise ValueError("3DS textures are made of 8x8 tiles")
        i = np.arange(64)
        tx = (i & 1) | ((i >> 1) & 2) | ((i >> 2) & 4)
        ty = ((i >> 1) & 1) | ((i >> 2) & 2) | ((i >> 3) & 4)
        t = np.arange((w // 8) * (h // 8))
        xs = ((t % (w // 8))[:, None] * 8 + tx[None, :]).ravel()
        ys = ((t // (w // 8))[:, None] * 8 + ty[None, :]).ravel()
        _PERM_CACHE[key] = (ys, xs)
    return _PERM_CACHE[key]


def decode_sheet(raw: bytes, w: int, h: int, fmt: int = FMT_A4) -> np.ndarray:
    """Swizzled sheet bytes -> top-down uint8 array (h, w) with values 0..15 (A4)."""
    if fmt != FMT_A4:
        raise NotImplementedError(f"sheet format {fmt} ({FMT_NAMES.get(fmt)}) not supported")
    b = np.frombuffer(raw, dtype=np.uint8, count=w * h // 2)
    nib = np.empty(w * h, dtype=np.uint8)
    nib[0::2] = b & 0x0F
    nib[1::2] = b >> 4
    ys, xs = _perm(w, h)
    img = np.zeros((h, w), dtype=np.uint8)
    img[ys, xs] = nib
    return img


def encode_sheet(img: np.ndarray, fmt: int = FMT_A4) -> bytes:
    """Inverse of decode_sheet."""
    if fmt != FMT_A4:
        raise NotImplementedError(f"sheet format {fmt} not supported")
    h, w = img.shape
    if img.max(initial=0) > 15:
        raise ValueError("A4 values must be 0..15")
    ys, xs = _perm(w, h)
    nib = img[ys, xs].astype(np.uint8)
    return (nib[0::2] | (nib[1::2] << 4)).astype(np.uint8).tobytes()


# --------------------------------------------------------------------- structures
@dataclass
class CharWidth:
    left: int
    glyph: int
    char: int


@dataclass
class CMap:
    begin: int
    end: int
    method: int
    reserved: int = 0
    base: int = 0                                   # method 0
    table: list[int] = field(default_factory=list)  # method 1 (glyph per code, 0xFFFF = none)
    scan: list[tuple[int, int]] = field(default_factory=list)  # method 2, sorted by code

    def mapping(self) -> dict[int, int]:
        if self.method == 0:
            return {c: self.base + c - self.begin for c in range(self.begin, self.end + 1)}
        if self.method == 1:
            return {self.begin + i: g for i, g in enumerate(self.table) if g != GLYPH_NONE}
        return dict(self.scan)

    def payload(self) -> bytes:
        if self.method == 0:
            return struct.pack("<H", self.base)
        if self.method == 1:
            if len(self.table) != self.end - self.begin + 1:
                raise ValueError("CMAP table length does not match its code range")
            return struct.pack(f"<{len(self.table)}H", *self.table)
        codes = [c for c, _ in self.scan]
        if codes != sorted(codes) or len(set(codes)) != len(codes):
            raise ValueError("CMAP scan entries must be unique and sorted by code (binary search)")
        return struct.pack("<H", len(self.scan)) + b"".join(struct.pack("<HH", c, g) for c, g in self.scan)


@dataclass
class Bffnt:
    version: int
    hdr_reserved: int
    # FINF
    font_type: int
    height: int
    width: int
    ascent: int
    line_feed: int
    alter_char: int
    default_width: CharWidth
    encoding: int
    # TGLP
    cell_w: int
    cell_h: int
    max_char_w: int
    sheet_size: int
    baseline: int
    sheet_fmt: int
    cols: int
    rows: int
    sheet_w: int
    sheet_h: int
    tglp_gap: bytes                   # bytes between the TGLP header and the sheet data
    sheets: list[bytes]
    # CWDH blocks (start index, widths) and CMAP blocks, in file/chain order
    cwdh: list[tuple[int, list[CharWidth]]]
    cmaps: list[CMap]
    # KRNG (kerning) block body, kept verbatim; None when the font has no KRNG block.
    # Layout (all offsets relative to the body, so the block can be moved as-is):
    #   firstWordNum(u16), (firstWord u16, offset u16 in half-words) * n,
    #   at each offset: secondWordNum(u16), (secondWord u16, value s16) * m
    krng: bytes | None = None

    def kerning(self) -> dict[tuple[int, int], int]:
        """(first code, second code) -> kerning value in pixels, from the KRNG block."""
        return parse_krng(self.krng) if self.krng else {}

    # ---------------------------------------------------------------- queries
    @property
    def glyphs_per_sheet(self) -> int:
        return self.cols * self.rows

    def widths(self) -> dict[int, CharWidth]:
        out: dict[int, CharWidth] = {}
        for start, ws in self.cwdh:
            for i, w in enumerate(ws):
                out[start + i] = w
        return out

    def glyph_count(self) -> int:
        return max((s + len(ws) for s, ws in self.cwdh), default=0)

    def char_map(self) -> dict[int, int]:
        """code point -> glyph index, resolved like nn::font: the first block (chain order) whose
        code range holds the code decides; a 0xFFFF table entry there means 'not in font'."""
        out: dict[int, int] = {}
        ranges: list[tuple[int, int]] = []
        for cm in self.cmaps:
            for c, g in cm.mapping().items():
                if not any(b <= c <= e for b, e in ranges):
                    out[c] = g
            ranges.append((cm.begin, cm.end))
        return out

    def lookup(self, code: int) -> int | None:
        """Glyph index for code under 'first block whose range contains code wins' semantics."""
        for cm in self.cmaps:
            if cm.begin <= code <= cm.end:
                g = cm.mapping().get(code)
                return g
        return None

    def cell_origin(self, glyph: int) -> tuple[int, int, int]:
        sheet, cell = divmod(glyph, self.glyphs_per_sheet)
        row, col = divmod(cell, self.cols)
        return sheet, col * (self.cell_w + 1) + 1, row * (self.cell_h + 1) + 1


# --------------------------------------------------------------------- parse
def parse_krng(body: bytes) -> dict[tuple[int, int], int]:
    """Decode a KRNG block body (see Bffnt.krng) into {(first, second): value}."""
    n = struct.unpack_from("<H", body, 0)[0]
    out: dict[tuple[int, int], int] = {}
    for i in range(n):
        first, off = struct.unpack_from("<HH", body, 2 + 4 * i)
        m = struct.unpack_from("<H", body, off * 2)[0]
        for k in range(m):
            second, val = struct.unpack_from("<Hh", body, off * 2 + 2 + 4 * k)
            out[(first, second)] = val
    return out


def parse(data: bytes) -> Bffnt:
    magic, bom, hsize, version, fsize, nblocks, hres = struct.unpack_from("<4sHHIIHH", data, 0)
    if magic != b"FFNT" or bom != 0xFEFF:
        raise ValueError("not a little-endian FFNT (3DS BFFNT)")
    if fsize != len(data):
        raise ValueError(f"file size field {fsize} != {len(data)}")
    p = hsize
    sections: list[tuple[bytes, int, int]] = []
    while p < len(data):
        m, sz = data[p:p + 4], struct.unpack_from("<I", data, p + 4)[0]
        if sz < 8:
            raise ValueError(f"bad section size at 0x{p:X}")
        sections.append((m, p, sz))
        p += sz
    if p != len(data) or len(sections) != nblocks:
        raise ValueError("section chain does not cover the file exactly")
    kinds = [m for m, _, _ in sections]
    krng = None
    if kinds[-1] == b"KRNG" and b"KRNG" not in kinds[:-1]:   # optional kerning block, last
        _, ko, ksz = sections[-1]
        krng = data[ko + 8:ko + ksz]
        parse_krng(krng)                                       # validate
        sections = sections[:-1]
        kinds = kinds[:-1]
    if kinds[0] != b"FINF" or kinds[1] != b"TGLP" or set(kinds[2:]) - {b"CWDH", b"CMAP"}:
        raise ValueError(f"unsupported section layout {kinds}")
    finf = sections[0][1]
    ftype, h, w, asc, lf, alt = struct.unpack_from("<BBBBHH", data, finf + 8)
    dl, dg, dc, enc = struct.unpack_from("<bBBB", data, finf + 16)
    pg, pw, pm = struct.unpack_from("<III", data, finf + 20)
    tg, tg_size = sections[1][1], sections[1][2]
    if pg != tg + 8:
        raise ValueError("FINF.ptrGlyph does not point at TGLP")
    cw, ch, ns, mcw, ssz, bl, fmt, nc, nr, sw, sh, sdo = struct.unpack_from("<BBBBIHHHHHHI", data, tg + 8)
    if sdo + ns * ssz != tg + tg_size:
        raise ValueError("TGLP sheet data does not end at the end of the TGLP section")
    gap = data[tg + 0x20:sdo]
    sheets = [data[sdo + k * ssz:sdo + (k + 1) * ssz] for k in range(ns)]

    cwdh: list[tuple[int, list[CharWidth]]] = []
    cmaps: list[CMap] = []
    cw_offs = [o for m, o, _ in sections if m == b"CWDH"]
    cm_offs = [o for m, o, _ in sections if m == b"CMAP"]
    # follow the pointer chains and check they visit the sections in file order
    q, seen = pw, []
    while q:
        o = q - 8
        seen.append(o)
        s, e, nxt = struct.unpack_from("<HHI", data, q)
        cwdh.append((s, [CharWidth(*struct.unpack_from("<bBB", data, q + 8 + 3 * i))
                         for i in range(e - s + 1)]))
        q = nxt
    if seen != cw_offs:
        raise ValueError("CWDH chain order differs from file order")
    q, seen = pm, []
    while q:
        o = q - 8
        seen.append(o)
        cs, ce, meth, res, nxt = struct.unpack_from("<HHHHI", data, q)
        body = q + 12
        cm = CMap(cs, ce, meth, res)
        if meth == 0:
            cm.base = struct.unpack_from("<H", data, body)[0]
        elif meth == 1:
            cm.table = list(struct.unpack_from(f"<{ce - cs + 1}H", data, body))
        elif meth == 2:
            n = struct.unpack_from("<H", data, body)[0]
            cm.scan = [struct.unpack_from("<HH", data, body + 2 + 4 * i) for i in range(n)]
        else:
            raise ValueError(f"unknown CMAP method {meth}")
        cmaps.append(cm)
        q = nxt
    if seen != cm_offs:
        raise ValueError("CMAP chain order differs from file order")
    return Bffnt(version, hres, ftype, h, w, asc, lf, alt, CharWidth(dl, dg, dc), enc,
                 cw, ch, mcw, ssz, bl, fmt, nc, nr, sw, sh, gap, sheets, cwdh, cmaps, krng)


# --------------------------------------------------------------------- build
def build(f: Bffnt) -> bytes:
    if len(f.sheets) > 255:
        raise ValueError("TGLP.numSheets is a u8")
    for s in f.sheets:
        if len(s) != f.sheet_size:
            raise ValueError("every sheet must be exactly sheet_size bytes")
    out = bytearray(0x14)
    finf_off = len(out)
    out += bytes(0x20)
    tglp_off = len(out)
    sdo = tglp_off + 0x20 + len(f.tglp_gap)
    tglp = struct.pack("<4sI", b"TGLP", sdo - tglp_off + len(f.sheets) * f.sheet_size)
    tglp += struct.pack("<BBBBIHHHHHHI", f.cell_w, f.cell_h, len(f.sheets), f.max_char_w, f.sheet_size,
                        f.baseline, f.sheet_fmt, f.cols, f.rows, f.sheet_w, f.sheet_h, sdo)
    out += tglp + f.tglp_gap
    for s in f.sheets:
        out += s
    nblocks = 2
    cw_offs = []
    for start, ws in f.cwdh:
        off = len(out)
        cw_offs.append(off)
        body = struct.pack("<HHI", start, start + len(ws) - 1, 0)
        body += b"".join(struct.pack("<bBB", w.left, w.glyph, w.char) for w in ws)
        size = _align(8 + len(body), 4)
        out += struct.pack("<4sI", b"CWDH", size) + body + bytes(size - 8 - len(body))
        nblocks += 1
    for k in range(len(cw_offs) - 1):
        struct.pack_into("<I", out, cw_offs[k] + 12, cw_offs[k + 1] + 8)
    cm_offs = []
    for cm in f.cmaps:
        off = len(out)
        cm_offs.append(off)
        body = struct.pack("<HHHHI", cm.begin, cm.end, cm.method, cm.reserved, 0) + cm.payload()
        size = _align(8 + len(body), 4)
        out += struct.pack("<4sI", b"CMAP", size) + body + bytes(size - 8 - len(body))
        nblocks += 1
    for k in range(len(cm_offs) - 1):
        struct.pack_into("<I", out, cm_offs[k] + 16, cm_offs[k + 1] + 8)
    if f.krng is not None:
        if (8 + len(f.krng)) % 4:
            raise ValueError("KRNG body must keep the block 4-byte aligned")
        out += struct.pack("<4sI", b"KRNG", 8 + len(f.krng)) + f.krng
        nblocks += 1
    struct.pack_into("<4sI", out, finf_off, b"FINF", 0x20)
    struct.pack_into("<BBBBHH", out, finf_off + 8, f.font_type, f.height, f.width, f.ascent,
                     f.line_feed, f.alter_char)
    struct.pack_into("<bBBB", out, finf_off + 16, f.default_width.left, f.default_width.glyph,
                     f.default_width.char, f.encoding)
    struct.pack_into("<III", out, finf_off + 20, tglp_off + 8, (cw_offs[0] + 8) if cw_offs else 0,
                     (cm_offs[0] + 8) if cm_offs else 0)
    struct.pack_into("<4sHHIIHH", out, 0, b"FFNT", 0xFEFF, 0x14, f.version, len(out), nblocks,
                     f.hdr_reserved)
    return bytes(out)


# --------------------------------------------------------------------- pixel access helpers
class SheetImages:
    """Decoded, editable view of all sheets of a font (top-down 0..15 arrays)."""

    def __init__(self, font: Bffnt):
        self.font = font
        self.images = [decode_sheet(s, font.sheet_w, font.sheet_h, font.sheet_fmt) for s in font.sheets]

    def add_sheet(self) -> None:
        self.images.append(np.zeros((self.font.sheet_h, self.font.sheet_w), dtype=np.uint8))

    def cell(self, glyph: int) -> np.ndarray:
        f = self.font
        s, x, y = f.cell_origin(glyph)
        return self.images[s][y:y + f.cell_h, x:x + f.cell_w]

    def put(self, glyph: int, pix: np.ndarray) -> None:
        f = self.font
        if pix.shape != (f.cell_h, f.cell_w):
            raise ValueError(f"glyph bitmap must be {f.cell_h}x{f.cell_w}")
        s, x, y = f.cell_origin(glyph)
        while s >= len(self.images):
            self.add_sheet()
        self.images[s][y:y + f.cell_h, x:x + f.cell_w] = pix

    def commit(self) -> None:
        self.font.sheets = [encode_sheet(im, self.font.sheet_fmt) for im in self.images]
