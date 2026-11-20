"""FONT2 (wave 5, 2026-10-30): derive the v2 advances (CWDH) of Latin letters and digits -> v2_spacing.json.

    .venv\\Scripts\\python work\\build\\menu_font_stage\\v2_spacing.py              final table (mode "fit")
    .venv\\Scripts\\python work\\build\\menu_font_stage\\v2_spacing.py --mode=box   a rejected candidate (record)

Why: v1 (build_menu_font.py) gave the 1DX letter/digit glyphs their 1DX CWDH. The 1DX bearings are 1-2 px on
each side, so Latin runs look letter-spaced next to the Hangul ('P O W부츠D X', 'E x c e l l e n t').

Rule (pixels and rows stay exactly as v1 = 1DX shapes on the Hangul baseline; only CWDH left/char change):
  1. Base letterfit = the Japanese original's Latin box metrics: core ink (alpha >= 4/15) starts at the pen
     (left bearing 0) and leaves 1 px on the right, so two letters/digits are 1 px apart, like 3DX JP Latin
     (JP: Latin-Latin core gap mean 1.06 px next to kana-kana 2.11; Hangul-Hangul in the Korean fonts 2.17).
     One-stroke glyphs get more white, as the JP original gives them: I, i, l = 1/1, digit 1 = 1/2.
  2. Ink never leaves its advance box (any alpha > 0 pixel lies inside [pen, pen + advance)): nothing can be
     clipped at a box edge and no glyph image overlaps its neighbour.
  3. Hard limit: no touching. Two neighbours touch when a core pixel of one is 8-adjacent to (or on) a core
     pixel of the other. Checked for every pair that occurs in the Korean text drawn with that font
     (work/ko_final.json, style -> font as MessageSimple::GetFont; 13/255 -> both, except battle names
     BMsg style 13 without 'KJ' in the label -> font_btl only, see text_pairs), the pairs created at
     runtime around string variables (one-line style-13 names x the characters next to [0003:0001] tags),
     the characters next to number variables x every digit, and every digit x digit pair.
  4. Fit: start from 1 + 2, add 1 px where 3 fails, then a local search over each glyph's two core bearings
     (any value that keeps 2 and 3) minimising, over the text pairs that contain a Latin glyph,
     sum n * (core gap - core gap under rules 1 + 2)^2  +  0.3 * uses * ((left - base)^2 + (right - base)^2),
     i.e. a pixel that 3 forces onto one side is taken back from the partner where that is safe.
  Candidates kept for the record (REPORT.md section 10): "optical" / "jpchar" (white-area model D = 2, targets
  = median / per-character side white of the JP Latin), "box" (rule 1 without the one-stroke exception),
  "stem" (rules 1-3 without the fit); those also apply the no-touch limit to all letter x letter pairs.
Inputs : v1 staged fonts (work/build/menu_font_stage/romfs/Msg/JP_ja, = build_menu_font.py output; pixels and
         the untouched glyphs), JP original fonts (romfs/Msg/JP_ja), work/ko_final.json, text/jp (styles).
Output : v2_spacing.json (per font: char -> [left, glyph, char] + diagnostics), v2_spacing.txt.
The builder (build_menu_font_v2.py) reads only v2_spacing.json, so the fonts do not change when text changes;
rerun this script after text edits: its report lists any pair that would touch ("still touching").
"""
from __future__ import annotations

import json
import re
import sys
from collections import Counter
from pathlib import Path

import numpy as np

STAGE = Path(__file__).resolve().parent
ROOT = STAGE.parents[2]
sys.path.insert(0, str(ROOT / "scripts"))
import libbffnt as L  # noqa: E402

V1_MSG = STAGE / "romfs/Msg/JP_ja"
JP_MSG = ROOT / "romfs/Msg/JP_ja"
FONTS = ["font", "font_btl"]
LATIN = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
DIGITS = "0123456789"
CORE = 4
D = 2
STEM = {"I": (1, 1), "l": (1, 1), "i": (1, 1), "1": (1, 2)}
LAMBDA = 0.3
MODE = "fit"
for _a in sys.argv[1:]:
    if _a.startswith("--mode="):
        MODE = _a.split("=", 1)[1]
