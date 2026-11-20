# AUD — every reader of the fps mode in 3DX JP v1.2 (static + all CROs)

Worker AUD, wave 2, 2026-10-30. Report written incrementally.
Inputs: `work/fps60/dis/3dx_v12/*.s` (armdis listings), Ghidra dump `work/fps60/decomp/3dx_v12/*.c` +
`functions.tsv`, wave-1 reports (`engine.md`, `battle.md`, `modes.md`, `hugebattle.md`, `crash.md`,
`1dx_compare.md`, `runtime/findings.md`).
Tools (read-only, mine): `scripts/fps60/aud_sites.py` (`sites`, `cfuncs`, `inline`, `inlinec`, `fn`, `dis`),
`scripts/fps60/aud_table.py` (consumer of each isFps30 result, queried task, first-pass category).
Addresses: static = runtime address (file offset = addr − 0x100000); CRO = `Module+fileoffset [analysis address]`.
"ret" = return address of the `bl` (call site + 4), the value an adaptive `isFps30` would see in `lr`.
Confidence: **confirmed** = read in disassembly/decompile; **likely**; **guess**.

## 0. Result

- 122 calls of `ad::fw::TaskBase::isFps30` (0x25EDD0): 14 in static, 108 through the CRO import veneers
  (AttackMiniGame 1, BCat 1, Battle 2, Colosseum 11, KJMenu 38, LoadMenu 13, MainMenu 24, SaveMenu 1, ShopMenu 17;
  HugeBattle, KJRPG, Field, SaveLoad, KJGuide, MenuGuide 0). No pointer use of isFps30, no Thumb caller.
- Every used result is the select `isFps30() ? 2.0 : 1.0` (C84 selects ints 2/1 and converts): a step in 60 Hz units.
  **a = 87** per-frame steps (`Frm::update`, `MoveVBase/MoveC/MoveFBase/CellAnime/LytAnim::update`, float and
  integer countdowns with threshold tests, the field/battle/KJ/menu/event master steps, KJ step getters);
  **b = 28** latched steps (25 `MCursorBase::init` cursor-blink steps, field step `fld+0x1A4C` at field init and
  fast-forward on/off); **c = 0** (no frame skipping, no parity logic, no `== N` on a stepped counter);
  **d = 7** (5 results discarded in MainMenu, 1 always-true `step > 0` gate, 1 skip-to-end loop).
- Inline readers of the fps byte outside isFps30: only `TaskBase::init`/`funcInit`/`func` (4)/`isStoreCmdList`,
  `Boot::funcCalc` and HugeBattle's own `func`. **No CRO reads a task's +0x3D/+0x45.**
- One frame-counted wait sits inside a step-aware KJMenu helper (C36, FUN_1380F684): half as long at 60 (§5).
- **Adaptive isFps30 (v2) is not safe for every site**: safe for the 94 a/d sites, not for the 28 b sites. Exclude
  static ret 0x302C6C, 0x31ED40, 0x31EE60 by return address, handle the 25 cursor sites once at
  `MCursorBase::init` (store at 0x3244D8) instead of 25 CRO return addresses, and either exclude S8
  (ret 0x307078, then the field gets no catch-up) or re-base `fld+0x1A4C` where FUN_00307234 clears
  `fld+0x6E0` bit 0x40 (§6).
- D1's allow-list covers every task any site asks (§9).

## 1. Categories used in the tables

| cat | meaning | adaptive-isFps30 (v2) consequence |
|---|---|---|
| a | per-frame step: the 2.0/1.0 value is consumed in the same frame (timer/animation/move update, countdown, master step) and recomputed next frame | follows the per-frame value: a 2.0 frame after an overrun = catch-up, correct |
| b | latched: the value is stored once (object creation, init, state change) and reused on later frames | wrong if the latch happens on an overrun frame (2.0 kept while the task runs at 60) → that object runs 2× fast until re-created |
| c | frame skipping / every-other-frame logic | (none found) |
| d | other: result unused, code-path select | no effect |

## 2. Static code: the 14 direct calls (all confirmed; matches `engine.md` §7)

| # | site (file off) | ret | function | task asked | result feeds | cat |
|---|---|---|---|---|---|---|
| S1 | 0x16D998 (0x6D998) | 0x16D99C | FUN_0016D984 (kj UI object update, called from `KJSystem::funcCalc` right after S3) | KJSystem `[0x3F61C0]` | `CellAnime::update(step)`, `MoveFBase::update(step)` | a |
| S2 | 0x195E90 (0x95E90) | 0x195E94 | `kj::KJSystem::funcCalc` (vfunc_0x18) 0x195D94 | KJSystem (this) | s17 = step → KJ master step `+0x61C58 = step × [[t+0x574]+0x7C] × [+0xC8D90]` (0x1960E8), `MoveC::update` ×2 | a |
| S3 | 0x196260 (0x96260) | 0x196264 | same funcCalc | KJSystem `[0x3F61C0]` | `MoveC::update(step)` of KJ object +0xC89F8 | a |
| S4 | 0x1EBD7C (0xEBD7C) | 0x1EBD80 | `btl::ChrCmdPcDefHammer::ObjDispHam` vfunc_0xc 0x1EBCD8 (hammer-defence display object update) | btl::Main `[0x3F35F8+8]` | only `if (step <= 0) return;` (0x1EBD90 `vcmpe s0,#0; ble`), the value is not used afterwards (s0 is dead after 0x1EBD98) | d |
| S5 | 0x23C7A0 (0x13C7A0) | 0x23C7A4 | `btl::ObjBase::calcUpdateSpd` 0x23C784 | btl::Main `[0x3F35F8+8]` | returns `step × obj+0x20` (objects with flag +0x24 bit 1) | a |
| S6 | 0x28B6A0 (0x18B6A0) | 0x28B6A4 | `btl::Main::funcCalc` (vfunc_0x18) 0x28B67C | btl::Main (this) | battle master step × dfx speed × +0x8A3C → `+0x8A44 += step; modff` (integer ticks for AI waits), `+0xBA15C`, `+0x8A40` | a |
| S7 | 0x302C68 (0x202C68) | 0x302C6C | field init FUN_00302A64 | fld::System (this) | `fld+0x1A4C = step × game speed × ffwd` (stored) | **b** |
| S8 | 0x307074 (0x207074) | 0x307078 | `fld::System::funcCalc` (vfunc_0x18) 0x306BC4, only when `[fld+0x6E0] & 0x40` | fld::System (this) | `fld+0x1A50 = old; fld+0x1A4C = step × …` (stored, recomputed every frame while the bit is set) | a (b while bit clear) |
| S9 | 0x31ED3C (0x21ED3C) | 0x31ED40 | fast-forward controller FUN_0031EC90 (ffwd on) | fld::System | `fld+0x1A4C = step × speed × [0x412C80]` (stored once) | **b** |
| S10 | 0x31EE5C (0x21EE5C) | 0x31EE60 | same (ffwd off) | fld::System | `fld+0x1A4C = step × speed × 1.0` (stored once) | **b** |
| S11 | 0x32F41C (0x22F41C) | 0x32F420 | `msys::MComSys::funcCalc` 0x32F40C | menu task (`MComSys+4`) | menu update step → FUN_0032EEF8 (all menu objects, `MessageSys::func`) | a |
| S12 | 0x32F448 (0x22F448) | 0x32F44C | same | menu task | event step `MComSys+0xE6530` (= `+0xE651C+0x14`, GlobalEvent wait decrement) | a |
| S13 | 0x345278 (0x245278) | 0x34527C | `kj::ObjFontLose` vfunc_0x18 0x34525C (getter, flag +0x468) | KJSystem `[0x3F61C0]` | returns step (else the KJ master step +0x61C58) | a |
| S14 | 0x3467EC (0x2467EC) | 0x3467F0 | `kj::ObjFade` vfunc_0x18 0x3467D0 (getter, flag +0x2DC) | KJSystem `[0x3F61C0]` | same pattern | a |

