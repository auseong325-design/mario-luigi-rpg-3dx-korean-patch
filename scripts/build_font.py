"""Build the Korean versions of the three 3DX message fonts (LayeredFS output).

  .venv\\Scripts\\python scripts\\build_font.py              add every character work/ko_final.json uses
                                                           that the font lacks (recomputed on every run)
  .venv\\Scripts\\python scripts\\build_font.py --all-hangul  also add all 2,350 KS X 1001 Hangul syllables
  .venv\\Scripts\\python scripts\\build_font.py --same-size   keep the original sheet count: new glyphs take
                                                           the free cells and the cells of kana/kanji the
                                                           Korean text never uses (fallback, see below)
  .venv\\Scripts\\python scripts\\build_font.py --no-donor    old build: every new glyph rendered from fonts/
  .venv\\Scripts\\python scripts\\build_font.py --compose-test  leave-one-out check of the syllable composer
  .venv\\Scripts\\python scripts\\build_font.py --compare     only render face/size comparison sheets
  .venv\\Scripts\\python scripts\\build_font.py --selftest    codec checks on the original fonts
Options: --only font,font_l,font_btl   --out <romfs root>   --no-preview

Outputs  patch/00040000001CA900/romfs/Msg/JP_ja/{font,font_l,font_btl}.bffnt
         work/font_preview/*.png (sheets, diff vs original, sample lines next to the 1DX original,
         composed syllables)
         work/build/font_report.json (numbers of the last default run; other modes write
         font_report_same-size.json / font_report_all-hangul.json / font_report_no-donor.json)

Where a new glyph comes from (first that applies):
  1. the Korean 1DX font of the same role (ml 1dx/3romfs/Msg/KR_ko/font, font_l, font_btl.bffnt,
     Mario & Luigi RPG1 DX KR), so the Korean text looks like the Korean 1DX: pixels copied
     unchanged, only moved vertically by one whole-pixel offset per font (Hangul centred on the
     3DX kanji box, punctuation on the 3DX Latin baseline), Hangul keep the 1DX CWDH. Punctuation
     keeps the advance scripts/merge_ko.py assumes (its ink fits), so no line gets wider.
  2. font / font_btl: Hangul the 1DX font lacks (it only has what 1DX needs: 1,103 syllables)
     composed from 1DX syllables by scripts/hangul_compose.py (e.g. 펀 = 펄 + 번 - 벌).
  3. font_l (1DX font_l has only 287 syllables, too few for clean compositions): the 1DX
     dialogue-font glyph (real or composed) scaled by 1.5 and tone-matched to the real 1DX
     font_l glyphs; font_l's own compositions only if that fails.
  4. anything else: rendered from fonts/<face> (Noto Sans KR / NanumSquareRound).
  The 3DX's own glyphs, CWDH entries and CMAP mappings are kept as they are; new glyphs get the
  next glyph indices (first the empty cells of the last sheet, then new sheets of the same size
  and format, A4 = 4-bit alpha), so no original cell changes. Code points inside a CMAP table
  block's range (e.g. '!' in U+0020-007A) are written into that table (nn::font stops at the
  first block whose range holds the code); all others are merged into the sorted scan block.
  Rendered glyphs (4.) are drawn so their ink box is centred on the Japanese kanji ink box
  (Hangul, full-width symbols) or sit on the Latin baseline (ASCII-like symbols).
  --same-size frees the cells of glyphs whose every code point is a kana/kanji not used by the
  Korean text, clears them and reuses them (priority: characters inside font-switch tag spans,
  then by frequency). Characters that still do not fit are listed in the report.
A watchdog aborts the run after 600 s.
"""

from __future__ import annotations

import argparse
import faulthandler
import json
import re
import sys
import time
from collections import Counter
from dataclasses import dataclass, field
from pathlib import Path

import numpy as np
from fontTools.ttLib import TTFont
from PIL import Image, ImageDraw, ImageFont

import libbffnt as L
from hangul_compose import Composer, leave_one_out, tone_lut
from lib3dx import ROOT, TITLE_ID, bffnt_advances, romfs_path

faulthandler.dump_traceback_later(600, exit=True)

KO_FINAL = ROOT / "work" / "ko_final.json"
FONT_DIR = ROOT / "fonts"
DONOR_ROOT = ROOT / "ml 1dx" / "3romfs"   # Korean 1DX dump (read-only source, like romfs/)
PREVIEW = ROOT / "work" / "font_preview"
REPORT = ROOT / "work" / "build" / "font_report.json"
PATCH_ROMFS = ROOT / "patch" / TITLE_ID / "romfs"
TEXT_RGB = (0x37, 0x37, 0x37)          # default text colour of the game's boxes ([Color #373737])
# not used by the text yet, but the fonts should have them (※ was dropped from 4 lines for lack of it)
EXTRA_WANTED = "※"


@dataclass
class Spec:
    name: str
    rel: str
    face: str          # file in fonts/ (rendered fallback)
    px: int            # FreeType pixel size
    method: str        # 'hinted' (FreeType at px) or 'ss4' (4x supersampled, box filtered)
    full_adv: int      # advance of a Hangul syllable
    gamma: float = 1.0  # <1 darkens anti-aliased edges
    donor: str = ""     # the Korean 1DX font of the same role (path under DONOR_ROOT)
    hangul_face: tuple[str, int] | None = None  # rendered fallback for Hangul nothing else covers
    upscale_from: str = ""  # font_l: 1DX font whose glyphs are scaled up for what font_l lacks


# Rendered fallback (4.): chosen for the old all-rendered build after comparing four OFL faces
# (work/font_preview/compare_*.png): FreeType-hinted NanumSquareRound ExtraBold at 16/23 px and
# Bold 12 px (gamma 0.6) in the battle font. For Hangul that the 1DX glyphs cannot provide, the
# face closest to the 1DX glyphs was measured instead (IoU of ink masks against 150 real 1DX
# syllables after the best shift): font Noto Sans KR Bold 15 px 0.69, font_btl NanumSquareRound
# ExtraBold 12 px 0.65; font_l's best is the 1DX font scaled x1.5 (0.82, faces <= 0.71).
SPECS: dict[str, Spec] = {
    "font": Spec("font", "Msg/JP_ja/font.bffnt", "NanumSquareRoundEB.ttf", 16, "hinted", 16,
                 donor="Msg/KR_ko/font.bffnt", hangul_face=("NotoSansKR-Bold.otf", 15)),
    "font_l": Spec("font_l", "Msg/JP_ja/font_l.bffnt", "NanumSquareRoundEB.ttf", 23, "hinted", 24,
                   donor="Msg/KR_ko/font_l.bffnt", upscale_from="Msg/KR_ko/font.bffnt"),
    "font_btl": Spec("font_btl", "Msg/JP_ja/font_btl.bffnt", "NanumSquareRoundB.ttf", 12, "hinted", 12, 0.6,
                     donor="Msg/KR_ko/font_btl.bffnt", hangul_face=("NanumSquareRoundEB.ttf", 12)),
}
FACES = ["NanumSquareRoundB.ttf", "NanumSquareRoundEB.ttf", "NotoSansKR-Medium.otf", "NotoSansKR-Bold.otf"]

