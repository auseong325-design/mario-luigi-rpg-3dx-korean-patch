"""List Lyt/JP/*.dat SARC contents and BFLYT font lists / text panes (FONT worker, read-only)."""
from __future__ import annotations

import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[4]
sys.path.insert(0, str(ROOT / "scripts"))
from lib3dx import blz_decompress, read_bg4, romfs_path  # noqa: E402
from lytimg import sarc_list  # noqa: E402


def sections(b: bytes):
    magic, bom, hsize, ver, fsize, nsec = struct.unpack_from("<4sHHIIH", b, 0)
    p = hsize
    out = []
    for _ in range(nsec):
        m, sz = b[p:p + 4], struct.unpack_from("<I", b, p + 4)[0]
        out.append((m.decode("latin1"), p, sz))
        p += sz
    return ver, out


def strlist(b: bytes, p: int) -> list[str]:
    n = struct.unpack_from("<H", b, p + 8)[0]
    base = p + 12
    names = []
    for i in range(n):
        o = struct.unpack_from("<I", b, base + 4 * i)[0]
        s = base + o
        names.append(b[s:b.find(b"\0", s)].decode("latin1"))
    return names


def main():
    dat = sys.argv[1] if len(sys.argv) > 1 else "MLyt"
    filt = sys.argv[2] if len(sys.argv) > 2 else ""
    _, ents = read_bg4(romfs_path(f"Lyt/JP/{dat}.dat").read_bytes())
    for e in ents:
        if e.size_flag or not e.data:
            continue
        raw = blz_decompress(e.data) if e.compressed else e.data
        if raw[:4] != b"SARC":
            print(e.name, "not SARC", raw[:4])
            continue
        files = sarc_list(raw)
        lyts = [f for f in files if f[0].endswith(".bflyt")]
        info = []
        for name, s, t in lyts:
            b = raw[s:t]
            ver, secs = sections(b)
            fn = []
            ntxt = 0
            for m, p, sz in secs:
                if m == "fnl1":
                    fn = strlist(b, p)
                if m == "txt1":
                    ntxt += 1
            info.append(f"{name.rsplit('/', 1)[-1]}(v{ver:08X} txt={ntxt} fonts={fn})")
        line = f"{e.name}: {len(files)} files; " + "; ".join(info)
        if filt.lower() in line.lower():
            print(line)


if __name__ == "__main__":
    main()
