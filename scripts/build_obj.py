"""Obj/JP sprite archives: extract to PNG, rebuild with Korean sprites.

    python scripts/build_obj.py extract            # 3DX Obj/JP + 1DX Obj/KR, Obj/Menu -> work/img/obj/ + manifest
    python scripts/build_obj.py identity           # rebuild every 3DX dat through the writer, byte-compare
    python scripts/build_obj.py selftest           # fake replacement -> rebuild -> re-read -> compare
    python scripts/build_obj.py build [--out DIR]  # work/img/obj_ko/... -> work/build/obj_stage/romfs/Obj/JP/

Korean input (RGBA PNG, same size as the extracted image):
    work/img/obj_ko/<dat>/<object>/f<frame>.png    whole frame composite (as extracted); every part of
                                                   the frame is cut back out of it (parts must not
                                                   overlap on screen, or they must agree)
    work/img/obj_ko/<dat>/<object>/<region>.png    one part region b<buf>_<w>x<h> (as extracted)
A graph buffer region written by several inputs must receive identical pixels (checked).
Only the graph (pixel) entries change; they keep their size and format, so the anim files and
_CA_INFO_ stay byte-identical.  lib3dx.rebuild_bg4 re-compresses the changed entries only.
"""

from __future__ import annotations

import argparse
import hashlib
import json
import sys
from pathlib import Path

import numpy as np
from PIL import Image

sys.path.insert(0, str(Path(__file__).resolve().parent))
import lib3dx  # noqa: E402
import libobj  # noqa: E402
import libtex3ds  # noqa: E402

ROOT = lib3dx.ROOT
IMG = ROOT / "work" / "img" / "obj"
KO = ROOT / "work" / "img" / "obj_ko"
MANIFEST = ROOT / "work" / "img" / "obj_manifest.json"
STAGE = ROOT / "work" / "build" / "obj_stage" / "romfs" / "Obj" / "JP"


def _save(img: np.ndarray, path: Path) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    Image.fromarray(img, "RGBA").save(path)


def _sha(img: np.ndarray) -> str:
    return hashlib.sha1(img.tobytes() + str(img.shape).encode()).hexdigest()[:16]


# ------------------------------------------------------------------ extract
def extract() -> dict:
    man = {"note": "frames: f<global frame index>.png = composite (part 0 on top, no colour shader); "
                   "regions: b<buf>_<w>x<h>.png = one part's pixels, unflipped storage orientation",
           "games": {}}
    for game, dats in (("3DX", libobj.DATS_3DX), ("1DX", list(libobj.DATS_1DX))):
        gm = man["games"][game] = {}
        for dat in dats:
            od = libobj.ObjDat(game, dat)
            dm = gm[dat] = {"path": str(od.path.relative_to(ROOT)).replace("\\", "/"), "objects": {}}
            for name in sorted(od.objs):
                o = od.objs[name]
                af = od.anim(o.anim)
                graph = od.plain(o.graph)
                base = IMG / game / dat / name
                om = {"anim": o.anim, "graph": o.graph, "color": o.color, "hitbox": o.hitbox,
                      "fmt": af.fmt, "graph_len": len(graph), "bbox": af.bbox,
                      "anims": [[a.first_frame, a.total_frames, a.length] for a in af.anims],
                      "frames": [], "regions": {}}
                for fi, fr in enumerate(af.frames):
                    lay, size, origin = libobj.frame_layout(af, fr)
                    img = libobj.render_frame(af, graph, fr)
                    ent = {"size": list(size), "origin": list(origin), "transform": fr.transform,
                           "parts": [[libobj.region_key(p), x0, y0, int(p.flip[0]), int(p.flip[1])]
                                     for p, x0, y0 in lay]}
                    if img is not None:
                        _save(img, base / f"f{fi:03d}.png")
                        ent["sha"] = _sha(img)
                    om["frames"].append(ent)
                for p in af.parts:
                    k = libobj.region_key(p)
                    if k in om["regions"]:
                        continue
                    img = libobj.part_rgba(af, graph, p, apply_flip=False)
                    _save(img, base / "regions" / f"{k}.png")
                    om["regions"][k] = {"buf": p.buf, "w": p.size[0], "h": p.size[1], "sha": _sha(img),
                                        "empty": bool(img[..., 3].max() == 0)}
                dm["objects"][name] = om
            print(game, dat, len(dm["objects"]), "objects")
    MANIFEST.write_text(json.dumps(man, ensure_ascii=False, indent=1), "utf-8")
    return man


