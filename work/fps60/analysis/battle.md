# BTL — battle and action-command timing at 60fps (3DX JP v1.2)

Worker BTL, 2026-10-30. Static analysis only (armdis + own decoders; Ghidra dumps were not ready:
`work/fps60/TOOLS_STATUS.md` did not exist). Addresses: static = runtime address; CRO = analysis
address (Battle.cro base 0x11000000, file offset = addr − 0x11000000). Confidence tags:
**confirmed** (read in disassembly / decoded data), **likely**, **guess**.

Tools written for this report (read-only):
- `scripts/fps60/btl_aitbl.py` — dumps the Battle.cro AI command table (535 battle opcodes from
  0x4e) and the AI system-variable table.
- `scripts/fps60/btl_bai.py` — decoder for the battle AI scripts in `romfs/BAI/BAI.dat` (543
  `.bai` files, 646k commands decoded, ~95% of bytes), plus `grep`, `var`, `loops` queries.

## 1. Pipeline overview (confirmed)

```
main loop (main() @0x101cdc, once per presented frame)
  Btn::update(gBtn @0x4238d0)          0x10409c   hold/prev/trg/rls/rep from PadReader, 17 buttons
  Tp update(gTp @0x423930)             0x103ca4
  gTaskMainMan->vfunc[0x10](), [0]     task run (btl::Main among them)
btl::Main::update (unnamed, 0x28b67c, the function right after Main::entryObj)
  step s19 = (isFps30?2:1) * [Main+0x574]->+0x7c * Main+0x8a3c          ; 60 Hz units per frame
  Main+0x8a44 += s19; whole = modff -> int part (sp+0x44); wholeStep = (int != 0)
  accumulate gBtn hold/trg/rls into Main+0x8a28/2c/30 (cleared after a frame that had wholeStep)
  Main+0xba15c = s19  (AI sysvar $7012), Main+0x8a40 += s19 (AI sysvar $7013)
  KeyContFrm update for each ChrPc (0x28c1c8)
  objects: ObjMove::update -> calcUpdateSpd = step (s19-derived)
  AI: GlobalEvent(AISys)+0x14 = max(1?, int part)  (0x28c740..0x28c764); waits decrement by it
```

### 1.1 Input sampling (confirmed)
- `Btn::update` @0x10409c (called from the main loop @0x101cec every iteration): reads the pad via
  the SDK PadReader (0x107480), then
  `+0x00 hold, +0x04 prev hold, +0x08 trg = hold & ~prev, +0x0c rls = prev & ~hold,
  +0x10 rep` (repeat: first after `+0x44`=10 loop iterations, then every `+0x46`=2; set by the
  static initializer @0x367dc8/0x367dd4). Trigger edges are computed between consecutive main-loop
  iterations, i.e. once per presented frame: 30 Hz at 30fps, 60 Hz at 60fps.
- `btl::Main::update` @0x28b75c–0x28b7e8 ORs `gBtn[0]` (hold), `gBtn[2]` (trg), `gBtn[3]` (rls)
  into `Main+0x8a28/+0x8a2c/+0x8a30` and touch bits into `+0x8a34`. When the frame produced at least
  one whole 60 Hz step it sets `Main+0x17b0 |= 0x1000`, and the next frame clears the accumulators
  first (0x28b728–0x28b758). So a press is never lost when the battle runs slower than one step per
  frame (slow motion); at normal speed the accumulator equals the current frame's state.
- Accessors: `btl::Main::getBtnCnt` 0x3530e4 = `+0x8a24 & +0x8a28`, `getBtnTrg` 0x353138 =
  `+0x8a24 & +0x8a2c`, `getBtnRls` 0x353124, `getBtnRep` 0x3530f8 = `gBtn.rep & +0x8a24`
  (not accumulated). `+0x8a24` is the enabled-button mask.
- AI scripts read buttons through system variables (read switch @0x110477c4, jump table
  0x11047804): `$7005` = getBtnCnt & 0xdffb, `$7006` = getBtnTrg & 0xdffb, `$7007` rls,
  `$7008` rep, `$7009..$700c` raw gBtn hold/trg/rls/rep, `$700d/$700e` stick, `$7025/$7026`
  touch x/y. Only `$7005` (72 uses) and `$7006` (247 uses) occur in BAI.dat.

### 1.2 The frame step (confirmed)
```
0028b69c: mov r0, r4 ; bl isFps30            ; Main (TaskBase) fps byte +0x45
0028b6a4: vldr s17, =1.0 ; vmoveq s0, s17 ; vldrne s0, =2.0
0028b6bc: vldr s1, [r0(+0x574), #0x7c]       ; external speed factor (likely the "game speed")
0028b6c4: vmul s0, s0, s1
0028b6c8: vldr s1, [Main+0x8a3c]             ; battle time scale, 1.0 at construction (0x28e238)
0028b6d0: vmul s19, s0, s1                   ; s19 = step in 60 Hz units
0028b6e8: Main+0x8a44 += s19 ; modff -> fractional back to +0x8a44, int part to sp+0x44
0028b7f4: vstr s19, [Main+0xba15c]           ; AI sysvar $7012
0028b804: Main+0x8a40 += s19 (wraps at 2^24) ; AI sysvar $7013
```
`Main+0x8a3c` is written by AI sysvar `$7011` (write switch @0x110487bc) and by a few Battle.cro
tasks (0x11019d14, 0x1101f088, 0x11020ba0) — slow-motion effects; it does **not** contain the fps
factor.

