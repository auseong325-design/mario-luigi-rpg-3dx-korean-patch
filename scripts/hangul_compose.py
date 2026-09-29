"""Compose Hangul syllables a bitmap font lacks out of syllables it has (glyph analogies).

The Korean 1DX fonts (Mario & Luigi RPG1 DX, KR) hold only the syllables that game needs
(font/font_btl 1,103, font_l 287). build_font.py copies every 1DX glyph it can and asks this
module for the missing ones. A missing syllable S is built from three glyphs of the SAME font:

    S = A + B - B'     A  = S with one jamo replaced             (펀 <- 펄: final ㄹ, not ㄴ)
                       B  = a syllable that has the jamo S needs  (번: final ㄴ)
                       B' = B with A's jamo instead               (벌: final ㄹ)

so 펀 = 펄 + 번 - 벌: the change ㄹ -> ㄴ is measured on 번/벌 and applied to 펄. This is exact
when the exchanged jamo is drawn the same way in both places, so B/B' are picked to share A's
vowel shape and its layout (with or without a final). Up to `k` analogies are evaluated and
merged with a pixel-wise median, which cancels the artefacts of any single one. Glyphs are
aligned in pen space (the CWDH 'left' offset applied), so the result keeps the font's spacing.

leave_one_out() rebuilds syllables the font HAS without using them and measures the error
against the real glyph; build_font.py --compose-test runs it.
"""

from __future__ import annotations

from dataclasses import dataclass, field

import numpy as np

import libbffnt as L

N_L, N_V, N_T = 19, 21, 28

# the initial consonant's shape depends on the vowel beside/below it
INITIAL_CTX = {0: "R", 2: "R", 20: "R",                 # ㅏ ㅑ ㅣ
               4: "Lt", 6: "Lt",                        # ㅓ ㅕ (ticks point at the initial)
               1: "D", 3: "D", 5: "D", 7: "D",          # ㅐ ㅒ ㅔ ㅖ
               8: "Hu", 12: "Hu",                       # ㅗ ㅛ (stems between initial and bar)
               13: "Hd", 17: "Hd",                      # ㅜ ㅠ (bar in the middle)
               18: "Hf",                                # ㅡ (bar low, tall initial)
               9: "Co", 10: "Co", 11: "Co",             # ㅘ ㅙ ㅚ
               14: "Cu", 15: "Cu", 16: "Cu",            # ㅝ ㅞ ㅟ
               19: "Cf"}                                # ㅢ
# the final consonant's shape/position depends on the vowel above it
FINAL_CTX = {v: ("vs" if v in (0, 2, 4, 6, 20) else "vd" if v in (1, 3, 5, 7)
                 else "h" if v in (8, 12, 13, 17, 18) else "c") for v in range(N_V)}
VOWEL_CLASS = {v: ("v" if v in (0, 1, 2, 3, 4, 5, 6, 7, 20) else "h" if v in (8, 12, 13, 17, 18) else "c")
               for v in range(N_V)}
RELAXED_PENALTY = 1.5     # added when the relaxed pass borrows from another vowel shape group


def decompose(ch: str) -> tuple[int, int, int]:
    s = ord(ch) - 0xAC00
    return s // 588, (s % 588) // 28, s % 28


def syllable(l: int, v: int, t: int) -> str:
    return chr(0xAC00 + (l * N_V + v) * N_T + t)


def is_syllable(ch: str) -> bool:
    return len(ch) == 1 and 0xAC00 <= ord(ch) <= 0xD7A3


@dataclass
class Composed:
    pix: np.ndarray              # (cell_h, cell_w) uint8 0..15, ink starts at column 0
    width: L.CharWidth
    recipes: list[str] = field(default_factory=list)   # "A+B-B'" of every analogy used
    relaxed: bool = False        # True when only the relaxed (cross-group) pass found analogies


