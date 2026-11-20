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
- 2026-10-08 사용자 추가 요청: 인트로 로고 조립 문제는 메인 에이전트가 **Codex 내장 computer-use**로 Azahar를 직접 조작해 재현·수정·재검증한다. Orca나 별도 Windows 입력 스크립트로 대체하지 않는다. 이 범위에서는 위 사용자 실행 원칙 대신 직접 검증을 수행하며 서브에이전트는 사용하지 않는다.

## 7. 기술 메모

- 3DX 텍스트: `Msg/JP_ja/FMsg.dat`(BG4, 방별 MSBT 362개), `BMsg.dat`(전투 b_sys), `Item/Menu/MenuKJ/HugeBattle/InitLoad.msbt`. MSBT 구조: LBL1(101버킷)·ATR1(4바이트)·TSY1·TXT2, UTF-16LE, 0x00 패딩. `lib3dx.py`가 바이트 단위 무손실 왕복.
- 3DX 폰트: `font.bffnt`(18×18, A4, 1시트 1378칸), `font_l`, `font_btl`, `font_ruby`, `gaizi`(아이콘, 1DX와 바이트까지 같음), `Staffroll/mario_font.bffnt`. 한글은 `build_font.py`가 시트를 늘려 넣는다(font 2장, font_l 3장, font_btl 2장). 3DX 원래 글리프·폭·매핑은 바꾸지 않는다. 폰트가 커져 게임이 멈추면 `--same-size`판(`work/build/same_size_romfs/`)으로 바꾼다.
- 한글 글리프 출처(`build_font.py`, 먼저 되는 것):
  1. 1DX 한국판 같은 역할 폰트(`ml 1dx/3romfs/Msg/KR_ko/font`, `font_l`, `font_btl`)의 글리프를 픽셀 그대로 복사한다. 한글은 1DX 폭(CWDH)도 그대로 쓴다. 칸 크기가 달라(1DX 17×18·23×24·13×14) 세로 위치만 옮긴다: 한글은 3DX 한자 칸 중심에 맞추고(font +1, font_l +2, font_btl −1), 문장부호는 3DX 영문 기준선에 맞춘다.
  2. 1DX에 없는 음절은 `hangul_compose.py`가 1DX 음절 셋으로 조합한다. 1DX는 자기 대사에 쓴 음절만 담고 있다(font·font_btl 1,103자, font_l 287자). 조합식은 A+B−B′이다(예: 펀 = 펄 + 번 − 벌). 대화·전투 폰트에서 163자가 이 경우이고, 있는 음절을 빼고 다시 만들어 본 검사에서 IoU 0.89가 나왔다(다른 글꼴로 그리면 0.69).
  3. font_l에는 1DX 대화 폰트 글자를 1.5배로 확대해 넣고, 1DX font_l 진짜 글자와 톤을 맞춘다(히스토그램 매칭).
  4. 그래도 없는 것만 `fonts/`에서 렌더링한다. 한글은 몫·쬔·췄·핥·휩 5자, 나머지는 `* · ■ ▲ ●` 같은 기호다.
- (2026-10-30 변경) `font`·`font_btl`의 영문·숫자·문장부호 75자는 **1DX 한국판 글리프**를 한글과 같은 기준선에 둔다(한 문자열 안에서 3DX 라틴과 1DX 한글이 섞여 보이던 문제). 폭은 1DX 폭이 아니라 일본판 라틴 자간에 맞춘 좁은 폭(잉크 왼쪽 0·오른쪽 1px, 닿는 쌍만 +1px)이고, 공백은 3DX 5px 그대로다. 만든 곳 `work/build/menu_font_stage/`(`build_menu_font.py` → `build_menu_font_v2.py`, 보고서 `work/review/menu_fonts_20261030/REPORT.md` §10). **`build_font.py`를 다시 돌리면 그 뒤에 이 두 스크립트를 다시 돌려야 한다.** merge_ko 폭 모델은 `scripts/font_ascii_widths_v2.json`을 읽는다. 런타임 숫자(코인·HP·능력치·개수·가격)는 그림 숫자, 대사 속 숫자 변수는 전각 숫자라 이 변경과 무관하다. `font_l`은 바꾸지 않았다. 바꾸기 전 폰트: `work/build/prev_wave5_20261030/`.
- (2026-10-30 이전 규칙, 참고) 영문·숫자·`?`·`.`·공백은 3DX 원래 글리프를 썼다. 1DX 글리프로 새로 넣은 문장부호는 merge_ko 폭 모델에 맞춰 옆 여백만 줄였다(`!` 6, `,` 5, `:` 5). `~`·`%`는 잉크가 넓어 1DX 폭 16px을 그대로 쓰고, merge_ko 모델도 16으로 바꿨다.
- 대사 속 글자 크기 태그 `[0000:0001:XX 00]`(번역 화면의 `{n:font}`)의 XX는 폰트 번호가 아니라 크기 코드다. 코드 표 `DAT_003a02f4`(v1.2 code.bin)로 바뀐다(2026-11-16 확인).
  - 00 → font_btl(작게), 01 → font, 02 → font_l(크게), 03 → font_btl 사본, 04 → font 사본, 06 → font, FF FF → 스타일 기본.
  - `merge_ko.py`는 이 구간도 16px로 센다. 큰 글씨 폭은 `work/review/final_check_20261116/tools/width.py`로 잰다.
