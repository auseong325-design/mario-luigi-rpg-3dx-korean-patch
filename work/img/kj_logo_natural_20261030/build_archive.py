"""Replace only the two 쿠파주니어 RPG file-select texture halves (LOAD_GAME_IMG_KJ_L/R_00_JP_ja) in the
installed MLyt (baseline = patch/.../Lyt/JP/MLyt.dat, copied to out/before_MLyt.dat).

Checks: exactly those two BFLIMs change; every other SARC file and archive entry is byte-identical; the
changed BFLIMs decode to the build_natural.py PNGs (as RGB565). Writes out/after_MLyt.dat, out/build_verify.json,
and copies the PNGs to the Lyt build inputs (work/img/ko/lyt/MLyt/MENU_FILE_LOAD_JP_ja/) so a full
build_lyt.py run gives the same textures. (Same procedure as fileload_titlelogo_20261009/build_archive.py.)
"""
from pathlib import Path
import hashlib
import json
import shutil
import sys

import numpy as np
from PIL import Image

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
sys.path.insert(0, str(ROOT / "scripts"))
import build_lyt  # noqa: E402
import lib3dx  # noqa: E402
import lytimg  # noqa: E402

OUT = HERE / "out"
NAMES = ["LOAD_GAME_IMG_KJ_L_00_JP_ja", "LOAD_GAME_IMG_KJ_R_00_JP_ja"]
PATCH_MLYT = ROOT / "patch/00040000001CA900/romfs/Lyt/JP/MLyt.dat"


def main():
    shutil.copy2(PATCH_MLYT, OUT / "before_MLyt.dat")
    baseline = (OUT / "before_MLyt.dat").read_bytes()
    _, entries = lib3dx.read_bg4(baseline)
    repl, changes, before_imgs = {}, [], {}
    for slot, entry in enumerate(entries):
        if entry.size_flag or not entry.data:
            continue
        plain = lib3dx.bg4_plain(entry)
        if plain[:4] != b"SARC":
            continue
        files = {}
        for name, start, end in lytimg.sarc_list(plain):
            stem = Path(name).stem
            if stem not in NAMES:
                continue
            assert entry.name == "MENU_FILE_LOAD_JP_ja", entry.name
            before_imgs[stem] = lytimg.bflim_to_rgba(plain[start:end])
            image = np.asarray(Image.open(OUT / f"{stem}.png").convert("RGBA"))
            files[name] = lytimg.rgba_to_bflim(plain[start:end], image)
            assert np.array_equal(lytimg.bflim_to_rgba(files[name]), build_lyt.expected("RGB565", image))
            changes.append(f"{entry.name}/{name}")
        if files:
            repl[slot] = lytimg.sarc_replace(plain, files)
    assert len(changes) == 2 and len(repl) == 1, changes
    rebuilt = lib3dx.rebuild_bg4(baseline, repl)
    _, new = lib3dx.read_bg4(rebuilt)
    assert len(entries) == len(new)
    actual_changes = []
    for before, after in zip(entries, new):
        assert before.name == after.name and before.size_flag == after.size_flag
        if before.data == after.data:
            continue
        assert before.name == "MENU_FILE_LOAD_JP_ja"
        p, q = lib3dx.bg4_plain(before), lib3dx.bg4_plain(after)
        f_old, f_new = lytimg.sarc_list(p), lytimg.sarc_list(q)
        assert [f[0] for f in f_old] == [f[0] for f in f_new]
        changed = []
        for (name, s, t), (n, u, v) in zip(f_old, f_new):
            if p[s:t] == q[u:v]:
                continue
            assert Path(name).stem in NAMES, name
            image = np.asarray(Image.open(OUT / (Path(name).stem + ".png")).convert("RGBA"))
            assert np.array_equal(lytimg.bflim_to_rgba(q[u:v]), build_lyt.expected("RGB565", image))
            changed.append(name)
            actual_changes.append(f"{before.name}/{name}")
        assert 1 <= len(changed) <= 2
    (OUT / "after_MLyt.dat").write_bytes(rebuilt)
    # the installed KJ halves before this change, for the record
    before = np.concatenate([before_imgs[n] for n in NAMES], 1)
    Image.fromarray(before).save(OUT / "installed_before_KJ.png")
    inputs = ROOT / "work/img/ko/lyt/MLyt/MENU_FILE_LOAD_JP_ja"
    for name in NAMES:
        target = inputs / f"{name}.png"
        tmp = target.with_suffix(".kj_natural.tmp")
        tmp.write_bytes((OUT / f"{name}.png").read_bytes())
        tmp.replace(target)
    result = {"changed_texture_copies": changes, "only_two_KJ_textures_changed": True,
              "actual_changed_texture_copies": actual_changes,
              "all_other_SARC_files_and_archive_entries_unchanged": True,
              "decoded_RGB565_matches_inputs": True,
              "before_sha256": hashlib.sha256(baseline).hexdigest(),
              "after_sha256": hashlib.sha256(rebuilt).hexdigest()}
    (OUT / "build_verify.json").write_text(json.dumps(result, indent=2) + "\n", encoding="utf8")
    print(json.dumps(result, indent=2))


if __name__ == "__main__":
    main()
