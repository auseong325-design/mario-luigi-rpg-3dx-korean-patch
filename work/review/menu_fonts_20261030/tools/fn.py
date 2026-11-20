"""fn.py <addr-hex> [more...] [--body N] : function containing addr (functions.tsv) + first N decomp lines."""
from __future__ import annotations

import csv
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[4]
D = ROOT / "work/fps60/decomp/3dx_v12"


def load():
    rows = []
    with open(D / "functions.tsv", encoding="utf-8") as fh:
        for r in csv.DictReader(fh, delimiter="\t"):
            rows.append((int(r["addr"], 16), int(r["end"], 16), r))
    return rows


def main():
    args = sys.argv[1:]
    body = 0
    if "--body" in args:
        i = args.index("--body")
        body = int(args[i + 1])
        del args[i:i + 2]
    rows = load()
    cache: dict[str, list[str]] = {}
    for a in args:
        x = int(a, 16)
        hit = [(s, e, r) for s, e, r in rows if s <= x < e]
        if not hit:
            print(f"{x:08X}: no function")
            continue
        r = max(hit, key=lambda t: t[0])[2]          # innermost (latest start)
        print(f"{x:08X}: in {r['addr']} {r['name']} size {r['size']} {r['file']}:{r['line']} callers={r['callers']}")
        if body:
            f = r["file"]
            if f not in cache:
                cache[f] = (D / f).read_text("utf-8", errors="replace").splitlines()
            ln = int(r["line"])
            print("\n".join(cache[f][ln - 1:ln - 1 + body]))
            print("-" * 60)


if __name__ == "__main__":
    main()
