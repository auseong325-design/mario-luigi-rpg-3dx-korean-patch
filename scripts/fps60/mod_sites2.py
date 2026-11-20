"""Resolve what every isFps30 call site selects and who consumes it (MOD2 workstream).

    python scripts/fps60/mod_sites2.py [game] [--module NAME] [--win N]
    python scripts/fps60/mod_sites2.py [game] --prims [--module NAME]   # literal steps passed to update primitives

For each call to ad::fw::TaskBase::isFps30 (direct BL or CRO veneer) this looks at the next N instructions
(default 14) for the conditional selects that use the result (vmovne/vmoveq/vldrne/vldreq/movne/moveq), resolves
the selected registers back to their constants inside the function (one-hop register copies followed), and
names the first call that receives s0/r0 afterwards (the consumer). Output, one line per site:

    <site> [module] <function label> | sel: ne=<val> eq=<val> | consumer: <name> | verdict

verdict: STEP (2.0 when 30fps / 1.0 when 60fps), INT-STEP (2/1 integers), DISCARD (result never tested),
ODD (anything else: read it).
"""
from __future__ import annotations

import os
import re
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import armdis  # noqa: E402
import mod_fn  # noqa: E402
import mod_hardstep  # noqa: E402

ISFPS30 = 0x25EDD0
COND = r"(eq|ne)"


def _def_value(c, a, mnem, ops):
    """If (mnem, ops) at a defines an s-reg from a constant, return (dst, value-str); copies -> (dst, '=sN')."""
    parts = [p.strip() for p in ops.split(",", 1)]
    if len(parts) != 2 or not re.fullmatch(r"s\d+", parts[0]):
        return None
    dst, src = parts
    if mnem == "vldr":
        f = mod_hardstep.lit_float(c.g, a, ops)
        return (dst, f"{f:g}" if f is not None else f"mem[{src}]")
    if mnem == "vmov.f32":
        if re.fullmatch(r"s\d+", src):
            return (dst, "=" + src)
        f = mod_hardstep.imm_float(src)
        if f is not None:
            return (dst, f"{f:g}")
    if mnem.startswith(("vcvt", "vmul", "vadd", "vsub", "vdiv", "vneg", "vabs", "vmla", "vnmul", "vsqrt")):
        return (dst, f"calc({mnem})")
    if mnem.startswith(("vmov", "vldr", "vcvt", "vmul", "vadd", "vsub", "vdiv")):
        return (dst, f"cond({mnem} {ops})")
    return None


def resolve(c, fs, site, reg, depth=0):
    """Value of s-reg `reg` just before `site`: walk back to the function start, ignoring early-return pops
    (callee-saved s16-s31 are normally loaded once at entry). Follows register copies up to 3 hops."""
    if reg.startswith("#"):
        return reg[1:]
    cs = armdis.md(False)
    a = site - 4
    n = int(reg[1:]) if re.fullmatch(r"s\d+", reg) else 99
    while a >= fs:
        ins = list(cs.disasm_lite(c.g.read(a, 4), a))
        if ins:
            _, _, mnem, ops = ins[0]
            if mnem in ("bl", "blx") and n < 16 and a != site - 4:
                return f"callret@{a:#x}"
            d = _def_value(c, a, mnem, ops)
            if d and d[0] == reg:
                if d[1].startswith("=") and depth < 3:
                    return resolve(c, fs, a, d[1][1:], depth + 1)
                return d[1]
        a -= 4
    return "arg"


def prims(name, mod):
    """For every update-primitive call (mod_hardstep.PRIMS) resolve the s0 step argument with resolve()."""
    c = mod_fn.Ctx(name)
    from collections import Counter
    stats = Counter()
    for t, pname in mod_hardstep.PRIMS.items():
        for a, kind in armdis.callers(name, t):
            if kind == "literal":
                continue
            m = c.g.module_of(a)
            if mod and m != mod:
                continue
            fs = c.fn_start(a)
            v = resolve(c, fs, a, "s0")
            cls = "CONST" if re.fullmatch(r"-?[\d.e+]+", v) else v.split("(")[0].split("@")[0]
            stats[(m, cls)] += 1
            if cls == "CONST":
                print(f"{a:#010x} [{m}] {pname:36s} in {c.label(fs)} ({fs:#x}) => s0 = {v}")
    print("; summary (module, class, count):")
    for (m, v), n in sorted(stats.items()):
        print(f";   {m:16s} {v:12s} {n}")


