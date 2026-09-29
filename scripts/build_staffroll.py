"""Build the Korean staffroll (Staffroll/JP/Staffroll.bin + Staffroll/mario_font.bffnt).

  python scripts/build_staffroll.py --export     # (re)write the readable JSON lists (keeps `ko`)
  python scripts/build_staffroll.py --identity   # codec round trips == original bytes
  python scripts/build_staffroll.py              # build -> work/build/staffroll_stage/romfs/...,
                                                 # re-read verification, previews

Readable lists (work/img/staffroll/):
  staffroll.json          3DX lines: i, section, kind, jp, ko, color, size, size_bits, in_1dx, basis.
                          Only `ko` (and `basis`) may be edited; line count, colours and sizes are
                          the scroll timing and are always taken from the original file.
  staffroll_1dx_kr.json   1DX Korean staffroll, same fields (reference only).
  name_check.tsv          3DX names/roles vs 1DX KR: identical / similar (same surname) / 3DX only.

Font: the game reads rom:/Staffroll/mario_font.bffnt (RO/Field.cro) for every line. Characters
the Korean text needs that the font lacks are copied pixel for pixel, with their 1DX widths,
from the 1DX Korean ml 1dx/3romfs/Staffroll/KR/mario_font_kr.bffnt (same glyph design: its
Latin glyphs are pixel-identical to the 3DX font; cell 25x31 vs 26x31, same baseline 24).
Existing glyphs, widths, mappings and the KRNG kerning block are unchanged.
"""

from __future__ import annotations

import argparse
import json
import struct
import sys
from pathlib import Path

import numpy as np
from PIL import Image, ImageDraw

sys.path.insert(0, str(Path(__file__).resolve().parent))
import lib3dx  # noqa: E402
import libbffnt as L  # noqa: E402
import libstaffroll as SR  # noqa: E402

ROOT = lib3dx.ROOT
SR_REL = "Staffroll/JP/Staffroll.bin"
FONT_REL = "Staffroll/mario_font.bffnt"
KR_DIR = ROOT / "ml 1dx" / "3romfs" / "Staffroll"
KR_BIN = KR_DIR / "KR" / "Staffroll.bin"
KR_FONT = KR_DIR / "KR" / "mario_font_kr.bffnt"
IMG_DIR = ROOT / "work" / "img" / "staffroll"
JSON_PATH = IMG_DIR / "staffroll.json"
REVIEW_DIR = ROOT / "work" / "img" / "review"
STAGE = ROOT / "work" / "build" / "staffroll_stage" / "romfs"
SCREEN_W, SCREEN_H = 400, 240


# --------------------------------------------------------------------- JSON lists
def kind_of(ln: SR.Line, game: str) -> str:
    if not ln.text:
        return "blank"
    teal = ln.color == (SR.TEAL_3DX if game == "3dx" else 0x07C4A6FF)
    return "role" if teal else "name"


def to_records(lines: list[SR.Line], game: str, other_texts: set[str]) -> list[dict]:
    recs, section, prev_blank = [], 0, True
    for i, ln in enumerate(lines):
        k = kind_of(ln, game)
        if k != "blank" and prev_blank and i:
            section += 1
        prev_blank = k == "blank"
        recs.append({"i": i, "section": section, "kind": k, "jp" if game == "3dx" else "text": ln.text,
                     "color": f"0x{ln.color:08X}", "size": ln.size, "size_bits": f"0x{ln.size_bits:08X}",
                     "in_other": ln.text in other_texts if ln.text else None})
    return recs


def load_orig() -> tuple[bytes, list[SR.Line], bytes, list[SR.Line]]:
    jp_data = lib3dx.romfs_path(SR_REL).read_bytes()
    kr_data = KR_BIN.read_bytes()
    return jp_data, SR.read(jp_data), kr_data, SR.read(kr_data)


