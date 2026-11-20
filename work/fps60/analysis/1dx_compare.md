# D1X — 1DX (KR) vs 3DX (JP v1.2) fps comparison

Worker D1X, started 2026-10-30. Written incrementally; sections marked (WIP) are not finished.
Game ids: `1dx_kr` (Mario & Luigi RPG1 DX, KR), `3dx_v12` (M&L RPG3 DX JP v1.2). Static code base 0x100000.
Confidence tags: **confirmed** (read in disassembly), **likely**, **guess**.

## 0. Engine core is identical (confirmed)

| function | 1DX KR | 3DX v1.2 | note |
|---|---|---|---|
| `ad::fw::TaskBase::isFps30() const` | 0x2AE220 | 0x25EDD0 | 1DX: `ldrb r0,[r0,#0x45]; cmp #0 → 0; cmp #1 → 1; else 0` (returns 1 only for mode 1) |
| `ad::fw::TaskBase::InitParam::InitParam()` | 0x2AD0AC | 0x24B240 | 1DX writes +0x30=1, **+0x31=0**, +0x32=1 (strb sequence at 0x2AD118..0x2AD124) — same defaults as 3DX |
| `ad::fw::TaskBase::funcInit()` | 0x1412A4 | 0x13E8B8 | byte-for-byte same logic: +0x44=+0x3C, +0x45=+0x3D, +0x47=(+0x3E && is3DActive@0x42924C), mode 2 → +0x48 toggle |
| `ad::fw::TaskBase::init(const InitParam&)` | 0x2E9340 | 0x28068C | memcpy 0x35 bytes InitParam → this+0x0C |
| `ad::fw::TaskBase::callbackVSync(u32)` | 0x1402E0 | 0x13DA24 | same: 0x400 → LightEvent +0x368, 0x401 → +0x370, flags +0x378, both → signal +0x41C |


Both exheaders request the same New 3DS mode: 1DX `ml 1dx/00040000001C4F00_v00.trim.3ds` ARM11 local caps flag bytes
(+0x0C..+0x0F) = `03 01 04 30` (L2 + 804 MHz, New3DS mode 1), identical to 3DX. Internal name "Remillio". **confirmed**

## 1. Which tasks run at which fps mode (InitParam+0x31 → TaskBase+0x3D → +0x45)

Method: every caller of `InitParam::InitParam()` and `TaskBase::init()` in both games (`armdis.py --callers`), class from
the vtable stored right after the `TaskBase` ctor (RTTI via `d1x_ctx.py <game> rtti <vtable>`), register value of the
byte stored at InitParam+0x31 traced with `d1x_ctx.py <game> regw` (all writes of that register between function
start and the store) plus `binto` (no branch skips the defining instruction). **All rows confirmed.**

| task class (RTTI) | 1DX creator → +0x31 store | 1DX mode | 3DX creator → +0x31 store | 3DX mode |
|---|---|---|---|---|
| `Boot` (vt 1DX 0x481CD8 / 3DX 0x3DCA1C) | 0x107D20: `mov r4,#0` @0x107D34 … `strb r4,[sp,#0x31]` @0x107EA0 | **0** | 0x1092FC: `mov r4,#0` @0x109310 … `strb r4,[sp,#0x31]` @0x109474 | **0** |
| `fld::System` (field; vt 0x487C5C / 0x3E3B3C) | Param fillers 0x370D80 `strb r2(=0),[r0,#0x31]` @0x370D9C and 0x370EE0 `strb r1(=0),[r0,#0x31]` @0x370EFC (chosen by byte 0x4AA35C in 0x132E54) | **0** | Param fillers 0x31CADC `mov ip,#1` @0x31CAE4, `strb ip,[r0,#0x31]` @0x31CB48; 0x31CD94 `mov r5,#1` @0x31CE38, `strb r5,[r0,#0x31]` @0x31CE44 (chosen by byte 0x415E64 in 0x131D70) | **1** |
| `btl::Main` (battle; vt 0x486184) | 0x216D88: `mov r2,#0; mov fp,r2` @0x216D9C/0x216DA4 … `strb fp,[sp,#0x31]` @0x218154 | **0** | 0x28DB2C: `mov fp,#1` @0x28DD60 … `strb fp,[sp,#0x69]` (= InitParam@sp+0x38 +0x31) @0x28EEA8 | **1** |
| `kg::KGSystem` (1DX Bowser's Minions) / `kj::KJSystem` (3DX Bowser Jr.'s Journey) | 0x1B2064: `mov r5,#0` @0x1B2080 … `strb r5,[sp,#0x39]` (InitParam@sp+8) @0x1B2B28 | **0** | 0x196940: `mov r6,#1` @0x196FF0 … `strb r6,[sp,#0x41]` (InitParam@sp+0x10) @0x197410 | **1** |
| `msys::MTaskBase` (menus; vt 0x48917C / 0x3E4874) | 0x2E06E4: `mov r5,#0` @0x2E0708, `strb r5,[sp,#0x31]` @0x2E0730 | **0** | 0x334688: `mov r1,#1` @0x3346AC, `strb r1,[sp,#0x31]` @0x3346C8 | **1** |
| minigames `mg::` (1DX EtcSys.cro; also Title/Staffroll, see §3) | EtcSys+0x45980 (0x10045980) Param ctor: `strb r1(=0),[r0,#0x31]` @0x100459E4 | **0** | — (no `mg::` system) | — |
| giant battle (3DX HugeBattle.cro) | — | — | HugeBattle EntryTask+0xD14: `mov r7,#1` @0x12802398, `strb r7,[sp,#0x41]` @0x128023FC | **1** |

