"""2nd-round layout images, group D (list_title, list_title_faint, guide_pnl, record_btn).

python scripts/lyt_D.py measure            -> work/img/D_measure.json (imgtext.measure_style per texture)
python scripts/lyt_D.py make [--only a,b] [--dry]
        render every `replace` texture with the family style -> work/img/ko/lyt/<dat>/<entry>/<name>.png
        (written as <name>.tmp.png, then renamed), report -> work/img/D_make.json
python scripts/lyt_D.py sheets             -> work/img/review/D_<family>*.png (<= 1600 px tiles)
"""
from __future__ import annotations

import copy
import json
import os
import sys
from pathlib import Path

import numpy as np

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "scripts"))
os.chdir(ROOT)

FAMS = ("list_title", "list_title_faint", "guide_pnl", "record_btn")

# Family decoration, unified from the measurements in work/img/D_measure.json (see work/img/D.md).
#   em      Hangul face height (px) per line count
#   stroke  face stroke thickness to reach (px)
#   layers  outline layers (width px, colour)
FAMILY = {
    # 1DX font.bffnt (15 px) drawn at 12 px. (font_btl at its own 11 px was tried: crisp, but its
    #  「틀」「블」 are solid blobs -- the jamo gaps are half-grey rows that close up; D.md)
    "list_title": {"em": {1: 12.0}, "stroke": 1.8, "track": {1: -1.0}, "layers": [], "white_face": True,
                   "fonts": ("font",)},
    # toolkit v1.2 defaults (Japanese em / stroke, 1DX font_btl at its own 11 px on the pixel grid)
    "list_title_faint": {"em": {1: None}, "stroke": None, "track": {1: -1.0}, "layers": [], "white_face": True,
                         "sharp": 1.0},
    # two lines in 96x32: 12 px lines need a 13 px pitch (the Japanese 9.5 px lines used 10.5)
    "guide_pnl": {"em": {1: 12.0, 2: 12.0}, "stroke": 1.9, "track": {1: -1.0, 2: -1.0}, "fonts": ("font",),
                  "layers": [(1.75, (0.0, 0.0, 0.0))], "lines": {2: [(3, 15), (16, 28)]}},
    # 88x24 buttons: every label on ONE line (two 10 px Hangul lines do not fit legibly; D.md)
    "record_btn": {"em": {1: 12.0}, "stroke": 1.9, "track": {1: -1.0}, "fonts": ("font",),
                   "layers": [(1.75, (0.0, 0.0, 0.0))]},
}
# glyph source for every D texture: 1DX bitmap font (font.bffnt), downscaled 15 -> 10..12 px.
SOURCE = "font"

# per-texture changes to the family settings (none at present)
ITEM_CFG: dict[str, dict] = {}

# Korean text where the image differs from lyt_plan.json `ko` (line breaks only; D.md 리드 확인)
TEXT = {
    "btn_p_MINIGAME_00_JP_ja": "어택 미니 게임",
    "btn_p_ATTACK_00_JP_ja": "어택피스",
    "btn_p_COLISEUM_00_JP_ja": "배틀 콜로세움",
}

# per-texture overrides (render keyword arguments)
OVERRIDE: dict[str, dict] = {}


MIN_SRC_RATIO = 0.95     # image glyphs smaller than this x target em are not used (would be upscaled)
FONT_NAMES = [None]      # bitmap fonts render() may pick from (set per family in cmd_make)


