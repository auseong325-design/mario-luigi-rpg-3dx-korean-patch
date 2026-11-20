"""D1X: classify the float step passed to frame-step APIs at every call site (both games).

    python scripts/fps60/d1x_steps.py <game> sites <api-addr|symbol> [--all]   # one API, every call site
    python scripts/fps60/d1x_steps.py compare [--list]                         # API table, 1dx_kr vs 3dx_v12

The step is the first float argument (s0, AAPCS-VFP). For each BL/veneer call to the API the value of s0 is
traced backwards (through vmov copies, callee-saved s16-s31 across calls, simple add-chains for the base
register of a vldr) and classified as:
  FPS        selected by isFps30() (vldrne/vldreq 2.0/1.0, movne/moveq + vcvt, ...)
  RET:<fn>   float returned by a call (e.g. btl::ObjBase::calcUpdateSpd, a getStep() helper)
  CONST:<v>  hard-wired constant (the interesting case: no 30/60 adaptation at this call)
  MEM:<base>+<off>  loaded from memory (a stored step, e.g. fld::System step field)
  CALC       result of vmul/vadd/... (operands not traced further)
  ARG        s0 not written in the function before the call (passed through from the caller)
  ?          not resolved
Read-only, heuristic: verify interesting rows by reading the disassembly (d1x_ctx.py at <addr>).
"""
from __future__ import annotations

import os
import re
import struct
import sys
from collections import Counter

import capstone

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import armdis  # noqa: E402

FPS30 = "_ZNK2ad2fw8TaskBase7isFps30Ev"

# API name -> (1dx address, 3dx address); addresses of unnamed twins found with d1x_match.py (score 1.0)
APIS = {
    "Frm::update(f)": (0x2D1104, 0x26AED4),
    "Frm::play(f)": (0x2E45B4, 0x27A324),
    "Frm::setSpd(f)": (0x2E4558, 0x27A2A4),
    "MoveVBase::update(f)": (0x2C2930, 0x2597D4),
    "MoveFBase::update(f)": (0x2D4AD0, 0x26B6FC),
    "MoveC::update(f)": (0x2D48A4, 0x26B4D0),
    "CellAnime::update(f)": (0x2D5538, 0x26BF5C),
    "ad::lyt::LytAnim::update(f)": (0x2B4184, 0x25631C),
    "ad::lyt::LytAnim::playAuto(f)": (0x2B3E78, 0x25620C),
    "ad::lyt::LytNumReel2::update(f)": (0x2B3F10, 0x159EA0),
    "ad::h3d::Anim::updateFrmOnly(f)": (0x2B3730, 0x22CEA8),
    "ad::h3d::SceneAnim::update(f)": (0x2B3694, 0x22A2D4),
    "ad::dfx::Unit::updateFrm(f)": (0x2ADE7C, 0x24CD20),
    "ad::pctx::PctxManager::update(f)": (0x2ADE18, 0x24D0C4),
    "SndSeCtrl::update(f)": (0x2AEC38, 0x249D74),
    "fld::CircleMove::update(f)": (0x273214, 0x217110),
    "ad::util::ProcessManager::update(f)": (0x2D268C, 0x26A3B8),
}
GAMES = ("1dx_kr", "3dx_v12")

_cs = capstone.Cs(capstone.CS_ARCH_ARM, capstone.CS_MODE_ARM)
_cs.detail = True


def decode(g, a):
    b = g.read(a, 4)
    if len(b) < 4:
        return None
    for ins in _cs.disasm(b, a):
        return ins
    return None


def regs_w(ins) -> set[str]:
    try:
        _, w = ins.regs_access()
    except capstone.CsError:
        return set()
    names = {ins.reg_name(r) for r in w}
    out = set()
    for n in names:
        m = re.fullmatch(r"d(\d+)", n)
        if m:  # d<n> = s<2n>:s<2n+1>
            k = int(m.group(1))
            out |= {f"s{2 * k}", f"s{2 * k + 1}"}
        out.add(n)
    return out


def callee_name(g, ins) -> str | None:
    if ins.mnemonic.split(".")[0] not in ("bl", "blx") or not ins.op_str.startswith("#"):
        return None
    t = int(ins.op_str[1:], 16)
    nm = g.a2s.get(t & ~1)
    if nm:
        nm = nm[8:] if nm.startswith("veneer->") else nm
        nm = nm.split(":", 1)[1] if ":" in nm and not nm.startswith("_Z") else nm
        return nm
    return f"sub_{t:x}"


def is_push(w: int) -> bool:
    return (w & 0xFFFF4000) == 0xE92D4000


def cond_of(ins) -> int:
    return (struct.unpack("<I", ins.bytes)[0] >> 28) & 0xF


def literal(g, ins) -> int | None:
    m = re.search(r"\[pc, #(-?0x[0-9a-f]+)\]", ins.op_str)
    if not m:
        return None
    return g.u32(ins.address + 8 + int(m.group(1), 16))


def f32(v: int) -> str:
    return f"{struct.unpack('<f', struct.pack('<I', v))[0]:g}"


