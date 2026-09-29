"""FMdl/JP/FMdl.dat builder (BCH model textures) -- stream I4.

    python scripts/build_fmdl.py extract      # all textures -> work/img/fmdl/<game>/<model>/<tex>.png
                                              #   + work/img/fmdl_manifest.json + contact sheets
    python scripts/build_fmdl.py --identity   # rebuild with no replacement; must equal the original
    python scripts/build_fmdl.py              # build with Korean PNGs (default)
    python scripts/build_fmdl.py --selftest   # fake replacement -> rebuild -> read back

Korean textures: work/img/fmdl_ko/<model>/<texture>.png (RGBA, the texture's own size, top row
first). Every copy of the same original texture (same pixel bytes, in any model) gets the same
replacement. Output: work/build/fmdl_stage/romfs/FMdl/JP/FMdl.dat (source: v1.2 romf2 version).
Only changed models are BLZ-compressed again (lib3dx.rebuild_bg4); pixel bytes are replaced in
place, so each BCH keeps its length and layout.
"""

from __future__ import annotations

import argparse
import hashlib
import json
import sys
from pathlib import Path

import numpy as np
from PIL import Image

sys.path.insert(0, str(Path(__file__).parent))
import lib3dx  # noqa: E402
import libbch  # noqa: E402
import libtex3ds  # noqa: E402

ROOT = lib3dx.ROOT
SRC_REL = "FMdl/JP/FMdl.dat"
KO_DIR = ROOT / "work/img/fmdl_ko"
OUT = ROOT / "work/build/fmdl_stage/romfs/FMdl/JP/FMdl.dat"
GAMES = {"3DX": lambda: lib3dx.romfs_path(SRC_REL),
         "1DX": lambda: ROOT / "ml 1dx/3romfs/FMdl/KR/FMdl.dat"}


def load(path: Path):
    raw = path.read_bytes()
    _, es = lib3dx.read_bg4(raw)
    models = {}
    for n, e in enumerate(es):
        if e.size_flag or not e.data:
            continue
        plain = lib3dx.bg4_plain(e)
        if plain[:4] != b"BCH\0":
            continue
        models[e.name] = (n, plain, libbch.Bch(plain))
    return raw, models


def tex_sha(bch: libbch.Bch, t: libbch.BchTexture) -> str:
    return hashlib.sha1(bch.data[t.offset:t.offset + t.size]).hexdigest()


def extract() -> None:
    from img_sheets import sheets
    manifest = {}
    for game, pf in GAMES.items():
        _, models = load(pf())
        rows, seen = [], {}
        for name, (slot, _plain, bch) in models.items():
            for t in bch.textures:
                sha = tex_sha(bch, t)
                png = ROOT / f"work/img/fmdl/{game}/{name}/{t.name}.png"
                row = {"id": f"{name}/{t.name}", "model": name, "slot": slot, "tex": t.name,
                       "w": t.w, "h": t.h, "fmt": t.fmt, "levels": t.levels, "sha1": sha,
                       "png": png.relative_to(ROOT).as_posix()}
                if sha in seen:
                    row["dup_of"] = seen[sha]
                else:
                    seen[sha] = row["id"]
                    png.parent.mkdir(parents=True, exist_ok=True)
                    Image.fromarray(bch.decode(t)).save(png)
                rows.append(row)
        manifest[game] = rows
        uniq = [r for r in rows if "dup_of" not in r]
        items = [(r["id"][:34], ROOT / r["png"], f"{r['id']}\t{r['w']}x{r['h']}\t{r['fmt']}") for r in uniq]
        sheets(items, f"work/img/fmdl/sheets/{game}", 6, 8)
        print(game, len(models), "models", len(rows), "textures", len(uniq), "unique")
    (ROOT / "work/img/fmdl_manifest.json").write_text(json.dumps(manifest, ensure_ascii=False, indent=1), "utf-8")


def ko_images() -> dict[str, np.ndarray]:
    out = {}
    for p in sorted(KO_DIR.glob("*/*.png")):
        out[f"{p.parent.name}/{p.stem}"] = np.asarray(Image.open(p).convert("RGBA"))
    return out


