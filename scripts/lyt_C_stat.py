"""C group: stat_en pixel-font labels (BP->SP, HIGE->SUYEOM, TSUNO->PPUL, GDD->GDH).

Two 3DX label sets use their own pixel fonts:
  * STbr  (60x16 LA4, battle result): white face, grey bevel row, black outline + shadow.
  * ST    (42x12 LA4, menus / Bowser Jr.): white letters, alpha only.
Letters are taken from the 3DX originals of the same set; missing letters (Y, M, L) are drawn on
the same grid. For STbr the decoration is re-applied with a neighbourhood lookup learned from the
seven originals (key = face bits in a 7x7 window -> exact LA4 pixel value), validated by
reproducing the originals from their own face masks.

    python scripts/lyt_C_stat.py letters   -> work/img/C_tmp/letters.txt (ASCII of every letter)
    python scripts/lyt_C_stat.py selftest  -> reproduction error of the originals
    python scripts/lyt_C_stat.py build     -> work/img/ko/lyt/... PNGs (temp name, then rename)
"""
from __future__ import annotations

import json
import os
import sys
from pathlib import Path

import numpy as np
from PIL import Image

ROOT = Path(__file__).resolve().parent.parent
L3 = ROOT / "work/img/lyt/3DX"
KO = ROOT / "work/img/ko/lyt"
TMP = ROOT / "work/img/C_tmp"
TMP.mkdir(parents=True, exist_ok=True)

STBR = {w: L3 / "BLyt/btl_RESLT_LYT_JP_ja" / f"STbr_{w}_00_JP_ja.png"
        for w in ("POW", "SPEED", "TSUNO", "BP", "HIGE", "DEF", "HP")}
ST = {"DEF": L3 / "KLyt/KJ_RESULT_JP_ja/KJ_ST_DEF_00_JP_ja.png",
      "SPEED": L3 / "KLyt/KJ_RESULT_JP_ja/KJ_ST_SPEED_00_JP_ja.png",
      "GDD": L3 / "KLyt/KJ_RESULT_JP_ja/KJ_ST_GDD_00_JP_ja.png",
      "HP": L3 / "KLyt/KJ_RESULT_JP_ja/KJ_ST_HP_00_JP_ja.png",
      "POW": L3 / "KLyt/KJ_RESULT_JP_ja/KJ_ST_POW_00_JP_ja.png",
      "BP": L3 / "MLyt/MENU_ITEM_Lyt_JP_ja/ST_BP_00_JP_ja.png",
      "HIGE": L3 / "MLyt/MENU_ITEM_Lyt_JP_ja/ST_HIGE_00_JP_ja.png",
      "TSUNO": L3 / "MLyt/MENU_ITEM_Lyt_JP_ja/ST_TSUNO_00_JP_ja.png"}


