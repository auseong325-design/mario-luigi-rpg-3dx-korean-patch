"""FONT2 (wave 5, 2026-10-30): spacing measurements for the v2 advances (read-only).

For font and font_btl: side bearings and neighbour gaps (ink at alpha >= thr, thr = 1, 4, 8 of 15) of
  * Hangul as installed (weighted by how often each syllable / pair occurs in work/ko_final.json),
  * Latin letters and digits in the v1 stage (1DX shapes, 1DX CWDH) and as installed (3DX shapes),
  * the Japanese original (kana-kana and Latin-Latin) for reference.
Usage: v2_measure.py [stage_dir]   (stage_dir = folder holding font.bffnt / font_btl.bffnt to measure as "cand")
Writes v2_measure.txt (or v2_measure_<name>.txt for a candidate dir).
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

OUT_DIR = ROOT / "work/review/menu_fonts_20261030"
V1 = ROOT / "work/build/menu_font_stage/romfs/Msg/JP_ja"
LATIN = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"


def is_hangul(ch: str) -> bool:
    return 0xAC00 <= ord(ch) <= 0xD7A3


def is_kana(ch: str) -> bool:
    return 0x3041 <= ord(ch) <= 0x30FA


def bearings(font: Font, ch: str, thr: int):
    cell, left, gw, adv, miss = font.glyph(ord(ch))
    m = (cell * 15 + 0.5).astype(int) >= thr
    xs = np.nonzero(m.any(axis=0))[0]
    if miss or not len(xs):
        return None
    return int(left + xs[0]), int(adv - (left + xs[-1] + 1)), int(xs[-1] - xs[0] + 1), int(adv)


def text_counts(texts):
    chars, pairs = Counter(), Counter()
    for t in texts:
        for line in lines_of(t):
            line = re.sub(r"[\uE000-\uF8FF]", "\0", line)
            chars.update(c for c in line if c not in " \0")
            for a, b in zip(line, line[1:]):
                if a in " \0" or b in " \0":
                    continue
                pairs[(a, b)] += 1
    return chars, pairs


def wstats(vals: list[tuple[int, int]]):
    """(value, weight) -> weighted median / mean / p10 / p90"""
    if not vals:
        return "n/a"
    v = np.array([a for a, _ in vals], float)
    w = np.array([b for _, b in vals], float)
    o = np.argsort(v)
    v, w = v[o], w[o]
    c = np.cumsum(w) / w.sum()
    q = lambda p: v[np.searchsorted(c, p)]  # noqa: E731
    hist = Counter()
    for a, b in vals:
        hist[a] += b
    tot = sum(hist.values())
    h = " ".join(f"{k}:{100 * n / tot:.0f}%" for k, n in sorted(hist.items()))
    return f"median {q(0.5):.0f} mean {np.average(v, weights=w):.2f} p10 {q(0.1):.0f} p90 {q(0.9):.0f}  [{h}]"


def main():
    cand = Path(sys.argv[1]) if len(sys.argv) > 1 else None
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
        fonts = [("shipped", ship), ("v1", v1)]
        if cand:
            fonts.append(("cand", Font(f"cand:{name}", (cand / f"{name}.bffnt").read_bytes())))
        out.append(f"######## {name}")
        for thr in (1, 4, 8):
            out.append(f"--- ink threshold alpha >= {thr}/15")
            hb = [(bearings(ship, c, thr), n) for c, n in kch.items() if is_hangul(c) and ship.has(c)]
            hb = [(b, n) for b, n in hb if b]
            out.append(f"Hangul (shipped, by use) left bearing : {wstats([(b[0], n) for b, n in hb])}")
            out.append(f"Hangul (shipped, by use) right bearing: {wstats([(b[1], n) for b, n in hb])}")
            out.append(f"Hangul ink width                     : {wstats([(b[2], n) for b, n in hb])}")
            hh = []
            for (a, b), n in kpairs.items():
                if is_hangul(a) and is_hangul(b) and ship.has(a) and ship.has(b):
                    ba, bb = bearings(ship, a, thr), bearings(ship, b, thr)
                    if ba and bb:
                        hh.append((ba[1] + bb[0], n))
            out.append(f"Hangul-Hangul gap (pairs by use)     : {wstats(hh)}")
            kk = []
            for (a, b), n in jpairs.items():
                if is_kana(a) and is_kana(b) and jp.has(a) and jp.has(b):
                    ba, bb = bearings(jp, a, thr), bearings(jp, b, thr)
                    if ba and bb:
                        kk.append((ba[1] + bb[0], n))
            out.append(f"JP kana-kana gap (JP text)           : {wstats(kk)}")
            for tag, fo in [("JP", jp)] + fonts:
                ll, lh, hl = [], [], []
                src_pairs = jpairs if tag == "JP" else kpairs
                for (a, b), n in src_pairs.items():
                    if not (fo.has(a) and fo.has(b)):
                        continue
                    ba, bb = bearings(fo, a, thr), bearings(fo, b, thr)
                    if not (ba and bb):
                        continue
                    g = ba[1] + bb[0]
                    if a in LATIN and b in LATIN:
                        ll.append((g, n))
                    elif a in LATIN and (is_hangul(b) or is_kana(b)):
                        lh.append((g, n))
                    elif (is_hangul(a) or is_kana(a)) and b in LATIN:
                        hl.append((g, n))
                out.append(f"{tag:8s} Latin-Latin gap : {wstats(ll)}")
                out.append(f"{tag:8s} Latin-H/kana gap: {wstats(lh)}")
                out.append(f"{tag:8s} H/kana-Latin gap: {wstats(hl)}")
        out.append("--- per glyph (alpha>=1 box / alpha>=4 core): lb rb ink adv   [shipped 3DX | v1 1DX" +
                   (" | cand]" if cand else "]"))
        for ch in LATIN:
            row = [f"{ch} x{kch.get(ch, 0):5d}"]
            for tag, fo in fonts:
                if not fo.has(ch):
                    row.append(f"{tag}: -")
                    continue
                b1, b4 = bearings(fo, ch, 1), bearings(fo, ch, 4)
                row.append(f"{tag}: {b1[0]:2d} {b1[1]:2d} {b1[2]:2d} {b1[3]:2d} / {b4[0]:2d} {b4[1]:2d} {b4[2]:2d}")
            out.append("  " + "  |  ".join(row))
        out.append("")
    txt = "\n".join(out)
    dst = OUT_DIR / ("v2_measure.txt" if not cand else f"v2_measure_{cand.parent.parent.parent.name}.txt")
    dst.write_text(txt, "utf-8")
    print(txt)


if __name__ == "__main__":
    main()
