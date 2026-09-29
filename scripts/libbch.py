"""BCH (H3D) texture access for FMdl/JP/FMdl.dat models (Mario & Luigi RPG3 DX).

    bch = Bch(plain_bytes)                 # one BG4 entry, decompressed
    for t in bch.textures: t.name, t.fmt, t.w, t.h, t.levels, t.offset, t.size
    rgba = bch.decode(t)                   # (h, w, 4) uint8, level 0, upright. BCH pixels are
                                           # stored top row first (unlike BFLIM) -> flip=False
    new = bch.replace(t, rgba)             # same size / format, mip levels regenerated -> new BCH bytes

Only the pixel bytes inside the data section are rewritten, so the file length and every other
byte stay the same (no relocation or pointer changes needed).

Format notes (checked on all 205 models of the v1.2 FMdl.dat, backward compat 0x22):
  header: 'BCH\\0', u8 backward, u8 forward, u16 version, then u32 offsets
          main, strings, commands, data, dataExt, relocation, and lengths.
  main (contents) section: 15 dictionaries x (pointer table, count, name dict); #3 = textures.
  Pointers in the file are section-relative; the relocation table says which section each one
  points at (value = (address/4) | target<<25 | source<<29).  Contents->Contents/Strings/Commands
  pointers are relative to those sections; texture addresses inside GPU commands (target 5) are
  relative to the data section.
  texture entry: 3 x (commands ptr, word count) for texture units 0..2, u8 format(PICA id),
  u8 mipmap count, u16 pad, name ptr.  Unit-0 commands carry 0x82 (dim: width<<16 | height),
  0x85 (address), 0x8E (format), 0x84 (LOD: max level in bits 16..19).
"""

from __future__ import annotations

import struct
from dataclasses import dataclass

import numpy as np

import libtex3ds

TEX_DICT = 3


@dataclass
class BchTexture:
    index: int
    name: str
    fmt: str          # libtex3ds format name
    w: int
    h: int
    levels: int       # mip levels incl. base
    offset: int       # absolute offset of level 0 in the BCH bytes
    size: int         # bytes of all levels together
    cmd_levels: int   # levels according to the LOD register (cross-check)


def _cstr(b: bytes, off: int) -> str:
    end = b.index(b"\0", off)
    return b[off:end].decode("ascii", "replace")


def pica_commands(b: bytes, off: int, words: int) -> dict[int, list[int]]:
    """Parse a PICA200 command buffer -> {register: [values...]} (last write wins in [-1])."""
    regs: dict[int, list[int]] = {}
    w = list(struct.unpack_from(f"<{words}I", b, off))
    i = 0
    while i + 1 < len(w):
        param, hdr = w[i], w[i + 1]
        rid, extra, consec = hdr & 0xFFFF, (hdr >> 20) & 0x7FF, hdr >> 31
        vals = [param] + w[i + 2:i + 2 + extra]
        for k, v in enumerate(vals):
            r = rid + k if consec else rid
            regs.setdefault(r, []).append(v)
        i += 2 + extra
        if i % 2:
            i += 1
    return regs


def level_sizes(fmt: str, w: int, h: int, levels: int) -> list[tuple[int, int, int]]:
    out = []
    for lv in range(levels):
        lw, lh = w >> lv, h >> lv
        out.append((lw, lh, libtex3ds.data_size(fmt, lw, lh)))
    return out


