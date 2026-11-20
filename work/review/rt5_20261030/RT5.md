# RT5 (wave 5, 2026-10-30): runtime checks — guide images, item/gear menus, 스타&스타

Worker RT5 (the only worker that starts the emulator). Instance `tools/azahar-test/` (Azahar 2126.1.2, New 3DS,
HLE applets, portable `user/`). Rules: HARNESS §1–§10. Status: **complete** (items 2–4 done; item 1 was finished
before the user cancelled it). Key result: §3.5–3.6 (스타&스타 hit phase 331 frames at 60fps vs 204–234 units at 30fps,
emulator at full speed).
Confidence tags: **confirmed** (seen/measured here), **likely**, **guess**.

## 0. Instance state as found (2026-10-30 21:03 KST, before any run) — confirmed

| item | value |
|---|---|
| mods entry `user/load/mods/00040000001CA900` | junction → `patch/00040000001CA900` (mode `patch`, 38 files, MainMenu.cro sha256 `1F227C75…BAFC`, `rt_mods.py status` ok) |
| emulator | not running |
| `…/001ca900/data/00000001/ML3R_000.sav` | `1F1CF4F65C036D48A88556D39984981F6C37697EE951C804E84B9633DFEBDCCD` (4 B) |
| `…/ML3R_001.sav` (slot 1, test bed source) | `43C2CA72CB6A5FF26174906C62506AE27743EACE6648E4AD2F49AB6ED8EED7CB` (75,968 B) |
| `…/ML3R_002.sav` | `659AB0D2EA21C1B5A7D102548FADDC611B49CE054174A8DD1D3565383293CE5F` (75,968 B) |
| `…/data/00000001.metadata` | `E5738E6DACA097A79AB1270099FD23F3F3B3D6D83CD279726EB41A4907B2E130` (16 B) |
| `user/config/qt-config.ini` (TEST config) | `23A71C631C98A5167AE0DAB437043D9D6526A5181368B75310C0310424AF0339` (35,652 B) |
| `user/config/custom/00040000001CA900.ini` | `1C6E8B89795E80A5976540DA8A9D45BE8C03759BF903B537A15B7DD76B046F7C` (1,915 B) |
| cheats | `user/cheats/` empty (no cheat file for this title) |

Byte copies of all seven files: `state_backup/` (this folder). Restore = copy back + re-hash (§4).

Builds made by RT5 (all under `tools/azahar-test/mods_builds/rt5*`):
- `rt5_ko` = `rt_mods.py use-build rt5_ko --empty-ok` → Korean patch romfs + BAI fix, **no code patch** (30fps).
- `rt5_nomods` = empty folder (helper `rt5_mods.py use-empty`), the junction points at it → no LayeredFS at all.
- `rt5_p60` = byte copy of the whole `patch/00040000001CA900` (38 files, `code.ips` at the title root) as a real folder,
  so that the T1 bed can be installed on the shipped 60fps build without touching `patch/` (helper `rt5_mods.py use-copy`).


## 1. Guide (가이드) — top-screen images

Path: field (slot 1, Bowser at the save block) → START (스타 메뉴: 아이템 / 장비 / 능력 / 기록 / 배지 / 가이드) → 가이드
(bottom right: `DRIGHT DRIGHT DDOWN A`) → four categories 필드 기본 / 배틀 기본 / 필드 액션 / 배틀 어택 → topic list → pages
(`DRIGHT` = next page). Grabs = both screens of the render surface (top 400×240 above bottom 320×240, scale 1.66,
saved at 1600×790).

### 1a. `use-patch` (Korean + 60fps, 38 files) — boot 21:08 KST, pid 30668 — confirmed

Log: `ApplyCodePatch … /mods/00040000001CA900/code.ips patching code.bin`, 74 `LayeredFS replacement` lines,
`System_IsNew3ds: true`. Opening the pause menu: `Unloading CRO "Field"` (t = 96.42 s), `CRO "MainMenu" loaded at
0x0047B000, fixed_end=0x004B2000`, `CRO "MenuGuide" loaded at 0x004B3000, fixed_end=0x004B6000` (t = 96.44 s). Opening
the guide and its pages added **no** log line (no FS error, no GPU error, no CRO load). The guide runs inside the
MainMenu task; MenuGuide.cro is loaded together with MainMenu when the pause menu opens.

