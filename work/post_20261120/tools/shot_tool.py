"""Screenshots of the patch tool (v0.3.1 source) for the post. Runs real jobs into C:\\3DS-Work\\post-demo only.

Captures the whole window with PrintWindow, so it works while the window is behind others.
"""
import ctypes
import ctypes.wintypes as wt
import os
import shutil
import sys
import time
from pathlib import Path

DEMO = Path(r'C:\3DS-Work\post-demo')
OUT = Path(r'C:\AI-Projects\mario-luigi-rpg-3dx-korean-patch\work\post_20261120\images\05_tool')
APP = Path(r'C:\AI-Projects\3ds-patch-universal-tool\upstream\TranslationToolkit')
LUMA = Path(r'C:\AI-Projects\mario-luigi-rpg-3dx-korean-patch\work\distribution_20261102\ml3dx_ko_luma.zip')
MERGED = Path(r'C:\3DS-Work\post-demo\ml3dx_ko_merged_20261120.zip')
GAME = Path(r'C:\3DS-Work\base.cia')
THEME = 'dark' if '--dark' in sys.argv else 'light'

for sub in ('SD', 'Azahar', 'game'):
    (DEMO / sub).mkdir(parents=True, exist_ok=True)
(DEMO / 'SD' / 'Nintendo 3DS').mkdir(exist_ok=True)
OUT.mkdir(parents=True, exist_ok=True)
os.environ['KPM_SETTINGS'] = str(DEMO / 'settings.json')
Path(os.environ['KPM_SETTINGS']).unlink(missing_ok=True)
sys.path.insert(0, str(APP)); sys.dont_write_bytecode = True
from PIL import Image  # noqa: E402
import KoreanPatchManager as kpm  # noqa: E402
from korean_patch_manager import easy, easy_ui  # noqa: E402
easy_ui.system_dark = lambda: THEME == 'dark'

user32, gdi32 = ctypes.windll.user32, ctypes.windll.gdi32
app = kpm.App()
panel = app.easy_panel
app.vars['xdelta'].set(str(APP / 'tools' / 'xdelta-3.2.2' / 'xdelta3.exe'))


def settle(n=10):
    for _ in range(n):
        app.update_idletasks(); app.update(); time.sleep(0.04)


def shot(name):
    settle()
    hwnd = int(app.frame(), 16)
    r = wt.RECT(); ctypes.windll.dwmapi.DwmGetWindowAttribute(hwnd, 9, ctypes.byref(r), ctypes.sizeof(r))
    w0 = wt.RECT(); user32.GetWindowRect(hwnd, ctypes.byref(w0))
    w, h = w0.right - w0.left, w0.bottom - w0.top
    hdc = user32.GetWindowDC(hwnd); mem = gdi32.CreateCompatibleDC(hdc)
    bmp = gdi32.CreateCompatibleBitmap(hdc, w, h); gdi32.SelectObject(mem, bmp)
    user32.PrintWindow(hwnd, mem, 2)
    buf = ctypes.create_string_buffer(w * h * 4)
    class BMI(ctypes.Structure):
        _fields_ = [('a', wt.DWORD), ('w', wt.LONG), ('h', wt.LONG), ('p', wt.WORD), ('b', wt.WORD), ('c', wt.DWORD),
                    ('s', wt.DWORD), ('x', wt.LONG), ('y', wt.LONG), ('u', wt.DWORD), ('i', wt.DWORD)]
    gdi32.GetDIBits(mem, bmp, 0, h, buf, ctypes.byref(BMI(ctypes.sizeof(BMI), w, -h, 1, 32, 0, 0, 0, 0, 0, 0)), 0)
    gdi32.DeleteObject(bmp); gdi32.DeleteDC(mem); user32.ReleaseDC(hwnd, hdc)
    img = Image.frombuffer('RGBA', (w, h), buf, 'raw', 'BGRA', 0, 1).convert('RGB')
    # trim the invisible resize border so only the visible window remains
    img = img.crop((r.left - w0.left, r.top - w0.top, r.right - w0.left, r.bottom - w0.top))
    img.save(OUT / f'{THEME}_{name}.png'); print(name, img.size, flush=True)


def wait_job(timeout=600, mid=None):
    start = time.monotonic(); took = False
    while panel.busy and time.monotonic() - start < timeout:
        settle(1)
        if mid and not took and panel.job and panel.job.get('phase', 0) >= mid[0] and time.monotonic() - start > 3:
            shot(mid[1]); took = True


app.geometry('+40+40'); settle(15)
shot('01_start')
panel.cards = []
panel.add_paths([str(LUMA)]); shot('02_patch_added')
panel.sd_root = DEMO / 'SD'; panel.choose_place('3ds'); shot('03_ready_3ds')
shutil.rmtree(DEMO / 'SD' / 'luma', ignore_errors=True); shutil.rmtree(DEMO / 'SD' / 'luma_backup', ignore_errors=True)
panel.start(); wait_job(120, (1, '04_installing'))
shot('05_done_3ds')
panel.emu_root = DEMO / 'Azahar'; panel.reset(); panel.add_paths([str(LUMA)]); panel.choose_place('pc'); shot('06_ready_pc')
panel.reset(); panel.where = None
panel.add_paths([str(MERGED)]); shot('07_merged_needs_game')
panel.add_paths([str(GAME)]); panel.out_dir = DEMO / 'game'; panel.choose_place('pc'); shot('08_merged_ready_pc')
for f in (DEMO / 'game').glob('*'): f.unlink()
panel.start(); wait_job(900, (2, '09_building'))
shot('10_done_game')
panel.open_help('package'); shot('11_help')
app.mode.set(kpm.FULL); app.book.select(app.tab_frames['업데이트 통합'])
app.vars['merge_title'].set('마리오&루이지 RPG3 DX'); shot('12_full_merge_tab')
app.mode.set(kpm.SIMPLE); shot('13_simple_mode')
app.destroy()
for f in (DEMO / 'game').glob('*.cci'): f.unlink()
print('ok')
