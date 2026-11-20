"""Find the 1DX KR font-name pointer table (pointers to the UTF-16 names found by cmp_1dx_fonts.py)."""
from __future__ import annotations

import struct
from pathlib import Path

ROOT = Path(__file__).resolve().parents[4]
CODE = ROOT / "work/fps60/bin/1dx_kr.code.bin"
BASE = 0x100000


def u16str(b, off):
    out = []
    while True:
        c = struct.unpack_from("<H", b, off)[0]
        if c == 0:
            return "".join(out)
        out.append(chr(c))
        off += 2


def main():
    b = CODE.read_bytes()
    names = {}
    for n in ["font_sys.bffnt", "font_sys_btl.bffnt", "font_l.bffnt", "font.bffnt", "font_btl.bffnt",
              "gaizi.bffnt", "font_ruby.bffnt"]:
        u = n.encode("utf-16-le") + b"\0\0"
        p = 0
        while True:
            i = b.find(u, p)
            if i < 0:
                break
            # make sure it is the start of the string (previous u16 is 0 or the name begins after a NUL)
            names[i + BASE] = n
            p = i + 2
    print("name addrs:", {f"0x{a:08X}": n for a, n in names.items()})
    # scan for runs of pointers to these names
    hits = []
    for off in range(0, len(b) - 4, 4):
        v = struct.unpack_from("<I", b, off)[0]
        if v in names:
            hits.append(off)
    runs = []
    for h in hits:
        if runs and h - runs[-1][-1] <= 16:
            runs[-1].append(h)
        else:
            runs.append([h])
    for r in runs:
        if len(r) >= 2:
            s, e = r[0] - 8, r[-1] + 12
            print(f"run at 0x{s + BASE:08X}:")
            for off in range(s, e, 4):
                v = struct.unpack_from("<I", b, off)[0]
                nm = names.get(v)
                if nm is None and BASE <= v < BASE + len(b):
                    try:
                        t = u16str(b, v - BASE)
                        nm = repr(t) if 0 < len(t) < 40 and t.isprintable() else ""
                    except Exception:
                        nm = ""
                print(f"  0x{off + BASE:08X}: 0x{v:08X} {nm or ''}")


if __name__ == "__main__":
    main()
