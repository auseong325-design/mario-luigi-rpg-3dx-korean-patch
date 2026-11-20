import csv
import json
import re
from collections import defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
OUT = Path(__file__).resolve().parent
rows = json.loads((OUT / 'menu_item_rows.json').read_text(encoding='utf-8'))
by_label = defaultdict(list)
with (ROOT / 'work/ref_1dx_ko.tsv').open(encoding='utf-8', newline='') as stream:
    for row in csv.DictReader(stream, delimiter='\t'):
        by_label[row['label']].append(row)

def plain(text):
    text = re.sub(r'\[Ruby ([^;\]]*);[^\]]*\]', r'\1', text)
    return re.sub(r'\[[^\]]*\]|\{\d+:[^}]*\}', '', text).replace('\\n', ' / ').replace('\n', ' / ')

results = []
for row in rows:
    labels = [row['label']]
    if row['label'].startswith('Menu_KJ_Chr_'):
        labels.append(row['label'].replace('Menu_KJ_Chr_', 'KMsgChr_', 1))
    if row['label'].startswith('Menu_KJ_'):
        labels.extend(row['label'].replace('Menu_KJ_', p, 1) for p in ('KMsg_', 'KMsgMenu_'))
    current = json.loads((ROOT / 'text/ko' / (row['batch'] + '.json')).read_text(encoding='utf-8'))['translations'][row['id']]
    seen = set()
    for label in labels:
        for ref in by_label.get(label, []):
            text = plain(ref['text'])
            if text in seen:
                continue
            seen.add(text)
            results.append(dict(batch=row['batch'], id=row['id'], label=row['label'], jp=plain(row['src']), ko=plain(current), ref=ref['key'] + '#' + ref['index'], ref_label=label, ref_ko=text))
with (OUT / 'menu_item_1dx.tsv').open('w', encoding='utf-8-sig', newline='') as stream:
    writer = csv.DictWriter(stream, fieldnames=['batch', 'id', 'label', 'jp', 'ko', 'ref', 'ref_label', 'ref_ko'], delimiter='\t')
    writer.writeheader()
    writer.writerows(results)
for family in ('Item', 'Menu', 'MenuKJ', 'HugeBattle', 'InitLoad'):
    selected = [r for r in results if r['batch'].split('__')[0] == family]
    (OUT / (family + '_1dx_read.txt')).write_text('\n'.join('\n'.join([r['id'] + ' ' + r['label'] + ' <- ' + r['ref'], 'JP ' + r['jp'], 'KO ' + r['ko'], '1DX ' + r['ref_ko']]) for r in selected), encoding='utf-8')
    print(family, len(selected), 'pairs for', len({r['id'] for r in selected}), 'messages')
print('Total', len(results), 'pairs', len({r['id'] for r in results}), 'messages')
