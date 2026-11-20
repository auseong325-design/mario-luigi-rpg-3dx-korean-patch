"""RT5 wrapper around scripts/fps60/rt_watch4.py (not modified): same commands, outputs in RT5's own folder.

  rt5_watch.py follow --label L [--secs S] [--hz H] [...]   -> work/review/rt5_20261030/logs/L.jsonl (rt_watch4 follow)
  rt5_watch.py burst2 DIR --n N --dt MS [--keys ...] [--key-delay MS]
      like rt_watch4 burst, but every frame also saves the window's status bar strip (App FPS / Speed / Frame time)
      at full resolution: DIR/fNNN.png (render surface, <= 800 px) + DIR/sNNN.png (status bar) + DIR/index.json
  rt5_watch.py strips DIR OUT.png [--every K] [--x0 FRAC]   stack the status strips (right part) with their times
"""
from __future__ import annotations

import argparse
import json
import sys
import threading
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT / "scripts" / "fps60"))
import rt_watch4  # noqa: E402

rt_watch4.OUTDIR = ROOT / "work" / "review" / "rt5_20261030" / "logs"


def burst2(a):
    import rt_input
    pid = rt_input.check_instance()
    main_h, render = rt_input.find_windows(pid)
    rl, rt, rr, rb = rt_input.wrect(render)
    ml, mt, mr, mb = rt_input.wrect(main_h)
    full = (rl, rt, rr, mb - 4)
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
        img = rt_watch4.grab_img(full)
        te = time.perf_counter() - t0
        h_render = rb - rt
        rt_watch4.fit(img.crop((0, 0, img.width, h_render)), a.max).save(d / f"f{i:03d}.png")
        img.crop((0, h_render, img.width, img.height)).save(d / f"s{i:03d}.png")
        frames.append({"i": i, "t0": round(ts, 4), "t1": round(te, 4), "wall": round(wall0 + ts, 4)})
    th.join()
    (d / "index.json").write_text(json.dumps({"rect": full, "wall0": wall0, "frames": frames, "keys": events},
                                             indent=1), encoding="utf-8")
    print(f"{d}: {len(frames)} frames, keys {events}")


def strips(a):
    from PIL import Image, ImageDraw
    d = Path(a.dir)
    idx = json.loads((d / "index.json").read_text(encoding="utf-8"))
    fr = idx["frames"][::a.every]
    ims = []
    for f in fr:
        im = Image.open(d / f"s{f['i']:03d}.png").convert("RGB")
        im = im.crop((int(im.width * a.x0), 0, im.width, im.height))
        ims.append((f, im))
    w = max(im.width for _, im in ims) + 90
    h = sum(im.height for _, im in ims)
    sheet = Image.new("RGB", (w, h), (0, 0, 0))
    dr = ImageDraw.Draw(sheet)
    y = 0
    for f, im in ims:
        sheet.paste(im, (90, y))
        dr.text((2, y + 2), f"#{f['i']} {f['t0']:.2f}s", fill=(255, 255, 0))
        y += im.height
    s = min(1.0, 1600 / max(sheet.size))
    if s < 1.0:
        sheet = sheet.resize((int(sheet.width * s), int(sheet.height * s)))
    sheet.save(a.out)
    print(f"saved {a.out} {sheet.size}")


def main():
    if len(sys.argv) > 1 and sys.argv[1] in ("follow", "burst", "sheet", "grab"):
        return rt_watch4.main(sys.argv[1:])
    ap = argparse.ArgumentParser()
    sub = ap.add_subparsers(dest="cmd", required=True)
    p = sub.add_parser("burst2")
    p.add_argument("dir")
    p.add_argument("--n", type=int, default=20)
    p.add_argument("--dt", type=float, default=100.0)
    p.add_argument("--keys", default="")
    p.add_argument("--key-delay", type=float, default=0.0)
    p.add_argument("--gap", type=float, default=0.0)
    p.add_argument("--max", type=int, default=800)
    p = sub.add_parser("strips")
    p.add_argument("dir")
    p.add_argument("out")
    p.add_argument("--every", type=int, default=1)
    p.add_argument("--x0", type=float, default=0.55)
    a = ap.parse_args()
    {"burst2": burst2, "strips": strips}[a.cmd](a)


if __name__ == "__main__":
    main()
