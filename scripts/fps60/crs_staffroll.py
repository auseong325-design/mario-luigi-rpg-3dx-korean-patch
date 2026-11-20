"""CRS worker helper: parse Staffroll.bin and simulate fld::StaffrollCtrl (Field.cro) at 30/60 fps.

Model (from Field.cro disassembly, 3DX v1.2, analysis base 0x12000000):
  init  @Field+0x3a8 : file = BLZ; u32 count; count x 0x60-byte entries
                       (wchar text[0x2c] @+0, u32 color @+0x58, float height @+0x5c)
                       total = sum(height) - 480 - P[0x14];  speed = P[0x18]
  update@Field+0x98c : pos = clamp_u32(frame*speed - (P0+P4)), pos = min(pos, total)
                       windows: idx0 = entry containing pos, idx1 = entry containing pos+240+P14,
                       idx2 = entry containing pos+480+P14 (else count-1); builds text for
                       [idx0, idx1-1] and [idx1, idx2] into two 0x800-byte stack buffers; frame += 1
  isFinish@Field+0x1000: frame*speed > total
P = fld::GetParamStaffroll() @0x415e38 (static ctor 0x36509c): P0=P4=1 (u32), P8=-140, PC=3, P10=-2,
P14=20, P18=2.0 (px per update).

    python scripts/fps60/crs_staffroll.py [path-to-Staffroll.bin ...]
"""
from __future__ import annotations

import os
import struct
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
P0 = P4 = 1
P14 = 20.0
SPEED = 2.0
STACKBUF_U16 = 0x400  # each text buffer in update() is 0x800 bytes


def blz_decompress(data: bytes) -> bytes:
    from ndspy import codeCompression
    return codeCompression.decompress(data)


def parse(path: str):
    raw = open(path, "rb").read()
    try:
        data = blz_decompress(raw)
    except Exception as exc:  # noqa: BLE001
        print(f"  BLZ decompress failed ({exc}); trying raw")
        data = raw
    count = struct.unpack_from("<I", data, 0)[0]
    entries = []
    for i in range(count):
        off = 4 + i * 0x60
        txt = data[off:off + 0x58].decode("utf-16-le", "replace").split("\0")[0]
        color, height = struct.unpack_from("<If", data, off + 0x58)
        entries.append((txt, color, height))
    return len(raw), len(data), entries


def f32(x: float) -> float:
    return struct.unpack("<f", struct.pack("<f", x))[0]


def u32_of(x: float) -> int:
    if x != x or x <= 0:
        return 0
    return min(int(x), 0xFFFFFFFF)


def text_len_u16(entries, first: int, last: int) -> int:
    """u16 written by the builder at Field+0x874 for entries [first,last] (inclusive), +terminator."""
    if first > last:
        return 1
    n = 0
    for i in range(first, last + 1):
        n += 11 + (1 if i != first else 0)
        t = entries[i][0]
        n += len(t) if t else 1
    return n + 1


def simulate(entries):
    count = len(entries)
    heights = [f32(h) for _, _, h in entries]
    total = f32(f32(sum(heights)) - 480.0 - P14)
    frame = 0
    worst = (0, None)
    anomalies = []
    while True:
        pos_f = f32(frame * SPEED) - (P0 + P4)
        pos = float(u32_of(pos_f))
        if total < pos:
            pos = float(u32_of(total))
        idx = [None, None, None]
        s16, s17, r7 = pos, 0.0, 0
        for i in range(count):
            s18 = s17 + heights[i]
            if s18 > s16:
                idx[r7] = i
                if r7 == 0:
                    s16 = s16 + 240.0 + P14
                elif r7 == 1:
                    s16 = s16 + 240.0
                else:
                    break
                r7 += 1
            s17 = s18
        if idx[2] is None:
            idx[2] = count - 1
        if idx[1] is None:
            anomalies.append((frame, "idx1 not found (uninitialised stack read)"))
        else:
            if idx[1] == 0:
                anomalies.append((frame, "idx1==0 -> builder range [0,0xffffffff] (stack overflow)"))
            a = text_len_u16(entries, idx[0], idx[1] - 1)
            b = text_len_u16(entries, idx[1], idx[2])
            m = max(a, b)
            if m > worst[0]:
                worst = (m, (frame, idx[:]))
            if m > STACKBUF_U16:
                anomalies.append((frame, f"text {m} u16 > 0x400 buffer"))
        if f32(frame * SPEED) > total:  # isFinish()
            break
        frame += 1
        if frame > 10_000_000:
            anomalies.append((frame, "no finish"))
            break
    return total, frame, worst, anomalies


def main(paths):
    if not paths:
        paths = [os.path.join(ROOT, "romfs/Staffroll/JP/Staffroll.bin"),
                 os.path.join(ROOT, "patch/00040000001CA900/romfs/Staffroll/JP/Staffroll.bin"),
                 os.path.join(ROOT, "ml 1dx/3romfs/Staffroll/KR/Staffroll.bin")]
    for p in paths:
        if not os.path.exists(p):
            continue
        clen, dlen, entries = parse(p)
        print(f"== {os.path.relpath(p, ROOT)}: file {clen} B, decompressed {dlen} B, {len(entries)} entries")
        hs = [h for _, _, h in entries]
        print(f"   height sum {sum(hs):.1f}, min {min(hs):.1f}, max {max(hs):.1f}; max text len {max(len(t) for t, _, _ in entries)}")
        total, frames, worst, anomalies = simulate(entries)
        print(f"   total scroll {total:.1f} px; isFinish after {frames} updates = "
              f"{frames / 30:.1f} s at 30 updates/s, {frames / 60:.1f} s at 60 updates/s")
        print(f"   largest text buffer use {worst[0]} u16 of 0x400 at update {worst[1]}")
        print(f"   anomalies: {anomalies[:5]}{' ...' if len(anomalies) > 5 else ''} ({len(anomalies)} total)")
        if "--dump" in sys.argv:
            for i, (t, c, h) in enumerate(entries):
                print(f"   {i:3d} h={h:6.1f} c={c:#010x} {t}")


if __name__ == "__main__":
    main([a for a in sys.argv[1:] if not a.startswith("--")])
