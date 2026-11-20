import numpy as np
from PIL import Image
from pathlib import Path
W = Path(__file__).resolve().parent.parent
E = W / "extract"
P = W / "preview"


def load(p):
    return np.asarray(Image.open(p).convert("RGBA"), np.float32)


bg = np.array([52, 52, 64], np.float32)
def f(a):
    al = a[..., 3:] / 255
    return np.uint8(np.clip(a[..., :3] * al + bg * (1 - al), 0, 255))


kt = load(E / "title_kr_title_logo_JP_top.png")
jt = load(E / "title_jp_title_logo_JP_top.png")
ban = load(E / "3dx_COMMON_jp.png")[::-1]
a = f(kt)[130:170, 470:512]
b = f(jt)[120:160, 430:472]
c = f(ban)[60:80, 232:256]
Image.fromarray(np.concatenate([a, np.zeros((40, 4, 3), np.uint8), b], 1)).resize((88 * 8, 40 * 8), Image.NEAREST).save(P / "tm_title_kr_jp_x8.png")
# print luminance of the JP banner TM box
lum = ban[..., :3].mean(2)
np.set_printoptions(linewidth=250)
print("JP banner lum y60..80 x232..256\n", np.round(lum[60:80, 232:256]).astype(int))
print("JP banner alpha\n", ban[60:80, 232:256, 3].astype(int))
print("ink colours", ban[60:80, 232:256][lum[60:80, 232:256] < 60][:, :3][:10])
lk = kt[..., :3].mean(2)
print("KR title lum y135..165 x478..508\n", np.round(lk[135:165, 478:508]).astype(int))
print("KR title alpha\n", kt[135:165, 478:508, 3].astype(int))
