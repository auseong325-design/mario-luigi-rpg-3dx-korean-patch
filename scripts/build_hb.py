"""Giant-battle UI builder (romfs/HB/JP_ja/*.arc.z and the shared HB/*.arc.z).

    python scripts/build_hb.py extract     all textures -> work/img/hb/<arc>/<name>.png + work/img/hb/_manifest.json
    python scripts/build_hb.py identity    rebuild every archive with no changes -> must equal the originals
    python scripts/build_hb.py selftest    LZH8 encoder round trip on every archive + fake-texture replace test
    python scripts/build_hb.py build [--out DIR]
        Korean PNGs work/img/hb_ko/<texture name>.png (logical size RGBA, name as in the manifest,
        e.g. ja_sentaku_yes.png) are encoded into EVERY archive that holds the same texture
        (same hash and same original bytes), SARC patched in place, re-compressed (LZH8, verified by
        decoding) and only changed archives are written to --out (default work/build/hb_stage/romfs/),
        then read back and compared with the intended pictures.
"""
from __future__ import annotations

import argparse
import json
import sys
import time
from pathlib import Path

import numpy as np

sys.path.insert(0, str(Path(__file__).resolve().parent))
import libhb as H  # noqa: E402
import libhb_lzh8 as LZ  # noqa: E402
import lytimg  # noqa: E402
import libtex3ds as T  # noqa: E402
from lib3dx import ROOT, romfs_path  # noqa: E402

IMG = ROOT / "work" / "img" / "hb"
KO = ROOT / "work" / "img" / "hb_ko"
STAGE = ROOT / "work" / "build" / "hb_stage" / "romfs"


def arc_key(rel: str) -> str:
    return rel.replace("HB/", "").replace("/", "_").replace(".arc.z", "")


def iter_textures():
    names = H.name_table()
    for rel in H.arc_rels():
        comp = romfs_path(rel).read_bytes()
        sarc = H.unpack(comp)
        for e in H.sarc_entries(sarc):
            d = sarc[e["start"]:e["end"]]
            if H.is_bflim(d):
                nm = names.get(e["hash"])
                base = nm[5:-6] if nm else f"h{e['hash']:08x}"
                yield rel, e, base, d


def cmd_extract():
    from PIL import Image
    rows, seen = [], {}
    for rel, e, base, d in iter_textures():
        info = lytimg.parse_bflim(d)
        sha = H.sha16(d)
        key = arc_key(rel)
        png = IMG / key / f"{base}.png"
        row = {"id": f"{rel}:{base}", "arc": rel, "name": base, "hash": f"{e['hash']:08x}", "fmt": info["fmt"],
               "w": info["w"], "h": info["h"], "flags": info["flags"], "sha1": sha,
               "png": png.relative_to(ROOT).as_posix()}
        if sha in seen:
            row["dup_of"] = seen[sha]["id"]
            row["png"] = seen[sha]["png"]
        else:
            png.parent.mkdir(parents=True, exist_ok=True)
            Image.fromarray(lytimg.bflim_to_rgba(d), "RGBA").save(png)
            seen[sha] = row
        rows.append(row)
    IMG.mkdir(parents=True, exist_ok=True)
    (IMG / "_manifest.json").write_text(json.dumps(rows, ensure_ascii=False, indent=1), "utf-8")
    print(f"{len(rows)} textures, {len(seen)} unique -> {IMG}")


def cmd_identity():
    bad = 0
    for rel in H.arc_rels():
        comp = romfs_path(rel).read_bytes()
        sarc = H.unpack(comp)
        # rewrite every texture with itself through the same path the builder uses
        repl = {e["hash"]: sarc[e["start"]:e["end"]] for e in H.sarc_entries(sarc)}
        sarc2 = H.replace_by_hash(sarc, repl)
        out = H.pack(comp, sarc2)
        ok = out == comp and sarc2 == sarc and len(sarc) == int.from_bytes(comp[1:4], "little")
        bad += not ok
        print(f"{'OK ' if ok else 'BAD'} {rel} {len(comp)} bytes, sarc {len(sarc)}")
    print("identity:", "PASS" if bad == 0 else f"FAIL ({bad})")
    return bad == 0


