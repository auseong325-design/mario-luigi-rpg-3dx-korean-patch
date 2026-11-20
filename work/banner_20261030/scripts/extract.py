"""Unpack the 3DX and 1DX HOME Menu banners: decompressed CGFX, BCWAV, every texture as PNG,
a texture sheet, and extract/banners.json. Read-only on originals."""
from __future__ import annotations

import hashlib
import json
import sys
from pathlib import Path

import numpy as np
from PIL import Image, ImageDraw

HERE = Path(__file__).resolve().parent
WORK = HERE.parent
ROOT = WORK.parents[1]
sys.path.insert(0, str(HERE))
sys.path.insert(0, str(ROOT / "scripts"))
import bnr  # noqa: E402
import libtex3ds as T  # noqa: E402

OUT = WORK / "extract"
SRC = {"3dx": ROOT / "exefs/banner", "1dx": ROOT / "ml 1dx/3exefs/banner"}


def checker(w, h, s=8):
    yy, xx = np.mgrid[:h, :w]
    c = np.where(((yy // s) + (xx // s)) % 2 == 0, 200, 150).astype(np.uint8)
    return np.dstack([c, c, c])


def over_checker(rgba):
    a = rgba[..., 3:4] / 255.0
    bg = checker(rgba.shape[1], rgba.shape[0])
    return np.uint8(np.clip(rgba[..., :3] * a + bg * (1 - a), 0, 255))


def main() -> int:
    OUT.mkdir(exist_ok=True)
    rep = {}
    for game, path in SRC.items():
        raw = path.read_bytes()
        c = bnr.parse_cbmd(raw)
        cg = c["cgfx"]
        (OUT / f"{game}_banner.cgfx").write_bytes(cg)
        (OUT / f"{game}_banner.bcwav").write_bytes(c["bcwav"])
        texs = bnr.cgfx_textures(cg)
        tiles = []
        for t in texs:
            im = t["img"]
            rgba = T.decode(cg[im["data_off"]:im["data_off"] + im["data_len"]], t["fmt"], t["w"], t["h"])
            Image.fromarray(rgba, "RGBA").save(OUT / f"{game}_{t['name']}.png")
            # re-encode check (lossless formats must round-trip byte-exactly)
            if t["fmt"] in ("RGBA4", "A4", "A8", "LA8", "RGB565", "RGBA5551", "RGBA8", "RGB8", "LA4", "L8"):
                t["reencode_identical"] = T.encode(rgba, t["fmt"]) == cg[im["data_off"]:im["data_off"] + im["data_len"]]
            t["alpha_hist"] = {"0": int((rgba[..., 3] == 0).sum()), "255": int((rgba[..., 3] == 255).sum()),
                               "mid": int(((rgba[..., 3] > 0) & (rgba[..., 3] < 255)).sum())}
            ys, xs = np.nonzero(rgba[..., 3] > 0)
            t["alpha_bbox"] = [int(xs.min()), int(ys.min()), int(xs.max()) + 1, int(ys.max()) + 1] if len(xs) else None
            tiles.append((t["name"], rgba))
        # sheet: each texture x2 over checker, labelled
        sc = 2
        W = sum(r.shape[1] * sc + 8 for _, r in tiles) + 8
        H = max(r.shape[0] * sc for _, r in tiles) + 24
        sheet = Image.new("RGB", (W, H), (60, 60, 70))
        x = 8
        d = ImageDraw.Draw(sheet)
        for n, r in tiles:
            im = Image.fromarray(over_checker(r)).resize((r.shape[1] * sc, r.shape[0] * sc), Image.NEAREST)
            sheet.paste(im, (x, 20))
            d.text((x, 4), f"{n} {r.shape[1]}x{r.shape[0]}", fill=(255, 255, 255))
            x += im.width + 8
        if sheet.width > 1600:
            k = 1600 / sheet.width
            sheet = sheet.resize((1600, int(sheet.height * k)), Image.LANCZOS)
        sheet.save(OUT / f"{game}_textures_sheet.png")
        rep[game] = {"file": str(path), "sha256": hashlib.sha256(raw).hexdigest(), "size": len(raw),
                     "cgfx_sha256": hashlib.sha256(cg).hexdigest(), "cgfx_size": len(cg),
                     "cgfx_comp_len": c["cgfx_comp_len"], "bcwav_off": c["bcwav_off"],
                     "bcwav_size": len(c["bcwav"]),
                     "textures": [{k: v for k, v in t.items()} for t in texs]}
    (OUT / "banners.json").write_text(json.dumps(rep, indent=1), encoding="utf-8")
    for g, r in rep.items():
        for t in r["textures"]:
            print(g, t["name"], t["w"], t["h"], t["fmt"], t.get("reencode_identical"), t["alpha_bbox"], t["alpha_hist"])
    return 0


if __name__ == "__main__":
    sys.exit(main())
