# 쿠파주니어 RPG의 R 녹색 면 경계 정리 — 2026-10-10

사용자가 지적한 왼쪽 줄기/아래 모서리에서 적갈 테가 녹색 면을 침범하는 부분을 수정했다.
제공된 한국판 1DX 「쿠파군단 RPG」 R의 곧은 줄기와 깔끔한 면/테 경계를 형태 참고로 삼았다.

## 수정

- 이전 R 분리 작업의 테두리 복원 픽셀이 면 쪽으로 들어가 있었다. 왼쪽 면 경계를 직선으로 잇고 줄기 아래를 평평한 모서리로 정리했다.
- 새 서체로 바꾸거나 R 전체를 늘리지 않았다. 알파/외곽 실루엣, 구멍, 위쪽 몸통, 오른쪽 다리는 동일하다.
- Affinity MCP의 native RGBA8 PixelReader/Writer로 x206..224/y164..196 내부만 수정했다. **독립 R 110픽셀** 변경.
- 기존 3DX 색/질감을 유지했다. 손상되지 않은 녹색 면 픽셀을 그대로 쓰고, 비어 있던 면만 원본 R에서 측정한 행별 그라데이션과 사선 결로 보완했다.
- 곧은 경계를 따라 얇은 연녹색 밝은 테를 연결해 적갈 외곽과 녹색 면이 구분되도록 했다.
- 의도한 녹색 면 내부의 적갈색 픽셀 **10 → 0**. 알파/외곽 및 crop/aligned RGBA 일치 확인.
- 18% 커진 쿠파주니어 문구, 기울기/위치/재질, 위아래 바람은 SHA256/픽셀 동일하다. 합성본은 R 부분의 **25픽셀**만 바뀌었다(나머지 수정 부위는 문구/바람 뒤에 있다).

## 검증 및 설치

- MLyt에서 실제 바뀐 파일은 `MENU_FILE_LOAD_JP_ja/timg/LOAD_GAME_IMG_KJ_R_00_JP_ja.bflim` **한 장**. 왼쪽 그림을 포함한 다른 SARC 파일/BG4 항목은 바이트 동일하다.
- 바뀐 BFLIM을 디코드한 RGB565와 입력 PNG가 정확히 일치한다.
- Codex 내장 `@oai/sky`로 Azahar 2126.1.2를 실행해 실제 KJ 모드 선택 화면에서 확인했다. 문구/바람 조립 유지, 잘림/이음새 없음.
- Ctrl+P 캡처: `Mario & Luigi Bowser's Inside…_10.10.26_00.43.23.654.png`. 정적 상단 그림 400×208과 설치 PNG의 채널 차이 최대 1, 평균 0.034271.
- 입력 프로필 변경 없이 F5 정상 중지. 서브에이전트·Orca·별도 Windows 입력 스크립트 없음.
- patch·Azahar 정션·SD 폴더·ZIP **36파일** 일치, ZIP CRC PASS, lyt_stage 동기화.
- MLyt SHA256 `2c0c382189a4737b419bb37e6595855a71962346fcce8c8bece1dc7f5917f374`.
- 배포 ZIP SHA256 `a25e5abbbc0b99a8f4e526b70878e456fb028c49f1181e37bf4514ea1b8d7c5b`.
- 메인 타이틀/인트로 FMdl, 원래 클로드 OA Affinity 파일은 동일하다.
- 직전 MLyt/ZIP 백업: `work/build/prev_kj_R_polish_20261010/`.
- `work/img/logo2/run_all.py`는 이 폴더의 `build_refined_assembly.py`를 호출한다. 이전 조립 레시피는 기본 R 파일을 유지해 이전 결과도 재현할 수 있다.

## 파일

- `R_clean.png`: 최신 투명 R 소재(60×63).
- `R_clean_aligned.png`: 기존 400×208 좌표의 R.
- `R_before_after.png`: 왼쪽 이전 / 가운데 수정 / 오른쪽 파란 배경 확인.
- `R_refined_20261010.af`: R 단독 Affinity 파일.
- `KJ_assembled_R_refined_20261010.af`: 수정 R을 반영한 전체 조립 Affinity 파일.
- `out/runtime_after.png`, `out/runtime_top.png`, `out/runtime_R_before_after.png`: 실제 게임 화면.
- `affinity_refine_R.js`, `fit_material.py`, `build_refined_assembly.py`: 재현 코드.
- `manifest.json`, `R_verify.json`, `out/R_only_verify.json`, `out/build_verify.json`, `out/install.json`, `out/runtime_verify.json`: 확인 기록.
