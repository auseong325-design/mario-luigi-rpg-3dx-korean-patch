"""Build Korean layout archives (Lyt/JP/*.dat) from edited texture PNGs.

    python scripts/build_lyt.py                 # work/img/ko/lyt/<dat>/<entry>/<name>.png
                                                #   -> work/build/lyt_stage/romfs/Lyt/JP/<dat>.dat
    python scripts/build_lyt.py --identity      # rewrite all 6 dats through the full pipeline
                                                #   (every lossless texture re-encoded) -> byte-identical
    python scripts/build_lyt.py --selftest      # fake images -> build -> re-read and compare
    options: --ko DIR  --out DIR  --report FILE  --dry-run

A Korean PNG is the logical-size RGBA picture of one unique texture, stored at the texture's
manifest location (work/img/ko/lyt/<dat>/<entry>/<name>.png, i.e. the path of the manifest row
that has no `dup_of`). A PNG placed at a duplicate's location is accepted too. The picture is
applied to EVERY copy with the same pixel data (sha1), in every SARC of every dat, each copy
encoded with its own original size/format/flags (lytimg.rgba_to_bflim). SARCs are patched in
place (lytimg.sarc_replace) and the BG4 is rebuilt with lib3dx.rebuild_bg4 (only changed slots
are BLZ-compressed again; everything else keeps its original bytes). Only changed dats are
written. Every written dat is read back through the whole chain and each replaced texture is
compared with the intended picture (lossless formats: exactly the quantized PNG; ETC: PSNR).
"""

from __future__ import annotations

import argparse
import hashlib
import json
import shutil
import sys
import tempfile
from pathlib import Path

import numpy as np
from PIL import Image

sys.path.insert(0, str(Path(__file__).resolve().parent))
import libtex3ds as T  # noqa: E402
from lib3dx import ROOT, bg4_plain, read_bg4, rebuild_bg4  # noqa: E402
from lytimg import (LYT_DATS, _to_stored, bflim_full, bflim_to_rgba, dat_path,  # noqa: E402
                    parse_bflim, rgba_to_bflim, sarc_list, sarc_replace)

GAME = "3DX"
KO_DIR = ROOT / "work" / "img" / "ko" / "lyt"
OUT_DIR = ROOT / "work" / "build" / "lyt_stage" / "romfs" / "Lyt" / "JP"
MANIFEST = ROOT / "work" / "img" / "lyt_manifest.json"
NO_ALPHA = {"RGB8", "RGB565", "ETC1", "L8", "L4"}
LUMA_ONLY = {"L8", "L4", "LA4", "LA8"}           # the encoder keeps only R as luminance
ETC = {"ETC1", "ETC1A4"}


def tex_sha(bflim: bytes) -> str:
    """Same key as lyt_manifest.json: sha1 of the pixel data (footer excluded), 16 hex digits."""
    return hashlib.sha1(bflim[:parse_bflim(bflim)["dsz"]]).hexdigest()[:16]


def load_manifest() -> list[dict]:
    return json.loads(MANIFEST.read_text("utf-8"))[GAME]


def collect_pngs(ko_dir: Path, rows: list[dict]) -> tuple[dict[str, tuple[Path, dict]], list[str]]:
    """sha1 -> (png, unique manifest row). Returns problems (unknown / conflicting PNGs)."""
    by_loc = {}
    for r in rows:
        base = r["file"].rsplit("/", 1)[-1][:-6]
        by_loc[f"{r['dat']}/{r['entry']}/{base}".lower()] = r
    uniq = {r["sha1"]: r for r in rows if "dup_of" not in r}
    found: dict[str, tuple[Path, dict]] = {}
    problems = []
    if not ko_dir.exists():
        return found, problems
    for png in sorted(ko_dir.rglob("*.png")):
        rel = png.relative_to(ko_dir).with_suffix("").as_posix()
        r = by_loc.get(rel.lower())
        if r is None:
            problems.append(f"no texture at this location: {rel}.png")
            continue
        sha = r["sha1"]
        if sha in found:
            problems.append(f"two PNGs for the same texture: {found[sha][0].relative_to(ko_dir)} and {rel}.png")
            continue
        found[sha] = (png, uniq[sha])
    return found, problems


