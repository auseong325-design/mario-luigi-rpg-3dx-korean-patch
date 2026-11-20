# WEB — prior art, cheats, crash reports, Luma/Azahar loading facts

Worker: WEB (M&L RPG3 DX 60fps project). Started 2026-10-30.
Every fact carries a source URL. Confidence: confirmed (read in source/primary post) / likely / guess.
Facts and hypotheses are kept separate; hypotheses are marked "HYPOTHESIS".

(Sections are appended as the research progresses.)


## 1. Every variant of the BIS+BJJ 60fps cheat (exact text)

Thread: GBAtemp "60 FPS Patches/Cheat Codes Releases and Discussion" (thread 550527, 40 pages, all fetched
2026-10-30 and grepped). First post (cheat list, by Hazerou, last edited 2021-07-13):
https://gbatemp.net/threads/60-fps-patches-cheat-codes-releases-and-discussion.550527/post-8831461
Repo: https://github.com/Reshiban/60FPS-AR-CHEATS-3DS (files
`Cheats/Mario & Luigi - Bowsers Inside Story + Bowser Jrs Journey (USA)/00040000001D1400.txt` and `(EUR)/00040000001D1500.txt`).
No JPN (`00040000001CA900`) code exists in either place (confirmed: repo tree has only USA/EUR; thread grep for
`1CA900` = 0 hits).

### 1.1 Timeline (confirmed, from post dates)
| Date | Event | Source |
|---|---|---|
| 2020-02-10 | Hazerou adds "BIS+BJJ v1.2 EUR, by @Reshiban" (game-speed codes) | https://gbatemp.net/threads/60-fps-patches-cheat-codes-releases-and-discussion.550527/post-8943281 |
| 2020-03-02 | Hazerou adds BIS+BJJ v1.2 USA+EUR "FPS Codes, by @Shay#4684 from Discord with help of @Reshiban" | https://gbatemp.net/threads/60-fps-patches-cheat-codes-releases-and-discussion.550527/post-8963011 |
| 2020-03-25 | Reshiban repo: files created (USA commit 8760890, EUR 3dfaaf2); EUR adds Game Speed codes; 2020-04-18 only the credit line changed | https://github.com/Reshiban/60FPS-AR-CHEATS-3DS/commits/master/Cheats/Mario%20%26%20Luigi%20-%20Bowsers%20Inside%20Story%20%2B%20Bowser%20Jrs%20Journey%20(USA)/00040000001D1400.txt |
| 2021-01-07 | Hazerou posts "v1.2 FIX" (adds neighbour-word checks) | https://gbatemp.net/threads/60-fps-patches-cheat-codes-releases-and-discussion.550527/post-9320576 |
| 2021-01-11 | Hazerou adds "[60FPS (L+R) v1.2 Less Crashes]" + "[30 FPS (L+UP) v1.2 Less Crashes]", tested by BlazeHeatnix | https://gbatemp.net/threads/60-fps-patches-cheat-codes-releases-and-discussion.550527/post-9325144 |
| 2021-08-20 | A (now deleted) user posts a CTRPF-only "delayed" variant | https://gbatemp.net/threads/60-fps-patches-cheat-codes-releases-and-discussion.550527/post-9558787 |

