"""Static "link" of a game's CRO modules for analysis (60fps investigation).

The real RO service loads each CRO at a heap address chosen at runtime. For static analysis we
place every CRO at a fixed, documented base, apply its internal relocations and bind its imports
against the static module (static.crs exports) and the other CROs. Only ABS32/TARGET1 (2/38) and
REL32 (3) are applied, exactly like Azahar's ldr_ro (games only use these).

Outputs (work/fps60/link/<game>/):
    <Module>.bin          relocated image, first byte = module base
    link.json             {modules: {name: {base, size, segments:[...], exports:{name: addr}}},
                           static_imports_bound: {name: addr}, unresolved: [...]}
    symbols.tsv           addr<TAB>module<TAB>name for every named export (static + CROs)

Analysis bases: module k (sorted by file name) -> 0x10000000 + k * 0x00800000.
Segment layout inside a module: text/rodata/data stay at their file offsets, .bss at
align(file_size, 0x1000). (At runtime .data may be copied elsewhere; offsets inside stay valid.)

    python scripts/fps60/crolink.py 3dx_v12      # romf2/RO (v1.2 RomFS overlay over romfs)
    python scripts/fps60/crolink.py 1dx_kr       # ml 1dx/3romfs/RO
"""
from __future__ import annotations

import json
import os
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from cro import CRO  # noqa: E402

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
GAMES = {
    "3dx_v12": ["romf2/RO", "romfs/RO"],
    "3dx_v10": ["romfs/RO"],
    "1dx_kr": ["ml 1dx/3romfs/RO"],
}
BASE0, STRIDE = 0x10000000, 0x00800000


def ro_files(game: str) -> dict[str, str]:
    files: dict[str, str] = {}
    for d in GAMES[game]:
        full = os.path.join(ROOT, d)
        for fn in os.listdir(full):
            if fn.endswith((".cro", ".crs")) and fn not in files:
                files[fn] = os.path.join(full, fn)
    return dict(sorted(files.items()))


def align(x: int, a: int) -> int:
    return (x + a - 1) // a * a


class Module:
    def __init__(self, name: str, cro: CRO, base: int):
        self.name, self.cro, self.base = name, cro, base
        self.image = bytearray(cro.data)
        self.bss_addr = base + align(len(cro.data), 0x1000)
        self.seg_addr = []
        for s in cro.segments:
            if s.type == 3:
                self.seg_addr.append(self.bss_addr if s.size else 0)
            else:
                self.seg_addr.append(base + s.offset if (s.offset or s.size) else 0)
        self.exports = {n: self.seg_addr[seg] + off for n, seg, off in cro.named_exports()}
        self.indexed = [self.seg_addr[seg] + off for _i, seg, off in cro.indexed_exports()]

    def addr_of(self, seg: int, off: int) -> int:
        return self.seg_addr[seg] + off

    def write32(self, addr: int, value: int) -> bool:
        o = addr - self.base
        if 0 <= o <= len(self.image) - 4:
            struct.pack_into("<I", self.image, o, value & 0xFFFFFFFF)
            return True
        return False  # .bss target (nothing stored in file)


def apply(mod: Module, target: int, typ: int, addend: int, sym: int) -> str | None:
    if typ == 0:
        return None
    if typ in (2, 38):
        ok = mod.write32(target, sym + addend)
    elif typ == 3:
        ok = mod.write32(target, sym + addend - target)
    else:
        return f"unsupported reloc type {typ} at {target:#x}"
    return None if ok else f"target {target:#x} outside image (bss?)"


