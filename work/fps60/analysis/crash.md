# CRS — crash candidates at fps mode 0 (3DX JP v1.2)

Worker CRS, 2026-10-30. Target `work/fps60/bin/3dx_v12.code.bin` (static, base 0x100000) + linked CROs
(analysis bases per BRIEF §3). Tools: `scripts/fps60/armdis.py`, listings `work/fps60/dis/3dx_v12/*.s`,
own helpers `scripts/fps60/crs_imports.py`, `crs_staffroll.py`. Ghidra: `work/fps60/TOOLS_STATUS.md`
did not exist while this ran, so all of the below is from the capstone listings (no decompile).

Confidence: **confirmed** (read in code), **likely** (strong indirect evidence), **guess**.

---

## 0. TL;DR ranking (most likely hard crash first)

| # | Candidate | Where | Confidence it crashes at mode 0 | Hardware-only? |
|---|-----------|-------|----|----|
| C1 | **fps mode flipped *after* init → TaskBase render/pace path uses a latched-at-init state that no longer matches** (the cheat's exact failure; our patch must set mode *before* init) | `TaskBase::funcInit` 0x13E8B8, `TaskBase::func` 0x13DBCC | high (explains "flip L+R each scene, credits still crash") | partly |
| C2 | **GPU command-list + VRAM-transfer double-buffer pipeline produces lists 2× as often; queue/timestamp assumptions break on real-HW vsync** | `TaskBase::func` 0x13DBCC, `CheckCmdListTimestampForInvalidate` 0x22EC3C, `btl::ReservedReleaseObjFunctor` 0x351AAC | medium-high | **yes** (Citra lax, real HW strict) |
| C3 | **Staff roll has *zero* fps scaling → scroll + window walk run at 2× and desync from the fixed-length, non-looping end-roll stream** | `fld::StaffrollCtrl` Field.cro 0x12000240.. | high it misbehaves; medium it is the *hard* crash | — |
| C4 | **Scene/battle transition "isFinish" gates compare a frame counter minus a per-frame step; at 2× step a `> ` test can be skipped and a teardown fires a frame early** | `ad::Encount::isFinish` 0x34512C, `btl::Main::isEndOpenEncountAndLoadResources` 0x28AAF0 | medium | partly |
| C5 | **Async resource-loader thread (encount/scene) started per transition; at 2× scene cadence on real HW the loader can be read before it finishes** | `ad::Encount::startLoadRes` 0x16A80C → thread 0x16B920 | low-medium | **yes** |

C3 is the one the brief singles out ("credits crash without fail"); C1/C2 are the shared mechanism that
makes C3 *and* the transition/menu/giant-battle crashes all cluster on real hardware. ENG owns the
TaskBase-pacing core (C1/C2) and HB owns giant battles; this report establishes the crash surface and the
runtime tests, and defers the pacing *fix* to ENG.

---

## 1. Staff roll / credits (C3) — located and modelled

### 1.1 Where it lives
3DX has **no Staffroll.cro** (1DX does: `Staffroll` module, `EntryTask`). In 3DX the credits are
`fld::StaffrollCtrl`, implemented in **Field.cro** and driven from the field event-script engine:

- Field.cro exports (confirmed, `cro.py romf2/RO/Field.cro --exports`):
  `CreateStaffrollCtrl` @Field+0xc0 (0x12000240), `StaffrollCtrl::init` @0x120003A8,
  `StaffrollCtrl::update` @0x1200098C, `StaffrollCtrl::isFinish` @0x12001000.
- Static imports them (`crs_imports.py staffroll`): stubs at 0x131790/0x131798/0x1317A0/0x1317A8.
- The field **event command** that drives it is opcode **0x280** (= `GlobalEvent::_CmdFuncTblSize` 0x4E + 562),
  handler **0x2E8B24** (`_CmdFuncTbl[562]`, table 0x3A30C4). The handler sub-dispatches on arg byte:
  sub-op 0 → `CreateStaffrollCtrl`+`init` (0x2E8B80/0x2E8B98), 1 → `update` (0x2E8BB8),
  2 → `isFinish` (0x2E8BEC), 3 → teardown (0x2E8C00). (confirmed, disasm 0x2E8B24.)
- Assets it opens: `rom:/Staffroll/mario_font.bffnt`, `rom:/Staffroll/JP/Staffroll.bin`
  (string refs in Field.cro @+0x744/+0x764).

### 1.2 What `Staffroll.bin` is, and how `update()` consumes it (confirmed by disasm + sim)
`Staffroll.bin` = BLZ-compressed: `u32 count` then `count × 0x60`-byte rows
(`wchar text[0x2c]`, `u32 colour` @+0x58, `float lineHeight` @+0x5c). `init` (0x120003A8) decompresses it,
stores base @ctrl+0x20 and count @ctrl+0x1c, and computes `total = Σ lineHeight − 480 − P[0x14]`
(0x120007B8..0x12000854). `P = fld::GetParamStaffroll()` → a const block @0x415E38 (built by the static
ctor at 0x36509C; `P0=P4=1`, `P14=20.0`, **`P18 = 2.0`** px/step).

`update()` (0x1200098C):
- `frame = ctrl+0x14`; `speed = ctrl+0x28 = P18 = 2.0` (copied in init).
- `pos` is derived from `frame`, `speed`, `P0+P4` (0x120009B0..0x120009E4), clamped `u32` and capped at `total`.
- it then scans the line array to find the lines covering the two 240-px screen windows (0x12000A3C loop),
  calls the builder `0x12000874` twice to compose two wchar strings, each into a **fixed 0x800-byte
  (0x400 u16) stack buffer** (frame is `sub sp,sp,#0x1040`; buffers at sp+0x20 and sp+0x820), and plays each
  via `MessageSimple::play` into 4 message columns.
- **`frame += 1` once per call** (0x12000DDC-0x12000DE4).

`isFinish()` (0x12001000): `(float)frame * speed > total`.

**Field.cro contains no `isFps30` call at all** (BRIEF §3: Field 0 sites; confirmed — I read all of Field.s,
only float consts, no isFps30 veneer). So the credits have **no 60-fps branch**: `frame` ticks once per
*rendered* frame, and the engine renders `update()` at 60 Hz in mode 0.

### 1.3 Consequences (my simulator `crs_staffroll.py`, validated against the data + BGM)
```
romfs/Staffroll/JP/Staffroll.bin : 416 entries, total 12312 px, isFinish after 6157 updates
   = 205.2 s @30/s,  102.6 s @60/s ; max text-buffer use 385 of 1024 u16, 0 anomalies
patch/.../JP/Staffroll.bin        : byte-identical to romfs (Korean patch does not touch it)
ml 1dx/.../KR/Staffroll.bin       : 305 entries, total 1195 px, 598 updates ; peak 1822 u16  <-- OOB in 3DX's buffer
```
- The 30-step duration (205 s) matches the **non-looping** `04_end_roll` stream (214.0 s, 32 kHz, confirmed
  from the BCSTM header) — the credits are authored to the music at 30 fps. At 60 fps they finish in ~103 s,
  i.e. **2× too fast and desynced from the end-roll BGM** (confirmed correctness bug; `the_end` 05 is the
  104-s looping "THE END" track that follows).
- The two on-screen text buffers are sized tightly (0x400 u16). JP peaks at **385 u16** at the normal step and
  never overflows *for JP data* (verified across all 6157 updates), because window occupancy is set by the
  240-px window height, not by scroll speed — so doubling the step does **not** by itself overflow the buffer.
  I explicitly could **not** reproduce a buffer overrun from JP data; the 1DX layout *does* overflow (1822 u16),
  which only proves the buffer has little margin, not that JP crashes here.

**So C3 is a confirmed 2×-speed / BGM-desync bug, but the *hard crash* of the credits is almost certainly not
inside StaffrollCtrl's own buffers for JP data.** The credits crash is better explained by C1/C2 below (the
shared render/pace path), which is exactly why the community "Less Crashes" build — which resets to 30 fps on
every scene and asks the player to re-press L+R — still crashes on the credits *every time*: the credits are a
long, GPU-heavy, streamed scene where the mode is most likely to be toggled while the task is mid-flight, and
where the real-HW GPU pipeline has the least slack.

