"""Direct check of the universal tool (C:\\AI-Projects\\3ds-patch-universal-tool) against the shipped patch.

Imports korean_patch_manager from the tool project (read-only: bytecode writing is off, nothing is written
there; a size/mtime snapshot of the whole tool project is compared before and after) and runs its real
functions on the real patch files. Inputs: scratch dt/ trees from prep_inputs.py. Outputs: scratch dt/out/,
results -> work/review/dist_tool_20261031/results.json.

  T1 metadata.identify on the base / update CIA
  T2 inspect (full v1.2 tree, code.ips, original code)
  T3 build -> luma.zip / azahar.zip, compared with patch/, the SD folder and the release ZIP
  T4 variants: Korean only (no code.ips, no BAI.dat), 60fps only (BAI.dat + code.ips), union = full
  T5 limits: edited = patch folder only, IPS vs v1.0 code, update CIA as the game file
  T6 xdelta bundle -> apply -> restored_packages (v1.2 base and v1.0 base), wrong-base apply
  T7 deploy_azahar into scratch user folders (fresh, repeat, old version present, junction)
  T8 deploy_ftp to a local pyftpdlib server (only if pyftpdlib is importable from dt/pylib)
"""
from __future__ import annotations

import sys

sys.dont_write_bytecode = True

import hashlib  # noqa: E402
import json  # noqa: E402
import os  # noqa: E402
import shutil  # noqa: E402
import socket  # noqa: E402
import stat  # noqa: E402
import threading  # noqa: E402
import time  # noqa: E402
import traceback  # noqa: E402
import zipfile  # noqa: E402
from pathlib import Path  # noqa: E402

ROOT = Path(__file__).resolve().parents[3]
HERE = Path(__file__).resolve().parent
TID = "00040000001CA900"
TOOLROOT = Path(r"C:\AI-Projects\3ds-patch-universal-tool")
TT = TOOLROOT / "upstream" / "TranslationToolkit"
XDELTA = TT / "tools" / "xdelta-3.2.2" / "xdelta3.exe"
SCRATCH = Path(os.environ["KIROCREW_SCRATCH"]).resolve()
DT = SCRATCH / "dt"
# DT_TAG (environment) = name of this run: outputs go to dt/<tag>/, results to results_<tag>.json.
# Unset = the first run's layout (dt/out, dt/az1 ..., results.json).
TAG = os.environ.get("DT_TAG", "").strip()
RUN = DT / TAG if TAG else DT
OUT = RUN / "out"
PATCH = ROOT / "patch" / TID
SD = ROOT / "work" / "sd_package" / "luma" / "titles" / TID
SDZIP = ROOT / "work" / "sd_package" / "ml3dx_ko_luma.zip"
CODE_IPS = PATCH / "code.ips"
V12CODE = ROOT / "work" / "fps60" / "bin" / "3dx_v12.code.bin"
V10CODE = ROOT / "work" / "fps60" / "bin" / "3dx_v10.code.bin"
BASE_CIA = next(ROOT.glob("00040000001CA900*.cia"))
UPD_CIA = next(ROOT.glob("0004000E001CA900*.cia"))

sys.path.insert(0, str(TT))
from korean_patch_manager import core, metadata  # noqa: E402

RESULTS: list[dict] = []


def sha256b(b: bytes) -> str:
    return hashlib.sha256(b).hexdigest()


def tree(root: Path) -> dict[str, Path]:
    return {p.relative_to(root).as_posix(): p for p in Path(root).rglob("*") if p.is_file()}


def dir_hashes(root: Path) -> dict[str, str]:
    return {rel: core.sha256(p) for rel, p in tree(root).items()}


def zip_hashes(zpath: Path) -> dict[str, str]:
    out = {}
    with zipfile.ZipFile(zpath) as z:
        names = [i.filename for i in z.infolist()]
        if len(names) != len(set(names)):
            raise AssertionError(f"duplicate entries in {zpath.name}")
        for info in z.infolist():
            if not info.is_dir():
                out[info.filename] = sha256b(z.read(info))
    return out


