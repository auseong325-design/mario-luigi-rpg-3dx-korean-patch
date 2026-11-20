"""CIA / TMD / NCCH / ExeFS reader and banner-replacing rebuilder (read-only on the input CIA).

  cia.py info  <cia>                         parse + verify every hash, compare ExeFS with exefs/
  cia.py build <cia> <banner> <out|->        rebuild with this ExeFS banner. '-' = do not write,
                                             only stream-hash the output and compare with <cia>
Layout rules (3dbrew CIA/Title_metadata/NCCH/ExeFS): CIA sections aligned to 64 bytes; TMD and
CIA header fields big/little-endian as documented; NCCH media unit 0x200 << flags[6].
Rebuild recomputes (never copies): ExeFS header entry size + SHA-256 of the banner, NCCH ExeFS
superblock hash, TMD content size + SHA-256, TMD content-info-record hash. ExeFS file offsets
are kept (the banner gets more zero padding if it shrinks; it must fit its old 0x200 slot), so
the ExeFS, NCCH and CIA sizes stay the same. Signatures are kept as they are.
"""
from __future__ import annotations

import hashlib
import json
import struct
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
CHUNK = 8 << 20


def align(x: int, a: int) -> int:
    return (x + a - 1) // a * a


SIG_SIZES = {0x010000: (0x200, 0x3C), 0x010001: (0x100, 0x3C), 0x010002: (0x3C, 0x40),
             0x010003: (0x200, 0x3C), 0x010004: (0x100, 0x3C), 0x010005: (0x3C, 0x40)}


class Cia:
    def __init__(self, path: Path):
        self.path = Path(path)
        with open(self.path, "rb") as f:
            hdr = f.read(0x2020)
            (self.hdr_size, self.type, self.version, self.cert_size, self.tik_size, self.tmd_size,
             self.meta_size, self.content_size) = struct.unpack_from("<IHHIIIIQ", hdr, 0)
            self.bitmap = hdr[0x20:0x2020]
            self.off_cert = align(self.hdr_size, 64)
            self.off_tik = align(self.off_cert + self.cert_size, 64)
            self.off_tmd = align(self.off_tik + self.tik_size, 64)
            self.off_content = align(self.off_tmd + self.tmd_size, 64)
            self.off_meta = align(self.off_content + self.content_size, 64)
            f.seek(self.off_tmd)
            self.tmd = f.read(self.tmd_size)
            f.seek(self.off_tik)
            self.tik = f.read(self.tik_size)
        self.file_size = self.path.stat().st_size
        self._parse_tmd()

    def _parse_tmd(self):
        t = self.tmd
        st = struct.unpack_from(">I", t, 0)[0]
        sig, pad = SIG_SIZES[st]
        self.tmd_sig_type = st
        h = 4 + sig + pad
        self.tmd_hdr = h
        self.title_id = struct.unpack_from(">Q", t, h + 0x4C)[0]
        self.title_version = struct.unpack_from(">H", t, h + 0x9C)[0]
        self.content_count = struct.unpack_from(">H", t, h + 0x9E)[0]
        self.info_hash_off = h + 0xA4
        self.info_off = h + 0xC4
        self.chunk_off = self.info_off + 64 * 0x24
        self.chunks = []
        pos = 0
        for i in range(self.content_count):
            o = self.chunk_off + 0x30 * i
            cid, idx, ctype, csize = struct.unpack_from(">IHHQ", t, o)
            self.chunks.append({"id": cid, "index": idx, "type": ctype, "size": csize,
                                "sha256": t[o + 0x10:o + 0x30].hex(), "rec_off": o, "cia_off": self.off_content + pos})
            pos += align(csize, 64) if i < self.content_count - 1 else csize
        self.issuer = t[h:h + 0x40].rstrip(b"\0").decode("ascii", "replace")

    def read(self, off: int, n: int) -> bytes:
        with open(self.path, "rb") as f:
            f.seek(off)
            return f.read(n)


