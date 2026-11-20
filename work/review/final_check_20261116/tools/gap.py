import json, re, sys
sys.path.insert(0, str(__import__('pathlib').Path(__file__).resolve().parents[4] / 'scripts'))
from review_triage import norm, bigrams, parse_refs
from corpus import *
idx = json.load(open(ROOT/'work/batches/_index.json'))
tri = json.load(open(ROOT/'work/review/triage.json'))['batches']
out = []
tot_unused = 0
for e in idx:
    bid = e['batch']
    if not bid.startswith('FMsg'): continue
    b = json.load(open(ROOT/f'work/batches/{bid}.json'))
    tr = json.load(open(ROOT/f'text/ko/{bid}.json'))['translations']
    refs = b.get('ds_reference') or []
    if not refs or refs[0].startswith('@file'): continue
    lines = []
    for r in refs: lines += r.split('\n')
    ents = parse_refs(lines)
    kos = {m['id']: norm(tr[m['id']]) for m in b['messages']}
    kog = {k: bigrams(v) for k, v in kos.items()}
    for key, text in ents:
        t = norm(text)
        g = bigrams(t)
        if len(g) < 8: continue
        best, bid2 = 0, None
        for k, kg in kog.items():
            if not kg: continue
            c = len(g & kg) / len(g)
            if c > best: best, bid2 = c, k
        if best < 0.5:
            tot_unused += 1
            out.append((bid, key, round(best, 2), bid2, text))
print('unused DS entries (>=8 bigrams, best single-KO coverage < 0.5):', tot_unused)
json.dump(out, open('gap.json', 'w'), ensure_ascii=False, indent=0)
import collections
c = collections.Counter(o[0] for o in out)
for k, v in c.most_common(): print(v, k)
