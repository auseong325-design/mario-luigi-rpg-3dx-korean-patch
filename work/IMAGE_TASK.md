# IMAGE_TASK.md — 그림 속 글자·로고·스태프롤 한글화 (서브에이전트 공통 지시서)

AGENTS.md를 먼저 읽고, 이 문서의 0~4장과 5장의 **자기 스트림**을 끝까지 읽은 뒤 시작한다.
목표는 게임 화면에 보이는 일본어를 전부 한국어로 바꾸는 것(풀 한글화)이고, 기준은 하나다:
**원본과 나란히 놓아도 원래 게임에 들어 있던 그림처럼 보일 것.**

## 0. 표기 규칙

- 게임 제목: **「마리오&루이지 RPG3 DX」** (`&` 앞뒤 붙여 씀, `RPG3`와 `DX` 사이 한 칸). 원본이 DX를 뺀 자리(예: `LABEL_MLRPG_00_JP_ja` 「マリオ&ルイージRPG3」)는 원본대로 「마리오&루이지 RPG3」. DS 한국판 제목도 「마리오&루이지 RPG3」이다(`!!!`는 일본판에만 있었다).
- 쿠파Jr. 모드: **「쿠파주니어 RPG」** (MSBT 번역과 같음. 예: MenuKJ#65).
- 그림 속 낱말은 이 순서로 정한다. (1) 같은 일본어가 게임 대사·메뉴 번역(`work/ko_final.json`)에서 **같은 뜻으로** 쓰인 말(`text/jp/`에서 일본어로 찾고 같은 id의 한국어를 본다. 도움말이 그 버튼을 부르는 이름이 있으면 반드시 그것과 똑같이) → (2) `text/glossary.tsv` → (3) 1DX 한국판에서 같은 역할의 그림이 쓴 말(공식 표기) → (4) 새로 짓기(DS 번역 문체에 맞게, 보고서에 적는다). 예: 「ひらく」 버튼 = 「열기」(Menu#717), 쿠파Jr. RPG 종료 버튼 = 「쿠파주니어 RPG 종료」(b_sys#557).
- 원본이 **영어**인 글자: 1DX 한국판이 같은 요소를 어떻게 했는지 따른다. 1DX가 영어로 둔 것(MARIO, LUIGI, LEVEL UP!, EXP, LV, HP, POW, DEF, SPEED)은 영어 그대로. 확정 변경 3개: **BP→SP**, **HIGE→SUYEOM**(1DX 한국판과 같음), **TSUNO→PPUL**(용어집 さいだいHIGE/TSUNO 규칙). 1DX에 대응이 없는 영어(CONGRATULATIONS!, PAUSE, SOLD OUT, NEW DATA, BONUS, ON/OFF, KOOPA 등)는 영어 그대로 두고 보고서의 「리드 확인」에 적는다.
- 칸이 모자라면 이 순서로 맞춘다: 장평 줄이기(최소 80%) → 자간 줄이기 → (원본 칸이 두 줄일 때만) 줄바꿈 → 뜻이 같은 더 짧은 말. 용어집 확정어는 스스로 바꾸지 말고 「리드 확인」에 적는다. **텍스처 크기·포맷은 절대 바꾸지 않는다**(레이아웃이 그 크기를 전제로 한다).

## 1. 스타일 원칙

그림을 두 겹으로 나눠서 다룬다.

1. **글자 모양 = 1DX 한국판.** 출처 우선순위(먼저 되는 것):
   1. 1DX 한국판 그림에 같은 낱말이 있으면 그 글자를 그대로(꾸밈을 벗긴 글자 모양만).
   2. 1DX 한국판 그림에서 떼어 낸 음절.
   3. 1DX 한국판 폰트 글리프(`ml 1dx/3romfs/Msg/KR_ko/font.bffnt` 17×18, `font_l.bffnt` 23×24). 작은 글자(높이 24px 이하)는 이것이 곧 1DX 글꼴이다.
   4. 1DX 음절 조합(`scripts/hangul_compose.py`와 같은 A+B−B′ 방식).
   5. 마지막 수단: `fonts/`의 OFL 글꼴 중 1DX 글자와 가장 비슷한 것(겹침 IoU로 고른다). 쓴 곳은 보고서에 적는다. 윈도 시스템 글꼴 등 라이선스가 없는 글꼴은 결과물에 쓰지 않는다.
   - 한 낱말 안에서는 한 출처로 통일한다(음절마다 모양이 달라 보이면 안 된다).
   - **글자 크기에 따른 규칙 (리드 결정, I6 결과를 보고 추가).**
     - 비트맵 폰트(3번)와 그 조합(4번)은 원래 칸 크기(font 18px, font_l 24px)의 약 1.25배까지만 쓴다. 그보다 크게 늘리면 흐리고 가늘어진다. 거대 전투 1차 결과에서 이렇게 원본보다 약해 보였다.
     - 큰 글자는 1·2번(1DX 그림 글자, 한 묶음 안의 음절)으로 쓴다. 안 되면 5번 벡터 글꼴을 4배로 선명하게 그린다. 이때 글꼴은 1DX 그림 글자와 가장 비슷한 OFL 글꼴을 고른다.
     - 후보는 `fonts/`에 있는 것과 Google Fonts의 OFL 한글 글꼴이다(예: Jua, Do Hyeon, Black Han Sans, Gothic A1, Noto Sans KR, Sunflower, NanumSquareRound). 받은 글꼴은 `fonts/`에 라이선스 파일과 함께 두고, 출처와 버전을 적는다.
   - **굵기는 원본에 맞춘다.** 획 두께와 테두리 두께는 3DX 일본어 원본에서 잰 값의 ±10% 안에 든다. 읽기 어려우면 가늘게 만들지 말고, 더 굵은 글꼴이나 굵기(weight)를 고른다.
2. **꾸밈 = 3DX 일본어 원본에서 잰 값.** 채움색·그라데이션 방향, 테두리 겹 수·겹마다 두께와 색, 그림자 방향·거리·색·번짐, 하이라이트, 글자 뒤 판(버튼 바탕 등)을 원본에서 픽셀 단위로 재서 한글 글자에 다시 입힌다. 1DX 그림의 꾸밈은 가져오지 않는다.
3. 글자 높이·획 굵기·기준선·정렬(가운데/왼쪽)·좌우 여백은 원본 일본어 글자와 맞춘다. 굵기는 획 두께(거리 변환)로 재서 맞춘다.
4. 4배로 그려서 줄이고, 최종 결과를 원본 텍스처 포맷으로 한 번 양자화해 본 모습으로 확인한다(LA4·A4는 16단계, RGBA4는 채널당 16단계, ETC는 블록 압축 흔적).
   - ETC1·ETC1A4 인코더(`libtex3ds.py`)는 이제 etcpak 뒤에 알파 가중 정밀 탐색을 한다(리드, 2026-09-29 23:55). 흰 글자 가장자리의 회색 얼룩이 없어지고 PSNR이 36~42dB에서 52~99dB로 올랐다. 텍스처당 1~3초 걸린다. `imgtext.finalize`·빌더가 모두 이 인코더를 쓰므로 따로 할 일은 없다. **ETC 텍스처를 이 날 이전에 저장했다면 한 번 다시 만든다**(저장 PNG에 옛 인코더의 얼룩이 들어 있다).
5. 일본어를 지운 자리의 배경(판·무늬·그라데이션)은 주변에서 복원한다. 글자가 없는 부분의 픽셀은 원본 그대로 둔다.

작업 분류(텍스처마다 하나):
- **가**: 1DX 한국판에 역할·디자인이 같은 그림이 있다 → 1DX 그림을 쓰되 크기와 꾸밈을 3DX 원본에 맞춘다(꾸밈이 다르면 '나'로 처리).
- **나**: 1DX에 같은 역할의 그림은 있지만 모양이 다르다 → 글자는 1DX, 꾸밈은 3DX.
- **다**: 3DX에만 있다 → 3DX 꾸밈을 재서 1DX 글자 모양 위에 만든다.

## 2. 이미 준비된 것

| 경로 | 내용 |
|---|---|
| `scripts/libtex3ds.py` | 3DS 텍스처 코덱: 모든 PICA 포맷(ETC1·ETC1A4 포함), 8×8 타일 스위즐. `decode(data, fmt, w, h)` / `encode(rgba, fmt)`. `python scripts/libtex3ds.py` = 자체 검사 |
| `scripts/lytimg.py` | Lyt: BG4 → BLZ → SARC → BFLIM. `bflim_to_rgba`, `rgba_to_bflim`(같은 크기·포맷·플래그), `sarc_list`, `sarc_replace`(제자리 교체). `check`: 무손실 텍스처 6,690/6,690개 디코드→인코드 바이트 일치 확인됨 |
| `work/img/lyt_manifest.json` | 레이아웃 텍스처 전부. 3DX 4,485개(고유 1,158), 1DX 4,511개(고유 1,088). `dup_of` = 다른 SARC에 들어 있는 같은 그림(하나만 만들면 빌드가 모든 복사본에 적용) |
| `work/img/lyt/<3DX\|1DX>/<dat>/<entry>/<이름>.png` | 텍스처 PNG(논리 크기, 위가 위) |
| `scripts/img_sheets.py` | 대조표(여러 그림을 한 장에). `--game/--dat/--entry/--suffix` 또는 `--pngs` |
| `work/img/sheets/3DX_JP_*.png`, `1DX_KR_*.png` | 이름에 `_JP_ja`/`_KR_ko`가 붙은 현지화 텍스처(3DX 214개, 1DX 194개). `_index.txt`에 번호→id |

- BFLIM 저장 방식(확인됨): 저장 크기 = (p2(h) × p2(w)), 플래그 4 = 90° 회전, 플래그 8 = 전치(ETC 전부), 최소 변 8(ETC1은 16). 여백 열·행은 마지막 열·행을 반복(95%) — `rgba_to_bflim`이 그대로 재현한다.
- BG4·BLZ(검증됨, 리드 소유 `scripts/lib3dx.py`): `read_bg4`, `bg4_plain(entry)`(압축 해제된 내용), `blz_compress`(되풀기 검증 포함), `rebuild_bg4(orig, {슬롯 번호: 새 내용(압축 전)})` — 압축 항목은 다시 압축하고 나머지는 원본 바이트, 원본의 정렬·패딩 규칙 유지. `rebuild_bg4(x, {}) == x`를 Lyt 6개, Obj 4개, FMdl, FMsg, BMsg 전부에서 확인했다. **빌더는 이것을 쓰고 BG4 작성기를 따로 만들지 않는다.** BLZ 재압축은 4MB에 3초 정도이고, 결과가 원본 압축보다 조금 클 수 있다(예: +1.5KB). 바뀐 항목만 다시 압축된다.
- 설치된 파이썬 패키지: numpy, pillow, scipy, opencv-python-headless, etcpak, texture2ddecoder, fonttools, ndspy.
- 1DX 한국판 참고 위치: 타이틀 로고 `ml 1dx/3romfs/MGMap/KR/MGMap.dat` 항목 `mg_map_title_logo_KR_ko`, 쿠파군단 RPG 로고 `Lyt/KR/MLyt.dat` `MLYT_MAIN_KR_ko/timg/KG_LOGO_TEXT_L_12_KR_ko`(400×206)·`KG_RECORDnn_KR_ko/timg/KG_LOGO_TEXT_S_12_KR_ko`, 게임 시작 버튼 `SLyt GAMESTART_KR_ko/timg/btn_GAMESTART_12_KR_ko`, 그림 `Lyt/KR`·`Obj/KR`·`FMdl/KR`, 스태프롤 `Staffroll/KR/`.
- 3DX 파일은 항상 `lib3dx.romfs_path()`로 연다(FMdl은 v1.2 업데이트판 `romf2/FMdl/JP/FMdl.dat`).

## 3. 공통 규칙

- 원본(`romfs/ romf2/ exefs*/ ml 1dx/ *.nds`)은 절대 수정하지 않는다. **`patch/`에는 쓰지 않는다**(사용자가 게임을 켜 보는 중). 빌드 결과는 `work/build/<스트림>_stage/romfs/…`에만 쓰고, 설치는 리드가 검증한 뒤에 한다.
- 파일 소유: `lib3dx.py`·`libtex3ds.py`·`img_sheets.py`·`requirements.txt`·`AGENTS.md`·`work/lead_state.json` = 리드. `lytimg.py` = I1. 나머지는 자기 스트림이 만든 파일만 고친다. 공유 파일에서 버그를 찾으면 뒤로 호환되는 최소 수정만 하고, 자체 검사(`python scripts/libtex3ds.py`, `python scripts/lytimg.py check`)를 통과시킨 뒤 `work/img/SHARED_CHANGES.md`에 한 줄 적는다. 새 패키지가 꼭 필요하면 정확한 버전으로 설치하고 같은 파일에 적는다.
- 빌더 규칙: 무변경 빌드(`--identity`)는 원본과 **바이트 단위로 같아야** 한다. 원본에 없던 패딩을 마지막 파일 뒤에 넣지 않는다. 항목 순서·이름표·빈 항목·정렬은 원본대로 둔다. 바꾼 텍스처는 다시 풀어서 의도한 PNG와 비교한다(무손실 포맷은 양자화 후 완전 일치, ETC는 PSNR 30dB 이상).
- 파이썬은 타임아웃을 걸어 실행한다(`Start-Process … -PassThru` + `WaitForExit(ms)`). 콘솔은 한글·일본어를 깨뜨릴 수 있으니 결과는 파일로 쓰고 read 도구로 읽는다.
- 그림은 직접 보고 판단한다(read 도구 Image 모드). 경로가 길면 도구 이름 길이 제한에 걸리므로 짧은 이름으로 복사해서 한두 장씩 연다.
- **read 도구로 여는 그림은 가로·세로 모두 1600px 이하로 만든다.** 그림이 여러 장 쌓인 대화에서 한 변이 2000px를 넘는 그림을 한 장이라도 열면 대화 전체가 API에서 거부되고, 그 대화는 이어서 할 수도 없게 된다(I2·I3 1차 실행이 이렇게 끊겼다). 큰 대조표·확대본은 1600px 이하 조각으로 나눠 저장하고, 조각만 연다. 원본 크기 그림이 필요하면 파일로만 두고 열지 않는다.
- **매 응답에 도구 호출을 넣는다.** 도구 없이 말만 하고 응답을 끝내면 그대로 작업이 끊긴다. 최종 보고 전까지 멈추지 않는다.
- 진행 기록: `work/img/<ID>.md`에 마일스톤마다 적는다(한 일, 다음 할 일, 정한 것, 리드 확인). 끊기면 이 파일로 재개한다. 결과물은 조금씩 저장한다.
- 막히면 멈추지 말고 다른 항목을 먼저 한다. 결정이 필요하면 이 문서의 기준으로 정하고 「리드 확인」에 적는다.
- 품질 확인: 바꾼 그림마다 원본/한국어판 대조표를 만든다(실제 크기와 3배 확대를 함께, `work/img/review/<ID>_*.png`). 대조표를 직접 보고 어색한 것을 고친 뒤에 끝낸다.

## 4. 최종 보고 형식

1) 한 일과 결과 숫자(바꾼 그림 수, 검증 결과) 2) 만든·바꾼 파일 3) 대조표 경로 4) 리드 확인 목록 5) 남은 일. 모든 경로는 절대 경로로.

