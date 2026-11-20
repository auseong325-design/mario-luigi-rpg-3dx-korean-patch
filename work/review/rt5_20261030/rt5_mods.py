"""RT5 helper: two extra mods modes for the TEST instance, built on rt_mods.py's own safety functions.

  rt5_mods.py use-empty TAG [--replace]   mods_builds/TAG = EMPTY real folder, mods junction -> it (no LayeredFS, no code)
  rt5_mods.py use-copy TAG [--replace]    mods_builds/TAG = byte copy of the WHOLE patch/00040000001CA900 (romfs + code.ips
                                          at the title root, 38 files), junction -> it (= use-patch, but a real folder,
                                          so tb_build.py can install a test bed into it)

TAG must start with "rt5" (BRIEF5: RT5 owns tools/azahar-test/mods_builds/rt5*).  Refuses while azahar.exe runs.
Never writes under patch/ or the user's Azahar folders.  rt_mods.py itself is imported, not changed.
"""
from __future__ import annotations

import argparse
import json
import os
import shutil
import sys
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT / "scripts" / "fps60"))
import rt_mods  # noqa: E402


def _prep(tag: str, replace: bool) -> Path:
    if rt_mods.emulator_running():
        raise SystemExit("stop the test emulator first (rt_launch.ps1 -Stop)")
    if not tag.startswith("rt5") or any(c in tag for c in "\\/:*?\"<>|"):
        raise SystemExit(f"bad tag {tag!r} (must start with rt5)")
    dst = rt_mods.BUILDS_DST / tag
    if os.path.lexists(dst):
        if not replace:
            raise SystemExit(f"{dst} exists; pass --replace")
        tgt = rt_mods.link_target(rt_mods.MODS_ENTRY)
        if tgt and os.path.normcase(os.path.realpath(tgt)) == os.path.normcase(os.path.realpath(dst)):
            rt_mods.remove_entry_link()
        rt_mods.safe_rmtree_build(dst)
    if not rt_mods.under(dst, rt_mods.TEST):
        raise SystemExit("destination escaped tools/azahar-test")
    return dst


def _link(dst: Path) -> None:
    rt_mods.remove_entry_link()
    rt_mods.make_junction(dst)
    tgt = rt_mods.link_target(rt_mods.MODS_ENTRY)
    if not tgt or os.path.normcase(os.path.realpath(tgt)) != os.path.normcase(os.path.realpath(dst)):
        raise SystemExit(f"junction target check failed: {tgt}")


def use_empty(tag: str, replace: bool) -> dict:
    dst = _prep(tag, replace)
    dst.mkdir(parents=True)
    _link(dst)
    n = rt_mods.count_files(dst)
    if n:
        raise SystemExit(f"{dst} is not empty ({n} files)")
    chk = rt_mods.check_patch_untouched()
    man = {"tag": tag, "built": time.strftime("%Y-%m-%d %H:%M:%S"), "kind": "empty", "files": n, "patch_check": chk}
    (rt_mods.BUILDS_DST / f"{tag}.json").write_text(json.dumps(man, indent=1), encoding="utf-8")
    return {"mode": f"build:{tag}", "target": str(dst), **man}


def use_copy(tag: str, replace: bool) -> dict:
    dst = _prep(tag, replace)
    shutil.copytree(rt_mods.PATCH, dst)
    rt_mods.no_reparse_inside(dst)
    src_files = sorted(p.relative_to(rt_mods.PATCH) for p in rt_mods.PATCH.rglob("*") if p.is_file())
    dst_files = sorted(p.relative_to(dst) for p in dst.rglob("*") if p.is_file())
    if src_files != dst_files:
        raise SystemExit("copy file list differs from patch/")
    bad = [str(r) for r in src_files if rt_mods.sha256(rt_mods.PATCH / r) != rt_mods.sha256(dst / r)]
    if bad:
        raise SystemExit(f"copy differs from patch/: {bad}")
    _link(dst)
    chk = rt_mods.check_patch_untouched()
    man = {"tag": tag, "built": time.strftime("%Y-%m-%d %H:%M:%S"), "kind": "copy of patch/00040000001CA900",
           "files": len(dst_files), "all_sha256_equal_patch": True, "patch_check": chk}
    (rt_mods.BUILDS_DST / f"{tag}.json").write_text(json.dumps(man, indent=1), encoding="utf-8")
    if not chk["ok"]:
        raise SystemExit(f"PATCH CHECK FAILED: {chk}")
    return {"mode": f"build:{tag}", "target": str(dst), **man}


def main(argv=None) -> None:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    for name in ("use-empty", "use-copy"):
        p = sub.add_parser(name)
        p.add_argument("tag")
        p.add_argument("--replace", action="store_true")
    a = ap.parse_args(argv)
    out = use_empty(a.tag, a.replace) if a.cmd == "use-empty" else use_copy(a.tag, a.replace)
    print(json.dumps(out, indent=1))


if __name__ == "__main__":
    main()
