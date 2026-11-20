# R 왼쪽 경계·빈 부분·덧칠 이음선 추가 정리 — 2026-10-10

사용자가 올린 세 확대 이미지는 직전 `kj_R_polish_20261010/R_before_after.png`의 수정 열과 정확히 일치했다(RGB RMSE 0).
해당 위치를 원래 R 좌표로 환산해 추가 수정했다. 이전 작업과 기록은 보존한다.

## 수정한 부분

- 왼쪽 줄기의 녹색 면 경계를 약 1픽셀 바깥으로 옮겨, 남은 적갈색 침범과 경계의 빈칸을 정리했다.
- 아래 모서리는 기존 외곽 안에서 녹색 면을 이어 채웠다. 외곽 알파·구멍·위 몸통·오른쪽 다리는 동일하다.
- 지난 작업에서 추가한 밝은 하단 가장자리 효과를 제거했다. 이 효과와 불연속적인 면 색이 합쳐져 덧칠 이음선처럼 보였다.
- 원본 R의 노랑→초록 색과 사선 결을 측정하고, 행별 색을 부드럽게 연결한 뒤 원본 색 잔차를 주변 면에서 이어 받았다. Affinity native RGBA writer로 실제 픽셀을 적용했다.
- 사선 결 각도/주기는 기존 원본 측정값 59도/3.7픽셀. 새로운 서체나 다른 팔레트를 쓰지 않았다.
- 독립 R **300픽셀** 변경. R 알파 및 좌표 보존 PNG 일치 확인.
- 새로 넓힌 줄기 면 내부의 어두운 적갈 픽셀 16→0. 색상 경사 내부의 최대 행간 RGB 변화 24.39→6.94. 이는 그림의 연속성 확인 수치이며 모든 시각적 취향을 판정하는 수치는 아니다.
- 이전처럼 18% 확대된 쿠파주니어 문구의 자형·위치·기울기·재질 및 두 바람은 파일 해시 동일. 실제 합성본은 R 위치의 **96픽셀**만 바뀌었다.

## 실제 화면 및 설치

- Affinity의 R 확대 비교와 조립본을 직접 렌더링해 확인했다.
- Codex 내장 computer-use로 Azahar 2126.1.2 실행 → 쿠파주니어 RPG 모드 선택 → Ctrl+P 원해상도 캡처 → F5 정상 중지.
- 원해상도 캡처 `Mario & Luigi Bowser's Inside…_10.10.26_01.05.39.294.png`. 상단 정적 그림 400×208과 빌드 입력의 채널 차이 최대 1, 평균 0.034243.
- 실제 바뀐 MLyt 텍스처는 `MENU_FILE_LOAD_JP_ja/timg/LOAD_GAME_IMG_KJ_R_00_JP_ja.bflim` 한 장. 나머지 SARC 파일과 BG4 항목은 바이트 동일, 재디코드 RGB565 일치.
- patch/Azahar 정션/SD 폴더/배포 ZIP **36파일** 일치, ZIP CRC PASS, lyt_stage 동기화.
- MLyt SHA256 `c3acd2cf8c91e813db48b12a2de968893cfeea60290fccb316a4d9942e403bd3`.
- 배포 ZIP SHA256 `568f0a33457eae514e17ca753881c1eeb110f2570237c97cb947add3a36aeca7`.
- 직전 패치와 ZIP 백업: `work/build/prev_kj_R_touchup_20261010/`.
- 원래 OA Affinity 문서와 타이틀/인트로 FMdl은 해시 동일. 서브에이전트·Orca·Windows 별도 입력 스크립트 없음.
- `logo2/run_all.py`는 최신 `build_touchup_assembly.py`로 연결했다.

## 소재 및 편집 파일

- `R_clean.png`: 투명 R 60×63.
- `R_clean_aligned.png`: 400×208의 기존 좌표.
- `R_before_after.png`: 왼쪽 직전 / 가운데 추가 수정 / 오른쪽 배경 확인.
- `R_detail_before_after.png`: 침범·빈칸·이음선 부분(위 직전, 아래 수정).
- `R_touchup_20261010.af`: R 단독 편집본.
- `KJ_assembled_R_touchup_20261010.af`: 문구·R·바람 독립 레이어를 유지한 전체 편집본.
- `out/runtime_top.png`, `out/runtime_R_before_after.png`: 실제 게임 화면 및 확대 비교.
- `affinity_touchup_R.js`, `prepare_colours.py`, `colour_field.json`: native 수정 및 수치 자료.
- `KJ_R_touchup_editable_20261010.zip`: 최신 소재·문구 벡터·바람·Affinity 편집본·레시피·기록 묶음.
