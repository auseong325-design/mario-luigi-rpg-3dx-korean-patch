"""Wave 5 install (2026-10-30): menu fonts v2 (FONT2), SUYEOM stat label (FONT2), 스타&스타 BAI fix v3b (STAR2).

Replaces four files of the title folder, changes nothing else (code.ips stays the v2 one):
  romfs/Msg/JP_ja/font.bffnt      <- work/build/menu_font_stage/v2/   (1DX Latin/digit/punct glyphs, tight advances)
  romfs/Msg/JP_ja/font_btl.bffnt  <- work/build/menu_font_stage/v2/
  romfs/Lyt/JP/MLyt.dat           <- work/build/suyeom_label_stage/   (ST_HIGE label at SPEED width, 5 copies)
  romfs/BAI/BAI.dat               <- work/fps60/build/v3b/            (atk_pc_sp_ml_star*.bai throw cycle)
in patch/00040000001CA900/, work/sd_package/luma/titles/00040000001CA900/ and work/sd_package/ml3dx_ko_luma.zip.
Each replaced file must currently hold exactly the version the stage was built from. Backups (old files + ZIP) in
work/build/prev_wave5_20261030/. Idempotent. No emulator may be running.
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

ROOT = Path(__file__).resolve().parents[2]
OUT = Path(__file__).parent
TITLE = "00040000001CA900"
PATCH = ROOT / "patch" / TITLE
PACKAGE = ROOT / "work/sd_package"
DISTRO = PACKAGE / "luma/titles" / TITLE
ZPATH = PACKAGE / "ml3dx_ko_luma.zip"
ZPREFIX = f"luma/titles/{TITLE}/"
BACKUP = ROOT / "work/build/prev_wave5_20261030"
JUNCTION = Path(os.environ["APPDATA"]) / "Azahar/load/mods" / TITLE
EXPECT_FILES = 38

# rel path: (source, sha256 the installed file must have now, sha256 of the new file)
FILES = {
    "romfs/Msg/JP_ja/font.bffnt": (ROOT / "work/build/menu_font_stage/v2/romfs/Msg/JP_ja/font.bffnt",
                                   "461125b999e0", "a786316c26fe"),
    "romfs/Msg/JP_ja/font_btl.bffnt": (ROOT / "work/build/menu_font_stage/v2/romfs/Msg/JP_ja/font_btl.bffnt",
                                       "874281604410", "6c058d36905f"),
    "romfs/Lyt/JP/MLyt.dat": (ROOT / "work/build/suyeom_label_stage/romfs/Lyt/JP/MLyt.dat",
                              "fec2bac8300f", "14f0aa9a6c22"),
    "romfs/BAI/BAI.dat": (ROOT / "work/fps60/build/v3b/romfs/BAI/BAI.dat", "c681a963b842", "8f3c1928b91f"),
}


def sha(b: bytes) -> str:
    return hashlib.sha256(b).hexdigest()


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
    tmp = target.with_name(target.name + ".wave5.tmp")
    tmp.write_bytes(data)
    replace_retry(tmp, target)
    return "replaced"


def main() -> None:
    no_emulator()
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
        tmpz = PACKAGE / "ml3dx_ko_luma.wave5.tmp.zip"
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
            assert (JUNCTION / r).read_bytes() == b, ("junction", r)
            assert (DISTRO / r).read_bytes() == b, ("sd", r)
            assert z.read(ZPREFIX + r) == b, ("zip", r)
    srel = sorted(p.relative_to(DISTRO).as_posix() for p in DISTRO.rglob("*") if p.is_file())
    assert srel == rel == zrel
    result = {"installed": {r: sha(b) for r, b in data.items()}, "actions": actions,
              "title_folder_files": len(rel), "patch_junction_sd_zip_match": True,
              "zip_sha256": sha(ZPATH.read_bytes()), "backup": str(BACKUP)}
    (OUT / "install.json").write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(result, indent=2))


if __name__ == "__main__":
    main()
