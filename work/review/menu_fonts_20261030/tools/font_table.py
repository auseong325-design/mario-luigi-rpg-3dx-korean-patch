"""Read the game's font file table (code 0x3F41A4, used by FUN_0010579c -> MessageDrawer::_Font[i])."""
from __future__ import annotations

import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[4]
CODE = ROOT / "work/fps60/bin/3dx_v12.code.bin"
BASE = 0x100000


def u16str(b: bytes, off: int) -> str:
    out = []
    while True:
        c = struct.unpack_from("<H", b, off)[0]
        if c == 0:
            break
        out.append(chr(c))
        off += 2
    return "".join(out)


def main():
    b = CODE.read_bytes()
    tab = int(sys.argv[1], 16) if len(sys.argv) > 1 else 0x3F41A4
    n = int(sys.argv[2]) if len(sys.argv) > 2 else 9
    for i in range(n):
        p = struct.unpack_from("<I", b, tab - BASE + 4 * i)[0]
        s = u16str(b, p - BASE) if BASE <= p < BASE + len(b) else "?"
        print(f"_Font[{i}] ptr=0x{p:08X} -> {s!r}")


if __name__ == "__main__":
    main()
