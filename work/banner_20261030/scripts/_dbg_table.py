import struct, sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).parent))
import bnr
for p in ["exefs/banner", "ml 1dx/3exefs/banner"]:
    raw = Path(p).read_bytes()
    c = bnr.parse_cbmd(raw)
    b = c["cgfx"]
    hsize = struct.unpack_from("<H", b, 6)[0]
    print(p, "hsize", hex(hsize), b[:0x14].hex(), "DATA size", hex(struct.unpack_from("<I", b, hsize + 4)[0]))
    for k in range(16):
        cnt, off = struct.unpack_from("<II", b, hsize + 8 + 8 * k)
        at = hsize + 8 + 8 * k + 4
        tgt = at + off if off else 0
        print(k, bnr.SECTION_NAMES[k], cnt, hex(off), hex(tgt), b[tgt:tgt + 4] if tgt else b"")
    print(b[0x9C:0x200].hex())
