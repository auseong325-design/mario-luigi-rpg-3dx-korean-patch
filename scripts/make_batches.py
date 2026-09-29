"""Build translation batches (work/batches/*.json) from text/jp.

Translator view of a message ("src"):
  * the leading box header tag [0009:0000:..] is hidden (restored automatically)
  * [Ruby 漢字;かな] -> 漢字 (Korean needs no furigana)
  * [Next] stays literal (page break)
  * every other tag becomes a numbered placeholder {n:kind}; its original is kept in
    "tags" so scripts/merge_ko.py can restore it. Translators must keep every
    placeholder exactly once (order may change).
Identical translator views are translated once: later copies are listed in
"dups" and receive the same translation on merge.

Each batch carries: DS Korean reference lines of the mapped DS rooms
(text/align/room_map.json), and the glossary rows whose Japanese term occurs in it.
Run: .venv\\Scripts\\python scripts\\make_batches.py
"""

from __future__ import annotations

import csv
import json
import re
import sys
from collections import OrderedDict, defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
JP = ROOT / "text" / "jp"
DS = ROOT / "text" / "ref_ds_ko"
GLOSSARY = ROOT / "text" / "glossary.tsv"
ROOM_MAP = ROOT / "text" / "align" / "room_map.json"
OUT = ROOT / "work" / "batches"
MAX_MSGS = 110          # messages per batch (after dedupe)
MAX_REF_LINES = 400     # DS reference lines per batch

TAG = re.compile(r"\[[^\[\]]*\]")
HEADER = re.compile(r"^\[0009:0000:[0-9A-F ]*\]")


def kind(tag: str) -> str:
    """Placeholder kind shown to translators (semantics verified from JP contexts)."""
    body = tag[1:-1]
    if body.startswith("Color"):
        return "color"
    if body.startswith("U+"):
        return "icon"
    gt = body[:9]
    return {"0000:0001": "font", "0000:0002": "size", "0002:0000": "pause", "0002:0001": "wait",
            "0002:0002": "speed", "0006:0000": "tab", "0006:0001": "indent"}.get(gt) or \
        {"0001": "align", "0003": "var", "0004": "choice", "0005": "mode"}.get(body[:4], "tag")


def to_view(text: str) -> tuple[str, str, dict[str, str]]:
    """-> (hidden header, translator view, placeholder map)."""
    m = HEADER.match(text)
    header = m.group(0) if m else ""
    body = text[len(header):]
    body = re.sub(r"\[Ruby ([^;\]]*);[^\]]*\]", r"\1", body)
    tags: dict[str, str] = {}

    def repl(mt: re.Match) -> str:
        t = mt.group(0)
        if t == "[Next]":
            return t
        n = str(len(tags) + 1)
        tags[n] = t
        return f"{{{n}:{kind(t)}}}"

    return header, TAG.sub(repl, body), tags


def load_glossary() -> list[dict]:
    if not GLOSSARY.exists():
        return []
    with GLOSSARY.open(encoding="utf-8", newline="") as f:
        return [r for r in csv.DictReader(f, delimiter="\t") if r.get("jp")]


def ds_ref_lines(rooms: list[str]) -> list[str]:
    if not rooms:
        return []
    fe = {r["room"]: r["messages"] for r in json.loads((DS / "FEvent.json").read_text(encoding="utf-8"))}
    out = []
    for rid in rooms:
        for m in fe.get(rid, []):
            ko = re.sub(r"\{[^}]*\}", "", m["ko"]).strip()
            if ko:
                out.append(f"DS{rid}#{m['i']}: {ko}")
    return out[:MAX_REF_LINES]


# DS reference files for the non-room sources (text/ref_ds_ko/<stem>.json)
SOURCE_DS = {
    "BMsg": ["BAI__BMes_yo", "BAI__BMes_cf", "BAI__BMes_ji", "MAI__MMes_yo", "BData__mfset_Help",
             "BData__mfset_BadgeEffectE", "BData__mfset_RankUpE", "BData__mfset_AItmN", "BData__mfset_AItmE2"],
    "Item": ["BData__mfset_UItmN", "BData__mfset_UItmE2", "BData__mfset_WearN", "BData__mfset_WearE",
             "BData__mfset_BadgeN", "BData__mfset_BadgeE", "BData__mfset_AItmN", "BData__mfset_AItmE2"],
    "Menu": ["MData__mfset_MenuMes", "MData__mfset_ShopMes", "MData__mfset_ParamExpMes",
             "EDataSave__mfset_EMesOutline", "EDataSave__mfset_EMesPlace", "EDataSave__mfset_EMesSys",
             "EDataSave__mfset_EMesJig", "BData__mfset_MiniGame", "BDataMiniGame__mfset_MesDat_MiniGame",
             "SAI__SMes_yo", "BData__mfset_RankUpE", "BData__mfset_Help"],
    "HugeBattle": ["BAI__BMes_ji", "SAI__SMes_yo"],
    "InitLoad": ["MData__mfset_InitLoadMes"],
    "MenuKJ": [],
}
MAX_SOURCE_REF_LINES = 700

# 3DX rooms whose DS counterpart lives outside FEvent (found during room alignment)
ROOM_EXTRA_DS = {
    "i_areanone_puzzle_01_L": ["EDataSave__mfset_EMesJig"],
    "i_areanone_puzzle_01_U": ["EDataSave__mfset_EMesJig"],
    "i_areanone_puzzle_02_L": ["EDataSave__mfset_EMesJig"],
    "i_areanone_puzzle_02_U": ["EDataSave__mfset_EMesJig"],
}


