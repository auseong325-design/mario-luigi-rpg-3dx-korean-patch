"""BTL2: rebuild romfs BAI/BAI.dat (battle AI scripts) with exact 60fps timing fixes.

    python scripts/fps60/btl_baifix.py identity                  # zero-change rebuild must be byte-identical
    python scripts/fps60/btl_baifix.py build [--groups hold,step2,orbit] [--out DIR] [--codec-all]
    python scripts/fps60/btl_baifix.py verify FILE               # compare FILE with the source, list changes

Source (BRIEF2 R2): patch/00040000001CA900/romfs/BAI/BAI.dat if it exists, else lib3dx.romfs_path("BAI/BAI.dat")
(romf2 has no BAI/, so this is romfs/BAI/BAI.dat of v1.0, which v1.2 keeps). Read-only on every input.
Output (default DIR = work/fps60/build/bai): DIR/romfs/BAI/BAI.dat, DIR/diff.tsv, DIR/manifest.json.

Transforms (battle.md 2.4; both are the same length, so no offset in any script moves):
  add2   `$v = op025(2f)`  -> `$v = op016($v, $7012)`   v += 2 per frame  ->  v += step (2.0 at 30fps, 1.0 at 60fps)
  sub2   `$v = op026(2f)`  -> `$v = op017($v, $7012)`   v -= 2 per frame  ->  v -= step
  wait2  `wait(1)`         -> `wait(2)`                 30fps: still one frame; 60fps: the loop runs every 2nd frame
Every site is checked against the expected original instruction text and must be on the decoded control flow.
"""
from __future__ import annotations

import hashlib
import json
import os
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(os.path.dirname(HERE))
sys.path.insert(0, HERE)
sys.path.insert(0, os.path.join(ROOT, "scripts"))
import btl_bai  # noqa: E402
import lib3dx  # noqa: E402

REL = "BAI/BAI.dat"
PATCH_ROMFS = os.path.join(ROOT, "patch", "00040000001CA900", "romfs")
DEFAULT_OUT = os.path.join(ROOT, "work", "fps60", "build", "bai")
STEP_VAR = 0x7012

# (script, offset, transform, group, expected original instruction, reason)
FIXES = [
    # hold-button grace: while the button is not held, +2 per frame; >= 16 ends the hold (267 ms at 30fps)
    ("atk_dstar_4", 0x3454, "add2", "hold", "$8012 = op025(2f)", "hold grace +2/frame, ends at >=16"),
    ("atk_dstar_x_4", 0x3454, "add2", "hold", "$8012 = op025(2f)", "hold grace +2/frame, ends at >=16"),
    ("atk_koopa2_2", 0x2B78, "add2", "hold", "$8012 = op025(2f)", "hold grace +2/frame, ends at >=16"),
    ("atk_koopax_2", 0x2742, "add2", "hold", "$8012 = op025(2f)", "hold grace +2/frame, ends at >=16"),
    ("atk_dgeraco_5", 0x298E, "add2", "hold", "$8012 = op025(2f)", "hold grace +2/frame, ends at >=16"),
    # other per-frame timers written in 60 Hz units with a hard-coded 30fps step of 2
    ("atk_geraco2_4", 0x2560, "add2", "step2", "$8018 = op025(2f)", "wait loop: +2/frame until >= $707e"),
    ("atk_koopax_5", 0x4B82, "add2", "step2", "$8011 = op025(2f)", "timeout loop: +2/frame until >= $8001"),
    ("atk_geraco2_3", 0x2E66, "add2", "step2", "$8010 = op025(2f)", "interpolation $8013=$8010/50 per frame"),
    ("atk_geraco2_3", 0x2EC9, "add2", "step2", "$8010 = op025(2f)", "idle animation toggle every 80 units"),
    ("atk_dgeraco_4", 0x22D8, "add2", "step2", "$707e = op025(2f)", "orbit radius ramp +2/frame to 192"),
    # orbit loops: angle += c degrees per frame (no trigger read, no step-scaled update, single wait(1))
    ("atk_dstar_4", 0x2F7C, "wait2", "orbit", "wait(1)", "orbit loop 0x2e09: angle += 7.4 deg/frame"),
    ("atk_dstar_x_4", 0x2F7C, "wait2", "orbit", "wait(1)", "orbit loop 0x2e09: angle += 8 deg/frame"),
    ("atk_koopa2_2", 0x27D8, "wait2", "orbit", "wait(1)", "orbit loop 0x2659: angle += 6.8 deg/frame"),
    ("atk_koopax_2", 0x23A2, "wait2", "orbit", "wait(1)", "orbit loop 0x2223: angle += 7 deg/frame"),
    ("atk_dgeraco_5", 0x25CF, "wait2", "orbit", "wait(1)", "orbit loop 0x2450: angle += 7.4 deg/frame"),
]
GROUPS = ("hold", "step2", "orbit")


