"""Print header facts of the 3DX (original, patched) and 1DX KR fonts (FONT worker, read-only)."""
from __future__ import annotations

import hashlib
import sys
from collections import Counter
from pathlib import Path

ROOT = Path(__file__).resolve().parents[4]
sys.path.insert(0, str(ROOT / "scripts"))
import libbffnt as L  # noqa: E402

FILES = {
    "3dx_font": ROOT / "romfs/Msg/JP_ja/font.bffnt",
    "3dx_font_l": ROOT / "romfs/Msg/JP_ja/font_l.bffnt",
    "3dx_font_btl": ROOT / "romfs/Msg/JP_ja/font_btl.bffnt",
    "3dx_font_ruby": ROOT / "romfs/Msg/font_ruby.bffnt",
    "3dx_gaizi": ROOT / "romfs/Msg/gaizi.bffnt",
    "3dx_mario_font": ROOT / "romfs/Staffroll/mario_font.bffnt",
    "ko_font": ROOT / "patch/00040000001CA900/romfs/Msg/JP_ja/font.bffnt",
    "ko_font_l": ROOT / "patch/00040000001CA900/romfs/Msg/JP_ja/font_l.bffnt",
    "ko_font_btl": ROOT / "patch/00040000001CA900/romfs/Msg/JP_ja/font_btl.bffnt",
    "1dx_font": ROOT / "ml 1dx/3romfs/Msg/KR_ko/font.bffnt",
    "1dx_font_l": ROOT / "ml 1dx/3romfs/Msg/KR_ko/font_l.bffnt",
    "1dx_font_btl": ROOT / "ml 1dx/3romfs/Msg/KR_ko/font_btl.bffnt",
    "1dx_font_sys": ROOT / "ml 1dx/3romfs/Msg/KR_ko/font_sys.bffnt",
    "1dx_font_sys_btl": ROOT / "ml 1dx/3romfs/Msg/KR_ko/font_sys_btl.bffnt",
}


def main():
    for k, p in FILES.items():
        if not p.exists():
            print(k, "missing", p)
            continue
        b = p.read_bytes()
        f = L.parse(b)
        cm = f.char_map()
        w = f.widths()
        hang = [c for c in cm if 0xAC00 <= c <= 0xD7A3]
        kanji = [c for c in cm if 0x4E00 <= c <= 0x9FFF]
        kana = [c for c in cm if 0x3041 <= c <= 0x30FF]
        hadv = Counter(w[cm[c]].char for c in hang).most_common(3)
        kadv = Counter(w[cm[c]].char for c in kanji + kana).most_common(3)
        digits = {chr(c): (w[cm[c]].left, w[cm[c]].glyph, w[cm[c]].char) for c in map(ord, "0A a") if c in cm}
        print(f"{k:18s} sha1={hashlib.sha1(b).hexdigest()[:12]} type={f.font_type} h={f.height} w={f.width} "
              f"asc={f.ascent} lf={f.line_feed} cell={f.cell_w}x{f.cell_h} base={f.baseline} maxw={f.max_char_w} "
              f"sheets={len(f.sheets)} {f.sheet_w}x{f.sheet_h} fmt={f.sheet_fmt} glyphs={f.glyph_count()} "
              f"codes={len(cm)} hangul={len(hang)} kanji={len(kanji)} kana={len(kana)} "
              f"adv_hangul={hadv} adv_kanji={kadv} dflt=({f.default_width.left},{f.default_width.glyph},"
              f"{f.default_width.char}) alt=U+{f.alter_char:04X} krng={'yes' if f.krng else 'no'} sample={digits}")


if __name__ == "__main__":
    main()
