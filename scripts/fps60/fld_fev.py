"""FLD workstream: field event scripts (FEvent/FEvent.dat, v1.2 romf2 > romfs) — find frame-counting loops.

    python scripts/fps60/fld_fev.py list [substr]
    python scripts/fps60/fld_fev.py dis <entry> [script#]          # flow-decoded listing (all scripts of entry)
    python scripts/fps60/fld_fev.py loops [substr] [--all]         # loops with counters / input / small waits
    python scripts/fps60/fld_fev.py opcount                         # opcode histogram (decoded instructions)
    python scripts/fps60/fld_fev.py grep <op> [...]                 # every use of opcodes
    python scripts/fps60/fld_fev.py var <id> [...]                  # every instruction touching variable ids

Decoder logic follows CRD's `crd_fevent.py` (copied, read-only use): argument descriptors at 0x3A0874
(16 bytes/op, 0x4E base ops + 567 field ops), bytecode as GlobalEvent::execLocalEvent 0x25BFA0;
.fev: u32 at +0x14 = script section S; S: u32 N, N u32, then script offsets relative to S; jump targets are
relative to S. Base ops (shared with battle AI, battle.md §1.4): 0x03 jmpif(cmp,a,b,expect,target),
0x04 jump(kind 0/2 jump, 1 call; target), 0x05 wait(n) [60 Hz units, decremented by the field step],
0x15 =, 0x16 +, 0x17 -, 0x18 *, 0x19 /, 0x23 ++, 0x24 --, 0x25 +=, 0x26 -=.
Field system variables (fld::EventSystem vt+0x2C = 0x2E225C): $702F..$7032 party hold/trg/rls/rep,
$7037..$703A field pad hold/trg/rls/rep, $703B/$703C, $7033..$7036/$703D..$7040 stick, $7041..$7043 touch.
There is NO step variable in the field set (unlike battle $7012).
"""
from __future__ import annotations

import os
import struct
import sys
from collections import Counter

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(os.path.dirname(HERE))
sys.path.insert(0, HERE)
sys.path.insert(0, os.path.join(ROOT, "scripts"))
import lib3dx  # noqa: E402

CODE = os.path.join(ROOT, "work", "fps60", "bin", "3dx_v12.code.bin")
BASE = 0x100000
FDESC = 0x3A0874
FNOPS = 0x4E + 567
SIZES = {0: 1, 1: 2, 2: 4, 3: 1, 4: 2, 5: 4, 6: 2, 7: 4, 8: 4}
NAMES = {0x00: "end", 0x01: "return", 0x03: "jmpif", 0x04: "jump", 0x05: "wait", 0x15: "set", 0x16: "add",
         0x17: "sub", 0x18: "mul", 0x19: "div", 0x23: "inc", 0x24: "dec", 0x25: "addto", 0x26: "subfrom",
         0x280: "staffroll"}
INPUT = {0x702F: "pHold", 0x7030: "pTrg", 0x7031: "pRls", 0x7032: "pRep", 0x7037: "hold", 0x7038: "trg",
         0x7039: "rls", 0x703A: "rep", 0x703B: "btnB", 0x703C: "btnC", 0x7041: "tp", 0x7042: "tpX", 0x7043: "tpY"}


