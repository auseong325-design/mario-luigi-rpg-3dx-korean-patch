"""RT5: per-frame colour metrics of a burst2 folder, to time the phases of the 스타&스타 demonstration.

The demonstration scene is drawn in greyscale; only the attack effects are coloured. For each fNNN.png the script
measures, separately for the top and the bottom 3DS screen (Azahar default layout inside the render surface):
  sat  = mean HSV saturation (0..255)       yel = % of pixels that are saturated yellow (EXCELLENT / flash)
and prints one line per frame plus the segments where bottom `sat` >= --thr (effects on the bottom screen = hits).

  rt5_phase.py DIR [--thr 40] [--every 1]
"""
from __future__ import annotations

import argparse
import json
from pathlib import Path

from PIL import Image


def screens(im: Image.Image):
    w, h = im.size
    s = min(w / 400, h / 480)
    x_top = (w - 400 * s) / 2
    x_bot = (w - 320 * s) / 2
    y0 = (h - 480 * s) / 2
    top = im.crop((int(x_top), int(y0), int(x_top + 400 * s), int(y0 + 240 * s)))
    bot = im.crop((int(x_bot), int(y0 + 240 * s), int(x_bot + 320 * s), int(y0 + 480 * s)))
    return top, bot


def metrics(img: Image.Image):
    hsv = img.convert("HSV")
    hist_s = hsv.getchannel("S").histogram()
    n = sum(hist_s)
    sat = sum(i * c for i, c in enumerate(hist_s)) / n
    px = img.convert("RGB").getdata()
    yel = sum(1 for r, g, b in px if r > 200 and g > 170 and b < 90) * 100.0 / n
    return round(sat, 1), round(yel, 1)


def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("dir")
    ap.add_argument("--thr", type=float, default=40.0)
    ap.add_argument("--every", type=int, default=1)
    ap.add_argument("--quiet", action="store_true")
    a = ap.parse_args()
    d = Path(a.dir)
    idx = json.loads((d / "index.json").read_text(encoding="utf-8"))
    rows = []
    for f in idx["frames"][::a.every]:
        im = Image.open(d / f"f{f['i']:03d}.png").convert("RGB")
        top, bot = screens(im)
        ts, ty = metrics(top)
        bs, by = metrics(bot)
        rows.append((f["i"], f["t0"], ts, ty, bs, by))
        if not a.quiet:
            print(f"#{f['i']:03d} t={f['t0']:7.3f}  top sat {ts:5.1f} yel {ty:5.1f}  bot sat {bs:5.1f} yel {by:5.1f}")
    seg, start = [], None
    for r in rows:
        on = r[4] >= a.thr
        if on and start is None:
            start = r
        if not on and start is not None:
            seg.append((start, prev))
            start = None
        prev = r
    if start is not None:
        seg.append((start, rows[-1]))
    for s, e in seg:
        print(f"bottom effects: #{s[0]}..#{e[0]}  t {s[1]:.3f}..{e[1]:.3f}  ({e[1] - s[1]:.3f} s)")
    out = d / "phase.json"
    out.write_text(json.dumps({"thr": a.thr, "rows": rows,
                               "segments": [[s[0], e[0], s[1], e[1]] for s, e in seg]}), encoding="utf-8")


if __name__ == "__main__":
    main()