def fps_before(g, a: int, n: int = 10) -> bool:
    for i in range(1, n + 1):
        ins = decode(g, a - 4 * i)
        if ins is None:
            return False
        if callee_name(g, ins) == FPS30:
            return True
        if is_push(struct.unpack("<I", ins.bytes)[0]):
            return False
    return False


def classify(game: str, site: int, depth: int = 0) -> str:
    g = armdis.game(game)
    reg = "s0"
    cond_seen = False
    a = site - 4
    for _ in range(600):
        ins = decode(g, a)
        if ins is None:
            return "?"
        w = struct.unpack("<I", ins.bytes)[0]
        nm = callee_name(g, ins)
        if nm:
            if nm == FPS30 and cond_seen:
                return "FPS"
            if int(reg[1:]) < 16:
                return f"RET:{armdis.demangle_hint(nm)}" if reg == "s0" else "?"
            # callee-saved: keep scanning past the call
        if reg in regs_w(ins):
            mn = ins.mnemonic
            c = cond_of(ins)
            val = None
            if mn.startswith("vmov") and "#" in ins.op_str:
                val = "CONST:" + ins.op_str.split("#", 1)[1].strip()
                try:
                    val = f"CONST:{float(val[6:]):g}"
                except ValueError:
                    pass
            elif mn.startswith("vldr"):
                lit = literal(g, ins)
                if lit is not None:
                    val = f"CONST:{f32(lit)}"
                else:
                    m = re.search(r"\[(\w+)(?:, #(-?0x[0-9a-f]+|\d+))?\]", ins.op_str)
                    base, off = (m.group(1), int(m.group(2) or "0", 0)) if m else ("?", 0)
                    val = f"MEM:{base}+{off:#x}"
            elif mn.startswith("vmov") and re.fullmatch(r"s\d+, s\d+", ins.op_str):
                src = ins.op_str.split(", ")[1]
                if c != 0xE:
                    cond_seen = True
                    if fps_before(g, a):
                        return "FPS"
                    a -= 4
                    continue
                reg = src
                a -= 4
                continue
            elif mn.startswith("vcvt"):
                # int -> float: look for movne/moveq 2/1 + isFps30 just before
                if fps_before(g, a, 12):
                    return "FPS"
                val = "CVT"
            elif mn.startswith("vmov"):
                val = "INT"
            elif mn.startswith(("vmul", "vadd", "vsub", "vdiv", "vnmul", "vmla", "vmls", "vfma")):
                val = "CALC"
            else:
                val = f"OP:{mn}"
            if c != 0xE:
                cond_seen = True
                if fps_before(g, a):
                    return "FPS"
                a -= 4
                continue
            if cond_seen and val.startswith("CONST") and fps_before(g, a, 6):
                return "FPS"
            return val
        if is_push(w):
            return "ARG" if not cond_seen else "?"
        a -= 4
    return "?"


def api_sites(game: str, addr: int) -> list[int]:
    return [a for a, kind in armdis.callers(game, addr) if kind != "literal"]


def bucket(c: str) -> str:
    if c.startswith("CONST:"):
        return c
    if c.startswith("RET:"):
        return "RET"
    if c.startswith("MEM:"):
        return "MEM"
    return c


def main(argv: list[str]) -> None:
    if argv and argv[0] == "compare":
        show_list = "--list" in argv
        print("| API | game | sites | FPS | RET | MEM | CALC | ARG | CONST (value:count) | other |")
        print("|---|---|---|---|---|---|---|---|---|---|")
        detail = []
        for api, addrs in APIS.items():
            for game, addr in zip(GAMES, addrs):
                sites = api_sites(game, addr)
                cls = [(s, classify(game, s)) for s in sites]
                cnt = Counter(bucket(c) for _, c in cls)
                consts = ", ".join(f"{k[6:]}:{v}" for k, v in sorted(cnt.items()) if k.startswith("CONST:"))
                other = sum(v for k, v in cnt.items() if k not in ("FPS", "RET", "MEM", "CALC", "ARG") and not k.startswith("CONST:"))
                print(f"| {api} | {game} | {len(sites)} | {cnt['FPS']} | {cnt['RET']} | {cnt['MEM']} | {cnt['CALC']} | {cnt['ARG']} | {consts} | {other} |")
                for s, c in cls:
                    detail.append((api, game, s, c))
        if show_list:
            print()
            for api, game, s, c in detail:
                print(f"{game} {s:#010x} {api:36s} {c:40s} {armdis.where(game, s)}")
        return
    game, cmd, *rest = argv
    if cmd == "sites":
        g = armdis.game(game)
        tok = rest[0]
        addr = int(tok, 0) if re.fullmatch(r"0x[0-9a-fA-F]+|\d+", tok) else armdis.resolve(g, tok)[0]
        for s in api_sites(game, addr):
            print(f"{s:#010x} {classify(game, s):40s} {armdis.where(game, s)}")
        return
    if cmd == "at":
        for tok in rest:
            print(f"{int(tok, 0):#010x} {classify(game, int(tok, 0))}")
        return
    raise SystemExit(__doc__)


if __name__ == "__main__":
    main(sys.argv[1:])
