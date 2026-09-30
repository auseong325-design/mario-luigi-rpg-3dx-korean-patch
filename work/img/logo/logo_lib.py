"""Layered logo model for the 3DX title logo (stream I4).

A logo piece is
    F   letter faces (hi-res binary mask, one label per element: word / & / RPG ...)
    B   dark body = {dist(F) <= r_o} U {dist(E) <= r_e},  E = F swept along (sx, 1) for 1..D rows
        (+ extra body parts that are not letters, e.g. the Mario/Luigi silhouettes)
Everything is MEASURED on the Japanese original:
    fit()      -> r_o, sx, D, r_e by IoU against the original body
    face       colour by row per element + white gloss P(signed distance, edge normal)
    non-face   (outline, extrusion shading, glow, drop shadow): k-nearest-neighbour lookup of the
               original's premultiplied RGBA by geometric features (distance to face, signed
               distance to the body edge, body-edge normal, rows below the face).
Features are evaluated at 1x pixel centres; hi-res (HR x) masks give the anti-aliased coverage.
"""
from __future__ import annotations

import numpy as np
from PIL import Image
from scipy import ndimage as ndi
from scipy.spatial import cKDTree

HR = 4
NAV = np.array([0, 51, 85], float)


def load(p) -> np.ndarray:
    return np.asarray(Image.open(p).convert("RGBA")).astype(np.float64)


def save(a, p):
    Image.fromarray(np.clip(np.rint(a), 0, 255).astype(np.uint8)).save(p)


# ------------------------------------------------------------------ masks / fields
OPAQUE = {"on": False}      # opaque images (RGB565 layout art on white): outside = light pixels
                            # connected to the image border


def glow_mask(a):
    rgb, al = a[..., :3], a[..., 3]
    if OPAQUE["on"]:
        light = rgb.min(2) >= 120
        lab, _ = ndi.label(light)
        border = np.unique(np.r_[lab[0], lab[-1], lab[:, 0], lab[:, -1]])
        return np.isin(lab, border[border > 0])
    white = (rgb.min(2) >= 200) | (al < 255)
    lab, _ = ndi.label(white)
    ids = np.unique(lab[al == 0])
    return np.isin(lab, ids[ids > 0])


def face_cov(a, glow=None, lo=70, hi=120, ref=NAV):
    """Soft coverage of the bright letter faces: colour distance from the outline navy, away from
    the glow (faces never touch the glow: there is always >= 3 px of outline)."""
    if glow is None:
        glow = glow_mask(a)
    dist = np.sqrt(((a[..., :3] - np.asarray(ref, float)) ** 2).sum(2))
    cov = np.clip((dist - lo) / (hi - lo), 0, 1)
    cov[ndi.binary_dilation(glow, iterations=2) | (a[..., 3] < 255)] = 0
    core = cov > 0.9
    weak = cov > 0.25
    lab, _ = ndi.label(weak)
    ids = np.unique(lab[core])
    return cov * np.isin(lab, ids[ids > 0])


def body_of(a):
    glow = glow_mask(a)
    return (a[..., 3] >= 255) & ~glow, glow


def up_hr(cov):
    return ndi.zoom(np.asarray(cov, float), HR, order=1, grid_mode=True, mode="nearest") > 0.5


def kron(m):
    return np.kron(m, np.ones((HR, HR), bool))


def down(hr):
    h, w = hr.shape[0] // HR, hr.shape[1] // HR
    return hr.reshape(h, HR, w, HR).mean((1, 3))


def centre(hr):
    c = HR // 2
    return 0.5 * (hr[c - 1::HR, c - 1::HR] + hr[c::HR, c::HR])


def sdf(mask_hr):
    """Signed distance in 1x px, + inside."""
    return (ndi.distance_transform_edt(mask_hr) - ndi.distance_transform_edt(~mask_hr)) / HR


def dist_out(mask_hr):
    return ndi.distance_transform_edt(~mask_hr) / HR


