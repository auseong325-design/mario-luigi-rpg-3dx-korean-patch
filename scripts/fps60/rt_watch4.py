"""RT4 (wave 4): light RPC monitor, desktop grabs and key+grab bursts for the TEST instance only.

  rt_watch4.py follow --label L [--secs S] [--hz H] [--f32 NAME=ADDR] [--u32 NAME=ADDR]
                      [--pf32 NAME=PTR+OFF] [--pu32 NAME=PTR+OFF]
      Every sample (not only changes) as one JSON line in work/fps60/runtime/rt4/L.jsonl:
      t, wall, current task [0x3F40B4] (+vptr, +0x3D/+0x41/+0x45, +0x578),
      fld::System [0x3F49D0] (+0x3D/+0x41/+0x45, +0x578, +0x1A4C step, +0x1A48 ffwd),
      btl::Main [0x3F3600] (+0x3D/+0x41/+0x45, +0x578, +0xBA15C step, +0x8A3C, [[+0x574]+0x7C],
      badge gauge words +0x18A8/+0x18B0), latch 0x434F00..0x434F0F, plus the extra probes.
      Run it detached (Start-Process -WindowStyle Hidden, no redirection); it stops after --secs.
  rt_watch4.py grab OUT.png [--max 1600]
      Desktop grab of the test window's render surface (the window must be visible), scaled so that no
      side exceeds --max.
  rt_watch4.py burst DIR --n N --dt MS [--keys T1,T2,...] [--key-delay MS] [--max 800]
      Sends TOKENS (rt_input.py syntax, in a thread, starting after --key-delay) while grabbing N frames every
      MS; writes DIR/fNNN.png + DIR/index.json (frame times and key-down/up times on one clock).
  rt_watch4.py sheet DIR OUT.png [--cols C] [--every K] [--first A] [--last B] [--max 1600]
      Contact sheet of a burst (each tile labelled with its time), at most --max px per side.

Safety: input and grabs go only to the process named in tools/azahar-test/rt_azahar.pid
(rt_input.check_instance: exactly one azahar.exe, PID match, image = tools/azahar-test/azahar.exe).
RPC reads only; no writes.
"""
from __future__ import annotations

import argparse
import json
import struct
import sys
import threading
import time
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import rt_rpc  # noqa: E402

ROOT = Path(__file__).resolve().parents[2]
OUTDIR = ROOT / "work" / "fps60" / "runtime" / "rt4"
CUR_TASK = 0x3F40B4
FLD_PTR = 0x3F49D0
BTL_PTR = 0x3F3600
LATCH = 0x434F00


def mapped_runs():
    j = json.loads((ROOT / "work" / "fps60" / "runtime" / "memmap.json").read_text(encoding="utf-8"))
    return [(int(r["start"], 16), int(r["end"], 16)) for r in j["runs"]]


def ok(addr, size, runs):
    return addr and any(lo <= addr and addr + size <= hi for lo, hi in runs)


def f32(b, o=0):
    return round(struct.unpack_from("<f", b, o)[0], 4)


def parse_probe(s):
    name, rest = s.split("=", 1)
    if "+" in rest:
        p, o = rest.split("+", 1)
        return name, int(p, 0), int(o, 0)
    return name, int(rest, 0), None


