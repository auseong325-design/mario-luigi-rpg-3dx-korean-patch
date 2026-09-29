"""imgtext -- draw Korean text into the game's text images (layout / sprite / model textures).

Two layers, as work/IMAGE_TASK.md chapter 1 asks:
  * letter SHAPE  = Mario & Luigi RPG1 DX (Korean) -- glyph_mask() picks, per word, the first source
    that has every syllable: 1DX image with the same word > syllables cut from 1DX images >
    1DX bitmap font (font / font_l) > syllables composed from that font (A+B-B') > OFL font.
  * DECORATION    = measured on the 3DX Japanese original -- measure_style() finds the face colour
    (per-row gradient), outline layers (width + colour), drop shadow (offset, width, colour, blur),
    the text box, alignment, line count and stroke thickness.

render() rasterises the glyph run 4x larger as a signed distance field, applies the style
(face / outline layers / shadow), fits the box (horizontal scale down to 80 %, then tracking),
area-downsamples to the texture size and returns float RGBA 0..1. finalize() quantises it the way
the texture format will (LA4 = 16 grey + 16 alpha levels, RGBA4, ETC1A4 = real encode/decode).

    import imgtext as T
    jp = T.load_png("work/img/lyt/3DX/.../btn_cancel_00_JP_ja.png")
    ko, rep = T.redraw(jp, "취소", fmt="LA4")          # measure + render + finalize
    T.save_png(ko, "out.png"); print(rep["sources"], rep["fit"])

CLI (always run with a timeout, see AGENTS.md 3):
    python scripts/imgtext.py measure <png>
    python scripts/imgtext.py render <png> <text> <out.png> [--fmt LA4] [--sheet sheet.png]
    python scripts/imgtext.py bank          (rebuild work/img/toolkit/bank from bank_labels.json)
    python scripts/imgtext.py selftest

Full documentation: work/img/toolkit/README.md
"""

from __future__ import annotations

import json
import math
import sys
from dataclasses import asdict, dataclass, field
from pathlib import Path

import cv2
import numpy as np
from PIL import Image

ROOT = Path(__file__).resolve().parent.parent
TOOLKIT = ROOT / "work" / "img" / "toolkit"
SS = 4                      # supersampling factor of render()
VERSION = "1.3"

# ----------------------------------------------------------------------------- basic io


def load_png(path) -> np.ndarray:
    """PNG -> float RGBA (h, w, 4) in 0..1 (straight alpha)."""
    return np.asarray(Image.open(path).convert("RGBA"), dtype=np.float64) / 255.0


def save_png(rgba: np.ndarray, path) -> None:
    Path(path).parent.mkdir(parents=True, exist_ok=True)
    Image.fromarray(to_u8(rgba), "RGBA").save(path)


def to_u8(rgba: np.ndarray) -> np.ndarray:
    return np.clip(np.rint(np.asarray(rgba) * 255.0), 0, 255).astype(np.uint8)


def luminance(rgb: np.ndarray) -> np.ndarray:
    return rgb[..., 0] * 0.299 + rgb[..., 1] * 0.587 + rgb[..., 2] * 0.114


_MANIFEST = None


def texinfo(png_path) -> dict | None:
    """Manifest record (fmt, w, h, id, ...) of a work/img/lyt/... PNG, or None."""
    global _MANIFEST
    if _MANIFEST is None:
        m = json.loads((ROOT / "work/img/lyt_manifest.json").read_text(encoding="utf-8"))
        _MANIFEST = {}
        for game in m:
            for t in m[game]:
                _MANIFEST[str(Path(t["png"])).lower()] = t
    p = Path(png_path)
    try:
        p = p.resolve().relative_to(ROOT)
    except ValueError:
        pass
    return _MANIFEST.get(str(p).lower())


# ----------------------------------------------------------------------------- distance fields


def upsample(cov: np.ndarray, f: float, out_shape=None) -> np.ndarray:
    """Coverage 0..1 -> f-times larger soft mask whose 0.5 contour follows the source shape
    (cubic interpolation, then an edge ramp about one output pixel wide)."""
    h, w = cov.shape
    if out_shape is None:
        out_shape = (max(1, int(round(h * f))), max(1, int(round(w * f))))
    pad = 2
    c = np.pad(cov, pad)
    big = cv2.resize(c.astype(np.float32), (int(round((w + 2 * pad) * f)), int(round((h + 2 * pad) * f))),
                     interpolation=cv2.INTER_CUBIC)
    o = int(round(pad * f))
    big = big[o:o + out_shape[0], o:o + out_shape[1]]
    if big.shape != tuple(out_shape):
        big = cv2.resize(big, (out_shape[1], out_shape[0]), interpolation=cv2.INTER_LINEAR)
    gain = max(1.0, f * 0.8)
    return np.clip((big - 0.5) * gain + 0.5, 0.0, 1.0)


def sdf(mask: np.ndarray) -> np.ndarray:
    """Signed distance (pixels of `mask`'s own grid) to the 0.5 contour: <0 inside, >0 outside.
    The soft mask value is used for a sub-pixel correction at the boundary."""
    m = np.asarray(mask, np.float32)
    inside = (m >= 0.5).astype(np.uint8)
    if not inside.any():
        return np.full(m.shape, 1e4, np.float32)
    if inside.all():
        return np.full(m.shape, -1e4, np.float32)
    d_out = cv2.distanceTransform(1 - inside, cv2.DIST_L2, cv2.DIST_MASK_PRECISE)
    d_in = cv2.distanceTransform(inside, cv2.DIST_L2, cv2.DIST_MASK_PRECISE)
    d = np.where(inside > 0, -(d_in - 0.5), d_out - 0.5)
    # boundary pixels: use the soft value (a ramp of ~1 px) for a smoother contour
    edge = np.abs(d) < 1.0
    d[edge] = (0.5 - m[edge])
    return d.astype(np.float32)


def cov_from_sdf(d: np.ndarray, r: float = 0.0) -> np.ndarray:
    """Coverage of the region {d <= r} with a 1-pixel anti-aliasing ramp."""
    return np.clip(r - d + 0.5, 0.0, 1.0)


def shift(img: np.ndarray, dx: float, dy: float) -> np.ndarray:
    """Sub-pixel translation (zero fill)."""
    m = np.float32([[1, 0, dx], [0, 1, dy]])
    return cv2.warpAffine(img.astype(np.float32), m, (img.shape[1], img.shape[0]), flags=cv2.INTER_LINEAR,
                          borderMode=cv2.BORDER_CONSTANT, borderValue=0)


