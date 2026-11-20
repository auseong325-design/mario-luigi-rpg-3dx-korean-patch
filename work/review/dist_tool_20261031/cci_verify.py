"""Independent read-only check of a CCI (NCSD) or of a CIA's first NCCH. Uses no RomForge or tool code.

Checks every hash a 3DS loader relies on: NCCH exheader hash, logo hash, ExeFS file hashes and ExeFS
superblock hash, RomFS superblock hash and all three IVFC hash levels (master -> L1 -> L2 -> L3). Then walks
the level-3 RomFS directory/file tables and hashes every file. Layouts: 3dbrew "NCSD", "NCCH", "ExeFS",
"RomFS" (IVFC level 3 is stored first after the master hash, then level 1, then level 2, each block-aligned).

  cci_verify.py FILE [--expect-tree DIR] [--json OUT]
      --expect-tree DIR   compare the RomFS file tree (path -> sha256) with the files under DIR
As a module: verify(path) -> dict (also returns 'exefs_data' {name: bytes}, 'exheader' bytes, 'tree' {path: sha}).
"""
from __future__ import annotations

import argparse
import hashlib
import json
import struct
import sys
from pathlib import Path

NONE = 0xFFFFFFFF


def align(x: int, a: int) -> int:
    return (x + a - 1) // a * a


class Img:
    def __init__(self, path: Path):
        self.path = Path(path)
        self.f = self.path.open("rb")
        self.size = self.path.stat().st_size

    def read(self, off: int, n: int) -> bytes:
        self.f.seek(off)
        b = self.f.read(n)
        if len(b) != n:
            raise ValueError(f"short read at {off:#x}+{n:#x}")
        return b

    def sha(self, off: int, n: int, chunk: int = 8 << 20) -> bytes:
        h = hashlib.sha256()
        self.f.seek(off)
        left = n
        while left:
            b = self.f.read(min(chunk, left))
            if not b:
                raise ValueError("short read")
            h.update(b)
            left -= len(b)
        return h.digest()

    def close(self) -> None:
        self.f.close()


def locate_ncch(img: Img) -> dict:
    h = img.read(0, 0x200)
    if h[0x100:0x104] == b"NCSD":
        flags = h[0x188:0x190]
        unit = 0x200 << flags[6]
        parts = [struct.unpack_from("<II", h, 0x120 + 8 * i) for i in range(8)]
        return {"container": "NCSD", "ncch_off": parts[0][0] * unit,
                "partitions": [{"index": i, "offset": o * unit, "size": s * unit} for i, (o, s) in enumerate(parts) if s],
                "image_size": struct.unpack_from("<I", h, 0x104)[0] * unit, "file_size": img.size,
                "media_id": h[0x108:0x110][::-1].hex().upper(), "ncsd_flags": flags.hex(),
                "partition_fs_types": h[0x110:0x118].hex(), "partition_crypt_types": h[0x118:0x120].hex()}
    hdr, _typ, _ver, cert, tik, tmd, _meta, content = struct.unpack_from("<IHHIIIIQ", h, 0)
    if hdr == 0x2020:
        a = lambda x: align(x, 64)
        return {"container": "CIA", "ncch_off": a(hdr) + a(cert) + a(tik) + a(tmd), "content_size": content}
    raise ValueError("neither NCSD nor CIA")


