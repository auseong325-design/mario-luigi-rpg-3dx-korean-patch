"""FONT2: width checks for the v2 fonts (read-only). Writes v2_width_check.txt.

1. Real pixel width of every Korean line in the font the game draws it with (style -> font as MessageSimple::GetFont,
   13/255 -> both), shipped vs v1 vs v2, against the widest Japanese line of the same (source, style) in the original
   3DX font (box proxy, as real_width.py).
2. scripts/merge_ko.py width model with the v2 advance table (v2/merge_ko_ascii_widths.json): lines over limit.
3. HugeBattle.msbt lines (HB layout TextBoxes, font.bffnt, 240 px boxes): shipped vs v2.
4. Runtime numbers drawn with these fonts. Only one number variable is formatted with ASCII digits
   (Battle FUN_11027d84 -> FUN_11028778(..., 1, level, 0): BMsg/b_sys#1215 MonName_Lv '{name} LV{level}', style 0 =
   font_btl); every other setNum call passes the full-width flag (digits U+FF10..FF19, glyphs not changed). Widest
   realistic value: longest monster name + ' LV' + '100', v2 vs shipped vs the Japanese original's widest.
"""
from __future__ import annotations

import json
import re
import sys
from collections import defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from real_width import STYLE_FONT, adv_table, lines_of  # noqa: E402
from render import ROOT, Font, get_font  # noqa: E402

sys.path.insert(0, str(ROOT / "scripts"))
import merge_ko as M  # noqa: E402

V1 = ROOT / "work/build/menu_font_stage/romfs/Msg/JP_ja"
V2 = ROOT / "work/build/menu_font_stage/v2/romfs/Msg/JP_ja"
V2_WIDTHS = ROOT / "work/build/menu_font_stage/v2/merge_ko_ascii_widths.json"
OUT = ROOT / "work/review/menu_fonts_20261030/v2_width_check.txt"