OUT_JSON = STAGE / ("v2_spacing.json" if MODE == "fit" else f"v2_spacing_{MODE}.json")
OUT_TXT = STAGE / ("v2_spacing.txt" if MODE == "fit" else f"v2_spacing_{MODE}.txt")
STYLE_FONT = {0: "font_btl", 5: "font_btl", 8: "font_btl", 1: "font", 6: "font", 9: "font",
              2: "font_l", 7: "font_l", 10: "font_l", 3: "font_btl", 11: "font_btl"}
TAG = re.compile(r"\[([^\[\]]*)\]")
SVAR, NVAR = "\x01", "\x02"      # string / number variable insertion points in a visible line


def lines_of(text: str, mark_vars: bool = False):
    """Visible lines: [Next] = page break, [Ruby a;b] -> a, [U+XXXX] icons -> private-use char,
    [0003:0001:..] -> SVAR and [0003:0000:..] -> NVAR when mark_vars, every other tag removed."""
    out, pos = [], 0
    for m in TAG.finditer(text):
        out.append(text[pos:m.start()])
        b = m.group(1)
        if b == "Next":
            out.append("\n")
        elif b.startswith("Ruby "):
            out.append(b[5:].split(";", 1)[0])
        elif b.startswith("U+"):
            out.append(chr(int(b[2:], 16)))
        elif mark_vars and b.startswith("0003:0001"):
            out.append(SVAR)
        elif mark_vars and b.startswith("0003:0000"):
            out.append(NVAR)
        pos = m.end()
    out.append(text[pos:])
    return [ln for ln in "".join(out).split("\n") if ln.strip()]


class Face:
    """One font: per character the drawn core rows (cell columns 0..glyphWidth-1), left, advance."""

    def __init__(self, path: Path):
        self.f = L.parse(path.read_bytes())
        self.si = L.SheetImages(self.f)
        self.cmap = self.f.char_map()
        self.w = self.f.widths()
        self._g = {}

    def has(self, ch: str) -> bool:
        return ord(ch) in self.cmap

    def glyph(self, ch: str):
        if ch not in self._g:
            g = self.cmap[ord(ch)]
            cw = self.w[g]
            cell = self.si.cell(g)[:, :cw.glyph].astype(int)
            core = cell >= CORE
            rows = {}
            for r in range(core.shape[0]):
                xs = np.nonzero(core[r])[0]
                if len(xs):
                    rows[r] = (int(xs[0]), int(xs[-1]))
            anyx = np.nonzero((cell > 0).any(axis=0))[0]
            corex = np.nonzero(core.any(axis=0))[0]
            self._g[ch] = {"left": cw.left, "glyph": cw.glyph, "adv": cw.char, "rows": rows,
                           "x0": int(anyx[0]) if len(anyx) else 0, "x1": int(anyx[-1]) if len(anyx) else -1,
                           "c0": int(corex[0]) if len(corex) else 0, "c1": int(corex[-1]) if len(corex) else -1}
        return self._g[ch]


def white(gl, band, side: str) -> float:
    vals = []
    for r in range(band[0], band[1] + 1):
        if r not in gl["rows"]:
            vals.append(D)
        else:
            a, b = gl["rows"][r]
            vals.append(min(D, a - gl["c0"]) if side == "l" else min(D, gl["c1"] - b))
    return float(np.mean(vals))


def band_of(face: Face, chars="BDEFHIKLMNPRTUZ") -> tuple[int, int]:
    tops, bots = [], []
    for ch in chars:
        if face.has(ch):
            rows = sorted(face.glyph(ch)["rows"])
            if rows:
                tops.append(rows[0])
                bots.append(rows[-1])
    return int(np.median(tops)), int(np.median(bots))


def d_min(ga, gb) -> int:
    """Smallest offset of b's cell origin relative to a's cell origin at which no core pixel of b is
    8-adjacent to or on a core pixel of a (cell coordinates; b to the right of a)."""
    best = -10 ** 6
    for r, (_, a_right) in ga["rows"].items():
        for r2 in (r - 1, r, r + 1):
            if r2 in gb["rows"]:
                best = max(best, a_right + 2 - gb["rows"][r2][0])
    return best


