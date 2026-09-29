"""Extract all Korean text from the DS release (CLJK) into text/ref_ds_ko/*.json.

Needs work/kr_font/kr_table.json ({"main": {"01": "버", ...}, "rep": {"000": "펀", ...}}),
built by scripts/kr_merge_table.py from the glyph transcriptions.

Containers (layouts per 8y8x/mlbis-dumper):
  FEvent/FEvent.dat           per room: language table, column 66 = Korean, entries are textboxes
  BAI|MAI|SAI/*Mes*.dat       segmented tables of language tables (fonts + column 66 text)
  */mfset_*.dat, E*/EMes*.dat single language table; column 0 (plain) or 66 (with fonts)
Textbox entries start with 2 bytes (width/8, height code) that are not text.
"""

from __future__ import annotations

import json
import re
import struct
import sys

from libnds_kr import (DATA, FEVENT_HEADER_OVERLAY3, KO_TEXT_COLUMN, ROOT, overlay, segmented_file,
                       segments32, tokenize)

TABLE = ROOT / "work" / "kr_font" / "kr_table.json"
OUT = ROOT / "text" / "ref_ds_ko"
UNKNOWN = "〓"

TEXTBOX_TABLES = ["BAI/BMes_cf.dat", "BAI/BMes_ji.dat", "BAI/BMes_yo.dat", "MAI/MMes_yo.dat", "SAI/SMes_yo.dat"]
SINGLE = {  # path: (column, is_textbox) per mlbis-dumper types; None = auto-detect
    **{f"BData/mfset_{n}.dat": (0, False) for n in
       ["AItmE", "AItmE2", "AItmN", "BadgeE", "BadgeEffectE", "BadgeN", "BonusE", "Help", "MiniGame",
        "MonN", "RankUpE", "UItmE", "UItmE2", "UItmN", "WearE", "WearN", "AItmC"]},
    "BDataMiniGame/mfset_MesDat_MiniGame.dat": (KO_TEXT_COLUMN, True),
    "EDataSave/mfset_EMesJig.dat": (KO_TEXT_COLUMN, True),
    "EDataSave/mfset_EMesOutline.dat": (KO_TEXT_COLUMN, True),
    "EDataSave/mfset_EMesPlace.dat": (KO_TEXT_COLUMN, True),
    "EDataSave/mfset_EMesSys.dat": (KO_TEXT_COLUMN, True),
    # EDataBC/EMesColosseum.dat and EDataMic/EMesMic.dat use a different container
    # layout (not decoded yet; small, reference-only).
    "MData/mfset_InitLoadMes.dat": (0, True),
    "MData/mfset_MenuMes.dat": (0, False),
    "MData/mfset_ParamExpMes.dat": (0, True),
    "MData/mfset_ShopMes.dat": (0, True),
}


class Decoder:
    def __init__(self) -> None:
        t = json.loads(TABLE.read_text(encoding="utf-8"))
        self.main = {int(k, 16): v for k, v in t["main"].items()}
        self.rep = {int(k, 16): v for k, v in t["rep"].items()}
        self.unknown = 0

    def decode(self, raw: bytes) -> str:
        out: list[str] = []
        for kind, code, args in tokenize(raw):
            if kind == "main":
                if code == 0x00:
                    continue
                ch = " " if code == 0x20 else self.main.get(code)
            elif kind == "rep":
                ch = self.rep.get(code)
            else:
                ch = self.ctrl(code, args)
            if ch is None:
                self.unknown += 1
                ch = UNKNOWN
            out.append(ch)
        text = "".join(out)
        text = re.sub(r"\s*(\[Next\]\s*)+", "[Next]", text)          # collapse runs of breaks
        text = re.sub(r"^(\s|\[Next\])+|(\s|\[Next\])+$", "", text)  # trim at both ends
        return text

    @staticmethod
    def ctrl(code: int, args: bytes) -> str:
        """Reference text only needs meaning: newline, page break, variables, choices.

        0x01 (clear box) and 0x0B (scroll to a new box) both start a new page; they
        correspond to 3DX [Next] (checked on parallel scenes, e.g. DS16E)."""
        if code == 0x00:
            return "\n"
        if code in (0x01, 0x0B):
            return "[Next]"
        if code == 0x0F:
            return f"{{var:{args.hex()}}}"
        if code == 0x70:
            return "{opt}"
        return ""  # colour / font / wait / button / alignment: layout only