### 1.4 Fix direction for C3 (hand off scroll math to ENG/lead)
Make StaffrollCtrl fps-aware: either (a) halve the per-call advance at mode 0 (scale `speed`/`frame` by the
isFps30 factor like `btl::ObjBase::calcUpdateSpd` 0x23C784 does), or (b) keep the credits task at 30 fps via a
per-task opt-out (cleanest; the scene is a fixed cutscene with a fixed-length stream, nothing to gain from 60).
Recommend (b). Patch point = the staffroll task's `InitParam+0x31` (set 1), or force `isFps30→true` for this
one task. (b) also side-steps C1/C2 for the credits entirely.

---

## 2. The shared mechanism (C1 + C2) — why credits *and* transitions crash, worse on real HW

### 2.1 The fps state is latched at init; the cheat changes it afterwards (C1, confirmed)
- `InitParam::InitParam` 0x24B240 sets `+0x31 = 0` (60 default); task creators pass 30 explicitly (BRIEF §3).
- `TaskBase::init` 0x28068C copies InitParam→task+0x3C.., then (0x280918-0x28093C) seeds
  `+0x4a` (buffer-swap mode) from `+0x3e`, `+0x44 = +0x3c`, `+0x45 = +0x3d (fps)`, `+0x46 = 1`.
