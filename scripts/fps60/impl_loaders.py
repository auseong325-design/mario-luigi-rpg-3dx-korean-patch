"""IMPL: Python re-implementations of the two code loaders, written from their source code.

Used by scripts/fps60/build_fps60.py to verify code.ips / code.bps before anything is installed.
Sources read (2026-10-30, copies under $KIROCREW_SCRATCH/impl/src while this ran):

  Luma3DS  sysmodules/loader/source/patcher.c, bps_patcher.cpp, loader.c, romfsredir.s
           tags v10.1 (first release with code.bps, commit 8233d4e226 2019-07-08), v13.4 (latest release,
           2026-04-02) and master (2026-10-25: IPS grow/trailer support, UPS). github.com/LumaTeam/Luma3DS
  Azahar   src/core/file_sys/patch.cpp, ncch_container.cpp, src/core/loader/ncch.cpp,
           tag 2126.1.2 (the user's build) = master for these files. github.com/azahar-emu/azahar

Every function documents the source behaviour it reproduces, including what happens on a bad file.
Results are (ok: bool, detail: str) or a status string, never exceptions for a malformed patch.
"""
from __future__ import annotations

import struct
import zlib

NONE32 = 0xFFFFFFFF


def u32(buf, off: int) -> int:
    return struct.unpack_from("<I", buf, off)[0]


# ----------------------------------------------------------------------------------------------------------
# CRC-32 (BPS). Luma: bitwise reflected 0xEDB88320, init/xorout 0xFFFFFFFF; Azahar: boost::crc_32_type (same).
# ----------------------------------------------------------------------------------------------------------
def crc32_bitwise(data: bytes) -> int:
    """Literal port of Luma bps_patcher.cpp crc32() (slow; used to prove zlib.crc32 is the same function)."""
    crc = 0xFFFFFFFF
    for b in data:
        crc ^= b
        for _ in range(8):
            mask = (-(crc & 1)) & 0xFFFFFFFF
            crc = (crc >> 1) ^ (0xEDB88320 & mask)
    return (~crc) & 0xFFFFFFFF


def crc32(data) -> int:
    return zlib.crc32(data) & 0xFFFFFFFF


# ----------------------------------------------------------------------------------------------------------
# Writers
# ----------------------------------------------------------------------------------------------------------
def ips_records(orig: bytes, new: bytes, merge_gap: int = 0) -> list[tuple[int, bytes]]:
    """Changed byte runs as (offset, new bytes); runs closer than merge_gap are merged."""
    assert len(orig) == len(new)
    recs: list[list] = []
    i, n = 0, len(orig)
    while i < n:
        if orig[i] == new[i]:
            i += 1
            continue
        j = i
        while j < n and orig[j] != new[j]:
            j += 1
        if recs and i - (recs[-1][0] + len(recs[-1][1])) <= merge_gap:
            start = recs[-1][0]
            recs[-1][1] = new[start:j]
        else:
            recs.append([i, new[i:j]])
        i = j
    return [(o, bytes(b)) for o, b in recs]


def ips_encode(records: list[tuple[int, bytes]]) -> bytes:
    out = bytearray(b"PATCH")
    for off, data in records:
        if off > 0xFFFFFF or off == 0x454F46:
            raise ValueError(f"IPS offset {off:#x} not encodable")
        for k in range(0, len(data), 0xFFFF):
            chunk = data[k:k + 0xFFFF]
            out += struct.pack(">I", off + k)[1:] + struct.pack(">H", len(chunk)) + chunk
    out += b"EOF"
    return bytes(out)


def bps_number(v: int) -> bytes:
    out = bytearray()
    while True:
        x = v & 0x7F
        v >>= 7
        if v == 0:
            out.append(0x80 | x)
            return bytes(out)
        out.append(x)
        v -= 1


