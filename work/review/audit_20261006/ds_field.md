# 본편 필드 대사 DS 대조 검토 — 2026-10-06

기준: AGENTS.md 0·4·5.3, text/style_guide.md 전반 및 5.1 확정 결정, text/glossary.tsv 현행, work/review/R12.md·R13.md·review_items.md. 원본 게임·JP·DS 추출물을 수정하지 않았다. 전역 용어집, ko_final, lead_state, dup_overrides는 수정하지 않았다.

## 범위와 방법

- FMsg 본편 i_* / o_*, fcommon, 이벤트·minimap: 75배치, 정본 메시지 3,333개. 이 정본에 연결된 dups id는 732개이며 쿠파주니어 k_* 연결도 일부 포함하므로 이를 본편 메시지 수에 그대로 더하지 않는다.
- room_map 기준 전체 DS FEvent.json 방을 읽고 배치의 DS:EMesJig 참조도 합쳤다. 배치 ds_reference의 400줄 잘림은 사용하지 않고 DS FEvent 전체로 보완했다.
- 번역문에서 제어태그·페이지/줄 나눔·공백을 제외한 글자와 문장부호가 DS 문자열과 동일한 메시지 2,870개를 자동 확인했다. 이 통계는 띄어쓰기 보존이나 일본어 뜻의 완전한 일치까지 자동으로 증명하는 수치가 아니다.
- 차이가 남은 463개 모두 일본어/번역/DS와 기존 메모를 직접 대조했다. DS 동일 그룹은 공식 문장을 보존하는 방향으로 검사하고 별도 의미 변경을 가하지 않았다.
- 후보 최초 508개 → 공통 동일 문자열·EMesJig 참조 보완 후 463개. ds_field_before_rows.json 및 ds_field_candidates.tsv는 수정 전 자료이며, 최종 판정은 ds_field_evaluated.tsv에 있다.

## 수정 결과

뜻이 같은 DS 문장을 유지하면서 3DX 일본어 부호에 다시 맞춘 흔적 9개를 DS 문장부호로 복원했다. 뜻·어휘·제어태그·뜸 시간·페이지 수는 그대로다. 5배치 개별 --check는 모두 오류 0. 경고는 기존 glossary 경고이며 해당 log에 남겼다.

- FMsg/i_energy_11#0: DS0BD#0의 노래 제목 따옴표 없음 복원. 뜻이 같은 DS 번역의 문장부호 보존(AGENTS 0·4.6); 페이지 수와 태그 유지.
- FMsg/i_metaboru_19#6: DS0B8#6의 동일 문구에 없던 말줄임표 제거. 3DX 페이지 분할·태그는 유지하면서 DS 문장부호 보존.
- FMsg/o_ekubon_06#0: DS053#0과 뜻이 같은 마지막 문장의 느낌표를 DS대로 한 개로 복원.
- FMsg/o_ekubon_07_1#0: DS048#37과 뜻이 같은 문장의 느낌표를 DS대로 한 개로 복원. 뜸 태그 유지.
- FMsg/o_ekubon_07_1#7: DS048#13의 동일 발화 문장부호 복원. 뜸 태그 유지.
- FMsg/o_ekubon_07_1#12: DS048#18과 뜻이 같은 문장의 느낌표를 DS대로 한 개로 복원.
- FMsg/o_ekubon_07_1#30: DS048#7의 동일 질문 문장부호 복원.
- FMsg/o_koopa_13_1#6: DS041#13과 뜻이 같은 문구에 추가된 느낌표 제거. 3DX 뜸 태그 유지.
- FMsg/o_mushiba_05_before#26: DS03E#20의 땡큐 베리 머치 문장부호 복원. 3DX 뜸 태그 유지.

## 유지한 중요한 차이

