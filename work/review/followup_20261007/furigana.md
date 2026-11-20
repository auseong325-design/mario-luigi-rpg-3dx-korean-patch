# 후리가나 설정 제거

한국어 메시지의 ruby는 기존 파이프라인에서 제거돼 있다. 이번에는 설정 화면의 후리가나 항목을 게임에 이미 구현된 비일본어 경로로 숨겼다. 라벨을 빈 문자열로 바꾸지 않았으며, 나머지 설정과 커서 처리를 기존 구현에 맡긴다.

대상은 `romfs_path()`로 선택한 v1.2 `RO/MainMenu.cro`다. 원본 SHA-256은 `cc42b47f9041206879da695a88b648f2825373fcf86bf690b8e5deb9f62d7aa6`이다. 오프셋 `0x20C38`의 `moveq r0,#1`을 `moveq r0,#0`으로 바꿔 일본 지역에서도 `hasRuby`를 0으로 만든다. 실행 코드 변경은 1바이트다. 버전·기대 명령·주변 명령이 다르면 빌더가 중단한다.

기존 `hasRuby=0` 경로는 후리가나 설명 생성을 건너뛰고, `SET_PNL_hurigana` 애니메이션 frame 1을 선택한다. 이 애니메이션은 후리가나 행·배경을 숨기고 나머지 설정 행·확인 버튼·배경 높이를 조정한다. 커서는 첫 유효 행부터 시작하며, 위·아래 순환에서 숨긴 행을 건너뛴다. 후리가나의 두 선택 버튼도 비활성화한다.

검증은 게임 실행과 구분했다. 추출한 실제 ARM 명령을 Unicorn으로 실행해 8개 지역 입력의 predicate, 후리가나 유무에 따른 모든 유효 행의 상하 순환, 초기 포커스와 버튼 활성/비활성 호출을 확인했다. 기존 애니메이션의 10개 pane·13개 track·37개 key도 파싱했다. 전체 메시지 9,623개에는 ruby가 0개였다. SaveMenu·LoadMenu 문자열 조사에서는 별도의 후리가나 설정 구현을 발견하지 않았다.

CRO의 4개 구간 해시를 검증·재계산하고, 로더 재배치 위치 2,788개와 코드 변경의 충돌이 없음을 확인했다. `.crr/static.crr`의 15개 모듈 등록 중 MainMenu 해시를 교체하고 정렬했다. 다른 모듈의 해시는 유지한다. 설치 산출물은 `RO/MainMenu.cro`와 `.crr/static.crr` 두 파일이다. 원본은 수정하지 않았다.

CRR의 원본 RSA 서명은 검증되지만, 변경 후 같은 서명은 유효하지 않다. 서명 바이트를 보존했으며 새 공식 서명을 만들었다고 주장하지 않는다. 배포 대상인 Luma3DS는 RO의 CRR 서명 및 CRO/CRR 해시 검사 우회를 구현한다([LumaTeam 공식 소스](https://github.com/LumaTeam/Luma3DS/blob/master/sysmodules/loader/source/patcher.c)). 서명 검사를 강제하는 환경에서의 동작을 보장하지 않는다. Azahar·실기의 실제 설정 화면과 전체 CRO 로딩은 사용자 실행 확인이 남는다.

재생성은 `run_checked.py`에 hard timeout을 주고 `build_furigana.py`를 실행한다. 읽기 검증은 `verify_furigana.py`, 수치·해시는 `furigana_build.json` 및 `furigana_verify.json`에 있다. 메인이 최종 검증을 직접 다시 실행하고 설치했다.
