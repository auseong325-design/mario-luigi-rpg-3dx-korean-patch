"""C group driver (2차 C: battle_btn, rank_name, stat_en, panel_label, field_btn, minigame_btn,
result_banner). stat_en is made by scripts/lyt_C_stat.py (3DX pixel letters); the Korean
families go through imgtext.

    python scripts/lyt_C.py list      -> work/img/C_tmp/items.json (the 36 replace items)
    python scripts/lyt_C.py make [family|base,...] -> work/img/ko/lyt/... + work/img/C_make_report.json + review/C_<family>.png
    python scripts/lyt_C.py measure   -> work/img/C_measure.json (imgtext.measure_style per item)
"""
from __future__ import annotations

import json
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "scripts"))
TMP = ROOT / "work/img/C_tmp"          # scratch (list/try); reports go to work/img/C_*.json
FAMS = ["battle_btn", "rank_name", "stat_en", "panel_label", "field_btn", "minigame_btn", "result_banner"]


def items():
    p = json.loads((ROOT / "work/img/lyt_plan.json").read_text("utf-8"))
    return [it for it in p["items"] if it.get("family") in FAMS and it["action"] == "replace"]


def cmd_list():
    its = items()
    (TMP / "items.json").write_text(json.dumps(its, ensure_ascii=False, indent=1), "utf-8")
    print(len(its))


def cmd_measure():
    import imgtext as T
    out = {}
    for it in items():
        if it["family"] == "stat_en":
            continue
        jp = T.load_png(ROOT / it["png"])
        kw = {}
        if it["box"].get("lines", 1) > 1:
            kw["lines"] = it["box"]["lines"]
        try:
            st = T.measure_style(jp, **kw)
            out[it["base"]] = {"family": it["family"], "fmt": it["fmt"], "w": it["w"], "h": it["h"],
                               "jp": it["jp"], "ko": it["ko"], "style": st.to_json()}
        except Exception as e:  # noqa: BLE001
            out[it["base"]] = {"error": repr(e)}
    (ROOT / "work/img/C_measure.json").write_text(json.dumps(out, ensure_ascii=False, indent=1), "utf-8")


def cmd_try():
    """quick trial of imgtext on a few items -> work/img/C_tmp/try/ (not the ko folder)."""
    import imgtext as T
    names = sys.argv[2].split(",") if len(sys.argv) > 2 else ["btn_cancel_00_JP_ja", "RANK_NAME_STAR_00_JP_ja"]
    rep = {}
    by = {it["base"]: it for it in items()}
    pairs = []
    for n in names:
        it = by[n]
        jp = T.load_png(ROOT / it["png"])
        kw = {}
        if it["box"].get("lines", 1) > 1:
            kw["lines"] = it["box"]["lines"]
        ko, r = T.redraw(jp, it["ko"], fmt=it["fmt"], **kw)
        T.save_png(ko, TMP / "try" / f"{n}.png")
        rep[n] = {"sources": r.get("sources"), "fit": r.get("fit"), "problems": r.get("problems"),
                  "compare": r.get("compare")}
        pairs.append((n, jp, ko))
    rgba_sheet(pairs, TMP / "try" / "sheet.png")
    (TMP / "try" / "rep.json").write_text(json.dumps(rep, ensure_ascii=False, indent=1, default=str), "utf-8")