def info_hash_check(tmd: bytes, c: Cia) -> dict:
    """content info records: hash over the following k chunk records; header hash over 64 records."""
    res = {}
    recs = tmd[c.info_off:c.info_off + 64 * 0x24]
    res["info_records_hash_ok"] = hashlib.sha256(recs).digest() == tmd[c.info_hash_off:c.info_hash_off + 0x20]
    ok = True
    for i in range(64):
        o = c.info_off + 0x24 * i
        first, count = struct.unpack_from(">HH", tmd, o)
        if count == 0:
            continue
        data = tmd[c.chunk_off + 0x30 * first:c.chunk_off + 0x30 * (first + count)]
        ok &= hashlib.sha256(data).digest() == tmd[o + 4:o + 0x24]
    res["chunk_records_hash_ok"] = ok
    return res


def ncch_info(h: bytes) -> dict:
    assert h[0x100:0x104] == b"NCCH", h[0x100:0x104]
    flags = h[0x188:0x190]
    mu = 0x200 << flags[6]
    g = lambda o: struct.unpack_from("<I", h, o)[0]
    return {"content_size": g(0x104) * mu, "program_id": hex(struct.unpack_from("<Q", h, 0x118)[0]),
            "partition_id": hex(struct.unpack_from("<Q", h, 0x108)[0]),
            "product_code": h[0x150:0x160].rstrip(b"\0").decode(), "flags": flags.hex(), "media_unit": mu,
            "no_crypto": bool(flags[7] & 4), "fixed_key": bool(flags[7] & 1), "seed_crypto": bool(flags[7] & 0x20),
            "exheader_size": g(0x180), "logo": (g(0x198) * mu, g(0x19C) * mu), "plain": (g(0x190) * mu, g(0x194) * mu),
            "exefs_off": g(0x1A0) * mu, "exefs_size": g(0x1A4) * mu, "exefs_hash_size": g(0x1A8) * mu,
            "romfs_off": g(0x1B0) * mu, "romfs_size": g(0x1B4) * mu, "romfs_hash_size": g(0x1B8) * mu,
            "exefs_hash": h[0x1C0:0x1E0].hex(), "romfs_hash": h[0x1E0:0x200].hex()}


def exefs_entries(hdr: bytes) -> list[dict]:
    res = []
    for i in range(10):
        name = hdr[i * 16:i * 16 + 8].rstrip(b"\0").decode("ascii", "replace")
        off, size = struct.unpack_from("<II", hdr, i * 16 + 8)
        if not name and not size:
            continue
        hsh = hdr[0xC0 + (9 - i) * 0x20:0xC0 + (10 - i) * 0x20]
        res.append({"slot": i, "name": name, "off": off, "size": size, "sha256": hsh.hex()})
    return res


def stream_sha(path: Path, off: int, n: int) -> str:
    h = hashlib.sha256()
    with open(path, "rb") as f:
        f.seek(off)
        left = n
        while left:
            b = f.read(min(CHUNK, left))
            if not b:
                raise IOError("short read")
            h.update(b)
            left -= len(b)
    return h.hexdigest()


