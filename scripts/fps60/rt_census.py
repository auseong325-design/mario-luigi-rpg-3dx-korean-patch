"""RT2: per-scene census and logic-speed probes on the running test instance (RPC reads only).

  rt_census.py snap --label L [--secs 2] [--no-tasks] [--note TEXT]
      current task [0x3F40B4]: vptr, RTTI class, +0x3C..+0x48 (+0x3D persistent fps byte, +0x41 patch
      marker, +0x45 live fps byte), func counter +0x578 rate, game-speed float [[task+0x574]+0x7C],
      class-specific step variables (fld::System +0x1A4C/+0x1A48/+0x6E0, btl::Main +0xBA15C/+0x8A3C/
      +0x8A40 rate, kj::KJSystem +0x61C58/+0xC8D90); loaded CROs (from the instance log); and, unless
      --no-tasks, every live ad::fw::TaskBase-derived object in the mapped heap/linear heap
      (memmap.json) with +0x3D/+0x41/+0x45.  Appends one JSON line to work/fps60/runtime/census.jsonl.
  rt_census.py counters --label L [--secs 2] [--range A:L ...] [--out FILE] [--compare FILE]
      three snapshots (t0, t0+secs/2, t0+secs) of the ranges (default: current task +0..+0x10000,
      static .data/.bss 0x3EF000..0x434D40, the field save buffer [[0x3F49F8]] +0..+0x12900);
      reports every aligned u32 / f32 that increased steadily, with its rate per second.
      --compare FILE: join with an earlier --out by (addr, kind) and print the rate ratio
      (≈2 = advances per frame, ≈1 = advances per unit of game time).
Run through Start-Process with redirected output and WaitForExit (HARNESS.md section 3).
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

ROOT = Path(__file__).resolve().parents[2]
OUT = ROOT / "work" / "fps60" / "runtime" / "census.jsonl"
CUR_TASK_PTR = 0x3F40B4
SAVE_OBJ = 0x3F49F8          # fld::GetSaveData() -> &0x3F49F8; +0 = loaded save buffer (fld::SaveData::load)
SAVE_SIZE = 0x12900
STATIC_DATA = (0x3EF000, 0x434D40 - 0x3EF000)
FRAME_CTR = 0x578

# (name, struct fmt, offset, sample-rate?) per class name (first RTTI name of the task)
PROBES = {
    "fld::System": [("step_1A4C", "f", 0x1A4C, False), ("ffwd_1A48", "f", 0x1A48, False),
                    ("prev_step_1A50", "f", 0x1A50, False), ("flags_6E0", "I", 0x6E0, False)],
    "btl::Main": [("step_BA15C", "f", 0xBA15C, False), ("scale_8A3C", "f", 0x8A3C, False),
                  ("acc_8A40", "f", 0x8A40, True)],
    "kj::KJSystem": [("step_61C58", "f", 0x61C58, False), ("scale_C8D90", "f", 0xC8D90, False)],
}

# Lead (wave 2) globals: object pointers that exist independent of the current task.
GLOBAL_PTRS = {"fld": 0x3F49D0,    # [0x3F49B0+0x20] = fld::System*
               "btl": 0x3F3600,    # btl::Main*
               "kj": 0x3F61C0,     # kj::KJSystem*
               "mcom": 0x3F62A8}   # msys::MComSys::_sys
GLOBAL_PROBES = {"fld": [("step_1A4C", "f", 0x1A4C), ("ffwd_1A48", "f", 0x1A48), ("flags_6E0", "I", 0x6E0)],
                 "btl": [("step_BA15C", "f", 0xBA15C)],
                 "kj": [("step_61C58", "f", 0x61C58)],
                 "mcom": [("step_E6530", "f", 0xE6530)]}
FFWD_GLOBAL = 0x412C80              # field fast-forward factor source (f32)


def read_globals(rpc: rt_rpc.Rpc, runs) -> dict:
    out: dict = {}
    for name, gp in GLOBAL_PTRS.items():
        p = rpc.u32(gp)
        d: dict = {"ptr": f"{p:#010x}"}
        if p and in_mapped(p, 4, runs):
            for n, f, o in GLOBAL_PROBES[name]:
                if in_mapped(p + o, 4, runs):
                    v = struct.unpack("<" + f, rpc.read(p + o, 4))[0]
                    d[n] = round(v, 4) if f == "f" else f"{v:#x}"
        out[name] = d
    out["ffwd_412C80"] = round(struct.unpack("<f", rpc.read(FFWD_GLOBAL, 4))[0], 4)
    return out


def mapped_ranges() -> list[tuple[int, int]]:
    j = json.loads((ROOT / "work" / "fps60" / "runtime" / "memmap.json").read_text(encoding="utf-8"))
    return [(int(r["start"], 16), int(r["end"], 16)) for r in j["runs"]]


def in_mapped(addr: int, size: int = 4, runs=None) -> bool:
    runs = runs or mapped_ranges()
    return any(lo <= addr and addr + size <= hi for lo, hi in runs)


def class_chain(img: rt_rpc.Image, rt: rt_rpc.Rtti, vptr: int) -> list[str]:
    ch = rt.class_of_vptr(vptr) or []
    return [rt_rpc.demangle_simple(c) for c in ch]


def snap(rpc: rt_rpc.Rpc, a) -> dict:
    runs = mapped_ranges()
    rt_rpc.flush_log(rpc)
    cros = rt_rpc.parse_cro_log()
    syms = rt_rpc.load_symbols()
    img = rt_rpc.Image(rpc, cros)
    rt = rt_rpc.Rtti(img, syms)
    rec: dict = {"cmd": "snap", "label": a.label, "note": a.note, "time": time.strftime("%Y-%m-%d %H:%M:%S")}
    rec["cros_loaded"] = sorted(n for n, d in cros.items() if d.get("loaded"))
    task = rpc.u32(CUR_TASK_PTR)
    rec["cur_task"] = f"{task:#010x}"
    if task and in_mapped(task, 0x580, runs):
        hdr = rpc.read(task, 0x580)
        vptr = struct.unpack_from("<I", hdr)[0]
        ch = class_chain(img, rt, vptr)
        rec.update(vptr=f"{vptr:#010x}", module=img.module_of(vptr), cls=ch,
                   b3C_48=hdr[0x3C:0x49].hex(" "), fps_3D=hdr[0x3D], mark_41=hdr[0x41], fps_45=hdr[0x45])
        p574 = struct.unpack_from("<I", hdr, 0x574)[0]
        if p574 and in_mapped(p574 + 0x7C, 4, runs):
            rec["game_speed_574_7C"] = round(struct.unpack("<f", rpc.read(p574 + 0x7C, 4))[0], 4)
        probes = PROBES.get(ch[0], []) if ch else []
        fixed = {n: (f, o) for n, f, o, r in probes}
        rated = [(n, f, o) for n, f, o, r in probes if r]
        for n, (f, o) in fixed.items():
            if in_mapped(task + o, 4, runs):
                v = struct.unpack("<" + f, rpc.read(task + o, 4))[0]
                rec[n] = round(v, 4) if f == "f" else f"{v:#x}"
        samples = []
        t0 = time.perf_counter()
        while True:
            t = time.perf_counter() - t0
            row = [round(t, 3), rpc.u32(task + FRAME_CTR)]
            for n, f, o in rated:
                row.append(struct.unpack("<" + f, rpc.read(task + o, 4))[0])
            samples.append(row)
            if t >= a.secs:
                break
            time.sleep(0.25)
        dt = samples[-1][0] - samples[0][0]
        rec["ctr_578_per_s"] = round((samples[-1][1] - samples[0][1]) / dt, 2) if dt else None
        for i, (n, f, o) in enumerate(rated):
            rec[n + "_per_s"] = round((samples[-1][2 + i] - samples[0][2 + i]) / dt, 2) if dt else None
        rec["fps_45_after"] = rpc.read(task + 0x45, 1)[0]
    save = rpc.u32(SAVE_OBJ)
    rec["save_buf"] = f"{save:#010x}"
    rec["globals"] = read_globals(rpc, runs)
    if not a.no_tasks:
        ranges = rt_rpc.load_ranges(None)
        tasks = rt_rpc.find_tasks(rpc, ranges, cros, syms)
        out = []
        for t in tasks:
            b = bytes.fromhex(t["b3c_48"].replace(" ", ""))
            # a live TaskBase has InitParam flag bytes +0x3C..+0x40 in {0,1} and fps mode 0..3;
            # other hits are words equal to a vptr inside code/literal pools (CRO images in the heap)
            plausible = all(x in (0, 1) for x in b[0:5]) and b[1] <= 3 and b[9] <= 3
            out.append({"addr": t["addr"], "vptr": t["vptr"], "module": t["module"], "class": t["class"],
                        "bases": t["bases"], "fps_3D": b[1], "mark_41": b[5], "fps_45": b[9],
                        "b3c_48": t["b3c_48"], "current": int(t["addr"], 16) == task,
                        "plausible": plausible})
        rec["tasks"] = out
    return rec


def default_ranges(rpc: rt_rpc.Rpc) -> list[tuple[str, int, int]]:
    runs = mapped_ranges()
    out = [("static_data_bss", *STATIC_DATA)]
    task = rpc.u32(CUR_TASK_PTR)
    if task and in_mapped(task, 0x10000, runs):
        out.append(("task", task, 0x10000))
    save = rpc.u32(SAVE_OBJ)
    if save and in_mapped(save, SAVE_SIZE, runs):
        out.append(("save", save, SAVE_SIZE))
    return out


def counters(rpc: rt_rpc.Rpc, a) -> dict:
    import numpy as np

    if a.range:
        ranges = []
        for r in a.range:
            name, _, rest = r.rpartition("=") if "=" in r else ("range", "", r)
            s, l = rest.split(":")
            ranges.append((name or "range", int(s, 0), int(l, 0)))
    else:
        ranges = default_ranges(rpc)
    snaps, times = [], []
    for k in range(3):
        times.append(time.perf_counter())
        snaps.append([rpc.read(s, l) for _, s, l in ranges])
        if k < 2:
            time.sleep(a.secs / 2)
    hits = []
    for ri, (name, start, size) in enumerate(ranges):
        d = [np.frombuffer(snaps[k][ri][: size // 4 * 4], dtype="<u4") for k in range(3)]
        dt1, dt2 = times[1] - times[0], times[2] - times[1]
        # u32 counters
        w = [x.astype(np.int64) for x in d]
        d1 = (w[1] - w[0]) & 0xFFFFFFFF
        d2 = (w[2] - w[1]) & 0xFFFFFFFF
        r1, r2 = d1 / dt1, d2 / dt2
        ok = (d1 > 0) & (d2 > 0) & (r1 >= a.min) & (r1 <= a.max) & (r2 >= a.min) & (r2 <= a.max)
        ok &= np.abs(r1 - r2) <= 0.3 * np.maximum(r1, r2) + 2.0 / min(dt1, dt2)
        for i in np.nonzero(ok)[0]:
            hits.append({"range": name, "addr": f"{start + 4 * int(i):#010x}", "off": f"{4 * int(i):#x}",
                         "kind": "u32", "v0": int(w[0][i]), "v2": int(w[2][i]),
                         "rate": round(float(d1[i] + d2[i]) / (dt1 + dt2), 2)})
        # f32 counters
        f = [x.view("<f4").astype(np.float64) for x in d]
        with np.errstate(all="ignore"):
            e1, e2 = f[1] - f[0], f[2] - f[1]
            q1, q2 = e1 / dt1, e2 / dt2
            okf = np.isfinite(f[0]) & np.isfinite(f[2]) & (np.abs(f[0]) < 1e9)
            okf &= (e1 > 0) & (e2 > 0) & (q1 >= a.min) & (q1 <= a.max) & (q2 >= a.min) & (q2 <= a.max)
            okf &= np.abs(q1 - q2) <= 0.3 * np.maximum(q1, q2) + 2.0 / min(dt1, dt2)
        for i in np.nonzero(okf)[0]:
            hits.append({"range": name, "addr": f"{start + 4 * int(i):#010x}", "off": f"{4 * int(i):#x}",
                         "kind": "f32", "v0": round(float(f[0][i]), 4), "v2": round(float(f[2][i]), 4),
                         "rate": round(float(e1[i] + e2[i]) / (dt1 + dt2), 2)})
    rec = {"cmd": "counters", "label": a.label, "time": time.strftime("%Y-%m-%d %H:%M:%S"),
           "ranges": [{"name": n, "start": f"{s:#010x}", "size": f"{l:#x}"} for n, s, l in ranges],
           "secs": round(times[2] - times[0], 3), "hits": hits}
    return rec


def dump_ranges(rpc: rt_rpc.Rpc, ranges: list[tuple[str, int, int]], path: Path) -> None:
    blob = {"ranges": [], "time": time.time()}
    data = bytearray()
    for name, s, l in ranges:
        blob["ranges"].append([name, s, l, len(data)])
        data += rpc.read(s, l)
    path.with_suffix(".json").write_text(json.dumps(blob), encoding="utf-8")
    path.with_suffix(".bin").write_bytes(bytes(data))


def load_dump(path: Path):
    blob = json.loads(path.with_suffix(".json").read_text(encoding="utf-8"))
    return blob, path.with_suffix(".bin").read_bytes()


def fdiff(a_path: Path, b_path: Path, thr: float, lim: float, c_path: Path | None = None):
    """f32 words that moved by >= thr between dump A and B (and, with C, moved back toward A
    or kept moving the same direction) -- used to find positions after a scripted walk."""
    import numpy as np

    ja, da = load_dump(a_path)
    jb, db = load_dump(b_path)
    jc, dc = load_dump(c_path) if c_path else (None, None)
    out = []
    for (name, s, l, off) in ja["ranges"]:
        fa = np.frombuffer(da[off:off + l // 4 * 4], dtype="<f4").astype(np.float64)
        fb = np.frombuffer(db[off:off + l // 4 * 4], dtype="<f4").astype(np.float64)
        with np.errstate(all="ignore"):
            ok = np.isfinite(fa) & np.isfinite(fb) & (np.abs(fa) < lim) & (np.abs(fb) < lim)
            ok &= np.abs(fb - fa) >= thr
            ok &= (np.abs(fa) > 1e-3) | (np.abs(fb) > 1e-3)
        if dc is not None:
            fc = np.frombuffer(dc[off:off + l // 4 * 4], dtype="<f4").astype(np.float64)
        for i in np.nonzero(ok)[0]:
            rec = {"addr": f"{s + 4 * int(i):#010x}", "range": name, "a": round(float(fa[i]), 3),
                   "b": round(float(fb[i]), 3), "d": round(float(fb[i] - fa[i]), 3)}
            if dc is not None:
                rec["c"] = round(float(fc[i]), 3)
                rec["d2"] = round(float(fc[i] - fb[i]), 3)
            out.append(rec)
    return out


def follow(rpc: rt_rpc.Rpc, secs: float, hz: float) -> dict:
    """Sample the current task (+0x3D/+0x45/+0x578) and the global step floats at `hz`; keep only
    the samples where something other than the frame counter changed."""
    runs = mapped_ranges()
    t0 = time.perf_counter()
    log, last = [], None
    n = 0
    while True:
        t = time.perf_counter() - t0
        task = rpc.u32(CUR_TASK_PTR)
        row: dict = {"task": f"{task:#010x}"}
        if task and in_mapped(task, 0x580, runs):
            hdr = rpc.read(task, 0x48)
            row.update(vptr=f"{struct.unpack_from('<I', hdr)[0]:#010x}", b3D=hdr[0x3D], b41=hdr[0x41], b45=hdr[0x45])
            ctr = rpc.u32(task + FRAME_CTR)
        else:
            ctr = None
        g = read_globals(rpc, runs)
        for k in ("fld", "btl", "kj", "mcom"):
            for kk, vv in g[k].items():
                row[f"{k}.{kk}"] = vv
        key = json.dumps(row, sort_keys=True)
        if key != last:
            log.append({"t": round(t, 3), "ctr": ctr, **row})
            last = key
        n += 1
        if t >= secs:
            break
        time.sleep(max(0.0, 1.0 / hz - 0.004))
    return {"cmd": "follow", "time": time.strftime("%Y-%m-%d %H:%M:%S"), "secs": round(t, 3),
            "samples": n, "changes": log}


def main(argv=None) -> None:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    p = sub.add_parser("snap"); p.add_argument("--label", required=True); p.add_argument("--note", default="")
    p.add_argument("--secs", type=float, default=2.0); p.add_argument("--no-tasks", action="store_true")
    p = sub.add_parser("counters"); p.add_argument("--label", required=True)
    p.add_argument("--secs", type=float, default=2.0); p.add_argument("--range", action="append",
                   help="[name=]ADDR:LEN")
    p.add_argument("--min", type=float, default=0.5); p.add_argument("--max", type=float, default=400.0)
    p.add_argument("--out"); p.add_argument("--compare")
    p = sub.add_parser("dump"); p.add_argument("--range", action="append", required=True, help="[name=]ADDR:LEN")
    p.add_argument("--out", required=True, help="path without suffix (.bin/.json written)")
    p = sub.add_parser("fdiff"); p.add_argument("a"); p.add_argument("b"); p.add_argument("c", nargs="?")
    p.add_argument("--thr", type=float, default=5.0); p.add_argument("--lim", type=float, default=1e5)
    p.add_argument("--max", type=int, default=80); p.add_argument("--back", type=float, default=0.0)
    p = sub.add_parser("watchf"); p.add_argument("addrs", nargs="+", type=lambda s: int(s, 0))
    p.add_argument("--secs", type=float, default=2.0); p.add_argument("--hz", type=float, default=20.0)
    p.add_argument("--label", default="")
    p = sub.add_parser("follow"); p.add_argument("--secs", type=float, default=5.0)
    p.add_argument("--hz", type=float, default=20.0); p.add_argument("--label", default="")
    a = ap.parse_args(argv)

    if a.cmd == "fdiff":
        hits = fdiff(Path(a.a), Path(a.b), a.thr, a.lim, Path(a.c) if a.c else None)
        if a.back and a.c:
            hits = [h for h in hits if abs(h["d"] + h["d2"]) <= a.back]
        print(f"{len(hits)} f32 word(s) moved by >= {a.thr}" + (f" and back within {a.back}" if a.back else ""))
        for h in hits[: a.max]:
            print("  " + "  ".join(f"{k}={v}" for k, v in h.items()))
        return

    rpc = rt_rpc.Rpc(timeout=1.0)
    pid = rpc.select_game()
    if a.cmd == "dump":
        ranges = []
        for r in a.range:
            name, _, rest = r.rpartition("=") if "=" in r else ("range", "", r)
            s, l = rest.split(":")
            ranges.append((name or "range", int(s, 0), int(l, 0)))
        dump_ranges(rpc, ranges, Path(a.out))
        print(f"dumped {sum(l for _, _, l in ranges):#x} bytes to {a.out}.bin")
        return
    if a.cmd == "follow":
        rec = follow(rpc, a.secs, a.hz)
        rec["label"] = a.label
        with OUT.open("a", encoding="utf-8") as fo:
            fo.write(json.dumps(rec) + "\n")
        print(f"{a.label}: {rec['samples']} samples in {rec['secs']} s, {len(rec['changes'])} distinct states")
        for c in rec["changes"]:
            print("  " + " ".join(f"{k}={v}" for k, v in c.items()))
        return
    if a.cmd == "watchf":
        t0 = time.perf_counter()
        series = []
        while True:
            t = time.perf_counter() - t0
            series.append((t, [struct.unpack("<f", rpc.read(ad, 4))[0] for ad in a.addrs]))
            if t >= a.secs:
                break
            time.sleep(1.0 / a.hz)
        rec = {"cmd": "watchf", "label": a.label, "time": time.strftime("%Y-%m-%d %H:%M:%S"),
               "secs": round(series[-1][0], 3), "addrs": [f"{ad:#010x}" for ad in a.addrs],
               "first": [round(v, 3) for v in series[0][1]], "last": [round(v, 3) for v in series[-1][1]]}
        # path length (sum of |steps|) and net change per address
        rec["path"] = [round(sum(abs(series[k][1][i] - series[k - 1][1][i]) for k in range(1, len(series))), 3)
                       for i in range(len(a.addrs))]
        rec["net"] = [round(series[-1][1][i] - series[0][1][i], 3) for i in range(len(a.addrs))]
        moving = [k for k in range(1, len(series)) if any(series[k][1][i] != series[k - 1][1][i]
                                                          for i in range(len(a.addrs)))]
        rec["moving_secs"] = round(series[moving[-1]][0] - series[moving[0] - 1][0], 3) if moving else 0.0
        with OUT.open("a", encoding="utf-8") as fo:
            fo.write(json.dumps(rec) + "\n")
        print(json.dumps(rec))
        return
    if a.cmd == "snap":
        rec = snap(rpc, a)
        rec["pid"] = pid
        OUT.parent.mkdir(parents=True, exist_ok=True)
        with OUT.open("a", encoding="utf-8") as fo:
            fo.write(json.dumps(rec) + "\n")
        brief = {k: v for k, v in rec.items() if k != "tasks"}
        print(json.dumps(brief, indent=1))
        for t in rec.get("tasks", []):
            print(f"{'*' if t['current'] else ' '}{'' if t['plausible'] else '?'} {t['addr']} vptr={t['vptr']}"
                  f" [{t['module']}] {t['class']} 3D={t['fps_3D']} 41={t['mark_41']} 45={t['fps_45']}"
                  f"  +3C..+48={t['b3c_48']}")
        if "tasks" in rec:
            n_ok = sum(1 for t in rec["tasks"] if t["plausible"])
            print(f"{len(rec['tasks'])} vptr hit(s), {n_ok} plausible live TaskBase object(s) ('?' = literal/code word)")
    else:
        rec = counters(rpc, a)
        rec["pid"] = pid
        if a.out:
            Path(a.out).parent.mkdir(parents=True, exist_ok=True)
            Path(a.out).write_text(json.dumps(rec, indent=1), encoding="utf-8")
        prev = {}
        if a.compare:
            for h in json.loads(Path(a.compare).read_text(encoding="utf-8"))["hits"]:
                prev[(h["addr"], h["kind"])] = h["rate"]
        print(f"{a.label}: {len(rec['hits'])} steady counter(s) over {rec['secs']} s; ranges "
              + ", ".join(f"{r['name']}={r['start']}+{r['size']}" for r in rec["ranges"]))
        for h in rec["hits"]:
            extra = ""
            if prev:
                pr = prev.get((h["addr"], h["kind"]))
                extra = f"  prev={pr}  ratio={h['rate'] / pr:.2f}" if pr else "  (new)"
            print(f"  {h['range']:15s} {h['addr']} +{h['off']:>7s} {h['kind']} {h['v0']} -> {h['v2']}"
                  f"  {h['rate']}/s{extra}")
        if prev:
            cur = {(h["addr"], h["kind"]) for h in rec["hits"]}
            gone = [k for k in prev if k not in cur]
            if gone:
                print(f"  stopped/missing vs compare: {len(gone)}: "
                      + ", ".join(f"{ad}/{k}({prev[(ad, k)]}/s)" for ad, k in gone[:40]))


if __name__ == "__main__":
    main()