def text_pairs():
    """-> static {font: Counter((a, b))}, runtime {font: Counter((a, b))} (string-variable contexts x names and
    number-variable contexts x digits), uses {font: Counter(char)}."""
    ko = json.loads((ROOT / "work/ko_final.json").read_text("utf-8"))
    style, label = {}, {}
    for f in (ROOT / "text/jp").glob("*.json"):
        for m in json.loads(f.read_text("utf-8"))["messages"]:
            style[m["id"]] = m["style"]
            label[m["id"]] = m.get("label") or ""
    static = {n: Counter() for n in FONTS}
    uses = {n: Counter() for n in FONTS}
    sb = {n: Counter() for n in FONTS}
    sa = {n: Counter() for n in FONTS}
    nb = {n: Counter() for n in FONTS}
    na = {n: Counter() for n in FONTS}
    names = Counter()
    skip = " \0" + SVAR + NVAR
    for mid, t in ko.items():
        st = style.get(mid, 13)
        fonts = [STYLE_FONT.get(st, "font")] if st not in (13, 255) else ["font", "font_btl"]
        if st == 13 and mid.startswith("BMsg/") and not re.search(r"(?i)kj", label.get(mid, "")):
            # battle names (monsters, bosses): drawn in battle only, through MonName_Lv (style 0 = font_btl,
            # Battle.c FUN_11027d84) or the target window's own default (Battle.c line 12882: default font
            # slot 4 = font_btl, colour 0x373737). Bowser Jr. RPG labels (KJ) keep both fonts.
            fonts = ["font_btl"]
        lines = lines_of(t, mark_vars=True)
        if st == 13 and len(lines) == 1 and 1 <= len(lines[0]) <= 16 and SVAR not in lines[0] and NVAR not in lines[0]:
            names[lines[0].strip()] += 1
        for fn in fonts:
            if fn not in static:
                continue
            for ln in lines:
                ln2 = re.sub(r"[\uE000-\uF8FF]", "\0", ln)
                uses[fn].update(c for c in ln2 if c not in skip)
                for a, b in zip(ln2, ln2[1:]):
                    if a in skip or b in skip:
                        if a not in skip and b == SVAR:
                            sb[fn][a] += 1
                        if a == SVAR and b not in skip:
                            sa[fn][b] += 1
                        if a not in skip and b == NVAR:
                            nb[fn][a] += 1
                        if a == NVAR and b not in skip:
                            na[fn][b] += 1
                        continue
                    static[fn][(a, b)] += 1
    runtime = {n: Counter() for n in FONTS}
    for fn in FONTS:
        for nm in names:
            for c in sb[fn]:
                if nm[0] in LATIN or c in LATIN:
                    runtime[fn][(c, nm[0])] += 1
            for c in sa[fn]:
                if nm[-1] in LATIN or c in LATIN:
                    runtime[fn][(nm[-1], c)] += 1
        for d in DIGITS:
            for c in nb[fn]:
                runtime[fn][(c, d)] += 1
            for c in na[fn]:
                runtime[fn][(d, c)] += 1
    return static, runtime, uses, {fn: (dict(nb[fn]), dict(na[fn])) for fn in FONTS}


