# RT runtime findings (M&L RPG3 DX JP v1.2 + Korean patch, Azahar 2126.1.2 test instance)

Worker RT. Harness and exact commands: `work/fps60/runtime/HARNESS.md`.
Confidence tags: **confirmed** (measured here), **likely**, **guess**.

## 0. Environment facts (confirmed)

- Emulator: Azahar `2126.1.2 | HEAD-9e6f523` (user's `%APPDATA%\Azahar\log\azahar_log.txt`), copied to
  `tools/azahar-test/`. Game content in the user's install is decrypted (NCCH flags[7]=0x04 NoCrypto for both
  `00040000001CA900` and `0004000E001CA900`), so the test instance needs no keys or system titles.
- Copies verified by SHA-256 (base `.app` DA548427…, update `.app` 5D8E0534…, `ML3R_000/001/002.sav` identical).
- RPC server (UDP 45987) in 2126.1.2 supports only ReadMemory / WriteMemory / ProcessList / SetGetProcess
  (source `src/core/rpc/rpc_server.cpp` at tag 2126.1.2). **WriteMemory ignores the 0x30000000 linear heap**
  (allowed: image 0x00100000–0x04000000, heap 0x08000000–0x10000000, old linear 0x14000000–0x1C000000,
  N3DS extra 0x1E800000–0x1EC00000). The game's linear heap is at 0x30000000 (kernel 2.52), so writes there go
  through the GDB stub (`M` packet) or the cheat engine.
- GDB stub (TCP 24689) in 2126.1.2: non-blocking accept polled from the core loop (no wait at boot); `?` attaches the
  launched title and halts it; `c` resumes; `D` detaches and re-listens; single-step `s` unsupported (E5F);
  `Z0` writes `BKPT` (0xE1200070); `m` returns `E0E` for unmapped pages.
- Status bar "App: N FPS" = top-screen `GSP SetBufferSwap` calls per second (`video_core/gpu.cpp`
  `GPU::SetBufferSwap`: `if (screen_id == 0) perf_stats->EndGameFrame()`), i.e. presented frames per second.
- The emulator log prints every CRO load with its runtime base: `CRO "Field" loaded at 0x0063B000,
  fixed_end=0x0063F000` (user log: SaveLoad 0x0047B000, LoadMenu 0x00483000, Field 0x0063B000).
  `rt_rpc.py cros` parses it; the loaded CRO's rebased segment table gives its data/bss buffers.


## 1. Current task at the title/intro scene, 30fps baseline (confirmed, 2026-10-30 14:01, boot + ~60 s)

`rt_measure.py task --secs 2` (record in `measure_log.jsonl`, label `boot_title_30fps`), game pid 11:
- `u32 [0x3F40B4]` (current task) = **0x320DA370**, vptr **0x003E3B3C** (static .rodata). RTTI chain via
  vptr−4: **`fld::System` → `ad::fw::TaskBase` → `TaskMainBase` → `Task`**.
- Bytes task+0x3C..+0x48 = `01 01 00 01 | 01 00 00 00 | 01 01 00 00 00`
  → +0x3C=1, **+0x3D=1** (InitParam fps copy = 30), +0x3E=0, +0x3F=1, +0x40=1, +0x44=1, **+0x45=1** (live fps
  mode = 30), +0x46=0, +0x47=0 (3D off), +0x48=0.
- **Cheat address match:** task+0x3C = **0x320DA3AC**, exactly the community cheat's
  `520DA3AC 01000101 / 220DA3AD 00` (USA/EUR v1.2). So in JP v1.2 the fld::System task sits at the same linear-heap
  address, and that cheat line checks bytes +0x3C..+0x3F (`01 01 00 01`) and clears **+0x3D**, not +0x45.
  (+0x44..+0x47 here is `01 01 00 00`: the `01 01 00 01` pattern at +0x44 needs the 3D flag +0x47=1.)
- Frame counter `u32 task+0x578`: 1391 → 1450 in 2.003 s (8 samples, +7/+8 per 0.25 s) = **29.46/s** ≈ 30.
- Status bar (desktop tools, accessibility tree of the test window): `Speed: 100% / 100%`, **`App: 30 FPS`**,
  `Frame: 1.95 ms`.

## 3. New 3DS detection bytes (confirmed, same run, is_new_3ds=true)

- `u8 [0x3F716C]` (IsRunOnSnake cache) = **1**.
- `u32 [0x1FF80030]` (config memory APPMEMTYPE) = **6** (= New 3DS 124 MB mode, matching the exheader's
  system mode). Old 3DS values would be 0–5; the 178 MB mode would be 7.


## 2. Flipping the fps byte at runtime (confirmed, title screen, 2026-10-30 14:02–14:04)

Scene: title screen of the patched game (Korean logo 「마리오&루이지RPG3 DX 디럭스」, button 「게임 시작」,
`Ver. 1.2`), so the Korean patch and the v1.2 update are both active in the test instance.

| step (`rt_measure.py setfps …`, GDB `M`, game halted for the write only) | +0x3C..+0x48 afterwards | +0x3D | +0x45 | task+0x578 rate | status bar |
|---|---|---|---|---|---|
| baseline (section 1) | `01 01 00 01 01 00 00 00 01 01 00 00 00` | 1 | 1 | 29.46/s | App: 30 FPS, Speed 100% |
| write **+0x3D = 0** | `01 00 00 01 01 00 00 00 01 00 00 00 00` | 0 | **0** | **59.91/s** | **App: 60 FPS**, Speed 100% / 100% |
| then write only +0x45 = 1 (+0x3D still 0) | `01 00 00 01 01 00 00 00 01 00 00 00 00` | 0 | **0 again within 1 s** | 59.91/s | – |
| restore +0x3D = 1 | `01 01 00 01 01 00 00 00 01 01 00 00 00` | 1 | 1 | 29.96/s | – |

Facts:
- One byte, task+0x3D of the `fld::System` task (0x320DA3AD), switches the whole presentation from 30 to 60 frames
  per second: the task's frame counter doubles (29.5 → 59.9/s) and the emulator counts 60 top-screen buffer swaps
  per second, at 100% emulation speed. (confirmed)
- **+0x45 is re-derived from +0x3D while the task runs**: writing +0x45 alone is overwritten from +0x3D within
  ≤1 s, and clearing +0x3D alone makes +0x45 follow. So the lever is +0x3D (the InitParam copy), which is exactly the
  byte the community cheat clears (`220DA3AD 00`). Which code re-copies it (funcInit re-run per frame/scene, or
  another path) is for ENG to pin down. (confirmed behaviour; mechanism open)
- The switch is reversible at runtime on the title screen (back to 29.96/s after restoring +0x3D=1). No crash
  or freeze from the GDB halt/write/resume cycle.
- Not measured: whether game logic speed stays correct at mode 0 (needs a logic timer or a recorded scene),
  other scenes, and what the game writes back into +0x3D on a scene change.

## 4. The cheat's three other addresses in JP v1.2 (confirmed for the title scene)

`rt_rpc.py read 0x30000000 0x80` at the title screen:
```
30000040  78 51 42 00 00 7c 34 30 1c 00 00 30 00 00 00 00
30000060  01 00 00 00 11 01 0f 00 01 00 00 00 10 01 0f 00
30000070  02 00 00 00 17 01 0f 00 78 00 00 03 1d 01 0f 00
```
0x30000044 = `00 7c 34 30`, 0x30000064 = `11 01 0f 00`, 0x30000074 = `17 01 0f 00`: none holds `01 01 00 01`.
The start of the JP linear heap is allocator bookkeeping (pointers 0x30000014, 0x3000003C, 0x30347C00, static
0x00425178), so those three conditional cheat lines cannot fire in JP at this scene. Their JP equivalents
(other live TaskBase objects) still have to be found with `rt_rpc.py tasks` over the mapped linear heap
(`rt_gdb.py map` first) in field/battle/menu scenes. (open)

## 5. Open items for the wave-3 runtime worker

1. `rt_gdb.py map --out work\fps60\runtime\memmap.json`, then `rt_rpc.py tasks --json …` per scene (title, file
   select, field, battle, menu, Bowser, giant battle, staff roll) to list every live TaskBase, its class and +0x3D.
2. Per scene: does a scene change re-create tasks with +0x3D=1 (cheat users report "the game resets the flag")?
3. Game-logic speed at mode 0 (compare an in-game timer or a movement distance per second at 30 vs 60).
4. With the real code patch: repeat section 2 with no runtime write and confirm `App: 60 FPS` per scene.



## 6. Wave 2 (RT2): per-scene census, mode-0 behaviour, scene changes (2026-10-30, from 14:20)

Worker RT2. Same instance (Azahar 2126.1.2, New 3DS mode, Korean patch junction). Tools added/changed:
- `scripts/fps60/rt_census.py` (new): `snap` (current task, class, +0x3C..+0x48, +0x578 rate, game-speed float
  `[[task+0x574]+0x7C]`, class step variables, loaded CROs, every live TaskBase via RTTI scan; one JSON line per call
  in `work/fps60/runtime/census.jsonl`) and `counters` (3 snapshots over N s of the task object, static .data/.bss
  and the field save buffer; every u32/f32 that rises steadily, with its rate; `--compare` prints the rate ratio
  against an earlier run, so a counter that doubles at mode 0 is a per-frame counter). Raw scans:
  `work/fps60/runtime/census/*_counters.json`.
- `rt_gdb.py map`: (a) the stub answers `m` on an unmapped page with an **empty packet**, not `E0E`, so the old
  `is_mapped` said "mapped" everywhere; fixed. (b) one GDB round trip costs ~15 ms, so the 64 KiB sweep (~10k probes)
  ran > 120 s and the killed client left the game **halted** (counter frozen; resumed by any attach+`c`, e.g.
  `rt_gdb.py regs`). Now 1 MiB probes + binary-searched edges: 9.5 s. Islands < 1 MiB (CRO images) are not listed;
  CRO bases come from the log anyway.
- `rt_setup.py --config` now sets `log_filter=*:Info RPC_Server:Warning` (the RPC server logged 2 Info lines per
  request; the log had grown to 3.4 MB). CRO/LayeredFS lines are unaffected.

Memory map at the title (`work/fps60/runtime/memmap.json`, confirmed): image 0x00100000–0x00436000, heap
0x08000000–0x08540000 (5.3 MiB), shared 0x10000000–0x10003000, old-linear 0x1BC00000–0x1C000000 (4 MiB),
config/shared 0x1FF80000–0x1FF84000, **linear heap 0x30000000–0x37382000 (115.5 MiB)**. A full RTTI task scan of
heap + linear heaps (`snap`) takes ~7 s over RPC (0.1 ms per 1 KiB read).

