"""CRD worker: test bed that reaches the real staff roll (credits) quickly in the portable Azahar instance.

Two independent variants (RT2 installs one; neither touches patch/ or the user's Azahar):

  A  save redirect  work/fps60/credits/testbed/save_credits/ML3R_001.sav
     = a copy of the TEST INSTANCE's ML3R_001.sav whose field room block (SaveData2 = file+0x28C0; block =
       +8 + u32[+8]; u16 room ids at +2 (upper) / +4 (lower), read by the field start 0x3135xx:
       DAT_00415E6A/6C) is changed to 0x2C2 zi_areanone_staffroll_01_U / 0x2C1 zi_areanone_staffroll_01_L.
       Loading file 1 starts the field directly in the two credits rooms; each room runs its own entry script
       (#1 U / #0 L by default, #0 U with an explicit entry 0 -- both run the whole ending).
  B  room warp      work/fps60/credits/testbed/romfs/FEvent/FEvent.dat
     = romf2 FEvent.dat (not in patch/) where the DEFAULT entry script (u32 at .fev+0) of the two rooms the
       save is in jumps to appended code copied byte-for-byte from o_peach_t_06_lastboss_03_U.fev (the story's
       own lead-in): upper room -> op18a(0x2C2, 0,0,0, 8, 0, -1, 3, 0); return / lower room -> op18a(0x2C1, ...).

    python scripts/fps60/crd_testbed.py status        # rooms stored in the test instance's saves (read-only)
    python scripts/fps60/crd_testbed.py build         # writes both variants + MANIFEST.json
    python scripts/fps60/crd_testbed.py verify        # re-reads the outputs and checks every claim
"""
from __future__ import annotations

import glob
import hashlib
import json
import os
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(os.path.dirname(HERE))
sys.path.insert(0, HERE)
sys.path.insert(0, os.path.join(ROOT, "scripts"))
import crd_fevent as F  # noqa: E402
import lib3dx  # noqa: E402

OUT = os.path.join(ROOT, "work", "fps60", "credits", "testbed")
SAVE_GLOB = os.path.join(ROOT, "tools", "azahar-test", "user", "sdmc", "Nintendo 3DS", "*", "*", "title",
                         "00040000", "001ca900", "data", "00000001")
ROOM_U, ROOM_L = 0x2C2, 0x2C1
SD1 = 0x28C0                         # SaveData1 (GameWork copy) size; SaveData2 (0x10000) follows
LEADIN = "o_peach_t_06_lastboss_03_U.fev"
LEADIN_U = (0x481B, 0x4838)          # op18a(0x2c2, 0f, 0f, 0f, 8, 0, -1, 3, 0)
LEADIN_L = (0x65D6, 0x65F3)          # op18a(0x2c1, 0f, 0f, 0f, 8, 0, -1, 3, 0)
RETURN = (0x4838, 0x4842)            # return(0f)


def sha(b: bytes) -> str:
    return hashlib.sha256(b).hexdigest()


def save_dir() -> str:
    hits = [d for d in glob.glob(SAVE_GLOB) if os.path.isdir(d)]
    if len(hits) != 1:
        raise SystemExit(f"expected one test-instance save dir, found {hits}")
    return hits[0]


def room_block(sav: bytes) -> int:
    off8 = struct.unpack_from("<I", sav, SD1 + 8)[0]
    return SD1 + 8 + off8


def save_rooms(sav: bytes):
    blk = room_block(sav)
    if blk + 6 > len(sav):
        return None
    return blk, struct.unpack_from("<HH", sav, blk + 2)


def cmd_status(_argv):
    rs = F.rooms()
    d = save_dir()
    for n in sorted(os.listdir(d)):
        b = open(os.path.join(d, n), "rb").read()
        r = save_rooms(b) if len(b) == SD1 + 0x10000 else None
        if r is None:
            print(f"{n}: {len(b)} B (no field block)")
            continue
        blk, (u, l) = r
        print(f"{n}: {len(b)} B sha256 {sha(b)[:16]}  room block @{blk:#x}: upper {u:#x} "
              f"{rs[u] if u < len(rs) else '?'}, lower {l:#x} {rs[l] if l < len(rs) else '?'}")


