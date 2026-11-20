"""D1X: find INLINED isFps30() checks: `ldrb rA, [rB, #0x45]` followed within 4 instructions by `cmp rA, #1`
(or `cmp rA, #0` + `cmp rA, #1`), plus float constant selection 2.0/1.0 nearby.

    python scripts/fps60/d1x_inline.py <game> [--all]

Prints one line per candidate with the nearest symbol; `--all` also prints candidates without a 2.0/1.0 literal
nearby (those are usually other structs with a byte at +0x45). Read-only.
"""
from __future__ import annotations

import os
import re
import struct
import sys

import capstone

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import armdis  # noqa: E402

_cs = capstone.Cs(capstone.CS_ARCH_ARM, capstone.CS_MODE_ARM)


def ins_at(g, a):
    b = g.read(a, 4)
    for i in _cs.disasm(b, a):
        return i
    return None


def main(argv: list[str]) -> None:
    game = argv[0]
    show_all = "--all" in argv
    g = armdis.game(game)
    n_hit = 0
    for mod, s, e in g.text_ranges:
        data = g.read(s, e - s)
        n = len(data) // 4
        words = struct.unpack_from(f"<{n}I", data)
        for i, w in enumerate(words):
            # ldrb rt, [rn, #0x45]  : cond 01 0 1 1 1 0 1 Rn Rt imm12  (P=1 U=1 B=1 W=0 L=1)
            if (w & 0x0FF00FFF) != 0x05D00045:
                continue
            rt = (w >> 12) & 0xF
            a = s + 4 * i
            ok = False
            for k in range(1, 5):
                if i + k >= n:
                    break
                w2 = words[i + k]
                # cmp rt, #imm : cond 0011 0101 Rn 0000 imm12
                if (w2 & 0x0FF0F000) == 0x03500000 and ((w2 >> 16) & 0xF) == rt and (w2 & 0xFF) in (0, 1):
                    ok = True
                    break
            if not ok:
                continue
            # float 2.0 / 1.0 literal within +-12 instructions?
            fl = False
            for k in range(-4, 14):
                ins = ins_at(g, a + 4 * k)
                if ins is None:
                    continue
                if ins.mnemonic.startswith("vldr") and "[pc" in ins.op_str:
                    m = re.search(r"\[pc, #(-?0x[0-9a-f]+)\]", ins.op_str)
                    v = g.u32(ins.address + 8 + int(m.group(1), 16)) if m else None
                    if v in (0x40000000, 0x3F800000):
                        fl = True
                if ins.mnemonic.startswith("vmov") and ("#2.0" in ins.op_str or "#1.0" in ins.op_str):
                    fl = True
                if ins.mnemonic.startswith("mov") and re.search(r", #[12]$", ins.op_str) and k > 0:
                    pass
            if fl or show_all:
                n_hit += 1
                print(f"{a:#010x} {'FLOAT2/1' if fl else '        '} {armdis.where(game, a)}")
    print(f"# {n_hit} candidates")


if __name__ == "__main__":
    main(sys.argv[1:])
