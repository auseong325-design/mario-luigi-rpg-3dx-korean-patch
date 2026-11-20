"""STAR2: BAI.dat fix for 스타&스타 (atk_pc_sp_ml_star.bai, atk_pc_sp_ml_star_easy.bai) — restores the 30fps
throw cycle at 60fps (koikoi_star.md §7/§8).

  star2_baifix.py build [--out DIR]     v3a, default DIR = work/fps60/build/v3a (writes DIR/romfs/BAI/BAI.dat,
                                        DIR/bai_diff.tsv, DIR/bai_manifest.json, DIR/bai_verify.txt)
  star2_baifix.py build --window [--out DIR]   v3b = v3a + demonstration window `$708a >= 51` (0x727A),
                                        default DIR = work/fps60/build/v3b
  star2_baifix.py verify FILE           compare FILE with the source BAI.dat, check the two regions

Source: patch/00040000001CA900/romfs/BAI/BAI.dat = the shipped BTL2 fix (sha256 c681a963…fbb6); read-only.

Why: the throw cycle "hand refilled -> bro throws -> reload thread starts the next star (thread 0x30A4) -> jump +
wait(0x12) -> hand refilled" has two one-frame hand-offs between AI threads. They cost 2 units at 30fps and 1 unit at
60fps, so the cycle is 20 instead of 22 units and the demonstration catches 47 instead of 43 stars (§7).

Change (only inside thread 0x30A4, bytes 0x30CE..0x31DA; every instruction from 0x31DB on keeps its offset):
  1. `$8012 = op025(1f)` (z += 1) is in both bro branches: Mario's copy is dropped, his branch jumps to Luigi's
     copy, which becomes the merge point                                                          -12 bytes
  2. `$1006 = op017($8011, $1007)` recomputes `$8014` (same operands: `$1007` and `$8013` both read the star's y
     in the same frame, nothing runs in between): dropped, `op12f` reads `$8014`                    -12 bytes
  3. `$8013 = op025(30f)` -> `$8013 = op016($8013, 30f)` (the same float add, a + b == b + a)       +2 bytes
  4. `wait(0x12)` -> `wait(0x10)`, `$1005 = op019(4f, $7012)`, `wait($1005)`                        +22 bytes
     30fps ($7012 = 2.0): 8 frames + wait(2) = 1 frame = 9 frames, exactly as wait(0x12);
     60fps ($7012 = 1.0): 16 + 4 = 20 frames (was 18) -> cycle 22 units as at 30fps.
Checks: original instruction text of the region and its neighbours; encoder round trip of every original instruction;
the region keeps its length; no code offset anywhere in the script (decoded type-5 params, label table, and a raw scan
of every 4-byte window) points inside the region except the four internal branches that are rewritten; the new region
decodes to the expected text; the reachable flow (op003/op004 and every type-5 param) covers every new instruction;
outside the region the plain script is byte-identical and its instruction boundaries are unchanged; BG4 entry table,
header and name block equal; only the two star scripts change; a model of op005 gives 9 frames at step 2 for both
the old and the new code and 18 -> 20 frames at step 1.
"""
from __future__ import annotations

import hashlib
import json
import os
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(os.path.dirname(os.path.dirname(HERE)))
sys.path.insert(0, os.path.join(ROOT, "scripts", "fps60"))
sys.path.insert(0, os.path.join(ROOT, "scripts"))
import btl_bai  # noqa: E402
import lib3dx  # noqa: E402

REL = "BAI/BAI.dat"
SRC = os.path.join(ROOT, "patch", "00040000001CA900", "romfs", "BAI", "BAI.dat")
SRC_SHA256 = "c681a963b8428128a2d9133c39911f9f2acf5a53e83dff0a097de8fbe750fbb6"
DEFAULT_OUT = os.path.join(ROOT, "work", "fps60", "build", "v3a")
SCRIPTS = ("atk_pc_sp_ml_star.bai", "atk_pc_sp_ml_star_easy.bai")
R0, R1 = 0x30CE, 0x31DB          # region [R0, R1): re-laid out, same length
THREAD = 0x30A4

