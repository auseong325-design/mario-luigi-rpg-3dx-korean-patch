import csv
import json
import re
from collections import Counter
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
OUT = Path(__file__).resolve().parent
rows = json.loads((OUT / 'menu_item_rows.json').read_text(encoding='utf-8'))
changes = json.loads((OUT / 'menu_item_changes.json').read_text(encoding='utf-8'))
changed = {c['id']: c for c in changes}
allrows = {r['id']: r for r in rows}
fuzzy = json.loads((OUT / 'ds_candidates.json').read_text(encoding='utf-8'))
manual = {
 'Menu#202': ('유지: 3DX 변화', 'SAI__SMes_yo 표0#107', 'JP なりました에 맞춘 베리 쿨해졌군요. DS 베리 쿨하군요보다 변화 시점을 드러냄.'),
 'Menu#223': ('유지: 3DX 변화', 'SAI__SMes_yo 표0#109', 'JP さらに 매력의 정도 변화에 맞춘 더욱 매력 넘치는 유지.'),
 'Menu#291': ('유지: 3DX 표현 차이', 'SAI__SMes_yo 표0#58', '3DX これまでより 비교 표현을 반영한 지금까지보다 유지. DS의 아마보다 비교를 명시.'),
 'Menu#418': ('유지: 3DX 표현 차이', 'SAI__SMes_yo 표0#50', '3DX これまでより 비교 표현을 반영한 지금까지보다 유지. DS의 아마보다 비교를 명시.'),
 'Menu#798': ('유지: 3DX 표현 차이', '', '3DX 원문이 스타 패널 명칭을 명시하므로 DS 패널보다 명칭을 구체적으로 표현한 현행 유지.'),
 'Menu#628': ('유지: 오류 아님', '', '元に戻れます가 행동 설명 문맥에서 원래대로 돌아와요로 전달됨. 명백한 의미 누락으로 보지 않아 표현 개선만을 위한 수정은 하지 않음.'),
 'Menu#361': ('보류: 게임 화면', '', '설정 이름 메시지에 후리가나 표시. 사용자 화면 검토 대기 항목이므로 임의 변경하지 않음.'),
 'MenuKJ#20': ('보류: 화자 확인', '', '마귀 추정 해요체 현행. 화자/씬을 게임 화면에서 확인해야 루드윅 여부를 확정할 수 있음.'),
 'HugeBattle#77': ('유지: 3DX 변화', '', '3DX 펀치를 크게 휘두른다는 설명과 DS 펀치가 닿지 않는다는 설명이 다름.'),
 'HugeBattle#99': ('유지: 3DX 변화', '', '3DX キタナイ의 비겁함/반칙 의미를 반칙이다로 번역. DS 커질 줄 몰랐다는 표현과 의미가 달라 복원하지 않음.'),
 'HugeBattle#131': ('유지: 3DX 변화', 'BAI__BMes_yo 표2#25', '3DX 뒤로 물러나면 끝장과 DS 타격을 입으면 그것으로 끝은 전투 조건이 달라 현행 유지.'),
 'HugeBattle#115': ('유지: 3DX 조작 변화', '', '3DX 左/右から左 방향에 따라 왼쪽 조작 안내 유지. DS 오른쪽으로 돌리지 않음.'),
 'HugeBattle#98': ('유지: 3DX 기술명 변화', '', '3DX ファイアブレス=파이어 브레스 확정 glossary. DS 파이어와 구분됨.'),
}
for mid in ('MenuKJ#4', 'MenuKJ#12', 'MenuKJ#25', 'MenuKJ#26', 'MenuKJ#59', 'MenuKJ#60', 'MenuKJ#62', 'MenuKJ#88'):
    manual[mid] = ('보류: 게임 화면', '', '파티 이름 변수 결합용 수식어 끝 공백 1칸. 코드/번역 규칙 검사를 통과하지만 실제 UI 결합 결과 확인 필요.')

candidates = {}
for r in fuzzy:
    candidates[r['id']] = dict(batch=r['batch'], id=r['id'], disposition='유지: 유사도 후보 검토', reference=r['ds_ref'], score=r['score'], before=r['ko'], after=r['ko'], reason='JP/KO와 가장 비슷한 DS 후보를 읽음. 글자 유사도만으로 같은 메시지로 확정하지 않으며 3DX 설명·조건·수치 차이 및 DS 문형을 고려해 현행 유지.')
