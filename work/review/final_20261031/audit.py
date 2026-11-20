"""Final pre-release translation audit (2026-10-31): automated consistency checks over all 9,623 messages.

    .venv\\Scripts\\python work\\review\\final_20261031\\audit.py        -> findings.tsv, summary.md, sample.txt

Reads only: work/batches (src with placeholders, labels, dups), text/ko (translations), text/glossary.tsv,
work/review/triage.json (ds / edited / new / short). Writes only into this folder.

Checks (one row per hit in findings.tsv; `check` column):
  samejp      same Japanese text (visible, spacing ignored) translated differently in different representatives
  glossary    merge_ko glossary warnings (term in the source, glossary Korean absent)
  space       the same compound written both with and without a space (corpus-wide), e.g. 퍼즐 피스 / 퍼즐피스
  glossvar    a glossary Korean term written with a different spacing than the glossary
  particle    particle that does not match the final sound (를 after a final consonant, 으로 after a vowel, ...)
  punct       ... / .. / ?! / ?? / !… / double space / space before punctuation / unbalanced brackets / line-edge spaces
  spell       common Korean misspellings and bound-noun spacing (할수 있다, 것같다, 할때, 되요, 할께, ...)
  number      digits in the Korean that the Japanese does not have; Japanese numbers >= 10 missing in the Korean
  length      Korean visible text much shorter / longer than the Japanese (possible omission / addition)
  voice       character speech tics missing (るる->롱롱, リュリュ->로로, びん->로빈, ガハハ->크핫, ケケケ->케케케)
  choice      はい/いいえ choices not 예/아니요; 아니오 anywhere
  names       an item / enemy / skill name (style-13 name message) used in another message with a different Korean
  oldname     retired names (수림, 무지오, 용기 for リューギー), 쿠파Jr / Jr. / 쿠파 주니어 spellings
  latin       Latin words in the Korean (inventory, for a quick look)
"""
from __future__ import annotations

import collections
import csv
import json
import random
import re
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
sys.path.insert(0, str(ROOT / "scripts"))
import merge_ko as MK  # noqa: E402

PH = re.compile(r"\{(\d+):([a-z]+)\}")
BOUND = r"(?=[\s.,!?…~\)」』\]¶◆Ⓥ♪♥·:;\-―]|$)"
FW = str.maketrans("０１２３４５６７８９", "0123456789")


def vis(s: str) -> str:
    """placeholders -> markers: var Ⓥ, icon ◆, others removed; [Next] -> ¶."""
    def rep(m):
        k = m.group(2)
        return "Ⓥ" if k == "var" else "◆" if k == "icon" else ""
    return PH.sub(rep, s).replace("[Next]", "¶")


def flat(s: str) -> str:
    return re.sub(r"\s+", " ", vis(s).replace("¶", " ")).strip()


def nospace(s: str) -> str:
    return re.sub(r"[\s¶]+", "", vis(s))


def jong(ch: str) -> int | None:
    c = ord(ch) - 0xAC00
    return c % 28 if 0 <= c < 11172 else None


# ----------------------------------------------------------------------------- data

def load():
    msgs, tr, batch_of = {}, {}, {}
    for bid in MK.all_batches():
        batch, ko = MK.load_batch(bid)
        for m in batch["messages"]:
            msgs[m["id"]] = m
            batch_of[m["id"]] = bid
            tr[m["id"]] = ko["translations"][m["id"]]
    tri = {}
    for b in json.loads((ROOT / "work/review/triage.json").read_text(encoding="utf-8"))["batches"].values():
        for mid, v in b["msgs"].items():
            tri[mid] = v[0]
    gloss = list(csv.DictReader(open(ROOT / "text/glossary.tsv", encoding="utf-8"), delimiter="\t"))
    return msgs, tr, batch_of, tri, gloss


ROWS: list[dict] = []


def add(check, mid, detail, msgs, tr, batch_of, tri, sev="check"):
    m = msgs.get(mid, {})
    ROWS.append({"check": check, "sev": sev, "id": mid, "label": m.get("label", ""), "style": m.get("style", ""),
                 "batch": batch_of.get(mid, ""), "cat": tri.get(mid, ""),
                 "jp": flat(m.get("src", "")) if m else "", "ko": flat(tr.get(mid, "")) if mid in tr else "",
                 "detail": detail})