### 1.3 Battle objects (confirmed)
- `btl::ObjBase::calcUpdateSpd` @0x23c784: if `obj+0x24 & 2`: `(isFps30(btl::Main)?2:1) *
  obj+0x20`; else `[obj+0x2c]+4 * obj+0x20`, and `Main::entryLayer` @0x23a80c sets `obj+0x2c =
  Main+0xba158`, so `[obj+0x2c]+4` = `Main+0xba15c` = s19. Both paths are fps-aware. The task used
  by the first path is `[0x3f35f8+8]` = btl::Main (same pointer the KeyCont code uses to reach
  `Main+0x8a2c`).
- `btl::ObjMove::update` @0x23c7e0 advances everything with that step: MoveVBase/MoveC/MoveFBase,
  CellAnime, LytAnim, **and the per-object action timer** `obj+0x374 = min(obj+0x374 + step,
  obj+0x378)` (0x23c848–0x23c864).

### 1.4 AI script timing (confirmed)
- Battle AI = AlphaDream event VM `GlobalEvent::execLocalEvent` @0x25bfa0 with btl::AISys
  (Battle.cro; vtable 0x11064374, ctor 0x11059a38, command descriptors 0x1105f730, extra command
  PMF table 0x1105e118, first battle opcode = `GlobalEvent::_CmdFuncTblSize` = 0x4e).
- Wait: base op 0x05 `wait(u16 n)` @0x133ec4 sets `LocalEvent+0x28 = n` and yields; every exec
  does `+0x28 -= GlobalEvent+0x14` (0x25bfc8–0x25bff8). btl::Main sets
  `AISys+0x14 = int part of the step accumulator` (and at least 1.0 when `Main+0x17b0 & 1`),
  0x28c740–0x28c764. ⇒ waits are in 60 Hz units: `wait(n)` = ceil(n/2) frames at 30fps, n frames
  at 60fps. Identical in ms for even n; odd n is 16.7 ms longer at 30fps.
- Script arithmetic (base ops, decoded handlers 0x133900…0x13450c): 0x15 assign, 0x16 add,
  0x17 sub, 0x18 mul, 0x19 div, 0x23 `x++`, 0x24 `x--`, 0x25 `x+=a`, 0x26 `x-=a`, 0x03 conditional
  jump `(cmp, a, b, expect, target)`, 0x04 jump `(0/2 jump, 1 call, target)`.
- Scripts use the step variable `$7012` 376 times in 134 files (`x += c*$7012`), and the global
  clock `$7013` 71 times — the authors wrote most per-frame logic in 60 Hz units.

## 2. How the action commands are judged

### 2.1 Basic attacks (jump, hammer, punch, fire) — fps-correct (confirmed)
Player attacks are AI scripts: `atk_pc_solo_jump/hammer/punch/fire.bai`, `atk_pc_vacuum.bai`,
`atk_pc_sp_*` (Bros./Brawl attacks), `atk_pc_minigame_*`, started by the Battle.cro command tasks
(`CreateChrPcCmdSoloJump` 0x11036c18 etc.). Example `atk_pc_solo_jump.bai` (decoded):
```
002ff8: $8011 = $707c + $8011
003004: op1d6($7004, $8011)          ; obj(+0x374) = 0, obj(+0x378) = limit      (handler 0x1104e1cc)
00304f: loop: if ($707d != 0) return
00307d: $8012 = op1d7($7004, 0)      ; read obj+0x374 (the step-driven timer)    (handler 0x1104c374)
003088: $1007 = $7006 & $8014        ; trigger & this PC's button
003094: if pressed: t = $8012 - $707c; if lo<=t<=hi (tables @0x1e44/0x1e7c by level) -> excellent
                    else second table pair (0x1e60/0x1e98) -> good, else fail
00331c: other button pressed -> fail
00334e: op1d7($7004, 2) (timer >= limit) -> fail (timeout)
003381: wait(1) ; goto loop
```
The window is measured with `obj+0x374`, which ObjMove::update advances by the step (2 per frame at
30fps, 1 per frame at 60fps). Window bounds are 60 Hz units. ⇒ with a correct fps flag the window
is the same in milliseconds at 30 and 60fps (60fps resolves it in 16.7 ms steps instead of 33 ms).

### 2.2 KeyContFrm (ChrPc button buffer) — frame-counted, but inert in the shipped data (confirmed)
- Update in btl::Main::update 0x28c1c8–0x28c4e4, for both slots of every ChrPc of the current layer
  (`ChrPc+0x500+16*i`, slot button masks from `vfunc[0xd0]`/`vfunc[0xd4]`):
  press → `time=0, limit=end(+8), active=1`; otherwise `time = min(time + Main+0x8a3c, limit)`,
  `active = time < limit`. The increment is `Main+0x8a3c` (1.0 per frame), **not** the step, so a
  non-zero window would be twice as long at 30fps as at 60fps in ms.
- The window end is only set by AI op 0x18e (`setKeyContFrmEndTime`, handler 0x1104f508 → ChrPc
  0x2928c8 → PMF 0x1f0774). Op 0x18e occurs **0 times** in BAI.dat (flow decode and a brute-force
  byte scan). With end = 0 the flag is true only in the press frame, at both frame rates.
