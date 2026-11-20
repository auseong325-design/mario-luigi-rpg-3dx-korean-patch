"""IMPL3: prove the field-VM latch bytes are mapped RW, zero at start and unused (BRIEF3 IMPL3 item 2).

    python scripts/fps60/impl_rwscan.py [--lo 0x434D40] [--hi 0x435000] [--json out.json]

Read-only. Checks, for the static image (work/fps60/bin/3dx_v12.code.bin) and every relocated CRO image
(work/fps60/link/3dx_v12/<module>.bin at its analysis base):
  1. mapping: bss end (data addr + data size + bss size) and the RW page end used by Luma (rw_size_total =
     ceil((data.size + bss_size) / 0x1000) pages) and Azahar (code+data pages + page-rounded bss);
  2. literal words: every aligned 32-bit word in [lo-0x1000, hi) (pointers into the tail or base pointers close
     enough below it for an immediate offset to reach it), in every module; for literal-pool words in code, the
     loading instruction and every following [rX, #imm] access while rX is live (straight-line scan);
  3. movw/movt pairs (ARMv6K has none; counted to document it) in every text range;
  4. the highest static.crs-exported / labelled symbols in bss.
Exit code 0 when no reference reaches [lo, hi).
"""
from __future__ import annotations

import argparse
import json
import os
import re
import struct
import sys

import capstone

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(os.path.dirname(HERE))
BASE = 0x100000
TEXT_END, RO_ADDR, RO_END = 0x388BD8, 0x389000, 0x389000 + 0x65E50
DATA_ADDR, DATA_SIZE, BSS_SIZE = 0x3EF000, 0x9170, 0x3CBD0
BSS_ADDR = DATA_ADDR + DATA_SIZE
BSS_END = BSS_ADDR + BSS_SIZE


_MODS = None
RAW = {}


def load_modules():
    """[(name, base, linked image, text ranges)]; RAW[name] = the unrelocated CRO file (for relocation checks)."""
    global _MODS
    if _MODS is not None:
        return _MODS
    img = open(os.path.join(ROOT, "work/fps60/bin/3dx_v12.code.bin"), "rb").read()
    mods = [("|static|", BASE, img, [(BASE, TEXT_END)])]
    link = json.load(open(os.path.join(ROOT, "work/fps60/link/3dx_v12/link.json"), encoding="utf-8"))
    for name, m in link["modules"].items():
        data = open(os.path.join(ROOT, f"work/fps60/link/3dx_v12/{name}.bin"), "rb").read()
        texts = [(s["addr"], s["addr"] + s["size"]) for s in m["segments"] if s["type"] == "text" and s["size"]]
        mods.append((name, m["base"], data, texts))
        RAW[name] = open(os.path.join(ROOT, m["file"]), "rb").read()
    _MODS = mods
    return mods


def cro_word_is_relocated(name: str, off: int, linked: bytes) -> bool:
    """A CRO can hold an absolute static address only where the RO module writes a relocation; such a word
    differs between the raw file and the linked image (or lies past the file end, in the CRO's own bss)."""
    raw = RAW[name]
    return off + 4 > len(raw) or raw[off:off + 4] != linked[off:off + 4]


def symbols():
    out = []
    p = os.path.join(ROOT, "work/fps60/link/3dx_v12/symbols.tsv")
    for ln in open(p, encoding="utf-8"):
        a, mod, name = ln.rstrip("\n").split("\t")[:3]
        if mod == "|static|":
            out.append((int(a, 16), name))
    lay = os.path.join(ROOT, "work/fps60/ghidra/3dx_v12/layout.tsv")
    if os.path.exists(lay):
        for ln in open(lay, encoding="utf-8"):
            v = ln.rstrip("\n").split("\t")
            if v[0] == "LABEL" and len(v) > 2:
                out.append((int(v[1], 16), v[2]))
    return sorted(set(out))


MEMRE = re.compile(r"\[(r\d+|sb|sl|fp|ip|lr)(?:, #(-?0x[0-9a-f]+|-?\d+))?\]")


