"""D1X: match functions between two games of the same engine (default 1dx_kr -> 3dx_v12).

    python scripts/fps60/d1x_match.py match <addr> [<addr> ...] [--src 1dx_kr] [--dst 3dx_v12] [--top 5]
    python scripts/fps60/d1x_match.py fps30 [--src 1dx_kr] [--dst 3dx_v12]     # every isFps30 call site of src
    python scripts/fps60/d1x_match.py calls <addr> [--game g]                    # named callees of one function

Functions = [start, next start) where starts are 'push {..lr}' (cond AL), BL targets and symbol addresses.
Each 32-bit word is normalised: branch targets -> callee name (static symbol, CRO export, CRO veneer) or
LOCAL+offset / EXT; pc-relative literals -> literal value unless it looks like a pointer (then name or PTR);
data words that look like pointers -> PTR; everything else kept verbatim (registers, immediates, struct
offsets). Similarity = Jaccard of 4-gram shingle sets (shingles shared by > 300 functions are ignored).
Read-only; uses armdis.py as a library. Scores > 0.6 are almost always the same source function.
"""
from __future__ import annotations

import bisect
import os
import struct
import sys
from collections import defaultdict
from functools import lru_cache

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import armdis  # noqa: E402

FPS30 = {"1dx_kr": 0x2AE220, "3dx_v12": 0x25EDD0, "3dx_v10": None}
SKIP_MODULES = {"HugeBattle"}  # no 1DX counterpart; saves memory
K = 4
MAX_DF = 300
MAX_LEN = 0x6000


def is_ptr(v: int) -> bool:
    return 0x100000 <= v < 0x700000 or 0x10000000 <= v < 0x18000000


def clean(name: str) -> str:
    if name.startswith("veneer->"):
        name = name[8:]
    if ":" in name and not name.startswith("_Z"):
        name = name.split(":", 1)[1]
    return name


class Funcs:
    def __init__(self, game: str):
        self.game = game
        g = armdis.game(game)
        self.g = g
        starts: set[int] = set()
        ranges = [(m, s, e) for m, s, e in g.text_ranges if m not in SKIP_MODULES]
        self.ranges = ranges
        for mod, s, e in ranges:
            data = g.read(s, e - s)
            n = len(data) // 4
            words = struct.unpack_from(f"<{n}I", data)
            for i, w in enumerate(words):
                if (w & 0xFFFF4000) == 0xE92D4000:  # push {...lr} AL
                    starts.add(s + 4 * i)
                elif (w >> 24) & 0x0F == 0x0B and (w >> 28) != 0xF:
                    t = armdis.branch_target(w, s + 4 * i)
                    if t is not None and any(a <= t < b for _, a, b in ranges):
                        starts.add(t)
        for a, nm in g.a2s.items():
            if not nm.startswith("veneer->") and any(s <= a < e for _, s, e in ranges):
                starts.add(a & ~1)
        self.starts = sorted(starts)
        self.ends = {}
        for mod, s, e in ranges:
            idx = [a for a in self.starts if s <= a < e]
            for i, a in enumerate(idx):
                self.ends[a] = min(idx[i + 1] if i + 1 < len(idx) else e, a + MAX_LEN)

    def fstart(self, addr: int) -> int:
        i = bisect.bisect_right(self.starts, addr) - 1
        return self.starts[i] if i >= 0 else addr

    def name(self, addr: int) -> str:
        nm = self.g.a2s.get(addr)
        return armdis.demangle_hint(nm) if nm else armdis.where(self.game, addr)

    @lru_cache(maxsize=None)
    def tokens(self, fs: int) -> tuple:
        g = self.g
        fe = self.ends.get(fs, fs + 4)
        data = g.read(fs, fe - fs)
        n = len(data) // 4
        out = []
        for i, w in enumerate(struct.unpack_from(f"<{n}I", data)):
            a = fs + 4 * i
            if (w >> 25) & 7 == 0b101:
                t = armdis.branch_target(w, a)
                nm = g.a2s.get(t & ~1) if t is not None else None
                if nm:
                    out.append(("B", w >> 24, clean(nm)))
                elif t is not None and fs <= t < fe:
                    out.append(("B", w >> 24, "L", t - fs))
                else:
                    out.append(("B", w >> 24, "X"))
                continue
            if (w & 0x0F7F0000) == 0x051F0000:  # ldr rt, [pc, #+-imm12]
                imm = w & 0xFFF
                lit = a + 8 + (imm if w & (1 << 23) else -imm)
                v = g.u32(lit)
                if v is not None and is_ptr(v):
                    nm = g.a2s.get(v & ~1)
                    out.append(("LP", w & 0xFFFFF000, clean(nm) if nm else "P"))
                else:
                    out.append(("LP", w & 0xFFFFF000, v))
                continue
            if (w & 0x0F3F0E00) == 0x0D1F0A00:  # vldr sd/dd, [pc, #+-imm8*4]
                imm = (w & 0xFF) * 4
                lit = a + 8 + (imm if w & (1 << 23) else -imm)
                out.append(("VL", w & 0xFFFFFF00, g.u32(lit)))
                continue
            if (w & 0x0FFF0000) == 0x028F0000:  # adr
                out.append(("ADR", (w >> 12) & 0xF))
                continue
            if is_ptr(w):
                out.append(("P",))
                continue
            out.append(w)
        return tuple(out)

    def shingles(self, fs: int) -> set[int]:
        t = self.tokens(fs)
        if len(t) < K:
            return {hash(t)}
        return {hash(t[i:i + K]) for i in range(len(t) - K + 1)}

    def callees(self, fs: int) -> list[str]:
        return [x[2] for x in self.tokens(fs) if isinstance(x, tuple) and x[0] == "B" and len(x) == 3 and x[2] not in ("X",)]


