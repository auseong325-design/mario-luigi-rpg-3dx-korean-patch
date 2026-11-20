"""Step 1 - analysis of the Japanese 「クッパJr.」 lettering (file-select logo, MLyt MENU_FILE_LOAD_JP_ja,
LOAD_GAME_IMG_KJ_L/R_00_JP_ja, 144+256 x 208, RGB565 opaque).

Every Japanese letter is a MARIO Font glyph placed on its own (own size, own turn, own height). Each
letter's face (orange) is fitted with its MARIO Font glyph (scale, rotation, position, by IoU at 8x), which
gives the exact lettering parameters and a vector outline of every original letter (for the overlays).

Writes analysis.json, analysis.md, jp_letters.svg and sheets/analysis_*.png.
"""
from __future__ import annotations

import json
import math
import sys
from pathlib import Path

import numpy as np
from PIL import Image, ImageDraw, ImageFont
from scipy import ndimage as ndi

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
sys.path.insert(0, str(ROOT / "work/img/logo2"))
import l2  # noqa: E402

SRC = ROOT / "work/img/lyt/3DX/MLyt/MENU_FILE_LOAD_JP_ja"
FONT = ROOT / "work/img/logo2/ref/MARIO_Font_v3_Solid.otf"
UP = 8
# face components (1x, see analysis) grouped into the letters of クッパJr. and the ruby ジュニア
LETTERS = [("ク", (66, 103, 150, 190)), ("ッ", (100, 124, 165, 190)), ("パ", (121, 157, 152, 188)),
           ("J", (154, 183, 150, 182)), ("r", (181, 202, 164, 181)), (".", (196, 207, 178, 190))]
RUBY = (162, 192, 180, 190)


def load_jp():
    return np.concatenate([l2.load(SRC / f"{n}.png") for n in ("LOAD_GAME_IMG_KJ_L_00_JP_ja",
                                                               "LOAD_GAME_IMG_KJ_R_00_JP_ja")], 1)


def face_mask(a):
    rgb = a[..., :3]
    r, g, b = rgb[..., 0], rgb[..., 1], rgb[..., 2]
    yy, xx = np.mgrid[0:a.shape[0], 0:a.shape[1]]
    return (r > 180) & (r - g > 60) & (b < 170) & (yy > 135) & (yy < 200) & (xx < 206)


def glyph_img(ch, px=400):
    f = ImageFont.truetype(str(FONT), px)
    im = Image.new("L", (int(px * 1.6), int(px * 1.6)), 0)
    ImageDraw.Draw(im).text((px * 0.3, px * 0.3), ch, font=f, fill=255)
    m = np.asarray(im) > 127
    ys, xs = np.nonzero(m)
    return m[ys.min():ys.max() + 1, xs.min():xs.max() + 1]


def fit_letter(ch, target_up):
    """target_up: 8x bool mask of one letter (cropped frame). Search scale / rotation / shift."""
    g = glyph_img(ch)
    th, tw = target_up.shape
    ty, tx = np.nonzero(target_up)
    tcy, tcx = ty.mean(), tx.mean()
    t_area = target_up.sum()
    best = None
    for ang in np.arange(-24, 24.1, 1.0):
        gr = ndi.rotate(g.astype(float), ang, reshape=True, order=1) > 0.5
        gy, gx = np.nonzero(gr)
        g_area = gr.sum()
        s0 = math.sqrt(t_area / g_area)
        for s in s0 * np.array([0.9, 0.95, 1.0, 1.05, 1.1]):
            gs = ndi.zoom(gr.astype(float), s, order=1) > 0.5
            if gs.shape[0] > th * 1.6 or gs.shape[1] > tw * 1.6:
                continue
            sy, sx = np.nonzero(gs)
            cy, cx = sy.mean(), sx.mean()
            for dy in (-4, 0, 4):
                for dx in (-4, 0, 4):
                    oy = int(round(tcy - cy + dy))
                    ox = int(round(tcx - cx + dx))
                    canvas = np.zeros_like(target_up)
                    yy, xx = sy + oy, sx + ox
                    ok = (yy >= 0) & (yy < th) & (xx >= 0) & (xx < tw)
                    canvas[yy[ok], xx[ok]] = True
                    iou = (canvas & target_up).sum() / (canvas | target_up).sum()
                    if best is None or iou > best[0]:
                        best = (iou, ang, s, oy, ox, canvas)
    return best