def access_scan(md, mod_img, mod_base, ld_addr, reg, base_val, limit=24):
    """Straight-line scan after 'ldr reg, [pc, #x]': report [reg, #off] accesses until reg is overwritten or a
    branch/return ends the block."""
    hits = []
    off = ld_addr + 4 - mod_base
    code = mod_img[off:off + 4 * limit]
    for ins in md.disasm(code, ld_addr + 4):
        ops = ins.op_str
        for m in MEMRE.finditer(ops):
            if m.group(1) == reg:
                imm = int(m.group(2), 0) if m.group(2) else 0
                hits.append((ins.address, f"{ins.mnemonic} {ops}", base_val + imm))
        # forms the immediate model cannot bound: register offset, writeback, multi-register, base passed on
        if re.search(r"\[" + reg + r", (r\d+|sb|sl|fp|ip|lr)", ops) or re.search(r"\[" + reg + r"[^\]]*\]!", ops) \
                or re.search(r"\[" + reg + r"\], ", ops) or (ins.mnemonic.startswith(("stm", "ldm", "vstm", "vldm", "vpush"))
                                                          and ops.startswith(reg)):
            hits.append((ins.address, f"{ins.mnemonic} {ops}", -1))
        first = ops.split(",")[0].strip()
        if ins.mnemonic.startswith(("b", "pop")) or "pc" in first or (first == reg and not ins.mnemonic.startswith(("str", "cmp", "tst", "vstr", "stm"))):
            break
    return hits