ORIG = [  # the original region, both scripts
    (0x30CE, "op003(0, $3000, 65536f, 0, 0x310f)"),
    (0x30E0, "$8010 = op025(17f)"),
    (0x30EC, "$8011 = op025(23f)"),
    (0x30F8, "$8012 = op025(1f)"),
    (0x3104, "op004(2, 0x3133)"),
    (0x310F, "$8010 = op025(-23f)"),
    (0x311B, "$8011 = op025(20f)"),
    (0x3127, "$8012 = op025(1f)"),
    (0x3133, "$8013 = op0d3($7000, 0x100c)"),
    (0x313F, "$8014 = op017($8011, $8013)"),
    (0x314B, "op003(5, $8014, 0f, 0, 0x3172)"),
    (0x315D, "$8013 = op015($8014)"),
    (0x3167, "op004(2, 0x317e)"),
    (0x3172, "$8013 = op015(0f)"),
    (0x317E, "$8013 = op025(30f)"),
    (0x318A, "$1007 = op0d3($7000, 0x100c)"),
    (0x3196, "$1006 = op017($8011, $1007)"),
    (0x31A2, "op12f($7000, 1, $1006, $8013, 18f)"),
    (0x31B3, "op118($7000, 2, 0, $8010, $1007, $8012, 18f)"),
    (0x31C7, "op19c(0x13019d, $7000)"),
    (0x31D3, "wait(0x12)"),
]
CONTEXT = [  # unchanged neighbours the reasoning relies on
    (0x30A4, "op007()"),
    (0x30AA, "$8010 = op0d3($3000, 0x100b)"),
    (0x30B6, "$8011 = op0d3($3000, 0x100c)"),
    (0x30C2, "$8012 = op0d3($3000, 0x100d)"),
    (0x31DB, "op003(1, $3001, 0f, 0, 0x321b)"),
    (0x321B, "op19c(0x13019e, $7000)"),
    (0x3234, "op1b9($3000, 0, $7000)"),
    (0x32F2, "op04e($8010, 0, 0x30a4)"),
]
BRANCHES = {0x30CE: 4, 0x3104: 1, 0x314B: 4, 0x3167: 1}   # internal branch -> index of its target param
NEW_TEXT = [
    "op003(0, $3000, 65536f, 0, 0x3103)",
    "$8010 = op025(17f)",
    "$8011 = op025(23f)",
    "op004(2, 0x311b)",
    "$8010 = op025(-23f)",
    "$8011 = op025(20f)",
    "$8012 = op025(1f)",
    "$8013 = op0d3($7000, 0x100c)",
    "$8014 = op017($8011, $8013)",
    "op003(5, $8014, 0f, 0, 0x3166)",
    "$8013 = op015($8014)",
    "op004(2, 0x3172)",
    "$8013 = op015(0f)",
    "$8013 = op016($8013, 30f)",
    "$1007 = op0d3($7000, 0x100c)",
    "op12f($7000, 1, $8014, $8013, 18f)",
    "op118($7000, 2, 0, $8010, $1007, $8012, 18f)",
    "op19c(0x13019d, $7000)",
    "wait(0x10)",
    "$1005 = op019(4f, $7012)",
    "wait($1005)",
]


def sha(b: bytes) -> str:
    return hashlib.sha256(b).hexdigest()


def text(ins) -> str:
    return btl_bai.fmt(ins).split(": ", 1)[1]


