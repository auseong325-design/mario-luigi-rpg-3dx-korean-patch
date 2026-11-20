"""FEV Q4: who writes the factors of the field step `fld::System+0x1A4C = (isFps30?2:1) x [[sys+0x574]+0x7C] x
sys+0x1A48`? Scans the ARM listings `work/fps60/dis/3dx_v12/*.s` (static + every CRO) with a small register tracker:

    python scripts/fps60/fev_q4.py scan [--all]

Tracked forms: `add/sub rd, rs, #imm`, `mov rd, rs`, `ldr rd, [rs, #imm]` (word load), `ldr rd, [pc, ...] ; =VALUE`,
`movw/movt`. A store (`str*`, `vstr`, `stm*` first slot) is reported when its address is
  A  base + 0x1A48 for any base register / loaded pointer       (field fast-forward factor, also other classes)
  B  [[x + 0x574] + 0x7C]                                       (global game speed via TaskBase+0x574)
  C  0x412C80 (+0..3)                                           (fast-forward value read by FUN_0031EC90)
  D  base + 0x1A4C                                              (the field step itself)
State is reset after unconditional branches/returns and at symbol labels; bl/blx clobber r0-r3, r12, lr.
It is a heuristic (straight-line, no merge of paths): every hit is read by hand. `--all` also prints loads.
"""
from __future__ import annotations

import glob
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(os.path.dirname(HERE))
DIS = os.path.join(ROOT, "work", "fps60", "dis", "3dx_v12")

LINE = re.compile(r"^([0-9a-f]{8}):\s+(?:[0-9a-f]{8}\s+)?([a-z][a-z0-9.]*)\s*(.*)$")
REG = r"(r\d+|ip|lr|sp|fp|sl|sb|pc)"
ALIAS = {"ip": "r12", "lr": "r14", "sp": "r13", "fp": "r11", "sl": "r10", "sb": "r9", "pc": "r15"}
COND = r"(?:eq|ne|cs|hs|cc|lo|mi|pl|vs|vc|hi|ls|ge|lt|gt|le|al)?"


def rn(r: str) -> str:
    return ALIAS.get(r, r)


def imm(s: str) -> int:
    s = s.strip().lstrip("#")
    return int(s, 16) if s.lower().startswith(("0x", "-0x")) else int(s)


class Tracker:
    def __init__(self):
        self.v: dict[str, tuple] = {}
        self.seq = 0

    def get(self, r):
        r = rn(r)
        if r not in self.v:
            self.seq += 1
            self.v[r] = (("R", r, self.seq), 0)
        return self.v[r]

    def kill(self, r):
        self.v.pop(rn(r), None)


