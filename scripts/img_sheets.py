"""Contact sheets of layout textures for visual triage and before/after review.

    python scripts/img_sheets.py --game 3DX --suffix _JP_ja --out work/img/sheets/3DX_JP
    python scripts/img_sheets.py --game 1DX --suffix _KR_ko --out work/img/sheets/1DX_KR
    python scripts/img_sheets.py --pngs a.png b.png ... --out <prefix>      # any list of PNGs

Each cell shows the texture on a checkerboard (so white text and alpha stay visible), scaled
to fit the cell, with its index; <prefix>_index.txt maps index -> manifest id, size, format.
"""

from __future__ import annotations

import argparse
import json
from pathlib import Path

from PIL import Image, ImageDraw

ROOT = Path(__file__).resolve().parent.parent
CELL_W, CELL_H, LABEL = 200, 110, 14


def checker(w: int, h: int, s: int = 6) -> Image.Image:
    im = Image.new("RGBA", (w, h), (70, 70, 70, 255))
    d = ImageDraw.Draw(im)
    for y in range(0, h, s):
        for x in range((y // s) % 2 * s, w, 2 * s):
            d.rectangle([x, y, x + s - 1, y + s - 1], fill=(110, 110, 110, 255))
    return im


def sheets(items: list[tuple[str, Path, str]], out: str, cols: int = 6, rows: int = 8) -> list[Path]:
    """items = [(label, png path, index text)] -> sheet files."""
    prefix = ROOT / out if not Path(out).is_absolute() else Path(out)
    prefix.parent.mkdir(parents=True, exist_ok=True)
    per = cols * rows
    written = []
    lines = []
    for page in range((len(items) + per - 1) // per):
        sheet = Image.new("RGBA", (cols * CELL_W, rows * (CELL_H + LABEL)), (40, 40, 40, 255))
        d = ImageDraw.Draw(sheet)
        for k, (label, png, text) in enumerate(items[page * per:(page + 1) * per]):
            i = page * per + k
            im = Image.open(png).convert("RGBA")
            sc = min((CELL_W - 6) / im.width, (CELL_H - 6) / im.height, 4.0)
            im = im.resize((max(1, round(im.width * sc)), max(1, round(im.height * sc))),
                           Image.NEAREST if sc >= 1 else Image.LANCZOS)
            bg = checker(im.width, im.height)
            bg.alpha_composite(im)
            x, y = (k % cols) * CELL_W, (k // cols) * (CELL_H + LABEL)
            sheet.paste(bg, (x + 3, y + LABEL + 3))
            d.text((x + 3, y + 1), f"{i}: {label}"[:34], fill=(255, 230, 90, 255))
            lines.append(f"{i}\t{text}")
        p = Path(f"{prefix}_{page + 1:02d}.png")
        sheet.convert("RGB").save(p)
        written.append(p)
    Path(f"{prefix}_index.txt").write_text("\n".join(lines) + "\n", "utf-8")
    return written


def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("--game", choices=["3DX", "1DX"])
    ap.add_argument("--suffix", default="", help="keep files whose name ends with this (before .bflim)")
    ap.add_argument("--dat", help="keep one Lyt dat (BLyt, KLyt, ...)")
    ap.add_argument("--entry", help="keep one BG4 entry")
    ap.add_argument("--pngs", nargs="*")
    ap.add_argument("--out", required=True)
    ap.add_argument("--cols", type=int, default=6)
    ap.add_argument("--rows", type=int, default=8)
    a = ap.parse_args()
    if a.pngs:
        items = [(Path(p).stem, Path(p), p) for p in a.pngs]
    else:
        man = json.loads((ROOT / "work/img/lyt_manifest.json").read_text("utf-8"))[a.game]
        rows = [r for r in man if "dup_of" not in r and r["file"].endswith(a.suffix + ".bflim")
                and (not a.dat or r["dat"] == a.dat) and (not a.entry or r["entry"] == a.entry)]
        items = [(r["file"].rsplit("/", 1)[-1][:-6], ROOT / r["png"],
                  f"{r['id']}\t{r['w']}x{r['h']}\t{r['fmt']}") for r in rows]
    for p in sheets(items, a.out, a.cols, a.rows):
        print(p.relative_to(ROOT) if p.is_relative_to(ROOT) else p)


if __name__ == "__main__":
    main()
