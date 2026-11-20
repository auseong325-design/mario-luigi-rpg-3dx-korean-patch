"""Cross-check: the fitted 쿠 / 파 (from the small orange 「쿠파주니어」) against the larger rainbow 「쿠파」
(ref/web/official/kupa_rainbow.png). Only a similarity transform per syllable (scale, turn, shift) is
fitted; a high IoU means both samples are the same glyphs and gives the logo turns of the rainbow set.
Writes sheets/official_rainbow_check.png and rainbow_check.json."""
from __future__ import annotations

import json

import numpy as np
from scipy import ndimage as ndi
from scipy.optimize import minimize
from shapely import affinity

import fit_official as F
import glyphs as G
import official as O

HERE = G.HERE


def main():
    a = O.load("kupa_rainbow.png")
    cov = O.coverage_rainbow(a)
    lab, n = ndi.label(cov > 0.5)
    H, W = cov.shape
    xx = np.arange(W)[None, :]
    rep, placed = {}, []
    for ch, (x0, x1) in (("쿠", (0, 85)), ("파", (85, W))):
        T = cov * ((xx >= x0) & (xx < x1))
        g0 = F.glyph(ch)
        ys, xs = np.nonzero(T > 0.5)
        s0 = (xs.max() - xs.min()) / (g0.bounds[2] - g0.bounds[0])

        def make(v):
            s, rot, tx, ty = v
            g = affinity.scale(g0, s, s, origin=(0, 0))
            g = affinity.rotate(g, rot, origin="centroid")
            return affinity.translate(g, tx, ty)

        def loss(v):
            return float(((G.raster(make(v), (H, W)) - T) ** 2).sum())
        v0 = [s0, 0.0, float(xs.min()), float(ys.min())]
        best = None
        for r0 in (-8, -4, 0, 4, 8):
            res = minimize(loss, [v0[0], r0, v0[2], v0[3]], method="Powell", options=dict(maxfev=3000))
            if best is None or res.fun < best.fun:
                best = res
        R = G.raster(make(best.x), (H, W))
        iou = float(((R > 0.5) & (T > 0.5)).sum() / ((R > 0.5) | (T > 0.5)).sum())
        rep[ch] = dict(scale=round(float(best.x[0]), 3), turn_deg=round(float(best.x[1]), 2), iou=round(iou, 3))
        placed.append(R)
        print(ch, rep[ch])
    R = np.maximum(*placed)
    T = cov
    ov = np.full((H, W, 3), 255.0)
    c, v = (T > 0.5)[..., None], R[..., None]
    ov = ov * (1 - 0.5 * c) + np.array([230, 90, 20]) * 0.5 * c
    ov = ov * (1 - 0.5 * v) + np.array([20, 80, 230]) * 0.5 * v
    import sheet as SH
    SH.sheet([[("공식 「쿠파」 (무지개, x4)", G.l2.zoom_img(a, 4)),
               ("맞춘 쿠·파를 크기·회전만 맞춰 겹침 x4 (주황 = 공식, 파랑 = 벡터)", G.l2.zoom_img(ov, 4))]],
             HERE / "sheets/official_rainbow_check.png")
    (HERE / "rainbow_check.json").write_text(json.dumps(rep, ensure_ascii=False, indent=1), encoding="utf-8")


if __name__ == "__main__":
    main()
