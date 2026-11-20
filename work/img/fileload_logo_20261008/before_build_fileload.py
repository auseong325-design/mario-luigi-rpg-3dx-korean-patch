"""File-select logo 「마리오&루이지 RPG3」 (MLyt MENU_FILE_LOAD_JP_ja LOAD_GAME_IMG_ML_L/R, 144+256 x 208,
RGB565, opaque on white, no DX, no silhouettes) with the same letters and material as the title logo v2.

letters   the Korean words of the title bottom layer (fit/kr_bottom_layout.npz) mapped by the same affine
          that maps the Japanese title letters onto these Japanese letters
material  model.py fitted on this image itself (outline, 3D side rows, face rows, gloss), composited on white
kept      & (moved like on the title), RPG3, Bowser, Mario / Luigi / the star creature: original pixels
The halves are processed as one 400 px image and split again.
"""
from __future__ import annotations

import itertools
import json
import sys

import numpy as np
from scipy import ndimage as ndi

import l2
import model as M
from fit_jp import face_rows, ext_rows

HR = l2.HR
SRC = l2.ROOT / "work/img/lyt/3DX/MLyt/MENU_FILE_LOAD_JP_ja"
DST = l2.ROOT / "work/img/ko/lyt/MLyt/MENU_FILE_LOAD_JP_ja"
NAMES = ("LOAD_GAME_IMG_ML_L_00_JP_ja", "LOAD_GAME_IMG_ML_R_00_JP_ja")
REGION = (0, 0, 300, 100)            # x0, y0, x1, y1: the lettering ("3" and Bowser start at x 300)
P_FL = dict(seam=(222.0, 230.0))
if len(sys.argv) > 1:
    P_FL.update(json.loads(sys.argv[1]))


def segment(a):
    rgb = a[..., :3]
    H, W = rgb.shape[:2]
    reg = np.zeros((H, W), bool)
    x0, y0, x1, y1 = REGION
    reg[y0:y1, x0:x1] = True
    light = rgb.min(2) >= 200
    lab, _ = ndi.label(light)
    border = np.unique(np.r_[lab[0], lab[-1], lab[:, 0], lab[:, -1]])
    bg = np.isin(lab, border[border > 0])
    body = ~bg & reg
    # keep the logo's dark body only (drop the character art below)
    lab, n = ndi.label(body)
    sizes = ndi.sum(body, lab, range(1, n + 1))
    body = lab == 1 + int(np.argmax(sizes))
    navy = np.median(rgb[body & (rgb.max(2) < 100)], 0)
    d = np.sqrt(((rgb - navy) ** 2).sum(2))
    away = ~ndi.binary_dilation(bg, iterations=2)
    cov = np.clip((d - 60) / 60, 0, 1) * body * away
    labf, _ = ndi.label(cov > 0.35)
    keep = np.unique(labf[(d >= 150) & body & away])
    cov = cov * np.isin(labf, keep[keep > 0])
    return dict(bg=bg, body=body, cov=cov, navy=navy)


def groups(cov):
    """1 マリオ, 2 &, 3 ルイージ, 4 R, 5 P/G (by components and x)."""
    lab, n = ndi.label(cov > 0.35)
    comps = []
    for i, sl in enumerate(ndi.find_objects(lab)):
        comps.append((i + 1, sl[1].start, sl[1].stop, sl[0].start, sl[0].stop))
    return lab, comps


