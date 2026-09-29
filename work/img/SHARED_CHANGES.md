# 공유 파일 변경 기록

- 2026-09-29 I5 `scripts/libbffnt.py`: KRNG(커닝) 블록 읽기·쓰기 추가(뒤로 호환). `Bffnt.krng`(블록 본문 bytes, 기본값 None)·`Bffnt.kerning()`·`parse_krng()`를 새로 두고, `parse`가 맨 끝의 KRNG 블록 하나를 받아들이며 `build`가 그대로 다시 쓴다. KRNG가 없는 폰트는 동작이 전과 같다. 검사: `build_patch.py --identity` 7/7 바이트 일치·9,623개 0 문제, 폰트 28개(romfs·ml 1dx·patch·work/build의 모든 .bffnt, KRNG 있는 `Staffroll/mario_font.bffnt` 3개 포함) parse→build 바이트 일치.
