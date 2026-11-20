"""STAR helper: for every battle opcode given, follow the PMF handler through stubs and print the
first instructions and every bl/b target with its symbol (read-only).

    python work/fps60/star/star_hand.py 0x117 0x118 ...
"""
from __future__ import annotations

import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))))
sys.path.insert(0, os.path.join(ROOT, "scripts", "fps60"))
import armdis  # noqa: E402
import btl_aitbl  # noqa: E402


def body(g, addr, n=80):
    lines = armdis.disasm("3dx_v12", addr, n)
    out = []
    for ln in lines:
        out.append(ln)
        s = ln.split("\n")[-1]
        if re.search(r"\b(pop\s+\{[^}]*pc\}|bx\s+lr|ldm\w*\s+sp!,\s*\{[^}]*pc\})", s):
            break
    return out


def main(argv):
    g = armdis.game("3dx_v12")
    _tbl, first, rows = btl_aitbl.battle_table(g)
    hand = {op: ptr for op, ptr, _adj in rows}
    n = 60
    ops = []
    for a in argv:
        if a.startswith("-n"):
            n = int(a[2:])
        else:
            ops.append(int(a, 0))
    for op in ops:
        h = hand[op] if op >= 0x4E else op
        print(f"===== op{op:03x} handler {h:#x}  ({armdis.where('3dx_v12', h)})")
        for ln in body(g, h, n):
            print(ln)
        print()


if __name__ == "__main__":
    main(sys.argv[1:])