def normals(sd_hr, sigma=0.75):
    s = ndi.gaussian_filter(sd_hr, HR * sigma)
    gy, gx = np.gradient(s)
    n = np.hypot(gx, gy) + 1e-9
    return -gx / n, -gy / n                 # outward normal (x, y), image y down


def sweep(F_hr, lab_hr, sx):
    """Vertical distance k (1x rows) to the face pixel each hi-res pixel was swept from along
    (sx, 1), and that face's label. k = 0 inside F, huge if none."""
    H, W = F_hr.shape
    pad = int(np.ceil(abs(sx) * H)) + 2
    last_y = np.full(W + 2 * pad, -1e9)
    last_l = np.zeros(W + 2 * pad, int)
    K = np.empty((H, W))
    L = np.zeros((H, W), int)
    xs = np.arange(W)
    for y in range(H):
        cols = xs - int(round(sx * y)) + pad
        f = F_hr[y]
        last_y[cols[f]] = y
        last_l[cols[f]] = lab_hr[y, f]
        K[y] = (y - last_y[cols]) / HR
        L[y] = last_l[cols]
    return K, L


def body(F_hr, K, r_o, D, r_e):
    return (dist_out(F_hr) <= r_o) | (dist_out(K <= D) <= r_e)


def nearest_label(F_hr, lab_hr):
    _, (iy, ix) = ndi.distance_transform_edt(~F_hr, return_indices=True)
    return lab_hr[iy, ix]


# ------------------------------------------------------------------ fitting
class Style:
    pass


def fit_body(a, F_hr, lab_hr, region=None, sx_list=(0, 0.25, 0.5, 0.75, 1.0), r_o=None, log=print,
             D_max=16):
    st = Style()
    B1, _ = body_of(a)
    B_hr = up_hr(B1)
    reg = np.ones(B_hr.shape, bool) if region is None else kron(region)
    dF = dist_out(F_hr)
    if r_o is None:
        sdB = sdf(B_hr)
        nx, ny = normals(sdB)
        edge = B_hr & ~ndi.binary_erosion(B_hr) & reg & (ny < -0.8)
        r_o = float(np.median(dF[edge]))
    best = None
    for sx in sx_list:
        K, _ = sweep(F_hr, lab_hr, sx)
        for D in range(0, D_max + 1):
            dE = dist_out(K <= D)
            for r_e in (1, 1.5, 2, 2.5, 3, 3.5, 4, 4.5, 5, 5.5, 6):
                Bm = (dF <= r_o) | (dE <= r_e)
                iou = (Bm & B_hr & reg).sum() / ((Bm | B_hr) & reg).sum()
                if best is None or iou > best[0]:
                    best = (iou, sx, D, r_e)
    st.iou, st.sx, st.D, st.r_e = best
    st.r_o = r_o
    log(f"fit: r_o={r_o:.2f} sx={st.sx} D={st.D} r_e={st.r_e} IoU={st.iou:.4f}")
    return st


def features(F_hr, lab_hr, B_hr, st):
    """Per-1x-pixel geometric features for the non-face k-NN."""
    Kv, _ = sweep(F_hr, lab_hr, 0.0)
    sdB = sdf(B_hr)
    nx, ny = normals(sdB, 1.0)
    # the face copy at the far end of the extrusion (its shape shows as the lit 3D side)
    dx, dy = int(round(st.sx * st.D * HR)), int(round(st.D * HR))
    Fs = np.zeros_like(F_hr)
    Fs[dy:, dx:] = F_hr[:F_hr.shape[0] - dy, :F_hr.shape[1] - dx]
    f = dict(dF=centre(dist_out(F_hr)), sB=centre(sdB), nx=centre(nx), ny=centre(ny),
             k=centre(np.minimum(Kv, 40)), sS=centre(sdf(Fs)))
    return f


FW = dict(dF=1.0, sB=1.6, nx=2.0, ny=4.0, k=0.15, sS=3.0)


def _fvec(f, m):
    return np.stack([np.clip(f["dF"][m], 0, 25) * FW["dF"], np.clip(f["sB"][m], -22, 22) * FW["sB"],
                     f["nx"][m] * FW["nx"], f["ny"][m] * FW["ny"], np.clip(f["k"][m], 0, 40) * FW["k"],
                     np.clip(f["sS"][m], -8, 8) * FW["sS"]], 1)