def bg4_index(data: bytes) -> dict[str, int]:
    _v, es = lib3dx.read_bg4(data)
    return {e.name: i for i, e in enumerate(es)}


def warp_code(lead: bytes, which) -> bytes:
    return lead[which[0]:which[1]] + lead[RETURN[0]:RETURN[1]]


def patch_room(fev: bytes, code: bytes):
    """Append code and point the default entry script at it. Returns (new_bytes, info)."""
    sec, n, offs = F.fev_layout(fev)
    default = struct.unpack_from("<I", fev, 0)[0]
    if default >= len(offs):
        raise SystemExit(f"default entry {default} out of range ({len(offs)} scripts)")
    new_off = len(fev)
    out = bytearray(fev) + code
    slot = sec + 4 + 4 * n + 4 * default
    old_rel = struct.unpack_from("<I", out, slot)[0]
    struct.pack_into("<I", out, slot, new_off - sec)
    return bytes(out), {"default_entry": default, "table_slot_offset": slot, "old_rel": old_rel,
                        "new_rel": new_off - sec, "code_offset": new_off, "code_len": len(code)}


def append_bg4(orig: bytes, replace: dict[int, bytes]) -> bytes:
    """FEvent.dat is not contiguous (entries overlap/share data), so lib3dx.rebuild_bg4 refuses it. Keep every
    original byte in place and append each replaced entry (BLZ-compressed again when its slot is flagged
    compressed) at the end of the file, 4-byte aligned with 0x00; only that slot's offset/size words change."""
    if orig[:4] != b"BG4\0":
        raise SystemExit("not BG4")
    out = bytearray(orig)
    for n in sorted(replace):
        off, size = struct.unpack_from("<II", orig, 16 + n * 14)
        if size >> 31:
            raise SystemExit(f"slot {n} is a filler entry")
        data = lib3dx.blz_compress(replace[n]) if off >> 31 else bytes(replace[n])
        while len(out) % 4:
            out.append(0)
        start = len(out)
        out += data
        struct.pack_into("<II", out, 16 + n * 14, start | (off & 0x80000000), len(data) | (size & 0x80000000))
    return bytes(out)


def cmd_build(_argv):
    os.makedirs(OUT, exist_ok=True)
    rs = F.rooms()
    man = {"tool": "scripts/fps60/crd_testbed.py", "variants": {}}
    # ---------------- A: save redirect
    d = save_dir()
    src = os.path.join(d, "ML3R_001.sav")
    sav = open(src, "rb").read()
    if len(sav) != SD1 + 0x10000:
        raise SystemExit("unexpected save size")
    blk, (u, l) = save_rooms(sav)
    new = bytearray(sav)
    struct.pack_into("<HH", new, blk + 2, ROOM_U, ROOM_L)
    os.makedirs(os.path.join(OUT, "save_credits"), exist_ok=True)
    dst = os.path.join(OUT, "save_credits", "ML3R_001.sav")
    open(dst, "wb").write(new)
    man["variants"]["A_save_redirect"] = {
        "source": os.path.relpath(src, ROOT), "source_sha256": sha(sav),
        "output": os.path.relpath(dst, ROOT), "output_sha256": sha(bytes(new)),
        "room_block_offset": blk, "old_rooms": [u, l, rs[u], rs[l]],
        "new_rooms": [ROOM_U, ROOM_L, rs[ROOM_U], rs[ROOM_L]],
        "changed_bytes": [blk + 2, blk + 3, blk + 4, blk + 5]}
    # ---------------- B: FEvent room warp
    fsrc = str(lib3dx.romfs_path("FEvent/FEvent.dat"))
    orig = open(fsrc, "rb").read()
    ents = F.entries()
    lead = ents[LEADIN]
    dt = F.fdescs()
    for name, rng in (("U", LEADIN_U), ("L", LEADIN_L), ("ret", RETURN)):
        ins, nxt = F.decode_one(lead, dt, rng[0])
        if nxt != rng[1]:
            raise SystemExit(f"lead-in {name} decode mismatch {F.fmt(ins)} ends {nxt:#x}")
    idx = bg4_index(orig)
    repl = {}
    info = {}
    for room, code in ((u, warp_code(lead, LEADIN_U)), (l, warp_code(lead, LEADIN_L))):
        name = rs[room] + ".fev"
        newb, inf = patch_room(ents[name], code)
        repl[idx[name]] = newb
        inf["room"] = [room, rs[room]]
        inf["warp"] = [F.fmt(i) for i in decode_seq(newb, dt, inf["code_offset"])]
        info[name] = inf
    rebuilt = append_bg4(orig, repl)
    fdst = os.path.join(OUT, "romfs", "FEvent", "FEvent.dat")
    os.makedirs(os.path.dirname(fdst), exist_ok=True)
    open(fdst, "wb").write(rebuilt)
    man["variants"]["B_room_warp"] = {
        "source": os.path.relpath(fsrc, ROOT), "source_sha256": sha(orig),
        "output": os.path.relpath(fdst, ROOT), "output_sha256": sha(rebuilt), "rooms": info}
    open(os.path.join(OUT, "MANIFEST.json"), "w", encoding="utf-8").write(json.dumps(man, indent=2))
    print(json.dumps(man, indent=2))


