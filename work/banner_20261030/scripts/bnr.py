"""CBMD banner (CGFX + BCWAV) reader/writer for the HOME Menu banner work (wave 5, BANNER).

Read-only on originals. Library + CLI:
  bnr.py info <banner>            list CBMD slots, CGFX sections (models, textures, ...), textures
  bnr.py lzcheck <banner>         try LZ11 compressor variants against the original stream
"""
from __future__ import annotations

import hashlib
import json
import struct
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
sys.path.insert(0, str(ROOT / "scripts"))

# CGFX DATA block: 15 (count, self-relative DICT offset) pairs (measured: the first DICT starts
# right after 15 pairs at DATA+0x80 in both banners).
SECTION_NAMES = ["models", "textures", "luts", "materials", "shaders", "cameras", "lights", "fogs",
                 "environments", "skeletal_anims", "material_anims", "visibility_anims", "camera_anims",
                 "light_anims", "emitters"]


# ---------------------------------------------------------------- LZ11
def lz11_decompress(data: bytes, start: int = 0) -> tuple[bytes, int, list]:
    """Return (output, bytes consumed, token list). token = ('L', byte) or ('M', length, disp)."""
    p = start
    if data[p] != 0x11:
        raise ValueError("not LZ11")
    size = data[p + 1] | data[p + 2] << 8 | data[p + 3] << 16
    p += 4
    if size == 0:
        size = struct.unpack_from("<I", data, p)[0]
        p += 4
    out = bytearray()
    toks = []
    while len(out) < size:
        flags = data[p]
        p += 1
        for bit in range(8):
            if len(out) >= size:
                break
            if flags & (0x80 >> bit):
                b = data[p]
                ind = b >> 4
                if ind == 0:
                    length = (((b & 0xF) << 4) | (data[p + 1] >> 4)) + 0x11
                    disp = (((data[p + 1] & 0xF) << 8) | data[p + 2]) + 1
                    p += 3
                elif ind == 1:
                    length = (((b & 0xF) << 12) | (data[p + 1] << 4) | (data[p + 2] >> 4)) + 0x111
                    disp = (((data[p + 2] & 0xF) << 8) | data[p + 3]) + 1
                    p += 4
                else:
                    length = ind + 1
                    disp = (((b & 0xF) << 8) | data[p + 1]) + 1
                    p += 2
                if disp > len(out):
                    raise ValueError("bad disp")
                for _ in range(length):
                    out.append(out[-disp])
                toks.append(("M", length, disp))
            else:
                out.append(data[p])
                toks.append(("L", data[p]))
                p += 1
    return bytes(out), p - start, toks


def _enc_token(t) -> bytes:
    if t[0] == "L":
        return bytes([t[1]])
    _, length, disp = t
    d = disp - 1
    if length <= 0x10:
        return bytes([((length - 1) << 4) | (d >> 8), d & 0xFF])
    if length <= 0x110:
        l = length - 0x11
        return bytes([l >> 4, ((l & 0xF) << 4) | (d >> 8), d & 0xFF])
    l = length - 0x111
    return bytes([0x10 | (l >> 12), (l >> 4) & 0xFF, ((l & 0xF) << 4) | (d >> 8), d & 0xFF])


def lz11_pack(tokens, size: int) -> bytes:
    if size < 0x1000000:
        out = bytearray([0x11, size & 0xFF, (size >> 8) & 0xFF, (size >> 16) & 0xFF])
    else:
        out = bytearray([0x11, 0, 0, 0]) + struct.pack("<I", size)
    for i in range(0, len(tokens), 8):
        grp = tokens[i:i + 8]
        flag = 0
        body = bytearray()
        for k, t in enumerate(grp):
            if t[0] == "M":
                flag |= 0x80 >> k
            body += _enc_token(t)
        out.append(flag)
        out += body
    return bytes(out)


