# 작업지시서: 3DX ↔ DS 방(대사 묶음) 정렬

목표: 3DX 방(FMsg 파일)마다, 같은 장면의 대사가 들어 있는 **DS 한국판 방 번호**를 찾는다.
이 결과로 번역자가 DS 공식 번역문을 그대로 참고한다. 정확도가 번역 품질을 좌우하니 꼼꼼히 확인한다.

## 입력
- 담당 목록: `work/align/assign_<k>.txt` (한 줄에 3DX 방 이름 하나)
- 도구 (프로젝트 루트에서, 반드시 이 파이썬으로):
  - `.venv\Scripts\python scripts\show_room.py --jp <방>` : 3DX 방 전체 대사(일본어)
  - `.venv\Scripts\python scripts\show_room.py --cand <방>` : 구조(대사 길이·페이지 수) 기반 DS 후보 6개. **참고용일 뿐, 틀린 경우가 많다.**
  - `.venv\Scripts\python scripts\show_room.py --ds <DS방> [--ds <DS방> ...]` : DS 방 전체 대사(한국어)
  - `.venv\Scripts\python scripts\show_room.py --find-ds <한국어 문자열>` : 그 문자열이 들어 있는 DS 방 찾기
- 전체 DS 방 요약: `work/align/ds_rooms_digest.txt` (방마다 앞 대사 몇 개)

## 방법
1. 3DX 방 대사를 읽고 장면을 파악한다(누가, 어디서, 무슨 일).
2. 후보 DS 방을 열어 **뜻이 같은 대사가 여러 개 겹치는지** 확인한다. 한두 줄 우연 일치(“쿠파님!”)로 판단하지 않는다.
3. 후보가 아니면 고유명사/특징적 표현을 한국어로 추측해 `--find-ds`로 찾는다(예: 퍼즐피스, 어택피스, 오키노, 블캐츠, 러즐 …). 요약 파일을 훑어도 된다.
4. 3DX 한 방이 DS 여러 방에 나뉘어 있으면 모두 적는다. DS에 해당 장면이 없으면(3DX 신규·디버그 문구 `=== 仮・未実装 ===` 등) `none`.
5. 방을 확인하면서 눈에 띄는 **고유명사 대응**(캐릭터·장소·아이템·기술 이름)을 함께 기록한다. DS에 실제로 쓰인 표기만 적는다.

## 출력: `text/align/parts/room_map_<k>.json` (UTF-8)
```json
{
  "o_town_33": {"ds": ["0F2"], "confidence": "high", "note": "클리닉 장면, 대사 대부분 일치"},
  "i_air_21":  {"ds": [], "confidence": "none", "note": "3DX 디버그/미구현 안내문"},
  "_names": [
    {"jp": "Dr.コキノ", "ko": "오키노 선생님", "type": "character", "evidence": "o_town_33#12 ↔ DS0F2#3"}
  ]
}
```
- `confidence`: high(여러 대사 일치) / medium(장면은 같으나 대사 변경 많음) / low(추정) / none(대응 없음)
- 담당 목록의 **모든 방**을 빠짐없이 적는다. `_names`는 중복 없이.
- 파일 외 다른 파일은 만들거나 고치지 않는다. 끝나면 방 개수와 confidence 분포, 애매했던 방 목록을 보고한다.
