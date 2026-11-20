# MOD — 60fps readiness of field, events, text, menus, Bowser Jr.'s Journey, Colosseum, BCat, minigames

Worker: MOD. Target: 3DX JP v1.2 (`3dx_v12`). Static addresses are runtime addresses; CRO addresses are
`Module+fileoffset` (analysis address in brackets). Confidence tags: **confirmed** (read in disassembly),
**likely** (strong indirect evidence), **guess**. Tools written for this report: `scripts/fps60/mod_rtti.py`
(RTTI → typeinfo → vtable map for static + all CROs), `scripts/fps60/mod_fn.py` (function-level disassembly
with class/vslot labels, caller lists).

Status: complete (§0–§2.4 MOD wave 1; §2.5–§6 MOD2 wave 2, 2026-10-30).

## 0. Task classes (RTTI) — who owns each mode

`mod_rtti.py` finds 14 classes derived from `ad::fw::TaskBase` (vtable address, module):

| Class | Base | Vtable | Module | Mode |
|---|---|---|---|---|
| `Boot` | TaskBase | 0x3DCA1C | static | boot |
| `fld::System` | TaskBase | 0x3E3B3C | static | field + events + field text (msg) |
| `btl::Main` | TaskBase | 0x3E10C4 | static | battle (BTL) |
| `kj::KJSystem` | TaskBase | 0x3DEBD8 | static | Bowser Jr.'s Journey (KJRPG.cro has no task class) |
| `hb::HugeBattleSystem` | TaskBase | HugeBattle+0x16D9F4 [0x1296D9F4] | HugeBattle | giant battles (HB) |
| `msys::MTaskBase` | TaskBase | 0x3E4874 | static | base of all menu-like tasks below |
| `main_menu::MainMenuTask` | MTaskBase | MainMenu+0x25FAC | MainMenu | pause/main menu |
| `load_menu::LoadMenuTask` | MTaskBase | LoadMenu+0xEB60 | LoadMenu | title/file select |
| `save_menu::SaveMenuTask` | MTaskBase | SaveMenu+0x558C | SaveMenu | save |
| `shop::ShopMenuTask` | MTaskBase | ShopMenu+0x17268 | ShopMenu | shops |
| `kj_menu::KJMenuTask` | MTaskBase | KJMenu+0x4C564 | KJMenu | KJ menus |
| `col::ColosseumTask` | MTaskBase | Colosseum+0xC9E8 | Colosseum | amiibo/Colosseum? |
| `bcat::BCatTask` | MTaskBase | BCat+0x47F8 | BCat | Bowser Jr. RPG "BCat" (badge/data?) |
| `atk_mg::AttackMiniGameTask` | MTaskBase | AttackMiniGame+0x8A10 | AttackMiniGame | attack-piece minigames |

TaskBase vtable 0x3DCFCC (slot index = byte offset / 4): 0 `func` 0x13DBCC, 5 `funcInit` 0x13E8B8 (called by
`func` every frame through `[vt+0x14]` at 0x13DC00, so +0x45 is re-latched from +0x3D **every frame**),
6 `funcCalc` (per-frame logic; `msys::MTaskBase::funcCalc` 0x334678 is the named one, called from `func` at
0x13DF14 via `[vt+0x18]`), 9 `funcDrawUpper`, 11 `funcDrawUpperRight`, 13 `funcDrawLower`, 18 `callbackVSync`.
Per-mode `funcCalc`: `fld::System` 0x306BC4, `kj::KJSystem` 0x195D94, `btl::Main` 0x28B67C, all msys tasks
0x334678 (→ `MComSys` vtable slot 2 = `msys::MComSys::funcCalc` 0x32F40C).

## 1. fps mode at task creation — every MOD task is created at 30 (confirmed)

`InitParam::InitParam()` (0x24B240) defaults +0x31 = 0 (60fps); each creator then writes 1:

| Task | Where the fps byte is written | Instruction | Covers |
|---|---|---|---|
| `fld::System` (BootInfo mode 0 or 2) | 0x31CB48 in fn_31CADC (field config filler) | `strb ip,[r0,#0x31]` (ip = 1 from 0x31CAE4 `mov ip,#1`) | field, events, field text, field minigames |
| `fld::System` (BootInfo mode 1) | 0x31CE44 in fn_31CD94 | `strb r5,[r0,#0x31]` (r5 = 1 from 0x31CE38) | same |
| `kj::KJSystem` | 0x197410 in fn_196940 (KJSystem ctor) | `strb r6,[sp,#0x41]` (InitParam at sp+0x10; r6 = 1 from 0x196FF0, callee-saved, not rewritten before) | Bowser Jr.'s Journey (KJRPG.cro runs inside this task) |
| `msys::MTaskBase` (ctor 0x334688) | 0x3346C8 | `strb r1,[sp,#0x31]` (r1 = 1 from 0x3346AC `mov r1,#1`); also +0x32 = 0 at 0x3346E0 | MainMenu, LoadMenu, SaveMenu, ShopMenu, KJMenu, Colosseum, BCat, AttackMiniGame (every CRO `EntryTask` = `new` + derived ctor → MTaskBase ctor → `TaskMan::entry(gTaskMainMan)`, e.g. MainMenu+0xC68 [0x15000C68]) |

