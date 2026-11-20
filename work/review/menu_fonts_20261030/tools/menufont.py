"""Menu-font unification transform on the installed Korean fonts (FONT worker).

Input : the shipped patch fonts (patch/.../Msg/JP_ja/{font,font_btl}.bffnt) and the 1DX KR donor of the
        same role (ml 1dx/3romfs/Msg/KR_ko/{font,font_btl}.bffnt).
Output: a Bffnt in which every glyph the Korean text uses sits on ONE baseline and non-Hangul glyphs come
        from the same 1DX typeface as the Hangul:
  * Hangul cells (U+AC00..D7A3, whatever their source: 1DX copy, composed, rendered) are moved down by
    `hangul_dy` whole pixels, which puts them on the 1DX arrangement relative to the 3DX Latin baseline
    (font +1, font_btl +1; font_l is left alone).
  * ASCII letters/digits/punctuation (`ascii_set`) get the 1DX glyph pixels, placed with the baseline-aligned
    shift (3DX TGLP baseline - 1DX TGLP baseline) so they share the Hangul's 1DX baseline; advances are
    either the 3DX ones (`adv='3dx'`, ink centred, line widths unchanged) or the 1DX ones (`adv='1dx'`).
  * Nothing else changes: other glyph cells, CMAP, sheet count, every non-listed CWDH entry.
"""
from __future__ import annotations

import sys
from dataclasses import dataclass, field
from pathlib import Path

import numpy as np

ROOT = Path(__file__).resolve().parents[4]
sys.path.insert(0, str(ROOT / "scripts"))
import libbffnt as L  # noqa: E402

PATCH_MSG = ROOT / "patch/00040000001CA900/romfs/Msg/JP_ja"
DONOR_MSG = ROOT / "ml 1dx/3romfs/Msg/KR_ko"

LETTERS_DIGITS = "".join(chr(c) for c in range(0x30, 0x3A)) + "".join(chr(c) for c in range(0x41, 0x5B)) + \
    "".join(chr(c) for c in range(0x61, 0x7B))
PUNCT = "!\"#$%&'()*+,-./:;<=>?@[]^_`{|}~"


@dataclass
class Result:
    font: L.Bffnt
    changed_glyphs: dict = field(default_factory=dict)   # char -> (glyph, what)
    problems: list = field(default_factory=list)
    hangul_moved: int = 0


def is_hangul(cp: int) -> bool:
    return 0xAC00 <= cp <= 0xD7A3


def move_cell(si: L.SheetImages, g: int, dy: int) -> bool:
    """Move a glyph cell's pixels down by dy (dy > 0) inside the cell; False if ink would be cut."""
    c = si.cell(g)
    if dy == 0:
        return True
    if dy > 0:
        if c[-dy:].any():
            return False
        new = np.zeros_like(c)
        new[dy:] = c[:-dy]
    else:
        if c[:-dy].any():
            return False
        new = np.zeros_like(c)
        new[:dy] = c[-dy:]
    si.put(g, new)
    return True