def load_rgba(png: Path, row: dict, warn: list[str]) -> np.ndarray:
    im = Image.open(png)
    rgba = np.asarray(im.convert("RGBA"), np.uint8).copy()
    name = png.name
    if rgba.shape[:2] != (row["h"], row["w"]):
        raise ValueError(f"{name}: PNG is {rgba.shape[1]}x{rgba.shape[0]}, texture is {row['w']}x{row['h']}")
    fmt = row["fmt"]
    if fmt in NO_ALPHA and (rgba[..., 3] < 255).any():
        warn.append(f"{name}: {fmt} has no alpha channel, PNG transparency is dropped")
    if fmt in LUMA_ONLY and not ((rgba[..., 0] == rgba[..., 1]) & (rgba[..., 1] == rgba[..., 2])).all():
        warn.append(f"{name}: {fmt} is greyscale, only the red channel is kept")
    return rgba


def expected(fmt: str, rgba: np.ndarray) -> np.ndarray:
    """What the game will show for `rgba` in a lossless format (channel quantization)."""
    h, w = rgba.shape[:2]
    ph, pw = -h % 8, -w % 8                     # the codec works on 8x8 tiles
    p = np.pad(rgba, ((0, ph), (0, pw), (0, 0)), mode="edge")
    e = T.decode(T.encode(p, fmt, flip=False), fmt, w + pw, h + ph, flip=False)
    return e[:h, :w]


def psnr(a: np.ndarray, b: np.ndarray, alpha: np.ndarray | None = None) -> float:
    """PSNR over RGB. With `alpha` (the intended picture's alpha) the colours are premultiplied
    first, i.e. compared as they look when the game blends them (hidden pixels do not count)."""
    a = a.astype(np.float64)
    b = b.astype(np.float64)
    if alpha is not None:
        w = alpha.astype(np.float64)[..., None] / 255.0
        a, b = a * w, b * w
    mse = float(((a - b) ** 2).mean())
    return 99.0 if mse == 0 else 10 * np.log10(255.0 ** 2 / mse)


