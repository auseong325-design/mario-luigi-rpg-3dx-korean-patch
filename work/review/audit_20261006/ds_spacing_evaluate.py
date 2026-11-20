import csv, json, re, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
OUT = Path(__file__).parent
sys.path.insert(0,str(ROOT/'scripts'))
from merge_ko import check_message

candidates = json.loads((OUT/'ds_spacing_candidates.json').read_text(encoding='utf-8'))
decisions = {}
for mid in ['FMsg/i_challenge_01#51','FMsg/i_challenge_01#53','FMsg/i_challenge_01#54','FMsg/o_town_37#1']:
    decisions[mid] = ('keep_choice_tags', 'DS 선택지 사이 공백은 3DX의 choice/tab 제어태그로 대체됨. 실제 낱말 내부 띄어쓰기 차이가 아니므로 유지.')
for mid in ['FMsg/i_koopa_13_escape_01_L#19','FMsg/i_metaboru_19#14','FMsg/o_chika_09_before#25','FMsg/o_town_14#4','FMsg/o_zutsuda_04_after#14']:
    decisions[mid] = ('keep_ds_typo_correction', '기존 notes에 DS 오기 수정 근거가 있고 AGENTS 4.6에서 허용하는 명확한 띄어쓰기 수정이므로 유지.')
decisions['FMsg/o_zutsuda_04_before#7'] = ('keep_changed_context', 'DS0F9의 쿠 파 님은 군단 구호. 3DX before 신규 장면은 보통 호칭 クッパ様이고 glossary 쿠파님을 따른다. 3DX after#9의 クッ パッ さまっ 구호는 이미 쿠 파 님으로 구별돼 있음.')
for mid in ['FMsg/o_ekubon_02#0','FMsg/o_ekubon_04_1#1','FMsg/o_ekubon_04_2#0','FMsg/o_gepu_11#0']:
    decisions[mid] = ('restore_ds_candidate', '표지판은 일본어/DS와 동일 내용. style_guide 2.1의 일반 화살표 붙임보다 AGENTS 0·4.6 및 style_guide 첫머리의 같은 DS 문장 그대로 사용 규칙이 우선하므로 DS 간격 복원 후보.')
decisions['FMsg/o_koopa_13_2#57'] = ('restore_ds_candidate','DS0D1#53은 나라고. JP의 わ/し 분리 연출은 pause 태그로 유지할 수 있으므로 한 낱말 안의 추가 공백은 제거하는 후보.')
decisions['FMsg/o_peach_1f_03#41'] = ('restore_ds_candidate','DS20F#2는 끝이다. JP의 オワ/ル 분리 연출은 pause 태그로 유지할 수 있고, 메타보스의 가타카나 말투를 띄어쓰기로 흉내 내지 말라는 style_guide 3.3에도 부합하므로 추가 공백 제거 후보.')
for mid in ['FMsg/o_peach_1f_08#9','FMsg/o_zutsuda_15#15']:
    decisions[mid] = ('restore_ds_candidate','같은 뜻의 DS 대사에 없는 말줄임표 뒤 공백. 일반 문장부호 지침(style_guide 2.1)보다 DS 동일 표현 보존 규칙이 우선하며 pause 태그는 유지하므로 DS 간격 복원 후보.')

proposals = []
evaluated = []
for r in candidates:
    status, reason = decisions[r['id']]
    before = r['ko_current']
    after = before
    if status == 'restore_ds_candidate':
        if r['id'] in ['FMsg/o_ekubon_02#0','FMsg/o_ekubon_04_1#1','FMsg/o_ekubon_04_2#0','FMsg/o_gepu_11#0']:
            after = re.sub(r'[↑↓→←]',lambda m:m.group(0)+' ',after)
        elif r['id']=='FMsg/o_koopa_13_2#57':
            after = after.replace('나{1:pause} 라고','나{1:pause}라고')
        elif r['id']=='FMsg/o_peach_1f_03#41':
            after = after.replace('끝{3:pause} 이다','끝{3:pause}이다')
        elif r['id']=='FMsg/o_peach_1f_08#9':
            after = after.replace('…{4:pause} 솔직히','…{4:pause}솔직히')
        elif r['id']=='FMsg/o_zutsuda_15#15':
            after = after.replace('…{5:pause} 아!','…{5:pause}아!').replace('…{10:pause} 에헴!','…{10:pause}에헴!')
        assert after != before, r['id']
        b = json.loads((ROOT/'work/batches'/f"{r['batch']}.json").read_text(encoding='utf-8'))
        msg = next(m for m in b['messages'] if m['id']==r['id'])
        errors, warnings = check_message(msg,after)
        proposals.append(dict(id=r['id'],batch=r['batch'],before=before,after=after,ds_key=r['ds_key'],reason=reason,errors=errors,warnings=warnings))
    evaluated.append(dict(id=r['id'],batch=r['batch'],ds_key=r['ds_key'],status=status,reason=reason,boundaries=len(r['gaps']),before=before,proposed_after=after))
(OUT/'ds_spacing_proposals.json').write_text(json.dumps(proposals,ensure_ascii=False,indent=2),encoding='utf-8')
with (OUT/'ds_spacing_evaluated.tsv').open('w',encoding='utf-8',newline='') as f:
    w=csv.DictWriter(f,fieldnames=list(evaluated[0]),delimiter='\t')
    w.writeheader();w.writerows(evaluated)
print('candidates',len(candidates),'proposals',len(proposals),'errors',sum(len(p['errors']) for p in proposals),'warnings',sum(len(p['warnings']) for p in proposals))
for p in proposals:
    print(p['id'],p['errors'],p['warnings'])