# ----------------------------------------------------------------------------- checks

def c_samejp(msgs, tr, *ctx):
    groups = collections.defaultdict(list)
    for mid, m in msgs.items():
        k = nospace(m["src"])
        if k:
            groups[k].append(mid)
    n = 0
    for k, ids in groups.items():
        if len(ids) < 2:
            continue
        variants = collections.defaultdict(list)
        for mid in ids:
            variants[flat(tr[mid]).replace(" ", "") if False else flat(tr[mid])].append(mid)
        if len(variants) > 1:
            n += 1
            # spacing-only difference is reported separately from wording differences
            kind = "spacing-only" if len({v.replace(" ", "") for v in variants}) == 1 else "wording"
            desc = " || ".join(f"[{len(v)}] {t}" for t, v in sorted(variants.items(), key=lambda x: -len(x[1])))
            for mid in ids:
                add("samejp", mid, f"{kind}: {desc}", msgs, tr, *ctx)
    return n


def c_glossary(msgs, tr, *ctx):
    n = 0
    for bid in MK.all_batches():
        res = MK.check_batch(bid, verbose=False)
        for w in res["warnings"]:
            mid, _, rest = w.partition(": ")
            if rest.startswith("glossary"):
                add("glossary", mid, rest, msgs, tr, *ctx)
                n += 1
            else:
                add("checker", mid, rest, msgs, tr, *ctx)
    return n


PARTICLE_TAIL = re.compile(r"(으로부터|로부터|에서는|에서도|에게는|에게도|으로는|로는|으로도|로도|까지는|부터는|에서|에게|한테|까지|부터|처럼|보다|"
                           r"이라도|라도|이나|이란|이라|으로|이야|이에요|예요|입니다|이다|의|을|를|이|가|은|는|에|로|와|과|도|만|나|랑|야|아|요|께)$")


def tokens(text: str) -> list[list[str]]:
    """lines of space-separated words; punctuation inside a word (「」 ~ … ―) is dropped, so only real spaces split."""
    out = []
    for line in re.split(r"[\n¶]", vis(text)):
        words = []
        for w in line.split(" "):
            w = re.sub(r"[^\w가-힣]", "", w)
            if w:
                words.append(w)
        out.append(words)
    return out


def c_space(msgs, tr, *ctx):
    joined_prefix = collections.Counter()
    tok_lines = {}
    for mid, t in tr.items():
        tl = tokens(t)
        tok_lines[mid] = tl
        for line in tl:
            for tok in line:
                if re.fullmatch(r"[가-힣]+", tok):
                    for i in range(2, len(tok) + 1):
                        joined_prefix[tok[:i]] += 1
    pairs = collections.defaultdict(list)
    for mid, tl in tok_lines.items():
        for line in tl:
            for a, b in zip(line, line[1:]):
                if not (re.fullmatch(r"[가-힣]{1,8}", a) and re.fullmatch(r"[가-힣]{1,10}", b)):
                    continue
                stem = PARTICLE_TAIL.sub("", b) if len(b) > 1 else b
                if not stem:
                    continue
                j = a + stem
                if len(j) >= 3 and joined_prefix[j]:
                    pairs[(a, stem)].append(mid)
    n = 0
    for (a, stem), ids in pairs.items():
        j = a + stem
        jc = joined_prefix[j] - sum(1 for _ in ())  # joined occurrences (as token prefix)
        # tokens that START with the joined form but are not just a longer spaced phrase
        add_rows = ids if len(ids) <= 3 or jc <= 3 else ids[:3]
        for mid in add_rows:
            add("space", mid, f"'{a} {stem}' x{len(ids)} vs '{j}' x{jc}", msgs, tr, *ctx)
        n += 1
    return n


