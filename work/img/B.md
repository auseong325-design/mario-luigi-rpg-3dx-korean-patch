# B 진행 기록 (2차 B조 — 메뉴·상점·파일 화면, 46장) — 완료

묶음: menu_top 6, set_tab 2, shop_btn 5, shop_top 7, shop_title 8, status_label 2, file_btn 12, file_label 4 (전부 MLyt, 전부 LA4).
스크립트 `scripts/lyt_B.py`:
- `measure` → `work/img/B_styles.json`·`.txt` (원본 꾸밈 측정)
- `make [--out DIR] [base…]` → `work/img/ko/lyt/MLyt/<entry>/<name>.png` (`.tmpB.png`로 쓴 뒤 이름 바꾸기), 기록 `work/img/B_make.json`·`.txt`
- `review` → `work/img/review/B_<묶음>.png` (원본|한국어, 1배+3배, 1600px 이하 조각)
- `tk DIR` / `cmp3` : imgtext 1.1 기본값과 나란히 비교(시험용)

## 수정 2라운드 (2026-09-30 클라우드) — 격자 맞춤판 굵기
- 리드: 1라운드 격자 맞춤판 11장(상점 제목 8, 마리오&루이지 RPG3, 쿠파주니어 RPG, 슬롯)은 흐림은 없어졌지만 너무 가늘다(획 비 0.55~0.92).
- 원인: 1DX 폰트의 가로획은 진한 1px 줄에 반투명 줄(10/15 안팎)이 붙은 모양이다. 문턱값 0.70에서 반투명 줄이 잘려 1px만 남았다.
- 수정(`lyt_B.py` `grid_glyph`, `GRID_THRS`): 음절마다 문턱값을 0.45부터 0.70까지 낮은 것부터 시험한다.
  격자 맞춤 결과의 먹 조각 수와 속공간 수가 원래 크기 글자(0.70)와 같은 가장 낮은 값을 쓴다. 손으로 정한 숍(row_groups)과 롯(splice)은 0.70 그대로다.
- 결과(`B_fixcheck.txt`, 획 비): 배지 숍 0.95, 장비 숍 0.90, 부티크 키노다 0.92, 아이템 숍 0.87, 상점블록 0.84, 블로크 숍 0.78, 럭셔리 숍 0.78, 블도그 숍 0.71, 슬롯 0.57.
  마리오&루이지 RPG3는 0.92(한글/영문 0.80, 이전 0.72), 쿠파주니어 RPG는 0.97(0.81). 한글에 반투명 픽셀 0(선명함 유지).
- 남은 한계: 「숍」(ㅅ·ㅛ·ㅂ)과 「슬롯」(ㅅ·ㅡ·ㄹ / ㄹ·ㅗ·ㅅ)은 16px 칸의 12~13줄 안에 가로 요소가 6겹이라 2px 획이 들어갈 자리가 없다.
  더 굵히면 틈이 막힌다. 전체 문턱값 0.5 시험에서 숍의 ㅂ과 템의 ㅁ이 막혔다. 숍이 든 제목은 0.71~0.95.
- 빌드: `build_lyt.py --out work/build/lyt_stage_B` 178장, errors 0, warnings 0. lyt_stage_A와 비교하면 MLyt만 다르다.
- 대조표 `B_shop_title.png`, `B_file_label.png` 확인.

## 측정
- 버튼형(menu_top·set_tab·shop_btn·shop_top·status_label·file_btn): 흰 채움(L=15) + 검은 테두리 1.75~2.0px(바깥 가장자리만 반투명), 그림자 없음. → 채움 흰색, 테두리 1.85px로 묶음 전체 통일.
  measure_style의 채움색 0.6~0.93은 가장자리 섞임을 채움으로 센 값(픽셀 덤프로 속은 전부 L=F 확인). compare의 「채움색 차」 경고는 이 때문이다.
