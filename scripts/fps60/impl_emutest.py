"""IMPL: unicorn (ARM11 MPCore + VFP) tests of the fps60 code patch, called by build_fps60.py.

The patched image is mapped at 0x100000 (+ zero bss up to 0x435000). Fake TaskBase objects live at 0x30000000.
nn::os::CTR::IsRunOnSnake() is the game's real function, taken through its cached path
([0x3F7170] guard bit 1, [0x3F716C] = 0 Old 3DS / 1 New 3DS); the uncached path is an APT IPC call
(svc 0x32) that cannot run here.

A  cave called directly (bl from 0x28092C): every allowed / not-allowed vptr x fps mode {0,1,2} x {O3DS,N3DS}:
   +0x3D/+0x41/r0, r1-r11 and sp preserved, sp 8-aligned inside IsRunOnSnake, IsRunOnSnake called only for
   allowed mode-1 tasks, no memory written except the stack, +0x3D and +0x41.
B  TaskBase::init tail 0x280918..pop (fake 40-byte frame) on the patched AND the original image:
   +0x44/+0x45/+0x46/+0x4A/+0x378, callee-saved registers and sp after the return; patched == original except
   +0x3D/+0x45 (promoted) and +0x41 (marker).
C  --credits-fix: 0x2E8B9C..0x2E8BA4 with fld::System(r5)+0x45 in {0,1}, ctrl present / NULL.
"""
from __future__ import annotations

import struct

from unicorn import UC_ARCH_ARM, UC_HOOK_CODE, UC_HOOK_MEM_WRITE, UC_MODE_ARM, Uc
from unicorn import arm_const as A

BASE = 0x100000
MAP_END = 0x435000
STACK_LO, STACK_HI = 0x0FF00000, 0x10000000
HEAP, HEAP_SIZE = 0x30000000, 0x20000
STOP = 0x00F00000
SNAKE_FN, SNAKE_CACHE, SNAKE_GUARD = 0x2844AC, 0x3F716C, 0x3F7170
INIT_TAIL, INIT_HOOK = 0x280918, 0x28092C
CRD_START, CRD_END = 0x2E8B9C, 0x2E8BA4
REGS = [getattr(A, f"UC_ARM_REG_R{i}") for i in range(13)]
SENT = [0xA0A0A000 + 0x11 * i for i in range(13)]
OTHER_VPTRS = {"Boot": 0x3DCA1C, "TaskBase": 0x3DCFCC, "HugeBattleSystem(CRO analysis vptr)": 0x1296D9F4,
               "null": 0}


def f32(x: float) -> bytes:
    return struct.pack("<f", x)


class Emu:
    def __init__(self, img: bytes):
        uc = Uc(UC_ARCH_ARM, UC_MODE_ARM)
        try:
            uc.ctl_set_cpu_model(A.UC_CPU_ARM_11MPCORE)
            self.cpu = "ARM11MPCore"
        except Exception:  # noqa: BLE001
            self.cpu = "unicorn default ARM"
        uc.mem_map(BASE, MAP_END - BASE)
        uc.mem_write(BASE, img)
        uc.mem_map(STACK_LO, STACK_HI - STACK_LO)
        uc.mem_map(HEAP, HEAP_SIZE)
        uc.mem_map(STOP & ~0xFFF, 0x1000)
        uc.mem_write(STOP, b"\xfe\xff\xff\xea")  # b .
        uc.reg_write(A.UC_ARM_REG_C1_C0_2, uc.reg_read(A.UC_ARM_REG_C1_C0_2) | (0xF << 20))
        uc.reg_write(A.UC_ARM_REG_FPEXC, 0x40000000)
        self.uc = uc
        self.writes: list[tuple[int, int]] = []
        self.snake_sp: list[int] = []
        uc.hook_add(UC_HOOK_MEM_WRITE, lambda u, acc, addr, size, val, ud: self.writes.append((addr, size)))
        uc.hook_add(UC_HOOK_CODE, lambda u, addr, size, ud: self.snake_sp.append(u.reg_read(A.UC_ARM_REG_SP)),
                    begin=SNAKE_FN, end=SNAKE_FN)

    def reset(self, snake: int):
        self.uc.mem_write(HEAP, bytes(HEAP_SIZE))
        self.uc.mem_write(SNAKE_CACHE, bytes([snake & 0xFF]))
        self.uc.mem_write(SNAKE_GUARD, struct.pack("<I", 1))
        for r, v in zip(REGS, SENT):
            self.uc.reg_write(r, v)
        self.writes.clear()
        self.snake_sp.clear()

    def run(self, start: int, until: int, sp: int, lr: int = STOP):
        cpsr = self.uc.reg_read(A.UC_ARM_REG_CPSR)
        self.uc.reg_write(A.UC_ARM_REG_CPSR, cpsr & ~0xF0000020)  # same mode, ARM state, NZCV clear
        self.uc.reg_write(A.UC_ARM_REG_SP, sp)
        self.uc.reg_write(A.UC_ARM_REG_LR, lr)
        self.writes.clear()
        self.uc.emu_start(start, until, timeout=2_000_000, count=20000)
        return self.uc.reg_read(A.UC_ARM_REG_PC)

    def r(self, i: int) -> int:
        return self.uc.reg_read(REGS[i])

    def mem(self, a: int, n: int) -> bytes:
        return bytes(self.uc.mem_read(a, n))


