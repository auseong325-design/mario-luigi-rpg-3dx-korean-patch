"""TB workstream (wave 3): read-only queries on the field event scripts for the test beds.

    python scripts/fps60/tb_fev.py battles [substr]        # every op240 (scripted battle start) with its strings
    python scripts/fps60/tb_fev.py ctx <entry> <off> [n]    # flow-decoded instructions around an offset
    python scripts/fps60/tb_fev.py str <entry> <off>        # NUL-terminated string at a buffer offset

Uses FLD's decoder `fld_fev.py` (buffer-relative jump targets, BRIEF3 W2) on the ORIGINAL v1.2 FEvent.dat
(`lib3dx.romfs_path('FEvent/FEvent.dat')` = romf2). op240 = handler FUN_002E0038 (descriptor
[u8,u8,u8,u8,u8,u8,u32 str,u32 str,u8,u32,u16,u16,u8]); string params are absolute .fev buffer offsets.
"""
from __future__ import annotations

import os
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import fld_fev as V  # noqa: E402


def cstr(b: bytes, off: int) -> str:
    if off >= len(b):
        return f"<oob {off:#x}>"
    e = b.find(b"\0", off)
    return b[off:e if e >= 0 else len(b)].decode("latin-1")


def fmt_battle(b, ins):
    pos, op, mask, res, params = ins
    ps = []
    for i, (t, v) in enumerate(params):
        if t == "var":
            ps.append(f"${v:04x}")
        elif i in (6, 7):
            ps.append(f'"{cstr(b, v)}"@{v:#x}')
        else:
            ps.append(f"{v:#x}" if isinstance(v, int) else str(v))
    return f"{pos:05x}: op240({', '.join(ps)})"


def main(argv):
    if not argv:
        print(__doc__)
        return 0
    dt = V.fdescs()
    es = V.entries()
    cmd = argv[0]
    if cmd == "battles":
        sub = argv[1] if len(argv) > 1 else ""
        n = 0
        for k in sorted(es):
            if sub not in k:
                continue
            ins, sec, offs = V.decode_flow(es[k], dt)
            for i in ins:
                if i[1] == 0x240:
                    n += 1
                    print(f"{k:34s} {fmt_battle(es[k], i)}")
        print(f"; {n} op240 uses")
    elif cmd == "ctx":
        b = es[argv[1]]
        off = int(argv[2], 0)
        cnt = int(argv[3]) if len(argv) > 3 else 20
        ins, sec, offs = V.decode_flow(b, dt)
        starts = {sec + o: k for k, o in enumerate(offs) if o}
        idx = [j for j, i in enumerate(ins) if i[0] >= off]
        j0 = max(0, (idx[0] if idx else len(ins)) - cnt // 2)
        for i in ins[j0:j0 + cnt]:
            if i[0] in starts:
                print(f"; ---- script #{starts[i[0]]}")
            print(fmt_battle(b, i) if i[1] == 0x240 else V.fmt(i))
    elif cmd == "str":
        print(cstr(es[argv[1]], int(argv[2], 0)))
    elif cmd == "rawbattles":
        # op240 instructions found by a raw scan (also code that FLD's flow decoder does not reach, e.g.
        # threads started by op052/op06b): u16 0x240 that decodes and whose two string params are
        # in-buffer offsets of a "*.bai" name and a NUL-terminated string.
        sub = argv[1] if len(argv) > 1 else ""
        n = 0
        for k in sorted(es):
            if sub not in k:
                continue
            b = es[k]
            flow = {i[0] for i in V.decode_flow(b, dt)[0]}
            p = b.find(b"\x40\x02")
            while p >= 0:
                r = V.decode_one(b, dt, p)
                if r and r[0][1] == 0x240:
                    ps = r[0][4]
                    s6 = ps[6][1] if ps[6][0] != "var" else None
                    if s6 is not None and s6 < len(b) and cstr(b, s6).endswith(".bai"):
                        n += 1
                        tag = "flow" if p in flow else "raw "
                        print(f"{k:34s} {tag} {fmt_battle(b, r[0])}")
                p = b.find(b"\x40\x02", p + 1)
        print(f"; {n} op240 found by raw scan")
    elif cmd == "who":
        # instructions (raw scan, any alignment) with an immediate param equal to the absolute offset, and
        # script-table slots holding it relative to the script section
        b = es[argv[1]]
        tgt = int(argv[2], 0)
        sec, n, offs = V.layout(b)
        for k, o in enumerate(offs):
            if o and sec + o == tgt:
                print(f"script table: entry #{k} (slot @{sec + 4 + 4 * n + 4 * k:#x})")
        for p in range(len(b) - 6):
            r = V.decode_one(b, dt, p)
            if r and any(t != "var" and v == tgt for t, v in r[0][4]) and r[0][1] in (0x03, 0x04, 0x4f, 0x50, 0x51, 0x52, 0x6a, 0x6b):
                print(V.fmt(r[0]))
    elif cmd == "rawdis":
        # linear decode from an arbitrary offset (stops at end/return or an undecodable op)
        b = es[argv[1]]
        pos = int(argv[2], 0)
        cnt = int(argv[3]) if len(argv) > 3 else 20
        for _ in range(cnt):
            r = V.decode_one(b, dt, pos)
            if r is None:
                print(f"{pos:05x}: <undecodable>")
                break
            print(fmt_battle(b, r[0]) if r[0][1] == 0x240 else V.fmt(r[0]))
            pos = r[1]
    else:
        print(__doc__)
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