def scan_file(path: str, show_loads: bool):
    module = os.path.splitext(os.path.basename(path))[0]
    t = Tracker()
    hits = []
    for raw in open(path, encoding="utf-8", errors="replace"):
        if not raw.strip():
            continue
        if not raw[0].isdigit() and not raw[0] in "abcdef":
            if raw.startswith((";", "<", "|")) or raw.rstrip().endswith(":"):
                t = Tracker()            # label / symbol line: new straight-line block
            continue
        m = LINE.match(raw.strip())
        if not m:
            continue
        addr, mn, ops = int(m.group(1), 16), m.group(2), m.group(3)
        lit = None
        if "; =" in ops:
            ops, c = ops.split("; =", 1)
            try:
                lit = int(c.split()[0], 16)
            except ValueError:
                lit = None
        ops = ops.strip()
        base_mn = re.sub(COND + r"$", "", mn) if not mn.startswith(("b", "bl")) else mn
        # ---- stores
        sm = re.match(r"^(str|strb|strh|strd|vstr|vstr\.32|vstr\.64|stm|stmia|stmib|stmda|stmdb|vstm|vstmia)" + COND
                      + r"(\.\w+)?$", mn)
        if sm:
            am = re.search(r"\[" + REG + r"(?:,\s*#(-?0x[0-9a-f]+|-?\d+))?\]", ops)
            rm = re.search(r"\[" + REG + r",\s*" + REG + r"\]", ops)
            sb = re.match(r"^" + REG + r"!?,\s*\{", ops)
            eff = None
            if am:
                b, o = t.get(am.group(1))
                eff = (b, o + (imm(am.group(2)) if am.group(2) else 0))
            elif rm:
                b, o = t.get(rm.group(1))
                b2, o2 = t.get(rm.group(2))
                if b2[0] == "C":
                    eff = (b, o + b2[1] + o2)
            elif sb:
                eff = t.get(sb.group(1))
            if eff:
                b, o = eff
                tag = None
                if o == 0x1A48:
                    tag = "A"
                elif o == 0x1A4C:
                    tag = "D"
                elif o == 0x7C and b[0] == "L" and b[2] == 0x574:
                    tag = "B"
                elif b[0] == "C" and 0x412C80 <= b[1] + o < 0x412C84:
                    tag = "C"
                if tag:
                    hits.append((tag, module, addr, mn, ops))
            if "!" in ops and am:
                t.kill(am.group(1))
            continue
        # ---- register definitions
        dm = re.match(r"^" + REG + r"(?:,|$)", ops)
        rd = dm.group(1) if dm else None
        if base_mn in ("add", "sub") and rd:
            mm = re.match(r"^" + REG + r",\s*" + REG + r",\s*#(-?0x[0-9a-f]+|-?\d+)$", ops)
            if mm:
                b, o = t.get(mm.group(2))
                k = imm(mm.group(3))
                t.v[rn(rd)] = (b, o + k if base_mn == "add" else o - k)
                continue
        if base_mn == "mov" and rd:
            mm = re.match(r"^" + REG + r",\s*" + REG + r"$", ops)
            if mm:
                t.v[rn(rd)] = t.get(mm.group(2))
                continue
            mm = re.match(r"^" + REG + r",\s*#(-?0x[0-9a-f]+|-?\d+)$", ops)
            if mm:
                t.v[rn(rd)] = (("C", imm(mm.group(2))), 0)
                continue
        if base_mn == "movw" and rd:
            mm = re.match(r"^" + REG + r",\s*#(0x[0-9a-f]+|\d+)$", ops)
            if mm:
                t.v[rn(rd)] = (("C", imm(mm.group(2))), 0)
                continue
        if base_mn == "movt" and rd:
            mm = re.match(r"^" + REG + r",\s*#(0x[0-9a-f]+|\d+)$", ops)
            b, o = t.get(rd)
            if mm and b[0] == "C":
                t.v[rn(rd)] = (("C", (b[1] & 0xFFFF) | (imm(mm.group(2)) << 16)), 0)
                continue
        if base_mn == "ldr" and rd:
            if lit is not None:
                t.v[rn(rd)] = (("C", lit), 0)
                continue
            mm = re.match(r"^" + REG + r",\s*\[" + REG + r"(?:,\s*#(-?0x[0-9a-f]+|-?\d+))?\]$", ops)
            if mm:
                b, o = t.get(mm.group(2))
                off = o + (imm(mm.group(3)) if mm.group(3) else 0)
                if show_loads and (off in (0x1A48, 0x1A4C) or (off == 0x7C and b[0] == "L" and b[2] == 0x574)):
                    hits.append(("load", module, addr, mn, ops))
                t.v[rn(rd)] = (("L", b, off), 0)
                continue
        if base_mn in ("bl", "blx"):
            for r in ("r0", "r1", "r2", "r3", "r12", "r14"):
                t.kill(r)
            continue
        if mn in ("b", "bx") or (mn.startswith("pop") and "pc" in ops) or (mn.startswith("ldm") and "pc" in ops):
            t = Tracker()
            continue
        if rd and not mn.startswith(("cmp", "cmn", "tst", "teq", "v", "str", "push", "b")):
            t.kill(rd)
        for r in re.findall(r"\{([^}]*)\}", ops):
            if mn.startswith(("pop", "ldm")):
                for x in r.split(","):
                    t.kill(x.strip())
    return hits


def main(argv):
    if not argv or argv[0] != "scan":
        print(__doc__)
        return
    show = "--all" in argv
    tot = 0
    for path in sorted(glob.glob(os.path.join(DIS, "*.s"))):
        for tag, module, addr, mn, ops in scan_file(path, show):
            tot += 1
            print(f"{tag:4s} {module:14s} {addr:08x}: {mn} {ops}")
    print(f"; {tot} hits")


if __name__ == "__main__":
    main(sys.argv[1:])
