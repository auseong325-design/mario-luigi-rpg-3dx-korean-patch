"""Segment a Japanese title-logo piece into glow / body / faces (1x masks + soft face coverage).

glow   : white halo outside the dark body (alpha ramp + opaque white rim)
body   : opaque dark part (navy outline, 3D side, silhouettes)
faces  : bright letter faces inside the body (soft coverage, labelled components)
"""
from __future__ import annotations

import numpy as np
from scipy import ndimage as ndi

import l2


def glow_mask(a):
    rgb, al = a[..., :3], a[..., 3]
    whiteish = (rgb.min(2) >= 170) | (al < 255)
    lab, _ = ndi.label(whiteish)
    ids = np.unique(lab[al == 0])
    g = np.isin(lab, ids[ids > 0])
    return g


def segment(a, face_lo=60.0, face_hi=120.0, core_thr=150.0):
    """Face coverage = colour distance from the outline navy (deep green faces are only ~128 away,
    the darkest 3D side ~113 but never connected to a face core)."""
    al = a[..., 3]
    glow = glow_mask(a)
    body = (al >= 255) & ~glow
    rgb = a[..., :3]
    ref = np.median(rgb[body & (np.abs(rgb - l2.NAVY).sum(2) < 60)], 0) if body.any() else l2.NAVY
    d = np.sqrt(((rgb - ref) ** 2).sum(2))
    # faces never touch the glow: there is always >= 2 px of dark outline
    away = ~ndi.binary_dilation(glow, iterations=2)
    core = (d >= core_thr) & body & away
    cov = np.clip((d - face_lo) / (face_hi - face_lo), 0, 1) * body * away
    lab, n = ndi.label(cov > 0.35)
    keep = np.unique(lab[core])
    keep = keep[keep > 0]
    cov = cov * np.isin(lab, keep)
    lab, n = ndi.label(cov > 0.35)
    return dict(glow=glow, body=body, cov=cov, lab=lab, n=n)


def comps(lab, n):
    out = []
    for i, sl in enumerate(ndi.find_objects(lab)):
        m = lab[sl] == i + 1
        out.append(dict(id=i + 1, x0=sl[1].start, x1=sl[1].stop, y0=sl[0].start, y1=sl[0].stop, px=int(m.sum())))
    return out


if __name__ == "__main__":
    a = l2.load(l2.JP_DIR / "title_logo_JP_bottom.png")
    s = segment(a)
    for c in comps(s["lab"], s["n"]):
        print(c)
