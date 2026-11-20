"""AUD: build the isFps30 site table (consumer of the result, queried task, first-pass category). Read-only.

    python scripts/fps60/aud_table.py [--md FILE] [--tsv FILE]

For every isFps30 call site (aud_sites.py enumeration) the listing after the call is scanned to find what the
result feeds:
  - the step registers written by `vmov{eq,ne}` / `vldr{eq,ne}` (float 2.0/1.0) or `mov{eq,ne}` (int),
  - the first consumer: a call that receives the step in s0 (callee name), a virtual call (`blx rN`),
    a store of the step (`vstr`), an inline countdown (`vsub` + `vcvt.s32`), or nothing (result unused).
The task the call asks (r0) is guessed from the instructions before the call.
Category (first pass, reviewed by hand in audit_fps_sites.md):
  a = per-frame step (consumer updates something every frame with the step)
  b = latched once (step stored at creation: MCursorBase::init, field-init step)
  c = frame skipping / every-other-frame logic
  d = other (result unused, code-path select, ...)
"""
from __future__ import annotations

import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import aud_sites as A  # noqa: E402
import armdis  # noqa: E402

PER_FRAME_CALLEES = ("Frm::update", "MoveVBase::update", "MoveC::update", "MoveFBase::update",
                     "CellAnime::update", "LytAnim::update", "updateAnimeFrm", "MessageSys::func",
                     "Message::func")
LATCH_CALLEES = ("MCursorBase::init",)

RE_SEL_F = re.compile(r"^(vmov|vldr)(eq|ne)(\.f32)?\s+(s\d+), ")
RE_SEL_I = re.compile(r"^mov(eq|ne)\s+(r\d+|sb|sl|fp|ip), #(0x[0-9a-f]+|\d+)")
RE_COPY = re.compile(r"^vmov\.f32\s+(s\d+), (s\d+)$")
RE_CALL = re.compile(r"^(bl|blx)\s+(#0x[0-9a-f]+|r\d+|ip)(?:\s+; (.*))?$")
RE_VSTR = re.compile(r"^vstr\s+(s\d+), \[(\w+), #(0x[0-9a-f]+)\]")
RE_VSUB = re.compile(r"^vsub\.f32\s+(s\d+), (s\d+), (s\d+)")
RE_VOP = re.compile(r"^(vmul|vadd|vcmpe?|vdiv)\.f32\s+(.*)$")


def task_guess(before: list[str]) -> str:
    txt = "\n".join(before[-8:])
    if "btl::GetMain" in txt:
        return "btl::Main (GetMain)"
    if "=0x3f61c0" in txt:
        return "kj::KJSystem [0x3F61C0]"
    if "=0x3f35f8" in txt:
        return "btl::Main [0x3F35F8+8]"
    if "MComSys::_sys" in txt or re.search(r"ldr\s+r0, \[r[0-9], #4\]$", before[-1] if before else ""):
        return "menu task (MComSys->+4)"
    m = re.search(r"mov\s+r0, (r\d+|sb|sl|fp)$", before[-1] if before else "")
    if m:
        return f"this/{m.group(1)}"
    return "?"


