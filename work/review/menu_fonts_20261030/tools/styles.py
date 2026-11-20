"""Style (leading [0009:0000:XX] tag / TSY1) -> font, per label family, for Item/Menu/MenuKJ (read-only)."""
from __future__ import annotations

import json
import re
import sys
from collections import Counter, defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[4]

# MessageSimple::GetFont (static 0x270fd4) and the copy inlined in UIListWindowPlusLyt::drawListStr (0x1437bc)
FONT_IDX = {0: 2, 5: 2, 8: 2, 1: 1, 6: 1, 9: 1, 2: 0, 7: 0, 10: 0, 3: 4, 11: 4}
FONT_NAME = {0: "font_l", 1: "font", 2: "font_btl", 3: "font(copy#3)", 4: "font_btl(copy#4)"}


def font_of(style: int, list_draw: bool) -> str:
    """MessageSimple::play keeps the caller's font for style 13 and 255 (0x275444); list drawing maps 13 -> 3."""
    if style in (13, 255) and not list_draw:
        return "caller default (init=3 font)"
    return FONT_NAME[FONT_IDX.get(style, 3)]


def family(label: str) -> str:
    m = re.match(r"([A-Za-z]+_?[A-Za-z]*?)(?:_|\d|$)", label)
    parts = label.split("_")
    return "_".join(parts[:2]) if len(parts) > 2 else parts[0]


def main():
    ko = json.loads((ROOT / "work/ko_final.json").read_text("utf-8"))
    out = []
    for src in ("Item", "Menu", "MenuKJ"):
        d = json.loads((ROOT / f"text/jp/{src}.json").read_text("utf-8"))
        fam: dict[tuple[str, int], list] = defaultdict(list)
        for m in d["messages"]:
            st = m["style"]
            tag = re.match(r"\[0009:0000:([0-9A-F]{2}) 00\]", m["jp"])
            tst = int(tag.group(1), 16) if tag else None
            fam[(family(m["label"]), st)].append((m["id"], m["label"], tst))
        out.append(f"== {src}: {len(d['messages'])} messages")
        for (f, st), items in sorted(fam.items(), key=lambda kv: (kv[0][1], kv[0][0])):
            mism = sum(1 for _, _, t in items if t != st)
            ex = items[0]
            kot = ko.get(ex[0], "")
            out.append(f"style {st:3d} -> play:{font_of(st, False):28s} list:{font_of(st, True):18s} "
                       f"{f:34s} n={len(items):4d} tag!=style:{mism}  e.g. {ex[1]} | {kot[:60]!r}")
    txt = "\n".join(out)
    (ROOT / "work/review/menu_fonts_20261030/styles.txt").write_text(txt, "utf-8")
    print(txt)


if __name__ == "__main__":
    main()
