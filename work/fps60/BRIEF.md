# 60fps mode for M&L RPG3 DX (JP v1.2) — shared brief for all workers

Read this whole file first. Then read the section for your workstream ID (given in your task).
Project root: `C:\AI-Projects\mario-luigi-rpg-3dx-korean-patch` (also read `AGENTS.md` sections 0–2 and 7).

## 1. Mission

Add a **60fps mode** to 『マリオ&ルイージRPG3 DX』 JP **v1.2** (title `00040000001CA900`, update `0004000E001CA900`),
with the Korean patch installed. **New 3DS only** (the game's exheader already requests 804 MHz + L2 cache + 124 MB
mode; Old 3DS must keep 30fps). It must be robust enough to run on **real hardware** (Luma3DS: `code.ips` +
LayeredFS romfs) and on Azahar. Known problems of the existing community 60fps cheat must be understood and fixed:
broken **action commands** (timed button presses in battle) and **crashes** (scene/battle/menu transitions,
giant-Bowser battles, and the **staff roll/credits, which crash "without fail" at 60fps**). The sister game
『マリオ&ルイージRPG1 DX』 (KR, `ml 1dx/`) uses the same AlphaDream engine (`ad::fw`) and is the reference to
compare against.

Lead (main agent) integrates, decides the patch design and builds the final patch. Workers investigate,
build tools and report. **Workers do not write into `patch/`** and do not change the Korean text/image work.

## 2. Hard rules