for mid, (disposition, reference, reason) in manual.items():
    r = allrows[mid]
    candidates[mid] = dict(batch=r['batch'], id=mid, disposition=disposition, reference=reference, score='', before=r['ko'], after=r['ko'], reason=reason)
for c in changes:
    candidates[c['id']] = dict(batch=c['batch'], id=c['id'], disposition='수정 완료', reference='', score='', before=c['before'], after=c['after'], reason=c['reason'])
with (OUT / 'menu_item_candidates.tsv').open('w', encoding='utf-8-sig', newline='') as stream:
    writer = csv.DictWriter(stream, fieldnames=['batch', 'id', 'disposition', 'reference', 'score', 'before', 'after', 'reason'], delimiter='\t')
    writer.writeheader()
    writer.writerows(sorted(candidates.values(), key=lambda r: (r['batch'], int(r['id'].split('#')[-1]))))

groups = []
for family in ('Item', 'Menu', 'MenuKJ', 'HugeBattle', 'InitLoad'):
    family_rows = [r for r in rows if r['batch'].split('__')[0] == family]
    duplicate_count = sum(len(r['dups']) for r in family_rows)
    nchange = sum(c['batch'].split('__')[0] == family for c in changes)
    groups.append(f'| {family} | {len({r["batch"] for r in family_rows})} | {len(family_rows)} | {duplicate_count} | {len(family_rows) + duplicate_count} | {nchange} |')
batch_lines = []
for batch in sorted({r['batch'] for r in rows}):
    ids = [r['id'] for r in rows if r['batch'] == batch]
    dups = sum(len(r['dups']) for r in rows if r['batch'] == batch)
    fixes = [c['id'] for c in changes if c['batch'] == batch]
    batch_lines.append(f'| {batch} | {len(ids)} | {dups} | {", ".join(fixes) if fixes else "없음"} |')
