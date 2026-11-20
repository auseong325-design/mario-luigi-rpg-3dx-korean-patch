"""TB2 workstream (wave 4): test beds T3b / T3c = FEvent warp from the slot-1 save rooms into the adrenaline minigame
`i_power_hip_SA_adorena_01_L` (room 0x86), the way the story does it. Files only; RT installs. No save edit.

    python scripts/fps60/tb_warp.py status                     # sources, outputs, what each mods_builds tag holds
    python scripts/fps60/tb_warp.py build  [bed ...]           # writes work/fps60/testbeds/<bed>/ (+ MANIFEST.json)
    python scripts/fps60/tb_warp.py verify [bed ...]           # re-reads every output, checks every claim; exit 0 = OK
    python scripts/fps60/tb_warp.py selftest                   # verify must reject mutated copies (negative tests)
    python scripts/fps60/tb_warp.py install <bed> --tag TAG    # RT only, emulator stopped
    python scripts/fps60/tb_warp.py remove  <bed> --tag TAG    # RT only, emulator stopped

Beds (work/fps60/testbeds/README.md section 7):
  t3b_minigame_warp      on the ORIGINAL v1.2 FEvent.dat (romf2, sha256 a0fecd0f...): for v2 (Option A), v2n, smoke
  t3c_minigame_warp_fev  on FEV's FEvent.dat (work/fps60/build/fev, sha256 2e117581...): for v2b (Option B)
Both change one entry, i_tainai_01.fev (the save's lower room): its arrival entries #53/#54/#55 point at appended
wrappers [call original entry; wait(0x3c); hub state copied from i_tainai_01 itself ($c39e = 0, $500d = 3); the story
lead-in copied byte for byte from i_power_hip_01.fev +0x3BA8..+0x3E1A (event flag, party/HUD/fast-forward state,
fades, op18a(0x86)); the upper-screen fade script copied from i_power_hip_01 #19]. Only jump targets and the op06b
script offset are relocated (they are .fev buffer offsets, FLD decoder, BRIEF3 W2). The changed entry is appended at
the end of the BG4 (tb_build.append_bg4 = CRD's method): every original byte stays, only that slot's table words change.

install/remove: same safety checks as tb_build.py (refuse while azahar.exe runs; only the real folder
tools/azahar-test/mods_builds/<TAG>/romfs/ that the mods junction points at; never patch/, never %APPDATA%\\Azahar);
backups in mods_builds/<TAG>.tbw_backup/. They also refuse to mix: t3b needs a tag without FEvent.dat (or the
original), t3c needs a tag holding FEV's FEvent.dat (v2b), and neither installs over a tb_build bed (T1/T2).
"""
from __future__ import annotations

import csv
import hashlib
import json
import os
import shutil
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(os.path.dirname(HERE))
sys.path.insert(0, HERE)
sys.path.insert(0, os.path.join(ROOT, "scripts"))
import crd_fevent as F  # noqa: E402  (room-name table only)
import fld_fev as V  # noqa: E402  (FLD decoder: buffer-relative jump targets)
import lib3dx  # noqa: E402
import tb_build as TB  # noqa: E402  (read-only helpers: append_bg4, param_offsets, find_template, install checks)

OUT = os.path.join(ROOT, "work", "fps60", "testbeds")
FEV_ORIG_SHA = TB.FEV_SHA                     # a0fecd0f... romf2 v1.2 original
FEV_B = os.path.join(ROOT, "work", "fps60", "build", "fev", "romfs", "FEvent", "FEvent.dat")
FEV_B_SHA = "2e1175813e7627002d499d0a8accbe2a5221bba72b2c73158bdb6eff343a5e72"
FEV_B_DIFF = os.path.join(ROOT, "work", "fps60", "build", "fev", "diff.tsv")
FEV_B_NSITES = 136
V2B_FEV = os.path.join(ROOT, "work", "fps60", "build", "v2b", "romfs", "FEvent", "FEvent.dat")

BEDS = {
    "t3b_minigame_warp": {"source": "orig", "use_with": "v2 (Option A), v2n (control), smoke (30fps reference)"},
    "t3c_minigame_warp_fev": {"source": "fev", "use_with": "v2b (Option B)"},
}
HOST = "i_tainai_01.fev"
HOST_ENTRIES = (53, 54, 55)          # arrival entries; #53/#54 set $7078 = 3/4 and jump into #55 (default)
HOST_DEFAULT = 55
LEAD = "i_power_hip_01.fev"
TARGET = "i_power_hip_SA_adorena_01_L.fev"
TARGET_ROOM, TARGET_ENTRY = 0x86, 0x1A
WAIT_UNITS = 0x3C

