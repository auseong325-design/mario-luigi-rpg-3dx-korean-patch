"""Clean vector 쿠 파 주 니 어 fitted to the official 「쿠파주니어」 lettering.

The orange sample (ref/web/official/kupajunior_orange.png) is a 2x nearest-neighbour blow-up of a
161 x 56 texture: the syllables are ~28 px wide, the strokes ~4.5 px. Tracing its outline would carry the
pixel steps into the vector, so every syllable is rebuilt from its strokes and the stroke parameters are
fitted to the official face coverage at its own resolution (least squares on the anti-aliased coverage,
Powell).

Stroke model (native px of the orange sample): bent strokes (the ㄱ of ㅋ, ㄴ, ㅅ) are one polyline with
mitred corners; an end that runs into another stroke is tied to that stroke's centre line (a parameter t
along it), so no end can stick out of the stroke it joins. Start values come from a first free-bar fit and
the native pixels (README 6장):
  쿠  ㅋ top bar falling ~5 deg to the right, upright leg, middle bar running into the leg; ㅜ bar + stem
  파  ㅍ top bar, two legs, bottom bar rising to the right into the ㅏ stem; ㅏ tick at mid height
  주  ㅈ top bar, ㅅ = a long left leg from under the bar and a right leg branching off its top; ㅜ
  니  ㄴ stem, foot rising to the right into the ㅣ
  어  ㅇ ring (superellipse), tick joining it to the stem

Writes official_fit.json and sheets/official_fit.png. glyph(ch) returns the fitted syllable (box at 0, 0);
all five share one scale (native px), strokes(ch) its named strokes.
"""
from __future__ import annotations

import functools
import json
import math

import numpy as np
from scipy import ndimage as ndi
from scipy.optimize import minimize
from shapely import affinity
from shapely.geometry import LineString, Polygon
from shapely.ops import unary_union

import glyphs as G
import official as O

HERE = G.HERE
FIT_JSON = HERE / "official_fit.json"

INIT = {
    "쿠": dict(ax=11.2, ay=18.3, cx=30.0, cy=20.2, dx=28.5, dy=30.0, wk=4.5,
               mx=9.8, my=24.7, mt=0.52, wm=4.37,
               u0x=7.75, u0y=32.87, u1x=35.64, u1y=32.86, wu=4.32, st=0.486, sbx=21.5, sby=44.0, ws=4.5),
    "파": dict(p0x=39.1, p0y=21.3, p1x=57.6, p1y=21.35, wt=4.06,
               q0x=38.7, q0y=35.56, qt=0.737, wb=4.44,
               l0=0.24, l1=0.266, wl=4.19, r0=0.69, r1=0.57, wr=4.4,
               s0x=61.05, s0y=18.31, s1x=60.14, s1y=39.05, ws=4.38, tt=0.48, tex=67.26, tey=28.86, wti=4.45),
    "주": dict(j0x=73.14, j0y=18.01, j1x=93.59, j1y=18.01, wj=3.87,
               at=0.507, lx=73.3, ly=29.39, wl=4.45, rb=0.15, rx=95.0, ry=27.55, wr=4.25,
               u0x=69.73, u0y=32.87, u1x=98.0, u1y=32.86, wu=4.17, st=0.48, sbx=83.45, sby=44.07, ws=4.51),
    "니": dict(nx=103.25, ny=20.55, cx=105.9, cy=35.1, ft=0.587, wn=4.35,
               i0x=124.28, i0y=18.62, i1x=124.02, i1y=39.05, wi=4.38),
    "어": dict(cx=140.31, cy=28.37, rx=9.34, ry=8.95, tx=4.39, ty=4.37, p=2.09, rot=-0.24,
               ky=27.77, kt=0.44, wk=4.54, s0x=155.43, s0y=18.33, s1x=154.89, s1y=39.04, ws=4.29),
}


def stroke(points, w):
    """polyline with flat ends and mitred corners."""
    return LineString(points).buffer(w / 2, cap_style=2, join_style=2, mitre_limit=6.0)


def on(p0, p1, t):
    return (p0[0] + (p1[0] - p0[0]) * t, p0[1] + (p1[1] - p0[1]) * t)


def below(p0, p1, w):
    """the half plane under the top edge of the bar p0-p1 (width w), as a big polygon."""
    L = math.hypot(p1[0] - p0[0], p1[1] - p0[1])
    ux, uy = (p1[0] - p0[0]) / L, (p1[1] - p0[1]) / L
    nx, ny = uy, -ux                                    # pointing up (y down)
    a = (p0[0] + nx * w / 2 - ux * 100, p0[1] + ny * w / 2 - uy * 100)
    b = (p1[0] + nx * w / 2 + ux * 100, p1[1] + ny * w / 2 + uy * 100)
    return Polygon([a, b, (b[0] - nx * 200, b[1] - ny * 200), (a[0] - nx * 200, a[1] - ny * 200)])