- The check op 0x18f (handler 0x1104b270, reads `ChrPc+0x50c`) is used 9 times: `atk_dgeraco_3`,
  `atk_dstar_6`, `atk_dstar_x_6`, `atk_gmonster_1`, `atk_gmonster_x_1`, `atk_mboss_b_sbit_4`,
  `atk_pc_minigame_ml_ball`, `atk_pc_sp_ml_ball`, `atk_pc_sp_ml_ball_easy`.
- ⇒ no 60fps change in shipped content. A fix is only needed if a future data change uses 0x18e.

### 2.3 Scripts that hard-code the 30fps step (confirmed, few)
`btl_bai.py loops` scans every backward branch (12,091 loops); 155 loops read buttons. Per-frame
counters that do not use `$7012`:
| scripts | loop | logic | 30fps | 60fps |
|---|---|---|---|---|
| atk_dstar_4, atk_dstar_x_4, atk_koopa2_2, atk_koopax_2, atk_dgeraco_5 | e.g. dstar_4 0x3421–0x34a4 | hold-button grace: while not held `$8012 += 2` per `wait(1)`; `>= 16` ends the hold | 8 frames = 267 ms | 8 frames = 133 ms |
| (same files) | dstar_4 0x31a4–0x3626 | `$707e++/--` phase counter (event count, not time) | — | — |
| atk_gmonster_4 (+_x) | 0x1ece–0x1f6c | mash: `$8012++` per trigger, need 32 within obj timer 360 units | count | count (easier: 60 Hz sampling registers faster mashing) |
The `+= 2` per frame is the only time-based fixed counter in an input loop; it shortens a release
grace period, it does not shorten a press window.


---
## BTL2 continuation (wave 2, 2026-10-30)

Worker BTL2. Ghidra dumps (`work/fps60/decomp/3dx_v12/`) + `armdis.py` + own tools. New tools:
`scripts/fps60/btl_timing.py` (frame-rate-dependent loops in BAI scripts) and `scripts/fps60/btl_baifix.py`
(BAI.dat rebuild + fix, see section 7). Outputs in `work/fps60/build/bai/`.

### 2.4 AI VM timing model, exact (confirmed)
- Variables and immediates are **floats**. `GlobalEvent::execLocalEvent` 0x25BFA0 decodes params: a param flagged
  in the var mask is read through the register reader (`getRegister` 0x2762B8; `$7xxx` -> `btl::AISys::vfunc_0x18`
  Battle:0x110477C4); a float-typed param (type 8) keeps the raw float (`local_a8[i]`), other types are converted
  to int. `$7012` returns `*(float*)(btl::Main+0xBA15C)` (Battle.c line 53408), `$7011` = Main+0x8A3C,
  `$7013` = Main+0x8A40.
- op016 0x133900: `vldmia {s0,s1} <- params; vadd.f32 s0,s0,s1; PutRegFlag(res)` => `res = p0 + p1`.
  op025 0x133FEC: `res = GetRegFlag(res) + p0`. op015 0x133CA0: `res = p0`. op017 = `p0 - p1`, op018 `p0*p1`,
  op019 `p0/p1`, op027 `x *= a`, op028 `x /= a` (descriptors: op016..op019 res + [f32,f32]; op025/op026 res + [f32]).
- op005 `wait(n)` 0x133EC4: `if n: LocalEvent+0x28 = (float)n; return 3 (yield)`; `wait(0)` does not yield.
  On every later exec: `if +0x28 > 0 { +0x28 -= AISys+0x14; if > 0 return 3; +0x28 = 0 }` (remainder dropped).
- `AISys+0x14` = whole 60 Hz ticks of this frame (0x28C740..0x28C764: `int part of Main+0x8A44 accumulator`,
  raised to >= 1.0 only when a flag at sp+0x454 is set). At time scale 1.0: **2.0 at 30fps, 1.0 at 60fps**.
- `$7012` (= s19, 0x28B7F4) = `(isFps30?2:1) * [[Main+0x574]+0x7C] * Main+0x8A3C`. The two factors are 1.0 in
  every battle phase except the victory sequence: `[[Main+0x574]+0x7C]` and `+0x8A3C` are reset to 1.0 by
  FUN_001EAAF0 (0x1EAD48 `vstrne s16,[r0,#0x7c]` with r0 = [Main+0x574]; 0x1EAD4C `vstr s16,[r6,#0x23c]`, r6 =
  Main+0x8800; s16 = 1.0; called from 0x1EADF8), the only other writers of `+0x8A3C` are
  `btl::TaskBtlResultPcWin` (Battle:0x11019BE4, victory slow-motion, restores 1.0) and the AI write of `$7011`,
  which **no BAI script uses** (`btl_bai.py var 0x7011`: only reads, in `atk_pc_sp_ml_meteo*`). [likely: no
  other writer found in static/Battle decomp]
- Consequences (per frame = per presented frame):
  | script construct | 30fps | 60fps | fps-correct? |
  |---|---|---|---|
  | `wait(2k)` | k frames = k*33.3 ms | 2k frames = k*33.3 ms | yes |
  | `wait(2k+1)` | k+1 frames | 2k+1 frames | 16.7 ms shorter at 60 |
  | `wait(1)` loop body | once per frame (33.3 ms) | once per frame (16.7 ms) | rate doubles |
  | `x += c*$7012` per `wait(1)` | 2c per 33 ms | c per 16.7 ms | yes |
  | `x += 2` per `wait(1)` (hard-coded 30fps step) | 2 per 33 ms | 2 per 16.7 ms | **no (2x)** |
  | `x += c` per `wait(1)` (per-frame rate, c != 2) | c per 33 ms | c per 16.7 ms | **no (2x)** |
  | `x /= $7012` then `x--` per `wait(1)` (e.g. `atk_dkoopa_3` 0x2EAB) | frames | frames | yes |