- SELECT 버튼 → 아래 화면 「열기」 버튼, 방향패드 → 슬라이드 패드, 액션 전환 L/R와 동시 L+R 리셋, 점프·헤엄치기 동시 조작의 버튼 변경: 3DX 원문에 맞아 유지.
- 블록 상점 선택지 통합, 예/아니요 또는 퀴즈 선택지 순서, 스태미나·스타 메뉴 가이드 및 신규 터보 배틀 안내, 특별 세일 1코인, 새로운 콩·방어웨어·플라워/부메랑 랭크: 3DX 변경을 반영했으므로 DS로 되돌리지 않음.
- 몸속/암흑 파워/동료/수상한 지점/미니 지도/방어 장치/보너스 카드/초강력한 어택 등은 현행 glossary 결정에 따른 차이. マリオ達=마리오 일행의 기본값은 따르되 DS155·1AB 등의 마리오 형제와 DS0F4의 마리오와 루이지 예외도 보존됨.
- 1DX 공통 아이템 회복허브의 표기는 work/ref_1dx_ko.tsv Item.msbt N_Refleshhb·Ns_Refleshhb·F_Refleshhb와 일치. 3DX 신규 콩/보너스 카드/방어웨어 등은 1DX TSV에 동일 항목을 찾지 못했으며 현행 DS 방식의 glossary coined 표기를 유지.
- 신규 보스·쿠파주니어 관련 본편 카메오 3개(o_areanone_k_lastbattle): 쿠파주니어의 나/아빠 및 군단 명칭이 기존 결정과 같음.

## 확정하지 않은 의미 검토 2건

### FMsg/i_metaboru_06#43

추가 의미 검토: ボケーッとしてきた는 멍하니/정신없이 되는 모습. 현행 멍청해졌다는 지능 저하로도 읽힘. 정답 ボーッとの 구분까지 고려하여 멍~해졌다 등으로 옮길지 판단 필요.

- 일본어: クッパは 頭の調子がどうなって / きたと 感じているでしょう？ / クラクラしてきた / ボーッとしてきた / ボケーッとしてきた / ズキズキしてきた
- 현행: 쿠파는 자신의 머리가 / 어떻게 됐다고 느끼고 있나요? / 어질어질해졌다 / 멍해졌다 / 멍청해졌다 / 지끈지끈해졌다
- DS: DS069#31 쿠파는 자신의 머리가 / 어떻게 됐다고 느끼고 있나요? / 어질어질해졌다 / 멍해졌다 / 둥글둥글해졌다 / 지끈지끈해졌다

### FMsg/i_energy_32#19

추가 의미 검토: 失笑는 참지 못하고 웃음을 터뜨리는 뜻. 현행 코웃음은 경멸이 강화될 수 있으나 이 장면의 빈정거림과도 맞아 확정 오류로 단정하지 않음.

- 일본어: イモーヌ 失笑！ みたいな～
- 현행: 애번느 코웃음! …이랄까요~
- 같은 장면의 DS: DS110#8 `웃기네요![Next]기가 막혀서…`. DS110#2 `애번느가 생각해도 딱하네요!`는 #13의 다른 발화이며, #19의 직접 대응 문장으로 쓰지 않는다. (메인 재확인: focus.log)

## 이전 리뷰의 중복 대사 이월 3건 — 현재 해결됨

현재 text/ko/_dup_overrides.json을 읽어 각 장면의 DS 표기가 이미 별도로 적용되어 있음을 확인했다. 새 수정은 하지 않았다.
- o_peach_op_04#38: 오프닝 DS218#4 으흑흑… / 엔딩 정본 o_koopa_end_01#3 DS23E#22 어흐흑…
- o_koopa_end_01#16: 엔딩 DS23E#17 꺄~ 무서워, 무서워… / 정본 o_ekubon_16#7 DS07F#7 히익~ 무섭다, 무서워…
- o_ekubon_19#10: DS0A8#17 허억!! 크허어~억!? / 정본 o_ekubon_14#0 DS032#8 으으!! 아아아~!

## 게임 화면 확인이 남은 사항

코드·텍스트만으로 화자를 확정할 수 없는 o_chika_09_before#30·#31, 바닥 위치 마크 모양(o_ibiki_03), 작은 한 줄 알림·큰 글자의 실제 화면 칸 맞춤, 퀴즈·마사지 선택지 시작 결과는 기존 review_items 게임 확인 항목으로 유지한다. Azahar는 사용자가 직접 실행해야 한다. 폰트 픽셀/메트릭·이미지 설치·최종 빌드는 메인 감사 범위다.

## 배치별 메시지 수