def bps_encode(source: bytes, target: bytes, ranges: list[tuple[int, int]] | None = None) -> bytes:
    """BPS1 with SourceRead (unchanged runs) and TargetRead (changed runs) only, metadata size 0
    (Luma and Azahar both refuse metadata_size != 0). With `ranges` [(offset, length)], each range is one
    TargetRead (bytes inside it may equal the source) and everything else is SourceRead."""
    out = bytearray(b"BPS1")
    out += bps_number(len(source)) + bps_number(len(target)) + bps_number(0)
    n = len(target)
    if ranges is not None:
        assert len(source) == n
        pos = 0
        for off, ln in sorted(ranges):
            assert off >= pos and ln > 0 and off + ln <= n
            if off > pos:
                out += bps_number(((off - pos - 1) << 2) | 0)
            out += bps_number(((ln - 1) << 2) | 1) + target[off:off + ln]
            pos = off + ln
        if pos < n:
            out += bps_number(((n - pos - 1) << 2) | 0)
        out += struct.pack("<II", crc32(source), crc32(target))
        out += struct.pack("<I", crc32(bytes(out)))
        return bytes(out)
    i = 0
    while i < n:
        same = i < len(source) and source[i] == target[i]
        j = i
        while j < n and (j < len(source) and source[j] == target[j]) == same:
            j += 1
        length = j - i
        if same:
            out += bps_number(((length - 1) << 2) | 0)
        else:
            out += bps_number(((length - 1) << 2) | 1) + target[i:j]
        i = j
    out += struct.pack("<II", crc32(source), crc32(target))
    out += struct.pack("<I", crc32(bytes(out)))
    return bytes(out)


# ----------------------------------------------------------------------------------------------------------
# BPS appliers (Luma bps_patcher.cpp v10.1..master; Azahar patch.cpp). Same algorithm, different failure exits.
# ----------------------------------------------------------------------------------------------------------
class _Stream:
    def __init__(self, buf, size: int, checked_seek: bool):
        self.buf, self.size, self.off, self.checked_seek = buf, size, 0, checked_seek

    def read(self, n: int):
        if self.off + n > self.size:
            return None
        d = bytes(self.buf[self.off:self.off + n])
        self.off += n
        return d

    def copy_from(self, other: "_Stream", n: int) -> bool:
        if self.off + n > self.size:
            return False
        d = other.read(n)
        if d is None:
            return False
        self.buf[self.off:self.off + n] = d
        self.off += n
        return True

    def read_number(self) -> int:
        data, shift = 0, 1
        while True:
            x = self.read(1)
            if x is None:
                break
            x = x[0]
            data = (data + (x & 0x7F) * shift) & 0xFFFFFFFF
            if x & 0x80:
                break
            shift = (shift << 7) & 0xFFFFFFFF
            data = (data + shift) & 0xFFFFFFFF
        return data

    def seek(self, off: int) -> bool:
        if self.checked_seek and off > self.size:  # Azahar's Seek; Luma's never fails
            return False
        self.off = off
        return True


def _bps_apply(source: _Stream, target: _Stream, patch: _Stream) -> tuple[str, int]:
    """PatchApplier::Apply. Returns (status, target_size); status in
    ok | bad_magic | bad_sizes | source_crc | bad_command | target_crc."""
    if patch.read(4) != b"BPS1":
        return "bad_magic", 0
    source_size = patch.read_number()
    target_size = patch.read_number()
    metadata_size = patch.read_number()
    if source_size > source.size or target_size > target.size or metadata_size != 0:
        return "bad_sizes", 0
    cmd_start = patch.off
    cmd_end = patch.size - 12
    patch.seek(cmd_end)
    src_crc = u32(patch.read(4), 0)
    tgt_crc = u32(patch.read(4), 0)
    patch.seek(cmd_start)
    if crc32(bytes(source.buf[:source_size])) != src_crc:
        return "source_crc", 0                      # nothing written yet (memset comes after this check)
    target.buf[:target.size] = bytes(target.size)   # std::memset(target, 0, target.size())
    src_rel = tgt_rel = 0
    while patch.off < cmd_end:
        data = patch.read_number()
        cmd, length = data & 3, (data >> 2) + 1
        if cmd == 0:  # SourceRead
            ok = source.seek(target.off) and target.copy_from(source, length)
        elif cmd == 1:  # TargetRead
            ok = target.copy_from(patch, length)
        elif cmd == 2:  # SourceCopy
            d = patch.read_number()
            src_rel += (-1 if d & 1 else 1) * (d >> 1)
            ok = src_rel >= 0 and source.seek(src_rel) and target.copy_from(source, length)
            src_rel += length
        else:  # TargetCopy
            d = patch.read_number()
            tgt_rel += (-1 if d & 1 else 1) * (d >> 1)
            ok = tgt_rel >= 0 and target.off + length <= target.size and tgt_rel + length <= target.size
            if ok:
                for k in range(length):
                    target.buf[target.off + k] = target.buf[tgt_rel]
                    tgt_rel += 1
                target.seek(target.off + length)
        if not ok:
            return "bad_command", 0
    if crc32(bytes(target.buf[:target_size])) != tgt_crc:
        return "target_crc", 0
    return "ok", target_size


