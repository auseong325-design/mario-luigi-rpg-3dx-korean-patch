# ENG — timing core of 3DX JP v1.2 (`ad::fw::TaskBase`)

Worker ENG, 2026-10-30. Static listing `work/fps60/dis/3dx_v12/static.s`, tools `scripts/fps60/armdis.py` and
`scripts/fps60/eng_tool.py` (mine: `func`, `regs`, `derived`, `vt`, `modes`). Ghidra dumps were not available
(`work/fps60/TOOLS_STATUS.md` absent during this work), so everything below is read from disassembly.
Addresses are static runtime addresses unless written `Module:addr` (CRO analysis address, see BRIEF §3).
Confidence tags: **[confirmed]** = read directly from code, **[likely]** = strong inference, **[guess]**.

> Report is written incrementally. Sections marked (WIP) are still being filled in.

## 0. Key corrections to the BRIEF

1. **`funcInit` runs every frame, not once.** `TaskBase::func` (vtable slot 0) calls vtable slot 5
   (`funcInit`, 0x13E8B8) as its first action every frame (0x13DBFC `ldr r1,[r0,#0x14]; blx r1`). It recopies
   `+0x3C→+0x44`, `+0x3D→+0x45`, recomputes `+0x47` (3D active) and toggles `+0x48`. So the *persistent* fps-mode
   byte is **TaskBase+0x3D** (InitParam+0x31); `+0x45` is a per-frame copy that is overwritten every frame. [confirmed]
