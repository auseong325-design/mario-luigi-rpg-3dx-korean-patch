# 타이틀 루이지 실루엣을 「마리오」 위로 이동 — 2026-10-08

사용자 요청에 따라 1DX 정발판처럼 두 실루엣을 모두 「마리오」 위에 배치했다.
참조: `C:/Users/woose/AppData/Local/Temp/codex-clipboard-23eb66b5-deb3-4511-ad3d-1ef2e1644857.png`.

- 기존 마리오는 「리」 위에 유지하고, 루이지를 「이」에서 「오」 위로 옮겼다.
- 제작 레시피 `work/img/title_layout_20261008/build_title.py`의 `silhouette_syllables`를
  `['ri', 'o']`로 변경했다. 글자 비율·크기·전체 배치와 DX·디럭스 중앙 정렬은 같다.
- FMdl 재읽기에서 타이틀 아래 텍스처 한 장만 달라졌다.
  픽셀 차이는 루이지의 이전·새 위치 주변(실루엣·외곽선·글로우)에 한정된다.
  다른 텍스처·정점·뼈대·애니메이션·인트로 & 좌표 바이트는 모두 이전 설치본과 같다.
- 첨부 화면 배율을 적용한 정지 미리보기에서 실루엣 위 여백은 약 12.5픽셀이다.
  실제 게임을 실행해 검증한 수치가 아니다.
- patch, Azahar 정션, SD 폴더, 배포 ZIP의 파일 일치와 ZIP CRC 검사를 통과했다.
  이전 FMdl·ZIP·빌드 입력 PNG는 `work/build/prev_title_silhouettes_20261008/`에 보관했다.

비교 그림: `title_before_after.png` (왼쪽 이전 배치, 오른쪽 두 실루엣이 마리오 위에 있는 배치).
검증: `build_verify.json`, `preview_metrics.json`, `install.json`.
게임 실행은 하지 않았으며 실제 표시·연출은 사용자 테스트 대상이다.


후속 사용자 지침: &를 포함한 마리오&루이지의 골조·간격을 실제 1DX와 통일하고 3DX 재질을 유지했다. 두 실루엣은 리/오 위, DX·디럭스 중앙 정렬 유지. 최신 설치 기록은 `work/img/title_1dx_shapes_20261008/REPORT.md`.
