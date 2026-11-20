# STAR — Bros. Attack 스타&스타 (こいこいスター) at 60fps: why it drags, and candidate fixes

Worker STAR, wave 5, 2026-10-30. Static analysis only (no emulator). Confidence tags: **confirmed** (read in
code/data here), **likely**, **guess**. Addresses: static = runtime; Battle.cro = analysis address (base
0x11000000, file offset = addr − 0x11000000). Script offsets = offsets inside the decompressed `.bai` file.
Tools and raw outputs: `work/fps60/star/` (`star_ops.py`, `star_calls.py`, `star_hand.py`, listings `*.dis.txt`).

STATUS: §0–§5 by STAR (static, cut off); **Part 2 (§6–§11, STAR2) is complete and corrects §4**: the drop/hit sequence
is not frame-rate dependent, but the throw cycle of the collect phase is (20 vs 22 units); fix `work/fps60/build/v3b`.

## 0. The attack's script

- 스타&스타 = `atk_pc_sp_ml_star.bai` (normal) and `atk_pc_sp_ml_star_easy.bai` (easy mode), 42,176 bytes each
  (decompressed), in `romfs/BAI/BAI.dat` (v1.0 base; neither the v1.2 update nor the Korean patch has its own copy;
  the shipped `BAI.dat` fix (v2) leaves both scripts byte-identical: they are not among the 15 BTL2 sites).
  **confirmed** (`btl_bai.py list`, `work/fps60/build/bai/diff.tsv`).
- The two scripts have the same instruction layout and differ in 14 immediates only (start heights, window sizes,
  star count limits 22 → 24, etc.) **confirmed** (`star.dis.txt` vs `star_easy.dis.txt`).
- 0x0050..≈0x2300 is the shared Bros.-attack library (identical to `atk_pc_sp_ml_koura` up to 0x1AF5); the
  attack itself is 0x2300..0xA4C0; entry `op004(0, 0xA015)` at 0x0050.

## 1. Opcode map used by the attack (Battle.cro handlers, `star_calls.py`)

| ops | handler → C++ | role |
|---|---|---|
| op165 / op169 / op16a | 0x11058F50 `btl::Main::entryDfxPos`; 0x11046EEC / 0x11049678 `btl::Main::entryDfxObj` | spawn a dfx effect at a position / on an object |
| op16e / op16f | 0x110497B4 / 0x110506AC `btl::Main::entryDfxShake` | spawn an effect + screen shake |
| op172 | 0x1104EBF8 `btl::Main::entryDfxFollowObj` | spawn an effect that follows an object |
| op174 | 0x11057CCC `ad::dfx::Unit::kill` / `killForce` | kill an effect |
| op17f / op17e / op181 | 0x1104450C / 0x11044350 / 0x1104D9B8 | effect params (speed `FrmFixed::setSpd`, frame, pause, attach, LCD) |
| op19c / op19d / op19e | 0x110457B4 / 0x11047544 `btl::Main::playSeObj`; 0x11057304 `btl::SeTask::stop` | sound effects |
| op0bb / op0b9 / op233 | `btl::ChrDmgParam` fields; `btl::ChrPc::DoDamageML`; `btl::ChrMon::playDmgAnm` | damage |
| op117 / op118 / op119 / op12f / op134 / op103 / op107 / op10b | 0x11029880 (`MoveVBase::move/moveFrm`), 0x11029AE4 (`MoveVBase::jump*`), `MoveV1/V3/C…ByCurveType` | object motion (step-driven) |
| op1e5 / op1e7 / op1e8 / op1ee / op1f0 | `btl::Camera::movePos/moveTwist/moveWidth/...` | camera |
| op0af / op0b3 / op065 / op066 / op072 | `Main::allocObjBySlot+entryObj`, `freeObjOnSlot`, `loadCA`, `loadMdl`, `loadDfxSymbolArray` | objects / resources |
| op1da..op1e4 | `btl::AI2DArray` | script-side arrays (star lists) |
| op005 | `wait(n)` (60 Hz units, battle.md §2.4) | |

(Full list with every callee: `work/fps60/star/star_opcalls.txt`.)

## 2. Engine facts this analysis relies on (from earlier reports, re-read)