def link(game: str) -> dict:
    files = ro_files(game)
    static_path = files.pop("static.crs")
    crs = CRO.load(static_path)
    static_exports = {n: crs.segments[seg].offset + off for n, seg, off in crs.named_exports()}
    mods: dict[str, Module] = {}
    for k, (fn, path) in enumerate(files.items()):
        cro = CRO.load(path)
        mods[cro.module_name] = Module(cro.module_name, cro, BASE0 + k * STRIDE)
    global_exports: dict[str, tuple[str, int]] = {n: ("|static|", a) for n, a in static_exports.items()}
    for m in mods.values():
        for n, a in m.exports.items():
            global_exports.setdefault(n, (m.name, a))

    problems: list[str] = []
    unresolved: list[str] = []
    for m in mods.values():
        cro = m.cro
        # internal relocations: symbol = base of symbol segment + addend
        for r in cro.internal_relocs():
            t = m.addr_of(r.seg, r.off)
            p = apply(m, t, r.type, r.addend, m.seg_addr[r.extra])
            if p:
                problems.append(f"{m.name} internal: {p}")
        # named imports
        for imp in cro.named_imports():
            hit = global_exports.get(imp.name)
            if hit is None:
                unresolved.append(f"{m.name}: {imp.name}")
                continue
            for r in imp.relocs:
                p = apply(m, m.addr_of(r.seg, r.off), r.type, r.addend, hit[1])
                if p:
                    problems.append(f"{m.name} import {imp.name}: {p}")
        # indexed / anonymous imports by module
        for im in cro.import_modules():
            src = mods.get(im["name"])
            for idx, relocs in im["indexed"]:
                if src is None or idx >= len(src.indexed):
                    unresolved.append(f"{m.name}: {im['name']}#idx{idx}")
                    continue
                for r in relocs:
                    p = apply(m, m.addr_of(r.seg, r.off), r.type, r.addend, src.indexed[idx])
                    if p:
                        problems.append(f"{m.name} idx import: {p}")
            for seg, off, relocs in im["anonymous"]:
                if src is None:
                    unresolved.append(f"{m.name}: {im['name']}#anon")
                    continue
                for r in relocs:
                    p = apply(m, m.addr_of(r.seg, r.off), r.type, r.addend, src.addr_of(seg, off))
                    if p:
                        problems.append(f"{m.name} anon import: {p}")

    # static module imports (slots in static .data patched when CROs load)
    static_bound = {}
    for imp in crs.named_imports():
        hit = global_exports.get(imp.name)
        static_bound[imp.name] = hit[1] if hit else None
        if hit is None:
            unresolved.append(f"|static|: {imp.name}")

    out_dir = os.path.join(ROOT, "work", "fps60", "link", game)
    os.makedirs(out_dir, exist_ok=True)
    info = {"game": game, "base0": BASE0, "stride": STRIDE, "modules": {}, "static_imports_bound": static_bound,
            "unresolved": unresolved, "problems": problems[:200], "problem_count": len(problems)}
    for m in mods.values():
        with open(os.path.join(out_dir, f"{m.name}.bin"), "wb") as f:
            f.write(m.image)
        info["modules"][m.name] = {
            "file": os.path.relpath(m.cro.path, ROOT).replace("\\", "/"),
            "base": m.base, "size": len(m.image), "bss": [m.bss_addr, m.cro.h["BssSize"]],
            "segments": [{"index": s.index, "type": s.name, "addr": m.seg_addr[s.index], "size": s.size}
                         for s in m.cro.segments],
            "exports": m.exports,
            "onload": m.cro.h["OnLoadSegmentTag"], "onexit": m.cro.h["OnExitSegmentTag"],
        }
    with open(os.path.join(out_dir, "link.json"), "w", encoding="utf-8") as f:
        json.dump(info, f, indent=1)
    with open(os.path.join(out_dir, "symbols.tsv"), "w", encoding="utf-8") as f:
        rows = [(a, "|static|", n) for n, a in static_exports.items()]
        for m in mods.values():
            rows += [(a, m.name, n) for n, a in m.exports.items()]
        for a, mn, n in sorted(rows):
            f.write(f"{a:#010x}\t{mn}\t{n}\n")
    return info


if __name__ == "__main__":
    game = sys.argv[1] if len(sys.argv) > 1 else "3dx_v12"
    info = link(game)
    for n, m in info["modules"].items():
        print(f"{n:16s} base {m['base']:#010x} size {m['size']:#x} exports {len(m['exports'])}")
    print("unresolved:", len(info["unresolved"]), info["unresolved"][:15])
    print("problems:", info["problem_count"], info["problems"][:10])
