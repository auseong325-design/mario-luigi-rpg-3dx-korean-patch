"""Scan decompiled C dumps for per-call (per-frame) counters that ignore the task step (MOD2 workstream).

    python scripts/fps60/mod_kjscan.py [game] <Module> [--fn REGEX] [--all] [--ctx N]

Parses work/fps60/decomp/<game>/<Module>.c into functions (`// FUNC <addr> <name> (<module>)` headers) and
reports, per function:
  step  : reads a known step source (KJ step +0x61c58, field step +0x1a4c, isFps30 call, MComSys step)
  INC   : integer field incremented/decremented by a literal 1 (`x = x + 1`, `+ '\\x01'`, `+ -1`, `- 1`)
  FCONST: float field changed by a literal (`x = x + 1.0`, `- 2.0` ...)
  UPD1  : update primitive called with a literal step (Frm::update(1.0), MoveC::update(2.0) ...)
  CMP   : the same field compared with a literal in the function (a frame-count timer)
Default output: functions with INC/FCONST/UPD1 hits whose name matches --fn (default: update-like slots
vfunc_0x8|vfunc_0xc|vfunc_0x10|update|calc|func|exec). --all prints every function with hits.
"""
from __future__ import annotations

import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
HDR = re.compile(r"^// FUNC (0x[0-9a-f]+) (\S+) \(([^)]+)\)")
FIELD = r"(?:\*\((?:[\w ]+?) \*\)\((?:\w+) \+ 0x[0-9a-f]+\)|\w+\[0x[0-9a-f]+\]|\*\([\w ]+ \*\)\(\w+ \+ \w+\))"
INC = re.compile(r"(" + FIELD + r") = (?:\([\w ]+\))?\(?\s*(" + FIELD + r")\s*\)?\s*([+-])\s*(1|'\\x01'|-1|0x1|'\\xff')\s*;")
FCON = re.compile(r"(" + FIELD + r") = (?:\([\w ]+\))?\(?\s*(" + FIELD + r")\s*\)?\s*([+-])\s*(-?\d+\.\d+)\s*;")
UPD1 = re.compile(r"\b(Frm::update|MoveC::update|MoveVBase::update|MoveFBase::update|CellAnime::update|"
                  r"LytAnim::update|ad::lyt::LytAnim::update|MessageSys::func|Message::func|"
                  r"\w+::updateAnimeFrm|SlotDigits::update|ad::ui::SlotDigits::update)\(([^;]*)\);")
STEP = re.compile(r"0x61c58|0x1a4c|isFps30|0xe651c|0x8a44|0x8a40")


def functions(path):
    cur = None
    buf = []
    with open(path, encoding="utf-8", errors="replace") as f:
        for ln in f:
            m = HDR.match(ln)
            if m:
                if cur:
                    yield cur, buf
                cur = (int(m.group(1), 16), m.group(2), m.group(3))
                buf = []
            elif cur:
                buf.append(ln.rstrip("\n"))
    if cur:
        yield cur, buf


def norm(x: str) -> str:
    return re.sub(r"\s+", "", x)


def main(argv):
    game = "3dx_v12"
    if argv and argv[0] in ("3dx_v12", "1dx_kr", "3dx_v10"):
        game, argv = argv[0], argv[1:]
    mod = argv[0]
    rx = re.compile(argv[argv.index("--fn") + 1]) if "--fn" in argv else re.compile(
        r"vfunc_0x(8|c|10|14)$|update|calc|func|exec|Calc|Update", re.I)
    show_all = "--all" in argv
    path = os.path.join(ROOT, "work", "fps60", "decomp", game, f"{mod}.c")
    tot = 0
    for (addr, name, m), body in functions(path):
        if not show_all and not rx.search(name):
            continue
        text = "\n".join(body)
        hits = []
        for i, ln in enumerate(body):
            for mm in INC.finditer(ln):
                if norm(mm.group(1)) == norm(mm.group(2)):
                    fld = norm(mm.group(1))
                    cmp_ = [b.strip() for b in body if fld in norm(b) and re.search(r"[<>=!]=?\s*(0x[0-9a-f]+|\d+|'\\x[0-9a-f]+')", b)
                            and " = " not in b.replace("==", "")][:2]
                    hits.append(("INC", ln.strip(), cmp_))
            for mm in FCON.finditer(ln):
                if norm(mm.group(1)) == norm(mm.group(2)):
                    hits.append(("FCONST", ln.strip(), []))
            for mm in UPD1.finditer(ln):
                args = mm.group(2)
                lastarg = args.split(",")[-1].strip()
                if re.fullmatch(r"-?\d+\.\d+", lastarg):
                    hits.append(("UPD1", ln.strip(), []))
        if not hits:
            continue
        tot += 1
        step = "step" if STEP.search(text) else "nostep"
        print(f"== {addr:#010x} {name} ({m}) [{step}] {len(body)} lines")
        for kind, ln, cmp_ in hits[:12]:
            print(f"   {kind:6s} {ln}")
            for c in cmp_:
                print(f"          cmp: {c}")
    print(f"; {tot} functions with hits")


if __name__ == "__main__":
    main(sys.argv[1:])
