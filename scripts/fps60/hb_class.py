"""HB helper: RTTI-based class/vtable map for HugeBattle.cro and "which function/class owns this address".

    python scripts/fps60/hb_class.py who <addr> [addr ...]     # containing function start + classes whose vtables hold it
    python scripts/fps60/hb_class.py vt <ClassSubstr>           # list vtables (and slots) of matching classes
    python scripts/fps60/hb_class.py callers <func>             # BL/B callers of a function inside HugeBattle (+ vtable refs)

Function starts = BL/B targets inside HugeBattle text + vtable slot targets + exports. Classes come from
Itanium RTTI (typeinfo name strings like N2hb3sys10CGameSpeedE). Read-only; owned by worker HB.
"""
from __future__ import annotations

import bisect
import json
import os
import re
import struct
import sys
from functools import lru_cache

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(os.path.dirname(HERE))
LINK = os.path.join(ROOT, "work", "fps60", "link", "3dx_v12")
INFO = json.load(open(os.path.join(LINK, "link.json"), encoding="utf-8"))
MOD = INFO["modules"]["HugeBattle"]
BASE = MOD["base"]
DATA = open(os.path.join(LINK, "HugeBattle.bin"), "rb").read()
TEXT = [(s["addr"], s["addr"] + s["size"]) for s in MOD["segments"] if s["type"] == "text" and s["size"]][0]


def u32(a: int) -> int | None:
    o = a - BASE
    return struct.unpack_from("<I", DATA, o)[0] if 0 <= o <= len(DATA) - 4 else None


def in_text(a: int) -> bool:
    return TEXT[0] <= a < TEXT[1]


def cstr(a: int) -> str:
    o = a - BASE
    e = DATA.find(b"\0", o, o + 300)
    return DATA[o:e].decode("latin-1") if e > o else ""


def demangle(n: str) -> str:
    if not n.startswith("N"):
        m = re.match(r"(\d+)(.*)", n)
        return m.group(2)[: int(m.group(1))] if m else n
    parts, rest = [], n[1:]
    while rest and rest[0].isdigit():
        m = re.match(r"(\d+)", rest)
        ln = int(m.group(1))
        rest = rest[len(m.group(1)):]
        parts.append(rest[:ln])
        rest = rest[ln:]
        if rest.startswith("I"):  # template args: keep raw tail
            parts[-1] += "<" + rest[1:rest.rfind("E")] + ">"
            break
    return "::".join(parts)


@lru_cache(maxsize=None)
def typeinfos() -> dict[int, str]:
    """typeinfo object address -> demangled class name."""
    out = {}
    for m in re.finditer(rb"N[0-9][0-9A-Za-z_]{3,}E\0|[1-9][0-9]?[A-Za-z_][0-9A-Za-z_]{2,}\0", DATA):
        na = BASE + m.start()
        s = cstr(na)
        pat = struct.pack("<I", na)
        i = DATA.find(pat)
        while i >= 0:
            if i % 4 == 0 and i >= 4:
                ti = BASE + i - 4
                vp = u32(ti)
                # typeinfo vptr points into a __cxxabiv1 vtable in static (address < 0x400000)
                if vp is not None and 0x100000 <= vp < 0x400000:
                    out[ti] = demangle(s)
            i = DATA.find(pat, i + 1)
    return out


@lru_cache(maxsize=None)
def vtables() -> list[tuple[int, str, list[int]]]:
    """(address point, class, slot targets) for every primary/secondary vtable found via typeinfo refs."""
    tis = typeinfos()
    res = []
    for o in range(0, len(DATA) - 8, 4):
        v = struct.unpack_from("<I", DATA, o)[0]
        if v in tis:
            a = BASE + o
            top = u32(a - 4)
            if top is None or not (top == 0 or top >= 0xFFFFF000):
                continue
            # skip typeinfo objects that reference a base typeinfo (si/vmi base pointers)
            if a - 4 in tis or a - 8 in tis:
                continue
            slots = []
            k = a + 4
            while True:
                t = u32(k)
                if t is None or not (in_text(t & ~1) or 0x100000 <= t < 0x389000):
                    break
                slots.append(t)
                k += 4
            if slots:
                res.append((a + 4, tis[v], slots))
    return res


@lru_cache(maxsize=None)
def func_starts() -> list[int]:
    starts = set()
    lo, hi = TEXT
    for a in range(lo, hi, 4):
        w = u32(a)
        if (w >> 25) & 7 == 0b101 and (w >> 28) != 0xF:
            imm = w & 0xFFFFFF
            if imm & 0x800000:
                imm -= 0x1000000
            t = a + 8 + imm * 4
            if lo <= t < hi and (w >> 24) & 1:  # BL only (B targets are often in-function labels)
                starts.add(t)
    for _, _, slots in vtables():
        for t in slots:
            if in_text(t & ~1):
                starts.add(t & ~1)
    for a in MOD["exports"].values():
        starts.add(a & ~1)
    return sorted(starts)


@lru_cache(maxsize=None)
def slot_owners() -> dict[int, list[str]]:
    own: dict[int, list[str]] = {}
    for ap, cls, slots in vtables():
        for i, t in enumerate(slots):
            own.setdefault(t & ~1, []).append(f"{cls}[{i}]@{ap:#x}")
    return own


def who(a: int) -> str:
    fs = func_starts()
    i = bisect.bisect_right(fs, a) - 1
    f = fs[i] if i >= 0 else None
    owners = slot_owners().get(f, []) if f is not None else []
    return f"{a:#010x}: func {f:#010x}+{a - f:#x} " + (" ".join(owners) if owners else "(no vtable slot)")


def callers(f: int) -> None:
    lo, hi = TEXT
    for a in range(lo, hi, 4):
        w = u32(a)
        if (w >> 25) & 7 == 0b101 and (w >> 28) != 0xF:
            imm = w & 0xFFFFFF
            if imm & 0x800000:
                imm -= 0x1000000
            if a + 8 + imm * 4 == f:
                print(f"{a:#010x} {'bl' if (w >> 24) & 1 else 'b '} in {who(a)}")
    for t, own in slot_owners().items():
        if t == f:
            print("vtable:", " ".join(own))


def main(argv: list[str]) -> None:
    if not argv:
        print(__doc__)
        return
    if argv[0] == "who":
        for t in argv[1:]:
            print(who(int(t, 0)))
    elif argv[0] == "vt":
        sub = argv[1].lower() if len(argv) > 1 else ""
        for ap, cls, slots in vtables():
            if sub in cls.lower():
                print(f"{cls}  vtable {ap:#010x}  ({len(slots)} slots)")
                for i, t in enumerate(slots):
                    print(f"   [{i:2d}] +{4 * i:#05x} {t:#010x}")
    elif argv[0] == "callers":
        callers(int(argv[1], 0))
    else:
        print(__doc__)


if __name__ == "__main__":
    main(sys.argv[1:])