def patch_sources() -> None:
    """Wrapper around imgtext_bank (TOOLKIT_REQUESTS.md, D-1): the bank's 1DX list-title glyphs
    are ~10 px blobs; the stock size cost prefers them to 16 px button glyphs for an 11 px
    target, and upscaling them gives an illegible smear. Here: upscaling costs far more than
    downscaling, and a same_word / bank result that would still be upscaled is refused so the
    next source (1DX bitmap font, downscaled) is used."""
    import math
    import imgtext_bank as B
    if getattr(B, "_lyt_D_patched", False):
        return
    if hasattr(B, "BANK_MIN_EM") or not hasattr(B, "_bank_word"):
        # toolkit >= 1.1 already refuses small / upscaled bank glyphs. Only add a per-family
        # choice of bitmap fonts (FONT_NAMES) to _font_order.
        order = B._font_order

        def font_order(em_native, names=None):
            return order(em_native, FONT_NAMES[0] or names or ("font", "font_l", "font_btl"))

        B._font_order = font_order
        B._lyt_D_patched = True
        return

    def cost(src_em: float, em: float) -> float:
        r = src_em / em
        return abs(math.log(r)) if r >= 1 else 2.0 + 6.0 * abs(math.log(r))

    B._size_cost = cost
    same, bank = B._same_word, B._bank_word

    def guard(fn):
        def inner(word, em_native):
            g = fn(word, em_native)
            if g and min(x.em for x in g) < MIN_SRC_RATIO * em_native:
                return None
            return g
        return inner

    B._same_word = guard(same)
    B._bank_word = guard(bank)
    # (tried: 1DX font_btl as a native 11 px source -- rejected, its bold battle strokes turn
    #  블/틀/콜 into blobs; see D.md)
    B._lyt_D_patched = True


def items(action: str | None = "replace") -> list[dict]:
    plan = json.load(open("work/img/lyt_plan.json", encoding="utf-8"))
    out = [it for it in plan["items"] if it.get("family") in FAMS]
    if action:
        out = [it for it in out if it.get("action") == action]
    return out


def ref_png(ref_id: str) -> str:
    game, rest = ref_id.split(":", 1)
    dat, entry, _timg, name = rest.split("/")
    return f"work/img/lyt/{game}/{dat}/{entry}/{name.replace('.bflim', '.png')}"


def cmd_measure() -> None:
    import imgtext as T
    res = {}
    for it in items(None):
        rgba = T.load_png(it["png"])
        try:
            st = T.measure_style(rgba, lines=it["box"].get("lines"))
            res[it["base"]] = {"family": it["family"], "style": st.to_json()}
        except Exception as e:  # noqa: BLE001
            res[it["base"]] = {"family": it["family"], "error": repr(e)}
    json.dump(res, open("work/img/D_measure.json", "w", encoding="utf-8"), ensure_ascii=False, indent=1)
    print("measured", len(res))


def family_face(fam: str) -> list:
    """Mean face gradient (7 stops) over the family's measured textures."""
    if FAMILY[fam].get("white_face"):
        return [(i / 6, (1.0, 1.0, 1.0)) for i in range(7)]
    m = json.load(open("work/img/D_measure.json", encoding="utf-8"))
    rows = [v["style"]["face_stops"] for k, v in m.items()
            if v.get("family") == fam and "style" in v and k != "btn_p_HATENA_00_JP_ja"]
    arr = np.array([[c for _t, c in r] for r in rows])     # n, 7, 3
    mean = arr.mean(axis=0)
    g = mean.mean(axis=1)                                  # grey
    return [(round(i / 6, 4), (float(v), float(v), float(v))) for i, v in enumerate(g)]


def style_for(it: dict, T, lines_override=None):
    fam = it["family"]
    cfg = FAMILY[fam]
    jp = T.load_png(it["png"])
    st = T.measure_style(jp, lines=it["box"].get("lines"))
    st.face_stops = family_face(fam)
    st.layers = [T.Layer(w, c, 1.0) for w, c in cfg["layers"]]
    st.shadow = None
    st.plate = False
    lo = lines_override or cfg.get("lines", {}).get(it["box"].get("lines"))
    if lo:
        st.lines = [tuple(x) for x in lo]
    return jp, st


PHASE_DY = (-0.5, -0.25, 0.0, 0.25, 0.5)
PHASE_DX = (0.0, 0.25, 0.5, 0.75)


SHARP = 1.5      # contrast gain on coverage around 0.5 (1 = off); see D.md
SHARP_FACE = True


def sharpen(k: np.ndarray, white: bool, gain: float = SHARP) -> np.ndarray:
    """Crisper edges after the 15 -> 10..12 px downscale: stretch alpha (outer edge) and, for
    outlined labels, the face coverage L / (face level of that row) (face/outline edge)."""
    if gain == 1.0:
        return k
    x = k.copy()
    s = lambda v: np.clip((v - 0.5) * gain + 0.5, 0, 1)
    x[..., 3] = s(x[..., 3])
    if not white and SHARP_FACE:
        L = x[..., 0]
        op = k[..., 3] > 0.5
        lev = np.ones(L.shape[0])
        for y in range(L.shape[0]):
            v = L[y][op[y]]
            if len(v) and v.max() > 0.3:
                lev[y] = np.percentile(v, 95)
        c = np.clip(L / lev[:, None], 0, 1)
        L2 = s(c) * lev[:, None]
        x[..., :3] = L2[..., None]
    return x


