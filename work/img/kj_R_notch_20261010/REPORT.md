# R 다리 사이 꼭짓점 및 사선 경계 정리 — 2026-10-10

사용자 확대 이미지의 두 다리 사이 꼭짓점과 아래 사선에서 밝은 테/적갈색 경계가 불규칙하게 섞여 보이는 부분을 추가 정리했다.

- 안쪽 꼭짓점을 작게 둥글려 튀어나온 밝은 점을 정리했다.
- 세로와 사선 경계를 하나의 연속된 경로로 만들고, 얇은 밝은 테의 두께를 맞췄다.
- 적갈 경계 내부의 잡색을 주변의 깊은 적갈색으로 맞췄다. 녹색 면은 직전 원본 재질 필드를 이용해 색과 사선 결을 연결했다.
- Affinity native RGBA 픽셀 편집으로 독립 R 100픽셀 수정. 알파/외곽과 좌표 보존 PNG 동일.
- 기존 18% 문구의 자형·크기·위치·재질, 바람 두 장의 픽셀/배치는 해시 동일. 합성본은 R 위치 84픽셀만 변경.
- Affinity 확대 비교 `R_notch_detail.png`: 왼쪽 직전 / 오른쪽 수정, 12배 nearest 확대. `R_before_after.png`: 직전 / 수정 / 파란 배경.
- 실제 변경 MLyt 텍스처는 KJ_R 한 장. 다른 SARC 파일과 BG4 항목 바이트 동일, RGB565 재디코드 일치.
- Codex 내장 computer-use로 Azahar 모드 선택을 직접 확인하고 Ctrl+P 캡처 후 F5 정상 중지. 입력 프로필 변경 없음.
- 실제 캡처 `Mario & Luigi Bowser's Inside…_10.10.26_01.23.09.829.png`의 상단 정적 그림과 설치 PNG 채널 차이 최대 1, 평균 0.034247.
- patch/정션/SD/ZIP 36파일 일치 및 ZIP CRC PASS. lyt_stage 동기화.
- MLyt SHA256 `44625133d32b03eab61904736a06d5b078c63505175632eac5b06905359b2149`.
- 배포 ZIP SHA256 `6d4112ff29455637f02771f8d0d4b8c8097d391c4eae07e46c975784d53b556e`.
- 원래 OA Affinity 파일 및 타이틀/인트로 FMdl 동일. 서브에이전트·Orca·별도 입력 스크립트 사용 없음.
- 직전 MLyt/ZIP 백업: `work/build/prev_kj_R_notch_20261010/`.
- 최신 레시피: `build_notch_assembly.py`, `affinity_notch_R.js`. `logo2/run_all.py` 연결 갱신.
- 소재: `R_clean.png`, `R_clean_aligned.png`, `R_notch_20261010.af`, `KJ_assembled_R_notch_20261010.af`.