def enc(dt, op: int, res, params) -> bytes:
    """Encode one command: params = [("var", id) | (type, value)] in descriptor order."""
    has_res, types = dt[op]
    if len(params) != len(types):
        raise ValueError(f"op{op:03x}: {len(params)} params, descriptor has {len(types)}")
    mask, body = 0, b""
    for i, ((kind, v), t) in enumerate(zip(params, types)):
        if kind == "var":
            mask |= 1 << i
            body += struct.pack("<H", v)
            continue
        if kind != t:
            raise ValueError(f"op{op:03x} param {i}: type {kind} != descriptor {t}")
        if t == 8:
            body += struct.pack("<f", v)
        elif t == 3:
            body += struct.pack("<b", v)
        elif t in (4, 6):
            body += struct.pack("<h", v)
        elif btl_bai.SIZES[t] == 1:
            body += struct.pack("<B", v)
        elif btl_bai.SIZES[t] == 2:
            body += struct.pack("<H", v)
        else:
            body += struct.pack("<I", v)
    head = struct.pack("<HI", op, mask)
    if has_res:
        head += struct.pack("<H", res)
    elif res is not None:
        raise ValueError(f"op{op:03x} has no result")
    return head + body


def reenc(dt, ins, k=None, target=None) -> bytes:
    pos, op, mask, res, params = ins
    params = list(params)
    if k is not None:
        if params[k][0] == "var":
            raise SystemExit(f"{pos:#x}: branch target is a variable")
        params[k] = (params[k][0], target)
    return enc(dt, op, res, params)


def wait_frames(n: int, step: float) -> int:
    """op005 (battle.md §2.4): wait(n) sets the counter and yields; each later frame subtracts the frame's
    whole ticks and resumes as soon as the counter is <= 0. Returns the frames until the script resumes."""
    if n == 0:
        return 0
    c, f = float(n), 1
    while True:
        c -= step
        if c > 0:
            f += 1
        else:
            return f


def reachable(buf: bytes, dt) -> set[int]:
    """Instruction offsets reachable from the code start and the labels: fall-through (except after end/return/
    unconditional jump), op003/op004 targets and every type-5 (u32) immediate that lands on a decoded instruction
    (thread starts such as op04e) — the same walk as BTL2's btl_baifix.reachable."""
    ins, n = btl_bai.decode_all(buf, dt)
    by = {i[0]: i for i in ins}
    order = sorted(by)
    nxt = {a: b for a, b in zip(order, order[1:])}
    work = [4 + 4 * n] + [x for x in struct.unpack_from(f"<{n}I", buf, 4) if x in by]
    seen: set[int] = set()
    while work:
        p = work.pop()
        if p in seen or p not in by:
            continue
        seen.add(p)
        pos, op, mask, res, params = by[p]
        types = dt[op][1]
        for i, (t, v) in enumerate(params):
            if t != "var" and i < len(types) and types[i] == 5 and v in by:
                work.append(v)
        stop = op in (0x00, 0x01) or (op == 0x04 and btl_bai.imm(params, 0) in (0, 2))
        if not stop and p in nxt:
            work.append(nxt[p])
    return seen


