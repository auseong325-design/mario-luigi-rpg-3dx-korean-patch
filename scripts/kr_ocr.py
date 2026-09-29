"""Build code -> character tables for the Korean DS font by template matching.

The DS glyphs are 12x12 bitmaps that closely follow Gulim/Dotum 12px embedded bitmaps,
so every glyph is compared (with +-1 px shifts) against those renderings of the
KS X 1001 repertoire. Output: work/kr_font/table_<space>.json with score/margin per
code, plus review sheets for low-confidence matches.

Code spaces:
  main  - single-byte codes (arm9 font)
  dlg   - 2-byte codes of dialogue fonts (FEvent rooms / BMes tables, globally consistent)
  stat  - 2-byte codes of StatFontSet[5] (used by 'plain' mfset data)
"""

from __future__ import annotations

import collections
import json
import sys

import numpy as np
from PIL import Image, ImageDraw, ImageFont

from libnds_kr import (DATA, FEVENT_HEADER_OVERLAY3, ROOT, Glyph, main_font, overlay, parse_font,
                       segmented_file, segments32)

OUT = ROOT / "work" / "kr_font"
PAD = 22


def candidates() -> list[str]:
    chars = []
    for hi in range(0xA1, 0xFE):
        for lo in range(0xA1, 0xFF):
            try:
                ch = bytes([hi, lo]).decode("euc-kr")
            except UnicodeDecodeError:
                continue
            if ch.strip():
                chars.append(ch)
    chars += [chr(c) for c in range(0x21, 0x7F)]
    return list(dict.fromkeys(chars))


def render(font: ImageFont.FreeTypeFont, ch: str) -> np.ndarray:
    img = Image.new("1", (PAD, PAD), 0)
    ImageDraw.Draw(img).text((2, 1), ch, font=font, fill=1)
    return np.array(img, dtype=bool)


NORM = 20


def normalize(bits: np.ndarray) -> np.ndarray:
    """Fit the ink bbox (aspect preserved) into a NORM x NORM float canvas, top-left anchored.

    Scale-normalising absorbs the 1 px size difference between the DS font (12 px tall)
    and the Gulim/Dotum embedded bitmaps."""
    ys, xs = np.nonzero(bits)
    out = np.zeros((NORM, NORM), dtype=np.float32)
    if len(ys) == 0:
        return out
    crop = bits[ys.min():ys.max() + 1, xs.min():xs.max() + 1].astype(np.uint8) * 255
    h, w = crop.shape
    s = (NORM - 2) / max(h, w, 8)  # tiny marks (dots, commas) are not blown up to full size
    nh, nw = max(1, round(h * s)), max(1, round(w * s))
    img = Image.fromarray(crop).resize((nw, nh), Image.BILINEAR)
    out[1:1 + nh, 1:1 + nw] = np.asarray(img, dtype=np.float32) / 255.0
    return out


def glyph_bits(g: Glyph) -> np.ndarray:
    return np.array(g.pixels, dtype=np.uint8).reshape(g.height, g.width) == 2


class Matcher:
    """Cosine similarity between scale-normalised DS glyphs and KS X 1001 renderings.

    A small penalty on bbox aspect / height difference keeps '1', 'l', '|' and
    '.', ',', '·' apart after normalisation."""

    FACES = [(r"C:\Windows\Fonts\gulim.ttc", i, s) for i in (0, 2) for s in (12, 13, 14)]

    def __init__(self) -> None:
        self.chars = candidates()
        vecs, owner, meta = [], [], []
        for path, idx, size in self.FACES:
            f = ImageFont.truetype(path, size, index=idx)
            for ch in self.chars:
                bits = render(f, ch)
                if not bits.any():
                    continue
                vecs.append(normalize(bits).reshape(-1))
                owner.append(ch)
                meta.append(self._shape(bits) + (size,))
        m = np.stack(vecs)
        self.cand = m / (np.linalg.norm(m, axis=1, keepdims=True) + 1e-6)
        self.owner = owner
        self.meta = np.array(meta, dtype=np.float32)  # h, w, size

    @staticmethod
    def _shape(bits: np.ndarray) -> tuple[float, float]:
        ys, xs = np.nonzero(bits)
        return float(ys.max() - ys.min() + 1), float(xs.max() - xs.min() + 1)

    def match(self, bits: np.ndarray) -> list[tuple[str, float]]:
        v = normalize(bits).reshape(-1)
        v = v / (np.linalg.norm(v) + 1e-6)
        sim = self.cand @ v
        h, w = self._shape(bits)
        # expected size of the candidate in DS pixels: 12 px DS ~ Gulim `size` px
        scale = 12.0 / self.meta[:, 2]
        ch, cw = self.meta[:, 0] * scale, self.meta[:, 1] * scale
        penalty = 0.02 * (np.abs(np.log((ch + 1) / (h + 1))) + np.abs(np.log((cw + 1) / (w + 1))))
        score = sim - penalty
        best: dict[str, float] = {}
        for k in np.argpartition(-score, 40)[:40]:
            c = self.owner[k]
            if score[k] > best.get(c, -1):
                best[c] = float(score[k])
        return sorted(best.items(), key=lambda kv: -kv[1])[:5]


