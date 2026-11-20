"""D1X helper: call-site context with function boundaries (uses armdis.py as a library, read-only).

    python scripts/fps60/d1x_ctx.py <game> sites <target-addr> [before] [after]   # every caller of target
    python scripts/fps60/d1x_ctx.py <game> at <addr> [<addr> ...] [--before N] [--after N]
    python scripts/fps60/d1x_ctx.py <game> func <addr>                            # whole containing function
    python scripts/fps60/d1x_ctx.py <game> fstart <addr>                          # containing function start

Function starts = BL/B targets + symbol addresses + aligned text pointers found in data/rodata/literal pools.
"""
from __future__ import annotations

import bisect
import os
import struct
import sys
from functools import lru_cache

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import armdis  # noqa: E402


@lru_cache(maxsize=None)
def func_starts(name: str) -> list[int]:
    g = armdis.game(name)
    starts: set[int] = set()
    text = [(s, e) for _, s, e in g.text_ranges]

    def in_text(a: int) -> bool:
        return any(s <= a < e for s, e in text)

    for mod, start, end in g.text_ranges:
        data = g.read(start, end - start)
        for off in range(0, len(data) - 3, 4):
            w = struct.unpack_from("<I", data, off)[0]
            if (w >> 24) & 0x0F == 0x0B and (w >> 28) != 0xF:  # BL only (B is often intra-function)
                t = armdis.branch_target(w, start + off)
                if t is not None and in_text(t):
                    starts.add(t)
            # push {..., lr} = stmdb sp!, {..lr}
            if (w & 0x0FFF4000) == 0x092D4000:
                starts.add(start + off)
    for a in g.a2s:
        if not g.a2s[a].startswith("veneer->"):
            starts.add(a & ~1)
    for base, data, mod in g.regions:
        for off in range(0, len(data) - 3, 4):
            v = struct.unpack_from("<I", data, off)[0]
            if v & 3 == 0 and in_text(v):
                # only accept pointer targets that look like code entries (push/mov/ldr/bx etc.)
                starts.add(v)
    return sorted(starts)


def fstart(name: str, addr: int) -> int:
    s = func_starts(name)
    i = bisect.bisect_right(s, addr) - 1
    return s[i] if i >= 0 else addr


def fend(name: str, addr: int) -> int:
    s = func_starts(name)
    i = bisect.bisect_right(s, addr)
    return s[i] if i < len(s) else addr + 0x400


def rdisasm(name: str, addr: int, count: int) -> list[str]:
    """Word-by-word ARM disassembly that never stops on data words."""
    g = armdis.game(name)
    cs = armdis.md(False)
    out = []
    for i in range(count):
        a = addr + 4 * i
        b = g.read(a, 4)
        if len(b) < 4:
            break
        label = f"<{armdis.demangle_hint(g.a2s[a])}>\n" if a in g.a2s and i else ""
        ins = list(cs.disasm_lite(b, a))
        if ins:
            _, _, mnem, ops = ins[0]
            out.append(f"{label}{a:08x}: {b.hex():8s} {mnem:8s} {ops}{armdis.annotate(g, a, mnem, ops, False)}")
        else:
            out.append(f"{label}{a:08x}: {b.hex():8s} .word    {struct.unpack('<I', b)[0]:#010x}")
    return out


