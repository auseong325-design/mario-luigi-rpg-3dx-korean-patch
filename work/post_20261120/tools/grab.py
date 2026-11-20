"""Capture the test Azahar's render surface without needing it in front: PrintWindow(PW_RENDERFULLCONTENT).

  grab.py OUT.png [--split]      whole render area; --split also writes OUT_top.png / OUT_bottom.png
  grab.py --check                print the render window size

The layout is Azahar's default (top 400x240 above a centred bottom 320x240, same scale). Only the test
instance (PID in tools/azahar-test/rt_azahar.pid, image tools/azahar-test/azahar.exe) is captured.
"""
import ctypes
import ctypes.wintypes as wt
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT / 'scripts' / 'fps60'))
import rt_input  # noqa: E402  (instance checks + window lookup)
from PIL import Image  # noqa: E402

user32, gdi32 = ctypes.windll.user32, ctypes.windll.gdi32


def capture(hwnd):
    l, t, r, b = rt_input.wrect(hwnd)
    w, h = r - l, b - t
    hdc = user32.GetWindowDC(hwnd)
    mem = gdi32.CreateCompatibleDC(hdc)
    bmp = gdi32.CreateCompatibleBitmap(hdc, w, h)
    gdi32.SelectObject(mem, bmp)
    ok = user32.PrintWindow(hwnd, mem, 2)      # PW_RENDERFULLCONTENT: includes GPU-composited content
    class BMI(ctypes.Structure):
        _fields_ = [('biSize', wt.DWORD), ('biWidth', wt.LONG), ('biHeight', wt.LONG), ('biPlanes', wt.WORD),
                    ('biBitCount', wt.WORD), ('biCompression', wt.DWORD), ('biSizeImage', wt.DWORD),
                    ('biXPelsPerMeter', wt.LONG), ('biYPelsPerMeter', wt.LONG), ('biClrUsed', wt.DWORD),
                    ('biClrImportant', wt.DWORD)]
    bmi = BMI(ctypes.sizeof(BMI), w, -h, 1, 32, 0, 0, 0, 0, 0, 0)
    buf = ctypes.create_string_buffer(w * h * 4)
    gdi32.GetDIBits(mem, bmp, 0, h, buf, ctypes.byref(bmi), 0)
    gdi32.DeleteObject(bmp); gdi32.DeleteDC(mem); user32.ReleaseDC(hwnd, hdc)
    if not ok:
        raise SystemExit('PrintWindow failed')
    return Image.frombuffer('RGBA', (w, h), buf, 'raw', 'BGRA', 0, 1).convert('RGB')


def screens(img):
    """Cut the top and bottom 3DS screens out of the default layout."""
    w, h = img.size
    scale = min(w / 400, h / 480)
    sh = round(240 * scale)
    oy = round((h - 2 * sh) / 2)
    tx = round((w - 400 * scale) / 2); bx = round((w - 320 * scale) / 2)
    top = img.crop((tx, oy, tx + round(400 * scale), oy + sh))
    bottom = img.crop((bx, oy + sh, bx + round(320 * scale), oy + 2 * sh))
    return top, bottom


def main():
    pid = rt_input.check_instance()
    main_hwnd, render = rt_input.find_windows(pid)
    img = capture(render)
    if sys.argv[1] == '--check':
        print('render', img.size); return
    out = Path(sys.argv[1]); out.parent.mkdir(parents=True, exist_ok=True)
    img.save(out)
    if '--split' in sys.argv:
        top, bottom = screens(img)
        top.save(out.with_name(out.stem + '_top.png')); bottom.save(out.with_name(out.stem + '_bottom.png'))
    print(out, img.size)


if __name__ == '__main__':
    main()
