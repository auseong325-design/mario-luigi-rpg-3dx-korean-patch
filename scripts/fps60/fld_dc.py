"""FLD workstream helper: read the Ghidra C dumps of 3dx_v12 by function (read-only).

    python scripts/fps60/fld_dc.py show <addr|name> [...]          # print function bodies from the dump
    python scripts/fps60/fld_dc.py callees <addr|name> [...]       # direct callees (name -> addr)
    python scripts/fps60/fld_dc.py tree <addr|name> [depth] [--max N] [--skip REGEX]   # call tree (BFS, unique)
    python scripts/fps60/fld_dc.py grep <regex> [--names REGEX] [--ctx N]   # regex over bodies, per function
    python scripts/fps60/fld_dc.py find <regex>                    # list functions whose name matches
    python scripts/fps60/fld_dc.py callers <addr|name>             # callers from functions.tsv

Addresses are analysis addresses (static = runtime). Output goes to stdout (redirect to a file).
"""
from __future__ import annotations

import bisect
import os
import re
import sys
from collections import deque

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", ".."))
GAME = "3dx_v12"
DDIR = os.path.join(ROOT, "work", "fps60", "decomp", GAME)


class DC:
    def __init__(self):
        self.rows = []
        with open(os.path.join(DDIR, "functions.tsv"), encoding="utf-8") as f:
            cols = f.readline().rstrip("\n").split("\t")
            for line in f:
                v = line.rstrip("\n").split("\t")
                if len(v) == len(cols):
                    d = dict(zip(cols, v))
                    d["a"] = int(d["addr"], 16)
                    d["e"] = int(d["end"], 16)
                    self.rows.append(d)
        self.rows.sort(key=lambda d: d["a"])
        self.starts = [d["a"] for d in self.rows]
        self.by_name = {}
        for d in self.rows:
            self.by_name.setdefault(d["name"], []).append(d)
        self._bodies = {}
        self._files = {}

    def row(self, a):
        i = bisect.bisect_right(self.starts, a) - 1
        if i >= 0 and self.rows[i]["a"] <= a < max(self.rows[i]["e"], self.rows[i]["a"] + 1):
            return self.rows[i]
        return None

    def resolve(self, t):
        if re.fullmatch(r"(0x)?[0-9a-fA-F]{6,8}", t):
            r = self.row(int(t, 16))
            return [r] if r else []
        if t in self.by_name:
            return self.by_name[t]
        return [d for d in self.rows if t in d["name"]][:40]

    def _load(self, fname):
        if fname in self._files:
            return
        path = os.path.join(DDIR, fname)
        bodies = {}
        cur = None
        buf = []
        with open(path, encoding="utf-8", errors="replace") as f:
            for line in f:
                if line.startswith("// FUNC 0x"):
                    if cur is not None:
                        bodies[cur] = "".join(buf)
                    cur = int(line.split()[2], 16)
                    buf = [line]
                elif cur is not None:
                    buf.append(line)
        if cur is not None:
            bodies[cur] = "".join(buf)
        self._files[fname] = bodies

    def body(self, d):
        fname = d["file"]
        self._load(fname)
        return self._files[fname].get(d["a"], "")

    CALL_RX = re.compile(r"\b(FUN_([0-9a-f]{8})|thunk_FUN_([0-9a-f]{8})|([A-Za-z_][\w:~<>]*(?:::[\w~<>]+)+))\s*\(")

    def callees(self, d):
        out = []
        seen = set()
        for m in self.CALL_RX.finditer(self.body(d)):
            if m.group(2) or m.group(3):
                a = int(m.group(2) or m.group(3), 16)
                r = self.row(a)
            else:
                nm = m.group(4)
                rs = self.by_name.get(nm)
                r = rs[0] if rs else None
            if r and r["a"] != d["a"] and r["a"] not in seen:
                seen.add(r["a"])
                out.append(r)
        return out


def fmt(d):
    return f"{d['a']:#010x} {d['module']:10s} {d['name']}"


def main(argv):
    if not argv:
        print(__doc__)
        return
    dc = DC()
    cmd, args = argv[0], argv[1:]
    if cmd == "show":
        for t in args:
            for d in dc.resolve(t):
                print(dc.body(d))
    elif cmd == "callees":
        for t in args:
            for d in dc.resolve(t):
                print("#", fmt(d))
                for r in dc.callees(d):
                    print("   ", fmt(r))
    elif cmd == "tree":
        t = args[0]
        depth = int(args[1]) if len(args) > 1 and args[1].isdigit() else 3
        mx = int(args[args.index("--max") + 1]) if "--max" in args else 400
        skip = re.compile(args[args.index("--skip") + 1]) if "--skip" in args else None
        for d0 in dc.resolve(t)[:1]:
            q = deque([(d0, 0, None)])
            seen = {d0["a"]}
            n = 0
            while q and n < mx:
                d, k, par = q.popleft()
                n += 1
                print(f"{'  ' * k}{fmt(d)}" + (f"   <- {par:#x}" if par else ""))
                if k >= depth:
                    continue
                for r in dc.callees(d):
                    if r["a"] in seen:
                        continue
                    if skip and skip.search(r["name"]):
                        continue
                    seen.add(r["a"])
                    q.append((r, k + 1, d["a"]))
    elif cmd == "grep":
        rx = re.compile(args[0])
        nrx = re.compile(args[args.index("--names") + 1]) if "--names" in args else None
        ctx = int(args[args.index("--ctx") + 1]) if "--ctx" in args else 0
        mods = args[args.index("--mod") + 1].split(",") if "--mod" in args else None
        for d in dc.rows:
            if mods and d["module"] not in mods:
                continue
            if nrx and not nrx.search(d["name"]):
                continue
            b = dc.body(d)
            if not b:
                continue
            lines = b.splitlines()
            hits = [i for i, ln in enumerate(lines) if rx.search(ln)]
            if hits:
                print("#", fmt(d))
                shown = set()
                for i in hits:
                    for j in range(max(0, i - ctx), min(len(lines), i + ctx + 1)):
                        if j not in shown:
                            shown.add(j)
                            print(f"   {j:4d}: {lines[j]}")
    elif cmd == "find":
        rx = re.compile(args[0])
        for d in dc.rows:
            if rx.search(d["name"]):
                print(fmt(d), d["size"], "callers", d.get("callers", ""))
    elif cmd == "callers":
        for t in args:
            for d in dc.resolve(t):
                print("#", fmt(d))
                b = dc.body(d)
                m = re.search(r"callers\(\d+\):?([^|\n]*)", b)
                for c in (m.group(1).split() if m else []):
                    if c.startswith("0x"):
                        r = dc.row(int(c, 16))
                        print("   ", c, fmt(r) if r else "?")
    else:
        print(__doc__)


if __name__ == "__main__":
    main(sys.argv[1:])
