"""Lead TEXT PASS (2026-09-30): restore ※ in 4 lines and switch 4 coined names to the 1DX KR official ones.

Edits the raw JSON text in place, so each batch file keeps its own layout, then re-parses the result and checks
that exactly the intended values changed. Every edit states the exact old text; nothing is written if one is
missing. Without --apply it only writes the diff to $KIROCREW_SCRATCH/textpass_diff.txt.
"""
import difflib
import json
import os
import pathlib
import sys
from json.decoder import scanstring

ROOT = pathlib.Path(r"C:\mario-luigi-rpg-3dx-korean-patch")
KO = ROOT / "text" / "ko"
GLOSS = ROOT / "text" / "glossary.tsv"
APPLY = "--apply" in sys.argv

N_MARK = "review(리드): ※ 복원 — 1DX 기반 폰트에 ※가 들어가서 원문대로 되돌림."
N_UCHI = ("review(리드): うちけし = 「스킬 지우기」(1DX 한국판 공식, BMsg k_sys#48·#316·#641, 버튼 btn_KGLA_TX_n01). "
          "동사형은 '(스킬을) 지우다'.")
N_KORO = "review(리드): ころび = 「꽈당」(1DX 한국판 공식, BMsg b_sys#341, Item#430, 스프라이트 bui_sys_badstatname)."
N_THUN = "review(리드): サンダー = 「선더」(1DX 한국판 공식, BMsg k_sys#95·#349, 버튼 btn_KGLA_TX_n05)."
N_DOSS = "review(리드): ドッスンおとし = 「쿵쿵 떨어트리기」(1DX 한국판 공식, BMsg k_sys#123·#847, 버튼 btn_KGLA_TX_n08)."

# (id, old substring, new substring, note)
EDITS = [
    ("FMsg/k_o_koopa_08#9", "{3:color}*개인차가 있습니다.", "{3:color}※개인차가 있습니다.", N_MARK),
    ("FMsg/k_o_koopa_08#11", "{3:color}*전문가의 적절한", "{3:color}※전문가의 적절한", N_MARK),
    ("BMsg/b_sys#670", "\n이지 모드는 스타 메뉴의\n", "\n※이지 모드는 스타 메뉴의\n", N_MARK),
    ("BMsg/b_sys#1546", "\n단, 어택은 피할 수 없어요.", "\n※어택은 피할 수 없어요.", N_MARK),

    ("BMsg/b_sys#12", "{2:color}「무효화」가 통하지 않는{3:color} 데다 엄청난 파워로\n리더를 향해 달려와요.",
     "{2:color}「스킬 지우기」가 통하지 않는{3:color} 데다\n엄청난 파워로 리더를 향해 달려와요.", N_UCHI),
    ("BMsg/b_sys#1847", "{2:color}「무효화」가 통하지 않는{3:color} 데다 엄청난 파워로\n리더를 향해 달려와요.",
     "{2:color}「스킬 지우기」가 통하지 않는{3:color} 데다\n엄청난 파워로 리더를 향해 달려와요.", N_UCHI),
    ("BMsg/b_sys#208", "{11:color}「무효화」{12:color}를 입력!", "{11:color}「스킬 지우기」{12:color}를 입력!", N_UCHI),
    ("BMsg/b_sys#225", "녀석의 어택을 무효화해 버렸다!", "녀석의 어택을 지워 버렸다!", N_UCHI),
    ("BMsg/b_sys#238", "단, 무효화를 쓸 수 있는 건", "단, 스킬 지우기를 쓸 수 있는 건", N_UCHI),
    ("BMsg/b_sys#239", "「{6:color}무효화{7:color}」는", "「{6:color}스킬 지우기{7:color}」는", N_UCHI),
    ("BMsg/b_sys#273", "{2:font}무효화+타격!{3:font}", "{2:font}스킬 지우기+타격!{3:font}", N_UCHI),
    ("BMsg/b_sys#293", "{2:font}무효화+타격!{3:font}", "{2:font}스킬 지우기+타격!{3:font}", N_UCHI),
    ("BMsg/b_sys#495", "{3:var}마리 무효화했다!", "{3:var}마리의 스킬을 지웠다!", N_UCHI),
    ("BMsg/b_sys#510", "{3:var}명 무효화당했다!", "{3:var}명의 스킬이 지워졌다!", N_UCHI),
    ("BMsg/b_sys#528", "{2:font}무효화하지 못했다!", "{2:font}스킬을 지우지 못했다!", N_UCHI),
    ("BMsg/b_sys#1008", "「{9:color}무효화{10:color}」를 쓰거나", "「{9:color}스킬 지우기{10:color}」를 쓰거나", N_UCHI),
    ("BMsg/b_sys#1055", "효과가 있는 건 무효화와 마찬가지로", "효과가 있는 건 스킬 지우기와 마찬가지로", N_UCHI),
    ("BMsg/b_sys#1134", "무효화", "스킬 지우기", N_UCHI),
    ("BMsg/b_sys#1450", "되도록 무효화하고 싶다.", "되도록 지우고 싶다.", N_UCHI),

    ("BMsg/b_sys#179", "감기, 넘어짐{2:color}은", "감기, 꽈당{2:color}은", N_KORO),

    ("BMsg/b_sys#195", "썬더", "선더", N_THUN),
    ("BMsg/b_sys#969", "「{9:color}썬더{10:color}」나", "「{9:color}선더{10:color}」나", N_THUN),
    ("BMsg/b_sys#990", "「{2:color}썬더{3:color}」는", "「{2:color}선더{3:color}」는", N_THUN),

    ("BMsg/b_sys#600", "쿵쿵 떨구기", "쿵쿵 떨어트리기", N_DOSS),
]

