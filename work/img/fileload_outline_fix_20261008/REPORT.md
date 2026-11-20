# 모드 선택 RPG·3 외곽선 수정 — 2026-10-08

모드 선택 화면의 G와 숫자 3 사이에 남은 흰색 각, 작은 흰 점과 하단의 절단 흔적을 제거했다. Codex 내장 Computer Use로 Azahar 2126.1.2 / 일본판 v1.2의 해당 화면에 직접 진입해 수정된 윤곽을 확인했다. patch·Azahar 정션·SD 폴더·배포 ZIP 설치를 완료했다.

## 원인과 수정

- 기존 레시피는 RPG 면을 사각 영역으로 추출할 때 숫자 3 쪽의 작은 광택 조각까지 포함했고, 숫자 3을 보존할 때 x=301 경계에서 원본을 통째로 덮어썼다. 새 G 외곽과 원본 숫자 외곽 사이의 사각 틈과 잔점이 생긴 원인이다.
- 실제 R/P/G 면의 연결 성분만 추출한다. 숫자 3의 면과 RPG 면까지의 거리로 원본을 보존할 영역을 정하고, 고정된 사각 덮어쓰기를 제거했다.
- G와 왼쪽 불꽃의 접합부에서 두 외곽의 피복률을 합쳐 곡선으로 연결했다. 작은 흰 구멍을 메우고 실제 반투명 경계까지 반영해 흰색 테두리 잔재를 제거했다.
- RGB565 양자화 후 변경은 203픽셀, 범위는 x=289..309 / y=24..83이다. RPG 글자 면·광택, 숫자 3의 색이 있는 전면, 한글·&와 캐릭터 그림은 그대로다. 접합부의 외곽선은 의도적으로 수정했다.
- 공통 재제작 레시피는 `work/img/fileload_logo_20261008/build_fileload.py`를 갱신했다. `logo2/run_all.py`의 기존 연결로 다시 만들어도 이 수정이 적용된다. 이전 레시피는 이 폴더의 `before_build_fileload.py`에 보관했다.

## 검사와 실제 화면

- `audit_art.py`: 변경 범위 제한, 한글·& 및 일러스트 보존, 접합부의 고립된 흰 점 제거 확인.
- `build_archive.py`: MLyt의 `MENU_FILE_LOAD_JP_ja/timg/LOAD_GAME_IMG_ML_R_00_JP_ja.bflim` 한 장만 교체했다. 다른 모든 SARC 파일·BG4 항목·레이아웃·애니메이션·쿠파주니어 로고는 바이트가 같다. 디코드한 RGB565는 양자화 입력과 정확히 일치한다.
- 메인 에이전트가 Codex 내장 `@oai/sky`로 게임 시작 → 슬롯 1 → 시작하기 → 모드 선택 화면을 조작했다. G·3 사이의 흰색 각과 점이 사라지고 둥근 테두리가 이어지는 것을 확인했다.
- Azahar Ctrl+P의 실제 캡처: `Mario & Luigi Bowser's Inside…_08.10.26_17.21.36.201.png`. 수정 전 화면은 직전 설치본을 실제로 캡처한 `fileload_logo_20261008/runtime_after.png`와 동일하다. 아래 비교는 원본 캡처를 자르고 4배 최근접 확대했으며 게임 픽셀을 보정하지 않았다.
- 이번 실행에서는 입력 프로필·설정을 바꾸지 않았다. 검증 후 F5로 에뮬레이션을 정상 중지했다. 서브에이전트·Orca·별도 Windows 입력 스크립트는 사용하지 않았다.

![실제 화면의 외곽선 수정 전후](C:/AI-Projects/mario-luigi-rpg-3dx-korean-patch/work/img/fileload_outline_fix_20261008/runtime_detail_before_after.png)

전체 화면 비교: `runtime_before_after.png`. 상세 증거: `art_verify.json`, `build_verify.json`, `runtime_verify.json`, `install.json`.

## 설치 결과

- 패치 변경 파일: `Lyt/JP/MLyt.dat` 하나. 기본 `work/build/lyt_stage/romfs/`에도 동기화했다.
- patch·Azahar 정션·SD 폴더·ZIP 36파일 모두 바이트 일치, ZIP CRC PASS.
- MLyt SHA-256: `e389a915a35ad6484262d3b763bb83c123cd620f37bb8616e0748c72b20abbb7`.
- ZIP SHA-256: `208ef79237e749794f3342a91555bb3a17e563467a82f76d90bdcf7894ffbae4`.
- 메인 타이틀·인트로 FMdl은 `2d7819214886f6e973810940ff69f4096c254cd8da30381983e52ac519cefcad`로 그대로다.
- 직전 MLyt·PNG 입력·배포 ZIP: `work/build/prev_fileload_outline_fix_20261008/`.
- 원본 게임 파일은 수정하지 않았다.
