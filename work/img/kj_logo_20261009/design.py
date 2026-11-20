"""Steps 4-6 - black-and-white vector lettering for the two plans, compared with the Japanese silhouette.

A안 (완전 한글형):  쿠 파 big (like ク / パ), 주 니 어 small (in the place of Jr.)
B안 (원본 충실형):  쿠 파 big in the place of クッパ, the original 「Jr.」 kept, the small reading
                    ジュニア replaced by a small 「주니어」 (pixel-drawn, it is ~8 px tall)

Base glyphs: glyphs.skel_1dx - the bar skeleton of the official 1DX Korean 쿠 / 파, redrawn with the
Japanese letters' weight (MARIO Font) and chisel-cut ends; 주 니 어 from the same bar system.
Every syllable is its own path with its own height, turn, position and gap (PLANS below).

Writes svg/A_bw.svg, svg/B_bw.svg (one path per syllable, ids = syllables), plans.json and
sheets/A_*.png, sheets/B_*.png. No colour / texture work here (that waits for the approval).
"""
from __future__ import annotations

import json

import numpy as np
from scipy import ndimage as ndi
from shapely import affinity
from shapely.geometry import box as sbox
from shapely.ops import unary_union

import glyphs as G
import sheet as SH

HERE = G.HERE
SRC = G.ROOT / "work/img/lyt/3DX/MLyt/MENU_FILE_LOAD_JP_ja"
H1, W1 = 208, 400
RING = 6.9             # outer edge of the maroon ring (mitre offset), measured on the Japanese letters
MITRE = 2.2

