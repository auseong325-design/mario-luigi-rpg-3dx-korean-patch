"""RT: one-shot runtime measurements on the running test instance (RPC reads, GDB writes).

  rt_measure.py task [--secs 1] [--label TEXT]
      u32 [0x3F40B4] = current task; its vptr + RTTI class; bytes +0x3C..+0x48 (+0x3D InitParam fps
      copy, +0x45 live fps mode); frame counter u32 +0x578 sampled every 0.25 s for --secs (rate per s);
      IsRunOnSnake cache byte 0x3F716C; config memory APPMEMTYPE u32 0x1FF80030.
  rt_measure.py setfps VALUE [--offset 0x3D] [--offset 0x45 ...] [--secs 1] [--label TEXT]
      GDB: attach (game halts), write VALUE (byte) at task+offset for each --offset, resume;
      then wait 1 s and measure like `task`.
Every run appends one JSON record to work/fps60/runtime/measure_log.jsonl.
Run it through Start-Process with redirected output and WaitForExit (see HARNESS.md).
"""
from __future__ import annotations

import argparse
import json
import struct
import sys
import time
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import rt_rpc  # noqa: E402
import rt_gdb  # noqa: E402

ROOT = Path(__file__).resolve().parents[2]
OUT = ROOT / "work" / "fps60" / "runtime" / "measure_log.jsonl"
CUR_TASK_PTR = 0x3F40B4
FRAME_CTR = 0x578
SNAKE_CACHE = 0x3F716C
APPMEMTYPE = 0x1FF80030


def class_of(rpc: rt_rpc.Rpc, vptr: int) -> list[str]:
    try:
        img = rt_rpc.Image(rpc, rt_rpc.parse_cro_log())
        ch = rt_rpc.Rtti(img, rt_rpc.load_symbols()).class_of_vptr(vptr) or []
        mod = img.module_of(vptr)
        return [f"[{mod}]"] + [rt_rpc.demangle_simple(c) for c in ch]
    except Exception as e:  # keep the measurement even if RTTI resolution fails
        return [f"rtti-error: {e}"]


def measure(rpc: rt_rpc.Rpc, secs: float) -> dict:
    task = rpc.u32(CUR_TASK_PTR)
    rec: dict = {"time": time.strftime("%Y-%m-%d %H:%M:%S"), "cur_task": f"{task:#010x}"}
    rec["snake_cache_3F716C"] = rpc.read(SNAKE_CACHE, 1)[0]
    rec["appmemtype_1FF80030"] = rpc.u32(APPMEMTYPE)
    if not task:
        return rec
    hdr = rpc.read(task, 0x50)
    vptr = struct.unpack_from("<I", hdr)[0]
    rec["vptr"] = f"{vptr:#010x}"
    rec["class"] = class_of(rpc, vptr)
    rec["b3C_48"] = hdr[0x3C:0x49].hex(" ")
    rec["fps_init_3D"] = hdr[0x3D]
    rec["fps_live_45"] = hdr[0x45]
    samples = []
    t0 = time.perf_counter()
    while True:
        t = time.perf_counter() - t0
        samples.append((round(t, 3), rpc.u32(task + FRAME_CTR)))
        if t >= secs:
            break
        time.sleep(0.25)
    (ta, va), (tb, vb) = samples[0], samples[-1]
    rec["ctr_578_samples"] = samples
    rec["ctr_578_per_s"] = round((vb - va) / (tb - ta), 2) if tb > ta else None
    rec["fps_live_45_after"] = rpc.read(task + 0x45, 1)[0]
    return rec


def main(argv=None) -> None:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    p = sub.add_parser("task"); p.add_argument("--secs", type=float, default=1.0); p.add_argument("--label", default="")
    p = sub.add_parser("setfps"); p.add_argument("value", type=lambda s: int(s, 0))
    p.add_argument("--offset", action="append", type=lambda s: int(s, 0))
    p.add_argument("--secs", type=float, default=1.0); p.add_argument("--label", default="")
    a = ap.parse_args(argv)

    rpc = rt_rpc.Rpc(timeout=1.0)
    pid = rpc.select_game()
    rec: dict = {"cmd": a.cmd, "label": a.label, "pid": pid}
    if a.cmd == "setfps":
        task = rpc.u32(CUR_TASK_PTR)
        offs = a.offset or [0x3D]
        g = rt_gdb.Gdb(timeout=5.0)
        try:
            g.attach()
            before = {f"{o:#x}": g.read(task + o, 1)[0] for o in offs}
            for o in offs:
                g.write(task + o, bytes([a.value]))
            after = {f"{o:#x}": g.read(task + o, 1)[0] for o in offs}
        finally:
            g.detach()
            g.close()
        rec.update(write_task=f"{task:#010x}", write_value=a.value, before=before, after=after)
        time.sleep(1.0)
    rec.update(measure(rpc, a.secs))
    OUT.parent.mkdir(parents=True, exist_ok=True)
    with OUT.open("a", encoding="utf-8") as f:
        f.write(json.dumps(rec) + "\n")
    print(json.dumps(rec, indent=1))


if __name__ == "__main__":
    main()