class Bch:
    def __init__(self, data: bytes):
        if data[:4] != b"BCH\0":
            raise ValueError("not a BCH file")
        self.data = bytes(data)
        self.backward = data[4]
        if self.backward < 0x21:
            raise ValueError(f"BCH backward compat 0x{data[4]:X} not supported")
        (self.main, self.strings, self.cmds, self.dat, self.dat_ext, self.reloc,
         self.main_len, self.str_len, self.cmd_len, self.dat_len, self.dat_ext_len,
         self.reloc_len) = struct.unpack_from("<12I", data, 8)
        self.textures = self._read_textures()

    # pointer helpers: the stored value is section-relative (see module doc)
    def _u32(self, off):
        return struct.unpack_from("<I", self.data, off)[0]

    def _read_textures(self) -> list[BchTexture]:
        b = self.data
        pt, cnt, _nd = struct.unpack_from("<III", b, self.main + TEX_DICT * 12)
        out = []
        for k in range(cnt):
            ent = self.main + self._u32(self.main + pt + 4 * k)
            c0, n0 = struct.unpack_from("<II", b, ent)
            fmt_id, mips = b[ent + 24], b[ent + 25]
            name = _cstr(b, self.strings + self._u32(ent + 28))
            regs = pica_commands(b, self.cmds + c0, n0)
            dim = regs[0x82][-1]
            w, h = dim >> 16, dim & 0xFFFF
            addr = regs[0x85][-1]
            cfmt = regs[0x8E][-1] & 0xF
            lod = regs.get(0x84, [0])[-1]
            cmd_levels = ((lod >> 16) & 0xF) + 1
            if cfmt != fmt_id:
                raise ValueError(f"{name}: format mismatch cmd {cfmt} vs entry {fmt_id}")
            fmt = libtex3ds.PICA_FORMATS[fmt_id]
            levels = max(1, mips)
            size = sum(s for _, _, s in level_sizes(fmt, w, h, levels))
            off = self.dat + addr
            if off + size > self.dat + self.dat_len:
                raise ValueError(f"{name}: data runs past the data section")
            out.append(BchTexture(k, name, fmt, w, h, levels, off, size, cmd_levels))
        return out

    def texture(self, name: str) -> BchTexture:
        for t in self.textures:
            if t.name == name:
                return t
        raise KeyError(name)

    def decode(self, t: BchTexture, level: int = 0) -> np.ndarray:
        off = t.offset
        for lw, lh, s in level_sizes(t.fmt, t.w, t.h, t.levels):
            if level == 0:
                return libtex3ds.decode(self.data[off:off + s], t.fmt, lw, lh, flip=False)
            off += s
            level -= 1
        raise IndexError("mip level")

    @staticmethod
    def encode_levels(t: BchTexture, rgba: np.ndarray) -> bytes:
        """Level 0 = rgba; lower levels = box-filtered (premultiplied alpha) downscales."""
        from PIL import Image
        if rgba.shape[:2] != (t.h, t.w):
            raise ValueError(f"{t.name}: need {t.w}x{t.h}, got {rgba.shape[1]}x{rgba.shape[0]}")
        out = bytearray()
        cur = rgba.astype(np.float64)
        for lv, (lw, lh, s) in enumerate(level_sizes(t.fmt, t.w, t.h, t.levels)):
            if lv:
                a = cur[..., 3:4] / 255.0
                pm = np.concatenate([cur[..., :3] * a, cur[..., 3:4]], 2)
                pm = pm.reshape(lh, 2, lw, 2, 4).mean((1, 3))
                al = pm[..., 3:4] / 255.0
                rgb = np.where(al > 0, pm[..., :3] / np.maximum(al, 1e-9), 0)
                cur = np.concatenate([rgb, pm[..., 3:4]], 2)
            img = np.clip(np.rint(cur), 0, 255).astype(np.uint8)
            enc = libtex3ds.encode(img, t.fmt, flip=False)
            assert len(enc) == s
            out += enc
        _ = Image  # (pillow not needed; kept import-light)
        return bytes(out)

    def replace(self, t: BchTexture, rgba: np.ndarray) -> bytes:
        blob = self.encode_levels(t, rgba)
        assert len(blob) == t.size
        return self.data[:t.offset] + blob + self.data[t.offset + t.size:]

    def replace_many(self, items: dict[str, np.ndarray]) -> bytes:
        buf = bytearray(self.data)
        for name, rgba in items.items():
            t = self.texture(name)
            blob = self.encode_levels(t, rgba)
            buf[t.offset:t.offset + t.size] = blob
        return bytes(buf)


def _selftest() -> None:
    import sys
    from pathlib import Path
    sys.path.insert(0, str(Path(__file__).parent))
    import lib3dx
    d = lib3dx.romfs_path("FMdl/JP/FMdl.dat").read_bytes()
    _, es = lib3dx.read_bg4(d)
    n_models = n_tex = 0
    lossless_ok = 0
    for e in es:
        if e.size_flag:
            continue
        b = lib3dx.bg4_plain(e)
        bch = Bch(b)
        n_models += 1
        for t in bch.textures:
            n_tex += 1
            if t.levels == 1 and t.fmt not in ("ETC1", "ETC1A4"):
                img = bch.decode(t)
                assert bch.replace(t, img) == b, t.name
                lossless_ok += 1
    print(f"libbch selftest OK: {n_models} models, {n_tex} textures, {lossless_ok} lossless round trips")


if __name__ == "__main__":
    _selftest()
