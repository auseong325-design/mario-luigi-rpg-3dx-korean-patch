"""TB workstream (wave 3): build, verify and (for RT) install the 60fps test beds. Files only.

    python scripts/fps60/tb_build.py status                    # sources, hashes, what is installed
    python scripts/fps60/tb_build.py build [bed ...]           # writes work/fps60/testbeds/<bed>/ + MANIFEST.json
    python scripts/fps60/tb_build.py verify [bed ...]          # re-reads every output and checks every claim
    python scripts/fps60/tb_build.py install <bed> --tag TAG [--variant nofix]   # RT only, emulator stopped
    python scripts/fps60/tb_build.py remove  <bed> --tag TAG                    # RT only, emulator stopped

Beds (README.md in work/fps60/testbeds/):
  t1_battle    FEvent.dat: i_tainai_01.fev arrival entries #53/#54/#55 -> wrapper
               [call original entry; wait(0x3c); op240 copied from i_metaboru_06.fev +0xE83F (scn_meta_05.bai); return]
  t2_hold      FEvent.dat: same wrapper with the op240 of i_air_21.fev +0xB0BD (scn_air_boss.bai, Dark Star)
               + BAI.dat: mon_dstar.bai pattern tables forced to attack 4 (atk_dstar_4), on the BAI-fixed file
                 (romfs/) and on the original file (romfs_nofix/)
  t3_minigame  save: ML3R_001.sav with the lower room 0xA8 i_tainai_01 -> 0x86 i_power_hip_SA_adorena_01_L

Sources (read-only, sha256-checked): FEvent.dat = lib3dx.romfs_path (romf2, v1.2 original, never the patch or a build),
BAI.dat = romfs/BAI/BAI.dat (v1.0, the game's file) and work/fps60/build/bai/romfs/BAI/BAI.dat (BTL2 fix), save =
the test instance's original ML3R_001.sav (sha256 43c2ca72...; taken from the live file, a *.crd_orig / *.tb_orig
backup, or rebuilt from CRD's credits save by restoring its 4 room bytes).
FEvent.dat is not a contiguous BG4 (entries share data), so the changed entry is appended at the end (CRD's
crd_testbed.append_bg4 method, copied here): every original byte stays in place, only that slot's offset/size change.

install/remove only write inside tools/azahar-test: romfs overlays into mods_builds/<TAG>/romfs/ (the real folder that
rt_mods.py use-build TAG made and the mods junction points at; backups in mods_builds/<TAG>.tb_backup/), the save into
the test instance's save folder (backup ML3R_001.sav.tb_orig). They refuse while azahar.exe runs, refuse reparse
points, and never touch patch/ or %APPDATA%\\Azahar (BRIEF2 R5).
"""
from __future__ import annotations

import glob
import hashlib
import json
import os
import shutil
import stat
import struct
import subprocess
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(os.path.dirname(HERE))
sys.path.insert(0, HERE)
sys.path.insert(0, os.path.join(ROOT, "scripts"))
import crd_fevent as F  # noqa: E402  (room-name table only)
import fld_fev as V  # noqa: E402  (FLD decoder: buffer-relative jump targets, BRIEF3 W2)
import lib3dx  # noqa: E402

OUT = os.path.join(ROOT, "work", "fps60", "testbeds")
TEST = os.path.join(ROOT, "tools", "azahar-test")
MODS_BUILDS = os.path.join(TEST, "mods_builds")
MODS_ENTRY = os.path.join(TEST, "user", "load", "mods", "00040000001CA900")
PATCH = os.path.join(ROOT, "patch", "00040000001CA900")
SAVE_GLOB = os.path.join(TEST, "user", "sdmc", "Nintendo 3DS", "*", "*", "title", "00040000", "001ca900", "data",
                         "00000001")

FEV_SHA = "a0fecd0fc48ecf8c63df2498bfe233a35d6c89001fe7d7d1e99a939141bd40aa"
BAI_ORIG = os.path.join(ROOT, "romfs", "BAI", "BAI.dat")
BAI_ORIG_SHA = "12be16cd099b69aee84b9f5fa6cd07342eccb112f1ddc21d440187061de0c2f2"
BAI_FIX = os.path.join(ROOT, "work", "fps60", "build", "bai", "romfs", "BAI", "BAI.dat")
BAI_FIX_SHA = "c681a963b8428128a2d9133c39911f9f2acf5a53e83dff0a097de8fbe750fbb6"
SAVE_SHA = "43c2ca72cb6a5ff26174906c62506ae27743eace6648e4ad2f49ab6ed8eed7cb"
CRD_SAVE = os.path.join(ROOT, "work", "fps60", "credits", "testbed", "save_credits", "ML3R_001.sav")
SD1 = 0x28C0

