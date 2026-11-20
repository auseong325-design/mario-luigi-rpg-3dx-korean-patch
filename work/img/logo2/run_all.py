"""Title logo v2: run the whole pipeline in order (about 10 minutes).

    python run_all.py            # measure, build every picture into out/, review sheets
    python run_all.py --install  # also copy out/ into the build inputs
                                 #   work/img/fmdl_ko/fmd_title_JP_ja/  (scripts/build_fmdl.py)
                                 #   work/img/ko/lyt/MLyt/MENU_FILE_LOAD_JP_ja/  (scripts/build_lyt.py)
"""
from __future__ import annotations

import shutil
import subprocess
import sys

import l2

STEPS = ["seg_1dx.py", "fit_jp.py", "fit_piece.py", "build_bottom.py", "build_top.py", "build_pieces.py",
         "build_fileload.py", "make_review.py"]
TITLE = ["title_logo_JP_bottom", "title_logo_JP_top", "title_logo_M_JP", "title_logo_L_JP", "title_logo_and_JP"]
FILELOAD = ["LOAD_GAME_IMG_ML_L_00_JP_ja", "LOAD_GAME_IMG_ML_R_00_JP_ja"]
# 쿠파주니어 RPG uses the accepted official Hangul glyphs and independent R/wind
# assembly recipe. Earlier build_kj.py experiments are superseded.
KJ_FILELOAD = ["LOAD_GAME_IMG_KJ_L_00_JP_ja", "LOAD_GAME_IMG_KJ_R_00_JP_ja"]


def main():
    for s in STEPS:
        # Apply the accepted main-title layout and the common-affine intro pieces
        # after the base recipes, followed by the latest file-select logo recipe.
        layout_recipe = l2.ROOT / "work/img/title_layout_20261008/build_title.py"
        if s == "make_review.py" and layout_recipe.exists():
            subprocess.run([sys.executable, str(layout_recipe)], check=True, cwd=l2.ROOT, timeout=180)
            for n in TITLE[:2]:
                source = layout_recipe.parent / f"{n}.png"
                target = l2.HERE / f"out/{n}.png"
                temporary = target.with_suffix(".title_layout.tmp")
                temporary.write_bytes(source.read_bytes())
                temporary.replace(target)
            intro_recipe = l2.ROOT / "work/img/logo_runtime_fix_20261008/build_intro.py"
            if intro_recipe.exists():
                subprocess.run([sys.executable, str(intro_recipe)], check=True, cwd=l2.ROOT, timeout=60)
                for n in TITLE[2:]:
                    target = l2.HERE / f"out/{n}.png"
                    temporary = target.with_suffix(".intro_layout.tmp")
                    temporary.write_bytes((intro_recipe.parent / target.name).read_bytes())
                    temporary.replace(target)
            fileload_recipe = l2.ROOT / "work/img/fileload_titlelogo_20261009/build_fileload_title.py"
            if fileload_recipe.exists():
                subprocess.run([sys.executable, str(fileload_recipe)], check=True, cwd=l2.ROOT, timeout=60)
                for n in FILELOAD:
                    target = l2.HERE / f"out/{n}.png"
                    temporary = target.with_suffix(".fileload_layout.tmp")
                    temporary.write_bytes((fileload_recipe.parent / target.name).read_bytes())
                    temporary.replace(target)
        print("==", s, flush=True)
        subprocess.run([sys.executable, str(l2.HERE / s)], check=True, cwd=l2.HERE, timeout=3600)
    kj_recipe = l2.ROOT / "work/img/kj_logo_natural_20261030/build_natural.py"
    if kj_recipe.exists():
        subprocess.run([sys.executable, str(kj_recipe)], check=True, cwd=l2.ROOT, timeout=180)
        for n in KJ_FILELOAD:
            shutil.copyfile(kj_recipe.parent / f"out/{n}.png", l2.HERE / f"out/{n}.png")
    if "--install" in sys.argv:
        for n in TITLE:
            target = l2.ROOT / f"work/img/fmdl_ko/fmd_title_JP_ja/{n}.png"
            temporary = target.with_suffix(".logo_pipeline.tmp")
            temporary.write_bytes((l2.HERE / f"out/{n}.png").read_bytes())
            temporary.replace(target)
        for n in FILELOAD:
            shutil.copyfile(l2.HERE / f"out/{n}.png", l2.ROOT / f"work/img/ko/lyt/MLyt/MENU_FILE_LOAD_JP_ja/{n}.png")
        if kj_recipe.exists():
            for n in KJ_FILELOAD:
                shutil.copyfile(l2.HERE / f"out/{n}.png", l2.ROOT / f"work/img/ko/lyt/MLyt/MENU_FILE_LOAD_JP_ja/{n}.png")
        print("copied into the build inputs; now run scripts/build_fmdl.py and scripts/build_lyt.py")


if __name__ == "__main__":
    main()