2. **The community cheat's pattern `01 01 00 01` matches TaskBase+0x3C..+0x3F, not +0x44..+0x47**, and the byte it
   clears is **+0x3D**. Every scene task is created with InitParam `+0x30=1, +0x31=1, +0x32=0, +0x33=1`
   (table in §2), which is exactly `01 01 00 01` at +0x3C. At +0x44 the same bytes would be `01 01 00 00`
   (+0x46 is 0 after the first frame, +0x47 is always 0 because +0x3E=0 for every 30fps task). [confirmed for
   the code; the cheat's object addresses still need RT to confirm: `addr_matched − 0x3C` must hold a TaskBase vptr]
3. fps modes: **0 = 60fps, 1 = 30fps, 2 = 60fps update / draw on alternate frames while stereo 3D is on,
   3 = 60fps with event-driven swap (unused by any task found)**. Details §3. [confirmed]

## 1. TaskBase layout (size ≥ 0x580; derived classes start their members at +0x580)

Sources: ctor `TaskBase::TaskBase` 0x280C08, `TaskBase::init(InitParam const&)` 0x28068C,
`InitParam::InitParam` 0x24B240, `funcInit` 0x13E8B8, `func` 0x13DBCC, `callbackVSync` 0x13DA24,
`waitVSyncEvent` 0x13DB30, `callbackCmdList` 0x13DB80. All [confirmed] unless marked.

### 1.1 InitParam (0x35 bytes, copied by `init` with `memcpy4(this+0x0C, ip, 0x35)` at 0x28069C)

| IP off | TB off | default (ctor 0x24B240) | meaning (use site) |
|---|---|---|---|
| +0x00 | +0x0C | `*gMemAlc` (0x3F638C) | allocator for the 2 command lists (`CmdList::init` 0x2806E8) |
| +0x04 | +0x10 | 0xC8000 | command-list buffer size (MTaskBase uses 0xFA000) |
| +0x08 | +0x14 | 0x10 | command-list request count |
| +0x0C | +0x18 | `*gMemAlc` | allocator for the +0x10 buffer |
| +0x10 | +0x1C | 0x280000 | size of a work buffer at +0x4C8.. (CriticalSection +0x4BC) |
| +0x14 | +0x20 | `*gMemAlc` | allocator |
| +0x18 | +0x24 | 0x20000 | buffer → +0x4D4 (size +0x4D8) |
| +0x1C | +0x28 | `*gMemAlc` | allocator for CtrJobMan |
| +0x20 | +0x2C | 0x4000 | CtrJobMan (+0x4DC) heap size (`0x119C28(+0x4DC, alc, size, 0x11)`) |
| +0x24 | +0x30 | `*gMemAlc` | allocator for MemAlcUnit |
| +0x28 | +0x34 | 0x60 | MemAlcUnit unit size (+0x55C) |
| +0x2C | +0x38 | 0x40 | MemAlcUnit unit count |
| +0x30 | +0x3C | 1 | **pipelined GPU** (copied to +0x44 every frame; 1 = GPU executes frame N−1 while CPU builds N) |
| +0x31 | +0x3D | **0** | **fps mode** (copied to +0x45 every frame) |
| +0x32 | +0x3E | 1 | stereo-3D allowed (gates +0x47; also sets +0x4A = 1 or 3 in `init`) |
| +0x33 | +0x3F | 1 (ctor 0x114094 writes 1) | clear top screen in `Grp::Begin` (`r2 = +0x3F ? 7 : 0`) |
| +0x34 | +0x40 | 1 | clear bottom screen |

### 1.2 TaskBase fields

| off | type | meaning | written by |
|---|---|---|---|
| +0x00 | vptr | 0x3DCFCC for TaskBase | ctor |
| +0x0C..+0x40 | InitParam copy | §1.1 | ctor (defaults inline), `init` |
| +0x41..+0x43 | — | tail padding of the embedded InitParam (sizeof 0x38, `init` copies 0x35 bytes; ctor does not touch them). The proposed patch uses +0x41 as "promoted to 60" marker (§8) | — |
| +0x44 | u8 | pipelined flag (copy of +0x3C) | `init`, `funcInit` (every frame) |
| +0x45 | u8 | **fps mode in use this frame** (copy of +0x3D); read by `isFps30` 0x25EDD0 (`== 1`) | `init`, `funcInit` (every frame) |
| +0x46 | u8 | "first frame" flag: 1 after ctor/init, cleared at end of every `func` (0x13E76C) | |
| +0x47 | s8 | stereo 3D active this frame = `+0x3E && is3DActive()` (0x36B9C8 reads 0x1FF81080 slider, 0x1FF81084) | `funcInit` |
| +0x48 | s8 | mode-2 draw toggle: maintained only when mode == 2 (=1 while 3D is off, flips every frame while 3D is on); ctor 0 | `funcInit` |
| +0x49 | u8 | suppress right-eye draw (right eye drawn when `+0x47 && !+0x49`) | (not traced) |
| +0x4A | u8 | display-mode state: `init` sets 1 (3D allowed) or 3; after the first swap `func` calls 0x26D89C(0x702) → 2 or 0x26D89C(0x700) → 4 | `init`, `func` |
| +0x4C | CmdList[2] (0x8C each) | double-buffered GPU command lists; per list: +0x78 timestamp (=frame no.), +0x7C has-right-eye, +0x7D "mode-3 list", +0x80 LightEvent (GPU done, signalled from `callbackCmdList` when list+0x88 matches), +0x88 callback id, +0x89 target back-buffer no. | `init`, `func` |
| +0x164/+0x16C/+0x170 | inline vector cap 2 | **free** command lists (begin +0x16C, end +0x170) | |
| +0x174/+0x17C/+0x180 | inline vector cap 2 | **queued** (built, not yet executed) command lists | |
| +0x184 | CmdList* | list currently executing on the GPU | |
| +0x188 | u32 | index (0/1) of the list being built | |
| +0x18C | u32 | `nngxCheckVSync(0x400)` value at the last swap (ctor: current−1) | |
| +0x190 | u32 | draw counter (frames built; skips −1); stored into list+0x78 | |
| +0x194/+0x198 | u32 | timestamp of list started / finished | |
| +0x19C..+0x1A4 | u32×3 | previous-frame copies of +0x190..+0x198 (copied at start of `func`) | |
| +0x1A8 | `nn::ulcd::CTR::StereoCamera` | | ctor/init |
| +0x20C | stereo matrices helper (0x342664 builds per-eye commands) | | |
| +0x27C | 2×0x70 | camera info (2 eyes) | |
| +0x35C/+0x360 | f32 | 0.0 | ctor |
| +0x368, +0x370 | `nn::os::LightEvent` ×2 | **vsync events: top (event 0x400) and bottom (0x401)**, signalled in `callbackVSync` | |
| +0x378 | u8 | bit0 = top vsync seen, bit1 = bottom vsync seen | `callbackVSync`, cleared by `func` |
| +0x37C | 5×0x20 | (not traced) | |
| +0x41C | VramTransfer (0x9C) | VRAM transfer queue; its LightEvent at **+0x49C** is signalled when both vsyncs arrived (`+0x378 == 3`, 0x13DA78) and cleared with the vsync events (0x26DAF0) | `func` calls `VramTransfer::transfer(+0x41C)` 0x135164 |
| +0x4B8..+0x4D0 | work-buffer header (vptr 0x3DC990, CriticalSection +0x4BC, buffers +0x4C8..) | from IP+0x10 | |
| +0x4D4/+0x4D8 | buffer, size | from IP+0x18 | |
| +0x4DC | `CtrJobMan` | job queue (`CtrJobMan::enqueue` 0x26DBE8 from 0x13DB28) | |
| +0x518 | job worker (0x119B18) | | |
| +0x558/+0x55C | MemAlcUnit buffer / object | | |
| +0x574 | dfx system ptr (`ad::dfx`; `RenderBuffer::swapAndClear` after swap) | | `initDfxResSys` |
| +0x578 | u32 | **`func` call counter** (incremented at the end of every `func`, 0x13E770) | |
| +0x57C | u8 | 1 | ctor |

Global **0x3F40B4** (`MessageSys::_RubyEnable+0x64` in the symbol map) = the *current task*: the TaskBase ctor stores
`this` there (0x280E08) and the fld launcher re-points it (0x31D2AC). The vsync interrupt callback 0x11406C forwards
vsync events only to that task (`task->vtable[18] = callbackVSync`), registered for both screens by
`0x11A248(0x402, 0x11406C)` in `init`. A task that is not current never gets its vsync events signalled. [confirmed]

## 2. Every task and its fps mode

Task classes = everything whose RTTI derives from `ad::fw::TaskBase` (`eng_tool.py derived ad::fw::TaskBase`).
Scene switching: `GameMain` (gGameMain 0x3F405C) pops a `GAME_MODE` and dispatches in 0x33E3AC:
modes 0–8 load CROs from table 0x3F4180 and call the CRO's exported `EntryTask`; 9/12 → field 0x131D70,
10 → battle 0x131E38, 11 → Bowser Jr. RPG 0x131DF8. Every scene task is entered with
`TaskMan::entry(gTaskMainMan 0x3F4130, task)`.

| GAME_MODE | task class (vtable) | created at | InitParam +0x30/+0x31/+0x32/+0x33/+0x34 | fps mode | TB+0x3C..+0x3F |
|---|---|---|---|---|---|
| boot | `Boot` (0x3DCA1C) | ctor 0x1092FC, `init` 0x109480 (inline IP at sp) | 1 / **0** / 0 / 1 / 1 | **60** | 01 00 00 01 |
| 0 HugeBattle.cro | `hb::HugeBattleSystem` (HugeBattle:0x1296D9F4) | HugeBattle:EntryTask+0xF1C/0xF40 (0x128023F8/0x1280241C) | 1 / **1** (r7=1 @0x12802398) / 0 (r5) / 1 / 1 | 30 | 01 01 00 01 |
| 1–8 MainMenu, KJMenu, ShopMenu, BCat, LoadMenu(+SaveLoad), SaveMenu(+SaveLoad), AttackMiniGame, Colosseum | `msys::MTaskBase` (0x3E4874) → `main_menu::MainMenuTask`, `kj_menu::KJMenuTask`, `shop::ShopMenuTask`, `bcat::BCatTask`, `load_menu::LoadMenuTask`, `save_menu::SaveMenuTask`, `atk_mg::AttackMiniGameTask`, `col::ColosseumTask` | `MTaskBase::MTaskBase` 0x334688 (IP at sp; `strb r1(=1),[sp,#0x31]` 0x3346C8, `strb r5(=0),[sp,#0x32]` 0x3346E0), cmd-list size 0xFA000 | 1 / **1** / 0 / 1 / 1 | 30 | 01 01 00 01 |
| 9, 12 field (incl. staff roll, `fld::GetParamStaffroll`) | `fld::System` (0x3E3B3C) | param built by 0x306858, filled by 0x31CADC (`strb ip(=1),[r0,#0x31]` 0x31CB48, `strb r7(=0),[r0,#0x32]` 0x31CB50) or 0x31CD94 (0x31CE44/0x31CE4C) depending on u8 0x415E64; copied to fld::System+0x580 and passed to `init` at 0x30163C | 1 / **1** / 0 / 1 / 1 | 30 | 01 01 00 01 |
| 10 battle | `btl::Main` (0x3E10C4) | ctor 0x28DB2C, IP at sp+0x38, `init` 0x28EECC (`strb fp(=1),[sp,#0x69]`, `strb r5(=0),[sp,#0x6A]`) | 1 / **1** / 0 / 1 / 1 | 30 | 01 01 00 01 |
| 11 Bowser Jr. RPG | `kj::KJSystem` (0x3DEBD8) | ctor 0x196940, IP at sp+0x10, `init` 0x197430 (`strb r6(=1),[sp,#0x41]`, `strb r7(=0),[sp,#0x42]`, `+0x34 = 0`) | 1 / **1** / 0 / 1 / 0 | 30 | 01 01 00 01 |

No code path was found that writes TaskBase+0x3D after `init` (all 24 `strb …,#0x3d` sites in static/CROs
outside HugeBattle are other structures: stack temporaries or non-task objects; HugeBattle pending §6).
No task uses mode 2 or 3. Only Boot runs at mode 0. [confirmed for the creation paths; "no later write" = likely]

## 3. The frame loop: `TaskBase::func` 0x13DBCC (one call = one frame)

Pseudo-code (r4 = this; every branch address checked in the listing):

```
func():
  prev = {+0x190,+0x194,+0x198}; this->funcInit()              // vtable+0x14, EVERY FRAME (0x13DBFC)
  vsyncEv[top,bot].ClearSignal(); +0x378 = 0; ClearSignal(+0x49C) // 0x13DC0C..0x13DC40
  async = (+0x44 == 1) || mode == 2 || mode == 3                 // 0x13DC44..0x13DC60
  if (!async) {                                                  // synchronous GPU path (no task uses it)
      if (gpuList) { WaitDoneAndStop(); recycle gpuList and all queued lists }   // 0x13DC74..0x13DD10
      backBuf = DisplayBufSet::getBackBufNo()
  } else if (gpuList) {                                          // previous list still on the GPU
      backBuf = gDisplayBufSet->+0xB8                            // 0x13DD24
  } else if (nngxCheckVSync(0x400) != +0x18C && queued non-empty) {  // a vsync passed since the last swap
      pick the newest queued list built for the current back buffer, start it on the GPU
      (CmdListBase::run 0x287FE8), recycle every other queued list   // 0x13DD80..0x13DED4  (= drop stale frames)
      backBuf = gDisplayBufSet->+0xB8
  } else backBuf = getBackBufNo()
  dfx pre-calc hooks (+0x574)
  this->funcCalc()                                               // vtable+0x18: GAME LOGIC, once per func call (0x13DF14)
  rightEye = +0x47 && !+0x49
  draw = !(mode == 2 && +0x47 && +0x48 == 0)                     // 0x13DF48..0x13DF78
  if (draw) {                                                    // 0x13DF7C..0x13E39C
      list = free.pop() or (if none free) the OLDEST queued list (its frame is discarded)
      clear list; +0x188 = index
      vt+0x1C/+0x20 (pre-draw); Grp::Begin(0x400 top, clear=+0x3F?7:0); left-eye camera cmds;
      funcDrawUpper (vt+0x24); Grp::EndTransBufNo(0x400, …, backBuf); vt+0x28
      if rightEye: Grp::Begin(0x410); funcDrawUpperRight (vt+0x2C); EndTransBufNo(0x410)
      vt+0x30; Grp::Begin(0x401 bottom, clear=+0x40?7:0); funcDrawLower (vt+0x34); EndTransBufNo(0x401)
      vt+0x38, vt+0x3C; list.+0x78 = +0x190; list.+0x7C = rightEye; list.+0x7D = (mode == 3); list.+0x89 = backBuf
      queued.push(list); +0x190++
  }
  done = false
  if (!async) { start the list just built, WaitDoneAndStop(), done = true }
  else if (gpuList && !gpuList.+0x7D && draw) { CmdListBase::WaitDoneAndStop(); recycle; done = true }  // 0x13E43C
  else if (!gpuList && +0x46) goto end_without_vsync_wait        // very first frame only (0x13E488)
  if (mode == 1) { vsyncEv[top].Wait(); vsyncEv[bot].Wait(); ClearSignal both; +0x378 = 0; ClearSignal(+0x49C) } // 0x13E494: the 30fps extra vsync
  if (gpuList && gpuList.+0x7D) { mode-3 path: poll the list's done-event with a timeout while running
       VramTransfer, then swapAll/swapBufNo, +0x18C = nngxCheckVSync(0x400) }   // 0x13E510..0x13E62C
  else if (done) { ClearSignal both vsync events; +0x378 = 0; ClearSignal(+0x49C);
       DisplayBufSet::swapAll(rightEye)  0x287E7C; DisplayBufSet::swapBufNo 0x287E68;
       +0x18C = nngxCheckVSync(0x400); dfx RenderBuffer::swapAndClear; vt+0x40 }   // 0x13E684..0x13E6F8
  display-mode one-shot (+0x4A 1→2 via 0x26D89C(0x702), 3→4 via 0x26D89C(0x700))
  if (!gpuList) VramTransfer::transfer(+0x41C)                   // 0x13E748
  vsyncEv[top].Wait(); vsyncEv[bot].Wait()                       // 0x13E74C: always wait for the NEXT vsync
end_without_vsync_wait:
  +0x46 = 0; (+0x578)++
```

Consequences [confirmed from the code above]:

- **Mode 1 (30fps)** = one extra "wait for a vsync, then clear" before the swap. Because the vsync events are
  cleared at the start of the frame, that first wait is satisfied by any vsync that occurred while the frame was
  being computed. Then the events are cleared again right before the swap and the loop waits for the *next*
  vsync. Net: exactly 2 vsyncs per frame as long as calc+draw+GPU fits in ~33 ms; game logic (`funcCalc`)
  runs once per frame → 30 updates/s.
- **Mode 0 (60fps)** = only the final wait. Budget ≈ 16.7 ms. The loop is the same; `funcCalc` is still called
  once per frame, and the engine's per-frame step comes from `isFps30()` (×2 at mode 1, ×1 at mode 0).
- **Mode 2** = mode 0 when 3D is off; with 3D on, `funcCalc` still runs every vsync but drawing and swapping
  happen only on every other frame (+0x48 toggled by `funcInit`). So mode 2 is "60 Hz logic, 30 Hz stereo
  rendering". `isFps30()` is false in mode 2, so all fps-aware code steps ×1. No 3DX task uses it.
- **Mode 3** marks the list (`+0x7D`) and swaps from the GPU-done event (poll loop with timeout constant
  0x28870 kept in a static at 0x3F4128/0x3F412C, `VramTransfer` serviced while waiting). Unused.
- **+0x44 = 1 (every task)**: 2-stage pipeline. The list built in frame N is started on the GPU at the
  beginning of frame N+1 (only if a vsync has passed since the last swap) and is waited for and swapped at the
  end of frame N+1, i.e. one frame of display latency. Only 2 command lists exist: if both are busy when a new
  frame is built, the oldest *queued* (never executed) list is reused, so that frame is silently dropped.

### 3.1 Who calls `func`, and input sampling [confirmed]

Main loop 0x101CDC..0x101D64 (one iteration = one frame):
`gSndSys` update 0x104824 → `gBtn` update 0x10409C (buttons) → `gTp` 0x103CA4 (touch) → 0x1038A4(0x423944) →
`if (!0x104D68()) exit` → `task = *gTaskMainMan; task->vt[4]()` (TaskBase: empty) → `task->vt[0]()` = `func`
→ 0x10352C(0x425258, 1) → loop. So input is sampled once per `func` call: 30 Hz at mode 1, 60 Hz at mode 0.
There is no frame-skip or catch-up loop around `func`; `funcCalc` runs exactly once per `func`.
`nngxCheckVSync` is called only by `TaskBase::func` (0x13DD3C, 0x13E5CC, 0x13E6D4), the ctor (0x280CFC) and
HugeBattle's own loop; it is used only for "has a vsync passed since the last swap", never to compute a time step.
`nngxWaitVSync` is used only in boot/teardown paths (0x101C10, field 0x3011A8/0x302288, Boot 0x3227CC/0x322980,
`MTaskBase::initDfxSys` 0x33462C, KJMenu), not for per-frame pacing.

### 3.2 Scene switch and vsync ownership [confirmed]

`GameMain` (not a TaskBase) becomes the main task between scenes: it deletes the old task (vt[2] at 0x33E3C8),
loads the CROs of the next mode, then calls the creator, whose `TaskMan::entry` (0x287B18: `*gTaskMainMan = task`)
makes the new task current. The vsync callback is registered by `TaskBase::init` (`0x11A248(0x402, 0x11406C)`,
0x2807E4) and unregistered by `TaskBase::term` (`0x11A248(0x402, 0)`, 0x24A3A4, only when the task is the current
one). The current-task global 0x3F40B4 is never cleared (only the ctor 0x280E08 and the field launcher 0x31D2AC
write it), so it dangles between `term` and the next ctor; this is harmless only because the callback is
unregistered in that window. [confirmed] Any patch that creates a second TaskBase while another runs must keep
this in mind (the ctor steals the vsync callback target).

## 4. Frame overrun at mode 0 [confirmed by the loop structure; size of the effect = runtime]

- The loop has no time-step compensation: one `func` = one logic step of fixed size (1.0 at mode 0,
  2.0 at mode 1 via `isFps30`). The step is never derived from elapsed vsyncs.
- At mode 0, if calc+draw+GPU of a frame takes longer than one vsync interval, the frame simply takes two vsyncs:
  the final wait (0x13E74C) waits for the next vsync after the swap, and the vsync events are cleared just
  before the swap (0x13E684), so an already-passed vsync is not counted. Result: **slowdown** (that frame's
  game time advances by 1/60 s while 1/30 s of real time passes). No double step, no dropped logic frame.
- GPU-bound case: the CPU blocks in `CmdListBase::WaitDoneAndStop` (0x287988) for the previous list before the
  swap; same consequence (slowdown). If both command lists are busy, a built-but-not-started frame is discarded
  (0x13DF8C) — an image is lost, logic is not.
- Mode 1 has a 2-vsync budget, so the existing 30fps game has never seen overruns of 16.7..33 ms; at mode 0 those
  frames become slowdowns. Scenes that are heavy on the 268 MHz-GPU side (the GPU is not faster on New 3DS) are
  the ones to measure (RT: presented FPS = Azahar "App: N FPS"; on hardware use a frame counter, e.g. TaskBase
  +0x578 per second).
- HugeBattle does not use this loop: `hb::HugeBattleSystem` overrides `func` (HugeBattle:0x128018F8) with its own
  copy that calls `funcInit`, `resetVSyncEvent`/`waitVSyncEvent` and a float accumulator around 0x12802070..
  0x12802104 (variable number of vsync waits per frame), i.e. `CGameSpeed`-style pacing. See `hugebattle.md`.

## 5. Changing the fps mode at runtime — what is safe, what is latched

`TaskBase` itself: changing **+0x3D** between frames is safe. `funcInit` copies it to +0x45 at the start of the
next frame and the whole frame (calc, draw, pacing) uses that value. Writing +0x45 directly (the "Less Crashes"
code also writes +0x45 via `220DA3B5`) is overwritten at the next frame start; a mid-frame change can only alter
that one frame's extra vsync wait. Nothing in `TaskBase` caches the mode: the display mode state +0x4A and the
command-list sizes depend only on +0x3E/IP sizes, not on +0x3D. [confirmed]

Latched state found in the game code (every static `isFps30` site in §7 is a `step = isFps30 ? 2.0 : 1.0`):

| state | written | per frame? | consequence of a flip after init |
|---|---|---|---|
| field step `fld::System+0x1A4C` | init 0x302C94 (field init fn 0x302A64, right after `TaskBase::init` at 0x30163C via 0x301674), fast-forward on/off 0x31ED60/0x31EE7C, and **every frame in `fld::System::funcCalc` 0x30709C only while `fld+0x6E0` bit 0x40 is set** (set at 0x30B2F0 when the field state machine fn 0x30A9D8 reaches state 8, cleared at 0x3072A8 in fn 0x307234) | conditional | between field init and state 8, and while the bit is clear, the step keeps the value computed at the old mode → field runs at 2× (30→60 flip) or ½× speed until the bit is set. The cheat flips ~50 ms after init, so it always starts a field scene with a 2.0 step that is corrected only when the state machine reaches 8. [confirmed code; duration = runtime] |
| field previous step +0x1A50 | 0x30706C | yes | none |
| battle step (btl::Main::funcCalc 0x28B67C: `(isFps30?2:1) × [[task+0x574]+0x7C] × [+0x8A3C]`, accumulated into +0x8A44 with `modff`) | every frame | yes | follows the mode; the integer-tick accumulator (+0x8A44) is mode-independent. Battle details: `battle.md`. |
| menu step (`MComSys::funcCalc` 0x32F40C) and event step (MComSys+0xE651C+0x14) | every frame | yes | follows the mode |
| KJ step `KJSystem+0x61C58` (read by kj objects through getters 0x345260/0x3467D0) | `KJSystem::funcCalc` 0x1960E8: `(isFps30?2:1) × [[task+0x574]+0x7C] × [KJSystem+0xC8D90]`; 0.0 while paused (0x195ED0); ctor 0.0 (0x196DF0) | yes | follows the mode |
| objects created during the 30fps frames (cheat case) | their constructors | — | any object that computes a frame count or speed at creation from `isFps30()` keeps it; none found in static (all 14 sites are per-frame step computations, §7); CRO sites are covered by BTL/MOD |

Conclusion: the cheat's "flip after init" is safe for the engine core but makes every scene start with up to
~3 frames (Luma applies cheats every 50 ms, see `research/web.md` §3) at 30fps state and leaves the field step
latched until state 8. **A code patch should decide the mode before `TaskBase::init` copies it, so no state is
ever computed at the wrong mode.** The hardware-only "transition crashes" of the cheat match the Luma
cheat-engine/kernel race described in `research/web.md` §3 better than any engine-side mechanism found here.

## 6. The cheat, decoded against the code [confirmed for the code, addresses = RT]

| cheat word (EUR v1.2) | = | evidence |
|---|---|---|
| `5X…74/64/44/0x20DA3AC == 0x01000101` | TaskBase **+0x3C..+0x3F** = 01 01 00 01 (IP+0x30..0x33 of every 30fps task) | §2 table; +0x44..+0x47 would read `01 01 00 00` |
| `2X…+1 = 0` | **+0x3D = 0** (persistent fps mode → 60) | `funcInit` copies it every frame |
| FIX's extra check `u32[matched+8] == 0x00000101` | +0x44..+0x47 = 01 01 00 00 (per-frame copies: +0x44=1, +0x45=1, +0x46=0, +0x47=0) | so "matched+8" is the funcInit copy, which confirms matched = +0x3C |
| FIX's restore check `u32[matched+8] == 0x00000001` | +0x45 = 0 (already running at 60) | |
| Less Crashes `220DA3B5 = 1` | +0x45 = 1 (redundant: funcInit rewrites it) | |
| EUR game speed float `0x320DBDB8` | **fld::System+0x1A48** if 0x320DA3AC = fld::System+0x3C (0x320DA370 + 0x1A48 = 0x320DBDB8) | +0x1A48 = field fast-forward factor, see §6.1 |

So the EUR "0x320DA3AC" object is (very likely) `fld::System`, the persistent field task (created once, kept in
`[0x3F49B0+0x20]`). The three low-heap candidates (0x30000044/64/74 → objects at 0x30000008/28/38) are scene tasks
allocated first in a fresh scene heap (only one exists at a time). RT: read the u32 at `matched−0x3C` and compare
with the vptr table in §2 (JP static vptrs are the same values as listed; EUR/USA binaries differ).

### 6.1 Game-speed floats (JP v1.2) [confirmed]

- **fld::System+0x1A48** (field fast-forward factor; the EUR cheat's "game speed"): reset to 1.0 at field init
  (0x302C60 `vstr s18,[sb,#0x248]`, sb = fld+0x1800), set to the global float **0x412C80** by the fast-forward
  controller fn 0x31EC90 (0x31ED34) and back to 1.0 (0x31EE58). Multiplied into the field step every frame
  (0x307088..0x30709C: `step = (isFps30?2:1) × [[fld+0x574]+0x7C] × [fld+0x1A48]`).
- **[[task+0x574]+0x7C]** (dfx-system speed, global per task): set to 1.0 at field init (0x302C5C) and by the
  fast-forward controller (0x31EE54); multiplied into the field step and the battle step (0x28B6BC).
- Battle factor **btl::Main+0x8A3C** (0x28B6C8 `vldr s1,[r6,#0x23c]`, r6 = btl+0x8800).
None of these is an fps setting; they multiply the per-frame step. Keep them at 1.0; a 60fps patch needs no change
to them.

## 7. All static `isFps30` call sites (14 direct `bl 0x25EDD0`) [confirmed]

All 14 compute a step `isFps30() ? 2.0 : 1.0` from the *current* +0x45 at the time of the call; none caches a
frame count. "Per frame" = evaluated in the task's per-frame update.

| # | call site | function (start) | task asked | what the step drives | when |
|---|---|---|---|---|---|
| 1 | 0x16D998 | fn 0x16D984 (kj UI object update) | `[0x3F61C0]` = KJSystem | `CellAnime::update`, `MoveFBase::update` of that object | per frame |
| 2 | 0x195E90 | `kj::KJSystem::funcCalc` 0x195D94 | KJSystem | s17 = step: KJ master step +0x61C58 = s17 × dfx speed × +0xC8D90 (0x1960E8), `MoveC::update(s17)` ×2 (0x195F50) | per frame |
| 3 | 0x196260 | same funcCalc (later block) | KJSystem | `MoveC::update(step)` of KJ object at +0xC8A0C+… | per frame |
| 4 | 0x1EBD7C | in `btl::ObjBadgeStarMan` update (0x1EBD74) | btl::Main (`[0x3F35F8+8]`) | badge-star effect step (only used `if step > 0`) | per frame |
| 5 | 0x23C7A0 | `btl::ObjBase::calcUpdateSpd` 0x23C784 | btl::Main | `obj->spd(+0x20) × step` for objects with flag +0x24 bit1, else `spd × parent speed` | per object per frame |
| 6 | 0x28B6A0 | `btl::Main::funcCalc` 0x28B67C | btl::Main (this) | battle master step × dfx speed × +0x8A3C → accumulator +0x8A44 (`modff`) | per frame |
| 7 | 0x302C68 | field init fn 0x302A64 | fld::System | initial field step +0x1A4C (= 2.0 at 30fps) | once at field start |
| 8 | 0x307074 | `fld::System::funcCalc` tail 0x307010.. | fld::System | field step +0x1A4C (prev → +0x1A50), fed to `fn_24D0C4` updaters and the effect engine | per frame while +0x6E0 bit 0x40 |
| 9 | 0x31ED3C | fast-forward controller fn 0x31EC90 | fld::System | field step with fast-forward factor 0x412C80 | on fast-forward start |
| 10 | 0x31EE5C | same controller | fld::System | field step with factor 1.0 | on fast-forward stop |
| 11 | 0x32F41C | `msys::MComSys::funcCalc` 0x32F40C | menu task (`MComSys+4`) | menu update step → fn 0x32EEF8 | per frame |
| 12 | 0x32F448 | same | menu task | event step (`MComSys+0xE651C+0x14`) for `GlobalEvent::execLocalEvent` | per frame |
| 13 | 0x345278 | getter 0x345260 (kj object, flag at +0x468) | KJSystem | returns `isFps30?2:1` if the flag is set, else the KJ step +0x61C58 | per call |
| 14 | 0x3467EC | getter 0x3467D0 (kj object, flag at +0x2DC) | KJSystem | same pattern | per call |

Plus inline equivalents of `isFps30` (read +0x45 directly): `Boot` funcCalc 0x3226D8 (`MessageSys::func` step,
0x322700: mode 1 → 2.0 else 1.0) and `TaskBase::isStoreCmdList` 0x342810 (draw predicate, used only by HugeBattle).
The BRIEF's count of 15 probably included one of these. CRO sites (Battle 2, Colosseum 11, KJMenu 38, LoadMenu 13,
MainMenu 24, SaveMenu 1, ShopMenu 17, AttackMiniGame 1, BCat 1) are covered by BTL and MOD.

## 8. New 3DS detection available in the binary [confirmed]

`nn::os::CTR::IsRunOnSnake()` at **0x2844AC** (ARM, AAPCS, returns r0 = 1 on New 3DS):
```
002844b0: ldr  r4, =0x3f716c          ; cached result (s8) at 0x3F716C, guard word 0x3F7170
002844b8: tst  r0, #1 / bne cached
002844e0: bl   #0x10ed0c              ; -> 0x117598: IPC header 0x01010000 (APT CheckNew3DSApp) on the APT
                                      ;    handle [0x3F772C], svc 0x32 SendSyncRequest; u8 result
002844f8: strb r0, [r4]               ; cache
00284504: ldrsb r0, [r4]
```
The game already uses it: boot 0x104060 (`if IsRunOnSnake(): 0x2843C0(0, 0xC)`, New-3DS-only setup),
GPU setup 0x114148/0x1142AC/0x114490/0x1146D4/0x114A08, amiibo `ad::nfp::IsConnected`/`StartDetection`
(built-in NFC) and LoadMenu. After the first call it costs a guard test and one load. On Azahar the result follows
the emulator's "New 3DS mode" setting, which gives a free A/B test. (Alternative: config-memory APPMEMTYPE at
0x1FF80030, 6/7 only in New-3DS memory modes; the game already reads the shared page 0x1FF81080 in
`is3DActive`. The SDK call is preferred because it is what the game itself trusts.)

