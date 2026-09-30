"""Glyph skeleton for 「쿠파주니어」 in the 1DX 쿠파군단 RPG logo lettering (KG_LOGO_TEXT_L_12_KR_ko).

쿠 and 파 are the 1DX letters themselves (pixel masks). 주 / 니 / 어 do not exist there; they are
assembled from the same strokes: the lettering is built from straight ~6 px bars (measured on 쿠/파),
so 주 = the 쿠's ㅜ + a ㅈ made of the ㅋ top bar and two slanted bars of the same width,
니 = ㄴ (bars of the same width) + the 파's ㅏ stem, 어 = an angular ㅇ ring of the same width + ㅓ
(the 파's ㅏ with its tick mirrored). Output: a hi-res (x8) mask of the word and per-syllable boxes.
"""
from pathlib import Path
import numpy as np
from PIL import Image, ImageDraw
from scipy import ndimage as ndi

ROOT = Path(r"C:\mario-luigi-rpg-3dx-korean-patch")
SS = 8


def kg_face():
    a = np.asarray(Image.open(ROOT / "work/img/lyt/1DX/MLyt/MLYT_MAIN_KR_ko/KG_LOGO_TEXT_L_12_KR_ko.png")
                   .convert("RGBA")).astype(float)
    rgb, al = a[..., :3], a[..., 3]
    # soft coverage: dark brown letters (the RPG below is cut away by the y range)
    dark = np.clip((170 - rgb.max(2)) / 60, 0, 1) * np.clip((al - 100) / 100, 0, 1) * (rgb[..., 0] >= rgb[..., 2])
    dark[:45] = 0; dark[92:] = 0
    return dark


def word_mask(gap=3.0, stroke=None):
    f = kg_face()
    up = ndi.zoom(f, SS, order=1, grid_mode=True, mode="nearest") > 0.5
    lab, n = ndi.label(up)
    sizes = ndi.sum(up, lab, range(1, n + 1))
    up = np.isin(lab, 1 + np.nonzero(sizes >= 30 * SS * SS)[0])     # drop glow specks
    ku = up[45 * SS:92 * SS, 95 * SS:155 * SS]      # 쿠
    pa = up[45 * SS:92 * SS, 155 * SS:199 * SS]     # 파
    # measured strokes (1x): bar width, ㅏ stem box, ㅜ box
    w = stroke or 6.0
    H = 47
    def canvas(wd):
        return Image.new("L", (int(wd * SS), H * SS), 0)
    def rect(d, x0, y0, x1, y1):
        d.rectangle([x0 * SS, y0 * SS, x1 * SS - 1, y1 * SS - 1], fill=255)
    def poly(d, pts):
        d.polygon([(x * SS, y * SS) for x, y in pts], fill=255)
    top = 51 - 45            # letter top of 쿠 (y=51 in 1DX)
    # 주: ㅈ = top bar + ㅅ, then the ㅜ of 쿠 (y 71..90 in 1DX)
    ju = canvas(60); d = ImageDraw.Draw(ju)
    rect(d, 22, top, 55, top + w)                      # ㅈ top bar (the ㅋ top bar of 쿠: x 118..150)
    cx = 38.5                                          # over the ㅜ stem of 쿠 (x 130..136)
    poly(d, [(cx - w / 2, top + w), (cx + w / 2, top + w), (cx - 10, top + 20), (cx - 10 - w, top + 20)])
    poly(d, [(cx - w / 2 + 1, top + w + 2), (cx + w / 2 + 1, top + w + 2), (cx + 12 + w, top + 20), (cx + 12, top + 20)])
    ju_a = np.asarray(ju) > 127
    ku_u = ku.copy(); ku_u[:(71 - 45) * SS] = False  # the ㅜ of 쿠
    ju_a = ju_a | np.pad(ku_u, ((0, 0), (0, ju_a.shape[1] - ku_u.shape[1])))[:, :ju_a.shape[1]]
    # 니: ㄴ + ㅣ (the 파's ㅏ stem, x 185..192, y 54..85 in 1DX; tick removed)
    ni = canvas(40); d = ImageDraw.Draw(ni)
    t2 = 54 - 45
    rect(d, 3, t2, 3 + w, t2 + 28)                     # ㄴ vertical
    rect(d, 3, t2 + 22, 25, t2 + 28)                   # ㄴ bottom bar
    stem_img = Image.new("L", (int(7 * SS), H * SS), 0)
    ImageDraw.Draw(stem_img).rectangle([0, (54 - 45) * SS, int(6.5 * SS) - 1, (85 - 45) * SS - 1], fill=255)
    stem = np.asarray(stem_img) > 127       # the 파's ㅏ stem: 6.5 px wide, y 54..85 (measured)
    ni_a = np.asarray(ni) > 127
    ni_a[:, 28 * SS:28 * SS + stem.shape[1]] |= stem
    # 어: angular ㅇ ring + ㅓ (stem + tick on the left)
    eo = canvas(42); d = ImageDraw.Draw(eo)
    x0, y0, x1, y1, c = 0, t2 + 5, 22, t2 + 26, 6
    poly(d, [(x0 + c, y0), (x1 - c, y0), (x1, y0 + c), (x1, y1 - c), (x1 - c, y1), (x0 + c, y1), (x0, y1 - c), (x0, y0 + c)])
    d.polygon([((x0 + w + c * 0.5) * SS, (y0 + w) * SS), ((x1 - w - c * 0.5) * SS, (y0 + w) * SS),
               ((x1 - w) * SS, (y0 + w + c * 0.5) * SS), ((x1 - w) * SS, (y1 - w - c * 0.5) * SS),
               ((x1 - w - c * 0.5) * SS, (y1 - w) * SS), ((x0 + w + c * 0.5) * SS, (y1 - w) * SS),
               ((x0 + w) * SS, (y1 - w - c * 0.5) * SS), ((x0 + w) * SS, (y0 + w + c * 0.5) * SS)], fill=0)
    eo_a = np.asarray(eo) > 127
    eo_a[:, 33 * SS:33 * SS + stem.shape[1]] |= stem
    tick = pa[(66 - 45) * SS:(72 - 45) * SS, (192 - 155) * SS:(198 - 155) * SS][:, ::-1]
    eo_a[(66 - 45) * SS:(72 - 45) * SS, 33 * SS - tick.shape[1] + SS:33 * SS + SS] |= tick
    # assemble: trim each syllable to its ink columns and join with a fixed gap
    parts = []
    for p in (ku, pa, ju_a, ni_a, eo_a):
        lab_, n_ = ndi.label(p)
        sz = ndi.sum(p, lab_, range(1, n_ + 1))
        p = np.isin(lab_, 1 + np.nonzero(sz >= 25 * SS * SS)[0])
        cols = np.nonzero(p.any(0))[0]
        parts.append(p[:, cols.min():cols.max() + 1])
    g = np.zeros((H * SS, int(gap * SS)), bool)
    boxes, out, x = [], [], 0
    for i, p in enumerate(parts):
        if i:
            out.append(g); x += g.shape[1]
        boxes.append((x / SS, (x + p.shape[1]) / SS))
        out.append(p); x += p.shape[1]
    return np.concatenate(out, 1), boxes


if __name__ == "__main__":
    m, boxes = word_mask()
    print("word size (1x):", m.shape[1] / SS, "x", m.shape[0] / SS, boxes)
    Image.fromarray((m * 255).astype(np.uint8)).resize((m.shape[1] // 2, m.shape[0] // 2), Image.LANCZOS).save(
        ROOT / "work/img/logo/kr_skeleton/kupa_junior.png")
