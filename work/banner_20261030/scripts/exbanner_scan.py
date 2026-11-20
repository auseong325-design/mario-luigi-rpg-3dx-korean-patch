"""Does the game itself create/use extdata or an ExBanner (which HOME would show instead of
ExeFS:/banner)? Scan the decompressed v1.2 code, all CROs and the exheader for the strings and for
the extdata archive id / ExBanner path pieces. Read-only. Writes out/exbanner_scan.json."""
from __future__ import annotations

import json
import re
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
WORK = HERE.parent
ROOT = WORK.parents[1]
PAT = [b"banner", b"Banner", b"BANNER", b"ExBanner", b"exbanner", b"extdata", b"ExtData", b"EXTDATA",
       b"COMMON.bin", b"/ExBanner"]


def scan(path: Path) -> dict:
    b = path.read_bytes()
    res = {}
    for p in PAT:
        hits = [m.start() for m in re.finditer(re.escape(p), b)]
        # UTF-16LE too
        p16 = p.decode().encode("utf-16-le")
        hits16 = [m.start() for m in re.finditer(re.escape(p16), b)]
        if hits or hits16:
            ctx = []
            for h in (hits + hits16)[:6]:
                s = b[max(0, h - 24):h + 40]
                ctx.append(s.decode("latin-1").replace("\0", "."))
            res[p.decode()] = {"ascii": len(hits), "utf16": len(hits16), "context": ctx}
    return res


def main() -> int:
    targets = [ROOT / "work/fps60/bin/3dx_v12.code.bin"] + sorted((ROOT / "romf2/RO").glob("*.cr*")) + \
              sorted((ROOT / "romfs/RO").glob("*.cr*"))
    rep = {}
    for t in targets:
        if t.exists():
            r = scan(t)
            if r:
                rep[str(t.relative_to(ROOT))] = r
    # exheader: extdata id in the ARM11 local system capabilities (storage info)
    cia = next(ROOT.glob("00040000001CA900*.cia"))
    sys.path.insert(0, str(HERE))
    import cia as C
    c = C.Cia(cia)
    base = c.chunks[0]["cia_off"]
    ex = c.read(base + 0x200, 0x400)
    # SCI: 0x000; ACI starts at 0x200: ARM11 local system caps at 0x200: program id(8) core ver(4) flags(4)
    # storage info at ACI+0x30: extdata id (8), system savedata ids (8), storage accessible unique ids (8), fs access info (7) + other attrs (1)
    st = 0x200 + 0x30
    extdata_id = int.from_bytes(ex[st:st + 8], "little")
    fs_access = int.from_bytes(ex[st + 0x18:st + 0x1F], "little")
    other = ex[st + 0x1F]
    rep["exheader_extdata_id"] = hex(extdata_id)
    rep["exheader_fs_access_info"] = hex(fs_access)
    rep["exheader_other_attributes"] = hex(other)
    (WORK / "out/exbanner_scan.json").write_text(json.dumps(rep, indent=1), encoding="utf-8")
    print(json.dumps(rep, indent=1)[:6000])
    return 0


if __name__ == "__main__":
    sys.exit(main())
