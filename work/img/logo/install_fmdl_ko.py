"""Collect the finished I4 model textures into work/img/fmdl_ko/ (input of scripts/build_fmdl.py)."""
import shutil
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
OUT = ROOT / "work/img/logo/out"
KO = ROOT / "work/img/fmdl_ko"
MAP = {
    "fmd_title_JP_ja/title_logo_JP_bottom.png": "title_logo_JP_bottom.png",
    "fmd_title_JP_ja/title_logo_JP_top.png": "title_logo_JP_top.png",
    "fmd_title_JP_ja/title_logo_M_JP.png": "title_logo_M_JP.png",
    "fmd_title_JP_ja/title_logo_L_JP.png": "title_logo_L_JP.png",
    "fmd_title_start_JP_ja/st.png": "st.png",
}
for dst, src in MAP.items():
    p = KO / dst
    p.parent.mkdir(parents=True, exist_ok=True)
    shutil.copyfile(OUT / src, p)
    print(p.relative_to(ROOT))
