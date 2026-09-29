"""imgtext_bank -- letter shapes for imgtext: the 1DX glyph bank, bitmap fonts, composition, OFL.

Sources (IMAGE_TASK.md 1.1, first one that covers the whole word wins; one source per word):
  same_word  a 1DX KR image showing exactly this word           (bank, same image)
  bank       syllables cut from 1DX KR images                    (work/img/toolkit/bank)
  font       1DX KR bitmap font glyphs (font 17x18 / font_l 23x24, the one closest in size)
  compose    1DX font + syllables composed from it (hangul_compose, A+B-B')
  ofl        fonts/ OFL font chosen by overlap with the bank (last resort; reported)
Latin / digits / punctuation are separate words: same_word > bank (1DX images) > 3DX bitmap font
(the game's own Latin glyphs) > ofl.

build_bank() cuts the images listed in work/img/toolkit/bank_labels.json into syllables
(face coverage only, decoration removed) and writes bank/*.png + bank.json + a review sheet, and
the font-vs-image overlap report (bank_report.json).
"""

from __future__ import annotations

import json
import math
import sys
from dataclasses import dataclass, field
from functools import lru_cache
from pathlib import Path

import cv2
import numpy as np
from PIL import Image

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "scripts"))
import imgtext as T  # noqa: E402

BANK = T.TOOLKIT / "bank"
FONT_1DX = {"font": ROOT / "ml 1dx/3romfs/Msg/KR_ko/font.bffnt",
            "font_l": ROOT / "ml 1dx/3romfs/Msg/KR_ko/font_l.bffnt",
            # battle font 13x14 (em 11, 1,103 syllables): small labels at their own size (A-1)
            "font_btl": ROOT / "ml 1dx/3romfs/Msg/KR_ko/font_btl.bffnt"}
FONT_3DX = ROOT / "romfs/Msg/JP_ja/font.bffnt"
OFL = {"NanumSquareRoundEB": ROOT / "fonts/NanumSquareRoundEB.ttf",
       "NanumSquareRoundB": ROOT / "fonts/NanumSquareRoundB.ttf",
       "NotoSansKR-Bold": ROOT / "fonts/NotoSansKR-Bold.otf",
       "NotoSansKR-Medium": ROOT / "fonts/NotoSansKR-Medium.otf",
       "GothicA1-Bold": ROOT / "fonts/GothicA1-Bold.ttf",
       "GothicA1-ExtraBold": ROOT / "fonts/GothicA1-ExtraBold.ttf",
       "GothicA1-Black": ROOT / "fonts/GothicA1-Black.ttf",
       "NanumGothic-ExtraBold": ROOT / "fonts/NanumGothic-ExtraBold.ttf",
       "BlackHanSans-Regular": ROOT / "fonts/BlackHanSans-Regular.ttf",
       "Jua-Regular": ROOT / "fonts/Jua-Regular.ttf",
       "DoHyeon-Regular": ROOT / "fonts/DoHyeon-Regular.ttf",
       "Sunflower-Bold": ROOT / "fonts/Sunflower-Bold.ttf"}
# Vector fallback (source 5 / large letters): the OFL family closest to the 1DX image lettering
# (aspect-preserving overlap with the 145 bank syllables of em >= 15: GothicA1-Black 0.564,
# NanumSquareRoundEB 0.548, NanumGothic-ExtraBold 0.547, NotoSansKR-Bold 0.538, Jua 0.515,
# BlackHanSans 0.513). One family, three weights: the weight whose own stroke is closest to the
# Japanese stroke is used and the rest is added by counter-safe thickening (imgtext.thicken).
OFL_LADDER = ["GothicA1-Bold", "GothicA1-ExtraBold", "GothicA1-Black"]
# size rule (IMAGE_TASK.md 1): bitmap glyphs (font / compose) and bank glyphs are enlarged at
# most this much; larger letters come from a source drawn at least that big, else vector.
MAX_UPSCALE = 1.25
BANK_MIN_EM = 14.0          # bank glyphs cut from smaller images are too coarse to reuse
BANK_MIN_QUALITY = 0.45     # overlap with the same 1DX font syllable (catches bad cuts)


def is_hangul(ch: str) -> bool:
    return 0xAC00 <= ord(ch) <= 0xD7A3


# ----------------------------------------------------------------------------- glyph records


@dataclass
class Glyph:
    ch: str
    cov: np.ndarray            # ink coverage 0..1, cropped to the ink box
    y: float                   # ink top relative to the em-box top, source px
    em: float                  # em-box (Hangul face height) of the source, px
    gap: float                 # typical space after this glyph, source px
    src: str                   # "bank:<image>" / "font:font_l" / ...
    stroke: float = 0.0


# ----------------------------------------------------------------------------- bank building


def _expected_w(ch: str) -> float:
    if is_hangul(ch) or ord(ch) >= 0x3000:          # Hangul, kana, kanji, full-width
        return 0.95
    if ch in "…":
        return 0.9
    if ch in ".,:;!'":
        return 0.3
    if ch in "&?":
        return 0.75
    if ch in "iIl1":
        return 0.35
    if ch in "mMwW":
        return 0.85
    return 0.62


def segment_line(L: np.ndarray, chars: str, em: float) -> list[tuple[int, int]] | None:
    """Cut one text line (face coverage, rows = the line band) into len(chars) column ranges
    by dynamic programming: segments should hold one glyph of the expected width, cuts should
    cross as little ink as possible."""
    W = L.shape[1]
    k = len(chars)
    p = L.sum(axis=0)
    occ = p > 0.3
    if occ.sum() == 0 or k == 0:
        return None
    pn = p / max(p.max(), 1e-6)
    nxt = np.full(W + 1, W, int)
    for x in range(W - 1, -1, -1):
        nxt[x] = x if occ[x] else nxt[x + 1]
    prv = np.full(W + 1, -1, int)
    for x in range(1, W + 1):
        prv[x] = x - 1 if occ[x - 1] else prv[x - 1]
    a = np.arange(W + 1)[:, None]
    b = np.arange(W + 1)[None, :]
    first = nxt[np.minimum(a, W)]
    last = prv[b]
    inkw = np.where((first < b) & (last >= a), last - first + 1, 0).astype(float)
    valid = b > a
    cut = np.concatenate([pn, [0.0]]) * 6.0          # cost of cutting before column x
    cut[0] = 0
    INF = 1e9
    best = np.full(W + 1, INF)
    best[0] = 0.0
    back = []
    for i, ch in enumerate(chars):
        e = _expected_w(ch) * em
        seg = ((inkw - e) / em) ** 2 * 2.0
        seg = np.where(inkw > 0, seg, INF)
        seg = np.where(valid, seg, INF)
        M = best[:, None] + seg + cut[:, None] * (1 if i > 0 else 0)
        arg = M.argmin(axis=0)
        best = M[arg, np.arange(W + 1)]
        back.append(arg)
    if best[W] >= INF:
        return None
    cuts = [W]
    x = W
    for i in range(k - 1, -1, -1):
        x = back[i][x]
        cuts.append(x)
    cuts = cuts[::-1]
    return [(cuts[i], cuts[i + 1]) for i in range(k)]


