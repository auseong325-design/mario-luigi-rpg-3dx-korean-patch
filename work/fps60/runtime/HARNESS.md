# RT harness: portable Azahar test instance for the 60fps work

Owner: RT. Instance: `tools/azahar-test/` (git-ignored except `rt_launch.ps1`). Clients: `scripts/fps60/rt_rpc.py`,
`rt_gdb.py`, `rt_measure.py`; builder `rt_setup.py`. Results: `work/fps60/runtime/findings.md`,
raw records `work/fps60/runtime/measure_log.jsonl`.

## 1. What the instance is

- `tools/azahar-test/azahar.exe` + DLLs = copy of `C:\Program Files\Azahar` (Azahar 2126.1.2, HEAD-9e6f523).
- Portable mode = the `user/` folder next to `azahar.exe`. Verified: the boot log is written to
  `tools/azahar-test/user/log/azahar_log.txt` (not `%APPDATA%\Azahar\log`), and the game's save path is
  `user/sdmc/...`.
- `user/sdmc/Nintendo 3DS/0…0/0…0/title/00040000/001ca900/{content,data}` (base game + **copied** saves
  ML3R_000/001/002.sav) and `title/0004000e/001ca900/content` (v1.2 update). SHA-256 identical to the user's.
- `user/nand/{data,dbs}` copied (CFG/Mii system saves, tickets). Not copied: encrypted NAND system titles,
  `nand/private`, `nand/rw/sys`, `sysdata/otp.bin` (console-unique, not needed: the game content is decrypted).
  Consequence: config uses HLE applets (`lle_applets=false`); the log shows a harmless
  "CHN/KOR/TWN shared font file missing … open source replacement" line (the game uses its own fonts).
