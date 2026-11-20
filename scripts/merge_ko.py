"""Validate translated batches (text/ko/*.json) and merge them into work/ko_final.json.

  python scripts/merge_ko.py --check <batch> [...]  validate given batches (errors + warnings)
  python scripts/merge_ko.py --check-all            validate every translated batch
  python scripts/merge_ko.py --status               progress overview
  python scripts/merge_ko.py --merge                validate all, write work/ko_final.json,
                                                    work/new_terms.tsv, work/merge_report.json
  python scripts/merge_ko.py --grep <text>          search translations
Exit code 1 when a checked batch has errors. Errors block merging; warnings do not.

Shared translations (a batch message's "dups") are restored with each copy's own hidden tags.
A copy that needs different wording (another scene, another listener) gets it from
text/ko/_dup_overrides.json {"translations": {id: text}, "notes": {id: why}}; each entry is
validated against that id's own Japanese message before --merge applies it.
"""

from __future__ import annotations

import argparse
import csv
import json
import re
import sys
from collections import Counter, defaultdict
from functools import lru_cache
from pathlib import Path

from lib3dx import ROOT, bffnt_advances, encode_text

BATCHES = ROOT / "work" / "batches"
KO = ROOT / "text" / "ko"
JP = ROOT / "text" / "jp"
GLOSSARY = ROOT / "text" / "glossary.tsv"
FINAL = ROOT / "work" / "ko_final.json"
REPORT = ROOT / "work" / "merge_report.json"
NEW_TERMS = ROOT / "work" / "new_terms.tsv"
DUP_OVERRIDES = KO / "_dup_overrides.json"

PH = re.compile(r"\{(\d+):([a-z]+)\}")
JP_RESIDUE = re.compile(r"[\u3040-\u30fa\u30fc-\u30ff\u31f0-\u31ff\u3400-\u4dbf\u4e00-\u9fff\uff66-\uff9f、。]")
FULLWIDTH = re.compile(r"[\uff01-\uff5e\u3000]")
# ASCII the 3DX font lacks: widths of the glyphs scripts/build_font.py adds (from the Korean 1DX
# font; '~' and '%' keep their 1DX advance 16 because their ink does not fit narrower)
EXTRA_ASCII_WIDTH = {"!": 6, ",": 5, "-": 8, ":": 5, ";": 5, "%": 16, "~": 16, '"': 8, "#": 12, "*": 10,
                     "<": 10, ">": 10, "@": 14, "^": 10, "_": 10, "|": 5, "\\": 8, "`": 6, "$": 10}
EXTRA_SYMBOLS = {"·": 8, "♥": 16, "※": 16}


@lru_cache(maxsize=1)
def charset() -> tuple[dict[str, int], frozenset[str]]:
    adv = {c: w for c, w in bffnt_advances().items() if not re.match(r"[\u3040-\u30ff\u4e00-\u9fff]", c)}
    adv.update(EXTRA_ASCII_WIDTH)
    # 2026-10-30 (wave 5): the installed font.bffnt draws Latin letters, digits and punctuation with 1DX glyphs and
    # tighter advances (work/build/menu_font_stage/v2); their widths replace the 3DX ones read above.
    v2 = Path(__file__).with_name("font_ascii_widths_v2.json")
    if v2.exists():
        adv.update(json.loads(v2.read_text(encoding="utf-8"))["font"])
    adv.update(EXTRA_SYMBOLS)
    for c in range(0x20, 0x7F):
        adv.setdefault(chr(c), 10)
    hangul = frozenset(ch for ch in map(chr, range(0xAC00, 0xD7A4))
                       if len(ch.encode("euc-kr", errors="ignore")) == 2)
    adv["・"] = 16
    return adv, hangul


def width(line: str) -> int:
    adv, _ = charset()
    return sum(adv.get(c, 16) for c in line)


def visible(text: str) -> str:
    return PH.sub("", text)


def pages(text: str) -> list[list[str]]:
    return [visible(p).split("\n") for p in text.split("[Next]")]


