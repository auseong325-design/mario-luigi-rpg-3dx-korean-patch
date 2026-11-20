import csv, json
from kj_battle_audit import ROOT, OUT, rows, plain

owned = {r['id'] for r in rows()}
expanded_owned = {mid for r in rows() for mid in [r['id'], *r['dups']]}
originals = {}
for p in (ROOT/'text/jp').glob('*.json'):
    if not(p.name.startswith('FMsg__k') or p.name == 'BMsg__b_sys.json'):
        continue
    for m in json.loads(p.read_text(encoding='utf-8'))['messages']:
        originals[m['id']] = m
translations = {}
canonical = {}
for p in (ROOT/'work/batches').glob('*.json'):
    b = json.loads(p.read_text(encoding='utf-8'))
    if not isinstance(b, dict) or 'messages' not in b:
        continue
    k = json.loads((ROOT/'text/ko'/p.name).read_text(encoding='utf-8'))
    for m in b['messages']:
        for mid in [m['id'], *m.get('dups', [])]:
            translations[mid] = k['translations'].get(m['id'], '')
            canonical[mid] = (b['batch'], m)
overrides = json.loads((ROOT/'text/ko/_dup_overrides.json').read_text(encoding='utf-8'))['translations']
missing = []
empty = []
for mid in sorted(set(originals)-expanded_owned):
    if mid not in canonical:
        empty.append(mid)
        print('not batched', mid, repr(originals[mid]['jp']))
        continue
    bid, m = canonical[mid]
    missing.append(dict(id=mid, batch=bid, canonical=m['id'], label=originals[mid]['label'],
                        src=m['src'], ko=overrides.get(mid, translations[mid])))
with (OUT/'kj_battle_external_copies.tsv').open('w',encoding='utf-8',newline='') as f:
    w = csv.DictWriter(f, fieldnames=['id','batch','canonical','label','src','ko'],delimiter='\t')
    w.writeheader(); w.writerows(missing)
print('original_instances', len(originals), 'owned_expanded', len(set(originals)&expanded_owned), 'external_canonical', len(missing), 'empty',len(empty))
for r in missing:
    print(r['id']+' ← '+r['canonical']+' ('+r['batch']+')')
    print(plain(r['src'])+' ⇒ '+plain(r['ko']))
print('override review')
for mid, text in overrides.items():
    if mid in originals:
        print(mid+' '+plain(text))
