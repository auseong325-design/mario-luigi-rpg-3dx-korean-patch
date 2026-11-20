"""Staged build v2 (FONT2, wave 5, 2026-10-30): v1 glyphs (1DX shapes on the Hangul baseline) with tight advances.

    .venv\\Scripts\\python work\\build\\menu_font_stage\\build_menu_font_v2.py          build + verify
    .venv\\Scripts\\python work\\build\\menu_font_stage\\build_menu_font_v2.py --check  verify the staged v2 files only

v1 (build_menu_font.py, FONT) replaced 75 ASCII glyphs in font.bffnt / font_btl.bffnt with 1DX glyphs and gave
letters and digits the 1DX CWDH; the lead found the result letter-spaced ('P O W부츠D X', 'E x c e l l e n t').
v2 = the v1 transform, unchanged pixels and rows, then CWDH (left, glyph, char) of the letters and digits from
v2_spacing.json (derived by v2_spacing.py: JP-original Latin letterfit = 0 px left / 1 px right of the core ink,
one-stroke glyphs I i l 1 a little wider, ink never outside the advance box, no touching neighbours in the
Korean text). Punctuation, space and everything else stay as v1 / as installed.
Inputs : patch/00040000001CA900/romfs/Msg/JP_ja/{font,font_btl}.bffnt (installed, read-only),
         ml 1dx/3romfs/Msg/KR_ko/{font,font_btl}.bffnt (1DX KR, read-only) - both through build_menu_font.transform,
         work/build/menu_font_stage/v2_spacing.json
Outputs: work/build/menu_font_stage/v2/romfs/Msg/JP_ja/{font,font_btl}.bffnt, v2/manifest.json,
         v2/merge_ko_ascii_widths.json (advance table for scripts/merge_ko.py)
"""
from __future__ import annotations

import hashlib
import json
import sys
from pathlib import Path

import numpy as np

STAGE = Path(__file__).resolve().parent
ROOT = STAGE.parents[2]
sys.path.insert(0, str(ROOT / "scripts"))
sys.path.insert(0, str(STAGE))
_argv, sys.argv = sys.argv, sys.argv[:1]          # build_menu_font parses its own options at import time
import build_menu_font as V1  # noqa: E402
sys.argv = _argv
import libbffnt as L  # noqa: E402

OUT = STAGE / "v2"
OUT_MSG = OUT / "romfs/Msg/JP_ja"
TABLE = STAGE / "v2_spacing.json"
V1_STAGED = STAGE / "romfs/Msg/JP_ja"
FONTS = ["font", "font_btl"]


def sha(b: bytes) -> str:
    return hashlib.sha256(b).hexdigest().upper()


def slot(f: L.Bffnt, g: int):
    for k, (start, ws) in enumerate(f.cwdh):
        if start <= g < start + len(ws):
            return k, g - start
    raise KeyError(g)


def build(name: str, table: dict):
    src = (V1.PATCH_MSG / f"{name}.bffnt").read_bytes()
    donor = (V1.DONOR_MSG / f"{name}.bffnt").read_bytes()
    f, changes, skipped, shift = V1.transform(name, src, donor)
    v1_bytes = L.build(f)
    f = L.parse(v1_bytes)
    cmap = f.char_map()
    rows = []
    for ch, t in table["fonts"][name]["chars"].items():
        g = cmap[ord(ch)]
        k, i = slot(f, g)
        old = f.cwdh[k][1][i]
        left, glyph, char = t["cwdh"]
        if glyph != old.glyph:
            raise ValueError(f"{name} {ch!r}: table glyph width {glyph} != v1 {old.glyph}")
        f.cwdh[k][1][i] = L.CharWidth(left=left, glyph=glyph, char=char)
        rows.append({"char": ch, "glyph": g, "cwdh_v1": [old.left, old.glyph, old.char], "cwdh_v2": [left, glyph, char],
                     "core_bearings": t["core_bearings"], "advance_delta_vs_v1": char - old.char,
                     "notes": t.get("notes", [])})
    return src, v1_bytes, L.build(f), rows, changes


