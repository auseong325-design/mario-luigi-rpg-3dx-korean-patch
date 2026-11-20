"""Glyph sources for the 「쿠파주니어」 lettering - every syllable is its own vector shape (shapely).

Sources (all in "design units": y down, cap line y = 0, the syllable's height in units = its cap height):
  font(name, ch)   outline of a font glyph (fontTools, curves flattened finely)
  dx1_kr(ch)       the official 1DX Korean 「쿠파군단 RPG」 쿠 / 파 (MLyt KG_LOGO_TEXT_L_12_KR_ko), vectorised
  mario_kr(ch)     the Korean MARIO Font assembled from Nintendo of Korea's 「슈퍼 마리오 RPG」 subtitle
                   (work/img/logo2/kj_mario.py)
  skel_1dx(ch)     the 1DX 쿠 / 파 skeleton (bar centre lines measured on the 1DX logo) redrawn as straight
                   bars of the Japanese letters' weight with chisel-cut ends; 주 니 어 built from the same
                   bar system
Also: svg_path(geom) and write_svg(...) so every result stays editable.
"""
from __future__ import annotations

import math
import sys
from pathlib import Path

import cv2
import numpy as np
from fontTools.pens.basePen import BasePen
from fontTools.ttLib import TTFont
from scipy import ndimage as ndi
from shapely import affinity
from shapely.geometry import MultiPolygon, Polygon
from shapely.ops import unary_union

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
sys.path.insert(0, str(ROOT / "work/img/logo2"))
import l2  # noqa: E402

FONTS = {
    "cafe24": HERE / "ref/cafe24/Cafe24Ssurround-v2.0.ttf",
    "blackhan": ROOT / "fonts/BlackHanSans-Regular.ttf",
    "jua": ROOT / "fonts/Jua-Regular.ttf",
    "dohyeon": ROOT / "fonts/DoHyeon-Regular.ttf",
    "mario_jp": ROOT / "work/img/logo2/ref/MARIO_Font_v3_Solid.otf",
}


# ----------------------------------------------------------------------------- font outlines
class _PolyPen(BasePen):
    def __init__(self, glyphset, steps=12):
        super().__init__(glyphset)
        self.contours, self.cur, self.steps = [], [], steps

    def _moveTo(self, p):
        self.cur = [p]

    def _lineTo(self, p):
        self.cur.append(p)

    def _curveToOne(self, p1, p2, p3):
        p0 = self.cur[-1]
        for t in np.linspace(0, 1, self.steps + 1)[1:]:
            u = 1 - t
            self.cur.append((u ** 3 * p0[0] + 3 * u * u * t * p1[0] + 3 * u * t * t * p2[0] + t ** 3 * p3[0],
                             u ** 3 * p0[1] + 3 * u * u * t * p1[1] + 3 * u * t * t * p2[1] + t ** 3 * p3[1]))

    def _qCurveToOne(self, p1, p2):
        p0 = self.cur[-1]
        for t in np.linspace(0, 1, self.steps + 1)[1:]:
            u = 1 - t
            self.cur.append((u * u * p0[0] + 2 * u * t * p1[0] + t * t * p2[0],
                             u * u * p0[1] + 2 * u * t * p1[1] + t * t * p2[1]))

    def _closePath(self):
        if len(self.cur) >= 3:
            self.contours.append(self.cur)
        self.cur = []

    _endPath = _closePath


_FONT_CACHE = {}


def font(name, ch):
    """glyph outline, flipped to y down; returned in font units (call normalise() afterwards)."""
    if name not in _FONT_CACHE:
        _FONT_CACHE[name] = TTFont(str(FONTS[name]))
    f = _FONT_CACHE[name]
    gs = f.getGlyphSet()
    gname = f.getBestCmap()[ord(ch)]
    pen = _PolyPen(gs)
    gs[gname].draw(pen)
    # even-odd assembly: sort by area, holes are contours inside others
    polys = [Polygon([(x, -y) for x, y in c]).buffer(0) for c in pen.contours]
    polys = [p for p in polys if p.area > 1]
    polys.sort(key=lambda p: -p.area)
    shape = None
    for p in polys:
        if shape is None:
            shape = p
        elif shape.contains(p.representative_point()) and shape.buffer(-1e-6).contains(p):
            shape = shape.difference(p)
        else:
            shape = shape.union(p)
    return shape


