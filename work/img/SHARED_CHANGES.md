# 공유 파일 변경 기록

- 2026-09-29 I5 `scripts/libbffnt.py`: KRNG(커닝) 블록 읽기·쓰기 추가(뒤로 호환). `Bffnt.krng`(블록 본문 bytes, 기본값 None)·`Bffnt.kerning()`·`parse_krng()`를 새로 두고, `parse`가 맨 끝의 KRNG 블록 하나를 받아들이며 `build`가 그대로 다시 쓴다. KRNG가 없는 폰트는 동작이 전과 같다. 검사: `build_patch.py --identity` 7/7 바이트 일치·9,623개 0 문제, 폰트 28개(romfs·ml 1dx·patch·work/build의 모든 .bffnt, KRNG 있는 `Staffroll/mario_font.bffnt` 3개 포함) parse→build 바이트 일치.
- 2026-10-02 리드(로고 v2): shapely==2.0.6 설치 (쿠파주니어 RPG 로고 글자를 다각형으로 만들고 일본판처럼 각진(miter) 테두리를 계산, work/img/logo2/kj_*.py)
- 2026-10-08 리드(인트로 & 조립 위치): `scripts/build_fmdl.py`가 `work/img/fmdl_geometry_patches.json`의 좌표 수정 레시피를 일반 빌드에 적용한다. 원본 명령 섹션 SHA-256·수정 전 바이트·명령 섹션 범위 검사와 BCH 전체 재읽기 검증을 추가했다. `--identity`/`--selftest`는 좌표 레시피를 적용하지 않아 기존 원본 검사를 유지한다. 결과 기록: `work/img/intro_fix_20261008/REPORT.md`.

- 2026-10-08 리드(1DX 로고 골조): `work/img/logo2/seg_1dx.py`의 `syllables`에 `fix_stem=True` 선택 인자를 추가했다. 기존 호출의 동작은 동일하고, 타이틀만 `False`로 실제 1DX 기둥을 사용한다. `logo2/run_all.py`에 새 타이틀 골조·인트로 & 제작 경로와 다섯 번째 타이틀 빌드 입력을 연결했다. 기록: `work/img/title_1dx_shapes_20261008/REPORT.md`.

- 2026-10-08 리드(하단 음영): `model.render`에 선택 인자 `ext_override`를 추가했다. 2D RGB·마스크를 하단 몸통에만 입히고 면·광택·기본 호출의 동작은 유지한다. `donor_layout.masks`는 선택적 `donor_masks`를 받아 지 ㅣ 끝 복원을 적용한다. 기록: `work/img/title_lower_shading_20261008/REPORT.md`.

- 2026-10-08 리드(인트로/루·지 후속): logo2/run_all.py의 이전 & 단독 제작 경로를 logo_assembly_contours_20261008/build_intro.py의 세 조각 제작 경로로 교체. fmdl_geometry_patches.json의 models를 비워 이전 좌표 이동을 해제. title_lower_shading/material.py는 루 ㅜ/지의 정상 하단 윤곽을 복원하고, title_layout/build_title.py는 승인된 RPG 면을 보존하면서 원본 띠 대신 깨끗한 몸통/글로우로 합성한다. 기록: work/img/logo_assembly_contours_20261008/REPORT.md.

- 2026-10-08 리드(모드 선택 로고): `material.geometry_and_shading`에 선택적 `output_dir`를 추가해 파일 선택용 음영 디버그 자료를 별도 폴더에 쓴다. 기본 렌더링은 동일하며 승인된 메인 타이틀 캐시 재생성 바이트 일치 확인. `logo2/run_all.py`에 최신 `fileload_logo_20261008/build_fileload.py` 경로 연결. 기록: work/img/fileload_logo_20261008/REPORT.md.
