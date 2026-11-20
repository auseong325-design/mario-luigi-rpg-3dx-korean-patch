"""Census of Latin letters / digits inside Korean menu strings (Item / Menu / MenuKJ), per label family.
Writes latin_census.txt (FONT worker, read-only)."""
from __future__ import annotations

import json
import re
import sys
from collections import Counter, defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from render import ROOT, visible  # noqa: E402

LAT = re.compile(r"[A-Za-z0-9]")


def main():
    ko = json.loads((ROOT / "work/ko_final.json").read_text("utf-8"))
    out = []
    tot = Counter()
    chars = Counter()
    fam_rows = defaultdict(list)
    for src in ("Item", "Menu", "MenuKJ"):
        for m in json.loads((ROOT / f"text/jp/{src}.json").read_text("utf-8"))["messages"]:
            k = ko.get(m["id"])
            if not k:
                continue
            v = visible(k)
            v = re.sub(r"[\uE000-\uF8FF]", "", v)
            lat = LAT.findall(v)
            has_h = any(0xAC00 <= ord(c) <= 0xD7A3 for c in v)
            fam = m["label"].split("_")[0]
            tot[(src, fam, "all")] += 1
            if lat:
                tot[(src, fam, "latin")] += 1
                if has_h:
                    tot[(src, fam, "mixed")] += 1
                chars.update(lat)
                fam_rows[(src, fam, m["style"])].append((m["id"], m["label"], v.replace("\n", " / ")))
    out.append("# Latin letters/digits in Korean menu strings")
    out.append("src fam: all / with latin / mixed with Hangul")
    for (src, fam, kind), n in sorted(tot.items()):
        if kind == "all":
            out.append(f"{src:6s} {fam:12s} {n:4d} / {tot[(src, fam, 'latin')]:4d} / {tot[(src, fam, 'mixed')]:4d}")
    out.append("")
    out.append("chars: " + " ".join(f"{c}:{n}" for c, n in chars.most_common()))
    out.append("")
    for (src, fam, st), rows in sorted(fam_rows.items()):
        out.append(f"== {src} {fam} style {st}: {len(rows)}")
        for mid, lab, v in rows[:400]:
            out.append(f"  {mid:12s} {lab:40s} {v}")
    txt = "\n".join(out)
    (ROOT / "work/review/menu_fonts_20261030/latin_census.txt").write_text(txt, "utf-8")
    print("\n".join(out[:40]))


if __name__ == "__main__":
    main()
