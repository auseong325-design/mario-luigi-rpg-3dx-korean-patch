"""CRD worker: explore/decode 3DX field event scripts (FEvent/FEvent.dat) for the staff roll.

    python scripts/fps60/crd_fevent.py list [substr]          # BG4 entries of FEvent.dat (v1.2: romf2)
    python scripts/fps60/crd_fevent.py finddesc               # locate the field VM's argument-descriptor table
    python scripts/fps60/crd_fevent.py grepop 0x280 [...]     # every entry holding the given opcode(s)

Read-only. Writes nothing outside stdout.
"""
from __future__ import annotations

import os
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(os.path.dirname(HERE))
sys.path.insert(0, HERE)
sys.path.insert(0, os.path.join(ROOT, "scripts"))
import lib3dx  # noqa: E402

CODE = os.path.join(ROOT, "work", "fps60", "bin", "3dx_v12.code.bin")
BASE = 0x100000


def fevent_bytes() -> bytes:
    return open(lib3dx.romfs_path("FEvent/FEvent.dat"), "rb").read()


def cmd_list(argv):
    data = fevent_bytes()
    print("header", data[:16].hex(" "))
    try:
        ver, es = lib3dx.read_bg4(data)
    except ValueError as exc:
        print("not BG4:", exc)
        return
    print("version", ver, "entries", len(es))
    sub = argv[0] if argv else None
    for i, e in enumerate(es):
        if sub and sub not in e.name:
            continue
        print(f"{i:5d} {e.name:40s} comp={int(e.compressed)} inv={int(e.size_flag)} size={len(e.data)}")


def cmd_finddesc(argv):
    code = open(CODE, "rb").read()
    battle = open(os.path.join(ROOT, "work", "fps60", "link", "3dx_v12", "Battle.bin"), "rb").read()
    boff = 0x1105F730 - 0x11000000
    base_desc = battle[boff:boff + 0x4E * 16]
    print("battle base desc first entries:", base_desc[:48].hex(" "))
    hits = []
    pos = code.find(base_desc[:0x40])
    while pos >= 0:
        hits.append(pos)
        pos = code.find(base_desc[:0x40], pos + 1)
    for h in hits:
        same = code[h:h + 0x4E * 16] == base_desc
        print(f"static hit at 0x{BASE + h:08x} full-base-match={same}")
    if not hits:
        # weaker: entry for op 0 and op 5 only
        print("no exact hit for the first 4 entries")


def entries() -> dict[str, bytes]:
    _v, es = lib3dx.read_bg4(fevent_bytes())
    return {e.name: lib3dx.bg4_plain(e) for e in es if not e.size_flag}


# ------------------------------------------------------------------ field VM decoder
# Field argument-descriptor table (16 bytes per opcode, 0x4E base + 567 field ops), found by
# `finddesc`: it ends exactly where GlobalEvent::_CmdFuncTbl (0x3A30C4) starts.
FDESC = 0x3A0874
FNOPS = 0x4E + 567
SIZES = {0: 1, 1: 2, 2: 4, 3: 1, 4: 2, 5: 4, 6: 2, 7: 4, 8: 4}
NAMES = {0x00: "end", 0x01: "return", 0x03: "jmpif", 0x04: "jump", 0x05: "wait", 0x280: "staffroll"}

_CODE = None


def code_bin() -> bytes:
    global _CODE
    if _CODE is None:
        _CODE = open(CODE, "rb").read()
    return _CODE


