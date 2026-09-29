"""Classify every translated message by how much of it comes from the DS Korean text.

  python scripts/review_triage.py

For each batch, each Korean translation is compared with the batch's DS reference lines
(inline `ds_reference` or the shared `@file work/batches/_refs_*.txt`):

  ds      almost all of the Korean text appears in one DS line (copied, maybe re-wrapped)
  edited  a large part comes from a DS line, the rest was changed or added
  new     no DS line covers it (3DX-only content or a free translation)
  short   too short to judge (a few characters)

Writes work/review/triage.json:
  {"summary": {...}, "batches": {batch: {"counts": {...}, "msgs": {id: [class, coverage, ds_key]}}}}
Reviewers read every `new` and `edited` message and spot-check `ds` ones.
"""

from __future__ import annotations

import difflib
import json
import re
import sys
from collections import Counter, defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
BATCHES = ROOT / "work" / "batches"
KO = ROOT / "text" / "ko"
OUT = ROOT / "work" / "review" / "triage.json"

PLACEHOLDER = re.compile(r"\{\d+:\w+\}")
ENTRY = re.compile(r"^(DS\S*?#[\w.]+): ?(.*)$")
NOISE = re.compile(r"[\s.,!?~…·―\-「」()\[\]'\"♪♥★☆]+")
DS_MIN, EDITED_MIN, SHORT_BIGRAMS = 0.9, 0.55, 5


def norm(text: str) -> str:
    """Visible characters only: no placeholders, page breaks, spaces or punctuation."""
    text = PLACEHOLDER.sub("", text).replace("[Next]", " ")
    return NOISE.sub("", text)


def bigrams(s: str) -> set[str]:
    return {s[i:i + 2] for i in range(len(s) - 1)}


def parse_refs(lines: list[str]) -> list[tuple[str, str]]:
    """-> [(ds_key, text)]; lines that do not start an entry continue the previous one."""
    out: list[list[str]] = []
    for ln in lines:
        m = ENTRY.match(ln)
        if m:
            out.append([m.group(1), m.group(2)])
        elif out:
            out[-1][1] += "\n" + ln
    return [(k, t) for k, t in out]


class RefIndex:
    def __init__(self, entries: list[tuple[str, str]]):
        self.keys = [k for k, _ in entries]
        self.texts = [norm(t) for _, t in entries]
        self.grams = [bigrams(t) for t in self.texts]
        self.inv: dict[str, list[int]] = defaultdict(list)
        for i, g in enumerate(self.grams):
            for b in g:
                self.inv[b].append(i)

    def best(self, ko: str) -> tuple[float, str]:
        g = bigrams(ko)
        if not g:
            return 0.0, ""
        hits: Counter[int] = Counter()
        for b in g:
            for i in self.inv.get(b, ()):
                hits[i] += 1
        best_cov, best_key = 0.0, ""
        for i, _n in hits.most_common(8):
            cov = len(g & self.grams[i]) / len(g)
            if cov > best_cov or (cov == best_cov and best_key and
                                  difflib.SequenceMatcher(None, ko, self.texts[i]).ratio() > 0.5):
                best_cov, best_key = cov, self.keys[i]
        return best_cov, best_key


def load_refs(batch: dict, cache: dict[str, RefIndex]) -> RefIndex | None:
    refs = batch.get("ds_reference") or []
    if not refs:
        return None
    if refs[0].startswith("@file"):
        rel = refs[0].split(None, 1)[1].strip().split()[0]
        if rel not in cache:
            lines = (ROOT / rel).read_text(encoding="utf-8").splitlines()
            cache[rel] = RefIndex(parse_refs(lines))
        return cache[rel]
    lines: list[str] = []
    for r in refs:
        lines.extend(r.split("\n"))
    return RefIndex(parse_refs(lines))


def main() -> int:
    sys.stdout.reconfigure(encoding="utf-8")
    index = json.loads((BATCHES / "_index.json").read_text(encoding="utf-8"))
    cache: dict[str, RefIndex] = {}
    result: dict[str, dict] = {}
    total: Counter[str] = Counter()
    for entry in index:
        bid = entry["batch"]
        batch = json.loads((BATCHES / f"{bid}.json").read_text(encoding="utf-8"))
        kp = KO / f"{bid}.json"
        if not kp.exists():
            print(f"{bid}: no translation, skipped")
            continue
        tr = json.loads(kp.read_text(encoding="utf-8-sig")).get("translations", {})
        refs = load_refs(batch, cache)
        msgs, counts = {}, Counter()
        for m in batch["messages"]:
            ko = norm(tr.get(m["id"], ""))
            if len(bigrams(ko)) < SHORT_BIGRAMS:
                cls, cov, key = "short", 0.0, ""
            elif refs is None:
                cls, cov, key = "new", 0.0, ""
            else:
                cov, key = refs.best(ko)
                cls = "ds" if cov >= DS_MIN else "edited" if cov >= EDITED_MIN else "new"
            msgs[m["id"]] = [cls, round(cov, 2), key]
            counts[cls] += 1
        total.update(counts)
        result[bid] = {"counts": dict(counts), "msgs": msgs}
    OUT.parent.mkdir(parents=True, exist_ok=True)
    OUT.write_text(json.dumps({"summary": dict(total), "batches": result}, ensure_ascii=False, indent=0),
                   encoding="utf-8")
    print(f"messages: {sum(total.values())} | " + " | ".join(f"{k} {v}" for k, v in total.most_common()))
    for bid, r in result.items():
        c = r["counts"]
        print(f"{bid}: new {c.get('new', 0)} edited {c.get('edited', 0)} ds {c.get('ds', 0)} short {c.get('short', 0)}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
