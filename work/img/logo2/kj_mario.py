"""「쿠파주니어」 assembled from the Korean MARIO Font (Nintendo's Korean version of the Mario series font).

The Japanese 「クッパJr.」 of the 3DX file-select logo is set in MARIO Font (checked against
MARIO_Font_v3_Solid.otf: same glyphs, each letter turned on its own). MARIO Font's Korean version is not
public; it is the lettering of Nintendo of Korea's 「슈퍼 마리오 RPG」 logo subtitle (and the Paper Mario
logos). Its strokes are cut out of that subtitle (ref/kr_smrpg_logo.png, 「슈퍼 마리오 RPG」, whose
RPG matches MARIO Font exactly) and put together into 쿠 파 주 니 어:

  쿠 = ㅋ (ㅍ top bar x2 + ㅏ stem, as the right descender) + ㅜ (ㅠ of 슈 with one centred leg)
  파 = ㅍ of 퍼 + ㅏ of 마
  주 = ㅈ (ㅍ top bar + ㅅ of 슈 under it) + ㅜ
  니 = ㄴ (ㅣ stem + ㅍ bottom bar) + ㅣ of 리
  어 = ㅇ of 오 (narrowed, the small diamond counter kept) + ㅓ of 퍼

Coordinates: reference px (cap height 44: the ㅣ of 리 runs y 504..548); syllables are returned with the
cap line at y = 0.
"""
from __future__ import annotations

import cv2
import numpy as np
from PIL import Image
from scipy import ndimage as ndi
from shapely import affinity
from shapely.geometry import Polygon, box
from shapely.ops import unary_union

import l2

REF = l2.HERE / "ref/kr_smrpg_logo.png"
X0, Y0 = 380, 488          # crop origin of the subtitle band
UP = 8                     # vectorising resolution


def _coverage():
    im = np.asarray(Image.open(REF).convert("RGBA")).astype(float)
    reg = im[Y0:562, X0:910]
    lum = reg[..., :3].mean(2) * reg[..., 3] / 255
    cov = np.clip((lum - 60) / (220 - 60), 0, 1)
    cov[:4] = 0                                   # the ribbon's top line
    return cov


def _vectorise(cov):
    """soft coverage -> list of shapely polygons (absolute reference px), straight edges kept."""
    big = ndi.zoom(cov, UP, order=3, grid_mode=True, mode="nearest") > 0.5
    cnts, hier = cv2.findContours(big.astype(np.uint8), cv2.RETR_CCOMP, cv2.CHAIN_APPROX_NONE)
    polys = []
    for i, c in enumerate(cnts):
        if hier[0][i][3] != -1:
            continue
        ap = cv2.approxPolyDP(c, 0.45 * UP, True)[:, 0, :].astype(float)
        if len(ap) < 3:
            continue
        holes = []
        j = hier[0][i][2]
        while j != -1:
            h = cv2.approxPolyDP(cnts[j], 0.45 * UP, True)[:, 0, :].astype(float)
            if len(h) >= 3:
                holes.append([(x / UP + X0, y / UP + Y0) for x, y in h])
            j = hier[0][j][0]
        p = Polygon([(x / UP + X0, y / UP + Y0) for x, y in ap], holes).buffer(0)
        if p.area > 4:
            polys.append(p)
    return polys


_PIECES = None


def pieces():
    global _PIECES
    if _PIECES is None:
        polys = _vectorise(_coverage())
        def pick(x0, x1, y0, y1):
            g = unary_union([p for p in polys if box(x0, y0, x1, y1).contains(p.centroid)])
            return g.intersection(box(x0, y0, x1, y1))
        P = {}
        P["ㅅ"] = pick(414, 472, 498, 530)
        P["ㅠ"] = pick(414, 478, 530, 553)
        P["ㅍ_top"] = pick(478, 519, 505, 519)
        P["ㅍ_low"] = pick(478, 519, 519, 545)
        P["ㅓ"] = pick(517, 540, 500, 550)
        P["ㅁ"] = pick(554, 594, 505, 545)
        P["ㅏ"] = pick(594, 620, 500, 550)
        P["ㄹ"] = pick(620, 658, 505, 546)
        P["ㅣ"] = pick(657, 677, 500, 550)
        P["ㅇ"] = pick(678, 733, 498, 533)
        P["ㅗ"] = pick(678, 733, 533, 553)
        _PIECES = P
    return _PIECES


def _norm(g, x, y):
    """move g so its bbox top-left is at (x, y)."""
    b = g.bounds
    return affinity.translate(g, x - b[0], y - b[1])


def _fit(g, x0, y0, x1, y1):
    b = g.bounds
    g = affinity.scale(g, (x1 - x0) / (b[2] - b[0]), (y1 - y0) / (b[3] - b[1]), origin=(b[0], b[1]))
    return _norm(g, x0, y0)


def _leg(P):
    """the left leg of ㅠ (below its bar) as a separate piece."""
    yu = P["ㅠ"]
    b = yu.bounds
    return yu.intersection(box(b[0], 541.5, (b[0] + b[2]) / 2, b[3] + 1))


