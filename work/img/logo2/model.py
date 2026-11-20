"""Explicit layer model of the 3DX title-logo lettering (measured on the Japanese original).

Layers, bottom to top (all evaluated at HR x and box-filtered to 1x):
  glow       white, alpha = profile(distance outside the body)
  extrusion  E = sweep(dilate(F, r_e), v * t, t in [0, D]); colour = per-word row table
  outline    O = dilate(F, r_o); navy
  face       F; colour = per-word row table, rim (per word: rim colour = A * face + b, fitted on the
             Japanese edge pixels; navy blend if no fit), white gloss crescent:
             gloss = {sd >= a} and {sd(p + (0, delta)) < a}   (sd = inside distance of the face)
Words ("groups") carry their own face / extrusion row tables.
"""
from __future__ import annotations

import json
from dataclasses import dataclass, field, asdict

import numpy as np
from scipy import ndimage as ndi

import l2

HR = l2.HR


@dataclass
class Params:
    r_o: float = 5.0          # outline radius
    r_e: float = 5.0          # radius of the swept extrusion shape
    sx: float = 0.75          # extrusion direction (sx, 1)
    D: float = 6.5            # extrusion length (rows)
    gl_a: float = 1.1         # gloss: inset of the crescent  (face px error 19.4 -> 12.6, and the total
    gl_d: float = 2.0         # gloss: vertical shift          whiteness 99 % / white px 101 % of the original)
    gl_k: float = 1.0         # gloss strength (0..1 towards white)
    gl_soft: float = 0.25     # gloss edge softness (1x px)
    rim_k: float = 0.25       # face rim darkening towards navy at the very edge
    rim_w: float = 1.5        # rim width (1x px)
    navy: tuple = (0, 51, 85)
    glow: bool = True         # the intro pieces have no glow
    blur: float = 0.0         # gaussian blur of the body (1x px) before downsampling


# ------------------------------------------------------------------ geometry
def sweep_dist(M, sx, D, step=0.25):
    """T = smallest t in [0, D] with p in shift(M, t*(sx,1)); inf outside the sweep."""
    T = np.full(M.shape, np.inf)
    T[M] = 0
    t = step
    while t <= D + 1e-9:
        S = l2.shift_hr(M, int(round(sx * t * HR)), int(round(t * HR)))
        T[S & (T > t)] = t
        t += step
    return T


def label_map(F_groups):
    """hi-res int map of the face group (0 = none) and its nearest-face extension."""
    lab = np.zeros(next(iter(F_groups.values())).shape, np.int16)
    for g, m in F_groups.items():
        lab[m] = g
    F = lab > 0
    _, (iy, ix) = ndi.distance_transform_edt(~F, return_indices=True)
    return lab, lab[iy, ix]


def geometry(F_groups, P: Params, extra_body=None):
    lab, nlab = label_map(F_groups)
    F = lab > 0
    dF = l2.dist_out(F)
    O = dF <= P.r_o
    T = sweep_dist(dF <= P.r_e, P.sx, P.D)
    E = np.isfinite(T)
    # owner of an extrusion pixel: the face it was swept from
    ty = np.where(E, T, 0)
    oy = np.clip(np.arange(F.shape[0])[:, None] - np.rint(ty * HR).astype(int), 0, F.shape[0] - 1)
    ox = np.clip(np.arange(F.shape[1])[None, :] - np.rint(P.sx * ty * HR).astype(int), 0, F.shape[1] - 1)
    own = nlab[oy, ox]
    B = O | E
    if extra_body is not None:
        B = B | extra_body
    return dict(F=F, lab=lab, nlab=nlab, dF=dF, O=O, E=E, T=T, own=own, B=B)


# ------------------------------------------------------------------ rendering
def _rows_hr(table, H_hr):
    """1x row table (H,3) -> hi-res rows (sub-pixel linear)."""
    y1 = (np.arange(H_hr) + 0.5) / HR - 0.5
    ys = np.arange(table.shape[0])
    return np.stack([np.interp(y1, ys, table[:, c]) for c in range(3)], 1)