def patch_script(plain: bytes, dt, log: list) -> bytes:
    by, p = {}, R0
    for off, want in ORIG:
        r = btl_bai.decode_one(plain, dt, off)
        if r is None or text(r[0]) != want:
            raise SystemExit(f"{off:#x}: expected `{want}`, found `{text(r[0]) if r else '<bad>'}`")
        if off != p:
            raise SystemExit(f"{off:#x}: region not contiguous (expected {p:#x})")
        if reenc(dt, r[0]) != plain[off:r[1]]:
            raise SystemExit(f"{off:#x}: encoder does not round-trip the original bytes")
        by[off] = r[0]
        p = r[1]
    if p != R1:
        raise SystemExit(f"region ends at {p:#x}, expected {R1:#x}")
    for off, want in CONTEXT:
        r = btl_bai.decode_one(plain, dt, off)
        if r is None or text(r[0]) != want:
            raise SystemExit(f"context {off:#x}: expected `{want}`, found `{text(r[0]) if r else '<bad>'}`")
    reach = reachable(plain, dt)
    if THREAD not in reach or not all(off in reach for off, _ in ORIG):
        raise SystemExit("the original region is not on the reachable flow")
    # 1) decoded code offsets (type-5 params, labels) into the interior: only the region's own branches
    ins, n = btl_bai.decode_all(plain, dt)
    refs = [("label", None, x) for x in struct.unpack_from(f"<{n}I", plain, 4)]
    for i in ins:
        pos, op, mask, res, params = i
        types = dt[op][1]
        refs += [("param", pos, v) for k, (t, v) in enumerate(params)
                 if t != "var" and k < len(types) and types[k] == 5]
    bad = [(k, at, hex(v)) for k, at, v in refs if R0 < v < R1 and not (k == "param" and at in BRANCHES)]
    if bad:
        raise SystemExit(f"code offsets into the region from outside: {bad}")
    # 2) raw scan: any 4-byte window equal to an interior instruction offset, except the branch target fields
    inner = {off for off, _ in ORIG if off != R0}
    allowed = set()
    for off, k in BRANCHES.items():
        pos, op, mask, res, params = by[off]
        q = off + 6 + (2 if dt[op][0] else 0)
        for j in range(k):
            q += 2 if params[j][0] == "var" else btl_bai.SIZES[params[j][0]]
        if struct.unpack_from("<I", plain, q)[0] != params[k][1]:
            raise SystemExit(f"{off:#x}: target field position wrong")
        allowed.add(q)
    hits = [(i, struct.unpack_from("<I", plain, i)[0]) for i in range(len(plain) - 3)
            if struct.unpack_from("<I", plain, i)[0] in inner]
    stray = [(hex(i), hex(v)) for i, v in hits if i not in allowed]
    log.append(f"  raw words equal to an interior offset: {[(hex(i), hex(v)) for i, v in hits]}; "
               f"allowed (branch target fields): {sorted(hex(a) for a in allowed)}")
    if stray:
        raise SystemExit(f"raw words equal to interior offsets outside the region's branches: {stray}")

    # new layout
    def piece(tag, labels):
        if tag == "br0":
            return reenc(dt, by[0x30CE], 4, labels.get("L_luigi", 0))
        if tag == "br1":
            return reenc(dt, by[0x3104], 1, labels.get("L_merge", 0))
        if tag == "br2":
            return reenc(dt, by[0x314B], 4, labels.get("L_neg", 0))
        if tag == "br3":
            return reenc(dt, by[0x3167], 1, labels.get("L_h", 0))
        if tag == "L_h":       # $8013 = op016($8013, 30f)
            o = by[0x317E]
            if o[4] != [(8, 30.0)]:
                raise SystemExit("0x317e operand")
            return enc(dt, 0x16, 0x8013, [("var", 0x8013), (8, 30.0)])
        if tag == "jmp":       # op12f with $8014 instead of $1006
            pos, op, mask, res, params = by[0x31A2]
            params = list(params)
            if params[2] != ("var", 0x1006):
                raise SystemExit("op12f param 2 is not $1006")
            params[2] = ("var", 0x8014)
            return enc(dt, op, res, params)
        if tag == "wait16":
            return enc(dt, 0x05, None, [(1, 16)])
        if tag == "div":       # $1005 = 4 / $7012
            return enc(dt, 0x19, 0x1005, [(8, 4.0), ("var", 0x7012)])
        if tag == "waitv":
            return enc(dt, 0x05, None, [("var", 0x1005)])
        return reenc(dt, by[tag])

    seq = ["br0", 0x30E0, 0x30EC, "br1", ("L_luigi", 0x310F), 0x311B, ("L_merge", 0x3127), 0x3133, 0x313F,
           "br2", 0x315D, "br3", ("L_neg", 0x3172), ("L_h", "L_h"), 0x318A, "jmp", 0x31B3, 0x31C7,
           "wait16", "div", "waitv"]

    def lay(labels):
        out, offs, q = [], {}, R0
        for item in seq:
            if isinstance(item, tuple):
                offs[item[0]] = q
                b = piece(item[1], labels)
            else:
                b = piece(item, labels)
            out.append((q, b))
            q += len(b)
        return out, offs, q

    _, labels, _ = lay({})
    out, labels2, end = lay(labels)
    if labels2 != labels:
        raise SystemExit("label offsets not stable")
    if end != R1:
        raise SystemExit(f"new region ends at {end:#x}, must end at {R1:#x} (length {end - R0} vs {R1 - R0})")
    patched = plain[:R0] + b"".join(b for _, b in out) + plain[R1:]
    if len(patched) != len(plain) or patched[:R0] != plain[:R0] or patched[R1:] != plain[R1:]:
        raise SystemExit("bytes changed outside the region")
    got, q = [], R0
    while q < R1:
        r = btl_bai.decode_one(patched, dt, q)
        if r is None:
            raise SystemExit(f"new region does not decode at {q:#x}")
        got.append(text(r[0]))
        q = r[1]
    if q != R1 or got != NEW_TEXT:
        raise SystemExit("new region text differs:\n" + "\n".join(f"  {a!r} vs {b!r}" for a, b in zip(got, NEW_TEXT)))
    reach2 = reachable(patched, dt)
    missing = [hex(o) for o, _ in out if o not in reach2] + ([] if R1 in reach2 else [hex(R1)])
    if missing:
        raise SystemExit(f"new instructions not reachable: {missing}")
    a, _ = btl_bai.decode_all(plain, dt)
    b, _ = btl_bai.decode_all(patched, dt)
    if [i[0] for i in a if not R0 <= i[0] < R1] != [i[0] for i in b if not R0 <= i[0] < R1]:
        raise SystemExit("instruction boundaries outside the region changed")
    lost = sorted(reach - {o for o, _ in ORIG} - reach2)
    if lost:
        raise SystemExit(f"instructions outside the region lost reachability: {[hex(x) for x in lost[:10]]}")
    log.append("  new region:")
    for (o, bts), t in zip(out, NEW_TEXT):
        log.append(f"    {o:06x}: {bts.hex():48s} {t}")
    return patched


