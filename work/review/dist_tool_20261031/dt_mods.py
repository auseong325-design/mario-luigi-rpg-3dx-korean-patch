"""Load a universal-tool azahar.zip into the TEST instance (tools/azahar-test), never the user's Azahar.

  dt_mods.py use-zip TAG ZIP [--replace]
      mods_builds/TAG = exactly the files of ZIP under load/mods/00040000001CA900/ (what the user would get by
      extracting azahar.zip into the Azahar user folder), each checked by sha256; mods junction -> it.
  dt_mods.py use-merge TAG [--replace]
      merged-base simulation: patch romfs + romf2 FEvent.dat/static.crs + exefs/code.bin (v1.2 code with
      code.ips pre-applied); use with `update hide` so no update is installed (what one RomForge repack of the
      base game with base+update merged would contain).
  dt_mods.py use-empty TAG [--replace]
      mods entry -> an empty folder (no LayeredFS, no code patch), for booting a merged CCI with rt_launch.ps1 -Game.
  dt_mods.py update hide|show|status
      rename the TEST instance's installed update folder (title/0004000e/001ca900 <-> 001ca900.dt_hidden).
  dt_mods.py saves
      sha256 of the test instance's save files (to show a run left them unchanged).
  dt_mods.py log
      LayeredFS / code-patch lines of the test instance's current log (call after rt_rpc.flush_log()).

TAG must start with "dt". Refuses while azahar.exe runs. Built on rt_mods.py's safety functions (imported, not
changed); never writes under patch/ or the user's Azahar folders. Return to the patch with rt_mods.py use-patch.
"""
from __future__ import annotations

import argparse
import hashlib
import json
import os
import re
import sys
import time
import zipfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT / "scripts" / "fps60"))
import rt_mods  # noqa: E402

PREFIX = f"load/mods/{rt_mods.TID}/"
SAVE_DIR = (rt_mods.TEST / "user" / "sdmc" / "Nintendo 3DS" / ("0" * 32) / ("0" * 32) / "title" / "00040000"
            / "001ca900" / "data")
LOG = rt_mods.TEST / "user" / "log" / "azahar_log.txt"


def use_zip(tag: str, zpath: Path, replace: bool) -> dict:
    if rt_mods.emulator_running():
        raise SystemExit("stop the test emulator first (rt_launch.ps1 -Stop)")
    if not tag.startswith("dt") or any(c in tag for c in "\\/:*?\"<>|"):
        raise SystemExit(f"bad tag {tag!r} (must start with dt)")
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
    files, extras = [], []
    with zipfile.ZipFile(zpath) as z:
        for info in z.infolist():
            if info.is_dir():
                continue
            if not info.filename.startswith(PREFIX):
                extras.append(info.filename)
                continue
            rel = info.filename[len(PREFIX):]
            parts = rel.split("/")
            if not rel or any(p in ("", ".", "..") for p in parts):
                raise SystemExit(f"bad entry {info.filename}")
            out = dst.joinpath(*parts)
            out.parent.mkdir(parents=True, exist_ok=True)
            data = z.read(info)
            out.write_bytes(data)
            if hashlib.sha256(out.read_bytes()).hexdigest() != hashlib.sha256(data).hexdigest():
                raise SystemExit(f"write check failed: {rel}")
            files.append(rel)
    rt_mods.no_reparse_inside(dst)
    rt_mods.remove_entry_link()
    rt_mods.make_junction(dst)
    tgt = rt_mods.link_target(rt_mods.MODS_ENTRY)
    if not tgt or os.path.normcase(os.path.realpath(tgt)) != os.path.normcase(os.path.realpath(dst)):
        raise SystemExit(f"junction target check failed: {tgt}")
    chk = rt_mods.check_patch_untouched()
    man = {"tag": tag, "built": time.strftime("%Y-%m-%d %H:%M:%S"), "kind": "universal-tool azahar.zip",
           "zip": str(zpath), "files": len(files), "code": [f for f in files if f.endswith((".ips", ".bps"))],
           "zip_root_extras_not_copied": extras, "patch_check": chk}
    (rt_mods.BUILDS_DST / f"{tag}.json").write_text(json.dumps(man, ensure_ascii=False, indent=1), encoding="utf-8")
    if not chk["ok"]:
        raise SystemExit(f"PATCH CHECK FAILED: {chk}")
    return {"mode": f"build:{tag}", "target": str(dst), **man}


UPDATE_DIR = (rt_mods.TEST / "user" / "sdmc" / "Nintendo 3DS" / ("0" * 32) / ("0" * 32) / "title" / "0004000e"
              / "001ca900")