def info(path: Path) -> dict:
    c = Cia(path)
    rep = {"file": str(path), "file_size": c.file_size, "header_size": c.hdr_size, "cert_size": c.cert_size,
           "ticket_size": c.tik_size, "tmd_size": c.tmd_size, "meta_size": c.meta_size,
           "content_size": c.content_size, "offsets": {"cert": c.off_cert, "ticket": c.off_tik, "tmd": c.off_tmd,
                                                      "content": c.off_content, "meta": c.off_meta},
           "end_check": (c.off_meta + c.meta_size) if c.meta_size else (c.off_content + c.content_size),
           "title_id": f"{c.title_id:016X}", "title_version": c.title_version, "tmd_sig_type": hex(c.tmd_sig_type),
           "tmd_issuer": c.issuer, "ticket_issuer": c.tik[0x140:0x180].rstrip(b"\0").decode("ascii", "replace"),
           "content_count": c.content_count, "chunks": c.chunks}
    rep.update(info_hash_check(c.tmd, c))
    ch = c.chunks[0]
    rep["content0_encrypted_flag"] = bool(ch["type"] & 1)
    nh = c.read(ch["cia_off"], 0x200)
    n = ncch_info(nh)
    rep["ncch"] = n
    ex_hdr = c.read(ch["cia_off"] + n["exefs_off"], 0x200)
    rep["exefs_superblock_hash_ok"] = hashlib.sha256(c.read(ch["cia_off"] + n["exefs_off"], n["exefs_hash_size"])).hexdigest() == n["exefs_hash"]
    ents = exefs_entries(ex_hdr)
    for e in ents:
        data = c.read(ch["cia_off"] + n["exefs_off"] + 0x200 + e["off"], e["size"])
        e["hash_ok"] = hashlib.sha256(data).hexdigest() == e["sha256"]
        local = ROOT / "exefs" / e["name"]
        if local.exists():
            e["equals_project_exefs_file"] = local.read_bytes() == data
        # padding after the file up to the next file / end of ExeFS must be zero
    rep["exefs"] = ents
    ends = sorted([(e["off"], e["off"] + e["size"]) for e in ents])
    rep["exefs_packed"] = all(align(ends[i][1], 0x200) == ends[i + 1][0] for i in range(len(ends) - 1))
    rep["exefs_data_end"] = align(ends[-1][1], 0x200) + 0x200
    rep["romfs_superblock_hash_ok"] = hashlib.sha256(c.read(ch["cia_off"] + n["romfs_off"], n["romfs_hash_size"])).hexdigest() == n["romfs_hash"]
    rep["content0_sha256"] = stream_sha(path, ch["cia_off"], ch["size"])
    rep["content0_hash_ok"] = rep["content0_sha256"] == ch["sha256"]
    rep["file_sha256"] = stream_sha(path, 0, c.file_size)
    return rep


