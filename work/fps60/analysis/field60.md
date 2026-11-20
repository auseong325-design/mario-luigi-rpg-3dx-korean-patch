# FLD — field mode at 60fps: 30fps-only assumptions (3DX JP v1.2)

Worker FLD (wave 2), 2026-10-30. Target `3dx_v12` static code + Field.cro. Static addresses are runtime
addresses (code.bin file offset = address − 0x100000); CRO addresses are analysis addresses (BRIEF §3).
Sources: Ghidra C dumps `work/fps60/decomp/3dx_v12/*.c`, listings `work/fps60/dis/3dx_v12/*.s`, `armdis.py`.
Tools written for this report (read-only): `scripts/fps60/fld_dc.py` (dump reader: show/callees/tree/grep/
callers by function), more listed in §2.
Confidence: **confirmed** (read in code), **likely**, **guess**.

> Status: complete (2026-10-30). Runtime items are in §8.

## 0. Summary

- The field **C++** code is step-correct at 60fps: player actions, jump physics, camera follow, field timer,
  message windows, effects and event `wait()` all scale by the field step (§1, §3, §5.2). No static patch needed.
- The field **event scripts** are not: the field VM has no step variable, and **139 loops in 96 scripts** count
  frames with `wait(1)`. They include the Bowser-body **minigames** (cursor 6 px/frame, countdowns, meters, a beat
  clock), `.fme` room gimmicks/enemies and NPC timers. At 60fps all of them run **2× fast** (§4).
- Fix: **Option A** (recommended, §6.1) keeps the field VM on its 30 Hz schedule at 60fps — 3 vtable-slot
  wrappers on the two field event systems (event step ×2, execute on even frames only, latch button/touch edges of
  the skipped frame) + 16 bytes RW. **Option B** (§6.2) is a same-length data patch, `wait(1)`→`wait(2)` at 136
  sites in 90 scripts of FEvent.dat (byte-identical behaviour at 30fps).
- Key repeat (`gBtn` 10/2 frames) halves in ms at 60fps — global, optional F6 (§5.1).
- Decoder correction for CRD: field jump targets are .fev buffer offsets, not section-relative (§2).

## 1. Field timing plumbing (recap of `modes.md` §2 + new facts)

- Field master step `fld::System+0x1A4C` = `(isFps30 ? 2 : 1) × [[sys+0x574]+0x7C] × sys+0x1A48` (60 Hz units per
  frame; `modes.md` §2.1). It is fanned out every frame by the field update functions FUN_0020d228 /
  FUN_0020dcb0 / FUN_0020e02c (state-dependent variants called from the field state machine 0x307FB4..0x30A9D8):
  `MoveVBase::update(sys+0x1B24, step)` (screen-scroll mover), **party step** `PlayerParty(Main+0x9840/+0x9844)+0x100
  = step` (read by every `fld::PlayerPartyMario/Koopa::ActionState*` as `*(float*)(party+0x100)`), FUN_00210458 /
  FUN_00210258 / FUN_0020f5a8 / FUN_0020ee18 / FUN_0020ec9c (step passed in s0/s1), and the event systems below.
  **confirmed** (decomp of 0x20D228, 0x20DCB0, 0x20E02C).
- **Field event step (open item of `modes.md` §2.3) — answered, confirmed.** Script waits
  (`GlobalEvent::execLocalEvent` 0x25BFA0: `LocalEvent+0x28 -= GlobalEvent+0x14`) use the field step:
  - map events: `fld::MainBase::vfunc_0x14` 0x30FD90 calls `EventSystem(Main+0x14FC)->vfunc_0x34(step = sys+0x1A4C)`;
    `fld::EventSystem::vfunc_0x34` 0x2A8AF0 writes `GlobalEvent+0x14 = step` for both of its GlobalEvents.
  - resident (system) events: FUN_0020dcb0/FUN_0020e02c call `ResidentEventSystem(sys+0x1ACC)->vfunc_0x34(step)`;
    `fld::ResidentEventSystem::vfunc_0x34` 0x2D9914 writes `GlobalEvent+0x14 = step`.
  ```
  002a8af0 fld::EventSystem::vfunc_0x34(step s0, EventSystem* r0):
     for i in 0..1: ge = this->vt[0x10](this, tbl_3A0782[i]); ge+0x14 = step
  0030fd90 fld::MainBase::vfunc_0x14: (**(Main+0x14FC)->vt[0x34])(*(float*)(Main->sys(+0x130) + 0x1A4C))
  ```
  ⇒ `wait(n)` in a field event script lasts n/60 s at both fps modes (rounded up to whole frames). Field script
  timing is fine **as long as the script itself does not count frames** (see §4).

