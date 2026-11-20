"""D1X: pair every step-API call site of one game with the same call in the other game's twin function.

    python scripts/fps60/d1x_pairs.py [--from 3dx_v12] [--to 1dx_kr] [--min 0.25] [--api <substr>] [--all]

For each API in d1x_steps.APIS: classify every call site in --from; find the containing function's best
twin in --to (d1x_match, Jaccard >= --min); classify the call(s) to the same API inside the twin (k-th call
paired by order). Prints rows where the two classes differ (or all rows with --all), so "3DX passes CONST:1
where 1DX passes FPS/RET/MEM" stands out. Read-only.
"""
from __future__ import annotations

import os
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import armdis  # noqa: E402
import d1x_match as M  # noqa: E402
import d1x_steps as S  # noqa: E402


def main(argv: list[str]) -> None:
    src, dst, mn, api_f, show_all = "3dx_v12", "1dx_kr", 0.25, "", False
    it = iter(argv)
    for a in it:
        if a == "--from":
            src = next(it)
        elif a == "--to":
            dst = next(it)
        elif a == "--min":
            mn = float(next(it))
        elif a == "--api":
            api_f = next(it)
        elif a == "--all":
            show_all = True
    gi = {g: i for i, g in enumerate(S.GAMES)}
    fs_src, fs_dst = M.Funcs(src), M.Funcs(dst)
    idx = M.Index(fs_dst)
    print(f"# pairs {src} -> {dst}, min score {mn}")
    for api, addrs in S.APIS.items():
        if api_f and api_f not in api:
            continue
        a_src, a_dst = addrs[gi[src]], addrs[gi[dst]]
        dst_sites = S.api_sites(dst, a_dst)
        by_func: dict[int, list[int]] = {}
        for s in dst_sites:
            by_func.setdefault(fs_dst.fstart(s), []).append(s)
        src_sites = S.api_sites(src, a_src)
        src_by_func: dict[int, list[int]] = {}
        for s in src_sites:
            src_by_func.setdefault(fs_src.fstart(s), []).append(s)
        print(f"\n## {api}: {src} {len(src_sites)} sites, {dst} {len(dst_sites)} sites")
        for f, sites in sorted(src_by_func.items()):
            res = idx.query(fs_src.shingles(f), 1)
            twin = res[0] if res and res[0][0] >= mn else None
            tw_sites = by_func.get(twin[1], []) if twin else []
            for k, s in enumerate(sites):
                c1 = S.classify(src, s)
                if twin and k < len(tw_sites):
                    c2 = S.classify(dst, tw_sites[k])
                    t = f"{tw_sites[k]:#010x} {c2}"
                elif twin:
                    c2 = "-"
                    t = f"(twin {twin[1]:#x} has no call #{k})"
                else:
                    c2 = "-"
                    t = "(no twin)"
                if show_all or (twin and c1 != c2):
                    sc = f"{twin[0]:.2f}" if twin else "    "
                    print(f"{s:#010x} {c1:28s} | {sc} {t:48s} | {armdis.where(src, s)}")


if __name__ == "__main__":
    main(sys.argv[1:])