InitParam+0x32 (stereo-3D request → +0x47) is 0 in every 1DX creator; 1DX never asks for 3D.

**Result: 1DX creates every gameplay task (field, battle, Bowser's Minions, menus, minigames incl. title and staff
roll) with fps mode 0 = 60 fps; there is no hardware-dependent choice (constant 0, no New-3DS test at the creation
sites). 3DX creates the same five task classes (field, battle, Bowser Jr., menus, HugeBattle) with an explicit
constant 1 = 30 fps.** Boot is mode 0 in both. So the 1DX code base is a working 60 fps build of the same engine, and
3DX is that engine with every creator flipped to 30 fps; the remaining differences are in the per-subsystem
`isFps30()` handling (§2).


## 2. Staff roll: different implementations; the 3DX one is hard-wired (confirmed)

**1DX**: `RO/Staffroll.cro` is a 0x2000-byte stub. `Staffroll:EntryTask` (0x110001A0) calls static
`SetMinigameWorkForStaffroll()` (0x1353E4: `mg::Work::_INSTANCE`.kind = 5), then `new(0x96AE8) mg::MGSystem()`
(EtcSys export 0x1004723C) and `TaskMan::entry(gTaskMainMan, …)`. So the credits are their own task. Its InitParam
(EtcSys 0x10045980, kind 5 → heap 0xE00000) has **+0x31 = 0 → 60 fps**, and the MGSystem frame calc (EtcSys
0x10046B24) computes a step with `isFps30()` (sites 0x10046FE0, 0x10047174: `step = isFps30 ? s19 : s20`, multiplied by
`[task+0x574]->+0x110` like the field step). The credits are a scripted animated sequence (`mg::staffroll::Seq0_Intro,
Seq1_Side, Seq2_Top, Seq3_Front`, `Proc_WaitCreaditEnd`, `Component::StaffrollResLoadProcess`, RTTI in EtcSys rodata
0x1005CDDF…) reading `rom:/Staffroll/$R$/Staffroll.bin` and `Staffroll/KR/mario_font_kr.bffnt`.

