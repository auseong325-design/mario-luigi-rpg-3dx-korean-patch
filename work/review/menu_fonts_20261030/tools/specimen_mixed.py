"""Mixed Latin + Hangul specimens: shipped KO fonts vs JP original vs 1DX KR (FONT worker, offline)."""
from __future__ import annotations

import json
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from render import ROOT, Sheet, draw_text, get_font, to_rgba  # noqa: E402

OUT = ROOT / "work/review/menu_fonts_20261030/sheets"
IDS_NAME = ["Item#362", "Item#342", "Item#193", "Item#455", "Item#791", "Item#557"]
IDS_DESC = ["Item#754", "Item#1", "Item#20", "Item#13"]


def main():
    OUT.mkdir(parents=True, exist_ok=True)
    ko = json.loads((ROOT / "work/ko_final.json").read_text("utf-8"))
    jp = {m["id"]: m["jp"] for m in json.loads((ROOT / "text/jp/Item.json").read_text("utf-8"))["messages"]}
    gz = get_font("gaizi")
    sh = Sheet(zoom=3, label_w=250)
    for mid in IDS_NAME:
        sh.add(f"{mid} JP  3DX font", to_rgba(draw_text(get_font("jp:font"), jp[mid], icon_font=gz)[0]))
        for key in ("ko:font", "1dx:font", "1dx:font_sys"):
            sh.add(f"{mid} KO  {key}", to_rgba(draw_text(get_font(key), ko[mid], icon_font=gz)[0]))
    sh.save(OUT / "mixed_names_font.png")
    sh = Sheet(zoom=3, label_w=250)
    for mid in IDS_DESC:
        sh.add(f"{mid} JP  3DX font_btl", to_rgba(draw_text(get_font("jp:font_btl"), jp[mid], icon_font=gz)[0]))
        for key in ("ko:font_btl", "1dx:font_btl", "1dx:font_sys_btl"):
            sh.add(f"{mid} KO  {key}", to_rgba(draw_text(get_font(key), ko[mid], icon_font=gz)[0]))
    sh.save(OUT / "mixed_desc_font_btl.png")


if __name__ == "__main__":
    main()
