"""imgtext_demo -- the required demonstration set of IMAGE_TASK.md 5 / I2 (and a few extra
families), drawn with imgtext and put next to the Japanese originals.

    python scripts/imgtext_demo.py [--only name,name] [--tag v2]
      -> work/img/toolkit/demo/<name>.png, demo/_report.json,
         review sheets work/img/review/I2_demo[_NN].png (<= 1600 px per side)
Korean words come from work/img/lyt_plan.json (`ko`) or, for HB, work/img/hb_plan.json.
"""
from __future__ import annotations

import json
import sys
import time
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import imgtext as T  # noqa: E402

ROOT = T.ROOT
DEMO = T.TOOLKIT / "demo"

# name -> render overrides (after looking at the review sheets)
REQUIRED = {
    "btn_USE_00_JP_ja": {},
    "btn_cancel_00_JP_ja": {},
    "RANK_NAME_STAR_00_JP_ja": {},
    "LTIT_btl_HINT_00_JP_ja": {},
    "btn_KJ_LA_12_00_JP_ja": {},
    "STbr_BP_00_JP_ja": {"donors": [(str(ROOT / "work/img/lyt/3DX/BLyt/btl_RESLT_LYT_JP_ja/STbr_BP_00_JP_ja.png"), "BP"),
                                     (str(ROOT / "work/img/lyt/3DX/BLyt/btl_RESLT_LYT_JP_ja/STbr_SPEED_00_JP_ja.png"), "SPEED")]},
    "LTIT_ITEM_00_JP_ja": {},
    "SHOP_TIT_BADGE_00_JP_ja": {},
    "btn_F_MAP_OPEN_00_JP_ja": {},
    "KJ_TYPE_02_00_JP_ja": {},
}
# large giant-battle lettering (I6): the case the size rule of IMAGE_TASK.md 1 is about
HB = {
    "ja_slide_text": {},
    "ja_modoru_text": {},
    "ja_renzoku_slide_text": {},
    "ja_sentaku_yes": {},
}


def items():
    plan = json.loads((ROOT / "work/img/lyt_plan.json").read_text(encoding="utf-8"))
    by = {it["base"]: it for it in plan["items"]}
    for n, kw in REQUIRED.items():
        it = by[n]
        yield n, ROOT / it["png"], it["ko"], it["fmt"], {"jp_text": it.get("jp"), **kw}
    hp = ROOT / "work/img/hb_plan.json"
    if hp.exists():
        hb = {i["name"]: i for i in json.loads(hp.read_text("utf-8"))["items"]}
        for n, kw in HB.items():
            if n in hb:
                it = hb[n]
                yield n, ROOT / it["png"], it["ko"], it["fmt"], {"jp_text": it.get("jp"), **kw}


def main(argv):
    only = None
    tag = ""
    if "--only" in argv:
        only = set(argv[argv.index("--only") + 1].split(","))
    if "--tag" in argv:
        tag = "_" + argv[argv.index("--tag") + 1]
    force = {}
    if "--source" in argv:          # comparison runs: same set, one glyph source for all
        force["source"] = argv[argv.index("--source") + 1]
    DEMO.mkdir(parents=True, exist_ok=True)
    rp = DEMO / "_report.json"
    report = json.loads(rp.read_text("utf-8")) if rp.exists() else {}
    rows = []
    for name, png, ko, fmt, kw in items():
        if only and name not in only:
            continue
        t0 = time.time()
        kw = {**kw, **force}
        jp = T.load_png(png)
        out, rep = T.redraw(jp, ko, fmt=fmt, **kw)
        if not force:
            T.save_png(out, DEMO / f"{name}.png")
        report[name] = {"ko": ko, "fmt": fmt, "overrides": kw, "sources": rep.get("sources"),
                        "fit": rep.get("fit"), "weight": rep.get("weight"),
                        "summary": rep["compare"]["summary"], "problems": rep["problems"],
                        "sec": round(time.time() - t0, 1)}
        rows.append((f"{name} ({fmt}) -> {ko}  {rep.get('sources')}", [jp, out]))
        print(name, rep.get("sources"), rep["problems"], flush=True)
    if not force:
        rp.write_text(json.dumps(report, ensure_ascii=False, indent=1, default=str), "utf-8")
    if rows:
        print(T.make_sheet(rows, ROOT / f"work/img/review/I2_demo{tag}.png", zoom=3))


def smoke(limit: int | None = None) -> None:
    """Run redraw() with default settings on every `replace` texture of lyt_plan.json and
    hb_plan.json (no overrides): catches crashes and lists what the checks flag.
    -> work/img/toolkit/demo/_smoke.json and sheets work/img/review/I2_smoke_NN.png"""
    plan = json.loads((ROOT / "work/img/lyt_plan.json").read_text(encoding="utf-8"))
    todo = [(it["base"], ROOT / it["png"], it["ko"], it["fmt"], it.get("family", ""), it.get("jp")) for it in plan["items"]
            if it.get("action") == "replace" and it.get("ko") and it.get("family") != "logo"]
    hp = ROOT / "work/img/hb_plan.json"
    if hp.exists():
        todo += [(i["name"], ROOT / i["png"], i["ko"], i["fmt"], "hb", i.get("jp"))
                 for i in json.loads(hp.read_text("utf-8"))["items"] if i["action"] == "replace" and "dup_of" not in i]
    todo.sort(key=lambda x: (x[4], x[0]))
    if limit:
        todo = todo[:limit]
    res, rows = {}, []
    for name, png, ko, fmt, fam, jpt in todo:
        t0 = time.time()
        try:
            jp = T.load_png(png)
            out, rep = T.redraw(jp, ko, fmt=fmt, jp_text=jpt)
            res[name] = {"family": fam, "ko": ko, "levels": rep.get("levels"), "sources": rep.get("sources"),
                         "weight_ratio": rep["weight"]["ratio"], "fit": rep["fit"], "problems": rep["problems"],
                         "sec": round(time.time() - t0, 2)}
            rows.append((f"[{fam}] {name} -> {ko.replace(chr(10), ' / ')}  w={rep['weight']['ratio']}", [jp, out]))
        except Exception as e:  # noqa: BLE001 - report, keep going
            import traceback
            res[name] = {"family": fam, "ko": ko, "error": repr(e), "trace": traceback.format_exc()[-800:]}
        print(name, res[name].get("error") or res[name]["problems"], flush=True)
    (DEMO / "_smoke.json").write_text(json.dumps(res, ensure_ascii=False, indent=1, default=str), "utf-8")
    if rows:
        T.make_sheet(rows, ROOT / "work/img/review/I2_smoke.png", zoom=2)


if __name__ == "__main__":
    if "--smoke" in sys.argv:
        DEMO.mkdir(parents=True, exist_ok=True)
        smoke(int(sys.argv[sys.argv.index("--smoke") + 1]) if len(sys.argv) > sys.argv.index("--smoke") + 1 else None)
    else:
        main(sys.argv[1:])