def normalise(g, height=None):
    """move to cap line y = 0 / left x = 0; optionally scale to the given height."""
    b = g.bounds
    g = affinity.translate(g, -b[0], -b[1])
    if height:
        s = height / (b[3] - b[1])
        g = affinity.scale(g, s, s, origin=(0, 0))
    return g


# ----------------------------------------------------------------------------- 1DX Korean logo
def _vectorise(cov, up=8, eps=0.4, x0=0, y0=0):
    big = ndi.zoom(cov, up, order=3, grid_mode=True, mode="nearest") > 0.5
    cnts, hier = cv2.findContours(big.astype(np.uint8), cv2.RETR_CCOMP, cv2.CHAIN_APPROX_NONE)
    out = []
    for i, c in enumerate(cnts):
        if hier[0][i][3] != -1:
            continue
        ap = cv2.approxPolyDP(c, eps * up, True)[:, 0, :].astype(float)
        if len(ap) < 3:
            continue
        holes, j = [], hier[0][i][2]
        while j != -1:
            h = cv2.approxPolyDP(cnts[j], eps * up, True)[:, 0, :].astype(float)
            if len(h) >= 3:
                holes.append([(x / up + x0, y / up + y0) for x, y in h])
            j = hier[0][j][0]
        p = Polygon([(x / up + x0, y / up + y0) for x, y in ap], holes).buffer(0)
        if p.area > 3:
            out.append(p)
    return unary_union(out)


def dx1_kr(ch):
    """쿠 / 파 of the 1DX Korean 「쿠파군단 RPG」 logo (dark letters on transparent)."""
    t = l2.load(ROOT / "work/img/lyt/1DX/MLyt/MLYT_MAIN_KR_ko/KG_LOGO_TEXT_L_12_KR_ko.png")
    rgb, al = t[..., :3], t[..., 3]
    dark = np.clip((170 - rgb.max(2)) / 60, 0, 1) * np.clip((al - 100) / 100, 0, 1)
    boxes = {"쿠": (110, 156, 48, 93), "파": (154, 200, 50, 86)}
    x0, x1, y0, y1 = boxes[ch]
    cov = np.zeros_like(dark)
    cov[y0:y1, x0:x1] = dark[y0:y1, x0:x1]
    if ch == "파":
        cov[:, 199:] = 0                   # 군 starts right after the ㅏ tick
    return _vectorise(cov)


def mario_kr(ch):
    import kj_mario
    return kj_mario.syllables()[ch]


# ----------------------------------------------------------------------------- 1DX skeleton, heavy
def bar(p0, p1, w0, w1=None, cut0=0.0, cut1=0.0):
    """straight bar p0 -> p1, width w0 / w1, ends cut cut0 / cut1 degrees off square (chisel)."""
    w1 = w0 if w1 is None else w1
    (x0, y0), (x1, y1) = p0, p1
    L = math.hypot(x1 - x0, y1 - y0)
    ux, uy = (x1 - x0) / L, (y1 - y0) / L
    nx, ny = -uy, ux

    def end(px, py, w, cut):
        t = math.tan(math.radians(cut))
        return ((px + nx * w / 2 + ux * t * w / 2, py + ny * w / 2 + uy * t * w / 2),
                (px - nx * w / 2 - ux * t * w / 2, py - ny * w / 2 - uy * t * w / 2))

    a0, b0 = end(x0, y0, w0, cut0)
    a1, b1 = end(x1, y1, w1, cut1)
    return Polygon([a0, a1, b1, b0]).buffer(0)


def ring(cx, cy, rx, ry, hole_rx, hole_ry, n=8, rot=22.5, jit=()):
    def poly(sx, sy):
        pts = []
        for i in range(n):
            a = math.radians(rot + 360 * i / n)
            j = 1 + (jit[i] if i < len(jit) else 0)
            pts.append((cx + sx * j * math.cos(a), cy + sy * j * math.sin(a)))
        return Polygon(pts)
    return poly(rx, ry).difference(poly(hole_rx, hole_ry))


