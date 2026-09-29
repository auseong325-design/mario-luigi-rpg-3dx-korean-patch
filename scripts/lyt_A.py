"""lyt_A.py -- 2nd-round layout images, group A (Koopa Jr. RPG screens).

Group A's own helper (work/IMAGE_TASK.md 5장 2차). Reads work/img/lyt_plan.json, keeps only
group A families, and offers:
    analyze   -> per-texture stats + zoomed JP/1DX tiles (scratch dir) for planning
The actual image makers live further down (added as they are written).
"""
from __future__ import annotations

import json
import os
import sys
from pathlib import Path

import numpy as np
from PIL import Image

ROOT = Path(__file__).resolve().parents[1]
FAMS = ["kj_skill", "kj_battle_btn", "kj_menu_btn", "kj_small_btn", "kj_faint_label",
        "kj_dark_label", "kj_sort_btn", "kj_type", "kj_label"]
SCRATCH = Path(os.environ.get("KIROCREW_SCRATCH", ROOT / "work" / "tmp_A"))
RUN = os.environ.get("A_RUN", "")  # suffix for scratch outputs (read tool caches by path)


def plan_items(all_=False):
    p = json.load(open(ROOT / "work/img/lyt_plan.json", encoding="utf-8"))
    out = [it for it in p["items"] if it.get("family") in FAMS]
    if not all_:
        out = [it for it in out if it.get("action") == "replace"]
    return out


_MAN = None


def manifest():
    global _MAN
    if _MAN is None:
        m = json.load(open(ROOT / "work/img/lyt_manifest.json", encoding="utf-8"))
        _MAN = {e["id"]: e for g in m.values() for e in g}
    return _MAN


def load(path) -> np.ndarray:
    return np.asarray(Image.open(ROOT / path).convert("RGBA"))


def ref_png(ref_id: str):
    e = manifest().get(ref_id)
    return None if e is None else e["png"]


def stats(a: np.ndarray) -> dict:
    al = a[..., 3].astype(int)
    L = a[..., 0].astype(int)
    ys, xs = np.nonzero(al > 0)
    bb = (int(xs.min()), int(ys.min()), int(xs.max()), int(ys.max())) if len(xs) else None
    op = al > 200
    return {
        "bbox": bb,
        "alpha_levels": sorted(set(al.ravel().tolist()))[:20],
        "L_opaque": dict(zip(*[x.tolist() for x in np.unique(L[op], return_counts=True)])) if op.any() else {},
        "white_px": int(((L > 200) & op).sum()),
        "black_px": int(((L < 60) & op).sum()),
    }


def zoom_tile(arrs, z=6, bg=(60, 120, 200)):
    hs = sum(a.shape[0] * z + 4 for a in arrs)
    ws = max(a.shape[1] * z for a in arrs)
    out = Image.new("RGB", (ws, hs), (30, 30, 30))
    y = 0
    for a in arrs:
        im = Image.fromarray(a, "RGBA")
        b = Image.new("RGBA", im.size, bg + (255,))
        b.alpha_composite(im)
        out.paste(b.convert("RGB").resize((a.shape[1] * z, a.shape[0] * z), Image.NEAREST), (0, y))
        y += a.shape[0] * z + 4
    return out


def cmd_analyze():
    rep = []
    tiles = SCRATCH / "A_tiles"
    tiles.mkdir(parents=True, exist_ok=True)
    for it in plan_items():
        jp = load(it["png"])
        r = {"base": it["base"], "family": it["family"], "kind": it["kind"], "ko": it["ko"],
             "size": [it["w"], it["h"]], "fmt": it["fmt"], "jp": stats(jp)}
        arrs = [jp]
        rp = ref_png(it["ref_1dx"]) if it.get("ref_1dx") else None
        if rp:
            e = manifest()[it["ref_1dx"]]
            ra = load(rp)
            r["ref"] = {"id": it["ref_1dx"], "size": [e["w"], e["h"]], "fmt": e["fmt"], **stats(ra)}
            arrs.append(ra)
        rep.append(r)
        zoom_tile(arrs).save(tiles / f"{it['base']}.png")
    with open(SCRATCH / "A_analyze.json", "w", encoding="utf-8") as f:
        json.dump(rep, f, ensure_ascii=False, indent=1)
    print(len(rep))