def _find_png(game: str, name: str) -> Path | None:
    m = json.loads((ROOT / "work/img/lyt_manifest.json").read_text(encoding="utf-8"))
    for t in m[game]:
        if Path(t["file"]).stem == name and (ROOT / t["png"]).exists():
            return ROOT / t["png"]
    return None


def split_lines_by_components(cov: np.ndarray, n: int):
    """Lines whose ink boxes overlap or touch: cut between consecutive lines along the
    least-ink horizontal seam (dynamic programming, the path may move 1 row per column),
    searched between 25 % and 75 % of each pair of expected line positions."""
    rows = np.nonzero(cov.max(axis=1) > 0.12)[0]
    if not len(rows):
        return [cov] * n, []
    top, bot = rows.min(), rows.max() + 1
    h, w = cov.shape
    seams = []
    for k in range(1, n):
        mid = top + (bot - top) * k / n
        span = (bot - top) / n
        lo, hi = int(mid - 0.3 * span), int(math.ceil(mid + 0.3 * span))
        lo, hi = max(lo, top + 1), min(hi, bot - 1)
        e = cov[lo:hi] + 1e-3 * np.abs(np.arange(lo, hi) - mid)[:, None]
        R = hi - lo
        acc = e[:, 0].copy()
        back = np.zeros((R, w), int)
        for x in range(1, w):
            prev = np.stack([np.r_[np.inf, acc[:-1]], acc, np.r_[acc[1:], np.inf]])
            j = prev.argmin(axis=0)
            back[:, x] = j - 1
            acc = prev[j, np.arange(R)] + e[:, x]
        y = int(acc.argmin())
        path = np.zeros(w, int)
        for x in range(w - 1, -1, -1):
            path[x] = y + lo
            y = y + back[y, x] if x > 0 else y
        seams.append(path)
    covs, bands = [], []
    yy = np.arange(h)[:, None]
    for k in range(n):
        m = np.ones((h, w), bool)
        if k > 0:
            m &= yy > seams[k - 1][None, :]
        if k < n - 1:
            m &= yy <= seams[k][None, :]
        c = np.where(m, cov, 0.0)
        r = np.nonzero(c.max(axis=1) > 0.12)[0]
        if not len(r):
            return [cov] * n, []
        covs.append(c)
        bands.append((int(r.min()), int(r.max()) + 1))
    return covs, bands


def build_bank() -> dict:
    labels = json.loads((T.TOOLKIT / "bank_labels.json").read_text(encoding="utf-8"))
    m = json.loads((ROOT / "work/img/lyt_manifest.json").read_text(encoding="utf-8"))
    pngs = {}
    for t in m["1DX"]:
        if (ROOT / t["png"]).exists():
            pngs.setdefault(Path(t["file"]).stem, ROOT / t["png"])
    BANK.mkdir(parents=True, exist_ok=True)
    for f in BANK.glob("*.png"):
        f.unlink()
    entries, problems, images = [], [], {}
    for key, text in labels.items():
        if key.startswith("_"):
            continue
        p = pngs.get(f"{key}_12_KR_ko")
        if p is None:
            problems.append(f"{key}: png not found")
            continue
        rgba = T.load_png(p)
        fc = T.face_coverage(rgba)
        cov = fc.cov
        lines = text.split("\n")
        bands = T.line_bands(cov, len(lines))
        line_covs = [cov] * len(lines)
        if len(lines) > 1:
            line_covs, bands = split_lines_by_components(cov, len(lines))
        if len(bands) != len(lines):
            problems.append(f"{key}: {len(bands)} bands for {len(lines)} lines")
            continue
        img_rec = {"png": str(p.relative_to(ROOT)).replace("\\", "/"), "text": text, "lines": []}
        for li, (ltxt, (y0, y1)) in enumerate(zip(lines, bands)):
            L = line_covs[li][y0:y1]
            chars = ltxt.replace(" ", "")
            hang = [c for c in chars if is_hangul(c)]
            # em = Hangul face height; for a line without Hangul, the band height
            em = float(y1 - y0)
            segs = segment_line(L, chars, em)
            if segs is None:
                problems.append(f"{key}: line {li} not segmented")
                continue
            # tighten: per glyph ink box
            boxes = []
            for (a, b) in segs:
                sub = L[:, a:b]
                ys, xs = np.nonzero(sub > 0.12)
                if not len(ys):
                    boxes.append(None)
                    continue
                boxes.append((a + xs.min(), ys.min(), a + xs.max() + 1, ys.max() + 1))
            # em of the line: median height of Hangul glyphs (tallest decides the band)
            hh = [bx[3] - bx[1] for bx, c in zip(boxes, chars) if bx and is_hangul(c)]
            em_line = float(y1 - y0)
            gaps = [boxes[i + 1][0] - boxes[i][2] for i in range(len(boxes) - 1)
                    if boxes[i] and boxes[i + 1]]
            # which gaps contain a space
            sp_after = []
            j = 0
            for i, c in enumerate(ltxt):
                if c == " ":
                    sp_after.append(j - 1)
                else:
                    j += 1
            line_rec = {"band": [int(y0), int(y1)], "em": em_line, "glyphs": []}
            for i, (c, bx) in enumerate(zip(chars, boxes)):
                if bx is None:
                    problems.append(f"{key}: empty glyph {c}")
                    continue
                x0, gy0, x1, gy1 = [int(v) for v in bx]
                g = L[gy0:gy1, x0:x1]
                name = f"{key}_{li}_{i}.png"
                Image.fromarray(np.clip(np.rint(g * 255), 0, 255).astype(np.uint8), "L").save(BANK / name)
                gap = None
                if i < len(boxes) - 1 and boxes[i + 1]:
                    gap = int(boxes[i + 1][0] - x1)
                e = {"ch": c, "file": name, "image": key, "line": li, "x": x0, "y": gy0, "w": x1 - x0,
                     "h": gy1 - gy0, "em": em_line, "gap_after": gap, "space_after": i in sp_after,
                     "stroke": round(T.stroke_width(g), 3), "fmt": T.texinfo(p)["fmt"] if T.texinfo(p) else None}
                entries.append(e)
                line_rec["glyphs"].append(len(entries) - 1)
            img_rec["lines"].append(line_rec)
        images[key] = img_rec
    # spacing statistics (glyph gap / em, space gap / em) over Hangul pairs
    gs = [e["gap_after"] / e["em"] for e in entries if e["gap_after"] is not None and not e["space_after"]
          and is_hangul(e["ch"])]
    ss = [e["gap_after"] / e["em"] for e in entries if e["gap_after"] is not None and e["space_after"]]
    meta = {"version": T.VERSION, "glyphs": len(entries), "images": len(images),
            "syllables": len({e["ch"] for e in entries if is_hangul(e["ch"])}),
            "gap_em": round(float(np.median(gs)), 4) if gs else 0.08,
            "space_em": round(float(np.median(ss)), 4) if ss else 0.35,
            "problems": problems}
    bank = {"meta": meta, "images": images, "glyphs": entries}
    (T.TOOLKIT / "bank.json").write_text(json.dumps(bank, ensure_ascii=False, indent=1), encoding="utf-8")
    _bank_sheet(bank)
    rep = font_report(bank)
    meta["ofl_choice"] = rep["ofl_choice"]
    (T.TOOLKIT / "bank.json").write_text(json.dumps(bank, ensure_ascii=False, indent=1), encoding="utf-8")
    _bank_cache.cache_clear()
    print(json.dumps(meta, ensure_ascii=False, indent=1))
    return bank


