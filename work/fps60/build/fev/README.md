# FEV — FLD Option B fallback: FEvent.dat `wait(1)` → `wait(2)` (wave 3)

Worker FEV, 2026-10-30. Brief: `work/fps60/BRIEF3.md` § FEV; design: `work/fps60/analysis/field60.md` §2, §4, §6.2.
Status: **complete** — `identity`, `build`, `verify` pass; FLD open question 4 answered (§5: no, the step never
drops below 2.0 at 30fps, so Option B is behaviour-identical at 30fps). Output sha256 `2e117581…5e72`.

## 0. Inputs (facts)

- Source: `romf2/FEvent/FEvent.dat` = `lib3dx.romfs_path('FEvent/FEvent.dat')` (v1.2 update), 6,395,308 bytes,
  sha256 `a0fecd0fc48ecf8c63df2498bfe233a35d6c89001fe7d7d1e99a939141bd40aa`. (v1.0 `romfs/FEvent/FEvent.dat` is
  6,395,200 bytes, sha256 `cf586598…b85d`, not used.) The Korean patch ships no `FEvent/`
  (`patch/00040000001CA900/romfs/` = `.crr FMdl HB Lyt Msg Obj RO Staffroll`), so R2 does not apply.
- Site list: `python scripts/fps60/fld_fev.py waitsites` → 136 sites in 90 entries; not patched: the edge-reading
  loop `i_areanone_puzzle_02_U.fev 0x655–0x79D` (hold + trg) and every `*_test_*` room.