def source_path() -> str:
    p = os.path.join(PATCH_ROMFS, *REL.split("/"))
    return p if os.path.exists(p) else str(lib3dx.romfs_path(REL))


def sha(b: bytes) -> str:
    return hashlib.sha256(b).hexdigest()


def new_bytes(buf: bytes, dt, pos: int, transform: str) -> bytes:
    r = btl_bai.decode_one(buf, dt, pos)
    if r is None:
        raise ValueError(f"no command at {pos:#x}")
    (p, op, mask, res, params), end = r
    old = buf[pos:end]
    if transform in ("add2", "sub2"):
        want_op = 0x25 if transform == "add2" else 0x26
        if old != struct.pack("<HIHf", want_op, 0, res, 2.0):
            raise ValueError(f"{pos:#x}: not `${res:04x} = op{want_op:03x}(2f)`: {old.hex()}")
        nb = struct.pack("<HIHHH", 0x16 if transform == "add2" else 0x17, 0b11, res, res, STEP_VAR)
    elif transform == "wait2":
        if old != struct.pack("<HIH", 0x05, 0, 1):
            raise ValueError(f"{pos:#x}: not `wait(1)`: {old.hex()}")
        nb = struct.pack("<HIH", 0x05, 0, 2)
    else:
        raise ValueError(transform)
    if len(nb) != len(old):
        raise ValueError("length changed")
    return nb


def load(path: str):
    data = open(path, "rb").read()
    _v, es = lib3dx.read_bg4(data)
    slots = {e.name: n for n, e in enumerate(es)}
    return data, es, slots


def reachable(buf: bytes, dt) -> set[int]:
    """Instruction offsets reachable from the code start and the label table, following fall-through
    (except after end/return/unconditional jump), op003/op004 targets, and every u32 (type 5) immediate
    of any command that lands exactly on a decoded instruction boundary (battle ops 0x193..0x198, 0x4e,
    ... take code offsets there; btl_bai.decode_flow follows only op003/op004)."""
    ins, n = btl_bai.decode_all(buf, dt)
    by = {i[0]: i for i in ins}
    order = sorted(by)
    nxt = {a: b for a, b in zip(order, order[1:])}
    code0 = 4 + 4 * n
    work = [code0] + [x for x in struct.unpack_from(f"<{n}I", buf, 4) if x in by]
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


def apply(groups):
    dt = btl_bai.descs()
    src = source_path()
    data, es, slots = load(src)
    plain = {}
    rows = []
    for script, pos, tr, grp, expect, why in FIXES:
        if grp not in groups:
            continue
        name = script + ".bai"
        n = slots[name]
        cur = plain.get(n)
        if cur is None:
            cur = bytearray(lib3dx.bg4_plain(es[n]))
        r = btl_bai.decode_one(bytes(cur), dt, pos)
        if r is None or btl_bai.fmt(r[0]).split(": ", 1)[1] != expect:
            got = btl_bai.fmt(r[0]) if r else "<undecodable>"
            raise SystemExit(f"{name} {pos:#x}: expected `{expect}`, found `{got}`")
        if pos not in reachable(bytes(cur), dt):
            raise SystemExit(f"{name} {pos:#x}: not reachable from the script entry points")
        nb = new_bytes(bytes(cur), dt, pos, tr)
        old = bytes(cur[pos:pos + len(nb)])
        cur[pos:pos + len(nb)] = nb
        newi = btl_bai.decode_one(bytes(cur), dt, pos)
        plain[n] = cur
        rows.append({"script": name, "offset": f"{pos:#06x}", "group": grp, "transform": tr,
                     "old_bytes": old.hex(), "new_bytes": nb.hex(), "old": expect,
                     "new": btl_bai.fmt(newi[0]).split(": ", 1)[1], "reason": why})
    out = lib3dx.rebuild_bg4(data, {n: bytes(b) for n, b in plain.items()})
    return src, data, out, rows


def compare(src_data: bytes, new_data: bytes, dt):
    """Entry-level comparison: same names/order/flags; list plain-data differences as (name, [offsets])."""
    _v1, a = lib3dx.read_bg4(src_data)
    _v2, b = lib3dx.read_bg4(new_data)
    if [(e.name, e.compressed, e.size_flag, e.name_hash) for e in a] != \
            [(e.name, e.compressed, e.size_flag, e.name_hash) for e in b]:
        raise SystemExit("entry table differs (names/flags/hashes)")
    if src_data[:16] != new_data[:16] or src_data[16 + 14 * len(a):struct.unpack_from("<I", src_data, 8)[0]] != \
            new_data[16 + 14 * len(b):struct.unpack_from("<I", new_data, 8)[0]]:
        raise SystemExit("BG4 header or name block differs")
    diffs = []
    for ea, eb in zip(a, b):
        pa, pb = lib3dx.bg4_plain(ea), lib3dx.bg4_plain(eb)
        if pa == pb:
            continue
        if len(pa) != len(pb):
            raise SystemExit(f"{ea.name}: plain size changed {len(pa)} -> {len(pb)}")
        ia, _ = btl_bai.decode_all(pa, dt)
        ib, _ = btl_bai.decode_all(pb, dt)
        if [i[0] for i in ia] != [i[0] for i in ib]:
            raise SystemExit(f"{ea.name}: instruction boundaries changed")
        changed = [x[0] for x, y in zip(ia, ib) if x != y]
        bytes_diff = [k for k in range(len(pa)) if pa[k] != pb[k]]
        diffs.append((ea.name, changed, bytes_diff))
    return diffs


