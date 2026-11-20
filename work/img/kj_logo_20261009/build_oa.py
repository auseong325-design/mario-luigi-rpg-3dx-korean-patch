"""OA안 final texture: the official 「쿠파주니어」 glyphs (fit_official.py, layout design.PLANS["OA"]) dressed
in the Japanese 「クッパJr.」 material, on the file-select image LOAD_GAME_IMG_KJ_L/R (144 + 256 x 208).

Material model - measured on the Japanese letters of this very image (README 8장):
  face    orange R 239, G 72 -> 92 from the top of the word to its bottom, B 0; fine "/" hatching
          (period 3.0 px, wave direction 54-63 deg, G +-7); 1 px red rim (214, 18, 0) on the edges that
          face down / right
  white   0 .. r_white px from the face
  yellow  r_white .. r_yellow (strong yellow, B ~ 30)
  maroon  r_yellow .. the outer edge; the outer edge is the mitre offset r_maroon moved down by
          maroon_dy (thin on top, thick at the bottom), dark on top-facing edges, red at the bottom
  every ring is a MITRE offset of the letters (sharp corners like the hand-cut original).
  Drawn crisp at 8x and box-filtered to 1x (the anti-aliasing of every border comes from that).
  A first try with an empirical colour(distance, direction) table blurred the borders: the original's
  outer maroon edge is hand-drawn, so at one distance it is sometimes maroon, sometimes white.
  The radii are fitted so that the Japanese letters re-drawn with this model match the original
  (`python build_oa.py fit`, the check sheet is sheets/oa_material_check_jp.png).
Kept in front, pixel for pixel: R P G (and R's outline) and the right smoke puff. The left puff sits
behind the word as in the original (its tail runs under ク's ring): it moves down with the lower word
until its tail is 1 px inside the new ring. The old word (letters, ruby, rings) is erased to white.

  python build_oa.py fit   - fit the ring radii on the Japanese word (writes out/material.json)
  python build_oa.py jp    - re-draw the Japanese word with the model, compare with the original
  python build_oa.py kr    - the Korean word: out/LOAD_GAME_IMG_KJ_{L,R}_00_JP_ja.png + review sheets
"""
from __future__ import annotations

import itertools
import json
import math
import sys

import numpy as np
from PIL import Image, ImageDraw
from scipy import ndimage as ndi
from shapely import affinity
from shapely.geometry import MultiPolygon
from shapely.ops import unary_union

import design as D
import glyphs as G
import sheet as SH

HERE = G.HERE
OUT = HERE / "out"
MAT_JSON = OUT / "material.json"
H1, W1 = D.H1, D.W1
NAMES = ("LOAD_GAME_IMG_KJ_L_00_JP_ja", "LOAD_GAME_IMG_KJ_R_00_JP_ja")
HR = 8
WIN = (52, 136, 216, 206)                    # x0, y0, x1, y1: the word's window (everything is drawn here)

MAT = dict(r_white=2.7, r_yellow=4.0, r_maroon=7.2, maroon_dy=0.55, mitre=2.2,
           yellow=(242, 236, 28), yellow_in=(255, 255, 175),
           maroon_up=(62, 12, 0), maroon_down=(108, 16, 0), maroon_side=(70, 4, 0),
           rim=(214, 18, 0), face_r=239.0, g_top=72.0, g_bot=92.0, y_top=156.0, y_span=24.0,
           hatch_period=3.0, hatch_amp=7.0)
HATCH_DEG = {"쿠": 55.0, "파": 60.0, "주": 57.0, "니": 62.0, "어": 56.0}


def load_mat():
    m = dict(MAT)
    if MAT_JSON.exists():
        m.update(json.loads(MAT_JSON.read_text(encoding="utf-8")))
    return m


