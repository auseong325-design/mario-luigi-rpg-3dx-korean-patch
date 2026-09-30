"""Korean title logo, top layer: デラックス -> 디럭스 under DX (DX, 3, ™ stay as they are).

Glyph skeleton: the 디럭스 of the 1DX Korean logo (same role: the small word under DX).
Decoration measured on the Japanese デラックス: fill colour by row, navy outline radius, glow profile.
Only the neighbourhood of the small word is redrawn; DX faces and everything else keep their pixels.
"""
import sys, json
from pathlib import Path
import numpy as np
from scipy import ndimage as ndi
sys.path.insert(0, str(Path(__file__).parent))
import logo_lib as L

ROOT = Path(__file__).resolve().parents[3]
LOGO = ROOT / "work/img/logo"
P = dict(sy=0.64, sx=0.68, track=5.0, dy=0.0)
if len(sys.argv) > 1:
    P.update(json.loads(sys.argv[1]))
BOX_JP = (200, 197, 300, 226)       # x0, y0, x1, y1 around デラックス
BOX_KR = (390, 200, 472, 228)       # around 디럭스 in the 1DX logo


def white_cov(a, box, glow):
    x0, y0, x1, y1 = box
    w = np.clip((a[..., :3].min(2) - 70) / (200 - 70), 0, 1)
    m = np.zeros(a.shape[:2], bool)
    m[y0:y1, x0:x1] = True
    w = w * m * ~glow
    lab, n = ndi.label(w > 0.1)
    red = ndi.binary_dilation((a[..., 0] - a[..., 2] > 80) & (a[..., 3] > 0), iterations=1)
    keep = np.zeros(a.shape[:2], bool)
    for i in range(1, n + 1):
        c = lab == i
        if c.sum() >= 2 and not (c & red).any():     # white gloss on the DX letters touches red
            keep |= c
    return w * keep


