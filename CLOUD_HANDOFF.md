# 클라우드 세션 인수인계 (2026-09-30)

Kiro 사용량 한도로 멈춘 작업을 Claude 클라우드 세션 크레딧으로 잠시 이어 가고 있다. **작업 계약서는 `AGENTS.md`**다(먼저 읽을 것).

## 클라우드 환경
- 사용자가 게임 파일(`romfs/`, `romf2/`, `exefs*/`, `ml 1dx/`, `work/`, `patch/`, `tools/`)을 비공개 저장소 `main`에 올려 두었다(`.gitignore` 주석: 공개 전에 지울 것). 그래서 클라우드에서도 빌드·폰트·그림 작업이 된다. Azahar 테스트만 로컬에서 한다.
- 파이썬: `uv venv --python /usr/bin/python3.12 .venv` 후 `uv pip install -r requirements.txt`(`.venv`는 커밋하지 않는다). 실행은 `.venv/bin/python scripts/<name>.py`, 늘 `timeout`을 건다.
- 재현성 확인됨: msbt 왕복 368/368, `build_patch --identity` 7/7. TEXT PASS 2 전의 `ko_final`로 다시 빌드한 Msg·폰트 10개가 설치본과 바이트까지 같다. `build_lyt` 결과도 로컬 스테이지와 바이트가 같다(ETC 인코딩 결정적).
- `merge_ko.py`의 폭 계산: 실제 폰트가 있으면 그것을 쓰고, 없으면 `work/font_metrics.json`(실제 폰트에서 뽑은 폭 표, 커밋함), 그것도 없으면 추정 폭으로 돈다(`lib3dx.py`).

## 현재 상태 (2026-09-30 10:30 KST, 브랜치 `claude/tender-goldberg-ob76gv`)
- 번역: 130개 배치, 9,617개 메시지 번역과 교차 리뷰 완료. `merge_ko --check-all` 130/130, 오류 0.
- **1DX 용어 정렬과 TEXT PASS 2**
  - 사용자가 terms·spacing·amiibo 묶음을 승인했고, 챌린지는 그대로 둔다.
  - 스크립트 `work/textpass2_20260930.py`. 메시지 81곳(복사본 포함 120개), glossary 46행을 바꿨다.
  - 검토 자료: `work/review/kj_1dx_terms.md`, `.tsv`.
- **Msg 빌드와 설치**: `build_patch --fonts` 결과를 `patch/`에 설치했다. 이전 파일은 `work/build/prev_msg_before_textpass2_20260930/`에 있다.
- **그림 수정 2라운드**: Kiro가 기록 없이 멈춘 4개 작업을 확인해 마무리했다. 자세한 내용은 `work/lead_state.json`의 `image_fix_round_2.results`.
  - A(떨어트리기)는 이미 되어 있었다. TEXT PASS 2로 바뀐 커맨드 버튼 3개(허 찌르기·회피·도우미)는 새로 그렸다.
  - I3: 1DX에서 가져온 스프라이트 43개를 3DX 색으로 바꿨다(갈색 테두리 → 검정). 「앞으로」는 선명하게 다시 그렸다.
  - B: 상점 제목·파일 라벨 11장의 굵기를 원본의 0.84~0.97배로 올렸다. 숍·슬롯은 구조상 한계라 더 가늘다.
  - I6: 쪼르미터와 보스 안내 2장을 흰 채움으로 다시 그렸다(회색·분홍빛이 없어짐).
- **3차 교차 검수**(`image_wave3`)
  - 색 검사: 원본에 없는 색이 0.
  - 레이아웃 178장을 모두 원본과 나란히 봤다. 깨진 「배틀 시작」을 1DX 폰트로 다시 그렸다.
  - 통합 빌드 `work/build/lyt_stage_A`: 178장, 오류 0.
- **patch/ 설치본** (`patch/00040000001CA900/romfs/`): Msg 10개(대사 7 + 폰트 3), Staffroll 2개, Lyt/JP 5개, Obj/JP 4개, HB 12개, FMdl/JP/FMdl.dat.
  - 로고(타이틀·파일 선택 2종)와 게임 시작 버튼은 사용자 검토 3회를 거쳐 「일단 이대로, 개선 여지 남김」으로 설치했다(12:40 KST).
  - 모든 설치본은 `work/build/` 스테이지와 바이트가 같다(Lyt = `lyt_stage_A`, FMdl = `fmdl_stage`).

## 남은 일
1. (완료) 로고 설치. 나중에 다듬을 여지: `review_items` 마지막 항목.
2. 사용자: Azahar에서 전체 패치를 시험한다. 볼 곳은 `work/lead_state.json`의 `next`와 `review_items`(게임 화면 확인 19개)에 적어 두었다.
3. 게임 화면을 보고 결정할 것: 설정 「후리가나 표시」 이름(`font_phase`), `review_items`의 말투·선택지·폭 확인.

## 하지 말 것
- `text/jp`, `text/ref_ds_ko`, 원본 게임 파일(`romfs/`, `romf2/`, `exefs*/`, `ml 1dx/`, `*.nds`, `unpacked/`)은 수정하지 않는다.
- 빌드 결과는 `work/build/<스트림>_stage/`에 먼저 쓰고, 검증한 뒤에만 `patch/`에 설치한다.
