"""Install the 60fps mode (Option A = build v2) next to the Korean patch.

Adds two files, changes nothing else:
  <title>/code.bps          = work/fps60/build/v2/code.bps          (New-3DS-only 60fps + field script VM at 30 Hz)
  <title>/romfs/BAI/BAI.dat = work/fps60/build/v2/romfs/BAI/BAI.dat (battle script timing fix, identical at 30fps)
into patch/00040000001CA900/ (Azahar, via the mods junction), work/sd_package/luma/titles/00040000001CA900/ and
work/sd_package/ml3dx_ko_luma.zip. Backup of the ZIP in work/build/prev_fps60_20261030/. Idempotent: a target that
already holds the same bytes is left alone; a target with other bytes aborts the run.
Run: .venv\\Scripts\\python.exe work\\fps60\\install_20261030\\install.py   (no emulator may be running)
"""
from __future__ import annotations

import hashlib
import json
import os
import shutil
import subprocess
import time
import zipfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
OUT = Path(__file__).parent
BUILD = ROOT / "work/fps60/build/v2"
TITLE = "00040000001CA900"
PATCH = ROOT / "patch" / TITLE
PACKAGE = ROOT / "work/sd_package"
DISTRO = PACKAGE / "luma/titles" / TITLE
ZPATH = PACKAGE / "ml3dx_ko_luma.zip"
ZPREFIX = f"luma/titles/{TITLE}/"
BACKUP = ROOT / "work/build/prev_fps60_20261030"
JUNCTION = Path(os.environ["APPDATA"]) / "Azahar/load/mods" / TITLE

FILES = {  # relative path in the title folder -> (source, expected sha256)
    "code.bps": (BUILD / "code.bps", "c3922b9dcaafb5edacee2eda93ae13bd4c49f49c256495fbc456baf19a405be2"),
    "romfs/BAI/BAI.dat": (BUILD / "romfs/BAI/BAI.dat", "c681a963b8428128a2d9133c39911f9f2acf5a53e83dff0a097de8fbe750fbb6"),
}
EXPECT_BEFORE = 36  # Korean patch files under patch/<title>/ before this install (all under romfs/)


def sha(b: bytes) -> str:
    return hashlib.sha256(b).hexdigest()


def fsha(p: Path) -> str:
    return sha(p.read_bytes())


def no_emulator() -> None:
    r = subprocess.run(["powershell", "-NoProfile", "-Command",
                        "(Get-Process azahar,citra-qt -ErrorAction SilentlyContinue | Measure-Object).Count"],
                       capture_output=True, text=True, timeout=30, check=True)
    assert r.stdout.strip() == "0", "an emulator is running; close it first"


def replace_retry(temp: Path, target: Path) -> None:
    for attempt in range(10):
        try:
            temp.replace(target)
            return
        except OSError:
            if attempt == 9:
                raise
            time.sleep(0.5)


def put(target: Path, data: bytes) -> str:
    """Write data to target unless it already holds it; refuse foreign content."""
    if target.exists():
        if target.read_bytes() == data:
            return "unchanged"
        raise SystemExit(f"{target} exists with other content; not overwriting")
    target.parent.mkdir(parents=True, exist_ok=True)
    tmp = target.with_name(target.name + ".fps60.tmp")
    tmp.write_bytes(data)
    replace_retry(tmp, target)
    return "added"