def split(hashes: dict[str, str], prefix: str) -> tuple[dict[str, str], list[str]]:
    inside = {k[len(prefix):]: v for k, v in hashes.items() if k.startswith(prefix)}
    return inside, sorted(k for k in hashes if not k.startswith(prefix))


def diff(a: dict[str, str], b: dict[str, str]) -> dict:
    return {"only_a": sorted(set(a) - set(b)), "only_b": sorted(set(b) - set(a)),
            "bytes_differ": sorted(k for k in set(a) & set(b) if a[k] != b[k]), "equal": a == b}


def snapshot(root: Path) -> dict[str, tuple[int, int]]:
    snap = {}
    for dirpath, dirnames, filenames in os.walk(root):
        for n in filenames:
            p = Path(dirpath) / n
            st = os.lstat(p)
            snap[str(p.relative_to(root))] = (st.st_size, st.st_mtime_ns)
        for n in dirnames:
            p = Path(dirpath) / n
            snap[str(p.relative_to(root)) + os.sep] = (0, 0)
    return snap


def record(tid: str, title: str, fn) -> None:
    t0 = time.time()
    entry = {"id": tid, "title": title}
    try:
        entry.update(fn())
        entry.setdefault("ok", True)
    except Exception as exc:  # a failing check is a result, not a crash of the run
        entry["ok"] = False
        entry["exception"] = f"{type(exc).__name__}: {exc}"
        entry["traceback"] = traceback.format_exc(limit=4)
    entry["seconds"] = round(time.time() - t0, 2)
    RESULTS.append(entry)
    print(f"[{tid}] ok={entry['ok']} {title} ({entry['seconds']} s)", flush=True)


def expect_error(fn, *args, **kw) -> str:
    """Outcome of a call that the earlier tool version refused: the error text, or a marked success.
    (Recorded, not asserted: an updated tool may accept a case it used to refuse.)"""
    try:
        ret = fn(*args, **kw)
    except Exception as exc:
        return f"{type(exc).__name__}: {exc}"
    return f"ACCEPTED (no error): {str(ret)[:160]}"


def fresh(p: Path) -> Path:
    if os.path.normcase(os.path.realpath(p)).startswith(os.path.normcase(str(DT)) + os.sep) is False:
        raise SystemExit(f"refusing: {p} outside dt")
    if p.exists():
        raise SystemExit(f"{p} exists; rerun prep or delete dt/out")
    return p


PATCH_H = dir_hashes(PATCH)                       # 'romfs/...', 'code.ips'
AZ_EXPECT = {("exefs/code.ips" if k == "code.ips" else k): v for k, v in PATCH_H.items()}
BASE = {"title_id": TID, "region": "JPN", "version": "본편 v1.0.0 + 업데이트 v1.2.0 필수",
        "original_rom": str(BASE_CIA), "code_ips": str(CODE_IPS), "original_code": str(V12CODE)}
CFG_FULL = dict(BASE, original=str(DT / "v12"), edited=str(DT / "ed_full"))
CFG_KO = dict(BASE, original=str(DT / "v12"), edited=str(DT / "ed_ko"), code_ips="", original_code="")
CFG_60 = dict(BASE, original=str(DT / "v12"), edited=str(DT / "ed_60"))
CFG_FULL_V10 = dict(BASE, original=str(DT / "v10"), edited=str(DT / "ed_full_v10"))


