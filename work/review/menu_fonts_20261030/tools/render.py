"""Offline BFFNT text renderer for the FONT review (no game code; mirrors nn::font metrics).

Glyph placement (as nw/nn::font CharWriter): pen advances by CWDH.char * scale; the glyph cell is drawn
at pen + CWDH.left * scale; vertically the cell row TGLP.baseline sits on the line baseline, which is
FINF.ascent below the line top. Tags of the work/ko_final.json / text/jp notation are stripped
([...] blocks; [Ruby base;kana] keeps the base), icons (U+E000..F8FF) are drawn from gaizi.bffnt.
Scaled text is resampled bilinearly (the GPU samples font sheets with linear filtering).
"""
from __future__ import annotations

import re
import sys
from functools import lru_cache
from pathlib import Path

import numpy as np
from PIL import Image, ImageDraw, ImageFont

ROOT = Path(__file__).resolve().parents[4]
sys.path.insert(0, str(ROOT / "scripts"))
import libbffnt as L  # noqa: E402

PATCH = ROOT / "patch/00040000001CA900/romfs"
FONTS = {
    "jp:font": ROOT / "romfs/Msg/JP_ja/font.bffnt",
    "jp:font_l": ROOT / "romfs/Msg/JP_ja/font_l.bffnt",
    "jp:font_btl": ROOT / "romfs/Msg/JP_ja/font_btl.bffnt",
    "ko:font": PATCH / "Msg/JP_ja/font.bffnt",
    "ko:font_l": PATCH / "Msg/JP_ja/font_l.bffnt",
    "ko:font_btl": PATCH / "Msg/JP_ja/font_btl.bffnt",
    "1dx:font": ROOT / "ml 1dx/3romfs/Msg/KR_ko/font.bffnt",
    "1dx:font_l": ROOT / "ml 1dx/3romfs/Msg/KR_ko/font_l.bffnt",
    "1dx:font_btl": ROOT / "ml 1dx/3romfs/Msg/KR_ko/font_btl.bffnt",
    "1dx:font_sys": ROOT / "ml 1dx/3romfs/Msg/KR_ko/font_sys.bffnt",
    "1dx:font_sys_btl": ROOT / "ml 1dx/3romfs/Msg/KR_ko/font_sys_btl.bffnt",
    "gaizi": ROOT / "romfs/Msg/gaizi.bffnt",
    "st:font": ROOT / "work/build/menu_font_stage/romfs/Msg/JP_ja/font.bffnt",
    "st:font_btl": ROOT / "work/build/menu_font_stage/romfs/Msg/JP_ja/font_btl.bffnt",
}
TAG = re.compile(r"\[([^\[\]]*)\]")
LABEL_FONT = ROOT / "fonts/NotoSansKR-Medium.otf"


class Font:
    def __init__(self, key_or_path, data: bytes | None = None):
        p = FONTS.get(key_or_path, key_or_path)
        self.name = str(key_or_path)
        self.f = L.parse(data if data is not None else Path(p).read_bytes())
        self.si = L.SheetImages(self.f)
        self.cmap = self.f.char_map()
        self.w = self.f.widths()
        self.alt = self.cmap.get(self.f.alter_char, 0)

    def glyph(self, cp: int):
        g = self.cmap.get(cp)
        missing = g is None
        if missing:
            g = self.alt
        cw = self.w.get(g, self.f.default_width)
        return self.si.cell(g).astype(np.float32) / 15.0, cw.left, cw.glyph, cw.char, missing

    def has(self, ch: str) -> bool:
        return ord(ch) in self.cmap


@lru_cache(maxsize=None)
def get_font(key: str) -> Font:
    return Font(key)


def visible(text: str) -> str:
    out, pos = [], 0
    for m in TAG.finditer(text):
        out.append(text[pos:m.start()])
        body = m.group(1)
        if body.startswith("Ruby "):
            out.append(body[5:].split(";", 1)[0])
        elif body.startswith("U+"):
            out.append(chr(int(body[2:], 16)))
        pos = m.end()
    out.append(text[pos:])
    return "".join(out)


