"""D1X2: split constant-step calls of step APIs into 'settle after stop' and 'per-frame' candidates.

    python scripts/fps60/d1x_settle.py <steps_list.txt> [--game 3dx_v12|1dx_kr]

Input = output of `d1x_steps.py compare --list` (lines `<game> <site> <api> <class> <where>`). For every CONST:<v>
row of the step-update APIs (Frm::update, MoveVBase/MoveFBase/MoveC::update, CellAnime::update, LytAnim::update,
SndSeCtrl::update, fld::CircleMove::update) it scans the 8 instructions before the site for a `bl` to a
`*::stop` / `*::moveFrm*` / `*::set*` / `*::play*` symbol of the same object family. Such a call followed by one
update(1.0) is the engine's "stop/start then apply once" idiom (a one-shot settle, not a per-frame step).
Rows without it are printed as PER-FRAME candidates (verify by reading the caller). Read-only.
"""
from __future__ import annotations

import os
import re
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import armdis  # noqa: E402

UPDATE_APIS = ("Frm::update", "MoveVBase::update", "MoveFBase::update", "MoveC::update", "CellAnime::update",
               "ad::lyt::LytAnim::update", "SndSeCtrl::update", "fld::CircleMove::update")
SETTLE_RE = re.compile(r"(stop|moveFrm|moveSin|moveCos|jump|set|play|wait|init|start)", re.I)


def callee(g, a: int) -> str | None:
    b = g.read(a, 4)
    if len(b) < 4:
        return None
    w = struct.unpack("<I", b)[0]
    if (w >> 24) & 0x0F != 0x0B or (w >> 28) == 0xF:
        return None
    t = armdis.branch_target(w, a)
    if t is None:
        return None
    nm = g.a2s.get(t & ~1)
    return armdis.demangle_hint(nm) if nm else f"sub_{t:x}"


def main(argv: list[str]) -> None:
    path = argv[0]
    only = None
    if "--game" in argv:
        only = argv[argv.index("--game") + 1]
    stats: dict[tuple, list[int]] = {}
    rows = []
    for ln in open(path, encoding="utf-8"):
        m = re.match(r"(\S+) (0x[0-9a-f]+) (\S+?)\(f\)\s+(CONST:\S+)", ln)
        if not m:
            continue
        game, site, api, cls = m.group(1), int(m.group(2), 16), m.group(3), m.group(4)
        if only and game != only:
            continue
        if api not in UPDATE_APIS:
            continue
        g = armdis.game(game)
        prev = []
        for k in range(1, 9):
            c = callee(g, site - 4 * k)
            if c:
                prev.append(c)
        settle = next((c for c in prev if SETTLE_RE.search(c.split("::")[-1]) and "update" not in c), None)
        kind = "SETTLE" if settle else "PER-FRAME?"
        stats.setdefault((game, api, kind), []).append(site)
        rows.append((game, site, api, cls, kind, settle or (prev[0] if prev else "-"), armdis.where(game, site)))
    for r in rows:
        if r[4] != "SETTLE":
            print(f"{r[0]} {r[1]:#010x} {r[2]:26s} {r[3]:9s} {r[4]:10s} prev={r[5]:40s} {r[6]}")
    print()
    print("| game | API | settle-after-stop/set | per-frame candidates |")
    print("|---|---|---|---|")
    keys = sorted({(k[0], k[1]) for k in stats})
    for game, api in keys:
        s = len(stats.get((game, api, "SETTLE"), []))
        p = len(stats.get((game, api, "PER-FRAME?"), []))
        print(f"| {game} | {api} | {s} | {p} |")


if __name__ == "__main__":
    main(sys.argv[1:])
