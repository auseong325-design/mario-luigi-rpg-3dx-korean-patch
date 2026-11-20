# HB — HugeBattle.cro (giant Bowser battles) at 60fps

Worker HB, 2026-10-30. Target: 3DX JP v1.2 (`3dx_v12`). Status: IN PROGRESS (written incrementally).

Conventions: static addresses are runtime addresses (code.bin offset = addr − 0x100000). HugeBattle addresses are
the crolink **analysis** addresses (module base 0x12800000, so `HugeBattle+off` = addr − 0x12800000 = CRO file
offset). Tools: `scripts/fps60/armdis.py 3dx_v12 ...`, listing `work/fps60/dis/3dx_v12/HugeBattle.s`.
Ghidra dumps: not READY when this work started (`work/fps60/TOOLS_STATUS.md` absent).

HugeBattle.cro layout (link.json): text 0x12800180–0x12961034 (0x160EB4), rodata 0x12962000 (0x184B0),
data 0x129C6620 (0x1A14), bss 0x129C9000 (0x480C0). Exports: `EntryTask` 0x128014DC, `nnroControlObject_` 0x12949284.

## Findings log (appended as work proceeds)

### F1. Task creation and fps mode — confirmed

`HugeBattle:EntryTask` (0x128014DC, `HugeBattle+0x14DC`):
```
128014f4  bl ->operator new(0xF04, gMemAlc)          ; task object 0xF04 bytes
12801500  bl ->hb::GetBootInfo                        ; static 0x16C8D0, 4-byte boot info at 0x3F61BC
1280150c  bl 0x128021F0                               ; hb::HugeBattleSystem ctor (vtable 0x1296D9F4, RTTI N2hb16HugeBattleSystemE)
1280151c  b  ->TaskMan::entry(gTaskMainMan, task)
```
`hb::HugeBattleSystem` derives directly from `ad::fw::TaskBase` (typeinfo 0x12965ED0, base pointer at +8 = `_ZTIN2ad2fw8TaskBaseE`).
It is the **only** `ad::fw::TaskBase` HB creates (the only `TaskBase::init` / `InitParam` veneer calls are in this ctor).
Inside the ctor (`HugeBattle+0x23F4`):
```
128023f4  add  r0, sp, #0x10
128023f8  bl   ->ad::fw::TaskBase::InitParam      ; +0x30=1, +0x31=0, +0x32=1, +0x33=1, +0x34=1 (static 0x24B240, 0x114094)
128023fc  strb r7, [sp, #0x41]                    ; r7=1 -> InitParam+0x31 = 1  => fps mode 1 (30fps)
12802400  strb r5, [sp, #0x42]                    ; r5=0 -> InitParam+0x32 = 0  => no stereo 3D (+0x3E=0, so +0x47 always 0)
12802404..14  InitParam+4/+8 = rodata[0x1C]/[0x20] (heap sizes)
1280241c  bl   ->ad::fw::TaskBase::init(this, &param)
```
So the HB task bytes are `+0x3C..+0x3F = 01 01 00 01` (mode source, 3D off, top clear on) and, after `funcInit`,
`+0x44..+0x47 = 01 01 xx 00`. Note: **`01 01 00 01` is exactly the community cheat's match pattern**, and it sits at
`TaskBase+0x3C` of the HB task (the cheat writes pattern+1 = `+0x3D`, the fps-mode *source*, which `funcInit` copies to
`+0x45` every frame). Confidence: confirmed (code); which live objects the cheat actually hits is for RT.

Boot info (static `hb::GetBootInfo`/`hb::SetBootInfoColosseum` 0x16CA68): byte0 = battle/sub-mode, byte1 = mode
(**2 = Colosseum**, written by `SetBootInfoColosseum`), byte2 = colosseum result. The ctor copies the 4 bytes to
`HugeBattleSystem+0x58A..+0x58D` (`str r0, [r7, #0x58a]` at 0x12802250), so `+0x58B == 2` means "Colosseum giant battle".

### F2. HB replaces the whole TaskBase frame loop — confirmed

`hb::HugeBattleSystem` vtable 0x1296D9F4 vs `ad::fw::TaskBase` vtable 0x3DCFCC (slot = vtable offset/4):