def collect_fonts() -> dict[str, dict[int, Glyph]]:
    spaces: dict[str, dict[int, Glyph]] = {"main": main_font(), "dlg": {}, "stat": {}}
    spaces["stat"] = parse_font(segments32((DATA / "Font" / "StatFontSet.dat").read_bytes())[5])
    ov3, fe = overlay(3), (DATA / "FEvent" / "FEvent.dat").read_bytes()
    fseg = segmented_file(ov3, FEVENT_HEADER_OVERLAY3, fe)
    tables = [fseg[r * 3 + 2] for r in range(len(fseg) // 3) if fseg[r * 3 + 2]]
    for rel in ["BAI/BMes_cf.dat", "BAI/BMes_ji.dat", "BAI/BMes_yo.dat", "MAI/MMes_yo.dat", "SAI/SMes_yo.dat"]:
        d = (DATA / rel).read_bytes()
        tables += [t for t in segmented_file(d, 0, d) if any(t)]
    conflicts = 0
    for lt in tables:
        cols = segmented_file(lt, 0, lt)
        if cols and cols[0]:
            for code, g in parse_font(cols[0]).items():
                prev = spaces["dlg"].get(code)
                if prev is not None and prev.pixels != g.pixels:
                    conflicts += 1
                spaces["dlg"].setdefault(code, g)
    print(f"dialogue replacement codes: {len(spaces['dlg'])} (bitmap conflicts across tables: {conflicts})")
    return spaces


def review_sheet(items: list[tuple[str, int, Glyph, list[tuple[str, float]]]], path) -> None:
    S, cw, chh = 4, 150, 64
    cols = 6
    rows = (len(items) + cols - 1) // cols
    img = Image.new("RGB", (cols * cw, max(1, rows) * chh), "white")
    d = ImageDraw.Draw(img)
    kfont = ImageFont.truetype(r"C:\Windows\Fonts\malgun.ttf", 22)
    sfont = ImageFont.truetype(r"C:\Windows\Fonts\malgun.ttf", 11)
    for k, (space, code, g, top) in enumerate(items):
        x0, y0 = (k % cols) * cw, (k // cols) * chh
        bits = glyph_bits(g)
        for y in range(g.height):
            for x in range(g.width):
                if bits[y, x]:
                    d.rectangle([x0 + 2 + x * S, y0 + 12 + y * S, x0 + 1 + (x + 1) * S, y0 + 11 + (y + 1) * S], fill="black")
        d.text((x0 + 2, y0), f"{space}:{code:03X}", fill=(200, 0, 0), font=sfont)
        d.text((x0 + 56, y0 + 10), top[0][0], fill=(0, 0, 160), font=kfont)
        d.text((x0 + 90, y0 + 16), f"{top[0][1]:.2f}\n{top[1][0]}{top[1][1]:.2f}", fill=(0, 120, 0), font=sfont)
    img.save(path)


def main() -> int:
    OUT.mkdir(parents=True, exist_ok=True)
    matcher = Matcher()
    print(f"candidates: {len(matcher.chars)} chars")
    spaces = collect_fonts()
    low: list[tuple[str, int, Glyph, list[tuple[str, float]]]] = []
    for space, font in spaces.items():
        table = {}
        for code, g in sorted(font.items()):
            bits = glyph_bits(g)
            if not bits.any():
                table[f"{code:03X}"] = {"char": " ", "score": 1.0, "margin": 1.0, "alt": []}
                continue
            top = matcher.match(bits)
            score, margin = top[0][1], top[0][1] - (top[1][1] if len(top) > 1 else 0)
            table[f"{code:03X}"] = {"char": top[0][0], "score": round(score, 3), "margin": round(margin, 3),
                                   "alt": [c for c, _ in top[1:4]]}
            if score < 0.93 or margin < 0.04:
                low.append((space, code, g, top))
        (OUT / f"table_{space}.json").write_text(json.dumps(table, ensure_ascii=False, indent=0), encoding="utf-8")
        hist = collections.Counter(round(v["score"], 1) for v in table.values())
        print(f"{space}: {len(table)} codes, score histogram {sorted(hist.items())}")
    for i in range(0, len(low), 120):
        review_sheet(low[i:i + 120], OUT / f"review_{i // 120:02d}.png")
    print(f"low-confidence glyphs: {len(low)} -> review_XX.png")
    return 0


if __name__ == "__main__":
    sys.exit(main())
