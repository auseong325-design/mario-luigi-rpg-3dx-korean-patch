"""FLD: classify constant-step update calls found by mod_hardstep.py (read-only).

    python scripts/fps60/fld_hsck.py <hardstep_output.txt>

For every `=> CONST` line in static/Field, prints the 10 instructions before the call and a verdict:
  FINALIZE  a stop() call precedes the update (stop + update(1) snaps the mover to its end = one-shot)
  PERFRAME  otherwise (needs manual review)
"""
from __future__ import annotations

import os
import re
import sys

import capstone

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import armdis  # noqa: E402
import fld_dc  # noqa: E402

STOPS = {0x24F578: "MoveVBase::stop(int)", 0x259DD8: "MoveVBase::stop()"}


def main(argv):
    g = armdis.Game("3dx_v12")
    dc = fld_dc.DC()
    for d in dc.rows:
        if re.search(r"Move\w*::stop|Frm::stop|CellAnime::stop", d["name"]):
            STOPS[d["a"]] = d["name"]
    md = capstone.Cs(capstone.CS_ARCH_ARM, capstone.CS_MODE_ARM)
    for ln in open(argv[0], encoding="utf-8", errors="replace"):
        if "=> CONST" not in ln:
            continue
        m = re.match(r"(0x[0-9a-f]+) \[([^\]]+)\] (\S+)\s+in (.*?) \((0x[0-9a-f]+)\) => CONST (\S+)", ln.strip())
        if not m:
            continue
        site = int(m.group(1), 16)
        mod = m.group(2)
        if mod not in ("|static|", "Field"):
            continue
        lo = site - 40
        ins = list(md.disasm_lite(g.read(lo, 44), lo))
        verdict = "PERFRAME"
        stop = ""
        for a, size, mn, ops in ins:
            if mn.startswith("bl"):
                mt = re.match(r"#(0x[0-9a-f]+)", ops)
                if mt and int(mt.group(1), 16) in STOPS and a < site:
                    verdict = "FINALIZE"
                    stop = STOPS[int(mt.group(1), 16)]
        r = dc.row(site)
        print(f"{site:#010x} {m.group(3):22s} c={m.group(6):5s} {verdict:9s} {stop:24s} in {r['name'] if r else m.group(4)}")


if __name__ == "__main__":
    main(sys.argv[1:])