# Wrapper body after [call, wait(0x3c)], in order: (room, source offset, expected FLD text of the source instruction)
BODY = (
    ("host", 0x60B4, "$c39e = set(0f)"),
    ("host", 0x613B, "$500d = set(3f)"),
    ("lead", 0x3BA8, "$c59c = set(1f)"),
    ("lead", 0x3BB4, "op199(0)"),
    ("lead", 0x3BBB, "op198(1)"),
    ("lead", 0x3CFC, "jmpif(0, $c59d, 1f, 0, 0x3d21)"),
    ("lead", 0x3D0E, "wait(1)"),
    ("lead", 0x3D16, "jump(2, 0x3cfc)"),
    ("lead", 0x3D83, "op270(0)"),
    ("lead", 0x3D8A, "op26a($7021, 0, 0, $705a, 0, 0xff, 0, 1, 55f)"),
    ("lead", 0x3DA4, "op26b($7021)"),
    ("lead", 0x3DAC, "$c08f = set(0f)"),
    ("lead", 0x3DB8, "op150(0, 0)"),
    ("lead", 0x3DC0, "op150(1, 0)"),
    ("lead", 0x3DC8, "op150(2, 0)"),
    ("lead", 0x3DD0, "op06b(1, 0x3e2e, 4)"),
    ("lead", 0x3DDC, "op061(4, $7022)"),
    ("lead", 0x3DFD, "op18a(0x86, 0f, 0f, 0f, 0, 0, 0x1a, 3, 0)"),
    ("lead", 0x3E1A, "return(0f)"),
)
UPPER = (                            # i_power_hip_01 #19, run on the other (upper) screen by op06b
    ("lead", 0x3E2E, "op26a($7021, 0, 0, $705a, 0, 0xff, 0, 1, 16f)"),
    ("lead", 0x3E48, "op26b($7021)"),
    ("lead", 0x3E50, "return(0f)"),
)
LEAD_SCRIPT19 = 19
# relocated u32 fields: source offset -> (parameter index, label of the copied instruction it must point at)
# 0x3CFC's story target 0x3D21 is the $7070 poll, which is left out: the next copied instruction is op270 (0x3D83).
RELOC = {0x3CFC: (4, ("lead", 0x3D83)), 0x3D16: (1, ("lead", 0x3CFC)), 0x3DD0: (1, ("lead", 0x3E2E))}
LEFT_OUT = [
    "lead 0x3BC2..0x3CF4 camera op1a6/op1a7, wait(0x14), op097(0/1,0x63,0f), op1ec/op1f0/op0df/op0aa on actors 0/1/6/7, "
    "wait(0x50): the hip room's jump-in animation (its positions and helper actors)",
    "lead 0x3D21..0x3D7A poll $7070, op195($7022), op194 if $702e == 3, op0e1(1), op195($7022), op061(1, $7022): "
    "readiness polls of the interaction context; the minigame room syncs the upper screen itself (#27 +0x35DB..)",
    "lead 0x3DE5/0x3DF1 op097(0/1, 0x63, 1f): undoes the left-out 0x3BEA/0x3BF6",
]


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


def bed_dir(bed: str) -> str:
    return os.path.join(OUT, bed)


def bed_output(bed: str) -> str:
    return os.path.join(bed_dir(bed), "romfs", "FEvent", "FEvent.dat")


def bed_manifest(bed: str) -> str:
    return os.path.join(bed_dir(bed), "MANIFEST.json")


# ------------------------------------------------------------------ sources
def orig_source() -> tuple[str, bytes]:
    return TB.fev_source()           # sha256-checked against the original romf2 file


def fev_b_source() -> tuple[str, bytes]:
    b = rd(FEV_B)
    if sha(b) != FEV_B_SHA:
        raise SystemExit(f"FEV FEvent.dat {FEV_B} sha256 {sha(b)} != expected {FEV_B_SHA}")
    return FEV_B, b


def bed_source(bed: str) -> tuple[str, bytes, str]:
    if BEDS[bed]["source"] == "orig":
        p, b = orig_source()
        return p, b, FEV_ORIG_SHA
    p, b = fev_b_source()
    return p, b, FEV_B_SHA


def plains(data: bytes):
    _v, es = lib3dx.read_bg4(data)
    return es, {e.name: i for i, e in enumerate(es)}


def text(ins) -> str:
    return V.fmt(ins).split(": ", 1)[1]


def fev_b_sites() -> list[tuple[str, int]]:
    with open(FEV_B_DIFF, encoding="utf-8", newline="") as f:
        rows = list(csv.DictReader(f, delimiter="\t"))
    out = [(r["entry"], int(r["param"], 16)) for r in rows]
    if len(out) != FEV_B_NSITES:
        raise SystemExit(f"FEV diff.tsv has {len(out)} sites, expected {FEV_B_NSITES}")
    return out


