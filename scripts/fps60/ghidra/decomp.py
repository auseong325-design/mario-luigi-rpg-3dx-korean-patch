"""Decompile functions of 3dx_v12 / 1dx_kr with Ghidra (fps60 workstream TG).

    python scripts/fps60/ghidra/decomp.py <game> <addr|name> [<addr|name> ...] [options]

    python scripts/fps60/ghidra/decomp.py 3dx_v12 0x25edd0                 # function containing the address
    python scripts/fps60/ghidra/decomp.py 3dx_v12 isFps30 --xrefs          # name / substring / mangled name
    python scripts/fps60/ghidra/decomp.py 3dx_v12 ad::fw::TaskBase::funcInit --asm
    python scripts/fps60/ghidra/decomp.py 3dx_v12 0x25edd0 --cached        # instant: print from the dumps
    python scripts/fps60/ghidra/decomp.py 3dx_v12 --find TaskBase          # list matching functions (index)

Options: --asm (append disassembly), --xrefs (callers + data refs, incl. via CRO veneers),
         --cached (no Ghidra; read work/fps60/decomp/<game>/), --find (list only),
         --timeout S (whole Ghidra run, default 900), --func-timeout S (per function, default 180),
         --max-match N (substring hits decompiled at most, default 8).

Fresh mode is read-only and lock-free for callers: it runs analyzeHeadless -readOnly on a private
snapshot copy of the project (pool of slots in %TEMP%\\fps60_ghidra_snap, one caller per slot, re-copied
when the master project changes), so any number of agents can call it at once. Typical cost: 30-60 s
(JVM + project open); batch several targets in one call. CRO addresses are analysis addresses
(work/fps60/link/<game>/link.json), not runtime addresses.
"""
from __future__ import annotations

import argparse
import bisect
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import ghidra_run  # noqa: E402

ROOT = ghidra_run.ROOT


# ------------------------------------------------------------------ index (dumps)
class Index:
    def __init__(self, game: str):
        self.dir = os.path.join(ROOT, "work", "fps60", "decomp", game)
        self.rows: list[dict] = []
        p = os.path.join(self.dir, "functions.tsv")
        if os.path.exists(p):
            with open(p, encoding="utf-8") as f:
                cols = f.readline().rstrip("\n").split("\t")
                for line in f:
                    v = line.rstrip("\n").split("\t")
                    if len(v) == len(cols):
                        d = dict(zip(cols, v))
                        d["a"], d["e"] = int(d["addr"], 16), int(d["end"], 16)
                        self.rows.append(d)
        self.rows.sort(key=lambda d: d["a"])
        self.starts = [d["a"] for d in self.rows]

    def by_addr(self, a: int) -> dict | None:
        i = bisect.bisect_right(self.starts, a) - 1
        if i >= 0 and self.rows[i]["a"] <= a < max(self.rows[i]["e"], self.rows[i]["a"] + 1):
            return self.rows[i]
        return None

    def by_name(self, q: str) -> list[dict]:
        exact = [d for d in self.rows if q in (d["name"], d["symbol"], d["name"].lstrip("->"))]
        if exact:
            return exact
        ql = q.lower()
        return [d for d in self.rows if ql in d["name"].lower() or ql in d["symbol"].lower()]

    def text(self, d: dict) -> str:
        path = os.path.join(self.dir, d["file"])
        out = []
        with open(path, encoding="utf-8") as f:
            for i, line in enumerate(f, 1):
                if i < int(d["line"]):
                    continue
                if i > int(d["line"]) and line.startswith("// FUNC 0x"):
                    break
                out.append(line)
        return "".join(out).rstrip() + "\n"


def is_addr(t: str) -> bool:
    return re.fullmatch(r"(?i)0x[0-9a-f]+|\d+", t) is not None


# ------------------------------------------------------------------ main
def fresh(game: str, targets: list[str], flags: list[str], timeout: int) -> str:
    with ghidra_run.Slot(game) as slot:
        out = os.path.join(slot.dir, f"out_{os.getpid()}.c")
        req = os.path.join(slot.dir, f"req_{os.getpid()}.txt")
        logb = os.path.join(slot.dir, f"run_{os.getpid()}")
        with open(req, "w", encoding="utf-8", newline="\n") as f:
            f.write(" ".join(flags) + "\n" + "\n".join(targets) + "\n")
        argv = [slot.dir, game, "-process", ghidra_run.program_name(game), "-noanalysis", "-readOnly",
                "-scriptPath", HERE, "-postScript", "DecompFuncs.java", req, out]
        rc = ghidra_run.run_headless(argv, logb, timeout, maxmem="3G", quiet=True)
        if not os.path.exists(out):
            tail = ""
            if os.path.exists(logb + ".out"):
                tail = "".join(open(logb + ".out", encoding="utf-8", errors="replace").readlines()[-25:])
            raise SystemExit(f"[decomp] Ghidra run failed (rc={rc}); log {logb}.out\n{tail}")
        text = open(out, encoding="utf-8").read()
        for p in (out, req, logb + ".out", logb + ".err"):
            try:
                os.remove(p)
            except OSError:
                pass
        return text


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("game", choices=ghidra_run.GAMES)
    ap.add_argument("targets", nargs="+")
    ap.add_argument("--asm", action="store_true")
    ap.add_argument("--xrefs", action="store_true")
    ap.add_argument("--cached", action="store_true")
    ap.add_argument("--find", action="store_true")
    ap.add_argument("--timeout", type=int, default=900)
    ap.add_argument("--func-timeout", type=int, default=180)
    ap.add_argument("--max-match", type=int, default=8)
    a = ap.parse_args()
    if hasattr(sys.stdout, "reconfigure"):
        sys.stdout.reconfigure(encoding="utf-8", errors="replace")
    idx = Index(a.game)

    if a.find or a.cached:
        if not idx.rows:
            raise SystemExit("no dump index yet (work/fps60/decomp/<game>/functions.tsv); run without --cached")
        for t in a.targets:
            hits = [idx.by_addr(int(t, 0))] if is_addr(t) else idx.by_name(t)
            hits = [h for h in hits if h]
            if not hits:
                print(f"// {t}: not found in the dump index")
                continue
            if a.find or len(hits) > a.max_match:
                if not a.find:
                    print(f"// {t}: {len(hits)} matches; refine or use an address")
                for h in hits[:200]:
                    print(f"{h['addr']}  {h['module']:14s} {h['name']}  [{h['file']}:{h['line']}] {h['status']}")
                continue
            for h in hits:
                print(idx.text(h))
        return

    # resolve names with the index first (fast, precise); unresolved names go to Ghidra as-is
    targets: list[str] = []
    for t in a.targets:
        if is_addr(t) or not idx.rows:
            targets.append(t)
            continue
        hits = idx.by_name(t)
        if 0 < len(hits) <= a.max_match:
            targets += [h["addr"] for h in hits]
        elif len(hits) > a.max_match:
            print(f"// {t}: {len(hits)} matches in the index; refine the name or use an address:")
            for h in hits[:60]:
                print(f"//   {h['addr']} {h['name']} ({h['module']})")
        else:
            targets.append(t)
    if not targets:
        return
    flags = [f for f, on in (("asm", a.asm), ("xrefs", a.xrefs)) if on]
    flags += [f"timeout={a.func_timeout}", f"maxmatch={a.max_match}"]
    sys.stdout.write(fresh(a.game, targets, flags, a.timeout))


if __name__ == "__main__":
    main()
