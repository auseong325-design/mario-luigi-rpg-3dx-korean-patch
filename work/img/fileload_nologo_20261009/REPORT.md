# 모드 선택(마리오&루이지 RPG3) 배경 — 로고 제거판 · 2026-10-09

로고를 나중에 별도 레이어로 얹기 위해, 모드 선택 그림에서 「マリオ&ルイージRPG3」 로고를 지운 배경을 만들어 설치했다. 쿠파주니어 RPG 쪽 그림은 건드리지 않았다.

- 원본: 일본판 `work/img/lyt/3DX/MLyt/MENU_FILE_LOAD_JP_ja/LOAD_GAME_IMG_ML_{L,R}_00_JP_ja.png`(400×208, x=144에서 분할).
- 로고 자리는 흰색으로 지우고, 숫자 3·테두리에 가려졌던 쿠파 머리(머리털·뿔·뿔 고리·이마)는 사용자가 준 박스아트 쿠파 `bowser_boxart.png`로 채웠다.
  - 정합: SIFT+RANSAC 유사변환 후 로고 없는 영역에서 오차 최소화(`register.py`, `regcmp.py` → `warp_best.npy`, 배율 ≈0.336).
  - 색: 로고 아래 쿠파 픽셀로 RGB 아핀 보정 후 사용. 로고가 덮었던 픽셀만 교체(경계 1px 페더), y≥95 행은 원본과 바이트 동일.
- 레시피 `build_nologo.py` → `build_archive.py`(MLyt에서 ML 텍스처 2장만 교체, RGB565 디코드 일치) → `install.py`.
- 설치: patch·Azahar 정션·SD 폴더·ZIP·lyt_stage. MLyt SHA-256 `2162a8ff…2013`. 직전(로고 있는 판) MLyt·ZIP 백업: `work/build/prev_fileload_nologo_20261009/`.
- `work/img/ko/lyt/…`와 `logo2/out`의 로고판 PNG는 그대로 두었다(로고 합성 작업 때 이 배경을 바탕으로 쓴다).
- Azahar 실제 화면 확인은 아직 하지 않았다.
