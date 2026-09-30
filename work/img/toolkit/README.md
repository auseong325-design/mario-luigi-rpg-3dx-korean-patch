# imgtext — 한글 그림 글자 도구 (v1.3)

게임 그림(레이아웃·스프라이트·모델 텍스처) 속 일본어 글자를 한국어로 다시 그린다.
**글자 모양 = 1DX 한국판**, **꾸밈(채움·테두리·그림자) = 3DX 일본어 원본에서 잰 값** (IMAGE_TASK.md 1장).

- 코드: `C:\mario-luigi-rpg-3dx-korean-patch\scripts\imgtext.py`(재기·지우기·그리기·양자화·비교), `scripts\imgtext_bank.py`(글자 출처), `scripts\imgtext_demo.py`(시연·전수 시험)
- 자료: `work\img\toolkit\bank\`(1DX 그림에서 떼어 낸 음절 412개), `bank.json`, `bank_quality.json`, `fonts\`(OFL 글꼴 + 라이선스)
- 시연: `work\img\toolkit\demo\*.png` + `_report.json`, 대조표 `work\img\review\I2_demo_*.png`

## 1. 가장 짧은 사용법

```python
import sys; sys.path.insert(0, r"C:\mario-luigi-rpg-3dx-korean-patch\scripts")
import imgtext as T
ko, rep = T.redraw(r"work\img\lyt\3DX\...\btn_cancel_00_JP_ja.png", "취소", fmt="LA4", jp_text="やめる")
T.save_png(ko, out_path)            # 원본과 같은 크기의 RGBA, 이미 fmt로 양자화된 모습
print(rep["sources"], rep["weight"], rep["problems"])
```

- `fmt`를 빼면 `lyt_manifest.json`에서 찾는다(레이아웃 PNG일 때). 스프라이트·HB·모델은 직접 준다.
- `jp_text`(원본 일본어 글자)를 주면, 원본에 있던 영문·숫자(RPG3, NEW 등)는 **원본 그림에서 떼어 낸 모양 그대로** 쓴다.
- 줄바꿈은 `"\n"`. 원본 일본어 줄이 붙어 있어도 한국어 줄 수대로 나눠 잰다.
- 결과를 빌더에 넣을 때는 이 RGBA를 그대로 `work\img\ko\...`에 저장하면 된다(빌더가 같은 포맷으로 다시 인코드).

CLI (타임아웃을 걸어 실행):
```
python scripts\imgtext.py measure <png> [--out style.json]
python scripts\imgtext.py render <png> <text> <out.png> [--fmt LA4] [--source auto] [--em 14] [--align center] [--sheet s.png] [--report r.json]
python scripts\imgtext.py selftest
python scripts\imgtext_demo.py            (필수 시연 → demo\, 대조표 review\I2_demo_NN.png)
python scripts\imgtext_demo.py --smoke    (lyt_plan·hb_plan의 replace 전부를 기본값으로 → demo\_smoke.json, review\I2_smoke_NN.png)
```

## 2. 글자 출처 (자동 선택)

한 줄의 한글 낱말 전부를 **한 단계**에서 가져온다(줄 안에서 출처가 섞이지 않는다. 여러 줄이면 모든 줄을 가장 뒤 단계로 맞춘다).

| 순서 | source | 내용 | 조건 |
|---|---|---|---|
| 1 | `same_word` | 1DX 그림에 같은 낱말이 있으면 그 글자 | 원본 그림 em 14px 이상, 확대 1.25배 이하, 품질 검사 통과 |
| 2 | `bank` | 1DX 그림에서 떼어 낸 음절. **한 그림(또는 같은 굵기·크기 묶음)**에서만 모은다. 모자라는 음절은 같은 묶음 안 A+B−B′ 조합 | 위와 같음 |
| 3 | `font` | 1DX 비트맵 폰트(font_btl 13×14 em 11 / font 17×18 em 15 / font_l 23×24 em 21, 크기가 가까운 것) | 확대 1.25배 이하 |
| 4 | `compose` | 1DX 폰트 + 없는 음절 조합(A+B−B′) | 확대 1.25배 이하 |
| 5 | `ofl` | 벡터 글꼴 GothicA1(Bold/ExtraBold/Black 중 굵기가 가까운 것)을 **목표 크기로 직접** 그림 | 항상 가능 |

- 크기 규칙(1장): 비트맵·은행 글자는 1.25배보다 크게 늘리지 않는다. 그보다 큰 글자는 자동으로 다음 단계(결국 벡터)로 간다. `strict=False`로 끌 수 있지만 쓰지 않는다.
- 비트맵 글자가 자기 크기와 ±13% 안이면 **자기 크기 그대로, 픽셀 격자에 맞춰** 그린다(1px 틈이 회색 두 줄이 되지 않게).
- 영문·숫자: 원본(`jp_text`)·`donors` → 1DX 그림 → 3DX 비트맵 폰트(작을 때) → 벡터 글꼴. 기호만 있는 낱말(~ ! ? … ♪): 1DX 그림 → 1DX 폰트 → 3DX 폰트 → 벡터.
- 한글도 `donors=[(그림, "글자")]`로 직접 줄 수 있다(예: 1DX 스프라이트 `bui_sys_button_KR_ko`의 한 칸). 낱말의 음절이 전부 있으면 최우선. 한 줄의 영문 낱말이 **전부** 원본에서 나올 때만 원본 모양을 쓴다(섞이면 폰트로 통일).
- 벡터 글꼴 선택 근거: 1DX 그림 음절(em 15 이상 145개)과의 겹침 IoU — GothicA1-Black 0.564, NanumSquareRoundEB 0.548, NanumGothic-ExtraBold 0.547, NotoSansKR-Bold 0.538, Jua 0.515, BlackHanSans 0.513.
- 굵기로 출처 고르기(`source="auto"`일 때만): 고른 글자가 일본어 획보다 1.3배 넘게 굵으면(가는 글씨) 다음 단계로 넘어간다. 비트맵의 1px 획은 깎으면 깨지기 때문이다. 원래 크기 비트맵은 12%까지만 깎는다.
- 한 묶음(같은 화면에 함께 나오는 그림들)에서 출처가 갈리면 보고 나서 `source=`를 묶음 전체에 같은 값으로 주는 것을 권한다(예: 거대 전투 큰 글자는 `source="ofl"` 또는 `"compose"`).
- 쓰인 출처는 `rep["sources"]`(낱말별), `rep["levels"]`(줄별)에 남는다. 보고서에 그대로 옮기면 된다.

## 3. 굵기 (±10%)

- 목표 = 일본어 원본 채움 획 두께(`measure_style().stroke`, 픽셀). `weight=`로 바꿀 수 있다.
- 글자를 목표까지 **두껍게 할 때 획 사이 틈이 `gap_min`(기본 1px, 큰 글자 최대 1.5px) 밑으로 줄지 않게** 한다(`T.thicken`). ㄹ·ㅌ·ㅁ 속과 받침 사이가 막히지 않는다.
- 그린 결과를 원본과 같은 방법으로 다시 재서 최대 3번 보정한다. 결과: `rep["weight"] = {target_px, glyph_px, achieved_px, ratio}`.
- 전수 시험(194장): ratio 중앙값 0.998, 93%가 ±10% 안. 밖으로 나가는 것은 획이 빽빽한 음절(스타 랭크·슬라이드 등 0.75~0.8)이다. 틈을 지키느라 덜 두꺼워진 것이고, 막히게 하는 것보다 낫다고 판단했다.
- **`weight=0.0`은 "굵기 그대로"**(v1.0과 같음). v1.1에서는 쓰지 않는 것을 권한다.

## 4. 크기·위치

- `em`(한글 채움 높이)을 주지 않으면 일본어 채움 높이로 시작해, 한국어 잉크 높이(두꺼워진 뒤)가 일본어의 1.08배(최소 +0.5px)를 넘으면 줄인다(`fit_height`).
- 가로가 모자라면 장평 80%까지 → 자간 → (줄바꿈은 호출하는 쪽이 `"\n"`으로).
- 줄 중심 = 일본어 줄 중심. 줄 위치는 픽셀 격자에 맞춘다. 정렬(가운데/왼쪽/오른쪽)은 일본어 글자 상자에서 잰다.

## 5. API

| 함수 | 하는 일 |
|---|---|
| `load_png(p)` / `save_png(rgba, p)` | float RGBA 0..1 |
| `measure_style(rgba, plate=None, lines=None) -> Style` | 채움(줄별 그라데이션 7점), 테두리 겹(두께·색), 그림자(dx·dy·두께·색·번짐), 글자 상자, 줄, em, 획 두께, 정렬, 판 여부 |
| `erase_text(rgba, mask=None) -> rgba` | 글자 뒤 판이 있는 그림에서 글자를 지우고 판을 복원(행·열 보간 + inpaint). 투명 배경이면 전부 투명 |
| `render(text, style, size=None, *, em, box, align, source, weight, hscale, tracking, min_hscale=0.8, margin, background, gradient, report, strict=True, gap_min, donors, fit_height=True, calibrate=True)` | 그리기. 4배로 그려 줄임 |
| `redraw(jp, text, fmt=None, style=None, jp_text=None, **render_kw) -> (rgba, report)` | 재기 + (판이면 지우기) + 그리기 + bleed + 양자화 + compare/verdict |
| `finalize(rgba, fmt)` | 포맷대로 양자화(LA4·L·A·RGBA4·5551·565·RGB8·ETC1·ETC1A4 실제 인코드/디코드) |
| `compare(jp, ko) / verdict(cmp)` | 높이·획 두께 비, 채움색, 테두리 두께·색, 그림자 위치 차 / 사람이 읽는 문제 목록 |
| `thicken(mask, r, gap_min)` | 틈을 지키며 두껍게 |
| `make_sheet(rows, path, zoom=3)` | 대조표. **1600px 넘으면 path_01, _02… 로 나눠 저장**하고 경로 목록을 돌려준다 |
| `save_tiled(pil_images, path)` | 같은 규칙으로 아무 그림이나 조각 저장 |
| `imgtext_bank.glyph_mask(text, height_px, source, ss, weight_px, strict, extra)` | 한 줄 글자 마스크(GlyphRun: `.level`, `.sources`, `.native`, `.font_name`) |
| `imgtext_bank.cut_glyphs(png, "SPEED") -> {글자: Glyph}` | 한 그림에서 글자 모양 떼어 내기(`render(donors=[(png, text)])`가 씀) |
| `imgtext_bank.word_glyphs(word, em, source)` | v1.0 호환 |

`render`/`redraw`의 키워드는 모두 선택 사항이다. v1.0 호출은 그대로 동작한다(출처 선택과 굵기 기본값만 바뀌었다).

## 6. 묶음별 권장 설정 (시연·전수 시험 결과)

| 묶음 | 예 | 설정 |
|---|---|---|
| 흰 채움 + 검은 굵은 테두리 버튼 (battle_btn, kj_skill, kj_type, file_btn) | btn_USE, btn_KJ_LA_12, KJ_TYPE_02 | 기본값 |
| 테두리 없는 흰 목록 제목 (list_title, shop_title) | LTIT_ITEM, SHOP_TIT_BADGE | 기본값 |
| 랭크 이름 (얇은 남색 테두리 + 검은 그림자) | RANK_NAME_STAR | 기본값. 굵기 0.75~0.9로 원본보다 조금 가볍다 |
| 영문 판 (stat_en: BP→SP 등) | STbr_BP | `donors=[(원본 png, "BP"), (같은 판 STbr_SPEED png, "SPEED")]` — 같은 판의 3DX 글자를 그대로 쓴다 |
| 두 줄 패널 (guide_pnl 등) | btn_text_KJ_GUIDE_pnl_1 | `"군단\n메뉴"`처럼 줄바꿈만 주면 된다 |
| 오른쪽 정렬 (field_btn) | btn_F_MAP_OPEN | 기본값(정렬을 잰다) |
| 거대 전투 큰 글자 (HB, ETC1A4, em 16~22) | ja_slide_text, ja_modoru_text | 기본값. **I6의 v1.0용 덮어쓰기(`source: font`, `weight: 0.0`, `BIG_SOURCE`, `WEIGHT_FACTOR`)는 지운다** — 그 설정이 가늘고 흐린 결과의 원인이었다 |
| 한 글자 (예) | ja_sentaku_yes | 기본값이면 획이 원본보다 두껍게 재진다(1.4, 한 음절이라 재기 오차). 보기에 무거우면 `weight=원본획*0.8` |

## 7. 한계

- 획이 빽빽한 음절(슬·랭·돌 등)은 em 14~20px에서 원본 가나만큼 두꺼워지지 않는다(틈 보호). 0.75~0.9배.
- ETC1·ETC1A4: `finalize()`는 빌더와 같은 `libtex3ds.encode`를 부른다. 리드가 이 인코더를 고쳐서(etcpak 1차 + 보이는 블록마다 알파 가중 정밀 탐색, 블록별로 더 나은 쪽을 고르므로 etcpak보다 나빠지지 않음) 흰 글자 가장자리·1px 틈의 회색 얼룩이 없어졌다(C조 ETC1A4 15장 PSNR 36~42 → 52~99dB). 대신 한 장에 1~3초 걸린다. 환경변수 `LIBTEX3DS_ETC=fast`는 빠른 확인용일 뿐이고 설치용 빌드에는 쓰지 않는다. `imgtext_demo.py --smoke`는 ETC 40장 때문에 1~2분 더 걸리고 `build_lyt.py --selftest`는 약 3분이므로 타임아웃을 10분 이상으로 잡는다.
- `bank`/`same_word`는 em 14px 이상 1DX 그림에서만 쓴다. 작은 그림에서 뗀 음절은 꾸밈을 벗기면 모양이 깨졌다(I6 1차의 예·돌아가기·회).
- 판(불투명 바탕) 위 글자는 `erase_text`로 지운 뒤 그린다. 무늬가 복잡한 판은 결과를 꼭 눈으로 확인한다.
- 대조표는 3배 확대라 실제보다 거칠어 보인다. 1배(맨 위 작은 칸)를 기준으로 판단한다.

## 8. 요청·버그

`work\img\TOOLKIT_REQUESTS.md`에 적는다(조 이름, 텍스처, 기대 동작). I2가 30분마다 확인하고, 처리한 줄에 버전과 답을 단다. API는 뒤로 호환되게만 바꾼다.

## 바뀐 것

- 1.3 (2026-09-29): 글자 획을 텍스처 크기에서 재어 일본어와 같은 방법으로 비교, 너무 굵은 비트맵은 다음 출처로(I3-2). 
- 1.2 (2026-09-29): 1DX font_btl(em 11) 출처 추가(작은 글자를 자기 크기로), 기호는 1DX 폰트 먼저. TOOLKIT_REQUESTS D-1·D-2·I3-1·A-1·A-2·A-3 처리.
- 1.1 (2026-09-29): 줄 단위 출처 선택 + 크기 규칙(1.25배) + 은행 품질·묶음 검사, 벡터 글꼴 GothicA1(목표 크기로 직접 렌더), 틈 보호 굵기 + 재측정 보정, 비트맵 원래 크기·픽셀 격자 맞춤, 높이 맞춤, 두 줄 자동 분리, 원본 영문 재사용(`jp_text`/`donors`), 채움 그라데이션 끝줄 오염 수정, kmeans 결과 고정(실행 순서에 따라 결과가 달라지던 문제), 대조표 1600px 조각 저장.
- 1.0: 첫 판(measure_style·erase_text·render·finalize·compare, 1DX 은행).
