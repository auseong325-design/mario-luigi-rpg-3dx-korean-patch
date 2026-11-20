import json, re, difflib, sys
sys.path.insert(0, str(__import__('pathlib').Path(__file__).resolve().parents[4] / 'scripts'))
from review_triage import parse_refs
from corpus import *
tri = json.load(open(ROOT/'work/review/triage.json'))['batches']
jp = jp_msgs(); ko = ko_final()
# DS text by key, per batch
cache = {}
def refs_of(bid):
    b = json.load(open(ROOT/f'work/batches/{bid}.json'))
    refs = b.get('ds_reference') or []
    if refs and refs[0].startswith('@file'):
        rel = refs[0].split(None, 1)[1].strip().split()[0]
        if rel not in cache: cache[rel] = dict(parse_refs((ROOT/rel).read_text(encoding='utf-8').splitlines()))
        return cache[rel]
    lines = []
    for r in refs: lines += r.split('\n')
    return dict(parse_refs(lines))
def flat(t): return re.sub(r'\s+', ' ', re.sub(r'\{\d+:\w+\}', '', t).replace('[Next]', ' ')).strip()
out = []
for bid, d in tri.items():
    tr = json.load(open(ROOT/f'text/ko/{bid}.json'))['translations']
    R = None
    for mid, (cls, cov, key) in d['msgs'].items():
        if cls not in ('edited', 'ds') or not key: continue
        if R is None: R = refs_of(bid)
        a, b = flat(tr[mid]), flat(R.get(key, ''))
        a2, b2 = re.sub(r'[\s]', '', a), re.sub(r'[\s]', '', b)
        if a2 == b2 or a2 in b2: continue
        sm = difflib.SequenceMatcher(None, b2, a2)
        ops = [(t, b2[i1:i2], a2[j1:j2]) for t, i1, i2, j1, j2 in sm.get_opcodes() if t != 'equal']
        changed = sum(max(len(x[1]), len(x[2])) for x in ops)
        out.append((cls, cov, changed, mid, key, ops))
json.dump(out, open('edited.json', 'w'), ensure_ascii=False)
small = [o for o in out if o[2] <= 6 and o[0] == 'ds']
print('ds-class with any diff:', sum(1 for o in out if o[0]=='ds'), ' edited:', sum(1 for o in out if o[0]=='edited'), ' ds-class small diffs (<=6 chars):', len(small))
for cls, cov, ch, mid, key, ops in sorted(small, key=lambda o: o[3])[:400]:
    print(f'{mid} [{key}] ' + ' ; '.join(f'{t}:{x!r}->{y!r}' for t, x, y in ops)[:200])
