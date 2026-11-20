"""The official Korean 「쿠파주니어」 / 「쿠파」 lettering (Korean Super Mario typeface), traced to vectors.

Samples supplied by the user (ref/web/official/, git-ignored):
  kupajunior_orange.png  「쿠파주니어」 - orange face, teal outline, pale ring; all five syllables, upright,
                         one width (56 px), open syllables 42 px tall, stacked ones (쿠 주) 56 px. The right
                         ring is cut by the crop, the faces are complete.
  kupa_rainbow.png       「쿠파」 - gradient face, black outline, blue ring; the same glyphs set as a logo:
                         each syllable turned on its own, tight spacing.

glyph(ch) returns the syllable from the orange sample as a shapely geometry in sample pixels, its box at
(0, 0) (x to the right, y down). All five share one scale (UNIT = 56 px = one syllable width), so the
relative sizes of the official set are kept when they are placed with one scale.
"""
from __future__ import annotations

import functools
import math

import numpy as np
from PIL import Image
from scipy import ndimage as ndi
from shapely import affinity

import glyphs as G

HERE = G.HERE
OFFICIAL = HERE / "ref/web/official"
UNIT = 56.0                      # syllable width in the orange sample (px)
SYLLABLES = "쿠파주니어"
EPS = 0.45                       # polygon tolerance (sample px)


def coverage_orange(a):
    """face coverage: orange / yellow face (b < 140), partial towards the dark teal outline."""
    r, b = a[..., 0], a[..., 2]
    return np.clip((r - 8.0) / 231.0, 0, 1) * (b < 140)


def coverage_rainbow(a):
    r, g, b = a[..., 0], a[..., 1], a[..., 2]
    face = (r >= 90) & ~((g > 140) & (r < 200))
    mx = a.max(-1)
    edge = (mx > 30) & (mx < 90) & (b < 120)
    return np.where(face, 1.0, np.where(edge, mx / 255.0, 0.0))


def load(name):
    return np.asarray(Image.open(OFFICIAL / name).convert("RGB")).astype(float)


@functools.lru_cache(None)
def syllable_boxes():
    """x ranges of the five syllables in the orange sample, from the face components."""
    cov = coverage_orange(load("kupajunior_orange.png"))
    lab, n = ndi.label(cov > 0.5)
    comps = [(sl[1].start, sl[1].stop, sl[0].start, sl[0].stop) for sl in ndi.find_objects(lab)
             if (lab[sl] > 0).sum() > 50]
    comps.sort()
    groups = []
    for c in comps:                                   # jamo stacked in one column = one syllable
        if groups and c[0] < groups[-1][1] - 10:
            g = groups[-1]
            groups[-1] = (min(g[0], c[0]), max(g[1], c[1]), min(g[2], c[2]), max(g[3], c[3]))
        else:
            groups.append(c)
    assert len(groups) == 5, groups
    return dict(zip(SYLLABLES, groups))


@functools.lru_cache(None)
def glyph(ch):
    cov = coverage_orange(load("kupajunior_orange.png"))
    x0, x1, y0, y1 = syllable_boxes()[ch]
    pad = 3
    sub = cov[y0 - pad:y1 + pad, x0 - pad:x1 + pad].copy()
    # keep only this syllable's components (the neighbours' anti-aliased edges stay out)
    lab, _ = ndi.label(sub > 0.5)
    keep = np.isin(lab, np.unique(lab[pad:-pad, pad:-pad][sub[pad:-pad, pad:-pad] > 0.5]))
    sub = sub * ndi.binary_dilation(keep, iterations=2)
    g = G._vectorise(sub, up=8, eps=EPS, x0=x0 - pad, y0=y0 - pad)
    b = g.bounds
    return affinity.translate(g, -b[0], -b[1])


def stroke_widths():
    """median stroke width (sample px) from the distance transform on the skeleton-like ridge."""
    cov = coverage_orange(load("kupajunior_orange.png")) > 0.5
    dt = ndi.distance_transform_edt(cov)
    ridge = (dt == ndi.maximum_filter(dt, 3)) & (dt > 2)
    return float(np.median(2 * dt[ridge]))


def rainbow_turns():
    """turn of each syllable in the rainbow 「쿠파」 (deg, + = clockwise): the long axis of its bars."""
    import cv2
    cov = coverage_rainbow(load("kupa_rainbow.png")) > 0.5
    lab, n = ndi.label(cov)
    out = []
    for i, sl in enumerate(ndi.find_objects(lab)):
        m = (lab == i + 1).astype(np.uint8)
        ys, xs = np.nonzero(m)
        if len(xs) < 100:
            continue
        # top edge slope: for every column, the first face row
        cols = np.unique(xs)
        top = np.array([ys[xs == c].min() for c in cols])
        k = np.polyfit(cols[5:-5], top[5:-5], 1)[0]
        out.append(dict(bbox=[int(xs.min()), int(ys.min()), int(xs.max()), int(ys.max())],
                        top_edge_deg=round(math.degrees(math.atan(k)), 1)))
    return out


if __name__ == "__main__":
    for ch in SYLLABLES:
        g = glyph(ch)
        b = g.bounds
        n = sum(len(p.exterior.coords) for p in getattr(g, "geoms", [g]))
        print(ch, "box", [round(v, 1) for v in b], "nodes", n)
    print("stroke width (sample px)", stroke_widths())
    print("rainbow components", rainbow_turns())


def trace_sheet(out=HERE / "sheets/official_trace.png"):
    """sample / traced vector / overlay, x4."""
    import sheet as SH
    from shapely.ops import unary_union
    a = load("kupajunior_orange.png")
    cov = coverage_orange(a)
    H, W = cov.shape
    placed = []
    for ch in SYLLABLES:
        x0, x1, y0, y1 = syllable_boxes()[ch]
        g = glyph(ch)
        # back to sample position: the traced box starts where the face starts
        sub = cov[y0:y1, x0:x1] > 0.5
        ys, xs = np.nonzero(sub)
        placed.append(affinity.translate(g, x0 + xs.min() - 0.0 + (g.bounds[0]), y0 + ys.min()))
    vec = G.raster(unary_union(placed), (H, W))
    bw = np.repeat((255 * (1 - vec))[..., None], 3, 2)
    ov = np.full((H, W, 3), 255.0)
    c, v = (cov > 0.5)[..., None], vec[..., None]
    ov = ov * (1 - 0.5 * c) + np.array([230, 90, 20]) * 0.5 * c
    ov = ov * (1 - 0.5 * v) + np.array([20, 80, 230]) * 0.5 * v
    iou = float(((cov > 0.5) & (vec > 0.5)).sum() / ((cov > 0.5) | (vec > 0.5)).sum())
    z = 4
    SH.sheet([[("공식 「쿠파주니어」 (사용자 제공) x4", G.l2.zoom_img(a, z))],
              [("벡터로 옮긴 글자 면 x4", G.l2.zoom_img(bw, z))],
              [(f"겹침 (주황 = 공식, 파랑 = 벡터) IoU {iou:.3f}", G.l2.zoom_img(ov, z))]], out)
    return iou
