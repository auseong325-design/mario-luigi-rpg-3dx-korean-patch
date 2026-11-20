"""Approximate front view of the banner scene (orthographic, bind pose, painter's order by z),
JP original vs Korean, from the SPICA mesh dump + the decoded textures. Not the HOME Menu camera:
only to see the logo in its scene. Writes preview/banner_mockup_jp_ko.png (<= 1600 px wide).
"""
from __future__ import annotations

import json
import sys
from pathlib import Path

import numpy as np
from PIL import Image, ImageDraw

HERE = Path(__file__).resolve().parent
WORK = HERE.parent
E = WORK / "extract"
SCALE = 16.0            # px per world unit
X0, X1, Y0, Y1 = -11.5, 12.5, -8.5, 9.5


def tex(name: str, ko: bool) -> np.ndarray:
    if name == "COMMON_jp" and ko:
        a = np.asarray(Image.open(WORK / "out/logo/COMMON_ko_upright.png").convert("RGBA"), np.float32)
        return a[::-1]          # back to stored (bottom-up) orientation, v=0 = row 0
    return np.asarray(Image.open(E / f"3dx_{name}.png").convert("RGBA"), np.float32)


def sample(t: np.ndarray, u: np.ndarray, v: np.ndarray) -> np.ndarray:
    h, w = t.shape[:2]
    x = (u % 1.0) * w - 0.5
    y = (v % 1.0) * h - 0.5            # row 0 of the decoded array is v = 0 (stored bottom-up)
    x0 = np.floor(x).astype(int); y0 = np.floor(y).astype(int)
    fx = (x - x0)[..., None]; fy = (y - y0)[..., None]
    g = lambda yy, xx: t[np.clip(yy, 0, h - 1), np.clip(xx, 0, w - 1)]
    return (g(y0, x0) * (1 - fx) * (1 - fy) + g(y0, x0 + 1) * fx * (1 - fy)
            + g(y0 + 1, x0) * (1 - fx) * fy + g(y0 + 1, x0 + 1) * fx * fy)


def render(ko: bool) -> np.ndarray:
    js = json.loads((E / "3dx_spica.json").read_text(encoding="utf-8-sig"))
    m = js["models"][0]
    W, H = int((X1 - X0) * SCALE), int((Y1 - Y0) * SCALE)
    img = np.zeros((H, W, 3), np.float32) + np.array([236, 236, 240], np.float32)   # light HOME-like backdrop
    meshes = sorted(m["meshes"], key=lambda ms: np.mean([v["p"][2] for v in ms["vertices"]]))
    for ms in meshes:
        t = tex(ms["tex0"], ko)
        V = ms["vertices"]
        P = np.array([[(v["p"][0] - X0) * SCALE, (Y1 - v["p"][1]) * SCALE] for v in V])
        UV = np.array([[v["uv0"][0], v["uv0"][1]] for v in V])
        for sm in ms["submeshes"]:
            idx = sm["indices"]
            for k in range(0, len(idx) - 2, 3):
                tri = [idx[k], idx[k + 1], idx[k + 2]]
                p = P[tri]; uv = UV[tri]
                xmin, ymin = np.floor(p.min(0)).astype(int); xmax, ymax = np.ceil(p.max(0)).astype(int)
                xmin, ymin = max(xmin, 0), max(ymin, 0); xmax, ymax = min(xmax, W), min(ymax, H)
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
                u = l0 * uv[0, 0] + l1 * uv[1, 0] + l2 * uv[2, 0]
                v = l0 * uv[0, 1] + l1 * uv[1, 1] + l2 * uv[2, 1]
                c = sample(t, u, v)
                a = (c[..., 3:] / 255.0) * inside[..., None]
                reg = img[ymin:ymax, xmin:xmax]
                img[ymin:ymax, xmin:xmax] = c[..., :3] * a + reg * (1 - a)
    return np.uint8(np.clip(img, 0, 255))


def main() -> int:
    a, b = render(False), render(True)
    sheet = Image.new("RGB", (a.shape[1] * 2 + 12, a.shape[0] + 22), (40, 40, 48))
    sheet.paste(Image.fromarray(a), (0, 22)); sheet.paste(Image.fromarray(b), (a.shape[1] + 12, 22))
    d = ImageDraw.Draw(sheet)
    d.text((6, 5), "JP original (approx. front view, bind pose)", fill=(255, 255, 255))
    d.text((a.shape[1] + 18, 5), "Korean banner (same scene)", fill=(255, 255, 255))
    if sheet.width > 1600:
        sheet = sheet.resize((1600, int(sheet.height * 1600 / sheet.width)), Image.LANCZOS)
    sheet.save(WORK / "preview/banner_mockup_jp_ko.png")
    print(sheet.size)
    return 0


if __name__ == "__main__":
    sys.exit(main())
