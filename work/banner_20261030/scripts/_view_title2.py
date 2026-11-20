import numpy as np
from PIL import Image
from pathlib import Path
W = Path(__file__).resolve().parent.parent
E = W / "extract"
P = W / "preview"
bg = np.array([52, 52, 64], float)


def flat(a):
    al = a[..., 3:] / 255
    return np.uint8(a[..., :3] * al + bg * (1 - al))


def comp(src):
    a = Image.open(E / f"title_{src}_title_logo_JP_bottom.png").convert("RGBA")
    b = Image.open(E / f"title_{src}_title_logo_JP_top.png").convert("RGBA")
    return np.asarray(Image.alpha_composite(a, b), float)


jp = comp("jp")
kr = comp("kr")
Image.fromarray(np.uint8(jp)).save(E / "title_jp_composite.png")
Image.fromarray(np.uint8(kr)).save(E / "title_kr_composite.png")
ban = np.asarray(Image.open(P / "3dx_COMMON_jp_upright.png").convert("RGBA"), float)
ban2 = np.asarray(Image.fromarray(np.uint8(ban)).resize((512, 256), Image.NEAREST), float)
sheet = np.concatenate([flat(jp), flat(ban2), flat(kr)], 0)
Image.fromarray(sheet).save(P / "title_jp_banner_title_kr.png")
for n, a in [("jp_title", jp), ("kr_title", kr), ("jp_banner", ban)]:
    ys, xs = np.nonzero(a[..., 3] > 128)
    print(n, "alpha>128 bbox", xs.min(), ys.min(), xs.max() + 1, ys.max() + 1)