@lru_cache(maxsize=1)
def group_limits() -> dict[tuple[str, int], dict[str, float]]:
    """Per (source, style): max JP line width and p99 lines/page, from text/jp."""
    from make_batches import to_view
    widths: dict[tuple[str, int], list[int]] = defaultdict(list)
    lines: dict[tuple[str, int], list[int]] = defaultdict(list)
    for f in JP.glob("*.json"):
        for m in json.loads(f.read_text(encoding="utf-8"))["messages"]:
            key = (m["id"].split("/")[0].split("#")[0], m["style"])
            for page in pages(to_view(m["jp"])[1]):
                ls = [ln for ln in page if ln.strip()]
                lines[key].append(len(ls))
                widths[key] += [width(ln) for ln in ls]
    out = {}
    for key in widths:
        w, ln = sorted(widths[key]) or [0], sorted(lines[key]) or [1]
        out[key] = {"max_w": w[-1], "p99_lines": ln[min(len(ln) - 1, int(len(ln) * 0.99))]}
    return out


@lru_cache(maxsize=1)
def glossary() -> list[dict]:
    if not GLOSSARY.exists():
        return []
    with GLOSSARY.open(encoding="utf-8", newline="") as f:
        return [r for r in csv.DictReader(f, delimiter="\t") if len(r.get("jp") or "") >= 2 and r.get("ko")]


def _script(ch: str) -> str:
    if "\u30a1" <= ch <= "\u30fa" or ch == "\u30fc":
        return "kata"
    if "\u3041" <= ch <= "\u3096":
        return "hira"
    return ""


# hiragana that commonly follows a noun (particles, copula, sentence-final, する-verb forms): a term
# ending in hiragana and followed by one of these is still a word of its own (ボムへい|が, とっしん|する)
_PARTICLES = frozenset("のをがはにへでともやかよねなだぞぜさわしす")


def _word_in(term: str, text: str) -> bool:
    """term occurs in text as a word of its own, not inside a longer word.

    Katakana glued to katakana is one longer word (ミー in レミー, ブル in ブルブル). Hiragana is
    judged only after the term, because particles follow words: そうび|ん is another word,
    ボムへい|が is not.
    """
    start = text.find(term)
    while start >= 0:
        end = start + len(term)
        prev = text[start - 1] if start > 0 else ""
        nxt = text[end] if end < len(text) else ""
        glued = ((_script(term[0]) == "kata" and prev != "" and _script(prev) == "kata")
                 or (_script(term[-1]) == "kata" and nxt != "" and _script(nxt) == "kata")
                 or (_script(term[-1]) == "hira" and nxt != "" and _script(nxt) == "hira"
                     and nxt not in _PARTICLES))
        if not glued:
            return True
        start = text.find(term, start + 1)
    return False