| slot | TaskBase (static) | HugeBattleSystem |
|---|---|---|
| 0 `func` (per-frame loop) | 0x13DBCC `TaskBase::func` | **0x128018F8 (own)** |
| 5 `funcInit` (called at the start of every frame) | 0x13E8B8 | 0x13E8B8 (inherited) |
| 9 `funcDrawUpper` | 0x24D16C | 0x12801608 (calls base) |
| 11 `funcDrawUpperRight` | 0x132B6C | inherited (no right-eye work, 3D disabled) |
| 13 `funcDrawLower` | 0x230014 | 0x12801590 (calls base) |
| 18 `callbackVSync` | 0x13DA24 | **0x1280155C (own, calls base)** |

How the static engine makes a task 30fps (`TaskBase::func`, static):
```
0013dbfc  ldr r1,[vtbl,#0x14]; blx r1          ; funcInit every frame: +0x45 = +0x3D (so +0x45 is re-latched per frame)
0013e494  ldrb r0, [r4, #0x45]                 ; fps mode
0013e498  cmp  r0, #1
0013e49c  bne  0x13e4f0
0013e4a0..bc  wait LightEvent +0x368 and +0x370  ; one EXTRA vsync (top 0x400 + bottom 0x401) mid-frame
0013e4c0..dc  ClearSignal both
0013e74c..68  wait LightEvent +0x368/+0x370    ; the normal end-of-frame vsync wait (all modes)
```
`HugeBattleSystem::func` (0x128018F8–0x12802034) is a modified copy of this loop **without the `mode == 1` extra
wait**. The only read of the fps byte in the whole function is:
```
12801e50  ldrb r0, [r4, #0x45]
12801e54  cmp  r0, #3                ; only "mode 3" matters
12801e58  moveq r0, #1 / movne r0, #0
12801e60  strb r0, [r5, #0x7d]       ; CmdList +0x7D flag (same as static 0x13E344)
```
Other mode readers it calls behave identically for modes 0 and 1: `TaskBase::isStoreCmdList` (static 0x342810) returns 1
for mode 0/1 (only mode 2 looks at +0x47/+0x48). A grep of the whole HugeBattle listing finds no other `[this,#0x45]`
access on the task and **no isFps30 call** (0 veneer calls). Confidence: confirmed.

⇒ **The HB task's fps mode (0 or 1) has no effect on giant-battle pacing.** Setting it to 0 (cheat or patch) is a no-op
for HB; leaving it at 1 does not make HB 30fps either.

### F3. HB frame pacing: vsync accumulator driven by `hb::sys::CGameSpeed` — confirmed

End of every HB frame (`HugeBattle+0x1F84` → `bl 0x12802038`, "waitFrame"):
```
12801ed0  CmdListBase::WaitDoneAndStop         ; wait for the previous frame's GPU list (pipelined path)
12801f1c  resetVSyncEvent(this, 0)             ; clear vsync events AFTER the GPU wait
12801fe8  DisplayBufSet::swapAll / swapBufNo
12802038: waitFrame(this)
12802088    waitVSyncEvent(this); resetVSyncEvent(this,0)      ; >= 1 vsync per frame
1280209c    gs = *(this+0x5C0)                                 ; hb::sys::CGameSpeed (singleton, refcounted)
128020a8    gs->+0x140 = this->+0x6E4                          ; vsyncs counted since last frame end
128020d0    s0 = (gs->*(gs+0xC))(count)                        ; member-function pointer = step mode
128020d8    accum = 0 + s0
128020f0    while (accum < (float)S.interval) {                ; S @0x129C7804 (static local), interval == 1
128020f8        waitVSyncEvent; resetVSyncEvent(0)
12802120        delta = this->+0x6E4 - gs->+0x140; gs->+0x140 = this->+0x6E4
12802150        accum += (gs->*fn)(delta) }
12802164    step = min(accum, 10.0)
12802194    data[0x2A4] = step / data[0x2AC]                   ; step in 60Hz frames (data[0x2AC] = 1.0 always)
128021a4    data[0x2B4] = data[0x2A8] / data[0x2A4]            ; "current fps" = 60/step
128021a8    0x128D212C(frameTime)                              ; update global frame-time object
128021cc    this->+0x6E4 = 0
```
(`data` = HugeBattle .data base 0x129C6620; ctor sets data[0x2A4..0x2B4] = {1.0, 60.0, 1.0, 1/60, 60.0}, u16 data[0x16]=60,
data[0x18]=1 at 0x12802460–0x1280248C.) `S.interval` is only ever written with 1 (0x12802070, 0x12810340).