## 5. 스트림

### I1 — 레이아웃 빌더 + 전수 목록 (Lyt)

1. `scripts/build_lyt.py`: 한국어 PNG `work/img/ko/lyt/<dat>/<entry>/<이름>.png`(매니페스트의 고유 텍스처 위치, 논리 크기 RGBA)를 받아, 같은 sha1을 가진 **모든 복사본**(모든 SARC, 모든 dat)에 `rgba_to_bflim`으로 넣고 → `sarc_replace` → `lib3dx.rebuild_bg4`(바뀐 항목만 다시 압축, 나머지는 원본 바이트) → `--out`(기본 `work/build/lyt_stage/romfs/Lyt/JP/`)에 바뀐 dat만 쓴다. `--identity`(6개 dat을 교체 없이 작성기로 다시 써서 바이트 일치), 가짜 그림 몇 장으로 하는 자체 검사(교체→재조립→다시 읽어 비교)를 넣는다. 한국어 PNG가 있는 텍스처 목록과 적용된 복사본 수를 출력한다.
2. 전수 목록 `work/img/lyt_plan.json`: 3DX 고유 텍스처 1,158개를 **전부** 대조표로 보고 분류한다. `_JP_ja` 214개는 한 장씩, 나머지는 대조표로 훑어 글자가 있는 것을 찾는다.
   - 항목마다: `id`, `action`(keep / replace / review), `jp`(그림 속 글자), `ko`(최종 한국어와 근거: ko_final id, glossary 행 또는 1DX 그림 id), `family`(꾸밈이 같은 묶음 id — 같은 묶음은 같은 방식으로 만든다. 여러 dat에 걸쳐도 하나의 묶음), `kind`(가/나/다), `ref_1dx`(같은 역할·스타일의 1DX 한국판 텍스처 id), `box`(글자 영역, 줄 수, 정렬), `notes`. 로고(쿠파주니어 RPG 로고 등)는 `family: "logo"`로 두면 I4가 맡는다.
   - 묶음(family)마다 대표 원본 1장과 1DX 참고 1장을 붙인 대조표 `work/img/sheets/family_<id>.png`, 그리고 묶음 목록 `work/img/lyt_families.json`(묶음마다 설명, 꾸밈 요약, 텍스처 수, 어려움 1~3).
   - 2차 분배안: 묶음을 **쪼개지 않고** 3~4개 작업 묶음으로 나눈 안(작업량이 비슷하게, 꾸밈이 비슷한 묶음끼리)을 `work/img/lyt_plan.json`의 `groups`에 적는다. 리드가 이 안으로 2차를 투입한다.