| file | screen | top screen |
|---|---|---|
| `guide_a_p1.png` | 필드 기본 → 캐릭터 이동 1/2 (「◯로 이동할 수 있어요.」) | **starry background only, no picture** |
| `guide_a_p2.png` | 캐릭터 이동 2/2 | no picture |
| `guide_a_p3.png` | 필드 기본 → 캐릭터별 버튼 1/2 | no picture |
| `guide_a_p4.png` | 캐릭터별 버튼 2/2 | no picture |
| `guide_a_p5_btlbasic.png` | 배틀 기본 → 기본①: 커맨드를 골라 공격 1/5 | no picture |
| `guide_a_list_btlattack.png` | 배틀 어택 topic list | starry background |
| `guide_a_p6_btlattack.png` | 배틀 어택 → 점프 1/1 (시범 / 연습 buttons) | no picture |

Waiting 5 s on a page does not make a picture appear (`guide2.png` vs `guide2b.png` in scratch: only the shooting star
moved). So **Azahar shows the same symptom as the real New 3DS** with the shipped patch (confirmed for Azahar).


## 2. Item / gear / badge / key-item menus

### 2a. `use-patch` (same boot as §1a) — confirmed (what the grabs show)

Star menu cursor moves with the D-pad, `A` opens, `B` goes back; L/R switch the character on gear/stats pages; `R`
switches the item tabs (consumables 🍄 / battle items 🐢 / key items 🔑).

| file | screen | cursor / content |
|---|---|---|
| `menu0` (scratch) | 스타 메뉴 | labels 아이템 장비 능력 기록 배지 가이드 |
| `menu_items_patch_1.png`, `_1b` | 아이템, tab 1 (consumables) | 슈퍼버섯 15 (desc. 「마리오와 루이지 중 한 명의 HP를 50 회복.」) |
| `menu_items_patch_2.png` | same | 약간매운치킨 30 (「쿠파의 HP를 80 회복.」) |
| `menu_items_patch_3.png` | same, scrolled | 미라클너트 31 (「마리오와 루이지의 HP를 완전 회복.」) |
| `menu_items_patch_4_tabR.png`, `_5` | tab 2 (battle items) | empty list for this save |
| `menu_items_patch_6_tabR2.png` | tab 3 (key items) | 해머 1 (「잡동사니 스페이스에서 발견한 해머. 이걸로 단단한 것을 부술 수 있다!」) |
| `menu_items_patch_7.png` | same | 블캐츠 1 (「먹깨굼바 안에 있던 블캐츠.」), 배큐엄블록 |
| `menu_gear_patch_1.png` | 장비, KOOPA, 장비 중 slots | 무장등껍질 (desc. + stat strip) |
| `menu_gear_patch_2.png` | same | 파워이빨 |
| `menu_gear_patch_3.png`, `_4` | KOOPA gear list (장비) | 파워이빨 E / 스페셜이빨SP / 스페셜이빨 / 나대기이빨 / 아뜨뜨이빨 / 양날이빨, compare numbers in green/red |
| `menu_gear_patch_5.png` | back to slots | 파워이빨 |
| `menu_gear_patch_6_R.png` | LUIGI slots | 퍼펙트웨어 / POW부츠DX / POW글러브DX |
| `menu_gear_patch_7_R2.png` | MARIO slots | 퍼펙트웨어 / POW부츠DX / POW글러브DX |
| `menu_gear_patch_8_list.png`, `_9_list` | MARIO boots/accessory list | POW부츠DX 2 / 톡톡부츠 / 욕심쟁이부츠 / 럭키스트랩 / 해피스트랩 3 / 절약벨트 |
| `menu_badge_patch_1.png` … `_7`, `_8_L`, `_9_RR` | 배지 wheel (마스터배지 / 보너스배지, 결정) | description 「배틀 종료 시 획득 EXP가 2배.」 on both screens; D-pad/L/R did not move the badge cursor (touch-driven, not tried) |
| `menu_records_patch_1.png`, `_2` | 기록 (icon grid 블록 76% / 홈 40% / 어택피스 / 어택 미니 게임 / 배틀 콜로세움 / BGM 79%) | top: 배틀 횟수 380 … Excellent 횟수 1152 … |
| `menu_stats_patch_1.png` | 능력, KOOPA (LV 32, 파이널 보스 랭크, gear list small) | 무장등껍질 |
| `menu_stats_patch_2_R.png`, `_3_R2` | 능력, other characters | |

