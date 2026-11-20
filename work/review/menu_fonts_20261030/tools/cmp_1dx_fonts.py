"""Compare Hangul glyph pixels between the 1DX KR fonts (font vs font_sys, font_btl vs font_sys_btl) and
find the font file name table in the 1DX code (FONT worker, read-only)."""
from __future__ import annotations

import struct
import sys
from pathlib import Path

import numpy as np

ROOT = Path(__file__).resolve().parents[4]
sys.path.insert(0, str(ROOT / "scripts"))
import libbffnt as L  # noqa: E402

KR = ROOT / "ml 1dx/3romfs/Msg/KR_ko"


def load(name):
    f = L.parse((KR / name).read_bytes())
    return f, L.SheetImages(f), f.char_map(), f.widths()


def cmp(a, b):
    fa, sa, ca, wa = load(a)
    fb, sb, cb, wb = load(b)
    common = sorted(set(ca) & set(cb))
    same = diff = wdiff = 0
    hs = hd = 0
    examples = []
    for c in common:
        pa, pb = sa.cell(ca[c]), sb.cell(cb[c])
        eq = pa.shape == pb.shape and np.array_equal(pa, pb)
        weq = (wa[ca[c]].left, wa[ca[c]].glyph, wa[ca[c]].char) == (wb[cb[c]].left, wb[cb[c]].glyph, wb[cb[c]].char)
        if eq:
            same += 1
        else:
            diff += 1
            if len(examples) < 12:
                examples.append(chr(c))
        if not weq:
            wdiff += 1
        if 0xAC00 <= c <= 0xD7A3:
            hs += eq
            hd += not eq
    print(f"{a} vs {b}: common {len(common)} identical {same} different {diff} (hangul same {hs} diff {hd}) "
          f"width-diff {wdiff} e.g. {''.join(examples)!r}; only-in-{a}: {len(set(ca) - set(cb))} only-in-{b}: {len(set(cb) - set(ca))}")


def find_strings(code: Path, needles):
    b = code.read_bytes()
    for n in needles:
        u = n.encode("utf-16-le")
        p = 0
        while True:
            i = b.find(u, p)
            if i < 0:
                break
            print(f"  {code.name}: {n!r} at file 0x{i:X} (addr 0x{i + 0x100000:08X})")
            p = i + 2


def main():
    cmp("font.bffnt", "font_sys.bffnt")
    cmp("font_btl.bffnt", "font_sys_btl.bffnt")
    find_strings(ROOT / "work/fps60/bin/1dx_kr.code.bin", ["font_sys.bffnt", "font_sys_btl.bffnt", "font_l.bffnt",
                                                           "font.bffnt", "font_btl.bffnt"])


if __name__ == "__main__":
    main()
