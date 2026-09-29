"""Print rooms in plain text for side-by-side comparison.

  python scripts/show_room.py --jp o_town_33          3DX room (Japanese, tags stripped)
  python scripts/show_room.py --ds 0F2 [--ds 0F3]     DS room(s) (Korean)
  python scripts/show_room.py --cand o_town_33        structural DS candidates of a 3DX room
  python scripts/show_room.py --find-ds 오키노         DS rooms containing a Korean string
  python scripts/show_room.py --find-jp コッキー       3DX rooms containing a Japanese string
"""

from __future__ import annotations

import argparse
import json
import sys
from pathlib import Path

from parallel_corpus import plain_jp, plain_ko

ROOT = Path(__file__).resolve().parent.parent
JP = ROOT / "text" / "jp"
DS = ROOT / "text" / "ref_ds_ko" / "FEvent.json"
CAND = ROOT / "work" / "align" / "candidates.json"


def main() -> int:
    sys.stdout.reconfigure(encoding="utf-8")
    ap = argparse.ArgumentParser()
    ap.add_argument("--jp", action="append", default=[])
    ap.add_argument("--ds", action="append", default=[])
    ap.add_argument("--cand", action="append", default=[])
    ap.add_argument("--find-ds")
    ap.add_argument("--find-jp")
    ap.add_argument("--max", type=int, default=400, help="max messages per room")
    a = ap.parse_args()
    ds = {r["room"]: r["messages"] for r in json.loads(DS.read_text(encoding="utf-8"))}
    for name in a.jp:
        msgs = json.loads((JP / f"FMsg__{name}.json").read_text(encoding="utf-8"))["messages"]
        print(f"===== 3DX {name} ({len(msgs)} messages)")
        for m in msgs[: a.max]:
            print(f"  {m['id'].split('#')[1]:>4}: {plain_jp(m['jp'])}")
    for rid in a.ds:
        rid = rid.upper().zfill(3)
        msgs = ds.get(rid, [])
        print(f"===== DS {rid} ({len(msgs)} messages)")
        for m in msgs[: a.max]:
            print(f"  {m['i']:>4}: {plain_ko(m['ko'])}")
    if a.cand:
        cand = json.loads(CAND.read_text(encoding="utf-8"))
        for name in a.cand:
            print(name, cand.get(name))
    if a.find_ds:
        for rid, msgs in ds.items():
            hits = [m for m in msgs if a.find_ds in m["ko"]]
            if hits:
                print(f"DS{rid} ({len(hits)}): {plain_ko(hits[0]['ko'])[:100]}")
    if a.find_jp:
        for f in sorted(JP.glob("*.json")):
            for m in json.loads(f.read_text(encoding="utf-8"))["messages"]:
                if a.find_jp in plain_jp(m["jp"]):
                    print(f"{m['id']}: {plain_jp(m['jp'])[:100]}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
