"""Find update-primitive calls whose float step argument (s0) is a hard-coded constant (MOD workstream).

    python scripts/fps60/mod_hardstep.py [game] [--module NAME] [--all]

A call to MoveC::update(f), MoveVBase::update(f), Frm::update(f), CellAnime::update(f), LytAnim::update(f), ...
normally receives the task step (isFps30 ? 2.0 : 1.0, possibly x game speed). A literal 2.0 there runs 2x fast at
fps mode 0; a literal 1.0 runs at half speed at fps mode 1 (so it would have been noticed in the shipped game,
unless intended). The tracer looks back from the call (inside the same function) for the last write of s0, and
follows one `vmov.f32 s0, sN` hop. Conditional writes (vmovne/vmoveq/vldrne...) are reported as "select".
Output: site, function label, module, verdict (CONST x / select / reg / unknown).
"""
from __future__ import annotations

import os
import re
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import armdis  # noqa: E402
import mod_fn  # noqa: E402

PRIMS = {
    0x00146000: "UIListWindowPlusLyt::update", 0x00159EA0: "LytNumReel2::update", 0x0015A63C: "LytNumReel3::update",
    0x001C0AD8: "nw::lyt::Layout::UpdateAnimFrame", 0x001C1240: "nw::lyt::Layout::AnimateAndUpdateAnimFrame",
    0x0024CB28: "SlotDigits::update", 0x0024CF80: "MessageSys::func", 0x0025631C: "LytAnim::update",
    0x002597D4: "MoveVBase::update", 0x0026AED4: "Frm::update", 0x0026B4D0: "MoveC::update",
    0x0026B65C: "UIIconCatalogue::update", 0x0026B6FC: "MoveFBase::update", 0x0026BF5C: "CellAnime::update",
    0x00323E68: "MCellAnime::updateAnimeFrm", 0x00328640: "MListWndPBase::updateAnimeFrm",
    0x00329C68: "MCellAnimeListSimple::updateAnimeFrm", 0x0032BE0C: "MLyt::updateAnimeFrm",
    0x00331E98: "MMoveMsg::updateAnimeFrm", 0x00334034: "MPageBase::updateAnimeFrm",
    0x00273BE0: "Message::func", 0x0016D260: "kj::FollowMove::update",
}

SREG = r"s(\d+)"


def lit_float(g, a: int, ops: str) -> float | None:
    m = re.search(r"\[pc, #(-?0x[0-9a-f]+)\]", ops)
    if not m:
        return None
    v = g.u32(a + 8 + int(m.group(1), 16))
    if v is None:
        return None
    return struct.unpack("<f", struct.pack("<I", v))[0]


def imm_float(ops: str) -> float | None:
    m = re.search(r"#(-?[0-9.e+]+)$", ops)
    if m:
        try:
            return float(m.group(1))
        except ValueError:
            return None
    return None


def trace(c: mod_fn.Ctx, fs: int, site: int, reg: str, depth: int = 0):
    """Walk backwards from site to fs, find last def of `reg`."""
    cs = armdis.md(False)
    a = site - 4
    while a >= fs:
        code = c.g.read(a, 4)
        ins = list(cs.disasm_lite(code, a))
        if ins:
            _, _, mnem, ops = ins[0]
            parts = [p.strip() for p in ops.split(",")]
            if parts and parts[0] == reg and mnem.startswith(("vmov", "vldr", "vcvt", "vmul", "vadd", "vsub", "vdiv", "vneg", "vabs", "vsqrt", "vmla", "vnmul")):
                cond = re.match(r"^v\w+?(eq|ne|gt|ge|lt|le|hi|ls|cs|cc|mi|pl)(\.|$)", mnem)
                if cond:
                    return ("select", f"{a:#x}: {mnem} {ops}")
                if mnem.startswith("vldr"):
                    f = lit_float(c.g, a, ops)
                    if f is not None:
                        return ("CONST", f"{f:g} @ {a:#x}")
                    return ("mem", f"{a:#x}: {mnem} {ops}")
                if mnem.startswith("vmov.f32") and len(parts) == 2:
                    f = imm_float(parts[1])
                    if f is not None and not re.fullmatch(SREG, parts[1]):
                        return ("CONST", f"{f:g} @ {a:#x}")
                    if re.fullmatch(SREG, parts[1]) and depth < 2:
                        return trace(c, fs, a, parts[1], depth + 1)
                return ("calc", f"{a:#x}: {mnem} {ops}")
            if mnem in ("bl", "blx") and depth == 0 and a != site - 4:
                # a call clobbers s0-s15: value of a low sreg after a call = call result
                n = int(reg[1:])
                if n < 16:
                    return ("callret", f"{a:#x}: {mnem} {ops}")
            if mnem == "pop" or (mnem == "bx" and ops == "lr"):
                return ("unknown", f"{a:#x}: function boundary")
        a -= 4
    return ("arg", "incoming s-reg (caller's value)")


def main(argv):
    name = argv[0] if argv and argv[0] in armdis.GAMES else "3dx_v12"
    args = argv[1:] if argv and argv[0] in armdis.GAMES else argv
    mod = args[args.index("--module") + 1] if "--module" in args else None
    show_all = "--all" in args
    c = mod_fn.Ctx(name)
    from collections import Counter
    stats = Counter()
    for t, pname in PRIMS.items():
        for a, kind in armdis.callers(name, t):
            if kind == "literal":
                continue
            m = c.g.module_of(a)
            if mod and m != mod:
                continue
            fs = c.fn_start(a)
            verdict, detail = trace(c, fs, a, "s0")
            stats[(m, verdict)] += 1
            if show_all or verdict == "CONST":
                print(f"{a:#010x} [{m}] {pname:38s} in {c.label(fs)} ({fs:#x}) => {verdict} {detail}")
    print("; summary (module, verdict, count):")
    for (m, v), n in sorted(stats.items()):
        print(f";   {m:16s} {v:8s} {n}")


if __name__ == "__main__":
    main(sys.argv[1:])