def build(replace: dict[str, np.ndarray], out: Path | None, verbose=True) -> bytes:
    raw, models = load(GAMES["3DX"]())
    # sha of every requested original -> image
    want = {}
    for key, img in replace.items():
        model, tex = key.split("/", 1)
        if model not in models:
            raise KeyError(f"no model {model}")
        _slot, _p, bch = models[model]
        t = bch.texture(tex)
        if img.shape[:2] != (t.h, t.w):
            raise ValueError(f"{key}: need {t.w}x{t.h}, got {img.shape[1]}x{img.shape[0]}")
        want[tex_sha(bch, t)] = (key, img)
    new_slots, applied = {}, {}
    for name, (slot, plain, bch) in models.items():
        items = {}
        for t in bch.textures:
            s = tex_sha(bch, t)
            if s in want:
                items[t.name] = want[s][1]
                applied.setdefault(want[s][0], []).append(f"{name}/{t.name}")
        if items:
            new_slots[slot] = bch.replace_many(items)
    data = lib3dx.rebuild_bg4(raw, new_slots)
    # verify: read back every replaced texture
    _, es = lib3dx.read_bg4(data)
    for key, copies in applied.items():
        img = want[[s for s, v in want.items() if v[0] == key][0]][1]
        for c in copies:
            model, tex = c.split("/", 1)
            b = libbch.Bch(lib3dx.bg4_plain(es[models[model][0]]))
            t = b.texture(tex)
            got = b.decode(t)
            ref = libtex3ds.decode(libtex3ds.encode(img, t.fmt, flip=False), t.fmt, t.w, t.h, flip=False)
            if t.fmt in ("ETC1", "ETC1A4"):
                mse = ((got.astype(float) - img.astype(float)) ** 2)[..., :3].mean()
                psnr = 99 if mse == 0 else 10 * np.log10(255 ** 2 / mse)
                if psnr < 30:
                    raise ValueError(f"{c}: ETC PSNR {psnr:.1f} dB")
            elif not (got == ref).all():
                raise ValueError(f"{c}: read-back differs")
            if len(b.data) != len(models[model][1]):
                raise ValueError(f"{c}: BCH length changed")
    if verbose:
        for key, copies in applied.items():
            print(f"replaced {key}: {len(copies)} copies ({', '.join(copies)})")
        missing = set(replace) - set(applied)
        if missing:
            print("NOT applied:", sorted(missing))
        print(f"{len(new_slots)} models rebuilt, {len(data)} bytes (orig {len(raw)})")
    if out:
        out.parent.mkdir(parents=True, exist_ok=True)
        out.write_bytes(data)
        print("wrote", out.relative_to(ROOT))
    return data


def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("cmd", nargs="?", default="build", choices=["build", "extract"])
    ap.add_argument("--identity", action="store_true")
    ap.add_argument("--selftest", action="store_true")
    ap.add_argument("--out", default=str(OUT))
    a = ap.parse_args()
    if a.cmd == "extract":
        return extract()
    if a.identity:
        raw = GAMES["3DX"]().read_bytes()
        data = build({}, None, verbose=False)
        # also re-encode every model with every lossless texture replaced by itself
        _, models = load(GAMES["3DX"]())
        same = {slot: bch.replace_many({t.name: bch.decode(t) for t in bch.textures
                                        if t.levels == 1 and t.fmt not in ("ETC1", "ETC1A4")})
                for _n, (slot, _p, bch) in list(models.items())[:12]}
        ok2 = all(v == models_plain for v, models_plain in
                  ((same[s], p) for _n, (s, p, _b) in list(models.items())[:12]))
        print("identity:", "OK" if data == raw else "FAIL", len(data), len(raw),
              "| self-replace 12 models:", "OK" if ok2 else "FAIL")
        sys.exit(0 if data == raw and ok2 else 1)
    if a.selftest:
        _, models = load(GAMES["3DX"]())
        name = "fmd_title_JP_ja"
        _s, _p, bch = models[name]
        fake = {}
        for t in bch.textures[:3]:
            img = bch.decode(t).copy()
            img[: t.h // 2, : t.w // 2, :3] = 255 - img[: t.h // 2, : t.w // 2, :3]
            fake[f"{name}/{t.name}"] = img
        build(fake, None)
        print("selftest OK")
        return
    build(ko_images(), Path(a.out))


if __name__ == "__main__":
    main()