def c_glossvar(msgs, tr, gloss, *ctx):
    import bisect
    ids = list(tr)
    parts, starts, pos = [], [], 0
    for mid in ids:
        s = flat(tr[mid]) + "\u0001"
        starts.append(pos)
        parts.append(s)
        pos += len(s)
    corpus = "".join(parts)
    kos = {g["ko"].strip() for g in gloss}
    n = 0
    seen = set()
    for g in gloss:
        k = g["ko"].strip()
        if not re.fullmatch(r"[가-힣 ]{3,}", k) or k in seen:
            continue
        seen.add(k)
        variants = [k.replace(" ", "")] if " " in k else [k[:i] + " " + k[i:] for i in range(1, len(k))]
        for v in variants:
            if v == k or v in kos:
                continue
            hit_ids = []
            for m in re.finditer(r"(?<![가-힣])" + re.escape(v), corpus):
                hit_ids.append(ids[bisect.bisect_right(starts, m.start()) - 1])
            for mid in dict.fromkeys(hit_ids):
                add("glossvar", mid, f"glossary '{k}' ({g['jp']}) written '{v}'", msgs, tr, *ctx)
                n += 1
    return n


LATIN_BATCHIM = {"HP": 0, "SP": 0, "BP": 0, "POW": 0, "SPEED": 0, "SUYEOM": 16, "PPUL": 8, "GDH": 0, "GDD": 0,
                 "EXP": 0, "LV": 0, "DX": 0, "amiibo": 0, "BGM": 16, "Excellent": 0, "LUCKY": 0, "DEF": 0,
                 "SP업": 0, "OK": 0, "SUN": 4, "SAK": 1}
LETTER = {"L": 8, "R": 8, "M": 16, "N": 4}
DIGIT = {"0": 21, "1": 8, "2": 0, "3": 16, "4": 0, "5": 0, "6": 1, "7": 8, "8": 8, "9": 0}
ZEROS = {1: 17, 2: 1, 3: 4, 4: 4}      # 십(ㅂ) 백(ㄱ) 천(ㄴ) 만(ㄴ)


def final_of_word(w: str) -> int | None:
    """jongseong index of how the word ends when read aloud (None = unknown)."""
    if not w:
        return None
    if re.match(r"[가-힣]", w[-1]):
        return jong(w[-1])
    m = re.search(r"([A-Za-z]+)$", w)
    if m:
        word = m.group(1)
        if word in LATIN_BATCHIM:
            return LATIN_BATCHIM[word]
        if word.isupper() or len(word) == 1:
            return LETTER.get(word[-1].upper(), 0)
        return None
    m = re.search(r"(\d+)$", w.translate(FW))
    if m:
        d = m.group(1)
        z = len(d) - len(d.rstrip("0"))
        if d.strip("0") == "":
            return 21
        return ZEROS.get(z, None) if z else DIGIT[d[-1]]
    return None


RULES = [  # (particle, needs_final: True=after final consonant, False=after vowel, special)
    ("을", True), ("를", False), ("은", True), ("는", False), ("이", True), ("가", False), ("과", True), ("와", False),
    ("으로", "ro_eu"), ("로", "ro"), ("이나", True), ("이랑", True), ("랑", False), ("이에요", True), ("예요", False),
    ("이라고", True), ("라고", False), ("이라는", True), ("라는", False), ("이야", True), ("아", True), ("야", False),
]


def ok_particle(fin: int, p, need) -> bool:
    if need == "ro_eu":
        return fin not in (0, 8)
    if need == "ro":
        return fin in (0, 8)
    return (fin != 0) == need