What is visibly mixed (for FONT; likely, from the grabs at 1.66× scale): names that contain Latin letters/digits
(`POW부츠DX`, `POW글러브DX`, `스페셜이빨SP`, `파워팔찌SP`, `Excellent 횟수`) draw the Latin part with the large 3DX
glyphs next to visibly smaller Hangul; consumable names in the item list (`슈퍼버섯`…) look larger/greyer than key-item
names (`해머`, `블캐츠`); the same gear names are drawn smaller on the 능력 page than on the 장비 page; Luigi/Mario
`SUYEOM` touches its number (`SUYEOM126`) on the 장비 and 능력 pages.


### 1b. Korean only, no 60fps code (`rt5_ko` = `use-build rt5_ko --empty-ok`, 37 files) — boot 21:18 KST, pid 31944 — confirmed

Log: **no** `ApplyCodePatch` line, 74 `LayeredFS replacement` lines. Pause menu: `CRO "MainMenu" loaded at 0x0047B000`,
`CRO "MenuGuide" loaded at 0x004B3000` (t = 93.78 s), nothing else while the guide pages were open. Log copy:
`log_b_rt5_ko.txt`.

| file | screen | top screen |
|---|---|---|
| `guide_b_p1.png` … `guide_b_p4.png` | 캐릭터 이동 1/2, 2/2, 캐릭터별 버튼 1/2, 2/2 | starry background only, **no picture** |
| `guide_b_p5_btlbasic.png` | 기본①: 커맨드를 골라 공격 1/5 | no picture |
| `guide_b_p6_btlattack.png` | 배틀 어택 → 점프 1/1 | no picture |

→ The missing picture does **not** depend on the 60fps code (`code.ips`) (confirmed in Azahar).


### 1c. No mods at all (`rt5_nomods` = empty folder, Japanese v1.2) — boot 21:22 KST, pid 31312 — confirmed

Log: **0** `LayeredFS` lines, no `ApplyCodePatch`. Pause menu: `CRO "MainMenu" loaded at 0x0047A000, fixed_end=0x004B1000`,
`CRO "MenuGuide" loaded at 0x004B2000, fixed_end=0x004B5000` (t = 78.68 s; one page lower than with the patch because
the patched MainMenu.cro differs). No warning/error line while the guide was open (whole-log warning/error census:
only boot-time stubs, `GetOpenDelayNs`, the CHN/KOR/TWN shared-font line and my RPC flush read). Log copy `log_c_nomods.txt`.

| file | screen (Japanese) | top screen |
|---|---|---|
| `guide_c_categories.png` | フィールドきほん / バトルきほん / フィールドアクション / バトルアタック | starry sky |
| `guide_c_p1.png`, `_p2` | キャラクターの移動 1/2, 2/2 | starry sky only, **no picture** |
| `guide_c_p3.png`, `_p4` | キャラクターのボタン 1/2, 2/2 | no picture |
| `guide_c_p5_btlbasic.png` | 基本①：コマンドを選んで攻撃 1/5 | no picture |
| `guide_c_p6_btlattack.png` | ジャンプ 1/1 (おてほん / れんしゅう) | no picture |
| `guide_c_list_fldaction.png` | フィールドアクション list | starry sky |
| `guide_c_p7_fldaction1.png`, `_p8_fldaction1_2` | アクションアイコン 1/2, 2/2 | no picture |
| `guide_c_p9_fldaction4.png` | ハンマー 1/3 | no picture |
| `guide_c_p10_btlbasic3.png`, `_p11_btlbasic3_2` | ジャンプでの攻撃 1/2, 2/2 | no picture |

