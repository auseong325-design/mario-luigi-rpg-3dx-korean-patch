"""Korean title logo pieces title_logo_M_JP (마리오) and title_logo_L_JP (루이지).

Same method as make_bottom.py: 1DX Korean glyph skeleton, decoration fitted on the Japanese piece.
The word is scaled to the Japanese face box (width squeeze never below 80 % of the height scale),
bottom-aligned and centred like the Japanese word.
"""
import sys, pickle, json
from pathlib import Path
import numpy as np
from scipy import ndimage as ndi
sys.path.insert(0, str(Path(__file__).parent))
import logo_lib as L
from kr_skeleton import kr_masks

ROOT = Path(__file__).resolve().parents[3]
LOGO = ROOT / "work/img/logo"
PIECES = {"title_logo_M_JP": "mario", "title_logo_L_JP": "luigi"}
MIN_RATIO = 0.8
# user review 2026-09-30: same stroke growth / hard face edges as make_bottom.py
OPT = dict(margin=0.0, min_px=60, grow=0.75, face_gain=2.0)
if len(sys.argv) > 1:
    OPT.update(json.loads(sys.argv[1]))


def jp_faces(a):
    B1, glow = L.body_of(a)
    cov = L.face_cov(a, glow)
    F = L.up_hr(cov)
    lab, n = ndi.label(F)
    sizes = ndi.sum(F, lab, range(1, n + 1))
    return np.isin(lab, 1 + np.nonzero(sizes >= 10 * L.HR * L.HR)[0])


def main():
    _, words = kr_masks()
    for tex, word in PIECES.items():
        a = L.load(ROOT / f"work/img/fmdl/3DX/fmd_title_JP_ja/{tex}.png")
        H1, W1 = a.shape[:2]
        F_jp = jp_faces(a)
        lab_jp = F_jp.astype(int)
        st = L.fit_style(a, F_jp, lab_jp, [1], log=lambda s: print(tex, s))
        del st.B_model
        pickle.dump(st, open(LOGO / f"fit/style_{tex}.pkl", "wb"))
        ys, xs = np.nonzero(F_jp)
        jx0, jx1, jy0, jy1 = xs.min() / L.HR, (xs.max() + 1) / L.HR, ys.min() / L.HR, (ys.max() + 1) / L.HR
        m = words[word]
        ky, kx = np.nonzero(m > 0.5)
        kx0, kx1, ky0, ky1 = kx.min(), kx.max() + 1, ky.min(), ky.max() + 1
        # the 1DX blobs (마's ㅁ, 루's ㄹ) are tall: use the whole texture height above the
        # Japanese baseline and the full width that leaves room for outline + extrusion
        top = st.r_o + 2.5
        left = st.r_o + 2.5
        right = W1 - (st.r_o + st.sx * st.D + 2.5)
        sy = (jy1 - top) / (ky1 - ky0)
        sx = min(sy, (right - left) / (kx1 - kx0))
        if sx / sy < MIN_RATIO:
            sy = sx / MIN_RATIO
        # bottom aligned on the Japanese baseline, centred in the usable width
        X0 = (left + right) / 2 - (kx1 - kx0) * sx / 2
        Y0 = jy1
        Hh, Wh = F_jp.shape
        Y, X = np.mgrid[0:Hh, 0:Wh].astype(float)
        xs1 = kx0 + ((X + 0.5) / L.HR - X0) / sx
        ys1 = ky1 + ((Y + 0.5) / L.HR - Y0) / sy
        F = ndi.map_coordinates(m, [ys1 - 0.5, xs1 - 0.5], order=1, mode="constant") > 0.5
        F = L.clean_kr(F, OPT["min_px"], OPT["grow"])
        lab = F.astype(int)
        print(tex, f"JP face box x {jx0:.0f}-{jx1:.0f} y {jy0:.0f}-{jy1:.0f}; scale sx={sx:.3f} sy={sy:.3f} "
                   f"(ratio {sx / sy:.2f})")
        ytop = np.nonzero(F.any(1))[0].min() / L.HR
        ymap = np.clip(jy0 + (np.arange(H1) - ytop) * (jy1 - jy0) / (Y0 - ytop), 0, H1 - 1)
        sk = np.zeros((H1, W1, 4)); sk[..., :3] = 255; sk[..., 3] = L.down(F.astype(float)) * 255
        L.save(sk, LOGO / f"steps/{tex}_1_skeleton.png")
        plain, _ = L.render((H1, W1), F, lab, st, {1: 1}, ymap={1: ymap}, gloss_on=False, face_gain=OPT["face_gain"])
        L.save(plain, LOGO / f"steps/{tex}_2_body_fill.png")
        out, _ = L.render((H1, W1), F, lab, st, {1: 1}, ymap={1: ymap}, face_gain=OPT["face_gain"])
        L.save(out, LOGO / f"steps/{tex}_3_final_unquantised.png")
        q = np.rint(np.clip(out, 0, 255) / 17) * 17          # RGBA4
        L.save(q, LOGO / f"out/{tex}.png")
        # re-render the Japanese piece with the same model (validation)
        chk, _ = L.render((H1, W1), F_jp, lab_jp, st, {1: 1})
        L.save(chk, LOGO / f"fit/rerender_{tex}.png")


if __name__ == "__main__":
    main()