# ----------------------------------------------------------------------------- hi-res rasters (window)
def rast(geom):
    x0, y0, x1, y1 = WIN
    img = Image.new("L", ((x1 - x0) * HR, (y1 - y0) * HR), 0)
    d = ImageDraw.Draw(img)
    polys = geom.geoms if isinstance(geom, MultiPolygon) else [geom]
    for p in polys:
        if p.is_empty:
            continue
        d.polygon([((x - x0) * HR - 0.5, (y - y0) * HR - 0.5) for x, y in p.exterior.coords], fill=255)
        for h in p.interiors:
            d.polygon([((x - x0) * HR - 0.5, (y - y0) * HR - 0.5) for x, y in h.coords], fill=0)
    return np.asarray(img) > 127


def down(hr):
    h, w = hr.shape[0] // HR, hr.shape[1] // HR
    return hr.reshape(h, HR, w, HR, *hr.shape[2:]).mean((1, 3))


def word_colour(geom, labels_hr, hatch_by_label, m):
    """hi-res colour and coverage of the dressed word inside WIN."""
    jm = dict(join_style="mitre", mitre_limit=m["mitre"])
    F = rast(geom)
    Wm = rast(geom.buffer(m["r_white"], **jm)) | F
    Ym = rast(geom.buffer(m["r_yellow"], **jm)) | Wm
    Mm = rast(affinity.translate(geom.buffer(m["r_maroon"], **jm), 0, m["maroon_dy"])) | Ym
    # counters (yellow / maroon enclosed by a letter's white, not part of the outer ring), as in the
    # original: tiny ones (< 30 px) stay white, larger ones keep only the yellow seam (no maroon)
    rest = Mm & ~Wm
    lab, n = ndi.label(rest)
    if n > 1:
        sizes = ndi.sum(rest, lab, range(1, n + 1)) / (HR * HR)
        outer = 1 + int(np.argmax(sizes))
        for i, sz in enumerate(sizes, start=1):
            if i == outer:
                continue
            isl = lab == i
            if sz < 30:
                Wm |= isl
                Ym |= isl
            else:
                Ym |= isl
    shp = F.shape
    x0, y0 = WIN[0], WIN[1]
    Y = (np.arange(shp[0])[:, None] + 0.5) / HR + y0
    X = (np.arange(shp[1])[None, :] + 0.5) / HR + x0
    # maroon, shaded by the outward direction of the ring (dark facing up, red facing down)
    dist = ndi.distance_transform_edt(~Ym).astype(np.float32)
    s = ndi.gaussian_filter(dist, HR * 1.0)
    gy, gx = np.gradient(s)
    ny = gy / (np.hypot(gx, gy) + 1e-9)               # +1 = outward normal points down
    up_c, dn_c, sd_c = (np.array(m[k], float) for k in ("maroon_up", "maroon_down", "maroon_side"))
    w_up = np.clip(-ny, 0, 1)[..., None]
    w_dn = np.clip(ny, 0, 1)[..., None]
    col = sd_c * (1 - w_up - w_dn) + up_c * w_up + dn_c * w_dn
    # yellow (its inner 0.4 px paler, the soft join with the white)
    yin = np.clip(1 - ndi.distance_transform_edt(~Wm) / HR / 0.4, 0, 1)[..., None]
    yel = np.array(m["yellow"], float) * (1 - yin) + np.array(m["yellow_in"], float) * yin
    col = np.where((Ym & ~Wm)[..., None], yel, col)
    col = np.where((Wm & ~F)[..., None], 255.0, col)
    # face: gradient + hatching per letter + red rim on the lower / right edges
    ty = np.clip((Y - m["y_top"]) / m["y_span"], 0, 1)
    fc = np.zeros(shp + (3,))
    fc[..., 0] = m["face_r"]
    fc[..., 1] = m["g_top"] + (m["g_bot"] - m["g_top"]) * ty
    hatch = np.zeros(shp)
    for lab, deg in hatch_by_label.items():
        th = math.radians(deg)
        ph = 2 * np.pi * (X * math.cos(th) + Y * math.sin(th)) / m["hatch_period"]
        hatch = np.where(labels_hr == lab, np.sin(ph), hatch)
    fc[..., 1] += m["hatch_amp"] * hatch
    dF = ndi.distance_transform_edt(F).astype(np.float32) / HR
    sF = ndi.gaussian_filter(ndi.distance_transform_edt(~F).astype(np.float32)
                             - ndi.distance_transform_edt(F).astype(np.float32), HR * 0.8)
    fgy, fgx = np.gradient(sF)
    fn = np.hypot(fgx, fgy) + 1e-9
    downright = np.clip((fgy / fn) * 0.8 + (fgx / fn) * 0.6, 0, 1)
    rim = (np.clip(1 - dF / 1.0, 0, 1) * downright)[..., None]
    fc = fc * (1 - rim) + np.array(m["rim"], float) * rim
    col = np.where(F[..., None], fc, col)
    return col, Mm


