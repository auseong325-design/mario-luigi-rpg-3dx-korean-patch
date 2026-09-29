"""Render a DS font {code: Glyph} to a labelled PNG sheet (for inspection / OCR checks)."""

from __future__ import annotations

from pathlib import Path

from PIL import Image, ImageDraw

from libnds_kr import Glyph


def render_sheet(font: dict[int, Glyph], path: Path, cols: int = 16, scale: int = 3,
                 codes: list[int] | None = None, label_fmt: str = "{:03X}") -> Path:
    codes = sorted(font) if codes is None else codes
    cell_w = max((g.width for g in font.values()), default=12) * scale + 6
    cell_h = max((g.height for g in font.values()), default=12) * scale + 16
    rows = (len(codes) + cols - 1) // cols
    img = Image.new("RGB", (cols * cell_w, max(1, rows) * cell_h), "white")
    draw = ImageDraw.Draw(img)
    for k, code in enumerate(codes):
        g = font.get(code)
        x0, y0 = (k % cols) * cell_w, (k // cols) * cell_h
        draw.text((x0 + 2, y0 + 1), label_fmt.format(code), fill=(200, 0, 0))
        if g is None:
            continue
        for y in range(g.height):
            for x in range(g.width):
                v = g.pixels[y * g.width + x]
                if v:
                    c = (0, 0, 0) if v == 2 else (150, 150, 150)
                    draw.rectangle([x0 + 3 + x * scale, y0 + 13 + y * scale,
                                    x0 + 3 + (x + 1) * scale - 1, y0 + 13 + (y + 1) * scale - 1], fill=c)
    path.parent.mkdir(parents=True, exist_ok=True)
    img.save(path)
    return path
