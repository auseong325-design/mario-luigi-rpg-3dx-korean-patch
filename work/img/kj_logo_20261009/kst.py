"""Korean Super Mario typeface (KST) glyphs for 쿠 파 주 니 어.

KST = the uneven sans-serif lettering Nintendo of Korea drew (~2007) for the Korean Mario logos and for the
Korean counterparts of the MARIO Font titles (Mario Party 9 minigame titles such as 「가든 배틀」 next to
ガーデンバトル, Mario Party 8/9/DS/Island Tour logos, Paper Mario: Sticker Star, Mario & Luigi: Paper Jam
「페이퍼 마리오」 ...). There is no font file, so the five syllables are drawn here from those samples:

  쿠  - 「밴쿠버」 (M&S Vancouver) and the stacked 「든」 「틀」 of 「가든 배틀」
  파  - 「마리오파티」 (Mario Party 9 logo: box ㅍ, tall ㅏ)
  어  - 「투어」 (Island Tour: round ㅇ, ㅓ tick), 「퍼」 (Paper Jam)
  주  - ㅈ from 「스」 「징」 (long left leg, short right leg), ㅜ from 「쿠」 「투」
  니  - ㄴ from 「든」 (short stem, long foot rising to the right), ㅣ from 「티」

Rules taken from 「가든 배틀」 (measured on the user's sheet, ref/web/mp9_garden_battle_sheet.png):
  * every stroke is a straight bar with square-cut ends, one thickness per glyph
    (verticals ~22-24 % of an open syllable's height, horizontals ~18-19 %)
  * counters are small (gaps ~ half a stroke), so the letters look dense
  * every jamo has its own small turn (hand-cut look), and every syllable its own turn and baseline
  * ㄱ / ㅋ = a top bar and a leg leaning down to the left like a "7"
  * horizontal vowels (ㅡ ㅜ) overhang the consonant above them on both sides
  * syllables keep roughly one width; open syllables are short and wide, stacked ones tall

Coordinates: unit height (y down), the syllable width w given as a fraction of the height.
"""
from __future__ import annotations

import math

from shapely import affinity
from shapely.geometry import Polygon, box
from shapely.ops import unary_union


def bar(p0, p1, w0, w1=None):
    """straight bar p0 -> p1 with square ends, width w0 at p0 and w1 at p1."""
    w1 = w0 if w1 is None else w1
    (x0, y0), (x1, y1) = p0, p1
    L = math.hypot(x1 - x0, y1 - y0)
    nx, ny = -(y1 - y0) / L, (x1 - x0) / L
    return Polygon([(x0 + nx * w0 / 2, y0 + ny * w0 / 2), (x1 + nx * w1 / 2, y1 + ny * w1 / 2),
                    (x1 - nx * w1 / 2, y1 - ny * w1 / 2), (x0 - nx * w0 / 2, y0 - ny * w0 / 2)]).buffer(0)


def turn(g, deg):
    return affinity.rotate(g, deg, origin="centroid")


def oval(cx, cy, rx, ry, hx, hy, p=2.6, n=48):
    """ㅇ: a superellipse ring (between a circle and the blocky bars), exponent p."""
    def poly(sx, sy):
        pts = []
        for i in range(n):
            t = 2 * math.pi * i / n
            c, s = math.cos(t), math.sin(t)
            pts.append((cx + sx * math.copysign(abs(c) ** (2 / p), c),
                        cy + sy * math.copysign(abs(s) ** (2 / p), s)))
        return Polygon(pts)
    return poly(rx, ry).difference(poly(hx, hy))


# default per-jamo turns (deg, + = clockwise on screen) - small, alternating, like the hand-cut samples
TURNS = {
    "쿠": dict(k=-2.0, u=1.5),
    "파": dict(p=2.0, a=-1.5),
    "주": dict(j=-2.0, u=2.0),
    "니": dict(n=1.5, i=-1.0),
    "어": dict(o=0.0, e=1.5),
}


