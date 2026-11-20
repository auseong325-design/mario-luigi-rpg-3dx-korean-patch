"""Measure the Japanese bottom logo (title_logo_JP_bottom) and re-render it with model.py.

Outputs fit/jp_bottom.npz (masks, row tables) and review/fit_jp_*.png (original vs model).
Group ids: 1 マリオ, 2 &, 3 ルイージ, 4 R, 5 P, 6 G.
"""
from __future__ import annotations

import json
import sys

import numpy as np
from scipy import ndimage as ndi

import l2
import model as M
import seg_jp

# groups by x on the texture (1x): マリオ < 145, & = the component at (155, 120), ルイージ < 275,
# R < 311, P < 342, G < 380 (P and G touch)
X_SPLIT = [(1, 0, 145), (3, 145, 275), (4, 275, 311), (5, 311, 342), (6, 342, 380)]
SP = l2.HERE / "review"


def jp_masks(a):
    s = seg_jp.segment(a)
    cov, lab = s["cov"], s["lab"]
    F_groups = {}
    Fall = l2.up(cov) > 0.5
    labhr = l2.kron(lab.astype(np.int32))
    _, (iy, ix) = ndi.distance_transform_edt(labhr == 0, return_indices=True)
    nl = labhr[iy, ix]
    amp_id = lab[120, 155]
    xh = (np.arange(Fall.shape[1])[None, :] + 0.5) / l2.HR
    amp = Fall & (nl == amp_id)
    F_groups[2] = amp
    for g, x0, x1 in X_SPLIT:
        F_groups[g] = Fall & ~amp & (xh >= x0) & (xh < x1)
    return s, dict(sorted(F_groups.items()))


def face_rows(rgb, m1, sd1, H, gl1=None, sd_min=1.6):
    rows = np.full((H, 3), np.nan)
    inner = m1 & (sd1 > sd_min)
    if gl1 is not None:
        inner &= gl1 < 0.02
    cnt = np.zeros(H, int)
    for y in range(H):
        px = rgb[y][inner[y]]
        cnt[y] = len(px)
        if len(px) < 2:
            continue
        lum = px.mean(1)
        keep = lum <= np.percentile(lum, 60) + 12
        rows[y] = np.median(px[keep], 0)
    # the first rows are only a few rim-shaded pixels: hold the first well-sampled row upward
    rows[cnt < 2] = np.nan
    # the letters get darker downward: a sparsely sampled row much lighter than the row above is
    # gloss / rim contamination
    last = None
    for y in range(H):
        if np.isnan(rows[y, 0]):
            continue
        if last is not None and cnt[y] < 10 and rows[y].mean() > rows[last].mean() + 15:
            rows[y] = np.nan
            continue
        last = y
    good = np.nonzero(cnt >= max(10, 0.3 * cnt.max()))[0]
    if len(good):
        rows[: good[0]] = rows[good[0]]
    if np.isnan(rows[:, 0]).all():
        return np.full((H, 3), 255.0)
    return _fill(rows)


def _fill(rows, top=None):
    ok = ~np.isnan(rows[:, 0])
    ys = np.arange(len(rows))
    out = rows.copy()
    for c in range(3):
        out[:, c] = np.interp(ys, ys[ok], rows[ok, c])
    if top is not None:
        first = np.nonzero(ok)[0][0]
        out[:first] = top
    return out


def ext_rows(rgb, body1, cov, T1, own1, sdB1, g, H, navy):
    rows = np.full((H, 3), np.nan)
    m = body1 & (cov == 0) & (own1 == g) & (T1 > 0) & np.isfinite(T1) & (sdB1 > 1.2)
    for y in range(H):
        px = rgb[y][m[y]]
        if len(px) >= 2:
            rows[y] = px.mean(0)
    if np.isnan(rows[:, 0]).all():
        return np.tile(navy, (H, 1))
    # smooth a little along y (RGBA4 steps), keep navy above the first measured row
    ok = ~np.isnan(rows[:, 0])
    out = _fill(rows, top=navy)
    out = ndi.uniform_filter1d(out, 3, axis=0)
    out[: np.nonzero(ok)[0][0]] = navy
    return out


