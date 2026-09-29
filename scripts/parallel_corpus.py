"""Build a JP<->KO parallel line corpus from the structural room alignment.

For each 3DX FMsg room, its best DS candidate (work/align/candidates.json, or the
confirmed text/align/room_map.json when present) is aligned message-by-message with
the same DP as align_candidates.py; pairs with a good local score are written to
work/align/parallel.tsv (room, jp_id, ds_ref, pair_score, room_score, jp, ko).
Pairs are *candidates*: always sanity-check meaning before relying on one.
"""

from __future__ import annotations

import csv
import json
import math
import re
import sys
from pathlib import Path

from align_candidates import GAP, jp_feat, ko_feat

ROOT = Path(__file__).resolve().parent.parent
JP = ROOT / "text" / "jp"
DS = ROOT / "text" / "ref_ds_ko"
CAND = ROOT / "work" / "align" / "candidates.json"
ROOM_MAP = ROOT / "text" / "align" / "room_map.json"
OUT = ROOT / "work" / "align" / "parallel.tsv"
K = 0.85


def plain_jp(t: str) -> str:
    t = re.sub(r"\[Ruby ([^;\]]*);[^\]]*\]", r"\1", t)
    t = t.replace("[Next]", " / ")
    return re.sub(r"\s+", " ", re.sub(r"\[[^\]]*\]", "", t)).strip()


def plain_ko(t: str) -> str:
    t = t.strip()
    if t.startswith("[Next]"):
        t = t[6:]
    t = t.replace("[Next]", " / ")
    return re.sub(r"\s+", " ", re.sub(r"\{[^}]*\}", "", t)).strip()


def pair_score(a: tuple[int, int], b: tuple[int, int]) -> float:
    (la, pa), (lb, pb) = a, b
    s = 1.0 - min(1.0, abs(math.log((lb + 4) / (la * K + 4))) * 1.4)
    return s + (0.35 if pa == pb else -0.35)


def backtrack(a: list, b: list) -> list[tuple[int, int, float]]:
    n, m = len(a), len(b)
    dp = [[0.0] * (m + 1) for _ in range(n + 1)]
    for i in range(1, n + 1):
        dp[i][0] = i * GAP
    for j in range(1, m + 1):
        dp[0][j] = j * GAP
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            dp[i][j] = max(dp[i - 1][j - 1] + pair_score(a[i - 1], b[j - 1]),
                           dp[i - 1][j] + GAP, dp[i][j - 1] + GAP)
    i, j, pairs = n, m, []
    while i > 0 and j > 0:
        s = pair_score(a[i - 1], b[j - 1])
        if abs(dp[i][j] - (dp[i - 1][j - 1] + s)) < 1e-9:
            pairs.append((i - 1, j - 1, s))
            i, j = i - 1, j - 1
        elif abs(dp[i][j] - (dp[i - 1][j] + GAP)) < 1e-9:
            i -= 1
        else:
            j -= 1
    return pairs[::-1]


def main() -> int:
    cand = json.loads(CAND.read_text(encoding="utf-8"))
    confirmed = json.loads(ROOM_MAP.read_text(encoding="utf-8")) if ROOM_MAP.exists() else {}
    ds_rooms = {r["room"]: r["messages"] for r in json.loads((DS / "FEvent.json").read_text(encoding="utf-8"))}
    rows = []
    for name, cands in cand.items():
        if name in confirmed:
            targets = [(rid, 1.0) for rid in confirmed[name]]
        elif len(cands) > 1 and cands[1]["score"] >= 0.55:
            targets = [(cands[1]["ds"], cands[1]["score"])]
        else:
            continue
        jmsgs = [m for m in json.loads((JP / f"FMsg__{name}.json").read_text(encoding="utf-8"))["messages"]
                 if jp_feat(m["jp"])[0] > 1]
        for rid, room_score in targets:
            kmsgs = [m for m in ds_rooms.get(rid, []) if ko_feat(m["ko"])[0] > 1]
            a = [jp_feat(m["jp"]) for m in jmsgs]
            b = [ko_feat(m["ko"]) for m in kmsgs]
            for i, j, s in backtrack(a, b):
                if s >= 0.95:
                    rows.append([name, jmsgs[i]["id"], f"DS{rid}#{kmsgs[j]['i']}", round(s, 2), room_score,
                                 plain_jp(jmsgs[i]["jp"]), plain_ko(kmsgs[j]["ko"])])
    OUT.parent.mkdir(parents=True, exist_ok=True)
    with OUT.open("w", encoding="utf-8", newline="") as f:
        w = csv.writer(f, delimiter="\t")
        w.writerow(["room", "jp_id", "ds_ref", "pair_score", "room_score", "jp", "ko"])
        w.writerows(rows)
    print(f"{len(rows)} candidate line pairs from {len({r[0] for r in rows})} rooms -> {OUT}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