class Composer:
    """Analogy-based composer over the Hangul glyphs of one BFFNT."""

    def __init__(self, font: L.Bffnt, margin: int = 3):
        si = L.SheetImages(font)
        widths = font.widths()
        self.cell_h, self.cell_w, self.m = font.cell_h, font.cell_w, margin
        self.W = font.cell_w + 2 * margin
        self.glyphs: dict[str, np.ndarray] = {}
        self.adv: dict[str, int] = {}
        for cp, g in font.char_map().items():
            ch = chr(cp)
            if not is_syllable(ch):
                continue
            cw = widths[g]
            canvas = np.zeros((self.cell_h, self.W), dtype=np.float64)
            x0 = margin + cw.left
            gw = min(cw.glyph, self.W - x0)
            if x0 < 0 or gw <= 0:
                continue
            canvas[:, x0:x0 + gw] = si.cell(g)[:, :gw]
            self.glyphs[ch] = canvas
            self.adv[ch] = cw.char
        self.have = {decompose(c) for c in self.glyphs}
        self.maps = self._learn_maps()

    def _learn_maps(self) -> dict[tuple, np.ndarray]:
        """Where one jamo lives, learned from the font: mean |G1 - G2| over syllable pairs that
        differ in that jamo only (per vowel context and final layout), scaled to 0..1."""
        from collections import defaultdict
        acc: dict[tuple, list] = {}

        def add(key, a, b):
            s = acc.setdefault(key, [0.0, 0])
            s[0] = s[0] + np.abs(a - b)
            s[1] += 1

        by_vt, by_lv, by_lt = defaultdict(list), defaultdict(list), defaultdict(list)
        for ch, img in self.glyphs.items():
            l, v, t = decompose(ch)
            by_vt[(v, t)].append(img)
            by_lv[(l, v)].append((t, img))
            by_lt[(l, t)].append((v, img))
        for (v, t), imgs in by_vt.items():
            for i in range(len(imgs)):
                for j in range(i + 1, len(imgs)):
                    add(("I", INITIAL_CTX[v], t > 0), imgs[i], imgs[j])
        for (l, v), lst in by_lv.items():
            fin = [img for t, img in lst if t > 0]
            for i in range(len(fin)):
                for j in range(i + 1, len(fin)):
                    add(("F", FINAL_CTX[v]), fin[i], fin[j])
        for (l, t), lst in by_lt.items():
            for i in range(len(lst)):
                for j in range(i + 1, len(lst)):
                    if INITIAL_CTX[lst[i][0]] == INITIAL_CTX[lst[j][0]]:
                        add(("V", INITIAL_CTX[lst[i][0]], t > 0), lst[i][1], lst[j][1])
        maps = {}
        for key, (s, n) in acc.items():
            m = s / n
            maps[key] = m / max(float(m.max()), 1e-9)
        return maps

    def movement(self, key: tuple, b: np.ndarray, b2: np.ndarray) -> float:
        """Share of the B/B' difference that lies OUTSIDE the area where the exchanged jamo lives
        (0 = the exchange moved nothing else, so the analogy transfers cleanly)."""
        m = self.maps.get(key)
        d = np.abs(b - b2)
        tot = float(d.sum())
        if m is None or tot == 0:
            return 0.5
        return float((d * (1.0 - m)).sum() / tot)

    # ---------------------------------------------------------------- analogies
    @staticmethod
    def _ctx(table: dict, v: int, v2: int, relaxed: bool) -> float | None:
        """Context penalty for using vowel v2 where v is wanted (None = not allowed)."""
        if table[v] == table[v2]:
            return 0.0
        if relaxed and VOWEL_CLASS[v] == VOWEL_CLASS[v2]:
            return RELAXED_PENALTY
        return None

    def analogies(self, l: int, v: int, t: int, have: set[tuple[int, int, int]],
                  relaxed: bool = False) -> list[tuple]:
        """(context score, map key, A, B, B') candidates; lower score = closer contexts.
        relaxed also accepts vowels of the same class but another shape group (penalised)."""
        out: list[tuple] = []
        # 1) exchange the final:  A=(l,v,t1)  B=(l2,v2,t)  B'=(l2,v2,t1)   (only between finals)
        if t:
            for t1 in range(1, N_T):
                if t1 == t or (l, v, t1) not in have:
                    continue
                for v2 in range(N_V):
                    p = self._ctx(FINAL_CTX, v, v2, relaxed)
                    if p is None:
                        continue
                    for l2 in range(N_L):
                        if (l2, v2, t) in have and (l2, v2, t1) in have:
                            out.append((p + (0.0 if v2 == v else 1.0), ("F", FINAL_CTX[v2]),
                                        (l, v, t1), (l2, v2, t), (l2, v2, t1)))
        # 2) exchange the initial:  A=(l2,v,t)  B=(l,v2,t2)  B'=(l2,v2,t2)   (same final layout)
        for l2 in range(N_L):
            if l2 == l or (l2, v, t) not in have:
                continue
            for v2 in range(N_V):
                p = self._ctx(INITIAL_CTX, v, v2, relaxed)
                if p is None:
                    continue
                for t2 in range(N_T):
                    if (t2 > 0) != (t > 0):
                        continue
                    if (l, v2, t2) in have and (l2, v2, t2) in have:
                        s = p + 0.5 + (0.0 if v2 == v else 1.0) + (0.0 if t2 == t else 0.5)
                        out.append((s, ("I", INITIAL_CTX[v2], t2 > 0), (l2, v, t), (l, v2, t2), (l2, v2, t2)))
        # 3) exchange the vowel:  A=(l,v2,t)  B=(l2,v,t3)  B'=(l2,v2,t3)   (same initial context)
        for v2 in range(N_V):
            if v2 == v or (l, v2, t) not in have:
                continue
            p = self._ctx(INITIAL_CTX, v, v2, relaxed)
            if p is None:
                continue
            for l2 in range(N_L):
                for t3 in range(N_T):
                    if (t3 > 0) != (t > 0):
                        continue
                    if (l2, v, t3) in have and (l2, v2, t3) in have:
                        s = p + 1.5 + (0.0 if t3 == t else 0.5) + (0.0 if FINAL_CTX[v2] == FINAL_CTX[v] else 1.0)
                        out.append((s, ("V", INITIAL_CTX[v2], t3 > 0), (l, v2, t), (l2, v, t3), (l2, v2, t3)))
        return out

    def ranked(self, l: int, v: int, t: int, have: set[tuple[int, int, int]], k: int,
               move_weight: float = 2.0, per_donor: int = 2, tier: float = 1.0,
               relaxed: bool = False, only_relaxed: bool = False) -> list[tuple]:
        """The k best analogies: context score + move_weight * movement(B, B') within `tier` of
        the best, at most per_donor of them sharing one A, so one odd donor cannot dominate.
        only_relaxed keeps just the candidates the strict rules would refuse (for testing)."""
        scored = []
        strict = {(a, b, b2) for _, _, a, b, b2 in self.analogies(l, v, t, have)} if only_relaxed else set()
        for s, key, a, b, b2 in self.analogies(l, v, t, have, relaxed or only_relaxed):
            if only_relaxed and (a, b, b2) in strict:
                continue
            B, B2 = self.glyphs[syllable(*b)], self.glyphs[syllable(*b2)]
            scored.append((s + move_weight * self.movement(key, B, B2), a, b, b2))
        scored.sort(key=lambda e: e[0])
        if not scored:
            return []
        best, uses, out = scored[0][0], {}, []
        for e in scored:
            if e[0] > best + tier or len(out) >= k:
                break
            if uses.get(e[1], 0) >= per_donor:
                continue
            uses[e[1]] = uses.get(e[1], 0) + 1
            out.append(e)
        return out

    def compose(self, ch: str, k: int = 7, exclude: set[str] | None = None, tier: float = 1.0,
                relaxed: bool = True, only_relaxed: bool = False) -> Composed | None:
        """Median of the k best analogies for syllable ch (None when there is none). Strict
        contexts first; if they give nothing and relaxed is True, the relaxed pass."""
        l, v, t = decompose(ch)
        have = self.have
        if exclude:
            have = have - {decompose(c) for c in exclude}
        have = have - {(l, v, t)}
        used_relaxed = only_relaxed
        cands = self.ranked(l, v, t, have, k, tier=tier, only_relaxed=only_relaxed)
        if not cands and relaxed and not only_relaxed:
            cands = self.ranked(l, v, t, have, k, tier=tier, relaxed=True)
            used_relaxed = True
        if not cands:
            return None
        imgs, recipes, advs = [], [], []
        for _, a, b, b2 in cands:
            A, B, B2 = (self.glyphs[syllable(*x)] for x in (a, b, b2))
            imgs.append(np.clip(A + B - B2, 0, 15))
            recipes.append(f"{syllable(*a)}+{syllable(*b)}-{syllable(*b2)}")
            advs.append(self.adv[syllable(*a)])
        img = np.median(np.stack(imgs), axis=0) if len(imgs) > 2 else np.mean(np.stack(imgs), axis=0)
        img = deghost(np.rint(img))
        out = self._to_cell(img.astype(np.uint8), max(set(advs), key=advs.count), recipes)
        if out is not None:
            out.relaxed = used_relaxed
        return out

    def _to_cell(self, canvas: np.ndarray, adv: int, recipes: list[str]) -> Composed | None:
        cols = np.nonzero(canvas.any(axis=0))[0]
        pix = np.zeros((self.cell_h, self.cell_w), dtype=np.uint8)
        if not len(cols):
            return None
        x0, x1 = int(cols[0]), int(cols[-1])
        gw = min(x1 - x0 + 1, self.cell_w)
        pix[:, :gw] = canvas[:, x0:x0 + gw]
        return Composed(pix, L.CharWidth(x0 - self.m, gw, adv), recipes)

    def pen_image(self, ch: str) -> np.ndarray:
        return self.glyphs[ch]


