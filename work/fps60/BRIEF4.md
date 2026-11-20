# 60fps mode — WAVE 4 brief (runtime decision A vs B, final checks)

Read `work/fps60/BRIEF.md` §1–5, `work/fps60/BRIEF2.md` §0–1, `work/fps60/BRIEF3.md` §0 and §2, then this file.
Same working rules as before: report written incrementally (at least every ~25 tool calls), every Python command
with a timeout, final reply 5–15 lines + report path.

## 0. State after wave 3

- Builds (`work/fps60/build/README.md` §10–§15, `work/fps60/build/fev/README.md`):
  - `v2` = **Option A**: D1 init hook + field VM at 30 Hz (F1–F4: vtable slots of `fld::EventSystem` 0x3E1784 and
    `fld::ResidentEventSystem` 0x3E303C, latch at 0x434F00) + BAI fix. No credits fix: the staff roll is updated
    only from the field VM, so under F2 it already runs 30×/s.
  - `v2n` = control: D1 + credits fix + BAI fix (code identical to `v1c`), no field-script fix.
  - `v2b` = **Option B**: `v2n` code + BAI fix + FEV's FEvent.dat (136 `wait(1)`→`wait(2)`).
- RT3 (`runtime/findings.md` §7): credits R1–R4 ran to the ending without a crash on Azahar; `v1cb` roll timing
  equals stock (205.8 s, music end +1.3 s); unfixed 60 = 102.9 s then ~102 s frozen last screen. Old-3DS `v1cb` =
  30 fps everywhere (+0x3D 1, +0x41 0). 37 scene transitions with `v1cb`, no freeze/crash. Latch region
  0x434D40–0x434FFF mapped and zero at title/field/menu. BAI.dat replacement seen in the log; no battle reached.
- **Save redirects into special rooms are unsafe**: the credits save redirect (test bed A) crashes at field start
  even on the stock game (findings §7.1, `readArcFile` on NULL). Credits runs use test bed B (FEvent warp).
- Test beds (`work/fps60/testbeds/README.md`, `scripts/fps60/tb_build.py install|remove <bed> --tag <TAG>
  [--variant nofix]`): T1 ordinary battle and T2 Dark Star hold attack are FEvent warps; T3 adrenaline minigame is a
  save redirect and may hit the §7.1 problem. TB2 (§2, in parallel) builds **T3b** (FEvent warp to the same
  minigame on the original FEvent.dat) and **T3c** (same warp on FEV's FEvent.dat, for `v2b`); use them only when
  `tb_warp.py verify` reports them OK at the time you reach item 3. Do items 1–2 first.

## 1. RT4 (the only worker of this wave that runs the emulator)

Follow `runtime/HARNESS.md` §1–§9. Append to `runtime/findings.md` from §8 on after each item. For every item record
build tag, test bed, scene, measured value, expected value and PASS/FAIL. Restore the test save before installing a
different test bed (`tb_build.py remove`), and switch builds only with the emulator stopped.
1. **T1 battle, `v2`**: BAI.dat replaced (log); btl::Main +0x3D 0 / +0x41 1; `[0x3F3600]+0xBA15C` = 1.0; one Mario
   and one Luigi jump attack with their timed button (action command) succeed; the battle ends and the field resumes
   at +0x3D 0. Repeat the action-command part with `v2n` if cheap.
2. **T2 hold attack**: with `v2` (BAI fix), then with the `nofix` variant: hold A+B, release about 200 ms, hold again
   (use the input string TB documents). Expected: fix keeps hanging on, nofix falls off. Also the orbit lap time
   (≈ 1.62 s fix, ≈ 0.81 s nofix).
3. **T3 minigame** with `v2` (A), `v2b` (B) and `v2n` (control): time for the cursor to reach the edge (expected
   1.1 s for A and B, 0.55 s for v2n), shot interval with A held (333 ms vs 167 ms), fade (6 s vs 3 s). If the save
   redirect crashes or misbehaves, stop it, restore the save, and use T3b (`v2`, `v2n`) / T3c (`v2b`) via
   `tb_warp.py` if it verifies OK; otherwise record the gap and move on.
4. **Credits** (test bed B) with `v2` only: roll start → isFinish ≈ 205.8 s and music-end alignment as stock, then
   the ending rooms. (`v2b` needs no run: its code is `v1c`'s, FEV changed no staff-roll script, and RT3 measured
   `v1cb` = stock timing.)
5. **Input under A** (`v2`): in a script that waits for a button trigger (FLD `field60.md` §4.4; list candidates
   with `scripts/fps60/fld_fev.py`; the minigame's start prompt or any reachable script prompt), send at least 20
   single taps with the shortest hold `rt_input.py` can produce (16–20 ms) and count how many register; compare
   with `v2n`. Every tap must register under `v2`.
6. **Old 3DS** (TEST config `is_new_3ds=false`, backup and restore): `v2` title/field/minigame at 30 fps, +0x3D 1,
   minigame timings equal to the 30fps reference.
7. **Soak with `v2`**: at least 25 transitions including battle enter/exit (T1), the minigame (T3/T3b), pause and
   save menus and room changes; no freeze or crash.
8. **`v2b` extras** (FEV README §7 checks 1, 5, 6): FEvent.dat replacement line in the log, normal field play and
   room changes, the fast-forward note.
Finish with `use-patch` verified (junction, 36 files, MainMenu.cro sha256), the test save and TEST config restored,
the emulator stopped. Final reply: a PASS/FAIL table for A (`v2`) and B (`v2b`) and your recommendation.


## 2. TB2 (files only, runs in parallel with RT4)

Owned: a NEW script `scripts/fps60/tb_warp.py` (build / verify / install / remove for T3b and T3c) and new folders
`work/fps60/testbeds/t3b_minigame_warp/`, `work/fps60/testbeds/t3c_minigame_warp_fev/`. **Do not edit
`scripts/fps60/tb_build.py` or the existing test-bed folders**: RT4 runs them while you work. Read `testbeds/README.md`,
`runtime/findings.md` §7.1 (why a save redirect into a special room crashes), CRD `credits/REPORT.md` §6 (variant B:
FEvent room warp from the saved rooms) and FLD `field60.md` §2/§4 (use FLD's decoder for jump targets).
1. **T3b**: an FEvent.dat variant built on the original v1.2 FEvent.dat that takes the player from the slot-1 save
   rooms into the adrenaline minigame `i_power_hip_SA_adorena_01_L` the way the game does (the game's own room-change
   / minigame-start commands, the flags the minigame needs; find the story entry and copy it), so the minigame starts
   by itself within a minute of loading slot 1. No save edit.
2. **T3c**: the same warp applied on FEV's `work/fps60/build/fev/romfs/FEvent/FEvent.dat` (for `v2b`).
3. **Trigger prompt**: find one field script that waits for a button trigger edge (`$7038`, FLD §4.4) reachable in
   T3b/T3c or near the slot-1 save point, and document how RT4 exercises it and what one registered tap looks like.
4. `tb_warp.py verify` for T3b/T3c (differs from its source only where intended; FEV's 136 sites intact in T3c),
   `install`/`remove` with the same safety checks as `tb_build.py` (emulator stopped, only inside
   `tools/azahar-test/mods_builds/<TAG>/`), and a section appended to `testbeds/README.md` (append only) with install
   steps and the expected first screen.
Stop when T3b and T3c verify OK.
