"""ARM11 disassembly helper for the 60fps investigation (static code.bin + linked CROs).

    python scripts/fps60/armdis.py [game] <addr|symbol> [count] [--thumb]
    python scripts/fps60/armdis.py 3dx_v12 _ZNK2ad2fw8TaskBase7isFps30Ev 12
    python scripts/fps60/armdis.py 3dx_v12 --sym isFps30            # symbol search (static + CRO exports + imports)
    python scripts/fps60/armdis.py 3dx_v12 --callers 0x25edd0       # direct BL/B sites + literal (pointer) refs
    python scripts/fps60/armdis.py 3dx_v12 --lit 0x3f35f8           # 32-bit literal occurrences
    python scripts/fps60/armdis.py 3dx_v12 --listing                # write work/fps60/dis/<game>/<module>.s

games: 3dx_v12 (analysis target, JP v1.2), 3dx_v10, 1dx_kr. Static module at 0x100000; CROs at the
fixed analysis bases from scripts/fps60/crolink.py (work/fps60/link/<game>/link.json). CRO addresses
are NOT runtime addresses: runtime base = (analysis addr - module base) + real load address.
"""
from __future__ import annotations

import bisect
import json
import os
import re
import struct
import sys
from functools import lru_cache

import capstone

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(os.path.dirname(HERE))
sys.path.insert(0, HERE)
from cro import static_symbols  # noqa: E402

BASE = 0x100000
GAMES = {
    "3dx_v12": ("work/fps60/bin/3dx_v12.code.bin", "romf2/RO/static.crs", 0x289000),
    "3dx_v10": ("work/fps60/bin/3dx_v10.code.bin", "romfs/RO/static.crs", 0x289000),
    "1dx_kr": ("work/fps60/bin/1dx_kr.code.bin", "ml 1dx/3romfs/RO/static.crs", 0x340000),
}


class Game:
    def __init__(self, name: str):
        self.name = name
        path, crs, text_size = GAMES[name]
        self.static = open(os.path.join(ROOT, path), "rb").read()
        self.text_ranges = [("|static|", BASE, BASE + text_size)]
        self.regions = [(BASE, self.static, "|static|")]
        self.syms: dict[str, int] = dict(static_symbols(os.path.join(ROOT, crs)))
        link = os.path.join(ROOT, "work", "fps60", "link", name, "link.json")
        if os.path.exists(link):
            info = json.load(open(link, encoding="utf-8"))
            for mname, m in info["modules"].items():
                data = open(os.path.join(os.path.dirname(link), f"{mname}.bin"), "rb").read()
                self.regions.append((m["base"], data, mname))
                for s in m["segments"]:
                    if s["type"] == "text" and s["size"]:
                        self.text_ranges.append((mname, s["addr"], s["addr"] + s["size"]))
                for n, a in m["exports"].items():
                    self.syms.setdefault(f"{mname}:{n}", a)
        self.regions.sort()
        self._starts = [r[0] for r in self.regions]
        a2s: dict[int, str] = {}
        for s, a in self.syms.items():
            a2s.setdefault(a & ~1, s)
        # CRO import veneers: "ldr pc, [pc, #-4]" followed by the (relocated) target address.
        self.veneers: dict[int, int] = {}
        for mod, start, end in self.text_ranges:
            if mod == "|static|":
                continue
            data = self.read(start, end - start)
            i = data.find(b"\x04\xf0\x1f\xe5")
            while i >= 0:
                if i % 4 == 0 and i + 8 <= len(data):
                    tgt = struct.unpack_from("<I", data, i + 4)[0]
                    self.veneers[start + i] = tgt
                    if (tgt & ~1) in a2s:
                        a2s.setdefault(start + i, "veneer->" + a2s[tgt & ~1])
                i = data.find(b"\x04\xf0\x1f\xe5", i + 1)
        self.a2s = a2s
        self._sorted_syms = sorted(a for a in a2s if not a2s[a].startswith("veneer->"))

    def read(self, addr: int, n: int) -> bytes:
        i = bisect.bisect_right(self._starts, addr) - 1
        if i < 0:
            return b""
        base, data, _ = self.regions[i]
        o = addr - base
        return data[o:o + n] if 0 <= o < len(data) else b""

    def u32(self, addr: int) -> int | None:
        b = self.read(addr, 4)
        return struct.unpack("<I", b)[0] if len(b) == 4 else None

    def module_of(self, addr: int) -> str:
        i = bisect.bisect_right(self._starts, addr) - 1
        if i >= 0:
            base, data, name = self.regions[i]
            if addr < base + len(data):
                return name
        return "?"

    def nearest(self, addr: int) -> tuple[int, str] | None:
        i = bisect.bisect_right(self._sorted_syms, addr) - 1
        if i < 0:
            return None
        a = self._sorted_syms[i]
        return a, self.a2s[a]