Field step latch (S7–S10), confirmed: `fld+0x1A4C` is the step every field updater reads (24 direct readers,
`modes.md` §2.1). It is written only at these four sites. S8 rewrites it every frame **only while
`[fld+0x6E0] & 0x40`** is set (set when the field state machine reaches state 8 at 0x30B2F0, cleared in
fn 0x307234 at 0x3072A8, `engine.md` §5); otherwise the value written by S7 (field init), S9 or S10
(fast-forward toggle) stays in force.


## 3. CRO calls through the isFps30 veneers (108 sites)

Every CRO module imports isFps30 once (veneer `ldr pc,[pc,#-4]; .word 0x25EDD0` at AttackMiniGame 0x10000450,
BCat 0x10800208, Battle 0x1100092C, Colosseum 0x118003E8, KJMenu 0x13800360, LoadMenu 0x14800438, MainMenu
0x15000358, SaveMenu 0x16800340, ShopMenu 0x170002C0). The task asked is always the current task of the mode:
menus `MComSys::_sys→+4` (directly or via the page's cached `+8` MComSys pointer), Battle `btl::GetMain()`.
Column "function +off" = containing function (Ghidra name, or the nearest preceding `push {…lr}` when Ghidra did
not create a function) and the call's offset in it. Row ids `C<n>` follow `aud_table.py` numbering.

Menu framework facts used below (all confirmed in the dump):
- `Frm::update(float step)` (static 0x26AED4): `cur += spd × step`, wraps/ends with `<= 0` tests, returns
  "still running"; the callers are page **state functions** (member-function pointers stored at page+0x20/+0x24
  or +0x12A04/+0x12A08 and called once per frame) → category a.
- `msys::MCursorBase::init(MLyt*, float step)` (static 0x324464) stores the step at **cursor+0x2C** and nothing
  else reads it at init. Each menu CRO has a copy of the cursor update that does every frame
  `c = (short)(cursor+0x1A − cursor+0x2C); if (c < 0) c = 30; else if (c < 15) offset +2 px` (e.g. BCat.c
  line ~2045; MainMenu, ShopMenu, KJMenu, LoadMenu, SaveMenu, Colosseum, AttackMiniGame have the same line):
  a 30-unit (0.5 s) blink cycle whose step is **latched at page creation** → category b. 37 calls of
  `MCursorBase::init` exist: 21 directly after an isFps30 call, 16 through tiny wrappers
  (`push {r4,lr}; mov r4,r0; bl MCursorBase::init; clear +0x30.. ; pop`) that sit in vtables at slot +8; only 4 of
  those wrappers are called (C15, C19, C68, C105, `ldr r2,[vptr,#8]; blx r2` with s0 = isFps30 step); no other
  `blx [vptr+8]` passes a float in s0 in any menu CRO (scan in §7), so every executed cursor init gets an
  isFps30 step.

| id | site | ret | function +off | result feeds | when | cat |
|---|---|---|---|---|---|---|
| C15 | AttackMiniGame+0x2198 [0x10002198] | 0x1000219c | (no Ghidra fn, starts ~0x10001df8) 0x3a0 | virtual `obj->vt[+8](lyt, step)` = wrapper AttackMiniGame+0x7AE8 [0x10007AE8] → `MCursorBase::init` (cursor step latched at page init) | page/task init (fn ~0x10001DF8) | b |
| C16 | BCat+0x8b4 [0x108008b4] | 0x108008b8 | FUN_10800828 0x8c | `MCursorBase::init(lyt, step)` → cursor+0x2C (blink countdown step, read every frame by the CRO cursor update `(short)(+0x1A − +0x2C)`) | BCat page init FUN_10800828 | b |
| C17 | Battle+0x10524 [0x11010524] | 0x11010528 | btl::ChrCmdPcCmdSelect::vfunc_0x8 0x2394 | s0 = step → `if (!(btn & 0x30) && +0x40 > 0) +0x40 -= step` (0x1101070C `vsubgt`, 0x11010710 `vstrgt`): float hold/repeat timer | command-select update (per frame) | a |
| C18 | Battle+0x5c560 [0x1105c560] | 0x1105c564 | btl::ObjCursor::vfunc_0xc 0x21c | `if (+0xA64 > 0) +0xA64 -= step` (0x1105C5A0): float cursor timer | battle cursor update (per frame) | a |
| C19 | Colosseum+0x34f4 [0x118034f4] | 0x118034f8 | (no Ghidra fn, starts ~0x11802e24) 0x6d0 | virtual `obj->vt[+8](lyt, step)` = wrapper Colosseum+0xBB48 [0x1180BB48] → `MCursorBase::init` (cursor step latched at page init) | page init (fn ~0x11802E24) | b |
| C20 | Colosseum+0x5020 [0x11805020] | 0x11805024 | FUN_11804fdc 0x44 | `Frm::update(step)` in a page state function (per-frame float frame timer, `<= 0` tests) | page state fn | a |
| C21 | Colosseum+0x7178 [0x11807178] | 0x1180717c | FUN_11807118 0x60 | `Frm::update(step)` in a page state function (per-frame float frame timer, `<= 0` tests) | page state fn | a |
| C22 | Colosseum+0x7408 [0x11807408] | 0x1180740c | FUN_11807390 0x78 | `Frm::update(step)` in a page state function (per-frame float frame timer, `<= 0` tests) | page state fn | a |
| C23 | Colosseum+0x7814 [0x11807814] | 0x11807818 | FUN_118077c0 0x54 | `Frm::update(step)` in a page state function (per-frame float frame timer, `<= 0` tests) | page state fn | a |
| C24 | Colosseum+0x7c60 [0x11807c60] | 0x11807c64 | FUN_11807bcc 0x94 | `Frm::update(step)` in a page state function (per-frame float frame timer, `<= 0` tests) | page state fn | a |
| C25 | Colosseum+0x7dd8 [0x11807dd8] | 0x11807ddc | FUN_11807d88 0x50 | `Frm::update(step)` in a page state function (per-frame float frame timer, `<= 0` tests) | page state fn | a |
| C26 | Colosseum+0x7f00 [0x11807f00] | 0x11807f04 | FUN_11807edc 0x24 | `Frm::update(step)` in a page state function (per-frame float frame timer, `<= 0` tests) | page state fn | a |
| C27 | Colosseum+0x8044 [0x11808044] | 0x11808048 | FUN_11808010 0x34 | `Frm::update(step)` in a page state function (per-frame float frame timer, `<= 0` tests) | page state fn | a |
| C28 | Colosseum+0x8338 [0x11808338] | 0x1180833c | FUN_118082f0 0x48 | `Frm::update(step)` in a page state function (per-frame float frame timer, `<= 0` tests) | page state fn | a |
| C29 | Colosseum+0x83ec [0x118083ec] | 0x118083f0 | FUN_118083b8 0x34 | `Frm::update(step)` in a page state function (per-frame float frame timer, `<= 0` tests) | page state fn | a |
| C30 | KJMenu+0x2eb0 [0x13802eb0] | 0x13802eb4 | (no Ghidra fn, starts ~0x13802db4) 0xfc | `MCursorBase::init(lyt, step)` → cursor+0x2C (blink countdown step, read every frame by the CRO cursor update `(short)(+0x1A − +0x2C)`) | page/window init | b |
| C31 | KJMenu+0x3700 [0x13803700] | 0x13803704 | (no Ghidra fn, starts ~0x13802db4) 0x94c | `MCursorBase::init(lyt, step)` → cursor+0x2C (blink countdown step, read every frame by the CRO cursor update `(short)(+0x1A − +0x2C)`) | page/window init | b |
| C32 | KJMenu+0x5aac [0x13805aac] | 0x13805ab0 | FUN_13805a5c 0x50 | `Frm::update(step)` in a page state function (per-frame float frame timer, `<= 0` tests) | page state fn | a |
| C33 | KJMenu+0xdb48 [0x1380db48] | 0x1380db4c | (no Ghidra fn, starts ~0x1380dae4) 0x64 | `MCursorBase::init(lyt, step)` → cursor+0x2C (blink countdown step, read every frame by the CRO cursor update `(short)(+0x1A − +0x2C)`) | page/window init | b |
| C34 | KJMenu+0x10b40 [0x13810b40] | 0x13810b44 | (no Ghidra fn, starts ~0x13810a00) 0x140 | `MCursorBase::init(lyt, step)` → cursor+0x2C (blink countdown step, read every frame by the CRO cursor update `(short)(+0x1A − +0x2C)`) | page/window init | b |
| C35 | KJMenu+0x11844 [0x13811844] | 0x13811848 | FUN_13811820 0x24 | FUN_1382174C(step): `MoveVBase::update(step)` ×3, then an index counter that advances when the moves finish (event count) | page state fn | a |
| C36 | KJMenu+0x12b98 [0x13812b98] | 0x13812b9c | FUN_13812b74 0x24 | FUN_1380F684(step): `MoveVBase::update(step)` ×3; **its state-1 wait `+0x7A32` is decremented by 1 per call (frame-counted, not step-scaled)** — see §4 | page state fn | a |
| C37 | KJMenu+0x15e88 [0x13815e88] | 0x13815e8c | FUN_13815e64 0x24 | `Frm::update(step)` in a page state function (per-frame float frame timer, `<= 0` tests) | page state fn | a |
| C38 | KJMenu+0x1697c [0x1381697c] | 0x13816980 | FUN_13816958 0x24 | FUN_1380F200(step): `MoveVBase::update(step)` ×3 + sequence index +0x1E8D (advances on move completion) | page state fn | a |
| C39 | KJMenu+0x16bf4 [0x13816bf4] | 0x13816bf8 | FUN_13816bd0 0x24 | FUN_1381FA10(step, list): per-frame list update (contains #49/#50) | page state fn | a |
| C40 | KJMenu+0x16e60 [0x13816e60] | 0x13816e64 | FUN_13816e18 0x48 | int countdown `+0x692EC = (int)(+0x692EC − step)`; tested `< 1` in FUN_13817E90 | page state fn | a |
| C41 | KJMenu+0x170d8 [0x138170d8] | 0x138170dc | FUN_13817098 0x40 | FUN_13815180(step): `MoveVBase::update(step)` per list element | page state fn | a |
| C42 | KJMenu+0x1751c [0x1381751c] | 0x13817520 | FUN_138174f0 0x2c | FUN_1381FA10(step) | page state fn | a |
| C43 | KJMenu+0x17908 [0x13817908] | 0x1381790c | FUN_138178dc 0x2c | `MoveVBase::update(step)` ×3 | page state fn | a |
| C44 | KJMenu+0x17bb4 [0x13817bb4] | 0x13817bb8 | FUN_13817b90 0x24 | FUN_1380F200(step) (see #38) | page state fn | a |
| C45 | KJMenu+0x17d30 [0x13817d30] | 0x13817d34 | FUN_13817c30 0x100 | `do { r = FUN_1381FA10(step) } while (r == 0)` in one frame (skip-to-end loop); the step only changes the iteration count | page state fn (one-shot) | d |
| C46 | KJMenu+0x17ee8 [0x13817ee8] | 0x13817eec | FUN_13817e90 0x58 | int countdown `+0x692EC −= step`, tested `< 1` at the function start | page state fn | a |
| C47 | KJMenu+0x1977c [0x1381977c] | 0x13819780 | (no Ghidra fn, starts ~0x13819718) 0x64 | `MCursorBase::init(lyt, step)` → cursor+0x2C (blink countdown step, read every frame by the CRO cursor update `(short)(+0x1A − +0x2C)`) | page/window init | b |
| C48 | KJMenu+0x1a97c [0x1381a97c] | 0x1381a980 | (no Ghidra fn, starts ~0x1381a898) 0xe4 | `MCursorBase::init(lyt, step)` → cursor+0x2C (blink countdown step, read every frame by the CRO cursor update `(short)(+0x1A − +0x2C)`) | page/window init | b |
| C49 | KJMenu+0x1fcfc [0x1381fcfc] | 0x1381fd00 | FUN_1381fa10 0x2ec | char countdown `+0x1390 = (s8)(+0x1390 − step)`, loop while `> 0` (0x1381FD34 `bgt`) | list update FUN_1381FA10 | a |
| C50 | KJMenu+0x1ffa4 [0x1381ffa4] | 0x1381ffa8 | (no Ghidra fn, starts ~0x1381fa10) 0x594 | same countdown (second path, 0x1381FFDC `bgt`) | list update FUN_1381FA10 | a |
| C51 | KJMenu+0x31394 [0x13831394] | 0x13831398 | FUN_13831370 0x24 | FUN_13826590(step): `MoveVBase::update`/`MoveFBase::update(step)` | page state fn | a |
| C52 | KJMenu+0x32ae0 [0x13832ae0] | 0x13832ae4 | FUN_13832abc 0x24 | `Frm::update(step)` in a page state function (per-frame float frame timer, `<= 0` tests) | page state fn | a |
| C53 | KJMenu+0x32d60 [0x13832d60] | 0x13832d64 | FUN_13832d3c 0x24 | `Frm::update(step)` in a page state function (per-frame float frame timer, `<= 0` tests) | page state fn | a |
| C54 | KJMenu+0x32e7c [0x13832e7c] | 0x13832e80 | FUN_13832e58 0x24 | `Frm::update(step)` in a page state function (per-frame float frame timer, `<= 0` tests) | page state fn | a |
| C55 | KJMenu+0x32f54 [0x13832f54] | 0x13832f58 | FUN_13832f30 0x24 | `Frm::update(step)` in a page state function (per-frame float frame timer, `<= 0` tests) | page state fn | a |
| C56 | KJMenu+0x3302c [0x1383302c] | 0x13833030 | FUN_13833008 0x24 | `Frm::update(step)` in a page state function (per-frame float frame timer, `<= 0` tests) | page state fn | a |
| C57 | KJMenu+0x33148 [0x13833148] | 0x1383314c | FUN_13833104 0x44 | `Frm::update(step)` in a page state function (per-frame float frame timer, `<= 0` tests) | page state fn | a |
| C58 | KJMenu+0x331d4 [0x138331d4] | 0x138331d8 | FUN_138331b0 0x24 | `Frm::update(step)` in a page state function (per-frame float frame timer, `<= 0` tests) | page state fn | a |
| C59 | KJMenu+0x33280 [0x13833280] | 0x13833284 | FUN_1383325c 0x24 | `Frm::update(step)` in a page state function (per-frame float frame timer, `<= 0` tests) | page state fn | a |
| C60 | KJMenu+0x3330c [0x1383330c] | 0x13833310 | FUN_138332e8 0x24 | `Frm::update(step)` in a page state function (per-frame float frame timer, `<= 0` tests) | page state fn | a |
| C61 | KJMenu+0x33398 [0x13833398] | 0x1383339c | FUN_13833374 0x24 | `Frm::update(step)` in a page state function (per-frame float frame timer, `<= 0` tests) | page state fn | a |
| C62 | KJMenu+0x33938 [0x13833938] | 0x1383393c | FUN_13833914 0x24 | `Frm::update(step)` in a page state function (per-frame float frame timer, `<= 0` tests) | page state fn | a |
| C63 | KJMenu+0x356e8 [0x138356e8] | 0x138356ec | FUN_138355c0 0x128 | `MCursorBase::init(lyt, step)` → cursor+0x2C (blink countdown step, read every frame by the CRO cursor update `(short)(+0x1A − +0x2C)`) | page/window init | b |
| C64 | KJMenu+0x367fc [0x138367fc] | 0x13836800 | FUN_1383668c 0x170 | `MCursorBase::init(lyt, step)` → cursor+0x2C (blink countdown step, read every frame by the CRO cursor update `(short)(+0x1A − +0x2C)`) | page/window init | b |
| C65 | KJMenu+0x38dd0 [0x13838dd0] | 0x13838dd4 | FUN_13838cc4 0x10c | `MCursorBase::init(lyt, step)` → cursor+0x2C (blink countdown step, read every frame by the CRO cursor update `(short)(+0x1A − +0x2C)`) | page/window init | b |
| C66 | KJMenu+0x39f3c [0x13839f3c] | 0x13839f40 | FUN_13839e58 0xe4 | `MCursorBase::init(lyt, step)` → cursor+0x2C (blink countdown step, read every frame by the CRO cursor update `(short)(+0x1A − +0x2C)`) | page/window init | b |
| C67 | KJMenu+0x43f10 [0x13843f10] | 0x13843f14 | FUN_13843e50 0xc0 | `ad::lyt::LytAnim::update(step)` ×29 (KJMenu MComSys calc variant, then `funcCalcMainNomal`) | per frame | a |
| C68 | LoadMenu+0x3220 [0x14803220] | 0x14803224 | (no Ghidra fn, starts ~0x14802f6c) 0x2b4 | virtual `obj->vt[+8](lyt, step)` = wrapper LoadMenu+0xDAF8 [0x1480DAF8] → `MCursorBase::init` (cursor step latched at page init) | page init (fn ~0x14802F6C) | b |
| C69 | LoadMenu+0x5b0c [0x14805b0c] | 0x14805b10 | FUN_14805ae0 0x2c | `Frm::update(step)` in a page state function (per-frame float frame timer, `<= 0` tests) | page state fn | a |
| C70 | LoadMenu+0x71f4 [0x148071f4] | 0x148071f8 | FUN_14806ac8 0x72c | `Frm::update(step)` in a page state function (per-frame float frame timer, `<= 0` tests) | page state fn | a |
| C71 | LoadMenu+0x727c [0x1480727c] | 0x14807280 | FUN_14806ac8 0x7b4 | `Frm::update(step)` in a page state function (per-frame float frame timer, `<= 0` tests) | page state fn | a |
| C72 | LoadMenu+0x73ac [0x148073ac] | 0x148073b0 | FUN_14806ac8 0x8e4 | `Frm::update(step)` in a page state function (per-frame float frame timer, `<= 0` tests) | page state fn | a |
| C73 | LoadMenu+0x7568 [0x14807568] | 0x1480756c | FUN_14806ac8 0xaa0 | `Frm::update(step)` in a page state function (per-frame float frame timer, `<= 0` tests) | page state fn | a |
| C74 | LoadMenu+0x7724 [0x14807724] | 0x14807728 | FUN_14806ac8 0xc5c | `Frm::update(step)` in a page state function (per-frame float frame timer, `<= 0` tests) | page state fn | a |
| C75 | LoadMenu+0x7790 [0x14807790] | 0x14807794 | FUN_14806ac8 0xcc8 | `Frm::update(step)` in a page state function (per-frame float frame timer, `<= 0` tests) | page state fn | a |
| C76 | LoadMenu+0x7818 [0x14807818] | 0x1480781c | FUN_14806ac8 0xd50 | `Frm::update(step)` in a page state function (per-frame float frame timer, `<= 0` tests) | page state fn | a |
| C77 | LoadMenu+0x7e00 [0x14807e00] | 0x14807e04 | FUN_14806ac8 0x1338 | `Frm::update(step)` in a page state function (per-frame float frame timer, `<= 0` tests) | page state fn | a |
| C78 | LoadMenu+0x7f70 [0x14807f70] | 0x14807f74 | FUN_14806ac8 0x14a8 | `Frm::update(step)` in a page state function (per-frame float frame timer, `<= 0` tests) | page state fn | a |
| C79 | LoadMenu+0x7fe0 [0x14807fe0] | 0x14807fe4 | FUN_14806ac8 0x1518 | `Frm::update(step)` in a page state function (per-frame float frame timer, `<= 0` tests) | page state fn | a |
| C80 | LoadMenu+0xabcc [0x1480abcc] | 0x1480abd0 | FUN_1480ab9c 0x30 | `Frm::update(step)` in a page state function (per-frame float frame timer, `<= 0` tests) | page state fn | a |
| C81 | MainMenu+0x2400 [0x15002400] | 0x15002404 | (no Ghidra fn, starts ~0x150022e0) 0x120 | `MCursorBase::init(lyt, step)` → cursor+0x2C (blink countdown step, read every frame by the CRO cursor update `(short)(+0x1A − +0x2C)`) | page/window init | b |
| C82 | MainMenu+0x4f2c [0x15004f2c] | 0x15004f30 | (no Ghidra fn, starts ~0x15004e1c) 0x110 | `MCursorBase::init(lyt, step)` → cursor+0x2C (blink countdown step, read every frame by the CRO cursor update `(short)(+0x1A − +0x2C)`) | page/window init | b |
| C83 | MainMenu+0x635c [0x1500635c] | 0x15006360 | FUN_150062cc 0x90 | `MoveVBase::update(step)` (cursor/marker move) | page state fn | a |
| C84 | MainMenu+0x65ac [0x150065ac] | 0x150065b0 | FUN_15006534 0x78 | **int select** `isFps30 ? 2 : 1` → `vcvt.f32.u32` → `Frm::update` | page state fn | a |
| C85 | MainMenu+0x6e80 [0x15006e80] | 0x15006e84 | FUN_15006d44 0x13c | `MoveVBase::update(step)` | page update FUN_15006D44 | a |
| C86 | MainMenu+0x7494 [0x15007494] | 0x15007498 | FUN_15006d44 0x750 | result unused (r0 reloaded at 0x15007498 `ldr r0,=0x802`) | same fn | d |
| C87 | MainMenu+0x8c58 [0x15008c58] | 0x15008c5c | FUN_15008c24 0x34 | `Frm::update(step)` in a page state function (per-frame float frame timer, `<= 0` tests) | page state fn | a |
| C88 | MainMenu+0x8d60 [0x15008d60] | 0x15008d64 | FUN_15008d2c 0x34 | `Frm::update(step)` in a page state function (per-frame float frame timer, `<= 0` tests) | page state fn | a |
| C89 | MainMenu+0x9d88 [0x15009d88] | 0x15009d8c | (no Ghidra fn, starts ~0x150097bc) 0x5cc | `MCursorBase::init(lyt, step)` → cursor+0x2C (blink countdown step, read every frame by the CRO cursor update `(short)(+0x1A − +0x2C)`) | page/window init | b |
| C90 | MainMenu+0xe728 [0x1500e728] | 0x1500e72c | FUN_1500e6b0 0x78 | `MCursorBase::init(lyt, step)` → cursor+0x2C (blink countdown step, read every frame by the CRO cursor update `(short)(+0x1A − +0x2C)`) | page/window init | b |
| C91 | MainMenu+0xea20 [0x1500ea20] | 0x1500ea24 | FUN_1500e6b0 0x370 | `MCursorBase::init(lyt, step)` → cursor+0x2C (blink countdown step, read every frame by the CRO cursor update `(short)(+0x1A − +0x2C)`) | page/window init | b |
| C92 | MainMenu+0x105fc [0x150105fc] | 0x15010600 | (no Ghidra fn, starts ~0x150100d0) 0x52c | `MCursorBase::init(lyt, step)` → cursor+0x2C (blink countdown step, read every frame by the CRO cursor update `(short)(+0x1A − +0x2C)`) | page/window init | b |
| C93 | MainMenu+0x1485c [0x1501485c] | 0x15014860 | FUN_150147a8 0xb4 | `Frm::update(step)` in a page state function (per-frame float frame timer, `<= 0` tests) | page state fn | a |
| C94 | MainMenu+0x14bbc [0x15014bbc] | 0x15014bc0 | FUN_15014940 0x27c | `ad::lyt::LytAnim::update(step)` | per frame | a |
| C95 | MainMenu+0x14bf4 [0x15014bf4] | 0x15014bf8 | FUN_15014940 0x2b4 | `ad::lyt::LytAnim::update(step)` | per frame | a |
| C96 | MainMenu+0x14c34 [0x15014c34] | 0x15014c38 | FUN_15014940 0x2f4 | `ad::lyt::LytAnim::update(step)` (inner loop ×6) | per frame | a |
| C97 | MainMenu+0x18438 [0x15018438] | 0x1501843c | (no Ghidra fn, starts ~0x15017bac) 0x88c | `MCursorBase::init(lyt, step)` → cursor+0x2C (blink countdown step, read every frame by the CRO cursor update `(short)(+0x1A − +0x2C)`) | page/window init | b |
| C98 | MainMenu+0x19d30 [0x15019d30] | 0x15019d34 | FUN_15019ce0 0x50 | result unused (r0 reloaded at 0x15019D34) | page input fn | d |
| C99 | MainMenu+0x1cd30 [0x1501cd30] | 0x1501cd34 | FUN_1501ccd8 0x58 | result unused (r0 reloaded at 0x1501CD34) | page input fn | d |
| C100 | MainMenu+0x1d598 [0x1501d598] | 0x1501d59c | FUN_1501d53c 0x5c | result unused (r0 reloaded at 0x1501D59C) | page input fn | d |
| C101 | MainMenu+0x1d974 [0x1501d974] | 0x1501d978 | FUN_1501d920 0x54 | result unused (r0 reloaded at 0x1501D978) | page input fn | d |
| C102 | MainMenu+0x213bc [0x150213bc] | 0x150213c0 | FUN_15021310 0xac | `MCursorBase::init(lyt, step)` → cursor+0x2C (blink countdown step, read every frame by the CRO cursor update `(short)(+0x1A − +0x2C)`) | page/window init | b |
| C103 | MainMenu+0x21e88 [0x15021e88] | 0x15021e8c | FUN_15021dac 0xdc | `ad::lyt::LytAnim::update(step)` (MainMenu MComSys calc variant FUN_15021DAC) | per frame | a |
| C104 | MainMenu+0x21eb4 [0x15021eb4] | 0x15021eb8 | FUN_15021dac 0x108 | `ad::lyt::LytAnim::update(step)` | per frame | a |
| C105 | SaveMenu+0x1510 [0x16801510] | 0x16801514 | (no Ghidra fn, starts ~0x16801220) 0x2f0 | virtual `obj->vt[+8](lyt, step)` = wrapper SaveMenu+0x432C [0x1680432C] → `MCursorBase::init` (cursor step latched at page init) | page init (fn ~0x16801220) | b |
| C106 | ShopMenu+0x2308 [0x17002308] | 0x1700230c | FUN_17002228 0xe0 | short countdown `+0x72E2 = (s16)(+0x72E2 − step)`, reset when `< 0` (blink cycle) | per frame | a |
| C107 | ShopMenu+0x520c [0x1700520c] | 0x17005210 | FUN_170051c8 0x44 | `Frm::update(step)` in a page state function (per-frame float frame timer, `<= 0` tests) | page state fn | a |
| C108 | ShopMenu+0x5770 [0x17005770] | 0x17005774 | FUN_1700572c 0x44 | `Frm::update(step)` in a page state function (per-frame float frame timer, `<= 0` tests) | page state fn | a |
| C109 | ShopMenu+0x58fc [0x170058fc] | 0x17005900 | FUN_170058bc 0x40 | `Frm::update(step)` in a page state function (per-frame float frame timer, `<= 0` tests) | page state fn | a |
| C110 | ShopMenu+0x5a08 [0x17005a08] | 0x17005a0c | FUN_170059ac 0x5c | `Frm::update(step)` in a page state function (per-frame float frame timer, `<= 0` tests) | page state fn | a |
| C111 | ShopMenu+0x6170 [0x17006170] | 0x17006174 | FUN_17006130 0x40 | `Frm::update(step)` in a page state function (per-frame float frame timer, `<= 0` tests) | page state fn | a |
| C112 | ShopMenu+0x627c [0x1700627c] | 0x17006280 | FUN_17006220 0x5c | `Frm::update(step)` in a page state function (per-frame float frame timer, `<= 0` tests) | page state fn | a |
| C113 | ShopMenu+0x6450 [0x17006450] | 0x17006454 | FUN_1700641c 0x34 | `Frm::update(step)` in a page state function (per-frame float frame timer, `<= 0` tests) | page state fn | a |
| C114 | ShopMenu+0x66f4 [0x170066f4] | 0x170066f8 | FUN_170066a8 0x4c | `Frm::update(step)` in a page state function (per-frame float frame timer, `<= 0` tests) | page state fn | a |
| C115 | ShopMenu+0x67b4 [0x170067b4] | 0x170067b8 | FUN_17006784 0x30 | `Frm::update(step)` in a page state function (per-frame float frame timer, `<= 0` tests) | page state fn | a |
| C116 | ShopMenu+0x6880 [0x17006880] | 0x17006884 | FUN_17006848 0x38 | `Frm::update(step)` in a page state function (per-frame float frame timer, `<= 0` tests) | page state fn | a |
| C117 | ShopMenu+0x6990 [0x17006990] | 0x17006994 | FUN_1700696c 0x24 | `Frm::update(step)` in a page state function (per-frame float frame timer, `<= 0` tests) | page state fn | a |
| C118 | ShopMenu+0x6be4 [0x17006be4] | 0x17006be8 | FUN_17006bb0 0x34 | `Frm::update(step)` in a page state function (per-frame float frame timer, `<= 0` tests) | page state fn | a |
| C119 | ShopMenu+0x7258 [0x17007258] | 0x1700725c | FUN_17007210 0x48 | `Frm::update(step)` in a page state function (per-frame float frame timer, `<= 0` tests) | page state fn | a |
| C120 | ShopMenu+0x1284c [0x1701284c] | 0x17012850 | FUN_1701276c 0xe0 | same countdown as #106 (second copy) | per frame | a |
| C121 | ShopMenu+0x135ec [0x170135ec] | 0x170135f0 | FUN_17012c3c 0x9b0 | `MCursorBase::init(lyt, step)` → cursor+0x2C (blink countdown step, read every frame by the CRO cursor update `(short)(+0x1A − +0x2C)`) | page/window init | b |
| C122 | ShopMenu+0x13638 [0x17013638] | 0x1701363c | FUN_17012c3c 0x9fc | `MCursorBase::init(lyt, step)` → cursor+0x2C (blink countdown step, read every frame by the CRO cursor update `(short)(+0x1A − +0x2C)`) | page/window init | b |

Per-module totals (CRO): AttackMiniGame 1 = b1; BCat 1 = b1; Battle 2 = a2; Colosseum 11 = a10 b1; KJMenu 38 =
a27 b10 d1; LoadMenu 13 = a12 b1; MainMenu 24 = a11 b8 d5; SaveMenu 1 = b1; ShopMenu 17 = a15 b2.
**All 122 sites: a 87, b 28, c 0, d 7** (static a10 b3 d1, CRO a77 b25 d6).

## 4. Readers of TaskBase+0x45 / +0x3D that do not go through isFps30

Scan (`aud_sites.py inline` / `inlinec`): every `ldrb`/`ldrsb rX,[rY,#0x45]` and `#0x3d` in static and all 15 CROs,
198 loads in 97 functions; each base register checked in the dump or the listing. Word/halfword reads of
+0x3C/+0x44 inside the TaskBase methods were checked separately (none reads the fps byte as part of a word).
Only these read a task's fps byte (all confirmed):

| location | function | reads | use | affected by an adaptive isFps30? |
|---|---|---|---|---|
| 0x28092C | `ad::fw::TaskBase::init` | +0x3D → +0x45 | initial copy (D1 hook point) | no |
| 0x13E8E4 | `ad::fw::TaskBase::funcInit` (every frame) | +0x3D → +0x45; `+0x3D == 2` → toggle +0x48 | per-frame copy | no |
| 0x13DC54 | `ad::fw::TaskBase::func` | +0x45 ∈ {2,3} (with +0x44) | async (pipelined) GPU path select | no |
| 0x13DF48 | same | `+0x45 == 2 && +0x47` | draw-on-alternate-frames predicate (mode 2) | no |
| 0x13E344 | same | `+0x45 == 3` | CmdList +0x7D (event-driven swap) | no |
| 0x13E494 | same | `+0x45 == 1` | **the 30fps extra vsync wait** | no (must stay so) |
| 0x342810 | `ad::fw::TaskBase::isStoreCmdList` (only caller: HugeBattle veneer 0x128001F8) | `+0x45 == 2 && +0x47 && !+0x48` | draw predicate | no |
| 0x322700 | `Boot::funcCalc` (vfunc_0x18) 0x3226D8 | `+0x45 == 1 ? 2.0 : 1.0` | `MessageSys::func` step (Boot runs at mode 0 → 1.0) | no (inline copy of isFps30, category a) |
| HugeBattle+0x1E50 [0x12801E50] | `hb::HugeBattleSystem::func` | `+0x45 == 3` | CmdList +0x7D | no |
| 0x25EDD0 | `ad::fw::TaskBase::isFps30` | `+0x45 == 1` | — | (the function itself) |

Everything else is another structure: `nw::lyt`/`ad::lyt` Pane/DrawVisitor/Drawer/Layout and
`msys::MLytRenderQueue` pane flag +0x45 / build byte +0x3D (32 loads),
`kj::Lyt`/`kj::LytListWindow` +0x45, RGBA bytes +0x42..+0x45 (0x150E68, 0x150FF0, 0x151D04, 0x153EBC), GPU
command-list objects +0x3D (0x112B54, 0x112CB0, 0x27F8E0), field/message objects (0x202C68 = +0xD45,
0x20F174, 0x2114D4, 0x211570, `MsgWndPosCalculator::calc`, 0x2B144C, 0x2B185C), save/data structs (`DataPc::getRank`,
0x360BD8, 0x36197C, 0x36BAD4, 0x1C6BD4), stack temporaries (`[sp,#0x3d/0x45]`), Battle `btl::TaskBtlResultPcWin` vfunc_0x8
+0x3D (PC index byte, used as an array index) and FUN_11034440, KJRPG `kj::GetSys()+0xC7BD4+0x3D` (0x1400BE64, 0x1400BFE0, 0x14016464)
and kj command objects, HugeBattle game objects (`CRoboFormation`, `CPeach`, `CKikanbohFlowLane`, … state bytes).
**No CRO reads +0x3D/+0x45 of a task** (HugeBattle's own loop excepted). No code outside `init` writes +0x3D
of a task (`engine.md` §2).

Design consequence for a v2: an adaptive answer must be produced **inside isFps30 only**. Writing it into +0x45
would also trigger the extra vsync wait at 0x13E494 (halving that frame's presentation), and funcInit overwrites
+0x45 at the start of every frame anyway.

## 5. Sites whose 60fps branch looks wrong, dead or untested

The 1.0 branch of every site has never run in the shipped game (every caller's task is created at mode 1;
Boot, the only mode-0 task, reads +0x45 inline). All 122 sites are symmetric constant selects, so the 1.0 branch is
the same code with a smaller constant. Points worth knowing (all confirmed in code, effects = likely):

1. **KJMenu C36 (ret KJMenu+0x12B9C): frame-counted wait in a step-aware helper.** FUN_13812B74 passes the step to
   FUN_1380F684 (KJMenu+0xF684), which moves 3 `MoveVBase` with the step, but in its state 1 it decrements the
   short `obj+0x7A32` by **1 per call** until 0 (`if (state == 1) { if (--cnt != 0) return 1; state = 2; }`);
   `cnt` is reloaded from `(u16)[[MComSys::_sys+0x1528EC]+0x574]` when state 0 ends. At 60fps this wait is half as
   long (cosmetic Bowser Jr. menu animation timing; the parameter value is runtime data). Not an isFps30 bug, but the
   only frame-counted timer found inside a function that receives the step. (MOD2 owns KJMenu behaviour.)
2. **MainMenu C86, C98–C101: isFps30 called, result discarded** (r0 reloaded immediately: 0x15007498,
   0x15019D34, 0x1501CD34, 0x1501D59C, 0x1501D978). The functions are page input handlers (`*param_2 & 0x802`
   button tests). No 60fps branch exists there; nothing to fix.
3. **S4 (ret 0x1EBD80)**: the step only gates `if (step <= 0) return;`, always true for 1.0 and 2.0.
4. **KJMenu C45 (ret KJMenu+0x17D34)**: `do { r = FUN_1381FA10(step) } while (r == 0)` finishes a list animation
   inside one frame (skip-to-end); the step only changes the iteration count.
5. **Latched steps (28 b-sites)**: correct under D1 (decided before any of them runs: field init FUN_00302A64 runs
   after `TaskBase::init` via 0x301674; menu pages are built after the MTaskBase ctor's `init`), but wrong whenever
   the mode changes after they ran: the community cheat (flip ~50 ms after init) leaves `fld+0x1A4C = 2.0` until the
   field state machine sets `fld+0x6E0` bit 0x40, and leaves every cursor created in the 30fps window blinking at
   2× speed for that page's lifetime. Any runtime opt-out (credits back to 30, `engine.md` §9) must recompute
   `fld+0x1A4C` (S8 expression) and accept that open menus keep their cursor step.
6. `fld+0x1A50` (previous field step, written by S8 at 0x30706C) has no reader in the dump (offset search);
   irrelevant for 60fps.

No site uses frame parity, `== N` on a stepped counter, or a 30fps-only code path.

## 6. Is a v2 adaptive isFps30 safe for every site?

v2 as asked: for a promoted task (+0x41 == 1), `isFps30()` returns 1 on a frame that followed an overrun (the
previous frame took ≥ 2 vsyncs), so that frame advances 2.0 steps (real-time catch-up, like `hb::sys::CGameSpeed`).

**Answer: no, not for every site. It is safe for the 94 sites of categories a and d; the 28 latched sites (b) must
keep the base answer.** On a catch-up frame an a-site runs exactly the code the shipped 30fps game runs on every
frame (step 2.0) and recomputes next frame; all their tests are thresholds (`<= 0`, `< 1`, `> 0`, `< 0`, `modff`
integer part), so alternating 1/2 steps cannot jump over a target. A b-site stores the value of one particular
frame; if that frame is a catch-up frame, 2.0 stays in force while the task runs at 60 → that object (or the whole
field) runs 2× fast until it is re-created/recomputed.

### 6.1 Exceptions (return addresses)

Static (fixed runtime addresses):

| ret | site | why |
|---|---|---|
| 0x302C6C | S7 field init | stores `fld+0x1A4C`, kept until S8 runs |
| 0x31ED40 | S9 fast-forward on | stores `fld+0x1A4C` once |
| 0x31EE60 | S10 fast-forward off | stores `fld+0x1A4C` once |
| 0x307078 | S8 field funcCalc (conditional) | per frame only while `fld+0x6E0 & 0x40`; when FUN_00307234 clears the bit (0x3072A8 path: state 0x19, transition) the last frame's value stays latched. Either exclude it (then the field gets **no** catch-up at all, because every field updater reads `fld+0x1A4C`), or keep it adaptive **and** rewrite `fld+0x1A4C` with the base step where the bit is cleared. The second option is the only one that makes v2 useful in the field. |

CRO (module + offset; the runtime `lr` = CRO runtime base + offset, and CRO bases are only known at runtime,
`runtime/findings.md` §0): the 25 cursor-latch sites

| module | ret offsets |
|---|---|
| AttackMiniGame | +0x219C (C15, virtual init) |
| BCat | +0x8B8 (C16) |
| Colosseum | +0x34F8 (C19, virtual init) |
| KJMenu | +0x2EB4, +0x3704, +0xDB4C, +0x10B44, +0x19780, +0x1A980, +0x356EC, +0x36800, +0x38DD4, +0x39F40 (C30, C31, C33, C34, C47, C48, C63–C66) |
| LoadMenu | +0x3224 (C68, virtual init) |
| MainMenu | +0x2404, +0x4F30, +0x9D8C, +0xE72C, +0xEA24, +0x10600, +0x1843C, +0x213C0 (C81, C82, C89–C92, C97, C102) |
| SaveMenu | +0x1514 (C105, virtual init) |
| ShopMenu | +0x135F0, +0x1363C (C121, C122) |

**Recommended instead of 25 lr checks:** exclude them at the single consumer. All 37 `MCursorBase::init` calls go
to static 0x324464, which stores the step at 0x3244D8 (`0b8ac4ed vstr s17,[r4,#0x2c]`). A v2 patch there can store
the base-mode step of the current menu task instead of s17 (`[[0x3F62A8 MComSys::_sys]+4]+0x45 == 1 ? 2.0 : 1.0`;
every caller is a menu CRO running under an MTaskBase task). Then an lr exclusion list in isFps30 only needs the
3 static addresses above (+ 0x307078 if S8 is excluded). [confirmed: code; proposal: guess-level design]

### 6.2 Constraints a v2 must respect (from the site audit)

1. **One answer per task per frame.** Many functions call isFps30 several times per frame (MComSys::funcCalc S11
   menu step and S12 event step; KJMenu C49/C50 inside FUN_1381FA10 which also receives a step from C39/C42/C45; LoadMenu
   FUN_14806AC8 ten calls). Decide the flag once in `funcInit` (start of frame, before `funcCalc`), not per call.
2. **Only 1.0 or 2.0.** Every site selects between those two constants (C84 between ints 1/2); a stall of 3+ vsyncs
   still gets 2.0 (time is lost, unlike HugeBattle's cap of 10).
3. **Do not write +0x45** (§4: 0x13E494 would add a vsync wait to that frame; funcInit overwrites it anyway).
4. **Detection data exists:** `task+0x18C` = `nngxCheckVSync(0x400)` stored after every swap (0x13E6D4; mode-3 path
   0x13E5CC). The difference between two consecutive values is the vsyncs the last frame took. Free storage:
   +0x42/+0x43 (InitParam tail padding, untouched by ctor/init, `engine.md` §1.2; +0x41 is the D1 marker).
5. Old 3DS / non-promoted tasks must keep `isFps30 = (+0x45 == 1)` exactly.
6. v2 does not reach frame-counted code (C36's wait, the staff roll `frame += 1`, BAI `+= 2` loops, HugeBattle has
   its own step); those behave as in v1.

### 6.3 What v2 would buy

On frames after an overrun the game keeps real-time speed instead of slowing down (D3 behaviour). Motion then
alternates 1/2 steps (judder), input is still sampled once per frame, battle timing windows (60 Hz units) stay
hittable (likely: a window must already be ≥ 2 units wide to be hittable at 30fps, and steps of 1 or 2 cannot jump
over 2 consecutive units). The field is where it matters most
and is also the one place that needs the extra `fld+0x1A4C` fix-up (S8 row above).

## 7. Method and reproduction

```
.venv\Scripts\python.exe scripts\fps60\aud_sites.py sites  --out <f> --tsv <f>   # 122 sites + listing + decompile
.venv\Scripts\python.exe scripts\fps60\aud_sites.py cfuncs --out <f>             # per-function decompiled view
.venv\Scripts\python.exe scripts\fps60\aud_table.py --md <f> --tsv <f>           # consumer / task / first-pass cat
.venv\Scripts\python.exe scripts\fps60\aud_sites.py inline --out <f>             # 198 +0x45/+0x3D byte loads
.venv\Scripts\python.exe scripts\fps60\aud_sites.py inlinec --out <f>            # their decompiled lines
```
Enumeration = `armdis.callers(0x25EDD0)` (ARM BL/B/BLX words incl. conditional, veneer targets, literal words);
the only literal hits are the 9 veneer words. Ghidra's caller count for isFps30 (20 = 11 static functions +
9 veneers) agrees, so no Thumb caller exists. First-pass categories from `aud_table.py`; every b/d row, every
helper callee (FUN_1382174C, FUN_1380F684, FUN_1380F200, FUN_13815180, FUN_1381FA10, FUN_13826590, `Frm::update`,
`MCursorBase::init`) and every inline countdown were read by hand in the dump/listing. Cursor wrappers: the 16
`MCursorBase::init` calls without a nearby isFps30 are vtable wrappers (literal refs only, e.g. AttackMiniGame
0x10008888, Colosseum 0x1180CAC4, LoadMenu 0x1480EB10, SaveMenu 0x16805460); a scan of every `blx rN` preceded by
`ldr rN,[rX,#8]` in the 8 menu CROs found s0 set only at C15/C19/C68/C105 (+ two unrelated vector calls).

## 8. Runtime checks for RT2 (scene → expected observation)

| # | scene | how | expected (D1 build, New 3DS mode) |
|---|---|---|---|
| R1 | pause menu, save menu, shop, file select, KJ menu: any blinking/bobbing cursor | read the cursor object's +0x2C (float) / +0x1A (short) or time the bob | +0x2C = 1.0 and a 0.5 s cycle (30 units); with New 3DS mode off +0x2C = 2.0, same 0.5 s |
| R2 | first field frame after load, then fast-forward on/off (if reachable) | read `fld::System` (`[0x3F49B0+0x20]`) +0x1A4C every frame | 1.0 from the first frame (S7), 1.0×factor after S9, 1.0 after S10; never 2.0 |
| R3 | any battle | `btl::Main+0xBA15C` | 1.0 per frame |
| R4 | KJ menu screen using FUN_1380F684 (KJMenu runtime base + 0xF684) | break there, log `obj+0x7A34` state and `+0x7A32`, time state 1 at 30 vs 60 | state-1 wait half as long at 60 (§5.1) — decides whether MOD2 needs a fix |
| R5 | (v2 only) field walk with a forced overrun (e.g. a test hook that busy-waits ~20 ms every other frame) | `fld+0x1A4C` per frame, walking distance per second | 1.0/2.0 alternating, distance per second equal to the 30/60 baseline; after a transition (bit 0x40 cleared) the value must be the base step |

## 9. Evidence on the lead's decisions

- D1 (native mode at `init`, allow-list fld::System / btl::Main / kj::KJSystem / msys::MTaskBase): **supported.**
  Every one of the 122 sites asks one of these four task classes (KJ via `[0x3F61C0]`, battle via `[0x3F35F8+8]` or
  `btl::GetMain()`, menus via `MComSys::_sys→+4`, field via `this`); none asks Boot or `hb::HugeBattleSystem`, and
  HugeBattle has no isFps30 site. All 28 latched sites run after `TaskBase::init` of their task (field: confirmed, FUN_00302A64 via 0x301674;
  cursors: likely, they are page builders that read `MComSys::_sys→task`, and a pre-init read would already show as a
  wrong blink speed in the shipped 30fps game), so with D1 they latch 1.0. No CRO reads the fps byte (§4), so
  changing +0x3D itself (not only +0x45) is enough.
- D3 (fixed step v1): nothing in the sites requires adaptive stepping; v2 is possible with the §6 exceptions.
- No evidence against D2, D4–D6 from this audit.
