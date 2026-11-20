"""CRD worker: exact model of fld::StaffrollCtrl (Field.cro, 3DX JP v1.2) for the shipped (Korean) and the
original Staffroll.bin, at the 30fps cadence (speed 2.0 px/update, 30 updates/s) and at the proposed 60fps fix
(speed 1.0 px/update, 60 updates/s).

Model, read from the Ghidra decomp (work/fps60/decomp/3dx_v12/Field.c) and the static param ctor:
  P = fld::GetParamStaffroll() = 0x415E38: P0=1 (u32), P4=1 (u32), P8=-140, PC=3, P10=-2, P14=20, P18=2.0
  init   Field+0x3A8 : ctrl+0x28 = P18; entries u32 count + count*0x60 (wchar text[0x2C], u32 colour @+0x58,
                       float height @+0x5C); ctrl+0x24 total = (sum(height) - 480) - P14 (float32, pairwise sum
                       order of the unrolled loop: odd element first, then (h[i] + acc_a), (h[i+1] + acc_b))
  update Field+0x98C : pos = f2u(float(frame)*speed - float(P0+P4)); if total < float(pos): pos = f2u(total)
                       line search with thresholds pos, pos+P14+240, (+240) -> idx0, idx1, idx2 (default count-1)
                       buffer A = builder(idx0, idx1-1), buffer B = builder(idx1, idx2), each 0x400 u16 on the
                       stack (A: sp..+0x800, B: next 0x800 + 0x20 slack before saved registers); frame += 1
  builder Field+0x874: per line 11 u16 of tags (+1 for '\\n' after the first line) + wcslen(text) (or 1 space)
                       + final NUL
  isFinish Field+0x1000: total < float(frame) * speed

    python scripts/fps60/crd_staffroll.py [--dump]
Read-only.
"""
from __future__ import annotations

import os
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(os.path.dirname(HERE))
sys.path.insert(0, os.path.join(ROOT, "scripts"))
import lib3dx  # noqa: E402

P0 = P4 = 1
P14 = 20.0
BUF_U16 = 0x400


def f32(x: float) -> float:
    return struct.unpack("<f", struct.pack("<f", x))[0]


def f2u(x: float) -> int:
    """vcvt.u32.f32 (round toward zero, saturating)."""
    if x != x or x <= 0:
        return 0
    return min(int(x), 0xFFFFFFFF)


def parse(path: str):
    raw = open(path, "rb").read()
    data = lib3dx.blz_decompress(raw)
    count = struct.unpack_from("<I", data, 0)[0]
    ents = []
    for i in range(count):
        off = 4 + 0x60 * i
        t = data[off:off + 0x58]
        u16 = [struct.unpack_from("<H", t, 2 * k)[0] for k in range(0x2C)]
        n = u16.index(0) if 0 in u16 else 0x2C        # wcslen (no terminator inside the 0x58 bytes -> runs on)
        txt = t[:2 * n].decode("utf-16-le", "replace")
        colour, h = struct.unpack_from("<If", data, off + 0x58)
        ents.append((txt, n, colour, f32(h)))
    return raw, data, ents


def total_of(ents) -> float:
    hs = [h for *_, h in ents]
    a = b = 0.0
    k = 0
    if len(hs) & 1:
        a = f32(hs[0] + 0.0)
        k = 1
    while k + 1 < len(hs) + 0:
        a = f32(hs[k] + a)
        b = f32(hs[k + 1] + b)
        k += 2
    s = f32(a + b) if len(hs) else 0.0
    return f32(f32(s - 480.0) - P14)


def build_len(ents, first: int, last: int) -> int:
    if first > last:
        return 1
    n = 0
    for u in range(first, last + 1):
        n += 11 + (1 if u != first else 0)
        n += ents[u][1] if ents[u][1] else 1
    return n + 1


def update_state(ents, total: float, frame: int, speed: float):
    pos_i = f2u(f32(f32(float(frame)) * speed) - float(P0 + P4))
    if total < float(pos_i):
        pos_i = f2u(total)
    thr = float(pos_i)
    idx = [None, None, None]
    s12 = 0.0
    k = 0
    for i, e in enumerate(ents):
        s14 = f32(s12 + e[3])
        if thr < s14:
            idx[k] = i
            if k == 0:
                thr = f32(f32(P14 + thr) + 240.0)
            elif k == 1:
                thr = f32(thr + 240.0)
            else:
                break
            k += 1
        s12 = s14
    else:
        idx[2] = len(ents) - 1
    return pos_i, idx


def simulate(ents, speed: float):
    total = total_of(ents)
    frame = 0
    states = {}
    worst_a = worst_b = (0, None)
    bad = []
    while True:
        pos, idx = update_state(ents, total, frame, speed)
        if idx[0] is None or idx[1] is None:
            bad.append((frame, pos, idx))
            la = lb = 0
        else:
            la = build_len(ents, idx[0], idx[1] - 1)
            lb = build_len(ents, idx[1], idx[2])
            if la > worst_a[0]:
                worst_a = (la, (frame, pos, tuple(idx)))
            if lb > worst_b[0]:
                worst_b = (lb, (frame, pos, tuple(idx)))
        states[tuple(idx)] = states.get(tuple(idx), 0) + 1
        if total < f32(float(frame) * speed):     # isFinish() evaluated after this update by op280(2)
            break
        frame += 1
        if frame > 10_000_000:
            bad.append((frame, "no finish"))
            break
    return {"total": total, "updates": frame + 1, "states": states, "worst_a": worst_a, "worst_b": worst_b,
            "bad": bad}


def main(argv):
    files = [("shipped (Korean) patch", os.path.join(ROOT, "patch/00040000001CA900/romfs/Staffroll/JP/Staffroll.bin")),
             ("original JP v1.2", str(lib3dx.romfs_path("Staffroll/JP/Staffroll.bin")))]
    for label, path in files:
        raw, data, ents = parse(path)
        hs = [e[3] for e in ents]
        print(f"== {label}: {os.path.relpath(path, ROOT)}  {len(raw)} B -> {len(data)} B, {len(ents)} lines, "
              f"height sum {sum(hs):.1f} (min {min(hs):.0f} max {max(hs):.0f}), longest line {max(e[1] for e in ents)} u16")
        for speed, rate, tag in ((2.0, 30, "30fps (stock, speed 2.0)"), (1.0, 60, "60fps + fix (speed 1.0)"),
                                 (2.0, 60, "60fps unfixed (speed 2.0)")):
            r = simulate(ents, speed)
            print(f"   {tag:28s}: total {r['total']:.1f} px, {r['updates']} updates = {r['updates'] / rate:6.1f} s; "
                  f"distinct windows {len(r['states'])}; max buffer A {r['worst_a'][0]} u16 @{r['worst_a'][1]}, "
                  f"B {r['worst_b'][0]} u16 @{r['worst_b'][1]} (limit {BUF_U16}); anomalies {len(r['bad'])}")
        if "--dump" in argv:
            for i, (t, n, c, h) in enumerate(ents):
                print(f"   {i:3d} h={h:4.0f} c={c:#010x} n={n:2d} {t}")


if __name__ == "__main__":
    main(sys.argv[1:])
