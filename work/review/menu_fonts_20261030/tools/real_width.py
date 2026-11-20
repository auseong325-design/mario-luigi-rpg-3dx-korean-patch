"""Real pixel widths of every Korean line in the font the game draws it with (style -> font as in
MessageSimple::GetFont; style 13/255 = writer default -> checked in font AND font_btl), shipped fonts vs a
candidate font pair, against the widest Japanese line of the same (source, style) drawn with the original
3DX font (the box proxy). Usage: real_width.py <cand_font.bffnt> <cand_font_btl.bffnt> [out.txt]"""
from __future__ import annotations

import json
import re
import sys
from collections import defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from render import ROOT, Font, get_font  # noqa: E402

TAG = re.compile(r"\[([^\[\]]*)\]")
STYLE_FONT = {0: "font_btl", 5: "font_btl", 8: "font_btl", 1: "font", 6: "font", 9: "font",
              2: "font_l", 7: "font_l", 10: "font_l", 3: "font_btl", 11: "font_btl"}


def lines_of(text: str):
    """Visible lines; icons -> '\\uE000'-range chars kept, [Ruby a;b] -> a, other tags removed."""
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
        pos = m.end()
    out.append(text[pos:])
    return [ln for ln in "".join(out).split("\n") if ln.strip()]


def adv_table(font: Font, gaizi: Font):
    cache = {}

    def w(ch):
        if ch not in cache:
            cp = ord(ch)
            f = gaizi if 0xE000 <= cp <= 0xF8FF else font
            cache[ch] = f.glyph(cp)[3]
        return cache[ch]
    return lambda s: sum(w(c) for c in s)


def main():
    cand_font, cand_btl = sys.argv[1], sys.argv[2]
    out_path = Path(sys.argv[3]) if len(sys.argv) > 3 else ROOT / "work/review/menu_fonts_20261030/real_width.txt"
    gz = get_font("gaizi")
    W = {
        ("jp", "font"): adv_table(get_font("jp:font"), gz), ("jp", "font_btl"): adv_table(get_font("jp:font_btl"), gz),
        ("ko", "font"): adv_table(get_font("ko:font"), gz), ("ko", "font_btl"): adv_table(get_font("ko:font_btl"), gz),
        ("new", "font"): adv_table(Font("cand_font", Path(cand_font).read_bytes()), gz),
        ("new", "font_btl"): adv_table(Font("cand_btl", Path(cand_btl).read_bytes()), gz),
    }
    ko = json.loads((ROOT / "work/ko_final.json").read_text("utf-8"))
    jp_msgs = {}
    for f in (ROOT / "text/jp").glob("*.json"):
        for m in json.loads(f.read_text("utf-8"))["messages"]:
            jp_msgs[m["id"]] = m
    jpmax = defaultdict(int)
    work = []
    for mid, m in jp_msgs.items():
        st = m["style"]
        fonts = [STYLE_FONT.get(st, "font")] if st not in (13, 255) else ["font", "font_btl"]
        key = (mid.split("/")[0].split("#")[0], st)
        for fn in fonts:
            if fn == "font_l":
                continue
            for ln in lines_of(m["jp"]):
                jpmax[(key, fn)] = max(jpmax[(key, fn)], W[("jp", fn)](ln))
            if mid in ko:
                for ln in lines_of(ko[mid]):
                    work.append((mid, key, fn, ln))
    newly, grown, n = [], 0, 0
    for mid, key, fn, ln in work:
        n += 1
        a, b = W[("ko", fn)](ln), W[("new", fn)](ln)
        lim = jpmax[(key, fn)]
        if b != a:
            grown += 1
        if b > lim >= a:
            newly.append((mid, key, fn, lim, a, b, ln))
    over_before = sum(1 for mid, key, fn, ln in work if W[("ko", fn)](ln) > jpmax[(key, fn)])
    rep = [f"{n} (line, font) pairs; width changed in {grown}; over the JP max of their group before: {over_before} "
           f"(shipped, for reference); newly over because of the candidate: {len(newly)}"]
    for mid, key, fn, lim, a, b, ln in newly:
        rep.append(f"  NEW-OVER {mid} {key} {fn}: JP max {lim}px, shipped {a}px -> {b}px: {ln!r}")
    deltas = sorted(((W[("new", fn)](ln) - W[("ko", fn)](ln), mid, fn, ln) for mid, key, fn, ln in work), reverse=True)
    rep.append("largest growth:")
    for d, mid, fn, ln in deltas[:15]:
        rep.append(f"  +{d}px {mid} {fn}: {ln!r}")
    out_path.write_text("\n".join(rep), "utf-8")
    print("\n".join(rep[:60]))


if __name__ == "__main__":
    main()
