"""RT2: switch what the TEST instance loads as LayeredFS/code mods (tools/azahar-test only).

  rt_mods.py status
  rt_mods.py use-patch                 user/load/mods/00040000001CA900 -> junction to patch/00040000001CA900
  rt_mods.py use-build TAG [--replace] [--empty-ok] [--ips]
        builds tools/azahar-test/mods_builds/TAG/ = COPY of patch/00040000001CA900/romfs
        + work/fps60/build/TAG/romfs/** overlay (if any) + exefs/code.bps (default; --ips: code.ips),
        then points the mods entry (a junction) at it.  --empty-ok allows a TAG without a build folder
        (no overlay, no code patch: the smoke test).  --replace rebuilds an existing mods_builds/TAG.

Rules (BRIEF2 R5): the mods entry is always a JUNCTION; it is removed with os.rmdir (removes the link only,
never the target) after asserting it is a reparse point under tools/azahar-test.  A recursive delete is done
only for an old mods_builds/TAG copy and only after asserting: real directory (not a reparse point), resolved
path inside tools/azahar-test/mods_builds, and no reparse point anywhere inside it.  Nothing is ever written
under patch/ or the user's Azahar folders.  Refuses to switch while the test emulator runs (Azahar reads the
mods at boot).  After use-patch it asserts the junction target, the patch file count (36) and the sha256 of
patch/00040000001CA900/romfs/RO/MainMenu.cro.
"""
from __future__ import annotations

import argparse
import hashlib
import json
import os
import shutil
import stat
import subprocess
import sys
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
TEST = ROOT / "tools" / "azahar-test"
TID = "00040000001CA900"
MODS_ENTRY = TEST / "user" / "load" / "mods" / TID
PATCH = ROOT / "patch" / TID
BUILDS_SRC = ROOT / "work" / "fps60" / "build"
BUILDS_DST = TEST / "mods_builds"
# 36 Korean-patch files + the 60fps install of 2026-10-30 (code.bps at the title root, romfs/BAI/BAI.dat).
# use-build copies only patch/<tid>/romfs, so test builds now start from the BAI-fixed BAI.dat.
EXPECT_PATCH_FILES = 38
MAINMENU_SHA256 = "1F227C75EA8D811AC15044884C276F84A06D60585DC372F524128040F9F1BAFC"


def is_reparse(p: Path) -> bool:
    try:
        st = os.lstat(p)
    except FileNotFoundError:
        return False
    return bool(getattr(st, "st_file_attributes", 0) & stat.FILE_ATTRIBUTE_REPARSE_POINT)


def link_target(p: Path) -> Path | None:
    if not is_reparse(p):
        return None
    t = os.readlink(p)
    if t.startswith("\\\\?\\"):
        t = t[4:]
    return Path(t)


def under(p: Path, root: Path) -> bool:
    r, rr = os.path.realpath(p), os.path.realpath(root)
    return os.path.normcase(r).startswith(os.path.normcase(rr) + os.sep)


def sha256(p: Path) -> str:
    h = hashlib.sha256()
    with p.open("rb") as f:
        for chunk in iter(lambda: f.read(1 << 20), b""):
            h.update(chunk)
    return h.hexdigest().upper()


def count_files(p: Path) -> int:
    return sum(1 for q in p.rglob("*") if q.is_file())


def emulator_running() -> list[int]:
    out = subprocess.run(["tasklist", "/FI", "IMAGENAME eq azahar.exe", "/FO", "CSV", "/NH"],
                         capture_output=True, text=True, timeout=20).stdout
    pids = []
    for line in out.splitlines():
        parts = [x.strip('"') for x in line.split('","')]
        if len(parts) > 1 and parts[0].strip('"').lower() == "azahar.exe":
            pids.append(int(parts[1]))
    return pids


def no_reparse_inside(p: Path) -> None:
    for dirpath, dirnames, filenames in os.walk(p, followlinks=False):
        for n in dirnames + filenames:
            q = Path(dirpath) / n
            if is_reparse(q):
                raise SystemExit(f"refusing: {q} is a reparse point inside {p}")


def safe_rmtree_build(p: Path) -> None:
    """Delete an old mods_builds/TAG copy, only after every R5 assertion."""
    if is_reparse(p):
        raise SystemExit(f"refusing to delete {p}: it is a reparse point")
    if not p.is_dir():
        raise SystemExit(f"refusing to delete {p}: not a directory")
    if not under(p, BUILDS_DST):
        raise SystemExit(f"refusing to delete {p}: not inside {BUILDS_DST}")
    no_reparse_inside(p)
    if os.path.normcase(os.path.realpath(p)) == os.path.normcase(os.path.realpath(PATCH)):
        raise SystemExit("refusing: that is the patch folder")
    shutil.rmtree(p)


def remove_entry_link() -> None:
    """Remove the mods entry junction itself (never its target)."""
    if not os.path.lexists(MODS_ENTRY):
        return
    if not is_reparse(MODS_ENTRY):
        raise SystemExit(f"refusing: {MODS_ENTRY} is a real folder, not a junction; inspect it by hand")
    if not under(MODS_ENTRY.parent, TEST):
        raise SystemExit("refusing: mods entry is not under tools/azahar-test")
    os.rmdir(MODS_ENTRY)  # removes the junction only
    if os.path.lexists(MODS_ENTRY):
        raise SystemExit("junction still present after rmdir")


def make_junction(target: Path) -> None:
    import _winapi
    MODS_ENTRY.parent.mkdir(parents=True, exist_ok=True)
    _winapi.CreateJunction(str(target), str(MODS_ENTRY))


