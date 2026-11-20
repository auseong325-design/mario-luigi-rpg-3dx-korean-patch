"""FEV (wave 3): FLD Option B as data -- FEvent/FEvent.dat with `wait(1)` -> `wait(2)` at the frame-timer loop
sites that `python scripts/fps60/fld_fev.py waitsites` lists (field60.md 6.2).

    python scripts/fps60/fev_build.py identity [--codec-all]  # decode every entry + zero-change rebuild == source
    python scripts/fps60/fev_build.py sites                   # live site list (fld_fev.py waitsites) with loop notes
    python scripts/fps60/fev_build.py build [--out DIR]       # DIR/romfs/FEvent/FEvent.dat, diff.tsv, manifest.json
    python scripts/fps60/fev_build.py verify [FILE]           # re-read FILE: only the listed u16 parameters differ
    python scripts/fps60/fev_build.py audit [--out DIR]       # inputs read by each site loop, incl. called subroutines

Source: patch/00040000001CA900/romfs/FEvent/FEvent.dat if it exists (BRIEF2 R2; it does not), else
lib3dx.romfs_path("FEvent/FEvent.dat") = romf2/FEvent/FEvent.dat (v1.2). Read-only on every input.
Default DIR = work/fps60/build/fev. Start every run with a timeout (Start-Process + WaitForExit).

Why an own BG4 writer: FEvent.dat has 574 zero-size `.fme` slots that share their offset with the next stored
entry, and its table order is not its storage order. `lib3dx.bg4_layout` sorts by offset only and rejects the file
("entry #1301 is not contiguous"), so `lib3dx.rebuild_bg4` cannot be used here. `assemble()` orders the slots by
(offset, size != 0, slot) -- an empty slot before the stored entry at the same offset -- and packs them
contiguously from the header's data-start, exactly like the original (proved by `identity`).
The decoder for scripts is FLD's (`fld_fev.py`, imported read-only; jump targets are buffer-relative, BRIEF3 W2).
"""
from __future__ import annotations

import contextlib
import hashlib
import io
import json
import os
import struct
import sys
import time

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(os.path.dirname(HERE))
sys.path.insert(0, HERE)
sys.path.insert(0, os.path.join(ROOT, "scripts"))
import fld_fev  # noqa: E402
import lib3dx  # noqa: E402

REL = "FEvent/FEvent.dat"
PATCH_ROMFS = os.path.join(ROOT, "patch", "00040000001CA900", "romfs")
DEFAULT_OUT = os.path.join(ROOT, "work", "fps60", "build", "fev")
OP_WAIT = 0x05
WAIT1 = struct.pack("<HIH", OP_WAIT, 0, 1)
WAIT2 = struct.pack("<HIH", OP_WAIT, 0, 2)
EXPECT_SITES, EXPECT_ENTRIES = 136, 90
EDGE = {"trg", "pTrg", "rls", "pRls", "tp", "btnB", "btnC"}      # what fld_fev.py waitsites excludes
PULSE = EDGE | {"rep", "pRep"}                                     # + key-repeat pulses (true on single frames)


def sha(b: bytes) -> str:
    return hashlib.sha256(b).hexdigest()


def ndspy_version() -> str:
    try:
        from importlib.metadata import version
        return version("ndspy")
    except Exception:  # noqa: BLE001
        return "unknown"


def rel(p: str) -> str:
    return os.path.relpath(p, ROOT).replace("\\", "/")


def source_path() -> str:
    p = os.path.join(PATCH_ROMFS, *REL.split("/"))
    if os.path.exists(p):
        raise SystemExit(f"{p} exists: fld_fev.py computes the sites on lib3dx.romfs_path(); re-derive them first")
    return str(lib3dx.romfs_path(REL))