HOST = "i_tainai_01.fev"
HOST_ENTRIES = (53, 54, 55)          # arrival entries: #53/#54 set $7078 = 3/4 and jump into #55 (default)
WAIT_UNITS = 0x3C                    # 1 s in 60 Hz units at both fps modes
BATTLES = {
    "t1_battle": ("i_metaboru_06.fev", 0xE83F, "scn_meta_05.bai"),
    "t2_hold": ("i_air_21.fev", 0xB0BD, "scn_air_boss.bai"),
}
# mon_dstar.bai attack-pattern tables (offset of the u16 header; header; original u8 elements)
DSTAR_TABLES = (
    (0x4768, 0x800F, (1, 0, 0, 2, 0, 0, 3, 0, 0, 1, 0, 0, 2, 3, 0)),   # phase 0, both bros up (18280)
    (0x477C, 0x8009, (4, 0, 0, 3, 0, 0, 2, 0, 0)),                     # phase 0, one bro down (18300)
    (0x4788, 0x800F, (4, 1, 0, 3, 2, 0, 1, 4, 0, 2, 1, 0, 3, 4, 0)),   # phase >= 1, both up (18312)
    (0x479C, 0x800F, (4, 2, 0, 3, 4, 0, 4, 2, 0, 3, 2, 0, 3, 4, 0)),   # phase >= 1, one down (18332)
)
DSTAR_TABLE_REFS = {0x50EB: 18280.0, 0x5102: 18300.0, 0x513D: 18312.0, 0x5154: 18332.0, 0x518F: 18312.0,
                    0x51A6: 18332.0}   # $8014 = op015(<table>f) in the dispatcher (checked by decoding)
FORCED_ATTACK = 4
T3_ROOM_L = 0x86                     # i_power_hip_SA_adorena_01_L


def sha(b: bytes) -> str:
    return hashlib.sha256(b).hexdigest()


def rd(p: str) -> bytes:
    with open(p, "rb") as f:
        return f.read()


def wr(p: str, b: bytes) -> None:
    os.makedirs(os.path.dirname(p), exist_ok=True)
    with open(p, "wb") as f:
        f.write(b)


def rel(p: str) -> str:
    return os.path.relpath(p, ROOT).replace("\\", "/")


# ------------------------------------------------------------------ sources
def fev_source() -> tuple[str, bytes]:
    p = str(lib3dx.romfs_path("FEvent/FEvent.dat"))
    b = rd(p)
    if sha(b) != FEV_SHA:
        raise SystemExit(f"FEvent.dat source {p} sha256 {sha(b)} != expected original {FEV_SHA}")
    return p, b


def bai_source(which: str) -> tuple[str, bytes]:
    p, h = (BAI_FIX, BAI_FIX_SHA) if which == "fix" else (BAI_ORIG, BAI_ORIG_SHA)
    b = rd(p)
    if sha(b) != h:
        raise SystemExit(f"BAI source {p} sha256 {sha(b)} != expected {h}")
    return p, b


def save_dir() -> str:
    hits = [d for d in glob.glob(SAVE_GLOB) if os.path.isdir(d)]
    if len(hits) != 1:
        raise SystemExit(f"expected one test-instance save dir, found {hits}")
    return hits[0]


def room_block(sav: bytes) -> int:
    return SD1 + 8 + struct.unpack_from("<I", sav, SD1 + 8)[0]


def save_source() -> tuple[str, bytes]:
    """The test instance's original slot-1 save, wherever it currently is (RT may have a test save installed)."""
    d = save_dir()
    for n in ("ML3R_001.sav", "ML3R_001.sav.tb_orig", "ML3R_001.sav.crd_orig"):
        p = os.path.join(d, n)
        if os.path.isfile(p) and sha(rd(p)) == SAVE_SHA:
            return p, rd(p)
    if os.path.isfile(CRD_SAVE):
        b = bytearray(rd(CRD_SAVE))
        struct.pack_into("<HH", b, room_block(bytes(b)) + 2, 0x24D, 0xA8)
        if sha(bytes(b)) == SAVE_SHA:
            return CRD_SAVE + " (room bytes restored)", bytes(b)
    raise SystemExit("original ML3R_001.sav (sha256 43c2ca72...) not found")


