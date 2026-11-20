"""Read-only look at the two CIA files: TMD title version, content chunks (encrypted flag), first NCCH header.

The tool's metadata.identify() reported title version 0 for both files; this checks the raw TMD and whether
the content is titlekey-encrypted (TMD content type bit 0) or NCCH-encrypted (NCCH flags[7] bit 2 = NoCrypto).
Writes nothing except results to stdout.
"""
from __future__ import annotations

import json
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
SIG = {0x10000: 0x240, 0x10001: 0x140, 0x10002: 0x80, 0x10003: 0x240, 0x10004: 0x140, 0x10005: 0x80}


def al(x: int) -> int:
    return (x + 63) & ~63


def info(path: Path) -> dict:
    with path.open("rb") as f:
        h = f.read(0x20)
        hdr, typ, ver, cert, tik, tmd, meta, content = struct.unpack("<IHHIIIIQ", h)
        tmd_off = al(hdr) + al(cert) + al(tik)
        content_off = al(tmd_off + tmd)
        f.seek(tmd_off)
        t = f.read(tmd)
        sig = struct.unpack(">I", t[:4])[0]
        o = SIG[sig]
        head = t[o:o + 0xC4]
        tid = head[0x4C:0x54].hex().upper()
        title_ver = struct.unpack(">H", head[0x9C:0x9E])[0]
        count = struct.unpack(">H", head[0x9E:0xA0])[0]
        chunks = []
        base = o + 0xC4 + 64 * 0x24
        for i in range(count):
            c = t[base + i * 0x30: base + (i + 1) * 0x30]
            cid, idx, ctype, size = struct.unpack(">IHHQ", c[:16])
            chunks.append({"id": f"{cid:08x}", "index": idx, "type": f"{ctype:#06x}",
                           "titlekey_encrypted": bool(ctype & 1), "size": size})
        # ticket: title version too (offset 0x1E6 in the ticket body after the signature)
        f.seek(al(hdr) + al(cert))
        tk = f.read(tik)
        tsig = struct.unpack(">I", tk[:4])[0]
        tb = tk[SIG[tsig]:]
        ticket_ver = struct.unpack(">H", tb[0xA6:0xA8])[0]
        f.seek(content_off)
        n = f.read(0x200)
    out = {"file": path.name, "tmd_sig": hex(sig), "tmd_title_id": tid, "tmd_title_version": title_ver,
           "tmd_version_display": f"{title_ver >> 10}.{(title_ver >> 4) & 63}.{title_ver & 15}",
           "ticket_title_version": ticket_ver, "contents": chunks}
    if n[0x100:0x104] == b"NCCH":
        flags = n[0x188:0x190]
        out["ncch0"] = {"readable_header": True, "program_id": n[0x118:0x120][::-1].hex().upper(),
                        "product_code": n[0x150:0x160].split(b"\0")[0].decode("ascii", "replace"),
                        "flags7": hex(flags[7]), "no_crypto": bool(flags[7] & 4)}
    else:
        out["ncch0"] = {"readable_header": False, "note": "content 0 is titlekey-encrypted (no NCCH magic)"}
    return out


def main() -> None:
    sys.stdout.reconfigure(encoding="utf-8")
    res = [info(p) for p in sorted(ROOT.glob("*.cia"))]
    print(json.dumps(res, ensure_ascii=False, indent=1))


if __name__ == "__main__":
    main()
