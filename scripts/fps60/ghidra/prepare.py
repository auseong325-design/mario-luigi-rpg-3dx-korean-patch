"""Build the Ghidra import layout for one game (fps60 workstream TG).

    python scripts/fps60/ghidra/prepare.py 3dx_v12     # -> work/fps60/ghidra/3dx_v12/layout.tsv
    python scripts/fps60/ghidra/prepare.py 1dx_kr

The layout is read by ImportLayout.java (pre-analysis) and PostAnalysis.java. It puts the static
code.bin at 0x100000 and every relocated CRO image (work/fps60/link/<game>/<Module>.bin, made by
scripts/fps60/crolink.py) at its analysis base, all in ONE program. Rows (tab separated):

    STATIC   <code.bin path> <load length>              static image, imported by BinaryLoader
    BLOCK    <name> <start> <size> <perm> <file> <file offset>   initialised block (perm r/rw/rx)
    BSS      <name> <start> <size> <perm>               uninitialised block
    PATCH32  <addr> <value> <note>                      static import slot bound to a CRO export
    FUNC     <addr> <thumb> <name|-> <namespace|-> <why>     function entry (name may be mangled)
    LABEL    <addr> <name> <namespace|->                data label
    VENEER   <addr> <target>                            'ldr pc,[pc,#-4]; .word target' import veneer
    VTSLOT   <func addr> <class path> <slot offset>     unnamed virtual function -> Class::vfunc_<off>
    COMMENT  <addr> <text>                              plate comment

Sources: segment sizes from the exheaders (3DX values by the lead, 1DX parsed from the .3ds) and
the static.crs segment table; symbols from work/fps60/link/<game>/symbols.tsv; static import slots
from static.crs named imports bound in link.json; RTTI/vtables by scanning rodata/data for
Itanium-ABI type_info objects (armcc uses the ARM C++ ABI).
"""
from __future__ import annotations

import bisect
import collections
import json
import os
import re
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(os.path.dirname(os.path.dirname(HERE)))
sys.path.insert(0, os.path.join(ROOT, "scripts", "fps60"))
from cro import CRO  # noqa: E402  (lead-owned parser, used read-only)

BASE = 0x100000
# text/ro/data = (address, size in bytes); bss = size. Data and bss sizes come from the exheader.
GAMES = {
    "3dx_v12": dict(bin="work/fps60/bin/3dx_v12.code.bin", crs="romf2/RO/static.crs",
                    text=(0x100000, 0x288BD8), ro=(0x389000, 0x65E50), data=(0x3EF000, 0x9170), bss=0x3CBD0),
    "1dx_kr": dict(bin="work/fps60/bin/1dx_kr.code.bin", crs="ml 1dx/3romfs/RO/static.crs",
                   text=(0x100000, 0x33FBC4), ro=(0x440000, 0x56BC4), data=(0x497000, 0xA2E8), bss=0x25AE8),
}
# Kernel config memory / shared page fields used by the engine (3dbrew).
HW_LABELS = [
    (0x1FF80030, "CFGMEM_APPMEMTYPE"), (0x1FF80040, "CFGMEM_APPMEMALLOC"), (0x1FF80044, "CFGMEM_SYSMEMALLOC"),
    (0x1FF80048, "CFGMEM_BASEMEMALLOC"), (0x1FF80014, "CFGMEM_ENVINFO"), (0x1FF80015, "CFGMEM_UNITINFO"),
    (0x1FF81000, "SHAREDPAGE_DATETIME_SELECTOR"), (0x1FF81002, "SHAREDPAGE_RUNNING_HW"),
    (0x1FF81020, "SHAREDPAGE_DATETIME_0"), (0x1FF81040, "SHAREDPAGE_DATETIME_1"),
    (0x1FF81080, "SHAREDPAGE_3D_SLIDERSTATE"), (0x1FF81084, "SHAREDPAGE_3D_LEDSTATE"),
    (0x1FF81085, "SHAREDPAGE_BATTERY_STATE"), (0x1FF810C0, "SHAREDPAGE_HEADSET_CONNECTED"),
]
VENEER_OP = b"\x04\xf0\x1f\xe5"  # ldr pc, [pc, #-4]


def page(x: int) -> int:
    return (x + 0xFFF) & ~0xFFF


