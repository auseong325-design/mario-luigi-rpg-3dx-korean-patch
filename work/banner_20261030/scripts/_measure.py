import numpy as np
from PIL import Image
from pathlib import Path
from scipy import ndimage as ndi
W = Path(__file__).resolve().parent.parent
E = W / "extract"
P = W / "preview"


def load(p):
    return np.asarray(Image.open(p).convert("RGBA"), np.float32)


bot = load(E / "title_kr_title_logo_JP_bottom.png")
top = load(E / "title_kr_title_logo_JP_top.png")
comp = np.asarray(Image.alpha_composite(Image.fromarray(np.uint8(bot)), Image.fromarray(np.uint8(top))), np.float32)
jtop = load(E / "title_jp_title_logo_JP_top.png")
ban = load(E / "3dx_COMMON_jp.png")[::-1]
kr1 = load(E / "1dx_COMMON_kr.png")[::-1]
for n, a in [("kr_comp", comp), ("kr_top", top), ("kr_bot", bot), ("jp_top", jtop), ("jp_banner", ban), ("1dx_banner", kr1)]:
    for thr in (1, 17, 128):
        ys, xs = np.nonzero(a[..., 3] >= thr)
        print(n, "alpha>=%d" % thr, xs.min(), ys.min(), xs.max() + 1, ys.max() + 1)
# components of the top textures (find TM): small components
for n, a in [("kr_top", top), ("jp_top", jtop)]:
    lab, k = ndi.label(a[..., 3] > 16)
    for i in range(1, k + 1):
        ys, xs = np.nonzero(lab == i)
        if len(xs) < 2000:
            print(n, "comp", i, len(xs), xs.min(), ys.min(), xs.max() + 1, ys.max() + 1)
# JP banner small components (TM)
lab, k = ndi.label(ban[..., 3] > 16)
for i in range(1, k + 1):
    ys, xs = np.nonzero(lab == i)
    print("jp_banner comp", i, len(xs), xs.min(), ys.min(), xs.max() + 1, ys.max() + 1)
lab, k = ndi.label(kr1[..., 3] > 16)
for i in range(1, k + 1):
    ys, xs = np.nonzero(lab == i)
    print("1dx_banner comp", i, len(xs), xs.min(), ys.min(), xs.max() + 1, ys.max() + 1)