3. bflyt의 글상자(txt1)에 기본 글자가 들어 있어 화면에 그대로 보일 수 있는지, 폰트 참조(fnl1)가 있는지 확인해 보고한다.
4. 끝 조건: `--identity` 통과, 자체 검사 통과, 1,158개 전부 분류, 보고.

### I2 — 한글 그림 글자 도구 (imgtext)

`scripts/imgtext.py`(필요하면 보조 모듈)와 `work/img/toolkit/`를 만든다. 레이아웃·스프라이트·모델 텍스처 모두 이 도구로 한글 글자를 만든다.
1. **글자 모양 은행**: 1DX 한국판 `_KR_ko` 그림(대조표 `work/img/sheets/1DX_KR_*`)의 한글을 음절 단위로 떼어 꾸밈을 벗긴 글자 모양(채움 마스크)으로 저장한다(`work/img/toolkit/bank/`, `bank.json`에 음절·출처·크기·획 두께). 1DX 그림 글자와 1DX 비트맵 폰트(font·font_l) 글자가 같은 글꼴인지 겹침으로 비교해 보고한다. 5순위 대체 글꼴도 `fonts/` 안에서 IoU로 고른다.
2. `glyph_mask(text, height_px, …)`: 1장의 우선순위대로 출처를 골라 고해상도 글자 마스크를 만든다(음절별 출처 기록).
3. `measure_style(jp_rgba)`: 원본 글자 그림에서 채움(단색/그라데이션), 테두리 겹(두께·색), 그림자(거리·방향·색·번짐), 하이라이트, 글자 상자·기준선·정렬, 획 두께를 잰다. 대조표의 대표 묶음(흰 글자+검은 테두리 버튼, 랭크 이름, 쿠파Jr. 기술 이름, 메뉴 제목, 숫자·영문 판 등)에서 모두 동작해야 한다.
4. `render(text, style, size, box)`: 4배로 그려 줄이고, 장평·자간 맞춤까지 해서 원본 크기 RGBA를 돌려준다. `erase_text(jp_rgba, …)`: 글자 뒤 판이 있는 그림에서 일본어를 지우고 판을 복원한다. `compare(jp, ko)`: 테두리 두께·색, 채움색, 그림자 거리, 글자 높이·굵기 비의 차이를 숫자로.
5. 시연: 서로 다른 묶음 10장 이상을 한국어로 만들어 원본과의 대조표를 만든다. 최소한 `btn_USE_00_JP_ja`(つかう), `btn_cancel_00_JP_ja`(やめる), `RANK_NAME_STAR_00_JP_ja`(スターランク), `LTIT_btl_HINT_00_JP_ja`(ヒント), `btn_KJ_LA_12_00_JP_ja`(おだてる), `STbr_BP_00_JP_ja`(BP→SP), `LTIT_ITEM_00_JP_ja`(アイテム), `SHOP_TIT_BADGE_00_JP_ja`(バッジショップ), `btn_F_MAP_OPEN_00_JP_ja`(ひらく→열기), `KJ_TYPE_02_00_JP_ja`(ひこう). 한국어 낱말은 0장 규칙으로 찾는다. 시연 결과는 `work/img/toolkit/demo/`에만 둔다(`work/img/ko/`에는 쓰지 않는다).
6. 끝나면 `work/img/toolkit/README.md`(사용법·API·한계)와 `work/img/toolkit/READY`(한 줄: 버전과 요약)를 쓴다.

