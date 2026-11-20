# CRD — staff roll (credits) at 60fps: event script, fix, test bed

Worker CRD, wave 2, 2026-10-30. Written incrementally; sections marked (WIP) are not finished.
Inputs: BRIEF.md §1–5, BRIEF2.md §0–1 + CRD, `analysis/crash.md` §1, `analysis/1dx_compare.md` §2.
Confidence: **confirmed** (read in code/data), **likely**, **guess**.
Tool written for this report (read-only): `scripts/fps60/crd_fevent.py` (field-event decoder; see §1.1).
Also: `scripts/fps60/crd_staffroll.py` (exact roll model, §3), `scripts/fps60/crd_testbed.py` (test bed, §6).

## Status / TL;DR (complete; runtime items are for RT2)
- The credits are field event command 0x280 in rooms `zi_areanone_staffroll_01_U/L` (0x2C2/0x2C1; Bowser Jr.'s
  Journey: `zo_areanone_k_staffroll_01_U/L` 0x2C4/0x2C3). The roll thread is `update(); wait(1); isFinish?`,
  i.e. **one update per frame: 30/s at 30fps, 60/s at 60fps**; everything else is step-scaled real time (§1–§2).
- Unfixed 60fps: the text scrolls 2× fast and ends ≈ 112 s into the 214-s `04_end_roll` (normally together),
  then sits frozen ≈ 100 s. Same buffers/states per update as at 30fps (Korean file: max 385/1,024 u16) (§3).
- **No rate-dependent crash path exists in the roll or the two rooms' scripts** (§4). The community's
  deterministic credits crash is most likely hardware-side (frame budget/GPU, H1) or cheat-state (H2);
  RT2 runs R1–R4 (§7) to separate them; the lead runs R4 on a New 3DS.
- Fix CRD-1 = IMPL `--credits-fix`, validated and made exact: hook the NOP at **0x2E8B9C** (after
  `bl 0x131798` init), halve `ctrl+0x28` and set `P0=2, P4=0` (fade-in) when `fld::System+0x45 != 1` (§5).
- Test bed: `work/fps60/credits/testbed/` — A: save redirect (load file 1 → credits start at once), B: room warp
  in FEvent.dat; install/remove steps in §7.

## 1. Field event scripts and the VM (confirmed)

### 1.1 Storage and decoder
- `FEvent/FEvent.dat` (v1.2: `romf2/FEvent/FEvent.dat`, BG4 v261, 1,428 entries, BLZ-compressed), one
  `<room>.fev` (scripts) + `<room>.fme` per room. Room id → name: char* table **0x3F5674** (719 rooms), used by
  `fld::MainBase::ProcessLoadEventData::vfunc_0x8` 0x3170E8 (`strncat(name,".fev")`).
- `.fev` layout (from `FUN_002ec050` = op06a and `fld::...` loaders): u32 at +0x14 = offset S of the script
  section; `S: u32 N; N × u32; then script entry offsets (relative to S)`; script k starts at
  `S + S_u32[N+1+k]` (`piVar5[*piVar5 + k + 1]`). **Jump targets and string operands inside the code are
  absolute file offsets** (they land exactly on instruction / string boundaries).
- Bytecode = the same AlphaDream VM as battle AI (`GlobalEvent::execLocalEvent` 0x25BFA0):
  `u16 op; u32 varmask; [u16 result var]; params`. Field **argument-descriptor table = 0x3A0874**
  (16 bytes × 645 = 0x4E base + 567 field ops; it ends exactly at `GlobalEvent::_CmdFuncTbl` 0x3A30C4;
  located by matching the battle table's 0x4E base entries — two other copies exist at 0x3A91A0/0x3AC204 for
  other VMs). Handlers: base ops `0x389918 + 8·op`, field ops `0x3A30C4 + 8·(op−0x4E)`.