def lz11_tokens(data: bytes, window: int = 0x1000, max_len: int = 0x10110, prefer: str = "near",
                min_len: int = 3, min_disp: int = 1) -> list:
    """Greedy LZ11 tokeniser. prefer='near' keeps the smallest displacement among equal-length
    matches, 'far' the largest. Hash chains on 3-byte prefixes (exact, not approximate).
    min_disp=2 = 'VRAM-safe' (no displacement 1)."""
    n = len(data)
    head: dict[bytes, list[int]] = {}
    toks = []
    i = 0

    def add(pos):
        if pos + 3 <= n:
            head.setdefault(data[pos:pos + 3], []).append(pos)

    while i < n:
        best_len, best_disp = 0, 0
        if i + min_len <= n:
            cands = head.get(data[i:i + 3], ())
            lim = min(max_len, n - i)
            # iterate candidates from nearest to farthest
            for j in reversed(cands):
                d = i - j
                if d > window:
                    break
                if d < min_disp:
                    continue
                l = 3
                while l < lim and data[j + l] == data[i + l]:
                    l += 1
                if l > best_len or (l == best_len and prefer == "far"):
                    best_len, best_disp = l, d
                    if l == lim and prefer == "near":
                        break
        if best_len >= min_len:
            toks.append(("M", best_len, best_disp))
            for k in range(best_len):
                add(i + k)
            i += best_len
        else:
            toks.append(("L", data[i]))
            add(i)
            i += 1
    return toks


# ---------------------------------------------------------------- CBMD
def parse_cbmd(b: bytes) -> dict:
    assert b[:4] == b"CBMD", b[:4]
    offs = list(struct.unpack_from("<14I", b, 8))
    bcwav = struct.unpack_from("<I", b, 0x84)[0]
    cg_off = offs[0]
    cgfx, used, toks = lz11_decompress(b, cg_off)
    return {"offsets": offs, "bcwav_off": bcwav, "cgfx_off": cg_off, "cgfx_comp_len": used,
            "cgfx": cgfx, "tokens": toks, "pad_after_cgfx": b[cg_off + used:bcwav] if bcwav else b"",
            "bcwav": b[bcwav:] if bcwav else b"", "header": b[:cg_off]}


def build_cbmd(header: bytes, comp_cgfx: bytes, bcwav: bytes, align: int) -> bytes:
    """Rebuild a single-CGFX CBMD: header (0x88 incl. offsets), compressed CGFX, zero pad to
    `align`, BCWAV. Only the BCWAV offset field (0x84) is recomputed."""
    out = bytearray(header)
    out += comp_cgfx
    while len(out) % align:
        out.append(0)
    struct.pack_into("<I", out, 0x84, len(out))
    out += bcwav
    return bytes(out)


# ---------------------------------------------------------------- CGFX
def rel(b: bytes, off: int) -> int:
    return off + struct.unpack_from("<I", b, off)[0]


def cstr(b: bytes, off: int) -> str:
    return b[off:b.index(b"\0", off)].decode("ascii", "replace")


def dict_entries(b: bytes, dic: int) -> list[tuple[str, int]]:
    assert b[dic:dic + 4] == b"DICT", (hex(dic), b[dic:dic + 4])
    n = struct.unpack_from("<I", b, dic + 8)[0]
    res = []
    for k in range(n):
        node = dic + 12 + 16 * (k + 1)
        name_rel = struct.unpack_from("<I", b, node + 8)[0]
        name = cstr(b, node + 8 + name_rel) if name_rel else ""
        res.append((name, rel(b, node + 12)))
    return res


def cgfx_sections(b: bytes) -> dict:
    assert b[:4] == b"CGFX", b[:4]
    hsize = struct.unpack_from("<H", b, 6)[0]
    rev, fsize, nsec = struct.unpack_from("<III", b, 8)
    assert b[hsize:hsize + 4] == b"DATA"
    res = {"header_size": hsize, "revision": hex(rev), "file_size": fsize, "n_blocks": nsec,
           "data_size": struct.unpack_from("<I", b, hsize + 4)[0]}
    secs = {}
    for k, nm in enumerate(SECTION_NAMES):
        cnt = struct.unpack_from("<I", b, hsize + 8 + 8 * k)[0]
        if cnt:
            dic = rel(b, hsize + 8 + 8 * k + 4)
            secs[nm] = [{"name": n, "off": o, "magic": b[o + 4:o + 8].decode("ascii", "replace")}
                        for n, o in dict_entries(b, dic)]
    res["sections"] = secs
    imag = b.find(b"IMAG", hsize)
    res["imag_off"] = imag
    if imag >= 0:
        res["imag_size"] = struct.unpack_from("<I", b, imag + 4)[0]
    return res