# per syllable: height (px, before the turn), turn (deg, + = clockwise), bottom (px), gap to the previous
# syllable (px, closest face-to-face distance), fv / fh = vertical / horizontal stroke as a fraction of the
# height, w = width / height
PLANS = {
    "A": dict(x_left=68.0, x_right=203.0, syl=[
        dict(ch="쿠", h=34.0, rot=-5.0, bottom=189.0, gap=0.0, fv=0.26, fh=0.19, w=0.95),
        dict(ch="파", h=32.0, rot=-7.0, bottom=185.5, gap=2.6, fv=0.26, fh=0.19, w=1.10),
        dict(ch="주", h=24.0, rot=6.0, bottom=181.5, gap=2.4, fv=0.28, fh=0.21, w=0.98),
        dict(ch="니", h=21.5, rot=-4.0, bottom=186.5, gap=2.2, fv=0.28, fh=0.21, w=0.80),
        dict(ch="어", h=22.5, rot=5.0, bottom=187.0, gap=2.2, fv=0.28, fh=0.21, w=0.98),
    ]),
    "B": dict(x_left=70.0, x_right=152.5, keep_jr=True, syl=[
        dict(ch="쿠", h=34.0, rot=-4.0, bottom=188.5, gap=0.0, fv=0.26, fh=0.19, w=1.15),
        dict(ch="파", h=32.0, rot=-7.0, bottom=185.0, gap=3.0, fv=0.26, fh=0.19, w=1.42),
    ]),
    # 2nd round: the same two plans in the Korean Super Mario typeface (kst.py; the Korean lettering of
    # the Mario Party 9 「가든 배틀」 title and the Korean Mario logos)
    "KA": dict(x_left=70.0, x_right=205.0, syl=[
        dict(ch="쿠", font="kst", h=34.0, rot=-4.0, bottom=189.0, gap=0.0, fv=0.21, fh=0.185, w=0.98),
        dict(ch="파", font="kst", h=31.0, rot=-6.0, bottom=185.5, gap=2.4, fv=0.23, fh=0.19, w=1.22),
        dict(ch="주", font="kst", h=24.5, rot=5.0, bottom=182.5, gap=2.2, fv=0.24, fh=0.20, w=0.98),
        dict(ch="니", font="kst", h=18.0, rot=-4.0, bottom=187.0, gap=2.0, fv=0.25, fh=0.21, w=1.0),
        dict(ch="어", font="kst", h=19.5, rot=4.0, bottom=187.5, gap=2.0, fv=0.25, fh=0.21, w=1.12),
    ]),
    "KB": dict(x_left=70.0, x_right=152.5, keep_jr=True, syl=[
        dict(ch="쿠", font="kst", h=34.0, rot=-4.0, bottom=188.5, gap=0.0, fv=0.21, fh=0.185, w=1.08),
        dict(ch="파", font="kst", h=32.0, rot=-7.0, bottom=185.0, gap=2.8, fv=0.23, fh=0.19, w=1.32),
    ]),
    # 3rd round: the official 「쿠파주니어」 glyphs (fit_official.py; size = texture px per sample px,
    # cy = where the sample's word centre line (sample y 30) lands; the official vertical offsets of the
    # syllables are kept). word_rot turns the finished word like the Japanese one (rising to the right).
    # OA ends at x 200: R's outline starts at x 203-205 at the height of 어, and 어's white ring has to
    # show before it (like the r of Jr.).
    "OA": dict(x_left=67.0, x_right=200.0, word_rot=-3.0, syl=[
        dict(ch=c, font="official", size=1.0, rot=0.0, cy=171.0, gap=(0.0 if c == "쿠" else 2.2))
        for c in "쿠파주니어"]),
    "OB": dict(x_left=69.0, x_right=205.0, word_rot=0.0, syl=[
        dict(ch="쿠", font="official", size=1.16, rot=-4.0, cy=172.5, gap=0.0),
        dict(ch="파", font="official", size=1.16, rot=-6.0, cy=170.0, gap=2.2),
        dict(ch="주", font="official", size=0.80, rot=5.0, cy=170.5, gap=2.0),
        dict(ch="니", font="official", size=0.80, rot=-3.0, cy=176.0, gap=1.8),
        dict(ch="어", font="official", size=0.80, rot=4.0, cy=176.5, gap=1.8),
    ]),
}
SAMPLE_CY = 30.0          # the word centre line of the official orange sample (native px)
# B안 ruby 「주니어」: 8 px pixel lettering in place of ジュニア (164..189, 181..188 on the Japanese)
RUBY_GLYPHS = {
    "주": ["#######",
           "...#...",
           "..#.#..",
           ".#...#.",
           ".......",
           "#######",
           "...#...",
           "...#..."],
    "니": ["#....#",
           "#....#",
           "#....#",
           "#....#",
           "#....#",
           "#....#",
           "####.#",
           ".....#"],
    "어": ["......#",
           ".##...#",
           "#..#..#",
           "#..####",
           "#..#..#",
           ".##...#",
           "......#",
           "......#"],
}
RUBY_ORIGIN = (164.0, 181.0)


def load_jp():
    return np.concatenate([G.l2.load(SRC / f"{n}.png") for n in ("LOAD_GAME_IMG_KJ_L_00_JP_ja",
                                                                 "LOAD_GAME_IMG_KJ_R_00_JP_ja")], 1)