Field creation path (confirmed): fn_131D70 builds a 0x164-byte config on the stack (fn_306858 = InitParam ctor +
field config defaults), picks fn_31CADC / fn_31CD94 by `fld::BootInfo` byte 0x415E64 (`startKJMode` 0x30DCB8 writes
2, so KJ boot also goes through fn_31CADC), then `new fld::TaskMain` (fn_31D250, vtable 0x3E4134) → fn_3014E4 copies
the stored InitParam (fld::System+0x580, fps byte at **fld::System+0x5B1**) and calls `TaskBase::init` at 0x30163C.
The fld::System object itself is created once (fn_30B5B8, vtable store at 0x30B5C4) and kept in `[0x3F49B0+0x20]`.

So a static patch has only **four byte-write sites** for all MOD modes (0x31CB48, 0x31CE44, 0x197410, 0x3346C8).
Changing them changes the persistent byte +0x3D, which `funcInit` copies to +0x45 each frame; nothing later in
these modes rewrites +0x3D (searched: no other `TaskBase::init` callers for these classes).

## 2. Timing basis per framework (confirmed) — the engine is 60 Hz-step based

### 2.1 Field (`fld::System`)
Master step **fld::System+0x1A4C** = (isFps30 ? 2.0 : 1.0) × `[[task+0x574]+0x7C]` (global game-speed float, set to
1.0 at init) × **+0x1A48** (field fast-forward factor, 1.0 or the global float at 0x412C80). Written at:
- 0x302C94 (field init fn_302A64, isFps30 at 0x302C68, game speed and ffwd reset to 1.0 at 0x302C5C/0x302C60);
- 0x30709C (`fld::System::funcCalc` tail 0x307010, isFps30 at 0x307074; only when `[sys+0x6E0] & 0x40`),
  previous value kept at +0x1A50; then fed to two `fn_24D0C4` updaters (+0x1A88, +0x1AA0) and to the effect
  engine `fn_36F7EC([[task+0x574]+0x8C]+0x5C/0xDC, step)`;
- 0x31ED60 / 0x31EE7C (fn_31EC90 = fast-forward controller at fld::System+0x1AC0, isFps30 at 0x31ED3C/0x31EE5C).

```
00307074: bl   #0x25edd0          ; isFps30
0030707c: ldr  r0, [r4, #0x574]
00307080: vldreq s0, =1.0
00307084: vldrne s0, =2.0
00307088: vldr s2, [r6, #0x248]    ; fast-forward factor
0030708c: vldr s1, [r0, #0x7c]     ; game speed
00307094: vmul.f32 s0, s0, s1
00307098: vmul.f32 s0, s0, s2
0030709c: vstr s0, [r6, #0x24c]    ; field step
```
24 functions read the step directly (`mod_scan.py step-users`), including `fld::System::StateMain::v3`,
`fld::MainL::v34/v36`, 8 `fld::MainMiniMap` slots, fn_20D228 (field per-frame update that passes the step as
s0/s1 into ~10 sub-updaters: fn_210458, fn_210258, fn_20F6F4, fn_20EE18, fn_20EC9C …). The rest of the field gets
the step as a float argument.

### 2.2 Field text (message windows)
Text reveal is step-driven: `Message::func(u32,u32,u32,bool,float step)` 0x273BE0. Field path: fn_20D228 →
fn_20EC9C(MsgSys, s0 = s1 = field step) → `MoveC::update` for window motion (0x20EDB8) and fn_132804 → one
`Message::func` per window (0x132940; window type 0x401 gets the second step argument). So field text speed is
in real time at either fps mode (**confirmed**, BRIEF's "fld::MsgSys calls isFps30" was a mislabel: those isFps30
sites are the step computations above). Menus: `msys::MMsgWnd::v2` 0x331A0C and each menu CRO's MsgWnd::v2 call
`Message::func` with the MComSys step; KJ: `KJSystem::funcCalc` calls `MessageSys::func(float)` at 0x195FEC.

### 2.3 Event scripts (all modes share `GlobalEvent`)
`GlobalEvent` (ctor 0x24DC98): +0x14 = **event step float** (default 1.0). `GlobalEvent::execLocalEvent`
0x25BFA0 implements script waits as a float countdown in LocalEvent+0x28:
```
0025bfc8: vldr s0, [r0, #0x28]     ; wait remaining
0025bfd8: vldr s2, [r7, #0x14]     ; event step
0025bfdc: vsub.f32 s0, s0, s2
0025bfe0: vstr s0, [r0, #0x28]
0025bff4: movgt r0, #3             ; still waiting
```
So script waits are in 60 Hz units scaled by the step. Menus set the step every frame in `MComSys::funcCalc`
(0x32F458 `vstr s16,[r8,#0x14]`, r8 = MComSys+0xE651C). Field event executor: `fld::EventSystem::v8` 0x2B81A8
(execLocalEvent at 0x2B8224, `this` is the GlobalEvent). Who writes the field event step is still open (see 6).

