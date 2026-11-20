"""Install the 2026-11-16 pre-release check fixes (3 messages that were wider than their box's Japanese maximum).

  FMsg/i_challenge_01#111  볼록볼록하게 생긴 → 볼록볼록한, 그 수가 → 수가      (FMsg.dat)
  BMsg/b_sys#1199          들이마시는 → 들이쉬는                              (BMsg.dat)
  Menu#628                 line breaks only                                   (Menu.msbt)

Replaces three files of the title folder, changes nothing else:
  romfs/Msg/JP_ja/{FMsg.dat,BMsg.dat,Menu.msbt} <- work/review/final_check_20261116/romfs/
in patch/00040000001CA900/, work/sd_package/luma/titles/00040000001CA900/ and work/sd_package/ml3dx_ko_luma.zip.
The Azahar mods junction on Windows points at patch/00040000001CA900, so it follows patch/.
Each installed file must be the version this build started from. Backups in work/build/prev_final_check_20261116/.
Idempotent. Runs on Linux or Windows (no emulator can run while the Windows partition is mounted here).
The public release folder work/distribution_20261102/ is NOT touched.
"""
from __future__ import annotations

import hashlib
import json
import shutil
import time
import zipfile
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
TITLE = "00040000001CA900"
PATCH = ROOT / "patch" / TITLE
PACKAGE = ROOT / "work/sd_package"
DISTRO = PACKAGE / "luma/titles" / TITLE
ZPATH = PACKAGE / "ml3dx_ko_luma.zip"
ZPREFIX = f"luma/titles/{TITLE}/"
BACKUP = ROOT / "work/build/prev_final_check_20261116"
EXPECT_FILES = 38

# rel path: (source, sha256 prefix the installed file must have now, sha256 prefix of the new file)
FILES = {
    "romfs/Msg/JP_ja/FMsg.dat": (HERE / "romfs/Msg/JP_ja/FMsg.dat", "f1effac5c8a6", "9f44163b4da4"),
    "romfs/Msg/JP_ja/BMsg.dat": (HERE / "romfs/Msg/JP_ja/BMsg.dat", "029d915cb923", "5e5c5faca900"),
    "romfs/Msg/JP_ja/Menu.msbt": (HERE / "romfs/Msg/JP_ja/Menu.msbt", "0838bc676015", "44fdbd7058d0"),
}


def sha(b: bytes) -> str:
    return hashlib.sha256(b).hexdigest()


def replace_retry(temp: Path, target: Path) -> None:
    for attempt in range(10):
        try:
            temp.replace(target)
            return
        except OSError:
            if attempt == 9:
                raise
            time.sleep(0.5)


def put(target: Path, data: bytes, old_prefix: str, new_prefix: str, keep: Path) -> str:
    cur = target.read_bytes()
    h = sha(cur)
    if h.startswith(new_prefix):
        assert cur == data
        return "unchanged"
    assert h.startswith(old_prefix), f"{target}: unexpected current version {h[:12]}"
    keep.parent.mkdir(parents=True, exist_ok=True)
    if not keep.exists():
        shutil.copy2(target, keep)
    assert keep.read_bytes() == cur
    tmp = target.with_name(target.name + ".fc.tmp")
    tmp.write_bytes(data)
    replace_retry(tmp, target)
    return f"replaced {h[:12]}"


def main() -> None:
    data = {}
    for rel, (src, _old, new) in FILES.items():
        b = src.read_bytes()
        assert sha(b).startswith(new), (rel, sha(b)[:12])
        data[rel] = b
    BACKUP.mkdir(parents=True, exist_ok=True)
    actions = {}
    for rel, (_src, old, new) in FILES.items():
        actions["patch/" + rel] = put(PATCH / rel, data[rel], old, new, BACKUP / "patch" / rel)
        actions["sd/" + rel] = put(DISTRO / rel, data[rel], old, new, BACKUP / "sd" / rel)

    with zipfile.ZipFile(ZPATH) as z:
        need = [r for r in FILES if z.read(ZPREFIX + r) != data[r]]
    if need:
        zbak = BACKUP / ZPATH.name
        if not zbak.exists():
            shutil.copy2(ZPATH, zbak)
        tmpz = PACKAGE / "ml3dx_ko_luma.fc.tmp.zip"
        with zipfile.ZipFile(ZPATH) as old:
            for r in need:
                assert sha(old.read(ZPREFIX + r)).startswith(FILES[r][1]), f"ZIP {r}: unexpected version"
            with zipfile.ZipFile(tmpz, "w") as newz:
                newz.comment = old.comment
                for info in old.infolist():
                    rel = info.filename[len(ZPREFIX):] if info.filename.startswith(ZPREFIX) else None
                    newz.writestr(info, data[rel] if rel in data else old.read(info.filename))
        with zipfile.ZipFile(tmpz) as z:
            assert z.testzip() is None and all(z.read(ZPREFIX + r) == data[r] for r in FILES)
        replace_retry(tmpz, ZPATH)
        actions["zip"] = f"replaced {need}"
    else:
        actions["zip"] = "unchanged"

    rel = sorted(p.relative_to(PATCH).as_posix() for p in PATCH.rglob("*") if p.is_file())
    assert len(rel) == EXPECT_FILES and "code.ips" in rel and "code.bps" not in rel, rel
    with zipfile.ZipFile(ZPATH) as z:
        assert z.testzip() is None
        zrel = sorted(n[len(ZPREFIX):] for n in z.namelist() if n.startswith(ZPREFIX) and not n.endswith("/"))
        for r in rel:
            b = (PATCH / r).read_bytes()
            assert (DISTRO / r).read_bytes() == b, ("sd", r)
            assert z.read(ZPREFIX + r) == b, ("zip", r)
    srel = sorted(p.relative_to(DISTRO).as_posix() for p in DISTRO.rglob("*") if p.is_file())
    assert srel == rel == zrel
    result = {"installed": {r: sha(b) for r, b in data.items()}, "actions": actions,
              "title_folder_files": len(rel), "patch_sd_zip_match": True,
              "zip_sha256": sha(ZPATH.read_bytes()), "backup": BACKUP.relative_to(ROOT).as_posix()}
    (HERE / "install.json").write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(result, indent=2))


if __name__ == "__main__":
    main()