- No time-step compensation in `ad::fw::TaskBase::func` 0x13DBCC: one `funcCalc` per presented frame, fixed step
  (1.0 at mode 0, 2.0 at mode 1). A mode-0 frame that needs more than one vsync (≈16.7 ms) is shown for two
  vsyncs and the game advances only 1/60 s in that 1/30 s → **slow motion**, no skipped logic (`engine.md` §4).
- Battle step s19 = `(isFps30?2:1) × [[Main+0x574]+0x7C] × Main+0x8A3C`; AI waits count whole 60 Hz ticks
  (`battle.md` §1.2, §2.4).

## 3. What runs during the attack (script flow, confirmed from the listing)

Main thread 0xA015: sets up four `AI2DArray`s (`$7114`..`$7117`), creates object 0x30008 and starts on it the
**position-history thread 0x9F50** (every frame, `wait(1)`: rotate `$7117` by 2, store the big star 0x30009's x/y;
it records per frame, so at 60fps the 90-entry history spans 1.5 s instead of 3 s — cosmetic, only used for a
trail), then calls the phases in order:

| call | phase | per-frame loops (`wait(1)`) | effects / sounds |
|---|---|---|---|
| 0x3A50 | intro (bros jump in, camera) | — | — |
| 0x4160 | big star appears, catch phase setup | 0x4AB9–0x4C6C, 0x4EB6–0x57FB, 0x5956–0x5F3C (state machines; effects only on state changes) | follow effects 0x48D..0x493 on 0x30009, shakes 0x565 |
| 0x7850 | **collect**: Mario/Luigi threads 0x71F1 poll A/B every frame (`$7006`), small stars 0x6885–0x6AEF / 0x6C68–0x7055 | button polls | catch effects 0x497/0x498 + shakes 0x4A3/0x59F (one set per caught star) |
| 0x9379 | big star rises (`op119` 50 units, `op119` 40 units, spin `op103` 20+20) | — | follow 0x494/0x495 |
| 0x974E → 0x994B → **0x8FA5** | **drop + hits** | falling poll 0x88BC–0x8920 (no work), history 0x9F56 | per group hit: see below |
| 0x9CC7 | end (`wait(30)`, `op165` 0xFB, camera to default, bros return) | — | — |

Drop routine 0x8FA5: the big star (type 0) and then the collected stars (`$7085` of them) are dropped as
groups of up to 7 (`op203` attaches the 6 followers to the group leader, positions from table 0x1B58), each group
started as thread 0x871D with a start delay `$3001` that grows by **30 units (0.5 s) per group**. Thread 0x871D:
`wait($3001)`; follow effect 0x499; `op12f` fall (gravity −0.1, 90 units); poll every frame until the star
reaches the target's height; then hit function **0x7CA6**; then the stars bounce away (0x854D: `op12f` jump +
`op118` 80-unit move + `op103` 80-unit spin, **all 7 stars of the group keep moving after the hit**).

Hit function 0x7CA6 (once per group, confirmed): `op0bb`×11 damage parameters → `op0b9` `btl::ChrPc::DoDamageML`
(damage, damage number, enemy reaction) → optional `op0cc` status (`entryAbnormalWithRoll`) → one SE
(0x1301AA/AC/AE) → by rank/type **1–3 dfx** (0x49A + attach + thread 0x1FFE that turns on
`btl::Main::setEnableChrMdlXlu` until the effect ends; or 0x49F + 0x4A0; or one of 0x49C/0x49D/0x49E) →
optional second-target dfx 0x49A on 0x30000 → **`op16f` screen-shake effect** 263..266 or 1179.

So the heavy moment the user describes (stars dropped on the enemy, several hits in a row) is: a new group hit
every 0.5 s, each adding 1–3 particle effects, a shake, a damage number and an SE, while up to 7×N star models
(each with its own follow/trail effect 0x499) and all earlier effects are still alive and moving.

## 4. Is anything in this attack frame-rate dependent? (logic timing)