def check_pkg(outdir: Path, expect_luma: dict[str, str]) -> dict:
    lz, lout = split(zip_hashes(outdir / "luma.zip"), f"luma/titles/{TID}/")
    az, aout = split(zip_hashes(outdir / "azahar.zip"), f"load/mods/{TID}/")
    expect_az = {("exefs/code.ips" if k == "code.ips" else k): v for k, v in expect_luma.items()}
    d1, d2 = diff(lz, expect_luma), diff(az, expect_az)
    with zipfile.ZipFile(outdir / "luma.zip") as z:
        guide = z.read("설치 안내.txt").decode("utf-8") if "설치 안내.txt" in z.namelist() else None
    return {"luma_files": len(lz), "luma_root_extras": lout, "luma_vs_expected": d1,
            "azahar_files": len(az), "azahar_root_extras": aout, "azahar_vs_expected": d2,
            "zip_bytes": {n: (outdir / n).stat().st_size for n in ("luma.zip", "azahar.zip")},
            "guide_txt": guide, "ok": d1["equal"] and d2["equal"]}


def t1():
    return {"base_cia": metadata.identify(BASE_CIA), "update_cia": metadata.identify(UPD_CIA),
            "base_cia_name": BASE_CIA.name, "update_cia_name": UPD_CIA.name}


def t2():
    r = core.inspect(CFG_FULL)
    paths = [c["path"] for c in r["changes"]]
    expect = sorted(k[len("romfs/"):] for k in PATCH_H if k.startswith("romfs/"))
    ips_records = core.validate_ips(CODE_IPS, V12CODE.stat().st_size)
    return {"changes": len(paths), "removed": len(r["removed"]), "paths_equal_patch": sorted(paths) == expect,
            "added_files": [c["path"] for c in r["changes"] if c["original_sha256"] is None],
            "rom_metadata": r["rom_metadata"], "code_ips_sha256": r["code_ips_sha256"],
            "original_code_sha256": r["original_code_sha256"], "ips_records": ips_records,
            "ok": sorted(paths) == expect and not r["removed"] and ips_records == 8}


def t3():
    out = fresh(OUT / "full")
    core.build(CFG_FULL, out)
    res = check_pkg(out, PATCH_H)
    sd = dir_hashes(SD)
    sdz, sdz_out = split(zip_hashes(SDZIP), f"luma/titles/{TID}/")
    lz, _ = split(zip_hashes(out / "luma.zip"), f"luma/titles/{TID}/")
    res["luma_vs_sd_folder"] = diff(lz, sd)
    res["luma_vs_release_zip"] = diff(lz, sdz)
    res["release_zip_root_extras"] = sdz_out
    res["output_folder"] = sorted(p.name for p in out.iterdir())
    res["ok"] = res["ok"] and res["luma_vs_sd_folder"]["equal"] and res["luma_vs_release_zip"]["equal"]
    return res


def t4():
    out_ko, out_60 = fresh(OUT / "ko"), fresh(OUT / "fps60")
    core.build(CFG_KO, out_ko)
    core.build(CFG_60, out_60)
    exp_ko = {k: v for k, v in PATCH_H.items() if k not in ("romfs/BAI/BAI.dat", "code.ips")}
    exp_60 = {k: v for k, v in PATCH_H.items() if k in ("romfs/BAI/BAI.dat", "code.ips")}
    ko, f60 = check_pkg(out_ko, exp_ko), check_pkg(out_60, exp_60)
    lko, _ = split(zip_hashes(out_ko / "luma.zip"), f"luma/titles/{TID}/")
    l60, _ = split(zip_hashes(out_60 / "luma.zip"), f"luma/titles/{TID}/")
    union = dict(lko)
    union.update(l60)
    return {"korean_only": ko, "fps60_only": f60, "overlap": sorted(set(lko) & set(l60)),
            "union_vs_full": diff(union, PATCH_H),
            "ok": ko["ok"] and f60["ok"] and not (set(lko) & set(l60)) and union == PATCH_H}