- Two **exact** same-length transforms (byte-identical behaviour at 30fps whenever the step is 2.0, i.e. outside
  the victory slow-motion):
  1. `$v = op025(2f)` (12 bytes: `25 00 | 00000000 | vv vv | 00 00 00 40`) -> `$v = op016($v, $7012)` (12 bytes:
     `16 00 | 03000000 | vv vv | vv vv | 12 70`). 30fps: `v + 2.0`; 60fps: `v + 1.0`. Same for `op026(2f)` ->
     `op017($v, $7012)`. Keeps 60 Hz resolution.
  2. `wait(1)` (8 bytes `05 00 | 00000000 | 01 00`) -> `wait(2)`. 30fps: `2 - 2 = 0` -> resumes next frame, same as
     `1 - 2 < 0`. 60fps: the loop body runs every 2nd frame = every 33.3 ms, i.e. exactly the 30fps rate for every
     constant inside the loop. Costs: the loop updates at 30 Hz at 60fps, and a **trigger** (`$7006`) polled only in
     that loop can be missed on the skipped frame (battle button accumulators are cleared every frame that has a
     whole tick, i.e. every frame at 60fps, 0x28B728..0x28B758), so it is not used on trigger-polling loops.
  Inserting bytes is avoided: decode coverage is ~95%, so relocating jump targets cannot be proven complete.

### 2.5 Frame-rate-dependent loops in BAI.dat (confirmed, `btl_timing.py counters`)
`work/fps60/build/bai/scan_counters.tsv`: 234 constant-delta variable updates in loops whose direct body has a
`wait(1)` (columns: kind = step2 / angle / rate / count, uncond = updated on every pass, cmp_in_loop).
Waits overall (`scan_waits.tsv`): odd immediates are almost all `wait(1)` (atk 520, atk_pc 568, mon 122);
other odd waits are rare (wait(15) x9, wait(29) x9, wait(5/9/37/73/25...) <= 2 each) -> negligible.
Triage so far:
- **Hard-coded 30fps step `+= 2` used as time** (fix with transform 1): the 5 hold-grace loops of 2.3
  (`atk_dstar_4`/`_x_4` 0x3454, `atk_koopa2_2` 0x2B78, `atk_koopax_2` 0x2742, `atk_dgeraco_5` 0x298E) plus
  `atk_geraco2_4` 0x2560 (`$8018 += 2` per frame until `>= $707E`: a wait of `$707E` 60 Hz units, half as long at
  60fps), `atk_koopax_5` 0x4B82 (`$8011 += 2` per frame, timeout `$8001`), `atk_geraco2_3` 0x2E66/0x2EC9 (`$8010 += 2`
  drives an interpolation `$8013 = $8010/50` and an 80-unit animation toggle).
- **Per-frame angles/rates in the same attacks**: `atk_dstar_4` 0x2E09 (`$8013 += 7.4` deg per frame, wrap 360;
  the enemy circles on an ellipse via op118, 1.62 s per lap at 30fps, 0.81 s at 60fps), `atk_dstar_x_4` (8 deg),
  `atk_koopa2_2` 0x2659 (6.8), `atk_koopax_2` 0x2223 (7), `atk_dgeraco_5` 0x2450 (7.4) -> transform 2 on the loop's
  `wait(1)`.
- Correct by construction (examples): `atk_dkoopa_3` 0x2EAB `$3002 /= $7012` then `--` per frame; the solo attacks
  (2.1); `atk_dokkun_1`, `atk_dstar_6`, Bowser brawl attacks with `step=yes`.

## 3. Bowser's attacks and Bowser's special moves (confirmed)
- Solo attacks: `atk_pc_solo_punch` (Bowser punch), `atk_pc_solo_fire` (fire breath), `atk_pc_solo_hammer`, `_jump`:
  each starts the step-driven object timer with op1d6 (`obj+0x374 = 0, +0x378 = limit`) and judges with op1d7
  (op1d6 1x, op1d7 2x per script), polling `$7006` once per frame in a `wait(1)` loop (punch 0x2E61-0x2FC4, fire
  0x32E1-0x3448, hammer 0x2D97-0x2EE6). Fire's hold loop 0x347E-0x34F0 only compares `$7005` with a mask every
  frame (no counter). Windows are therefore the same in ms at 30 and 60fps (as for jump, 2.1).