def cmd_export() -> int:
    _, jp, _, kr = load_orig()
    kr_texts = {ln.text for ln in kr}
    jp_texts = {ln.text for ln in jp}
    old = {}
    if JSON_PATH.exists():
        old = {r["i"]: r for r in json.loads(JSON_PATH.read_text(encoding="utf-8"))["lines"]}
    recs = to_records(jp, "3dx", kr_texts)
    for r in recs:
        r["in_1dx"] = r.pop("in_other")
        o = old.get(r["i"], {})
        r["ko"] = o.get("ko", r["jp"])
        r["basis"] = o.get("basis", "")
    IMG_DIR.mkdir(parents=True, exist_ok=True)
    JSON_PATH.write_text(json.dumps({
        "source": SR_REL, "font": FONT_REL,
        "fields": "i=line, section=credit block, kind=role/name/blank, jp=original text, ko=Korean-patch "
                  "text (the only editable field), color=u32 as stored, size=f32 line size (px; timing)",
        "lines": recs}, ensure_ascii=False, indent=1), encoding="utf-8")
    krr = to_records(kr, "1dx", jp_texts)
    for r in krr:
        r["in_3dx"] = r.pop("in_other")
    (IMG_DIR / "staffroll_1dx_kr.json").write_text(json.dumps({
        "source": "ml 1dx/3romfs/Staffroll/KR/Staffroll.bin", "lines": krr}, ensure_ascii=False, indent=1),
        encoding="utf-8")
    # names / roles vs 1DX
    kr_by_last: dict[str, list[str]] = {}
    for t in kr_texts:
        if t:
            kr_by_last.setdefault(t.split()[-1].lower(), []).append(t)
    rows = ["i\tkind\t3dx\tstatus\t1dx_similar"]
    for r in recs:
        if r["kind"] == "blank":
            continue
        if r["in_1dx"]:
            st, sim = "same", ""
        else:
            cand = [t for t in kr_by_last.get(r["jp"].split()[-1].lower(), []) if t != r["jp"]]
            st, sim = ("similar", " | ".join(sorted(cand))) if cand else ("3dx_only", "")
        rows.append(f"{r['i']}\t{r['kind']}\t{r['jp']}\t{st}\t{sim}")
    (IMG_DIR / "name_check.tsv").write_text("\n".join(rows) + "\n", encoding="utf-8")
    print(f"exported {len(recs)} 3DX lines, {len(krr)} 1DX lines -> {IMG_DIR}")
    return 0


def load_ko(jp: list[SR.Line]) -> tuple[list[SR.Line], list[str]]:
    doc = json.loads(JSON_PATH.read_text(encoding="utf-8"))
    recs = doc["lines"]
    errs = []
    if len(recs) != len(jp):
        errs.append(f"staffroll.json has {len(recs)} lines, original {len(jp)}")
    out = []
    for r, ln in zip(recs, jp):
        if r["jp"] != ln.text or int(r["color"], 16) != ln.color or int(r["size_bits"], 16) != ln.size_bits:
            errs.append(f"line {r['i']}: jp/color/size differ from the original (only `ko` may change)")
        if bool(r["ko"]) != bool(ln.text):
            errs.append(f"line {r['i']}: blank/non-blank changed (would move the timing)")
        out.append(SR.Line(r["ko"], ln.color, ln.size_bits, ln.tail))
    return out, errs


# --------------------------------------------------------------------- font
def add_glyphs(base: L.Bffnt, donor: L.Bffnt, chars: list[str]) -> tuple[L.Bffnt, dict[str, int]]:
    f = L.parse(L.build(base))                  # deep copy
    bimg, dimg = L.SheetImages(f), L.SheetImages(donor)
    dmap, dw = donor.char_map(), donor.widths()
    scan = [cm for cm in f.cmaps if cm.method == 2 and cm.begin == 0 and cm.end == 0xFFFF]
    if len(scan) != 1:
        raise ValueError("expected one catch-all scan CMAP block")
    start, ws = f.cwdh[-1]
    if start + len(ws) != f.glyph_count():
        raise ValueError("last CWDH block does not end the glyph list")
    added = {}
    if f.cell_h != donor.cell_h or f.baseline != donor.baseline or donor.cell_w > f.cell_w:
        raise ValueError("donor cell does not fit the base cell with the same baseline")
    for ch in chars:
        cp = ord(ch)
        if cp not in dmap:
            raise ValueError(f"{ch!r} (U+{cp:04X}) is in neither the 3DX nor the 1DX KR staffroll font")
        g = f.glyph_count()
        if g >= f.glyphs_per_sheet * len(f.sheets) and g // f.glyphs_per_sheet >= 255:
            raise ValueError("font full")
        pix = np.zeros((f.cell_h, f.cell_w), np.uint8)
        src = dimg.cell(dmap[cp])
        pix[:, :src.shape[1]] = src                 # same rows (same baseline), left aligned
        bimg.put(g, pix)
        cw = dw[dmap[cp]]
        ws.append(L.CharWidth(cw.left, cw.glyph, cw.char))
        scan[0].scan.append((cp, g))
        added[ch] = g
    scan[0].scan.sort()
    bimg.commit()
    return f, added