def main(argv):
    name = argv[0] if argv and argv[0] in armdis.GAMES else "3dx_v12"
    args = argv[1:] if argv and argv[0] in armdis.GAMES else argv
    mod = args[args.index("--module") + 1] if "--module" in args else None
    if "--prims" in args:
        prims(name, mod)
        return
    win = int(args[args.index("--win") + 1]) if "--win" in args else 14
    c = mod_fn.Ctx(name)
    cs = armdis.md(False)
    from collections import Counter
    stats = Counter()
    for a, kind in armdis.callers(name, ISFPS30):
        if kind == "literal":
            continue
        m = c.g.module_of(a)
        if mod and m != mod:
            continue
        fs = c.fn_start(a)
        sel = {}
        consumer = None
        tested = False
        r0_dead = False
        local = {}  # unconditional s-reg defs inside the window
        for k in range(1, win + 1):
            ia = a + 4 * k
            ins = list(cs.disasm_lite(c.g.read(ia, 4), ia))
            if not ins:
                break
            _, _, mnem, ops = ins[0]
            dv = _def_value(c, ia, mnem, ops)
            if dv and not dv[1].startswith("cond("):
                val = dv[1]
                if val.startswith("="):
                    val = local.get(val[1:]) or resolve(c, fs, a, val[1:])
                if dv[0] in sel:  # overwritten after the select: stop tracking
                    pass
                local[dv[0]] = val
                continue
            if mnem == "cmp" and ops.startswith("r0, #0") and not r0_dead:
                tested = True
                continue
            if mnem == "tst" and ops.startswith("r0,") and not r0_dead:
                tested = True
                continue
            mm = re.match(r"^(vmov|vldr|mov)" + COND + r"(\.f32)?$", mnem)
            if mm and tested:
                cond = mm.group(2)
                parts = [p.strip() for p in ops.split(",", 1)]
                dst, src = parts[0], parts[1]
                if mm.group(1) == "vldr":
                    f = mod_hardstep.lit_float(c.g, ia, ops)
                    val = f"{f:g}" if f is not None else src
                elif src.startswith("#"):
                    val = src[1:]
                else:
                    val = local.get(src) or resolve(c, fs, a, src)
                sel.setdefault(dst, {})[cond] = val
                continue
            if re.match(r"^(mov|ldr|add|sub|rsb|and|orr)\b", mnem) and ops.startswith("r0,") and not tested:
                r0_dead = True
            if mnem in ("bl", "blx") or mnem.startswith("b") and mnem in ("b",):
                if mnem in ("bl", "blx"):
                    t = int(ops[1:], 16) if ops.startswith("#") else None
                    note = armdis.annotate(c.g, ia, mnem, ops, False).strip("; ").strip()
                    consumer = note or (c.label(t) if t else ops)
                break
        # fill the "other" branch of single-sided selects from the register's previous value
        for dst, d in sel.items():
            for cond, other in (("eq", "ne"), ("ne", "eq")):
                if cond in d and other not in d:
                    d[other] = (local.get(dst) or resolve(c, fs, a, dst)) + "(pre)"
        desc = "; ".join(f"{dst}: ne={d.get('ne')} eq={d.get('eq')}" for dst, d in sel.items())
        if not tested:
            verdict = "DISCARD" if r0_dead else "ODD"
        else:
            vals = [(d.get("ne", ""), d.get("eq", "")) for d in sel.values()]
            def is2(x):
                return x.split("(")[0] in ("2", "2.0")
            def is1(x):
                return x.split("(")[0] in ("1", "1.0")
            if vals and all(is2(ne) and is1(eq) for ne, eq in vals):
                verdict = "STEP"
                if any(not dst.startswith("s") for dst in sel):
                    verdict = "INT-STEP"
            else:
                verdict = "ODD"
        stats[(m, verdict)] += 1
        print(f"{a:#010x} [{m}] {c.label(fs)} ({fs:#x}) | sel: {desc or '-'} | consumer: {consumer or '-'} | {verdict}")
    print("; summary (module, verdict, count):")
    for (m, v), n in sorted(stats.items()):
        print(f";   {m:16s} {v:9s} {n}")


if __name__ == "__main__":
    main(sys.argv[1:])