def T():
    sys.path.insert(0, str(ROOT / "scripts"))
    import imgtext
    return imgtext


def cmd_measure():
    t = T()
    rows, js = [], {}
    for it in plan_items():
        jp = t.load_png(ROOT / it["png"])
        lines = it.get("box", {}).get("lines")
        st = t.measure_style(jp, lines=lines)
        js[it["base"]] = st.to_json()
        lay = " ".join(f"{l.width:.2f}@{l.color[0]:.2f}" for l in st.layers)
        sh = f"sh({st.shadow.dx},{st.shadow.dy},w{st.shadow.width},{st.shadow.color[0]:.2f},a{st.shadow.alpha})" if st.shadow else "-"
        f0, f1 = st.face_stops[0][1][0], st.face_stops[-1][1][0]
        rows.append(f"{it['family']:15s} {it['base']:30s} {it['w']}x{it['h']} em={st.em:.1f} stroke={st.stroke:.2f} "
                    f"face={f0:.2f}->{f1:.2f} layers[{lay}] {sh} box={st.box} ink={st.ink} {st.align} lines={st.lines} {st.notes[-1]}")
    rows.sort()
    (SCRATCH / "A_measure.txt").write_text("\n".join(rows), encoding="utf-8")
    json.dump(js, open(SCRATCH / "A_measure.json", "w", encoding="utf-8"), ensure_ascii=False, indent=0)
    print(len(rows))


def cmd_sources():
    """Which glyph source imgtext would pick for each word (planning)."""
    T()
    import imgtext_bank as B
    ms = json.load(open(SCRATCH / "A_measure.json", encoding="utf-8"))
    out = []
    for it in plan_items():
        em = ms[it["base"]]["em"] or 12
        row = [it["family"], it["base"], it["kind"], it["ko"].replace("\n", "/"), f"em={em}"]
        for line in it["ko"].split("\n"):
            for w in line.split(" "):
                try:
                    g, src = B.word_glyphs(w, em * 4)
                    row.append(f"{w}:{src}")
                except Exception as e:  # noqa
                    row.append(f"{w}:ERR {e}")
        out.append(" ".join(row))
    (SCRATCH / "A_sources.txt").write_text("\n".join(sorted(out)), encoding="utf-8")
    print(len(out))


def _u8(a):
    a = np.asarray(a)
    if a.dtype != np.uint8:
        a = np.clip(np.rint(a * 255), 0, 255).astype(np.uint8)
    return a


def _on(a, bg):
    im = Image.fromarray(_u8(a), "RGBA")
    b = Image.new("RGBA", im.size, bg + (255,))
    b.alpha_composite(im)
    return b.convert("RGB")


