"""File-select logo 「쿠파주니어 RPG」 (MLyt MENU_FILE_LOAD_JP_ja LOAD_GAME_IMG_KJ_L/R, RGB565).

Glyph skeleton: kj_skeleton.py (쿠/파 = 1DX 쿠파군단 RPG lettering, 주/니/어 built from its strokes).
Decoration: measured on the Japanese クッパJr. letters of this image (k-NN on geometric features for the
white / yellow / maroon rings and the 3D side, face k-NN for the orange face with its stripes and rim).
The ruby ジュニア is dropped (주니어 is spelled out). RPG, stars, clouds and Bowser Jr. keep their pixels.
"""
import sys, json
from pathlib import Path
import numpy as np
from scipy import ndimage as ndi
sys.path.insert(0, str(Path(__file__).parent))
import logo_lib as L
import kj_skeleton as K

ROOT = Path(__file__).resolve().parents[3]
LOGO = ROOT / "work/img/logo"
SRC = ROOT / "work/img/lyt/3DX/MLyt/MENU_FILE_LOAD_JP_ja"
DST = ROOT / "work/img/ko/lyt/MLyt/MENU_FILE_LOAD_JP_ja"
NAMES = ("LOAD_GAME_IMG_KJ_L_00_JP_ja", "LOAD_GAME_IMG_KJ_R_00_JP_ja")
P = dict(gap=2.0, sy=0.80, ratio=0.86, x_left=67.0, x_right=196.0, baseline=None, rot=-3.0,
         seam=(206, 212), y_top=128, grow_max=0.8, puffs=[(40, 125, 100, 166), (196, 185, 236, 208)],
         # per syllable: (scale x, scale y, rotation deg, bottom y); 쿠파 big, 주니어 smaller (like クッパ / Jr.)
         syll=[(0.78, 0.92, -5.0, 187.0), (0.78, 0.92, 3.0, 185.0), (0.62, 0.74, -4.0, 182.0),
               (0.62, 0.74, 3.0, 181.0), (0.62, 0.74, -3.0, 179.0)], syll_gap=1.0, puff_reach=4.0, puff_clear=3, r_zone=(4, 14))
if len(sys.argv) > 1:
    P.update(json.loads(sys.argv[1]))


def ring_render(a, F_all, lab_jp, Fn, F2, st, B1, glow, reg):
    """Parametric rings: colour = table(distance to the face) measured on the Japanese letters,
    separately for edges facing up and down (the 3D side is below); face = table(depth inside)."""
    H1, W1 = a.shape[:2]
    rgb = a[..., :3]
    Fj = F_all & (lab_jp == 1)
    dF = L.centre(L.dist_out(Fj)); sdF = L.centre(L.sdf(Fj))
    nx, ny = L.normals(L.sdf(Fj), 1.5); ny1 = L.centre(ny)
    covF = L.down(Fj.astype(float))
    xs = np.arange(W1)[None, :] * np.ones((H1, 1))
    train = B1 & reg & (covF == 0) & (xs < 203) & (L.down((F_all & (lab_jp != 1)).astype(float)) == 0)
    far_other = L.centre(L.dist_out(F_all & (lab_jp != 1))) > 9     # away from ruby / RPG
    train &= far_other
    nb = 60
    def table(m):
        T = np.zeros((nb, 3)); C = np.zeros(nb)
        db = np.clip((dF / 0.25).astype(int), 0, nb - 1)
        np.add.at(T, db[m], rgb[m]); np.add.at(C, db[m], 1)
        ok = C >= 3
        for c in range(3):
            T[:, c] = np.interp(np.arange(nb), np.nonzero(ok)[0], T[ok, c] / C[ok])
        return T
    Tup, Tdn = table(train & (ny1 < -0.3)), table(train & (ny1 > 0.3))
    inside = (covF >= 1) & reg & (xs < 203) & ~ndi.binary_dilation(L.down(F_all.astype(float) * (lab_jp != 1)) > 0, iterations=3)
    Tf = np.zeros((40, 3)); Cf = np.zeros(40)
    sb = np.clip((sdF / 0.25).astype(int), 0, 39)
    np.add.at(Tf, sb[inside], rgb[inside]); np.add.at(Cf, sb[inside], 1)
    ok = Cf >= 3
    for c in range(3):
        Tf[:, c] = np.interp(np.arange(40), np.nonzero(ok)[0], Tf[ok, c] / Cf[ok])
    print("ring profile up (d: rgb):", [(k / 4, Tup[k].round().astype(int).tolist()) for k in range(0, 36, 4)])
    print("ring profile down:", [(k / 4, Tdn[k].round().astype(int).tolist()) for k in range(0, 44, 4)])
    print("face profile (depth: rgb):", [(k / 4, Tf[k].round().astype(int).tolist()) for k in range(0, 24, 4)])
    # new geometry
    lab_n = Fn.astype(int)
    K, _ = L.sweep(Fn, lab_n, st.sx)
    Bn = L.body(Fn, K, st.r_o, st.D, st.r_e)
    dFn = L.centre(L.dist_out(Fn)); sdn = L.centre(L.sdf(Fn))
    _, nyn = L.normals(L.sdf(Fn), 1.5); nyn = L.centre(nyn)
    t = np.clip((nyn + 0.3) / 0.6, 0, 1)[..., None]
    db = np.clip((dFn / 0.25).astype(int), 0, nb - 1)
    cB = Tup[db] * (1 - t) + Tdn[db] * t
    cF = Tf[np.clip((np.maximum(sdn, 0) / 0.25).astype(int), 0, 39)]
    covFn, covBn = L.down(Fn.astype(float)), L.down(Bn.astype(float))
    col = covFn[..., None] * cF + (covBn - covFn)[..., None] * cB
    A = covBn
    rgbn = np.where(A[..., None] > 0, col / np.maximum(A, 1e-6)[..., None], 255)
    out = np.concatenate([rgbn, (A * 255)[..., None]], 2)
    # RPG: original pixels over its own body (the RPG part is taken from the original by the seam)
    return out, Bn