def main():
    static, runtime, uses, numctx = text_pairs()
    report, table = [], {"rule": __doc__.split("Rule (")[1].split("Inputs :")[0].strip(), "mode": MODE, "D": D,
                         "core_alpha": CORE, "lambda": LAMBDA, "fonts": {}}
    for name in FONTS:
        v1 = Face(V1_MSG / f"{name}.bffnt")
        jp = Face(JP_MSG / f"{name}.bffnt")
        band_v1, band_jp = band_of(v1), band_of(jp)
        jl, jr, jside = [], [], {}
        for ch in LATIN:
            if jp.has(ch):
                g = jp.glyph(ch)
                lb = g["left"] + g["c0"]
                rb = g["adv"] - (g["left"] + g["c1"] + 1)
                jside[ch] = (lb + white(g, band_jp, "l"), rb + white(g, band_jp, "r"))
                jl.append(jside[ch][0])
                jr.append(jside[ch][1])
        T_l, T_r = float(np.median(jl)), float(np.median(jr))
        report.append(f"######## {name} (mode {MODE}): band rows v1 {band_v1}, JP {band_jp}; JP Latin side white "
                      f"median left {T_l:.2f} right {T_r:.2f}, D = {D}")
        # 1 + 2: base bearings (core) per glyph, ink inside the advance box
        cur, base = {}, {}
        for ch in LATIN:
            if not v1.has(ch):
                continue
            g = v1.glyph(ch)
            wl, wr = white(g, band_v1, "l"), white(g, band_v1, "r")
            if MODE in ("box", "stem", "fit"):
                lb_core, rb_core = 0, 1
                if MODE != "box" and ch in STEM:
                    lb_core, rb_core = STEM[ch]
            else:
                tl, tr = jside[ch] if (MODE == "jpchar" and ch in jside) else (T_l, T_r)
                lb_core, rb_core = int(round(tl - wl)), int(round(tr - wr))
            base[ch] = (lb_core, rb_core)
            lbc = max(lb_core, g["c0"] - g["x0"])            # any-ink never left of the pen
            rbc = max(rb_core, g["x1"] - g["c1"])            # any-ink never right of the advance
            cur[ch] = [lbc, rbc, wl, wr, []]                 # core left/right bearing, whites, notes

        def lft(ch):                                         # CWDH.left
            if ch in cur:
                return cur[ch][0] - v1.glyph(ch)["c0"]
            return v1.glyph(ch)["left"]

        def adv(ch):                                         # CWDH.char
            if ch in cur:
                g = v1.glyph(ch)
                return lft(ch) + g["c1"] + 1 + cur[ch][1]
            return v1.glyph(ch)["adv"]

        # 3: constraint pairs
        cons = Counter(static[name])
        cons.update(runtime[name])
        for a in DIGITS:
            for b in DIGITS:
                cons.setdefault((a, b), 0)
        if MODE != "fit":
            for a in LATIN:
                for b in LATIN:
                    cons.setdefault((a, b), 0)
        cons = {p: n for p, n in cons.items() if (p[0] in cur or p[1] in cur) and v1.has(p[0]) and v1.has(p[1])}
        dm = {p: d_min(v1.glyph(p[0]), v1.glyph(p[1])) for p in cons}
        by_glyph = {}
        for p in cons:
            for ch in set(p):
                if ch in cur:
                    by_glyph.setdefault(ch, []).append(p)

        def off(a, b):
            return adv(a) - lft(a) + lft(b)

        def ok(ch):
            return all(off(*p) >= dm[p] for p in by_glyph.get(ch, []))
        # 3: add 1 px on the Latin side where a pair touches (Latin-Latin: the right side of the first)
        for it in range(30):
            bad = sorted(((p, n) for p, n in cons.items() if off(*p) < dm[p]), key=lambda x: -x[1])
            if not bad:
                break
            for (a, b), n in bad:
                if off(a, b) >= dm[(a, b)]:
                    continue
                need = dm[(a, b)] - off(a, b)
                if a in cur:                                 # Latin first: its right side (fit may move it)
                    cur[a][1] += need
                    cur[a][4].append(f"+{need} right for {a}{b} (x{n})")
                else:                                        # other glyph first: the Latin's left side
                    cur[b][0] += need
                    cur[b][4].append(f"+{need} left for {a}{b} (x{n})")
        # 4: local search (mode fit): every text pair with a Latin glyph should keep the gap the base rule gives it
        txt_pairs = [(a, b, n) for (a, b), n in static[name].items()
                     if (a in cur or b in cur) and v1.has(a) and v1.has(b)]
        pairs_of = {}
        for a, b, n in txt_pairs:
            for ch in {a, b}:
                if ch in cur:
                    pairs_of.setdefault(ch, []).append((a, b, n))

        def rb_now(ch, use_base=False):
            if ch in cur:
                return base[ch][1] if use_base else cur[ch][1]
            g = v1.glyph(ch)
            return g["adv"] - (g["left"] + g["c1"] + 1)

        def lb_now(ch, use_base=False):
            if ch in cur:
                return base[ch][0] if use_base else cur[ch][0]
            g = v1.glyph(ch)
            return g["left"] + g["c0"]

        def local_cost(ch):
            c = sum(n * ((rb_now(a) + lb_now(b)) - (rb_now(a, True) + lb_now(b, True))) ** 2
                    for a, b, n in pairs_of.get(ch, []))
            bl, br = base[ch]
            return c + LAMBDA * max(1, uses[name][ch]) * ((cur[ch][0] - bl) ** 2 + (cur[ch][1] - br) ** 2)
        moves = []
        if MODE == "fit":
            for rnd in range(12):
                changed = False
                for ch in sorted(cur, key=lambda c: -uses[name][c]):
                    g = v1.glyph(ch)
                    best = (local_cost(ch), cur[ch][0], cur[ch][1])
                    keep = (cur[ch][0], cur[ch][1])
                    for lbc in range(g["c0"] - g["x0"], 4):
                        for rbc in range(g["x1"] - g["c1"], 4):
                            cur[ch][0], cur[ch][1] = lbc, rbc
                            if not ok(ch):
                                continue
                            c = local_cost(ch)
                            if c < best[0] - 1e-9:
                                best = (c, lbc, rbc)
                    cur[ch][0], cur[ch][1] = best[1], best[2]
                    if (best[1], best[2]) != keep:
                        changed = True
                        moves.append(f"{ch}: {keep[0]}/{keep[1]} -> {best[1]}/{best[2]}")
                if not changed:
                    break
        still = [(p, n) for p, n in cons.items() if off(*p) < dm[p]]
        # report
        out = {}
        report.append(f"constraint pairs: {len(cons)} (text {sum(1 for p in static[name] if p in cons)}, runtime "
                      f"{sum(1 for p in runtime[name] if p in cons)}, digit x digit"
                      + (", all Latin x Latin" if MODE != "fit" else "") + f"); still touching: {len(still)}")
        report.append(f"number-variable contexts (before / after): {numctx[name]}")
        if moves:
            report.append("fit moves (core left/right): " + "; ".join(moves))
        report.append("char uses  v1[left glyph char] -> v2[left glyph char]  core lb/rb (base)  notes")
        for ch in LATIN:
            if ch not in cur:
                continue
            g = v1.glyph(ch)
            lbc, rbc = cur[ch][0], cur[ch][1]
            out[ch] = {"cwdh": [lft(ch), g["glyph"], adv(ch)], "v1_cwdh": [g["left"], g["glyph"], g["adv"]],
                       "core_bearings": [lbc, rbc], "base": list(base[ch]), "uses": uses[name][ch],
                       "side_white": [round(lbc + cur[ch][2], 2), round(rbc + cur[ch][3], 2)], "notes": cur[ch][4]}
            report.append(f"  {ch} {uses[name][ch]:5d}  [{g['left']:2d} {g['glyph']:2d} {g['adv']:2d}] -> "
                          f"[{lft(ch):2d} {g['glyph']:2d} {adv(ch):2d}]  {lbc}/{rbc} ({base[ch][0]}/{base[ch][1]})  "
                          + "; ".join(cur[ch][4][:4]))
        for (a, b), n in still[:20]:
            report.append(f"  STILL TOUCHING {a}{b} x{n}")
        stats = {}
        for (a, b), n in static[name].items():
            if not (v1.has(a) and v1.has(b)):
                continue
            ka = "L" if a in LATIN else ("H" if 0xAC00 <= ord(a) <= 0xD7A3 else None)
            kb = "L" if b in LATIN else ("H" if 0xAC00 <= ord(b) <= 0xD7A3 else None)
            if ka and kb and "L" in (ka, kb):
                ga, gb = v1.glyph(a), v1.glyph(b)
                gp = (adv(a) - (lft(a) + ga["c1"] + 1)) + (lft(b) + gb["c0"])
                stats.setdefault(ka + kb, Counter())[gp] += n
        for k, c in sorted(stats.items()):
            tot = sum(c.values())
            report.append(f"  text {k} core box gap: mean {sum(g * n for g, n in c.items()) / tot:.2f}  "
                          + " ".join(f"{g}:{100 * n / tot:.0f}%" for g, n in sorted(c.items())))
        table["fonts"][name] = {"band_v1": band_v1, "band_jp": band_jp, "jp_side_white_median": [round(T_l, 3),
                                round(T_r, 3)], "constraint_pairs": len(cons),
                                "still_touching": [f"{a}{b}" for (a, b), _ in still], "fit_moves": moves, "chars": out}
        report.append("")
    OUT_JSON.write_text(json.dumps(table, ensure_ascii=False, indent=1), "utf-8")
    OUT_TXT.write_text("\n".join(report), "utf-8")
    print("\n".join(report))


if __name__ == "__main__":
    main()
