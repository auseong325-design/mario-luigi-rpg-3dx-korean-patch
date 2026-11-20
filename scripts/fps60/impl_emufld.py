"""IMPL3: unicorn (ARM11 MPCore + VFP) tests of the --field-vm30 wrappers, called by build_fps60.py.

Three emulators share the layout of impl_emutest.Emu (image at 0x100000 + zero bss to 0x435000, heap 0x30000000):
  real  = patched image, untouched (real originals behind the wrappers),
  stub  = patched image whose two originals 0x2B81A8 / 0x2E225C are replaced by 'bx lr' in emulator memory; a
          code hook on them records r0-r3/sp/lr and the pad/touch/latch memory at the moment of the call (and
          sets s0 to a marker for the sysvar original),
  orig  = the unpatched image (vtable slots -> originals) for A/B comparisons.
Every call starts from the patched vtable slot word, so the slot -> wrapper mapping is exercised too.

F1  slot +0x34 (both vtables): real originals store s0 into GlobalEvent+0x14; under G (+0x45 == 0, Main and
    fld::System present) the stored step is 2*s0, else s0 exactly as the original image; r4-r11, s16-s31, sp kept.
F2  slot +0x20: gated (original not called, latch {trg, rls, touch&0x3C, frame} written, r0 = status) exactly
    when the LocalEvent is not in [sp, sp+0x8000), Main/System present, +0x45 == 0 and +0x578 odd; otherwise
    the original is entered with r0/r1/sp/lr intact and nothing written. The skip status equals the original's
    early-out return value for inactive LocalEvents.
F3  slot +0x2C: for ids $702F..$7041 on even frames with latch.tag == frame-1 (G, Main/System present) the
    original sees P.trg|L.trg, P.rls|L.rls, T|L.touch and the structs are restored afterwards; in every other
    case the original is tail-called with r0-r3/sp/lr intact and the structs untouched. Real-original checks:
    $7038/$7039/$7041 return the latched edges; a stale or odd-frame latch is ignored.
F23 integration: odd frame (A pressed only then) -> even frame: $7038 reads 1.0 although P.trg is 0 again.
"""
from __future__ import annotations

import struct

from unicorn import UC_HOOK_CODE, UcError
from unicorn import arm_const as A

import impl_emutest as E

BASE = E.BASE
HEAP = E.HEAP
STOP = E.STOP
S = [getattr(A, f"UC_ARM_REG_S{i}") for i in range(32)]
VT_ES, VT_RES = 0x3E1784, 0x3E303C
EXEC_ORIG, SYSVAR_ORIG = 0x2B81A8, 0x2E225C
LATCH = 0x434F00
ES, RES, MAIN, SYS, P, T, LE, GE = (HEAP + 0x1000, HEAP + 0x6000, HEAP + 0x8000, HEAP + 0x9000, HEAP + 0xC000,
                                    HEAP + 0xC100, HEAP + 0xD000, HEAP + 0xF000)
SP0 = E.STACK_HI - 0x10000     # 8-aligned; sp+0x8000+0x814 still inside the mapped stack
MARK = 0x4479C000              # 999.0f, returned by the sysvar stub


def f2u(x: float) -> int:
    return struct.unpack("<I", struct.pack("<f", x))[0]


def u2f(u: int) -> float:
    return struct.unpack("<f", struct.pack("<I", u & 0xFFFFFFFF))[0]


