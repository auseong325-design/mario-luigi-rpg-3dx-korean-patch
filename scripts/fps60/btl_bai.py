"""BTL workstream: decode 3DX battle AI scripts (romfs BAI/BAI.dat, BG4 of *.bai) with the command
descriptor table that Battle.cro's btl::AISys passes to GlobalEvent::init (0x1105f730, 16 bytes/op).

    python scripts/fps60/btl_bai.py list                        # entries
    python scripts/fps60/btl_bai.py dis atk_pc_solo_jump        # linear disassembly of one script
    python scripts/fps60/btl_bai.py grep 0x18e [0x18f ...]      # every use of the given opcodes, all scripts
    python scripts/fps60/btl_bai.py var 0x7011                  # every command that reads/writes variable id
    python scripts/fps60/btl_bai.py stats                       # decode coverage per script

Bytecode (from GlobalEvent::execLocalEvent @0x25bfa0, confirmed by disassembly):
    u16 opcode; u32 varmask (bit i: param i is a u16 variable id instead of an immediate);
    [u16 result variable id if desc[0] & 0x80]; params: count = desc[0] & 0x7f, type = nibble i of
    desc[1..] (low nibble first). Immediate sizes: 0 u8, 1 u16, 2 u32, 3 s8, 4 s16, 5 u32, 6 s16,
    7 u32, 8 f32 (float slot), >=9 none.
File: u32 N; N x u32 label offsets; code starts at 4 + 4*N (btl::AISys::startAtkAI @0x11043550).
Opcodes < 0x4e: GlobalEvent base table (static 0x389918); >= 0x4e: AISys PMF table 0x1105e118.
Read-only.
"""
from __future__ import annotations

import os
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(os.path.dirname(HERE))
sys.path.insert(0, HERE)
sys.path.insert(0, os.path.join(ROOT, "scripts"))
import armdis  # noqa: E402
import lib3dx  # noqa: E402

DESC = 0x1105F730
NOPS = 0x4E + 535
SIZES = {0: 1, 1: 2, 2: 4, 3: 1, 4: 2, 5: 4, 6: 2, 7: 4, 8: 4}

# Opcode names established by disassembly in work/fps60/analysis/battle.md
NAMES = {
    0x00: "end", 0x01: "return", 0x05: "wait", 0x18E: "setKeyContFrmEndTime", 0x18F: "checkKeyCont",
}