# ------------------------------------------------------------------ FEvent helpers
def param_offsets(buf: bytes, dt, pos: int) -> list[tuple[int, int]]:
    """(byte offset, size) of every parameter of the instruction at pos (mirrors fld_fev.decode_one)."""
    op = struct.unpack_from("<H", buf, pos)[0]
    mask = struct.unpack_from("<I", buf, pos + 2)[0]
    has_res, types = dt[op]
    p = pos + 6 + (2 if has_res else 0)
    out = []
    for i, t in enumerate(types):
        sz = 2 if (mask >> i) & 1 else V.SIZES.get(t, 0)
        out.append((p, sz))
        p += sz
    return out


def decode(buf: bytes, dt, pos: int):
    r = V.decode_one(buf, dt, pos)
    if r is None:
        raise SystemExit(f"undecodable instruction at {pos:#x}")
    return r


def cstr_bytes(buf: bytes, off: int) -> bytes:
    e = buf.find(b"\0", off)
    if e < 0:
        raise SystemExit(f"unterminated string at {off:#x}")
    return buf[off:e + 1]


def find_template(buf: bytes, dt, op: int, want) -> tuple[int, bytes]:
    """First flow-decoded instruction with opcode op whose immediates satisfy want(params); returns (pos, bytes)."""
    ins, _sec, _offs = V.decode_flow(buf, dt)
    for i in ins:
        if i[1] == op and i[2] == 0 and want(i[4]):
            _r, nxt = decode(buf, dt, i[0])
            return i[0], buf[i[0]:nxt]
    raise SystemExit(f"no template instruction op{op:03x} found")


def append_bg4(orig: bytes, replace: dict[int, bytes]) -> bytes:
    """CRD crd_testbed.append_bg4 (copied): keep every original byte in place, append each replaced entry
    (BLZ-compressed again when its slot is flagged compressed) 4-aligned with 0x00; only that slot's offset/size
    words change."""
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


def build_fev_battle(bed: str) -> tuple[bytes, dict]:
    src_path, data = fev_source()
    _v, es = lib3dx.read_bg4(data)
    idx = {e.name: i for i, e in enumerate(es)}
    dt = V.fdescs()
    src_room, src_pos, scene = BATTLES[bed]
    src = lib3dx.bg4_plain(es[idx[src_room]])
    host = lib3dx.bg4_plain(es[idx[HOST]])
    # the story's battle start, byte for byte
    (b_ins, b_end) = decode(src, dt, src_pos)
    if b_ins[1] != 0x240 or b_ins[2] != 0:
        raise SystemExit(f"{src_room} {src_pos:#x} is not an immediate op240")
    battle = bytearray(src[src_pos:b_end])
    po = param_offsets(src, dt, src_pos)
    (s6p, s6z), (s7p, s7z) = po[6], po[7]
    if (s6z, s7z) != (4, 4):
        raise SystemExit("op240 string params are not u32")
    s6 = cstr_bytes(src, b_ins[4][6][1])
    s7 = cstr_bytes(src, b_ins[4][7][1])
    if s6[:-1].decode() != scene:
        raise SystemExit(f"scene mismatch {s6!r}")
    # templates from the host room itself
    call_pos, call_t = find_template(host, dt, 0x04, lambda ps: ps[0] == (0, 1) or ps[0][1] == 1)
    wait_pos, wait_t = find_template(host, dt, 0x05, lambda ps: ps[0][1] == WAIT_UNITS)
    ret_pos, ret_t = find_template(host, dt, 0x01, lambda ps: ps and ps[0][1] == 0.0)
    call_tgt = param_offsets(host, dt, call_pos)[1]
    if call_tgt[1] != 4:
        raise SystemExit("call target is not a u32")
    call_tgt_rel = call_tgt[0] - call_pos
    sec, n, offs = V.layout(host)
    new = bytearray(host)
    wrappers = []
    for k in HOST_ENTRIES:
        if not offs[k]:
            raise SystemExit(f"{HOST} entry #{k} is empty")
        entry_abs = sec + offs[k]
        code_off = len(new)
        call = bytearray(call_t)
        struct.pack_into("<I", call, call_tgt_rel, entry_abs)
        code = bytes(call) + wait_t
        b = bytearray(battle)
        str_off = code_off + len(code) + len(battle) + len(ret_t)
        struct.pack_into("<I", b, s6p - src_pos, str_off)
        struct.pack_into("<I", b, s7p - src_pos, str_off + len(s6))
        code += bytes(b) + ret_t + s6 + s7
        new += code
        slot = sec + 4 + 4 * n + 4 * k
        old_rel = struct.unpack_from("<I", host, slot)[0]
        struct.pack_into("<I", new, slot, code_off - sec)
        wrappers.append({"entry": k, "table_slot": slot, "old_rel": old_rel, "old_abs": entry_abs,
                         "new_rel": code_off - sec, "code_offset": code_off, "code_len": len(code),
                         "strings_offset": str_off})
    out = append_bg4(data, {idx[HOST]: bytes(new)})
    info = {"source": rel(src_path), "source_sha256": FEV_SHA, "host": HOST, "host_slot": idx[HOST],
            "host_plain_len": len(host), "host_new_len": len(new), "default_entry": struct.unpack_from("<I", host, 0)[0],
            "battle_from": [src_room, f"{src_pos:#x}", V.fmt(b_ins)], "battle_bytes": bytes(battle).hex(),
            "scene": scene, "strings": [s6.hex(), s7.hex()],
            "templates": {"call": [f"{call_pos:#x}", call_t.hex()], "wait": [f"{wait_pos:#x}", wait_t.hex()],
                          "return": [f"{ret_pos:#x}", ret_t.hex()]},
            "wrappers": wrappers, "output_sha256": sha(out), "output_size": len(out)}
    return out, info