def cmd_follow(a):
    OUTDIR.mkdir(parents=True, exist_ok=True)
    out = OUTDIR / f"{a.label}.jsonl"
    rpc = rt_rpc.Rpc(timeout=1.0)
    rpc.select_game()
    runs = mapped_runs()
    probes = [("f", *parse_probe(s)) for s in a.f32] + [("I", *parse_probe(s)) for s in a.u32]
    probes += [("pf", *parse_probe(s)) for s in a.pf32] + [("pI", *parse_probe(s)) for s in a.pu32]
    t0 = time.perf_counter()
    n = 0
    with out.open("a", encoding="utf-8") as fh:
        fh.write(json.dumps({"start": time.strftime("%Y-%m-%d %H:%M:%S"), "label": a.label, "hz": a.hz}) + "\n")
        while True:
            t = time.perf_counter() - t0
            row = {"t": round(t, 3), "wall": round(time.time(), 3)}
            try:
                task = rpc.u32(CUR_TASK)
                row["task"] = f"{task:#x}"
                if ok(task, 0x580, runs):
                    h = rpc.read(task, 0x48)
                    row.update(vptr=f"{struct.unpack_from('<I', h)[0]:#x}", t3D=h[0x3D], t41=h[0x41], t45=h[0x45],
                               tctr=rpc.u32(task + 0x578))
                fp = rpc.u32(FLD_PTR)
                row["fld"] = f"{fp:#x}"
                if ok(fp, 0x1A60, runs):
                    h = rpc.read(fp + 0x3C, 0x10)
                    row.update(f3D=h[1], f41=h[5], f45=h[9], fctr=rpc.u32(fp + 0x578))
                    s = rpc.read(fp + 0x1A48, 8)
                    row.update(fstep=f32(s, 4), fffwd=f32(s, 0))
                bp = rpc.u32(BTL_PTR)
                row["btl"] = f"{bp:#x}"
                if ok(bp, 0xBA160, runs):
                    h = rpc.read(bp + 0x3C, 0x10)
                    row.update(b3D=h[1], b41=h[5], b45=h[9], bctr=rpc.u32(bp + 0x578))
                    row["bstep"] = f32(rpc.read(bp + 0xBA15C, 4))
                    row["b8A3C"] = f32(rpc.read(bp + 0x8A3C, 4))
                    p574 = rpc.u32(bp + 0x574)
                    if ok(p574 + 0x7C, 4, runs):
                        row["bspeed"] = f32(rpc.read(p574 + 0x7C, 4))
                    g = rpc.read(bp + 0x18A8, 0x10)
                    row["badge"] = [struct.unpack_from("<I", g, 0)[0], struct.unpack_from("<I", g, 8)[0]]
                lt = rpc.read(LATCH, 0x10)
                row["latch"] = list(struct.unpack("<4I", lt))
                for kind, name, p, o in probes:
                    if kind in ("pf", "pI"):
                        base = rpc.u32(p)
                        addr = base + o if base else 0
                    else:
                        addr = p
                    if ok(addr, 4, runs):
                        b = rpc.read(addr, 4)
                        row[name] = f32(b) if kind in ("f", "pf") else struct.unpack("<I", b)[0]
                    else:
                        row[name] = None
            except Exception as ex:  # keep logging through transient RPC errors
                row["err"] = repr(ex)[:120]
            fh.write(json.dumps(row) + "\n")
            n += 1
            if n % 20 == 0:
                fh.flush()
            if t >= a.secs:
                break
            time.sleep(max(0.0, 1.0 / a.hz - 0.003))
    print(f"{out}: {n} samples")


def render_rect():
    import rt_input
    pid = rt_input.check_instance()
    _, render = rt_input.find_windows(pid)
    return rt_input.wrect(render)


def crop_rect(rect, which):
    """Screen rect of the top / bottom 3DS screen inside the render rect (default layout: top 400x240 above a
    centred 320x240 bottom screen, same scale)."""
    l, t, r, b = rect
    if which in (None, "", "all"):
        return rect
    w, h = r - l, b - t
    s = min(w / 400, h / 480)
    y0 = t + (h - 480 * s) / 2
    if which == "top":
        x0 = l + (w - 400 * s) / 2
        return (int(x0), int(y0), int(x0 + 400 * s), int(y0 + 240 * s))
    x0 = l + (w - 320 * s) / 2
    return (int(x0), int(y0 + 240 * s), int(x0 + 320 * s), int(y0 + 480 * s))


def grab_img(rect):
    from PIL import ImageGrab
    return ImageGrab.grab(bbox=rect, all_screens=True)


def fit(img, mx):
    w, h = img.size
    s = min(1.0, mx / max(w, h))
    if s < 1.0:
        img = img.resize((max(1, int(w * s)), max(1, int(h * s))))
    return img


def cmd_grab(a):
    rect = crop_rect(render_rect(), a.crop)
    img = fit(grab_img(rect), a.max)
    img.save(a.out)
    print(f"saved {a.out} {img.size} from rect {rect}")


