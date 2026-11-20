"""Merge path of the UPDATED universal tool (korean_patch_manager.merge + its RomForge bridge) on the real game files.

Writes only under %KIROCREW_SCRATCH%/dt/<tag> (tag from DT_TAG, default "v2"); the tool project and the original game
files are read only (bytecode writing off). An EMPTY key folder is used: both CIAs are decrypted.

  merge_check.py stage1   M1 setup_workspace(base CIA) + setup_workspace(update CIA); compare with romfs/romf2, code,
                             exheader (read from the CIAs by exheader_diff.py), banner
                          M2 build_bundle: full (patch 37 + code.ips + Korean banner), ko (patch 37 + banner, no IPS),
                             fps60 (BAI.dat only + code.ips, no banner)
                          M3 compare our full bundle with the tool author's work/real-merge-validation/ml3dx-merge-verified.zip
  merge_check.py stage2   M4 repack_bundle -> CCI for full and ko; a CIA attempt with the empty key folder
                          M5 cci_verify.py on both CCIs: all hashes, RomFS tree == expected tree, exheader == expected
                             merge, .code == expected code, banner, icon
Results are merged into work/review/dist_tool_20261031/results_merge_<tag>.json.
"""
from __future__ import annotations

import sys

sys.dont_write_bytecode = True

import hashlib  # noqa: E402
import json  # noqa: E402
import os  # noqa: E402
import shutil  # noqa: E402
import time  # noqa: E402
import traceback  # noqa: E402
import zipfile  # noqa: E402
from pathlib import Path  # noqa: E402

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
TOOLROOT = Path(r"C:\AI-Projects\3ds-patch-universal-tool")
TT = TOOLROOT / "upstream" / "TranslationToolkit"
sys.path.insert(0, str(TT))
sys.path.insert(0, str(HERE))
from korean_patch_manager import core, merge, romforge  # noqa: E402
import cci_verify  # noqa: E402
import exheader_diff  # noqa: E402

TID = "00040000001CA900"
BRIDGE = TOOLROOT / "RomForge-reference" / "KpmBridge" / "bin" / "Release" / "net10.0" / "KpmBridge.dll"
XDELTA = TT / "tools" / "xdelta-3.2.2" / "xdelta3.exe"
THEIR_BUNDLE = TOOLROOT / "work" / "real-merge-validation" / "ml3dx-merge-verified.zip"
SCRATCH = Path(os.environ["KIROCREW_SCRATCH"]).resolve()
DT = SCRATCH / "dt"
TAG = os.environ.get("DT_TAG", "v2").strip() or "v2"
RUN = DT / TAG / "merge"
KEYS = RUN / "keys_empty"
PATCH_ROMFS = ROOT / "patch" / TID / "romfs"
CODE_IPS = ROOT / "patch" / TID / "code.ips"
BANNER_KO = ROOT / "work" / "banner_20261030" / "out" / "banner" / "banner_ko.bin"
V10CODE = ROOT / "work" / "fps60" / "bin" / "3dx_v10.code.bin"
V12CODE = ROOT / "work" / "fps60" / "bin" / "3dx_v12.code.bin"
V3B_CODE = ROOT / "work" / "fps60" / "build" / "v3b" / "patched.code.bin"
BASE_CIA = next(ROOT.glob("00040000001CA900*.cia"))
UPD_CIA = next(ROOT.glob("0004000E001CA900*.cia"))
RESULTS = HERE / f"results_merge_{TAG}.json"


def sha(p) -> str:
    return core.sha256(p)


def dir_hashes(root: Path) -> dict[str, str]:
    return {p.relative_to(root).as_posix(): sha(p) for p in Path(root).rglob("*") if p.is_file()}


def cmp(a: dict, b: dict) -> dict:
    return {"only_a": sorted(set(a) - set(b))[:10], "only_b": sorted(set(b) - set(a))[:10],
            "bytes_differ": sorted(k for k in set(a) & set(b) if a[k] != b[k])[:10], "equal": a == b}


def under_run(p: Path) -> Path:
    if not os.path.normcase(os.path.realpath(p)).startswith(os.path.normcase(str(RUN)) + os.sep):
        raise SystemExit(f"refusing: {p} outside {RUN}")
    return p


def outcome(fn, *a, **kw) -> dict:
    t0 = time.time()
    try:
        ret = fn(*a, **kw)
        return {"ok": True, "seconds": round(time.time() - t0, 1), "returned": ret}
    except Exception as exc:
        return {"ok": False, "seconds": round(time.time() - t0, 1), "error": f"{type(exc).__name__}: {exc}"[:800]}


def expected_exheader() -> bytes:
    _, base_ex, _ = exheader_diff.ncch_of(BASE_CIA)
    _, upd_ex, _ = exheader_diff.ncch_of(UPD_CIA)
    exp = bytearray(base_ex)
    for s, e in ((0x0E, 0x10), (0x18, 0x1C), (0x28, 0x2C)):
        exp[s:e] = upd_ex[s:e]
    exp[0x0D] &= 0xFE
    return bytes(exp)