# ------------------------------------------------------------------ wrapper assembly
def pieces(orig: bytes, dt):
    """Source instructions of the wrapper, read from the ORIGINAL file (so T3b and T3c get identical bytes):
    [(key, bytes, src_pos, src_buf_name)], plus the call/wait templates and their source positions."""
    es, idx = plains(orig)
    host = lib3dx.bg4_plain(es[idx[HOST]])
    lead = lib3dx.bg4_plain(es[idx[LEAD]])
    bufs = {"host": host, "lead": lead}
    call_pos, call_t = TB.find_template(host, dt, 0x04, lambda ps: ps[0] == (0, 1) or ps[0][1] == 1)
    wait_pos, wait_t = TB.find_template(host, dt, 0x05, lambda ps: ps[0][1] == WAIT_UNITS)
    call_ins, _n = TB.decode(host, dt, call_pos)
    if call_ins[1] != 0x04 or V.imm(call_ins[4], 0) != 1 or TB.param_offsets(host, dt, call_pos)[1][1] != 4:
        raise SystemExit("call template is not jump(1, u32)")
    out = [(("tmpl", "call"), call_t, call_pos, "host"), (("tmpl", "wait"), wait_t, wait_pos, "host")]
    for room, pos, want in BODY + UPPER:
        b = bufs[room]
        ins, nxt = TB.decode(b, dt, pos)
        if text(ins) != want:
            raise SystemExit(f"{room} {pos:#x}: decodes as `{text(ins)}`, expected `{want}`")
        out.append(((room, pos), b[pos:nxt], pos, room))
    # #19 of the lead-in room is the upper fade script the story's op06b names (0x3E2E)
    sec, _n, offs = V.layout(lead)
    if sec + offs[LEAD_SCRIPT19] != 0x3E2E:
        raise SystemExit("i_power_hip_01 script #19 does not start at 0x3E2E")
    return out, bufs


def reloc_field(buf: bytes, dt, pos: int, param: int) -> int:
    """byte offset (relative to the instruction) of a u32 parameter."""
    off, size = TB.param_offsets(buf, dt, pos)[param]
    if size != 4:
        raise SystemExit(f"parameter {param} of the instruction at {pos:#x} is not a u32")
    return off - pos


def assemble_wrapper(ps, bufs, dt, code_off: int, entry_abs: int) -> tuple[bytes, dict]:
    """One wrapper at absolute buffer offset code_off. Returns (bytes, {key: absolute offset})."""
    at = {}
    p = code_off
    for key, b, _sp, _r in ps:
        at[key] = p
        p += len(b)
    out = bytearray()
    for key, b, sp, room in ps:
        x = bytearray(b)
        if key == ("tmpl", "call"):
            struct.pack_into("<I", x, reloc_field(bufs[room], dt, sp, 1), entry_abs)
        elif key[0] == "lead" and key[1] in RELOC:
            par, lab = RELOC[key[1]]
            struct.pack_into("<I", x, reloc_field(bufs[room], dt, sp, par), at[lab])
        out += x
    return bytes(out), at


def build_bed(bed: str) -> tuple[bytes, dict]:
    src_path, data, src_sha = bed_source(bed)
    _p, orig = orig_source()
    dt = V.fdescs()
    ps, bufs = pieces(orig, dt)
    es, idx = plains(data)
    host = lib3dx.bg4_plain(es[idx[HOST]])
    # the copied host instructions are the same bytes in this source's host (FEV changed only same-length waits)
    for key, b, sp, room in ps:
        if room == "host" and host[sp:sp + len(b)] != b:
            raise SystemExit(f"{bed}: host bytes at {sp:#x} differ from the original")
    sec, n, offs = V.layout(host)
    if struct.unpack_from("<I", host, 0)[0] != HOST_DEFAULT:
        raise SystemExit(f"{HOST} default entry is not #{HOST_DEFAULT}")
    new = bytearray(host)
    wrappers = []
    for k in HOST_ENTRIES:
        if not offs[k]:
            raise SystemExit(f"{HOST} entry #{k} is empty")
        entry_abs = sec + offs[k]
        code_off = len(new)
        code, at = assemble_wrapper(ps, bufs, dt, code_off, entry_abs)
        new += code
        slot = sec + 4 + 4 * n + 4 * k
        old_rel = struct.unpack_from("<I", host, slot)[0]
        struct.pack_into("<I", new, slot, code_off - sec)
        wrappers.append({"entry": k, "table_slot": slot, "old_rel": old_rel, "old_abs": entry_abs,
                         "new_rel": code_off - sec, "code_offset": code_off, "code_len": len(code),
                         "upper_offset": at[("lead", 0x3E2E)], "poll_offset": at[("lead", 0x3CFC)],
                         "after_poll_offset": at[("lead", 0x3D83)], "warp_offset": at[("lead", 0x3DFD)]})
    out = TB.append_bg4(data, {idx[HOST]: bytes(new)})
    tgt = lib3dx.bg4_plain(es[idx[TARGET]])
    info = {"bed": bed, "use_with": BEDS[bed]["use_with"], "source": rel(src_path), "source_sha256": src_sha,
            "host": HOST, "host_slot": idx[HOST], "host_plain_len": len(host), "host_new_len": len(new),
            "host_default_entry": HOST_DEFAULT, "target": [f"{TARGET_ROOM:#x}", F.rooms()[TARGET_ROOM],
                                                           "default entry", struct.unpack_from("<I", tgt, 0)[0]],
            "templates": {"call": [f"{ps[0][2]:#x}", ps[0][1].hex()], "wait": [f"{ps[1][2]:#x}", ps[1][1].hex()]},
            "body": [[r, f"{sp:#x}", t, ""] for r, sp, t in BODY], "upper": [[r, f"{sp:#x}", t] for r, sp, t in UPPER],
            "relocated": {f"{k:#x}": [v[0], f"{v[1][0]} {v[1][1]:#x}"] for k, v in RELOC.items()},
            "left_out": LEFT_OUT, "wrappers": wrappers,
            "output_sha256": sha(out), "output_size": len(out)}
    for row, (_key, b, _sp, _r) in zip(info["body"], ps[2:2 + len(BODY)]):
        row[3] = b.hex()
    return out, info