def _near_strong(img: np.ndarray, strong: int) -> np.ndarray:
    """True where the pixel or one of its 8 neighbours is >= strong."""
    s = img >= strong
    p = np.pad(s, 1)
    h, w = img.shape
    out = np.zeros_like(s)
    for dy in (0, 1, 2):
        for dx in (0, 1, 2):
            out |= p[dy:dy + h, dx:dx + w]
    return out


def deghost(img: np.ndarray, strong: int = 12, faint: int = 9) -> np.ndarray:
    """Drop the grey residue an imperfect analogy leaves behind: pixels up to `faint` that do
    not touch a stroke pixel (>= `strong`), and the barely visible 0..1 values."""
    out = img.copy()
    out[(out <= faint) & ~_near_strong(out, strong)] = 0
    out[out <= 1] = 0
    return out


def ghost_pixels(img: np.ndarray) -> int:
    """Grey pixels that float free of any stroke (what deghost removes); 0 for clean glyphs."""
    return int(((img >= 2) & (img <= 9) & ~_near_strong(img, 12)).sum())


def _bbox_values(img: np.ndarray) -> np.ndarray:
    ys, xs = np.nonzero(img)
    if not len(ys):
        return np.zeros(0, dtype=np.int64)
    return img[ys.min():ys.max() + 1, xs.min():xs.max() + 1].astype(np.int64).ravel()