- Never modify originals: `romfs/`, `romf2/`, `exefs/`, `exefs2/`, `unpacked/`, `ml 1dx/`, `*.cia`, `*.nds`, `text/jp/`.
- Never modify the user's Azahar setup: `%APPDATA%\Azahar\` (config, saves, sdmc, mods junction) and
  `C:\Program Files\Azahar\`. Runtime tests use the portable test instance owned by workstream RT (section 6).
- Write only inside your owned paths (section 6). Shared tools in `scripts/fps60/{cro,crolink,armdis}.py` are
  owned by the lead: do not edit them; copy into your own script if you need changes.
- Shell is PowerShell on a Korean-locale Windows host. Start shell commands with
  `[Console]::OutputEncoding = [Text.UTF8Encoding]::new($false); $OutputEncoding = [Text.UTF8Encoding]::new($false)`.
  Env vars are `$env:NAME` (never `%NAME%`). Python: `.venv\Scripts\python.exe` (capstone 5.0.6 + keystone 0.9.2 installed).
- Run every Python/Java/emulator command with a hard timeout: `Start-Process ... -PassThru` + `.WaitForExit(ms)`,
  stdout/stderr redirected to files. Never pipe a long-running launcher's stdout (it stalls the turn). Kill only
  processes you started (check the PID).
- Scratch files go to `$env:KIROCREW_SCRATCH`. Durable outputs go to your owned paths.
- If you view images with the read tool, keep each image ≤ 1600 px per side.
- Write your report **incrementally** (append findings as you go, at least every ~20 minutes of work), so nothing
  is lost if you are cut off. Your final chat message: 5–15 lines summary + report path.
- Evidence standard: every claim gets an address + disassembly/decompile snippet or a runtime measurement.
  Mark confidence (confirmed / likely / guess). Separate facts from hypotheses.

## 3. Facts established so far (lead, 2026-10-30)

Binaries (decompressed with ndspy BLZ; verified sizes):
- `work/fps60/bin/3dx_v12.code.bin` (JP v1.2, analysis target), `3dx_v10.code.bin`, `1dx_kr.code.bin`.
  Base 0x100000. 3DX v1.2 segments: text 0x100000–0x388BD8 (pages to 0x389000; 0x428 zero bytes of slack at
  0x388BD8 usable as a code cave), rodata 0x389000 (0x65E50), data 0x3EF000 (0x9170), bss 0x3F8170 (+0x3CBD0).
  1DX: text 0x100000 size 0x33FBC4, rodata 0x440000, data 0x497000.
- Exheader ARM11 local caps flag bytes `03 01 04 30`: L2 cache + 804 MHz, New3DS system mode 1 (124 MB).
- Symbols: `static.crs` named exports (2,461 for 3DX; mangled C++). CROs export few names but import many.
  `scripts/fps60/crolink.py` places each CRO at a fixed **analysis base** (NOT the runtime address) and binds
  imports; see `work/fps60/link/<game>/link.json` and `symbols.tsv`. 3DX bases: AttackMiniGame 0x10000000,
  BCat 0x10800000, Battle 0x11000000, Colosseum 0x11800000, Field 0x12000000, HugeBattle 0x12800000,
  KJGuide 0x13000000, KJMenu 0x13800000, KJRPG 0x14000000, LoadMenu 0x14800000, MainMenu 0x15000000,
  MenuGuide 0x15800000, SaveLoad 0x16000000, SaveMenu 0x16800000, ShopMenu 0x17000000.
  1DX: EtcSys 0x10000000, MiniGame 0x10800000, Staffroll 0x11000000, Title 0x11800000.
  CRO file offset = analysis address − module base. CRO calls into static go through veneers
  `ldr pc,[pc,#-4]; .word target` at the start of the CRO text (armdis annotates them as `->name`).
- Full grep-able listings: `work/fps60/dis/<game>/<module>.s` (ARM-mode linear sweep, symbol labels,
  literal-pool values, veneer targets). Thumb code (rare, libc) is garbled there; use `--thumb`.

Engine timing (3DX v1.2 static code, confirmed by disassembly):
- `ad::fw::TaskBase::isFps30() const` @ **0x25EDD0**: returns `this->byte[0x45] == 1`.
- `ad::fw::TaskBase::funcInit()` @ 0x13E8B8: `+0x44 = +0x3C; +0x45 = +0x3D (fps mode); +0x47 = (+0x3E && is3DActive())`;
  if mode (+0x3D) == 2 it also maintains a toggle byte +0x48. `is3DActive` @ 0x36B9C8 reads the shared page
  0x1FF81080 (3D slider float) and 0x1FF81084 (3D LED state). So fps mode is 0 = 60fps, 1 = 30fps, 2 = ? (3D-related).
- `ad::fw::TaskBase::init(const InitParam&)` @ 0x28068C copies 0x35 bytes of InitParam to TaskBase+0x0C, so
  InitParam+0x30/+0x31/+0x32 → TaskBase+0x3C/+0x3D/+0x3E. `InitParam::InitParam()` @ 0x24B240 sets
  +0x30=1, **+0x31=0 (fps mode 60 by default)**, +0x32=1. Task creators therefore set 30fps explicitly.
- `btl::ObjBase::calcUpdateSpd` @ 0x23C784: speed = (isFps30 ? 2.0 : 1.0) × obj->spd. `msys::MComSys::funcCalc`
  @ 0x32F40C picks a 2.0/1.0-style constant from isFps30. ⇒ the engine is built around a 60 Hz step with a ×2
  step in 30fps mode. This is why the cheat "runs at normal speed".
- Other names: `TaskBase::callbackVSync(u32)` 0x13DA24 (events 0x400/0x401 → LightEvents at +0x368/+0x370,
  flag byte +0x378), `waitVSyncEvent` 0x13DB30, `resetVSyncEvent` 0x26DAAC, `TaskBase::func` 0x13DBCC,
  `nngxWaitVSync` 0x287DB8, `nngxCheckVSync` 0x27EFF8. HugeBattle has its own `hb::sys::CGameSpeed`.
- isFps30 call sites (3DX v1.2): 15 in static, and via veneers: AttackMiniGame 1, BCat 1, Battle 2, Colosseum 11,
  KJMenu 38, LoadMenu 13, MainMenu 24, SaveMenu 1, ShopMenu 17; **HugeBattle 0, KJRPG 0, Field 0**.
  `python scripts/fps60/armdis.py 3dx_v12 --callers 0x25edd0`. 1DX static has 47 isFps30 call sites.

Community cheat (USA 00040000001D1400 / EUR 00040000001D1500, v1.2, by "Shay", Reshiban/60FPS-AR-CHEATS-3DS):
```
[60FPS v1.2]
D3000000 30000000
50000074 01000101   ; if u32[0x30000074]==0x01000101
20000075 00000000   ;   u8[0x30000075]=0
D0000000 00000000
520DA3AC 01000101   ; if u32[0x320DA3AC]==0x01000101
220DA3AD 00000000   ;   u8[0x320DA3AD]=0
D0000000 00000000
50000064 01000101   ; u8[0x30000065]=0 when pattern matches
20000065 01000000
D0000000 00000000
50000044 01000101   ; u8[0x30000045]=0 when pattern matches
20000045 00000000
D2000000 00000000
```
(Default-30 variant writes 1 back when the word is 0x01000001. EUR also has "game speed" float at 0x320DBDB8
(1.0 normal, 2.0 fast, 0.5 slow).) The pattern `01 01 00 01` at +0x44..+0x47 matches TaskBase +0x44 (copy of
InitParam+0x30), +0x45 (fps mode 1), +0x46, +0x47 (3D flag). So the cheat flips the fps byte of four live task
objects in the linear heap **after** they were initialised at 30fps.
Reported problems (GBAtemp "60 FPS Patches/Cheat Codes Releases and Discussion" pages 26–28, 2021; GBAtemp thread
663091, 2024): breaks action-command inputs; occasional crashes mostly on **real hardware** (Citra fine) during
battle and menu transitions and giant-Bowser scenes; repeatable crash "a little after the first Mibus fight… after
the third Chubby Goomba"; a "FIX" variant adds neighbour-field checks; a "Less Crashes" variant leaves 30fps as the
default and the player presses L+R after each scene change (the game resets the flag on every new menu/field/
battle/cutscene) — then crashes mostly stop, giant battles work, but **the credits crash every time unless 30fps
is restored first**.

## 4. Address/patch conventions for reports

- Static code: give the runtime address (0x1xxxxx–0x38xxxx); code.bin file offset = address − 0x100000.
- CRO code: give `Module+fileoffset` and the analysis address.
- A proposed code change = (location, original bytes/instructions, new instructions, why, side effects).
- Do not assume runtime CRO addresses; RT measures them at runtime when needed.

## 5. Tools

- `python scripts/fps60/armdis.py 3dx_v12 <addr|symbol-substring> [count] [--thumb]`
- `... --sym <substr>` symbol search; `--callers <addr>` direct branches, veneer calls and literal refs;
  `--lit <value>` literal search; `--where <addr>` nearest symbol.
- `python scripts/fps60/cro.py <cro> [--exports] [--imports]`, `python scripts/fps60/crolink.py <game>`.
- Grep the listings in `work/fps60/dis/` with the grep tool (fast).
- Ghidra headless + full decompiled C dumps are being built by workstream TG. Check `work/fps60/TOOLS_STATUS.md`;
  when it says READY, prefer the decompiled text in `work/fps60/decomp/<game>/` for understanding logic.
- Runtime harness (portable Azahar + RPC/GDB clients) is being built by workstream RT; see
  `work/fps60/runtime/HARNESS.md` when present. Only RT drives the emulator in wave 1.

## 6. Workstreams, ownership and outputs

| ID | Topic | Owned paths | Main output |
|---|---|---|---|
| WEB | prior art, cheats, crash reports, Luma/Azahar loading facts | `work/fps60/research/` | `research/web.md` |
| TG | Ghidra headless + decompiled dumps + decompile CLI | `tools/ghidra/`, `scripts/fps60/ghidra/`, `work/fps60/ghidra/`, `work/fps60/decomp/`, `work/fps60/TOOLS_STATUS.md` | dumps + STATUS |
| RT | runtime harness on a portable Azahar copy; runtime discovery of task objects; FPS measurement | `tools/azahar-test/`, `scripts/fps60/rt_*.py`, `work/fps60/runtime/` | `runtime/HARNESS.md`, `runtime/findings.md` |
| ENG | engine timing core (TaskBase lifecycle, fps mode per task, frame pacing/vsync, frame drops, game speed) | `work/fps60/analysis/engine.md`, `scripts/fps60/eng_*.py` | `analysis/engine.md` |
| D1X | 1DX comparison (does 1DX run 60? which tasks, how; fps-aware code 1DX has but 3DX lost) | `work/fps60/analysis/1dx_compare.md`, `scripts/fps60/d1x_*.py` | `analysis/1dx_compare.md` |
| BTL | battle + action-command timing at 60fps (static `btl::` + Battle/AttackMiniGame CROs) | `work/fps60/analysis/battle.md`, `scripts/fps60/btl_*.py` | `analysis/battle.md` |
| CRS | crash candidates: transitions, staff roll/credits, risky frame-count patterns | `work/fps60/analysis/crash.md`, `scripts/fps60/crs_*.py` | `analysis/crash.md` |
| HB | giant battles (HugeBattle.cro, `hb::`, CGameSpeed) at 60fps | `work/fps60/analysis/hugebattle.md`, `scripts/fps60/hb_*.py` | `analysis/hugebattle.md` |
| MOD | field/events/menus/Bowser Jr. RPG (KJ*)/minigames/Colosseum readiness | `work/fps60/analysis/modes.md`, `scripts/fps60/mod_*.py` | `analysis/modes.md` |

Every analysis report should end with: (a) a table of concrete patch points with proposed changes,
(b) what must be verified at runtime and how (scene, expected observation), (c) open questions.

### WEB
Collect every variant of the BIS+BJJ 60fps cheat (original, FIX, "Less Crashes" L+R/L+UP — get the exact code
text, likely in the thread's first post or the Reshiban repo history/issues/PRs), all crash/bug reports with
conditions (scene, hardware vs Citra, Luma/plugin versions), and anything about action commands. Search other
pages of the GBAtemp thread (search `site:gbatemp.net "Bowser's Inside Story" 60 fps`), Reddit, YouTube
descriptions. Facts to confirm with sources: native frame rate of 3DX per mode and of 1DX (SS+BM) per mode.
Technical facts with sources (prefer source code): (1) Luma3DS loader game patching paths for an updated title
(code.ips/code.bps, exheader.bin, code.bin), whether Luma patches the RO sysmodule to skip CRR/CRO signature and
hash checks, and since which version; (2) Azahar: which title-ID folder `load/mods/<tid>/exefs/code.ips` must use
for an installed update (read `src/core/file_sys/ncch_container.cpp` / loader code on GitHub azahar-emu/azahar),
whether Azahar checks CRO/CRR hashes or signatures, its cheat file format/location, GDB stub and the UDP RPC
server protocol (`dist/scripting/citra.py`, `src/core/rpc/`); (3) the GBAtemp tutorial "How to Change Game Speed
Independently of FPS (Example with Pokémon ORAS)" (2026) — summarize the method. Output `research/web.md` with URLs.

### TG
Download and install the latest Ghidra release (GitHub NationalSecurityAgency/ghidra; JDK 25 Temurin is already
installed — check compatibility, use a portable JDK 21 zip under `tools/` if needed) into `tools/ghidra/`.
Headless-import, for game `3dx_v12`: the static image (`work/fps60/bin/3dx_v12.code.bin` at 0x100000 with blocks
text RX / rodata R / data RW / bss RW sized per section 3) plus every relocated CRO image from
`work/fps60/link/3dx_v12/*.bin` at its analysis base, all in ONE program (so cross-module xrefs work), language
ARM:LE:32:v6 (ARMv6K, VFPv2). Apply labels from `work/fps60/link/3dx_v12/symbols.tsv` (static + CRO exports),
veneer labels (`->name`), and RTTI/vtable names if you can (typeinfo `_ZTI*` symbols exist). Mark Thumb entry points
(odd export addresses) with TMode. Run auto-analysis. Then do the same for `1dx_kr`. Produce full decompiled C
dumps: one file per module, every function, header line `// FUNC <addr> <name> (<module>)`, into
`work/fps60/decomp/<game>/<module>.c` (split files > 30 MB). Also a CLI `python scripts/fps60/ghidra/decomp.py
<game> <addr|name> [...]` that prints fresh decompilation (headless, read-only, must work while other agents use
the dumps; avoid project lock conflicts, e.g. by copying the project to scratch per call or serving requests from
one long-lived process). Update `work/fps60/TOOLS_STATUS.md` (`READY`/`PARTIAL`/`BLOCKED`, paths, usage, known
gaps) as soon as the first usable dump exists, then again at the end.

### RT
Create a portable Azahar test instance in `tools/azahar-test/` (copy `C:\Program Files\Azahar\*`; portable mode
= a `user` folder next to azahar.exe; verify Azahar really uses it). Install the game there by copying the user's
installed title folders (`%APPDATA%\Azahar\sdmc\Nintendo 3DS\0…0\0…0\title\00040000\001ca900` and
`title\0004000e\001ca900`) and copy (do not move) the save data; point `user/load/mods/00040000001CA900` at the
project's `patch/00040000001CA900` (junction or copy) so the Korean patch is active. Enable the RPC server and the
GDB stub only in the test instance's config; New 3DS mode on. Write `scripts/fps60/rt_rpc.py` (memory read/write
client, based on Azahar's `scripting/citra.py`, process selection) and `scripts/fps60/rt_gdb.py` (minimal GDB RSP
client: attach, read/write memory and registers, software breakpoints, continue/interrupt, report exceptions).
Boot the game from the command line (installed content `.app`, or whatever Azahar accepts) and measure:
(1) where the TaskBase objects live at runtime (scan the heap for `01 01 00 01` at +0x44 or for TaskBase-derived
vtable pointers; map them to their classes), (2) whether flipping +0x45 to 0 on the live tasks gives 60 presented
frames per second (measure via the emulator status bar if you have desktop tools, or via a frame counter in
memory), (3) the JP equivalents of the cheat's four addresses. If you have the `computer_*` desktop tools, you may
drive the test instance's window (keyboard mapping in its config) to reach the title screen/file select/field and
make save states there (record which slot = which scene). If you do not have them, say so and do everything else.
Never touch the user's own Azahar. Output `runtime/HARNESS.md` (exact launch/attach/measure steps) and
`runtime/findings.md`.

### ENG
Map the timing core of 3DX v1.2: TaskBase layout around +0x0C..+0x50 and +0x360..+0x420; how InitParam+0x31
(fps mode) is set for each task (find every task creation path: `TaskBase::init` callers, InitParam
constructions with +0x31 written, per-CRO `EntryTask`), and list which tasks/modes run with mode 0/1/2; how the
frame loop paces at 30 vs 60 (vsync events 0x400/0x401, waits, `nngxWaitVSync`, swap); what mode 2 does (the +0x48
toggle; stereo 3D); what happens when a frame overruns at mode 0 (slowdown? dropped frames? double step?);
whether the fps mode can be changed safely at runtime and which state is latched at init (this matters: the cheat
changes it after init); the global "game speed" float (EUR 0x320DBDB8 in linear heap — find the JP code that owns
it). Inventory all 15 static isFps30 call sites and summarise what each does. Recommend the cleanest code patch
point(s) to run tasks at 60fps on New 3DS only (how to detect New 3DS reliably in this binary; e.g. kernel config
memory APPMEMTYPE at 0x1FF80030 = 6/7 on New 3DS, or an existing SDK call), and how to keep a per-task opt-out
(e.g. keep giant battles/staff roll at 30 if they cannot be fixed).

### D1X
Same engine in 1DX KR (`1dx_kr`). Determine which 1DX tasks use fps mode 0/1/2 (static: InitParam+0x31 writes,
`TaskBase::init` callers; CROs EtcSys/MiniGame/Staffroll/Title), i.e. whether 1DX field/battle/menus run at 60fps
on New 3DS. Compare the 47 isFps30 sites of 1DX with the 3DX ones: find subsystems that are fps-aware in 1DX but
hard-wired in 3DX (especially battle action commands/input timing, staff roll — note 1DX
`fld::TaskMain::DeleteStaffrollSaveData` region calls isFps30 — sound/BGM sync, message/text speed, camera,
animation playback). Use function matching by shared symbol names, strings and code similarity. Output concrete
"3DX function X lacks the 60fps branch that 1DX function Y has" findings.

### BTL
Find how action commands are judged in 3DX battles (Mario/Luigi/Bowser attacks and dodges/counters, badge
gauge, special attacks; static `btl::` code and Battle.cro/AttackMiniGame.cro): input sampling (`nn::hid::CTR::
PadReader`, trigger vs hold), timing windows (frame counters, timers, animation-frame tests), and whether each
uses the isFps30-scaled step. Explain precisely why 60fps "breaks action command inputs" (window length halves?
trigger edge lost? counters incremented per frame but compared against 30fps tables?) and propose fixes that make
windows identical in milliseconds to 30fps. Also check battle timers (`btl::ObjTimer`), enemy AI timing,
`btl::Main::entryObj` (calls isFps30) and the battle transition in/out.

### CRS
Hunt crash causes. (1) Staff roll / credits: locate the code (3DX has no Staffroll.cro; look for `Staffroll/`
file names, `mario_font.bffnt`, staff-roll symbols in static or CROs) and find what fails at fps mode 0 (array
index from frame count, buffer sized for 30fps, stream/movie sync, divide by step, odd/even assumptions).
(2) Scene/battle/menu transitions: task teardown/creation, CRO load/unload, job queues (`CtrJobMan`), VRAM
transfer queues, command list sizes (`CmdList::init`) — anything whose capacity or timing assumes 2 vsyncs per
frame (e.g. a GPU command buffer or transfer queue that overflows when frames are produced twice as often, or a
loader thread starved on real hardware). (3) Generic risky patterns near fps-dependent code: counters decremented
by a step and tested with `==`, `x/step`, tables indexed by frame. Prioritise by likelihood of a hard crash and
explain how to confirm each at runtime.

### HB
HugeBattle.cro (giant Bowser battles, 1.8 MB, `hb::` namespace, no isFps30 calls, has `hb::sys::CGameSpeed`,
`hb::evscript::CTimer`, many `*_speed`/`*_frame` parameter names from `HB/*.csv`). Determine: how HB creates its
task (InitParam fps mode), how it paces frames, how CGameSpeed works, what happens if its task runs at fps mode 0
(2× speed? fine? crash?), and what would be needed to run giant battles at 60fps correctly — or recommend keeping
them at 30 with a clean per-task opt-out. Note the mic/touch/stylus inputs used in giant battles.

### MOD
Readiness of the remaining modes at 60fps: field movement/camera/collision and event scripts (`fld::`, Field.cro,
event wait timers, `fld::MsgSys` text speed — it calls isFps30), menus (MainMenu/LoadMenu/SaveMenu/ShopMenu/
KJMenu CROs all call isFps30 many times — check they are consistent), Bowser Jr.'s Journey (KJRPG.cro has no
isFps30 calls; `kj::` code in static does), Colosseum, BCat, AttackMiniGame and field minigames. For each mode:
what timing basis it uses, whether it would run correctly at fps mode 0, and suspected issues.