UPDATE_HIDDEN = UPDATE_DIR.with_name("001ca900.dt_hidden")


def apply_ips(code: bytes, ips: bytes) -> bytes:
    out = bytearray(code)
    if not ips.startswith(b"PATCH"):
        raise SystemExit("bad IPS header")
    pos = 5
    while ips[pos:pos + 3] != b"EOF":
        off = int.from_bytes(ips[pos:pos + 3], "big")
        size = int.from_bytes(ips[pos + 3:pos + 5], "big")
        pos += 5
        if size == 0:
            n = int.from_bytes(ips[pos:pos + 2], "big")
            out[off:off + n] = ips[pos + 2:pos + 3] * n
            pos += 3
        else:
            out[off:off + size] = ips[pos:pos + size]
            pos += size
    if len(out) != len(code):
        raise SystemExit("IPS changed the code size")
    return bytes(out)


def use_merge(tag: str, replace: bool) -> dict:
    """Simulate a merged base title (base + v1.2 update in one): no update installed, the v1.2 code (+ the 60fps
    IPS, pre-applied) as an ExeFS code.bin override, and the RomFS = base + the update files that differ from the
    base and are not in the patch (FEvent/FEvent.dat, RO/static.crs) + the 37 patch files."""
    if rt_mods.emulator_running():
        raise SystemExit("stop the test emulator first (rt_launch.ps1 -Stop)")
    if not tag.startswith("dt") or any(c in tag for c in "\\/:*?\"<>|"):
        raise SystemExit(f"bad tag {tag!r} (must start with dt)")
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
    import shutil
    shutil.copytree(rt_mods.PATCH / "romfs", dst / "romfs")
    added = []
    for rel in ("FEvent/FEvent.dat", "RO/static.crs"):
        src = ROOT / "romf2" / rel
        out = dst / "romfs" / rel
        if out.exists():
            raise SystemExit(f"{rel} is already in the patch")
        out.parent.mkdir(parents=True, exist_ok=True)
        shutil.copyfile(src, out)
        added.append({"path": rel, "sha256": rt_mods.sha256(out)[:16]})
    v12 = (ROOT / "work" / "fps60" / "bin" / "3dx_v12.code.bin").read_bytes()
    code = apply_ips(v12, (rt_mods.PATCH / "code.ips").read_bytes())
    (dst / "exefs").mkdir()
    (dst / "exefs" / "code.bin").write_bytes(code)
    ref = ROOT / "work" / "fps60" / "build" / "v3b" / "patched.code.bin"
    same_as_ref = ref.exists() and hashlib.sha256(code).hexdigest() == hashlib.sha256(ref.read_bytes()).hexdigest()
    rt_mods.no_reparse_inside(dst)
    rt_mods.remove_entry_link()
    rt_mods.make_junction(dst)
    tgt = rt_mods.link_target(rt_mods.MODS_ENTRY)
    if not tgt or os.path.normcase(os.path.realpath(tgt)) != os.path.normcase(os.path.realpath(dst)):
        raise SystemExit(f"junction target check failed: {tgt}")
    chk = rt_mods.check_patch_untouched()
    man = {"tag": tag, "built": time.strftime("%Y-%m-%d %H:%M:%S"), "kind": "merged-base simulation",
           "files": rt_mods.count_files(dst), "added_update_files": added,
           "code_bin_sha256": hashlib.sha256(code).hexdigest()[:16], "code_bin_equals_v3b_patched": same_as_ref,
           "patch_check": chk}
    (rt_mods.BUILDS_DST / f"{tag}.json").write_text(json.dumps(man, ensure_ascii=False, indent=1), encoding="utf-8")
    if not chk["ok"]:
        raise SystemExit(f"PATCH CHECK FAILED: {chk}")
    return {"mode": f"build:{tag}", "target": str(dst), **man}


def use_empty(tag: str, replace: bool) -> dict:
    """mods entry -> an EMPTY real folder (no LayeredFS, no code patch): for booting a merged CCI on its own."""
    if rt_mods.emulator_running():
        raise SystemExit("stop the test emulator first (rt_launch.ps1 -Stop)")
    if not tag.startswith("dt") or any(c in tag for c in "\\/:*?\"<>|"):
        raise SystemExit(f"bad tag {tag!r} (must start with dt)")
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
    dst.mkdir(parents=True)
    rt_mods.remove_entry_link()
    rt_mods.make_junction(dst)
    tgt = rt_mods.link_target(rt_mods.MODS_ENTRY)
    if not tgt or os.path.normcase(os.path.realpath(tgt)) != os.path.normcase(os.path.realpath(dst)):
        raise SystemExit(f"junction target check failed: {tgt}")
    n = rt_mods.count_files(dst)
    chk = rt_mods.check_patch_untouched()
    man = {"tag": tag, "built": time.strftime("%Y-%m-%d %H:%M:%S"), "kind": "empty", "files": n, "patch_check": chk}
    (rt_mods.BUILDS_DST / f"{tag}.json").write_text(json.dumps(man, ensure_ascii=False, indent=1), encoding="utf-8")
    if n or not chk["ok"]:
        raise SystemExit(f"check failed: files={n} patch={chk}")
    return {"mode": f"build:{tag}", "target": str(dst), **man}