- 이전 나눔스퀘어라운드판 폰트: `work/build/prev_fonts_nanum/`(되돌릴 때 `patch/.../Msg/JP_ja/`에 복사) 또는 `build_font.py --no-donor`.
- DS 한국판 텍스트: 1바이트 코드 = arm9 폰트(0x43D90), 2바이트 `F9~FE xx` = 대체 폰트(전역 코드). 표: `work/kr_font/kr_table.json`(1,158자, 2인 독립 판독 일치 + 수동 5건).
- 대사 밖 일본어: HB/*.csv(개발용 파라미터명), RO/HugeBattle.cro(디버그 문자열)뿐 — 번역 불필요. 이미지 속 글자(Obj/JP, Lyt/JP, FMdl/JP 타이틀 로고)와 스태프롤(Staffroll/JP/Staffroll.bin)은 `work/IMAGE_TASK.md`.
- 그림 형식(확인됨): `Lyt/JP/*.dat` = BG4 → BLZ → SARC(bflyt·bflan·bflim, 폰트 없음). BFLIM은 저장 크기가 (p2(h)×p2(w))이고 90° 회전(플래그 4)이나 전치(플래그 8, ETC 전부) 상태로 저장된다(최소 변 8, ETC1은 16). 현지화 텍스처는 이름에 `_JP_ja`(1DX는 `_KR_ko`)가 붙는다(3DX 고유 1,158개 중 214개). `Obj/JP/*.dat` = AlphaDream 스프라이트(BG4, 픽셀 버퍼 + 설명 데이터 + 중첩 BG4 `_CA_INFO_`). `FMdl/JP/FMdl.dat` = BCH 모델(v1.2판이 romf2에 있음; 타이틀 로고 `fmd_title_JP_ja`, `fmd_title_start_JP_ja`, `fmd_ev_tfp_JP_ja`). 1DX 한국판 타이틀 로고는 `MGMap/KR/MGMap.dat`의 `mg_map_title_logo_KR_ko`.

## 8. 남은 작업 (순서)

- 2026-10-07 사용자 검토 지침: 표현 검토 2건(i_metaboru_06#43, i_energy_32#19)은 현행을 유지한다. 한국어 출력에 필요 없는 후리가나는 제거한다. 재등장하는 마리오 시리즈 캐릭터의 신규 대사는 한국어 공식 말투를 검색·대조해 반영하고, 오리지널 캐릭터는 DS 번역과 캐릭터성에 맞춘다. 임시 이벤트 아이템 이미지 6종은 기존 처리대로 유지한다.
- 2026-10-07 추가 사용자 지침: 후속 작업은 메인 에이전트가 직접 수행하며 서브에이전트를 사용하지 않는다. SS컴퍼니 인물은 スーリム=슬림, キュット=큐티, ムチオ=마초로 확정한다. スーさん은 슬림씨로 통일하며 용어집 override에도 기록한다.

1. (완료) 방 정렬·용어집·말투 가이드 → 전 배치 번역 → 교차 리뷰 → 1DX 한국판 글리프 폰트 → 패치 빌드.
2. 그림 속 글자·로고·스태프롤(풀 한글화): `work/IMAGE_TASK.md`. 1차 = I1 레이아웃 빌더·전수 목록, I2 한글 그림 글자 도구, I3 스프라이트, I4 모델 텍스처·로고, I5 스태프롤, I6 거대 전투 UI(HB/JP_ja). 2차 = 레이아웃 한글 그림(I1의 묶음별 분배). 3차 = 교차 검수 → 통합 빌드 → Azahar 테스트.
   - 2026-09-30: 수정 2라운드(I3 팔레트, B 굵기, I6 작은 글자)와 3차 검수·통합 빌드 완료. Lyt·Obj·HB·FMdl을 `patch/`에 설치했다. 로고(타이틀 FMdl, 파일 선택 MLyt)와 게임 시작 버튼도 사용자 검토를 거쳐 설치했다(개선 여지는 `review_items`). 남은 것은 Azahar 테스트.
   - 2026-10-02: 타이틀 로고(마리오&루이지·디럭스·인트로 조각)와 파일 선택 「마리오&루이지 RPG3」 로고를 v2로 다시 만들어 설치했다. 1DX 글자 골조에 일본판에서 잰 재질 모델(광택 초승달·행 그라데이션·테두리·입체·블러 글로우)을 입히고, 같은 모델로 일본어 글자를 다시 그려 원본과 맞는지 먼저 확인한다. `work/img/logo2/run_all.py`, 기록은 `work/img/I4.md` 9장.
   - 2026-10-08: 메인 에이전트가 Codex 내장 computer-use로 Azahar v1.2 인트로의 `&` 하방 어긋남을 재현하고 수정·재검증했다. 텍스처 행 방향의 보정 부호를 고쳐 인트로 `&` 그림만 24행 위로 이동했다. 실제 조립 유지/분리·회전/타이틀 화면 확인 완료. 메인 타이틀 그림·원래 모델/애니메이션은 동일하며 patch/정션/SD/ZIP 36파일 일치. 최신 레시피·보고서: `work/img/logo_runtime_fix_20261008/build_intro.py`, `REPORT.md`.
   - 2026-10-08: 모드 선택 화면 「마리오&루이지 RPG3」도 최신 1DX 글자·&와 3DX 색·광택·하단 음영으로 갱신했다. MLyt의 좌우 그림 두 장만 교체, 메인 타이틀·인트로 FMdl 동일. Codex 내장 computer-use로 Azahar v1.2 해당 화면 직접 검증 완료, patch/정션/SD/ZIP 36파일 일치. 최신 레시피·실제 화면·보고서: `work/img/fileload_logo_20261008/build_fileload.py`, `runtime_before_after.png`, `REPORT.md`.
   - 2026-10-08: 모드 선택 로고의 G·3 접합부 흰색 각·잔점·절단 흔적을 곡선으로 수정했다. MLyt 오른쪽 텍스처 203픽셀만 변경, 글자 면·광택·일러스트와 메인 타이틀·인트로 FMdl 동일. Codex 내장 computer-use로 Azahar v1.2 실제 화면 검증 완료, patch/정션/SD/ZIP 36파일 일치. 최신 외곽선 보고서·실제 확대 비교: `work/img/fileload_outline_fix_20261008/REPORT.md`, `runtime_detail_before_after.png`.
   - 2026-10-09: 모드 선택 「마리오&루이지 RPG3」 그림에서 로고를 지우고, 로고에 가려진 쿠파 머리를 박스아트 쿠파로 채운 배경판을 설치했다(로고는 나중에 따로 얹는다, 쿠파주니어 쪽은 무관). 레시피·보고서: `work/img/fileload_nologo_20261009/build_nologo.py`, `REPORT.md`. 로고 있는 직전판 백업 `work/build/prev_fileload_nologo_20261009/`.
   - 2026-10-09: 그 배경에 최신 메인 타이틀 로고를 타이틀 화면에 보이는 비율 그대로(가로:세로 0.940, 글자+3 한 변환, 균등 0.971배) 얹었다. 일본판처럼 실루엣·DX·발광·™은 없다. 겹침 순서도 타이틀과 같다(글자 → 숫자 판; 판이 G 오른쪽을 덮고 판의 소용돌이가 G 꼬리). 일본판 모드 선택의 축별 배율을 쓰면 글자가 납작해지므로 쓰지 않는다. 레시피 `work/img/fileload_titlelogo_20261009/build_fileload_title.py`(logo2/run_all.py가 호출), 보고서 `REPORT.md`.
   - 2026-10-09: 파일 선택 「쿠파주니어 RPG」 로고 재작업 1단계(흑백 벡터 자형 A안·B안, 원본 실루엣 비교)만 했다. **자형 승인 전이므로 색·질감·설치 작업은 하지 않는다**(설치본은 9/30 원래 그림 그대로). 원판 「クッパJr.」 = MARIO Font 글자별 배치. 기초 자형 = 1DX 한국판 쿠·파 골격 + 원판 굵기. 쿠키런 폰트는 게임 사용 금지 라이선스라 쓰지 않는다. 기록·SVG·시트: `work/img/kj_logo_20261009/README.md`.
   - 2026-10-09 (2차): 사용자 지시로 자형 기준을 마리오 파티 9 「가든 배틀」의 한글 글꼴로 바꿨다. 이 글꼴은 **한국어 슈퍼 마리오 서체**로 특정했다. 닌텐도 한국이 만든 로고용 레터링이고 글꼴 파일은 없다. HY엽서는 화면 글자용 펜글씨체여서 맞지 않는다. 공식 로고의 쿠·파·어 등에서 자모를 따 `kst.py`로 그렸다(KA안·KB안, `sheets/kst_approval.png`). 아직 자형 승인 대기 중이며, 색·질감·설치는 하지 않았다.
   - 2026-10-09 (3차): 사용자가 준 공식 「쿠파」「쿠파주니어」 그림(같은 서체)을 기준으로 다시 짰다. 공식 글자의 획을 반듯한 막대로 다시 세우고 수치를 맞췄다(`fit_official.py`, IoU 0.975). 배치안은 OA(공식처럼 다섯 음절 같은 크기)와 OB(쿠파 크게, 주니어 작게) 두 가지다(`sheets/official_approval.png`). 2차 `kst.py` 자형은 대체됐다. 아직 자형 승인 대기 중이며, 색·질감·설치는 하지 않았다.
   - 2026-10-10: 사용자 요청으로 쿠파주니어 로고의 R과 위·아래 바람 이펙트를 Affinity MCP에서 독립 투명 소재로 분리했다. R의 문구·이펙트에 가린 테두리와 바람 꼬리만 복원했고 글자 면·사선 결은 보존했다. 개별 PNG·400×208 좌표 보존 PNG·독립 레이어 Affinity 파일을 저장했다. 최종 합성 전 소재 작업이며 기존 OA 문서·패치·배포 ZIP은 동일하다. 기록: `work/img/kj_parts_20261009/README.md`, `manifest.json`.
   - 2026-10-10: 사용자 요청으로 승인된 쿠파주니어 OA 자형을 18% 균등 확대하고 R 앞에 조립했다. 문구 전체 기울기를 4도 조정해 마지막 「어」의 테두리로 R 왼쪽의 위·아래 복원 부분을 가렸다. 분리한 위·아래 바람을 독립 배치했으며 RPG보다 작은 높이를 유지했다. Affinity 편집본 저장, Codex 내장 computer-use로 Azahar 모드 선택 화면 직접 확인, MLyt KJ 좌우 두 텍스처만 변경·그 외 바이트 동일, patch/정션/SD/ZIP 36파일 일치. 최신 레시피는 logo2/run_all.py에 연결했다. 기록: `work/img/kj_assembly_20261010/REPORT.md`, `KJ_assembled_20261010.af`, `out/runtime_after.png`.
   - 2026-10-10 (R 정리): 사용자 참고 1DX 쿠파군단 RPG의 R처럼 왼쪽 줄기/아래 모서리의 면·테두리 경계를 정리했다. Affinity native 픽셀 편집으로 독립 R 110픽셀을 수정, 녹색 면 안의 적갈 침범 10→0. 외곽 알파/나머지 면과 기존 3DX 그라데이션·사선 결 보존. 문구/바람 조립은 동일하며 실제 합성 R 25픽셀·MLyt KJ_R 한 장만 변경했다. Codex 내장 computer-use로 Azahar 모드 선택 직접 확인, patch/정션/SD/ZIP 36파일 일치. 최신 R 소재·Affinity·레시피·보고서: `work/img/kj_R_polish_20261010/REPORT.md`, `R_clean.png`, `KJ_assembled_R_refined_20261010.af`. logo2/run_all.py 연결 갱신.
   - 2026-10-10 (R 추가 정리): 사용자 지적 잔여 적갈 침범과 빈칸을 녹색 면 경계 확장으로 채우고, 지난 수정의 밝은 하단선을 제거해 이음선과 색/사선 결을 연결했다. Affinity native 독립 R 300픽셀·합성 R 96픽셀만 변경, 외곽 알파·문구·바람 동일. MLyt KJ_R 한 장만 수정, Codex 내장 computer-use로 Azahar 실제 모드 선택 확인, patch/정션/SD/ZIP 36파일 일치. 최신 소재·Affinity·레시피·보고서: `work/img/kj_R_touchup_20261010/REPORT.md`, `R_clean.png`, `KJ_assembled_R_touchup_20261010.af`. logo2/run_all.py 갱신.
   - 2026-10-10 (R 안쪽 꼭짓점): 두 다리 사이 밝은 돌기와 세로/사선 경계의 잡색을 정리했다. Affinity native R 100픽셀·합성 84픽셀만 변경, 외곽 알파·문구·바람 동일. MLyt KJ_R 한 장만 교체, Codex 내장 computer-use로 Azahar 모드 선택 직접 확인, patch/정션/SD/ZIP 36파일 일치. 최신 소재·Affinity·레시피·기록: `work/img/kj_R_notch_20261010/REPORT.md`. logo2/run_all.py 갱신.
   - 2026-10-10 (R 원본 그대로 분리): 사용자 지적 — 원본 R은 다리 사이가 적갈 외곽으로 채워져 있고, R은 원본 특징 그대로 두고 가려진 부분만 이어야 한다(다리 사이 비우기·다리 깎기 금지). 면·테·구멍·두 다리는 일본판 원본 픽셀 그대로, 다리 구역 외곽은 원본+가려진 곳만 측정 모델(면 5.5px 확장)로 이었다. 앞선 crotch 회차는 대체됐다. Affinity `R_faithful_20261010.af`·`KJ_assembled_R_faithful_20261010.af`, 조립 109픽셀·MLyt KJ_R 한 장 변경, patch/정션/SD/ZIP 36파일 일치. Azahar 확인은 사용자 담당. 기록 `work/img/kj_R_faithful_20261010/REPORT.md`, logo2/run_all.py 연결 갱신. 이어서 사용자 지정으로 왼쪽 다리 아래 모서리(R x≤17, y≥44)만 직전 직각 모서리로 되돌렸다(`R_faithful_corner_20261010.af`, R 155픽셀, 조립 화면 10픽셀).
   - 2026-10-10 (R 새 누끼 소재): 사용자 요청으로 Affinity에서 일본판 ROM을 직접 재추출해 R 원본 누끼를 새로 만들었다. 원본 면·테·구멍·두 다리 1,482픽셀 그대로, 가려진 외곽은 사용자 쿠파군단 R의 획을 맞춰 원본 적갈색으로 아래 레이어에 보완하고 원본을 위에 겹쳤다. 원본/보완 PNG·독립 레이어 Affinity·좌표 보존본 저장 및 검증. 이번 결과는 소재 작업이며 설치 조립본/배포 ZIP은 직전 faithful/corner판 동일. 최신 소재·편집본·기록: `work/img/kj_R_recut_20261010/REPORT.md`, `R_recut_20261010.af`.
   - 2026-10-30: 사용자 지적(모드 선택 쿠파주니어 로고 편집티)으로 RPG 글자의 편집 흔적을 없앴다. 첨부 `final.png`는 바탕화면의 10-09 클로드판(10-10 조립 전)이고, 거기 보이는 R 왼쪽 「r.」 흔적은 설치본에서 이미 「어」 밑이었다. 설치본에 남아 있던 R·P 사이 흰 지그재그 줄과 R 바깥선 차이를 고쳤다: 바탕판의 R·P·별·클라운카 자리는 일본판 원본 픽셀 그대로, 분리 R은 「Jr.」·옛 바람에 덮였던 곳에만, 「어」 위 R 줄기 바깥선은 원본의 기울어진 직선(잔차 0.07px)을 이어 「r」이 닿은 67픽셀만 교체. 한글 문구·바람·모서리·P·G는 10-10 그대로. 185픽셀·MLyt KJ_R 한 장 변경, patch/정션/SD/ZIP 36파일 일치. Azahar 확인은 사용자 담당. 레시피·기록 `work/img/kj_logo_natural_20261030/build_natural.py`, `REPORT.md`, 백업 `work/build/prev_kj_logo_natural_20261030/`. logo2/run_all.py 연결 갱신.
   - 2026-10-31: 스타 메뉴(START) 항목 이름 6개(아이템·장비·스테이터스·기록·배지·가이드)를 한 글꼴·크기·높이로 맞췄다(사용자 지시). 글꼴은 옛 배지·능력과 같은 1DX 대사 비트맵 폰트(`lyt_B.compose` font em 13, 세로 중심 12)다. 「능력」은 1DX 한국판처럼 「스테이터스」로 바꿨고, 그 메뉴를 가리키는 배틀 가이드 BtlGuide_11·11_0(복사본 포함 4개)도 함께 바꿨다. 능력치를 두루 이르는 ステータス는 DS대로 「능력」이다(용어집 행 추가). 같은 날 사용자 지시로 쿠파주니어 가이드(KJGuide_*)의 ステータス 7줄도 1DX KGGuide처럼 「스테이터스」로 바꿨다. 가이드 밖 룰렛·스킬 문구는 「능력」이다(`work/review/kj_guide_status_20261031/REPORT.md`, BMsg.dat만 변경). MLyt.dat에서 TOP_MENU_TEXT 6장만 바꿨고 patch/·정션·SD·ZIP 38파일이 일치한다. 레시피·보고서는 `work/img/pause_menu_20261031/build_pause_menu.py`·`REPORT.md`, 백업은 `work/build/prev_pause_menu_20261031/`(이전)·`…b/`(같은 날 1차판)에 있다. `lyt_B.py make`를 다시 돌리면 이 6장을 `build_pause_menu.py`로 다시 만든다.
3. 2026-10-07: 후리가나 설정은 `MainMenu.cro`의 기존 비일본어 경로로 숨기는 패치를 설치했다. 커서·버튼·행 재배치 및 해시 검증 완료, 실제 게임 화면 확인은 사용자 담당. SS컴퍼니 이름 슬림·큐티·마초와 1DX 근거 말투 교정도 반영했다. 기록은 `work/review/followup_20261007/REPORT.md`. (「※」 4줄 복원과 1DX 공식 용어 4개 반영은 2026-09-30 완료, `work/textpass_20260930.py`. 1DX 용어 정렬 리뷰(`work/review/kj_1dx_terms.md`)와 TEXT PASS 2(기술명·띄어쓰기·amiibo 문구, `work/textpass2_20260930.py`)도 2026-09-30 완료. TEXT PASS에서 glossary 행을 바꾸면 `text/glossary_overrides.tsv`에도 넣는다 — `build_glossary.py`가 재생성할 때 override만 남는다)
4. 게임 화면 확인 목록: `work/lead_state.json`의 `review_items`, `font_phase`.
   - 2026-10-30 검토(설치본을 원본과 직접 비교, 파일 변경 없음): 대사 9,623개 일본어 0·후리가나 0·폰트 누락 0, 번역 130배치 → ko_final → 설치본 바이트 일치, 교체 계획 그림 전부 설치(Lyt 258장·Obj 17·HB 12·FMdl 2·스태프롤 1줄). 게임 파일 안 일본어는 임시 아이콘 6종(사용자 결정으로 유지)과 화면에 안 나오는 개발용 그림·문자열뿐. 실기 HOME 메뉴 3D 배너 로고(`exefs/banner` `COMMON_jp`)와 일본어 본체의 HOME 이름(SMDH)은 LayeredFS 밖이라 일본어로 남는다. 남은 일은 게임 화면 확인뿐. 기록 `work/review/remaining_20261030/REPORT.md`.
   - 2026-10-31 배포 전 최종 번역 검토(사용자 요청)를 했다. 9,623개 전부를 자동 검사(`work/review/final_20261031/audit.py`)로 훑었다. 같은 일본어의 다른 번역, 용어집, 띄어쓰기, 조사, 문장부호, 맞춤법, 숫자, 길이, 말버릇, 선택지, 이름, 옛 이름을 봤고 걸린 것은 모두 문맥으로 판정했다. 선택지 92종과 새로 지은 이름도 직접 봤고, 의미 표본 242줄에서 오류는 0이었다. 고친 것은 DS 띄어쓰기 오류 「책임 지고 → 책임지고」 2곳(FMsg/o_ekubon_34 #4 #9)뿐이며 FMsg.dat만 바뀌었다. 38파일 일치, 일본어 0, 폰트 누락 0. 기록 `work/review/final_20261031/REPORT.md`.
   - 2026-11-16 배포 전 최종 확인을 했다(사용자 요청: DS 충실도, 리메이크 반영, 쿠파주니어 RPG 일관성, 칸 넘침).
     - 새로 쓴 방법: 번역에 안 쓰인 DS 줄을 방 순서로 대조, DS와 다른 글자 111건 판정, 기기 표현 대조, 두 모드의 호칭·말버릇 대조. 여기서는 고칠 것이 없었다.
     - 실제 설치 폰트로 줄 폭을 다시 쟀다(7장의 크기 코드 반영). 같은 창 종류의 일본어 최대 폭을 넘던 3건을 줄였다: FMsg/i_challenge_01#111, Menu#628(줄바꿈만), BMsg/b_sys#1199.
     - FMsg.dat·BMsg.dat·Menu.msbt만 바뀌었고 patch/·SD·ZIP 38파일이 일치한다.
     - 공개 배포 저장소 `work/distribution_20261102/`의 ZIP은 아직 10-31판이다.
     - 기록 `work/review/final_check_20261116/REPORT.md`.
5. 배포 준비(2026-10-31 시작): 통합 툴 `C:\AI-Projects\3ds-patch-universal-tool`을 진짜 패치 파일로 직접 돌려 봤다(도구 프로젝트는 읽기만, 변경 0). Luma/Azahar ZIP 만들기·xdelta·Azahar 직접 설치·FTP는 이 패치에 그대로 쓸 수 있고, 만든 ZIP은 현재 배포본과 바이트 단위로 같다. RomForge 리팩은 못 쓴다(이 패치는 v1.2 업데이트가 필요한데 RomForge는 업데이트 타이틀을 만들지 않고, `aes_keys.txt` 없이는 시작하지 않는다). 60fps를 고르는 옵션은 없어서 수정 폴더를 따로 준비해 만든다. 한글만 36개(30fps)와 60fps만 2개(일본어)를 만들어 Azahar 시험기에서 부팅 확인했고, 둘을 합치면 전체 38개와 같다. 사용자는 `code.ips`만 지우면 60fps를 끌 수 있다. 이 PC에서는 도구의 「Azahar 설치」를 쓰지 않는다(mods 정션을 막지 못한다). 기록 `work/review/dist_tool_20261031/REPORT.md`. 같은 날 후속: 본편과 v1.2 업데이트를 한 패키지로 합치면 RomForge도 쓸 수 있다. 확장 헤더 차이는 코드 크기 2개·버전·Jump ID뿐이고, RomFS는 4개 파일만 다르다. RomForge는 원래 기능으로 `exheader.bin`·exefs 코드 차분·배너·RomFS xdelta를 넣을 수 있다. 시험기에서 업데이트를 숨기고 흉내 냈더니 타이틀·필드·스타 메뉴가 한글·60fps로 정상이었다. 이 방식은 공식 업데이트를 지워야 하고 키가 필요하다. 같은 날 오후, 사용자가 업데이트한 툴(「업데이트 통합」 탭, `merge.py`)로 실제 통합 패키지(6.5MB)와 CCI를 만들어 검증했다. 독립 검사기로 해시 전부와 RomFS 1,282개(v1.2 + 패치)를 확인했고, Azahar에서 업데이트·모드 없이 한글·60fps로 돌았다. 공식 업데이트가 깔려 있으면 30fps와 일본어 타이틀 로고로 돌아간다. 실기용 CIA는 각자의 `certs.bin`·키가 있어야 해서 시험하지 못했다. 60fps는 IPS 없는 한글 통합판에 기존 `code.ips`·`BAI.dat`을 얹어 켜고 끌 수 있다. 사용자용 설치 안내서는 `work/sd_package/설치 안내.md`다(ZIP과 따로 배포, 설치·60fps 끄기·문제 해결). 패치를 바꾸면 안내서의 날짜 줄과 내용도 함께 확인한다.
   - 2026-11-20: 사용자 요청으로 통합 툴에 **초간단 모드**를 추가했다(이번에는 도구 프로젝트를 수정했다). 처음 화면이 초간단 모드이고, 기존 간편·전체 모드는 「제작자 도구」로 들어간다. 패치 ZIP을 창에 놓으면 종류(설치용·통합·xdelta)를 스스로 알아내 SD 카드나 에뮬레이터 폴더에 설치하거나 게임 파일을 만든다. 이 패치의 `ml3dx_ko_luma.zip`(38파일)과 통합 패키지를 그대로 인식한다. 새 파일은 도구의 `korean_patch_manager/easy.py`·`easy_ui.py`·`paint.py`·`dnd.py`와 시험 `tests/test_easy.py`·`test_easy_ui.py`다(전체 44개 통과, 합성 게임으로 확인). 이 PC의 Azahar mods 폴더는 정션이라 초간단 모드도 설치를 거부한다(위 원칙 그대로). 실제 SD 카드·실기에서는 아직 써 보지 않았다. 같은 날 사용자 지시로 휴대용 배포본 v0.3.0을 빌드해 독립 검증(시스템 Python·.NET 없이 리팩과 초간단 설치)한 뒤, 공개 저장소 `auseong325-design/3ds-patch-universal-tool`의 main에 커밋 `1d3aaa5`로 푸시하고 사전 공개 릴리스 v0.3.0에 ZIP을 올렸다(릴리스 노트 `work/release-v0.3.0.md`). auseong325-design 계정 저장소의 커밋은 작성자를 그 계정의 noreply 주소로 한다(이 PC의 전역 git 설정은 Kws325와 개인 메일이라 그대로 커밋하면 공개 저장소에 노출된다. 툴 공개 저장소에는 저장소 전용 설정을 넣어 두었다).
   - 2026-11-20 (저장소 정리): 사용자가 쓰는 한글패치 저장소는 `auseong325-design/mario-luigi-rpg-3dx-korean-patch`(비공개, 체크아웃 `work/distribution_20261102/`)다. 커밋·푸시는 auseong325-design 계정으로 한다(사용자 지시: Kws325 계정을 쓰지 않는다). 설치 안내에 통합 툴 초간단 모드로 설치하는 방법을 넣어 푸시했다(배포 쪽 8번, `work/sd_package/설치 안내.md`는 9번, 커밋 `37d7f91`). 릴리스 `v2026.11.16`의 ZIP은 `patch/`와 38파일이 같다. 이 개발 저장소의 origin은 Kws325 계정의 비공개 저장소라 auseong325-design으로는 접근할 수 없다. 10-08부터 남아 있던 `.git/index.lock`을 지우고 10-01 이후 쌓인 변경을 주제별로 로컬 커밋했으며, 원격에는 올리지 않았다. 원본 게임 데이터가 든 이 이력을 배포 저장소에 올리지 않는다.

## 9. 60fps 모드 (2026-10-30 시작, 진행 중)

- 사용자 요청(2026-10-30): New 3DS 전용 60fps 모드 추가. 1DX 엔진 비교, 기존 60fps 치트의 크래시·액션 커맨드 문제 조사, 실기(Luma3DS)에서도 돌아가는 형태로 완성. 이 작업은 사용자가 **서브에이전트 사용을 지시**했다(10-07의 "서브에이전트 미사용" 지침은 이 작업에 적용하지 않는다).
- 작업 계약서: `work/fps60/BRIEF.md`(모든 작업자가 먼저 읽는다). 도구 `scripts/fps60/`(cro.py·crolink.py·armdis.py는 리드 소유), 산출물 `work/fps60/`, 전용 도구 설치는 `tools/`.
- 실행 코드 원본(`exefs/`, `exefs2/`, CRO 원본)은 읽기만 한다. 코드 수정은 `code.ips`(정적 코드)와 LayeredFS의 `romfs/RO/*.cro` + `.crr/static.crr`(CRO 수정 시 해시 갱신)로만 한다.
- 사용자의 Azahar 설정·세이브(`%APPDATA%\Azahar`, `C:\Program Files\Azahar`)는 바꾸지 않는다. 실행 시험은 `tools/azahar-test/`의 휴대용 복사본에서 한다.
- 핵심 사실: 엔진(`ad::fw::TaskBase`)은 60Hz 기준이고 30fps 모드에서 2배 보폭을 쓴다. fps 모드 바이트 = TaskBase+0x45(InitParam+0x31에서 복사, 0=60·1=30·2=?), `isFps30()` @0x25EDD0.
- 2026-10-30 완료·설치: A안(`work/fps60/build/v2`)을 채택했다. 코드 패치(TaskBase::init에서 New 3DS + 허용 태스크만 60fps, 필드/상주 이벤트 VM은 짝수 프레임에만 실행하고 홀수 프레임 입력은 0x434F00에 보관해 전달)와 `romfs/BAI/BAI.dat`(전투 스크립트 15곳, 30fps 동작 동일) 두 파일만 추가했다. 설치 스크립트 `work/fps60/install_20261030/install.py`, patch/정션/SD/ZIP 38파일 일치, ZIP 백업 `work/build/prev_fps60_20261030/`. B안(FEvent.dat 136곳)은 예비로만 둔다. 보고서 `work/fps60/REPORT.md`, 실행 검증 `work/fps60/runtime/findings.md` §8.
- 2026-10-30 실기 크래시 수정: 코드 패치는 **`code.ips`**(타이틀 폴더 루트, Luma `SD:/luma/titles/00040000001CA900/code.ips`, Azahar `patch/00040000001CA900/code.ips`)로 배포한다. `code.bps`는 쓰지 않는다. Luma v13.4(최신 릴리스) BPS 처리기가 남은 APPLICATION 메모리 전부(이 게임 New 3DS 124MB 모드에서 0x07907000)를 임시로 잡다가 실패해 loader가 `svcBreak(PANIC)`로 멈췄다(사용자 덤프 `crash_dump_00000011.dmp`, v13.4 loader 0x14000730). IPS는 할당 없이 적용되고 v1.2에서 결과가 BPS와 바이트 동일하다. 교체 스크립트 `work/fps60/install_ips_20261030/install.py`, 백업 `work/build/prev_fps60_ips_20261030/`. `code.bps`와 `code.ips`를 함께 두지 않는다. 남은 일은 New 3DS 실기 확인뿐이다.
- 2026-10-30 실기 피드백(5차, 계획서 `work/BRIEF5_20261030.md`):
  - 가이드 위 화면이 비는 것은 원작 그대로다(사용자가 실제 카트리지로 확인, 수정 없음).
  - 스타&스타가 60fps에서 늘어지던 것은 별을 모으는 단계의 던지기 주기(60fps 20 단위, 30fps 22 단위)가 짧아 별이 더 붙고 낙하 묶음이 늘어난 탓이었다. `BAI.dat`을 v3b(`work/fps60/build/v3b`, 별 스크립트 2개만, 30fps 동작 동일)로 바꿨다. 낙하·타격 자체는 프레임 의존이 없다. 남는 실기 부하는 실기에서 확인한다. 기록 `work/fps60/analysis/koikoi_star.md` §6~§11.
  - 메뉴 글꼴 통일(7장 위 규칙)과 SUYEOM 능력치 라벨 폭 수정(MLyt.dat의 ST_HIGE 사본 5개, `work/build/suyeom_label_stage/`)을 설치했다. 설치 스크립트 `work/wave5_install_20261030/install.py`, 백업 `work/build/prev_wave5_20261030/`, patch/정션/SD/ZIP 38파일 일치.
  - HOME 메뉴 배너: LayeredFS 밖이라 패치 폴더로는 못 바꾼다. 한글 배너를 넣은 기본 게임 CIA `work/banner_20261030/out/00040000001CA900_ML3DX_KoreanBanner.cia`(FBI로 덮어 설치, 설치 안내 `INSTALL_KO.md`)를 만들었다. 배너와 그 해시만 다르고 원본 CIA 무변경 재빌드는 바이트 동일.
- 2026-10-31: 기존 치트와의 차이, 60fps·한글 패치 따로 쓰기, 서양판 적용 가능성은 `work/fps60/CHEAT_COMPARISON.md`에 정리했다. 60fps 모드(`code.ips` + `romfs/BAI/BAI.dat`)는 한국어 글자가 없어 일본어 원본에 단독으로 써도 된다(Azahar 확인, `findings.md` §8.11). 지금 파일은 일본판 v1.2 전용이며 서양판(북미 `00040000001D1400`, 유럽 `00040000001D1500`)에는 주소를 옮겨 새로 만들어야 한다.
- 이후 한글 패치 파일 수를 검사하는 스크립트는 38(한글 36 + 60fps 2)을 기준으로 한다. 시험 도구 `rt_mods.py use-build`는 `patch/…/romfs`만 복사하므로 시험 빌드도 BAI 수정본에서 시작한다.
