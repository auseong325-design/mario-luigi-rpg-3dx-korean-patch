"""AUD: enumerate and pre-classify every reader of the fps mode in 3DX v1.2 (static + all CROs). Read-only.

    python scripts/fps60/aud_sites.py sites  [--out FILE] [--tsv FILE] [--module M] [--before N] [--after N]
    python scripts/fps60/aud_sites.py inline [--out FILE] [--off 0x45,0x3d] [--module M]
    python scripts/fps60/aud_sites.py fn <addr> [<addr> ...]          # decompiled text of the containing function(s)
    python scripts/fps60/aud_sites.py dis <addr> [count]              # listing lines starting at addr

sites : every call of ad::fw::TaskBase::isFps30 (0x25EDD0): direct BL/B/BLX in static, calls through each CRO's
        import veneer, and literal (pointer) references. Per site: module, Module+offset, return address,
        containing function (Ghidra index), its callers, the listing before/after the call, a guess of what the
        result selects, and the decompiled lines that mention isFps30.
inline: every byte load `ldrb/ldrsb rX,[rY,#OFF]` with OFF in {0x45, 0x3d} (all modules) with the containing
        function, so readers of TaskBase+0x45/+0x3D that do not go through isFps30 can be audited.
Inputs: work/fps60/dis/3dx_v12/*.s (armdis listings), work/fps60/decomp/3dx_v12/{functions.tsv,*.c} (Ghidra dump).
"""
from __future__ import annotations

import bisect
import os
import re
import sys
from functools import lru_cache

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(os.path.dirname(HERE))
sys.path.insert(0, HERE)
import armdis  # noqa: E402

GAME = "3dx_v12"
ISFPS30 = 0x25EDD0
DIS = os.path.join(ROOT, "work", "fps60", "dis", GAME)
DEC = os.path.join(ROOT, "work", "fps60", "decomp", GAME)
LINE_RE = re.compile(r"^([0-9a-f]{8}): (.*)$")


@lru_cache(maxsize=None)
def listing(module: str) -> tuple[list[int], list[str]]:
    addrs, lines = [], []
    with open(os.path.join(DIS, f"{module}.s"), encoding="utf-8") as f:
        for ln in f:
            m = LINE_RE.match(ln.rstrip("\n"))
            if m:
                addrs.append(int(m.group(1), 16))
                lines.append(m.group(2))
    return addrs, lines


def dis_window(module: str, addr: int, before: int, after: int) -> list[str]:
    addrs, lines = listing(module)
    i = bisect.bisect_left(addrs, addr)
    out = []
    for k in range(max(0, i - before), min(len(addrs), i + after + 1)):
        out.append(f"{addrs[k]:08x}: {lines[k]}")
    return out


class Fn:
    __slots__ = ("addr", "end", "size", "module", "name", "symbol", "file", "line", "status", "callers")


@lru_cache(maxsize=None)
def fn_index() -> tuple[list[int], list[Fn]]:
    rows = []
    with open(os.path.join(DEC, "functions.tsv"), encoding="utf-8") as f:
        f.readline()
        for ln in f:
            p = ln.rstrip("\n").split("\t")
            if len(p) < 10:
                continue
            r = Fn()
            r.addr, r.end, r.size = int(p[0], 16), int(p[1], 16), int(p[2], 16)
            r.module, r.name, r.symbol, r.file = p[3], p[4], p[5], p[6]
            r.line, r.status, r.callers = int(p[7]), p[8], p[9]
            rows.append(r)
    rows.sort(key=lambda r: r.addr)
    return [r.addr for r in rows], rows


def fn_of(addr: int) -> Fn | None:
    starts, rows = fn_index()
    i = bisect.bisect_right(starts, addr) - 1
    while i >= 0 and rows[i].addr > addr - 0x20000:
        r = rows[i]
        if r.addr <= addr < r.addr + max(r.size, 4):
            return r
        i -= 1
    return None


def fn_at(addr: int) -> Fn | None:
    starts, rows = fn_index()
    i = bisect.bisect_left(starts, addr)
    return rows[i] if i < len(rows) and starts[i] == addr else None


@lru_cache(maxsize=None)
def c_lines(file: str) -> list[str]:
    with open(os.path.join(DEC, file), encoding="utf-8", errors="replace") as f:
        return f.read().split("\n")


