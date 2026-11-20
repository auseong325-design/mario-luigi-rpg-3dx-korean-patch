import json,re,subprocess,sys,shutil
from pathlib import Path

ROOT=Path(__file__).resolve().parents[3]
OUT=ROOT/'work/review/audit_20261006'
changes={
 'FMsg/i_energy_11#0':('「부끄부끄해도 될까요?」','부끄부끄해도 될까요?','DS0BD#0의 노래 제목 따옴표 없음 복원. 뜻이 같은 DS 번역의 문장부호 보존(AGENTS 0·4.6); 페이지 수와 태그 유지.'),
 'FMsg/i_metaboru_19#6':('앗! 혹시 지금…','앗! 혹시 지금','DS0B8#6의 동일 문구에 없던 말줄임표 제거. 3DX 페이지 분할·태그는 유지하면서 DS 문장부호 보존.'),
 'FMsg/o_ekubon_06#0':('발사 다이어트{42:color}{43:color}!!','발사 다이어트{42:color}{43:color}!','DS053#0과 뜻이 같은 마지막 문장의 느낌표를 DS대로 한 개로 복원.'),
 'FMsg/o_ekubon_07_1#0':('시간문제지롱롱롱!!','시간문제지롱롱롱!','DS048#37과 뜻이 같은 문장의 느낌표를 DS대로 한 개로 복원. 뜸 태그 유지.'),
 'FMsg/o_ekubon_07_1#7':('뭐라고!','뭐라고?','DS048#13의 동일 발화 문장부호 복원. 뜸 태그 유지.'),
 'FMsg/o_ekubon_07_1#12':('그러니까 마리오에게 매번 지지!!','그러니까 마리오에게 매번 지지!','DS048#18과 뜻이 같은 문장의 느낌표를 DS대로 한 개로 복원.'),
 'FMsg/o_ekubon_07_1#30':('놀고 있을 땐 줄 아느냐!?','놀고 있을 땐 줄 아느냐?','DS048#7의 동일 질문 문장부호 복원.'),
 'FMsg/o_koopa_13_1#6':('그럼!{6:pause}','그럼{6:pause}','DS041#13과 뜻이 같은 문구에 추가된 느낌표 제거. 3DX 뜸 태그 유지.'),
 'FMsg/o_mushiba_05_before#26':('땡큐!{2:pause}','땡큐{2:pause}','DS03E#20의 땡큐 베리 머치 문장부호 복원. 3DX 뜸 태그 유지.'),
}
rows=json.loads((OUT/'ds_field_rows.json').read_text(encoding='utf-8'))
shutil.copyfile(OUT/'ds_field_rows.json', OUT/'ds_field_before_rows.json')
changed=[]
for b in sorted({r['batch'] for r in rows if r['id'] in changes}):
 p=ROOT/'text/ko'/f'{b}.json'
 obj=json.loads(p.read_text(encoding='utf-8-sig'))
 backup=OUT/'ds_field_backup';backup.mkdir(exist_ok=True)
 shutil.copyfile(p,backup/p.name)
 for key,(old,new,note) in changes.items():
  if key not in obj['translations']:continue
  before=obj['translations'][key]
  assert before.count(old)==1,(key,old)
  after=before.replace(old,new)
  obj['translations'][key]=after
  prior=obj.setdefault('notes',{}).get(key,'')
  obj['notes'][key]='review: 2026-10-06 '+note+(' | 기존 메모: '+prior if prior else '')
  changed.append({'batch':b,'id':key,'before':before,'after':after,'reason':note})
 p.write_text(json.dumps(obj,ensure_ascii=False,indent=1)+'\n',encoding='utf-8')
(OUT/'ds_field_changes.json').write_text(json.dumps(changed,ensure_ascii=False,indent=1),encoding='utf-8')
print(f'changed {len(changed)} messages in {len(set(c["batch"] for c in changed))} batches')
for b in sorted(set(c['batch'] for c in changed)):
 proc=subprocess.run([sys.executable,'-X','utf8',str(ROOT/'scripts/merge_ko.py'),'--check',b],cwd=ROOT,text=True,encoding='utf-8',capture_output=True,timeout=120)
 (OUT/f'ds_check_{b}.log').write_text(proc.stdout+'\n'+proc.stderr,encoding='utf-8')
 print(b,proc.returncode,proc.stdout.splitlines()[-1:] if proc.stdout else proc.stderr[-200:])
 assert proc.returncode==0,b