# --------------------------------------------------------------------------------------------- BG4 (own)
def parse_bg4(data: bytes) -> dict:
    """Header, table rows (offset word, size word, name hash, name offset) and names; cross-checked with
    lib3dx.read_bg4 by `identity`."""
    if data[:4] != b"BG4\0":
        raise ValueError("not a BG4 archive")
    version, count, data_start = struct.unpack_from("<HHI", data, 4)
    rows = [struct.unpack_from("<IIIH", data, 16 + 14 * n) for n in range(count)]
    names_base = 16 + 14 * count
    names = []
    for _o, _s, _h, noff in rows:
        end = data.find(b"\0", names_base + noff)
        names.append(data[names_base + noff:end].decode("ascii"))
    return {"version": version, "count": count, "data_start": data_start, "rows": rows,
            "names_base": names_base, "names": names}


def stored(data: bytes, row) -> bytes:
    off, size = row[0] & 0x7FFFFFFF, row[1] & 0x7FFFFFFF
    return data[off:off + size]


def storage_order(m: dict) -> list[int]:
    """Slots in storage order: by offset, an empty slot before the stored entry that starts at its offset."""
    rows = m["rows"]
    return sorted(range(m["count"]), key=lambda n: (rows[n][0] & 0x7FFFFFFF, (rows[n][1] & 0x7FFFFFFF) != 0, n))


def check_packing(data: bytes, m: dict) -> None:
    """The layout assemble() reproduces: contiguous from data-start, no gaps, no overlaps, no tail."""
    pos = m["data_start"]
    for n in storage_order(m):
        off, size = m["rows"][n][0] & 0x7FFFFFFF, m["rows"][n][1] & 0x7FFFFFFF
        if off != pos:
            raise ValueError(f"slot {n} ({m['names'][n]}) at {off:#x}, expected {pos:#x}")
        if m["rows"][n][1] >> 31:
            raise ValueError(f"slot {n}: size bit 31 set (not expected in FEvent.dat)")
        pos += size
    if pos != len(data):
        raise ValueError(f"data ends at {pos:#x}, file at {len(data):#x}")


def assemble(orig: bytes, m: dict, blobs: dict[int, bytes]) -> bytes:
    """Rebuild: header + table (only offset/size low 31 bits change) + names block copied verbatim
    (it ends with 0xFF padding) + stored data in the original storage order, packed contiguously.
    blobs[n] = new STORED bytes of slot n (already compressed when the slot's flag says so)."""
    head = bytearray(orig[:m["data_start"]])
    body = bytearray()
    for n in storage_order(m):
        off, size, _h, _no = m["rows"][n]
        blob = blobs[n] if n in blobs else stored(orig, m["rows"][n])
        if len(blob) >= 0x80000000:
            raise ValueError("entry too large")
        struct.pack_into("<II", head, 16 + 14 * n, (m["data_start"] + len(body)) | (off & 0x80000000),
                         len(blob) | (size & 0x80000000))
        body += blob
    return bytes(head + body)


# --------------------------------------------------------------------------------------------- BLZ (strict)
def blz_footer(comp: bytes) -> tuple[int, int, int]:
    enc_and_hdr, inc = struct.unpack_from("<II", comp, len(comp) - 8)
    return enc_and_hdr >> 24, enc_and_hdr & 0xFFFFFF, inc


