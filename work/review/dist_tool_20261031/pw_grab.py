"""Screenshot of the TEST instance's render surface with PrintWindow (PW_RENDERFULLCONTENT), so a window or
system dialog lying on top of it does not end up in the picture (a desktop grab copies whatever is on screen).

  pw_grab.py OUT.png [--max 800]
Safety: same instance check as rt_input.py (exactly one azahar.exe, PID = tools/azahar-test/rt_azahar.pid, image =
tools/azahar-test/azahar.exe). Read-only: it only asks that window to paint into a memory bitmap.
"""
from __future__ import annotations

import argparse
import ctypes
import ctypes.wintypes as wt
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT / "scripts" / "fps60"))
import rt_input  # noqa: E402  (sets DPI awareness, provides the instance check and window lookup)

user32, gdi32 = ctypes.WinDLL("user32"), ctypes.WinDLL("gdi32")
PW_CLIENTONLY, PW_RENDERFULLCONTENT = 0x1, 0x2


class BITMAPINFOHEADER(ctypes.Structure):
    _fields_ = [("biSize", wt.DWORD), ("biWidth", wt.LONG), ("biHeight", wt.LONG), ("biPlanes", wt.WORD),
                ("biBitCount", wt.WORD), ("biCompression", wt.DWORD), ("biSizeImage", wt.DWORD),
                ("biXPelsPerMeter", wt.LONG), ("biYPelsPerMeter", wt.LONG), ("biClrUsed", wt.DWORD),
                ("biClrImportant", wt.DWORD)]


def grab(hwnd: int):
    from PIL import Image
    rc = wt.RECT()
    user32.GetClientRect(wt.HWND(hwnd), ctypes.byref(rc))
    w, h = rc.right - rc.left, rc.bottom - rc.top
    hdc_win = user32.GetDC(wt.HWND(hwnd))
    hdc = gdi32.CreateCompatibleDC(hdc_win)
    bmp = gdi32.CreateCompatibleBitmap(hdc_win, w, h)
    old = gdi32.SelectObject(hdc, bmp)
    try:
        ok = user32.PrintWindow(wt.HWND(hwnd), hdc, PW_CLIENTONLY | PW_RENDERFULLCONTENT)
        bi = BITMAPINFOHEADER(ctypes.sizeof(BITMAPINFOHEADER), w, -h, 1, 32, 0, 0, 0, 0, 0, 0)
        buf = ctypes.create_string_buffer(w * h * 4)
        gdi32.GetDIBits(hdc, bmp, 0, h, buf, ctypes.byref(bi), 0)
        img = Image.frombuffer("RGBA", (w, h), buf, "raw", "BGRA", 0, 1).convert("RGB")
        return bool(ok), img
    finally:
        gdi32.SelectObject(hdc, old)
        gdi32.DeleteObject(bmp)
        gdi32.DeleteDC(hdc)
        user32.ReleaseDC(wt.HWND(hwnd), hdc_win)


def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("out")
    ap.add_argument("--max", type=int, default=800)
    a = ap.parse_args()
    pid = rt_input.check_instance()
    _top, render = rt_input.find_windows(pid)
    ok, img = grab(render)
    w, h = img.size
    s = min(1.0, a.max / max(w, h))
    if s < 1:
        img = img.resize((max(1, int(w * s)), max(1, int(h * s))))
    img.save(a.out)
    extrema = img.convert("L").getextrema()
    print(f"saved {a.out} {img.size} printwindow_ok={ok} luminance_range={extrema}")


if __name__ == "__main__":
    main()
