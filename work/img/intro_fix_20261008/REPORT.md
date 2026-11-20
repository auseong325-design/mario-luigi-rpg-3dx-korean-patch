# 인트로 로고의 & 조립 위치 수정 — 2026-10-08

사용자 화면 `C:/Users/woose/Downloads/2026-10-08_11-40-50.791_top.bmp`에서
`&`가 「마리오」의 「오」 위에 겹치는 문제를 확인했다. 현재 한글 로고 조각은
기존에 확정한 1DX 글자 골조를 그대로 사용한다.

## 원인과 수정

완성 로고의 한글 배치에서는 일본어판보다 `&`가 오른쪽으로 15.5 텍스처 픽셀 이동했다.
하지만 인트로에서 쓰는 별도 `&` 모델은 일본어판의 좌표가 남아 있었다.
또한 한글 「마리오」「루이지」 조각은 64픽셀 높이에 맞춰 제작하면서 면의 밑선이
바뀌었으므로, `&`의 높이도 한글 조각에 맞춰야 한다. 오른쪽 이동만 적용한 중간
미리보기에서는 「루이지」의 「루」와 겹쳤다.

- `logo_L`의 루이지와 함께 움직이는 `&`, `logo_pch`의 조립 상태 `&` 두 메시를 수정했다.
- 완성 로고 배율 0.66과 인트로 배율 0.75를 적용해 X를 로컬 좌표 +13.64
  (월드 좌표 +10.23) 이동했다.
- 한글 「마리오」 면의 밑선과 완성 로고의 `&` 밑선 차이를 적용해 Z를 로컬 좌표
  −23.88 (월드 좌표 −17.91, 화면상 아래) 이동했다.
- 메시의 PICA uniform6 PositionOffset에서 X/Z 네 필드만 수정했다.
  깊이(Y), 원본 텍스처, 정점 버퍼, 뼈대와 애니메이션 데이터는 이전 설치본과 같다.

레시피는 `work/img/fmdl_geometry_patches.json`에 저장했다.
`scripts/build_fmdl.py`는 일반 빌드 때 이 레시피도 적용하므로 재빌드해도 수정이 유지된다.
원본 명령 섹션 SHA-256과 각 수정 전 바이트를 검사하고, 수정은 같은 길이로 덮어쓴다.
`--identity`와 `--selftest`는 한국어 좌표 수정을 적용하지 않는다.

## 검증과 설치

- FMdl BG4의 366개 엔트리 중 실제 변경 모델은 `fmd_title_JP_ja` 하나다.
  이 모델의 626,980바이트 중 차이는 네 좌표 필드의 15바이트뿐이다.
  텍스처 바이트와 그 밖의 모델·애니메이션 바이트는 모두 이전 설치본과 같다.
- 빌드한 BG4를 다시 풀어 네 필드 수정 결과와 전체 BCH 바이트를 대조했다.
- 기존 SwitchToolbox의 SPICA 라이브러리로 BCH를 별도로 읽었다.
  두 `&` 메시의 네 정점이 예상한 X/Z 거리만큼 이동했고, 나머지 모델 정보와
  애니메이션은 모두 동일했다.
- 다시 읽은 정점과 뼈대 좌표로 기본 조립 상태를 정사영 렌더링했다.
  8배 샘플링한 밝은 글자 면의 교차 샘플 수는 수정 전 「마리오」와 1,680,
  수정 후 「마리오」·「루이지」 모두 0이다.
  이 수치는 정지 상태와 해당 면 판별 마스크에 대한 검사이며, 전체 애니메이션 실기 검증은 아니다.
- `build_fmdl.py --identity`: 원본 16,018,524바이트 일치, 12개 모델 텍스처 자기 교체 일치.
- `patch/00040000001CA900/romfs/FMdl/JP/FMdl.dat`에 설치했다.
  Azahar 모드 정션, SD 폴더, ZIP의 모든 패치 파일을 대조했고 ZIP CRC 검사도 통과했다.
- 이전 FMdl과 ZIP은 `work/build/prev_intro_fix_20261008/`에 보관했다.

비교 그림: `assembly_verified.png` (위 BEFORE, 아래 AFTER).
게임을 실행하지 않았으며, 실제 인트로의 조립·이동 연출은 사용자 화면 확인 대상이다.

## 재현

프로젝트 루트에서 타임아웃 래퍼를 사용한다.

```powershell
.venv\Scripts\python -X utf8 work/img/intro_fix_20261008/run_checked.py rebuild 300 scripts/build_fmdl.py
.venv\Scripts\python -X utf8 work/img/intro_fix_20261008/run_checked.py identity 120 scripts/build_fmdl.py --identity
```

일회성 진단·설치 도구는 이 폴더에 남겼다. `verify_archive.py`와 `install.py`는
수정 전 설치본을 기준으로 검사하므로, 이미 설치한 뒤 그대로 재실행하는 도구가 아니다.
독립 검증 결과는 `archive_verify.json`, `geometry_verify.json`, `preview_metrics.json`,
설치 결과는 `install.json`에 있다.