- **No constant per-frame counter** in any `wait(1)` loop of the script (`btl_timing.py counters` lists no row for
  `atk_pc_sp_ml_star*`; my loop table `work/fps60/star/star_loops.txt` agrees). 12 updates are scaled with the
  step `$7012` (0x4B6A, 0x4EDA, 0x4EF0, 0x4FE8, 0x5024, 0x5721, 0x5CBA, 0x5CD4, 0x5D55, 0x7012, 0x7028, 0x971B).
  **confirmed**
- Every wait is even (`wait(1)` polls, `wait(0x12/0x14/0x1E)`, `wait($var)` with 60 Hz values), every motion
  is a C++ mover (`MoveVBase::move/moveFrm/jump*`, `MoveV1/V3/C…ByCurveType`) advanced by the battle step, so
  phase lengths are the same in seconds at 30 and 60fps. **confirmed**
- Effects are spawned only on events (per caught star, per group hit), never once per frame, so the number of
  live effects does **not** double at 60fps. Effects and particles are advanced with the battle step:
  `btl::Main` calc passes s19 (the step) to the particle/effect updaters at 0x28C160 (`bl 0x238A68`), 0x28C16C
  (`bl 0x2A1ACC`), 0x28C17C (`bl 0x24D0C4`) and `Frm::update` 0x28C198. **confirmed**
- No slow motion or hit-stop is used by the attack: the battle time scale `Main+0x8A3C` is written only by
  `btl::TaskBtlResultPcWin` (victory, Battle.c lines 19383/21987/22871), the AI write of `$7011` (not used by this
  script) and its reset FUN_001EAAF0; the dfx speed `[[Main+0x574]+0x7C]` is only ever set to 1.0 (static.c lines
  191892, 424470, 445489). **confirmed**
- The only 60fps difference in the script is cosmetic: the 0x9F50 position history fills twice as fast.

⇒ **(a) logic timing is not the cause.** At 60fps the attack's logic runs at the same speed in seconds as at 30fps.

> STAR2 correction (§7): true for the drop/hit sequence, but the collect phase has two one-frame AI hand-offs per
> throw (throw cycle 20 units at 60fps vs 22 at 30fps), so more stars are caught and more drops follow; fix §8/§10.

## 5. Why it drags on a real New 3DS (hardware load) — confirmed mechanism, likely trigger

Mechanism (confirmed in code):
1. `TaskBase::func` 0x13DBCC runs `funcCalc` exactly once per frame with a **fixed** step (1.0 at mode 0). At the
   end it swaps (0x13E6BC/0x13E6C8), stores `+0x18C = nngxCheckVSync(0x400)` (0x13E6D4) and waits for the next
   vsync (0x13E74C). Mode 1 adds one more vsync wait (0x13E494..0x13E4EC) → 2 vsyncs per frame.
