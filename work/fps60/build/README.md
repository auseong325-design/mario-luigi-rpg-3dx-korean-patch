# fps60 build — `scripts/fps60/build_fps60.py` (worker IMPL, wave 2)

Status: **COMPLETE for wave 2** — default build `v1` and `v1c` (`--credits-fix`) pass every check (§5).
Target: 『マリオ&ルイージRPG3 DX』 JP v1.2 static code (`work/fps60/bin/3dx_v12.code.bin`, decompressed,
0x2F9000 bytes, base 0x100000). Design decisions D1–D6 from `work/fps60/BRIEF2.md` §1.
Confidence tags: **confirmed** (read in code / measured by my tools), **likely**, **guess**.
Nothing here writes into `patch/` (D6). Builds are in `work/fps60/build/<tag>/`.

## 1. How to build

Run from the project root (every command with a timeout, as usual):

```
.venv\Scripts\python.exe scripts\fps60\build_fps60.py --tag v1                 # default: init hook only
.venv\Scripts\python.exe scripts\fps60\build_fps60.py --tag v1c --credits-fix   # + staff-roll scroll fix
.venv\Scripts\python.exe scripts\fps60\build_fps60.py --tag t1 --allow fld,btl  # other allow-list (names or 0x vptrs)
.venv\Scripts\python.exe scripts\fps60\build_fps60.py --tag t2 --no-snake       # TEST ONLY: no New-3DS test
.venv\Scripts\python.exe scripts\fps60\build_fps60.py --tag v1 --skip-emu       # skip the unicorn tests
```

Exit code 0 = every check passed (`RESULT: ALL CHECKS PASSED` at the end of `verify.txt`). Each run here finished
well inside the 10-minute `WaitForExit` limit I used; the pure-Python LZSS and BPS checks are the slow part.
Requirements: keystone 0.9.2, capstone 5.0.6, unicorn 2.1.4 (`pip install unicorn` into `.venv`, done 2026-10-30).

Files of the build tool:

| file | role |
|---|---|
| `scripts/fps60/build_fps60.py` | builder: original-byte checks, keystone assembly + capstone round trip, IPS/BPS writer, manifest, runs all checks |
| `scripts/fps60/impl_loaders.py` | my Python ports of the Luma3DS and Azahar appliers (IPS, BPS, LZSS, Luma LayeredFS placement), from their source |
| `scripts/fps60/impl_emutest.py` | unicorn ARM11 tests of the cave (TaskBase::init tail, credits fix) |
| `scripts/fps60/impl_exheader.py` | read-only CIA → NCCH → exheader code-set parser (sizes the loaders use) |

Outputs per tag (`work/fps60/build/<tag>/`):

| file | what |
|---|---|
| `code.bps` | **the deliverable** (D4, §4): one file for Luma3DS and Azahar |
| `code.ips` | same patch as IPS, for analysis / emergency use only; **never install it next to `code.bps`** |
| `patched.code.bin` | patched decompressed code (for disassembly / Ghidra), never installed |
| `manifest.json` | sha256 of input and outputs, patch list (address, file offset, old/new bytes, disassembly), allow-list with RTTI, cave usage, every verification result |
| `verify.txt` | human-readable build log: cave listing, patch table, PASS/FAIL per check |

Current builds (2026-10-30 14:50, input `3dx_v12.code.bin` sha256 `3e9d5c52…1816`, CRC32 `BD87889C`):

| tag | flags | code.bps | code.ips | patched.code.bin sha256 | result |
|---|---|---|---|---|---|
| `v1` | default (allow fld,btl,kj,menu; New-3DS test on) | 155 B, sha256 `f0983fa1…3356` | 134 B: 0x18092C ×4, 0x288E10 ×0x70 | `62a42dc0…e5e8` | ALL CHECKS PASSED |
| `v1c` | `--credits-fix` | 215 B, sha256 `ec4189b9…c0c6` | 195 B: 0x18092C ×4, 0x1E8B9C ×4, 0x288E10 ×0xA4 | `aa197f11…f61b` | ALL CHECKS PASSED |

(Full hashes in each `manifest.json`. IPS/BPS records are exactly the declared patch ranges; the builder asserts
that no byte outside them differs.)

## 2. Register-liveness check of the hook site (confirmed, `armdis.py 3dx_v12 0x28068c 200`)

`ad::fw::TaskBase::init(const InitParam&)` 0x28068C, prologue `push {r3,r4,r5,r6,r7,r8,sb,sl,fp,lr}` (10 regs,
40 bytes → sp stays 8-aligned if it was at entry). Tail:

```
00280918: ldrb  r0, [r4, #0x3e]
0028091c: cmp   r0, #0
00280920: strbne r7, [r4, #0x4a]      ; r7 = 1 (set at 0x2806CC, never changed)
00280924: strbeq r8, [r4, #0x4a]      ; r8 = 3 (0x2807EC)
00280928: ldrb  r1, [r4, #0x3c]       ; r1 = pipelined flag, LIVE until 0x280934
0028092c: ldrb  r0, [r4, #0x3d]       ; <-- HOOK: becomes  bl eng60_init
00280930: strb  r7, [r4, #0x46]
00280934: strb  r1, [r4, #0x44]
00280938: strb  r6, [r4, #0x378]      ; r6 = 0 (0x2806B8)
0028093c: strb  r0, [r4, #0x45]       ; r0 = fps mode
00280940: pop   {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
```

