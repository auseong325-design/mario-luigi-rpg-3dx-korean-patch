"""Staffroll/<region>/Staffroll.bin codec (Mario & Luigi RPG3 DX / RPG1 DX, 3DS).

File = Nintendo BLZ ("backwards LZ", same as BG4 entries) around a flat record table:

  u32 count
  count * 96-byte records:
     0x00  char16[44]  UTF-16LE text, NUL-terminated, zero-padded (an empty text = spacer line)
     0x58  u32         colour. 3DX: 0xFFFFFFFF = white (names), 0xFFA6C407 = teal (roles);
                        bytes in memory 07 C4 A6 FF = r,g,b,a (7,196,166). 1DX stores the same
                        colours with the bytes reversed (0 = default white, 0x07C4A6FF = teal).
     0x5C  f32         line size. 3DX: text height in px (names 20, roles 18, title 24,
                        spacers 60) - the scroll timing is the running sum of these, so it is
                        kept exactly. 1DX uses other values (0 = default, spacers 5/10).

There is no separate timing table: line count, order and the size field ARE the timing.

The BLZ footer of the game files counts the whole file as compressed (enc_len = file size),
while ndspy's compressor leaves 2 bytes out; blz_pack() writes the game's value, so
blz_pack(blz_decompress(orig)) == orig for both 3DX JP and 1DX KR files (checked by
scripts/build_staffroll.py --identity).
"""

from __future__ import annotations

import struct
from dataclasses import dataclass

import lib3dx

REC_SIZE = 96
TEXT_UNITS = 44            # UTF-16 code units in the text field (one must stay NUL)
WHITE = 0xFFFFFFFF
TEAL_3DX = 0xFFA6C407


@dataclass
class Line:
    text: str
    color: int             # u32 as stored
    size_bits: int         # raw f32 bits (kept exactly)
    tail: bytes = b""      # non-zero bytes after the NUL in the text field (none in the game files)

    @property
    def size(self) -> float:
        return struct.unpack("<f", struct.pack("<I", self.size_bits))[0]


def blz_pack(raw: bytes) -> bytes:
    """BLZ-compress like the game's files (footer enc_len = whole file)."""
    from ndspy.codeCompression import compress
    out = bytearray(compress(bytes(raw)))
    enc_hdr = struct.unpack_from("<I", out, len(out) - 8)[0]
    if struct.unpack_from("<I", out, len(out) - 4)[0] == 0:
        raise ValueError("BLZ: data did not compress")
    game = bytearray(out)
    struct.pack_into("<I", game, len(game) - 8, (enc_hdr & 0xFF000000) | len(game))
    if lib3dx.blz_decompress(bytes(game)) == raw:
        return bytes(game)
    if lib3dx.blz_decompress(bytes(out)) != raw:
        raise ValueError("BLZ: round trip failed")
    return bytes(out)


def decode_raw(raw: bytes) -> list[Line]:
    n = struct.unpack_from("<I", raw, 0)[0]
    if 4 + n * REC_SIZE != len(raw):
        raise ValueError(f"staffroll: {n} records do not fill {len(raw)} bytes")
    lines = []
    for i in range(n):
        r = raw[4 + i * REC_SIZE:4 + (i + 1) * REC_SIZE]
        units = struct.unpack_from(f"<{TEXT_UNITS}H", r, 0)
        z = units.index(0) if 0 in units else TEXT_UNITS
        if z == TEXT_UNITS:
            raise ValueError(f"staffroll line {i}: text is not NUL-terminated")
        text = r[:2 * z].decode("utf-16le")
        tail = r[2 * z:88]
        color, size_bits = struct.unpack_from("<II", r, 88)
        lines.append(Line(text, color, size_bits, tail if any(tail) else b""))
    return lines


def encode_raw(lines: list[Line]) -> bytes:
    out = bytearray(struct.pack("<I", len(lines)))
    for i, ln in enumerate(lines):
        t = ln.text.encode("utf-16le")
        if len(t) // 2 >= TEXT_UNITS:
            raise ValueError(f"staffroll line {i}: {len(t) // 2} UTF-16 units, max {TEXT_UNITS - 1}")
        field = t + ln.tail if ln.tail else t
        if len(field) > 88:
            raise ValueError(f"staffroll line {i}: text field overflow")
        out += field + bytes(88 - len(field)) + struct.pack("<II", ln.color, ln.size_bits)
    return bytes(out)


def read(data: bytes) -> list[Line]:
    return decode_raw(lib3dx.blz_decompress(data))


def write(lines: list[Line]) -> bytes:
    return blz_pack(encode_raw(lines))


def size_bits(value: float) -> int:
    return struct.unpack("<I", struct.pack("<f", value))[0]


def rgb(color: int, game: str = "3dx") -> tuple[int, int, int]:
    """Preview colour of a line (memory byte order r,g,b,a in 3DX; reversed in 1DX)."""
    if game == "3dx":
        b = struct.pack("<I", color)
    else:
        if color == 0:
            return (255, 255, 255)
        b = struct.pack(">I", color)
    return b[0], b[1], b[2]