### 2.4 Menus (`msys::MComSys`, shared by all 8 msys tasks)
`msys::MComSys::funcCalc` 0x32F40C: step = isFps30 ? 2.0 : 1.0 (0x32F41C..0x32F430) → fn_32EEF8(this, step)
(menu object/animation update; it calls `MessageSys::func` at 0x32F0EC) and the same value → event step
(0x32F458). Menu objects use `updateAnimeFrm(float)` (MLyt, MPageBase, MListWndPBase, MCellAnime, MMoveMsg …).



---
*(§2.5 onward: worker MOD2, wave 2, 2026-10-30. Tools added: `scripts/fps60/mod_sites2.py` (resolves what every
isFps30 site selects and who consumes it), `scripts/fps60/mod_kjscan.py` (decomp scan for per-call counters and
literal steps). Hit format: location / why frame-based / consequence at 60fps / proposed fix.)*

### 2.5 Bowser Jr.'s Journey (`kj::KJSystem`, KJRPG.cro, static `kj::`) — step-based, two cosmetic hits

**Master step (confirmed, `kj::KJSystem::funcCalc` 0x195D94 = decomp `kj::KJSystem::vfunc_0x18`).**
```
00195e8c: bl   #0x25edd0            ; isFps30
00195e9c: vldr s19, =2.0
00195ea4: vmoveq.f32 s17, s18       ; s18 = 1.0
00195ea8: vmovne.f32 s17, s19       ; s17 = unscaled step 2.0/1.0
...  KJSystem+0x61C58 = [[this+0x574]+0x7C] (dfx speed) * s17 * [this+0xC8D90]   (decomp line: *(float*)(this+0x61c58) = ...)
     or 0.0 when the lower-screen UI state machine (+0x63CBC handler != fn_185338, or +0x63CC0 != 0) is active
```
- `+0xC8D90` = KJ speed factor: 1.0, or **`kj::gParamProd+0x204` = 1.8** (fast-forward; `ldr r1,[gParamProd,#0x204]`
  at 0x195E44, stored at 0x195E4C) while bit 0x100 of the KJ `Input` hold word (+0x61C20) is down and fast-forward is
  enabled (+0xC8D94 bit 0x40, set by `kj::KJSystem::enableSkip` 0x193A80, called only by `kj::TaskProdStart::v2`
  KJRPG+0xBC8C and `kj::TaskProdWinLose::v2` KJRPG+0x149B0). **Fast-forward exists only in the battle productions**
  (march/intro before the fight, win/lose sequence after it): `kj::KJSystem::startBattle` 0x194338 sets the
  "battle running" bit 0 of +0xC8D94, clears bit 0x40 and resets +0xC8D90 to 1.0 (decomp static.c:124331..124340),
  unless bit 0x400 is set (only by `kj::TaskBtlSp::endForce` KJRPG+0x4B8A8, a forced end). The dfx speed
  `[[task+0x574]+0x7C]` has only 1.0 writers in the whole binary (field init, field fast-forward, btl), so **during
  the fight the KJ step is exactly 1.0 (mode 0) or 2.0 (mode 1)**. gParamProd defaults come from its static ctor
  fn_19CC78 (`param_1[0x81] = 0x3FE66666`), called from the C++ static-init fn_36A3E0. [confirmed]
- KJ step consumers in the same funcCalc: camera MoveVBase/MoveFBase (+0x4E658/+0x4E6E0/+0x4E72C), fn_338A40,
  fn_24D0C4(+0x4E460), every `ObjMan` object (+0x62E8C list, slot 2), `MessageSys::func(+0x7E728, step)` (KJ text),
  dfx units (fn_24CD20), MoveC list +0xC8298, `SlotDigits::update` ×2, MoveFBase +0xC8A38, and the **KJ event step**:
  `this+0x63018 = this+0x61C58` (0x19619C `ldr r1,[sb,#0x58]`; 0x1961A0 `str r1,[r0,r5]`, r0 = 0x63018; then the
  event units run at 0x1961AC `bl fn_170684`; `kj::EventSys` = GlobalEvent at KJSystem+0x63004, ctor fn_193820, so +0x14
  = +0x63018; its LocalEvents run through `GlobalEvent::execLocalEvent`). The unscaled s17 goes to MoveC ×2
  (+0x4E798), fn_18575C, fn_16B5D4, MoveC +0xC89F8 and the LocationUI fn_16D984 (static isFps30 site 0x16D998).
  [confirmed]
- Objects: `kj::ObjBase` slot 2 (update, 0x26B478) asks slot 6 for its step (`kj::ObjBase::vfunc_0x18` 0x3467A8 =
  `return [0x3F61C0]+0x61C58`) and feeds `CellAnime::update`, `MoveC::update` and its alpha-fade timer.
  `kj::ObjFontLose` 0x34525C and `kj::ObjFade` 0x3467D0 override slot 6 (the two static isFps30 getters): with their
  flag (+0x468 / +0x2DC) set they return the unscaled `isFps30?2:1`, so they keep running during a pause and ignore
  fast-forward. Unit movement uses `MoveVBase::move/moveFrm/moveFrmAbs/wait/jumpFS` (durations in 60 Hz frames)
  advanced by that object step. [confirmed]