def compare(src: bytes, new: bytes, window: bool = False) -> list[str]:
    # op003 layout: u16 op, u32 mask, u8 cmp, u16 var, f32 (WIN+9..WIN+12), u8 expect, u32 target
    ranges = [(R0, R1)] + ([(WIN + 9, WIN + 13)] if window else [])
    log = []
    _a, a = lib3dx.read_bg4(src)
    _b, b = lib3dx.read_bg4(new)
    if [(e.name, e.compressed, e.size_flag, e.name_hash) for e in a] != \
            [(e.name, e.compressed, e.size_flag, e.name_hash) for e in b]:
        raise SystemExit("entry table differs")
    if src[:16] != new[:16] or src[16 + 14 * len(a):struct.unpack_from("<I", src, 8)[0]] != \
            new[16 + 14 * len(b):struct.unpack_from("<I", new, 8)[0]]:
        raise SystemExit("BG4 header or name block differs")
    diffs = []
    for ea, eb in zip(a, b):
        pa, pb = lib3dx.bg4_plain(ea), lib3dx.bg4_plain(eb)
        if pa == pb:
            if ea.data != eb.data:
                raise SystemExit(f"{ea.name}: stored bytes changed although the plain data did not")
            continue
        if len(pa) != len(pb):
            raise SystemExit(f"{ea.name}: plain size changed")
        diffs.append((ea.name, [k for k in range(len(pa)) if pa[k] != pb[k]]))
    if sorted(d[0] for d in diffs) != sorted(SCRIPTS):
        raise SystemExit(f"changed scripts {sorted(d[0] for d in diffs)} != {sorted(SCRIPTS)}")
    for name, bd in diffs:
        outside = [k for k in bd if not any(lo <= k < hi for lo, hi in ranges)]
        if outside:
            raise SystemExit(f"{name}: byte change outside {[(hex(a), hex(b)) for a, b in ranges]}: {outside[:8]}")
        log.append(f"compare: {name}: {len(bd)} plain bytes differ, all inside "
                   f"{', '.join(f'{lo:#x}..{hi - 1:#x}' for lo, hi in ranges)}")
    log.append(f"compare: BG4 entry table, header and name block equal; the other {len(a) - len(diffs)} entries "
               "are stored byte-identical")
    return log


