"""Place the 1DX Korean syllables (glyph skeleton) on a 3DX logo line.

Each syllable is resampled from the 1DX soft face coverage with its own affine map
(x' = ox + (x - x0) * sx, y' = base3 + (y - base1) * sy), thresholded at hi-res and smoothed.
Syllables are packed left to right so that the closest face-to-face distance to everything already
placed is exactly `gap` (1x px), like the tight spacing of the Japanese logo.
"""
from __future__ import annotations

import numpy as np
from scipy import ndimage as ndi

import l2

HR = l2.HR
BASE_1DX = 81.0          # baseline of the 1DX small letters (리, 이, ㅣ bottoms)


def resample(cov1, x0, y0, sx, sy, ox, oy, shape_hr, order=3):
    """1DX coverage -> hi-res mask: hi-res pixel centre (X, Y) (1x units) maps to
    1DX x = x0 + (X - ox) / sx, y = y0 + (Y - oy) / sy."""
    H, W = shape_hr
    Y, X = np.mgrid[0:H, 0:W].astype(float)
    X1 = (X + 0.5) / HR
    Y1 = (Y + 0.5) / HR
    xs = x0 + (X1 - ox) / sx
    ys = y0 + (Y1 - oy) / sy
    v = ndi.map_coordinates(cov1, [ys - 0.5, xs - 0.5], order=order, mode="constant", prefilter=True)
    return v


def thicken(m, grow, gap_min=1.5):
    """Grow a hi-res mask by `grow` 1x px, keeping counters / gaps >= gap_min (imgtext.thicken)."""
    if grow <= 0:
        return m
    import sys as _s
    _s.path.insert(0, str(l2.ROOT / "scripts"))
    import imgtext
    return imgtext.thicken(m.astype(np.float32), grow * HR, gap_min * HR) >= 0.5


def syllable_mask(cov1, sx, sy, base3, pad=4, grow=0.0):
    """Hi-res mask of one syllable in a local frame. Returns (mask, x_left_1x) where the local
    frame's x = 0 is the syllable's left face edge (1x units: mask column / HR)."""
    ys, xs = np.nonzero(cov1 > 0.02)
    x0, x1 = xs.min(), xs.max() + 1
    y0, y1 = ys.min(), ys.max() + 1
    w = (x1 - x0) * sx + 2 * pad
    Wh = int(np.ceil(w * HR))
    # local frame: x_local = pad + (x - x0) * sx ; y = base3 + (y - BASE_1DX) * sy (global rows)
    Hh = int(np.ceil((base3 + (y1 - BASE_1DX) * sy + pad) * HR))
    v = resample(cov1, x0, BASE_1DX, sx, sy, pad, base3, (Hh, Wh))
    m = v > 0.5
    m = thicken(m, grow)
    m = l2.smooth_mask(m, 0.3)
    return m


def pack(masks, H_hr, W_hr, x_start, gap, kerns=None):
    """masks: list of local hi-res masks (rows already global). Returns list of x offsets (hi-res px)
    and the union mask. Each next mask is shifted left from far right until its min distance to
    the union reaches `gap` (1x px), plus an optional per-pair kern (1x px, + = wider)."""
    union = np.zeros((H_hr, W_hr), bool)
    offs = []
    for i, m in enumerate(masks):
        h = min(m.shape[0], H_hr)
        mm = np.zeros((H_hr, m.shape[1]), bool)
        mm[:h] = m[:h]
        if i == 0:
            cols = np.nonzero(mm.any(0))[0]
            off = int(round(x_start * HR)) - cols.min()
        else:
            d = l2.dist_out(union)
            ys, xs = np.nonzero(mm)
            g = gap + (kerns[i] if kerns else 0.0)
            # largest-left offset where min distance >= g: scan from the right edge of union
            right = np.nonzero(union.any(0))[0].max()
            off = right + int(g * HR) + 2 - xs.min()
            while True:
                xx = xs + off - 1
                if xx.min() < 0:
                    break
                ok = (xx < W_hr)
                if not ok.all():
                    off -= 1
                    continue
                if d[ys, xx].min() < g:
                    break
                off -= 1
        xx = np.nonzero(mm)[1] + off
        sel = (xx >= 0) & (xx < W_hr)
        yy = np.nonzero(mm)[0][sel]
        union[yy, xx[sel]] = True
        offs.append(off)
    return offs, union


def place(mask, off, H_hr, W_hr):
    out = np.zeros((H_hr, W_hr), bool)
    ys, xs = np.nonzero(mask[:H_hr])
    xs = xs + off
    sel = (xs >= 0) & (xs < W_hr)
    out[ys[sel], xs[sel]] = True
    return out
