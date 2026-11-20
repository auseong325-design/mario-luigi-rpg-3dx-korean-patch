"""Restore verified DS spacing while retaining every 3DX control tag."""
from pathlib import Path
import json
ROOT=Path(__file__).resolve().parents[3]
OUT=Path(__file__).resolve().parent
spec={
 'FMsg/o_ekubon_02#0': [('↑숲','↑ 숲'),('↓이아파','↓ 이아파')],
 'FMsg/o_ekubon_04_1#1': [('↑숲','↑ 숲')],
 'FMsg/o_ekubon_04_2#0': [('→숲','→ 숲')],
 'FMsg/o_gepu_11#0': [('↑고라파','↑ 고라파'),('→이아파','→ 이아파')],
 'FMsg/o_koopa_13_2#57': [('{1:pause} 라고','{1:pause}라고')],
 'FMsg/o_peach_1f_03#41': [('{3:pause} 이다','{3:pause}이다')],
 'FMsg/o_peach_1f_08#9': [('{4:pause} 솔직히','{4:pause}솔직히')],
 'FMsg/o_zutsuda_15#15': [('{5:pause} 아!','{5:pause}아!'),('{10:pause} 에헴','{10:pause}에헴')],
}
sources={'FMsg/o_ekubon_02#0':'DS046#0',
 'FMsg/o_ekubon_04_1#1':'DS047#0','FMsg/o_ekubon_04_2#0':'DS178#0',
 'FMsg/o_gepu_11#0':'DS20C#0','FMsg/o_koopa_13_2#57':'DS0D1#53',
 'FMsg/o_peach_1f_03#41':'DS20F#2','FMsg/o_peach_1f_08#9':'DS298#8',
 'FMsg/o_zutsuda_15#15':'DS108#30'}
changes=[]
backup=OUT/'ds_spacing_backup';backup.mkdir(exist_ok=True)
for p in sorted((ROOT/'text/ko').glob('*.json')):
    d=json.loads(p.read_text(encoding='utf-8-sig'))
    hits=set(spec)&d.get('translations',{}).keys()
    if not hits: continue
    assert not (backup/p.name).exists(), 'Run once only'
    (backup/p.name).write_bytes(p.read_bytes())
    for mid in sorted(hits):
        old=d['translations'][mid];new=old
        for a,b in spec[mid]:
            assert new.count(a)==1,(mid,a)
            new=new.replace(a,b,1)
        reason=f"review: 2026-10-06 {sources[mid]}의 같은 뜻 대사 띄어쓰기 복원. 화살표 뒤/말줄임표 뒤 공백과 어절을 DS대로 유지하고 3DX pause·서식·페이지 태그는 그대로 둠. AGENTS 0·4.6의 DS 보존 원칙이 일반 스타일 권고보다 우선."
        note=d.setdefault('notes',{}).get(mid,'')
        d['notes'][mid]=reason+(' | 이전 검토 메모(띄어쓰기 판정은 이번 검토로 대체): '+note if note else '')
        d['translations'][mid]=new
        changes.append({'batch':p.stem,'id':mid,'before':old,'after':new,'reason':reason})
    p.write_text(json.dumps(d,ensure_ascii=False,indent=1)+'\n',encoding='utf8',newline='')
assert len(changes)==8,len(changes)
(OUT/'ds_spacing_changes.json').write_text(json.dumps(changes,ensure_ascii=False,indent=2),encoding='utf8')
print(f'{len(changes)} verified DS spacing restorations applied')