def t5():
    res = {}
    cfg = dict(BASE, original=str(DT / "v12"), edited=str(DT / "patch_only"))
    r = core.inspect(cfg)
    res["patch_only_inspect"] = {"changes": len(r["changes"]), "removed": len(r["removed"])}
    res["patch_only_build"] = expect_error(core.build, cfg, fresh(OUT / "patch_only"))
    v10, v12 = V10CODE.read_bytes(), V12CODE.read_bytes()
    spans = core.ips_ranges(CODE_IPS, len(v12))
    res["code_sizes"] = {"v10": len(v10), "v12": len(v12)}
    res["ips_on_v10_size_check"] = core.validate_ips(CODE_IPS, len(v10))
    res["code_bytes_differ_v10_v12"] = sum(1 for a, b in zip(v10, v12) if a != b)
    res["ips_spans"] = [{"start": hex(s), "len": e - s, "v10_equals_v12_here": v10[s:e] == v12[s:e]} for s, e in spans]
    res["update_cia_as_game"] = expect_error(core.inspect, dict(CFG_FULL, original_rom=str(UPD_CIA)))
    return res


def t6():
    res = {}
    xd = OUT / "xdelta"
    xd.mkdir(parents=True, exist_ok=False)
    b12, b10 = xd / "bundle_v12base.zip", xd / "bundle_v10base.zip"
    core.xdelta_bundle(CFG_FULL, b12, str(XDELTA))
    core.xdelta_bundle(CFG_FULL_V10, b10, str(XDELTA))
    for name, b in (("v12base", b12), ("v10base", b10)):
        with zipfile.ZipFile(b) as z:
            names = z.namelist()
        res[f"bundle_{name}"] = {"bytes": b.stat().st_size, "entries": len(names),
                                  "patches": sum(n.startswith("patches/") for n in names),
                                  "added": sum(n.startswith("added/") for n in names), "code_ips": "code.ips" in names}
    # end user: apply to the matching original RomFS, then build the install ZIPs
    for name, b, orig in (("v12base", b12, DT / "v12"), ("v10base", b10, DT / "v10")):
        restored, pk = xd / f"restored_{name}", xd / f"packages_{name}"
        n = core.apply_xdelta_bundle(b, orig, restored, str(XDELTA), original_rom=str(BASE_CIA),
                                     original_code=str(V12CODE))
        core.restored_packages(restored, pk)
        res[f"apply_{name}"] = {"files": n, **check_pkg(pk, PATCH_H)}
    # end user with the other base
    res["apply_v12base_to_v10"] = expect_error(core.apply_xdelta_bundle, b12, DT / "v10", xd / "wrong1", str(XDELTA))
    res["apply_v10base_to_v12"] = expect_error(core.apply_xdelta_bundle, b10, DT / "v12", xd / "wrong2", str(XDELTA))
    res["apply_with_v10_code"] = expect_error(core.apply_xdelta_bundle, b12, DT / "v12", xd / "wrong3", str(XDELTA),
                                              original_code=str(V10CODE))
    res["ok"] = res["apply_v12base"]["ok"] and res["apply_v10base"]["ok"]
    return res


def t7():
    import _winapi
    res = {}
    az1 = fresh(RUN / "az1")
    az1.mkdir()
    target = core.deploy_azahar(CFG_FULL, az1)
    got = dir_hashes(target)
    res["fresh_full"] = {"target": str(Path(target).relative_to(DT)), "vs_expected": diff(got, AZ_EXPECT)}
    res["repeat_full"] = expect_error(core.deploy_azahar, CFG_FULL, az1)
    core.deploy_azahar(CFG_KO, az1)
    res["korean_over_same_files"] = {"files_after": len(tree(target)), "unchanged": dir_hashes(target) == got}
    # an older patch version already installed: one file differs
    az2 = fresh(RUN / "az2")
    old = az2 / "load" / "mods" / TID / "romfs" / "Msg" / "JP_ja" / "FMsg.dat"
    old.parent.mkdir(parents=True)
    shutil.copyfile(DT / "v12" / "Msg" / "JP_ja" / "FMsg.dat", old)
    res["older_version_present"] = expect_error(core.deploy_azahar, CFG_KO, az2)
    res["older_version_files_after"] = len(tree(az2 / "load" / "mods" / TID))
    # the mods folder is a junction (as on the dev PC: Azahar mods -> patch/)
    az3, jt = fresh(RUN / "az3"), fresh(RUN / "junction_target")
    (az3 / "load" / "mods").mkdir(parents=True)
    jt.mkdir()
    _winapi.CreateJunction(str(jt), str(az3 / "load" / "mods" / TID))
    try:
        core.deploy_azahar(CFG_KO, az3)
        res["junction"] = {"refused": False, "files_written_into_junction_target": len(tree(jt))}
    except Exception as exc:
        res["junction"] = {"refused": True, "error": f"{type(exc).__name__}: {exc}",
                           "files_written_into_junction_target": len(tree(jt))}
    finally:
        os.rmdir(az3 / "load" / "mods" / TID)  # removes the junction only
    res["ok"] = res["fresh_full"]["vs_expected"]["equal"]
    return res