# preview texts (message ids of work/ko_final.json)
SAMPLES = {
    "font": ["FMsg/o_peach_1f_01#10", "FMsg/o_peach_1f_01#11", "FMsg/i_air_07#1",
             "FMsg/i_areanone_puzzle_01_L#12"],
    "font_btl": ["BMsg/b_sys#39", "BMsg/b_sys#5", "BMsg/b_sys#23"],
    "font_l": ["BMsg/b_sys#1771", "BMsg/b_sys#1748", "FMsg/i_air_14#0"],
}
ITEM_SAMPLES = ["Item#3", "Item#4", "Item#9", "Item#10", "Item#22", "Item#29", "Item#39", "Item#25", "Item#8"]

TAG = re.compile(r"\[([^\[\]]*)\]")
FONT_SPAN = re.compile(r"\[0000:0001:(?!FF FF)[0-9A-F ]*\](.*?)(?:\[0000:0001:FF FF\]|$)", re.S)


# --------------------------------------------------------------------- text
def visible(text: str) -> str:
    """Characters the game draws for a message (tags removed, Ruby base kept, icons dropped)."""
    out, pos = [], 0
    for m in TAG.finditer(text):
        out.append(text[pos:m.start()])
        body = m.group(1)
        if body.startswith("Ruby "):
            out.append(body[5:].split(";", 1)[0])
        elif body.startswith("U+"):
            cp = int(body[2:], 16)
            if not (0xE000 <= cp <= 0xF8FF or cp < 0x20):
                out.append(chr(cp))
        elif body == "Next":
            out.append("\f")
        pos = m.end()
    out.append(text[pos:])
    return "".join(out)


def load_ko() -> dict[str, str]:
    return json.loads(KO_FINAL.read_text(encoding="utf-8"))


def used_chars(ko: dict[str, str]) -> Counter:
    c: Counter = Counter()
    for t in ko.values():
        c.update(ch for ch in visible(t) if ch not in "\n\f")
    return c


def font_span_chars(ko: dict[str, str]) -> set[str]:
    s: set[str] = set()
    for t in ko.values():
        for m in FONT_SPAN.finditer(t):
            s.update(ch for ch in visible(m.group(1)) if ch not in "\n\f")
    return s


def ksx1001_hangul() -> list[str]:
    return [chr(c) for c in range(0xAC00, 0xD7A4) if len(chr(c).encode("euc-kr", errors="ignore")) == 2]


def is_hangul(ch: str) -> bool:
    return 0xAC00 <= ord(ch) <= 0xD7A3 or 0x3131 <= ord(ch) <= 0x318E


def is_cjk_class(ch: str) -> bool:
    """Drawn in the kanji box (full-width design) rather than on the Latin baseline."""
    return is_hangul(ch) or ord(ch) >= 0x2000


def is_kana_kanji(cp: int) -> bool:
    return (0x3041 <= cp <= 0x3096 or 0x309B <= cp <= 0x309F or 0x30A1 <= cp <= 0x30FA
            or 0x30FC <= cp <= 0x30FF or 0x3400 <= cp <= 0x4DBF or 0x4E00 <= cp <= 0x9FFF
            or cp in (0x3005, 0x3006))


# --------------------------------------------------------------------- metrics of a game font
@dataclass
class Metrics:
    kanji_center: float     # vertical centre of the kanji ink box (cell rows)
    kanji_h: float
    latin_baseline: int     # first row below the ink of capitals/digits
    full_adv: int


def font_metrics(f: L.Bffnt) -> Metrics:
    si = L.SheetImages(f)
    cmap, widths = f.char_map(), f.widths()
    cents, heights, bottoms = [], [], []
    for cp, g in cmap.items():
        ys = np.nonzero(si.cell(g).any(axis=1))[0]
        if not len(ys):
            continue
        if 0x4E00 <= cp <= 0x9FFF:
            cents.append((ys[0] + ys[-1]) / 2)
            heights.append(ys[-1] - ys[0] + 1)
        elif chr(cp) in "ABDEHIKLMNRTUVWXZ0123456789":
            bottoms.append(ys[-1])
    advs = Counter(widths[g].char for cp, g in cmap.items() if 0x4E00 <= cp <= 0x9FFF or 0x3041 <= cp <= 0x30FA)
    return Metrics(float(np.median(cents)), float(np.median(heights)),
                   int(Counter(bottoms).most_common(1)[0][0]) + 1, advs.most_common(1)[0][0])


# --------------------------------------------------------------------- rasterizer
class Rasterizer:
    def __init__(self, face: str, px: int, method: str, cell_w: int, cell_h: int, gamma: float = 1.0):
        self.path = FONT_DIR / face
        self.px, self.method, self.gamma = px, method, gamma
        self.ss = 4 if method == "ss4" else 1
        if method not in ("hinted", "ss4"):
            raise ValueError(f"unknown method {method}")
        self.pil = ImageFont.truetype(str(self.path), px * self.ss)
        tt = TTFont(str(self.path), lazy=True)
        self.upem = tt["head"].unitsPerEm
        self.cmap = tt.getBestCmap()
        self.hmtx = tt["hmtx"]
        self.cell_w, self.cell_h = cell_w, cell_h

    def has(self, ch: str) -> bool:
        return ord(ch) in self.cmap

    def face_adv(self, ch: str) -> float:
        return self.hmtx[self.cmap[ord(ch)]][0] / self.upem * self.px

    def _canvas(self, ch: str, baseline: int, pen_x: float) -> np.ndarray:
        """Render ch with its origin at (pen_x, baseline) on a canvas 3 cells wide/high whose
        middle cell is the target cell; returns 0..1 coverage at 1x resolution."""
        s = self.ss
        w, h = self.cell_w * 3, self.cell_h * 3
        img = Image.new("L", (w * s, h * s), 0)
        ImageDraw.Draw(img).text(((self.cell_w + pen_x) * s, (self.cell_h + baseline) * s), ch,
                                 font=self.pil, fill=255, anchor="ls")
        a = np.asarray(img, dtype=np.float64) / 255.0
        if s > 1:
            a = a.reshape(h, s, w, s).mean(axis=(1, 3))
        return a

    def ink_rows(self, ch: str, baseline: int) -> tuple[int, int] | None:
        a = self._canvas(ch, baseline, 0)
        ys = np.nonzero((a > 0.25).any(axis=1))[0]
        if not len(ys):
            return None
        return int(ys[0]) - self.cell_h, int(ys[-1]) - self.cell_h

    def render(self, ch: str, baseline: int, adv: int) -> tuple[np.ndarray, L.CharWidth, list[str]]:
        """-> (cell bitmap 0..15 with the ink left-aligned, CWDH entry, problems)."""
        off = (adv - self.face_adv(ch)) / 2
        if self.ss == 1:
            off = round(off)
        else:
            off = round(off * self.ss) / self.ss
        a = self._canvas(ch, baseline, off)
        if self.gamma != 1.0:
            a = a ** self.gamma
        q = np.clip(np.rint(a * 15), 0, 15).astype(np.uint8)
        ch_, cw = self.cell_h, self.cell_w
        problems = []
        ink_y = np.nonzero(q.any(axis=1))[0]
        if len(ink_y) and (ink_y[0] < ch_ or ink_y[-1] >= 2 * ch_):
            # nudge the whole glyph vertically (whole pixels, exact) so it fits into the cell
            top, bot = int(ink_y[0]), int(ink_y[-1])
            if bot - top + 1 > ch_:
                problems.append(f"{ch!r} taller than the cell ({bot - top + 1} > {ch_}), clipped")
            else:
                shift = (2 * ch_ - 1 - bot) if bot >= 2 * ch_ else (ch_ - top)
                q = np.roll(q, shift, axis=0)
                problems.append(f"{ch!r} nudged {shift:+d} px vertically to fit the cell")
        rows = q[ch_:2 * ch_]
        cols = np.nonzero(rows.any(axis=0))[0]
        pix = np.zeros((ch_, cw), dtype=np.uint8)
        if not len(cols):
            return pix, L.CharWidth(0, 0, adv), problems
        x0, x1 = int(cols[0]), int(cols[-1])
        gw = x1 - x0 + 1
        if gw > cw:
            problems.append(f"{ch!r} wider than the cell ({gw} > {cw})")
            gw = cw
        pix[:, :gw] = rows[:, x0:x0 + gw]
        return pix, L.CharWidth(x0 - cw, gw, adv), problems


