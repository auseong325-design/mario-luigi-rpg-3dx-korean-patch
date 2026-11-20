"""Build the New-3DS-only 60fps code patch for M&L RPG3 DX JP v1.2 (worker IMPL, BRIEF2 D1-D6).

    python scripts/fps60/build_fps60.py --tag v1                    # default build + every check
    python scripts/fps60/build_fps60.py --tag v1c --credits-fix      # + staff-roll scroll fix (static variant)
    python scripts/fps60/build_fps60.py --tag t1 --allow fld,btl     # other allow-list (names or 0x vptrs)
    python scripts/fps60/build_fps60.py --tag t2 --no-snake          # TEST ONLY: no New-3DS test (O3DS A/B)
    python scripts/fps60/build_fps60.py --tag v1 --skip-emu          # skip the unicorn tests
    python scripts/fps60/build_fps60.py --tag v2 --credits-fix --field-vm30 --with-bai   # wave 3 (IMPL3)
    python scripts/fps60/build_fps60.py --tag v2n --credits-fix --with-bai               # v2 without the VM fix

Wave 3 (IMPL3, field60.md §6.1/§7 F1-F4, README §10-§14):
  --field-vm30: under G (fld::System+0x45 == 0) the two field event systems keep the 30 Hz script schedule:
     F1 vtable slot +0x34 (0x3E17B8, 0x3E3070) -> fld60_step_*: event step s0 *= 2, tail-call the original;
     F2 slot +0x20 (0x3E17A4, 0x3E305C) -> fld60_exec: on odd fld::System+0x578 frames do not run the
        LocalEvent (latch this frame's pad/touch edges, return its status); one-shot runs on a stack
        LocalEvent (r1 in [sp, sp+0x8000)) are never gated;
     F3 slot +0x2C (0x3E17B0, 0x3E3068) -> fld60_sysvar: on even frames, for ids $702F..$7041, OR the latch
        of the previous (odd) frame into the pad trg/rls and touch edge bits around the original call;
     F4 latch 16 bytes RW at 0x434F00 (bss page tail, impl_rwscan.py).
     With --credits-fix the staff-roll speed halving is NOT installed: fld::StaffrollCtrl::update is called
     only by the op280 VM command, so under --field-vm30 it already runs 30 times per second.
  --with-bai: copy work/fps60/build/bai/romfs/BAI/BAI.dat (BTL2) to <tag>/romfs/BAI/BAI.dat (sha256 asserted).

Inputs (read-only): work/fps60/bin/3dx_v12.code.bin (decompressed v1.2 code, the patch source),
exefs2/.code + exefs/.code (compressed v1.2 / v1.0 code, for the loader-chain checks), the two CIAs
(exheader sizes), romf2/RO/static.crs (symbols + relocation targets).
Outputs: work/fps60/build/<tag>/code.bps (deliverable, D4), code.ips (same bytes, see README), patched.code.bin,
manifest.json, verify.txt. Never writes into patch/ (D6).

Patch design (BRIEF2 D1/D2, engine.md §9; verified again here):
  hook   ad::fw::TaskBase::init 0x28092C  'ldrb r0,[r4,#0x3d]' -> 'bl eng60_init'
  cave   0x388E00.. (D2: above Luma's LayeredFS payload at .text end 0x388BD8, max 0x11C bytes)
  eng60_init(r4 = task): +0x41 = 0; if (+0x3D == 1 && vptr in allow-list && IsRunOnSnake()) {+0x3D = 0; +0x41 = 1}
                         return r0 = +0x3D   (init stores it to +0x45; funcInit re-copies +0x3D every frame)
  --credits-fix: field event cmd 0x280 sub-op 0 (0x2E8B24): the nop at 0x2E8B9C right after
                 'bl fld::StaffrollCtrl::init' -> 'bl crd60_fix': if fld::System(r5)+0x45 == 0 then
                 ctrl(=[r5+0x1B3C])+0x28 (scroll px per update, 2.0) *= 0.5.
"""
from __future__ import annotations

import argparse
import datetime
import hashlib
import json
import os
import struct
import sys

import capstone
import keystone

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(os.path.dirname(HERE))
sys.path.insert(0, HERE)
import impl_exheader  # noqa: E402
import impl_loaders as L  # noqa: E402
from cro import CRO, static_symbols  # noqa: E402  (lead-owned tool, imported read-only)

BASE = 0x100000
TITLE_ID = "00040000001CA900"
P_V12 = "work/fps60/bin/3dx_v12.code.bin"
P_V10 = "work/fps60/bin/3dx_v10.code.bin"
P_EXEFS_V12 = "exefs2/.code"
P_EXEFS_V10 = "exefs/.code"
P_CRS = "romf2/RO/static.crs"
OUT_ROOT = "work/fps60/build"

# v1.2 code-set (checked against the update CIA exheader at build time)
CODE_SIZE = 0x2F9000
TEXT_SIZE, RO_ADDR, RO_SIZE = 0x288BD8, 0x389000, 0x65E50
DATA_ADDR, DATA_SIZE, BSS_SIZE = 0x3EF000, 0x9170, 0x3CBD0
TEXT_END = BASE + TEXT_SIZE                 # 0x388BD8
TEXT_PAGE_END = BASE + 0x289000             # 0x389000
CAVE_LO, CAVE_HI = 0x388E10, TEXT_PAGE_END  # D2 range 0x388E00..0x388FFF; 0x388E10 keeps >= 0x110 B above the
LUMA_PAYLOAD_MAX = max(L.ROMFS_REDIR_SIZE.values())  # largest Luma payload (0x11C, v10.1..v13.0.2; 0x114 since)
MIN_MARGIN = 0x110

SYMS = {  # name -> (mangled substring, expected address)
    "ad::fw::TaskBase::init": ("_ZN2ad2fw8TaskBase4initERKNS1_9InitParamE", 0x28068C),
    "nn::os::CTR::IsRunOnSnake": ("_ZN2nn2os3CTR12IsRunOnSnakeEv", 0x2844AC),
    "ad::fw::TaskBase::isFps30": ("_ZNK2ad2fw8TaskBase7isFps30Ev", 0x25EDD0),
}
IS_RUN_ON_SNAKE = 0x2844AC

INIT_HOOK = 0x28092C
INIT_CTX = (0x280918, "3e00d4e5000050e34a70c4154a80c4053c10d4e5" "3d00d4e5" "4670c4e54410c4e57863c4e54500c4e5f88fbde8")
CRD_HOOK = 0x2E8B9C
CRD_CTX = (0x2E8B64, "041090e5e4009fe57f90a0e3305191e5014090e70910a0e10400a0e10223f9ebcc109fe50930a0e1"
                     "0420a0e1050081e70510a0e1fe22f9eb" "00f020e3" "00f020e3210000ea")