def cmd_selftest():
    ok_all = True
    for rel in H.arc_rels():
        comp = romfs_path(rel).read_bytes()
        sarc = H.unpack(comp)
        t = time.time()
        c2 = LZ.compress(sarc)
        d2 = H.unpack(c2)
        ok = d2 == sarc
        ok_all &= ok
        print(f"{'OK ' if ok else 'BAD'} LZH8 {rel}: original {len(comp)} -> ours {len(c2)} ({time.time() - t:.1f}s)")
    # fake replacement: invert one texture of yesno and check read-back
    rel = "HB/JP_ja/yesno.arc.z"
    comp = romfs_path(rel).read_bytes()
    sarc = H.unpack(comp)
    e = next(x for x in H.sarc_entries(sarc) if H.is_bflim(sarc[x["start"]:x["end"]]))
    d = sarc[e["start"]:e["end"]]
    rgba = lytimg.bflim_to_rgba(d)
    fake = rgba.copy()
    fake[..., :3] = 255 - fake[..., :3]
    newd = lytimg.rgba_to_bflim(d, fake)
    sarc2 = H.replace_by_hash(sarc, {e["hash"]: newd})
    c2 = H.pack(comp, sarc2)
    s3 = H.unpack(c2)
    e3 = next(x for x in H.sarc_entries(s3) if x["hash"] == e["hash"])
    back = lytimg.bflim_to_rgba(s3[e3["start"]:e3["end"]])
    again = lytimg.bflim_to_rgba(newd)
    ok = np.array_equal(back, again) and s3[:e["start"]] == sarc[:e["start"]] and s3[e["end"]:] == sarc[e["end"]:]
    print(f"{'OK ' if ok else 'BAD'} fake replace {rel} {e['hash']:08x}: psnr vs intended {psnr(fake, back):.1f} dB")
    ok_all &= ok
    print("selftest:", "PASS" if ok_all else "FAIL")
    return ok_all


def psnr(a, b):
    a = a.astype(np.float64)
    b = b.astype(np.float64)
    m = a[..., 3:] / 255.0
    # compare premultiplied colour + alpha so fully transparent pixels do not count
    pa = np.concatenate([a[..., :3] * m, a[..., 3:]], -1)
    pb = np.concatenate([b[..., :3] * (b[..., 3:] / 255.0), b[..., 3:]], -1)
    mse = np.mean((pa - pb) ** 2)
    return 99.0 if mse == 0 else 10 * np.log10(255 ** 2 / mse)


def cmd_build(out_root: Path):
    from PIL import Image
    kos = {p.stem: p for p in KO.glob("*.png")} if KO.exists() else {}
    report = []
    applied = {}
    for rel in H.arc_rels():
        comp = romfs_path(rel).read_bytes()
        sarc = H.unpack(comp)
        names = H.name_table()
        repl, want = {}, {}
        for e in H.sarc_entries(sarc):
            nm = names.get(e["hash"])
            base = nm[5:-6] if nm else f"h{e['hash']:08x}"
            if base not in kos:
                continue
            d = sarc[e["start"]:e["end"]]
            img = np.array(Image.open(kos[base]).convert("RGBA"))
            newd = lytimg.rgba_to_bflim(d, img)
            repl[e["hash"]] = newd
            want[e["hash"]] = (base, img, newd)
        if not repl:
            continue
        sarc2 = H.replace_by_hash(sarc, repl)
        c2 = H.pack(comp, sarc2)
        dst = out_root / rel
        dst.parent.mkdir(parents=True, exist_ok=True)
        dst.write_bytes(c2)
        # read back from disk
        s3 = H.unpack(dst.read_bytes())
        idx = {x["hash"]: x for x in H.sarc_entries(s3)}
        for h, (base, img, newd) in want.items():
            x = idx[h]
            back = lytimg.bflim_to_rgba(s3[x["start"]:x["end"]])
            fmt = lytimg.parse_bflim(newd)["fmt"]
            p = psnr(img, back)
            ok = (p >= 30) if fmt.startswith("ETC") else np.array_equal(back, lytimg.bflim_to_rgba(newd))
            report.append({"arc": rel, "texture": base, "fmt": fmt, "psnr": round(p, 2), "ok": bool(ok)})
            applied.setdefault(base, []).append(rel)
        print(f"wrote {dst.relative_to(ROOT)}: {len(repl)} textures, {len(comp)} -> {len(c2)} bytes")
    missing = sorted(set(kos) - set(applied))
    (ROOT / "work" / "img" / "hb" / "_build_report.json").write_text(
        json.dumps({"textures": report, "applied": applied, "unused_png": missing}, ensure_ascii=False, indent=1), "utf-8")
    bad = [r for r in report if not r["ok"]]
    print(f"{len(applied)} Korean textures applied to {len(report)} copies; bad {len(bad)}; unused PNG {missing}")
    return not bad