def check_message(msg: dict, ko: object) -> tuple[list[str], list[str]]:
    errs: list[str] = []
    warns: list[str] = []
    if not isinstance(ko, str) or not ko.strip():
        return ["missing or empty translation"], warns
    src = msg["src"]
    want, got = Counter(PH.findall(src)), Counter(PH.findall(ko))
    if want != got:
        miss = sorted(f"{{{n}:{k}}}" for (n, k), c in (want - got).items())
        extra = sorted(f"{{{n}:{k}}}" for (n, k), c in (got - want).items())
        errs.append(f"placeholders differ (missing {miss}, extra/duplicate {extra})")
    rest = PH.sub("", ko).replace("[Next]", "")
    if re.search(r"[\[\]{}]", rest):
        errs.append("stray bracket/brace (only {n:kind} and [Next] are allowed)")
    if src.count("[Next]") != ko.count("[Next]"):
        errs.append(f"[Next] count {ko.count('[Next]')} != source {src.count('[Next]')}")
    residue = sorted(set(JP_RESIDUE.findall(rest)))
    if residue:
        errs.append(f"Japanese characters left: {''.join(residue)}")
    adv, hangul = charset()
    bad = sorted({c for c in rest if c not in adv and c not in hangul and c != "\n" and not JP_RESIDUE.match(c)})
    if bad:
        errs.append(f"characters not available in the game font: {''.join(bad)} "
                    f"(Hangul must be KS X 1001; no Ⓐ-style buttons, use the {{n:icon}} placeholder)")
    fw = sorted(set(FULLWIDTH.findall(rest)))
    if fw:
        warns.append(f"full-width characters (use half-width): {''.join(fw)}")
    if "・" in rest:
        warns.append("use '·' instead of '・'")

    key = (msg["id"].split("/")[0].split("#")[0], msg["style"])
    lim = group_limits().get(key, {"max_w": 336, "p99_lines": 3})
    src_pages, ko_pages = pages(src), pages(ko)
    for k, page in enumerate(ko_pages):
        ls = [ln for ln in page if ln.strip()]
        jp_ls = [ln for ln in src_pages[k] if ln.strip()] if k < len(src_pages) else []
        for ln in ls:
            w = width(ln)
            if w > lim["max_w"]:
                errs.append(f"page {k + 1}: line too wide ({w}px > {lim['max_w']}px, ~{lim['max_w'] // 16} Hangul): {ln!r}")
            elif jp_ls and w > max(width(j) for j in jp_ls) + 48 and w > 0.8 * lim["max_w"]:
                warns.append(f"page {k + 1}: line much longer than the original ({w}px): {ln!r}")
        if len(ls) > max(len(jp_ls), lim["p99_lines"]):
            errs.append(f"page {k + 1}: {len(ls)} lines (original {len(jp_ls)}, limit {max(len(jp_ls), lim['p99_lines'])})")
        elif len(ls) > len(jp_ls) and jp_ls:
            warns.append(f"page {k + 1}: {len(ls)} lines vs original {len(jp_ls)}")

    # colour tags are switches: warn only when a colour that coloured some text in the
    # original colours nothing in the translation (e.g. highlight moved off its word)
    def colour_segments(text: str) -> dict[str, str]:
        marks = [(m.start(), m.end(), m.group(1)) for m in PH.finditer(text) if m.group(2) == "color"]
        segs = {}
        for i, (_, end, n) in enumerate(marks):
            stop = marks[i + 1][0] if i + 1 < len(marks) else len(text)
            segs[n] = visible(text[end:stop]).replace("[Next]", "").strip()
        return segs
    src_segs, ko_segs = colour_segments(src), colour_segments(ko)
    for n, seg in src_segs.items():
        if seg and n in ko_segs and not ko_segs[n]:
            warns.append(f"colour {{{n}:color}} coloured text in the original but colours nothing here")

    # choice menus: option markers / tabs / indents must keep their order and line layout
    layout = {"choice", "tab", "indent"}
    seq_src = [n for n, k in PH.findall(src) if k in layout]
    seq_ko = [n for n, k in PH.findall(ko) if k in layout]
    if seq_src and seq_src != seq_ko and Counter(seq_src) == Counter(seq_ko):
        errs.append("choice/tab/indent placeholders must keep the original order")
    if seq_src:
        lines_src = [ln for ln in src.split("\n") if PH.search(ln) and any(k in layout for _, k in PH.findall(ln))]
        lines_ko = [ln for ln in ko.split("\n") if PH.search(ln) and any(k in layout for _, k in PH.findall(ln))]
        if len(lines_src) != len(lines_ko):
            errs.append("choice lines: keep the same line breaks as the original menu")
    for m in re.finditer(r"\{\d+:var\}(을|를|이|가|은|는|과|와|으로|로|이다|이야|야)(?![가-힣])", ko):
        warns.append(f"particle '{m.group(1)}' right after a variable (받침 unknown): restructure")

    src_vis, ko_vis = visible(src), visible(ko)
    hits = [g for g in glossary() if _word_in(g["jp"], src_vis)]
    for g in hits:
        if g["ko"] in ko_vis:
            continue
        # a longer matched term that contains this one (買い物をする ⊃ 買い物) and was used covers it
        if any(h is not g and g["jp"] in h["jp"] and h["ko"] in ko_vis for h in hits):
            continue
        warns.append(f"glossary: {g['jp']} → {g['ko']} not used")
    try:
        encode_text(restore(msg, ko))
    except ValueError as exc:
        errs.append(f"does not encode: {exc}")
    return errs, warns