def compose(base, geom, labels_hr, hatch_by_label, m):
    col, Mm = word_colour(geom, labels_hr, hatch_by_label, m)
    x0, y0, x1, y1 = WIN
    cov = down(Mm.astype(float))
    rgb = down(col * Mm[..., None]) / np.maximum(cov, 1e-6)[..., None]
    out = base.copy()
    win = out[y0:y1, x0:x1]
    out[y0:y1, x0:x1] = win * (1 - cov[..., None]) + rgb * cov[..., None]
    full = np.zeros((H1, W1))
    full[y0:y1, x0:x1] = cov
    return out, full


def labels_hr_of(geoms, angles):
    lab = np.zeros(((WIN[3] - WIN[1]) * HR, (WIN[2] - WIN[0]) * HR), np.int16)
    for i, g in enumerate(geoms):
        lab[rast(g.buffer(1.5, join_style="mitre"))] = i + 1
    return lab, {i + 1: a for i, a in enumerate(angles)}


# ----------------------------------------------------------------------------- the Japanese reference
def jp_reference():
    a = D.load_jp()
    M = D.jp_masks(a)
    face = M["face"] & ~M["ruby"]
    # sub-pixel face edge: the face (B ~ 0) is anti-aliased into the white ring (B 255), so 1 - B / 255
    # is the face coverage of an edge pixel (the red rim has B 0 too)
    rgb = a[..., :3]
    edge = ndi.binary_dilation(face, iterations=1) & ~ndi.binary_dilation(M["ruby"], iterations=2)
    cov = np.where(edge, np.clip(1.0 - rgb[..., 2] / 255.0, 0, 1), 0.0)
    cov[face] = 1.0
    vec = G._vectorise(cov, up=8, eps=0.15)
    return rgb, M, vec


def erase_plate(rgb, M):
    """the original with the old word (letters, ruby, rings) whitened, except R and the puffs."""
    # the old outline's anti-aliased outer edge reaches ~9.8 px from the old faces; R's own edge pixels
    # (next to its front mask) stay
    sil = ndi.distance_transform_edt(~M["face"]) <= 10.5
    keep = ndi.distance_transform_edt(~M["r_front"]) <= 1.5
    erase = sil & ~M["r_front"] & ~M["puff"] & ~keep
    base = rgb.copy()
    base[erase] = 255.0
    return base, erase


def q565(rgb):
    q = rgb.copy()
    q[..., 0] = np.rint(np.clip(rgb[..., 0], 0, 255) / 255 * 31) * 255 / 31
    q[..., 1] = np.rint(np.clip(rgb[..., 1], 0, 255) / 255 * 63) * 255 / 63
    q[..., 2] = np.rint(np.clip(rgb[..., 2], 0, 255) / 255 * 31) * 255 / 31
    return q


JP_LETTERS = ((60, 101, 54.0), (101, 121, 57.0), (121, 154, 60.0), (154, 182, 63.0), (182, 198, 57.0),
              (198, 206, 57.0))