def fn_text(r: Fn) -> list[str]:
    lines = c_lines(r.file)
    i = r.line - 1
    out = [lines[i]] if 0 <= i < len(lines) else []
    j = i + 1
    while j < len(lines) and not lines[j].startswith("// FUNC "):
        out.append(lines[j])
        j += 1
    return out


def fn_label(r: Fn | None) -> str:
    if r is None:
        return "?"
    return f"{r.name} @{r.addr:#x}"


def caller_addrs(r: Fn) -> list[int]:
    body = fn_text(r)
    info = body[1] if len(body) > 1 else ""
    m = re.search(r"callers\((\d+)\):([^|]*)", info)
    if not m:
        return []
    return [int(t, 16) for t in m.group(2).split() if re.fullmatch(r"0x[0-9a-fA-F]+", t)]


def callers_desc(r: Fn, limit: int = 4) -> str:
    addrs = caller_addrs(r)
    cs = []
    for a in addrs[:limit]:
        c = fn_of(a)
        cs.append(f"{a:#x}({c.name if c else '?'})")
    n = len(addrs)
    return (", ".join(cs) + (f" …(+{n - limit})" if n > limit else "")) if cs else f"- (index count {r.callers})"


FLOAT_RE = re.compile(r"=0x[0-9a-f]+ \(([-0-9.e+inf]+)\)")


def guess(after: list[str]) -> str:
    txt = "\n".join(after)
    fl = FLOAT_RE.findall(txt)
    tags = []
    if fl:
        tags.append("F{" + ",".join(dict.fromkeys(fl)) + "}")
    ints = re.findall(r"\bmov(?:ne|eq)\s+\w+, #(0x[0-9a-f]+|\d+)", txt)
    if ints:
        tags.append("I{" + ",".join(dict.fromkeys(ints)) + "}")
    if re.search(r"\b(lsl|lsr|asr)(ne|eq)\b", txt):
        tags.append("shift")
    if re.search(r"\b(b|bl)(eq|ne)\s", txt):
        tags.append("branch")
    if re.search(r"\b(add|sub)(eq|ne)\s", txt):
        tags.append("addsub")
    return " ".join(tags) or "?"


def module_of(addr: int) -> str:
    g = armdis.game(GAME)
    m = g.module_of(addr)
    return "static" if m == "|static|" else m


def module_base(module: str) -> int:
    if module == "static":
        return 0x100000
    g = armdis.game(GAME)
    for base, _data, name in g.regions:
        if name == module:
            return base
    return 0


def loc(addr: int) -> str:
    m = module_of(addr)
    if m == "static":
        return f"{addr:#x} (file {addr - 0x100000:#x})"
    return f"{m}+{addr - module_base(m):#x} [{addr:#x}]"


def cmd_sites(args) -> None:
    out = open(args.out, "w", encoding="utf-8") if args.out else sys.stdout
    tsv = open(args.tsv, "w", encoding="utf-8") if args.tsv else None
    if tsv:
        tsv.write("n\tsite\tret\tmodule\tloc\tkind\tfunc_addr\tfunc\tguess\tcallers\n")
    n = 0
    from collections import Counter
    stats = Counter()
    for a, kind in armdis.callers(GAME, ISFPS30):
        m = module_of(a)
        if args.module and m != args.module:
            continue
        r = fn_of(a)
        if kind == "literal":
            # the veneer's own .word is expected; anything else is a pointer use
            prev = dis_window(m, a - 4, 0, 0)
            if prev and "ldr      pc, [pc, #-4]" in prev[0]:
                continue
        n += 1
        before = dis_window(m, a, args.before, 0)[:-1]
        after = dis_window(m, a + 4, 0, args.after - 1)
        g = guess(after) if kind != "literal" else "pointer"
        stats[(m, g.split(" ")[0])] += 1
        print(f"== #{n} {loc(a)} ret {a + 4:#x} [{kind}] in {fn_label(r)}  => {g}", file=out)
        if r:
            print(f"   fn size {r.size:#x} callers({len(caller_addrs(r))}): {callers_desc(r)}", file=out)
        for ln in before:
            print("     " + ln, file=out)
        print("  >> " + dis_window(m, a, 0, 0)[0], file=out)
        for ln in after:
            print("     " + ln, file=out)
        if r:
            body = fn_text(r)
            hits = [i for i, t in enumerate(body) if "isFps30" in t]
            shown = set()
            for i in hits:
                for k in range(max(1, i - args.cbefore), min(len(body), i + args.cafter + 1)):
                    if k not in shown:
                        shown.add(k)
                        print("   c| " + body[k].rstrip()[:220], file=out)
                print("   c| ...", file=out)
        if tsv:
            tsv.write(f"{n}\t{a:#x}\t{a + 4:#x}\t{m}\t{loc(a)}\t{kind}\t{(r.addr if r else 0):#x}\t"
                      f"{r.name if r else '?'}\t{g}\t{len(caller_addrs(r)) if r else 0}\n")
    print("; summary (module, first guess tag): count", file=out)
    for (m, g), k in sorted(stats.items()):
        print(f";   {m:16s} {g:14s} {k}", file=out)
    print(f"; total {n}", file=out)