# ------------------------------------------------------------------ verify
def verify_bytes(bed: str, src: bytes, out: bytes, info: dict, check_sha: bool = True) -> list[str]:
    """Every claim about one bed; returns the list of failures (empty = OK)."""
    bad: list[str] = []

    def need(cond, msg):
        if not cond:
            bad.append(msg)

    want_src = FEV_ORIG_SHA if BEDS[bed]["source"] == "orig" else FEV_B_SHA
    need(sha(src) == want_src, f"source sha256 {sha(src)[:16]} != {want_src[:16]}")
    if check_sha:
        need(sha(out) == info["output_sha256"], "output sha256 differs from the manifest")
    _p, orig = orig_source()
    dt = V.fdescs()
    try:
        eo, io_ = plains(src)
        en, _in = plains(out)
    except Exception as exc:  # noqa: BLE001
        return bad + [f"BG4 parse failed: {exc}"]
    need([(e.name, e.compressed, e.size_flag, e.name_hash) for e in eo] ==
         [(e.name, e.compressed, e.size_flag, e.name_hash) for e in en], "slot names/flags/hashes differ")
    hs = io_[HOST]
    need(hs == info["host_slot"], "host slot moved")
    tbl = set(range(16 + hs * 14, 16 + hs * 14 + 8))
    raw_diff = [i for i in range(min(len(src), len(out))) if src[i] != out[i]]
    need(len(out) > len(src) and set(raw_diff) <= tbl,
         f"raw bytes differ outside the host slot's table words ({len(raw_diff)} bytes)")
    changed = []
    for x, y in zip(eo, en):
        if x.size_flag or y.size_flag:
            continue
        try:
            if lib3dx.bg4_plain(x) != lib3dx.bg4_plain(y):
                changed.append(x.name)
        except Exception as exc:  # noqa: BLE001
            bad.append(f"{x.name}: decompression failed: {exc}")
    need(changed == [HOST], f"changed entries {changed[:6]} != [{HOST}]")
    ho = lib3dx.bg4_plain(eo[hs])
    hn = lib3dx.bg4_plain(en[hs])
    # strict in-place BLZ check of the stored host entry (FEV's checker)
    try:
        import fev_build  # noqa: E402  (FEV's strict in-place decompressor, read-only)
        need(fev_build.blz_inplace(en[hs].data) == hn, "host entry: strict in-place BLZ output != plain")
    except Exception as exc:  # noqa: BLE001
        bad.append(f"host entry: strict in-place BLZ failed: {exc}")
    sec, n, offs = V.layout(ho)
    slots = {sec + 4 + 4 * n + 4 * k for k in HOST_ENTRIES}
    pre = [i for i in range(min(len(ho), len(hn))) if ho[i] != hn[i]]
    need(all(any(s <= i < s + 4 for s in slots) for i in pre), "host bytes changed outside the entry table words")
    need(len(hn) == info["host_new_len"] and struct.unpack_from("<I", hn, 0)[0] == HOST_DEFAULT,
         "host length / default entry differ")
    # the wrappers: decode and compare with the source instructions
    try:
        ps, bufs = pieces(orig, dt)
    except SystemExit as exc:
        return bad + [f"source pieces: {exc}"]
    flow = {i[0] for i in V.decode_flow(hn, dt)[0]}
    nsec, _nn, noffs = V.layout(hn)
    for w in info["wrappers"]:
        k = w["entry"]
        start = nsec + noffs[k]
        need(start == w["code_offset"], f"#{k}: table points at {start:#x}, manifest {w['code_offset']:#x}")
        exp, at = assemble_wrapper(ps, bufs, dt, start, sec + offs[k])
        got = hn[start:start + len(exp)]
        need(got == exp, f"#{k}: wrapper bytes differ from the expected assembly")
        need(len(exp) == w["code_len"], f"#{k}: wrapper length {len(exp)} != manifest {w['code_len']}")
        # instruction by instruction: decodes, equals the source except the relocated u32, targets as intended
        pos = start
        for key, b, sp, room in ps:
            try:
                ins, nxt = TB.decode(hn, dt, pos)
            except SystemExit as exc:
                bad.append(f"#{k} {pos:#x}: {exc}")
                break
            nb, sb = bytearray(hn[pos:nxt]), bytearray(b)
            if len(nb) != len(sb) or nb[:2] != sb[:2]:
                bad.append(f"#{k} {pos:#x}: `{text(ins)}` is not the copy of {room} {sp:#x}")
                pos = nxt
                continue
            fld = None
            if key == ("tmpl", "call"):
                fld = (reloc_field(bufs[room], dt, sp, 1), sec + offs[k])
            elif key[0] == "lead" and key[1] in RELOC:
                par, lab = RELOC[key[1]]
                fld = (reloc_field(bufs[room], dt, sp, par), at[lab])
            if fld:
                need(struct.unpack_from("<I", nb, fld[0])[0] == fld[1], f"#{k} {pos:#x}: relocated field != {fld[1]:#x}")
                nb[fld[0]:fld[0] + 4] = b"\0\0\0\0"
                sb[fld[0]:fld[0] + 4] = b"\0\0\0\0"
            need(nb == sb, f"#{k} {pos:#x}: bytes differ from {room} {sp:#x}")
            if key not in [("lead", p_) for _r, p_, _t in UPPER]:
                need(pos in flow, f"#{k} {pos:#x}: not reached by FLD's flow decoder")
            pos = nxt
        need(pos == start + w["code_len"], f"#{k}: decoded length differs")
        # call target = first instruction of the original entry (still decodes, still in flow)
        try:
            TB.decode(hn, dt, sec + offs[k])
            need(sec + offs[k] in flow, f"#{k}: original entry {sec + offs[k]:#x} not reached through the call")
        except SystemExit as exc:
            bad.append(f"#{k}: original entry does not decode: {exc}")
        need(at[("lead", 0x3E2E)] == w["upper_offset"] and at[("lead", 0x3DFD)] == w["warp_offset"],
             f"#{k}: label offsets differ from the manifest")
    # target room facts
    rs = F.rooms()
    to = lib3dx.bg4_plain(eo[io_[TARGET]])
    need(rs[TARGET_ROOM] + ".fev" == TARGET, f"room {TARGET_ROOM:#x} is {rs[TARGET_ROOM]}")
    need(struct.unpack_from("<I", to, 0)[0] == TARGET_ENTRY, "target room default entry != 0x1A")
    # T3c: FEV's 136 sites intact (u16 2 in the output, 1 in the original) and the output = FEV + host only
    if BEDS[bed]["source"] == "fev":
        e0, i0 = plains(orig)
        ok_sites = 0
        for name, par in fev_b_sites():
            yo = lib3dx.bg4_plain(e0[i0[name]])
            yn = lib3dx.bg4_plain(en[_in[name]])
            if struct.unpack_from("<H", yo, par)[0] == 1 and struct.unpack_from("<H", yn, par)[0] == 2:
                ok_sites += 1
            else:
                bad.append(f"FEV site {name} {par:#x} not intact")
        need(ok_sites == FEV_B_NSITES, f"FEV sites intact {ok_sites}/{FEV_B_NSITES}")
        # entries that differ from the ORIGINAL = FEV's changed entries (+ the host, which FEV also changed)
        fev_entries = {nm for nm, _p in fev_b_sites()}
        diff_orig = {x.name for x, y in zip(e0, en) if not x.size_flag and lib3dx.bg4_plain(x) != lib3dx.bg4_plain(y)}
        need(diff_orig == fev_entries | {HOST}, "entries differing from the original != FEV's entries + host")
    return bad