- `user/load/mods/00040000001CA900` = **junction** to `patch/00040000001CA900` (Korean patch active, follows the
  lead's builds). Log proof: `LayeredFS replacement file in use for /RO/MainMenu.cro`.
- `user/config/qt-config.ini` = the user's config with only these changes (`rt_setup.py --config` regenerates it):
  `use_gdbstub=true`, `gdbstub_port=24689`, `enable_rpc_server=true`, `is_new_3ds=true`, `lle_applets=false`,
  `nand/sdmc_directory` = the instance's `user/`, screenshots to `user/screenshots/`, UI language `en`,
  `volume=0`, no Discord presence / update check / close-confirm / save-state warning,
  `pauseWhenInBackground=false`, web tokens blanked, controller profile 0 = stock keyboard map:
  **A=A B=S X=Z Y=X, D-pad T/G/F/H, L=Q R=W, ZL=1 ZR=2, Start=M Select=N, Home=B, circle pad = arrow keys**.
  Hotkeys (user's): F4 pause/continue, F5 stop, F6 restart, Ctrl+C save to oldest slot, Ctrl+V load newest,
  Ctrl+P screenshot.

Rebuild from scratch: `.venv\Scripts\python.exe scripts\fps60\rt_setup.py` (idempotent; only reads the user's
Azahar dirs; refuses any write outside `tools/azahar-test`).

## 2. Launch / stop (never pipe, never wait on the emulator)

```powershell
# start (returns at once; ShellExecute, no inherited handles; PID -> tools\azahar-test\rt_azahar.pid)
powershell -NoProfile -ExecutionPolicy Bypass -File tools\azahar-test\rt_launch.ps1
# stop (only kills that PID, only if it is tools\azahar-test\azahar.exe)
powershell -NoProfile -ExecutionPolicy Bypass -File tools\azahar-test\rt_launch.ps1 -Stop
```
Do NOT add `-RedirectStandardOutput/-Error` to the emulator's Start-Process: it switches to CreateProcess with
handle inheritance and the calling shell tool never returns (cost RT 45 min). Boot to the title screen takes
~10–20 s; the RPC and GDB servers are up as soon as the log shows `Starting RPC server` /
`Starting GDB server on port 24689`.

## 3. Running a client (always Start-Process + redirect + WaitForExit ≤ 120 s)

```powershell
[Console]::OutputEncoding = [Text.UTF8Encoding]::new($false); $OutputEncoding = [Text.UTF8Encoding]::new($false)
Set-Location C:\AI-Projects\mario-luigi-rpg-3dx-korean-patch
$o = "$env:KIROCREW_SCRATCH\rt.out.txt"; $e = "$env:KIROCREW_SCRATCH\rt.err.txt"
$p = Start-Process .venv\Scripts\python.exe -ArgumentList 'scripts\fps60\rt_measure.py','task' `
     -RedirectStandardOutput $o -RedirectStandardError $e -NoNewWindow -PassThru
if (-not $p.WaitForExit(120000)) { Stop-Process -Id $p.Id -Force; 'TIMEOUT' }
Get-Content $o, $e
```
All clients use socket timeouts (RPC 1 s × 3 retries, GDB 5 s).

## 4. RPC (UDP 45987) — reads anywhere mapped, writes only outside the 0x30000000 linear heap

`rt_rpc.py ps | read ADDR LEN | dump ADDR LEN FILE | write ADDR HEX | find HEX --range A:L |
watch ADDR --secs S | cros | tasks --range A:L`. The client selects the game process
(title 00040000001CA900) itself.
- 2126.1.2 server: ReadMemory/WriteMemory/ProcessList/SetGetProcess only (no perf stats, no screenshot).
- WriteMemory is silently ignored for 0x30000000+ (the game's linear heap, where tasks live);
  `rt_rpc.py write` refuses those addresses. Use GDB `M` (below).
- Reading unmapped pages returns zeros and logs one error per page: stay inside mapped ranges
  (`rt_gdb.py map --out work\fps60\runtime\memmap.json` probes them; `rt_rpc.py` then uses that file).
- `cros` parses `CRO "<name>" loaded at 0x…` lines from the instance log = runtime CRO bases.
  runtime address = base + CRO file offset = base + (analysis address − analysis module base).

## 5. GDB stub (TCP 24689)

`rt_gdb.py regs | threads | read | write | map | bp ADDR [--count N --mem r0:0x50] | watchw ADDR LEN | wait`.
- `?` attaches the launched title and **halts** it; the client resumes on exit by sending `c` and closing
  (2126.1.2's `D` resets the stub state before `Continue()`, which can leave the game halted).
  `--keep` leaves it halted on purpose.
- No single-step in this version: `bp --count N` hops over the BKPT with a temporary breakpoint on ADDR+4, so ADDR
  must not be a branch. Watchpoints under the JIT are approximate (stub warns).
- Breakpoints write `BKPT 0xE1200070` into the code; they are removed on exit (and by the stub on disconnect).

## 6. Measurements (rt_measure.py)

- `rt_measure.py task --secs 1 --label <scene>`: `[0x3F40B4]` = current task, vptr + RTTI class chain,
  bytes +0x3C..+0x48 (+0x3D = InitParam fps copy, +0x45 = live fps mode), frame counter `task+0x578` sampled
  every 0.25 s (→ frames/s), `0x3F716C` (IsRunOnSnake cache), `0x1FF80030` (APPMEMTYPE).
- `rt_measure.py setfps 0 --offset 0x3D [--offset 0x45]`: GDB write of the fps byte(s) of the current task, resume,
  wait 1 s, re-measure.
- Presented FPS: the window's status bar "App: N FPS" (= top-screen SetBufferSwap per second). Read it with the
  desktop tools (`computer_get_state(app="azahar")`) or by eye.


## 7. Verified run (2026-10-30) and pitfalls

Verified sequence: `rt_launch.ps1` → wait ~40–60 s (title screen; `Starting RPC server` appears after ~1 s) →
`rt_measure.py task --secs 2 --label boot_title_30fps` (game pid 11, current task 0x320DA370) →
`computer_get_state(app="azahar")` shows `App: 30 FPS` → `rt_measure.py setfps 0 --offset 0x3D` → `App: 60 FPS`,
counter 59.9/s → `rt_measure.py setfps 1 --offset 0x3D` → back to 30/s → `rt_launch.ps1 -Stop`.
The GDB write path (attach `?` → `M` → `c` + close) resumed the game every time (counter kept advancing).

Pitfalls:
- `Start-Process -ArgumentList` does not quote elements: an argument with spaces (`--label "a b"`) is split.
  Use labels without spaces.
- Never redirect the emulator's output (section 2). Client processes (python) may be redirected; they exit.
- `rt_rpc.py write` refuses 0x30000000+ (server ignores it); use `rt_gdb.py write` / `rt_measure.py setfps`.
- Writing the live fps byte +0x45 has no lasting effect: it is re-derived from +0x3D within ≤1 s.
- The Azahar log is flushed lazily; CRO load lines can appear late. `rt_rpc.py cros` reads whatever is flushed.
- `user/sysdata/` must exist (else a harmless "Cannot open mac address file" error); `rt_setup.py` creates it.
- Status-bar text is in English because the test config sets UI language `en`; the window chrome stays Korean
  (system buttons 최소화/최대화/닫기).



## 8. Wave-2 additions (RT2, 2026-10-30)

### 8.1 Input without taking the user's focus: `rt_input.py`
`computer_press_key` cannot drive the game: the render surface is not in the accessibility tree, so no element
takes keyboard focus and the tool refuses to send keys. Use instead (Start-Process + WaitForExit as in §3):
```
rt_input.py keys A w3000 A CDOWN:150 R+A:300 START   # BUTTON[:hold_ms][*count], wMS = wait, '+' = chord
rt_input.py touch 160 120                            # bottom-screen pixel (WM_LBUTTON*, untested)
rt_input.py info                                     # which hwnd it would target
```
It posts WM_KEYDOWN/UP to the test process's render child window only (`Qt6111QWindowOwnDCIcon`), after checking:
exactly one azahar.exe, PID = `rt_azahar.pid`, image = `tools/azahar-test/azahar.exe`. Buttons follow the §1 map.
No real keyboard focus is taken and the mouse pointer never moves.

### 8.2 Census and logic probes: `rt_census.py` (RPC only; JSON lines in `work/fps60/runtime/census.jsonl`)
- `snap --label L [--no-tasks]`: current task (class, +0x3C..+0x48, +0x578/s), class steps, globals
  (`[0x3F49D0]` fld::System +0x1A4C/+0x1A48/+0x6E0, `[0x3F3600]` btl::Main +0xBA15C, `[0x3F61C0]` kj::KJSystem
  +0x61C58, `[0x3F62A8]` MComSys +0xE6530, `[0x412C80]` ffwd), loaded CROs, RTTI scan of heap + linear heaps
  (`plausible=false` marks vptr-valued words inside CRO code copies).
- `follow --secs S --label L`: 20 Hz change log of task/+0x3D/+0x41/+0x45/+0x578 and the global steps; run it in the
  background while sending keys (scratch helper pattern: start `follow`, sleep 0.5 s, run `rt_input.py`).
- `counters --label L [--compare earlier.json]`: steadily rising u32/f32 in the task, static data/bss (and ranges
  given with `--range name=ADDR:LEN`); ratio ≈ 2 at mode 0 = per-frame counter.
- `dump --range … --out P`, `fdiff A B [C] --thr 20 --back 0.5`: find positions (moved and moved back).
- `watchf ADDR… --secs S`: sample floats (e.g. a position) and report net/path change.
  Bowser's X in the slot-1 save room was 0x30003BD8 in the first boot only (allocation changes between boots).

### 8.3 Mods switcher: `rt_mods.py` (only with the emulator stopped)
```
rt_mods.py status
rt_mods.py use-build v1            # COPY of patch romfs + work/fps60/build/v1/romfs overlay + exefs/code.bps
rt_mods.py use-build smoke --empty-ok      # no build folder: patch copy only
rt_mods.py use-build v1 --replace          # rebuild an existing tools/azahar-test/mods_builds/v1
rt_mods.py use-patch               # back to the junction to patch/00040000001CA900 (+ 36-file / MainMenu sha256 check)
```
Builds live in `tools/azahar-test/mods_builds/<tag>/` (+ `<tag>.json` manifest). Never install `code.ips` and
`code.bps` together (`--ips` copies the IPS instead of the BPS). Proof in the log after boot:
`ApplyCodePatch: File …/exefs/code.bps patching code.bin` and the LayeredFS lines.

### 8.4 New pitfalls
- `rt_gdb.py map`: unmapped pages answer `m` with an EMPTY packet (fixed in `is_mapped`); a killed GDB client
  leaves the game halted (+0x578 frozen) — any attach + `c` (e.g. `rt_gdb.py regs`) resumes it.
- The emulator log is flushed only on Error lines; `rt_rpc.flush_log()` (one unmapped 4-byte RPC read at 0x05000000)
  forces it before parsing CRO bases. `log_filter` = `*:Info RPC_Server:Warning` keeps RPC traffic out of the log.
- Do not run heavy RPC reads (`snap` with task scan, `counters`, `dump`) during or within ~10 s of a scene change: one
  such scan 4 s after the title → file select change coincided with an azahar.exe access violation (findings §6.10).
- After the window moved to a monitor with another DPI, the render area stayed black (game kept running);
  restarting the emulator fixed it. Use a desktop grab of the render rect (PIL `ImageGrab`) or
  `computer_get_state(screenshot=true)` to look; the GSP framebuffer in guest memory is not usable as a screenshot
  with the hardware renderer (stale data).
- `Start-Process -ArgumentList` splits on spaces: labels/notes without spaces.


## 9. Wave-3 additions (RT3, 2026-10-30)

- `scripts/fps60/rt_credits.py follow --label L --secs S [--flip] [--find-room]`: 4 Hz light RPC log (current task, fld::System
  fps bytes/+0x578/step/+0x6E0, StaffrollCtrl `[fld+0x1B3C]`, `[0x415E38]` P0/P4, BGM handles, RT2's counter words) into
  `work/fps60/runtime/rt3/L.jsonl`; `summary FILE` → roll start/isFinish/delete, updates/s, music play/detach, freezes.
  Run it **detached** so the shell call returns: `Start-Process .venv\Scripts\python.exe -ArgumentList … -WindowStyle Hidden
  -PassThru` (no `-NoNewWindow`, no redirection; the script writes its own files and stops after `--secs`).
- BGM markers: `SndSys` is static 0x3FBF9C (`u32[[fld+0xA08]]`); `+0`/`+4` = BGM slot 0/1 SoundHandle (BasicSound* or 0, 0 after
  a non-looping stream ends); field per-slot state fld+0xA0C (u8 playing) / +0xA10 (sound id). `04_end_roll` = 0x0100032C.
- Credits: use CRD test bed **B** (FEvent.dat copied into a `mods_builds/<tag>/romfs/FEvent/` copy, original slot-1 save);
  test bed A (save redirect into 0x2C2/0x2C1) makes the guest read NULL in `TaskBase::readArcFile` and spray unmapped writes
  (findings §7.1; the emulator crawls at Speed 0% while logging them: stop it).
- Old 3DS run: edit only `is_new_3ds\default` and `is_new_3ds` in `user/config/qt-config.ini` (both lines; with `\default=true`
  the value is ignored), emulator stopped; log shows `System_IsNew3ds: false`; edit them back afterwards.
- Navigation: a press during the title intro only skips the intro; check the screen before the next A. No soft reset
  (L+R+START+SELECT opens the pause menu); restart the emulator to get back to the title.


## 10. Wave-4 additions (lead, 2026-10-30)

- Since the 60fps install, `patch/00040000001CA900/` holds **38** files: the 36 Korean-patch files, `code.ips` at the
  title root (was `code.bps` until the real-HW loader panic, findings §8.10) and `romfs/BAI/BAI.dat` (BAI fix).
  `use-patch` therefore boots the shipped 60fps build (log `…/mods/00040000001CA900/code.ips patching code.bin`);
  `rt_mods.py` expects 38. Azahar never shows Luma-loader problems: test any change of the code-patch format on Luma. `use-build` copies only the patch
  romfs, so every test build now starts from the BAI-fixed BAI.dat; a stock-BAI reference needs that file removed
  from the test copy.
- T3b/T3c (minigame warps): the copied story poll waits on `$c59d`, which is 1 while the hub map of `i_tainai_01` is open.
  After loading slot 1 and pressing A (bros), clear bit 29 of u32 0x3F9A58 by RPC (static gGameWork; allowed); the warp
  then runs. The retry question 「다시 한번 아드레리버를…」 → 「건너기」 replays the minigame without another write.
- Script pass rate without knowing variable addresses: breakpoint-count a field op handler used once per loop pass,
  e.g. `rt_gdb.py bp 0x2ECBF0 --count 120 --timeout 10 --mem 0x320DA8E8:4` (op0de; handler of op N = u32 at
  0x3A38D4 + 8·(N − 0x150)); group the hits by r2 (LocalEvent) and take the frame-counter gap per thread.
- Short-tap check: alternate A / X on the Bowser ↔ bros switch in the save room and watch `$700e`
  (u8 `[[fld::System+0x1A70]+0x9848]`); the latch word 0x434F00 {trg, rls, touch, frame} shows taps saved on odd frames.
- Bowser's save block: `CUP:150`, then `X` (Bowser must face the block).
