"""1DX Korean title logo -> soft face coverage of each syllable of 마리오 & 루이지 (glyph skeleton).

The 1DX logo (mg_map_title_logo_KR_ko, ttl_c02_str_KR + _a) has the same construction as the 3DX one:
bright letter faces inside a dark navy outline. Coverage = brightness above the outline navy.
The bean sprout on 지 (1DX theme decoration) is not part of the letter and is dropped.
"""
from __future__ import annotations

import numpy as np
from scipy import ndimage as ndi

import l2

# syllables by the left edge (x0, 1x) of their face components on the 1DX texture:
# 마 = blob 6 + ㅏ 64, 리 = ㄹ 87 + ㅣ 117, 오 133, & 172, 루 = blob 187 + ㅜ 203, 이 = ㅇ 238 + ㅣ 268,
# 지 = ㅈ 287 + ㅣ 320 (R of RPG starts at 343)
SYL = {"ma": (0, 66), "ri": (66, 132), "o": (132, 170), "amp": (170, 186), "ru": (186, 236),
       "i": (236, 284), "ji": (284, 340)}


NAV1DX = np.array([0, 44, 74], float)


def face_cov(a, lo=45.0, hi=140.0, core_thr=150.0):
    """Coverage from the colour distance to the 1DX outline navy (green faces are darker than red)."""
    d = np.sqrt(((a[..., :3] - NAV1DX) ** 2).sum(2)) * (a[..., 3] >= 250)
    cov = np.clip((d - lo) / (hi - lo), 0, 1)
    lab, _ = ndi.label(cov > 0.3)
    keep = np.unique(lab[d >= core_thr])
    keep = keep[keep > 0]
    return cov * np.isin(lab, keep)


def syllables(a=None, fix_stem=True):
    """dict syllable -> soft coverage (full texture size) for the top line (y < 100)."""
    if a is None:
        a = l2.load(l2.KR1DX)
    cov = face_cov(a)
    cov[100:] = 0
    lab, n = ndi.label(cov > 0.3)
    out = {k: np.zeros_like(cov) for k in SYL}
    info = []
    for i, sl in enumerate(ndi.find_objects(lab)):
        m = lab == i + 1
        x0, x1, y0, y1 = sl[1].start, sl[1].stop, sl[0].start, sl[0].stop
        if m.sum() < 6:
            continue
        if x0 >= 312 and y1 <= 42:          # sprout on 지
            info.append(("sprout", x0, x1, y0, y1, int(m.sum())))
            continue
        for k, (a0, a1) in SYL.items():
            if a0 <= x0 < a1:
                grow = ndi.binary_dilation(m, iterations=1)
                out[k] = np.maximum(out[k], cov * grow)
                info.append((k, x0, x1, y0, y1, int(m.sum())))
                break
    if fix_stem:
        out["ji"] = fix_ji_stem(cov, lab, out["ji"])
    return out, info


def _comp(cov, lab, x_from, x_to):
    """soft coverage of the face component whose left edge lies in [x_from, x_to)."""
    for i, sl in enumerate(ndi.find_objects(lab)):
        if x_from <= sl[1].start < x_to and sl[0].stop <= 100:
            return cov * ndi.binary_dilation(lab == i + 1, iterations=1)
    raise KeyError((x_from, x_to))


def fix_ji_stem(cov, lab, ji, cut=51, blend=(51, 57)):
    """The ㅣ of 지 carried the bean sprout in 1DX; without it its top is a chopped stump with a
    notch. Give it the round, slightly bulbous head every other ㅣ of the logo has (이 / 리, and the
    지 of the later Korean M&L logos): the head of 이's ㅣ, moved onto the centre of 지's stem
    (stem centres measured on rows 58-64), joined to 지's own stem below `cut`."""
    stem_ji = _comp(cov, lab, 318, 330)
    stem_i = _comp(cov, lab, 266, 275)
    ys = np.arange(cov.shape[0])[:, None]
    xs = np.arange(cov.shape[1])[None, :]

    def centre(m):
        w = m[58:65]
        return float((w * xs).sum() / w.sum())

    dx = centre(stem_ji) - centre(stem_i)
    head = ndi.shift(stem_i, (0, dx), order=1, mode="constant")
    head = np.where(ys < blend[1], head, 0)
    # join: above `cut` the head only, in the blend band the union, below 지's own stem
    t = np.clip((ys - blend[0]) / (blend[1] - blend[0]), 0, 1)
    new_stem = np.where(ys < cut, head, np.maximum(head * (1 - t), stem_ji))
    near = ndi.binary_dilation(stem_ji > 0.05, iterations=3) | (head > 0.05)
    return np.where(near, np.maximum(ji * ~(ndi.binary_dilation(stem_ji > 0.05, iterations=1)), new_stem), ji)


if __name__ == "__main__":
    out, info = syllables()
    for r in info:
        print(r)
    np.savez_compressed(l2.HERE / "fit/kr_syllables.npz", **out)
    print("wrote fit/kr_syllables.npz")
