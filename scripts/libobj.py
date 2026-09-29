"""AlphaDream 3DS sprite archives (Obj/*.dat): BG4 of anim ("description") files, pixel buffers
and a nested BG4 `_CA_INFO_` naming the cell-animation objects.

Format (checked against Spritoglobin-DX, github.com/MnL-Modding/Spritoglobin-DX, GPLv3 -- only
the format knowledge is used, no code is copied):

  _CA_INFO_ (nested BG4, compressed): one entry per object, named e.g. `bui_sys_font_JP_ja`;
      data = four 4-byte NUL-padded names of outer entries: anim, graph, color, hitbox (+ rest).
  anim file (little-endian):
      u8 anim_num, u8 color_mode (PICA format id), u8 renderer_num, u8 0, u32 anim_len, u32 graph_len
      3DX (ML3R): + 4 x s16 bounding box + 7 x u32 offsets (frame, part, part_trans, full_trans,
                  renderer, normal, unused)      -> 16 default colours at 0x30, anims at 0x70
      1DX (ML1R): + 6 x u32 offsets              -> colours at 0x24, anims at 0x64
      animation = u16 first_frame, u16 total_frames, u16 length, u16 0 (+ 4 x s16 bbox on 3DX)
      frame     = u16 first_part, u8 total_parts, u8 invert, u16 timer, u16 transform
      part (16 bytes on both DX games) = u16 oam, u16 renderer, s16 hflip?, u16 buffer_offset,
                  s16 x, s16 y, u32 normal.  oam bits: size = oam & 3, shape = oam >> 2 & 3,
                  0x100 = h-flip, 0x200 = v-flip.  Pixel data of a part = graph[128*buffer_offset:],
                  w x h pixels in 8x8 Morton tiles, tiles row-major, TOP row first.
      part_offset == 0 -> "sprite sheet mode": the graph buffer is one sheet texture (size in the
                  sheet descriptor placed after the animations).
  graph file: raw PICA pixels (color_mode), no header.
"""

from __future__ import annotations

import struct
from dataclasses import dataclass, field
from pathlib import Path

import numpy as np

import lib3dx
import libtex3ds

ROOT = lib3dx.ROOT
PICA = libtex3ds.PICA_FORMATS
SIZING = [[(8, 8), (16, 16), (32, 32), (64, 64)], [(16, 8), (32, 8), (32, 16), (64, 32)],
          [(8, 16), (8, 32), (16, 32), (32, 64)]]

DATS_3DX = ["BUI", "FUI", "KUI", "Menu"]
DATS_1DX = {"BUI": "KR/BUI", "FUI": "KR/FUI", "KUI": "KR/KUI", "MGUI": "KR/MGUI", "Menu": "Menu"}


def dat_path(game: str, dat: str) -> Path:
    if game == "3DX":
        return lib3dx.romfs_path(f"Obj/JP/{dat}.dat")
    return ROOT / "ml 1dx" / "3romfs" / "Obj" / f"{DATS_1DX[dat]}.dat"


@dataclass
class Part:
    index: int
    oam: int
    renderer: int
    hflag: int
    buf: int          # 128-byte units
    x: int
    y: int
    normal: int

    @property
    def size(self) -> tuple[int, int]:
        return SIZING[(self.oam >> 2) & 3][self.oam & 3]

    @property
    def flip(self) -> tuple[bool, bool]:
        return bool(self.oam & 0x100), bool(self.oam & 0x200)


@dataclass
class Frame:
    first_part: int
    total_parts: int
    invert: int
    timer: int
    transform: int


@dataclass
class Anim:
    first_frame: int
    total_frames: int
    length: int
    bbox: tuple | None


@dataclass
class AnimFile:
    game: str
    raw: bytes
    anim_num: int
    fmt: str
    renderer_num: int
    anim_len: int
    graph_len: int
    bbox: tuple | None
    offsets: dict
    anims: list = field(default_factory=list)
    frames: list = field(default_factory=list)
    parts: list = field(default_factory=list)
    sheet: dict | None = None     # sprite-sheet mode descriptor

    @property
    def bpp(self) -> int:
        return libtex3ds.BPP[self.fmt]