def measure(a, F_groups, P, s):
    H = a.shape[0]
    rgb = a[..., :3]
    geo = M.geometry(F_groups, P)
    sd1 = l2.centre(l2.sdf(geo["F"]))
    lab1 = np.rint(l2.centre(geo["lab"].astype(float))).astype(int)
    st = {"face": {}, "ext": {}}
    T1 = l2.centre(np.where(np.isfinite(geo["T"]), geo["T"], 99))
    T1[T1 >= 99] = np.inf
    own1 = geo["own"][HR // 2::HR, HR // 2::HR]
    Bjp = l2.up(s["body"].astype(float), order=1) > 0.5
    sdB1 = l2.centre(l2.sdf(Bjp))
    sd = l2.sdf(geo["F"])
    below = l2.shift_hr(sd, 0, -int(round(P.gl_d * HR)), fill=-10.0)
    glm = (sd > P.gl_a - 0.5) & (below < P.gl_a)
    gl1 = l2.down(ndi.binary_dilation(glm, iterations=HR // 2).astype(float))
    for g in F_groups:
        st["face"][g] = face_rows(rgb, (lab1 == g) & (s["cov"] >= 0.999), sd1, H, gl1)
        st["ext"][g] = ext_rows(rgb, s["body"], s["cov"], T1, own1, sdB1, g, H, np.asarray(P.navy, float))
    return st, geo


HR = l2.HR


def silhouettes(s, geo, a):
    """Body parts that are not outline/extrusion of a face (Mario / Luigi silhouettes).
    Returns a smooth hi-res mask from the original's soft coverage (navy vs white glow)."""
    B1 = s["body"]
    model1 = l2.down(geo["B"].astype(float)) > 0.5
    extra = B1 & ~ndi.binary_dilation(model1, iterations=2)
    lab, n = ndi.label(extra)
    sizes = ndi.sum(extra, lab, range(1, n + 1))
    big = 1 + np.nonzero(sizes >= 30)[0]
    seed = np.isin(lab, big)
    # grow back into the body (the feet touch the outline)
    sil = B1 & ndi.binary_dilation(seed, iterations=3) & ~model1 | seed
    # soft coverage around it: navy (lum 43) .. white glow (lum 255)
    lum = a[..., :3].mean(2)
    near = ndi.binary_dilation(sil, iterations=2)
    c = np.where(near, np.clip((255 - lum) / (255 - 45.3), 0, 1), 0) * (a[..., 3] / 255)
    c[sil] = np.maximum(c[sil], 0.0)
    return l2.up(c, order=3) > 0.5


def glow_stats(a, B1):
    Bh = l2.up(B1.astype(float), order=1) > 0.5
    dB = l2.centre(l2.dist_out(Bh))
    al = a[..., 3]
    out = []
    for d in np.arange(0, 16, 0.5):
        m = (dB >= d) & (dB < d + 0.5) & ~B1
        if m.sum():
            out.append((d, al[m].mean(), int(m.sum())))
    return out


def fit_rim(a, F_groups, st, sil, P):
    """Face rim: the outer ~1.5 px of a Japanese face is a darker, more saturated shade of the face
    (deep green on ルイージ, brown-red on マリオ), not a blend with the navy. Fit per word and channel
    rim = A * face + b by least squares on the edge pixels (gloss excluded); weight 1 - sd / rim_w."""
    amp_rgb = np.kron(a[..., :3], np.ones((HR, HR, 1)))
    P0 = M.Params(**{**P.__dict__, "rim_k": 0.0})
    st0 = {"face": st["face"], "ext": st["ext"]}
    R0, geo = M.render(F_groups, P0, st0, extra_body=sil, face_override={2: (amp_rgb, F_groups[2])})
    R0 = R0[..., :3]
    Fall, lab = geo["F"], geo["lab"]
    H = a.shape[0]
    sd = l2.sdf(Fall)
    below = l2.shift_hr(sd, 0, -int(round(P.gl_d * HR)), fill=-10.0)
    s = P.gl_soft
    gl = np.clip((sd - P.gl_a) / s + 0.5, 0, 1) * np.clip((P.gl_a - below) / s + 0.5, 0, 1)
    gl1 = l2.down(ndi.binary_dilation(gl > 0.01, iterations=HR).astype(float))
    r = np.clip(1 - sd / P.rim_w, 0, 1) * Fall
    rims = {}
    e0 = e1 = n = 0
    for g in (1, 3, 4, 5, 6):
        m = lab == g
        face = np.zeros(Fall.shape + (3,))
        face[m] = M._rows_hr(st["face"][g], H * HR)[np.nonzero(m)[0]]
        c0 = face + (255 - face) * (P.gl_k * gl)[..., None]
        mr = l2.down(m * r)
        mrc0 = l2.down((m * r)[..., None] * c0)
        mrF = l2.down((m * r)[..., None] * face)
        sel = (mr > 0.03) & (gl1 < 0.01) & (l2.down(m.astype(float)) > 0.3)
        sel[:, 385:] = False
        y = a[..., :3][sel] - R0[sel] + mrc0[sel]
        AB = []
        for c in range(3):
            X = np.stack([mrF[sel][:, c], mr[sel]], 1)
            sol, *_ = np.linalg.lstsq(X, y[:, c], rcond=None)
            AB.append(sol)
            pred = R0[sel][:, c] - mrc0[sel][:, c] + X @ sol
            e1 += np.abs(pred - a[..., c][sel]).sum()
            e0 += np.abs(R0[sel][:, c] - a[..., c][sel]).sum()
            n += sel.sum()
        rims[g] = np.array(AB)
    print("rim fit: edge px error %.2f -> %.2f" % (e0 / n, e1 / n))
    return rims


def fit_glow(a, body1):
    """Outer glow = curve(gaussian(body spread by `spread`, sigma)): grid search, monotone binned
    curve (alpha error 2.6/255; a distance-only profile gives 14.6). Left part only (the right part
    has the hidden DX/3 colours under the glow)."""
    Bh = l2.up(body1.astype(float), order=1) > 0.5
    al = a[..., 3] / 255
    dB = l2.centre(l2.dist_out(Bh))
    reg = ~body1 & (dB < 14)
    reg[:, 290:] = False
    best = None
    for sig in (3.75, 4.0, 4.25, 4.5, 5.0):
        for spread in (0.5, 1.0, 1.5):
            Bs = l2.dist_out(Bh) <= spread
            g = ndi.gaussian_filter(l2.down(Bs.astype(float)), sig)
            idx = np.clip((g[reg] * 200).astype(int), 0, 200)
            f = np.zeros(201)
            c = np.zeros(201)
            np.add.at(f, idx, al[reg])
            np.add.at(c, idx, 1)
            ok = c > 0
            fm = np.interp(np.arange(201), np.nonzero(ok)[0], f[ok] / c[ok])
            fm = np.maximum.accumulate(fm)
            e = np.abs(fm[idx] - al[reg]).mean() * 255
            if best is None or e < best[0]:
                best = (e, sig, spread, fm.tolist())
    print("glow fit: sigma %.2f spread %.1f alpha err %.2f" % (best[1], best[2], best[0]))
    json.dump(dict(sigma=best[1], spread=best[2], curve=best[3]), open(l2.HERE / "fit/glow.json", "w"))


def main():
    P = M.Params()
    a = l2.load(l2.JP_DIR / "title_logo_JP_bottom.png")
    s, F_groups = jp_masks(a)
    fit_glow(a, s["body"])
    M._GLOW = None
    st, geo = measure(a, F_groups, P, s)
    silhr = silhouettes(s, geo, a)
    print("glow alpha by distance outside body:")
    for d, m, n in glow_stats(a, s["body"]):
        print(f"  {d:4.1f} {m:6.1f} n={n}")
    # face override for & (its own drawing) -> keep original pixels at 1x via up-sampled rgb
    amp_rgb = np.kron(a[..., :3], np.ones((HR, HR, 1)))
    out, g2 = M.render(F_groups, P, st, extra_body=silhr, face_override={2: (amp_rgb, F_groups[2])})
    st["rim"] = fit_rim(a, F_groups, st, silhr, P)
    out, g2 = M.render(F_groups, P, st, extra_body=silhr, face_override={2: (amp_rgb, F_groups[2])})
    np.savez_compressed(l2.HERE / "fit/jp_bottom.npz",
                        **{f"rim{g}": t for g, t in st["rim"].items()},
                        **{f"F{g}": m for g, m in F_groups.items()}, sil=silhr,
                        **{f"face{g}": t for g, t in st["face"].items()},
                        **{f"ext{g}": t for g, t in st["ext"].items()})
    l2.save(out, l2.HERE / "fit/jp_bottom_rerender.png")
    oq = l2.q4(out)
    # comparison sheet
    x0, y0, x1, y1 = 40, 20, 400, 160
    A = l2.comp_on(a)[y0:y1, x0:x1]
    Bq = l2.comp_on(oq)[y0:y1, x0:x1]
    l2.sheet([[("original", A), ("model (RGBA4)", Bq)]], SP / "fit_jp_1x.png")
    zx0, zy0, zx1, zy1 = 50, 60, 200, 145
    za = l2.zoom_img(l2.comp_on(a)[zy0:zy1, zx0:zx1], 5)
    zb = l2.zoom_img(l2.comp_on(oq)[zy0:zy1, zx0:zx1], 5)
    l2.sheet([[("original", za)], [("model", zb)]], SP / "fit_jp_zoom_mario.png")
    zx0, zy0, zx1, zy1 = 160, 60, 300, 145
    za = l2.zoom_img(l2.comp_on(a)[zy0:zy1, zx0:zx1], 5)
    zb = l2.zoom_img(l2.comp_on(oq)[zy0:zy1, zx0:zx1], 5)
    l2.sheet([[("original", za)], [("model", zb)]], SP / "fit_jp_zoom_luigi.png")
    # error
    m = (a[..., 3] > 0) | (oq[..., 3] > 0)
    m[:, 280:] = False
    err = np.abs(l2.comp_on(a) - l2.comp_on(oq)).mean(2)
    print("mean abs err (left part, on blue):", err[m].mean().round(2))


if __name__ == "__main__":
    main()
