"""BTL workstream helper: dump AlphaDream event/AI command tables (PMF tables) for 3DX v1.2.

    python scripts/fps60/btl_aitbl.py [game] battle      # btl::AISys extra commands (Battle.cro PMF table)
    python scripts/fps60/btl_aitbl.py [game] global      # GlobalEvent base command table (static)
    python scripts/fps60/btl_aitbl.py [game] find <addr> # which command id(s) dispatch to a handler address
    python scripts/fps60/btl_aitbl.py [game] sysvar      # AISys read-system-variable switch (ids 0x7000..)

Read-only. Uses the linked images of scripts/fps60/armdis.py (analysis addresses, not runtime).
"""
from __future__ import annotations

import os
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import armdis  # noqa: E402

# Battle.cro: AISys command dispatcher at 0x11056cbc loads ip=[pc,#0x54] -> PMF table base and
# subtracts GlobalEvent::_CmdFuncTblSize (static 0x3a0728) from the opcode.
BATTLE_PMF_TABLE_LIT = 0x11056d24      # literal pool word holding the table address (=0x1105e118)
GLOBAL_TBLSIZE = 0x3A0728               # GlobalEvent::_CmdFuncTblSize
SYSVAR_JT = 0x11047804                  # jump table of AISys read-sysvar switch (ids 0x7000..0x706b)
SYSVAR_N = 0x6C


def pmf_entries(g, base: int, n: int):
    out = []
    for i in range(n):
        ptr = g.u32(base + 8 * i)
        adj = g.u32(base + 8 * i + 4)
        if ptr is None:
            break
        out.append((i, ptr, adj))
    return out


def looks_code(g, a: int) -> bool:
    return any(s <= (a & ~1) < e for _, s, e in g.text_ranges)


def battle_table(g):
    tbl = g.u32(BATTLE_PMF_TABLE_LIT)
    first = g.u32(GLOBAL_TBLSIZE)
    rows = []
    i = 0
    while True:
        ptr = g.u32(tbl + 8 * i)
        adj = g.u32(tbl + 8 * i + 4)
        if ptr is None or (ptr != 0 and not looks_code(g, ptr)) or adj not in (0, 1) and adj > 0x100:
            break
        rows.append((first + i, ptr, adj))
        i += 1
        if i > 600:
            break
    return tbl, first, rows


def main(argv):
    name = argv[0] if argv and argv[0] in armdis.GAMES else "3dx_v12"
    args = argv[1:] if argv and argv[0] in armdis.GAMES else argv
    g = armdis.game(name)
    if not args:
        print(__doc__)
        return
    if args[0] == "battle":
        tbl, first, rows = battle_table(g)
        print(f"; Battle AISys command PMF table @ {tbl:#x}, first opcode {first:#x}, {len(rows)} entries")
        for op, ptr, adj in rows:
            print(f"op {op:#06x}  {ptr:#010x} adj={adj:#x}  {armdis.where(name, ptr) if ptr else '-'}")
    elif args[0] == "find":
        t = int(args[1], 0)
        tbl, first, rows = battle_table(g)
        for op, ptr, adj in rows:
            if ptr == t:
                print(f"battle op {op:#06x} -> {ptr:#x}")
    elif args[0] == "sysvar":
        for i in range(SYSVAR_N):
            print(f"var {0x7000 + i:#06x} -> {g.u32(SYSVAR_JT + 4 * i):#010x}")
    else:
        print(__doc__)


if __name__ == "__main__":
    main(sys.argv[1:])