def review_sheet(rows, path, z=3, maxw=1600, maxh=1600, bgs=((60, 120, 200), (200, 200, 200))):
    """rows = [(label, jp_rgba, ko_rgba)]. Each row: label, then JP 1x | KO 1x | JP 3x | KO 3x, on
    two backgrounds (blue, light grey). Saved in pieces of at most maxw x maxh (path_1.png ...)."""
    from PIL import ImageDraw, ImageFont
    try:
        fnt = ImageFont.truetype(str(ROOT / "fonts" / sorted(os.listdir(ROOT / "fonts"))[0]), 12)
    except Exception:
        fnt = None
    cand = [f for f in (ROOT / "fonts").rglob("*.[ot]tf")]
    for f in cand:
        if "Nanum" in f.name or "Noto" in f.name or "Gothic" in f.name:
            try:
                fnt = ImageFont.truetype(str(f), 12)
                break
            except Exception:
                pass
    blocks = []
    for label, jp, ko in rows:
        h, w = jp.shape[:2]
        parts = []
        for bg in bgs:
            parts += [_on(jp, bg), _on(ko, bg)]
        big = [p.resize((p.width * z, p.height * z), Image.NEAREST) for p in parts]
        small_w = w * 2 + 3
        side = small_w + 6 + 2 * w * z + 3 + 4 <= maxw
        W = max(small_w + 6 + (2 * w * z + 3 if side else w * z) + 4, 300)
        rowh = h * z if side else 2 * h * z + 3
        H = 14 + (rowh + 4) * len(bgs)
        blk = Image.new("RGB", (min(W, maxw), H), (32, 32, 32))
        d = ImageDraw.Draw(blk)
        d.text((2, 0), label, fill=(255, 230, 120), font=fnt)
        y = 14
        for i in range(len(bgs)):
            x = 2
            for p in parts[2 * i:2 * i + 2]:
                blk.paste(p, (x, y)); x += p.width + 3
            x += 6
            if side:
                for p in big[2 * i:2 * i + 2]:
                    blk.paste(p, (x, y)); x += p.width + 3
            else:
                blk.paste(big[2 * i], (x, y))
                blk.paste(big[2 * i + 1], (x, y + h * z + 3))
            y += rowh + 4
        blocks.append(blk)
    # pack blocks into columns/pages
    pages, cur, cy, colw = [], [], 0, 0
    W = min(maxw, max(b.width for b in blocks))
    for b in blocks:
        if cy + b.height > maxh and cur:
            pages.append(cur); cur, cy = [], 0
        cur.append(b); cy += b.height + 2
    if cur:
        pages.append(cur)
    out = []
    for i, pg in enumerate(pages, 1):
        H = sum(b.height + 2 for b in pg)
        im = Image.new("RGB", (min(maxw, max(b.width for b in pg)), min(maxh, H)), (20, 20, 20))
        y = 0
        for b in pg:
            im.paste(b.crop((0, 0, min(b.width, maxw), b.height)), (0, y)); y += b.height + 2
        p = Path(str(path).replace(".png", f"_{i}.png")) if len(pages) > 1 else Path(path)
        im.save(p)
        out.append(p)
    return out


def cmd_try():
    """Quick trial: python lyt_A.py try <base> [source] -> scratch A_try_<base>.png (+report)."""
    t = T()
    base = sys.argv[2]
    src = sys.argv[3] if len(sys.argv) > 3 else "auto"
    it = next(i for i in plan_items() if i["base"] == base)
    ko, rep = t.redraw(ROOT / it["png"], it["ko"], fmt=it["fmt"], source=src,
                       lines=it.get("box", {}).get("lines"))
    jp = t.load_png(ROOT / it["png"])
    review_sheet([(f"{base} {src}", jp, ko)], SCRATCH / f"A_try_{base}.png", z=6)
    json.dump({k: v for k, v in rep.items() if k != "style"}, open(SCRATCH / f"A_try_{base}.json", "w", encoding="utf-8"),
              ensure_ascii=False, indent=1, default=str)
    print(rep.get("problems"))


# ----------------------------------------------------------------------------- making

# per-texture overrides: text (default plan ko), source, em, weight, hscale, tracking,
# keep_rows=(y0,y1) rows copied from the original (e.g. the 'LV' line), lines
CFG: dict[str, dict] = {
    # kind 가 that keep the 1DX picture of the same word
    "btn_KJ_BSTART_00_JP_ja": {"source": "auto"},
    # 「LV」 line: original pixels (rows 14-27), only 「군단」 is new
    "PARTY_LV_00_JP_ja": {"source": "auto", "keep_rows": [14, 28]},
    # one syllable measures too bold (README 6: weight = JP stroke x 0.8)
    "btn_YES1_00_JP_ja": {"weight": 2.4},
    # 쿵쿵 떨어트리기: the default weight stops at ratio 0.965 (calibration tolerance 4 %), just under
    # the rest of kj_skill (0.973-1.025); 3.15 px (JP stroke 3.10 x 1.02) lands on the family median
    "btn_KJ_LA_24_00_JP_ja": {"weight": 3.15},
}

