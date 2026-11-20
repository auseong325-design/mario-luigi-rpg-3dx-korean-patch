# 모드 선택 화면 로고 갱신 — 2026-10-08

사용자가 첨부한 흰 배경의 모드 선택 화면에서 「마리오&루이지 RPG3」 로고를 최신 메인 타이틀과 같은 글자 형태·재질로 갱신했다. Codex 내장 Computer Use로 Azahar 2126.1.2 / 일본판 v1.2를 직접 조작해 실제 표시를 확인했다. patch·Azahar 정션·SD 폴더·배포 ZIP 설치 완료.

## 그림과 빌드

- 「마·리·오·&·루·이·지」는 1DX 한국판의 실제 글자 면과 상대 위치를 사용한다. 가로·세로 배율은 모두 0.618098이며, 글자를 납작하게 압축하지 않는다.
- 최신 타이틀의 둥근 「지」 ㅣ 윗끝, 승인된 「루」 ㅜ와 「지」 하단 입체 윤곽, 1DX 하단 음영 무늬를 반영했다. 색·광택·테두리·입체 음영은 최신 3DX 일본판 측정 재질을 따른다.
- RPG는 원판 글자 면과 광택을 그대로 재표본화하고 가로·세로 0.78배로 맞춰 한글과 비율을 조정했다. 숫자 3과 마리오·루이지·쿠파 일러스트는 원판 픽셀을 보존한다.
- 전체 400×208 그림을 먼저 만든 뒤 x=144에서 두 장으로 나눴다. 원래 화면 레이아웃과 애니메이션은 유지한다.
- `build_fileload.py`가 최종 그림 레시피다. `work/img/logo2/run_all.py`의 기본 그림 제작 뒤에 연결했고 두 PNG를 `work/img/ko/lyt/MLyt/MENU_FILE_LOAD_JP_ja/`와 logo2/out에 반영했다.
- 설치 직전 MLyt를 기준으로 `build_archive.py`에서 해당 BFLIM 두 장만 교체했다. 아카이브 재읽기로 다른 모든 SARC 파일과 다른 BG4 항목의 바이트가 같은 것을 확인했다. RGB565 디코드 결과는 양자화한 입력 그림과 정확히 같다.
- 공통 `material.geometry_and_shading`에 선택 인자 `output_dir`를 추가해 파일 선택용 디버그 마스크가 메인 타이틀 캐시를 덮어쓰지 않게 했다. 기본 호출의 렌더링은 동일하다. 메인 타이틀을 다시 생성해 승인된 bottom/top PNG의 바이트가 같은 것도 확인했다(`restore_title_cache.py`).

## 실제 Azahar 확인

갱신 전·후 네이티브 스크린숏은 Azahar Ctrl+P로 저장했다. 갱신 후에는 내장 Computer Use의 터치 드래그 및 더블클릭으로 게임 시작 → 슬롯 1 → 시작하기 → 모드 선택 화면에 진입했다. 새 한글과 &가 표시되고, 좌우 그림 경계의 이음새와 글자 잘림이 보이지 않는 것을 확인했다. 위·아래 화면의 메뉴도 정상 표시된다. 저장 데이터의 삭제·복사나 실제 게임 시작은 수행하지 않았다.

입력 설정은 원래 `Default`가 게임패드용 프로필이어서 별도 `Codex Logo QA` 프로필에 Azahar 기본 키보드 설정을 적용했다. 짧은 키 입력에는 게임이 반응하지 않아 화면 버튼을 터치 조작으로 진행했다. 검증 후 F5로 에뮬레이션을 정상 중지하고, 기존 `Default` 게임패드 프로필을 다시 선택·적용했다. `Codex Logo QA`는 비활성 검증용 프로필로 남아 있다. 기존 Default의 버튼·스틱 설정은 보존됐다. 서브에이전트·Orca·별도 Windows 입력 스크립트는 사용하지 않았다.

비교 그림은 실제 Azahar 네이티브 스크린숏에서 상단 400×240 화면만 잘라 나란히 둔 것이다. 설명 문구는 스크롤 중이어서 캡처 시점이 서로 다르다.

![갱신 전후 실제 화면](C:/AI-Projects/mario-luigi-rpg-3dx-korean-patch/work/img/fileload_logo_20261008/runtime_before_after.png)

## 설치·보존 확인

- 변경된 패치 파일: `Lyt/JP/MLyt.dat` 하나. 변경된 텍스처는 `LOAD_GAME_IMG_ML_L_00_JP_ja.bflim`, `LOAD_GAME_IMG_ML_R_00_JP_ja.bflim` 두 장.
- 메인 타이틀·인트로 FMdl SHA-256은 `2d7819214886f6e973810940ff69f4096c254cd8da30381983e52ac519cefcad`로 그대로다. 쿠파주니어 로고와 나머지 MLyt 파일도 동일하다.
- patch·Azahar 정션·SD 폴더·ZIP의 36파일 모두 바이트 일치. ZIP CRC PASS. 최종 MLyt는 `work/build/lyt_stage/romfs/Lyt/JP/MLyt.dat`에도 보관했다.
- MLyt SHA-256: `0e6519193d9b62d4951bee9b3f2fa02f6e0c3cea81b1ab4551223da3ff698f26`.
- 배포 ZIP SHA-256: `a23f3090f53a183596a3f7a7258505721e96f236c200b8630e6f3f3566d03498`.
- 이전 MLyt·그림 입력·배포 ZIP: `work/build/prev_fileload_logo_20261008/`.
- 원본 게임 파일은 수정하지 않았다. 상세 검사 결과는 `art_metrics.json`, `build_verify.json`, `runtime_verify.json`, `install.json`에 기록했다.

## 후속 외곽선 수정 (2026-10-08)

사용자가 추가 지적한 G·3 접합부의 흰색 각·점과 하단 절단 흔적을 수정했다. 이 문서의 설치 해시는 당시 기록이며 최신 설치 결과·실제 검증은 `work/img/fileload_outline_fix_20261008/REPORT.md`에 있다. 같은 `build_fileload.py`를 갱신했다. 숫자 3의 색이 있는 전면은 보존하고 접합부 외곽만 곡선으로 연결했다.
