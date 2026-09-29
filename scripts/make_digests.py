"""Build compact digests for alignment/glossary work (inputs for subagents).

Outputs (work/align, work/gloss):
  ds_rooms_digest.txt          one line per DS FEvent room: id, count, first lines (Korean)
  3dx_rooms_digest_<k>.txt     one line per 3DX FMsg room, split in N parts (Japanese)
  jp_lists.json / ds_lists.json  name lists for glossary alignment
"""

from __future__ import annotations

import json
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
JP = ROOT / "text" / "jp"
DS = ROOT / "text" / "ref_ds_ko"
ALIGN = ROOT / "work" / "align"
GLOSS = ROOT / "work" / "gloss"


def plain_jp(t: str) -> str:
    t = re.sub(r"\[Ruby ([^;\]]*);[^\]]*\]", r"\1", t)
    t = t.replace("[Next]", " / ")
    t = re.sub(r"\[[^\]]*\]", "", t)
    return re.sub(r"\s+", " ", t).strip()


def plain_ko(t: str) -> str:
    t = t.replace("[Next]", " / ")
    t = re.sub(r"\{[^}]*\}", "", t)
    return re.sub(r"\s+", " ", t).strip()


def clip(s: str, n: int) -> str:
    return s if len(s) <= n else s[: n - 1] + "…"


def jp_msgs(name: str) -> list[dict]:
    return json.loads((JP / f"{name}.json").read_text(encoding="utf-8"))["messages"]


def main(parts: int = 4) -> int:
    ALIGN.mkdir(parents=True, exist_ok=True)
    GLOSS.mkdir(parents=True, exist_ok=True)

    rooms = json.loads((DS / "FEvent.json").read_text(encoding="utf-8"))
    lines = []
    for r in rooms:
        ms = [plain_ko(m["ko"]) for m in r["messages"]]
        ms = [m for m in ms if len(m) > 3]
        if not ms:
            continue
        pick = ms[:3] + ([ms[-1]] if len(ms) > 3 else [])
        lines.append(f"DS{r['room']} (n={len(r['messages'])}): " + " || ".join(clip(m, 55) for m in pick))
    (ALIGN / "ds_rooms_digest.txt").write_text("\n".join(lines), encoding="utf-8")

    fmsg = sorted(JP.glob("FMsg__*.json"))
    entries = []
    for f in fmsg:
        name = f.stem.split("__", 1)[1]
        ms = [plain_jp(m["jp"]) for m in json.loads(f.read_text(encoding="utf-8"))["messages"]]
        ms = [m for m in ms if len(m) > 2]
        if not ms:
            continue
        pick = ms[:3] + ([ms[-1]] if len(ms) > 3 else [])
        entries.append(f"{name} (n={len(ms)}): " + " || ".join(clip(m, 60) for m in pick))
    size = (len(entries) + parts - 1) // parts
    for k in range(parts):
        (ALIGN / f"3dx_rooms_digest_{k}.txt").write_text("\n".join(entries[k * size:(k + 1) * size]),
                                                         encoding="utf-8")

    jp_lists = {
        "Item_names": [(m["label"], plain_jp(m["jp"])) for m in jp_msgs("Item") if (m["label"] or "").startswith(("N_", "Ns_"))],
        "Item_desc_sample": [(m["label"], plain_jp(m["jp"])) for m in jp_msgs("Item") if (m["label"] or "").startswith("E_")][:40],
        "BMsg_short_labels": [(m["label"], plain_jp(m["jp"])) for m in jp_msgs("BMsg__b_sys")
                              if len(plain_jp(m["jp"])) <= 14 and "_" not in (m["label"] or "_")],
        "Menu_places_outline_specials": [(m["label"], plain_jp(m["jp"])) for m in jp_msgs("Menu")
                                         if re.match(r"(MES_EMesPlace|SpAtk|MES_MenuMes_ml|MES_MenuMes_EventItemN)", m["label"] or "")],
        "MenuKJ": [(m["label"], plain_jp(m["jp"])) for m in jp_msgs("MenuKJ")],
    }
    (GLOSS / "jp_lists.json").write_text(json.dumps(jp_lists, ensure_ascii=False, indent=0), encoding="utf-8")
    ds_lists = {}
    for f in sorted(DS.glob("*.json")):
        if f.stem in ("FEvent",) or f.stem.startswith(("BAI__", "MAI__", "SAI__")):
            continue
        j = json.loads(f.read_text(encoding="utf-8"))
        ds_lists[f.stem] = [(m["i"], plain_ko(m["ko"])) for m in j]
    (GLOSS / "ds_lists.json").write_text(json.dumps(ds_lists, ensure_ascii=False, indent=0), encoding="utf-8")
    print(f"ds rooms {len(lines)}, 3dx rooms {len(entries)} in {parts} parts, "
          f"jp lists {[ (k, len(v)) for k, v in jp_lists.items()]}, ds lists {len(ds_lists)}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
