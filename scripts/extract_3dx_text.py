"""Extract every translatable 3DX message (v1.2 RomFS view) into text/jp/*.json.

One JSON file per MSBT (FMsg/BMsg BG4 entries, standalone .msbt files):
  {"source": "Msg/JP_ja/FMsg.dat:o_mushiba_06",
   "messages": [{"id": "FMsg/o_mushiba_06#0", "label": ..., "style": 12, "attr": "00000000",
                 "jp": "<lossless text with tags>"}]}
The files are the single source of truth for insertion; never hand-edit them.
Run: .venv\\Scripts\\python scripts\\extract_3dx_text.py
"""

from __future__ import annotations

import json
import re
import sys

from lib3dx import ROOT, iter_all_msbt, read_msbt

OUT = ROOT / "text" / "jp"


def source_id(key: str) -> str:
    """'Msg/JP_ja/FMsg.dat:o_town_33' -> 'FMsg/o_town_33'; 'Msg/JP_ja/Menu.msbt' -> 'Menu'."""
    path, _, entry = key.partition(":")
    stem = path.rsplit("/", 1)[-1].split(".")[0]
    return f"{stem}/{entry}" if entry else stem


def main() -> int:
    OUT.mkdir(parents=True, exist_ok=True)
    total = files = 0
    for key, data in iter_all_msbt():
        sid = source_id(key)
        doc = read_msbt(data)
        msgs = [{"id": f"{sid}#{m.index}", "label": m.label, "style": m.style, "attr": m.attr,
                 "jp": m.text} for m in doc.messages]
        path = OUT / (re.sub(r"[^\w.-]", "_", sid.replace("/", "__")) + ".json")
        path.write_text(json.dumps({"source": key, "messages": msgs}, ensure_ascii=False, indent=1),
                        encoding="utf-8")
        total += len(msgs)
        files += 1
    print(f"wrote {files} files, {total} messages -> {OUT}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