# ------------------------------------------------------------------ build
def _load_png(path: Path, w: int, h: int) -> np.ndarray:
    im = np.array(Image.open(path).convert("RGBA"))
    if im.shape[:2] != (h, w):
        raise ValueError(f"{path}: size {im.shape[1]}x{im.shape[0]}, expected {w}x{h}")
    return im


def collect(od: libobj.ObjDat, ko_dir: Path, log: list) -> dict[str, dict[int, bytes]]:
    """Korean PNGs of one dat -> {graph entry name: {byte offset: encoded bytes}}."""
    writes: dict[str, dict[int, tuple[bytes, str]]] = {}

    def put(gname: str, off: int, data: bytes, src: str) -> None:
        w = writes.setdefault(gname, {})
        if off in w and w[off][0] != data:
            raise ValueError(f"{gname}@{off:#x}: conflicting pixels from {w[off][1]} and {src}")
        for o2, (d2, s2) in w.items():   # partial overlap of two different regions
            if o2 != off and o2 < off + len(data) and off < o2 + len(d2):
                a0, a1 = max(o2, off), min(o2 + len(d2), off + len(data))
                if d2[a0 - o2:a1 - o2] != data[a0 - off:a1 - off]:
                    raise ValueError(f"{gname}: overlapping regions {src} / {s2} disagree")
        w[off] = (data, src)

    if not ko_dir.exists():
        return {}
    for odir in sorted(p for p in ko_dir.iterdir() if p.is_dir()):
        if odir.name not in od.objs:
            raise ValueError(f"{odir}: no such object in {od.dat}")
        o = od.objs[odir.name]
        af = od.anim(o.anim)
        by_key = {}
        for p in af.parts:
            by_key.setdefault(libobj.region_key(p), p)
        for png in sorted(odir.glob("*.png")):
            src = f"{od.dat}/{odir.name}/{png.name}"
            if png.stem.startswith("f") and png.stem[1:].isdigit():
                fr = af.frames[int(png.stem[1:])]
                lay, (w, h), _o = libobj.frame_layout(af, fr)
                im = _load_png(png, w, h)
                for i, (p, x0, y0) in enumerate(lay):
                    for q, x1, y1 in lay[:i]:
                        if (x0 < x1 + q.size[0] and x1 < x0 + p.size[0] and y0 < y1 + q.size[1]
                                and y1 < y0 + p.size[1]):
                            raise ValueError(f"{src}: parts overlap on screen; give region PNGs instead")
                for p, x0, y0 in lay:
                    pw, ph = p.size
                    put(o.graph, 128 * p.buf, libobj.part_encode(af, p, im[y0:y0 + ph, x0:x0 + pw]), src)
            elif png.stem in by_key:
                p = by_key[png.stem]
                im = _load_png(png, *p.size)
                put(o.graph, 128 * p.buf, libobj.part_encode(af, p, im, undo_flip=False), src)
            else:
                raise ValueError(f"{png}: not f<frame>.png or a region name")
            log.append(src)
    return {g: {off: d for off, (d, _s) in w.items()} for g, w in writes.items()}


def apply(od: libobj.ObjDat, writes: dict[str, dict[int, bytes]]) -> bytes:
    rep = {}
    for gname, w in writes.items():
        buf = bytearray(od.plain(gname))
        for off, data in w.items():
            if off + len(data) > len(buf):
                raise ValueError(f"{gname}: write past end")
            buf[off:off + len(data)] = data
        rep[od.slot[gname]] = bytes(buf)
    return lib3dx.rebuild_bg4(od.data, rep)


def verify(od: libobj.ObjDat, new: bytes, writes: dict[str, dict[int, bytes]]) -> None:
    nd = libobj.ObjDat(od.game, od.dat, new)
    assert nd.ca_raw == od.ca_raw
    for name, e in enumerate(od.entries):
        pass
    for n, i in od.slot.items():
        a = od.plain(n)
        b = nd.plain(n)
        if n in writes:
            exp = bytearray(a)
            for off, data in writes[n].items():
                exp[off:off + len(data)] = data
            assert b == bytes(exp), n
        else:
            assert b == a, n
            assert nd.entries[i].data == od.entries[i].data, n


def build(out: Path) -> None:
    out.mkdir(parents=True, exist_ok=True)
    total = []
    for dat in libobj.DATS_3DX:
        od = libobj.ObjDat("3DX", dat)
        log: list = []
        writes = collect(od, KO / dat, log)
        if not writes:
            print(dat, "no Korean sprites")
            continue
        new = apply(od, writes)
        verify(od, new, writes)
        (out / f"{dat}.dat").write_bytes(new)
        total += log
        print(dat, f"{len(log)} PNG -> {sum(len(w) for w in writes.values())} regions in "
                   f"{len(writes)} buffers, {len(od.data)} -> {len(new)} bytes, re-read OK")
    print("total PNG", len(total))


