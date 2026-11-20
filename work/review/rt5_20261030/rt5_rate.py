"""RT5: frame-rate summary of an rt_watch4-style follow log (JSON lines).

  rt5_rate.py LOG.jsonl [--from WALL] [--to WALL] [--win 1.0] [--key bctr]
  Prints, per window, the counter increase per wall second (= task frames/s), bstep/bspeed values seen, and gaps
  (samples > 0.2 s apart). The counter is btl::Main +0x578 (one per task frame).
"""
from __future__ import annotations

import argparse
import json


def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("log")
    ap.add_argument("--from", dest="t0", type=float, default=0.0)
    ap.add_argument("--to", dest="t1", type=float, default=1e12)
    ap.add_argument("--win", type=float, default=1.0)
    ap.add_argument("--key", default="bctr")
    a = ap.parse_args()
    rows = []
    for line in open(a.log, encoding="utf-8"):
        r = json.loads(line)
        if "wall" in r and a.key in r and a.t0 <= r["wall"] <= a.t1:
            rows.append(r)
    if not rows:
        print("no rows")
        return
    w0 = rows[0]["wall"]
    start = rows[0]
    out = []
    for r in rows[1:]:
        if r["wall"] - start["wall"] >= a.win:
            dt = r["wall"] - start["wall"]
            d = r[a.key] - start[a.key]
            out.append((round(start["wall"] - w0, 2), round(d / dt, 1), r.get("bstep"), r.get("bspeed"), r.get("b8A3C")))
            start = r
    for o in out:
        print(f"t+{o[0]:7.2f}s  {o[1]:6.1f} frames/s  bstep={o[2]} bspeed={o[3]} b8A3C={o[4]}")
    gaps = [(round(b["wall"] - w0, 2), round(b["wall"] - a_["wall"], 3)) for a_, b in zip(rows, rows[1:])
            if b["wall"] - a_["wall"] > 0.2]
    tot = (rows[-1][a.key] - rows[0][a.key]) / (rows[-1]["wall"] - rows[0]["wall"])
    print(f"rows {len(rows)}  span {rows[-1]['wall'] - w0:.2f}s  mean {tot:.2f} frames/s  "
          f"min {min(o[1] for o in out) if out else None}  max {max(o[1] for o in out) if out else None}  "
          f"sample gaps>0.2s: {gaps[:10]}")


if __name__ == "__main__":
    main()
