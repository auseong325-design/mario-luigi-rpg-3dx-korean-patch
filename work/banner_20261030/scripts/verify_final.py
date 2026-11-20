"""Final read-back of the Korean CIA (read-only): pull ExeFS:/banner out of the built CIA, check it
equals out/banner/banner_ko.bin, decompress it to extract/ko_banner.cgfx (for the SPICA read),
decode the logo and compare with out/logo/COMMON_ko_upright.png, and compare every other
ExeFS file and the RomFS region byte-for-byte with the original CIA.
Writes out/cia/final_verify.json.
"""
from __future__ import annotations

import hashlib
import json
import sys
from pathlib import Path

import numpy as np
from PIL import Image

HERE = Path(__file__).resolve().parent
WORK = HERE.parent
ROOT = WORK.parents[1]
sys.path.insert(0, str(HERE))
sys.path.insert(0, str(ROOT / "scripts"))
import bnr  # noqa: E402
import cia as C  # noqa: E402
import libtex3ds as T  # noqa: E402

NEW = WORK / "out/00040000001CA900_ML3DX_KoreanBanner.cia"


def exefs_files(c: C.Cia) -> dict:
    base = c.chunks[0]["cia_off"]
    n = C.ncch_info(c.read(base, 0x200))
    ents = C.exefs_entries(c.read(base + n["exefs_off"], 0x200))
    return {e["name"]: c.read(base + n["exefs_off"] + 0x200 + e["off"], e["size"]) for e in ents}, n


def same_region(a: Path, b: Path, off: int, n: int) -> bool:
    with open(a, "rb") as fa, open(b, "rb") as fb:
        fa.seek(off); fb.seek(off)
        left = n
        while left:
            k = min(left, 8 << 20)
            if fa.read(k) != fb.read(k):
                return False
            left -= k
    return True


def main() -> int:
    orig_path = next(ROOT.glob("00040000001CA900*.cia"))
    o, k = C.Cia(orig_path), C.Cia(NEW)
    fo, no = exefs_files(o)
    fk, nk = exefs_files(k)
    rep = {"new_cia": str(NEW), "orig_cia": str(orig_path)}
    rep["banner_equals_build"] = fk["banner"] == (WORK / "out/banner/banner_ko.bin").read_bytes()
    rep["other_exefs_files_identical"] = {n: fk[n] == fo[n] for n in fo if n != "banner"}
    rep["ncch_layout_identical"] = {key: nk[key] == no[key] for key in no if key not in ("exefs_hash",)}
    base = o.chunks[0]["cia_off"]
    rep["romfs_region_identical"] = same_region(orig_path, NEW, base + no["romfs_off"], no["romfs_size"])
    rep["exheader_logo_plain_identical"] = same_region(orig_path, NEW, base + 0x200, no["exefs_off"] - 0x200)
    rep["cert_ticket_identical"] = same_region(orig_path, NEW, 0, o.off_tmd)
    rep["meta_identical"] = same_region(orig_path, NEW, o.off_meta, o.meta_size)
    c = bnr.parse_cbmd(fk["banner"])
    (WORK / "extract/ko_banner.cgfx").write_bytes(c["cgfx"])
    tex = {t["name"]: t for t in bnr.cgfx_textures(c["cgfx"])}["COMMON_jp"]
    im = tex["img"]
    dec = T.decode(c["cgfx"][im["data_off"]:im["data_off"] + im["data_len"]], "RGBA4", 256, 128)[::-1]
    want = np.asarray(Image.open(WORK / "out/logo/COMMON_ko_upright.png").convert("RGBA"))
    rep["logo_from_cia_equals_png"] = bool(np.array_equal(dec, want))
    rep["logo_raw_sha256"] = hashlib.sha256(c["cgfx"][im["data_off"]:im["data_off"] + im["data_len"]]).hexdigest()
    rep["ko_cgfx_sha256"] = hashlib.sha256(c["cgfx"]).hexdigest()
    Image.fromarray(dec, "RGBA").save(WORK / "out/cia/logo_read_back_from_cia.png")
    ok = (rep["banner_equals_build"] and all(rep["other_exefs_files_identical"].values())
          and all(rep["ncch_layout_identical"].values()) and rep["romfs_region_identical"]
          and rep["exheader_logo_plain_identical"] and rep["cert_ticket_identical"] and rep["meta_identical"]
          and rep["logo_from_cia_equals_png"])
    rep["all_ok"] = ok
    (WORK / "out/cia/final_verify.json").write_text(json.dumps(rep, indent=1), encoding="utf-8")
    print(json.dumps(rep, indent=1))
    return 0 if ok else 1


if __name__ == "__main__":
    sys.exit(main())