def fdescs():
    c = open(CODE, "rb").read()
    out = []
    for op in range(FNOPS):
        b = c[FDESC - BASE + 16 * op: FDESC - BASE + 16 * op + 16]
        n = b[0] & 0x7F
        types = [(b[1 + i // 2] >> (4 * (i & 1))) & 0xF for i in range(n)]
        out.append((bool(b[0] & 0x80), types))
    return out


def entries():
    data = open(lib3dx.romfs_path("FEvent/FEvent.dat"), "rb").read()
    _v, es = lib3dx.read_bg4(data)
    out = {}
    for e in es:
        if e.size_flag:
            continue
        b = lib3dx.bg4_plain(e)
        if len(b) >= 0x20 and e.name.endswith(('.fev', '.fme')):
            out[e.name] = b
    return out


def decode_one(buf, dt, pos):
    if pos + 6 > len(buf):
        return None
    op = struct.unpack_from("<H", buf, pos)[0]
    if op >= FNOPS:
        return None
    mask = struct.unpack_from("<I", buf, pos + 2)[0]
    has_res, types = dt[op]
    if mask >> max(len(types), 0):
        return None
    p = pos + 6
    res = None
    if has_res:
        if p + 2 > len(buf):
            return None
        res = struct.unpack_from("<H", buf, p)[0]
        p += 2
    params = []
    for i, t in enumerate(types):
        if (mask >> i) & 1:
            if p + 2 > len(buf):
                return None
            params.append(("var", struct.unpack_from("<H", buf, p)[0]))
            p += 2
            continue
        sz = SIZES.get(t, 0)
        raw = buf[p:p + sz]
        if len(raw) < sz:
            return None
        if t == 8:
            v = struct.unpack("<f", raw)[0]
        elif t == 3:
            v = struct.unpack("<b", raw)[0]
        elif t in (4, 6):
            v = struct.unpack("<h", raw)[0]
        elif sz == 1:
            v = raw[0]
        elif sz == 2:
            v = struct.unpack("<H", raw)[0]
        elif sz == 4:
            v = struct.unpack("<I", raw)[0]
        else:
            v = None
        params.append((t, v))
        p += sz
    return (pos, op, mask, res, params), p


def imm(params, i):
    if i < len(params) and params[i][0] != "var":
        return params[i][1]
    return None


def layout(b):
    sec = struct.unpack_from("<I", b, 0x14)[0]
    n = struct.unpack_from("<I", b, sec)[0]
    first = sec + 4 + 4 * n
    offs = []
    p = first
    code_start = len(b)
    while p + 4 <= code_start:
        v = struct.unpack_from("<I", b, p)[0]
        offs.append(v)
        if v:
            code_start = min(code_start, sec + v)
        p += 4
    return sec, n, offs


BROAD = False  # timers: also report constant-delta loops without a compare on the counter
TBASE_SEC = False  # jump targets: buffer offsets (False) or relative to the script section (True)


def decode_flow(b, dt, rel_sec=None):
    rel_sec = TBASE_SEC if rel_sec is None else rel_sec
    sec, n, offs = layout(b)
    tb = sec if rel_sec else 0
    work = [sec + o for o in offs if o and sec + o < len(b)]
    seen = {}
    while work:
        pos = work.pop()
        while pos not in seen:
            r = decode_one(b, dt, pos)
            if r is None:
                break
            ins, nxt = r
            seen[pos] = ins
            op, params = ins[1], ins[4]
            if op in (0x00, 0x01):
                break
            if op == 0x03:
                t = imm(params, 4)
                if t is not None and tb + t < len(b):
                    work.append(tb + t)
            if op == 0x04:
                kind, t = imm(params, 0), imm(params, 1)
                if t is not None and tb + t < len(b):
                    work.append(tb + t)
                if kind in (0, 2):
                    break
            pos = nxt
    return [seen[k] for k in sorted(seen)], sec, offs


def fmt(ins):
    pos, op, mask, res, params = ins
    ps = []
    for t, v in params:
        if t == "var":
            ps.append(f"${v:04x}")
        elif t == 8:
            ps.append(f"{v:g}f")
        else:
            ps.append(f"{v:#x}" if isinstance(v, int) and v > 9 else str(v))
    r = f"${res:04x} = " if res is not None else ""
    return f"{pos:05x}: {r}{NAMES.get(op, f'op{op:03x}')}({', '.join(ps)})"


def var_ids(ins):
    out = set()
    if ins[3] is not None:
        out.add(ins[3])
    for t, v in ins[4]:
        if t == "var":
            out.add(v)
    return out


def loops_in(name, b, dt, show_all=False):
    ins, sec, offs = decode_flow(b, dt)
    order = [i[0] for i in ins]
    by = {i[0]: i for i in ins}
    out = []
    for i in ins:
        op, params = i[1], i[4]
        t = None
        if op == 0x04 and imm(params, 0) in (0, 2):
            t = imm(params, 1)
        elif op == 0x03:
            t = imm(params, 4)
        if t is None:
            continue
        t += sec if TBASE_SEC else 0
        if t >= i[0]:
            continue
        body = [by[p] for p in order if t <= p <= i[0]]
        waits = [imm(x[4], 0) if x[4] and x[4][0][0] != "var" else "var" for x in body if x[1] == 0x05]
        inputs = sorted({INPUT[v] for x in body for v in var_ids(x) if v in INPUT})
        # counters: ++/--, +=/-= with immediate, x = x + imm
        ctr = {}
        for x in body:
            if x[1] in (0x23, 0x24) and x[3] is not None:
                ctr.setdefault(x[3], []).append("++" if x[1] == 0x23 else "--")
            elif x[1] in (0x25, 0x26) and x[3] is not None and x[4]:
                amt = x[4][0]
                ctr.setdefault(x[3], []).append(("+=" if x[1] == 0x25 else "-=") +
                                                (f"${amt[1]:04x}" if amt[0] == "var" else f"{amt[1]:g}"))
            elif x[1] in (0x16, 0x17) and x[3] is not None and len(x[4]) >= 2:
                a, c = x[4][0], x[4][1]
                if a == ("var", x[3]) and c[0] != "var":
                    ctr.setdefault(x[3], []).append(("+" if x[1] == 0x16 else "-") + f"{c[1]:g}")
        # compares of a counter with an immediate inside the body
        cmps = []
        for x in body:
            if x[1] == 0x03 and len(x[4]) >= 3:
                a, bb = x[4][1], x[4][2]
                for v, other in ((a, bb), (bb, a)):
                    if v[0] == "var" and v[1] in ctr and other[0] != "var":
                        cmps.append(f"${v[1]:04x}~{other[1]:g}")
        timed = [v for v in ctr if v < 0x7000]
        interesting = bool(ctr) and bool(waits) or (inputs and waits)
        if show_all or interesting:
            out.append((t, i[0], waits, inputs, ctr, cmps, body))
    return out


def timers_in(name, b, dt, maxn=120):
    """Frame-counting loops: a backward branch whose body (<= maxn instructions) waits wait(1) per
    iteration and advances a counter X by a constant (inc/dec/addto/subfrom/add/sub imm) where X is
    not re-set inside the body and X is compared by a jmpif in the body. Returns list of dicts."""
    ins, sec, offs = decode_flow(b, dt)
    order = [i[0] for i in ins]
    by = {i[0]: i for i in ins}
    res = []
    for i in ins:
        op, params = i[1], i[4]
        t = None
        if op == 0x04 and imm(params, 0) in (0, 2):
            t = imm(params, 1)
        elif op == 0x03:
            t = imm(params, 4)
        if t is None:
            continue
        t += sec if TBASE_SEC else 0
        if t >= i[0]:
            continue
        body = [by[p] for p in order if t <= p <= i[0]]
        if len(body) > maxn:
            continue
        w = [imm(x[4], 0) if x[4] and x[4][0][0] != "var" else "var" for x in body if x[1] == 0x05]
        if 1 not in w:
            continue
        sets = {x[3] for x in body if x[1] == 0x15 and x[3] is not None and x[4] and x[4][0][0] == "var"}
        # variables recomputed in the body from something other than themselves (fresh values, not accumulators)
        for x in body:
            if x[3] is None or x[1] in (0x23, 0x24, 0x25, 0x26) or x[1] == 0x15 and x[4] and x[4][0][0] != "var":
                continue
            if x[1] in (0x16, 0x17) and len(x[4]) >= 2 and x[4][0] == ("var", x[3]) and x[4][1][0] != "var":
                continue
            sets.add(x[3])
        # a variable whose first write in the iteration is a set(imm) is a fresh per-iteration accumulator
        first_w = {}
        for x in body:
            if x[3] is not None and x[3] not in first_w:
                first_w[x[3]] = x[1]
        for v, op0 in first_w.items():
            if op0 == 0x15:
                sets.add(v)
        ctr = {}
        for x in body:
            v, d = None, None
            if x[1] in (0x23, 0x24) and x[3] is not None:
                v, d = x[3], (1 if x[1] == 0x23 else -1)
            elif x[1] in (0x25, 0x26) and x[3] is not None and x[4] and x[4][0][0] != "var":
                v, d = x[3], x[4][0][1] * (1 if x[1] == 0x25 else -1)
            elif x[1] in (0x16, 0x17) and x[3] is not None and len(x[4]) >= 2 and x[4][0] == ("var", x[3]) \
                    and x[4][1][0] != "var":
                v, d = x[3], x[4][1][1] * (1 if x[1] == 0x16 else -1)
            if v is not None and v not in sets and (v < 0x7000 or 0x7078 <= v < 0x70A8):
                ctr.setdefault(v, []).append(d)
        if not ctr:
            continue
        cmps = []
        for x in body:
            if x[1] == 0x03 and len(x[4]) >= 3:
                for a, other in ((x[4][1], x[4][2]), (x[4][2], x[4][1])):
                    if a[0] == "var" and a[1] in ctr:
                        cmps.append((a[1], other[1] if other[0] != "var" else f"${other[1]:04x}"))
        if not cmps and not BROAD:
            continue
        inputs = sorted({INPUT[v] for x in body for v in var_ids(x) if v in INPUT})
        res.append({"entry": name, "lo": t, "hi": i[0], "n": len(body), "waits": w, "body": body, "in": inputs,
                    "ctr": {f"${k:04x}": v for k, v in ctr.items()},
                    "cmp": [(f"${a:04x}", c) for a, c in cmps]})
    # dedupe nested duplicates (same counter, same compare, overlapping)
    out, seen = [], set()
    for r in sorted(res, key=lambda r: (r["lo"], r["hi"] - r["lo"])):
        key = (tuple(sorted(r["ctr"])), tuple(r["cmp"]))
        if any(k[0] == key and k[1] <= r["lo"] <= k[2] for k in seen):
            continue
        seen.add((key, r["lo"], r["hi"]))
        out.append(r)
    return out


def main(argv):
    global BROAD
    if not argv:
        print(__doc__)
        return
    dt = fdescs()
    es = entries()
    cmd = argv[0]
    if cmd == "list":
        sub = argv[1] if len(argv) > 1 else ""
        for k, v in es.items():
            if sub in k:
                print(k, len(v))
        print(len(es), "entries")
    elif cmd == "dis":
        b = es[argv[1]]
        ins, sec, offs = decode_flow(b, dt)
        print(f"; {argv[1]} {len(b)} bytes sec={sec:#x} scripts={len(offs)}")
        starts = {sec + o: k for k, o in enumerate(offs) if o}
        for i in ins:
            if i[0] in starts:
                print(f"; ---- script #{starts[i[0]]}")
            s = fmt(i)
            if i[1] == 0x03 and imm(i[4], 4) is not None:
                s += f"   ; -> {(sec if TBASE_SEC else 0) + imm(i[4], 4):05x}"
            if i[1] == 0x04 and imm(i[4], 1) is not None:
                s += f"   ; -> {(sec if TBASE_SEC else 0) + imm(i[4], 1):05x}"
            print(s)
    elif cmd == "loops":
        sub = argv[1] if len(argv) > 1 and not argv[1].startswith("--") else ""
        show_all = "--all" in argv
        tot = Counter()
        for k in sorted(es):
            if sub not in k:
                continue
            try:
                ls = loops_in(k, es[k], dt, show_all)
            except Exception as exc:  # noqa: BLE001
                print(f"{k}: decode error {exc}")
                continue
            for (t, e, waits, inputs, ctr, cmps, body) in ls:
                tot["loops"] += 1
                if 1 in waits:
                    tot["wait1"] += 1
                if ctr:
                    tot["ctr"] += 1
                c = {f"${v:04x}": ops for v, ops in ctr.items()}
                print(f"{k:28s} {t:05x}-{e:05x} n={len(body):3d} waits={waits[:4]} in={inputs} ctr={c} cmp={cmps[:4]}")
        print(dict(tot))
    elif cmd == "timers":
        sub = argv[1] if len(argv) > 1 and not argv[1].startswith("--") else ""
        maxn = int(argv[argv.index("--maxn") + 1]) if "--maxn" in argv else 120
        BROAD = "--broad" in argv
        n = 0
        rooms = set()
        for k in sorted(es):
            if sub not in k:
                continue
            try:
                ts = timers_in(k, es[k], dt, maxn)
            except Exception as exc:  # noqa: BLE001
                print(f"{k}: decode error {exc}")
                continue
            for r in ts:
                n += 1
                rooms.add(k)
                print(f"{k:32s} {r['lo']:05x}-{r['hi']:05x} n={r['n']:3d} waits={r['waits'][:4]} in={r['in']} ctr={r['ctr']} cmp={r['cmp'][:3]}")
                if "--body" in argv:
                    for x in r["body"]:
                        print("        " + fmt(x))
        print(f"; {n} frame-timer loops in {len(rooms)} entries")
    elif cmd == "tbase":
        # Which base puts jump targets on decoded instruction boundaries: buffer offset or sec-relative?
        for rel in (False, True):
            ok = tot = cover = 0
            for k in sorted(es):
                b = es[k]
                ins, sec, _o = decode_flow(b, dt, rel_sec=rel)
                pos = {i[0] for i in ins}
                cover += len(ins)
                base = sec if rel else 0
                for i in ins:
                    t = imm(i[4], 4) if i[1] == 0x03 else (imm(i[4], 1) if i[1] == 0x04 else None)
                    if t is None:
                        continue
                    tot += 1
                    ok += (base + t) in pos
            print(f"rel_sec={rel}: targets {tot}, on decoded boundary {ok}, instructions decoded {cover}")
    elif cmd == "rareops":
        # opcodes (>= 0x4E) used by the given entries (substrings) and in at most --max entries overall
        subs = [a for a in argv[1:] if not a.startswith("--")]
        mx = int(argv[argv.index("--max") + 1]) if "--max" in argv else 6
        use = {}
        for k in sorted(es):
            ins, _s, _o = decode_flow(es[k], dt)
            for op in {i[1] for i in ins if i[1] >= 0x4E}:
                use.setdefault(op, set()).add(k)
        c = open(CODE, "rb").read()
        for op in sorted(use):
            ents = use[op]
            if len(ents) > mx or not any(any(s in e for s in subs) for e in ents):
                continue
            fn, adj = struct.unpack_from("<II", c, 0x3A30C4 - BASE + (op - 0x4E) * 8)
            print(f"op{op:03x} handler {fn:#x} used in {len(ents)}: {' '.join(sorted(ents))}")
    elif cmd == "waitsites":
        # Option B data patch: every wait(1) inside a detected frame-timer loop (excluding test rooms and
        # loops that read button/touch edges), as entry, instruction offset, u16 param offset, value.
        BROAD = True
        maxn = int(argv[argv.index("--maxn") + 1]) if "--maxn" in argv else 80
        edge = {"trg", "pTrg", "rls", "pRls", "tp", "btnB", "btnC"}
        sites = {}
        skipped = []
        for k in sorted(es):
            for r in timers_in(k, es[k], dt, maxn):
                if "_test_" in k:
                    continue
                if edge & set(r["in"]):
                    skipped.append(f"{k} {r['lo']:05x}-{r['hi']:05x} in={r['in']}")
                    continue
                for x in r["body"]:
                    if x[1] == 0x05 and x[4] and x[4][0][0] != "var" and x[4][0][1] == 1:
                        sites.setdefault(k, set()).add(x[0])
        n = 0
        for k in sorted(sites):
            for pos in sorted(sites[k]):
                n += 1
                print(f"{k}\t{pos:#07x}\t{pos + 6:#07x}\t1\t2")
        print(f"; {n} wait(1) sites in {len(sites)} entries (u16 param at instruction+6: 1 -> 2)")
        for s in skipped:
            print(f"; not patched (reads edges): {s}")
    elif cmd == "opcount":
        c = Counter()
        for k in sorted(es):
            ins, _s, _o = decode_flow(es[k], dt)
            c.update(i[1] for i in ins)
        for op, cnt in sorted(c.items()):
            print(f"op{op:03x} {cnt}")
    elif cmd == "grep":
        ops = {int(x, 0) for x in argv[1:]}
        for k in sorted(es):
            ins, sec, _o = decode_flow(es[k], dt)
            for i in ins:
                if i[1] in ops:
                    print(f"{k:28s} {fmt(i)}")
    elif cmd == "var":
        vids = {int(x, 0) for x in argv[1:]}
        for k in sorted(es):
            ins, sec, _o = decode_flow(es[k], dt)
            for i in ins:
                if var_ids(i) & vids:
                    print(f"{k:28s} {fmt(i)}")
    else:
        print(__doc__)


if __name__ == "__main__":
    main(sys.argv[1:])
