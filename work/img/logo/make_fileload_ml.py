"""File-select logo 「마리오&루이지 RPG3」 (MLyt MENU_FILE_LOAD_JP_ja LOAD_GAME_IMG_ML_L/R, RGB565, no DX).

Same method and the same letter shapes as the title logo (make_bottom.py): 1DX Korean glyph skeleton in
the title's Korean layout mapped onto this smaller logo, decoration fitted on this image itself
(opaque art on white). RPG3, &, Bowser, Mario and Luigi keep their pixels. The two halves (144 + 256 px)
are processed as one 400 px image and split again, so the letters run across the seam.
"""
import sys, json
from pathlib import Path
import numpy as np
from PIL import Image
from scipy import ndimage as ndi
sys.path.insert(0, str(Path(__file__).parent))
import logo_lib as L
from kr_skeleton import kr_masks

ROOT = Path(__file__).resolve().parents[3]
LOGO = ROOT / "work/img/logo"
SRC = ROOT / "work/img/lyt/3DX/MLyt/MENU_FILE_LOAD_JP_ja"
DST = ROOT / "work/img/ko/lyt/MLyt/MENU_FILE_LOAD_JP_ja"
NAMES = ("LOAD_GAME_IMG_ML_L_00_JP_ja", "LOAD_GAME_IMG_ML_R_00_JP_ja")
# title-logo coordinates -> this logo: x' = 35 + (x - 56) * KX, y' = 33 + (y - 78) * KY
KX, KY = (212 - 35) / (274 - 56), (72 - 33) / (128 - 78)
T = dict(X0=44.0, Y0=127.0, SX=0.703, SY=0.87)       # title layout (make_bottom.P)
P = dict(X0=35 + (T["X0"] - 56) * KX, Y0=33 + (T["Y0"] - 78) * KY, SX=T["SX"] * KX, SY=T["SY"] * KY,
         seam=(218, 226), region_y=100, min_px=60, grow=0.75, face_gain=2.0)
if len(sys.argv) > 1:
    P.update(json.loads(sys.argv[1]))


def place(cov1dx, shape_hr):
    H, W = shape_hr
    Y, X = np.mgrid[0:H, 0:W].astype(float)
    xs = 6 + ((X + 0.5) / L.HR - P["X0"]) / P["SX"]
    ys = 82 + ((Y + 0.5) / L.HR - P["Y0"]) / P["SY"]
    return ndi.map_coordinates(cov1dx, [ys - 0.5, xs - 0.5], order=1, mode="constant") > 0.5