def fdescs():
    c = code_bin()
    out = []
    for op in range(FNOPS):
        b = c[FDESC - BASE + 16 * op: FDESC - BASE + 16 * op + 16]
        n = b[0] & 0x7F
        types = [(b[1 + i // 2] >> (4 * (i & 1))) & 0xF for i in range(n)]
        out.append((bool(b[0] & 0x80), types))
    return out


def decode_one(buf: bytes, dt, pos: int):
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


def fmt(ins) -> str:
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


def fev_layout(b: bytes):
    """.fev: header u32 at +0x14 = offset of the script section S. S: u32 N, N u32 (labels/vars?),
    then script entry offsets (relative to S) up to the first code byte. (FUN_002ebf.. reads
    script k at S + S_u32[N + 1 + k].)"""
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


def cmd_dis(argv):
    name = argv[0]
    lo = int(argv[1], 0) if len(argv) > 1 else 0
    hi = int(argv[2], 0) if len(argv) > 2 else 1 << 30
    b = entries()[name]
    dt = fdescs()
    sec, n, offs = fev_layout(b)
    print(f"; {name}: {len(b)} bytes, script section at {sec:#x}, N={n}, {len(offs)} script offsets")
    print(";   scripts:", ", ".join(f"#{k}={sec + o:#x}" for k, o in enumerate(offs)))
    starts = {sec + o: k for k, o in enumerate(offs) if o}
    pos = min(starts) if starts else sec + 4 + 4 * n + 4 * len(offs)
    end = len(b)
    while pos < end:
        show = lo <= pos <= hi
        if pos in starts and show:
            print(f"; ---- script #{starts[pos]} @ {pos:#x} (rel {pos - sec:#x})")
        r = decode_one(b, dt, pos)
        if r is None:
            if show:
                print(f"{pos:05x}: <undecodable> {b[pos:pos + 8].hex(' ')}")
            # resync at the next script start
            nxt = [s for s in starts if s > pos]
            if not nxt:
                break
            pos = min(nxt)
            continue
        ins, nxt = r
        if show:
            print(fmt(ins))
        pos = nxt


ROOMTBL = 0x3F5674   # char* table indexed by room id (fld::MainBase::ProcessLoadEventData::vfunc_0x8)


def cstr(addr: int) -> str:
    c = code_bin()
    o = addr - BASE
    e = c.find(b"\0", o)
    return c[o:e].decode("ascii", "replace")


def rooms() -> list[str]:
    c = code_bin()
    out = []
    i = 0
    while True:
        p = struct.unpack_from("<I", c, ROOMTBL - BASE + 4 * i)[0]
        if not (0x389000 <= p < 0x3EF000):
            break
        out.append(cstr(p))
        i += 1
    return out


def cmd_rooms(argv):
    rs = rooms()
    print(f"; {len(rs)} rooms in the table at {ROOMTBL:#x}")
    for a in argv:
        if a.startswith("0x") or a.isdigit():
            i = int(a, 0)
            print(f"{i:#05x} {i:4d} {rs[i] if i < len(rs) else '?'}")
        else:
            for i, n in enumerate(rs):
                if a in n:
                    print(f"{i:#05x} {i:4d} {n}")


def iter_script_ins(b: bytes, dt):
    """Linear decode from every script start until an undecodable word (or next script start)."""
    try:
        sec, n, offs = fev_layout(b)
    except struct.error:
        return
    starts = sorted({sec + o for o in offs if o and sec + o < len(b)})
    seen = set()
    for s in starts:
        pos = s
        while pos < len(b) and pos not in seen:
            r = decode_one(b, dt, pos)
            if r is None:
                break
            seen.add(pos)
            ins, nxt = r
            yield ins
            if ins[1] in (0x00, 0x01):   # end / return: next script follows
                nxt_starts = [t for t in starts if t > pos]
                if nxt_starts and nxt < min(nxt_starts):
                    pos = nxt  # code may continue (labels after return)
                    continue
            pos = nxt


def cmd_grepop(argv):
    ops = set()
    filt = None
    for a in argv:
        if a.startswith("p0="):
            filt = int(a[3:], 0)
        else:
            ops.add(int(a, 0))
    dt = fdescs()
    for name, b in sorted(entries().items()):
        if not name.endswith(".fev") or len(b) < 0x20:
            continue
        for ins in iter_script_ins(b, dt):
            if ins[1] in ops:
                if filt is not None and (not ins[4] or ins[4][0][1] != filt):
                    continue
                print(f"{name:40s} {fmt(ins)}")


def cmd_desc(argv):
    dt = fdescs()
    c = code_bin()
    for a in argv:
        op = int(a, 0)
        if op >= 0x4E:
            fn, adj = struct.unpack_from("<II", c, 0x3A30C4 - BASE + (op - 0x4E) * 8)
            h = f"_CmdFuncTbl handler {fn:#x} adj {adj:#x}"
        else:
            fn, adj = struct.unpack_from("<II", c, 0x389918 - BASE + op * 8)
            h = f"base handler {fn:#x} adj {adj:#x}"
        print(f"op{op:03x}: result={dt[op][0]} types={dt[op][1]}  {h}")


def hexdump(b: bytes, start: int = 0, n: int | None = None):
    end = len(b) if n is None else min(len(b), start + n)
    for off in range(start, end, 16):
        chunk = b[off:min(off + 16, end)]
        print(f"{off:06x}  {chunk.hex(' '):48s}  {''.join(chr(c) if 32 <= c < 127 else '.' for c in chunk)}")


def cmd_hex(argv):
    name = argv[0]
    start = int(argv[1], 0) if len(argv) > 1 else 0
    n = int(argv[2], 0) if len(argv) > 2 else None
    b = entries()[name]
    print(f"; {name}: {len(b)} bytes")
    hexdump(b, start, n)


def main(argv):
    if not argv:
        print(__doc__)
        return
    cmd = argv[0]
    if cmd == "list":
        cmd_list(argv[1:])
    elif cmd == "finddesc":
        cmd_finddesc(argv[1:])
    elif cmd == "hex":
        cmd_hex(argv[1:])
    elif cmd == "dis":
        cmd_dis(argv[1:])
    elif cmd == "desc":
        cmd_desc(argv[1:])
    elif cmd == "rooms":
        cmd_rooms(argv[1:])
    elif cmd == "grepop":
        cmd_grepop(argv[1:])
    else:
        print(__doc__)


if __name__ == "__main__":
    main(sys.argv[1:])
