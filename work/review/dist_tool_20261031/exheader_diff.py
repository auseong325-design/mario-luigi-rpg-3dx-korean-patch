"""Read-only: compare the NCCH headers and extended headers of the base and update CIAs.

Question: can a single "merged" base title be made from base + v1.2 update (update exheader + v1.2 code +
update RomFS files) so that RomForge's normal base-game repack can carry the whole patch? This lists which
exheader fields differ between the two titles (code-set layout, flags, IDs, save data, access control).
Field offsets: 3dbrew "NCCH/Extended Header". Prints JSON; writes nothing.
"""
from __future__ import annotations

import hashlib
import json
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]


def al(x: int) -> int:
    return (x + 63) & ~63


def ncch_of(cia: Path) -> tuple[bytes, bytes, int]:
    with cia.open("rb") as f:
        hdr, typ, ver, cert, tik, tmd, meta, content = struct.unpack("<IHHIIIIQ", f.read(0x20))
        off = al(al(hdr) + al(cert) + al(tik) + tmd)
        f.seek(off)
        head = f.read(0x200)
        exh = f.read(0x800)
    return head, exh, off


def codeset(b: bytes, o: int) -> dict:
    addr, pages, size = struct.unpack_from("<III", b, o)
    return {"addr": hex(addr), "pages": pages, "size": hex(size)}


def fields(head: bytes, exh: bytes) -> dict:
    sci = exh[:0x200]
    aci = exh[0x200:0x400]
    d = {
        "ncch.program_id": head[0x118:0x120][::-1].hex().upper(),
        "ncch.partition_id": head[0x108:0x110][::-1].hex().upper(),
        "ncch.product_code": head[0x150:0x160].split(b"\0")[0].decode("ascii", "replace"),
        "ncch.exheader_size": hex(struct.unpack_from("<I", head, 0x180)[0]),
        "ncch.flags": head[0x188:0x190].hex(),
        "sci.title": sci[:8].split(b"\0")[0].decode("ascii", "replace"),
        "sci.flag(compress=1,sd=2)": sci[0x0D],
        "sci.remaster_version": struct.unpack_from("<H", sci, 0x0E)[0],
        "sci.text": codeset(sci, 0x10),
        "sci.stack": hex(struct.unpack_from("<I", sci, 0x1C)[0]),
        "sci.ro": codeset(sci, 0x20),
        "sci.data": codeset(sci, 0x30),
        "sci.bss": hex(struct.unpack_from("<I", sci, 0x3C)[0]),
        "sci.dependencies_sha": hashlib.sha256(sci[0x40:0x1C0]).hexdigest()[:16],
        "sci.savedata_size": hex(struct.unpack_from("<Q", sci, 0x1C0)[0]),
        "sci.jump_id": hex(struct.unpack_from("<Q", sci, 0x1C8)[0]),
        "aci.program_id": aci[0:8][::-1].hex().upper(),
        "aci.core_version": hex(struct.unpack_from("<I", aci, 8)[0]),
        "aci.flags_rest_sha": hashlib.sha256(aci[0x0C:0x30]).hexdigest()[:16],
        "aci.extdata_id": hex(struct.unpack_from("<Q", aci, 0x30)[0]),
        "aci.system_savedata_ids": hex(struct.unpack_from("<Q", aci, 0x38)[0]),
        "aci.storage_unique_ids": hex(struct.unpack_from("<Q", aci, 0x40)[0]),
        "aci.fs_access": aci[0x48:0x50].hex(),
        "aci.services_sha": hashlib.sha256(aci[0x50:0x170]).hexdigest()[:16],
        "aci.kernel_caps_sha": hashlib.sha256(aci[0x170:0x1F0]).hexdigest()[:16],
        "aci.arm9_sha": hashlib.sha256(aci[0x1F0:0x200]).hexdigest()[:16],
        "accessdesc_sig_sha": hashlib.sha256(exh[0x400:0x500]).hexdigest()[:16],
        "accessdesc_aci_program_id": exh[0x600:0x608][::-1].hex().upper(),
        "accessdesc_rest_sha": hashlib.sha256(exh[0x608:0x800]).hexdigest()[:16],
    }
    return d


def main() -> None:
    sys.stdout.reconfigure(encoding="utf-8")
    base = next(ROOT.glob("00040000001CA900*.cia"))
    upd = next(ROOT.glob("0004000E001CA900*.cia"))
    hb, eb, _ = ncch_of(base)
    hu, eu, _ = ncch_of(upd)
    fb, fu = fields(hb, eb), fields(hu, eu)
    same = {k: fb[k] for k in fb if fb[k] == fu[k]}
    differ = {k: {"base": fb[k], "update": fu[k]} for k in fb if fb[k] != fu[k]}
    raw_diff = [hex(i) for i in range(0x800) if eb[i] != eu[i]]
    print(json.dumps({"differ": differ, "same": same, "exheader_bytes_differ": len(raw_diff),
                      "first_differing_offsets": raw_diff[:40]}, ensure_ascii=False, indent=1))


if __name__ == "__main__":
    main()
