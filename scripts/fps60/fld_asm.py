"""FLD workstream: assembly-level scan of the field function set for per-call counters (read-only).

    python scripts/fps60/fld_asm.py scan [--depth N] [--fn ADDR ...] > out.txt
    python scripts/fps60/fld_asm.py fn <addr> [<addr> ...]      # scan only these functions (any module)

Detects, inside one function (ARM mode, capstone linear sweep):
  INC   ldr{,b,h,sb,sh} rT,[rN,#o] -> add/sub rD,rT,#k (1<=k<=4) -> str{,b,h} rD,[rN,#o]   (member counter)
  FINC  vldr sX,[rN,#o] -> vadd/vsub sY,sX,sC (sC a literal float) -> vstr sY,[rN,#o]   (member float += const)
  LERP  vldr sM,[rN,#o] ... vmla/vmls sM,sA,sC (sC literal) ... vstr sM,[rN,#o]           (per-call smoothing)
For each hit: the compare that follows (cmp/vcmp with a literal) if any.
Field set = fld_scan.field_set() + the field event command handlers that Ghidra did not make functions of.
"""
from __future__ import annotations

import os
import re
import struct
import sys

import capstone

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import armdis  # noqa: E402
import fld_dc  # noqa: E402
import fld_scan  # noqa: E402

LDR = re.compile(r"^ldr(b|h|sb|sh)?$")
STR = re.compile(r"^str(b|h)?$")
MEM = re.compile(r"^(\w+), \[(\w+)(?:, #(-?0x[0-9a-f]+|-?\d+))?\]$")
ADDI = re.compile(r"^(add|sub)s?$")
REGW = re.compile(r"^(\w+)")


def fimm(g, a, ops):
    m = re.search(r"\[pc, #(-?0x[0-9a-f]+|-?\d+)\]", ops)
    if m:
        v = g.u32(a + 8 + int(m.group(1), 0))
        if v is None:
            return None
        return struct.unpack("<f", struct.pack("<I", v))[0]
    m = re.search(r"#(-?[0-9.]+(?:e[+-]?\d+)?)$", ops)
    if m:
        try:
            return float(m.group(1))
        except ValueError:
            return None
    return None


