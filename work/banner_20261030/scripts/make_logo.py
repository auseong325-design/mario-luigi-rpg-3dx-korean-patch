"""Korean HOME Menu banner logo (COMMON_jp replacement, 256x128 RGBA4) from the installed Korean
title logo, made the way Nintendo made the Japanese banner logo (see fit_jp.py):

  1. stack the installed Korean title textures (title_logo_JP_bottom, then title_logo_JP_top over it),
     exactly as on the title screen; pixels decoded from the installed FMdl (extract/title_kr_*.png);
  2. erase the thin title TM (title px x 484..495, y 145..150) by interpolating the white glow
     between the rows above and below (it would be a faint 3 px smudge at banner size);
  3. move up 10 title px (vertical centre like the JP banner), 2x2 box downsample in premultiplied
     alpha (uniform scale 0.5, the largest that keeps the JP 2 px side margins);
  4. paste the JP banner's own banner-size TM (navy ink on the white glow, unmixed against white)
     at the Korean title TM position mapped to the banner (+ the 1.3 px right offset Nintendo used),
     on a small white halo (the half-size glow is too thin there to back it as in the JP banner);
  5. un-premultiply, transparent texels white (as in the JP texture), RGBA4.

Outputs (out/logo/): COMMON_ko_upright.png (quantised RGBA, top row first), COMMON_ko_rgba4.bin
(texture bytes in CGFX order), logo.json; preview/ sheets.
"""
from __future__ import annotations

import hashlib
import json
import sys
from pathlib import Path

import numpy as np
from PIL import Image

HERE = Path(__file__).resolve().parent
WORK = HERE.parent
ROOT = WORK.parents[1]
sys.path.insert(0, str(ROOT / "scripts"))
import libtex3ds as T  # noqa: E402

E = WORK / "extract"
OUT = WORK / "out" / "logo"
PV = WORK / "preview"
SHIFT_UP = 10                       # title px (even: keeps the 2x2 grid)
TM_TITLE_BOX = (484, 145, 496, 151)  # x0, y0, x1, y1 (exclusive) of the Korean title TM ink
JP_TM_BOX = (240, 68, 251, 74)       # JP banner (upright) box holding the TM ink
TM_SHIFT = (1, -2)                   # JP TM -> Korean position (banner px), see REPORT 5
NAVY = np.array([0, 51, 85], np.float32)   # TM ink colour in the JP banner


def load(p):
    return np.asarray(Image.open(p).convert("RGBA"), np.float32)


def premul(a):
    al = a[..., 3:] / 255.0
    return np.concatenate([a[..., :3] * al, a[..., 3:]], 2)


def unpremul(pm):
    al = pm[..., 3:]
    rgb = np.where(al > 0, pm[..., :3] * 255.0 / np.maximum(al, 1e-6), 255.0)
    return np.concatenate([rgb, al], 2)


