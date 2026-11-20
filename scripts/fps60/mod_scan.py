"""Scan functions for timing patterns (MOD workstream).

    python scripts/fps60/mod_scan.py [game] step-users  [lo hi]     # functions reading fld::System+0x1A4C
    python scripts/fps60/mod_scan.py [game] has <regexA> <regexB> [lo hi]  # functions containing both patterns
    python scripts/fps60/mod_scan.py [game] count <regex> [lo hi]   # per-function match counts

Field step = fld::System+0x1A4C, read as "add rA, rB, #0x1800" ... "vldr sN, [rA, #0x24c]" (or #0x1000/#0xa4c).
Function boundaries and labels come from mod_fn.Ctx.
"""
from __future__ import annotations

import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import armdis  # noqa: E402
import mod_fn  # noqa: E402


def functions(c: mod_fn.Ctx, lo: int, hi: int):
    for s in c.starts:
        if s < lo or s >= hi:
            continue
        e = c.fn_end(s)
        yield s, e


def main(argv):
    name = argv[0] if argv and argv[0] in armdis.GAMES else "3dx_v12"
    args = argv[1:] if argv and argv[0] in armdis.GAMES else argv
    c = mod_fn.Ctx(name)
    cmd = args[0]
    if cmd == "step-users":
        lo = int(args[1], 0) if len(args) > 1 else 0x100000
        hi = int(args[2], 0) if len(args) > 2 else 0x389000
        n = 0
        for s, e in functions(c, lo, hi):
            lines = c.disasm_range(s, e)
            regs = {}
            hits = []
            for ln in lines:
                m = re.search(r": add\s+(r\d+|sb|sl|fp|ip), (r\d+|sb|sl|fp|ip), #0x1800$", ln)
                if m:
                    regs[m.group(1)] = True
                    continue
                m = re.search(r": vldr\s+(s\d+), \[(r\d+|sb|sl|fp|ip), #0x24c\]", ln)
                if m and m.group(2) in regs:
                    hits.append(ln.split(":")[0])
                m = re.search(r": vstr\s+(s\d+), \[(r\d+|sb|sl|fp|ip), #0x24c\]", ln)
                if m and m.group(2) in regs:
                    hits.append(ln.split(":")[0] + "(W)")
            if hits:
                n += 1
                print(f"{s:#x} {c.label(s)}: {' '.join(hits[:6])}")
        print(f"; {n} functions")
        return
    if cmd == "has":
        ra, rb = re.compile(args[1]), re.compile(args[2])
        lo = int(args[3], 0) if len(args) > 3 else 0x100000
        hi = int(args[4], 0) if len(args) > 4 else 0x389000
        for s, e in functions(c, lo, hi):
            lines = c.disasm_range(s, e)
            a = [ln for ln in lines if ra.search(ln)]
            b = [ln for ln in lines if rb.search(ln)]
            if a and b:
                print(f"{s:#x} {c.label(s)}")
                for ln in (a[:3] + b[:3]):
                    print("    " + ln)
        return
    if cmd == "count":
        rx = re.compile(args[1])
        lo = int(args[2], 0) if len(args) > 2 else 0x100000
        hi = int(args[3], 0) if len(args) > 3 else 0x389000
        for s, e in functions(c, lo, hi):
            k = sum(1 for ln in c.disasm_range(s, e) if rx.search(ln))
            if k:
                print(f"{k:4d} {s:#x} {c.label(s)}")
        return
    print(__doc__)


if __name__ == "__main__":
    main(sys.argv[1:])
