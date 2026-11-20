import csv, difflib, json, re, sys
from pathlib import Path
from kj_battle_audit import ROOT, OUT, rows, plain

sys.path.insert(0, str(ROOT / 'scripts'))
from review_triage import parse_refs, norm, RefIndex

refs = parse_refs((ROOT/'work/batches/_refs_BMsg.txt').read_text(encoding='utf-8').splitlines())
idx = RefIndex(refs)
refdict = dict(refs)
matches = []
for r in rows():
    if not r['id'].startswith('BMsg/'):
        continue
    normalized = norm(r['ko'])
    if len(normalized) < 6:
        continue
    coverage, key = idx.best(normalized)
    if coverage < .55:
        continue
    r = dict(r)
    r['ds_key'], r['ds_ko'], r['coverage'] = key, refdict[key], round(coverage, 3)
    r['ratio'] = round(difflib.SequenceMatcher(None, normalized, norm(refdict[key])).ratio(), 3)
    matches.append(r)
matches.sort(key=lambda r:int(r['id'].split('#')[1]))
with (OUT/'kj_battle_ds_pairs.tsv').open('w', encoding='utf-8', newline='') as f:
    w = csv.DictWriter(f, fieldnames=list(matches[0]), delimiter='\t')
    w.writeheader(); w.writerows(matches)
print(f'candidate rows: {len(matches)}')
for r in matches[int(sys.argv[1]):int(sys.argv[2])]:
    print(r['id']+' '+r['label']+' cov='+str(r['coverage'])+' ratio='+str(r['ratio']))
    print('JP '+plain(r['src']))
    print('KO '+plain(r['ko']))
    print('DS '+r['ds_key']+' '+plain(r['ds_ko']))
    if r['note']:
        print('note '+r['note'])