def main():
    a = load_jp()
    F = face_mask(a)
    out = {"letters": [], "ruby": None}
    overlay_cells = []
    for ch, (x0, x1, y0, y1) in LETTERS:
        m = F[y0:y1, x0:x1]
        lab, n = ndi.label(m)
        sizes = ndi.sum(m, lab, range(1, n + 1))
        m = np.isin(lab, 1 + np.nonzero(sizes >= 3)[0])
        up = ndi.zoom(m.astype(float), UP, order=1) > 0.5
        iou, ang, s, oy, ox, canvas = fit_letter(ch, up)
        ys, xs = np.nonzero(m)
        em_px = 400 * s / UP           # MARIO Font em size in texture px
        rec = dict(letter=ch, bbox=[int(xs.min() + x0), int(ys.min() + y0), int(xs.max() + x0 + 1),
                                    int(ys.max() + y0 + 1)],
                   height=int(ys.max() - ys.min() + 1), width=int(xs.max() - xs.min() + 1),
                   rotation_deg=float(-ang), font_em_px=round(em_px, 1), iou=round(float(iou), 3),
                   ink_px=int(m.sum()))
        out["letters"].append(rec)
        print(rec)
        vis = np.zeros(up.shape + (3,))
        vis[up] = (255, 120, 0)
        vis[canvas] = vis[canvas] * 0.5 + np.array([0, 160, 255]) * 0.5
        overlay_cells.append((f"{ch} IoU {iou:.2f} rot {-ang:+.0f}", vis))
    rm = F[RUBY[2]:RUBY[3], RUBY[0]:RUBY[1]]
    ys, xs = np.nonzero(rm)
    out["ruby"] = dict(text="ジュニア", bbox=[int(xs.min() + RUBY[0]), int(ys.min() + RUBY[2]),
                                            int(xs.max() + RUBY[0] + 1), int(ys.max() + RUBY[2] + 1)],
                       height=int(ys.max() - ys.min() + 1), colour="red on the white ring")
    # ring structure measured on the straight edges (2026-10-02, build_kj.py notes)
    out["rings"] = dict(face="orange (239, 72..92, 0), darker at the top; fine diagonal hatching; 1 px red rim "
                             "(214, 18, 0) on edges facing down/right; pink anti-aliasing into the white",
                        white="0 .. 2.4 px from the face (last px tinted yellow)",
                        yellow="2.4 .. 3.6 px (255, 255, 112), olive where it meets the maroon",
                        maroon="3.6 .. 6.9 px, darker inside and on top edges, redder outside / at the bottom",
                        corners="every ring is a sharp (mitre) offset of the letter outline")
    out["layout"] = dict(word_bbox=[int(min(r["bbox"][0] for r in out["letters"])),
                                    int(min(r["bbox"][1] for r in out["letters"])),
                                    int(max(r["bbox"][2] for r in out["letters"])),
                                    int(max(r["bbox"][3] for r in out["letters"]))],
                         R_face_left=212, puffs=[[44, 122, 92, 162], [196, 184, 230, 208]])
    (HERE / "analysis.json").write_text(json.dumps(out, ensure_ascii=False, indent=1), encoding="utf-8")
    (HERE / "sheets").mkdir(exist_ok=True)
    rows = [overlay_cells[:3], overlay_cells[3:]]
    l2.sheet(rows, HERE / "sheets/analysis_fit.png")
    # face-mask / ink view of the whole word
    vis = np.full(a.shape[:2] + (3,), 255.0)
    vis[F] = (255, 110, 0)
    l2.sheet([[("original x3", l2.zoom_img(a[120:205, 35:260, :3], 3))],
              [("orange faces only x3", l2.zoom_img(vis[120:205, 35:260], 3))]], HERE / "sheets/analysis_faces.png")


if __name__ == "__main__":
    main()