| 배치 | 정본 메시지 |
|---|---:|
| FMsg__cs_scn_01_metakoro_03_U | 1 |
| FMsg__ev_MAIN_town_20 | 1 |
| FMsg__ev_zutsuda_09 | 3 |
| FMsg__fcommon | 1 |
| FMsg__i_air_01__and7 | 53 |
| FMsg__i_areanone_op_02_L | 6 |
| FMsg__i_areanone_puzzle_01_L__and1 | 32 |
| FMsg__i_challenge_01 | 106 |
| FMsg__i_dokan_01 | 32 |
| FMsg__i_energy_01__and11 | 67 |
| FMsg__i_fire_02 | 14 |
| FMsg__i_garakuta_02__and7 | 76 |
| FMsg__i_kinopio_01 | 41 |
| FMsg__i_kioku_02__and1 | 23 |
| FMsg__i_koopa_13_beam_01_L__and1 | 26 |
| FMsg__i_koshi_01 | 30 |
| FMsg__i_metaboru_02__and9 | 109 |
| FMsg__i_metaboru_19 | 19 |
| FMsg__i_odoroki_01 | 23 |
| FMsg__i_power_arm_01__and1 | 15 |
| FMsg__i_power_hip_01 | 10 |
| FMsg__i_power_hip_SA_adorena_01_L | 13 |
| FMsg__i_power_leg_SA_push_01_L | 7 |
| FMsg__i_power_lungs_SA_fire_01_L | 11 |
| FMsg__i_power_nose_01 | 17 |
| FMsg__i_power_stomach_02__and1 | 34 |
| FMsg__i_press_01 | 24 |
| FMsg__i_pump_01__and6 | 54 |
| FMsg__i_shinkei_01__and1 | 23 |
| FMsg__i_tainai_01 | 72 |
| FMsg__i_test_dnh_01 | 1 |
| FMsg__minimap_o_mushiba_01 | 3 |
| FMsg__o_areanone_allmap_01_U | 17 |
| FMsg__o_areanone_allmap_bcat_U | 11 |
| FMsg__o_areanone_dstar_setumei_01_L | 7 |
| FMsg__o_areanone_end_02_U__and1 | 16 |
| FMsg__o_areanone_k_lastbattle_01_U | 3 |
| FMsg__o_areanone_lastboss_01_L__and1 | 24 |
| FMsg__o_areanone_meter_01_U | 7 |
| FMsg__o_areanone_suishou_01_L | 1 |
| FMsg__o_chika_01__and3 | 59 |
| FMsg__o_chika_geraexpress_04 | 7 |
| FMsg__o_ekubon_02__and7 | 94 |
| FMsg__o_ekubon_09_1__and3 | 86 |
| FMsg__o_ekubon_15__and6 | 109 |
| FMsg__o_ekubon_39_1 | 14 |
| FMsg__o_evselect_U | 1 |
| FMsg__o_gepu_01__and3 | 79 |
| FMsg__o_gepu_08__and1 | 43 |
| FMsg__o_ibiki_01__and1 | 50 |
| FMsg__o_koopa_01__and6 | 108 |
| FMsg__o_koopa_09_2_gerashow_01_U__and3 | 51 |
| FMsg__o_koopa_13_2__and4 | 90 |
| FMsg__o_koopa_18__and2 | 100 |
| FMsg__o_koopa_19__and10 | 102 |
| FMsg__o_koopa_end_01 | 26 |
| FMsg__o_koopa_r_20__and5 | 65 |
| FMsg__o_mushiba_01__and7 | 109 |
| FMsg__o_mushiba_16__and2 | 108 |
| FMsg__o_otapuku_02__and1 | 5 |
| FMsg__o_peach_1f_03__and3 | 107 |
| FMsg__o_peach_2f_04__and5 | 40 |
| FMsg__o_peach_g_02__and6 | 95 |
| FMsg__o_peach_op_01__and3 | 81 |
| FMsg__o_peach_t_02__and6 | 59 |
| FMsg__o_test_fh_01 | 2 |
| FMsg__o_test_ho_01 | 2 |
| FMsg__o_test_mk_01 | 1 |
| FMsg__o_town_01_after__and10 | 87 |
| FMsg__o_town_23__and7 | 69 |
| FMsg__o_town_31__and1 | 96 |
| FMsg__o_town_33__and1 | 82 |
| FMsg__o_town_34_suishou_01_U__and7 | 110 |
| FMsg__o_zutsuda_01__and9 | 108 |
| FMsg__o_zutsuda_30 | 55 |