### I3 — 스프라이트 UI (Obj/JP)

1. `romfs/Obj/JP/{BUI,FUI,KUI,Menu}.dat`(BG4) 형식을 푼다. 항목은 작은 설명 데이터(예: `0d 04 06 00 …`), 큰 픽셀 버퍼(예: 32,768바이트, 같은 16비트 값이 반복되는 PICA 픽셀로 보임), 중첩 BG4인 `_CA_INFO_`로 이뤄져 있다. 참고: `tools/Spritoglobin-DX/spritoglobin_dx.exe`(이 형식의 뷰어. 웹에서 소스를 찾아 형식을 확인한다), 1DX `Obj/KR/{BUI,FUI,KUI,MGUI}.dat`·`Obj/Menu.dat`.
2. 모든 픽셀 버퍼를 PNG로 풀고(`work/img/obj/<game>/…` + 매니페스트), 어떤 조각이 어떤 스프라이트인지 알 만큼 설명 데이터를 해석한다. `scripts/build_obj.py`(같은 크기·포맷 제자리 교체, BLZ, BG4 재조립, `--identity`) → `work/build/obj_stage/romfs/Obj/JP/`.
3. 글자가 있는 스프라이트(일본어, BP/HIGE/TSUNO)를 모두 찾아 `work/img/obj_plan.json`(I1 목록과 같은 항목)에 적고, 1DX 한국판의 같은 스프라이트를 찾는다. 같은 엔진이라 1DX에 같은 디자인이 많을 것이다.
4. 한국어 스프라이트를 만든다(1DX 재사용, 또는 `work/img/toolkit/READY`가 생긴 뒤 imgtext). READY 전에는 형식·목록·1DX 재사용 항목을 먼저 한다. 빌드·검증·대조표.

