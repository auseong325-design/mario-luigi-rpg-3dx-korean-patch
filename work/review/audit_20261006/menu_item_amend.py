import csv
import json
from pathlib import Path
ROOT = Path(__file__).resolve().parents[3]
OUT = Path(__file__).resolve().parent
path = ROOT / 'text/ko/HugeBattle__p1.json'
doc = json.loads(path.read_text(encoding='utf-8'))
mid = 'HugeBattle#25'
doc['translations'][mid] = '방금{1:pause} 공격은{2:pause}\n제법{3:pause} 위협적이군!{4:pause}{5:color}{6:wait}[Next]{7:color}블랙홀을{8:pause}\n사용해서{9:pause} 몸으로{10:pause}\n공격해 올 줄이야…{11:pause}{12:color}{13:wait}{14:color}'
reason = '배치 참조에 누락된 DS BAI__BMes_yo 표2#15~16의 공통 대사를 두 페이지 모두 복원. 단독 タイアタリ/体当たり의 확정 glossary 행은 없으며 行列体当たり·超体当たり는 별도 기술명이다. 이 문장의 타격 방식은 DS의 몸으로 공격해 올 줄이야와 같은 뜻이므로 DS 공통 문장 그대로 쓰기 원칙 적용.'
doc['notes'][mid] = 'review: ' + reason
path.write_text(json.dumps(doc, ensure_ascii=False, indent=1) + '\n', encoding='utf-8')
changes = json.loads((OUT / 'menu_item_changes.json').read_text(encoding='utf-8'))
entry = next(c for c in changes if c['id'] == mid)
entry['after'] = doc['translations'][mid]
entry['reason'] = reason
(OUT / 'menu_item_changes.json').write_text(json.dumps(changes, ensure_ascii=False, indent=2) + '\n', encoding='utf-8')
with (OUT / 'menu_item_changes.tsv').open('w', encoding='utf-8-sig', newline='') as stream:
    writer = csv.DictWriter(stream, fieldnames=['batch', 'id', 'before', 'after', 'reason', 'duplicates'], delimiter='\t')
    writer.writeheader()
    writer.writerows(changes)
print('Amended HugeBattle#25 second page and evidence; total changed IDs remains', len(changes))
