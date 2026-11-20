"""IMPL helper: read the code-set info (text/ro/data sizes) from the game's CIA files, read-only.

    python scripts/fps60/impl_exheader.py            # both CIAs in the project root (v1.0 base, v1.2 update)
    python scripts/fps60/impl_exheader.py <file.cia> [...]

The loaders need these numbers: Luma3DS passes `csi->text.size` (exact, unrounded) to its LayeredFS payload
placement (payload copied to code + textSize when the .text padding is large enough) and maps
(text pages + ro pages + data pages) << 12 bytes as the code buffer it patches; Azahar sizes the code segments
from `num_max_pages` and appends the bss pages before it applies code.ips / code.bps.
"""
from __future__ import annotations

import glob
import json
import os
import struct
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))


def _align(x: int, a: int = 64) -> int:
    return (x + a - 1) & ~(a - 1)


def read_cia_ncch(path: str) -> dict:
    """Return the NCCH header fields and the exheader code-set info of content 0 of a CIA."""
    with open(path, "rb") as f:
        hdr = f.read(0x20)
        hsize, _typ, _ver, cert, tik, tmd, _meta, _csize = struct.unpack("<IHHIIIIQ", hdr)
        off_tmd = _align(hsize) + _align(cert) + _align(tik)
        off_content = off_tmd + _align(tmd)
        f.seek(off_tmd)
        tmd_data = f.read(tmd)
        sig_type = struct.unpack(">I", tmd_data[:4])[0]
        sig_len = {0x10003: 0x200 + 0x3C, 0x10004: 0x100 + 0x3C, 0x10005: 0x3C + 0x40}[sig_type]
        th = 4 + sig_len  # TMD header start
        content_count = struct.unpack(">H", tmd_data[th + 0x9E:th + 0xA0])[0]
        chunk0 = th + 0xC4 + 0x900
        cid, cidx, ctype, csz = struct.unpack(">IHHQ", tmd_data[chunk0:chunk0 + 0x10])
        f.seek(off_content)
        ncch = f.read(0x200 + 0x800)
    if ncch[0x100:0x104] != b"NCCH":
        raise ValueError(f"{path}: content 0 is not a plain NCCH (CIA content type {ctype:#x}; encrypted?)")
    program_id = struct.unpack_from("<Q", ncch, 0x118)[0]
    flags = ncch[0x188:0x190]
    exh = ncch[0x200:0x600]

    def csi(o: int) -> dict:
        addr, pages, size = struct.unpack_from("<III", exh, o)
        return {"address": addr, "num_max_pages": pages, "size": size}

    info = {
        "file": os.path.relpath(path, ROOT),
        "cia_content0": {"id": cid, "index": cidx, "type": ctype, "size": csz, "count": content_count},
        "program_id": f"{program_id:016X}",
        "ncch_flags": flags.hex(),
        "no_crypto": bool(flags[7] & 4),
        "sci_name": exh[0:8].rstrip(b"\0").decode("ascii", "replace"),
        "compress_exefs_code": bool(exh[0x0D] & 1),
        "remaster_version": struct.unpack_from("<H", exh, 0x0E)[0],
        "text": csi(0x10),
        "stack_size": struct.unpack_from("<I", exh, 0x1C)[0],
        "rodata": csi(0x20),
        "data": csi(0x30),
        "bss_size": struct.unpack_from("<I", exh, 0x3C)[0],
        "aci_title_id": f"{struct.unpack_from('<Q', exh, 0x200)[0]:016X}",
        "local_caps_flags": exh[0x200 + 0x0C:0x200 + 0x10].hex(),
    }
    t, r, d = info["text"], info["rodata"], info["data"]
    pages = [(s["size"] + 4095) >> 12 for s in (t, r, d)]
    info["luma_total_size"] = sum(pages) << 12          # loader.c: (text+ro+data pages) << 12
    info["luma_text_size"] = t["size"]                  # patchCode(..., csi->text.size, ...)
    info["azahar_code_segment_size"] = t["num_max_pages"] << 12
    info["azahar_bss_page_size"] = (info["bss_size"] + 0xFFF) & ~0xFFF
    return info


def project_cias() -> dict[str, str]:
    out = {}
    for p in sorted(glob.glob(os.path.join(ROOT, "*.cia"))):
        name = os.path.basename(p)
        if name.startswith("0004000E001CA900"):
            out["v12_update"] = p
        elif name.startswith("00040000001CA900"):
            out["v10_base"] = p
    return out


def main(argv: list[str]) -> None:
    paths = argv or list(project_cias().values())
    print(json.dumps([read_cia_ncch(p) for p in paths], indent=1))


if __name__ == "__main__":
    main(sys.argv[1:])