def verify_font(orig: L.Bffnt, new_data: bytes, donor: L.Bffnt, added: dict[str, int],
                needed: set[str]) -> list[str]:
    errs = []
    new = L.parse(new_data)
    if L.build(new) != new_data:
        errs.append("font: rebuilt bytes do not re-parse losslessly")
    om, nm = orig.char_map(), new.char_map()
    ow, nw = orig.widths(), new.widths()
    oi, ni, di = L.SheetImages(orig), L.SheetImages(new), L.SheetImages(donor)
    for cp, g in om.items():
        if nm.get(cp) != g or nw[g] != ow[g] or not np.array_equal(oi.cell(g), ni.cell(g)):
            errs.append(f"font: original U+{cp:04X} changed")
    if new.krng != orig.krng:
        errs.append("font: KRNG changed")
    for attr in ("font_type", "height", "width", "ascent", "line_feed", "alter_char", "cell_w", "cell_h",
                 "baseline", "sheet_fmt", "cols", "rows", "sheet_w", "sheet_h"):
        if getattr(new, attr) != getattr(orig, attr):
            errs.append(f"font: {attr} changed")
    if len(new.sheets) != len(orig.sheets):
        errs.append(f"font: sheet count {len(orig.sheets)} -> {len(new.sheets)}")
    dm, dw = donor.char_map(), donor.widths()
    for ch, g in added.items():
        src = di.cell(dm[ord(ch)])
        cell = ni.cell(nm.get(ord(ch), -1)) if ord(ch) in nm else None
        if cell is None or not np.array_equal(cell[:, :src.shape[1]], src) or cell[:, src.shape[1]:].any():
            errs.append(f"font: {ch} pixels differ from the 1DX glyph")
        if nw[nm[ord(ch)]] != dw[dm[ord(ch)]]:
            errs.append(f"font: {ch} width differs from the 1DX glyph")
    for ch in needed:
        if ord(ch) not in nm:
            errs.append(f"font: {ch!r} still missing")
    return errs


# --------------------------------------------------------------------- preview
class Renderer:
    def __init__(self, font: L.Bffnt):
        self.f = font
        self.img = L.SheetImages(font)
        self.map = font.char_map()
        self.w = font.widths()
        self.kern = font.kerning()

    def line(self, text: str) -> tuple[np.ndarray, list[str]]:
        f, missing = self.f, []
        glyphs, x, prev = [], 0, None
        for ch in text:
            g = self.map.get(ord(ch))
            if g is None:
                missing.append(ch)
                g = self.map.get(f.alter_char, 0)
            if prev is not None:
                x += self.kern.get((prev, ord(ch)), 0)
            cw = self.w[g]
            glyphs.append((x + cw.left, g))
            x += cw.char
            prev = ord(ch)
        width = max([x] + [gx + f.cell_w for gx, _ in glyphs]) + 2
        out = np.zeros((f.cell_h, width), np.float32)
        for gx, g in glyphs:
            c = self.img.cell(g).astype(np.float32) / 15
            sl = out[:, gx:gx + f.cell_w]
            np.maximum(sl, c[:, :sl.shape[1]], out=sl)
        return out[:, :max(1, x)], missing

    def scroll(self, lines: list[SR.Line], game: str = "3dx") -> tuple[Image.Image, list[tuple[int, int, int]], list[str]]:
        """Whole scroll on a 400 px wide canvas; returns image, [(line, y, width px)], warnings."""
        f = self.f
        ys, y = [], 0
        for ln in lines:
            ys.append(y)
            y += max(1, round(ln.size))
        canvas = Image.new("RGB", (SCREEN_W, y + SCREEN_H), (24, 26, 40))
        placed, warns = [], []
        for i, ln in enumerate(lines):
            if not ln.text:
                continue
            a, miss = self.line(ln.text)
            if miss:
                warns.append(f"line {i}: missing {''.join(miss)!r}")
            s = ln.size / f.height
            w, h = max(1, round(a.shape[1] * s)), max(1, round(f.cell_h * s))
            am = Image.fromarray((a * 255).astype(np.uint8), "L").resize((w, h), Image.LANCZOS)
            x0 = (SCREEN_W - w) // 2
            if w > SCREEN_W - 16:
                warns.append(f"line {i}: {w}px wide (screen {SCREEN_W})")
            col = Image.new("RGB", (w, h), SR.rgb(ln.color, game))
            canvas.paste(col, (x0, ys[i]), am)
            placed.append((i, ys[i], w))
        return canvas, placed, warns


