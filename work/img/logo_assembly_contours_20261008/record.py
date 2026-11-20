from pathlib import Path
import hashlib,json,shutil
ROOT=Path(__file__).resolve().parents[3];OUT=Path(__file__).parent
install=json.loads((OUT/'install.json').read_text())
assert install['all_sd_and_zip_files_match'] and install['zip_crc_check']=='PASS'
art=json.loads((OUT/'art_verify.json').read_text())
build=json.loads((OUT/'build_verify.json').read_text())
default_stage=ROOT/'work/build/fmdl_stage/romfs/FMdl/JP/FMdl.dat'
temporary=default_stage.with_name(default_stage.name+'.assembly_contours_20261008.tmp')
assert not temporary.exists()
temporary.write_bytes((OUT/'after_fmdl.dat').read_bytes());temporary.replace(default_stage)
assert hashlib.sha256(default_stage.read_bytes()).hexdigest()==install['fmdl_sha256']
(OUT/'default_stage_sync.json').write_text(json.dumps({'stage':str(default_stage),'matches_installed':True},indent=2)+'\n',encoding='utf8')
report='''# 인트로 조립·루/지 하단 윤곽 수정 — 2026-10-08

사용자 첨부 1번의 조립 어긋남, 3/4번의 루 ㅜ 아래 입체면 차이, 5/6번의 지 아래 겹쳐 보이는 테두리를 수정하여 patch·Azahar 정션·SD 폴더·배포 ZIP에 설치했다. 서브에이전트와 에뮬레이터를 사용하지 않았다.

## 인트로

앞선 수정은 두 & 메시의 PositionOffset 네 필드만 옮겼다. 당시 정지 상태 파싱/합성에서는 겹침이 없었으나 사용자가 실제 인트로에서 다시 어긋남을 신고했다. 이전 텍스처를 일본판 원래 좌표로 투영하면 첨부와 유사한 &의 높은 위치와 오 겹침이 재현된다. 게임이 어느 렌더링 경로를 사용했는지는 이번 파일 검사만으로 확정하지 않는다.

이번에는 마리오·&·루이지 세 텍스처를 함께 다시 제작했다. 1DX의 실제 글자 면과 상대 간격을 공통 가로=세로 0.60배로 옮기고, 일본판 원래 조각 사각형과 뼈대 좌표에서 같은 밑선에 놓이도록 각 텍스처 안의 위치를 계산했다. 원래 부모 배율은 0.75, 공통 기준 밑선은 월드 Z=111.375다. 두 & 메시의 과거 수정은 해제했고 원본 메시·뼈대·애니메이션을 사용한다. 3DX의 색·광택·입체 재질과 승인된 지 ㅣ 끝 형태를 적용했다.

SPICA의 실제 GetFrameValue 곡선으로 0~370프레임을 읽었다. 조립 상태 0~159의 160프레임에서 &와 마리오/루이지 글자 면의 교차는 각각 0픽셀, 공통 밑선의 최대 차이는 약 0.0864 월드 단위다. 160 이후는 원래의 회전/비행/분리 연출이므로 조립 상태 정렬 검사와 구분했다. 전체 371프레임 좌표가 유한하며, 루이지에 붙은 & 복사본과 조립 모델의 상대 위치도 일치한다. 텍스처 가장자리의 최대 알파는 마리오 17, 루이지/& 0이며 불투명 본체가 잘리지 않는다.

## 타이틀 하단

루 ㅜ와 지의 아래 외곽은 최근 1DX 하단 외곽 이식으로 달라진 부분이다. 해당 면 아래에서 이전 정상 로고에 쓰던 3DX의 연속 입체면/외곽을 복원했다. 색은 최근의 1DX 2D 음영 무늬를 3DX 일본판 빨강·초록·청록 곡선으로 옮긴 재질을 유지한다. 그 외 글자 아래 외곽은 현재 1DX 이식 형태를 유지한다.

RPG 주변은 원본 일본어 그림의 오른쪽 띠 전체를 복사하던 처리를 없애고, 승인된 RPG 글자 내부 픽셀 위에 깨끗한 몸통·글로우를 다시 합성했다. 원본 띠에 포함되는 다른 도형이 따라오는 경로를 없앴다. 지의 문제 윤곽은 한글 하단 외곽의 변화로 확인되며 일본어 글자 잔재라고 단정하지 않는다.

마·리·오·&·루·이·지의 면 마스크, 글자 배율/간격, 둥근 지 ㅣ 끝, 실루엣 리/오 위치가 직전 설치본과 모두 같다. RPG를 포함한 내부 색·광택 10,092픽셀이 같다. 숫자 3·DX·디럭스 상단 텍스처는 바이트/픽셀 단위로 같다. 중앙 정렬과 전체 제목 배치도 유지했다.

## 빌드·설치 검증

- FMdl의 변경 모델은 fmd_title_JP_ja 하나이며, bottom/M/L/and 텍스처 네 장과 원본으로 되돌린 좌표 네 필드만 달라졌다.
- 이 범위를 치환하면 나머지 BCH 바이트가 직전 설치본과 모두 같다. 명령 섹션 전체는 v1.2 원본과 같다.
- SPICA 독립 파싱 결과 모델 전체가 일본판 원본과 같고 뼈대/가시성 애니메이션은 직전 설치본과도 같다.
- 새 FMdl에서 디코드한 교체 이미지 네 장이 입력 PNG와 정확히 같다.
- patch·Azahar 정션·SD 폴더·ZIP의 패치 파일 36개가 일치하며 ZIP CRC 검사는 PASS다.
- 원본 게임 파일은 수정하지 않았다. 실제 게임에서의 인트로/타이틀 확인은 사용자 확인 대기다.

기본 fmdl_stage 파일은 직접 쓰기에서 Windows 오류가 나 새 경로 after_fmdl.dat에 빌드한 뒤 검증·설치했다. 이후 임시 파일 교체 방식으로 기본 fmdl_stage도 동기화했다. 빌드 입력과 logo2/out 다섯 이미지도 최신으로 맞췄다.

## 파일

- 재제작: build_intro.py, ../title_layout_20261008/build_title.py, ../title_lower_shading_20261008/material.py
- 전체 파이프라인: ../logo2/run_all.py (main-title + 세 intro 조각 연결)
- 좌표 레시피: ../fmdl_geometry_patches.json (models 빈 객체, 과거 수정 해제)
- 인트로 비교: intro_fix_preview.png (위: 이전 텍스처/원래 좌표, 아래: 수정), animation_samples.png
- 윤곽 비교: title_details_before_after.png (왼쪽: 이전, 오른쪽: 수정; 루/지 두 행)
- 전체 제목 근사 투영: title_before_after.png
- 근거: art_verify.json, animation_verify.json, build_verify.json, install.json
- 직전 FMdl·ZIP·빌드 입력 백업: work/build/prev_logo_assembly_contours_20261008/
- 이전 레시피·좌표 백업: recipes_before/
- 배포: work/sd_package/ml3dx_ko_luma.zip

'''
report+=f"설치 FMdl SHA-256: `{install['fmdl_sha256']}`\n\n배포 ZIP SHA-256: `{install['zip_sha256']}`\n"
(OUT/'REPORT.md').write_text(report,encoding='utf8')
state_path=ROOT/'work/lead_state.json'
state=json.loads(state_path.read_text(encoding='utf8'))
state['updated']='2026-10-08'
state['phase']='2026-10-08 인트로 마리오/&/루이지 세 조각을 원래 애니메이션 좌표에서 공통 밑선으로 재제작. 타이틀 루 ㅜ/지 아래 정상 외곽 복원. patch/SD ZIP 설치 완료, 실제 게임 화면 확인 대기.'
state['build']['latest']='2026-10-08: Rebuilt all three intro textures with a uniform 1DX transform on ORIGINAL mesh coordinates; retired four ampersand-only coordinate fields. SPICA native curves checked 371 frames; 160 assembled frames have zero Mario/& and Luigi/& face overlap and <=0.0864 world-unit baseline difference. Restored approved lower ru/ji sweeps with current 3DX shading; clean RPG body composition. All main face masks/silhouettes, 10,092 face/gloss pixels and DX/3 texture equal. Only four title textures and original coordinate restoration changed; independent SPICA geometry matches original, animations unchanged. All 36 patch/junction/SD/ZIP files equal, CRC PASS. Backup work/build/prev_logo_assembly_contours_20261008/. No game launched.'
key='logo_assembly_contours_20261008'
state[key]={'status':'installed; user runtime check pending',
            'report':'work/img/'+key+'/REPORT.md',
            'intro_recipe':'work/img/'+key+'/build_intro.py',
            'intro_preview':'work/img/'+key+'/intro_fix_preview.png',
            'contour_preview':'work/img/'+key+'/title_details_before_after.png',
            'main_title_face_masks_and_silhouettes_unchanged':True,
            'original_mesh_commands_restored':True,'animation_checks':art['animation_checks'],
            'install':install,'default_stage_matches_installed':True}
