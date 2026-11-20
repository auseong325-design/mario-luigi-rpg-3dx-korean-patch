"""Before/after sheets for the staged build (FONT worker): the strings of the RT5 menu screens drawn with the
real fonts at 1x (shown 3x nearest): JP original | KO shipped | KO staged | 1DX KR reference.
Writes sheets/final_<tag>_*.png."""
from __future__ import annotations

import json
import sys
from pathlib import Path

import numpy as np
from PIL import Image

sys.path.insert(0, str(Path(__file__).resolve().parent))
from render import ROOT, Font, Sheet, draw_text, get_font  # noqa: E402

OUT = ROOT / "work/review/menu_fonts_20261030/sheets"
STAGE = ROOT / "work/build/menu_font_stage/romfs/Msg/JP_ja"
LIST_BG, LIST_FG = (0x0E, 0x4C, 0x8C), (0xF0, 0xF0, 0xF0)
DESC_BG, DESC_FG = (0xF4, 0xF4, 0xF4), (0x37, 0x37, 0x37)
DLG_BG, DLG_FG = (0xFF, 0xFF, 0xFF), (0x37, 0x37, 0x37)

# (message id, font, colours) - item/gear/badge/stats screens of RT5 + shop notice + guide + dialogue
ROWS = [
    ("Item#671", "font", "list"), ("Item#362", "font", "list"), ("Item#342", "font", "list"),
    ("Item#193", "font", "list"), ("Item#791", "font", "list"), ("Item#557", "font", "list"),
    ("Item#172", "font", "list"),
    ("Item#754", "font_btl", "desc"), ("Item#13", "font_btl", "desc"), ("Item#20", "font_btl", "desc"),
    ("Item#81", "font_btl", "desc"), ("Item#193", "font_btl", "desc"),
    ("Menu#108", "font_btl", "desc"), ("Menu#22", "font_btl", "desc"),
    ("FMsg/o_peach_1f_01#10", "font", "dlg"), ("FMsg/o_mushiba_24#13", "font", "dlg"),
]


def colour(alpha, fg, bg):
    a = alpha[..., None]
    img = np.asarray(bg, np.float32) * (1 - a) + np.asarray(fg, np.float32) * a
    return Image.fromarray(np.clip(img, 0, 255).astype(np.uint8), "RGB")


def first_page(t: str) -> str:
    return t.split("[Next]")[0]


def main():
    tag = sys.argv[1] if len(sys.argv) > 1 else "v1"
    OUT.mkdir(parents=True, exist_ok=True)
    ko = json.loads((ROOT / "work/ko_final.json").read_text("utf-8"))
    jp = {}
    for f in (ROOT / "text/jp").glob("*.json"):
        for m in json.loads(f.read_text("utf-8"))["messages"]:
            jp[m["id"]] = m["jp"]
    gz = get_font("gaizi")
    staged = {n: Font(f"staged:{n}", (STAGE / f"{n}.bffnt").read_bytes()) for n in ("font", "font_btl")}
    pal = {"list": (LIST_FG, LIST_BG), "desc": (DESC_FG, DESC_BG), "dlg": (DLG_FG, DLG_BG)}
    sh = Sheet(zoom=3, label_w=200)
    for mid, fn, kind in ROWS:
        fg, bg = pal[kind]
        k, j = first_page(ko[mid]), first_page(jp[mid])
        sh.add(f"{mid} JP original", colour(draw_text(get_font(f"jp:{fn}"), j, icon_font=gz)[0], fg, bg))
        sh.add(f"  KO shipped ({fn})", colour(draw_text(get_font(f"ko:{fn}"), k, icon_font=gz)[0], fg, bg))
        sh.add(f"  KO staged ({fn})", colour(draw_text(staged[fn], k, icon_font=gz)[0], fg, bg))
    outs = sh.save(OUT / f"final_{tag}.png", max_side=1590)
    print("\n".join(str(o) for o in outs))


if __name__ == "__main__":
    main()