def load(p) -> np.ndarray:
    """-> int array (h, w, 2): LA4 levels 0..15 (luminance, alpha)."""
    im = np.asarray(Image.open(p).convert("RGBA")).astype(int)
    lum = (im[..., 0] * 299 + im[..., 1] * 587 + im[..., 2] * 114 + 500) // 1000
    return np.stack([(lum + 8) // 17, (im[..., 3] + 8) // 17], -1)


def save(la: np.ndarray, p: Path) -> None:
    p.parent.mkdir(parents=True, exist_ok=True)
    l = (la[..., 0] * 17).astype(np.uint8)
    a = (la[..., 1] * 17).astype(np.uint8)
    rgba = np.stack([l, l, l, a], -1)
    tmp = p.with_name(p.stem + ".tmp_C.png")
    Image.fromarray(rgba, "RGBA").save(tmp)
    os.replace(tmp, p)


# ----------------------------------------------------------------------------- STbr set

def face_br(la):
    return (la[..., 0] >= 8) & (la[..., 1] >= 8)


def segments(mask):
    cols = mask.any(0)
    segs, x = [], 0
    while x < len(cols):
        if cols[x]:
            x0 = x
            while x < len(cols) and cols[x]:
                x += 1
            segs.append((x0, x))
        else:
            x += 1
    return segs


def letters_of(word, mask):
    segs = segments(mask)
    if len(segs) != len(word):
        raise ValueError(f"{word}: {len(segs)} segments {segs}")
    return {ch: (x0, x1) for ch, (x0, x1) in zip(word, segs)}, segs


R = 3  # window radius


def keys_of(face):
    h, w = face.shape
    pad = np.pad(face, R)
    ks = np.zeros((h, w, (2 * R + 1) ** 2), bool)
    i = 0
    for dy in range(-R, R + 1):
        for dx in range(-R, R + 1):
            ks[..., i] = pad[R + dy:R + dy + h, R + dx:R + dx + w]
            i += 1
    return ks


_W = None


def weights():
    global _W
    if _W is None:
        w = []
        for dy in range(-R, R + 1):
            for dx in range(-R, R + 1):
                w.append(1.0 / (1 + abs(dx) + abs(dy)) ** 2)
        _W = np.array(w)
    return _W


class Model:
    """Neighbourhood lookup: exact 7x7 key -> exact 5x5 key -> nearest weighted 7x7."""

    def __init__(self, imgs, exclude=None, face_fn=None):
        self.face_fn = face_fn or face_br
        K, V = [], []
        for name, la in imgs.items():
            if name == exclude:
                continue
            f = self.face_fn(la)
            k = keys_of(f).reshape(-1, (2 * R + 1) ** 2)
            v = la.reshape(-1, 2)
            K.append(k)
            V.append(v)
        self.K = np.concatenate(K)
        self.V = np.concatenate(V)
        n = 2 * R + 1
        idx5 = [(dy + R) * n + (dx + R) for dy in range(-2, 3) for dx in range(-2, 3)]
        self.idx5 = idx5
        self.tables = []
        for sel in (list(range(n * n)),):
            d = {}
            for kb, v in zip(map(bytes, np.packbits(self.K[:, sel], axis=1)), self.V):
                d.setdefault(kb, []).append(v)
            self.tables.append((sel, {k: np.rint(np.mean(v, 0)).astype(int) for k, v in d.items()}))
        self.miss = 0
        self.miss5 = 0

    def apply(self, face):
        h, w = face.shape
        ks = keys_of(face).reshape(-1, (2 * R + 1) ** 2)
        out = np.zeros((h * w, 2), int)
        W = weights()
        out[:, 0] = 15
        packs = [(sel, tab, np.packbits(ks[:, sel], axis=1)) for sel, tab in self.tables]
        for i, k in enumerate(ks):
            if not k.any():
                continue
            v = None
            for lvl, (sel, tab, pk) in enumerate(packs):
                v = tab.get(bytes(pk[i]))
                if v is not None:
                    break
                if lvl == 0:
                    self.miss += 1
                else:
                    self.miss5 += 1
            if v is None:
                dist = ((self.K != k) * W).sum(1)
                best = dist.min()
                v = np.rint(self.V[dist <= best + 1e-9].mean(0)).astype(int)
            out[i] = v
        return out.reshape(h, w, 2)


def load_br():
    return {n: load(p) for n, p in STBR.items()}


# glyph masks (face) for letters missing from the STbr originals, 8 rows (y4..y11)
def parse(rows):
    return np.array([[c == "#" for c in r] for r in rows], bool)


BR_NEW = {
    "Y": ["###...##",
          "###...##",
          ".###.##.",
          "..#####.",
          "...###..",
          "...##...",
          "...##...",
          "...##..."],
    "M": ["###....###",
          "####..####",
          "##########",
          "##.####.##",
          "##..##..##",
          "##......##",
          "##......##",
          "##......##"],
    "L": ["##.....",
          "##.....",
          "##.....",
          "##.....",
          "##.....",
          "##.....",
          "######.",
          "#######"],
}
BR_CROP = {"S": ("SPEED", 1, 9), "P": ("BP", 10, 18), "U": ("TSUNO", 18, 26),
           "E": ("HIGE", 23, 30), "O": ("TSUNO", 36, 44)}

ST_NEW = {  # 7 rows, y2..y8
    "Y": ["##..##",
          "##..##",
          "######",
          ".####.",
          "..##..",
          "..##..",
          "..##.."],
    "M": ["##...##",
          "###.###",
          "#######",
          "##.#.##",
          "##...##",
          "##...##",
          "##...##"],
    "L": ["##...",
          "##...",
          "##...",
          "##...",
          "##...",
          "#####",
          "#####"],
}
ST_CROP = {"S": ("SPEED", 0, 7), "U": ("TSUNO", 14, 20), "E": ("DEF", 8, 13),
           "O": ("POW", 7, 14), "P": ("BP", 8, 14), "H": ("HP", 1, 7)}


def glyph(ch, setname):
    if setname == "STbr":
        if ch in BR_NEW:
            g = parse(BR_NEW[ch])
            m = np.zeros((16, g.shape[1]), bool)
            m[4:12] = g
            return m
        w, x0, x1 = BR_CROP[ch]
        return face_br(load(STBR[w]))[:, x0:x1]
    if ch in ST_NEW:
        g = parse(ST_NEW[ch])
        m = np.zeros((12, g.shape[1]), bool)
        m[2:9] = g
        return m
    w, x0, x1 = ST_CROP[ch]
    return _trim(face_st(load(ST[w]))[:, x0:x1])


def _trim(m):
    c = np.nonzero(m.any(0))[0]
    return m[:, c.min():c.max() + 1]


def compose(word, setname, start, gap=1, width=None, places=None):
    h, W = (16, 60) if setname == "STbr" else (12, 42)
    face = np.zeros((h, width or W), bool)
    x = start
    for i, ch in enumerate(word):
        g = glyph(ch, setname)
        if places:
            x = places[i]
        face[:, x:x + g.shape[1]] |= g[:, :max(0, min(g.shape[1], face.shape[1] - x))]
        x += g.shape[1] + gap
    return face


def render_word(word, setname, **kw):
    face = compose(word, setname, **kw)
    if setname == "STbr":
        m = Model(load_br(), face_fn=face_br)
    else:
        m = Model(load_st(), face_fn=face_st)
    la = m.apply(face)
    if setname == "ST":
        la[..., 0] = 15
    return la, face, m.miss


def paste_max(dst, src, x):
    w = min(src.shape[1], dst.shape[1] - x)
    d = dst[:, x:x + w]
    take = src[:, :w, 1] > d[..., 1]
    d[take] = src[:, :w][take]
    return dst


def lv(rows):
    """hand-drawn ST letter: rows of hex alpha levels ('.' = 0), placed on rows 2..8 of 12."""
    w = max(len(r) for r in rows)
    a = np.zeros((12, w), int)
    for y, r in enumerate(rows):
        for x, c in enumerate(r):
            a[2 + y, x] = 0 if c == "." else int(c, 16)
    return a


ST_LV_NEW = {
    "Y": lv(["fb..8f4",
             "fb..8f4",
             "df88df4",
             "3cffd83",
             "..fb...",
             "..fb...",
             "..b8..."]),
    "M": lv(["fb...8f4",
             "ffb.8ff4",
             "fbfbfbf4",
             "fb.b.8f4",
             "fb...8f4",
             "fb...8f4",
             "b8...6b3"]),
    "L": lv(["fb....",
             "fb....",
             "fb....",
             "fb....",
             "fb....",
             "febbb6",
             "bbbbb6"]),
}
ST_LV_CROP = {"S": ("SPEED", 0, 7), "U": ("TSUNO", 14, 21), "E": ("DEF", 8, 14),
              "O": ("POW", 8, 15), "P": ("BP", 8, 14)}


def st_lv(ch):
    if ch in ST_LV_NEW:
        return ST_LV_NEW[ch]
    w, x0, x1 = ST_LV_CROP[ch]
    return load(ST[w])[:, x0:x1, 1]


def st_word(word, places):
    a = np.zeros((12, 42), int)
    for ch, x in zip(word, places):
        g = st_lv(ch)
        w = min(g.shape[1], 42 - x)
        a[:, x:x + w] = np.maximum(a[:, x:x + w], g[:, :w])
    la = np.zeros((12, 42, 2), int)
    la[..., 0] = 15
    la[..., 1] = a
    return la


# (output path relative to work/img/ko/lyt, source original, how)
JOBS = {
    "STbr_BP": ("BLyt/btl_RESLT_LYT_JP_ja/STbr_BP_00_JP_ja.png", "model", ("SP", "STbr", dict(places=[1, 10]))),
    "STbr_HIGE": ("BLyt/btl_RESLT_LYT_JP_ja/STbr_HIGE_00_JP_ja.png", "model",
                  ("SUYEOM", "STbr", dict(places=[1, 10, 19, 28, 36, 45]))),
    "STbr_TSUNO": ("BLyt/btl_RESLT_LYT_JP_ja/STbr_TSUNO_00_JP_ja.png", "model",
                   ("PPUL", "STbr", dict(places=[2, 11, 20, 29]))),
    "ST_BP": ("MLyt/MENU_ITEM_Lyt_JP_ja/ST_BP_00_JP_ja.png", "copy_sp", None),
    "KJ_ST_GDD": ("KLyt/KJ_RESULT_JP_ja/KJ_ST_GDD_00_JP_ja.png", "copy_gdh", None),
    "ST_HIGE": ("MLyt/MENU_ITEM_Lyt_JP_ja/ST_HIGE_00_JP_ja.png", "st_word", ("SUYEOM", [0, 8, 15, 22, 28, 35])),
    "ST_TSUNO": ("MLyt/MENU_ITEM_Lyt_JP_ja/ST_TSUNO_00_JP_ja.png", "st_word", ("PPUL", [1, 8, 15, 23])),
}


def make(job):
    rel, how, arg = JOBS[job]
    orig = load(L3 / rel)
    if how == "st_word":
        la = st_word(*arg)
        face, miss = face_st(la), 0
    elif how == "model":
        a2 = arg[2]
        la, face, miss = render_word(arg[0], arg[1], start=a2.get("start", 0), gap=a2.get("gap", 1),
                                     places=a2.get("places"), width=a2.get("canvas"))
        if a2.get("fit"):
            la = hfit(la, a2["fit"], orig.shape[1], a2.get("start", 0))
    elif how == "copy_sp":
        sp = load(ST["SPEED"])
        la = np.zeros_like(orig)
        la[..., 0] = 15
        la[:, :14] = sp[:, :14]
        face, miss = face_st(la), 0
    elif how == "copy_gdh":
        g = load(ST["GDD"])
        hp = load(ST["HP"])
        la = np.zeros_like(orig)
        la[..., 0] = 15
        la[:, :15] = g[:, :15]
        paste_max(la, hp[:, 1:8], GDH_X)
        face, miss = face_st(la), 0
    la[la[..., 1] == 0, 0] = 15            # transparent texels: same grey as the originals
    return orig, la, face, miss


GDH_X = 15


def hfit(la, target, out_w, x0):
    """Squeeze the ink horizontally (alpha-only ST set) to `target` px wide (0장: 장평 >= 80 %)."""
    import cv2
    a = la[..., 1].astype(np.float64) / 15.0
    cols = np.nonzero(a.any(0))[0]
    c0, c1 = cols.min(), cols.max() + 1
    src = a[:, c0:c1]
    scale = target / src.shape[1]
    assert scale >= 0.8, scale
    # area resample at 8x for exact fractional widths
    big = cv2.resize(src, (src.shape[1] * 8, src.shape[0]), interpolation=cv2.INTER_NEAREST)
    small = cv2.resize(big, (target, src.shape[0]), interpolation=cv2.INTER_AREA)
    out = np.zeros((la.shape[0], out_w, 2), int)
    out[..., 0] = 15
    out[:, x0:x0 + target, 1] = np.clip(np.rint(small * 15), 0, 15).astype(int)
    return out


def on_bg(la, bg=(59, 120, 199)):
    a = la[..., 1:2] / 15.0
    l = la[..., 0:1] * 17.0
    return (l * a + np.asarray(bg) * (1 - a)).astype(np.uint8)


def sheet(pairs, out, zoom=6):
    """pairs: [(label, orig_la, ko_la)] -> PNG (<=1600 px per side), orig | ko at 1x and zoom x."""
    from PIL import ImageDraw
    rows = []
    for label, o, k in pairs:
        h, w = o.shape[:2]
        tile = Image.new("RGB", (w * zoom * 2 + w * 2 + 60, h * zoom + 22), (40, 40, 40))
        d = ImageDraw.Draw(tile)
        d.text((4, 2), label, fill=(255, 220, 90))
        x = 4
        for im in (o, k):
            tile.paste(Image.fromarray(on_bg(im)), (x, 20))
            x += w + 8
        for im in (o, k):
            big = Image.fromarray(on_bg(im)).resize((w * zoom, h * zoom), Image.NEAREST)
            tile.paste(big, (x, 20))
            x += w * zoom + 8
        rows.append(tile)
    W = max(t.width for t in rows)
    H = sum(t.height + 4 for t in rows)
    assert W <= 1600 and H <= 1600, (W, H)
    img = Image.new("RGB", (W, H), (30, 30, 30))
    y = 0
    for t in rows:
        img.paste(t, (0, y))
        y += t.height + 4
    img.save(out)


def cmd_build(write=True):
    pairs = []
    rep = {}
    for job, (rel, how, arg) in JOBS.items():
        orig, la, face, miss = make(job)
        pairs.append((f"{job}  {rel.split('/')[-1]}", orig, la))
        ink = np.nonzero(la[..., 1].any(0))[0]
        rep[job] = {"out": rel, "how": how, "model_misses": int(miss),
                    "ink_x": [int(ink.min()), int(ink.max())] if len(ink) else None}
        if write:
            save(la, KO / rel)
    sheet(pairs[:4], ROOT / "work/img/review/C_stat_en_1.png", zoom=6)
    sheet(pairs[4:], ROOT / "work/img/review/C_stat_en_2.png", zoom=8)
    (ROOT / "work/img/C_stat_report.json").write_text(json.dumps(rep, indent=1), "utf-8")


def cmd_preview():
    cmd_build(write=False)


def br_letters():
    imgs = load_br()
    lib = {}
    for name, la in imgs.items():
        f = face_br(la)
        segs, _ = letters_of(name, f)
        for ch, (x0, x1) in segs.items():
            lib.setdefault(ch, f[:, x0:x1].copy())
    return lib, imgs


# ----------------------------------------------------------------------------- ST set (alpha only)

def st_letters():
    lib = {}
    imgs = {n: load(p) for n, p in ST.items()}
    for name, la in imgs.items():
        a = la[..., 1]
        segs = segments(a >= 7)
        if len(segs) != len(name):
            # touching letters: fall back to splitting at weakest column
            lib.setdefault("_bad_" + name, a)
            continue
        for ch, (x0, x1) in zip(name, segs):
            lib.setdefault(ch, a[:, x0:x1].copy())
    return lib, imgs


def ascii_mask(m, chars=" #"):
    return "\n".join("".join(chars[int(v)] for v in row) for row in m)


def ascii_levels(a):
    return "\n".join("".join("%x" % v if v else "." for v in row) for row in a)


def cmd_letters():
    out = open(TMP / "letters.txt", "w", encoding="utf-8")
    for name, la in load_br().items():
        f = face_br(la)
        out.write(f"=== STbr {name} segs {segments(f)}\n")
        out.write("".join(str(x % 10) for x in range(f.shape[1])) + "\n")
        out.write(ascii_mask(f[3:13], ".#") + "\n")
    for name, p in ST.items():
        a = load(p)[..., 1]
        out.write(f"=== ST {name} segs {segments(a >= 7)}\n")
        out.write("".join(str(x % 10) for x in range(a.shape[1])) + "\n")
        out.write(ascii_levels(a[1:10]) + "\n")
    out.close()
    return
    lib, imgs = br_letters()
    for name, la in imgs.items():
        f = face_br(la)
        out.write(f"STbr {name} segs {segments(f)}\n")
    for ch, m in sorted(lib.items()):
        out.write(f"--- STbr {ch} w={m.shape[1]}\n" + ascii_mask(m[3:13]) + "\n")
    slib, simgs = st_letters()
    for name, la in simgs.items():
        out.write(f"ST {name} segs {segments(la[..., 1] >= 7)}\n")
    for ch, m in sorted(slib.items()):
        out.write(f"--- ST {ch} w={m.shape[1]}\n" + ascii_levels(m[1:10]) + "\n")
    out.close()


def face_st(la):
    return la[..., 1] >= 8


def load_st():
    return {n: load(p) for n, p in ST.items()}


def cmd_selftest():
    out = open(TMP / "selftest_stat.txt", "w", encoding="utf-8")
    for setname, imgs, ff in (("STbr", load_br(), face_br), ("ST", load_st(), face_st)):
        for name, la in imgs.items():
            for excl in (None, name):
                m = Model(imgs, exclude=excl, face_fn=ff)
                rep = m.apply(ff(la))
                vis = la[..., 1] > 0
                dl = np.abs(rep[..., 0] - la[..., 0])[vis | (rep[..., 1] > 0)]
                da = np.abs(rep[..., 1] - la[..., 1])
                out.write(f"{setname} {name} exclude={excl}: mean|dL|vis={dl.mean():.3f} maxL={dl.max()} "
                          f"mean|dA|={da.mean():.3f} maxA={da.max()} pxA>2={(da>2).sum()} misses={m.miss}\n")
    out.close()


def _old_selftest():
    imgs = load_br()
    out = open(TMP / "selftest_stat.txt", "w", encoding="utf-8")
    for name, la in imgs.items():
        for excl in (None, name):
            m = Model(imgs, exclude=excl)
            rep = m.apply(face_br(la))
            vis = la[..., 1] > 0
            dl = np.abs(rep[..., 0] - la[..., 0])[vis | (rep[..., 1] > 0)]
            da = np.abs(rep[..., 1] - la[..., 1])
            bg = np.bincount(la[..., 0][~vis]).argmax() if (~vis).any() else -1
            out.write(f"{name} exclude={excl}: mean|dL|vis={dl.mean():.3f} maxL={dl.max()} mean|dA|={da.mean():.3f} "
                      f"maxA={da.max()} pxA>2={(da>2).sum()} misses={m.miss}/{m.miss5} bgL={bg}\n")
    out.close()


if __name__ == "__main__":
    {"letters": cmd_letters, "selftest": cmd_selftest, "build": cmd_build, "preview": cmd_preview}[sys.argv[1]]()
