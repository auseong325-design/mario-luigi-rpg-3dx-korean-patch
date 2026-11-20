"""Apply the user's SS Company names without regenerating translation batches."""
from pathlib import Path
import csv, io, json, shutil
ROOT=Path(__file__).resolve().parents[3]
OUT=Path(__file__).resolve().parent
BACKUP=OUT/'before_ss_names'
REPLACE={'수림':'슬림','무지오':'마초'}
TERMS={'スーリム':'슬림','キュット':'큐티','ムチオ':'마초','スーさん':'슬림씨'}
NOTE='review: 2026-10-07 사용자 확정 SS컴퍼니 이름 슬림·큐티·마초 반영. 애칭 スーさん은 DS 호칭 관례대로 슬림씨.'
def swap(v):
    if isinstance(v,str):
        for old,new in REPLACE.items():v=v.replace(old,new)
        return v
    if isinstance(v,list):return [swap(x) for x in v]
    if isinstance(v,dict):return {k:swap(x) for k,x in v.items()}
    return v
def backup(p):
    dst=BACKUP/p.relative_to(ROOT)
    dst.parent.mkdir(parents=True,exist_ok=True)
    assert not dst.exists(),dst
    shutil.copy2(p,dst)
def write(p,data):
    p.write_text(json.dumps(data,ensure_ascii=False,indent=2)+'\n',encoding='utf8')

changes=[]
for p in sorted((ROOT/'text/ko').glob('*.json')):
    old=json.loads(p.read_text(encoding='utf-8-sig'));new=swap(old)
    for mid,before in old.get('translations',{}).items():
        after=new['translations'][mid]
        if before!=after:
            changes.append({'batch':p.stem,'id':mid,'before':before,'after':after})
            prev=new.setdefault('notes',{}).get(mid,'')
            new['notes'][mid]=(prev+' '+NOTE).strip()
    for term in new.get('new_terms',[]) or []:
        if term.get('jp') in TERMS:
            term.update(ko=TERMS[term['jp']],basis='coined',note='2026-10-07 사용자 확정 표기. '+('애칭은 슬림씨.' if term['jp']=='スーさん' else 'SS컴퍼니 인물.'))
    if p.stem=='FMsg__k_o_ekubon_80__p1':
        mid='FMsg/k_o_ekubon_80#21'
        before=old['translations'][mid]
        new['translations'][mid]='마초는?{1:pause}\n마…{2:pause}마…{3:pause}몰라…{4:wait}'
        new['notes'][mid]=NOTE+' 이름의 말머리 반복과 無知(모름)를 연결하는 장면. 새 이름의 말머리 마…를 반복한 뒤 몰라…로 받아 다음 루드윅의 무지는 죄라네(#90)에 이어지게 한다. 화자를 새로 단정하지 않는다.'
        next(row for row in changes if row['id']==mid)['after']=new['translations'][mid]
    if new!=old:backup(p);write(p,new)

cols=['jp','ko','type','basis','source','note']
overrides=[]
for name in ['glossary.tsv','glossary_overrides.tsv']:
    p=ROOT/'text'/name
    rows=list(csv.DictReader(io.StringIO(p.read_text(encoding='utf-8-sig')),delimiter='\t'))
    byjp={row['jp']:row for row in rows}
    for jp,ko in TERMS.items():
        if jp not in byjp:
            byjp[jp]={'jp':jp,'type':'character' if jp=='スーさん' else 'boss'}
            rows.append(byjp[jp])
        byjp[jp].update(ko=ko,basis='coined',source='2026-10-07 사용자 확정',note='사용자 지정 SS컴퍼니 표기. '+('슬림의 애칭. DS 관례대로 씨를 붙여 쓴다.' if jp=='スーさん' else '이 표기가 이전 임시 이름보다 우선한다.'))
    backup(p)
    with p.open('w',encoding='utf8',newline='') as f:
        w=csv.DictWriter(f,fieldnames=cols,delimiter='\t',lineterminator='\n');w.writeheader();w.writerows(rows)

p=ROOT/'text/style_guide.md';before=p.read_text(encoding='utf8');after=swap(before)
after=after.replace('큐티(キュートー)','큐티(キュット)')
assert before!=after
backup(p);p.write_text(after,encoding='utf8')
batchcount=0
for p in sorted((ROOT/'work/batches').glob('*.json')):
    if p.name.startswith('_'):continue
    old=json.loads(p.read_text(encoding='utf-8-sig'));new=dict(old)
    new['glossary']=swap(old.get('glossary',[]))
    if new!=old:backup(p);write(p,new);batchcount+=1
result={'translation_changes':changes,'representatives':len(changes),'batch_metadata_files':batchcount,'new_names':TERMS}
write(OUT/'ss_name_changes.json',result)
print(json.dumps({'representatives':len(changes),'batch_metadata_files':batchcount,'names':TERMS},ensure_ascii=False))
