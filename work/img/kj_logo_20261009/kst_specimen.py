"""sheets/kst_specimen.png - the KST syllables (kst.py) next to the official samples they are drawn from."""
from __future__ import annotations

import numpy as np
from PIL import Image
from shapely import affinity

import glyphs as G
import kst as K
import sheet as SH

HERE = G.HERE
WEB = HERE / "ref/web"


def ref(p, crop, s):
    im = Image.open(WEB / p).convert("RGBA").crop(crop)
    bg = Image.new("RGBA", im.size, (255, 255, 255, 255))
    bg.alpha_composite(im)
    bg = bg.resize((int(im.width * s), int(im.height * s)), Image.LANCZOS)
    return np.asarray(bg.convert("RGB")).astype(float)


def render(g, height, pad=6):
    b = g.bounds
    s = height / (b[3] - b[1])
    g = affinity.scale(g, s, s, origin=(0, 0))
    b = g.bounds
    g = affinity.translate(g, pad - b[0], pad - b[1])
    W = int(np.ceil(g.bounds[2] + pad))
    H = int(np.ceil(g.bounds[3] + pad))
    cov = G.raster(g, (H, W))
    return np.repeat((255 * (1 - cov))[..., None], 3, 2)


def main(out=HERE / "sheets/kst_specimen.png"):
    syl = "쿠파주니어"
    big = [(ch, render(K.kst(ch), 150)) for ch in syl]
    small = []
    for ch, h in zip(syl, (34, 32, 20, 18, 19)):
        small.append((f"{ch} {h}px x4", G.l2.zoom_img(render(K.kst(ch), h, pad=3), 4)))
    rows = [
        [("「가든 배틀」 MP9 미니게임 (x2)", ref("mp9_garden_battle_sheet.png", (10, 558, 352, 652), 2.0)),
         ("「쿠」 밴쿠버 (x3)", ref("kst/MandSOWG_Korean_Logo.png", (165, 85, 235, 145), 3.0))],
        [("「파」 마리오파티 9 (x3)", ref("kst/MP9_K_Logo.png", (195, 40, 262, 105), 3.0)),
         ("「투어」 아일랜드 투어 (x4)", ref("kst/MPIT_KR_Logo.png", (212, 52, 285, 98), 4.0)),
         ("「스티커」 스티커 스타 (x2)", ref("kst/PMSS_KR_logo.png", (80, 95, 240, 158), 2.0))],
        big,
        small,
    ]
    print(SH.sheet(rows, out, bg=(70, 70, 76), max_px=1800))


if __name__ == "__main__":
    main()
