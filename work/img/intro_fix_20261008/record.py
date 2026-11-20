from pathlib import Path
import datetime,json
ROOT=Path(__file__).resolve().parents[3];OUT=Path(__file__).parent
state_path=ROOT/'work/lead_state.json'
state=json.loads(state_path.read_text(encoding='utf8'))
install=json.loads((OUT/'install.json').read_text(encoding='utf8'))
state['updated']='2026-10-08'
state['phase']='2026-10-08 인트로 & 조립 좌표 수정·독립 모델 재읽기 검증·patch/SD ZIP 설치 완료. 기존 한글화 후속 수정 유지. 실제 인트로 연출 화면 확인 대기.'
state['build']['latest']='2026-10-08: intro & PositionOffset X/Z corrected in logo_L and logo_pch; original Korean texture pixels retained. FMdl read-back: only 4 coordinate fields/15 bytes in title BCH changed; all other model/animation bytes identical. Independent SPICA read-back and rest-pose assembly overlap check passed. build_fmdl --identity byte-identical. Installed FMdl.dat, all patch/Azahar-junction/SD/ZIP bytes match and ZIP CRC PASS. Backup work/build/prev_intro_fix_20261008/. Game not launched.'
state['intro_fix_20261008']={'report':'work/img/intro_fix_20261008/REPORT.md',
    'recipe':'work/img/fmdl_geometry_patches.json','preview':'work/img/intro_fix_20261008/assembly_verified.png',
    'verification':['work/img/intro_fix_20261008/archive_verify.json','work/img/intro_fix_20261008/geometry_verify.json','work/img/intro_fix_20261008/preview_metrics.json'],
    'install':install,'runtime_verified':False,'subagents_used':False,
    'timestamp':datetime.datetime.now(datetime.timezone(datetime.timedelta(hours=9))).isoformat()}
state_path.write_text(json.dumps(state,ensure_ascii=False,indent=1)+'\n',encoding='utf8')
i4=ROOT/'work/img/I4.md'
i4.write_text(i4.read_text(encoding='utf8')+'''\n\n## 11. 인트로 & 조립 좌표 수정 (2026-10-08, 사용자 화면 지적)\n- 한글 「마리오」의 「오」 위로 `&`가 겹침: 한글 조각은 넓어졌지만 별도 `&` 메시의 위치는 일본판 그대로였다.\n- `logo_L`와 `logo_pch`의 `title_logo_and_JP` PositionOffset X/Z를 같은 거리로 수정했다. 완성 한글 로고의 & 이동량과 배율을 적용해 로컬 X +13.64, 한글 면 밑선을 맞춰 Z −23.88. 텍스처와 애니메이션은 기존 설치본과 동일하다.\n- 재빌드 레시피: `work/img/fmdl_geometry_patches.json`; `scripts/build_fmdl.py` 일반 빌드가 자동 적용한다. `--identity`/`--selftest`는 적용하지 않는다.\n- FMdl을 다시 풀어 변경이 좌표 네 필드(실제 바이트 차이 15)에 한정됨을 검증했다. SPICA로 독립 파싱해 두 메시의 정점 이동과 나머지 모델·애니메이션 동일성을 확인했다. 정지 상태 조립 미리보기에서 &와 양쪽 한글 면의 교차는 0.\n- patch·Azahar 정션·SD 폴더·ZIP 동기화, ZIP CRC PASS. 이전 FMdl/ZIP: `work/build/prev_intro_fix_20261008/`.\n- 보고서와 비교 그림: `work/img/intro_fix_20261008/REPORT.md`, `assembly_verified.png`. 게임 실행은 하지 않았으며, 실제 인트로 연출은 사용자 확인 대기.\n''',encoding='utf8')
print('Recorded intro fix in lead_state.json and I4.md')
