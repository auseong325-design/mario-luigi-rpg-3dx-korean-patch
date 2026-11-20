"""RTTI -> typeinfo -> vtable mapper (static code.bin + linked CRO images), MOD workstream.

    python scripts/fps60/mod_rtti.py [game] [--out FILE] [--filter SUBSTR] [--slots N]

For every Itanium/ARM-EABI typeinfo name string ("N3fld6SystemE", "9GameMain") it finds the
typeinfo object (vptr, name*, [base*]) that points at the string, the base class (si/vmi
typeinfo), and every vtable whose typeinfo slot points at it ({offset_to_top, typeinfo*, fn...}).
Prints one line per vtable:  class  base  vtable_addr  module  slot0 slot1 ...
Addresses are analysis addresses (static runtime addresses; CRO analysis bases).
"""
from __future__ import annotations

import os
import re
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import armdis  # noqa: E402

NAME_RE = re.compile(rb"(?:N(?:\d+[A-Za-z_][A-Za-z0-9_]*)+E|\d+[A-Za-z_][A-Za-z0-9_]*)\x00")


def demangle_type(s: str) -> str:
    if s.startswith("N") and s.endswith("E"):
        s = s[1:-1]
    parts = []
    while s:
        m = re.match(r"(\d+)", s)
        if not m:
            parts.append(s)
            break
        n = int(m.group(1))
        s = s[len(m.group(1)):]
        parts.append(s[:n])
        s = s[n:]
    return "::".join(parts)


def scan(game_name: str):
    g = armdis.game(game_name)
    # 1) candidate name strings
    names: dict[int, str] = {}
    for base, data, mod in g.regions:
        for m in NAME_RE.finditer(data):
            s = m.group(0)[:-1].decode()
            # require a sane mangled type name: digits must match lengths exactly
            try:
                dm = demangle_type(s)
            except Exception:
                continue
            if not dm or any(not p or not re.fullmatch(r"[A-Za-z_]\w*", p) for p in dm.split("::")):
                continue
            # check exact length parse
            t = s[1:-1] if s.startswith("N") else s
            ok = True
            while t:
                mm = re.match(r"(\d+)", t)
                if not mm:
                    ok = False
                    break
                n = int(mm.group(1))
                t = t[len(mm.group(1)):]
                if len(t) < n:
                    ok = False
                    break
                t = t[n:]
            if ok:
                names[base + m.start()] = dm
    # 2) word index over all regions
    word_at: dict[int, list[int]] = {}
    for base, data, mod in g.regions:
        for off in range(0, len(data) - 3, 4):
            w = struct.unpack_from("<I", data, off)[0]
            if w in names:
                word_at.setdefault(w, []).append(base + off)
    typeinfo: dict[int, str] = {}
    for saddr, dm in names.items():
        for waddr in word_at.get(saddr, []):
            ti = waddr - 4
            typeinfo[ti] = dm
    # base classes (si: ti+8 points at another typeinfo)
    base_of: dict[int, str] = {}
    for ti, dm in typeinfo.items():
        b = g.u32(ti + 8)
        if b in typeinfo:
            base_of[ti] = typeinfo[b]
        else:
            # vmi: flags, count, then (base*, offset_flags) pairs
            cnt = g.u32(ti + 12)
            if cnt and cnt < 8:
                bs = []
                for k in range(cnt):
                    bp = g.u32(ti + 16 + 8 * k)
                    if bp in typeinfo:
                        bs.append(typeinfo[bp])
                if bs:
                    base_of[ti] = "+".join(bs)
    # 3) vtables: word == typeinfo and the word before is offset_to_top (0 or small negative)
    ti_refs: dict[int, list[int]] = {}
    for base, data, mod in g.regions:
        for off in range(4, len(data) - 3, 4):
            w = struct.unpack_from("<I", data, off)[0]
            if w in typeinfo:
                ott = struct.unpack_from("<i", data, off - 4)[0]
                if -0x1000 <= ott <= 0:
                    ti_refs.setdefault(w, []).append(base + off + 4)
    return g, typeinfo, base_of, ti_refs


def is_code(g, a: int) -> bool:
    a &= ~1
    return any(s <= a < e for _, s, e in g.text_ranges)


def main(argv):
    game_name = argv[0] if argv and argv[0] in armdis.GAMES else "3dx_v12"
    args = argv[1:] if argv and argv[0] in armdis.GAMES else argv
    out = None
    filt = None
    slots = 24
    i = 0
    while i < len(args):
        if args[i] == "--out":
            out = args[i + 1]; i += 2
        elif args[i] == "--filter":
            filt = args[i + 1]; i += 2
        elif args[i] == "--slots":
            slots = int(args[i + 1]); i += 2
        else:
            i += 1
    g, typeinfo, base_of, ti_refs = scan(game_name)
    lines = []
    for ti, dm in sorted(typeinfo.items(), key=lambda kv: kv[1]):
        if filt and filt.lower() not in dm.lower():
            continue
        vts = ti_refs.get(ti, [])
        if not vts:
            lines.append(f"{dm}\t{base_of.get(ti, '')}\t-\t{g.module_of(ti)}\tti={ti:#x}")
        for vt in vts:
            fns = []
            for k in range(slots):
                f = g.u32(vt + 4 * k)
                if f is None or not (is_code(g, f) or f == 0):
                    break
                fns.append(f"{f:#x}")
            lines.append(f"{dm}\t{base_of.get(ti, '')}\t{vt:#x}\t{g.module_of(vt)}\tti={ti:#x}\t" + " ".join(fns))
    text = "\n".join(lines) + "\n"
    if out:
        with open(out, "w", encoding="utf-8") as f:
            f.write(text)
        print(f"wrote {out}: {len(lines)} lines")
    else:
        sys.stdout.write(text)


if __name__ == "__main__":
    main(sys.argv[1:])