def load() -> dict:
    return json.loads(RESULTS.read_text(encoding="utf-8")) if RESULTS.exists() else {"tag": TAG, "steps": {}}


def save(doc: dict) -> None:
    RESULTS.write_text(json.dumps(doc, ensure_ascii=False, indent=1, default=str), encoding="utf-8")


def step(doc: dict, key: str, title: str, fn) -> None:
    t0 = time.time()
    entry = {"title": title}
    try:
        entry.update(fn())
    except Exception as exc:
        entry["exception"] = f"{type(exc).__name__}: {exc}"
        entry["traceback"] = traceback.format_exc(limit=4)
    entry["seconds"] = round(time.time() - t0, 1)
    doc["steps"][key] = entry
    save(doc)
    print(f"[{key}] {title} ({entry['seconds']} s) {entry.get('exception', '')}"[:300], flush=True)


# ---------------------------------------------------------------- stage 1
def m1() -> dict:
    res = {}
    for name, cia in (("base", BASE_CIA), ("update", UPD_CIA)):
        ws = under_run(RUN / f"ws_{name}")
        res[name] = outcome(romforge.setup_workspace, cia, KEYS, ws, BRIDGE)
        if res[name]["ok"]:
            r = res[name].pop("returned")
            res[name].update(files=r["files"], title_id=r["project"]["title_id"],
                             components=sorted(p.name for p in ws.glob("original_*.bin")))
    wb, wu = RUN / "ws_base", RUN / "ws_update"
    _, base_ex, _ = exheader_diff.ncch_of(BASE_CIA)
    _, upd_ex, _ = exheader_diff.ncch_of(UPD_CIA)
    res["base_romfs_vs_romfs"] = cmp(dir_hashes(wb / "original"), dir_hashes(ROOT / "romfs"))
    res["update_romfs_vs_romf2"] = cmp(dir_hashes(wu / "original"), dir_hashes(ROOT / "romf2"))
    res["base_edited_equals_original"] = dir_hashes(wb / "edited") == dir_hashes(wb / "original")
    res["base_code_is_v10"] = sha(wb / "original_code.bin") == sha(V10CODE)
    res["update_code_is_v12"] = sha(wu / "original_code.bin") == sha(V12CODE)
    res["base_exheader_matches_cia"] = (wb / "original_exheader.bin").read_bytes() == base_ex
    res["update_exheader_matches_cia"] = (wu / "original_exheader.bin").read_bytes() == upd_ex
    res["base_banner_matches_exefs"] = sha(wb / "original_banner.bin") == sha(ROOT / "exefs" / "banner")
    res["update_has_banner"] = (wu / "original_banner.bin").exists()
    res["ok"] = all(res[k]["ok"] for k in ("base", "update")) and res["base_romfs_vs_romfs"]["equal"] and \
        res["update_romfs_vs_romf2"]["equal"] and res["base_code_is_v10"] and res["update_code_is_v12"] and \
        res["base_exheader_matches_cia"] and res["update_exheader_matches_cia"] and res["base_banner_matches_exefs"]
    return res


def bai_only_folder() -> Path:
    d = under_run(RUN / "patch_bai_only")
    (d / "BAI").mkdir(parents=True)
    shutil.copyfile(PATCH_ROMFS / "BAI" / "BAI.dat", d / "BAI" / "BAI.dat")
    return d


def m2() -> dict:
    res = {}
    variants = {"full": (PATCH_ROMFS, CODE_IPS, BANNER_KO), "ko": (PATCH_ROMFS, None, BANNER_KO),
                "fps60": (bai_only_folder(), CODE_IPS, None)}
    for name, (patch, ips, banner) in variants.items():
        out = under_run(RUN / f"bundle_{name}.zip")
        o = outcome(merge.build_bundle, RUN / "ws_base", RUN / "ws_update", patch, out, str(XDELTA), ips, banner)
        if o["ok"]:
            man = o.pop("returned")
            with zipfile.ZipFile(out) as z:
                names = z.namelist()
                z.extractall(RUN / f"bundle_{name}_x")
            o.update(bytes=out.stat().st_size, sha256=sha(out), romfs_changes=len(man["changes"]),
                     changed_paths=sorted(c["path"] for c in man["changes"]), components=sorted(man["components"]),
                     entries=len(names), includes_ips=man["includes_ips"],
                     root_entries=sorted(n for n in names if "/" not in n))
        res[name] = o
    # targets the code delta restores to
    x = RUN / "bundle_full_x" / "components" / "code.xdelta"
    if x.exists():
        import subprocess
        restored = RUN / "code_full_restored.bin"
        subprocess.run([str(XDELTA), "-d", "-s", str(RUN / "ws_base" / "original_code.bin"), str(x), str(restored)],
                       check=True, capture_output=True, timeout=120)
        res["full_code_equals_v3b_patched"] = sha(restored) == sha(V3B_CODE)
    res["ok"] = all(res[k]["ok"] for k in variants)
    return res