def consumer(after: list[str]) -> tuple[str, list[str], str]:
    """Return (consumer description, step regs, selection kind)."""
    step: set[str] = set()
    ints: set[str] = set()
    sel = ""
    r0_live = True
    for ln in after:
        t = ln.split(": ", 1)[1] if ": " in ln else ln
        m = RE_SEL_F.match(t)
        if m:
            step.add(m.group(4))
            vals = re.findall(r"\(([-0-9.e+]+)\)", t)
            sel = sel or "float"
            continue
        m = RE_SEL_I.match(t)
        if m:
            ints.add(m.group(2))
            sel = sel or "int"
            continue
        m = RE_COPY.match(t)
        if m and m.group(2) in step:
            step.add(m.group(1))
            continue
        if re.match(r"^vmov\s+(s\d+), (r\d+)", t):
            mm = re.match(r"^vmov\s+(s\d+), (r\d+)", t)
            if mm.group(2) in ints:
                step.add(mm.group(1))
            continue
        if re.match(r"^vcvt\.f32\.u32\s+(s\d+), (s\d+)", t):
            mm = re.match(r"^vcvt\.f32\.u32\s+(s\d+), (s\d+)", t)
            if mm.group(2) in step:
                step.add(mm.group(1))
            continue
        m = RE_CALL.match(t)
        if m:
            tgt = m.group(3) or m.group(2)
            if "s0" in step:
                return (f"call {tgt}" if m.group(1) == "bl" else f"virtual call blx {m.group(2)}"), sorted(step), sel
            if not step and not ints and sel == "":
                return f"unused (next call {tgt})", [], sel
            if ints and not step:
                return f"int select → call {tgt}", sorted(ints), sel
            continue
        m = RE_VSTR.match(t)
        if m and m.group(1) in step:
            return f"store [{m.group(2)},#{m.group(3)}]", sorted(step), sel
        m = RE_VSUB.match(t)
        if m and m.group(3) in step:
            return "inline countdown (vsub)", sorted(step), sel
        m = RE_VOP.match(t)
        if m and any(re.search(rf"\b{r}\b", m.group(2)) for r in step):
            return f"inline {m.group(1)}", sorted(step), sel
        if re.match(r"^(pop|bx lr)", t) and "s0" in step:
            return "returned in s0", sorted(step), sel
        if re.match(r"^(b|bl)(eq|ne)\s", t) and not step:
            return "branch on result", [], "branch"
        if re.match(r"^(ldr|mov|add|sub|ldrb|ldrsb)\s+r0, ", t) and not step and not ints and r0_live:
            # r0 overwritten before any use of the result
            prev = "\n".join(x.split(": ", 1)[-1] for x in after[:after.index(ln)])
            if "r0" not in prev and "cmp" not in prev:
                return "unused (r0 overwritten)", [], ""
            r0_live = False
    return "?", sorted(step), sel


def category(cons: str, func: str) -> str:
    if cons.startswith("unused"):
        return "d"
    if any(k in cons for k in LATCH_CALLEES):
        return "b"
    if any(k in cons for k in PER_FRAME_CALLEES):
        return "a"
    if cons.startswith("inline countdown") or cons.startswith("inline v"):
        return "a?"
    if cons.startswith("virtual call"):
        return "b?"
    return "?"


def main(argv) -> None:
    import argparse
    ap = argparse.ArgumentParser()
    ap.add_argument("--md")
    ap.add_argument("--tsv")
    args = ap.parse_args(argv)
    rows = []
    n = 0
    for a, kind in armdis.callers(A.GAME, A.ISFPS30):
        if kind == "literal":
            continue
        n += 1
        m = A.module_of(a)
        r = A.fn_of(a)
        fstart = r.addr if r else A.listing_fn_start(m, a)
        fname = r.name if r else f"(no Ghidra fn; push @{fstart:#x})"
        before = A.dis_window(m, a, 8, 0)[:-1]
        after = A.dis_window(m, a + 4, 0, 29)
        cons, regs, sel = consumer(after)
        cat = category(cons, fname)
        rows.append(dict(n=n, site=a, ret=a + 4, module=m, loc=A.loc(a), func=fname, fstart=fstart,
                         off=a - fstart, task=task_guess(before), cons=cons, sel=sel, cat=cat))
    if args.tsv:
        with open(args.tsv, "w", encoding="utf-8") as f:
            f.write("n\tret\tmodule\tloc\tfunc\tfstart\toff\ttask\tconsumer\tsel\tcat\n")
            for x in rows:
                f.write(f"{x['n']}\t{x['ret']:#x}\t{x['module']}\t{x['loc']}\t{x['func']}\t{x['fstart']:#x}\t"
                        f"{x['off']:#x}\t{x['task']}\t{x['cons']}\t{x['sel']}\t{x['cat']}\n")
    out = open(args.md, "w", encoding="utf-8") if args.md else sys.stdout
    for x in rows:
        print(f"| {x['n']} | {x['loc']} | {x['ret']:#x} | {x['func']} (+{x['off']:#x}) | {x['task']} | "
              f"{x['cons']} | {x['cat']} |", file=out)
    from collections import Counter
    c = Counter((x["module"], x["cat"]) for x in rows)
    print("; " + ", ".join(f"{k[0]}:{k[1]}={v}" for k, v in sorted(c.items())), file=out)


if __name__ == "__main__":
    main(sys.argv[1:])
