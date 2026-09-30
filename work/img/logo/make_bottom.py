"""Korean title logo, bottom layer: 「마리오&루이지」 + original & / RPG / silhouettes.

    glyph skeleton : 1DX Korean logo faces (kr_skeleton.py), scaled sx x sy into the 3DX line
    decoration     : 3DX Japanese measurements (logo_lib.fit_style on title_logo_JP_bottom)
    kept           : & (moved), RPG, Mario/Luigi silhouettes (moved onto the new letters)
Outputs work/img/logo/out/title_logo_JP_bottom.png and step images in work/img/logo/steps/.
"""
import sys, pickle, json
from pathlib import Path
import numpy as np
from PIL import Image
from scipy import ndimage as ndi
sys.path.insert(0, str(Path(__file__).parent))
import logo_lib as L
from kr_skeleton import kr_masks

ROOT = Path(r"C:\mario-luigi-rpg-3dx-korean-patch")
LOGO = ROOT / "work/img/logo"
(LOGO / "out").mkdir(exist_ok=True)
(LOGO / "steps").mkdir(exist_ok=True)

# layout (1x texture px). 1DX composition x=6 -> X0, baseline y=82 -> Y0
P = dict(X0=44.0, Y0=127.0, SX=0.703, SY=0.87, seam=(282, 292), mario_blob_w=42, mario_foot_dx=0,
         luigi_blob_w=38, luigi_foot_dx=0)
if len(sys.argv) > 1:
    P.update(json.loads(sys.argv[1]))


def place(cov1dx, shape_hr):
    """1DX soft mask -> hi-res 3DX mask through the affine layout."""
    H, W = shape_hr
    Y, X = np.mgrid[0:H, 0:W].astype(float)
    x1 = (X + 0.5) / L.HR          # 3DX 1x edge coords
    y1 = (Y + 0.5) / L.HR
    xs = 6 + (x1 - P["X0"]) / P["SX"]  # 1DX edge coords
    ys = 82 + (y1 - P["Y0"]) / P["SY"]
    v = ndi.map_coordinates(cov1dx, [ys - 0.5, xs - 0.5], order=1, mode="constant")
    return v > 0.5