class Index:
    def __init__(self, f: Funcs):
        self.f = f
        inv: dict[int, list[int]] = defaultdict(list)
        self.size: dict[int, int] = {}
        for fs in f.starts:
            sh = f.shingles(fs)
            self.size[fs] = len(sh)
            for h in sh:
                inv[h].append(fs)
        self.inv = {h: v for h, v in inv.items() if len(v) <= MAX_DF}

    def query(self, sh: set[int], top: int = 5) -> list[tuple[float, int]]:
        cnt: dict[int, int] = defaultdict(int)
        for h in sh:
            for fs in self.inv.get(h, ()):
                cnt[fs] += 1
        res = []
        for fs, c in cnt.items():
            j = c / (len(sh) + self.size[fs] - c)
            res.append((j, fs))
        res.sort(reverse=True)
        return res[:top]


def calls_fps30(f: Funcs, fs: int) -> int:
    return sum(1 for x in f.callees(fs) if x == "_ZNK2ad2fw8TaskBase7isFps30Ev")


def main(argv: list[str]) -> None:
    src, dst, top = "1dx_kr", "3dx_v12", 5
    args = []
    it = iter(argv)
    for a in it:
        if a == "--src":
            src = next(it)
        elif a == "--dst":
            dst = next(it)
        elif a == "--top":
            top = int(next(it))
        elif a == "--game":
            src = next(it)
        else:
            args.append(a)
    cmd, rest = args[0], args[1:]
    fsrc = Funcs(src)
    if cmd == "calls":
        for tok in rest:
            fs = fsrc.fstart(int(tok, 0))
            print(f"{fs:#x} {fsrc.name(fs)}: " + ", ".join(armdis.demangle_hint(c) for c in fsrc.callees(fs)))
        return
    fdst = Funcs(dst)
    idx = Index(fdst)
    if cmd == "match":
        for tok in rest:
            a = int(tok, 0)
            fs = fsrc.fstart(a)
            print(f"== {src} {a:#x} func {fs:#x}..{fsrc.ends.get(fs, 0):#x} {fsrc.name(fs)}  fps30-calls={calls_fps30(fsrc, fs)}")
            for j, g in idx.query(fsrc.shingles(fs), top):
                print(f"   {j:.3f} {dst} {g:#x}..{fdst.ends.get(g, 0):#x} {fdst.name(g)}  fps30-calls={calls_fps30(fdst, g)}")
        return
    if cmd == "fps30":
        sites = [a for a, kind in armdis.callers(src, FPS30[src]) if kind != "literal"]
        seen = set()
        for a in sites:
            fs = fsrc.fstart(a)
            if fs in seen:
                continue
            seen.add(fs)
            res = idx.query(fsrc.shingles(fs), top)
            best = res[0] if res else (0.0, 0)
            print(f"{src} {fs:#x} ({fsrc.ends.get(fs, 0) - fs:#x} B, fps30x{calls_fps30(fsrc, fs)}) {fsrc.name(fs)}")
            for j, g in res[:3]:
                print(f"    -> {j:.3f} {g:#x} ({fdst.ends.get(g, 0) - g:#x} B, fps30x{calls_fps30(fdst, g)}) {fdst.name(g)}")
        return
    raise SystemExit(f"unknown command {cmd}")


if __name__ == "__main__":
    main(sys.argv[1:])
