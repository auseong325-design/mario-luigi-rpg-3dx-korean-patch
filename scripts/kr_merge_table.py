"""Merge independent glyph transcriptions into work/kr_font/kr_table.json.

Rules: two readers agree -> accepted; disagreement or single reading -> listed in
work/kr_font/kr_table_review.json for a decision. Manual decisions live in
work/kr_font/kr_table_overrides.json ({"main:041": "A", "rep:12F": "뷁"}) and win over readers.
"""

from __future__ import annotations

import json
import sys
from collections import defaultdict

from libnds_kr import ROOT

BASE = ROOT / "work" / "kr_font"
READ = BASE / "read" / "transcripts"


def main() -> int:
    readings: dict[str, dict[str, str]] = defaultdict(dict)
    unsure: dict[str, list[str]] = defaultdict(list)
    for f in READ.glob("*/*.json"):
        j = json.loads(f.read_text(encoding="utf-8"))
        space = j["sheet"].split("_")[0]
        for code, ch in j["cells"].items():
            readings[f"{space}:{code.upper()}"][f.parent.name] = ch
        for code, note in (j.get("unsure") or {}).items():
            unsure[f"{space}:{code.upper()}"].append(f"{f.parent.name}: {note}")
    overrides = {}
    ov_path = BASE / "kr_table_overrides.json"
    if ov_path.exists():
        overrides = json.loads(ov_path.read_text(encoding="utf-8"))
    index = json.loads((BASE / "read" / "index.json").read_text(encoding="utf-8"))
    expected = {f"{s.split('_')[0]}:{c}" for s, codes in index.items() for c in codes}

    table: dict[str, dict[str, str]] = {"main": {}, "rep": {}}
    review = {}
    for key in sorted(expected):
        space, code = key.split(":")
        votes = readings.get(key, {})
        values = set(votes.values())
        if key in overrides:
            table[space][code] = overrides[key]
        elif len(votes) >= 2 and len(values) == 1:
            table[space][code] = values.pop()
        elif votes:
            table[space][code] = sorted(votes.values())[0]
            review[key] = {"votes": votes, "unsure": unsure.get(key, [])}
        else:
            review[key] = {"votes": {}, "unsure": ["no reading yet"]}
    (BASE / "kr_table.json").write_text(json.dumps(table, ensure_ascii=False, indent=0), encoding="utf-8")
    (BASE / "kr_table_review.json").write_text(json.dumps(review, ensure_ascii=False, indent=1), encoding="utf-8")
    agreed = sum(len(v) for v in table.values()) - len(review)
    print(f"codes expected {len(expected)} | accepted (2 agreeing readers or override) {agreed} | "
          f"needs review {len(review)}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
