"""Progress report for a translation round.

  python scripts/round_status.py [work/batches/_assign_round1.json]
Prints, per translator, each batch: missing / OK (warnings) / N errors, then totals,
and writes work/round_status.json with the batches that still need work.
"""

from __future__ import annotations

import io
import json
import sys
from contextlib import redirect_stdout
from pathlib import Path

import merge_ko as mk

ROOT = Path(__file__).resolve().parent.parent


def main() -> int:
    sys.stdout.reconfigure(encoding="utf-8")
    path = Path(sys.argv[1]) if len(sys.argv) > 1 else ROOT / "work" / "batches" / "_assign_round1.json"
    assign = json.loads(path.read_text(encoding="utf-8"))
    todo, ok, total_w = [], 0, 0
    for a in assign:
        parts = []
        for bid in a["batches"]:
            if not (mk.KO / f"{bid}.json").exists():
                parts.append(f"{bid}: missing")
                todo.append(bid)
                continue
            with redirect_stdout(io.StringIO()):
                res = mk.check_batch(bid, verbose=False)
            if res["errors"]:
                parts.append(f"{bid}: {len(res['errors'])} ERR")
                todo.append(bid)
            else:
                ok += 1
                total_w += len(res["warnings"])
                parts.append(f"{bid}: ok({len(res['warnings'])}w)")
        print(f"{a['agent']}: " + " | ".join(parts))
    n = sum(len(a["batches"]) for a in assign)
    print(f"\nOK {ok}/{n} batches, warnings in OK batches: {total_w}, still to do: {len(todo)}")
    (ROOT / "work" / "round_status.json").write_text(json.dumps({"todo": todo}, indent=0), encoding="utf-8")
    return 0


if __name__ == "__main__":
    sys.exit(main())