def tone_lut(pairs: list[tuple[np.ndarray, np.ndarray]]) -> np.ndarray:
    """Histogram matching over (made, real) glyph pairs of the same syllables: a monotonic
    16-level table that gives made glyphs the value distribution of real ones inside their ink
    box (soft halos of a scaled or averaged glyph go to 0, its mid-tones get the real darkness)."""
    made = np.concatenate([_bbox_values(m) for m, _ in pairs])
    real = np.concatenate([_bbox_values(r) for _, r in pairs])
    cm = np.cumsum(np.bincount(made, minlength=16)[:16]) / max(1, len(made))
    cr = np.cumsum(np.bincount(real, minlength=16)[:16]) / max(1, len(real))
    lut = np.array([int(np.searchsorted(cr, cm[v] - 1e-9)) for v in range(16)], dtype=np.uint8)
    lut[0] = 0
    return np.minimum(np.maximum.accumulate(lut), 15)


def pen_canvas(pix: np.ndarray, cw: L.CharWidth, width: int, margin: int = 3) -> np.ndarray:
    """A cell bitmap + CWDH as a pen-space canvas (same convention as Composer.glyphs)."""
    out = np.zeros((pix.shape[0], width), dtype=np.float64)
    x0 = margin + cw.left
    gw = max(0, min(cw.glyph, width - x0))
    if x0 >= 0 and gw:
        out[:, x0:x0 + gw] = pix[:, :gw]
    return out


def leave_one_out(comp: Composer, chars: list[str], k: int = 7, tier: float = 1.0,
                  relaxed: bool = False, only_relaxed: bool = False) -> dict:
    """Rebuild syllables the font has without them; error statistics against the real glyphs.

    mae   mean absolute alpha difference (0..15) over the union of both ink boxes
    iou   overlap of the ink masks (alpha >= 6)
    only_relaxed measures the relaxed pass alone (what the leftovers get)
    """
    maes, ious, fails, worst = [], [], [], []
    for ch in chars:
        c = comp.compose(ch, k=k, exclude={ch}, tier=tier, relaxed=relaxed, only_relaxed=only_relaxed)
        if c is None:
            fails.append(ch)
            continue
        got = pen_canvas(c.pix, c.width, comp.W, comp.m)
        real = comp.glyphs[ch]
        box = (got > 0) | (real > 0)
        mae = float(np.abs(got - real)[box].mean()) if box.any() else 0.0
        a, b = got >= 6, real >= 6
        iou = float((a & b).sum() / max(1, (a | b).sum()))
        maes.append(mae)
        ious.append(iou)
        worst.append((mae, ch, c.recipes[:3]))
    worst.sort(reverse=True)
    q = (lambda xs, p: float(np.percentile(xs, p)) if xs else float("nan"))
    return {"tested": len(chars), "composed": len(maes), "no_analogy": "".join(fails),
            "mae_mean": float(np.mean(maes)) if maes else float("nan"), "mae_p90": q(maes, 90),
            "iou_mean": float(np.mean(ious)) if ious else float("nan"), "iou_p10": q(ious, 10),
            "worst": [(round(m, 2), ch, r) for m, ch, r in worst[:10]]}