## 9. Recommended patch: decide the fps mode inside `TaskBase::init` (New 3DS only, per-class opt-out)

Prototype: `scripts/fps60/eng_patch.py` (assembles with keystone, verifies the original bytes and the zero
slack, optional `--ips <path>` test file; never writes into `patch/`). Verified output:

```
hook  0x28092C (file 0x18092C): 3d00d4e5 'ldrb r0,[r4,#0x3d]' -> b32004eb 'bl 0x388C00'
cave  0x388C00 (file 0x288C00), 112 bytes, in the zero slack 0x388BD8..0x389000 (last RX page of .text)
  388c00 push {r1,r2,r3,lr}          ; r1 (= +0x3C) is live in init; 16 bytes keeps sp 8-aligned
  388c04 mov  r0,#0 ; strb r0,[r4,#0x41]    ; promoted marker = 0 (InitParam tail padding)
  388c0c ldrb r0,[r4,#0x3d] ; cmp r0,#1 ; bne done        ; only 30fps tasks are candidates
  388c18 ldr  r2,[r4]                 ; vptr at init time
  388c1c adr  r3,allow ; scan: ldr r1,[r3],#4 ; cmp r1,#0 ; beq keep ; cmp r1,r2 ; bne scan
  388c34 bl   0x2844AC ; cmp r0,#0 ; beq keep   ; nn::os::CTR::IsRunOnSnake
  388c40 mov  r0,#0 ; strb r0,[r4,#0x3d] ; mov r1,#1 ; strb r1,[r4,#0x41] ; b done
  388c54 keep: ldrb r0,[r4,#0x3d]
  388c58 done: pop {r1,r2,r3,pc}     ; r0 = mode, stored to +0x45 by init at 0x28093C
  388c5c allow: .word 0x3E3B3C, 0x3E10C4, 0x3DEBD8, 0x3E4874, 0
```