def fit_style(a, F_hr, lab_hr, elems, region=None, B_extra_hr=None, log=print, **kw):
    st = fit_body(a, F_hr, lab_hr, region, log=log, **kw)
    H1, W1 = a.shape[:2]
    reg1 = np.ones((H1, W1), bool) if region is None else region
    rgb = a[..., :3]
    K, Lb = sweep(F_hr, lab_hr, st.sx)
    Bm = body(F_hr, K, st.r_o, st.D, st.r_e)
    if B_extra_hr is not None:
        Bm = Bm | B_extra_hr
    st.B_model = Bm
    covF = down(F_hr.astype(float))
    lab1 = np.rint(centre(np.where(F_hr, lab_hr, 0).astype(float))).astype(int)
    sdh = sdf(F_hr)
    sd1 = centre(sdh)
    nx, ny = normals(sdh)
    ang1 = centre(np.arctan2(ny, nx))
    nlab1 = np.rint(centre(nearest_label(F_hr, lab_hr).astype(float))).astype(int)
    # train on the ORIGINAL body edge (the glow and rim follow it exactly); render uses the model
    feats = features(F_hr, lab_hr, up_hr(body_of(a)[0]) | Bm & False, st)
    pm = np.concatenate([rgb * a[..., 3:4] / 255, a[..., 3:4]], 2)
    st.face_rows, st.gloss, st.gloss_rgb, st.knn = {}, {}, {}, {}
    for e in elems:
        inside = (covF >= 1) & (lab1 == e) & reg1
        if inside.sum() >= 10:
            rows = _row_table(rgb, inside & (sd1 > 1.0) & (rgb.min(2) < 200), H1)
            w = np.clip(((rgb - rows[:, None, :]) / np.maximum(255 - rows[:, None, :], 1)).min(2), 0, 1)
            gl = inside & (w > 0.45)
            rows = _row_table(rgb, inside & (sd1 > 1.0) & ~ndi.binary_dilation(gl), H1)
            w = np.clip(((rgb - rows[:, None, :]) / np.maximum(255 - rows[:, None, :], 1)).min(2), 0, 1)
            gl = inside & (w > 0.45)
            st.face_rows[e] = rows
            st.gloss_rgb[e] = rgb[gl].mean(0) if gl.sum() else np.array([255.0, 255, 255])
            sdb = np.clip((sd1 / 0.5).astype(int), 0, 20)
            ab = ((ang1 + np.pi) / (2 * np.pi) * 16).astype(int) % 16
            T = np.zeros((21, 16)); C = np.zeros((21, 16))
            np.add.at(T, (sdb[inside], ab[inside]), gl[inside])
            np.add.at(C, (sdb[inside], ab[inside]), 1)
            Pg = np.where(C >= 5, T / np.maximum(C, 1), 0)
            Pg[9:] = 0                     # gloss lines live within 4.5 px of the edge
            st.gloss[e] = (Pg, C)
            # face k-NN (textured faces): depth inside, edge normal, row, stripe phase
            fin = inside | ((covF > 0) & (lab1 == e) & reg1)
            ph = (np.arange(W1)[None, :] + np.arange(H1)[:, None] * STRIPE[0]) % STRIPE[1] / STRIPE[1] * 2 * np.pi
            st.face_knn = getattr(st, "face_knn", {})
            st.face_knn[e] = (cKDTree(_ffvec(sd1, nx1 := centre(nx), ny1 := centre(ny), ph, fin)), rgb[fin],
                              np.nonzero(fin)[0].min(), np.nonzero(fin)[0].max())
        train = (covF == 0) & reg1 & (nlab1 == e) & (feats["dF"] < 24) & (feats["sB"] >= 0)
        if train.sum() >= 20:
            st.knn[e] = (cKDTree(_fvec(feats, train)), pm[train])
    # glow (outside the body): premultiplied RGBA by distance to the body edge and edge normal y
    out = (feats["sB"] < 0) & reg1
    db = np.clip((-feats["sB"] / 0.25).astype(int), 0, 99)
    nb = np.clip(((feats["ny"] + 1) / 2 * 5).astype(int), 0, 4)
    G = np.zeros((100, 5, 4)); GC = np.zeros((100, 5))
    np.add.at(G, (db[out], nb[out]), pm[out])
    np.add.at(GC, (db[out], nb[out]), 1)
    G = G / np.maximum(GC, 1)[..., None]
    for j in range(5):                 # fill empty cells along the distance axis
        ok = GC[:, j] >= 3
        if ok.any():
            for c in range(4):
                G[:, j, c] = np.interp(np.arange(100), np.nonzero(ok)[0], G[ok, j, c])
    G[80:] = 0
    st.glowtab = G
    log("elements measured: " + ", ".join(f"{e}:{'face' if e in st.face_rows else '-'}"
                                          f"/{len(st.knn[e][1]) if e in st.knn else 0}px" for e in elems))
    return st