def blz_inplace(comp: bytes) -> bytes:
    """BLZ decompression in ONE buffer of the output size, compressed bytes at its start and output written from
    the end backwards (what an in-place loader does). Raises if a write would hit a compressed byte not yet read,
    if a token crosses the stored prefix, or if the output does not end exactly at the stored prefix."""
    if len(comp) < 8:
        raise ValueError("BLZ: too short")
    hdr, enc, inc = blz_footer(comp)
    if not (8 <= hdr <= enc <= len(comp)):
        raise ValueError(f"BLZ: bad footer hdr={hdr} enc={enc} len={len(comp)}")
    buf = bytearray(comp) + bytearray(inc)
    src, dst, end = len(comp) - hdr, len(buf), len(comp) - enc
    while src > end:
        src -= 1
        flags = buf[src]
        for _ in range(8):
            if src <= end:
                break
            if flags & 0x80:
                src -= 2
                if src < end:
                    raise ValueError("BLZ: reference token crosses the stored prefix")
                b1, b2 = buf[src + 1], buf[src]
                length, disp = (b1 >> 4) + 3, (((b1 & 0x0F) << 8) | b2) + 3
                for _ in range(length):
                    dst -= 1
                    if dst < src:
                        raise ValueError("BLZ: write overtakes unread input (not in-place safe)")
                    if dst + disp >= len(buf):
                        raise ValueError("BLZ: reference beyond the output end")
                    buf[dst] = buf[dst + disp]
            else:
                src -= 1
                dst -= 1
                if dst < src:
                    raise ValueError("BLZ: write overtakes unread input (not in-place safe)")
                buf[dst] = buf[src]
            flags = (flags << 1) & 0xFF
    if dst != end:
        raise ValueError(f"BLZ: output stops at {dst}, stored prefix ends at {end}")
    return bytes(buf)


def plain_of(data: bytes, m: dict, n: int) -> bytes:
    b = stored(data, m["rows"][n])
    if m["rows"][n][0] >> 31 and b:
        return lib3dx.blz_decompress(b)
    return b


# --------------------------------------------------------------------------------------------- sites
def live_sites():
    """Run `fld_fev.py waitsites` in-process; returns (sites, skipped, summary, raw text).
    site = (entry, instruction offset, u16 parameter offset, old, new)."""
    buf = io.StringIO()
    with contextlib.redirect_stdout(buf):
        fld_fev.main(["waitsites"])
    text = buf.getvalue()
    sites, skipped, summary = [], [], ""
    for line in text.splitlines():
        if not line.strip():
            continue
        if line.startswith("; not patched"):
            skipped.append(line[2:])
        elif line.startswith(";"):
            summary = line[2:]
        else:
            name, ins, par, old, new = line.split("\t")
            sites.append((name, int(ins, 16), int(par, 16), int(old), int(new)))
    return sites, skipped, summary, text


def site_loops(name: str, plain: bytes, dt) -> list[dict]:
    """The loops fld_fev.py waitsites patches in this entry (same filter: timers_in(--broad, maxn 80),
    no test room, no edge input in the body)."""
    fld_fev.BROAD = True
    if "_test_" in name:
        return []
    return [r for r in fld_fev.timers_in(name, plain, dt, 80) if not (EDGE & set(r["in"]))]


def loop_of(pos: int, loops: list[dict]):
    cand = [r for r in loops if any(x[0] == pos and x[1] == OP_WAIT for x in r["body"])]
    return min(cand, key=lambda r: (r["hi"] - r["lo"], r["lo"])) if cand else None


def wait_param_type(dt) -> int:
    has_res, types = dt[OP_WAIT]
    if has_res or len(types) != 1 or fld_fev.SIZES.get(types[0]) != 2:
        raise SystemExit(f"op005 descriptor is not one 2-byte parameter: {dt[OP_WAIT]}")
    return types[0]


def flow_positions(plain: bytes, dt) -> dict:
    ins, _sec, _offs = fld_fev.decode_flow(plain, dt)
    return {i[0]: i for i in ins}


