"""RT2: send 3DS button presses / touches to the TEST instance's render window, without taking the
user's keyboard focus or moving their mouse pointer.

Why: the accessibility tree of the Azahar window does not expose the render surface (GRenderWindow), so
`computer_press_key` has no element that can hold keyboard focus and refuses to send keys
("element 0 ... did not take keyboard focus").  Azahar feeds the emulated pad only from
GRenderWindow::keyPressEvent/keyReleaseEvent (src/citra_qt/bootmanager.cpp) and touches from its
mouse events.  We post WM_KEYDOWN/WM_KEYUP (and WM_LBUTTONDOWN/UP for touch) straight to the render
surface's native child HWND of the test process; Qt delivers them to that widget and they propagate
to GRenderWindow.  Nothing is sent to any other window.

Safety: refuses unless exactly one azahar.exe runs, its PID equals tools/azahar-test/rt_azahar.pid
and its image is tools/azahar-test/azahar.exe.

  rt_input.py keys TOKEN [TOKEN ...]
     TOKEN = BUTTON[:hold_ms][*count] | wMS (wait)    e.g.  A  A*3  CUP:1500  w500  START
     BUTTON = A B X Y L R ZL ZR START SELECT DUP DDOWN DLEFT DRIGHT CUP CDOWN CLEFT CRIGHT
     (test keyboard map, HARNESS.md section 1: A=A B=S X=Z Y=X D-pad T/G/F/H L=Q R=W ZL=1 ZR=2
      Start=M Select=N, circle pad = arrow keys).  Default hold 90 ms, gap 160 ms.
  rt_input.py touch X Y [--hold MS]     3DS bottom-screen pixel (0..319, 0..239)
  rt_input.py info                      print the windows it would target
"""
from __future__ import annotations

import argparse
import ctypes
import ctypes.wintypes as wt
import sys
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
TEST = ROOT / "tools" / "azahar-test"
EXE = (TEST / "azahar.exe").resolve()
PIDFILE = TEST / "rt_azahar.pid"

user32 = ctypes.WinDLL("user32", use_last_error=True)
kernel32 = ctypes.WinDLL("kernel32", use_last_error=True)
user32.SetProcessDPIAware()  # physical pixels for window rects

WM_KEYDOWN, WM_KEYUP = 0x0100, 0x0101
WM_LBUTTONDOWN, WM_LBUTTONUP, WM_MOUSEMOVE = 0x0201, 0x0202, 0x0200
MK_LBUTTON = 0x0001
VK = {"A": 0x41, "S": 0x53, "Z": 0x5A, "X": 0x58, "T": 0x54, "G": 0x47, "F": 0x46, "H": 0x48,
      "Q": 0x51, "W": 0x57, "1": 0x31, "2": 0x32, "M": 0x4D, "N": 0x4E,
      "UP": 0x26, "DOWN": 0x28, "LEFT": 0x25, "RIGHT": 0x27}
EXTENDED = {"UP", "DOWN", "LEFT", "RIGHT"}
BUTTONS = {"A": "A", "B": "S", "X": "Z", "Y": "X", "L": "Q", "R": "W", "ZL": "1", "ZR": "2",
           "START": "M", "SELECT": "N", "DUP": "T", "DDOWN": "G", "DLEFT": "F", "DRIGHT": "H",
           "CUP": "UP", "CDOWN": "DOWN", "CLEFT": "LEFT", "CRIGHT": "RIGHT"}

EnumProc = ctypes.WINFUNCTYPE(wt.BOOL, wt.HWND, wt.LPARAM)


def process_image(pid: int) -> str | None:
    h = kernel32.OpenProcess(0x1000, False, pid)  # PROCESS_QUERY_LIMITED_INFORMATION
    if not h:
        return None
    try:
        buf = ctypes.create_unicode_buffer(1024)
        n = wt.DWORD(1024)
        if kernel32.QueryFullProcessImageNameW(h, 0, buf, ctypes.byref(n)):
            return buf.value
        return None
    finally:
        kernel32.CloseHandle(h)


def azahar_pids() -> list[int]:
    import subprocess
    out = subprocess.run(["tasklist", "/FI", "IMAGENAME eq azahar.exe", "/FO", "CSV", "/NH"],
                         capture_output=True, text=True, timeout=20).stdout
    pids = []
    for line in out.splitlines():
        parts = [p.strip('"') for p in line.split('","')]
        if len(parts) > 1 and parts[0].lower().strip('"') == "azahar.exe":
            pids.append(int(parts[1]))
    return pids


def check_instance() -> int:
    if not PIDFILE.exists():
        raise SystemExit("no tools/azahar-test/rt_azahar.pid: test instance not started by rt_launch.ps1")
    pid = int(PIDFILE.read_text().split()[0])
    pids = azahar_pids()
    if pids != [pid]:
        raise SystemExit(f"refusing: azahar.exe PIDs {pids}, expected exactly [{pid}] (user's Azahar running?)")
    img = process_image(pid)
    if not img or Path(img).resolve() != EXE:
        raise SystemExit(f"refusing: pid {pid} image is {img}, not {EXE}")
    return pid


def wclass(h) -> str:
    b = ctypes.create_unicode_buffer(256)
    user32.GetClassNameW(h, b, 256)
    return b.value