- `atk_pc_vacuum` (Bowser's inhale): object timer (`op1d7($7000,0/2)` at 0x4BC7/0x4BE4) bounds the phase, `$8012++`
  only when a trigger arrives (0x4C1F, `$8014 = $8013 & $7006`), compared with `$8019` (0x4CA9). Press count, not
  time. At 60fps a press is sampled 60 times per second: a player pressing <= 15 times/s gets the same count; only
  faster mashing can count higher than at 30fps (easier, never harder).
- Brawl attacks `atk_pc_sp_k_{kuribo,heiho,bombhei,kameck,nokonoko,blodog}` (+`_easy`): 28 button-reading loops,
  all `wait(1)`; 8 of them advance their meters with `$7012`; the other 20 are start/confirm prompts reading only
  triggers. Their counters (`$7072/$7073/$706e/$707e`) are round/hit counts, e.g. `atk_pc_sp_k_kameck` 0xA332
  `$707e++` tested `< 4` at 0xA475 (four rounds). The `+= 2` in every k_* script (e.g. bombhei 0x75A3/0x7619/0x7734)
  are table index steps (`op1dd($708b, i, 0)` on records of 18 words), not time.

## 4. Bros. attacks, multi-stage timing (confirmed)
- `atk_pc_sp_ml_*` (+`_easy`): 50 button-reading loops, every one polls once per frame (`wait(1)`); 10 advance
  meters with `$7012`; windows are read from attack-object timers, e.g. `atk_pc_sp_ml_ball` loop 0x7025-0x72AD:
  `$801c = op1d7(0x30009, 0)`, `$801d = $801c - $3009`, then `$3005 <= $801d`, `$3003 <= $801d <= $3004` (0x7207..
  0x7265). The `wait(2)` listed for that loop is in a sub-thread body started by `op04e(0x30009, 0, 0x713a)`
  (0x7120 -> 0x713A..0x7164), not in the polling path. Spin Pipe (`_dokan` 0x47DA-0x5828) waits `wait($8017)` with
  `$8017` = 36/50/74/100 (60 Hz units, 0x4A54..0x4AAF). Fire Flower counts presses (`$7071++`/`$8017++` only after a
  trigger, thresholds 20/27/28/42). `_meteo` reads `$7011` (the battle time scale), not the fps.
- Every stage of a Bros. attack is a separate wait/timer in 60 Hz units, so multi-stage sequences keep their ms
  timing at 60fps; the remaining 60fps difference is input resolution (16.7 ms instead of 33.3 ms), which only
  makes windows easier to hit at their edges.

## 5. Enemy-attack dodges and counters (confirmed)
- The player's reactions are C++ commands in static code, not enemy scripts (175 of the 190 enemy `atk_*`
  scripts read no button at all):
  - `btl::ChrCmdPcDefJump` (ctor 0x1E7C50, state PMF at +0x6C/+0x70, state fns 0x1E7460/0x1E72EC/0x1E7498): jump
    parameters are floats (+0x74 2.0/16.0, +0x80 4.0/10.0, +0x88 -0.625, +0x78 62, +0x84 44, +0x8C 20/15) used by
    the PC's MoveV, i.e. advanced with the step; hold test `Main+0x8A24 & Main+0x8A28 & 0x800` (0x1E7498).
  - `btl::ChrCmdPcDefHammer` (vfuncs 0x1ED9E0/0x1EDA84, states 0x1EC2C4/0x1EC598/0x1EC5CC/0x1ED08C); its display
    object `ChrCmdPcDefHammer::ObjDispHam::vfunc_0xc` 0x1EBCD8 is where the static isFps30 call 0x1EBD7C lives
    (engine.md lists it under ObjBadgeStarMan; Ghidra's function bounds put it here) -> step.
  - `btl::ChrCmdPcDefKoopa::vfunc_0x8` 0x1E9A70 (Bowser guard / counter punch): press = KeyContFrm active flags
    `ChrPc+0x50C` / `+0x51C` (true only in the press frame, 2.2), hold = `Main+0x8A24 & +0x8A28 & 0x800`, every
    phase ends on `obj+0x378 <= obj+0x374` (ObjMove action timer, step) with limits from the command (+0x18,
    +0x20, +0x30, +0x38, +0x3C) or on `isAnmBusy`.
  - Hits are tested by C++ hit checks every update (`btl::Obj::startDefaultHitCheck` 0x1F8BE8): 60 samples/s at
    60fps instead of 30, so a dodge is judged at least as precisely.
- Assembly-level scan (`scripts/fps60/btl_asmscan.py`, `work/fps60/build/bai/scan_asm_counters.tsv`; it reads the
  armdis listings, so it is not affected by Ghidra treating `MoveVBase::stop` 0x24F578 as non-returning and cutting
  87 C functions): over every static btl function and every Battle.cro function, the field `+/-1` updates that are
  compared with an immediate are reference counts (`[rX,#4]`, `+0x258` vs 0), state bytes, and FUN_0023D7C4
  0x23E1FC (byte counts vs 22/30). **No per-frame integer timer in the defense, encount, result, timer or badge
  code.** (A decompiler-text scan, `btl_cscan.py`, agrees.)
- Enemy scripts that do read buttons: the hold attacks of 2.3/7 (fixed), `atk_gmonster_4`/`_x_4` mash count (2.3),
  `atk_imonu_k_4`/`_x_4`, `atk_koopa_1`, `atk_koopa2_1/_2/_4`, `atk_koopax_1/_2/_4/_5`: all poll in `wait(1)` loops;
  none has a constant per-frame counter except the fixed ones (scan_counters.tsv).
- What does change for dodges at 60fps: each odd immediate wait before a hit is 16.7 ms shorter (enemy `atk_*`:
  wait(15) x5, wait(5/73/25) x2, wait(45/17/35/11/29) x1, besides wait(1)); and the frame-counted enemy loops of
  2.5 (orbits fixed in 7; e.g. `atk_uruhei_1` 0x2458 raises a random chance every frame, `atk_zuttsun_1` 0x22E5
  counts frames up to `$8012`, `atk_dstar_2` 0x28EB ramps 0.2/frame: not fixed, see 9).

## 6. Gauges, timers, transitions, Bowser Jr.'s Journey (confirmed unless marked)
- Badge gauge: values change per event (`btl::ObjBadgeLlcd::setGaugeValueInstant` 0x1DFF6C, `getGaugeValue`
  0x350C70, `setPcBadgeDataBadgeGauge` 0x28A388); the display animation in `ObjBadgeLlcd::vfunc_0xc` 0x1E0220 uses
  `calcUpdateSpd` (decomp line 217) and MoveFBase objects at +0x7570 -> step. Badge stars (`ObjBadgeStar::vfunc_0xc`
  0x1E1A78) and `TaskBadgeEffect::vfunc_0x8` 0x1E8E70 animate through ObjMove. fps-correct.
- Special-attack gauges/meters are BAI variables of the Bros./Brawl attack scripts, updated with `$7012` (3, 4).
  No other C++ gauge class exists in btl (index search: `Gauge` only in ObjBadgeLlcd).
- `btl::ObjTimer` (Battle.cro: `btl::CreateObjTimer` 0x11006818, created by `btl::Main::entryObjSystemTimer`
  0x2893C0; API `ObjTimer_getTime` 0x1100CBBC, `_setTime` 0x1100CBF0, `_pauseTimer` 0x1102303C, `_resumeTimer`
  0x110276B8): update `ObjTimer::vfunc_0xc` Battle:0x1105AD4C does `elapsed(+0xA58) += calcUpdateSpd` clamped to
  the set time `+0xA5C` (setTime clamps to 215999 = 59:59 + 59/60 s in 60 Hz units), time left = `+0xA5C - +0xA58`,
  warning blink phase `+0xA68 += step*4`. fps-correct.
- Battle start/end: `btl::TaskEncount{Standard,Back,Jump,Hammer,Punch,Fire,Toge}::vfunc_0x8` (Battle:0x11025AEC,
  0x1100A068, 0x1100AC9C, 0x11014034, 0x1100D6D4, 0x1100A730, 0x1100B5AC), `TaskPcEscape` 0x11004408,
  `TaskBtlResultPcWin` 0x11019BE4, `TaskBtlResultPcLose` 0x1102347C: they wait on
  `isEndOpenEncountAndLoadResources` / `isLoadingAnyWithUpdate` / `isLoadingDfxSymbol`, `MoveVBase/MoveFBase::isBusy`,
  `isAnmBusy` and ObjMove timers (+0x374/+0x378); the win result's count-up adds `Main+0xBA15C x rate` (Battle.c line
  23674) and its slow-motion multiplies `Main+0x8A3C` into the step (restored to 1.0). No frame counters (asm scan).
  Several of these C functions call `MoveVBase::stop` and may be cut in the dump; the asm scan covers their full
  ranges. Crash gates of the transitions: crash.md C4.
