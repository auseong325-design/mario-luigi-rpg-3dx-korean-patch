"""Korean title logo, top layer (title_logo_JP_top, 512x256 RGBA4): デラックス -> 디럭스.

glyphs   1DX Korean logo 「디럭스」 (same role, official), uniform scale so the stroke matches the
         Japanese one (1DX 4 px -> ~2.4 px), centred where デラックス was
style    Japanese: white faces, navy outline r_t (measured), sitting in the bottom of the DX body,
         blurred outer glow (model.glow_alpha, fitted on the bottom layer)
kept     DX, 3, flames, (TM) and everything outside the text zone: original pixels
"""
from __future__ import annotations

import json
import sys

import numpy as np
from scipy import ndimage as ndi

import l2
import model as M
import seg_jp

HR = l2.HR
P_TOP = dict(scale=0.66, track=1.0, r_t=2.0, cx=None, top=200.5, y_cut=210.5,
             zone=(212, 196, 300, 224))   # x0, y0, x1, y1 of the text zone (1x)
if len(sys.argv) > 1:
    P_TOP.update(json.loads(sys.argv[1]))
NAVY = np.array([0, 51, 85.0])


def jp_text(a, zone):
    x0, y0, x1, y1 = zone
    glow = seg_jp.glow_mask(a)
    rgb = a[..., :3]
    z = np.zeros(a.shape[:2], bool)
    z[y0:y1, x0:x1] = True
    cov = np.clip((rgb.min(2) - 70.0) / (200.0 - 70.0), 0, 1) * ((a[..., 3] == 255) & ~glow & z)
    lab, n = ndi.label(cov > 0.3)
    sizes = ndi.sum(cov > 0.3, lab, range(1, n + 1))
    keep = 1 + np.nonzero(sizes >= 2)[0]
    cov = cov * np.isin(lab, keep)
    # not text: the white rim of the DX body above (row 198) and the small white sparkle on the body
    # edge above ス (x 281-283, y 199-201; rows 196-201 of x 278-285)
    cov[:200] = 0
    cov[196:202, 278:286] = 0
    return cov, glow


def kr_text():
    a = l2.load(l2.KR1DX)
    rgb = a[..., :3]
    z = np.zeros(a.shape[:2], bool)
    z[200:236, 390:472] = True
    cov = np.clip((rgb.min(2) - 70.0) / (200.0 - 70.0), 0, 1) * (a[..., 3] >= 250) * z
    lab, n = ndi.label(cov > 0.3)
    sizes = ndi.sum(cov > 0.3, lab, range(1, n + 1))
    cov = cov * np.isin(lab, 1 + np.nonzero(sizes >= 20)[0])
    # syllable column ranges (1DX): 디 395-415, 럭 422-442, 스 449-467
    syl = []
    for p, q in ((390, 418), (418, 446), (446, 472)):
        c = cov.copy()
        c[:, :p] = 0
        c[:, q:] = 0
        syl.append(c)
    return syl


def place_text(syl, s, track, cx, top, shape_hr):
    """Uniform scale s, syllables kept at their 1DX spacing + `track` px extra, block centred at cx,
    top of the block at `top` (1x)."""
    boxes = []
    for c in syl:
        ys, xs = np.nonzero(c > 0.02)
        boxes.append((xs.min(), xs.max() + 1, ys.min(), ys.max() + 1))
    ytop = min(b[2] for b in boxes)
    # x positions: 1DX positions scaled + tracking
    xs0 = [boxes[0][0] + (b[0] - boxes[0][0]) for b in boxes]
    left = [(b[0] - boxes[0][0]) * s + i * track for i, b in enumerate(boxes)]
    width = left[-1] + (boxes[-1][1] - boxes[-1][0]) * s
    x_start = cx - width / 2
    H, W = shape_hr
    Y, X = np.mgrid[0:H, 0:W].astype(float)
    X1 = (X + 0.5) / HR
    Y1 = (Y + 0.5) / HR
    out = np.zeros(shape_hr, bool)
    for c, b, lx in zip(syl, boxes, left):
        ox = x_start + lx
        xs = b[0] + (X1 - ox) / s
        ys = ytop + (Y1 - top) / s
        v = ndi.map_coordinates(c, [ys - 0.5, xs - 0.5], order=3, mode="constant")
        out |= v > 0.5
    return l2.smooth_mask(out, 0.25), (x_start, x_start + width)


