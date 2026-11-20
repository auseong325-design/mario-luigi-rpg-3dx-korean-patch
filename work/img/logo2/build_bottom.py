"""Korean title logo, bottom layer (title_logo_JP_bottom, 512x256 RGBA4): 「마리오&루이지」 + original RPG.

glyphs     1DX Korean logo syllables (fit/kr_syllables.npz), sx 0.72 / sy 0.94 (sy = 1DX ratio of the
           small letters to RPG), packed with the Japanese face gaps (1.75 px in a word)
material   model.py fitted on the Japanese original (fit_jp.py): face row gradients, gloss crescent,
           rim, navy outline, swept extrusion with per-word row colours, blurred outer glow
kept       & (Japanese pixels, moved), RPG and everything right of it (original pixels),
           Mario / Luigi silhouettes (original shapes, standing on the 마 / 루 heads)
"""
from __future__ import annotations

import json
import sys

import numpy as np
from scipy import ndimage as ndi

import l2
import layout
import model as M

HR = l2.HR
P_LAY = dict(sx=None, sy=0.94, base=127.5, x_left=44.0, gap=1.75, gap_amp=2.5,
             grow=0.6,              # 1DX strokes scaled 0.72 are ~17 % thinner than the Japanese ones
             x_right=273.75,        # last face column before R (Japanese ジ ends at 274)
             seam=(283.0, 291.0),   # blend to the original inside R's face
             band_jp=(79.0, 128.0),  # rows of the Japanese letters (face gradient band)
             head_light={1: 0.25, 3: 0.0})  # 마 head up to 25 % lighter at the top (루 is pale already)
if len(sys.argv) > 1:
    P_LAY.update(json.loads(sys.argv[1]))
OUT = l2.HERE / "out"
STEPS = l2.HERE / "steps"


def jp_inputs():
    a = l2.load(l2.JP_DIR / "title_logo_JP_bottom.png")
    z = np.load(l2.HERE / "fit/jp_bottom.npz")
    F = {g: z[f"F{g}"] for g in range(1, 7)}
    st = {"face": {g: z[f"face{g}"] for g in range(1, 7)}, "ext": {g: z[f"ext{g}"] for g in range(1, 7)},
          "rim": {g: z[f"rim{g}"] for g in (1, 3, 4, 5, 6)}}
    return a, F, st, z["sil"]


def local(mask_hr):
    """crop a global hi-res mask to its columns (rows stay global) -> (local mask, x0 hi-res)."""
    cols = np.nonzero(mask_hr.any(0))[0]
    x0 = max(cols.min() - 8 * HR, 0)
    return mask_hr[:, x0:cols.max() + 8 * HR], x0


def build_masks(F_jp, shape_hr):
    S = np.load(l2.HERE / "fit/kr_syllables.npz")
    sy, base = P_LAY["sy"], P_LAY["base"]
    amp_loc, amp_x0 = local(F_jp[2])
    order = ["ma", "ri", "o", "amp", "ru", "i", "ji"]
    g = P_LAY["gap"]
    kern = [0, 0, 0, P_LAY["gap_amp"] - g, P_LAY["gap_amp"] - g, 0, 0]

    def trial(sx):
        syl = {k: layout.syllable_mask(S[k], sx, sy, base, grow=P_LAY["grow"])
               for k in ("ma", "ri", "o", "ru", "i", "ji")}
        masks = [syl[k] if k != "amp" else amp_loc for k in order]
        offs, U = layout.pack(masks, *shape_hr, P_LAY["x_left"], g, kerns=kern)
        right = (np.nonzero(U.any(0))[0].max() + 1) / HR
        return right, masks, offs

    if P_LAY["sx"]:
        sx = P_LAY["sx"]
        right, masks, offs = trial(sx)
    else:                      # widest letters whose line still ends before R
        sx = 0.74
        while True:
            right, masks, offs = trial(sx)
            if right <= P_LAY["x_right"] or sx < 0.6:
                break
            sx = round(sx - 0.005, 3)
    print(f"layout: sx {sx}  sy {sy}  right edge {right:.2f}")
    placed = {k: layout.place(m, o, *shape_hr) for k, m, o in zip(order, masks, offs)}
    amp_dx = offs[3] - amp_x0            # hi-res shift of the & (from its Japanese place)
    return placed, amp_dx