def rgba_sheet(pairs, out, zoom=3, bg=(59, 120, 199)):
    """[(label, jp_rgba float, ko_rgba float)] -> sheet(s) <= 1600 px: jp | ko at 1x, then jp | ko at zoom."""
    import numpy as np
    from PIL import Image, ImageDraw
    tiles = []
    for label, jp, ko in pairs:
        h, w = jp.shape[:2]
        z = zoom
        while w * z * 2 + w * 2 + 40 > 1600 and z > 1:
            z -= 1
        tw = w * 2 + 24 + w * z * 2 + 16
        tile = Image.new("RGB", (tw, h * z + 20), (40, 40, 40))
        d = ImageDraw.Draw(tile)
        d.text((4, 2), label, fill=(255, 220, 90))

        def flat(a):
            a = np.asarray(a, dtype=np.float64)
            al = a[..., 3:4]
            return Image.fromarray(np.clip((a[..., :3] * al + np.asarray(bg) / 255 * (1 - al)) * 255 + .5, 0, 255)
                                   .astype(np.uint8))
        x = 4
        for a in (jp, ko):
            tile.paste(flat(a), (x, 18))
            x += w + 8
        for a in (jp, ko):
            tile.paste(flat(a).resize((w * z, h * z), Image.NEAREST), (x, 18))
            x += w * z + 8
        tiles.append(tile)
    # pack into pages <= 1600x1600
    pages, cur, hh = [], [], 0
    for t in tiles:
        if cur and hh + t.height + 4 > 1600:
            pages.append(cur)
            cur, hh = [], 0
        cur.append(t)
        hh += t.height + 4
    if cur:
        pages.append(cur)
    outs = []
    out = Path(out)
    for i, pg in enumerate(pages):
        W = max(t.width for t in pg)
        H = sum(t.height + 4 for t in pg)
        img = Image.new("RGB", (W, H), (30, 30, 30))
        y = 0
        for t in pg:
            img.paste(t, (0, y))
            y += t.height + 4
        assert W <= 1600 and H <= 1600
        p = out if len(pages) == 1 else out.with_name(f"{out.stem}_{i + 1}{out.suffix}")
        img.save(p)
        outs.append(p)
    return outs


FAMILY_STYLE = {"rank_name": "RANK_NAME_STAR_00_JP_ja"}   # one measured style for the whole family
OVERRIDE = {   # base -> extra redraw kwargs
    "btn_MGAME_pnl1_00_jp_ja": {"source": "font"},   # same source as pnl2 (bank 보스 broke at em 11.5)
}
FAMILY_KW = {"rank_name": {"em": 13.0, "box": (12, 0, 116, 42)}}


def cmd_make():
    """Korean families -> work/img/ko/lyt/<dat>/<entry>/<name>.png (+ report, review sheets)."""
    import os
    import imgtext as T
    only = sys.argv[2].split(",") if len(sys.argv) > 2 else None
    its = [it for it in items() if it["family"] != "stat_en"]
    by = {it["base"]: it for it in its}
    styles = {}
    for fam, rep_base in FAMILY_STYLE.items():
        styles[fam] = T.measure_style(T.load_png(ROOT / by[rep_base]["png"]))
    rpt_path = ROOT / "work/img/C_make_report.json"
    report = json.loads(rpt_path.read_text("utf-8")) if rpt_path.exists() else {}
    pairs = {}
    for it in its:
        if only and it["base"] not in only and it["family"] not in only:
            continue
        jp = T.load_png(ROOT / it["png"])
        kw = dict(OVERRIDE.get(it["base"], {}))
        if it["box"].get("lines", 1) > 1 and "style" not in kw:
            kw["lines"] = it["box"]["lines"]
        for k, v in FAMILY_KW.get(it["family"], {}).items():
            kw.setdefault(k, v)
        if it["family"] in styles and "style" not in kw:
            kw["style"] = styles[it["family"]]
        ko, r = T.redraw(jp, it["ko"], fmt=it["fmt"], jp_text=it["jp"], **kw)
        out = ROOT / it["ko_png"]
        out.parent.mkdir(parents=True, exist_ok=True)
        tmp = out.with_name(out.stem + ".tmp_C.png")
        T.save_png(ko, tmp)
        os.replace(tmp, out)
        report[it["base"]] = {"family": it["family"], "ko": it["ko"], "out": it["ko_png"],
                              "sources": r.get("sources"), "levels": r.get("levels"), "fit": r.get("fit"),
                              "weight": r.get("weight"), "problems": r.get("problems"),
                              "kw": {k: v for k, v in kw.items() if k != "style"}}
        pairs.setdefault(it["family"], []).append((it["base"], jp, ko))
    rpt_path.write_text(json.dumps(report, ensure_ascii=False, indent=1, default=str), "utf-8")
    for fam, ps in pairs.items():
        rgba_sheet(ps, ROOT / "work/img/review" / f"C_{fam}.png")


if __name__ == "__main__":
    {"list": cmd_list, "measure": cmd_measure, "try": cmd_try, "make": cmd_make}[sys.argv[1]]()