def show(name: str, addr: int, before: int, after: int) -> str:
    fs = fstart(name, addr)
    lo = max(fs, addr - 4 * before)
    lines = rdisasm(name, lo, (addr - lo) // 4 + after + 1)
    head = f"== site {addr:#x}  func {fs:#x} ({armdis.where(name, fs)})"
    return head + "\n" + "\n".join(("=> " if l.startswith(f"{addr:08x}") else "   ") + l for l in lines)


def rtti_name(name: str, vtable: int) -> str:
    """vtable -> mangled class name via typeinfo (Itanium ABI: vtable[-1] = &typeinfo, typeinfo[1] = name)."""
    g = armdis.game(name)
    ti = g.u32(vtable - 4)
    if not ti:
        return "?"
    p = g.u32(ti + 4)
    if not p:
        return "?"
    s = g.read(p, 200).split(b"\0")[0]
    try:
        return s.decode("ascii")
    except UnicodeDecodeError:
        return "?"


def reg_writes(name: str, lo: int, hi: int, reg: str) -> list[str]:
    """Instructions in [lo, hi) that write register `reg` (capstone detail)."""
    import capstone
    g = armdis.game(name)
    cs = capstone.Cs(capstone.CS_ARCH_ARM, capstone.CS_MODE_ARM)
    cs.detail = True
    out = []
    for a in range(lo, hi, 4):
        b = g.read(a, 4)
        for ins in cs.disasm(b, a):
            try:
                _, w = ins.regs_access()
            except capstone.CsError:
                continue
            if reg in [ins.reg_name(r) for r in w]:
                out.append(f"{a:08x}: {ins.mnemonic} {ins.op_str}")
    return out


def pstart(name: str, addr: int, limit: int = 0x20000) -> int:
    """Nearest preceding 'push {..., lr}' (stmdb sp!, {...lr}) at or before addr."""
    g = armdis.game(name)
    a = addr & ~3
    while a > addr - limit:
        w = g.u32(a)
        if w is not None and (w & 0x0FFF4000) == 0x092D4000 and (w >> 28) == 0xE:
            return a
        a -= 4
    return addr


def branches_into(name: str, lo: int, hi: int, tlo: int, thi: int) -> list[str]:
    """Branch instructions located in [lo, hi) whose target falls in [tlo, thi)."""
    g = armdis.game(name)
    out = []
    for a in range(lo, hi, 4):
        w = g.u32(a)
        if w is None:
            continue
        t = armdis.branch_target(w, a)
        if t is not None and tlo <= t < thi:
            out.append(f"{a:08x} -> {t:08x}")
    return out


def vtables(name: str, needle: str, nent: int = 12) -> list[str]:
    """Find vtables whose RTTI class name contains `needle` (Itanium ABI layout, all regions)."""
    g = armdis.game(name)
    import re as _re
    out = []
    for base, data, mod in g.regions:
        names = {}
        for m in _re.finditer(rb"[0-9]+[A-Za-z_][A-Za-z0-9_]*\x00|N[0-9][A-Za-z0-9_]+E\x00", data):
            s = m.group()[:-1].decode("ascii", "replace")
            if needle in s:
                names[base + m.start()] = s
        if not names:
            continue
        for b2, d2, m2 in g.regions:
            n = len(d2) // 4
            words = struct.unpack_from(f"<{n}I", d2)
            tis = {}
            for i in range(1, n):
                if words[i] in names:
                    tis[b2 + 4 * (i - 1)] = names[words[i]]
            if not tis:
                continue
            for i in range(n - 1):
                if words[i] in tis and i > 0 and words[i - 1] in (0, 0xFFFFFFF8, 0xFFFFFFFC, 0xFFFFFFF0) or \
                        (words[i] in tis and i > 0 and words[i - 1] > 0x80000000):
                    vt = b2 + 4 * (i + 1)
                    ents = words[i + 1:i + 1 + nent]
                    out.append(f"{vt:#010x} {tis[words[i]]} [{m2}]: " + " ".join(f"{e:#x}" for e in ents))
    return out


def main(argv: list[str]) -> None:
    name, cmd, *rest = argv
    if cmd == "vtables":
        n = int(rest[1]) if len(rest) > 1 else 12
        print("\n".join(vtables(name, rest[0], n)))
        return
    if cmd == "binto":
        lo, hi, tlo, thi = (int(x, 0) for x in rest[:4])
        print("\n".join(branches_into(name, lo, hi, tlo, thi)))
        return
    if cmd == "pstart":
        for tok in rest:
            a = int(tok, 0)
            p = pstart(name, a)
            print(f"{a:#x} -> push-start {p:#x}  {armdis.where(name, p)}")
        return
    if cmd == "rtti":
        for tok in rest:
            v = int(tok, 0)
            print(f"{v:#x} {rtti_name(name, v)}")
        return
    if cmd == "regw":
        lo, hi, reg = int(rest[0], 0), int(rest[1], 0), rest[2]
        print("\n".join(reg_writes(name, lo, hi, reg)))
        return
    if cmd == "sites":
        t = int(rest[0], 0)
        before = int(rest[1]) if len(rest) > 1 else 8
        after = int(rest[2]) if len(rest) > 2 else 12
        for a, kind in armdis.callers(name, t):
            if kind == "literal":
                continue
            print(show(name, a, before, after))
            print()
    elif cmd == "at":
        before, after, addrs = 8, 12, []
        it = iter(rest)
        for tok in it:
            if tok == "--before":
                before = int(next(it))
            elif tok == "--after":
                after = int(next(it))
            else:
                addrs.append(int(tok, 0))
        for a in addrs:
            print(show(name, a, before, after))
            print()
    elif cmd == "func":
        a = int(rest[0], 0)
        fs, fe = fstart(name, a), fend(name, a)
        print(f"== func {fs:#x}..{fe:#x} ({armdis.where(name, fs)})")
        print("\n".join(rdisasm(name, fs, (fe - fs) // 4)))
    elif cmd == "range":
        lo, hi = int(rest[0], 0), int(rest[1], 0)
        print("\n".join(rdisasm(name, lo, (hi - lo) // 4)))
    elif cmd == "fstart":
        for tok in rest:
            a = int(tok, 0)
            print(f"{a:#x} -> {fstart(name, a):#x} .. {fend(name, a):#x}  {armdis.where(name, fstart(name, a))}")


if __name__ == "__main__":
    main(sys.argv[1:])