def main(argv):
    if not argv:
        print(__doc__)
        return
    cmd = argv[0]
    out_dir = DEFAULT_OUT
    if "--out" in argv:
        out_dir = argv[argv.index("--out") + 1]
    groups = set(GROUPS)
    if "--groups" in argv:
        groups = set(argv[argv.index("--groups") + 1].split(","))
        bad = groups - set(GROUPS)
        if bad:
            raise SystemExit(f"unknown groups {bad}")
    dt = btl_bai.descs()
    if cmd == "identity":
        src = source_path()
        data, es, _ = load(src)
        same = lib3dx.rebuild_bg4(data, {}) == data
        print(f"source {src}\nsize {len(data)} sha256 {sha(data)}\nzero-change rebuild byte-identical: {same}")
        # decompress -> recompress -> decompress: a sample of entries (all of them with --codec-all)
        idx = range(len(es)) if "--codec-all" in argv else range(0, len(es), 50)
        ok = same_bytes = 0
        for n in idx:
            p = lib3dx.bg4_plain(es[n])
            c = lib3dx.blz_compress(p)        # raises if the round trip fails
            ok += 1
            same_bytes += c == es[n].data
        print(f"BLZ round trip ok for {ok} entries ({same_bytes} recompressed byte-identical to the original)")
        if not same:
            raise SystemExit(1)
    elif cmd == "build":
        src, data, out, rows = apply(groups)
        diffs = compare(data, out, dt)
        # every changed instruction must be one of ours, and every byte change inside one of our sites
        sites = {(r["script"], int(r["offset"], 16), len(bytes.fromhex(r["new_bytes"]))) for r in rows}
        for name, changed, bdiff in diffs:
            mine = {(p, ln) for (s, p, ln) in sites if s == name}
            if set(changed) != {p for p, _ in mine}:
                raise SystemExit(f"{name}: changed instructions {changed} != sites {sorted(mine)}")
            if any(not any(p <= k < p + ln for p, ln in mine) for k in bdiff):
                raise SystemExit(f"{name}: byte change outside a patch site")
        if len({r['script'] for r in rows}) != len(diffs):
            raise SystemExit("some patched script did not change")
        dst = os.path.join(out_dir, "romfs", *REL.split("/"))
        os.makedirs(os.path.dirname(dst), exist_ok=True)
        with open(dst, "wb") as fh:
            fh.write(out)
        cols = ["script", "offset", "group", "transform", "old_bytes", "new_bytes", "old", "new", "reason"]
        with open(os.path.join(out_dir, "diff.tsv"), "w", encoding="utf-8", newline="\n") as fh:
            fh.write("\t".join(cols) + "\n")
            for r in rows:
                fh.write("\t".join(r[c] for c in cols) + "\n")
        man = {
            "tool": "scripts/fps60/btl_baifix.py", "source": os.path.relpath(src, ROOT).replace("\\", "/"),
            "source_size": len(data), "source_sha256": sha(data),
            "output": os.path.relpath(dst, ROOT).replace("\\", "/"), "output_size": len(out),
            "output_sha256": sha(out), "groups": sorted(groups), "sites": len(rows),
            "scripts_changed": sorted({r["script"] for r in rows}),
            "install": "LayeredFS: copy romfs/BAI/BAI.dat to <mods>/00040000001CA900/romfs/BAI/BAI.dat",
        }
        with open(os.path.join(out_dir, "manifest.json"), "w", encoding="utf-8", newline="\n") as fh:
            json.dump(man, fh, indent=2)
        print(json.dumps(man, indent=2))
        for r in rows:
            print(f"{r['script']:22s} {r['offset']} {r['group']:5s} {r['old']:22s} -> {r['new']}")
    elif cmd == "verify":
        path = argv[1]
        src = source_path()
        data = open(src, "rb").read()
        new = open(path, "rb").read()
        for name, changed, bdiff in compare(data, new, dt):
            print(f"{name}: instructions changed at {[hex(c) for c in changed]}, {len(bdiff)} bytes")
        print(f"source sha256 {sha(data)}\nfile   sha256 {sha(new)}")
    else:
        print(__doc__)


if __name__ == "__main__":
    main(sys.argv[1:])