## 2. Method and coverage

1. **C++ field code (static + Field.cro).** Field set = every `fld::*` function, Field.cro, the 567 field event
   command handlers (`GlobalEvent::_CmdFuncTbl` 0x3A30C4; 192 handlers have no Ghidra function and were
   disassembled from their entry), the field updaters 0x20D228/0x20DCB0/0x20E02C, plus direct callees to depth 3
   minus library code: **2,986 functions + 192 handler entries = 3,178 scanned code ranges**.
   Ghidra treats `MoveVBase::stop(int)` 0x24F578 as non-returning and cuts the C dump of its 87 callers after the
   call (lead note), so `fld_asm.py` scans raw code up to the next function start; the rescan added 1 hit, a
   reference count. Functions cut that way were read with `armdis.py`.
   - `scripts/fps60/fld_asm.py scan` (capstone): member counters `ldr/add|sub #1..4/str` on the same address,
     member floats `vldr/vadd|vsub literal/vstr`, smoothing `vmla/vmls literal`, damping `vmul literal`.
   - `scripts/fps60/fld_scan.py scan` (same idea on the C dump) as a cross-check.
   - `scripts/fps60/mod_hardstep.py` (MOD) + `scripts/fps60/fld_hsck.py`: update primitives called with a
     constant step.
