import numpy as np
from PIL import Image
from pathlib import Path
W = Path(__file__).resolve().parent.parent
E = W / "extract"
P = W / "preview"


def load(p):
    return np.asarray(Image.open(p).convert("RGBA"), np.float32)


def premul(a):
    al = a[..., 3:] / 255.0
    return np.concatenate([a[..., :3] * al, a[..., 3:]], 2)


bot = load(E / "title_kr_title_logo_JP_bottom.png")
top = load(E / "title_kr_title_logo_JP_top.png")
comp = np.asarray(Image.alpha_composite(Image.fromarray(np.uint8(bot)), Image.fromarray(np.uint8(top))), np.float32)
pm = premul(comp)
pm = np.roll(pm, -10, axis=0)
small = pm.reshape(128, 2, 256, 2, 4).mean((1, 3))
bg = np.array([52, 52, 64], np.float32)
f = lambda pm: np.uint8(np.clip(pm[..., :3] + bg * (1 - pm[..., 3:] / 255), 0, 255))
ban = premul(load(E / "3dx_COMMON_jp.png")[::-1])
kr1 = premul(load(E / "1dx_COMMON_kr.png")[::-1])
sheet = np.concatenate([f(ban), f(small), f(kr1)], 0)
Image.fromarray(sheet).resize((768, 1152), Image.LANCZOS).save(P / "v1_jp_kr_1dx_x3.png")
# crops x6: TM region and DX region
crops = []
for (x0, y0, x1, y1) in [(200, 40, 256, 90), (60, 70, 190, 128)]:
    row = [f(a)[y0:y1, x0:x1] for a in (ban, small, kr1)]
    crops.append(np.concatenate(row, 1))
for i, c in enumerate(crops):
    Image.fromarray(c).resize((c.shape[1] * 4, c.shape[0] * 4), Image.NEAREST).save(P / f"v1_crop{i}.png")
    print(c.shape)