def luma_bps_apply(code: bytearray, max_size: int, patch: bytes) -> tuple[bool, str]:
    """Luma ApplyCodeBpsPatch: source = copy of code[0:max_size]; target = code (max_size);
    any Apply() failure -> svcBreak(USERBREAK_PANIC) in the loader (game never starts)."""
    source = bytearray(code[:max_size])
    st, _ = _bps_apply(_Stream(source, max_size, False), _Stream(code, max_size, False),
                       _Stream(patch, len(patch), False))
    if st != "ok":
        return False, f"{st} -> svcBreak(USERBREAK_PANIC) in loader (title does not start)"
    return True, "applied"


def azahar_bps_apply(buffer: bytearray, patch: bytes) -> str:
    """Azahar Patch::ApplyBpsPatch: resize to target_size if larger, source = copy of buffer, Apply().
    Returns Success | ErrorPatches | ErrorPatchesInvalidTitle (LoadExec then fails: title does not start)."""
    ps = _Stream(patch, len(patch), True)
    ps.seek(4)
    source_size = ps.read_number()
    target_size = ps.read_number()
    if target_size > source_size and target_size > len(buffer):
        buffer.extend(bytes(target_size - len(buffer)))
    source = bytearray(buffer)
    st, _ = _bps_apply(_Stream(source, len(source), True), _Stream(buffer, len(buffer), True),
                       _Stream(patch, len(patch), True))
    return {"ok": "Success", "source_crc": "ErrorPatchesInvalidTitle"}.get(st, "ErrorPatches")


# ----------------------------------------------------------------------------------------------------------
# IPS appliers
# ----------------------------------------------------------------------------------------------------------
def luma_ips_apply_v134(code: bytearray, size: int, patch: bytes) -> tuple[bool, str]:
    """Luma v10.1..v13.4 applyCodeIpsPatch(progId, code, size=max size). No checksum. Records are read
    straight into code+offset; anything malformed (no 'PATCH', truncated record, offset+len > size, no 'EOF')
    returns false -> svcBreak(USERBREAK_ASSERT)."""
    p = 0

    def rd(n):
        nonlocal p
        d = patch[p:p + n]
        p += len(d)
        return d

    if rd(5) != b"PATCH":
        return False, "no PATCH header -> svcBreak(USERBREAK_ASSERT)"
    while True:
        b = rd(3)
        if len(b) != 3:
            return False, "missing EOF -> svcBreak(USERBREAK_ASSERT)"
        if b == b"EOF":
            return True, "applied"
        off = (b[0] << 16) | (b[1] << 8) | b[2]
        b = rd(2)
        if len(b) != 2:
            return False, "truncated -> svcBreak"
        sz = (b[0] << 8) | b[1]
        if sz == 0:
            b = rd(2)
            if len(b) != 2:
                return False, "truncated -> svcBreak"
            rle = (b[0] << 8) | b[1]
            if off + rle > size:
                return False, "RLE past max size -> svcBreak"
            v = rd(1)
            if len(v) != 1:
                return False, "truncated -> svcBreak"
            code[off:off + rle] = v * rle
            continue
        if off + sz > size:
            return False, "record past max size -> svcBreak"
        d = rd(sz)
        code[off:off + len(d)] = d
        if len(d) != sz:
            return False, "truncated record -> svcBreak"


