"""Alpha (tone) histograms: share of ink pixels that are full (15) vs partial (1..14), per glyph class."""
from __future__ import annotations

import sys
from pathlib import Path

import numpy as np

sys.path.insert(0, str(Path(__file__).resolve().parent))
from render import ROOT, get_font  # noqa: E402

CLASSES = {"latin": "ABDEHKLMNOPRSUWXacemnorsuw", "digits": "0123456789",
           "hangul": "가나다라마바사아자차카타파하부츠글러브양말팔찌이빨버섯회복증",
           "kana": "あいうえおかきくけこアイウエオカキクケコブーツ"}


def main():
    out = []
    for k in ["jp:font", "ko:font", "1dx:font", "1dx:font_sys", "jp:font_btl", "ko:font_btl", "1dx:font_btl",
              "1dx:font_sys_btl", "jp:font_l", "ko:font_l", "1dx:font_l"]:
        f = get_font(k)
        for cl, chars in CLASSES.items():
            vals = []
            for ch in chars:
                if f.has(ch):
                    cell = (f.glyph(ord(ch))[0] * 15).round().astype(int)
                    vals.append(cell[cell > 0])
            if not vals:
                continue
            v = np.concatenate(vals)
            full = (v == 15).mean()
            mid = ((v > 0) & (v < 15)).mean()
            out.append(f"{k:17s} {cl:7s} ink px {len(v):5d}  full(15) {full:5.1%}  partial {mid:5.1%}  mean {v.mean():5.2f}")
    txt = "\n".join(out)
    (ROOT / "work/review/menu_fonts_20261030/tone.txt").write_text(txt, "utf-8")
    print(txt)


if __name__ == "__main__":
    main()
