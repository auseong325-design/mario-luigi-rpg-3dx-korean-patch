import json,pathlib,re,difflib,csv
ROOT=pathlib.Path(__file__).resolve().parents[3]
OUT=pathlib.Path(__file__).resolve().parent
def visit(data,ref):
    if isinstance(data,list):
        for n,x in enumerate(data): yield from visit(x,ref+f':{n}')
    elif isinstance(data,dict):
        if 'ko' in data: yield ref, data['ko']
        elif 'messages' in data:
            for n,x in enumerate(data['messages']): yield from visit(x,ref+f"#{x.get('i',n)}")
        else:
            for k,x in data.items(): yield from visit(x,ref+'/'+k)
def norm(s):
    s=re.sub(r'\{\d+:[^}]+\}|\[Next\]|\[[^\]]*\]','',s)
    s=re.sub(r'[ⒶⒷⓍⓎⓁⓇ①-⑨][)\]]?','@',s)
    s=re.sub(r'\s+','',s)
    return s
ds=[]
for p in sorted((ROOT/'text/ref_ds_ko').glob('*.json')):
    if p.stem.startswith('FEvent'): continue
    ds += list(visit(json.loads(p.read_text(encoding='utf-8')),p.stem))
(OUT/'ds_nonfield_read.txt').write_text('\n'.join(f'{ref}: {s}' for ref,s in ds),encoding='utf-8')
rows=json.loads((OUT/'menu_item_rows.json').read_text(encoding='utf-8'))
norms=[norm(s) for _,s in ds]
out=[]
counts={}
for r in rows:
    n=norm(r['ko'])
    if len(n)<10: continue
    scores=[difflib.SequenceMatcher(None,n,d,autojunk=False).ratio() for d in norms]
    ix=max(range(len(scores)),key=scores.__getitem__)
    sc=scores[ix]
    counts[r['batch']]=counts.get(r['batch'],0)+int(sc==1)
    if .70<=sc<1:
        out.append({**r,'ds_ref':ds[ix][0],'ds_ko':ds[ix][1],'score':round(sc,3)})
(OUT/'ds_candidates.json').write_text(json.dumps(out,ensure_ascii=False,indent=2),encoding='utf-8')
for b in sorted(set(r['batch'] for r in rows)):
    lines=[]
    for r in out:
        if r['batch']!=b:continue
        lines += [f"{r['id']} {r['label']} score={r['score']} <- {r['ds_ref']}",'JP '+r['src'].replace('\n',' / '),'KO '+r['ko'].replace('\n',' / '),'DS '+r['ds_ko'].replace('\n',' / ')]
    (OUT/(b+'_ds.txt')).write_text('\n'.join(lines),encoding='utf-8')
print('DS nonfield',len(ds),'exact normalized',counts,'candidates',len(out))
