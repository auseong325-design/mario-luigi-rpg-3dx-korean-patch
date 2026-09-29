"""Merge subagent outputs into the shared reference files.

  text/align/parts/room_map_*.json  -> text/align/room_map.json   ({3dx_room: [ds rooms]})
                                       work/align/room_map_report.json (confidence, notes)
  work/gloss/gl_*.tsv + _names      -> text/glossary.tsv (jp, ko, type, basis, source, note)
                                       work/gloss/conflicts.tsv (same jp, different ko)
Rows from text/glossary_overrides.tsv (same columns) always win; use it to settle conflicts.
Run: .venv\\Scripts\\python scripts\\build_glossary.py
"""

from __future__ import annotations

import csv
import json
import sys
from collections import defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
PARTS = ROOT / "text" / "align" / "parts"
ROOM_MAP = ROOT / "text" / "align" / "room_map.json"
GLOSS_DIR = ROOT / "work" / "gloss"
GLOSSARY = ROOT / "text" / "glossary.tsv"
OVERRIDES = ROOT / "text" / "glossary_overrides.tsv"
COLS = ["jp", "ko", "type", "basis", "source", "note"]
BASIS_RANK = {"override": 0, "DS": 1, "official": 2, "coined": 3}


def read_tsv(path: Path) -> list[dict]:
    with path.open(encoding="utf-8-sig", newline="") as f:
        rows = list(csv.DictReader(f, delimiter="\t"))
    out = []
    for r in rows:
        r = {k.strip().lower(): (v or "").strip() for k, v in r.items() if k}
        if r.get("jp") and r.get("ko"):
            out.append({c: r.get(c, "") for c in COLS})
    return out


def basis_key(basis: str) -> str:
    b = basis.split(":")[0].strip().lower()
    return {"ds": "DS", "official": "official", "coined": "coined", "override": "override"}.get(b, "coined")


def main() -> int:
    # ---- room map
    room_map, report, names = {}, {}, []
    for p in sorted(PARTS.glob("room_map_*.json")):
        data = json.loads(p.read_text(encoding="utf-8"))
        for room, v in data.items():
            if room == "_names":
                for n in v or []:
                    if n.get("jp") and n.get("ko"):
                        names.append({"jp": n["jp"], "ko": n["ko"], "type": n.get("type", "other"),
                                      "basis": "DS", "source": n.get("evidence", p.stem), "note": "room-align"})
                continue
            ds = [str(x).upper().zfill(3) for x in (v.get("ds") or [])]
            room_map[room] = ds
            report[room] = {"ds": ds, "confidence": v.get("confidence", ""), "note": v.get("note", "")}
    if room_map:
        ROOM_MAP.write_text(json.dumps(room_map, ensure_ascii=False, indent=0), encoding="utf-8")
        (ROOT / "work" / "align" / "room_map_report.json").write_text(
            json.dumps(report, ensure_ascii=False, indent=1), encoding="utf-8")
        conf = defaultdict(int)
        for v in report.values():
            conf[v["confidence"] or "?"] += 1
        print(f"room map: {len(room_map)} rooms {dict(conf)}")

    # ---- glossary
    rows = []
    for p in sorted(GLOSS_DIR.glob("gl_*.tsv")):
        for r in read_tsv(p):
            r["note"] = (r["note"] + f" [{p.stem}]").strip()
            rows.append(r)
    rows += names
    overrides = read_tsv(OVERRIDES) if OVERRIDES.exists() else []
    by_jp: dict[str, list[dict]] = defaultdict(list)
    for r in rows:
        by_jp[r["jp"]].append(r)
    final, conflicts = {}, []
    for jp, cands in by_jp.items():
        kos = {c["ko"] for c in cands}
        best = sorted(cands, key=lambda c: BASIS_RANK[basis_key(c["basis"])])[0]
        final[jp] = dict(best)
        if len(kos) > 1:
            conflicts.append((jp, cands))
    for o in overrides:
        o["basis"] = o["basis"] or "override"
        final[o["jp"]] = o
    resolved = {o["jp"] for o in overrides}
    with GLOSSARY.open("w", encoding="utf-8", newline="") as f:
        w = csv.DictWriter(f, fieldnames=COLS, delimiter="\t")
        w.writeheader()
        for jp in sorted(final, key=lambda k: (final[k]["type"], k)):
            w.writerow(final[jp])
    with (GLOSS_DIR / "conflicts.tsv").open("w", encoding="utf-8", newline="") as f:
        w = csv.writer(f, delimiter="\t")
        w.writerow(["jp", "resolved_by_override", "candidates (ko | basis | source | note)"])
        for jp, cands in conflicts:
            w.writerow([jp, "yes" if jp in resolved else "",
                        " || ".join(f"{c['ko']} | {c['basis']} | {c['source']} | {c['note']}" for c in cands)])
    open_conf = sum(1 for jp, _ in conflicts if jp not in resolved)
    basis = defaultdict(int)
    for r in final.values():
        basis[basis_key(r["basis"])] += 1
    print(f"glossary: {len(final)} terms {dict(basis)} | conflicts {len(conflicts)} (open {open_conf})")
    return 0


if __name__ == "__main__":
    sys.exit(main())