# one glyph source per family, so that every texture of a family has the same letter shape
# (1DX bitmap font; imgtext picks font / font_l / font_btl by size)
FAMILY_SOURCE = {f: "font" for f in FAMS}


_FAMSTYLE: dict = {}


def family_style(fam: str, outlined: bool):
    """Median face gradient / outline of the family members that share the outline structure
    (decoration identical inside a family; small buttons mix outlined and plain labels)."""
    t = T()
    key = (fam, outlined)
    if key in _FAMSTYLE:
        return _FAMSTYLE[key]
    sts = []
    for it in plan_items():
        if it["family"] == fam:
            s = t.measure_style(t.load_png(ROOT / it["png"]), lines=it.get("box", {}).get("lines"))
            sts.append(s)
    sts = [s for s in sts if bool(s.layers) == outlined] or sts
    n = len(sts[0].face_stops)
    stops = []
    for i in range(n):
        c = np.median([np.array(s.face_stops[i][1]) for s in sts if len(s.face_stops) == n], axis=0)
        stops.append((sts[0].face_stops[i][0], tuple(float(v) for v in c)))
    nl = int(np.median([len(s.layers) for s in sts]))
    layers = []
    for k in range(nl):
        ls = [s.layers[k] for s in sts if len(s.layers) > k]
        layers.append(t.Layer(width=float(np.median([l.width for l in ls])),
                              color=tuple(float(v) for v in np.median([l.color for l in ls], axis=0))))
    _FAMSTYLE[key] = (stops, layers)
    return _FAMSTYLE[key]


RENDER_KEYS = ("source", "em", "weight", "hscale", "tracking", "box", "align", "min_hscale", "margin",
               "gap_min", "fit_height", "donors")


def compare_noplate(jp, ko, st_jp):
    """imgtext.compare() with the Korean image measured as a transparent label (plate=False)."""
    t = T()
    orig = t.measure_style

    def ms(rgba, *, plate=None, **kw):
        return orig(rgba, plate=False if plate is None else plate, **kw)

    t.measure_style = ms
    try:
        return t.compare(jp, ko, st_jp)
    finally:
        t.measure_style = orig


def make_one(it: dict, extra: dict | None = None):
    """Draw one texture with imgtext 1.1 redraw(); returns (jp, ko, report). Nothing is written.
    Decoration: the texture's own measured style, with face gradient and outline replaced by the
    family median (same family = same look), unless cfg family_style=False."""
    t = T()
    cfg = dict(CFG.get(it["base"], {}))
    if extra:
        cfg.update(extra)
    jp = t.load_png(ROOT / it["png"])
    text = cfg.get("text", it["ko"])
    lines = cfg.get("lines", len(text.split("\n")))
    st = t.measure_style(jp, lines=lines)
    if cfg.get("family_style", True):
        stops, layers = family_style(it["family"], bool(st.layers))
        st.face_stops = stops
        if st.layers and layers:
            st.layers = layers
    if cfg.get("face"):
        st.face_stops = [(0.0, tuple(cfg["face"])), (1.0, tuple(cfg["face"]))]
    kw = {k: cfg[k] for k in RENDER_KEYS if k in cfg}
    kw.setdefault("source", FAMILY_SOURCE.get(it["family"], "auto"))
    ko, rep = t.redraw(jp, text, fmt=it["fmt"], style=st, jp_text=it.get("jp"), **kw)
    if not st.plate and "compare" in rep:
        # imgtext.compare() re-measures the Korean image with plate=None (auto): a transparent
        # label whose ink covers > 60 % of the texture (쿵쿵 떨어트리기) is then read as a plate
        # and its stroke / outline come out wrong. Re-measure it as what it is: no plate.
        rep["compare"] = compare_noplate(jp, ko, st)
        rep["problems"] = t.verdict(rep["compare"])
    if cfg.get("keep_rows"):
        a, b = cfg["keep_rows"]
        ko = ko.copy()
        ko[a:b] = jp[a:b]
        ko = t.finalize(ko, it["fmt"])
    rep["cfg"] = cfg
    return jp, ko, rep