def main():
    a = L.load(ROOT / "work/img/fmdl/3DX/fmd_title_JP_ja/title_logo_JP_bottom.png")
    st = pickle.load(open(LOGO / "fit/style_bottom.pkl", "rb"))
    F_jp = np.load(LOGO / "fit/F_bottom.npy")
    lab_jp = np.load(LOGO / "fit/lab_bottom.npy")
    Bx = np.load(LOGO / "fit/extra_bottom.npy")
    H1, W1 = a.shape[:2]
    shp = F_jp.shape
    _, words = kr_masks()
    Fm = place(words["mario"], shp)
    Fl = place(words["luigi"], shp)
    # & : move the Japanese & to where the 1DX composition has its &
    amp_old = lab_jp == 2
    ys, xs = np.nonzero(words["amp"] > 0.5)
    cx_new = P["X0"] + ((xs.min() + xs.max() + 1) / 2 - 6) * P["SX"]
    ys2, xs2 = np.nonzero(amp_old)
    cx_old = (xs2.min() + xs2.max() + 1) / 2 / L.HR
    dx_amp = int(round(cx_new - cx_old))
    amp_new = np.roll(amp_old, dx_amp * L.HR, axis=1)
    keep = np.isin(lab_jp, [4, 5])
    F = Fm | Fl | amp_new | keep
    lab = np.zeros(shp, int)
    lab[Fm] = 1; lab[Fl] = 3; lab[amp_new] = 2; lab[keep] = lab_jp[keep]
    # silhouettes: move so the feet stand on the new outline as deep as before
    K, _ = L.sweep(F, lab, st.sx)
    Bn = L.body(F, K, st.r_o, st.D, st.r_e)
    Ko, _ = L.sweep(F_jp, lab_jp, st.sx)
    Bo = L.body(F_jp, Ko, st.r_o, st.D, st.r_e)
    sl, ns = ndi.label(Bx)
    comps = sorted(range(1, ns + 1), key=lambda i: np.nonzero(sl == i)[1].mean())
    moves = {}
    patches = []
    Bx_new = np.zeros_like(Bx)
    for name, i in zip(("mario", "luigi"), comps):
        m = sl == i
        yy, xx = np.nonzero(m & ~Bo)          # the part standing above the old outline
        foot_y = yy.max()
        fx = xx[yy >= foot_y - 3 * L.HR].mean()
        # stand on the big first-letter blob of the word (마 / 루)
        word = Fm if name == "mario" else Fl
        cols = np.nonzero(word.any(0))[0]
        c0 = cols.min()
        span = word[:, c0:c0 + int(P[name + "_blob_w"] * L.HR)]
        tops = np.where(span.any(0), span.argmax(0), 10 ** 6)
        tx = c0 + int(np.argmin(tops)) + P[name + "_foot_dx"] * L.HR
        dx = int(round(tx - fx))
        col_old = int(round(fx)); col_new = int(round(tx))
        top_old = np.nonzero(Bo[:, col_old])[0].min()
        top_new = np.nonzero(Bn[:, col_new])[0].min()
        dy = top_new - top_old
        moves[name] = (dx / L.HR, dy / L.HR)
        patches.append((m, dx // L.HR, dy // L.HR))
        Bx_new |= np.roll(np.roll(Bx & ~Bo & ndi.binary_dilation(m, iterations=3 * L.HR), dy, 0), dx, 1)
    print("silhouette moves (1x px):", moves, "& dx", dx_amp)
    # face gradient: map the Korean main band onto the Japanese band 78..127
    kr_top = np.nonzero((Fm | Fl).any(1))[0].min() / L.HR
    ymap = np.clip(78 + (np.arange(H1) - kr_top) * (127 - 78) / (P["Y0"] - kr_top), 0, H1 - 1)
    ymaps = {1: ymap, 3: ymap}
    elem = {1: 1, 2: 2, 3: 3, 4: 4, 5: 5}
    # step images
    sk = np.zeros((H1, W1, 4)); sk[..., :3] = 255; sk[..., 3] = L.down(F.astype(float)) * 255
    L.save(sk, LOGO / "steps/bottom_1_skeleton.png")
    plain, _ = L.render((H1, W1), F, lab, st, elem, B_extra_hr=Bx_new, ymap=ymaps, gloss_on=False)
    L.save(plain, LOGO / "steps/bottom_2_body_fill.png")
    out, B_hr = L.render((H1, W1), F, lab, st, elem, B_extra_hr=Bx_new, ymap=ymaps)
    L.save(out, LOGO / "steps/bottom_3_model.png")
    # paste the original pixels of the kept faces (& moved, RPG)
    covo = L.down(F_jp.astype(float))
    lab1 = np.rint(L.centre(lab_jp.astype(float))).astype(int)
    for e, dx in ((2, dx_amp), (4, 0), (5, 0)):
        m = (covo >= 1) & (lab1 == e)
        m2 = np.roll(m, dx, 1)
        out[m2] = np.roll(a, dx, 1)[m2]
    # silhouettes: copy the original pixels (body + own glow), moved
    covF = L.down(F.astype(float))
    for m, dx, dy in patches:
        s1 = L.down(m.astype(float)) > 0
        reg = ndi.binary_dilation(s1, iterations=12) & ~ndi.binary_dilation(L.down(Bo.astype(float)) > 0, iterations=1) | s1
        bodyp = ndi.binary_dilation(s1, iterations=1) & (a[..., 3] >= 255)
        sh = lambda z: np.roll(np.roll(z, dy, 0), dx, 1)
        reg, bodyp, pa_ = sh(reg), sh(bodyp), sh(a)
        take = sh(s1) & (covF == 0)            # only the silhouette's own navy pixels
        out[take] = pa_[take]
    # right part (RPG and beyond) = original, soft seam inside R
    x = np.arange(W1)
    w = np.clip((x - P["seam"][0]) / (P["seam"][1] - P["seam"][0]), 0, 1)[None, :, None]
    pa = np.concatenate([a[..., :3] * a[..., 3:] / 255, a[..., 3:]], 2)
    po = np.concatenate([out[..., :3] * out[..., 3:] / 255, out[..., 3:]], 2)
    pm = po * (1 - w) + pa * w
    A = pm[..., 3:]
    res = np.concatenate([np.where(A > 0, pm[..., :3] * 255 / np.maximum(A, 1e-6), 255), A], 2)
    # quantise like the texture (RGBA4) to see the real look
    q = np.rint(np.clip(res, 0, 255) / 17) * 17
    L.save(q, LOGO / "out/title_logo_JP_bottom.png")
    L.save(res, LOGO / "steps/bottom_4_final_unquantised.png")
    ys, xs = np.nonzero(q[..., 3] > 0)
    print("final bbox x", xs.min(), xs.max(), "y", ys.min(), ys.max())


if __name__ == "__main__":
    main()