- Variables (GetRegFlag 0x2762CC / PutRegFlag 0x2731A0): `$1xxx` LocalEvent+8 floats (per thread), `$2xxx`
  bits / `$3xxx` floats in buffers owned by **each LocalEvent** (+0x34/+0x30, cleared by the script start
  `FUN_002a37ac`), `$4xxx` GlobalEvent vars, `$7xxx` system vars, `$Cxxx` global story flags (0x3F99A8).
  So `$3000` in two actor threads is two different variables.
- `python scripts/fps60/crd_fevent.py dis <room>.fev` disassembles a room; `grepop <op> [p0=<v>]` scans all
  rooms; `rooms <id|substr>`; `desc <op>` prints descriptor + handler.

### 1.2 Ops used by the ending (handlers read in the decomp)
| op | meaning (evidence) |
|---|---|
| `wait(n)` op005 0x133EC4 | `if n: LocalEvent+0x28 = (float)n; return 3` (stop this frame). `execLocalEvent` 0x25BFC8: `if (t>0) { t -= GlobalEvent+0x14; if (t>0) return 3; t = 0 }` |
| `jmpif(cmp,a,b,?,target)` op003 | jumps to target when the comparison is **false** (if-block skip) |
| `jump(kind,target)` op004 | kind 0/2 jump, 1 call |
| `op052(actor, flag, offset)` 0x2EB8F0 | start the script at `offset` on actor `actor`'s own LocalEvent (actor+0x1C) = a parallel thread |
| `op053(actor)` 0x2EC4C0 | if that actor's script still runs (`+0x830 & 2`): rewind + return 3 → **wait for the thread to end** |
| `op06a(f, room<<16|k, slot)` 0x2EC050 | start script k of the **other screen's** room (checks the room id) |
| `op06b(f, offset, slot)` 0x2ED3BC | start a script of this file on the other screen's event system |
| `op18a(room, x,y,z, …)` | room change (targets below) |
| `staffroll(sub)` op280 0x2E8B24 | 0 `CreateStaffrollCtrl`+`init` → `fld::System+0x1B3C`; 1 `update`; 2 result = `ctrl && ctrl+0x18 && !isFinish`; 3 delete |

### 1.3 Event step = field step (confirmed)
`fld::EventSystem::vfunc_0x34(float)` 0x2A8AF0 writes GlobalEvent+0x14 of both room GlobalEvents;
`fld::MainBase::vfunc_0x14` 0x30FD90 calls it every frame with **`fld::System+0x1A4C`** (= `isFps30?2:1` ×
game speed × fast-forward, `modes.md` §2.1); the resident system gets the same value in `FUN_0020dcb0` /
`FUN_0020e02c`. So waits are in 60 Hz units at both modes.

## 2. The ending sequence (main game) — decoded (confirmed)

Entry: `o_peach_t_06_lastboss_03_U.fev` +0x481B `op18a(0x2C2 zi_areanone_staffroll_01_U, …)` and +0x65D6
`op18a(0x2C1 zi_areanone_staffroll_01_L, …)` (also reachable from the debug room `o_evselect_U.fev`
+0x1084F/+0x10876). Bowser Jr.'s Journey has its own roll: `zo_areanone_k_staffroll_01_U/L` (0x2C4/0x2C3),
entered from `k_o_koopa_19.fev` +0xF95F/+0xF97C; same op280 sequence at +0x109F/+0x1762/+0x1773/+0x16D1.