class Rig:
    def __init__(self, img: bytes, stub: bool):
        self.e = E.Emu(img)
        self.uc = self.e.uc
        self.calls = []
        if stub:
            for a in (EXEC_ORIG, SYSVAR_ORIG):
                self.uc.mem_write(a, bytes.fromhex("1eff2fe1"))  # bx lr
            self.uc.hook_add(UC_HOOK_CODE, self._hook, begin=EXEC_ORIG, end=EXEC_ORIG)
            self.uc.hook_add(UC_HOOK_CODE, self._hook, begin=SYSVAR_ORIG, end=SYSVAR_ORIG)

    def _hook(self, uc, addr, size, ud):
        rec = {"pc": addr, "r": [uc.reg_read(E.REGS[i]) for i in range(13)], "sp": uc.reg_read(A.UC_ARM_REG_SP),
               "lr": uc.reg_read(A.UC_ARM_REG_LR), "P": self.words(P, 5), "T": self.words(T + 8, 1)[0],
               "latch": self.words(LATCH, 4)}
        self.calls.append(rec)
        if addr == SYSVAR_ORIG:
            uc.reg_write(S[0], MARK)

    def words(self, a: int, n: int) -> list[int]:
        return list(struct.unpack(f"<{n}I", self.e.mem(a, 4 * n)))

    def w32(self, a: int, v: int):
        self.uc.mem_write(a, struct.pack("<I", v & 0xFFFFFFFF))

    def setup(self, mode=0, frame=0x100, main=True, sysp=True, p=(0, 0, 0, 0, 0), t=0, latch=(0, 0, 0, 0),
              le_status=0, txy=(0, 0)):
        e = self.e
        e.reset(1)
        self.calls.clear()
        self.uc.mem_write(LATCH, struct.pack("<4I", *latch))
        for obj, vt in ((ES, VT_ES), (RES, VT_RES)):
            self.w32(obj, vt)
            self.w32(obj + 4, MAIN if main else 0)
        self.w32(MAIN + 0x130, SYS if sysp else 0)
        self.uc.mem_write(SYS + 0x45, bytes([mode]))
        self.w32(SYS + 0x578, frame)
        self.w32(SYS + 0x1B00, P)
        self.w32(SYS + 0x1B08, T)
        self.uc.mem_write(SYS + 0x6E0, struct.pack("<H", 0x8 | 0x10))      # touch enabled ($7041)
        self.uc.mem_write(P, struct.pack("<5I", *p))
        self.uc.mem_write(T, struct.pack("<hh", *txy))
        self.w32(T + 8, t)
        self.w32(LE + 0x814, le_status)
        for i in range(32):
            self.uc.reg_write(S[i], f2u(100.0 + i))

    def call_slot(self, vt: int, off: int, r0: int, r1: int = 0, r2: int = 0, r3: int = 0, s0: float | None = None,
                  sp: int = SP0):
        target = struct.unpack("<I", self.e.mem(vt + off, 4))[0]
        for i, v in enumerate((r0, r1, r2, r3)):
            self.uc.reg_write(E.REGS[i], v)
        if s0 is not None:
            self.uc.reg_write(S[0], f2u(s0))
        try:
            pc = self.e.run(target, STOP, sp)
        except UcError:          # a fault (e.g. a NULL dereference) is a failed case, not a crash of the suite
            pc = -1
        return pc, target

    def kept(self, sp: int) -> bool:
        ok = all(self.e.r(i) == E.SENT[i] for i in range(4, 12)) and self.uc.reg_read(A.UC_ARM_REG_SP) == sp
        return ok and all(self.uc.reg_read(S[i]) == f2u(100.0 + i) for i in range(16, 32))