def jp_redraw(m, ctx=None):
    rgb, M, vec = ctx or jp_reference()
    base, erase = erase_plate(rgb, M)
    polys = list(vec.geoms) if isinstance(vec, MultiPolygon) else [vec]
    geoms, angles = [], []
    for x0, x1, a in JP_LETTERS:
        part = [p for p in polys if x0 <= p.centroid.x < x1]
        if part:
            geoms.append(unary_union(part))
            angles.append(a)
    lab, ang = labels_hr_of(geoms, angles)
    out, _ = compose(base, vec, lab, ang, m)
    out[M["r_front"]] = rgb[M["r_front"]]
    out[M["puff"]] = rgb[M["puff"]]
    ruby = ndi.distance_transform_edt(~M["ruby"]) <= 8.0          # the ruby changes the white around it
    zone = erase & ~ruby
    return out, zone


def jp_error(m, ctx):
    rgb = ctx[0]
    out, zone = jp_redraw(m, ctx)
    return float(np.abs(q565(out) - rgb)[zone].mean()), out, zone


def fit():
    ctx = jp_reference()
    m = load_mat()
    best = None
    grid = dict(r_white=(2.5, 2.7, 2.9), r_yellow=(3.8, 4.0, 4.2), r_maroon=(6.9, 7.1, 7.3, 7.5),
                maroon_dy=(0.3, 0.55, 0.8))
    for vals in itertools.product(*grid.values()):
        mm = dict(m, **dict(zip(grid, vals)))
        e, _, _ = jp_error(mm, ctx)
        if best is None or e < best[0]:
            best = (e, dict(zip(grid, vals)))
        print("  ", vals, round(e, 2), flush=True)
    print("best", best)
    MAT_JSON.write_text(json.dumps(best[1], indent=1), encoding="utf-8")
    return best


def check_jp():
    ctx = jp_reference()
    m = load_mat()
    e, out, zone = jp_error(m, ctx)
    rgb = ctx[0]
    err = np.abs(q565(out) - rgb)[zone]
    rep = dict(material={k: m[k] for k in ("r_white", "r_yellow", "r_maroon", "maroon_dy")},
               pixels=int(zone.sum()), mean_abs=[round(float(v), 2) for v in err.mean(0)])
    print("JP re-draw vs original:", rep)
    diff = np.clip(np.abs(q565(out) - rgb).max(2) * 3, 0, 255) * zone
    z = 4
    crop = (slice(140, 200), slice(55, 215))
    SH.sheet([[("원본 일본어 x4", G.l2.zoom_img(rgb[crop], z))],
              [("같은 재질 모델로 다시 그린 일본어 x4 (루비 제외)", G.l2.zoom_img(q565(out)[crop], z))],
              [("차이 x3 (밝을수록 다름, 루비 주변 제외)", G.l2.zoom_img(np.repeat(diff[crop][..., None], 3, 2), z))]],
             HERE / "sheets/oa_material_check_jp.png")
    return rep


def puffs(rgb, M):
    """the two smoke puffs without the bits of the old outline that design.jp_masks lets into them:
    left = its largest piece (three specks of the old ク outline dropped), right = without the strip of the
    old 「.」 outline left of R (x < 204, within 11 px of the old faces)."""
    xx = np.arange(W1)[None, :].repeat(H1, 0)
    df = ndi.distance_transform_edt(~M["face"])
    left_all = M["puff"] & (xx < 120)
    lab, n = ndi.label(left_all)
    sizes = ndi.sum(left_all, lab, range(1, n + 1))
    left = lab == 1 + int(np.argmax(sizes))
    right_all = M["puff"] & (xx >= 120)
    right = right_all & ~((xx < 204) & (df < 11.0))
    return left_all, left, right_all, right


