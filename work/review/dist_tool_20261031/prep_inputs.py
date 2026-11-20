"""Build the scratch input trees for the universal-tool review (work/review/dist_tool_20261031).

Writes ONLY under %KIROCREW_SCRATCH%/dt (asserted). Reads romfs/, romf2/ and patch/00040000001CA900/romfs.
Unchanged files in the edited trees are NTFS hard links to the scratch copy v10/ (never to the original game
folders), so the trees cost one RomFS of disk space. The tool under test only reads its input folders.

  v10/          real copy of romfs/ (v1.0 base RomFS, 1,282 files)
  v12/          v10 + romf2/ (19 real copies) = v1.2 RomFS (romf2 over romfs, as lib3dx.romfs_path())
  ed_full/      v12 + all 37 patch romfs files (real copies)          -> Korean + 60fps
  ed_ko/        v12 + 36 patch files (all but BAI/BAI.dat)            -> Korean only
  ed_60/        v12 + BAI/BAI.dat only                                -> 60fps only
  ed_full_v10/  v10 + all 37 patch files                              -> same patch files, v1.0 originals as the base
  patch_only/   copy of patch/00040000001CA900/romfs only             -> user mistake: edited = the patch folder

  python prep_inputs.py [--force]   (--force rebuilds an existing dt/ tree after checking it is under scratch)
"""
from __future__ import annotations

import argparse
import hashlib
import json
import os
import shutil
import stat
import sys
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
TID = "00040000001CA900"
ROMFS = ROOT / "romfs"
ROMF2 = ROOT / "romf2"
PATCH_ROMFS = ROOT / "patch" / TID / "romfs"
SCRATCH = Path(os.environ["KIROCREW_SCRATCH"]).resolve()
DT = SCRATCH / "dt"


def sha256(p: Path) -> str:
    h = hashlib.sha256()
    with p.open("rb") as f:
        for chunk in iter(lambda: f.read(1 << 20), b""):
            h.update(chunk)
    return h.hexdigest()


def tree(root: Path) -> dict[str, Path]:
    return {p.relative_to(root).as_posix(): p for p in root.rglob("*") if p.is_file()}


def inside_scratch(p: Path) -> bool:
    r = os.path.normcase(os.path.realpath(p))
    return r.startswith(os.path.normcase(str(SCRATCH)) + os.sep)


def no_reparse(p: Path) -> None:
    for dirpath, dirnames, filenames in os.walk(p, followlinks=False):
        for n in dirnames + filenames:
            q = Path(dirpath) / n
            if getattr(os.lstat(q), "st_file_attributes", 0) & stat.FILE_ATTRIBUTE_REPARSE_POINT:
                raise SystemExit(f"refusing: reparse point {q}")


def link_tree(src_files: dict[str, Path], dst: Path, overlay: dict[str, Path]) -> dict:
    """dst = hard links to src_files, then real copies of overlay (rel -> source file)."""
    if not inside_scratch(dst):
        raise SystemExit(f"refusing: {dst} is outside scratch")
    dst.mkdir(parents=True)
    n_link = n_copy = 0
    for rel, src in src_files.items():
        if not inside_scratch(src):
            raise SystemExit(f"refusing to hard-link to {src} (outside scratch)")
        out = dst / rel
        out.parent.mkdir(parents=True, exist_ok=True)
        if rel in overlay:
            continue
        os.link(src, out)
        n_link += 1
    for rel, src in overlay.items():
        out = dst / rel
        out.parent.mkdir(parents=True, exist_ok=True)
        shutil.copyfile(src, out)
        if sha256(out) != sha256(src):
            raise SystemExit(f"copy check failed: {rel}")
        n_copy += 1
    return {"links": n_link, "copies": n_copy, "files": len(tree(dst))}


def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("--force", action="store_true")
    a = ap.parse_args()
    if not inside_scratch(DT):
        raise SystemExit("dt is not under scratch")
    if DT.exists():
        if not a.force:
            raise SystemExit(f"{DT} exists (use --force)")
        no_reparse(DT)
        shutil.rmtree(DT)
    t0 = time.time()
    DT.mkdir(parents=True)
    report: dict = {"dt": str(DT)}

    base = tree(ROMFS)
    upd = tree(ROMF2)
    patch = tree(PATCH_ROMFS)
    missing = sorted(set(upd) - set(base)) + sorted(set(patch) - set(base))
    if missing:
        raise SystemExit(f"paths not in the base RomFS: {missing}")

    # v10: real copy of the base RomFS, verified by size + sha256
    v10 = DT / "v10"
    for rel, src in base.items():
        out = v10 / rel
        out.parent.mkdir(parents=True, exist_ok=True)
        shutil.copyfile(src, out)
    bad = [rel for rel, src in base.items() if (v10 / rel).stat().st_size != src.stat().st_size
           or sha256(v10 / rel) != sha256(src)]
    if bad:
        raise SystemExit(f"v10 copy differs: {bad[:5]}")
    v10_files = tree(v10)
    report["v10"] = {"files": len(v10_files), "bytes": sum(p.stat().st_size for p in v10_files.values())}

    # v12 = v10 + romf2 (real copies)
    v12 = DT / "v12"
    report["v12"] = link_tree(v10_files, v12, upd)
    v12_files = tree(v12)

    no_bai = {k: v for k, v in patch.items() if k != "BAI/BAI.dat"}
    report["ed_full"] = link_tree(v12_files, DT / "ed_full", patch)
    report["ed_ko"] = link_tree(v12_files, DT / "ed_ko", no_bai)
    report["ed_60"] = link_tree(v12_files, DT / "ed_60", {"BAI/BAI.dat": patch["BAI/BAI.dat"]})
    report["ed_full_v10"] = link_tree(v10_files, DT / "ed_full_v10", patch)
    shutil.copytree(PATCH_ROMFS, DT / "patch_only")
    report["patch_only"] = {"files": len(tree(DT / "patch_only"))}

    # which of the 37 patch paths have a v1.2 original that differs from v1.0
    report["patch_paths"] = len(patch)
    report["patch_paths_from_update"] = sorted(rel for rel in patch if rel in upd)
    report["update_differs_from_base"] = sorted(rel for rel in upd if sha256(ROMF2 / rel) != sha256(ROMFS / rel))
    report["seconds"] = round(time.time() - t0, 1)
    (DT / "prep_report.json").write_text(json.dumps(report, indent=1), encoding="utf-8")
    print(json.dumps(report, indent=1))


if __name__ == "__main__":
    main()