# ------------------------------------------------------------------ BAI helpers
def bai_slots(data: bytes):
    _v, es = lib3dx.read_bg4(data)
    return es, {e.name: i for i, e in enumerate(es)}


def force_dstar(plain: bytes) -> tuple[bytes, list[int]]:
    b = bytearray(plain)
    changed = []
    for off, hdr, vals in DSTAR_TABLES:
        h = struct.unpack_from("<H", b, off)[0]
        if h != hdr or tuple(b[off + 2:off + 2 + len(vals)]) != vals:
            raise SystemExit(f"mon_dstar table at {off:#x}: header {h:#x} / values {list(b[off + 2:off + 2 + len(vals)])}"
                             f" differ from the expected original")
        for i, v in enumerate(vals):
            if v and v != FORCED_ATTACK:
                b[off + 2 + i] = FORCED_ATTACK
                changed.append(off + 2 + i)
    return bytes(b), changed


def check_dstar_refs(plain: bytes) -> None:
    import btl_bai  # noqa: E402  (BTL2 decoder, read-only)
    dt = btl_bai.descs()
    for pos, val in DSTAR_TABLE_REFS.items():
        r = btl_bai.decode_one(plain, dt, pos)
        if r is None or r[0][1] != 0x15 or r[0][3] != 0x8014 or r[0][4][0] != (8, val):
            raise SystemExit(f"mon_dstar {pos:#x}: expected `$8014 = op015({val:g}f)`, got {r and btl_bai.fmt(r[0])}")


def build_bai_forced(which: str) -> tuple[bytes, dict]:
    p, data = bai_source(which)
    es, idx = bai_slots(data)
    n = idx["mon_dstar.bai"]
    plain = lib3dx.bg4_plain(es[n])
    check_dstar_refs(plain)
    new, changed = force_dstar(plain)
    out = lib3dx.rebuild_bg4(data, {n: new})
    return out, {"source": rel(p), "source_sha256": sha(data), "entry": "mon_dstar.bai", "slot": n,
                 "changed_plain_offsets": [f"{x:#x}" for x in changed], "forced_attack": FORCED_ATTACK,
                 "output_sha256": sha(out), "output_size": len(out)}


# ------------------------------------------------------------------ build / verify
def bed_dir(bed: str) -> str:
    return os.path.join(OUT, bed)


