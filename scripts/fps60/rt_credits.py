"""RT3: follow one staff-roll (credits) run on the TEST instance; RPC reads only (+ optional GDB flip).

  rt_credits.py follow --label L --secs S [--hz 4] [--flip] [--watch A,B,...] [--find-room]
  rt_credits.py summary work/fps60/runtime/rt3/L.jsonl

Per sample: [0x3F40B4] current task (vptr, +0x3D/+0x41/+0x45, +0x578); fld::System = [0x3F49D0] (checked by
vptr 0x3E3B3C: +0x3D/+0x41/+0x45, +0x578, +0x1A48 ffwd, +0x1A4C step, +0x6E0 flags, ctrl = +0x1B3C);
StaffrollCtrl +0x14 frame, +0x18 ready, +0x1C count, +0x24 total, +0x28 speed; GetParamStaffroll()
[0x415E38] P0 / [0x415E3C] P4; u32 watch words (default: RT2's real-time / sound counters in static .bss).
One JSON line per sample in work/fps60/runtime/rt3/<label>.jsonl (flushed every sample, so a killed run keeps
its data); `summary` (also run at the end of `follow`) writes <label>_summary.json: roll start / isFinish /
ctrl delete times, updates per second, watch-word start/stop times, task and +0x6E0 changes, freezes.
--flip   community-cheat equivalent: whenever the current task is fld::System with +0x3D == 1, write
         +0x3D = 0 through GDB (attach halts the game, M write, 'c' + close).  Start the monitor on the mode
         select (LoadMenuTask current) so only the loaded field task is flipped (R2).
--find-room  12 s after the ctrl appears, read fld::System +0..+0x20000 once and track every u16 equal to
         0x02C2 / 0x02C1 (credits rooms U / L) as room-id candidates (sampled from then on).
Light reads only (~15 small RPC requests per sample); never a heap scan (HARNESS 8.4).
Run it detached (Start-Process -WindowStyle Hidden, no redirection) and poll the .jsonl; it stops by itself
after --secs or when the RPC server disappears (emulator closed or crashed).
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
OUTDIR = ROOT / "work" / "fps60" / "runtime" / "rt3"
CUR_TASK = 0x3F40B4
FLD_PTR = 0x3F49D0
FLD_VPTR = 0x3E3B3C
PARAM = 0x415E38
SNDSYS = 0x3FBF9C            # u32 [[fld+0xA08]] at runtime (RT3 7.2); +0/+4 = BGM slot 0/1 handles
END_ROLL_ID = 0x0100032C     # 04_end_roll stream id prepared by the credits room (CRD 3)
LIN_LO, LIN_HI = 0x30000000, 0x37382000
HEAP_LO, HEAP_HI = 0x08000000, 0x08540000
# RT2 findings 6.1: 0x4291E4 vsync count (60/s), 0x425258 main-loop frames, 0x42C6B8 ~83/s (sound frame
# clock), 2.44/s words (likely stream blocks): 0x42ECAC 0x42ED4C 0x4301A8 0x430244 0x430248 0x43451C
DEFAULT_WATCH = [0x4291E4, 0x425258, 0x42C6B8, 0x42ECAC, 0x42ED4C, 0x4301A8, 0x430244, 0x430248, 0x43451C]
ROOM_IDS = (0x2C2, 0x2C1)


def ok_ptr(p: int, size: int = 4) -> bool:
    return (LIN_LO <= p and p + size <= LIN_HI) or (HEAP_LO <= p and p + size <= HEAP_HI)


def sample(rpc: rt_rpc.Rpc, watch: list[int], rooms: list[int]) -> dict:
    s: dict = {}
    task = rpc.u32(CUR_TASK)
    s["task"] = task
    if task and ok_ptr(task, 0x580):
        h = rpc.read(task, 0x48)
        s["tv"] = struct.unpack_from("<I", h)[0]
        s["t3D"], s["t41"], s["t45"] = h[0x3D], h[0x41], h[0x45]
        s["tctr"] = rpc.u32(task + 0x578)
    fld = rpc.u32(FLD_PTR)
    s["fld"] = fld
    if fld and ok_ptr(fld, 0x1B40) and rpc.u32(fld) == FLD_VPTR:
        h = rpc.read(fld, 0x48)
        s["f3D"], s["f41"], s["f45"] = h[0x3D], h[0x41], h[0x45]
        s["fctr"] = rpc.u32(fld + 0x578)
        s["f6E0"] = rpc.u32(fld + 0x6E0)
        b = rpc.read(fld + 0x1A48, 0x1B40 - 0x1A48)
        s["ffwd"] = round(struct.unpack_from("<f", b, 0)[0], 4)
        s["step"] = round(struct.unpack_from("<f", b, 4)[0], 4)
        ctrl = struct.unpack_from("<I", b, 0x1B3C - 0x1A48)[0]
        s["ctrl"] = ctrl
        if ctrl and ok_ptr(ctrl, 0x2C):
            c = rpc.read(ctrl + 0x10, 0x1C)
            s["c_sys"] = struct.unpack_from("<I", c, 0)[0]
            s["frame"] = struct.unpack_from("<I", c, 4)[0]
            s["ready"] = c[8]
            s["count"] = struct.unpack_from("<I", c, 0xC)[0]
            s["total"] = round(struct.unpack_from("<f", c, 0x14)[0], 2)
            s["speed"] = round(struct.unpack_from("<f", c, 0x18)[0], 4)
        if rooms:
            s["rooms"] = [struct.unpack("<H", rpc.read(fld + o, 2))[0] for o in rooms]
        # field BGM state (op228 handler 0x2ED570): fld+0xA08 -> SndSys holder; per slot s:
        # +0xA0C+0x10*s u8 playing flag (set 1 by op228 play), +0xA10+0x10*s u32 sound id
        fb = rpc.read(fld + 0xA08, 0x20)
        s["fb"] = [fb[4], struct.unpack_from("<I", fb, 8)[0], fb[0x14], struct.unpack_from("<I", fb, 0x18)[0]]
    p = rpc.read(PARAM, 8)
    # SndSys (static .bss 0x3FBF9C, SndSys::stopAllBgm 0x33C450): two BGM SoundHandles = BasicSound* or 0
    s["bgm"] = list(struct.unpack("<II", rpc.read(SNDSYS, 8)))
    s["P0"], s["P4"] = struct.unpack("<II", p)
    s["w"] = [rpc.u32(a) for a in watch]
    return s


def gdb_flip(task: int) -> dict:
    import rt_gdb
    g = rt_gdb.Gdb(timeout=5.0)
    try:
        g.attach()
        before = g.read(task + 0x3D, 1)[0]
        g.write(task + 0x3D, b"\x00")
        after = g.read(task + 0x3D, 1)[0]
    finally:
        g.detach()
        g.close()
    return {"before": before, "after": after}


def follow(a) -> Path:
    OUTDIR.mkdir(parents=True, exist_ok=True)
    path = OUTDIR / f"{a.label}.jsonl"
    watch = [int(x, 0) for x in a.watch.split(",")] if a.watch else list(DEFAULT_WATCH)
    rpc = rt_rpc.Rpc(timeout=1.0)
    pid = rpc.select_game()
    rooms: list[int] = []
    ctrl_seen_t = None
    room_done = not a.find_room
    flips = 0
    t0 = time.perf_counter()
    with path.open("w", encoding="utf-8") as fo:
        fo.write(json.dumps({"hdr": 1, "label": a.label, "start": time.strftime("%Y-%m-%d %H:%M:%S"),
                             "pid": pid, "hz": a.hz, "flip": a.flip,
                             "watch": [f"{w:#x}" for w in watch]}) + "\n")
        fo.flush()
        while True:
            t = time.perf_counter() - t0
            if t >= a.secs:
                break
            try:
                s = sample(rpc, watch, rooms)
            except (ConnectionError, OSError) as e:
                fo.write(json.dumps({"t": round(t, 3), "event": "rpc_lost", "err": str(e)}) + "\n")
                fo.flush()
                break
            s["t"] = round(t, 3)
            s["wall"] = time.strftime("%H:%M:%S")
            if a.flip and s.get("tv") == FLD_VPTR and s.get("t3D") == 1 and flips < a.max_flips:
                try:
                    r = gdb_flip(s["task"])
                    flips += 1
                    s["flip"] = r
                except Exception as e:  # keep following even if the GDB write fails
                    s["flip_err"] = str(e)
            if s.get("ctrl") and ctrl_seen_t is None:
                ctrl_seen_t = t
            if not room_done and ctrl_seen_t is not None and t - ctrl_seen_t >= 12.0 and s.get("fld"):
                fld = s["fld"]
                blob = rpc.read(fld, a.room_len)
                for o in range(0, len(blob) - 1, 2):
                    v = struct.unpack_from("<H", blob, o)[0]
                    if v in ROOM_IDS:
                        rooms.append(o)
                rooms = rooms[:24]
                room_done = True
                s["room_offsets"] = [f"{o:#x}" for o in rooms]
            fo.write(json.dumps(s) + "\n")
            fo.flush()
            time.sleep(max(0.0, 1.0 / a.hz - (time.perf_counter() - t0 - t)))
    return path


def runs_of_change(series: list[tuple[float, int]], quiet: float) -> list[list[float]]:
    """Intervals [start, end] in which a counter kept increasing (gaps > quiet seconds split runs)."""
    out: list[list[float]] = []
    last_t, last_v = None, None
    for t, v in series:
        if last_v is not None and v != last_v:
            if out and t - out[-1][1] <= quiet:
                out[-1][1] = t
            else:
                out.append([last_t, t])
        last_t, last_v = t, v
    return [[round(x, 2), round(y, 2)] for x, y in out]


def summarize(path: Path) -> dict:
    lines = [json.loads(x) for x in path.read_text(encoding="utf-8").splitlines() if x.strip()]
    hdr = lines[0] if lines and "hdr" in lines[0] else {}
    smp = [x for x in lines if "t" in x and "event" not in x]
    events = [x for x in lines if "event" in x]
    out: dict = {"label": hdr.get("label"), "start": hdr.get("start"), "samples": len(smp),
                 "secs": smp[-1]["t"] if smp else 0, "events": events}
    # task changes
    tc, last = [], None
    for s in smp:
        k = (s.get("task"), s.get("tv"), s.get("t3D"), s.get("t41"))
        if k != last:
            tc.append({"t": s["t"], "wall": s.get("wall"), "task": f"{s.get('task', 0):#x}",
                       "vptr": f"{s.get('tv', 0):#x}", "3D": s.get("t3D"), "41": s.get("t41"), "45": s.get("t45")})
            last = k
    out["task_changes"] = tc[:60]
    # flips
    out["flips"] = [{"t": s["t"], **s["flip"]} for s in smp if "flip" in s]
    # fld flags / step changes
    fc, last = [], None
    for s in smp:
        k = (s.get("f6E0"), s.get("step"), s.get("ffwd"), s.get("f3D"), s.get("f45"))
        if k != last and s.get("f6E0") is not None:
            fc.append({"t": s["t"], "f6E0": f"{s['f6E0']:#x}", "step": s.get("step"), "ffwd": s.get("ffwd"),
                       "3D": s.get("f3D"), "41": s.get("f41"), "45": s.get("f45")})
            last = k
    out["fld_changes"] = fc[:80]
    # ctrl lifetime and roll
    on = [s for s in smp if s.get("ctrl")]
    if on:
        t_on = on[0]["t"]
        after = [s for s in smp if s["t"] > t_on and not s.get("ctrl")]
        t_off = after[0]["t"] if after else None
        out["ctrl"] = {"created_t": t_on, "created_wall": on[0].get("wall"), "deleted_t": t_off,
                       "deleted_wall": after[0].get("wall") if after else None,
                       "count": on[-1].get("count"), "total": on[-1].get("total"),
                       "speed_first": on[0].get("speed"), "speed_last": on[-1].get("speed"),
                       "P0_P4_during": sorted({(s["P0"], s["P4"]) for s in on})}
        fr = [(s["t"], s["frame"]) for s in on if "frame" in s]
        final = max(v for _, v in fr) if fr else 0
        moving = [(t, v) for t, v in fr if 0 < v < final]
        if len(moving) >= 2:
            n = len(moving)
            mt = sum(t for t, _ in moving) / n
            mv = sum(v for _, v in moving) / n
            sxx = sum((t - mt) ** 2 for t, _ in moving)
            sxy = sum((t - mt) * (v - mv) for t, v in moving)
            slope = sxy / sxx if sxx else 0.0
            icpt = mv - slope * mt
            t_first = (1 - icpt) / slope if slope else None
            t_final = (final - icpt) / slope if slope else None
            first_final = next((t for t, v in fr if v == final), None)
            spd = on[-1].get("speed") or 0
            tot = on[-1].get("total") or 0
            out["roll"] = {"updates_per_s": round(slope, 2), "final_frame": final,
                           "final_x_speed": round(final * spd, 1), "total": tot,
                           "isFinish_reached": bool(spd and final * spd > tot),
                           "t_first_update": round(t_first, 2) if t_first is not None else None,
                           "t_finish_fit": round(t_final, 2) if t_final is not None else None,
                           "t_finish_first_sample": first_final,
                           "roll_secs": round(t_final - t_first, 2) if t_first is not None else None}
            if t_first is not None:
                ms = t_first - 571 / 60.0
                out["roll"]["music_start_est_t"] = round(ms, 2)
                out["roll"]["text_end_minus_music_end_est"] = round(t_final - (ms + 214.0), 2)
        if fr:
            out["roll"] = out.get("roll", {})
            out["roll"]["frame_last_sample"] = fr[-1]
    # BGM handles / field BGM state
    bc, last = [], None
    for s in smp:
        k = (tuple(s.get("bgm", [])), tuple(s.get("fb", [])))
        if k != last and "bgm" in s:
            bc.append({"t": s["t"], "wall": s.get("wall"), "bgm": [f"{x:#x}" for x in s["bgm"]],
                       "fld_bgm": [s["fb"][0], f"{s['fb'][1]:#x}", s["fb"][2], f"{s['fb'][3]:#x}"] if "fb" in s else None})
            last = k
    out["bgm_changes"] = bc[:40]
    if on and "roll" in out:
        t_on = on[0]["t"]
        play = next((s["t"] for s in smp if s["t"] >= t_on and "fb" in s and s["fb"][0] == 1
                     and s["fb"][1] == END_ROLL_ID), None)
        end = None
        if play is not None:
            end = next((s["t"] for s in smp if s["t"] > play and s.get("bgm") and s["bgm"][0] == 0), None)
        r = out["roll"]
        r["music_play_t"] = play
        r["music_handle_detached_t"] = end
        if play is not None and end is not None:
            r["music_secs_measured"] = round(end - play, 2)
        if play is not None and r.get("t_first_update") is not None:
            r["first_update_minus_play"] = round(r["t_first_update"] - play, 2)
        if end is not None and r.get("t_finish_fit") is not None:
            r["text_end_minus_music_end_measured"] = round(r["t_finish_fit"] - end, 2)
    # watch words
    hdrw = hdr.get("watch", [])
    ww = []
    for i, name in enumerate(hdrw):
        ser = [(s["t"], s["w"][i]) for s in smp if "w" in s]
        if not ser:
            continue
        rr = runs_of_change(ser, quiet=3.0)
        dt = ser[-1][0] - ser[0][0]
        rate = (ser[-1][1] - ser[0][1]) / dt if dt else 0
        ww.append({"addr": name, "first": ser[0][1], "last": ser[-1][1], "mean_rate": round(rate, 2),
                   "runs": rr[:12]})
    out["watch"] = ww
    # room candidates
    ro = next((s["room_offsets"] for s in smp if "room_offsets" in s), None)
    if ro:
        rc = []
        for i, off in enumerate(ro):
            ser = [(s["t"], s["rooms"][i]) for s in smp if "rooms" in s and len(s["rooms"]) > i]
            ch, lv = [], None
            for t, v in ser:
                if v != lv:
                    ch.append([t, f"{v:#x}"])
                    lv = v
            rc.append({"off": off, "changes": ch[:10]})
        out["room_candidates"] = rc
    # freezes (field/task frame counter unchanged for >= 3 s while RPC answers)
    fz, lastv, lastt = [], None, None
    for s in smp:
        v = (s.get("tctr"), s.get("fctr"))
        if v != lastv:
            if lastt is not None and s["t"] - lastt >= 3.0:
                fz.append([lastt, s["t"]])
            lastv, lastt = v, s["t"]
    if smp and lastt is not None and smp[-1]["t"] - lastt >= 3.0:
        fz.append([lastt, smp[-1]["t"], "until end"])
    out["freezes"] = fz
    # frame-counter rate (fld) in 10-s windows
    fr10 = []
    fs = [(s["t"], s["fctr"]) for s in smp if s.get("fctr") is not None]
    if fs:
        k = 0
        while k < len(fs):
            j = k
            while j + 1 < len(fs) and fs[j + 1][0] - fs[k][0] <= 10.0:
                j += 1
            if j > k and fs[j][1] >= fs[k][1]:
                fr10.append([round(fs[k][0], 1), round((fs[j][1] - fs[k][1]) / (fs[j][0] - fs[k][0]), 1)])
            k = j + 1
    out["fld_ctr_rate_10s"] = fr10
    sp = path.with_name(path.stem + "_summary.json")
    sp.write_text(json.dumps(out, indent=1), encoding="utf-8")
    return out


def main(argv=None) -> None:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    p = sub.add_parser("follow")
    p.add_argument("--label", required=True); p.add_argument("--secs", type=float, default=300.0)
    p.add_argument("--hz", type=float, default=4.0); p.add_argument("--flip", action="store_true")
    p.add_argument("--max-flips", type=int, default=20)
    p.add_argument("--watch", default=""); p.add_argument("--find-room", action="store_true")
    p.add_argument("--room-len", type=lambda s: int(s, 0), default=0x20000)
    p = sub.add_parser("summary"); p.add_argument("file")
    a = ap.parse_args(argv)
    if a.cmd == "follow":
        path = follow(a)
        out = summarize(path)
    else:
        out = summarize(Path(a.file))
    brief = {k: v for k, v in out.items() if k not in ("fld_changes",)}
    print(json.dumps(brief, indent=1))


if __name__ == "__main__":
    main()