def jp_masks(a):
    rgb = a[..., :3]
    r, g, b = rgb[..., 0], rgb[..., 1], rgb[..., 2]
    yy, xx = np.mgrid[0:H1, 0:W1]
    face = (r > 180) & (r - g > 60) & (b < 170) & (yy > 135) & (yy < 200) & (xx < 206)
    lab, n = ndi.label(face)
    sizes = ndi.sum(face, lab, range(1, n + 1))
    face = np.isin(lab, 1 + np.nonzero(sizes >= 3)[0])
    ruby = face & (yy >= 180) & (xx >= 162) & (xx < 192)
    # 「Jr.」 = the face components starting right of パ (J 156.., r 182.., . 198..), without the ruby
    labj, nj = ndi.label(face & ~ruby)
    jr = np.zeros_like(face)
    for i, sl in enumerate(ndi.find_objects(labj)):
        if sl[1].start >= 155:
            jr |= labj == i + 1
    nonwhite = rgb.min(2) < 235
    word_sil = nonwhite & (ndi.distance_transform_edt(~face) <= 8.0)
    # R in front (its bright face holding the green, and its own dark outline) and the smoke puffs
    green = (g > r + 20) & (g > 120) & (yy > 130) & (xx >= 200)
    bright = (rgb.max(2) > 150) & ~(rgb.min(2) > 200)
    labb, _ = ndi.label(bright & (xx >= 209))
    ids = np.unique(labb[green])
    r_face = np.isin(labb, ids[ids > 0])
    dark = rgb.max(2) < 150
    r_front = r_face | (dark & (ndi.distance_transform_edt(~r_face) <= 9.5) & (xx >= 203))
    dface = ndi.distance_transform_edt(~face)
    puff = np.zeros_like(face)
    for x0, y0, x1, y1 in ((44, 122, 92, 162), (196, 184, 230, 208)):
        bx = (xx >= x0) & (xx < x1) & (yy >= y0) & (yy < y1)
        p = bx & nonwhite & (dface > 7.5)
        puff |= ndi.binary_fill_holes(ndi.binary_dilation(p, iterations=1)) & bx
    return dict(face=face, ruby=ruby, jr=jr, sil=word_sil, kupa=face & (xx < 156), r_front=r_front, puff=puff)


def syllable_geom(spec):
    """the syllable (unit height, weights relative to it) scaled to its height, turned, bottom at
    spec['bottom']."""
    if spec.get("font") == "official":
        import fit_official as F
        g = F.placed(spec["ch"])                        # sample position (native px)
        k = spec["size"]
        g = affinity.scale(g, k, k, origin=(0, SAMPLE_CY))
        g = affinity.rotate(g, spec["rot"], origin="centroid")
        return affinity.translate(g, -g.bounds[0], spec["cy"] - SAMPLE_CY)
    if spec.get("font") == "kst":
        import kst as K
        g = G.normalise(K.kst(spec["ch"], fv=spec["fv"], fh=spec["fh"], w=spec["w"]))
    else:
        g = G.normalise(G.skel_1dx(spec["ch"], fv=spec["fv"], fh=spec["fh"], w=spec["w"]))
    s = spec["h"] / (g.bounds[3] - g.bounds[1])
    g = affinity.scale(g, s, s, origin=(0, 0))
    g = affinity.rotate(g, spec["rot"], origin="centroid")
    b = g.bounds
    return affinity.translate(g, -b[0], spec["bottom"] - b[3])


def layout(plan):
    P = PLANS[plan]

    def place(k):
        out = []
        for spec in P["syl"]:
            sp = dict(spec, h=spec.get("h", 0) * k, size=spec.get("size", 0) * k)
            g = syllable_geom(sp)
            if not out:
                g = affinity.translate(g, P["x_left"], 0)
            else:
                prev = unary_union(out)
                g = affinity.translate(g, out[-1].bounds[2] + spec["gap"] - g.bounds[0], 0)
                for _ in range(60):
                    d = g.distance(prev)
                    if abs(d - spec["gap"]) < 0.05:
                        break
                    g = affinity.translate(g, spec["gap"] - d, 0)
            out.append(g)
        if P.get("word_rot"):
            word = unary_union(out)
            c = ((word.bounds[0] + word.bounds[2]) / 2, (word.bounds[1] + word.bounds[3]) / 2)
            out = [affinity.rotate(g, P["word_rot"], origin=c) for g in out]
            dx = P["x_left"] - unary_union(out).bounds[0]
            out = [affinity.translate(g, dx, 0) for g in out]
        return out
    lo, hi = (0.5, 1.3) if P["syl"][0].get("font") == "official" else (0.8, 1.0)
    # (KST / 1DX skeleton: never larger than the Japanese letters; official glyphs: size is the scale)
    for _ in range(24):
        k = (lo + hi) / 2
        right = place(k)[-1].bounds[2]
        lo, hi = (k, hi) if right < P["x_right"] else (lo, k)
    return place(lo), lo