WIN = 0x727A   # demonstration throw window `op003(5, $708a, 50f, 0, 0x7484)` (auto-play branch only)
WIN_OLD, WIN_NEW = "op003(5, $708a, 50f, 0, 0x7484)", "op003(5, $708a, 51f, 0, 0x7484)"


def patch_window(plain: bytes, dt, log: list) -> bytes:
    """`$708a >= 50` -> `$708a >= 51` (v3b). Exact at 30fps while `$708a` is odd there: every write to it in the
    script must be `$708a = op015(<odd integer>)` or `$708a = op026($7012)` (step 2.0 at 30fps)."""
    r = btl_bai.decode_one(plain, dt, WIN)
    if r is None or text(r[0]) != WIN_OLD:
        raise SystemExit(f"{WIN:#x}: expected `{WIN_OLD}`, found `{text(r[0]) if r else '<bad>'}`")
    ins, _ = btl_bai.decode_all(plain, dt)
    writes = [i for i in ins if i[3] == 0x708A]
    for i in writes:
        t = text(i)
        ok = (i[1] == 0x15 and i[4][0][0] == 8 and float(i[4][0][1]).is_integer() and int(i[4][0][1]) % 2 == 1) or \
             t == "$708a = op026($7012)"
        if not ok:
            raise SystemExit(f"write to $708a breaks the odd-parity argument: {btl_bai.fmt(i)}")
    reads = [btl_bai.fmt(i) for i in ins if any(t == "var" and v == 0x708A for t, v in i[4])]
    if reads != [btl_bai.fmt(r[0])]:
        raise SystemExit(f"$708a is read elsewhere: {reads}")
    # the window test sits in the auto-play branch: 0x722C jumps to it only when $7082 != 0
    g = btl_bai.decode_one(plain, dt, 0x722C)
    if text(g[0]) != "op003(0, $7082, 0f, 0, 0x727a)":
        raise SystemExit("0x722c is not the auto-play branch")
    pos, op, mask, res, params = r[0]
    params = list(params)
    params[2] = (8, 51.0)
    nb = enc(dt, op, res, params)
    if len(nb) != r[1] - WIN:
        raise SystemExit("window instruction length changed")
    new = plain[:WIN] + nb + plain[r[1]:]
    if text(btl_bai.decode_one(new, dt, WIN)[0]) != WIN_NEW:
        raise SystemExit("window patch does not decode")
    log.append(f"  window {WIN:#06x}: {plain[WIN:r[1]].hex()} -> {nb.hex()}  {WIN_NEW}; writes to $708a: "
               f"{[text(i) for i in writes]}")
    return new