- KJRPG.cro (army battle, captain/leader commands, battle productions) has no isFps30 call, but reads the KJ step
  directly: `bl ->kj::GetSys; add r0,#0x40000; add r0,#0x21C00; vldr sN,[r0,#0x58]`. `mod_hardstep.py`: of the 22
  update-primitive calls in KJRPG, 21 take that value (e.g. `kj::TaskBtlAtk::v2` KJRPG+0x4F04: `Frm::update(step)`
  ×2) and one takes a literal 1.0 (hit K3). Input is `kj::Input::getBtnTrg` 0x345A8C (+0x61C20+8, returns 0 while the
  lower-screen UI is busy), sampled once per frame; triggers are edge-based, so 60 Hz sampling loses nothing.
  The shared key-repeat helper `ad::ui::UICommon::KeyRep::update` 0x146B80 (callers: `ad::ui` list windows and
  Battle) counts down a float by its step argument, so held-direction repeat is time-based too. [confirmed]

So the real-time army battle advances through the KJ step: at fps mode 0 every float timer, move, animation, text and
event wait keeps its wall-clock speed. Code that **truncates the step to an integer** would be lossy for a fractional
step (fast-forward 3.6 at 30fps → 3, 1.8 at 60fps → 1). A scan of every `vcvt.u32/s32.f32` within 10 instructions of
a KJ-step load (KJRPG.s + static.s) finds exactly two such sites (K1, K2); both run only while the fight is running
(K1 is a battle command; K2 requires +0xC8D94 bit 0), where the step is an integer, so they are exact.

| # | Location | Why frame-based | Consequence at 60fps | Proposed fix |
|---|---|---|---|---|
| K1 | `kj::TaskSubLdCmdMikiriInput::v2` KJRPG+0x46D58 [0x14046D58]; `vcvt.u32.f32 s1,s0` at KJRPG+0x46D78 | counter `+0x20 += (u32)KJstep` (+0x24 = 0xFFFFFF lap size, laps in +0x28); pos = +0x24×+0x28 + +0x20; on A trigger or pos ≥ +0x1C (= target + 9): d = pos − target(+0x18, set by slot 4 `vfunc_0x10` KJRPG+0x4700C from its float argument); **great** if d ∈ [gParamCmd+0x3A8, +0x3AC] = [−9, 7], **good** if d ∈ [+0x3A0, +0x3A4] = [−13, 9] (gParamCmd ctor fn_198A18 `param_1[0xe8..0xeb]`), else miss. Units: 60 Hz frames | step 1.0: +1/frame at 60 = +2/frame at 30 → the same window in ms; at 60 the press is sampled every 16.7 ms instead of 33 ms, so the window can only gain one sample (**OK**). Fractional steps never reach it in normal play (fast-forward is off during the fight). [confirmed] | none. If fast-forward were ever enabled in battles (bit 0x400 path after `TaskBtlSp::endForce`), the counter would run at 60 u/s vs 108 u/s animations at 60fps (90 vs 108 at 30fps): RT2 can watch `[[0x3F61C0]+0x61C58]` during a fight to confirm it stays 1.0 |
| K2 | fn_17F91C (static, kj command update called from 0x17890C), 0x17F990..0x17F9A4: `+0x74 = (u16)(float(+0x74) + KJstep)` while +0x74 < +0x76 (`vcvt.u32.f32` 0x17F99C), only while KJSystem+0xC8D94 bit 0 (fight running) is set and bits 0x14 are clear | same truncation into a u16 counter | exact (integer step during the fight) | none |
| K3 | `kj::TaskProdMove::v2` KJRPG+0x7B54; `vldr s0,=1.0` KJRPG+0x7B90 → `Frm::update` KJRPG+0x7B9C | the task's Frm (+0x24) is armed with `Frm::play(+0x24, gParamProd+0x35C = 20.0)` and advanced by a literal 1.0 per frame; states 1/3 wait for it (+0x32 bit 0) | the pause in the march production between battles lasts 20 frames = 0.67 s at 30 but 0.33 s at 60 (cosmetic) | optional CRO edit: replace the literal 1.0 with 0.5 at mode 0 (needs a 2-instruction helper: not a 1:1 swap); accept for v1 |
| K4 | KJ sound-effect manager fn_19DE7C (KJSystem+0xC6B28, called from funcCalc): `vldr s17,=1.0` at 0x19DEE4; `fn_249D74(1.0, se)` 0x19DF00 (per-SE update callback with `speed×[se+0x44]`) and `Frm::update(1.0)` 0x19DF18 (SE auto-stop timer at entry+0x68, armed e.g. by fn_257E1C with gParamBattle+0x5FC frames for SE 0x14001F) | literal 1.0 per frame; the field passes its step to the same callback (fn_210458) | KJ SE fades/timed stops end 2× sooner (minor, audible) | static: replace `vldr s17,[pc,#0xec]` at 0x19DEE4 by `bl cave` that sets s17 = ([[0x3F61C0]+0x45]==1) ? 1.0 : 0.5 (patch P1, §4) |

