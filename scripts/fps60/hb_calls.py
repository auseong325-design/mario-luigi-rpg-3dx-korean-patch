"""HB helper: list the calls a function makes (direct BL targets, import veneers, float literals), optionally
recursively, or for every vtable method of a class.

    python scripts/fps60/hb_calls.py func <addr> [depth]          # calls made by one function (depth default 1)
    python scripts/fps60/hb_calls.py class <ClassSubstr> [depth]  # same for every vtable slot of matching classes
    python scripts/fps60/hb_calls.py grep <regex> <addr> [depth]  # only print call lines whose text matches regex

A "function" spans from its start to the next known function start (hb_class.func_starts). Owned by worker HB.
"""
from __future__ import annotations

import bisect
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import armdis  # noqa: E402
import hb_class  # noqa: E402

G = armdis.game("3dx_v12")


def func_end(f: int) -> int:
    fs = hb_class.func_starts()
    i = bisect.bisect_right(fs, f)
    end = fs[i] if i < len(fs) else hb_class.TEXT[1]
    return min(end, f + 0x4000)


def body(f: int) -> list[str]:
    n = (func_end(f) - f) // 4
    return armdis.disasm("3dx_v12", f, max(n, 1))


def calls(f: int) -> list[tuple[int, str, int | None]]:
    out = []
    for line in body(f):
        line = line.split("\n")[-1]
        m = re.match(r"([0-9a-f]{8}): \S+\s+(bl|blx|b)\s+#(0x[0-9a-f]+)(.*)", line)
        if m:
            t = int(m.group(3), 16)
            if m.group(2) == "b" and f <= t < func_end(f):
                continue
            out.append((int(m.group(1), 16), line, t))
        elif re.search(r"\bblx\s+r\d+", line) or "vldr" in line and "; =" in line:
            out.append((int(line[:8], 16), line, None))
    return out


def show(f: int, depth: int, pat: str | None, seen: set[int], ind: str = "") -> None:
    if f in seen:
        return
    seen.add(f)
    print(f"{ind}== {hb_class.who(f)}")
    for a, line, t in calls(f):
        if pat is None or re.search(pat, line):
            print(f"{ind}   {line}")
        if t is not None and depth > 1 and hb_class.in_text(t) and t not in G.veneers:
            show(t, depth - 1, pat, seen, ind + "  ")


def main(argv: list[str]) -> None:
    if not argv:
        print(__doc__)
        return
    if argv[0] == "func":
        show(int(argv[1], 0), int(argv[2]) if len(argv) > 2 else 1, None, set())
    elif argv[0] == "grep":
        show(int(argv[2], 0), int(argv[3]) if len(argv) > 3 else 1, argv[1], set())
    elif argv[0] == "class":
        sub = argv[1].lower()
        depth = int(argv[2]) if len(argv) > 2 else 1
        seen: set[int] = set()
        for ap, cls, slots in hb_class.vtables():
            if sub in cls.lower():
                print(f"######## {cls} vtable {ap:#x}")
                for t in slots:
                    if hb_class.in_text(t & ~1):
                        show(t & ~1, depth, None, seen)
    else:
        print(__doc__)


if __name__ == "__main__":
    main(sys.argv[1:])
