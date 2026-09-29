# C 조 진행 기록 (2차 — 전투·결과·미니게임 레이아웃 한글 그림)

대상 묶음: battle_btn(6), rank_name(11), stat_en(7 교체 / 21), panel_label(2), field_btn(2), minigame_btn(5), result_banner(3) = 36장.

## 원본 꾸밈 관찰 (묶음 대조표 + 픽셀 덤프)

- battle_btn: 흰 채움 + 검은 굵은 테두리(약 2px) + 오른쪽 아래 그림자(검정, 테두리와 이어짐). 가운데 정렬. btn_USE만 ETC1A4.
- rank_name: 흰 채움 + 남색 테두리 + 오른쪽 아래 남색 그림자(입체). 가운데 정렬. ETC1A4 128x42.
- stat_en (교체 7장):
  - STbr_* 60x16 LA4: 픽셀 영문 글꼴(글자 높이 8행 y4–11), 흰 채움, 왼쪽·위 옅은 가장자리, 아래 회색 한 줄(입체) + 검은 테두리/그림자(아래·오른쪽 2px). 1DX STbr는 글꼴·테두리 모양이 달라(키 11행, 사방 테두리) 꾸밈이 맞지 않는다 → 1DX 그림 재사용(가) 대신 3DX 같은 판 글자에서 재조합(나).
  - ST_* / KJ_ST_* 42x12 LA4: 흰 글자만(테두리 없음, 알파만), 7행(y2–8). 1DX ST_GDD(36x16, 검은 테두리)는 모양이 달라 역시 3DX 글자로 재조합.
- panel_label: 흰 글자만(테두리 없음), 128x16 LA4.
- field_btn: 흰 채움 + 검은 테두리, 오른쪽 정렬, 64x16.
- minigame_btn: 흰 채움 + 검은 굵은 테두리, 두 줄 3개.
- result_banner: 흰 채움 + 남색 테두리(베스트…), GET_PRIZE는 LA4 검은 테두리 + 원본 GET! 유지.

## 계획

1. stat_en: 3DX 원본에서 글자 채움 마스크를 떼어 픽셀 글꼴을 만들고, 원본 꾸밈을 이웃 픽셀 대응표(원본 7장에서 학습)로 다시 입힌다. 없는 글자 Y·M·L은 같은 격자에서 새로 그린다. 원본 재현 오차로 검증.
2. 한글 묶음: READY 이후 imgtext로. 그 전에는 measure_style로 꾸밈을 재서 `work/img/C_measure.json`에 둔다.

## 진행 (13:55~)

- [완료] stat_en 7장 → `scripts/lyt_C_stat.py build` (READY 불필요, 3DX 원본 글자만 사용). 대조표 `work/img/review/C_stat_en_1.png`, `C_stat_en_2.png` 확인함.
  - STbr(60x16): 채움 마스크 + 이웃 대응표(원본 7장 학습, 자기 재현 평균 오차 L 0.02·A 0.06단계, 한 장 빼고 학습해도 L 0.4~1.1). S·P·U·E·O는 원본 글자, Y·M·L은 같은 격자에 새로 그림. SP(1–19px), SUYEOM(1–56px, 1DX와 같은 폭), PPUL(1–37px).
  - ST(42x12, 알파만): SP = 3DX SPEED의 앞 두 글자 그대로. GDH = 3DX GDD의 G·D + HP의 H 픽셀 복사. SUYEOM·PPUL = 원본 글자 복사 + Y·M·L 손으로 그린 알파(같은 부드러운 가장자리 값). SUYEOM은 글꼴 원래 폭으로 0–41px(칸 42px 전부). 장평을 줄이면 글자가 뭉개져서 원래 폭을 택함.
  - kind 가(STbr_HIGE→1DX STbr_HIGE, KJ_ST_GDD→1DX ST_GDD): 1DX 그림은 글꼴·테두리가 3DX와 달라(1DX는 사방 1px 테두리, 키 11행 / 3DX는 아래 입체 그림자, 키 8행) 1장 '가'의 단서(꾸밈이 다르면 나)에 따라 3DX 글자 재조합으로 처리.
