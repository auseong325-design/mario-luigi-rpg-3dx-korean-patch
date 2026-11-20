"""CRO0 / CRS parser (3DS relocatable modules) for the 60fps investigation.

Layout follows Azahar/Citra src/core/hle/service/ldr_ro/cro_helper.h.
Header fields start at 0x80 (after the 0x80-byte hash area), 4 bytes each.

Usage:
    python scripts/fps60/cro.py romf2/RO/static.crs            # summary
    python scripts/fps60/cro.py romf2/RO/Battle.cro --exports   # list exports
    python scripts/fps60/cro.py romf2/RO/Battle.cro --imports   # list named imports
"""
from __future__ import annotations

import struct
import sys
from dataclasses import dataclass, field

HEADER_FIELDS = [
    "Magic", "NameOffset", "NextCRO", "PreviousCRO", "FileSize", "BssSize", "FixedSize",
    "UnknownZero", "UnkSegmentTag", "OnLoadSegmentTag", "OnExitSegmentTag", "OnUnresolvedSegmentTag",
    "CodeOffset", "CodeSize", "DataOffset", "DataSize", "ModuleNameOffset", "ModuleNameSize",
    "SegmentTableOffset", "SegmentNum",
    "ExportNamedSymbolTableOffset", "ExportNamedSymbolNum", "ExportIndexedSymbolTableOffset",
    "ExportIndexedSymbolNum", "ExportStringsOffset", "ExportStringsSize", "ExportTreeTableOffset",
    "ExportTreeNum",
    "ImportModuleTableOffset", "ImportModuleNum", "ExternalRelocationTableOffset", "ExternalRelocationNum",
    "ImportNamedSymbolTableOffset", "ImportNamedSymbolNum", "ImportIndexedSymbolTableOffset",
    "ImportIndexedSymbolNum", "ImportAnonymousSymbolTableOffset", "ImportAnonymousSymbolNum",
    "ImportStringsOffset", "ImportStringsSize",
    "StaticAnonymousSymbolTableOffset", "StaticAnonymousSymbolNum", "InternalRelocationTableOffset",
    "InternalRelocationNum", "StaticRelocationTableOffset", "StaticRelocationNum",
]
SEG_TYPES = {0: "text", 1: "rodata", 2: "data", 3: "bss"}
# Relocation types (ARM ELF numbering as used by RO)
R_ARM_NONE, R_ARM_ABS32, R_ARM_REL32, R_ARM_THM_PC22, R_ARM_CALL, R_ARM_JUMP24, R_ARM_TARGET1, R_ARM_PREL31 = 0, 2, 3, 10, 28, 29, 38, 42


@dataclass
class Segment:
    index: int
    offset: int  # file offset for CRO, address/offset as stored for CRS
    size: int
    type: int

    @property
    def name(self) -> str:
        return SEG_TYPES.get(self.type, f"seg{self.type}")


@dataclass
class Reloc:
    seg: int
    off: int
    type: int
    is_end: int
    extra: int  # is_resolved (external) or symbol_segment (internal)
    addend: int


@dataclass
class Import:
    name: str
    batch_offset: int
    relocs: list = field(default_factory=list)


