"""CRS worker helper: list the static module's (static.crs) named imports with relocation sites.

Static code reaches CRO exports through words that the RO service patches when the CRO loads.
This prints each import name with the absolute static address of every patched word, so the
static caller can be disassembled with armdis.py.

    python scripts/fps60/crs_imports.py [substring] [--game 3dx_v12|1dx_kr]
"""
from __future__ import annotations

import os
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(os.path.dirname(HERE))
sys.path.insert(0, HERE)
from cro import CRO  # noqa: E402

CRS = {"3dx_v12": "romf2/RO/static.crs", "3dx_v10": "romfs/RO/static.crs", "1dx_kr": "ml 1dx/3romfs/RO/static.crs"}
TYPES = {2: "ABS32", 3: "REL32", 38: "TARGET1", 28: "CALL", 29: "JUMP24"}


def main(argv: list[str]) -> None:
    game = "3dx_v12"
    if "--game" in argv:
        i = argv.index("--game")
        game = argv[i + 1]
        argv = argv[:i] + argv[i + 2:]
    sub = argv[0].lower() if argv else ""
    crs = CRO.load(os.path.join(ROOT, CRS[game]))
    for imp in crs.named_imports():
        if sub and sub not in imp.name.lower():
            continue
        sites = []
        for r in imp.relocs:
            seg = crs.segments[r.seg]
            sites.append(f"{seg.offset + r.off:#010x}({seg.name},{TYPES.get(r.type, r.type)},+{r.addend:#x})")
        print(f"{imp.name}: {' '.join(sites)}")


if __name__ == "__main__":
    main(sys.argv[1:])