def c_particle(msgs, tr, gloss, *ctx):
    n = 0
    names = {g["ko"].strip() for g in gloss if g["type"] in ("character", "boss", "enemy", "item", "badge", "gear",
                                                              "key_item", "place", "attack", "ability", "skill")}
    names = {x for x in names if len(x) >= 2 and not re.search(r"[^\w가-힣 &·]", x)}
    name_re = re.compile("(" + "|".join(sorted(map(re.escape, names), key=len, reverse=True)) + ")"
                         r"(으로|이에요|이라고|이라는|이나|이랑|이야|예요|라고|라는|랑|을|를|은|는|이|가|과|와|로|야|아)" + BOUND)
    generic = [  # high-precision generic rules
        (re.compile(r"([가-힣])를" + BOUND), lambda f: f != 0, "를 after a final consonant"),
        (re.compile(r"([가-힣])으로" + BOUND), lambda f: f in (0, 8), "으로 after a vowel / ㄹ"),
        (re.compile(r"([가-힣])예요" + BOUND), lambda f: f != 0, "예요 after a final consonant"),
    ]
    soft = [  # need an exception list
        (re.compile(r"(?<![가-힣])([가-힣]*?)([가-힣])을" + BOUND), "을 after a vowel",
         {"마을", "가을", "노을", "고을", "이을", "지을", "나을", "부을", "저을", "그을", "젓을", "붓을", "보이을"}),
        (re.compile(r"(?<![가-힣])([가-힣]*?)([가-힣])은" + BOUND), "은 after a vowel",
         {"나은", "지은", "부은", "이은", "그은", "저은", "보은", "다은"}),
        (re.compile(r"(?<![가-힣])([가-힣]*?)([가-힣])과" + BOUND), "과 after a vowel",
         {"효과", "사과", "교과", "외과", "치과", "부과", "초과", "소과", "과"}),
        (re.compile(r"(?<![가-힣])([가-힣]*?)([가-힣])와" + BOUND), "와 after a final consonant", {"나와", "들어와", "와"}),
        (re.compile(r"(?<![가-힣])([가-힣]*?)([가-힣])에요" + BOUND), "에요 after a vowel (예요?)",
         {"아니에요"}),
    ]
    latin = re.compile(r"([A-Za-z0-9０-９]+)[」』)]?(을|를|은|는|이|가|과|와|으로|로)" + BOUND)
    for mid, t in tr.items():
        s = vis(t)
        hits = []
        for m in name_re.finditer(s):
            word, p = m.group(1), m.group(2)
            # longer Hangul word containing the name (e.g. 초록등껍질) is fine: require a non-Hangul char before
            st = m.start(1)
            if st > 0 and re.match(r"[가-힣]", s[st - 1]):
                continue
            fin = final_of_word(word)
            need = dict(RULES).get(p)
            if fin is None or need is None:
                continue
            if not ok_particle(fin, p, need):
                hits.append(f"{word}+{p}")
        for rx, bad, why in generic:
            for m in rx.finditer(s):
                f = jong(m.group(1))
                if f is not None and bad(f):
                    hits.append(f"{m.group(0)} ({why})")
        for rx, why, exc in soft:
            for m in rx.finditer(s):
                if why.startswith("에요") and m.group(2) == "이":
                    continue  # X이에요 (copula after a final consonant) is the correct form
                tail = s[m.start(2):m.end()].rstrip()
                full = m.group(1) + tail
                f = jong(m.group(2))
                if f is None:
                    continue
                if why.startswith(("을", "은", "과", "에요")) and f == 0:
                    if not any(full.rstrip("!?.,…~ ").endswith(e) for e in exc):
                        hits.append(f"{full.strip()} ({why})")
                if why.startswith("와") and f != 0:
                    if not any(full.rstrip("!?.,…~ ").endswith(e) for e in exc):
                        hits.append(f"{full.strip()} ({why})")
        for m in latin.finditer(s):
            w, p = m.group(1), m.group(2)
            st = m.start(1)
            if st > 0 and re.match(r"[가-힣A-Za-z0-9]", s[st - 1]):
                prev = re.search(r"[가-힣A-Za-z0-9]+$", s[:st])
                w = (prev.group(0) if prev else "") + w
            fin = final_of_word(w)
            need = dict(RULES).get(p)
            if fin is None or need is None:
                continue
            if not ok_particle(fin, p, need):
                hits.append(f"{w}+{p} (read aloud)")
        for h in dict.fromkeys(hits):
            add("particle", mid, h, msgs, tr, *ctx)
            n += 1
    return n


