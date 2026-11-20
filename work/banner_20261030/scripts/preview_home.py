"""Preview of what the Korean CIA changes on the HOME Menu: the 3D banner (top screen) and the title text.

The banner scene is the same approximation as mockup.py (orthographic front view, bind pose), with one
correction: `bunner_rem3_bk` is an alpha-only texture of character silhouettes, i.e. the drop shadows.
mockup.py drew it white and in front of Bowser; here it is drawn as a soft dark shadow right after the
background and the floor, under the characters. Its real colour comes from the material's combiner, which
the dump does not include, so the shade is an assumption. The HOME camera, lighting and animation are not
reproduced.

Writes preview/home_preview_ko.png.
"""
from __future__ import annotations

import json
import sys
from pathlib import Path

import numpy as np
from PIL import Image, ImageDraw, ImageFont

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
import mockup  # noqa: E402  (tex, sample, scene bounds)

WORK = HERE.parent
ROOT = WORK.parents[1]
ORDER = {'bunner_rem3_bg': 0, 'bunner_rem3_base': 1, 'bunner_rem3_bk': 2, 'bunner_rem3_chara': 3, 'COMMON_jp': 4}
SHADOW = 0.45


def render(ko: bool) -> np.ndarray:
    js = json.loads((mockup.E / '3dx_spica.json').read_text(encoding='utf-8-sig'))
    m = js['models'][0]
    S, X0, X1, Y0, Y1 = mockup.SCALE, mockup.X0, mockup.X1, mockup.Y0, mockup.Y1
    W, H = int((X1 - X0) * S), int((Y1 - Y0) * S)
    img = np.zeros((H, W, 3), np.float32) + np.array([246, 246, 248], np.float32)
    meshes = sorted(m['meshes'], key=lambda ms: (ORDER.get(ms['tex0'], 9), np.mean([v['p'][2] for v in ms['vertices']])))
    for ms in meshes:
        t = mockup.tex(ms['tex0'], ko)
        shadow = ms['tex0'] == 'bunner_rem3_bk'
        V = ms['vertices']
        P = np.array([[(v['p'][0] - X0) * S, (Y1 - v['p'][1]) * S] for v in V])
        UV = np.array([[v['uv0'][0], v['uv0'][1]] for v in V])
        for sm in ms['submeshes']:
            idx = sm['indices']
            for k in range(0, len(idx) - 2, 3):
                p, uv = P[idx[k:k + 3]], UV[idx[k:k + 3]]
                xmin, ymin = np.maximum(np.floor(p.min(0)).astype(int), 0)
                xmax, ymax = np.minimum(np.ceil(p.max(0)).astype(int), [W, H])
                if xmax <= xmin or ymax <= ymin:
                    continue
                yy, xx = np.mgrid[ymin:ymax, xmin:xmax] + 0.5
                d = (p[1, 1] - p[2, 1]) * (p[0, 0] - p[2, 0]) + (p[2, 0] - p[1, 0]) * (p[0, 1] - p[2, 1])
                if abs(d) < 1e-9:
                    continue
                l0 = ((p[1, 1] - p[2, 1]) * (xx - p[2, 0]) + (p[2, 0] - p[1, 0]) * (yy - p[2, 1])) / d
                l1 = ((p[2, 1] - p[0, 1]) * (xx - p[2, 0]) + (p[0, 0] - p[2, 0]) * (yy - p[2, 1])) / d
                l2 = 1 - l0 - l1
                inside = (l0 >= 0) & (l1 >= 0) & (l2 >= 0)
                if not inside.any():
                    continue
                c = mockup.sample(t, l0 * uv[0, 0] + l1 * uv[1, 0] + l2 * uv[2, 0], l0 * uv[0, 1] + l1 * uv[1, 1] + l2 * uv[2, 1])
                a = (c[..., 3:] / 255.0) * inside[..., None]
                colour = c[..., :3]
                if shadow:
                    a, colour = a * SHADOW, np.zeros_like(colour) + np.array([30, 28, 40], np.float32)
                reg = img[ymin:ymax, xmin:xmax]
                img[ymin:ymax, xmin:xmax] = colour * a + reg * (1 - a)
    return np.uint8(np.clip(img, 0, 255))


def font(size, bold=False):
    return ImageFont.truetype(r'C:\Windows\Fonts\malgunbd.ttf' if bold else r'C:\Windows\Fonts\malgun.ttf', size)


def bubble(draw, box, text, sub=None):
    draw.rounded_rectangle(box, 14, fill=(255, 255, 255), outline=(206, 210, 220), width=2)
    x0, y0, x1, y1 = box
    draw.text(((x0 + x1) / 2, y0 + (26 if sub else (y1 - y0) / 2)), text, font=font(24, True), fill=(30, 32, 40), anchor='mm')
    if sub:
        draw.text(((x0 + x1) / 2, y0 + 58), sub, font=font(17), fill=(110, 116, 128), anchor='mm')


def main() -> int:
    titles = json.loads((WORK / 'out' / 'icon' / 'icon.json').read_text(encoding='utf-8'))
    before, after = titles['korean_slot_before']['short'], titles['korean_slot_after']['short']
    panels = [(render(False), '지금 (일본판 그대로)', before), (render(True), '한글 CIA 설치 후', after)]
    scale = 2
    pw, ph = panels[0][0].shape[1] * scale, panels[0][0].shape[0] * scale
    gap, head, foot = 28, 66, 120
    sheet = Image.new('RGB', (2 * pw + 3 * gap, head + ph + foot + 92), (232, 234, 240))
    d = ImageDraw.Draw(sheet)
    for i, (scene, label, name) in enumerate(panels):
        x = gap + i * (pw + gap)
        d.text((x, 20), label, font=font(28, True), fill=(26, 28, 36))
        frame = Image.fromarray(scene).resize((pw, ph), Image.LANCZOS)
        d.rounded_rectangle((x - 6, head - 6, x + pw + 6, head + ph + 6), 18, fill=(40, 42, 50))
        sheet.paste(frame, (x, head))
        d.text((x, head + ph + 18), '한국어 본체 HOME 메뉴의 게임 이름', font=font(18), fill=(96, 100, 112))
        bubble(d, (x, head + ph + 48, x + pw, head + ph + 48 + 84), name, 'Nintendo')
    note = ('배너 장면은 정면에서 본 근사 그림입니다(실제 HOME 메뉴는 비스듬한 카메라와 애니메이션으로 보입니다). '
            '그림자 색은 추정입니다.\n이름은 HOME 메뉴 글꼴이 아니라 맑은 고딕으로 그렸습니다. 한글 이름은 한국어 본체에서만 보입니다.')
    d.multiline_text((gap, head + ph + foot + 24), note, font=font(17), fill=(96, 100, 112), spacing=8)
    out = WORK / 'preview' / 'home_preview_ko.png'
    sheet.save(out, optimize=True)
    print(out, sheet.size)
    return 0


if __name__ == '__main__':
    sys.exit(main())