def cmd_build(argv):
    beds = argv or list(BEDS)
    for bed in beds:
        out, info = build_bed(bed)
        p = bed_output(bed)
        wr(p, out)
        info["output"] = rel(p)
        info["tool"] = "scripts/fps60/tb_warp.py"
        wr(bed_manifest(bed), json.dumps(info, indent=1).encode("utf-8"))
        print(f"built {bed}: {info['output']} {len(out)} B sha256 {info['output_sha256'][:16]} "
              f"(host +{info['host_new_len'] - info['host_plain_len']} B, wrappers "
              + ", ".join(f"#{w['entry']}@{w['code_offset']:#x}" for w in info["wrappers"]) + ")")
    return 0


def describe(bed: str, out: bytes, info: dict) -> None:
    dt = V.fdescs()
    en, inx = plains(out)
    hn = lib3dx.bg4_plain(en[inx[HOST]])
    w = info["wrappers"][-1]
    pos, end = w["code_offset"], w["code_offset"] + w["code_len"]
    print(f"   wrapper #{w['entry']} (default entry) at {pos:#x}..{end:#x}:")
    while pos < end:
        ins, nxt = TB.decode(hn, dt, pos)
        print("      " + V.fmt(ins))
        pos = nxt


def cmd_verify(argv):
    beds = argv or list(BEDS)
    allok = True
    wrappers = {}
    for bed in beds:
        if not os.path.isfile(bed_manifest(bed)):
            print(f"[{bed}] no MANIFEST.json (run build)")
            allok = False
            continue
        info = json.load(open(bed_manifest(bed), encoding="utf-8"))
        src = rd(os.path.join(ROOT, info["source"]))
        out = rd(bed_output(bed))
        bad = verify_bytes(bed, src, out, info)
        rebuilt, _i = build_bed(bed)
        if rebuilt != out:
            bad.append("a fresh build from the sources differs from the file on disk")
        en, inx = plains(out)
        hn = lib3dx.bg4_plain(en[inx[HOST]])
        wrappers[bed] = hn[info["host_plain_len"]:]
        print(f"[{bed}] source {info['source']} {info['source_sha256'][:16]}, output {info['output']} "
              f"{info['output_size']} B {info['output_sha256'][:16]}; only {HOST} changed "
              f"(+{info['host_new_len'] - info['host_plain_len']} B, 3 table words)")
        describe(bed, out, info)
        for b in bad:
            print("   FAIL: " + b)
        print(f"[{bed}] {'OK' if not bad else 'FAILED'}")
        allok &= not bad
    if len(wrappers) == 2:
        same = len(set(wrappers.values())) == 1
        print(f"appended wrapper bytes identical in T3b and T3c: {same}")
        allok &= same
    print("VERIFY", "OK" if allok else "FAILED")
    return 0 if allok else 1


