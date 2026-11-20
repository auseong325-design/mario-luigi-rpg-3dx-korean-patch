# 60fps mode — WAVE 3 brief (field VM fix, fallback, test beds, runtime)

Read `work/fps60/BRIEF.md` §1–5, `work/fps60/BRIEF2.md` §0 (R1–R5) and §1 (D1–D6), then this file, then the reports
your section names. Same working rules as wave 2: report written **incrementally** (at least every ~25 tool calls,
table rows ≤ 40 per write), every Python command with a timeout, final reply 5–15 lines + report path.

## 0. State after wave 2 (all eight reports complete)

- Builds (`work/fps60/build/README.md`): `v1` = D1 init hook; `v1c` = + credits fix; `v1cb` = v1c code + BAI fix
  overlay (composed by the lead with `scripts/fps60/lead_compose.py`). The lead re-verified v1/v1c independently
  (`scripts/fps60/lead_check_build.py <tag>`: IPS == patched image, BPS CRCs, only declared bytes change).
- RT2 (`runtime/findings.md` §6, `HARNESS.md` §8): Azahar applies v1's `code.bps`; title, file select, field and
  pause menu are created at +0x3D = 0 / +0x41 = 1, 60 FPS at 100% speed, field step 1.0 from the first frame;
  unpatched, every new task (and the field re-init after a menu) comes back at +0x3D = 1. Tools: `rt_input.py`
  (keys to the test window without taking focus), `rt_census.py`, `rt_mods.py`. Slot 1 = late-game save (Dark
  Bowser's castle area, save block room); slot 2 empty. No enemy was reachable near the slot-1 save point.
- Battle (BTL2, `analysis/battle.md` §2.4–§11): C++ action-command timing is fps-correct. BAI fix staged at
  `work/fps60/build/bai/romfs/BAI/BAI.dat` (sha256 `c681a963…fbb6`), identical at 30fps.
- Credits (CRD, `credits/REPORT.md`): no rate-dependent crash path in code/scripts; fix = halve the scroll speed
  (in v1c); test bed A (save redirect) and B (FEvent warp) in `work/fps60/credits/testbed/`.
- Field (FLD, `analysis/field60.md`): field C++ is step-correct; field event scripts count frames (139 loops in
  96 scripts, incl. the Bowser-body minigames) and run 2× fast at 60.
- **Lead decisions:** field-script fix = FLD **Option A** (field VM keeps its 30 Hz schedule at 60fps) as primary,
  **Option B** (FEvent.dat `wait(1)`→`wait(2)` at the detected sites) as fallback; if neither passes runtime tests,
  `fld::System` leaves the allow-list. Keep 1DX key repeat 10/2 (no F6). Skip MOD2 K4/P1 and menu M1–M4. Skip CRD's
  P0/P4 fade-in tweak.

## 1. Workstreams

| ID | Topic | Owned paths | Output |
|---|---|---|---|
| IMPL3 | build v2: credits fix + field VM 30 Hz (FLD Option A, F1–F4) | `scripts/fps60/build_fps60.py`, `scripts/fps60/impl_*.py`, `work/fps60/build/v2/`, `work/fps60/build/v2n/` | `work/fps60/build/README.md` (new v2 sections) |
| FEV | Option B fallback: FEvent.dat rebuild tool + detected-site patch | `scripts/fps60/fev_*.py`, `work/fps60/build/fev/` | `work/fps60/build/fev/README.md` |
| TB | test beds: battles (incl. a BAI-fixed hold attack), Bowser-body minigame, Bowser Jr. battle | `scripts/fps60/tb_*.py`, `work/fps60/testbeds/` | `work/fps60/testbeds/README.md` |
| RT3 | runtime: credits R1–R4, Old-3DS check, transition soak, BAI load, RW latch read | `tools/azahar-test/`, `scripts/fps60/rt_*.py`, `work/fps60/runtime/` | `findings.md` §7 on |

### IMPL3
Start from IMPL's builder and README. Add `--field-vm30` implementing `field60.md` §6.1 / §7 F1–F4. Tag `v2` =
init hook + credits fix + field VM 30 Hz, plus a copy of the BAI fix at `work/fps60/build/v2/romfs/BAI/BAI.dat`
(assert the sha256). Tag `v2n` = the same without `--field-vm30` (for the runtime A/B comparison).
1. Re-verify in the code every FLD claim you rely on: both vtables (0x3E1784 `fld::EventSystem`, 0x3E303C
   `fld::ResidentEventSystem`) and the original targets of slots +0x20/+0x2C/+0x34; every other path that reaches
   those functions (other vtables, direct `bl`), and whether such a path would break the frame-parity scheme; that
   all callers of slot +0x20 ignore its return value; the one-shot init call from FUN_00305D3C (stack
   `ResidentEventSystem`) and a robust "this is on the stack" test; the pad struct `*(fld+0x1B00)` (+8 trg,
   +0xC rls), the touch struct `*(fld+0x1B08)+8`, `$703B/$703C` (FLD open question 2); how a wrapper reaches
   `fld::System` (`[[this+4]+0x130]` or `[0x3F49D0]`); the frame counter used for parity (where +0x578 is
   incremented relative to the event VM, so F2 and F3 agree on even/odd within one frame).
2. RW latch (16 bytes): prove the chosen bytes are mapped RW, zero at start and unused (exheader data/bss sizes and
   page rounding; scan static code/data and every CRO for literal words and movw/movt pairs pointing into the
   range; heap and stacks are elsewhere). If you cannot prove it, choose another location and give the evidence.
   RT3 reads 0x434D40–0x435000 at runtime (findings §7).
3. Wrappers: AAPCS (preserve r4–r11 and s16–s31, sp 8-aligned at every call), VFPv2 only (no `vmov` immediate),
   tail-call the originals with arguments intact (s0 for slot +0x34). With G false (+0x45 != 0) the behaviour must
   be the original bit for bit.
4. Unicorn tests: F1 (step × 2 only under G); F2 (odd frame: original not called, latch saved with the frame
   number; even frame: original called; stack `this` never gated); F3 (even frame with a fresh latch: the pad shows
   the OR'ed edges during the original call and is restored afterwards; a stale latch is ignored; odd frame or
   G false: untouched). Keep every existing IMPL check green (loaders, LayeredFS, relocations, CRCs). Report cave
   usage within 0x388E10–0x388FFF.
5. README: per-patch table (address, old/new bytes, disassembly), test results, hashes of `v2` and `v2n`.
Stop when `v2` and `v2n` pass every check.

### FEV
Implement FLD Option B as data in `scripts/fps60/fev_build.py`:
1. `identity`: decode `FEvent/FEvent.dat` (v1.2: `lib3dx.romfs_path('FEvent/FEvent.dat')`, BG4 + BLZ entries) and
   rebuild it with zero changes, byte-identical. Add helpers in your own files; do not change existing `lib3dx`
   behaviour.
2. `build`: apply exactly the sites of `python scripts/fps60/fld_fev.py waitsites` (136 sites in 90 entries; test
   rooms and the edge-reading loop of `i_areanone_puzzle_02_U` excluded), u16 1 → 2; re-compress only changed
   entries, every other entry byte-identical. Output `work/fps60/build/fev/romfs/FEvent/FEvent.dat`, `diff.tsv`,
   `manifest.json`.
3. `verify`: re-read the output, decode every entry, assert that only the listed u16 parameters differ and that the
   instruction layouts match; decompress every changed entry and compare with the expected plain bytes.
4. Answer FLD open question 4 for the changed entries: can the field game speed `[[sys+0x574]+0x7C]` or
   `sys+0x1A48` drop the field step below 2.0 at 30fps while those loops run (then `wait(2)` ≠ `wait(1)`)? Find the
   script commands and C++ writers that set them and whether any of the 90 entries use them.
Stop when `verify` passes.

### TB
Prepare test beds as files only (RT installs them; never touch `patch/` or the user's Azahar). Read CRD
`credits/REPORT.md` §1, §6, §7 (save-redirect method `scripts/fps60/crd_testbed.py`), FLD `field60.md` §2 and §4
(rule W2 below), BTL2 `battle.md` §7–§10, RT2 `runtime/findings.md` §6.
Goal: from loading a save to the scene under test in under a minute, for
- **T1** an ordinary field battle (any enemy): BAI.dat loads, battle step 1.0;
- **T2** a battle against an enemy that uses one of BTL2's fixed hold attacks (`atk_dstar_4`, `atk_dstar_x_4`,
  `atk_koopa2_2`, `atk_koopax_2`, `atk_dgeraco_5`): name the attack, how to make the enemy use it, and the inputs;
- **T3** one Bowser-body minigame from FLD §4.2 (prefer `i_power_hip_SA_adorena_01_L`), plus the rhythm minigame
  `i_power_arm_02` if cheap;
- **T4** (optional) a Bowser Jr.'s Journey battle with its timed captain command.
Use the least invasive method: a save-file redirect when the scene starts by itself in the target room, else an
FEvent.dat variant that starts the battle/minigame from a room script by reusing the game's own commands and
arguments exactly. Build FEvent variants on the **original** v1.2 FEvent.dat. Each test bed lives in
`work/fps60/testbeds/<id>/` with a `romfs/` overlay usable by `rt_mods.py use-build` (or a save file), a `verify`
step proving it differs from its source only where intended, and exact install/remove steps plus the expected first
screen. Stop when T1–T3 have verified files (T4 if reachable).

### RT3
Runtime with the existing builds; IMPL3, FEV and TB run in parallel and you do not need their outputs. Follow
`HARNESS.md` (launch only with `rt_launch.ps1`; keys with `rt_input.py`; `rt_mods.py` only with the emulator
stopped; no heavy RPC scans within ~10 s of a scene change). Append to `findings.md` from §7 on after each item.
1. **Credits** (`credits/REPORT.md` §7, runs R1–R4, test bed A): stock (`use-patch`), runtime flip, `v1` (no fix),
   `v1cb` (fix). Measure roll start → isFinish → room change, text end versus music end with the values CRD names,
   and any freeze or crash. Back up the test instance's save before and restore it after (never the user's).
