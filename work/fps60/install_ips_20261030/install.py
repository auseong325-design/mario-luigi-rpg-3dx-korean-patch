"""Switch the shipped 60fps code patch from code.bps to code.ips (same patched code, Option A = build v2).

Why: on real hardware Luma3DS v13.4 (latest release) panics in its loader before the game starts
(crash_dump_00000011.dmp: process "loader", svcBreak(USERBREAK_PANIC) at 0x14000878, reached from 0x14000730
`blt` right after svcControlMemory). Its BPS patcher first allocates ALL free APPLICATION memory as a temporary
buffer (bps_patcher.cpp ScopedAppHeap); with this game's New 3DS 124 MB mode that is 0x07907000 bytes and the
allocation fails. Luma master caps it at 30 MB (commit aef3130, 2026-09-04) but no release has that yet.
Luma's IPS patcher writes into the code buffer directly and allocates nothing. The IPS gives the same bytes as the
BPS on v1.2 (build v2 verify.txt: luma_v10.1-v13.4_ips / luma_master_ips / azahar_ips ok).

Changes: <title>/code.bps -> removed (kept in the backup), <title>/code.ips added, in patch/00040000001CA900/,
work/sd_package/luma/titles/00040000001CA900/ and work/sd_package/ml3dx_ko_luma.zip. Nothing else changes.
Backup: work/build/prev_fps60_ips_20261030/. Idempotent. No emulator may be running.
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
BACKUP = ROOT / "work/build/prev_fps60_ips_20261030"
JUNCTION = Path(os.environ["APPDATA"]) / "Azahar/load/mods" / TITLE
IPS_SHA = "e5aa7d60686a9129508600e0a43f4391290dd09e9a9661db1c9de1d3b05d998a"
BPS_SHA = "c3922b9dcaafb5edacee2eda93ae13bd4c49f49c256495fbc456baf19a405be2"
EXPECT_FILES = 38  # 36 Korean patch + code patch + romfs/BAI/BAI.dat


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


def main() -> None:
    no_emulator()
    assert "luma_v10.1-v13.4_ips ok" in (BUILD / "verify.txt").read_text(encoding="utf-8")
    ips = (BUILD / "code.ips").read_bytes()
    assert sha(ips) == IPS_SHA
    BACKUP.mkdir(parents=True, exist_ok=True)
    actions = {}
    for name, folder in (("patch", PATCH), ("sd", DISTRO)):
        bps, ipsf = folder / "code.bps", folder / "code.ips"
        if bps.exists():
            assert sha(bps.read_bytes()) == BPS_SHA, f"{bps} is not the shipped v2 code.bps"
            keep = BACKUP / name / "code.bps"
            keep.parent.mkdir(parents=True, exist_ok=True)
            if not keep.exists():
                shutil.copy2(bps, keep)
            assert keep.read_bytes() == bps.read_bytes()
            bps.unlink()
            actions[f"{name}/code.bps"] = "removed (backup kept)"
        else:
            actions[f"{name}/code.bps"] = "absent"
        if ipsf.exists():
            assert ipsf.read_bytes() == ips, f"{ipsf} exists with other content"
            actions[f"{name}/code.ips"] = "unchanged"
        else:
            tmp = ipsf.with_name("code.ips.fps60.tmp")
            tmp.write_bytes(ips)
            replace_retry(tmp, ipsf)
            actions[f"{name}/code.ips"] = "added"

    zbak = BACKUP / ZPATH.name
    with zipfile.ZipFile(ZPATH) as z:
        names = z.namelist()
    need = (ZPREFIX + "code.bps") in names or (ZPREFIX + "code.ips") not in names
    if need:
        if not zbak.exists():
            shutil.copy2(ZPATH, zbak)
        tmpz = PACKAGE / "ml3dx_ko_luma.fps60_ips.tmp.zip"
        with zipfile.ZipFile(ZPATH) as old:
            ref = next(i for i in old.infolist() if not i.is_dir() and i.compress_type == zipfile.ZIP_DEFLATED)
            with zipfile.ZipFile(tmpz, "w") as new:
                new.comment = old.comment
                for info in old.infolist():
                    if info.filename in (ZPREFIX + "code.bps", ZPREFIX + "code.ips"):
                        continue
                    new.writestr(info, old.read(info.filename))
                zi = zipfile.ZipInfo(ZPREFIX + "code.ips", date_time=time.localtime()[:6])
                zi.compress_type = zipfile.ZIP_DEFLATED
                zi.external_attr = ref.external_attr
                zi.create_system = ref.create_system
                new.writestr(zi, ips)
        with zipfile.ZipFile(tmpz) as z:
            assert z.testzip() is None and z.read(ZPREFIX + "code.ips") == ips
            assert ZPREFIX + "code.bps" not in z.namelist()
        replace_retry(tmpz, ZPATH)
        actions["zip"] = "code.bps entry dropped, code.ips added"
    else:
        actions["zip"] = "unchanged"

    files = [p for p in PATCH.rglob("*") if p.is_file()]
    rel = sorted(p.relative_to(PATCH).as_posix() for p in files)
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
    assert srel == rel == zrel, (set(srel) ^ set(rel), set(zrel) ^ set(rel))
    result = {"code.ips": {"sha256": IPS_SHA, "bytes": len(ips)}, "actions": actions,
              "title_folder_files": len(rel), "patch_junction_sd_zip_match": True,
              "zip_sha256": sha(ZPATH.read_bytes()), "backup": str(BACKUP)}
    (OUT / "install.json").write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(result, indent=2))


if __name__ == "__main__":
    main()
