"""Korean intro pieces title_logo_M_JP / title_logo_L_JP (128x64 RGBA4, no glow): 마리오 / 루이지.

The words are the Korean bottom-layer letters (fit/kr_bottom_layout.npz) scaled by k and rendered with
the model fitted on each Japanese piece (fit_piece.py: thinner outline, darker navy, soft edge).
The Japanese pieces hold their word at 0.90 of the bottom layer; the Korean words are taller (the 1DX
heads of 마 / 루), so k is the largest scale whose body still fits the 64 rows (about 0.745).
"""
from __future__ import annotations

import json

import numpy as np
from scipy import ndimage as ndi

import l2
import model as M

HR = l2.HR
PIECES = {"title_logo_M_JP": ("Fma", 1, (8, 52)), "title_logo_L_JP": ("Flu", 3, (9, 49))}
HEAD_LIGHT = {1: 0.25, 3: 0.0}


def scale_mask(F_hr, k):
    """Scale a hi-res mask by k about the origin through its signed distance (smooth edges)."""
    ys, xs = np.nonzero(F_hr)
    y0, y1, x0, x1 = ys.min(), ys.max() + 1, xs.min(), xs.max() + 1
    pad = 8 * HR
    crop = F_hr[max(y0 - pad, 0):y1 + pad, max(x0 - pad, 0):x1 + pad]
    sd = l2.sdf(crop)
    z = ndi.zoom(sd, k if np.ndim(k) == 0 else tuple(k), order=1)
    return z > 0


def build(name, key, gid, band_jp, k=None, kx=0.88):
    lay = np.load(l2.HERE / "fit/kr_bottom_layout.npz")
    Fw = lay[key]
    top_small_bottom = float(lay["top_small"])     # top of the small letters on the bottom layer
    a = l2.load(l2.JP_DIR / f"{name}.png")
    H1, W1 = a.shape[:2]
    cfg = json.load(open(l2.HERE / f"fit/piece_{name}.json"))
    z = np.load(l2.HERE / f"fit/piece_{name}.npz")
    P = M.Params(r_o=cfg["r_o"], sx=cfg["sx"], D=cfg["D"], r_e=cfg["r_e"], navy=tuple(cfg["navy"]),
                 glow=False, blur=cfg["blur"],
                 # gloss of the big logo scaled to the piece (the pieces are drawn at 0.9 of it)
                 gl_a=1.0, gl_d=2.0, gl_k=1.0)
    ys, xs = np.nonzero(Fw)
    word_h = (ys.max() + 1 - ys.min()) / HR
    reach_top = P.r_e + P.blur * 2
    reach_bot = P.D + P.r_e + P.blur * 2
    if k is None:
        k = min(0.90, (H1 - 1 - reach_top - reach_bot) / word_h)
    # height: what fits; width: the Japanese piece/bottom ratio (0.90 -> 0.88), so the word keeps
    # its weight on screen (the Japanese pieces show their word as large as the final logo)
    kx = max(kx, k)
    Fs = scale_mask(Fw, (k, kx))
    hs, ws = Fs.shape
    ys2, xs2 = np.nonzero(Fs)
    fy0, fy1 = ys2.min(), ys2.max() + 1
    fx0, fx1 = xs2.min(), xs2.max() + 1
    # vertical: body centred in the texture; horizontal: face box centred on the Japanese one
    body_top = fy0 / HR - reach_top
    body_bot = fy1 / HR + reach_bot
    oy = (H1 - (body_bot - body_top)) / 2 - body_top
    sj = np.nonzero(z["F"].any(0))[0]
    cx_jp = (sj.min() + sj.max() + 1) / 2 / HR
    ox = cx_jp - (fx0 + fx1) / 2 / HR
    F = np.zeros((H1 * HR, W1 * HR), bool)
    dy, dx = int(round(oy * HR)), int(round(ox * HR))
    yy, xx = np.nonzero(Fs)
    yy, xx = yy + dy, xx + dx
    ok = (yy >= 0) & (yy < F.shape[0]) & (xx >= 0) & (xx < F.shape[1])
    if not ok.all():
        print("  WARNING: word clipped", (~ok).sum())
    F[yy[ok], xx[ok]] = True
    # face gradient: Japanese piece band -> Korean small letters (scaled like the word)
    bot = np.nonzero(F.any(1))[0].max() / HR + 1 / HR
    word_top_b = ys.min() / HR
    top_small = (fy0 + dy) / HR + (top_small_bottom - word_top_b) * k
    head_top = np.nonzero(F.any(1))[0].min() / HR
    y = np.arange(H1, dtype=float)
    src = band_jp[0] + (y - top_small) * (band_jp[1] - band_jp[0]) / (bot - top_small)
    tab = z["face"]
    f = np.stack([np.interp(np.clip(src, 0, H1 - 1), np.arange(H1), tab[:, c]) for c in range(3)], 1)
    t = np.clip((top_small - y) / max(top_small - head_top, 1), 0, 1)
    face = f + (255 - f) * (HEAD_LIGHT[gid] * t)[:, None]
    # extrusion rows: shift the Japanese table so it starts at the same distance below the letters
    ext = z["ext"]
    shift = bot - band_jp[1]
    ext_s = np.stack([np.interp(y - shift, np.arange(H1), ext[:, c]) for c in range(3)], 1)
    jb = np.load(l2.HERE / "fit/jp_bottom.npz")
    st = {"face": {gid: face}, "ext": {gid: ext_s}, "rim": {gid: jb[f"rim{gid}"]}}
    out, geo = M.render({gid: F}, P, st)
    al = out[..., 3]
    ys3, xs3 = np.nonzero(al > 0)
    print(f"{name}: k {k:.3f} kx {kx:.3f}  alpha box x {xs3.min()}-{xs3.max()} y {ys3.min()}-{ys3.max()}")
    q = l2.q4(out)
    q[q[..., 3] == 0, :3] = np.asarray(P.navy, float)    # colour under alpha 0, like the original
    l2.save(q, l2.HERE / f"out/{name}.png")
    return q, k


if __name__ == "__main__":
    for nm, (key, gid, band) in PIECES.items():
        build(nm, key, gid, band)