def _bank_sheet(bank: dict) -> None:
    """Review sheet of the cut glyphs: per image, the cut syllables at 4x with their labels."""
    from PIL import ImageDraw, ImageFont
    font = ImageFont.truetype(str(ROOT / "fonts/NotoSansKR-Medium.otf"), 12)
    rows = []
    for key, rec in bank["images"].items():
        ids = [i for ln in rec["lines"] for i in ln["glyphs"]]
        tiles = []
        for i in ids:
            e = bank["glyphs"][i]
            g = np.asarray(Image.open(BANK / e["file"]), np.float64) / 255
            z = cv2.resize(g, (g.shape[1] * 3, g.shape[0] * 3), interpolation=cv2.INTER_NEAREST)
            tiles.append((e["ch"], z))
        if not tiles:
            continue
        h = max(t.shape[0] for _, t in tiles) + 16
        w = sum(t.shape[1] + 6 for _, t in tiles) + 200
        im = Image.new("RGB", (w, h), (30, 30, 30))
        d = ImageDraw.Draw(im)
        d.text((2, 2), key[:28], fill=(255, 220, 120), font=font)
        x = 200
        for ch, z in tiles:
            im.paste(Image.fromarray((z * 255).astype(np.uint8)).convert("RGB"), (x, 14))
            d.text((x, 0), ch, fill=(120, 220, 255), font=font)
            x += z.shape[1] + 6
        rows.append(im)
    # sheets of at most 1600 x 1600 px (IMAGE_TASK.md 3); new name so the old oversized
    # I2_bank_01..03.png are never overwritten with something that looks safe to open
    T.save_tiled(rows, ROOT / "work/img/review/I2_banksheet.png", gap=2)


def cut_glyphs(rgba, text: str, strict: bool = False) -> dict:
    """Letter shapes cut from ONE image (face only, decoration removed), e.g. a 3DX original of
    the same family: cut_glyphs(STbr_SPEED png, "SPEED") gives S, P, E, D in the exact shape
    the game uses next to them. text = what the image shows ('\\n' = line break, spaces are
    ignored). Returns {char: Glyph}; em = the line's ink band height (for a Latin-only image,
    the cap height). Used through render(..., donors=[(png, text)])."""
    if not isinstance(rgba, np.ndarray):
        rgba = T.load_png(rgba)
    cov = T.face_coverage(rgba).cov
    lines = text.split("\n")
    bands = T.line_bands(cov, len(lines))
    covs = [cov] * len(lines)
    if len(lines) > 1:
        covs, bands = split_lines_by_components(cov, len(lines))
    out = {}
    for li, (ltxt, (y0, y1)) in enumerate(zip(lines, bands)):
        L = covs[li][y0:y1]
        chars = ltxt.replace(" ", "")
        segs = segment_line(L, chars, float(y1 - y0))
        if segs is None:
            if strict:
                raise ValueError(f"cannot cut {ltxt!r}")
            continue
        cut = []
        for c, (a, b) in zip(chars, segs):
            sub = L[:, a:b].copy()
            # drop slivers of the neighbouring glyph: small components touching the cut edge
            n, lab, stats, _ = cv2.connectedComponentsWithStats((sub > 0.12).astype(np.uint8), connectivity=8)
            if n > 2:
                tot = stats[1:, cv2.CC_STAT_AREA].sum()
                big = stats[1:, cv2.CC_STAT_AREA].max()
                for k in range(1, n):
                    x, _, ww, _, area = stats[k]
                    if (x == 0 or x + ww >= sub.shape[1]) and area < 0.2 * tot:
                        sub[lab == k] = 0
                    elif c.isascii() and c.isalnum() and c not in "ij" and area < 0.2 * big:
                        sub[lab == k] = 0          # Latin letters have no detached dots
            ys, xs = np.nonzero(sub > 0.12)
            if not len(ys):
                continue
            cut.append((c, sub[ys.min():ys.max() + 1, xs.min():xs.max() + 1], float(ys.min())))
        if not cut:
            continue
        # em = median glyph height (round letters such as S / O overshoot the band), so a donor
        # of the same size as the target is used pixel for pixel
        em = float(np.median([g.shape[0] for _, g, _ in cut]))
        top = float(np.median([y for _, _, y in cut]))
        for c, g, y in cut:
            if c not in out:
                out[c] = Glyph(c, g, y - top, em, 0.08 * em, "donor", T.stroke_width(g))
    return out


# ----------------------------------------------------------------------------- loading sources


@lru_cache(maxsize=1)
def _bank_cache():
    p = T.TOOLKIT / "bank.json"
    if not p.exists():
        return {"meta": {"gap_em": 0.08, "space_em": 0.35}, "glyphs": [], "images": {}}, {}
    bank = json.loads(p.read_text(encoding="utf-8"))
    by_ch: dict[str, list[int]] = {}
    for i, e in enumerate(bank["glyphs"]):
        by_ch.setdefault(e["ch"], []).append(i)
    return bank, by_ch