def build() -> dict:
    bot = load(E / "title_kr_title_logo_JP_bottom.png")
    top = load(E / "title_kr_title_logo_JP_top.png")
    comp = np.asarray(Image.alpha_composite(Image.fromarray(np.uint8(bot)), Image.fromarray(np.uint8(top))),
                      np.float32)
    pm = premul(comp)
    # 2. erase the title TM: per column, linear interpolation between the row above and below
    x0, y0, x1, y1 = TM_TITLE_BOX
    a, b = pm[y0 - 1, x0:x1], pm[y1, x0:x1]
    for k, y in enumerate(range(y0, y1)):
        t = (k + 1) / (y1 - y0 + 1)
        pm[y, x0:x1] = a * (1 - t) + b * t
    # 3. shift up, 2x2 premultiplied box filter
    assert not pm[:SHIFT_UP, :, 3].any(), "shift would cut visible pixels"
    sh = np.zeros_like(pm)
    sh[:-SHIFT_UP] = pm[SHIFT_UP:]
    small = sh.reshape(128, 2, 256, 2, 4).mean((1, 3))
    # 4. JP banner TM: coverage of navy ink over white glow, pasted at the Korean spot
    jp = load(E / "3dx_COMMON_jp.png")[::-1]
    bx0, by0, bx1, by1 = JP_TM_BOX
    patch = jp[by0:by1, bx0:bx1]
    lum = patch[..., :3].mean(2)
    cov = np.clip((255.0 - lum) / (255.0 - NAVY.mean()), 0, 1) * (patch[..., 3] / 255.0)
    cov[cov < 0.05] = 0
    dx, dy = TM_SHIFT
    # white halo like the JP banner's glow under its TM (opaque within 1 px of the ink, gone at 3 px)
    from scipy import ndimage as ndi
    pad = 4
    big = np.zeros((cov.shape[0] + 2 * pad, cov.shape[1] + 2 * pad), np.float32)
    big[pad:-pad, pad:-pad] = cov
    d = ndi.distance_transform_edt(big < 0.3)
    halo = np.clip((3.0 - d) / 2.0, 0, 1)
    hy0, hx0 = by0 + dy - pad, bx0 + dx - pad
    reg = small[hy0:hy0 + big.shape[0], hx0:hx0 + big.shape[1]]
    white = np.array([255, 255, 255, 255], np.float32)
    small[hy0:hy0 + big.shape[0], hx0:hx0 + big.shape[1]] = white * halo[..., None] + reg * (1 - halo[..., None])
    region = small[by0 + dy:by1 + dy, bx0 + dx:bx1 + dx]
    ink = np.concatenate([np.broadcast_to(NAVY, cov.shape + (3,)) * cov[..., None], 255.0 * cov[..., None]], 2)
    small[by0 + dy:by1 + dy, bx0 + dx:bx1 + dx] = ink + region * (1 - cov[..., None])
    # 5. straight alpha, white transparent texels, RGBA4
    rgba = unpremul(small)
    q = np.clip(np.rint(rgba / 17.0) * 17.0, 0, 255).astype(np.uint8)
    q[q[..., 3] == 0, :3] = 255
    data = T.encode(q[::-1].copy(), "RGBA4")             # CGFX stores the image bottom-up
    back = T.decode(data, "RGBA4", 256, 128)[::-1]
    assert np.array_equal(back, q), "RGBA4 round trip"
    ys, xs = np.nonzero(q[..., 3] > 0)
    info = {"size": [256, 128], "format": "RGBA4", "bytes": len(data), "sha256": hashlib.sha256(data).hexdigest(),
            "alpha_bbox": [int(xs.min()), int(ys.min()), int(xs.max()) + 1, int(ys.max()) + 1],
            "scale": 0.5, "shift_up_title_px": SHIFT_UP, "tm_title_box_erased": TM_TITLE_BOX,
            "jp_tm_box": JP_TM_BOX, "tm_shift": TM_SHIFT, "tm_ink_pixels": int((cov > 0).sum()),
            "sources": {"title_bottom": str(E / "title_kr_title_logo_JP_bottom.png"),
                        "title_top": str(E / "title_kr_title_logo_JP_top.png"),
                        "jp_banner": str(E / "3dx_COMMON_jp.png")}}
    return {"q": q, "data": data, "info": info, "comp": comp}


def previews(q: np.ndarray, tag: str) -> None:
    bg = np.array([52, 52, 64], np.float32)

    def flat(a):
        al = a[..., 3:] / 255.0
        return np.uint8(np.clip(a[..., :3] * al + bg * (1 - al), 0, 255))

    jp = load(E / "3dx_COMMON_jp.png")[::-1]
    kr1 = load(E / "1dx_COMMON_kr.png")[::-1]
    sheet = np.concatenate([flat(jp), flat(q.astype(np.float32)), flat(kr1)], 0)
    Image.fromarray(sheet).resize((768, 1152), Image.NEAREST).save(PV / f"logo_jp_ko_1dx_x3_{tag}.png")
    crop = np.concatenate([flat(jp)[50:128, 150:256], np.zeros((78, 4, 3), np.uint8),
                           flat(q.astype(np.float32))[50:128, 150:256]], 1)
    Image.fromarray(crop).resize((crop.shape[1] * 6, crop.shape[0] * 6), Image.NEAREST).save(PV / f"logo_detail_x6_{tag}.png")


def main() -> int:
    OUT.mkdir(parents=True, exist_ok=True)
    PV.mkdir(exist_ok=True)
    r = build()
    Image.fromarray(r["q"], "RGBA").save(OUT / "COMMON_ko_upright.png")
    (OUT / "COMMON_ko_rgba4.bin").write_bytes(r["data"])
    (OUT / "logo.json").write_text(json.dumps(r["info"], indent=1), encoding="utf-8")
    previews(r["q"], r["info"]["sha256"][:8])
    print(json.dumps(r["info"], indent=1))
    return 0


if __name__ == "__main__":
    sys.exit(main())