def apply_sites(data: bytes, m: dict, sites, dt, value: int = 2):
    """Patch the u16 parameter of every listed `wait(1)` to `value`. Returns ({slot: new plain}, rows).
    Every site must decode as exactly `wait(1)` (bytes 05 00 00 00 00 00 01 00) on FLD's decoded control flow."""
    wait_param_type(dt)
    slot_of = {}
    for n, nm in enumerate(m["names"]):
        if nm in slot_of:
            slot_of[nm] = None          # duplicate name: refuse below
        else:
            slot_of[nm] = n
    by_entry: dict[str, list] = {}
    for s in sites:
        by_entry.setdefault(s[0], []).append(s)
    plain_new, rows = {}, []
    for name in sorted(by_entry):
        n = slot_of.get(name)
        if n is None:
            raise SystemExit(f"{name}: not a unique BG4 slot name")
        old = plain_of(data, m, n)
        cur = bytearray(old)
        flow = flow_positions(old, dt)
        loops = site_loops(name, old, dt)
        for _e, pos, par, ov, nv in sorted(by_entry[name], key=lambda s: s[1]):
            if par != pos + 6 or ov != 1 or nv != 2:
                raise SystemExit(f"{name} {pos:#x}: unexpected site row {par:#x} {ov}->{nv}")
            if bytes(old[pos:pos + 8]) != WAIT1:
                raise SystemExit(f"{name} {pos:#x}: not `wait(1)`: {bytes(old[pos:pos + 8]).hex()}")
            if pos not in flow or flow[pos][1] != OP_WAIT:
                raise SystemExit(f"{name} {pos:#x}: not on the decoded control flow")
            r = loop_of(pos, loops)
            if r is None:
                raise SystemExit(f"{name} {pos:#x}: no patched loop contains this site")
            cur[par:par + 2] = struct.pack("<H", value)
            rows.append({
                "entry": name, "slot": n, "ins": pos, "param": par,
                "old_bytes": bytes(old[pos:pos + 8]).hex(), "new_bytes": bytes(cur[pos:pos + 8]).hex(),
                "old": "wait(1)", "new": f"wait({value})",
                "loop": f"{r['lo']:#07x}-{r['hi']:#07x}", "loop_n": r["n"],
                "ctr": ";".join(f"{k}:{'/'.join(f'{d:g}' for d in v)}" for k, v in sorted(r["ctr"].items())),
                "cmp": ";".join(f"{a}~{c if isinstance(c, str) else format(c, 'g')}" for a, c in r["cmp"][:4]),
                "inputs": ",".join(r["in"]),
            })
        if bytes(cur) != old:
            plain_new[n] = bytes(cur)
    return plain_new, rows


def build_bytes(data: bytes, m: dict, plain_new: dict[int, bytes]):
    """Re-compress only the slots whose plain bytes changed; every other slot keeps its stored bytes."""
    blobs = {}
    for n, p in plain_new.items():
        if p == plain_of(data, m, n):
            continue
        if m["rows"][n][0] >> 31:
            c = lib3dx.blz_compress(p)            # ndspy; raises if the round trip fails
            if blz_inplace(c) != p:
                raise SystemExit(f"slot {n}: recompressed entry is not in-place safe")
            blobs[n] = c
        else:
            blobs[n] = p
    return assemble(data, m, blobs), blobs