2. `nngxCheckVSync(0x400)` 0x27EFF8 returns `[0x429090+0x154]`, which the GSP vsync handler 0x112F08 increments by
   one per top-screen vsync (after calling the engine's vsync callback). So `+0x18C` is "vsync number of the last
   swap", and the difference between two frames is how many vsyncs the previous frame took.
3. The command list of frame N runs on the GPU during frame N+1 and is waited for before frame N+1's swap
   (2-stage pipeline, `engine.md` §3). A frame therefore takes 2 vsyncs as soon as **either** the CPU part
   (calc + list building) **or** the GPU part of one frame needs more than 16.7 ms.
4. Nothing measures that: the next frame again advances only 1/60 s. While the overload lasts the game shows 30
   images per second **and** runs at half speed. At 30fps (mode 1) the budget is 33.3 ms, so the same scene
   never slowed down in the shipped game.

Trigger (likely): the drop/hit phase is the heaviest moment of the attack — many star models with trail effects,
several particle effects and a screen shake per group hit, damage numbers, `setEnableChrMdlXlu` (characters in the
translucent pass while 0x49A plays), on top of the battle scene. The PICA200 GPU of the New 3DS has the same clock
as on the Old 3DS (only the CPU is faster), and Azahar renders on the PC GPU instantly (`REPORT.md` §4), so an
emulator run can show 60 FPS here while hardware cannot. The old cheat also forces mode 0 with the same fixed step
and shows the same kind of drag (user report), which fits a load problem and not a script problem.
Which side (GPU fill, GPU vertices, or CPU spikes when `DoDamageML`/`entryDfx*` create objects) is the larger part
cannot be decided without hardware timings: **guess** = GPU fill from overlapping additive particle quads and the
extra translucent character pass; both lead to the same symptom and the same fix (§6).


---

# Part 2 (worker STAR2, 2026-10-30, continuing STAR): runtime measurement of the drop/hit sequence and fix

STATUS: complete (result §11). Inputs: RT5 `work/review/rt5_20261030/RT5.md` §3 (demonstration
impact → 「EXCELLENT!」 = 331 btl frames at 60fps in 3 cycles vs 117/102 frames = 234/204 60-Hz units at 30fps,
Azahar at full speed). That overturns §4's conclusion "(a) logic timing is not the cause" for the demonstration at least.
Tools: `work/fps60/star/star2_bp.py` (multi-breakpoint logger on Battle.cro AI op handlers, frame counter per hit).

## 6. What decides the length of "impact → EXCELLENT" (static, confirmed from the listing)

- 「EXCELLENT!」 is `op1d8` = `btl::Main::entryEstimate` (handler Battle:0x1104C9D4) in subroutine **0x38AC**
  (`if ($8000 > $706f) { $706f = $8000; if ($8000) op1d8($7004, $8000, -30, 80, 300, 0) }`). The only caller is the
  drop thread 0x871D at 0x8D36, executed only by the thread whose `$3002 != 0`, i.e. the **last group** (0x9361 sets
  `$3002 = 1` on the last thread started by the drop routine). The rank `$8000` = `$8020` of call 0x2983(`$7085`):
  `$7085 >= 21` → 5 (EXCELLENT), `>= 15` → 4, `>= 10` → 3, `>= 6` → 2, else 0.
- The call sits right after that thread's hit (0x892B `call 0x7CA6`, which has no wait: its only call, 0x1FFE, starts
  a separate thread on 0x30005 and returns). So 「EXCELLENT!」 appears in the frame of the **last group's hit**.
- Drop routine 0x8FA5 (called once from 0x9A85): big star 0x30009 = type 0, delay `$3001` = 0; then for the `$7085`
  caught stars `floor(S/7)` groups of 7 (type 1, leader + 6 followers attached with `op203`) and `S mod 7` single stars
  (type 2), each started with delay +30 (`$8016 += 30`, 0x908B/0x92A8/0x933C). All start at the same point
  (`op11e` to target x, target y + 500, target z) and run the same thread 0x871D: `wait($3001)` → SE + trail effect →
  `op12f` fall (`jumpFT`, dy = −y, 0.1, 90) → poll `wait(1)` until `y <= target top` (0x88E1) or motion end → hit.
- So, if every group falls alike: impact (big star hit) → EXCELLENT (last hit) = 30 × (number of drop threads − 1)
  + (fall of the last − fall of the first). Number of drop threads G = 1 + floor(S/7) + (S mod 7), e.g. S = 24 → 7,
  S = 25 → 8, S = 34 → 11. The hit phase therefore depends on how many stars the demonstration caught (`$7085`),
  and on any per-group timing difference. Both are measured below.
- The demonstration is the same script in auto-play: `$7067` = `(Main+0x17B0 & 0x40) && Main::isEnableAutoPlayMode()`
  (AISys read switch, Battle.c `case 0x7067`), copied to `$7082` at 0xA24A. Auto-play code: the yellow star chases
  the big star with `4 × $7012` per frame (0x5CEB..0x5DAA, step-scaled), and each bro's thread 0x71F1 throws
  (call 0x70D5) when the big star's colour is his and the yellow star is within 42 of it (0x727A..0x7479), polled
  every frame (`wait(1)` at 0x7484).

## 7. Measurement in Azahar (demonstration, T1 bed) — confirmed