class CRO:
    def __init__(self, data: bytes, path: str = ""):
        self.data = data
        self.path = path
        if data[0x80:0x84] != b"CRO0":
            raise ValueError(f"{path}: not a CRO0/CRS (magic {data[0x80:0x84]!r})")
        self.h = {name: struct.unpack_from("<I", data, 0x80 + 4 * i)[0] for i, name in enumerate(HEADER_FIELDS)}
        self.segments = [
            Segment(i, *struct.unpack_from("<III", data, self.h["SegmentTableOffset"] + 12 * i))
            for i in range(self.h["SegmentNum"])
        ]

    @classmethod
    def load(cls, path: str) -> "CRO":
        with open(path, "rb") as f:
            return cls(f.read(), path)

    # ---- helpers -------------------------------------------------------
    def cstr(self, off: int) -> str:
        end = self.data.index(b"\0", off)
        return self.data[off:end].decode("ascii", "replace")

    @property
    def module_name(self) -> str:
        n = self.h["ModuleNameSize"]
        return self.data[self.h["ModuleNameOffset"]:self.h["ModuleNameOffset"] + n].rstrip(b"\0").decode("ascii", "replace")

    @staticmethod
    def split_tag(tag: int) -> tuple[int, int]:
        return tag & 0xF, tag >> 4

    def tag_to_fileoff(self, tag: int) -> int:
        seg, off = self.split_tag(tag)
        return self.segments[seg].offset + off

    # ---- tables ----------------------------------------------------------
    def named_exports(self) -> list[tuple[str, int, int]]:
        """[(name, segment_index, offset_in_segment)]"""
        out = []
        base = self.h["ExportNamedSymbolTableOffset"]
        for i in range(self.h["ExportNamedSymbolNum"]):
            noff, tag = struct.unpack_from("<II", self.data, base + 8 * i)
            seg, off = self.split_tag(tag)
            out.append((self.cstr(noff), seg, off))
        return out

    def indexed_exports(self) -> list[tuple[int, int, int]]:
        out = []
        base = self.h["ExportIndexedSymbolTableOffset"]
        for i in range(self.h["ExportIndexedSymbolNum"]):
            (tag,) = struct.unpack_from("<I", self.data, base + 4 * i)
            seg, off = self.split_tag(tag)
            out.append((i, seg, off))
        return out

    def _reloc_batch(self, table_off: int, batch_off: int) -> list[Reloc]:
        out = []
        p = batch_off
        while True:
            tag, typ, end, extra, _pad, addend = struct.unpack_from("<IBBBBI", self.data, p)
            seg, off = self.split_tag(tag)
            out.append(Reloc(seg, off, typ, end, extra, addend))
            if end or len(out) > 100000:
                break
            p += 12
        return out

    def named_imports(self) -> list[Import]:
        out = []
        base = self.h["ImportNamedSymbolTableOffset"]
        for i in range(self.h["ImportNamedSymbolNum"]):
            noff, boff = struct.unpack_from("<II", self.data, base + 8 * i)
            imp = Import(self.cstr(noff), boff)
            imp.relocs = self._reloc_batch(self.h["ExternalRelocationTableOffset"], boff)
            out.append(imp)
        return out

    def import_modules(self) -> list[dict]:
        out = []
        base = self.h["ImportModuleTableOffset"]
        for i in range(self.h["ImportModuleNum"]):
            noff, ioff, inum, aoff, anum = struct.unpack_from("<IIIII", self.data, base + 20 * i)
            mod = {"name": self.cstr(noff), "indexed": [], "anonymous": []}
            for j in range(inum):
                idx, boff = struct.unpack_from("<II", self.data, ioff + 8 * j)
                mod["indexed"].append((idx, self._reloc_batch(0, boff)))
            for j in range(anum):
                tag, boff = struct.unpack_from("<II", self.data, aoff + 8 * j)
                seg, off = self.split_tag(tag)
                mod["anonymous"].append((seg, off, self._reloc_batch(0, boff)))
            out.append(mod)
        return out

    def internal_relocs(self) -> list[Reloc]:
        out = []
        base = self.h["InternalRelocationTableOffset"]
        for i in range(self.h["InternalRelocationNum"]):
            tag, typ, symseg, _a, _b, addend = struct.unpack_from("<IBBBBI", self.data, base + 12 * i)
            seg, off = self.split_tag(tag)
            out.append(Reloc(seg, off, typ, 0, symseg, addend))
        return out

    def summary(self) -> str:
        lines = [f"{self.path}: module '{self.module_name}' size {len(self.data):#x} bss {self.h['BssSize']:#x}"]
        for s in self.segments:
            lines.append(f"  seg{s.index} {s.name:6s} offset {s.offset:#010x} size {s.size:#x}")
        for k in ("ExportNamedSymbolNum", "ExportIndexedSymbolNum", "ImportModuleNum", "ImportNamedSymbolNum",
                  "ImportIndexedSymbolNum", "ImportAnonymousSymbolNum", "InternalRelocationNum", "ExternalRelocationNum"):
            lines.append(f"  {k} = {self.h[k]}")
        for k in ("OnLoadSegmentTag", "OnExitSegmentTag", "OnUnresolvedSegmentTag", "UnkSegmentTag"):
            v = self.h[k]
            lines.append(f"  {k} = {v:#x}" + ("" if v == 0xFFFFFFFF else f" (seg {v & 0xF} + {v >> 4:#x})"))
        return "\n".join(lines)


def static_symbols(crs_path: str) -> dict[str, int]:
    """Named exports of the static module as absolute addresses (CRS segment offsets are absolute)."""
    crs = CRO.load(crs_path)
    out = {}
    for name, seg, off in crs.named_exports():
        out[name] = crs.segments[seg].offset + off
    return out


if __name__ == "__main__":
    c = CRO.load(sys.argv[1])
    print(c.summary())
    if "--exports" in sys.argv:
        for name, seg, off in c.named_exports():
            print(f"E seg{seg} +{off:#08x} {c.segments[seg].offset + off:#010x} {name}")
    if "--imports" in sys.argv:
        for imp in c.named_imports():
            print(f"I {imp.name} relocs={len(imp.relocs)}")
        for m in c.import_modules():
            print(f"M {m['name']} indexed={len(m['indexed'])} anonymous={len(m['anonymous'])}")
