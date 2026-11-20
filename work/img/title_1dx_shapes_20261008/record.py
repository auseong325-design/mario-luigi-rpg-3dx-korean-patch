from pathlib import Path
import datetime
import json

ROOT = Path(__file__).resolve().parents[3]
OUT = Path(__file__).parent
install = json.loads((OUT / 'install.json').read_text(encoding='utf8'))
assert install['stage_patch_junction_match'] and install['all_sd_and_zip_files_match']
state_path = ROOT / 'work/lead_state.json'
state = json.loads(state_path.read_text(encoding='utf8'))
state['updated'] = '2026-10-08'
state['phase'] = '2026-10-08 타이틀 마리오&루이지 글꼴·형태·간격을 1DX 원래 골조로 통일, 3DX 색·광택 유지. 인트로 &도 통일. 두 실루엣은 마리오 위(리/오), DX·디럭스 중앙 정렬 유지. patch/SD ZIP 설치 완료, 실제 게임 화면 확인 대기.'
state['build']['latest'] = '2026-10-08: All seven main-title glyphs including & use raw 1DX masks and relative positions under one uniform scale; prior stroke growth and ji-stem redesign removed. 3DX measured colors/gloss/material retained. Intro & uses the same donor shape. Only three title textures differ; geometry/animation and DX/deluxe pixels unchanged. Installed FMdl and synced all 36 patch/Azahar-junction/SD/ZIP files; ZIP CRC PASS. Backup work/build/prev_title_1dx_shapes_20261008/. No game launched.'
state['title_1dx_shapes_20261008'] = {
    'report': 'work/img/title_1dx_shapes_20261008/REPORT.md',
    'preview': 'work/img/title_1dx_shapes_20261008/title_before_after.png',
    'intro_preview': 'work/img/title_1dx_shapes_20261008/intro_before_after.png',
    'donor': 'work/img/logo/src/1DX/kr_logo_rgba.png',
    'donor_layout': 'work/img/title_1dx_shapes_20261008/donor_layout.py',
    'glyphs': ['마', '리', '오', '&', '루', '이', '지'],
    'uniform_scale': 0.9095092024539877,
    'donor_relative_positions_preserved': True,
    'stroke_growth': 0,
    'stem_redesign': False,
    'material': '3DX measured face/extrusion gradients, gloss, navy outline and glow',
    'silhouette_positions': {'mario': '리', 'luigi': '오'},
    'dx_deluxe_pixels_preserved': True,
    'verification': [
        'work/img/title_1dx_shapes_20261008/shape_verify.json',
        'work/img/title_1dx_shapes_20261008/build_verify.json',
        'work/img/title_1dx_shapes_20261008/intro_preview_verify.json',
    ],
    'install': install,
    'runtime_verified': False,
    'subagents_used': False,
    'timestamp': datetime.datetime.now(
        datetime.timezone(datetime.timedelta(hours=9))).isoformat(),
}
state_path.write_text(json.dumps(state, ensure_ascii=False, indent=1) + '\n', encoding='utf8')


def append_once(path, marker, note):
    text = path.read_text(encoding='utf8')
    if marker not in text:
        path.write_text(text + note, encoding='utf8')


append_once(ROOT / 'work/img/I4.md', '## 14. 마리오&루이지 골조', '''

## 14. 마리오&루이지 골조·&를 1DX로 통일 (2026-10-08, 사용자 추가 지침)
- 1DX 원본 「마·리·오·&·루·이·지」 면과 상대 위치를 하나의 가로=세로 배율(약 0.9095)로 옮겼다. 획 굵힘·「지」 기둥 재설계 제거. 3DX 색·광택·테두리·입체·글로우는 기존 측정 재질로 유지한다.
- 타이틀 `&`와 별도 인트로 `&` 모두 1DX 모양. 두 실루엣은 리/오 위로 유지, DX·디럭스 픽셀·중앙 정렬 동일. RPG·3은 직전보다 오른쪽 0.5 텍스처 픽셀 이동.
- 역투영한 글자 면 마스크 IoU 99.44~100%, 인트로 & 99.84%. 정적 인트로 투영에서 양쪽 단어 면과 교차 0. 게임 실행 검증과는 구분한다.
- 재읽기에서 fmd_title_JP_ja의 텍스처 세 장만 변경. 그 밖의 픽셀·모델·정점·뼈대·애니메이션·조립 좌표 모두 동일. patch/정션/SD/ZIP 36파일 일치, ZIP CRC PASS.
- build_title.py 및 logo2/run_all.py 재제작 경로 갱신. 이전 파일: work/build/prev_title_1dx_shapes_20261008/. 최종 보고서·비교 그림: work/img/title_1dx_shapes_20261008/REPORT.md, title_before_after.png. 실제 게임은 사용자 확인 대기.
''')
append_once(ROOT / 'work/img/SHARED_CHANGES.md', 'title_1dx_shapes_20261008/REPORT.md', '''
- 2026-10-08 리드(1DX 로고 골조): `work/img/logo2/seg_1dx.py`의 `syllables`에 `fix_stem=True` 선택 인자를 추가했다. 기존 호출의 동작은 동일하고, 타이틀만 `False`로 실제 1DX 기둥을 사용한다. `logo2/run_all.py`에 새 타이틀 골조·인트로 & 제작 경로와 다섯 번째 타이틀 빌드 입력을 연결했다. 기록: `work/img/title_1dx_shapes_20261008/REPORT.md`.
''')
for folder in ['title_layout_20261008', 'title_silhouettes_20261008']:
    append_once(ROOT / f'work/img/{folder}/REPORT.md', 'title_1dx_shapes_20261008/REPORT.md',
                '\n\n후속 사용자 지침: &를 포함한 마리오&루이지의 골조·간격을 실제 1DX와 통일하고 3DX 재질을 유지했다. 두 실루엣은 리/오 위, DX·디럭스 중앙 정렬 유지. 최신 설치 기록은 `work/img/title_1dx_shapes_20261008/REPORT.md`.\n')
print('Recorded installed 1DX title glyphs, 3DX material, verification and distribution hashes')
