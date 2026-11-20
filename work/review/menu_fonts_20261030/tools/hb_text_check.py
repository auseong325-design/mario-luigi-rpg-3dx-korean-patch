"""HugeBattle.msbt lines (drawn by HB layout TextBoxes with font.bffnt) that contain changed glyphs:
width shipped vs staged vs the widest Japanese line of the file (font.bffnt units). FONT worker."""
from __future__ import annotations

import json
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from real_width import adv_table, lines_of  # noqa: E402
from render import ROOT, Font, get_font  # noqa: E402

CH = re.compile(r"[A-Za-z0-9+/=&?.,!:%~()]")


def main():
    gz = get_font("gaizi")
    ship = adv_table(get_font("ko:font"), gz)
    new = adv_table(Font("staged", (ROOT / "work/build/menu_font_stage/romfs/Msg/JP_ja/font.bffnt").read_bytes()), gz)
    jpw = adv_table(get_font("jp:font"), gz)
    ko = json.loads((ROOT / "work/ko_final.json").read_text("utf-8"))
    msgs = json.loads((ROOT / "text/jp/HugeBattle.json").read_text("utf-8"))["messages"]
    jpmax = max((jpw(ln) for m in msgs for ln in lines_of(m["jp"])), default=0)
    n = 0
    for m in msgs:
        for ln in lines_of(ko.get(m["id"], "")):
            if CH.search(ln):
                a, b = ship(ln), new(ln)
                if a != b:
                    n += 1
                    print(f"{m['id']} {m['label']}: {a} -> {b} px (JP widest line {jpmax}): {ln!r}")
    print(f"{n} HugeBattle lines change width")


if __name__ == "__main__":
    main()
