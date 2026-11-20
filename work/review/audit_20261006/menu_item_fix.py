import csv
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
OUT = Path(__file__).resolve().parent
rows = json.loads((OUT / 'menu_item_rows.json').read_text(encoding='utf-8'))
by_id = {row['id']: row for row in rows}
fixes = {}

def set_text(mid, text, reason):
    fixes[mid] = (text, reason)

def replace(mid, old, new, reason):
    text = by_id[mid]['ko']
    assert text.count(old) == 1, (mid, old)
    set_text(mid, text.replace(old, new), reason)

replace('Menu#333', '로 바꾸고', '로 전환하고', '액션 아이콘 切り替える/きりかえる는 DS 공통 조작 용어 전환으로 통일. 히라가나 표기 때문에 앞선 용어 점검에서 빠진 곳을 수정.')
for mid, ref in [('Menu#232', 110), ('Menu#245', 112)]:
    replace(mid, '앞으로는 쇼핑하실 때마다', '앞으로는 구입하실 때마다', f'DS SAI__SMes_yo 표0#{ref}와 같은 상점 보너스 안내의 공통 문장 복원. 쇼핑 단독 명칭을 맞추느라 재번역한 서술문을 DS대로 쓰며, 3DX에서 바뀐 카드 명칭은 유지.')
replace('Menu#649', '그럼 즐거운 쇼핑\n되시길 바랍니다~', '그럼 천천히\n둘러보세요~', 'DS SAI__SMes_yo 표0#90와 같은 상점 설명 마무리 대사를 그대로 복원. 기존 note의 お買い物=쇼핑 경고 회피보다 DS 공통 문장 그대로 쓰기 원칙을 적용.')
replace('Menu#731', '(New 닌텐도 3DS 전용)', '※New 닌텐도 3DS 전용', '원문 주석 기호 ※ 복원. 기존 note의 폰트 미지원 사유는 2026-09-30 기호 글리프 반영 이후 해소됨.')
set_text('Menu#322', '어머나! 손님!\nSUYEOM 멋진 것 좀 봐!{1:wait}', 'DS SAI__SMes_yo 표0#37와 같은 부티크 상점 첫 보너스 안내의 공통 대사를 띄어쓰기·문장부호까지 복원.')
set_text('Menu#343', '어머나! 손님!\nSUYEOM이 더 멋져진 것\n같은데 맞죠?{1:wait}', 'DS SAI__SMes_yo 표0#45와 같은 부티크 상점 보너스 업그레이드의 공통 대사를 그대로 복원.')
set_text('Menu#801', '우와! 마리오님! 루이지님!\nSUYEOM이 훨씬 더\n멋져지셨네요!{1:wait}', 'DS SAI__SMes_yo 표0#44와 같은 상점 보너스 업그레이드의 공통 대사를 감탄사·문장부호까지 복원.')
replace('Menu#458', '당첨 되면', '당첨되면', 'DS 오기 수정: SAI__SMes_yo 표0#130의 당첨 되면을 합성 동사 당첨되다에 맞춰 붙여 씀.')

