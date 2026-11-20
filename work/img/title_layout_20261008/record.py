from pathlib import Path
import datetime,json,shutil
ROOT=Path(__file__).resolve().parents[3];OUT=Path(__file__).parent
state_path=ROOT/'work/lead_state.json'
state=json.loads(state_path.read_text(encoding='utf8'))
install=json.loads((OUT/'install.json').read_text(encoding='utf8'))
state['updated']='2026-10-08'
state['phase']='2026-10-08 인트로 & 좌표 수정과 타이틀 1DX 글자 비율·실루엣 화면 배치 수정 완료. patch/Azahar 정션/SD ZIP 동기화·독립 BCH 검증 통과. 실제 게임 화면 확인 대기.'
state['build']['latest']='2026-10-08: title glyphs restored to uniform 1DX scale (.94/.94), silhouettes placed over smaller letters, main line and DX moved down 10 texture pixels and centered. Only two assembled-title textures changed; geometry/animation and prior intro & fix identical. BG4/BCH/PNG read-back and independent SPICA equality passed. FMdl installed; every patch/Azahar-junction/SD/ZIP file matches, ZIP CRC PASS. Backup work/build/prev_title_layout_20261008/. No game launched.'
state['title_layout_20261008']={'report':'work/img/title_layout_20261008/REPORT.md',
    'recipe':'work/img/title_layout_20261008/build_title.py','preview':'work/img/title_layout_20261008/title_before_after.png',
    'reference':'user-supplied 1DX Korean title screenshot; official extracted 1DX glyph masks',
    'install':install,'runtime_verified':False,'subagents_used':False,
    'timestamp':datetime.datetime.now(datetime.timezone(datetime.timedelta(hours=9))).isoformat()}
state_path.write_text(json.dumps(state,ensure_ascii=False,indent=1)+'\n',encoding='utf8')
i4=ROOT/'work/img/I4.md'
i4.write_text(i4.read_text(encoding='utf8')+'''\n\n## 12. 타이틀 1DX 비율·실루엣 배치 수정 (2026-10-08, 사용자 화면 대조)\n- 일본어 자리에 맞춘 가로 0.695/세로 0.94 압축을 없애고, 1DX 음절 골조를 가로·세로 0.94로 다시 렌더링했다. 한글 왼쪽 X=18, 뒤의 RPG·3은 X +40.75 이동.\n- 실루엣은 1DX처럼 높은 머리 글자 옆의 낮은 글자 위로 옮겼다(마리오: 리, 루이지: 이). 윗줄과 DX·디럭스는 아래로 10픽셀, DX 중심은 X=256. 양자화 후 윗줄 가시 중심과 차이 0.5 텍스처 픽셀.\n- 첨부 화면에 등록한 근사 투영에서 실루엣 위 여백 약 18px, 좌우 여백 약 17px. 실제 게임을 실행해 확인한 수치가 아니다.\n- 레시피: `work/img/title_layout_20261008/build_title.py`; 전체 `logo2/run_all.py`에도 연결. 검토 그림의 가로 크롭을 512 전체로 수정.\n- FMdl 재읽기에서 타이틀 텍스처 두 장만 변경, 다른 텍스처·정점·뼈대·애니메이션 및 인트로 & 좌표 모두 동일. SPICA 독립 모델 판독 동일. patch/정션/SD/ZIP 동기화, ZIP CRC PASS.\n- 이전 파일: `work/build/prev_title_layout_20261008/`; 보고서·비교 그림: `work/img/title_layout_20261008/REPORT.md`, `title_before_after.png`. 게임 화면은 사용자 확인 대기.\n''',encoding='utf8')
for name in ['title_logo_JP_bottom','title_logo_JP_top']:
    target=ROOT/'work/img/logo2/out'/f'{name}.png'
    temporary=target.with_suffix('.title_layout.tmp')
    temporary.write_bytes((OUT/f'{name}.png').read_bytes());temporary.replace(target)
print('Recorded new title layout and synchronized logo2 main outputs')