def ivfc_check(img: Img, start: int) -> dict:
    hd = img.read(start, 0x60)
    if hd[:4] != b"IVFC" or struct.unpack_from("<I", hd, 4)[0] != 0x10000:
        raise ValueError("bad IVFC header")
    mh_size = struct.unpack_from("<I", hd, 8)[0]
    lv = []
    for i in range(3):
        loff, size, bs = struct.unpack_from("<QQI", hd, 0x0C + i * 0x18)
        lv.append({"logical_offset": loff, "size": size, "block": 1 << bs})
    master = img.read(start + 0x60, mh_size)
    l3 = align(0x60 + mh_size, lv[2]["block"])
    l1 = align(l3 + lv[2]["size"], lv[0]["block"])
    l2 = align(l1 + lv[0]["size"], lv[1]["block"])
    phys = [l1, l2, l3]
    parents = [master, img.read(start + l1, lv[0]["size"]), img.read(start + l2, lv[1]["size"])]
    out = {"master_hash_size": mh_size, "levels": []}
    for k in range(3):
        bs, size = lv[k]["block"], lv[k]["size"]
        n = (size + bs - 1) // bs
        bad, first_bad = 0, None
        img.f.seek(start + phys[k])
        for j in range(n):
            blk = img.f.read(min(bs, size - j * bs))
            if len(blk) < bs:
                blk += b"\0" * (bs - len(blk))
            if hashlib.sha256(blk).digest() != parents[k][j * 32:(j + 1) * 32]:
                bad += 1
                first_bad = j if first_bad is None else first_bad
        out["levels"].append({"level": k + 1, "physical_offset": phys[k], **lv[k], "blocks": n,
                              "bad_blocks": bad, "first_bad": first_bad})
    out["ok"] = all(x["bad_blocks"] == 0 for x in out["levels"])
    out["level3_abs"] = start + l3
    return out


def romfs_tree(img: Img, l3: int) -> dict[str, tuple[int, int]]:
    hd = img.read(l3, 0x28)
    (_hlen, _dht, _dhl, dm_off, dm_len, _fht, _fhl, fm_off, fm_len, data_off) = struct.unpack("<10I", hd)
    dm, fm = img.read(l3 + dm_off, dm_len), img.read(l3 + fm_off, fm_len)
    files: dict[str, tuple[int, int]] = {}

    def walk(doff: int, prefix: str, depth: int) -> None:
        if depth > 64:
            raise ValueError("directory loop")
        _p, _s, child, ff, _n, _nl = struct.unpack_from("<6I", dm, doff)
        f = ff
        while f != NONE:
            _fp, fsib, d_off, d_size, _fn, fnl = struct.unpack_from("<IIQQII", fm, f)
            name = fm[f + 0x20:f + 0x20 + fnl].decode("utf-16le")
            if prefix + name in files:
                raise ValueError(f"duplicate file {prefix + name}")
            files[prefix + name] = (l3 + data_off + d_off, d_size)
            f = fsib
        c = child
        while c != NONE:
            _cp, csib, _cc, _cf, _cn, cnl = struct.unpack_from("<6I", dm, c)
            walk(c, prefix + dm[c + 0x18:c + 0x18 + cnl].decode("utf-16le") + "/", depth + 1)
            c = csib

    walk(0, "", 0)
    return files


