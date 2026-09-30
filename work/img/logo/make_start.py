"""Title 'start' button fmd_title_start_JP_ja/st: ゲームスタート -> 게임 시작.

Glyph: the same word on the 1DX Korean button btn_GAMESTART_12_KR_ko (white face, dark outline).
Decoration measured on the Japanese button: outline radius and colour, drop-shadow direction/length
and colour (fit_body on the dark body), face colour by row. The yellow panel under the old word is
restored row by row from the panel pixels beside the text (the panel is a vertical gradient).
"""
import sys, json
from pathlib import Path
import numpy as np
from scipy import ndimage as ndi
sys.path.insert(0, str(Path(__file__).parent))
import logo_lib as L

ROOT = Path(__file__).resolve().parents[3]
LOGO = ROOT / "work/img/logo"
P = dict(scale=1.13, sx=1.0, dy=0.0, dx=0.0, grow_max=0.5)
if len(sys.argv) > 1:
    P.update(json.loads(sys.argv[1]))


def masks(a, box):
    x0, y0, x1, y1 = box
    reg = np.zeros(a.shape[:2], bool); reg[y0:y1, x0:x1] = True
    rgb = a[..., :3]
    face = np.clip((rgb.min(2) - 120) / (200 - 120), 0, 1) * reg * (a[..., 3] / 255)
    dark = (rgb.max(2) < 130) & reg & (a[..., 3] > 128)
    lab, n = ndi.label(face > 0.2)
    keep = np.isin(lab, [i for i in range(1, n + 1) if ((lab == i) & ndi.binary_dilation(dark, iterations=2)).any()])
    return face * keep, dark


