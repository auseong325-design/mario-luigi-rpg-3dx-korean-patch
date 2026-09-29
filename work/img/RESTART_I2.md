# I2 재시작 지시 (리드 작성, 2026-09-29)

첫 I2 실행(484f633b)은 한 변이 2,000px를 넘는 대조표(`work/img/review/I2_bank_01~03.png`, 약 500×2,500px)를 read 도구로 열었다가 API에서 거부됐다. 그 대화는 이어서 할 수 없어서 새로 시작한다. **만들어 둔 코드와 결과물은 그대로 있으니 처음부터 다시 만들지 말고 이어서 한다.** `C:\mario-luigi-rpg-3dx-korean-patch\work\IMAGE_TASK.md` 3장의 그림 크기 규칙(열어 보는 그림은 가로·세로 1,600px 이하)을 반드시 지킨다. 위 세 파일은 열지 않는다.

## 이미 있는 것 (파일로 확인됨)

- `scripts/imgtext.py`(1,002줄): measure_style, erase_text, render(4배 SDF → 줄임, 장평·자간 맞춤), finalize(LA4·RGBA4·ETC1A4 양자화), compare, verdict, redraw, make_sheet, CLI(`measure <png>`, `redraw <png> <text> <out> [--fmt --source --em --align --sheet --report]`).
- `scripts/imgtext_bank.py`(758줄): build_bank(1DX `_KR_ko` 그림을 음절로 잘라 꾸밈을 벗긴 글자 모양), 출처 순서 same_word > bank > font(1DX font/font_l) > compose > ofl, glyph_mask, font_report, selftest.
- `work/img/toolkit/bank/`, `bank.json`(음절 412개 항목), `bank_labels.json`, `bank_report.json`:
  - 1DX 그림 글자와 1DX 비트맵 폰트의 겹침 IoU는 font 0.62, font_l 0.63이다. 폰트 획이 그림 글자 획의 0.83~0.87배로, 폰트가 더 가늘다.
  - 1DX 그림끼리 같은 음절을 비교한 IoU는 0.60이다. 은행 안에 서로 다른 글꼴·굵기가 섞여 있다는 뜻이다.
  - 대체 글꼴은 NanumSquareRoundEB가 뽑혔다(IoU 0.54).
- 아직 없는 것: `work/img/toolkit/demo/`, `README.md`, `READY`, `work/img/I2.md`(진행 기록).

## 할 일 (순서대로)

1. `work/img/I2.md`를 만들고, 위 상태와 이번 계획을 적는다. 이후 마일스톤마다 갱신한다.
2. 대조표를 만드는 함수(`_bank_sheet`, `make_sheet` 등)가 1,600px를 넘는 그림을 만들지 않도록 여러 장으로 나누게 고친다. 확인할 때는 새로 만든 조각만 연다.
3. 자체 검사(selftest)를 돌려 지금 코드가 동작하는지 확인한다.
4. 글자 모양 품질:
   - IMAGE_TASK.md 1장의 **글자 크기에 따른 규칙**을 먼저 읽는다(리드가 새로 넣었다). 요점은 세 가지다. 큰 글자에 비트맵 폰트를 크게 늘려 쓰지 않는다. 큰 글자는 1DX 그림 글자에서 가져오고, 안 되면 1DX 그림 글자와 가장 비슷한 OFL 벡터 글꼴로 선명하게 그린다. 굵기는 원본 ±10%에 맞춘다.
   - 참고할 실제 결과: 거대 전투 담당 I6이 지금 도구로 만든 1차 그림(`work/img/review/I6_01~05.png`, 모두 1,600px 이하)이 있다.
     - 큰 글자는 1DX 비트맵 폰트를 늘리고 굵기를 원본의 0.7배로 줄인 것이다. 그래서 원본보다 가늘고 흐리다. 이 방식을 고치는 것이 이번 작업의 핵심이다.
     - I6는 1DX 그림에서 떼어 낸 조각(bank)도 시험했지만, 이 크기에서 「예」「돌아가기」「회」가 깨져서 쓰지 않았다.
   - 은행을 글꼴·굵기별로 묶는다(획 두께, 글자 폭 비율 등). 한 낱말 안에서는 같은 묶음의 음절만 쓴다.
   - 은행에 없는 음절은 같은 묶음 안에서 A+B−B′ 조합을 먼저 시도하고, 그다음 위 규칙을 따른다.
   - 판단 기준은 숫자가 아니라 원본 옆에 놓았을 때의 모습이다.
   - 새 규칙으로 바뀐 도구에 맞춰, I6가 `python scripts\libhb_ko.py` → `python scripts\build_hb.py build` → `review` 순서로 다시 돌릴 수 있게 API를 유지한다.
5. IMAGE_TASK.md 5장 I2의 필수 시연 10장 이상을 `work/img/toolkit/demo/`에 만든다. 원본/한국어 대조표(1,600px 이하 조각)를 직접 보고, 어색한 것을 고친다.
6. `README.md`(사용법·API·한계·묶음별 권장 설정), 그리고 `READY`(한 줄: 버전과 요약)를 쓴다.
   - 다른 작업자(I3·I4·I6, 곧 투입될 2차 3~4명)가 READY를 기다리고 있다. 필수 시연이 통과하는 대로 READY를 먼저 만들고, 개선은 버전을 올려 이어 간다.
   - 2차 작업자 A·B·C·D는 필요한 기능이나 버그를 `work/img/TOOLKIT_REQUESTS.md`에 적는다. READY를 낸 뒤에는 이 파일을 30분마다 확인해서 처리하고, 처리한 줄에 버전과 한 줄 답을 단다. 도구를 고칠 때는 이미 쓰는 사람이 있으니 API를 깨지 않는다.
7. 최종 보고(IMAGE_TASK.md 4장 형식).