def verify(name: str, src: bytes, v1b: bytes, out: bytes, rows: list, v1_changes: list) -> list[str]:
    errs = []
    a, b, v = L.parse(src), L.parse(out), L.parse(v1b)
    if L.build(L.parse(out)) != out:
        errs.append("output does not round-trip through libbffnt")
    if (V1_STAGED / f"{name}.bffnt").exists() and (V1_STAGED / f"{name}.bffnt").read_bytes() != v1b:
        errs.append("in-memory v1 transform differs from the staged v1 file")
    for attr in ("cell_w", "cell_h", "baseline", "sheet_fmt", "sheet_w", "sheet_h", "sheet_size", "cols", "rows",
                 "height", "width", "ascent", "line_feed", "alter_char", "font_type", "encoding", "default_width",
                 "tglp_gap", "krng"):
        if getattr(a, attr) != getattr(b, attr):
            errs.append(f"{attr} changed vs installed")
    if len(out) != len(src) or len(a.sheets) != len(b.sheets):
        errs.append(f"size / sheet count changed ({len(src)}->{len(out)}, {len(a.sheets)}->{len(b.sheets)})")
    if b.sheets != v.sheets:
        errs.append("sheet pixels differ from v1 (v2 must only change CWDH)")
    if [(c.begin, c.end, c.method, c.base, c.table, c.scan) for c in a.cmaps] != \
       [(c.begin, c.end, c.method, c.base, c.table, c.scan) for c in b.cmaps]:
        errs.append("CMAP changed")
    v1_glyphs = {c["glyph"] for c in v1_changes}
    v2_glyphs = {r["glyph"] for r in rows}
    if not v2_glyphs <= v1_glyphs:
        errs.append("v2 touches a glyph that v1 did not replace")
    wa, wb, wv = a.widths(), b.widths(), v.widths()
    for g in wa:
        tri = lambda w: (w.left, w.glyph, w.char)  # noqa: E731
        if g not in v1_glyphs and tri(wa[g]) != tri(wb[g]):
            errs.append(f"CWDH of glyph {g} (not replaced by v1) changed")
        if g in v1_glyphs and g not in v2_glyphs and tri(wv[g]) != tri(wb[g]):
            errs.append(f"CWDH of v1 glyph {g} (not a letter/digit) differs from v1")
    # pixels outside the v1-replaced cells identical to the installed font (inherited from v1, re-checked here)
    sa, sb = L.SheetImages(a), L.SheetImages(b)
    for g in range(a.glyph_count()):
        if g not in v1_glyphs and not np.array_equal(sa.cell(g), sb.cell(g)):
            errs.append(f"pixels of glyph {g} differ from installed")
            break
    # every changed letter/digit: whole ink inside its advance box, glyph image not cut
    for r in rows:
        g = r["glyph"]
        left, glyph, char = r["cwdh_v2"]
        cell = sb.cell(g)
        xs = np.nonzero(cell.any(axis=0))[0]
        if len(xs) and (xs[-1] + 1 > glyph):
            errs.append(f"{r['char']!r}: ink beyond the glyph width (cut)")
        if left < 0 or left + glyph > char:
            errs.append(f"{r['char']!r}: ink box outside the advance ({left}, {glyph}, {char})")
    return errs


def main():
    check = "--check" in sys.argv
    table = json.loads(TABLE.read_text("utf-8"))
    OUT_MSG.mkdir(parents=True, exist_ok=True)
    man = {"rule": table["rule"], "table": str(TABLE.relative_to(ROOT)), "table_sha256": sha(TABLE.read_bytes()),
           "fonts": {}}
    widths = {"note": "Advance table for scripts/merge_ko.py after the v2 fonts are installed (FONT2, wave 5): "
                      "merge_ko takes ASCII advances from the ORIGINAL 3DX font.bffnt + EXTRA_ASCII_WIDTH; add "
                      "adv.update(json.load(open(ROOT/'work/build/menu_font_stage/v2/merge_ko_ascii_widths.json'))"
                      "['font']) after EXTRA_ASCII_WIDTH.", "font": {}, "font_btl_for_reference": {}}
    errs_all = []
    for name in FONTS:
        src, v1b, out, rows, v1_changes = build(name, table)
        dst = OUT_MSG / f"{name}.bffnt"
        if check:
            if not dst.exists() or dst.read_bytes() != out:
                errs_all.append(f"{name}: staged v2 file differs from a fresh build")
        else:
            dst.write_bytes(out)
        errs = verify(name, src, v1b, out, rows, v1_changes)
        errs_all += [f"{name}: {e}" for e in errs]
        man["fonts"][name] = {"input": str((V1.PATCH_MSG / f"{name}.bffnt").relative_to(ROOT)), "input_sha256": sha(src),
                              "v1_sha256": sha(v1b), "output": str(dst.relative_to(ROOT)), "output_sha256": sha(out),
                              "size": len(out), "letters_digits": rows, "verify_errors": errs}
        f = L.parse(out)
        wmap = f.widths()
        adv = {chr(c): wmap[g].char for c, g in f.char_map().items() if c < 0x80}
        if name == "font":
            sys.path.insert(0, str(ROOT / "scripts"))
            import merge_ko as M
            model, _ = M.charset()
            widths["font"] = {ch: a for ch, a in sorted(adv.items()) if model.get(ch) != a}
        else:
            inst = L.parse(src)
            iw = inst.widths()
            iadv = {chr(c): iw[g].char for c, g in inst.char_map().items() if c < 0x80}
            widths["font_btl_for_reference"] = {ch: [iadv.get(ch), a] for ch, a in sorted(adv.items())
                                                if iadv.get(ch) != a}
        print(f"{name}: {len(rows)} letters/digits re-spaced, sum of advance changes vs v1 "
              f"{sum(r['advance_delta_vs_v1'] for r in rows):+d} px, verify errors {len(errs)}; sha256 {sha(out)[:16]}")
    man["ok"] = not errs_all
    if not check:
        (OUT / "manifest.json").write_text(json.dumps(man, ensure_ascii=False, indent=1), "utf-8")
        (OUT / "merge_ko_ascii_widths.json").write_text(json.dumps(widths, ensure_ascii=False, indent=1), "utf-8")
    for e in errs_all:
        print("ERROR", e)
    sys.exit(1 if errs_all else 0)


if __name__ == "__main__":
    main()
