import csv, json, re, subprocess
from pathlib import Path
from kj_speech_helper import ROOT, OUT, ownrows

IGGY = "review: 2026-10-07 사용자 공식 한국어 말투 지침에 따라 이기의 1인칭을 나/내로 교정. 1DX KR FMsg:krpg_gera_02 krpg_gera_qst7_8 '난 강하다구~', qst7_17 '아~ 그런 거야? / 아하하하~'가 근거. 이전 임의 결정 '나님'을 대체한다. 3DX ボクチャン의 유아적 느낌은 기존 태평한 말투·유행어로 살린다."
CHANGES = {
    'BMsg/b_sys#1165': ('나님이','내가',IGGY),
    'FMsg/k_o_ekubon_80#106': ('나님도','나도',IGGY),
    'FMsg/k_o_mushiba_07#0': ('나님은 누구?','나는 누구?',"화자 러즐(リューグー). 초면인 쿠파주니어·마귀에게는 하게체, 손주로 여기는 이기·큐티에게는 해라체. 이기의 자기소개를 인용한 부분도 나/내로 맞춘다. "+IGGY),
    'FMsg/k_o_mushiba_16#38': ('나님은','나는',IGGY),
    'FMsg/k_o_mushiba_16#52': ('나님은','나는',IGGY),
    'FMsg/k_o_mushiba_16#61': ('나님 기억이','나 기억이',IGGY),
    'FMsg/k_o_mushiba_80#44': ('나님은','나는',IGGY),
    'BMsg/b_sys#1604': ('키킥,','케케,',"review: 2026-10-07 공식 한국어 말투 대조. 1DX KR FMsg:krpg_gera_00#109 krpg_gera_qst6_10에서 레미가 '케케케'라고 웃는다고 직접 명시한다. ケケッ은 그 짧은 형태로 '케케'로 맞춤. 기존 '키킥' 제안은 대체한다."),
}

def main():
    rows={r['id']:r for r in ownrows()}
    files={}
    records=[]
    for mid,(before,after,note) in CHANGES.items():
        r=rows[mid]
        p=ROOT/'text/ko'/(r['batch']+'.json')
        if p not in files:
            raw=p.read_text(encoding='utf-8')
            files[p]={'raw':raw,'data':json.loads(raw),'mods':[]}
        f=files[p]
        old=f['data']['translations'][mid]
        assert before in old, (mid,old)
        new=old.replace(before,after)
        f['mods'].append((old,new))
        f['data']['translations'][mid]=new
        oldnote=f['data'].setdefault('notes',{}).get(mid,'')
        if mid in ('FMsg/k_o_ekubon_80#106','FMsg/k_o_mushiba_07#0','BMsg/b_sys#1604'):
            f['data']['notes'][mid]=note
        else:
            f['data']['notes'][mid]=(oldnote+' '+note).strip()
        records.append({'batch':r['batch'],'id':mid,'label':r['label'],'src':r['src'],'before':old,'after':new,'reason':note,'dups':r['dups']})
    backup=OUT/'before_kj_speech'
    backup.mkdir(exist_ok=True)
    for p,f in files.items():
        bp=backup/p.name
        assert not bp.exists(), 'refusing to overwrite backup'
        bp.write_text(f['raw'],encoding='utf-8')
        raw=f['raw']
        for old,new in f['mods']:
            quoted=json.dumps(old,ensure_ascii=False)
            assert raw.count(quoted)>=1
            raw=raw.replace(quoted,json.dumps(new,ensure_ascii=False),1)
        # Replace only the notes object; other JSON formatting remains untouched.
        match=re.search(r'(?m)^(\s*)"notes"\s*:\s*',raw)
        assert match
        start=match.end()
        _,used=json.JSONDecoder().raw_decode(raw[start:])
        base=match.group(1)
        step=' ' if len(base)==1 else '  '
        lines=['{']
        items=list(f['data']['notes'].items())
        for i,(k,v) in enumerate(items):
            lines.append(base+step+json.dumps(k,ensure_ascii=False)+': '+json.dumps(v,ensure_ascii=False)+(',' if i<len(items)-1 else ''))
        lines.append(base+'}')
        raw=raw[:start]+'\n'.join(lines)+raw[start+used:]
        assert json.loads(raw)==f['data']
        p.write_text(raw,encoding='utf-8')
    (OUT/'kj_speech_changes.json').write_text(json.dumps(records,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
    with (OUT/'kj_speech_changes.tsv').open('w',encoding='utf-8',newline='') as file:
        writer=csv.DictWriter(file,fieldnames=records[0].keys(),delimiter='\t');writer.writeheader();writer.writerows(records)
    with (OUT/'kj_speech_check.log').open('w',encoding='utf-8') as logfile:
        for p in files:
            result=subprocess.run([str(ROOT/'.venv/Scripts/python.exe'),'-X','utf8',str(ROOT/'scripts/merge_ko.py'),'--check',p.stem],cwd=ROOT,timeout=120,stdout=subprocess.PIPE,stderr=subprocess.STDOUT,encoding='utf-8',check=True)
            logfile.write('== '+p.stem+' ==\n'+result.stdout+'\n')
            print(p.stem,result.stdout[-300:])
    print('CHANGES',len(records),'BATCHES',len(files),'EXPANDED',sum(1+len(r['dups']) for r in records))

if __name__=='__main__':
    main()
