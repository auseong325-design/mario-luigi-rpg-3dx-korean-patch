"""D1X2: grep the Ghidra C dumps and print each hit with its enclosing function.

    python scripts/fps60/d1x_grep.py <game> <regex> [--module static] [--ctx N] [--max 400]

Reads work/fps60/decomp/<game>/<module>.c (all modules unless --module), finds lines matching <regex>
(Python re), prints `<module>:<line> <func addr> <func name> | <line text>`; --ctx N adds N lines of
context after each hit. Read-only.
"""
from __future__ import annotations

import glob
import os
import re
import sys

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", ".."))
FUNC_RE = re.compile(r"^// FUNC (0x[0-9a-fA-F]+) (\S+) \((\w+)\)")


def main(argv: list[str]) -> None:
    if len(argv) < 2:
        raise SystemExit(__doc__)
    game, pat = argv[0], re.compile(argv[1])
    module, ctx, mx = None, 0, 400
    it = iter(argv[2:])
    for a in it:
        if a == "--module":
            module = next(it)
        elif a == "--ctx":
            ctx = int(next(it))
        elif a == "--max":
            mx = int(next(it))
    files = sorted(glob.glob(os.path.join(ROOT, "work", "fps60", "decomp", game, "*.c")))
    n = 0
    for fn in files:
        mod = os.path.splitext(os.path.basename(fn))[0]
        if module and mod != module:
            continue
        cur = ("?", "?")
        with open(fn, encoding="utf-8", errors="replace") as f:
            lines = f.readlines()
        for i, ln in enumerate(lines):
            m = FUNC_RE.match(ln)
            if m:
                cur = (m.group(1), m.group(2))
                continue
            if pat.search(ln):
                n += 1
                print(f"{mod}:{i + 1} {cur[0]} {cur[1]} | {ln.rstrip()}")
                for k in range(1, ctx + 1):
                    if i + k < len(lines):
                        print(f"        {lines[i + k].rstrip()}")
                if n >= mx:
                    print(f"# stopped at --max {mx}")
                    return
    print(f"# {n} hits")


if __name__ == "__main__":
    main(sys.argv[1:])
