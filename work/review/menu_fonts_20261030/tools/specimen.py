"""Specimen sheets: the same menu strings in every candidate font (FONT worker, offline)."""
from __future__ import annotations

import json
import sys
from pathlib import Path

import numpy as np

sys.path.insert(0, str(Path(__file__).resolve().parent))
from render import ROOT, Sheet, draw_text, get_font, to_rgba  # noqa: E402

OUT = ROOT / "work/review/menu_fonts_20261030/sheets"

KO_IDS = ["Item#9", "Item#3", "Item#4", "Item#0", "Item#13"]


def main():
    OUT.mkdir(parents=True, exist_ok=True)
    ko = json.loads((ROOT / "work/ko_final.json").read_text("utf-8"))
    jp = {}
    for m in json.loads((ROOT / "text/jp/Item.json").read_text("utf-8"))["messages"]:
        jp[m["id"]] = m["jp"]
    sh = Sheet(zoom=3, label_w=230)
    gz = get_font("gaizi")
    for mid in KO_IDS:
        k, j = ko[mid], jp[mid]
        sh.add(f"{mid} JP 3DX font", to_rgba(draw_text(get_font("jp:font"), j, icon_font=gz)[0]))
        sh.add(f"{mid} JP 3DX font_btl", to_rgba(draw_text(get_font("jp:font_btl"), j, icon_font=gz)[0]))
        for key in ("ko:font", "ko:font_btl", "1dx:font", "1dx:font_sys", "1dx:font_btl", "1dx:font_sys_btl"):
            a, info = draw_text(get_font(key), k, icon_font=gz)
            sh.add(f"{mid} KO {key}", to_rgba(a), note=f"missing {''.join(info['missing'])}" if info["missing"] else "")
    outs = sh.save(OUT / "specimen_item_fonts.png")
    print("\n".join(str(o) for o in outs))


if __name__ == "__main__":
    main()