def ds_file_lines(stems: list[str]) -> list[str]:
    out, seen = [], set()
    for stem in stems:
        p = DS / f"{stem}.json"
        if not p.exists():
            continue
        j = json.loads(p.read_text(encoding="utf-8"))
        items = ([(f"{t['table']}.{m['i']}", m["ko"]) for t in j for m in t["messages"]]
                 if j and isinstance(j[0], dict) and "messages" in j[0] else [(m["i"], m["ko"]) for m in j])
        for i, ko in items:
            ko = re.sub(r"\{[^}]*\}", "", ko).strip()
            if ko and ko not in seen and ko != "DUMMY":
                seen.add(ko)
                out.append(f"DS:{stem}#{i}: {ko}")
    return out[:MAX_SOURCE_REF_LINES]


def groups() -> list[tuple[str, str, list[dict]]]:
    """(batch_base, source_name, messages) in a scene-preserving order."""
    out = []
    for f in sorted(JP.glob("*.json")):
        msgs = json.loads(f.read_text(encoding="utf-8"))["messages"]
        out.append((f.stem, f.stem.split("__", 1)[-1], msgs))
    return out


def main() -> int:
    only = set(sys.argv[sys.argv.index("--only") + 1:]) if "--only" in sys.argv else None
    from merge_ko import _word_in  # same word-boundary rule as the checker (ミー must not match レミー)
    OUT.mkdir(parents=True, exist_ok=True)
    if only is None:
        for old in list(OUT.glob("*.json")) + list(OUT.glob("_refs_*.txt")):
            old.unlink()
    glossary = load_glossary()
    room_map = json.loads(ROOM_MAP.read_text(encoding="utf-8")) if ROOM_MAP.exists() else {}
    seen: dict[str, str] = {}
    dups: dict[str, list[str]] = defaultdict(list)
    batches = []
    for base, name, msgs in groups():
        items = []
        for m in msgs:
            header, view, tags = to_view(m["jp"])
            plain = re.sub(r"\{[^}]*\}|\[Next\]|\s", "", view)
            if not plain:
                continue  # tag-only message: nothing to translate
            if view in seen:
                dups[seen[view]].append(m["id"])
                continue
            seen[view] = m["id"]
            items.append({"id": m["id"], "label": m["label"], "style": m["style"], "src": view,
                          "tags": tags, "header": header})
        for k in range(0, len(items), MAX_MSGS):
            chunk = items[k:k + MAX_MSGS]
            bid = base if len(items) <= MAX_MSGS else f"{base}__p{k // MAX_MSGS + 1}"
            batches.append((bid, name, chunk))

    # small FMsg rooms of the same area are merged so batches have a useful size
    merged: list[tuple[str, list[str], list[dict]]] = []
    for bid, name, chunk in batches:
        area = re.sub(r"_\d+.*$", "", name) if bid.startswith("FMsg__") else None
        if (merged and area and merged[-1][0].startswith("FMsg__") and merged[-1][0].endswith("~")
                and re.sub(r"_\d+.*$", "", merged[-1][1][0]) == area
                and len(merged[-1][2]) + len(chunk) <= MAX_MSGS):
            merged[-1][1].append(name)
            merged[-1][2].extend(chunk)
        else:
            merged.append((bid + ("~" if area and "__p" not in bid else ""), [name], list(chunk)))

    index = []
    for bid, names, chunk in merged:
        bid = bid.rstrip("~")
        if len(names) > 1:
            bid = f"{bid}__and{len(names) - 1}"
        ds_rooms = sorted({r for n in names for r in room_map.get(n, [])})
        text_blob = "\n".join(it["src"] for it in chunk)
        terms = [g for g in glossary if _word_in(g["jp"], text_blob)]
        for it in chunk:
            it["dups"] = dups.get(it["id"], [])
        src_key = bid.split("__", 1)[0]
        if src_key == "FMsg":
            refs = ds_ref_lines(ds_rooms)
        else:
            shared = OUT / f"_refs_{src_key}.txt"
            lines = ds_file_lines(SOURCE_DS.get(src_key, []))
            if lines:
                if only is None:
                    shared.write_text("\n".join(lines), encoding="utf-8")
                refs = [f"@file work/batches/{shared.name} ({len(lines)} DS lines shared by all {src_key} "
                        f"batches - read it once)"]
            else:
                refs = []
        extra = sorted({s for n in names for s in ROOM_EXTRA_DS.get(n, [])})
        if extra:
            refs += ds_file_lines(extra)
        batch = OrderedDict(batch=bid, rooms=names, ds_rooms=ds_rooms,
                            ds_reference=refs, glossary=terms, messages=chunk)
        if only is not None and bid not in only:
            continue
        (OUT / f"{bid}.json").write_text(json.dumps(batch, ensure_ascii=False, indent=1), encoding="utf-8")
        index.append({"batch": bid, "messages": len(chunk), "dups": sum(len(i["dups"]) for i in chunk),
                      "jp_chars": sum(len(re.sub(r"\{[^}]*\}", "", i["src"])) for i in chunk)})
    if only is None:
        (OUT / "_index.json").write_text(json.dumps(index, ensure_ascii=False, indent=0), encoding="utf-8")
    print(f"{len(index)} batches, {sum(b['messages'] for b in index)} unique messages "
          f"(+{sum(b['dups'] for b in index)} duplicates), {sum(b['jp_chars'] for b in index)} JP chars")
    return 0


if __name__ == "__main__":
    sys.exit(main())
