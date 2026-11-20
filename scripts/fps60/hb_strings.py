"""HB helper: strings, RTTI type names and vtables inside the linked HugeBattle.cro image.

    python scripts/fps60/hb_strings.py strings [substr]        # printable strings (ASCII/SJIS-ish) with analysis address
    python scripts/fps60/hb_strings.py rtti [substr]           # RTTI typeinfo objects -> name, vtable(s) that use them
    python scripts/fps60/hb_strings.py refs <addr>             # 32-bit words equal to addr (or addr|1) anywhere in the image
    python scripts/fps60/hb_strings.py vtable <addr> [n]       # dump n vtable slots with nearest symbol / module

Works on work/fps60/link/3dx_v12/HugeBattle.bin (relocated at analysis base 0x12800000).
Read-only; owned by worker HB.
"""
from __future__ import annotations

import json
import os
import re
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(os.path.dirname(HERE))
LINK = os.path.join(ROOT, "work", "fps60", "link", "3dx_v12")
INFO = json.load(open(os.path.join(LINK, "link.json"), encoding="utf-8"))
MOD = INFO["modules"]["HugeBattle"]
BASE = MOD["base"]
DATA = open(os.path.join(LINK, "HugeBattle.bin"), "rb").read()
SEGS = {s["type"] + str(s["index"]): (s["addr"], s["size"]) for s in MOD["segments"] if s["size"]}


def u32(a: int) -> int | None:
    o = a - BASE
    if 0 <= o <= len(DATA) - 4:
        return struct.unpack_from("<I", DATA, o)[0]
    return None


def cstr(a: int, maxlen: int = 200) -> str:
    o = a - BASE
    if not 0 <= o < len(DATA):
        return ""
    e = DATA.find(b"\0", o, o + maxlen)
    raw = DATA[o:e if e >= 0 else o + maxlen]
    try:
        return raw.decode("shift_jis")
    except UnicodeDecodeError:
        return raw.decode("latin-1")


def seg_of(a: int) -> str:
    for n, (s, z) in SEGS.items():
        if s <= a < s + z:
            return n
    return "?"


def strings(sub: str | None) -> None:
    # ASCII C strings (>=5 chars, mostly identifier-like) and UTF-16LE ASCII strings (>=4 chars).
    for m in re.finditer(rb"(?<![\x20-\x7e])[\x20-\x7e]{5,}\0", DATA):
        a = BASE + m.start()
        s = m.group(0)[:-1].decode("ascii")
        if sum(c.isalnum() or c in "_/.%-: " for c in s) < 0.8 * len(s):
            continue
        if sub and sub.lower() not in s.lower():
            continue
        print(f"{a:#010x} [{seg_of(a)}] {s}")
    for m in re.finditer(rb"(?:[\x20-\x7e]\x00){4,}\x00\x00", DATA):
        if m.start() % 2:
            continue
        a = BASE + m.start()
        s = m.group(0)[:-2].decode("utf-16le")
        if sub and sub.lower() not in s.lower():
            continue
        print(f"{a:#010x} [{seg_of(a)}] u16:{s}")


def rtti(sub: str | None) -> None:
    # Itanium ABI typeinfo: {vptr(type_info vtable+8), name_ptr[, base...]}; names look like "N2hb3sys10CGameSpeedE".
    names = {}
    for m in re.finditer(rb"(?:N|[0-9])[0-9A-Za-z_]{3,}E?\0", DATA):
        a = BASE + m.start()
        s = cstr(a)
        if re.fullmatch(r"(N(\d+[A-Za-z_]\w*?)+E|\d+[A-Za-z_]\w*)", s) and (not sub or sub.lower() in s.lower()):
            names[a] = s
    for na, s in sorted(names.items()):
        # typeinfo objects pointing at the name
        pat = struct.pack("<I", na)
        i = DATA.find(pat)
        tis = []
        while i >= 0:
            if i % 4 == 0 and i >= 4:
                tis.append(BASE + i - 4)
            i = DATA.find(pat, i + 1)
        for ti in tis:
            pat2 = struct.pack("<I", ti)
            vts = []
            j = DATA.find(pat2)
            while j >= 0:
                if j % 4 == 0 and BASE + j != ti:
                    vts.append(BASE + j + 4)  # vtable address point = after typeinfo slot
                j = DATA.find(pat2, j + 1)
            print(f"name {na:#010x} {s:50s} typeinfo {ti:#010x} vtables {[hex(v) for v in vts]}")


def refs(a: int) -> None:
    for v in (a, a | 1):
        pat = struct.pack("<I", v)
        i = DATA.find(pat)
        while i >= 0:
            if i % 4 == 0:
                print(f"{BASE + i:#010x} [{seg_of(BASE + i)}] = {v:#x}")
            i = DATA.find(pat, i + 1)


def vtable(a: int, n: int) -> None:
    sys.path.insert(0, HERE)
    import armdis  # lead-owned, imported read-only

    g = armdis.game("3dx_v12")
    for k in range(n):
        v = g.u32(a + 4 * k)
        if v is None:
            break
        near = armdis.where("3dx_v12", v & ~1) if v else ""
        print(f"[{k:3d}] +{4 * k:#05x} {a + 4 * k:#010x}: {v:#010x}  {near}")


def main(argv: list[str]) -> None:
    if not argv:
        print(__doc__)
        return
    cmd = argv[0]
    if cmd == "strings":
        strings(argv[1] if len(argv) > 1 else None)
    elif cmd == "rtti":
        rtti(argv[1] if len(argv) > 1 else None)
    elif cmd == "refs":
        refs(int(argv[1], 0))
    elif cmd == "vtable":
        vtable(int(argv[1], 0), int(argv[2]) if len(argv) > 2 else 40)
    else:
        print(__doc__)


if __name__ == "__main__":
    main(sys.argv[1:])
