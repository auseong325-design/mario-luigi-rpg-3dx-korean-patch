"""Fit model.py on the intro pieces title_logo_M_JP / title_logo_L_JP (128x64, no glow).

Body geometry (r_o, sx, D, r_e) by IoU, face / extrusion row tables, gloss inset/shift by face error.
Output fit/piece_<name>.npz + fit/piece_<name>.json, review/fit_piece_<name>.png.
"""
from __future__ import annotations

import itertools
import json
import sys

import numpy as np
from scipy import ndimage as ndi

import l2
import model as M
import seg_jp
from fit_jp import face_rows, ext_rows

HR = l2.HR


def fit(name, gid):
    a = l2.load(l2.JP_DIR / f"{name}.png")
    H1, W1 = a.shape[:2]
    rgb_all = a[..., :3]
    s = seg_jp.segment(a)
    F = l2.up(s["cov"]) > 0.5
    B = l2.up(s["body"].astype(float), order=1) > 0.5
    dF = l2.dist_out(F)
    best = None
    for r_o in (1.5, 2.0, 2.5, 3.0, 3.5):
        O = dF <= r_o
        for sx in (0.3, 0.5, 0.75, 1.0):
            for D in (3, 4, 5, 6, 7):
                for r_e in (1.5, 2.0, 2.5, 3.0, 3.5, 4.0):
                    E = np.isfinite(M.sweep_dist(dF <= r_e, sx, D, step=0.5))
                    Bm = O | E
                    iou = (Bm & B).sum() / (Bm | B).sum()
                    if best is None or iou > best[0]:
                        best = (iou, r_o, sx, D, r_e)
    iou, r_o, sx, D, r_e = best
    r_o = max(r_o, r_e)            # the swept shape already contains dilate(F, r_e) at t = 0
    print(name, "body fit IoU %.4f r_o %.2f sx %.2f D %.1f r_e %.2f" % best)
    # outline colour of the piece (darker than the big logo): body pixels far from faces, top half
    far = s["body"] & (l2.centre(dF) > 1.5) & (l2.centre(dF) < r_o - 1.0) & (np.arange(H1)[:, None] < H1 // 2)
    navy = tuple(int(v) for v in np.median(rgb_all[far], 0)) if far.sum() > 10 else (0, 51, 85)
    print("  outline colour", navy)
    P = M.Params(r_o=r_o, sx=sx, D=D, r_e=r_e, navy=navy, glow=False)
    Fg = {gid: F}
    geo = M.geometry(Fg, P)
    rgb = a[..., :3]
    sd = l2.sdf(F)
    sd1 = l2.centre(sd)
    # gloss calibration on face pixels
    full = l2.down(F.astype(float)) >= 0.999
    ev = full & (s["cov"] >= 0.999)
    rows0 = face_rows(rgb, s["cov"] >= 0.999, sd1, H1)
    navy = np.asarray(P.navy, float)
    rowsh = M._rows_hr(rows0, H1 * HR)
    res = []
    for gl_a, gl_d, gl_k in itertools.product([0.75, 1.0, 1.25, 1.5], [1.25, 1.5, 2.0, 2.5], [0.8, 0.9, 1.0]):
        below = l2.shift_hr(sd, 0, -int(round(gl_d * HR)), fill=-10.0)
        gl = np.clip((sd - gl_a) / 0.25 + 0.5, 0, 1) * np.clip((gl_a - below) / 0.25 + 0.5, 0, 1)
        rim = P.rim_k * np.clip(1 - sd / P.rim_w, 0, 1)
        c = rowsh[np.nonzero(F)[0]]
        c = c + (255 - c) * (gl_k * gl[F])[:, None]
        c = c + (navy - c) * rim[F][:, None]
        img = np.zeros(F.shape + (3,))
        img[F] = c
        e = np.abs(l2.q4(l2.down(img))[ev] - rgb[ev]).mean()
        res.append((e, gl_a, gl_d, gl_k))
    res.sort()
    e, P.gl_a, P.gl_d, P.gl_k = res[0]
    print("  gloss a %.2f d %.2f k %.2f (face err %.2f)" % (P.gl_a, P.gl_d, P.gl_k, e))
    # row tables (gloss excluded)
    below = l2.shift_hr(sd, 0, -int(round(P.gl_d * HR)), fill=-10.0)
    glm = (sd > P.gl_a - 0.5) & (below < P.gl_a)
    gl1 = l2.down(ndi.binary_dilation(glm, iterations=HR // 2).astype(float))
    face = face_rows(rgb, s["cov"] >= 0.999, sd1, H1, gl1, sd_min=1.0)
    T1 = l2.centre(np.where(np.isfinite(geo["T"]), geo["T"], 99))
    T1[T1 >= 99] = np.inf
    own1 = geo["own"][HR // 2::HR, HR // 2::HR]
    sdB1 = l2.centre(l2.sdf(B))
    ext = ext_rows(rgb, s["body"], s["cov"], T1, own1, sdB1, gid, H1, navy)
    st = {"face": {gid: face}, "ext": {gid: ext}}
    best_b = None
    for blur in (0.0, 0.3, 0.5, 0.7, 0.9):
        P.blur = blur
        o, _ = M.render(Fg, P, st)
        mm = (a[..., 3] > 0) | (o[..., 3] > 0)
        e = np.abs(l2.comp_on(a) - l2.comp_on(l2.q4(o)))[mm].mean()
        if best_b is None or e < best_b[0]:
            best_b = (e, blur)
    P.blur = best_b[1]
    print("  blur %.1f" % P.blur)
    out, _ = M.render(Fg, P, st)
    np.savez_compressed(l2.HERE / f"fit/piece_{name}.npz", F=F, face=face, ext=ext)
    json.dump(dict(r_o=P.r_o, sx=P.sx, D=P.D, r_e=P.r_e, gl_a=P.gl_a, gl_d=P.gl_d, gl_k=P.gl_k,
                   navy=list(P.navy), blur=P.blur, glow=False, iou=iou), open(l2.HERE / f"fit/piece_{name}.json", "w"), indent=1)
    za = l2.zoom_img(l2.comp_on(a), 5)
    zb = l2.zoom_img(l2.comp_on(l2.q4(out)), 5)
    l2.sheet([[("original", za), ("model", zb)]], l2.HERE / f"review/fit_piece_{name}.png")
    m = (a[..., 3] > 0) | (out[..., 3] > 0)
    print("  mean abs err on blue %.2f" % np.abs(l2.comp_on(a) - l2.comp_on(l2.q4(out)))[m].mean())


if __name__ == "__main__":
    fit("title_logo_M_JP", 1)
    fit("title_logo_L_JP", 3)
