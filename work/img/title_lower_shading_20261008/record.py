from pathlib import Path
import datetime,json
ROOT=Path(__file__).resolve().parents[3];OUT=Path(__file__).parent
install=json.loads((OUT/'install.json').read_text(encoding='utf8'))
assert install['stage_patch_junction_match'] and install['all_sd_and_zip_files_match']
path=ROOT/'work/lead_state.json'
state=json.loads(path.read_text(encoding='utf8'))
state['updated']='2026-10-08'
state['phase']='2026-10-08 1DX 골조 타이틀의 지 ㅣ 끝을 첨부 로고로 복원. 하단 음영은 1DX 외곽·무늬와 3DX 일본판 색 변화로 재제작. 두 실루엣 리/오 및 DX 중앙 정렬 유지. patch/SD ZIP 설치 완료, 실제 게임 화면 확인 대기.'
state['build']['latest']='2026-10-08: Rounded ji-stem cap restored from user reference; original stem retained. Imported actual 1DX underside alpha contour and 2D light pattern, mapped to measured 3DX Japanese dark red/green/cyan gradients. Other six face masks and 6,217 interior color/gloss pixels equal. Only title bottom texture changed; all other BCH bytes, intro, geometry/animation, DX/deluxe/3 texture equal. Installed FMdl and synced all 36 patch/junction/SD/ZIP files; CRC PASS. Backup work/build/prev_title_lower_shading_20261008/. No emulator launched.'
state['title_lower_shading_20261008']={
    'report':'work/img/title_lower_shading_20261008/REPORT.md',
    'recipe':'work/img/title_lower_shading_20261008/material.py',
    'preview':'work/img/title_lower_shading_20261008/title_before_after.png',
    'stem_preview':'work/img/title_lower_shading_20261008/stem_before_after.png',
    'underside_preview':'work/img/title_lower_shading_20261008/underside_before_after.png',
    'stem_reference':'work/img/title_lower_shading_20261008/ref/luigi_stem.png',
    'stem_change':'rounded cap added to ji; color and gloss remain 3DX',
    'underside_shape_and_pattern':'actual 1DX contour and 2D light pattern',
    'underside_palette':'measured Japanese 3DX gradients',
    'positions_unchanged':True,'install':install,'runtime_verified':False,'subagents_used':False,
    'timestamp':datetime.datetime.now(datetime.timezone(datetime.timedelta(hours=9))).isoformat()}
path.write_text(json.dumps(state,ensure_ascii=False,indent=1)+'\n',encoding='utf8')

def append_once(path,marker,note):
    text=path.read_text(encoding='utf8')
    if marker not in text:path.write_text(text+note,encoding='utf8')

append_once(ROOT/'work/img/I4.md','## 15. ㅣ 끝 복원','''

## 15. ㅣ 끝 복원과 하단 음영 재제작 (2026-10-08, 사용자 첨부 참고)
- 지 ㅣ의 새싹 제거 흔적을 첨부 로고의 둥근 끝으로 채움. 기존 기둥을 보존하고 색·광택은 기존 3DX 재질로 제작. 원본 좌표 X 321~331, Y 37~43에만 글자 면 추가.
- 하단 음영은 전역 행별 색칠에서 실제 1DX 알파 외곽·2D 음영 무늬로 변경. 3DX 일본판의 남색→자주/빨강·초록·청록 곡선으로 색을 옮겨 글자 굴곡을 따르게 했다.
- 다른 여섯 글자의 마스크·내부 면 색/광택 6,217픽셀 동일. 실루엣 리/오, 글자 간격·배율·RPG/3 위치, DX/디럭스 동일.
- FMdl 재읽기에서 타이틀 bottom 텍스처만 변경, 그 밖의 모든 BCH 바이트·인트로·애니메이션·좌표 동일. patch/정션/SD/ZIP 36파일 일치, ZIP CRC PASS.
- 최종 레시피·보고서·비교: work/img/title_lower_shading_20261008/material.py, REPORT.md, stem_before_after.png, underside_before_after.png. 이전 파일: work/build/prev_title_lower_shading_20261008/. 실제 게임 실행은 사용자 확인 대기.
''')
append_once(ROOT/'work/img/SHARED_CHANGES.md','title_lower_shading_20261008/REPORT.md','''
- 2026-10-08 리드(하단 음영): `model.render`에 선택 인자 `ext_override`를 추가했다. 2D RGB·마스크를 하단 몸통에만 입히고 면·광택·기본 호출의 동작은 유지한다. `donor_layout.masks`는 선택적 `donor_masks`를 받아 지 ㅣ 끝 복원을 적용한다. 기록: `work/img/title_lower_shading_20261008/REPORT.md`.
''')
for folder in ['title_1dx_shapes_20261008','title_layout_20261008']:
    append_once(ROOT/f'work/img/{folder}/REPORT.md','title_lower_shading_20261008/REPORT.md',
                '\n\n후속 사용자 지침: 지 ㅣ의 윗부분을 둥근 참고 형태로 복원하고, 하단 음영을 실제 1DX 외곽·무늬와 3DX 일본판 색 표로 다시 제작했다. 최신 기록: `work/img/title_lower_shading_20261008/REPORT.md`.\n')
print('Recorded completed cap repair, donor underside shading and synchronized install')