def luma_ips_apply_master(code: bytearray, code_size: int, max_size: int, patch: bytes) -> tuple[bool, str, int]:
    """Luma master (2026-10-25) applyCodeIpsPatch(code, &codeSize, maxSize): records may grow the code up to
    maxSize (gap zero-filled), optional 3-byte size trailer after EOF. Returns (ok, detail, new code size)."""
    p = 0
    patched = code_size

    def rd(n):
        nonlocal p
        d = patch[p:p + n]
        p += len(d)
        return d

    def grow(off, sz):
        nonlocal patched
        if off + sz > max_size:
            return False
        if sz == 0:
            return True
        if off > patched:
            code[patched:off] = bytes(off - patched)
        if off + sz > patched:
            patched = off + sz
        return True

    if rd(5) != b"PATCH":
        return False, "no PATCH header -> svcBreak", code_size
    while True:
        b = rd(3)
        if len(b) != 3:
            return False, "missing EOF -> svcBreak", code_size
        if b == b"EOF":
            tr = rd(4)
            if len(tr) not in (0, 3):
                return False, "bad trailer -> svcBreak", code_size
            if len(tr) == 3:
                new = (tr[0] << 16) | (tr[1] << 8) | tr[2]
                if new > max_size:
                    return False, "trailer size > max -> svcBreak", code_size
                if new < patched:
                    code[new:patched] = bytes(patched - new)
                else:
                    code[patched:new] = bytes(new - patched)
                patched = new
            return True, "applied", patched
        off = (b[0] << 16) | (b[1] << 8) | b[2]
        b = rd(2)
        if len(b) != 2:
            return False, "truncated -> svcBreak", code_size
        sz = (b[0] << 8) | b[1]
        if sz == 0:
            b = rd(3)
            if len(b) != 3:
                return False, "truncated -> svcBreak", code_size
            rle = (b[0] << 8) | b[1]
            if not grow(off, rle):
                return False, "RLE past max -> svcBreak", code_size
            code[off:off + rle] = bytes([b[2]]) * rle
            continue
        if not grow(off, sz):
            return False, "record past max -> svcBreak", code_size
        d = rd(sz)
        code[off:off + len(d)] = d
        if len(d) != sz:
            return False, "truncated record -> svcBreak", code_size


def azahar_ips_apply(buffer: bytearray, ips: bytes) -> str:
    """Azahar Patch::ApplyIpsPatch: no checksum; ErrorPatches on a bad header or a record past the buffer."""
    if ips[:5] != b"PATCH":
        return "ErrorPatches"
    cursor, end = 5, len(ips) - 3
    while cursor < end:
        if ips[cursor:cursor + 3] == b"EOF":
            break
        off = ips[cursor] << 16 | ips[cursor + 1] << 8 | ips[cursor + 2]
        length = ips[cursor + 3] << 8 | ips[cursor + 4]
        if length == 0:
            length = ips[cursor + 5] << 8 | ips[cursor + 6]
            if len(buffer) < off + length:
                return "ErrorPatches"
            buffer[off:off + length] = bytes([ips[cursor + 7]]) * length
            cursor += 8
            continue
        if len(buffer) < off + length:
            return "ErrorPatches"
        buffer[off:off + length] = ips[cursor + 5:cursor + 5 + length]
        cursor += length + 5
    return "Success"


# ----------------------------------------------------------------------------------------------------------
# ExeFS .code decompression (BLZ / "LZSS" backwards)
# ----------------------------------------------------------------------------------------------------------
def luma_lzss_decompress(buf: bytearray, end: int) -> int:
    """In-place port of Luma loader.c lzss_decompress(u8 *end). buf[0:end] holds the compressed .code;
    returns the decompressed size (= end + last footer word, as loadCode computes codeSize)."""
    v1 = u32(buf, end - 8)
    out = end + u32(buf, end - 4)
    size = out
    v3 = end - (v1 >> 24)
    v4 = end - (v1 & 0xFFFFFF)
    while v3 > v4:
        v3 -= 1
        flags = buf[v3]
        for _ in range(8):
            if flags & 0x80:
                hi = buf[v3 - 1]
                lo = buf[v3 - 2]
                v3 -= 2
                disp = (((lo | (hi << 8)) & 0x0FFF) + 2)
                for _k in range((hi >> 4) + 3):
                    b = buf[out + disp]
                    out -= 1
                    buf[out] = b
            else:
                v3 -= 1
                out -= 1
                buf[out] = buf[v3]
            flags = (flags << 1) & 0xFF
            if v3 <= v4:
                return size
    return size


def azahar_lzss_decompress(comp: bytes) -> bytes | None:
    """Port of Azahar ncch_container.cpp LZSS_GetDecompressedSize + LZSS_Decompress."""
    dsize = len(comp) + u32(comp, len(comp) - 4)
    dec = bytearray(dsize)
    dec[:len(comp)] = comp
    tb = u32(comp, len(comp) - 8)
    out = dsize
    index = len(comp) - ((tb >> 24) & 0xFF)
    stop = len(comp) - (tb & 0xFFFFFF)
    while index > stop:
        index -= 1
        control = comp[index]
        for _ in range(8):
            if index <= stop or index <= 0 or out <= 0:
                break
            if control & 0x80:
                if index < 2:
                    return None
                index -= 2
                seg = comp[index] | (comp[index + 1] << 8)
                seg_size = ((seg >> 12) & 15) + 3
                seg = (seg & 0x0FFF) + 2
                if out < seg_size:
                    return None
                for _j in range(seg_size):
                    if out + seg >= dsize:
                        return None
                    b = dec[out + seg]
                    out -= 1
                    dec[out] = b
            else:
                if out < 1:
                    return None
                out -= 1
                index -= 1
                dec[out] = comp[index]
            control = (control << 1) & 0xFF
    return bytes(dec)