def downsample(img: np.ndarray, f: int) -> np.ndarray:
    h, w = img.shape[:2]
    return img.reshape(h // f, f, w // f, f, *img.shape[2:]).mean(axis=(1, 3))


def stroke_width(cov: np.ndarray, f: int = 4) -> float:
    """Mean stroke thickness in pixels of cov's grid: 2 * area / perimeter of the upsampled shape."""
    if cov.max() < 0.5:
        return 0.0
    big = (upsample(cov, f) >= 0.5).astype(np.uint8)
    cnts, _ = cv2.findContours(big, cv2.RETR_LIST, cv2.CHAIN_APPROX_NONE)
    per = sum(cv2.arcLength(c, True) for c in cnts)
    return float(2.0 * big.sum() / max(per, 1.0)) / f


# ----------------------------------------------------------------------------- face extraction


def _kmeans(x: np.ndarray, k: int) -> tuple[np.ndarray, np.ndarray]:
    crit = (cv2.TERM_CRITERIA_EPS + cv2.TERM_CRITERIA_MAX_ITER, 50, 1e-4)
    cv2.setRNGSeed(12345)           # deterministic: same image -> same split, whatever ran before
    _, lab, cen = cv2.kmeans(x.astype(np.float32), k, None, crit, 5, cv2.KMEANS_PP_CENTERS)
    return lab.ravel(), cen.astype(np.float64)


@dataclass
class Face:
    cov: np.ndarray                 # face coverage 0..1 (h, w)
    rows: np.ndarray                # face colour per row (h, 3)
    edge: np.ndarray | None         # outline / edge colour (3,) or None (face only)
    two_tone: bool


def face_coverage(rgba: np.ndarray, text_alpha: np.ndarray | None = None) -> Face:
    """Split a text image into the letter FACE (coverage 0..1 per pixel) and the rest.

    Opaque pixels are split into two colour clusters; the face is the cluster lying deeper inside
    the ink (larger distance to transparency). Face colour is estimated per row (gradients), and a
    pixel's face coverage is its position between edge and face colour times its alpha. Images
    with one colour (plain white titles, black labels) have face = alpha.
    `text_alpha` replaces the alpha channel (plate images, see erase_text)."""
    A = rgba[..., 3] if text_alpha is None else text_alpha
    C = rgba[..., :3]
    h, w = A.shape
    op = A > 0.8
    if op.sum() < 8:
        op = A > 0.4
    rows = np.ones((h, 3))
    if op.sum() < 8:
        return Face(A.copy(), rows, None, False)
    px = C[op]
    lab, cen = _kmeans(px, 2)
    if np.linalg.norm(cen[0] - cen[1]) < 0.18:
        col = np.median(px, axis=0)
        rows[:] = col
        return Face(A.copy(), rows, None, False)
    depth = cv2.distanceTransform((A > 0.4).astype(np.uint8), cv2.DIST_L2, 3)[op]
    d0, d1 = depth[lab == 0].mean(), depth[lab == 1].mean()
    fi = 0 if d0 > d1 else 1
    face_c, edge_c = cen[fi], cen[1 - fi]
    # robust edge colour: pixels of the edge cluster far from the face colour
    ep = px[lab != fi]
    edge_c = np.median(ep, axis=0)
    # per-row face colour
    fmask = np.zeros((h, w), bool)
    fmask[op] = lab == fi
    # "pure" face pixels: closer to face centre than 30 % of the distance to edge
    dist_e = np.linalg.norm(C - edge_c, axis=-1)
    span = np.linalg.norm(face_c - edge_c)
    pure = fmask & (dist_e > 0.6 * span)
    # rows with only a few face pixels (glyph tops / bottoms) are mostly anti-aliased edge:
    # they are filled from the neighbouring rows instead of read (else a white face gets grey
    # first / last stops that render as a grey band -- I6 round 1)
    deep = pure & (cv2.erode(fmask.astype(np.uint8), np.array([[0, 1, 0], [1, 1, 1], [0, 1, 0]], np.uint8)) > 0)
    if deep.sum() >= 0.3 * max(1, pure.sum()):
        pure = deep
    cnt = pure.sum(axis=1)
    ys = np.nonzero(cnt >= max(2, 0.2 * cnt.max()))[0]
    if len(ys) < 2:
        ys = np.nonzero(pure.any(axis=1))[0]
    if len(ys):
        for y in ys:
            rows[y] = np.median(C[y][pure[y]], axis=0)
        # fill rows without pure face pixels by interpolation, then smooth lightly
        for ch in range(3):
            rows[:, ch] = np.interp(np.arange(h), ys, rows[ys, ch])
        if len(ys) > 3:
            k = np.array([0.25, 0.5, 0.25])
            sm = rows.copy()
            for ch in range(3):
                sm[1:-1, ch] = np.convolve(rows[:, ch], k, mode="same")[1:-1]
            rows = sm
    else:
        rows[:] = face_c
    d = rows[:, None, :] - edge_c[None, None, :]
    t = ((C - edge_c) * d).sum(-1) / np.maximum((d * d).sum(-1), 1e-6)
    cov = np.clip(t, 0, 1) * A
    cov[cov < 0.03] = 0
    return Face(cov, rows, edge_c, True)


# ----------------------------------------------------------------------------- style


@dataclass
class Layer:
    width: float                    # outer radius beyond the face contour, output pixels
    color: tuple                    # RGB 0..1
    alpha: float = 1.0


@dataclass
class Shadow:
    dx: float
    dy: float
    width: float                    # radius of the shadow shape beyond the face contour
    color: tuple
    alpha: float = 1.0
    blur: float = 0.0


@dataclass
class Style:
    face_stops: list                # [(t 0..1 over the line's em box, (r,g,b))]
    layers: list = field(default_factory=list)      # inner -> outer
    shadow: Shadow | None = None
    box: tuple = (0, 0, 0, 0)       # face bbox x0,y0,x1,y1 (exclusive) of the Japanese text
    ink: tuple = (0, 0, 0, 0)       # bbox of everything drawn (face+outline+shadow)
    align: str = "center"           # left / center / right
    valign: str = "center"
    lines: list = field(default_factory=list)       # [(y0, y1)] face rows per line
    em: float = 0.0                 # face height of one line (px)
    stroke: float = 0.0             # face stroke thickness (px)
    size: tuple = (0, 0)            # image w, h
    plate: bool = False             # opaque background behind the text
    gradient_per_line: bool = True
    notes: list = field(default_factory=list)

    def to_json(self) -> dict:
        d = asdict(self)
        return json.loads(json.dumps(d, default=float))

    @staticmethod
    def from_json(d: dict) -> "Style":
        d = dict(d)
        d["layers"] = [Layer(**l) for l in d.get("layers", [])]
        d["shadow"] = Shadow(**d["shadow"]) if d.get("shadow") else None
        d["face_stops"] = [(t, tuple(c)) for t, c in d["face_stops"]]
        for k in ("box", "ink", "size"):
            d[k] = tuple(d[k])
        d["lines"] = [tuple(l) for l in d.get("lines", [])]
        return Style(**d)

    def extent(self) -> float:
        """How far drawing reaches outside the face contour (px): outline / shadow."""
        e = max([l.width for l in self.layers] + [0.0])
        if self.shadow:
            s = self.shadow
            e = max(e, s.width + max(abs(s.dx), abs(s.dy)) + s.blur)
        return e


def _bbox(mask: np.ndarray):
    ys, xs = np.nonzero(mask)
    if not len(ys):
        return (0, 0, 0, 0)
    return (int(xs.min()), int(ys.min()), int(xs.max()) + 1, int(ys.max()) + 1)


def line_bands(cov: np.ndarray, n: int | None = None, thr: float = 0.3) -> list[tuple[int, int]]:
    """Row bands of ink; with n, merge across the smallest gaps until n bands remain; without,
    bands shorter than 35 % of the tallest are merged into their nearest neighbour."""
    prof = cov.sum(axis=1)
    on = prof > thr
    bands, y = [], 0
    h = len(prof)
    while y < h:
        if on[y]:
            y0 = y
            while y < h and on[y]:
                y += 1
            bands.append([y0, y])
        else:
            y += 1
    if not bands:
        return []

    def merge_smallest_gap():
        gi = min(range(len(bands) - 1), key=lambda i: bands[i + 1][0] - bands[i][1])
        bands[gi][1] = bands[gi + 1][1]
        del bands[gi + 1]

    if n is not None:
        while len(bands) > n:
            merge_smallest_gap()
        while len(bands) < n:
            # lines that touch: split the tallest band at its thinnest row near the middle
            i = max(range(len(bands)), key=lambda j: bands[j][1] - bands[j][0])
            y0, y1 = bands[i]
            lo, hi = y0 + int((y1 - y0) * 0.3), y0 + int(math.ceil((y1 - y0) * 0.7))
            if hi <= lo + 1:
                break
            ys = np.arange(lo, hi)
            y = int(ys[np.argmin(prof[lo:hi] + 1e-3 * np.abs(ys - (y0 + y1) / 2))])
            bands[i:i + 1] = [[y0, y], [y + 1, y1]] if prof[y] > thr else [[y0, y], [y, y1]]
    else:
        changed = True
        while changed and len(bands) > 1:
            changed = False
            tall = max(b[1] - b[0] for b in bands)
            for i, b in enumerate(bands):
                if b[1] - b[0] < 0.35 * tall:
                    j = i - 1 if i == len(bands) - 1 else i + 1 if i == 0 else \
                        (i - 1 if b[0] - bands[i - 1][1] <= bands[i + 1][0] - b[1] else i + 1)
                    lo, hi = min(i, j), max(i, j)
                    bands[lo] = [bands[lo][0], bands[hi][1]]
                    del bands[hi]
                    changed = True
                    break
            # gaps of 0-1 rows between tall bands inside one text line are not line breaks
            for i in range(len(bands) - 1):
                if bands[i + 1][0] - bands[i][1] <= 1 and not changed:
                    tall = max(b[1] - b[0] for b in bands)
                    if (bands[i][1] - bands[i][0]) + (bands[i + 1][1] - bands[i + 1][0]) < 1.3 * tall:
                        bands[i][1] = bands[i + 1][1]
                        del bands[i + 1]
                        changed = True
                        break
    return [tuple(b) for b in bands]


def _stops_from_rows(rows: np.ndarray, y0: int, y1: int, n: int = 7) -> list:
    out = []
    for i in range(n):
        t = i / (n - 1)
        y = y0 + t * (y1 - 1 - y0)
        a, b = int(math.floor(y)), min(int(math.floor(y)) + 1, len(rows) - 1)
        fr = y - a
        c = rows[a] * (1 - fr) + rows[b] * fr
        out.append((round(t, 4), tuple(round(float(v), 4) for v in c)))
    return out


def measure_style(rgba: np.ndarray, *, plate: bool | None = None, text_mask: np.ndarray | None = None,
                  lines: int | None = None) -> Style:
    """Measure the decoration of a Japanese text image (see module doc). `plate` forces plate
    mode (opaque background; the text is found by erase_text); `lines` forces the line count."""
    h, w = rgba.shape[:2]
    A = rgba[..., 3]
    notes = []
    if plate is None:
        plate = (A > 0.9).mean() > 0.6
    work = rgba
    if plate:
        bg, tm = erase_text(rgba, return_mask=True, mask=text_mask)
        diff = np.linalg.norm(rgba[..., :3] - bg[..., :3], axis=-1)
        ta = np.clip(diff / max(0.25, float(np.percentile(diff[tm], 90)) if tm.any() else 0.25), 0, 1) * tm
        work = rgba.copy()
        work[..., 3] = ta
        notes.append("plate: text alpha = colour distance from the restored plate")
    fc = face_coverage(work)
    cov = fc.cov
    A = work[..., 3]
    bands = line_bands(cov, lines)
    if not bands:
        return Style(face_stops=[(0.0, (1, 1, 1)), (1.0, (1, 1, 1))], size=(w, h), plate=plate,
                     notes=["no text found"])
    box = _bbox(cov > 0.3)
    em = float(np.median([b[1] - b[0] for b in bands]))
    stops = _stops_from_rows(fc.rows, bands[0][0], bands[0][1])
    # --- outline / shadow fit on the alpha of everything that is not face
    f = SS
    big = upsample(cov, f)
    d = sdf(big) / f                                   # native-pixel distance from face contour
    d = downsample(d, f) if False else cv2.resize(d, (w, h), interpolation=cv2.INTER_AREA)
    obs = A
    best = None
    rs = [x * 0.25 for x in range(0, 21)]
    base_cache = {}
    for r in rs:
        base_cache[r] = cov_from_sdf(d, r)
    for r in rs:
        m0 = np.maximum(base_cache[r], cov)
        err0 = float(np.abs(obs - m0).mean())
        if best is None or err0 < best[0]:
            best = (err0, r, None)
    r_o = best[1]
    err_ns = best[0]
    # shadow search: shifted copy of an outlined shape
    sh_best = None
    for r2 in [x * 0.25 for x in range(0, 17)]:
        for dy in [x * 0.5 for x in range(-4, 9)]:
            for dx in [x * 0.5 for x in range(-6, 9)]:
                if dx == 0 and dy == 0:
                    continue
                s = shift(base_cache[r2], dx, dy)
                for rr in (r_o, max(0.0, r_o - 0.25), max(0.0, r_o - 0.5), r_o + 0.25):
                    m = np.maximum(np.maximum(base_cache.get(rr, cov_from_sdf(d, rr)), cov), s)
                    e = float(np.abs(obs - m).mean())
                    if sh_best is None or e < sh_best[0]:
                        sh_best = (e, dx, dy, r2, rr)
    shadow = None
    if sh_best and sh_best[0] < err_ns * 0.8 and sh_best[0] < err_ns - 0.004:
        _, dx, dy, r2, r_o = sh_best
        shadow = (dx, dy, r2)
    # --- colours of outline bands and shadow
    C = work[..., :3]
    layers = []
    outline_zone = (d > 0.25) & (d <= r_o) & (A > 0.5) & (cov < 0.3)
    shadow_only = np.zeros_like(outline_zone)
    if shadow:
        dx, dy, r2 = shadow
        s = shift(cov_from_sdf(d, r2), dx, dy)
        shadow_only = (s > 0.5) & (d > r_o + 0.5) & (A > 0.1)
    if r_o > 0 and outline_zone.sum() >= 3:
        # split the outline into bands by distance; merge bands of similar colour into layers
        edges = np.arange(0.25, r_o + 0.01, 0.5)
        bcols = []
        for lo in edges:
            z = outline_zone & (d > lo) & (d <= lo + 0.5)
            if z.sum() >= 3:
                bcols.append((lo + 0.5, np.median(C[z], axis=0), float(np.median(A[z]))))
        if not bcols:
            bcols = [(r_o, np.median(C[outline_zone], axis=0), 1.0)]
        cur = [bcols[0]]
        for b in bcols[1:]:
            if np.linalg.norm(b[1] - cur[-1][1]) < 0.2:
                cur[-1] = (b[0], (cur[-1][1] + b[1]) / 2, cur[-1][2])
            else:
                cur.append(b)
        for i, (rad, col, al) in enumerate(cur):
            layers.append(Layer(width=float(rad if i < len(cur) - 1 else r_o),
                                color=tuple(round(float(v), 4) for v in col), alpha=1.0))
    sh = None
    if shadow:
        dx, dy, r2 = shadow
        if shadow_only.sum() >= 2:
            col = np.median(C[shadow_only], axis=0)
            al = float(np.clip(np.percentile(A[shadow_only], 75), 0.2, 1.0))
        else:
            col = np.array(layers[-1].color if layers else (0, 0, 0))
            al = 1.0
        sh = Shadow(dx=dx, dy=dy, width=r2, color=tuple(round(float(v), 4) for v in col), alpha=round(al, 3))
    ink = _bbox(A > 0.15)
    ml, mr = box[0], w - box[2]
    if abs(ml - mr) <= max(2, 0.06 * w):
        align = "center"
    elif ml < mr:
        align = "left"
    else:
        align = "right"
    mt, mb = box[1], h - box[3]
    valign = "center" if abs(mt - mb) <= 2 else ("top" if mt < mb else "bottom")
    st = Style(face_stops=stops, layers=layers, shadow=sh, box=box, ink=ink, align=align, valign=valign,
               lines=bands, em=em, stroke=round(stroke_width(cov), 3), size=(w, h), plate=plate, notes=notes)
    st.notes.append(f"fit error {sh_best[0] if shadow else err_ns:.4f}")
    return st


# ----------------------------------------------------------------------------- erase


def erase_text(rgba: np.ndarray, mask: np.ndarray | None = None, *, return_mask: bool = False,
               grow: int = 1):
    """Remove the text and restore what was behind it.

    Transparent-background images: the text is everything, so the result is fully transparent.
    Plate images (opaque background): the text zone is found as pixels that differ from a large
    median of the image (or given as `mask`), grown by `grow` px, and filled by interpolating the
    plate along rows and columns from the zone's borders (keeps gradients), with cv2 inpainting
    for what that cannot reach. Pixels outside the zone are returned unchanged."""
    h, w = rgba.shape[:2]
    A = rgba[..., 3]
    if mask is None and (A > 0.9).mean() <= 0.6:
        out = rgba.copy()
        out[...] = 0
        return (out, A > 0.02) if return_mask else out
    u8 = to_u8(rgba)
    if mask is None:
        k = max(7, (min(h, w) // 2) | 1)
        med = cv2.medianBlur(u8[..., :3], min(k, 255 if k <= 255 else 255))
        diff = np.abs(u8[..., :3].astype(int) - med.astype(int)).max(-1)
        mask = diff > 40
    mask = mask.astype(np.uint8)
    if grow:
        mask = cv2.dilate(mask, np.ones((2 * grow + 1, 2 * grow + 1), np.uint8))
    m = mask > 0
    out = rgba.copy()
    # row / column linear interpolation from the zone borders
    acc = np.zeros_like(rgba)
    wt = np.zeros((h, w))
    for axis in (0, 1):
        img = rgba if axis == 1 else rgba.transpose(1, 0, 2)
        mm = m if axis == 1 else m.T
        res = np.zeros_like(img)
        ok = np.zeros(mm.shape, bool)
        for i in range(mm.shape[0]):
            row = mm[i]
            if not row.any():
                continue
            good = np.nonzero(~row)[0]
            if len(good) < 2:
                continue
            bad = np.nonzero(row)[0]
            for ch in range(4):
                res[i, bad, ch] = np.interp(bad, good, img[i, good, ch])
            # only trust runs closed on both sides
            ok[i, bad] = (bad > good.min()) & (bad < good.max())
        if axis == 0:
            res, ok = res.transpose(1, 0, 2), ok.T
        acc += res * ok[..., None]
        wt += ok
    fill = acc / np.maximum(wt, 1)[..., None]
    out[m] = fill[m]
    rest = m & (wt == 0)
    if rest.any():
        inp = cv2.inpaint(to_u8(out)[..., :3], rest.astype(np.uint8), 3, cv2.INPAINT_TELEA)
        out[rest, :3] = inp[rest] / 255.0
    return (out, m) if return_mask else out


# ----------------------------------------------------------------------------- render


@dataclass
class Fit:
    hscale: float = 1.0
    tracking: float = 0.0           # extra px between syllables (can be negative)
    overflow: bool = False
    width: float = 0.0              # final text width (px)
    lines: int = 1


def _gradient(stops, n: int) -> np.ndarray:
    ts = np.array([s[0] for s in stops])
    cs = np.array([s[1] for s in stops], dtype=np.float64)
    t = (np.arange(n) + 0.5) / n
    return np.stack([np.interp(t, ts, cs[:, c]) for c in range(3)], axis=-1)


def render(text: str, style: Style, size: tuple | None = None, *, em: float | None = None,
           box: tuple | None = None, align: str | None = None, source: str = "auto",
           weight: float | None = None, hscale: float | None = None, tracking: float | None = None,
           min_hscale: float = 0.8, margin: float | None = None, background: np.ndarray | None = None,
           gradient: str = "line", report: dict | None = None, strict: bool = True,
           gap_min: float | None = None, donors=None, fit_height: bool = True,
           calibrate: bool = True) -> np.ndarray:
    """Draw `text` ('\\n' = line break) with `style`; returns float RGBA (h, w, 4).

    size      (w, h) of the texture; default style.size
    em        Hangul face height in px; default style.em (the Japanese face height)
    box       area (x0,y0,x1,y1) the text is placed in; default = the whole image minus the
              decoration extent (so Korean may be wider than the Japanese was)
    align     left / center / right; default style.align (anchor = Japanese face box)
    source    glyph source: auto | same_word | bank | font | compose | ofl  (see glyph_mask)
    weight    stroke thickness to reach (px); default style.stroke, None-equivalent 0 = keep
    hscale / tracking   force horizontal scale / extra spacing (px); default: fitted
    background  RGBA to draw on (plate images: erase_text() result)
    strict    size rule of IMAGE_TASK.md 1 (no bitmap / bank glyph enlarged > 1.25x); False = off
    gap_min   smallest gap (px) thickening may leave between strokes; default max(1, 0.06 em)
    donors    [(png or RGBA, "text it shows"), ...]: letter shapes cut from these images win
              (e.g. the S of the 3DX STbr_SPEED original for BP -> SP)
    fit_height  when em is not given: shrink em until the Korean ink band is no taller than
              the Japanese one (+4 %); Hangul with 받침 is taller than kana of the same em
    calibrate re-measure the drawn stroke like the Japanese one and correct the growth
    report    dict filled with sources, fit, em, weight change
    """
    import imgtext_bank as B
    w, h = size or style.size
    em_given = em is not None
    em = float(em or style.em or 12)
    ext = style.extent()
    if margin is None:
        margin = ext + 0.5
    if box is None:
        box = (margin, 0, w - margin, h)
    align = align or style.align
    lines_txt = text.split("\n")
    if weight is None:
        weight = style.stroke
    # --- glyph runs at SS (one source level per line; the weight picks the vector weight)
    extra = None
    if donors:
        extra = {}
        for img, txt in donors:
            for c, g in B.cut_glyphs(img, txt).items():
                extra.setdefault(c, g)

    floor = [source]                 # first source level allowed (raised by the weight check)

    def make_runs(e, src=None):
        rs = [B.glyph_mask(t, e * SS, source=src or floor[0], ss=SS,
                           weight_px=(weight * SS if weight else None),
                           strict=strict, extra=extra) for t in lines_txt]
        lv = [getattr(r, "level", "") for r in rs]
        if len(set(lv)) > 1 and all(x in B.LEVELS for x in lv):
            # one letter source for the whole texture: the latest level any line needed
            worst = max(lv, key=B.LEVELS.index)
            rs = [B.glyph_mask(t, e * SS, source=worst, ss=SS, weight_px=(weight * SS if weight else None),
                               strict=strict, extra=extra) for t in lines_txt]
        return rs

    def plan_weight(rs):
        # the glyph stroke is measured like the Japanese one: on the texture-size image
        # (a hi-res measure of a bitmap glyph reads thicker and made thin text thinner still)
        gs = float(np.median([_native_stroke(r) * SS for r in rs if r.stroke] or [0.0]))
        wd = 0.0
        if weight and gs:
            lo = -0.12 if all(getattr(r, "native", False) for r in rs) else -0.25
            wd = float(np.clip((weight * SS - gs) / 2.0, lo * gs, 0.5 * gs))
        return gs, wd

    def ink_band(rs, wd):
        return max(_ink_rows(r.raster()) for r in rs) / SS + 2 * max(wd, 0.0) / SS

    runs = make_runs(em)
    gstroke, wdelta = plan_weight(runs)
    if weight and source == "auto":
        # a bitmap / image glyph much heavier than the Japanese cannot be thinned without
        # breaking its 1-px strokes (I3-2: 보통 on a thin navy label): take the next source
        lv = getattr(runs[0], "level", "ofl")
        while gstroke > weight * SS * 1.3 and lv in B.LEVELS[:-1]:
            floor[0] = B.LEVELS[B.LEVELS.index(lv) + 1]
            runs = make_runs(em)
            gstroke, wdelta = plan_weight(runs)
            lv = getattr(runs[0], "level", "ofl")
    jp_band = float(np.median([b - a for a, b in style.lines])) if style.lines else em
    snapped = all(getattr(r, "native", False) for r in runs)    # donors / bitmap at own size
    if not em_given and not snapped:
        # bitmap glyphs close to their own size: draw them at exactly that size, on the pixel
        # grid, so their 1-px counters land on whole pixels instead of two grey half rows
        fns = {getattr(r, "font_name", None) for r in runs}
        if len(fns) == 1 and None not in fns and hscale in (None, 1.0):
            fe = B.bitmap_font(fns.pop()).em
            if 0.87 <= fe / em <= 1.15:
                r2 = make_runs(fe, runs[0].level)
                g2, w2 = plan_weight(r2)
                if all(getattr(r, "font_name", None) for r in r2) and \
                        (not fit_height or ink_band(r2, w2) <= jp_band * 1.12):
                    em, runs, gstroke, wdelta, snapped = fe, r2, g2, w2, True
        if fit_height and not snapped and style.lines:
            # the finished face (after thickening) should be about as tall as the Japanese face
            ink = ink_band(runs, wdelta) - 2 * max(wdelta, 0.0) / SS
            grow_px = 2 * max(wdelta, 0.0) / SS
            # Hangul reads smaller than kana of the same ink height: allow 8 % (at least half a
            # pixel of anti-aliasing) before shrinking
            tgt = max(jp_band + 0.5, jp_band * 1.08)
            if ink + grow_px > tgt and ink > 0:
                em = em * max(0.6, (tgt - grow_px) / ink)
                runs = make_runs(em)
                gstroke, wdelta = plan_weight(runs)
    if gap_min is None:
        snapped = snapped or all(getattr(r, "native", False) for r in runs)
        gap_min = 1.0 if snapped else max(1.0, min(1.5, 0.08 * em))
    else:
        snapped = snapped or all(getattr(r, "native", False) for r in runs)
    # --- fit width
    avail = (box[2] - box[0]) * SS
    fit = Fit(lines=len(runs))
    nat = max(r.width(0.0) for r in runs)
    grow = 2 * max(wdelta, 0)
    if hscale is None:
        hs = 1.0
        if nat + grow > avail:
            hs = max(min_hscale, avail / (nat + grow))
    else:
        hs = hscale
    tr = 0.0 if tracking is None else tracking * SS
    if tracking is None:
        for r in runs:
            if r.width(0.0) * hs + grow > avail and r.gaps() > 0:
                need = (r.width(0.0) * hs + grow - avail) / r.gaps()
                tr = min(tr, -need)
        tr = max(tr, -0.12 * em * SS)
    fit.hscale, fit.tracking = hs, tr / SS
    # --- rasterise lines into one SS canvas
    W, H = w * SS, h * SS
    face = np.zeros((H, W), np.float32)
    jl = style.lines or [(style.box[1], style.box[3])]
    # line pitch: Japanese pitch when it had as many lines, else em * 1.25
    if len(jl) >= len(runs) and len(runs) > 1:
        centers = [((a + b) / 2.0) for a, b in jl[:len(runs)]]
    else:
        cy = (style.box[1] + style.box[3]) / 2.0 if style.box[3] else h / 2.0
        if style.valign == "center" and len(jl) != len(runs):
            cy = h / 2.0 if abs(cy - h / 2.0) < 2 else cy
        pitch = (jl[1][0] - jl[0][0]) if len(jl) > 1 else em * 1.3
        n = len(runs)
        centers = [cy + (i - (n - 1) / 2.0) * pitch for i in range(n)]
    widths = []
    for r, cyl in zip(runs, centers):
        img = r.raster(hs, tr)                   # (em-box rows, width) at SS, top = em top
        rw = img.shape[1]
        widths.append(rw / SS)
        if rw > avail + 1:
            fit.overflow = True
        if align == "left":
            x0 = (style.box[0] if style.box[2] else box[0]) * SS
            x0 = max(x0, box[0] * SS)
        elif align == "right":
            x1 = (style.box[2] if style.box[2] else box[2]) * SS
            x1 = min(x1, box[2] * SS)
            x0 = x1 - rw
        else:
            cx = ((style.box[0] + style.box[2]) / 2.0 if style.box[2] else w / 2.0)
            if abs(cx - w / 2.0) <= 1.5:
                cx = w / 2.0
            x0 = cx * SS - rw / 2.0
            x0 = min(max(x0, box[0] * SS), box[2] * SS - rw)
        # centre the run's INK band on the Japanese line centre (Hangul with 받침 hangs lower
        # than the em box)
        iy = np.nonzero(img.max(axis=1) >= 0.5)[0]
        ic = (iy.min() + iy.max() + 1) / 2.0 if len(iy) else img.shape[0] / 2.0
        xi, yi = int(round(x0)), int(round(cyl * SS - ic))
        if snapped and hs == 1.0:
            xi = int(round(xi / SS)) * SS
        yi = int(round(yi / SS)) * SS           # line on the pixel grid: crisp top / bottom rows
        _paste_max(face, img, xi, yi)
    fit.width = max(widths)
    # --- weight change: thicken with counters kept open, or thin via the distance field
    # the target is measured on the Japanese texture at its own size, so the result is measured
    # the same way and the growth corrected (up to 3 rounds, stop within 4 %)
    face0 = face
    for _ in range(3):
        if wdelta > 0:
            face = thicken(face0, wdelta, gap_min * SS)
            d = sdf(face)
        else:
            d = sdf(face0) - wdelta               # SS px
        if not weight or not calibrate:
            break
        ach = stroke_width(downsample(cov_from_sdf(d, 0.0), SS))
        if not ach or abs(ach / weight - 1) < 0.04:
            break
        wdelta = float(np.clip(wdelta + (weight - ach) * SS / 2.0 * 0.9,
                               (-0.12 if snapped else -0.3) * gstroke, 0.7 * gstroke))
    fcov = cov_from_sdf(d, 0.0)
    out = np.zeros((H, W, 4), np.float64)
    if background is not None:
        bg = cv2.resize(background, (W, H), interpolation=cv2.INTER_NEAREST).astype(np.float64)
        out[:] = bg
    # colour of each layer is composited premultiplied, bottom -> top
    prem = np.zeros((H, W, 3))
    alpha = np.zeros((H, W))
    if background is not None:
        alpha = out[..., 3].copy()
        prem = out[..., :3] * alpha[..., None]

    def over(cov, col):
        nonlocal prem, alpha
        col = np.broadcast_to(np.asarray(col, np.float64), prem.shape) if np.ndim(col) == 1 else col
        prem = col * cov[..., None] + prem * (1 - cov[..., None])
        alpha = cov + alpha * (1 - cov)

    if style.shadow:
        s = style.shadow
        sc = cov_from_sdf(d, s.width * SS)
        sc = shift(sc, s.dx * SS, s.dy * SS)
        if s.blur:
            k = max(3, int(s.blur * SS * 2) | 1)
            sc = cv2.GaussianBlur(sc, (k, k), s.blur * SS)
        over(sc * s.alpha, s.color)
    for lay in reversed(style.layers):
        over(cov_from_sdf(d, lay.width * SS) * lay.alpha, lay.color)
    # face gradient over each line's em box
    ts = np.array([s[0] for s in style.face_stops])
    cs = np.array([s[1] for s in style.face_stops], dtype=np.float64)
    ys = np.arange(H) + 0.5
    tt = np.zeros(H)
    if gradient == "line":
        tops = np.array([cyl * SS - r.em_h / 2.0 for r, cyl in zip(runs, centers)])
        hts = np.array([r.em_h for r in runs])
        mids = tops + hts / 2
        idx = np.argmin(np.abs(ys[:, None] - mids[None, :]), axis=1)
        tt = np.clip((ys - tops[idx]) / hts[idx], 0, 1)
    else:
        tt[:] = 0.5
    grow_rows = np.stack([np.interp(tt, ts, cs[:, c]) for c in range(3)], axis=-1)
    grad = np.broadcast_to(grow_rows[:, None, :], (H, W, 3))
    over(fcov, grad)
    res = np.zeros((h, w, 4))
    a = downsample(alpha, SS)
    p = downsample(prem, SS)
    res[..., 3] = a
    res[..., :3] = np.where(a[..., None] > 1e-6, p / np.maximum(a[..., None], 1e-6), 0)
    if report is not None:
        achieved = stroke_width(downsample(fcov, SS)) if fcov.max() > 0.5 else 0.0
        report.update({"sources": [r.sources for r in runs], "levels": [getattr(r, "level", "") for r in runs],
                       "fit": asdict(fit), "em": em,
                       "weight_delta_px": round(wdelta / SS, 3), "glyph_stroke_px": round(gstroke / SS, 3),
                       "weight": {"target_px": round(float(weight or 0), 3), "glyph_px": round(gstroke / SS, 3),
                                  "achieved_px": round(achieved, 3),
                                  "ratio": round(achieved / weight, 3) if weight else None}})
    return res


def thicken(face: np.ndarray, r: float, gap_min: float) -> np.ndarray:
    """Grow a soft mask by r px (its own grid) but never let a gap between strokes shrink below
    gap_min px: in a gap of half-width g the growth is limited to g - gap_min/2, so ㄹ, ㅌ,
    ㅁ counters and the space between 받침 and vowel stay open while open outlines get the full
    growth. The local half-width of the background is found by openings with discs of
    growing radius (local thickness)."""
    m = np.asarray(face, np.float32)
    inside = (m >= 0.5).astype(np.uint8)
    if r <= 0 or not inside.any():
        return m
    d = sdf(m)                                   # <0 inside, >0 outside
    bg = (1 - inside)
    thick = np.zeros(m.shape, np.float32)       # local half-width of the background
    step = 0.5
    rad = step
    rmax = r + gap_min / 2 + 1.0
    while rad <= rmax + 1e-6:
        k = int(math.ceil(rad))
        disk = cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (2 * k + 1, 2 * k + 1))
        if rad < k:
            yy, xx = np.mgrid[-k:k + 1, -k:k + 1]
            disk = ((xx * xx + yy * yy) <= rad * rad + 0.25).astype(np.uint8)
        op = cv2.morphologyEx(bg, cv2.MORPH_OPEN, disk, borderType=cv2.BORDER_CONSTANT, borderValue=1)
        thick[op > 0] = rad
        rad += step
    thick[(bg > 0) & (thick >= rmax)] = 1e4       # open space
    allow = np.minimum(r, np.maximum(0.0, thick - gap_min / 2.0))
    # smooth the allowance a little so the edge is not stair-stepped
    allow = cv2.GaussianBlur(allow.astype(np.float32), (0, 0), 0.7)
    allow = np.minimum(allow, r)
    grown = np.clip(allow - d + 0.5, 0.0, 1.0)
    return np.maximum(m, np.where(inside > 0, 1.0, grown)).astype(np.float32)


def _ink_rows(img: np.ndarray) -> float:
    ys = np.nonzero(img.max(axis=1) >= 0.5)[0]
    return float(ys.max() + 1 - ys.min()) if len(ys) else 0.0


def _native_stroke(run) -> float:
    """Stroke of a glyph run measured at texture size (same method as measure_style)."""
    img = run.raster()
    h, w = img.shape
    H, W = -(-h // SS) * SS, -(-w // SS) * SS
    img = np.pad(img, ((0, H - h), (0, W - w)))
    return stroke_width(downsample(img, SS))


def _paste_max(dst: np.ndarray, src: np.ndarray, x: int, y: int) -> None:
    H, W = dst.shape
    h, w = src.shape
    xa, ya = max(0, x), max(0, y)
    xb, yb = min(W, x + w), min(H, y + h)
    if xb <= xa or yb <= ya:
        return
    dst[ya:yb, xa:xb] = np.maximum(dst[ya:yb, xa:xb], src[ya - y:yb - y, xa - x:xb - x])


# ----------------------------------------------------------------------------- formats


def finalize(rgba: np.ndarray, fmt: str) -> np.ndarray:
    """Quantise like the texture format (what the game will show). Grey formats keep luminance
    only. ETC1 / ETC1A4 go through the real encoder and decoder (libtex3ds)."""
    x = np.clip(rgba, 0, 1).copy()
    q = lambda v, bits: np.rint(v * (2 ** bits - 1)) / (2 ** bits - 1)
    if fmt in ("LA4", "LA8", "L4", "L8", "A4", "A8"):
        L = luminance(x[..., :3])
        bits = 4 if fmt.endswith("4") else 8
        if fmt.startswith("A"):
            L = np.ones_like(L)
        elif fmt.startswith("L") and fmt[1] != "A":
            x[..., 3] = 1.0
        x[..., :3] = q(L, bits)[..., None]
        if fmt[:2] == "LA" or fmt[0] == "A":
            x[..., 3] = q(x[..., 3], bits)
        return x
    if fmt == "RGBA4":
        return q(x, 4)
    if fmt == "RGBA5551":
        x[..., :3] = q(x[..., :3], 5)
        x[..., 3] = (x[..., 3] >= 0.5).astype(float)
        return x
    if fmt == "RGB565":
        x[..., 0], x[..., 1], x[..., 2] = q(x[..., 0], 5), q(x[..., 1], 6), q(x[..., 2], 5)
        x[..., 3] = 1.0
        return x
    if fmt in ("RGB8", "RGBA8"):
        x = q(x, 8)
        if fmt == "RGB8":
            x[..., 3] = 1.0
        return x
    if fmt in ("ETC1", "ETC1A4"):
        sys.path.insert(0, str(ROOT / "scripts"))
        import libtex3ds as X
        h, w = x.shape[:2]
        H, W = -(-h // 8) * 8, -(-w // 8) * 8
        u = np.pad(to_u8(x), ((0, H - h), (0, W - w), (0, 0)), mode="edge")
        # colour of fully transparent pixels does not matter; use the nearest ink colour so the
        # ETC blocks are not polluted by black
        dec = X.decode(X.encode(u, fmt), fmt, W, H)[:h, :w].astype(np.float64) / 255.0
        if fmt == "ETC1":
            dec[..., 3] = 1.0
        return dec
    raise ValueError(f"unknown format {fmt}")


def bleed(rgba: np.ndarray, iters: int = 6) -> np.ndarray:
    """Give fully transparent pixels the colour of their nearest visible neighbour (alpha kept),
    as the original textures do; keeps ETC blocks and bilinear filtering from darkening edges."""
    x = rgba.copy()
    a = x[..., 3] > 0.02
    col = x[..., :3].copy()
    known = a.copy()
    k = np.ones((3, 3), np.float32)
    for _ in range(iters):
        if known.all():
            break
        s = cv2.filter2D((col * known[..., None]).astype(np.float32), -1, k, borderType=cv2.BORDER_CONSTANT)
        n = cv2.filter2D(known.astype(np.float32), -1, k, borderType=cv2.BORDER_CONSTANT)
        new = (~known) & (n > 0)
        col[new] = s[new] / n[new][:, None]
        known |= new
    x[..., :3] = np.where(a[..., None], x[..., :3], col)
    return x


# ----------------------------------------------------------------------------- compare


def compare(jp: np.ndarray, ko: np.ndarray, st_jp: Style | None = None) -> dict:
    """Numbers that should match between the Japanese original and the Korean image."""
    a = st_jp or measure_style(jp)
    b = measure_style(ko, plate=a.plate or None, lines=len(a.lines) or None)

    def lay(s, i):
        return s.layers[i] if len(s.layers) > i else None

    out = {
        "em": (a.em, b.em, round(b.em - a.em, 2)),
        "stroke_per_em": (round(a.stroke / max(a.em, 1), 3), round(b.stroke / max(b.em, 1), 3)),
        "face_top": (a.face_stops[0][1], b.face_stops[0][1]),
        "face_bottom": (a.face_stops[-1][1], b.face_stops[-1][1]),
        "layers": ([(l.width, l.color) for l in a.layers], [(l.width, l.color) for l in b.layers]),
        "shadow": (asdict(a.shadow) if a.shadow else None, asdict(b.shadow) if b.shadow else None),
        "align": (a.align, b.align),
        "box": (a.box, b.box),
        "lines": (len(a.lines), len(b.lines)),
    }
    fd = float(np.abs(np.array(out["face_top"][0]) - np.array(out["face_top"][1])).max() +
               np.abs(np.array(out["face_bottom"][0]) - np.array(out["face_bottom"][1])).max()) / 2
    ow = [abs(la.width - lb.width) for la, lb in zip(a.layers, b.layers)]
    oc = [float(np.abs(np.array(la.color) - np.array(lb.color)).max()) for la, lb in zip(a.layers, b.layers)]
    sd = None
    if a.shadow and b.shadow:
        sd = math.hypot(a.shadow.dx - b.shadow.dx, a.shadow.dy - b.shadow.dy)
    out["summary"] = {
        "em_ratio": round(b.em / max(a.em, 1e-6), 3),
        "stroke_ratio": round((b.stroke / max(b.em, 1)) / max(a.stroke / max(a.em, 1), 1e-6), 3),
        "face_color_diff": round(fd, 3),
        "outline_width_diff": round(max(ow), 3) if ow else (0.0 if not a.layers and not b.layers else None),
        "outline_color_diff": round(max(oc), 3) if oc else None,
        "layer_count": (len(a.layers), len(b.layers)),
        "shadow_offset_diff": round(sd, 3) if sd is not None else (0.0 if not a.shadow and not b.shadow else None),
    }
    return out


def verdict(cmp: dict) -> list[str]:
    """Human-readable problems in a compare() result (empty = within tolerance)."""
    s = cmp["summary"]
    bad = []
    if not 0.88 <= s["em_ratio"] <= 1.12:
        bad.append(f"글자 높이 비 {s['em_ratio']}")
    if not 0.8 <= s["stroke_ratio"] <= 1.25:
        bad.append(f"획 두께 비 {s['stroke_ratio']}")
    if s["face_color_diff"] > 0.12:
        bad.append(f"채움색 차 {s['face_color_diff']}")
    if s["layer_count"][0] != s["layer_count"][1]:
        bad.append(f"테두리 겹 수 {s['layer_count']}")
    if s["outline_width_diff"] is None or s["outline_width_diff"] > 0.6:
        bad.append(f"테두리 두께 차 {s['outline_width_diff']}")
    if s["outline_color_diff"] is not None and s["outline_color_diff"] > 0.2:
        bad.append(f"테두리 색 차 {s['outline_color_diff']}")
    if s["shadow_offset_diff"] is None or s["shadow_offset_diff"] > 0.8:
        bad.append(f"그림자 위치 차 {s['shadow_offset_diff']}")
    return bad


# ----------------------------------------------------------------------------- one call


def redraw(jp, text: str, fmt: str | None = None, style: Style | None = None, **kw):
    """Measure the Japanese image, draw `text` in its style, quantise for `fmt`.
    jp = path or RGBA array. Returns (rgba float, report dict). Keyword arguments go to render()
    (em, box, align, source, weight, hscale, tracking, ...) or measure_style (plate=, lines=)."""
    path = None
    if not isinstance(jp, np.ndarray):
        path = jp
        jp = load_png(jp)
        if fmt is None:
            ti = texinfo(path)
            fmt = ti["fmt"] if ti else None
    mkw = {k: kw.pop(k) for k in ("plate", "lines", "text_mask") if k in kw}
    jp_text = kw.pop("jp_text", None)
    st = style or measure_style(jp, **mkw)
    n_ko = text.count("\n") + 1
    if style is None and "lines" not in mkw and n_ko > 1 and len(st.lines) != n_ko:
        # Japanese lines that touch are found as one band: split them into as many lines as
        # the Korean text has; if the Japanese really was one line, fit n lines into its box
        st2 = measure_style(jp, lines=n_ko, **mkw)
        hs = [b - a for a, b in st2.lines]
        if len(hs) == n_ko and min(hs) >= 0.6 * max(hs):
            st = st2
        elif "em" not in kw and st.lines:
            a, b = st.lines[0][0], st.lines[-1][1]
            kw["em"] = max(6.0, min(st.em, (b - a) / (n_ko * 1.15)))
    if jp_text and "donors" not in kw and any(c.isascii() and c.isalnum() for c in jp_text):
        # Latin kept from the Japanese original (NEW DATA -> NEW GAME): its own letter shapes
        kw["donors"] = [(jp, jp_text)]
    rep = {"style": st.to_json(), "fmt": fmt}
    bg = None
    if st.plate:
        bg = erase_text(jp, mask=mkw.get("text_mask"))
        kw.setdefault("background", bg)
    ko = render(text, st, report=rep, **kw)
    if st.plate and bg is not None:
        # keep untouched plate pixels byte-exact
        pass
    ko = bleed(ko)
    if fmt:
        ko = finalize(ko, fmt)
    rep["compare"] = compare(jp, ko, st)
    rep["problems"] = verdict(rep["compare"])
    return ko, rep


# ----------------------------------------------------------------------------- review sheets


def _on_bg(rgba: np.ndarray, bg=(0.23, 0.47, 0.78)) -> np.ndarray:
    a = rgba[..., 3:4]
    return rgba[..., :3] * a + np.asarray(bg) * (1 - a)


def _checker(h, w, s=4):
    y, x = np.mgrid[0:h, 0:w]
    c = ((x // s + y // s) % 2).astype(float)
    return (0.55 + 0.12 * c)[..., None].repeat(3, -1)


def make_sheet(rows, path, zoom: int = 3, label_font=None) -> None:
    """Review sheet: each row = (label, [rgba, rgba, ...]); every image is shown at 1x on a
    checkerboard and at `zoom`x on blue and on dark grey."""
    from PIL import ImageDraw, ImageFont
    font = None
    for cand in (ROOT / "fonts/NotoSansKR-Medium.otf", ROOT / "fonts/NanumSquareRoundB.ttf"):
        if cand.exists():
            font = ImageFont.truetype(str(cand), 13)
            break
    blocks = []
    for label, imgs in rows:
        tiles = []
        for im in imgs:
            h, w = im.shape[:2]
            one = im[..., :3] * im[..., 3:4] + _checker(h, w) * (1 - im[..., 3:4])
            z1 = cv2.resize(_on_bg(im), (w * zoom, h * zoom), interpolation=cv2.INTER_NEAREST)
            z2 = cv2.resize(_on_bg(im, (0.16, 0.16, 0.16)), (w * zoom, h * zoom), interpolation=cv2.INTER_NEAREST)
            tile = np.ones((h + 4 + 2 * h * zoom + 4, max(w, w * zoom), 3)) * 0.12
            tile[:h, :w] = one
            tile[h + 4:h + 4 + h * zoom, :w * zoom] = z1
            tile[h + 8 + h * zoom:h + 8 + 2 * h * zoom, :w * zoom] = z2
            tiles.append(tile)
        th = max(t.shape[0] for t in tiles)
        tw = sum(t.shape[1] for t in tiles) + 12 * (len(tiles) - 1)
        blk = np.ones((th + 20, max(tw, 300), 3)) * 0.12
        x = 0
        for t in tiles:
            blk[20:20 + t.shape[0], x:x + t.shape[1]] = t
            x += t.shape[1] + 12
        pil = Image.fromarray(to_u8(blk))
        ImageDraw.Draw(pil).text((2, 2), label, fill=(255, 230, 120), font=font)
        blocks.append(np.asarray(pil, np.float64) / 255)
    return save_tiled([Image.fromarray(to_u8(b)) for b in blocks], path)


MAX_SHEET = 1600            # review images must stay <= 1600 px on each side (IMAGE_TASK.md 3)


def save_tiled(blocks, path, max_px: int = MAX_SHEET, gap: int = 8) -> list[Path]:
    """Stack PIL images vertically into sheets of at most max_px x max_px. A block wider or taller
    than max_px is shrunk to fit. One sheet -> `path`; more -> path_01.png, path_02.png, ...
    Returns the written paths."""
    fixed = []
    for b in blocks:
        if b.width > max_px or b.height > max_px:
            f = max_px / max(b.width, b.height)
            b = b.resize((max(1, int(b.width * f)), max(1, int(b.height * f))), Image.NEAREST)
        fixed.append(b.convert("RGB"))
    pages, cur, h = [], [], 0
    for b in fixed:
        if cur and h + b.height > max_px:
            pages.append(cur)
            cur, h = [], 0
        cur.append(b)
        h += b.height + gap
    if cur:
        pages.append(cur)
    path = Path(path)
    path.parent.mkdir(parents=True, exist_ok=True)
    out = []
    for i, pg in enumerate(pages):
        W = max(b.width for b in pg)
        H = sum(b.height for b in pg) + gap * (len(pg) - 1)
        sheet = Image.new("RGB", (W, H), (31, 31, 31))
        y = 0
        for b in pg:
            sheet.paste(b, (0, y))
            y += b.height + gap
        p = path if len(pages) == 1 else path.with_name(f"{path.stem}_{i + 1:02d}{path.suffix}")
        sheet.save(p)
        out.append(p)
    return out


# ----------------------------------------------------------------------------- cli


def _cli() -> None:
    import argparse
    sys.path.insert(0, str(ROOT / "scripts"))
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    sub = ap.add_subparsers(dest="cmd", required=True)
    m = sub.add_parser("measure")
    m.add_argument("png")
    m.add_argument("--out")
    r = sub.add_parser("render")
    r.add_argument("png")
    r.add_argument("text")
    r.add_argument("out")
    r.add_argument("--fmt")
    r.add_argument("--source", default="auto")
    r.add_argument("--em", type=float)
    r.add_argument("--align")
    r.add_argument("--sheet")
    r.add_argument("--report")
    sub.add_parser("bank")
    sub.add_parser("selftest")
    a = ap.parse_args()
    if a.cmd == "measure":
        st = measure_style(load_png(a.png))
        s = json.dumps(st.to_json(), ensure_ascii=False, indent=1)
        (Path(a.out).write_text(s, encoding="utf-8") if a.out else print(s))
    elif a.cmd == "render":
        kw = {"source": a.source}
        if a.em:
            kw["em"] = a.em
        if a.align:
            kw["align"] = a.align
        ko, rep = redraw(a.png, a.text.replace("\\n", "\n"), fmt=a.fmt, **kw)
        save_png(ko, a.out)
        if a.sheet:
            make_sheet([(f"{Path(a.png).stem} -> {a.text}", [load_png(a.png), ko])], a.sheet)
        s = json.dumps({k: v for k, v in rep.items() if k != "style"}, ensure_ascii=False, indent=1, default=str)
        (Path(a.report).write_text(s, encoding="utf-8") if a.report else print(s))
    elif a.cmd == "bank":
        import imgtext_bank as B
        B.build_bank()
    elif a.cmd == "selftest":
        import imgtext_bank as B
        B.selftest()


if __name__ == "__main__":
    sys.path.insert(0, str(ROOT / "scripts"))
    _cli()
