"""Function-level helper for the MOD workstream (static + linked CROs).

    python scripts/fps60/mod_fn.py [game] fn <addr> [maxinsn]     # whole function containing addr
    python scripts/fps60/mod_fn.py [game] start <addr>             # function start + label
    python scripts/fps60/mod_fn.py [game] xref <addr>              # callers, each with its function + label
    python scripts/fps60/mod_fn.py [game] vt <class-substr>        # vtables with labelled slots
    python scripts/fps60/mod_fn.py [game] calls <addr>             # direct calls made by the function
    python scripts/fps60/mod_fn.py [game] grep <regex> <lo> <hi>   # disasm lines matching regex in range

Function starts = every direct BL/BLX/B-to-symbol target + every vtable slot + every exported symbol.
Labels: exported symbol, else "Class::vN" (vtable slot N, from mod_rtti), else "fn_<addr>".
The RTTI scan is cached in $KIROCREW_SCRATCH (or %TEMP%) as mod_rtti_<game>.json.
"""
from __future__ import annotations

import bisect
import json
import os
import re
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import armdis  # noqa: E402
import mod_rtti  # noqa: E402

SCR = os.environ.get("KIROCREW_SCRATCH") or os.environ.get("TEMP") or "."


class Ctx:
    def __init__(self, name: str):
        self.name = name
        self.g = armdis.game(name)
        cache = os.path.join(SCR, f"mod_rtti_{name}.json")
        if os.path.exists(cache):
            d = json.load(open(cache, encoding="utf-8"))
        else:
            g, typeinfo, base_of, ti_refs = mod_rtti.scan(name)
            d = {"vt": []}
            for ti, cls in typeinfo.items():
                for vt in ti_refs.get(ti, []):
                    slots = []
                    for k in range(160):
                        f = g.u32(vt + 4 * k)
                        if f is None or not (self.is_code(f) or f == 0):
                            break
                        if f == 0 and k > 0:
                            break
                        slots.append(f)
                    d["vt"].append([cls, base_of.get(ti, ""), vt, slots])
            json.dump(d, open(cache, "w", encoding="utf-8"))
        self.vtables = d["vt"]
        self.labels: dict[int, str] = {}
        for cls, base, vt, slots in self.vtables:
            for k, f in enumerate(slots):
                if f:
                    self.labels.setdefault(f & ~1, f"{cls}::v{k}")
        starts = set()
        for a, s in self.g.a2s.items():
            if not s.startswith("veneer->"):
                starts.add(a)
        starts.update(self.labels)
        for mod, lo, hi in self.g.text_ranges:
            data = self.g.read(lo, hi - lo)
            for off in range(0, len(data) - 3, 4):
                w = struct.unpack_from("<I", data, off)[0]
                if (w >> 24) & 0xF == 0xB or (w >> 25) == 0x7D:  # BL (any cond) or BLX imm
                    t = armdis.branch_target(w, lo + off)
                    if t is not None and self.is_code(t):
                        starts.add(t & ~1)
        self.starts = sorted(starts)

    def is_code(self, a: int) -> bool:
        a &= ~1
        return any(s <= a < e for _, s, e in self.g.text_ranges)

    def label(self, a: int) -> str:
        a &= ~1
        if a in self.g.a2s and not self.g.a2s[a].startswith("veneer->"):
            s = armdis.demangle_hint(self.g.a2s[a])
            if a in self.labels:
                s += f" [{self.labels[a]}]"
            return s
        if a in self.g.a2s:
            return armdis.demangle_hint(self.g.a2s[a])
        if a in self.labels:
            return self.labels[a]
        return f"fn_{a:x}"

    def fn_start(self, a: int) -> int:
        i = bisect.bisect_right(self.starts, a) - 1
        return self.starts[i] if i >= 0 else a

    def fn_end(self, start: int) -> int:
        i = bisect.bisect_right(self.starts, start)
        nxt = self.starts[i] if i < len(self.starts) else start + 0x4000
        for _, lo, hi in self.g.text_ranges:
            if lo <= start < hi:
                nxt = min(nxt, hi)
        return nxt

    def disasm_range(self, lo: int, hi: int) -> list[str]:
        out = []
        cs = armdis.md(False)
        code = self.g.read(lo, hi - lo)
        pos = 0
        while pos < len(code):
            got = False
            for (a, size, mnem, ops) in cs.disasm_lite(code[pos:], lo + pos):
                got = True
                note = armdis.annotate(self.g, a, mnem, ops, False)
                if re.match(r"^b(l|lx)?(eq|ne|cs|cc|hs|lo|mi|pl|vs|vc|hi|ls|ge|lt|gt|le)?$", mnem) and ops.startswith("#"):
                    t = int(ops[1:], 16)
                    if mnem.startswith("bl") or t in self.labels or (t in self.g.a2s):
                        if not note:
                            note = f"  ; {self.label(t)}"
                        elif t in self.labels and self.labels[t] not in note:
                            note += f" [{self.labels[t]}]"
                m = re.search(r"\[pc, #(-?0x[0-9a-f]+)\]", ops)
                if m and mnem.startswith("ldr") and "  ; =" in note:
                    v = self.g.u32(a + 8 + int(m.group(1), 16))
                    if v is not None and (v & ~1) in self.labels and self.labels[v & ~1] not in note:
                        note += f" [{self.labels[v & ~1]}]"
                lab = f"<{self.label(a)}>\n" if (a in self.labels or a in self.g.a2s) and a != lo else ""
                out.append(f"{lab}{a:08x}: {mnem:8s} {ops}{note}")
                pos = a - lo + size
            if pos < len(code):
                w = struct.unpack_from("<I", code, pos)[0] if pos + 4 <= len(code) else 0
                out.append(f"{lo + pos:08x}: .word    {w:#010x}")
                pos += 4
            if not got and pos >= len(code):
                break
        return out


