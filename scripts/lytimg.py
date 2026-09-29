"""Layout images (Lyt/*.dat): BG4 -> BLZ -> SARC -> BFLIM, shared by the image workstreams.

Library:
    for t in iter_textures("3DX"):            # t.game, t.dat, t.entry, t.file, t.data (BFLIM bytes)
        info = parse_bflim(t.data)            # fmt, w, h, flags, stored (sw, sh), ...
        rgba = bflim_to_rgba(t.data)          # logical image, uint8 (h, w, 4), top row first
        new  = rgba_to_bflim(t.data, rgba2)   # same size/format/flags -> drop-in replacement
    sarc2 = sarc_replace(sarc_bytes, {"timg/x.bflim": new})   # in place; sizes must not change

3DS BFLIM storage (verified on MLyt name_MARIO9624_00_JP_ja / SHOP_BG_U_05): the stored image
is (p2(h) x p2(w)) and the logical picture is rot90(stored) for flags 4 and stored.T for
flags 8 (all ETC textures here), cropped to the top-left w x h. Padding columns/rows repeat
the last logical column/row; rgba_to_bflim() rebuilds them the same way.

CLI:
    python scripts/lytimg.py extract [--game 3DX|1DX]   -> work/img/lyt/<game>/<dat>/<entry>/<name>.png
                                                          + work/img/lyt_manifest.json
    python scripts/lytimg.py check                      -> decode/encode byte round trip of every
                                                          lossless texture (proves the codec)
"""

from __future__ import annotations

import argparse
import hashlib
import json
import struct
import sys
from dataclasses import dataclass
from pathlib import Path

import numpy as np

sys.path.insert(0, str(Path(__file__).resolve().parent))
import libtex3ds as T  # noqa: E402
from lib3dx import ROOT, blz_decompress, read_bg4, romfs_path  # noqa: E402

DX1_ROMFS = ROOT / "ml 1dx" / "3romfs"
LYT_DATS = {"3DX": ["BLyt", "FLyt", "GLyt", "KLyt", "MLyt", "SLyt"],
            "1DX": ["BLyt", "FLyt", "GLyt", "MLyt", "SLyt"]}
IMG_ROOT = ROOT / "work" / "img"


def dat_path(game: str, dat: str) -> Path:
    return romfs_path(f"Lyt/JP/{dat}.dat") if game == "3DX" else DX1_ROMFS / f"Lyt/KR/{dat}.dat"


# --------------------------------------------------------------------- SARC
def sarc_list(b: bytes) -> list[tuple[str, int, int]]:
    """[(path, start, end)] with absolute offsets into the SARC bytes."""
    if b[:4] != b"SARC":
        raise ValueError("not a SARC archive")
    hdr_len, _bom, _size, data_off = struct.unpack_from("<HHII", b, 4)
    p = hdr_len
    if b[p:p + 4] != b"SFAT":
        raise ValueError("SFAT missing")
    _, count, _hk = struct.unpack_from("<HHI", b, p + 4)
    names_base = p + 12 + count * 16 + 8
    out = []
    for i in range(count):
        _h, attr, s, e = struct.unpack_from("<IIII", b, p + 12 + i * 16)
        name = ""
        if attr & 0x01000000:
            no = names_base + (attr & 0xFFFF) * 4
            name = b[no:b.find(b"\0", no)].decode("utf-8")
        out.append((name, data_off + s, data_off + e))
    return out


def sarc_replace(b: bytes, repl: dict[str, bytes]) -> bytes:
    """Replace files in place. Every replacement must keep the original size."""
    out = bytearray(b)
    idx = {n: (s, e) for n, s, e in sarc_list(b)}
    for name, data in repl.items():
        s, e = idx[name]
        if len(data) != e - s:
            raise ValueError(f"{name}: size {len(data)} != original {e - s}")
        out[s:e] = data
    return bytes(out)


# --------------------------------------------------------------------- BFLIM
def parse_bflim(b: bytes) -> dict:
    ft = b[-0x28:]
    if ft[:4] != b"FLIM" or ft[0x14:0x18] != b"imag":
        raise ValueError("not a BFLIM")
    _ssz, w, h, align, fmt, flags, dsz = struct.unpack_from("<IHHHBBI", ft, 0x18)
    name = T.FLIM_FORMATS[fmt]

    def p2(v):  # stored sides are powers of two, at least 8 (16 for ETC1; ETC1A4 8x8 exists)
        return max(16 if name == "ETC1" else 8, 1 << (int(v) - 1).bit_length())
    sw, sh = (p2(h), p2(w)) if flags in (4, 8) else (p2(w), p2(h))
    if T.data_size(name, sw, sh) != dsz:
        raise ValueError(f"unexpected stored size: {w}x{h} {name} flags {flags} data {dsz}")
    return {"fmt": name, "w": w, "h": h, "flags": flags, "align": align, "stored": (sw, sh), "dsz": dsz}


def _to_logical(stored: np.ndarray, flags: int) -> np.ndarray:
    if flags == 4:
        return np.rot90(stored, 1)
    if flags == 8:
        return stored.transpose(1, 0, 2)
    return stored[::-1]


def _to_stored(full: np.ndarray, flags: int) -> np.ndarray:
    if flags == 4:
        return np.rot90(full, -1)
    if flags == 8:
        return full.transpose(1, 0, 2)
    return full[::-1]