# --------------------------------------------------------------------------------------------- compare
def compare(src: bytes, out: bytes, sites, dt) -> dict:
    """Prove: same header/names/flags/hashes, unchanged slots byte-identical, changed slots = the site entries,
    their plain data = source plain with exactly the listed u16 parameters 1 -> 2, every entry decodes to the
    same instruction layout with only those parameters different. Returns statistics; raises on any mismatch."""
    a, b = parse_bg4(src), parse_bg4(out)
    if src[:4] != out[:4] or (a["version"], a["count"], a["data_start"]) != (b["version"], b["count"], b["data_start"]):
        raise SystemExit("BG4 header differs")
    if src[12:16] != out[12:16] or src[a["names_base"]:a["data_start"]] != out[b["names_base"]:b["data_start"]]:
        raise SystemExit("BG4 header word +12 or names block differs")
    for n in range(a["count"]):
        ra, rb = a["rows"][n], b["rows"][n]
        if (ra[0] >> 31, ra[1] >> 31, ra[2], ra[3]) != (rb[0] >> 31, rb[1] >> 31, rb[2], rb[3]):
            raise SystemExit(f"slot {n}: flags/hash/name offset differ")
    check_packing(out, b)
    want: dict[str, dict[int, int]] = {}
    for name, pos, par, ov, nv in sites:
        want.setdefault(name, {})[par] = (ov, nv)
    st = {"slots": a["count"], "unchanged": 0, "changed": 0, "sites": 0, "decoded_entries": 0,
          "decoded_instructions": 0, "inplace_checked": 0}
    for n in range(a["count"]):
        name = a["names"][n]
        sa, sb = stored(src, a["rows"][n]), stored(out, b["rows"][n])
        pa = plain_of(src, a, n)
        if sa == sb:
            if name in want:
                raise SystemExit(f"{name}: listed entry unchanged")
            st["unchanged"] += 1
            pb = pa
        else:
            if name not in want:
                raise SystemExit(f"{name}: changed but has no listed site")
            st["changed"] += 1
            pb = plain_of(out, b, n)
            if b["rows"][n][0] >> 31:
                if blz_inplace(sb) != pb:
                    raise SystemExit(f"{name}: strict in-place decompression differs")
                st["inplace_checked"] += 1
            exp = bytearray(pa)
            for par, (ov, nv) in want[name].items():
                if struct.unpack_from("<H", pa, par)[0] != ov:
                    raise SystemExit(f"{name} {par:#x}: source parameter is not {ov}")
                struct.pack_into("<H", exp, par, nv)
            if pb != bytes(exp):
                raise SystemExit(f"{name}: plain data != source plain with the listed parameters")
            diff = [k for k in range(len(pa)) if pa[k] != pb[k]]
            if sorted(diff) != sorted(want[name]):      # 1 -> 2 changes only the low byte of the u16
                raise SystemExit(f"{name}: byte changes {diff} != parameter offsets {sorted(want[name])}")
            st["sites"] += len(want[name])
        if not name.endswith((".fev", ".fme")) or len(pa) < 0x20:
            continue
        ia, _s1, _o1 = fld_fev.decode_flow(pa, dt)
        ib, _s2, _o2 = fld_fev.decode_flow(pb, dt)
        if [(i[0], i[1], i[2], i[3], len(i[4])) for i in ia] != [(i[0], i[1], i[2], i[3], len(i[4])) for i in ib]:
            raise SystemExit(f"{name}: instruction layout differs")
        for x, y in zip(ia, ib):
            if x == y:
                continue
            if name not in want or x[1] != OP_WAIT or x[0] + 6 not in want[name] or x[4] != [(x[4][0][0], 1)] \
                    or y[4] != [(x[4][0][0], 2)]:
                raise SystemExit(f"{name} {x[0]:#x}: instruction changed outside the site list: {x} -> {y}")
        st["decoded_entries"] += 1
        st["decoded_instructions"] += len(ia)
    if set(want) - {a["names"][n] for n in range(a["count"]) if stored(src, a["rows"][n]) != stored(out, b["rows"][n])}:
        raise SystemExit("some listed entries did not change")
    return st


# --------------------------------------------------------------------------------------------- audit
def reach_inputs(plain: bytes, dt, start: int, limit: int = 4000) -> tuple[set, int]:
    """Input variables read by code reachable from `start` until return/end (follows jmpif, jumps and nested calls)."""
    seen, work, inputs = set(), [start], set()
    while work and len(seen) < limit:
        p = work.pop()
        while p not in seen:
            r = fld_fev.decode_one(plain, dt, p)
            if r is None:
                break
            ins, nxt = r
            seen.add(p)
            inputs |= {fld_fev.INPUT[v] for v in fld_fev.var_ids(ins) if v in fld_fev.INPUT}
            op, params = ins[1], ins[4]
            if op in (0x00, 0x01):
                break
            if op == 0x03:
                t = fld_fev.imm(params, 4)
                if t is not None:
                    work.append(t)
            if op == 0x04:
                kind, t = fld_fev.imm(params, 0), fld_fev.imm(params, 1)
                if t is not None:
                    work.append(t)
                if kind in (0, 2):
                    break
            p = nxt
    return inputs, len(seen)


