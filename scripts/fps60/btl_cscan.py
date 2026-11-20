"""BTL2: find per-call integer counters in battle C++ code (Ghidra dump text), i.e. candidates for
timers that count frames instead of using the battle step.

    python scripts/fps60/btl_cscan.py [--out file.tsv] [--module Battle|static|KJRPG|AttackMiniGame]

A hit is a statement `F = F + c;` / `F = F - c;` / `F = F + -c;` where F is a memory field
(`*(T *)(base + 0xNN)` or `base[0xNN]`) and c an integer literal, inside a function of the battle code
(static functions named btl::* or lying in the static btl ranges, every Battle/AttackMiniGame function).
Per hit: function, field, constant, whether the same field is compared with a literal in the function,
and whether the function also reads a step (battle step 0xba15c, isFps30, calcUpdateSpd, ObjMove anim speed).
Output is a candidate list for manual review; it proves nothing by itself. Read-only.
"""
from __future__ import annotations

import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(os.path.dirname(HERE))
DUMP = os.path.join(ROOT, "work", "fps60", "decomp", "3dx_v12")

# static address ranges holding btl:: code (from functions.tsv: btl:: names cluster here)
STATIC_BTL = [(0x1C8000, 0x23F000), (0x285000, 0x2A0000), (0x34F000, 0x356000)]
FIELD = r"(\*\((?:u?int|short|ushort|char|byte|undefined[124]?|uint)\s*\*\)\s*\([A-Za-z_0-9]+ \+ 0x[0-9a-f]+\)|[A-Za-z_0-9]+\[0x[0-9a-f]+\])"
INC = re.compile(rf"^\s*{FIELD} = (?:\([a-z0-9 ]+\))?\(?{FIELD} ?([+-]) ?(-?(?:0x[0-9a-f]+|\d+)|'\\x0?1')\)?;")
STEP = re.compile(r"0xba15c|isFps30|calcUpdateSpd|getUpdateSpd|0x8a44|MoveFBase::update|MoveVBase::update|"
                  r"MoveC::update|Frm::update|CellAnime::update|LytAnim::update|setAnmSpd")


def norm(f: str) -> str:
    m = re.search(r"([A-Za-z_0-9]+) \+ (0x[0-9a-f]+)", f) or re.search(r"([A-Za-z_0-9]+)\[(0x[0-9a-f]+)\]", f)
    return f"{m.group(1)}+{m.group(2)}" if m else f


def functions(path):
    name, addr, body = None, None, []
    with open(path, encoding="utf-8", errors="replace") as fh:
        for line in fh:
            if line.startswith("// FUNC "):
                if name is not None:
                    yield addr, name, body
                parts = line.split()
                addr, name, body = int(parts[2], 16), " ".join(parts[3:-1]), []
            elif name is not None:
                body.append(line.rstrip("\n"))
    if name is not None:
        yield addr, name, body


def wanted(module, addr, name):
    if module != "static":
        return True
    if name.startswith("btl::"):
        return True
    return name.startswith("FUN_") and any(a <= addr < b for a, b in STATIC_BTL)


def main(argv):
    out = None
    if "--out" in argv:
        out = argv[argv.index("--out") + 1]
    mods = ["static", "Battle", "AttackMiniGame"]
    if "--module" in argv:
        mods = [argv[argv.index("--module") + 1]]
    rows = ["module\tfunc\tname\tfield\top\tconst\tcompared_with\tstep_in_func\tline"]
    for mod in mods:
        for addr, name, body in functions(os.path.join(DUMP, f"{mod}.c")):
            if name.startswith("->") or not wanted(mod, addr, name):
                continue
            text = "\n".join(body)
            step = bool(STEP.search(text))
            for ln in body:
                m = INC.match(ln)
                if not m:
                    continue
                lhs, rhs, sign, c = m.group(1), m.group(2), m.group(3), m.group(4)
                if norm(lhs) != norm(rhs):
                    continue
                key = norm(lhs)
                base, off = key.split("+")
                cmp_re = re.compile(rf"{re.escape(base)} \+ {off}\)\s*(?:<|>|<=|>=|==|!=)\s*(-?(?:0x[0-9a-f]+|\d+))|"
                                    rf"{re.escape(base)}\[{off}\]\s*(?:<|>|<=|>=|==|!=)\s*(-?(?:0x[0-9a-f]+|\d+))")
                cmps = sorted({x for t in cmp_re.findall(text) for x in t if x})
                rows.append(f"{mod}\t{addr:#x}\t{name}\t{key}\t{sign}\t{c}\t{','.join(cmps)}\t"
                            f"{'yes' if step else ''}\t{ln.strip()}")
    text = "\n".join(rows) + "\n"
    if out:
        with open(out, "w", encoding="utf-8", newline="\n") as fh:
            fh.write(text)
        print(f"wrote {out}: {len(rows) - 1} hits")
    else:
        sys.stdout.write(text)


if __name__ == "__main__":
    main(sys.argv[1:])