- [측정] 한글 묶음 29장 measure_style → `work/img/C_measure.json`.
  - battle_btn: 흰(위아래 0.87→1.0 그라데이션) + 검정 1.75px, 그림자 없음. em 11~16.
  - rank_name: 흰(위아래 옅은 남색 그라데이션) + 남색(0.05,0.1,0.2) 1px + 검정 그림자 (1,2). em 14~15.
  - result_banner(베스트…): 흰 + 남색 1.75px + 남색 그림자 (2,3). GET_PRIZE: 흰 + 검정 1.75px.
  - minigame_btn / field_btn: 흰 + 검정 1.75~2px.
  - panel_label: 흰 글자만(알파만, 테두리 없음 — 픽셀 덤프로 확인). em 10~11.
- 대기: `work/img/toolkit/READY` 없음(13:55 기준).
- [완료 14:45~] READY(imgtext 1.1) 확인 → 한글 29장 `python scripts\lyt_C.py make`. 보고 `work/img/C_make_report.json`.
  - 글자 출처(줄별): same_word = 취소(btn_cancel), 시작(btn_MINIGAME_START). compose(1DX 폰트+조합) = 랭크 이름 11장, 베스트 턴 갱신. font(1DX font) = 나머지 버튼·라벨. ofl(GothicA1, em 21 큰 글자) = GET_PRIZE의 「상품」(「GET!」은 원본 그림 글자 그대로). 5순위 OFL을 쓴 곳은 GET_PRIZE 한 장.
  - 정한 것: rank_name은 STAR 한 장에서 잰 꾸밈을 11장에 공통 적용, em 13, 글자 영역 x 12–116(원본 일본어 폭 안쪽) → 긴 이름 장평 95~98%(파이널/마스터/브론즈 보스 랭크). 보스\n배틀은 은행 글자(bank)가 em 11.5에서 깨져 같은 묶음 거대화\n배틀과 같은 font 출처로 맞춤.
  - 굵기 비(목표 대비) 0.90~1.04. 랭크 이름은 compare 기준 획 두께 비 0.75~0.79로 원본 가나보다 조금 가볍다(README 7장 한계와 같음).
- [검증] `python scripts\build_lyt.py --out work/build/lyt_stage_C --report work/img/C_build.json`: errors 0, warnings 0, C조 36장 모두 적용(복사본 포함). ETC1A4 알파 곱 PSNR 36.4~41.7dB(최저 btn_USE·btn_MGAME_pnl2 36.4).
- [대조표 확인] `work/img/review/C_battle_btn.png`, `C_rank_name_1.png`, `C_rank_name_2.png`, `C_stat_en_1.png`, `C_stat_en_2.png`, `C_panel_label.png`, `C_field_btn.png`, `C_minigame_btn.png`, `C_result_banner.png` (모두 1600px 이하) 직접 보고 위 두 가지를 고침.

## 리드 확인
- ST_HIGE(42x12) SUYEOM: 글꼴 원래 폭으로 42px 칸을 다 씀(원본 TSUNO 35px). 게임에서 옆 숫자와 겹치는지 확인 필요. 겹치면 장평 88%판(흐려짐)으로 바꿀 수 있음(`lyt_C_stat.py`의 JOBS에 fit 옵션).
- STbr_HIGE·KJ_ST_GDD: 계획표 kind '가'(1DX 재사용)를 '나'(3DX 글자 재조합)로 처리. 이유는 위.
- 새로 지은/원본보다 긴 이름: 「파이널 보스 랭크」는 장평 98%로 칸 안에 들어감(보고할 넘침 없음). 랭크 이름 중 「○○ 보스 랭크」 5장은 원본 일본어 글자 폭보다 좌우 3~5px 넓음(텍스처 안).
- 영문 유지: 「GET!」(GET_PRIZE), 「LV」(RECOMMEND_LV) — 계획표대로 원본 글자 그대로.
- 굵기: 랭크 이름 한글이 원본 가나보다 약간 가볍다(획이 빽빽한 랭·등·껍 등, 도구 한계). 게임 화면에서 약해 보이면 알려 달라.

## 남은 일
- 없음(C조 36장 완료). 게임 화면 확인은 리드 통합 빌드 후.