def render(F_groups, P: Params, style, extra_body=None, face_override=None, geo=None, ext_override=None):
    """F_groups: {group id: hi-res bool face mask}. style: {'face': {g: (H,3)}, 'ext': {g: (H,3)}}.
    face_override: {g: (rgb_hr, mask_hr)} faces whose colour is given (copied original pixels).
    ext_override: (rgb_hr, mask_hr), an optional 2D underside material under the face/gloss.
    Returns RGBA (1x float), geometry dict."""
    g = geo or geometry(F_groups, P, extra_body)
    F, lab, nlab, B, O, E, own = g["F"], g["lab"], g["nlab"], g["B"], g["O"], g["E"], g["own"]
    Hh, Wh = F.shape
    navy = np.asarray(P.navy, float)
    rgb = np.zeros((Hh, Wh, 3))
    # extrusion colour by owner group rows
    for gid, tab in style["ext"].items():
        m = E & (own == gid)
        if m.any():
            rows = _rows_hr(tab, Hh)
            rgb[m] = rows[np.nonzero(m)[0]]
    rgb[O | ~E] = navy                    # outline (and silhouettes) on top
    if ext_override is not None:
        # A measured 2D underside can replace row-only shading without touching face/gloss layers.
        ext_rgb, ext_mask = ext_override
        rgb[ext_mask & B & ~F] = ext_rgb[ext_mask & B & ~F]
    # faces
    sd = l2.sdf(F)
    below = l2.shift_hr(sd, 0, -int(round(P.gl_d * HR)), fill=-10.0)   # sd(p + (0, delta))
    s = max(P.gl_soft, 1e-3)
    gl = np.clip((sd - P.gl_a) / s + 0.5, 0, 1) * np.clip((P.gl_a - below) / s + 0.5, 0, 1)
    rim = P.rim_k * np.clip(1 - sd / P.rim_w, 0, 1)
    for gid, tab in style["face"].items():
        m = lab == gid
        if not m.any():
            continue
        rows = _rows_hr(tab, Hh)
        c = rows[np.nonzero(m)[0]]
        c0 = c
        c = c + (255 - c) * (P.gl_k * gl[m])[:, None]
        if gid in style.get("rim", {}):
            AB = np.asarray(style["rim"][gid])            # (3, 2): per channel slope, offset
            X = np.clip(c0 * AB[:, 0] + AB[:, 1], 0, 255)
            r = np.clip(1 - sd[m] / P.rim_w, 0, 1)
            c = c + (X - c) * r[:, None]
        else:
            c = c + (navy - c) * rim[m][:, None]
        rgb[m] = c
    if face_override:
        for gid, (orgb, om) in face_override.items():
            rgb[om] = orgb[om]
    BB = B | F
    pm_hr = np.concatenate([rgb * BB[..., None], BB[..., None].astype(float)], 2)
    pm1 = l2.down(pm_hr)
    cb = pm1[..., 3]
    body_rgb = pm1[..., :3] / np.maximum(cb, 1e-6)[..., None]
    if P.blur > 0:
        # softer silhouette edge (the intro pieces): blur only the coverage, colours stay crisp and
        # are extended outward from the nearest body pixel
        cbb = l2.down(ndi.gaussian_filter(BB.astype(float), HR * P.blur))
        inside = cb > 0.5
        _, (iy, ix) = ndi.distance_transform_edt(~inside, return_indices=True)
        body_rgb = np.where(inside[..., None], body_rgb, body_rgb[iy, ix])
        cb = np.where(inside & (cb >= 0.999), cb, cbb)
    ga = glow_alpha(BB) if P.glow else np.zeros_like(cb)
    A = cb + (1 - cb) * ga
    pmrgb = cb[..., None] * body_rgb + ((1 - cb) * ga)[..., None] * 255.0
    out = np.concatenate([np.where(A[..., None] > 0, pmrgb / np.maximum(A, 1e-6)[..., None], 255),
                          (A * 255)[..., None]], 2)
    return out, g


_GLOW = None


def glow_alpha(BB_hr):
    """Outer glow = curve(gaussian blur of the body spread by `spread` px). sigma, spread and the curve
    are fitted on title_logo_JP_bottom (fit/glow.json; alpha error 2.6/255 vs 14.6 for a distance model)."""
    global _GLOW
    if _GLOW is None:
        _GLOW = json.load(open(l2.HERE / "fit/glow.json"))
    Bs = l2.dist_out(BB_hr) <= _GLOW["spread"]
    g = ndi.gaussian_filter(l2.down(Bs.astype(float)), _GLOW["sigma"])
    curve = np.asarray(_GLOW["curve"])
    return np.interp(g * 200, np.arange(len(curve)), curve)


def params_json(P):
    return json.dumps(asdict(P))
