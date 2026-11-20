"""Non-Hangul characters the Korean text uses: count, where the shipped glyph comes from (3DX original or
1DX via build_font), presence in the 1DX donor, advances (FONT worker). Writes charuse.txt."""
from __future__ import annotations

import json
import re
import sys
from collections import Counter
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from render import ROOT, get_font, visible  # noqa: E402


def main():
    ko = json.loads((ROOT / "work/ko_final.json").read_text("utf-8"))
    c = Counter()
    for t in ko.values():
        v = re.sub(r"[\uE000-\uF8FF]", "", visible(t))
        c.update(ch for ch in v if ch not in "\n" and not (0xAC00 <= ord(ch) <= 0xD7A3))
    out = []
    for name in ("font", "font_btl", "font_l"):
        jp, kof, dx = get_font(f"jp:{name}"), get_font(f"ko:{name}"), get_font(f"1dx:{name}")
        out.append(f"## {name}")
        for ch, n in c.most_common():
            src = "3DX" if jp.has(ch) else ("added" if kof.has(ch) else "MISSING")
            a3 = kof.glyph(ord(ch))[3] if kof.has(ch) else None
            a1 = dx.glyph(ord(ch))[3] if dx.has(ch) else None
            out.append(f"  {ch!r:6s} U+{ord(ch):04X} x{n:6d}  shipped={src:7s} adv={a3}  1dx={'yes' if a1 is not None else 'no'} adv1={a1}")
    txt = "\n".join(out)
    (ROOT / "work/review/menu_fonts_20261030/charuse.txt").write_text(txt, "utf-8")
    print("\n".join(out[:75]))


if __name__ == "__main__":
    main()