### I4 — 모델 텍스처 + 로고 (FMdl, 로고 전부)

1. BCH 텍스처 도구 `scripts/libbch.py`: `FMdl.dat`의 BCH(205개)에서 텍스처(PICA 포맷 id, 크기, 데이터 위치, 밉맵)를 찾아 디코드하고, 같은 크기·포맷으로 제자리 교체(밉맵이 있으면 다시 만든다). `scripts/build_fmdl.py`(BLZ, BG4 재조립, `--identity`) → `work/build/fmdl_stage/romfs/FMdl/JP/FMdl.dat`.
2. 205개 모델의 텍스처를 대조표로 훑어 일본어 글자가 보이는 것을 모두 목록에 올린다(`_JP_ja` 3개: `fmd_title_JP_ja`, `fmd_title_start_JP_ja`, `fmd_ev_tfp_JP_ja` 외에도 있는지).
3. **타이틀 로고** `fmd_title_JP_ja` → 「마리오&루이지 RPG3 DX」: 「마리오&루이지」 글자 뼈대는 1DX 한국판 로고(`mg_map_title_logo_KR_ko`, 형식부터 확인)에서, 음영·테두리·입체감·하이라이트는 3DX 일본어 로고에서 잰 값으로 다시 입힌다. 「RPG3 DX」 등 원래 영문·숫자인 부분은 3DX 원본을 그대로 둔다. 손으로 그린 듯한 하이라이트는 원본 조각을 옮겨 붙인다. 단계별 시안과 최종본의 원본 대조표(실제 크기·확대)를 만든다.
4. `fmd_title_start_JP_ja`(시작 안내 글자; 1DX `btn_GAMESTART_12_KR_ko` 참고)와 `fmd_ev_tfp_JP_ja`(1DX `fmd_ev_tfp_KR_ko`와 같은 디자인이면 재사용).
5. **쿠파주니어 RPG 로고**가 어디 있는지 찾아(레이아웃·모델·스프라이트) 1DX 쿠파군단 RPG 로고(`KG_LOGO_TEXT_L_12_KR_ko`)의 글자 모양으로 「쿠파」「RPG」를 쓰고 「주니어」를 같은 모양으로 만든다. 레이아웃 텍스처면 PNG를 `work/img/ko/lyt/<dat>/<entry>/<이름>.png`에 두고 `work/img/I4.md`에 적는다(빌드는 I1의 `build_lyt.py`가 한다. `lytimg.py`·`build_lyt.py`는 고치지 않는다).