def make_task(emu: Emu, task: int, vptr: int, mode: int, flag3e: int = 0):
    emu.uc.mem_write(task, struct.pack("<I", vptr))
    emu.uc.mem_write(task + 0x3C, bytes([1, mode, flag3e, 1, 1, 0xAA, 0xAA, 0xAA]))  # +0x41..43 garbage


def run(b: dict, args) -> tuple[list[str], bool]:
    out: list[str] = []
    ok_all = True
    allow = [int(a["vptr"], 16) for a in b["allow"]]
    snake_on = not args.no_snake
    labels = b["labels"]
    cave = labels["eng60_init"]
    emu = Emu(b["img"])
    orig = Emu(b["src"])

    # ---------------- A: direct cave calls ----------------
    vptrs = [(a["name"], int(a["vptr"], 16)) for a in b["allow"]] + list(OTHER_VPTRS.items())
    n = fails = 0
    task = HEAP + 0x1000
    sp0 = STACK_HI - 0x1000
    for name, vp in vptrs:
        for mode in (0, 1, 2):
            for snake in (0, 1):
                n += 1
                emu.reset(snake)
                make_task(emu, task, vp, mode)
                emu.uc.reg_write(REGS[4], task)
                pc = emu.run(cave, STOP, sp0)
                promote = mode == 1 and vp in allow and (snake == 1 or not snake_on)
                want3d = 0 if promote else mode
                t = emu.mem(task + 0x3C, 8)
                regs_ok = all(emu.r(i) == SENT[i] for i in (1, 2, 3, 5, 6, 7, 8, 9, 10, 11)) and emu.r(4) == task
                sp_ok = emu.uc.reg_read(A.UC_ARM_REG_SP) == sp0
                called = len(emu.snake_sp)
                want_called = 1 if (mode == 1 and vp in allow and snake_on) else 0
                align_ok = all(s % 8 == 0 for s in emu.snake_sp)
                bad_w = [(hex(a), s) for a, s in emu.writes if not (STACK_LO <= a < STACK_HI)
                         and a not in (task + 0x3D, task + 0x41)]
                good = (pc == STOP and t[1] == want3d and t[5] == (1 if promote else 0) and emu.r(0) == want3d
                        and regs_ok and sp_ok and called == want_called and align_ok and not bad_w
                        and t[0] == 1 and t[2:5] == bytes([0, 1, 1]) and t[6:8] == b"\xAA\xAA")
                if not good:
                    fails += 1
                    out.append(f"FAIL [emu A] {name} {vp:#x} mode {mode} snake {snake}: +3D {t[1]} +41 {t[5]} r0 "
                               f"{emu.r(0)} regs {regs_ok} sp {sp_ok} snake calls {called}/{want_called} "
                               f"align {align_ok} stray writes {bad_w}")
    out.append(("PASS " if not fails else "FAIL ") + f"[emu A] cave called directly ({emu.cpu}): {n} cases "
               f"({len(vptrs)} vptrs x modes 0/1/2 x O3DS/N3DS), {fails} failed; promoted only for allowed "
               f"mode-1 tasks on New 3DS; r1-r11/sp preserved; IsRunOnSnake entered with sp%8==0; "
               f"only stack/+0x3D/+0x41 written")
    ok_all &= not fails

    # ---------------- B: TaskBase::init tail on patched vs original ----------------
    n = fails = 0
    frame_sp = STACK_HI - 0x2000
    for name, vp in vptrs[:len(b["allow"])] + [("Boot", OTHER_VPTRS["Boot"])]:
        for mode in (0, 1):
            for snake in (0, 1):
                for flag3e in (0, 1):
                    n += 1
                    results = []
                    for e in (emu, orig):
                        e.reset(snake)
                        make_task(e, task, vp, mode, flag3e)
                        e.uc.mem_write(task + 0x378, b"\x77")
                        frame = [SENT[3], task, SENT[5], SENT[6], SENT[7], SENT[8], SENT[9], SENT[10], SENT[11], STOP]
                        e.uc.mem_write(frame_sp, struct.pack("<10I", *frame))
                        e.uc.reg_write(REGS[4], task)
                        e.uc.reg_write(REGS[6], 0)
                        e.uc.reg_write(REGS[7], 1)
                        e.uc.reg_write(REGS[8], 3)
                        pc = e.run(INIT_TAIL, STOP, frame_sp)
                        regs = [e.r(i) for i in range(3, 12)]
                        results.append((pc, e.mem(task, 0x380), regs, e.uc.reg_read(A.UC_ARM_REG_SP)))
                    (pc, tp, regs, sp), (opc, to, oregs, osp) = results
                    promote = mode == 1 and vp in allow and (snake == 1 or not snake_on)
                    mode_final = 0 if promote else mode
                    exp_regs = [SENT[3], task] + [SENT[i] for i in range(5, 12)]
                    diff = [i for i in range(0x380) if tp[i] != to[i]]
                    allowed_diff = {0x41} | ({0x3D, 0x45} if promote else set())
                    good = (pc == STOP and opc == STOP and regs == exp_regs == oregs and sp == osp == frame_sp + 40
                            and tp[0x45] == mode_final and tp[0x3D] == mode_final and tp[0x44] == 1
                            and tp[0x46] == 1 and tp[0x4A] == (1 if flag3e else 3) and tp[0x378] == 0
                            and tp[0x41] == (1 if promote else 0) and to[0x45] == mode and set(diff) <= allowed_diff)
                    if not good:
                        fails += 1
                        out.append(f"FAIL [emu B] {name} mode {mode} snake {snake} 3e {flag3e}: diff {[hex(i) for i in diff]}"
                                   f" +45 {tp[0x45]}/{to[0x45]} regs {regs == exp_regs} sp {sp - frame_sp}")
    out.append(("PASS " if not fails else "FAIL ") + f"[emu B] TaskBase::init tail 0x280918..return, patched vs "
               f"original image: {n} cases, {fails} failed; +0x44/+0x46/+0x4A/+0x378 and r3-r11/sp identical to the "
               f"original; the only differences are +0x41 (marker) and, when promoted, +0x3D/+0x45 = 0")
    ok_all &= not fails

    # ---------------- C: credits fix ----------------
    if b.get("credits_installed", args.credits_fix):
        n = fails = 0
        fld, ctrl = HEAP + 0x4000, HEAP + 0x8000
        for mode in (0, 1):
            for has_ctrl in (True, False):
                n += 1
                res = []
                for e in (emu, orig):
                    e.reset(1)
                    e.uc.mem_write(fld + 0x45, bytes([mode]))
                    e.uc.mem_write(fld + 0x1B3C, struct.pack("<I", ctrl if has_ctrl else 0))
                    e.uc.mem_write(ctrl + 0x28, f32(2.0))
                    e.uc.reg_write(REGS[5], fld)
                    e.uc.reg_write(A.UC_ARM_REG_S16, 0x3F9E0419)  # 1.2345f
                    e.uc.reg_write(A.UC_ARM_REG_S31, 0x40490FDB)
                    pc = e.run(CRD_START, CRD_END, STACK_HI - 0x3000)
                    spd = struct.unpack("<f", e.mem(ctrl + 0x28, 4))[0]
                    keep = all(e.r(i) == SENT[i] for i in (4, 6, 7, 8, 9, 10, 11)) and e.r(5) == fld \
                        and e.uc.reg_read(A.UC_ARM_REG_S16) == 0x3F9E0419 and e.uc.reg_read(A.UC_ARM_REG_S31) == 0x40490FDB
                    stray = [(hex(a), s) for a, s in e.writes if a != ctrl + 0x28]
                    res.append((pc, spd, keep, stray, list(e.writes)))
                (pc, spd, keep, stray, w), (opc, ospd, okeep, _ostray, ow) = res
                want = 1.0 if (mode == 0 and has_ctrl) else 2.0
                good = pc == CRD_END and opc == CRD_END and spd == want and ospd == 2.0 and keep and okeep \
                    and not stray and not ow
                if not good:
                    fails += 1
                    out.append(f"FAIL [emu C] mode {mode} ctrl {has_ctrl}: speed {spd} (want {want}), orig {ospd}, "
                               f"regs kept {keep}, stray writes {stray}")
        out.append(("PASS " if not fails else "FAIL ") + f"[emu C] credits fix 0x2E8B9C..0x2E8BA4: {n} cases, {fails} "
                   f"failed; ctrl+0x28 2.0 -> 1.0 only when fld::System+0x45 == 0 and ctrl != NULL; r4-r11, s16, s31 "
                   f"preserved; original image (nop) leaves 2.0")
        ok_all &= not fails
    return out, ok_all
