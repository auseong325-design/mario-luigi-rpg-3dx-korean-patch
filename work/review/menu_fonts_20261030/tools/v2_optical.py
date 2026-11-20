"""FONT2: optical (white-area) spacing model, calibrated on the Japanese original (read-only).

Side white of a glyph (left or right): box bearing (advance edge to the core ink box, alpha >= 4/15) plus the mean
over the band rows of min(depth, D), depth = how far the row's ink edge lies inside the ink box (rows without ink
count D). Pair gap = right side white of the first + left side white of the second (HT-Letterspacer-like area model).
Band = rows the Hangul core ink covers (median top..bottom), i.e. cap height; lowercase letters get D for their
empty upper rows.
Usage: v2_optical.py   -> prints/writes v2_optical.txt: for D = 1..4: JP kana-kana / Latin-Latin / mixed, Hangul-Hangul
(shipped), Latin in v1, and the box bearings that would give every Latin glyph the Hangul side whites.
"""
from __future__ import annotations

import json
import re
import sys
from collections import Counter
from pathlib import Path

import numpy as np

sys.path.insert(0, str(Path(__file__).resolve().parent))
from render import ROOT, Font, get_font  # noqa: E402
from real_width import lines_of  # noqa: E402

V1 = ROOT / "work/build/menu_font_stage/romfs/Msg/JP_ja"
LATIN = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
CORE = 4


def is_hangul(ch):
    return 0xAC00 <= ord(ch) <= 0xD7A3


def is_kana(ch):
    return 0x3041 <= ord(ch) <= 0x30FA


def text_counts(texts):
    chars, pairs = Counter(), Counter()
    for t in texts:
        for line in lines_of(t):
            line = re.sub(r"[\uE000-\uF8FF]", "\0", line)
            chars.update(c for c in line if c not in " \0")
            for a, b in zip(line, line[1:]):
                if a not in " \0" and b not in " \0":
                    pairs[(a, b)] += 1
    return chars, pairs


class Prof:
    """Core-ink profile of one glyph in one font: per band row the left/right ink edge (cell x) or None."""

    def __init__(self, font: Font, ch: str, band: tuple[int, int]):
        cell, left, gw, adv, miss = font.glyph(ord(ch))
        self.ok = not miss
        a = (cell * 15 + 0.5).astype(int)
        m = a >= CORE
        xs = np.nonzero(m.any(axis=0))[0]
        if not len(xs):
            self.ok = False
            return
        self.x0, self.x1 = int(xs[0]), int(xs[-1])
        self.left, self.adv = left, adv
        self.lb = left + self.x0                     # box bearings at core
        self.rb = adv - (left + self.x1 + 1)
        r0, r1 = band
        self.dl, self.dr = [], []
        for r in range(r0, r1 + 1):
            row = np.nonzero(m[r])[0] if 0 <= r < m.shape[0] else []
            if len(row):
                self.dl.append(int(row[0] - self.x0))
                self.dr.append(int(self.x1 - row[-1]))
            else:
                self.dl.append(None)
                self.dr.append(None)

    def white_l(self, D):
        return float(np.mean([min(d, D) if d is not None else D for d in self.dl]))

    def white_r(self, D):
        return float(np.mean([min(d, D) if d is not None else D for d in self.dr]))

    def side_l(self, D):
        return self.lb + self.white_l(D)

    def side_r(self, D):
        return self.rb + self.white_r(D)


def band_of(font: Font, chars):
    tops, bots = [], []
    for ch in chars:
        if not font.has(ch):
            continue
        cell = font.glyph(ord(ch))[0]
        ys = np.nonzero(((cell * 15 + 0.5).astype(int) >= CORE).any(axis=1))[0]
        if len(ys):
            tops.append(ys[0])
            bots.append(ys[-1])
    return int(np.median(tops)), int(np.median(bots))


def wmean(pairs):
    v = np.array([a for a, _ in pairs], float)
    w = np.array([b for _, b in pairs], float)
    return float(np.average(v, weights=w)) if len(v) else float("nan")


def main():
    ko = json.loads((ROOT / "work/ko_final.json").read_text("utf-8"))
    jp_texts = []
    for f in (ROOT / "text/jp").glob("*.json"):
        jp_texts += [m["jp"] for m in json.loads(f.read_text("utf-8"))["messages"]]
    kch, kpairs = text_counts(ko.values())
    jch, jpairs = text_counts(jp_texts)
    out = []
    for name in ("font", "font_btl"):
        ship = get_font(f"ko:{name}")
        v1 = Font(f"v1:{name}", (V1 / f"{name}.bffnt").read_bytes())
        jp = get_font(f"jp:{name}")
        hangul_chars = [c for c in kch if is_hangul(c)]
        band_k = band_of(ship, hangul_chars)
        band_j = band_of(jp, "ABCDEFGHKLMNPRTUVXZ")      # JP caps band
        out.append(f"######## {name}: band rows Hangul {band_k} (cell rows), JP caps {band_j}")
        P = {}

        def prof(font, tag, ch, band):
            k = (tag, ch)
            if k not in P:
                P[k] = Prof(font, ch, band)
            return P[k]
        for D in (1, 2, 3, 4):
            def pair_stats(font, tag, pairs, band, cls_a, cls_b):
                vals = []
                for (a, b), n in pairs.items():
                    if cls_a(a) and cls_b(b) and font.has(a) and font.has(b):
                        pa, pb = prof(font, tag, a, band), prof(font, tag, b, band)
                        if pa.ok and pb.ok:
                            vals.append((pa.side_r(D) + pb.side_l(D), n))
                return wmean(vals)
            lat = lambda c: c in LATIN  # noqa: E731
            out.append(f"D={D}: JP kana-kana {pair_stats(jp, 'jp', jpairs, band_j, is_kana, is_kana):.2f}  "
                       f"JP Latin-Latin {pair_stats(jp, 'jp', jpairs, band_j, lat, lat):.2f}  "
                       f"JP Latin-kana {pair_stats(jp, 'jp', jpairs, band_j, lat, is_kana):.2f}  "
                       f"JP kana-Latin {pair_stats(jp, 'jp', jpairs, band_j, is_kana, lat):.2f}  |  "
                       f"KO Hangul-Hangul {pair_stats(ship, 'ko', kpairs, band_k, is_hangul, is_hangul):.2f}  "
                       f"v1 Latin-Latin {pair_stats(v1, 'v1', kpairs, band_k, lat, lat):.2f}  "
                       f"v1 Latin-Hangul {pair_stats(v1, 'v1', kpairs, band_k, lat, is_hangul):.2f}  "
                       f"v1 Hangul-Latin {pair_stats(v1, 'v1', kpairs, band_k, is_hangul, lat):.2f}  "
                       f"shipped(3DX) Latin-Latin {pair_stats(ship, 'ko', kpairs, band_k, lat, lat):.2f}")
            hl = [(prof(ship, 'ko', c, band_k).side_l(D), n) for c, n in kch.items() if is_hangul(c) and ship.has(c)
                  and prof(ship, 'ko', c, band_k).ok]
            hr = [(prof(ship, 'ko', c, band_k).side_r(D), n) for c, n in kch.items() if is_hangul(c) and ship.has(c)
                  and prof(ship, 'ko', c, band_k).ok]
            out.append(f"      Hangul side white (by use): left {wmean(hl):.2f}  right {wmean(hr):.2f}")
        out.append("")
    txt = "\n".join(out)
    (ROOT / "work/review/menu_fonts_20261030/v2_optical.txt").write_text(txt, "utf-8")
    print(txt)


if __name__ == "__main__":
    main()