### I5 — 스태프롤

1. `romfs/Staffroll/JP/Staffroll.bin`(7,112바이트, `a0 01 00 00`으로 시작, 나머지는 압축이나 부호화로 보임)과 1DX 한국판 `ml 1dx/3romfs/Staffroll/KR/Staffroll.bin`(5,484바이트) 형식을 풀어 읽을 수 있는 목록(JSON: 줄마다 역할·이름·배치·타이밍 코드)으로 만들고, 다시 부호화했을 때 원본과 바이트 일치를 확인한다.
2. 폰트: 3DX는 `Staffroll/mario_font.bffnt` 하나, 1DX는 그것과 `Staffroll/KR/mario_font_kr.bffnt`(KRNG 커닝 블록 — `scripts/libbffnt.py`는 아직 못 읽는다)를 쓴다. 3DX 코드가 어떤 파일을 읽는지 확인하고, 한국어 스태프롤에 필요한 한글을 1DX `mario_font_kr` 글리프를 픽셀 그대로 옮겨 넣는다(기존 글리프·폭·매핑은 그대로. `scripts/build_font.py` 방식 참고).
3. 내용: 역할·부서 이름은 1DX 한국판 스태프롤에서 같은 역할을 부르는 말을 그대로 쓰고, 이름 표기 방식(한글/로마자)도 1DX 한국판을 따른다. 두 게임에 모두 나오는 사람은 1DX 표기를 그대로 쓴다. 크레디트를 새로 만들거나 빼지 않는다. 줄 수·페이지·타이밍 코드는 원본 그대로(음악과 맞춰져 있다).
4. `scripts/build_staffroll.py` → `work/build/staffroll_stage/romfs/Staffroll/…`, 다시 읽기 검증, 전 페이지 미리보기 그림(새 폰트로 그린 것).

