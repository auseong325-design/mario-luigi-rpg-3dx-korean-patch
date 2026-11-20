"""File-select logo 「쿠파주니어 RPG」 (MLyt MENU_FILE_LOAD_JP_ja LOAD_GAME_IMG_KJ_L/R, 144+256 x 208, RGB565,
opaque on white).

Letters (kj_mario.py): the Japanese 「クッパJr.」 is set in MARIO Font, so 쿠파주니어 is put together from
the Korean MARIO Font (Nintendo of Korea's 「슈퍼 마리오 RPG」 subtitle), every syllable the same size,
each turned a few degrees on its own like the Japanese letters. The Korean font is wide, so the word
starts further left than クッパJr. (the smoke puff at its top-left corner moves with it).
Decoration: the Japanese 「クッパJr.」 of this image (below).

Measured on the Japanese letters (ring profile by distance from the face, straight edges):
  face    orange (239, 74..91, 0) darker at the top, fine diagonal hatching, 1 px red rim on the edges that
          face down / right (the light comes from the top left), pink anti-aliasing into the white
  white   to 2.4 px, the last px tinted towards the yellow
  yellow  2.4 .. 3.6 px (255, 255, 110), olive where it meets the maroon
  maroon  3.6 .. 6.9 px, darker inside / on the top edges, redder outside / at the bottom
  every ring is a MITRE offset of the letter polygons: the outline keeps the sharp corners of the
  hand-cut letters (no rounding), which is what makes the Japanese silhouette jagged.
Kept: RPG (in front), Bowser Jr., stars, both smoke puffs (in front; the left one moved with the word).
"""
from __future__ import annotations

import json
import sys

import numpy as np
from PIL import Image, ImageDraw
from scipy import ndimage as ndi
from shapely.geometry import MultiPolygon, Polygon
from shapely.ops import unary_union
from shapely import affinity

import kj_mario as KM
import l2

HR = l2.HR
SRC = l2.ROOT / "work/img/lyt/3DX/MLyt/MENU_FILE_LOAD_JP_ja"
NAMES = ("LOAD_GAME_IMG_KJ_L_00_JP_ja", "LOAD_GAME_IMG_KJ_R_00_JP_ja")
P = dict(x_left=26.0, x_right=201.0, y_top=153.5, condense=0.9,
         gap_ref=4.0,                           # gap between the syllables (reference px)
         r_white=2.4, r_yellow=3.6, r_maroon=6.9, mitre=2.2,
         puffs=[(44, 122, 92, 162), (196, 184, 230, 208)], keep_x=205)
if len(sys.argv) > 1 and sys.argv[1].startswith("{"):
    P.update(json.loads(sys.argv[1]))

ORANGE_TOP, ORANGE_BOT = np.array([239, 72, 0.0]), np.array([239, 92, 0.0])
RIM = np.array([214, 18, 0.0])
YELLOW = np.array([255, 255, 112.0])
MAR_IN, MAR_OUT = np.array([62, 0, 0.0]), np.array([120, 12, 0.0])
MAR_TOP = np.array([45, 2, 0.0])


def raster(geom, shape_hr):
    """shapely (multi)polygon in 1x px -> hi-res bool mask (pixel centres)."""
    img = Image.new("L", (shape_hr[1], shape_hr[0]), 0)
    d = ImageDraw.Draw(img)
    polys = geom.geoms if isinstance(geom, MultiPolygon) else [geom]
    for p in polys:
        d.polygon([(x * HR - 0.5, y * HR - 0.5) for x, y in p.exterior.coords], fill=255)
        for h in p.interiors:
            d.polygon([(x * HR - 0.5, y * HR - 0.5) for x, y in h.coords], fill=0)
    return np.asarray(img) > 127