def restore(msg: dict, ko: str) -> str:
    return msg.get("header", "") + PH.sub(lambda m: msg["tags"][m.group(1)], ko)


@lru_cache(maxsize=1)
def jp_messages() -> dict[str, dict]:
    """id -> text/jp message (id, label, style, attr, jp) for every 3DX message."""
    out: dict[str, dict] = {}
    for f in JP.glob("*.json"):
        for m in json.loads(f.read_text(encoding="utf-8"))["messages"]:
            out[m["id"]] = m
    return out


def own_msg(mid: str) -> dict | None:
    """The message `mid` in batch form (src/tags/header/style) built from its OWN Japanese text."""
    from make_batches import to_view
    jm = jp_messages().get(mid)
    if jm is None:
        return None
    header, view, tags = to_view(jm["jp"])
    return {"id": mid, "label": jm.get("label"), "style": jm.get("style"), "src": view,
            "tags": tags, "header": header}


def restore_copy(mid: str, primary: dict, ko: str) -> str:
    """Restore a shared (dup) translation with the copy's own hidden header and tags.

    Copies share the primary's translator view, but their real tags can differ
    (message-box header 0C/0D, pause lengths, colours, button icons).
    """
    own = own_msg(mid)
    if own is None or own["src"] != primary["src"]:
        return restore(primary, ko)
    return restore(own, ko)


def load_dup_overrides() -> tuple[dict[str, str], list[str]]:
    """text/ko/_dup_overrides.json: per-id wording for copies that share a translation.

    {"translations": {id: text in the same {n:kind} form}, "notes": {id: why}}.
    Every entry is validated against that id's own Japanese message; invalid entries are
    reported and skipped (the shared translation stays).
    """
    if not DUP_OVERRIDES.exists():
        return {}, []
    data = json.loads(DUP_OVERRIDES.read_text(encoding="utf-8-sig"))
    ok: dict[str, str] = {}
    errors: list[str] = []
    for mid, text in (data.get("translations") or {}).items():
        own = own_msg(mid)
        if own is None:
            errors.append(f"{mid}: unknown message id")
            continue
        errs, warns = check_message(own, text)
        if errs:
            errors += [f"{mid}: {e}" for e in errs]
            continue
        for w in warns:
            print(f"  W (dup override) {mid}: {w}")
        ok[mid] = restore(own, text)
    return ok, errors


def load_batch(bid: str) -> tuple[dict, dict | None]:
    batch = json.loads((BATCHES / f"{bid}.json").read_text(encoding="utf-8"))
    kp = KO / f"{bid}.json"
    if not kp.exists():
        return batch, None
    try:
        return batch, json.loads(kp.read_text(encoding="utf-8-sig"))
    except json.JSONDecodeError as exc:
        return batch, {"_invalid": f"text/ko/{bid}.json is not valid JSON: {exc}"}


def check_batch(bid: str, verbose: bool = True) -> dict:
    batch, ko = load_batch(bid)
    res = {"batch": bid, "errors": [], "warnings": []}
    if ko is None:
        res["errors"].append(f"text/ko/{bid}.json not found")
    elif "_invalid" in ko:
        res["errors"].append(ko["_invalid"])
    else:
        tr = ko.get("translations", {})
        ids = {m["id"] for m in batch["messages"]}
        for extra in sorted(set(tr) - ids):
            res["errors"].append(f"{extra}: id not in batch")
        for m in batch["messages"]:
            e, w = check_message(m, tr.get(m["id"]))
            res["errors"] += [f"{m['id']}: {x}" for x in e]
            res["warnings"] += [f"{m['id']}: {x}" for x in w]
    if verbose:
        status = "OK" if not res["errors"] else f"{len(res['errors'])} ERRORS"
        print(f"== {bid}: {status}, {len(res['warnings'])} warnings")
        for x in res["errors"][:60]:
            print("  E", x)
        kinds = Counter(re.sub(r"^[^:]+#\d+: ", "", w).split(":")[0].split("(")[0] for w in res["warnings"])
        if res["warnings"]:
            print("  warnings by kind:", dict(kinds.most_common()))
            for x in res["warnings"][:25]:
                print("  W", x)
    return res