class Scanner:
    def __init__(self):
        self.g = armdis.Game("3dx_v12")
        self.md = capstone.Cs(capstone.CS_ARCH_ARM, capstone.CS_MODE_ARM)

    def insns(self, start, end):
        data = self.g.read(start, end - start)
        out = []
        off = 0
        while off < len(data):
            n0 = off
            for (a, size, mn, ops) in self.md.disasm_lite(data[off:], start + off):
                out.append((a, mn, ops))
                off += size
            if off == n0 or off < len(data):
                if off < len(data):
                    out.append((start + off, ".word", ""))
                    off += 4
        return out

    def scan(self, start, end):
        ins = self.insns(start, end)
        hits = []
        # float constants defined in the function: sreg -> (value, addr)
        fconst = {}
        for idx, (a, mn, ops) in enumerate(ins):
            if mn.startswith(("vldr", "vmov.f32")) and "[pc" in ops or (mn.startswith("vmov.f32") and "#" in ops):
                r = ops.split(",")[0].strip()
                v = fimm(self.g, a, ops)
                if v is not None:
                    fconst.setdefault(r, []).append((a, v))
        for i, (a, mn, ops) in enumerate(ins):
            if LDR.match(mn):
                m = MEM.match(ops)
                if not m:
                    continue
                rt, rn, off = m.group(1), m.group(2), m.group(3) or "0"
                if rn == "pc" or rn == "sp":
                    continue
                for j in range(i + 1, min(i + 5, len(ins))):
                    a2, mn2, ops2 = ins[j]
                    p = [x.strip() for x in ops2.split(",")]
                    if ADDI.match(mn2) and len(p) == 3 and p[1] == rt and p[2].startswith("#"):
                        k = int(p[2][1:], 0)
                        if not 1 <= k <= 4:
                            break
                        rd = p[0]
                        for t in range(j + 1, min(j + 5, len(ins))):
                            a3, mn3, ops3 = ins[t]
                            m3 = MEM.match(ops3)
                            if STR.match(mn3) and m3 and m3.group(1) == rd and m3.group(2) == rn and (m3.group(3) or "0") == off:
                                cmpv = self.find_cmp(ins, t, rd)
                                hits.append(("INC", a, f"{mn} {ops} ; {mn2} {ops2} ; {mn3} {ops3}", rn, off, ("+" if mn2.startswith("add") else "-") + str(k), cmpv))
                                break
                            if REGW.match(ops3) and REGW.match(ops3).group(1) in (rn, rd) and not STR.match(mn3):
                                break
                        break
                    if REGW.match(ops2) and REGW.match(ops2).group(1) in (rt, rn) and not mn2.startswith(("cmp", "tst", "str", "vstr", "push")):
                        break
            elif mn == "vldr" and "[pc" not in ops:
                m = MEM.match(ops)
                if not m:
                    continue
                sx, rn, off = m.group(1), m.group(2), m.group(3) or "0"
                if rn == "sp":
                    continue
                for j in range(i + 1, min(i + 7, len(ins))):
                    a2, mn2, ops2 = ins[j]
                    p = [x.strip() for x in ops2.split(",")]
                    if mn2 in ("vadd.f32", "vsub.f32") and len(p) == 3 and sx in p[1:]:
                        other = p[2] if p[1] == sx else p[1]
                        c = self.const_before(fconst, other, a2)
                        if c is None:
                            break
                        sy = p[0]
                        for t in range(j + 1, min(j + 7, len(ins))):
                            a3, mn3, ops3 = ins[t]
                            m3 = MEM.match(ops3)
                            if mn3 == "vstr" and m3 and m3.group(1) == sy and m3.group(2) == rn and (m3.group(3) or "0") == off:
                                cmpv = self.find_vcmp(ins, t, sy, fconst)
                                hits.append(("FINC", a, f"{mn} {ops} ; {mn2} {ops2} ; {mn3} {ops3}", rn, off, ("+" if mn2 == "vadd.f32" else "-") + f"{c:g}", cmpv))
                                break
                        break
                    if mn2 == "vmul.f32" and len(p) == 3 and sx in p[1:]:
                        other = p[2] if p[1] == sx else p[1]
                        c = self.const_before(fconst, other, a2)
                        if c is None or c in (1.0, 0.0, -1.0, 2.0, 0.5):
                            break
                        sy = p[0]
                        for t in range(j + 1, min(j + 7, len(ins))):
                            a3, mn3, ops3 = ins[t]
                            m3 = MEM.match(ops3)
                            if mn3 == "vstr" and m3 and m3.group(1) == sy and m3.group(2) == rn and (m3.group(3) or "0") == off:
                                hits.append(("MUL", a, f"{mn} {ops} ; {mn2} {ops2} ; {mn3} {ops3}", rn, off, f"*{c:g}", None))
                                break
                        break
                    if mn2 in ("vmla.f32", "vmls.f32") and len(p) == 3 and p[0] == sx:
                        c = self.const_before(fconst, p[2], a2)
                        if c is None:
                            c = self.const_before(fconst, p[1], a2)
                        if c is None:
                            break
                        for t in range(j + 1, min(j + 7, len(ins))):
                            a3, mn3, ops3 = ins[t]
                            m3 = MEM.match(ops3)
                            if mn3 == "vstr" and m3 and m3.group(1) == sx and m3.group(2) == rn and (m3.group(3) or "0") == off:
                                hits.append(("LERP", a, f"{mn} {ops} ; {mn2} {ops2} ; {mn3} {ops3}", rn, off, f"*{c:g}", None))
                                break
                        break
        return hits

    @staticmethod
    def const_before(fconst, reg, at):
        best = None
        for a, v in fconst.get(reg, []):
            if a < at and (best is None or a > best[0]):
                best = (a, v)
        return best[1] if best and at - best[0] < 0x80 else None

    @staticmethod
    def find_cmp(ins, t, rd):
        for u in range(t + 1, min(t + 9, len(ins))):
            a, mn, ops = ins[u]
            p = [x.strip() for x in ops.split(",")]
            if mn.startswith("cmp") and p and p[0] == rd:
                return p[1]
            if mn in ("bl", "blx", "pop") or mn.startswith("b") and not mn.startswith("bic"):
                if mn in ("bl", "blx"):
                    return None
        return None

    def find_vcmp(self, ins, t, sy, fconst):
        for u in range(t + 1, min(t + 9, len(ins))):
            a, mn, ops = ins[u]
            p = [x.strip() for x in ops.split(",")]
            if mn.startswith("vcmp") and p and sy in p:
                other = p[1] if p[0] == sy else p[0]
                if other.startswith("#"):
                    return other
                c = self.const_before(fconst, other, a)
                return f"{c:g}" if c is not None else other
            if mn in ("bl", "blx"):
                return None
        return None


def main(argv):
    if not argv:
        print(__doc__)
        return
    dc = fld_dc.DC()
    sc = Scanner()
    cmd = argv[0]
    if cmd == "fn":
        targets = []
        for t in argv[1:]:
            r = dc.row(int(t, 16))
            if r:
                targets.append((r["a"], max(r["e"], r["a"] + 4), r["name"]))
        tag = {}
    else:
        depth = int(argv[argv.index("--depth") + 1]) if "--depth" in argv else 3
        seen, cmds = fld_scan.field_set(dc, depth)
        targets = []
        import bisect
        starts = dc.starts
        for a in sorted(seen):
            r = dc.row(a)
            k = bisect.bisect_right(starts, r["a"])
            nxt = starts[k] if k < len(starts) else r["e"]
            # Ghidra treats MoveVBase::stop(int) 0x24F578 as non-returning and cuts function bodies after
            # it (87 functions): scan the raw code up to the next function start instead of Ghidra's end.
            targets.append((r["a"], max(min(nxt, r["a"] + 0x3000), r["a"] + 4), r["name"]))
        data = open(fld_scan.BIN, "rb").read()
        for i, p, adj in fld_scan.cmd_handlers(data):
            if adj & 1 or dc.row(p):
                continue
            k = bisect.bisect_right(starts, p)
            nxt = starts[k] if k < len(starts) else p + 0x400
            targets.append((p, min(nxt, p + 0x800), f"cmd_{i + 0x4E:#x}_nofunc"))
        tag = {a: cmds[a] for a in cmds}
    n = 0
    for s, e, name in sorted(targets):
        hits = sc.scan(s, e)
        if not hits:
            continue
        n += 1
        cm = f" cmd {','.join(hex(c) for c in tag[s])}" if s in tag else ""
        print(f"# {s:#010x} {name}{cm}")
        for k, a, txt, rn, off, d, cmpv in hits:
            print(f"    {k:4s} {a:#010x} [{rn}+{off}] {d:>6s} cmp={cmpv}   {txt}")
    print(f"; {n} functions with hits of {len(targets)} scanned")


if __name__ == "__main__":
    main(sys.argv[1:])
