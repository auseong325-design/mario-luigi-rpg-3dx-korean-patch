"""Review sheets for stream I4 -> work/img/review/I4_*.png (every sheet <= 1600 px a side)."""
import sys
from pathlib import Path
import numpy as np
sys.path.insert(0, str(Path(__file__).parent))
import logo_lib as L
import review as V

ROOT = Path(__file__).resolve().parents[3]
RV = ROOT / "work/img/review"
RV.mkdir(parents=True, exist_ok=True)
J = ROOT / "work/img/fmdl/3DX/fmd_title_JP_ja"
O = ROOT / "work/img/logo/out"
ST = ROOT / "work/img/logo/steps"
FIT = ROOT / "work/img/logo/fit"
SKY, DARK, WHITE = (70, 130, 220, 255), (20, 20, 40, 255), (255, 255, 255, 255)


def over(a, b):
    """b over a (both RGBA float)."""
    A = b[..., 3:] / 255
    rgb = b[..., :3] * A + a[..., :3] * (a[..., 3:] / 255) * (1 - A)
    al = b[..., 3:] + a[..., 3:] * (1 - A)
    return np.concatenate([np.where(al > 0, rgb * 255 / np.maximum(al, 1e-6), 255), al], 2)


def main():
    jb, jt = L.load(J / "title_logo_JP_bottom.png"), L.load(J / "title_logo_JP_top.png")
    kb, kt = L.load(O / "title_logo_JP_bottom.png"), L.load(O / "title_logo_JP_top.png")
    jall, kall = over(jb, jt), over(kb, kt)
    V.sheet([("original (bottom+top layers)", jall), ("Korean", kall)], RV / "I4_title_logo_1x.png",
            crop=(0, 0, 512, 256), bgs=(SKY, DARK))
    V.sheet([("original", jall), ("Korean", kall)], RV / "I4_title_logo_zoom_left.png", scale=3, crop=(20, 10, 270, 160))
    V.sheet([("original", jall), ("Korean", kall)], RV / "I4_title_logo_zoom_right.png", scale=3, crop=(250, 30, 480, 240))
    V.sheet([("1 skeleton (1DX faces placed)", L.load(ST / "bottom_1_skeleton.png")),
             ("2 body+fill, no gloss", L.load(ST / "bottom_2_body_fill.png"))],
            RV / "I4_title_logo_steps_1-2.png", scale=2, crop=(20, 10, 300, 160))
    V.sheet([("3 model (gloss added)", L.load(ST / "bottom_3_model.png")),
             ("4 final (& / RPG / silhouettes)", kb)], RV / "I4_title_logo_steps_3-4.png", scale=2, crop=(20, 10, 300, 160))
    V.sheet([("JP original", jb), ("JP re-drawn by the fitted model", L.load(FIT / "rerender_bottom.png"))],
            RV / "I4_title_logo_fitcheck.png", scale=3, crop=(40, 60, 290, 150))
    V.sheet([("original", jt), ("Korean", kt)], RV / "I4_title_top_deluxe.png", scale=6, crop=(195, 185, 310, 230))
    for t, nm in (("title_logo_M_JP", "M"), ("title_logo_L_JP", "L")):
        V.sheet([("original", L.load(J / f"{t}.png")), ("JP re-drawn (model check)", L.load(FIT / f"rerender_{t}.png")),
                 ("Korean", L.load(O / f"{t}.png"))], RV / f"I4_title_piece_{nm}.png", scale=4, bgs=(SKY, DARK))
    st0 = L.load(ROOT / "work/img/fmdl/3DX/fmd_title_start_JP_ja/st.png")
    V.sheet([("original", st0), ("text erased", L.load(ST / "st_2_panel_erased.png")), ("Korean", L.load(O / "st.png"))],
            RV / "I4_title_start_button.png", scale=2)
    V.sheet([("original", st0), ("Korean", L.load(O / "st.png"))], RV / "I4_title_start_button_zoom.png", scale=5,
            crop=(55, 12, 205, 55))
    src = ROOT / "work/img/lyt/3DX/MLyt/MENU_FILE_LOAD_JP_ja"
    ko = ROOT / "work/img/ko/lyt/MLyt/MENU_FILE_LOAD_JP_ja"
    for k in ("ML", "KJ"):
        a = np.concatenate([L.load(src / f"LOAD_GAME_IMG_{k}_L_00_JP_ja.png"), L.load(src / f"LOAD_GAME_IMG_{k}_R_00_JP_ja.png")], 1)
        b = np.concatenate([L.load(ko / f"LOAD_GAME_IMG_{k}_L_00_JP_ja.png"), L.load(ko / f"LOAD_GAME_IMG_{k}_R_00_JP_ja.png")], 1)
        V.sheet([("original (L|R joined)", a), ("Korean", b)], RV / f"I4_fileload_{k}_1x.png", bgs=(WHITE,))
        crop = (15, 10, 240, 100) if k == "ML" else (40, 125, 290, 208)
        V.sheet([("original", a), ("Korean", b)], RV / f"I4_fileload_{k}_zoom.png", scale=3, crop=crop, bgs=(WHITE,))
        # the L|R seam at x=144
        V.sheet([("original seam x=144", a), ("Korean seam x=144", b)], RV / f"I4_fileload_{k}_seam.png", scale=6,
                crop=(124, 20 if k == "ML" else 130, 164, 100 if k == "ML" else 208), bgs=(WHITE,))
    # glyph sources
    kr = L.load(ROOT / "work/img/logo/src/1DX/kr_logo_rgba.png")
    kg = L.load(ROOT / "work/img/lyt/1DX/MLyt/MLYT_MAIN_KR_ko/KG_LOGO_TEXT_L_12_KR_ko.png")
    V.sheet([("1DX KR title logo (glyph source)", kr)], RV / "I4_src_1DX_title_logo.png", crop=(0, 0, 512, 256), bgs=(SKY,))
    V.sheet([("1DX 쿠파군단 RPG logo (glyph source)", kg)], RV / "I4_src_1DX_KG_logo.png", bgs=(SKY,))
    sk = L.load(ROOT / "work/img/logo/kr_skeleton/kupa_junior.png") if False else None
    from PIL import Image
    m = np.asarray(Image.open(ROOT / "work/img/logo/kr_skeleton/kupa_junior.png").convert("L")).astype(float)
    mm = np.zeros(m.shape + (4,)); mm[..., :3] = 255; mm[..., 3] = m
    V.sheet([("쿠파주니어 skeleton: 쿠파 = 1DX, 주니어 = its strokes", mm)], RV / "I4_src_kupa_junior_skeleton.png", bgs=(DARK,))
    for p in sorted(RV.glob("I4_*.png")):
        from PIL import Image as I
        w, h = I.open(p).size
        print(p.name, w, h)


if __name__ == "__main__":
    main()