class Space:
    """Analysis address space: static image + relocated CRO images (read-only view)."""

    def __init__(self) -> None:
        self.regions: list[tuple[int, bytes, str]] = []
        self.starts: list[int] = []

    def add(self, start: int, data: bytes, name: str) -> None:
        self.regions.append((start, data, name))
        self.regions.sort(key=lambda r: r[0])
        self.starts = [r[0] for r in self.regions]

    def read(self, addr: int, n: int) -> bytes:
        i = bisect.bisect_right(self.starts, addr) - 1
        if i < 0:
            return b""
        start, data, _ = self.regions[i]
        o = addr - start
        return data[o:o + n] if 0 <= o < len(data) else b""

    def u32(self, addr: int) -> int | None:
        b = self.read(addr, 4)
        return struct.unpack("<I", b)[0] if len(b) == 4 else None

    def cstr(self, addr: int, limit: int = 256) -> bytes | None:
        b = self.read(addr, limit)
        z = b.find(b"\0")
        return b[:z] if z > 0 else None


class Ranges:
    def __init__(self, items: list[tuple[int, int, str]]):
        self.items = sorted(items)
        self.starts = [s for s, _e, _n in self.items]

    def find(self, addr: int) -> str | None:
        i = bisect.bisect_right(self.starts, addr) - 1
        if i >= 0 and addr < self.items[i][1]:
            return self.items[i][2]
        return None


def demangle_class(s: str) -> str | None:
    """'N2ad2fw8TaskBaseE' -> 'ad::fw::TaskBase', '7MyClass' -> 'MyClass'; None for templates/std/etc."""
    def ident(t: str, i: int):
        m = re.match(r"(\d+)", t[i:])
        if not m:
            return None, i
        n = int(m.group(1))
        j = i + len(m.group(1))
        name = t[j:j + n]
        if len(name) != n or not re.fullmatch(r"[A-Za-z_][A-Za-z0-9_]*", name):
            return None, i
        return name, j + n
    if s.startswith("N") and s.endswith("E"):
        parts, i, body = [], 1, s
        while i < len(body) - 1:
            name, i2 = ident(body, i)
            if name is None:
                return None
            parts.append(name)
            i = i2
        return "::".join(parts) if parts and i == len(body) - 1 else None
    name, i = ident(s, 0)
    return name if name is not None and i == len(s) else None