def main() -> None:
    no_emulator()
    verify = (BUILD / "verify.txt").read_text(encoding="utf-8")
    assert "RESULT: ALL CHECKS PASSED" in verify, "build v2 verify.txt does not pass"
    data = {}
    for rel, (src, want) in FILES.items():
        b = src.read_bytes()
        assert sha(b) == want, (rel, sha(b))
        data[rel] = b
    before = sorted(p.relative_to(PATCH).as_posix() for p in PATCH.rglob("*") if p.is_file())
    pre_existing = [r for r in FILES if r in before]
    assert len(before) - len(pre_existing) == EXPECT_BEFORE, (len(before), pre_existing)
    assert all(r.startswith("romfs/") for r in before if r not in FILES)

    # backup (once) of the distribution ZIP; the two files did not exist before this install
    BACKUP.mkdir(parents=True, exist_ok=True)
    zbak = BACKUP / ZPATH.name
    with zipfile.ZipFile(ZPATH) as z:
        names = set(z.namelist())
    if not zbak.exists():
        assert not any(ZPREFIX + r in names for r in FILES), "ZIP already has a 60fps file but no backup"
        shutil.copy2(ZPATH, zbak)
    (BACKUP / "README.txt").write_text(
        "Before the 60fps install (2026-10-30): patch/ and the SD package had no code.bps and no romfs/BAI/BAI.dat.\n"
        "Undo = delete those two files from patch/00040000001CA900/ and work/sd_package/luma/titles/00040000001CA900/,\n"
        "and copy ml3dx_ko_luma.zip from this folder back to work/sd_package/.\n", encoding="utf-8")

    actions = {}
    for rel, b in data.items():
        actions["patch/" + rel] = put(PATCH / rel, b)
        actions["sd/" + rel] = put(DISTRO / rel, b)

    # ZIP: keep every old entry byte for byte (same ZipInfo), add the two files (deflated, like the other files)
    tmp = PACKAGE / "ml3dx_ko_luma.fps60.tmp.zip"
    with zipfile.ZipFile(ZPATH) as old:
        missing = [r for r in FILES if ZPREFIX + r not in old.namelist()]
        for r in FILES:
            if ZPREFIX + r in old.namelist():
                assert old.read(ZPREFIX + r) == data[r], f"ZIP holds another {r}"
        if missing:
            ref = next(i for i in old.infolist() if not i.is_dir() and i.compress_type == zipfile.ZIP_DEFLATED)
            with zipfile.ZipFile(tmp, "w") as new:
                new.comment = old.comment
                for info in old.infolist():
                    new.writestr(info, old.read(info.filename))
                for r in missing:
                    zi = zipfile.ZipInfo(ZPREFIX + r, date_time=time.localtime()[:6])
                    zi.compress_type = zipfile.ZIP_DEFLATED
                    zi.external_attr = ref.external_attr
                    zi.create_system = ref.create_system
                    new.writestr(zi, data[r])
    if missing:  # the old ZIP is closed here (Windows cannot replace an open file)
        with zipfile.ZipFile(tmp) as z:
            assert z.testzip() is None
            assert all(z.read(ZPREFIX + r) == data[r] for r in FILES)
        replace_retry(tmp, ZPATH)
    actions["zip"] = f"added {missing}" if missing else "unchanged"

    # full check: patch == Azahar junction == SD folder == ZIP for every file of the title folder
    files = sorted(p for p in PATCH.rglob("*") if p.is_file())
    with zipfile.ZipFile(ZPATH) as z:
        assert z.testzip() is None
        zip_files = sorted(n[len(ZPREFIX):] for n in z.namelist() if n.startswith(ZPREFIX) and not n.endswith("/"))
        for p in files:
            rel = p.relative_to(PATCH).as_posix()
            b = p.read_bytes()
            assert (JUNCTION / rel).read_bytes() == b, ("junction", rel)
            assert (DISTRO / rel).read_bytes() == b, ("sd", rel)
            assert z.read(ZPREFIX + rel) == b, ("zip", rel)
    sd_files = sorted(p.relative_to(DISTRO).as_posix() for p in DISTRO.rglob("*") if p.is_file())
    patch_rel = [p.relative_to(PATCH).as_posix() for p in files]
    patch_rel = sorted(patch_rel)  # Path order is case-insensitive on Windows; compare plain sorted strings
    assert sd_files == patch_rel == zip_files, ("file lists differ", set(sd_files) ^ set(patch_rel), set(zip_files) ^ set(patch_rel))
    result = {
        "installed": {rel: {"sha256": sha(b), "bytes": len(b)} for rel, b in data.items()},
        "actions": actions,
        "title_folder_files": len(files),
        "romfs_files": sum(1 for r in patch_rel if r.startswith("romfs/")),
        "patch_junction_sd_zip_match": True,
        "zip_sha256": fsha(ZPATH),
        "zip_backup": str(zbak),
        "korean_patch_files_unchanged": EXPECT_BEFORE,
    }
    (OUT / "install.json").write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(result, indent=2))


if __name__ == "__main__":
    main()