def blob_top(mask_hr, x_from, x_to):
    """(x, y) hi-res of the highest face point of a word between columns x_from..x_to (1x)."""
    sub = mask_hr[:, int(x_from * HR):int(x_to * HR)]
    rows = np.where(sub.any(0), sub.argmax(0), 10 ** 6)
    c = int(np.argmin(rows))
    # centre of the flat top (columns within 0.5 px of the top)
    flat = np.nonzero(rows <= rows[c] + HR // 2)[0]
    return int(x_from * HR) + int(flat.mean()), int(rows[c])


def move_silhouettes(sil_jp, O_jp, F_kr, O_kr, targets):
    """Shift each silhouette so its feet stand on the Korean outline as deep as on the Japanese one.
    targets: [(x_hr of the word's head)] left-to-right silhouettes (Mario, Luigi)."""
    lab, n = ndi.label(sil_jp)
    comps = sorted(range(1, n + 1), key=lambda i: np.nonzero(lab == i)[1].mean())
    out = np.zeros_like(sil_jp)
    moves = []
    for i, tx in zip(comps, targets):
        m = lab == i
        ys, xs = np.nonzero(m)
        foot_y = ys.max()
        fx = int(xs[ys >= foot_y - 2 * HR].mean())
        top_jp = np.nonzero(O_jp[:, fx])[0].min()
        depth = foot_y - top_jp
        top_kr = np.nonzero(O_kr[:, tx])[0].min()
        dy = top_kr + depth - foot_y
        dx = tx - fx
        out |= l2.shift_hr(m, dx, dy)
        moves.append((dx / HR, dy / HR))
    return out, moves


def main():
    a, F_jp, st, sil_jp = jp_inputs()
    H1, W1 = a.shape[:2]
    shp = (H1 * HR, W1 * HR)
    P = M.Params()
    placed, amp_dx = build_masks(F_jp, shp)
    F = {1: placed["ma"] | placed["ri"] | placed["o"], 2: placed["amp"],
         3: placed["ru"] | placed["i"] | placed["ji"], 4: F_jp[4], 5: F_jp[5], 6: F_jp[6]}
    # silhouettes on the 마 / 루 heads
    O_jp = l2.dist_out(np.any([F_jp[g] for g in F_jp], 0)) <= P.r_o
    Fall = np.any([F[g] for g in F], 0)
    O_kr = l2.dist_out(Fall) <= P.r_o
    cols = np.nonzero(placed["ma"].any(0))[0]
    mx, _ = blob_top(placed["ma"], cols.min() / HR, cols.max() / HR)
    cols = np.nonzero(placed["ru"].any(0))[0]
    lx, _ = blob_top(placed["ru"], cols.min() / HR, cols.max() / HR)
    sil, moves = move_silhouettes(sil_jp, O_jp, Fall, O_kr, [mx, lx])
    print("silhouette moves (1x px):", moves, " & dx:", amp_dx / HR)
    # face gradient: the Japanese band (79..128) mapped onto the Korean small letters
    small = placed["ri"] | placed["o"] | placed["i"] | placed["ji"]
    top_small = np.median([np.nonzero(placed[k].any(1))[0].min() for k in ("ri", "i", "ji")]) / HR
    y0j, y1j = P_LAY["band_jp"]
    ys = np.arange(H1, dtype=float)
    src = y0j + (ys - top_small) * (y1j - y0j) / (P_LAY["base"] - top_small)
    src = np.clip(src, 0, H1 - 1)
    style = {"face": dict(st["face"]), "ext": dict(st["ext"]), "rim": dict(st["rim"])}
    head_top = min(np.nonzero(placed[k].any(1))[0].min() for k in ("ma", "ru")) / HR
    t = np.clip((top_small - ys) / max(top_small - head_top, 1), 0, 1)
    for g in (1, 3):
        tab = st["face"][g]
        f = np.stack([np.interp(src, np.arange(H1), tab[:, c]) for c in range(3)], 1)
        style["face"][g] = f + (255 - f) * (P_LAY["head_light"][g] * t)[:, None]
    amp_rgb = np.kron(np.roll(a[..., :3], amp_dx // HR, axis=1), np.ones((HR, HR, 1)))
    out, geo = M.render(F, P, style, extra_body=sil, face_override={2: (amp_rgb, F[2])})
    l2.save(out, STEPS / "bottom_1_model.png")
    # & : original pixels (moved) wherever its face covers the pixel
    amp1 = l2.down(placed["amp"].astype(float)) > 0
    sh = np.roll(a, amp_dx // HR, axis=1)
    out[amp1] = sh[amp1]
    # right part: original, blended inside R's face
    x = np.arange(W1)
    s0, s1 = P_LAY["seam"]
    w = np.clip((x - s0) / (s1 - s0), 0, 1)[None, :, None]
    pa = np.concatenate([a[..., :3] * a[..., 3:] / 255, a[..., 3:]], 2)
    po = np.concatenate([out[..., :3] * out[..., 3:] / 255, out[..., 3:]], 2)
    pm = po * (1 - w) + pa * w
    A = pm[..., 3:]
    res = np.concatenate([np.where(A > 0, pm[..., :3] * 255 / np.maximum(A, 1e-6), 255), A], 2)
    l2.save(res, STEPS / "bottom_2_unquantised.png")
    q = l2.q4(res)
    l2.save(q, OUT / "title_logo_JP_bottom.png")
    ys_, xs_ = np.nonzero(q[..., 3] > 0)
    print("bbox x", xs_.min(), xs_.max(), "y", ys_.min(), ys_.max())
    np.savez_compressed(l2.HERE / "fit/kr_bottom_layout.npz", Fma=F[1], Flu=F[3], Famp=F[2], sil=sil,
                        amp_dx=amp_dx, top_small=top_small)


if __name__ == "__main__":
    main()
