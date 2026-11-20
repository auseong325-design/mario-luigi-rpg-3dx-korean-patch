"""ENG workstream helper (60fps timing core of 3DX v1.2). Read-only analysis; never writes outside work/fps60/analysis.

    python scripts/fps60/eng_tool.py [game] func <addr> [maxinsn]      # disassemble the whole function containing addr
    python scripts/fps60/eng_tool.py [game] regs <addr>                # constant values of r0-r12 just before addr (linear scan from func start)
    python scripts/fps60/eng_tool.py [game] rtti [--out file]          # all typeinfos (name, kind, bases) + vtables
    python scripts/fps60/eng_tool.py [game] derived <TypeName> [--slots N]   # classes derived from TypeName, their vtables, slot overrides
    python scripts/fps60/eng_tool.py [game] vt <vptr> [n]              # dump vtable slots with symbols
    python scripts/fps60/eng_tool.py [game] strb <offset> [--mod M]    # every strb/ldrb [rX,#offset] (grep helper over listings)

Function start heuristic: walk back from addr to the nearest 'push {...,lr}' (or stmdb sp!) that is preceded by a
return / branch / literal word. Good enough for ARMCC output; check by eye.
"""
from __future__ import annotations

import json
import os
import re
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import armdis  # noqa: E402  (lead-owned, imported read-only)

ROOT = armdis.ROOT


def is_push_lr(w: int) -> bool:
    # STMDB sp!, {..., lr}  (push)   cond=AL
    return (w & 0xFFFF4000) == 0xE92D4000


def is_terminator(w: int) -> bool:
    if (w & 0x0FFFFFF0) == 0x012FFF10 and (w >> 28) == 0xE:  # bx rX (AL)
        return True
    if (w & 0xFFFF8000) == 0xE8BD8000:  # pop {..., pc}
        return True
    if (w & 0x0F000000) == 0x0A000000 and (w >> 28) == 0xE:  # b (AL)
        return True
    if (w & 0xFFFFF000) == 0xE49DF000:  # ldr pc, [sp], #4
        return True
    return False


def func_start(g, addr: int, limit: int = 0x4000) -> int:
    a = addr & ~3
    best = None
    while addr - a < limit:
        w = g.u32(a)
        if w is None:
            break
        if is_push_lr(w):
            prev = g.u32(a - 4)
            if prev is None or is_terminator(prev) or prev == 0xE1A00000 or prev == 0xE320F000 or not _decodes(g, a - 4):
                return a
            if best is None:
                best = a
        a -= 4
    return best if best is not None else addr


def _decodes(g, a: int) -> bool:
    w = g.u32(a)
    if w is None:
        return False
    # literal-pool heuristic: a word whose condition field is not AL is most likely data at a function boundary
    return (w >> 28) == 0xE


def func_end(g, start: int, limit: int = 0x8000) -> int:
    """First terminating 'pop {...pc}' / 'bx lr' after which the next word is a new push or data. Heuristic."""
    a = start
    last_term = None
    while a - start < limit:
        w = g.u32(a)
        if w is None:
            break
        if a != start and is_push_lr(w) and last_term is not None and last_term >= a - 0x400:
            return a
        if is_terminator(w):
            last_term = a
        a += 4
    return a