def cmd_burst(a):
    import rt_input
    pid = rt_input.check_instance()
    _, render = rt_input.find_windows(pid)
    rect = crop_rect(rt_input.wrect(render), a.crop)
    d = Path(a.dir)
    d.mkdir(parents=True, exist_ok=True)
    events = []
    t0 = time.perf_counter()
    wall0 = round(time.time(), 4)

    def sender():
        time.sleep(a.key_delay / 1000)
        for tok in [x for x in (a.keys or "").replace(",", " ").split() if x]:
            tok = tok.upper()
            if tok.startswith("W") and tok[1:].isdigit():
                time.sleep(int(tok[1:]) / 1000)
                continue
            hold = 90
            if ":" in tok:
                tok, hs = tok.split(":")
                hold = int(hs)
            keys = [rt_input.BUTTONS[b] for b in tok.split("+")]
            for k in keys:
                rt_input.post(render, rt_input.WM_KEYDOWN, rt_input.VK[k],
                              rt_input.key_lparam(rt_input.VK[k], False, k in rt_input.EXTENDED))
            events.append({"t": round(time.perf_counter() - t0, 4), "down": tok})
            time.sleep(hold / 1000)
            for k in reversed(keys):
                rt_input.post(render, rt_input.WM_KEYUP, rt_input.VK[k],
                              rt_input.key_lparam(rt_input.VK[k], True, k in rt_input.EXTENDED))
            events.append({"t": round(time.perf_counter() - t0, 4), "up": tok})
            time.sleep(a.gap / 1000)

    th = threading.Thread(target=sender)
    th.start()
    frames = []
    for i in range(a.n):
        target = i * a.dt / 1000
        now = time.perf_counter() - t0
        if target > now:
            time.sleep(target - now)
        ts = time.perf_counter() - t0
        img = grab_img(rect)
        te = time.perf_counter() - t0
        fit(img, a.max).save(d / f"f{i:03d}.png")
        frames.append({"i": i, "t0": round(ts, 4), "t1": round(te, 4)})
    th.join()
    (d / "index.json").write_text(json.dumps({"rect": rect, "wall0": wall0, "frames": frames, "keys": events}, indent=1),
                                  encoding="utf-8")
    print(f"{d}: {len(frames)} frames, keys {events}")