def descs():
    g = armdis.game("3dx_v12")
    out = []
    for op in range(NOPS):
        b = g.read(DESC + 16 * op, 16)
        n = b[0] & 0x7F
        types = [(b[1 + i // 2] >> (4 * (i & 1))) & 0xF for i in range(n)]
        out.append((bool(b[0] & 0x80), types))
    return out


def load():
    data = open(os.path.join(ROOT, "romfs", "BAI", "BAI.dat"), "rb").read()
    _v, es = lib3dx.read_bg4(data)
    return {e.name: lib3dx.bg4_plain(e) for e in es if not e.size_flag}


def decode(buf: bytes, dt, start: int | None = None, stop_at_bad=True):
    n = struct.unpack_from("<I", buf, 0)[0]
    pos = 4 + 4 * n if start is None else start
    out = []
    while pos + 6 <= len(buf):
        op = struct.unpack_from("<H", buf, pos)[0]
        if op >= NOPS:
            out.append((pos, None, None, None, None))
            if stop_at_bad:
                break
            pos += 2
            continue
        mask = struct.unpack_from("<I", buf, pos + 2)[0]
        p = pos + 6
        has_res, types = dt[op]
        res = None
        if has_res:
            res = struct.unpack_from("<H", buf, p)[0]
            p += 2
        params = []
        for i, t in enumerate(types):
            if (mask >> i) & 1:
                params.append(("var", struct.unpack_from("<H", buf, p)[0]))
                p += 2
            else:
                sz = SIZES.get(t, 0)
                raw = buf[p:p + sz]
                if t == 8:
                    v = struct.unpack("<f", raw)[0]
                elif t in (3,):
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
        out.append((pos, op, mask, res, params))
        pos = p
    return out, n


def decode_one(buf: bytes, dt, pos: int):
    """Decode a single command at pos, or None if pos does not hold a valid command."""
    if pos + 6 > len(buf):
        return None
    op = struct.unpack_from("<H", buf, pos)[0]
    if op >= NOPS:
        return None
    mask = struct.unpack_from("<I", buf, pos + 2)[0]
    has_res, types = dt[op]
    if mask >> max(len(types), 0):
        return None              # mask bits beyond the parameter count: not a command
    p = pos + 6
    res = None
    if has_res:
        res = struct.unpack_from("<H", buf, p)[0]
        p += 2
    params = []
    for i, t in enumerate(types):
        if (mask >> i) & 1:
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
    if p > len(buf):
        return None
    return (pos, op, mask, res, params), p


def imm(params, i):
    if i < len(params) and params[i][0] != "var":
        return params[i][1]
    return None


def decode_flow(buf: bytes, dt):
    """Recursive descent from the code start (and every label) following op003 (conditional jump,
    target = param 4), op004 (param 0: 0/2 jump, 1 call; target = param 1). Targets are offsets
    from the script start (GlobalEvent op 4 @0x1340d0: ptr = base + offset)."""
    n = struct.unpack_from("<I", buf, 0)[0]
    code0 = 4 + 4 * n
    work = [code0] + [x for x in struct.unpack_from(f"<{n}I", buf, 4) if x]
    seen: dict[int, tuple] = {}
    while work:
        pos = work.pop()
        while pos not in seen:
            r = decode_one(buf, dt, pos)
            if r is None:
                break
            ins, nxt = r
            seen[pos] = ins
            op, params = ins[1], ins[4]
            if op in (0x00, 0x01):               # end / return
                break
            if op == 0x03:
                t = imm(params, 4)
                if t is not None and code0 <= t < len(buf):
                    work.append(t)
            if op == 0x04:
                kind, t = imm(params, 0), imm(params, 1)
                if t is not None and code0 <= t < len(buf):
                    work.append(t)
                if kind in (0, 2):
                    break
            pos = nxt
    return [seen[k] for k in sorted(seen)], n


def targets_of(ins):
    op, params = ins[1], ins[4]
    if op == 0x03:
        t = imm(params, 4)
        return [t] if t is not None else []
    if op == 0x04:
        t = imm(params, 1)
        return [t] if t is not None else []
    return []


def decode_all(buf: bytes, dt):
    """Union of decode_flow and a linear sweep that, at an undecodable word, resumes at the next
    known branch target (or the next offset where >= 8 consecutive commands decode)."""
    flow, n = decode_flow(buf, dt)
    code0 = 4 + 4 * n
    seen = {i[0]: i for i in flow}
    tg = set()
    for i in flow:
        tg.update(t for t in targets_of(i) if code0 <= t < len(buf))
    pos = code0
    while pos < len(buf) - 6:
        r = decode_one(buf, dt, pos)
        if r is None:
            nxt_t = min((t for t in tg if t > pos), default=None)
            # probe for a run of valid commands
            probe = pos + 1
            found = None
            while probe < len(buf) - 6 and (nxt_t is None or probe < nxt_t):
                q, ok = probe, 0
                while ok < 8:
                    rr = decode_one(buf, dt, q)
                    if rr is None or rr[0][1] == 0:
                        break
                    q = rr[1]
                    ok += 1
                if ok >= 8:
                    found = probe
                    break
                probe += 1
            pos = found if found is not None else (nxt_t if nxt_t is not None else len(buf))
            continue
        ins, nxt = r
        seen.setdefault(pos, ins)
        tg.update(t for t in targets_of(ins) if code0 <= t < len(buf))
        pos = nxt
    return [seen[k] for k in sorted(seen)], n


def fmt(ins) -> str:
    pos, op, mask, res, params = ins
    if op is None:
        return f"{pos:06x}: <bad opcode>"
    ps = []
    for t, v in params:
        if t == "var":
            ps.append(f"${v:04x}")
        elif t == 8:
            ps.append(f"{v:g}f")
        else:
            ps.append(f"{v:#x}" if isinstance(v, int) and v > 9 else str(v))
    r = f"${res:04x} = " if res is not None else ""
    return f"{pos:06x}: {r}{NAMES.get(op, f'op{op:03x}')}({', '.join(ps)})"


def main(argv):
    if not argv:
        print(__doc__)
        return
    dt = descs()
    files = load()
    cmd = argv[0]
    if cmd == "list":
        for k, v in sorted(files.items()):
            print(k, len(v))
    elif cmd == "dis":
        name = argv[1] if argv[1].endswith(".bai") else argv[1] + ".bai"
        ins, n = decode_all(files[name], dt)
        labels = struct.unpack_from(f"<{n}I", files[name], 4)
        print(f"; {name}: {n} labels {[hex(x) for x in labels]}")
        prev_end = None
        for i in ins:
            print(fmt(i))
    elif cmd == "grep":
        ops = {int(x, 0) for x in argv[1:]}
        for k in sorted(files):
            ins, _ = decode_all(files[k], dt)
            for i in ins:
                if i[1] in ops:
                    print(f"{k:40s} {fmt(i)}")
    elif cmd == "var":
        vids = {int(x, 0) for x in argv[1:]}
        for k in sorted(files):
            ins, _ = decode_all(files[k], dt)
            for i in ins:
                if i[3] in vids or any(t == "var" and v in vids for t, v in i[4]):
                    print(f"{k:40s} {fmt(i)}")
    elif cmd == "stats":
        tot = 0
        for k in sorted(files):
            ins, _ = decode_all(files[k], dt)
            cov = sum(decode_one(files[k], dt, i[0])[1] - i[0] for i in ins)
            tot += len(ins)
            print(f"{k:40s} size {len(files[k]):6d} ins {len(ins):5d} bytes_decoded {cov:6d}")
        print("total instructions", tot)
    elif cmd == "loops":
        # Per script: backward branches (loops). For each loop body report waits, input reads
        # ($7005 hold, $7006 trigger), counters advanced per execution (op023 ++, op024 --,
        # op025/op026 +=/-= immediate) vs advanced by the frame step ($7012).
        only = set(argv[1:])
        INPUT = {0x7005: "hold", 0x7006: "trg", 0x7007: "rls", 0x7008: "rep"}
        tot = {"loops": 0, "input_loops": 0, "fixed_counter_input_loops": 0}
        for k in sorted(files):
            if only and not any(o in k for o in only):
                continue
            ins, _ = decode_all(files[k], dt)
            by = {i[0]: i for i in ins}
            order = [i[0] for i in ins]
            for i in ins:
                op, params = i[1], i[4]
                t = None
                if op == 0x04 and imm(params, 0) in (0, 2):
                    t = imm(params, 1)
                elif op == 0x03:
                    t = imm(params, 4)
                if t is None or t >= i[0]:
                    continue
                body = [by[p] for p in order if t <= p <= i[0]]
                waits = [b for b in body if b[1] == 0x05]
                inputs = sorted({INPUT[v] for b in body for (tt, v) in b[4] if tt == "var" and v in INPUT})
                fixed = [b for b in body if b[1] in (0x23, 0x24) or
                         (b[1] in (0x25, 0x26) and b[4] and b[4][0][0] != "var")]
                stepc = [b for b in body if b[1] in (0x25, 0x26, 0x16, 0x17, 0x18) and
                         any(tt == "var" and v == 0x7012 for tt, v in b[4])]
                tot["loops"] += 1
                if inputs:
                    tot["input_loops"] += 1
                    if fixed:
                        tot["fixed_counter_input_loops"] += 1
                if inputs or fixed:
                    print(f"{k:34s} loop {t:05x}-{i[0]:05x} waits={[fmt(w).split(': ', 1)[1] for w in waits][:3]} "
                          f"input={inputs} fixed={[fmt(f).split(': ', 1)[1] for f in fixed][:4]} "
                          f"step={len(stepc)}")
        print(tot)
    elif cmd == "opcount":
        from collections import Counter
        c = Counter()
        for k in sorted(files):
            ins, _ = decode_all(files[k], dt)
            c.update(i[1] for i in ins)
        for op, cnt in sorted(c.items()):
            print(f"op{op:03x} {cnt}")
    else:
        print(__doc__)


if __name__ == "__main__":
    main(sys.argv[1:])
