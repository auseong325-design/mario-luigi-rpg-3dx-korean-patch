# 클라우드 세션 인수인계 (2026-09-30)

Kiro 사용량 한도로 중단된 작업을 Claude 클라우드 세션 크레딧으로 잠시 이어간다. **작업 계약서는 `AGENTS.md`**(먼저 읽을 것).

## 클라우드 환경의 한계
- 이 저장소에는 게임 원본(`romfs/`, `romf2/`, `exefs*/`, `ml 1dx/`, CIA, .nds), 그림·빌드 산출물(`work/img`, `work/build`), `patch/`, `.venv`가 **없다**(저작권·용량). 그래서 패치 빌드, 폰트, 그림·로고, 스태프롤, Azahar 테스트는 **불가능** → 로컬에서 한다.
- 가능한 것: 텍스트 작업. `text/jp`(원문), `text/ref_ds_ko`(DS 한국판), `text/ko`(번역), `text/glossary.tsv`, `work/ref_1dx_ko.tsv`(1DX 한국판 대사), `work/batches`, `scripts/merge_ko.py`(검증·병합)는 모두 있다. 파이썬 3 표준 라이브러리만으로 돈다.
- `merge_ko.py`의 줄 폭 계산은 3DX 폰트(`romfs/.../font.bffnt`)가 필요했다. 이제 폰트가 없으면 `work/font_metrics.json`(글자 폭 표)을 쓰고, 그것도 없으면 **추정 폭**으로 돌며 경고를 낸다. 추정 폭으로도 `--check-all` 130/130 0 오류, `--merge` 결과 `work/ko_final.json`이 커밋본과 바이트까지 같았다. 그래도 한도 가까운 줄은 로컬 정확 검사가 기준이다.
- **`work/ko_final.json`은 `merge_ko.py --merge`의 산출물**이다. 번역을 고쳤으면 `--merge`를 다시 돌려 커밋한다(로컬에서 `build_patch.py --fonts`가 이것을 읽는다). 폰트 글자 집합이 바뀔 수 있으므로 KS X 1001 밖 글자를 쓰지 말 것(검증기가 거른다).

## 현재 상태 (2026-09-30 09:40 KST, 브랜치 `claude/tender-goldberg-ob76gv`)
- 번역 130개 배치 9,617메시지 완료·교차 리뷰 완료·`merge_ko --check-all` 130/130 0 오류.
- **1DX 용어 정렬 리뷰 완료** → `work/review/kj_1dx_terms.md`(요약)·`.tsv`(108행). 라벨 대조 도구 `scripts/align_1dx.py` → `work/review/kj_1dx_pairs.tsv`.
- **TEXT PASS 2 적용**(사용자 승인 묶음 terms·spacing·amiibo, `work/textpass2_20260930.py`): 도우미·허 찌르기·회피·정수리 깨기·내던지기·튕겨내기·내동댕이·관통 공격·3상성·군단의 혼, 쿠파7인조·로켓 박치기·`HP 콩`/`슈퍼 EXP 콩 S` 등 콩 21종·치킨 9종 띄어쓰기, amiibo 표준 오류 문구 8개. 메시지 81곳(복사본 포함 120개), glossary 46행(`glossary.tsv`와 `glossary_overrides.tsv` 둘 다), 스타일 가이드 1줄. `work/ko_final.json` 다시 병합함. 쿠파주니어 RPG의 **챌린지는 그대로**(사용자 결정).
- **glossary 재생성 안전**: 첫 텍스트 패스의 4개 행(스킬 지우기·선더·쿵쿵 떨어트리기·꽈당)이 `glossary_overrides.tsv`에 없어 `build_glossary.py`를 돌리면 예전 값으로 돌아가던 문제를 고쳤다.
- **review_items 정리 완료** → `work/review/review_items_cloud.md`: 38개 중 26개를 텍스트로 닫고, 게임 화면이 필요한 12개만 `work/lead_state.json`의 `review_items`에 남김.
- 그림 글자 작업(I1~I6, 레이아웃 A~D)은 `work/lead_state.json`의 image_* 항목 참고. **로컬 전용.** 마지막에 중단된 4개 그림 서브에이전트(B 무게 보정, I3 팔레트, I6 작은 글씨, A 떨어트리기 버튼)는 결과가 기록되지 않았다(1DX 용어 리뷰는 클라우드에서 다시 했음).

## 로컬로 돌아가면
1. 이 브랜치를 pull 해서 `text/ko`, `text/glossary.tsv`, `work/ko_final.json`, `work/lead_state.json`을 반영한다.
2. `python scripts\lib3dx.py --export-font-metrics` → `work/font_metrics.json`(글자 폭 숫자만, 가나·한자 제외)을 커밋하면 다음 클라우드 세션부터 폭 검사가 정확해진다.
3. `merge_ko.py --check-all`(실제 폰트) → `build_patch.py --fonts`(TEXT PASS 2가 든 `ko_final.json`) → Azahar.
4. 바뀐 낱말이 든 그림을 다시 그린다: 쿠파주니어 RPG 커맨드 버튼 `btn_KJ_LA_*`의 すけっと→도우미, やみうち→허 찌르기, みきり→회피(`work/img/lyt_plan_src.tsv`의 ko를 고치고 A 빌더로 다시 빌드). 그 밖에 지원군·기습·간파·쿠파 7인조가 그림에 있으면 같이 맞춘다.

## 하지 말 것
- 게임 원본·그림·빌드 산출물 추가·커밋 금지. `text/jp`, `text/ref_ds_ko` 수정 금지.
- 로컬 전용 작업(그림·폰트·빌드)을 흉내 내지 말 것.