def ring(cx, cy, rx, ry, tx, ty, p, rot, n=72):
    def poly(sx, sy):
        pts = []
        for i in range(n):
            t = 2 * math.pi * i / n
            c, s = math.cos(t), math.sin(t)
            pts.append((cx + sx * math.copysign(abs(c) ** (2 / p), c), cy + sy * math.copysign(abs(s) ** (2 / p), s)))
        return Polygon(pts)
    g = poly(rx, ry).difference(poly(max(rx - tx, 0.5), max(ry - ty, 0.5)))
    return affinity.rotate(g, rot, origin=(cx, cy))


def build(ch, q):
    """the syllable from its parameters, as one geometry, and its named strokes."""
    S = {}
    if ch == "쿠":
        A, C, D = (q["ax"], q["ay"]), (q["cx"], q["cy"]), (q["dx"], q["dy"])
        S["k_hook"] = stroke([A, C, D], q["wk"])                          # ㄱ of ㅋ
        S["k_mid"] = stroke([(q["mx"], q["my"]), on(C, D, q["mt"])], q["wm"])
        U0, U1 = (q["u0x"], q["u0y"]), (q["u1x"], q["u1y"])
        S["u_bar"] = stroke([U0, U1], q["wu"])
        S["u_stem"] = stroke([on(U0, U1, q["st"]), (q["sbx"], q["sby"])], q["ws"])
    elif ch == "파":
        P0, P1 = (q["p0x"], q["p0y"]), (q["p1x"], q["p1y"])
        S0, S1 = (q["s0x"], q["s0y"]), (q["s1x"], q["s1y"])
        Q0, Q1 = (q["q0x"], q["q0y"]), on(S0, S1, q["qt"])
        S["p_top"] = stroke([P0, P1], q["wt"])
        S["p_bot"] = stroke([Q0, Q1], q["wb"])
        S["p_l"] = stroke([on(P0, P1, q["l0"]), on(Q0, Q1, q["l1"])], q["wl"])
        S["p_r"] = stroke([on(P0, P1, q["r0"]), on(Q0, Q1, q["r1"])], q["wr"])
        S["a_stem"] = stroke([S0, S1], q["ws"])
        S["a_tick"] = stroke([on(S0, S1, q["tt"]), (q["tex"], q["tey"])], q["wti"])
    elif ch == "주":
        J0, J1 = (q["j0x"], q["j0y"]), (q["j1x"], q["j1y"])
        S["j_top"] = stroke([J0, J1], q["wj"])
        apex, L = on(J0, J1, q["at"]), (q["lx"], q["ly"])
        legs = unary_union([stroke([apex, L], q["wl"]),                       # ㅅ: long left leg,
                            stroke([on(apex, L, q["rb"]), (q["rx"], q["ry"])], q["wr"])])  # right leg off it
        S["j_legs"] = legs.intersection(below(J0, J1, q["wj"]))
        U0, U1 = (q["u0x"], q["u0y"]), (q["u1x"], q["u1y"])
        S["u_bar"] = stroke([U0, U1], q["wu"])
        S["u_stem"] = stroke([on(U0, U1, q["st"]), (q["sbx"], q["sby"])], q["ws"])
    elif ch == "니":
        I0, I1 = (q["i0x"], q["i0y"]), (q["i1x"], q["i1y"])
        S["n_hook"] = stroke([(q["nx"], q["ny"]), (q["cx"], q["cy"]), on(I0, I1, q["ft"])], q["wn"])
        S["i"] = stroke([I0, I1], q["wi"])
    elif ch == "어":
        S["o"] = ring(q["cx"], q["cy"], q["rx"], q["ry"], q["tx"], q["ty"], q["p"], q["rot"])
        S0, S1 = (q["s0x"], q["s0y"]), (q["s1x"], q["s1y"])
        S["e_tick"] = stroke([(q["cx"] + q["rx"] - q["tx"] / 2, q["ky"]), on(S0, S1, q["kt"])], q["wk"])
        S["e_stem"] = stroke([S0, S1], q["ws"])
    else:
        raise KeyError(ch)
    return unary_union(list(S.values())).buffer(0), S


def native_target():
    a = O.load("kupajunior_orange.png")[::2, ::2]
    r, b = a[..., 0], a[..., 2]
    return a, np.clip((r - 8.0) / 172.0, 0, 1) * (b < 140)