# BAI__BMes_yo 표2는 기존 HugeBattle 배치 DS 참조에서 빠져 있었다.
# 같은 장면과 뜻인 원작 한국어만 복원하고 3DX 제어 태그는 모두 보존한다.
ds_huge = {
    21: (14, '뜨거워{1:pause}지면{2:pause}\n버리자!{3:pause}{4:color}{5:wait}{6:color}'),
    26: (20, '싸울 줄 아는걸?{1:pause}\n하지만{2:pause} 이 공격은{3:pause}\n피할 수 없을 거다…{4:pause}'),
    29: (6, '또 그것을\n쏠 작정이냐!?'),
    33: (7, '흥!{1:pause} 저따위 건\n이 몸이 화염으로\n떨어뜨려 주겠다!'),
    37: (8, '크핫핫핫!{1:pause} 봤느냐?{2:pause}\n이 몸의 힘을!'),
    41: (18, '방어 시스템{1:pause}\n프로그램{2:pause} 가동!{3:pause}{4:color}{5:wait}{6:color}'),
    44: (19, '이제{1:pause} 정면에서\n오는{2:pause} 공격은{3:pause}\n완전히{4:pause} 막는다!{5:pause}{6:color}{7:wait}{8:color}'),
    96: (0, '무슨 속셈이냐?'),
    97: (1, '뭐냐? 불꽃이냐?\n어수룩한 녀석이군…'),
    100: (2, '응?{1:pause} 터지질 않는데?\n불발탄인가?'),
    103: (3, '특이한 불꽃이군…{1:pause}\n상관없다!{2:pause}\n불꽃은 신경 끄고…'),
    107: (4, '이 녀석부터\n해치워야겠군!'),
    109: (5, '허억―!{1:pause} 이 몸을\n빨아들일 작정이냐?{2:color}{3:wait}{4:color}'),
    111: (9, '당할 것 같으냐!?{1:color}{2:wait}{3:color}'),
    114: (12, '뜨거워!{1:pause} 뜨거워!{2:pause}\n불이야!{3:pause} 불이야!{4:pause}{5:color}{6:wait}{7:color}'),
    116: (13, '타 버릴 만한{1:pause} 물건은{2:pause}\n버려야겠다!{3:pause}{4:color}{5:wait}{6:color}'),
    122: (17, '방어 시스템{1:pause}\n프로그램{2:pause} 에러!{3:pause}\n방어{4:pause} 소멸!{5:pause}{6:color}{7:wait}{8:color}'),
    124: (22, '부끄부끄 시스템{1:pause} 가동!{2:pause}\n중간에{3:pause} 모습이{4:pause}\n보이지 않게{5:pause} 된다면…{6:pause}{7:color}{8:wait}{9:color}'),
    125: (23, '반격의{1:pause} 타이밍도{2:pause}\n알 수 없게{3:pause} 되겠지!{4:pause}{5:color}{6:wait}{7:color}'),
    127: (24, '생각보단 세군.{1:pause}\n하지만{2:pause} 이걸{3:pause}\n견뎌 낼 수 있을까?{4:pause}'),
    134: (26, '블랙홀로{1:pause} 빠지는{2:pause}\n데스 매치다!{3:pause}'),
    135: ('27~28', '네가{1:pause} 강하다는 건{2:pause}\n인정하겠다!{3:pause}{4:color}{5:wait}{6:color}[Next]하지만{7:pause} 너도{8:pause}\n이걸로 끝이다!{9:pause}{10:color}{11:wait}{12:color}'),
}
for number, (ref, text) in ds_huge.items():
    reason = f'배치 참조에 누락된 DS BAI__BMes_yo 표2#{ref}의 같은 장면·같은 뜻 한국어를 복원. 3DX 자리표시자·페이지 수 유지.'
    if number == 122:
        reason += ' 피치로봇의 이 문맥은 DS에서 방어 소멸이며 용어집 전투 ガード=방어와도 일치하므로 기존 방어벽을 복원.'
    set_text(f'HugeBattle#{number}', text, reason)
replace('HugeBattle#1', '얼른 수리하는 거야!', '수리하는 거야!', 'DS BAI__BMes_ji 표3#7의 같은 장면·같은 뜻 대사를 그대로 복원.')
set_text('HugeBattle#25', '방금{1:pause} 공격은{2:pause}\n제법{3:pause} 위협적이군!{4:pause}{5:color}{6:wait}[Next]{7:color}블랙홀을{8:pause}\n사용해서{9:pause} 몸으로{10:pause}\n공격해 올 줄이야…{11:pause}{12:color}{13:wait}{14:color}', '배치 참조에 누락된 DS BAI__BMes_yo 표2#15~16의 공통 대사를 두 페이지 모두 복원. 단독 タイアタリ/体当たり의 확정 glossary 행은 없으며 行列体当たり·超体当たり는 별도 기술명이다. 이 문장의 타격 방식은 DS의 몸으로 공격해 올 줄이야와 같은 뜻이므로 DS 공통 문장 그대로 쓰기 원칙 적용.')
replace('HugeBattle#101', '주세요!', '주세요.', 'DS BAI__BMes_ji 표2#30와 같은 파이어 버튼 터치 안내의 문장부호를 DS대로 복원.')

changes = []
documents = {}
backup = OUT / 'menu_item_backup'
backup.mkdir(exist_ok=True)
for mid, (new, reason) in fixes.items():
    row = by_id[mid]
    batch = row['batch']
    path = ROOT / 'text/ko' / f'{batch}.json'
    if batch not in documents:
        original = path.read_text(encoding='utf-8')
        (backup / path.name).write_text(original, encoding='utf-8')
        documents[batch] = json.loads(original)
    document = documents[batch]
    assert document['translations'][mid] == row['ko'], (mid, 'concurrent edit or already applied')
    assert new != row['ko'], mid
    document['translations'][mid] = new
    old_note = document.setdefault('notes', {}).get(mid, '')
    document['notes'][mid] = ((old_note.rstrip() + '\n') if old_note else '') + 'review: ' + reason
    changes.append(dict(batch=batch, id=mid, before=row['ko'], after=new, reason=reason, duplicates=len(row['dups'])))
for batch, document in documents.items():
    (ROOT / 'text/ko' / f'{batch}.json').write_text(json.dumps(document, ensure_ascii=False, indent=1) + '\n', encoding='utf-8')
(OUT / 'menu_item_changes.json').write_text(json.dumps(changes, ensure_ascii=False, indent=2) + '\n', encoding='utf-8')
with (OUT / 'menu_item_changes.tsv').open('w', encoding='utf-8-sig', newline='') as stream:
    writer = csv.DictWriter(stream, fieldnames=['batch', 'id', 'before', 'after', 'reason', 'duplicates'], delimiter='\t')
    writer.writeheader()
    writer.writerows(changes)
print('Changed', len(changes), 'messages in', len(documents), 'batches; affected duplicate IDs', sum(c['duplicates'] for c in changes))
print('Batches:', ' '.join(sorted(documents)))
