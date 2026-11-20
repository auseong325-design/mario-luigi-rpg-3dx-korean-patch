"""Editable copies of the OA안 texture (build_oa.py does the real 1x pixels).

  svg/OA_final_layers.svg   layered SVG (texture px = SVG units): rasters for the original (hidden), the
                            cleaned plate, R + right puff in front and the final render (hidden); vectors
                            for the three rings and the five syllables (gradient face + hatching pattern)
  <dir>/                    the same layers as files for the Affinity document (affinity_oa.js reads
                            them): original.png, plate.png, front.png (alpha), face_texture.png (alpha),
                            final.png, vectors.json

  python export_layers.py [<dir for the Affinity assets>]
"""
from __future__ import annotations

import base64
import io
import json
import sys
from pathlib import Path

import numpy as np
from PIL import Image
from shapely import affinity
from shapely.geometry import MultiPolygon
from shapely.ops import unary_union

import build_oa as B
import glyphs as G

HERE = G.HERE
ROM = {"쿠": "ku", "파": "pa", "주": "ju", "니": "ni", "어": "eo"}


def rgba_u8(rgb, alpha=None):
    a = np.full(rgb.shape[:2] + (1,), 255.0) if alpha is None else alpha[..., None] * 255.0
    return np.clip(np.rint(np.concatenate([rgb, a], 2)), 0, 255).astype(np.uint8)


def png_uri(u8):
    buf = io.BytesIO()
    Image.fromarray(u8).save(buf, "PNG")
    return "data:image/png;base64," + base64.b64encode(buf.getvalue()).decode("ascii")


def polys(g):
    """[[exterior, hole, hole ...], ...] with [x, y] points (closing point dropped)."""
    out = []
    for p in (g.geoms if isinstance(g, MultiPolygon) else [g]):
        if p.is_empty:
            continue
        rings = [p.exterior] + list(p.interiors)
        out.append([[[round(x, 3), round(y, 3)] for x, y in list(r.coords)[:-1]] for r in rings])
    return out


def shapes(L):
    m = L["m"]
    jm = dict(join_style="mitre", mitre_limit=m["mitre"])
    word = unary_union(L["geoms"])
    return dict(maroon=affinity.translate(word.buffer(m["r_maroon"], **jm), 0, m["maroon_dy"]),
                yellow=word.buffer(m["r_yellow"], **jm), white=word.buffer(m["r_white"], **jm))


def hx(c):
    return "#%02x%02x%02x" % tuple(int(round(v)) for v in c)