CLASSES = {  # allow-list names: vptr at TaskBase::init time, RTTI name, what it covers
    "fld": (0x3E3B3C, "N3fld6SystemE", "fld::System: field, events, title screen, staff roll"),
    "btl": (0x3E10C4, "N3btl4MainE", "btl::Main: battles"),
    "kj": (0x3DEBD8, "N2kj8KJSystemE", "kj::KJSystem: Bowser Jr.'s Journey"),
    "menu": (0x3E4874, "N4msys9MTaskBaseE", "msys::MTaskBase: MainMenu/KJMenu/ShopMenu/BCat/LoadMenu/SaveMenu/"
                                             "AttackMiniGame/Colosseum (init runs inside the MTaskBase ctor)"),
}
DEFAULT_ALLOW = ["fld", "btl", "kj", "menu"]
TASKBASE_RTTI = "N2ad2fw8TaskBaseE"

# --field-vm30 (IMPL3, README §10-§14)
VT_ES, VT_RES = 0x3E1784, 0x3E303C                    # fld::EventSystem / fld::ResidentEventSystem address points
VT_RTTI = {VT_ES: "N3fld11EventSystemE", VT_RES: "N3fld19ResidentEventSystemE"}
STEP_ES_ORIG, STEP_RES_ORIG = 0x2A8AF0, 0x2D9914       # slot +0x34: GlobalEvent+0x14 = step
EXEC_ORIG, SYSVAR_ORIG = 0x2B81A8, 0x2E225C            # slot +0x20 (both), slot +0x2C (both)
FV_SLOTS = [  # (id, vtable, slot offset, original target, wrapper label)
    ("es_step", VT_ES, 0x34, STEP_ES_ORIG, "fld60_step_es"),
    ("res_step", VT_RES, 0x34, STEP_RES_ORIG, "fld60_step_res"),
    ("es_exec", VT_ES, 0x20, EXEC_ORIG, "fld60_exec"),
    ("res_exec", VT_RES, 0x20, EXEC_ORIG, "fld60_exec"),
    ("es_sysvar", VT_ES, 0x2C, SYSVAR_ORIG, "fld60_sysvar"),
    ("res_sysvar", VT_RES, 0x2C, SYSVAR_ORIG, "fld60_sysvar"),
]
LATCH = 0x434F00                                       # 16 bytes {trg, rls, touch bits, frame tag}, impl_rwscan.py
STACK_WINDOW = 0x8000                                  # exheader main-thread stack size
BAI_SRC = "work/fps60/build/bai/romfs/BAI/BAI.dat"
BAI_SHA256 = "c681a963b8428128a2d9133c39911f9f2acf5a53e83dff0a097de8fbe750fbb6"


def rel(p: str) -> str:
    return os.path.join(ROOT, p)


def sha256(b: bytes) -> str:
    return hashlib.sha256(b).hexdigest()


def rd32(img: bytes, addr: int) -> int:
    return struct.unpack_from("<I", img, addr - BASE)[0]


def cstr(img: bytes, addr: int) -> str:
    o = addr - BASE
    if not 0 <= o < len(img):
        return ""
    e = img.index(b"\0", o)
    return img[o:e].decode("ascii", "replace")


def rtti_chain(img: bytes, vptr: int) -> list[str]:
    """Class chain from the vtable's type_info (vptr-4): __si_class_type_info base at +8,
    __vmi_class_type_info first base at +16."""
    lo, hi = RO_ADDR, DATA_ADDR + DATA_SIZE
    if not lo <= vptr < RO_ADDR + RO_SIZE:
        return []
    ti, out, seen = rd32(img, vptr - 4), [], set()
    while lo <= ti < hi and ti not in seen:
        seen.add(ti)
        out.append(cstr(img, rd32(img, ti + 4)))
        nxt = rd32(img, ti + 8)
        if lo <= nxt < hi:
            ti = nxt
        elif 0 < rd32(img, ti + 12) < 16:
            ti = rd32(img, ti + 16)
        else:
            break
    return out


# ---------------------------------------------------------------------------------------------------------
# assembly
# ---------------------------------------------------------------------------------------------------------
def cave_lines(allow: list[int], snake: bool, credits: bool, fieldvm: bool = False) -> list[str]:
    s = [
        "eng60_init:",                       # bl from TaskBase::init 0x28092C; r4 = task, r1 live (+0x3C)
        "push {r1, r2, r3, lr}",             # 16 bytes: sp stays 8-aligned (init pushed 40)
        "mov r0, #0",
        "strb r0, [r4, #0x41]",              # marker = 0 (InitParam tail padding, unused by the game)
        "ldrb r0, [r4, #0x3d]",              # persistent fps mode (InitParam+0x31 copy)
        "cmp r0, #1",
        "bne eng60_done",                    # only 30fps tasks are candidates; r0 = mode
        "ldr r2, [r4]",                      # vptr at init time
        "adr r3, eng60_allow",
        "eng60_scan:",
        "ldr r1, [r3], #4",
        "cmp r1, #0",
        "beq eng60_keep",
        "cmp r1, r2",
        "bne eng60_scan",
    ]
    if snake:
        s += [f"bl #{IS_RUN_ON_SNAKE:#x}", "cmp r0, #0", "beq eng60_keep"]  # New 3DS only
    s += [
        "mov r0, #0",
        "strb r0, [r4, #0x3d]",              # 60fps
        "mov r1, #1",
        "strb r1, [r4, #0x41]",              # marker = promoted
        "b eng60_done",
        "eng60_keep:",
        "ldrb r0, [r4, #0x3d]",
        "eng60_done:",
        "pop {r1, r2, r3, pc}",              # r0 = mode -> init stores it to +0x45
    ]
    if credits:
        s += [
            "crd60_fix:",                    # bl from 0x2E8B9C (was nop) after fld::StaffrollCtrl::init
            "ldrb r0, [r5, #0x45]",          # r5 = fld::System* passed to init; fps mode of this frame
            "cmp r0, #0",
            "bxne lr",
            "add r0, r5, #0x1000",
            "ldr r0, [r0, #0xb3c]",          # ctrl = fld::System+0x1B3C (stored at 0x2E8B90)
            "cmp r0, #0",
            "bxeq lr",
            "vldr s0, [r0, #0x28]",          # scroll speed px/update (GetParamStaffroll()+0x18 = 2.0)
            "vldr s1, crd60_half",
            "vmul.f32 s0, s0, s1",
            "vstr s0, [r0, #0x28]",
            "bx lr",
        ]
    s += ["eng60_allow:"] + [f".word {v:#x}" for v in allow] + [".word 0"]
    if credits:
        s += ["crd60_half:", ".word 0x3f000000"]
    if fieldvm:
        s += fieldvm_lines()
    return s