2. **Field event scripts (data).** `scripts/fps60/fld_fev.py` decodes every `.fev` and `.fme` of
   `FEvent/FEvent.dat` (romf2, 1,428 BG4 entries: 714 `.fev`, 714 `.fme` of which 140 are non-empty; `.fme` have
   the same layout) with the field argument-descriptor table 0x3A0874 (from CRD's `crd_fevent.py`), follows
   control flow, and reports loops that run once per frame (`wait(1)`) and advance a variable by a constant per
   iteration (`fld_fev.py timers [--broad] [--body]`).
   **Correction for CRD's decoder (confirmed):** field jump targets (`jmpif` param 4, `jump` param 1) are
   **offsets from the start of the .fev buffer**, not from the script section S. Measured over all scripts
   (`fld_fev.py tbase`): buffer-relative 280,915 of 280,916 targets land on decoded instruction boundaries and
   1,162,910 instructions decode; S-relative only 8,323 of 44,596 and 270,397 instructions.

## 3. Results: field C++ code — step-correct (confirmed)

The field C++ code is written in 60 Hz units and scales by the step almost everywhere:
- Player actions: every `fld::PlayerPartyMario/Koopa::ActionState*` timer is `t -= party+0x100 (step)`; jump
  physics integrate with `v += a·0.5·step²` (e.g. `ActionStateSpinJump::vfunc_0x1c` 0x21DE50 / `vfunc_0x18`
  0x2C7500). **confirmed**
- On-screen field timer `fld::TimerObj::vfunc_0x8` 0x31E4B8: `+0xE7C += dir × step`, 60 units = 1 s, blink
  phase `+0xEF4 += step × 4`. Real time at both rates. **confirmed**
- `fld::BreakableChr::vfunc_0x3c` 0x2AB9EC: bob angle `+= step × 4`. **confirmed**
- The 39 constant-step `MoveVBase/MoveFBase/MoveC::update` calls in field code (`mod_hardstep.py` +
  `fld_hsck.py` + `armdis.py`) are one-shot finalizers: `stop` then `update(1.0)` (snap a mover to its end) or
  `update(0)` right after a move is set up (0x2BC2DC). None is a per-frame update. **confirmed**
- Integer member counters found by `fld_asm.py` in field code are reference/lock counts (`+0xBC`, `+0x2F48`,
  `+0x2F06/+0x2F08`, event-command lock bytes `+0x7F8`, `+0x833`), list sizes, or one-frame handshakes
  (`fld::MainBase::StateMapJumpPre::vfunc_0xc` 0x3138D0 waits `+0x68 == 1` = one frame for an async job).
  None is a gameplay timer. **confirmed** (each read in the dump)
- No `vmul`-by-literal damping and no literal smoothing on members in the field set. **confirmed (scanner)**
- Only per-call frame counter with gameplay effect: `fld::StaffrollCtrl::update` (Field.cro 0x12000DDC
  `frame += 1`), owned by CRD.

## 4. Results: field event scripts — frame-counting loops (confirmed in data)

The field VM has **no step variable** (field system variables, `fld::EventSystem` vt+0x2C = 0x2E225C, cover
$7000..$7077 + $7078..$70A7; none returns `fld::System+0x1A4C`). A script loop that ends with `wait(1)` runs
once per frame: 30×/s at 30fps, 60×/s at 60fps. Any constant added per iteration (position, meter, counter)
therefore runs **2× fast in wall-clock time at 60fps**.

### 4.1 Why `wait(1)` loops are per-frame (confirmed)
`wait(n)` (base op 0x05, handler 0x133EC4) stores `LocalEvent+0x28 = n` and yields (returns 3); n = 0 does not
yield. `execLocalEvent` 0x25BFA0 resumes the script after k frames, k = smallest integer with n − k·step ≤ 0,
i.e. **k = ceil(n / step)**. Field step = 2.0 at 30fps, 1.0 at 60fps (× fast-forward/game speed, §1):

| wait(n) | 30fps frames (ms) | 60fps frames (ms) |
|---|---|---|
| 1 | 1 (33) | 1 (17) |
| 2 | 1 (33) | 2 (33) |
| 3 | 2 (67) | 3 (50) |
| 2m | m (33·m) | 2m (33·m) |

So `wait(n)` is right in milliseconds for even n, and **`wait(1)` and `wait(2)` are identical at 30fps**.
Blocking field commands (`ScriptSystem::rewind` + return 3, e.g. op179 0x2E920C, op22F 0x2E1338) re-poll a
condition every frame; they wait for a state, not for a time, so they are fine.

### 4.2 Inventory (`fld_fev.py timers --broad`, body ≤ 80 instructions, accumulators only)
A loop is counted when it contains `wait(1)`, and a variable that is not recomputed in the iteration is advanced
by a constant (`inc/dec`, `+=/-=` immediate, `x = x ± imm`; local variables and the shared registers
$7078..$70A7). Result over all 714 `.fev` + 140 `.fme` scripts: **139 loops in 96 entries**; 5 are in dev test
rooms (`*_test_*`), 2 read button edges (§4.4), a few are input-driven cursors (`o_ekubon_07_2` `$7079`) that the
heuristic cannot tell from timers.
Grouped by what the player sees:

| group | entries (examples) | per-frame logic (decoded) | effect at 60fps |
|---|---|---|---|
| **Bowser-body minigames** (rooms with the DX "skip minigame" message `MES_sys_minigame_relief_01`) | `i_power_hip_SA_adorena_01_L` (shoot the adrenaline), `i_power_arm_02`, `i_power_nose_SA_peppansy_01_L`, `i_power_stomach_15_SA_giganin_01_L`, `i_power_lungs_SA_fire_01_L` (stylus slingshot), `o_peach_3f_15_SA_fire_packun_01_U`, `o_peach_t_SA_fire_dkoopa_01_U`, `o_ekubon_15_SA_giganin_01_U` | hip: cursor moves **±6 px per frame** with the stick, clamped 43..238 (0x8AAF–0x8BA5) and 18..213 (0x8D4C), countdowns `$3004/$3008 −1` per frame, hold counter `$3007` to 10 frames, timers −1/180 per frame (0xC621); arm_02: beat clock `$300C += 1.00282` per frame vs beat times `$300D += 30·tempo` (0x6AB1) and 15/8/7-frame waits; nose/stomach/packun/dkoopa: countdowns −1 per frame, meter `$300F −= 0.7`/frame (min −12), `$300E += 0.04`/frame, phase `+= 5`/frame | **minigames run 2× fast**: cursor speed 180 → 360 px/s, timing windows and countdowns halved, arm_02 beats drift off the music |
| **room gimmicks / enemies** (`.fme` object scripts) | `o_peach_2f_07/11/15/21/24`, `o_peach_3f_04/08/09/11`, `o_ekubon_08/11/12/20/21/30/32` (same snippet: `$300B −= 2` per frame, then act), `i_air_08..20`, `i_energy_02..30` (`$3001` to 10 frames "standing on it"), `i_energy_12/15/22/25` (`$3005` to 180 frames, `$300D −5/−10`), `i_pump_04..17` (20/41 frames), `o_koopa_23/27/31/32/33` (60 frames), `i_metaboru_02/06/08/11/13`, `o_zutsuda_01..03`, `i_garakuta_15` | timers that start an enemy action / trap / platform after N frames | enemies and traps react after half the time |
| **NPC idle / room scripts** | `o_town_04/32/41`, `o_zutsuda_07/17`, `o_koopa_40`, `o_ekubon_24`, `o_peach_g_16` (same 44-instruction snippet: owner register `$70A4` +1 per frame up to 60), `o_koopa_26/27`, `o_peach_3f_10` (`$70A0` −1 per frame) | 60-frame NPC timers | NPC behaviours cycle 2× fast |
| **cutscenes / NPC** | `i_dokan_01` (turn to face Mario for 60/90 frames), `o_gepu_02/03/05_after` (8-frame cycle), `o_peach_2f_19` (countdown), `o_koopa_19/28`, `o_ekubon_02/11` (`$3008 += 0.1`/frame into op0C3), `i_tainai_01` (hold counter) | per-frame counters in event scripts | shorter pauses / faster cycles; cosmetic |

Full machine-readable list: `python scripts/fps60/fld_fev.py timers --broad --body` (loops with bodies) and
`python scripts/fps60/fld_fev.py waitsites` (patch sites, §6.2). Not every minigame is script-timed:
`i_power_leg_SA_push_01_L`, `o_chika_12` and `i_power_arm_01` showed no accumulator loop (their remaining
per-frame loops poll states/inputs only). The minigame-only C++ commands that were read in the dump (op056,
op179, op17A–op17C, op1FF, op205, op206, op22F) are setters or condition waits; op201–op204 and op207–op209 have
no Ghidra function and were not read. These minigames are **likely fine** but must be played at 60fps (§8).

### 4.3 What the scanner does not see (limits)
Counters advanced inside a called subroutine, loops whose only per-frame wait is `wait($var)` with a runtime value 1
(not counted), unrolled straight-line sequences, and constant per-iteration moves done by a command argument
(e.g. a relative move command with an immediate). Coverage of these is **unknown**; the VM-level fix (§6.1)
covers them, the data fix (§6.2) does not.

### 4.4 Input in scripts (confirmed)
Scripts read buttons through `$7037..$703A` (`*(fld::System+0x1B00)`: hold, trg, rls, rep), party input
`$702F..$7032` (FUN_002221EC: same struct & party mask | forced input), `$703B/$703C`, touch `$7041..$7043`.
`$7038` (trigger) is used 195 times in 44 entries, touch 44 times in 8. Triggers are **per-frame edges**
(`Btn::update` 0x10409C: `trg = hold & ~prev` every main-loop iteration). Any fix that makes scripts poll less
often than every frame must keep the edges of the skipped frame, or presses are lost (§6.1 P4).
Only 2 of the 139 frame-timer loops read edges: `i_areanone_puzzle_02_U` 0x655–0x79D (hold scroll +1/frame,
triggers select) and `o_test_ay_01` (test room).


## 5. Other field-side items

### 5.1 Key repeat counts frames (global, confirmed; low priority)
`Btn::update` 0x10409C decrements one u16 repeat counter per button per main-loop iteration; first repeat after
`gBtn+0x44` = 10 iterations, then every `gBtn+0x46` = 2 (initializer FUN_00367C54: `DAT_00423914 = 10;
DAT_00423916 = 2;`; touch: `DAT_0042393A = 10; DAT_0042393B = 2`). At 60fps a held key repeats after 167 ms
(was 333 ms) and then every 33 ms (was 67 ms). Readers of `gBtn.rep` (0x4238E0): message windows
(`MessageSys::func` 0x24CF80 and FUN_00132804 OR it into the advance keys), menus
(`msys::MComSys::funcCalcMainNomal` cursor, `MMsgWnd`, `MEventSys`), battle (`btl::Main::getBtnRep`), field
script `$703A` (1 use, `o_evselect_U`). 1DX (native 60fps) keeps the same 10/2 (1DX init: `DAT_004b2914 = 10;
DAT_004b2916 = 2;`), so 60fps 3DX would feel like 1DX. Optional fix that keeps the 3DX feel: in the D1 init cave,
write 20/4 to 0x423914/0x423916 (u16) and 0x42393A/0x42393B (u8) when a task is promoted, 10/2 otherwise.

### 5.2 Checked and step-correct (no action)
Camera follow (`fld::TrgPosOfsUpdater_Normal::vfunc_0x10/0x14` 0x2DA8E0/0x2DA660: speed `+0x34 × step`, ramp
`+0x70 += step` to 12, limit `(ramp/12·6.92+0.08) × step`), field timer object (§3), message windows (FUN_0020EC9C
→ `Message::func` with the step, `modes.md` §2.2), player actions and jump physics (§3), screen-scroll mover
(`MoveVBase::update(sys+0x1B24, step)`), effects (`FUN_0036F7EC(step)`), event waits (§1). **confirmed**

### 5.3 Owned elsewhere
Staff roll (`fld::StaffrollCtrl`, Field.cro): CRD. Its scripts are `zi_areanone_staffroll_01_U.fev` and
`zo_areanone_k_staffroll_01_U.fev` (they use op22F 0x2E1338 = wait until an object's vt+0x14 reports done). The
field-step latch at field start: solved by D1 (`engine.md` §5/§9).

## 6. Fix options for the script frame loops

### 6.1 Option A (recommended): field scripts keep their 30 Hz schedule at 60fps (static code patch)
Gate G = `fld::System+0x45 == 0` (task promoted to 60fps by D1). Under G, run the field event VM only on even
frames (`fld::System+0x578 & 1 == 0`, the TaskBase frame counter) with twice the event step, and give scripts
the button/touch edges of the skipped frame. Every script slice then runs every 33.3 ms with step 2.0, exactly as
shipped; the C++ field (movement, camera, animation, drawing) runs at 60. No change when G is false (30fps, Old
3DS). It also covers the patterns the scanner misses (§4.3). Implementation via vtable-slot redirects to cave
wrappers (vtables `fld::EventSystem` 0x3E1784, `fld::ResidentEventSystem` 0x3E303C, both 14 slots):

| # | hook | wrapper behaviour |
|---|---|---|
| P1 | slot +0x34 (0x2A8AF0 / 0x2D9914: `GlobalEvent+0x14 = step`) | under G: `s0 *= 2.0`, then tail-call the original |
| P2 | slot +0x20 (FUN_002B81A8, exec one LocalEvent; called by the 7-slot loop vt+0x28 and directly by `fld::MainBase::vfunc_0x14` 0x30FD90 for NPC/object events = the `.fme` scripts) | under G on odd frames: save the latch (P4) and return the stored status `(LocalEvent+0x814 & 0x7FFFFFF) >> 25` without executing. **Do not gate** the one-shot init call from FUN_00305D3C (it passes a stack `ResidentEventSystem`; test `this` against sp, e.g. `0 <= this − sp < 0x2000` → no gate) |
| P3 | slot +0x2C (FUN_002E225C, system-variable read) | under G on even frames: OR the latch into the pad struct `*(fld+0x1B00)` +8 (trg) / +0xC (rls) and the touch edge bits of `*(fld+0x1B08)+8`, call the original, restore the struct, return s0. Covers `$7037..$703A`, party input `$702F..$7032` (FUN_002221EC reads the same struct), touch `$7041`; `$703B/$703C` (Main+0x2F80/+0x2F98, 4 uses in `i_tainai_01`) need the same if they are edges (open) |
| P4 | latch storage (16 bytes RW) | {trg, rls, touch bits, frame no.}; saved on odd frames by P2 (the struct already holds that frame's input: `fld::System::funcCalc` 0x306BC4 refills it before the field state machine runs), used by P3 only if `latch.frame == current − 1` (no stale re-trigger). Candidate RW space: the zero tail of the last bss page **0x434D40–0x434FFF** (bss 0x3F8170 + 0x3CBD0 = 0x434D40, data+bss are mapped in whole pages) — verify at runtime (§8) |

Implementation notes: the wrappers reach `fld::System` as `[[this+4]+0x130]` (the shared reader 0x2E225C uses this
path for both event systems) or through the persistent pointer `[0x3F49B0+0x20]`; the return values of slot +0x20
are ignored by all three callers (vt+0x28 loop, `fld::MainBase::vfunc_0x14`, FUN_00305D3C). Cost: 6 rodata words +
about 0xC0 bytes of cave + 16 bytes RW; with D1 (0x70) and the CRD credits fix this still fits D2's cave
0x388E00–0x388FFF (0x200 bytes) — IMPL to confirm. Behaviour changes at 60fps: scripted moves update
at 30 Hz (as shipped); events start ≤ 16.7 ms later. Risks: C++ code that expects a script-written value every
frame (none found), the parity of P2/P3 must match, `this` test for the init path. Fast-forward stays as shipped
(event step = 2 × field step = the 30fps value).

### 6.2 Option B (fallback): data patch `wait(1)` → `wait(2)` in the detected loops
`python scripts/fps60/fld_fev.py waitsites` lists **136 sites in 90 entries** (entry, instruction offset, u16
parameter offset = instruction + 6, 1 → 2), excluding test rooms and the edge-reading loop of
`i_areanone_puzzle_02_U`. Same length, so no relocation. At 30fps behaviour is byte-identical (`wait(1)` ≡
`wait(2)` at step 2, §4.1); at 60fps the loops iterate every 33 ms, so cursors, meters, countdowns and beats are
right in ms. Cost: FEvent.dat (romf2, 6,395,308 bytes, BG4 v261, 714 BLZ `.fev` + 140 BLZ `.fme`) goes into the
patch romfs (the Korean patch does not ship it) with a byte-identical BG4/BLZ rebuild (`lib3dx.rebuild_bg4`), like
BTL2's BAI. Limits: only detected loops; a game speed < 1.0 would make `wait(2)` ≠ `wait(1)` at 30fps (no field
code that sets it was seen; scripts not checked). A and B are compatible (under A, `wait(2)` = one VM tick).

### 6.3 Recommendation
Ship **Option A** with D1 (field promoted to 60): it is the field counterpart of BTL2's BAI fix but generic, and
the minigames are unplayable at 2× without it. Keep Option B as the fallback if the input latch (P3/P4) fails
runtime tests; B fixes all listed minigames except the hold-scroll in `i_areanone_puzzle_02_U`.
If neither is ready, exclude `fld::System` from the D1 allow-list (field stays 30) rather than ship 2× minigames.

## 7. Patch-point table

| ID | location | original | proposed | why | side effects |
|---|---|---|---|---|---|
| F1 | vtables 0x3E1784+0x34, 0x3E303C+0x34 (file 0x2E17B8, 0x2E3070) | 0x002A8AF0, 0x002D9914 | cave `fld60_evstep`: under G `s0 *= 2`, b original | event waits = 30fps schedule | none at 30fps |
| F2 | vtables 0x3E1784+0x20, 0x3E303C+0x20 (file 0x2E17A4, 0x2E305C) | 0x002B81A8 (both) | cave `fld60_evexec`: under G and odd frame (and `this` not on the stack) save latch, return status; else b 0x2B81A8 | scripts run every 2nd frame | scripted moves 30 Hz (as shipped) |
| F3 | vtables 0x3E1784+0x2C, 0x3E303C+0x2C (file 0x2E17B0, 0x2E3068) | 0x002E225C (both) | cave `fld60_sysvar`: under G and even frame OR latch edges into pad/touch structs around the call | no lost presses at 30 Hz polling | none at 30fps |
| F4 | RW latch 16 bytes, e.g. 0x434F00 | zero | {trg, rls, touch, frame} | storage for F2/F3 | must be verified mapped and unused |
| F5 (alt.) | FEvent.dat, 136 `wait(1)` u16 params (`fld_fev.py waitsites`) | 0x0001 | 0x0002 | data-only fix of detected loops | +6.4 MB romfs file |
| F6 (opt.) | D1 init cave: 0x423914/0x423916 (u16), 0x42393A/0x42393B (u8) | 10/2 | 20/4 when promoted, 10/2 otherwise | key repeat in ms as at 30fps | menus feel like 3DX instead of 1DX |

(File offsets: address − 0x100000. The vtable address points are from the RTTI layout,
`work/fps60/ghidra/3dx_v12/layout.tsv`; slot = address point + byte offset.)

## 8. Runtime checks for RT2 (scene → expected observation)

1. **Minigame speed, unpatched mode 0** (D1 build or `setfps 0`): `i_power_hip_SA_adorena_01_L` (adrenaline beam):
   the cursor moves twice as fast as at mode 1 (measure x of the moved object per second: ≈180 px/s at 30,
   ≈360 at 60); with Option A or B, 180 at both.
2. **Rhythm** `i_power_arm_02`: beats drift from the music at mode 0 without the fix; in sync with it.
3. **Gimmick timer** e.g. `o_peach_2f_07` enemy (`$300B −= 2` per frame): reaction delay halves at mode 0
   without the fix.
4. **Input latch (Option A)**: in any "press A" script prompt and in a trigger minigame
   (`i_power_leg_SA_push_01_L`), tap A for one frame many times: every tap must register at mode 0.
5. **RW latch space**: read 0x434D40..0x435000 at the title and in the field (expect zeros, readable and
   writable); GDB `m`/`M`.
6. **Init path**: enter a field room on an odd and on an even frame (resident init scripts run, field starts
   normally) with Option A.
7. Key repeat (F6): hold Down in the pause menu; first repeat ≈333 ms, then ≈67 ms with F6.

## 9. Open questions

1. What drives `fld::System+0x6E0` bit 0x40 (cleared by FUN_00307234 from FUN_00309A20 and
   `fld::System::StateMain::vfunc_0xc`): do events run in states where the field step is not refreshed? (Option A
   gates on +0x45 only, so it is unaffected; the field step itself is D1's concern.)
2. Meaning of the touch edge bits 2..5 at `*(fld+0x1B08)+8` (copied from gTp+8 at 0x306BC4) and whether
   `$703B/$703C` are edge sets; needed for P3.
3. Field commands with no Ghidra function (192 handlers; op201–op204, op207–op209 among the minigame ones) were
   scanned only as raw code (`fld_asm.py`), not read.
4. Whether the field game-speed factor `[[sys+0x574]+0x7C]` is ever set below 1.0 by scripts (affects Option B
   only).