def demangle_hint(s: str) -> str:
    """_ZN2ad2fw8TaskBase7isFps30Ev -> ad::fw::TaskBase::isFps30 (rough, args dropped)."""
    if s.startswith("veneer->"):
        return "->" + demangle_hint(s[8:])
    pre = ""
    if ":" in s and not s.startswith("_Z"):
        pre, s = s.split(":", 1)
        pre += ":"
    m = re.match(r"_Z(?:N|NK)?((?:\d+[A-Za-z_][A-Za-z0-9_]*)+)", s)
    if not m:
        return pre + s
    parts, rest = [], m.group(1)
    while rest:
        n = re.match(r"(\d+)", rest)
        if not n:
            break
        ln = int(n.group(1))
        rest = rest[len(n.group(1)):]
        parts.append(rest[:ln])
        rest = rest[ln:]
    return pre + ("::".join(parts) if parts else s)


@lru_cache(maxsize=None)
def game(name: str) -> Game:
    return Game(name)


def md(thumb: bool):
    return capstone.Cs(capstone.CS_ARCH_ARM, capstone.CS_MODE_THUMB if thumb else capstone.CS_MODE_ARM)


def annotate(g: Game, addr: int, mnem: str, ops: str, thumb: bool) -> str:
    note = ""
    if mnem.split(".")[0] in ("bl", "b", "blx") or re.match(r"^b(l|lx)?(eq|ne|cs|cc|mi|pl|vs|vc|hi|ls|ge|lt|gt|le)?$", mnem):
        if ops.startswith("#"):
            t = int(ops[1:], 16)
            if t in g.a2s:
                note = f"  ; {demangle_hint(g.a2s[t])}"
    m = re.search(r"\[pc, #(-?0x[0-9a-f]+)\]", ops)
    if m and mnem.startswith(("ldr", "vldr")):
        lit = ((addr + 4) & ~3 if thumb else addr + 8) + int(m.group(1), 16)
        v = g.u32(lit)
        if v is not None:
            if mnem.startswith("vldr"):
                f = struct.unpack("<f", struct.pack("<I", v))[0]
                note = f"  ; ={v:#x} ({f:g})"
            else:
                note = f"  ; ={v:#x}" + (f" {demangle_hint(g.a2s[v & ~1])}" if (v & ~1) in g.a2s else "")
    return note


def disasm(name: str, addr: int, count: int = 60, thumb: bool = False) -> list[str]:
    g = game(name)
    out = []
    code = g.read(addr, count * 4)
    for (a, size, mnem, ops) in md(thumb).disasm_lite(code, addr):
        raw = g.read(a, size).hex()
        label = f"<{demangle_hint(g.a2s[a])}>\n" if a in g.a2s and a != addr else ""
        out.append(f"{label}{a:08x}: {raw:8s} {mnem:8s} {ops}{annotate(g, a, mnem, ops, thumb)}")
        if len(out) >= count:
            break
    return out


def branch_target(w: int, pc: int) -> int | None:
    if (w >> 25) & 7 != 0b101:
        return None
    imm = w & 0xFFFFFF
    if imm & 0x800000:
        imm -= 0x1000000
    t = pc + 8 + imm * 4
    if (w >> 28) == 0xF:
        t |= ((w >> 24) & 1) << 1
    return t