Builds: `v3_ref60` = Korean patch romfs (with the shipped BAI fix) + shipped `code.ips` (`work/fps60/build/v3_ref60/`
holds only a copy of `v2/code.ips`, sha256 `e5aa7d60…998a`); `star2_30` = the same romfs without code (30fps).
T1 bed installed into both (`tb_build.py install t1_battle`). Logger `star2_bp.py run` with breakpoints on the
handlers of op0b9 (`DoDamageML`, one per drop-group hit), op1d8 (`entryEstimate` = 「EXCELLENT!」) and op12d..op135
(`MoveVBase::jump*`: fall start, bounce, star hops); each hit records btl::Main +0x578 and the 60-Hz clock `$7013`
(btl::Main+0x8A40), the LocalEvent PC, `$3000..$3003` and `$7085` (AISys+0x184). Logs `work/fps60/star/logs/`,
classifier `star2_ana.py`.

| run | stars caught `$7085` | drop threads G | group start delays (units) | fall start → hit, every group | first hit → last hit = EXCELLENT |
|---|---|---|---|---|---|
| 60fps `ref60_demo1.jsonl` | **47** | 12 (1 + 6×7 + 5 singles) | 0, 30, …, 330 | 88 | **330** (EXCELLENT in the frame of the last hit) |
| 30fps `ref30_demo1.jsonl` | **43** | 8 (1 + 6×7 + 1 single) | 0, 30, …, 210 | 88 | **210** |

