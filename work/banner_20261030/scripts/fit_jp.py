"""Register the Japanese title logo (FMdl title textures, v1.2) onto the Japanese banner logo
(COMMON_jp, upright) to learn how Nintendo placed the title art in the banner.

Model: banner(x, y) = title(x', y') with x = sx*x' + tx, y = sy*y' + ty (texture px, top row first),
fitted on premultiplied RGBA with a 4x supersampled warp. Fits the whole logo and each part
(word = bottom texture, numeral plate, DX block, TM) separately.
Writes fit/fit_jp.json + fit/fit_jp_overlay.png.
"""
from __future__ import annotations

import json
import sys
from pathlib import Path

import cv2
import numpy as np
from PIL import Image
from scipy import ndimage as ndi
from scipy.optimize import minimize

HERE = Path(__file__).resolve().parent
WORK = HERE.parent
E = WORK / "extract"
OUT = WORK / "fit"
S = 4


def load(p):
    return np.asarray(Image.open(p).convert("RGBA"), np.float32)


def premul(a):
    al = a[..., 3:] / 255.0
    return np.concatenate([a[..., :3] * al, a[..., 3:]], 2)


def warp(pm, p, shape):
    sx, sy, tx, ty = p
    A = np.array([[sx * S, 0, (tx + 0.5) * S - 0.5 - (0.5 * sx * S - 0.5 * S) * 0], [0, sy * S, (ty + 0.5) * S - 0.5]], np.float32)
    # pixel-centre convention: dst_c = s*src_c + t  (centres at +0.5)
    A[0, 2] = S * (tx + 0.5 * sx) - 0.5
    A[1, 2] = S * (ty + 0.5 * sy) - 0.5
    A[0, 0] = sx * S
    A[1, 1] = sy * S
    w = cv2.warpAffine(pm, A, (shape[1] * S, shape[0] * S), flags=cv2.INTER_LINEAR, borderValue=0)
    return cv2.resize(w, (shape[1], shape[0]), interpolation=cv2.INTER_AREA)


def fit(src_pm, dst_pm, p0, weight=None, blur=1.0):
    d = cv2.GaussianBlur(dst_pm, (0, 0), blur) if blur else dst_pm

    def err(p):
        w = warp(src_pm, p, dst_pm.shape)
        if blur:
            w = cv2.GaussianBlur(w, (0, 0), blur)
        r = np.abs(w - d).sum(2)
        if weight is not None:
            r = r * weight
        return float(r.mean())

    res = minimize(err, p0, method="Nelder-Mead",
                   options={"xatol": 1e-4, "fatol": 1e-4, "maxiter": 4000, "initial_simplex": None})
    return res.x, res.fun


def main() -> int:
    OUT.mkdir(exist_ok=True)
    bot = load(E / "title_jp_title_logo_JP_bottom.png")
    top = load(E / "title_jp_title_logo_JP_top.png")
    ban = load(E / "3dx_COMMON_jp.png")[::-1].copy()       # upright (row 0 = top)
    comp = np.asarray(Image.alpha_composite(Image.fromarray(np.uint8(bot)), Image.fromarray(np.uint8(top))), np.float32)
    B = premul(ban)
    rep = {}
    # initial guess from opaque bounding boxes
    def bbox(a, thr=128):
        ys, xs = np.nonzero(a[..., 3] >= thr)
        return xs.min(), ys.min(), xs.max() + 1, ys.max() + 1
    tb, bb = bbox(comp), bbox(ban)
    sx0 = (bb[2] - bb[0]) / (tb[2] - tb[0]); sy0 = (bb[3] - bb[1]) / (tb[3] - tb[1])
    p0 = [sx0, sy0, bb[0] - sx0 * tb[0], bb[1] - sy0 * tb[1]]
    rep["bbox_title"], rep["bbox_banner"], rep["p0"] = [int(v) for v in tb], [int(v) for v in bb], p0
    p, e = fit(premul(comp), B, p0, blur=1.5)
    p, e = fit(premul(comp), B, p, blur=0.6)
    rep["whole"] = {"p": [float(v) for v in p], "err": e, "x_over_y": float(p[0] / p[1])}
    print("whole", rep["whole"])
    # parts of the top texture: connected components of alpha
    lab, n = ndi.label(top[..., 3] > 16)
    sizes = ndi.sum(np.ones_like(lab), lab, range(1, n + 1))
    parts = {}
    for k in np.argsort(-sizes)[:6]:
        ys, xs = np.nonzero(lab == k + 1)
        parts[f"top_c{k+1}"] = (lab == k + 1, [int(xs.min()), int(ys.min()), int(xs.max()) + 1, int(ys.max()) + 1], int(sizes[k]))
    rep["top_components"] = {k: {"bbox": v[1], "px": v[2]} for k, v in parts.items()}
    print(rep["top_components"])
    # per-part fits: each part alone vs the banner, weighted to the part's neighbourhood
    res_parts = {}
    for name, (mask, box, _) in parts.items():
        src = top.copy()
        src[~mask] = 0
        pm = premul(src)
        w0 = warp(pm, rep["whole"]["p"], B.shape)[..., 3] > 4
        wt = ndi.binary_dilation(w0, iterations=6).astype(np.float32)
        pp, ee = fit(pm, B * wt[..., None], rep["whole"]["p"], weight=wt, blur=0.8)
        res_parts[name] = {"p": [float(v) for v in pp], "err": ee, "bbox_tex": box}
        print(name, res_parts[name])
    # word (bottom texture) alone
    pm = premul(bot)
    w0 = warp(pm, rep["whole"]["p"], B.shape)[..., 3] > 4
    wt = ndi.binary_dilation(w0, iterations=6).astype(np.float32)
    # exclude where the top texture covers the word
    cover = warp(premul(top), rep["whole"]["p"], B.shape)[..., 3] > 32
    wt[cover] = 0
    pp, ee = fit(pm, B * wt[..., None], rep["whole"]["p"], weight=wt, blur=0.8)
    res_parts["bottom_word"] = {"p": [float(v) for v in pp], "err": ee}
    print("bottom_word", res_parts["bottom_word"])
    rep["parts"] = res_parts
    (OUT / "fit_jp.json").write_text(json.dumps(rep, indent=1), encoding="utf-8")
    # overlay: banner vs warped title (whole fit), x3
    W = warp(premul(comp), rep["whole"]["p"], B.shape)
    bg = np.array([52, 52, 64], np.float32)
    f = lambda pm: np.uint8(np.clip(pm[..., :3] + bg * (1 - pm[..., 3:] / 255), 0, 255))
    diff = np.uint8(np.clip(np.abs(W - B).sum(2) / 3, 0, 255))
    sheet = np.concatenate([f(B), f(W), np.dstack([diff] * 3)], 0)
    Image.fromarray(sheet).resize((768, 1152), Image.NEAREST).save(OUT / "fit_jp_overlay.png")
    return 0


if __name__ == "__main__":
    sys.exit(main())
