"""Font lists (fnl1) and text panes (txt1) in the giant-battle HB layouts: do they draw with the message
fonts this build changes? (FONT worker, read-only)"""
from __future__ import annotations

import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[4]
sys.path.insert(0, str(ROOT / "scripts"))
import libhb as H  # noqa: E402
from lib3dx import romfs_path  # noqa: E402


def main():
    for rel in H.arc_rels():
        p = romfs_path(rel)
        if not p.exists():
            continue
        sarc = H.unpack(p.read_bytes())
        for e in H.sarc_entries(sarc):
            d = sarc[e["start"]:e["end"]]
            if d[:4] != b"FLYT":
                continue
            _m, _bom, hl, ver, _fs, ns = struct.unpack_from("<4sHHIIH", d, 0)
            q = hl
            fonts, txt = [], []
            for _ in range(ns):
                m, sz = d[q:q + 4], struct.unpack_from("<I", d, q + 4)[0]
                if m == b"fnl1":
                    n = struct.unpack_from("<H", d, q + 8)[0]
                    for i in range(n):
                        o = struct.unpack_from("<I", d, q + 12 + 4 * i)[0]
                        s = q + 12 + o
                        fonts.append(d[s:d.find(b"\0", s)].decode("latin1"))
                if m == b"txt1":
                    name = d[q + 0x0C:q + 0x24].split(b"\0")[0].decode("latin1")
                    fi = struct.unpack_from("<H", d, q + 0x54 + 6)[0]
                    txt.append(f"{name}(font#{fi})")
                q += sz
            if fonts or txt:
                print(f"{rel} #{e['index']}: fonts={fonts} text panes={txt[:12]}{' ...' if len(txt) > 12 else ''}")


if __name__ == "__main__":
    main()