def ruby_geom():
    parts, x = {}, RUBY_ORIGIN[0]
    for ch, rows in RUBY_GLYPHS.items():
        cells = [sbox(x + c, RUBY_ORIGIN[1] + r, x + c + 1, RUBY_ORIGIN[1] + r + 1)
                 for r, line in enumerate(rows) for c, v in enumerate(line) if v == "#"]
        parts[ch] = unary_union(cells)
        x += len(rows[0]) + 1.5
    return parts


def ring_sil(geom):
    return geom.buffer(RING, join_style=2, mitre_limit=MITRE)


def centroid_of(mask):
    ys, xs = np.nonzero(mask > 0.5)
    return float(xs.mean()), float(ys.mean())


def bw(face, sil, extra_gray=None):
    """faces black, ring silhouette grey, on white."""
    img = np.full(face.shape + (3,), 255.0)
    img = img * (1 - sil[..., None] * 0.35)
    if extra_gray is not None:
        img = img * (1 - extra_gray[..., None] * 0.35)
    return img * (1 - face[..., None]) + 0 * face[..., None]


def build(plan, a, M):
    geoms, k = layout(plan)
    rom = {"쿠": "ku", "파": "pa", "주": "ju", "니": "ni", "어": "eo"}
    items = [dict(id=f"{plan}_{rom[s['ch']]}", label=s["ch"], geom=g) for s, g in zip(PLANS[plan]["syl"], geoms)]
    ruby = ruby_geom() if PLANS[plan].get("keep_jr") else {}
    for ch, g in ruby.items():
        items.append(dict(id=f"{plan}_ruby_{rom[ch]}", label=ch, geom=g))
    word = unary_union([it["geom"] for it in items if "ruby" not in it["id"]])
    kr_face = G.raster(unary_union([it["geom"] for it in items]), (H1, W1))
    kr_sil = G.raster(ring_sil(word), (H1, W1))
    if PLANS[plan].get("keep_jr"):
        # the kept Jr. and its rings from the original; the ruby sits on the white ring like ジュニア
        kr_face = np.maximum(kr_face, M["jr"].astype(float))
        kr_sil = np.maximum(kr_sil, ((M["sil"]) & (np.arange(W1)[None, :] >= 150)).astype(float))
    jp_face = M["face"].astype(float)
    jp_sil = M["sil"].astype(float)
    # ---- review sheets
    x0, x1, y0, y1 = 40, 215, 128, 200
    crop = (slice(y0, y1), slice(x0, x1))
    orig = a[..., :3]
    p_orig = orig[crop]
    p_jp = bw(jp_face, jp_sil)[crop]
    p_kr = bw(kr_face, kr_sil)[crop]
    ov = np.full((H1, W1, 3), 255.0)
    ov = ov * (1 - 0.25 * np.maximum(jp_sil, kr_sil)[..., None])
    jpf, krf = jp_face[..., None], kr_face[..., None]
    ov = ov * (1 - 0.55 * jpf) + np.array([230, 90, 20]) * 0.55 * jpf
    ov = ov * (1 - 0.55 * krf) + np.array([20, 80, 230]) * 0.55 * krf
    p_ov = ov[crop]
    z = 4
    rows = [[("원본", G.l2.zoom_img(p_orig, z))],
            [("원본 글자 실루엣 (글자 검정, 테두리 회색)", G.l2.zoom_img(p_jp, z))],
            [(f"{plan}안 한글 실루엣 (흑백 벡터)", G.l2.zoom_img(p_kr, z))],
            [("겹침 (주황 = 원본 글자, 파랑 = 한글, 회색 = 테두리 합)", G.l2.zoom_img(p_ov, z))]]
    SH.sheet(rows, HERE / f"sheets/{plan}_compare.png")
    # in place (1x, x2, and the original next to it) - grey silhouette instead of the coloured rings
    erase = M["sil"] & ~M["r_front"] & ~M["puff"]
    base = orig.copy()
    base[erase] = 255.0
    sil_only = G.raster(ring_sil(word), (H1, W1))
    if PLANS[plan].get("keep_jr"):       # the kept Jr. shown the same way (black face, grey ring silhouette)
        sil_only = np.maximum(sil_only, (ndi.distance_transform_edt(~M["jr"]) <= RING).astype(float))
    inplace = base * (1 - 0.45 * sil_only[..., None]) + np.array([150, 150, 150]) * 0.45 * sil_only[..., None]
    inplace = inplace * (1 - kr_face[..., None])
    rows = [[("원본 (실제 크기)", orig), (f"{plan}안 배치 (흑백, 실제 크기)", inplace)],
            [("원본 x2", G.l2.zoom_img(orig[100:208, 20:320], 2))],
            [(f"{plan}안 x2", G.l2.zoom_img(inplace[100:208, 20:320], 2))]]
    SH.sheet(rows, HERE / f"sheets/{plan}_inplace.png")
    # ---- numbers
    rep = dict(scale=round(k, 3), syllables=[])
    for s, g in zip(PLANS[plan]["syl"], geoms):
        b = g.bounds
        rep["syllables"].append(dict(ch=s["ch"], bbox=[round(v, 1) for v in b], height=round(b[3] - b[1], 1),
                                     rot=s["rot"], weight=round(2 * g.area / g.length / (b[3] - b[1]), 3)))
    wb = word.bounds
    rep["word_bbox"] = [round(v, 1) for v in wb]
    rep["face_centroid_jp"] = [round(v, 1) for v in centroid_of(jp_face)]
    rep["face_centroid_kr"] = [round(v, 1) for v in centroid_of(kr_face)]
    rep["silhouette_centroid_jp"] = [round(v, 1) for v in centroid_of(jp_sil)]
    rep["silhouette_centroid_kr"] = [round(v, 1) for v in centroid_of(kr_sil)]
    rep["face_area_jp"] = int(jp_face.sum())
    rep["face_area_kr"] = int(kr_face.sum())
    rep["silhouette_iou"] = round(float(((jp_sil > 0.5) & (kr_sil > 0.5)).sum() / ((jp_sil > 0.5) | (kr_sil > 0.5)).sum()), 3)
    # ---- editable vector: texture coordinates (1 unit = 1 texture px), one path per syllable,
    # plus the Japanese faces as a locked reference layer
    from glyphs import _vectorise
    jp_vec = _vectorise(jp_face, up=8, eps=0.3)
    sil_vec = ring_sil(word)
    svg_items = [dict(id="ref_jp_faces", geom=jp_vec, fill="#e06010", opacity=0.35),
                 dict(id=f"{plan}_ring_silhouette", geom=sil_vec, fill="#999", opacity=0.35)]
    svg_items += items
    G.write_svg(HERE / f"svg/{plan}_bw.svg", svg_items, W1, H1,
                note=f"{plan}안 black-and-white lettering in texture coordinates (400 x 208 = "
                     f"LOAD_GAME_IMG_KJ_L + _R). Paths: ref_jp_faces (Japanese faces, reference), "
                     f"{plan}_ring_silhouette (outer maroon edge, mitre {RING} px), one path per syllable.")
    return rep


def main():
    (HERE / "svg").mkdir(exist_ok=True)
    (HERE / "sheets").mkdir(exist_ok=True)
    a = load_jp()
    M = jp_masks(a)
    report = {p: build(p, a, M) for p in PLANS}
    report["plans"] = PLANS
    report["ruby"] = RUBY_GLYPHS
    (HERE / "plans.json").write_text(json.dumps(report, ensure_ascii=False, indent=1), encoding="utf-8")
    for p in PLANS:
        r = report[p]
        print(p, "scale", r["scale"], "word", r["word_bbox"], "face centroid jp/kr", r["face_centroid_jp"],
              r["face_centroid_kr"], "area jp/kr", r["face_area_jp"], r["face_area_kr"], "sil IoU", r["silhouette_iou"])
        for s in r["syllables"]:
            print("   ", s)


if __name__ == "__main__":
    main()