def cmd_build(argv):
    beds = argv or ["t1_battle", "t2_hold", "t3_minigame"]
    mpath = os.path.join(OUT, "MANIFEST.json")
    man = json.load(open(mpath, encoding="utf-8")) if os.path.isfile(mpath) else {"tool": "scripts/fps60/tb_build.py",
                                                                                   "beds": {}}
    rs = F.rooms()
    for bed in beds:
        m = {}
        if bed in BATTLES:
            fev, info = build_fev_battle(bed)
            p = os.path.join(bed_dir(bed), "romfs", "FEvent", "FEvent.dat")
            wr(p, fev)
            info["output"] = rel(p)
            m["fevent"] = info
        if bed == "t2_hold":
            for which, sub in (("fix", "romfs"), ("orig", "romfs_nofix")):
                bai, info = build_bai_forced(which)
                p = os.path.join(bed_dir(bed), sub, "BAI", "BAI.dat")
                wr(p, bai)
                info["output"] = rel(p)
                m[f"bai_{which}"] = info
        if bed == "t3_minigame":
            sp, sav = save_source()
            blk = room_block(sav)
            u, low = struct.unpack_from("<HH", sav, blk + 2)
            new = bytearray(sav)
            struct.pack_into("<H", new, blk + 4, T3_ROOM_L)
            p = os.path.join(bed_dir(bed), "save", "ML3R_001.sav")
            wr(p, bytes(new))
            src_copy = os.path.join(OUT, "_source", "ML3R_001.sav")
            wr(src_copy, sav)
            m["save"] = {"source": sp if " (" in sp else rel(sp), "source_sha256": sha(sav),
                         "source_copy": rel(src_copy), "room_block_offset": blk,
                         "old_rooms": [f"{u:#x} {rs[u]}", f"{low:#x} {rs[low]}"],
                         "new_rooms": [f"{u:#x} {rs[u]}", f"{T3_ROOM_L:#x} {rs[T3_ROOM_L]}"],
                         "changed_bytes": [blk + 4, blk + 5], "output": rel(p), "output_sha256": sha(bytes(new))}
        man["beds"][bed] = m
        print(f"built {bed}: " + ", ".join(f"{k} {v['output']} {v['output_sha256'][:12]}" for k, v in m.items()))
    wr(mpath, json.dumps(man, indent=1).encode("utf-8"))


def verify_fev(info: dict) -> bool:
    ok = True
    orig = rd(os.path.join(ROOT, info["source"]))
    new = rd(os.path.join(ROOT, info["output"]))
    ok &= sha(orig) == FEV_SHA and sha(new) == info["output_sha256"]
    _v, eo = lib3dx.read_bg4(orig)
    _v, en = lib3dx.read_bg4(new)
    ok &= [(e.name, e.compressed, e.size_flag, e.name_hash) for e in eo] == \
        [(e.name, e.compressed, e.size_flag, e.name_hash) for e in en]
    # raw bytes: the original file is a prefix except the host slot's 8 table bytes
    hs = info["host_slot"]
    tbl = set(range(16 + hs * 14, 16 + hs * 14 + 8))
    raw_diff = [i for i in range(len(orig)) if orig[i] != new[i]]
    ok &= set(raw_diff) <= tbl and len(new) > len(orig)
    changed = [x.name for x, y in zip(eo, en) if not x.size_flag and lib3dx.bg4_plain(x) != lib3dx.bg4_plain(y)]
    ok &= changed == [info["host"]]
    dt = V.fdescs()
    ho = lib3dx.bg4_plain(eo[hs])
    hn = lib3dx.bg4_plain(en[hs])
    sec, n, offs = V.layout(ho)
    slots = {w["table_slot"] for w in info["wrappers"]}
    pre_diff = [i for i in range(len(ho)) if ho[i] != hn[i]]
    ok &= all(any(s <= i < s + 4 for s in slots) for i in pre_diff) and hn[:len(ho)] != ho
    src = lib3dx.bg4_plain(eo[[e.name for e in eo].index(info["battle_from"][0])])
    bpos = int(info["battle_from"][1], 16)
    src_ins, src_end = decode(src, dt, bpos)
    lines = []
    for w in info["wrappers"]:
        start = sec + struct.unpack_from("<I", hn, w["table_slot"])[0]
        ok &= start == w["code_offset"]
        seq = []
        pos = start
        for _ in range(4):
            ins, nxt = decode(hn, dt, pos)
            seq.append((pos, nxt, ins))
            pos = nxt
        (c0, c1, ci), (w0, w1, wi), (b0, b1, bi), (r0, r1, ri) = seq
        ok &= ci[1] == 0x04 and ci[4][0][1] == 1 and ci[4][1][1] == w["old_abs"] == sec + offs[w["entry"]]
        ok &= wi[1] == 0x05 and wi[4][0][1] == WAIT_UNITS and ri[1] == 0x01
        ok &= bi[1] == 0x240 and [p for i, p in enumerate(bi[4]) if i not in (6, 7)] == \
            [p for i, p in enumerate(src_ins[4]) if i not in (6, 7)]
        # op240 bytes equal the story's except the two string operands
        po_new = param_offsets(hn, dt, b0)
        po_src = param_offsets(src, dt, bpos)
        nb, sb = bytearray(hn[b0:b1]), bytearray(src[bpos:src_end])
        for (pn, _z), (ps_, _z2) in zip(po_new[6:8], po_src[6:8]):
            nb[pn - b0:pn - b0 + 4] = b"\0\0\0\0"
            sb[ps_ - bpos:ps_ - bpos + 4] = b"\0\0\0\0"
        ok &= nb == sb
        s6 = cstr_bytes(hn, bi[4][6][1])
        s7 = cstr_bytes(hn, bi[4][7][1])
        ok &= s6 == cstr_bytes(src, src_ins[4][6][1]) and s7 == cstr_bytes(src, src_ins[4][7][1])
        ok &= bi[4][6][1] == r1 and bi[4][7][1] == r1 + len(s6)
        ok &= r1 + len(s6) + len(s7) == w["code_offset"] + w["code_len"]
        # the call target is the first instruction of the original entry (decodes)
        decode(hn, dt, w["old_abs"])
        lines.append(f"   #{w['entry']} -> {start:#x}: {V.fmt(ci)} | {V.fmt(wi)} | op240 '{s6[:-1].decode()}' "
                     f"'{s7[:-1].decode()}' | {V.fmt(ri)}")
    ok &= _restore(hn[:len(ho)], ho, slots) == ho     # original host bytes except the redirected table slots
    ok &= len(hn) == info["host_new_len"] and struct.unpack_from("<I", hn, 0)[0] == info["default_entry"]
    print(f"  FEvent {info['output']}: raw diff only in slot {hs} table words ({len(raw_diff)} B), changed entries "
          f"{changed}, host +{len(hn) - len(ho)} B")
    print("\n".join(lines))
    return ok