# ----------------------------------------------------------------------------------------------------------
# Luma LayeredFS (patcher.c patchLayeredFs): symbol search + payload/path placement, runs AFTER BPS/IPS.
# ----------------------------------------------------------------------------------------------------------
ROMFS_REDIR_SIZE = {"v10.1..v13.0.2": 0x11C, "v13.1+..master": 0x114}  # counted from romfsredir.s


def _find_function_start(code, pos: int) -> int:
    while pos >= 4:
        pos -= 4
        if struct.unpack_from("<H", code, pos + 2)[0] == 0xE92D:
            return pos
    return NONE32


def luma_find_layeredfs_symbols(code, size: int) -> dict:
    """findLayeredFsSymbols(code, textSize, ...) (v13.4 and master use the same patterns)."""
    s = {"fsMountArchive": NONE32, "fsRegisterArchive": NONE32, "fsTryOpenFile": NONE32,
         "fsOpenFileDirectly": NONE32, "fsUnMountArchive": NONE32}
    found = 0
    w = lambda a: u32(code, a)  # noqa: E731
    for addr in range(0, size - 4 + 1, 4):
        v = w(addr)
        temp = None
        if v == 0xE5970010:
            if addr <= size - 12 and s["fsMountArchive"] == NONE32 and w(addr + 4) == 0xE1CD20D8 and \
                    (w(addr + 8) & 0xFFFFFF) == 0x008D0000:
                temp = "fsMountArchive"
        elif v == 0xE24DD028:
            if addr <= size - 16 and s["fsMountArchive"] == NONE32 and w(addr + 4) == 0xE1A04000 and \
                    w(addr + 8) == 0xE59F60A8 and w(addr + 12) == 0xE3A0C001:
                temp = "fsMountArchive"
        elif v == 0xE2844001:
            if addr <= size - 12 and s["fsUnMountArchive"] == NONE32 and w(addr + 4) == 0xE3540020 and \
                    w(addr + 8) == 0x3AFFFFF0:
                temp = "fsUnMountArchive"
        elif v == 0xE353003A:
            if addr <= size - 12 and s["fsUnMountArchive"] == NONE32 and (w(addr + 4) & 0xFFFFFF0F) == 0x0A000009 \
                    and (w(addr + 8) & 0xFFFF0FF0) == 0xE1A00400:
                temp = "fsUnMountArchive"
        elif v == 0xE3500008:
            if addr <= size - 12 and s["fsRegisterArchive"] == NONE32 and (w(addr + 4) & 0xFFF00FF0) == 0xE1800400 \
                    and (w(addr + 8) & 0xFFF00FF0) == 0xE1800FC0:
                temp = "fsRegisterArchive"
        elif v == 0xE351003A:
            if addr <= size - 0x40 and s["fsTryOpenFile"] == NONE32 and w(addr + 4) == 0x1AFFFFFC and \
                    w(addr + 0x34) == 0xE590C000 and w(addr + 0x3C) == 0xE12FFF3C:
                temp = "fsTryOpenFile"
        elif v == 0x08030204:
            if s["fsOpenFileDirectly"] == NONE32:
                temp = "fsOpenFileDirectly"
        if temp is not None:
            s[temp] = _find_function_start(code, addr)
            if s[temp] != NONE32:
                found += 1
                if found == 5:
                    break
    s["found"] = found
    return s


def luma_layeredfs_placement(text_size: int, ro_size: int, data_size: int, ro_address: int,
                             data_address: int, payload_size: int) -> dict:
    """findLayeredFsPayloadOffset for the case 'enough .text padding' (the only one that applies here),
    plus the path string placement. Offsets are code-buffer offsets (= address - 0x100000)."""
    rt = (text_size + 4095) & ~4095
    rr = (ro_size + 4095) & ~4095
    rd = (data_size + 4095) & ~4095
    out = {"rounded_text": rt}
    if rt - text_size >= payload_size:
        out["payload"] = (text_size, text_size + payload_size)
    else:
        out["payload"] = None  # Luma would then overwrite a 'throwFatalError'-like function instead
    if rr - ro_size >= 39:
        out["path"] = (rt + ro_size, rt + ro_size + 39)
        out["path_address"] = ro_address + ro_size
    elif rd - data_size >= 39:
        out["path"] = (rt + rr + data_size, rt + rr + data_size + 39)
        out["path_address"] = data_address + data_size
    else:
        out["path"] = None
    return out