`zi_areanone_staffroll_01_U.fev` (upper screen, 3,684 B decompressed), script #2 (main), excerpt:
```
00779: $1000 = staffroll(0)                    ; create + init
...                                            ; camera, 8 picture models fmd_dv_ed_u_01..08 (actors 4..0xB)
009f1: wait(0x96)                              ; 2.5 s
009f9: op06a(0, 0x2c10001, 4)                  ; L-screen script 1
00a05: wait(0xb4)                              ; 3 s
00a94: op052(0xd, 0, 0xb6e)                    ; actor 0xD runs script #3 = the roll loop
00aa0: op06a(0, 0x2c10003, 4)                  ; L-screen slideshow
00aac: op052(0xe, 0, 0xbaf)                    ; actor 0xE runs script #4 = U-screen slideshow
00ab8: op053(0xe)                              ; wait for the slideshow (wall-clock, 60 Hz units)
00abf: wait(0x262)                             ; 10.2 s
00ac7: op06a(0, 0x2c10004, 4)
00ad3: op053(0xd)                              ; wait for the roll thread to finish
00ada: wait(0x2d0)                             ; 12 s
00ae2: op06b(0, 0xcdd, 4)                      ; fade out (other screen)
00b10: $1000 = staffroll(3)                    ; delete
00b32: op06b(0, 0xd48, 4)                      ; L screen -> op18a(0x121 o_areanone_end_02_L)
00b47: op18a(0x1c6, …)                         ; U screen -> o_koopa_end_01
; script #3 (actor 0xD) — the only frame-based part:
00b6e: $1000 = staffroll(1)                    ; update(): frame += 1
00b77: wait(1)
00b7f: $3000 = staffroll(2)                    ; still running?
00b88: jmpif(0, $3000, 1f, 0, 0xba5)           ; if !running -> return
00b9a: jump(0, 0xb6e)
; script #4 (actor 0xE): wait(0x294) then 9 × [wait(0x4c3) + black appear/vanish anim + next picture]
```
Update cadence (confirmed from the wait mechanics): after `wait(1)` the timer is 1.0; the next frame subtracts
the step: 30fps 1−2 = −1, 60fps 1−1 = 0, both `≤ 0` → the loop runs again in that frame. **One `update()` per
field frame at both modes = 30 updates/s at 30fps, 60 updates/s at 60fps.** Everything else in the room
(slideshow, fades, the 610/720-frame tails, the L screen) is step-scaled wall-clock time.

## 3. Timing model with the shipped (Korean) data (confirmed)

`python scripts/fps60/crd_staffroll.py` (exact float32 model of init/update/builder/isFinish from the Field.cro
decomp; params from the static ctor at 0x36509C: `P0=P4=1, P8=-140, PC=3, P10=-2, P14=20, P18=2.0`):

| data | cadence | updates to isFinish | wall clock | distinct line windows | max text buffer A / B (limit 0x400 u16) | anomalies |
|---|---|---|---|---|---|---|
| patch (Korean) | 30fps stock (2 px/update, 30/s) | 6,158 | 205.3 s | 1,091 | 385 / 385 | 0 |
| patch (Korean) | 60fps unfixed (2 px/update, 60/s) | 6,158 | **102.6 s** | 1,091 | 385 / 385 | 0 |
| patch (Korean) | 60fps + fix (1 px/update, 60/s) | 12,314 | 205.2 s | 1,090 | 385 / 385 | 0 |
| JP v1.2 original | (same three rows: identical numbers) | | | | | |

- R3 check: the shipped `Staffroll/JP/Staffroll.bin` differs from the original in **one line only**: line 28,
  `Mario&LuigiRPG3 DX` (18 u16) → `마리오&루이지 RPG3 DX` (15 u16), same height (24 px). Every other line is the
  original English staff text, so line heights, total (12,312 px) and the worst windows (lines 294–322) are
  unchanged. (`crash.md` §1.3 was right about the numbers but wrong that the file is byte-identical.)
- The 60fps fix visits every pixel position instead of every second one; no new worst case appears (385 u16 is
  reached at the same windows). The builder never gets an empty/unfound window (idx1 always found because
  `pos ≤ total = Σh − 500`).
- BGM: the room prepares stream `0x0100032C` (`op228(0, 0x100032C, 1)` = `SndSys::prepare`, handler 0x2ED570)
  right after `staffroll(0)` and starts it at +0x952 (`op228(…,0)` = play; `op229(slot,fade)` 0x2EC514 = stop).
  The roll thread starts ~571 frames (≈9.5 s: waits 150 + 180 + two 120-frame fades) later, so at 30fps the roll
  ends ≈ 214.8 s after the music starts — the 214.0-s non-looping `04_end_roll` stream (crash.md). The ending
  is authored so text and music end together. **Unfixed 60fps: the text ends ≈ 112 s into the song and stays
  frozen on the last screen for ~100 s** while the slideshow, the music and the L screen continue in real time.