def transform(name: str, hangul_dy: int, ascii_set: str, adv: str = "3dx",
              src: Path | None = None, donor: Path | None = None) -> Result:
    data = (src or PATCH_MSG / f"{name}.bffnt").read_bytes()
    f = L.parse(data)
    d = L.parse((donor or DONOR_MSG / f"{name}.bffnt").read_bytes())
    si, sd = L.SheetImages(f), L.SheetImages(d)
    cmap, dmap = f.char_map(), d.char_map()
    res = Result(f)
    # 1. Hangul on the 1DX arrangement
    if hangul_dy:
        for cp, g in cmap.items():
            if is_hangul(cp):
                if move_cell(si, g, hangul_dy):
                    res.hangul_moved += 1
                else:
                    res.problems.append(f"{name}: Hangul {chr(cp)} would lose ink when moved {hangul_dy}")
    # 2. non-Hangul glyphs from the donor, baseline aligned
    shift = f.baseline - d.baseline + hangul_dy + _hangul_bias(name)
    widths = {}
    for start, ws in f.cwdh:
        for i, w in enumerate(ws):
            widths[start + i] = (start, i)
    for ch in ascii_set:
        cp = ord(ch)
        if cp not in cmap or cp not in dmap:
            continue
        g, gd = cmap[cp], dmap[cp]
        shared = [c for c, gg in cmap.items() if gg == g and c != cp]
        if shared:
            res.problems.append(f"{name}: {ch!r} glyph {g} shared with {''.join(map(chr, shared))} -> skipped")
            continue
        dc = sd.cell(gd)
        new = np.zeros((f.cell_h, f.cell_w), np.uint8)
        ys, xs = np.nonzero(dc)
        if not len(ys):
            continue
        y0, y1, x0, x1 = ys.min(), ys.max(), xs.min(), xs.max()
        ny0, ny1 = y0 + shift, y1 + shift
        ink_w = x1 - x0 + 1
        if ny0 < 0 or ny1 >= f.cell_h or ink_w > f.cell_w:
            res.problems.append(f"{name}: {ch!r} does not fit the 3DX cell (rows {ny0}..{ny1}, ink {ink_w})")
            continue
        new[ny0:ny1 + 1, 0:ink_w] = dc[y0:y1 + 1, x0:x1 + 1]
        dw = d.widths()[gd]
        s, i = widths[g]
        old = f.cwdh[[k for k, (st, _) in enumerate(f.cwdh) if st == s][0]][1][i]
        lb1 = dw.left + int(x0)                       # 1DX side bearings of the alpha>0 ink box
        rb1 = dw.char - (dw.left + int(x1) + 1)
        if adv == "1dx":
            char, left = dw.char, lb1
        elif adv == "centre":
            char = old.char
            left = int(round((char - ink_w) / 2))
        else:  # "3dx": keep the shipped advance, grow only when the ink leaves < 1 px of side bearing
            char = old.char
            if char - ink_w < 1:
                char = max(char, min(int(ink_w) + 1, dw.char))
            t = char - int(ink_w)
            if lb1 < 0 or rb1 < 0:                    # glyphs that 1DX lets overhang ('j', ',' ...)
                left = max(min(lb1, t), t - max(rb1, 0)) if t >= 0 else lb1
            elif lb1 + rb1 > 0:
                left = int(round(t * lb1 / (lb1 + rb1)))
            else:
                left = t // 2
            left = int(left)
        nw = L.CharWidth(left=int(left), glyph=int(ink_w), char=int(char))
        si.put(g, new)
        blk = [k for k, (st, _) in enumerate(f.cwdh) if st == s][0]
        f.cwdh[blk][1][i] = nw
        res.changed_glyphs[ch] = (g, f"1dx pixels, adv {old.char}->{char}, left {old.left}->{left}, ink {ink_w}")
    si.commit()
    return res


def _hangul_bias(name: str) -> int:
    """Shift that the shipped build gave the Hangul beyond baseline alignment (build_font donor_shift cjk minus
    TGLP baseline difference): font +1-2 = -1, font_btl -1-0 = -1, font_l 2-3 = -1. Adding it to the donor
    baseline shift + hangul_dy puts ASCII exactly where 1DX has it relative to the (moved) Hangul."""
    return -1


if __name__ == "__main__":
    mode = sys.argv[1] if len(sys.argv) > 1 else "3dx"
    for n in ("font", "font_btl"):
        r = transform(n, 0, LETTERS_DIGITS + PUNCT, adv=mode)
        grown = {c: w for c, (g, w) in r.changed_glyphs.items() if "adv " in w and w.split("adv ")[1].split(",")[0].split("->")[0] != w.split("->")[1].split(",")[0]}
        print(f"{n}: changed {len(r.changed_glyphs)} glyphs, advance changed for {len(grown)}: "
              + " ".join(f"{c}({w.split('adv ')[1].split(',')[0]})" for c, w in grown.items()))
        for p in r.problems:
            print("  problem:", p)
