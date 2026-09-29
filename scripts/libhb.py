"""Giant-battle UI archives (romfs/HB/**/*.arc.z): LZH8 -> SARC (hash-only, no names) -> BFLIM.

    comp  = romfs_path("HB/JP_ja/yesno.arc.z").read_bytes()
    sarc  = unpack(comp)                         # LZH8 decode
    ents  = sarc_entries(sarc)                   # [{hash, start, end, name?}], names from layouts
    sarc2 = replace_by_hash(sarc, {hash: bflim}) # in place, same sizes
    comp2 = pack(comp, sarc2)                    # original bytes when unchanged, else LZH8 encode (checked)

SARC here has no SFNT names (attr flag clear); files are looked up by the name hash
(key 101) of "timg/<texture>.bflim". Texture names come from the layouts' txl1 and the
animations' pai1 lists, so every texture used by a layout or a pattern animation gets its name.
"""
from __future__ import annotations

import hashlib
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import libhb_lzh8 as LZ  # noqa: E402
from lib3dx import ROOT, romfs_path  # noqa: E402

HB_JP = ["cyorometer", "demoskip", "dpunch", "fireball", "get", "kyusai", "punch", "result_win",
         "rotation", "start", "touchpen", "ui_fa", "value", "yesno"]
HB_COMMON = ["battle_guide", "life1", "life2", "life3", "life4", "parts", "primitive", "result", "ui"]


def arc_rels() -> list[str]:
    return [f"HB/JP_ja/{n}.arc.z" for n in HB_JP] + [f"HB/{n}.arc.z" for n in HB_COMMON]


def sarc_hash(name: str, key: int = 101) -> int:
    v = 0
    for c in name.encode("utf-8"):
        v = (v * key + c) & 0xFFFFFFFF
    return v


def unpack(comp: bytes) -> bytes:
    return LZ.decompress(comp)[0]


def pack(orig_comp: bytes, sarc: bytes) -> bytes:
    """Original compressed bytes if the content is unchanged, otherwise a verified LZH8 encode."""
    if unpack(orig_comp) == sarc:
        return orig_comp
    return LZ.compress_checked(sarc)


def sarc_entries(b: bytes) -> list[dict]:
    if b[:4] != b"SARC":
        raise ValueError("not a SARC")
    hdr_len, bom, size, data_off = struct.unpack_from("<HHII", b, 4)
    if b[hdr_len:hdr_len + 4] != b"SFAT":
        raise ValueError("SFAT missing")
    _, count, key = struct.unpack_from("<HHI", b, hdr_len + 4)
    out = []
    for i in range(count):
        h, attr, s, e = struct.unpack_from("<IIII", b, hdr_len + 12 + i * 16)
        out.append({"hash": h, "attr": attr, "start": data_off + s, "end": data_off + e, "index": i})
    return out


def replace_by_hash(b: bytes, repl: dict[int, bytes]) -> bytes:
    out = bytearray(b)
    idx = {e["hash"]: e for e in sarc_entries(b)}
    for h, data in repl.items():
        e = idx[h]
        if len(data) != e["end"] - e["start"]:
            raise ValueError(f"{h:08x}: size {len(data)} != {e['end'] - e['start']}")
        out[e["start"]:e["end"]] = data
    return bytes(out)


# ------------------------------------------------------------------ layout name lists
def _sections(b: bytes):
    _m, _bom, hl, _ver, _fs, ns = struct.unpack_from("<4sHHIIH", b, 0)
    p = hl
    for _ in range(ns):
        m, sz = struct.unpack_from("<4sI", b, p)
        yield m, b[p:p + sz]
        p += sz


def _strings(sec: bytes, count: int, base: int) -> list[str]:
    offs = struct.unpack_from(f"<{count}I", sec, base)
    return [sec[base + o:sec.index(b"\0", base + o)].decode("utf-8") for o in offs]


def texture_names(b: bytes) -> list[str]:
    """Texture file names referenced by a FLYT (txl1) or FLAN (pai1)."""
    names = []
    if b[:4] == b"FLYT":
        for m, sec in _sections(b):
            if m == b"txl1":
                n = struct.unpack_from("<H", sec, 8)[0]
                names += _strings(sec, n, 12)
    elif b[:4] == b"FLAN":
        for m, sec in _sections(b):
            if m == b"pai1":
                n = struct.unpack_from("<H", sec, 0x0C)[0]
                names += _strings(sec, n, 0x14)
    return names


_NAME_CACHE: dict[int, str] | None = None


def name_table() -> dict[int, str]:
    """hash -> 'timg/<name>.bflim' for every texture name used by any HB layout or animation."""
    global _NAME_CACHE
    if _NAME_CACHE is None:
        t = {}
        for rel in arc_rels():
            sarc = unpack(romfs_path(rel).read_bytes())
            for e in sarc_entries(sarc):
                d = sarc[e["start"]:e["end"]]
                if d[:4] in (b"FLYT", b"FLAN"):
                    for n in texture_names(d):
                        p = "timg/" + n
                        t[sarc_hash(p)] = p
        _NAME_CACHE = t
    return _NAME_CACHE


def is_bflim(d: bytes) -> bool:
    return len(d) >= 0x28 and d[-0x28:-0x24] == b"FLIM"


def sha16(d: bytes) -> str:
    return hashlib.sha1(d).hexdigest()[:16]