def build(pictures: dict[str, np.ndarray], out_dir: Path | None, identity: bool = False,
          log=print) -> dict:
    """pictures: sha1 -> RGBA. Returns a report. out_dir None = do not write."""
    report = {"dats": {}, "applied": {sha: [] for sha in pictures}, "errors": []}
    for dat in LYT_DATS[GAME]:
        src = dat_path(GAME, dat)
        orig = src.read_bytes()
        _, ents = read_bg4(orig)
        slot_repl: dict[int, bytes] = {}
        changed_tex: list[tuple[int, str, str, bytes]] = []   # slot, file, sha, new bflim
        n_reenc = 0
        for n, e in enumerate(ents):
            if e.size_flag or not e.data:
                continue
            plain = bg4_plain(e)
            if plain[:4] != b"SARC":
                continue
            repl = {}
            for fname, s, t in sarc_list(plain):
                if not fname.endswith(".bflim"):
                    continue
                b = plain[s:t]
                sha = tex_sha(b)
                if sha in pictures:
                    new = rgba_to_bflim(b, pictures[sha])
                    repl[fname] = new
                    changed_tex.append((n, fname, sha, new))
                    report["applied"][sha].append(f"{dat}/{e.name}/{fname}")
                elif identity:
                    info = parse_bflim(b)
                    if info["fmt"] not in ETC:        # ETC re-encoding is lossy by nature
                        # whole stored texture (padding included: ~5% of originals do not
                        # repeat the edge there, which rgba_to_bflim would normalise)
                        full = np.ascontiguousarray(_to_stored(bflim_full(b), info["flags"]))
                        repl[fname] = T.encode(full, info["fmt"], flip=False) + b[info["dsz"]:]
                        n_reenc += 1
            if repl:
                new_sarc = sarc_replace(plain, repl)
                if new_sarc != plain:
                    slot_repl[n] = new_sarc
        rebuilt = rebuild_bg4(orig, slot_repl)
        info = {"textures_replaced": len(changed_tex), "slots_changed": len(slot_repl),
                "size_orig": len(orig), "size_new": len(rebuilt)}
        if identity:
            info["reencoded"] = n_reenc
            info["identical"] = rebuilt == orig
            if rebuilt != orig:
                report["errors"].append(f"{dat}: identity rebuild differs from the original")
        report["dats"][dat] = info
        if not slot_repl:
            continue
        # read back through BG4 -> BLZ -> SARC -> BFLIM and compare
        _, ents2 = read_bg4(rebuilt)
        if [e.name for e in ents2] != [e.name for e in ents]:
            report["errors"].append(f"{dat}: entry names/order changed")
        for n, e in enumerate(ents):
            if n in slot_repl:
                continue
            if ents2[n].data != e.data:
                report["errors"].append(f"{dat}: untouched slot {n} ({e.name}) changed")
        for n, new_sarc in slot_repl.items():
            back = bg4_plain(ents2[n])
            if back != new_sarc:
                report["errors"].append(f"{dat}/{ents[n].name}: SARC read back differs")
                continue
            orig_sarc = bg4_plain(ents[n])
            names_new = sarc_list(back)
            if [x[0] for x in names_new] != [x[0] for x in sarc_list(orig_sarc)]:
                report["errors"].append(f"{dat}/{ents[n].name}: SARC file list changed")
            touched = {f for (m, f, _s, _b) in changed_tex if m == n}
            for fname, s, t in names_new:
                if fname not in touched and back[s:t] != orig_sarc[s:t]:
                    report["errors"].append(f"{dat}/{ents[n].name}/{fname}: untouched file changed")
        for n, fname, sha, _new in changed_tex:
            back = bg4_plain(ents2[n])
            s, t = next((s, t) for f, s, t in sarc_list(back) if f == fname)
            b = back[s:t]
            got = bflim_to_rgba(b)
            fmt = parse_bflim(b)["fmt"]
            want = pictures[sha]
            if fmt in ETC:
                ref = want.copy()
                if fmt == "ETC1":
                    ref[..., 3] = 255
                p = psnr(got[..., :3], ref[..., :3], ref[..., 3])
                report.setdefault("etc_psnr", {})[f"{dat}/{ents[n].name}/{fname}"] = round(p, 1)
                if p < 30:
                    report["errors"].append(f"{dat}/{ents[n].name}/{fname}: ETC PSNR {p:.1f} dB < 30")
                if fmt == "ETC1A4" and not (got[..., 3] == expected("A4", want)[..., 3]).all():
                    report["errors"].append(f"{dat}/{ents[n].name}/{fname}: ETC1A4 alpha differs")
            elif not (got == expected(fmt, want)).all():
                report["errors"].append(f"{dat}/{ents[n].name}/{fname}: decoded picture differs")
        if out_dir is not None:
            out_dir.mkdir(parents=True, exist_ok=True)
            (out_dir / f"{dat}.dat").write_bytes(rebuilt)
        log(f"{dat}: {len(changed_tex)} textures in {len(slot_repl)} SARCs, "
            f"{len(orig)} -> {len(rebuilt)} bytes" + (f" -> {out_dir / (dat + '.dat')}" if out_dir else ""))
    return report