def main():
    a = l2.load(l2.JP_DIR / "title_logo_JP_top.png")
    H1, W1 = a.shape[:2]
    shp = (H1 * HR, W1 * HR)
    zone = P_TOP["zone"]
    cov_jp, glow = jp_text(a, zone)
    T_jp = l2.up(cov_jp) > 0.5
    ys, xs = np.nonzero(cov_jp > 0.5)
    cx = P_TOP["cx"] or (xs.min() + xs.max() + 1) / 2
    print("JP text box x", xs.min(), xs.max(), "y", ys.min(), ys.max(), "centre", cx)
    body1 = (a[..., 3] >= 255) & ~glow
    B = l2.up(body1.astype(float), order=1) > 0.5
    # DX body without the text: drop what only the text outlines explain below y_cut
    O_jp = l2.dist_out(T_jp) <= P_TOP["r_t"] + 1.0
    Yh = (np.arange(shp[0])[:, None] + 0.5) / HR
    Xh = (np.arange(shp[1])[None, :] + 0.5) / HR
    inzone = (Xh >= zone[0]) & (Xh < zone[2]) & (Yh >= zone[1]) & (Yh < zone[3])
    B_dx = B & ~(O_jp & (Yh >= P_TOP["y_cut"]) & inzone)
    # smooth the cut edge (round off the steps left by the removed outlines)
    sm = ndi.gaussian_filter(l2.sdf(B_dx), HR * 1.2) > 0
    low = inzone & (Yh >= P_TOP["y_cut"] - 3)
    B_dx = np.where(low, sm & B, B_dx)
    syl = kr_text()
    T_kr, (tx0, tx1) = place_text(syl, P_TOP["scale"], P_TOP["track"], cx, P_TOP["top"], shp)
    print("KR text x", round(tx0, 1), round(tx1, 1))
    O_kr = l2.dist_out(T_kr) <= P_TOP["r_t"]
    B_new = B_dx | O_kr
    # hi-res composition: original pixels inside the DX body, JP text faces painted navy,
    # Korean text = white face + navy outline, glow outside (model) near the change
    orig_hr = np.kron(a[..., :3], np.ones((HR, HR, 1)))
    # JP faces incl. their anti-aliased rim: pale grey/blue pixels around the text (the DX faces in
    # the zone are saturated red/orange and are not touched)
    rgb1 = a[..., :3]
    pale = ((rgb1.max(2) - rgb1.min(2)) < 90) & (np.abs(rgb1 - NAVY).sum(2) > 24) & body1
    near_jp = ndi.binary_dilation(cov_jp > 0.3, iterations=2) & pale
    near_jp[196:202, 278:286] = False
    jp_face = (l2.dist_out(T_jp) <= 0.75) | l2.kron(near_jp)
    rgb = orig_hr.copy()
    rgb[(jp_face & inzone) | O_kr] = NAVY
    rgb[T_kr] = 255.0
    BB = B_new | T_kr
    cb = l2.down(BB.astype(float))
    body_rgb = l2.down(rgb * BB[..., None]) / np.maximum(cb, 1e-6)[..., None]
    ga = M.glow_alpha(BB)
    A = cb + (1 - cb) * ga
    pmrgb = cb[..., None] * body_rgb + ((1 - cb) * ga)[..., None] * 255.0
    new = np.concatenate([np.where(A[..., None] > 0, pmrgb / np.maximum(A, 1e-6)[..., None], 255),
                          (A * 255)[..., None]], 2)
    # body pixels that did not change stay exactly original; the glow is re-rendered only near the
    # change (blend over 4 px at the edge of its reach)
    changed = l2.down((B_new ^ B).astype(float)) > 0
    changed |= l2.down(((T_kr | jp_face) & inzone).astype(float)) > 0
    near = ndi.distance_transform_edt(~changed)
    w = np.clip(1 - (near - 10) / 4, 0, 1)
    body_same = (l2.down(BB.astype(float)) >= 1) & (l2.down(B.astype(float)) >= 1) & ~changed
    w[body_same & (near > 2)] = 0
    zone1 = np.zeros((H1, W1), bool)
    zone1[zone[1] - 6:zone[3] + 14, zone[0] - 14:zone[2] + 14] = True
    w = (w * zone1)[..., None]
    pa = np.concatenate([a[..., :3] * a[..., 3:] / 255, a[..., 3:]], 2)
    pn = np.concatenate([new[..., :3] * new[..., 3:] / 255, new[..., 3:]], 2)
    pm = pa * (1 - w) + pn * w
    Af = pm[..., 3:]
    res = np.concatenate([np.where(Af > 0, pm[..., :3] * 255 / np.maximum(Af, 1e-6), 255), Af], 2)
    # check: glow model vs original alpha on the untouched part of this layer
    gm = M.glow_alpha(B | T_jp)
    o = ~body1 & (a[..., 3] > 0) & zone1 & ~(w[..., 0] > 0)
    if o.any():
        print("glow model check (untouched zone px): mean |alpha err| =",
              round(float(np.abs(gm[o] * 255 - a[..., 3][o]).mean()), 2))
    l2.save(res, l2.HERE / "steps/top_unquantised.png")
    q = l2.q4(res)
    l2.save(q, l2.HERE / "out/title_logo_JP_top.png")


if __name__ == "__main__":
    main()