def column(table: bytes, index: int) -> list[bytes]:
    cols = segmented_file(table, 0, table)
    return segments32(cols[index]) if index < len(cols) and cols[index] else []


def entries(raw_list: list[bytes], textbox: bool, dec: Decoder) -> list[dict]:
    out = []
    for i, raw in enumerate(raw_list):
        body = raw[2:] if textbox and len(raw) >= 2 else raw
        text = dec.decode(body)
        if text:
            out.append({"i": i, "ko": text})
    return out


def _hangul_score(msgs: list[dict]) -> float:
    """Hangul count, but only for text that looks like prose (spaces/newlines between words)."""
    text = "".join(m["ko"] for m in msgs)
    if len(text) < 4:
        return 0.0
    hangul = sum(1 for c in text if "\uac00" <= c <= "\ud7a3")
    spacing = (text.count(" ") + text.count("\n")) / len(text)
    if spacing < 0.08 or text.count(UNKNOWN) > 0.05 * len(text):
        return 0.0
    return float(hangul)


def best_layout(table: bytes, dec: Decoder) -> list[dict]:
    """Pick the (column, textbox) combination that decodes to the most Hangul."""
    cols = segmented_file(table, 0, table)
    best: tuple[float, list[dict]] = (0.0, [])
    for ci, col in enumerate(cols):
        if not col or len(col) < 8 or struct.unpack_from("<I", col, 0)[0] > len(col):
            continue
        try:
            raws = segments32(col)
        except struct.error:
            continue
        for textbox in (True, False):
            saved = dec.unknown
            msgs = entries(raws, textbox, dec)
            dec.unknown = saved
            score = _hangul_score(msgs)
            if score > best[0]:
                best = (score, msgs)
    if best[1]:  # count unknown glyphs of the chosen layout only
        dec.unknown += sum(m["ko"].count(UNKNOWN) for m in best[1])
    return best[1]


def main() -> int:
    OUT.mkdir(parents=True, exist_ok=True)
    dec = Decoder()
    written = 0

    fe = (DATA / "FEvent" / "FEvent.dat").read_bytes()
    fseg = segmented_file(overlay(3), FEVENT_HEADER_OVERLAY3, fe)
    rooms = []
    for r in range(len(fseg) // 3):
        lt = fseg[r * 3 + 2]
        if lt:
            msgs = entries(column(lt, KO_TEXT_COLUMN), True, dec)
            if msgs:
                rooms.append({"room": f"{r:03X}", "messages": msgs})
    (OUT / "FEvent.json").write_text(json.dumps(rooms, ensure_ascii=False, indent=1), encoding="utf-8")
    written += sum(len(r["messages"]) for r in rooms)

    for rel in TEXTBOX_TABLES:
        d = (DATA / rel).read_bytes()
        tables = []
        for ti, tab in enumerate(segmented_file(d, 0, d)):
            if any(tab):
                msgs = entries(column(tab, KO_TEXT_COLUMN), True, dec)
                if msgs:
                    tables.append({"table": ti, "messages": msgs})
        name = rel.replace("/", "__").replace(".dat", "")
        (OUT / f"{name}.json").write_text(json.dumps(tables, ensure_ascii=False, indent=1), encoding="utf-8")
        written += sum(len(t["messages"]) for t in tables)

    for rel, layout in SINGLE.items():
        p = DATA / rel
        if not p.exists():
            continue
        d = p.read_bytes()
        msgs = best_layout(d, dec) if layout is None else entries(column(d, layout[0]), layout[1], dec)
        name = rel.replace("/", "__").replace(".dat", "")
        (OUT / f"{name}.json").write_text(json.dumps(msgs, ensure_ascii=False, indent=1), encoding="utf-8")
        written += len(msgs)

    print(f"{written} Korean messages -> {OUT}; undecodable glyph codes: {dec.unknown}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