**3DX**: no task. The credits are a text scroller `fld::StaffrollCtrl` in `Field.cro`, driven by a field event
command in static code 0x2E8B24 (sub-command byte `[r3+8]`: 0 = `CreateStaffrollCtrl` + `init` and store at
`fld::System+0x1B3C`; 1 = `update`; 2 = `!isFinish` returned as the script's "still running" value; 3 = delete).
static.crs imports the four Field exports through stubs 0x131790/0x131798/0x1317A0/0x1317A8 (reloc offsets
0x31794…0x317AC). The scroller has **no step at all**:

```
Field+0x98C  fld::StaffrollCtrl::update()           (analysis 0x1200098C)
1200098C  push ... ; r1 = [this+0x14] (u32 frame) ; s3 = [this+0x28] (float speed = GetParamStaffroll()->+0x18)
120009E0  vnmls.f32 s0, s4, s3        ; pos = frame*speed - (param+0 + param+4)
120009F8  cmp r1, r6 ; movhs r0,#0xFF ; else alpha = frame*255/param+0   (fade-in in frames)
...       MessageSimple::play x4 (two text buffers of 0x400 u16 on the stack, sp+0x20 / sp+0x820)
12000DDC  ldr r0,[r4,#0x14] ; add r0,r0,#1 ; str r0,[r4,#0x14]     ; frame += 1 per call, unconditionally
Field+0x1000 fld::StaffrollCtrl::isFinish()          (analysis 0x12001000)
12001000  vldr s0,[r0,#0x14]; vldr s1,[r0,#0x28]; vldr s2,[r0,#0x24]; vcvt.f32.u32 s0,s0
12001010  vmul.f32 s0,s0,s1 ; vcmpe s0,s2 ; movgt r0,#1                 ; done when frame*speed > total height
```

Consequence at fps mode 0 (**likely**, needs runtime check): the event command runs once per field frame, so the
roll scrolls and fades in at 2× speed and `isFinish` turns true at half the wall-clock time, while the credits BGM
and the rest of the ending event keep their own timing. 1DX offers no drop-in replacement (different design). A
3DX fix has to scale this counter: e.g. in `StaffrollCtrl::init` store half the speed (`this+0x28`) and double the
fade length when the field task is in 60 fps mode, or add `isFps30()?1:0.5`-style stepping to `update`. Whether this
desync is what crashes the ending at 60 fps is for CRS/RT to confirm (the two 0x800-byte stack text buffers do
not grow with speed, so a buffer overrun from the scroll itself is not visible here).



## 3. All 1DX isFps30() call sites vs 3DX (worker D1X2, 2026-10-30)

Method: `armdis.py 1dx_kr --callers 0x2ae220` + `decomp.py 1dx_kr 0x2ae220 --xrefs` (Ghidra class names from vtables),
`scripts/fps60/d1x_sites.py <game>` (per-site function, class guess from neighbouring named functions, first consumer),
`d1x_match.py fps30` (Jaccard twin search 1DX→3DX), then the C dumps of both twins read side by side
(`decomp.py <game> <addr> --cached`; `scripts/fps60/d1x_grep.py` greps the dumps with the enclosing function).
"(2/1)" below = `isFps30() ? 2.0 : 1.0`; "gs" = game-speed float `[task+0x574]+0x110` (1DX) / `+0x7C` (3DX).

**Count.** 1DX has **48 call sites**: 46 in static + 2 in EtcSys.cro (49 Ghidra code xrefs = 48 calls + the EtcSys
veneer). 3DX has 14 static + 117 CRO sites (131 code xrefs). **confirmed**

**The armdis nearest-symbol labels of the 1DX sites are misleading** (they name the closest exported symbol, often
0x10000–0x40000 bytes away). Real owners (Ghidra vtable names, confirmed):
`ad::pctx::PctxManager::init+0x48234` = `kg::KGSystem` calc; `Message+0x2164` = field init; `ad::fw::Resource::
getFileData+0x528c` = battle object step (twin of `btl::ObjBase::calcUpdateSpd`); `fld::FldMdl+0x21ed8/+0x2445c` =
field re-init / `fld::System` calc; `fld::TaskMain::DeleteStaffrollSaveData+0x1fa0/+0x219c` = **field event
fast-forward (hold R), not the staff roll**; `Prim::setProj2dParallax+…` = `menu::`/`shop::` pages and `msys::MComSys`;
`SndSys::init+…` (the "unnamed region") = `kg_menu::` (Bowser's Minions menus: Quest/Amiibo/Result pages);
`ad::fw::TaskBase::isPause+…` = `kg::` object getStep virtuals. No 1DX site is in particle, message-text, camera or
sound code: those subsystems receive a step argument from their owner in both games (see §4).

### 3.1 Site table, part 1: task steps, field, battle, Bowser's Minions/Bowser Jr. objects (all confirmed)

| # | 1DX site | 1DX function | what the (2/1) drives | 3DX counterpart | 3DX same branch? |
|---|---|---|---|---|---|
| 1 | 0x1B1614 | `kg::KGSystem::vfunc_0x18` (task calc) 0x1B1534 | KG step `+0xC9DDC = gs×(2/1)×local(+0xC9F4C)`; raw (2/1) also to 2 fade `MoveC::update` (+0x4E96C), LocationUI CellAnime/MoveFBase, FUN_001A1690 | `kj::KJSystem::vfunc_0x18` 0x195D94: site 0x195E90 KJ step `+0x61C58 = gs×(2/1)×local(+0xC8D90)`, raw to fades `MoveC` +0x4E798, FUN_0018575C, FUN_0016B5D4; site 0x196260 raw to `MoveC` +0xC89F8 | **yes** (3DX has one more site) |
| 2 | 0x215858 | `btl::Main::vfunc_0x18` (battle calc) 0x21582C | battle step `(2/1)×gs×local(+0x8B20)`, accumulated +0x8B28 | `btl::Main::vfunc_0x18` 0x28B67C, site 0x28B6A0: `(2/1)×gs×local(+0x8A3C)` → +0x8A44 | **yes** |
| 3 | 0x35BA60 | `fld::System::vfunc_0x18` (field calc) 0x35B61C | field step `+0x23DB4 = (2/1)×gs×local(+0x23DB0)` **every frame**; passed to `PctxManager::update`, `dfx::Unit::updateFrm`, `CellAnime::update` | `fld::System::vfunc_0x18` 0x306BC4, site 0x307074: `+0x1A4C = (2/1)×gs×local(+0x1A48)` when `+0x6E0 & 0x40`; passed to `PctxManager::update` (0x24D0C4) ×2 and FUN_0036F7EC ×2 | **yes** (recomputed each frame while bit 0x40 is set) |
| 4 | 0x265C78 | FUN_00265B24 = field-system init (from `fld::TaskMain` init FUN_00371320) | initial field step | FUN_00302A64 (from FUN_003014E4), site 0x302C68 | **yes** |
| 5 | 0x3594DC | FUN_0035944C = re-init of an already existing `fld::System` (else-branch of FUN_00371320) | step recompute on resume | none: 3DX has a single init path (FUN_00302A64); the calc recomputes the step anyway | n/a, no gap |
| 6 | 0x372D00 | outlined block 0x372CDC of FUN_00372DF4 (Ghidra folds it in) | field event **fast-forward on** (pad word bit `0x100` held, = R in the nn::hid layout (**likely**), plus a flag): local speed = `[0x4AC280]`, step recomputed | FUN_0031EC90, site 0x31EE5C: local = `[0x412C80]` | **yes** |
| 7 | 0x372EFC | FUN_00372DF4 (called from `fld::System` calc) | fast-forward off: local = 1.0, step recomputed | FUN_0031EC90, site 0x31ED3C | **yes** |
| 8 | 0x3A7908 | `msys::MComSys::vfunc_0x8` (= funcCalc) 0x3A78F8 | menu update FUN_003A76C4(step) | `msys::MComSys::funcCalc` 0x32F40C, site 0x32F41C → FUN_0032EEF8(step) | **yes** |
| 9 | 0x3A7934 | same | menu step stored at `MComSys+0xE5DCC` (pages read it) | site 0x32F448 → `MComSys+0xE6530` | **yes** |
| 10 | 0x10046FE0 | `mg::MGSystem::vfunc_0x18` (EtcSys+0x46B24; minigames **and the credits task**, §2) | MG step stored +0x969E8 | none: 3DX has no `mg::` system; its credits are `fld::StaffrollCtrl` with no step (§2) | **NO → gap G1** |
| 11 | 0x10047174 | same | FUN_1004493C(step) | none | **NO → gap G1** |
| 12 | 0x2A5B30 | FUN_002A5B14 (22 callers in `btl::`) | object speed: flag `+0x14 & 2` ? `(2/1)×spd(+0x10)` : `owner(+0x18)->+4 × spd` | `btl::ObjBase::calcUpdateSpd` 0x23C784, site 0x23C7A0 (flag `+0x24 & 2`, spd +0x20, owner +0x2C) | **yes** (identical) |
| 13 | 0x1E830C | `btl::ChrCmdPcCmdSelect::vfunc_0x8` | command-block key-repeat timer `obj+0x40 -= (2/1)` | Battle.cro `btl::ChrCmdPcCmdSelect::vfunc_0x8` Battle+0x10524 (0x11010524): `+0x40 -= (2/1)` | **yes** |
| 14 | 0x23A90C | `btl::ObjCursor::vfunc_0xc` | target-cursor key-repeat timer `+0xA4C -= (2/1)` | Battle.cro `btl::ObjCursor::vfunc_0xc` Battle+0x5C560 (0x1105C560): `+0xA64 -= (2/1)` | **yes** |
| 15 | 0x1E9264 | `btl::ChrCmdPcDefHammer::ObjDispHam::vfunc_0xc` | `if ((2/1) > 0)` before re-aiming the hammer (always true) | same class, static 0x1EBD7C | **yes** (no timing effect in either) |
| 16 | 0x40B8C0 | `kg::FadeObj::vfunc_0x8` (getStep) | flag `+0x4C0` ? raw (2/1) : KG step | `kj::ObjFade::vfunc_0x18` 0x3467D0, site 0x3467EC (flag `+0x2DC`, KJ step) | **yes** |
| 17 | 0x40A954 | `kg::LocationUI::vfunc_0x8` (getStep) | raw (2/1) for the location UI | `kj::LocationUI` update FUN_0016D984, site 0x16D998: raw (2/1) → `CellAnime::update`, `MoveFBase::update(+600)` (called from KJSystem calc) | **yes** (inlined instead of virtual) |
| 18 | 0x40A980 | `kg::TaskEscape::ObjEscFont::vfunc_0x8` (getStep) | raw (2/1) for the animated "escape" banner font | `kj::TaskProdEscape` (KJRPG+0xDCBC) has no font object (waits for `FadeDrawer` then `GameMain::Back`); the same raw-step getStep exists for the lose banner `kj::ObjFontLose::vfunc_0x18` 0x34525C (flag +0x468) | n/a, no gap |


### 3.2 Site table, part 2: menus (1DX menus are in static; 3DX moved them to CROs) (all confirmed)

1DX `menu::`/`shop::`/`kg_menu::` page code is in static; the 3DX equivalents are `main_menu::` (MainMenu.cro),
`shop::` (ShopMenu.cro), `kj_menu::` (KJMenu.cro), `load_menu::` (LoadMenu.cro). Page state functions all fetch the
task through the menu system global (1DX `[0x49E8B8]`, same role as 3DX `msys::MComSys::_sys` `[0x3F62A8]`; the 1DX
symbol is not exported) whose `+4` is the task, and call isFps30 on it.

| # | 1DX site(s) | 1DX function | what the (2/1) drives | 3DX counterpart | 3DX same branch? |
|---|---|---|---|---|---|
| 19 | 0x37A594 | `menu::MainMenu_TopPage::vfunc_0x14` | **nothing**: dead call (`bl isFps30` then `ldr r0,[r7]` overwrites r0) | `main_menu::MainMenu_TopPage::Core::vfunc_0x10`, sites 0x15004F2C / 0x15009D88: (2/1) → s0 of the next call | 3DX uses it (more fps-aware) |
| 20 | 0x38010C | `menu::MainMenu_ItemPage::vfunc_0x14` | dead call (same pattern) | ItemPage::Core sites 0x1500635C (`MoveVBase::update`), 0x15006E80, 0x15007494 | 3DX uses it |
| 21 | 0x380AF8 | same function | `Frm::update((float)((2/1) as int))` for the item page | FUN_15006534, site 0x150065AC: identical code (`VectorUnsignedToFloat` → `Frm::update`, then FUN_15013BB0(+0x870)) | **yes** |
| 22 | 0x38B740 | `menu::MainMenu_GuidePage::vfunc_0x14` | dead call | GuidePage list window 0x15019D30 | 3DX uses it |
| 23 | 0x390430 | `menu::MainMenu_StampPage::vfunc_0x14` | dead call | no Stamp page in 3DX | n/a |
| 24 | 0x398A48 | `menu::MainMenu_RecordPage::vfunc_0x14` | dead call | RecordPage::Core 0x1501CD30, 0x1501D598, 0x1501D974 | 3DX uses it |
| 25 | 0x39D92C | `menu::MainMenu_SettingPage::vfunc_0x14` | dead call (disasm 0x39D92C: `bl isFps30; ldr r0,[r6]`) | SettingPage 0x150213BC (`MCursorBase::init`), 0x15021E88/0x15021EB4 (`LytAnim::update`) | 3DX uses it |
| 26 | 0x3B0A5C | FUN_003AF6D4 (`shop::` list window, between `MListWndShopSell` and `EquipPage::Core::MoveListCur`) | byte countdown `+0xB -= (2/1)`, clamped at 0 | ShopMenu FUN_17002228, site 0x17002308: short countdown `+0x72E2 -= (2/1)` | **yes** |
| 27 | 0x3B73AC | `shop::ShopMenu_UseItemPage::vfunc_0x14` | byte countdown `+0xF -= (2/1)` | ShopMenu FUN_1701276C, site 0x1701284C: `+0x72E2 -= (2/1)` | **yes** |
| 28–35 | 0x3CCD74, 0x3CDD10, 0x3D19F8, 0x3D1BA0, 0x3D1F08, 0x3D2328, 0x3D25D8, 0x3D26D4 | `kg_menu::KGQuestPage::Core` state functions (FUN_003CCD50 … FUN_003D26B0, stored as `+0x20` next-state pointers) | panel open/close/slide animations: FUN_003CE714 / FUN_003CB118 / FUN_003CAC90 / FUN_003CE870 / FUN_003D04C4 (step) and 3× `MoveVBase::update(step)` | `kj_menu::KJQuestPage::Core`: 0x13811844, 0x13812B98, 0x13815E88, 0x1381697C, 0x13816BF4, 0x13816E60, 0x138170D8, 0x1381751C, 0x13817908, 0x13817BB4, 0x13817D30, 0x13817EE8. Example twin: 1DX FUN_003D25AC ↔ 3DX FUN_138178DC (3× `MoveVBase::update(step)` on +0x5306C/+0x530F4/+0x53150, then `isBusy`) | **yes** |
| 36 | 0x3DA4E0 | FUN_003DA2D8 (`kg_menu::KGAmiiboPage::Core`, called from `KGAmiiboPage::Core::vfunc_0x8`) | `Frm::update(step)` at the end of the amiibo-scan state handler | LoadMenu `load_menu::LoadMenuAmiiboPage::Core` FUN_1480AB9C, site 0x1480ABCC (`Frm::update(step)`) | **yes** |
| 37–48 | 0x3E43C4, 0x3E4474, 0x3E4524, 0x3E4624, 0x3E46C0, 0x3E4770, 0x3E4800, 0x3E5148, 0x3E5318, 0x3E53A8, 0x3E5438, 0x3E56D4 | `kg_menu::KGResultPage::Core` state functions | `Frm::update(step)` then wait for a layout animation | `kj_menu::KJResultPage::Core` 0x13832AE0, 0x13832D60, 0x13832E7C, 0x13832F54, 0x1383302C, 0x13833148, 0x138331D4, 0x13833280, 0x1383330C, 0x13833398, 0x13833938 (+ PartyMember 0x13831394). Example twin: 1DX FUN_003E43A0 ↔ 3DX FUN_138331B0 (`Frm::update(step)`, then `MLyt::getAnime(+0x110, …)` check) | **yes** |

### 3.3 Result of the site-by-site comparison

- **46 of the 48 1DX sites have a 3DX counterpart with the same `isFps30() ? 2 : 1` branch, or the 1DX site does
  nothing** (the 6 dead calls in 1DX MainMenu pages, where 3DX actually uses the value). The 3DX code base kept the
  60fps plumbing of every shared subsystem: task steps (field, battle, Bowser Jr., menus), field fast-forward, battle
  object speeds and menu cursors/timers, Bowser Jr. fade/location/banner steps, all menu page animations.
- **The only 1DX fps-aware code without a 3DX counterpart is `mg::MGSystem`** (sites 10–11), i.e. the 1DX minigame
  and credits task. 3DX's credits are the step-less `fld::StaffrollCtrl` (§2) → **gap G1** (§5).
- 3DX has 83 more call sites than 1DX, all in 3DX-only or reorganised code (Colosseum 11, LoadMenu 13, BCat,
  AttackMiniGame, SaveMenu, more MainMenu/ShopMenu/KJMenu page functions). None of them is a 1DX site that 3DX lost.


## 4. Code that never calls isFps30: where its step comes from, and hard-wired steps (D1X2)

### 4.1 Particles, effects, text, event waits get the owner task's step in both games (confirmed)

| subsystem | 1DX | 3DX |
|---|---|---|
| particles `ad::pctx::PctxManager::update(step)` | 4 calls: KG calc 0x1B17F8 (KG step), battle calc 0x215CF0 (computed value), field calc 0x35BA90 (field step), MG calc EtcSys 0x10047028 (MG step) | 3 calls: KJ calc 0x195F94 (KJ step), battle calc 0x28C17C (inside `btl::Main::vfunc_0x18`, source not traced), field calc 0x3070CC (field step) |
| effects `ad::dfx::Unit::updateFrm(step)` | 7 calls: stored/computed step (4) or the caller's argument (3), no constant | 7 calls: stored/computed step (4) or the caller's argument (3), no constant |
| field text | `fld::FldMsgSys::update(msg, field step)` from FUN_00267128 / FUN_0035BC9C | FUN_0020EC9C(field step, field step, `fld::System+0x1B30` MessageSys) from FUN_0020D228 / FUN_0020DCB0 / FUN_0020E02C (also `modes.md` §2) |
| other text | MG calc → `FldMsgSys::update(+0x4E460, MG step)` | KJ calc 0x195FEC → `MessageSys::func(+0x7E728, KJ step)`; menus FUN_0032EEF8 → `MessageSys::func(+0xFD8, menu step)`; HugeBattle ×2 (own step) |
| event waits | GlobalEvent step | GlobalEvent+0x14 = field step (`field60.md`), menu step (`modes.md` §2) |

So "particles/effects/text running 2× fast at 60fps" does **not** come from a missing isFps30 branch: those systems
are stepped by the field/battle/KJ/menu step, which is fps-aware in 3DX (§3, rows 1–9).

### 4.2 Constant steps passed to the step APIs (`d1x_steps.py compare --list`, `d1x_settle.py`)

A constant step is correct in 1DX (built for 60 Hz) and runs at half speed in 3DX at 30fps. At fps mode 0 such a
3DX call runs at 1DX speed, i.e. 2× faster than in 3DX today. Counts of constant-step calls (excluding `Frm::play`,
`playAuto`, `setSpd`, whose constants are animation lengths/rates):

| API | 1DX const calls | of which "stop/set then one update(1.0)" | 3DX const calls | of which "stop/set then one update(1.0)" |
|---|---|---|---|---|
| `MoveVBase::update` | 25 | 15 | 49 | 36 |
| `MoveFBase::update` | 20 | 0 | 3 | 0 |
| `Frm::update` | 11 | 7 | 5 | 2 |
| `CellAnime::update` / `LytAnim::update` | 1 / 3 | 0 | 0 / 0 | 0 |
| `fld::CircleMove::update` | 3 | 3 | 4 | 4 |
| `SndSeCtrl::update` | 0 | 0 | 1 | 0 |

- **Most 3DX constant steps are a one-shot "settle", not timing.** Typical code (3DX 0x2D1B1C,
  `fld::PlayerPartyMario::ActionStateSpinJumpKatagurumaToNormal::vfunc_0x10`):
  `bl MoveVBase::stop(int)` → `if (mover+0x5C == 0) MoveVBase::update(mover, 1.0)`. The 36 such 3DX sites include
  the player piggyback/drill/shell action states (18 sites), `fld::Chr::vfunc_0x20` (5), `ChrBasicWander` /
  `ChrTerritoryWander`, 5 field event command handlers (0x2DEB78, 0x2E055C, 0x2E1AC0, 0x2E1B78, 0x2E4E94, all in
  `GlobalEvent::_CmdFuncTbl` 0x3A30C4); they behave the same at 30 and 60fps. The `MoveFBase::update(1.0)` calls of
  both games (1DX 20, 3DX 2) all follow a call to one unnamed function (1DX sub_2D539C, 3DX sub_26BDCC), most likely
  the same stop/set idiom (**likely**, not read).
- **The remaining 3DX per-frame constant steps are code shared with 1DX, where 1DX has the same constant.**
  Example, identical instructions in both games: 1DX `menu::MainMenu_EquipPage::Core::MovePnlNameBar::vfunc_0x10`
  0x3834D8 and 3DX `main_menu::MainMenu_EquipPage::Core::MovePnlNameBar::vfunc_0x10` MainMenu+0xC0E0
  (`bl MoveVBase::isBusy; vldr s0,=1.0; bl MoveVBase::update`). At mode 0 these menu name bars/panels move as in 1DX.
  3DX list (verify durations before treating any as a bug): MainMenu+0xC104/+0xC454/+0xCA38/+0xD10C/+0xD18C,
  ShopMenu+0x8484/+0x8584/+0x965C/+0xBD30/+0xFDB8/+0x108C4/+0x10910 (`MoveVBase::update(1.0)`), MainMenu FUN_150062CC
  +0x62F8 (`Frm::update(1.0)`, item page), static FUN_0019DE7C 0x19DF00/0x19DF18 (Bowser Jr. placement:
  `SndSeCtrl::update(1.0)`, `Frm::update(1.0)`), KJRPG `kj::TaskProdMove::vfunc_0x8` KJRPG+0x7B9C (`Frm::update(1.0)`),
  static FUN_00211228 0x211450 (`MoveVBase::update(1.0)` right after another update call; not classified).
  These are hand-offs for MOD2/AUD (Bowser Jr. ones) and are cosmetic in the menus.
- **Pairing result:** 134 of the 791 3DX step-API calls have a 1DX twin function (Jaccard ≥ 0.2, `d1x_pairs.py
  --all`). In none of them does 3DX pass a constant where the 1DX twin passes a step; the 3 class differences are
  argument/return-value plumbing only. So in shared code 3DX did not lose step plumbing at the API level either.

**Tool gap found (affects every worker reading the dumps):** Ghidra marked `MoveVBase::stop(int)` (3DX 0x24F578,
1DX 0x2BEB1C) as non-returning. The C dump of every function that calls it is cut off after that call
(`/* WARNING: Subroutine does not return */`): 87 functions in 3DX, 64 in 1DX. The disassembly continues normally
(e.g. 0x2D1B20 after the call at 0x2D1B1C). Read those functions with `decomp.py … --asm` or `armdis.py`.

## 5. Gaps and patch points (D1X2)

**Answer for the user:** 3DX runs on the 1DX engine and kept almost all of its 60fps code. Every shared subsystem
still has the `isFps30() ? 2 : 1` branch (46 of 48 1DX sites, §3), and particles, effects, text and event waits
take the owner task's step (§4.1). What 3DX lacks is (a) the 60fps setting at task creation (every 3DX gameplay task
is created with fps mode 1, §1; this is lead decision D1) and (b) a stepped credits sequence (gap G1). No other
"1DX has the branch, 3DX lost it" case exists in static code or the CROs.

| id | 3DX location | now | proposed change | why (1DX evidence) | side effects / owner |
|---|---|---|---|---|---|
| G1 | static field event handler 0x2E8B24, sub-op 0: `bl 0x131790` (Create) at 0x2E8B80, store at `fld::System+0x1B3C`, `bl 0x131798` (`fld::StaffrollCtrl::init`) at 0x2E8B98; insert after 0x2E8B98 | `update()` adds 1 to `frame` per call (Field+0xDDC); scroll = `frame × speed(+0x28 = 2.0)`, `isFinish` = scroll > total (Field+0x1000) | if the `fld::System` passed in has `+0x45 == 0`: `ctrl+0x28 *= 0.5` (= IMPL `--credits-fix`) | 1DX runs its credits as `mg::MGSystem`, a mode-0 task whose calc multiplies by `isFps30 ? s19 : s20` (EtcSys 0x10046FE0/0x10047174). Halving the px-per-update speed at twice the update rate gives the same px/s and the same `isFinish` time as 30fps | the fade-in (`alpha = frame×255/param+0`, Field+0x9F8) still finishes in half the 30fps time (cosmetic). Whether the 60fps credits **crash** has another cause is for CRD (`credits/REPORT.md`) |
| — | Menu/Bowser Jr. code with a constant 1.0 per call (§4.2 list) | 1.0 per call, same as 1DX | none needed for parity with 1DX | identical instructions in 1DX (example MovePnlNameBar 0x3834D8 ↔ MainMenu+0xC0E0) | at mode 0 these run at 1DX speed, i.e. 2× their 3DX-30fps speed; MOD2/AUD decide if any is visible |

**D1 cross-check (no evidence against it):** 1DX creates exactly the task classes of the D1 allow-list at mode 0
(`fld::System`, `btl::Main`, `kg::KGSystem` ≙ `kj::KJSystem`, `msys::MTaskBase`) plus `mg::MGSystem` (minigames,
credits) and Title, which 3DX does not have as separate tasks (the 3DX title and credits live in `fld::System`).

## 6. Runtime checks for RT2 (D1X2)

Globals: current task `[0x3F40B4]`; battle `btl::Main*` = `[0x3F3600]`; Bowser Jr. `kj::KJSystem*` = `[0x3F61C0]`;
menus `msys::MComSys*` = `[0x3F62A8]` (`msys::MComSys::_sys`). Expected values with the D1 hook active (mode 0)
versus the unpatched game (mode 1); game speed 1.0, no fast-forward:

| # | scene | read | mode 1 (30fps) | mode 0 (60fps) | confirms |
|---|---|---|---|---|---|
| 1 | field, walking | f32 `fld::System+0x1A4C` | 2.0 | 1.0 | §3 rows 3–4 |
| 2 | field cutscene, hold R (likely the pad bit 0x100 the code tests) | f32 `+0x1A48` / `+0x1A4C` | `[0x412C80]` / 2×that | `[0x412C80]` / 1×that | rows 6–7 |
| 3 | battle | f32 `btl::Main+0xBA15C` (the BAI step register `$7012`, `battle.md` §2.4) | 2.0 | 1.0 | row 2 (the calc's own accumulator `+0x8A44` keeps only the fraction after `modff`, so it reads 0 in both modes) |
| 4 | Bowser Jr.'s Journey | f32 `kj::KJSystem+0x61C58` | 2.0 | 1.0 | row 1 |
| 5 | pause menu open | f32 `MComSys+0xE6530` | 2.0 | 1.0 | rows 8–9 |
| 6 | field right after a room change or battle exit | `+0x1A4C` within the first frames | 2.0 | 1.0 (if it shows 2.0 for some frames, the field init FUN_00302A64 ran before `funcInit` copied +0x3D→+0x45; the calc corrects it while `+0x6E0 & 0x40`) | rows 3–4, D1 timing |
| 7 | Equip page name bars (MainMenu) | slide time by eye/video | reference | half of the 30fps time (= 1DX) | §4.2 |
| 8 | credits test bed (CRD) | wall-clock time to `isFinish`, BGM end | reference | same as 30fps with G1, half without | G1 |

## 7. Open questions (D1X2)

- Durations of the §4.2 constant-step movers were not compared between the games (1DX and 3DX might use different
  frame counts in `MovePnlNameBar::vfunc_0x8`); the C dump of those functions is truncated by the bogus no-return of
  `MoveVBase::stop(int)` (§4.2 tool gap), so this needs `--asm` reading.
- 3DX `fld::System` calc recomputes the field step only while `+0x6E0 & 0x40` is set; who sets/clears bit 0x40 was
  not traced (1DX recomputes every frame). Harmless if D1 decides the mode before the first calc (check 6 in §6).
- 3DX inline fps readers found by `d1x_inline.py` and not in 1DX: `ad::fw::TaskBase::isStoreCmdList` 0x342810 (mode 2
  + 3D only, caller HugeBattle) and KJRPG FUN_140352D4 (flagged FLOAT2/1, not read). `Boot::vfunc_0x18` has the same
  inline 2/1 reader in both games (1DX 0x375658, 3DX 0x322700). AUD owns the full reader inventory.