def bflim_full(b: bytes) -> np.ndarray:
    """Whole stored texture in logical orientation (padding included)."""
    i = parse_bflim(b)
    sw, sh = i["stored"]
    return np.ascontiguousarray(_to_logical(T.decode(b[:i["dsz"]], i["fmt"], sw, sh, flip=False), i["flags"]))


def bflim_to_rgba(b: bytes) -> np.ndarray:
    i = parse_bflim(b)
    return bflim_full(b)[:i["h"], :i["w"]].copy()


def rgba_to_bflim(orig: bytes, rgba: np.ndarray) -> bytes:
    """Encode `rgba` (h, w, 4) into a BFLIM with exactly the original's size, format and flags."""
    i = parse_bflim(orig)
    w, h = i["w"], i["h"]
    if rgba.shape[:2] != (h, w):
        raise ValueError(f"image is {rgba.shape[1]}x{rgba.shape[0]}, texture is {w}x{h}")
    full = bflim_full(orig).copy()
    full[:h, :w] = rgba
    full[:h, w:] = full[:h, w - 1:w]            # repeat the last column / row like the originals
    full[h:, :] = full[h - 1:h, :]
    sw, sh = i["stored"]
    data = T.encode(np.ascontiguousarray(_to_stored(full, i["flags"])), i["fmt"], flip=False)
    assert len(data) == i["dsz"]
    return data + orig[i["dsz"]:]


# --------------------------------------------------------------------- iteration
@dataclass
class Texture:
    game: str
    dat: str
    entry: str
    file: str
    data: bytes


def iter_sarcs(game: str):
    """(dat, entry, sarc bytes) for every SARC in the game's Lyt/*.dat files."""
    for dat in LYT_DATS[game]:
        _, ents = read_bg4(dat_path(game, dat).read_bytes())
        for e in ents:
            if e.size_flag or not e.data:
                continue
            raw = blz_decompress(e.data) if e.compressed else e.data
            if raw[:4] == b"SARC":
                yield dat, e.name, raw


def iter_textures(game: str):
    for dat, entry, sarc in iter_sarcs(game):
        for name, s, e in sarc_list(sarc):
            if name.endswith(".bflim"):
                yield Texture(game, dat, entry, name, sarc[s:e])


# --------------------------------------------------------------------- CLI
def cmd_extract(games: list[str]) -> None:
    from PIL import Image
    man_path = IMG_ROOT / "lyt_manifest.json"
    manifest = json.loads(man_path.read_text("utf-8")) if man_path.exists() else {}
    for game in games:
        seen: dict[str, str] = {}
        rows = []
        for t in iter_textures(game):
            info = parse_bflim(t.data)
            sha = hashlib.sha1(t.data[:info["dsz"]]).hexdigest()[:16]
            base = t.file.rsplit("/", 1)[-1][:-6]
            png = IMG_ROOT / "lyt" / game / t.dat / t.entry / f"{base}.png"
            row = {"id": f"{game}:{t.dat}/{t.entry}/{t.file}", "dat": t.dat, "entry": t.entry, "file": t.file,
                   "fmt": info["fmt"], "w": info["w"], "h": info["h"], "flags": info["flags"], "sha1": sha,
                   "png": png.relative_to(ROOT).as_posix()}
            if sha in seen:
                row["dup_of"] = seen[sha]
                row["png"] = next(r["png"] for r in rows if r["id"] == seen[sha])
            else:
                seen[sha] = row["id"]
                png.parent.mkdir(parents=True, exist_ok=True)
                Image.fromarray(bflim_to_rgba(t.data), "RGBA").save(png)
            rows.append(row)
        manifest[game] = rows
        uniq = len(seen)
        print(f"{game}: {len(rows)} textures, {uniq} unique -> work/img/lyt/{game}/")
    man_path.parent.mkdir(parents=True, exist_ok=True)
    man_path.write_text(json.dumps(manifest, ensure_ascii=False, indent=1), "utf-8")


def cmd_check(games: list[str]) -> None:
    bad = n = skipped = pad_rep = 0
    for game in games:
        for t in iter_textures(game):
            info = parse_bflim(t.data)
            full = bflim_full(t.data)
            w, h = info["w"], info["h"]
            if (full[:h, w:] == full[:h, w - 1:w]).all() and (full[h:, :] == full[h - 1:h, :]).all():
                pad_rep += 1
            if info["fmt"] in ("ETC1", "ETC1A4"):
                skipped += 1
                continue
            n += 1
            enc = T.encode(np.ascontiguousarray(_to_stored(full, info["flags"])), info["fmt"], flip=False)
            if enc != t.data[:info["dsz"]]:
                bad += 1
                if bad <= 10:
                    print("round-trip differs:", game, t.dat, t.entry, t.file, info["fmt"], w, h)
    print(f"lossless round trip: {n - bad}/{n} byte-identical ({skipped} ETC textures skipped); "
          f"padding = repeated edge in {pad_rep}/{n + skipped}")
    if bad:
        sys.exit(1)


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("cmd", choices=["extract", "check"])
    ap.add_argument("--game", choices=["3DX", "1DX"], action="append")
    a = ap.parse_args()
    games = a.game or ["3DX", "1DX"]
    (cmd_extract if a.cmd == "extract" else cmd_check)(games)


if __name__ == "__main__":
    main()