- `TaskBase::funcInit` 0x13E8B8 re-derives `+0x44 = +0x3c`, `+0x45 = +0x3d`, `+0x47 = (+0x3e && is3DActive)`,
  and the `+0x48` toggle when fps==2.
- `TaskBase::func` 0x13DBCC branches the entire present/command-list path on **+0x44/+0x45/+0x47/+0x4a**
  (e.g. 0x13DC44 `ldrb[+0x44];cmp#1;ldrbne[+0x45];cmpne#2;cmpne#3`, 0x13E344 `ldrb[+0x45];cmp#3` picks the
  stereo path, 0x13E630 drives `Grp::ChangeDisplay` 0x26D89C off +0x4a).

The cheat pokes **+0x45 only**, on already-initialised live tasks. That leaves `+0x44` (and the derived
`+0x4a` swap-mode, `+0x47` stereo flag, `+0x48` toggle) describing the *old* 30-fps state while +0x45 says 60 —
an inconsistent combination the code was never meant to see. **Our patch must set the fps byte *before*
`init`/`funcInit` run (at the InitParam or at funcInit), never poke it live.** This is the single most
important crash-avoidance rule and it is why the cheat is fragile; it is ENG's core, flagged here because it
is the direct cause of the cheat's instability.

### 2.2 Doubled GPU command-list / transfer cadence (C2, confirmed structure, HW-only effect)
`TaskBase::func` builds GPU command lists (`Grp::Begin` 0x26D998 / `Grp::EndTransBufNo` 0x26D8E4,
`CmdListBase::run/flush/WaitDoneAndStop`), cycles a ring of command-list buffers (+0x16C..+0x184) and a
VRAM-transfer path (`VramTransfer::transfer` 0x135164 at 0x13E748), and tracks an incremental timestamp
(+0x188 from `IncrementalTimestamp`, +0x18C from `nngxCheckVSync`). Deferred resource frees are gated on that
timestamp: `CheckCmdListTimestampForInvalidate` 0x22EC3C returns "safe to free" only once the GPU has passed
the list that last used the buffer; it is called by `btl::ReservedReleaseObjFunctor` 0x351AAC and
`TaskBase::funcDrawLower` 0x230014.

At mode 0 the whole loop runs **twice as often in wall-clock**. On Citra the GPU "completes" instantly so the
timestamp/queue checks always pass; on real hardware the GPU has a real latency and fixed-size command/transfer
buffers, so producing lists at 2× can (a) overflow a transfer/command queue, or (b) let a deferred free fire
against a buffer the GPU is still reading (timestamp comparison off by the extra in-flight frame) → use-after-
free / GPU hang. This is the textbook "capacity/timing assumes 2 vsyncs per frame" case the CRS charter calls
out, and it matches "crashes mostly on real hardware, Citra fine."