def kst(ch, fv=0.23, fh=0.19, w=None, gap=None, turns=None):
    """one syllable as a shapely geometry (unit height before the jamo turns)."""
    g = gap if gap is not None else 0.5 * fh                 # counter gap
    t = dict(TURNS[ch], **(turns or {}))
    if ch == "쿠":                                          # ㅋ over ㅜ
        w = w or 0.98
        kl, kr = 0.10 * w, 0.84 * w                          # ㅋ extent
        kb = 0.50                                            # ㅋ bottom
        mb = fh + g + fh / 2                                 # ㅋ middle bar centre
        legx_top, legx_bot = kr - fv / 2, kr - fv / 2 - 0.07  # leg leans down-left
        k = unary_union([
            bar((kl, fh / 2 + 0.012), (kr, fh / 2), fh),                          # top bar (rises a little)
            bar((legx_top, 0.0), (legx_bot, kb), fv),                              # leg
            bar((kl + 0.02, mb), (legx_bot + 0.03, mb - 0.005), fh * 0.95),        # middle bar
        ]).intersection(box(-1, 0.0, 2, kb))
        ub = kb + g + fh / 2                                 # ㅜ bar centre
        u = unary_union([
            bar((0.0, ub + 0.01), (w, ub - 0.01), fh),                             # wide bar
            bar((0.52 * w, ub), (0.50 * w, 1.0), fv),                              # stem
        ]).intersection(box(-1, ub - fh, 2, 1.0))
        return unary_union([turn(k, t["k"]), turn(u, t["u"])])
    if ch == "파":                                          # ㅍ + tall ㅏ
        w = w or 1.22
        pl, pr = 0.0, 0.64 * w                               # ㅍ extent
        pt, pb = 0.14, 0.86                                  # ㅍ top / bottom
        lw = fv * 0.82                                       # legs a little lighter
        ov = max(0.09, 0.45 * lw)                            # bars overhang the legs (else it reads ㅁ)
        lx0, lx1 = pl + ov + lw / 2, pr - ov - lw / 2
        p = unary_union([
            bar((pl + 0.02, pt + fh / 2), (pr - 0.02, pt + fh / 2 - 0.01), fh),    # top bar
            bar((lx0, pt + fh / 2), (lx0 + 0.02, pb - fh / 2), lw),                # legs (lean in a hair)
            bar((lx1, pt + fh / 2), (lx1 - 0.015, pb - fh / 2), lw),
            bar((pl, pb - fh / 2 + 0.01), (pr + 0.02, pb - fh / 2 - 0.015), fh),   # bottom bar (wider)
        ])
        sx = pr + g + fv / 2 + 0.01                          # ㅏ stem centre
        a = unary_union([
            bar((sx, 0.0), (sx - 0.01, 1.0), fv),                                  # stem
            bar((sx, 0.47), (w, 0.46), fh),                                        # tick
        ])
        return unary_union([turn(p, t["p"]), turn(a, t["a"])])
    if ch == "주":                                          # ㅈ over ㅜ
        w = w or 0.98
        jb = 0.52                                            # ㅈ bottom
        top = bar((0.08 * w, fh / 2 + 0.01), (0.92 * w, fh / 2 - 0.005), fh)      # top bar
        apex = (0.50 * w, fh * 0.6)
        left = bar(apex, (0.06 * w, jb + 0.05), fv * 0.95)                         # long left leg
        mid = (apex[0] + 0.42 * (0.06 * w - apex[0]), apex[1] + 0.42 * (jb + 0.05 - apex[1]))
        right = bar(mid, (0.92 * w, jb + 0.05), fv * 0.9)                          # short right leg
        j = unary_union([top, left, right]).intersection(box(-1, 0.0, 2, jb))      # feet cut level
        ub = jb + g + fh / 2
        u = unary_union([
            bar((0.0, ub + 0.01), (w, ub - 0.01), fh),
            bar((0.50 * w, ub), (0.48 * w, 1.0), fv),
        ]).intersection(box(-1, ub - fh, 2, 1.0))
        return unary_union([turn(j, t["j"]), turn(u, t["u"])])
    if ch == "니":                                          # ㄴ + tall ㅣ
        w = w or 1.05
        sx = 0.02 + fv / 2
        fy = 0.84 - fh / 2                                   # foot centre
        fr = w - fv - g                                      # foot reaches the ㅣ gap
        n = unary_union([
            bar((sx, 0.06), (sx + 0.01, fy + fh / 2), fv),                         # stem
            bar((sx - fv / 2, fy + 0.02), (fr, fy - 0.025), fh),                   # foot rising right
        ]).intersection(box(-1, 0.0, 2, 1.0))
        i = bar((w - fv / 2, 0.0), (w - fv / 2 - 0.01, 1.0), fv)                   # ㅣ
        return unary_union([turn(n, t["n"]), turn(i, t["i"])])
    if ch == "어":                                          # round ㅇ + ㅓ
        w = w or 1.15
        sx = w - fv / 2
        rx, ry = 0.30 * w, 0.36
        cx, cy = rx, 0.50
        hx, hy = max(rx - fv * 1.05, 0.06), max(ry - fh * 1.15, 0.09)
        o = oval(cx, cy, rx, ry, hx, hy)
        e = bar((max(cx + rx + g, sx - fv / 2 - 0.20), 0.49), (sx, 0.48), fh * 0.95)  # tick, apart from ㅇ
        s = bar((sx, 0.0), (sx - 0.01, 1.0), fv)                                    # stem
        return unary_union([turn(o, t["o"]), turn(e, t["e"]), s])
    raise KeyError(ch)