# The 1DX 쿠 / 파 skeleton (sheets/ref_1dx_kupa_grid.png): straight bars of one width, ㅋ = ㄱ + middle
# bar, the ㅜ stem long below its bar, the ㅍ legs between a top and a bottom bar (the bottom bar rises
# to the right), the ㅏ stem taller than the ㅍ. Redrawn on a unit cap height with the Japanese letters'
# weight (MARIO Font: verticals ~26 %, horizontals ~19 % of the height), chisel-cut ends, the gaps
# computed so the counters stay open. 주 니 어 use the same bars. fv / fh = stroke fractions of the
# height, w = width / height. Returned with height ~1 (scale afterwards).
def skel_1dx(ch, fv=0.26, fh=0.19, w=None):
    c = 12.0                                   # chisel angle of the ends (deg)
    if ch == "쿠":
        w = w or 1.0
        mb = fh + 0.12 + fh / 2                # ㅋ middle bar centre (gap 0.12 under the top bar)
        ub = mb + fh / 2 + 0.09 + fh / 2       # ㅜ bar centre
        sx = w * 0.88 - fv / 2                 # ㅋ stem centre
        return unary_union([
            bar((0.08 * w, fh / 2), (w * 0.88, fh / 2 + 0.015), fh, fh, -c, 0),     # ㅋ top bar
            bar((sx, 0.0), (sx - 0.02, mb + fh / 2), fv, fv, 0, c),                 # ㅋ stem
            bar((0.10 * w, mb), (sx, mb + 0.005), fh * 0.95, fh * 0.95, -c, 0),     # ㅋ middle bar
            bar((0.0, ub + 0.012), (w, ub - 0.012), fh, fh, c * 0.7, -c * 0.7),     # ㅜ bar
            bar((w * 0.5, ub), (w * 0.49, 1.0), fv, fv, 0, c),                      # ㅜ stem
        ])
    if ch == "파":
        w = w or 1.15
        pw = 0.64 * w                          # ㅍ width
        bb = 0.84 - fh / 2                     # ㅍ bottom bar centre
        lx0, lx1 = pw * 0.26, pw * 0.74        # ㅍ legs
        sx = pw + 0.07 + fv / 2                # ㅏ stem
        return unary_union([
            bar((0.0, fh / 2 + 0.04), (pw, fh / 2 + 0.03), fh, fh, -c, c * 0.5),    # ㅍ top bar
            bar((lx0, 0.04 + fh / 2), (lx0 + 0.01, bb), fv * 0.82, fv * 0.82),      # ㅍ legs
            bar((lx1, 0.04 + fh / 2), (lx1 + 0.01, bb), fv * 0.82, fv * 0.82),
            bar((0.0, bb + 0.02), (pw + 0.04, bb - 0.03), fh, fh, c * 0.7, -c),     # ㅍ bottom bar
            bar((sx, -0.05), (sx - 0.01, 1.0), fv, fv, -c, c * 0.7),                # ㅏ stem (taller)
            bar((sx, 0.47), (sx + fv / 2 + 0.13, 0.46), fh * 0.9, fh * 0.9, 0, -c),  # ㅏ tick
        ])
    if ch == "주":
        w = w or 1.0
        ub = 0.60 + fh / 2
        from shapely.geometry import box as _b
        legs = unary_union([bar((0.5 * w, fh * 0.6), (0.11 * w, 0.52), fv * 0.82, fv * 0.82),
                            bar((0.5 * w, fh * 1.0), (0.89 * w, 0.52), fv * 0.78, fv * 0.78)])
        legs = legs.intersection(_b(-1, -1, w + 1, 0.48))                          # ends cut level
        return unary_union([
            bar((0.02 * w, fh / 2), (0.98 * w, fh / 2 - 0.01), fh, fh, -c, c),      # ㅈ top bar
            legs,                                                                   # ㅈ legs (ㅅ)
            bar((0.0, ub + 0.012), (w, ub - 0.012), fh, fh, c * 0.7, -c * 0.7),     # ㅜ bar
            bar((w * 0.5, ub), (w * 0.49, 1.0), fv, fv, 0, c),                      # ㅜ stem
        ])
    if ch == "니":
        w = w or 0.80
        sx = 0.06 + fv / 2
        fy = 0.90 - fh / 2
        return unary_union([
            bar((sx, 0.06), (sx + 0.01, fy + fh / 2), fv, fv, -c, 0),               # ㄴ stem
            bar((sx - fv / 2, fy), (0.56 * w, fy - 0.01), fh, fh, 0, c),            # ㄴ foot
            bar((w - fv / 2, -0.05), (w - fv / 2 - 0.01, 1.0), fv, fv, c, -c * 0.7),  # ㅣ (taller)
        ])
    if ch == "어":
        w = w or 1.0
        rx, ry = 0.31 * w, 0.42
        cx, cy = rx, 0.50
        hx, hy = max(rx - fv * 1.02, 0.07), max(ry - fh * 1.15, 0.11)
        sx = w - fv / 2
        return unary_union([
            ring(cx, cy, rx, ry, hx, hy, n=8, rot=22.5,                             # angular ㅇ
                 jit=(0.02, -0.03, 0.03, 0.0, -0.02, 0.03, 0.0, -0.02)),
            bar((cx + rx - 0.02, cy), (sx, cy - 0.005), fh * 0.9, fh * 0.9),        # ㅓ tick
            bar((sx, -0.05), (sx - 0.01, 1.0), fv, fv, c, -c * 0.7),                # ㅓ stem (taller)
        ])
    raise KeyError(ch)