def c_punct(msgs, tr, *ctx):
    n = 0
    pats = [
        (re.compile(r"(?<!\.)\.\.(?!\.)|\.\.\."), "... / .. (style: …)"),
        (re.compile(r"\?!|\?\?"), "?! / ?? (style: !?)"),
        (re.compile(r"!…"), "!… (style: not used)"),
        (re.compile(r"[^\s]  +[^\s]"), "double space"),
        (re.compile(r"[가-힣A-Za-z0-9] +[!?.,](?![.\d])"), "space before punctuation"),
        (re.compile(r" +\n|\n +"), "space at a line edge"),
        (re.compile(r"[！？～、。，：；（）　]"), "full-width punctuation"),
    ]
    for mid, t in tr.items():
        s = vis(t).replace("¶", "\n")      # icons stay as ◆, variables as Ⓥ
        hits = []
        for rx, why in pats:
            for m in rx.finditer(s):
                hits.append(f"{why}: '{s[max(0, m.start() - 6):m.end() + 6]}'".replace("\n", "/"))
        for a, b in (("「", "」"), ("(", ")"), ("『", "』"), ("[", "]")):
            if s.count(a) != s.count(b):
                hits.append(f"unbalanced {a}{b}: {s.count(a)} vs {s.count(b)}")
        for h in dict.fromkeys(hits):
            add("punct", mid, h, msgs, tr, *ctx)
            n += 1
    return n


SPELL = [
    (r"됬", "됬 -> 됐"), (r"되요", "되요 -> 돼요"), (r"(?<![가-힣])되서", "되서 -> 돼서"), (r"안돼|안되(?=[^어었고는면지게기])", "안돼/안되 -> 안 돼/안 되"),
    (r"않되|않돼", "않되 -> 안 돼"), (r"(할|갈|볼|올|줄|될|칠|살|놀|만들|도와줄|해줄)께", "-ㄹ께 -> -ㄹ게"),
    (r"(할|갈|볼|줄|될)껄", "-ㄹ껄 -> -ㄹ걸"), (r"금새", "금새 -> 금세"), (r"일부로", "일부로 -> 일부러"),
    (r"오랫만", "오랫만 -> 오랜만"), (r"희안", "희안 -> 희한"), (r"설레임", "설레임 -> 설렘"), (r"바램", "바램 -> 바람"),
    (r"어의없", "어의없 -> 어이없"), (r"역활", "역활 -> 역할"), (r"몇\s?일", "몇일 -> 며칠"), (r"(할|갈|볼|올|줄)려고", "-ㄹ려고 -> -려고"),
    (r"뵈요", "뵈요 -> 봬요"), (r"웬지", "웬지 -> 왠지"), (r"왠만|왠일", "왠만/왠일 -> 웬만/웬일"), (r"어떻해", "어떻해 -> 어떡해"),
    (r"어떡게", "어떡게 -> 어떻게"), (r"것같", "것같 -> 것 같"), (r"(있|없)슴", "-슴 -> -음"), (r"됀", "됀 -> 된"),
    (r"[가-힣]꺼(?=야|예요|에요|다|지|니|라|잖|든)", "꺼 -> 거"), (r"아니예요", "아니예요 -> 아니에요"),
    (r"(?<![가-힣])(거|뭐|누구|어디)에요", "거에요/뭐에요 -> 거예요/뭐예요"), (r"야 겠(?=다|어|네|지|습|어요)", "-야 겠 -> -야겠"),
    (r"(?<![가-힣])왠(?! ?지|지)", "왠 -> 웬"), (r"[가-힣]데로(?! 가|가)", "-데로 (대로?)"),
    (r"할 지 ", "할 지 -> 할지"), (r"(?<=[가-힣])(?<![는은을를])수(있|없)", "수있 -> 수 있"),
]
BOUND_NOUN = [  # (bound noun right after an ㄹ-final adnominal, attached = error)
    ("수", r"수(?= ?(있|없|밖에|도))"), ("때", r"때"), ("거", r"거(?=야|예요|에요|다|라|지|니|잖|란|래|면|든|\s|$|[!?.…~])"),
    ("줄", r"줄(?= (알|몰))"), ("뿐", r"뿐"), ("만큼", r"만큼"), ("테", r"테(?=니|고|야|다|지|요|데)"), ("것", r"것"),
]