- The drop/hit sequence is **identical in 60-Hz units** at both rates: group delays 30, fall 88, hits 30 apart,
  「EXCELLENT!」 in the frame of the last hit. RT5's 331 (60fps) and 204/234 (30fps) are G − 1 = 11 and 7/8 drops
  × 30 units (RT5's ±0.15 s grab spacing). **No segment of the drop/hit sequence is frame-rate dependent.**
- The difference is the number of stars the demonstration caught: 47 vs 43, and the drop's grouping
  G = 1 + ⌊S/7⌋ + (S mod 7) turns +4 stars into +4 drops (+120 units). The grouping is not monotonic
  (S = 43 → 8 drops, 47 → 12, 49 → 8), so for the same S the hit phase has the same length at 30 and 60fps.
- Why 47 vs 43 — the throw cycle (confirmed, `ref60_demo2.jsonl` with an SE breakpoint, `star2_ana.py --timeline`):

| event (one cycle of the throwing bro) | 60fps (units) | 30fps (units) |
|---|---|---|
| hand refilled (thread 0x30A4 after `wait(0x12)`: SE 0x13019E at 0x321B, `op1b9($3000, 0, star)` at 0x3234) | T | T |
| throw (bro thread 0x71F1 → 0x70D5, SE 0x1301A2 at 0x7192; hand cleared at 0x70F8) | T + 1 | T + 2 |
| reload starts (reload thread 0x4AB3 sees the empty hand → 0x3263 → new thread 0x30A4: jump `op12f` at 0x31A2) | T + 2 | T + 4 |
| hand refilled again (`wait(0x12)` = 18 units) | **T + 20** | **T + 22** |

  The cycle has two one-frame hand-offs between AI threads (hand set → the bro's poll; hand empty → the reload
  thread's poll / the new thread's first run). A frame is 1 unit at 60fps and 2 units at 30fps, so the cycle is
  20 instead of 22 units (−9 %). The demonstration throws whenever its colour/distance test passes, so it is limited
  only by this cycle: throws per colour phase 13, 14, 13, 7 at 60fps vs 11, 13, 13, 7 at 30fps (reload events
  `to_hand` in the two logs), 47 vs 43 caught, none missed. Every other timer in the collect phase is step-scaled (replenish `$8013 -= $7012`
  36 units, `$708a -= $7012`, yellow-star speed `4 × $7012`).
- Real play: a player can only throw when the hand is full, so a player mashing A/B also gets ≤ 1 throw per 20 units at
  60fps vs 22 at 30fps (≈ +10 % stars at most); the hit phase for a given number of stars is unchanged.
- Consequence for the user's report: the drop/hit phase has no logic slowdown. The "drag while the enemy is hit"
  on a real New 3DS remains STAR §5's frame-time overload (cause (b)), which Azahar cannot show. The 60fps cadence
  makes a fast player collect a few more stars, i.e. a few more groups and objects in that phase.

## 8. Fix `v3a`: restore the 22-unit throw cycle at 60fps (BAI data only, exact at 30fps)

Where the two lost units can be put back without changing 30fps: any `wait(n)` costs `n` frames at 60fps but
`ceil(n/2)` frames at 30fps, so a one-frame hand-off cannot be lengthened at 60fps with a constant wait without also
lengthening 30fps. A wait whose length depends on the step can: `wait(4 / $7012)` is `wait(2)` = 1 frame at 30fps and
`wait(4)` = 4 frames at 60fps. Splitting the reload thread's `wait(0x12)` into `wait(0x10)` + `wait(4 / $7012)` gives
8 + 1 = **9 frames at 30fps (unchanged)** and 16 + 4 = **20 frames at 60fps** (was 18): cycle 20 + 2 = 22 units.

The extra instructions need 24 bytes. They come from thread 0x30A4 itself, so no offset outside 0x30CE..0x31DA moves
(tool `work/fps60/star/star2_baifix.py`, both `atk_pc_sp_ml_star.bai` and `_easy.bai`, identical region bytes):

| original | new | bytes | why the result is the same at 30fps |
|---|---|---|---|
| Mario branch `$8012 = op025(1f)` (0x30F8) + Luigi branch `$8012 = op025(1f)` (0x3127) | Mario's branch jumps to Luigi's copy (new merge point 0x311B) | −12 | both branches add 1 to z; x and y are independent |
| `$1006 = op017($8011, $1007)` (0x3196), `op12f(…, $1006, …)` | dropped; `op12f($7000, 1, $8014, $8013, 18f)` | −12 | `$8014 = $8011 − y` (0x313F) and `$1006 = $8011 − y` use the same two values (y read by `op0d3($7000, 0x100c)` twice in one frame with only arithmetic between) |
| `$8013 = op025(30f)` | `$8013 = op016($8013, 30f)` | +2 | the same IEEE add (a + b = b + a) |
| `wait(0x12)` | `wait(0x10)`, `$1005 = op019(4f, $7012)`, `wait($1005)` | +22 | 30fps: 8 + 1 = 9 frames; 60fps: 16 + 4 = 20; `$1005` is a temporary written before every other read in the script |

Checks (`work/fps60/build/v3a/bai_verify.txt`, RESULT: ALL BAI CHECKS PASSED): source = shipped BTL2 file
(sha256 `c681a963…fbb6`, zero-change rebuild byte-identical); exact original text of the region and its neighbours;
encoder round trip of every original instruction; same region length (0x10D bytes); no decoded code offset and no raw
4-byte word anywhere in the script points inside the region except the four rewritten branch targets (raw hits only at
0x30DC/0x310B/0x3159/0x316E = those fields); the new region decodes to the expected text and is reachable from 0x30A4
(started by `op04e($8010, 0, 0x30a4)` at 0x32F2); nothing outside the region lost reachability; instruction
boundaries and bytes outside the region unchanged; BG4 entry table, header and name block equal; the other 541 entries
stored byte-identical; op005 model 9 → 9 frames (step 2) and 18 → 20 (step 1).
Output `work/fps60/build/v3a/romfs/BAI/BAI.dat` 2,861,896 bytes, sha256 `d44d656bd0504585950c737b0390d51c0d77f1632306d400bd0f6c475c16389e`.
The code patch is unchanged from v2 (rebuilt into the same folder by `build_fps60.py --tag v3a --credits-fix
--field-vm30 --out work/fps60/build/v3a`, see §9).

Side effects: the first fill of each bro's hand at the start of the attack (0x3263 with `$3001 = 1`, 0x4658) uses the
same thread, so at 60fps it completes 2 units (33 ms) later; it happens ≈ 115 units before the first throw is allowed,
so nothing waits on it. Real play: the hand refills 2 units later at 60fps, i.e. a mashing player gets the 30fps
maximum of one throw per 22 units again.

## 9. `v3a` in Azahar (60fps, `rt_mods.py use-build v3a --ips` + T1) — confirmed

- Code: `build_fps60.py --tag v3a --credits-fix --field-vm30 --out work/fps60/build/v3a` rebuilt the v2 code with
  every check (`v3a/verify.txt`: RESULT: ALL CHECKS PASSED); `code.ips` sha256 `e5aa7d60…998a`, `code.bps`
  `c3922b9d…05be2`, `patched.code.bin` `4bd714f2…a7e2` = v2 byte for byte (the builder also writes `code.bps`; ship
  only `code.ips`, as for v2). Boot log: `ApplyCodePatch … /mods/00040000001CA900/exefs/code.ips patching code.bin`,
  `LayeredFS replacement file in use for /BAI/BAI.dat` and `/FEvent/FEvent.dat`, `System_IsNew3ds: true`.
- Throw cycle (`v3a60_demo1.jsonl`, reload thread's `op12f` now at 0x318C, next 0x319D): **22 units between every two
  reloads** in all four colour phases (40 of 40 gaps), as at 30fps; before the fix 20.
- Stars caught / impact → EXCELLENT, 60fps `v3a` (`v3a60_demo1.jsonl`, `v3a60_hits.jsonl`, 3 complete cycles):
  45 / 270, 45 / 270, 44 / 240 units. Reference 30fps: 43 / 210 (mine), RT5 204 and 234 (= 43 / 210, 44 / 240).
  Unfixed 60fps: 47 / 330 in 4 of 4 cycles.
- Per colour phase (v3a 60fps vs 30fps reference, throws): 12/11, 13/13, 13/13, 7/7. The extra throw sits at the end of
  phase 1: its 12th throw is 242 units after the first, which the 30fps window just misses.
- The demonstration's throw window is `$708a >= 50` (0x727A, auto-play branch only; real play jumps from 0x726F to
  0x7484 and never reads `$708a`). `$708a` is set to 305 (0x4D55) or 325 (0x5555) and decremented by `$7012` every
  frame (0x4FE8): at 30fps it only takes odd values, so `>= 50` acts as `>= 51` and the window is 254/274 units; at
  60fps it reaches 50.0 and the window is 1 unit longer. This is the one odd-start timer compared with an even
  threshold in the collect phase; the others start even (`$801c` 120, `$7089` 26, reload `$8013` 36) and compare with
  0, which is the same on both grids. → `v3b` adds `op003(5, $708a, 51f, …)` (exact at 30fps, demonstration only).

## 10. `v3b` (= v3a + `$708a >= 51`) in Azahar, 60fps — confirmed

Build `work/fps60/build/v3b/`: `romfs/BAI/BAI.dat` 2,861,904 B sha256 `8f3c1928b91f3b851c3f437bd06a0a200663822538967491a83794f025827261`
(`bai_verify.txt`: RESULT: ALL BAI CHECKS PASSED; per script 146 plain bytes differ, inside 0x30CE..0x31DA and the
float at 0x7283..0x7286; every write to `$708a` in both scripts is `op015(odd)` or `op026($7012)` (normal 305/325,
easy 325/345); the only read is the window test; 0x722C sends only auto-play there), code = v2 byte for byte
(`v3b/verify.txt` ALL CHECKS PASSED, `code.ips` `e5aa7d60…998a`). Other scripts that write `$708a` (monster
libraries, other attacks: `btl_bai.py var 0x708a`) do not run during the player's attack, so `$708a` stays odd at
30fps in this attack (likely; the window test is auto-play only either way).

Logs `v3b60_hits2.jsonl`, `v3b60_detail.jsonl`, `v3b60_detail2.jsonl` (`--work` records `$706c..$70ab` at each hit):

| cycle | throws per colour phase | stars | impact → EXCELLENT |
|---|---|---|---|
| detail 1 | 11 (first reload at `$708a` 289), 13, 13, 7 | 44 | 240 |
| detail 2 (prev. cycle) | (12), 13, 13, 7 | 45 | 270 |
| detail 2 (next cycle) | 12 (first reload at `$708a` 297), 13, 13, … | — | — |
| hits2 | — | 44, 45 | 240, 270 |

- Reloads now come exactly every 22 units, and inside a phase at `$708a` = 323, 301, …, 59 (phases 2–4: the bro throws
  in the frame after the colour switch sets 325), the same 13 throws as at 30fps. Phase 1 starts at 305 and its count
  depends on how soon the yellow star first reaches the big star: first throw at 290 → 11 throws, at 298 → 12. With
  the window at 51 both grids give the same count for every first-throw time τ (60fps: ⌊(254 − ⌈τ⌉)/22⌋ + 1, 30fps:
  ⌊(254 − 2⌈τ/2⌉)/22⌋ + 1; they could only differ if ⌈τ⌉ were odd and 254 − ⌈τ⌉ a multiple of 22, which is impossible).
- So after the fix the demonstration's star count (43–45) is decided by the random start of phase 1, as at 30fps;
  the hit phase is 210, 240 or 270 units accordingly (RT5's 30fps 204/234 are two of these). Before the fix every
  60fps cycle had 47 stars / 330 units.

## 11. 30fps checks, spot check, result — confirmed unless marked

30fps runs (logs `ref30_demo1`, `stock30_hits2` = shipped BAI; `v3b30_detail`, `v3b30_hits1` = v3b BAI, no code):

| build (30fps) | stars per cycle | impact → EXCELLENT (units) |
|---|---|---|
| shipped BAI (`star2_30`) | 43, 45, 45 | 210, 270, 270 |
| v3b BAI (`v3b30`) | 45, 43, 45, 44 | 270, 210, 270, 240 |

- With the v3b BAI at 30fps the reload thread still runs every 22 units and the reloads sit on odd `$708a` values
  (295, 273, …, 53; 321, …, 57): the step-dependent wait gives 1 frame and the window test behaves as before.
- **The 30fps game itself varies between 210, 240 and 270 units** (43–45 stars; phase 1 gets 11 or 12 throws depending
  on how soon the yellow star first reaches the big star, a random start). RT5's 204/234 were two of these. The
  shipped 60fps build was always 330 (47 stars); `v3a`/`v3b` at 60fps give 240/270 (44/45 stars), inside the 30fps set.
- Spot check (60fps `v3b`): 초록등껍질 demonstration (`koura60` burst, contact sheet in scratch) shows the normal
  GOOD!/GREAT!/EXCELLENT! sequence and the final hit; btl::Main counter 59.74 frames/s. Every other script in BAI.dat is
  stored byte-identical to the shipped file, so other attacks cannot differ.

Result:
1. The drop/hit sequence of 스타&스타 has no frame-rate-dependent timing (§7). RT5's longer hit phase at 60fps came from
   the demonstration catching 47 instead of 43–45 stars, which the drop turns into up to 4 extra half-second drops.
2. The frame-dependent part is the throw cycle (two one-frame AI hand-offs, 20 vs 22 units). `v3a` restores it exactly
   (BAI only, 30fps unchanged); `v3b` also aligns the demonstration's throw window (`$708a >= 51`). Recommended build:
   **`work/fps60/build/v3b`** (install `code.ips` = unchanged v2 + `romfs/BAI/BAI.dat`). README there.
3. In real play the fix only lowers the maximum throw rate at 60fps back to the 30fps value (≤ 10 % fewer stars for a
   player who mashes at the limit); for the same number of stars the hit phase is the same at 30 and 60fps.
4. Not fixed, not measurable here: the slowdown the user saw on a real New 3DS while the stars hit is most likely
   frame-time overload (§5: fixed step, a frame over 16.7 ms is shown twice and the game runs at half speed). The fix
   removes up to ~4 extra drop groups (7 stars each with trails/hit effects) from fast 60fps play, which lowers that
   load in the longest cases, but a hardware test is needed to know whether the remaining load still drops frames.
   Suggested real-HW check: 스타&스타 demonstration on a New 3DS with v3b vs v2, watch the hit phase for stutter.

Instance restored (2026-10-30 23:40 KST): emulator stopped; T1 removed from `star2_30`, `v3_ref60`, `v3a`, `v3b`,
`v3b30` (test copies rebuilt clean, all `*.tb_backup` empty); `rt_mods.py use-patch` → junction to
`patch/00040000001CA900`, 38 files, MainMenu.cro `1F227C75…BAFC`, ok; ML3R_000/001/002.sav, `00000001.metadata`,
`qt-config.ini`, `custom/00040000001CA900.ini` hashes equal to RT5 §0 (unchanged); no cheats; no logger running.
`patch/` and `work/sd_package/` were not touched.

STATUS: complete.
