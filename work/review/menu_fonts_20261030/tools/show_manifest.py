import json
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[4]
m = json.loads((ROOT / "work/build/menu_font_stage/manifest.json").read_text("utf-8"))
print("ok:", m["ok"])
for n, f in m["fonts"].items():
    print(n, "sha256", f["output_sha256"], "size", f["size"], "shift", f["vertical_shift_vs_1dx_cell"])
    print("  advance changes:", " ".join(f"{c}({a}->{b})" for c, (a, b) in f["advance_changes"].items()))
    if "-v" in sys.argv:
        for c in f["changed"]:
            print(f"   {c['char']!r} g{c['glyph']} cwdh {c['cwdh_old']} -> {c['cwdh_new']} (1dx {c['donor_cwdh']}) rows {c['rows']}")