**Confirm at runtime (RT):** at 60 fps, on the GDB stub, break in `btl::ReservedReleaseObjFunctor` 0x351AAC /
free paths and watch for a free whose `CheckCmdListTimestampForInvalidate` input (task+0x188 vs object
timestamp) is newer than the GPU's last-completed list; and watch the command-list ring (+0x16C..+0x184) and
transfer queue for wrap/overrun. Compare the same breakpoints at 30 fps. ENG should own the fix (e.g. keep the
2-vsync pacing while presenting at 60, or bound the ring).

---

## 3. Scene / battle / menu transitions (C4, C5)

### 3.1 Transition "isFinish" gates use frame−step comparisons (C4, confirmed)
`ad::Encount::isFinish` 0x34512C: when state (`enc+0x24c`)==6, it does
`remaining = enc+0x2a0; step = caller+0x1a4; if (remaining − step) <= 0 → finished`. The encount update
state-machine (0x16B5D4..0x16B748) advances `+0x24c` through wipe states and calls `isWaitWipeIn`
(0x3450A4). `btl::Main::isEndOpenEncountAndLoadResources` 0x28AAF0 compares a pair of floats
(`+0xa1054` vs `+0xa1058`, `+0xa10d4` vs `+0xa10d8`) that are per-frame accumulators, then checks the
encount isFinish and `btl::BtlSndSys::isLoadingAnyWithUpdate` 0x22EAF4.

If the per-frame `step`/accumulator is the fps-scaled 2× step (the engine's isFps30 ×2 factor, cf.
`fld::MsgSys::getComMsgSys` sites 0x302C68/0x307074 and `SaveData::load` 0x31ED3C/0x31EE5C which compute
`spd = (isFps30?1:2) × base × wipe`), then at 60 fps the wipe/transition "progress" still advances the same
per-*frame* amount but the `<= 0` / `>` edge can be **stepped over** (a counter that hit exactly the boundary
at 30 fps now jumps past it), firing task teardown/creation one state early. A teardown that runs while the
next task's resources are still loading is a classic transition crash. **Confidence medium** — the compare is
`>`/`<=` (not `==`), so it's edge-skip not exact-miss; needs the runtime check below.

**Confirm at runtime:** break on `ad::Encount::isFinish` 0x34512C and the transition state writes
`strb ...,[+0x24c]` (0x16B5C4/0x16B744/0x16C1C4); log state + `enc+0x2a0` + `step` each frame across one
battle-in/out at 30 vs 60; look for a state that is entered with a resource still loading
(`btl::Main::isEndOpenEncountAndLoadResources` still false, or `*_isLoading*`/`isBusy*` true).

