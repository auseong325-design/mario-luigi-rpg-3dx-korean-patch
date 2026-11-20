"""Classify every isFps30 call site (static + CROs) by what the result selects (MOD workstream).

    python scripts/fps60/mod_fps30sites.py [game] [--module NAME] [--ctx N]

For each call (direct BL or CRO veneer) prints the containing function label and the next N instructions
(default 8), plus a guess of the pattern:
  F2/1   float select 2.0 / 1.0 (step)            I-sel  integer select (movne/moveq #imm)
  Fx     float select of other constants          ?      anything else (read the context)
"""
from __future__ import annotations

import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import armdis  # noqa: E402
import mod_fn  # noqa: E402

ISFPS30 = 0x25EDD0


def classify(lines: list[str]) -> str:
    txt = "\n".join(lines)
    floats = re.findall(r"=0x[0-9a-f]+ \(([-0-9.e+]+)\)", txt)
    if "vmov" in txt or "vldr" in txt:
        if "2" in floats and "1" in floats:
            return "F2/1"
        if floats:
            return "F" + "/".join(floats[:3])
    m = re.findall(r"mov(?:ne|eq)\s+\w+, #(0x[0-9a-f]+|\d+)", txt)
    if m:
        return "I-sel " + "/".join(m[:3])
    m = re.findall(r"(lsl|lsr|asr)(?:ne|eq)?\s", txt)
    if m:
        return "shift"
    return "?"


def main(argv):
    name = argv[0] if argv and argv[0] in armdis.GAMES else "3dx_v12"
    args = argv[1:] if argv and argv[0] in armdis.GAMES else argv
    mod = None
    ctx = 8
    i = 0
    while i < len(args):
        if args[i] == "--module":
            mod = args[i + 1]; i += 2
        elif args[i] == "--ctx":
            ctx = int(args[i + 1]); i += 2
        else:
            i += 1
    c = mod_fn.Ctx(name)
    from collections import Counter
    stats = Counter()
    for a, kind in armdis.callers(name, ISFPS30):
        if kind == "literal":
            continue
        m = c.g.module_of(a)
        if mod and m != mod:
            continue
        s = c.fn_start(a)
        lines = c.disasm_range(a + 4, a + 4 + 4 * ctx)
        cl = classify(lines)
        stats[(m, cl.split(" ")[0])] += 1
        print(f"== {a:#010x} [{m}] in {c.label(s)} ({s:#x}+{a - s:#x})  => {cl}")
        for ln in lines:
            print("     " + ln)
    print("; summary:")
    for (m, cl), n in sorted(stats.items()):
        print(f";   {m:16s} {cl:8s} {n}")


if __name__ == "__main__":
    main(sys.argv[1:])