def ju_vowel(P, w):
    """ㅜ: the bar of ㅠ (stretched to width w) + one of its legs, centred."""
    yu = P["ㅠ"]
    b = yu.bounds
    bar = yu.intersection(box(b[0] - 1, b[1] - 1, b[2] + 1, 541.5))
    bar = _fit(bar, 0, 0, w, bar.bounds[3] - bar.bounds[1])
    leg = _leg(P)
    lb = leg.bounds
    leg = _norm(leg, (w - (lb[2] - lb[0])) / 2, bar.bounds[3] - 0.6)
    return unary_union([bar, leg])


def syllables():
    """dict name -> polygon, cap line y = 0, reference px."""
    P = pieces()
    top = P["ㅍ_top"]
    S = {}
    # 쿠: ㅋ = top bar, middle bar (shorter, a little thinner), right descender (ㅏ stem cut)
    w = 50.0
    a = P["ㅏ"]
    ab = a.bounds
    stem = a.intersection(box(ab[0] - 1, ab[1] - 1, ab[0] + 12.6, ab[1] + 27))
    k_top = _fit(top, 1, 0, w - 3, 9.6)
    k_mid = _fit(top, 4, 14.0, w - 12, 22.2)
    k_stem = _fit(stem, w - 15.5, 0, w - 3, 28.5)
    u = affinity.translate(ju_vowel(P, w), 0, 31.0)
    S["쿠"] = unary_union([k_top, k_mid, k_stem, u])
    # 파: ㅍ of 퍼 + ㅏ of 마 (left-positioned ㅍ already)
    p = unary_union([P["ㅍ_top"], P["ㅍ_low"]])
    pb = p.bounds
    p = _fit(p, 0, 4.0, 38.5, 4.0 + (pb[3] - pb[1]))
    a2 = _norm(P["ㅏ"], 40.5, 0)
    S["파"] = unary_union([p, a2])
    # 주: ㅈ = top bar + ㅅ (its apex under the bar) + ㅜ
    s = P["ㅅ"]
    sb = s.bounds
    s_cut = s.intersection(box(sb[0] - 1, sb[1] + 6.5, sb[2] + 1, sb[3] + 1))
    s_cut = _fit(s_cut, 3.0, 7.5, w - 3.0, 29.0)
    j_top = _fit(top, 1, 0, w - 1, 9.6)
    S["주"] = unary_union([j_top, s_cut, u])
    # 니: ㄴ = ㅣ stem (shortened) + ㅍ bottom bar; ㅣ of 리
    i = P["ㅣ"]
    ib = i.bounds
    n_stem = _fit(i.intersection(box(ib[0] - 1, ib[1] - 1, ib[2] + 1, ib[1] + 34)), 0, 1.5, 13.0, 36.0)
    low = P["ㅍ_low"]
    lb = low.bounds
    n_foot = low.intersection(box(lb[0] - 1, lb[3] - 11.5, lb[2] + 1, lb[3] + 1))
    n_foot = _fit(n_foot, 0, 31.0, 27.0, 42.0)
    S["니"] = unary_union([n_stem, n_foot, _norm(i, 31.0, 0)])
    # 어: ㅇ narrowed and made taller (counter kept small), ㅓ of 퍼
    o = P["ㅇ"]
    ob = o.bounds
    outer = Polygon(o.exterior.coords) if hasattr(o, "exterior") else unary_union(o.geoms).convex_hull
    outer = _fit(outer, 0, 4.0, 30.0, 40.0)
    c = outer.centroid
    hole = Polygon([(c.x, c.y - 6.0), (c.x + 3.6, c.y - 0.5), (c.x, c.y + 4.5), (c.x - 3.6, c.y - 0.5)])
    ring = outer.difference(hole)
    eo = _norm(P["ㅓ"], 29.0, 0)
    S["어"] = unary_union([ring, eo])
    return S


ORDER = ["쿠", "파", "주", "니", "어"]
TILT = [-4.0, 3.0, -3.0, 4.0, -3.0]      # each letter turned on its own, like クッパJr.
BOB = [1.5, -1.0, 0.5, -1.5, 0.5]       # small cap-line offsets (ref px), like the subtitle


if __name__ == "__main__":
    from PIL import ImageDraw
    S = syllables()
    SS = 6
    img = Image.new("L", (360 * SS // 2, 70 * SS // 2), 0)
    d = ImageDraw.Draw(img)
    x = 5
    for name in ORDER:
        g = S[name]
        for p in getattr(g, "geoms", [g]):
            d.polygon([((x + px) * SS / 2, (8 + py) * SS / 2) for px, py in p.exterior.coords], fill=255)
            for h in p.interiors:
                d.polygon([((x + px) * SS / 2, (8 + py) * SS / 2) for px, py in h.coords], fill=0)
        x += g.bounds[2] + 6
    img.save(l2.HERE / "review/kj_mario_glyphs.png")
    print({k: tuple(round(v, 1) for v in g.bounds) for k, g in S.items()})
