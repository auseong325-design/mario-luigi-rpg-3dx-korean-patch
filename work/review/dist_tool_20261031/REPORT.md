# 통합 툴 실사용 검토 (2026-10-31)

## 최신 결론 (오후 재검토, 업데이트된 툴 기준)
- 기존 기능(Luma/Azahar ZIP, xdelta, FTP)은 오전과 결과가 같다. 만든 ZIP은 지금 배포본과 바이트까지 같다.
- 개선된 점:
  - 정션을 거부한다. 이제 이 PC의 mods 정션 너머로 파일을 쓰지 않는다.
  - 같은 패치를 다시 설치해도 오류가 나지 않는다.
- 새 기능 「업데이트 통합」은 이 패치에 쓸 수 있다.
  - 본편 CIA와 v1.2를 합친 통합 패키지는 6.5MB다. 툴 제작자가 만든 것과 내용이 같다.
  - 이 패키지로 만든 CCI를 직접 만든 검사기로 다시 열어 봤다. 해시가 전부 맞고, RomFS 1,282개가 「v1.2 + 패치」와 같다.
  - Azahar에서 업데이트와 모드 없이 한글과 60fps로 돈다.
- 조건:
  - 공식 업데이트를 지워야 한다. 업데이트가 깔려 있으면 30fps, 일본어 타이틀 로고, 후리가나 설정 복귀가 된다(대사는 한글).
  - 실기용 CIA는 각자의 `certs.bin`과 키가 있어야 만들 수 있어서 시험하지 못했다.
- 60fps 선택: 체크박스는 여전히 없다. 대신 두 가지 방법을 확인했다.
  - 통합 패키지를 IPS 없이 만들면 30fps 한글판이 된다.
  - 그 30fps 한글판에 기존 「60fps 추가」 파일 2개(`code.ips`, `BAI.dat`)를 얹으면 60fps가 된다.
  - 그래서 받는 사람이 `code.ips` 한 파일로 켜고 끌 수 있다.
- 자세한 내용은 맨 아래 「재검토」 절에 있다.

## 요청
`C:\AI-Projects\3ds-patch-universal-tool`(3DS 한글패치 매니저 + RomForge 브리지)을 직접 열어서 다음을 확인한다.
- 이 패치(한글 36개 + 60fps 2개 = 38개 파일)에 실제로 쓸 수 있는가.
- 60fps 모드를 넣을지 뺄지 고를 수 있는가.

## 결론
- **쓸 수 있는 기능:** Luma/Azahar ZIP 만들기, xdelta 만들기·적용, Azahar 직접 설치, FTP 전송. 진짜 패치 파일로 돌렸고, 만든 ZIP은 지금 배포본과 바이트 단위로 같다. Azahar 시험기에서 세 가지 조합을 부팅해 확인했다.
- **지금 형태로는 못 쓰는 기능:** RomForge 리팩(CIA/CCI 직접 만들기). 이 패치는 v1.2 업데이트 위에서 돈다. RomForge는 업데이트 타이틀을 만들지 못하고, 키 파일(`aes_keys.txt`)이 없으면 시작도 하지 않는다. 본편과 업데이트를 한 패키지로 합치면 쓸 수 있다(아래 「후속 질문」).
- **60fps 선택:** 도구 안에 켜고 끄는 옵션은 없다. 대신 폴더를 따로 준비해 따로 만들면 된다. 「한글만」(36개, 30fps)과 「60fps만」(2개)을 만들어 확인했다. 두 ZIP은 겹치는 파일이 없고, 같이 풀면 전체 38개와 똑같다.

## 시험 방법
- 도구의 함수를 그대로 불러 썼다. GUI 버튼은 같은 함수를 부른다(`KoreanPatchManager.py` 247·252·266·273·277행).
- 입력:
  - 원본 = v1.2 RomFS 전체 1,282개(`romfs` 위에 `romf2`)
  - 수정본 = 그 복사본에 패치 파일을 덮은 것
  - 코드 패치 = `patch\00040000001CA900\code.ips`
  - 원본 코드 = `work\fps60\bin\3dx_v12.code.bin`
  - 게임 파일 = 본편 CIA
