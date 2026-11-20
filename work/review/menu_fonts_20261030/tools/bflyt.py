"""Minimal BFLYT (FLYT v7.2.1, 3DX MLyt) pane-tree reader: panes, parts, world transforms (FONT worker).

Pane block (pan1/pic1/wnd1/bnd1/txt1/prt1 share the first 0x54 bytes):
  +0x08 flags u8, origin u8, alpha u8, magnify-flags u8, +0x0C name[24], +0x24 user[8],
  +0x2C translate xyz f32, +0x38 rotate xyz f32, +0x44 scale xy f32, +0x4C size wh f32
prt1: +0x54 property count u32, +0x58 magnify xy f32, +0x60 properties (0x28 each), then part layout name.
"""
from __future__ import annotations

import math
import struct
import sys
from dataclasses import dataclass, field
from pathlib import Path

ROOT = Path(__file__).resolve().parents[4]
sys.path.insert(0, str(ROOT / "scripts"))
from lib3dx import blz_decompress, read_bg4, romfs_path  # noqa: E402
from lytimg import sarc_list  # noqa: E402

PANE_KINDS = {b"pan1", b"pic1", b"wnd1", b"bnd1", b"txt1", b"prt1"}


@dataclass
class Pane:
    kind: str
    name: str
    flags: int
    origin: int
    alpha: int
    t: tuple
    r: tuple
    s: tuple
    size: tuple
    parent: "Pane | None" = None
    children: list = field(default_factory=list)
    part: str = ""
    part_magnify: tuple = (1.0, 1.0)
    extra: dict = field(default_factory=dict)

    def path(self) -> str:
        p, out = self, []
        while p is not None:
            out.append(p.name)
            p = p.parent
        return "/".join(reversed(out))

    def world(self):
        """(x, y, sx, sy) of the pane origin in root space (rotation ignored except z, reported)."""
        x = y = 0.0
        sx = sy = 1.0
        chain = []
        p = self
        while p is not None:
            chain.append(p)
            p = p.parent
        for q in reversed(chain):
            x += q.t[0] * sx
            y += q.t[1] * sy
            sx *= q.s[0]
            sy *= q.s[1]
        return x, y, sx, sy


def cstr(b: bytes) -> str:
    return b.split(b"\0", 1)[0].decode("latin1")


def parse(b: bytes) -> dict:
    magic, bom, hsize, ver, fsize, nsec = struct.unpack_from("<4sHHIIH", b, 0)
    assert magic == b"FLYT"
    p = hsize
    root = None
    last = None
    stack: list[Pane] = []
    panes: list[Pane] = []
    layout = {}
    for _ in range(nsec):
        m, sz = b[p:p + 4], struct.unpack_from("<I", b, p + 4)[0]
        if m == b"lyt1":
            layout["center"] = b[p + 8]
            layout["w"], layout["h"] = struct.unpack_from("<ff", b, p + 12)
        elif m in PANE_KINDS:
            fl, org, al, mag = struct.unpack_from("<BBBB", b, p + 8)
            name = cstr(b[p + 0x0C:p + 0x24])
            t = struct.unpack_from("<fff", b, p + 0x2C)
            r = struct.unpack_from("<fff", b, p + 0x38)
            s = struct.unpack_from("<ff", b, p + 0x44)
            size = struct.unpack_from("<ff", b, p + 0x4C)
            pane = Pane(m.decode(), name, fl, org, al, t, r, s, size)
            if m == b"prt1":
                n = struct.unpack_from("<I", b, p + 0x54)[0]
                pane.part_magnify = struct.unpack_from("<ff", b, p + 0x58)
                no = p + 0x60 + n * 0x28
                pane.part = cstr(b[no:no + 64])
                pane.extra["props"] = [cstr(b[p + 0x60 + i * 0x28:p + 0x60 + i * 0x28 + 24]) for i in range(n)]
            if stack:
                pane.parent = stack[-1]
                stack[-1].children.append(pane)
            else:
                root = pane
            panes.append(pane)
            last = pane
        elif m == b"pas1":
            stack.append(last)
        elif m == b"pae1":
            stack.pop()
        p += sz
    return {"version": ver, "layout": layout, "root": root, "panes": panes}


def load_sarc(dat: str, entry: str, base: bool = False) -> bytes:
    path = (ROOT / "romfs" / f"Lyt/JP/{dat}.dat") if base else romfs_path(f"Lyt/JP/{dat}.dat")
    _, ents = read_bg4(path.read_bytes())
    for e in ents:
        if e.name == entry:
            return blz_decompress(e.data) if e.compressed else e.data
    raise KeyError(entry)


def sarc_files(sarc: bytes) -> dict[str, bytes]:
    return {n: sarc[s:e] for n, s, e in sarc_list(sarc)}


def main():
    dat, entry = sys.argv[1], sys.argv[2]
    want = sys.argv[3:]   # layout names (without .bflyt); empty = all
    files = sarc_files(load_sarc(dat, entry))
    for n, data in sorted(files.items()):
        if not n.endswith(".bflyt"):
            continue
        stem = n.rsplit("/", 1)[-1][:-6]
        if want and stem not in want:
            continue
        L = parse(data)
        print(f"### {stem}  layout {L['layout']}")
        for pn in L["panes"]:
            x, y, sx, sy = pn.world()
            depth = pn.path().count("/")
            extra = f" part={pn.part} mag={pn.part_magnify}" if pn.kind == "prt1" else ""
            rot = f" rot={pn.r}" if any(abs(v) > 1e-6 for v in pn.r) else ""
            print(f"{'  ' * depth}{pn.kind} {pn.name} t=({pn.t[0]:.1f},{pn.t[1]:.1f}) s=({pn.s[0]:.3f},{pn.s[1]:.3f}) "
                  f"size=({pn.size[0]:.1f},{pn.size[1]:.1f}) world=({x:.1f},{y:.1f}) ws=({sx:.3f},{sy:.3f}) "
                  f"org={pn.origin} a={pn.alpha} fl={pn.flags}{extra}{rot}")


if __name__ == "__main__":
    main()