def update_state(action: str) -> dict:
    """hide/show the TEST instance's installed v1.2 update (rename inside tools/azahar-test only)."""
    if rt_mods.emulator_running():
        raise SystemExit("stop the test emulator first (rt_launch.ps1 -Stop)")
    for p in (UPDATE_DIR, UPDATE_HIDDEN):
        if os.path.lexists(p) and (rt_mods.is_reparse(p) or not rt_mods.under(p, rt_mods.TEST)):
            raise SystemExit(f"refusing: {p}")
    if action == "hide":
        if not UPDATE_DIR.is_dir() or os.path.lexists(UPDATE_HIDDEN):
            raise SystemExit(f"cannot hide: present={UPDATE_DIR.is_dir()} hidden={os.path.lexists(UPDATE_HIDDEN)}")
        UPDATE_DIR.rename(UPDATE_HIDDEN)
    elif action == "show":
        if not UPDATE_HIDDEN.is_dir() or os.path.lexists(UPDATE_DIR):
            raise SystemExit(f"cannot show: present={UPDATE_DIR.is_dir()} hidden={os.path.lexists(UPDATE_HIDDEN)}")
        UPDATE_HIDDEN.rename(UPDATE_DIR)
    present = UPDATE_DIR.is_dir()
    files = {str(p.relative_to(UPDATE_DIR if present else UPDATE_HIDDEN)): p.stat().st_size
             for p in sorted((UPDATE_DIR if present else UPDATE_HIDDEN).rglob("*")) if p.is_file()}
    return {"update_installed": present, "hidden": UPDATE_HIDDEN.is_dir(), "files": files}


def saves() -> dict:
    return {str(p.relative_to(SAVE_DIR)): hashlib.sha256(p.read_bytes()).hexdigest()[:16]
            for p in sorted(SAVE_DIR.rglob("*")) if p.is_file()}


def log_lines() -> dict:
    text = LOG.read_text(encoding="utf-8", errors="replace") if LOG.exists() else ""
    repl = re.findall(r"LayeredFS replacement file in use for (\S+)", text)
    code = [ln.strip()[:240] for ln in text.splitlines() if "patching code.bin" in ln]
    n3ds = [ln.strip()[:160] for ln in text.splitlines() if "IsNew3ds" in ln][:2]
    override = [ln.strip()[:240] for ln in text.splitlines() if "override" in ln.lower()][:6]
    update = [ln.strip()[:240] for ln in text.splitlines() if "update" in ln.lower()][:8]
    errors = [ln.strip()[:240] for ln in text.splitlines() if "<Error>" in ln or "<Critical>" in ln][:12]
    return {"log_bytes": len(text), "layeredfs_replacements": len(repl), "replaced": sorted(set(repl)),
            "code_patch_lines": code, "new3ds_lines": n3ds, "override_lines": override, "update_lines": update,
            "error_lines": errors}


def main(argv=None) -> None:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    p = sub.add_parser("use-zip")
    p.add_argument("tag")
    p.add_argument("zip")
    p.add_argument("--replace", action="store_true")
    p = sub.add_parser("use-merge")
    p.add_argument("tag")
    p.add_argument("--replace", action="store_true")
    p = sub.add_parser("use-empty")
    p.add_argument("tag")
    p.add_argument("--replace", action="store_true")
    p = sub.add_parser("update")
    p.add_argument("action", choices=("hide", "show", "status"))
    sub.add_parser("saves")
    sub.add_parser("log")
    a = ap.parse_args(argv)
    if a.cmd == "use-zip":
        out = use_zip(a.tag, Path(a.zip), a.replace)
    elif a.cmd == "use-merge":
        out = use_merge(a.tag, a.replace)
    elif a.cmd == "use-empty":
        out = use_empty(a.tag, a.replace)
    elif a.cmd == "update":
        out = update_state(a.action)
    elif a.cmd == "saves":
        out = saves()
    else:
        out = log_lines()
    sys.stdout.reconfigure(encoding="utf-8")
    print(json.dumps(out, ensure_ascii=False, indent=1))


if __name__ == "__main__":
    main()
