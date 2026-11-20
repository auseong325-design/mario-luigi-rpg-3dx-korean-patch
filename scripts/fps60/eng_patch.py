"""ENG prototype of the New-3DS-only 60fps engine patch for 3DX JP v1.2 (static code.bin only).

    python scripts/fps60/eng_patch.py                 # assemble, verify original bytes, print the patch table
    python scripts/fps60/eng_patch.py --ips OUT.ips   # also write a test IPS (never into patch/; lead builds the real one)
    python scripts/fps60/eng_patch.py --no-snake      # variant without the New 3DS test (for Azahar O3DS-mode A/B tests)

Design (see work/fps60/analysis/engine.md §8):
  hook  TaskBase::init 0x28092C  'ldrb r0,[r4,#0x3d]'  ->  'bl eng60_init'
  cave  0x388C00 (zero slack after .text, inside the last RX page 0x388000-0x389000)
  eng60_init(r4 = task): +0x41 = 0; if (+0x3D == 1 && vptr in allow-list && IsRunOnSnake()) { +0x3D = 0; +0x41 = 1 }
                         return r0 = +0x3D   (init then stores it to +0x45; funcInit re-copies +0x3D every frame)
  allow-list = vptr at TaskBase::init time: fld::System, btl::Main, kj::KJSystem, msys::MTaskBase (all menus).
  hb::HugeBattleSystem (HugeBattle.cro) is not listed -> giant battles stay at 30fps (per-class opt-out).
"""
from __future__ import annotations

import os
import struct
import sys

import keystone

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import armdis  # noqa: E402

BASE = 0x100000
HOOK = 0x28092C
HOOK_ORIG = "ldrb r0, [r4, #0x3d]"
CAVE = 0x388C00
CAVE_LIMIT = 0x389000
TEXT_END = 0x388BD8
IS_RUN_ON_SNAKE = 0x2844AC

ALLOW = [
    (0x3E3B3C, "fld::System (field, events, staff roll)"),
    (0x3E10C4, "btl::Main (battle)"),
    (0x3DEBD8, "kj::KJSystem (Bowser Jr.'s Journey)"),
    (0x3E4874, "msys::MTaskBase (MainMenu/LoadMenu/SaveMenu/ShopMenu/KJMenu/Colosseum/BCat/AttackMiniGame)"),
]


def cave_source(snake: bool) -> str:
    test = (f"    bl    #{IS_RUN_ON_SNAKE:#x}\n"
            "    cmp   r0, #0\n"
            "    beq   keep\n") if snake else ""
    words = "".join(f"    .word {v:#x}\n" for v, _ in ALLOW)
    return f"""
eng60_init:
    push  {{r1, r2, r3, lr}}
    mov   r0, #0
    strb  r0, [r4, #0x41]
    ldrb  r0, [r4, #0x3d]
    cmp   r0, #1
    bne   done
    ldr   r2, [r4]
    adr   r3, allow
scan:
    ldr   r1, [r3], #4
    cmp   r1, #0
    beq   keep
    cmp   r1, r2
    bne   scan
{test}    mov   r0, #0
    strb  r0, [r4, #0x3d]
    mov   r1, #1
    strb  r1, [r4, #0x41]
    b     done
keep:
    ldrb  r0, [r4, #0x3d]
done:
    pop   {{r1, r2, r3, pc}}
allow:
{words}    .word 0
"""


def assemble(src: str, addr: int) -> bytes:
    ks = keystone.Ks(keystone.KS_ARCH_ARM, keystone.KS_MODE_ARM)
    enc, _ = ks.asm(src, addr)
    return bytes(enc)


def main(argv: list[str]) -> None:
    g = armdis.game("3dx_v12")
    snake = "--no-snake" not in argv
    # 1. verify original instruction at the hook and the cave is zero slack
    orig = g.read(HOOK, 4)
    dis = armdis.disasm("3dx_v12", HOOK, 1)[0]
    assert HOOK_ORIG.replace(" ", "") in dis.replace(" ", ""), dis
    cave = assemble(cave_source(snake), CAVE)
    assert CAVE + len(cave) <= CAVE_LIMIT
    slack = g.read(TEXT_END, CAVE_LIMIT - TEXT_END)
    assert slack == b"\0" * len(slack), "slack after .text is not zero"
    hook = assemble(f"bl #{CAVE:#x}", HOOK)
    print(f"hook  {HOOK:#x} (file {HOOK - BASE:#x}): {orig.hex()} '{HOOK_ORIG}' -> {hook.hex()} 'bl {CAVE:#x}'")
    print(f"cave  {CAVE:#x} (file {CAVE - BASE:#x}): {len(cave)} bytes{'' if snake else '  [NO New-3DS test]'}")
    for line in armdis.md(False).disasm_lite(cave, CAVE):
        a, size, m, ops = line
        print(f"   {a:08x}: {cave[a - CAVE:a - CAVE + 4].hex()}  {m} {ops}")
    for v, name in ALLOW:
        print(f"   allow vptr {v:#x}  {name}")
    if "--ips" in argv:
        out = argv[argv.index("--ips") + 1]
        if os.path.abspath(out).lower().startswith(os.path.join(armdis.ROOT, "patch").lower()):
            raise SystemExit("refusing to write into patch/ (lead-owned)")
        recs = [(HOOK - BASE, hook), (CAVE - BASE, cave)]
        with open(out, "wb") as f:
            f.write(b"PATCH")
            for off, data in recs:
                f.write(struct.pack(">I", off)[1:] + struct.pack(">H", len(data)) + data)
            f.write(b"EOF")
        print("wrote", out)


if __name__ == "__main__":
    main(sys.argv[1:])