def make_branch(src: int, dst: int, link: bool = False) -> int:
    return (0xEB000000 if link else 0xEA000000) | (((dst - src - 8) >> 2) & 0xFFFFFF)


def luma_apply_layeredfs(code: bytearray, text_size: int, ro_size: int, data_size: int, ro_address: int,
                         data_address: int, payload_size: int, title_id: str) -> dict:
    """Simulate patchLayeredFs on the buffer: payload bytes (filled with 0xCC: the real payload is assembled
    code we do not need byte-exactly), path string, and the two hook branches. Returns what was written."""
    sym = luma_find_layeredfs_symbols(code, text_size)
    pl = luma_layeredfs_placement(text_size, ro_size, data_size, ro_address, data_address, payload_size)
    res = {"symbols": sym, "placement": pl, "ok": sym["found"] == 5 and pl["payload"] and pl["path"]}
    if not res["ok"]:
        return res  # Luma: patchLayeredFs returns false -> svcBreak(USERBREAK_ASSERT)
    a, b = pl["payload"]
    code[a:b] = b"\xCC" * (b - a)
    path = b"lf:" + f"/luma/titles/{title_id}/romfs".encode() + b"\0"
    pa, pb = pl["path"]
    code[pa:pa + len(path)] = path
    ofd, tof = sym["fsOpenFileDirectly"], sym["fsTryOpenFile"]
    struct.pack_into("<I", code, ofd, make_branch(ofd, a))
    struct.pack_into("<I", code, tof, make_branch(tof, a + 12))
    res["written"] = [(a, b, "payload"), (pa, pa + len(path), "path"), (ofd, ofd + 4, "hook fsOpenFileDirectly"),
                      (tof, tof + 4, "hook fsTryOpenFile")]
    return res


def self_test() -> list[str]:
    """Round-trip checks of the writers against the appliers on a synthetic buffer."""
    msgs = []
    src = bytes(range(256)) * 64
    tgt = bytearray(src)
    tgt[100:104] = b"\xAA\xBB\xCC\xDD"
    tgt[5000:5001] = b"\x00"
    tgt = bytes(tgt)
    assert crc32_bitwise(src[:4096]) == crc32(src[:4096])
    bps = bps_encode(src, tgt)
    buf = bytearray(src)
    assert luma_bps_apply(buf, len(buf), bps)[0] and bytes(buf) == tgt
    buf = bytearray(src)
    assert azahar_bps_apply(buf, bps) == "Success" and bytes(buf) == tgt
    bad = bytearray(src)
    bad[0] ^= 1
    snapshot = bytes(bad)
    assert luma_bps_apply(bad, len(bad), bps)[1].startswith("source_crc") and bytes(bad) == snapshot
    assert azahar_bps_apply(bad, bps) == "ErrorPatchesInvalidTitle" and bytes(bad) == snapshot
    ips = ips_encode(ips_records(src, tgt))
    for f in ("v134", "master", "azahar"):
        buf = bytearray(src)
        if f == "v134":
            ok = luma_ips_apply_v134(buf, len(buf), ips)[0]
        elif f == "master":
            ok = luma_ips_apply_master(buf, len(buf), len(buf), ips)[0]
        else:
            ok = azahar_ips_apply(buf, ips) == "Success"
        assert ok and bytes(buf) == tgt, f
    bps2 = bps_encode(src, tgt, [(96, 16), (5000, 1)])
    buf = bytearray(src)
    assert luma_bps_apply(buf, len(buf), bps2)[0] and bytes(buf) == tgt
    buf = bytearray(src)
    assert azahar_bps_apply(buf, bps2) == "Success" and bytes(buf) == tgt
    msgs.append("writer/applier self-test: IPS x3 appliers, BPS (diff and range writers) x2 appliers, "
                "CRC bitwise==zlib, BPS source-CRC refusal leaves the buffer untouched (Luma, Azahar): OK")
    return msgs