def cmd_selftest(_argv):
    """Negative tests: verify_bytes must reject each mutation and accept the unmutated output."""
    dt = V.fdescs()
    results = []
    for bed in BEDS:
        info = json.load(open(bed_manifest(bed), encoding="utf-8"))
        src = rd(os.path.join(ROOT, info["source"]))
        out = rd(bed_output(bed))
        es, idx = plains(src)
        hs = idx[HOST]
        en_, _ix = plains(out)
        hn = bytearray(lib3dx.bg4_plain(en_[hs]))
        w = info["wrappers"][-1]

        def rehost(mut: bytes) -> bytes:
            return TB.append_bg4(src, {hs: bytes(mut)})

        muts = {}
        m = bytearray(hn)
        p18 = w["warp_offset"]
        r = TB.param_offsets(bytes(hn), dt, p18)[0][0]
        m[r] = 0x87                                   # op18a room 0x86 -> 0x87
        muts["op18a room 0x86->0x87"] = rehost(m)
        m = bytearray(hn)
        pw = w["code_offset"] + len(bytes.fromhex(info["templates"]["call"][1]))
        m[pw + 6] = 0x3D                              # wait(0x3c) -> wait(0x3d)
        muts["template wait(0x3c)->wait(0x3d)"] = rehost(m)
        m = bytearray(hn)
        pp = w["poll_offset"]
        r = TB.param_offsets(bytes(hn), dt, pp)[4][0]
        struct.pack_into("<I", m, r, 0x3D21)          # relocated jmpif target back to the story value
        muts["jmpif target not relocated"] = rehost(m)
        m = bytearray(hn)
        m[0x3000] ^= 1                                # one byte of the original host code
        muts["host original byte flipped"] = rehost(m)
        muts["unchanged source as output"] = src
        other = "i_metaboru_09.fev"
        po = bytearray(lib3dx.bg4_plain(es[idx[other]]))
        po[0x40] ^= 1
        muts[f"extra change in {other}"] = TB.append_bg4(out, {idx[other]: bytes(po)})
        if BEDS[bed]["source"] == "fev":
            name, par = fev_b_sites()[0]
            pf = bytearray(lib3dx.bg4_plain(en_[idx[name]]))
            struct.pack_into("<H", pf, par, 1)        # revert one FEV site
            muts[f"FEV site {name} {par:#x} reverted"] = TB.append_bg4(out, {idx[name]: bytes(pf)})
        base = verify_bytes(bed, src, out, info, check_sha=False)
        results.append((bed, "baseline", not base, base[:2]))
        for label, data in muts.items():
            bad = verify_bytes(bed, src, data, info, check_sha=False)
            results.append((bed, label, bool(bad), bad[:2]))
    ok = True
    for bed, label, good, why in results:
        exp = "accepted" if label == "baseline" else "rejected"
        print(f"{bed:24s} {label:44s} {exp if good else 'NOT ' + exp}  {why[:1]}")
        ok &= good
    print("SELFTEST", "OK" if ok else "FAILED")
    return 0 if ok else 1


