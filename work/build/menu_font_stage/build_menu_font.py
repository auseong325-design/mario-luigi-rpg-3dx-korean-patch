"""Staged build (FONT, wave 5, 2026-10-30): one design and one baseline per Korean font.

    .venv\\Scripts\\python work\\build\\menu_font_stage\\build_menu_font.py          build + verify
    .venv\\Scripts\\python work\\build\\menu_font_stage\\build_menu_font.py --check  verify the staged files only

Problem (work/review/menu_fonts_20261030/REPORT.md): in the menus (and everywhere else) the Korean fonts mix two
typefaces in one string: Hangul are 1DX Korean glyphs, Latin letters / digits / most ASCII punctuation are the
Japanese 3DX glyphs (wider, rounder, soft edges) and sit 1 px lower than the Hangul (font, font_btl); the 1DX
punctuation build_font.py added ('!' ',' ':' '%' '~') sits 1-2 px lower than in 1DX.

Rule implemented here, for font.bffnt and font_btl.bffnt (font_l untouched):
  * Hangul and every other glyph stay as installed, except the characters in CHARS (ASCII letters, digits,
    ASCII punctuation) that both the installed font and the 1DX KR font of the same role have.
  * Those get the 1DX glyph pixels unchanged (alpha > 0 ink box), moved vertically by the same whole-pixel shift
    the installed Hangul got (TGLP baseline difference - 1: font +1, font_btl -1), so Latin, digits, punctuation
    and Hangul keep exactly the 1DX relation to each other (one baseline, one design).
  * Advance (CWDH.char) stays the installed one (= the scripts/merge_ko.py width model) when the 1DX ink leaves
    at least 1 px of side bearing; otherwise it grows to ink + 1 px, never beyond the 1DX advance. The free
    bearing is split in the 1DX proportions. The space keeps its 3DX width.
  * Nothing else changes: sheet count/size/format, CMAP, every other CWDH entry and glyph cell.
Inputs : patch/00040000001CA900/romfs/Msg/JP_ja/{font,font_btl}.bffnt (installed build, read-only)
         ml 1dx/3romfs/Msg/KR_ko/{font,font_btl}.bffnt (1DX KR, read-only)
Outputs: work/build/menu_font_stage/romfs/Msg/JP_ja/{font,font_btl}.bffnt, manifest.json
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
import libbffnt as L  # noqa: E402

PATCH_MSG = ROOT / "patch/00040000001CA900/romfs/Msg/JP_ja"
DONOR_MSG = ROOT / "ml 1dx/3romfs/Msg/KR_ko"
OUT_MSG = STAGE / "romfs/Msg/JP_ja"
MANIFEST = STAGE / "manifest.json"
FONTS = ["font", "font_btl"]
CHARS = ("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
         "!\"#$%&'()*+,-./:;<=>?@[]^_`{|}~")
CORE = 4          # alpha (0..15) from which a pixel counts as glyph core for spacing decisions
LEADING = "([{"
INFIX = "&+=/-*#@^_|\\<>$"
# "hybrid" (chosen, see REPORT.md section 4): letters and digits take the 1DX CWDH as they are; punctuation keeps
# the installed advance (= the merge_ko width model) and grows only when its core would touch a neighbour.
# "1dx" = 1DX CWDH for every replaced glyph | "min" = installed advance for every replaced glyph (both rejected).
SPACING = "hybrid"
for _a in sys.argv[1:]:
    if _a.startswith("--spacing="):
        SPACING = _a.split("=", 1)[1]
    if _a.startswith("--out="):
        OUT_MSG = Path(_a.split("=", 1)[1])
        MANIFEST = OUT_MSG / "manifest.json"
    if _a.startswith("--in="):            # other input folder (idempotency test: --in=<staged folder>)
        PATCH_MSG = Path(_a.split("=", 1)[1])


def sha(b: bytes) -> str:
    return hashlib.sha256(b).hexdigest().upper()


def cwdh_slot(f: L.Bffnt, g: int) -> tuple[int, int]:
    for k, (start, ws) in enumerate(f.cwdh):
        if start <= g < start + len(ws):
            return k, g - start
    raise KeyError(g)


def transform(name: str, src: bytes, donor: bytes):
    f = L.parse(src)
    d = L.parse(donor)
    si, sd = L.SheetImages(f), L.SheetImages(d)
    cmap, dmap = f.char_map(), d.char_map()
    dwid = d.widths()
    shift = f.baseline - d.baseline - 1          # = build_font.py donor_shift[cjk] (font +1, font_btl -1)
    changes, skipped = [], []
    users: dict[int, list[int]] = {}
    for cp, g in cmap.items():
        users.setdefault(g, []).append(cp)
    for ch in CHARS:
        cp = ord(ch)
        if cp not in cmap or cp not in dmap:
            continue
        g, gd = cmap[cp], dmap[cp]
        if len(users[g]) > 1:
            skipped.append(f"{ch!r}: glyph {g} shared by {''.join(map(chr, users[g]))}")
            continue
        dc = sd.cell(gd)
        ys, xs = np.nonzero(dc)
        if not len(ys):
            skipped.append(f"{ch!r}: empty in 1DX")
            continue
        y0, y1, x0, x1 = int(ys.min()), int(ys.max()), int(xs.min()), int(xs.max())
        w = x1 - x0 + 1
        if y0 + shift < 0 or y1 + shift >= f.cell_h or w > f.cell_w:
            skipped.append(f"{ch!r}: does not fit the cell (rows {y0 + shift}..{y1 + shift}, ink {w})")
            continue
        new = np.zeros((f.cell_h, f.cell_w), np.uint8)
        new[y0 + shift:y1 + shift + 1, 0:w] = dc[y0:y1 + 1, x0:x1 + 1]
        dw = dwid[gd]
        k, i = cwdh_slot(f, g)
        old = f.cwdh[k][1][i]
        # spacing is decided on the glyph core (alpha >= CORE), faint edge pixels may reach 1 px further
        cx = np.nonzero((dc >= CORE).any(axis=0))[0]
        c0, c1 = (int(cx.min()), int(cx.max())) if len(cx) else (x0, x1)
        core_w = c1 - c0 + 1
        core_lb1 = dw.left + c0                       # 1DX side bearing left of the core
        if SPACING == "1dx" or (SPACING == "hybrid" and ch.isalnum()):   # the 1DX metrics as they are
            char, left = dw.char, dw.left + x0
        else:                                         # "min": installed advance, grown only if the core touches
            char = old.char
            if char - core_w < 1:
                char = max(char, min(core_w + 1, dw.char))
            t = char - core_w
            core_rb1 = dw.char - (dw.left + c1 + 1)
            if core_lb1 < 0:                          # 1DX lets it overhang on the left ('j'): keep that
                core_left = core_lb1
            elif ch in LEADING:                       # '(' hugs what follows: keep the 1DX right bearing
                core_left = max(t - max(core_rb1, 0), 0)
            elif ch in INFIX:                         # '&' '+' '=' '/': split in the 1DX proportions
                core_left = int(round(t * core_lb1 / (core_lb1 + core_rb1))) if core_lb1 + core_rb1 > 0 else t // 2
            else:                                     # trailing ('.' ',' '!' '?' ')' ':' '~'): left bearing
                core_left = min(core_lb1, max(t, 0))
            left = core_left - (c0 - x0)
        nw = L.CharWidth(left=int(left), glyph=int(w), char=int(char))
        old_cell = si.cell(g).copy()
        si.put(g, new)
        f.cwdh[k][1][i] = nw
        changes.append({"char": ch, "code": f"U+{cp:04X}", "glyph": g, "donor_glyph": gd,
                        "was_from": "3DX" if old_cell.any() and name else "?",
                        "cwdh_old": [old.left, old.glyph, old.char], "cwdh_new": [nw.left, nw.glyph, nw.char],
                        "donor_cwdh": [dw.left, dw.glyph, dw.char], "rows": [y0 + shift, y1 + shift],
                        "advance_delta": nw.char - old.char})
    si.commit()
    return f, changes, skipped, shift


def verify(name: str, src: bytes, out: bytes, donor: bytes, changes: list, shift: int) -> list[str]:
    errs = []
    a, b, d = L.parse(src), L.parse(out), L.parse(donor)
    if L.build(L.parse(out)) != out:
        errs.append("output does not round-trip through libbffnt")
    for attr in ("cell_w", "cell_h", "baseline", "sheet_fmt", "sheet_w", "sheet_h", "sheet_size", "cols", "rows",
                 "height", "width", "ascent", "line_feed", "alter_char", "font_type", "encoding"):
        if getattr(a, attr) != getattr(b, attr):
            errs.append(f"{attr} changed")
    if len(a.sheets) != len(b.sheets) or len(out) != len(src):
        errs.append(f"sheet count / size changed ({len(a.sheets)}->{len(b.sheets)}, {len(src)}->{len(out)})")
    if [(c.begin, c.end, c.method, c.base, c.table, c.scan) for c in a.cmaps] != \
       [(c.begin, c.end, c.method, c.base, c.table, c.scan) for c in b.cmaps]:
        errs.append("CMAP changed")
    changed = {c["glyph"] for c in changes}
    wa, wb = a.widths(), b.widths()
    for g in wa:
        if g not in changed and (wa[g].left, wa[g].glyph, wa[g].char) != (wb[g].left, wb[g].glyph, wb[g].char):
            errs.append(f"CWDH of untouched glyph {g} changed")
    sa, sb, sd = L.SheetImages(a), L.SheetImages(b), L.SheetImages(d)
    mask = [np.ones((a.sheet_h, a.sheet_w), bool) for _ in a.sheets]
    for g in range(a.glyph_count()):
        s, x, y = a.cell_origin(g)
        if s >= len(mask):
            continue
        mask[s][y:y + a.cell_h, x:x + a.cell_w] = False
        if g not in changed and not np.array_equal(sa.cell(g), sb.cell(g)):
            errs.append(f"pixels of untouched glyph {g} changed")
    for s in range(len(a.sheets)):
        if not np.array_equal(sa.images[s][mask[s]], sb.images[s][mask[s]]):
            errs.append(f"sheet {s}: pixels outside the glyph cells changed")
    dmap = d.char_map()
    for c in changes:
        cell = sb.cell(c["glyph"])
        dc = sd.cell(dmap[ord(c["char"])])
        ys, xs = np.nonzero(dc)
        ink = dc[ys.min():ys.max() + 1, xs.min():xs.max() + 1]
        r0 = ys.min() + shift
        if not np.array_equal(cell[r0:r0 + ink.shape[0], 0:ink.shape[1]], ink) or cell.sum() != ink.sum():
            errs.append(f"{c['char']!r}: staged pixels are not the 1DX ink")
    return errs


def main():
    check_only = "--check" in sys.argv
    OUT_MSG.mkdir(parents=True, exist_ok=True)
    man = {"rule": __doc__.split("Rule implemented here")[1].split("Inputs :")[0].strip(), "spacing": SPACING,
           "fonts": {}}
    all_errs = []
    for name in FONTS:
        src = (PATCH_MSG / f"{name}.bffnt").read_bytes()
        donor = (DONOR_MSG / f"{name}.bffnt").read_bytes()
        if L.build(L.parse(src)) != src:
            all_errs.append(f"{name}: installed font does not round-trip (libbffnt)")
        f, changes, skipped, shift = transform(name, src, donor)
        out = L.build(f)
        dst = OUT_MSG / f"{name}.bffnt"
        if check_only:
            if dst.read_bytes() != out:
                all_errs.append(f"{name}: staged file differs from a fresh build")
        else:
            dst.write_bytes(out)
        errs = verify(name, src, out, donor, changes, shift)
        all_errs += [f"{name}: {e}" for e in errs]
        man["fonts"][name] = {
            "input": str((PATCH_MSG / f"{name}.bffnt").relative_to(ROOT)), "input_sha256": sha(src),
            "donor": str((DONOR_MSG / f"{name}.bffnt").relative_to(ROOT)), "donor_sha256": sha(donor),
            "output": str(dst.relative_to(ROOT)), "output_sha256": sha(out), "size": len(out),
            "vertical_shift_vs_1dx_cell": shift, "changed": changes, "skipped": skipped,
            "advance_changes": {c["char"]: [c["cwdh_old"][2], c["cwdh_new"][2]] for c in changes
                                if c["advance_delta"]},
            "verify_errors": errs}
        print(f"{name}: {len(changes)} glyphs replaced, {sum(1 for c in changes if c['advance_delta'])} advances "
              f"changed, {len(skipped)} skipped, verify errors {len(errs)}; sha256 {sha(out)[:16]}")
        for s in skipped:
            print("   skipped", s)
    man["ok"] = not all_errs
    if not check_only:
        MANIFEST.write_text(json.dumps(man, ensure_ascii=False, indent=1), "utf-8")
    for e in all_errs:
        print("ERROR", e)
    sys.exit(1 if all_errs else 0)


if __name__ == "__main__":
    main()