2. **Old 3DS**: set `is_new_3ds=false` in the TEST config only (keep a backup), `use-build v1cb`: title and field
   must stay +0x3D = 1, +0x41 = 0, App 30 FPS. Restore `is_new_3ds=true` afterwards.
3. **Soak** with `v1cb`: at least 20 scene transitions (title → file select → field, field ↔ pause menu, field ↔
   save menu, room changes, mode select ↔ Bowser Jr.'s Journey) with no scans; record any freeze or crash with the
   last actions and the log tail.
4. **BAI load** with `v1cb`: reach any battle from slot 1 if you can (walk to an enemy; screenshots ≤ 1600 px);
   record btl::Main +0x3D/+0x41, `[0x3F3600]+0xBA15C` = 1.0 and that the battle runs. Give up after ~15 minutes
   (TB is building a battle test bed).
5. **RW latch region** for IMPL3: read 0x434D40–0x435000 at the title, in the field and in a menu (expect mapped
   and zero).
Finish with `use-patch` (junction, 36 files, MainMenu.cro sha256 checked), the test save restored, emulator stopped.

## 2. Rules added in wave 3
- W1. Build tags are folders under `work/fps60/build/`. Never overwrite a tag you do not own (`v1`, `v1c`, `v1cb`,
  `bai` are fixed). IMPL3 owns `v2`/`v2n`, FEV owns `fev/`, TB owns `work/fps60/testbeds/`.
- W2. `.fev` jump targets are **buffer-relative** (FLD `field60.md` §2, `fld_fev.py`); `crd_fevent.py` computes
  them as `sec + target`, which is wrong. Use FLD's decoder for control flow.
