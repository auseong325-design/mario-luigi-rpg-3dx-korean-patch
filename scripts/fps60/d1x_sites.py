"""D1X2: one row per isFps30() call site of a game, with enclosing function, class guess and consumer.

    python scripts/fps60/d1x_sites.py <game> [--tsv out.tsv]

Sources: armdis.callers (branch / via-veneer sites), work/fps60/decomp/<game>/functions.tsv (function ranges and
names) and the C dumps (text after the isFps30() line). Columns:
  site, module, func, func_name, unit, consumer, snippet
unit     = class of the function name; for unnamed FUN_/? functions the class of the nearest named neighbours
           in the same module (prev|next when they differ) -- translation units are contiguous, so this
           is a good guess for menu/page code.
consumer = first callee named in the 14 dump lines after the isFps30() line (what the 2.0/1.0 feeds), or
           'store:+0x..' when the selected value is stored to a field first. Heuristic: verify by reading.
Read-only.
"""
from __future__ import annotations

import bisect
import csv
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import armdis  # noqa: E402

ROOT = os.path.abspath(os.path.join(HERE, "..", ".."))
FPS30 = {"1dx_kr": 0x2AE220, "3dx_v12": 0x25EDD0}
CALL_RE = re.compile(r"([A-Za-z_][\w:~<>]*(?:::[\w~<>]+)*)\s*\(")
SKIP_CALLEES = {"if", "while", "for", "switch", "return", "sizeof", "isFps30", "ad::fw::TaskBase::isFps30",
                "float", "int", "uint", "char", "bool", "code", "undefined4", "TaskBase", "MComSys", "Main",
                "GetMain", "TransCrossBtnBit", "Main::getBtnCnt", "Main::getBtnTrg"}


def unit_of(name: str) -> str:
    if name.startswith("->"):
        name = name[2:]
    if "::" not in name:
        return ""
    n = re.sub(r"::vfunc_0x[0-9a-f]+$", "", name)
    if n == name:
        n = name.rsplit("::", 1)[0]
    return n


def load_funcs(game: str):
    rows = []
    with open(os.path.join(ROOT, "work", "fps60", "decomp", game, "functions.tsv"), encoding="utf-8") as f:
        for r in csv.DictReader(f, delimiter="\t"):
            rows.append((int(r["addr"], 16), int(r["end"], 16), r["module"], r["name"], r["file"], int(r["line"] or 0)))
    rows.sort()
    return rows


def main(argv: list[str]) -> None:
    game = argv[0]
    out = None
    if "--tsv" in argv:
        out = argv[argv.index("--tsv") + 1]
    funcs = load_funcs(game)
    starts = [r[0] for r in funcs]
    files: dict[str, list[str]] = {}

    def text(fn: str) -> list[str]:
        if fn not in files:
            with open(os.path.join(ROOT, "work", "fps60", "decomp", game, fn), encoding="utf-8", errors="replace") as f:
                files[fn] = f.readlines()
        return files[fn]

    def find(addr: int):
        i = bisect.bisect_right(starts, addr) - 1
        while i >= 0:
            r = funcs[i]
            if r[0] <= addr < r[1] and not r[3].startswith("->"):
                return i
            if addr - r[0] > 0x8000:
                break
            i -= 1
        return None

    def neighbour_unit(i: int, step: int) -> str:
        mod = funcs[i][2]
        j = i + step
        while 0 <= j < len(funcs) and funcs[j][2] == mod:
            u = unit_of(funcs[j][3])
            if u and not funcs[j][3].startswith("->"):
                return u
            j += step
        return ""

    sites = [a for a, kind in armdis.callers(game, FPS30[game]) if kind != "literal"]
    rows_out = []
    seen_line: dict[tuple, int] = {}
    for s in sites:
        i = find(s)
        if i is None:
            rows_out.append((f"{s:#x}", "?", "?", "?", "?", "?", ""))
            continue
        a, e, mod, name, fn, line = funcs[i]
        u = unit_of(name)
        if not u:
            p, n = neighbour_unit(i, -1), neighbour_unit(i, +1)
            u = p if p == n else f"{p}|{n}"
            u = "~" + u
        consumer, snip = "?", ""
        if fn and line:
            lines = text(fn)
            k = line - 1
            # k-th isFps30 occurrence inside this function, in site order
            key = (a,)
            occ = seen_line.get(key, 0)
            seen_line[key] = occ + 1
            hits = []
            j = k + 1
            while j < len(lines) and not lines[j].startswith("// FUNC"):
                if "isFps30(" in lines[j] and not lines[j].lstrip().startswith("//"):
                    hits.append(j)
                j += 1
            if hits:
                h = hits[min(occ, len(hits) - 1)]
                snip = lines[h].strip()
                for t in range(h + 1, min(h + 15, len(lines))):
                    ln = lines[t]
                    m = re.search(r"\*\(\w+ \*\)\((?:param_1|this|\w+) \+ (0x[0-9a-f]+)\) =\s*(?:fVar|uVar)", ln)
                    if m:
                        consumer = f"store:+{m.group(1)}"
                        break
                    found = None
                    for cm in CALL_RE.finditer(ln):
                        nm = cm.group(1)
                        if nm in SKIP_CALLEES or nm.split("::")[-1] in SKIP_CALLEES:
                            continue
                        if re.fullmatch(r"(?:FUN|LAB|DAT)_[0-9a-f]+|[A-Za-z_][\w:]*", nm):
                            found = nm
                            break
                    if found:
                        consumer = found
                        break
        rows_out.append((f"{s:#x}", mod, f"{a:#x}", name, u, consumer, snip[:90]))
    if out:
        with open(out, "w", encoding="utf-8", newline="") as f:
            w = csv.writer(f, delimiter="\t")
            w.writerow(["site", "module", "func", "func_name", "unit", "consumer", "snippet"])
            w.writerows(rows_out)
    for r in rows_out:
        print("\t".join(r))


if __name__ == "__main__":
    main(sys.argv[1:])