def blur_metric(k: np.ndarray, white: bool) -> float:
    """Mean 'greyness' of the ink: a(1-a) of alpha, plus L(1-L) of luminance under opaque
    pixels for outlined labels (face/outline edge). Lower = crisper."""
    a = k[..., 3]
    ink = a > 0.02
    if not ink.any():
        return 1e9
    m = float((a * (1 - a))[ink].mean())
    if not white:
        L = k[..., 0]
        op = a > 0.5
        m += float((L * (1 - L))[op].mean())
    return m


def cmd_make(only: set[str] | None, dry: bool) -> None:
    import imgtext as T
    patch_sources()
    report = {}
    made = []
    for it in items():
        if only and it["base"] not in only:
            continue
        fam = it["family"]
        cfg = dict(FAMILY[fam])
        cfg.update(ITEM_CFG.get(it["base"], {}))
        jp, st = style_for(it, T)
        text = TEXT.get(it["base"], it["ko"])
        n = text.count("\n") + 1
        if n != len(st.lines):
            h = st.size[1]
            st.lines = [(h / 2 - cfg["em"][n] / 2, h / 2 + cfg["em"][n] / 2)]
            st.box = (st.box[0], int(st.lines[0][0]), st.box[2], int(st.lines[0][1]))
        kw = {"em": cfg["em"][n], "weight": cfg["stroke"], "tracking": cfg["track"][n], "source": SOURCE}
        kw = {k: v for k, v in kw.items() if v is not None}
        gain = cfg.get("sharp", SHARP)
        FONT_NAMES[0] = cfg.get("fonts")
        if it["box"].get("align"):
            kw["align"] = it["box"]["align"]
        kw.update(OVERRIDE.get(it["base"], {}))
        # pixel-grid phase: the 15 px font is drawn at 10-12 px, so where the strokes land on the
        # pixel grid decides whether a horizontal stroke is one solid row or two grey ones. Try
        # quarter-pixel shifts and keep the crispest (least half-transparent / half-grey ink).
        best = None
        grid = cfg.get("sharp", SHARP) != 1.0       # v1.2 native-size glyphs are grid-snapped already
        for dy in (PHASE_DY if grid else (0.0,)):
            for dx in (PHASE_DX if grid else (0.0,)):
                st2 = copy.deepcopy(st)
                st2.box = (st.box[0] + dx, st.box[1] + dy, st.box[2] + dx, st.box[3] + dy)
                st2.lines = [(a + dy, b + dy) for a, b in st.lines]
                rep_c = {}
                k = T.render(text, st2, report=rep_c, **kw)
                k = T.bleed(k)
                if cfg.get("white_face"):
                    k[..., :3] = 1.0
                k = sharpen(k, bool(cfg.get("white_face")), gain)
                k = T.finalize(k, it["fmt"])
                m = blur_metric(k, bool(cfg.get("white_face")))
                if best is None or m < best[0] - 1e-9:
                    best = (m, k, rep_c, dx, dy)
        _m, ko, rep, pdx, pdy = best
        rep["phase"] = (pdx, pdy, round(_m, 4))
        cmp = T.compare(jp, ko, st)
        prob = T.verdict(cmp)
        report[it["base"]] = {"text": text, "sources": rep.get("sources"), "fit": rep.get("fit"),
                              "em": rep.get("em"), "weight_delta_px": rep.get("weight_delta_px"),
                              "phase": rep.get("phase"),
                              "compare": cmp["summary"], "problems": prob}
        if dry:
            pv = Path("work/img/D_tmp/preview") / (it["base"] + ".png")
            pv.parent.mkdir(parents=True, exist_ok=True)
            T.save_png(ko, pv)
        else:
            out = Path(it["ko_png"])
            out.parent.mkdir(parents=True, exist_ok=True)
            tmp = out.with_name(out.stem + ".tmp.png")
            T.save_png(ko, tmp)
            os.replace(tmp, out)
        made.append(it["base"])
    old = {}
    rp = Path("work/img/D_make.json")
    if rp.exists() and only:
        old = json.load(open(rp, encoding="utf-8"))
    old.update(report)
    json.dump(old, open(rp, "w", encoding="utf-8"), ensure_ascii=False, indent=1, default=str)
    print("made", len(made), "dry" if dry else "")


