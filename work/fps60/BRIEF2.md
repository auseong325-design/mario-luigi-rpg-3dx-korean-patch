# 60fps mode — WAVE 2 brief (design + implementation + audits)

Read `work/fps60/BRIEF.md` sections 1–5 first (rules, tools, conventions still apply), then this file, then the
wave-1 reports your section names. Wave-1 reports: `work/fps60/research/web.md`, `work/fps60/analysis/{engine,
1dx_compare,battle,crash,hugebattle,modes}.md`, `work/fps60/runtime/findings.md` (+ `HARNESS.md` when present).
Ghidra is READY for both games (`work/fps60/TOOLS_STATUS.md`): grep `work/fps60/decomp/<game>/*.c` first, use
`python scripts/fps60/ghidra/decomp.py <game> <addr|name> [--xrefs] [--asm]` for fresh output.

Your tool-call budget is large but finite: write your report **incrementally** (at least every ~25 tool calls) so
a cut-off run still leaves a complete-so-far file. Final chat reply: 5–15 lines + report path.

## 0. Facts added by the lead after wave 1 (2026-10-30 14:10) — read before your section

R1. **Runtime-confirmed lever** (`work/fps60/runtime/findings.md` §1–§3, Azahar test instance, title screen):
    the current task `[0x3F40B4]` is already `fld::System` 0x320DA370 (vptr 0x3E3B3C) at the title screen.
    Writing **+0x3D = 0** makes +0x45 follow, the task's frame counter +0x578 goes 29.5 → 59.9/s and the emulator
    shows `App: 60 FPS` at 100% speed; writing +0x45 alone is undone from +0x3D within 1 s; restoring +0x3D = 1
    returns to 30/s; no crash. The community cheat address 0x320DA3AC is fld::System+0x3C in JP v1.2 too.
    New 3DS bytes at runtime: `[0x3F716C]` (IsRunOnSnake cache) = 1, APPMEMTYPE `[0x1FF80030]` = 6.
R2. **The Korean patch already edits CRO/CRR.** `patch/00040000001CA900/romfs/RO/MainMenu.cro` (furigana option
    hidden, 2026-10-07) and `patch/00040000001CA900/romfs/.crr/static.crr` (MainMenu hash replaced) differ from the
    game's files. Any fps60 edit of MainMenu must start from the patch's MainMenu.cro; any CRR you build must start
    from the patch's static.crr and replace only the hashes of the modules you change (procedure:
    `work/review/followup_20261007/build_furigana.py`). For every other romfs file: start from
    `patch/00040000001CA900/romfs/<path>` when it exists, else from `lib3dx.romfs_path(<path>)`. Read-only for you.
R3. **The shipped staff roll is Korean.** `patch/00040000001CA900/romfs/Staffroll/` (2 files) replaces the
    Japanese credits. `crash.md` simulated the text/line buffers with the Japanese data only: redo any length or
    buffer reasoning with the Korean files (CRD, AUD).
R4. **Only RT2 runs the emulator** (portable instance `tools/azahar-test/`, `HARNESS.md`). Every other worker
    prepares files and writes what RT2 should run in its report.
R5. **Never recursive-delete a junction or a folder that contains one.** `tools/azahar-test/user/load/mods/
    00040000001CA900` is a junction to `patch/00040000001CA900`; Windows PowerShell 5.1 `Remove-Item -Recurse`
    follows junctions and would delete the Korean patch. Remove or rename links with `cmd /c rmdir "<link>"` (no
    `/s`) or Python `os.rmdir` / `os.rename`, and assert "not a reparse point and under tools/azahar-test" before
    any recursive delete.

## 1. Decisions taken by the lead (do not re-litigate; flag evidence against them in your report)