def parse_anim(raw: bytes, game: str) -> AnimFile:
    anim_num, cm, rn, _u, alen, glen = struct.unpack_from("<4B2I", raw, 0)
    if game == "3DX":
        bbox = struct.unpack_from("<4h", raw, 0xC)
        offs = struct.unpack_from("<7I", raw, 0x14)
        keys = ["frame", "part", "part_trans", "full_trans", "renderer", "normal", "unused"]
        anim_off, anim_size = 0x70, 16
    else:
        bbox = None
        offs = struct.unpack_from("<6I", raw, 0xC)
        keys = ["frame", "part", "part_trans", "full_trans", "renderer", "normal"]
        anim_off, anim_size = 0x64, 8
    o = dict(zip(keys, offs))
    af = AnimFile(game, raw, anim_num, PICA[cm], rn, alen, glen, bbox, o)
    if anim_off + anim_num * anim_size != o["frame"]:
        raise ValueError("anim table does not end at the frame table (wrong game variant?)")
    for i in range(anim_num):
        a = struct.unpack_from("<4H", raw, anim_off + i * anim_size)
        bb = struct.unpack_from("<4h", raw, anim_off + i * anim_size + 8) if anim_size == 16 else None
        af.anims.append(Anim(a[0], a[1], a[2], bb))
    part_off = o["part"]
    if part_off == 0:
        # sprite-sheet mode: descriptor sits between the animations and the frames? (Spritoglobin:
        # part area = anim end .. frame_offset). Keep the raw descriptor.
        start = anim_off + anim_num * anim_size
        desc = raw[start:o["frame"]]
        af.sheet = {"raw_start": start, "raw": desc}
        if len(desc) >= 8:
            ng, ns, sw, sh = struct.unpack_from("<4H", desc, 0)
            af.sheet.update(groups=ng, segments=ns, w=sw, h=sh)
        nframes = 0
    else:
        nframes = (part_off - o["frame"]) // 8
    for i in range(nframes):
        af.frames.append(Frame(*struct.unpack_from("<HBBHH", raw, o["frame"] + i * 8)))
    if part_off:
        pend = o["part_trans"] if o["part_trans"] else len(raw)
        for i in range((pend - part_off) // 16):
            v = struct.unpack_from("<HHhHhhI", raw, part_off + i * 16)
            af.parts.append(Part(i, *v))
    return af


@dataclass
class ObjDef:
    name: str
    anim: str
    graph: str
    color: str
    hitbox: str
    raw: bytes


class ObjDat:
    """One Obj/*.dat archive."""

    def __init__(self, game: str, dat: str, data: bytes | None = None):
        self.game, self.dat = game, dat
        self.path = dat_path(game, dat)
        self.data = data if data is not None else self.path.read_bytes()
        _v, self.entries = lib3dx.read_bg4(self.data)
        self.slot = {e.name: i for i, e in enumerate(self.entries) if not e.size_flag}
        ca = self.entries[self.slot["_CA_INFO_"]]
        self.ca_raw = lib3dx.bg4_plain(ca)
        _v, ie = lib3dx.read_bg4(self.ca_raw)
        self.objs: dict[str, ObjDef] = {}
        for e in ie:
            if e.size_flag:
                continue
            d = lib3dx.bg4_plain(e)
            names = [d[k:k + 4].split(b"\0")[0].decode("ascii") for k in range(0, 16, 4)]
            self.objs[e.name] = ObjDef(e.name, *names, d)
        self._plain: dict[str, bytes] = {}
        self._anim: dict[str, AnimFile] = {}

    def plain(self, name: str) -> bytes:
        if name not in self._plain:
            self._plain[name] = lib3dx.bg4_plain(self.entries[self.slot[name]])
        return self._plain[name]

    def anim(self, name: str) -> AnimFile:
        if name not in self._anim:
            self._anim[name] = parse_anim(self.plain(name), self.game)
        return self._anim[name]


# ------------------------------------------------------------------ pixels
def part_rgba(af: AnimFile, graph: bytes, p: Part, apply_flip: bool = True) -> np.ndarray:
    w, h = p.size
    start = 128 * p.buf
    n = libtex3ds.data_size(af.fmt, w, h)
    img = libtex3ds.decode(graph[start:start + n], af.fmt, w, h, flip=False)
    if apply_flip:
        hf, vf = p.flip
        if hf:
            img = img[:, ::-1]
        if vf:
            img = img[::-1]
    return np.ascontiguousarray(img)


def part_encode(af: AnimFile, p: Part, rgba: np.ndarray, undo_flip: bool = True) -> bytes:
    img = rgba
    if undo_flip:
        hf, vf = p.flip
        if hf:
            img = img[:, ::-1]
        if vf:
            img = img[::-1]
    return libtex3ds.encode(np.ascontiguousarray(img), af.fmt, flip=False)


def frame_layout(af: AnimFile, fr: Frame):
    """Parts of a frame with their top-left position in the frame image, and the image size.
    Returns (parts [(part, x0, y0)], (w, h), origin (ox, oy)).  Part centre = origin + (x, -y)."""
    ps = [af.parts[fr.first_part + i] for i in range(fr.total_parts)]
    if not ps:
        return [], (0, 0), (0, 0)
    xs0 = [p.x - p.size[0] // 2 for p in ps]
    ys0 = [-p.y - p.size[1] // 2 for p in ps]
    minx, miny = min(xs0), min(ys0)
    maxx = max(x + p.size[0] for x, p in zip(xs0, ps))
    maxy = max(y + p.size[1] for y, p in zip(ys0, ps))
    lay = [(p, x - minx, y - miny) for p, x, y in zip(ps, xs0, ys0)]
    return lay, (maxx - minx, maxy - miny), (-minx, -miny)


def render_frame(af: AnimFile, graph: bytes, fr: Frame) -> np.ndarray | None:
    """Composite a frame (no colour shader, no transform). Part 0 is drawn on top."""
    lay, (w, h), _o = frame_layout(af, fr)
    if not lay:
        return None
    out = np.zeros((h, w, 4), np.float32)
    for p, x0, y0 in reversed(lay):
        t = part_rgba(af, graph, p).astype(np.float32)
        pw, ph = p.size
        dst = out[y0:y0 + ph, x0:x0 + pw]
        sa = t[..., 3:4] / 255
        da = dst[..., 3:4] / 255
        a = sa + da * (1 - sa)
        rgb = (t[..., :3] * sa + dst[..., :3] * da * (1 - sa)) / np.maximum(a, 1e-3)
        dst[..., :3] = np.where(a < 1e-3, t[..., :3], rgb)
        dst[..., 3:4] = a * 255
    return np.clip(out + 0.5, 0, 255).astype(np.uint8)


def sheet_rgba(af: AnimFile, graph: bytes) -> np.ndarray:
    w, h = af.sheet["w"], af.sheet["h"]
    return libtex3ds.decode(graph[:libtex3ds.data_size(af.fmt, w, h)], af.fmt, w, h, flip=False)


def region_key(p: Part) -> str:
    w, h = p.size
    return f"b{p.buf:05d}_{w}x{h}"