def cmd_sheet(a):
    from PIL import Image, ImageDraw
    d = Path(a.dir)
    idx = json.loads((d / "index.json").read_text(encoding="utf-8"))
    fr = [f for f in idx["frames"] if a.first <= f["i"] <= (a.last if a.last >= 0 else 10 ** 9)][::a.every]
    ims = [Image.open(d / f"f{f['i']:03d}.png") for f in fr]
    if not ims:
        raise SystemExit("no frames")
    w, h = ims[0].size
    cols = a.cols
    rows = (len(ims) + cols - 1) // cols
    sheet = Image.new("RGB", (cols * w, rows * (h + 14)), (40, 40, 40))
    dr = ImageDraw.Draw(sheet)
    for k, (f, im) in enumerate(zip(fr, ims)):
        x, y = (k % cols) * w, (k // cols) * (h + 14)
        sheet.paste(im, (x, y + 14))
        dr.text((x + 2, y + 1), f"#{f['i']} {f['t0']:.3f}s", fill=(255, 255, 0))
    sheet = fit(sheet, a.max)
    sheet.save(a.out)
    print(f"saved {a.out} {sheet.size} ({len(ims)} tiles)")


def cmd_rtti(a):
    rpc = rt_rpc.Rpc(timeout=1.0)
    rpc.select_game()
    rt_rpc.flush_log(rpc)
    cros = rt_rpc.parse_cro_log()
    syms = rt_rpc.load_symbols()
    ranges = []
    for r in a.range:
        s, n = r.split(":")
        ranges.append((int(s, 0), int(n, 0)))
    found = rt_rpc.find_tasks(rpc, ranges, cros, syms, all_classes=True)
    hits = [f for f in found if any(a.cls in x for x in [f["class"]] + f["bases"])]
    for f in hits[: a.max]:
        print(json.dumps({k: f[k] for k in ("addr", "vptr", "module", "class", "bases")}))
    print(f"{len(hits)} hits ({len(found)} RTTI objects scanned)")


def cmd_react(a):
    """Pre keys, then poll the battle attack register $707c (AISys+0x160, AISys = [[0x3F3600]+0xBA148]) until it
    becomes non-zero (the judge loop of atk_pc_solo_* has started its window timer), wait value*1000/60 + offset ms,
    press the button, then poll $707d (AISys+0x164) for the judgement (atk_pc_solo_jump: 3/5 excellent, 2/4 good,
    1 fail) until --timeout."""
    import rt_input
    rpc = rt_rpc.Rpc(timeout=1.0)
    rpc.select_game()
    pid = rt_input.check_instance()
    _, render = rt_input.find_windows(pid)
    main_ = rpc.u32(BTL_PTR)
    ais = rpc.u32(main_ + 0xBA148)
    trig, res = ais + 0x160, ais + 0x164
    t0 = time.perf_counter()
    wall0 = time.time()
    log = {"main": f"{main_:#x}", "aisys": f"{ais:#x}", "wall0": round(wall0, 4), "events": []}

    def ev(**kw):
        kw["t"] = round(time.perf_counter() - t0, 4)
        log["events"].append(kw)

    def press(tok, hold):
        keys = [rt_input.BUTTONS[b] for b in tok.split("+")]
        for k in keys:
            rt_input.post(render, rt_input.WM_KEYDOWN, rt_input.VK[k],
                          rt_input.key_lparam(rt_input.VK[k], False, k in rt_input.EXTENDED))
        ev(down=tok)
        time.sleep(hold / 1000)
        for k in reversed(keys):
            rt_input.post(render, rt_input.WM_KEYUP, rt_input.VK[k],
                          rt_input.key_lparam(rt_input.VK[k], True, k in rt_input.EXTENDED))
        ev(up=tok)

    for tok in [x for x in a.pre.replace(",", " ").split() if x]:
        tok = tok.upper()
        if tok.startswith("W") and tok[1:].isdigit():
            time.sleep(int(tok[1:]) / 1000)
        else:
            press(tok, 90)
    v0 = struct.unpack("<f", rpc.read(trig, 4))[0]
    ev(start_707c=v0)
    deadline = time.perf_counter() + a.timeout
    val = 0.0
    while time.perf_counter() < deadline:
        val = struct.unpack("<f", rpc.read(trig, 4))[0]
        if val != 0.0 and val != v0:
            break
        if v0 != 0.0 and val == 0.0:
            v0 = 0.0
    else:
        ev(error="trigger not seen")
        print(json.dumps(log))
        return
    ev(trigger_707c=val, d707d=struct.unpack("<f", rpc.read(res, 4))[0])
    delay = val * 1000 / 60 + a.offset_ms
    time.sleep(max(0.0, delay / 1000))
    press(a.button, a.hold)
    end = time.perf_counter() + 3.0
    last = None
    while time.perf_counter() < end:
        r = struct.unpack("<f", rpc.read(res, 4))[0]
        if r != last:
            ev(r707d=r)
            last = r
        time.sleep(0.002)
    print(json.dumps(log))


def cmd_hold(a):
    """T2 (atk_dstar_4) driver. Waits until $707C (AISys+0x160) is one of 144/160/172 (the attack set its hold
    duration), optionally grabs frames, waits --watch ms (star orbit), then taps A+B (down --spam-hold ms, up
    --spam-up ms) until $707E (AISys+0x168, number of bros hanging) reaches 2 or $707D (+0x164, phase) leaves 0,
    keeps A+B held for --before ms, releases for --gap ms, holds again until $707D == 3 (+1 s), and logs every
    change of $707D/$707E/$707F with times (one clock)."""
    import rt_input
    rpc = rt_rpc.Rpc(timeout=1.0)
    rpc.select_game()
    pid = rt_input.check_instance()
    _, render = rt_input.find_windows(pid)
    main_ = rpc.u32(BTL_PTR)
    ais = rpc.u32(main_ + 0xBA148)
    t0 = time.perf_counter()
    log = {"main": f"{main_:#x}", "aisys": f"{ais:#x}", "wall0": round(time.time(), 4), "events": [], "frames": []}
    keys_ab = [rt_input.BUTTONS["A"], rt_input.BUTTONS["B"]]

    def now():
        return round(time.perf_counter() - t0, 4)

    def regs():
        b = rpc.read(ais + 0x160, 0x10)
        return struct.unpack("<4f", b)

    def ab(down):
        for k in keys_ab:
            rt_input.post(render, rt_input.WM_KEYDOWN if down else rt_input.WM_KEYUP, rt_input.VK[k],
                          rt_input.key_lparam(rt_input.VK[k], not down, False))
        log["events"].append({"t": now(), "AB": "down" if down else "up"})

    last = [None]

    def poll():
        r = regs()
        if r != last[0]:
            log["events"].append({"t": now(), "707c": r[0], "707d": r[1], "707e": r[2], "707f": r[3]})
            last[0] = r
        return r

    deadline = time.perf_counter() + a.wait
    while True:
        r = poll()
        if r[0] in (144.0, 160.0, 172.0):
            break
        if time.perf_counter() > deadline:
            print(json.dumps(log))
            return
        time.sleep(0.002)
    log["events"].append({"t": now(), "trigger": r[0]})
    stop = threading.Event()
    if a.frames:
        rect = crop_rect(rt_input.wrect(render), "bottom")
        d = Path(a.dir)
        d.mkdir(parents=True, exist_ok=True)

        def grabber():
            for i in range(a.frames):
                if stop.is_set():
                    break
                target = i * a.frame_dt / 1000
                t = time.perf_counter() - tf0
                if target > t:
                    time.sleep(target - t)
                ts = now()
                fit(grab_img(rect), 400).save(d / f"f{i:03d}.png")
                log["frames"].append({"i": i, "t0": ts})
        tf0 = time.perf_counter()
        th = threading.Thread(target=grabber)
        th.start()
    end_watch = time.perf_counter() + a.watch / 1000
    while time.perf_counter() < end_watch:
        poll()
        time.sleep(0.003)
    spam_end = time.perf_counter() + a.spam_secs
    grabbed = False
    while time.perf_counter() < spam_end:
        ab(True)
        t_up = time.perf_counter() + a.spam_hold / 1000
        while time.perf_counter() < t_up:
            r = poll()
            if r[2] >= 2.0:
                grabbed = True
                break
            time.sleep(0.002)
        if grabbed:
            break
        ab(False)
        t_dn = time.perf_counter() + a.spam_up / 1000
        while time.perf_counter() < t_dn:
            r = poll()
            time.sleep(0.002)
        if r[2] >= 2.0:
            ab(True)
            grabbed = True
            break
        if r[1] != 0.0:
            break
    log["events"].append({"t": now(), "grabbed_both": grabbed})
    if grabbed:
        t1 = time.perf_counter() + a.before / 1000
        while time.perf_counter() < t1:
            poll()
            time.sleep(0.002)
        ab(False)
        t2 = time.perf_counter() + a.gap / 1000
        while time.perf_counter() < t2:
            poll()
            time.sleep(0.001)
        ab(True)
    t3 = time.perf_counter() + a.timeout
    seen3 = None
    while time.perf_counter() < t3:
        r = poll()
        if r[1] == 3.0 and seen3 is None:
            seen3 = time.perf_counter()
        if seen3 is not None and time.perf_counter() - seen3 > 1.0:
            break
        time.sleep(0.003)
    ab(False)
    stop.set()
    if a.frames:
        th.join()
    print(json.dumps(log))


def cmd_sample(a):
    """Wait for the T2 attack trigger ($707C in 144/160/172), then read the given ranges at --hz for --secs and
    store {t, regs $707C..$707F, hex of every range} lines in OUT (JSON lines)."""
    rpc = rt_rpc.Rpc(timeout=1.0)
    rpc.select_game()
    main_ = rpc.u32(BTL_PTR)
    ais = rpc.u32(main_ + 0xBA148)
    rngs = []
    for r in a.range:
        s, n = r.split(":")
        rngs.append((int(s, 0), int(n, 0)))
    t0 = time.perf_counter()
    deadline = t0 + a.wait
    while time.perf_counter() < deadline:
        r = struct.unpack("<4f", rpc.read(ais + 0x160, 0x10))
        if r[0] in (144.0, 160.0, 172.0):
            break
        time.sleep(0.002)
    else:
        print("no trigger")
        return
    t1 = time.perf_counter()
    n = 0
    with open(a.out, "w", encoding="utf-8") as fh:
        fh.write(json.dumps({"wall_trigger": round(time.time(), 4), "ranges": [[hex(s), l] for s, l in rngs]}) + "\n")
        while time.perf_counter() - t1 < a.secs:
            t = time.perf_counter() - t1
            regs = struct.unpack("<4f", rpc.read(ais + 0x160, 0x10))
            data = [rpc.read(s, l).hex() for s, l in rngs]
            fh.write(json.dumps({"t": round(t, 4), "regs": regs, "d": data}) + "\n")
            n += 1
            nxt = t1 + n / a.hz
            dt = nxt - time.perf_counter()
            if dt > 0:
                time.sleep(dt)
    print(f"{a.out}: {n} samples")


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    p = sub.add_parser("follow")
    p.add_argument("--label", required=True)
    p.add_argument("--secs", type=float, default=60.0)
    p.add_argument("--hz", type=float, default=20.0)
    for k in ("f32", "u32", "pf32", "pu32"):
        p.add_argument(f"--{k}", action="append", default=[])
    p = sub.add_parser("grab")
    p.add_argument("out")
    p.add_argument("--max", type=int, default=1600)
    p.add_argument("--crop", default="all", choices=["all", "top", "bottom"])
    p = sub.add_parser("burst")
    p.add_argument("--crop", default="all", choices=["all", "top", "bottom"])
    p.add_argument("dir")
    p.add_argument("--n", type=int, default=20)
    p.add_argument("--dt", type=float, default=50.0)
    p.add_argument("--keys", default="")
    p.add_argument("--key-delay", type=float, default=0.0)
    p.add_argument("--gap", type=float, default=0.0)
    p.add_argument("--max", type=int, default=800)
    p = sub.add_parser("sheet")
    p.add_argument("dir")
    p.add_argument("out")
    p.add_argument("--cols", type=int, default=6)
    p.add_argument("--every", type=int, default=1)
    p.add_argument("--first", type=int, default=0)
    p.add_argument("--last", type=int, default=-1)
    p.add_argument("--max", type=int, default=1600)
    p = sub.add_parser("react")
    p.add_argument("--pre", default="")
    p.add_argument("--button", default="A")
    p.add_argument("--hold", type=float, default=60.0)
    p.add_argument("--offset-ms", type=float, default=0.0)
    p.add_argument("--timeout", type=float, default=6.0)
    p = sub.add_parser("hold")
    p.add_argument("--wait", type=float, default=60.0, help="s to wait for the attack trigger")
    p.add_argument("--watch", type=float, default=0.0, help="ms to watch the orbit before tapping")
    p.add_argument("--spam-secs", type=float, default=6.0)
    p.add_argument("--spam-hold", type=float, default=250.0)
    p.add_argument("--spam-up", type=float, default=60.0)
    p.add_argument("--before", type=float, default=1000.0)
    p.add_argument("--gap", type=float, default=200.0)
    p.add_argument("--timeout", type=float, default=12.0)
    p.add_argument("--frames", type=int, default=0)
    p.add_argument("--frame-dt", type=float, default=33.0)
    p.add_argument("--dir", default="")
    p = sub.add_parser("sample")
    p.add_argument("--range", action="append", required=True)
    p.add_argument("--hz", type=float, default=60.0)
    p.add_argument("--secs", type=float, default=6.0)
    p.add_argument("--wait", type=float, default=60.0)
    p.add_argument("--out", required=True)
    p = sub.add_parser("rtti")
    p.add_argument("--range", action="append", required=True, help="ADDR:LEN")
    p.add_argument("--cls", required=True, help="substring of the class or a base class name")
    p.add_argument("--max", type=int, default=40)
    a = ap.parse_args(argv)
    {"follow": cmd_follow, "grab": cmd_grab, "burst": cmd_burst, "sheet": cmd_sheet, "rtti": cmd_rtti, "react": cmd_react, "hold": cmd_hold, "sample": cmd_sample}[a.cmd](a)


if __name__ == "__main__":
    main()