def cmd_review():
    """Original / Korean (read back from the staged archive) side by side, 1x and 3x -> work/img/review/I6_*.png"""
    from PIL import Image, ImageDraw
    plan = json.loads((ROOT / "work" / "img" / "hb_plan.json").read_text("utf-8"))
    items = [i for i in plan["items"] if i["action"] == "replace" and "dup_of" not in i]
    back = {}
    for rel in H.arc_rels():
        p = STAGE / rel
        if not p.exists():
            continue
        s = H.unpack(p.read_bytes())
        names = H.name_table()
        for e in H.sarc_entries(s):
            nm = names.get(e["hash"])
            if nm:
                d = s[e["start"]:e["end"]]
                if H.is_bflim(d):
                    back.setdefault(nm[5:-6], lytimg.bflim_to_rgba(d))

    def on(bgc, rgba, scale):
        im = Image.fromarray(rgba, "RGBA")
        bg = Image.new("RGBA", im.size, bgc)
        bg.alpha_composite(im)
        return bg.resize((im.width * scale, im.height * scale), Image.NEAREST).convert("RGB")

    rows = []
    rp = KO / "_report.json"
    rep = json.loads(rp.read_text("utf-8")) if rp.exists() else {}
    try:  # one screen group per sheet, in the order libhb_ko lists them
        import libhb_ko as HK
        order = {m: (gi, mi) for gi, g in enumerate(HK.GROUPS.values()) for mi, m in enumerate(g["members"])}
        items.sort(key=lambda i: order.get(i["name"], (99, 0)))
    except Exception:  # noqa: BLE001 -- the sheet still works without the grouping
        pass
    for it in items:
        o = np.array(Image.open(ROOT / it["png"]).convert("RGBA"))
        k = back.get(it["name"])
        if k is None:
            kp = KO / f"{it['name']}.png"
            k = np.array(Image.open(kp).convert("RGBA")) if kp.exists() else np.zeros_like(o)
        rows.append((it, o, k))
    for old in (ROOT / "work" / "img" / "review").glob("I6_[0-9][0-9].png"):
        old.unlink()                                  # pages of an earlier round
    pages = []
    groups, cur, ch = [], [], 0
    for r in rows:
        hh = r[1].shape[0] * 7 + 40
        if cur and ch + hh > 1560:
            groups.append(cur); cur, ch = [], 0
        cur.append(r); ch += hh
    if cur:
        groups.append(cur)
    for gi, chunk in enumerate(groups):
        pg = gi
        W = max(r[1].shape[1] for r in chunk)
        cellw = min(1600, max(W * 3 + 8, W * 2 + 12))
        H_ = sum(r[1].shape[0] * (1 + 6) + 40 for r in chunk)
        sheet = Image.new("RGB", (cellw, H_), (32, 32, 32))
        dr = ImageDraw.Draw(sheet)
        y = 0
        for it, o, k in chunk:
            h, w = o.shape[:2]
            r = rep.get(it["name"], {})
            wr = (r.get("weight") or {}).get("ratio")
            src = f"{r.get('group', '?')}:{'/'.join(r.get('levels') or [])} w{wr}" if r else "no report"
            dr.text((4, y + 2), f"{it['name']} {w}x{h} {it['fmt']} | {src} | top original, bottom Korean",
                    fill=(255, 230, 0))
            y += 14
            sheet.paste(on((90, 130, 170, 255), o, 1), (4, y))          # actual size: original | Korean
            sheet.paste(on((90, 130, 170, 255), k, 1), (8 + w, y))
            y += h + 4
            sheet.paste(on((110, 110, 110, 255), o, 3), (4, y))          # 3x: original above Korean
            y += h * 3 + 2
            sheet.paste(on((110, 110, 110, 255), k, 3), (4, y))
            y += h * 3 + 20
        sheet = sheet.crop((0, 0, cellw, min(y, 1600)))
        out = ROOT / "work" / "img" / "review" / f"I6_{pg + 1:02d}.png"
        out.parent.mkdir(parents=True, exist_ok=True)
        sheet.save(out)
        pages.append(out)
    for p in pages:
        print(p)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("cmd", nargs="?", default="build", choices=["extract", "identity", "selftest", "build", "review"])
    ap.add_argument("--out", type=Path, default=STAGE)
    ap.add_argument("--identity", action="store_true", help="same as the identity command")
    a = ap.parse_args()
    if a.identity or a.cmd == "identity":
        sys.exit(0 if cmd_identity() else 1)
    if a.cmd == "extract":
        cmd_extract()
    elif a.cmd == "selftest":
        sys.exit(0 if cmd_selftest() else 1)
    elif a.cmd == "build":
        sys.exit(0 if cmd_build(a.out) else 1)
    elif a.cmd == "review":
        cmd_review()


if __name__ == "__main__":
    main()