def all_batches() -> list[str]:
    return [b["batch"] for b in json.loads((BATCHES / "_index.json").read_text(encoding="utf-8"))]


def cmd_status() -> None:
    ids = all_batches()
    done = [b for b in ids if (KO / f"{b}.json").exists()]
    print(f"batches: {len(ids)} | translated files: {len(done)} | missing: {len(ids) - len(done)}")
    missing = [b for b in ids if b not in done]
    if missing:
        print("missing:", " ".join(missing[:200]))


def cmd_merge() -> int:
    final: dict[str, str] = {}
    report = {"ok": [], "failed": {}, "missing": []}
    terms: dict[str, dict[str, list[str]]] = defaultdict(lambda: defaultdict(list))
    for bid in all_batches():
        if not (KO / f"{bid}.json").exists():
            report["missing"].append(bid)
            continue
        res = check_batch(bid, verbose=False)
        if res["errors"]:
            report["failed"][bid] = res["errors"][:50]
            continue
        batch, ko = load_batch(bid)
        for m in batch["messages"]:
            text_ko = ko["translations"][m["id"]]
            final[m["id"]] = restore(m, text_ko)
            for d in m.get("dups", []):
                final[d] = restore_copy(d, m, text_ko)
        for t in ko.get("new_terms", []) or []:
            if t.get("jp") and t.get("ko"):
                terms[t["jp"]][t["ko"]].append(f"{bid}|{t.get('type', '')}|{t.get('basis', '')}")
        report["ok"].append(bid)
    overrides, override_errors = load_dup_overrides()
    for mid, text in overrides.items():
        final[mid] = text
    report["dup_overrides"] = {"applied": sorted(overrides), "errors": override_errors}
    FINAL.write_text(json.dumps(final, ensure_ascii=False, indent=0), encoding="utf-8")
    REPORT.write_text(json.dumps(report, ensure_ascii=False, indent=1), encoding="utf-8")
    with NEW_TERMS.open("w", encoding="utf-8", newline="") as f:
        w = csv.writer(f, delimiter="\t", lineterminator="\n")
        w.writerow(["jp", "ko", "conflict", "sources"])
        for jp, kos in sorted(terms.items()):
            for ko, src in kos.items():
                w.writerow([jp, ko, "YES" if len(kos) > 1 else "", "; ".join(src[:6])])
    conflicts = sum(1 for k in terms.values() if len(k) > 1)
    print(f"merged {len(report['ok'])} batches ({len(final)} messages incl. duplicates); "
          f"failed {len(report['failed'])}; missing {len(report['missing'])}; "
          f"new terms {len(terms)} ({conflicts} with conflicting translations)")
    for bid, errs in list(report["failed"].items())[:20]:
        print(f"  FAILED {bid}: {errs[0]}")
    print(f"dup overrides ({DUP_OVERRIDES.name}): {len(overrides)} applied, {len(override_errors)} errors")
    for e in override_errors[:20]:
        print(f"  OVERRIDE ERROR {e}")
    return 0


def cmd_grep(needle: str) -> None:
    for kp in sorted(KO.glob("*.json")):
        tr = json.loads(kp.read_text(encoding="utf-8")).get("translations", {})
        for mid, text in tr.items():
            if isinstance(text, str) and needle in text:
                print(f"{kp.stem} | {mid} | {text.replace(chr(10), ' / ')[:160]}")


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--check", nargs="+")
    ap.add_argument("--check-all", action="store_true")
    ap.add_argument("--status", action="store_true")
    ap.add_argument("--merge", action="store_true")
    ap.add_argument("--grep")
    a = ap.parse_args()
    if a.status:
        cmd_status()
    if a.grep:
        cmd_grep(a.grep)
    if a.merge:
        return cmd_merge()
    targets = a.check or ([b for b in all_batches() if (KO / f"{b}.json").exists()] if a.check_all else [])
    failed = sum(1 for b in targets if check_batch(b)["errors"])
    if targets:
        print(f"checked {len(targets)} batch(es), {failed} with errors")
    return 1 if failed else 0


if __name__ == "__main__":
    sys.exit(main())