warning_log = (OUT / 'menu_item_check.log').read_text(encoding='utf-8')
warnings = [line for line in warning_log.splitlines() if line.startswith('  W ')]
report = f'''# Item/Menu/MenuKJ/HugeBattle/InitLoad 전수 검토 — 2026-10-06

담당: menu_item_audit. AGENTS.md 5.3 교차 검수. 원본·glossary·ko_final·병합·패치 빌드는 메인 담당 범위이며 이 검토에서는 수정하지 않았다.

## 범위와 직접 읽은 자료

| 계열 | 배치 수 | 직접 읽은 대표 메시지 | 복사본 ID | 복사본 포함 ID | 수정 대표 메시지 |
|---|---:|---:|---:|---:|---:|
{chr(10).join(groups)}
| 합계 | 16 | 1,405 | 275 | 1,680 | 34 |

16개 배치의 1,405개 대표 메시지 전부에 대해 일본어 src와 현재 한국어 번역을 직접 읽었다. 275개 복사본은 동일 문장의 자동 공유 대상이라는 뜻으로 집계했으며, 별도 문장 275개를 읽었다고 세지 않았다. 수정 34개에는 복사본이 없으므로 실제 변경 ID도 34개다. 전 범위 원문·번역 읽기 자료는 `*_read.txt`, 수정 전 1,405개 행 스냅샷은 `menu_item_rows.json`이다.

AGENTS.md와 text/style_guide.md를 끝까지 읽고, 기존 R09·R10·R11 검수 기록, `work/review/kj_1dx_terms.md`, `text/glossary.tsv`, `text/glossary_overrides.tsv`, Sept30 TEXT PASS 결정을 확인했다. DS 비필드 참조 전체를 재귀적으로 읽는 대조 자료를 만들고, 추출된 공통 문장/설명 후보를 직접 대조했다. 특히 MAI__MMes_yo의 배지 튜토리얼, SAI__SMes_yo 상점 대사, BAI__BMes_ji 거대전투 설명, BAI__BMes_yo 표2 피치로봇/쿠파 공통 대사를 확인했다.

현재 번역과 `work/ref_1dx_ko.tsv`를 다시 짝지어 만든 174개 라벨 대응을 모두 읽었다(Item 120, Menu 32, MenuKJ 17, InitLoad 5). 짝은 라벨에 따른 후보로서 실제 설명과 아이템 이름이 같은지 따로 판단했다. 장비 순번·가이드 순번·amiibo 오류 순번이 두 작품에서 달라 이름이 같지 않은 대응을 억지로 적용하지 않았다. 관련 대조표는 `menu_item_1dx.tsv`와 `*_1dx_read.txt`다.

## 반영한 수정

34개 대표 메시지를 5개 번역 파일에서 수정하고 각각 notes에 `review:`와 근거를 남겼다. 구성은 DS 공통 대사/부호 복원 31개, DS 오기 수정 1개, 조작 용어 통일 1개, 원문 주석 기호 복원 1개다. 전후 문장과 상세 근거는 `menu_item_changes.tsv` / `menu_item_changes.json`에 기록했다.

| 배치 | 직접 읽은 대표 수 | 복사본 수 | 수정 ID |
|---|---:|---:|---|
{chr(10).join(batch_lines)}

Menu#232/#245는 DS SAI__SMes_yo 표0#110/#112의 「앞으로는 구입하실 때마다」를 「쇼핑하실 때마다」로 바꾸었던 서술문을 복원했다. Menu#649도 표0#90의 「그럼 천천히 둘러보세요~」를 복원했다. お買い物 단독 용어로서 쇼핑 표기는 유지하지만, 같은 장면의 공통 대사를 glossary 부분문자열 경고를 피하려고 재번역하지 않는다. 3DX에서 달라진 스크래치 카드→보너스 카드 명칭은 유지했다.

Menu#322/#343/#801은 같은 상점 주인·같은 보너스 단계의 DS 표0#37/#45/#44 문장을 감탄사, SUYEOM 뒤 문형, 문장부호까지 복원했다. Menu#458의 당첨 되면은 DS에도 있는 명백한 합성 동사 띄어쓰기 오기로 보아 「당첨되면」으로 고치고 `DS 오기 수정`을 기록했다.

Menu#333은 액션 아이콘을 해머로 「바꾸고」를 「전환하고」로 통일했다. 일본어가 히라가나 きりかえて로 쓰여 이전 切り替える 점검에서 빠진 곳이다. Menu#731은 폰트가 ※를 지원하지 않는다는 옛 note를 근거로 괄호가 되었던 원문 주석을 「※New 닌텐도 3DS 전용」으로 복원했다. ※는 Sept30에 폰트에 추가된 상태다.

HugeBattle은 기존 배치 참조가 BAI__BMes_yo 표2를 포함하지 않아 같은 장면 대사를 새로 번역한 부분이 남아 있었다. 표2의 본문 29개(0~28, 실제 문장 27개와 placeholder 2개)를 전부 읽었고, 같은 의미의 대사 23개 대표 ID를 DS로 복원했다. BAI__BMes_ji 공통 대사 2개(#1/#101)를 합쳐 HugeBattle 수정은 25개다. 원작의 방어 시스템·가동·데스 매치 표기를 되돌렸으며, #122 ガード=방어는 해당 DS 대사와 전투 glossary에 모두 맞는다.

HugeBattle#25는 DS BAI__BMes_yo 표2#15~16의 「방금 공격은 제법 위협적이군!」「블랙홀을 사용해서 몸으로 공격해 올 줄이야…」를 두 페이지 모두 복원했다. 원문 タイアタリ/体当たり의 뜻은 몸으로 들이받는 공격이며, DS의 「몸으로 공격」과 같은 상황·의미다. 현행 glossary에는 단독 タイアタリ/体当たり 확정 행이 없다. 行列体当たり=행렬 몸통 박치기 및 超体当たり=초몸통박치기는 별도 기술명이므로 이 대사의 서술문에 우선 적용할 근거가 되지 않는다. 따라서 DS 공통 문장 원칙을 적용했다. 제어 태그, pause 수, 페이지 수는 3DX 그대로 보존했다.

## 유지한 차이와 대기 항목

Item 575개는 아이템 이름·장비 효과·배지 효과·스페셜 어택 설명을 전부 읽었다. 회복량, 능력치, 발동 조건, 장비 대상, 공격 대상 등은 3DX 원문을 따르며 DS 수치를 복사하지 않았다. 1DX의 ウルトラキノコ=80 회복과 3DX의 100 회복, 같은 라벨이지만 전혀 다른 웨어/팬츠 등은 실제 작품 차이다. DS 확정 SP·타격·미라클버섯·헐렁헐렁웨어·배지 등은 glossary/DS 우선으로 유지한다. ラリー=랠리(주고받기)와 적 이름 래리, 점프점프헬멧 설명의 メット=헬멧과 적 이름 하잉바의 부분문자열 경고는 문맥이 다르다. 이번 범위에서 Item 수정은 없다.

MenuKJ 101개는 모든 시스템 문구·기록·편성·서브 리더·가이드를 읽었다. 1DX와 공통인 기록·편성·강화·작별·LP 등 용어와 기존 Sept30 정렬 결과를 확인했다. 동료는 DS/glossary 우선이라 1DX 아군으로 일괄 변경하지 않았다. 챌린지는 사용자 Sept30 결정대로 유지했다. 문체와 변수 뒤 조사 처리도 검토했고, 명확한 새 오류는 발견하지 않아 이번 수정은 없다.

InitLoad 5개는 저장 데이터 오류·초기화·삭제 경고·대기 문구 모두 검토했다. 1DX와 표현이 다른 일부 문장도 현재 DS/glossary 문형 및 하십시오체와 맞고 원문 의미를 전달하므로 유지했다.

HugeBattle#131은 DS 「타격을 입으면」과 3DX 「뒤로 물러나면」의 조건이 다르다. #77(펀치 설명), #99(치사하다는 대사), #98(파이어→파이어 브레스 기술명), 슬라이드 왼쪽 방향, 마이크 대신 터치하는 화염 조작, 파이널 어택은 실제 원문/게임 조작이 달라 현행을 유지했다. Menu#202/#223의 변화·정도 표현과 #291/#418의 これまでより 비교 표현도 3DX 의미를 고려해 유지했다.

설정 이름 Menu#361 「메시지에 후리가나 표시」는 사용자 게임 화면 검토 대기라 손대지 않았다. MenuKJ#20 화자가 마귀인지 루드윅인지, 서브 리더 수식어 8개 끝 공백의 파티 이름 결합 결과는 실제 화면 확인이 남아 있다. 배치 notes에 기존 확인 필요 기록이 있으며 `menu_item_candidates.tsv`에 보류로 기록했다. 게임 화면을 보지 않고 이름이나 말투를 임의로 바꾸지 않았다.

## 검증과 한계

`.venv\\Scripts\\python -X utf8`로 UTF-8 출력과 subprocess 180초 timeout을 걸어 `scripts/merge_ko.py --check`를 담당 16배치 전체에 실행했다. **16/16 통과, 오류 0, 경고 {len(warnings)}개**다. 미번역, 일본어 잔존, 금지 문자, 자리표시자 누락/중복, [Next] 수 변경, 한도 초과 폭 오류는 없다. 결과 원문은 `menu_item_check.log`다.

경고 중 41개는 glossary 부분문자열/활용형 검사다. DS 문장 「구입하실」「둘러보세요」의 쇼핑 경고, 덮어쓴/덮어써도 활용형, 랠리/헬멧 문맥 등을 직접 검토했다. 2개 줄 수 경고는 Menu#534/#535의 원문 첫 줄이 변수만 있어 검증기에서 빈 줄로 취급한 결과다. 실제 원문과 번역은 각각 두 줄이며 기존 note에 근거가 있다.

후리가나 설정명·추정 화자·변수 결합은 실제 게임 화면 검증 전이다. 이 검토는 텍스트와 참조를 대조한 결과이며 폰트 픽셀·이미지·패치 설치·전체 병합/빌드·Azahar 플레이 확인은 메인이 따로 검증한다. 이 결과만으로 화면 넘침이나 연출 타이밍까지 검증했다고 주장하지 않는다.

자동 DS 유사도 후보 {len(fuzzy)}개와 별도로 직접 찾은 수정/유지/대기 항목을 합쳐 `menu_item_candidates.tsv`에 {len(candidates)}개 ID의 판단을 남겼다. 유사도는 같은 문장이라는 증거가 아니며 후보를 오역으로 세지 않았다. 최종 수정은 34개다.
'''
(OUT / 'menu_item.md').write_text(report, encoding='utf-8')
print('report written:', len(rows), 'canonical;', len(changes), 'changed;', len(fuzzy), 'fuzzy candidates;', len(candidates), 'candidate rows;', len(warnings), 'warnings')
print('\n'.join(groups))
