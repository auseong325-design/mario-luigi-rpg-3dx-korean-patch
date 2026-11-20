import json,re,csv,difflib
from pathlib import Path
from collections import Counter,defaultdict

ROOT=Path(__file__).resolve().parents[3]
OUT=ROOT/'work/review/followup_20261007'
OUT.mkdir(parents=True,exist_ok=True)
ds=json.loads((ROOT/'text/ref_ds_ko/FEvent.json').read_text(encoding='utf-8-sig'))
room={r['room']:[(f"DS{r['room']}#{m['i']}",m['ko']) for m in r['messages']] for r in ds}
mapping=json.loads((ROOT/'text/align/room_map.json').read_text(encoding='utf-8-sig'))
def clean(s):
    return re.sub(r'\{[^}]*\}', '', s).replace('[Next]','\n').strip()
def norm(s):
    return re.sub(r'\s+','',clean(s))
def slim(s):
    return re.sub(r'[\s.,!?~…·―\-「」()\[\]\'"♪♥★☆]+','',clean(s))
def txt(s):
    return clean(s).replace('\n',' / ')
global_exact={norm(t):(k,t) for entries in room.values() for k,t in entries}
rows=[]
files=[]
for path in sorted((ROOT/'text/ko').glob('FMsg__*.json')):
    if not (path.stem.startswith(('FMsg__i_','FMsg__o_','FMsg__ev_','FMsg__cs_','FMsg__minimap_')) or path.stem=='FMsg__fcommon'): continue
    obj=json.loads(path.read_text(encoding='utf-8-sig'))
    batch=json.loads((ROOT/'work/batches'/path.name).read_text(encoding='utf-8-sig'))
    files.append(path.stem)
    refs=[x for rid in batch.get('ds_rooms',[]) for x in room.get(rid,[])]
    for entry in batch.get('ds_reference',[]):
        mt=re.match(r'^(DS[^\n]+?#[\w.]+):\s?(.*)',entry,re.S)
        if mt:refs.append((mt[1],mt[2]))
    refs=list(dict.fromkeys(refs))
    exact_index={norm(t):(k,t) for k,t in refs}
    indexed={slim(t):(k,t) for k,t in refs}
    for msg in batch['messages']:
        key=msg['id'];ko=obj['translations'][key];n=slim(ko)
        if norm(ko) in exact_index:
            dk,dt=exact_index[norm(ko)];score=1.0
        elif norm(ko) in global_exact:
            dk,dt=global_exact[norm(ko)];score=1.0
        elif n and n in indexed:
            dk,dt=indexed[n];score=1.0
        elif refs:
            score,dk,dt=max((difflib.SequenceMatcher(None,n,slim(t),autojunk=False).ratio(),k,t) for k,t in refs)
        else:score,dk,dt=0.0,'',''
        exact=norm(ko)==norm(dt)
        rows.append({'batch':path.stem,'id':key,'src':msg['src'],'ko':ko,'ds_key':dk,'ds':dt,'score':round(score,3),'exact':exact,'dups':msg.get('dups',[]),'note':obj.get('notes',{}).get(key,'')})
(OUT/'ds_field_rows.json').write_text(json.dumps(rows,ensure_ascii=False,indent=1),encoding='utf-8')
with (OUT/'ds_field_candidates.tsv').open('w',encoding='utf-8-sig',newline='') as f:
    w=csv.writer(f,delimiter='\t');w.writerow(['batch','id','score','jp','ko','ds_key','ds','note'])
    for r in rows:
        if not r['exact']: w.writerow([r['batch'],r['id'],r['score'],txt(r['src']),txt(r['ko']),r['ds_key'],txt(r['ds']),r['note']])
with (OUT/'ds_field_digest.txt').open('w',encoding='utf-8') as f:
    for idx,r in enumerate(rows):
        f.write(f"[{idx}] {r['id']} ({r['score']} {'DSexact' if r['exact'] else 'DIFF'})\nJP {txt(r['src'])}\nKO {txt(r['ko'])}\n")
        if not r['exact']:f.write(f"DS {r['ds_key']} {txt(r['ds'])}\nNOTE {r['note']}\n")
print(json.dumps({'batches':len(files),'messages':len(rows),'dups':sum(len(r['dups']) for r in rows),'exact':sum(r['exact'] for r in rows),'diffs':sum(not r['exact'] for r in rows)},ensure_ascii=False))
print(json.dumps({name:sum(r['batch']==name for r in rows) for name in files},ensure_ascii=False))