### 3.2 Per-transition async loader thread (C5, confirmed thread, HW-only risk)
Each encounter spins a loader thread: `ad::Encount::startLoadRes` 0x16A80C and `...ForKJ` 0x16A9D4 call
`nn::os::Thread::TryInitializeAndStartImpl` 0x282704 with entry `0x16B920`, which opens the arc file and reads
via `BinGlu4Acs::getEntryAcs`. Completion is observed through the state byte, not a join. At 60 fps the main
task reaches the "loaded?" gate twice as fast in wall-clock; on real hardware (true thread scheduling + real
file latency, vs Citra's instant I/O) the gate can be polled before the thread has published its result.
Battle-in / scene-change is exactly where "worse on real hardware" bites. **Confidence low-medium** — the gates
(`btl::Main::isEndOpenEncountAndLoadResources`, `isLoadingAnyWithUpdate`, the `isBusy*`/`isLoaded*` family) do
re-poll, so this only crashes if a gate is *missing* on some path. Needs runtime instrumentation to confirm a
specific unguarded read.

**Confirm at runtime:** break on thread entry 0x16B920 and on the main-thread read of the loaded flag; verify
the flag is always set before first use at 60 fps. If a race shows, the fix is a proper wait on the loader
(the gate already exists on the common path; find the path that skips it).

---

## 4. Generic risky patterns found (lower priority, for the lead's audit)

- **`x / step` and `x * stepReciprocal`** appear in the isFps30-scaled wipe/opacity math
  (`fld::MsgSys::getComMsgSys` 0x302C68/0x307074, `SaveData::load` 0x31ED3C/0x31EE5C,
  `msys::MComSys::funcCalc` 0x32F40C): these select a 1.0 vs 2.0 multiplier from isFps30. They do **not**
  divide by a runtime-variable step, so no divide-by-zero; but if the cheat flips fps *after* one of these
  latched its multiplier (C1), the per-frame delta is wrong for the rest of that fade → stuck/!=-compared
  counters. Keep on the "set fps before init" rule and these are fine.
- **`== ` on frame counters:** `GlobalEvent::execLocalEvent` 0x25BFA0 decrements a float timer by `caller+0x14`
  per step and tests `<= 0` (0x25BFE4) — edge-safe. The field event command table (567 entries, 0x3A30C4) is
  dispatched by opcode, not frame count — safe. I did **not** find a bare `== frameTarget` gate that a 2×
  step would overshoot in the field script core; the risky ones are the transition gates in §3.1.
- **Stack-buffer sizing keyed to on-screen line count:** StaffrollCtrl §1.3 (JP fits; 1DX would not) — audit
  any *new* credits text (none here, Korean patch leaves Staffroll.bin byte-identical, confirmed).

---

## 5. Patch-point table (CRS scope)

| ID | Location | Original | Proposed | Why | Side effects |
|----|----------|----------|----------|-----|--------------|
| C3-a | credits task `InitParam+0x31` (the event-cmd-0x280 sub-op-0 path at 0x2E8B80 → `CreateStaffrollCtrl`/`StaffrollCtrl::init`) | fps mode inherited (0=60 on New3DS patch) | force **30** for this task | credits authored to 30 and to a fixed 214-s non-looping stream; nothing gained at 60 | credits display at 30 fps (intended) |
| C3-b (alt) | `fld::StaffrollCtrl::update` 0x1200098C scroll math | `frame += 1`; `speed = 2.0` | advance `frame` by ½ (or scale `speed`) at mode 0 | true-60 credits | must also keep BGM/line sync; riskier than C3-a |
| C1 | (ENG) wherever our mode-select writes the fps byte | — | write **before** `funcInit` 0x13E8B8 runs; never poke a live task | avoids the cheat's latch-mismatch crash class | none |
| C2 | (ENG) `TaskBase::func` 0x13DBCC pacing | — | present at 60 but keep command-list/transfer cadence safe on HW | fixes HW-only transition/credits crashes | ENG to design |

---

## 6. What RT must verify (scene, expected observation)

1. **Credits, 60 fps, real-HW-like:** does it crash with C3-a applied (credits forced 30)? Expected: no crash,
   credits at normal speed, BGM in sync. If still crashing → the crash is upstream (C1/C2) not the staffroll.
2. **Credits timestamp/free race (C2):** GDB-break the free/timestamp path (§2.2) during the roll at 60 vs 30.
3. **Battle-in/out and menu open/close (C4/C5):** log transition state `+0x24c`, `Encount+0x2a0`, loader-flag,
   and the `isEnd*/isLoading*/isBusy*` gates each frame at 60 vs 30; find a teardown that runs with a load in
   flight.
4. Confirm the JP `Staffroll.bin` text buffers never exceed 0x400 u16 on real data (my sim says max 385 — RT
   can sanity-check by reading ctrl+0x1c/+0x20 at runtime).

## 7. Open questions
- Exact field `TaskBase+0x1a4` vs `btl::Main+0x1a4` identity in `Encount::isFinish` (is the compared `step`
  the fps-scaled one?) — needs ENG's TaskBase layout map or Ghidra, then re-run §3.1.
- Does any credits/transition path call `nngxWaitVSync`/`nngxCheckVSync` a fixed number of times per logical
  step (would halve the wait budget at 60)? Saw the counts in `TaskBase::func`; ENG to quantify.
- HugeBattle credits/àla-giant teardown is HB's; cross-check C2 there (HugeBattle has 0 isFps30 calls).
