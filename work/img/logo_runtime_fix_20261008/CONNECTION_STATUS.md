# Codex 내장 Computer Use 연결 점검 — 2026-10-08

이 문서는 이전 연결 실패 시도의 기록이다. **현재 상태: 해결·설치·실제 게임 검증 완료.** 재시도에서 현재 제공된 computer-use/26.1002.52244 스킬의 `@oai/sky` 직접 초기화가 성공했다. Codex 내장 도구로 Azahar에서 재현·수정·재검증했으며, 최신 결과는 `REPORT.md` 및 `runtime_verify.json`에 있다. 아래 실패와 미설치 상태는 재시도 전의 기록으로 보존한다.

사용자가 직전 f90441b6... 설치본에서 &가 두 단어 아래로 떨어지는 실제 화면을 제공했다(user_issue.png). 다른 타이틀 문제는 고쳐졌다고 확인했다. 이전 로고의 파일 기반 애니메이션 검증은 실제 렌더링을 재현하지 못한 것으로 확인됐으므로 그 검증만 반복해 완료 처리하지 않는다.

## 내장 도구 연결

1. bundled computer-use/26.727.40816의 SKILL.md를 읽고 지시된 computer-use-client.mjs를 mcp__node_repl__js에서 import/초기화했다.
2. 오류: Windows Computer Use Sky runtime is unavailable.
3. js_reset 후 다시 초기화해도 같은 오류다. 일반 JavaScript 실행은 작동하지만 내장 연결에 필요한 nodeRepl.nativePipe/config 및 privileged 환경 정보가 없다.
4. 로컬 config.toml의 computer-use@openai-bundled는 enabled=true다. 수동 node_repl MCP 등록은 오래된 cua_node/3dd31cfff853001c를 가리키며, newer fb8898c05a62885e도 설치돼 있다. 이것이 원인인지 확정하지 않았다. 전역 설정과 허용 정책은 수정하지 않았다.
5. 연결 오류 후 잠깐 검토한 Orca 대체 경로도 runtime_open_timeout 오류였고, 사용자가 명시적으로 Codex 내장만 사용하도록 정정했다. 이후 Orca를 호출하지 않았으며 별도 입력 스크립트는 제거했다.
6. Azahar 창은 shell로 열었으나 초기 창 핸들 대기 중 종료되어 캡처/키 입력/게임 재생은 수행하지 않았다. 따라서 직접 게임을 검증했다고 주장하지 않는다.

공식 사용 안내: https://learn.chatgpt.com/docs/computer-use (Computer Use 플러그인, @Computer 요청, Windows 활성 데스크톱 요구). 로컬 연결 누락은 실제 도구 실행 결과이며 공식 문서로 원인을 확정하지 않았다.

## 재개할 작업

- Codex 앱의 Computer Use 연결을 갱신한 다음 같은 채팅에서 내장 초기화를 다시 시도한다. 앱 재시작은 필요한 연결을 새로 받기 위한 조치이며 성공을 보장하지 않는다.
- 연결되면 guidance/api/confirmations 문서를 읽고 Azahar를 내장 도구로 제어한다.
- 설치된 3DX v1.2를 실행하고 시작 인트로 조립/정지 구간을 캡처한다. 마리오/루이지/&의 화면 밑선과 이동 궤적을 직접 잰다.
- 이전 projection은 world Z/texture V와 실제 카메라 투영 관계를 충분히 검증하지 않았다. 특히 & 부모 Z=153, 단어 Z=144에 대한 텍스처 내부 +12행 보정이 실제 화면에서 아래 방향을 더하는지 확인한다. 이는 아직 가설이다.
- 실제 화면에서 확인한 방향/배율로 intro 이미지만 수정한다. 사용자 확인이 끝난 main bottom/top 타이틀은 그대로 보존한다.
- 에뮬레이션을 정상 중지한 뒤 새 파일을 교체하고, 재시작하여 같은 조립 장면 및 이어지는 움직임을 다시 검증한다.
- 그 다음 patch/SD/ZIP 동기화와 바이너리 검증을 한다.

## 현재 보존 상태

- 설치된 FMdl/배포 ZIP은 직전 설치본 그대로다.
- before_fmdl.dat / before_title.bch / before_intro_* / before_geometry_plan.json: 재개용 스냅샷.
- AGENTS.md §6에 이번 사용자 지침(내장 Computer Use만, 직접 실행 허용)을 반영했다.
- 서브에이전트 사용 없음.