def main(argv):
    name = argv[0] if argv and argv[0] in armdis.GAMES else "3dx_v12"
    args = argv[1:] if argv and argv[0] in armdis.GAMES else argv
    c = Ctx(name)
    cmd = args[0]
    if cmd in ("fn", "start", "calls"):
        a = int(args[1], 0)
        s = c.fn_start(a)
        e = c.fn_end(s)
        if cmd == "start":
            print(f"{s:#x} {c.label(s)} (ends {e:#x}, {c.g.module_of(s)})")
            return
        mx = int(args[2], 0) if len(args) > 2 else 2000
        e = min(e, s + 4 * mx)
        lines = c.disasm_range(s, e)
        if cmd == "fn":
            print(f"; {c.label(s)} {s:#x}..{e:#x} ({c.g.module_of(s)})")
            print("\n".join(lines))
        else:
            for ln in lines:
                if re.search(r": (bl|blx|b)\s", ln) and "; " in ln:
                    print(ln)
        return
    if cmd == "xref":
        t = int(args[1], 0)
        for a, kind in armdis.callers(name, t):
            s = c.fn_start(a)
            print(f"{a:#010x} {kind:10s} in {c.label(s)} ({s:#x}+{a - s:#x}) [{c.g.module_of(a)}]")
        return
    if cmd == "vt":
        for cls, base, vt, slots in c.vtables:
            if args[1].lower() in cls.lower():
                print(f"{cls} <{base}> vt={vt:#x} [{c.g.module_of(vt)}]")
                for k, f in enumerate(slots):
                    print(f"   v{k:<3d} +{4 * k:#05x} {f:#010x} {c.label(f)}")
        return
    if cmd == "grep":
        rx = re.compile(args[1])
        lo, hi = int(args[2], 0), int(args[3], 0)
        for ln in c.disasm_range(lo, hi):
            if rx.search(ln):
                print(ln)
        return
    print(__doc__)


if __name__ == "__main__":
    main(sys.argv[1:])
