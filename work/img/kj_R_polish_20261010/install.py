"""Install out/after_MLyt.dat (build_archive.py): patch/, the SD package folder and zip, lyt_stage.
Backs up the previous MLyt and zip to work/build/prev_kj_R_polish_20261010/ first, then checks that every patch
file equals the Azahar junction, the SD package and the zip. (Same procedure as
fileload_titlelogo_20261009/install.py.)"""
from pathlib import Path
import hashlib
import json
import os
import shutil
import zipfile

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
OUT = HERE / "out"
REL = Path("Lyt/JP/MLyt.dat")
PATCH = ROOT / "patch/00040000001CA900/romfs"
PACKAGE = ROOT / "work/sd_package"
DISTRO = PACKAGE / "luma/titles/00040000001CA900/romfs"
BACKUP = ROOT / "work/build/prev_kj_R_polish_20261010"
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()


def main():
    v = json.loads((OUT / "build_verify.json").read_text())
    assert sha(PATCH / REL) == v["before_sha256"], "the installed MLyt changed since build_archive.py"
    data = (OUT / "after_MLyt.dat").read_bytes()
    assert hashlib.sha256(data).hexdigest() == v["after_sha256"]
    (BACKUP / REL.parent).mkdir(parents=True, exist_ok=True)
    shutil.copy2(PATCH / REL, BACKUP / REL)
    zpath = PACKAGE / "ml3dx_ko_luma.zip"
    arc = "luma/titles/00040000001CA900/romfs/" + REL.as_posix()
    shutil.copy2(zpath, BACKUP / zpath.name)
    tmp = PACKAGE / "ml3dx_ko_luma.kj_R_polish.tmp.zip"
    with zipfile.ZipFile(zpath) as old, zipfile.ZipFile(tmp, "w") as new:
        new.comment = old.comment
        for info in old.infolist():
            new.writestr(info, data if info.filename == arc else old.read(info.filename))
    with zipfile.ZipFile(tmp) as z:
        assert z.testzip() is None and z.read(arc) == data
    tmp.replace(zpath)
    for t in [PATCH / REL, DISTRO / REL, ROOT / "work/build/lyt_stage/romfs" / REL]:
        t.parent.mkdir(parents=True, exist_ok=True)
        x = t.with_name(t.name + ".tmp")
        x.write_bytes(data)
        x.replace(t)
    junction = Path(os.environ["APPDATA"]) / "Azahar/load/mods/00040000001CA900/romfs"
    files = [p for p in PATCH.rglob("*") if p.is_file()]
    with zipfile.ZipFile(zpath) as z:
        for p in files:
            rel = p.relative_to(PATCH)
            assert sha(p) == sha(junction / rel) == sha(DISTRO / rel), rel
            assert z.read("luma/titles/00040000001CA900/romfs/" + rel.as_posix()) == p.read_bytes(), rel
    r = {"changed_patch_files": [REL.as_posix()], "MLyt_sha256": sha(PATCH / REL), "zip_sha256": sha(zpath),
         "checked_files": len(files), "backup": str(BACKUP)}
    (OUT / "install.json").write_text(json.dumps(r, indent=2) + "\n")
    print(r)


if __name__ == "__main__":
    main()