STRIPE = [1.0, 6.0]       # face stripe phase = (x + y*k) mod period (only used by the face k-NN)


def _ffvec(sd1, nx1, ny1, ph, m, yrel=None):
    return np.stack([np.clip(sd1[m], 0, 5) * 2.0, nx1[m] * 1.5, ny1[m] * 1.5,
                     np.cos(ph[m]) * 1.0, np.sin(ph[m]) * 1.0], 1)


def _row_table(rgb, m, H1):
    rows = np.full((H1, 3), np.nan)
    for y in range(H1):
        if m[y].sum() >= 2:
            rows[y] = rgb[y][m[y]].mean(0)
    ok = ~np.isnan(rows[:, 0])
    ys = np.arange(H1)
    for c in range(3):
        rows[:, c] = np.interp(ys, ys[ok], rows[ok, c]) if ok.any() else 255
    return rows


# ------------------------------------------------------------------ rendering
def render(shape, F_hr, lab_hr, st, elem_style, B_extra_hr=None, ymap=None, gloss_sharp=(0.15, 0.5),
           knn_k=10, gloss_on=True, face_knn=False, face_gain=1.0):
    """elem_style: label -> measured element id. ymap: per-element {label: array(H) of source rows}
    for the face gradient (default identity). face_gain > 1 steepens the face/outline edge of the
    downsampled face coverage (the hand-drawn originals have hard pixel edges; the 4x render
    averaged to 1x looks soft). Returns (RGBA float, body hi-res mask)."""
    H1, W1 = shape
    K, Lb = sweep(F_hr, lab_hr, st.sx)
    B_hr = body(F_hr, K, st.r_o, st.D, st.r_e)
    if B_extra_hr is not None:
        B_hr = B_hr | B_extra_hr
    covF = down(F_hr.astype(float))
    if face_gain != 1.0:
        covF = np.clip((covF - 0.5) * face_gain + 0.5, 0.0, 1.0)
    nlab1 = np.rint(centre(nearest_label(F_hr, lab_hr).astype(float))).astype(int)
    sdh = sdf(F_hr)
    sd1 = centre(sdh)
    nx, ny = normals(sdh)
    ang1 = centre(np.arctan2(ny, nx))
    feats = features(F_hr, lab_hr, B_hr, st)
    cF = np.zeros((H1, W1, 3))
    nonf = np.zeros((H1, W1, 4))
    nonf[feats["sB"] >= 0] = np.r_[getattr(st, "navy", NAV), 255.0]   # body far from letters
    for lab, e in elem_style.items():
        m = nlab1 == lab
        if face_knn and e in getattr(st, "face_knn", {}):
            tree, vals, _y0, _y1 = st.face_knn[e]
            ph = (np.arange(W1)[None, :] + np.arange(H1)[:, None] * STRIPE[0]) % STRIPE[1] / STRIPE[1] * 2 * np.pi
            q = m & (covF > 0)
            dd, ii = tree.query(_ffvec(sd1, centre(nx), centre(ny), ph, q), k=4)
            wt = 1 / (dd + 0.2)
            cF[q] = (vals[ii] * wt[..., None]).sum(1) / wt.sum(1)[:, None]
        elif e in st.face_rows:
            rows = st.face_rows[e]
            ys = np.nonzero(m)[0]
            src = ys if ymap is None or lab not in ymap else np.asarray(ymap[lab])[ys]
            cF[m] = rows[np.clip(np.rint(src), 0, H1 - 1).astype(int)]
            if gloss_on:
                P, _c = st.gloss[e]
                sdf_ = np.clip(np.maximum(sd1, 0) / 0.5 - 0.5, 0, 20)
                af = ((ang1 + np.pi) / (2 * np.pi) * 16 - 0.5) % 16
                s0 = np.floor(sdf_).astype(int); s1 = np.minimum(s0 + 1, 20); ts = sdf_ - s0
                a0 = np.floor(af).astype(int) % 16; a1 = (a0 + 1) % 16; ta = af - np.floor(af)
                w = (P[s0, a0] * (1 - ts) * (1 - ta) + P[s1, a0] * ts * (1 - ta)
                     + P[s0, a1] * (1 - ts) * ta + P[s1, a1] * ts * ta)
                lo, hi = gloss_sharp
                w = np.clip((w - lo) / (hi - lo), 0, 1)
                gc = st.gloss_rgb[e]
                cF[m] = cF[m] + (gc - cF[m]) * w[m][:, None]
        q = m & (covF < 1) & (feats["dF"] < 24) & (feats["sB"] >= 0)
        if q.any() and e in st.knn:
            tree, vals = st.knn[e]
            dd, ii = tree.query(_fvec(feats, q), k=knn_k)
            wt = 1 / (dd + 0.3)
            nonf[q] = (vals[ii] * wt[..., None]).sum(1) / wt.sum(1)[:, None]
    # glow outside the body
    o = feats["sB"] < 0
    dq = np.clip(-feats["sB"][o] / 0.25, 0, 99)
    d0 = np.floor(dq).astype(int); d1 = np.minimum(d0 + 1, 99); t = (dq - d0)[:, None]
    nq = np.clip((feats["ny"][o] + 1) / 2 * 5 - 0.5, 0, 4)
    n0 = np.floor(nq).astype(int); n1 = np.minimum(n0 + 1, 4); u = (nq - n0)[:, None]
    G = st.glowtab
    nonf[o] = ((G[d0, n0] * (1 - t) + G[d1, n0] * t) * (1 - u) + (G[d0, n1] * (1 - t) + G[d1, n1] * t) * u)
    pmF = np.concatenate([cF, np.full((H1, W1, 1), 255.0)], 2)
    pm = covF[..., None] * pmF + (1 - covF[..., None]) * nonf
    A = pm[..., 3]
    rgb = np.where(A[..., None] > 0, pm[..., :3] * 255 / np.maximum(A, 1e-6)[..., None], 255)
    out = np.concatenate([np.clip(rgb, 0, 255), np.clip(A, 0, 255)[..., None]], 2)
    return out, B_hr






def clean_kr(F_hr, min_px=60, grow_px=0.0, gap_px=1.5):
    """Placed Korean face mask: drop stray pieces smaller than min_px (1x px^2; the resampled 1DX
    mask leaves a thin arc under 마 and specks under 오), then grow the strokes by grow_px (1x px)
    without letting a gap or counter shrink below gap_px (imgtext.thicken)."""
    lab, n = ndi.label(F_hr)
    if n:
        sizes = ndi.sum(F_hr, lab, range(1, n + 1)) / (HR * HR)
        F_hr = np.isin(lab, 1 + np.nonzero(sizes >= min_px)[0])
    if grow_px > 0:
        import sys as _s
        _s.path.insert(0, str(__import__("pathlib").Path(__file__).resolve().parents[3] / "scripts"))
        import imgtext as _T
        F_hr = _T.thicken(F_hr.astype(np.float32), grow_px * HR, gap_px * HR) >= 0.5
    return F_hr