# --------------------------------------------------------------------- advance model
_KO_WIDTH = None


def checker_width(ch: str) -> int:
    """Width scripts/merge_ko.py assumes for ch in font.bffnt (its line-width checks)."""
    global _KO_WIDTH
    if _KO_WIDTH is None:
        from merge_ko import width as w  # read-only use of the checker's width model
        _KO_WIDTH = w
    return _KO_WIDTH(ch)


def advance_for(ch: str, spec: Spec, base_font_adv: dict[str, int]) -> int:
    if is_hangul(ch):
        return spec.full_adv
    base = base_font_adv.get(ch) or checker_width(ch)
    if spec.name == "font":
        return checker_width(ch)
    return max(1, int(base * spec.full_adv / 16 + 0.5))


# --------------------------------------------------------------------- building
def place_cell(pix: np.ndarray, shift: int, h: int, w: int) -> tuple[np.ndarray, int]:
    """Glyph image (ink from column 0) -> an h x w cell with the image moved down `shift` rows;
    also returns how many ink rows (or a column overflow) fell outside the cell."""
    out = np.zeros((h, w), dtype=np.uint8)
    cw = min(pix.shape[1], w)
    lost = 0
    for r in range(pix.shape[0]):
        rr = r + shift
        if 0 <= rr < h:
            out[rr, :cw] = pix[r, :cw]
        elif pix[r].any():
            lost += 1
    if pix[:, cw:].any():
        lost += 1
    return out, lost


def fit_width(cw: L.CharWidth, adv: int) -> L.CharWidth:
    """A donor glyph's CWDH for another advance: ink unchanged, the side bearings scaled so the
    ink keeps its relative place (1DX '!' 2+4+2 -> 1+4+1 at advance 6)."""
    spare_d, spare_t = cw.char - cw.glyph, adv - cw.glyph
    left = int(round(cw.left * spare_t / spare_d)) if spare_d > 0 else 0
    return L.CharWidth(max(0, min(left, spare_t)), cw.glyph, adv)


class Donor:
    """A Korean 1DX font (read-only) whose glyphs go into the 3DX font of the same role.

    cjk_shift    rows added to a 1DX Hangul/full-width glyph so its ink box is centred on the 3DX
                 kanji box (clamped so no 1DX syllable loses a row)
    latin_shift  rows added to a 1DX ASCII-like glyph: 1DX Latin baseline -> 3DX Latin baseline
    """

    def __init__(self, rel: str, target: L.Bffnt, met: "Metrics"):
        self.rel = rel
        self.font = L.parse((DONOR_ROOT / rel).read_bytes())
        self.si = L.SheetImages(self.font)
        self.cmap, self.widths = self.font.char_map(), self.font.widths()
        self.th, self.tw = target.cell_h, target.cell_w
        rows = [r for r in (self.ink_rows(g) for cp, g in self.cmap.items() if 0xAC00 <= cp <= 0xD7A3) if r]
        self.hangul_center = float(np.median([(a + b) / 2 for a, b in rows]))
        ideal = met.kanji_center - self.hangul_center
        lo, hi = -min(a for a, _ in rows), self.th - 1 - max(b for _, b in rows)
        self.cjk_shift = int(min(max(round(ideal), lo), hi)) if lo <= hi else int(round(ideal))
        caps = [self.ink_rows(self.cmap[ord(c)]) for c in "ABDEHIKLMNRTUVWXZ0123456789" if ord(c) in self.cmap]
        self.latin_baseline = Counter(r[1] for r in caps if r).most_common(1)[0][0] + 1
        self.latin_shift = met.latin_baseline - self.latin_baseline
        self._composer: Composer | None = None

    def ink_rows(self, g: int) -> tuple[int, int] | None:
        ys = np.nonzero(self.si.cell(g).any(axis=1))[0]
        return (int(ys[0]), int(ys[-1])) if len(ys) else None

    def has(self, ch: str) -> bool:
        return ord(ch) in self.cmap

    def raw(self, ch: str) -> tuple[np.ndarray, L.CharWidth]:
        g = self.cmap[ord(ch)]
        return self.si.cell(g).copy(), self.widths[g]

    def place(self, pix: np.ndarray, shift: int) -> tuple[np.ndarray, int]:
        """A glyph image (ink from column 0) -> a target cell, moved down by `shift` rows.
        Returns (cell, number of ink rows that fell outside the cell)."""
        return place_cell(pix, shift, self.th, self.tw)

    @property
    def composer(self) -> Composer:
        if self._composer is None:
            self._composer = Composer(self.font)
        return self._composer

    def syllable(self, ch: str, relaxed: bool = True) -> tuple[np.ndarray, L.CharWidth, str] | None:
        """1DX glyph of ch in 1DX geometry, real or composed: (pix, cwdh, 'real'|'composed'|'relaxed')."""
        if self.has(ch):
            pix, cw = self.raw(ch)
            return pix, cw, "real"
        if not (0xAC00 <= ord(ch) <= 0xD7A3):
            return None
        c = self.composer.compose(ch, relaxed=relaxed)
        if c is None:
            return None
        return c.pix, c.width, "relaxed" if c.relaxed else "composed"


def upscale(pix: np.ndarray, cw: L.CharWidth, scale: float) -> tuple[np.ndarray, int]:
    """A glyph image (ink from column 0, cw.glyph columns) scaled by `scale` with Lanczos; returns
    (image 0..15 with the ink from column 0, scaled left bearing)."""
    src = Image.fromarray((pix[:, :max(1, cw.glyph)].astype(np.uint16) * 17).astype(np.uint8))
    w = int(round(cw.glyph * scale))
    h = int(round(pix.shape[0] * scale))
    img = np.asarray(src.resize((max(1, w), max(1, h)), Image.LANCZOS), dtype=np.float64) / 255.0
    img = np.rint(np.clip(img, 0, 1) * 15)
    img[img <= 1] = 0
    cols = np.nonzero(img.any(axis=0))[0]
    left = int(round(cw.left * scale))
    if not len(cols):
        return np.zeros((h, 1), dtype=np.uint8), left
    img = img[:, cols[0]:cols[-1] + 1]
    return img.astype(np.uint8), left + int(cols[0])


