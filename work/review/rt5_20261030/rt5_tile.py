"""RT5: tile several grabs into one labelled sheet (each side <= --max px) for quick viewing.

  rt5_tile.py OUT.png IMG1 [IMG2 ...] [--cols 3] [--w 520] [--max 1600]
"""
from __future__ import annotations

import argparse
from pathlib import Path

from PIL import Image, ImageDraw


def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("out")
    ap.add_argument("imgs", nargs="+")
    ap.add_argument("--cols", type=int, default=3)
    ap.add_argument("--w", type=int, default=520)
    ap.add_argument("--max", type=int, default=1600)
    ap.add_argument("--crop-x", default="0.29:0.71", help="keep this fraction of the width (3DS screens only)")
    a = ap.parse_args()
    x0, x1 = (float(v) for v in a.crop_x.split(":"))
    ims = []
    for p in a.imgs:
        im = Image.open(p).convert("RGB")
        im = im.crop((int(im.width * x0), 0, int(im.width * x1), im.height))
        s = a.w / im.width
        ims.append((Path(p).stem, im.resize((a.w, max(1, int(im.height * s))))))
    h = max(im.height for _, im in ims)
    cols = min(a.cols, len(ims))
    rows = (len(ims) + cols - 1) // cols
    sheet = Image.new("RGB", (cols * a.w, rows * (h + 16)), (30, 30, 30))
    dr = ImageDraw.Draw(sheet)
    for k, (name, im) in enumerate(ims):
        x, y = (k % cols) * a.w, (k // cols) * (h + 16)
        sheet.paste(im, (x, y + 16))
        dr.text((x + 3, y + 2), name, fill=(255, 255, 0))
    s = min(1.0, a.max / max(sheet.size))
    if s < 1.0:
        sheet = sheet.resize((int(sheet.width * s), int(sheet.height * s)))
    sheet.save(a.out)
    print(f"saved {a.out} {sheet.size}")


if __name__ == "__main__":
    main()