def main(game: str) -> None:
    cfg = GAMES[game]
    out_dir = os.path.join(ROOT, "work", "fps60", "ghidra", game)
    os.makedirs(out_dir, exist_ok=True)
    link = json.load(open(os.path.join(ROOT, "work", "fps60", "link", game, "link.json"), encoding="utf-8"))
    link_dir = os.path.join(ROOT, "work", "fps60", "link", game)
    rows: list[str] = []
    stats = collections.Counter()

    def row(*cols) -> None:
        rows.append("\t".join(str(c) for c in cols))

    # ---------------- static image ----------------
    static_path = os.path.join(ROOT, cfg["bin"])
    static = bytearray(open(static_path, "rb").read())
    (t_addr, t_size), (r_addr, r_size), (d_addr, d_size) = cfg["text"], cfg["ro"], cfg["data"]
    load_len = d_addr + d_size - BASE
    assert len(static) >= load_len, (len(static), load_len)
    crs = CRO.load(os.path.join(ROOT, cfg["crs"]))
    segs = {}
    for s in crs.segments:  # first non-empty segment of each type (seg4 is a small extra rodata at 0x04000000)
        if s.size and s.name not in segs:
            segs[s.name] = s
    assert segs["text"].offset == t_addr and segs["text"].size == t_size, "text segment mismatch vs static.crs"
    assert segs["rodata"].offset == r_addr and segs["rodata"].size == r_size, "rodata segment mismatch vs static.crs"
    assert segs["data"].offset == d_addr and segs["data"].size == d_size + cfg["bss"], "data+bss mismatch vs static.crs"
    row("STATIC", static_path, hex(load_len))
    row("BLOCK", "static.text", hex(t_addr), hex(page(t_addr + t_size) - t_addr), "rx", static_path, hex(t_addr - BASE))
    row("BLOCK", "static.rodata", hex(r_addr), hex(d_addr - r_addr), "r", static_path, hex(r_addr - BASE))
    row("BLOCK", "static.data", hex(d_addr), hex(d_size), "rw", static_path, hex(d_addr - BASE))
    row("BSS", "static.bss", hex(d_addr + d_size), hex(cfg["bss"]), "rw")
    # rw (not r): the decompiler constant-folds loads from non-writable memory, and these pages have no bytes
    row("BSS", "hw.cfgmem", hex(0x1FF80000), hex(0x1000), "rw")
    row("BSS", "hw.sharedpage", hex(0x1FF81000), hex(0x1000), "rw")
    text_ranges = [(t_addr, t_addr + t_size, "static")]
    data_ranges = [(r_addr, r_addr + r_size, "static"), (d_addr, d_addr + d_size, "static")]

    # static import slots (patched by RO when the CROs load) -> bind to CRO analysis addresses
    bound = link.get("static_imports_bound", {})
    seg_by_index = {s.index: s for s in crs.segments}
    for imp in crs.named_imports():
        target = bound.get(imp.name)
        if target is None:
            stats["static_import_unbound"] += 1
            continue
        for r in imp.relocs:
            if r.type == 0:
                continue
            at = seg_by_index[r.seg].offset + r.off
            if r.type in (2, 38):
                val = (target + r.addend) & 0xFFFFFFFF
            elif r.type == 3:
                val = (target + r.addend - at) & 0xFFFFFFFF
            else:
                stats["static_import_reloc_unsupported"] += 1
                continue
            o = at - BASE
            if 0 <= o <= load_len - 4:
                struct.pack_into("<I", static, o, val)
                row("PATCH32", hex(at), hex(val), "import " + imp.name)
                stats["static_import_patched"] += 1
            else:
                stats["static_import_target_outside"] += 1
    if crs.h["ImportModuleNum"]:
        stats["static_import_modules_ignored"] = crs.h["ImportModuleNum"]

    space = Space()
    space.add(BASE, bytes(static[:load_len]), "static")

    # ---------------- CRO images ----------------
    module_bases = []
    for mname, m in link["modules"].items():
        base, size = m["base"], m["size"]
        path = os.path.join(link_dir, f"{mname}.bin")
        data = open(path, "rb").read()
        assert len(data) == size, (mname, len(data), size)
        space.add(base, data, mname)
        module_bases.append((base, mname))
        segl = [s for s in m["segments"] if s["size"] and s["type"] != "bss"]
        segl.sort(key=lambda s: s["addr"])
        cuts = []  # (start, end, kind)
        for s in segl:
            cuts.append((s["addr"], s["addr"] + s["size"], s["type"]))
        pos, gap_no = base, 0
        perm = {"text": "rx", "rodata": "r", "data": "rw"}
        for (s, e, kind) in cuts:
            if s > pos:
                gname = "hdr" if pos == base else ("tables" if kind == "data" else f"pad{gap_no}")
                gap_no += 1
                row("BLOCK", f"{mname}.{gname}", hex(pos), hex(s - pos), "r", path, hex(pos - base))
            row("BLOCK", f"{mname}.{kind}", hex(s), hex(e - s), perm[kind], path, hex(s - base))
            if kind == "text":
                text_ranges.append((s, e, mname))
            else:
                data_ranges.append((s, e, mname))
            pos = e
        if pos < base + size:
            row("BLOCK", f"{mname}.tail", hex(pos), hex(base + size - pos), "r", path, hex(pos - base))
        bss_addr, bss_hdr = m["bss"]
        bss_seg = max([s["size"] for s in m["segments"] if s["type"] == "bss"] + [0])
        bss_size = max(bss_hdr, bss_seg)
        if bss_size:
            row("BSS", f"{mname}.bss", hex(bss_addr), hex(page(bss_size)), "rw")
        row("LABEL", hex(base), f"{mname}_cro_base", "-")
        row("COMMENT", hex(base), f"CRO {mname} ({m['file']}) at analysis base {base:#x}; "
                                  f"file offset = address - {base:#x}. NOT the runtime address.")
        # CRO control entry points
        cro = CRO.load(os.path.join(ROOT, m["file"]))
        for tag_name, fname in (("OnLoadSegmentTag", "cro_OnLoad"), ("OnExitSegmentTag", "cro_OnExit"),
                                ("OnUnresolvedSegmentTag", "cro_OnUnresolved")):
            tag = cro.h[tag_name]
            if tag != 0xFFFFFFFF:
                seg, off = tag & 0xF, tag >> 4
                addr = m["segments"][seg]["addr"] + off
                row("FUNC", hex(addr & ~1), addr & 1, fname, mname, "cro-control")
    tr = Ranges(text_ranges)
    dr = Ranges(data_ranges)

    def is_code_ptr(v: int | None) -> bool:
        return v is not None and v != 0 and tr.find(v & ~1) is not None and ((v & 1) or (v & 3) == 0)

    # ---------------- symbols ----------------
    named: dict[int, str] = {}
    for line in open(os.path.join(link_dir, "symbols.tsv"), encoding="utf-8"):
        a_s, mod, name = line.rstrip("\n").split("\t")
        a = int(a_s, 16)
        mod = "static" if mod == "|static|" else mod
        ns = "-" if (name.startswith("_Z") or mod == "static") else mod
        if tr.find(a & ~1):
            row("FUNC", hex(a & ~1), a & 1, name, ns, "export")
            stats["func_export"] += 1
        else:
            row("LABEL", hex(a & ~1), name, ns)
            stats["label_export"] += 1
        named.setdefault(a & ~1, name)
    for a, n in HW_LABELS:
        row("LABEL", hex(a), n, "-")

    # ---------------- veneers ----------------
    unresolved_stub = None
    if crs.h["OnUnresolvedSegmentTag"] != 0xFFFFFFFF:
        tag = crs.h["OnUnresolvedSegmentTag"]
        unresolved_stub = seg_by_index[tag & 0xF].offset + (tag >> 4)
        row("FUNC", hex(unresolved_stub & ~1), unresolved_stub & 1, "ro_unresolved_import_stub", "-", "crs-control")
    for s, e, mod in text_ranges:
        data = space.read(s, e - s)
        i = data.find(VENEER_OP)
        while i >= 0:
            if i % 4 == 0 and i + 8 <= len(data):
                tgt = struct.unpack_from("<I", data, i + 4)[0]
                if tr.find(tgt & ~1):
                    row("VENEER", hex(s + i), hex(tgt))
                    stats[f"veneer_{'static' if mod == 'static' else 'cro'}"] += 1
            i = data.find(VENEER_OP, i + 1)

    # ---------------- RTTI ----------------
    ident_re = re.compile(rb"[A-Za-z0-9_]{2,200}")
    cands = []  # (addr, w0, type string, string addr)
    for s, e, mod in data_ranges:
        data = space.read(s, e - s)
        for o in range(0, len(data) - 7, 4):
            w1 = struct.unpack_from("<I", data, o + 4)[0]
            if dr.find(w1) is None:
                continue
            st = space.cstr(w1, 210)
            if not st or st[:1] not in b"N0123456789S" or not ident_re.fullmatch(st):
                continue
            w0 = struct.unpack_from("<I", data, o)[0]
            cands.append((s + o, w0, st.decode("ascii"), w1))
    seeds = set()
    for a, n in named.items():
        if n.startswith("_ZTI"):
            v = space.u32(a)
            if v:
                seeds.add(v)
    counts = collections.Counter(w0 for _a, w0, _s, _w1 in cands)
    abi = set(seeds)
    for v, c in counts.items():
        if c >= 2 and seeds and min(abs(v - x) for x in seeds) < 0x400 and dr.find(v) is not None:
            abi.add(v)
    if not seeds:  # fall back to the three most frequent (vptr, name) pairs
        abi = {v for v, c in counts.most_common(3) if c >= 4}
    stats["rtti_abi_vtables"] = len(abi)
    tinfo: dict[int, str] = {}
    tname_addr: dict[int, int] = {}
    for a, w0, st, w1 in cands:
        if w0 in abi:
            tinfo[a] = st
            tname_addr[a] = w1
    # classify abi vtables by structure (si: +8 is a type_info; vmi: +12 count, +16 type_info)
    kind_of_abi = {}
    for v in abi:
        group = [a for a, w0, _s, _w in cands if w0 == v and a in tinfo]
        if not group:
            continue
        si = sum(1 for a in group if space.u32(a + 8) in tinfo)
        vmi = sum(1 for a in group if (space.u32(a + 12) or 0) in range(1, 33) and space.u32(a + 16) in tinfo)
        k = "si" if si >= 0.8 * len(group) else ("vmi" if vmi >= 0.8 * len(group) else "class")
        kind_of_abi[v] = k
    bases: dict[int, list[int]] = {}
    for a in tinfo:
        k = kind_of_abi.get(space.u32(a))
        if k == "si":
            bases[a] = [space.u32(a + 8)]
        elif k == "vmi":
            n = space.u32(a + 12) or 0
            bases[a] = [b for b in (space.u32(a + 16 + 8 * i) for i in range(n)) if b in tinfo]
        else:
            bases[a] = []
    for a, st in tinfo.items():
        if a not in named:
            row("LABEL", hex(a), "_ZTI" + st, "-")
            stats["rtti_typeinfo_new"] += 1
        if tname_addr[a] not in named:
            row("LABEL", hex(tname_addr[a]), "_ZTS" + st, "-")
    stats["rtti_typeinfo_total"] = len(tinfo)

    def ancestors(t: int, seen=None) -> set[int]:
        seen = set() if seen is None else seen
        for b in bases.get(t, []):
            if b not in seen:
                seen.add(b)
                ancestors(b, seen)
        return seen

    # vtables: [offset_to_top][type_info*][slot0][slot1]...
    vt_refs: dict[int, list[tuple[int, int]]] = collections.defaultdict(list)  # func -> [(typeinfo, slot off)]
    for s, e, mod in data_ranges:
        data = space.read(s, e - s)
        for o in range(4, len(data) - 7, 4):
            w = struct.unpack_from("<I", data, o)[0]
            if w not in tinfo:
                continue
            ott = struct.unpack_from("<i", data, o - 4)[0]
            if not (-0x10000 <= ott <= 0) or ott % 4:
                continue
            first = struct.unpack_from("<I", data, o + 4)[0]
            if not is_code_ptr(first):
                continue
            vt = s + o - 4
            slots = []
            p = o + 4
            while p + 4 <= len(data):
                v = struct.unpack_from("<I", data, p)[0]
                if not is_code_ptr(v) or (v in tinfo):
                    break
                slots.append(v)
                p += 4
            st = tinfo[w]
            if vt not in named:
                lbl = ("_ZTV" + st) if ott == 0 else f"vtable_sec{-ott:#x}__ZTV{st}"
                row("LABEL", hex(vt), lbl, "-")
            row("COMMENT", hex(vt), f"vtable for {demangle_class(st) or st} (offset_to_top {ott}); "
                                    f"address point {vt + 8:#x}; {len(slots)} slots")
            row("VTABLE", hex(vt), demangle_class(st) or "-", ott, len(slots), st)
            stats["vtables_primary" if ott == 0 else "vtables_secondary"] += 1
            for i, v in enumerate(slots):
                row("FUNC", hex(v & ~1), v & 1, "-", "-", "vtable-slot")
                if ott == 0:
                    vt_refs[v & ~1].append((w, 4 * i))
    for f, refs in vt_refs.items():
        if f in named:
            continue
        owners = {t for t, _o in refs}
        owner = None
        if len(owners) == 1:
            owner = next(iter(owners))
        else:
            for c in owners:
                if all(c == o or c in ancestors(o) for o in owners):
                    owner = c
                    break
        if owner is None:
            stats["vtslot_ambiguous"] += 1
            continue
        cls = demangle_class(tinfo[owner])
        if not cls:
            stats["vtslot_unnamed_class"] += 1
            continue
        off = min(o for t, o in refs if t == owner)
        row("VTSLOT", hex(f), cls, hex(off))
        stats["vtslot_named"] += 1

    out = os.path.join(out_dir, "layout.tsv")
    with open(out, "w", encoding="utf-8", newline="\n") as fh:
        fh.write(f"# fps60 TG Ghidra layout for {game}; generated by scripts/fps60/ghidra/prepare.py\n")
        fh.write("\n".join(rows) + "\n")
    kinds = collections.Counter(r.split("\t", 1)[0] for r in rows)
    print(f"wrote {out}: {len(rows)} rows {dict(kinds)}")
    print("stats:", dict(sorted(stats.items())))


if __name__ == "__main__":
    main(sys.argv[1] if len(sys.argv) > 1 else "3dx_v12")
