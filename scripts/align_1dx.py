"""Pair 3DX messages with 1DX Korean messages by label, for checking official 1DX wording.

  python scripts/align_1dx.py            -> work/review/kj_1dx_pairs.tsv

The two games share AlphaDream's label scheme, so the Bowser Jr. RPG labels map onto the
Bowser's Minions ones (KJGuide_* -> KGGuide_*, Menu_KJ_Chr_exp_* -> KMsgChr_exp_*, Kj_Btl_* ->
KMsgBtl_*, KJ_Msg_*/KJMsg_* -> KMsg_*) and many system labels are identical (E_/N_/Ns_Item*,
amiibo_sys_err_*, Retry_*, Hint_*). A shared label is not always the same text (guide numbers
were reshuffled), so every pair carries `sim`, the Hangul/Latin bigram overlap of our Korean and
the 1DX Korean (1.0 = same wording). Read-only on text/jp, work/ko_final.json, work/ref_1dx_ko.tsv.
"""

from __future__ import annotations

import csv
import json
import re
from collections import Counter, defaultdict

from lib3dx import ROOT

REF_1DX = ROOT / "work" / "ref_1dx_ko.tsv"
OUT = ROOT / "work" / "review" / "kj_1dx_pairs.tsv"
TAG = re.compile(r"\[[^\]]*\]")
RUBY = re.compile(r"\[Ruby ([^;\]]*);[^\]]*\]")
LABEL_MAP = [(r"^KJGuide_", "KGGuide_"), (r"^KJMsg_", "KMsg_"), (r"^KJ_Msg_", "KMsg_"),
             (r"^Kj_Btl_", "KMsgBtl_"), (r"^kj_Btl_", "KMsgBtl_"), (r"^Menu_KJ_Chr_", "KMsgChr_"),
             (r"^Menu_KJ_", "KMsg_"), (r"^Menu_KJ_", "KMsgMenu_")]


def plain(text: str) -> str:
    """Visible text: ruby bases kept, control tags dropped, line breaks as ' / '."""
    return TAG.sub("", RUBY.sub(r"\1", text)).replace("\\n", " / ").replace("\n", " / ")


def candidates(label: str) -> list[str]:
    out = [label]
    for pat, rep in LABEL_MAP:
        if re.match(pat, label):
            out.append(re.sub(pat, rep, label))
    return out


def bigrams(s: str) -> Counter:
    s = re.sub(r"[^가-힣A-Za-z0-9]", "", s)
    return Counter(s[i:i + 2] for i in range(len(s) - 1))


def similarity(a: str, b: str) -> float:
    x, y = bigrams(a), bigrams(b)
    if not x or not y:
        return 0.0
    return sum((x & y).values()) / min(sum(x.values()), sum(y.values()))


def main() -> None:
    with REF_1DX.open(encoding="utf-8", newline="") as f:
        ref = list(csv.DictReader(f, delimiter="\t"))
    by_label: dict[str, list[dict]] = defaultdict(list)
    for r in ref:
        by_label[r["label"]].append(r)
    final = json.loads((ROOT / "work" / "ko_final.json").read_text(encoding="utf-8"))
    rows = []
    for path in sorted((ROOT / "text" / "jp").glob("*.json")):
        for m in json.loads(path.read_text(encoding="utf-8"))["messages"]:
            seen = set()
            for lab in candidates(m.get("label") or ""):
                for r in by_label.get(lab, []):
                    key = plain(r["text"])
                    if key in seen:
                        continue
                    seen.add(key)
                    ko = plain(final.get(m["id"], ""))
                    rows.append([m["id"], m["label"], plain(m["jp"]), ko, f"{r['key']}#{r['index']}",
                                 r["label"], key, f"{similarity(ko, key):.2f}"])
    OUT.parent.mkdir(parents=True, exist_ok=True)
    with OUT.open("w", encoding="utf-8", newline="") as f:
        w = csv.writer(f, delimiter="\t", lineterminator="\n")
        w.writerow(["id", "label", "jp", "ko", "ref_1dx", "label_1dx", "ko_1dx", "sim"])
        w.writerows(rows)
    print(f"wrote {OUT.relative_to(ROOT)}: {len(rows)} pairs for {len({r[0] for r in rows})} 3DX messages")


if __name__ == "__main__":
    main()
