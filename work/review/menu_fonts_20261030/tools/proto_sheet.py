"""Prototype comparison: shipped KO fonts vs unification variants vs JP original vs 1DX (FONT worker).

V0 shipped | V1 Hangul on the 1DX baseline arrangement (moved down 1 px) | V2 V1 + 1DX ASCII on 3DX advances |
V3 V1 + 1DX ASCII with 1DX advances. Text colours as in the menus: list/slot names white on the list blue,
descriptions #373737 on the panel white. 1x pixels, shown 3x nearest.
"""
from __future__ import annotations

import sys
from pathlib import Path

import numpy as np
from PIL import Image

sys.path.insert(0, str(Path(__file__).resolve().parent))
from menufont import LETTERS_DIGITS, PUNCT, transform  # noqa: E402
from render import ROOT, Font, Sheet, draw_text, get_font  # noqa: E402
import libbffnt as L  # noqa: E402  (scripts/ is on sys.path after the imports above)

OUT = ROOT / "work/review/menu_fonts_20261030/sheets"
NAMES = [("POW부츠DX", "POWブーツDX"), ("파워팔찌SP", "パワーうでわSP"), ("1UP버섯DX", "１UPキノコDX"),
         ("EX배지링", "EXバッジリング"), ("HP양말DX FULL!", "HPソックスDXはいっぱいです！"), ("퍼펙트웨어", "カンペキウェア")]
DESCS = [("POW가 증가하는 부츠.", "POWがアップするブーツ。"), ("HP를 50 회복.", "HPが ５０回復。"),
         ("배틀 종료 시 획득 EXP가 2배.", "バトル終了時の獲得EXPが2倍。"),
         ("Excellent를 내면 SP가 회복되는", "Excellentを出すとSPが回復する"), ("파워팔찌SP", "パワーうでわSP")]
LIST_BG, LIST_FG = (0x10, 0x3C, 0xA8), (0xE6, 0xE6, 0xE6)
DESC_BG, DESC_FG = (0xF4, 0xF4, 0xF4), (0x37, 0x37, 0x37)


def colour(alpha, fg, bg):
    a = alpha[..., None]
    img = np.asarray(bg, np.float32) * (1 - a) + np.asarray(fg, np.float32) * a
    return Image.fromarray(np.clip(img, 0, 255).astype(np.uint8), "RGB")


def variants(name):
    # Hangul cannot move down in font_btl (13-row cell, 120+ syllables already touch the bottom row), so the
    # ASCII glyphs move to the Hangul instead: hangul_dy = 0, ASCII shift = Hangul shift (1DX arrangement).
    v = {"V0 shipped": get_font(f"ko:{name}")}
    r2 = transform(name, 0, LETTERS_DIGITS + PUNCT, adv="3dx")
    v["V2 1DX ASCII on Hangul baseline, 3DX adv"] = Font(f"V2:{name}", L.build(r2.font))
    r3 = transform(name, 0, LETTERS_DIGITS + PUNCT, adv="1dx")
    v["V3 1DX ASCII on Hangul baseline, 1DX adv"] = Font(f"V3:{name}", L.build(r3.font))
    return v, (r2, r3)


def main():
    OUT.mkdir(parents=True, exist_ok=True)
    gz = get_font("gaizi")
    for name, samples, fg, bg in (("font", NAMES, LIST_FG, LIST_BG), ("font_btl", DESCS, DESC_FG, DESC_BG)):
        vs, rs = variants(name)
        for r in rs:
            for p in r.problems:
                print("problem:", p)
        sh = Sheet(zoom=3, label_w=270)
        for ko, jp in samples:
            sh.add(f"JP 3DX {name}: {jp}", colour(draw_text(get_font(f'jp:{name}'), jp, icon_font=gz)[0], fg, bg))
            for label, fnt in vs.items():
                a, info = draw_text(fnt, ko, icon_font=gz)
                sh.add(f"{label}", colour(a, fg, bg), note=f"width {info['width']:.0f}px")
            sh.add(f"1DX KR {name} (own advances)", colour(draw_text(get_font(f'1dx:{name}'), ko)[0], fg, bg))
        tag = sys.argv[1] if len(sys.argv) > 1 else "proto"
        outs = sh.save(OUT / f"{tag}_{name}.png")
        print(name, [str(o) for o in outs])


if __name__ == "__main__":
    main()
