"""STAR helper: battle AI opcode -> handler -> decompiled callees (read-only).

    python work/fps60/star/star_calls.py <script> [lo] [hi]      # every op of a script region
    python work/fps60/star/star_calls.py --ops 0x117 0x16a ...   # given ops
    python work/fps60/star/star_calls.py --func 0x11029880 ...   # print decompiled functions
"""
from __future__ import annotations

import csv
import os
import re
import struct
import sys
from collections import Counter

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))))
sys.path.insert(0, os.path.join(ROOT, "scripts", "fps60"))
sys.path.insert(0, os.path.join(ROOT, "scripts"))
import armdis  # noqa: E402
import btl_aitbl  # noqa: E402

DEC = os.path.join(ROOT, "work", "fps60", "decomp", "3dx_v12")


def load_index():
    rows = []
    with open(os.path.join(DEC, "functions.tsv"), encoding="utf-8") as f:
        r = csv.DictReader(f, delimiter="\t")
        for x in r:
            rows.append((int(x["addr"], 16), int(x["end"], 16), x["module"], x["name"], x["file"], int(x["line"] or 0)))
    rows.sort()
    return rows


_files: dict[str, list[str]] = {}


def text_of(rows, addr):
    import bisect
    starts = [r[0] for r in rows]
    i = bisect.bisect_right(starts, addr) - 1
    if i < 0:
        return None, None
    a, e, mod, name, fn, line = rows[i]
    if not (a <= addr < max(e, a + 4)):
        return None, None
    if fn not in _files:
        _files[fn] = open(os.path.join(DEC, fn), encoding="utf-8", errors="replace").read().split("\n")
    L = _files[fn]
    j = line - 1
    while j > 0 and not L[j].startswith("// FUNC"):
        j -= 1
    k = j + 1
    while k < len(L) and not L[k].startswith("// FUNC"):
        k += 1
    return (a, name), "\n".join(L[j:k])


def follow(g, addr):
    """follow plain 'b' stubs"""
    for _ in range(4):
        w = g.u32(addr)
        if w is None:
            break
        if (w >> 24) == 0xEA:
            t = armdis.branch_target(w, addr)
            addr = t
            continue
        break
    return addr


CALL = re.compile(r"([A-Za-z_][A-Za-z0-9_:~<>]*)\s*\(")
SKIP = {"if", "while", "for", "switch", "return", "sizeof", "CONCAT44", "SUB84", "ZEXT48", "CARRY4", "SBORROW4",
        "POPCOUNT", "uint", "int", "float", "char", "byte", "ushort", "short", "undefined4", "longlong", "ulonglong",
        "bool", "code", "VEC3", "ObjMove", "Main", "MoveVBase"}


def callees(txt):
    body = txt.split("{", 1)[1] if "{" in txt else txt
    c = []
    for m in CALL.finditer(body):
        n = m.group(1)
        if n in SKIP or n.startswith("("):
            continue
        if n not in c:
            c.append(n)
    return c


def main(argv):
    rows = load_index()
    g = armdis.game("3dx_v12")
    if argv[0] == "--func":
        for a in argv[1:]:
            _, t = text_of(rows, int(a, 0))
            print(t)
            print()
        return
    _tbl, first, trows = btl_aitbl.battle_table(g)
    hand = {op: ptr for op, ptr, _adj in trows}
    if argv[0] == "--ops":
        ops = [int(x, 0) for x in argv[1:]]
        counts = {}
    else:
        import btl_bai
        name = argv[0] if argv[0].endswith(".bai") else argv[0] + ".bai"
        lo = int(argv[1], 0) if len(argv) > 1 else 0
        hi = int(argv[2], 0) if len(argv) > 2 else 1 << 30
        dt = btl_bai.descs()
        files = btl_bai.load()
        ins, _ = btl_bai.decode_all(files[name], dt)
        counts = Counter(i[1] for i in ins if lo <= i[0] < hi and i[1] is not None and i[1] >= 0x4E)
        ops = sorted(counts)
    for op in ops:
        h = follow(g, hand[op])
        fn, t = text_of(rows, h)
        if t is None:
            print(f"op{op:03x} x{counts.get(op, '-')} handler {h:#x}: no decomp")
            continue
        cs = callees(t)
        cases = sorted(set(re.findall(r"case (0x[0-9a-f]+):", t)))
        mark = f" cases={','.join(cases)}" if cases else ""
        print(f"op{op:03x} x{counts.get(op, '-')} -> {h:#x} {fn[1]}{mark}: {', '.join(cs[:14])}")


if __name__ == "__main__":
    main(sys.argv[1:])