def layout_word():
    """MARIO-font syllables, one size; condensed to P['condense']; turned by KM.TILT about the middle of
    their cap line; packed with a fixed gap; scale chosen so the word spans x_left..x_right."""
    S = KM.syllables()

    def place(sc):
        geoms = []
        x = P["x_left"]
        for name, tilt, bob in zip(KM.ORDER, KM.TILT, KM.BOB):
            g = affinity.scale(S[name], sc * P["condense"], sc, origin=(0, 0))
            g = affinity.rotate(g, tilt, origin=((g.bounds[0] + g.bounds[2]) / 2, 0))
            g = affinity.translate(g, x - g.bounds[0], P["y_top"] + bob * sc)
            geoms.append(g)
            x = g.bounds[2] + P["gap_ref"] * sc * P["condense"]
        return geoms
    lo, hi = 0.3, 1.2
    for _ in range(30):
        sc = (lo + hi) / 2
        right = place(sc)[-1].bounds[2]
        lo, hi = (sc, hi) if right < P["x_right"] else (lo, sc)
    geoms = place(lo)
    print("ref->px %.3f (cap height %.1f px)  x %.1f..%.1f  y %.1f..%.1f" % (
        lo, 44 * lo, geoms[0].bounds[0], geoms[-1].bounds[2],
        min(g.bounds[1] for g in geoms), max(g.bounds[3] for g in geoms)))
    return geoms, lo


def jp_masks(a):
    rgb = a[..., :3]
    r, g, b = rgb[..., 0], rgb[..., 1], rgb[..., 2]
    H, W = r.shape
    yy, xx = np.mgrid[0:H, 0:W]
    reg = (yy > 135) & (yy < 200) & (xx < 206)
    face = (r > 180) & (r - g > 60) & (b < 170) & reg           # orange letters, red rims, the ruby
    lab, n = ndi.label(face)
    sizes = ndi.sum(face, lab, range(1, n + 1))
    face = np.isin(lab, 1 + np.nonzero(sizes >= 4)[0])
    green = (g > r + 20) & (g > 120) & (yy > 130) & (xx >= 200)  # R P G faces
    return face, green