def cmd_build(a) -> int:
    rows = load_manifest()
    found, problems = collect_pngs(Path(a.ko), rows)
    warns: list[str] = []
    pictures = {}
    for sha, (png, row) in found.items():
        try:
            pictures[sha] = load_rgba(png, row, warns)
        except ValueError as ex:
            problems.append(str(ex))
    for p in problems:
        print("ERROR:", p)
    for w in warns:
        print("warning:", w)
    if problems:
        return 1
    if not pictures:
        print(f"no Korean PNGs under {a.ko}")
        return 0
    out = None if a.dry_run else Path(a.out)
    rep = build(pictures, out)
    copies = {r["sha1"]: 0 for r in rows}
    for r in rows:
        copies[r["sha1"]] += 1
    lines = []
    for sha, (png, row) in sorted(found.items(), key=lambda x: x[1][1]["id"]):
        got = len(rep["applied"][sha])
        flag = "" if got == copies[sha] else f"  (manifest has {copies[sha]} copies!)"
        if got != copies[sha]:
            rep["errors"].append(f"{row['id']}: applied to {got} copies, manifest has {copies[sha]}")
        lines.append(f"{row['id']}\t{row['w']}x{row['h']} {row['fmt']}\t{got} copies{flag}")
    print(f"{len(pictures)} Korean textures, {sum(len(v) for v in rep['applied'].values())} copies replaced")
    for ln in lines:
        print(" ", ln)
    if a.report:
        Path(a.report).parent.mkdir(parents=True, exist_ok=True)
        Path(a.report).write_text(json.dumps({"textures": lines, "warnings": warns, **rep},
                                             ensure_ascii=False, indent=1), "utf-8")
    for e in rep["errors"]:
        print("ERROR:", e)
    print("OK" if not rep["errors"] else f"{len(rep['errors'])} errors")
    return 1 if rep["errors"] else 0


def cmd_identity(_a) -> int:
    rep = build({}, None, identity=True)
    for dat, i in rep["dats"].items():
        print(f"{dat}: {i['reencoded']} lossless textures re-encoded, rebuilt {i['size_new']} bytes, "
              f"{'byte-identical' if i['identical'] else 'DIFFERS'}")
    ok = not rep["errors"] and all(i["identical"] for i in rep["dats"].values())
    print("identity OK" if ok else "identity FAILED")
    return 0 if ok else 1