- 큰 시험 폴더는 임시 폴더(scratch)에만 만들었다. 바뀌지 않은 파일은 임시 복사본을 가리키는 하드 링크다.
- 도구 프로젝트는 읽기만 했다. 실행 전후로 2,972개 파일의 크기와 수정 시각을 비교했고, 바뀐 것은 0개다.
- 단위 시험: 19개 통과, 7개 건너뜀. FTP 시험은 pyftpdlib이 없어서, RomForge 시험 6개는 환경 변수가 없어서 건너뛰었다. FTP는 아래 T8에서 따로 시험했다.

## 결과

| # | 기능 | 결과 |
|---|---|---|
| T1 | 게임 파일 정보 읽기 | Title ID는 맞게 읽는다(본편 `00040000001CA900`, 업데이트 `0004000E001CA900`). 두 CIA 모두 TMD 버전이 0이라 버전은 둘 다 「0.0.0」으로 나온다. 그래서 v1.0과 v1.2를 구별하지 못한다 |
| T2 | 변경 분석 | 바뀐 파일 37개(추가 0, 삭제 0), IPS 기록 8개, 코드 범위 정상 |
| T3 | Luma / Azahar ZIP 생성 | `luma.zip` 38개 = `patch\` = SD 폴더 = 현재 배포 ZIP(`ml3dx_ko_luma.zip`), 바이트까지 같다. `azahar.zip`도 38개로 같고, 코드만 `exefs/code.ips` 자리에 넣는다. 다른 점은 ZIP 맨 위에 `설치 안내.txt`와 `manifest.json`이 붙는 것뿐이다 |
| T4 | 나눠 만들기 | 한글만 36개(24.4MB), 60fps만 2개(1.5MB). 겹치는 파일 0개, 둘을 합치면 전체 38개와 똑같다 |
| T5 | 한계 | ① 수정 폴더에 패치 파일 37개만 넣으면 「1,245개 삭제」로 보고 만들기를 거부한다. 수정 폴더는 RomFS 전체 복사본이어야 한다. ② IPS 검사는 크기만 본다. v1.0과 v1.2 코드는 크기가 같아서(3,117,056바이트) v1.0 코드로도 통과한다. 실제로는 IPS 8곳 중 7곳이 v1.0에서 다른 코드 위에 쓰인다. ③ Title ID를 본편으로 두고 업데이트 CIA를 고르면 Title ID 불일치로 거부한다 |
| T6 | xdelta | 묶음은 6.3MB(파일 37개의 차이 + `code.ips`). 같은 원본에 적용하면 설치 ZIP이 배포본과 바이트까지 같다. 원본이 다르면 거부한다: v1.2 기준 묶음을 v1.0 RomFS에 적용하거나 그 반대로 하면 `.crr/static.crr` 해시 불일치로 멈춘다. 코드 파일을 v1.0으로 고르면 「원본 코드 해시 불일치」로 멈춘다 |
| T7 | Azahar 직접 설치(임시 폴더) | 처음 설치는 38개가 정확히 들어간다. 다시 실행하면 「기존 실행 코드 패치」 때문에 거부한다. 예전 버전 파일이 하나라도 있으면 「기존 모드 파일과 충돌」로 거부한다. 그래서 패치를 새 버전으로 바꿀 때는 쓸 수 없다. 윈도우 정션은 막지 못한다(정션 너머로 36개를 썼다) |
| T8 | FTP 전송(이 PC 안의 시험 서버) | 처음 전송은 Luma 배치 38개가 그대로 들어간다. 타이틀 폴더가 이미 있으면 거부한다. 실제 3DS의 FTP 서버로는 시험하지 않았다 |
| R1~R3 | RomForge 작업 폴더 준비·리팩 | 본편·업데이트 CIA 모두 바로 멈춘다: 「Common Key index 0 없음 — aes_keys.txt에 common0=<hex> 추가 필요」. 두 CIA는 암호화되지 않았지만(`cia_info.py`: 콘텐츠 형식 0x0000, NCCH NoCrypto) RomForge는 티켓을 읽으려고 공용 키를 요구한다. 키는 쓰지 않았다 |

### Azahar 시험기 부팅(도구가 만든 `azahar.zip`, New 3DS 모드, 타이틀 화면)

| 조합 | 로그 | fld::System +0x3D | 프레임 | 화면 |
|---|---|---|---|---|
| 전체 38 | `…/exefs/code.ips patching code.bin`, 교체 파일 37개 | 0 | 59.91/s | 한글 타이틀(`runtime_full_title.png`) |
| 한글만 36 | 코드 패치 없음, 교체 파일 36개 | 1 | 29.96/s | 한글 타이틀(`runtime_ko_title.png`) |
| 60fps만 2 | `…/exefs/code.ips patching code.bin`, 교체 파일 `BAI.dat` 1개 | 0 | 59.88/s | 일본어 타이틀(`runtime_fps60_title.png`) |

시험 뒤 시험기를 `use-patch`(38개)로 되돌렸다. 세이브 3개(1f1cf4f6…, 43c2ca72…, 659ab0d2…)는 그대로다.

## RomForge 리팩이 이 패치에 맞지 않는 이유
- 게임은 v1.2 업데이트가 깔린 상태에서 업데이트의 코드와 업데이트 RomFS 파일 19개를 먼저 쓴다. 패치 파일 중 `.crr/static.crr`, `FMdl/JP/FMdl.dat`, `RO/MainMenu.cro` 세 개가 이 19개에 들어 있고, `code.ips`는 v1.2 코드용이다.
- RomForge는 업데이트 타이틀을 만들지 않는다. 소스에서 막고 있다: `N3DS\Core\Services\CiaBuilder.cs` 41~42행 「업데이트 파일은 CIA로 만들 수 없습니다」, `CciToCiaConverter.cs` 123~124행.
- 그래서 리팩으로는 본편만 고칠 수 있다. 결과는 아래와 같을 것으로 본다(게임에서 실행해 보지는 않았다).
  - 업데이트를 깔면 업데이트 쪽 코드와 파일이 앞서므로, 60fps와 타이틀 로고, 후리가나 숨김이 빠진다.
  - 업데이트를 안 깔면 v1.2용 코드 패치가 v1.0 코드의 다른 명령 위에 쓰여 게임이 망가진다(T5 ②).
- 키가 있더라도 v1.2 기준 원본으로는 브리지의 원본 확인에서 `.crr/static.crr`(v1.0과 v1.2가 다름)에 걸려 멈출 것으로 본다. 이 부분은 코드만 읽고 판단했고, 실행해 보지는 않았다.
- 이 문제는 업데이트 내용까지 본편 패키지에 함께 넣으면 피할 수 있다. 아래 「후속 질문」에 정리했다.

## 후속 질문: 본편과 업데이트를 합치면 RomForge를 쓸 수 있나 (같은 날)
결론: **가능하다.** 본편 CIA 하나에 「v1.2 + 한글 + 60fps」를 담고, 공식 업데이트 없이 돌리는 방식이다. 시험기에서 그 상태를 흉내 내 보니 정상으로 돌았다. RomForge를 실제로 돌려 보지는 않았다(키 필요).

### 본편과 v1.2의 차이 (`exheader_diff.py`, `prep_report.json`)
- 확장 헤더(exheader)에서 다른 것은 코드 크기 2개, 리마스터 버전(0→2), Jump ID, 서명뿐이다.
  - 코드 크기: text 0x288AA0→0x288BD8, ro 0x65E48→0x65E50. 메모리 쪽 수는 649·102쪽으로 같다.
  - 나머지(주소, 데이터·BSS 크기, 세이브 크기, 권한, 의존 모듈, ACI의 Program ID `00040000001CA900`)는 같다.
- RomFS는 업데이트 파일 19개 중 4개만 본편과 다르다: `.crr/static.crr`, `FEvent/FEvent.dat`, `FMdl/JP/FMdl.dat`, `RO/static.crs`. CRO 15개는 본편과 같다. 앞의 두 파일(static.crr, FMdl.dat)은 이미 우리 패치에 들어 있다.

### RomForge가 원래 할 수 있는 것 (원본 RomForge 기능, 포크는 결과 보고만 추가)
- 패치 맨 위의 `exheader.bin`(0x800바이트)으로 확장 헤더를 바꾼다(`RepackService.cs`).
- `exefs/code.bin`으로 코드를 통째로 바꾸거나, `exefs/code.bps`·`.xdelta`·`.ips`로 코드를 고친다. 압축된 코드는 풀어서 고친 뒤 다시 압축한다(`ExeFsPacker.cs`).
- `exefs/banner.bin`·`icon.bin`으로 HOME 배너와 아이콘을 바꾼다.
- `romfs/` 파일을 바꾸거나, `romfs/<파일>.xdelta`로 파일별 차분을 적용한다.

### 병합 패키지 구성(안)
본편 CIA에 적용한다.
- `exheader.bin`: 본편 것에 v1.2 코드 크기(와 리마스터 버전)만 바꾼 것
- `exefs/code.bps`(또는 `.xdelta`): 본편 코드를 「v1.2 + 60fps」 코드로 바꾸는 차분
- `romfs/`: 패치 37개 + v1.2 `FEvent.dat`·`static.crs`. 모두 본편 파일 기준 xdelta로 만들 수 있어서, 게임 파일을 통째로 담지 않아도 된다.
- 원하면 `exefs/banner.bin`: HOME 메뉴 한글 배너. LayeredFS로는 못 하던 것이 같은 CIA에 들어간다.

### 시험기에서 흉내 낸 결과 (`dt_mods.py use-merge`, `update hide`)
- 준비:
  - 설치된 업데이트를 시험기에서 잠시 숨겼다.
  - v1.2 코드에 `code.ips`를 미리 적용해 `exefs/code.bin`으로 넣었다(`v3b/patched.code.bin`과 같다).
  - RomFS에는 패치 37개 + 업데이트 파일 2개를 넣었다.
- 결과:
  - 타이틀: 한글, 「Ver. 1.2」, 59.91/s(`runtime_merge_title.png`)
  - 파일 선택 → 모드 선택: 정상
  - 필드: 59.88/s(`runtime_merge_field.png`)
  - 스타 메뉴: 59.88/s, 「스테이터스」 등 한글(`runtime_merge_pause.png`)
  - 로그: `exefs/code.bin overriding built-in ExeFS`, 교체 파일 39개
- 다른 점: 이번 흉내에서는 확장 헤더를 본편 것 그대로 두었다. 메모리 쪽 수가 같아서 그대로 돈다. 실제 패키지에서는 v1.2 값으로 맞춘다.
- 정리: 업데이트를 원래대로 돌려놓고 `use-patch`(38개)로 되돌렸다. 세이브 3개는 그대로다.

### 조건과 남은 일
- 이 CIA를 쓰려면 **공식 v1.2 업데이트를 지워야 한다.** 업데이트가 깔려 있으면 실기와 Azahar 모두 업데이트의 코드와 파일 19개를 다시 먼저 쓴다. 시험기는 본편 `.app`을 켜도 「Ver. 1.2」를 보여 줬다. 나중에 업데이트를 다시 깔면 60fps, 타이틀 로고, 후리가나 숨김이 원래대로 돌아가고 한글 대사는 남을 것으로 본다(추정).
- RomForge 쪽은 키 파일(`aes_keys.txt`)이 필요하다. 원래 RomForge의 사용 조건이다.
- 통합 툴은 이 패키지를 아직 다루지 못한다.
  - `build_romforge`가 `.xdelta` 같은 패치 파일을 거부한다.
  - exheader나 exefs를 넣을 칸이 없다.
  - 브리지가 RomFS 파일과 `code.ips`만 검증한다.
  - 툴을 고치거나(사용자 허락 필요), 패키지를 RomForge 앱에 바로 넣는다.
- 아직 안 한 것:
  - 실제 패키지 만들기
  - RomForge 실행(키가 필요하다. 아니면 암호화되지 않은 CIA 내용으로 CCI를 만들어 키 없이 시험한다)
  - 만든 CIA를 시험기와 실기에서 확인하기

## 60fps 선택 방법
- 도구에는 「이 파일은 넣고 저 파일은 빼기」 같은 선택지가 없다. 원본 폴더와 수정 폴더의 차이, 그리고 IPS 칸에 넣은 파일을 그대로 담는다.
- 나눠서 배포하려면 수정 폴더를 따로 준비하고 따로 만든다. 프로젝트 설정 JSON을 조합마다 하나씩 저장해 두면 된다. 이번 시험의 입력은 `prep_inputs.py`가 만든다.
- 사용자 쪽에서 끄는 방법은 `code.ips` 한 파일만 지우는 것이다. `BAI.dat`은 30fps에서 원래와 같게 동작하도록 만들었다(BAI v3b). 10-30 RT5 `rt5_ko`(한글 + BAI, 코드 패치 없음)에서 30fps를 확인했다.
- Old 3DS에서는 `code.ips`가 있어도 30fps 그대로다(findings §8.4). 선택이 필요한 사람은 New 3DS 사용자뿐이다.

## 배포할 때 주의할 점
- 도구가 만든 ZIP은 SD 루트(또는 Azahar 사용자 폴더)에 `설치 안내.txt`와 `manifest.json`을 남긴다. 게임에는 영향이 없다. 두 ZIP을 겹쳐 풀면 이 두 파일을 덮어쓸지 물어본다.
- 안내문은 도구가 정한 일반 문구다. 「버전」 칸에 쓴 글만 그대로 들어가므로 「본편 + v1.2 업데이트 필수」를 그 칸에 적어야 한다.
- 게임 파일로 업데이트 CIA를 고르고 「게임 파일 정보 읽기」를 누르면 Title ID 칸이 `0004000E001CA900`으로 바뀐다(GUI 145행). 그대로 만들면 ZIP이 `luma/titles/0004000E001CA900/`에 들어간다. Luma와 Azahar는 이 게임의 패치를 `00040000001CA900` 폴더에서 읽으므로(10-30 실기 덤프의 경로, 시험기 로그) 패치가 적용되지 않을 것이다. README 경고대로 본편 CIA를 골라야 한다.
- xdelta 방식은 배포 파일이 작고(6.3MB) 게임 파일을 통째로 담지 않는다. 대신 받는 사람이 자기 게임에서 RomFS를 뽑고 이 프로그램과 xdelta를 돌려야 한다. 이 도구로 뽑으려면 키 파일도 필요하다. 이 경로를 쓴다면 v1.0 본편 RomFS 기준으로 만들어야 받는 사람이 본편 하나만 뽑아서 쓸 수 있다(T6에서 확인).
- 이 PC에서는 도구의 「Azahar 설치」를 쓰지 않는다. 사용자 Azahar mods 폴더가 `patch\`로 가는 정션이고, 도구가 정션을 막지 못한다(T7).
- HOME 메뉴 한글 배너 CIA(`work\banner_20261030\out\`)는 이 도구의 범위 밖이다(ExeFS 배너는 다루지 않는다). 따로 배포한다.

## 재검토: 업데이트된 통합 툴 (같은 날 오후)
사용자가 툴을 업데이트한 뒤 다시 검토했다. 툴 폴더에서 바뀐 파일은 13:06~13:14에 고쳐진 것들이다.
- 파이썬 쪽: `korean_patch_manager\merge.py`(새 파일), `core.py`, `romforge.py`, `KoreanPatchManager.py`, `README_KO.md`, 시험 3개
- RomForge 쪽: `RomForge-reference`의 `CiaReader.cs`, `KpmBridge\Program.cs`, 시험 게임 생성기
- 툴 제작자의 실데이터 시험 기록: `work\real-merge-validation\`

툴 제작자는 이 시험에서 이 프로젝트의 CIA, `patch\` 폴더, `code.ips`, 한글 배너, 60fps 기준 코드를 읽기만 했다. 이 프로젝트 안에서 12:40 이후에 바뀐 파일은 없다(원본 게임 폴더와 .venv를 뺀 37,062개를 확인했다).

### 바뀐 코드 (읽어서 확인)
- `core.py`:
  - 입력 폴더나 Azahar 폴더의 경로 중에 정션·심볼릭 링크가 있으면 거부한다.
  - Azahar 설치 대상에 같은 해시의 `exefs/code.ips`가 이미 있으면 그대로 넘어간다.
  - `build_romforge`가 code·exheader·banner 구성 요소를 넣을 수 있다.
  - 나머지(ZIP 맨 위의 `설치 안내.txt`·`manifest.json`, IPS 크기 검사, 다른 내용 파일이 있으면 거부)는 그대로다.
- `CiaReader.cs`: 암호화된 콘텐츠가 없으면 티켓의 타이틀 키를 풀지 않는다. 그래서 복호화된 CIA는 빈 키 폴더로 읽힌다.
- 브리지:
  - 작업 폴더를 준비할 때 `original_exheader.bin`과 `original_banner.bin`도 저장한다.
  - 리팩 결과의 exheader·배너·코드 해시를 다시 읽어 비교한다.
- `merge.py`:
  - 본편 작업 폴더와 업데이트 작업 폴더, 변경 파일만 든 패치 폴더, IPS(선택), 배너(선택)로 「본편 기준 xdelta 통합 패키지」를 만든다. 우선순위는 본편 → 업데이트 → 패치다.
  - exheader는 본편 것에서 리마스터 버전과 text·ro 크기만 업데이트 값으로 바꾸고, 압축 플래그를 끈다. 코드를 압축하지 않은 `code.bin`으로 넣기 때문이다.
  - 그 밖의 바이트가 다르면 거부한다.
- GUI: 「업데이트 통합」 탭이 생겼다(작업 폴더 2개, 패치 폴더, IPS, 배너 칸, 버튼 2개).

### 단위 시험
선택 의존성(xdelta, RomForge 브리지·시험 게임 생성기, pyftpdlib)을 모두 넣고 돌렸다. 27개 모두 통과했고 건너뛴 것은 없다. 임시 파일은 scratch에 썼다.

### 실데이터 기존 기능 (T1~T8, `results_v2.json`)
T1~T6과 T8은 오전과 결과가 한 항목도 다르지 않다. T7(Azahar 직접 설치)만 다르다.

| 항목 | 오전 | 오후 |
|---|---|---|
| 같은 설치를 다시 실행 | 「기존 실행 코드 패치」로 거부 | 오류 없이 통과(바뀌는 파일 없음) |
| mods 폴더가 정션 | 정션 너머로 36개를 씀 | 「심볼릭 링크 또는 정션 경로는 지원하지 않습니다」로 거부, 0개 씀 |
| 예전 버전 파일이 있음 | 거부 | 거부(그대로) |

### 실데이터 통합 기능 (M1~M5, `merge_check.py` → `results_merge_v2.json`)

| # | 확인 | 결과 |
|---|---|---|
| M1 | 빈 키 폴더로 작업 폴더 준비 | 본편 1,282개 = `romfs\`, 업데이트 19개 = `romf2\`. 코드 v1.0·v1.2, exheader(CIA에서 따로 읽은 값), 배너가 모두 같다 |
| M2 | 통합 패키지 | 전체: 6,522,661B. RomFS 39개(패치 37 + `FEvent.dat`·`static.crs`)와 code·exheader·banner. 코드는 풀면 60fps 기준 코드(`v3b/patched.code.bin`)와 같다. 한글만(IPS 없음): 6,522,327B. 60fps만(`BAI.dat` 폴더 + IPS): 222,158B, RomFS 5개 |
| M3 | 툴 제작자 패키지와 비교 | 44개 항목의 내용과 매니페스트가 모두 같다 |
| M4 | CCI 만들기 | 전체 CCI의 SHA-256 `4f02f1ac…`가 툴 제작자 결과와 같다. 한글만 CCI는 `443d86ff…`. CIA는 빈 키 폴더에서 「certs.bin 추출 필요」로 멈추고 파일을 남기지 않는다 |
| M5 | 직접 만든 검사기(`cci_verify.py`, RomForge 코드 안 씀)로 CCI 다시 열기 | 검사기는 먼저 원본 본편 CIA로 확인했다(해시 전부 통과, RomFS = `romfs\`). 두 CCI 모두 exheader 해시, 로고 해시, ExeFS 파일·슈퍼블록 해시, RomFS 슈퍼블록, IVFC 3단계(169,125블록, 불량 0)가 맞다. RomFS 1,282개가 「v1.2 + 패치 37개」(`dt\ed_full`)와 바이트까지 같다. exheader = 기대한 병합값, `.code` = 60fps 코드 / v1.2 코드(압축 안 함, 3,117,056B), 배너 = 한글 배너, 아이콘 = 본편(업데이트와 동일) |

### Azahar 시험기 실행 (`rt_nav.py`, 모드 없음, New 3DS)
CCI 파일을 직접 켰다(`rt_launch.ps1 -Game`). 업데이트는 시험기 폴더 안에서만 잠시 숨겼다. 화면은 PrintWindow로 찍었다(`pw_grab.py`). 화면 위에 떠 있는 「Windows 보안」 창(아래)이 사진에 들어가지 않게 하기 위해서다.

| 조합 | 타이틀 | 모드 선택 | 필드 | 스타 메뉴 | 화면 |
|---|---|---|---|---|---|
| 통합 전체, 업데이트 없음 | 59.85/s | 59.88/s | 59.91/s | 59.91/s | 한글 로고, 한글 메뉴(`sheet_merge_full_noupd_v2.png`) |
| 통합 전체, **공식 업데이트 설치됨** | 29.94/s | – | 29.94/s | 29.94/s | **일본어 로고·「ゲームスタート」**, 대사·메뉴 한글. 스타 메뉴는 원본 MainMenu.cro(vptr 0x49FFAC)라서 후리가나 숨김이 빠진다(`sheet_merge_full_withupd.png`) |
| 통합 한글만, 업데이트 없음 | 29.96/s | – | 29.93/s | 29.93/s | 한글 로고 「게임 시작」, 「Ver. 1.2」(`sheet_merge_ko_noupd.png`) |
| 통합 한글만 + 「60fps만」 ZIP(`code.ips`·`BAI.dat`)을 모드로 | 59.88/s | – | 59.91/s | 59.88/s | 로그 `…/exefs/code.ips patching code.bin`, 교체 `/BAI/BAI.dat`(`sheet_merge_ko_plus60.png`) |

시험이 끝난 뒤 시험기의 업데이트를 되돌리고 `use-patch`(38개)로 돌렸다. 세이브 3개는 그대로다. 툴 프로젝트는 실행 전후로 2,986개 항목을 비교했고 바뀐 것은 0개다.

### 판단
- 통합 방식은 이 패치에 쓸 수 있다.
  - Azahar용으로는 키 없이 CCI 하나를 만들 수 있다. 복호화된 덤프에 한한다.
  - 실기용 CIA는 받는 사람이 자기 `certs.bin`과 키로 만들어야 한다. 시험하지 못했다.
- 공식 업데이트를 반드시 지워야 한다. 지우지 않으면 게임은 돌지만 60fps·한글 타이틀 로고·후리가나 숨김이 빠진다(Azahar로 확인).
  - 실기도 업데이트가 우선이라 같을 것으로 본다(추정).
  - 3DS가 온라인에서 업데이트를 권하면 다시 깔 수 있으니 안내가 필요하다.
- 60fps 선택은 두 가지로 할 수 있다.
  - ① 통합 패키지를 두 개(60fps 포함/제외) 배포한다.
  - ② 한글 통합판(30fps) 하나에, 지금 있는 「60fps만」 파일 2개를 LayeredFS로 얹게 한다. ②는 받는 사람이 `code.ips` 한 파일로 켜고 끈다. 실기 Luma에서도 같은 `code.ips`(v1.2 코드용)가 맞는다. 코드가 v1.2 그대로이기 때문이다.
- 통합판과 예전 LayeredFS 폴더를 함께 두지 않게 안내해야 한다. 예전 버전 파일이 통합판의 새 파일을 덮는다.

### 남은 주의점
- 화면에 「Windows 보안」 창이 떠 있다. 내용은 「공용 및 프라이빗 네트워크에서 이 앱에 액세스하도록 허용하시겠습니까? azahar.exe」이고, 프로세스는 PickerHost다.
  - 방화벽 규칙을 읽어 보니(읽기만), 시험기 `tools\azahar-test\azahar.exe`는 이미 허용돼 있다.
  - 툴 제작자가 시험할 때 쓴 임시 복사본 `…\3ds-patch-universal-tool\work\real-merge-validation\runtime-qcg60nvj\azahar\azahar.exe`(지금은 지워진 폴더)에 차단 규칙 2개가 생겨 있다. 그래서 이 창은 그 임시 복사본 때문에 뜬 것으로 본다.
  - 보안 설정이라 누르지 않았다. 「취소」를 눌러 닫아도 이 프로젝트에는 영향이 없다.
- GUI: 업데이트 CIA의 작업 폴더를 나중에 준비하면 프로젝트 탭의 Title ID·원본·수정 폴더가 업데이트 값(`0004000E…`)으로 바뀐다(`poll()`의 workspace 처리). 이어서 LayeredFS ZIP을 만들면 엉뚱한 폴더에 들어간다. 통합 기능에는 영향이 없다.
- 통합 패키지는 본편 파일 39개와 코드·exheader·배너의 원본 해시를 확인한다. 그래서 내부가 다른 덤프(예: 카트리지 덤프의 exheader가 다른 경우)에는 결과를 만들지 않고 거부한다. 다른 덤프로는 시험하지 않았다.
- 오전에 적은 한계 중 그대로인 것: ZIP 맨 위의 txt·json, IPS 크기만 검사, CIA TMD 버전 0, 다른 버전이 이미 깔려 있으면 설치·FTP 거부.

## 파일
- `prep_inputs.py`: 시험 입력 트리(scratch `dt\`)
- `run_tool_tests.py` → `results.json`: T1~T8
- `romforge_check.py` → `romforge_results.json`: R1~R4(R4는 R2가 멈춰 진행 안 됨)
- `cia_info.py`: CIA의 TMD·암호화 상태(읽기만)
- `dt_mods.py`: 도구가 만든 `azahar.zip`을 시험기에 넣는 도구, 병합 흉내(`use-merge`), 시험기 업데이트 숨기기·되돌리기(`update hide|show`). rt_mods.py의 안전 함수를 쓴다
- `exheader_diff.py`: 본편과 업데이트의 NCCH·확장 헤더 비교(읽기만)
- `runtime_full_title.png`, `runtime_ko_title.png`, `runtime_fps60_title.png`: 부팅 화면
- `runtime_merge_title.png`, `runtime_merge_field.png`, `runtime_merge_pause.png`: 병합 흉내 화면
- (재검토) `run_tool_tests.py`(DT_TAG=v2) → `results_v2.json`, `merge_check.py stage1|stage2` → `results_merge_v2.json`
- (재검토) `cci_verify.py`: CCI/CIA 독립 검사기(NCCH·ExeFS·IVFC 해시, RomFS 전체 비교)
- (재검토) `rt_nav.py`(타이틀→필드→스타 메뉴 측정·촬영), `pw_grab.py`(PrintWindow 촬영), `dt_mods.py use-empty`
- (재검토) `runtime_merge_*.json`·`.png`, `sheet_merge_full_noupd_v2.png`, `sheet_merge_full_withupd.png`, `sheet_merge_ko_noupd.png`, `sheet_merge_ko_plus60.png`

## 바꾸지 않은 것
- 도구 프로젝트: 변경 0(크기·시각 비교).
- `patch\`, SD 폴더, 배포 ZIP, 사용자 `%APPDATA%\Azahar`: 손대지 않았다. 패치는 38개 그대로다.
- 원본 게임 폴더: 읽기만 했다. 하드 링크는 scratch 안의 복사본에만 걸었다.
- pyftpdlib은 scratch `dt\pylib`에만 설치했다(FTP 시험용).