def cmd_func(g, addr: int, maxinsn: int = 3000) -> None:
    s = func_start(g, addr)
    e = func_end(g, s)
    n = min(maxinsn, (e - s) // 4)
    print(f"; function {s:#x}..{e:#x}  ({armdis.where(g.name, s)})")
    print("\n".join(armdis.disasm(g.name, s, n)))


REG = {f"r{i}": i for i in range(13)}
REG.update({"sb": 9, "sl": 10, "fp": 11, "ip": 12})


def cmd_regs(g, addr: int) -> dict:
    """Very small constant propagation: mov/mvn/movw/movt/add rd,rn,#imm/ldr =lit, over the straight-line text
    from function start to addr (ignores branches; reports the LAST definition seen)."""
    s = func_start(g, addr)
    md = armdis.md(False)
    md.detail = True
    vals: dict[int, object] = {}
    defs: dict[int, int] = {}
    code = g.read(s, addr - s)
    skip_to = 0

    def _iter():
        off = 0
        while off < len(code):
            got = False
            for ins in md.disasm(code[off:], s + off):
                got = True
                yield ins
                off = ins.address - s + ins.size
            if not got or off < len(code):
                off += 4 if not got else 0
                if not got:
                    continue
                # disasm stopped on an undecodable word: step over it
                off += 4

    for ins in _iter():
        if ins.address < skip_to:
            continue
        m, ops = ins.mnemonic, ins.op_str
        parts = [p.strip() for p in ops.split(",")]
        if m == "b" and ops.startswith("#"):
            t = int(ops[1:], 16)
            if ins.address < t <= addr:
                skip_to = t  # jump over literal pool / else-block (linear approximation)
            continue
        if (struct.unpack("<I", g.read(ins.address, 4))[0] >> 28) != 0xE and m in ("andeq", "andseq", "eorseq", "eoreq", "ldrsbeq", "ldrhteq", "ldrshteq", "strheq", "mulseq", "mlaseq", "ldrdeq", "andmi", "svclo", "cdp2"):
            continue  # data word decoded as conditional instruction
        try:
            written = {ins.reg_name(r) for r in ins.regs_access()[1]}
        except Exception:  # noqa: BLE001
            written = set()
        if m.startswith(("bl", "blx")) and not m.startswith("bls") and m not in ("blo", "ble"):
            for r in (0, 1, 2, 3, 12):
                vals[r] = f"?(call@{ins.address:#x})"
                defs[r] = ins.address
            continue
        for wn in written:
            if wn in REG and (not parts or parts[0] != wn):
                vals[REG[wn]] = f"?({ins.address:#x})"  # writeback / ldm etc.
                defs[REG[wn]] = ins.address
        rd = REG.get(parts[0]) if parts else None
        if rd is None or parts[0] not in written:
            continue
        defs[rd] = ins.address
        cond = m[-2:] in ("eq", "ne", "cs", "cc", "mi", "pl", "vs", "vc", "hi", "ls", "ge", "lt", "gt", "le") and len(m) > 3
        val: object = f"?({ins.address:#x} {m} {ops})"
        if m.startswith(("mov", "mvn")) and len(parts) == 2 and parts[1].startswith("#"):
            v = int(parts[1][1:], 0) & 0xFFFFFFFF
            if m.startswith("mvn"):
                v = (~v) & 0xFFFFFFFF
            val = v
        elif m.startswith("mov") and len(parts) == 2 and parts[1] in REG:
            val = vals.get(REG[parts[1]], "?")
        elif m.startswith("ldr") and "[pc," in ops:
            mm = re.search(r"\[pc, #(-?0x[0-9a-f]+|-?\d+)\]", ops)
            if mm:
                lit = ins.address + 8 + int(mm.group(1), 0)
                val = g.u32(lit)
        if cond:
            val = f"{val if not isinstance(val, int) else hex(val)}|cond@{ins.address:#x}"
        vals[rd] = val
    out = {}
    for name, r in sorted(((k, v) for k, v in REG.items() if k in ("r0", "r1", "r2", "r3", "r4", "r5", "r6", "r7", "r8", "sb", "sl", "fp", "ip")), key=lambda kv: kv[1]):
        v = vals.get(r, "-")
        out[name] = v
        d = f"  (def @{defs[r]:#x})" if r in defs else ""
        print((f"{name:3s} = {v:#x}" if isinstance(v, int) else f"{name:3s} = {v}") + d)
    print(f"; scanned {s:#x}..{addr:#x} linearly (branches ignored)")
    return out


# ---------------------------------------------------------------- RTTI
def cstr(g, a: int, n: int = 200) -> str:
    b = g.read(a, n)
    z = b.find(b"\0")
    return b[: z if z >= 0 else n].decode("latin1")


def rtti(g) -> dict:
    ti_vt = {}
    for kind, sym in (("class", "_ZTVN10__cxxabiv117__class_type_infoE"), ("si", "_ZTVN10__cxxabiv120__si_class_type_infoE"),
                      ("vmi", "_ZTVN10__cxxabiv121__vmi_class_type_infoE")):
        ti_vt[g.syms[sym] + 8] = kind
    types: dict[int, dict] = {}
    for base, data, mod in g.regions:
        for off in range(0, len(data) - 8, 4):
            w = struct.unpack_from("<I", data, off)[0]
            k = ti_vt.get(w)
            if not k:
                continue
            a = base + off
            namep = struct.unpack_from("<I", data, off + 4)[0]
            name = cstr(g, namep)
            if not name or not re.match(r"^[0-9A-Za-z_]+$", name):
                continue
            t = {"addr": a, "mod": mod, "kind": k, "name": name, "bases": []}
            if k == "si":
                t["bases"].append(struct.unpack_from("<I", data, off + 8)[0])
            elif k == "vmi":
                cnt = struct.unpack_from("<I", data, off + 12)[0]
                if cnt < 16:
                    for i in range(cnt):
                        t["bases"].append(struct.unpack_from("<I", data, off + 16 + 8 * i)[0])
            types[a] = t
    # vtables: [offset_to_top][typeinfo][slot0...]
    text = g.text_ranges

    def is_code(v: int) -> bool:
        return any(s <= (v & ~1) < e for _, s, e in text)

    vts: dict[int, list] = {a: [] for a in types}
    for base, data, mod in g.regions:
        for off in range(4, len(data) - 8, 4):
            w = struct.unpack_from("<I", data, off)[0]
            if w not in types:
                continue
            ott = struct.unpack_from("<i", data, off - 4)[0]
            nxt = struct.unpack_from("<I", data, off + 4)[0]
            if -0x4000 <= ott <= 0 and is_code(nxt):
                vts[w].append({"vptr": base + off + 4, "ott": ott, "mod": mod})
    for a, t in types.items():
        t["vtables"] = vts.get(a, [])
    return types


def demangle_type(name: str) -> str:
    # "N2ad2fw8TaskBaseE" -> ad::fw::TaskBase ; "8CmdList" -> CmdList
    s = name
    if s.startswith("N") and s.endswith("E"):
        s = s[1:-1]
    parts = []
    while s:
        m = re.match(r"(\d+)", s)
        if not m:
            parts.append(s)
            break
        ln = int(m.group(1))
        s = s[len(m.group(1)):]
        parts.append(s[:ln])
        s = s[ln:]
    return "::".join(parts)


def vt_slots(g, vptr: int, n: int = 24) -> list[int]:
    out = []
    for i in range(n):
        v = g.u32(vptr + 4 * i)
        if v is None:
            break
        out.append(v)
    return out


def symname(g, a: int) -> str:
    s = g.a2s.get(a & ~1)
    return armdis.demangle_hint(s) if s else ""


def cmd_derived(g, root: str, nslots: int = 24) -> None:
    types = rtti(g)
    by_name = {demangle_type(t["name"]): t for t in types.values()}
    if root not in by_name:
        raise SystemExit(f"type {root} not found")
    root_t = by_name[root]
    children: dict[int, list[int]] = {}
    for a, t in types.items():
        for b in t["bases"]:
            children.setdefault(b, []).append(a)
    root_vt = root_t["vtables"][0]["vptr"] if root_t["vtables"] else None
    root_slots = vt_slots(g, root_vt, nslots) if root_vt else []
    print(f"# {root} typeinfo {root_t['addr']:#x} vtable {root_vt and hex(root_vt)}")
    for i, v in enumerate(root_slots):
        print(f"#   slot {i:2d} (+{4*i:#04x}) {v:#x} {symname(g, v)}")
    seen = set()

    def walk(a: int, depth: int) -> None:
        for c in sorted(children.get(a, [])):
            if c in seen:
                continue
            seen.add(c)
            t = types[c]
            vts = [v for v in t["vtables"] if v["ott"] == 0]
            line = f"{'  ' * depth}{demangle_type(t['name'])}  [{t['mod']}] ti={c:#x}"
            if vts:
                vp = vts[0]["vptr"]
                sl = vt_slots(g, vp, nslots)
                ov = [f"{i}:{sl[i]:#x}{('=' + symname(g, sl[i])) if symname(g, sl[i]) else ''}" for i in range(min(len(sl), len(root_slots))) if sl[i] != root_slots[i]]
                line += f" vt={vp:#x} overrides: {' '.join(ov) if ov else '-'}"
            else:
                line += " (no primary vtable found)"
            print(line)
            walk(c, depth + 1)

    walk(root_t["addr"], 1)


def main(argv: list[str]) -> None:
    name = argv[0] if argv and argv[0] in armdis.GAMES else "3dx_v12"
    args = argv[1:] if argv and argv[0] in armdis.GAMES else argv
    g = armdis.game(name)
    cmd = args[0]
    if cmd == "func":
        cmd_func(g, int(args[1], 0), int(args[2]) if len(args) > 2 else 3000)
    elif cmd == "regs":
        cmd_regs(g, int(args[1], 0))
    elif cmd == "rtti":
        types = rtti(g)
        rows = []
        for a, t in sorted(types.items()):
            rows.append({"addr": hex(a), "mod": t["mod"], "kind": t["kind"], "name": demangle_type(t["name"]),
                         "bases": [demangle_type(types[b]["name"]) if b in types else hex(b) for b in t["bases"]],
                         "vtables": [hex(v["vptr"]) + ("" if v["ott"] == 0 else f"@{v['ott']}") for v in t["vtables"]]})
        if "--out" in args:
            fn = args[args.index("--out") + 1]
            json.dump(rows, open(fn, "w", encoding="utf-8"), indent=1)
            print("wrote", fn, len(rows))
        else:
            for r in rows:
                print(r["addr"], r["mod"], r["kind"], r["name"], r["bases"], r["vtables"])
    elif cmd == "derived":
        n = int(args[args.index("--slots") + 1]) if "--slots" in args else 24
        cmd_derived(g, args[1], n)
    elif cmd == "vt":
        vp = int(args[1], 0)
        n = int(args[2]) if len(args) > 2 else 24
        for i, v in enumerate(vt_slots(g, vp, n)):
            print(f"slot {i:2d} (+{4*i:#04x}) {v:#x} {symname(g, v)}")
    elif cmd == "modes":
        # GameMain mode table: u32[mode] -> {char** names, u32 count}
        tbl = int(args[1], 0) if len(args) > 1 else 0x3F4180
        for m in range(16):
            p = g.u32(tbl + 4 * m)
            if not p or not (0x100000 <= p < 0x500000):
                print(f"mode {m:2d}: {p!r}")
                continue
            names_p, cnt = g.u32(p), g.u32(p + 4)
            names = []
            if names_p and cnt is not None and cnt < 16:
                for i in range(cnt):
                    sp = g.u32(names_p + 4 * i)
                    raw = g.read(sp, 160) if sp else b""
                    z = raw.find(b"\0\0")
                    names.append(raw[: z + (z % 2) if z >= 0 else 160].decode("utf-16le", "replace") if raw[1:2] == b"\0" else cstr(g, sp))
            print(f"mode {m:2d}: entry@{p:#x} names@{names_p:#x} n={cnt} {names}")
    elif cmd == "str":
        print(repr(cstr(g, int(args[1], 0))))
    else:
        raise SystemExit(__doc__)


if __name__ == "__main__":
    main(sys.argv[1:])