def cmd_inline(args) -> None:
    out = open(args.out, "w", encoding="utf-8") if args.out else sys.stdout
    offs = [int(x, 16) for x in args.off.split(",")]
    pat = re.compile(r"^(ldrb|ldrsb)\w*\s+(\w+), \[(\w+), #(0x[0-9a-f]+)\]")
    mods = [f[:-2] for f in sorted(os.listdir(DIS)) if f.endswith(".s")]
    from collections import Counter
    per_fn = Counter()
    total = 0
    for m in mods:
        if args.module and m != args.module:
            continue
        addrs, lines = listing(m)
        for a, t in zip(addrs, lines):
            mm = pat.match(t)
            if not mm or int(mm.group(4), 16) not in offs:
                continue
            r = fn_of(a)
            total += 1
            per_fn[(m, fn_label(r))] += 1
            print(f"{loc(a)}\t{t}\tin {fn_label(r)}", file=out)
    print(f"; total {total} loads in {len(per_fn)} functions", file=out)


def listing_fn_start(module: str, addr: int) -> int:
    """Fallback when Ghidra has no function: nearest preceding `push {...lr}` in the listing."""
    addrs, lines = listing(module)
    i = bisect.bisect_left(addrs, addr)
    while i > 0:
        i -= 1
        t = lines[i]
        if t.startswith("push ") and "lr" in t:
            return addrs[i]
        if addr - addrs[i] > 0x4000:
            break
    return 0


def cmd_cfuncs(args) -> None:
    """Group isFps30 sites by containing function; print the decompiled text (whole if short, else windows)."""
    out = open(args.out, "w", encoding="utf-8") if args.out else sys.stdout
    groups: dict[tuple[str, int], list[int]] = {}
    for a, kind in armdis.callers(GAME, ISFPS30):
        if kind == "literal":
            continue
        m = module_of(a)
        if args.module and m != args.module:
            continue
        r = fn_of(a)
        key = (m, r.addr if r else -listing_fn_start(m, a))
        groups.setdefault(key, []).append(a)
    for (m, fa), sites in sorted(groups.items(), key=lambda kv: min(kv[1])):
        rets = " ".join(f"{s + 4:#x}" for s in sites)
        if fa < 0 or fa == 0:
            st = -fa
            print(f"#### {m} NO-GHIDRA-FUNC start~{st:#x} sites(ret): {rets}", file=out)
            for s in sites:
                for ln in dis_window(m, s, args.before, args.after):
                    print("     " + ln, file=out)
                print("     ...", file=out)
            continue
        r = fn_at(fa)
        body = fn_text(r)
        print(f"#### {m} {r.name} @{r.addr:#x} size {r.size:#x} callers: {callers_desc(r, 6)} sites(ret): {rets}",
              file=out)
        if len(body) <= args.whole:
            for t in body[2:]:
                print("   c| " + t.rstrip()[:200], file=out)
            continue
        hits = [i for i, t in enumerate(body) if "isFps30" in t]
        shown = set()
        last = -10
        for i in hits:
            for k in range(max(2, i - args.cbefore), min(len(body), i + args.cafter + 1)):
                if k in shown:
                    continue
                if k > last + 1:
                    print("   c| ...", file=out)
                shown.add(k)
                last = k
                print("   c| " + body[k].rstrip()[:200], file=out)
        print("   c| ...", file=out)