- Bowser Jr.'s Journey: KJRPG.cro has no reference to `btl::`, `AISys` or `.bai` -> its battles are `kj::` code
  (MOD2/modes.md), untouched by this report and by the BAI fix.
- AttackMiniGame.cro is a menu-type task (`atk_mg::AttackMiniGameTask`, msys list windows); the practice battles
  are `atk_pc_minigame_*` BAI scripts run by btl::Main (39 button loops, all `wait(1)`, 6 with `$7012`, no
  hard-coded `+= 2` timer).

## 7. BAI fix (implemented, staged in `work/fps60/build/bai/`)

**Where the file lives** (confirmed): only `romfs/BAI/BAI.dat` (v1.0 base, 2,862,248 bytes, sha256 `12be16cd…c2f2`).
The v1.2 update (`romf2/`) has no `BAI/`, and the Korean patch (`patch/00040000001CA900/romfs/`) has none either,
so the game runs the v1.0 file and the fix starts from it (BRIEF2 R2 resolution is coded in the tool). BG4 archive,
version 773, 543 entries, all BLZ-compressed, data 4-aligned from 0x4C7C. The game loads a script by name
(`btl::Main::loadAtkAI(main, "atk_pc_solo_jump.bai", 4)`, Battle.c), i.e. through the BG4 table, so changed
compressed sizes are fine; every changed script keeps its decompressed size.

**Tool** `scripts/fps60/btl_baifix.py` (Python, `.venv`):
- `identity`: `lib3dx.rebuild_bg4(src, {})` is **byte-identical** to the source (checked: True); BLZ recompression
  round-trips (sample of 11 entries; ndspy's output differs from Nintendo's bytes, as expected, so only changed
  entries are recompressed and all others keep their original bytes).
- `build [--groups hold,step2,orbit]`: for each site checks the exact original instruction text and bytes,
  checks the site is reachable from the script's entry points (fall-through + op003/op004 + every u32 code-offset
  parameter that lands on an instruction boundary), applies a same-length transform, rebuilds the BG4, then
  re-reads the output and asserts: same entry table (names, hashes, flags), same header and name block, same
  decompressed size and **identical instruction boundaries** in every changed script, and that the only changed
  instructions/bytes are the listed sites.
- `verify FILE`: the same comparison for any BAI.dat.
- Output: `work/fps60/build/bai/romfs/BAI/BAI.dat` (2,862,076 bytes, sha256 `c681a963…fbb6`), `diff.tsv`,
  `manifest.json`; scans `scan_counters.tsv`, `scan_waits.tsv`.

