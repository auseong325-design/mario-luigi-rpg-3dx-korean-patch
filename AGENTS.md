# AGENTS.md — 마리오&루이지 RPG3 DX 한글패치

이 문서는 이 저장소에서 일하는 모든 에이전트(메인·서브에이전트)의 **작업 계약서**다.
작업 전에 끝까지 읽고, 규칙이 바뀌면 이 문서를 먼저 고친다.

## 0. 목표와 원칙

- 대상: 3DS 『マリオ&ルイージRPG3 DX』 일본판 **v1.2** (타이틀 ID `00040000001CA900`, 업데이트 `0004000E001CA900`).
- 기준 번역: 원작 DS 『마리오&루이지 RPG3』 **한국 정발판**(게임코드 `CLJK`)의 공식 번역. (`!!!`는 일본판 제목에만 있었다.)
  - 원작과 같은 대사는 **DS 한국어를 그대로 쓴다**(띄어쓰기·문장부호까지). 3DX에서 달라진 부분만 고친다.
  - 원작에 없는 내용(쿠파Jr. RPG, 신규 UI·튜토리얼·amiibo 등)은 새로 번역하되 DS 번역의 문체·용어에 맞춘다.
- 한국어판 제목: **「마리오&루이지 RPG3 DX」**(리메이크는 일본판 제목에도 `!!!`가 없다). 쿠파Jr. 모드는 「쿠파주니어 RPG」.
- 글꼴·로고 기준: 한국 정발판 『마리오&루이지 RPG1 DX』(타이틀 ID `00040000001C4F00`, 덤프 `ml 1dx/`)와 통일한다.
  - 한글 글리프는 1DX 한국판 폰트를 **그대로** 쓴다. 1DX에 없는 음절만 1DX 음절을 조합해 만든다(7장). 다른 글꼴로 새로 그리는 것은 마지막 수단이다.
  - 타이틀 로고·이미지 속 글자는 1DX 한국판 로고와 이미지를 응용해 만든다.
- 고유명사 우선순위: ① `text/glossary.tsv` 확정값 → ② DS 한국판 표기 → ③ 한국닌텐도 공식 표기(다른 정발 게임·공식 사이트) → ④ 없을 때만 신조어(`basis=coined`로 표시하고 검토 대상).
  - ③의 첫 근거는 1DX 한국판 대사 `work/ref_1dx_ko.tsv`(`dump_1dx_text.py`)다. 쿠파주니어 RPG처럼 DS에 없는 용어는 1DX 쿠파군단 RPG에 같은 것이 있으면 그 표기를 쓴다(예: うちけし 스킬 지우기, サンダー 선더, ドッスンおとし 쿵쿵 떨어트리기, ころび 꽈당). 그림 속 글자는 1DX 그림도 함께 본다.
- 품질 기준: 원문 의미 보존 > 캐릭터 말투 일관성 > 자연스러운 한국어 > 글자 수. 번역투(“~하는 것이다”, 불필요한 피동/대명사)를 피한다. 말장난·개그는 의미를 살려 한국어 개그로 옮긴다.
- 원본 파일(`romfs/`, `romf2/`, `exefs/`, `exefs2/`, `unpacked/`, `*.nds`, `ml 1dx/`)은 **절대 수정하지 않는다**. 모든 산출물은 `text/`, `work/`, `patch/`에만 쓴다.

## 1. 원본 데이터와 버전 규칙

| 경로 | 내용 |
|---|---|
| `romfs/`, `exefs/` | 3DX v1.0 기본 게임 |
| `romf2/`, `exefs2/` | v1.2 업데이트 (바뀐 파일만: FEvent, FMdl/JP, RO/static.crs, .crr, 코드) |
| `mario&luigi rpg 3.nds`, `unpacked/` | DS 한국판 원본 |
| `work/nds_kr/data/` | DS 한국판을 mnllib 표준 형태로 푼 것 (압축 해제된 arm9/overlay 포함) |
| `ml 1dx/3romfs/`, `ml 1dx/3exefs/`, `ml 1dx/*.3ds` | 1DX 한국판 덤프(RomFS·ExeFS, 복호화된 .3ds). 폰트 `Msg/KR_ko/font*.bffnt`, 스태프롤 `Staffroll/KR/`, 이미지 `Lyt/KR`·`Obj/KR`·`FMdl/KR` |

