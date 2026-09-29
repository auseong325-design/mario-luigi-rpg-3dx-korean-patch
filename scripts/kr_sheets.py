"""Make large, labelled glyph sheets for visual transcription of the Korean DS fonts.

Output: work/kr_font/read/<space>_<nn>.png (80 glyphs each, 10 x 8 grid) and
work/kr_font/read/index.json describing which codes are on which sheet.
space 'main' = single-byte codes (arm9 font); 'rep' = 2-byte codes (dialogue font,
falling back to the StatFontSet 12x12 font for codes the dialogue font lacks).
"""

from __future__ import annotations

import json

from PIL import Image, ImageDraw, ImageFont

from kr_ocr import collect_fonts
from libnds_kr import ROOT, Glyph

OUT = ROOT / "work" / "kr_font" / "read"
COLS, ROWS, S = 10, 8, 5


def sheet(items: list[tuple[int, Glyph]], title: str, path) -> None:
    cw, ch = 16 * S + 14, 16 * S + 22
    img = Image.new("RGB", (COLS * cw, ROWS * ch + 20), "white")
    d = ImageDraw.Draw(img)
    lab = ImageFont.truetype(r"C:\Windows\Fonts\malgun.ttf", 13)
    d.text((4, 2), title, fill=(0, 0, 0), font=lab)
    for k, (code, g) in enumerate(items):
        x0, y0 = (k % COLS) * cw, 20 + (k // COLS) * ch
        d.rectangle([x0, y0, x0 + cw - 1, y0 + ch - 1], outline=(220, 220, 220))
        d.text((x0 + 3, y0 + 1), f"{code:03X}", fill=(210, 0, 0), font=lab)
        for y in range(g.height):
            for x in range(g.width):
                v = g.pixels[y * g.width + x]
                if v:
                    c = (0, 0, 0) if v == 2 else (170, 170, 170)
                    d.rectangle([x0 + 6 + x * S, y0 + 19 + y * S, x0 + 5 + (x + 1) * S, y0 + 18 + (y + 1) * S], fill=c)
    img.save(path)


def main() -> None:
    OUT.mkdir(parents=True, exist_ok=True)
    fonts = collect_fonts()
    rep = dict(fonts["stat"])
    rep.update(fonts["dlg"])
    spaces = {"main": fonts["main"], "rep": rep}
    index = {}
    for name, font in spaces.items():
        codes = sorted(font)
        for n in range(0, len(codes), COLS * ROWS):
            chunk = codes[n:n + COLS * ROWS]
            fname = f"{name}_{n // (COLS * ROWS):02d}.png"
            sheet([(c, font[c]) for c in chunk], f"{name} codes {chunk[0]:03X}-{chunk[-1]:03X}", OUT / fname)
            index[fname] = [f"{c:03X}" for c in chunk]
    (OUT / "index.json").write_text(json.dumps(index, indent=1), encoding="utf-8")
    print({k: len(v) for k, v in index.items()})


if __name__ == "__main__":
    main()
