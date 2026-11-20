"""Review-sheet helper with Korean labels (every sheet side <= 1600 px)."""
from __future__ import annotations

import numpy as np
from PIL import Image, ImageDraw, ImageFont

import glyphs as G

LABEL_FONT = G.ROOT / "fonts/NotoSansKR-Bold.otf"


def sheet(rows, path, gap=8, bg=(32, 32, 36), max_px=1600, label_px=15):
    f = ImageFont.truetype(str(LABEL_FONT), label_px)
    lab_h = label_px + 6
    sizes = []
    for row in rows:
        h = max(b.shape[0] for _, b in row) + lab_h
        w = sum(b.shape[1] for _, b in row) + gap * (len(row) - 1)
        sizes.append((h, w))
    W = max(w for _, w in sizes) + 2 * gap
    H = sum(h for h, _ in sizes) + gap * (len(rows) + 1)
    img = Image.new("RGB", (W, H), bg)
    d = ImageDraw.Draw(img)
    y = gap
    for row, (h, _) in zip(rows, sizes):
        x = gap
        for lab, b in row:
            d.text((x, y), lab, font=f, fill=(255, 225, 120))
            img.paste(Image.fromarray(np.clip(np.rint(b), 0, 255).astype(np.uint8)), (x, y + lab_h))
            x += b.shape[1] + gap
        y += h + gap
    if max(img.size) > max_px:
        s = max_px / max(img.size)
        img = img.resize((int(img.width * s), int(img.height * s)), Image.LANCZOS)
    img.save(path)
    return img.size