**Sites (15 in 9 scripts; default build = all three groups):**
| script | offset | group | old (bytes) | new (bytes) | 30fps | 60fps after fix |
|---|---|---|---|---|---|---|
| atk_dstar_4 | 0x3454 | hold | `$8012 = op025(2f)` `2500 00000000 1280 00000040` | `$8012 = op016($8012,$7012)` `1600 03000000 1280 1280 1270` | grace 8 frames = 267 ms | 16 frames = 267 ms |
| atk_dstar_x_4 | 0x3454 | hold | same | same | same | same |
| atk_koopa2_2 | 0x2B78 | hold | same | same | same | same |
| atk_koopax_2 | 0x2742 | hold | same | same | same | same |
| atk_dgeraco_5 | 0x298E | hold | same | same | same | same |
| atk_geraco2_4 | 0x2560 | step2 | `$8018 = op025(2f)` | `$8018 = op016($8018,$7012)` | wait `$707E` units | same ms |
| atk_koopax_5 | 0x4B82 | step2 | `$8011 = op025(2f)` | `$8011 = op016($8011,$7012)` | timeout `$8001` units | same ms |
| atk_geraco2_3 | 0x2E66 | step2 | `$8010 = op025(2f)` | `$8010 = op016($8010,$7012)` | interpolation 2/frame | same ms |
| atk_geraco2_3 | 0x2EC9 | step2 | `$8010 = op025(2f)` | `$8010 = op016($8010,$7012)` | toggle every 80 units | same ms |
| atk_dgeraco_4 | 0x22D8 | step2 | `$707e = op025(2f)` | `$707e = op016($707e,$7012)` | radius ramp to 192 | same ms |
| atk_dstar_4 | 0x2F7C | orbit | `wait(1)` `0500 00000000 0100` | `wait(2)` `0500 00000000 0200` | 7.4 deg/frame, 1.62 s/lap | loop every 33 ms, 1.62 s/lap |
| atk_dstar_x_4 | 0x2F7C | orbit | same | same | 8 deg/frame | same as 30 |
| atk_koopa2_2 | 0x27D8 | orbit | same | same | 6.8 deg/frame | same as 30 |
| atk_koopax_2 | 0x23A2 | orbit | same | same | 7 deg/frame | same as 30 |
| atk_dgeraco_5 | 0x25CF | orbit | same | same | 7.4 deg/frame | same as 30 |

Why each orbit loop qualifies for `wait(2)` (checked on the listing): it has exactly one `wait(1)`, no branch from
outside targets that wait, no call (op004 kind 1), no button read (`$7005..$700c`), no step-scaled update
(`$7012`-derived), and its exits test `$707D`/`$707E`, which are set by other threads and stay set (not one-frame
pulses). At 30fps every changed script behaves identically (both transforms are exact while the step is 2.0,
section 2.4). Residual (not fixed, needs an extra instruction or a C++ consumer change): `atk_dgeraco_4` 0x2391
radius ramp-down `-= 8`/frame to 64 (its loop also advances an angle by the step-scaled `$7081`, so `wait(2)` would
halve that angle speed at 60fps); `atk_dstar_2`/`_x_2` 0x28EB `+= 0.2`/frame to 4; the other "rate"/"angle" rows
of `scan_counters.tsv` (mostly cosmetic per-frame spins/scales in enemy attacks, see 2.5).

**Install (lead):** LayeredFS overlay file `romfs/BAI/BAI.dat` (new file in the patch; no CRO/CRR change, no code
change). Luma: `/luma/titles/00040000001CA900/romfs/BAI/BAI.dat`; Azahar: `load/mods/00040000001CA900/romfs/BAI/BAI.dat`.
The file is safe at 30fps (Old 3DS or opt-out tasks): identical behaviour there.

## 8. Why 60fps "breaks action commands", and what is left (summary)
- With the native fps mode chosen in D1 (the battle task created at mode 0, so `isFps30()` is false from the first
  frame), every action command is judged in 60 Hz units: object timers (op1d6/op1d7, `obj+0x374`), waits, `$7012`
  counters, C++ defense timers and animations all advance by the step (1.0 per frame at 60fps, 2.0 at 30fps).
  Basic attacks, Bros. attacks, Brawl attacks, Bowser's guard/counter, Mario/Luigi jump/hammer dodges and the
  battle timer keep their millisecond windows (sections 2.1, 3-6). Input is sampled 60 times per second, and the
  script loops that read a trigger poll it on every frame: 145 of the 155 button-reading loops contain only
  `wait(1)`; in 6 others the `wait(2)`/`wait(4)` sits in a sub-thread started by op04e (`atk_pc_sp_ml_ball`
  0x713A and 0x5D25, confirmed; the same code in `_easy` and `atk_pc_minigame_ml_ball`, likely), and the variable
  waits of the 4 remaining loops (Spin Pipe x3, `atk_pc_minigame_ml_taihou`) are in 60 Hz units at both rates, so
  a press that 30fps sees is also seen at 60fps.