def write_ko(it: dict, ko: np.ndarray):
    """Write to work/img/ko/lyt/<dat>/<entry>/<name>.png via a temp name + rename."""
    dst = ROOT / it["ko_png"]
    dst.parent.mkdir(parents=True, exist_ok=True)
    tmp = dst.with_name(dst.stem + ".A_tmp.png")
    Image.fromarray(_u8(ko), "RGBA").save(tmp)
    os.replace(tmp, dst)
    return dst


def cmd_make():
    """python lyt_A.py make <kind|family|base>... [--dry] -> writes PNGs + review sheet."""
    args = [{"ka": "가", "na": "나", "da": "다"}.get(a, a) for a in sys.argv[2:] if not a.startswith("--")]
    dry = "--dry" in sys.argv
    sel = [it for it in plan_items()
           if not args or it["kind"] in args or it["family"] in args or it["base"] in args]
    rows, reps = [], {}
    for it in sel:
        jp, ko, rep = make_one(it)
        reps[it["base"]] = {k: rep.get(k) for k in ("sources", "levels", "fit", "em", "weight", "problems", "cfg")}
        if not dry:
            write_ko(it, ko)
        prob = ";".join(rep.get("problems") or [])
        rows.append((f"{it['base']}  {it['ko'].replace(chr(10), '/')}  {rep.get('sources')}  {prob}", jp, ko))
    tag = "_".join(args) if args else "all"
    outdir = SCRATCH if dry else ROOT / "work/img/review"
    outdir.mkdir(parents=True, exist_ok=True)
    pages = review_sheet(rows, outdir / f"A_{tag}{RUN if dry else ''}.png", z=3)
    logp = ROOT / "work/img" / "A_make_log.json"
    old = json.load(open(logp, encoding="utf-8")) if logp.exists() else {}
    if not dry:
        old.update(reps)
        json.dump(old, open(logp, "w", encoding="utf-8"), ensure_ascii=False, indent=1, default=str)
    (SCRATCH / f"A_make_out{RUN}.txt").write_text(
        "\n".join([str(p) for p in pages] + [f"{b}: {r['sources']} w={r['weight']} em={r['em']} fit={r['fit']} {r['problems']}" for b, r in reps.items()]),
        encoding="utf-8")
    print(len(sel))


def cmd_variants():
    """python lyt_A.py variants <base> '<json cfg>' '<json cfg>' ... -> scratch A_var_<base>.png"""
    base = sys.argv[2]
    it = next(i for i in plan_items() if i["base"] == base)
    rows = []
    lines = []
    for spec in sys.argv[3:] or ["{}"]:
        extra = {}
        for kv in filter(None, spec.split(",")):
            k, v = kv.split("=", 1)
            try:
                extra[k] = json.loads(v)
            except Exception:
                extra[k] = v
        jp, ko, rep = make_one(it, extra)
        rows.append((f"{spec} {rep.get('weight')} {rep.get('problems')}", jp, ko))
        lines.append(f"{spec}: src={rep.get('sources')} wd={rep.get('weight_delta_px')} gs={rep.get('glyph_stroke_px')} "
                     f"fit={rep.get('fit')} {rep.get('problems')} sum={rep.get('compare', {}).get('summary')}")
    review_sheet(rows, SCRATCH / f"A_var_{base}{RUN}.png", z=5)
    (SCRATCH / f"A_var_{base}{RUN}.txt").write_text("\n".join(lines), encoding="utf-8")


