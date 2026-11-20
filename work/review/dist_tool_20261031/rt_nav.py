"""Drive the already-running TEST instance (tools/azahar-test) through title -> file select -> mode select ->
field -> pause menu, measuring the current task's fps byte / frame rate and grabbing the screen at each stop.

  rt_nav.py LABEL [--wait 45] [--only-title]
State-driven: after each press it reads the current task (rt_measure.py) and retries a press that the game did not
take (an A during the title intro only skips the intro). Runs only the project's own RT clients (rt_measure.py task,
rt_input.py keys, pw_grab.py) as child processes; they refuse unless the test instance named in
tools/azahar-test/rt_azahar.pid is the one running. Writes runtime_<LABEL>.json and runtime_<LABEL>_<stop>.png
(max 800 px) next to this script. Sends no save input.
"""
from __future__ import annotations

import argparse
import json
import os
import subprocess
import sys
import time
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
PY = str(ROOT / ".venv" / "Scripts" / "python.exe")
FPS = ROOT / "scripts" / "fps60"
LOADMENU, FIELD = "load_menu::LoadMenuTask", "fld::System"


def run(args: list[str], timeout: int = 120) -> str:
    p = subprocess.run([PY, *args], cwd=ROOT, capture_output=True, text=True, encoding="utf-8", errors="replace",
                       timeout=timeout, env={**os.environ, "PYTHONDONTWRITEBYTECODE": "1", "PYTHONIOENCODING": "utf-8"})
    if p.returncode:
        raise RuntimeError(f"{args[0]} failed: {p.stderr.strip()[-400:]}")
    return p.stdout


def measure(label: str) -> dict:
    out = run([str(FPS / "rt_measure.py"), "task", "--secs", "2", "--label", label])
    d = json.loads(out[out.index("{"):])
    return {k: d.get(k) for k in ("cur_task", "vptr", "class", "fps_init_3D", "fps_live_45", "ctr_578_per_s")}


def grab(label: str, stop: str) -> str:
    """PrintWindow capture (pw_grab.py): a system dialog lying on top of the emulator is not captured."""
    png = HERE / f"runtime_{label}_{stop}.png"
    run([str(HERE / "pw_grab.py"), str(png), "--max", "800"])
    return png.name


def keys(*tokens: str) -> None:
    run([str(FPS / "rt_input.py"), "keys", *tokens], timeout=90)


def is_(m: dict, cls: str) -> bool:
    return cls in (m.get("class") or [])


def press_until(label: str, key: str, wait_ms: int, ok, tries: int, log: list) -> dict:
    m: dict = {}
    for i in range(tries):
        keys(key, f"w{wait_ms}")
        m = measure(f"{label}_{key}{i}")
        log.append({"press": key, "try": i, "task": m.get("cur_task"), "class": (m.get("class") or [None])[-1]})
        if ok(m):
            break
    return m


def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("label")
    ap.add_argument("--wait", type=int, default=45)
    ap.add_argument("--only-title", action="store_true")
    a = ap.parse_args()
    L = a.label
    res: dict = {"label": L, "start": time.strftime("%Y-%m-%d %H:%M:%S"), "stops": {}, "presses": []}
    time.sleep(a.wait)
    res["stops"]["title"] = {**measure(f"{L}_title"), "png": grab(L, "title")}
    if not a.only_title:
        m = press_until(L, "A", 3500, lambda m: is_(m, LOADMENU), 3, res["presses"])       # title -> file select
        res["stops"]["file_select"] = {**m, "png": grab(L, "file")}
        keys("A", "w2500")                                                                  # open slot 1
        keys("A", "w3000")                                                                  # 시작하기 -> mode select
        res["stops"]["mode_select"] = {**measure(f"{L}_mode"), "png": grab(L, "mode")}
        m = press_until(L, "A", 12000, lambda m: is_(m, FIELD), 2, res["presses"])          # M&L RPG3 -> field
        res["stops"]["field"] = {**m, "png": grab(L, "field")}
        m = press_until(L, "START", 4000, lambda m: not is_(m, FIELD), 2, res["presses"])   # field -> pause menu
        res["stops"]["pause"] = {**m, "png": grab(L, "pause")}
        keys("B", "w1500")
    res["end"] = time.strftime("%Y-%m-%d %H:%M:%S")
    (HERE / f"runtime_{L}.json").write_text(json.dumps(res, ensure_ascii=False, indent=1), encoding="utf-8")
    sys.stdout.reconfigure(encoding="utf-8")
    print(json.dumps({k: {x: v.get(x) for x in ("cur_task", "vptr", "fps_init_3D", "ctr_578_per_s", "png")}
                      for k, v in res["stops"].items()}, ensure_ascii=False, indent=1))
    print(json.dumps(res["presses"], ensure_ascii=False))


if __name__ == "__main__":
    main()