def c_spell(msgs, tr, *ctx):
    n = 0
    spell = [(re.compile(p), why) for p, why in SPELL]
    bound = [(name, re.compile(r"([가-힣])" + p)) for name, p in BOUND_NOUN]
    for mid, t in tr.items():
        s = vis(t).replace("¶", "\n")
        hits = []
        for rx, why in spell:
            for m in rx.finditer(s):
                hits.append(f"{why}: '{s[max(0, m.start() - 6):m.end() + 6]}'".replace("\n", "/"))
        for name, rx in bound:
            for m in rx.finditer(s):
                f = jong(m.group(1))
                if f == 8 and m.group(1) not in ("일", "물", "말", "길", "날", "발", "칼", "술", "살", "줄", "글", "들", "알", "얼", "털", "벌", "별", "불", "돌", "굴", "풀", "활", "실", "열", "출", "물", "철", "탈", "할"[:0]):
                    # ㄹ-final syllable glued to a bound noun: 할수/할때/할거/할줄/할뿐/할만큼/할테/할것
                    w0 = re.search(r"[가-힣]*$", s[:m.start(1)]).group(0)
                    hits.append(f"bound noun '{name}' glued: '{w0}{m.group(0)}'")
        for h in dict.fromkeys(hits):
            add("spell", mid, h, msgs, tr, *ctx)
            n += 1
    return n


def c_number(msgs, tr, *ctx):
    n = 0
    for mid, m in msgs.items():
        jp = PH.sub("", m["src"]).translate(FW)
        ko = PH.sub("", tr[mid]).translate(FW)
        jn = collections.Counter(re.findall(r"\d+", jp))
        kn = collections.Counter(re.findall(r"\d+", ko))
        extra = kn - jn
        miss = {k: v for k, v in (jn - kn).items() if int(k) >= 10}
        if extra:
            add("number", mid, f"Korean has {dict(extra)} not in the Japanese", msgs, tr, *ctx)
            n += 1
        if miss:
            add("number", mid, f"Japanese {miss} missing in the Korean", msgs, tr, *ctx)
            n += 1
    return n


