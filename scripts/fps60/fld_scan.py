"""FLD workstream: scan field-side functions of 3dx_v12 for frame-based (non-step) timing patterns.

    python scripts/fps60/fld_scan.py cmdtbl                  # dump the field event command table (0x3A30C4)
    python scripts/fps60/fld_scan.py set [--depth N]         # list the field function set (fld:: + callees + cmds)
    python scripts/fps60/fld_scan.py scan [--depth N] [--all] > out.txt   # pattern scan over the field set

Field set = every static function named fld::*, every Field.cro function, the field event command handlers,
the field per-frame updaters (0x20D228/0x20DCB0/0x20E02C), plus their direct callees up to --depth (default 3),
minus library code (nn::, nw::, ad::fw::, Mem*, Grp::, primitives that take a step argument ...).

Patterns (per function, on the Ghidra C dump):
  INC   member integer counter += / -= small literal         *(T *)(X + 0xNN) = *(T *)(X + 0xNN) + 1;
  FINC  member float += / -= float literal                    *(float *)(X + 0xNN) = *(float *)(X + 0xNN) + 2.0;
  LERP  member exponential approach by a literal factor      m = m + (t - m) * 0.1  (frame-rate dependent)
  STEP  the function reads a step (field step +0x1a4c, party step +0x100, or has a float parameter)
A function with INC/FINC/LERP and no STEP evidence is the primary suspect list.
"""
from __future__ import annotations

import os
import re
import struct
import sys
from collections import deque

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import fld_dc  # noqa: E402

ROOT = fld_dc.ROOT
BIN = os.path.join(ROOT, "work", "fps60", "bin", "3dx_v12.code.bin")
BASE = 0x100000
CMDTBL = 0x3A30C4
NCMD = 567

LIB = re.compile(
    r"^(nn::|nw::|ad::fw::|ad::dfx|ad::pctx|__|->|operator|Mem|std::|Grp::|nngx|MoveVBase::|MoveC::|MoveFBase::|"
    r"Frm::|CellAnime::|LytAnim::|Message|CmdList|VramTransfer|ThreadSafeVramTransfer|FrameBuf|CtrJob|JobMan|Job::|"
    r"Ctr|DisplayBufSet|RenderDrawSys|VramAlc|SndSys|GlobalEvent::|Prim::|DataPc|GameWork|Backup|MSave|MemAlc)")


def u32(data, a):
    o = a - BASE
    return struct.unpack_from("<I", data, o)[0]


def cmd_handlers(data):
    out = []
    for i in range(NCMD):
        p = u32(data, CMDTBL + i * 8)
        adj = u32(data, CMDTBL + i * 8 + 4)
        out.append((i, p, adj))
    return out


def field_set(dc, depth=3, with_cmds=True):
    data = open(BIN, "rb").read()
    roots = []
    for d in dc.rows:
        if d["module"] == "Field" or (d["module"] == "static" and d["name"].startswith("fld::")):
            roots.append(d)
    for a in (0x20D228, 0x20DCB0, 0x20E02C):
        r = dc.row(a)
        if r:
            roots.append(r)
    cmds = {}
    if with_cmds:
        for i, p, adj in cmd_handlers(data):
            if adj & 1:
                continue
            r = dc.row(p)
            if r:
                roots.append(r)
                cmds.setdefault(r["a"], []).append(i + 0x4E)
    seen = {}
    q = deque()
    for r in roots:
        if r["a"] not in seen:
            seen[r["a"]] = 0
            q.append((r, 0))
    while q:
        d, k = q.popleft()
        if k >= depth:
            continue
        for c in dc.callees(d):
            if c["module"] not in ("static", "Field"):
                continue
            if LIB.search(c["name"]):
                continue
            if c["a"] not in seen:
                seen[c["a"]] = k + 1
                q.append((c, k + 1))
    return seen, cmds


T = r"(?:u?int|short|ushort|char|byte|undefined[124]|uint|int)"
INC_RX = re.compile(r"(\*\(" + T + r" \*\)\(([\w\[\]\.]+) \+ (0x[0-9a-f]+)\)) = (?:\(\w+\))?\1 \+ (-?(?:0x)?[0-9a-f]+);")
INC2_RX = re.compile(r"(\w+)\[(0x[0-9a-f]+)\] = (?:\(\w+\))?\1\[\2\] \+ (-?(?:0x)?[0-9a-f]+);")
FINC_RX = re.compile(r"(\*\(float \*\)\(([\w\[\]\.]+) \+ (0x[0-9a-f]+)\)) = \1 ([+-]) (-?[0-9]+\.[0-9]+(?:e[+-]?\d+)?);")
LERP_RX = re.compile(r"(\*\(float \*\)\(([\w\[\]\.]+) \+ (0x[0-9a-f]+)\)) = \1 \+ \(.*- \1\) \* ([0-9.]+(?:e-?\d+)?);")
STEP_RX = re.compile(r"0x1a4c\)|\+ 0x100\)|float param_|\(float\)param_")


def scan_body(b):
    lines = b.splitlines()
    hits = []
    for i, ln in enumerate(lines):
        m = INC_RX.search(ln)
        if m:
            v = int(m.group(4), 0)
            if abs(v) <= 4:
                hits.append(("INC", i, ln.strip()))
            continue
        m = INC2_RX.search(ln)
        if m:
            v = int(m.group(3), 0)
            if abs(v) <= 4:
                hits.append(("INC", i, ln.strip()))
            continue
        m = FINC_RX.search(ln)
        if m:
            hits.append(("FINC", i, ln.strip()))
            continue
        m = LERP_RX.search(ln)
        if m:
            hits.append(("LERP", i, ln.strip()))
    step = bool(STEP_RX.search(b))
    return hits, step


def main(argv):
    if not argv:
        print(__doc__)
        return
    dc = fld_dc.DC()
    cmd = argv[0]
    depth = int(argv[argv.index("--depth") + 1]) if "--depth" in argv else 3
    if cmd == "cmdtbl":
        data = open(BIN, "rb").read()
        for i, p, adj in cmd_handlers(data):
            r = dc.row(p) if not (adj & 1) else None
            print(f"{i + 0x4E:#05x} {p:#010x} adj={adj:#x} {r['name'] if r else ''}")
    elif cmd == "set":
        seen, cmds = field_set(dc, depth)
        for a in sorted(seen):
            r = dc.row(a)
            print(f"{a:#010x} d{seen[a]} {r['name']}" + (f"  cmd {','.join(hex(c) for c in cmds[a])}" if a in cmds else ""))
        print(f"; {len(seen)} functions")
    elif cmd == "scan":
        seen, cmds = field_set(dc, depth)
        show_all = "--all" in argv
        n = 0
        for a in sorted(seen):
            r = dc.row(a)
            b = dc.body(r)
            hits, step = scan_body(b)
            if not hits:
                continue
            if step and not show_all:
                kinds = {h[0] for h in hits}
                if kinds == {"INC"}:
                    pass
            n += 1
            tag = "STEP" if step else "nostep"
            cm = f" cmd {','.join(hex(c) for c in cmds[a])}" if a in cmds else ""
            print(f"# {a:#010x} {r['name']} [{tag}] d{seen[a]} size {r['size']}{cm}")
            for k, i, ln in hits[:12]:
                print(f"    {k:4s} {i:4d}: {ln}")
        print(f"; {n} functions with hits, field set {len(seen)}")
    else:
        print(__doc__)


if __name__ == "__main__":
    main(sys.argv[1:])