def target_crop(cov, ch, pad=3):
    x0, x1, y0, y1 = O.syllable_boxes()[ch]
    X0, X1, Y0, Y1 = x0 // 2 - pad, (x1 + 1) // 2 + pad, y0 // 2 - pad, (y1 + 1) // 2 + pad
    sub = cov[Y0:Y1, X0:X1].copy()
    lab, _ = ndi.label(sub > 0.5)
    inner = lab[pad:-pad, pad:-pad]
    ids = np.unique(inner[inner > 0])
    keep = ndi.binary_dilation(np.isin(lab, ids), iterations=2)
    return sub * keep, (X0, Y0)


def fit_one(ch, cov):
    T, (X0, Y0) = target_crop(cov, ch)
    keys = list(INIT[ch])

    def render(v):
        g, _ = build(ch, dict(zip(keys, v)))
        return G.raster(affinity.translate(g, -X0, -Y0), T.shape)

    def loss(v):
        try:
            return float(((render(v) - T) ** 2).sum())
        except Exception:
            return 1e9
    v0 = np.array([INIT[ch][k] for k in keys], float)
    res = minimize(loss, v0, method="Powell", options=dict(maxfev=12000, xtol=1e-3, ftol=1e-6))
    v = res.x
    R = render(v)
    iou = float(((R > 0.5) & (T > 0.5)).sum() / ((R > 0.5) | (T > 0.5)).sum())
    return ({k: round(float(x), 4) for k, x in zip(keys, v)},
            dict(loss0=round(loss(v0), 2), loss=round(float(res.fun), 2), iou=round(iou, 3), nfev=int(res.nfev)))


def fit_all():
    a, cov = native_target()
    out, rep = {}, {}
    for ch in O.SYLLABLES:
        out[ch], rep[ch] = fit_one(ch, cov)
        print(ch, rep[ch], flush=True)
    FIT_JSON.write_text(json.dumps(dict(fit=out, report=rep), ensure_ascii=False, indent=1), encoding="utf-8")
    return out, rep


@functools.lru_cache(None)
def _spec():
    return json.loads(FIT_JSON.read_text(encoding="utf-8"))["fit"]


def placed(ch):
    """the syllable where it sits in the sample (native px)."""
    return build(ch, _spec()[ch])[0]


def strokes(ch):
    return build(ch, _spec()[ch])[1]


@functools.lru_cache(None)
def glyph(ch):
    g = placed(ch)
    b = g.bounds
    return affinity.translate(g, -b[0], -b[1])


def fit_sheet(out=HERE / "sheets/official_fit.png"):
    import sheet as SH
    a, cov = native_target()
    H, W = cov.shape
    word = unary_union([placed(ch) for ch in O.SYLLABLES])
    vec = G.raster(word, (H, W))
    bw = np.repeat((255 * (1 - vec))[..., None], 3, 2)
    ov = np.full((H, W, 3), 255.0)
    c, v = (cov > 0.5)[..., None], vec[..., None]
    ov = ov * (1 - 0.5 * c) + np.array([230, 90, 20]) * 0.5 * c
    ov = ov * (1 - 0.5 * v) + np.array([20, 80, 230]) * 0.5 * v
    iou = float(((cov > 0.5) & (vec > 0.5)).sum() / ((cov > 0.5) | (vec > 0.5)).sum())
    big = G.raster(affinity.scale(word, 8, 8, origin=(0, 0)), (H * 8, W * 8))
    big_bw = np.repeat((255 * (1 - big))[..., None], 3, 2)[100:360, 40:1290]
    z = 6
    SH.sheet([[("공식 「쿠파주니어」 원래 텍스처 크기 x6", G.l2.zoom_img(a[12:46, 4:161], z))],
              [(f"획 맞춤 겹침 x6 (주황 = 공식, 파랑 = 벡터)  IoU {iou:.3f}", G.l2.zoom_img(ov[12:46, 4:161], z))],
              [("맞춘 벡터 (8배로 그림)", big_bw)]], out, max_px=1800)
    return iou


if __name__ == "__main__":
    fit_all()
    print("sheet IoU", fit_sheet())


def write_svg(out=HERE / "svg/official_kupajunior.svg"):
    """the fitted official lettering at the sample position (native px), one path per stroke."""
    rom = {"쿠": "ku", "파": "pa", "주": "ju", "니": "ni", "어": "eo"}
    items = []
    for ch in O.SYLLABLES:
        for name, g in strokes(ch).items():
            items.append(dict(id=f"{rom[ch]}_{name}", label=f"{ch} {name}", geom=g, fill="#000"))
    G.write_svg(out, items, 161, 56, background='<rect id="background" width="161" height="56" fill="#fff"/>',
                note="official 「쿠파주니어」 (Korean Super Mario typeface) refitted as strokes on the 161 x 56 "
                     "sample texture; one path per stroke (bars with square ends, mitred corners, ㅇ ring).")
