"""rowcmp.py out.png zoom  file:x0:y0:x1:y1 [...] : stack crops of several grabs (nearest zoom) for comparison,
and print the ink bounding box of light text (luma > thr) in each crop."""
import sys

import numpy as np
from PIL import Image, ImageDraw

out, zoom = sys.argv[1], int(sys.argv[2])
crops = []
for spec in sys.argv[3:]:
    f, *c = spec.rsplit(":", 4)
    x0, y0, x1, y1 = map(int, c)
    im = Image.open(f).convert("RGB").crop((x0, y0, x1, y1))
    a = np.asarray(im).astype(int)
    luma = 0.299 * a[..., 0] + 0.587 * a[..., 1] + 0.114 * a[..., 2]
    sat = a.max(axis=2) - a.min(axis=2)
    m = (luma > 150) & (sat < 60)
    ys, xs = np.nonzero(m)
    bb = (xs.min(), ys.min(), xs.max(), ys.max()) if len(xs) else None
    print(spec, "light-ink bbox", bb, "h", (bb[3] - bb[1] + 1) if bb else None)
    crops.append((spec.split("\\")[-1].split("/")[-1], im))
W = max(im.width for _, im in crops) * zoom
H = sum(im.height * zoom + 16 for _, im in crops)
s = min(1.0, 1600 / max(W, H))
canvas = Image.new("RGB", (W, H), (0, 0, 0))
d = ImageDraw.Draw(canvas)
y = 0
for name, im in crops:
    d.text((2, y), name, fill=(255, 255, 0))
    canvas.paste(im.resize((im.width * zoom, im.height * zoom), Image.NEAREST), (0, y + 14))
    y += im.height * zoom + 16
if s < 1:
    canvas = canvas.resize((int(W * s), int(H * s)), Image.NEAREST)
canvas.save(out)
print(out, canvas.size)