def decode_seq(b: bytes, dt, pos: int):
    out = []
    while pos < len(b):
        r = F.decode_one(b, dt, pos)
        if r is None:
            break
        out.append(r[0])
        pos = r[1]
        if r[0][1] in (0, 1):
            break
    return out


def cmd_verify(_argv):
    man = json.load(open(os.path.join(OUT, "MANIFEST.json"), encoding="utf-8"))
    ok = True
    a = man["variants"]["A_save_redirect"]
    src = open(os.path.join(ROOT, a["source"]), "rb").read()
    dst = open(os.path.join(ROOT, a["output"]), "rb").read()
    diff = [i for i in range(len(src)) if src[i] != dst[i]]
    rooms = save_rooms(dst)[1]
    print(f"A: {len(src)} vs {len(dst)} B, differing bytes {[hex(x) for x in diff]}, new rooms {[hex(r) for r in rooms]}")
    ok &= len(src) == len(dst) and set(diff) <= set(a["changed_bytes"]) and rooms == (ROOM_U, ROOM_L)
    ok &= sha(src) == a["source_sha256"] and sha(dst) == a["output_sha256"]
    b = man["variants"]["B_room_warp"]
    orig = open(os.path.join(ROOT, b["source"]), "rb").read()
    new = open(os.path.join(ROOT, b["output"]), "rb").read()
    _v, eo = lib3dx.read_bg4(orig)
    _v, en = lib3dx.read_bg4(new)
    ok &= [e.name for e in eo] == [e.name for e in en]
    changed = []
    for x, y in zip(eo, en):
        if x.size_flag or y.size_flag:
            ok &= x.data == y.data
            continue
        px, py = lib3dx.bg4_plain(x), lib3dx.bg4_plain(y)
        if px != py:
            changed.append(x.name)
    print(f"B: {len(eo)} entries, changed {changed}")
    ok &= sorted(changed) == sorted(b["rooms"])
    dt = F.fdescs()
    for name, inf in b["rooms"].items():
        e = next(lib3dx.bg4_plain(y) for y in en if y.name == name)
        sec, n, offs = F.fev_layout(e)
        start = sec + offs[inf["default_entry"]]
        seq = [F.fmt(i) for i in decode_seq(e, dt, start)]
        print(f"   {name}: default entry #{inf['default_entry']} -> {start:#x}: {seq}")
        ok &= start == inf["code_offset"] and seq == inf["warp"]
        o = next(lib3dx.bg4_plain(x) for x in eo if x.name == name)
        ok &= e[:inf["code_offset"]] == bytes(o[:inf["table_slot_offset"]]) + e[inf["table_slot_offset"]:inf["table_slot_offset"] + 4] + o[inf["table_slot_offset"] + 4:]
    print("VERIFY", "OK" if ok else "FAILED")
    return 0 if ok else 1


def main(argv):
    if not argv:
        print(__doc__)
        return 0
    return {"status": cmd_status, "build": cmd_build, "verify": cmd_verify}[argv[0]](argv[1:]) or 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