def main():
    L.OPAQUE["on"] = True
    a = np.concatenate([L.load(SRC / f"{n}.png") for n in NAMES], 1)
    H1, W1 = a.shape[:2]
    rgb = a[..., :3]
    B1, glow = L.body_of(a)
    R_, G_, B_ = rgb[..., 0], rgb[..., 1], rgb[..., 2]
    region = np.zeros((H1, W1), bool); region[P["y_top"]:, 40:300] = True
    orange = (R_ > 150) & (R_ - G_ > 60) & (B_ < 140) & region
    green = (G_ > 120) & (G_ >= R_ - 40) & (B_ < 120) & (G_ - B_ > 60) & region
    ys, xs = np.mgrid[0:H1, 0:W1]
    orange &= xs < 208
    green &= xs >= 208
    lab_c, n = ndi.label(orange)
    face1 = np.zeros((H1, W1), bool); ruby = np.zeros((H1, W1), bool)
    for i, sl in enumerate(ndi.find_objects(lab_c)):
        c = lab_c == i + 1
        h = sl[0].stop - sl[0].start
        if c.sum() < 6:
            continue
        if h <= 9 and sl[0].start >= 176:
            ruby |= c
        else:
            face1 |= c
    labg, ng = ndi.label(green)
    sz = ndi.sum(green, labg, range(1, ng + 1))
    face2 = np.isin(labg, 1 + np.nonzero(sz >= 30)[0])
    F_jp = L.up_hr(ndi.binary_closing(face1, iterations=1).astype(float))
    lab_jp = np.zeros(F_jp.shape, int)
    lab_jp[F_jp] = 1
    F2 = L.up_hr(face2.astype(float)); F9 = L.up_hr(ruby.astype(float))
    lab_jp[F2] = 2; lab_jp[F9] = 9
    F_all = F_jp | F2 | F9
    fy, fx = np.nonzero(face1)
    print(f"クッパJr. faces x {fx.min()}-{fx.max()} y {fy.min()}-{fy.max()}; ruby px {ruby.sum()}; RPG px {face2.sum()}")
    reg = np.zeros((H1, W1), bool); reg[P["y_top"]:, 40:215] = True
    st = L.fit_style(a, F_all, lab_jp, [1, 2, 9], region=reg)
    # Korean word
    m8, boxes = K.word_mask(gap=P["gap"])
    SS = K.SS
    wy, wx = np.nonzero(m8)
    kx0, kx1, ky0, ky1 = wx.min() / SS, (wx.max() + 1) / SS, wy.min() / SS, (wy.max() + 1) / SS
    Hh, Wh = F_jp.shape
    Y, X = np.mgrid[0:Hh, 0:Wh].astype(float)
    x1 = (X + 0.5) / L.HR; y1 = (Y + 0.5) / L.HR
    if P.get("syll"):
        # per-syllable layout (like the Japanese: big クッパ, smaller Jr., each letter tilted)
        Fn = np.zeros((Hh, Wh), bool)
        xcur = P["x_left"] if P["x_left"] is not None else fx.min()
        for (bx0, bx1), (ssx, ssy, rot, base_i) in zip(boxes, P["syll"]):
            sub = np.zeros_like(m8); c0, c1 = int(bx0 * SS), int(bx1 * SS)
            sub[:, c0:c1] = m8[:, c0:c1]
            yy_, xx_ = np.nonzero(sub)
            gy0, gy1 = yy_.min() / SS, (yy_.max() + 1) / SS
            wpx = (bx1 - bx0) * ssx
            cx_, cy_ = xcur + wpx / 2, base_i - (gy1 - gy0) * ssy / 2
            th = np.deg2rad(rot)
            xr = cx_ + (x1 - cx_) * np.cos(th) + (y1 - cy_) * np.sin(th)
            yr = cy_ - (x1 - cx_) * np.sin(th) + (y1 - cy_) * np.cos(th)
            xs1 = bx0 + (xr - xcur) / ssx
            ys1 = gy1 + (yr - base_i) / ssy
            Fn |= ndi.map_coordinates(sub.astype(float), [ys1 * SS - 0.5, xs1 * SS - 0.5], order=1,
                                      mode="constant") > 0.5
            xcur += wpx + P["syll_gap"]
        sx = sy = float("nan")
        x_left, x_right, base = P["x_left"], xcur, float("nan")
    else:
        Fn = None
    if Fn is None:
        x_left = P["x_left"] if P["x_left"] is not None else fx.min()
        x_right = P["x_right"]
        sx = (x_right - x_left) / (kx1 - kx0)
        sy = min(P["sy"], sx / P["ratio"])
        base = P["baseline"] if P["baseline"] is not None else np.percentile(fy, 97)
        cx, cy = (x_left + x_right) / 2, base - (ky1 - ky0) * sy / 2
        th = np.deg2rad(P["rot"])
        xr = cx + (x1 - cx) * np.cos(th) + (y1 - cy) * np.sin(th)
        yr = cy - (x1 - cx) * np.sin(th) + (y1 - cy) * np.cos(th)
        xs1 = kx0 + (xr - x_left) / sx
        ys1 = ky1 + (yr - base) / sy
        Fn = ndi.map_coordinates(m8.astype(float), [ys1 * SS - 0.5, xs1 * SS - 0.5], order=1, mode="constant") > 0.5
    # stroke weight: the Japanese letters are heavier; grow the Korean strokes toward it
    def ridge_w(Fh):
        d = ndi.distance_transform_edt(Fh)
        r = (d >= ndi.maximum_filter(d, size=3)) & (d > 0.5 * L.HR)
        return 2 * np.median(d[r]) / L.HR
    wj, wn = ridge_w(F_jp), ridge_w(Fn)
    grow = min(P["grow_max"], max(0.0, (wj - wn) / 2))
    if grow > 0:
        Fn = L.sdf(Fn) > -grow
    print(f"stroke JP {wj:.2f}px, Korean {wn:.2f}px -> grow {grow:.2f} -> {ridge_w(Fn):.2f}px")
    print(f"Korean word: sx={sx:.3f} sy={sy:.3f} (ratio {sx / sy:.2f}), x {x_left:.0f}-{x_right:.0f}, baseline {base:.1f}")
    F = Fn | F2
    lab = np.zeros(F.shape, int); lab[Fn] = 1; lab[F2] = 2
    sk = np.zeros((H1, W1, 4)); sk[..., :3] = 255; sk[..., 3] = L.down(F.astype(float)) * 255
    L.save(sk, LOGO / "steps/fileKJ_1_skeleton.png")
    chk, _ = L.render((H1, W1), F_all, lab_jp, st, {1: 1, 2: 2, 9: 9}, face_knn=True)
    L.save(chk, LOGO / "fit/rerender_fileKJ.png")
    out, B_hr = L.render((H1, W1), F, lab, st, {1: 1, 2: 2}, face_knn=True)
    if P.get("param_rings", True):
        out, B_hr = ring_render(a, F_all, lab_jp, Fn, F2, st, B1, glow, reg)
    L.save(out, LOGO / "steps/fileKJ_2_model.png")
    covo = L.down(F2.astype(float))
    m2 = covo >= 1
    out[m2] = a[m2]
    A = out[..., 3:] / 255
    comp = out[..., :3] * A + 255 * (1 - A)
    x = np.arange(W1)
    w = np.clip((x - P["seam"][0]) / (P["seam"][1] - P["seam"][0]), 0, 1)[None, :, None]
    changed = np.zeros((H1, W1), bool); changed[P["y_top"]:, :] = True
    wy_ = ndi.gaussian_filter(changed.astype(float), 2)[..., None]
    wgt = (1 - w) * wy_
    res = rgb * (1 - wgt) + comp * wgt
    # seam band: both sides are dark shapes on white -> union of the two = per-channel minimum
    b0, b1 = P["seam"]
    band = np.zeros((H1, W1), bool); band[P["y_top"]:, b0:b1] = True
    res[band] = np.minimum(comp, rgb)[band]
    res[:, b1:][changed[:, b1:]] = rgb[:, b1:][changed[:, b1:]]
    # next to R only R's own body stays original (user review 2026-09-30: the band kept the white /
    # yellow rim of the old Jr. between 어 and R); R is drawn in front of the Korean word
    K2, _ = L.sweep(F2, F2.astype(int), st.sx)
    rpgB = ndi.binary_dilation(L.down(L.body(F2, K2, st.r_o, st.D, st.r_e).astype(float)) > 0, iterations=1)
    zone = np.zeros((H1, W1), bool); zone[P["y_top"]:, b0 - P["r_zone"][0]:b1 + P["r_zone"][1]] = True
    faceR = ndi.binary_dilation(L.down(F2.astype(float)) > 0, iterations=1)
    ownR = faceR | (rpgB & (rgb.max(2) < 170))      # R's face and its dark outline / 3D side only
    res[zone & ~ownR] = comp[zone & ~ownR]
    res[zone & ownR] = rgb[zone & ownR]
    labB, _ = ndi.label(B1)
    logo_ids = np.unique(labB[L.down(F_all.astype(float)) > 0])
    art = (labB > 0) & ~np.isin(labB, logo_ids[logo_ids > 0])
    art = ndi.binary_dilation(art, iterations=1)
    near = L.down(((L.dist_out(B_hr) <= 10) | (L.dist_out(L.up_hr(B1 & ~art & reg)) <= 10)).astype(float)) > 0
    keep = ~near | art
    # the two smoke puffs are drawn in front of the letters: keep them as they are
    puffs = np.zeros((H1, W1), bool)
    puff_list = []
    for (x0, y0, x1, y1) in P["puffs"]:
        box = np.zeros((H1, W1), bool); box[y0:y1, x0:x1] = True
        inner = box & (rgb.min(2) >= 205) & ~glow
        lab_p, npf = ndi.label(inner)
        szp = ndi.sum(inner, lab_p, range(1, npf + 1))
        big = np.isin(lab_p, 1 + np.nonzero(szp >= 12)[0])
        # a puff interior is pinkish white enclosed by its own dark line (not the letter's white ring:
        # that one touches yellow)
        yellow = ndi.binary_dilation((R_ > 200) & (G_ > 180) & (B_ < 120), iterations=2)
        ids = [i for i in range(1, npf + 1) if (lab_p == i).sum() >= 12 and not ((lab_p == i) & yellow).any()]
        puff = np.isin(lab_p, ids)
        # the whole puff in front of the new letters: its interior plus the dark outline and tails
        # joined to it (user review 2026-09-30: a 3 px halo left the outline cut by the new rim)
        near = ndi.distance_transform_edt(~puff) <= P["puff_reach"]
        dark = rgb.max(2) < 170
        full = puff | (near & dark & box)
        full = ndi.binary_closing(full, iterations=1) & (near | puff)
        full |= ndi.binary_dilation(full, iterations=1) & near & (rgb.min(2) < 245) & ~yellow
        puff_list.append(full)
        puffs |= full
    res[keep & ~puffs] = rgb[keep & ~puffs]
    res[puffs] = comp[puffs]                    # the new letters (or white) where a puff was
    # the new 쿠 stands higher than ク: move each puff by the smallest step up / left that keeps it
    # off the Korean face and its white-yellow rim, so it sits on the outer corner like the original
    clear = ndi.binary_dilation(L.down(Fn.astype(float)) > 0.3, iterations=P["puff_clear"])
    for full in puff_list:
        best = None
        for dy in range(0, -13, -1):
            for dx in range(0, -9, -1):
                m = np.roll(np.roll(full, dy, 0), dx, 1)
                if not (m & clear).any() and (best is None or dx * dx + dy * dy < best[0]):
                    best = (dx * dx + dy * dy, dx, dy)
        _, dx, dy = best or (0, 0, 0)
        m = np.roll(np.roll(full, dy, 0), dx, 1)
        res[m] = np.roll(np.roll(rgb, dy, 0), dx, 1)[m]
        print("puff moved", (dx, dy))
    res = np.concatenate([res, np.full((H1, W1, 1), 255.0)], 2)
    DST.mkdir(parents=True, exist_ok=True)
    L.save(res[:, :144], DST / f"{NAMES[0]}.png")
    L.save(res[:, 144:], DST / f"{NAMES[1]}.png")
    L.save(res, LOGO / "steps/fileKJ_3_final.png")


if __name__ == "__main__":
    main()
