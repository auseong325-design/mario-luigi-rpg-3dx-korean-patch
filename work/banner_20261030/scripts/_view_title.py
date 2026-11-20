import numpy as np
from PIL import Image
from pathlib import Path
W = Path(__file__).resolve().parent.parent
R = W.parents[1]
P = W / "preview"
F = R / "work/img/fileload_titlelogo_20261009"
K = R / "work/img/logo2/out"
bg = np.array([52, 52, 64], float)


def comp(bottom, top):
    a = Image.alpha_composite(Image.open(bottom).convert("RGBA"), Image.open(top).convert("RGBA"))
    return np.asarray(a, float)


def flat(a):
    al = a[..., 3:] / 255
    return np.uint8(a[..., :3] * al + bg * (1 - al))


jp = comp(F / "jp_title_logo_JP_bottom.png", F / "jp_title_logo_JP_top.png")
kr = comp(K / "title_logo_JP_bottom.png", K / "title_logo_JP_top.png")
Image.fromarray(np.uint8(jp)).save(P / "title_jp_composite.png")
Image.fromarray(np.uint8(kr)).save(P / "title_kr_composite.png")
sheet = np.concatenate([flat(jp), flat(kr)], 0)
Image.fromarray(sheet).save(P / "title_jp_vs_kr.png")
print(jp.shape, kr.shape)
for n, a in [("jp", jp), ("kr", kr)]:
    ys, xs = np.nonzero(a[..., 3] > 8)
    print(n, "alpha>8 bbox", xs.min(), ys.min(), xs.max() + 1, ys.max() + 1)