def cmd_inlinec(args) -> None:
    """For every function with a byte load of +0x45/+0x3D: the decompiled lines that mention 0x45/0x3d."""
    out = open(args.out, "w", encoding="utf-8") if args.out else sys.stdout
    offs = [int(x, 16) for x in args.off.split(",")]
    pat = re.compile(r"^(ldrb|ldrsb)\w*\s+(\w+), \[(\w+), #(0x[0-9a-f]+)\]")
    mods = [f[:-2] for f in sorted(os.listdir(DIS)) if f.endswith(".s")]
    seen: dict[tuple[str, int], list[int]] = {}
    for m in mods:
        if args.module and m != args.module:
            continue
        addrs, lines = listing(m)
        for a, t in zip(addrs, lines):
            mm = pat.match(t)
            if not mm or int(mm.group(4), 16) not in offs or mm.group(3) == "sp":
                continue
            r = fn_of(a)
            key = (m, r.addr if r else -listing_fn_start(m, a))
            seen.setdefault(key, []).append(a)
    want = re.compile(r"0x(45|3d)\b")
    for (m, fa), loads in sorted(seen.items(), key=lambda kv: kv[1][0]):
        ls = " ".join(f"{x:#x}" for x in loads)
        if fa <= 0:
            print(f"#### {m} NO-GHIDRA-FUNC ~{-fa:#x} loads: {ls}", file=out)
            for x in loads:
                for ln in dis_window(m, x, 6, 2):
                    print("     " + ln, file=out)
            continue
        r = fn_at(fa)
        print(f"#### {m} {r.name} @{r.addr:#x} size {r.size:#x} loads: {ls}", file=out)
        body = fn_text(r)
        k = 0
        for t in body[2:]:
            if want.search(t):
                print("   c| " + t.strip()[:200], file=out)
                k += 1
                if k >= args.maxlines:
                    print("   c| …", file=out)
                    break


def cmd_fn(args) -> None:
    for tok in args.addrs:
        a = int(tok, 16)
        r = fn_of(a) or fn_at(a)
        if r is None:
            print(f"; no function at {a:#x}")
            continue
        print(f"; {fn_label(r)} {r.module} size {r.size:#x} callers: {callers_desc(r, 12)}")
        print("\n".join(fn_text(r)))


def cmd_dis(args) -> None:
    a = int(args.addr, 16)
    print("\n".join(dis_window(module_of(a), a, 0, args.count - 1)))


def main(argv) -> None:
    import argparse
    ap = argparse.ArgumentParser()
    sub = ap.add_subparsers(dest="cmd", required=True)
    s = sub.add_parser("sites")
    s.add_argument("--out")
    s.add_argument("--tsv")
    s.add_argument("--module")
    s.add_argument("--before", type=int, default=4)
    s.add_argument("--after", type=int, default=10)
    s.add_argument("--cbefore", type=int, default=2)
    s.add_argument("--cafter", type=int, default=4)
    i = sub.add_parser("inline")
    i.add_argument("--out")
    i.add_argument("--off", default="0x45,0x3d")
    i.add_argument("--module")
    f = sub.add_parser("fn")
    f.add_argument("addrs", nargs="+")
    d = sub.add_parser("dis")
    d.add_argument("addr")
    d.add_argument("count", type=int, nargs="?", default=40)
    cf = sub.add_parser("cfuncs")
    cf.add_argument("--out")
    cf.add_argument("--module")
    cf.add_argument("--whole", type=int, default=45)
    cf.add_argument("--cbefore", type=int, default=4)
    cf.add_argument("--cafter", type=int, default=10)
    cf.add_argument("--before", type=int, default=6)
    cf.add_argument("--after", type=int, default=16)
    ic = sub.add_parser("inlinec")
    ic.add_argument("--out")
    ic.add_argument("--off", default="0x45,0x3d")
    ic.add_argument("--module")
    ic.add_argument("--maxlines", type=int, default=6)
    args = ap.parse_args(argv)
    {"sites": cmd_sites, "inline": cmd_inline, "fn": cmd_fn, "dis": cmd_dis, "cfuncs": cmd_cfuncs,
     "inlinec": cmd_inlinec}[args.cmd](args)


if __name__ == "__main__":
    main(sys.argv[1:])
