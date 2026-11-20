"""Review sheets for the title logo v2 -> work/img/review/I4v2_*.png (every side <= 1600 px)."""
from __future__ import annotations

import numpy as np
from PIL import Image

import l2

R = l2.ROOT / "work/img/review"
V1 = l2.HERE / "prev_v1"
BLUE, DARK = (72, 128, 220), (14, 14, 34)


def stack(bot, top, bg=BLUE):
    out = np.zeros(bot.shape[:2] + (3,)) + np.array(bg, float)
    for L in (bot, top):
        al = L[..., 3:4] / 255
        out = L[..., :3] * al + out * (1 - al)
    return out


def screen(img, s=0.66):
    im = Image.fromarray(np.clip(img, 0, 255).astype(np.uint8))
    im = im.resize((round(im.width * s), round(im.height * s)), Image.BILINEAR)
    return np.asarray(im).astype(float)


def main():
    jb, jt = l2.load(l2.JP_DIR / "title_logo_JP_bottom.png"), l2.load(l2.JP_DIR / "title_logo_JP_top.png")
    kb, kt = l2.load(l2.HERE / "out/title_logo_JP_bottom.png"), l2.load(l2.HERE / "out/title_logo_JP_top.png")
    crop = (slice(0, 245), slice(0, 512))
    l2.sheet([[("Japanese original", stack(jb, jt)[crop]), ("Korean v2", stack(kb, kt)[crop])],
              [("Japanese original (dark)", stack(jb, jt, DARK)[crop]), ("Korean v2 (dark)", stack(kb, kt, DARK)[crop])]],
             R / "I4v2_title_1x.png")
    l2.sheet([[("Japanese original x2", l2.zoom_img(stack(jb, jt)[crop], 2))],
              [("Korean v2 x2", l2.zoom_img(stack(kb, kt)[crop], 2))]], R / "I4v2_title_2x.png")
    sa, sb = screen(stack(jb, jt))[0:165, :], screen(stack(kb, kt))[0:165, :]
    l2.sheet([[("in-game scale (x0.66), shown x2: Japanese", l2.zoom_img(sa, 2))],
              [("Korean v2", l2.zoom_img(sb, 2))]], R / "I4v2_title_screen_scale.png")
    for nm, (y0, y1, x0, x1) in {"left": (8, 150, 25, 175), "right": (55, 155, 150, 300)}.items():
        l2.sheet([[("Japanese x4", l2.zoom_img(l2.comp_on(jb)[y0:y1, x0:x1], 4))],
                  [("Korean v2 x4", l2.zoom_img(l2.comp_on(kb)[y0:y1, x0:x1], 4))]], R / f"I4v2_zoom_{nm}.png")
    l2.sheet([[("Japanese x7", l2.zoom_img(l2.comp_on(jt)[185:230, 195:310], 7))],
              [("Korean v2 x7", l2.zoom_img(l2.comp_on(kt)[185:230, 195:310], 7))]], R / "I4v2_deluxe.png")
    rows = []
    for n in ("title_logo_M_JP", "title_logo_L_JP"):
        a, b = l2.load(l2.JP_DIR / f"{n}.png"), l2.load(l2.HERE / f"out/{n}.png")
        rows.append([("Japanese " + n, l2.zoom_img(l2.comp_on(a), 4)), ("Korean v2", l2.zoom_img(l2.comp_on(b), 4))])
    l2.sheet(rows, R / "I4v2_pieces.png")
    src = l2.ROOT / "work/img/lyt/3DX/MLyt/MENU_FILE_LOAD_JP_ja"
    names = ("LOAD_GAME_IMG_ML_L_00_JP_ja", "LOAD_GAME_IMG_ML_R_00_JP_ja")
    fa = np.concatenate([l2.load(src / f"{n}.png") for n in names], 1)
    fb = np.concatenate([l2.load(l2.HERE / f"out/{n}.png") for n in names], 1)
    l2.sheet([[("file select: Japanese x2", l2.zoom_img(fa[:150, :, :3], 2))],
              [("Korean v2 x2", l2.zoom_img(fb[:150, :, :3], 2))]], R / "I4v2_fileload.png")
    names = ("LOAD_GAME_IMG_KJ_L_00_JP_ja", "LOAD_GAME_IMG_KJ_R_00_JP_ja")
    kja = np.concatenate([l2.load(src / f"{n}.png") for n in names], 1)
    kjb = np.concatenate([l2.load(l2.HERE / f"out/{n}.png") for n in names], 1)
    l2.sheet([[("Japanese x3", l2.zoom_img(kja[118:208, 35:300, :3], 3))],
              [("Korean x3", l2.zoom_img(kjb[118:208, 35:300, :3], 3))]], R / "I4v2_kj_logo.png")
    l2.sheet([[("Japanese", kja[..., :3]), ("Korean", kjb[..., :3])]], R / "I4v2_kj_logo_1x.png")
    fit = l2.load(l2.HERE / "fit/jp_bottom_rerender.png")
    l2.sheet([[("Japanese original", l2.zoom_img(l2.comp_on(jb)[60:145, 50:280], 3))],
              [("model re-render of the Japanese letters (material check)", l2.zoom_img(l2.comp_on(l2.q4(fit))[60:145, 50:280], 3))]],
             R / "I4v2_material_check.png")
    if (V1 / "fmdl_ko/title_logo_JP_bottom.png").exists():
        ob, ot = l2.load(V1 / "fmdl_ko/title_logo_JP_bottom.png"), l2.load(V1 / "fmdl_ko/title_logo_JP_top.png")
        l2.sheet([[("previous (v1, installed 2026-09-30)", l2.zoom_img(stack(ob, ot)[crop], 2))],
                  [("Korean v2", l2.zoom_img(stack(kb, kt)[crop], 2))]], R / "I4v2_vs_v1.png")
    print("review sheets written to work/img/review/I4v2_*.png")


if __name__ == "__main__":
    main()