def main():
    gz = get_font("gaizi")
    W = {}
    for fn in ("font", "font_btl"):
        W[("jp", fn)] = adv_table(get_font(f"jp:{fn}"), gz)
        W[("ship", fn)] = adv_table(get_font(f"ko:{fn}"), gz)
        W[("v1", fn)] = adv_table(Font(f"v1:{fn}", (V1 / f"{fn}.bffnt").read_bytes()), gz)
        W[("v2", fn)] = adv_table(Font(f"v2:{fn}", (V2 / f"{fn}.bffnt").read_bytes()), gz)
    ko = json.loads((ROOT / "work/ko_final.json").read_text("utf-8"))
    jp_msgs = {}
    for f in (ROOT / "text/jp").glob("*.json"):
        for m in json.loads(f.read_text("utf-8"))["messages"]:
            jp_msgs[m["id"]] = m
    out = []
    # 1. real widths
    jpmax = defaultdict(int)
    work = []
    for mid, m in jp_msgs.items():
        st = m["style"]
        fonts = [STYLE_FONT.get(st, "font")] if st not in (13, 255) else ["font", "font_btl"]
        key = (mid.split("/")[0].split("#")[0], st)
        for fn in fonts:
            if fn == "font_l":
                continue
            for ln in lines_of(m["jp"]):
                jpmax[(key, fn)] = max(jpmax[(key, fn)], W[("jp", fn)](ln))
            if mid in ko:
                for ln in lines_of(ko[mid]):
                    work.append((mid, key, fn, ln))
    out.append(f"## 1. real widths: {len(work)} (line, font) pairs")
    for tag in ("ship", "v1", "v2"):
        over = [(mid, fn, ln) for mid, key, fn, ln in work if W[(tag, fn)](ln) > jpmax[(key, fn)]]
        out.append(f"  {tag}: lines wider than the widest JP line of their (source, style): {len(over)}")
        for mid, fn, ln in over[:5]:
            out.append(f"      {mid} {fn}: {ln!r}")
    newly = [(mid, key, fn, ln) for mid, key, fn, ln in work
             if W[("v2", fn)](ln) > jpmax[(key, fn)] >= W[("ship", fn)](ln)]
    out.append(f"  v2 newly over vs shipped: {len(newly)}")
    for d_tag in ("ship", "v1"):
        ch = [(W[("v2", fn)](ln) - W[(d_tag, fn)](ln), mid, fn, ln) for mid, key, fn, ln in work]
        grow = sorted(ch, reverse=True)
        shrink = sorted(ch)
        n_grow = sum(1 for c in ch if c[0] > 0)
        n_shr = sum(1 for c in ch if c[0] < 0)
        out.append(f"  v2 vs {d_tag}: wider {n_grow}, narrower {n_shr}; max growth {grow[0][0]:+d} px, "
                   f"max shrink {shrink[0][0]:+d} px")
        for d, mid, fn, ln in grow[:6]:
            if d > 0:
                out.append(f"      {d:+d}px {mid} {fn}: {ln!r}")
    # tightest lines (smallest headroom) among lines that contain letters/digits, v2
    head = sorted((jpmax[(key, fn)] - W[("v2", fn)](ln), mid, fn, ln) for mid, key, fn, ln in work
                  if re.search(r"[A-Za-z0-9]", ln))
    out.append("  smallest headroom (JP max - v2 width) among lines with letters/digits:")
    for h, mid, fn, ln in head[:8]:
        out.append(f"      {h:+d}px {mid} {fn}: {ln!r}")
    # 2. merge_ko model
    adv0, _ = M.charset()
    adv2 = dict(adv0)
    adv2.update(json.loads(V2_WIDTHS.read_text("utf-8"))["font"])
    limits = M.group_limits()
    rows = []
    for bid in M.all_batches():
        batch, kob = M.load_batch(bid)
        if not kob:
            continue
        tr = kob.get("translations", {})
        for m in batch["messages"]:
            t = tr.get(m["id"])
            if not isinstance(t, str):
                continue
            key = (m["id"].split("/")[0].split("#")[0], m["style"])
            lim = limits.get(key, {"max_w": 336})["max_w"]
            for page in M.pages(t):
                for ln in page:
                    if ln.strip():
                        rows.append((m["id"], key, lim, ln))
    w0 = lambda s: sum(adv0.get(c, 16) for c in s)  # noqa: E731
    w2 = lambda s: sum(adv2.get(c, 16) for c in s)  # noqa: E731
    over0 = sum(1 for _, _, lim, ln in rows if w0(ln) > lim)
    over2 = [(mid, key, lim, w2(ln), ln) for mid, key, lim, ln in rows if w2(ln) > lim]
    out.append(f"\n## 2. merge_ko model: {len(rows)} translator lines; over limit: current model {over0}, "
               f"with v2 advances {len(over2)}")
    for r in over2[:10]:
        out.append(f"      OVER {r}")
    d = sorted(((w2(ln) - w0(ln), mid, ln) for mid, key, lim, ln in rows), reverse=True)
    out.append(f"  v2 vs current model: max growth {d[0][0]:+d} px ({d[0][1]} {d[0][2]!r}); "
               f"lines wider {sum(1 for x in d if x[0] > 0)}, narrower {sum(1 for x in d if x[0] < 0)}")
    out.append("  v2 advances that differ from the current model: " + json.dumps(
        json.loads(V2_WIDTHS.read_text("utf-8"))["font"], ensure_ascii=False))
    # 3. HugeBattle
    hb = json.loads((ROOT / "text/jp/HugeBattle.json").read_text("utf-8"))["messages"]
    hb_jpmax = max((W[("jp", "font")](ln) for m in hb for ln in lines_of(m["jp"])), default=0)
    out.append(f"\n## 3. HugeBattle (font.bffnt, TextBox 240 px; widest JP line {hb_jpmax} px)")
    worst = 0
    for m in hb:
        for ln in lines_of(ko.get(m["id"], "")):
            a, b, c = W[("ship", "font")](ln), W[("v1", "font")](ln), W[("v2", "font")](ln)
            worst = max(worst, c)
            if a != c and re.search(r"[A-Za-z0-9]", ln):
                out.append(f"  {m['id']} {m['label']}: shipped {a} / v1 {b} / v2 {c} px: {ln!r}")
    out.append(f"  widest HugeBattle Korean line with v2: {worst} px (box 240)")
    # 4. runtime numbers: MonName_Lv
    names = []
    for mid, m in jp_msgs.items():
        lab = m.get("label") or ""
        if mid.startswith("BMsg/") and m["style"] == 13 and "_" not in lab.rstrip("_x").replace("_x", "") \
                and re.fullmatch(r"[A-Z][A-Za-z0-9_]*", lab) and mid in ko:
            jl, kl = lines_of(m["jp"]), lines_of(ko[mid])
            if len(jl) == 1 and len(kl) == 1:
                names.append((mid, lab, jl[0], kl[0]))
    out.append(f"\n## 4. runtime number MonName_Lv (BMsg/b_sys#1215 '{{name}} LV{{level}}', font_btl), {len(names)} "
               f"battle names")
    for tag, idx, fnk in (("JP original", 2, "jp"), ("KO shipped", 3, "ship"), ("KO v1", 3, "v1"), ("KO v2", 3, "v2")):
        best = max(names, key=lambda x: W[(fnk, "font_btl")](x[idx]))
        for lv in ("99", "100"):
            s = f"{best[idx]} LV{lv}"
            out.append(f"  {tag:12s} widest: {W[(fnk, 'font_btl')](s):4d} px  {s!r} ({best[0]})")
    lv = {tag: W[(fnk, "font_btl")](" LV100") for tag, fnk in (("ship", "ship"), ("v1", "v1"), ("v2", "v2"))}
    out.append(f"  ' LV100' alone: shipped {lv['ship']} px, v1 {lv['v1']} px, v2 {lv['v2']} px")
    # full-width digits present (all other runtime numbers use them)
    f2 = Font("v2:font", (V2 / "font.bffnt").read_bytes())
    fb = Font("v2:font_btl", (V2 / "font_btl.bffnt").read_bytes())
    fw = "".join(chr(0xFF10 + i) for i in range(10))
    out.append(f"  full-width digits U+FF10..FF19 in v2 font: {all(f2.has(c) for c in fw)}, font_btl: "
               f"{all(fb.has(c) for c in fw)} (unchanged 3DX glyphs, advance "
               f"{f2.glyph(0xFF10)[3]} / {fb.glyph(0xFF10)[3]} px)")
    txt = "\n".join(out)
    OUT.write_text(txt, "utf-8")
    print(txt)


if __name__ == "__main__":
    main()