def callers(name: str, target: int) -> list[tuple[int, str]]:
    g = game(name)
    hits = []
    targets = {target: "branch"}
    for v, t in g.veneers.items():
        if (t & ~1) == target:
            targets[v] = "via-veneer"
    for mod, start, end in g.text_ranges:
        data = g.read(start, end - start)
        for off in range(0, len(data) - 3, 4):
            w = struct.unpack_from("<I", data, off)[0]
            t = branch_target(w, start + off)
            if t in targets:
                hits.append((start + off, targets[t]))
    pat = struct.pack("<I", target)
    pat_t = struct.pack("<I", target | 1)
    for base, data, mod in g.regions:
        for p in (pat, pat_t):
            i = data.find(p)
            while i >= 0:
                hits.append((base + i, "literal"))
                i = data.find(p, i + 1)
    return sorted(hits)


def where(name: str, addr: int) -> str:
    g = game(name)
    n = g.nearest(addr)
    mod = g.module_of(addr)
    if n:
        return f"{mod} {demangle_hint(n[1])}+{addr - n[0]:#x}"
    return mod


def write_listings(name: str) -> None:
    g = game(name)
    out_dir = os.path.join(ROOT, "work", "fps60", "dis", name)
    os.makedirs(out_dir, exist_ok=True)
    cs = md(False)
    for mod, start, end in g.text_ranges:
        data = g.read(start, end - start)
        fn = os.path.join(out_dir, f"{mod.strip('|')}.s")
        with open(fn, "w", encoding="utf-8") as f:
            pos = 0
            while pos < len(data):
                for (a, size, mnem, ops) in cs.disasm_lite(data[pos:], start + pos):
                    if a in g.a2s:
                        f.write(f"\n<{demangle_hint(g.a2s[a])}>  # {g.a2s[a]}\n")
                    f.write(f"{a:08x}: {mnem:8s} {ops}{annotate(g, a, mnem, ops, False)}\n")
                    pos = a - start + size
                else:
                    pass
                if pos < len(data):  # undecodable word: emit as data and continue
                    w = struct.unpack_from("<I", data, pos)[0] if pos + 4 <= len(data) else 0
                    f.write(f"{start + pos:08x}: .word    {w:#010x}\n")
                    pos += 4
        print("wrote", fn)


def main(argv: list[str]) -> None:
    name = argv[0] if argv and argv[0] in GAMES else "3dx_v12"
    args = argv[1:] if argv and argv[0] in GAMES else argv
    if not args:
        print(__doc__)
        return
    g = game(name)
    if args[0] == "--sym":
        for s, a in sorted(g.syms.items(), key=lambda kv: kv[1]):
            if args[1].lower() in s.lower():
                print(f"{a:#010x} {s}  [{demangle_hint(s)}]")
        return
    if args[0] == "--callers":
        t = resolve(g, args[1])[0]
        for a, kind in callers(name, t):
            print(f"{a:#010x} {kind:7s} in {where(name, a)}")
        return
    if args[0] == "--lit":
        v = int(args[1], 0)
        for base, data, mod in g.regions:
            pat = struct.pack("<I", v)
            i = data.find(pat)
            while i >= 0:
                print(f"{base + i:#010x} in {where(name, base + i)}")
                i = data.find(pat, i + 1)
        return
    if args[0] == "--where":
        print(where(name, int(args[1], 0)))
        return
    if args[0] == "--listing":
        write_listings(name)
        return
    addr, thumb = resolve(g, args[0])
    count = int(args[1]) if len(args) > 1 and args[1].isdigit() else 60
    print(f"; {where(name, addr)}")
    print("\n".join(disasm(name, addr, count, thumb or "--thumb" in args)))


def resolve(g: Game, token: str) -> tuple[int, bool]:
    if re.fullmatch(r"0x[0-9a-fA-F]+|\d+", token):
        a = int(token, 0)
        return a & ~1, bool(a & 1)
    if token not in g.syms:
        cands = [s for s in g.syms if token in s]
        if len(cands) != 1:
            raise SystemExit(f"symbol {token!r}: {len(cands)} candidates: {cands[:10]}")
        token = cands[0]
    a = g.syms[token]
    return a & ~1, bool(a & 1)


if __name__ == "__main__":
    main(sys.argv[1:])
