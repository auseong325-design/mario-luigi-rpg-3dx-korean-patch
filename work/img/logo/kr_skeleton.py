"""1DX Korean logo: letter-face masks (glyph skeleton) for 마리오 / 루이지, stripped of the 1DX decoration."""
import sys
from pathlib import Path
import numpy as np
from PIL import Image
from scipy import ndimage as ndi
sys.path.insert(0, str(Path(__file__).parent))
import logo_lib as L

ROOT = Path(__file__).resolve().parents[3]
OUT = ROOT / "work/img/logo/kr_skeleton"
NAV1DX = (0, 44, 74)


def kr_masks():
    a = L.load(ROOT / "work/img/logo/src/1DX/kr_logo_rgba.png")
    B1, glow = L.body_of(a)
    cov = L.face_cov(a, glow, ref=NAV1DX)
    lab, n = ndi.label(cov > 0)
    objs = ndi.find_objects(lab)
    words = {"mario": np.zeros_like(cov), "luigi": np.zeros_like(cov), "amp": np.zeros_like(cov),
             "sprout": np.zeros_like(cov)}
    for i, sl in enumerate(objs):
        x0, x1, y0, y1 = sl[1].start, sl[1].stop, sl[0].start, sl[0].stop
        m = lab == i + 1
        if m.sum() < 8 or y0 > 100:
            continue
        cx = (x0 + x1) / 2
        if 170 <= x0 and x1 <= 202 and y0 >= 45:
            key = "amp"
        elif x0 >= 312 and y1 <= 42:
            key = "sprout"                    # the 1DX bean sprout on 지 (not part of the letter)
        elif cx < 171:
            key = "mario"
        elif cx < 340:
            key = "luigi"
        else:
            continue
        words[key] += cov * m
    return a, words


if __name__ == "__main__":
    OUT.mkdir(parents=True, exist_ok=True)
    a, words = kr_masks()
    for k, m in words.items():
        ys, xs = np.nonzero(m > 0.5)
        print(k, "bbox x", xs.min(), xs.max(), "y", ys.min(), ys.max(), "area", round(m.sum()))
        Image.fromarray((m * 255).astype(np.uint8)).save(OUT / f"{k}.png")
    vis = np.zeros(a.shape[:2] + (3,), np.uint8)
    vis[..., 0] = words["mario"] * 255; vis[..., 1] = words["luigi"] * 255; vis[..., 2] = (words["amp"] + words["sprout"]) * 255
    Image.fromarray(vis[:120]).resize((1024, 240), Image.NEAREST).save(OUT / "_words.png")
