"""Rebuild exefs/banner (CBMD) with the Korean logo texture.

  identity: unchanged CGFX -> LZ11 (Nintendo-identical coder, bnr.lz11_tokens far/min_disp 2) ->
            CBMD; must equal exefs/banner byte for byte.
  korean:   CGFX with only the COMMON_jp pixel bytes replaced by out/logo/COMMON_ko_rgba4.bin.
Writes out/banner/banner_ko.bin, out/banner/banner_identity.bin (deleted if identical? no: kept
small) and out/banner/banner_build.json with every check.
"""
from __future__ import annotations

import hashlib
import json
import sys
from pathlib import Path

import numpy as np

HERE = Path(__file__).resolve().parent
WORK = HERE.parent
ROOT = WORK.parents[1]
sys.path.insert(0, str(HERE))
sys.path.insert(0, str(ROOT / "scripts"))
import bnr  # noqa: E402
import libtex3ds as T  # noqa: E402
from PIL import Image  # noqa: E402

SRC = ROOT / "exefs/banner"
OUT = WORK / "out" / "banner"
ALIGN = 0x40      # BCWAV offset alignment (original 0xA840 fits 0x10/0x20/0x40; 0x40 satisfies all)
TEX = "COMMON_jp"


def sha(b: bytes) -> str:
    return hashlib.sha256(b).hexdigest()


def compress(cgfx: bytes) -> bytes:
    return bnr.lz11_pack(bnr.lz11_tokens(cgfx, prefer="far", min_disp=2), len(cgfx))


def build(cgfx: bytes, orig: dict) -> bytes:
    return bnr.build_cbmd(orig["header"], compress(cgfx), orig["bcwav"], ALIGN)


def build_keep_layout(cgfx: bytes, orig: dict, raw: bytes) -> bytes | None:
    """Same header (incl. BCWAV offset 0x84), compressed CGFX, zero padding up to the original BCWAV
    offset, same BCWAV: the file keeps its size, so the ExeFS layout does not change at all.
    None if the new stream does not fit in front of the original BCWAV."""
    comp = compress(cgfx)
    room = orig["bcwav_off"] - orig["cgfx_off"]
    if len(comp) > room:
        return None
    out = bytearray(orig["header"]) + comp + bytes(room - len(comp)) + orig["bcwav"]
    assert len(out) == len(raw)
    return bytes(out)


def main() -> int:
    OUT.mkdir(parents=True, exist_ok=True)
    raw = SRC.read_bytes()
    c = bnr.parse_cbmd(raw)
    rep: dict = {"source": str(SRC), "source_sha256": sha(raw), "source_size": len(raw), "align": ALIGN}
    # identity
    ident = build(c["cgfx"], c)
    rep["identity_equal"] = ident == raw
    rep["identity_sha256"] = sha(ident)
    assert rep["identity_equal"], "unchanged rebuild differs"
    # korean
    tex = {t["name"]: t for t in bnr.cgfx_textures(c["cgfx"])}[TEX]
    off, n = tex["img"]["data_off"], tex["img"]["data_len"]
    new = (WORK / "out/logo/COMMON_ko_rgba4.bin").read_bytes()
    assert len(new) == n == 65536 and tex["fmt"] == "RGBA4" and (tex["w"], tex["h"]) == (256, 128)
    cg = bytearray(c["cgfx"])
    cg[off:off + n] = new
    cg = bytes(cg)
    diff = np.nonzero(np.frombuffer(cg, np.uint8) != np.frombuffer(c["cgfx"], np.uint8))[0]
    rep["cgfx_changed_bytes"] = int(len(diff))
    rep["cgfx_changed_range"] = [int(diff.min()), int(diff.max()) + 1] if len(diff) else None
    rep["cgfx_texture_range"] = [off, off + n]
    assert diff.min() >= off and diff.max() < off + n
    ko = build_keep_layout(cg, c, raw)
    rep["layout"] = "kept: header, BCWAV offset 0xA840 and file size unchanged; zero padding after the CGFX"
    if ko is None:
        ko = build(cg, c)
        rep["layout"] = f"compact: BCWAV moved, aligned {ALIGN:#x}"
    (OUT / "banner_ko.bin").write_bytes(ko)
    rep["ko_padding_after_cgfx"] = None
    # read back
    k = bnr.parse_cbmd(ko)
    rep["ko_size"] = len(ko)
    rep["ko_sha256"] = sha(ko)
    rep["ko_cgfx_comp_len"] = k["cgfx_comp_len"]
    rep["ko_bcwav_off"] = hex(k["bcwav_off"])
    rep["ko_padding_after_cgfx"] = {"bytes": len(k["pad_after_cgfx"]), "all_zero": not any(k["pad_after_cgfx"])}
    rep["ko_readback_cgfx_equal"] = k["cgfx"] == cg
    rep["ko_bcwav_equal"] = k["bcwav"] == c["bcwav"]
    hdr_diff = [i for i in range(0x88) if ko[i] != raw[i]]
    rep["ko_header_changed_bytes"] = hdr_diff
    rep["ko_cgfx_decompressed_size"] = len(k["cgfx"])
    rep["ko_cgfx_size_limit_ok"] = len(k["cgfx"]) <= 0x80000
    texs = {t["name"]: t for t in bnr.cgfx_textures(k["cgfx"])}
    others = {}
    for name, t in {t["name"]: t for t in bnr.cgfx_textures(c["cgfx"])}.items():
        a = c["cgfx"][t["img"]["data_off"]:t["img"]["data_off"] + t["img"]["data_len"]]
        b = k["cgfx"][texs[name]["img"]["data_off"]:texs[name]["img"]["data_off"] + texs[name]["img"]["data_len"]]
        others[name] = (a == b)
    rep["texture_bytes_unchanged"] = others
    dec = T.decode(k["cgfx"][off:off + n], "RGBA4", 256, 128)[::-1]
    want = np.asarray(Image.open(WORK / "out/logo/COMMON_ko_upright.png").convert("RGBA"))
    rep["ko_texture_equals_logo_png"] = bool(np.array_equal(dec, want))
    # ExeFS slot: banner is padded to 0x200 in ExeFS
    rep["exefs_slot_bytes"] = (len(raw) + 0x1FF) & ~0x1FF
    rep["fits_original_exefs_slot"] = len(ko) <= rep["exefs_slot_bytes"]
    (OUT / "banner_build.json").write_text(json.dumps(rep, indent=1), encoding="utf-8")
    print(json.dumps(rep, indent=1))
    ok = (rep["identity_equal"] and rep["ko_readback_cgfx_equal"] and rep["ko_bcwav_equal"]
          and rep["ko_texture_equals_logo_png"] and rep["ko_header_changed_bytes"] in ([], [0x84], [0x84, 0x85], [0x85])
          and rep["ko_padding_after_cgfx"]["all_zero"])
    print("ALL OK" if ok else "CHECK FAILED")
    return 0 if ok else 1


if __name__ == "__main__":
    sys.exit(main())