Not hits: the `+0x2CC += 1` increments in KJRPG (`mod_kjscan.py`) are dfx-unit link counts, and the byte
increments (+0x54, +0x88, +0x0C, +0x10 …) are state-machine phase or repetition counters advanced on events (e.g.
`kj::TaskProdMove` +0x54 counts `Chr::execProdJump` repetitions up to gParamProd+0x358 = 2), not per-frame timers.
`kj::KJSystem` is created at mode 1 (§1, 0x197410); 1DX creates its counterpart `kg::KGSystem` at mode 0
(`1dx_compare.md`), so this code family is the 60fps-capable one. Button-mash style commands (e.g. fn_14039FC8
KJRPG+0x39FC8 counts presses in +0xBC) register at most one press per frame, so 60 Hz sampling allows up to 30
presses/s instead of 15 (harmless; humans mash below 15 Hz). **Verdict: ready at 60; K3/K4 cosmetic.**

### 2.6 Menu CROs: every isFps30 site, resolved (confirmed)

`mod_sites2.py` follows each isFps30 call (direct or through the CRO veneer) to the conditional selects that use it,
resolves the selected registers back to their constants (window-local defs and one-hop copies included) and names
the first callee that receives the value. Result for 3DX v1.2 (106 sites in the 8 menu-type CROs; 122 with the 14
static and 2 Battle sites):

| Module | sites | what the result selects | consumers (count) |
|---|---|---|---|
| KJMenu | 38 | all `2.0 / 1.0` step | `Frm::update` 13, `msys::MCursorBase::init` 10, internal page updaters (fn_1381FA10 ×3, fn_1380F200 ×2, fn_1380F684, fn_13815180, fn_1382174C, fn_13826590) 9, `LytAnim::update` 1, `MoveVBase::update` 1, stored for a later call 4 |
| MainMenu | 24 | 18 × `2.0/1.0`; 1 × integer `2/1` then `vcvt.f32.u32` (0x150065AC → `Frm::update`); **5 × result discarded** (0x15007494, 0x15019D30, 0x1501CD30, 0x1501D598, 0x1501D974: `r0` is overwritten by `ldr r0,=0x802` right after the call; decomp `ad::fw::TaskBase::isFps30(...)` with no assignment) | `MCursorBase::init` 8, `LytAnim::update` 5, `Frm::update` 4, `MoveVBase::update` 2, discarded 5 |
| ShopMenu | 17 | all `2.0/1.0` | `Frm::update` 13, `MCursorBase::init` 2, stored 2 |
| LoadMenu | 13 | all `2.0/1.0` (3 in fn_14806AC8 select through s17, which an earlier site of the same function already set to 2.0 with `vmovne.f32 s17,s18`) | `Frm::update` 12, virtual `blx r2` 1 |
| Colosseum | 11 | all `2.0/1.0` | `Frm::update` 10, virtual 1 |
| SaveMenu | 1 | `2.0/1.0` | `save_load::MsgWnd::v0` → virtual update |
| BCat | 1 | `2.0/1.0` | `MCursorBase::init` |
| AttackMiniGame | 1 | `2.0/1.0` | `atk_mg::AttackMiniGame::v1` → virtual update |

So the menu CROs are **consistent**: no site uses the flag for anything but a 60 Hz-unit step (or nothing). One
category matters for the design: **`msys::MCursorBase::init(MLyt*, float)` 0x324464 latches the step** into
`cursor+0x2C` (decomp: `*(float *)(this + 0x2c) = param_2;`), i.e. the value is fixed when the page/cursor is
built. 21 sites feed it (BCat 0x108008B4; KJMenu 0x13802EB0, 0x13803700, 0x1380DB48, 0x13810B40, 0x1381977C,
0x1381A97C, 0x138356E8, 0x138367FC, 0x13838DD0, 0x13839F3C; MainMenu 0x15002400, 0x15004F2C, 0x15009D88,
0x1500E728, 0x1500EA20, 0x150105FC, 0x15018438, 0x150213BC; ShopMenu 0x170135EC, 0x17013638). With D1 (mode decided
in `TaskBase::init`, before any page exists) they latch 1.0 and stay correct. With the cheat (flip after init) a
cursor built in the first 30fps frames keeps 2.0. For AUD's adaptive-isFps30 idea these 21 return addresses must
be excluded (a page built in a slow frame would keep a 2× cursor speed for its lifetime).