### I6 — 거대 전투 UI (HB/JP_ja)

1. `romfs/HB/JP_ja/*.arc.z` 14개(cyorometer, demoskip, dpunch, fireball, get, kyusai, punch, result_win, rotation, start, touchpen, ui_fa, value, yesno — 거대 전투의 현지화 UI)의 형식을 푼다. 첫 바이트 `0x40` + 3바이트 크기는 LZ40 압축으로 보인다(zlib 아님). 푼 뒤의 아카이브 형식과 텍스처 형식(BCLIM/BCH/CTPK 등, `libtex3ds.py`로 디코드)을 확인한다. 거대 전투 코드 `RO/HugeBattle.cro`(v1.2판은 `romf2/RO/`)가 이 파일들을 어떻게 읽는지도 필요하면 본다. 같은 폴더 밖 `romfs/HB/*.bch.z` 중 글자 그림이 있는 것도 확인한다.
2. 압축·아카이브를 무손실로 다시 만드는 `scripts/build_hb.py`(`--identity` 바이트 일치) → `work/build/hb_stage/romfs/HB/JP_ja/`.
3. 모든 그림을 PNG로 풀어 `work/img/hb/…` + 목록 `work/img/hb_plan.json`(I1 목록과 같은 항목). 글자는 대사 번역(`text/ko/HugeBattle*.json`, `work/ko_final.json`의 `HugeBattle#…`)과 같은 말을 쓴다. 1DX에는 거대 전투가 없으니 꾸밈은 3DX 원본을 재고 글자 모양은 1장 우선순위대로.
4. 한국어 그림은 `work/img/toolkit/READY`가 생긴 뒤 imgtext로 만든다. 그 전에는 형식·빌더·목록·지우기(배경 복원)를 먼저 한다. 빌드·검증·대조표.

