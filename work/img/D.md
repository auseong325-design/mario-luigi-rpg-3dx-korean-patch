# D조 — 목록 제목·가이드·기록 화면 (2차 레이아웃 한글 그림) — 완료

묶음: list_title(24장), list_title_faint(2), guide_pnl(8), record_btn(9) = replace 43장 전부 완료. keep 3장(LTIT_record_BGM, btn_p_BGM, btn_p_HATENA ???)은 손대지 않음.
스크립트: `scripts/lyt_D.py` (measure / make [--only a,b] [--dry] / sheets / trial), imgtext 1.2 사용. 측정값 `work/img/D_measure.json`, 텍스처별 결과(출처·맞춤·비교) `work/img/D_make.json`, 빌드 `work/img/D_build.json`, 대조표 `work/img/review/D_*.png`.

## 1. 원본 꾸밈 측정 (imgtext.measure_style, 전부 LA4)

| 묶음 | 채움 | 테두리 | 그림자 | 글자 높이(em) | 획 | 정렬 |
|---|---|---|---|---|---|---|
| list_title | 흰색 단색. L=15 전부, 글자 모양은 알파에만 있다(테두리는 텍스처에 없음) | 없음 | 없음 | 11~12 | 2.2~2.4 | 왼쪽(원본 x0), LTIT_NOW_EQUIP만 가운데 |
| list_title_faint | 흰색, 알파만 | 없음 | 없음 | 9~10 | 1.37 | 오른쪽(x1=96) |
| guide_pnl | 밝은 회색 세로 그라데이션(위 0.85·가운데 1.0·아래 0.76) | 검정 1겹 1.75px | 없음 | 두 줄 9.5, 한 줄 10 | 2.0 | 가운데 |
| record_btn | guide_pnl과 같음 | 검정 1겹 1.75px | 없음 | 두 줄 9.5, 한 줄 10~12 | 2.0~2.4 | 가운데 |

1DX 참고 그림은 꾸밈이 다르다(1DX 목록 제목 = 회색 그라데이션 + 검은 테두리, 글자 8px) → 전부 kind 나 방식(글자만 1DX, 꾸밈은 3DX).

## 2. 정한 것

- 글자 출처
  - list_title·guide_pnl·record_btn: **1DX 대화 폰트 `font.bffnt`(한글 15px)를 12px로 축소**(imgtext `source="font"`, 폰트 후보를 font로 한정).
  - list_title_faint: imgtext 1.2 기본값 = **1DX `font_btl`(11px) 원래 크기, 픽셀 격자 맞춤**.
  - 시험하고 버린 것: ① 1DX 그림의 같은 낱말(1순위) — 1DX 목록 제목 글자는 테두리까지 뭉친 10px라 키우면 뭉개지고, 16px 버튼 글자를 12px로 줄인 것도 폰트보다 흐림. ② font_btl 원래 크기(1.2 기본값) — 선명하지만 「틀」「블」의 자모 틈이 반투명 줄이라 굵히면 덩어리가 된다(배틀·블록·블로즈 등 7장). faint 두 장은 촘촘한 음절이 없어 font_btl 그대로.
- 크기: list 12 / faint = 원본(9~10) / guide 12(두 줄도 12, 줄 3-15·16-28) / record 12. 원본 가나보다 약 1px 크다.
- 굵기: list 1.8px, guide·record 1.9px(imgtext 틈 보호 굵히기), faint = 원본 획. 결과는 원본 가나 획의 약 0.7~0.85배. 더 굵히면 한글 가로획이 붙는다.
- 선명도: 15→12px 축소 뒤 덮임(알파·테두리 안쪽 채움)을 0.5 중심 1.5배로 대비를 키우고, 1/4px 위치 20가지 중 반투명 픽셀이 가장 적은 것을 고른다(`sharpen`, `blur_metric`). faint는 격자 맞춤이라 끔.
- 꾸밈: list·faint = 흰 알파만(L=15 전부, 원본과 같음). guide·record = 검정 1.75px 1겹 + 묶음 평균 그라데이션(모든 텍스처 같은 값).
- **record_btn 두 줄 3장은 한 줄로**: 88×24 칸에 한글 두 줄은 10px밖에 안 돼 읽히지 않는다. 「어택 미니 게임」「어택피스」(용어집대로 붙여 씀)「배틀 콜로세움」 12px 한 줄(폭 44~76px / 칸 88px). guide_pnl(96×32)은 두 줄 유지.
- kind 가 2장(LTIT_record_BLOCK, btn_p_BLOCK): 1DX 그림 글자가 위 이유로 흐려서 같은 묶음의 폰트 방식으로 만들었다.

## 3. 검증

- `build_lyt.py --out work/build/lyt_stage_D --report work/img/D_build.json`: OK, errors 0, warnings 0. D조 43장 전부 적용(복사본 포함 50곳). (빌드는 그때 `work/img/ko/`에 있던 다른 조 그림까지 함께 넣은 확인용이다.)
- 대조표(원본 / 한국어 / 1DX 참고, 1배 + 3배): `work/img/review/D_list_title_01~03.png`, `D_list_title_faint.png`, `D_guide_pnl_01~02.png`, `D_record_btn_01~02.png`, 묶음 전체 3배 `D_*_all.png`. 직접 보고 확인함.

## 리드 확인
1. 글자 출처를 1순위(1DX 그림 같은 낱말) 대신 3순위(1DX font.bffnt, faint는 font_btl)로 통일.
2. 획 두께가 원본 가나의 약 0.7~0.85배(±10% 밖). 한글이 뭉개지지 않게 한 선택.
3. 글자 높이 12px(원본 가나 10~12px).
4. 기록 버튼 두 줄 3장을 한 줄로(어택 미니 게임 / 어택피스 / 배틀 콜로세움). lyt_plan `ko`의 줄바꿈과 다르다.
5. 「블」「틀」이 든 낱말(블록 2장, 블로즈, 배틀 6장)은 12px에서 가장 빽빽하다. 게임 화면에서 확인 필요.
6. `LTIT_NOW_EQUIP`「장비 중」은 새로 지은 말(lyt_plan basis=coined), 「베스트 스코어」「베스트 턴」「보스 배틀」도 coined.