# ------------------------------------------------------------------ status / install (RT only)
def known_hashes() -> dict[str, str]:
    k = {FEV_ORIG_SHA: "original FEvent.dat (romf2 v1.2)", FEV_B_SHA: "FEV FEvent.dat (Option B)"}
    for bed in BEDS:
        if os.path.isfile(bed_manifest(bed)):
            k[json.load(open(bed_manifest(bed), encoding="utf-8"))["output_sha256"]] = bed
    for path, key, label in ((os.path.join(OUT, "MANIFEST.json"), ("beds",), "tb_build"),
                             (os.path.join(ROOT, "work", "fps60", "credits", "testbed", "MANIFEST.json"),
                              ("variants",), "credits")):
        if os.path.isfile(path):
            m = json.load(open(path, encoding="utf-8"))
            for name, v in m.get(key[0], {}).items():
                for sub in (v.values() if isinstance(v, dict) else []):
                    if isinstance(sub, dict) and "output_sha256" in sub and str(sub.get("output", "")).endswith(
                            "FEvent.dat"):
                        k[sub["output_sha256"]] = f"{label} {name}"
                if isinstance(v, dict) and str(v.get("output", "")).endswith("FEvent.dat"):
                    k[v["output_sha256"]] = f"{label} {name}"
    return k


def cmd_status(_argv):
    p, b = orig_source()
    print(f"original source {rel(p)} sha256 {sha(b)[:16]}")
    p, b = fev_b_source()
    print(f"FEV source      {rel(p)} sha256 {sha(b)[:16]}; v2b copy "
          f"{'same' if os.path.isfile(V2B_FEV) and sha(rd(V2B_FEV)) == FEV_B_SHA else 'MISSING/DIFFERENT'}")
    for bed in BEDS:
        o = bed_output(bed)
        print(f"{bed}: {rel(o)} " + (f"sha256 {sha(rd(o))[:16]}" if os.path.isfile(o) else "not built"))
    kh = known_hashes()
    print(f"mods entry: junction={TB.is_reparse(TB.MODS_ENTRY)} -> {os.path.realpath(TB.MODS_ENTRY)}")
    if os.path.isdir(TB.MODS_BUILDS):
        for t in sorted(os.listdir(TB.MODS_BUILDS)):
            d = os.path.join(TB.MODS_BUILDS, t)
            if not os.path.isdir(d) or t.endswith((".tb_backup", ".tbw_backup")):
                continue
            f = os.path.join(d, "romfs", "FEvent", "FEvent.dat")
            h = sha(rd(f)) if os.path.isfile(f) else None
            extra = [s for s in (".tb_backup", ".tbw_backup") if os.path.isdir(d + s)]
            print(f"  tag {t}: FEvent.dat {kh.get(h, h[:16] if h else 'absent (game uses romf2)')} {extra or ''}")
    return 0


def tag_fevent(tag: str) -> tuple[str, str]:
    romfs = TB.tag_romfs(tag)        # real mods_builds/<tag>, junction points at it, not patch/
    return romfs, os.path.join(romfs, "FEvent", "FEvent.dat")


