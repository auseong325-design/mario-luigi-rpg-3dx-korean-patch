"""Lead: independent check of an fps60 build (does not import IMPL's code).

- IPS: apply with a minimal applier, compare with patched.code.bin, list changed ranges.
- BPS: read the footer CRCs (source/target/patch) and compare with CRC32 of the input/patched images.
- Disassemble every changed range with capstone.

Usage: python scripts/fps60/lead_check_build.py <tag>   (read-only)
"""
import sys, zlib, struct, pathlib

ROOT = pathlib.Path(__file__).resolve().parents[2]
BASE = 0x100000


def apply_ips(src: bytes, ips: bytes) -> bytes:
    assert ips[:5] == b'PATCH', 'not IPS'
    out = bytearray(src)
    i = 5
    while True:
        if ips[i:i + 3] == b'EOF':
            break
        off = int.from_bytes(ips[i:i + 3], 'big'); i += 3
        size = int.from_bytes(ips[i:i + 2], 'big'); i += 2
        if size == 0:
            rle = int.from_bytes(ips[i:i + 2], 'big'); i += 2
            val = ips[i]; i += 1
            data = bytes([val]) * rle
        else:
            data = ips[i:i + size]; i += size
        if off + len(data) > len(out):
            out.extend(b'\0' * (off + len(data) - len(out)))
        out[off:off + len(data)] = data
    return bytes(out)


def ranges(a: bytes, b: bytes):
    res, start = [], None
    for k in range(max(len(a), len(b))):
        d = (a[k] if k < len(a) else None) != (b[k] if k < len(b) else None)
        if d and start is None:
            start = k
        if not d and start is not None:
            res.append((start, k)); start = None
    if start is not None:
        res.append((start, max(len(a), len(b))))
    return res


def main():
    tag = sys.argv[1] if len(sys.argv) > 1 else 'v1'
    bdir = ROOT / 'work' / 'fps60' / 'build' / tag
    src = (ROOT / 'work' / 'fps60' / 'bin' / '3dx_v12.code.bin').read_bytes()
    tgt = (bdir / 'patched.code.bin').read_bytes()
    ips = (bdir / 'code.ips').read_bytes()
    bps = (bdir / 'code.bps').read_bytes()

    print(f'tag {tag}: src {len(src):#x} crc {zlib.crc32(src):08X} | patched {len(tgt):#x} crc {zlib.crc32(tgt):08X}')
    out = apply_ips(src, ips)
    print('IPS applied == patched.code.bin:', out == tgt)

    assert bps[:4] == b'BPS1', 'not BPS'
    s_crc, t_crc, p_crc = struct.unpack('<III', bps[-12:])
    print(f'BPS footer: source {s_crc:08X} (input {zlib.crc32(src):08X}) target {t_crc:08X} '
          f'(patched {zlib.crc32(tgt):08X}) patch {p_crc:08X} (own {zlib.crc32(bps[:-4]):08X})')
    ok = s_crc == zlib.crc32(src) and t_crc == zlib.crc32(tgt) and p_crc == zlib.crc32(bps[:-4])
    print('BPS CRCs consistent:', ok)

    from capstone import Cs, CS_ARCH_ARM, CS_MODE_ARM
    md = Cs(CS_ARCH_ARM, CS_MODE_ARM)
    for a, b in ranges(src, tgt):
        print(f'-- changed file {a:#x}..{b:#x} = addr {a + BASE:#x}..{b + BASE:#x} ({b - a} bytes)')
        lo = a & ~3
        hi = (b + 3) & ~3
        for ins in md.disasm(tgt[lo:hi], lo + BASE):
            old = src[ins.address - BASE:ins.address - BASE + 4].hex()
            print(f'   {ins.address:08x}: {ins.bytes.hex()} {ins.mnemonic:8s} {ins.op_str:28s} (was {old})')


if __name__ == '__main__':
    main()