The vsync counter: `HugeBattleSystem::callbackVSync` (0x1280155C) calls the base (signals LightEvents) and on event 0x400
does `if (+0x588 == 0) 0x12933AAC(); +0x6E4 += 1`. 0x12933AAC reads the touch panel
(`nn::hid::CTR::TouchPanelReader::Read`, up to 7 samples) into the ring buffer at 0x12A10DC8 — i.e. **stylus input is
sampled at every vsync (60 Hz) independent of the HB frame rate.**

`hb::sys::CGameSpeed` (vtable 0x1296DFFC, 0x144 bytes, ctor 0x1280E1E4, one instance shared through the handle at
0x129C685C; acquired by 0x128D157C, released by 0x128D0BA0):
- `+0x04` float speed (1.0), `+0x08` u8 step-mode index, `+0x0C/+0x10` member-function pointer (step function),
  `+0x14..` debug slider (IDebugLife: value +0x128=1.0, range 0.03125..100), `+0x140` last vsync count.
- Step functions (table 0x12963720): mode 0 `0x1280E1C0` = `return speed` (fixed step, ignores vsyncs; ctor default);
  **mode 1 `0x1280E1C8` = `return speed * (float)vsyncs` (real-time step)**; 0x1280E1DC = same as mode 0 (unused).
- Mode 1 is installed (`if (gs->+8 != 1) { gs->+0xC = table[1]; gs->+8 = 1; }`) by `hb::game::CGameRoot` setup
  (0x128E537C, called from CGameRoot vtable slots 1 and 4) and by the actor-setup helper 0x128C8250 (called from
  CActorBoss, CEvent, CEndEvent::CModelHook, …). Nothing switches back to mode 0.
- Speed writes: 1.5 in `CSeqBattle`/`CSeqBattleBt1..Bt4` slot 2 when `HugeBattleSystem+0x58B == 2` (Colosseum)
  (0x12814274, 0x12829FBC, 0x12843C40, 0x1285A684, 0x1287BD60); 1.0 in `CSeqBattle` slot 3 (0x12814440, shared by all).
  0x128961BC (bt4 CFireBallBt4/CKoopaObjBt4 helper) reads speed and passes 1/speed on (an animation/sound rate).

Resulting behaviour (confirmed by code, not yet measured):
- Each HB frame waits at least one vsync after the GPU finished the previous frame, so HB is capped at 60 fps and
  otherwise runs at whatever rate CPU+GPU allow (60, or 30 when a frame overruns 16.7 ms, or a mix).
- In gameplay (mode 1) the logic step = speed × vsyncs elapsed (1.0 at 60fps, 2.0 at 30fps, capped at 10), so game
  speed stays real-time when the rate drops. Before `CGameRoot` setup (loading/opening) mode 0: 1.0 per frame.

Global frame-time object (getter 0x128D2188 → static 0x129CDA1C, updated by 0x128D212C each frame):
`[0]` dt in 60Hz frames = local×step, `[4]` local multiplier (1.0), `[8]` dt seconds = local×step/60,
`[0xC]` fractional accumulator, `[0x10]` whole frames this tick (floor). The getter is called 1,412 times in HugeBattle.
Spot checks: `hb::evscript::CTimer::update` (0x128F0D2C) `t += frameTime[8]` (seconds); `MessageSys::func(float)` is
called with `frameTime[0]` (0x128E15D8, 0x129419A4); `nw::eft::System::MakeDrawCommand` gets `frameTime[0]` as the
effect frame rate (0x12923970); `arz::CTouch::update` (0x128CA45C) uses `frameTime[8]`. ⇒ HB is designed as a
variable-rate, delta-time engine.


### F4. Giant-battle inputs (touch / buttons / mic) — confirmed unless marked

- **Touch (stylus):** sampled at every top-screen vsync inside `HugeBattleSystem::callbackVSync` → 0x12933AAC
  (`nn::hid::CTR::GetTouchPanel` + `TouchPanelReader::Read(…, 7)`), stored in the ring buffer at 0x12A10DC8 (bss).
  The per-frame consumer `arz::CTouch::update` (vtable 0x12975964 slot 2, 0x128CA45C; instance embedded in the task at
  +0xEE8) looks the samples up with the frame-time object (`frameTime[8]` seconds) through 0x12941350 and sets
  pressed/trigger/release (+4/+5/+6) and position (+0xC/+0x10). Sampling rate is frame-rate independent.
  Mini-game names: rush (rapid taps: `rushtime`, `rushtotaltime`, `rush_norma`, `rush_success_forward_sec`), slide,
  slide-rush, charge, rotation, punch / double punch, touch circle (bt3), fireball defence, fire breath.
