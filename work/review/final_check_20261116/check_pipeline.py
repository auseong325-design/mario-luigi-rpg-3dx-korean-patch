"""Read-only check that nothing translated is left uninstalled (2026-10-30 review).

1. Every batch in work/batches/_index.json has a text/ko file and passes merge_ko's checks.
2. Merging text/ko in memory (same steps as merge_ko --merge, nothing written) gives exactly
   work/ko_final.json.
3. Building the 7 message files from work/ko_final.json in memory (build_patch.build_all) gives
   exactly the files installed in patch/00040000001CA900/romfs/Msg/JP_ja.
Writes check_pipeline.json next to this script.
"""

from __future__ import annotations

import contextlib
import io
import json
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
sys.path.insert(0, str(ROOT / "scripts"))

import build_patch  # noqa: E402
import merge_ko as M  # noqa: E402


def merged_in_memory() -> tuple[dict[str, str], dict]:
    final: dict[str, str] = {}
    rep = {"batches": 0, "missing": [], "failed": {}, "warnings": 0}
    for bid in M.all_batches():
        rep["batches"] += 1
        if not (M.KO / f"{bid}.json").exists():
            rep["missing"].append(bid)
            continue
        with contextlib.redirect_stdout(io.StringIO()):
            res = M.check_batch(bid, verbose=False)
        rep["warnings"] += len(res.get("warnings", []))
        if res["errors"]:
            rep["failed"][bid] = res["errors"][:10]
            continue
        batch, ko = M.load_batch(bid)
        for m in batch["messages"]:
            text_ko = ko["translations"][m["id"]]
            final[m["id"]] = M.restore(m, text_ko)
            for d in m.get("dups", []):
                final[d] = M.restore_copy(d, m, text_ko)
    overrides, errors = M.load_dup_overrides()
    final.update(overrides)
    rep["dup_override_errors"] = errors
    return final, rep


def main() -> int:
    out: dict = {}
    final, rep = merged_in_memory()
    out["merge"] = rep
    disk = json.loads(M.FINAL.read_text(encoding="utf-8"))
    out["ko_final"] = {"in_memory": len(final), "on_disk": len(disk),
                       "differs": sorted(k for k in set(final) | set(disk) if final.get(k) != disk.get(k))[:50]}
    with contextlib.redirect_stdout(io.StringIO()):
        built, _intended, used = build_patch.build_all(disk)
    inst = {}
    for rel, data in built.items():
        p = build_patch.PATCH_ROMFS / rel
        inst[rel] = "same" if p.exists() and p.read_bytes() == data else "DIFFERENT" if p.exists() else "missing"
    out["installed_vs_build_from_ko_final"] = inst
    out["ko_final_ids_applied"] = [len(used), len(disk)]
    (HERE / "check_pipeline.json").write_text(json.dumps(out, ensure_ascii=False, indent=1), encoding="utf-8")
    print(json.dumps({"batches": rep["batches"], "missing": len(rep["missing"]), "failed": len(rep["failed"]),
                      "warnings": rep["warnings"], "dup_override_errors": len(rep["dup_override_errors"]),
                      "ko_final_diffs": len(out["ko_final"]["differs"]), "installed": inst,
                      "applied": out["ko_final_ids_applied"]}, ensure_ascii=False))
    return 0


if __name__ == "__main__":
    sys.exit(main())