### 6.1 Scene: title screen (Korean logo, 「게임 시작」), boot + ~3 min

| item | mode 1 (as booted) | after `setfps 0 --offset 0x3D` |
|---|---|---|
| current task `[0x3F40B4]` | 0x320DA370 `fld::System` (vptr 0x3E3B3C, static); CROs loaded: **Field** | same object |
| +0x3C..+0x48 | `01 01 00 01 01 00 00 00 01 01 00 00 00` (+0x3D=1, +0x41=0, +0x45=1) | `01 00 00 01 01 00 00 00 01 00 00 00 00` |
| live TaskBase objects (RTTI scan) | **1**: only that fld::System | – |
| +0x578 frames/s | 29.94 | 59.91 |
| status bar | `App: 30 FPS`, Speed 100%, Frame 1.95 ms | **`App: 60 FPS`**, Speed 100%, Frame 4.24 ms |
| field step +0x1A4C / +0x1A50 | 2.0 / 2.0 | **1.0 / 1.0** (recomputed: `+0x6E0` = 0x3900007E has bit 0x40) |
| game speed `[[+0x574]+0x7C]`, ffwd +0x1A48 | 1.0, 1.0 | 1.0, 1.0 |

Counter scan (2 s, ratio mode0/mode1): per-frame counters (×1.97): static 0x425258 (main-loop frame counter),
0x4300B4/0x4300B8, task +0xC4, +0x150, +0x190..+0x1A4 (draw/list counters), +0x578. Real-time counters (×1.00):
static 0x4291E4/0x4291E8 (60.1/s = vsync count), task +0x18C (vsync at last swap), 0x42C6B8 (83/s, likely the
sound frame clock), five 2.44/s counters (0x42ECAC, 0x42ED4C, 0x4301A8, 0x430244/48, 0x43451C; likely sound
streaming blocks). So logic tied to the step stays at wall-clock speed; nothing else ticks per frame here except
render bookkeeping. (confirmed)


Input mechanism (deviation from the brief, confirmed): the Azahar window's accessibility tree has no element for
the render surface, so `computer_press_key` refuses every key ("element 0 … did not take keyboard focus … no
keystrokes were sent"). Azahar feeds the emulated pad only from `GRenderWindow::keyPressEvent` (source
`src/citra_qt/bootmanager.cpp`). New `scripts/fps60/rt_input.py` posts `WM_KEYDOWN/WM_KEYUP` (and
`WM_LBUTTONDOWN/UP` for touch) to the test process's render child HWND (`Qt6111QWindowOwnDCIcon`) only, after
checking that exactly one azahar.exe runs, its PID is `rt_azahar.pid` and its image is
`tools/azahar-test/azahar.exe`. It takes neither the user's keyboard focus nor the mouse pointer. Verified: one
posted `A` moved the title to the file select.

### 6.2 Scene: file select (slot list; arrived from the title with the title task at +0x3D = 0)

