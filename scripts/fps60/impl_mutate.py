"""IMPL3: mutation run for the --field-vm30 unicorn suite (impl_emufld.py). Read-only (writes nothing).

    python scripts/fps60/impl_mutate.py

Builds the v2 configuration in memory (build_fps60.build, same flags as tag v2), applies one mutation at a time
to the patched image (in memory only) and re-runs impl_emufld.run. Every mutation must be detected (at least
one FAIL line). Exit code 0 when all are detected and the unmutated image passes.
"""
from __future__ import annotations

import argparse
import os
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import build_fps60 as B  # noqa: E402
import impl_emufld  # noqa: E402

import keystone  # noqa: E402


def asm(src: str, addr: int) -> bytes:
    enc, _ = keystone.Ks(keystone.KS_ARCH_ARM, keystone.KS_MODE_ARM).asm(src, addr)
    return bytes(enc)


def find(img: bytes, lo: int, hi: int, word_hex: str, nth: int = 0) -> int:
    w = bytes.fromhex(word_hex)
    hits = [a for a in range(lo, hi, 4) if img[a - B.BASE:a - B.BASE + 4] == w]
    if len(hits) <= nth:
        raise SystemExit(f"mutation anchor {word_hex} #{nth} not found in {lo:#x}..{hi:#x}")
    return hits[nth]


def main() -> int:
    args = argparse.Namespace(tag="mut", credits_fix=True, field_vm30=True, allow=None, no_snake=False,
                              skip_emu=False, with_bai=False, out=None)
    b = B.build(args)
    lab = b["labels"]
    lo, hi = lab["fld60_step_es"], B.CAVE_LO + b["cave_len"]
    base_lines, base_ok = impl_emufld.run(b, args)
    print(f"unmutated: {'PASS' if base_ok else 'FAIL'}")
    img = b["img"]

    def ins(addr_hex_word, nth=0):
        return find(img, lo, hi, addr_hex_word, nth)

    muts = []
    # F1
    a = ins(asm("vaddeq.f32 s0, s0, s0", 0).hex())
    muts.append(("M1 F1 vaddeq -> vaddne (doubles at 30fps)", a, asm("vaddne.f32 s0, s0, s0", a)))
    a = lab["fld60_step"] + 8
    muts.append(("M2 F1 Main NULL check removed", a, asm("nop", a)))
    # F2
    a = lab["fld60_exec"] + 8
    muts.append(("M3 F2 stack test removed (one-shots gated)", a, asm("nop", a)))
    a = lab["fld60_exec"] + 4
    muts.append(("M4 F2 stack window 0x8000 -> 0x10", a, asm("cmp ip, #0x10", a)))
    a = ins(asm("tst r2, #1", 0).hex())
    muts.append(("M5 F2 parity inverted", a + 4, asm(f"bne #{B.EXEC_ORIG:#x}", a + 4)))
    a = ins(asm("str r2, [r3]", 0).hex())
    muts.append(("M6 F2 latch trg stored at +4", a, asm("str r2, [r3, #4]", a)))
    a = ins(asm("lsr r0, r0, #0x1e", 0).hex())
    muts.append(("M7 F2 skip status wrong", a, asm("lsr r0, r0, #0x1d", a)))
    a = ins(asm("ldrb r2, [ip, #0x45]", 0).hex())
    muts.append(("M8 F2 gate on +0x44 instead of +0x45", a, asm("ldrb r2, [ip, #0x44]", a)))
    # F3
    a = ins(asm("cmp ip, #0x12", 0).hex())
    muts.append(("M9 F3 id filter widened to $7042", a, asm("cmp ip, #0x13", a)))
    a = ins(asm("cmp r6, r4", 0).hex())
    muts.append(("M10 F3 stale-latch check removed", a + 4, asm("nop", a + 4)))
    a = ins(asm("str r4, [r6, #8]", 0).hex())
    muts.append(("M11 F3 trg not restored", a, asm("nop", a)))
    a = ins(asm("orr lr, lr, r8", 0).hex())
    muts.append(("M12 F3 rls latch not OR'ed", a, asm("mov lr, r8", a)))
    a = ins(asm("push {r4, r5, r6, r7, r8, lr}", 0).hex())
    p1 = ins(asm("pop {r4, r5, r6, r7, r8, pc}", 0).hex())
    p2 = ins(asm("pop {r4, r5, r6, r7, r8, lr}", 0).hex())
    muts.append(("M13 F3 r8 not saved (push/pop without r8, sp 4 mod 8)", [(a, asm("push {r4, r5, r6, r7, lr}", a)),
                 (p1, asm("pop {r4, r5, r6, r7, pc}", p1)), (p2, asm("pop {r4, r5, r6, r7, lr}", p2))], None))
    a = ins(asm("ldr r4, [ip, #0x578]", 0).hex())
    muts.append(("M14 F3 parity from +0x57C", a, asm("ldr r4, [ip, #0x57c]", a)))
    # slots
    muts.append(("M15 ES exec slot left on the original", 0x3E17A4, struct.pack("<I", B.EXEC_ORIG)))

    undetected = []
    for name, a, new in muts:
        m = bytearray(img)
        edits = a if isinstance(a, list) else [(a, new)]
        for ea, nb in edits:
            m[ea - B.BASE:ea - B.BASE + len(nb)] = nb
        bm = dict(b)
        bm["img"] = bytes(m)
        lines, ok = impl_emufld.run(bm, args)
        caught = [ln.split("]")[0] + "]" for ln in lines if ln.startswith("FAIL")]
        print(f"{name}: {'caught by ' + ', '.join(sorted(set(caught))) if not ok else 'NOT DETECTED'}")
        if ok:
            undetected.append(name)
    print("RESULT:", "all mutations detected" if not undetected and base_ok else f"FAIL {undetected}")
    return 0 if base_ok and not undetected else 1


if __name__ == "__main__":
    sys.exit(main())