def cmd_sheets():
    """Review sheets from the saved Korean PNGs: work/img/review/A_<family>[_n].png (<=1600 px),
    JP | KO at 1x and 3x on blue and grey. Also checks that every replace texture has its PNG."""
    rows_by = {}
    missing = []
    for it in plan_items():
        p = ROOT / it["ko_png"]
        if not p.exists():
            missing.append(it["base"])
            continue
        jp = load(it["png"])
        ko = np.asarray(Image.open(p).convert("RGBA"))
        if ko.shape != jp.shape:
            missing.append(it["base"] + " (size)")
        rows_by.setdefault(it["family"], []).append((f"{it['base']}  {it['ko'].replace(chr(10), '/')}", jp, ko))
    out = []
    for fam in FAMS:
        if fam in rows_by:
            out += review_sheet(rows_by[fam], ROOT / "work/img/review" / f"A_{fam}.png", z=3)
    (SCRATCH / f"A_sheets{RUN}.txt").write_text("\n".join([str(p) for p in out] + ["missing: " + repr(missing)]),
                                               encoding="utf-8")
    print(len(out), len(missing))


def cmd_overview():
    """One look at every family: JP 2x | KO 2x pairs flowed into rows (<=1600 px pages)
    -> work/img/review/A_overview[_n].png. For checking that a family looks the same."""
    from PIL import ImageDraw
    z, maxw, maxh = 2, 1600, 1600
    tiles = []
    for fam in FAMS:
        mem = [it for it in plan_items() if it["family"] == fam]
        if not mem:
            continue
        tiles.append(("FAM", fam))
        for it in mem:
            jp = _on(load(it["png"]), (60, 120, 200))
            ko = _on(np.asarray(Image.open(ROOT / it["ko_png"]).convert("RGBA")), (60, 120, 200))
            w, h = jp.size
            tile = Image.new("RGB", (2 * w * z + 6, h * z + 4), (32, 32, 32))
            tile.paste(jp.resize((w * z, h * z), Image.NEAREST), (0, 2))
            tile.paste(ko.resize((w * z, h * z), Image.NEAREST), (w * z + 4, 2))
            tiles.append(("T", tile))
    pages, cur, x, y, rowh = [], Image.new("RGB", (maxw, maxh), (20, 20, 20)), 0, 0, 0
    d = ImageDraw.Draw(cur)
    used = 0
    for kind, v in tiles:
        if kind == "FAM":
            x, y, rowh = 0, y + rowh + (6 if used else 0), 0
            if y + 16 > maxh:
                pages.append(cur.crop((0, 0, maxw, used))); cur = Image.new("RGB", (maxw, maxh), (20, 20, 20))
                d = ImageDraw.Draw(cur); y = 0
            d.text((2, y), v, fill=(255, 230, 120)); y += 14; used = y
            continue
        if x + v.width > maxw:
            x, y, rowh = 0, y + rowh + 2, 0
        if y + v.height > maxh:
            pages.append(cur.crop((0, 0, maxw, used))); cur = Image.new("RGB", (maxw, maxh), (20, 20, 20))
            d = ImageDraw.Draw(cur); x, y, rowh = 0, 0, 0
        cur.paste(v, (x, y)); x += v.width + 6; rowh = max(rowh, v.height); used = max(used, y + v.height)
    pages.append(cur.crop((0, 0, maxw, used)))
    outs = []
    for i, pg in enumerate(pages, 1):
        q = ROOT / "work/img/review" / (f"A_overview_{i}.png" if len(pages) > 1 else "A_overview.png")
        pg.save(q); outs.append(str(q))
    (SCRATCH / f"A_overview{RUN}.txt").write_text("\n".join(outs), encoding="utf-8")
    print(len(outs))


if __name__ == "__main__":
    {"analyze": cmd_analyze, "measure": cmd_measure, "sources": cmd_sources, "try": cmd_try,
     "make": cmd_make, "variants": cmd_variants, "sheets": cmd_sheets, "overview": cmd_overview}[sys.argv[1]]()