GLOSS_ROWS = {
    "うちけし": ["うちけし", "스킬 지우기", "ability", "official", "1DX-KR:BMsg.dat:k_sys#48",
                 "RPG1 DX 한국판 리더 액션명(k_sys#48·#316·#641, 버튼 btn_KGLA_TX_n01). 동사 うちけす는 '(스킬을) 지우다' "
                 "[gl_kj; 리드 2026-09-30, 예전 신조어 '무효화']"],
    "ころび": ["ころび", "꽈당", "term", "official", "1DX-KR:BMsg.dat:b_sys#341",
              "RPG1 DX 한국판 상태 이상명(b_sys#341, Item#430 '독/어질어질/꽈당', 스프라이트 bui_sys_badstatname) "
              "[gl_attacks; 리드 2026-09-30, 예전 신조어 '넘어짐']"],
    "サンダー": ["サンダー", "선더", "ability", "official", "1DX-KR:BMsg.dat:k_sys#95",
                "RPG1 DX 한국판 리더 액션명(k_sys#95·#349, 버튼 btn_KGLA_TX_n05; '선더 브러스'도 같은 표기) "
                "[gl_kj; 리드 2026-09-30, 예전 '썬더']"],
    "ドッスンおとし": ["ドッスンおとし", "쿵쿵 떨어트리기", "ability", "official", "1DX-KR:BMsg.dat:k_sys#123",
                   "RPG1 DX 한국판 리더 액션명(k_sys#123·#847, 설명 #693 '쿵쿵을 떨어트려', 버튼 btn_KGLA_TX_n08) "
                   "[gl_kj; 리드 2026-09-30, 예전 신조어 '쿵쿵 떨구기']"],
}


def enc(s: str) -> str:
    return json.dumps(s, ensure_ascii=False)[1:-1]


def region(text: str, key: str) -> tuple[int, int]:
    """Span of the top-level object `key` ("translations" / "notes"): from its '{' to the matching '}'."""
    i = text.find(f'"{key}":')
    if i < 0:
        return -1, -1
    j = text.index("{", i)
    depth, k, in_str = 0, j, False
    while k < len(text):
        c = text[k]
        if in_str:
            if c == "\\":
                k += 2
                continue
            if c == '"':
                in_str = False
        elif c == '"':
            in_str = True
        elif c == "{":
            depth += 1
        elif c == "}":
            depth -= 1
            if depth == 0:
                return j, k
        k += 1
    raise ValueError(f"unbalanced object {key}")


def value_span(text: str, key: str, lo: int, hi: int) -> tuple[int, int] | None:
    """(start of the opening quote, index after the closing quote) of the string value of `key` in [lo, hi)."""
    pat = json.dumps(key, ensure_ascii=False) + ":"
    i = text.find(pat, lo, hi)
    if i < 0:
        return None
    q = text.index('"', i + len(pat))
    _, end = scanstring(text, q + 1)
    return q, end