@lru_cache(maxsize=None)
def _bank_glyph(i: int) -> Glyph:
    bank, _ = _bank_cache()
    e = bank["glyphs"][i]
    cov = np.asarray(Image.open(BANK / e["file"]), np.float64) / 255
    band_top = bank["images"][e["image"]]["lines"][e["line"]]["band"][0]
    gap = e["gap_after"] if (e["gap_after"] is not None and not e["space_after"]) else bank["meta"]["gap_em"] * e["em"]
    return Glyph(e["ch"], cov, float(e["y"]), float(e["em"]), float(gap), f"bank:{e['image']}", e["stroke"])


class BitmapFont:
    """A BFFNT as a glyph source: coverage per character, em = median Hangul ink height."""

    def __init__(self, path: Path, name: str):
        import libbffnt as L
        self.name, self.path = name, path
        self.font = L.parse(path.read_bytes())
        self.si = L.SheetImages(self.font)
        self.widths = self.font.widths()
        self.cmap = self.font.char_map()
        tops, hs = [], []
        for cp, g in self.cmap.items():
            if 0xAC00 <= cp <= 0xD7A3:
                c = self.si.cell(g)
                ys = np.nonzero(c.max(axis=1) >= 6)[0]
                if len(ys):
                    tops.append(ys.min())
                    hs.append(ys.max() + 1 - ys.min())
        self.em = float(np.median(hs)) if hs else float(self.font.cell_h)
        self.top = float(np.median(tops)) if tops else 0.0
        # cap height (ink of H / E) for Latin-only lines
        ctops, chs = [], []
        for ch in "HEIN":
            g = self.cmap.get(ord(ch))
            if g is None:
                continue
            c = self.si.cell(g)
            ys = np.nonzero(c.max(axis=1) >= 6)[0]
            if len(ys):
                ctops.append(ys.min())
                chs.append(ys.max() + 1 - ys.min())
        self.cap = float(np.median(chs)) if chs else self.em
        self.cap_top = float(np.median(ctops)) if ctops else self.top
        gaps = []
        for cp, g in self.cmap.items():
            if 0xAC00 <= cp <= 0xD7A3:
                cw = self.widths[g]
                gaps.append(cw.char - cw.glyph - cw.left)
        self.gap = float(np.median(gaps)) if gaps else 1.0
        self._composer = None

    def has(self, ch: str) -> bool:
        return ord(ch) in self.cmap

    def _from_pix(self, ch: str, pix: np.ndarray, src: str) -> Glyph | None:
        cov = pix.astype(np.float64) / 15.0
        ys, xs = np.nonzero(cov > 0.05)
        if not len(ys):
            return None
        y0, y1, x0, x1 = ys.min(), ys.max() + 1, xs.min(), xs.max() + 1
        return Glyph(ch, cov[y0:y1, x0:x1], float(y0 - self.top), self.em, self.gap, src,
                     T.stroke_width(cov[y0:y1, x0:x1]))

    def glyph(self, ch: str) -> Glyph | None:
        g = self.cmap.get(ord(ch))
        if g is None:
            return None
        cw = self.widths[g]
        pix = self.si.cell(g)[:, :max(1, cw.glyph)]
        return self._from_pix(ch, pix, f"font:{self.name}")

    def composed(self, ch: str) -> Glyph | None:
        import hangul_compose as H
        if self._composer is None:
            self._composer = H.Composer(self.font)
        c = self._composer.compose(ch)
        if c is None:
            return None
        return self._from_pix(ch, c.pix[:, :max(1, c.width.glyph)], f"compose:{self.name}")


@lru_cache(maxsize=None)
def bitmap_font(name: str) -> BitmapFont:
    if name == "3dx_font":
        return BitmapFont(FONT_3DX, name)
    return BitmapFont(FONT_1DX[name], name)


