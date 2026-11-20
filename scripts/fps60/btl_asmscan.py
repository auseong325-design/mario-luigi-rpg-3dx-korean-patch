"""BTL2: assembly-level scan for per-call integer field counters in battle code.

    python scripts/fps60/btl_asmscan.py [--out file.tsv] [--module Battle|static] [--name REGEX]

Works on the armdis listings (work/fps60/dis/3dx_v12/<module>.s) and the function index
(work/fps60/decomp/3dx_v12/functions.tsv), so it is not affected by Ghidra's decompiler cutting a function
after a call it believes does not return (MoveVBase::stop 0x24F578, 87 functions, lead note 2026-10-30).

A hit is `ldr{,b,h} rX,[rB,#off]` ... `add|sub rX,rX,#c` ... `str{,b,h} rX,[rB,#off]` within 6 instructions
(same base register, same offset, no intervening redefinition of rB). Per function: hits (field +/-c), whether
the field is also loaded and compared with an immediate (`cmp rY,#imm` within 3 instructions of the load),
and whether the function reads a step (calls isFps30 / calcUpdateSpd, or loads [rN,#0x15c] / [rN,#0x244]).
Candidates only; read the code before concluding. Read-only.
"""
from __future__ import annotations

import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(os.path.dirname(HERE))
DIS = os.path.join(ROOT, "work", "fps60", "dis", "3dx_v12")
IDX = os.path.join(ROOT, "work", "fps60", "decomp", "3dx_v12", "functions.tsv")
STATIC_BTL = [(0x1C8000, 0x23F000), (0x285000, 0x2A0000), (0x34F000, 0x356000)]
LINE = re.compile(r"^([0-9a-f]{8}):\s+(\S+)\s*(.*)$")
LD = re.compile(r"^ldr(b|h|sb|sh)?$")
ST = re.compile(r"^str(b|h)?$")
MEM = re.compile(r"^(r\d+|sb|sl|fp|ip|lr), \[(r\d+|sb|sl|fp|ip|sp|lr)(?:, #(-?0x[0-9a-f]+|-?\d+))?\]$")
ADD = re.compile(r"^(r\d+|sb|sl|fp|ip|lr), (r\d+|sb|sl|fp|ip|lr), #(-?0x[0-9a-f]+|-?\d+)$")
CMP = re.compile(r"^(r\d+|sb|sl|fp|ip|lr), #(-?0x[0-9a-f]+|-?\d+)$")
STEP = re.compile(r"isFps30|calcUpdateSpd|#0x15c\]|#0x244\]")


def num(s):
    return int(s, 0) if s else 0


def load_index(module):
    rows = []
    with open(IDX, encoding="utf-8") as fh:
        next(fh)
        for ln in fh:
            c = ln.rstrip("\n").split("\t")
            if len(c) < 5 or c[3] != module:
                continue
            a, size, name = int(c[0], 16), int(c[2], 16), c[4]
            if name.startswith("->"):
                continue
            if module == "static" and not (name.startswith("btl::") or
                                           (name.startswith("FUN_") and any(lo <= a < hi for lo, hi in STATIC_BTL))):
                continue
            rows.append((a, a + size, name))
    return sorted(rows)


def load_listing(module):
    ins = {}
    with open(os.path.join(DIS, f"{module}.s"), encoding="utf-8", errors="replace") as fh:
        for ln in fh:
            m = LINE.match(ln.strip())
            if m:
                ins[int(m.group(1), 16)] = (m.group(2), m.group(3))
    return ins


def scan(module, name_re=None):
    funcs = load_index(module)
    ins = load_listing(module)
    out = []
    for lo, hi, name in funcs:
        if name_re and not re.search(name_re, name):
            continue
        seq = [(a, ins[a]) for a in range(lo, hi, 4) if a in ins]
        text = " ".join(m + " " + o for _, (m, o) in seq)
        step = bool(STEP.search(text))
        cmpd = set()
        for k, (a, (mn, op)) in enumerate(seq):
            if LD.match(mn):
                mm = MEM.match(op)
                if not mm:
                    continue
                rd, base, off = mm.group(1), mm.group(2), num(mm.group(3))
                for a2, (mn2, op2) in seq[k + 1:k + 4]:
                    cm = CMP.match(op2) if mn2 == "cmp" else None
                    if cm and cm.group(1) == rd:
                        cmpd.add((base, off, num(cm.group(2))))
        for k, (a, (mn, op)) in enumerate(seq):
            if not LD.match(mn):
                continue
            mm = MEM.match(op)
            if not mm:
                continue
            rd, base, off = mm.group(1), mm.group(2), num(mm.group(3))
            if base == "sp":
                continue
            for j in range(k + 1, min(k + 7, len(seq))):
                a2, (mn2, op2) = seq[j]
                am = ADD.match(op2) if mn2 in ("add", "sub") else None
                if am and am.group(1) == rd and am.group(2) == rd:
                    c = num(am.group(3)) * (1 if mn2 == "add" else -1)
                    for a3, (mn3, op3) in seq[j + 1:j + 4]:
                        sm = MEM.match(op3) if ST.match(mn3) else None
                        if sm and sm.group(1) == rd and sm.group(2) == base and num(sm.group(3)) == off:
                            cmps = sorted({v for b, o, v in cmpd if o == off})
                            out.append((module, lo, name, a, off, c, cmps, step))
                            break
                    break
                if op2.startswith(base + ",") or op2.startswith(rd + ","):
                    break
    return out


def main(argv):
    outp = argv[argv.index("--out") + 1] if "--out" in argv else None
    mods = [argv[argv.index("--module") + 1]] if "--module" in argv else ["static", "Battle"]
    name_re = argv[argv.index("--name") + 1] if "--name" in argv else None
    lines = ["module\tfunc\tname\tat\tfield_off\tdelta\tcompared_with\tstep_in_func"]
    for m in mods:
        for module, lo, name, a, off, c, cmps, step in scan(m, name_re):
            lines.append(f"{module}\t{lo:#x}\t{name}\t{a:#x}\t{off:#x}\t{c}\t{','.join(map(str, cmps))}\t"
                         f"{'yes' if step else ''}")
    text = "\n".join(lines) + "\n"
    if outp:
        with open(outp, "w", encoding="utf-8", newline="\n") as fh:
            fh.write(text)
        print(f"wrote {outp}: {len(lines) - 1} hits")
    else:
        sys.stdout.write(text)


if __name__ == "__main__":
    main(sys.argv[1:])