def tuck_dy(left, word, m):
    """how far the left puff moves down so its tail (lowest right point) sits 1 px inside the new
    word's maroon ring, as the tail of the Japanese puff sits in ク's ring."""
    ys, xs = np.nonzero(left)
    i = int(np.argmax(xs + 1.5 * ys))
    xt, yt = int(xs[i]), int(ys[i])
    ring = G.raster(affinity.translate(word.buffer(m["r_maroon"], join_style="mitre", mitre_limit=m["mitre"]),
                                       0, m["maroon_dy"]), (H1, W1))
    for dy in range(0, 16):
        if yt + dy + 1 < H1 and ring[yt + dy + 1, xt] > 0.6:
            return dy + 1, (xt, yt)
    return 0, (xt, yt)


LAST = {}          # the layers of the last build_kr() (export_layers.py)


def build_kr():
    rgb, M, _ = jp_reference()
    m = load_mat()
    base, erase = erase_plate(rgb, M)
    geoms, k = D.layout("OA")
    chars = [s["ch"] for s in D.PLANS["OA"]["syl"]]
    word = unary_union(geoms)
    lab, ang = labels_hr_of(geoms, [HATCH_DEG[c] for c in chars])
    left_all, left, right_all, right = puffs(rgb, M)
    base[left_all] = 255.0                                  # the left puff moves (below), the old
    base[right_all & ~right] = 255.0                        # outline strip by the right one goes
    dy, tail = tuck_dy(left, word, m)
    moved = np.roll(left, dy, axis=0)
    base[moved] = np.roll(rgb, dy, axis=0)[moved]           # behind the word: its tail under the ring
    out, cov = compose(base, word, lab, ang, m)
    # left of R's leg, below the new word (which ends higher than 「.」 did), the strip kept next to R's
    # outline still holds the old 「.」 ring: white there, R's own outline starts at its front mask
    yy, xx = np.mgrid[0:H1, 0:W1]
    strip = (yy >= 184) & (yy <= 197) & (xx >= 194) & (xx < 206) & (cov < 0.05) & ~M["r_front"] & ~right
    out[strip] = 255.0
    # R and the right puff stay in front, pixel for pixel
    out[M["r_front"]] = rgb[M["r_front"]]
    out[right] = rgb[right]
    q = q565(out)
    plate = base.copy()
    plate[strip] = 255.0
    LAST.update(rgb=rgb, plate=plate, front=(M["r_front"] | right), final=q, geoms=geoms, chars=chars, m=m)
    OUT.mkdir(exist_ok=True)
    res = np.concatenate([q, np.full((H1, W1, 1), 255.0)], 2)
    G.l2.save(res[:, :144], OUT / f"{NAMES[0]}.png")
    G.l2.save(res[:, 144:], OUT / f"{NAMES[1]}.png")
    G.l2.save(res, OUT / "fileload_KJ_OA.png")
    changed = np.abs(q - q565(rgb)).max(2) > 12
    ys, xs = np.nonzero(changed)
    rep = dict(scale=round(k, 3), word_bbox=[round(v, 1) for v in word.bounds],
               changed_box=[int(xs.min()), int(ys.min()), int(xs.max()), int(ys.max())],
               r_front_kept=bool((q[M["r_front"]] == q565(rgb)[M["r_front"]]).all()),
               right_puff_kept=bool((q[right] == q565(rgb)[right]).all()), left_puff_down_px=dy,
               left_puff_tail=list(tail))
    print("KR:", rep)
    z = 3
    crop = (slice(110, 208), slice(30, 330))
    SH.sheet([[("원본", rgb), ("OA안", q)]], HERE / "sheets/oa_final_1x.png")
    SH.sheet([[("원본 x3", G.l2.zoom_img(rgb[crop], z))], [("OA안 x3", G.l2.zoom_img(q[crop], z))]],
             HERE / "sheets/oa_final_zoom.png")
    (OUT / "oa_report.json").write_text(json.dumps(rep, ensure_ascii=False, indent=1), encoding="utf-8")
    return rep


if __name__ == "__main__":
    OUT.mkdir(exist_ok=True)
    what = sys.argv[1] if len(sys.argv) > 1 else "all"
    if what == "fit":
        fit()
    if what in ("jp", "all"):
        check_jp()
    if what in ("kr", "all"):
        build_kr()
