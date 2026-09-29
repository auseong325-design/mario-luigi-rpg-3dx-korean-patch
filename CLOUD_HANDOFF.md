# 클라우드 세션 인수인계 (2026-09-30)

Kiro 사용량 한도로 중단된 작업을 Claude 클라우드 세션 크레딧으로 잠시 이어간다. **작업 계약서는 `AGENTS.md`**(먼저 읽을 것).

## 클라우드 환경의 한계
- 이 저장소에는 게임 원본(`romfs/`, `romf2/`, `exefs*/`, `ml 1dx/`, CIA, .nds), 그림·빌드 산출물(`work/img`, `work/build`), `patch/`, `.venv`가 **없다**(저작권·용량). 그래서 패치 빌드, 폰트, 그림·로고, 스태프롤, Azahar 테스트는 **불가능** → 로컬에서 한다.
- 가능한 것: 텍스트 작업. `text/jp`(원문), `text/ref_ds_ko`(DS 한국판), `text/ko`(번역), `text/glossary.tsv`, `work/ref_1dx_ko.tsv`(1DX 한국판 대사), `work/batches`, `scripts/merge_ko.py`(검증·병합)는 모두 있다. `merge_ko.py --check-all`이 0 오류여야 한다. 파이썬 3 표준 라이브러리 위주이나, 의존성이 필요하면 `requirements.txt`.
- **`work/ko_final.json`은 `merge_ko.py --merge`의 산출물**이다. 번역을 고쳤으면 `--merge`를 다시 돌려 커밋한다(로컬에서 `build_patch.py --fonts`가 이것을 읽는다). 폰트 글자 집합이 바뀔 수 있으므로 KS X 1001 밖 글자를 쓰지 말 것(검증기가 거른다).

## 현재 상태
- 번역 130개 배치 9,617메시지 완료·교차 리뷰 완료·`merge_ko --check-all` 130/130 0 오류. 텍스트 패스(2026-09-30 02:55)까지 로컬 패치에 설치됨.
- 그림 글자 작업(I1~I6, 레이아웃 A~D)은 `work/lead_state.json`의 image_* 항목 참고. **로컬 전용.** 마지막에 중단된 5개 서브에이전트(B 무게 보정, I3 팔레트, I6 작은 글씨, A 떨어트리기 버튼, 1DX 용어 리뷰)는 결과가 기록되지 않았다.

## 클라우드에서 할 일 (우선순위)
1. **1DX 용어 정렬 리뷰(읽기 위주)**: 쿠파주니어 RPG 등 3DX에서 새로 번역한 용어를 `work/ref_1dx_ko.tsv`(1DX 한국판 공식 표기)와 대조한다. 규칙: 공식 1DX > 신조어, 단 DS 표기가 있으면 DS 우선(AGENTS.md 0장 우선순위). 결과 표를 `work/review/kj_1dx_terms.tsv`/`.md`로 쓰고 바꿀 목록을 **사용자에게 보여 승인받은 뒤** `text/ko`와 `text/glossary.tsv`를 고친다(TEXT PASS 2). 전 배치 검증 → `--merge`.
2. **`work/lead_state.json`의 `review_items`**(게임 화면 없이 판단 가능한 것: 화자 추정·말투 일관성·DS와 3DX 어느 쪽을 택했는지). 원문·DS·1DX 대사로 결정 가능한 것만 처리하고, 게임 화면이 필요한 항목은 그대로 남긴다.
3. `font_phase` 중 텍스트 성격의 잔여(예: 「후리가나 표시」 라벨)는 결정 보류(게임 화면 필요).
4. 작업 후 `work/lead_state.json`(phase, next, 결과)과 이 문서를 갱신하고 커밋·푸시. **로컬로 돌아올 때는 이 브랜치를 pull 해서 `text/ko`, `text/glossary.tsv`, `work/ko_final.json`을 반영**하면 된다.

## 하지 말 것
- 게임 원본·그림·빌드 산출물 추가·커밋 금지. `text/jp`, `text/ref_ds_ko` 수정 금지.
- 로컬 전용 작업(그림·폰트·빌드)을 흉내 내지 말 것.