def cgfx_textures(b: bytes) -> list[dict]:
    import libtex3ds as T
    secs = cgfx_sections(b)["sections"]
    res = []
    for e in secs.get("textures", []):
        tx = e["off"]
        assert b[tx + 4:tx + 8] == b"TXOB"
        flags = struct.unpack_from("<I", b, tx)[0]
        h, w = struct.unpack_from("<II", b, tx + 0x18)
        glfmt, gltype, mips = struct.unpack_from("<III", b, tx + 0x20)
        fmt = struct.unpack_from("<I", b, tx + 0x34)[0]
        img = None
        for f in range(0x38, 0x60, 4):
            q = rel(b, tx + f)
            if 0 < q < len(b) - 16 and struct.unpack_from("<II", b, q) == (h, w):
                dlen = struct.unpack_from("<I", b, q + 8)[0]
                img = {"struct_off": q, "ptr_field": tx + f, "data_off": rel(b, q + 12), "data_len": dlen}
                break
        res.append({"name": e["name"], "txob_off": tx, "flags": hex(flags), "w": w, "h": h,
                    "gl_format": hex(glfmt), "gl_type": hex(gltype), "mipmaps": mips, "pica_format": fmt,
                    "fmt": T.PICA_FORMATS.get(fmt, str(fmt)), "img": img})
    return res


def strings_in(b: bytes, lo: int, hi: int, minlen: int = 4) -> list[str]:
    out, cur = [], bytearray()
    for c in b[lo:hi]:
        if 32 <= c < 127:
            cur.append(c)
        else:
            if c == 0 and len(cur) >= minlen:
                out.append(cur.decode())
            cur = bytearray()
    return out


def info(path: Path) -> dict:
    import libtex3ds as T  # noqa: F401
    raw = path.read_bytes()
    c = parse_cbmd(raw)
    cg = c["cgfx"]
    s = cgfx_sections(cg)
    tex = cgfx_textures(cg)
    return {"file": str(path), "size": len(raw), "sha256": hashlib.sha256(raw).hexdigest(),
            "cbmd_offsets": [hex(o) for o in c["offsets"]], "bcwav_off": hex(c["bcwav_off"]),
            "cgfx_comp_len": c["cgfx_comp_len"], "pad_after_cgfx_len": len(c["pad_after_cgfx"]),
            "pad_after_cgfx_nonzero": any(c["pad_after_cgfx"]), "cgfx_size": len(cg),
            "bcwav_size": len(c["bcwav"]), "bcwav_magic": c["bcwav"][:4].decode("ascii", "replace"),
            "cgfx": {k: v for k, v in s.items() if k != "sections"},
            "sections": {k: [(e["name"], e["magic"], hex(e["off"])) for e in v] for k, v in s["sections"].items()},
            "textures": tex}


def main(argv: list[str]) -> int:
    cmd = argv[1]
    if cmd == "info":
        res = [info(Path(p)) for p in argv[2:]]
        print(json.dumps(res, indent=1, ensure_ascii=False))
        return 0
    if cmd == "lzcheck":
        raw = Path(argv[2]).read_bytes()
        c = parse_cbmd(raw)
        orig = raw[c["cgfx_off"]:c["cgfx_off"] + c["cgfx_comp_len"]]
        print("orig first tokens", c["tokens"][:40])
        variants = [(p, md) for md in (2, 1) for p in ("near", "far")]
        if len(argv) > 3:
            variants = [(argv[3], int(argv[4]))]
        for prefer, md in variants:
            toks = lz11_tokens(c["cgfx"], prefer=prefer, min_disp=md)
            comp = lz11_pack(toks, len(c["cgfx"]))
            first = next((i for i, (a, b2) in enumerate(zip(toks, c["tokens"])) if a != b2), None)
            print(prefer, "min_disp", md, "len", len(comp), "orig", len(orig), "identical", comp == orig,
                  "ntok", len(toks), len(c["tokens"]), "first_diff_token", first,
                  (toks[first - 2:first + 3], c["tokens"][first - 2:first + 3]) if first is not None else "")
        return 0
    raise SystemExit("unknown command")


if __name__ == "__main__":
    sys.exit(main(sys.argv))
