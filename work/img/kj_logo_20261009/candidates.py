"""Step 3 - base-glyph candidates for 쿠 파 주 니 어, black on white, shown at the Japanese letters' size
next to クッパJr. (sheets/candidates_*.png, candidates.svg) with simple weight measurements.

The measure "weight" = 2 x ink area / outline length / cap height (mean stroke thickness relative to the
letter height); "ink" = ink area / bounding-box area. The Japanese MARIO Font letters are the target.
"""
from __future__ import annotations

import json

import numpy as np
from PIL import Image, ImageDraw, ImageFont

import glyphs as G

HERE = G.HERE
CAP = 33.0          # the Japanese ク cap height (px)
SCALE = 4           # sheet zoom


def measure(g, height):
    g = G.normalise(g, height)
    b = g.bounds
    return dict(weight=round(2 * g.area / g.length / height, 3),
                ink=round(g.area / ((b[2] - b[0]) * (b[3] - b[1])), 3),
                aspect=round((b[2] - b[0]) / (b[3] - b[1]), 2))


def jp_reference():
    """the Japanese letters as MARIO Font glyphs at their measured sizes (black on white)."""
    out = []
    for ch, h in (("ク", 33), ("ッ", 19), ("パ", 30), ("J", 27), ("r", 14)):
        out.append((ch, G.normalise(G.font("mario_jp", ch), h), h))
    return out


def row_image(items, height_px=CAP, gap=4, bottom_align=True):
    """items: list of (label, geom normalised to its height, height). Returns RGB array (zoomed)."""
    W = int(sum(g.bounds[2] for _, g, _ in items) + gap * (len(items) + 1)) + 2
    H = int(height_px + 12)
    cov = np.zeros((H, W))
    x = gap
    for _, g, h in items:
        oy = (H - 6 - h) if bottom_align else 6
        cov = np.maximum(cov, G.raster(g, (H, W), offset=(x, oy)))
        x += g.bounds[2] + gap
    img = np.stack([255 - cov * 255] * 3, 2)
    return np.kron(img, np.ones((SCALE, SCALE, 1))), cov


def main():
    word = "쿠파주니어"
    cands = {
        "1DX 한국판 쿠·파 (원래 굵기)": lambda ch: G.dx1_kr(ch) if ch in "쿠파" else None,
        "1DX 골격 + 원판 굵기 (직선 막대·비스듬히 자른 끝)": G.skel_1dx,
        "MARIO Font 한국어판 (슈퍼 마리오 RPG 부제 조각)": G.mario_kr,
        "카페24 써라운드": lambda ch: G.font("cafe24", ch),
        "검은고딕 (Black Han Sans)": lambda ch: G.font("blackhan", ch),
        "주아 (Jua)": lambda ch: G.font("jua", ch),
        "도현 (Do Hyeon)": lambda ch: G.font("dohyeon", ch),
    }
    rows, report = [], {}
    ref = jp_reference()
    img, _ = row_image([(c, g, h) for c, g, h in ref])
    rows.append([("원판 クッパJr. (MARIO Font, 실제 크기 비율)", img)])
    report["JP"] = {c: measure(g, h) for c, g, h in ref}
    svg_items = []
    y_svg = 0
    for name, fn in cands.items():
        items, rep = [], {}
        for ch in word:
            g = fn(ch)
            if g is None:
                continue
            g = G.normalise(g, CAP)
            items.append((ch, g, CAP))
            rep[ch] = measure(g, CAP)
        img, _ = row_image(items)
        w = np.mean([v["weight"] for v in rep.values()])
        rows.append([(f"{name}  (평균 굵기 {w:.3f})", img)])
        report[name] = rep
        x = 4
        for ch, g, h in items:
            rom = {"쿠": "ku", "파": "pa", "주": "ju", "니": "ni", "어": "eo"}
            svg_items.append(dict(id=f"cand{list(cands).index(name)}_{rom[ch]}", label=f"{name} {ch}",
                                  geom=G.affinity.translate(g, x, y_svg + 4)))
            x += g.bounds[2] + 4
        y_svg += CAP + 12
    (HERE / "sheets").mkdir(exist_ok=True)
    import sheet as SH
    SH.sheet(rows, HERE / "sheets/candidates_bw.png")
    (HERE / "candidates.json").write_text(json.dumps(report, ensure_ascii=False, indent=1), encoding="utf-8")
    G.write_svg(HERE / "svg/candidates.svg", svg_items, 260, int(y_svg + 8),
                note="base-glyph candidates for 쿠파주니어, cap height 33 px (one path per syllable)")
    print(json.dumps({k: (round(np.mean([v['weight'] for v in r.values()]), 3) if r else None)
                      for k, r in report.items()}, ensure_ascii=False, indent=1))


if __name__ == "__main__":
    (HERE / "svg").mkdir(exist_ok=True)
    main()