## 4. Crash mechanism at 60fps — what the code allows (static, confidence noted per line)

What is fps-dependent in the credits (complete list for the two credits rooms, confirmed):
1. The roll (`fld::StaffrollCtrl`, Field.cro): frame-based, 2× fast. Field.cro has no `isFps30` call and reads
   no fps byte. **Per update it behaves identically at both modes** (same `frame` sequence, same positions,
   same windows, same buffers): the cheat changes only the call rate. All 6,158 states simulated (§3): no
   out-of-range index, no unfound window, buffers ≤ 385 of 1,024 u16. → No crash path inside the roll
   (**confirmed** for init/update/builder/isFinish; MessageSimple::play copies ≤ 385 u16 into its own
   0x1000-byte buffer, `this+0x5AD2`, so no overflow there either).
2. The scripts: every other timer is a step-scaled `wait`; threads synchronise only by `op053` (wait for a
   thread) and the `$C35B/$C35C` screen handshake, never by frame counts. The early end of the roll thread
   (actor 0xD) is observed only by `op053(0xd)`, which the main thread reaches later at both rates. → No
   rate-dependent ordering bug in the scripts (**confirmed** by decoding both rooms, U and L).
3. Allocation/lifetime: the ctrl, its font (`mario_font.bffnt`, 288 KB) and text (40 KB) are allocated once in
   `staffroll(0)` and freed once in `staffroll(3)`; nothing is allocated per update. Same at both modes.

