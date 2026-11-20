"""Can the 1DX Latin/digit glyphs sit on the 3DX advances? Per ASCII char: 1DX ink width vs 3DX advance
(FONT worker). Writes fit_check.txt."""
from __future__ import annotations

import sys
from pathlib import Path

import numpy as np

sys.path.insert(0, str(Path(__file__).resolve().parent))
from render import ROOT, get_font  # noqa: E402

PAIRS = [("ko:font", "1dx:font"), ("ko:font_btl", "1dx:font_btl"), ("ko:font_l", "1dx:font_l"),
         ("ko:font", "1dx:font_sys"), ("ko:font_btl", "1dx:font_sys_btl")]
CHARS = [chr(c) for c in range(0x21, 0x7F)]


def ink(font, ch):
    cell, left, gw, adv, miss = font.glyph(ord(ch))
    if miss:
        return None
    m = cell > 0
    xs = np.nonzero(m.any(axis=0))[0]
    ys = np.nonzero(m.any(axis=1))[0]
    if not len(xs):
        return {"w": 0, "adv": adv, "left": left, "x0": 0, "y0": 0, "y1": 0}
    return {"w": int(xs[-1] - xs[0] + 1), "adv": adv, "left": left, "x0": int(xs[0]),
            "y0": int(font.f.baseline - ys[0]), "y1": int(font.f.baseline - ys[-1])}


def main():
    out = []
    for k3, k1 in PAIRS:
        f3, f1 = get_font(k3), get_font(k1)
        out.append(f"## 3DX {k3} advances vs {k1} ink (fits = 1DX ink <= 3DX adv - 1)")
        bad = []
        rows = []
        for ch in CHARS:
            a, b = ink(f3, ch), ink(f1, ch)
            if a is None or b is None:
                rows.append(f"{ch!r}: 3dx={a is not None} 1dx={b is not None}")
                continue
            fits = b["w"] <= a["adv"] - 1
            if not fits:
                bad.append(ch)
            rows.append(f"{ch!r}: 3dx adv {a['adv']:2d} ink {a['w']:2d} | 1dx adv {b['adv']:2d} ink {b['w']:2d} "
                        f"rows {b['y0']}..{b['y1']} (3dx {a['y0']}..{a['y1']}) {'ok' if fits else 'WIDE'}")
        out.append("too wide: " + "".join(bad))
        out.extend("  " + r for r in rows)
        out.append("")
    txt = "\n".join(out)
    (ROOT / "work/review/menu_fonts_20261030/fit_check.txt").write_text(txt, "utf-8")
    print("\n".join(l for l in out if l.startswith("##") or l.startswith("too wide")))


if __name__ == "__main__":
    main()