def wrect(h) -> tuple[int, int, int, int]:
    r = wt.RECT()
    user32.GetWindowRect(h, ctypes.byref(r))
    return r.left, r.top, r.right, r.bottom


def find_windows(pid: int) -> tuple[int, int]:
    """(main top-level hwnd, render surface hwnd) of the test process."""
    tops = []

    def cb(h, lp):
        p = wt.DWORD()
        user32.GetWindowThreadProcessId(h, ctypes.byref(p))
        if p.value == pid and user32.IsWindowVisible(h) and user32.GetWindowTextLengthW(h) > 0:
            tops.append(h)
        return True
    user32.EnumWindows(EnumProc(cb), 0)
    if not tops:
        raise SystemExit("no visible top-level window for the test pid")
    main = max(tops, key=lambda h: (wrect(h)[2] - wrect(h)[0]) * (wrect(h)[3] - wrect(h)[1]))
    cands = []

    def cb2(h, lp):
        if user32.IsWindowVisible(h) and "OwnDC" in wclass(h):
            cands.append(h)
        return True
    user32.EnumChildWindows(main, EnumProc(cb2), 0)
    if not cands:
        raise SystemExit("render surface (Qt...QWindowOwnDCIcon child) not found")
    render = max(cands, key=lambda h: (wrect(h)[2] - wrect(h)[0]) * (wrect(h)[3] - wrect(h)[1]))
    return main, render


def key_lparam(vk: int, up: bool, extended: bool) -> int:
    scan = user32.MapVirtualKeyW(vk, 0) & 0xFF
    lp = 1 | (scan << 16)
    if extended:
        lp |= 1 << 24
    if up:
        lp |= (1 << 30) | (1 << 31)
    return lp


user32.PostMessageW.argtypes = [wt.HWND, wt.UINT, wt.WPARAM, wt.LPARAM]
user32.PostMessageW.restype = wt.BOOL


def post(h, msg, wp, lp) -> None:
    if not user32.PostMessageW(h, msg, wp, lp):
        raise OSError(f"PostMessage failed: {ctypes.get_last_error()}")


def press(render: int, button: str, hold_ms: int) -> None:
    keys = [BUTTONS[b] for b in button.split("+")]
    for k in keys:
        post(render, WM_KEYDOWN, VK[k], key_lparam(VK[k], False, k in EXTENDED))
    time.sleep(hold_ms / 1000)
    for k in reversed(keys):
        post(render, WM_KEYUP, VK[k], key_lparam(VK[k], True, k in EXTENDED))


def bottom_screen_point(render: int, x: int, y: int) -> tuple[int, int]:
    """Client coords of a 3DS bottom-screen pixel for Azahar's default layout (top 400x240 above a
    centred 320x240 bottom screen, both scaled by the same integer-or-fit factor)."""
    l, t, r, b = wrect(render)
    w, h = r - l, b - t
    scale = min(w / 400, h / 480)
    top_w, scr_h = 400 * scale, 240 * scale
    oy = (h - 2 * scr_h) / 2
    bx0 = (w - 320 * scale) / 2
    by0 = oy + scr_h
    return int(bx0 + (x + 0.5) * scale), int(by0 + (y + 0.5) * scale)


def main(argv=None) -> None:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    p = sub.add_parser("keys"); p.add_argument("tokens", nargs="+")
    p.add_argument("--hold", type=int, default=90); p.add_argument("--gap", type=int, default=160)
    p = sub.add_parser("touch"); p.add_argument("x", type=int); p.add_argument("y", type=int)
    p.add_argument("--hold", type=int, default=120)
    sub.add_parser("info")
    a = ap.parse_args(argv)

    pid = check_instance()
    main_h, render = find_windows(pid)
    if a.cmd == "info":
        print(f"pid {pid}: main hwnd {main_h:#x} rect {wrect(main_h)}; render hwnd {render:#x} "
              f"class {wclass(render)} rect {wrect(render)}")
        return
    if a.cmd == "touch":
        cx, cy = bottom_screen_point(render, a.x, a.y)
        lp = (cy << 16) | (cx & 0xFFFF)
        post(render, WM_MOUSEMOVE, 0, lp)
        post(render, WM_LBUTTONDOWN, MK_LBUTTON, lp)
        time.sleep(a.hold / 1000)
        post(render, WM_LBUTTONUP, 0, lp)
        print(f"touch ({a.x},{a.y}) -> client ({cx},{cy}) on hwnd {render:#x}")
        return
    sent = []
    for tok in a.tokens:
        tok = tok.upper()
        if tok.startswith("W") and tok[1:].isdigit():
            time.sleep(int(tok[1:]) / 1000)
            sent.append(tok)
            continue
        count = 1
        if "*" in tok:
            tok, c = tok.split("*")
            count = int(c)
        hold = a.hold
        if ":" in tok:
            tok, hs = tok.split(":")
            hold = int(hs)
        if any(b not in BUTTONS for b in tok.split("+")):
            raise SystemExit(f"unknown button {tok}")
        for _ in range(count):
            press(render, tok, hold)
            time.sleep(a.gap / 1000)
        sent.append(f"{tok}:{hold}*{count}")
    print(f"pid {pid} render {render:#x}: " + " ".join(sent))


if __name__ == "__main__":
    main()
