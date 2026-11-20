"""STAR helper: opcode census of a BAI script region + handler addresses (read-only).

    python work/fps60/star/star_ops.py <script> [lo] [hi]
"""
from __future__ import annotations

import os
import sys
from collections import Counter

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))))
sys.path.insert(0, os.path.join(ROOT, "scripts", "fps60"))
sys.path.insert(0, os.path.join(ROOT, "scripts"))
import btl_bai  # noqa: E402
import btl_aitbl  # noqa: E402
import armdis  # noqa: E402


def main(argv):
    name = argv[0] if argv[0].endswith(".bai") else argv[0] + ".bai"
    lo = int(argv[1], 0) if len(argv) > 1 else 0
    hi = int(argv[2], 0) if len(argv) > 2 else 1 << 30
    dt = btl_bai.descs()
    files = btl_bai.load()
    ins, _ = btl_bai.decode_all(files[name], dt)
    g = armdis.game("3dx_v12")
    _tbl, first, rows = btl_aitbl.battle_table(g)
    hand = {op: ptr for op, ptr, _adj in rows}
    c = Counter(i[1] for i in ins if lo <= i[0] < hi and i[1] is not None)
    for op, n in sorted(c.items()):
        h = hand.get(op)
        if op < 0x4E:
            base = g.u32(0x389918 + 8 * op) if g.u32(0x389918 + 8 * op) else None
            print(f"op{op:03x} {n:4d} base  {base:#x}" if base else f"op{op:03x} {n:4d} base")
        else:
            print(f"op{op:03x} {n:4d} {h:#010x}")


if __name__ == "__main__":
    main(sys.argv[1:])
