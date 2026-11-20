"""Ink metrics of Latin / digits / Hangul / kana in the 3DX JP, 3DX KO and 1DX KR fonts (FONT worker).

Per class: median ink top/bottom relative to the baseline (rows above baseline = positive), ink width,
advance, and a stroke-width estimate (2 * ink area / ink perimeter, alpha >= 8 of 15).
Writes metrics.txt.
"""
from __future__ import annotations

import sys
from pathlib import Path

import numpy as np

sys.path.insert(0, str(Path(__file__).resolve().parent))
from render import ROOT, get_font  # noqa: E402

CLASSES = {
    "caps": "ABCDEFGHIJKLMNOPRSTUVWXYZ",
    "lower_x": "acemnorsuvwxz",
    "digits": "0123456789",
    "hangul": "가나다라마바사아자차카타파하부츠글러브양말팔찌이빨버섯회복증마리오루지",
    "kana": "あいうえおかきくけこアイウエオカキクケコブーツグロ",
}


def ink_stats(font, chars):
    tops, bots, wids, advs, strokes, lefts = [], [], [], [], [], []
    for ch in chars:
        if not font.has(ch):
            continue
        cell, left, gw, adv, _ = font.glyph(ord(ch))
        m = cell >= 8 / 15
        if not m.any():
            continue
        ys = np.nonzero(m.any(axis=1))[0]
        xs = np.nonzero(m.any(axis=0))[0]
        base = font.f.baseline
        tops.append(base - ys[0])          # rows above the baseline row (incl.)
        bots.append(base - ys[-1])
        wids.append(xs[-1] - xs[0] + 1)
        lefts.append(left + xs[0])
        advs.append(adv)
        a = m.sum()
        pad = np.pad(m, 1)
        per = (pad[1:-1, 1:-1] & ~pad[:-2, 1:-1]).sum() + (pad[1:-1, 1:-1] & ~pad[2:, 1:-1]).sum() + \
              (pad[1:-1, 1:-1] & ~pad[1:-1, :-2]).sum() + (pad[1:-1, 1:-1] & ~pad[1:-1, 2:]).sum()
        strokes.append(2 * a / max(per, 1) * 2)
    if not tops:
        return None
    med = lambda v: float(np.median(v))  # noqa: E731
    return {"n": len(tops), "top": med(tops), "bot": med(bots), "h": med(np.array(tops) - np.array(bots) + 1),
            "w": med(wids), "adv": med(advs), "stroke": round(med(strokes), 2), "lead": med(lefts)}


def main():
    groups = [("font (18px family)", ["jp:font", "ko:font", "st:font", "1dx:font", "1dx:font_sys"]),
              ("font_btl (12px family)", ["jp:font_btl", "ko:font_btl", "st:font_btl", "1dx:font_btl",
                                          "1dx:font_sys_btl"]),
              ("font_l (24px family)", ["jp:font_l", "ko:font_l", "1dx:font_l"])]
    out = []
    for title, keys in groups:
        out.append(f"## {title}")
        out.append(f"{'font':16s} {'class':8s} {'n':>3s} {'top':>5s} {'bot':>5s} {'h':>5s} {'w':>5s} {'adv':>5s} {'stroke':>6s} {'lead':>5s}")
        for k in keys:
            f = get_font(k)
            for cl, chars in CLASSES.items():
                s = ink_stats(f, chars)
                if s:
                    out.append(f"{k:16s} {cl:8s} {s['n']:3d} {s['top']:5.1f} {s['bot']:5.1f} {s['h']:5.1f} {s['w']:5.1f} "
                               f"{s['adv']:5.1f} {s['stroke']:6.2f} {s['lead']:5.1f}")
        out.append("")
    txt = "\n".join(out)
    (ROOT / "work/review/menu_fonts_20261030/metrics.txt").write_text(txt, "utf-8")
    print(txt)


if __name__ == "__main__":
    main()