def _restore(prefix: bytes, orig: bytes, slots) -> bytes:
    b = bytearray(prefix)
    for s in slots:
        b[s:s + 4] = orig[s:s + 4]
    return bytes(b) if bytes(b) == orig else b"<mismatch>"


def verify_bai(info: dict, base_sha: str) -> bool:
    ok = True
    src = rd(os.path.join(ROOT, info["source"]))
    new = rd(os.path.join(ROOT, info["output"]))
    ok &= sha(src) == base_sha and sha(new) == info["output_sha256"]
    _v, a = lib3dx.read_bg4(src)
    _v, b = lib3dx.read_bg4(new)
    ok &= [(e.name, e.compressed, e.size_flag, e.name_hash) for e in a] == \
        [(e.name, e.compressed, e.size_flag, e.name_hash) for e in b]
    n0 = struct.unpack_from("<I", src, 8)[0]
    ok &= src[:16] == new[:16] and src[16 + 14 * len(a):n0] == new[16 + 14 * len(b):n0]
    changed = []
    for x, y in zip(a, b):
        px, py = lib3dx.bg4_plain(x), lib3dx.bg4_plain(y)
        if px != py:
            changed.append(x.name)
            if x.name != "mon_dstar.bai" or len(px) != len(py):
                ok = False
                continue
            diff = [i for i in range(len(px)) if px[i] != py[i]]
            want = [int(o, 16) for o in info["changed_plain_offsets"]]
            ok &= diff == want and all(py[i] == FORCED_ATTACK and px[i] not in (0, FORCED_ATTACK) for i in diff)
            forced, _c = force_dstar(px)
            ok &= forced == py
            print(f"  BAI {info['output']}: mon_dstar.bai {len(diff)} bytes, all -> {FORCED_ATTACK}; tables now "
                  + " ".join(str(list(py[o + 2:o + 2 + len(v)])) for o, _h, v in DSTAR_TABLES))
        elif x.data != y.data and x.compressed:
            pass  # unchanged plain, recompressed bytes are not expected but harmless; rebuild keeps originals
    ok &= changed == ["mon_dstar.bai"]
    same_stored = sum(1 for x, y in zip(a, b) if x.data == y.data)
    ok &= same_stored == len(a) - 1
    print(f"  BAI: {len(a)} entries, stored bytes identical for {same_stored}, plain changed {changed}")
    return ok


