"""Review sheets for the glyph approval (no colour work yet):
  sheets/refs.png      3DX 일본판 クッパJr. / 1DX 일본판 クッパ軍団 / 1DX 한국판 쿠파군단
  sheets/approval.png  A안 · B안 side by side: silhouettes, overlay, in place at real size
  sheets/kst_approval.png  the same for KA안 · KB안 (Korean Super Mario typeface, kst.py)
  sheets/official_approval.png  the same for OA안 · OB안 (the official 「쿠파주니어」 glyphs, fit_official.py)
"""
from __future__ import annotations

import numpy as np
from PIL import Image

import design as D
import glyphs as G
import sheet as SH

HERE = G.HERE


def rgb_on_white(path, crop=None, scale=1.0):
    im = Image.open(path).convert("RGBA")
    if crop:
        im = im.crop(crop)
    bg = Image.new("RGBA", im.size, (255, 255, 255, 255))
    bg.alpha_composite(im)
    if scale != 1.0:
        bg = bg.resize((int(bg.width * scale), int(bg.height * scale)), Image.LANCZOS)
    return np.asarray(bg.convert("RGB")).astype(float)


def main():
    a = D.load_jp()
    jp = G.l2.zoom_img(a[120:208, 35:260, :3], 3)
    dx_jp = rgb_on_white(HERE / "ref/web/1dx_jp_kgrpg_logo.png", (60, 360, 470, 520), 1.4)
    dx_kr = rgb_on_white(G.ROOT / "work/img/lyt/1DX/MLyt/MLYT_MAIN_KR_ko/KG_LOGO_TEXT_L_12_KR_ko.png",
                         (90, 20, 320, 200), 2.4)
    SH.sheet([[("① 3DX 일본판 「クッパJr.RPG」 (원본, x3)", jp)],
              [("④ 1DX 일본판 「クッパ軍団RPG」 (공식 사이트)", dx_jp), ("③ 1DX 한국판 「쿠파군단 RPG」 (게임 데이터, x2.4)", dx_kr)]],
             HERE / "sheets/refs.png")
    for plans, out in ((("A", "B"), "approval.png"), (("KA", "KB"), "kst_approval.png"),
                       (("OA", "OB"), "official_approval.png")):
        rows = []
        for p in plans:
            cmp_ = np.asarray(Image.open(HERE / f"sheets/{p}_compare.png").convert("RGB")).astype(float)
            inp = np.asarray(Image.open(HERE / f"sheets/{p}_inplace.png").convert("RGB")).astype(float)
            rows.append([(f"{p}안 비교", cmp_), (f"{p}안 배치", inp)])
        SH.sheet(rows, HERE / f"sheets/{out}")


if __name__ == "__main__":
    main()
