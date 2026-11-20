# 쿠파주니어 RPG 로고 조립 — 2026-10-10

사용자 요청: 기존에 제작된 쿠파주니어 자형과 복원한 R·바람을 조립한다.
R 왼쪽 위·아래의 지적된 부분은 문구 앞뒤 겹침으로 가리고, 한글 문구는 조금 키워 RPG보다 작게 한다.

## 결과

- 공식 자형 OA 벡터를 한 번에 **1.18배** 균등 확대했다. 획·음절별 비율은 바꾸지 않았다.
- 문구 전체를 기존 대비 4도 돌려 상승 기울기를 거의 수평으로 맞추었다. 마지막 「어」의 흰/노란/적갈 테두리가 R 왼쪽 줄기·아래 모서리를 덮는다.
- 가림 순서: 배경 → 복원 R → 위 바람 → 쿠파주니어 문구 → 아래 바람.
- 위 바람 원점 (36,139), 아래 바람 (214,187). R은 원래 (201,140)에 둔다.
- 한글 면 전체 범위 x=53.45..211.00, y=165.20..197.00. 외곽 포함 높이도 RPG보다 작고 하단 208행 안에 있다.
- 기존 주황 그라데이션·사선 결·붉은 가장자리와 흰/노란/적갈 외곽 재질을 유지했다. 크기에 맞춰 세로 그라데이션 범위만 맞췄다.
- `KJ_assembled_20261010.af`: 배경, R, 위 바람, 문구, 아래 바람 독립 레이어. 문구 그룹에는 실제 재질 래스터와 수정용 공식 자형/외곽 벡터가 함께 있다. 벡터는 숨김 참고 레이어다.

## 검증과 설치

- 대표 가림 좌표 (206,165), (207,175), (209,193), (210,196)의 문구 피복률 100%.
- 변경 8,018픽셀, 범위 [38, 138, 259, 206]. 별·일러스트와 P/G 면은 유지했다.
- MLyt 재읽기: KJ 좌우 BFLIM 두 장만 변경, 그 외 SARC 파일·BG4 항목은 바이트 동일. 디코드 RGB565와 입력이 정확히 같다.
- Codex 내장 `@oai/sky`로 Azahar 2126.1.2에서 슬롯1 → KJ 모드 선택을 직접 확인했다. R 두 복원 부위가 문구 뒤에 가려지고, 이음새·잘림이 없다.
- Ctrl+P 원본 캡처 `out/runtime_after.png` (400×480). 상단 정적 400×208 화면과 설치 PNG의 채널 차이 최대 1, 평균 0.034299이다.
- 입력 프로필 변경 없이 F5로 정상 중지. 서브에이전트·Orca·별도 Windows 입력 스크립트 없음.
- patch·Azahar 정션·SD 폴더·ZIP **36파일** 일치, ZIP CRC PASS, lyt_stage 동기화.
- MLyt SHA256: `cac646cfc32ac2b8dd00cba015724b6df59fcf5b03b19df1aa3a5b11f33fdc69`.
- ZIP SHA256: `495ce0be41b415e65971cbb6861af6e1a5ac2b63e5d9e38bba06bce3e61f1a88`.
- 메인 타이틀·인트로 FMdl 및 클로드의 원래 OA Affinity 파일은 SHA256 동일.
- 백업: `work/build/prev_kj_assembly_20261010/` (직전 MLyt와 배포 ZIP).
- 최신 레시피 `build_assembly.py`를 `work/img/logo2/run_all.py`에 연결해 전체 그림을 재생성해도 유지한다.

## 산출물

- `out/runtime_top.png`: 실제 Azahar 상단 화면.
- `out/runtime_R_detail.png`: 실제 R 접합부 최근접 확대.
- `out/before_after.png`: 기존 문구 크기와 조립 후 비교.
- `out/fileload_KJ_assembled.png`: 조립된 400×208 텍스처.
- `KJ_assembled_20261010.af`: 편집 가능한 Affinity 파일.
- `build_assembly.py`, `build_archive.py`, `install.py`, `affinity_assembly.js`: 재현 레시피.
- `manifest.json`, `out/assembly.json`, `out/build_verify.json`, `out/install.json`, `out/runtime_verify.json`: 확인 기록.