def cmd_install(argv, remove=False):
    if not argv or argv[0] not in BEDS or "--tag" not in argv:
        raise SystemExit("usage: tb_warp.py install|remove <t3b_minigame_warp|t3c_minigame_warp_fev> --tag TAG")
    bed, tag = argv[0], argv[argv.index("--tag") + 1]
    if TB.emulator_running():
        raise SystemExit("stop the test emulator first (rt_launch.ps1 -Stop)")
    romfs, dst = tag_fevent(tag)
    bak_dir = os.path.join(TB.MODS_BUILDS, f"{tag}.tbw_backup")
    if TB.is_reparse(bak_dir) or (os.path.exists(bak_dir) and not TB.under(bak_dir, TB.MODS_BUILDS)):
        raise SystemExit("bad backup folder")
    if TB.is_reparse(dst) or TB.is_reparse(os.path.dirname(dst)):
        raise SystemExit("refusing: FEvent path is a reparse point")
    bak = os.path.join(bak_dir, "FEvent", "FEvent.dat")
    rec_p = os.path.join(bak_dir, "install.json")
    src = bed_output(bed)
    want = json.load(open(bed_manifest(bed), encoding="utf-8"))["output_sha256"]
    if sha(rd(src)) != want:
        raise SystemExit(f"{rel(src)} does not match its manifest: run verify")
    if not remove:
        tb_bak = os.path.join(TB.MODS_BUILDS, f"{tag}.tb_backup", "FEvent", "FEvent.dat")
        if os.path.exists(tb_bak) or os.path.exists(tb_bak + ".absent"):
            raise SystemExit(f"a tb_build bed (T1/T2) is installed on {tag}: `tb_build.py remove <bed> --tag {tag}` first")
        if os.path.exists(rec_p):
            rec = json.load(open(rec_p, encoding="utf-8"))
            if rec.get("bed") == bed and os.path.isfile(dst) and sha(rd(dst)) == want:
                print(json.dumps({"bed": bed, "tag": tag, "action": "install", "note": "already installed",
                                  "ok": True}, indent=1))
                return 0
            raise SystemExit(f"{rec.get('bed')} is recorded as installed on {tag}: remove it first")
        cur = sha(rd(dst)) if os.path.isfile(dst) else None
        if BEDS[bed]["source"] == "orig" and cur not in (None, FEV_ORIG_SHA):
            raise SystemExit(f"{tag} holds FEvent.dat {cur[:16]} (not absent/original): t3b is for v2/v2n/smoke tags; "
                             "for v2b use t3c_minigame_warp_fev")
        if BEDS[bed]["source"] == "fev" and cur != FEV_B_SHA:
            raise SystemExit(f"{tag} does not hold FEV's FEvent.dat ({cur and cur[:16]}): t3c is for "
                             "`rt_mods.py use-build v2b`")
        os.makedirs(os.path.dirname(bak), exist_ok=True)
        if cur is None:
            open(bak + ".absent", "w").close()
        else:
            shutil.copy2(dst, bak)
        os.makedirs(os.path.dirname(dst), exist_ok=True)
        shutil.copy2(src, dst)
        ok = sha(rd(dst)) == want
        json.dump({"bed": bed, "tag": tag, "original_sha256": cur, "installed_sha256": want},
                  open(rec_p, "w", encoding="utf-8"), indent=1)
        res = {"bed": bed, "tag": tag, "action": "install", "file": rel(dst), "sha256": sha(rd(dst)),
               "replaced": cur and known_hashes().get(cur, cur[:16]), "ok": ok}
    else:
        if not os.path.exists(rec_p):
            raise SystemExit(f"nothing recorded as installed on {tag} (no {rel(rec_p)})")
        rec = json.load(open(rec_p, encoding="utf-8"))
        if rec.get("bed") != bed:
            raise SystemExit(f"{rec.get('bed')} is installed on {tag}, not {bed}")
        if os.path.isfile(dst) and sha(rd(dst)) not in (want, rec["original_sha256"]):
            raise SystemExit(f"{rel(dst)} was changed since install (sha256 {sha(rd(dst))[:16]}): not touching it")
        if rec["original_sha256"] is None:
            if not os.path.exists(bak + ".absent"):
                raise SystemExit("backup marker missing")
            if os.path.isfile(dst):
                os.remove(dst)
            os.remove(bak + ".absent")
            d = os.path.dirname(dst)
            if os.path.isdir(d) and not os.listdir(d) and not TB.is_reparse(d):
                os.rmdir(d)
            ok = not os.path.exists(dst)
        else:
            if not os.path.isfile(bak) or sha(rd(bak)) != rec["original_sha256"]:
                raise SystemExit("backup missing or changed")
            shutil.copy2(bak, dst)
            ok = sha(rd(dst)) == rec["original_sha256"]
            if ok:
                os.remove(bak)
        if ok:
            os.remove(rec_p)
            for d in (os.path.join(bak_dir, "FEvent"), bak_dir):
                if os.path.isdir(d) and not os.listdir(d) and not TB.is_reparse(d):
                    os.rmdir(d)
        res = {"bed": bed, "tag": tag, "action": "remove", "file": rel(dst),
               "restored": rec["original_sha256"] and known_hashes().get(rec["original_sha256"]), "ok": ok}
    print(json.dumps(res, indent=1))
    return 0 if res["ok"] else 1


def main(argv):
    if not argv:
        print(__doc__)
        return 0
    cmd, rest = argv[0], argv[1:]
    if cmd == "build":
        return cmd_build(rest)
    if cmd == "verify":
        return cmd_verify(rest)
    if cmd == "selftest":
        return cmd_selftest(rest)
    if cmd == "status":
        return cmd_status(rest)
    if cmd == "install":
        return cmd_install(rest)
    if cmd == "remove":
        return cmd_install(rest, remove=True)
    print(__doc__)
    return 2


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