def cmd_sheets(preview: bool = False) -> None:
    import imgtext as T
    from PIL import Image
    tag = "Dpv" if preview else "D"
    root = "work/img/D_tmp" if preview else "work/img/review"

    def ko_of(it):
        return Path("work/img/D_tmp/preview") / (it["base"] + ".png") if preview else Path(it["ko_png"])
    for fam in FAMS:
        rows = []
        for it in items():
            if it["family"] != fam:
                continue
            ko_p = ko_of(it)
            if not ko_p.exists():
                continue
            imgs = [T.load_png(it["png"]), T.load_png(ko_p)]
            if it.get("ref_1dx"):
                try:
                    imgs.append(T.load_png(ref_png(it["ref_1dx"])))
                except Exception:  # noqa: BLE001
                    pass
            rows.append((f"{it['base']}  {it['jp'].replace(chr(10), '/')} -> {TEXT.get(it['base'], it['ko']).replace(chr(10), '/')}", imgs))
        if rows:
            T.make_sheet(rows, f"{root}/{tag}_{fam}.png", zoom=3)
        # family overview: all Korean images at 3x stacked (same-family consistency)
        kos = [T.load_png(ko_of(it)) for it in items() if it["family"] == fam and ko_of(it).exists()]
        if kos:
            blocks = []
            for k in kos:
                h, w = k.shape[:2]
                im = T._on_bg(k, (0.23, 0.47, 0.78))
                blocks.append(Image.fromarray(T.to_u8(np.concatenate([im, np.ones((h, w, 1))], -1))[..., :3]).resize((w * 3, h * 3), Image.NEAREST))
            T.save_tiled(blocks, f"{root}/{tag}_{fam}_all.png", gap=6)
    print("sheets done")


def cmd_trial(base: str, text: str, combos: list[str], out: str, zoom: int = 6, lines_override=None) -> None:
    """Render one texture with several render() settings, stacked at zoom (<=1600 px)."""
    import imgtext as T
    from PIL import Image
    patch_sources()
    it = next(i for i in items(None) if i["base"] == base)
    jp, st = style_for(it, T, lines_override)
    cfg = FAMILY[it["family"]]
    rows = [jp]
    log = []
    for c in combos:
        kw = {"align": it["box"].get("align") or None}
        for part in c.split(";"):
            if not part:
                continue
            k, v = part.split("=")
            kw[k] = v if k == "source" else float(v)
        rep = {}
        ko = T.render(text, st, report=rep, **kw)
        ko = T.bleed(ko)
        if cfg.get("white_face"):
            ko[..., :3] = 1.0
        rows.append(T.finalize(ko, it["fmt"]))
        log.append(f"{c}: {rep.get('sources')} wd={rep.get('weight_delta_px')} fit={rep.get('fit')}")
    ims = []
    for r in rows:
        h, w = r.shape[:2]
        rgb = T._on_bg(r)
        ims.append(Image.fromarray(T.to_u8(rgb)).resize((w * zoom, h * zoom), Image.NEAREST))
    W = max(i.width for i in ims)
    H = sum(i.height + 4 for i in ims)
    o = Image.new("RGB", (W, H))
    y = 0
    for i in ims:
        o.paste(i, (0, y))
        y += i.height + 4
    if max(o.size) > 1600:
        f = 1600 / max(o.size)
        o = o.resize((int(o.width * f), int(o.height * f)), Image.NEAREST)
    o.save(out)
    Path(out).with_suffix(".txt").write_text("\n".join(log), encoding="utf-8")


if __name__ == "__main__":
    a = sys.argv[1:]
    if a[0] == "trial":
        cmd_trial(a[1], a[2].replace("\\n", "\n"), a[4:], a[3])
        sys.exit(0)
    if a[0] == "measure":
        cmd_measure()
    elif a[0] == "make":
        only = None
        if "--only" in a:
            only = set(a[a.index("--only") + 1].split(","))
        cmd_make(only, "--dry" in a)
    elif a[0] == "sheets":
        cmd_sheets("--preview" in a)
