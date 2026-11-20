"""RomForge path of the universal tool on the real game files (scratch only).

Both CIAs are decrypted (cia_info.py: content type 0x0000, NCCH NoCrypto), so an EMPTY key folder is used;
no key files are read. Calls the tool's own korean_patch_manager.romforge functions with its built bridge.

  R1 setup_workspace(base CIA)   -> which RomFS / code the tool's "작업 폴더 준비" gives (v1.0 or v1.2)
  R2 setup_workspace(update CIA) -> what it gives for the update (title ID, files, code)
  R3 repack(base CIA, patch with v1.2 originals) -> refused or not
  R4 repack(update CIA, the 3 update-file changes + code.ips) -> CIA and CCI output
Results -> work/review/dist_tool_20261031/romforge_results.json
"""
from __future__ import annotations

import sys

sys.dont_write_bytecode = True

import json  # noqa: E402
import os  # noqa: E402
import shutil  # noqa: E402
import time  # noqa: E402
import traceback  # noqa: E402
from pathlib import Path  # noqa: E402

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
import run_tool_tests as rt  # noqa: E402  (same paths/configs; importing runs no test)
from korean_patch_manager import core, romforge  # noqa: E402

BRIDGE = rt.TOOLROOT / "RomForge-reference" / "KpmBridge" / "bin" / "Release" / "net10.0" / "KpmBridge.dll"
DT = rt.DT
KEYS = DT / "keys_empty"
UPD_TID = "0004000E001CA900"
RESULTS: list[dict] = []


def record(tid, title, fn):
    t0 = time.time()
    e = {"id": tid, "title": title}
    try:
        e.update(fn())
    except Exception as exc:
        e["exception"] = f"{type(exc).__name__}: {exc}"
        e["traceback"] = traceback.format_exc(limit=3)
    e["seconds"] = round(time.time() - t0, 1)
    RESULTS.append(e)
    print(f"[{tid}] {title} ({e['seconds']} s) {e.get('exception', '')}"[:400], flush=True)


def r1():
    r = romforge.setup_workspace(rt.BASE_CIA, KEYS, DT / "ws_base", BRIDGE)
    got = rt.dir_hashes(DT / "ws_base" / "original")
    v10 = rt.dir_hashes(DT / "v10")
    v12 = rt.dir_hashes(DT / "v12")
    return {"title_id": r["project"]["title_id"], "files": r["files"],
            "original_vs_v10": rt.diff(got, v10)["equal"],
            "original_vs_v12_differs": rt.diff(got, v12)["bytes_differ"],
            "code_equals_v10": core.sha256(DT / "ws_base" / "original_code.bin") == core.sha256(rt.V10CODE),
            "code_equals_v12": core.sha256(DT / "ws_base" / "original_code.bin") == core.sha256(rt.V12CODE)}


def r2():
    r = romforge.setup_workspace(rt.UPD_CIA, KEYS, DT / "ws_upd", BRIDGE)
    got = rt.dir_hashes(DT / "ws_upd" / "original")
    upd = rt.dir_hashes(rt.ROOT / "romf2")
    return {"title_id": r["project"]["title_id"], "files": r["files"], "original_vs_romf2": rt.diff(got, upd)["equal"],
            "code_equals_v12": core.sha256(DT / "ws_upd" / "original_code.bin") == core.sha256(rt.V12CODE)}


def r3():
    msg = rt.expect_error(romforge.repack, rt.CFG_FULL, KEYS, DT / "out" / "rf_base_v12orig.cci", "CCI", str(BRIDGE))
    return {"error": msg, "output_exists": (DT / "out" / "rf_base_v12orig.cci").exists()}


def r4():
    ed = DT / "ed_upd"
    shutil.copytree(DT / "ws_upd" / "original", ed)
    for rel in (".crr/static.crr", "FMdl/JP/FMdl.dat", "RO/MainMenu.cro"):
        shutil.copyfile(rt.PATCH / "romfs" / rel, ed / rel)
    cfg = {"title_id": UPD_TID, "original": str(DT / "ws_upd" / "original"), "edited": str(ed),
           "original_rom": str(rt.UPD_CIA), "code_ips": str(rt.CODE_IPS),
           "original_code": str(DT / "ws_upd" / "original_code.bin")}
    rep = core.inspect(cfg)
    out = {"inspect_changes": [c["path"] for c in rep["changes"]]}
    for fmt in ("CIA", "CCI"):
        dst = DT / "out" / f"rf_update.{fmt.lower()}"
        try:
            r = romforge.repack(cfg, KEYS, dst, fmt, str(BRIDGE))
            out[fmt] = {"ok": True, "sha256": r["sha256"], "checked_files": r["checked_files"],
                        "code_checked": r["code_checked"]}
        except Exception as exc:
            out[fmt] = {"ok": False, "error": f"{type(exc).__name__}: {exc}"[:600]}
        out[fmt]["output_exists"] = dst.exists()
    return out


def main():
    if not BRIDGE.is_file():
        raise SystemExit(f"bridge missing: {BRIDGE}")
    KEYS.mkdir(exist_ok=True)
    if any(KEYS.iterdir()):
        raise SystemExit("key folder must be empty")
    before = rt.snapshot(rt.TOOLROOT)
    record("R1", "작업 폴더 준비: 본편 CIA", r1)
    record("R2", "작업 폴더 준비: 업데이트 CIA", r2)
    record("R3", "RomForge 리팩: 본편 CIA + v1.2 기준 패치", r3)
    record("R4", "RomForge 리팩: 업데이트 CIA + 업데이트 파일 3개 + code.ips", r4)
    after = rt.snapshot(rt.TOOLROOT)
    changed = sorted(k for k in set(before) | set(after) if before.get(k) != after.get(k))
    doc = {"when": time.strftime("%Y-%m-%d %H:%M:%S"), "bridge": str(BRIDGE), "key_folder_empty": True,
           "tool_project_changed": changed, "results": RESULTS}
    (HERE / "romforge_results.json").write_text(json.dumps(doc, ensure_ascii=False, indent=1), encoding="utf-8")
    print(json.dumps({"tool_project_changed": changed}, ensure_ascii=False))


if __name__ == "__main__":
    main()