def m3() -> dict:
    ours, theirs = RUN / "bundle_full.zip", THEIR_BUNDLE

    def entries(p: Path) -> dict[str, str]:
        with zipfile.ZipFile(p) as z:
            return {i.filename: hashlib.sha256(z.read(i)).hexdigest() for i in z.infolist() if not i.is_dir()}

    a, b = entries(ours), entries(theirs)
    with zipfile.ZipFile(ours) as z1, zipfile.ZipFile(theirs) as z2:
        m1_, m2_ = json.loads(z1.read("manifest.json")), json.loads(z2.read("manifest.json"))
    return {"ours_entries": len(a), "theirs_entries": len(b), "entries": cmp(a, b),
            "manifest_equal": m1_ == m2_, "manifest_keys_differ": sorted(k for k in set(m1_) | set(m2_) if m1_.get(k) != m2_.get(k)),
            "ok": a == b}


# ---------------------------------------------------------------- stage 2
def m4() -> dict:
    res = {}
    for name in ("full", "ko"):
        out = under_run(RUN / f"merged_{name}.cci")
        o = outcome(merge.repack_bundle, RUN / f"bundle_{name}.zip", RUN / "ws_base", KEYS, out, "CCI", str(BRIDGE), str(XDELTA))
        if o["ok"]:
            r = o.pop("returned")
            o.update(sha256=r["sha256"], checked_files=r["checked_files"], code_checked=r["code_checked"],
                     bytes=out.stat().st_size)
        res[name] = o
    cia = under_run(RUN / "merged_full.cia")
    o = outcome(merge.repack_bundle, RUN / "bundle_full.zip", RUN / "ws_base", KEYS, cia, "CIA", str(BRIDGE), str(XDELTA))
    o.pop("returned", None)
    o["output_exists"] = cia.exists()
    res["cia_with_empty_keys"] = o
    res["ok"] = res["full"]["ok"] and res["ko"]["ok"]
    return res


def m5() -> dict:
    exp_ex = expected_exheader()
    base_icon = (ROOT / "exefs" / "icon").read_bytes()
    res = {}
    for name, code_ref in (("full", V3B_CODE), ("ko", V12CODE)):
        r = cci_verify.verify(RUN / f"merged_{name}.cci", DT / "ed_full")
        exd = r.pop("_exefs_data", {})
        exh = r.pop("_exheader", b"")
        r.pop("_tree", None)
        r["exheader_equals_expected_merge"] = exh == exp_ex
        r["exheader_diff_offsets"] = [hex(i) for i in range(min(len(exh), len(exp_ex))) if exh[i] != exp_ex[i]][:20]
        r["code_equals_expected"] = hashlib.sha256(exd.get(".code", b"")).hexdigest() == sha(code_ref)
        r["code_uncompressed_size"] = len(exd.get(".code", b""))
        r["banner_equals_korean"] = exd.get("banner") == BANNER_KO.read_bytes()
        r["icon_equals_base"] = exd.get("icon") == base_icon
        r["verdict"] = bool(r.get("ok")) and r["exheader_equals_expected_merge"] and r["code_equals_expected"] and \
            r["banner_equals_korean"] and r["icon_equals_base"]
        res[name] = r
    res["ok"] = all(res[k]["verdict"] for k in ("full", "ko"))
    return res


def main() -> None:
    stage = sys.argv[1] if len(sys.argv) > 1 else ""
    doc = load()
    doc.update(tag=TAG, run=str(RUN), bridge=str(BRIDGE), key_folder_empty=True)
    if stage == "stage1":
        if RUN.exists():
            raise SystemExit(f"{RUN} exists")
        KEYS.mkdir(parents=True)
        step(doc, "M1", "작업 폴더 준비: 본편·업데이트 CIA (빈 키 폴더)", m1)
        step(doc, "M2", "통합 패키지 만들기: 전체 / 한글만 / 60fps만", m2)
        step(doc, "M3", "만든 사람의 통합 패키지와 비교", m3)
    elif stage == "stage2":
        if any(KEYS.iterdir()):
            raise SystemExit("key folder must stay empty")
        step(doc, "M4", "통합 패키지 → CCI (전체, 한글만) + CIA 시도", m4)
        step(doc, "M5", "CCI 독립 검사 (해시·RomFS 전체·확장 헤더·코드·배너)", m5)
    else:
        raise SystemExit(__doc__)
    print(json.dumps({k: v.get("ok") for k, v in doc["steps"].items()}, ensure_ascii=False))


if __name__ == "__main__":
    main()