def write_svg(L, path):
    m, W, H = L["m"], B.W1, B.H1
    S = shapes(L)
    y0, y1 = unary_union(L["geoms"]).bounds[1::2]
    out = [f'<svg xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" '
           f'width="{W}" height="{H}" viewBox="0 0 {W} {H}">',
           "<!-- 쿠파주니어 RPG file-select logo, OA안 (LOAD_GAME_IMG_KJ_L + _R = 400 x 208). build_oa.py writes the "
           "real texture; this file is the same construction as editable layers. -->",
           "<defs>",
           f'<linearGradient id="maroonShade" x1="0" y1="{y0 - 8:.1f}" x2="0" y2="{y1 + 8:.1f}" gradientUnits="userSpaceOnUse">'
           f'<stop offset="0" stop-color="{hx(m["maroon_up"])}"/><stop offset="0.5" stop-color="{hx(m["maroon_side"])}"/>'
           f'<stop offset="1" stop-color="{hx(m["maroon_down"])}"/></linearGradient>',
           f'<linearGradient id="faceOrange" x1="0" y1="{m["y_top"]}" x2="0" y2="{m["y_top"] + m["y_span"]}" '
           f'gradientUnits="userSpaceOnUse"><stop offset="0" stop-color="{hx((m["face_r"], m["g_top"], 0))}"/>'
           f'<stop offset="1" stop-color="{hx((m["face_r"], m["g_bot"], 0))}"/></linearGradient>']
    for c in L["chars"]:
        # vertical stripes turned by the wave angle (the stripes run across the wave direction)
        out.append(f'<pattern id="hatch_{ROM[c]}" width="{m["hatch_period"]}" height="{m["hatch_period"]}" '
                   f'patternUnits="userSpaceOnUse" patternTransform="rotate({B.HATCH_DEG[c]:.1f})">'
                   f'<rect width="{m["hatch_period"] / 2:.2f}" height="{m["hatch_period"]}" fill="#ffd200" '
                   f'fill-opacity="0.12"/></pattern>')
    out.append("</defs>")
    img = lambda u8: f'<image width="{W}" height="{H}" xlink:href="{png_uri(u8)}"/>'
    out.append(f'<g id="original_JP" style="display:none">{img(rgba_u8(L["rgb"]))}</g>')
    out.append(f'<g id="plate">{img(rgba_u8(L["plate"]))}</g>')
    out.append(f'<g id="ring_maroon"><path fill="url(#maroonShade)" fill-rule="evenodd" d="{G.svg_path(S["maroon"])}"/></g>')
    out.append(f'<g id="ring_yellow"><path fill="{hx(m["yellow"])}" fill-rule="evenodd" d="{G.svg_path(S["yellow"])}"/></g>')
    out.append(f'<g id="ring_white"><path fill="#ffffff" fill-rule="evenodd" d="{G.svg_path(S["white"])}"/></g>')
    out.append('<g id="letters">')
    for c, g in zip(L["chars"], L["geoms"]):
        d = G.svg_path(g)
        out.append(f'<g id="{ROM[c]}" data-label="{c}"><path fill="url(#faceOrange)" fill-rule="evenodd" d="{d}"/>'
                   f'<path fill="url(#hatch_{ROM[c]})" fill-rule="evenodd" d="{d}"/></g>')
    out.append("</g>")
    out.append(f'<g id="front_R_and_puff">{img(rgba_u8(L["rgb"], L["front"].astype(float)))}</g>')
    out.append(f'<g id="final_render" style="display:none">{img(rgba_u8(L["final"]))}</g>')
    out.append("</svg>")
    Path(path).write_text("\n".join(out), encoding="utf-8")


def write_assets(L, d):
    d = Path(d)
    d.mkdir(parents=True, exist_ok=True)
    Image.fromarray(rgba_u8(L["rgb"])).save(d / "original.png")
    Image.fromarray(rgba_u8(L["plate"])).save(d / "plate.png")
    Image.fromarray(rgba_u8(L["rgb"], L["front"].astype(float))).save(d / "front.png")
    Image.fromarray(rgba_u8(L["final"])).save(d / "final.png")
    # the baked face texture (hatching, red rim, gradient) where the letters are, alpha = face coverage
    face_cov = G.raster(unary_union(L["geoms"]), (B.H1, B.W1))
    Image.fromarray(rgba_u8(L["final"], face_cov)).save(d / "face_texture.png")
    m = L["m"]
    S = shapes(L)
    y0, y1 = unary_union(L["geoms"]).bounds[1::2]
    vec = dict(size=[B.W1, B.H1],
               rings={k: polys(v) for k, v in S.items()},
               letters=[dict(ch=c, id=ROM[c], polys=polys(g), hatch_deg=B.HATCH_DEG[c]) for c, g in zip(L["chars"], L["geoms"])],
               colours=dict(maroon_up=m["maroon_up"], maroon_side=m["maroon_side"], maroon_down=m["maroon_down"],
                            yellow=m["yellow"], white=[255, 255, 255],
                            face_top=[m["face_r"], m["g_top"], 0], face_bottom=[m["face_r"], m["g_bot"], 0]),
               maroon_grad=[y0 - 8, y1 + 8], face_grad=[m["y_top"], m["y_top"] + m["y_span"]],
               material={k: m[k] for k in ("r_white", "r_yellow", "r_maroon", "maroon_dy", "mitre", "hatch_period", "hatch_amp")})
    (d / "vectors.json").write_text(json.dumps(vec, ensure_ascii=False), encoding="utf-8")


if __name__ == "__main__":
    B.build_kr()
    write_svg(B.LAST, HERE / "svg/OA_final_layers.svg")
    print("svg", (HERE / "svg/OA_final_layers.svg").stat().st_size, "bytes")
    if len(sys.argv) > 1:
        write_assets(B.LAST, sys.argv[1])
        print("assets ->", sys.argv[1])