def main():
    a = np.concatenate([l2.load(SRC / f"{n}.png") for n in NAMES], 1)
    H1, W1 = a.shape[:2]
    rgb0 = a[..., :3]
    shp = (H1 * HR, W1 * HR)
    face_jp, green = jp_masks(a)
    sil_jp = ndi.distance_transform_edt(~face_jp) <= 10.5
    sil_r = ndi.distance_transform_edt(~green) <= 9.0
    nonwhite = rgb0.min(2) < 245
    # smoke puffs (in front of the word): their pixels outside the old word, holes filled
    puff = np.zeros((H1, W1), bool)
    puffs = []
    for x0, y0, x1, y1 in P["puffs"]:
        box = np.zeros((H1, W1), bool)
        box[y0:y1, x0:x1] = True
        p = box & nonwhite & ~sil_jp
        lab, n = ndi.label(p)
        if n:
            sizes = ndi.sum(p, lab, range(1, n + 1))
            p = np.isin(lab, 1 + np.nonzero(sizes >= 12)[0])
        pm = ndi.binary_fill_holes(ndi.binary_dilation(p, iterations=1)) & box
        puffs.append(pm)
        puff |= pm
    # R in front: its face (the bright component holding the green) and its own dark outline
    xcol = np.arange(W1)[None, :]
    bright = (rgb0.max(2) > 150) & ~(rgb0.min(2) > 200)
    labb, _ = ndi.label(bright & (xcol >= 209))           # R's face starts right of x 209
    ids = np.unique(labb[green])
    r_face = np.isin(labb, ids[ids > 0])
    dark = rgb0.max(2) < 150
    r_front = r_face | (dark & (ndi.distance_transform_edt(~r_face) <= 9.5) & (xcol >= 203))
    r_front &= ~(ndi.distance_transform_edt(~face_jp) <= 2.5)       # never the old Jr. letters
    # erase the old word (letters, ruby, rings) everywhere except R and the puffs
    erase = sil_jp & ~r_front
    base = rgb0.copy()
    base[erase] = 255.0
    # --- the Korean word
    geoms, scale = layout_word()
    # the left puff sits on the word's top-left corner (as on ク): move it with the word
    dx_puff = int(round(geoms[0].bounds[0] - 71.0))
    base[puffs[0]] = 255.0
    puff_l_src = puffs[0]
    puff_l = np.roll(puffs[0], dx_puff, axis=1)
    rgb_l = np.roll(rgb0, dx_puff, axis=1)
    word = unary_union(geoms)
    jm = dict(join_style=2, mitre_limit=P["mitre"])
    g_white = word.buffer(P["r_white"], **jm)
    g_yel = word.buffer(P["r_yellow"], **jm)
    g_mar = word.buffer(P["r_maroon"], **jm)
    F = raster(word, shp)
    Wm = raster(g_white, shp)
    Ym = raster(g_yel, shp)
    Mm = raster(g_mar, shp)
    # inside a letter the yellow line only survives where the strokes are far apart (as in the
    # Japanese ク); the specks left in narrow gaps become white
    # (also small yellow / maroon islands enclosed by a letter's white: counters too small to show them)
    for _ in range(2):
        rest = Mm & ~Wm
        lab_y, ny = ndi.label(rest)
        if ny:
            sz = ndi.sum(rest, lab_y, range(1, ny + 1)) / (HR * HR)
            small = 1 + np.nonzero(sz < 30)[0]
            Wm |= np.isin(lab_y, small)
            Ym |= np.isin(lab_y, small)
    # larger enclosed gaps (inside ㅍ / ㅈ): only the thin yellow seam of the Japanese ク, no maroon
    rest = Mm & ~Wm
    lab_y, ny = ndi.label(rest)
    if ny:
        sz = ndi.sum(rest, lab_y, range(1, ny + 1))
        outer = 1 + int(np.argmax(sz))
        Ym |= (lab_y > 0) & (lab_y != outer)
    # maroon slivers reaching into narrow gaps between strokes (thinner than ~3 px) become yellow
    mar_r = Mm & ~Ym
    yy_, xx_ = np.mgrid[-6:7, -6:7]
    disk = (xx_ ** 2 + yy_ ** 2) <= 36
    Ym |= mar_r & ~ndi.binary_opening(mar_r, structure=disk)
    Y = (np.arange(shp[0])[:, None] + 0.5) / HR
    X = (np.arange(shp[1])[None, :] + 0.5) / HR
    col = np.ones(shp + (3,)) * 255.0
    # maroon: darker inside and on top-facing edges, redder towards the outer edge / bottom
    dY = ndi.distance_transform_edt(~Ym) / HR
    t = np.clip(dY / max(P["r_maroon"] - P["r_yellow"], 1e-3), 0, 1)
    gy, gx = l2.grad_normal(ndi.distance_transform_edt(~Ym).astype(float) / HR, 1.0)
    up = np.clip(-gy, 0, 1)                       # outward normal pointing up
    mar = MAR_IN[None, None] * (1 - t[..., None]) + MAR_OUT[None, None] * t[..., None]
    mar = mar * (1 - up[..., None] * 0.6) + MAR_TOP[None, None] * (up[..., None] * 0.6)
    col[Mm] = mar[Mm]
    col[Ym] = YELLOW
    col[Wm] = 255.0
    # the white's last px towards the yellow is tinted (soft inner edge of the yellow line)
    dWo = ndi.distance_transform_edt(Wm) / HR
    tint = np.clip(1 - dWo / 1.0, 0, 1) * Wm * 0.35
    col = col * (1 - tint[..., None]) + np.array([255, 255, 150.0]) * tint[..., None]
    # face: vertical orange gradient, hatching along the letter's own diagonal, red rim down/right
    ty = np.clip((Y - 156) / 24, 0, 1)
    fc = np.broadcast_to(ORANGE_TOP * (1 - ty[..., None]) + ORANGE_BOT * ty[..., None], shp + (3,)).copy()
    lab_s = np.zeros(shp, np.int16)
    for i, g in enumerate(geoms):
        lab_s[raster(g, shp)] = i + 1
    hatch = np.zeros(shp)
    for i, tilt in enumerate(KM.TILT):
        th = np.radians(45 + tilt)
        ph = 2 * np.pi * (X * np.cos(th) + Y * np.sin(th)) / 3.0
        hatch = np.where(lab_s == i + 1, np.sin(ph), hatch)
    fc[..., 1] += 9 * hatch
    sdF = ndi.distance_transform_edt(F) / HR
    gyF, gxF = l2.grad_normal(-(ndi.distance_transform_edt(F) / HR) + ndi.distance_transform_edt(~F) / HR, 0.8)
    downright = np.clip(gyF * 0.8 + gxF * 0.6, 0, 1)
    rim = np.clip(1 - sdF / 1.0, 0, 1) * (0.35 + 0.65 * downright)
    fc = fc * (1 - rim[..., None]) + RIM * rim[..., None]
    col[F] = fc[F]
    cov = l2.down(Mm.astype(float))
    word_rgb = l2.down(col * Mm[..., None]) / np.maximum(cov, 1e-6)[..., None]
    out = base * (1 - cov[..., None]) + word_rgb * cov[..., None]
    # RPG and its outline stay in front; puffs in front
    out[r_front] = rgb0[r_front]
    # junction with R: the word's maroon outline and R's outline are one shape (as in the Japanese
    # logo). Inside the closing of both silhouettes: the word's yellow / white / face where the word
    # has them, R's face where R has it, otherwise one clean maroon (R's own pixels when they are
    # plain maroon, so its shading stays)
    word1 = cov > 0.5
    ycov = l2.down(Ym.astype(float))
    both = word1 | r_front
    yy, xx = np.mgrid[0:H1, 0:W1]
    zone = (xx >= 194) & (xx < 214) & (yy >= 140) & (yy < 200)
    closed = (ndi.binary_closing(both, structure=np.ones((3, 3)), iterations=3) | both) & zone
    inner = ycov > 0.5
    plain_maroon = (rgb0.max(2) < 135) & (rgb0[..., 1] < 40) & r_front
    fill = closed & ~inner & ~r_face
    mar_mid = MAR_IN + (MAR_OUT - MAR_IN) * 0.5
    out[fill] = np.where(plain_maroon[fill][:, None], rgb0[fill], mar_mid)
    word_part = closed & inner & ~r_face
    out[word_part] = word_rgb[word_part]
    gap = fill
    print("junction px merged:", int(fill.sum()))
    if "--debug" in sys.argv:
        for y in range(166, 190, 3):
            print(y, " ".join(f"{x}:{'R' if r_front[y, x] else ''}{'P' if puff[y, x] else ''}{'E' if erase[y, x] else ''}"
                              f"{'W' if word1[y, x] else ''}={tuple(int(v) for v in out[y, x])}" for x in range(203, 211)))
    out[puffs[1]] = rgb0[puffs[1]]
    out[puff_l] = rgb_l[puff_l]
    print("left puff moved by", dx_puff, "px")
    res = np.concatenate([out, np.full((H1, W1, 1), 255.0)], 2)
    q = res.copy()
    q[..., 0] = np.rint(res[..., 0] / 255 * 31) * 255 / 31
    q[..., 1] = np.rint(res[..., 1] / 255 * 63) * 255 / 63
    q[..., 2] = np.rint(res[..., 2] / 255 * 31) * 255 / 31
    l2.save(res[:, :144], l2.HERE / f"out/{NAMES[0]}.png")
    l2.save(res[:, 144:], l2.HERE / f"out/{NAMES[1]}.png")
    l2.save(q, l2.HERE / "out/fileload_KJ_rgb565.png")
    changed = np.abs(q[..., :3] - rgb0).max(2) > 12
    ys, xs = np.nonzero(changed)
    print("changed box x %d..%d y %d..%d" % (xs.min(), xs.max(), ys.min(), ys.max()))
    l2.sheet([[("Japanese x3", l2.zoom_img(rgb0[115:208, 30:300], 3))],
              [("Korean x3", l2.zoom_img(q[115:208, 30:300, :3], 3))]], l2.HERE / "review/kj_v2_zoom.png")
    l2.sheet([[("Japanese", rgb0), ("Korean", q[..., :3])]], l2.HERE / "review/kj_v2_1x.png")


if __name__ == "__main__":
    main()