def main(argv):
    ap = argparse.ArgumentParser()
    ap.add_argument("--lo", type=lambda x: int(x, 0), default=0x434D40)
    ap.add_argument("--hi", type=lambda x: int(x, 0), default=0x435000)
    ap.add_argument("--json")
    a = ap.parse_args(argv)
    lo, hi = a.lo, a.hi
    res = {"range": [hex(lo), hex(hi)]}
    ok = True

    # 1. mapping
    luma_rw_pages = (DATA_SIZE + BSS_SIZE + 0xFFF) >> 12
    luma_rw_end = DATA_ADDR + (luma_rw_pages << 12)
    az_end = DATA_ADDR + ((DATA_SIZE + 0xFFF) & ~0xFFF) + ((BSS_SIZE + 0xFFF) & ~0xFFF)
    res["mapping"] = {"bss": [hex(BSS_ADDR), hex(BSS_END)], "luma_rw_pages": luma_rw_pages,
                      "luma_rw_end": hex(luma_rw_end), "azahar_rw_end": hex(az_end),
                      "in_bss_tail": BSS_END <= lo and hi <= luma_rw_end and hi <= az_end}
    print(f"bss {BSS_ADDR:#x}..{BSS_END:#x}; Luma RW region {DATA_ADDR:#x}..{luma_rw_end:#x} ({luma_rw_pages} pages); "
          f"Azahar RW region {DATA_ADDR:#x}..{az_end:#x}; latch range {lo:#x}..{hi:#x} beyond bss end and mapped: "
          f"{res['mapping']['in_bss_tail']}")
    ok &= res["mapping"]["in_bss_tail"]

    # 2. literal words
    md = capstone.Cs(capstone.CS_ARCH_ARM, capstone.CS_MODE_ARM)
    syms = symbols()
    words, accesses, into, unbounded, constants = [], [], [], [], []
    wlo = lo - 0x1000
    # crt0 bss clear 0x100024: r0 = [0x100040] = bss start, r1 = [0x100044] = bss end; strlo r2,[r0],#4 while r0<r1
    crt0 = {"lit": 0x100044, "code": "14009fe514109fe50020a0e3010050e104208034fcffff3a1eff2fe1"}
    static_img = load_modules()[0][2]
    crt0_ok = (static_img[0x24:0x40].hex() == crt0["code"] and struct.unpack_from("<II", static_img, 0x40)
               == (BSS_ADDR, BSS_END))
    for name, mbase, img, texts in load_modules():
        for i in range(0, len(img) - 3, 4):
            v = struct.unpack_from("<I", img, i)[0]
            if not wlo <= v < hi:
                continue
            addr = mbase + i
            if name != "|static|" and not cro_word_is_relocated(name, i, img):
                constants.append((name, hex(addr), hex(v)))   # same bytes in the raw CRO file: not a pointer
                continue
            words.append((name, addr, v))
            if lo <= v < hi and not (name == "|static|" and addr == crt0["lit"] and crt0_ok):
                into.append((name, hex(addr), hex(v)))
            # literal pool: find loads 'ldr rX, [pc, #d]' within 4 KB before the word in a text range
            if any(t0 <= addr < t1 for t0, t1 in texts):
                for back in range(4, 0x1000, 4):
                    la = addr - back
                    if la < mbase:
                        break
                    w = struct.unpack_from("<I", img, la - mbase)[0]
                    # ARM ldr rX, [pc, #+imm12]: cond 0101 1001 1111 rrrr imm12
                    if (w & 0x0FFF0000) == 0x059F0000 and (w & 0xFFF) == back - 8:
                        reg = ["r0", "r1", "r2", "r3", "r4", "r5", "r6", "r7", "r8", "sb", "sl", "fp", "ip",
                               "sp", "lr", "pc"][(w >> 12) & 0xF]
                        for (ia, txt, ea) in access_scan(md, img, mbase, la, reg, v):
                            if ea < 0:
                                unbounded.append((name, hex(la), hex(ia), txt, hex(v)))
                                continue
                            accesses.append((name, hex(la), hex(ia), txt, hex(ea)))
                            if lo <= ea < hi:
                                into.append((name, hex(ia), txt + f" -> {ea:#x}"))
    res["crt0_bss_clear"] = {"ok": crt0_ok, "range": [hex(BSS_ADDR), hex(BSS_END)], "exclusive_end": True}
    res["words_near"] = [(n, hex(ad), hex(v)) for n, ad, v in words]
    res["cro_constants_skipped"] = constants
    res["accesses"] = accesses
    res["unbounded_forms"] = unbounded
    res["references_into_range"] = into
    mx = max((int(e[4], 16) for e in accesses), default=0)
    print(f"crt0 0x100024 clears [{BSS_ADDR:#x}, {BSS_END:#x}) with 4-byte stores while r0 < r1 (bss end exclusive): "
          f"{crt0_ok}")
    print(f"aligned words in [{wlo:#x}, {hi:#x}) that can be pointers (static, or relocated CRO words): {len(words)}; "
          f"pointing into the latch range: {[(n, hex(ad)) for n, ad, v in words if lo <= v < hi]}")
    print(f"CRO words with such values that are NOT relocations (raw CRO bytes, e.g. strings): {constants}")
    by_obj = {}
    for n, ad, v in words:
        near = max((s for s in syms if s[0] <= v), default=(0, "?"))
        by_obj.setdefault((near[0], near[1]), set()).add(v)
    for (sa, sn), vs in sorted(by_obj.items()):
        print(f"  object {sn} @ {sa:#x}: referenced values {', '.join(hex(x) for x in sorted(vs))}")
    print(f"immediate-offset accesses through those words (straight-line scan after each literal load): "
          f"{len(accesses)}, highest effective address {mx:#x}")
    print(f"register-offset / writeback / multi-register forms through those words (bounded by hand): {len(unbounded)}")
    for e in unbounded:
        print(f"  {e[0]:14s} ldr @ {e[1]} base {e[4]} use @ {e[2]}: {e[3]}")
    ok &= not into

    # 3. movw/movt (ARMv6K has none): real 'movw/movt' with cond AL, and any movt #0x43 (high half of 0x0043xxxx)
    mw, mt43 = 0, []
    for name, mbase, img, texts in load_modules():
        for t0, t1 in texts:
            for i in range(t0 - mbase, t1 - mbase - 3, 4):
                w = struct.unpack_from("<I", img, i)[0]
                if (w & 0xFFF00000) in (0xE3000000, 0xE3400000):
                    mw += 1
                    if (w & 0xFFF00000) == 0xE3400000 and (((w >> 4) & 0xF000) | (w & 0xFFF)) == 0x43:
                        mt43.append((name, hex(mbase + i)))
    res["movw_movt_al"] = mw
    res["movt_0x43"] = mt43
    print(f"cond-AL movw/movt encodings in all text ranges: {mw} (data words in literal pools; ARMv6K cannot "
          f"execute them); movt #0x43: {mt43}")
    ok &= not mt43

    # 4. top of bss
    top = [(hex(s), n) for s, n in syms if BSS_ADDR <= s < BSS_END][-8:]
    res["bss_top_symbols"] = top
    print("highest labelled bss symbols:", ", ".join(f"{n} {s}" for s, n in top))
    res["ok"] = bool(ok)
    print("RESULT:", "no reference reaches the latch range" if ok else "FAIL: " + repr(into[:10]))
    if a.json:
        with open(a.json, "w", encoding="utf-8") as f:
            json.dump(res, f, indent=1)
    return 0 if ok else 1


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