def edit_file(text: str, edits: list[tuple]) -> str:
    for mid, old, new, note in edits:
        t0, t1 = region(text, "translations")
        span = value_span(text, mid, t0, t1)
        raw = text[span[0]:span[1]]
        if raw.count(enc(old)) != 1:
            raise SystemExit(f"{mid}: old text found {raw.count(enc(old))} times in the raw value: {old!r}")
        text = text[:span[0]] + raw.replace(enc(old), enc(new)) + text[span[1]:]

        n0, n1 = region(text, "notes")
        if n0 < 0:
            raise SystemExit(f"{mid}: file has no notes object")
        nspan = value_span(text, mid, n0, n1)
        if nspan:  # append to the existing note, just before its closing quote
            text = text[:nspan[1] - 1] + enc(" " + note) + text[nspan[1] - 1:]
        else:      # new first entry of notes, indented like the entry that follows (or the object's own indent + 1)
            after = text[n0 + 1:n1]
            if after.strip():
                line = after.split("\n")[1] if after.startswith("\n") else after
                indent = line[:len(line) - len(line.lstrip())]
                text = text[:n0 + 1] + f"\n{indent}\"{enc(mid)}\": \"{enc(note)}\"," + text[n0 + 1:]
            else:
                text = text[:n0 + 1] + f"\"{enc(mid)}\": \"{enc(note)}\"" + text[n0 + 1:]
    return text


def main():
    by_id = {e[0]: e for e in EDITS}
    changed = {}
    for p in sorted(KO.glob("*.json")):
        if p.name.startswith("_"):
            continue
        text = p.read_text(encoding="utf-8")
        d = json.loads(text)
        tr = d.get("translations") or {}
        mine = [by_id.pop(mid) for mid in list(by_id) if mid in tr]
        if not mine:
            continue
        new_text = edit_file(text, mine)
        # verify: re-parse, and only the intended values changed
        d2 = json.loads(new_text)
        for mid, old, new, note in mine:
            want = tr[mid].replace(old, new)
            if d2["translations"][mid] != want:
                raise SystemExit(f"{p.name} {mid}: result differs from the intended value")
            if note not in d2["notes"][mid]:
                raise SystemExit(f"{p.name} {mid}: note missing")
        others = {k: v for k, v in d2["translations"].items() if k not in {m[0] for m in mine}}
        if others != {k: v for k, v in tr.items() if k not in {m[0] for m in mine}}:
            raise SystemExit(f"{p.name}: unintended translation change")
        changed[p] = (text, new_text)
    if by_id:
        raise SystemExit(f"ids not found in any batch file: {sorted(by_id)}")

    g_text = GLOSS.read_text(encoding="utf-8")
    lines = g_text.split("\n")
    seen = set()
    for i, line in enumerate(lines):
        jp = line.split("\t", 1)[0]
        if jp in GLOSS_ROWS:
            if jp in seen:
                raise SystemExit(f"glossary has two rows for {jp}")
            seen.add(jp)
            lines[i] = "\t".join(GLOSS_ROWS[jp])
    if seen != set(GLOSS_ROWS):
        raise SystemExit(f"glossary rows missing: {set(GLOSS_ROWS) - seen}")
    changed[GLOSS] = (g_text, "\n".join(lines))

    diff_lines = []
    for p, (old, new) in changed.items():
        diff_lines += list(difflib.unified_diff(old.splitlines(), new.splitlines(), str(p), str(p), n=0, lineterm=""))
        if APPLY:
            p.write_text(new, encoding="utf-8")
    dp = pathlib.Path(os.environ.get("KIROCREW_SCRATCH", ".")) / "textpass_diff.txt"
    dp.write_text("\n".join(diff_lines) + "\n", encoding="utf-8")
    print(f"diff: {len(diff_lines)} lines -> {dp}")
    print(f"{'APPLIED' if APPLY else 'DRY RUN'}: {len(EDITS)} message edits in {len(changed) - 1} batch files + glossary")


if __name__ == "__main__":
    main()