**Result of item 1 (confirmed in Azahar):** the top screen of the guide is the same in all three configurations: the
menu's starry sky (`MENU_BG_U`, shooting stars animate), never a picture — also in the unmodified Japanese game. The
Korean files and the 60fps code therefore do not change what the guide's top screen shows in Azahar. This matches
GUIDE's static finding (`work/review/guide_20261030/REPORT.md` §1: the guide page builds only `MENU_GUIDE_L.bflyt`;
no picture source exists for guide pages). Not testable here: a real-GPU-only failure (Azahar ignores SARC/BFLIM
alignment) — but since the original has no top picture either, such a failure would have nothing to hide on the top
screen. Bowser Jr. RPG guide (KJGuide.cro): not reached (slot 1's 쿠파주니어 RPG is at NEW GAME; see §5).


> **Item 1 cancelled by the user** (lead steering message, 2026-10-30 ~21:30 KST: the user confirmed on a real cartridge
> that the guide's top screen is empty in the original game). The §1 grabs and notes above were already complete
> when the message arrived (all three configurations done) and are kept as they are.

### 2c. No mods (Japanese reference, same boot as §1c) — confirmed (what the grabs show)

Same key sequences as §2a, file names `menu_*_orig_*` correspond 1:1 to `menu_*_patch_*`:

| file | screen |
|---|---|
| `menu_items_orig_1.png`, `_2`, `_3` | アイテム tab 1: スーパーキノコ 15 / ピリからチキン 30 / ミラクルナッツ 31 (cursor rows as in 2a) |
| `menu_items_orig_4_tabR.png` | tab 2 (empty) |
| `menu_items_orig_6_tabR2.png`, `_7` | tab 3: ハンマー / バキュームブロック / ブロキャット |
| `menu_gear_orig_1.png` … `_4` | そうび KOOPA: むそうコウラ / パワーきば / パワーうでわSP, list パワーきば … もろはのきば |
| `menu_gear_orig_6_R.png`, `_7_R2` | LUIGI / MARIO: カンペキウェア / POWブーツDX / POWグラブDX |
| `menu_gear_orig_8_list.png`, `_9_list` | MARIO list POWブーツDX … セツヤクベルト |
| `menu_badge_orig_1.png`, `_8_L`, `_9_RR` | バッジ wheel (エキスパートバッジ / キノコバッジ, けってい) |
| `menu_records_orig_1.png` | きろく (バトル回数 380 … Excellent回数 1152) |
| `menu_stats_orig_1.png`, `_2_R`, `_3_R2` | のうりょく KOOPA / LUIGI / MARIO (gear list with マスターバッジ) |

Reference observations (likely, by eye at 1.66×): in the original, kana, kanji and the Latin parts of a name (`POWブーツDX`,
`スペシャルきばSP`, `Excellent回数`) have the same visual height; consumables in tab 1 are drawn grey with the yellow
count for the cursor row in the original too (state colour, not a patch effect); the stats-page gear list uses a
smaller size than the gear page in the original too.


## 3. 스타&스타 (`こいこいスター`, Menu `SpAtk_08`) in the T1 battle

### 3.0 Setup — confirmed
- 60fps run: `rt5_mods.py use-copy rt5_p60` (38 files, every sha256 = `patch/`), `tb_build.py install t1_battle --tag rt5_p60`
  (`FEvent/FEvent.dat` `41131313…972c74`). Boot 21:31 KST, pid 38852. Log: `…/00040000001CA900/code.ips patching code.bin`,
  `LayeredFS replacement file in use for /BAI/BAI.dat` and `/FEvent/FEvent.dat`.
- Logger: `rt5_watch.py follow --label star60_follow --secs 420 --hz 20` (= `rt_watch4.py follow`, output redirected to
  `logs/star60_follow.jsonl`: btl::Main +0x3D/+0x41/+0x45, +0x578 counter `bctr`, step `bstep` (+0xBA15C), `b8A3C`,
  `bspeed` ([[+0x574]+0x7C]), field words, latch).
- Field → battle: after the slot-1 load, the first `A` was swallowed by the field fade-in; a second `A` switched to the
  bros and the T1 battle started (Mario & Luigi vs two `mon_juicy`, `star60_battle_cmd1.png`). btl::Main = 0x30000008,
  +0x3D = 0, +0x41 = 1, +0x45 = 0, `bstep` = 1.0, `b8A3C` = 1.0, `bspeed` = 1.0 (60fps mode, as designed).


### 3.1 The attack is in the save — confirmed
Mario's 스페셜 어택 list (one shared list in DX, `star60_splist_1.png` … `star60_splist_star2.png`): 초록등껍질 3 / 파이어플라워 5 /
점프점프헬멧 8 / 분신나무통대포 11 / … / 원더메테오 16 / 스핀토관 13 / 스위트바스켓 14 / 아무데나창문 21 / **스타&스타 22** (last row;
desc. 「◯로 옐로스타를 움직여서 큰 스타가 빨강이면 Ⓐ, 초록이면 Ⓑ로 작은 스타를 던지자! 공격 대상: 하나 효과: DEF 다운」).
Mario SP 117. The list has 난이도 (Y: 보통 / 쉬움) and the touch buttons 시범 / 연습. `rt_input.py touch 141 183` presses 시범
(touch input works: client (775,703)).

### 3.2 60fps (`rt5_p60`), 시범 (demonstration, the game plays the attack itself) — confirmed
`star60_demo/` (burst2: 200 frames every 150 ms, `fNNN.png` scene + `sNNN.png` status bar, `index.json` with wall times),
log `logs/star60_demo_follow.jsonl`. The demo runs in the battle task (btl::Main 0x30000008, greyscale scene, the big
star circles the top screen while small stars are thrown at it). btl::Main counter during the demo, 1-s windows:
60.5, **55.4**, 59.3, 60.4, **49.5** (demo start: fade/scene set-up), then 59.2–60.5 for the rest of the 52 s logged
(alternating 59.4/60.4 = sampling quantisation); `bstep` = `bspeed` = `b8A3C` = 1.0 throughout.


The demonstration **loops** until `L` (뒤로) is pressed (screen shows 「L 뒤로」, 「시범」, 「Y 연습 모드」), so one full cycle was
recorded: `star60_demo_loop/` (300 frames × 150 ms, 44.85 s, no late frame) with `logs/star60_demo_loop_follow.jsonl`
(50 s at 20 Hz). Phases (sheet of every 10th frame viewed; timing from `rt5_phase.py`: the demo scene is greyscale,
only effects are coloured):
- throwing phase ends ≈ #086 (t = 12.9 s), the big star leaves the top screen, top screen empty #086–#097;
- the star falls back (#098, 14.7 s), **impact** = full-screen colour flash on both screens #103–#107 (t = 15.45 s);
- hits on the enemy (bottom screen effects, purple/blue burst with many small stars) #108–#139;
- 「EXCELLENT!」 #140–#144 (21.00–21.60 s); bottom screen back to grey #145 (21.75 s); next demo cycle starts with a white
  ray flash ≈ #170 (25.5 s) and the next throwing phase from ≈ #200.
- **impact → end of EXCELLENT = 6.15 s** (#103 → #144, ±0.15 s frame spacing).
- btl::Main counter over the whole 50 s: 1-s windows 59.2–60.5, mean **59.83 frames/s**; `bstep`/`bspeed`/`b8A3C` 1.0.
  **No slowdown in Azahar** at 60fps during the drop/hit phase (confirmed; the emulator ran at full speed).


### 3.3 60fps, the real attack (Mario, 보통) — confirmed
`star60_real_0_list.png` (cursor on 스타&스타), `star60_real/` (330 frames × 150 ms, keys in `index.json`), log
`logs/star60_real_follow.jsonl` (90 s). Input (blind, no star tracking): `A`, wait 2.5 s, then 160 taps alternating A/B
(110 ms each, 20 ms gap) while the Circle Pad sweeps right/down/left/up in 0.53-s legs (≈ 21 s). Result in the frames:
throwing phase #030–#190 with only a few small stars stuck (the marker did not follow the big star), the star leaves
#200, falls #210, hits with damage numbers (「12」) #220–#240, Luigi's command blocks from #260 (≈ 39 s after `A`).
The hit phase here is short (few stars), so the demonstration (§3.2, many stars, EXCELLENT) is the better load case.
btl::Main counter, 2-s windows over 83.6 s: 59.4–60.3, mean **59.84 frames/s**; `bstep`/`bspeed`/`b8A3C` 1.0.


### 3.4 30fps reference (`rt5_ko` + T1: Korean patch + BAI fix, no code patch) — confirmed
Boot 21:47 KST, pid 17884; log has `/FEvent/FEvent.dat` in use and **no** `ApplyCodePatch`. btl::Main 0x30000008,
+0x3D = 1, +0x45 = 1, `bstep` = 2.0, counter 29.6–30.0/s (log `logs/star30_follow.jsonl`, 600 s, covers everything below).
- 시범 loop: `star30_demo_loop/` (420 frames × 150 ms = 63 s, burst started 20 s after pressing 시범): two cycles.
- real attack, same blind input as §3.3: `star30_real/`, `star30_real_0_list.png`. This time the star hit as one big
  impact (blue full-screen flash #220, 「1791」, 「TOTAL 2317」 #230), enemy defeated #240, Luigi's turn #250 — a different
  outcome from §3.3 because the blind input stuck a different number of stars; the real runs are not comparable to
  each other, the demo is.

### 3.5 Comparison of the hit phase (demo, impact flash → 「EXCELLENT!」 appears) — confirmed

Times from the burst frames (±0.15 s), frame counts from btl::Main +0x578 at the same wall time (`rt5_calc.py`):

| run | impact frame | EXCELLENT frame | wall-clock | btl frames | × step = 60-Hz units | counter rate |
|---|---|---|---|---|---|---|
| 60fps (`rt5_p60`), cycle 1 | `star60_demo_loop` #103 (15.45 s) | #140 (21.00 s) | **5.55 s** | 331 | 331 | 59.6/s |
| 30fps (`rt5_ko`), cycle 1 | `star30_demo_loop` #071 (10.65 s) | #097 (14.55 s) | **3.90 s** | 117 | 234 | 30.0/s |
| 30fps (`rt5_ko`), cycle 2 | `star30_demo_loop` #312 (46.80 s) | #335 (50.25 s) | **3.45 s** | 102 | 204 | 29.6/s |

Other segments: 「EXCELLENT!」 shown 0.60 s at both rates (#140→#144 = 38 frames at 60; #097→#101 = 18 frames at 30);
star leaves the top screen → impact 2.55 s at 60fps (#086→#103, 152 frames); 30fps impact → next impact 36.15 s.

Reading: Azahar ran at full speed in both modes (60fps counter 59.6/s, 30fps 30.0/s, no dip during the hit phase), yet
the hit phase of the demonstration lasted **5.55 s at 60fps against 3.45–3.90 s at 30fps** (331 frames against
204–234 60-Hz units, ×1.4–1.6). So at least part of the reported drag is **logic timing** that does not depend on CPU/GPU
load (likely: something in the drop/hit sequence counts frames or spawns per frame without the battle step). The two
30fps cycles differ by 0.45 s, so the number of stars/hits varies a little between demo cycles; a second 60fps cycle is
measured in §3.6 to rule out that variation.


### 3.6 Second 60fps run (fresh `rt5_p60` copy + T1, boot 21:58 KST, pid 26908) — confirmed
`star60b_demo_loop/` (420 frames × 150 ms), `logs/star60b_follow.jsonl` (150 s, counter 59.7–60.0/s in 5-s windows).

| run | impact | EXCELLENT | wall-clock | btl frames (60-Hz units) |
|---|---|---|---|---|
| 60fps run 2, cycle 1 | #066 (9.90 s) | #103 (15.45 s) | **5.55 s** | **331** |
| 60fps run 2, cycle 2 | #314 (47.10 s) | #351 (52.65 s) | **5.55 s** | **331** |

All three 60fps cycles took exactly **331 frames** from impact to 「EXCELLENT!」; the 30fps cycles took 117 and 102
frames = **234 and 204** 60-Hz units. The rest of the demo cycle matches: EXCELLENT → next impact 31.65 s = 1,895 frames
at 60fps; EXCELLENT end → next impact 31.65 s = 947 frames (1,894 units) at 30fps. **Only the drop/hit sequence is longer
at 60fps, by ≈ 100–130 60-Hz units (1.6–2.1 s, ×1.4–1.6), with the emulator at full speed** → logic timing (cause (a)),
measured in Azahar. Real-hardware load (cause (b)) cannot be measured here; Azahar showed no frame-rate dip in either mode.

Incident: a 30fps logger left running (`star30_follow`, 600 s) polled the RPC server while the next instance booted
(log line `RPC_Server <Error> … HandleReadMemory: No target process selected` at t = 1.02 s); that instance (pid 42372)
exited 1 s into boot. The logger was stopped and the emulator relaunched (pid 26908); no file was affected.
Rule for next time: stop every logger before `rt_launch.ps1`.

### 3.7 For STAR / the lead (how to re-check a fix)
- Same bed: `rt5_mods.py use-copy <tag>` (or `rt_mods.py use-build <v3 tag> --ips`) + `tb_build.py install t1_battle --tag <tag>`,
  boot, title `A w2500 A w2000 A w2500 A`, wait ~14 s, `A`, wait 4 s, `A` (the first field `A` is swallowed), battle ≈ 9 s
  later; Mario's turn: `DLEFT`, `A`, `DUP` (cursor wraps to 스타&스타), `rt_input.py touch 141 183` (시범). The demo loops; burst
  `rt5_watch.py burst2 DIR --n 420 --dt 150` + `rt5_phase.py DIR` (impact = both screens' saturation > 200, EXCELLENT = top
  yellow > 80 %), frame counts `rt5_calc.py LOG DIR <impact> <excellent>`.
- Pass criterion (prediction): impact → EXCELLENT ≈ 204–234 btl frames at 60fps (3.4–3.9 s), like 30fps; the rest of the
  cycle unchanged (≈ 1,895 frames).


## 4. Restore (2026-10-30 22:03 KST) — confirmed

- Emulator stopped (`rt_launch.ps1 -Stop` → `closed pid 26908`; `rt_mods.py status`: `emulator_pids: []`); no RT5 logger running.
- T1 bed removed from both builds (`tb_build.py remove t1_battle --tag rt5_p60` / `--tag rt5_ko` → `removed: true`).
- `rt_mods.py use-patch` → junction → `patch/00040000001CA900`, 38 files, MainMenu.cro `1F227C75…BAFC`, `ok: true`.
- Saves and TEST config compared with `state_backup/`: ML3R_000/001/002.sav, `00000001.metadata`, `qt-config.ini`,
  `custom/00040000001CA900.ini` all **byte-identical to the state found** (§0 hashes); nothing had to be copied back.
- Left on disk (RT5's own area): `tools/azahar-test/mods_builds/rt5_ko` (37 files), `rt5_p60` (38 files = patch copy),
  `rt5_nomods` (empty), their `.json` manifests and `rt5_*.tb_backup` (tb_build's backup folders). `patch/`,
  `work/sd_package/` and the user's Azahar folders were not touched.
- This folder: 4,126 files, 307 MB (burst frames). Tools written here: `rt5_mods.py`, `rt5_watch.py`, `rt5_flush.py`,
  `rt5_tile.py`, `rt5_rate.py`, `rt5_phase.py`, `rt5_calc.py`.

## 5. Not done / open

- Bowser Jr. RPG guide (KJGuide.cro): not reached (slot 1's 쿠파주니어 RPG is at NEW GAME). Item 1 was cancelled anyway.
- Shop lists (they may share the item layouts): not reachable from the save room.
- Badge wheel cursor (touch-driven) not moved; L/R rotate the wheels (`menu_badge_*_8_L`, `_9_RR`).
- 스타&스타 on real hardware: not run. Azahar shows the logic-timing part only (§3.5–3.6).
- Text note for the lead (guess, not checked): when the real attack starts, the bottom bar shows a label read as
  「추시 LV8」 (`star60_real/f010.png`, `star30_real/f010.png`); worth a look by the text team.
