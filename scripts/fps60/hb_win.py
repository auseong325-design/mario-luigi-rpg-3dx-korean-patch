"""HB helper: print disassembly windows around a list of addresses (uses the lead's armdis.py read-only).

    python scripts/fps60/hb_win.py <before> <after> addr [addr ...]
    python scripts/fps60/hb_win.py 8 24 0x12814260 0x12814430

Each window starts `before` instructions earlier and prints before+after+1 ARM instructions, with the
nearest-symbol header from armdis.where(). Owned by worker HB.
"""
from __future__ import annotations

import os
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import armdis  # noqa: E402


def main(argv: list[str]) -> None:
    if len(argv) < 3:
        print(__doc__)
        return
    before, after = int(argv[0]), int(argv[1])
    for tok in argv[2:]:
        a = int(tok, 0) & ~3
        start = a - 4 * before
        print(f"===== {a:#010x}  ({armdis.where('3dx_v12', a)})")
        for line in armdis.disasm("3dx_v12", start, before + after + 1):
            mark = ">>" if line.split(":")[0].strip().endswith(f"{a:08x}") else "  "
            print(mark + line)


if __name__ == "__main__":
    main(sys.argv[1:])
