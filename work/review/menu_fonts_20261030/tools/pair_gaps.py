"""Ink gaps between neighbouring glyphs for every character pair the Korean text uses, for a font variant
(FONT worker). gap = right bearing of the first + left bearing of the second, ink = alpha >= 4/15.
Usage: pair_gaps.py <variant: shipped|v2|v2b> [font|font_btl]"""
from __future__ import annotations

import json
import re
import sys
from collections import Counter
from pathlib import Path

import numpy as np

sys.path.insert(0, str(Path(__file__).resolve().parent))
from menufont import LETTERS_DIGITS, PUNCT, transform  # noqa: E402
from render import ROOT, Font, get_font, visible  # noqa: E402
import libbffnt as L  # noqa: E402


def bearings(font: Font, ch: str, thr: float = 4 / 15):
    cell, left, gw, adv, miss = font.glyph(ord(ch))
    m = cell >= thr
    xs = np.nonzero(m.any(axis=0))[0]
    if not len(xs):
        return None
    lb = left + xs[0]
    rb = adv - (left + xs[-1] + 1)
    return lb, rb


def text_pairs():
    ko = json.loads((ROOT / "work/ko_final.json").read_text("utf-8"))
    c = Counter()
    from real_width import lines_of          # [Next] = page break, icons kept as private-use chars
    for t in ko.values():
        for line in lines_of(t):
            line = re.sub(r"[\uE000-\uF8FF]", "\0", line)
            for a, b in zip(line, line[1:]):
                if a in " \0" or b in " \0":
                    continue
                if (ord(a) < 0x80 or ord(b) < 0x80):
                    c[(a, b)] += 1
    return c


def main():
    var = sys.argv[1] if len(sys.argv) > 1 else "v2"
    name = sys.argv[2] if len(sys.argv) > 2 else "font"
    if var == "shipped":
        font = get_font(f"ko:{name}")
    elif var == "staged":
        font = Font(f"staged:{name}", (ROOT / f"work/build/menu_font_stage/romfs/Msg/JP_ja/{name}.bffnt").read_bytes())
    elif var in ("1dx", "jp"):
        font = get_font(f"{var}:{name}")
    elif var.startswith("dir="):
        font = Font(f"{var}:{name}", (Path(var[4:]) / f"{name}.bffnt").read_bytes())
    else:
        r = transform(name, 0, LETTERS_DIGITS + PUNCT, adv="3dx" if var == "v2" else var)
        font = Font(f"{var}:{name}", L.build(r.font))
    pairs = text_pairs()
    bad = []
    for (a, b), n in pairs.most_common():
        if not (font.has(a) and font.has(b)):
            continue
        ba, bb = bearings(font, a), bearings(font, b)
        if ba is None or bb is None:
            continue
        gap = ba[1] + bb[0]
        if gap <= 0:
            bad.append((n, a, b, gap))
    tot = sum(n for n, *_ in bad)
    print(f"{var} {name}: {len(pairs)} distinct pairs with ASCII; touching/overlapping pairs {len(bad)} "
          f"({tot} occurrences)")
    for n, a, b, g in bad[:40]:
        print(f"  {a}{b} x{n} gap {g}")


if __name__ == "__main__":
    main()