def identity() -> bool:
    ok = True
    for dat in libobj.DATS_3DX:
        od = libobj.ObjDat("3DX", dat)
        new = apply(od, {})
        same = new == od.data
        # also rewrite every graph entry with its own decoded->encoded pixels (all lossless formats)
        rep = {}
        for o in od.objs.values():
            af = od.anim(o.anim)
            g = od.plain(o.graph)
            buf = bytearray(g)
            for p in af.parts:
                enc = libobj.part_encode(af, p, libobj.part_rgba(af, g, p, apply_flip=True))
                buf[128 * p.buf:128 * p.buf + len(enc)] = enc
            if bytes(buf) != g:
                ok = False
                print(dat, o.name, "pixel round trip differs")
            rep[od.slot[o.graph]] = bytes(buf)
        print(dat, "rebuild_bg4(x,{})==x:", same, "| pixel decode->encode round trip on",
              len(rep), "buffers")
        ok &= same
    return ok


def selftest() -> bool:
    """Replace one text sprite frame with a pattern, rebuild, re-read, compare pixels."""
    od = libobj.ObjDat("3DX", "BUI")
    o = od.objs["bui_sys_font_JP_ja"]
    af = od.anim(o.anim)
    g = od.plain(o.graph)
    fr = af.frames[0]
    lay, (w, h), _ = libobj.frame_layout(af, fr)
    rng = np.random.default_rng(3)
    pat = (rng.integers(0, 16, (h, w, 4)) * 17).astype(np.uint8)
    writes = {o.graph: {}}
    for p, x0, y0 in lay:
        pw, ph = p.size
        writes[o.graph][128 * p.buf] = libobj.part_encode(af, p, pat[y0:y0 + ph, x0:x0 + pw])
    new = apply(od, writes)
    verify(od, new, writes)
    nd = libobj.ObjDat("3DX", "BUI", new)
    img = libobj.render_frame(nd.anim(o.anim), nd.plain(o.graph), fr)
    ok = bool((img == pat).all())
    print("selftest BUI/bui_sys_font_JP_ja f000:", "OK" if ok else "MISMATCH", len(od.data), "->", len(new))
    return ok


def check(stage: Path) -> bool:
    """Re-read the staged dats on their own: every Korean region PNG must decode back exactly
    (after the texture format's quantisation), every other part and every non-graph entry must be
    byte-identical to the original."""
    ok = True
    for dat in libobj.DATS_3DX:
        p = stage / f"{dat}.dat"
        if not p.exists():
            continue
        od = libobj.ObjDat("3DX", dat)
        nd = libobj.ObjDat("3DX", dat, p.read_bytes())
        assert nd.ca_raw == od.ca_raw
        changed_graphs = set()
        n_png = n_same = 0
        for odir in sorted(x for x in (KO / dat).iterdir() if x.is_dir()):
            o = od.objs[odir.name]
            af = od.anim(o.anim)
            by_key = {}
            for pt in af.parts:
                by_key.setdefault(libobj.region_key(pt), pt)
            g_new = nd.plain(o.graph)
            for png in odir.glob("*.png"):
                pt = by_key[png.stem]
                w, h = pt.size
                want = _load_png(png, w, h)
                want_q = libtex3ds.decode(libtex3ds.encode(want, af.fmt, flip=False), af.fmt, w, h, flip=False)
                got = libobj.part_rgba(af, g_new, pt, apply_flip=False)
                n_png += 1
                if not np.array_equal(got, want_q):
                    ok = False
                    print("MISMATCH", dat, odir.name, png.name)
            changed_graphs.add(o.graph)
        for n in od.slot:
            if n in changed_graphs:
                continue
            if nd.plain(n) != od.plain(n):
                ok = False
                print("UNEXPECTED CHANGE", dat, n)
            else:
                n_same += 1
        print(dat, f"{n_png} Korean regions decode back exactly; {n_same} other entries unchanged;"
                   f" {len(changed_graphs)} graph entries changed")
    return ok


def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("cmd", choices=["extract", "identity", "selftest", "build", "check"])
    ap.add_argument("--out", default=str(STAGE))
    a = ap.parse_args()
    if a.cmd == "extract":
        extract()
    elif a.cmd == "identity":
        sys.exit(0 if identity() else 1)
    elif a.cmd == "selftest":
        sys.exit(0 if selftest() else 1)
    elif a.cmd == "check":
        sys.exit(0 if check(Path(a.out)) else 1)
    else:
        build(Path(a.out))


if __name__ == "__main__":
    main()