def audit(data: bytes, m: dict, sites, dt) -> list[dict]:
    out = []
    by_entry: dict[str, list] = {}
    for s in sites:
        by_entry.setdefault(s[0], []).append(s)
    for name in sorted(by_entry):
        n = m["names"].index(name)
        plain = plain_of(data, m, n)
        loops = site_loops(name, plain, dt)
        done = set()
        for _e, pos, _p, _o, _n in sorted(by_entry[name], key=lambda s: s[1]):
            r = loop_of(pos, loops)
            key = (r["lo"], r["hi"])
            if key in done:
                continue
            done.add(key)
            calls = [fld_fev.imm(x[4], 1) for x in r["body"] if x[1] == 0x04 and fld_fev.imm(x[4], 0) == 1]
            cin, cn = set(), 0
            for t in calls:
                if t is not None:
                    i, k = reach_inputs(plain, dt, t)
                    cin |= i
                    cn += k
            other_waits = sorted({fld_fev.imm(x[4], 0) if x[4][0][0] != "var" else "var"
                                  for x in r["body"] if x[1] == OP_WAIT} - {1}, key=str)
            out.append({"entry": name, "loop": f"{r['lo']:#07x}-{r['hi']:#07x}", "n": r["n"],
                        "body_inputs": sorted(r["in"]), "calls": len(calls), "callee_instructions": cn,
                        "callee_inputs": sorted(cin), "pulse_body": sorted(PULSE & set(r["in"])),
                        "pulse_callee": sorted(PULSE & cin), "other_waits": other_waits})
    return out


# --------------------------------------------------------------------------------------------- main
def write_tsv(path: str, cols: list[str], rows: list[dict]) -> None:
    with open(path, "w", encoding="utf-8", newline="\n") as fh:
        fh.write("\t".join(cols) + "\n")
        for r in rows:
            fh.write("\t".join(str(r[c]) if not isinstance(r[c], list) else ",".join(map(str, r[c])) for c in cols)
                     + "\n")