The repo files never changed after 2020-04-18 (only 2 commits for USA, 3 for EUR; diffs read via GitHub API), so
the repo holds only the original Shay codes (+ EUR game speed). FIX and Less Crashes exist only on GBAtemp.
Repo issues/PRs: 9 in total, none about BIS (https://github.com/Reshiban/60FPS-AR-CHEATS-3DS/issues?q=is%3Aissue).

### 1.2 AR semantics needed to read the codes (Gateway/Luma format)
`D3000000 X` offset=X; `0XXXXXXX Y` u32 write; `2XXXXXXX Y` u8 write (low byte of Y only, so `20000065 01000000`
writes 0x00); `5XXXXXXX Y` if u32==Y; `6XXXXXXX Y` if u32!=Y; `DD000000 K` if keys pressed (R=0x100, L=0x200,
Up=0x40; 0x300 = L+R, 0x240 = L+Up); `D0` ends one if; `D2` ends all ifs and clears offset/registers.
Little-endian: u32 `0x01000101` at A means bytes A+0..3 = `01 01 00 01`; `0x01000001` = `01 00 00 01`.
(Luma's engine source is summarised in section 6.)

### 1.3 Original (Shay, 2020-03) — USA and EUR are byte-identical
```
[60FPS (Hold R button for default 30FPS) v1.2]
D3000000 30000000
50000074 01000101
20000075 00000000
D0000000 00000000
520DA3AC 01000101
220DA3AD 00000000
D0000000 00000000
50000064 01000101
20000065 01000000
D0000000 00000000
50000044 01000101
20000045 00000000
D0000000 00000000
DD000000 00000100
50000074 01000001
20000075 00000001
D0000000 00000000
520DA3AC 01000001
220DA3AD 00000001
D0000000 00000000
50000064 01000001
20000065 01000001
D0000000 00000000
50000044 01000001
20000045 00000001
D0000000 00000000
D0000000 00000000
{Game runs normal.}

[60FPS v1.2]            = first 13 lines above + D2000000 00000000
[Default 30FPS v1.2]    = D3000000 30000000, then for each of 0x74/0x20DA3AC/0x64/0x44:
                          5X.. 01000001 ; 2X..(+1) 00000001 ; D0000000 00000000 ; finally D2000000 00000000
```
EUR extras (Reshiban): `[Game Speed faster v1.2]` `D3000000 32000000 / 000DBDB8 40000000 / D2000000 00000000`;
normal = `3F800000` (1.0f), slower = `3F000000` (0.5f). Source: raw files at
https://raw.githubusercontent.com/Reshiban/60FPS-AR-CHEATS-3DS/master/Cheats/Mario%20%26%20Luigi%20-%20Bowsers%20Inside%20Story%20%2B%20Bowser%20Jrs%20Journey%20(EUR)/00040000001D1500.txt
(The GBAtemp first post also lists the three Game Speed codes inside the EUR block.)

Watched addresses (all with D3 offset 0x30000000): words at **0x30000044, 0x30000064, 0x30000074, 0x320DA3AC**;
written byte = word+1. Observation (fact): 0x30000044/0x64/0x74 are only 0x10–0x20 apart, so they cannot be +0x44
of three *simultaneously live* TaskBase objects. HYPOTHESIS (likely): they are the same kind of object landing at
base 0x30000000 / 0x30000020 / 0x30000030 in different scenes (heap rebuilt per scene), and 0x320DA368 is a
longer-lived object; the pattern check is what makes the code scene-adaptive. RT should verify which class sits at
each address in field / battle / menu.

### 1.4 "FIX" (Hazerou, 2021-01-07) — exact text, post-9320576
```
[60FPS (Hold R button for default 30FPS) v1.2 FIX]
D3000000 30000000
6000007C 00000001
50000074 01000101
5000007C 00000101
20000075 00000000
D2000000 00000000
D3000000 30000000
620DA3B4 00000001
520DA3AC 01000101
520DA3B4 00000101
220DA3AD 00000000
D2000000 00000000
D3000000 30000000
6000006C 00000001
50000064 01000101
5000006C 00000101
20000065 01000000
D2000000 00000000
D3000000 30000000
6000004C 00000001
50000044 01000101
5000004C 00000101
20000045 00000000
D2000000 00000000
DD000000 00000100
D3000000 30000000
6000007C 00000101
50000074 01000001
5000007C 00000001
20000075 00000001
D2000000 00000000
DD000000 00000100
D3000000 30000000
620DA3B4 00000101
520DA3AC 01000001
520DA3B4 00000001
220DA3AD 00000001
D2000000 00000000
DD000000 00000100
D3000000 30000000
6000006C 00000101
50000064 01000001
5000006C 00000001
20000065 01000001
D2000000 00000000
DD000000 00000100
D3000000 30000000
6000004C 00000101
50000044 01000001
5000004C 00000001
20000045 00000001
D2000000 00000000

[60FPS v1.2 FIX]  = the first 24 lines above (four blocks, no R part)
```
Meaning (fact, from the AR semantics): flip +0x45 (relative to the matched word = obj+0x44) to 0 only if the u32 at
**obj+0x4C == 0x00000101** (bytes +0x4C=1, +0x4D=1); restore to 1 only if obj+0x4C == 0x00000001. So the FIX adds a
second byte, **obj+0x4D**, that mirrors the fps state (1 when 30fps is latched, 0 after the game itself chose 60?).
HYPOTHESIS for ENG: TaskBase+0x4C/+0x4D is a latched copy of the fps mode (cf. funcInit copying +0x3C/+0x3D to
+0x44/+0x45); the FIX author used it as a signature to avoid false matches. Result: FIX still crashed at the same
place (section 2, post-9320873/9320885).

### 1.5 "Less Crashes" (Hazerou, 2021-01-11) — exact text from the first post (USA block; EUR block identical)
```
[60FPS (L+R) v1.2 Less Crashes]
DD000000 00000300
D3000000 30000000
6000007C 00000001
60000044 01000101
60000044 01000001
50000074 01000101
5000007C 00000101
20000075 00000000
D2000000 00000000
DD000000 00000300
D3000000 30000000
620DA3B4 00000001
60000044 01000101
60000044 01000001
60000064 01000101
60000064 01000001
60000074 00000300
60000074 01000101
60000074 01000001
520DA3AC 01000101
520DA3B4 00000101
220DA3AD 00000000
D2000000 00000000
D3000000 30000000
50000074 00000300
520DA3AC 01000001
520DA3B4 00000001
220DA3AD 00000001
220DA3B5 00000001
D2000000 00000000
D3000000 30000000
50000064 01000101
520DA3AC 01000001
520DA3B4 00000001
220DA3AD 00000001
220DA3B5 00000001
D2000000 00000000
D3000000 30000000
50000044 01000101
520DA3AC 01000001
520DA3B4 00000001
220DA3AD 00000001
220DA3B5 00000001
D2000000 00000000
D3000000 30000000
50000074 01000101
520DA3AC 01000001
520DA3B4 00000001
220DA3AD 00000001
220DA3B5 00000001
D2000000 00000000
DD000000 00000300
D3000000 30000000
6000006C 00000001
60000044 01000101
60000044 01000001
60000074 01000101
60000074 01000001
50000064 01000101
5000006C 00000101
20000065 01000000
D2000000 00000000
DD000000 00000300
D3000000 30000000
6000004C 00000001
60000074 01000101
60000074 01000001
50000044 01000101
5000004C 00000101
20000045 00000000
D2000000 00000000

[30 FPS (L+UP) v1.2 Less Crashes]
DD000000 00000240
D3000000 30000000
520DA3AC 01000001
220DA3AD 00000001
220DA3B5 00000001
D2000000 00000000
DD000000 00000240
D3000000 30000000
50000044 01000001
20000045 00000001
2000004D 00000001
D2000000 00000000
DD000000 00000240
D3000000 30000000
50000064 01000001
20000065 00000001
2000006D 00000001
D2000000 00000000
DD000000 00000240
D3000000 30000000
50000074 01000001
20000075 00000001
2000007D 00000001
D2000000 00000000
```
Meaning (fact): (a) 60fps is applied **only on an L+R press**, never automatically; (b) each low-heap candidate
is flipped only if the *other* low-heap candidates are not currently a 30/60 TaskBase pattern (`6...` = "!=");
(c) four blocks with **no key condition** run every cheat cycle: whenever a low-heap object is present in its
30fps state (`50000064 01000101`, `50000044 01000101`, `50000074 01000101`; plus an odd `50000074 00000300` test),
the 0x320DA3AC object, if it is at 60 (`01000001` and +0x4C==1), is forced back to 30 (+0x45=1 **and +0x4D=1**).
So after every scene change (a new low-heap task appears at 30) everything is back at 30 until the player presses
L+R again — matching BlazeHeatnix's description; (d) the L+Up code restores 30fps by writing both +0x45 and +0x4D.
Credits in the first post: "Original Codes By @Shay#4684 from Discord", "Less Crashes by @Hazerou",
"Game Speed Codes by @Reshiban".

### 1.6 CTRPF-only "delayed" variant (deleted user, 2021-08-20, post-9558787)
For each of the four candidates: when the pattern matches, a CTRPF data-register counter (`DF000002 00010000`,
`D4000000 00000001`, `DFFFFFFF 00000003`, `80000000 00000055` = "if counter > 0x55") delays the flip by ~0x55
cheat-engine runs before writing +0x45=0. Author: "It adds a delay to when the code kicks in ... likely only works
on CTRPF ... Luma does not have [data/storage registers] ... the risk of crashing does increase the lower you go
likely". (Exact text saved in `work/fps60/research/gbatemp_550527_bis_posts.txt`.)
HYPOTHESIS (likely): the authors' experience is that flipping the byte while a scene/task is still initialising is
what crashes; a delay or a manual press after the transition avoids most crashes. Consistent with "state latched at
init" (ENG to confirm).

## 2. Crash / bug reports with conditions (all found)

Verbatim copies of every BIS post of thread 550527 (49 posts) are in
`work/fps60/research/gbatemp_550527_bis_posts.txt` (post URL in each header).

| # | Date | Who / where | Code used | HW / emulator, versions | Scene / symptom | Source |
|---|---|---|---|---|---|---|
| R1 | 2020-02-12 | Sharkive issue #199 | **every** cheat for the title (not 60fps) | New 2DS XL, Luma 10.0.1, game "0.0.0" | immediate crash "Arm11 Data Abort, Translation-Section, **Remillio (00040000001d1400)**" (Remillio = the game's process name). Maintainer: "kernel bug. Luma's cheat engine would need to be redesigned" | https://github.com/FlagBrew/Sharkive/issues/199 |
| R2 | 2020-03-07 | MarioKartFan | original | (console, N3DS implied) | "works wonderfully at 60 FPS", "a revelation" | https://gbatemp.net/threads/60-fps-patches-cheat-codes-releases-and-discussion.550527/post-8968634 |
| R3 | 2020-08-24 | CraftyCamerupt | original | New 3DS XL | "sometimes, I get a error for something relating to translation" (= ARM "Translation fault" data abort, likely) | https://gbatemp.net/threads/60-fps-patches-cheat-codes-releases-and-discussion.550527/post-9178013 |
| R4 | 2020-08-24 | MarioKartFan | original | N3DS | "crashes are random and ... very infrequent" | .../post-9178093 |
| R5 | 2020-08-28 | CraftyCamerupt | original | **Citra** | 1–2 h, **no errors** | .../post-9181200 |
| R6 | 2020-10-06 | Luma3DS issue #1506 (DarthVitrial) | original (Hold-R) via **Luma built-in engine** | New 3DS XL, 11.13.0-45U, FastBoot3DS, Luma commit ebeef7ab (2020-07-30), N3DS CPU "Clock+L2", game patching on | "occasionally crashes with a system panic ... when I open the start menu or after a battle ends — basically when transitioning from a subscreen to the overworld. Happens after an hour or so". Error: **Arm11 core 1, Data Abort, Translation - Section, Current Process: Rosalina**. Follow-up: also "a number of crashes ... where the current process is Remillio (00040000001D1400)". Closed as tech support | https://github.com/LumaTeam/Luma3DS/issues/1506 |
| R7 | 2021-01-05 | BlazeHeatnix | original | console (Luma built-in engine; tried Luma 10.2.1 and the 3GX-loader edition, same result — R11) | "risks crashing during basically any scene transition, including pausing, saving, battle scenes, and giant battles". Workaround tried: hold R (30fps) when touching an enemy, before the results screen, at save blocks, at the muscle minigame; turn the code off before "Tilt screen vertically" in giant battles; then "scratch all of that ... holding R [doesn't] actually help" | https://gbatemp.net/threads/60-fps-patches-cheat-codes-releases-and-discussion.550527/post-9318368 |
| R8 | 2021-01-06 | MarioKartFan | original | console | "one crash in BIS in like ten hours ... during a giant bowser scene" | .../post-9320065 |
| R9 | 2021-01-07 | BlazeHeatnix | original | console | in "the patch showcase video, other people are reporting multiple crashes ... battle and menu transitions"; inconsistent: a long span without crashes, next day two in a row without a giant battle | .../post-9320180 |
| R10 | 2021-01-07 | CraftyCamerupt + BlazeHeatnix | **FIX** and original | console ("The previous code mainly worked wonders on citra, but not the hardware") | new game: crash "a little bit after the first Mibus fight in which you have to lose ... after I was fighting my third Chubby Goomba"; BlazeHeatnix: "Same thing happened to me, at the same location ... with the original code" | .../post-9320775, .../post-9320873, .../post-9320885 |
| R11 | 2021-01-07 | Hazerou | none / 60fps | N3DS XL 11.6.0-39U, **Luma 9.0 plugin-loader build + CTRPF plugin** | "crashes on Giant Battles using **or without using** the 60 FPS cheat ... The game won't crash if I don't use the CTRPF Plugin" (photo attached) | .../post-9321249 |
| R12 | 2021-01-07 | BlazeHeatnix | original | Luma 10.2.1 and "3GX Loader Edition", built-in engine, no plugins | same crashes on both | .../post-9321259 |
| R13 | 2021-01-11 | BlazeHeatnix | **Less Crashes** | console | 30 by default, press L+R after every new menu/overworld/battle/cutscene; "you can enjoy the game without having to worry about crashes for the most part. It even works with giant battles. The only exception is the **credits. If you don't toggle 30 before the credits, it will crash without fail.**" | .../post-9325512 |
| R14 | 2021-01-11 | Hazerou | — | — | "We did our best but we still can't find what's causing the crashes..." | .../post-9325144 |
| R15 | 2021-08-20 | deleted user | delayed (CTRPF) | CTRPF | crash risk believed to rise if the flip happens sooner after the pattern appears | .../post-9558787 |
| R16 | 2021-12-10 | cloudlinkin | "these codes" (game not named) | N3DS XL, latest Luma | "Arm11 (core 0), data abort, Translation - Page" (not attributable to BIS) | .../post-9686529 |
| R17 | 2023-03-07 | NanashiFinal13 | — | CTRPF | auto-enabling a cheat at boot "can crash the console" for some games | .../post-10093736 |
| R18 | 2024-06-29 | DewottMaster | original | — | "when I enter/leave a battle or open the menu the game goes back to 30fps and I need to activate the code again" (expected for one-shot use; the code must stay enabled) | .../post-10448252 |
| R19 | 2024-11-10 | ChronoCrossfangirl2002 (shown as "Crystal_tofu" in quotes), GBAtemp thread 663091 | 60fps code | N3DS (overclock thread) | "**the 60fps code breaks action command inputs**, and I think it crashes the game occasionally" | https://gbatemp.net/threads/mario-luigi-bowsers-inside-story-3ds-overclock.663091/post-10538885 |
| R20 | 2025-05-28/30 | NiteDumper / moomeow96 | EUR, all variants | — | "all the cheat codes ... work EXCEPT for the ones that crash the game less often" (Less Crashes reported not working on EUR); reply "Typically, there's no crashes. Just don't fight Dark Star X unless you're extremely overleveled..." (joke about difficulty, not a crash); NiteDumper: "I hit one crash when I started a battle in dimble wood" | .../post-10660899, .../post-10660933, .../post-10662685 |

Thread 663091 (2024) also confirms New-3DS overclocking alone does **not** raise the game above 30 (Joom: "I doubt that it
does. Otherwise, this 60 FPS cheat wouldn't really need to exist"; recommends the CTRPF blank plugin FPS counter,
https://github.com/PabloMK7/CTRPluginFramework-BlankTemplate/releases/) — opinion, not a measurement.
Thread 557566 (2020-02-05/06): before Shay's code nobody had found one
(https://gbatemp.net/threads/does-anyone-have-a-60fps-code-for-the-bowsers-inside-story-remake.557566/).
Action commands: R19 is the only explicit statement found in GBAtemp; no description of *which* commands break.

### 2.1 Pattern of the reports (facts → interpretation)
- Citra: no crashes reported in any session (R5, R10 "worked wonders on citra"). Hardware: crashes at
  transitions (menu ↔ field, battle end, battle start, save block, giant battle start) — R3, R6, R7, R9, R10.
- Two different crashing processes are reported on hardware: **Rosalina** (the cheat engine's own process) and
  **Remillio** (the game) — R6. R1 shows the game crashing with **any** Luma cheat, not just 60fps.
- With CTRPF (plugin, no debugger attach) giant battles crash **even without the 60fps cheat** (R11).
- With Less Crashes (flip only on L+R after the scene is up) crashes "for the most part" stop, giant battles work,
  but the **credits crash every time if 60 is active** (R13) — the only deterministic 60fps crash reported.
- INTERPRETATION (likely): most hardware "transition crashes" are the cheat-engine/kernel race of section 3, not
  60fps logic; the credits crash is a real 60fps (or 60fps-state-carried-into-credits) bug and is the best
  reproducible target for CRS/RT. Giant-battle crashes need separating from plugin side effects (R11).

## 3. Why the cheat crashes on hardware but not on Citra (source-backed mechanism)

- Luma3DS README, "Known issues": "**Cheat engine crashes with some applications** ... there is a race condition in
  Nintendo's `Kernel11` pertaining to attaching a new `KDebugThread` to a `KThread` on thread creation, and another
  thread null-dereferencing `thread->debugThread`. This causes the cheat engine to crashes games that create and
  destroy many threads all the time ... having a dedicated 'game plugin' is the only alternative until Kernel11 is
  reimplemented." https://github.com/LumaTeam/Luma3DS/blob/master/README.md (Known issues). Tracking issue
  https://github.com/LumaTeam/Luma3DS/issues/1787 (open; "one of the most common causes of random crashes,
  particularly with cheats"); diagnosis by TuxSH in https://github.com/LumaTeam/Luma3DS/issues/1272 (2019-06-30:
  "kernel bug (null deref) ... race condition ... between CreateThread/Run attaches the KThread to a KDebugThread
  [and] the thread runs").
- Luma cheat engine source (confirmed, master): Rosalina's `menuThreadMain` loop sleeps
  `svcSleepThread(50 * 1000 * 1000LL)` then calls `Cheat_ApplyCheats()` (menu.c lines ~372–378); each active cheat is
  applied by `Cheat_MapMemoryAndApplyCheat`: `svcOpenProcess` → **`svcDebugActiveProcess`** → drain debug events →
  run the code with `svcReadProcessMemory`/`svcWriteProcessMemory` (guarded by `svcQueryDebugProcessMemory` in
  `Cheat_IsValidAddress`) → close the debug handle. So the game is debugger-attached and detached **~20 times per
  second**. Sources: https://github.com/LumaTeam/Luma3DS/blob/master/sysmodules/rosalina/source/menu.c and
  https://github.com/LumaTeam/Luma3DS/blob/master/sysmodules/rosalina/source/menus/cheats.c . This design (debug
  attach + Read/WriteProcessMemory + address validation) has been in place since 2018-03-20 (commit 938cb6492f,
  "Switched from mapping target process memory to svcReadProcessMemory & svcWriteProcessMemory"); verified present in
  the 2020-07-30 build used in R6 (ebeef7ab).
- Consequences for our design (likely): (1) a game that creates threads during transitions (loader/streaming/
  CRO-load threads) will randomly crash while a Luma cheat is active — matching R1/R6/R7; a **code.ips patch has no
  debugger attach and avoids this class entirely**; (2) the cheat's flip lands up to ~50 ms (≈3 frames at 60 Hz)
  after a task was initialised at 30fps, i.e. the game always starts each scene at 30 and is switched mid-run — any
  state latched at init (ENG) is then inconsistent; (3) Citra/Azahar has no such kernel race, which is why emulator
  users saw no crashes. The credits crash (R13) is not explained by this and must be a game-side 60fps issue.


## 4. Luma3DS: game patching for an updated title, RO (CRO/CRR) checks — from source

Source: LumaTeam/Luma3DS master, `sysmodules/loader/source/{loader.c,patcher.c,bps_patcher.cpp,romfsredir.s}`
(https://github.com/LumaTeam/Luma3DS/tree/master/sysmodules/loader/source), read 2026-10-30.

### 4.1 Which folder (confirmed: source + measurement)
- `loader.c` `loadCode()`: `u64 titleId = exhi->aci.local_caps.title_id;` → `loadTitleCodeSection(..., titleId)` and
  `patchCode(..., titleId, ...)`; `GetProgramInfoImpl()` uses the same `aci.local_caps.title_id` for
  `loadTitleExheaderInfo(originalTitleId, ...)`. All game paths are `/luma/titles/<that id, 16 hex upper>/…`.
- Measured on our own files (read-only, `$KIROCREW_SCRATCH/web/cia_ids.py` on the two CIAs in the project root):
  update CIA content 0: NCCH partition/program id **0004000E001CA900**, NoCrypto, exheader SCI name `Remillio`,
  **ACI local_caps.title_id = 00040000001CA900**; base CIA: same title_id 00040000001CA900.
  ⇒ On real hardware with the v1.2 update installed, Luma reads **`/luma/titles/00040000001CA900/`** (base ID), and
  the code it patches is the **update's** (v1.2) code. Confirmed.
- File names in that folder (patcher.c): `code.bin` (decrypted+decompressed full code, replaces the loaded code),
  `exheader.bin` (decrypted exheader or exheader-info, size must be exactly sizeof(ExHeader_Info) or sizeof(ExHeader)),
  `code.bps`, `code.ips`, `code.ups`, `locale.txt`, `romfs/` (LayeredFS). Order in `patchCode()`:
  **BPS → IPS → UPS** (all three are applied if present), then locale, then LayeredFS hooks. Requires the Luma
  option "Enable game patching" (`CONFIG(PATCHGAMES)`). Wiki: https://github.com/LumaTeam/Luma3DS/wiki/Optional-features
- Patches are applied to the **decompressed** code (loadCode decompresses LZSS first, then calls patchCode), so IPS
  offsets = virtual address − 0x100000 (text, rodata, data contiguous, page-aligned as in our code.bin).
  IPS details (`applyCodeIpsPatch`): 24-bit offsets, RLE records supported, optional 3-byte truncate/extend size after
  `EOF`; writes beyond the current size are allowed up to the mapped size (`ipsGrowToFit`, max = text+ro+data pages
  from the exheader) — no checksum. BPS (`bps_patcher.cpp`) verifies source and target CRC32, so a BPS made against
  v1.2 refuses to apply to another version (safer for distribution).

### 4.2 !! LayeredFS writes into the end-of-.text padding (impact on our code cave) — confirmed from source
- `findLayeredFsPayloadOffset()`: `roundedTextSize = (textSize+4095)&~4095; if (roundedTextSize - textSize >=
  romfsRedirPatchSize) payloadOffset = textSize;` → the romfs-redirection payload (`romfsredir.s`, by delebile) is
  copied to the **first bytes after the end of .text**. Size of `romfsRedirPatch` counted from romfsredir.s:
  **0x114 bytes** (69 words; script `$KIROCREW_SCRATCH/web/redir_size.py`).
- The path string `"lf:" + "/luma/titles/<id>/romfs"` (39 bytes) goes to the end of .rodata if its padding ≥ 39
  (`pathOffset = roundedTextSize + roSize`), else end of .data, else over a function containing `E3A00B42`.
- Hooks: the first instruction of the game's `fsOpenFileDirectly` and `fsTryOpenFile` (found by byte patterns) is
  replaced by a branch into the payload.
- For 3DX v1.2 (text end 0x388BD8, 0x428 bytes padding; rodata 0x389000 + 0x65E50): Luma will write the payload at
  **0x388BD8–0x388CEB** and the path at **0x3EEE50–0x3EEE76** (derived; exact values depend on the exheader
  text/ro sizes, ENG/lead to confirm). This happens **after** IPS/BPS. ⇒ a code cave placed at 0x388BD8 would be
  overwritten on real hardware whenever the romfs folder exists (the Korean patch needs it), while working on Azahar
  (Azahar's LayeredFS is in the emulator, no payload). Recommendation: keep caves out of 0x388BD8–0x388CEF and
  0x3EEE50–0x3EEE77 (e.g. use 0x388D00–0x388FFF, ~0x300 bytes), and do not patch the game's FS open functions.

### 4.3 RO sysmodule: CRR signature and CRO/CRR hash checks disabled by Luma (confirmed)
- `patchCode()` (master): `else if(progId == 0x0004013000003702LL && progVer > 0) //RO` … comment "Disable CRR0
  signature (RSA2048 with SHA256) check (redundant) and CRO0/CRR0 SHA256 hash checks (section hashes, and hash table)";
  three pattern patches each replace a function start with `mov r0,#0; bx lr`. It is in the always-applied
  system-module chain (no `CONFIG(...)` gate; only `progVer > 0`).
  https://github.com/LumaTeam/Luma3DS/blob/master/sysmodules/loader/source/patcher.c
- History: commit afc6f51ff2 "Revised and working RO patch" (TuxSH, 2016-05-14; file then `injector/source/patcher.c`)
  https://github.com/LumaTeam/Luma3DS/commit/afc6f51ff207dcfad86b04df1390e8973e6e29e2 . Release check by fetching
  tagged sources: v5.4 (2016-04-30) has no RO patch; **v5.5 (2016-05-27) is the first release with it**; present in
  v6.0 and in today's master. ⇒ Any Luma3DS ≥ v5.5 loads LayeredFS-modified CROs without updating `static.crr`/
  `.crr` hashes. (Keeping the CRR hashes correct anyway costs nothing and protects against non-Luma setups.)

## 5. Azahar — from source (azahar-emu/azahar master 01623d2, 2026-10-29; key points re-checked on tag 2126.1.2)

The user's installed `C:\Program Files\Azahar\azahar.exe` is dated 2026-09-21 (no version resource) → most likely
release **2126.1.2** (published 2026-09-20). Releases: https://github.com/azahar-emu/azahar/releases

### 5.1 Mod folder for code patches with an installed update (confirmed)
- `src/core/file_sys/ncch_container.cpp`: `GetModId(program_id)`: if `(program_id & 0xFF00000000) == 0x0E00000000`
  ("Apply the mods to updates") return `program_id & ~0x0E00000000`. `src/core/loader/ncch.cpp`: the installed
  update NCCH (`(program_id & 0xFFFFFFFF) | 0x0004000e00000000`, from SDMC) becomes `overlay_ncch`; code is loaded
  from it and patched by `overlay_ncch->ApplyCodePatch(code)`.
  ⇒ update NCCH 0004000E001CA900 → mods folder **`<user>/load/mods/00040000001CA900/`** (same folder as the romfs).
- `ApplyCodePatch()` tries, in order, and applies **only the first file found**: `mods/<id>/exefs/code.ips`,
  `mods/<id>/exefs/code.bps`, `mods/<id>/code.ips`, `mods/<id>/code.bps`, `<sdmc>/luma/titles/<ncch program_id>/code.ips`
  (note: raw NCCH id here, i.e. `0004000E001CA900` for the update — differs from real Luma), `<rom>.exefsdir/code.ips|bps`.
  Use `load/mods/00040000001CA900/exefs/code.ips` (or `.bps`).
- Also supported: `mods/<id>/exefs/code.bin` (full replacement), `mods/<id>/exheader.bin` (marks the title "tainted";
  warns if jump ID ≠ program ID), `mods/<id>/romfs/` and `romfs_ext/` (LayeredFS, applied separately to base and
  update RomFS). https://github.com/azahar-emu/azahar/blob/master/src/core/file_sys/ncch_container.cpp
- Patches are applied to the decompressed code (LoadSectionExeFS decompresses LZSS before LoadExec patches).

### 5.2 CRO/CRR checks (confirmed: none)
- `src/core/hle/service/ldr_ro/ldr_ro.cpp`: `RO::LoadCRR` and `UnloadCRR` are stubs ("(STUBBED) called", return
  success). `src/core/hle/service/ldr_ro/cro_helper.cpp`: `CROHelper::VerifyHash(...) { // TODO(wwylele): actually
  verify the hash  return ResultSuccess; }`. Same in tag 2126.1.2. Azahar does verify CRO **structure** (segment/
  table offsets in order and inside the buffer, export tree, string tables) — a modified CRO must stay structurally
  valid. Only HLE RO; if a user enabled LLE for the RO module (`lle_modules` setting) the real checks would run.
  https://github.com/azahar-emu/azahar/blob/master/src/core/hle/service/ldr_ro/cro_helper.cpp

### 5.3 Cheats (confirmed)
- File: `<user>/cheats/<16-hex program id>.txt` (`UserPath::CheatsDir`, `CHEATS_DIR "cheats"`); the id is
  `AppLoader_NCCH::ReadProgramId` = **base** NCCH id → `cheats/00040000001CA900.txt`.
- Format (`gateway_cheat.cpp` `LoadFile`): `[Name]` starts a cheat; a line `*citra_enabled` marks it enabled; other
  lines starting with `*` are comments; every other non-empty line is a code line `XXXXXXXX YYYYYYYY`
  (Gateway/AR: 0–2 writes, 3–A conditionals, B, C/D0/D1/D2 loop/terminators, D3 offset, D4–DC data register ops, E
  patch, DD joker). Luma-style `{...}` notes are not comments here.
- Execution: `cheats.cpp` `run_interval_ticks = 50'000'000` with the comment "Luma3DS uses this interval"; but it is
  in emulated ARM11 ticks (`BASE_CLOCK_RATE_ARM11 = 268111856`), i.e. **~0.186 s** between runs (derived), vs ~50 ms on
  Luma. Cheats run on the core-timing thread (no debugger attach → no KDebugThread race).

### 5.4 GDB stub (confirmed, master)
- Settings `use_gdbstub` (default false) and `gdbstub_port` (default **24689**) in `src/common/settings.h`.
- `src/core/gdbstub/gdbstub.cpp`: listens on **INADDR_ANY** (all interfaces), one client. `qSupported` reply:
  `PacketSize=…;qXfer:features:read+;qXfer:osdata:read+;qXfer:threads:read+;vContSupported+`; target.xml served;
  commands `g G p P m M c C s S z Z T v(Cont) H ? ! D k F(HIO)`; Z0/Z1 execute, Z2 write, Z3 read, Z4 access
  watchpoints; `M` writes check `IsValidVirtualAddress` and clear the instruction cache; stop signal SIGTRAP (5).
  Packet handling was reworked in #2631 (2026-10-04, release 2126.2+); RT should test against the installed build.

### 5.5 UDP RPC server (scripting) — protocol (confirmed)
- Setting `enable_rpc_server` (default false). `src/core/rpc/udp_server.cpp`: UDP **port 45987**, bound to
  `udp::v4()` = **0.0.0.0 (all interfaces), no source filtering** → anyone on the LAN can read/write emulated memory
  while it is enabled; keep it on only in the test instance and behind the Windows firewall.
- Packet = 16-byte little-endian header `{u32 version, u32 id, u32 type, u32 data_size}` + data; the reply echoes
  version/id/type with `data_size` = reply length; an invalid request gets an empty reply. All requests carry two u32
  args at data+0/+4.
- **Installed 2126.1.2** (`packet.h` at tag 2126.1.2): `CURRENT_VERSION = 1`, `MAX_PACKET_DATA_SIZE = 1024`; types
  1 ReadMemory(addr,size≤1024) → bytes; 2 WriteMemory(addr,size,data…≤1016); 3 ProcessList(start,max) → u32 count +
  count×{u32 pid, u64 title_id, char name[8]} (packed 0x14); 4 SetGetProcess(op 0=get/1=set, pid) — memory requests
  then target that process (default 0xFFFFFFFF = current). Client: `dist/scripting/citra.py`
  (https://github.com/azahar-emu/azahar/blob/2126.1.2/dist/scripting/citra.py), default address 127.0.0.1.
- **2126.2 (2026-10-08) and 2127.0-alpha1..3**: `CURRENT_VERSION = 2`, max data 32 KiB, adds 5 TakeScreenshot,
  6 ReadScreenshot, **7 GetPerfStats** (reply `PerfStatsInfo`: f64 system_fps, **game_fps**, time_vblank_interval,
  time_hle_svc, time_hle_ipc, time_gpu, time_swap, time_remaining, emulation_speed, artic_transmitted, u32
  artic_events; arg1 0=last, 1=get-and-reset). Client renamed `dist/scripting/AzaharRPC.py`.
- **master only (after 2026-10-28, no release yet)**: 8 SetFreeCam, **9 SaveState / 10 LoadState** (arg1 = slot),
  **11 SetInput** (`InputInfo{u32 buttons (HID bits), u32 flags (Home/Power/Touch/CirclePad), u16 touch_x,y, s16
  circle_pad_x,y}`, held until the next SetInput). Server rejects packets whose version ≠ its CURRENT_VERSION, so the
  client must match the build. Memory access is asynchronous to emulation unless built with ENABLE_SCRIPTING_SYNC.
  https://github.com/azahar-emu/azahar/blob/master/src/core/rpc/packet.h ,
  https://github.com/azahar-emu/azahar/blob/master/src/core/rpc/rpc_server.cpp
- For RT (suggestion): upgrading only the *portable test copy* to 2126.2+ gives an fps counter over RPC
  (GetPerfStats.game_fps); master nightlies add savestates and input injection over RPC.