def check_patch_untouched() -> dict:
    n = count_files(PATCH)
    h = sha256(PATCH / "romfs" / "RO" / "MainMenu.cro")
    ok = n == EXPECT_PATCH_FILES and h == MAINMENU_SHA256
    return {"patch_files": n, "mainmenu_sha256": h, "ok": ok}


def status() -> dict:
    d: dict = {"entry": str(MODS_ENTRY), "exists": os.path.lexists(MODS_ENTRY)}
    if d["exists"]:
        tgt = link_target(MODS_ENTRY)
        d["junction"] = tgt is not None
        d["target"] = str(tgt) if tgt else None
        if tgt:
            if os.path.normcase(os.path.realpath(tgt)) == os.path.normcase(os.path.realpath(PATCH)):
                d["mode"] = "patch"
            elif under(tgt, BUILDS_DST):
                d["mode"] = f"build:{tgt.name}"
            else:
                d["mode"] = "other"
            d["files"] = count_files(tgt)
            for name in ("code.bps", "code.ips"):
                f = tgt / "exefs" / name
                if f.exists():
                    d.setdefault("exefs", {})[name] = sha256(f)
    d["builds"] = sorted(p.name for p in BUILDS_DST.iterdir()) if BUILDS_DST.exists() else []
    d["patch_check"] = check_patch_untouched()
    d["emulator_pids"] = emulator_running()
    return d


def use_patch() -> dict:
    if emulator_running():
        raise SystemExit("stop the test emulator first (rt_launch.ps1 -Stop)")
    remove_entry_link()
    make_junction(PATCH)
    tgt = link_target(MODS_ENTRY)
    if not tgt or os.path.normcase(os.path.realpath(tgt)) != os.path.normcase(os.path.realpath(PATCH)):
        raise SystemExit(f"junction target check failed: {tgt}")
    chk = check_patch_untouched()
    if not chk["ok"]:
        raise SystemExit(f"PATCH CHECK FAILED: {chk}")
    return {"mode": "patch", "target": str(tgt), **chk}


def use_build(tag: str, replace: bool, empty_ok: bool, ips: bool) -> dict:
    if emulator_running():
        raise SystemExit("stop the test emulator first (rt_launch.ps1 -Stop)")
    if not tag or any(c in tag for c in "\\/:*?\"<>|") or tag in (".", ".."):
        raise SystemExit(f"bad tag {tag!r}")
    src = BUILDS_SRC / tag
    if not src.is_dir() and not empty_ok:
        raise SystemExit(f"{src} does not exist (use --empty-ok for a smoke tag with no build)")
    dst = BUILDS_DST / tag
    if os.path.lexists(dst):
        if not replace:
            raise SystemExit(f"{dst} exists; pass --replace to rebuild it")
        # the entry junction may point at it: drop the link first, then the copy
        if is_reparse(MODS_ENTRY) and link_target(MODS_ENTRY) and \
                os.path.normcase(os.path.realpath(link_target(MODS_ENTRY))) == os.path.normcase(os.path.realpath(dst)):
            remove_entry_link()
        safe_rmtree_build(dst)
    BUILDS_DST.mkdir(parents=True, exist_ok=True)
    if not under(dst, TEST):
        raise SystemExit("destination escaped tools/azahar-test")
    shutil.copytree(PATCH / "romfs", dst / "romfs")
    overlay = []
    if src.is_dir() and (src / "romfs").is_dir():
        for f in sorted((src / "romfs").rglob("*")):
            if f.is_file():
                rel = f.relative_to(src / "romfs")
                (dst / "romfs" / rel).parent.mkdir(parents=True, exist_ok=True)
                shutil.copy2(f, dst / "romfs" / rel)
                overlay.append({"path": str(rel).replace("\\", "/"), "sha256": sha256(f)})
    code = None
    if src.is_dir():
        name = "code.ips" if ips else "code.bps"
        if (src / name).exists():
            (dst / "exefs").mkdir(parents=True, exist_ok=True)
            shutil.copy2(src / name, dst / "exefs" / name)
            code = {"file": name, "sha256": sha256(src / name)}
        elif not empty_ok:
            raise SystemExit(f"{src / name} missing")
    remove_entry_link()
    make_junction(dst)
    tgt = link_target(MODS_ENTRY)
    if not tgt or os.path.normcase(os.path.realpath(tgt)) != os.path.normcase(os.path.realpath(dst)):
        raise SystemExit(f"junction target check failed: {tgt}")
    chk = check_patch_untouched()
    man = {"tag": tag, "built": time.strftime("%Y-%m-%d %H:%M:%S"), "source": str(src) if src.is_dir() else None,
           "files": count_files(dst), "overlay": overlay, "code": code, "patch_check": chk}
    (BUILDS_DST / f"{tag}.json").write_text(json.dumps(man, indent=1), encoding="utf-8")
    if not chk["ok"]:
        raise SystemExit(f"PATCH CHECK FAILED: {chk}")
    return {"mode": f"build:{tag}", "target": str(tgt), **man}


def main(argv=None) -> None:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    sub.add_parser("status")
    sub.add_parser("use-patch")
    p = sub.add_parser("use-build"); p.add_argument("tag"); p.add_argument("--replace", action="store_true")
    p.add_argument("--empty-ok", action="store_true"); p.add_argument("--ips", action="store_true")
    a = ap.parse_args(argv)
    if a.cmd == "status":
        out = status()
    elif a.cmd == "use-patch":
        out = use_patch()
    else:
        out = use_build(a.tag, a.replace, a.empty_ok, a.ips)
    print(json.dumps(out, indent=1))


if __name__ == "__main__":
    main()