def fake_picture(row: dict, seed: int) -> np.ndarray:
    """A recognisable test pattern: diagonal stripes + inverted box, alpha kept from the original."""
    h, w = row["h"], row["w"]
    y, x = np.mgrid[0:h, 0:w]
    orig = np.asarray(Image.open(ROOT / row["png"]).convert("RGBA"), np.uint8)
    img = np.zeros((h, w, 4), np.uint8)
    v = (((x + y + seed) // 3) % 2 * 200 + 30).astype(np.uint8)
    img[..., 0] = v
    img[..., 1] = v if row["fmt"] in LUMA_ONLY else (255 - v)
    img[..., 2] = v if row["fmt"] in LUMA_ONLY else ((x * 255) // max(1, w - 1)).astype(np.uint8)
    img[..., 3] = 255 if row["fmt"] in NO_ALPHA else np.where(orig[..., 3] > 0, 255, (x * 7 % 256)).astype(np.uint8)
    img[h // 4: h // 2, w // 4: w // 2, :3] = 255 - img[h // 4: h // 2, w // 4: w // 2, :3]
    if row["fmt"] in ETC:  # block codec: smooth colours + 4x4-aligned box (a lossy codec cannot keep stripes)
        img[..., 0] = (40 + x * 80 // max(1, w - 1)).astype(np.uint8)
        img[..., 1] = (60 + y * 80 // max(1, h - 1)).astype(np.uint8)
        img[..., 2] = 60
        img[: h // 8 * 4, : w // 8 * 4, :3] = (230, 40, 200)
        img[..., 3] = 255 if row["fmt"] == "ETC1" else np.where((x // 4 + y // 4) % 2, 255, 0x88).astype(np.uint8)
    return img


def cmd_selftest(_a) -> int:
    rows = load_manifest()
    uniq = [r for r in rows if "dup_of" not in r]
    copies: dict[str, int] = {}
    for r in rows:
        copies[r["sha1"]] = copies.get(r["sha1"], 0) + 1
    picks: list[dict] = []
    for fmt in ("LA4", "RGBA8", "ETC1A4", "RGB8", "ETC1", "RGBA4", "RGB565", "LA8", "RGBA5551", "A4", "L8"):
        cand = [r for r in uniq if r["fmt"] == fmt]
        if cand:  # the one with most copies, small size preferred
            picks.append(max(cand, key=lambda r: (copies[r["sha1"]], -r["w"] * r["h"])))
        big = [r for r in cand if r["w"] * r["h"] >= 2000 and r not in picks]
        if fmt in ETC and big:  # plus a real-sized ETC picture
            picks.append(max(big, key=lambda r: (copies[r["sha1"]], -r["w"] * r["h"])))
    for r in uniq:  # also textures stored rotated / transposed / plain
        if r["flags"] == 0 and r not in picks:
            picks.append(r)
            break
    tmp = Path(tempfile.mkdtemp(prefix="lyt_selftest_"))
    try:
        ko = tmp / "ko"
        for i, r in enumerate(picks):
            base = r["file"].rsplit("/", 1)[-1][:-6]
            p = ko / r["dat"] / r["entry"] / f"{base}.png"
            p.parent.mkdir(parents=True, exist_ok=True)
            Image.fromarray(fake_picture(r, i), "RGBA").save(p)
        found, problems = collect_pngs(ko, rows)
        assert not problems, problems
        pictures = {sha: np.asarray(Image.open(png).convert("RGBA"), np.uint8) for sha, (png, _r) in found.items()}
        out = tmp / "out"
        rep = build(pictures, out, log=lambda s: None)
        errs = list(rep["errors"])
        for r in picks:
            got = len(rep["applied"][r["sha1"]])
            if got != copies[r["sha1"]]:
                errs.append(f"{r['id']}: applied {got}/{copies[r['sha1']]} copies")
        # independent re-read: every copy of a replaced sha now decodes to the fake picture,
        # and every other texture of the dat is unchanged
        from lytimg import iter_textures  # noqa: F401 (uses dat_path; re-read manually below)
        from lib3dx import blz_decompress
        written = sorted(p.stem for p in out.glob("*.dat"))
        for dat in written:
            _, e_new = read_bg4((out / f"{dat}.dat").read_bytes())
            _, e_old = read_bg4(dat_path(GAME, dat).read_bytes())
            for en, eo in zip(e_new, e_old):
                if en.size_flag or not en.data:
                    continue
                pn = blz_decompress(en.data) if en.compressed else en.data
                po = blz_decompress(eo.data) if eo.compressed else eo.data
                if pn[:4] != b"SARC":
                    if pn != po:
                        errs.append(f"{dat}/{en.name}: non-SARC slot changed")
                    continue
                for (fn, s, t), (_fo, so, to) in zip(sarc_list(pn), sarc_list(po)):
                    bo = po[so:to]
                    sha = tex_sha(bo) if fn.endswith(".bflim") else None
                    if sha in pictures:
                        g = bflim_to_rgba(pn[s:t])
                        fmt = parse_bflim(bo)["fmt"]
                        want = pictures[sha]
                        if fmt in ETC:
                            if psnr(g[..., :3], want[..., :3], want[..., 3]) < 30:
                                errs.append(f"{dat}/{en.name}/{fn}: ETC PSNR too low")
                        elif not (g == expected(fmt, want)).all():
                            errs.append(f"{dat}/{en.name}/{fn}: fake picture not found")
                    elif pn[s:t] != bo:
                        errs.append(f"{dat}/{en.name}/{fn}: unrelated file changed")
        print(f"selftest: {len(picks)} fake textures "
              f"({', '.join(sorted({r['fmt'] + '/f' + str(r['flags']) for r in picks}))}), "
              f"{sum(len(v) for v in rep['applied'].values())} copies replaced, dats written: {', '.join(written)}")
        for e in errs:
            print("ERROR:", e)
        print("selftest OK" if not errs else f"selftest FAILED ({len(errs)} errors)")
        return 1 if errs else 0
    finally:
        shutil.rmtree(tmp, ignore_errors=True)


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("--identity", action="store_true")
    ap.add_argument("--selftest", action="store_true")
    ap.add_argument("--ko", default=str(KO_DIR))
    ap.add_argument("--out", default=str(OUT_DIR))
    ap.add_argument("--report", default=str(ROOT / "work" / "build" / "lyt_stage" / "build_report.json"))
    ap.add_argument("--dry-run", action="store_true", help="check and verify, write nothing")
    a = ap.parse_args()
    if a.identity:
        sys.exit(cmd_identity(a))
    if a.selftest:
        sys.exit(cmd_selftest(a))
    sys.exit(cmd_build(a))


if __name__ == "__main__":
    main()