- 글상자형(shop_title·file_label): 흰 채움만(테두리·그림자 없음).
- 묶음별 한글 높이 em / 목표 획: menu_top 13/2.4, set_tab 16/3.5, shop_btn 16/3.2, shop_top 13/2.4, shop_title 13/2.2, status_label 12/2.1, file_btn 108×22 12/2.8 · 172×22 14/3.0 · 128×24 16/3.4 · 232×62 16/3.1, file_label 12/2.3(슬롯만 2.0).

## 만드는 방법
- 1순위 1DX 같은 낱말 그림(20장): 채움(밝기×알파)만 떼어 em에 맞춰 줄이고(0.75~1.09배, 확대는 1.09배 이하), 목표 획까지 imgtext.thicken(획 사이 틈 1px 보호)으로 굵힌 뒤 3DX 테두리를 다시 입힘.
  아이템·장비·가이드·기록(메뉴), 사기·팔기·나중에, 팔기·웨어·아이템·장비(상점 첫 화면), 장비(능력), 저장·데이터 삭제·복사·취소·파일 삭제·삭제·덮어쓰기·시작하기.
- 3순위 1DX 비트맵 폰트(+4순위 조합) 25장(그중 4장은 원본 라틴 글자와 합침): font(17×18, 한글 em 15)는 em 12~14, font_l(23×24, em 21)은 em 16. 모두 축소만 함. 한 낱말은 한 글꼴.
- 원본 라틴 글자 재사용: RPG3·RPG·& (btn_MLRPG3, LABEL_MLRPG, btn_KJRPG, LABEL_KJRPG), NEW·A·E (NEW_DATA).
- kind 가 2장: 장비(TOP_MENU_TEXT_2, 1DX TOP_MENU_TEXT_2 글자), NEW GAME(N·E·W·A·E 원본 픽셀 + G·M은 BlackHanSans; N·E·W·D·A·T 겹침 IoU 0.83로 11개 OFL 중 최고, N 획 3.19px에 맞춤).
- imgtext 1.1이 나온 뒤 46장 전부를 기본값으로도 그려 나란히 봤다. 1DX 그림 글자(1순위)를 imgtext는 em<14라 쓰지 않았고, 등껍질·가이드는 imgtext 쪽이 막혀서 내 방식으로 통일했다.

## 검증
- 46/46 PNG(논리 크기 RGBA), 임시 파일 0.
- `python scripts\build_lyt.py --out work/build/lyt_stage_B --report work/img/B_build.json`: OK, errors 0, warnings 0. 내 46장 전부 적용(LABEL_MLRPG·NEW_DATA는 복사본 2 → 슬롯 48개). LA4라 다시 풀어 양자화 PNG와 완전 일치(빌더 검사).
- 대조표 `work/img/review/B_*.png` 직접 확인.

## 리드 확인
1. set_tab: 1DX 한국판 같은 탭은 영어 ON/OFF. 목록 확정어(있음/없음)대로 만들었다. 설정 항목 이름(후리가나 표시?)은 화면에서 확인 필요.
2. btn_equip 「착용하기」: 1DX 같은 버튼은 「장비하기」(목록 notes와 같음).
3. 획 두께: 획이 빽빽한 음절(틀·템·슬·롯·덮)은 틈 1px를 지키느라 원본 가나보다 가볍다(획 비 0.65~0.8: 등껍질 0.65, 능력 0.78, 덮어쓰기 0.78, 착용하기 0.79). 막히지 않게 한 결정.
4. 한글 높이: compare 기준 원본 가나 대비 1.1~1.36배(가나보다 한글이 키가 커 보이도록 em 13을 쓴 menu_top·shop_top). 칸 안에 여유 있게 들어간다.
5. LABEL_MLRPG·btn_MLRPG3의 「&」는 원본 글자 그대로라 한글 옆에서 조금 작아 보인다.
6. NEW GAME의 G·M은 5순위 OFL(BlackHanSans, fonts/LICENSE-blackhansans-OFL.txt). 1DX NEW GAME 글자는 모양·꾸밈이 달라(검은 굵은 테두리) 쓰지 않았다.
7. btn_SLOT 「슬롯」은 쓰이는 화면 확인 필요(목록 notes).