| item | on arrival | after `setfps 0` |
|---|---|---|
| current task | **new object** 0x30000038 `load_menu::LoadMenuTask` → `msys::MTaskBase` → TaskBase (vptr 0x00491B60 in LoadMenu.rodata); CROs loaded: **LoadMenu, SaveLoad** (Field unloaded) | same object |
| +0x3C..+0x48 | `01 01 00 01 01 00 00 03 01 01 00 00 00` → **+0x3D = 1 again** (title's 0 not inherited), +0x41 = 0, +0x43 = 3 (uninitialised tail byte) | `01 00 00 01 01 00 00 03 01 00 00 00 00` |
| live TaskBase objects | 1 plausible (the current one). The scan also hits 4 words equal to LoadMenu vptrs inside the CRO image copy in the heap (0x0804FB88…, 0x0805CBB8; bytes +0x3C.. are ARM code) → flagged `plausible=false` | – |
| +0x578 frames/s | 29.54–29.96 | 59.64–59.88 |
| status bar | App 28–30 FPS | **App 57–60 FPS**, Speed 100%, Frame 2.8–3.3 ms |

Counters: same picture as the title (render counters ×2.0; vsync, sound-clock 83/s and the ~2/s stream counters
×1.0 within the ±1-count quantisation of a 2 s window). Menu logic step: `msys::MComSys::funcCalc` 0x32F40C
recomputes `MComSys+0xE6530 = isFps30 ? 2.0 : 1.0` and passes the same value to fn_32EEF8 every frame, so it
follows the live byte (code read; not sampled because the MComSys object address is not known).
Visible: slot cursor, slot-open animation and the 「시작하기/삭제/복사」 panel ran normally at 60.

Saves in the test instance (from the slot list): **slot 1** = M&L RPG3 file, 2026/01/25 13:16, Mario Lv40,
Luigi Lv40, Bowser Lv32 (late game), Bowser Jr. RPG = NEW GAME; **slot 2** = (not opened yet).


### 6.3 Scene: mode select (「마리오&루이지 RPG3 / 쿠파주니어 RPG / amiibo」, after 「시작하기」 on slot 1)

Same task as the file select: 0x30000038 `load_menu::LoadMenuTask`, still **+0x3D = 0** (set on the file select),
+0x578 59.88/s, App 60 FPS, ticker text 「다크쿠파가 저곳에! 드디어 최후의…」 scrolled smoothly. File select →
mode select is a page change inside LoadMenu, not a new task. (confirmed)

### 6.4 Scene: field, Bowser section (slot 1 loaded; Dark Bowser's castle area, room with a save block)

Arrived via 「마리오&루이지 RPG3」 with LoadMenuTask at +0x3D = 0.

| item | on arrival | after `setfps 0` |
|---|---|---|
| current task | **new task** 0x320DA370 `fld::System` (vptr 0x3E3B3C; same address as the title's, re-created); `[0x3F49B0+0x20]` = same pointer; CROs: Field | same |
| +0x3C..+0x48 | `01 01 00 01 01 00 00 00 01 01 00 00 00` → **+0x3D = 1** (menu's 0 not inherited) | `01 00 00 01 01 00 00 00 01 00 00 00 00` |
| live TaskBase objects | 1 (fld::System) | – |
| +0x578 frames/s | 29.96 | 59.91 |
| status bar | App 30 FPS, Speed 100% | **App 60 FPS** (field fade-in black screen at 30 before) |
| fld +0x1A4C / +0x1A50 / +0x1A48 | 2.0 / 2.0 / 1.0 | **1.0 / 1.0** / 1.0 (followed the flip: `+0x6E0` = 0x79CC007E, bit 0x40 set) |
| globals | `[0x3F3600]` btl = 0, `[0x3F61C0]` kj = 0, `[0x3F62A8]` MComSys = 0x300005C0 (**stale**: the freed LoadMenu MComSys, its +0xE6530 still reads 1.0), `[0x412C80]` = 2.0 (fast-forward factor source) | same |

**Logic speed (walking), confirmed equal.** Bowser's X position is the f32 at 0x30003BD8 (copies at 0x30003C0C,
0x30003E08; found by dump → walk right → dump → walk left → dump: 351.74 → 427.34 → 351.74). Posted circle-pad
holds of 400 ms (`walk.ps1`: `rt_census.py watchf` sampling at 30 Hz while `rt_input.py keys CLEFT:400`):

| mode | ΔX per 400 ms hold (3 runs) | per frame |
|---|---|---|
| 1 (30fps) | 50.4, 54.6, 50.4 | 4.2 = 12 or 13 frames × 4.2 |
| 0 (60fps, after the flip) | 53.55, 53.55, 51.45 | 2.1 = 24–26 frames × 2.1 |

Same distance per wall-clock time at both modes (±1 frame of input quantisation); the per-frame speed halves
exactly. A 600 ms hold at mode 1 gave 75.6 (= 18 frames × 4.2). A 1000 ms hold gave only 87.9 (Bowser stopped
at the platform edge). Nothing visibly wrong at 60 (camera follow, Bowser's walk animation, mini map).
Play-time counter: no steadily rising u32/f32 at ~1/s or ~60/s in static .data/.bss, the task's 64 KiB, the heap
or 4 MiB of linear heap around the task (`04_field_m1_wide_counters.json`); the game most likely derives play
time from the system clock at save time (guess). Field counters found are render/vsync/sound ones as in 6.1.


### 6.5 Scene: field pause menu (START in the field, field task at +0x3D = 0) and back (B)

Change log (`rt_census.py follow`, 20 Hz, started 0.5 s before the key; `census.jsonl` labels
`05_field_to_pause_follow`, `06_pause_to_field_follow`):

| t (s) | `[0x3F40B4]` | +0x3D/+0x45 | +0x578 | fld::System (`[0x3F49D0]`) +0x1A4C / +0x6E0 | MComSys `[0x3F62A8]` +0xE6530 |
|---|---|---|---|---|---|
| 0.0 (field, flipped) | 0x320DA370 fld::System | 0/0 | 19367 | 1.0 / 0x79CC007E | 0x300005C0 (stale, LoadMenu's) 1.0 |
| 0.99 | **0x00000000** (between tasks) | – | – | 1.0 / unchanged | same |
| 1.04 | **0x30000028 `main_menu::MainMenuTask`** (MainMenu.rodata vptr 0x004A0FAC; CROs MainMenu + MenuGuide) | **1/1** (new task) | 1 | 1.0 (field object kept, frozen) | **0x300005AC (new) 2.0** |
| menu, after `setfps 0` | same | 0/0 | 59.5–59.94/s | 1.0 | **1.0** |
| B pressed: 0.945 | **0x320DA370 fld::System (same object, resumed)** | **1/1** | 19426 (continues from where the field stopped) | 1.0 / 0x78CF007E | old object, 1.0 |
| 1.04 | same | 1/1 | 19426 | **2.0** / 0x78CF005E (bit 0x40 clear) | – |
| 1.84–2.08 | same | 1/1 | 19451→19458 (30/s) | 2.0 / 0x79CF005E → 0x79CF007E (bit 0x40 set again) | – |

Facts (confirmed): (1) the pause menu is a **separate task** (`main_menu::MainMenuTask`, new each time, created
with +0x3D = 1) while the `fld::System` object stays allocated and frozen (its +0x578 does not advance; RTTI scan in
the menu lists both: the menu current, the field with its +0x3D = 0 kept). (2) Leaving the menu re-activates
**the same** `fld::System` object, and its **+0x3D is back to 1**: something re-initialises the persistent byte on
resume (most likely `TaskBase::init` runs again on the existing object; to be confirmed with a breakpoint on
0x28068C in the next cycle). The field step is then recomputed to 2.0 by the field init. So a patch that decides at
`TaskBase::init` (D1) also covers the menu → field return; a one-shot runtime flip (the cheat) is lost on every
menu visit. (3) MComSys step follows the live byte (2.0 → 1.0 after the flip). Pause menu at mode 0: App 60 FPS,
+0x578 59.5–59.9/s, counters as in 6.1.

Display problem in this cycle (host-side, not the game): between 14:46 and 14:52 the test window moved
(origin 392,324 → 290,141, title-bar height 49 → 28 px = a different monitor DPI). From then on the render area is
black in every capture (accessibility screenshot, screen grab, `PrintWindow(PW_RENDERFULLCONTENT)`), in the menu
and after returning to the field, while the status bar keeps `App: 60/30 FPS`, Speed 100%, `Frame: 3 ms` and all
counters advance. The emulator is restarted to recover the picture (6.6).


**Confirmed by breakpoint** (`rt_gdb.py bp 0x28068C --count 3 --mem r1:0x38` while posting START, then B):
hit 1 = `TaskBase::init(this = 0x30000028 MainMenuTask, ip = sp 0x0FFFFEA8)`, lr 0x3346E8 (`MTaskBase::MTaskBase`),
InitParam +0x30..+0x34 = `01 01 00 01 01`; hit 2 (B) = `TaskBase::init(this = 0x320DA370 fld::System, ip = 0x0FFFFD18)`,
**lr 0x301640** (the field launcher's call at 0x30163C), InitParam +0x30..+0x34 = `01 01 00 01 01`. So the field
task object is re-initialised through `TaskBase::init` on every menu → field return; the D1 hook site
(0x28092C, inside `init`) runs on that path too. No third call within 25 s.


### 6.6 Relaunch, then scene: save menu (Bowser punches the save block; field at +0x3D = 0)

Relaunch (`rt_launch.ps1 -Stop`, then start, 14:58): picture back (title intro visible; the window now opens at the
moved position). `memmap.json` re-probed; `probe_map` now also checks the last page of a region (old-linear is
0x1BC00000–0x1BF32000, the rest unchanged). Slot 1 reloaded with no flips: fld::System 0x320DA370 again, +0x3D = 1,
step 2.0, 29.97/s. The room is in 「피치 성」 (per the save menu's map label).

| item | value |
|---|---|
| field → save menu (`CUP:150`, `X` = Bowser punch on the S block; `08_field_to_savemenu_follow`) | field +0x3D = 0 (flipped), step 1.0 until the task switch; `[0x3F40B4]` = 0 for one sample, then **new task 0x30000038 `save_menu::SaveMenuTask`** (SaveMenu.rodata vptr 0x0048858C; CROs SaveLoad + SaveMenu) with **+0x3D = 1**, +0x43 = 3; MComSys `[0x3F62A8]` = 0x300005C0, +0xE6530 = 2.0 |
| live TaskBase objects | 2: SaveMenuTask (current) + the frozen fld::System (keeps +0x3D = 0) |
| save menu after `setfps 0` | +0x578 59.88/s, MComSys step **1.0**; menu drawn normally (world map, 「피치 성」, ticker 「…이다! 준비하고 출발!」, slot panel, 「저장」 button) |
| save menu → field (B, nothing saved; `09_savemenu_to_field_follow`) | same fld::System object resumes with **+0x3D = 1** (re-init as in 6.5); +0x1A4C 1.0 for one sample, then **2.0** 47 ms later; +0x6E0 0x78CF006E → 0x78CF004E → 0x79CF00(4E/6E/7E) (low byte bit 0x40 stays set) |


### 6.7 Room change with the field at +0x3D = 0

Save room → left room at mode 1, then flipped (`10_room2_set0`) and walked back (`CRIGHT+CUP:1500`, chord support
added to `rt_input.py`; `11_room_change_m0_follow`): the map changed rooms, but **the same fld::System kept +0x3D = 0,
+0x578 kept counting (5912 → 6011) and +0x1A4C stayed 1.0**; `+0x6E0` only toggled low bits (0x79CA007E ↔ 006E).
A room change neither re-creates nor re-initialises the field task, so a flip survives room changes (it is lost on
menu/save-menu visits, 6.5/6.6). (confirmed)

Slot 2 of the test saves is empty (M&L RPG3 and Bowser Jr. RPG both 「NEW GAME」). No enemy was reachable around the
slot-1 save room in a few rooms of walking, so no field battle (`btl::Main`) was measured in this cycle (open).

### 6.8 Scene: Bowser Jr.'s Journey, new game on slot 2 (intro cutscene)

Path: file select → slot 2 → 「시작하기」 → mode select (LoadMenuTask flipped to +0x3D = 0, `12_modeselect_set0`) →
「쿠파주니어 RPG」 (`12_modeselect_to_kj_follow`):

| t (s) | `[0x3F40B4]` | +0x3D / +0x41 / +0x45 | notes |
|---|---|---|---|
| 0.0 | 0x30000038 LoadMenuTask | 0 / 0 / 0 | |
| 1.08 | 0 | – | |
| 1.13 | 0x30000028, vptr 0x004C7564 (a CRO task, not resolved: its CRO line was not yet in the log) | **1 / 0x51 / 1** | MComSys `[0x3F62A8]` → 0x300005AC, +0xE6530 = 2.0 |
| 1.22 | **0x320ABAC8 `fld::System`** (new address; CRO Field) | **1 / 0x5D / 1** | +0x1A4C 2.0, +0x1A48 2.0 → 1.0 in the next sample, +0x6E0 0xF800005E |

So the Bowser Jr. RPG new game starts with a **field-engine cutscene** (fld::System), not `kj::KJSystem`
(`[0x3F61C0]` stays 0 through the whole intro); every new task came back at mode 1. **+0x41 is not zero-initialised:**
the persistent tail bytes +0x41..+0x43 hold heap garbage (here `5D F2 5D`; on LoadMenuTask/SaveMenuTask +0x43 = 3), so
the D1 marker byte +0x41 must be written by the hook in both branches (or not be relied on as "0 = not promoted").

Fast-forward in the cutscene (hold R, the 「▷▷ R」 button; `13_kj_intro_ffwd_m1_follow` / `_m0_follow`):

| mode | +0x1A48 (ffwd) while R held | +0x1A4C while R held | after release |
|---|---|---|---|
| 1 | 2.0 (`[0x412C80]` = 2.0) | **4.0** | 2.0 |
| 0 (flipped) | 2.0 | **2.0** | 1.0 |

Matches `1dx_compare.md` §6 row 2 (step = fps factor × game speed × ffwd). Korean text in the intro rendered and
advanced normally at 60 (「크, 크, 큰일입니다! 쿠파님!」, 「포대에 굼바가 끼어서 발사가 안 됩니다―!」, 「나오거라롱롱!」).
`kj::KJSystem` itself was not reached within ~60 s of fast-forwarded intro (open).


### 6.9 Test-mods switcher `scripts/fps60/rt_mods.py` (smoke test passed, 15:18–15:20)

`status` / `use-patch` / `use-build TAG [--replace] [--empty-ok] [--ips]` (details in HARNESS §8). The mods entry
`user/load/mods/00040000001CA900` is always a junction: to `patch/00040000001CA900` or to a real folder
`tools/azahar-test/mods_builds/TAG/` (copy of the patch romfs + `work/fps60/build/TAG/romfs` overlay +
`exefs/code.bps`, manifest `mods_builds/TAG.json`). Links are removed with `os.rmdir` only; recursive delete only
for an old `mods_builds/TAG` after R5 assertions; it refuses to switch while azahar.exe runs.
Smoke run: stop → `use-build smoke --empty-ok` (36 files, no code) → boot → instance log has the 72
`LayeredFS replacement file in use for …` lines (incl. `/.crr/static.crr`, `/RO/MainMenu.cro`), Korean title logo
shown, title task +0x3D = 1 / 29.94/s → stop → `use-patch` → junction target `patch\00040000001CA900`, 36 files,
MainMenu.cro sha256 `1F227C75…BAFC` unchanged. (confirmed)

### 6.10 Preview of the lead's build `v1` (`use-build v1` → `exefs/code.bps`, D1 hook), no runtime writes

Log: `ncch_container.cpp:ApplyCodePatch:536: File …/load/mods/00040000001CA900/exefs/code.bps patching code.bin`
(Azahar applies the BPS from the mods folder of the base title ID).

| scene | current task, +0x3C..+0x48 | +0x578 / status bar | steps |
|---|---|---|---|
| title | fld::System `01 00 00 01 01 01 00 00 01 00 00 00 00` (**+0x3D 0, +0x41 1**) | 59.82–59.88/s, **App 60 FPS** | fld +0x1A4C 1.0 |
| file select | LoadMenuTask `01 00 00 01 01 01 00 03 01 00 …` (promoted) | 59.94/s | MComSys 1.0 |
| field (slot 1; `17_v1_modeselect_to_field_follow`) | new fld::System already **+0x3D 0 / +0x41 1 at ctr = 0** | App 60 FPS, Speed 100% | first sample (ctr 0, before field init) shows stale 2.0 / ffwd 2.0; at ctr 0 47 ms later **1.0**, and 1.0 in every later sample (R2: never 2.0 in a frame) |
| pause menu (`18_v1_pause_roundtrip_follow`) | MainMenuTask created with +0x3D 0 / +0x41 1 (ctr 2) | – | MComSys 1.0 |
| back to field | same fld::System re-initialised, **+0x3D stays 0**, +0x41 1 | – | **1.0 throughout** (unpatched: 2.0, §6.5) |

So the D1 hook promotes every task class seen (fld::System, LoadMenuTask/MainMenuTask via msys::MTaskBase) at
init, including the field re-init after a menu, which the runtime flip/cheat cannot do. (confirmed)

**Emulator crash (open, likely harness-side):** in the first v1 boot the test azahar.exe died with an access
violation (Windows Application log 15:21:56, `c0000005`, offset `0x13F79C3` inside azahar.exe, no guest-exception
line in the Azahar log) while `rt_census.py snap` was reading the static image, CRO segments and ~120 MB of heap
4 s after the title → file select change (log: Field unloaded, SaveLoad/LoadMenu loaded at 74.4 s; last line = the
snap's flush read at 78.5 s). Second v1 boot, same transition with no RPC traffic during it: no crash; the same snap
10 s later: no crash. The RPC server reads guest memory from its own thread without pausing emulation, so a heavy
scan racing the CRO unmap/map is the likely cause (guess). Rule added to HARNESS: no `snap`/`counters`/`dump` within
~10 s of a scene change (light `follow` reads were used through ~15 transitions without a crash).

### 6.11 Summary of answers to BRIEF2 RT2 items 1–3

- Task census (scenes reached): title = fld::System; file select + mode select = one LoadMenuTask; field =
  fld::System (same address 0x320DA370 each load); pause menu = MainMenuTask, save menu = SaveMenuTask, each with the
  frozen fld::System still alive; Bowser Jr. new game = a CRO task (vptr 0x004C7564) then a field-engine cutscene
  fld::System 0x320ABAC8. Never more than 2 plausible live TaskBase objects. Not reached: field battle (btl::Main),
  kj::KJSystem, shop.
- Mode 0 (runtime flip) in every scene reached: +0x578 → 59.5–59.9/s, App 57–60 FPS at Speed 100%, render counters
  ×2, vsync/sound clocks ×1, step floats 2.0 → 1.0 (field +0x1A4C, MComSys +0xE6530; ffwd ×2 preserved), Bowser's
  walking distance per wall-clock second unchanged. Nothing visibly wrong in text, camera, map, menus.
- Scene changes: every scene change that creates a task gives +0x3D = 1 again (title→file select, mode select→field,
  field→menu, menu→field **(same object, re-`init`)**, mode select→Bowser Jr.); file select→mode select (same task) and
  room changes keep the flip. Hence the patch must act in `TaskBase::init` (D1), as `v1` does (§6.10).


## 7. Wave 3 (RT3): credits R1–R4, Old 3DS, transition soak, BAI load, RW latch region (2026-10-30, from 15:45)

Worker RT3. Same instance and rules (HARNESS §1–§8). Builds used: `v1` (D1 hook, code.bps sha256 `f0983fa1…`),
`v1cb` (v1c code = D1 + credits fix, code.bps `ec4189b9…c0c6`, + BAI fix `romfs/BAI/BAI.dat` `c681a963…fbb6`).
Backups made before any change (test instance only): `tools/azahar-test/rt3_backup/save/ML3R_00{0,1,2}.sav`
(sha256 `1F1CF4F6…`, `43C2CA72…`, `659AB0D2…`) and `rt3_backup/qt-config.ini` (`D35ED324…`), list in
`rt3_backup/SHA256.txt`.
New tool: `scripts/fps60/rt_credits.py` (`follow` = 4 Hz light RPC log of the current task, fld::System
+0x3D/+0x41/+0x45/+0x578/+0x1A4C/+0x6E0, StaffrollCtrl `[fld+0x1B3C]` +0x14 frame/+0x18/+0x1C/+0x24 total/+0x28 speed,
`[0x415E38]` P0/P4 and RT2's real-time/sound counter words; `--flip` = cheat-equivalent GDB write of +0x3D = 0 on the
loaded field task; `summary` = roll start / isFinish / ctrl delete times, updates/s, counter start/stop runs, freezes).
Raw logs: `work/fps60/runtime/rt3/<label>.jsonl` + `<label>_summary.json`.

### 7.1 Credits test bed A (save redirect) fails at the field start, also on the stock game (confirmed, 15:41–15:47)

Stock patch (junction), New 3DS, test bed A installed (`ML3R_001.sav` = CRD's `save_credits` copy, sha256 `289EBB57…`).
Title (fld::System `01 01 00 01 01 00 00 00 01 01 …`, 29.94/s) → file select → slot 1 → 「시작하기」 → mode select →
「마리오&루이지 RPG3」 at 15:43:59 (monitor `R1_stock`). Field CRO loaded at log 156.0 s; **1.0 s later the guest reads
through NULL and then writes through a wild pointer** (instance log, 830,000 `HW.Memory <Error> UnmappedAccess` lines in
~5 s, log 100 MB):

| first PCs (log 157.003 s) | function (decomp index) | access |
|---|---|---|
| 0x00100726, 0x0022C02C, 0x0026D708 | FUN_00100726, FUN_0022BFE8+0x44, FUN_0026D6A8+0x60 | Read8/Read32 @ 0x00000000..0x28 |
| 0x00251ECC | `ad::fw::TaskBase::readArcFile`+0x40 | Read32 @ 0x00000000..0x18 (archive entry pointer NULL) |
| then 0x0022A0FC (119k), 0x0036E4AC (69k), 0x002A789C, 0x0022A1B0, 0x0022A17C, 0x00260378 `ad::h3d::Model::Model` | FUN_0022A0E4+0x18, FUN_0036E288+0x224, … | Write8/16/32 @ 0xD688BCxx (unmapped) |

Effect in the emulator: `Speed: 0%`, `App: 0 FPS`, fld::System +0x578 advanced 31 → 32 in 10 s, vsync word 0x4291E4 1 per
5 s (the emulator thread is busy logging the faults); StaffrollCtrl never created (`[fld+0x1B3C]` = 0). Threads at the
stall: main pc 0x279BBC (lr 0x2849C4), thread 4 pc 0x279BBC (lr 0x121374, sp 0x3213B328), thread 5 pc 0x12E41C. On a real
console this is a data abort. **Cause: the test bed, not the frame rate** (stock 30fps, no code patch): loading a save
whose room block names the credits rooms (0x2C2/0x2C1) skips resources the story path provides, so a model/archive
pointer is NULL (`readArcFile` from NULL, then `ad::h3d::Model::Model` on garbage). Variant A is unusable; the credits
runs use **variant B** (FEvent room warp from the saved rooms, CRD §6) from here on. Emulator stopped; save restored
from `rt3_backup` before the next run. (for CRD/TB: do not use a save redirect into the staff-roll rooms)

### 7.2 R1 — stock credits (no code patch), test bed B (confirmed, 15:47–15:55)

Install: `rt_mods.py use-build r3stock --empty-ok` (copy of the patch romfs, 36 files, no exefs), then
`work/fps60/credits/testbed/romfs/FEvent/FEvent.dat` (sha256 `872427F6…A52C`) copied into
`tools/azahar-test/mods_builds/r3stock/romfs/FEvent/` (junction target asserted first); original slot-1 save.
Log: `LayeredFS replacement file in use for /FEvent/FEvent.dat`, no `ApplyCodePatch`. Path: title (29.94/s) → slot 1 →
「시작하기」 → mode select → 「마리오&루이지 RPG3」; the saved rooms' default scripts warp straight into
`zi_areanone_staffroll_01_U/L`. Monitor `R1_stockB` (t = 0 at 15:48:27, on the mode select):

| event | t (s) | wall | value |
|---|---|---|---|
| field task appears (`[0x3F40B4]` LoadMenuTask → fld::System 0x320DA370) | 2.25 | 15:48:29 | +0x3D 1 / +0x41 0 / +0x45 1, step +0x1A4C 2.0 |
| `staffroll(0)`: ctrl `[fld+0x1B3C]` = 0x30724300 | 5.76 | 15:48:32 | count 416, total 12312.0, speed 2.0, P0/P4 = 1/1 |
| first `update()` (fit of frame vs t) | 17.33 | | |
| isFinish: frame 6157 (6157 × 2.0 = 12314 > 12312) | 223.12 | 15:52:10 | **29.91 updates/s, roll 205.8 s** |
| `staffroll(3)`: ctrl → 0 (fade-out done, room change follows) | 239.77 | 15:52:26 | 16.6 s after isFinish (= wait(0x2D0) 12 s + fade) |
| next room `o_koopa_end_01`: Kamek 「쿠파님~ 기분은 어떠신가요~?」, waits for A | | 15:52:40 | game normal |

Throughout: fld +0x578 29.8–29.9/s in every 10-s window, status bar `Speed: 100% / 100%`, `App: 30 FPS`, `Frame: 1.76 ms`;
`fld+0x6E0` = 0x7900006E during the roll (**bit 0x40 set**, so the field step is recomputed per frame, CRD H2 premise
holds); no freeze, no `UnmappedAccess`, save not written (sha256 unchanged `43C2CA72…`). Picture: staff text over the
slideshow pictures (screenshot checked). Watch words 0x42ECAC / 0x42ED4C rose 2.0/s from the room load to t = 240.5 s
(room-scoped timers, **not** a BGM marker). Music markers found afterwards (used from R2 on): `SndSys` is static
**0x3FBF9C** (`u32[[fld+0xA08]]`); `+0` / `+4` = BGM slot 0/1 `SoundHandle` (BasicSound* or 0, same layout as
`SndSys::stopAllBgm` 0x33C450); the field keeps per-slot state at fld+0xA0C (u8 playing, set by op228 play) /
+0xA10 (sound id; slot 0 = **0x0100032C** = `04_end_roll` after the credits). After the credits both handles read 0.
R1's music start, by the script (571 frames before the first update = 9.52 s): t ≈ 7.8 s → 214-s stream ends t ≈ 221.8 s,
text ends 223.1 s: **text end − music end ≈ +1.3 s** (CRD model +0.8 s).

### 7.3 R2 — stock code + cheat-equivalent runtime flip, test bed B (confirmed, 15:56–16:04)

Same mods copy as R1. Monitor `R2_flipB --flip` started on the mode select; the first sample that saw the loaded field task
(t = 2.25 s, `fld::System` +0x3D = 1, step 2.0) wrote **+0x3D = 0 through GDB** (before 1 → after 0); +0x45 followed in the
next sample (t = 2.50 s), step +0x1A4C 2.0 → 1.0.

| event | t (s) | wall | value |
|---|---|---|---|
| flip | 2.25 | 15:58:29 | `{"before":1,"after":0}` |
| ctrl created | 4.76 | 15:58:31 | count 416, total 12312.0, speed **2.0**, P0/P4 1/1 |
| BGM play: fld+0xA0C = 1, id 0x0100032C, handle `[0x3FBF9C]` = 0x322122D8 | 6.76 | 15:58:33 | |
| first update | 16.15 | | 9.39 s after the play |
| isFinish (frame 6157) | 119.06 | 16:00:25 | **59.82 updates/s, roll 102.9 s**; last page 「©2009-2018 Nintendo / Developed by ALPHADREAM …」 then stays still (screenshot) |
| BGM handle detached (stream finished) | 220.76 | 16:02:07 | **214.0 s after the play** (= the 214-s `04_end_roll`) |
| ctrl deleted, both BGM handles 0, field BGM flags 0 | 238.03 | 16:02:24 | 231.3 s after the play (R1: ≈ 231.9 s; slideshow-driven) |
| `o_koopa_end_01`: 「쿠파님~ 기분은 어떠신가요~?」, 5 × A → 「배달입니다~ 배달입니다~!」 | | 16:02:46–16:03:21 | runs at 60 (field still +0x3D 0, step 1.0) |

**Text end − music end = −101.7 s** (text finishes 1 min 42 s before the music; the frozen last page is shown that long).
fld +0x578 59.2–59.9/s in every 10-s window, `App: 60 FPS`, `Speed: 100% / 100%`, `Frame: 3.27 ms`; `fld+0x6E0` = 0x7900006E
(bit 0x40 set → step followed the flip; H2's "stale step" case does not occur); no freeze, no `UnmappedAccess`, save
unchanged. No crash on Azahar with the cheat-equivalent flip.
Correction for R1 with the measured offset (first update = play + 9.39 s): R1 music 7.94 → 221.94 s, text end 223.12 s
→ **R1 text end − music end = +1.2 s**.

### 7.4 R3 — build `v1` (D1 hook, no credits fix), test bed B (confirmed, 16:05–16:12)

`rt_mods.py use-build v1 --replace` (37 files, `exefs/code.bps` sha256 `F0983FA1…3356` = `work/fps60/build/v1/code.bps`) + the
test-bed FEvent.dat. Log: `ApplyCodePatch:536: File …/exefs/code.bps patching code.bin`, FEvent LayeredFS line. Title task
already promoted (`01 00 00 01 01 01 00 00 01 00 …`, 59.88/s), LoadMenuTask too (+0x3D 0 / +0x41 1). Monitor `R3_v1B`:

| event | t (s) | wall | value |
|---|---|---|---|
| field task appears | 2.25 | 16:06:40 | **+0x3D 0 / +0x41 1 / +0x45 0 at fctr = 5, step 1.0** (no runtime write) |
| ctrl created | 4.51 | 16:06:42 | count 416, total 12312.0, speed 2.0, P0/P4 1/1 |
| BGM play (slot 0, 0x0100032C) | 6.51 | 16:06:44 | |
| first update | 15.98 | | play + 9.47 s |
| isFinish (frame 6157) | 118.88 | 16:08:36 | **59.83 updates/s, roll 102.9 s** |
| BGM handle detached | 220.76 | 16:10:19 | stream 214.25 s |
| ctrl deleted / room change | 238.03 | 16:10:36 | then `o_koopa_end_01` dialog (screenshot) |

**Text end − music end = −101.9 s** (same as R2). fld +0x578 59.7–59.9/s, `App: 60 FPS`, `Speed: 100% / 100%`,
`Frame: 3.17 ms`, `fld+0x6E0` 0x7900006E, no freeze, no `UnmappedAccess`, save unchanged.

### 7.5 R4 — build `v1cb` (D1 + credits fix + BAI fix), test bed B (confirmed, 16:12–16:22)

`rt_mods.py use-build v1cb` (38 files: patch copy + `romfs/BAI/BAI.dat` `C681A963…FBB6` + `exefs/code.bps` `EC4189B9…C0C6`) +
the test-bed FEvent.dat. Log: `ApplyCodePatch … code.bps patching code.bin`, `LayeredFS replacement file in use for
/BAI/BAI.dat` and `/FEvent/FEvent.dat`. Monitor `R4_v1cbB`:

| event | t (s) | wall | value |
|---|---|---|---|
| field task appears | 2.25 | 16:13:38 | +0x3D 0 / +0x41 1 / +0x45 0, step 1.0 |
| ctrl created | 4.51 | 16:13:41 | **speed `ctrl+0x28` = 1.0** (crd60_fix), count 416, total 12312.0, P0/P4 1/1 (v1c has no fade tweak) |
| BGM play | 6.51 | 16:13:43 | |
| first update | 15.96 | | play + 9.45 s |
| isFinish: frame **12313** (12313 × 1.0 > 12312) | 221.76 | 16:17:17 | **59.83 updates/s, roll 205.8 s** (R1: 205.79 s) |
| BGM handle detached | 220.50 | 16:17:17 | stream 213.99 s |
| ctrl deleted / room change | 237.77 | 16:17:34 | |
| ending scene in `o_koopa_end_01`, ~45 pages advanced (A, then R+A fast-forward) up to 「너희들도다! 당장 쿠파 성을 고쳐라!!」 | | 16:17:50–16:22 | fld::System +0x3D 0 / +0x41 1, 59.88–59.94/s |

**Text end − music end = +1.26 s** (R1 stock 30fps: +1.2 s). fld +0x578 59.7–59.9/s, `App: 60 FPS`, `Speed: 100% / 100%`,
`Frame: 3.16 ms`, no freeze, no `UnmappedAccess`, save unchanged.

### 7.6 Credits R1–R4 compared (Azahar, New 3DS mode; all four ran past the credits into the ending scene)

| run | code | fps set by | ctrl speed | updates/s | roll (first update → isFinish) | text end − music end | room change after play | crash / freeze |
|---|---|---|---|---|---|---|---|---|
| R1 | stock | — | 2.0 | 29.91 | 205.8 s | **+1.2 s** | ≈ 231.9 s | none |
| R2 | stock | GDB flip at the first field frame (cheat) | 2.0 | 59.82 | 102.9 s | **−101.7 s** | 231.3 s | none |
| R3 | `v1` | D1 at init | 2.0 | 59.83 | 102.9 s | **−101.9 s** | 231.5 s | none |
| R4 | `v1cb` | D1 at init | **1.0** | 59.83 | **205.8 s** | **+1.26 s** | 231.3 s | none |

Facts: (1) the roll is the only frame-counted part: unfixed 60fps halves it and leaves the last page frozen ≈ 102 s;
the slideshow, BGM (214.0 s measured from the SoundHandle) and the room change keep wall-clock time at both rates
(CRD §2–§3 confirmed). (2) The credits fix restores the 30fps timing exactly (205.8 s, text ends 1.3 s after the music,
like stock). (3) **No crash, freeze or guest fault in any credits run on Azahar**, including the cheat-equivalent flip;
`fld+0x6E0` bit 0x40 stays set during the roll (H2's stale-step premise does not occur). So the community's "credits crash
without fail" is not reproduced in the emulator; CRD H1 (hardware frame budget) remains the open explanation and needs a
New 3DS run of `v1cb` (lead). Stock 30fps frame time 1.76 ms vs 60fps 3.16–3.27 ms (host time, not a hardware budget).

### 7.7 Old 3DS check with `v1cb` (confirmed, 16:22–16:27)

`rt_mods.py use-build v1cb --replace` (clean: patch copy + BAI fix + code.bps, no test bed; 38 files). TEST config only:
`is_new_3ds\default=false`, `is_new_3ds=false` (pre-edit copy `tools/azahar-test/rt3_backup/qt-config.pre_o3ds.ini`).
Log: `Config <Info> … System_IsNew3ds: false`, `ApplyCodePatch … code.bps patching code.bin`, BAI LayeredFS line.

| scene | current task, +0x3C..+0x48 | +0x578 | status bar | New-3DS bytes |
|---|---|---|---|---|
| title | fld::System 0x320DA370 `01 01 00 01 01 00 00 00 01 01 00 00 00` (**+0x3D 1, +0x41 0, +0x45 1**) | 29.94/s | `App: 30 FPS`, Speed 100%, Frame 2.01 ms | `[0x3F716C]` IsRunOnSnake cache **0**, APPMEMTYPE `[0x1FF80030]` **0** |
| mode select | LoadMenuTask `01 01 00 01 01 00 00 03 01 01 …` (+0x3D 1, +0x41 0) | 29.94/s | | |
| field (slot 1) | fld::System `01 01 00 01 01 00 00 00 01 01 …`; from its first sample +0x3D 1 / +0x41 0, **step +0x1A4C 2.0** | 29.96/s (29.8–29.9 per 10 s) | `App: 30 FPS`, Speed 100%, Frame 1.52 ms | 0 / 0 |
| pause menu (START) | MainMenuTask 0x30000028 `01 01 00 01 01 00 00 00 01 01 …` | 29.94/s | | |
| back to field (B) | fld::System re-init, +0x3D 1 / +0x41 0 | 29.97/s | | |

So on an Old 3DS the D1 hook leaves every task at 30fps and the marker 0 (`IsRunOnSnake` = 0), as designed. No guest fault.
Config restored afterwards: both lines back to `true` (only the two `is_new_3ds` lines were edited); the file is byte-identical
to the 15:45 backup again (sha256 `D35ED324…B605`).

### 7.8 RW latch region 0x434D40–0x435000 for IMPL3 (confirmed; `latch_reads.jsonl` in `work/fps60/runtime/rt3/`)

RPC read of 0x434D40–0x436000 (content) + GDB `m` probes (mapped = data reply, unmapped = empty reply):

| when | build | current task | non-zero bytes in 0x434D40–0x435FFF | GDB `m` 0x434D40 / 0x434FFC / 0x435000 / 0x435FFC / 0x436000 |
|---|---|---|---|---|
| title 15:42 | stock | fld::System | 0 | mapped / mapped / mapped / mapped / **unmapped** |
| title 16:27 | v1cb | fld::System (+0x3D 0, +0x41 1) | 0 | same |
| field 16:36 | v1cb | fld::System, after 24 soak transitions | 0 | same |
| pause menu 16:36 | v1cb | main_menu::MainMenuTask | 0 | same |

The last .bss word **0x434D3C = 0x000000FF** (in use; the latch must not start below 0x434D40). In Azahar the image is
mapped to 0x436000 because the loader appends the bss pages to the decompressed code (0x2F9000 + 0x3D000, IMPL README
§4), so **0x435000–0x435FFF is an emulator-only page**: on hardware the data+bss segment is 0x46 pages from 0x3EF000
(data 0x9170 + bss 0x3CBD0 = 0x45D40) and ends at 0x435000 (likely; not observable here). A latch inside
0x434D40–0x434FFF (0x2C0 bytes) is mapped and zero in every scene measured.

### 7.9 Transition soak with `v1cb` (New 3DS; confirmed, 16:26–16:52)

No heap/task scans, no counters/dumps; only the 4 Hz light log (`SOAK_v1cb`, `SOAK2_v1cb`, `SOAK3_v1cb` in `rt3/`) and the
two latch reads of §7.8. Keys via `rt_input.py`, screenshots by desktop grab after each step (scratch `soak_*.png`).

| # | transitions | new / re-initialised task at arrival (+0x3D / +0x41 / +0x45) |
|---|---|---|
| boot 1 | T1 title → file select; T2 → mode select; T3 → field (slot 1, 「피치 성」 save hall) | LoadMenuTask 0x30000038 (0/1/0); fld::System 0x320DA370 (0/1/0) |
| | T4–T9 field ↔ pause menu ×3 | MainMenuTask 0x30000028 vptr 0x4A0FAC (0/1/0) each time; fld::System re-init (0/1/0) each return |
| | T10–T13 field ↔ save menu ×2 (X = Bowser punches the S block; B) | SaveMenuTask 0x30000038 vptr 0x48858C (0/1/0); field re-init (0/1/0) |
| | T14–T18 room changes: save hall → left corridor → star room → stair room → star room → right corridor | same fld::System, never re-initialised (as RT2 §6.7) |
| | T19–T26 field ↔ pause ×4 (T19 was an L+R+START+SELECT chord: no soft reset in this game, START opened the menu) | as above |
| boot 2 | T27 title → file select; T28 → mode select; T29 → 「쿠파주니어 RPG」 (slot 1 NEW GAME) | CRO task 0x30000028 vptr **0x4C7564** (0/1/0), then KJ intro fld::System **0x320ABAC8** (0/1/0, tail +0x42/+0x43 = `f2 5d`), 59.88/s |
| boot 3 | T30 title → file select; T31 → mode select; T32 → field; T33–T37 room changes: hall → left corridor → star room → stair room → throne hall (red route) → statue room | as boot 1 |

Result: **37 scene transitions, no freeze, no crash, no `UnmappedAccess` / `<Critical>` line** (the only `<Error>` lines are the
known ClCertA/shared-font/delay-generator ones and the GDB socket close of the latch reads). Every task created or
re-initialised came up promoted (+0x3D 0, +0x41 1), +0x578 ≈ 59.8/s whenever a field was current. Not done: the way back
from Bowser Jr.'s Journey to the mode select — the KJ new-game intro has no menu (START advances the text) and
~110 s of R+A fast-forward did not reach `kj::KJSystem` (`[0x3F61C0]` stayed 0); the emulator was restarted instead
(two KJ entries in total counting RT2's).

### 7.10 BAI load / battle (not reached; confirmed what could be)

Every `v1cb` boot logs `LayeredFS replacement file in use for /BAI/BAI.dat` (sha256 of the copy in the mods folder
`C681A963…FBB6` = the staged fix), so the layered RomFS serves the fixed file. A field battle was **not** reached from
slot 1 within the time box (~10 min this cycle, after RT2's earlier search): walked the slot-1 area of the final dungeon
(save hall, both corridors, star room, stair room, throne hall with the sealed door, statue room); no roaming enemy
appeared, and the corridors' orange routes are blocked. So `btl::Main` +0x3D/+0x41 and `[0x3F3600]+0xBA15C` at
runtime remain open for TB's battle test bed (T1). Not attempted: the red route's sealed door (likely the final-boss
event chain).

### 7.11 RT3 summary and final state (16:55)

- Credits (§7.2–§7.6): R1 stock 205.8 s roll, text ends 1.2 s after the 214.0-s BGM; R2 (cheat-equivalent flip) and R3
  (`v1`) 102.9 s, text ends ≈ 102 s before the music, last page frozen; R4 (`v1cb`) 205.8 s, +1.26 s, i.e. the fix restores
  the stock timing exactly. **No crash/freeze in any run on Azahar**; the community crash is not reproduced → hardware run of
  `v1cb` needed (CRD H1). Test bed A (save redirect) faults the stock game at field start (§7.1): use test bed B.
- Old 3DS (§7.7): `v1cb` keeps title / mode select / field / pause menu at +0x3D 1, +0x41 0, 30 FPS; IsRunOnSnake cache 0.
- Soak (§7.9): 37 transitions with `v1cb`, every task promoted at init, no freeze/crash. KJ → mode select path not reachable
  from the new-game intro.
- BAI (§7.10): the fixed BAI.dat is served (LayeredFS line); no battle reached from slot 1 (open, TB test bed).
- RW latch (§7.8): 0x434D40–0x434FFF mapped and zero at title, field and menu; 0x434D3C = 0xFF is live .bss; 0x435000–0x435FFF
  exists only in Azahar.
- Final state: `rt_mods.py use-patch` → junction `patch\00040000001CA900`, 36 files, MainMenu.cro sha256 `1F227C75…BAFC`;
  test saves equal the 15:45 backup (`43C2CA72…` etc.); TEST config equal to the backup (`D35ED324…`, `is_new_3ds=true`);
  emulator stopped, no monitor running. `mods_builds/{v1,v1cb,r3stock,smoke}` remain as plain build copies (the test-bed
  FEvent.dat copies were removed from `v1` and `r3stock`; `v1cb` was rebuilt clean before the Old-3DS run).


## 8. Wave 4 (RT4): runtime decision A (`v2`) vs B (`v2b`), final checks (2026-10-30, from 17:10)

Worker RT4. Same instance and rules (HARNESS §1–§9). Builds (sha256 of `code.bps` as installed by `rt_mods.py use-build`):
`v2` = Option A (D1 + field VM 30 Hz F1–F4 + BAI fix; `code.bps` `C3922B9D…5BE2`, `romfs/BAI/BAI.dat` `C681A963…FBB6`),
`v2n` = control (D1 + credits fix + BAI fix; `code.bps` `EC4189B9…C0C6` = `v1c`), `v2b` = Option B (`v2n` code + BAI fix +
FEV `romfs/FEvent/FEvent.dat` `2E117581…5E72`). Backups before any change (test instance only):
`tools/azahar-test/rt4_backup/save/ML3R_00{0,1,2}.sav` (`1F1CF4F6…`, `43C2CA72…`, `659AB0D2…`) and `rt4_backup/qt-config.ini`
(`D35ED324…B605`), list in `rt4_backup/SHA256.txt`; start state = junction to `patch\00040000001CA900`, 36 files, MainMenu.cro
`1F227C75…BAFC`, emulator stopped. New tool: `scripts/fps60/rt_watch4.py` (`follow` = every-sample 20 Hz RPC log of the current
task, `fld::System`, `btl::Main` fps bytes/steps/badge words and the F4 latch 0x434F00..0x434F0F, plus extra probes, into
`work/fps60/runtime/rt4/<label>.jsonl`; `grab` / `burst` / `sheet` = desktop grabs of the test window's render surface with
key events on the same clock). Each item: build tag, test bed, scene, measured, expected, PASS/FAIL.

### 8.1 Item 1 — T1 ordinary battle with `v2` (confirmed, 17:00–17:26)

Install: `rt_mods.py use-build v2` (38 files: patch copy + `romfs/BAI/BAI.dat` `C681A963…FBB6` + `exefs/code.bps` `C3922B9D…5BE2`), then
`tb_build.py install t1_battle --tag v2` (`romfs/FEvent/FEvent.dat` `41131313…2C74`). Log: `System_IsNew3ds: true`,
`ApplyCodePatch:536: File …/exefs/code.bps patching code.bin`, `LayeredFS replacement file in use for /BAI/BAI.dat` and
`/FEvent/FEvent.dat`. Path: title → file select → slot 1 → 「시작하기」 → 「마리오&루이지 RPG3」 → field (Bowser in the save room, map
on the lower screen) → **A** (switch to Mario & Luigi): the lower room `i_tainai_01` runs its wrapped entry and the battle starts
≈4 s later (TB §5 expected "≈1 s after the lower field fades in"; the lower field only runs once the bros are selected).
Battle = Mario & Luigi vs two 「쥬시 LV8」 (scn_meta_05). Logs `work/fps60/runtime/rt4/T1v2_{a,b,c}.jsonl` (20 Hz).

| quantity | measured (`v2`) | expected | result |
|---|---|---|---|
| BAI.dat / FEvent.dat replacement | both LayeredFS lines in every boot | present | PASS |
| btl::Main `[0x3F3600]` = 0x30000008, vptr 0x3E10C4 | **+0x3D 0 / +0x41 1 / +0x45 0 from its first sample (ctr 0)**, current task | 0 / 1 / 0 | PASS |
| `Main+0xBA15C` ($7012) / `Main+0x8A3C` / `[[Main+0x574]+0x7C]` | **1.0 / 1.0 / 1.0** in every sample of 3 battles | 1.0 / 1.0 / 1.0 | PASS |
| btl::Main +0x578 | 59.8–59.9 per s | ≈60 | PASS |
| Mario jump, A pressed (see method) | `$707d` = **3**, 「**GOOD!**」 shown, 331 damage + bonus bounce (no press: 269 / 248 damage, no rating) | success | PASS |
| Luigi jump, B pressed | `$707d` = **3**, 「**GOOD!**」, 300 damage (no press: 225) | success | PASS |
| battle end → field | result screen (EXP +60 each, coins +24 applied: pause menu shows 52904 = 52880 + 24) → **same fld::System 0x320DA370 current, +0x3D 0 / +0x41 1 / +0x45 0, step +0x1A4C 1.0**, +0x578 59.8/s | +0x3D 0 | PASS |
| second battle | none (wrapper ends with `return`) | none | PASS |

Judgement read-out (method, confirmed): the battle AI attack registers `$706C..$70AB` are floats at `AISys+0x120+4·(id−0x706C)`
(Battle.cro sysvar read/write, decomp Battle.c lines 53242/53845: `param_2 + 0x120`); the live `btl::AISys` (RTTI scan, the one with
+0x18 = btl::Main) is **0x305CC624** in every boot, pointer at **`btl::Main+0xBA148`**. `atk_pc_solo_jump.bai` sets `$707C` (=35.0,
the expected contact in 60 Hz units after its window timer `op1d6` starts) and writes the judgement into `$707D` (`$8016`/`$8017` =
3/2 for the first table set, 5/4 for the second, 1 = fail/timeout). New `rt_watch4.py react` polls `$707C` by RPC, presses the button
`35/60 s` after it turns non-zero, and logs `$707D`: Mario `A` 583.8 ms after the trigger → `$707D` 3.0 within the press frame; Luigi
`B` 563.9 ms → 3.0. Without a press (first two battles) `$707D` went 0 → 1 (timeout) ≈ 45 units after the trigger and the hit did
269/248 (Mario) and 225 (Luigi) damage with no rating text. Frames: scratch bursts `bj5`, `bj6` (desktop grabs, 33 ms).
After each success `$707D` returned to 0 and later to 1: the second (bonus) jump has its own window that was not pressed.

Test-bed artefact (not a 60fps issue, likely): after the battle the field is current and running but **both screens stay black**
until the pause menu is opened and closed (then the room is drawn normally). The T1 wrapper ends with `return` right after
`op240`; the story scripts that own these battle starts continue after `op240` (TB §6 item 3) and presumably fade the screen in
themselves. Not checked at 30fps.

### 8.2 Item 2 — T2 hold attack (`t2_hold`) with `v2` and the nofix control (17:27–)

Install (`v2`): `tb_build.py remove t1_battle --tag v2`, then `tb_build.py install t2_hold --tag v2` (`romfs/BAI/BAI.dat`
`9EA3E473…E04467` = BAI fix + test-bed rotation, `romfs/FEvent/FEvent.dat` `2D5B0A3B…84219B`). Log: code.bps patch line and both
LayeredFS lines. Same path as §8.1; battle = Mario & Luigi vs Dark Star (scn_air_boss), log `rt4/T2v2_a.jsonl`.

Method: `rt_watch4.py hold` polls `$707C..$707F` (`AISys+0x160..0x16C`). It waits for the `atk_dstar_4` trigger (`$707C` ∈
{144,160,172}), optionally watches `--watch` ms, taps A+B (250 ms down / 60 ms up) until `$707E` (bros hanging) = 2, holds A+B for
`--before` ms, releases both for `--gap` ms, then holds again until `$707D` = 3 (+1 s). The grace loop at 0x3421 adds 2 to `$8012`
per pass while released and drops the bro at ≥ 16: 8 passes = 267 ms with the fix (`wait(2)`), 133 ms without it. Orbit lap:
`rt_watch4.py sample` read `0x30000000+0xC0000`, `0x302E0000+0x80000` and `0x305C0000+0x20000` at 10 Hz from the trigger; the orbit
window is the samples with `$707E` < 2 (0–4.9 s, 50 samples). The orbiting star is btl::Obj #9 (array 0x302E63EC, stride 0xCFC):
`+0x1C0` = x (amplitude 60.2 = the script's `cos·60`), `+0x1C8` = y (amplitude 27.5). Period = least-squares sine fit against
`btl::Main+0x578` (59.8 per s in that window). The script's `$8013` angle itself is not in these ranges.

| run (`v2`) | measured | expected | result |
|---|---|---|---|
| btl::Main +0x3D / +0x41, steps BA15C / 8A3C / `[[+0x574]+0x7C]` | 0 / 1, 1.0 / 1.0 / 1.0 (whole battle) | 0 / 1, 1.0 | PASS |
| jumps in this battle (`react`) | Mario A → `$707D` 3, Luigi B → 3 | success | PASS |
| h1: release 200.8 ms (A+B up 9.809 s, down 10.010 s) | `$707E` stays **2**; `$707D` 1 (11.29) → 2 (11.60) → 3 (14.01) | kept (grace 267 ms) | PASS |
| h2: release 100.3 ms | `$707E` stays 2; `$707D` 1 (7.37) → 2 (7.70) → 3 (10.10) | kept | PASS |
| h3: watch 4 s, release 101 ms | `$707E` 1 at 5.01 s, 2 at 5.75 s, stays 2; `$707D` → 3 at 10.15 s | kept | PASS |
| orbit lap (h3, star x / y) | **98.25 / 97.7 frames = 1.643 / 1.634 s** (rms 2.4 / 0.66) | 2·360/7.4 = 97.3 frames ≈ 1.62 s | PASS |


Control: `tb_build.py remove t2_hold --tag v2`, then `tb_build.py install t2_hold --tag v2 --variant nofix` (`BAI.dat`
`1EE8BD60…EBFFF77` = the same test-bed rotation without the BAI fix; the code stays `v2`, so only the BAI timing differs). Log
`rt4/T2nf_a.jsonl`; orbit sampled at 20 Hz (`0x30000000+0x600`, `0x302E0000+0x80000`), star at the same addresses.

| run (`v2` code + nofix BAI) | measured | expected | result |
|---|---|---|---|
| h1n: watch 4 s, release 200 ms (A+B up 11.278 s, down 11.478 s) | `$707E` 2 → **0 at 11.428 s** (150 ms after the release, both bros fell); `$707D` 1 → 2 → 3 (14.02 s) | fall (grace 133 ms) | as expected |
| h2n: release 100.5 ms | `$707E` stays 2; `$707D` 1 (7.41) → 2 (7.74) → 3 (10.15) | kept | as expected |
| orbit lap (h1n, star visible from 0.45 s to the grab at 5.53 s) | **48.65 frames = 0.813 s** (x amplitude 60.0, rms 0.61; y the same) | 360/7.4 = 48.65 frames ≈ 0.81 s | as expected |

Item 2 result: **PASS**. With the BAI fix the orbit lap is 2.02× the nofix lap (98.25 vs 48.65 frames) and a 200 ms release is
survived only with the fix; 100 ms is survived in both, so the test tells the two apart.

RT4 stopped here (18:12): its model run ended with "monthly usage limit reached" after §8.2. The lead (main agent)
continued items 3–8 on the same instance under the same rules (HARNESS §1–§9) from 18:40. Scratch helpers (not project
tools): `mg_probe.py`, `mg_find.py`, `c59d.py`, `tapcount.py`, `bpan.py`, `nav_t3.ps1` in the lead's session scratch.

### 8.3 Item 3 — adrenaline minigame T3b / T3c with `v2`, `v2n`, `v2b` (lead, confirmed, 18:40–19:20)

Install per testbeds README §7.4 (`use-build <tag> --replace`, `tb_warp.py install t3b_minigame_warp --tag v2|v2n`,
`t3c_minigame_warp_fev --tag v2b`); log in every boot: `System_IsNew3ds: true`, `ApplyCodePatch … code.bps`,
`LayeredFS replacement file in use for /BAI/BAI.dat` and `/FEvent/FEvent.dat`. Path: title → slot 1 → 「시작하기」 →
「마리오&루이지 RPG3」 → field (Bowser at the save block) → **A** (bros) → lower screen shows the hub body map (cursor
「챌린지 홀」).

**Test-bed defect (T3b/T3c), worked around:** the warp stopped in its copied story poll (wrapper instructions 8–10,
`jmpif($c59d != 1)`): at runtime `$c59d` = 1 while the hub map is open (u32 0x3F9A58 = 0xFFFFFFFF, i.e. `$c580..$c59f`
all set; the save has 0). TB2 §7.7 point 2 named this risk. Test-only fix: an RPC write clearing bit 29 of 0x3F9A58
(static gGameWork, outside the linear heap); the wrapper then ran its fades and `op18a(0x86)`, and the minigame
(「아드레리버」) was running 8 s later. The retry path (loss → `i_power_hip_01` question 「다시 한번 아드레리버를
건너시겠습니까?」 → 「건너기」 → the story lead-in with its own `$c59d` poll) then worked without another write.

**Method (pass rate of the play loops):** breakpoint count on the field op `op0de` handler 0x2ECBF0 (handler table entry
= 0x3A38D4 + 8·(op − 0x150); op096 = 0x2E1654). Loops #55 (Mario) and #56 (Luigi) execute `op0de($7002, 0, $300e, 0f,
20f)` exactly once per pass (both stick branches end at +0x8B8A / +0x8E39; skipped only while `$c398` = 1), so the frame
gap between two hits of the same LocalEvent (r2) is frames per pass. `rt_gdb.py bp 0x2ECBF0 --count N --mem
0x320DA8E8:4` (frame counter fld::System+0x578 read at each hit; the game is halted at hits, so the gaps are in game
frames). The dump/fdiff search for the bros' x found no plain f32 (op096 param 9 is not stored as one); only a float
toggling −108.5/14.5 with the stick (0x302DCE7C) and two object coordinates.

| build (bed) | console | fld +0x3D / +0x41, step, frames/s | loop LocalEvents (r2) | frame gap per pass | passes/s | hit frames | result |
|---|---|---|---|---|---|---|---|
| `v2` = A (T3b) | New 3DS | 0 / 1, 1.0, 59.5 | 0x31CAC904, 0x31CADF1C | **2** (18 + 18 gaps) | **30** | all 19 on even frames | **PASS** |
| `v2n` = control (T3b) | New 3DS | 0 / 1, 1.0, 60.0 | same | **1** (51 + 51) | 60 = 2× | even and odd | as expected |
| `v2b` = B (T3c) | New 3DS | 0 / 1, 1.0, 60.0 | same | **2** (56 + 56) | **30** | 57 even, 3 odd | **PASS** |
| `v2` = A (T3b) | Old 3DS | 1 / 0, 2.0, 30.0 | same | 1 (38 + 38) at 30 fps | 30 | every frame | **PASS** (item 6) |

So Option A and Option B both run the minigame's play loops at the 30fps game's 30 passes per second while the screen
runs at 60; without a field fix they run twice as fast. Under `v2n` an unplayed round ended (loss) within ≈ 12 s of the
warp; under `v2` the round was still running 8–30 s after it (not timed). The bros' 6-unit steps, shot interval (10 passes)
and the #77 fade (180 passes) all count these passes.

### 8.4 Item 6 — Old 3DS with `v2` (lead, confirmed, 19:16–19:20)

`user/config/qt-config.ini` lines `is_new_3ds\default` and `is_new_3ds` set to `false` with the emulator stopped (copy of
the file kept in the lead's scratch), `v2` + T3b. Log `System_IsNew3ds: false`, code.bps patch line, both LayeredFS
lines. Title → field → minigame normal; fld::System **+0x3D 1 / +0x41 0 / +0x45 1, step 2.0, 30.0 frames/s**; minigame
loops one pass per frame at 30 fps (table above) = the stock 30fps reference. Both lines set back to `true` afterwards
(checked). **PASS.**

### 8.5 Item 4 — credits with `v2` (lead, confirmed, monitor `rt3/R5_v2B.jsonl`)

`use-build v2 --replace` + CRD test bed B (`credits/testbed/romfs/FEvent/FEvent.dat` `872427F6…`, copied into
`mods_builds/v2/romfs/FEvent/`), original save. Log: code.bps patch line, FEvent and BAI LayeredFS lines.
`rt_credits.py follow --label R5_v2B --secs 275` started on the mode select, then 「마리오&루이지 RPG3」.

| quantity | `v2` | stock (R1) | `v1` / cheat (R2/R3) |
|---|---|---|---|
| field task | 0x320DA370, +0x3D 0 / +0x41 1 from the first sample; fld +0x578 59.7–59.9/s in every 10-s window | 30/s | 60/s |
| staff-roll updates per second | **29.91** | 29.91 | 59.8 |
| roll (first update → isFinish, frame 6157) | **205.79 s** | 205.8 s | 102.9 s |
| music `04_end_roll` (play → handle detached) | 214.24 s | 214.0 s | 214.0 s |
| text end − music end (measured) | **+1.09 s** | +1.2 s | −101.7 s |
| after the roll | ctrl deleted at 237.3 s, room change → `o_koopa_end_01`, Kamek 「쿠파님~ 기분은 어떠신가요~?」 at 60/s | same | same |

No freeze, no `UnmappedAccess`. **PASS**: under Option A the roll is updated only by the 30-Hz field VM, so no
separate credits fix is needed (IMPL3's choice confirmed).

### 8.6 Item 5 — single short taps under `v2` (lead, confirmed, `rt4/taps_v2.json`, `rt4/taps_v2b.json`)

Script prompt used: the Bowser ↔ bros screen switch in the slot-1 save room (TB2 §7.6 second candidate, `resident.fev`
#4: A while Bowser has control, X while the bros have control, both read the field trigger `$7038`). Each tap = one
posted key with a **17 ms** hold (measured 17.2–17.5 ms); registered = `$700e` (u8 `[[fld+0x1A70]+0x9848]`, here
`[0x320CA6F4+0x9848]`) changed within 2.5 s.

| run | taps | registered | reaction |
|---|---|---|---|
| `v2`, 24 taps (A/X alternating) | 24 | **24** | A 0.52–0.73 s (switch animation first), X 0.03–0.06 s |
| `v2`, 10 taps with the latch logged at 60 Hz (`rt4/taps_v2_latch.jsonl`) | 10 | **10** | same |

Direct evidence that the latch delivered taps from skipped frames: in the second run the latch word 0x434F00 held
`trg` = 0x400 (X) or 0x1 (A) with `frame` = 0x1897, 0x19D3, 0x1B37, 0x1C17 — all **odd** frames, on which the field VM
does not run; those taps still switched the screen. **PASS (34/34).** The `v2n` control was not run (its VM runs every
frame, so it can only show the same 100 %).

### 8.7 Item 7 — transitions with `v2` (New 3DS)

Counted over the `v2` boots of RT4 and the lead (no freeze, no crash, log only the known ClCertA / delay-generator /
shared-font `<Error>` lines, no `<Critical>`, no `UnmappedAccess`):
- RT4 §8.1/§8.2: 3 ordinary battles + 1 Dark Star battle (field → battle → result → field, 8 transitions).
- T3b boot: title → file select → mode select → field (3), Bowser → bros (1), warp lower/upper room change into the
  minigame (1), 3 × minigame end → `i_power_hip_01` retry question → 「건너기」 → minigame (6).
- Credits boot: title → … → field (3), staff-roll rooms → `o_koopa_end_01` (1).
- No-bed boot: title → … → field (3), **34 screen switches** (§8.6), pause menu ×3 (MainMenuTask vptr 0x4A0FAC at
  +0x3D 0 / +0x41 1, 60/s, back to fld::System 0/1/0 each time = 6), save menu ×1 (`CUP`, `X`; SaveMenuTask vptr
  0x48858C at 0/1/0, 60/s; B back = 2). Walking out of the save room was not completed (Bowser stopped at the left
  walkway; RT2/RT3 measured walking room changes with the same field task).
- Bowser Jr.'s Journey boot: title → … → 「쿠파주니어 RPG」 (3) → KJ intro on fld::System **0x320ABAC8 at 0/1/0, 60/s**;
  dialog 「크, 크, 큰일입니다! 쿠파님!」 advanced with three 17-ms A taps, fade, next scene 「주니어… 또 그 장난이냐…」.
Total ≥ 40 scene/menu transitions + 34 control switches. **PASS.**

### 8.8 Item 8 — `v2b` extras

Every `v2b` boot logged `LayeredFS replacement file in use for /FEvent/FEvent.dat` (FEV's file, via T3c) and the BAI
line; the T3c warp (two room changes) and the minigame ran normally (§8.3). Normal walking with `v2b` was not repeated.
Option B is kept as the documented fallback only.

### 8.9 Decision and final state (lead, 2026-10-30)

| item | Option A `v2` | Option B `v2b` |
|---|---|---|
| 1 ordinary battle, action commands | PASS (RT4) | not run (same code and BAI as `v1cb`/`v2n` battles) |
| 2 hold attack grace + orbit | PASS (RT4) | same BAI file as A |
| 3 minigame per-pass rate | PASS (30/s) | PASS (30/s) |
| 4 credits | PASS (205.79 s) | covered by `v1cb` = stock (RT3 §7.5) |
| 5 short taps | PASS 34/34, latch seen on odd frames | not needed (FEV changed no trigger-reading loop) |
| 6 Old 3DS | PASS (30 fps, +0x3D 1) | not run |
| 7 transitions | PASS (≥ 40 + 34) | partial |
| coverage of frame-counted field scripts | every field/resident VM script (gating in code) | only the 136 sites FEV's scanner found |
| files | `code.bps` 559 B + `BAI.dat` | `code.bps` + `BAI.dat` + 6.4 MB `FEvent.dat` |

**Chosen: Option A (`v2`).** Installed by `work/fps60/install_20261030/install.py` (record `install.json`):
`patch/00040000001CA900/code.bps` (sha256 `c3922b9d…5be2`) and `patch/00040000001CA900/romfs/BAI/BAI.dat`
(`c681a963…fbb6`), the same two files in `work/sd_package/luma/titles/00040000001CA900/` and in
`work/sd_package/ml3dx_ko_luma.zip` (backup `work/build/prev_fps60_20261030/`). patch = Azahar junction = SD folder =
ZIP for all **38** files (36 Korean patch files unchanged). Test instance boot through the junction afterwards: log
`…/mods/00040000001CA900/code.bps patching code.bin` (title-root location), BAI and MainMenu.cro LayeredFS lines,
title and field at +0x3D 0 / +0x41 1, 60/s. Final state: `use-patch` (junction → `patch/00040000001CA900`, 38 files,
MainMenu.cro `1F227C75…`; `rt_mods.py` now expects 38), saves `1F1CF4F6…` / `43C2CA72…` / `659AB0D2…` unchanged,
TEST config `is_new_3ds=true`, emulator stopped.

### 8.10 Real New 3DS: loader panic with `code.bps`, switched to `code.ips` (lead, 2026-10-30 20:00–)

User report: the game crashed on real hardware right after launch, before any game screen; dump
`crash_dump_00000011.dmp` (project root). Parsed (Luma exception dump format v1.3): ARM11 core 1, **prefetch abort =
svcBreak(USERBREAK_PANIC)** (r0 = 0), process **`loader`**, pc 0x1400607C (`svc 0x3C`), lr 0x1400087C; r3 = r11 =
**0x07907000**, r9 = 0x07C00000, r4 = 0x002F9000; the stack holds `/luma/titles/00040000001CA900/code.bps` and the code-set
sizes text 0x288BD8 / ro 0x65E50 / data 0x9170 (= v1.2, so the update is installed).
Matched against the loaders of the last two releases (boot.firm → CXI `loader` → LZSS .code; scratch `lumaloader.py`):
the dump's 96 code bytes sit at the dump's pc only in **Luma v13.4** (v13.3.3 differs). v13.4 loader disassembly:
0x140006F8 `bl svcGetSystemInfo` (osGetMemRegionFree) → 0x14000728 `bl svcControlMemory(MEMOP_ALLOC|REGION_APP,
0x08000000, size = free)` → 0x14000730 `blt 0x14000874` → `mov r0, #0; bl svcBreak`. That is `ScopedAppHeap` in
`bps_patcher.cpp` (v13.4): it allocates **all** free APPLICATION memory as scratch; this title runs in the New 3DS
**124 MB** mode (exheader ACI flag2 = 1, L2 + 804 MHz), free = 0x7C00000 − 0x2F9000 = 0x07907000, and the allocation fails
→ the loader panics before the game process exists. Luma master caps the scratch at 30 MB (commit aef3130,
2026-09-04, "loader: bps: Limit temporary app size allocation"), not in any release. Azahar's BPS path has no such
allocation, which is why every emulator run passed.

Fix: ship the same patch as **`code.ips`** (build `v2`, 552 B, sha256 `e5aa7d60…998a`). Luma's IPS path (v13.4
`applyCodeIpsPatch`) reads records straight into the code buffer, no allocation. Checks: IPS applied to the v1.2 code =
`patched.code.bin` byte for byte (8 records: 0x28092C+4, 0x388E10+476, six vtable words; none in Luma's LayeredFS payload
0x388BD8..0x388E0F or path 0x3EEE50..0x3EEE77; nothing after `EOF`, so Luma master's new EOF rule passes); build verify:
`luma_v10.1-v13.4_ips ok, luma_master_ips ok, azahar_ips ok`. `work/fps60/install_ips_20261030/install.py` removed
`code.bps` (backup `work/build/prev_fps60_ips_20261030/`) and added `code.ips` in patch/, the SD folder and the ZIP
(38 files, all four copies equal). Test instance through the junction: log `…/mods/00040000001CA900/code.ips patching
code.bin`, title and field +0x3D 0 / +0x41 1, 60/s; saves unchanged; emulator stopped.
Trade-off: IPS has no version check (a v1.0 install would be corrupted); the Korean patch set is already v1.2-only.

### 8.11 60fps files alone on the Japanese game (lead, confirmed, 2026-10-31 00:10 KST)

Question: can the 60fps mode be used without the Korean patch? `work/review/rt5_20261030/rt5_mods.py use-empty
rt5_fps60only`, then only `code.ips` (`e5aa7d60…`, title root) and `romfs/BAI/BAI.dat` (`8f3c1928…`) copied into
`tools/azahar-test/mods_builds/rt5_fps60only/` (no Korean files). Log: `System_IsNew3ds: true`,
`…/mods/00040000001CA900/code.ips patching code.bin`, and `LayeredFS replacement file in use for /BAI/BAI.dat` as the only
replacement line. Title and field: fld::System 0x320DA370 +0x3D 0 / +0x41 1 / +0x45 0, 60/s; pause menu: MainMenuTask
0x30000028 (vptr 0x49FFAC = the original MainMenu.cro's, the Korean CRO gives 0x4A0FAC) 0/1/0, 60/s; menu text Japanese
(アイテム, そうび, ステータス …). Grabs `work/fps60/runtime/jp60_field.png`, `jp60_pause.png`. Restored: `use-patch` (38 files),
saves `1F1CF4F6…` / `43C2CA72…` / `659AB0D2…`, TEST config `is_new_3ds=true`, emulator stopped. The reverse (Korean
without `code.ips`) was RT5's `rt5_ko` run (RT5.md §1b, §3.4: 30fps). Comparison with the community cheat:
`work/fps60/CHEAT_COMPARISON.md`.