@dataclass
class Result:
    name: str
    data: bytes
    added: list[str]
    dropped: list[str]
    reclaimed: int
    sheets_before: int
    sheets_after: int
    size_before: int
    size_after: int
    new_glyphs: dict[str, tuple[int, np.ndarray, L.CharWidth]] = field(default_factory=dict)
    problems: list[str] = field(default_factory=list)
    baseline_cjk: int = 0
    baseline_latin: int = 0
    sources: dict[str, str] = field(default_factory=dict)      # char -> where its glyph came from
    donor_shift: tuple[int, int] | None = None                 # (cjk_shift, latin_shift)
    copy_shift: dict[str, int] = field(default_factory=dict)   # char copied from 1DX -> rows moved


def set_mapping(f: L.Bffnt, cp: int, glyph: int) -> None:
    for cm in f.cmaps:
        if cm.begin <= cp <= cm.end:
            if cm.method == 1:
                cm.table[cp - cm.begin] = glyph
            elif cm.method == 2:
                cm.scan = sorted([e for e in cm.scan if e[0] != cp] + [(cp, glyph)])
            else:
                raise ValueError(f"U+{cp:04X} falls in a direct CMAP block; cannot remap")
            return
    f.cmaps.append(L.CMap(cp, cp, 2, 0, scan=[(cp, glyph)]))


def unmap_glyph(f: L.Bffnt, glyph: int) -> list[int]:
    removed = []
    for cm in f.cmaps:
        if cm.method == 1:
            for i, g in enumerate(cm.table):
                if g == glyph:
                    cm.table[i] = L.GLYPH_NONE
                    removed.append(cm.begin + i)
        elif cm.method == 2:
            removed += [c for c, g in cm.scan if g == glyph]
            cm.scan = [e for e in cm.scan if e[1] != glyph]
        elif cm.base <= glyph <= cm.base + cm.end - cm.begin:
            raise ValueError("cannot unmap a glyph of a direct CMAP block")
    return removed


def extend_widths(f: L.Bffnt, count: int) -> None:
    start, ws = f.cwdh[-1]
    while start + len(ws) < count:
        ws.append(L.CharWidth(0, 0, 0))


