"""STAR helper: every loop (backward branch) of a BAI script with its waits, the work it does per pass
(effects, sounds, objects, damage, motion) and its step-scaled updates. Read-only.

    python work/fps60/star/star_loops.py atk_pc_sp_ml_star
"""
from __future__ import annotations

import os
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))))
sys.path.insert(0, os.path.join(ROOT, "scripts", "fps60"))
sys.path.insert(0, os.path.join(ROOT, "scripts"))
import btl_bai  # noqa: E402

WORK = {
    0x165: "dfxPos", 0x169: "dfxObj", 0x16A: "dfxObj", 0x16E: "dfxShake", 0x16F: "dfxShake", 0x172: "dfxFollow",
    0x174: "dfxKill", 0x17F: "dfxParam", 0x181: "dfxAttach", 0x19C: "se", 0x19D: "se", 0x19E: "seStop",
    0x0AF: "objNew", 0x0B3: "objFree", 0x0B9: "damage", 0x233: "dmgAnm", 0x101: "anm", 0x04E: "thread",
    0x117: "move", 0x118: "moveFrm", 0x119: "moveCurve", 0x11E: "setPos", 0x12F: "jump", 0x134: "jumpCalc",
    0x103: "rotV1", 0x107: "scaleV3", 0x10B: "colorC", 0x1E5: "cam", 0x1EE: "cam", 0x1E7: "cam", 0x1E8: "cam",
    0x1DC: "arrSet", 0x1E4: "arrRot", 0x0D4: "objSet",
}


def main(argv):
    name = argv[0] if argv[0].endswith(".bai") else argv[0] + ".bai"
    dt = btl_bai.descs()
    files = btl_bai.load()
    ins, _ = btl_bai.decode_all(files[name], dt)
    by = {i[0]: i for i in ins}
    order = [i[0] for i in ins]
    for i in ins:
        op, params = i[1], i[4]
        t = None
        if op == 0x04 and btl_bai.imm(params, 0) in (0, 2):
            t = btl_bai.imm(params, 1)
        elif op == 0x03:
            t = btl_bai.imm(params, 4)
        if t is None or t >= i[0]:
            continue
        body = [by[p] for p in order if t <= p <= i[0]]
        waits = [btl_bai.fmt(b).split(": ", 1)[1] for b in body if b[1] == 0x05]
        work = {}
        for b in body:
            if b[1] in WORK:
                work[WORK[b[1]]] = work.get(WORK[b[1]], 0) + 1
        step = sum(1 for b in body if any(tt == "var" and v == 0x7012 for tt, v in b[4]))
        calls = [btl_bai.fmt(b).split(": ", 1)[1] for b in body if b[1] == 0x04 and btl_bai.imm(b[4], 0) == 1]
        print(f"loop {t:05x}-{i[0]:05x} n={len(body):3d} waits={waits} step={step} work={work} calls={calls[:4]}")


if __name__ == "__main__":
    main(sys.argv[1:])