def t8():
    pylib = DT / "pylib"
    if not pylib.is_dir():
        return {"ok": None, "skipped": "pyftpdlib not installed in dt/pylib"}
    sys.path.insert(0, str(pylib))
    from pyftpdlib.authorizers import DummyAuthorizer
    from pyftpdlib.handlers import FTPHandler
    from pyftpdlib.servers import FTPServer
    root = fresh(RUN / "ftp_root")
    root.mkdir()
    auth = DummyAuthorizer()
    auth.add_anonymous(str(root), perm="elradfmwMT")
    handler = type("H", (FTPHandler,), {"authorizer": auth})
    server = FTPServer(("127.0.0.1", 0), handler)
    port = server.socket.getsockname()[1]
    th = threading.Thread(target=server.serve_forever, kwargs={"timeout": 0.2}, daemon=True)
    th.start()
    res = {}
    try:
        n = core.deploy_ftp(CFG_FULL, "127.0.0.1", port)
        got = dir_hashes(root / "luma" / "titles" / TID)
        res["first"] = {"romfs_files": n, "vs_patch": diff(got, PATCH_H)}
        res["second"] = expect_error(core.deploy_ftp, CFG_FULL, "127.0.0.1", port)
    finally:
        server.close_all()
    res["ok"] = res["first"]["vs_patch"]["equal"]
    return res


def main() -> None:
    if not DT.is_dir():
        raise SystemExit("run prep_inputs.py first")
    OUT.mkdir(parents=True, exist_ok=True)
    before = snapshot(TOOLROOT)
    t0 = time.time()
    record("T1", "게임 파일 정보 읽기 (metadata.identify)", t1)
    record("T2", "변경 분석 (inspect)", t2)
    record("T3", "Luma / Azahar ZIP 생성 (build) = 현재 배포본", t3)
    record("T4", "선택 배포: 한글만 / 60fps만 / 합치기", t4)
    record("T5", "한계 확인 (패치 폴더만, v1.0 코드, 업데이트 CIA)", t5)
    record("T6", "xdelta 생성·적용·설치 ZIP 복원", t6)
    record("T7", "Azahar 직접 설치 (임시 폴더)", t7)
    record("T8", "FTP 전송 (로컬 서버)", t8)
    after = snapshot(TOOLROOT)
    changed = sorted(k for k in set(before) | set(after) if before.get(k) != after.get(k))
    summary = {"when": time.strftime("%Y-%m-%d %H:%M:%S"), "seconds": round(time.time() - t0, 1),
               "tool_project_files": len(before), "tool_project_changed": changed,
               "python": sys.version.split()[0], "results": RESULTS}
    summary["tag"] = TAG or None
    name = f"results_{TAG}.json" if TAG else "results.json"
    (HERE / name).write_text(json.dumps(summary, ensure_ascii=False, indent=1), encoding="utf-8")
    print(json.dumps({"tool_project_changed": changed, "ok": {r["id"]: r["ok"] for r in RESULTS}}, ensure_ascii=False))


if __name__ == "__main__":
    main()