def fieldvm_lines() -> list[str]:
    """F1-F3 wrappers (field60.md §6.1, README §12). AAPCS: only r0-r3, ip, lr(saved) and flags are touched
    outside the saved r4-r8; no VFP register except s0 in F1 (doubling the argument)."""
    e, v = f"#{EXEC_ORIG:#x}", f"#{SYSVAR_ORIG:#x}"
    return [
        # F1: slot +0x34 (r0 = event system, s0 = field step): under G the event step is doubled
        "fld60_step_es:",
        "ldr ip, fld60_lit_step_es",
        "b fld60_step",
        "fld60_step_res:",
        "ldr ip, fld60_lit_step_res",
        "fld60_step:",
        "ldr r1, [r0, #4]",                 # Main (set by the system's init, vt+8)
        "cmp r1, #0",
        "bxeq ip",
        "ldr r1, [r1, #0x130]",             # fld::System
        "cmp r1, #0",
        "bxeq ip",
        "ldrb r1, [r1, #0x45]",             # fps mode of this frame (0 = 60fps)
        "cmp r1, #0",
        "vaddeq.f32 s0, s0, s0",            # G: step x2 (exact)
        "bx ip",                            # original(r0, s0)
        # F2: slot +0x20 (r0 = event system, r1 = LocalEvent): under G run scripts on even frames only
        "fld60_exec:",
        "sub ip, r1, sp",
        f"cmp ip, #{STACK_WINDOW:#x}",
        f"blo {e}",                         # LocalEvent on the stack = one-shot synchronous run: never gated
        "ldr ip, [r0, #4]",
        "cmp ip, #0",
        f"beq {e}",
        "ldr ip, [ip, #0x130]",
        "cmp ip, #0",
        f"beq {e}",
        "ldrb r2, [ip, #0x45]",
        "cmp r2, #0",
        f"bne {e}",                         # G false: the original, arguments intact
        "ldr r2, [ip, #0x578]",             # ad::fw::TaskBase frame counter of fld::System
        "tst r2, #1",
        f"beq {e}",                         # even frame: run (event step doubled by F1)
        "ldr r3, fld60_lit_latch",          # odd frame: latch this frame's edges and skip the script
        "str r2, [r3, #0xc]",               # tag = this (odd) frame number
        "add ip, ip, #0x1000",
        "ldr r0, [ip, #0xb00]",             # pad struct P = *(fld::System+0x1B00)
        "ldr r2, [r0, #8]",                 # trg
        "str r2, [r3]",
        "ldr r2, [r0, #0xc]",               # rls
        "str r2, [r3, #4]",
        "ldr r0, [ip, #0xb08]",             # touch struct T = *(fld::System+0x1B08)
        "ldr r2, [r0, #8]",
        "and r2, r2, #0x3c",                # touch-down / touch-up / repeat / changed bits
        "str r2, [r3, #8]",
        "ldr r0, [r1, #0x814]",             # status as the original's early-out: (x & 0x7FFFFFF) >> 25
        "lsl r0, r0, #5",
        "lsr r0, r0, #0x1e",
        "bx lr",
        # F3: slot +0x2C (r0 = event system, r1 = GlobalEvent, r2 = LocalEvent, r3 = id) -> s0
        "fld60_sysvar:",
        "sub ip, r3, #0x7000",
        "sub ip, ip, #0x2f",
        "cmp ip, #0x12",
        f"bhi {v}",                         # only $702F..$7041 read the pad/touch structs
        "ldr ip, [r0, #4]",
        "cmp ip, #0",
        f"beq {v}",
        "ldr ip, [ip, #0x130]",
        "cmp ip, #0",
        f"beq {v}",
        "push {r4, r5, r6, r7, r8, lr}",    # 24 bytes: sp stays 8-aligned for the call
        "ldrb r4, [ip, #0x45]",
        "cmp r4, #0",
        "bne fld60_sv_plain",
        "ldr r4, [ip, #0x578]",
        "tst r4, #1",
        "bne fld60_sv_plain",               # odd frame: no latch (gated scripts do not run)
        "ldr r5, fld60_lit_latch",
        "ldr r6, [r5, #0xc]",
        "sub r4, r4, #1",
        "cmp r6, r4",
        "bne fld60_sv_plain",               # latch not saved in the previous frame: ignore it
        "add ip, ip, #0x1000",
        "ldr r6, [ip, #0xb00]",             # P
        "ldr r7, [ip, #0xb08]",             # T
        "ldr r4, [r6, #8]",
        "ldr lr, [r5]",
        "orr lr, lr, r4",
        "str lr, [r6, #8]",                 # P.trg |= latch.trg
        "ldr r8, [r6, #0xc]",
        "ldr lr, [r5, #4]",
        "orr lr, lr, r8",
        "str lr, [r6, #0xc]",               # P.rls |= latch.rls
        "ldr lr, [r5, #8]",
        "ldr r5, [r7, #8]",
        "orr lr, lr, r5",
        "str lr, [r7, #8]",                 # T bits |= latch.touch
        f"bl {v}",
        "str r4, [r6, #8]",                 # restore exactly; s0 (result) untouched
        "str r8, [r6, #0xc]",
        "str r5, [r7, #8]",
        "pop {r4, r5, r6, r7, r8, pc}",
        "fld60_sv_plain:",
        "pop {r4, r5, r6, r7, r8, lr}",
        f"b {v}",
        "fld60_lit_step_es:", f".word {STEP_ES_ORIG:#x}",
        "fld60_lit_step_res:", f".word {STEP_RES_ORIG:#x}",
        "fld60_lit_latch:", f".word {LATCH:#x}",
    ]


def layout(lines: list[str], base: int) -> tuple[dict, list[tuple[int, str]]]:
    labels, items, a = {}, [], base
    for ln in lines:
        if ln.endswith(":"):
            labels[ln[:-1]] = a
        else:
            items.append((a, ln))
            a += 4
    return labels, items


def ks_asm(src: str, addr: int) -> bytes:
    ks = keystone.Ks(keystone.KS_ARCH_ARM, keystone.KS_MODE_ARM)
    enc, _ = ks.asm(src, addr)
    return bytes(enc)


BRANCHES = {"b", "bl"} | {"b" + c for c in ("eq", "ne", "cs", "cc", "hs", "lo", "mi", "pl", "vs", "vc", "hi", "ls",
                                            "ge", "lt", "gt", "le")}