def draw_text(font: Font, text: str, scale: float = 1.0, line_feed: float | None = None,
              icon_font: Font | None = None) -> tuple[np.ndarray, dict]:
    """-> (alpha (h, w) float 0..1 at output pixel size, info). Lines split on \\n."""
    lines = visible(text).split("\n")
    lf = (line_feed if line_feed is not None else font.f.line_feed)
    asc = font.f.ascent
    ss = 4  # draw at 4x then box-filter: exact for integer pixel placement, bilinear-like for fractional scale
    S = scale * ss
    width_px = 0.0
    glyphs = []
    missing = []
    for li, line in enumerate(lines):
        pen = 0.0
        for ch in line:
            fnt = font
            cp = ord(ch)
            if 0xE000 <= cp <= 0xF8FF and icon_font is not None:
                fnt = icon_font
            cell, left, gw, adv, miss = fnt.glyph(cp)
            if miss:
                missing.append(ch)
            glyphs.append((li, pen + left, cell, fnt))
            pen += adv
        width_px = max(width_px, pen)
    H = int(np.ceil((lf * (len(lines) - 1) + max(font.f.cell_h, asc + 4)) * S)) + ss
    W = int(np.ceil((width_px + font.f.cell_w) * S)) + ss
    canvas = np.zeros((H, W), np.float32)
    for li, x, cell, fnt in glyphs:
        top = li * lf + asc - fnt.f.baseline  # cell row `baseline` on the line baseline
        im = Image.fromarray((cell * 255).astype(np.uint8), "L")
        tw, th = max(1, int(round(cell.shape[1] * S))), max(1, int(round(cell.shape[0] * S)))
        res = Image.NEAREST if abs(scale - round(scale)) < 1e-6 else Image.BILINEAR
        im = im.resize((tw, th), res)
        a = np.asarray(im, np.float32) / 255.0
        ox, oy = int(round(x * S)), int(round(top * S))
        if ox < 0 or oy < 0:
            continue
        h2, w2 = min(th, H - oy), min(tw, W - ox)
        canvas[oy:oy + h2, ox:ox + w2] = np.maximum(canvas[oy:oy + h2, ox:ox + w2], a[:h2, :w2])
    # back to 1x output pixels (box filter)
    h1, w1 = H // ss, W // ss
    out = canvas[:h1 * ss, :w1 * ss].reshape(h1, ss, w1, ss).mean(axis=(1, 3))
    return out, {"width": width_px * scale, "lines": len(lines), "missing": missing}


def to_rgba(alpha: np.ndarray, rgb=(0x37, 0x37, 0x37), bg=(0xF4, 0xF0, 0xE6)) -> Image.Image:
    a = alpha[..., None]
    img = np.asarray(bg, np.float32)[None, None, :] * (1 - a) + np.asarray(rgb, np.float32)[None, None, :] * a
    return Image.fromarray(np.clip(img, 0, 255).astype(np.uint8), "RGB")


def label_font(px: int = 12):
    return ImageFont.truetype(str(LABEL_FONT), px)


class Sheet:
    """Vertical stack of (label, image) rows, upscaled by an integer factor for viewing."""

    def __init__(self, zoom: int = 3, label_w: int = 260, bg=(255, 255, 255)):
        self.rows = []
        self.zoom, self.label_w, self.bg = zoom, label_w, bg

    def add(self, label: str, img: Image.Image | None, note: str = ""):
        self.rows.append((label, img, note))

    def save(self, path: Path, max_side: int = 1600):
        z = self.zoom
        lf = label_font(14)
        widths = [self.label_w + (im.width * z if im is not None else 0) + 20 for _, im, _ in self.rows]
        W = min(max(widths + [400]), max_side)
        heights = [max(22, (im.height * z if im is not None else 0) + 8) + (14 if n else 0) for _, im, n in self.rows]
        H = sum(heights) + 10
        pages = []
        cur, cur_h = [], 0
        for row, h in zip(self.rows, heights):
            if cur and cur_h + h > max_side:
                pages.append((cur, cur_h))
                cur, cur_h = [], 0
            cur.append((row, h))
            cur_h += h
        if cur:
            pages.append((cur, cur_h))
        outs = []
        for pi, (rows, ph) in enumerate(pages):
            canvas = Image.new("RGB", (W, ph + 10), self.bg)
            d = ImageDraw.Draw(canvas)
            y = 5
            for (label, im, note), h in rows:
                d.text((6, y + 2), label, fill=(0, 0, 0), font=lf)
                if note:
                    d.text((6, y + h - 16), note, fill=(90, 90, 90), font=label_font(11))
                if im is not None:
                    big = im.resize((im.width * z, im.height * z), Image.NEAREST)
                    if big.width > W - self.label_w - 10:
                        big = big.crop((0, 0, W - self.label_w - 10, big.height))
                    canvas.paste(big, (self.label_w, y + 2))
                y += h
            p = path if len(pages) == 1 else path.with_name(f"{path.stem}_{pi + 1}{path.suffix}")
            canvas.save(p)
            outs.append(p)
        return outs