Steps that ignore the flag in menus (`mod_sites2.py --prims`: literal step passed to `Frm/MoveVBase/MoveC/
MoveFBase/CellAnime/LytAnim::update`, `updateAnimeFrm`, `Message(Sys)::func`): KJMenu 0, Colosseum 0, LoadMenu 0,
SaveMenu 0, BCat 0, AttackMiniGame 0, **MainMenu 8, ShopMenu 7** (all literal 1.0). Integer per-call counters
(`mod_kjscan.py --all`): none that time anything; the hits are repetition counters advanced when a step-timed
`Frm` finishes (MainMenu fn_15008C24 `+0x874--` then `Frm::play(+0x878, 40.0)`; fn_150147A8 `+0xF1EB0--` per jump;
LoadMenu fn_14806AC8 `[+0xF00]++` per finished animation; KJMenu fn_1380F684 `+0x7A34` 0/1 toggle), or the
`msys::MChrBase` destructor's reference count (`+600 -= 1`, every module).

| # | Location | Why frame-based | Consequence at 60fps | Proposed fix |
|---|---|---|---|---|
| M1 | MainMenu equip page name-bar slide: fn_1500D000 MainMenu+0xD000 arms `MoveVBase::moveSinAbs(+0x32C08 / +0x39D60, 16.0)` and sets state fn_1500C9C8 MainMenu+0xC9C8, which calls `MoveVBase::update(…, 1.0)` every frame (0x1500CA38, 0x1500CAC4; literal at 0x1500CA24) until not busy; the same literal in `MainMenu_EquipPage::Core::MovePnlNameBar::v4` 0x1500C104 and `MoveListCur::v4` 0x1500C454, and on the set-position path 0x1500D10C/0x1500D18C (no effect there: called right after `MoveVBase::stop`) | 1.0 per frame instead of the menu step | the 16-frame slide takes 0.27 s instead of 0.53 s (cosmetic; another MainMenu panel mover, fn_150062CC, passes the step) | accept for v1. A fix needs a CRO edit of the **patched** MainMenu.cro (R2) with a helper call (the 1.0 is a `vldr s0,[pc,#x]`, no 1:1 replacement yields 0.5 at mode 0 only) |
| M2 | MainMenu fn_1501153C MainMenu+0x1153C (callers 0x1501A400, 0x1501CF00): `Frm::update(1.0)` 0x150115F0 on a `Frm::play(+0x7D80, 7.0)` timer that gates `SndSys::stop(&0x3FBFA0, 8)` | literal 1.0 | the looping SE handled there (guess: a number-reel tick) stops/retriggers after 0.12 s instead of 0.23 s (minor audio) | accept |
| M3 | ShopMenu equip/buy panels: state fn_17010894 ShopMenu+0x10894 (`MoveVBase::update(+0xE128/+0x1504C, 1.0)` 0x170108C4/0x17010910 until not busy, then `DataPc::setEquip`), fn_1700FC24 0x1700FDB8, `shop::BuyPnlBase::ItemPnlBase::v0` 0x1700BD30, fn_17009648 0x1700965C, fn_17008410 0x17008484, fn_170084FC 0x17008584 | same as M1 (several are set-position calls right after `stop`) | shop panel slides 2× faster (cosmetic) | accept |
| M4 | MainMenu fn_150062CC: else-branch `Frm::update(1.0)` 0x150062F8 (when `+0xA34A` bit 0 is set) | literal 1.0 on one branch, step on the other | that branch's Frm runs 2× fast (cosmetic, rare path) | accept |

**Verdict menus (MainMenu, LoadMenu/title/file select, SaveMenu+SaveLoad, ShopMenu, KJMenu, BCat): ready at 60**,
cosmetic M1–M4 only. SaveLoad.cro has no task and no isFps30 site (library code of LoadMenu/SaveMenu); its update
primitives take the caller's step (`--prims`: SaveLoad none with literals).

### 2.7 Colosseum (`col::ColosseumTask`, msys)

Colosseum.cro is the boss/rematch "Coliseum" menu (strings `?COLISEUM`, `INS_ENEMY_NAME_TEXT`, `INS_TEXT_CONDITION`,
`btn_COIN_all`, `huge_*` list entries). Its 11 isFps30 sites are steps (§2.6), no literal steps, no frame counters.
The fights themselves are not run by this task: it imports `btl::GetBootInfo` + `GameMain::Change` (normal battle →
`btl::Main`, BTL/BTL2) and `hb::SetBootInfoColosseum` + `hb::GetColiseumResult` (giant battle → `hb::HugeBattleSystem`,
which D1 keeps at 30 and which plays Colosseum giant battles at speed 1.5, `hugebattle.md`). `col::BootInfo::
dataPartyBackup/Restor`, `saveBgm/restoreBgm` bracket the battle. **Menu ready at 60; battles = battle-mode and
HB verdicts.**

### 2.8 BCat (`bcat::BCatTask`, msys)

BCat.cro is the Blitty catalogue/exchange menu (layout `SHOP_L_BLOCAT.bflyt`, `BLOCAT_EXP_PNL`, message
`MES_Menu_reitem_01_Ekubon_brilock_shop_*`): one isFps30 site (step latched by `MCursorBase::init`, 0x108008B4), no
literal steps, uses `RandSys::get` only for presentation. **Ready at 60.**

