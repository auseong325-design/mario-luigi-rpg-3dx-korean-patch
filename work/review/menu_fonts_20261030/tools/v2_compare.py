"""FONT2: compare spacing candidates on the strings the lead flagged (offline render, 1x shown 3x).
Rows per string: JP original | KO shipped | v1 (1DX CWDH) | each candidate table (v2_spacing*.json applied to
the v1 font in memory). Writes sheets/v2_candidates_<font>_*.png (<= 1590 px per side).
Usage: v2_compare.py [mode ...]   (modes: optical jpchar box stem fit; default all)"""
from __future__ import annotations

import json
import sys
from pathlib import Path

import numpy as np
from PIL import Image

sys.path.insert(0, str(Path(__file__).resolve().parent))
from render import ROOT, Font, Sheet, draw_text, get_font  # noqa: E402
import libbffnt as L  # noqa: E402

STAGE = ROOT / "work/build/menu_font_stage"
V1 = STAGE / "romfs/Msg/JP_ja"
OUT = ROOT / "work/review/menu_fonts_20261030/sheets"
LIST_BG, LIST_FG = (0x0E, 0x4C, 0x8C), (0xF0, 0xF0, 0xF0)
DESC_BG, DESC_FG = (0xF4, 0xF4, 0xF4), (0x37, 0x37, 0x37)
ROWS = {
    "font": ["Item#671", "Item#362", "Item#342", "Item#193", "Item#791", "Item#557", "Item#172", "Menu#665",
             "Menu#38", "FMsg/i_areanone_puzzle_01_U#12", "Menu#462"],
    "font_btl": ["Item#754", "Item#13", "Item#20", "Item#81", "Item#193", "Item#42", "BMsg/b_sys#95", "Menu#108"],
}


def apply_table(name: str, table_path: Path) -> Font:
    f = L.parse((V1 / f"{name}.bffnt").read_bytes())
    t = json.loads(table_path.read_text("utf-8"))["fonts"][name]["chars"]
    cmap = f.char_map()
    for ch, row in t.items():
        g = cmap[ord(ch)]
        for k, (start, ws) in enumerate(f.cwdh):
            if start <= g < start + len(ws):
                ws[g - start] = L.CharWidth(left=row["cwdh"][0], glyph=row["cwdh"][1], char=row["cwdh"][2])
    return Font(f"{table_path.stem}:{name}", L.build(f))


def colour(alpha, fg, bg):
    a = alpha[..., None]
    img = np.asarray(bg, np.float32) * (1 - a) + np.asarray(fg, np.float32) * a
    return Image.fromarray(np.clip(img, 0, 255).astype(np.uint8), "RGB")


def main():
    modes = sys.argv[1:] or ["optical", "jpchar", "box", "stem", "fit"]
    ko = json.loads((ROOT / "work/ko_final.json").read_text("utf-8"))
    jp = {}
    for f in (ROOT / "text/jp").glob("*.json"):
        for m in json.loads(f.read_text("utf-8"))["messages"]:
            jp[m["id"]] = m["jp"]
    gz = get_font("gaizi")
    for name, ids in ROWS.items():
        fg, bg = (LIST_FG, LIST_BG) if name == "font" else (DESC_FG, DESC_BG)
        v1 = Font(f"v1:{name}", (V1 / f"{name}.bffnt").read_bytes())
        cands = []
        for m in modes:
            p = STAGE / ("v2_spacing.json" if m == "fit" else f"v2_spacing_{m}.json")
            cands.append(("v2 (fit, chosen)" if m == "fit" else m, apply_table(name, p)))
        sh = Sheet(zoom=3, label_w=170)
        for mid in ids:
            k = ko[mid].split("[Next]")[0]
            j = jp[mid].split("[Next]")[0]
            sh.add(f"{mid}", colour(draw_text(get_font(f"jp:{name}"), j, icon_font=gz)[0], fg, bg), "JP original")
            sh.add("  shipped", colour(draw_text(get_font(f"ko:{name}"), k, icon_font=gz)[0], fg, bg))
            sh.add("  v1 (1DX CWDH)", colour(draw_text(v1, k, icon_font=gz)[0], fg, bg))
            for m, fo in cands:
                sh.add(f"  {m}", colour(draw_text(fo, k, icon_font=gz)[0], fg, bg))
        outs = sh.save(OUT / f"v2_candidates_{name}.png", max_side=1590)
        print("\n".join(str(o) for o in outs))


if __name__ == "__main__":
    main()
