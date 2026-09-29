# 작업지시서: 용어집 작성 (카테고리별)

목표: 3DX 일본어 용어 → 한국어 표기를 확정한다. 번역 전체의 일관성이 이 표에 달려 있다.
먼저 `AGENTS.md`의 0장(원칙)과 4.4(고유명사 규칙)를 읽는다.

## 표기 결정 순서 (반드시 이 순서)
1. **DS 한국판 표기** (`text/ref_ds_ko/*.json`, 목록 요약 `work/gloss/ds_lists.json`)가 있으면 그대로. 띄어쓰기까지 동일하게.
   → `basis=DS`, `source=<DS파일>#<번호>` (예: `BData__mfset_WearN#12`)
2. DS에 없으면 **한국닌텐도 공식 표기**: 다른 정발 게임(마리오&루이지 RPG 시리즈, 마리오 카트 8 디럭스, 슈퍼 마리오 오디세이, 슈퍼 마리오브라더스 원더, 마리오 파티, 페이퍼 마리오 등)·nintendo.co.kr·공식 가이드. 웹 검색으로 **근거 URL을 확인**한다.
   → `basis=official`, `source=<URL>`
3. 그래도 없으면 새로 짓는다: 일본어 말장난·의미를 살리고 DS 명명 방식(짧고 입에 붙게)에 맞춘다.
   → `basis=coined`, `note`에 작명 이유
- 일본어와 같은 대상인지 확신이 없으면 `note`에 “확인 필요”라고 쓴다. 추측을 DS 근거로 적지 않는다.
- 한국어는 KS X 1001 한글 2,350자 안에서만(폰트 제약). 예: 똠·뷁 불가.
- 이름 칸이 좁다: 원문보다 눈에 띄게 길게 짓지 않는다.

## 입력 자료
- 3DX 원문: `text/jp/*.json` (id, label, jp). 태그 `[Ruby 漢字;かな]`는 후리가나, `[Color ...]` 등은 서식.
- 요약 목록: `work/gloss/jp_lists.json`(3DX), `work/gloss/ds_lists.json`(DS 한국판 이름·설명 목록)
- DS 전체 대사 검색: `.venv\Scripts\python scripts\show_room.py --find-ds <한국어>` (FEvent 대사), 그 밖엔 grep 도구로 `text/ref_ds_ko` 검색.
- 3DX 검색: `.venv\Scripts\python scripts\show_room.py --find-jp <일본어>`

## 출력: `work/gloss/gl_<카테고리>.tsv` (UTF-8, 탭 구분, 첫 줄 헤더)
```
jp	ko	type	basis	source	note
スーパーキノコ	슈퍼버섯	item	DS	BData__mfset_UItmN#3	
```
- `type`: character / place / item / gear / badge / key_item / enemy / boss / attack / ability / ui / term / other
- `jp`는 원문에 나오는 그대로(후리가나 제외). 같은 대상의 표기 변형(예: 짧은 이름 Ns_)도 각각 한 줄씩.
- 담당 범위의 용어를 빠짐없이. 일반 명사(“コイン”, “HP” 같은 UI 용어 포함)도 게임 내 고정 표기가 있으면 넣는다.
- 파일 외 다른 파일은 만들거나 고치지 않는다. 끝나면 행 수, basis 분포, “확인 필요” 목록을 보고한다.
