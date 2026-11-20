"""crop.py <src.png> <x0> <y0> <x1> <y1> <zoom> <out.png> : crop + nearest upscale (max 1600 px side)."""
import sys

from PIL import Image

src, x0, y0, x1, y1, z, out = sys.argv[1], *map(int, sys.argv[2:7]), sys.argv[7]
im = Image.open(src).convert("RGB").crop((x0, y0, x1, y1))
w, h = im.width * z, im.height * z
s = min(1.0, 1600 / max(w, h))
im = im.resize((max(1, int(w * s)), max(1, int(h * s))), Image.NEAREST)
im.save(out)
print(out, im.size)
