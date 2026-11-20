import json, pathlib, re, csv, difflib

ROOT = pathlib.Path(__file__).resolve().parents[3]
OUT = pathlib.Path(__file__).resolve().parent
PREFIXES = ('Item', 'Menu', 'MenuKJ', 'HugeBattle', 'InitLoad')
rows = []
for path in sorted((ROOT/'work/batches').glob('*.json')):
    if path.stem.split('__')[0] not in PREFIXES:
        continue
    batch = json.loads(path.read_text(encoding='utf-8'))
    ko = json.loads((ROOT/'text/ko'/path.name).read_text(encoding='utf-8'))
    for m in batch['messages']:
        rows.append(dict(batch=path.stem, id=m['id'], label=m.get('label',''), src=m['src'], ko=ko['translations'].get(m['id'],''), notes=ko.get('notes',{}).get(m['id'],''), dups=m.get('dups',[])))
    lines = []
    for r in rows:
        if r['batch'] != path.stem:
            continue
        lines += [f"{r['id']} {r['label']} dups={len(r['dups'])}", 'JP '+r['src'].replace('\n',' / '), 'KO '+r['ko'].replace('\n',' / ')]
        if r['notes']:
            lines.append('NOTE '+r['notes'])
    (OUT/(path.stem+'_read.txt')).write_text('\n'.join(lines)+'\n',encoding='utf-8')
(OUT/'menu_item_rows.json').write_text(json.dumps(rows,ensure_ascii=False,indent=2),encoding='utf-8')
print({p:sum(r['batch'].split('__')[0]==p for r in rows) for p in PREFIXES})
print('canonical',len(rows),'duplicates',sum(len(r['dups']) for r in rows))