class OflFont:
    """A vector font. glyph() renders at the base size (reports); glyph_at(ch, em_px) renders
    directly at the size needed, so large letters stay sharp (no bitmap enlargement)."""

    def __init__(self, name: str, px: int = 96):
        from PIL import ImageFont
        self.name = name
        self.px = px
        self.f = ImageFont.truetype(str(OFL[name]), px)
        self._sized = {}
        ref = self._raw("한")
        ys = np.nonzero(ref.max(axis=1) > 0.5)[0]
        self.em = float(ys.max() + 1 - ys.min())
        self.top = float(ys.min())
        g = self.glyph("한")
        self.stroke_em = g.stroke / self.em if g else 0.12

    def _raw(self, ch: str, f=None, px=None) -> np.ndarray:
        from PIL import ImageDraw
        f = f or self.f
        px = px or self.px
        im = Image.new("L", (px * 2, px * 2), 0)
        ImageDraw.Draw(im).text((px // 2, px // 4), ch, fill=255, font=f)
        return np.asarray(im, np.float64) / 255

    def _at(self, px: int):
        if px not in self._sized:
            from PIL import ImageFont
            f = ImageFont.truetype(str(OFL[self.name]), px)
            r = self._raw("한", f, px)
            ys = np.nonzero(r.max(axis=1) > 0.5)[0]
            self._sized[px] = (f, float(ys.max() + 1 - ys.min()), float(ys.min()))
        return self._sized[px]

    def glyph(self, ch: str) -> Glyph | None:
        r = self._raw(ch)
        ys, xs = np.nonzero(r > 0.05)
        if not len(ys):
            return None
        y0, y1, x0, x1 = ys.min(), ys.max() + 1, xs.min(), xs.max() + 1
        return Glyph(ch, r[y0:y1, x0:x1], float(y0 - self.top), self.em, 0.08 * self.em, f"ofl:{self.name}",
                     T.stroke_width(r[y0:y1, x0:x1], 1))

    def glyph_at(self, ch: str, em_px: float) -> Glyph | None:
        """Glyph rendered so that its Hangul face height is ~em_px (hi-res target pixels)."""
        px = max(8, int(round(em_px * self.px / self.em)))
        f, em, top = self._at(px)
        r = self._raw(ch, f, px)
        ys, xs = np.nonzero(r > 0.02)
        if not len(ys):
            return None
        y0, y1, x0, x1 = ys.min(), ys.max() + 1, xs.min(), xs.max() + 1
        return Glyph(ch, r[y0:y1, x0:x1], float(y0 - top), em, 0.08 * em, f"ofl:{self.name}",
                     self.stroke_em * em)


@lru_cache(maxsize=None)
def ofl_font(name: str) -> OflFont:
    return OflFont(name)


# ----------------------------------------------------------------------------- glyph runs


@dataclass
class Placed:
    mask: np.ndarray           # hi-res soft mask (target scale)
    y: float                   # top relative to em top (target px)
    gap: float                 # space after (target px)
    space: float = 0.0         # extra word space after (target px)


@dataclass
class GlyphRun:
    """One line of text as hi-res glyph masks (all in target pixels = em * scale)."""
    glyphs: list
    em_h: float
    stroke: float
    sources: list = field(default_factory=list)   # [(word, source)]

    @property
    def top(self) -> float:
        return min([0.0] + [g.y for g in self.glyphs])

    def gaps(self) -> int:
        return max(0, len(self.glyphs) - 1)

    def width(self, tracking: float = 0.0, hscale: float = 1.0) -> float:
        if not self.glyphs:
            return 0.0
        w = sum(g.mask.shape[1] * hscale for g in self.glyphs)
        w += sum((g.gap + g.space) * hscale + tracking for g in self.glyphs[:-1])
        return w

    def raster(self, hscale: float = 1.0, tracking: float = 0.0) -> np.ndarray:
        top = self.top
        bot = max([self.em_h] + [g.y + g.mask.shape[0] for g in self.glyphs])
        H = int(math.ceil(bot - top)) + 2
        W = int(math.ceil(self.width(tracking, hscale))) + 2
        out = np.zeros((H, max(W, 1)), np.float32)
        x = 0.0
        for i, g in enumerate(self.glyphs):
            m = g.mask
            if hscale != 1.0:
                m = cv2.resize(m.astype(np.float32), (max(1, int(round(m.shape[1] * hscale))), m.shape[0]),
                               interpolation=cv2.INTER_AREA if hscale < 1 else cv2.INTER_LINEAR)
            xi, yi = int(round(x)), int(round(g.y - top))
            T._paste_max(out, m.astype(np.float32), xi, yi)
            x += m.shape[1] + (g.gap + g.space) * hscale + tracking
        return out


def _words(text: str) -> list[tuple[str, bool, bool]]:
    """Split a line into (word, is_hangul_run, space_after)."""
    out = []
    cur, kind = "", None
    for ch in text:
        if ch == " ":
            if cur:
                out.append([cur, kind, True])
                cur, kind = "", None
            elif out:
                out[-1][2] = True
            continue
        k = is_hangul(ch)
        if cur and k != kind:
            out.append([cur, kind, False])
            cur = ""
        cur += ch
        kind = k
    if cur:
        out.append([cur, kind, False])
    return [tuple(w) for w in out]


def _size_cost(src_em: float, em: float) -> float:
    r = src_em / em
    return abs(math.log(r)) * (1.6 if r < 1 else 1.0)       # upscaling is worse than downscaling


def _upscale_ok(src_em: float, em_native: float) -> bool:
    return em_native <= MAX_UPSCALE * src_em + 1e-6


# ---- bank quality and style groups


def _norm_aspect(cov: np.ndarray, scale: float, S: int = 64) -> np.ndarray:
    """Binary shape, resized by `scale`, centred by its centroid on a 2S x 2S canvas."""
    big = T.upsample(cov, scale) >= 0.5
    out = np.zeros((2 * S, 2 * S), bool)
    ys, xs = np.nonzero(big)
    if not len(ys):
        return out
    oy, ox = int(round(S - ys.mean())), int(round(S - xs.mean()))
    h, w = big.shape
    y0, x0, y1, x1 = max(0, oy), max(0, ox), min(2 * S, oy + h), min(2 * S, ox + w)
    if y1 > y0 and x1 > x0:
        out[y0:y1, x0:x1] = big[y0 - oy:y1 - oy, x0 - ox:x1 - ox]
    return out


def shape_iou(a_cov: np.ndarray, b_cov: np.ndarray, S: int = 64) -> float:
    """Overlap of two glyph shapes at the same ink height (aspect kept, a small horizontal
    stretch is searched because fonts differ in width)."""
    a = _norm_aspect(a_cov, S / max(1, a_cov.shape[0]) * 0.9, S)
    best = 0.0
    for sx in (0.88, 0.94, 1.0, 1.06, 1.12):
        b = _norm_aspect(cv2.resize(b_cov.astype(np.float32), None, fx=sx, fy=1.0,
                                    interpolation=cv2.INTER_LINEAR), S / max(1, b_cov.shape[0]) * 0.9, S)
        best = max(best, float((a & b).sum() / max(1, (a | b).sum())))
    return best


@lru_cache(maxsize=1)
def bank_quality() -> dict:
    """Per bank glyph: overlap with the same syllable in 1DX font_l (else font). A bad cut
    (two glyphs merged, a stroke lost) scores low. Cached in toolkit/bank_quality.json."""
    bank, _ = _bank_cache()
    p = T.TOOLKIT / "bank_quality.json"
    sig = f"{len(bank['glyphs'])}:{bank['meta'].get('version')}"
    if p.exists():
        d = json.loads(p.read_text(encoding="utf-8"))
        if d.get("sig") == sig:
            return {int(k): v for k, v in d["q"].items()}
    q = {}
    fl, fs = bitmap_font("font_l"), bitmap_font("font")
    for i, e in enumerate(bank["glyphs"]):
        if not is_hangul(e["ch"]):
            q[i] = 1.0
            continue
        fg = fl.glyph(e["ch"]) or fs.glyph(e["ch"])
        q[i] = round(shape_iou(_bank_glyph(i).cov, fg.cov), 3) if fg else 0.5
    p.write_text(json.dumps({"sig": sig, "q": q}, indent=0), encoding="utf-8")
    return q


@lru_cache(maxsize=1)
def bank_groups() -> dict:
    """Style group of every bank image: (em, stroke/em) of its Hangul. Images whose stroke/em
    differ by <= 0.03 and em by <= 30 % count as one lettering style (IMAGE_TASK.md 1: one
    style per word)."""
    bank, _ = _bank_cache()
    info = {}
    for key, rec in bank["images"].items():
        st, ems = [], []
        for ln in rec["lines"]:
            for i in ln["glyphs"]:
                e = bank["glyphs"][i]
                if is_hangul(e["ch"]):
                    st.append(e["stroke"] / e["em"])
                    ems.append(e["em"])
        if st:
            info[key] = {"em": float(np.median(ems)), "st_em": float(np.median(st))}
    return info


def _compatible(a: str, b: str) -> bool:
    g = bank_groups()
    if a not in g or b not in g:
        return False
    x, y = g[a], g[b]
    return abs(x["st_em"] - y["st_em"]) <= 0.03 and max(x["em"], y["em"]) / min(x["em"], y["em"]) <= 1.3


def _bank_ok(i: int, em_native: float) -> bool:
    bank, _ = _bank_cache()
    e = bank["glyphs"][i]
    if e["em"] < BANK_MIN_EM or not _upscale_ok(e["em"], em_native):
        return False
    return bank_quality().get(i, 0) >= BANK_MIN_QUALITY


# ---- sources for one word


def _same_word(word: str, em_native: float, strict: bool = True) -> list[Glyph] | None:
    bank, _ = _bank_cache()
    best = None
    for key, rec in bank["images"].items():
        for li, ln in enumerate(rec["lines"]):
            ids = ln["glyphs"]
            chars = "".join(bank["glyphs"][i]["ch"] for i in ids)
            pos = chars.find(word)
            if pos < 0:
                continue
            ltxt = rec["text"].split("\n")[li]
            if word not in ltxt.split(" "):          # must be a whole word of the label
                continue
            sel = ids[pos:pos + len(word)]
            if strict and not all(_bank_ok(i, em_native) for i in sel):
                continue
            c = _size_cost(ln["em"], em_native)
            if best is None or c < best[0]:
                best = (c, sel)
    if best is None:
        return None
    return [_bank_glyph(i) for i in best[1]]


def _bank_pick(ch: str, em_native: float, anchor: str | None, strict: bool = True) -> int | None:
    bank, by_ch = _bank_cache()
    ids = [i for i in by_ch.get(ch, []) if (not strict or _bank_ok(i, em_native))
           and (anchor is None or bank["glyphs"][i]["image"] == anchor
                or _compatible(anchor, bank["glyphs"][i]["image"]))]
    if not ids:
        return None
    return min(ids, key=lambda i: _size_cost(bank["glyphs"][i]["em"], em_native)
               + (0.0 if anchor and bank["glyphs"][i]["image"] == anchor else 0.1)
               + (0.25 if "\n" in bank["images"][bank["glyphs"][i]["image"]]["text"] else 0.0))


def _bank_compose(ch: str, em_native: float, anchor: str) -> Glyph | None:
    """A+B-B' inside one style group (IMAGE_TASK.md 1.1 #4 applied to the image bank):
    target (l,v,t) = A(l,v,t') + B(l2,v2,t) - B'(l2,v2,t'), same vowel shape class, shapes
    aligned at the ink box's top-left in em units. Accepted only if the result looks like
    the 1DX font syllable (shape_iou >= 0.5)."""
    import hangul_compose as H
    bank, by_ch = _bank_cache()
    l, v, t = H.decompose(ch)
    have = {}
    for c, ids in by_ch.items():
        if not is_hangul(c):
            continue
        for i in ids:
            if _bank_ok(i, em_native) and (bank["glyphs"][i]["image"] == anchor
                                           or _compatible(anchor, bank["glyphs"][i]["image"])):
                have.setdefault(H.decompose(c), i)
                break
    ref = bitmap_font("font_l").glyph(ch) or bitmap_font("font").glyph(ch)
    best = None
    for (la, va, ta), ia in have.items():
        if (la, va) != (l, v) or ta == t:
            continue
        for (lb, vb, tb), ib in have.items():
            if tb != t or H.VOWEL_CLASS[vb] != H.VOWEL_CLASS[v] or (lb, vb) == (l, v):
                continue
            ib2 = have.get((lb, vb, ta))
            if ib2 is None:
                continue
            gs = [_bank_glyph(k) for k in (ia, ib, ib2)]
            em = gs[0].em
            S = 4.0
            cans = []
            for g in gs:
                m = T.upsample(g.cov, S * em / g.em)
                cans.append((m, g.y * S * em / g.em))
            off = int(2 * S * em * 0.5)
            H0 = int(max(m.shape[0] + y for m, y in cans)) + 2 * off + 4
            W0 = int(max(m.shape[1] for m, _ in cans)) + 4
            acc = np.zeros((H0, W0))
            for (m, y), sgn in zip(cans, (1, 1, -1)):
                c = np.zeros((H0, W0))
                yi = int(round(y)) + off
                c[yi:yi + m.shape[0], :m.shape[1]] = m
                acc += sgn * c
            acc = np.clip(acc, 0, 1)
            acc = cv2.resize(acc.astype(np.float32), None, fx=1 / S, fy=1 / S, interpolation=cv2.INTER_AREA)
            ys, xs = np.nonzero(acc > 0.12)
            if not len(ys):
                continue
            cov = acc[ys.min():ys.max() + 1, xs.min():xs.max() + 1].astype(np.float64)
            q = shape_iou(cov, ref.cov) if ref else 0.5
            if best is None or q > best[0]:
                best = (q, Glyph(ch, cov, float(ys.min()) - off / S, em, gs[0].gap, f"bankcompose:{anchor}",
                                 T.stroke_width(cov)))
    if best and best[0] >= 0.5:
        return best[1]
    return None


def _font_order(em_native: float, names=("font", "font_l", "font_btl")) -> list[str]:
    return sorted(names, key=lambda n: _size_cost(bitmap_font(n).em, em_native))


def _font_word(word: str, em_native: float, compose: bool, strict: bool = True) -> list[Glyph] | None:
    for n in _font_order(em_native):
        f = bitmap_font(n)
        if strict and not _upscale_ok(f.em, em_native):
            continue
        out = []
        for ch in word:
            g = f.glyph(ch)
            if g is None and compose and is_hangul(ch):
                g = f.composed(ch)
            if g is None:
                out = None
                break
            out.append(g)
        if out:
            return out
    return None


def _latin_word(word: str, em_native: float) -> tuple[list[Glyph] | None, str]:
    g = _same_word(word, em_native, strict=False)
    if g and all(_upscale_ok(x.em, em_native) for x in g):
        return g, "same_word"
    bank, by_ch = _bank_cache()
    ids = [_bank_pick(c, em_native, None, strict=False) for c in word]
    if all(i is not None for i in ids) and all(_upscale_ok(bank["glyphs"][i]["em"], em_native) for i in ids):
        return [_bank_glyph(i) for i in ids], "bank"
    if not any(c.isalnum() for c in word):
        # punctuation (~ ! ? … ♪): the 1DX Korean font's own symbols first (A-3)
        g = _font_word(word, em_native, False, True)
        if g:
            return g, g[0].src
    f = bitmap_font("3dx_font")
    if _upscale_ok(f.em, em_native):
        out = [f.glyph(c) for c in word]
        if all(out):
            return out, "font:3dx_font"
    return None, ""


def ofl_for_weight(weight_em: float | None) -> str:
    """Weight of the vector family whose own stroke/em is closest to (not above) the target."""
    if not weight_em:
        return OFL_LADDER[-1]
    best = OFL_LADDER[0]
    for n in OFL_LADDER:
        if ofl_font(n).stroke_em <= weight_em * 1.05:
            best = n
    return best


def _ofl_word(word: str, em_px: float | None = None, name: str | None = None) -> list[Glyph] | None:
    name = name or OFL_LADDER[-1]
    f = ofl_font(name)
    out = [f.glyph_at(c, em_px) if em_px else f.glyph(c) for c in word]
    return out if all(out) else None


def word_glyphs(word: str, em_native: float, source: str = "auto") -> tuple[list[Glyph], str]:
    """Glyphs of one word from the first source that covers all of it (kept for callers of
    v1.0; glyph_mask() now picks one source per LINE)."""
    for lvl in _order(source) + ["ofl"]:
        r = _line_words(word, lvl, em_native, em_native, None, True)
        if r:
            return r[0][0][0], r[0][0][1]
    raise ValueError(f"no glyph source for {word!r}")


# ---- one line


LEVELS = ["same_word", "bank", "font", "compose", "ofl"]


def _order(source: str) -> list[str]:
    if source == "auto":
        return LEVELS
    return LEVELS[LEVELS.index(source):] if source in LEVELS else [source]


def _line_words(text: str, lvl: str, em_native: float, em_px: float, weight_em: float | None,
                strict: bool, extra: dict | None = None) -> tuple[list, str] | None:
    """All words of a line from ONE Hangul source level. Returns ([(glyphs, src, space_after)],
    level name) or None when the level cannot cover every Hangul word."""
    words = _words(text)
    out = []
    anchor = None
    # donor letters only when they cover EVERY non-Hangul word of the line (a label must not
    # mix donor and font Latin: NEW from the original next to GAME from the font)
    if extra and not all(all(c in extra for c in w) for w, h, _ in words if not h):
        extra = {k: v for k, v in extra.items() if is_hangul(k)}
    latin_only = not any(is_hangul(c) for c in text)
    ofl_name = ofl_for_weight(weight_em) if lvl == "ofl" else None
    if lvl == "bank":
        # anchor = the image that covers most of the line's syllables
        bank, by_ch = _bank_cache()
        hang = [c for c in text if is_hangul(c)]
        cnt = {}
        for c in set(hang):
            for i in by_ch.get(c, []):
                if not strict or _bank_ok(i, em_native):
                    cnt.setdefault(bank["glyphs"][i]["image"], set()).add(c)
        if not cnt:
            return None
        anchor = max(cnt, key=lambda k: (len(cnt[k]), -_size_cost(bank_groups().get(k, {"em": 1})["em"], em_native)))
    for word, is_h, sp in words:
        if extra and all(c in extra for c in word):
            out.append(([extra[c] for c in word], "donor", sp))
            continue
        if not is_h:
            if lvl == "ofl":
                g = _ofl_word(word, em_px, ofl_name)
                out.append((g, "ofl:" + ofl_name, sp))
                continue
            g, s = _latin_word(word, em_native)
            if g is None:
                # punctuation / Latin without a small source: the vector family
                g, s = _ofl_word(word, em_px, ofl_for_weight(weight_em)), "ofl:" + ofl_for_weight(weight_em)
            elif latin_only and s.startswith("font:"):
                # a Latin-only line: em is the Japanese cap band -> scale by the cap height
                cap = bitmap_font(s.split(":")[1]).cap
                g = [Glyph(x.ch, x.cov, x.y - (bitmap_font(s.split(":")[1]).cap_top - bitmap_font(s.split(":")[1]).top),
                           cap, x.gap, x.src, x.stroke) for x in g]
            out.append((g, s, sp))
            continue
        if lvl == "same_word":
            g = _same_word(word, em_native, strict)
            s = "same_word"
        elif lvl == "bank":
            g = []
            for c in word:
                i = _bank_pick(c, em_native, anchor, strict)
                if i is not None:
                    g.append(_bank_glyph(i))
                    continue
                cg = _bank_compose(c, em_native, anchor)
                if cg is None:
                    g = None
                    break
                g.append(cg)
            if g:
                gap_em = _bank_cache()[0]["meta"]["gap_em"]
                g = [Glyph(x.ch, x.cov, x.y, x.em, gap_em * x.em, x.src, x.stroke) for x in g]
            s = f"bank:{anchor}"
        elif lvl in ("font", "compose"):
            g = _font_word(word, em_native, lvl == "compose", strict)
            s = g[0].src if g else ""
            if g and lvl == "compose":
                made = "".join(x.ch for x in g if x.src.startswith("compose"))
                s = f"compose:{g[0].src.split(':')[1]}({made})" if made else g[0].src
        else:
            g = _ofl_word(word, em_px, ofl_name)
            s = "ofl:" + ofl_name
        if not g:
            return None
        out.append((g, s, sp))
    return out, lvl


def glyph_mask(text: str, height_px: float, source: str = "auto", *, ss: int = 1,
               space_em: float | None = None, weight_px: float | None = None,
               strict: bool = True, extra: dict | None = None) -> GlyphRun:
    """Glyph run for one line. height_px = em (Hangul face height) of the run in the pixels it
    is drawn at; ss = how many times larger than the texture that is (render() uses
    height_px = em * SS, ss = SS), so sources are judged at the TEXTURE size.

    One source level for every Hangul word of the line, first that works of
    same_word > bank (one style group, A+B-B' inside it) > font > compose > ofl.
    `source` starts the search at that level. strict=True applies the size rule
    (IMAGE_TASK.md 1): bank / bitmap glyphs are never enlarged more than MAX_UPSCALE, bank
    glyphs come from images with em >= BANK_MIN_EM and pass the quality check; a level that
    breaks it is skipped (the vector family is drawn at the target size instead).
    weight_px = target face stroke in the same pixels as height_px (picks the vector weight).
    Latin / digits / punctuation: 1DX image or 3DX bitmap font when small enough, else the
    vector family. extra = {char: Glyph} (cut_glyphs of a donor image) wins for every word it
    fully covers."""
    bank, _ = _bank_cache()
    em_native = height_px / ss
    weight_em = (weight_px / height_px) if weight_px else None
    res = None
    for lvl in _order(source):
        res = _line_words(text, lvl, em_native, height_px, weight_em, strict, extra)
        if res:
            break
    if res is None:
        res = _line_words(text, "ofl", em_native, height_px, weight_em, strict, extra)
    words, lvl = res
    sp = (space_em if space_em is not None else bank["meta"]["space_em"]) * height_px
    placed, srcs, strokes, lat_strokes = [], [], [], []
    native = True
    for gl, s, space_after in words:
        srcs.append(("".join(g.ch for g in gl), s))
        for j, g in enumerate(gl):
            f = height_px / g.em
            if abs(f / ss - 1) > 0.01 or s.startswith("ofl"):
                native = False
            m = g.cov if abs(f - 1) < 0.03 else T.upsample(g.cov, f)
            if is_hangul(g.ch):
                strokes.append(g.stroke * f)
            elif g.ch.isalnum():
                lat_strokes.append(g.stroke * f)
            last = j == len(gl) - 1
            placed.append(Placed(m, g.y * f, 0.0 if last else g.gap * f, 0.0))
        if placed:
            placed[-1].gap = (bank["meta"]["gap_em"] * height_px)
            if space_after:
                placed[-1].space = sp
    if placed:
        placed[-1].gap = 0.0
        placed[-1].space = 0.0
    if native and ss > 1:
        # whole source pixels between glyphs, so every glyph stays on the texture pixel grid
        for p in placed:
            p.gap = round(p.gap / ss) * ss
            p.space = round(p.space / ss) * ss
    # weight is steered by the Hangul; a Latin-only line by its letters -- except donor letters,
    # which already have the weight of the image they were cut from
    stroke = float(np.median(strokes)) if strokes else \
        (float(np.median(lat_strokes)) if lat_strokes and lvl != "donor" and
         not all(s == "donor" for _, s in srcs) else 0.0)
    run = GlyphRun(placed, float(height_px), stroke, srcs)
    run.level = lvl
    run.native = native            # every glyph at its own pixel size (1 source px = 1 texture px)
    run.font_name = None
    if lvl in ("font", "compose"):
        for gl, s, _ in words:
            for g in gl:
                if is_hangul(g.ch) and ":" in g.src:
                    run.font_name = g.src.split(":")[1]
                    break
            if run.font_name:
                break
    return run


# ----------------------------------------------------------------------------- reports


def _norm_mask(cov: np.ndarray, y: float = 0, em: float = 1, size: int = 64) -> np.ndarray:
    """Shape only: the ink box resized to size x size (cubic), thresholded at 0.5."""
    h, w = cov.shape
    f = size / max(h, w)
    big = T.upsample(cov, f)
    big = cv2.resize(big.astype(np.float32), (size, size), interpolation=cv2.INTER_LINEAR)
    return big >= 0.5


def iou(a: np.ndarray, b: np.ndarray) -> float:
    return float((a & b).sum() / max(1, (a | b).sum()))


def font_report(bank: dict) -> dict:
    """Is the 1DX image lettering the 1DX bitmap font? Overlap (IoU) of every bank syllable with
    the same syllable in font / font_l and in each OFL candidate (em-normalised, ink centred)."""
    res = {"pairs": {}, "per_font": {}}
    by = {}
    for i, e in enumerate(bank["glyphs"]):
        if is_hangul(e["ch"]):
            by.setdefault(e["ch"], []).append(i)
    cands = {"font": bitmap_font("font"), "font_l": bitmap_font("font_l")}
    for n in OFL:
        cands[n] = ofl_font(n)
    scores = {n: [] for n in cands}
    wr = {n: [] for n in cands}
    by_size = {n: {"small": [], "large": []} for n in cands}
    for ch, ids in by.items():
        for i in ids:
            g = _bank_glyph(i)
            a = _norm_mask(g.cov, g.y, g.em)
            for n, f in cands.items():
                fg = f.glyph(ch)
                if fg is None:
                    continue
                s = iou(a, _norm_mask(fg.cov, fg.y, fg.em))
                scores[n].append(s)
                if g.stroke and fg.stroke:
                    wr[n].append((fg.stroke / fg.cov.shape[0]) / (g.stroke / g.cov.shape[0]))
                by_size[n]["small" if g.em <= 16 else "large"].append(s)
    for n, v in scores.items():
        res["per_font"][n] = {"n": len(v), "iou_mean": round(float(np.mean(v)), 3) if v else None,
                              "stroke_ratio_vs_image": round(float(np.median(wr[n])), 3) if wr[n] else None,
                              "iou_small_em<=16": round(float(np.mean(by_size[n]["small"])), 3) if by_size[n]["small"] else None,
                              "iou_large_em>16": round(float(np.mean(by_size[n]["large"])), 3) if by_size[n]["large"] else None}
    # font vs font_l on their shared syllables
    fl, fs = cands["font_l"], cands["font"]
    sh = [iou(_norm_mask(fs.glyph(chr(cp)).cov, fs.glyph(chr(cp)).y, fs.em),
              _norm_mask(fl.glyph(chr(cp)).cov, fl.glyph(chr(cp)).y, fl.em))
          for cp in fl.cmap if 0xAC00 <= cp <= 0xD7A3 and fs.has(chr(cp))]
    res["font_vs_font_l"] = round(float(np.mean(sh)), 3) if sh else None
    # image vs image of the same syllable (upper bound of what "same font" looks like)
    same = []
    for ch, ids in by.items():
        for x in range(len(ids)):
            for y in range(x + 1, len(ids)):
                a, b = _bank_glyph(ids[x]), _bank_glyph(ids[y])
                same.append(iou(_norm_mask(a.cov, a.y, a.em), _norm_mask(b.cov, b.y, b.em)))
    res["image_vs_image_same_syllable"] = round(float(np.mean(same)), 3) if same else None
    ofl_scores = {n: res["per_font"][n]["iou_mean"] or 0 for n in OFL}
    res["ofl_choice"] = max(ofl_scores, key=ofl_scores.get)
    # coverage of the bank vs the fonts
    res["bank_syllables"] = len(by)
    res["bank_not_in_font"] = "".join(sorted(c for c in by if not fs.has(c)))
    (T.TOOLKIT / "bank_report.json").write_text(json.dumps(res, ensure_ascii=False, indent=1), encoding="utf-8")
    return res


def selftest() -> None:
    """Quick checks: bank loads, every source produces a run, render gives the right size."""
    bank, by = _bank_cache()
    assert bank["glyphs"], "bank is empty: run `imgtext.py bank`"
    for src in ("auto", "bank", "font", "compose", "ofl"):
        r = glyph_mask("취소 테스트", 14 * T.SS, source=src, ss=T.SS)
        assert r.glyphs and r.raster().max() > 0.9, src
    st = T.Style(face_stops=[(0.0, (1, 1, 1)), (1.0, (0.8, 0.8, 0.8))], layers=[T.Layer(1.5, (0, 0, 0))],
                 shadow=T.Shadow(1, 1, 1.5, (0, 0, 0)), box=(10, 5, 90, 19), em=14, stroke=3, size=(100, 24),
                 lines=[(5, 19)])
    out = T.render("취소", st)
    assert out.shape == (24, 100, 4) and out[..., 3].max() > 0.99
    m = T.measure_style(out)
    assert m.layers and abs(m.layers[-1].width - 1.5) <= 0.5, m.layers
    assert m.shadow and abs(m.shadow.dx - 1) <= 0.5 and abs(m.shadow.dy - 1) <= 0.5, m.shadow
    print("imgtext selftest OK", T.VERSION)