def run(b: dict, args) -> tuple[list[str], bool]:
    out: list[str] = []
    ok_all = True
    lab = b["labels"]
    real, stub, orig = Rig(b["img"], False), Rig(b["img"], True), Rig(b["src"], False)
    ge_idx = {VT_ES: list(b["src"][0x3A0782 - BASE:0x3A0782 - BASE + 2]), VT_RES: [b["src"][0x3A0780 - BASE]]}

    def ge_of(obj, vt, i):
        return obj + 0xC + i * (0x124 if vt == VT_ES else 0)

    # ---------------- F1 ----------------
    n = fails = 0
    for vt, obj, want_lab in ((VT_ES, ES, "fld60_step_es"), (VT_RES, RES, "fld60_step_res")):
        for mode in (0, 1, 2):
            for main, sysp in ((True, True), (False, True), (True, False)):
                for step in (1.0, 0.5, 1.5):
                    n += 1
                    res = []
                    for rig in (real, orig):
                        rig.setup(mode=mode, main=main, sysp=sysp)
                        for i in ge_idx[vt]:
                            rig.w32(ge_of(obj, vt, i) + 0x14, f2u(-7.0))
                        pc, tgt = rig.call_slot(vt, 0x34, obj, s0=step)
                        vals = [u2f(rig.words(ge_of(obj, vt, i) + 0x14, 1)[0]) for i in ge_idx[vt]]
                        stray = [(hex(a), s) for a, s in rig.e.writes if not (E.STACK_LO <= a < E.STACK_HI)
                                 and a not in [ge_of(obj, vt, i) + 0x14 for i in ge_idx[vt]]]
                        res.append((pc, tgt, vals, rig.kept(SP0), stray))
                    (pc, tgt, vals, kept, stray), (opc, otgt, ovals, okept, _os) = res
                    g = mode == 0 and main and sysp
                    want = [step * 2 if g else step] * len(ge_idx[vt])
                    good = (pc == STOP and opc == STOP and tgt == lab[want_lab] and vals == want and ovals == [step] * len(want)
                            and kept and okept and not stray)
                    if not good:
                        fails += 1
                        out.append(f"FAIL [emu F1] vt {vt:#x} mode {mode} main {main} sys {sysp} step {step}: {vals} "
                                   f"(want {want}, orig {ovals}) kept {kept} stray {stray}")
    out.append(("PASS " if not fails else "FAIL ") + f"[emu F1] slot +0x34 both vtables, real originals: {n} cases, "
               f"{fails} failed; GlobalEvent+0x14 = 2*step only under G (mode 0, Main and fld::System present), "
               f"else = the original image's value; r4-r11, s16-s31, sp kept; only GlobalEvent+0x14 written")
    ok_all &= not fails

    # ---------------- F2 ----------------
    n = fails = 0
    p_vals, t_val = (0x11, 0x0, 0x404, 0x1000, 0x0), 0x3F | 0x40   # trg 0x404, rls 0x1000, touch bits 0..6
    le_cases = [("heap", LE, False), ("stack+0x18", SP0 + 0x18, True), ("stack+0x130", SP0 + 0x130, True),
                ("stack+0x7ffc", SP0 + 0x7FFC, True), ("stack+0x8000", SP0 + 0x8000, False),
                ("below sp", SP0 - 4, False)]
    for vt, obj in ((VT_ES, ES), (VT_RES, RES), ("stackobj", SP0)):
        for le_name, le, on_stack in le_cases:
            if vt == "stackobj" and le_name != "stack+0x130":
                continue
            for mode in (0, 1, 2):
                for frame in (0x100, 0x101):
                    for main, sysp in ((True, True), (False, True), (True, False)):
                        n += 1
                        rig = stub
                        rig.setup(mode=mode, frame=frame, main=main, sysp=sysp, p=p_vals, t=t_val,
                                  latch=(0xAAAA, 0xBBBB, 0xCC, 0x77), le_status=0x06000000 | 0x10)
                        if le != LE:
                            rig.w32(le + 0x814, 0x06000000 | 0x10)
                        if vt == "stackobj":
                            rig.w32(SP0, VT_RES)
                            rig.w32(SP0 + 4, MAIN if main else 0)
                        vtab = VT_RES if vt == "stackobj" else vt
                        pc, tgt = rig.call_slot(vtab, 0x20, obj, le)
                        gate = (not on_stack) and main and sysp and mode == 0 and frame & 1
                        latch = rig.words(LATCH, 4)
                        nonstack = [(hex(a), s) for a, s in rig.e.writes if not (E.STACK_LO <= a < E.STACK_HI)]
                        if gate:
                            good = (pc == STOP and not rig.calls and rig.e.r(0) == 3 and tgt == lab["fld60_exec"]
                                    and latch == [0x404, 0x1000, t_val & 0x3C, frame] and rig.kept(SP0)
                                    and all(a == LATCH + k for (a, s), k in zip(sorted(rig.e.writes), (0, 4, 8, 12)))
                                    and len(rig.e.writes) == 4)
                        else:
                            c = rig.calls[0] if len(rig.calls) == 1 else None
                            good = (pc == STOP and c is not None and c["pc"] == EXEC_ORIG and c["r"][0] == obj
                                    and c["r"][1] == le and c["sp"] == SP0 and c["lr"] == STOP
                                    and all(c["r"][i] == E.SENT[i] for i in range(4, 12))
                                    and latch == [0xAAAA, 0xBBBB, 0xCC, 0x77] and not nonstack and rig.kept(SP0))
                        if not good:
                            fails += 1
                            out.append(f"FAIL [emu F2] obj {vt} le {le_name} mode {mode} frame {frame:#x} main {main} "
                                       f"sys {sysp}: gate {bool(gate)} calls {len(rig.calls)} r0 {rig.e.r(0):#x} latch "
                                       f"{[hex(x) for x in latch]} writes {nonstack}")
    # skip status == the original's early-out value for inactive LocalEvents
    st_fail = []
    for status in (0, 0x02000000, 0x04000000, 0x06000000, 0xF9FFFFF9, 0x7FFFFFF9, 0xFFFFFFF9, 0x1):
        if status & 2 and not status & 4:
            continue                                    # active LocalEvent: the original would run the script
        stub.setup(mode=0, frame=0x101, le_status=status)
        stub.call_slot(VT_ES, 0x20, ES, LE)
        wr = stub.e.r(0)
        orig.setup(mode=0, frame=0x101, le_status=status)
        pc = orig.call_slot(VT_ES, 0x20, ES, LE)[0]     # original image: slot -> 0x2B81A8, early-out path
        if pc != STOP or orig.e.r(0) != wr or wr != (status & 0x7FFFFFF) >> 25:
            st_fail.append((hex(status), wr, orig.e.r(0)))
    n += 1
    fails += bool(st_fail)
    out.append(("PASS " if not fails else "FAIL ") + f"[emu F2] slot +0x20 both vtables + stack object: {n} cases, {fails} "
               f"failed; skipped (original not entered, latch = {{trg, rls, touch&0x3C, frame}}, r0 = status) exactly "
               f"for a non-stack LocalEvent under G on odd frames; LocalEvent in [sp, sp+0x8000) (one-shot runs, "
               f"stack ResidentEventSystem) never gated; otherwise the original entered with r0/r1/sp/lr intact and "
               f"nothing written; skip status == original early-out r0 for inactive LocalEvents"
               + (f"; status mismatches {st_fail}" if st_fail else ""))
    ok_all &= not fails

    # ---------------- F3 (stub original) ----------------
    n = fails = 0
    p0, t0 = (0x0, 0x0, 0x0101, 0x0010, 0x0), 0x01     # trg A|0x100, rls 0x10, touch: holding
    lt = (0x0003, 0x1000, 0x04 | 0x20, None)            # latch: trg A|B, rls 0x1000, touch-down + changed
    for vt, obj in ((VT_ES, ES), (VT_RES, RES)):
        for vid in (0x7000, 0x702E, 0x702F, 0x7030, 0x7037, 0x7038, 0x7039, 0x703A, 0x703B, 0x7040, 0x7041, 0x7042,
                    0x7078):
            for mode in (0, 1):
                for frame, tag in ((0x200, 0x1FF), (0x200, 0x1FD), (0x200, 0), (0x201, 0x200), (0x201, 0x1FF)):
                    for main, sysp in ((True, True), (False, True), (True, False)):
                        n += 1
                        rig = stub
                        rig.setup(mode=mode, frame=frame, main=main, sysp=sysp, p=p0, t=t0, latch=(*lt[:3], tag))
                        pc, tgt = rig.call_slot(vt, 0x2C, obj, GE, LE, vid)
                        apply = (0x702F <= vid <= 0x7041 and main and sysp and mode == 0 and not frame & 1
                                 and tag == frame - 1)
                        c = rig.calls[0] if len(rig.calls) == 1 else None
                        after_p, after_t = rig.words(P, 5), rig.words(T + 8, 1)[0]
                        good = (c is not None and pc == STOP and tgt == lab["fld60_sysvar"]
                                and c["r"][:4] == [obj, GE, LE, vid] and rig.uc.reg_read(S[0]) == MARK
                                and after_p == list(p0) and after_t == t0 and rig.kept(SP0)
                                and rig.words(LATCH, 4) == [*lt[:3], tag])
                        if apply:
                            good = good and (c["P"] == [p0[0], p0[1], p0[2] | lt[0], p0[3] | lt[1], p0[4]]
                                             and c["T"] == t0 | lt[2] and c["sp"] == SP0 - 24 and c["sp"] % 8 == 0
                                             and c["lr"] != STOP)
                        else:
                            good = good and (c["P"] == list(p0) and c["T"] == t0 and c["sp"] == SP0 and c["lr"] == STOP
                                             and all(c["r"][i] == E.SENT[i] for i in range(4, 12)))
                        if not good:
                            fails += 1
                            out.append(f"FAIL [emu F3] vt {vt:#x} id {vid:#x} mode {mode} frame {frame:#x} tag {tag:#x} "
                                       f"main {main} sys {sysp}: apply {bool(apply)} call {c and {k: c[k] for k in ('P', 'T', 'sp', 'lr')}}"
                                       f" after {after_p} {after_t:#x}")
    out.append(("PASS " if not fails else "FAIL ") + f"[emu F3] slot +0x2C both vtables (stubbed original): {n} cases, "
               f"{fails} failed; latch OR'ed into P.trg/P.rls/T+8 during the call exactly for ids $702F..$7041, G, "
               f"Main/fld::System present, even frame and tag == frame-1 (call with sp 8-aligned, entry sp-24), "
               f"structs restored after; otherwise tail call with r0-r3/sp/lr intact and nothing touched; s0 from "
               f"the original returned; r4-r11, s16-s31 kept")
    ok_all &= not fails

    # ---------------- F3 + F2 with the real originals ----------------
    def sysvar(rig, vid):
        rig.call_slot(VT_ES, 0x2C, ES, GE, LE, vid)
        return u2f(rig.uc.reg_read(S[0]))

    chk = []
    # (1) odd frame: A pressed only now -> F2 skips and latches; (2) even frame: $7038 sees A, P restored
    real.setup(mode=0, frame=0x301, p=(0x1, 0x0, 0x1, 0x0, 0x0), t=0x1 | 0x4 | 0x20, le_status=0x06000002 & ~2)
    real.call_slot(VT_ES, 0x20, ES, LE)                          # inactive LE: still a skip (odd frame, G)
    chk.append(("odd-frame latch", real.words(LATCH, 4), [0x1, 0x0, 0x24, 0x301]))
    real.w32(SYS + 0x578, 0x302)
    real.uc.mem_write(P, struct.pack("<5I", 0x0, 0x1, 0x0, 0x1, 0x0))    # released on the even frame
    real.w32(T + 8, 0x2 | 0x8 | 0x20)                                     # touch-up on the even frame
    chk.append(("$7038 even (latched A)", sysvar(real, 0x7038), 1.0))
    chk.append(("$7039 even (own rls)", sysvar(real, 0x7039), 1.0))
    chk.append(("$7041 even (latched touch-down)", sysvar(real, 0x7041), 2.0))
    chk.append(("P/T restored", (real.words(P, 5), real.words(T + 8, 1)[0]), ([0, 1, 0, 1, 0], 0x2A)))
    real.w32(SYS + 0x578, 0x303)
    chk.append(("$7038 odd (no latch)", sysvar(real, 0x7038), 0.0))
    real.w32(SYS + 0x578, 0x304)
    chk.append(("$7038 even, stale latch", sysvar(real, 0x7038), 0.0))
    real.w32(SYS + 0x578, 0x302)
    real.uc.mem_write(SYS + 0x45, b"\x01")
    chk.append(("$7038 30fps (G false)", sysvar(real, 0x7038), 0.0))
    # same reads on the original image (no wrapper): identical whenever G is false
    orig.setup(mode=1, frame=0x302, p=(0x0, 0x1, 0x0, 0x1, 0x0), t=0x2 | 0x8 | 0x20)
    chk.append(("orig $7038", sysvar(orig, 0x7038), 0.0))
    chk.append(("orig $7041", sysvar(orig, 0x7041), 3.0))
    bad = [c for c in chk if c[1] != c[2]]
    out.append(("PASS " if not bad else "FAIL ") + f"[emu F23] real originals, frame sequence odd->even->odd->even: "
               f"{len(chk)} checks, {len(bad)} failed; a 1-frame press/touch on the odd (skipped) frame is read by the "
               f"next even frame's scripts ($7038 = 1.0, $7041 = 2.0), the structs are restored, odd-frame / stale / "
               f"30fps reads see only the live struct" + (f"; {bad}" if bad else ""))
    ok_all &= not bad
    return out, ok_all