So, statically, unfixed 60fps credits are **wrong but deterministic**: text twice as fast, ends ≈ 112 s into
the 214-s song, last screen frozen ≈ 100 s, then the normal ending (fade, delete, rooms 0x1C6/0x121). I found
**no deterministic crash mechanism that depends on the update rate** (confidence: high for roll + scripts;
the engine-side per-frame cost is not modelled). The community crash ("credits crash without fail unless 30 is
restored", `research/web.md` R13, console, Luma cheat engine, "Less Crashes" variant) is therefore most likely
one of (ranked):
- **H1 (likely, hardware only): frame budget.** This is the steadiest heavy scene of the game: every frame
  rebuilds and re-lays out four centred text windows (≈ 2 × 385 glyphs + shadows) on top of two 3D screens
  with full-screen picture models. At 30fps it has a 33 ms budget; at 60fps on a real New 3DS it probably
  overruns 16.7 ms every frame. ENG §4 says an overrun is a slowdown in the engine core, so a crash needs
  something more (e.g. the C2 GPU-list/deferred-free timing of `crash.md` §2.2 under *sustained* overrun with
  dropped frames). Testable on hardware only (Azahar is lax about GPU timing). Not testable by RT2 on Azahar.
- **H2 (possible, weakened): cheat-specific state.** The cheat flips the byte at runtime; the field step
  `fld::System+0x1A4C` is recomputed per frame only while `fld+0x6E0 & 0x40` (ENG §5). Static: the bit is set
  when the field state machine reaches state 8 (0x30B2F0) and cleared by fn 0x307234 (0x3072A8, then state
  0x19), so it should be set while the credits rooms run and the step should follow the cheat's mode. If RT2
  sees the bit clear during the roll, the whole ending would run on a stale step (2× fast, room change ≈ 100 s
  before the 214-s stream ends → two streams overlapping in the next room). With D1 (mode decided at
  `TaskBase::init`) this class cannot happen.
- **H3 (unlikely): Luma cheat-engine/kernel race** (`research/web.md` §3) — it does not depend on 30/60.

## 5. The fix — IMPL `--credits-fix` validated, with corrections (confirmed)

Design (IMPL brief): after `StaffrollCtrl::init` in op280 sub-op 0, if the field task runs at 60fps, halve
`ctrl+0x28`. Validated: `isFinish = frame·speed > total` and `pos = frame·speed − 2` use the speed only
through the product, so 1 px/update at 60 updates/s reproduces the 30fps wall clock exactly (12,314 updates =
205.2 s vs 205.3 s), visits a superset of the 30fps positions, and keeps the buffer maximum at 385 u16 (§3).
The fade-in uses `frame < P0 = 1` (one update) and is unaffected. One patch covers both rolls (main game and
Bowser Jr.'s Journey; both rooms use op280 inside `fld::System`).

Exact hook (from the disassembly of 0x2E8B24; `armdis.py 3dx_v12 0x2e8b24 76`):
```
002e8b70: ldr r5, [r1, #0x130]       ; r5 = fld::System (the task: +0x45 fps byte, +0x1A4C step, +0x1B3C ctrl)
002e8b80: bl  #0x131790              ; CreateStaffrollCtrl (import stub)
002e8b90: str r0, [r1, r5]           ; System+0x1B3C = ctrl
002e8b98: bl  #0x131798              ; StaffrollCtrl::init(ctrl, System, alloc, 0x7f)
002e8b9c: nop                        ; e320f000   <-- hook here: bl cave_credits
002e8ba0: nop                        ; e320f000   (keep)
002e8ba4: b   #0x2e8c30              ; -> vmov s0,s16 ; PutRegFlag(...)  (uses s16, r6, r7, r8 only)
```
At 0x2E8B9C r0–r3, r12, s0–s15 are dead (init's result is unused; 0x2E8C30 reads only callee-saved s16/r6–r8);
r5 survives `init` (callee-saved). The NOPs are plain code (static.crs has `InternalRelocationNum = 0`; its 222
external relocations patch only the import stub words), so the RO loader never rewrites them. Proposed cave:
```
cave_credits:                        ; called with bl from 0x2E8B9C, lr = 0x2E8BA0
    ldrb  r0, [r5, #0x45]            ; fps mode of this frame (funcInit copies +0x3D every frame)
    cmp   r0, #1                     ; 1 = 30fps (same test as isFps30 0x25EDD0)
    bxeq  lr
    add   r0, r5, #0x1000
    ldr   r0, [r0, #0xB3C]           ; ctrl = System+0x1B3C
    cmp   r0, #0
    bxeq  lr
    vldr  s0, [r0, #0x28]            ; speed (P18 = 2.0)
    vldr  s1, half
    vmul.f32 s0, s0, s1
    vstr  s0, [r0, #0x28]
    bx    lr
half: .float 0.5
```
Corrections to the brief's wording: (a) test `+0x45 != 1` (isFps30 semantics; mode 2 is also 60 Hz logic) —
equivalent to `== 0` for this game; (b) **do not use `vmov.f32 sN, #imm`**: the 3DS ARM11 has VFPv2, VMOV
(immediate) is VFPv3 → undefined instruction; use a literal (above) or `ldr r1,[r0,#0x28]; sub r1,r1,#0x800000;
str r1,[r0,#0x28]` (exponent −1, exact for 2.0); (c) no stack use, no `push` needed. Unicorn test for IMPL:
fake System with +0x45 ∈ {0,1}, +0x1B3C → ctrl with +0x28 = 2.0, ctrl NULL case; expect 1.0 / 2.0 / no write.

Proposed cave (v2, includes the fade-in, per the lead's steering note):
```
cave_credits:                        ; bl from 0x2E8B9C (replaces the first nop), returns to 0x2E8BA0
    ldr   r1, lit_param              ; 0x415E38 = fld::GetParamStaffroll(): P0 (+0), P4 (+4)
    ldrb  r0, [r5, #0x45]            ; fps mode of this frame (funcInit copies +0x3D every frame)
    cmp   r0, #1                     ; 1 = 30fps (same test as isFps30 0x25EDD0)
    moveq r2, #1                     ; 30fps: stock P0 = 1, P4 = 1
    moveq r3, #1
    movne r2, #2                     ; 60fps: P0 = 2 -> fade-in over 2 updates (= 33 ms, as at 30fps)
    movne r3, #0                     ;        P4 = 0 -> P0+P4 stays 2, so pos = frame*speed - 2 is unchanged
    str   r2, [r1]
    str   r3, [r1, #4]               ; (flags from cmp survive the stores)
    bxeq  lr
    add   r0, r5, #0x1000
    ldr   r0, [r0, #0xB3C]           ; ctrl = System+0x1B3C
    cmp   r0, #0
    bxeq  lr
    vldr  s0, [r0, #0x28]            ; speed (P18 = 2.0)
    vldr  s1, half
    vmul.f32 s0, s0, s1
    vstr  s0, [r0, #0x28]            ; 1.0 px/update
    bx    lr
half:      .float 0.5
lit_param: .word 0x415E38
```
Fade-in detail (Field+0x9F8, confirmed): `alpha = frame < P0 ? frame*255/P0 : 255`, `P0 = 1` → stock 30fps:
alpha 0 for the first update (33 ms), then 255. Unfixed or speed-only fix at 60: 0 for 17 ms. With `P0 = 2`
at 60: 0, 127, 255 over 33 ms. P0/P4 are read **only** by `StaffrollCtrl::update` (`GetParamStaffroll` has no
other users: Field.c init reads +0x14/+0x18, update reads +0/+4/+8/+0xC/+0x10/+0x14), so the write is local to
the credits; writing both values in both modes keeps it idempotent. (Visible effect is one frame; it can be
dropped if cave space matters — the speed halving is the part that matters.)
Corrections to the brief's wording: (a) test `+0x45 != 1` (isFps30 semantics; mode 2 is also 60 Hz logic) —
equivalent to `== 0` for this game; (b) **do not use `vmov.f32 sN, #imm`**: the 3DS ARM11 has VFPv2, VMOV
(immediate) is VFPv3 → undefined instruction; use a literal (above) or `ldr r1,[r0,#0x28]; sub r1,r1,#0x800000;
str r1,[r0,#0x28]` (exponent −1, exact for 2.0); (c) no stack use, no `push` needed. Unicorn test for IMPL:
fake System with +0x45 ∈ {0,1}, +0x1B3C → ctrl (+0x28 = 2.0) or NULL, a writable page at 0x415E38; expect
(speed, P0, P4) = (1.0, 2, 0) / (2.0, 1, 1) / NULL: no ctrl write; r4–r11, sp, s16 unchanged.

Fallback, only if a crash is still seen with the fix: run the credits rooms at 30fps (crash.md C3-a) by writing
`System+0x3D = 1` in this cave instead of halving (only when `System+0x41 == 1`, i.e. promoted by D1) and
`System+0x3D = 0` after `staffroll(3)` (delete path 0x2E8C28–0x2E8C2C). The mode then changes at the next
frame's `funcInit`, and the field step follows because the field recomputes `+0x1A4C` every frame while
`fld+0x6E0 & 0x40` (static: the bit is set when the field state machine fn 0x30A9D8 reaches state 8 at
0x30B2F0, cleared at 0x3072A8 by fn 0x307234, which then sets state 0x19 — so it is set while a room runs;
RT2 confirms in the credits). Not recommended unless needed: it gives up 60fps in a scene that works.

## 6. Test bed (built and verified; nothing written to `patch/` or the user's Azahar)

`python scripts/fps60/crd_testbed.py status | build | verify` (read-only on its inputs; `verify` = OK).
Files: `work/fps60/credits/testbed/` — `MANIFEST.json` (sha256 of inputs/outputs, exact changes),
`save_credits/ML3R_001.sav` (variant A), `romfs/FEvent/FEvent.dat` (variant B).

Saves in the test instance (`tools/azahar-test/user/sdmc/…/title/00040000/001ca900/data/00000001/`):
`ML3R_001.sav` (75,968 B = SaveData1 0x28C0 + SaveData2 0x10000, `Backup::copySaveData` 0x3392C4) = a story
file in **upper room 0x24D `o_peach_t_04`, lower room 0xA8 `i_tainai_01`** (room block at file+0x297C, read
by the field start: `DAT_00415E6A/6C = u16 [SaveData2+8+u32[+8] + 2/+4]`); `ML3R_002.sav` has an empty field
block (no field progress; not usable); `ML3R_000.sav` is 4 bytes of system data. No checksum is applied in
`Backup::readSaveData2` 0x339778 (plain memcpy into gGameWork) — likely none; RT2's load confirms.

- **Variant A (recommended): save redirect.** Copy of ML3R_001.sav with the two room ids set to 0x2C2
  `zi_areanone_staffroll_01_U` / 0x2C1 `zi_areanone_staffroll_01_L` (3 bytes differ: 0x297E, 0x2980, 0x2981).
  Loading file 1 starts the field in the credits rooms; each runs its entry script (the room start code
  0x310C90.. uses the `.fev` default entry `u32 [+0]` unless an entry override is given: U default #1, L #0;
  U #0 also leads into the same main script), so the **real ending runs unmodified** (roll, both slideshows,
  `04_end_roll`, fade, delete, rooms 0x1C6/0x121 afterwards). Expected time from "load" to the first roll
  update ≈ 10 s.
- **Variant B (backup if A misbehaves): room warp.** `FEvent.dat` (from `romf2`, not in `patch/`) where the
  default entry of `o_peach_t_04.fev` (#24) and `i_tainai_01.fev` (#55) points to appended code copied from the
  story lead-in (`o_peach_t_06_lastboss_03_U.fev` +0x481B / +0x65D6 / +0x4838): `op18a(0x2C2|0x2C1, 0f, 0f, 0f,
  8, 0, -1, 3, 0); return(0f)`. The two credits rooms synchronise the screens themselves (`$C35B/$C35C`
  handshake). FEvent.dat is not a contiguous BG4 (entries share data), so the tool keeps every original byte
  and appends the two re-compressed entries at the end (only their table words change; all other 1,426
  entries decompress identically — verified). Caveat: the saved room's field BGM may keep playing on slot 1
  (the story stops it with `op229(1, 0x3C)` before the warp).

## 7. Exact steps for RT2 (emulator owner)

Common: follow `HARNESS.md` (launch only with `rt_launch.ps1`, clients via Start-Process + WaitForExit ≤ 120 s).
`$d = "tools\azahar-test\user\sdmc\Nintendo 3DS\00000000000000000000000000000000\00000000000000000000000000000000\title\00040000\001ca900\data\00000001"`

Install A (emulator stopped):
```powershell
if (-not (Test-Path "$d\ML3R_001.sav.crd_orig")) { Copy-Item "$d\ML3R_001.sav" "$d\ML3R_001.sav.crd_orig" }
(Get-FileHash "$d\ML3R_001.sav.crd_orig" -Algorithm SHA256).Hash   # must be 43C2CA72CB6A5FF26174906C62506AE27743EACE6648E4AD2F49AB6ED8EED7CB
Copy-Item "work\fps60\credits\testbed\save_credits\ML3R_001.sav" "$d\ML3R_001.sav" -Force
(Get-FileHash "$d\ML3R_001.sav" -Algorithm SHA256).Hash            # 289EBB5746D734F9752C7851A0C1A1DBDDA497B7DB86D8CB4479D80E6508EE10
```
Remove A (emulator stopped; the game may have written the file meanwhile): `Copy-Item "$d\ML3R_001.sav.crd_orig"
"$d\ML3R_001.sav" -Force`, re-check the 43C2… hash, then `Remove-Item "$d\ML3R_001.sav.crd_orig"` (one file).
Install B: only into a REAL mods folder made by `rt_mods.py use-build <tag>` (never the junction, R5): assert
`(Get-Item tools\azahar-test\user\load\mods\00040000001CA900).LinkType` is empty, then copy
`work\fps60\credits\testbed\romfs\FEvent\FEvent.dat` to `…\mods\00040000001CA900\romfs\FEvent\FEvent.dat`; log line
`LayeredFS replacement file in use for /FEvent/FEvent.dat`. Remove B: `rt_mods.py use-patch` (re-verifies the junction).

Runs (each: boot → title → story → file select → file 1 → load; with A the credits start at once):
| # | code | how 60fps is set | expected (ctrl+0x28 / updates per s / roll length) |
|---|---|---|---|
| R1 | stock (patch junction) | — | 2.0 / 30 / 6,158 updates ≈ 205 s; text ends with the music |
| R2 | stock | `rt_measure.py setfps 0 --offset 0x3D` as soon as `[0x3F40B4]` has vptr 0x3E3B3C after the load (= the cheat) | 2.0 / 60 / ≈ 102.6 s; then frozen text ≈ 100 s |
| R3 | IMPL build without `--credits-fix` (`use-build <tag>`) | D1 at init | as R2, plus `fld+0x3D = 0, +0x41 = 1` from the first frame |
| R4 | IMPL build with `--credits-fix` | D1 | 1.0 / 60 / 12,314 updates ≈ 205 s; `[0x415E38] = 2`, `[0x415E3C] = 0` |

What to read (RPC reads work in the heap; `fld = u32[0x3F40B4]`, check `u32[fld] == 0x3E3B3C`):
`ctrl = u32[fld+0x1B3C]`; `ctrl+0x14` u32 frame (sample twice 10 s apart → updates/s), `+0x18` u8 ready (1),
`+0x1C` u32 count (416), `+0x24` f32 total (12312.0 = 0x46406000), `+0x28` f32 speed; `fld+0x1A4C` f32 field
step (2.0 at 30, 1.0 at 60); `fld+0x6E0` u16 (bit 0x40 must be set during the roll — H2 check); `fld+0x578`
frames/s; status bar `App: N FPS` and `Frame: N ms` (slowdown = App < 60 with logic slowing). Note the wall time
of the first frame increment and of `frame·speed > total`, and whether text and music end together.
Keep each run going **past the credits** to the next interactive point (rooms 0x1C6 `o_koopa_end_01` /
0x121 `o_areanone_end_02_L`, THE END, any save prompt), because the community report does not say where the
crash happens. On a crash or freeze: `rt_gdb.py regs` and `rt_gdb.py threads` (attach halts; record pc/lr/sp/
cpsr), copy the tail of `tools\azahar-test\user\log\azahar_log.txt`, note the on-screen step, map pc with
`armdis.py 3dx_v12 --where <pc>` (static) or via `rt_rpc.py cros` (CRO base) — and report which of R2/R3/R4.
Interpretation: crash in R2 only → cheat-state cause (H2); R2+R3 but not R4 → the roll timing is involved;
none on Azahar → H1 (hardware budget) remains and needs a real New 3DS run of R4 (lead).

## 8. Patch points (CRD scope), runtime checks, open questions

| ID | location | original | new | why | side effects |
|---|---|---|---|---|---|
| CRD-1 | 0x2E8B9C (file 0x1E8B9C) in op280 handler, sub-op 0 | `e320f000` nop | `bl cave_credits` (cave in D2's 0x388E00–0x388FFF range) | roll speed 1 px/update + 2-update fade at 60fps → 30fps wall clock, synced to `04_end_roll` | both rolls (story + Bowser Jr.'s Journey); no effect at 30fps (writes stock P0/P4) |
| CRD-2 (fallback only) | same cave + 0x2E8C28 | — | `+0x3D = 1` during the roll, `0` after delete | 30fps credits if a crash persists | credits at 30fps |

Open questions: (1) the real crash cause is not in the roll or the scripts (§4); RT2 runs R1–R4 and the lead
runs R4 on hardware; (2) whether the save load honours a stored entry index (irrelevant for variant A,
matters for B); (3) the screen order of the save room block (+2 upper, +4 lower) is inferred from the names
(`o_`/`_U` upper, `i_`/`_L` lower) — if the credits appear on swapped screens with A, swap the two ids.

Steering (lead, 14:2x): MoveVBase::stop non-return cut-off — none of the functions this report relies on
calls it; the op280 handler and the wait handler were read as assembly, StaffrollCtrl::init/update end in
their normal epilogues (`this[0x18] = 1`, `frame += 1`). D1X2's finding (credits = the only 1DX-vs-3DX gap,
fix after `bl 0x131798`) agrees with CRD-1; the fade-in is now included.