def verify(path: Path, expect_tree: Path | None = None) -> dict:
    img = Img(path)
    try:
        loc = locate_ncch(img)
        base = loc["ncch_off"]
        h = img.read(base, 0x200)
        if h[0x100:0x104] != b"NCCH":
            raise ValueError("no NCCH magic at partition 0")
        u32 = lambda o: struct.unpack_from("<I", h, o)[0]
        fl = h[0x188:0x190]
        unit = 0x200 << fl[6]
        r: dict = {"file": str(path), **loc,
                   "ncch": {"program_id": h[0x118:0x120][::-1].hex().upper(),
                            "partition_id": h[0x108:0x110][::-1].hex().upper(),
                            "product_code": h[0x150:0x160].split(b"\0")[0].decode("ascii", "replace"),
                            "maker_code": h[0x110:0x112].decode("ascii", "replace"),
                            "version": struct.unpack_from("<H", h, 0x112)[0], "flags": fl.hex(),
                            "no_crypto": bool(fl[7] & 4), "content_size": u32(0x104) * unit,
                            "exheader_size": u32(0x180),
                            "plain": [u32(0x190) * unit, u32(0x194) * unit], "logo": [u32(0x198) * unit, u32(0x19C) * unit],
                            "exefs": [u32(0x1A0) * unit, u32(0x1A4) * unit, u32(0x1A8) * unit],
                            "romfs": [u32(0x1B0) * unit, u32(0x1B4) * unit, u32(0x1B8) * unit]}}
        if not r["ncch"]["no_crypto"]:
            r["ok"] = False
            r["error"] = "encrypted NCCH: cannot verify without keys"
            return r
        checks: dict = {}
        exh_size = u32(0x180)
        exh = img.read(base + 0x200, 0x800) if exh_size else b""
        checks["exheader_hash"] = bool(exh_size) and hashlib.sha256(exh[:exh_size]).digest() == h[0x160:0x180]
        lo, ls = r["ncch"]["logo"]
        checks["logo_hash"] = (img.sha(base + lo, ls) == h[0x130:0x150]) if ls else None
        eo, es, ehr = r["ncch"]["exefs"]
        checks["exefs_superblock_hash"] = img.sha(base + eo, ehr) == h[0x1C0:0x1E0]
        eh = img.read(base + eo, 0x200)
        exefs, exefs_data = {}, {}
        for i in range(10):
            name = eh[i * 16:i * 16 + 8].rstrip(b"\0").decode("ascii", "replace")
            off, size = struct.unpack_from("<II", eh, i * 16 + 8)
            if not name:
                continue
            data = img.read(base + eo + 0x200 + off, size)
            want = eh[0xC0 + (9 - i) * 0x20:0xC0 + (10 - i) * 0x20]
            exefs[name] = {"offset": off, "size": size, "sha256": hashlib.sha256(data).hexdigest(),
                           "hash_ok": hashlib.sha256(data).digest() == want}
            exefs_data[name] = data
        checks["exefs_file_hashes"] = all(v["hash_ok"] for v in exefs.values())
        ro, rs, rhr = r["ncch"]["romfs"]
        checks["romfs_superblock_hash"] = img.sha(base + ro, rhr) == h[0x1E0:0x200]
        iv = ivfc_check(img, base + ro)
        checks["ivfc_levels"] = iv["ok"]
        tree_loc = romfs_tree(img, iv["level3_abs"])
        tree = {p: img.sha(o, n).hex() for p, (o, n) in sorted(tree_loc.items())}
        r.update(checks=checks, exefs=exefs, ivfc=iv, romfs_files=len(tree),
                 romfs_bytes=sum(n for _, n in tree_loc.values()))
        if expect_tree is not None:
            exp = {p.relative_to(expect_tree).as_posix(): hashlib.sha256(p.read_bytes()).hexdigest()
                   for p in Path(expect_tree).rglob("*") if p.is_file()}
            r["tree_vs_expected"] = {"expected_files": len(exp), "only_image": sorted(set(tree) - set(exp))[:20],
                                     "only_expected": sorted(set(exp) - set(tree))[:20],
                                     "bytes_differ": sorted(k for k in set(tree) & set(exp) if tree[k] != exp[k])[:20],
                                     "equal": tree == exp}
        r["ok"] = all(v is not False for v in checks.values()) and (
            expect_tree is None or r["tree_vs_expected"]["equal"])
        r["_exefs_data"], r["_exheader"], r["_tree"] = exefs_data, exh, tree
        return r
    finally:
        img.close()


def public(r: dict) -> dict:
    return {k: v for k, v in r.items() if not k.startswith("_")}


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("file")
    ap.add_argument("--expect-tree")
    ap.add_argument("--json")
    a = ap.parse_args(argv)
    r = verify(Path(a.file), Path(a.expect_tree) if a.expect_tree else None)
    sys.stdout.reconfigure(encoding="utf-8")
    text = json.dumps(public(r), ensure_ascii=False, indent=1)
    if a.json:
        Path(a.json).write_text(text, encoding="utf-8")
    print(text)
    return 0 if r.get("ok") else 1


if __name__ == "__main__":
    sys.exit(main())
