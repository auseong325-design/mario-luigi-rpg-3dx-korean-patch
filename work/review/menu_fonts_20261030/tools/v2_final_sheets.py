"""FONT2: before/after sheets for the v2 build (offline render with the real font files, 1x shown 3x/4x).
  sheets/v2_final_<n>.png    strings of the RT5 menu screens + dialogue: JP original | KO shipped | KO v1 | KO v2
  sheets/v2_specimen_<font>_<n>.png   digits / letter pairs / names: JP 3DX | KO v1 | KO v2
Every page <= 1590 px per side (Sheet.save splits)."""
from __future__ import annotations

import json
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from final_sheets import DESC_BG, DESC_FG, DLG_BG, DLG_FG, LIST_BG, LIST_FG, colour, first_page  # noqa: E402
from render import ROOT, Font, Sheet, draw_text, get_font  # noqa: E402

OUT = ROOT / "work/review/menu_fonts_20261030/sheets"
V1 = ROOT / "work/build/menu_font_stage/romfs/Msg/JP_ja"
V2 = ROOT / "work/build/menu_font_stage/v2/romfs/Msg/JP_ja"
ROWS = [
    ("Item#362", "font", "list"), ("Item#342", "font", "list"), ("Item#193", "font", "list"),
    ("Item#791", "font", "list"), ("Item#557", "font", "list"), ("Item#172", "font", "list"),
    ("Menu#462", "font", "list"), ("Menu#665", "font", "list"),
    ("Item#754", "font_btl", "desc"), ("Item#13", "font_btl", "desc"), ("Item#20", "font_btl", "desc"),
    ("Item#81", "font_btl", "desc"), ("Item#42", "font_btl", "desc"), ("Item#193", "font_btl", "desc"),
    ("Item#362", "font_btl", "desc"), ("BMsg/b_sys#95", "font_btl", "desc"), ("Menu#108", "font_btl", "desc"),
    ("FMsg/o_peach_1f_01#10", "font", "dlg"), ("FMsg/o_mushiba_24#13", "font", "dlg"),
    ("FMsg/i_areanone_puzzle_01_U#12", "font", "dlg"),
]
SPECIMEN = ["0123456789  1152  2017  100  999", "HP 291/291  SP 116/116  LV99", "POW부츠DX  POW글러브DX  1UP버섯DX",
            "EX배지링  파워팔찌SP  HP양말DX FULL!", "Excellent 횟수  The Winner is… DX", "비삐더스X LV100  퍼즐피스2",
            "Illinois  AV AW LT TY Yo  rn m cl d"]


def main():
    ko = json.loads((ROOT / "work/ko_final.json").read_text("utf-8"))
    jp = {}
    for f in (ROOT / "text/jp").glob("*.json"):
        for m in json.loads(f.read_text("utf-8"))["messages"]:
            jp[m["id"]] = m["jp"]
    gz = get_font("gaizi")
    v1 = {n: Font(f"v1:{n}", (V1 / f"{n}.bffnt").read_bytes()) for n in ("font", "font_btl")}
    v2 = {n: Font(f"v2:{n}", (V2 / f"{n}.bffnt").read_bytes()) for n in ("font", "font_btl")}
    pal = {"list": (LIST_FG, LIST_BG), "desc": (DESC_FG, DESC_BG), "dlg": (DLG_FG, DLG_BG)}
    sh = Sheet(zoom=3, label_w=210)
    for mid, fn, kind in ROWS:
        fg, bg = pal[kind]
        k, j = first_page(ko[mid]), first_page(jp[mid])
        sh.add(f"{mid} JP original", colour(draw_text(get_font(f"jp:{fn}"), j, icon_font=gz)[0], fg, bg))
        sh.add(f"  KO shipped ({fn})", colour(draw_text(get_font(f"ko:{fn}"), k, icon_font=gz)[0], fg, bg))
        sh.add(f"  KO v1 ({fn})", colour(draw_text(v1[fn], k, icon_font=gz)[0], fg, bg))
        sh.add(f"  KO v2 ({fn})", colour(draw_text(v2[fn], k, icon_font=gz)[0], fg, bg))
    outs = sh.save(OUT / "v2_final.png", max_side=1590)
    for fn in ("font", "font_btl"):
        sp = Sheet(zoom=4 if fn == "font_btl" else 3, label_w=150)
        for s in SPECIMEN:
            sp.add(f"JP 3DX {fn}", colour(draw_text(get_font(f"jp:{fn}"), s)[0], DESC_FG, DESC_BG))
            sp.add(f"  KO v1", colour(draw_text(v1[fn], s)[0], DESC_FG, DESC_BG))
            sp.add(f"  KO v2", colour(draw_text(v2[fn], s)[0], DESC_FG, DESC_BG))
        outs += sp.save(OUT / f"v2_specimen_{fn}.png", max_side=1590)
    print("\n".join(str(o) for o in outs))


if __name__ == "__main__":
    main()
