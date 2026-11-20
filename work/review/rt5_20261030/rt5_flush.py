"""RT5: force the test emulator to flush its log (rt_rpc.flush_log = one unmapped RPC read), then print the log lines
that matter for RT5 (CRO loads/unloads, LayeredFS, code patch, FS/GPU errors) after an optional time offset.

  rt5_flush.py [--since SECONDS] [--all]
"""
from __future__ import annotations

import argparse
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT / "scripts" / "fps60"))
import rt_rpc  # noqa: E402

LOG = ROOT / "tools" / "azahar-test" / "user" / "log" / "azahar_log.txt"
KEEP = re.compile(r"CRO|LayeredFS|ApplyCodePatch|Program ID|New3ds|<Error>|<Critical>|not found|NotFound|HW\.GPU|Render")
SKIP = re.compile(r"Delay generator was not initalized|exports 0 static anonymous symbols")


def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("--since", type=float, default=0.0)
    ap.add_argument("--all", action="store_true", help="also LayeredFS boot lines")
    a = ap.parse_args()
    rpc = rt_rpc.Rpc(timeout=1.0)
    rpc.select_game()
    rt_rpc.flush_log(rpc)
    n = 0
    for line in LOG.read_text(encoding="utf-8", errors="replace").splitlines():
        m = re.match(r"\[\s*([0-9.]+)\]", line)
        t = float(m.group(1)) if m else 0.0
        if t < a.since or not KEEP.search(line) or SKIP.search(line):
            continue
        if not a.all and "LayeredFS" in line and t < 5:
            n += 1
            continue
        print(line[:240])
    print(f"(boot LayeredFS lines skipped: {n})")


if __name__ == "__main__":
    main()