Why this point:
- One instruction for every task class. `init` is the only place that loads the InitParam into +0x3D; the
  ctor's default is 0 and no later writer of +0x3D exists (§2). After the hook, `init` stores the mode to +0x45
  and `funcInit` re-copies +0x3D every frame, so the mode is decided **before the first frame and before any
  init-time step is computed** (the field step at 0x302C68 runs after `init`, via 0x301674 → fn 0x302A64). This
  removes the latching problem of §5 and the cheat's 30fps start window.
- The allow-list uses the vptr that is in place when `init` runs (checked: each ctor stores its vptr before
  calling `init` — Boot 0x10930C, kj 0x196954, btl 0x28DB3C, fld 0x30B5C0 (object created once, `init` at each
  field start 0x30163C), MTaskBase 0x334698, HB HugeBattle:0x12802204). Menus call `init` inside the MTaskBase ctor,
  so all 8 menu-type tasks share the MTaskBase vptr there. `hb::HugeBattleSystem` is not listed → stays 30.
  To opt a class out, delete its word; to opt HB in, add its runtime vptr (CRO address) or compare a static
  slot instead.
- Old 3DS (and Azahar with New 3DS mode off): `IsRunOnSnake` = 0 → bytes unchanged → 30fps exactly as now.
- `fld::System` is re-`init`ed on every field entry from its stored InitParam (+0x580, fps byte +0x5B1 = 1), so
  the decision is re-taken each time; the stored param is never modified.