def build(out_dir: str, window: bool = False) -> dict:
    dt = btl_bai.descs()
    data = open(SRC, "rb").read()
    if sha(data) != SRC_SHA256:
        raise SystemExit(f"source {SRC} sha256 {sha(data)} != shipped BTL2 fix {SRC_SHA256}")
    if lib3dx.rebuild_bg4(data, {}) != data:
        raise SystemExit("zero-change BG4 rebuild is not byte-identical")
    _v, es = lib3dx.read_bg4(data)
    slots = {e.name: n for n, e in enumerate(es)}
    log = [f"source {os.path.relpath(SRC, ROOT)} sha256 {sha(data)}; zero-change BG4 rebuild byte-identical"]
    old30 = wait_frames(18, 2.0)
    new30 = wait_frames(16, 2.0) + wait_frames(int(4.0 / 2.0), 2.0)
    old60 = wait_frames(18, 1.0)
    new60 = wait_frames(16, 1.0) + wait_frames(int(4.0 / 1.0), 1.0)
    log.append(f"op005 model: step 2.0 (30fps) old {old30} frames, new {new30}; step 1.0 (60fps) old {old60}, new {new60}")
    if old30 != new30 or (old60, new60) != (18, 20):
        raise SystemExit("wait model check failed")
    changed, rows = {}, []
    for name in SCRIPTS:
        n = slots[name]
        plain = lib3dx.bg4_plain(es[n])
        log.append(f"{name}: plain {len(plain)} bytes sha256 {sha(plain)}")
        new = patch_script(plain, dt, log)
        if window:
            new = patch_window(new, dt, log)
        changed[n] = new
        rows.append({"script": name, "region": f"{R0:#06x}-{R1:#06x}", "old_bytes": plain[R0:R1].hex(),
                     "new_bytes": new[R0:R1].hex(),
                     "window": (f"{WIN:#06x} {plain[WIN:WIN + 0x12].hex()} -> {new[WIN:WIN + 0x12].hex()}"
                                if window else "-"),
                     "plain_sha256_old": sha(plain), "plain_sha256_new": sha(new)})
    if changed[slots[SCRIPTS[0]]][R0:R1] != changed[slots[SCRIPTS[1]]][R0:R1]:
        raise SystemExit("the two star scripts got different regions")
    out = lib3dx.rebuild_bg4(data, changed)
    log.extend(compare(data, out, window))
    dst = os.path.join(out_dir, "romfs", *REL.split("/"))
    os.makedirs(os.path.dirname(dst), exist_ok=True)
    with open(dst, "wb") as fh:
        fh.write(out)
    with open(os.path.join(out_dir, "bai_diff.tsv"), "w", encoding="utf-8", newline="\n") as fh:
        cols = list(rows[0])
        fh.write("\t".join(cols) + "\n")
        for r in rows:
            fh.write("\t".join(r[c] for c in cols) + "\n")
    man = {"tool": "work/fps60/star/star2_baifix.py", "source": os.path.relpath(SRC, ROOT).replace("\\", "/"),
           "source_sha256": sha(data), "output": os.path.relpath(dst, ROOT).replace("\\", "/"),
           "output_size": len(out), "output_sha256": sha(out), "scripts_changed": list(SCRIPTS),
           "region": [hex(R0), hex(R1)], "demo_window": f"{WIN:#x} {WIN_NEW}" if window else None,
           "install": "LayeredFS romfs/BAI/BAI.dat (replaces the shipped BTL2 file)"}
    with open(os.path.join(out_dir, "bai_manifest.json"), "w", encoding="utf-8", newline="\n") as fh:
        json.dump(man, fh, indent=2)
    log.append(f"output {man['output']} {len(out)} bytes sha256 {man['output_sha256']}")
    log.append("RESULT: ALL BAI CHECKS PASSED")
    with open(os.path.join(out_dir, "bai_verify.txt"), "w", encoding="utf-8", newline="\n") as fh:
        fh.write("\n".join(log) + "\n")
    print("\n".join(log))
    return man


def verify(path: str) -> None:
    dt = btl_bai.descs()
    src = open(SRC, "rb").read()
    new = open(path, "rb").read()
    _v, es = lib3dx.read_bg4(new)
    window = False
    for e in es:
        if e.name in SCRIPTS:
            pl = lib3dx.bg4_plain(e)
            got, p = [], R0
            while p < R1:
                r = btl_bai.decode_one(pl, dt, p)
                got.append(text(r[0]))
                p = r[1]
            w = text(btl_bai.decode_one(pl, dt, WIN)[0])
            window = window or w == WIN_NEW
            print(f"{e.name}: region text {'OK' if got == NEW_TEXT and p == R1 else 'DIFFERS'}; {WIN:#x}: {w}")
    for line in compare(src, new, window):
        print(line)
    print(f"source sha256 {sha(src)}\nfile   sha256 {sha(new)}")


def main(argv):
    if not argv:
        print(__doc__)
    elif argv[0] == "build":
        window = "--window" in argv
        default = os.path.join(ROOT, "work", "fps60", "build", "v3b") if window else DEFAULT_OUT
        build(argv[argv.index("--out") + 1] if "--out" in argv else default, window)
    elif argv[0] == "verify":
        verify(argv[1])
    else:
        print(__doc__)


if __name__ == "__main__":
    main(sys.argv[1:])