### 2차 — 레이아웃 한글 그림 (A·B·C·D)

I1의 전수 목록 `work/img/lyt_plan.json`(항목 1,158개, `groups`), 묶음 목록 `work/img/lyt_families.json`, 묶음별 대조표 `work/img/sheets/family_<id>.png`를 쓴다. 목록의 `ko` 칸은 리드가 확정한 최종 낱말이다(바꿔야 할 것 같으면 「리드 확인」에 적는다).

| 조 | 화면 | 묶음(family) | 만들 장수 |
|---|---|---|---|
| A | 쿠파주니어 RPG | kj_skill, kj_battle_btn, kj_menu_btn, kj_small_btn, kj_faint_label, kj_dark_label, kj_sort_btn, kj_type, kj_label | 49 |
| B | 메뉴·상점·파일 | menu_top, set_tab, shop_btn, shop_top, shop_title, status_label, file_btn, file_label | 46 |
| C | 전투·결과·미니게임 | battle_btn, rank_name, stat_en, panel_label, field_btn, minigame_btn, result_banner | 36 |
| D | 목록 제목·가이드·기록 | list_title, list_title_faint, guide_pnl, record_btn | 43 |

- 로고 4장(family `logo`, 파일 선택 화면 `LOAD_GAME_IMG_*`)은 I4 몫이다.
- 자기 조 묶음의 `action: replace` 텍스처만 만든다. 같은 묶음은 한 사람이 끝까지 하고, 묶음 안에서 글자 크기·굵기·테두리·그림자·정렬을 통일한다.
- 출력: `work/img/ko/lyt/<dat>/<entry>/<이름>.png`. 매니페스트의 고유 텍스처(`dup_of`가 없는 항목) 위치와 같은 경로에 논리 크기 RGBA로 둔다. 복사본은 빌더가 채운다. 다른 조와 동시에 빌드하므로 임시 이름으로 쓴 뒤 이름을 바꿔 넣는다.
- 순서:
  1. 묶음마다 원본 꾸밈을 재고(`imgtext.measure_style`), 1DX 참고 그림(`ref_1dx`)을 본다. 텍스처별 계획을 `work/img/<조>.md`에 적는다.
  2. kind 가(1DX 그림 재사용, 크기·꾸밈은 3DX 원본에 맞춤)부터 만든다.
  3. `work/img/toolkit/READY`가 생기면 `work/img/toolkit/README.md`를 읽고 나머지를 imgtext로 만든다. READY가 없으면 1·2를 하면서 `wait` 도구로 10분씩 기다렸다가 다시 확인한다.
- 도구: `scripts/imgtext*.py`는 I2 소유다. 직접 고치지 말고, 필요한 기능이나 버그는 `work/img/TOOLKIT_REQUESTS.md`에 적는다(조 이름, 텍스처, 기대 동작). 급하면 자기 스크립트 `scripts/lyt_<조>.py`에서 감싸 쓴다.
- 검증:
  - 확인용 빌드는 `python scripts/build_lyt.py --out work/build/lyt_stage_<조> --report work/img/<조>_build.json`으로 한다. 최종 통합 빌드는 리드가 한다.
  - ETC1·ETC1A4 텍스처는 알파를 곱한 PSNR(화면에 섞인 모습) 30dB 이상이어야 한다.
  - 대조표는 원본/한국어를 실제 크기와 3배로 나란히 둔다. 묶음 전체를 한 장에 모아 같은 묶음끼리 모양이 같은지 확인하고, 1,600px 이하 조각으로 만든다.
- 끝 조건: 자기 조의 replace 텍스처가 전부 PNG로 있고, 빌드 검증을 통과하고, 대조표를 직접 확인한 뒤 보고한다(4장 형식).
