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
pm = np.roll(premul(comp), -10, axis=0)
small = pm.reshape(128, 2, 256, 2, 4).mean((1, 3))
bg = np.array([52, 52, 64], np.float32)
f = lambda pm: np.uint8(np.clip(pm[..., :3] + bg * (1 - pm[..., 3:] / 255), 0, 255))
ban = premul(load(E / "3dx_COMMON_jp.png")[::-1])
kr1 = premul(load(E / "1dx_COMMON_kr.png")[::-1])
a = f(small)[100:118, 95:150]
b = f(kr1)[104:122, 100:155]
c = f(ban)[104:122, 100:155]
d = f(ban)[60:80, 228:256]
e = f(small)[60:80, 228:256]
g = f(kr1)[28:42, 236:256]
row1 = np.concatenate([a, np.zeros((18, 4, 3), np.uint8), b, np.zeros((18, 4, 3), np.uint8), c], 1)
Image.fromarray(row1).resize((row1.shape[1] * 8, row1.shape[0] * 8), Image.NEAREST).save(P / "v1_deluxe_x8.png")
pad = lambda x, h: np.concatenate([x, np.zeros((h - x.shape[0], x.shape[1], 3), np.uint8)], 0)
row2 = np.concatenate([d, np.zeros((20, 4, 3), np.uint8), e, np.zeros((20, 4, 3), np.uint8), pad(g, 20)], 1)
Image.fromarray(row2).resize((row2.shape[1] * 8, row2.shape[0] * 8), Image.NEAREST).save(P / "v1_tm_x8.png")
print(row1.shape, row2.shape)