def verify_save(info: dict) -> bool:
    src = rd(os.path.join(ROOT, info["source_copy"]))
    new = rd(os.path.join(ROOT, info["output"]))
    diff = [i for i in range(len(src)) if src[i] != new[i]]
    blk = info["room_block_offset"]
    u, low = struct.unpack_from("<HH", new, blk + 2)
    ok = sha(src) == SAVE_SHA and sha(new) == info["output_sha256"] and len(src) == len(new)
    ok &= set(diff) <= set(info["changed_bytes"]) and diff and (u, low) == (0x24D, T3_ROOM_L)
    ok &= struct.unpack_from("<HH", src, blk + 2) == (0x24D, 0xA8)
    print(f"  save {info['output']}: differing bytes {[hex(x) for x in diff]}, rooms upper {u:#x} lower {low:#x}")
    return ok


def cmd_verify(argv):
    man = json.load(open(os.path.join(OUT, "MANIFEST.json"), encoding="utf-8"))
    beds = argv or sorted(man["beds"])
    allok = True
    for bed in beds:
        m = man["beds"][bed]
        ok = True
        print(f"[{bed}]")
        if "fevent" in m:
            ok &= verify_fev(m["fevent"])
        if "bai_fix" in m:
            ok &= verify_bai(m["bai_fix"], BAI_FIX_SHA)
            ok &= verify_bai(m["bai_orig"], BAI_ORIG_SHA)
            # the attack under test is untouched: atk_dstar_4 plain equals the fixed / original file's
            for key, base in (("bai_fix", BAI_FIX), ("bai_orig", BAI_ORIG)):
                _v, a = lib3dx.read_bg4(rd(base))
                _v, b = lib3dx.read_bg4(rd(os.path.join(ROOT, m[key]["output"])))
                pa = {e.name: e.data for e in a}
                pb = {e.name: e.data for e in b}
                ok &= pa["atk_dstar_4.bai"] == pb["atk_dstar_4.bai"]
        if "save" in m:
            ok &= verify_save(m["save"])
        print(f"[{bed}] {'OK' if ok else 'FAILED'}")
        allok &= bool(ok)
    print("VERIFY", "OK" if allok else "FAILED")
    return 0 if allok else 1


# ------------------------------------------------------------------ status / install (RT only)
def is_reparse(p: str) -> bool:
    try:
        return bool(os.lstat(p).st_file_attributes & stat.FILE_ATTRIBUTE_REPARSE_POINT)
    except FileNotFoundError:
        return False


def under(p: str, root: str) -> bool:
    return os.path.normcase(os.path.realpath(p)).startswith(os.path.normcase(os.path.realpath(root)) + os.sep)


def emulator_running() -> bool:
    out = subprocess.run(["tasklist", "/FI", "IMAGENAME eq azahar.exe", "/FO", "CSV", "/NH"], capture_output=True,
                         text=True, timeout=20).stdout
    return "azahar.exe" in out.lower()


def overlay_files(bed: str, variant: str | None) -> list[tuple[str, str]]:
    """[(source file, path relative to romfs)] for a bed; variant 'nofix' swaps in romfs_nofix/ files."""
    out = {}
    for sub in ("romfs",) + (("romfs_nofix",) if variant == "nofix" else ()):
        base = os.path.join(bed_dir(bed), sub)
        for dp, _dn, fn in os.walk(base):
            for f in fn:
                p = os.path.join(dp, f)
                out[os.path.relpath(p, base).replace("\\", "/")] = p
    return sorted((p, r) for r, p in out.items())


def tag_romfs(tag: str) -> str:
    dst = os.path.join(MODS_BUILDS, tag)
    if not os.path.isdir(dst) or is_reparse(dst) or not under(dst, MODS_BUILDS):
        raise SystemExit(f"{dst} is not a real mods_builds folder: run `rt_mods.py use-build {tag}` first")
    if not is_reparse(MODS_ENTRY) or os.path.normcase(os.path.realpath(MODS_ENTRY)) != \
            os.path.normcase(os.path.realpath(dst)):
        raise SystemExit(f"the mods junction does not point at {dst}: run `rt_mods.py use-build {tag}` first")
    if os.path.normcase(os.path.realpath(dst)) == os.path.normcase(os.path.realpath(PATCH)):
        raise SystemExit("refusing: that is the patch folder")
    return os.path.join(dst, "romfs")