### 2.9 AttackMiniGame (`atk_mg::AttackMiniGameTask`, msys)

AttackMiniGame.cro is the menu around the special-attack minigames (medals, best score, restart: `MEDAL_ONOFF`,
`BSCORE_IN`, `btn_MINIGAME_RESTART`, `INS_LIST_MINIGAME`). One isFps30 site (step to a virtual update). The minigame
itself runs as a battle: the CRO imports `btl::BootInfo::setModePcAtkMiniGame` + `btl::GetBootInfo` +
`GameMain::Change`, so its timing is the battle/attack-command timing of BTL/BTL2 (the BAI `+= 2` scripts, the
action-command windows), not menu code. **Menu ready at 60; minigame = battle verdict.**

### 2.10 Remaining modes

- **Boot** (title boot task, vptr 0x3DCA1C): already created at mode 0; `Boot::funcCalc` 0x3226D8 reads +0x45
  inline for its `MessageSys::func` step (engine.md §7). Nothing to do.
- **Title screen / mode select / file select**: the current task is `fld::System` (R1) plus the LoadMenu task
  (§2.6, ready). Field verdict: §2.1–2.3 and FLD (`field60.md`).
- **Field.cro** (46 functions, `fld::StaffrollCtrl` …): no isFps30; credits are CRD's (`credits/REPORT.md`).
- **KJGuide.cro / MenuGuide.cro**: 0xAC bytes of code each, no task, no timing.
- **HugeBattle.cro**: HB (excluded from the allow-list by D1).

## 3. Final table: mode → ready at 60 / needs fix / unknown

| Mode | Task (vptr) | Timing basis at mode 0 | Verdict | Patch point / runtime test |
|---|---|---|---|---|
| Boot | `Boot` 0x3DCA1C | already mode 0; inline +0x45 step for `MessageSys::func` | **ready** (unchanged) | — |
| Title, mode select, file select | `fld::System` (R1) + `load_menu::LoadMenuTask` (msys) | field step; MComSys step (LoadMenu: 13 step sites, 0 literals) | **ready** (menu part); field part → FLD | RT2 census (§5 R1) |
| Field, events, field text, field minigames | `fld::System` 0x3E3B3C | field step +0x1A4C, `Message::func(step)`, event step (§2.1–2.3) | step plumbing ready; 30fps-only assumptions → FLD `field60.md` | FLD |
| Pause/main menu | `main_menu::MainMenuTask` (msys 0x3E4874) | MComSys step: 18 step sites, 1 integer step, 5 discarded results | **ready**; M1, M2, M4 cosmetic (2× faster equip-page slide, a 7-frame SE timer) | optional CRO edit of the patched MainMenu.cro (not for v1) |
| Save | `save_menu::SaveMenuTask` + SaveLoad.cro | MComSys step | **ready** | — |
| Shops | `shop::ShopMenuTask` | MComSys step: 17 step sites | **ready**; M3 cosmetic (2× faster panel slides) | optional (not for v1) |
| Blitty catalogue (BCat) | `bcat::BCatTask` | MComSys step: 1 site (cursor latch) | **ready** | — |
| Colosseum (menu) | `col::ColosseumTask` | MComSys step: 11 step sites | **ready**; its fights are battles (BTL) or giant battles (HB, kept at 30 by D1) | §5 R6 |
| Attack minigames | `atk_mg::AttackMiniGameTask` (menu) → battle in `btl::Main` (`setModePcAtkMiniGame`) | MComSys step / battle step | menu **ready**; minigame = battle/action-command verdict (BTL2, BAI `+= 2` scripts) | §5 R7 |
| Bowser Jr.'s Journey: map, battles, captain commands, productions | `kj::KJSystem` 0x3DEBD8 + KJRPG.cro | KJ step +0x61C58 (also KJ event step, KJ text); integer only during the fight | **ready**; K3 cosmetic (0.33 s instead of 0.67 s march pause), K4 minor audio | K4: static P1 (optional); §5 R2–R4 |
| Bowser Jr.'s Journey menus | `kj_menu::KJMenuTask` (msys) | MComSys step: 38 step sites, 0 literals | **ready** | §5 R5 |
| Battle | `btl::Main` 0x3E10C4 | battle step | → BTL/BTL2 | — |
| Giant battles | `hb::HugeBattleSystem` | own real-time step | kept at 30 (D1) | HB |
| Credits | `fld::StaffrollCtrl` (Field.cro) inside `fld::System` | per-update scroll | → CRD | CRD |

Evidence on the lead's decisions: nothing against D1. In favour of deciding the mode at `TaskBase::init`: menu
cursors latch the step at creation (`MCursorBase::init` → `cursor+0x2C`, 21 sites, §2.6), so a mode flipped after a
page exists (the cheat) leaves those cursors at the old speed until the page is rebuilt.

## 4. Patch points (MOD scope)

No change is required for 60fps correctness in the modes covered here; the allow-list of D1 (`msys::MTaskBase`,
`kj::KJSystem`) is sufficient. Optional polish:

| ID | Location | Original | New | Why | Side effects |
|---|---|---|---|---|---|
| P1 (K4, optional) | static 0x19DEE4 (code.bin +0x9DEE4) in the KJ SE manager fn_19DE7C | `vldr s17,[pc,#0xec]` = bytes `3B 8A DF ED` (literal 1.0 at 0x19DFD8) | `bl cave_kjse`; cave: `ldr r0,=0x3F61C0; ldr r0,[r0]; ldrb r0,[r0,#0x45]; cmp r0,#1; vldreq s17,=1.0; vldrne s17,=0.5; bx lr` (same test as `isFps30`: +0x45 == 1; constants by `vldr` from cave literals: the ARM11 has VFPv2, no `vmov` immediate) | the SE manager advances every SE callback and SE stop timer by 1.0 per frame (60 Hz units only at 30fps) | KJ SE fades/auto-stops keep their 30fps duration in ms. Liveness checked: prologue 0x19DE7C `push {r4-r8,lr}`; r0 rewritten at 0x19DEEC before use, r1/r2 written before use (0x19DF28, 0x19DF68), flags re-set by `tst` at 0x19DF08; the loop back-edge (0x19DFC4 `bne 0x19DEEC`) skips the patched instruction; s16 loaded after it (0x19DEE8). Cave ≈ 9 words in D2's range |
| P2 (M1/M3, not recommended for v1) | MainMenu+0xCA24/+0xD0EC/+0xC0FC/+0xC44C literals, ShopMenu+0x10894 state etc. | `vldr s0,=1.0` → `MoveVBase::update` | needs a helper call per site (no 1:1 instruction yields 0.5 at mode 0 only); MainMenu.cro must start from the patched file (R2) and its CRR hash must be updated | cosmetic slide speed | CRO edits for a cosmetic effect; skip |
| P3 (K3, not recommended) | KJRPG+0x7B90 `vldr s0,=1.0` → `Frm::update` KJRPG+0x7B9C | same as P2 | same as P2 | cosmetic march pause | skip |

## 5. Runtime verification for RT2 (MOD scope)

KJSystem = `[0x3F61C0]`; KJ step = `[[0x3F61C0]+0x61C58]` (float); KJ flags `[[0x3F61C0]+0xC8D94]`
(bit 0 fight running, 0x40 fast-forward allowed, 0x80 fast-forward active); KJ speed factor `[[0x3F61C0]+0xC8D90]`.

| # | Scene | Action | Expected |
|---|---|---|---|
| R1 | title → file select | census at mode 0 (current task, every live TaskBase) | LoadMenuTask/msys tasks with +0x3D = 0 after the patch; cursor and list animations at normal speed |
| R2 | Bowser Jr.'s Journey, any army battle (title → Bowser Jr.'s Journey → new file reaches the first battle quickly) | sample the KJ step at 10 Hz through intro, fight and win sequence, with and without holding the fast-forward button (try R first, guess) | mode 0: 1.0 in the fight, 1.8 while fast-forwarding the intro/win sequence (bit 0x80 set), 0.0 while the lower-screen UI is open; mode 1: 2.0 / 3.6 / 0.0. **The step must stay 1.0 while bit 0 is set** (confirms K1/K2 are exact) |
| R3 | same battle | stopwatch the fight from "start" to the first unit contact, mode 1 vs mode 0 | equal within a frame or two (step-based movement) |
| R4 | same, captain timed command (guard/counter "Mikiri", button prompt over the unit) | press A on the cue at mode 0 | success as at 30fps; optional: read the task's +0x20/+0x18 (task found by vptr `kj::TaskSubLdCmdMikiriInput`) |
| R5 | Bowser Jr.'s Journey menu (X/Y menu) | open item/quest/record pages at mode 0 | cursor blink/move at normal speed (latched step 1.0) |
| R6 | Colosseum | start a normal rematch and a giant rematch | normal: `btl::Main` +0x3D = 0; giant: `hb::HugeBattleSystem` +0x3D = 1 (D1) |
| R7 | Attack minigame menu → start a minigame | census + play | `btl::Main` +0x3D = 0; action-command timing per BTL2 |
| R8 | pause menu → equip (gear) page; shop → equipment | switch items | name-bar/panel slide visibly ~2× faster at mode 0 than mode 1 (expected cosmetic M1/M3, confirms the analysis) |

## 6. Open questions

1. (from §2.3, previous MOD) Who writes the field event step (field GlobalEvent+0x14): not found by MOD2 in the
   field-step readers (fn_20DCB0, `fld::MainBase::v34`); belongs to FLD.
2. What `MCursorBase+0x2C` (latched step) drives in the cursor update (not traced; guess: cursor blink/slide speed).
3. `kj::TaskBtlSp::endForce` sets +0xC8D94 bit 0x400, which makes the next `startBattle` keep fast-forward enabled:
   can a fight then run with a fractional step (K1 window drift)? Edge case; R2 would show it.
4. M2/K4 audio timers: which SEs actually use them (only the KJ water-landing SE 0x14001F was traced).