def build_font(spec: Spec, chars: list[str], used: Counter, priority: set[str], same_size: bool,
               base_font_adv: dict[str, int], use_donor: bool = True) -> Result:
    orig = romfs_path(spec.rel).read_bytes()
    f = L.parse(orig)
    met = font_metrics(f)
    res = Result(spec.name, b"", [], [], 0, len(f.sheets), 0, len(orig), 0)
    mapped = f.char_map()
    need = [c for c in chars if ord(c) not in mapped]
    donor = Donor(spec.donor, f, met) if use_donor and spec.donor else None
    up = Donor(spec.upscale_from, f, met) if use_donor and spec.upscale_from else None
    if donor:
        res.donor_shift = (donor.cjk_shift, donor.latin_shift)

    # rendered fallback: one rasterizer per face, Hangul centred on the kanji box
    rasters: dict[tuple[str, int], tuple[Rasterizer, int]] = {}

    def raster(face: str, px: int) -> tuple[Rasterizer, int]:
        if (face, px) not in rasters:
            gamma = spec.gamma if (face, px) == (spec.face, spec.px) else 1.0
            r = Rasterizer(face, px, spec.method, f.cell_w, f.cell_h, gamma)
            probe = [c for c in need if is_hangul(c) and r.has(c)][:400] or ["가", "한", "글"]
            rows = [r.ink_rows(c, 0) for c in probe]
            cents = [(x[0] + x[1]) / 2 for x in rows if x]
            rasters[(face, px)] = (r, int(round(met.kanji_center - float(np.median(cents)))))
        return rasters[(face, px)]

    ras, res.baseline_cjk = raster(spec.face, spec.px)
    res.baseline_latin = met.latin_baseline

    # font_l: glyphs made by scaling or averaging are softer than the real 1DX ones; learn tone
    # tables (histogram matching) on syllables 1DX font_l HAS: x1.5 of the 1DX font glyph vs the
    # real font_l glyph, and a leave-one-out composition vs the real glyph
    lut_up = lut_comp = None
    if up and donor:
        scale = spec.full_adv / 16
        real_l = {ch: donor.raw(ch)[0] for ch in donor.composer.glyphs}
        pairs_u = [(upscale(*up.raw(ch), scale)[0], real) for ch, real in real_l.items() if up.has(ch)]
        pairs_c = []
        for ch in sorted(real_l)[::max(1, len(real_l) // 150)]:
            c = donor.composer.compose(ch, exclude={ch}, relaxed=False)
            if c is not None:
                pairs_c.append((c.pix, real_l[ch]))
        lut_up = tone_lut(pairs_u) if pairs_u else None
        lut_comp = tone_lut(pairs_c) if pairs_c else None
        res.problems.append(f"{spec.name}: tone tables 0..15 -> upscaled {lut_up.tolist() if lut_up is not None else None}"
                            f" ({len(pairs_u)} pairs), composed {lut_comp.tolist() if lut_comp is not None else None}"
                            f" ({len(pairs_c)} pairs)")

    def ascii_width(cw: L.CharWidth, ch: str) -> tuple[L.CharWidth, str | None]:
        """Punctuation from 1DX keeps the advance the checker assumes when its ink fits."""
        adv = advance_for(ch, spec, base_font_adv)
        if cw.glyph <= adv:
            return fit_width(cw, adv), None
        return cw, f"{ch!r} keeps its 1DX advance {cw.char} (ink {cw.glyph} > model {adv})"

    def fitted(target: "Donor", img: np.ndarray, shift: int, what: str, ch: str = "") -> np.ndarray:
        """place() with the shift pulled back just enough that no ink row leaves the cell."""
        pix, lost = target.place(img, shift)
        if lost:
            ys = np.nonzero(img.any(axis=1))[0]
            s2 = int(min(max(shift, -ys[0]), target.th - 1 - ys[-1]))
            pix, lost = target.place(img, s2)
            res.problems.append(f"{spec.name}: {what} nudged {s2 - shift:+d} px vertically to fit the cell"
                                + (f", still loses {lost} row(s)" if lost else ""))
            shift = s2
        if ch:
            res.copy_shift[ch] = shift
        return pix

    def make(ch: str) -> tuple[np.ndarray, L.CharWidth, str] | None:
        cjk = is_cjk_class(ch)
        if donor and donor.has(ch):                                   # 1. copied from 1DX
            pix, cw = donor.raw(ch)
            if not is_hangul(ch) and not (cjk and cw.char == spec.full_adv):
                cw, note = ascii_width(cw, ch)
                if note:
                    res.problems.append(f"{spec.name}: {note}")
            pix = fitted(donor, pix, donor.cjk_shift if cjk else donor.latin_shift, f"1DX {ch!r}", ch)
            return pix, cw, "1dx"
        if donor and not up and 0xAC00 <= ord(ch) <= 0xD7A3:         # 2. composed from 1DX syllables
            got = donor.syllable(ch)
            if got:
                pix, cw, how = got
                return fitted(donor, pix, donor.cjk_shift, f"composed {ch!r}"), cw, how
        if up and 0xAC00 <= ord(ch) <= 0xD7A3:                       # 3. font_l: 1DX font x1.5
            got = up.syllable(ch)
            if got:
                pix16, cw16, how = got
                scale = spec.full_adv / 16
                img, left = upscale(pix16, cw16, scale)
                if lut_up is not None:
                    img = lut_up[img]
                ref_dst = donor.hangul_center + donor.cjk_shift if donor else met.kanji_center
                target = donor or up
                pix = fitted(target, img, int(round(ref_dst - up.hangul_center * scale)), f"upscaled {ch!r}")
                return pix, L.CharWidth(left, min(img.shape[1], f.cell_w), spec.full_adv), f"upscaled-{how}"
        if donor and up and 0xAC00 <= ord(ch) <= 0xD7A3:             # 3b. font_l's own composition
            # last resort only: font_l has 287 donor syllables, too few for clean analogies
            # (stray strokes in 끌 들 튼 넙 ...), while the dialogue font has 1,103
            got = donor.syllable(ch, relaxed=False)
            if got:
                pix, cw, how = got
                if lut_comp is not None:
                    pix = lut_comp[pix]
                return fitted(donor, pix, donor.cjk_shift, f"composed {ch!r}"), cw, how
        face, px = (spec.hangul_face if (is_hangul(ch) and spec.hangul_face and use_donor)
                    else (spec.face, spec.px))                        # 4. rendered from fonts/
        r, bl_cjk = raster(face, px)
        if not r.has(ch):
            return None
        pix, cw, probs = r.render(ch, bl_cjk if cjk else met.latin_baseline, advance_for(ch, spec, base_font_adv))
        res.problems += [f"{spec.name}: {p}" for p in probs]
        return pix, cw, f"rendered-{face.rsplit('.', 1)[0]}-{px}"

    made: dict[str, tuple[np.ndarray, L.CharWidth, str]] = {}
    for ch in need:
        m = make(ch)
        if m is None:
            res.problems.append(f"{spec.name}: nothing provides {ch!r}")
        else:
            made[ch] = m
            res.sources[ch] = m[2]
    need = [c for c in need if c in made]

    # glyph slots
    gc = f.glyph_count()
    slots: list[int] = []
    si = L.SheetImages(f)
    if same_size:
        cap = f.glyphs_per_sheet * len(f.sheets)
        slots = list(range(gc, cap))
        owners: dict[int, list[int]] = {}
        for cp, g in mapped.items():
            owners.setdefault(g, []).append(cp)
        protected = {f.alter_char}
        reclaim = sorted(g for g, cps in owners.items()
                         if g not in protected and all(is_kana_kanji(cp) and chr(cp) not in used for cp in cps))
        slots += reclaim
        order = sorted(need, key=lambda c: (c not in priority, -used.get(c, 0), c))
        if len(order) > len(slots):
            res.dropped = order[len(slots):]
            order = order[:len(slots)]
        need = order
        # free cells first, then the reclaimed kana/kanji cells
        slots = slots[:len(need)]
        for g in slots:
            if g < gc:
                unmap_glyph(f, g)
                res.reclaimed += 1
        extend_widths(f, max([gc] + [g + 1 for g in slots]))
    else:
        slots = list(range(gc, gc + len(need)))
        extend_widths(f, gc + len(need))
    widths_block = f.cwdh[-1]
    for ch, g in zip(need, slots):
        pix, cw, _ = made[ch]
        si.put(g, pix)
        start, ws = widths_block
        ws[g - start] = cw
        set_mapping(f, ord(ch), g)
        res.new_glyphs[ch] = (g, pix, cw)
        res.added.append(ch)
    si.commit()
    f.max_char_w = max(f.max_char_w, *(w.char for _, ws in f.cwdh for w in ws))
    res.data = L.build(f)
    res.sheets_after = len(f.sheets)
    res.size_after = len(res.data)
    return res


# --------------------------------------------------------------------- verification
def verify(spec: Spec, res: Result, data: bytes, required: list[str], same_size: bool,
           path: Path | None = None) -> list[str]:
    """Re-parse the written file and check it against the original and the intended glyphs."""
    bad: list[str] = []
    orig = L.parse(romfs_path(spec.rel).read_bytes())
    new = L.parse(data)
    if L.build(new) != data:
        bad.append("build(parse(file)) != file")
    for fld in ("font_type", "height", "width", "ascent", "line_feed", "alter_char", "encoding",
                "cell_w", "cell_h", "sheet_size", "baseline", "sheet_fmt", "cols", "rows", "sheet_w", "sheet_h"):
        if getattr(orig, fld) != getattr(new, fld):
            bad.append(f"field {fld} changed")
    if same_size and len(new.sheets) != len(orig.sheets):
        bad.append("sheet count changed in --same-size mode")
    om, nm = orig.char_map(), new.char_map()
    ow, nw = orig.widths(), new.widths()
    osi, nsi = L.SheetImages(orig), L.SheetImages(new)
    reclaimed_glyphs = {g for ch, (g, _, _) in res.new_glyphs.items() if g < orig.glyph_count()}
    kept = total = 0
    for cp, g in om.items():
        if g in reclaimed_glyphs:
            continue
        total += 1
        if nm.get(cp) != g:
            bad.append(f"U+{cp:04X} mapping changed")
        elif (ow[g].left, ow[g].glyph, ow[g].char) != (nw[g].left, nw[g].glyph, nw[g].char):
            bad.append(f"U+{cp:04X} width changed")
        elif not np.array_equal(osi.cell(g), nsi.cell(g)):
            bad.append(f"U+{cp:04X} glyph pixels changed")
        else:
            kept += 1
    res.problems.append(f"{spec.name}: original glyphs unchanged (mapping, CWDH, pixels) {kept}/{total}"
                        + (f" (+{len(reclaimed_glyphs)} reclaimed for Hangul)" if reclaimed_glyphs else ""))
    # whole-sheet comparison outside the cells that received new glyphs
    touched = {g for g, _, _ in res.new_glyphs.values()}
    mask_changed = 0
    for k, oimg in enumerate(osi.images):
        diff = oimg != nsi.images[k]
        for g in touched:
            s, x, y = new.cell_origin(g)
            if s == k:
                diff[y:y + new.cell_h, x:x + new.cell_w] = False
        mask_changed += int(diff.sum())
    if mask_changed:
        bad.append(f"{mask_changed} pixels changed outside the new glyph cells")
    res.problems.append(f"{spec.name}: pixels changed outside new glyph cells: {mask_changed}")
    missing = []
    for ch in required:
        g = new.lookup(ord(ch))
        if g is None or g >= new.glyph_count():
            missing.append(ch)
            continue
        if ch in res.new_glyphs:
            eg, epix, ecw = res.new_glyphs[ch]
            w = nw[g]
            if g != eg or (w.left, w.glyph, w.char) != (ecw.left, ecw.glyph, ecw.char):
                bad.append(f"{ch!r}: CWDH/glyph index differs from intended")
            if not np.array_equal(nsi.cell(g), epix):
                bad.append(f"{ch!r}: sheet pixels differ from the rendered glyph (swizzle?)")
    dropped = set(res.dropped)
    missing_real = [c for c in missing if c not in dropped]
    if missing_real:
        bad.append(f"{len(missing_real)} required characters not mapped: {''.join(missing_real[:40])!r}")
    # glyphs copied from 1DX: re-derive them from the 1DX file itself and compare with the output
    if res.donor_shift and spec.donor:
        dn = L.parse((DONOR_ROOT / spec.donor).read_bytes())
        dsi, dmap, dw = L.SheetImages(dn), dn.char_map(), dn.widths()
        copied = [ch for ch, s in res.sources.items() if s == "1dx" and ch in res.new_glyphs]
        diff = []
        for ch in copied:
            g, dg = new.lookup(ord(ch)), dmap[ord(ch)]
            exp, _ = place_cell(dsi.cell(dg), res.copy_shift.get(ch, res.donor_shift[0 if is_cjk_class(ch) else 1]),
                                new.cell_h, new.cell_w)
            same_w = (not is_hangul(ch)) or (nw[g].left, nw[g].glyph, nw[g].char) == \
                (dw[dg].left, dw[dg].glyph, dw[dg].char)
            if not np.array_equal(nsi.cell(g), exp) or not same_w or nw[g].glyph != dw[dg].glyph:
                diff.append(ch)
        if diff:
            bad.append(f"{len(diff)} glyphs copied from 1DX differ from the 1DX file: {''.join(diff[:30])!r}")
        res.problems.append(f"{spec.name}: {len(copied) - len(diff)}/{len(copied)} glyphs identical to "
                            f"{spec.donor} (pixels; Hangul also CWDH), shift cjk {res.donor_shift[0]:+d} "
                            f"latin {res.donor_shift[1]:+d}")
    if spec.name == "font":
        # merge_ko's width model must never under-estimate: Hangul advances may be smaller than
        # the model (1DX has some 15 px syllables), everything else must match it exactly
        def off_model(c: str) -> bool:
            a, m = nw[new.lookup(ord(c))].char, checker_width(c)
            return a > m if is_hangul(c) else a != m
        mism = [(c, nw[new.lookup(ord(c))].char, checker_width(c)) for c in required
                if new.lookup(ord(c)) is not None and off_model(c)]
        if mism:
            bad.append(f"advance differs from merge_ko width model: {mism[:10]}")
        res.problems.append(f"font: advances within the merge_ko width model for "
                            f"{len(required) - len(mism) - len(missing)}/{len(required)} required characters")
    # independent reader: lib3dx.bffnt_advances follows the FINF pointers on its own
    # (romfs_path() of an absolute path is that path)
    if path is not None:
        indep = bffnt_advances(str(Path(path).resolve()))
        exp = {ch: nw[new.lookup(ord(ch))].char for ch in required if new.lookup(ord(ch)) is not None}
        diff = [ch for ch, a in exp.items() if indep.get(ch) != a]
        if diff:
            bad.append(f"lib3dx.bffnt_advances disagrees for {len(diff)} characters: {''.join(diff[:30])!r}")
        res.problems.append(f"{spec.name}: lib3dx.bffnt_advances reads {len(indep)} mapped characters, "
                            f"{len(exp) - len(diff)}/{len(required)} required characters with the intended advance")
    return bad


# --------------------------------------------------------------------- previews
def sheet_png(img: np.ndarray) -> Image.Image:
    return Image.fromarray((255 - img.astype(np.uint16) * 17).astype(np.uint8))


def render_text(f: L.Bffnt, sheets: list[np.ndarray], text: str, missing: set[str] | None = None) -> np.ndarray:
    """Lay out text with the font's own CMAP/CWDH/sheets (what the game would draw), 0..1 alpha."""
    cmap, widths = f.char_map(), f.widths()
    lines = text.split("\n")
    lf = f.line_feed

    def glyph(ch: str) -> int:
        g = cmap.get(ord(ch))
        if g is None:
            if missing is not None:
                missing.add(ch)
            g = f.alter_char
        return g

    width = max([sum(widths[glyph(c)].char for c in ln) for ln in lines] + [1]) + f.cell_w
    canvas = np.zeros((lf * (len(lines) - 1) + f.cell_h + 2, width + 2), dtype=np.float64)
    for li, ln in enumerate(lines):
        pen = 1
        for c in ln:
            g = glyph(c)
            w = widths[g]
            s, x, y = f.cell_origin(g)
            cell = sheets[s][y:y + f.cell_h, x:x + w.glyph] / 15.0
            x0, y0 = pen + w.left, 1 + li * lf
            if x0 >= 0 and cell.size:
                reg = canvas[y0:y0 + f.cell_h, x0:x0 + cell.shape[1]]
                np.maximum(reg, cell[:, :reg.shape[1]], out=reg)
            pen += w.char
    return canvas


def to_rgb(alpha: np.ndarray, scale: int = 2, fg=TEXT_RGB, bg=(255, 255, 255)) -> Image.Image:
    a = alpha[..., None]
    rgb = (np.array(bg) * (1 - a) + np.array(fg) * a).astype(np.uint8)
    im = Image.fromarray(rgb)
    return im.resize((im.width * scale, im.height * scale), Image.NEAREST) if scale != 1 else im


def stack(images: list[Image.Image], labels: list[str] | None = None, pad: int = 6) -> Image.Image:
    lab_h = 12 if labels else 0
    w = max(im.width for im in images) + 2 * pad
    h = sum(im.height + lab_h + pad for im in images) + pad
    out = Image.new("RGB", (w, h), (235, 235, 235))
    d = ImageDraw.Draw(out)
    y = pad
    for i, im in enumerate(images):
        if labels:
            d.text((pad, y), labels[i], fill=(160, 0, 0))
            y += lab_h
        out.paste(im, (pad, y))
        y += im.height + pad
    return out


def message_pages(ko: dict[str, str], mid: str, max_pages: int = 3) -> list[str]:
    t = visible(ko.get(mid, ""))
    return [p.strip("\n") for p in t.split("\f") if p.strip()][:max_pages]


def write_previews(spec: Spec, res: Result, ko: dict[str, str], jp_text: dict[str, str]) -> list[str]:
    PREVIEW.mkdir(parents=True, exist_ok=True)
    paths = []
    new = L.parse(res.data)
    orig = L.parse(romfs_path(spec.rel).read_bytes())
    nsi, osi = L.SheetImages(new), L.SheetImages(orig)
    for k, img in enumerate(nsi.images):
        p = PREVIEW / f"{spec.name}_sheet{k}.png"
        sheet_png(img).save(p)
        paths.append(str(p))
    # diff of sheet 0: grey = original ink (unchanged), red = pixels that differ from the original
    o0, n0 = osi.images[0], nsi.images[0]
    rgb = np.full(o0.shape + (3,), 255, dtype=np.uint8)
    ink = (255 - o0.astype(np.uint16) * 12).astype(np.uint8)
    rgb[..., 0] = rgb[..., 1] = rgb[..., 2] = ink
    changed = o0 != n0
    rgb[changed] = [220, 30, 30]
    p = PREVIEW / f"{spec.name}_sheet0_diff.png"
    Image.fromarray(rgb).save(p)
    paths.append(str(p))
    # sample lines rendered from the NEW font file only
    missing: set[str] = set()
    blocks, labels = [], []
    donor = L.parse((DONOR_ROOT / spec.donor).read_bytes()) if spec.donor and res.donor_shift else None
    dsi = L.SheetImages(donor) if donor else None
    for mid in SAMPLES.get(spec.name, []) + ITEM_SAMPLES[:6 if spec.name != "font_l" else 0]:
        pages = message_pages(ko, mid, 3 if mid.startswith(("FMsg", "BMsg")) else 1)
        if mid.startswith("Item") and mid in jp_text:
            jp_pages = [p for p in visible(jp_text[mid]).split("\f") if p.strip()][:1]
            blocks.append(to_rgb(render_text(orig, osi.images, jp_pages[0]), 2))
            labels.append(f"{mid} JP original")
        for pg in pages:
            blocks.append(to_rgb(render_text(new, nsi.images, pg, missing), 2))
            labels.append(f"{mid} KO")
            if donor:
                blocks.append(to_rgb(render_text(donor, dsi.images, pg, set()), 2))
                labels.append(f"{mid} KO drawn with the 1DX font itself (reference; '?' = not in 1DX)")
    if spec.name == "font":
        jp_mid = "FMsg/o_peach_1f_01#10"
        if jp_mid in jp_text:
            jp_pages = [p for p in visible(jp_text[jp_mid]).split("\f") if p.strip()][:2]
            for pg in jp_pages:
                blocks.insert(0, to_rgb(render_text(orig, osi.images, pg), 2))
                labels.insert(0, f"{jp_mid} JP original (reference)")
    if blocks:
        p = PREVIEW / f"sample_{spec.name}.png"
        stack(blocks, labels).save(p)
        paths.append(str(p))
    # every added glyph that is not a straight 1DX copy, grouped by where it came from, each
    # drawn between two real 1DX-copied syllables (가 ... 다) so the style can be compared
    if res.donor_shift:
        groups: dict[str, list[str]] = {}
        for ch in res.added:
            src = res.sources.get(ch, "?")
            if src != "1dx":
                groups.setdefault(src, []).append(ch)
        qa, qlab = [], []
        for src, chs in sorted(groups.items(), key=lambda e: -len(e[1])):
            for i in range(0, len(chs), 24):
                part = chs[i:i + 24]
                text = " ".join(f"가{c}다" if is_hangul(c) else c for c in part)
                qa.append(to_rgb(render_text(new, nsi.images, text), 3))
                qlab.append(f"{spec.name}: {src} ({i + 1}-{i + len(part)} of {len(chs)})")
        if qa:
            p = PREVIEW / f"not_from_1dx_{spec.name}.png"
            stack(qa, qlab).save(p)
            paths.append(str(p))
    if missing:
        res.problems.append(f"{spec.name}: preview drew alter-char for {''.join(sorted(missing))!r}")
    return paths


# --------------------------------------------------------------------- compare mode
def grid(blocks: list[Image.Image], labels: list[str], cols: int = 2) -> Image.Image:
    bw = max(b.width for b in blocks) + 10
    bh = max(b.height for b in blocks) + 16
    rows = (len(blocks) + cols - 1) // cols
    img = Image.new("RGB", (cols * bw, rows * bh), (230, 230, 230))
    d = ImageDraw.Draw(img)
    for i, (b, lab) in enumerate(zip(blocks, labels)):
        x, y = (i % cols) * bw + 5, (i // cols) * bh
        d.text((x, y + 1), lab.encode("ascii", "replace").decode(), fill=(170, 0, 0))
        img.paste(b, (x, y + 13))
    return img


def cmd_compare(ko: dict[str, str], only: list[str], jp_text: dict[str, str]) -> int:
    """work/font_preview/compare_<font>.png: the Japanese glyphs for reference, then every face at
    three sizes (FreeType hinted and 4x supersampled), the chosen setting with darker gamma, and a
    line of the densest syllables the translation uses."""
    used = used_chars(ko)
    base_adv = base_advances()
    px_sets = {"font": [15, 16, 17], "font_l": [22, 23, 24], "font_btl": [11, 12, 13]}
    PREVIEW.mkdir(parents=True, exist_ok=True)
    for name in only:
        spec0 = SPECS[name]
        orig = L.parse(romfs_path(spec0.rel).read_bytes())
        osi = L.SheetImages(orig)
        ras = Rasterizer(spec0.face, spec0.px, spec0.method, orig.cell_w, orig.cell_h)
        hangul = [c for c in used if is_hangul(c)]
        dense = "".join(sorted(hangul, key=lambda c: -int(ras.render(c, orig.cell_h - 3, spec0.full_adv)[0].sum()))[:11])
        mids = SAMPLES[name][:2]
        ko_lines = [ln for mid in mids for ln in message_pages(ko, mid, 1)[0].split("\n")][:2]
        jp_lines = [ln for mid in mids for ln in visible(jp_text.get(mid, "")).split("\f")[0].split("\n")][:2]
        text = "\n".join(ko_lines + [dense])
        chars = sorted(set(text) - {"\n"})
        blocks = [to_rgb(render_text(orig, osi.images, "\n".join(jp_lines)), 2)]
        labels = [f"{name}: Japanese original glyphs (reference)"]
        variants = [(face, px, method, 1.0) for method in ("hinted", "ss4") for face in FACES
                    for px in px_sets[name]]
        variants += [(spec0.face, spec0.px, spec0.method, g) for g in (0.75, 0.6)]
        for face, px, method, gamma in variants:
            spec = Spec(name, spec0.rel, face, px, method, spec0.full_adv, gamma)
            res = build_font(spec, chars, used, set(), False, base_adv, use_donor=False)
            nf = L.parse(res.data)
            blocks.append(to_rgb(render_text(nf, L.SheetImages(nf).images, text), 2))
            chosen = (face, px, method, gamma) == (spec0.face, spec0.px, spec0.method, spec0.gamma)
            clip = sum(1 for p in res.problems if "clipped" in p)
            labels.append(f"{face.rsplit('.', 1)[0]} {px}px {method} gamma {gamma}"
                          + (f" clipped {clip}" if clip else "") + ("  <== CHOSEN" if chosen else ""))
        p = PREVIEW / f"compare_{name}.png"
        grid(blocks, labels).save(p)
        print(f"wrote {p} ({len(blocks)} blocks)")
    return 0


# --------------------------------------------------------------------- misc
def base_advances() -> dict[str, int]:
    f = L.parse(romfs_path(SPECS["font"].rel).read_bytes())
    w = f.widths()
    return {chr(cp): w[g].char for cp, g in f.char_map().items()}


def jp_texts() -> dict[str, str]:
    out = {}
    for p in (ROOT / "text" / "jp").glob("*.json"):
        for m in json.loads(p.read_text(encoding="utf-8"))["messages"]:
            out[m["id"]] = m["jp"]
    return out


def cmd_selftest() -> int:
    ok = True
    for rel in ["Msg/JP_ja/font.bffnt", "Msg/JP_ja/font_l.bffnt", "Msg/JP_ja/font_btl.bffnt",
                "Msg/font_ruby.bffnt", "Msg/gaizi.bffnt"]:
        d = romfs_path(rel).read_bytes()
        f = L.parse(d)
        same = L.build(f) == d
        sheets_ok = all(L.encode_sheet(L.decode_sheet(s, f.sheet_w, f.sheet_h, f.sheet_fmt)) == s for s in f.sheets)
        rng = np.random.default_rng(1)
        img = rng.integers(0, 16, (f.sheet_h, f.sheet_w), dtype=np.uint8)
        rt = np.array_equal(L.decode_sheet(L.encode_sheet(img), f.sheet_w, f.sheet_h), img)
        print(f"  {rel}: build(parse) identical={same}, sheet round trip={sheets_ok}, random image round trip={rt}")
        ok &= same and sheets_ok and rt
    print("selftest", "OK" if ok else "FAILED")
    return 0 if ok else 1


def cmd_compose_test(only: list[str]) -> int:
    """Leave-one-out check of hangul_compose on each 1DX donor font: rebuild syllables 1DX HAS
    without using them and compare with the real glyphs (work/build/compose_test.json)."""
    import random
    out = {}
    for name in only:
        spec = SPECS[name]
        comp = Composer(L.parse((DONOR_ROOT / spec.donor).read_bytes()))
        random.seed(11)
        sample = random.sample(sorted(comp.glyphs), min(300, len(comp.glyphs)))
        out[name] = {"strict": leave_one_out(comp, sample), "relaxed_only": leave_one_out(comp, sample, only_relaxed=True)}
        for mode, r in out[name].items():
            print(f"{name} {mode}: composed {r['composed']}/{r['tested']}, mean IoU {r['iou_mean']:.3f} "
                  f"(10th pct {r['iou_p10']:.3f}), mean abs error {r['mae_mean']:.2f}/15")
    p = REPORT.with_name("compose_test.json")
    p.parent.mkdir(parents=True, exist_ok=True)
    p.write_text(json.dumps(out, ensure_ascii=False, indent=1), encoding="utf-8")
    print("report", p)
    return 0


def main(argv: list[str] | None = None) -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--all-hangul", action="store_true")
    ap.add_argument("--same-size", action="store_true")
    ap.add_argument("--no-donor", action="store_true", help="render every new glyph from fonts/ (old build)")
    ap.add_argument("--compose-test", action="store_true")
    ap.add_argument("--compare", action="store_true")
    ap.add_argument("--selftest", action="store_true")
    ap.add_argument("--no-preview", action="store_true")
    ap.add_argument("--only", default="font,font_l,font_btl")
    ap.add_argument("--out", type=Path, default=PATCH_ROMFS)
    a = ap.parse_args(sys.argv[1:] if argv is None else argv)
    a.out = a.out.resolve()
    only = [s.strip() for s in a.only.split(",") if s.strip()]
    if a.selftest:
        return cmd_selftest()
    if a.compose_test:
        return cmd_compose_test(only)
    t0 = time.time()
    ko = load_ko()
    jp = jp_texts()
    if a.compare:
        return cmd_compare(ko, only, jp)
    used = used_chars(ko)
    priority = font_span_chars(ko)
    base_adv = base_advances()
    wanted = sorted(set(used) | set(EXTRA_WANTED))
    if a.all_hangul:
        wanted = sorted(set(wanted) | set(ksx1001_hangul()))
    out_dir = a.out / "Msg" / "JP_ja"
    out_dir.mkdir(parents=True, exist_ok=True)
    mode = "same-size" if a.same_size else ("all-hangul" if a.all_hangul else ("no-donor" if a.no_donor else "used"))
    report = {"mode": mode, "used_chars": len(used), "used_hangul": sum(1 for c in used if is_hangul(c)),
              "extra_wanted": EXTRA_WANTED, "donor_root": str(DONOR_ROOT) if not a.no_donor else None, "fonts": {}}
    failed = 0
    print(f"characters used by work/ko_final.json: {len(used)} ({report['used_hangul']} Hangul); "
          f"wanted per font: {len(wanted)}")
    for name in only:
        spec = SPECS[name]
        res = build_font(spec, wanted, used, priority, a.same_size, base_adv, use_donor=not a.no_donor)
        path = out_dir / Path(spec.rel).name
        path.write_bytes(res.data)
        data = path.read_bytes()
        bad = verify(spec, res, data, wanted, a.same_size, path)
        previews = [] if a.no_preview else write_previews(spec, res, ko, jp)
        failed += bool(bad)
        orig = L.parse(romfs_path(spec.rel).read_bytes())
        by_src: dict[str, str] = {}
        for ch in res.added:
            by_src[res.sources.get(ch, "?")] = by_src.get(res.sources.get(ch, "?"), "") + ch
        print(f"== {name}: {res.size_before:,} -> {res.size_after:,} bytes, sheets {res.sheets_before} -> "
              f"{res.sheets_after}, glyphs {orig.glyph_count()} -> {L.parse(data).glyph_count()}, "
              f"added {len(res.added)} ({sum(1 for c in res.added if is_hangul(c))} Hangul)")
        for src, chs in sorted(by_src.items(), key=lambda e: -len(e[1])):
            print(f"   from {src}: {len(chs)}" + (f" {chs[:60]!r}" if len(chs) <= 60 or src != "1dx" else ""))
        if a.same_size:
            print(f"   reclaimed {res.reclaimed} unused kana/kanji cells; dropped {len(res.dropped)} "
                  f"({sum(1 for c in res.dropped if c in priority)} of them inside font-switch tag spans): "
                  f"{''.join(res.dropped[:80])!r}")
        info = [p for p in res.problems if any(k in p for k in ("unchanged", "outside", "model", "bffnt_advances",
                                                                "identical to"))]
        for p in info:
            print("   ", p)
        issues = [p for p in res.problems if p not in info]
        for p in issues[:20]:
            print("   note:", p)
        for b in bad[:20]:
            print("   FAIL:", b)
        report["fonts"][name] = {
            "file": str(path), "size_before": res.size_before, "size_after": res.size_after,
            "sheets_before": res.sheets_before, "sheets_after": res.sheets_after,
            "glyphs_before": orig.glyph_count(), "glyphs_after": L.parse(data).glyph_count(),
            "added": len(res.added), "added_non_hangul": "".join(c for c in res.added if not is_hangul(c)),
            "dropped": "".join(res.dropped), "reclaimed": res.reclaimed,
            "donor": spec.donor if not a.no_donor else None, "donor_shift": res.donor_shift,
            "sources": {src: len(chs) for src, chs in by_src.items()},
            "not_from_1dx": {src: chs for src, chs in by_src.items() if src != "1dx"},
            "face": spec.face, "px": spec.px, "method": spec.method,
            "baseline_cjk": res.baseline_cjk, "baseline_latin": res.baseline_latin,
            "notes": res.problems, "failures": bad, "previews": previews}
    REPORT.parent.mkdir(parents=True, exist_ok=True)
    rpath = REPORT if report["mode"] == "used" else REPORT.with_name(f"font_report_{report['mode']}.json")
    rpath.write_text(json.dumps(report, ensure_ascii=False, indent=1), encoding="utf-8")
    print(f"{'OK' if not failed else f'{failed} FONT(S) FAILED'} in {time.time() - t0:.1f}s; report {rpath}")
    return 1 if failed else 0


if __name__ == "__main__":
    sys.exit(main())