def cmd_install(argv, remove=False):
    bed = argv[0]
    tag = argv[argv.index("--tag") + 1] if "--tag" in argv else None
    variant = argv[argv.index("--variant") + 1] if "--variant" in argv else None
    if emulator_running():
        raise SystemExit("stop the test emulator first (rt_launch.ps1 -Stop)")
    done = []
    if bed in ("t1_battle", "t2_hold"):
        if not tag:
            raise SystemExit("--tag TAG required (the rt_mods.py use-build tag)")
        romfs = tag_romfs(tag)
        bak = os.path.join(MODS_BUILDS, f"{tag}.tb_backup")
        if is_reparse(bak) or (os.path.exists(bak) and not under(bak, MODS_BUILDS)):
            raise SystemExit("bad backup folder")
        for src, r in overlay_files(bed, variant):
            dst = os.path.join(romfs, *r.split("/"))
            b = os.path.join(bak, *r.split("/"))
            if not remove:
                if os.path.exists(dst) and not os.path.exists(b):
                    os.makedirs(os.path.dirname(b), exist_ok=True)
                    shutil.copy2(dst, b)
                elif not os.path.exists(dst) and not os.path.exists(b + ".absent"):
                    os.makedirs(os.path.dirname(b), exist_ok=True)
                    open(b + ".absent", "w").close()
                os.makedirs(os.path.dirname(dst), exist_ok=True)
                shutil.copy2(src, dst)
                ok = sha(rd(dst)) == sha(rd(src))
                done.append({"file": r, "sha256": sha(rd(dst)), "ok": ok})
            else:
                if os.path.exists(b):
                    shutil.copy2(b, dst)
                    ok = sha(rd(dst)) == sha(rd(b))
                    os.remove(b)
                    done.append({"file": r, "restored": True, "ok": ok})
                elif os.path.exists(b + ".absent"):
                    if os.path.isfile(dst) and not is_reparse(dst):
                        os.remove(dst)
                    os.remove(b + ".absent")
                    done.append({"file": r, "removed": True, "ok": not os.path.exists(dst)})
                else:
                    done.append({"file": r, "note": "no backup recorded; rebuild with rt_mods.py use-build "
                                                    f"{tag} --replace", "ok": False})
    elif bed == "t3_minigame":
        d = save_dir()
        live = os.path.join(d, "ML3R_001.sav")
        bak = live + ".tb_orig"
        var = os.path.join(bed_dir(bed), "save", "ML3R_001.sav")
        if not remove:
            cur = sha(rd(live))
            if not os.path.exists(bak):
                if cur != SAVE_SHA:
                    raise SystemExit(f"ML3R_001.sav is not the original (sha256 {cur[:12]}...): restore it first "
                                     "(e.g. CRD's .crd_orig)")
                shutil.copy2(live, bak)
            shutil.copy2(var, live)
            done.append({"file": "ML3R_001.sav", "sha256": sha(rd(live)), "ok": sha(rd(live)) == sha(rd(var)),
                         "backup": os.path.basename(bak)})
        else:
            if not os.path.exists(bak) or sha(rd(bak)) != SAVE_SHA:
                raise SystemExit("no valid ML3R_001.sav.tb_orig backup")
            shutil.copy2(bak, live)
            ok = sha(rd(live)) == SAVE_SHA
            if ok:
                os.remove(bak)
            done.append({"file": "ML3R_001.sav", "restored": True, "ok": ok})
    else:
        raise SystemExit(f"unknown bed {bed}")
    print(json.dumps({"bed": bed, "tag": tag, "variant": variant, "action": "remove" if remove else "install",
                      "files": done}, indent=1))
    return 0 if all(x.get("ok") for x in done) else 1


def cmd_status(_argv):
    p, b = fev_source()
    print(f"FEvent source {rel(p)} sha256 {sha(b)[:16]} (expected original)")
    for which in ("orig", "fix"):
        p, b = bai_source(which)
        print(f"BAI {which} {rel(p)} sha256 {sha(b)[:16]}")
    sp, sv = save_source()
    print(f"save source {sp} sha256 {sha(sv)[:16]}")
    d = save_dir()
    for n in sorted(os.listdir(d)):
        print(f"  test save dir: {n} {sha(rd(os.path.join(d, n)))[:16]}")
    print(f"mods entry {MODS_ENTRY}: junction={is_reparse(MODS_ENTRY)} -> {os.path.realpath(MODS_ENTRY)}")


def main(argv):
    if not argv:
        print(__doc__)
        return 0
    cmd, rest = argv[0], argv[1:]
    if cmd == "build":
        return cmd_build(rest) or 0
    if cmd == "verify":
        return cmd_verify(rest)
    if cmd == "status":
        return cmd_status(rest) or 0
    if cmd == "install":
        return cmd_install(rest)
    if cmd == "remove":
        return cmd_install(rest, remove=True)
    print(__doc__)
    return 2


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
