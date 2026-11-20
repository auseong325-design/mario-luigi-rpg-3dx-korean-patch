"""Title logo v2 (2026-10-02): shared helpers.

Masks are kept at HR x resolution (hi-res); 1x = texture pixels.
Conventions: images are float RGBA 0..255, y down. sdf() is + inside, in 1x px.
"""
from __future__ import annotations

from pathlib import Path

import numpy as np
from PIL import Image
from scipy import ndimage as ndi

ROOT = Path(__file__).resolve().parents[3]
HERE = Path(__file__).resolve().parent
HR = 4
NAVY = np.array([0, 51, 85], float)

JP_DIR = ROOT / "work/img/fmdl/3DX/fmd_title_JP_ja"
KR1DX = ROOT / "work/img/logo/src/1DX/kr_logo_rgba.png"


def load(p) -> np.ndarray:
    return np.asarray(Image.open(p).convert("RGBA")).astype(np.float64)


def save(a, p):
    Image.fromarray(np.clip(np.rint(a), 0, 255).astype(np.uint8)).save(p)


def q4(a):
    """RGBA4 quantisation (the texture format of every title-logo piece)."""
    return np.rint(np.clip(a, 0, 255) / 17.0) * 17.0


# ---------------------------------------------------------------- resampling
def up(cov1, order=3):
    """1x coverage -> hi-res coverage (pixel-centre aligned)."""
    return np.clip(ndi.zoom(np.asarray(cov1, float), HR, order=order, grid_mode=True, mode="nearest"), 0, 1)


def down(hr):
    h, w = hr.shape[0] // HR, hr.shape[1] // HR
    return hr.reshape(h, HR, w, HR, *hr.shape[2:]).mean((1, 3))


def centre(hr):
    c = HR // 2
    return 0.5 * (hr[c - 1::HR, c - 1::HR] + hr[c::HR, c::HR])


def kron(m):
    return np.kron(m, np.ones((HR, HR), m.dtype))


# ---------------------------------------------------------------- distance fields
def sdf(mask_hr):
    """Signed distance in 1x px, + inside (pixel-centre approx)."""
    m = np.asarray(mask_hr, bool)
    return (ndi.distance_transform_edt(m) - ndi.distance_transform_edt(~m)) / HR


def dist_out(mask_hr):
    return ndi.distance_transform_edt(~np.asarray(mask_hr, bool)) / HR


def grad_normal(field, sigma_px=0.75):
    """Unit vector of increasing `field` (hi-res), smoothed by sigma (1x px)."""
    s = ndi.gaussian_filter(field, HR * sigma_px) if sigma_px > 0 else field
    gy, gx = np.gradient(s)
    n = np.hypot(gx, gy) + 1e-9
    return gx / n, gy / n


def shift_hr(m, dx_hr, dy_hr, fill=0):
    """Integer shift of a hi-res array (dx right, dy down)."""
    out = np.full_like(m, fill)
    H, W = m.shape[:2]
    ys = slice(max(dy_hr, 0), H + min(dy_hr, 0))
    yd = slice(max(-dy_hr, 0), H + min(-dy_hr, 0))
    xs = slice(max(dx_hr, 0), W + min(dx_hr, 0))
    xd = slice(max(-dx_hr, 0), W + min(-dx_hr, 0))
    out[ys, xs] = m[yd, xd]
    return out


def smooth_mask(mask_hr, sigma_px=0.35):
    """Round off stair steps of a hi-res mask (keeps the shape: threshold of a blurred sdf)."""
    d = sdf(mask_hr)
    return ndi.gaussian_filter(d, HR * sigma_px) > 0


def comp_on(a, bg=(72, 128, 220)):
    """Composite RGBA over a flat colour (for viewing)."""
    al = a[..., 3:4] / 255.0
    return a[..., :3] * al + np.asarray(bg, float) * (1 - al)


def zoom_img(rgb, z):
    return np.kron(rgb, np.ones((z, z, 1)))


def sheet(blocks, path, gap=6, bg=(30, 30, 30), max_px=1600):
    """blocks: list of rows; each row a list of (label, rgb array). Saves a sheet (<= max_px each side)."""
    from PIL import ImageDraw
    rows = []
    for row in blocks:
        h = max(b.shape[0] for _, b in row) + 14
        w = sum(b.shape[1] for _, b in row) + gap * (len(row) - 1)
        rows.append((row, h, w))
    W = max(w for _, _, w in rows)
    H = sum(h for _, h, _ in rows) + gap * (len(rows) - 1)
    img = Image.new("RGB", (W, H), bg)
    d = ImageDraw.Draw(img)
    y = 0
    for row, h, _ in rows:
        x = 0
        for lab, b in row:
            d.text((x + 2, y), lab, fill=(255, 220, 90))
            img.paste(Image.fromarray(np.clip(np.rint(b), 0, 255).astype(np.uint8)), (x, y + 14))
            x += b.shape[1] + gap
        y += h + gap
    if max(img.size) > max_px:
        s = max_px / max(img.size)
        img = img.resize((int(img.width * s), int(img.height * s)), Image.LANCZOS)
    img.save(path)
    return img.size
