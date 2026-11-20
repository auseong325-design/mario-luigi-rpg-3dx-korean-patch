"""HB runtime probe (read-only): measure the giant-battle frame rate and CGameSpeed state through
Azahar's RPC server, using RT's client scripts/fps60/rt_rpc.py. Never writes memory.

    python scripts/fps60/hb_probe.py [--secs 3] [--hz 100] [--base 0xCRO_BASE] [--log azahar_log.txt]

Run it while a giant battle (HugeBattle.cro) is on screen in the RT test instance. It prints:
  * the HugeBattle CRO runtime base (from the emulator log, or --base) and its data segment,
  * the current task (static global 0x3F40B4, ENG) and whether its vptr is hb::HugeBattleSystem,
  * TaskBase bytes +0x3C..+0x47 (fps-mode source +0x3D and per-frame copy +0x45),
  * hb::sys::CGameSpeed: speed (+0x04), step-mode index (+0x08), step function (+0x0C), last vsyncs (+0x140),
  * frames/s from the task frame counter (+0x578, +1 per HugeBattleSystem::func frame),
  * a histogram of the per-frame step (data+0x2A4: 1.0 = frame took 1 vsync, 2.0 = 2 vsyncs) and data+0x2B4.

Offsets (analysis addresses in work/fps60/analysis/hugebattle.md; CRO file offset = analysis − 0x12800000):
  vtable hb::HugeBattleSystem  CRO+0x16D9F4   vtable hb::sys::CGameSpeed CRO+0x16DFFC
  step functions: mode0 CRO+0xE1C0 (fixed), mode1 CRO+0xE1C8 (speed * vsyncs, real time)
Owned by worker HB.
"""
from __future__ import annotations

import argparse
import collections
import os
import struct
import sys
import time

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import rt_rpc  # noqa: E402  (RT-owned client, used read-only)

CUR_TASK = 0x3F40B4          # static: current ad::fw::TaskBase (TaskBase ctor stores `this`)
VT_HBSYS = 0x16D9F4          # CRO offsets
VT_GSPEED = 0x16DFFC
FN_MODE = {0xE1C0: "mode0 fixed (speed per frame)", 0xE1C8: "mode1 real-time (speed*vsyncs)",
           0xE1DC: "mode2 fixed (same as 0)"}


def f32(rpc: rt_rpc.Rpc, a: int) -> float:
    return struct.unpack("<f", rpc.read(a, 4))[0]


def main(argv=None) -> None:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--secs", type=float, default=3.0)
    ap.add_argument("--hz", type=float, default=100.0)
    ap.add_argument("--base", type=lambda s: int(s, 0), help="HugeBattle CRO runtime base (default: from log)")
    ap.add_argument("--log", default=str(rt_rpc.LOG_FILE))
    a = ap.parse_args(argv)

    rpc = rt_rpc.Rpc()
    pid = rpc.select_game()
    base = a.base
    if base is None:
        cros = rt_rpc.parse_cro_log(rt_rpc.Path(a.log))
        hb = cros.get("HugeBattle")
        if not hb or not hb.get("loaded"):
            sys.exit("HugeBattle is not loaded according to the emulator log (start a giant battle or pass --base)")
        base = hb["base"]
    segs = {k: (addr, size) for k, addr, size in rt_rpc.Image.cro_segments(rpc, base)}
    data = segs["data"][0]
    print(f"pid {pid}  HugeBattle base {base:#010x}  segments " +
          " ".join(f"{k}={v[0]:#x}+{v[1]:#x}" for k, v in segs.items()))

    task = rpc.u32(CUR_TASK)
    vptr = rpc.u32(task)
    is_hb = vptr == base + VT_HBSYS
    print(f"current task {task:#010x} vptr {vptr:#010x} -> {'hb::HugeBattleSystem' if is_hb else 'NOT HB'}")
    tb = rpc.read(task + 0x3C, 0x0C)
    print("TaskBase +0x3C..+0x47:", tb.hex(" "), f"(fps source +0x3D={tb[1]}, per-frame +0x45={tb[9]})")
    if not is_hb:
        sys.exit("current task is not the HB task; is a giant battle running?")

    holder = rpc.u32(task + 0x5C0)
    gs = rpc.u32(holder)
    gvp = rpc.u32(gs)
    fn = rpc.u32(gs + 0x0C) - base
    print(f"CGameSpeed {gs:#010x} vptr ok={gvp == base + VT_GSPEED} speed={f32(rpc, gs + 4):g} "
          f"modeidx={rpc.read(gs + 8, 1)[0]} fn=CRO+{fn:#x} ({FN_MODE.get(fn, '?')}) "
          f"last_vsyncs={rpc.u32(gs + 0x140)}")

    hist: collections.Counter = collections.Counter()
    fps_est: collections.Counter = collections.Counter()
    t0, c0 = time.monotonic(), rpc.u32(task + 0x578)
    period = 1.0 / a.hz
    while time.monotonic() - t0 < a.secs:
        hist[round(f32(rpc, data + 0x2A4), 2)] += 1
        fps_est[round(f32(rpc, data + 0x2B4), 1)] += 1
        time.sleep(period)
    t1, c1 = time.monotonic(), rpc.u32(task + 0x578)
    print(f"HB frames: {c1 - c0} in {t1 - t0:.2f}s = {(c1 - c0) / (t1 - t0):.1f} frames/s (task+0x578)")
    print("step histogram (data+0x2A4, samples):", dict(sorted(hist.items())))
    print("fps estimate (data+0x2B4, samples):  ", dict(sorted(fps_est.items())))


if __name__ == "__main__":
    main()