def expected_text(addr: int, ln: str, labels: dict) -> tuple[str, str] | None:
    mn, _, ops = ln.partition(" ")
    ops = ops.strip()
    if mn == ".word":
        return None
    if mn in BRANCHES and not ops.startswith("#"):
        return mn, f"#{labels[ops]:#x}"
    if mn == "adr":
        reg, lab = [x.strip() for x in ops.split(",")]
        return "add", f"{reg}, pc, #{labels[lab] - (addr + 8):#x}"
    if mn == "vldr" and "[" not in ops:
        reg, lab = [x.strip() for x in ops.split(",")]
        return "vldr", f"{reg}, [pc, #{labels[lab] - ((addr + 8) & ~3):#x}]"
    if mn == "ldr" and "[" not in ops and "#" not in ops and "=" not in ops:
        reg, lab = [x.strip() for x in ops.split(",")]
        d = labels[lab] - (addr + 8)
        return "ldr", f"{reg}, [pc, #{d:#x}]" if d >= 0 else f"{reg}, [pc, #-{-d:#x}]"
    return mn, ops


def assemble_checked(lines: list[str], base: int) -> tuple[bytes, dict, list[str]]:
    """keystone assemble + capstone round trip: every instruction must decode to the intended text
    (branch / pc-relative targets resolved to the label addresses)."""
    labels, items = layout(lines, base)
    code = ks_asm("\n".join(ln if not ln.endswith(":") else ln for ln in lines), base)
    assert len(code) == 4 * len(items), (len(code), len(items))
    md = capstone.Cs(capstone.CS_ARCH_ARM, capstone.CS_MODE_ARM)
    listing = []
    for a, ln in items:
        word = code[a - base:a - base + 4]
        exp = expected_text(a, ln, labels)
        got = next(md.disasm(word, a), None)
        if exp is not None:
            if got is None or (got.mnemonic, got.op_str) != exp:
                raise SystemExit(f"round-trip mismatch at {a:#x}: want {exp}, got "
                                 f"{(got.mnemonic, got.op_str) if got else None}")
            listing.append(f"{a:08x}: {word.hex()}  {got.mnemonic} {got.op_str}")
        else:
            listing.append(f"{a:08x}: {word.hex()}  .word {struct.unpack('<I', word)[0]:#010x}")
    lab_by_addr = {v: k for k, v in labels.items()}
    listing = [(f"{lab_by_addr[int(x[:8], 16)]}:\n" if int(x[:8], 16) in lab_by_addr else "") + x for x in listing]
    return code, labels, listing


def one(src: str, addr: int, want: tuple[str, str]) -> bytes:
    b = ks_asm(src, addr)
    got = next(capstone.Cs(capstone.CS_ARCH_ARM, capstone.CS_MODE_ARM).disasm(b, addr))
    assert (got.mnemonic, got.op_str) == want, (got.mnemonic, got.op_str, want)
    return b


# ---------------------------------------------------------------------------------------------------------
# build
# ---------------------------------------------------------------------------------------------------------
def parse_allow(spec: str | None) -> list[tuple[str, int]]:
    names = DEFAULT_ALLOW if not spec else [x.strip() for x in spec.split(",") if x.strip()]
    out = []
    for n in names:
        if n in CLASSES:
            out.append((n, CLASSES[n][0]))
        else:
            out.append((n, int(n, 16)))
    return out


def check_context(img: bytes, ctx: tuple[int, str], what: str) -> None:
    a, hx = ctx
    want = bytes.fromhex(hx)
    got = img[a - BASE:a - BASE + len(want)]
    if got != want:
        raise SystemExit(f"ABORT: original bytes of {what} at {a:#x} differ from the expected v1.2 code:\n"
                         f"  want {want.hex()}\n  got  {got.hex()}")