def main(argv):
    if not argv:
        print(__doc__)
        return
    cmd = argv[0]
    out_dir = argv[argv.index("--out") + 1] if "--out" in argv else DEFAULT_OUT
    t0 = time.time()
    src = source_path()
    data = open(src, "rb").read()
    m = parse_bg4(data)
    dt = fld_fev.fdescs()
    if cmd == "identity":
        print(f"source {rel(src)} size {len(data)} sha256 {sha(data)}")
        _v, es = lib3dx.read_bg4(data)
        same_parse = [(e.name, e.raw_offset, e.raw_size, e.name_hash) for e in es] == \
                     [(m["names"][n], r[0], r[1], r[2]) for n, r in enumerate(m["rows"])]
        print(f"BG4 v{m['version']} slots {m['count']} data_start {m['data_start']:#x}; parse == lib3dx.read_bg4: {same_parse}")
        check_packing(data, m)
        print("packing: contiguous in (offset, non-empty, slot) order, no gap/overlap/tail: ok")
        comp = [n for n in range(m["count"]) if m["rows"][n][0] >> 31 and m["rows"][n][1] & 0x7FFFFFFF]
        empty = [n for n in range(m["count"]) if not m["rows"][n][1] & 0x7FFFFFFF]
        print(f"stored compressed {len(comp)}, stored plain {m['count'] - len(comp) - len(empty)}, empty {len(empty)}")
        plain_total, ins_total, dec = 0, 0, 0
        for n in comp:
            b = stored(data, m["rows"][n])
            p1 = lib3dx.blz_decompress(b)
            if blz_inplace(b) != p1:
                raise SystemExit(f"slot {n}: strict in-place decompression differs from lib3dx")
            plain_total += len(p1)
            if m["names"][n].endswith((".fev", ".fme")) and len(p1) >= 0x20:
                ins, _s, _o = fld_fev.decode_flow(p1, dt)
                ins_total += len(ins)
                dec += 1
        print(f"BLZ: all {len(comp)} decompress in place (strict) == lib3dx, plain total {plain_total} bytes")
        print(f"FLD decoder: {dec} scripts decoded, {ins_total} instructions")
        same1 = assemble(data, m, {}) == data
        same2 = assemble(data, m, {n: stored(data, m["rows"][n]) for n in range(m["count"])}) == data
        sites, skipped, summary, _text = live_sites()
        noop, _rows = apply_sites(data, m, sites, dt, value=1)
        out_noop, blobs = build_bytes(data, m, noop)
        same3 = out_noop == data and not blobs
        print(f"zero-change rebuild byte-identical: assemble({{}}) {same1}, assemble(all slots re-stored) {same2}, "
              f"build with all {len(sites)} sites set 1 -> 1 {same3}")
        idx = comp if "--codec-all" in argv else comp[::40]
        ok = same_bytes = 0
        for n in idx:
            b = stored(data, m["rows"][n])
            c = lib3dx.blz_compress(lib3dx.blz_decompress(b))
            blz_inplace(c)
            ok += 1
            same_bytes += c == b
        print(f"ndspy BLZ round trip + in-place check ok for {ok} entries ({same_bytes} byte-identical to the original)")
        print(f"elapsed {time.time() - t0:.1f} s")
        if not (same_parse and same1 and same2 and same3):
            raise SystemExit(1)
    elif cmd == "sites":
        sites, skipped, summary, _text = live_sites()
        _pn, rows = apply_sites(data, m, sites, dt)
        for r in rows:
            print(f"{r['entry']:34s} {r['ins']:#07x} loop {r['loop']} n={r['loop_n']:3d} in={r['inputs']} "
                  f"ctr={r['ctr']} cmp={r['cmp']}")
        print(f"; {summary}")
        for s in skipped:
            print(f"; {s}")
    elif cmd == "build":
        sites, skipped, summary, text = live_sites()
        if len(sites) != EXPECT_SITES or len({s[0] for s in sites}) != EXPECT_ENTRIES:
            raise SystemExit(f"site list changed: {len(sites)} sites in {len({s[0] for s in sites})} entries")
        plain_new, rows = apply_sites(data, m, sites, dt)
        out, blobs = build_bytes(data, m, plain_new)
        st = compare(data, out, sites, dt)
        dst = os.path.join(out_dir, "romfs", *REL.split("/"))
        os.makedirs(os.path.dirname(dst), exist_ok=True)
        with open(dst, "wb") as fh:
            fh.write(out)
        with open(os.path.join(out_dir, "sites.txt"), "w", encoding="utf-8", newline="\n") as fh:
            fh.write(text)
        cols = ["entry", "slot", "ins", "param", "old_bytes", "new_bytes", "old", "new", "loop", "loop_n", "ctr",
                "cmp", "inputs"]
        for r in rows:
            r["ins"], r["param"] = f"{r['ins']:#07x}", f"{r['param']:#07x}"
        write_tsv(os.path.join(out_dir, "diff.tsv"), cols, rows)
        b = parse_bg4(out)
        changed = []
        for n in sorted(blobs):
            changed.append({"entry": m["names"][n], "slot": n,
                            "stored_old": m["rows"][n][1] & 0x7FFFFFFF, "stored_new": len(blobs[n]),
                            "plain_size": len(plain_new[n]), "plain_sha256_old": sha(plain_of(data, m, n)),
                            "plain_sha256_new": sha(plain_new[n]),
                            "sites": sum(1 for s in sites if s[0] == m["names"][n])})
        man = {
            "tool": "scripts/fps60/fev_build.py", "source": rel(src), "source_size": len(data),
            "source_sha256": sha(data), "output": rel(dst), "output_size": len(out), "output_sha256": sha(out),
            "compressor": f"ndspy {ndspy_version()} codeCompression via lib3dx.blz_compress (deterministic)",
            "site_list": "python scripts/fps60/fld_fev.py waitsites (sites.txt)", "site_list_sha256": sha(text.encode()),
            "summary": summary, "not_patched": skipped, "sites": len(rows), "entries_changed": len(blobs),
            "slots": m["count"], "slots_unchanged_bytes": st["unchanged"], "transform": "wait(1) -> wait(2): u16 at instruction+6, 1 -> 2",
            "decoded_entries": st["decoded_entries"], "decoded_instructions": st["decoded_instructions"],
            "changed": changed,
            "install": "LayeredFS: copy romfs/FEvent/FEvent.dat to <mods>/00040000001CA900/romfs/FEvent/FEvent.dat",
        }
        with open(os.path.join(out_dir, "manifest.json"), "w", encoding="utf-8", newline="\n") as fh:
            json.dump(man, fh, indent=2)
        print(json.dumps({k: v for k, v in man.items() if k != "changed"}, indent=2))
        print(f"stored size change {sum(c['stored_new'] - c['stored_old'] for c in changed):+d} bytes; "
              f"data end {b['data_start']:#x}+; elapsed {time.time() - t0:.1f} s")
    elif cmd == "verify":
        path = argv[1] if len(argv) > 1 and not argv[1].startswith("--") else \
            os.path.join(out_dir, "romfs", *REL.split("/"))
        out = open(path, "rb").read()
        sites, skipped, summary, text = live_sites()
        st = compare(data, out, sites, dt)
        man_path = os.path.join(os.path.dirname(os.path.dirname(os.path.dirname(path))), "manifest.json")
        man_ok = None
        if os.path.exists(man_path):
            man = json.load(open(man_path, encoding="utf-8"))
            man_ok = (man["output_sha256"] == sha(out) and man["source_sha256"] == sha(data)
                      and man["sites"] == len(sites) and man["site_list_sha256"] == sha(text.encode()))
        b = parse_bg4(out)
        renew = assemble(out, b, {}) == out
        print(f"source {rel(src)} sha256 {sha(data)}")
        print(f"file   {rel(path) if path.startswith(ROOT) else path} size {len(out)} sha256 {sha(out)}")
        print(f"sites {st['sites']} (list: {summary}); entries changed {st['changed']}, slots byte-identical "
              f"{st['unchanged']} of {st['slots']}; strict in-place BLZ ok for {st['inplace_checked']} changed entries")
        print(f"decoded {st['decoded_entries']} entries / {st['decoded_instructions']} instructions in both files: "
              f"same layout, only the listed wait parameters differ (1 -> 2)")
        print(f"output re-assembles to itself: {renew}; manifest consistent: {man_ok}")
        print(f"elapsed {time.time() - t0:.1f} s")
        if st["sites"] != len(sites) or st["changed"] != len({s[0] for s in sites}) or not renew or man_ok is False:
            raise SystemExit("VERIFY FAILED")
        print("VERIFY OK")
    elif cmd == "audit":
        sites, _sk, _sm, _t = live_sites()
        rows = audit(data, m, sites, dt)
        cols = ["entry", "loop", "n", "body_inputs", "calls", "callee_instructions", "callee_inputs", "pulse_body",
                "pulse_callee", "other_waits"]
        os.makedirs(out_dir, exist_ok=True)
        write_tsv(os.path.join(out_dir, "audit_loops.tsv"), cols, rows)
        for r in rows:
            flag = " !PULSE" if r["pulse_body"] or r["pulse_callee"] else ""
            print(f"{r['entry']:34s} {r['loop']} n={r['n']:3d} body={r['body_inputs']} calls={r['calls']} "
                  f"callee={r['callee_inputs']} waits+={r['other_waits']}{flag}")
        print(f"; {len(rows)} loops; with pulse inputs (edge/repeat) in body or callees: "
              f"{sum(1 for r in rows if r['pulse_body'] or r['pulse_callee'])}")
    else:
        print(__doc__)


if __name__ == "__main__":
    main(sys.argv[1:])