def write_previews(jp: list[SR.Line], ko: list[SR.Line], old_font: L.Bffnt, new_font: L.Bffnt) -> tuple[list[Path], list[str]]:
    REVIEW_DIR.mkdir(parents=True, exist_ok=True)
    for p in REVIEW_DIR.glob("I5_*.png"):
        p.unlink()
    rj, rk = Renderer(old_font), Renderer(new_font)
    img_j, _, _ = rj.scroll(jp)
    img_k, placed, warns = rk.scroll(ko)
    paths = []
    # every screen of the Korean scroll, 4 columns x 5 screens per sheet (continuous columns)
    col_h, cols, gap = SCREEN_H * 5, 4, 8
    total = img_k.height
    n_cols = -(-total // col_h)
    for sheet in range(-(-n_cols // cols)):
        im = Image.new("RGB", (cols * (SCREEN_W + gap), col_h + 20), (255, 255, 255))
        d = ImageDraw.Draw(im)
        for c in range(cols):
            k = sheet * cols + c
            if k >= n_cols:
                break
            y0 = k * col_h
            im.paste(img_k.crop((0, y0, SCREEN_W, y0 + col_h)), (c * (SCREEN_W + gap), 20))
            for s in range(1, 5):
                d.line([(c * (SCREEN_W + gap), 20 + s * SCREEN_H), (c * (SCREEN_W + gap) + 12, 20 + s * SCREEN_H)],
                       fill=(255, 80, 80))
            d.text((c * (SCREEN_W + gap) + 2, 4), f"y {y0}-{y0 + col_h}", fill=(0, 0, 0))
        p = REVIEW_DIR / f"I5_scroll_{sheet + 1:02d}.png"
        im.save(p)
        paths.append(p)
    # changed lines: JP-original vs Korean, 1x and 3x
    changed = [i for i, (a, b) in enumerate(zip(jp, ko)) if a.text != b.text]
    y_of = {i: y for i, y, _ in placed}
    for n, i in enumerate(changed):
        y0 = max(0, y_of[i] - 60)
        a = img_j.crop((0, y0, SCREEN_W, y0 + SCREEN_H))
        b = img_k.crop((0, y0, SCREEN_W, y0 + SCREEN_H))
        top = Image.new("RGB", (SCREEN_W * 2 + gap, SCREEN_H), (255, 255, 255))
        top.paste(a, (0, 0)); top.paste(b, (SCREEN_W + gap, 0))
        band = (0, y_of[i] - y0 - 6, SCREEN_W, y_of[i] - y0 + round(ko[i].size) + 8)
        za = a.crop(band).resize(((band[2]) * 3, (band[3] - band[1]) * 3), Image.NEAREST)
        zb = b.crop(band).resize(((band[2]) * 3, (band[3] - band[1]) * 3), Image.NEAREST)
        im = Image.new("RGB", (za.width, SCREEN_H + za.height * 2 + gap * 2), (255, 255, 255))
        im.paste(top.resize((za.width, round(SCREEN_H * za.width / top.width))) if top.width > za.width else top, (0, 0))
        im.paste(za, (0, SCREEN_H + gap)); im.paste(zb, (0, SCREEN_H + za.height + gap * 2))
        p = REVIEW_DIR / f"I5_line{i:03d}_jp_vs_ko.png"
        im.save(p)
        paths.append(p)
    # glyph sheet of the copied glyphs (1DX donor vs installed), 4x
    return paths, warns


# --------------------------------------------------------------------- commands
def cmd_identity() -> int:
    jp_data, jp, kr_data, kr = load_orig()
    ok = True
    for name, data, lines in [("3DX JP", jp_data, jp), ("1DX KR", kr_data, kr)]:
        raw = lib3dx.blz_decompress(data)
        same_raw = SR.encode_raw(lines) == raw
        same = SR.write(lines) == data
        print(f"{name} Staffroll.bin: {len(lines)} lines, records {'==' if same_raw else '!='} original, "
              f"BLZ file {'==' if same else '!='} original ({len(data)} bytes)")
        ok &= same_raw and same
    for rel in [lib3dx.romfs_path(FONT_REL), KR_DIR / "mario_font.bffnt", KR_FONT]:
        d = rel.read_bytes()
        f = L.parse(d)
        same = L.build(f) == d
        print(f"{rel.relative_to(ROOT)}: parse->build {'==' if same else '!='} original, KRNG pairs {len(f.kerning())}")
        ok &= same
    print("IDENTITY", "OK" if ok else "FAILED")
    return 0 if ok else 1


def cmd_build(no_preview: bool) -> int:
    jp_data, jp, _, _ = load_orig()
    if not JSON_PATH.exists():
        cmd_export()
    ko, errs = load_ko(jp)
    base_data = lib3dx.romfs_path(FONT_REL).read_bytes()
    base, donor = L.parse(base_data), L.parse(KR_FONT.read_bytes())
    have = base.char_map()
    needed = {ch for ln in ko for ch in ln.text}
    new_chars = sorted(ch for ch in needed if ord(ch) not in have)
    font, added = add_glyphs(base, donor, new_chars)
    font_data = L.build(font)
    sr_data = SR.write(ko)
    # write
    out_sr, out_font = STAGE / SR_REL, STAGE / FONT_REL
    out_sr.parent.mkdir(parents=True, exist_ok=True)
    out_sr.write_bytes(sr_data)
    out_font.write_bytes(font_data)
    # re-read verification
    back = SR.read(out_sr.read_bytes())
    if len(back) != len(jp):
        errs.append("staffroll: line count changed")
    for i, (a, b, o) in enumerate(zip(back, ko, jp)):
        if a.text != b.text or a.color != o.color or a.size_bits != o.size_bits:
            errs.append(f"staffroll line {i}: re-read mismatch")
    if sum(x.size for x in back) != sum(x.size for x in jp):
        errs.append("staffroll: total scroll length changed")
    errs += verify_font(base, out_font.read_bytes(), donor, added, needed)
    changed = [(i, o.text, k.text) for i, (o, k) in enumerate(zip(jp, ko)) if o.text != k.text]
    print(f"Staffroll.bin: {len(back)} lines, {len(changed)} changed, {len(sr_data)} bytes -> {out_sr}")
    for i, a, b in changed:
        print(f"  #{i}: {a!r} -> {b!r}")
    print(f"mario_font.bffnt: +{len(added)} glyphs from 1DX KR ({''.join(added)}), "
          f"{L.parse(font_data).glyph_count()} glyphs, {len(font.sheets)} sheet(s), {len(font_data)} bytes -> {out_font}")
    if not no_preview:
        paths, warns = write_previews(jp, back, base, L.parse(font_data))
        for w in warns:
            print("  preview warning:", w)
        errs += [w for w in warns if "missing" in w]
        print(f"previews: {len(paths)} -> {REVIEW_DIR}")
        for p in paths:
            print("  ", p)
    for e in errs:
        print("ERROR:", e)
    print("BUILD", "OK" if not errs else f"FAILED ({len(errs)} errors)")
    return 0 if not errs else 1


def main(argv: list[str] | None = None) -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--export", action="store_true")
    ap.add_argument("--identity", action="store_true")
    ap.add_argument("--no-preview", action="store_true")
    a = ap.parse_args(argv)
    if a.export:
        return cmd_export()
    if a.identity:
        return cmd_identity()
    return cmd_build(a.no_preview)


if __name__ == "__main__":
    sys.exit(main())