def main():
    L.OPAQUE["on"] = True
    parts = [L.load(SRC / f"{n}.png") for n in NAMES]
    a = np.concatenate(parts, 1)
    H1, W1 = a.shape[:2]
    ry = P["region_y"]
    B1, glow = L.body_of(a)
    cov = L.face_cov(a, glow)
    cov[ry:] = 0
    cov[:, 300:] = 0                      # "3" and Bowser are not letters to redraw
    F = L.up_hr(cov)
    lab_c, n = ndi.label(F)
    sizes = ndi.sum(F, lab_c, range(1, n + 1))
    F = np.isin(lab_c, 1 + np.nonzero(sizes >= 10 * L.HR * L.HR)[0])
    Hh, Wh = F.shape
    yy, xx = np.mgrid[0:Hh, 0:Wh] / L.HR
    el = np.zeros((Hh, Wh), int)
    el[xx < 108] = 1
    el[(xx >= 108) & (xx < 125) & (yy > 52)] = 2
    el[(xx >= 108) & (xx < 125) & (yy <= 52)] = 1
    el[(xx >= 125) & (xx < 214.5)] = 3
    el[xx >= 214.5] = 4
    lab_jp = np.where(F, el, 0)
    region = np.zeros((H1, W1), bool)
    region[:ry + 12, :300] = True
    st = L.fit_style(a, F, lab_jp, [1, 2, 3, 4], region=region, log=print)
    # Korean faces
    _, words = kr_masks()
    Fm = place(words["mario"], F.shape)
    Fl = place(words["luigi"], F.shape)
    Fm = L.clean_kr(Fm, P["min_px"], P["grow"])      # the stray arc under 마 (user review 2026-09-30)
    Fl = L.clean_kr(Fl, P["min_px"], P["grow"])
    amp_old = lab_jp == 2
    ys, xs = np.nonzero(words["amp"] > 0.5)
    cx_new = P["X0"] + ((xs.min() + xs.max() + 1) / 2 - 6) * P["SX"]
    ys2, xs2 = np.nonzero(amp_old)
    dx_amp = int(round(cx_new - (xs2.min() + xs2.max() + 1) / 2 / L.HR))
    amp_new = np.roll(amp_old, dx_amp * L.HR, axis=1)
    keep = lab_jp == 4
    Fn = Fm | Fl | amp_new | keep
    lab = np.zeros(F.shape, int)
    lab[Fm] = 1; lab[Fl] = 3; lab[amp_new] = 2; lab[keep] = 4
    kr_top = np.nonzero((Fm | Fl).any(1))[0].min() / L.HR
    ymap = np.clip(33 + (np.arange(H1) - kr_top) * (72 - 33) / (P["Y0"] - kr_top), 0, H1 - 1)
    elem = {1: 1, 2: 2, 3: 3, 4: 4}
    sk = np.zeros((H1, W1, 4)); sk[..., :3] = 255; sk[..., 3] = L.down(Fn.astype(float)) * 255
    L.save(sk, LOGO / "steps/fileML_1_skeleton.png")
    chk, _ = L.render((H1, W1), F, lab_jp, st, elem)
    L.save(chk, LOGO / "fit/rerender_fileML.png")
    out, B_hr = L.render((H1, W1), Fn, lab, st, elem, ymap={1: ymap, 3: ymap}, face_gain=P["face_gain"])
    L.save(out, LOGO / "steps/fileML_2_model.png")
    covo = L.down(F.astype(float))
    lab1 = np.rint(L.centre(lab_jp.astype(float))).astype(int)
    for e, dx in ((2, dx_amp), (4, 0)):
        m = np.roll((covo >= 1) & (lab1 == e), dx, 1)
        out[m] = np.roll(a, dx, 1)[m]
    # composite over the white background (the texture is opaque), then keep the original outside
    A = out[..., 3:] / 255
    comp = out[..., :3] * A + 255 * (1 - A)
    x = np.arange(W1)
    w = np.clip((x - P["seam"][0]) / (P["seam"][1] - P["seam"][0]), 0, 1)[None, :, None]
    changed = np.zeros((H1, W1), bool)
    changed[:ry + 14, :] = True
    wy = ndi.gaussian_filter(changed.astype(float), 2)[..., None]
    wgt = (1 - w) * wy
    res = a[..., :3] * (1 - wgt) + comp * wgt
    # never paint over the character art: body components that do not touch the old letters
    labB, nB = ndi.label(B1)
    logo_ids = np.unique(labB[L.down(F.astype(float)) > 0])
    art = (labB > 0) & ~np.isin(labB, logo_ids[logo_ids > 0])
    art = ndi.binary_dilation(art, iterations=1)
    near = L.down(((L.dist_out(B_hr) <= 14) | (L.dist_out(L.up_hr(B1 & ~art & region)) <= 14)).astype(float)) > 0
    res[~near | art] = a[..., :3][~near | art]
    res = np.concatenate([res, np.full((H1, W1, 1), 255.0)], 2)
    q = res.copy()                          # RGB565 quantisation preview
    q[..., 0] = np.rint(res[..., 0] / 255 * 31) * 255 / 31
    q[..., 1] = np.rint(res[..., 1] / 255 * 63) * 255 / 63
    q[..., 2] = np.rint(res[..., 2] / 255 * 31) * 255 / 31
    DST.mkdir(parents=True, exist_ok=True)
    L.save(res[:, :144], DST / f"{NAMES[0]}.png")
    L.save(res[:, 144:], DST / f"{NAMES[1]}.png")
    L.save(q, LOGO / "steps/fileML_3_final_rgb565.png")
    print("& dx", dx_amp, "layout", {k: round(v, 3) if isinstance(v, float) else v for k, v in P.items()})


if __name__ == "__main__":
    main()
