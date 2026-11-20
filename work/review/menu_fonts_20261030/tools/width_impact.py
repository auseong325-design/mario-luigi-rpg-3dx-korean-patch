"""Line-width impact of giving Latin letters / digits other advances (FONT worker, read-only).

Uses scripts/merge_ko.py itself (width model, per (source, style) JP limits, translator views of every
batch) and recomputes each Korean line with the candidate advances. Reports lines that would newly exceed
the merge_ko limit and the largest growth. Writes width_impact.txt.
"""
from __future__ import annotations

import json
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[4]
sys.path.insert(0, str(ROOT / "scripts"))
sys.path.insert(0, str(Path(__file__).resolve().parent))
import merge_ko as M  # noqa: E402
from render import get_font  # noqa: E402

LATIN = [chr(c) for c in range(0x30, 0x3A)] + [chr(c) for c in range(0x41, 0x5B)] + [chr(c) for c in range(0x61, 0x7B)]


def candidate_adv(kind: str) -> dict[str, int]:
    adv, _ = M.charset()
    out = dict(adv)
    if kind == "1dx_latin":
        f = get_font("1dx:font")
        for ch in LATIN:
            if f.has(ch):
                out[ch] = f.glyph(ord(ch))[3]
    elif kind == "staged":           # every ASCII advance as in the staged font.bffnt
        from render import Font
        f = Font("staged", (ROOT / "work/build/menu_font_stage/romfs/Msg/JP_ja/font.bffnt").read_bytes())
        for c in range(0x21, 0x7F):
            ch = chr(c)
            if f.has(ch):
                out[ch] = f.glyph(c)[3]
    elif kind.startswith("plus"):
        n = int(kind[4:])
        for ch in LATIN:
            out[ch] = adv[ch] + n
    return out


def main():
    kinds = sys.argv[1:] or ["1dx_latin", "plus1"]
    limits = M.group_limits()
    msgs = M.jp_messages()
    rows = []
    for bid in M.all_batches():
        batch, ko = M.load_batch(bid)
        if not ko:
            continue
        tr = ko.get("translations", {})
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
    out = [f"{len(rows)} Korean lines checked (all batches, translator view, merge_ko width model)"]
    adv0, _ = M.charset()
    w0 = lambda s: sum(adv0.get(c, 16) for c in s)  # noqa: E731
    base_over = {(mid, ln) for mid, key, lim, ln in rows if w0(ln) > lim}
    out.append(f"current model: {len(base_over)} lines over their limit (should be 0)")
    for kind in kinds:
        adv = candidate_adv(kind)
        w1 = lambda s: sum(adv.get(c, 16) for c in s)  # noqa: E731
        grow = sorted(((w1(ln) - w0(ln), mid, key, lim, ln) for mid, key, lim, ln in rows), reverse=True)
        new_over = [(mid, key, lim, w1(ln), ln) for mid, key, lim, ln in rows if w1(ln) > lim and (mid, ln) not in base_over]
        latin_lines = sum(1 for g in grow if g[0] > 0)
        out.append(f"\n== {kind}: lines that grow {latin_lines}, max growth {grow[0][0]} px; new over-limit lines {len(new_over)}")
        for mid, key, lim, w, ln in new_over[:80]:
            out.append(f"  OVER {mid} {key} limit {lim} -> {w}: {ln!r}")
        for g in grow[:10]:
            out.append(f"  grow +{g[0]} {g[1]} {g[2]} limit {g[3]}: {g[4]!r}")
    txt = "\n".join(out)
    (ROOT / "work/review/menu_fonts_20261030/width_impact.txt").write_text(txt, "utf-8")
    print(txt)


if __name__ == "__main__":
    main()
