"""RT5: frame counts of btl::Main (+0x578) between burst frames (wall clock of a burst2 frame -> follow log sample).

  rt5_calc.py LOG.jsonl BURST_DIR I0 I1 [I2 ...]   counter value and wall time at each burst frame index, deltas
"""
from __future__ import annotations

import bisect
import json
import sys
from pathlib import Path


def main() -> None:
    log, bdir, idxs = sys.argv[1], Path(sys.argv[2]), [int(x) for x in sys.argv[3:]]
    rows = [json.loads(l) for l in open(log, encoding="utf-8")]
    rows = [r for r in rows if "wall" in r and "bctr" in r]
    walls = [r["wall"] for r in rows]
    idx = json.loads((bdir / "index.json").read_text(encoding="utf-8"))
    fr = {f["i"]: f for f in idx["frames"]}
    prev = None
    for i in idxs:
        w = idx["wall0"] + fr[i]["t0"]
        k = bisect.bisect_left(walls, w)
        k = min(max(k, 0), len(rows) - 1)
        r = rows[k]
        line = f"#{i:03d} t={fr[i]['t0']:7.3f} wall={w:.3f} log_dt={r['wall'] - w:+.3f} bctr={r['bctr']} bstep={r.get('bstep')}"
        if prev:
            dt = w - prev[0]
            dc = r["bctr"] - prev[1]
            line += f"  | since prev: {dt:.3f} s, {dc} frames ({dc / dt:.2f}/s), x step = {dc * (r.get('bstep') or 1):.0f} 60-Hz units"
        print(line)
        prev = (w, r["bctr"])


if __name__ == "__main__":
    main()
