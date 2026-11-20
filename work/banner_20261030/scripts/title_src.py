"""Pull the title-logo textures straight from the FMdl archives (read-only):
  - original v1.2 (romf2) fmd_title_JP_ja: title_logo_JP_bottom / title_logo_JP_top (Japanese)
  - installed Korean patch (patch/.../romfs/FMdl/JP/FMdl.dat): same two textures (Korean)
Writes extract/title_<src>_<tex>.png (top row first, as build_fmdl extracts) + title_src.json.
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
import build_fmdl as BF  # noqa: E402
import lib3dx  # noqa: E402

OUT = WORK / "extract"
SRCS = {"jp": lib3dx.romfs_path("FMdl/JP/FMdl.dat"),
        "kr": ROOT / "patch/00040000001CA900/romfs/FMdl/JP/FMdl.dat"}
TEX = ["title_logo_JP_bottom", "title_logo_JP_top"]


def main() -> int:
    rep = {}
    for src, path in SRCS.items():
        raw, models = BF.load(path)
        _slot, _plain, bch = models["fmd_title_JP_ja"]
        rep[src] = {"file": str(path), "sha256": hashlib.sha256(raw).hexdigest(), "textures": {}}
        for t in bch.textures:
            if t.name not in TEX:
                continue
            rgba = bch.decode(t)
            Image.fromarray(rgba, "RGBA").save(OUT / f"title_{src}_{t.name}.png")
            rep[src]["textures"][t.name] = {"w": t.w, "h": t.h, "fmt": t.fmt, "levels": t.levels,
                                             "sha1": BF.tex_sha(bch, t)}
    # compare with the PNGs the logo pipeline says were installed
    for n in TEX:
        a = np.asarray(Image.open(OUT / f"title_kr_{n}.png").convert("RGBA"))
        b = np.asarray(Image.open(ROOT / f"work/img/logo2/out/{n}.png").convert("RGBA"))
        rep["kr"]["textures"][n]["equals_logo2_out_png"] = bool(np.array_equal(a, b))
        c = np.asarray(Image.open(ROOT / f"work/img/fmdl/3DX/fmd_title_JP_ja/{n}.png").convert("RGBA"))
        d = np.asarray(Image.open(OUT / f"title_jp_{n}.png").convert("RGBA"))
        rep["jp"]["textures"][n]["equals_work_img_fmdl_png"] = bool(np.array_equal(c, d))
    (OUT / "title_src.json").write_text(json.dumps(rep, indent=1), encoding="utf-8")
    print(json.dumps(rep, indent=1))
    return 0


if __name__ == "__main__":
    sys.exit(main())