- BG4 facts (measured by `identity`): version 261, 1,428 slots, data-start 0xB66C, 854 BLZ-compressed `.fev`/`.fme`,
  574 empty `.fme` slots, no uncompressed stored entry, data packed contiguously (no padding, no tail), names block
  ends with 0xFF padding. **The table order is not the storage order and every empty slot shares its offset with
  the next stored entry**, so `lib3dx.bg4_layout`/`rebuild_bg4` reject this file ("entry #1301 is not
  contiguous (0xC1E8 != 0xC3C0)": stable sort by offset puts a stored entry before the empty `resident.fme`).
  `fev_build.py` therefore has its own writer (`assemble`): order = (offset, size ≠ 0, slot), contiguous packing,
  header/names copied, only the low 31 bits of offset/size words rewritten. `lib3dx` is not changed.

## 1. Tool and commands

`scripts/fps60/fev_build.py` (owned by FEV). Each run takes 8–12 s; start it with a timeout, e.g.
```
$p = Start-Process .venv\Scripts\python.exe -ArgumentList scripts\fps60\fev_build.py,identity -PassThru -NoNewWindow `
     -RedirectStandardOutput $env:KIROCREW_SCRATCH\fev_id.txt -RedirectStandardError $env:KIROCREW_SCRATCH\fev_id.err
$p.WaitForExit(900000)
```
| command | does |
|---|---|
| `identity [--codec-all]` | parse BG4 (cross-checked with `lib3dx.read_bg4`), check the packing, decompress all 854 BLZ entries with lib3dx **and** a strict in-place decompressor, decode every script with FLD's decoder, rebuild with zero changes 3 ways, BLZ round-trip sample |
| `sites` | the live site list (`fld_fev.main(["waitsites"])` in-process) with the loop each site belongs to |
| `build [--out DIR]` | apply exactly that list (refuses unless 136 sites / 90 entries), u16 1 → 2, re-compress only changed entries; writes `DIR/romfs/FEvent/FEvent.dat`, `diff.tsv`, `manifest.json`, `sites.txt` (raw waitsites output) |
| `verify [FILE]` | re-read FILE (default the build output), prove the claims in §3, check `manifest.json` |
| `audit` | per site loop: inputs read in the body and in subroutines it calls (`audit_loops.tsv`, §4) |

Each site is checked before patching: bytes `05 00 00 00 00 00 01 00` (`wait(1)`, mask 0, op005 has one 2-byte
parameter in the descriptor table 0x3A0874), on FLD's decoded control flow, inside a loop that `waitsites` patches,
parameter offset = instruction + 6.

## 2. Results

`identity` (exit 0, 11.5 s):
```
BG4 v261 slots 1428 data_start 0xb66c; parse == lib3dx.read_bg4: True
packing: contiguous in (offset, non-empty, slot) order, no gap/overlap/tail: ok
stored compressed 854, stored plain 0, empty 574
BLZ: all 854 decompress in place (strict) == lib3dx, plain total 22057195 bytes
FLD decoder: 854 scripts decoded, 1162910 instructions
zero-change rebuild byte-identical: assemble({}) True, assemble(all slots re-stored) True, build with all 136 sites set 1 -> 1 True
ndspy BLZ round trip + in-place check ok for 22 entries (0 byte-identical to the original)
```
(ndspy never reproduces the original compressor's bytes, so only the 90 changed entries are re-compressed.)

`build` (exit 0, 10.9 s) → `work/fps60/build/fev/romfs/FEvent/FEvent.dat`, **6,394,504 bytes, sha256
`2e1175813e7627002d499d0a8accbe2a5221bba72b2c73158bdb6eff343a5e72`** (−804 bytes: the 90 re-compressed entries are
smaller). 136 sites in 90 entries; 1,338 of 1,428 slots byte-identical.

`verify` (exit 0, 7.6 s):
```
sites 136 (list: 136 wait(1) sites in 90 entries ...); entries changed 90, slots byte-identical 1338 of 1428; strict in-place BLZ ok for 90 changed entries
decoded 854 entries / 1162910 instructions in both files: same layout, only the listed wait parameters differ (1 -> 2)
output re-assembles to itself: True; manifest consistent: True
VERIFY OK
```
`identity --codec-all` (42 s): ndspy BLZ round trip + strict in-place check ok for **all 854** entries (none
byte-identical to the original compressor's output).

## 3. What `verify` proves (and that it can fail)

`compare()` raises on any of: different header (magic, version, count, data-start, word +12) or names block;
any slot whose flags, name hash or name offset differ; output not packed contiguously in the original storage
order; an unchanged slot that is listed, or a changed slot that is not; a changed slot whose decompressed bytes
(lib3dx **and** the strict in-place decompressor) are not the source plain bytes with exactly the listed u16
parameters 1 → 2; a byte difference anywhere except the low byte of those parameters; any of the 854 scripts
decoding (FLD's flow decoder) to a different instruction list (offset, opcode, mask, result, parameter count), or
any instruction differing except a listed `wait(1)` → `wait(2)`. It also re-runs the site list live and checks the
manifest hashes and the site-list hash.

Negative tests (scratch script, mutated copies of the output; all rejected, baseline accepted):

| mutation | rejected with |
|---|---|
| one listed site reverted to `wait(1)` (entry re-compressed) | `i_air_08.fme: plain data != source plain with the listed parameters` |
| an extra `wait(1)` → `wait(2)` in an unlisted entry | `i_metaboru_09.fev: changed but has no listed site` |
| one byte of the names block | `BG4 header word +12 or names block differs` |
| one other byte in a listed entry | `i_air_08.fme: plain data != source plain with the listed parameters` |
| the unpatched source itself | `i_energy_07.fme: listed entry unchanged` |

## 4. Site set and input audit (`fev_build.py audit` → `audit_loops.tsv`)

- 136 sites = 60 in 31 `.fev` + 76 in 59 `.fme`; 130 distinct loops (`diff.tsv` gives each site's loop range,
  counters, compares and input variables). Minigame rooms: `i_power_arm_02` 7, `i_power_hip_SA_adorena_01_L` 7,
  `i_power_nose_SA_peppansy_01_L` 7, `o_peach_3f_15_SA_fire_packun_01_U` 8, `o_peach_t_SA_fire_dkoopa_01_U` 3,
  `i_power_stomach_15_SA_giganin_01_L` 2, `i_power_lungs_SA_fire_01_L` 1, `o_ekubon_15_SA_giganin_01_U` 1.
- A loop polled every 2nd frame at 60fps would miss one-frame pulses. Checked (confirmed in data and code):
  - input variables in the 130 loop bodies: only `hold` (state) in `i_tainai_01` 0x5CC0; no trigger, release,
    repeat or touch-edge variable (`fld_fev.INPUT`) — `waitsites` already excluded the one edge loop;
  - subroutines called from the loops (`jump(1, …)`, followed transitively to return): no input variable at all;
  - the 46 field commands used in the loops and their callees (op050 … op27F): the 39 with a Ghidra function read
    neither the pad struct `*(fld::System+0x1B00)`, the touch struct `+0x1B08`, `gBtn` 0x4238xx, nor the party
    input FUN_002221EC (decomp text, callees to depth 2); the 7 without one (op05D 0x2DE4A8, op08F 0x2E031C, op0AA
    0x2E3814, op0AB 0x2E389C, op161 0x2DFD50, op19E 0x2ED64C, op1F0 0x2DF27C) were read in the listing: object
    parameter setters (stores into actor fields), no input;
  - the 20 VM base ops used (op002 … op037; table 0x389918 + 8·op): call/stack bookkeeping, compare, random
    (`RandSys::get`), table lookup, trig, bit ops (results via `PutRegFlag`); none reads input (decomp for 12,
    listing for op002/006/008/01B/01C/01D/01F/022).
  ⇒ no patched loop reads a one-frame input pulse. **Not covered**: pulses between scripts or from C++ that last
  one frame (a flag set and cleared by another script within one iteration); none was looked for.
- 8 loops also contain `wait($var)`: `i_metaboru_02/06/08/11/13` (61-instruction loops; in `_02`, `$3000 =
  rand(3)·20 + 40`), `i_power_arm_02` 0x6F68 (beat catch-up `$4005 − $4006`), `i_power_hip_SA_adorena_01_L` 0x87BA
  (`$401E` from a table, `$300B = $401E / 2`), `i_power_nose_SA_peppansy_01_L` 0xBEEB (`$400D`). These are delays
  in 60 Hz units (exact at 60fps, rounded up to whole 30fps frames at 30), not per-frame counts; unchanged by B.

## 5. FLD open question 4 — can the step drop below 2.0 at 30fps? **No** (confirmed)

Why it matters: `wait(n)` (handler 0x133EC4: `ldr r0,[r2,#8]; cmp r0,#0; beq ret; vcvt.f32.s32; vstr s0,[r1,#0x28];
r0 = 3`) overwrites `LocalEvent+0x28 = (float)n` (no carry-over) and yields; `execLocalEvent` does `t -= step`
each later frame and resumes **in the same frame** when `t <= 0`:
```
0025bfc4: vldr     s1, [pc, #0x218]  ; =0.0
0025bfc8: vldr     s0, [r0, #0x28]   ; remaining wait
0025bfcc: vcmpe.f32 s0, s1
0025bfd4: ble      #0x25bffc         ; nothing pending: run the script
0025bfd8: vldr     s2, [r7, #0x14]   ; event step (GlobalEvent+0x14)
0025bfdc: vsub.f32 s0, s0, s2
0025bfe0: vstr     s0, [r0, #0x28]
0025bfe4: vcmpe.f32 s0, s1
0025bff0: vstrle   s1, [r0, #0x28]   ; t <= 0: clear and fall through to 0x25bffc (run this frame)
0025bff4: movgt    r0, #3            ; t > 0: still waiting
0025bff8: bgt      #0x25c1dc
```
So `wait(n)` lasts ceil(n/step) frames (≥ 1); `wait(1)` ≡ `wait(2)` exactly when step ≥ 2.0 (2.0 − 2.0 = 0.0 ≤ 0).

Writers of the factors of `fld::System+0x1A4C = (isFps30 ? 2 : 1) × [[sys+0x574]+0x7C] × sys+0x1A48`, found by two
independent scans of the whole game (static + all 15 CROs): decomp text (`*.c`, expressions `0x574) + 0x7c)`,
`0x1a48)`, `0x412c80`) and `scripts/fps60/fev_q4.py scan` (register-tracking scan of every ARM listing for stores
to `[x+0x1A48]`, `[[x+0x574]+0x7C]`, `[0x412C80]`, `[x+0x1A4C]`). Both give the same 11 stores, all in static code:

| factor | store | value | function |
|---|---|---|---|
| game speed `[[t+0x574]+0x7C]` | 0x1EAD48 `vstrne s16` | 1.0 (0x1EAD34) | FUN_001EAAF0 (battle, `[0x3F3600]` = btl::Main) |
| | 0x302C5C `vstr s18` | 1.0 (0x302C54) | field init FUN_00302A64 |
| | 0x31EE54 `vstr s16` | 1.0 | fast-forward controller FUN_0031EC90, "off" branch |
| ffwd `sys+0x1A48` | 0x302C60 `vstr s18` | 1.0 | field init |
| | 0x31EE58 `vstr s16` | 1.0 | FUN_0031EC90 "off" |
| | 0x31ED34 `str r0` | `[0x412C80]` | FUN_0031EC90 "on" (fast-forward active) |
| `[0x412C80]` | 0x3670AC `vstr s0` | 2.0 | static initializer (decomp: `DAT_00412c80 = 0x40000000`); only other ref = the read at 0x31ED28 |
| step `sys+0x1A4C` | 0x302C94, 0x30709C, 0x31ED60, 0x31EE7C | (2\|1) × gs × ffwd | init, `funcCalc` tail, FUN_0031EC90 ×2 |

- No script command writes either factor. The only command that reaches them is **op270** (`_CmdFuncTbl`, handler
  FUN_002E7E28): it sets `fld::System+0x1AC5` (fast-forward allowed = param ≠ 0) and calls FUN_0031EC90 once.
  FUN_0031EC90 (callers: `fld::System::funcCalc` 0x306BC4 and op270) switches between game speed 1.0 / ffwd 1.0 and
  ffwd `[0x412C80]` = 2.0 while R (pad hold bit 8, `**(sys+0x1B00) >> 8 & 1`) or the on-screen skip is active.
- op270 is used 317 times in 206 entries; **19 of the 90 changed entries use it** (7 of the 8 minigame rooms — all
  but `o_peach_t_SA_fire_dkoopa_01_U` — plus `i_tainai_01`, `o_ekubon_07_2`, `o_gepu_03`, `o_gepu_05_after`,
  `o_koopa_19/26/27/28`, `o_peach_3f_10`, `o_peach_g_16`, `o_town_04/32`), as `op270(1)` … `op270(0)` around
  their cutscenes.
- ⇒ at 30fps the field step is 2.0, or 4.0 while fast-forward is held; never below 2.0. `wait(1)` and `wait(2)` are
  the same one frame in every state of the shipped game, so the FEvent.dat of Option B is behaviour-identical at
  30fps (Old 3DS, or a task not promoted by D1). The EUR community "game speed" cheat writes `0x320DBDB8` =
  fld::System 0x320DA370 + **0x1A48** (0.5 = slow); only such a cheat can make the step < 2.0.
- Side note (not a 30fps issue): at 60fps with fast-forward held the step is 2.0, so `wait(2)` lasts one frame and the
  patched loops run at 60 Hz, i.e. 2× like the rest of the fast-forwarded scene. At 30fps fast-forward could not
  speed these loops up (`wait(1)` is already one frame). Option A keeps the 30fps-ffwd behaviour instead.

## 6. Loader facts (for D4/D5)

- The game opens `rom2:/FEvent/FEvent.dat` (UTF-16 path at 0x3EE774), i.e. from the **update** RomFS, like
  `rom2:/RO/*.cro`, `rom2:/.crr/static.crr` and `rom2:/FMdl/$R$/FMdl.dat`, which the Korean patch already replaces.
  Luma3DS LayeredFS redirects the update mount too: `patchLayeredFs` (sysmodules/loader/source/patcher.c, master,
  read 2026-10-30) searches the code for `"\0" + {"ro2:", "rom2:", "rex:", "patch:", "ext:"}` and passes the first
  hit to the payload as the update mount; 3DX has the ASCII string `rom2:` after a zero byte at 0x103A28. Azahar
  applies `romfs/` to the base and the update RomFS (web.md §5.1). So `romfs/FEvent/FEvent.dat` in the mod folder
  is picked up by both (Azahar: same path class as the patch's MainMenu.cro/static.crr, seen in RT2's log; Luma:
  from source, not tested on hardware).
- The field opens its 13 archives through one table at 0x3A4A80 ({UTF-16 path, flags}; FEvent.dat flags 0x12, same
  as FMdl.dat, FMapMdl.dat, FMapInfo.dat, FLyt.dat, FMsg.dat) with `ad::fw::FileContext::InitJob` (FUN_003021A0,
  called from the field init FUN_00302A64 at 0x302C18: `pJob+0x10 = &DAT_003a4a80`, `+0x14 = 0xD`). The Korean patch ships rebuilt BG4 files of the same loader class
  (`FMdl/JP/FMdl.dat` 15,993,792 vs 16,018,524 bytes, `Lyt/JP/FLyt.dat`, `Msg/JP_ja/FMsg.dat`) whose entry offsets
  and sizes differ from the originals and they load, so these archives are read through their BG4 table (likely;
  RT confirms by playing a patched room). The re-compressed entries are in-place-safe BLZ (checked).

## 7. Install and runtime test (lead / RT3 — FEV did not run the emulator)

Files in `work/fps60/build/fev/`: `romfs/FEvent/FEvent.dat` (the only payload), `diff.tsv` (136 rows: entry, slot,
instruction/parameter offset, old/new bytes, loop range, counters, compares, inputs), `manifest.json` (hashes,
the 90 changed entries with old/new stored size and plain sha256), `sites.txt` (raw `fld_fev.py waitsites`
output the build used), `audit_loops.tsv` (§4).

- **Install** (lead): copy `romfs/FEvent/FEvent.dat` to `<mods>/00040000001CA900/romfs/FEvent/FEvent.dat` (Luma
  `/luma/titles/00040000001CA900/romfs/FEvent/FEvent.dat`, Azahar `load/mods/00040000001CA900/romfs/FEvent/
  FEvent.dat`). No code, CRO or CRR change goes with it. It only has an effect when `fld::System` runs at 60fps
  (D1 allow-list); with Option A (IMPL3 `--field-vm30`) it is redundant but harmless (one VM tick = step 2.0 ⇒
  `wait(2)` = `wait(1)` = one tick).
- **Test build** (lead, W1: FEV creates no other tag): e.g. `python scripts/fps60/lead_compose.py v1cbf --code v1c
  --overlay work/fps60/build/bai/romfs --overlay work/fps60/build/fev/romfs`, then RT: emulator stopped,
  `rt_mods.py use-build v1cbf`; back with `rt_mods.py use-patch`.
- **Runtime checks** (scene → expected observation):
  1. Load: the instance log lists `LayeredFS replacement file in use for /FEvent/FEvent.dat`; title → file
     select → field and two room changes work; event scripts run (NPC talk, door).
  2. Hip minigame `i_power_hip_SA_adorena_01_L` (TB test bed T3), 60fps: the aiming cursor moves ≈180 px/s with
     the stick held (6 px per 33 ms), as at 30fps; countdowns and the 180-unit timer last as long as at 30fps;
     without this file ≈360 px/s.
  3. Rhythm `i_power_arm_02` at 60fps: beats stay in sync with the music for the whole song.
  4. A room gimmick, e.g. `o_peach_2f_07` (`$300B −= 2` per iteration) or `i_energy_*` (stand-on timer
     `$3001` to 10): reaction delay equal to 30fps.
  5. Old 3DS / 30fps (`is_new_3ds=false` or the stock code): same as without the file (byte-identical behaviour
     proved in §5; a quick play of check 2 is enough).
  6. Fast-forward (hold R) in a cutscene of a changed room at 60fps, e.g. `o_town_04`: scene runs 2× (§5 side note).

## 8. Patch-point table

| ID | location | original | new | why | side effects |
|---|---|---|---|---|---|
| F5 | `romfs/FEvent/FEvent.dat` (romf2 v1.2 source), 136 u16 `wait` parameters at instruction+6 in 90 entries (`diff.tsv`) | `05 00 00 00 00 00 01 00` `wait(1)` | `05 00 00 00 00 00 02 00` `wait(2)` | detected frame-timer loops iterate every 33 ms at 60fps, as at 30fps | none at 30fps (step ≥ 2.0 always, §5); 6.39 MB file in the mod romfs; 90 entries re-compressed (−804 bytes) |

## 9. Limits and open points

- B fixes only the 130 detected loops (FLD §4.3: counters in subroutines, `wait($var)` = 1 at runtime, unrolled
  sequences and moves done by command arguments are not covered); the edge-reading hold-scroll loop of
  `i_areanone_puzzle_02_U` 0x655–0x79D stays 2× fast at 60fps. Option A covers all of them.
- At 60fps a patched loop runs on every 2nd frame, so its visible updates (cursor, meters) are 30 Hz, as shipped.
- One-frame pulses exchanged between scripts (or set by C++ for one frame) were not analysed (§4).
- The BG4-table loading of FEvent.dat is inferred from the same loader class (§6), not observed: RT check 1.