def main():
    a = np.concatenate([l2.load(SRC / f"{n}.png") for n in NAMES], 1)
    H1, W1 = a.shape[:2]
    rgb = a[..., :3]
    s = segment(a)
    lab, comps = groups(s["cov"])
    for c in comps:
        print("comp", c)
    F = l2.up(s["cov"]) > 0.5
    labhr = l2.kron(lab.astype(np.int32))
    _, (iy, ix) = ndi.distance_transform_edt(labhr == 0, return_indices=True)
    nl = labhr[iy, ix]
    # & = the low component between the words
    amp_id = [c[0] for c in comps if 100 <= c[1] <= 125 and c[3] >= 45][0]
    x_r = max((c for c in comps if 200 < c[1] < 240), key=lambda c: (c[2] - c[1]) * (c[4] - c[3]))[1]  # R
    xh = (np.arange(F.shape[1])[None, :] + 0.5) / HR
    amp = F & (nl == amp_id)
    xs_amp = np.nonzero(amp.any(0))[0]
    amp_cx = (xs_amp.min() + xs_amp.max() + 1) / 2 / HR
    G = {1: F & ~amp & (xh < amp_cx), 2: amp, 3: F & ~amp & (xh >= amp_cx) & (xh < x_r - 0.5),
         4: F & (xh >= x_r - 0.5)}
    # --- fit the body geometry on this image
    B = l2.up(s["body"].astype(float), order=1) > 0.5
    dF = l2.dist_out(F)
    reg = np.zeros(F.shape, bool)
    reg[:, :int((x_r + 40) * HR)] = True
    best = None
    for r_o, sx, D, r_e in itertools.product((3.0, 3.5, 4.0, 4.5), (0.5, 0.75, 1.0), (4, 5, 6, 7),
                                            (2.5, 3.0, 3.5, 4.0, 4.5)):
        E = np.isfinite(M.sweep_dist(dF <= r_e, sx, D, step=0.5))
        Bm = (dF <= r_o) | E
        iou = (Bm & B & reg).sum() / ((Bm | B) & reg).sum()
        if best is None or iou > best[0]:
            best = (iou, r_o, sx, D, r_e)
    iou, r_o, sx, D, r_e = best
    print("body fit IoU %.4f r_o %.2f sx %.2f D %.1f r_e %.2f" % best)
    navy = tuple(int(v) for v in s["navy"])
    k_title = 0.8
    P = M.Params(r_o=max(r_o, r_e), sx=sx, D=D, r_e=r_e, navy=navy, glow=False,
                 gl_a=1.1 * k_title, gl_d=2.0 * k_title, gl_k=1.0)
    geo = M.geometry(G, P)
    sd1 = l2.centre(l2.sdf(F))
    lab1 = np.rint(l2.centre(geo["lab"].astype(float))).astype(int)
    sd = l2.sdf(F)
    below = l2.shift_hr(sd, 0, -int(round(P.gl_d * HR)), fill=-10.0)
    glm = (sd > P.gl_a - 0.5) & (below < P.gl_a)
    gl1 = l2.down(ndi.binary_dilation(glm, iterations=HR // 2).astype(float))
    T1 = l2.centre(np.where(np.isfinite(geo["T"]), geo["T"], 99))
    T1[T1 >= 99] = np.inf
    own1 = geo["own"][HR // 2::HR, HR // 2::HR]
    sdB1 = l2.centre(l2.sdf(B))
    jb = np.load(l2.HERE / "fit/jp_bottom.npz")
    st = {"face": {}, "ext": {}, "rim": {1: jb["rim1"], 3: jb["rim3"], 4: jb["rim4"]}}
    for g in G:
        st["face"][g] = face_rows(rgb, (lab1 == g) & (s["cov"] >= 0.999), sd1, H1, gl1, sd_min=1.0)
        st["ext"][g] = ext_rows(rgb, s["body"], s["cov"], T1, own1, sdB1, g, H1, np.asarray(navy, float))
    # check: re-render the Japanese letters
    chk, _ = M.render(G, P, st, face_override={2: (np.kron(rgb, np.ones((HR, HR, 1))), G[2])})
    al = chk[..., 3:] / 255
    chk_rgb = chk[..., :3] * al + 255 * (1 - al)
    # --- Korean letters: title layout -> this logo (affine from the Japanese letters of both)
    lay = np.load(l2.HERE / "fit/kr_bottom_layout.npz")
    ys, xs = np.nonzero(F & ~amp & (xh < x_r - 0.5))
    fl = dict(x0=xs.min() / HR, x1=(xs.max() + 1) / HR, y0=ys.min() / HR, y1=(ys.max() + 1) / HR)
    t = dict(x0=56.0, x1=274.0, y0=78.0, y1=128.0)      # Japanese title letters (bottom layer)
    KX = (fl["x1"] - fl["x0"]) / (t["x1"] - t["x0"])
    KY = (fl["y1"] - fl["y0"]) / (t["y1"] - t["y0"])
    print("title -> file-select: KX %.3f KY %.3f" % (KX, KY))

    def mapmask(Mt):
        sdt = l2.sdf(Mt)
        Hh, Wh = F.shape
        Y, X = np.mgrid[0:Hh, 0:Wh].astype(float)
        xt = t["x0"] + ((X + 0.5) / HR - fl["x0"]) / KX
        yt = t["y0"] + ((Y + 0.5) / HR - fl["y0"]) / KY
        v = ndi.map_coordinates(sdt, [yt * HR - 0.5, xt * HR - 0.5], order=1, mode="constant", cval=-50)
        return v > 0

    Fm, Fl = mapmask(lay["Fma"]), mapmask(lay["Flu"])
    amp_dx_title = float(lay["amp_dx"]) / HR
    dx_amp = int(round(amp_dx_title * KX))
    amp_new = l2.shift_hr(amp, dx_amp * HR, 0)
    K = {1: Fm, 2: amp_new, 3: Fl, 4: G[4]}
    # face gradient band: Japanese letters' rows -> Korean small letters
    top_small = fl["y0"] + (float(lay["top_small"]) - t["y0"]) * KY
    head_top = min(np.nonzero(Fm.any(1))[0].min(), np.nonzero(Fl.any(1))[0].min()) / HR
    y = np.arange(H1, dtype=float)
    src = fl["y0"] + (y - top_small) * (fl["y1"] - fl["y0"]) / (fl["y1"] - top_small)
    style = {"face": dict(st["face"]), "ext": dict(st["ext"]), "rim": dict(st["rim"])}
    tt = np.clip((top_small - y) / max(top_small - head_top, 1), 0, 1)
    for g, hl in ((1, 0.25), (3, 0.0)):
        f = np.stack([np.interp(np.clip(src, 0, H1 - 1), np.arange(H1), st["face"][g][:, c]) for c in range(3)], 1)
        style["face"][g] = f + (255 - f) * (hl * tt)[:, None]
    amp_rgb = np.kron(np.roll(rgb, dx_amp, axis=1), np.ones((HR, HR, 1)))
    out, geo2 = M.render(K, P, style, face_override={2: (amp_rgb, K[2])})
    # & and R/P/G faces: original pixels
    amp1 = l2.down(amp_new.astype(float)) > 0
    sh = np.roll(rgb, dx_amp, axis=1)
    al = out[..., 3:] / 255
    comp = out[..., :3] * al + 255 * (1 - al)
    comp[amp1] = sh[amp1]
    # blend: model on the left, original from inside R on; only near the lettering
    x = np.arange(W1)
    s0, s1 = P_FL["seam"]
    w = 1 - np.clip((x - s0) / (s1 - s0), 0, 1)[None, :]
    near = ndi.distance_transform_edt(~(l2.down((geo2["B"] | B).astype(float)) > 0)) <= 3
    w = w * near
    w = ndi.gaussian_filter(w, 0.7)
    # never paint over the character art (dark parts not connected to the logo body)
    art = ~s["bg"] & ~ndi.binary_dilation(s["body"], iterations=1)
    art[:REGION[3] - 30] = False
    w[art] = 0
    res = rgb * (1 - w[..., None]) + comp * w[..., None]
    res = np.concatenate([res, np.full((H1, W1, 1), 255.0)], 2)
    q = res.copy()
    q[..., 0] = np.rint(res[..., 0] / 255 * 31) * 255 / 31
    q[..., 1] = np.rint(res[..., 1] / 255 * 63) * 255 / 63
    q[..., 2] = np.rint(res[..., 2] / 255 * 31) * 255 / 31
    l2.save(q, l2.HERE / "out/fileload_ML_rgb565.png")
    l2.save(res[:, :144], l2.HERE / f"out/{NAMES[0]}.png")
    l2.save(res[:, 144:], l2.HERE / f"out/{NAMES[1]}.png")
    l2.sheet([[("original", l2.zoom_img(rgb[:110, :310], 2))],
              [("model re-render (Japanese letters)", l2.zoom_img(chk_rgb[:110, :310], 2))],
              [("Korean v2 (RGB565)", l2.zoom_img(q[:110, :310, :3], 2))]], l2.HERE / "review/v2_fileload_ml.png")
    print("& dx", dx_amp)


if __name__ == "__main__":
    main()