Live after the hook: r0 (result), r1, r4, r6, r7. Dead: r2, r3 (r3 is reloaded by the pop), r12, lr (the pop loads
pc, not lr; lr is caller-saved for init's caller), flags (no conditional instruction before the pop). The cave
returns r0 = mode byte and keeps r1–r3 and every callee-saved register (unicorn test B, §5.3).
`nn::os::CTR::IsRunOnSnake` 0x2844AC is plain AAPCS (`push {r3,r4,r5,lr}` … `ldrsb r0,[r4]; pop {r3,r4,r5,pc}`,
cache byte 0x3F716C, guard word 0x3F7170; first call = APT IPC 0x01010000 via 0x10ED0C, `nndbgPanic` on IPC error).
It is only reached for an allowed class at mode 1, never for Boot (mode 0), so it never runs before boot is done.

Marker byte +0x41: TaskBase+0x0C..+0x43 is the embedded `InitParam` (0x38 bytes); `init` copies only 0x35
(`memcpy4(this+0x0C, ip, 0x35)` 0x28069C) and `InitParam::InitParam` 0x24B240 writes +0x00..+0x34 (`stm`s, three
`strb`s, then `__aeabi_vec_ctor_nocookie_nodtor(+0x33, 0x114094, 1, 2)`), so +0x41..+0x43 are struct padding.
A scan of every `ldr/str{b,h} …, [rX, #0x41]` in the static listing and the 15 CRO listings found none inside a
TaskBase-family function (scratch `scan41.py`: static 53 / CROs 54 accesses, all on other structures or the stack
InitParam at `sp+0x41` in `kj::KJSystem` 0x197410 = InitParam+0x31). [confirmed for the listings; padding by layout]

## 3. What each patch does

### 3.1 `init_hook` + `eng60_init` (always, D1)

| location | file offset | original | new |
|---|---|---|---|
| 0x28092C in `ad::fw::TaskBase::init` | 0x18092C | `3d00d4e5` `ldrb r0, [r4, #0x3d]` | `372104eb` `bl #0x388e10` |
| 0x388E10..0x388E7F (v1) | 0x288E10 | 112 × `00` (.text page padding) | `eng60_init` + allow-list |

`eng60_init` (v1 build; the `--credits-fix` build inserts `crd60_fix` before the allow-list, the code is otherwise
identical apart from the `adr` offset):

```
eng60_init:
00388e10: 0e402de9  push {r1, r2, r3, lr}       ; 16 bytes: sp stays 8-aligned
00388e14: 0000a0e3  mov r0, #0
00388e18: 4100c4e5  strb r0, [r4, #0x41]        ; marker = 0
00388e1c: 3d00d4e5  ldrb r0, [r4, #0x3d]        ; persistent fps mode (InitParam+0x31)
00388e20: 010050e3  cmp r0, #1
00388e24: 0f00001a  bne #0x388e68               ; only 30fps tasks are candidates (r0 = mode)
00388e28: 002094e5  ldr r2, [r4]                ; vptr at init time
00388e2c: 38308fe2  add r3, pc, #0x38           ; adr r3, eng60_allow
eng60_scan:
00388e30: 041093e4  ldr r1, [r3], #4
00388e34: 000051e3  cmp r1, #0
00388e38: 0900000a  beq #0x388e64               ; end of list -> keep
00388e3c: 020051e1  cmp r1, r2
00388e40: faffff1a  bne #0x388e30
00388e44: 98edfbeb  bl #0x2844ac                ; nn::os::CTR::IsRunOnSnake()
00388e48: 000050e3  cmp r0, #0
00388e4c: 0400000a  beq #0x388e64               ; Old 3DS -> keep 30
00388e50: 0000a0e3  mov r0, #0
00388e54: 3d00c4e5  strb r0, [r4, #0x3d]        ; 60fps
00388e58: 0110a0e3  mov r1, #1
00388e5c: 4110c4e5  strb r1, [r4, #0x41]        ; marker = promoted
00388e60: 000000ea  b #0x388e68
eng60_keep:
00388e64: 3d00d4e5  ldrb r0, [r4, #0x3d]
eng60_done:
00388e68: 0e80bde8  pop {r1, r2, r3, pc}        ; r0 = mode -> init stores it to +0x45 (0x28093C)
eng60_allow:
00388e6c: 3c3b3e00  .word 0x003e3b3c            ; fld::System      RTTI N3fld6SystemE
00388e70: c4103e00  .word 0x003e10c4            ; btl::Main        RTTI N3btl4MainE
00388e74: d8eb3d00  .word 0x003debd8            ; kj::KJSystem     RTTI N2kj8KJSystemE
00388e78: 74483e00  .word 0x003e4874            ; msys::MTaskBase  RTTI N4msys9MTaskBaseE
00388e7c: 00000000  .word 0
```

The builder resolves each allow-list vptr through its type_info (vptr−4) and refuses an entry whose RTTI chain
does not contain `N2ad2fw8TaskBaseE` or whose name does not match (`--allow` names `fld,btl,kj,menu` or raw static
vptrs). `hb::HugeBattleSystem` cannot be listed: its vtable is in HugeBattle.cro, whose runtime address is not
fixed. The ENG prototype (`eng_patch.py`) differs only in the cave address (0x388C00, inside Luma's LayeredFS
payload area, rejected by D2).

### 3.2 `--credits-fix` (optional, default OFF; CRD validates the design)

Field event command 0x280, handler 0x2E8B24, sub-op 0 (confirmed, `armdis.py 3dx_v12 0x2e8b24 90`):

```
002e8b64: ldr  r1, [r0, #4]
002e8b70: ldr  r5, [r1, #0x130]            ; r5 = fld::System*
002e8b74: ldr  r4, [r0, r1]                ; r4 = allocator ([r1+0x30B0])
002e8b80: bl   0x131790                    ; Field::CreateStaffrollCtrl(r4, 0x7F) -> r0 = ctrl
002e8b90: str  r0, [r1(=0x1B3C), r5]       ; fld::System+0x1B3C = ctrl
002e8b98: bl   0x131798                    ; fld::StaffrollCtrl::init(ctrl, fld::System* r5, alloc, 0x7F)
002e8b9c: nop                              ; <-- becomes bl crd60_fix
002e8ba0: nop
002e8ba4: b    0x2e8c30                    ; -> PutRegFlag(...) with s0 = s16 = 0.0; r0-r2 reloaded there
```

`StaffrollCtrl::init` (Field.cro+0x3A8, decomp `work/fps60/decomp/3dx_v12/Field.c`) is synchronous: it stores
`this+0x10 = System*`, `this+0x14 = 0` (frame), `this+0x28 = GetParamStaffroll()+0x18` (2.0, px per `update()`),
loads and BLZ-decompresses `Staffroll.bin`, computes `this+0x24 = Σ lineHeight − 480 − P+0x14`, sets `this+0x18 = 1`.
Nothing writes +0x28 again; `update()` uses `pos = frame*speed − (P0+P4)` and `isFinish()` = `frame*speed > total`.
So after init returns, halving +0x28 when the field runs at 60 makes the scroll position a function of wall-clock
time identical to 30fps (`pos(t) = 2.0·30t − 2 = 1.0·60t − 2`), **provided `update()` runs once per field frame**.
CRD has since confirmed that from the event script (`work/fps60/credits/REPORT.md` §2, 14:34): the roll thread is
`staffroll(1); wait(1); staffroll(2); jmpif …; jump`, and `wait(1)` expires in the next frame at both steps
(1−2 and 1−1 are both ≤ 0), so `update()` runs 30×/s at 30fps and 60×/s at 60fps; everything else in the ending
room is step-scaled. The main-game roll (`zi_areanone_staffroll_01_U/L`) and Bowser Jr.'s roll
(`zo_areanone_k_staffroll_01_U/L`) both use op280, i.e. this handler, so the patch covers both. Whether the
desync is also the *crash* mechanism is CRD's §4 (WIP at the time of writing).
Parameter block `fld::GetParamStaffroll()` = 0x415E38, filled by a static initializer (decomp `static.c` line
511630): +0x00 = 1 (fade-in frames), +0x04 = 1, +0x08 = −140.0, +0x0C = 3.0, +0x10 = −2.0, +0x14 = 20.0,
+0x18 = 2.0 (speed). The 1-frame fade-in (`frame < P0`) is not scaled (it lasts 1/60 s instead of 1/30 s).
At 0x2E8B9C r0–r3, r12, lr, s0–s1 are dead (r0–r2 are reloaded at 0x2E8C34, s0 = s16 at 0x2E8C30); `crd60_fix`
touches only r0, s0, s1, flags and one float.

| location | file offset | original | new |
|---|---|---|---|
| 0x2E8B9C | 0x1E8B9C | `00f020e3` `nop` | `b28002eb` `bl #0x388e6c` (v1c) |
| 0x388E6C..0x388E9B (v1c) | 0x288E6C | zero padding | `crd60_fix` (below) |

```
crd60_fix:
00388e6c: 4500d5e5  ldrb r0, [r5, #0x45]   ; fps mode of this frame (funcInit copy of +0x3D)
00388e70: 000050e3  cmp r0, #0
00388e74: 1eff2f11  bxne lr                ; 30fps: unchanged
00388e78: 010a85e2  add r0, r5, #0x1000
00388e7c: 3c0b90e5  ldr r0, [r0, #0xb3c]   ; ctrl = fld::System+0x1B3C
00388e80: 000050e3  cmp r0, #0
00388e84: 1eff2f01  bxeq lr
00388e88: 0a0a90ed  vldr s0, [r0, #0x28]
00388e8c: 070adfed  vldr s1, [pc, #0x1c]   ; 0.5f at 0x388eb0 (VFPv2 has no vmov immediate)
00388e90: 200a20ee  vmul.f32 s0, s0, s1
00388e94: 0a0a80ed  vstr s0, [r0, #0x28]
00388e98: 1eff2fe1  bx lr
```

## 4. Loaders: what they do with code.ips / code.bps, and the D4 decision

Read from source (copies of the files in `$KIROCREW_SCRATCH/impl/src`, ported in `impl_loaders.py`):
Luma3DS `sysmodules/loader/source/{loader.c,patcher.c,bps_patcher.cpp,romfsredir.s}` at tags **v10.1**, **v13.4**
(latest release, 2026-04-02) and **master** (2026-10-25); Azahar `src/core/file_sys/{patch.cpp,ncch_container.cpp}`,
`src/core/loader/ncch.cpp` at tag **2126.1.2** (the user's build; identical to master for these files).

| | Luma3DS | Azahar |
|---|---|---|
| folder (v1.2 update installed) | `/luma/titles/00040000001CA900/` (ACI title id of the update's exheader = base id; `loader.c` uses `exhi->aci.local_caps.title_id`; measured from the update CIA) | `load/mods/00040000001CA900/` (`GetModId` strips 0x0E from the update id) |
| file names / order | `patchCode`: **code.bps, then code.ips** (then code.ups, master only) — all present files are applied, then LayeredFS | first file found wins: `exefs/code.ips`, `exefs/code.bps`, `code.ips`, `code.bps`, `sdmc/luma/titles/0004000E001CA900/code.ips`, … |
| buffer patched | decompressed .code in the mapped program memory, `size = (text+ro+data pages) << 12` = 0x2F9000 (`loader.c` `patchCode(..., mapped->total_size << 12, ...)`) | decompressed .code (0x2F9000) **plus bss pages** (`code.resize(code.size() + bss_page_size)` before `ApplyCodePatch`) = 0x336000 |
| IPS | no checksum; record past `size` or malformed file → `svcBreak(USERBREAK_ASSERT)`; master also grows the code and reads a 3-byte EOF size | no checksum; record past the buffer → `ErrorPatches` → title does not start |
| BPS | source CRC32 over `source_size` bytes and target CRC32 checked; `metadata_size` must be 0; any failure → `svcBreak(USERBREAK_PANIC)` in the loader, before the game process exists; first release with BPS: **v10.1** (commit 8233d4e226, 2019-07-08; v10.0.1 is older) | same checks; source CRC mismatch → `ErrorPatchesInvalidTitle` **before** the buffer is touched; `LoadExec` returns the error, the title does not start |
| runs after the code patch | LayeredFS: payload copied to `code + textSize` (= 0x388BD8, 0x11C bytes v10.1–v13.0.2 / 0x114 v13.1+), path string at the end of .rodata (0x3EEE50, 39 bytes), first words of `fsOpenFileDirectly`/`fsTryOpenFile` replaced by branches; failure to find the 5 FS functions → `svcBreak` | LayeredFS inside the emulator (no code change) |

**D4 decision: ship `code.bps`.** Both loaders check the source CRC32 of the whole decompressed code
(v1.2 = `BD87889C`, v1.0 = `19D8D342`) and refuse a mismatch without running patched code: Azahar refuses to boot
the title (buffer untouched, test `refuse_v10`), Luma stops in its loader with `svcBreak(USERBREAK_PANIC)` (Luma's
exception screen, reboot needed; no game code runs, nothing is written). With `code.ips` a v1.0 install (update not
installed) would be patched silently: v1.0 has `add r0, r0, #0x15c` at 0x28092C, so the game would run corrupted
code. Cost of BPS: Luma older than v10.1 (before 2020-04) ignores `code.bps` (game runs unpatched at 30fps,
LayeredFS still works); the IPS works with those but is unsafe on v1.0. One file serves both loaders when it is
placed at `<title folder>/code.bps` next to `romfs/`:
- real hardware: `SD:/luma/titles/00040000001CA900/code.bps` (Luma3DS ≥ v10.1, "Enable game patching" on — the
  Korean patch's LayeredFS already needs it);
- Azahar: `<user>/load/mods/00040000001CA900/code.bps` (the junction `→ patch/00040000001CA900` means the lead puts
  it at `patch/00040000001CA900/code.bps`; `exefs/code.bps` also works).
Never ship `code.ips` and `code.bps` together (Azahar would use only `exefs/code.ips`/`code.ips`; Luma would apply
both — harmless with identical bytes, but pointless).

## 5. Verification results (build `v1` and `v1c`, 2026-10-30) — all PASS

### 5.1 Static checks (`verify.txt`)

| check | result |
|---|---|
| symbols | `TaskBase::init` 0x28068C, `IsRunOnSnake` 0x2844AC, `isFps30` 0x25EDD0 = static.crs exports |
| original bytes | 0x280918..0x280944 (whole init tail) and, with `--credits-fix`, 0x2E8B64..0x2E8BA8 match byte for byte (abort otherwise; an accidental typo in my own expected bytes made the first `v1c` run abort, which shows the guard works); .text padding 0x388BD8..0x389000 all zero |
| exheader | update CIA: program id 0004000E001CA900, remaster v2, text 0x288BD8 (649 pages), ro 0x65E50, data 0x9170, bss 0x3CBD0, ACI title id 00040000001CA900; base CIA v1.0 text 0x288AA0 |
| decompress | `exefs2/.code` (1,913,800 B) through my port of Luma's `lzss_decompress` and of Azahar's `LZSS_Decompress` = `3dx_v12.code.bin` (0x2F9000 B); `exefs/.code` = `3dx_v10.code.bin`. So the BPS source CRC is computed over exactly what both loaders hold. |
| RO relocations | 222 static.crs relocation targets (named/indexed/anonymous imports, internal), none inside a patched byte (the RO module rewrites those at CRO link time) |
| appliers on v1.2 | Luma v10.1–v13.4 IPS, Luma master IPS, Azahar IPS, Luma BPS, Azahar BPS: result == `patched.code.bin` (Azahar: + zero bss) |
| appliers on v1.0 | BPS refused by both, buffer untouched; IPS would apply (see §4) |
| Luma LayeredFS | the 5 FS functions are found (5/5) at the same addresses before and after patching (fsOpenFileDirectly 0x114D74, fsTryOpenFile 0x28598C, fsMountArchive 0x114CB4, fsRegisterArchive 0x283098, fsUnMountArchive 0x28049C); payload 0x388BD8..0x388CF4 (worst case 0x11C), path 0x3EEE50..0x3EEE77; full chain ExeFS → LZSS → BPS → LayeredFS leaves every patched byte intact |
| Azahar chain | ExeFS → LZSS → +bss (0x336000) → `code.bps` → Success, == patched + zero bss |
| writers | self-test: IPS ×3 appliers and BPS (per-byte and range writers) ×2 appliers round-trip; bitwise Luma CRC == zlib CRC32 |

### 5.2 Cave placement and free space (D2)

- Luma payload (worst case 0x11C, Luma v10.1–v13.0.2; 0x114 since): 0x388BD8..0x388CF4. Path: 0x3EEE50..0x3EEE77.
- Cave starts at **0x388E10** (not 0x388E00): with the older 0x11C payload, 0x388E00 would leave only 0x10C bytes of
  margin, below D2's 0x110. 0x388E10 leaves 0x11C (0x124 against the current 0x114 payload) and is inside D2's
  range 0x388E00–0x388FFF.
- `v1` uses 0x388E10..0x388E80 (0x70 B), free after it: 0x180 B (0x388E80..0x389000).
- `v1c` uses 0x388E10..0x388EB4 (0xA4 B), free after it: 0x14C B.
- Keep 0x388BD8..0x388E0F free (Luma payload + margin) and do not touch .rodata 0x3EEE50..0x3EEE77.

### 5.3 Unicorn tests (`impl_emutest.py`, CPU model ARM11MPCore, VFP on)

| test | cases | result |
|---|---|---|
| A: `eng60_init` called directly; 4 allowed vptrs + Boot, TaskBase, HB analysis vptr, NULL × mode 0/1/2 × O3DS/N3DS; the game's real `IsRunOnSnake` through its cached path | 48 | PASS: promoted (+0x3D = 0, +0x41 = 1, r0 = 0) exactly for allowed mode-1 tasks on New 3DS; otherwise +0x3D unchanged, +0x41 = 0, r0 = mode; r1–r11 and sp preserved; `IsRunOnSnake` entered only for allowed mode-1 tasks, with sp % 8 == 0; no memory written except the stack, +0x3D, +0x41 |
| B: `TaskBase::init` tail 0x280918 → `pop` with a fake 40-byte frame, patched vs original image; allowed + Boot × mode 0/1 × O3DS/N3DS × +0x3E 0/1 | 40 | PASS: +0x44 = +0x3C, +0x46 = 1, +0x4A = 1/3, +0x378 = 0, r3–r11 and sp after return identical to the original; the only differences are +0x41 and, when promoted, +0x3D/+0x45 = 0 |
| C (`v1c`): 0x2E8B9C → 0x2E8BA4 with fld::System+0x45 ∈ {0,1}, ctrl present / NULL | 4 | PASS: +0x28 2.0 → 1.0 only for mode 0 with a ctrl; r4–r11, s16, s31 preserved; the original image (nop) leaves 2.0 |

### 5.4 Do the tests catch a broken cave? (mutation run, scratch `mutate.py`, 2026-10-30)

Each mutation was applied to the `v1c` image in memory and the unicorn suite re-run; all six were detected:

| mutation | caught by |
|---|---|
| M1 `push/pop {r1,r2,lr/pc}` (12 bytes, sp misaligned) | A (sp % 8 inside IsRunOnSnake) |
| M2 `bl IsRunOnSnake` → `mov r0,#1` (no New-3DS test) | A (promoted on O3DS) |
| M3 `pop {r0,r2,r3,pc}` (r1 lost, r0 wrong) | A (registers, return value) |
| M4 hook reverted to `ldrb r0,[r4,#0x3d]` | B (not promoted) |
| M5 credits factor 0.25 | C |
| M6 marker stored to +0x42 | A (+0x41 / stray write) |

## 6. What RT2 should run in wave 3 (I did not run the emulator, R4)

Install for a test: copy **only** `work/fps60/build/v1/code.bps` into the test mod folder
(`<test user>/load/mods/00040000001CA900/code.bps`, next to `romfs/`), with the Korean `romfs/` as today
(RT2's `use-build v1`). Do not copy `code.ips` as well.

| # | scene / setting | expected (build `v1`) | how |
|---|---|---|---|
| 1 | boot, Azahar log | `File …/mods/00040000001CA900/code.bps patching code.bin` (LOG_INFO Service_FS) and the usual LayeredFS lines; game boots | instance log |
| 2 | title screen (current task `[0x3F40B4]` = fld::System 0x320DA370) | **no runtime write**: +0x3D = 0, +0x41 = 1, +0x45 = 0; +0x578 ≈ 60/s; `App: 60 FPS` | `rt_measure.py task`, status bar |
| 3 | mode / file select, pause menu, shop, save (MTaskBase-derived) | +0x3D = 0, +0x41 = 1, 60 FPS | census per scene |
| 4 | field after loading a save | fld::System +0x3D = 0, +0x41 = 1; field step `fld::System+0x1A4C` = 1.0 from the first frame (2.0 unpatched); walking speed and event timing unchanged in wall-clock time | read the float at task+0x1A4C |
| 5 | battle | btl::Main +0x3D = 0, +0x41 = 1, 60 FPS (action-command windows are BTL2's issue) | census |
| 6 | Bowser Jr.'s Journey | kj::KJSystem +0x3D = 0, +0x41 = 1 | census |
| 7 | giant battle | hb::HugeBattleSystem +0x3D = 1, +0x41 = 0 (not promoted, ≤ 30 FPS as unpatched) | census |
| 8 | Boot task (if caught) | +0x3D = 0, +0x41 = 0 (already 60, not touched) | census |
| 9 | Azahar "New 3DS mode" OFF (O3DS) | every task +0x41 = 0, +0x3D = 1, 30 FPS, behaviour identical to unpatched | A/B |
| 10 | `v1c` only: staff roll (CRD test bed) | ctrl = `[fld::System+0x1B3C]`, ctrl+0x28 = 1.0 (2.0 unpatched or at 30); roll length in seconds equals the 30fps one (CRD's numbers); compare against the end-roll BGM | read the float; stopwatch |
| 11 | (optional) negative test | `code.bps` against a v1.0-only install: Azahar refuses to boot with a patch error (`ErrorPatchesInvalidTitle`) | only if a v1.0-only instance is at hand |

Real hardware (user, later): Luma3DS ≥ v10.1 with "Enable game patching"; `SD:/luma/titles/00040000001CA900/`
holding `code.bps` and the Korean `romfs/`; the v1.2 update installed. On an Old 3DS the patch does nothing.

## 7. Evidence on the lead's decisions (no re-litigation, only what I found)

- D1: consistent. AUD (`audit_fps_sites.md` §4) lists 0x28092C as the initial copy and finds no CRO that reads a
  task's +0x3D/+0x45; ENG/MOD: nothing rewrites +0x3D after `init` for the allowed classes. My unicorn test B shows
  the hook changes nothing else in `init`.
- D2: the cave is at 0x388E10, not 0x388E00 (§5.2): Luma v10.1–v13.0.2 copy a 0x11C-byte LayeredFS payload (the
  extra two words were removed later), so 0x388E00 would leave 0x10C < 0x110 bytes of margin. Executability on
  hardware (ENG open question 1) follows from the same page: Luma's LayeredFS payload at 0x388BD8 is executed from
  this page on every RomFS file open, and Azahar maps `text.num_max_pages × 0x1000` = up to 0x389000 as code.
- D4: decided for `code.bps` (§4). Note for the lead: the patch/SD/ZIP file count grows from 36 to 37.
- D5: no CRO edit is needed by IMPL; RO relocation targets do not touch the static patch (§5.1).

## 8. Open questions

1. What Luma3DS shows on `svcBreak(USERBREAK_PANIC)` inside the loader (a v1.0 install with our `code.bps`):
   expected Luma's ARM11 exception screen; not observed on hardware.
2. `IsRunOnSnake`'s first call is an APT IPC; the game already calls it at boot (0x104060) and in GPU setup
   (0x114148 …), so the cache is very likely filled before the first allowed `init` (likely, not traced).
3. The credits fix restores the scroll timing; CRD/RT2 must show whether the 60fps credits crash goes away with it.
4. `hb::HugeBattleSystem` cannot be allow-listed by vptr (CRO address); if HB is ever opted in, compare a static
   vtable slot or the HB `func` override instead.

## 9. Summary

- Changed: new `scripts/fps60/build_fps60.py`, `impl_loaders.py`, `impl_emutest.py`, `impl_exheader.py`;
  builds `work/fps60/build/v1/` (default) and `v1c/` (`--credits-fix`); `unicorn` 2.1.4 installed in `.venv`.
- To verify: RT2 list in §6 (items 2–9 with `v1`, item 10 with `v1c`).
- Left: lead installs `v1/code.bps` (or `v1c`) as `patch/00040000001CA900/code.bps`; CRD's crash verdict decides
  whether `--credits-fix` becomes default.



---

# Wave 3 (worker IMPL3): build `v2` / `v2n` — credits fix + field VM at 30 Hz (FLD Option A, F1–F4)

Status: **COMPLETE** (2026-10-30). `v2` and `v2n` pass every check (§13); hashes §14; runtime list §14.1.
Design source: `work/fps60/analysis/field60.md` §6.1 / §7 (F1–F4), `work/fps60/BRIEF3.md` §IMPL3.
Tags owned by IMPL3: `v2` (= init hook + `--credits-fix` + `--field-vm30` + copy of the BAI fix) and `v2n`
(= the same without `--field-vm30`, for the runtime A/B comparison). `v1`, `v1c`, `v1cb`, `bai` are untouched.

## 10. Re-verification of the FLD claims used by `--field-vm30` (BRIEF3 IMPL3 item 1)

### 10.1 Vtables and slot targets (confirmed: the builder's RTTI/original-word checks, `armdis.py --callers`)

| vtable (address point) | RTTI | +0x20 | +0x2C | +0x34 |
|---|---|---|---|---|
| 0x3E1784 (file 0x2E1784) | `N3fld11EventSystemE` (ti 0x3D5A24) | 0x002B81A8 @ 0x3E17A4 | 0x002E225C @ 0x3E17B0 | 0x002A8AF0 @ 0x3E17B8 |
| 0x3E303C (file 0x2E303C) | `N3fld19ResidentEventSystemE` (ti 0x3D602C) | 0x002B81A8 @ 0x3E305C | 0x002E225C @ 0x3E3068 | 0x002D9914 @ 0x3E3070 |

Both have 14 slots (+0x38 = 0, then the next type_info). The RTTI scan of all type_infos finds only these two
classes derived from `fld::EventSystemBase` / `fld::EventSystemBaseImplementCommand`; no other vtable (static or
any linked CRO image) contains the four targets (`armdis.py --callers`: only the four vtable words; no direct
`b/bl`, no CRO veneer). The two vtables are installed only by: EventSystem — `fld::MainBase::vfunc_0x40` 0x312B18
(heap, `Main+0x14FC`); ResidentEventSystem — FUN_00303C84 (heap, `fld::System+0x1ACC`) and FUN_00305D3C (stack,
one-shot init). (literal pools 0x31319C, 0x3041F4, 0x305E88; the other literal hits are the destructors).

### 10.2 Every path that reaches slots +0x20 / +0x2C / +0x34 (confirmed)

Slot +0x34 (`GlobalEvent+0x14 = step`, s0 = step, r0 = this):
- `fld::MainBase::vfunc_0x14` 0x30FDC0 (EventSystem, s0 = `[[Main+0x130]+0x1A4C]`), then tail call `b 0x2B9218`.
- FUN_0020DCB0 0x20DE0C and FUN_0020E02C 0x20E1CC (ResidentEventSystem, s0 = `[sys+0x1A4C]`).

Slot +0x20 (exec one LocalEvent: r0 = event system, r1 = LocalEvent):

| caller | object | LocalEvent | return value used? |
|---|---|---|---|
| `EventSystem::vfunc_0x28` 0x2A8B80 (7-slot loop) | heap ES | `this+0x254+i*0x8B8` (heap) | no (`add r4,#1`; loop) |
| `ResidentEventSystem::vfunc_0x28` 0x2D9998 (1 slot) | heap RES | `this+0x130` (heap) | no |
| FUN_002B9218 0x2B93E8 (tail of `MainBase::vfunc_0x14`: per-object `.fme` loop, `obj->vt[0x2C]() != 0`) | heap ES | `obj+0x1C` (heap) | no (`add r4,#1`) |
| FUN_00305D3C 0x305E58 (one-shot field init script) | **stack** RES at `sp` | `sp+0x130` (**stack**) | no |
| FUN_00227538 0x2275C0 (one-shot object script: callers 0x2AAE1C `_break`, 0x2B8720, 0x2B8C58, 0x2B8D1C, 0x2B8F44) | heap ES | **stack** `sp+0x18` | (r0 passed through, Ghidra: void) |
| FUN_002B8634 (per-object one-shot scripts from `MainBase::vfunc_0x88` 0x3198FC) | heap ES | **stack** (`auStack_8e0`) | (void) |

The vt+0x28 loop functions return the last slot-+0x20 result in r0; their callers discard it (0x2B938C, 0x20DE20,
0x20E1E0: next instruction overwrites r0).

**Correction to FLD §6.1 P2:** FLD tests only `this` against sp. FUN_00227538 and FUN_002B8634 run a script
**synchronously on a stack LocalEvent with the heap EventSystem as `this`** (the LocalEvent is destroyed when they
return). Gating them on odd frames would silently drop those one-shot scripts (e.g. a breakable object's `_break`
script). `--field-vm30` therefore never gates a call whose **LocalEvent (r1) or `this` (r0)** lies in
`[sp, sp+0x8000)` (0x8000 = exheader main-thread stack size; all field events run on the main thread inside
`TaskBase::func` → `fld::System::vfunc_0x18`). The real event systems and their LocalEvents are heap objects
(operator new from field allocators), never within 32 KB above sp.

Slot +0x2C (system variable read, `float f(EventSystem*, GlobalEvent*, LocalEvent*, id)`): reached only through
`fld::GlobalEvent::vfunc_0x18` 0x2A8D54 (`owner = GlobalEvent+0x18; bx owner->vt[0x2C]`, owner set by the
systems' vt+8 init 0x2A8BF8 / 0x2D9A10), which `GetRegFlag` 0x2762CC calls for ids 0x7xxx (case 7:
`ge->vt[0x18](ge, le, id)`). Float result in s0 is returned to GetRegFlag's caller.

### 10.3 Input structures (confirmed; answers FLD open question 2)

- Pad struct `P = *(fld::System+0x1B00)` (9 words), refilled at the top of every `fld::System::vfunc_0x18`
  (0x306BC4, the task's calc): `P[0..4] = gBtn+0..+0x10` (hold, prev, **trg +8**, **rls +0xC**, rep +0x10),
  `P[5..8]` sticks; zeroed when `sys+0x6E0` bits 2|4 are not both set. `Btn::update` 0x10409C (main loop
  0x101980, once per frame): `trg = cur & ~prev`, `rls = prev & ~cur`.
- Touch struct `T = *(fld::System+0x1B08)`: `T+8` low bits copied from gTp+8 (0x423938), written by
  `Tp::update` 0x103CA4: bit0 touching, bit1 previous, **bit2 touch-down edge**, **bit3 touch-up edge**,
  bit4 repeat pulse, bit5 changed; `fld::System::vfunc_0x18` then overwrites bit1 with its own previous bit0.
  Zeroed when `sys+0x6E0` bits 8|0x10 are not both set.
- Sysvar reads (0x2E225C): `$7037..$703A` = P+0/+8/+0xC/+0x10; `$702F..$7032` via FUN_002221EC = the same P
  words masked by the party mask and OR'ed with forced input `Main+0x2FB0/+0x2FB4`; `$7041` = 2 (bit2), 3 (bit3),
  4 (bit0), else 1; `$7042/$7043` = T x/y. **`$703B/$703C` are not edge sets**: they read `Main+0x2F80` /
  `Main+0x2F98`, the button-enable masks of the two 0x18-byte input-control slots (init 0xFFFFFFFF by
  FUN_002087F4 / FUN_0030A29C, ANDed into the party mask by FUN_0036065C, written by the field command
  FUN_002EB7DC as `~v & 0xDFFB`). No latch is needed for them.
- Script use (`fld_fev.py var`): `$7038` 195, `$7037` 34, `$7041` 44, `$7030` 13, `$702F`/`$7031`/`$7039` 10 each,
  `$703C` 3, `$703B` 1, `$703A` (rep) 1 (`o_evselect_U`, event-select room), `$7032` 0. Repeat pulses are
  therefore not latched.

### 10.4 Frame counter for parity (confirmed)

`fld::System` uses `ad::fw::TaskBase::func` 0x13DBCC (vtable slot 0 = 0x13DBC8, a `nop` that falls into it).
`func` calls vt+0x18 (`fld::System::vfunc_0x18`, which refills P/T and runs the field state machine and both
event systems), then draws, and increments `this+0x578` **once, as its last statement, on every path**
(0x13E76C label). So every slot +0x20 and +0x2C call made by the field VM inside one frame sees the same
`fld::System+0x578`, and consecutive frames alternate parity. The wrappers read `fld::System` as
`[[this+4]+0x130]`, the same path the game's own sysvar reader uses for both classes (`this+4` = the Main set by
vt+8 init, e.g. `*(sys+0x80C)` for the resident system), after the stack test and with NULL checks.


## 11. RW latch location (BRIEF3 IMPL3 item 2) — 0x434F00..0x434F0F

Tool: `scripts/fps60/impl_rwscan.py` (read-only; exit 0 = no reference reaches the range).
`.venv\Scripts\python.exe scripts\fps60\impl_rwscan.py --lo 0x434D40 --hi 0x435000` → `RESULT: no reference
reaches the latch range`.

| check | result |
|---|---|
| mapping | bss = 0x3F8170..0x434D40 (data 0x3EF000 + 0x9170, bss 0x3CBD0). Luma: `rw_size_total = ceil((data.size + bss) / 0x1000)` = 70 pages → RW 0x3EF000..**0x435000**. Azahar: code+data pages + page-rounded bss → RW 0x3EF000..0x436000. The whole tail 0x434D40..0x434FFF is mapped RW in both. **confirmed** (exheader numbers from the update CIA; loader formulas as ported in `impl_loaders.py`/§4) |
| zero at start | the crt0 clear loop at 0x100024 (`r0 = [0x100040] = 0x3F8170`, `r1 = [0x100044] = 0x434D40`, `strlo r2,[r0],#4` while `r0 < r1`) stops at 0x434D3C, so the tail is not cleared by the game; it is zero because the loader gives zeroed bss pages (Azahar: `code.resize(+bss pages)` with zeros; hardware: freshly allocated codeset pages, **likely** zero — RT3 reads 0x434D40..0x435000 at runtime). A zero latch can never be used (see §12: tag 0 would need frame 1, which is odd). |
| literal words | every aligned word in [0x433D40, 0x435000) in the static image and in all 15 relocated CRO images: 165 possible pointers; the only one into the tail is the crt0 bound 0x434D40 (exclusive). 5 CRO words with such values are not relocations (identical bytes in the raw CRO files, e.g. HugeBattle 0x129C7CE0 = `00 43 4F 00` inside a string table) — a CRO can hold a static address only where the RO module writes a relocation |
| accesses | 738 immediate-offset accesses through those literals (straight-line scan after each `ldr rX,[pc,#d]`): highest effective address **0x434D3C** (guard bytes at 0x434D34..0x434D3F written at 0x2A7508). 33 `ldm/stm/vldm/vstm` forms bounded by hand: every one stays inside its object (e.g. MTX34 identity 0x434C88 + 0x30, MTX44 identity 0x434CB8 + 0x40, `sort_inv_view_base` 0x434D04 + 0x30 = 0x434D34) |
| movw/movt | 0 cond-AL `movw/movt` words in any text range (ARMv6K has none), no `movt #0x43` |
| last bss objects | `nn::math` statics VEC3 One 0x434C3C, VEC3 Zero 0x434C48, VEC4 Zero 0x434C54, MTX34 Identity 0x434C88, MTX44 Identity 0x434CB8, `CalcSortCameraForRemillionOrtho::calc` statics 0x434CF8 / 0x434D04 (+ guards to 0x434D40) |
| heap / stacks | main-thread stack 0x0FFF8000..0x10000000 (exheader stack size 0x8000), app heap 0x08000000+, linear heap 0x14000000/0x30000000+ (runtime: `fld::System` 0x320DA370): none is adjacent to 0x434D40..0x435000 |

Chosen latch: **0x434F00..0x434F0F** (16 bytes, 0x1C0 above the bss end, same page): `+0 trg`, `+4 rls`,
`+8 touch edge bits`, `+0xC frame tag`. Luma's LayeredFS payload lives in .text padding (0x388BD8) and .rodata
padding (0x3EEE50) only (§4), not in bss.


## 12. `--field-vm30` patches (F1–F4) — build `v2`

Build commands (each run with a timeout; ~2–4 min each, the unicorn suites dominate):

```
.venv\Scripts\python.exe scripts\fps60\build_fps60.py --tag v2  --credits-fix --field-vm30 --with-bai
.venv\Scripts\python.exe scripts\fps60\build_fps60.py --tag v2n --credits-fix --with-bai
.venv\Scripts\python.exe scripts\fps60\impl_mutate.py        # mutation run of the F1-F3 tests (read-only)
.venv\Scripts\python.exe scripts\fps60\impl_rwscan.py        # latch-region proof (read-only)
```

New/changed files: `build_fps60.py` (`--field-vm30`, `--with-bai`, `--out`; refuses to overwrite `v1`, `v1c`,
`v1cb`, `bai`), `impl_emufld.py` (F1–F3 unicorn suite), `impl_mutate.py`, `impl_rwscan.py`; `impl_emutest.py`
runs its credits test only when `crd60_fix` is really installed.

| # | location | file offset | original | new | why |
|---|---|---|---|---|---|
| D1 | 0x28092C `TaskBase::init` | 0x18092C | `3d00d4e5` ldrb r0,[r4,#0x3d] | `372104eb` bl 0x388E10 | init hook (unchanged from v1) |
| F1 | 0x3E17B8 EventSystem +0x34 | 0x2E17B8 | `f08a2a00` .word 0x2A8AF0 | `808e3800` .word 0x388E80 `fld60_step_es` | event step ×2 under G |
| F1 | 0x3E3070 ResidentEventSystem +0x34 | 0x2E3070 | `14992d00` .word 0x2D9914 | `888e3800` .word 0x388E88 `fld60_step_res` | same |
| F2 | 0x3E17A4 EventSystem +0x20 | 0x2E17A4 | `a8812b00` .word 0x2B81A8 | `b48e3800` .word 0x388EB4 `fld60_exec` | scripts on even frames only |
| F2 | 0x3E305C ResidentEventSystem +0x20 | 0x2E305C | `a8812b00` .word 0x2B81A8 | `b48e3800` .word 0x388EB4 `fld60_exec` | same |
| F3 | 0x3E17B0 EventSystem +0x2C | 0x2E17B0 | `5c222e00` .word 0x2E225C | `308f3800` .word 0x388F30 `fld60_sysvar` | latched edges for script input reads |
| F3 | 0x3E3068 ResidentEventSystem +0x2C | 0x2E3068 | `5c222e00` .word 0x2E225C | `308f3800` .word 0x388F30 `fld60_sysvar` | same |
| cave | 0x388E10..0x388FEC | 0x288E10 | 0x1DC zero bytes | `eng60_init` + allow-list (0x388E10..0x388E80, byte-identical to v1) + F1–F3 (0x388E80..0x388FEC) | |
| F4 | 0x434F00..0x434F0F (RW, not in the patch) | — | zero | {trg, rls, touch bits 2..5, frame tag} at runtime | §11 |

G = `fld::System+0x45 == 0` with `fld::System = [[this+4]+0x130]` (NULL → no gate). Frame = `fld::System+0x578`.
**Cave usage: 0x1DC of 0x1F0 bytes (0x388E10..0x388FEC), 0x14 bytes free** (v1 part 0x70, F1 0x34+8,
F2 0x7C, F3 0xB0, latch literal 4). Any further cave code (e.g. F6 key repeat) needs another location.
`v2` patched image vs `v1`: differs only in 0x388E80..0x388FEC and the six vtable words (diff checked).

```
fld60_step_es:                         ; F1, slot +0x34 (r0 = event system, s0 = field step)
00388e80: 58c19fe5  ldr ip, [pc, #0x158]      ; = 0x2A8AF0
00388e84: 000000ea  b #0x388e8c
fld60_step_res:
00388e88: 54c19fe5  ldr ip, [pc, #0x154]      ; = 0x2D9914
fld60_step:
00388e8c: 041090e5  ldr r1, [r0, #4]          ; Main
00388e90: 000051e3  cmp r1, #0
00388e94: 1cff2f01  bxeq ip
00388e98: 301191e5  ldr r1, [r1, #0x130]      ; fld::System
00388e9c: 000051e3  cmp r1, #0
00388ea0: 1cff2f01  bxeq ip
00388ea4: 4510d1e5  ldrb r1, [r1, #0x45]
00388ea8: 000051e3  cmp r1, #0
00388eac: 000a300e  vaddeq.f32 s0, s0, s0      ; G: step x2 (exact; VFPv2, no vmov immediate)
00388eb0: 1cff2fe1  bx ip                      ; original(r0, s0)
fld60_exec:                            ; F2, slot +0x20 (r0 = event system, r1 = LocalEvent)
00388eb4: 0dc041e0  sub ip, r1, sp
00388eb8: 02095ce3  cmp ip, #0x8000
00388ebc: b9bcfc3a  blo #0x2b81a8              ; LocalEvent on the stack: one-shot run, never gated
00388ec0: 04c090e5  ldr ip, [r0, #4]
00388ec4: 00005ce3  cmp ip, #0
00388ec8: b6bcfc0a  beq #0x2b81a8
00388ecc: 30c19ce5  ldr ip, [ip, #0x130]
00388ed0: 00005ce3  cmp ip, #0
00388ed4: b3bcfc0a  beq #0x2b81a8
00388ed8: 4520dce5  ldrb r2, [ip, #0x45]
00388edc: 000052e3  cmp r2, #0
00388ee0: b0bcfc1a  bne #0x2b81a8              ; G false: original, r0/r1/sp/lr intact
00388ee4: 78259ce5  ldr r2, [ip, #0x578]
00388ee8: 010012e3  tst r2, #1
00388eec: adbcfc0a  beq #0x2b81a8              ; even frame: run
00388ef0: f0309fe5  ldr r3, [pc, #0xf0]       ; = 0x434F00 latch
00388ef4: 0c2083e5  str r2, [r3, #0xc]        ; tag = odd frame number
00388ef8: 01ca8ce2  add ip, ip, #0x1000
00388efc: 000b9ce5  ldr r0, [ip, #0xb00]      ; P
00388f00: 082090e5  ldr r2, [r0, #8]
00388f04: 002083e5  str r2, [r3]              ; latch.trg
00388f08: 0c2090e5  ldr r2, [r0, #0xc]
00388f0c: 042083e5  str r2, [r3, #4]          ; latch.rls
00388f10: 080b9ce5  ldr r0, [ip, #0xb08]      ; T
00388f14: 082090e5  ldr r2, [r0, #8]
00388f18: 3c2002e2  and r2, r2, #0x3c
00388f1c: 082083e5  str r2, [r3, #8]          ; latch.touch
00388f20: 140891e5  ldr r0, [r1, #0x814]
00388f24: 8002a0e1  lsl r0, r0, #5
00388f28: 200fa0e1  lsr r0, r0, #0x1e          ; = (x & 0x7FFFFFF) >> 25, the original's early-out value
00388f2c: 1eff2fe1  bx lr
fld60_sysvar:                          ; F3, slot +0x2C (r0 = sys, r1 = GlobalEvent, r2 = LocalEvent, r3 = id)
00388f30: 07ca43e2  sub ip, r3, #0x7000
00388f34: 2fc04ce2  sub ip, ip, #0x2f
00388f38: 12005ce3  cmp ip, #0x12
00388f3c: c664fd8a  bhi #0x2e225c              ; only $702F..$7041
00388f40..00388f54: Main / fld::System NULL checks -> b 0x2E225C
00388f58: f0412de9  push {r4, r5, r6, r7, r8, lr}   ; 24 B, sp stays 8-aligned
00388f5c..00388f84: G, even frame, latch.tag == frame-1, else -> fld60_sv_plain
00388f88..00388fc0: r6 = P, r7 = T; save P.trg (r4), P.rls (r8), T+8 (r5); store them OR latch
00388fc4: a464fdeb  bl #0x2e225c                ; original, r0-r3 intact
00388fc8..00388fd0: str r4/r8/r5 back (exact restore; s0 = result untouched)
00388fd4: f081bde8  pop {r4, r5, r6, r7, r8, pc}
fld60_sv_plain:
00388fd8: f041bde8  pop {r4, r5, r6, r7, r8, lr}
00388fdc: 9e64fdea  b #0x2e225c                 ; tail call, r0-r3/sp/lr intact
00388fe0: .word 0x002a8af0 / 00388fe4: .word 0x002d9914 / 00388fe8: .word 0x00434f00
```
(Full listing with every word: `work/fps60/build/v2/verify.txt`.)

AAPCS: F1/F2 use only r0–r3, ip and flags (F1 touches s0 only under G, by design); F3 saves r4–r8/lr, keeps
sp 8-aligned at the call, uses no VFP register; no `vmov` immediate. With G false every wrapper reaches the
original with the original arguments (F2's r2/r3 are not arguments of 0x2B81A8: its prologue writes r2 before
reading it). Behaviour then equals the original image (unicorn A/B, §13).

**Credits in `v2`:** `--credits-fix` is given but `crd60_fix` is not installed. `fld::StaffrollCtrl::update`
(Field.cro) is reached only through the static stub 0x1317A0, whose only caller is 0x2E8BB8 (field command 0x280
sub-op 1, a VM command; `armdis --callers` and the builder's own branch scan). Under `--field-vm30` the roll
thread `update(); wait(1)` runs on VM ticks, 30 per second as at 30fps, so the 2.0 px/update speed is already
right; halving it as in `v1c` would make the roll take twice as long. `v2n` (VM at 60) keeps `crd60_fix`.
The builder records this in `verify.txt` (`[credits_by_vm]`) and `manifest.json` (`credits`).

## 13. Test results (`v2`, `v2n`, 2026-10-30) — all PASS

| check | v2 | v2n | detail |
|---|---|---|---|
| IMPL wave-2 checks (selftest, exheader, decompress, ro_relocs, apply_v12, refuse_v10, luma_layeredfs, azahar_chain, cave) | PASS | PASS | as §5.1; the six vtable words are not RO relocation targets and do not touch Luma's payload/path |
| emu A / B (eng60_init, TaskBase::init tail) | PASS 48 / 40 | PASS 48 / 40 | unchanged code |
| emu C (crd60_fix) | not installed | PASS 4 | |
| fieldvm_slots | PASS | — | six slots → wrappers, RTTI of both vtables unchanged |
| latch | PASS | — | `impl_rwscan.py` on 0x434F00..0x434F10 |
| stack_window | PASS | — | 0x8000 = exheader stack size |
| credits_by_vm | PASS | — | update stub called only from 0x2E8BB8; 0x2E8B9C still `nop` |
| emu F1 | PASS 54 | — | both vtables, real originals: GlobalEvent+0x14 = 2·step only under G; else equal to the unpatched image; r4–r11, s16–s31, sp kept; only GE+0x14 written |
| emu F2 | PASS 235 | — | skipped exactly for non-stack LocalEvent + G + odd frame (latch = {trg, rls, touch&0x3C, frame}, r0 = status, only the 16 latch bytes written); LocalEvent at sp+0x18 / +0x130 / +0x7FFC and the stack ResidentEventSystem never gated, sp+0x8000 and sp−4 gated; otherwise original entered with r0/r1/sp/lr intact, nothing written; skip status == the unpatched original's early-out return for inactive LocalEvents |
| emu F3 | PASS 780 | — | 13 ids × mode × 5 frame/tag combinations × NULL variants × 2 vtables: latch OR'ed into P.trg/P.rls/T+8 during the call exactly for $702F..$7041 + G + even + tag == frame−1 (call sp = entry−24, 8-aligned), restored afterwards; else tail call with r0–r3/sp/lr intact, structs untouched; s0 passed through |
| emu F23 | PASS 10 | — | real originals: A pressed only on an odd (skipped) frame → next even frame `$7038` = 1.0, `$7039` own release = 1.0, touch-down latched → `$7041` = 2.0; P/T restored; next odd frame 0.0; stale latch 0.0; 30fps 0.0; unpatched image gives the same live values |
| bai | PASS | PASS | `romfs/BAI/BAI.dat` sha256 asserted = `c681a963…fbb6` |
| mutation run (`impl_mutate.py`) | 15/15 caught | — | M1 vaddne, M2 no Main NULL check, M3 no stack test, M4 stack window 0x10, M5 parity inverted, M6 latch field swapped, M7 wrong status, M8 gate on +0x44, M9 id filter to $7042, M10 no stale check, M11 no restore, M12 rls not OR'ed, M13 r8 not saved, M14 parity from +0x57C, M15 slot not redirected |
| regression | — | — | the modified builder rebuilt `v1` and `v1c` into scratch byte-identical (code.bps/code.ips/patched.code.bin); `v2n` code.bps == `v1c` code.bps |
| independent | PASS | PASS | `lead_check_build.py`: IPS == patched.code.bin, BPS source/target/patch CRCs consistent |

## 14. Outputs and hashes (2026-10-30)

| tag | flags | code.bps | code.ips | patched.code.bin | romfs |
|---|---|---|---|---|---|
| `v2` | `--credits-fix --field-vm30 --with-bai` (credits covered by the VM) | 559 B `c3922b9dcaafb5edacee2eda93ae13bd4c49f49c256495fbc456baf19a405be2` | 552 B `e5aa7d60686a9129508600e0a43f4391290dd09e9a9661db1c9de1d3b05d998a` | `4bd714f2a5f68337ae8966f263ce59b6e9415c9a0c968d1daea68e6ed5d7a7e2` (CRC32 3C84ACB4) | `BAI/BAI.dat` 2,862,076 B `c681a963b8428128a2d9133c39911f9f2acf5a53e83dff0a097de8fbe750fbb6` |
| `v2n` | `--credits-fix --with-bai` (= `v1c` code) | 215 B `ec4189b9f1cbbdc1d8147779b1b9cd5a17197eab6efc8cd3f8b656327fc2c0c6` | 195 B `780dd5d20d564358e8c00376e894abab47a45a16fca07d1bcc1112ab56d545e2` | `aa197f118f9288bec8b0adc1c04dc0d10974ef2e7b20b051db4ee6942763f61b` (CRC32 96F1502B) | same BAI.dat |

Input `3dx_v12.code.bin` CRC32 BD87889C. `manifest.json` / `verify.txt` hashes change per build (timestamp).
Install for RT3 (`rt_mods.py use-build v2` / `v2n`): `code.bps` + `romfs/BAI/BAI.dat` over the Korean romfs; never
`code.ips` next to `code.bps`.

### 14.1 What RT3 should look at with `v2` vs `v2n` (I did not run the emulator)

1. Latch at runtime: in the field, 0x434F0C (tag) holds an odd frame number that advances by 2 while events run;
   0x434F00..0x434F0B follow the pad/touch edges of odd frames (all zero when nothing is pressed).
2. FLD §8 items 1–4 and 6: minigame cursor ≈180 px/s in `v2` (≈360 in `v2n`), `i_power_arm_02` beats in sync,
   gimmick timers at 30fps length, every 1-frame A tap registers in `v2`, room entry init scripts run.
3. One-shot scripts (new finding, §10.2): hit breakable objects / `?` blocks and room-entry object scripts on
   many frames; their effects (items, flags, sounds) must appear every time in `v2`.
4. Credits (test bed A): `v2` roll length = the 30fps one with `crd60_fix` absent; `v2n` with `crd60_fix`.
5. Known limits of Option A to watch in the A/B: script-driven motion updates at 30 Hz (as shipped at 30fps);
   only pad/touch edges are latched, so a one-frame C++→script pulse other than input would be invisible to
   scripts on odd frames, and a script value held for one VM tick is seen by 60 Hz C++ code for two frames.
   No such case is known; report any event that fails only in `v2`.
6. Old 3DS / 30fps (`is_new_3ds=false`): G is false, behaviour equals the unpatched game.


RT3's credits runs (`runtime/findings.md` §7.2–§7.4) confirm the model behind the `v2` credits decision: one
`update()` per frame, 29.91/s stock and 59.8/s with `v1` (roll 205.8 s vs 102.9 s); under `--field-vm30` the
roll thread runs on 30-per-second VM ticks, so it needs no speed change.

## 15. Summary (IMPL3)

- Changed: `scripts/fps60/build_fps60.py` (`--field-vm30`, `--with-bai`, `--out`, fixed-tag guard),
  new `impl_emufld.py`, `impl_mutate.py`, `impl_rwscan.py`; `impl_emutest.py` (credits test only when installed).
  Builds `work/fps60/build/v2/` and `v2n/` (code.bps, code.ips, patched.code.bin, manifest.json, verify.txt,
  romfs/BAI/BAI.dat). `v1`, `v1c`, `v1cb`, `bai` untouched (rebuilt only into scratch for the regression check).
- Deviations from the FLD design, with evidence: the stack test is on the **LocalEvent** (FUN_00227538 and
  FUN_002B8634 run one-shot scripts on a stack LocalEvent with the heap EventSystem, §10.2); `crd60_fix` is not
  installed in `v2` (§12); repeat pulses (`$703A`/`$7032`, 1 use in a test room) are not latched (§10.3).
- To verify at runtime: §14.1 (RT3 A/B `v2` vs `v2n`), plus RT3's planned read of 0x434D40..0x435000.
- Left: the lead decides whether `v2` replaces `v1cb` in `patch/`; the cave has 0x14 bytes left, so F6 (key
  repeat) or any further cave code needs another location.