- **Buttons/stick:** `arz::CPad::update` (vtable 0x12975440 slot 2, 0x1292A0DC) and `hb::game::CPad`/`arz::CPadCustom`
  (0x1291CC54) read `nn::hid::CTR::PadReader` (stick) and the static held-mask `gBtn+0x50` (0x4238D0) once per HB frame;
  0x1292A020 computes trigger = held & ~prev per call and an **auto-repeat counter that counts update calls** against
  a threshold of `(u16)(60.0 / data[0x18]) × param_sec` (param at 0x129C6E98, runtime-filled). That threshold assumes
  60 updates per second (see F6).
- **Microphone:** HugeBattle.cro imports no microphone API (no `nn::mic` symbol among its 575 named imports, no static
  export containing "mic", no "mic" string in the module). Fire breath (`hb::game::CAttackFireBreath`,
  `hb::ui::CFireBreath`) therefore runs on touch/buttons in 3DX. Confidence: likely (absence of evidence; a mic read
  could only come from static code writing a shared variable, none found).

### F5. What fps mode 0 does to HugeBattle — confirmed by code

Nothing. With `+0x3D = 0` the per-frame `funcInit` makes `+0x45 = 0`; HB's own loop reads `+0x45` only for `== 3`,
`isStoreCmdList` returns 1 for both 0 and 1, and HB calls no `isFps30`. Pacing, logic step and rendering are identical
for mode 0 and mode 1. So:
- the community cheat cannot change giant-battle speed or frame rate (even if one of its 4 addresses is the HB task:
  HB's `+0x3C..+0x3F` is `01 01 00 01`, so a match only clears `+0x3D`, which HB ignores);
- a 60fps patch that forces mode 0 (per-task InitParam, `TaskBase::init`, or `funcInit`) leaves HB unchanged;
- a patch inside `TaskBase::func` does not reach HB at all (HB never calls it).
No 2× speed, and no HB-internal crash mechanism tied to the fps byte. Crashes reported "in giant-Bowser scenes" with
the cheat must come from the transitions or from other tasks (CRS/RT), not from HB's pacing.

### F6. HB is a 60 Hz design with real-time compensation — confirmed (code), native rate unmeasured

Evidence that the designers target 60 updates per second:
- data[0x2A8] = 60.0 "base fps", data[0x2B0] = 1/60 s per frame, data[0x16] = 60, data[0x18] = 1 frame per tick (ctor).
- 40 sites in 27 functions convert seconds to frames with `(u16)(data[0x2A8] / data[0x18]) × sec` = 60 × sec (e.g. CBgm fades
  0x129323D8/0x1293229C/0x129324A8, object slot-17 motion blends such as `CKoopaObj` 0x128E7DE8, `CPeachObj`
  0x128D9360, bt1–bt3 boss objects, `CEffScript`, `CSeqOpening` BGM fade). Values passed on as frame counts.
- The pad auto-repeat (F4) counts update calls against 60 × sec.
- The loop has no 30fps branch; `S.interval` (min vsyncs per frame) is 1.

Consequences:
- At 60 fps (frame fits in 16.7 ms) every HB timer runs as designed.
- When a frame overruns (30 fps or lower), dt-based logic stays real-time (mode-1 step = 2.0), while the few counters
  that count frames (pad repeat, frame-count fades/blends if consumed per call) run slower. This is today's native
  behaviour, independent of any fps patch.
- Whether giant battles natively reach 60 fps on New 3DS (804 MHz, L2) is a performance question only — must be
  measured (R1 below). Nothing in code forces 30.

### F7. Transition notes (for CRS) — confirmed code, risk = guess

- HB state byte `+0x588`: 0 running; set to 1 (with `+0x589` = 1) by the end request 0x128102B0 (reached through
  `data[0x344]`, the task pointer the ctor stores at 0x128023E4); 1 → releases
  the root task holder `+0x5B4`, state 2; 2 → spins (returns from `func` without a vsync wait or a swap, tail-calling
  0x128D21F0) until `data[0x400+0x2FC] == 0`, then `GameMain::Back(this)` if `+0x589` else `GameMain::Start(12, this)`
  (field), state 3.
- The ctor calls `nngxGetCmdlistParameteri(0x207)`, saves the allocator (`nngxGetAllocator` → `+0x580/+0x584`),
  **`nngxFinalize()` and `nngxInitialize(HB allocator)`** (0x12802218–0x12802234) with no GPU wait of its own; the dtor
  (0x128028A0) does `StopAllSound`, `SoundHeap::LoadState`, `CmdListBase::WaitDoneAndStop`, `TaskBase::term`, then
  `nngxFinalize` / `nngxInitialize(saved)` / `nngxBindCmdlist`. Entry into HB therefore relies on the previous task
  having drained the GPU. If a 60fps previous task (field/battle) ever leaves a command list in flight at teardown,
  this is where it would fault on real hardware. Worth a GDB check on the cheat build (R4).

### F8. HugeBattleSystem field map (for RT probes) — confirmed

| off | meaning | source |
|---|---|---|
| +0x3C..+0x40 | InitParam copy: `01 01 00 01 01` (pipelined, mode 1, no 3D, clear top, clear bottom) | ctor 0x128023F4 |
| +0x45 | fps mode copy (re-latched every frame by `funcInit`) | static 0x13E8F4 |
| +0x578 | frame counter, +1 at the start of every HB frame (0x12801940) | HB func |
| +0x580/+0x584 | nngx allocator saved before `nngxFinalize` | ctor 0x12802224 |
| +0x588 / +0x589 | state (0 run, 1 release, 2 wait+GameMain, 3 done) / "Back" flag | 0x128018F8, 0x128102B0 |
| +0x58A..+0x58D | copy of hb boot info (byte +0x58B = 2 → Colosseum) | ctor 0x12802250 |
| +0x590 | `arz::CParam` (vtable 0x12975954); `data[0x2E4]` points here | ctor 0x12802254 |
| +0x5B4 | `arz::CRootTaskHolder*` (game task tree) | ctor 0x128022F4 |
| +0x5C0 | holder → `hb::sys::CGameSpeed*` | ctor 0x12802370 |
| +0x6E4 | top-screen vsyncs since the last frame end | callbackVSync 0x12801584, waitFrame 0x128021CC |
| +0xEE8 | `arz::CTouch` | ctor 0x128023D4 |
Globals: `data[0x344]` = the task, `data[0x2A4]` step, `data[0x2B4]` fps estimate (HB .data, runtime address from the
CRO segment table). The static current-task global 0x3F40B4 (ENG) points at the HB task while a giant battle runs
(the TaskBase ctor stores `this` there), so a probe can find the task without a heap scan.
Probe: `scripts/fps60/hb_probe.py` (read-only, uses RT's `rt_rpc.py`; prints frames/s from +0x578, step histogram,
CGameSpeed mode/speed/last vsyncs). Not run by HB (RT owns the emulator in wave 1).

## Conclusions

1. HB creates exactly one engine task, `hb::HugeBattleSystem`, with **fps mode 1 (30fps)** and stereo 3D off.
2. HB **does not use the engine's 30fps mechanism**: it overrides `TaskBase::func` with its own loop, which never
   performs the mode-1 extra vsync wait. The fps byte only feeds a "mode 3" command-list flag.
3. HB paces itself: ≥1 vsync per frame (so ≤60 fps), plus `hb::sys::CGameSpeed`, which converts elapsed vsyncs into
   a logic step. In gameplay the step mode is real-time (`speed × vsyncs`), speed 1.0 (1.5 in Colosseum giant battles).
   Timers, effects, messages and touch lookup use the resulting delta time; constants assume 60 updates/s.
4. **fps mode 0 changes nothing in giant battles** (no speed-up, no new crash path in HB code). The community cheat
   therefore cannot be what makes giant battles misbehave through HB's pacing; look at transitions (F7) instead.
5. **For 60fps nothing has to be patched in HugeBattle.cro.** Giant battles already run as fast as the hardware allows
   (≤60) with correct game speed; whether they actually reach 60 on New 3DS is a performance question for RT (R1).
6. If the lead wants giant battles pinned to 30 (clean per-task opt-out), the HB-native knob is `S.interval`
   (minimum vsyncs per frame) = 2 (P2). Because the step is real-time, game speed stays correct.

## (a) Patch points

| # | Location (CRO file offset = analysis − 0x12800000) | Original | New | Why / side effects | Recommendation |
|---|---|---|---|---|---|
| P0 | — | — | — | HB ignores the fps mode and is already ≤60 fps with real-time step | **Leave HugeBattle.cro untouched** |
| P1 | `HugeBattle+0x23FC` (0x128023FC) | `41 70 CD E5` `strb r7,[sp,#0x41]` (InitParam+0x31 = 1) | `41 50 CD E5` `strb r5,[sp,#0x41]` (= 0; r5 is 0 here) | Makes the HB task report mode 0. Functionally a no-op for HB (F5); only useful if some *static* code later starts reading the current task's mode while HB runs | Not needed |
| P2a | `HugeBattle+0x2044` (0x12802044) | `01 40 A0 E3` `mov r4,#1` | `02 40 A0 E3` `mov r4,#2` | `S.interval` initial value (stored at 0x12802074; r4 is reloaded at 0x12802084, no other use) | Only for a 30fps lock |
| P2b | `HugeBattle+0x10324` (0x12810324) | `01 10 A0 E3` `mov r1,#1` | `02 10 A0 E3` | guard-init path of the interval setter 0x128102FC (stored at 0x1281032C) | with P2a |
| P2c | `HugeBattle+0x10340` (0x12810340) | `01 00 A0 E3` `mov r0,#1` | `02 00 A0 E3` | interval setter (stored at 0x12810344); called through slot 5 of CSeqTask/CBackEvent/CEventSeq/CEndEvent/CGameRoot/CEventRootBase | with P2a |

P2 effect: every HB frame waits ≥2 vsyncs (30 fps); mode-1 step becomes 2.0 per frame (real time kept); the
per-call counters of F6 (pad repeat, frame-count fades) run at half rate, exactly as today whenever HB drops to 30.
P2 applies on Old 3DS too (HB.cro is shared); a New-3DS-only variant would need a code cave in the CRO. Any CRO edit
needs the CRR hash update (AGENTS §9). Original bytes verified in `romf2/RO/HugeBattle.cro` (sha256 prefix
cc77443026fc6b04).

## (b) Runtime verification (RT)

| # | Scene | Method | Expected |
|---|---|---|---|
| R1 | Each giant battle (bt1–bt4) and one Colosseum giant battle, unpatched, New 3DS mode | `hb_probe.py --secs 5`; status bar "App: N FPS" | task frames/s = presented fps; step histogram mostly 1.0 if ≤16.7 ms frames (60 fps), 2.0 if load-limited; CGameSpeed fn = CRO+0xE1C8 (mode 1) in gameplay, speed 1.0 (1.5 Colosseum) |
| R2 | Same, with the lead's 60fps build | same | identical fps/step to R1; TaskBase+0x3D/+0x45 may read 0 but nothing else changes |
| R3 | Same, with the community cheat | same | identical to R1 (cheat cannot affect HB pacing) |
| R4 | Enter/leave a giant battle 10× on the 60fps build (real HW if possible) | GDB bp at runtime `base+0x2228` (ctor `nngxFinalize`) and `base+0x2B08` (dtor); at the bp read the previous task's `+0x184` (GPU list in flight) | `+0x184 == 0` / GPU idle at every hit; no fault after `nngxInitialize` |
| R5 | Rush/slide mini-games with P2 vs P0 | count taps registered per second, compare success thresholds | same success criteria (time-based), confirms dt handling of inputs |

## (c) Open questions

1. Native giant-battle frame rate on New 3DS (R1). If HB already holds 60 fps on hardware, its loop is a hardware-proven
   example of the pipelined 2-list path running at 60 — useful evidence for CRS C2.
2. Is the EUR "game speed" cheat float (0x320DBDB8) `CGameSpeed+0x04`? If so that cheat only affects giant battles.
3. Which static code refreshes `gBtn+0x50` while HB is the current task (HB replaces `TaskBase::func`, so it is not
   updated there); candidate writer near 0x20EC9C. Per-frame edge detection in HB is fine either way, but a 30 Hz
   refresh would merge presses at 60 fps. (BTL owns input sampling.)
4. The 0x128D21F0 path in state 2 returns without any wait (busy loop while an async job finishes); harmless for fps,
   but CRS may want to confirm it cannot starve a loader thread on real hardware.

Status: DONE (static analysis complete; runtime items R1–R5 handed to RT).