- Registers: called from `init` with r4 = this; r1 (= +0x3C) is preserved, r0 returns the mode; r2/r3/r12/lr
  are dead at 0x28092C (init's next instructions use r0, r1, r4, r6, r7 only). `IsRunOnSnake` is a normal
  AAPCS function (preserves r4–r11).

Side effects to expect (not engine bugs, but consequences of mode 0): every `isFps30` user switches to the ×1
step (field, battle, KJ, menus, events, text); input is sampled 60×/s; GPU budget per frame halves; code that
counts frames without the step (BTL action commands, CRS candidates) runs 2× fast.

Runtime opt-out of a promoted task (e.g. if the staff roll inside `fld::System` cannot be fixed): set
task+0x3D = 1 (back to 30) and later 0, only if task+0x41 == 1; it takes effect at the next frame. Caveat (§5): the
field step +0x1A4C is recomputed only while `fld+0x6E0` bit 0x40 is set — switch while it is set, or recompute
+0x1A4C with the 0x307074..0x30709C expression in the same hook. Prefer fixing the root cause (CRS).

Rejected alternatives:
- Patching the 5 creator stores (0x31CB48, 0x31CE44, 0x28EEA8, 0x197410, 0x3346C8): same effect, 5 hooks that each
  need a register-preserving cave (the stored register is reused after the store), and no single place for the
  New-3DS test.
- Mapping only in `funcInit` (0x13E8E4 `ldrb r1,[r4,#0x3d]`): the first frame and everything computed in `init`
  and the task ctor would still see 30fps (field step latched at 2.0 until state 8). Usable only together with
  the `init` hook.
- Writing +0x45: overwritten every frame by `funcInit`.
- Mode 2 instead of 0: identical to mode 0 here because no 3DX task enables stereo (+0x3E = 0 → +0x47 = 0).

## 10. Runtime checks (for RT) — what to look at and what to expect

Static pointers that make heap scanning unnecessary [confirmed]:
- **u32 0x3F40B4** = current TaskBase (the one that owns vsync); **u32[0x3F49B0+0x20]** = the persistent
  `fld::System`. Both are in the static image region, readable with the RPC client. Class = vptr at task+0
  (table §2), fps mode = u8 task+0x3D (persistent) / +0x45 (this frame), patch marker = u8 task+0x41,
  frame counter = u32 task+0x578 (+1 per `func` call), vsync-swap stamp = task+0x18C.

| # | scene | observation expected | how |
|---|---|---|---|
| 1 | unpatched, cheat-free field | task+0x3C..+0x3F = `01 01 00 01`, +0x44..+0x47 = `01 01 00 00`; +0x578 grows 30/s; "App: 30 FPS" | RPC read of [0x3F40B4] |
| 2 | unpatched + writing task+0x3D = 0 (GDB `M`) | next frame +0x45 = 0; +0x578 grows 60/s; "App: 60 FPS"; writing +0x45 alone reverts within one frame | confirms §0 items 1/2 |
| 3 | EUR/USA cheat mapping | at each matched address A: u32[A−0x3C] is a TaskBase vptr; A = 0x320DA3AC → `fld::System` | confirms §6 |
| 4 | patched (IPS from eng_patch.py), New 3DS mode | field/battle/KJ/menus: +0x3D = 0, +0x41 = 1, 60 FPS from the first frame; HB: +0x3D = 1, +0x41 = 0, 30 FPS; Boot unchanged | RPC + status bar |
| 5 | patched, Azahar New 3DS mode OFF | everything +0x41 = 0, 30 FPS, identical behaviour to unpatched | A/B |
| 6 | heavy scenes at 60 | slowdown appears as +0x578 < 60/s with no logic catch-up; note scene names | frame counter per second |
| 7 | field walking / event waits / text | same real-time speed at 30 and 60 (step ×1 vs ×2) | MOD's list |

## 11. Open questions

1. Executability of the cave on hardware: 0x388C00 is inside the last page of .text (0x388000–0x389000, the
   exheader text size rounds up to that page); expected RX under Luma's loader and Azahar. Confirm with test 4 on
   both. If not, use a smaller cave inside an unused function (none identified yet) or extend .text via
   exheader.bin.
2. Which field states clear `fld+0x6E0` bit 0x40 (fn 0x307234) — matters only for runtime switching.
3. Direct reads of task+0x3D in CROs were not audited one by one (static: only `init`/`funcInit` read it for
   tasks); a CRO that reads +0x3D for logic would still see 1 if a future patch maps only +0x45. With the
   recommended patch (+0x3D itself is changed) this does not matter.
4. GPU headroom at 60fps on hardware (PICA200 is not faster on New 3DS); the 2-list pipeline drops frames
   silently when the GPU is late.
5. HugeBattle's own loop (`hb::HugeBattleSystem::func`) and its nngx re-initialisation in the ctor
   (HugeBattle:0x12802218..0x12802234 `nngxGetCmdlistParameteri`/`nngxGetAllocator`/`nngxFinalize`/
   `nngxInitialize`) — for HB/CRS.

## 12. Patch-point table

| location | original | proposed | why | side effects |
|---|---|---|---|---|
| 0x28092C (file 0x18092C), in `TaskBase::init` | `3d00d4e5` `ldrb r0,[r4,#0x3d]` | `b32004eb` `bl 0x388C00` | single decision point for every task, before the first frame | none on Old 3DS; New 3DS: allowed classes run at mode 0 |
| 0x388C00..0x388C6F (file 0x288C00), zero slack after .text | 112 × `00` | `eng60_init` (above) | New-3DS test + per-class allow-list, writes +0x3D/+0x41 | uses InitParam tail padding +0x41 |
| allow-list words 0x388C5C..0x388C6B | — | fld::System 0x3E3B3C, btl::Main 0x3E10C4, kj::KJSystem 0x3DEBD8, msys::MTaskBase 0x3E4874 | opt-in per class; HB omitted | remove a word to keep that class at 30 |
| (optional) runtime switch | — | task+0x3D ← 1/0 when task+0x41 == 1 | per-scene opt-out (credits) | field step latch caveat, §9 |
