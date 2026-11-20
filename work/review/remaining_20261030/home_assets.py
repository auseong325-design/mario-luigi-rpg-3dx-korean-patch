"""Decode the HOME-menu icon (exefs2/icon SMDH) and the 3D banner (exefs/banner CBMD -> CGFX)
textures to PNG, to see whether they carry Japanese lettering (2026-10-30 review).

Read-only: writes PNGs and home_assets.json under work/review/remaining_20261030/home_assets/.
The banner is not in exefs2 (the update has no banner), so the v1.0 one is what HOME shows.
"""

from __future__ import annotations

import json
import struct
import sys
from pathlib import Path

import numpy as np
from PIL import Image

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
sys.path.insert(0, str(ROOT / "scripts"))
import libtex3ds as T  # noqa: E402

OUT = HERE / "home_assets"


def lz11(data: bytes) -> bytes:
    if data[0] != 0x11:
        raise ValueError("not LZ11")
    size = data[1] | data[2] << 8 | data[3] << 16
    p = 4
    if size == 0:
        size = struct.unpack_from("<I", data, 4)[0]
        p = 8
    out = bytearray()
    while len(out) < size:
        flags = data[p]
        p += 1
        for bit in range(8):
            if len(out) >= size:
                break
            if flags & (0x80 >> bit):
                b = data[p]
                ind = b >> 4
                if ind == 0:
                    length = (((b & 0xF) << 4) | (data[p + 1] >> 4)) + 0x11
                    disp = (((data[p + 1] & 0xF) << 8) | data[p + 2]) + 1
                    p += 3
                elif ind == 1:
                    length = (((b & 0xF) << 12) | (data[p + 1] << 4) | (data[p + 2] >> 4)) + 0x111
                    disp = (((data[p + 2] & 0xF) << 8) | data[p + 3]) + 1
                    p += 4
                else:
                    length = ind + 1
                    disp = (((b & 0xF) << 8) | data[p + 1]) + 1
                    p += 2
                for _ in range(length):
                    out.append(out[-disp])
            else:
                out.append(data[p])
                p += 1
    return bytes(out)


def rel(b: bytes, off: int) -> int:
    return off + struct.unpack_from("<I", b, off)[0]


def cstr(b: bytes, off: int) -> str:
    return b[off:b.index(b"\0", off)].decode("ascii", "replace")


def cgfx_textures(b: bytes) -> list[dict]:
    assert b[:4] == b"CGFX", b[:4]
    hsize = struct.unpack_from("<H", b, 6)[0]
    assert b[hsize:hsize + 4] == b"DATA"
    cnt, _ = struct.unpack_from("<II", b, hsize + 8 + 8)
    if not cnt:
        return []
    dic = rel(b, hsize + 8 + 8 + 4)
    assert b[dic:dic + 4] == b"DICT"
    n = struct.unpack_from("<I", b, dic + 8)[0]
    res = []
    for k in range(n):
        node = dic + 12 + 16 * (k + 1)
        name = cstr(b, rel(b, node + 8))
        tx = rel(b, node + 12)
        assert b[tx + 4:tx + 8] == b"TXOB", name
        h, w = struct.unpack_from("<II", b, tx + 0x18)
        fmt = struct.unpack_from("<I", b, tx + 0x34)[0]
        img = None
        for f in range(0x38, 0x60, 4):          # find the pixel-image struct: starts with (h, w)
            try:
                q = rel(b, tx + f)
            except struct.error:
                break
            if 0 < q < len(b) - 16 and struct.unpack_from("<II", b, q) == (h, w):
                dlen = struct.unpack_from("<I", b, q + 8)[0]
                img = (rel(b, q + 12), dlen)
                break
        res.append({"name": name, "w": w, "h": h, "fmt": T.PICA_FORMATS.get(fmt, str(fmt)), "img": img})
    return res


def save(rgba: np.ndarray, name: str, scale: int = 1) -> str:
    im = Image.fromarray(rgba, "RGBA")
    if scale > 1:
        im = im.resize((im.width * scale, im.height * scale), Image.NEAREST)
    p = OUT / name
    im.save(p)
    return str(p)


def main() -> int:
    OUT.mkdir(exist_ok=True)
    rep: dict = {}
    smdh = (ROOT / "exefs2/icon").read_bytes()
    big = T.decode(smdh[0x24C0:0x24C0 + 0x1200], "RGB565", 48, 48, flip=False)
    rep["icon"] = save(big, "icon48_x4.png", 4)
    bnr = (ROOT / "exefs/banner").read_bytes()
    assert bnr[:4] == b"CBMD"
    offs = struct.unpack_from("<14I", bnr, 8)
    rep["cbmd_cgfx_offsets"] = [hex(o) for o in offs]
    end = struct.unpack_from("<I", bnr, 0x84)[0] or len(bnr)
    starts = sorted({o for o in offs if o} | {end})
    texs = []
    for slot, o in enumerate(offs):
        if not o:
            continue
        nxt = min(x for x in starts if x > o)
        cg = lz11(bnr[o:nxt])
        for t in cgfx_textures(cg):
            entry = {"slot": slot, **{k: v for k, v in t.items() if k != "img"}}
            if t["img"]:
                s, dlen = t["img"]
                try:
                    rgba = T.decode(cg[s:s + dlen], t["fmt"], t["w"], t["h"])
                    entry["png"] = save(rgba, f"banner_s{slot}_{t['name']}.png", 2 if t["w"] <= 256 else 1)
                except Exception as e:  # noqa: BLE001
                    entry["error"] = repr(e)
            texs.append(entry)
    rep["banner_textures"] = texs
    (OUT / "home_assets.json").write_text(json.dumps(rep, ensure_ascii=False, indent=1), encoding="utf-8")
    print(json.dumps(rep, ensure_ascii=False, indent=1)[:4000])
    return 0


if __name__ == "__main__":
    sys.exit(main())
