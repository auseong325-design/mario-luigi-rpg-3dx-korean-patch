"""Propose DS room candidates for every 3DX FMsg room (input for the alignment subagents).

The remake keeps most dialogue, so a room's *sequence of messages* (relative text
length and page count per message) is a strong language-independent fingerprint.
Each 3DX room is aligned against every DS room with a Needleman-Wunsch DP and the
top candidates are written to work/align/candidates.json.
"""

from __future__ import annotations

import json
import math
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
JP = ROOT / "text" / "jp"
DS = ROOT / "text" / "ref_ds_ko"
OUT = ROOT / "work" / "align" / "candidates.json"
TOP = 6
GAP = -0.45


def jp_feat(text: str) -> tuple[int, int]:
    t = re.sub(r"\[Ruby ([^;\]]*);[^\]]*\]", r"\1", text)
    pages = t.count("[Next]") + 1
    t = re.sub(r"\[[^\]]*\]|\s", "", t)
    return len(t), pages


def ko_feat(text: str) -> tuple[int, int]:
    t = text.strip()
    if t.startswith("[Next]"):
        t = t[6:]
    pages = t.count("[Next]") + 1
    t = re.sub(r"\[Next\]|\{[^}]*\}|\s", "", t)
    return len(t), pages


def align(a: list[tuple[int, int]], b: list[tuple[int, int]], k: float) -> float:
    n, m = len(a), len(b)
    prev = [j * GAP for j in range(m + 1)]
    for i in range(1, n + 1):
        cur = [i * GAP] + [0.0] * m
        la, pa = a[i - 1]
        for j in range(1, m + 1):
            lb, pb = b[j - 1]
            s = 1.0 - min(1.0, abs(math.log((lb + 4) / (la * k + 4))) * 1.4)
            s += 0.35 if pa == pb else -0.35
            cur[j] = max(prev[j - 1] + s, prev[j] + GAP, cur[j - 1] + GAP)
        prev = cur
    return prev[m] / max(n, m, 1)


def main() -> int:
    jp_rooms = {}
    for f in sorted(JP.glob("FMsg__*.json")):
        msgs = json.loads(f.read_text(encoding="utf-8"))["messages"]
        feats = [jp_feat(m["jp"]) for m in msgs]
        feats = [x for x in feats if x[0] > 1]
        if feats:
            jp_rooms[f.stem.split("__", 1)[1]] = feats
    ds_rooms = {}
    for r in json.loads((DS / "FEvent.json").read_text(encoding="utf-8")):
        feats = [ko_feat(m["ko"]) for m in r["messages"]]
        feats = [x for x in feats if x[0] > 1]
        if feats:
            ds_rooms[r["room"]] = feats
    jp_total = sum(x[0] for v in jp_rooms.values() for x in v)
    ko_total = sum(x[0] for v in ds_rooms.values() for x in v)
    k = 0.85  # rough KO/JP length ratio for the same line
    print(f"3DX rooms {len(jp_rooms)} ({jp_total} chars), DS rooms {len(ds_rooms)} ({ko_total} chars)")
    out = {}
    for name, a in jp_rooms.items():
        la = sum(x[0] for x in a)
        scored = []
        for rid, b in ds_rooms.items():
            lb = sum(x[0] for x in b)
            ratio = (lb + 20) / (la * k + 20)
            if not 0.25 < ratio < 4 or not 0.2 < len(b) / len(a) < 5:
                continue
            scored.append((round(align(a, b, k), 3), rid, len(b)))
        scored.sort(reverse=True)
        out[name] = [{"ds": rid, "score": s, "n_ds": nb} for s, rid, nb in scored[:TOP]]
        out[name].insert(0, {"n_jp": len(a)})
    OUT.parent.mkdir(parents=True, exist_ok=True)
    OUT.write_text(json.dumps(out, ensure_ascii=False, indent=0), encoding="utf-8")
    strong = sum(1 for v in out.values() if len(v) > 1 and v[1]["score"] > 0.6)
    print(f"wrote {OUT} ; rooms with a strong top candidate (>0.6): {strong}/{len(out)}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