# ----------------------------------------------------------------------------- SVG
def svg_path(g, fmt="{:.2f}"):
    polys = g.geoms if isinstance(g, MultiPolygon) else [g]
    parts = []
    for p in polys:
        for ring_ in [p.exterior, *p.interiors]:
            pts = list(ring_.coords)[:-1]
            parts.append("M" + " L".join(f"{fmt.format(x)},{fmt.format(y)}" for x, y in pts) + " Z")
    return " ".join(parts)


def write_svg(path, items, width, height, background=None, note=""):
    """items: list of dict(id, geom, fill, opacity, stroke) in the SVG's own px units."""
    out = [f'<svg xmlns="http://www.w3.org/2000/svg" width="{width}" height="{height}" '
           f'viewBox="0 0 {width} {height}">']
    if note:
        out.append(f"<!-- {note} -->")
    if background is not None:
        out.append(background)
    for it in items:
        attrs = f'fill="{it.get("fill", "#000")}" fill-rule="evenodd"'
        if it.get("opacity") is not None:
            attrs += f' fill-opacity="{it["opacity"]}"'
        if it.get("stroke"):
            attrs += f' stroke="{it["stroke"]}" stroke-width="{it.get("stroke_width", 0.3)}"'
        label = f' data-label="{it["label"]}"' if it.get("label") else ""
        out.append(f'<path id="{it["id"]}"{label} {attrs} d="{svg_path(it["geom"])}"/>')
    out.append("</svg>")
    Path(path).write_text("\n".join(out), encoding="utf-8")


def raster(geom, shape, up=8, offset=(0.0, 0.0)):
    """1x coverage (0..1) of a geometry on an (H, W) texture grid."""
    from PIL import Image, ImageDraw
    H, W = shape
    img = Image.new("L", (W * up, H * up), 0)
    d = ImageDraw.Draw(img)
    polys = geom.geoms if isinstance(geom, MultiPolygon) else [geom]
    ox, oy = offset
    for p in polys:
        if p.is_empty:
            continue
        d.polygon([((x + ox) * up - 0.5, (y + oy) * up - 0.5) for x, y in p.exterior.coords], fill=255)
        for h in p.interiors:
            d.polygon([((x + ox) * up - 0.5, (y + oy) * up - 0.5) for x, y in h.coords], fill=0)
    a = np.asarray(img).astype(float) / 255
    return a.reshape(H, up, W, up).mean((1, 3))