def build(path: Path, banner: bytes, out: Path | None) -> dict:
    """Rebuild the CIA with ExeFS:/banner = banner. Returns a report incl. output SHA-256 and the
    exact list of changed byte ranges (relative to the input)."""
    c = Cia(path)
    ch = c.chunks[0]
    base = ch["cia_off"]
    nh = bytearray(c.read(base, 0x200))
    n = ncch_info(bytes(nh))
    exo = base + n["exefs_off"]
    exh = bytearray(c.read(exo, 0x200))
    ents = exefs_entries(bytes(exh))
    ban = next(e for e in ents if e["name"] == "banner")
    nxt = min([e["off"] for e in ents if e["off"] > ban["off"]] + [n["exefs_size"] - 0x200])
    if ban["off"] + len(banner) > nxt:
        raise SystemExit(f"banner {len(banner)} B does not fit its ExeFS slot ({nxt - ban['off']} B)")
    # ExeFS header: size + hash of the banner entry (recomputed)
    struct.pack_into("<I", exh, ban["slot"] * 16 + 12, len(banner))
    exh[0xC0 + (9 - ban["slot"]) * 0x20:0xC0 + (10 - ban["slot"]) * 0x20] = hashlib.sha256(banner).digest()
    # banner slot bytes: banner + zero padding up to the next file
    slot = bytes(banner) + bytes(nxt - ban["off"] - len(banner))
    # NCCH: ExeFS superblock hash over the first exefs_hash_size bytes (the header is 0x200)
    assert n["exefs_hash_size"] == 0x200, n["exefs_hash_size"]
    nh[0x1C0:0x1E0] = hashlib.sha256(bytes(exh)).digest()
    patches = {base: bytes(nh), exo: bytes(exh), exo + 0x200 + ban["off"]: slot}   # absolute CIA offsets

    def content_stream():
        """yield content-0 bytes with patches applied."""
        with open(path, "rb") as f:
            pos = base
            end = base + ch["size"]
            pts = sorted(patches.items())
            f.seek(pos)
            while pos < end:
                nxtp = next(((o, d) for o, d in pts if o + len(d) > pos), None)
                if nxtp and nxtp[0] <= pos:
                    o, d = nxtp
                    piece = d[pos - o:]
                    f.seek(pos + len(piece))
                    pos += len(piece)
                    yield piece
                    continue
                lim = min(end, nxtp[0] if nxtp else end, pos + CHUNK)
                b = f.read(lim - pos)
                pos += len(b)
                yield b

    hsh = hashlib.sha256()
    for b in content_stream():
        hsh.update(b)
    new_content_hash = hsh.digest()
    tmd = bytearray(c.tmd)
    ro = ch["rec_off"]
    struct.pack_into(">Q", tmd, ro + 8, ch["size"])                  # size unchanged by design
    tmd[ro + 0x10:ro + 0x30] = new_content_hash
    for i in range(64):                                                 # info records
        o = c.info_off + 0x24 * i
        first, count = struct.unpack_from(">HH", tmd, o)
        if count:
            tmd[o + 4:o + 0x24] = hashlib.sha256(bytes(tmd[c.chunk_off + 0x30 * first:c.chunk_off + 0x30 * (first + count)])).digest()
    tmd[c.info_hash_off:c.info_hash_off + 0x20] = hashlib.sha256(bytes(tmd[c.info_off:c.info_off + 64 * 0x24])).digest()
    tmd_patch = {c.off_tmd: bytes(tmd)}

    # write / hash the whole output: input stream with tmd + content patches
    allp = dict(patches)
    allp.update(tmd_patch)
    pts = sorted(allp.items())
    out_h = hashlib.sha256()
    changed = []
    fo = open(out, "wb") if out else None
    try:
        with open(path, "rb") as f:
            pos = 0
            size = c.file_size
            while pos < size:
                nxtp = next(((o, d) for o, d in pts if o + len(d) > pos), None)
                if nxtp and nxtp[0] <= pos:
                    o, d = nxtp
                    piece = d[pos - o:]
                    f.seek(pos)
                    orig = f.read(len(piece))
                    if orig != piece:
                        # record changed sub-ranges
                        i = 0
                        while i < len(piece):
                            if piece[i] != orig[i]:
                                j = i
                                while j < len(piece) and piece[j] != orig[j]:
                                    j += 1
                                changed.append([pos + i, pos + j])
                                i = j
                            else:
                                i += 1
                    pos += len(piece)
                    out_h.update(piece)
                    if fo:
                        fo.write(piece)
                    continue
                lim = min(size, nxtp[0] if nxtp else size, pos + CHUNK)
                f.seek(pos)
                b = f.read(lim - pos)
                pos += len(b)
                out_h.update(b)
                if fo:
                    fo.write(b)
    finally:
        if fo:
            fo.close()
    # merge adjacent ranges
    merged = []
    for a, b in changed:
        if merged and a <= merged[-1][1] + 16:
            merged[-1][1] = max(merged[-1][1], b)
        else:
            merged.append([a, b])
    labels = []
    for a, b in merged:
        if c.off_tmd <= a < c.off_tmd + c.tmd_size:
            what = "TMD"
        elif base <= a < base + 0x200:
            what = "NCCH header"
        elif exo <= a < exo + 0x200:
            what = "ExeFS header"
        elif exo + 0x200 + ban["off"] <= a < exo + 0x200 + nxt:
            what = "ExeFS banner slot"
        else:
            what = "OTHER"
        labels.append({"range": [hex(a), hex(b)], "bytes": b - a, "where": what})
    return {"input": str(path), "output": str(out) if out else None, "output_sha256": out_h.hexdigest(),
            "output_size": c.file_size, "banner_size": len(banner), "banner_slot": [ban["off"], nxt],
            "new_content0_sha256": new_content_hash.hex(), "old_content0_sha256": ch["sha256"],
            "new_exefs_hash": nh[0x1C0:0x1E0].hex(), "changed_ranges": labels}


def main(argv: list[str]) -> int:
    if argv[1] == "info":
        rep = info(Path(argv[2]))
        print(json.dumps(rep, indent=1))
        if len(argv) > 3:
            Path(argv[3]).write_text(json.dumps(rep, indent=1), encoding="utf-8")
        return 0
    if argv[1] == "build":
        out = None if argv[4] == "-" else Path(argv[4])
        rep = build(Path(argv[2]), Path(argv[3]).read_bytes(), out)
        print(json.dumps(rep, indent=1))
        if len(argv) > 5:
            Path(argv[5]).write_text(json.dumps(rep, indent=1), encoding="utf-8")
        return 0
    raise SystemExit("usage")


if __name__ == "__main__":
    sys.exit(main(sys.argv))