- What really changed at 60fps in the shipped data (all fixed by `work/fps60/build/bai/romfs/BAI/BAI.dat`):
  1. five boss attacks (`atk_dstar_4`, `atk_dstar_x_4`, `atk_koopa2_2`, `atk_koopax_2`, `atk_dgeraco_5`) in which
     Mario/Luigi hold A/B (mask `$8014` = 1/2, chosen from `$7000` at 0x3111..0x316A in dstar_4): the release grace
     counts `+2` per frame, so a release of more than 133 ms (instead of 267 ms) ends the hold -> the "input does
     not register / hold breaks" symptom;
  2. in the same five attacks the boss orbits on an ellipse at a fixed angle per frame, twice as fast at 60fps;
  3. four other loops counting `+2` per frame (`atk_geraco2_4` wait, `atk_koopax_5` timeout, `atk_geraco2_3`
     interpolation/animation toggle, `atk_dgeraco_4` radius ramp).
- The cheat adds problems of its own that a native mode avoids: it flips the mode after the task was created at 30
  (engine.md 5/6), so the first frames of every battle run with the 30fps step, and Luma applies it every ~50 ms
  from another thread. The only public report (web.md R19) does not say which commands broke, so the mapping of
  the community symptom to items 1-3 is **likely**, not confirmed.
- Not fixed (60fps runs them faster in ms, same behaviour otherwise; mostly visual): per-frame spins/scales/ramps of
  `scan_counters.tsv` kinds `rate`/`angle` outside the five orbit loops (e.g. `atk_dgeraco_4` 0x2391 `-= 8`,
  `atk_dstar_2` 0x28EB `+= 0.2`), per-frame counters in `atk_uruhei_1` 0x2458 (random chance rises per frame) and
  `atk_zuttsun_1` 0x22E5 (counts frames to `$8012`), odd waits (16.7 ms shorter), `btl::ObjDropCoin::v3` 0x1D891C
  (`Frm::update(1.0)`, dropped-coin animation 2x), KeyContFrm (inert, 2.2). Fixing the script ones needs either an
  extra instruction (a relocating BAI assembler; decode coverage is ~95 %, so that needs more decoder work first) or
  a `wait(2)` that is only safe after per-loop review.

## 9. Patch points (BTL2)
| # | location | original | new | why | side effects |
|---|---|---|---|---|---|
| 1 | `romfs/BAI/BAI.dat`, 10 sites (section 7, group hold + step2) | `$v = op025(2f)` (`2500 00000000 vvvv 00000040`) | `$v = op016($v, $7012)` (`1600 03000000 vvvv vvvv 1270`) | per-frame `+2` written for 30fps becomes the step | none at 30fps (2.0); 60fps: same ms |
| 2 | same file, 5 sites (group orbit) | `wait(1)` (`0500 00000000 0100`) | `wait(2)` (`0500 00000000 0200`) | orbit loops advance a fixed angle per pass | none at 30fps; 60fps: orbit updates at 30 Hz, same ms |
| 3 | static/CRO battle code | — | none needed | every C++ battle timer found uses the step | — |
| 4 | optional, not built: `scripts/fps60/btl_baifix.py` FIXES list | — | add rows | residual list of section 8 | review each loop first |

## 10. What RT2 should verify (BTL2 prepared files only; R4)
1. **Loading:** install `work/fps60/build/bai/romfs/BAI/BAI.dat` into the test instance's mod folder (via the
   `rt_mods.py use-build` overlay: copy to `<build>/romfs/BAI/BAI.dat`), boot, start any battle (first field
   battle), and confirm the LayeredFS log line for `BAI/BAI.dat`, normal enemy turns and action commands (jump on
   the first Goomba: Excellent with the usual timing), no crash. Expected: identical to the unpatched game at 30fps.
2. **Step value:** in a battle at mode 0, read the float at `btl::Main+0xBA15C` (`btl::Main` = `[0x3F3600]`, i.e.
   `[0x3F35F8+8]`, the pointer the battle code reads as `DAT_003f3600`): 1.0 at 60fps, 2.0 at 30fps;
   `Main+0x8A3C` and `[[Main+0x574]+0x7C]` = 1.0.
3. **Hold attacks (needs a late save):** Dark Star `atk_dstar_4` / Dark Fawful `atk_dgeraco_5` / the Bowser
   `koopa2`/`koopax` hold attacks: release the held button for ~200 ms. Expected: at 30fps and at 60fps with the
   fix the hold continues; at 60fps without the fix it ends (grace 133 ms). Orbit: one lap takes about 1.6 s at both
   rates with the fix (0.8 s at 60fps without). (A GDB breakpoint on op016's handler 0x133900 is not useful: op016
   runs thousands of times per battle and the decoded record does not keep the source variable ids.)
4. **Regression at 30fps:** the same attack at 30fps with and without the fix must look and play the same.

## 11. Open questions
- Which encounters run the nine changed scripts (dstar = Dark Star, dgeraco = Dark Fawful, geraco2 = Fawful's
  second form, koopa2/koopax = Bowser as an enemy, `_x` = the harder variant): guessed from the names; confirm from
  the battle data or at runtime.
- `$707C..$7083` are attack work registers shared between the threads of one attack; their C++ consumers (op118,
  op11e, ...) were not traced. If a C++ side reads `$707E` as a per-frame rate (orbit radius in `atk_dgeraco_4`), it
  is step-independent and runs 2x at 60fps on its own.
- The victory slow-motion is the only phase where `$7012` != 2.0 at 30fps; none of the fixed scripts runs there,
  but this was inferred from the script names and the writers of `Main+0x8A3C`, not traced per script.
- The `rate`/`angle` rows not fixed (section 8): decide whether visual 2x speeds in enemy attacks matter enough to
  build a relocating BAI assembler.