- 3DX 파일은 항상 `scripts/lib3dx.py`의 `romfs_path()`로 읽는다 → `romf2`에 있으면 그것, 없으면 `romfs`. (v1.2 = 기본 RomFS + 업데이트 RomFS 덮어쓰기)
- 대사 파일(Msg/*)은 v1.0과 v1.2가 동일하다.

## 2. 디렉터리 구조

```
scripts/            파이썬 도구 (.venv\Scripts\python 으로 실행)
text/jp/            3DX 일본어 원문 (추출물, 손대지 않음) — 368파일 / 9,623메시지
text/ref_ds_ko/     DS 한국판 대사 (추출물, 손대지 않음) — FEvent 방별 + 전투/메뉴/데이터
text/align/room_map.json   3DX 방 이름 → DS 방 번호 목록 (번역 참조 연결)
text/glossary.tsv   용어집 (jp, ko, type, basis, source, note)
text/style_guide.md 캐릭터별 말투 가이드 (DS 한국판 분석 결과)
text/ko/            번역 결과 (배치 단위 JSON, 병합 전 원본)
work/batches/       번역 배치 (make_batches.py 생성물, 재생성 가능)
work/kr_font/       DS 한국판 폰트 판독 자료 (kr_table.json = 코드→문자 표)
patch/00040000001CA900/romfs/   최종 LayeredFS 출력 (Azahar 모드 폴더와 연결됨)
tools/              Kuriimu2(실행은 tools\Kuriimu2.cmd), SwitchToolbox, Spritoglobin-DX
fonts/              한글 폰트 후보 (OFL)
```

## 3. 파이프라인과 명령어

모든 명령은 프로젝트 루트에서 `.venv\Scripts\python scripts\<name>.py`.

| 단계 | 스크립트 | 비고 |
|---|---|---|
| 환경 점검 | `check_env.py` | |
| MSBT 무손실 검증 | `test_msbt_roundtrip.py` | 368/368 바이트 일치해야 함 |
| 3DX 원문 추출 | `extract_3dx_text.py` | → `text/jp/` |
| DS 폰트 표 병합 | `kr_merge_table.py` | 판독 2인 일치 + `kr_table_overrides.json` |
| DS 한국어 추출 | `extract_nds_kr_text.py` | → `text/ref_ds_ko/` |
| 1DX 한국어 추출 | `dump_1dx_text.py` | `ml 1dx/3romfs/Msg/KR_ko` 대사 7,867개 → `work/ref_1dx_ko.tsv`(key, index, label, text). 공식 용어 확인용(원본은 읽기만) |
| 1DX 대조 | `align_1dx.py` | 3DX 메시지를 라벨로 1DX 한국어와 짝지음(`KJGuide_`↔`KGGuide_`, `Menu_KJ_Chr_exp_`↔`KMsgChr_exp_`, 아이템·amiibo 라벨은 같음) → `work/review/kj_1dx_pairs.tsv`(`sim`=문장 유사도). 가이드 번호는 두 게임에서 뒤섞여 있으니 설명문으로 같은 것인지 확인 |
| 정렬·용어 자료 | `make_digests.py` | → `work/align/`, `work/gloss/` |
| 번역 배치 생성 | `make_batches.py` | → `work/batches/` (room_map·glossary 반영) |
| 번역 검증·병합 | `merge_ko.py` | `text/ko/` 검증 → 태그 복원 → 결과 보고 (`--merge` → `work/ko_final.json`) |
| 검토 분류 | `review_triage.py` | 대사별 DS 일치도(ds/edited/new/short) → `work/review/triage.json` |
| 패치 빌드 | `build_patch.py --fonts` | `work/ko_final.json` → 메시지 7개 + 한글 폰트 3개 → `patch/00040000001CA900/romfs/Msg/JP_ja/`. `--identity`는 번역 없이 원본과 바이트 일치를 검사 |
| 폰트만 | `build_font.py` | 번역문에 쓰인 글자를 font/font_l/font_btl에 추가(시트 추가). 글리프는 1DX 한국판 폰트에서 그대로 복사하고, 없는 한글만 조합하거나 확대한다(7장). `--same-size`는 시트 수를 유지하는 대체판, `--all-hangul`은 2,350자 전부, `--no-donor`는 예전 나눔스퀘어라운드판, `--compose-test`는 조합 정확도 검사 |
| 그림 코덱 | `libtex3ds.py` | 3DS 텍스처 포맷 전부(ETC1·ETC1A4 포함) 디코드/인코드, 8×8 타일 스위즐. ETC 인코드 = etcpak 1차 + 보이는 블록마다 알파 가중 정밀 탐색(블록별로 더 나은 쪽, etcpak보다 나빠지지 않음. 텍스처당 1~3초, `LIBTEX3DS_ETC=fast`로 끔). 인자 없이 실행하면 자체 검사 |
| 레이아웃 그림 | `lytimg.py extract` / `check` | Lyt/*.dat → `work/img/lyt/<게임>/…png` + `work/img/lyt_manifest.json`(중복 표시). `check` = 무손실 텍스처 디코드→인코드 바이트 일치 |
| 대조표 | `img_sheets.py` | 여러 그림을 한 장으로(분류·검토용) |
| 그림·로고·스태프롤 | `work/IMAGE_TASK.md` | 스트림별 빌더(`build_lyt.py`, `build_obj.py`, `build_fmdl.py`, `build_staffroll.py`)는 `work/build/<스트림>_stage/`에 쓰고, 리드가 검증 후 `patch/`에 설치 |

- 파이썬 명령은 반드시 **타임아웃을 걸어** 실행한다(과거 pymsbmnl이 EOF에서 무한루프로 90분 멈춘 적 있음. MSBT는 `lib3dx.py`의 자체 코덱만 사용).
- 게임 파일이 없는 곳(클라우드)에서도 `merge_ko.py`가 돈다: 폭은 `work/font_metrics.json`(게임 파일이 있는 곳에서 `python scripts/lib3dx.py --export-font-metrics`로 만든 글자 폭 표)을, 그것도 없으면 추정 폭(경고 출력)을 쓴다. 추정 폭으로 검사했으면 한도 가까운 줄은 로컬에서 다시 검사한다.
- PowerShell에서 환경변수는 `$env:NAME`. 문자열 안의 `"$var:"`는 파싱 오류가 나므로 `"${var}:"`로 쓴다.

## 4. 번역 규칙

### 4.1 번역자가 보는 형식 (배치의 `src`)

- `{n:kind}` = 게임 제어태그 자리표시자. **각 자리표시자를 정확히 한 번씩** 번역문에 넣는다. 순서는 한국어 어순에 맞게 바꿔도 된다(단, 선택지 관련 태그는 순서 고정). 새 자리표시자를 만들지 않는다.
  - `{n:color}`: 강조색 전환. 보통 `강조색 → 기본색` 짝으로 나온다. **대응하는 한국어 단어를 감싼다**. 예: `{1:color}パズルピース{2:color}を手に入れた！` → `{1:color}퍼즐피스{2:color}를 획득했다!`
    - 색이 바뀌는 자리는 낱말 경계로 한다. 명사 뒤 조사는 강조 밖에 둬도 되지만, 용언을 어간과 어미 사이에서 쪼개지 않는다. 예: `[다리를 돌리]려면`(X) → `[다리를 돌릴] 때는`(O).
  - `{n:font}`: 글자 크기 전환(강조). `…{a:font}8回{b:font}…`처럼 짝으로 나오면 대응하는 한국어 단어를 감싼다.
  - `{n:wait}`: 버튼 입력 대기(페이지/대사 끝). 원문과 같은 위치(해당 문장 끝)에 둔다.
  - `{n:pause}`: N프레임 멈춤(말 사이의 뜸). 같은 말(“ガ…{pause} ガハハ” → “크…{pause} 크하하”) 뒤에 둔다.
  - `{n:speed}`: 글자 속도 변경. 원문과 같은 구절 앞에 둔다.
  - `{n:align}`, `{n:mode}`, `{n:tag}`: 줄/문장 서식. 원문과 같은 상대 위치(대개 줄 맨 앞)에 둔다.
  - `{n:var}`: 실행 중에 **숫자나 이름**이 들어간다(“第{var}問” = “제{var}문”). 뒤에 받침에 따라 바뀌는 조사(을/를, 이/가, 은/는, 와/과, 로/으로)를 붙이지 않는다 → “{var}개를”, “{var}코인”처럼 단위를 붙이거나 문장 구조를 바꾼다. `을(를)` 형태는 쓰지 않는다.
  - `{n:choice}` `{n:tab}` `{n:indent}`: **선택지**. `{choice}` 바로 뒤가 선택지 한 개의 글자, `{tab}`은 같은 줄 선택지 사이 간격, `{indent}`는 줄 시작 들여쓰기다. 이 태그들의 **순서와 선택지 줄바꿈은 원문 그대로** 두고 선택지 글자만 번역한다. 선택지는 짧게(예: 「はい/いいえ」 → 「예/아니요」).
  - `{n:icon}`: 버튼/아이콘 글리프. 그대로 둔다. DS식 `Ⓐ` 같은 문자로 바꾸지 않는다.
- `[Next]` = 페이지 넘김. **원문과 같은 개수**를 유지한다(페이지마다 음성·연출 타이밍이 붙어 있다).
- 후리가나(ruby)는 이미 제거돼 있다. 한국어에 후리가나를 넣지 않는다.
- `\n`은 줄바꿈. 줄바꿈 위치는 자유롭게 다시 잡는다(아래 폭 규칙).

### 4.2 줄 폭과 줄 수

- 폭 계산: 한글·전각문자 16px, 공백 5px, 영숫자는 폰트 폭(대략 9~14px). `merge_ko.py`가 자동 계산한다.
- 한 줄 한도 = 같은 파일·같은 style에서 일본어 원문이 쓴 **최대 폭**. 권장은 그보다 여유 있게.
  - 필드 대화(FMsg style 6): 한 줄 **한글 약 18자 이하 권장**, 절대 21자(336px) 초과 금지. 한 페이지 **3줄 이하**.
  - 전투 힌트(BMsg style 11): 한 줄 약 22자 이하, 4줄 이하.
  - 메뉴/아이템 이름(짧은 라벨): 원문보다 눈에 띄게 길어지지 않게. 이름 칸은 원문 폭을 넘기지 않는다.
- 한 페이지 줄 수는 원문 페이지의 줄 수를 넘기지 않는 것을 원칙으로 한다(원문이 1줄짜리 알림이면 1줄).

### 4.3 문자 제한

- 사용 가능: **KS X 1001 한글 2,350자**, ASCII, `… ! ? ~ ・ · ― 「 」 ( ) % & ♪ ♥ ★ ☆ × ↑ ↓ ← → ※` 등 DS판에 쓰인 기호.
- 일본어 전각 기호는 한국식으로: `！？` → `!?`, `～` → `~`, `…`는 유지, `、。`는 쓰지 않는다(쉼표·마침표 또는 생략).
- 강조 따옴표는 DS판처럼 `「 」`(드물게) 또는 색 태그를 쓴다.
- KS X 1001 밖의 음절(예: 똠, 뷁, 햏)은 폰트에 없으므로 금지. 검증기가 걸러낸다.

### 4.4 고유명사·용어

- `text/glossary.tsv`에 있으면 **무조건 그 표기**. 배치 파일의 `glossary` 필드에 해당 배치에 필요한 항목이 들어 있다.
- 글로서리에 없는 고유명사를 만나면: DS 참조(`ds_reference`)에서 찾아 그대로 쓰고, 출력의 `new_terms`에 `basis: "DS"`로 기록한다. DS에 없으면 한국닌텐도 공식 표기를 따르고(`basis: "official:<근거 URL>"`), 그래도 없을 때만 새로 짓는다(`basis: "coined"`).
- DS판 확정 예: 피치공주(붙여 씀), 쿠파님(부하들이 부를 때), 마리오님/루이지님(키노피오 등이 부를 때), 키노피오, 퍼즐피스, 헐렁헐렁웨어, 배지, 스페셜 어택, 등껍질 랭크.

### 4.5 말투

- `text/style_guide.md`의 캐릭터별 말투를 따른다(DS 한국판에서 추출). 같은 캐릭터가 DS에서 반말이면 3DX 신규 대사도 반말.
- DS 참조 문장이 있으면 그 말투·어미가 곧 정답이다.

### 4.6 DS 참조 사용법

- 배치의 `ds_reference`는 대응하는 DS 방의 한국어 대사 전부(순서대로)다. 3DX 문장과 뜻이 같으면 **DS 문장을 그대로 가져오고**, 줄바꿈만 3DX 폭에 맞춰 다시 잡는다.
- 3DX에서 내용이 추가·변경됐으면 바뀐 부분만 고쳐 쓴다. DS 문장에 끼워 맞추느라 원문 의미를 바꾸지 않는다.
- 참조가 비어 있거나 대응 문장이 없으면(신규 내용) 새로 번역한다.
- DS 문장의 명백한 맞춤법·띄어쓰기 실수는 고치고, `notes`에 `DS 오기 수정`이라고 남긴다(예: `효과가 미비하지만`→`미미하지만`, `성쪽에서`→`성 쪽에서`). DS가 일관되게 쓴 표기 관례는 실수로 보지 않고 그대로 따른다(예: `쿠파씨`처럼 `씨`를 붙여 쓰기).

### 4.7 금지

- 원문에 없는 정보 추가, 대사 생략, 자리표시자 누락/중복, `[Next]` 개수 변경, 일본어 문자 잔존.
- `text/jp/`, `text/ref_ds_ko/`, 원본 게임 파일 수정.

## 5. 서브에이전트 작업 방식

### 5.1 번역 배치

- 입력: `work/batches/<batch>.json`
  - `messages[]`: `id`, `label`(문맥 힌트), `style`, `src`(번역할 문장), `dups`(같은 문장이 쓰이는 다른 id — 자동 복사됨)
  - `ds_reference[]`: `DS<방>#<번호>: <한국어>` / `glossary[]`: 이 배치에 나오는 확정 용어
- 출력: `text/ko/<batch>.json` (UTF-8)

```json
{
  "batch": "<batch id>",
  "translations": {"FMsg/o_town_33#0": "{1:align}고마워요\n마리오님, 루이지님.{2:wait}[Next]..."},
  "new_terms": [{"jp": "コッキー", "ko": "...", "type": "character", "basis": "DS", "note": ""}],
  "notes": {"FMsg/o_town_33#5": "불확실한 점"}
}
```

- 배치의 **모든 메시지**를 번역한다. 끝나면 `python scripts\merge_ko.py --check <batch>`로 스스로 검증하고, 오류가 0이 될 때까지 고친다.
- 한 서브에이전트는 같은 지역의 배치를 연속으로 맡는다(용어·말투 일관성).

### 5.2 검증·병합 (`merge_ko.py`)

검사 항목: 누락 메시지, 자리표시자 집합 일치, `[Next]` 개수, 줄 폭/줄 수, 사용 불가 문자, 일본어 잔존, 글로서리 용어 미사용(경고). 오류가 있는 배치는 병합하지 않고 보고서에 남긴다.

- 같은 문장을 여러 곳이 함께 쓰는 복사본(`dups`)은 번역을 공유하되, 병합할 때 복사본마다 **자기 원문의 제어 태그**(말풍선 헤더, 뜸 길이, 색, 버튼 아이콘)로 복원한다.
- 장면이나 듣는 사람이 달라 복사본에 다른 번역이 필요하면 `text/ko/_dup_overrides.json`의 `translations`에 id별로 넣고 `notes`에 이유를 쓴다. `--merge`가 그 id의 원문으로 검사한 뒤 적용하고, 오류가 있으면 적용하지 않고 보고한다(배치 파일에 복사본 id를 넣으면 검사기가 막는다).

### 5.3 리뷰

- 번역 완료 후 다른 에이전트가 배치 샘플을 교차 검토한다(의미 오류·말투·용어). 수정은 원 번역 파일에 직접 반영하고 `notes`에 “review:” 접두어로 남긴다.
- 용어집 변경 시 해당 용어가 들어간 모든 배치를 `merge_ko.py --grep <용어>`로 찾아 일괄 수정한다.

### 5.4 오케스트레이션(메인 에이전트)

- 동시에 최대 12개 서브에이전트(런타임 한도, 넘치면 자동 대기). 한 에이전트당 같은 지역 배치 2~6개(메시지 약 100~450개).
- 서브에이전트가 도구 호출 없이 말만 하고 끝나면(1차에서 5명) 빈 결과로 끝난다. 결과가 비었으면 `spawn_continue`로 같은 대화를 이어서 재개하고, 대화가 만료됐으면 새로 투입한다.
- 진행 상태의 기준은 파일이다: `work/batches/_index.json`(전체) vs `text/ko/*.json`(완료). 컨텍스트가 끊겨도 파일로 재개한다.
- 서브에이전트 결과는 반드시 `merge_ko.py`로 검증한 뒤에만 완료로 간주한다.

## 6. 테스트 (Azahar)

- `%APPDATA%\Azahar\load\mods\00040000001CA900` → `patch\00040000001CA900` 정션으로 연결돼 있다. 빌드 결과를 `patch\...\romfs\`에 두면 Azahar에서 게임을 켜기만 하면 적용된다. v1.2 업데이트 CIA가 Azahar에 설치돼 있어야 한다.
- 사용자가 직접 실행해 확인한다. 패치는 항상 최신 빌드가 적용된 상태로 유지한다.

## 7. 기술 메모

- 3DX 텍스트: `Msg/JP_ja/FMsg.dat`(BG4, 방별 MSBT 362개), `BMsg.dat`(전투 b_sys), `Item/Menu/MenuKJ/HugeBattle/InitLoad.msbt`. MSBT 구조: LBL1(101버킷)·ATR1(4바이트)·TSY1·TXT2, UTF-16LE, 0x00 패딩. `lib3dx.py`가 바이트 단위 무손실 왕복.
- 3DX 폰트: `font.bffnt`(18×18, A4, 1시트 1378칸), `font_l`, `font_btl`, `font_ruby`, `gaizi`(아이콘, 1DX와 바이트까지 같음), `Staffroll/mario_font.bffnt`. 한글은 `build_font.py`가 시트를 늘려 넣는다(font 2장, font_l 3장, font_btl 2장). 3DX 원래 글리프·폭·매핑은 바꾸지 않는다. 폰트가 커져 게임이 멈추면 `--same-size`판(`work/build/same_size_romfs/`)으로 바꾼다.
- 한글 글리프 출처(`build_font.py`, 먼저 되는 것):
  1. 1DX 한국판 같은 역할 폰트(`ml 1dx/3romfs/Msg/KR_ko/font`, `font_l`, `font_btl`)의 글리프를 픽셀 그대로 복사한다. 한글은 1DX 폭(CWDH)도 그대로 쓴다. 칸 크기가 달라(1DX 17×18·23×24·13×14) 세로 위치만 옮긴다: 한글은 3DX 한자 칸 중심에 맞추고(font +1, font_l +2, font_btl −1), 문장부호는 3DX 영문 기준선에 맞춘다.
  2. 1DX에 없는 음절은 `hangul_compose.py`가 1DX 음절 셋으로 조합한다. 1DX는 자기 대사에 쓴 음절만 담고 있다(font·font_btl 1,103자, font_l 287자). 조합식은 A+B−B′이다(예: 펀 = 펄 + 번 − 벌). 대화·전투 폰트에서 163자가 이 경우이고, 있는 음절을 빼고 다시 만들어 본 검사에서 IoU 0.89가 나왔다(다른 글꼴로 그리면 0.69).
  3. font_l에는 1DX 대화 폰트 글자를 1.5배로 확대해 넣고, 1DX font_l 진짜 글자와 톤을 맞춘다(히스토그램 매칭).
  4. 그래도 없는 것만 `fonts/`에서 렌더링한다. 한글은 몫·쬔·췄·핥·휩 5자, 나머지는 `* · ■ ▲ ●` 같은 기호다.
- 영문·숫자·`?`·`.`·공백은 3DX 원래 글리프를 쓴다. 1DX 것은 폭이 넓어서(공백 8px, 숫자 12~13px) 바꾸면 줄바꿈과 메뉴 칸이 달라진다. 1DX 글리프로 새로 넣은 문장부호는 merge_ko 폭 모델에 맞춰 옆 여백만 줄였다(`!` 6, `,` 5, `:` 5). `~`·`%`는 잉크가 넓어 1DX 폭 16px을 그대로 쓰고, merge_ko 모델도 16으로 바꿨다.
- 이전 나눔스퀘어라운드판 폰트: `work/build/prev_fonts_nanum/`(되돌릴 때 `patch/.../Msg/JP_ja/`에 복사) 또는 `build_font.py --no-donor`.
- DS 한국판 텍스트: 1바이트 코드 = arm9 폰트(0x43D90), 2바이트 `F9~FE xx` = 대체 폰트(전역 코드). 표: `work/kr_font/kr_table.json`(1,158자, 2인 독립 판독 일치 + 수동 5건).
- 대사 밖 일본어: HB/*.csv(개발용 파라미터명), RO/HugeBattle.cro(디버그 문자열)뿐 — 번역 불필요. 이미지 속 글자(Obj/JP, Lyt/JP, FMdl/JP 타이틀 로고)와 스태프롤(Staffroll/JP/Staffroll.bin)은 `work/IMAGE_TASK.md`.
- 그림 형식(확인됨): `Lyt/JP/*.dat` = BG4 → BLZ → SARC(bflyt·bflan·bflim, 폰트 없음). BFLIM은 저장 크기가 (p2(h)×p2(w))이고 90° 회전(플래그 4)이나 전치(플래그 8, ETC 전부) 상태로 저장된다(최소 변 8, ETC1은 16). 현지화 텍스처는 이름에 `_JP_ja`(1DX는 `_KR_ko`)가 붙는다(3DX 고유 1,158개 중 214개). `Obj/JP/*.dat` = AlphaDream 스프라이트(BG4, 픽셀 버퍼 + 설명 데이터 + 중첩 BG4 `_CA_INFO_`). `FMdl/JP/FMdl.dat` = BCH 모델(v1.2판이 romf2에 있음; 타이틀 로고 `fmd_title_JP_ja`, `fmd_title_start_JP_ja`, `fmd_ev_tfp_JP_ja`). 1DX 한국판 타이틀 로고는 `MGMap/KR/MGMap.dat`의 `mg_map_title_logo_KR_ko`.

## 8. 남은 작업 (순서)

1. (완료) 방 정렬·용어집·말투 가이드 → 전 배치 번역 → 교차 리뷰 → 1DX 한국판 글리프 폰트 → 패치 빌드.
2. 그림 속 글자·로고·스태프롤(풀 한글화): `work/IMAGE_TASK.md`. 1차 = I1 레이아웃 빌더·전수 목록, I2 한글 그림 글자 도구, I3 스프라이트, I4 모델 텍스처·로고, I5 스태프롤, I6 거대 전투 UI(HB/JP_ja). 2차 = 레이아웃 한글 그림(I1의 묶음별 분배). 3차 = 교차 검수 → 통합 빌드 → Azahar 테스트.
   - 2026-09-30: 수정 2라운드(I3 팔레트, B 굵기, I6 작은 글자)와 3차 검수·통합 빌드 완료. Lyt·Obj·HB는 `patch/`에 설치했다(MLyt는 파일 선택 로고를 뺀 빌드). **로고**(타이틀 FMdl, 파일 선택 MLyt)와 게임 시작 버튼은 사용자 승인 뒤 설치한다(`work/lead_state.json` `build.logo_install_after_ok`). 남은 것은 Azahar 테스트.
3. 글 수정 잔여: 설정 「후리가나 표시」 이름(게임 화면 보고 결정). (「※」 4줄 복원과 1DX 공식 용어 4개 반영은 2026-09-30 완료, `work/textpass_20260930.py`. 1DX 용어 정렬 리뷰(`work/review/kj_1dx_terms.md`)와 TEXT PASS 2(기술명·띄어쓰기·amiibo 문구, `work/textpass2_20260930.py`)도 2026-09-30 완료. TEXT PASS에서 glossary 행을 바꾸면 `text/glossary_overrides.tsv`에도 넣는다 — `build_glossary.py`가 재생성할 때 override만 남는다)
4. 게임 화면 확인 목록: `work/lead_state.json`의 `review_items`, `font_phase`.