def c_length(msgs, tr, *ctx):
    n = 0
    rat = []
    for mid, m in msgs.items():
        j = len(re.sub(r"[\s\W_]", "", PH.sub("", m["src"]).replace("[Next]", "")))
        k = len(re.sub(r"[\s\W_]", "", PH.sub("", tr[mid]).replace("[Next]", "")))
        if j >= 25:
            rat.append((k / j, mid, j, k))
    rat.sort()
    lo = [r for r in rat if r[0] < 0.45]
    hi = [r for r in rat if r[0] > 1.6]
    for r, mid, j, k in lo + hi:
        add("length", mid, f"ratio {r:.2f} (jp {j} / ko {k} chars)", msgs, tr, *ctx)
        n += 1
    if rat:
        med = rat[len(rat) // 2][0]
        ROWS.append({"check": "length", "sev": "info", "id": "-", "label": "", "style": "", "batch": "", "cat": "",
                     "jp": "", "ko": "", "detail": f"median ratio {med:.2f} over {len(rat)} messages"})
    return n


VOICE = [
    (re.compile(r"るる"), "롱", "까르코비츠 るる -> 롱롱"),
    (re.compile(r"リュリュ|りゅりゅ"), "로로", "까르코비츠 リュリュ -> 로로"),
    (re.compile(r"(?<![ゆうきせ])び[ん～ー]+(?:[！？。…よかねっ～]|$|\s)"), "로빈", "헬로글로빈 びん -> 로빈"),
    (re.compile(r"ガハハ|ガーッハッハ|ガッハッハ"), "크핫", "쿠파 ガハハ -> 크핫핫"),
    (re.compile(r"ケケケ"), "케케", "부끄부끄 ケケケ -> 케케케"),
]


def c_voice(msgs, tr, *ctx):
    n = 0
    for mid, m in msgs.items():
        jp = PH.sub("", m["src"])
        ko = vis(tr[mid])
        for rx, want, why in VOICE:
            if rx.search(jp) and want not in ko:
                add("voice", mid, why, msgs, tr, *ctx)
                n += 1
    return n


def c_choice(msgs, tr, *ctx):
    n = 0
    for mid, m in msgs.items():
        ko = vis(tr[mid])
        if "아니오" in ko:
            add("choice", mid, "아니오 (style: 아니요)", msgs, tr, *ctx)
            n += 1
        src = m["src"]
        if "choice}" in src:
            js = [x.split("{")[0].strip() for x in re.split(r"\{\d+:choice\}", PH.sub(lambda q: q.group(0) if q.group(2) == "choice" else "", src))[1:]]
            ks = [x.split("{")[0].strip() for x in re.split(r"\{\d+:choice\}", PH.sub(lambda q: q.group(0) if q.group(2) == "choice" else "", tr[mid]))[1:]]
            for a, b in zip(js, ks):
                a1, b1 = a.split("\n")[0].strip(), b.split("\n")[0].strip()
                if a1 in ("はい", "はい！") and b1 not in ("예", "예!"):
                    add("choice", mid, f"choice はい -> '{b1}'", msgs, tr, *ctx)
                    n += 1
                if a1 in ("いいえ", "いいえ！") and b1 not in ("아니요", "아니요!"):
                    add("choice", mid, f"choice いいえ -> '{b1}'", msgs, tr, *ctx)
                    n += 1
    return n


def c_names(msgs, tr, *ctx):
    """style-13 name messages (items, gear, badges, enemies, skills...) as a name table."""
    table = collections.defaultdict(set)
    for mid, m in msgs.items():
        if m.get("style") == 13:
            j = re.sub(r"\s+", "", vis(m["src"])).strip()
            k = flat(tr[mid])
            if re.fullmatch(r"[\u30a0-\u30ffー・Ａ-Ｚａ-ｚA-Za-z０-９0-9\u3040-\u309f]{4,}", j) and re.search(r"[가-힣]", k):
                table[j].add(k)
    n = 0
    multi = {j: ks for j, ks in table.items() if len(ks) > 1}
    for j, ks in multi.items():
        ids = [mid for mid, m in msgs.items() if m.get("style") == 13 and re.sub(r"\s+", "", vis(m["src"])) == j]
        for mid in ids:
            add("names", mid, f"one Japanese name, several Korean names: {j} -> {sorted(ks)}", msgs, tr, *ctx)
            n += 1
    single = {j: next(iter(ks)) for j, ks in table.items() if len(ks) == 1}
    by_len = sorted(single, key=len, reverse=True)
    for mid, m in msgs.items():
        if m.get("style") == 13:
            continue
        jp = re.sub(r"\s+", "", vis(m["src"]))
        ko = re.sub(r"\s+", "", vis(tr[mid]))
        used = set()
        for j in by_len:
            if j in jp and not any(j in u for u in used) and MK._word_in(j, jp):
                used.add(j)
                if single[j].replace(" ", "") not in ko:
                    add("names", mid, f"name {j} = '{single[j]}' not found", msgs, tr, *ctx)
                    n += 1
    return n


def c_oldname(msgs, tr, *ctx):
    n = 0
    for mid, m in msgs.items():
        ko = vis(tr[mid])
        jp = m["src"]
        hits = []
        if "수림" in ko:
            hits.append("수림 (old name of スーリム, now 슬림)")
        if "무지오" in ko:
            hits.append("무지오 (old name of ムチオ, now 마초)")
        if "リューギー" in jp and "용기" in ko:
            hits.append("용기 (old name of リューギー, now 러기)")
        for rx, why in ((r"쿠파\s?Jr|Jr\.", "Jr. spelling"), (r"쿠파 주니어", "쿠파 주니어 (glossary 쿠파주니어)"),
                        (r"피치 공주", "피치 공주 (glossary 피치공주)"), (r"키노 영감", "키노 영감 (glossary 키노영감)"),
                        (r"(마리오|루이지|쿠파|까르코비츠|키노영감|피치공주|메타보스|러즐|드르렁|차크란|슬림) 님(?![가-힣])", "이름 + 님 spaced"),
                        (r"쿠파 씨|슬림 씨", "이름 + 씨 spaced (DS: 쿠파씨)")):
            for mm in re.finditer(rx, ko):
                hits.append(f"{why}: '{ko[max(0, mm.start() - 5):mm.end() + 5]}'")
        for h in dict.fromkeys(hits):
            add("oldname", mid, h, msgs, tr, *ctx)
            n += 1
    return n


def c_latin(msgs, tr, *ctx):
    inv = collections.Counter()
    where = collections.defaultdict(list)
    for mid, t in tr.items():
        for w in re.findall(r"[A-Za-z][A-Za-z.!?'&-]*", PH.sub("", t).replace("[Next]", " ")):
            inv[w] += 1
            if len(where[w]) < 3:
                where[w].append(mid)
    for w, c in inv.most_common():
        ROWS.append({"check": "latin", "sev": "info", "id": ",".join(where[w]), "label": "", "style": "", "batch": "",
                     "cat": "", "jp": "", "ko": w, "detail": f"x{c}"})
    return len(inv)


def sample(msgs, tr, tri, k=240, seed=20261031):
    """stratified random sample of new / edited messages for a human meaning check."""
    rnd = random.Random(seed)
    pool = collections.defaultdict(list)
    for mid, m in msgs.items():
        c = tri.get(mid)
        if c in ("new", "edited") and len(nospace(m["src"])) >= 12:
            pool[mid.split("/")[0].split("#")[0]].append(mid)
    total = sum(len(v) for v in pool.values())
    out = []
    for src, ids in sorted(pool.items()):
        take = max(4, round(k * len(ids) / total))
        out += rnd.sample(ids, min(take, len(ids)))
    lines = []
    for i, mid in enumerate(out, 1):
        m = msgs[mid]
        lines.append(f"#{i} {mid} [{m.get('label', '')}] ({tri.get(mid)})\nJP: {flat(m['src'])}\nKO: {flat(tr[mid])}\n")
    (HERE / "sample.txt").write_text("\n".join(lines), encoding="utf-8")
    return len(out)


def main():
    msgs, tr, batch_of, tri, gloss = load()
    ctx = (batch_of, tri)
    counts = {}
    counts["samejp"] = c_samejp(msgs, tr, *ctx)
    counts["glossary"] = c_glossary(msgs, tr, *ctx)
    counts["space"] = c_space(msgs, tr, *ctx)
    counts["glossvar"] = c_glossvar(msgs, tr, gloss, *ctx)
    counts["particle"] = c_particle(msgs, tr, gloss, *ctx)
    counts["punct"] = c_punct(msgs, tr, *ctx)
    counts["spell"] = c_spell(msgs, tr, *ctx)
    counts["number"] = c_number(msgs, tr, *ctx)
    counts["length"] = c_length(msgs, tr, *ctx)
    counts["voice"] = c_voice(msgs, tr, *ctx)
    counts["choice"] = c_choice(msgs, tr, *ctx)
    counts["names"] = c_names(msgs, tr, *ctx)
    counts["oldname"] = c_oldname(msgs, tr, *ctx)
    counts["latin"] = c_latin(msgs, tr, *ctx)
    counts["sample"] = sample(msgs, tr, tri)
    cols = ["check", "sev", "id", "label", "style", "batch", "cat", "detail", "jp", "ko"]
    with open(HERE / "findings.tsv", "w", encoding="utf-8", newline="") as f:
        w = csv.DictWriter(f, fieldnames=cols, delimiter="\t", extrasaction="ignore")
        w.writeheader()
        for r in ROWS:
            w.writerow({k: str(v).replace("\t", " ").replace("\n", "/") for k, v in r.items()})
    by = collections.Counter(r["check"] for r in ROWS)
    lines = ["# final audit summary", "", f"messages: {len(msgs)} representatives", "",
             "| check | groups / hits | rows |", "|---|---|---|"]
    for k, v in counts.items():
        lines.append(f"| {k} | {v} | {by.get(k, 0)} |")
    (HERE / "summary.md").write_text("\n".join(lines) + "\n", encoding="utf-8")
    print("\n".join(lines))


if __name__ == "__main__":
    main()