if 'title_lower_shading_20261008' in state:state['title_lower_shading_20261008']['superseded_by']=key
item='2026-10-08 logo_assembly_contours: actual intro assembly Mario/&/Luigi alignment and main-title ru ㅜ/ji lower contour after latest FMdl install (file/animation checks PASS; emulator not launched)'
if item not in state['review_items']:state['review_items'].append(item)
state_path.write_text(json.dumps(state,ensure_ascii=False,indent=1)+'\n',encoding='utf8')
note='''

## 16. 인트로 세 조각 정렬과 루/지 하단 윤곽 복원 (2026-10-08)
- 사용자 실제 화면에서 &의 겹침이 재신고되어, 이전 & 전용 좌표 수정 대신 세 조각 텍스처에 공통 1DX 배율/밑선을 적용했다. 원래 메시 명령 섹션을 복원했고 뼈대·애니메이션은 그대로다.
- SPICA 실제 곡선 371프레임 판독, 조립 상태 160프레임에서 글자 면 교차 0, 밑선 차이 최대 0.0864 월드 단위. 루이지와 함께 있는 & 복사본도 조립 모델과 상대 위치가 같다.
- 루 ㅜ/지 아래는 사용자 정상 예시의 이전 입체 윤곽을 복원. 최근 1DX 무늬를 3DX 색으로 옮긴 재질은 유지. RPG 오른쪽 원본 그림 띠 합성을 깨끗한 몸통/글로우와 승인된 면 픽셀 합성으로 교체.
- 메인 글자 마스크·실루엣·내부 색/광택 10,092픽셀, 숫자3/DX/디럭스 텍스처 동일. 변경은 타이틀 bottom/M/L/and 네 장과 원래 좌표 복원 네 필드뿐이며, SPICA 모델 전체는 원본과 같다.
- patch/정션/SD/ZIP 36파일 일치, CRC PASS. 기본 fmdl_stage도 동기화. 백업: work/build/prev_logo_assembly_contours_20261008/.
- 최신 보고서·비교: work/img/logo_assembly_contours_20261008/REPORT.md, intro_fix_preview.png, title_details_before_after.png. §11의 좌표 레시피는 해제되었으며 models={}다. 실제 게임 실행은 사용자 확인 대기.
'''
log=ROOT/'work/img/I4.md'
with log.open('a',encoding='utf8') as f:f.write(note)
shared=ROOT/'work/img/SHARED_CHANGES.md'
with shared.open('a',encoding='utf8') as f:
    f.write('\n- 2026-10-08 리드(인트로/루·지 후속): logo2/run_all.py의 이전 & 단독 제작 경로를 logo_assembly_contours_20261008/build_intro.py의 세 조각 제작 경로로 교체. fmdl_geometry_patches.json의 models를 비워 이전 좌표 이동을 해제. title_lower_shading/material.py는 루 ㅜ/지의 정상 하단 윤곽을 복원하고, title_layout/build_title.py는 승인된 RPG 면을 보존하면서 원본 띠 대신 깨끗한 몸통/글로우로 합성한다. 기록: work/img/logo_assembly_contours_20261008/REPORT.md.\n')
print('Updated report, lead_state, I4 log and shared changes; standard stage matches installed FMdl')