D1. **Mechanism = native fps mode, decided at task init, New 3DS only.** Hook `ad::fw::TaskBase::init` at
    0x28092C (`ldrb r0,[r4,#0x3d]` → `bl cave`), as designed in `engine.md` §9: if the task's persistent fps byte
    +0x3D is 1, its vptr (at init time) is in the allow-list, and `nn::os::CTR::IsRunOnSnake()` (0x2844AC) returns
    1, set +0x3D = 0 and the marker +0x41 = 1. Allow-list v1: `fld::System` 0x3E3B3C, `btl::Main` 0x3E10C4,
    `kj::KJSystem` 0x3DEBD8, `msys::MTaskBase` 0x3E4874 (all 8 menu-type CRO tasks). Boot is already 60.
    `hb::HugeBattleSystem` is excluded (it ignores the byte and already paces itself ≤60 with a real-time step).
    This is how 1DX works (1DX creates every gameplay task at mode 0).
D2. **Code cave placement:** NOT at 0x388BD8–0x388CEF. Luma3DS copies its LayeredFS redirection payload
    (0x114 bytes) to the first bytes after .text (0x388BD8) *after* applying IPS/BPS, and the Korean patch needs
    LayeredFS. Use 0x388E00–0x388FFF (keep ≥0x110 bytes of margin above the payload). Also avoid the end of
    .rodata 0x3EEE50–0x3EEE77 (Luma's path string).
D3. **Fixed step, like 1DX:** at 60fps a frame that overruns 16.7 ms slows the game down (engine behaviour, also
    1DX). No adaptive/variable step in v1. (An adaptive isFps30 is a possible v2; AUD collects the evidence.)
D4. **Delivery:** one code patch file for both loaders plus LayeredFS. Real hardware: Luma3DS ≥ v5.5 with game
    patching on, `/luma/titles/00040000001CA900/` (base title ID even with the v1.2 update). Azahar:
    `load/mods/00040000001CA900/` (same folder as `romfs/`). Prefer `code.bps` if both loaders verify the source
    CRC and fail safely on a mismatch (v1.0 installed); otherwise `code.ips`. IMPL decides from source evidence.
D5. CRO edits are allowed when needed (Luma ≥ 5.5 and Azahar skip CRO/CRR hashes), but keep `.crr/static.crr`
    hashes correct anyway. Prefer static-code (code patch) fixes over CRO edits when equivalent.
D6. Nothing is written into `patch/` by workers. Builds go to `work/fps60/build/`; the lead installs.

## 2. Workstreams (wave 2)

| ID | Topic | Owned paths | Output |
|---|---|---|---|
| IMPL | patch builder + verification | `scripts/fps60/build_fps60.py`, `scripts/fps60/impl_*.py`, `work/fps60/build/` | `work/fps60/build/README.md`, build artefacts |
| CRD | credits (staff roll) at 60fps: event script, fix, test bed | `scripts/fps60/crd_*.py`, `work/fps60/credits/` | `work/fps60/credits/REPORT.md` |
| AUD | every fps-mode reader classified (static + all CROs) | `scripts/fps60/aud_*.py`, `work/fps60/analysis/audit_fps_sites.md` | that report |
| FLD | field + field minigames + events/camera: 30fps-only assumptions | `scripts/fps60/fld_*.py`, `work/fps60/analysis/field60.md` | that report |
| MOD2 | finish `modes.md`: Bowser Jr.'s Journey (KJRPG/KJMenu/kj::), Colosseum, BCat, AttackMiniGame, menus | `scripts/fps60/mod_*.py`, `work/fps60/analysis/modes.md` (append) | `modes.md` |
| BTL2 | finish `battle.md` + BAI fix for 30fps-hard-coded scripts | `scripts/fps60/btl_*.py`, `work/fps60/analysis/battle.md` (append), `work/fps60/build/bai/` | `battle.md`, patched BAI staging |
| D1X2 | finish `1dx_compare.md`: all 1DX isFps30 sites vs 3DX counterparts | `scripts/fps60/d1x_*.py`, `work/fps60/analysis/1dx_compare.md` (append) | `1dx_compare.md` |
| RT2 | runtime: per-scene task census, mode-0 logic speed, scene-change behaviour, test-mods switcher | `tools/azahar-test/`, `scripts/fps60/rt_*.py`, `work/fps60/runtime/` | `findings.md` (§6 on), `HARNESS.md` |

### IMPL
Build `scripts/fps60/build_fps60.py` (keystone assembly, capstone round-trip) that:
1. Loads `work/fps60/bin/3dx_v12.code.bin` (decompressed v1.2, 0x2F9000 bytes) and checks every original byte it
   replaces (abort on mismatch) and that cave bytes are zero.
2. Applies the D1 init hook with the cave at D2's range. Start from `scripts/fps60/eng_patch.py` / `engine.md` §9
   (verify every register-liveness claim yourself at 0x28092C–0x280940; r1 must survive; AAPCS stack alignment).
3. Optional patches behind flags, default OFF unless the lead says otherwise: `--credits-fix` (see CRD; implement
   the static variant now: in the field event handler 0x2E8B24 sub-op 0, after `fld::StaffrollCtrl::init`, if the
   `fld::System` passed to init has +0x45 == 0 then `ctrl+0x28 *= 0.5` (scroll speed in px per update; `isFinish`
   = frame*speed > total, so the roll's wall-clock duration becomes the 30fps one when update runs once per frame)),
   `--allow <class,...>` to change the allow-list.
4. Writes `code.ips` and `code.bps` (+ a `patched.code.bin` for analysis) into `work/fps60/build/<tag>/`, with a
   manifest (sha256 of input/outputs, list of patches, flags).
5. Verifies the outputs with your own re-implementations of **both** appliers, written from their source code:
   Luma3DS `sysmodules/loader/source/patcher.c` (IPS) + `bps_patcher.cpp` (BPS), Azahar
   `src/core/file_sys/ncch_container.cpp` / `src/core/file_sys/patch.cpp` (or wherever its IPS/BPS lives). Read
   what each does on a CRC mismatch / short file (does Luma `svcBreak`?). Then decide D4 and say why.
6. Unit-tests the cave logic in an ARM emulator (`pip install unicorn` into `.venv` is allowed): map the patched
   image at 0x100000, stub `IsRunOnSnake` (return 0/1), fake TaskBase objects for each allowed/not-allowed vptr and
   +0x3D ∈ {0,1}, run `TaskBase::init`'s tail from the hook site (or call the cave directly with the right register
   state) and check +0x3D/+0x41/r0/r1/sp afterwards. Same for `--credits-fix`.
7. Checks the cave against Luma's payload region (D2) and documents the free space left.
Output `work/fps60/build/README.md`: how to build, what each patch does (address, old/new bytes, disassembly),
loader verification results, test results. Stop when a default build (`--tag v1`) passes all checks.

### CRD
The 3DX credits are `fld::StaffrollCtrl` (Field.cro) driven by field event command 0x280 (handler 0x2E8B24:
sub-op 0 create+init, 1 update, 2 `!isFinish` into a register, 3 delete). `update()` advances `frame` by 1 per
call; `isFinish` = frame × speed(+0x28 = 2.0) > total. Community: with 60fps active the credits crash
"without fail"; at 30 they do not. Tasks:
1. Find the field event script(s) that use command 0x280 (`romf2/` or `romfs/` `FEvent/`; find how field scripts
   are stored and decode the VM: base ops 0x00–0x4D are the same AlphaDream VM as battle AI scripts — see
   `scripts/fps60/btl_bai.py`; field command table `GlobalEvent::_CmdFuncTbl` at 0x3A30C4, 567 entries; find the
   argument-descriptor table the field VM uses). Decode the whole ending sequence around it: the update loop
   (does it `wait(1)` or `wait(2)` between updates? wait is in 60 Hz units and decremented by the event step),
   BGM/stream commands (`04_end_roll` 214 s non-looping, `05` THE END), what runs after `isFinish`, saves,
   scene changes. Conclude how many `update()` calls per second happen at 30 and at 60fps.
2. From that, find the most likely deterministic crash mechanism at 60fps and the minimal fix (validate or
   correct the IMPL `--credits-fix` design). Read `crash.md` §1 and `1dx_compare.md` §2 first.
3. Build a **test bed** that reaches the credits quickly in the portable Azahar instance (RT owns the emulator;
   you only prepare files): e.g. a test-only LayeredFS `FEvent` replacement in `work/fps60/credits/testbed/`
   that starts the real ending sequence (or the 0x280 loop with the right BGM) from an early, reachable point
   (new game first room, or the room of the user's saves: `ML3R_001/002.sav` in `tools/azahar-test/` user data —
   find the saved room/progress). Document exactly how RT installs/removes it. Never touch `patch/`.

### AUD
Classify **every** reader of the fps mode in 3DX v1.2: the 14 static `isFps30` call sites, the inline readers of
TaskBase+0x45 (e.g. Boot funcCalc 0x3226D8, `isStoreCmdList` 0x342810), every CRO call through the isFps30 veneer
(AttackMiniGame 1, BCat 1, Battle 2, Colosseum 11, KJMenu 38, LoadMenu 13, MainMenu 24, SaveMenu 1, ShopMenu 17),
and any direct read of +0x3D/+0x45 on a task in CROs. For each: function, what the result controls, category
(a) per-frame step multiplier 2.0/1.0, (b) value latched at creation/once, (c) frame skipping / every-other-frame
logic, (d) other. Note any site whose 60fps branch looks wrong or untested. Then answer: is a v2 adaptive
isFps30 (return 1 for a frame that followed an overrun) safe for every site? List the exceptions (by return
address) that would need to be excluded. Output `work/fps60/analysis/audit_fps_sites.md` with a full table.

### FLD
Field mode at 60fps beyond the step plumbing already found (`modes.md` §2): look for 30fps-only assumptions in
field code that do **not** use the field step: per-frame integer counters compared with constants (timers,
durations, cooldowns, input windows), animation/camera code advancing fixed amounts per call, field minigames
and timed field actions (Bowser body minigames, timed jumps/hammers in the field, block puzzles, chase/escape
sequences, timed events), field-side `MessageSys`, `fld::MainMiniMap`, effects. Prioritise what the player
notices (speed, input timing). Use the decomp; `scripts/fps60/mod_hardstep.py` (MOD) may help. For each hit:
location, why it is frame-based, consequence at 60fps, proposed fix (static patch preferred).
Output `work/fps60/analysis/field60.md`.

### MOD2
Continue `work/fps60/analysis/modes.md` (read it first; it stops after §2.4 because the previous worker ran out of
tool calls). Complete: Bowser Jr.'s Journey (`kj::KJSystem` step +0x61C58 and getters 0x345260/0x3467D0; KJRPG.cro
has no isFps30 calls — how does its real-time army battle advance: through the KJ step or fixed per-frame
amounts? input windows/cooldowns/timers there), KJMenu, Colosseum (amiibo/challenge battles), BCat, AttackMiniGame,
the remaining menu CROs (consistency of their isFps30 use), and any mode not yet covered. Same hit format as FLD,
then a final table "mode → ready at 60 / needs fix (patch point) / unknown (runtime test)".

### BTL2
Continue `work/fps60/analysis/battle.md` (read it first; it stops after §2.3). Complete: Bowser's attacks and
Bowser special moves, Bros. attacks/Brawl attacks with multi-stage timing, enemy-attack dodges/counters
(hammer/jump counters, Bowser guard/punch counters), badge gauge, special-attack gauges, `btl::ObjTimer`,
battle-start/end transitions, Bowser Jr.'s Journey battles if they use btl:: code. Then implement the BAI fix:
the scripts that hard-code a per-frame `+= 2` instead of the step (`atk_dstar_4`, `atk_dstar_x_4`,
`atk_koopa2_2`, `atk_koopax_2`, `atk_dgeraco_5`, plus any others you find) must behave identically in milliseconds
at 30 and 60fps, and byte-identically in behaviour at 30fps (e.g. replace the immediate 2 by the step variable
`$7012` if the encoding allows the same length; otherwise another exact transform). Find where BAI.dat lives
(`romf2` overrides `romfs`), write a rebuild tool, rebuild with zero changes first (byte-identical), then the
fixed file into `work/fps60/build/bai/` with a diff list. Never write into `patch/`.

### D1X2
Continue `work/fps60/analysis/1dx_compare.md` (read it first; §0–§2 are done). Map **all 44–47 1DX isFps30 call
sites** (`decomp.py 1dx_kr ad::fw::TaskBase::isFps30 --xrefs`) to their subsystem and to the corresponding 3DX
code (shared symbol names, strings, structure). The 1DX listing names sites near `ad::pctx` (particles),
`Message`, `Prim`, `fld::FldMdl`, `ad::fw::Resource`, `btl`, and many in an unnamed region after `SndSys::init`.
For each: does 3DX have the same fps branch? If 3DX lacks it, does 3DX get the step another way (argument,
caller's step) or is it a real 60fps bug in 3DX (e.g. particles/effects/text/camera running 2× fast)? This is the
"compare with the 1DX engine" deliverable for the user. Final table + concrete 3DX patch points for every real gap.


### RT2
You own the portable Azahar instance `tools/azahar-test/` and the only running emulator. Read
`work/fps60/runtime/HARNESS.md` and `findings.md` first and follow HARNESS exactly (launch only with
`rt_launch.ps1`, never redirect or wait on the emulator, clients via Start-Process + WaitForExit ≤ 120 s).
Append results to `findings.md` from §6 on, after each scene.
1. **Census.** `rt_gdb.py map --out work\fps60\runtime\memmap.json` once, then for each scene: current task
   `[0x3F40B4]` (class, vptr, +0x3C..+0x48) and every live TaskBase (`rt_rpc.py tasks`) with class and
   +0x3D/+0x41/+0x45. Scenes in this order, as far as you can reach them: title, mode select, file select, field
   (load a copied save; record which save is where and its progress), field pause menu, a field battle, a Bowser
   section, Bowser Jr.'s Journey (mode select → new file), any reachable menu CRO scene (shop, save).
2. **Mode-0 behaviour per scene.** Flip the current task's +0x3D to 0 (`rt_measure.py setfps 0 --offset 0x3D`),
   record `App: N FPS`, the frame-counter rate and whether game logic keeps its wall-clock speed. Measure at least
   one logic quantity at mode 1 and at mode 0, e.g. the play-time counter (find it in the task or save buffer: if it
   runs 2× at mode 0, report it), a field timer, or the distance Mario walks in a fixed key hold. Note anything
   visibly or audibly wrong (text, camera, effects, music) with the scene.
3. **Scene changes.** With +0x3D = 0, change scene (field ↔ menu, field → battle → field, room change, file
   select → field): does the new scene's current task come back with +0x3D = 1? Which transitions re-create the
   main task? (This is why the patch decides at TaskBase::init.)
4. **Test-mods switcher** `scripts/fps60/rt_mods.py` for wave 3: `status`, `use-patch` (the current junction to
   `patch/00040000001CA900`), `use-build <tag>` (a real folder under `tools/azahar-test/` holding a COPY of
   `patch/00040000001CA900/romfs`, the build's romfs overlay files from `work/fps60/build/<tag>/romfs/` if any, and
   `exefs/code.ips` or `code.bps` from `work/fps60/build/<tag>/`). Follow R5 to the letter. After `use-patch`,
   assert the junction target, `patch/00040000001CA900` file count (36) and the sha256 of
   `patch/00040000001CA900/romfs/RO/MainMenu.cro` are unchanged. Smoke-test once with a tag `smoke` that has no
   code patch: boot to the title, find the LayeredFS line in the instance log, switch back, re-verify.
**Input.** Drive the game with `computer_press_key` / `computer_click` on the TEST window only: before each burst
check that exactly one azahar.exe runs and that its PID is the one in `tools/azahar-test/rt_azahar.pid`; if the
user's own Azahar is running, send no keys and wait. On Windows a keystroke takes the user's keyboard focus: keep
bursts short (≤ ~10 keys) and do not hold keys for long. Keyboard map: HARNESS §1. Any screenshot you view must be
≤ 1600 px per side. Never change the user's Azahar folders.
Stop when 1–3 are recorded for every scene you can reach and the switcher smoke test passes; stop the emulator
(`rt_launch.ps1 -Stop`) before your final reply.