def main():
    a = L.load(ROOT / "work/img/fmdl/3DX/fmd_title_start_JP_ja/st.png")
    k = L.load(ROOT / "work/img/lyt/1DX/SLyt/GAMESTART_KR_ko/btn_GAMESTART_12_KR_ko.png")
    H1, W1 = a.shape[:2]
    BOX = (60, 18, 200, 50)
    Fj, Dj = masks(a, BOX)
    Fk, Dk = masks(k, (0, 0, k.shape[1], k.shape[0]))
    ys, xs = np.nonzero(Fj > 0.5); jx0, jx1, jy0, jy1 = xs.min(), xs.max() + 1, ys.min(), ys.max() + 1
    ky, kx = np.nonzero(Fk > 0.5); kx0, kx1, ky0, ky1 = kx.min(), kx.max() + 1, ky.min(), ky.max() + 1
    print(f"JP face box x {jx0}-{jx1} y {jy0}-{jy1}  1DX face box x {kx0}-{kx1} y {ky0}-{ky1}")
    F_hr = L.up_hr(Fj)
    B1 = (Fj > 0.5) | Dj
    # fit outline + shadow on the dark body
    lab_hr = F_hr.astype(int)
    fake = a.copy(); fake[..., 3] = 0; fake[L.down(L.up_hr(B1.astype(float))) > 0.5, 3] = 255
    fake[B1, :3] = a[B1, :3]; fake[~B1, :3] = 255
    reg = np.zeros((H1, W1), bool); reg[BOX[1]:BOX[3], BOX[0]:BOX[2]] = True
    Bh = L.up_hr(B1.astype(float)) & L.kron(reg)
    dF_ = L.dist_out(F_hr)
    best = None
    for r_o in np.arange(1.0, 3.01, 0.25):
        for t in np.arange(0, 4.01, 0.5):
            for sxr in (0.5, 1.0):
                E_ = np.zeros_like(F_hr)
                for s_ in np.linspace(0, 1, 5):
                    yy_, xx_ = int(round(t * s_ * L.HR)), int(round(t * sxr * s_ * L.HR))
                    E_[yy_:, xx_:] |= F_hr[:F_hr.shape[0] - yy_, :F_hr.shape[1] - xx_]
                Bm = L.dist_out(E_) <= r_o
                iou = (Bm & Bh).sum() / (Bm | Bh).sum()
                if best is None or iou > best[0]:
                    best = (iou, r_o, t, sxr)
    iou, r_o, t, sxr = best

    class St: pass
    st = St(); st.r_o = r_o; st.t = t; st.sxr = sxr
    print(f"body fit IoU={iou:.3f}: outline {r_o}px, shadow offset ({t * sxr}, {t}) px")

    def swept(Fh):
        E_ = np.zeros_like(Fh)
        for s_ in np.linspace(0, 1, 9):
            yy_, xx_ = int(round(st.t * s_ * L.HR)), int(round(st.t * st.sxr * s_ * L.HR))
            E_[yy_:, xx_:] |= Fh[:Fh.shape[0] - yy_, :Fh.shape[1] - xx_]
        return E_
    E = swept(F_hr)
    dF = L.dist_out(F_hr)
    dE = L.dist_out(E)
    outl1 = L.centre(dF) <= st.r_o - 0.5
    shad1 = (L.centre(dE) <= st.r_o - 0.5) & ~(L.centre(dF) <= st.r_o + 0.5)
    c_out = a[..., :3][outl1 & Dj & (Fj == 0)].mean(0)
    c_sh = a[..., :3][shad1 & Dj].mean(0) if (shad1 & Dj).any() else c_out
    rows = L._row_table(a[..., :3], Fj >= 1, H1)
    print(f"outline colour {c_out.round()}, shadow colour {c_sh.round()}, face rows {rows[jy0].round()}..{rows[jy1 - 1].round()}")
    # panel restoration: per row, median of panel pixels left/right of the text (inside the button)
    body_zone = ndi.binary_dilation(B1, iterations=3)
    panel = a.copy()
    for y in range(BOX[1] - 4, BOX[3] + 4):
        side = np.r_[np.arange(BOX[0] - 30, BOX[0] - 2), np.arange(BOX[2] + 2, BOX[2] + 30)]
        side = side[~body_zone[y, side]]
        med = np.median(a[y, side], 0)
        z = body_zone[y]
        panel[y, z] = med
    # place the Korean word: scale to the JP face height, centred on the JP word
    s = P["scale"] * (jy1 - jy0) / (ky1 - ky0)
    sxs = s * P["sx"]
    cxj, cyj = (jx0 + jx1) / 2 + P["dx"], (jy0 + jy1) / 2 + P["dy"]
    Hh, Wh = H1 * L.HR, W1 * L.HR
    Y, X = np.mgrid[0:Hh, 0:Wh].astype(float)
    xs1 = (kx0 + kx1) / 2 + ((X + 0.5) / L.HR - cxj) / sxs
    ys1 = (ky0 + ky1) / 2 + ((Y + 0.5) / L.HR - cyj) / s
    Fn = ndi.map_coordinates(Fk, [ys1 - 0.5, xs1 - 0.5], order=1, mode="constant") > 0.5
    # stroke weight: match the Japanese face (median stroke width = 2 x median ridge distance)
    def ridge_w(Fh):
        d = ndi.distance_transform_edt(Fh)
        mx = ndi.maximum_filter(d, size=3)
        r = (d >= mx) & (d > 0.5 * L.HR)
        return 2 * np.median(d[r]) / L.HR
    wj, wn = ridge_w(F_hr), ridge_w(Fn)
    grow = min(P["grow_max"], max(0.0, (wj - wn) / 2))
    if grow > 0:
        Fn = L.sdf(Fn) > -grow
    print(f"stroke width JP {wj:.2f}px, Korean {wn:.2f}px -> grow {grow:.2f}px")
    covF = L.down(Fn.astype(float))
    covO = L.down((L.dist_out(Fn) <= st.r_o).astype(float))
    covS = L.down((L.dist_out(swept(Fn)) <= st.r_o).astype(float))
    yy = np.clip(np.arange(H1), jy0, jy1 - 1)
    # map the face gradient over the new word's own rows
    nys = np.nonzero(covF.any(1))[0]
    src = np.clip(np.rint(jy0 + (np.arange(H1) - nys.min()) * (jy1 - 1 - jy0) / max(1, nys.max() - nys.min())), jy0, jy1 - 1).astype(int)
    fcol = rows[src][:, None, :]
    out = panel[..., :3].copy()
    out = out * (1 - covS[..., None]) + c_sh * covS[..., None]
    out = out * (1 - covO[..., None]) + c_out * covO[..., None]
    out = out * (1 - covF[..., None]) + fcol * covF[..., None]
    res = np.concatenate([out, a[..., 3:]], 2)
    L.save(res, LOGO / "out/st.png")
    sk = np.zeros((H1, W1, 4)); sk[..., :3] = 255; sk[..., 3] = covF * 255
    L.save(sk, LOGO / "steps/st_1_skeleton.png")
    L.save(np.concatenate([panel[..., :3], a[..., 3:]], 2), LOGO / "steps/st_2_panel_erased.png")
    nb = np.nonzero(covF > 0)
    print(f"scale {s:.3f}; new face box x {nb[1].min()}-{nb[1].max()} y {nb[0].min()}-{nb[0].max()}")


if __name__ == "__main__":
    main()
