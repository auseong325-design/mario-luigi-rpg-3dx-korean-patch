# I3 재시작 지시 (리드 작성, 2026-09-29)

첫 I3 실행(f6f2d185)은 1,298×2,720px 대조표(`work/img/review/I3_KUI.png`)를 read 도구로 열었다가 API에서 거부됐다. 그 대화는 이어서 할 수 없어서 새로 시작한다. **만들어 둔 코드와 결과물은 그대로 있으니 처음부터 다시 만들지 말고 이어서 한다.** `C:\mario-luigi-rpg-3dx-korean-patch\work\IMAGE_TASK.md` 3장의 그림 크기 규칙(열어 보는 그림은 가로·세로 1,600px 이하)을 반드시 지킨다. `I3_KUI.png`는 열지 않는다(`I3_BUI.png`는 1,266×1,072px라 열어도 된다).

## 이미 있는 것 (리드가 21:55에 확인)

- `scripts/libobj.py`: 형식 풀이. Spritoglobin-DX 소스에서 형식 정보만 참고했다.
  - `_CA_INFO_`는 객체마다 anim/graph/color/hitbox 항목 이름을 담는다.
  - anim은 ML3R(3DX)/ML1R(1DX) 형식이고, graph는 PICA 픽셀이다.
  - 3DX 객체 247개, 1DX 객체 184개를 모두 읽었다.
- `scripts/build_obj.py`(`extract | identity | selftest | build [--out]`):
  - `identity`: BUI·FUI·KUI·Menu 모두 `rebuild_bg4(x,{})==x`이고, 픽셀 디코드→인코드 왕복이 일치한다.
  - `selftest`: `bui_sys_font_JP_ja` f000 교체를 통과했다.
  - `build`는 아직 돌리지 않았다.
- `work/img/obj/3DX`(PNG 11,558장), `work/img/obj/1DX`(5,203장): 풀어 둔 스프라이트.
- `scripts/libobj_ko.py`: 1DX 한국판 프레임을 가져다 3DX 프레임에 맞춰 넣는 작업(donor)과 PNG 작업의 목록·생성기다. 지금 들어 있는 작업은 다음과 같고, 결과가 `work/img/obj_ko/`에 41개 있다.
  - BUI: bui_sys_badstatname, bui_sys_block_name, bui_tuto
  - KUI: ko_ui_jump, ko_ui_statname, ko_ui_fukubikiblock
- 아직 없는 것: `work/img/obj_plan.json`(전수 목록), `work/build/obj_stage/`. `work/img/I3.md`는 추출 전 단계에서 기록이 멈춰 있다.

## 할 일 (순서대로)

1. `work/img/I3.md`를 지금 상태로 고쳐 쓴다. 이후 마일스톤마다 갱신한다.
2. `libobj_ko.py --review`의 대조표 함수가 1,600px 이하 조각으로 나눠 저장하도록 고친다.
3. 전수 목록 `work/img/obj_plan.json`을 만든다.
   - 글자가 있는 3DX 스프라이트(일본어, BP/HIGE/TSUNO 등)를 빠짐없이 적는다.
   - 항목마다 1DX 한국판의 같은 스프라이트, 작업 분류(가/나/다), 한국어 낱말과 근거를 적는다(IMAGE_TASK.md 0장 순서).
4. 1DX에서 가져올 수 있는 스프라이트(donor)를 모두 끝낸다. 크기·꾸밈은 3DX 원본에 맞춘다.
5. 새로 그려야 하는 스프라이트는 I2의 도구로 만든다.
   - I2도 다시 시작해서, `work/img/toolkit/READY`가 생긴 뒤 README를 읽고 쓴다.
   - READY 전에는 3·4번과 빌드 준비, 일본어 지우기를 먼저 한다.
6. `build_obj.py build` → `work/build/obj_stage/romfs/Obj/JP/`, 다시 읽기 검증, 원본/한국어 대조표를 만든다. 대조표는 1,600px 이하 조각으로 만들고 직접 본다.
7. 최종 보고(IMAGE_TASK.md 4장 형식).