def build(args) -> dict:
    src = open(rel(P_V12), "rb").read()
    if len(src) != CODE_SIZE:
        raise SystemExit(f"ABORT: {P_V12} is {len(src):#x} bytes, expected {CODE_SIZE:#x}")
    log: list[str] = []

    # symbols from static.crs (lead tool, read-only)
    syms = static_symbols(rel(P_CRS))
    for name, (mangled, addr) in SYMS.items():
        if syms.get(mangled) != addr:
            raise SystemExit(f"ABORT: symbol {name} ({mangled}) = {syms.get(mangled)}, expected {addr:#x}")
    log.append("symbols (static.crs exports): " + ", ".join(f"{n} {a:#x}" for n, (_, a) in SYMS.items()))
    init_end = INIT_CTX[0] + len(bytes.fromhex(INIT_CTX[1]))
    assert SYMS["ad::fw::TaskBase::init"][1] <= INIT_HOOK < init_end

    # original bytes
    check_context(src, INIT_CTX, "TaskBase::init tail")
    credits = args.credits_fix and not args.field_vm30      # under --field-vm30 the roll needs no speed change
    if args.credits_fix:
        check_context(src, CRD_CTX, "field event cmd 0x280 sub-op 0")
    slack = src[TEXT_END - BASE:TEXT_PAGE_END - BASE]
    if slack != bytes(len(slack)):
        raise SystemExit("ABORT: the .text page padding 0x388BD8..0x389000 is not all zero")
    snake_bytes = src[IS_RUN_ON_SNAKE - BASE:IS_RUN_ON_SNAKE - BASE + 4].hex()
    assert snake_bytes == "38402de9", snake_bytes  # push {r3, r4, r5, lr}
    log.append("original bytes: TaskBase::init tail 0x280918..0x280944, event handler 0x2E8B64..0x2E8BA8"
               f"{'' if args.credits_fix else ' (not used)'}, .text padding zero: OK")
    if args.field_vm30:
        for vt, name in VT_RTTI.items():
            chain = rtti_chain(src, vt)
            if not chain or chain[0] != name:
                raise SystemExit(f"ABORT: vtable {vt:#x} RTTI {chain} != {name}")
        for sid, vt, off, orig, _lab in FV_SLOTS:
            if rd32(src, vt + off) != orig:
                raise SystemExit(f"ABORT: vtable slot {sid} {vt + off:#x} = {rd32(src, vt + off):#x}, expected {orig:#x}")
        for orig, prologue in ((STEP_ES_ORIG, "70402de9"), (STEP_RES_ORIG, "70402de9"), (EXEC_ORIG, "f0402de9"),
                               (SYSVAR_ORIG, "30402de9")):
            if src[orig - BASE:orig - BASE + 4].hex() != prologue:
                raise SystemExit(f"ABORT: unexpected prologue at {orig:#x}")
        log.append("original words: vtable slots " + ", ".join(f"{vt + off:#x}={orig:#x}" for _s, vt, off, orig, _l in FV_SLOTS)
                   + f" (RTTI {', '.join(VT_RTTI.values())}); slot targets' prologues: OK")
        if args.credits_fix:
            log.append("--credits-fix with --field-vm30: crd60_fix NOT installed (fld::StaffrollCtrl::update is called only "
                       "by field command 0x280 sub-op 1 at 0x2E8BB8, i.e. once per script tick = 30/s under --field-vm30)")

    # allow-list
    allow = parse_allow(args.allow)
    allow_info = []
    for n, v in allow:
        chain = rtti_chain(src, v)
        if TASKBASE_RTTI not in chain:
            raise SystemExit(f"ABORT: allow-list entry {n} {v:#x} is not a static ad::fw::TaskBase vtable "
                             f"(RTTI chain {chain})")
        if n in CLASSES and chain[0] != CLASSES[n][1]:
            raise SystemExit(f"ABORT: {n} {v:#x} RTTI {chain[0]} != {CLASSES[n][1]}")
        allow_info.append({"name": n, "vptr": f"{v:#x}", "rtti": chain,
                           "covers": CLASSES[n][2] if n in CLASSES else "custom"})
    log.append("allow-list: " + ", ".join(f"{a['name']} {a['vptr']} {a['rtti'][0]}" for a in allow_info))

    # assemble
    lines = cave_lines([v for _, v in allow], snake=not args.no_snake, credits=credits, fieldvm=args.field_vm30)
    cave, labels, listing = assemble_checked(lines, CAVE_LO)
    if CAVE_LO + len(cave) > CAVE_HI:
        raise SystemExit(f"ABORT: cave does not fit ({len(cave):#x} bytes from {CAVE_LO:#x}, limit {CAVE_HI:#x})")
    hook = one(f"bl #{labels['eng60_init']:#x}", INIT_HOOK, ("bl", f"#{labels['eng60_init']:#x}"))
    parts = ["eng60_init"] + (["crd60_fix"] if credits else []) + ["allow-list"] + \
        (["fld60_step_es/res", "fld60_exec", "fld60_sysvar"] if args.field_vm30 else [])
    patches = [
        {"id": "init_hook", "addr": INIT_HOOK, "orig": "3d00d4e5", "orig_asm": "ldrb r0, [r4, #0x3d]",
         "new": hook.hex(), "new_asm": f"bl #{labels['eng60_init']:#x}",
         "why": "decide the fps mode inside ad::fw::TaskBase::init, before the first frame (D1)"},
        {"id": "cave", "addr": CAVE_LO, "orig": "00" * len(cave), "orig_asm": f"{len(cave)} zero bytes (.text page padding)",
         "new": cave.hex(), "new_asm": " + ".join(parts),
         "why": "code cave in the last RX page of .text, above Luma's LayeredFS payload (D2)"},
    ]
    if credits:
        crd = one(f"bl #{labels['crd60_fix']:#x}", CRD_HOOK, ("bl", f"#{labels['crd60_fix']:#x}"))
        patches.append({"id": "credits_hook", "addr": CRD_HOOK, "orig": "00f020e3", "orig_asm": "nop",
                        "new": crd.hex(), "new_asm": f"bl #{labels['crd60_fix']:#x}",
                        "why": "staff roll: halve fld::StaffrollCtrl+0x28 (px per update) when the field runs at 60"})
    if args.field_vm30:
        whys = {0x34: "F1: event step x2 under G (wait(n) on the 30fps schedule)",
                0x20: "F2: run the LocalEvent only on even fld::System+0x578 frames under G; latch odd-frame edges",
                0x2C: "F3: OR the latched pad/touch edges into the structs around system-variable reads"}
        for sid, vt, off, orig, lab in FV_SLOTS:
            patches.append({"id": f"vt_{sid}", "addr": vt + off, "orig": struct.pack("<I", orig).hex(),
                            "orig_asm": f".word {orig:#010x} ({VT_RTTI[vt]} slot +{off:#x})",
                            "new": struct.pack("<I", labels[lab]).hex(), "new_asm": f".word {labels[lab]:#010x} ({lab})",
                            "why": whys[off]})
    for p in patches:
        o = p["addr"] - BASE
        assert src[o:o + len(p["new"]) // 2].hex() == p["orig"], p["id"]
    img = bytearray(src)
    for p in patches:
        o = p["addr"] - BASE
        img[o:o + len(p["new"]) // 2] = bytes.fromhex(p["new"])
        p["file_offset"] = f"{o:#x}"
        p["addr"] = f"{p['addr']:#x}"
    img = bytes(img)
    ranges = sorted((int(p["file_offset"], 16), len(p["new"]) // 2) for p in patches)
    assert all(a + n <= c for (a, n), (c, _m) in zip(ranges, ranges[1:])), "overlapping patches"
    assert all(src[o:o + n] != img[o:o + n] for o, n in ranges)
    outside = bytearray(img)
    for o, n in ranges:
        outside[o:o + n] = src[o:o + n]
    assert bytes(outside) == src, "bytes changed outside the declared patch ranges"
    changed = ranges
    return {"src": src, "img": img, "patches": patches, "labels": labels, "listing": listing,
            "allow": allow_info, "log": log, "changed": changed, "cave_len": len(cave),
            "credits_installed": credits}


# ---------------------------------------------------------------------------------------------------------
# verification
# ---------------------------------------------------------------------------------------------------------
def overlaps(a0: int, a1: int, b0: int, b1: int) -> bool:
    return a0 < b1 and b0 < a1


def verify(b: dict, ips: bytes, bps: bytes, args) -> tuple[list[str], dict]:
    src, img = b["src"], b["img"]
    out, res = [], {}
    ok_all = True

    def rec(key, ok, msg):
        nonlocal ok_all
        res[key] = {"ok": bool(ok), "detail": msg}
        out.append(("PASS " if ok else "FAIL ") + f"[{key}] {msg}")
        ok_all &= bool(ok)

    rec("selftest", True, L.self_test()[0])

    # V1 exheader of the installed-update CIA = the constants used here
    cias = impl_exheader.project_cias()
    ex12 = impl_exheader.read_cia_ncch(cias["v12_update"])
    ex10 = impl_exheader.read_cia_ncch(cias["v10_base"])
    good = (ex12["text"]["size"] == TEXT_SIZE and ex12["rodata"]["size"] == RO_SIZE and ex12["data"]["size"] == DATA_SIZE
            and ex12["bss_size"] == BSS_SIZE and ex12["luma_total_size"] == CODE_SIZE
            and ex12["aci_title_id"] == TITLE_ID and ex12["remaster_version"] == 2)
    rec("exheader", good, f"update CIA {ex12['program_id']} v{ex12['remaster_version']}: text {ex12['text']['size']:#x} "
                          f"({ex12['text']['num_max_pages']} pages), ro {ex12['rodata']['size']:#x}, data {ex12['data']['size']:#x}, "
                          f"bss {ex12['bss_size']:#x}; Luma code buffer {ex12['luma_total_size']:#x}; ACI title id {ex12['aci_title_id']} "
                          f"(Luma folder); base CIA v1.0 text {ex10['text']['size']:#x}")

    # V2 the analysis binary is exactly what both loaders decompress from the v1.2 ExeFS
    comp12 = open(rel(P_EXEFS_V12), "rb").read()
    comp10 = open(rel(P_EXEFS_V10), "rb").read()
    lbuf = bytearray(CODE_SIZE)
    lbuf[:len(comp12)] = comp12
    lsize = L.luma_lzss_decompress(lbuf, len(comp12))
    az12 = L.azahar_lzss_decompress(comp12)
    v10 = open(rel(P_V10), "rb").read()
    lbuf10 = bytearray(CODE_SIZE)
    lbuf10[:len(comp10)] = comp10
    lsize10 = L.luma_lzss_decompress(lbuf10, len(comp10))
    rec("decompress", lsize == CODE_SIZE and bytes(lbuf) == src and az12 == src and lsize10 == CODE_SIZE
        and bytes(lbuf10) == v10,
        f"exefs2/.code ({len(comp12)} B) -> Luma lzss port {lsize:#x} B == Azahar port == {P_V12}; exefs/.code (v1.0) "
        f"-> {lsize10:#x} B == {P_V10}. CRC32 v1.2 {L.crc32(src):08X}, v1.0 {L.crc32(v10):08X}")
    res["crc32_v12"] = f"{L.crc32(src):08X}"
    res["crc32_v10"] = f"{L.crc32(v10):08X}"

    # V3 RO relocation targets (static.crs import patches are written by the RO module at CRO link time)
    crs = CRO.load(rel(P_CRS))
    targets = []
    for imp in crs.named_imports():
        targets += [(crs.segments[r.seg].offset + r.off, "named " + imp.name) for r in imp.relocs]
    for m in crs.import_modules():
        for _i, rl in m["indexed"]:
            targets += [(crs.segments[r.seg].offset + r.off, "indexed " + m["name"]) for r in rl]
        for _s, _o, rl in m["anonymous"]:
            targets += [(crs.segments[r.seg].offset + r.off, "anon " + m["name"]) for r in rl]
    targets += [(crs.segments[r.seg].offset + r.off, "internal") for r in crs.internal_relocs()]
    hits = [(hex(t), why) for t, why in targets for o, n in b["changed"] if overlaps(t, t + 4, BASE + o, BASE + o + n)]
    rec("ro_relocs", not hits, f"{len(targets)} static.crs relocation targets, none inside the patched bytes"
        if not hits else f"patched bytes are RO relocation targets: {hits[:5]}")

    # V4 appliers on v1.2 (each loader's code buffer)
    def az_buf(code):
        return bytearray(code) + bytearray((BSS_SIZE + 0xFFF) & ~0xFFF)

    want_az = bytes(az_buf(img))
    r = {}
    t = bytearray(src)
    r["luma_v10.1-v13.4_ips"] = L.luma_ips_apply_v134(t, CODE_SIZE, ips)[0] and bytes(t) == img
    t = bytearray(src)
    ok, _, nsz = L.luma_ips_apply_master(t, CODE_SIZE, CODE_SIZE, ips)
    r["luma_master_ips"] = ok and nsz == CODE_SIZE and bytes(t) == img
    t = az_buf(src)
    r["azahar_ips"] = L.azahar_ips_apply(t, ips) == "Success" and bytes(t) == want_az
    t = bytearray(src)
    r["luma_bps"] = L.luma_bps_apply(t, CODE_SIZE, bps)[0] and bytes(t) == img
    t = az_buf(src)
    r["azahar_bps"] = L.azahar_bps_apply(t, bps) == "Success" and bytes(t) == want_az
    rec("apply_v12", all(r.values()), "v1.2 code -> patched.code.bin byte-exact with: " +
        ", ".join(f"{k} {'ok' if v else 'FAIL'}" for k, v in r.items()))

    # V5 appliers on v1.0 (update not installed): BPS must refuse without touching the buffer, IPS cannot
    t = bytearray(v10)
    lok, ldet = L.luma_bps_apply(t, CODE_SIZE, bps)
    l_untouched = bytes(t) == v10
    t = az_buf(v10)
    ast = L.azahar_bps_apply(t, bps)
    a_untouched = bytes(t) == bytes(az_buf(v10))
    t = bytearray(v10)
    iok = L.luma_ips_apply_v134(t, CODE_SIZE, ips)[0]
    md = capstone.Cs(capstone.CS_ARCH_ARM, capstone.CS_MODE_ARM)
    o = INIT_HOOK - BASE
    v10_at_hook = next(md.disasm(v10[o:o + 4], INIT_HOOK))
    rec("refuse_v10", (not lok) and l_untouched and ast == "ErrorPatchesInvalidTitle" and a_untouched,
        f"BPS on v1.0: Luma '{ldet}' (buffer untouched {l_untouched}); Azahar {ast} (buffer untouched {a_untouched}). "
        f"IPS on v1.0 would apply silently ({iok}): v1.0 has '{v10_at_hook.mnemonic} {v10_at_hook.op_str}' at "
        f"{INIT_HOOK:#x}, so code.ips on a v1.0 install corrupts the game")
    res["v10_at_hook"] = f"{v10_at_hook.mnemonic} {v10_at_hook.op_str}"

    # V6 Luma LayeredFS (runs after BPS/IPS): same symbols, payload/path clear of every patched byte
    s0 = L.luma_find_layeredfs_symbols(src, TEXT_SIZE)
    s1 = L.luma_find_layeredfs_symbols(img, TEXT_SIZE)
    clash = []
    for name, size in L.ROMFS_REDIR_SIZE.items():
        pl = L.luma_layeredfs_placement(TEXT_SIZE, RO_SIZE, DATA_SIZE, RO_ADDR, DATA_ADDR, size)
        regions = [("payload " + name, *pl["payload"]), ("path", *pl["path"])]
        regions += [(f"hook {k}", s1[k], s1[k] + 4) for k in ("fsOpenFileDirectly", "fsTryOpenFile")]
        regions += [(f"substituted {k}", s1[k], s1[k] + 4) for k in ("fsOpenFileDirectly", "fsTryOpenFile")]
        for rn, a0, a1 in regions:
            for po, pn in b["changed"]:
                if overlaps(a0, a1, po, po + pn):
                    clash.append((rn, hex(BASE + a0), hex(BASE + po)))
    # simulate the full Luma chain on the real ExeFS: decompress -> BPS -> LayeredFS -> our bytes intact?
    chain = bytearray(CODE_SIZE)
    chain[:len(comp12)] = comp12
    L.luma_lzss_decompress(chain, len(comp12))
    bok = L.luma_bps_apply(chain, CODE_SIZE, bps)[0]
    lfs = L.luma_apply_layeredfs(chain, TEXT_SIZE, RO_SIZE, DATA_SIZE, RO_ADDR, DATA_ADDR, LUMA_PAYLOAD_MAX, TITLE_ID)
    intact = all(chain[po:po + pn] == img[po:po + pn] for po, pn in b["changed"])
    pa, pb = lfs["placement"]["payload"]
    margin = (CAVE_LO - BASE) - pb
    syms_same = {k: v for k, v in s0.items()} == {k: v for k, v in s1.items()}
    rec("luma_layeredfs", s0["found"] == 5 and syms_same and not clash and bok and lfs["ok"] and intact,
        f"LayeredFS symbols found {s1['found']}/5, identical before/after patch "
        f"(fsOpenFileDirectly {BASE + s1['fsOpenFileDirectly']:#x}, fsTryOpenFile {BASE + s1['fsTryOpenFile']:#x}, "
        f"fsMountArchive {BASE + s1['fsMountArchive']:#x}, fsRegisterArchive {BASE + s1['fsRegisterArchive']:#x}, "
        f"fsUnMountArchive {BASE + s1['fsUnMountArchive']:#x}); payload {BASE + pa:#x}..{BASE + pb:#x} "
        f"(worst case {LUMA_PAYLOAD_MAX:#x} B), path {BASE + lfs['placement']['path'][0]:#x}..; "
        f"cave {CAVE_LO:#x} = payload end + {margin:#x}; ExeFS->lzss->BPS->LayeredFS chain leaves all patched "
        f"bytes intact: {intact}" + (f"; CLASH {clash}" if clash else ""))
    res["layeredfs_symbols"] = {k: (hex(BASE + v) if isinstance(v, int) and v != L.NONE32 and k != "found" else v)
                                for k, v in s1.items()}

    # V7 Azahar loader chain: decompress -> + bss pages -> ApplyCodePatch (first file found) with code.bps
    az = bytearray(L.azahar_lzss_decompress(comp12)) + bytearray((BSS_SIZE + 0xFFF) & ~0xFFF)
    st = L.azahar_bps_apply(az, bps)
    rec("azahar_chain", st == "Success" and bytes(az) == want_az,
        f"ExeFS -> LZSS -> code+bss ({len(az):#x} B) -> mods/{TITLE_ID}/code.bps: {st}, result == patched + zero bss")

    # V8 cave placement and free space
    used_hi = CAVE_LO + b["cave_len"]
    rec("cave", CAVE_LO >= TEXT_END + LUMA_PAYLOAD_MAX + MIN_MARGIN and 0x388E00 <= CAVE_LO and used_hi <= CAVE_HI,
        f"cave {CAVE_LO:#x}..{used_hi:#x} ({b['cave_len']:#x} B) inside the RX page 0x388000..0x389000; "
        f"free after the cave: {CAVE_HI - used_hi:#x} B ({used_hi:#x}..{CAVE_HI:#x}); free between Luma payload end "
        f"and cave: {CAVE_LO - (TEXT_END + LUMA_PAYLOAD_MAX):#x} B (keep it free)")

    # V9 --field-vm30: vtable slots, latch range, stack window, staff-roll update path
    if args.field_vm30:
        lab = b["labels"]
        slots = [(sid, vt + off, rd32(img, vt + off), lab[l]) for sid, vt, off, _o, l in FV_SLOTS]
        rtti_kept = all(rtti_chain(img, vt) == rtti_chain(src, vt) for vt in VT_RTTI)
        rec("fieldvm_slots", all(got == want for _s, _a, got, want in slots) and rtti_kept,
            "vtable slots -> wrappers: " + ", ".join(f"{s} {a:#x}={g:#x}" for s, a, g, _w in slots)
            + f"; RTTI of both vtables unchanged: {rtti_kept}")
        import impl_rwscan
        import contextlib
        import io
        buf = io.StringIO()
        with contextlib.redirect_stdout(buf):
            rc = impl_rwscan.main(["--lo", f"{LATCH:#x}", "--hi", f"{LATCH + 16:#x}"])
        last = [x for x in buf.getvalue().splitlines() if x.startswith("RESULT")]
        rec("latch", rc == 0 and impl_rwscan.BSS_END <= LATCH and LATCH + 16 <= 0x435000,
            f"latch {LATCH:#x}..{LATCH + 16:#x}: above bss end {impl_rwscan.BSS_END:#x}, inside the last RW page "
            f"(..0x435000); impl_rwscan: {last[0] if last else '?'}")
        rec("stack_window", ex12["stack_size"] == STACK_WINDOW,
            f"F2 never gates a LocalEvent in [sp, sp+{STACK_WINDOW:#x}) = exheader main-thread stack size "
            f"{ex12['stack_size']:#x}")
        if args.credits_fix:
            stub, callers = 0x1317A0, []
            for o in range(0, TEXT_SIZE, 4):
                w = struct.unpack_from("<I", src, o)[0]
                if (w >> 25) & 7 == 0b101:
                    imm = w & 0xFFFFFF
                    t = BASE + o + 8 + ((imm - 0x1000000) if imm & 0x800000 else imm) * 4
                    if t == stub:
                        callers.append(BASE + o)
            nop_kept = img[CRD_HOOK - BASE:CRD_HOOK - BASE + 4] == src[CRD_HOOK - BASE:CRD_HOOK - BASE + 4]
            rec("credits_by_vm", callers == [0x2E8BB8] and nop_kept and not b["credits_installed"],
                f"fld::StaffrollCtrl::update stub {stub:#x} is called only from {', '.join(hex(c) for c in callers)} "
                f"(field command 0x280 sub-op 1, a VM command), so under --field-vm30 the roll updates 30/s as at 30fps; "
                f"crd60_fix not installed, 0x2E8B9C still nop: {nop_kept}")
    res["all_ok"] = ok_all
    return out, res


def main(argv: list[str]) -> int:
    ap = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    ap.add_argument("--tag", required=True)
    ap.add_argument("--credits-fix", action="store_true")
    ap.add_argument("--allow", help="comma list of fld,btl,kj,menu or static vptrs (0x...)")
    ap.add_argument("--no-snake", action="store_true", help="TEST ONLY: promote without the New 3DS test")
    ap.add_argument("--skip-emu", action="store_true")
    ap.add_argument("--field-vm30", action="store_true", help="F1-F4: field event VM keeps its 30 Hz schedule at 60fps")
    ap.add_argument("--with-bai", action="store_true", help=f"copy the BTL2 BAI fix ({BAI_SRC}) into <tag>/romfs/")
    ap.add_argument("--out", help="write into this folder instead of work/fps60/build/<tag> (regression builds)")
    args = ap.parse_args(argv)
    if not args.tag.replace("-", "").replace("_", "").isalnum():
        raise SystemExit("tag must be alphanumeric (-/_ allowed)")
    outdir = os.path.abspath(args.out) if args.out else os.path.join(rel(OUT_ROOT), args.tag)
    if not args.out and args.tag in ("v1", "v1c", "v1cb", "bai"):
        raise SystemExit(f"refusing to overwrite the fixed tag {args.tag} (BRIEF3 W1); use --out <scratch dir>")
    if os.path.abspath(outdir).lower().startswith(rel("patch").lower()):
        raise SystemExit("refusing to write into patch/ (D6)")
    os.makedirs(outdir, exist_ok=True)

    b = build(args)
    ips = L.ips_encode([(o, b["img"][o:o + n]) for o, n in b["changed"]])
    bps = L.bps_encode(b["src"], b["img"], b["changed"])
    report, res = verify(b, ips, bps, args)
    if not args.skip_emu:
        import impl_emutest
        emu_lines, emu_ok = impl_emutest.run(b, args)
        report += emu_lines
        res["emu"] = {"ok": emu_ok}
        res["all_ok"] = res["all_ok"] and emu_ok
        if args.field_vm30:
            import impl_emufld
            fl, fok = impl_emufld.run(b, args)
            report += fl
            res["emu_fieldvm"] = {"ok": fok}
            res["all_ok"] = res["all_ok"] and fok

    files = {"code.bps": bps, "code.ips": ips, "patched.code.bin": b["img"]}
    for n, d in files.items():
        with open(os.path.join(outdir, n), "wb") as f:
            f.write(d)
    romfs = {}
    if args.with_bai:
        data = open(rel(BAI_SRC), "rb").read()
        ok_bai = sha256(data) == BAI_SHA256
        report.append(("PASS " if ok_bai else "FAIL ") + f"[bai] {BAI_SRC} sha256 {sha256(data)} "
                      f"{'==' if ok_bai else '!='} {BAI_SHA256} (BTL2 battle.md §7)")
        res["bai"] = {"ok": ok_bai}
        res["all_ok"] = res["all_ok"] and ok_bai
        if ok_bai:
            dst = os.path.join(outdir, "romfs", "BAI", "BAI.dat")
            os.makedirs(os.path.dirname(dst), exist_ok=True)
            with open(dst, "wb") as f:
                f.write(data)
            assert sha256(open(dst, "rb").read()) == BAI_SHA256
            romfs["romfs/BAI/BAI.dat"] = {"size": len(data), "sha256": BAI_SHA256, "from": BAI_SRC}
    manifest = {
        "tool": "scripts/fps60/build_fps60.py",
        "built": datetime.datetime.now().astimezone().isoformat(timespec="seconds"),
        "tag": args.tag,
        "flags": {"credits_fix": args.credits_fix, "allow": [a["name"] for a in b["allow"]],
                  "new3ds_test": not args.no_snake, "emu_tests": not args.skip_emu,
                  "field_vm30": args.field_vm30, "with_bai": args.with_bai},
        "credits": ("crd60_fix installed (update() runs 60/s at 60fps)" if b["credits_installed"] else
                    "covered by --field-vm30: update() runs once per script tick, 30/s; crd60_fix not installed"
                    if args.credits_fix else "no credits fix"),
        "target": {"game": "Mario & Luigi RPG3 DX JP", "version": "v1.2", "title_id": TITLE_ID,
                   "update_id": "0004000E001CA900"},
        "install": {"file": "code.bps",
                    "luma3ds": f"SD:/luma/titles/{TITLE_ID}/code.bps (Luma3DS >= v10.1, 'Enable game patching')",
                    "azahar": f"<user>/load/mods/{TITLE_ID}/code.bps (or exefs/code.bps)",
                    "romfs": "copy romfs/ overlay files (if any) into the same title folder's romfs/",
                    "never_both": "do not install code.ips next to code.bps (Azahar uses only exefs/code.ips if "
                                  "present; Luma applies BPS then IPS)"},
        "input": {"path": P_V12, "size": len(b["src"]), "sha256": sha256(b["src"]), "crc32": res.get("crc32_v12")},
        "outputs": {n: {"size": len(d), "sha256": sha256(d)} for n, d in files.items()},
        "romfs": romfs,
        "patches": b["patches"],
        "allow_list": b["allow"],
        "labels": {k: f"{v:#x}" for k, v in b["labels"].items()},
        "cave": {"start": f"{CAVE_LO:#x}", "end": f"{CAVE_LO + b['cave_len']:#x}", "size": b["cave_len"],
                 "free_after": CAVE_HI - CAVE_LO - b["cave_len"]},
        "latch": ({"addr": f"{LATCH:#x}", "size": 16, "layout": "+0 trg, +4 rls, +8 touch bits 2..5, +0xC frame tag"}
                  if args.field_vm30 else None),
        "verification": res,
    }
    with open(os.path.join(outdir, "manifest.json"), "w", encoding="utf-8") as f:
        json.dump(manifest, f, indent=1, ensure_ascii=False)
    text = [f"build {args.tag}  ({manifest['built']})", *b["log"], "", "cave listing:", *b["listing"], "",
            "patches:"]
    for p in b["patches"]:
        text.append(f"  {p['id']:13s} {p['addr']} (file {p['file_offset']}): {p['orig'][:16]}{'..' if len(p['orig']) > 16 else ''}"
                    f" '{p['orig_asm']}' -> {p['new'][:16]}{'..' if len(p['new']) > 16 else ''} '{p['new_asm']}'")
    text += ["", "verification:", *report, "", f"RESULT: {'ALL CHECKS PASSED' if res['all_ok'] else 'FAILED'}",
             f"outputs: {outdir}"]
    with open(os.path.join(outdir, "verify.txt"), "w", encoding="utf-8") as f:
        f.write("\n".join(text) + "\n")
    print("\n".join(text))
    return 0 if res["all_ok"] else 1


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