def main():
    a = L.load(ROOT / "work/img/fmdl/3DX/fmd_title_JP_ja/title_logo_JP_top.png")
    k = L.load(ROOT / "work/img/logo/src/1DX/kr_logo_rgba.png")
    H1, W1 = a.shape[:2]
    B1, glow = L.body_of(a)
    Tj = white_cov(a, BOX_JP, glow)
    _, gk = L.body_of(k)
    Tk = white_cov(k, BOX_KR, gk)
    ys, xs = np.nonzero(Tj > 0.5)
    jx0, jx1, jy0, jy1 = xs.min(), xs.max() + 1, ys.min(), ys.max() + 1
    ky, kx = np.nonzero(Tk > 0.5)
    kx0, kx1, ky0, ky1 = kx.min(), kx.max() + 1, ky.min(), ky.max() + 1
    print(f"JP word box x {jx0}-{jx1} y {jy0}-{jy1}; 1DX 디럭스 box x {kx0}-{kx1} y {ky0}-{ky1}")
    # --- measurements on the Japanese word
    Tj_hr = L.up_hr(Tj)
    B_hr = L.up_hr(B1)
    dT = L.dist_out(Tj_hr)
    edge = B_hr & ~ndi.binary_erosion(B_hr)
    near = edge & (dT < 6)
    below = near & (np.mgrid[0:H1 * L.HR, 0:W1 * L.HR][0] > (jy0 + jy1) / 2 * L.HR)
    r_t = float(np.median(dT[below]))
    core = Tj >= 1
    rows = L._row_table(a[..., :3], core, H1)
    dB1 = L.centre(L.dist_out(B_hr))
    reg = np.zeros((H1, W1), bool); reg[jy0 - 4:jy1 + 16, jx0 - 10:jx1 + 10] = True
    g = glow & reg
    gt = np.full(80, np.nan)
    db = np.clip((dB1 / 0.25).astype(int), 0, 79)
    for i in range(80):
        s = g & (db == i)
        if s.sum() >= 2:
            gt[i] = a[..., 3][s].mean()
    ok = ~np.isnan(gt)
    gt = np.interp(np.arange(80), np.nonzero(ok)[0], gt[ok]); gt[60:] = 0
    print(f"measured: outline r_t={r_t:.2f}px, fill rows {jy0}..{jy1}:",
          [rows[y].round().astype(int).tolist() for y in range(jy0, jy1, 3)])
    # --- place 디럭스 (tracking added between the three syllables)
    cols = np.nonzero((Tk > 0.5).any(0))[0]
    gaps = np.nonzero(np.diff(cols) > 5)[0]
    syl = np.split(cols, gaps + 1)
    print("1DX syllables x-ranges:", [(int(s[0]), int(s[-1])) for s in syl])
    width = (kx1 - kx0) * P["sx"] + P["track"] * (len(syl) - 1)
    cxj = (jx0 + jx1) / 2
    X0 = cxj - width / 2
    Y1 = jy1 + P["dy"]                   # bottom aligned with the Japanese word
    Hh, Wh = H1 * L.HR, W1 * L.HR
    Tn_hr = np.zeros((Hh, Wh), bool)
    Y, X = np.mgrid[0:Hh, 0:Wh].astype(float)
    for i, s in enumerate(syl):
        m = np.zeros_like(Tk); m[:, s[0] - 1:s[-1] + 2] = Tk[:, s[0] - 1:s[-1] + 2]
        off = X0 + P["track"] * i
        xs1 = kx0 + ((X + 0.5) / L.HR - off) / P["sx"]
        ys1 = ky1 + ((Y + 0.5) / L.HR - Y1) / P["sy"]
        Tn_hr |= ndi.map_coordinates(m, [ys1 - 0.5, xs1 - 0.5], order=1, mode="constant") > 0.5
    # --- new body: remove the old word's outline bumps below the DX body, add the new word's
    yy = np.mgrid[0:Hh, 0:Wh][0] / L.HR
    old_out = (dT <= r_t + 0.75) & (yy > (jy0 + jy1) / 2)
    B_base = B_hr & ~old_out
    # keep the DX body line: close small notches left by removed bumps (only inside the old body)
    B_base = B_base | (ndi.binary_closing(B_base, structure=np.ones((1, 4 * L.HR))) & B_hr)
    B_new = B_base | (L.dist_out(Tn_hr) <= r_t)
    # --- render the neighbourhood
    covT = L.down(Tn_hr.astype(float))
    covB = L.down(B_new.astype(float))
    dBn = L.centre(L.dist_out(B_new))
    ga = gt[np.clip((dBn / 0.25).astype(int), 0, 79)] / 255
    yidx = np.clip(np.arange(H1), jy0, jy1 - 1)
    tcol = rows[yidx][:, None, :] * np.ones((1, W1, 1))
    nav = L.NAV
    pm_rgb = covT[..., None] * tcol + (covB - covT)[..., None] * nav + ((1 - covB) * ga)[..., None] * 255
    A = covB + (1 - covB) * ga
    rgb = np.where(A[..., None] > 0, pm_rgb / np.maximum(A, 1e-6)[..., None], 255)
    syn = np.concatenate([rgb, (A * 255)[..., None]], 2)
    # --- paste into the original: only around the words, never over the DX letter faces
    ch = L.down((L.dist_out(Tj_hr | Tn_hr) <= r_t + 12).astype(float)) > 0
    wgt = ndi.gaussian_filter(ndi.binary_erosion(ch, iterations=3).astype(float), 1.5)
    dx_face = (L.face_cov(a, glow) > 0) & ~ndi.binary_dilation(Tj > 0, iterations=3)
    wgt[ndi.binary_dilation(dx_face, iterations=1)] = 0
    wgt = wgt[..., None]
    pa = np.concatenate([a[..., :3] * a[..., 3:] / 255, a[..., 3:]], 2)
    ps = np.concatenate([syn[..., :3] * syn[..., 3:] / 255, syn[..., 3:]], 2)
    pm = pa * (1 - wgt) + ps * wgt
    Ap = pm[..., 3:]
    res = np.concatenate([np.where(Ap > 0, pm[..., :3] * 255 / np.maximum(Ap, 1e-6), 255), Ap], 2)
    q = np.rint(np.clip(res, 0, 255) / 17) * 17          # RGBA4
    L.save(q, LOGO / "out/title_logo_JP_top.png")
    sk = np.zeros((H1, W1, 4)); sk[..., :3] = 255; sk[..., 3] = covT * 255
    L.save(sk, LOGO / "steps/top_1_skeleton.png")
    L.save(syn, LOGO / "steps/top_2_synth.png")
    nb = np.nonzero(covT > 0)
    print("new word box x", nb[1].min(), nb[1].max(), "y", nb[0].min(), nb[0].max())


if __name__ == "__main__":
    main()
