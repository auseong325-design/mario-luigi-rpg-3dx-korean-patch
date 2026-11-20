from pathlib import Path
from datetime import datetime,timezone,timedelta
import json
ROOT=Path(__file__).resolve().parents[3];OUT=Path(__file__).parent
timestamp=datetime.now(timezone(timedelta(hours=9))).isoformat()
path=ROOT/'work/lead_state.json';state=json.loads(path.read_text(encoding='utf8'))
before=OUT/'lead_state_before_final_record.json'
if not before.exists():before.write_bytes(path.read_bytes())
install=json.loads((OUT/'install.json').read_text());runtime=json.loads((OUT/'runtime_verify.json').read_text())
assert install['runtime_verified'] and runtime['runtime_verified']
state['updated']='2026-10-08'
state['phase']='2026-10-08 인트로 로고 & 정렬 수정 및 Codex 내장 computer-use로 Azahar v1.2 실제 검증 완료. 조립 유지/분리·회전/최종 타이틀 확인, patch·SD·ZIP 동기화 완료.'
state['build']['latest']='2026-10-08: Codex built-in @oai/sky reproduced and verified the intro logo in Azahar 2126.1.2, game v1.2. Corrected the texture-row direction: ampersand-only artwork translated upward 24 rows, without cropping or recoloring. Mario/Luigi/main-title artwork and all geometry/animation bytes unchanged. Actual assembly hold and separation/rotation observed in two patched runs, final title captured. All 36 patch/junction/SD/ZIP files equal, ZIP CRC PASS; default fmdl_stage synchronized. See work/img/logo_runtime_fix_20261008/REPORT.md.'
previous=state['logo_runtime_fix_20261008']
state['logo_runtime_fix_20261008']={'status':'complete; installed; verified in actual Azahar game via Codex built-in Computer Use',
    'report':'work/img/logo_runtime_fix_20261008/REPORT.md','intro_recipe':'work/img/logo_runtime_fix_20261008/build_intro.py',
    'runtime_comparison':'work/img/logo_runtime_fix_20261008/runtime_before_after.png',
    'runtime':runtime,'install':install,'timestamp':timestamp,
    'previous_connection_attempt':previous,'subagents_used':False}
state['logo_assembly_contours_20261008']['superseded_by']='logo_runtime_fix_20261008'
state['logo_assembly_contours_20261008']['animation_checks']['projection_valid_for_actual_alignment']=False
state['logo_assembly_contours_20261008']['status']='title fixes accepted; intro recipe superseded after actual-game texture-row direction correction'
closed=[];pending=[]
for item in state['review_items']:
    if item.startswith('2026-10-08 logo_assembly_contours:'):
        closed.append('2026-10-08: Intro Mario/&/Luigi alignment and main-title ru/ji contours verified directly in Azahar v1.2 via Codex built-in Computer Use; see logo_runtime_fix_20261008/REPORT.md.')
    elif item.startswith('Logos v2 (2026-10-02,'):
        pending.append('File-select logos v2: check 마리오&루이지 RPG3 and unchanged 쿠파주니어 RPG on the file-select screen. Main-title and intro alignment checks completed 2026-10-08 in Azahar; latest intro recipe logo_runtime_fix_20261008/build_intro.py.')
    else:pending.append(item)
state['review_items']=pending
if isinstance(state['review_items_closed'],str):state['review_items_closed']=[state['review_items_closed']]
for item in closed:
    if item not in state['review_items_closed']:state['review_items_closed'].append(item)
state['next']=[('USER: Remaining full-patch checks: file select, first dialogue, menus/shops, battle command blocks/status names, Bowser Jr. RPG, giant battles and staff roll. Intro assembly and main title verified directly in Azahar 2026-10-08.' if item.startswith('USER: Azahar test of the full patch') else item) for item in state['next']]
path.write_text(json.dumps(state,ensure_ascii=False,indent=1)+'\n',encoding='utf8')
i4=ROOT/'work/img/I4.md'
entry='''

## 18. 내장 Computer Use로 실제 인트로 재현·수정·검증 완료 (2026-10-08)
- 이번에 제공된 computer-use/26.1002.52244의 @oai/sky 직접 초기화가 성공했다. 메인 에이전트가 Azahar 2126.1.2에서 v1.2 게임을 직접 조작했다. 서브에이전트·Orca·별도 입력 스크립트 사용 없음.
- 실제 화면에서 §16의 &가 아래로 떨어지는 문제를 재현했다. 원인은 texture row/world Z 방향의 잘못된 해석이었다. & 밑선 보정을 +12에서 −12로 고쳐 이전 그림을 정확히 24행 위로 옮겼다. 글자/색/광택 픽셀과 마리오·루이지 그림은 동일, 잘림 없음.
- 원래 뼈대/모델/애니메이션 및 승인된 main title bottom/top 바이트는 그대로다. FMdl을 재읽어 title_logo_and_JP의 픽셀 영역만 바뀐 것을 확인했다.
- 실제 조립 유지 상태에서 정상 정렬 확인. 재시작 후 8개 실제 창 캡처로 유지/화면 붕괴/분리·회전/소용돌이 구간 확인. 최종 타이틀도 Ctrl+P로 기록했다. §16의 투영 검증은 실제 정렬 근거로 사용하지 않는다.
- patch/정션/SD/ZIP 36파일 일치, CRC PASS, 기본 fmdl_stage 동기화. 백업 work/build/prev_logo_runtime_fix_20261008/.
- 최신 레시피·보고서·실제 화면 비교: work/img/logo_runtime_fix_20261008/build_intro.py, REPORT.md, runtime_before_after.png. logo2/run_all.py는 새 레시피를 사용한다. 인트로 문제의 사용자 실행 대기는 종료했다.
'''
body=i4.read_text(encoding='utf8')
if '## 18. 내장 Computer Use' not in body:i4.write_text(body+entry,encoding='utf8')
print(json.dumps({'recorded':True,'runtime_verified':True,'closed_review_items':len(closed),'timestamp':timestamp},ensure_ascii=False))
