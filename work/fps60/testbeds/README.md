# TB — test beds for the 60fps runtime tests (battles, BAI hold attack, Bowser-body minigames)

Worker TB, wave 3, 2026-10-30. Status: **complete** — T1, T2, T3 built and verified (`tb_build.py verify` → OK);
T3b (rhythm) and T4 (Bowser Jr.'s Journey) not built (§6). Runtime items are predictions for RT (§5).
Inputs: BRIEF.md §1–5, BRIEF2.md §0–1, BRIEF3.md §0/§2/TB, `credits/REPORT.md` §1/§6/§7, `analysis/field60.md`
§2/§4, `analysis/battle.md` §7–§10, `runtime/findings.md` §6.
Confidence: **confirmed** (read in code/data), **likely**, **guess**. Nothing here was run in the emulator
(RT3 owns it); every runtime expectation is a prediction for RT.
Tools (read-only on their inputs): `scripts/fps60/tb_fev.py` (queries), `scripts/fps60/tb_build.py` (build/verify,
install/remove for RT, §3–§4). Outputs only under `work/fps60/testbeds/`.

## 1. How a field script starts a battle (confirmed)

- Field op **0x240** (handler `FUN_002E0038`, descriptor `[u8 actor, u8, u8, u8, u8 encount, u8, u32 str scene,
  u32 str bg, u8, u32 bgm, u16, u16, u8]`) = scripted battle start. It calls `FUN_00303580(fld::System, 1, …)`,
  which fills `btl::GetBootInfo()` (+0x00 = battle **scene script name** `scn_*.bai`, +0x30 = background name,
  empty → default per map from 0x3A52C0/0x3A52C4; +0xC0 BGM id; +0xC8.. encount/entry-effect bytes) and calls
  `ad::Encount::startLoadRes`. The party is the one of the actor in p0 (`*(u8*)(*(actor+4)+0x134)`; party 1 gives
  encount anim type 3, likely Bowser). The handler returns 3 (yield) with no rewind, so the script resumes after
  the battle. String params are **absolute .fev buffer offsets** (the handler adds the buffer base
  `param_3[1]`/`[0]`). p1 is not read by the handler.
- The only other caller of `FUN_00303580` is `FUN_0030482C` (field enemy contact, from 0x2B8864): the scene
  name comes from the enemy object (+0x162C), i.e. from the room's `.fme` enemy list (`scn_pch_00.bai` …).
- Every battle is a BAI **scene script** `scn_<area>_<n>.bai` (BAI.dat has 214 of them, 89 `mon_*`, 240 `atk_*`) that
  loads the enemy models `bm_*` and monster AIs `mon_*.bai`; a monster AI loads its attacks `atk_*_<n>.bai` (op069).
- 40 op240 uses in FEvent.dat (`tb_fev.py rawbattles`; 33 sit in cutscene threads that FLD's flow decoder does
  not reach because they are started by op052/op06b offsets).

Fixed hold attacks (BTL2 §7) → monster → scene → where the story starts it (confirmed by string references; the
party column is likely, from the actor in p0 and the scene contents):

| attack | monster AI | scene script | started by | party |
|---|---|---|---|---|
| `atk_dstar_4` | `mon_dstar.bai` (Dark Star) | `scn_air_boss.bai` | `i_air_21.fev` +0xB0BD op240(0, 4, 0, 2, 0, 3, "scn_air_boss.bai", "", 2, 0x1000357, 100, 100, 1) | Mario & Luigi (inside Bowser) |
| `atk_koopa2_2` | `mon_koopa2.bai` (Bowser) | `scn_Twn_boss.bai` | `o_town_34_suishou_01_U.fev` +0x52C8 op240(0, 8, 0, 2, 0, 3, "scn_Twn_boss.bai", "", 2, 0x1000356, 100, 100, 1) | Mario & Luigi |
| `atk_dgeraco_5` | `mon_dgeraco.bai` (Dark Fawful) | `scn_pch_boss_01.bai` (final battle, with Dark Bowser) | `o_peach_t_06.fev` +0x403A op240(2, 4, …, 0x1000359, …) | Bowser, then M&L |
| `atk_dstar_x_4` | `mon_dstar_x.bai` | `scn_challenge_6.bai` | not referenced by FEvent.dat (started elsewhere) | M&L |
| `atk_koopax_2` | `mon_koopax.bai` | `scn_challenge_7.bai` | not referenced by FEvent.dat (started elsewhere) | M&L |

`mon_koopa2` picks from tables at 9700 (phase 0: [1],[3],[1],[1],[3]) and 9720 (phase 1: [3,2],[1,4],[1,3],[3,2],
[1,4],[1,2,3]) and forces attack 2 once when phase ≥ 1 and `$70d5 == 0` (0x2ECA..0x2F1E); `$70d0` is not written in
`mon_koopa2` itself. So stock Bowser also uses its hold attack only later in the fight.


## 2. Facts used by the test beds (confirmed unless marked)

- **Variable storage** (`GetRegFlag` 0x2762CC, `gGameWork` = 0x3F95F0, 0x28C0 bytes = the first 0x28C0 bytes of
  `ML3R_00n.sav`, copied in by `Backup::readSaveData2` 0x339778): `$Cn` = bit (n & 31) of u32 at 0x3F99A8 + 4·(n >> 5)
  (save offset 0x3B8 + 4·(n >> 5)); `$Bn` = byte 0x3F9AA8 + n (save 0x4B8 + n); `$Dn`/`$En` bits at 0x3F97FC/0x3F9888;
  `$An` u32 at 0x3F9B38 + 4n; `$5n`/`$6n` (0x3FBEB0/0x3FBEF0) lie after gGameWork = not saved.
- **jmpif** (base op 3, 0x1338BC → `GlobalEvent::Cmp` 0x27307C): jump to the target when `Cmp(kind, a, b) == expect`;
  kinds 0 `==`, 1 `!=`, 2 `<`, 3 `>`, 4 `<=`, 5 `>=`, 6 `a & b != 0`.
- **AI script frames** (`GetRegFlag` case 8): `$8000..$800F` = arguments (caller frame), `$8010..$801F` = locals of the
  current call depth (`LocalEvent+0x7F8`), `$8020+` = per-thread return values. A subroutine does not clobber the
  caller's `$8010`.
- **Room entry**: the room start (0x310CDC..0x310CFC) runs the `.fev` script whose index is `u32 [.fev+0]` (default
  entry) unless the room-change request carries an entry override (`req+0x18 != 0xFFFF`, only for the `.fev`; the
  `.fme` always uses its default). The story's own warps into the test rooms use the default entry
  (`i_power_hip_01.fev` +0x3DFD `op18a(0x86, 0f, 0f, 0f, 0, 0, 0x1a, 3, 0)`: 0x1A = 26 = default of room 0x86).
  A **save load is assumed to use the default entry** (same assumption as CRD variant B; RT3's credits run with
  CRD variant A will show it — likely).
- Slot-1 save (test instance, sha256 `43c2ca72…d7cb`): upper room 0x24D `o_peach_t_04`, lower room 0xA8
  `i_tainai_01` (room block file+0x297C: u16 +2 upper, +4 lower). Flags read from the file: `$C396 = 1`,
  `$C397 = 1`, `$C398..$C39C = 0`, `$C39D = 1`, `$B07E = 0`, `$C49A = 1`, `$C2F4 = 1`, `$C133 = 1`.

### 2.1 Choices (and why)
- **T1/T2 = FEvent variant on the save's lower room** `i_tainai_01.fev` (Mario & Luigi's screen; actor 0 = Mario is
  created by its entry script, `op082(0, 0)` at 0x3C0C): the room's three arrival entries (#53, #54, #55 = default;
  #53/#54 set `$7078` = 3/4 and fall into #55) are redirected to appended wrappers
  `call <original entry>; wait(0x3c); op240(<exact copy of a story battle start>); return(0f)`. The original entry
  still builds the room; the battle starts 1 s (60 Hz units) after it returns. The op240 bytes are copied from the
  story room byte for byte; only its two string operands (absolute buffer offsets) are moved to copies of the same
  strings appended after the wrapper. `call`, `wait`, `return` are byte copies of instructions already in the room.
  No save change, no story flag change. A save redirect cannot do this: every battle start sits in a cutscene that
  the late-game flags skip.
- **T1 scene**: `scn_meta_05.bai` (enemy `mon_juicy`, ordinary Metabolism enemy; not the `_tuto` variant) from
  `i_metaboru_06.fev` +0xE83F `op240(0, 7, 0, 1, 0, 3, "scn_meta_05.bai", "", 2, 0x1000352, 100, 100, 1)`
  (BGM 0x1000352 = the normal battle theme of event battles).
- **T2 attack**: `atk_dstar_4` (Dark Star, `scn_air_boss.bai`, from `i_air_21.fev` +0xB0BD). It has both fixed parts:
  the hold grace (0x3454) and the orbit loop (0x2F7C). Dark Star picks attacks from four pattern tables in
  `mon_dstar.bai` (`$8014` = table at 18280/18300 in phase `$70d0` = 0, 18312/18332 in phases 1–2; row `$70d1`,
  column `$8016`, read by subroutine 0x3416 with op011; 0 = no further attack this turn):
  phase 0 both bros up [1],[2],[3],[1],[2,3]; one bro down [4],[3],[2]; phase ≥ 1 [4,1],[3,2],[1,4],[2,1],[3,4] /
  [4,2],[3,4],[4,2],[3,2],[3,4]. So stock Dark Star never uses attack 4 in phase 0 while both bros stand.
  Test-only change: every nonzero entry of the four tables → 4 (`mon_dstar.bai` plain +0x476A..+0x47AA, 21 bytes
  changed, data only). Built twice: on the BAI-fixed file (`build/bai`, sha256 `c681a963…fbb6`) and on the original
  v1.0 file (sha256 `12be16cd…c2f2`), so fix / no-fix runs differ only in BTL2's 15 sites.
- **T3 = save redirect** of the lower room 0xA8 → 0x86 `i_power_hip_SA_adorena_01_L` (1 byte, file +0x2980). With this save the
  room's own logic reaches the minigame: entry #26 → `call #27` (0x338C); #27: `$C396 == 1` (yes) and `$B07E >= 4`
  (no, 0 = DX relief counter) → normal path → `op06b(1, 0x3B0A, 4)` moves the **upper** screen to 0xA9
  `i_tainai_SA_adorena_01_U` (entry 3) itself, screen handshake `$C35B/$C35C` → 0x36CA `$C396 == 1` → call #69
  0xB26C → `op052(4, 0, 0x8A97)` (Mario's loop #55), `op052(5, 0, 0x8D34)` (Luigi's #56), `op052(0x21, 0, 0xAE4F)`.
  The upper room is left as saved (the story reaches the minigame from the garden the same way).
- `i_power_arm_02` (rhythm) is **not** built: its beat loop #35 is started by #33 (BGM by tempo, `op052(0x13, 0,
  0x6A31)`), called from #38, which only `op052(0xe, 0, 0x6C7D)` at +0x5D3E/+0x6632 start (interaction scripts, not
  the entry). The story enters the room from `i_tainai_01` +0x5EC1 `op18a(0x82, 470f, 108f, 0f, 0xc, 1, -1, 3, 0)`.
  A redirect would put the bros in the room but the minigame needs an in-room interaction (not traced).


## 3. Built and verified files (`tb_build.py build` / `verify` → `VERIFY OK`)

| bed | file (under `work/fps60/testbeds/`) | sha256 | size | differs from its source only in |
|---|---|---|---|---|
| T1 | `t1_battle/romfs/FEvent/FEvent.dat` | `4113131346705c5f…972c74` | 6,410,112 | table slot 955 (`i_tainai_01.fev`: 4 raw bytes; entry appended at the end); plain entry: 3 table words (#53/#54/#55) + 228 B appended |
| T2 | `t2_hold/romfs/FEvent/FEvent.dat` | `2d5b0a3b6edab9cd…84219b` | 6,410,116 | same, op240 of `scn_air_boss.bai`, +231 B |
| T2 | `t2_hold/romfs/BAI/BAI.dat` (BAI fix + forced pattern) | `9ea3e4731940…de04467` | 2,862,000 | `mon_dstar.bai` plain, 21 bytes (pattern tables) |
| T2 | `t2_hold/romfs_nofix/BAI/BAI.dat` (original + forced pattern) | `1ee8bd60cc87…ebfff77` | 2,862,172 | same 21 bytes |
| T3 | `t3_minigame/save/ML3R_001.sav` | `bfa48f829543…517668f` | 75,968 | 1 byte, +0x2980: 0xA8 → 0x86 (lower room) |

Sources (sha256-checked on every build): FEvent.dat = romf2 v1.2 original `a0fecd0f…40aa` (not the patch, not FEV's
build), BAI.dat `12be16cd…c2f2` (romfs v1.0) / `c681a963…fbb6` (`build/bai`), save `43c2ca72…d7cb` (copy kept in
`_source/ML3R_001.sav`). Full hashes, offsets and template bytes: `MANIFEST.json`.

What `verify` checks (all passed): FEvent — same 1,428 names/flags/hashes, the original file is a byte prefix of the
output except slot 955's offset/size words, only `i_tainai_01.fev` decompresses differently, its original bytes are
kept except the 3 entry-table words, each wrapper decodes as `jump(1, <first instruction of the original entry>)`,
`wait(0x3c)`, `op240`, `return(0f)`; the op240 equals the story instruction byte for byte except its two string
operands, which point at byte copies of the story's strings right after the wrapper. BAI — same 543 entries and
header/name block, 542 stored entries byte-identical, only `mon_dstar.bai` differs, exactly the 21 table bytes, all
→ 4, re-forcing the base gives the output; the four table references (`$8014 = op015(18280f…18332f)` at
0x50EB/0x5102/0x513D/0x5154/0x518F/0x51A6) decode as expected; `atk_dstar_4.bai` stored bytes equal the base file's
(fixed resp. original). Save — only +0x2980 differs, rooms upper 0x24D / lower 0x86.

Wrappers (T1; T2 identical apart from the string length):
```
#53 -> 0xB95E: jump(1, 0x3A39) | wait(0x3c) | op240(0, 7, 0, 1, 0, 3, "scn_meta_05.bai", "", 2, 0x1000352, 100, 100, 1) | return(0f)
#54 -> 0xB9AA: jump(1, 0x3A50) | …same…
#55 -> 0xB9F6: jump(1, 0x3A67) | …same…            (#55 = default entry)
templates copied from the room: call +0xF0B `04 00 00000000 01 36100000`, wait +0x9C29 `05 00 00000000 3c00`,
return +0x25C `01 00 00000000 00000000`
```
VM semantics used (static code): op004 kind 1 pushes the return pc (`LocalEvent+0x38[idx]`, idx = `+0x2D >> 4`) and
depth `+0x7F8`; op001 pops it when idx != 0 (else ends the thread, returns 2) and stores its operand in `+0x7FC`
(`$8020`). `wait(n)` yields until `n − Σstep ≤ 0`.

## 4. Install / remove (RT, emulator stopped; `.venv\Scripts\python.exe`, Start-Process + WaitForExit ≤ 120 s)

`tb_build.py install|remove` refuses while azahar.exe runs, writes only into the real folder
`tools/azahar-test/mods_builds/<TAG>/romfs/` that the mods junction points at (made by `rt_mods.py use-build <TAG>`;
backups in `mods_builds/<TAG>.tb_backup/`, `*.absent` markers for new files) or into the test save folder
(backup `ML3R_001.sav.tb_orig`; install refuses unless the live save is the original 43c2…). Never `patch/`,
never the junction to `patch/`, never `%APPDATA%\Azahar`.

| bed | install | remove | log proof after boot |
|---|---|---|---|
| T1 | `rt_mods.py use-build v1cb --replace`, then `tb_build.py install t1_battle --tag v1cb` | `tb_build.py remove t1_battle --tag v1cb` (or `rt_mods.py use-build v1cb --replace`, or `use-patch`) | `LayeredFS replacement file in use for /FEvent/FEvent.dat` and `/BAI/BAI.dat` |
| T2 fix | `rt_mods.py use-build v1cb --replace`, `tb_build.py install t2_hold --tag v1cb` | `tb_build.py remove t2_hold --tag v1cb` | `/FEvent/FEvent.dat`, `/BAI/BAI.dat` |
| T2 no fix | `rt_mods.py use-build v1 --replace`, `tb_build.py install t2_hold --tag v1 --variant nofix` | `tb_build.py remove t2_hold --tag v1` | same |
| T2 30fps ref. | `rt_mods.py use-build smoke --empty-ok --replace`, `tb_build.py install t2_hold --tag smoke [--variant nofix]` | `tb_build.py remove t2_hold --tag smoke` | same, no `ApplyCodePatch` line |
| T3 | any code build (`use-build v2` = Option A, `v2n` = none, a build with FEV's FEvent.dat = Option B, `smoke` = 30fps), then `tb_build.py install t3_minigame` | `tb_build.py remove t3_minigame` (restores 43c2…, deletes the backup) | none needed (save file) |

Manual equivalent for T3 (like CRD §7): copy `$d\ML3R_001.sav` → `ML3R_001.sav.tb_orig` (hash must be 43C2CA72…),
copy `work\fps60\testbeds\t3_minigame\save\ML3R_001.sav` over it (hash BFA48F82…); remove = copy the backup back and
re-check 43C2CA72…. T3 can be combined with T1/T2 only by accident: do not (it moves Mario & Luigi out of
`i_tainai_01`). If CRD's credits save is installed (`ML3R_001.sav.crd_orig` exists), restore it first.

## 5. What RT should see and do (predictions; nothing here was run)

Common path: boot → title → 「게임 시작」 → slot 1 → 「시작하기」 → 「마리오&루이지 RPG3」 (RT2 §6.2–§6.4). The field starts in
the saved rooms (upper `o_peach_t_04` Bowser, lower `i_tainai_01` Mario & Luigi).

**T1 (ordinary battle).** ≈1 s after the lower field has faded in (wrapper `wait(0x3c)` after the room's own entry),
the battle transition starts on Mario & Luigi's side: Mario & Luigi vs `mon_juicy` (scn_meta_05), event-battle
theme 0x1000352. Record: `[0x3F3600]` = btl::Main, its +0x3D/+0x41/+0x45 (expect 0/1/0 with v1cb), `+0xBA15C` = 1.0
(2.0 with `smoke`), `Main+0x8A3C` and `[[Main+0x574]+0x7C]` = 1.0, App 60 FPS, enemy turns and a jump attack with the
usual Excellent timing, back to the field after the win with no second battle. If the field returns and the battle
starts again, the room was re-entered through #53–#55 (report it; walk out of the room to stop it). If no battle
starts within ~5 s of the field appearing, the save load used a non-default entry (see §6, question 1).

**T2 (BAI-fixed hold attack, `atk_dstar_4`).** Battle vs Dark Star (scn_air_boss, boss theme 0x1000357). With the
forced pattern Dark Star uses `atk_dstar_4` on **every** turn (first phase: once per turn, twice on every fifth
turn; later phases: twice per turn). Inputs (the same
mechanic as Starlow's tutorial line in `atk_koopa2_2`, `MES_ji_scn_koopa2_yellow_star_tsukamatte`: 「둘 다 점프해서
날 붙잡아! 붙잡은 다음에 버튼을 누른 채로 있어야 돼!」): when Starlow comes over the bros, press **A (Mario) and B (Luigi)**
to jump up and grab her, then **keep A+B held** while Dark Star circles (`atk_dstar_4` per-bro thread 0x310B: Mario
mask 1 = A, Luigi mask 2 = B; hold loop 0x3421–0x34A4 reads `$7005 & mask`).
- Hold-grace test (the fix): `rt_input.py keys A+B:2500 w40 A+B:2500` = hold, release ≈200 ms (160 ms default gap +
  40 ms), hold again. Expected: 30fps (`smoke`) and 60fps + fix (`v1cb`): both bros keep hanging (grace 8 × 33 ms /
  16 × 17 ms = 267 ms); 60fps without fix (`v1` + `--variant nofix`): the released bros drop (grace 8 × 17 ms = 133 ms).
  A release of ~100 ms must survive in all three (control).
- Orbit test (the fix's `wait(2)` at 0x2F7C): one lap of Dark Star around the ellipse ≈1.62 s at 30fps and at 60fps +
  fix, ≈0.81 s at 60fps without fix (7.4° per loop pass).
- Also record btl::Main +0x3D/+0x41, `+0xBA15C`, App FPS, and that the battle ends normally (win or game over).

**T3 (Bowser-body minigame, adrenaline).** The lower screen loads `i_power_hip_SA_adorena_01_L`; its entry moves the
upper screen to `i_tainai_SA_adorena_01_U` (a room change on the upper screen right after the field appears), both
screens hand-shake (`$C35B/$C35C`), then the minigame threads start (#55 Mario, #56 Luigi, #77 timer). Controls read
by the script: Circle Pad X beyond ±0.6 (`$703D`) moves both bros 6 units per loop pass (Mario clamped 43..238, Luigi
18..213); **A** = Mario shoots, **B** = Luigi shoots (first shot on the press, then every 10 passes while held).
Measurements (loop pass = one `wait(1)` = one frame unpatched):

| quantity | 30fps (`smoke`) | 60fps, no field fix (`v2n`) | 60fps + Option A (`v2`) or Option B (FEV FEvent.dat) |
|---|---|---|---|
| Mario left clamp → right clamp holding CRIGHT (195 units / 6) | 33 passes ≈ 1.1 s | ≈ 0.55 s | ≈ 1.1 s |
| shot interval holding A | 10 passes = 333 ms | 167 ms | 333 ms |
| #77 fade (−1/180 per pass) | 6 s | 3 s | 6 s |

Remove T3 afterwards (`tb_build.py remove t3_minigame`); the minigame result may otherwise be saved by the player.

## 6. Not built, open questions

- **T3b `i_power_arm_02` (rhythm)**: not built (§2.1: the beat loop is started by an in-room interaction, not by the
  entry). Option if needed: same wrapper method as T1 on `i_power_arm_02.fev` calling #38 after its entry.
- **T4 Bowser Jr.'s Journey battle**: not built. Both test saves have Bowser Jr.'s Journey at NEW GAME, KJ battles are
  `kj::` code (`kj::KJSystem::startBattle` 0x194338 is called only from KJRPG.cro, via veneers at analysis addresses
  0x14009074/0x14017334, not from field event commands), and RT2 did not reach `kj::KJSystem` within ~60 s of the
  intro. A test bed needs either a KJ save in progress or a traced KJ battle start; neither exists yet.
1. Save load and the entry override (0x310CDC: `.fev` entry = `req+0x18` when not 0xFFFF): assumed 0xFFFF on a load
   (likely; same as CRD-B). T1/T2 hedge by wrapping all three arrival entries #53/#54/#55. If RT sees no battle, break
   at 0x310CF4 during the field start (after `ldrh r2, [sl, #0x18]`; reached only when `sl[8] & 0x20` is clear) and
   report `r2` (the override) to TB.
2. The op240 battle start runs here from the room-entry thread instead of a cutscene thread; the handler only reads
   actor 0 (created by the entry, `op082(0, 0)`), the buffer base and immediates, so this is likely fine.
3. After a battle the field resumes the same room (the story's scripts continue after op240, e.g. `i_air_21`
   +0xB0DB), so the wrapper ends with `return`; a re-run of the entry would start another battle (T1 note).
4. T3 assumes the hip room's flags as read from the save (`$C396 = 1`, `$B07E = 0`) select the normal path; `$6004`
   (runtime, not saved) is only read on the `$B07E >= 4` relief path.


## 7. TB2 (wave 4): T3b / T3c — FEvent warp into the adrenaline minigame (no save edit)

Worker TB2, wave 4, 2026-10-30. Status: **in progress** (this section is written incrementally). Files only; nothing was
run in the emulator (RT4 owns it). Tool: `scripts/fps60/tb_warp.py` (`build` / `verify` / `status` / `install` /
`remove`); outputs only in `work/fps60/testbeds/t3b_minigame_warp/` and `work/fps60/testbeds/t3c_minigame_warp_fev/`.
`tb_build.py`, `MANIFEST.json` and the other bed folders are not touched. Decoder: FLD `fld_fev.py` (jump targets are
.fev buffer offsets, BRIEF3 W2). Why a warp and not a save redirect: `runtime/findings.md` §7.1 (a save whose room
block names a special room skips resources the story path loads; `readArcFile` on NULL at field start, stock game).

### 7.1 How the story enters the minigame (confirmed in the v1.2 FEvent.dat, sha256 `a0fecd0f…40aa`)

A raw scan of all 1,428 entries (every offset, not only flow-decoded code) finds **one** room change into 0x86
`i_power_hip_SA_adorena_01_L`: `i_power_hip_01.fev` +0x3DFD `op18a(0x86, 0f, 0f, 0f, 0, 0, 0x1a, 3, 0)` (entry 0x1A = 26,
the room's default). The story path, all in the game's own scripts:
1. **Hub** `i_tainai_01.fev` (the slot-1 lower room) script #60 = the body-map loop (started by the arrival entries:
   #55 +0x47E6 `op052(8, 0, 0x4808)` → +0x4A44 `jump(0, 0x4B7D)`). Destination 8 of `$b049`, only when the story
   objective `$b01f == 8` (giant battle pending, +0x60A2): `$c39e = set(0f)` (+0x60B4), the instance
   `$500d = 0/1/2/3` by `$c1d8`/`$c431`/`$c447` (+0x60C0…+0x613B), then `op18a(0x84 i_power_hip_01, 470f, 63f, 0f, 0xc,
   1, -1, 1, 0)` (+0x6147).
2. `i_power_hip_01.fev` #14: question (op211 msg 0x48dd, answer `$6004`); yes (+0x19D4 `jump(0, 0x3BA8)`) → lead-in
   +0x3BA8…+0x3E1A: `$c59c = set(1f)`, `op199(0)`, `op198(1)`, camera + the bros' jump-in animation (actors 0/1/6/7),
   `wait(0x14)`, `wait(0x50)`, poll `$c59d != 1`, poll `$7070 != 0`, other-screen sync (`op195($7022)`, `op194` if
   `$702e == 3`, `op061(1, $7022)`), `op270(0)`, lower fade `op26a(…, 55f)` + `op26b`, `$c08f = set(0f)`,
   `op150(0..2, 0)`, `op06b(1, 0x3E2E, 4)` (#19 = upper-screen fade) + `op061(4, $7022)`, `op18a(0x86, …)`.
3. A lost minigame returns through the game's own retry path: #82 `$b07e += 1`, `$b058 = 3`, lower →
   `op18a(0x84, …, 0xc, …)` (hip_01 entry 12) → #13 `$b058 == 3` → #14 (question again) → the same lead-in.
   The developers' test room `o_test_ma_01.fev` #6 starts this minigame with only `fade; op18a(0x84, 447f, 63f, 0f, 8,
   0, 0xc, 3, 0)` after `$b01f = set(8f)` (+0x58D), i.e. the target rooms are self-contained.

What the minigame room reads (decoded): `$500d` (#29 +0x3B31: `$400d = $500d < 4 ? $500d : $b055`, difficulty tables
0xDA34… by `$400d`, `$4000 = $500d·8`; return rooms of #78/#84 by `op00b($500d)`: 0 `o_ekubon_09_*`, 1 `o_zutsuda_16_*`,
2 `o_chika_geraexpress_04`, 3 `o_peach_g_06`), `$c396` (1 = no tutorial), `$b07e` (≥ 4 offers the DX skip), `$6004`,
`$c39f` (#75). The play loops (#55 Mario, #56 Luigi, #77 fade) do **not** depend on the instance (#55: stick beyond
±0.6 → ±6 per pass, clamp 43..238, A hold counter `$3007` to 10), so the T3 timing table (§5) applies unchanged.
Op meanings used below (handlers read): `op150(k, v)` 0x2E6D88 writes `v != 0` to byte +0x35/+0x36/+0x37 of
`*(Main+0x6968)` (three field-HUD enables; the minigame's success exit #78 sets them back to 1); `op270(v)` 0x2E7E28 =
fast-forward enable (`fld+0x1AC5`, `FUN_0031EC90` resets game speed and `fld+0x1A48` to 1.0); `op199(v)` 0x2E77FC writes
screen+0x9B5; `op198(v)` 0x2E60E4 calls the M&L party's vt+0x58 (the minigame's end #77 does `op198(0)`); `$7070` =
`FUN_0035F34C` (party has control, both screens loaded and idle); `op195`/`op061` re-poll (rewind + return 3).

Slot-1 save flags (read from `_source/ML3R_001.sav`, TB formulas §2): `$c396 = 1`, `$c39d = 1`, `$c39f = 1`,
`$c1d8 = $c431 = $c447 = 1` (so the hub's rule gives instance **3**), `$b055 = 3` (the instance this file played last),
`$b07e = 0`, `$b01f = 0`, `$b049 = 19`, `$c59c = $c59d = $c08f = $c39e = 0`, `$c36c = 0`, `$c2d9 = 0`.

### 7.2 Design of T3b / T3c (same wrapper as T1/T2, story commands instead of op240)

Host = the save's lower room `i_tainai_01.fev` (slot 955), arrival entries #53/#54/#55 (as T1/T2) → appended wrapper.
Every instruction is a byte copy of an instruction of the game; only jump targets and the op06b script offset are
relocated (they are buffer offsets):

| # | instruction | copied from |
|---|---|---|
| 1 | `jump(1, <original entry>)` (call) | host +0xF0B (T1 template) |
| 2 | `wait(0x3c)` (1 s at both rates) | host +0x9C29 (T1 template) |
| 3 | `$c39e = set(0f)` | host +0x60B4 (hub, hip destination) |
| 4 | `$500d = set(3f)` | host +0x613B (what the hub's rule yields for this save) |
| 5 | `$c59c = set(1f)` | hip_01 +0x3BA8 |
| 6–7 | `op199(0)`, `op198(1)` | hip_01 +0x3BB4, +0x3BBB |
| 8–10 | `jmpif(0, $c59d, 1f, 0, →11)`, `wait(1)`, `jump(2, →8)` (wait while the resident script is busy) | hip_01 +0x3CFC, +0x3D0E, +0x3D16 |
| 11 | `op270(0)` (fast-forward off) | hip_01 +0x3D83 |
| 12–13 | `op26a($7021, 0, 0, $705a, 0, 0xff, 0, 1, 55f)`, `op26b($7021)` (lower fade-out) | hip_01 +0x3D8A, +0x3DA4 |
| 14 | `$c08f = set(0f)` | hip_01 +0x3DAC |
| 15–17 | `op150(0, 0)`, `op150(1, 0)`, `op150(2, 0)` | hip_01 +0x3DB8, +0x3DC0, +0x3DC8 |
| 18–19 | `op06b(1, →23, 4)`, `op061(4, $7022)` (upper fade-out, wait for it) | hip_01 +0x3DD0, +0x3DDC |
| 20 | `op18a(0x86, 0f, 0f, 0f, 0, 0, 0x1a, 3, 0)` | hip_01 +0x3DFD |
| 21 | `return(0f)` | hip_01 +0x3E1A |
| 23–25 | upper fade script: `op26a($7021, 0, 0, $705a, 0, 0xff, 0, 1, 16f)`, `op26b($7021)`, `return(0f)` | hip_01 #19 +0x3E2E…+0x3E50 |

Left out, with the reason:
- the hip room's jump-in animation (camera `op1a6`/`op1a7`, `op097(0/1, 0x63, …)` set to 0 and back to 1, `op1ec`/`op1f0`/
  `op0df`/`op0aa`/`op0e1` on actors 0/1/6/7, `wait(0x14)`, `wait(0x50)`): positions and helper actors of that room;
  the target room rebuilds every actor; the net change of actor param 0x63 is none.
- the polls `$7070` and `op195`/`op194`/`op061(1, $7022)`: they wait until the party has control and the other screen is
  idle. The story runs them in an interaction script after the player answered; here the code runs in the room-entry
  thread, where `FUN_0035F34C` is not shown to become true, and a wait that never ends would leave the bros standing.
  The warp itself works from an entry thread (CRD variant B, RT3 §7.2), and the minigame room does its own upper-screen
  sync before it uses that screen (#27 +0x35DB `op061(1, $7022)`, `$c35b`/`$c35c` handshake +0x35F0…+0x367B).
- `$500d` = 3 instead of 0: it is the value the game itself computes for this save; the play loops do not depend on it.


### 7.3 Built and verified files (`tb_warp.py build` / `verify` → `VERIFY OK`, `selftest` → `SELFTEST OK`)

| bed | file (under `work/fps60/testbeds/`) | sha256 | size | source (sha256-checked) | use with |
|---|---|---|---|---|---|
| T3b | `t3b_minigame_warp/romfs/FEvent/FEvent.dat` | `993a55293f642461c0a4b49d5a06c98ded0f958c8c7eae16bcae188c8cd637fd` | 6,410,248 | romf2 original `a0fecd0f…40aa` | `v2` (A), `v2n` (control), `smoke` (30fps) |
| T3c | `t3c_minigame_warp_fev/romfs/FEvent/FEvent.dat` | `cbc31a9f8432d71a7cb18c2a889645108595643cfb92fc153a9b7b4759c502cf` | 6,409,452 | FEV `build/fev/…/FEvent.dat` `2e117581…5e72` (= `build/v2b` copy) | `v2b` (B) |

Both differ from their source only in table slot 955 (`i_tainai_01.fev`, re-compressed entry appended at the end of the
file; the source is a byte prefix of the output except that slot's 8 table bytes). Plain entry 47,454 → 48,315 B:
3 entry-table words (#53 @0x130 0x3A21→0xB946, #54 @0x134 0x3A38→0xBA65, #55 @0x138 0x3A4F→0xBB84) + 3 wrappers of
287 B at 0xB95E / 0xBA7D / 0xBB9C. Templates: call +0xF0B `0400000000000136100000`, wait +0x9C29 `0500000000003c00`
(the same ones T1/T2 use). Wrapper #55 (default entry) as decoded from the output by FLD's decoder:
```
0bb9c: jump(1, 0x3a67)            ; call the original #55 (builds the room, starts the hub threads, returns)
0bba7: wait(0x3c)
0bbaf: $c39e = set(0f)             0bbbb: $500d = set(3f)            0bbc7: $c59c = set(1f)
0bbd3: op199(0)                    0bbda: op198(1)
0bbe1: jmpif(0, $c59d, 1f, 0, 0xbc06)   0bbf3: wait(1)   0bbfb: jump(2, 0xbbe1)
0bc06: op270(0)
0bc0d: op26a($7021, 0, 0, $705a, 0, 0xff, 0, 1, 55f)    0bc27: op26b($7021)
0bc2f: $c08f = set(0f)             0bc3b: op150(0, 0)   0bc43: op150(1, 0)   0bc4b: op150(2, 0)
0bc53: op06b(1, 0xbc8f, 4)         0bc5f: op061(4, $7022)
0bc68: op18a(0x86, 0f, 0f, 0f, 0, 0, 0x1a, 3, 0)
0bc85: return(0f)
0bc8f: op26a($7021, 0, 0, $705a, 0, 0xff, 0, 1, 16f)    0bca9: op26b($7021)   0bcb1: return(0f)   ; upper fade (#19 copy)
```
`verify` checks (per bed, all passed): source sha256; same 1,428 slot names/flags/hashes; raw bytes differ only in slot
955's table words; only `i_tainai_01.fev` decompresses differently; the stored entry passes FEV's strict in-place BLZ
decompressor (`fev_build.blz_inplace`) as well as lib3dx; the original host bytes are kept except the 3 table words;
default entry still #55; each wrapper equals a fresh assembly and, instruction by instruction, the source instruction
bytes except the 5 relocated u32 fields (call target = the original entry, which still decodes and is reached through
the call; jmpif → op270 copy; jump → jmpif copy; op06b → upper fade copy); every wrapper instruction (except the upper
fade script, reached only through op06b) is on FLD's flow-decoded path; room 0x86 = `i_power_hip_SA_adorena_01_L` with
default entry 0x1A; a fresh build from the sources is byte-identical to the file on disk. T3c in addition: all 136 FEV
sites read 2 in the output (1 in the original), and the set of entries that differ from the original is exactly FEV's
90 entries (one of them is `i_tainai_01.fev`: FEV site +0x5CD8 in the hub loop stays 2) + the host. The appended
wrapper bytes of T3b and T3c are identical.
`selftest` (negative tests on in-memory copies, both beds): baseline accepted; rejected: op18a room 0x86→0x87, template
`wait(0x3c)`→`wait(0x3d)`, jmpif target left at the story value 0x3D21, one original host byte flipped, the unchanged
source as output, an extra change in `i_metaboru_09.fev`, (T3c) one FEV site reverted to 1.


### 7.4 Install / remove (RT4, emulator stopped; `.venv\Scripts\python.exe`, Start-Process + WaitForExit ≤ 120 s)

`tb_warp.py install|remove` uses tb_build's own checks (`tag_romfs`: the real folder `tools/azahar-test/mods_builds/<TAG>/`
that the mods junction points at, never `patch/`; refuses while azahar.exe runs; refuses reparse points) and adds:
T3b only on a tag without `FEvent/FEvent.dat` (or with the original), T3c only on a tag holding FEV's file
(`2e117581…`, i.e. `use-build v2b`); refuses while a tb_build bed (T1/T2) is installed on that tag (its
`<TAG>.tb_backup/FEvent/…` exists) and while the other TB2 bed is recorded; `remove` restores the recorded original
(deletes the file for an absent original, or copies FEV's file back) and refuses if the file was changed since install.
Backup + record: `mods_builds/<TAG>.tbw_backup/` (`install.json`, `FEvent/FEvent.dat` or `FEvent.dat.absent`).
`tb_warp.py status` shows what each tag holds. Sandbox test (scratch copy of the layout with its own junction, 13 cases:
both refusals for the wrong tag type, junction elsewhere, idempotent install, wrong-bed remove, foreign change,
tb_build bed present, emulator running; install → file hash, remove → original restored, backup folder gone): all as
intended. The real test instance was not touched (RT4's emulator was running).

| run | install | remove |
|---|---|---|
| T3b, Option A | `rt_mods.py use-build v2 --replace`, then `tb_warp.py install t3b_minigame_warp --tag v2` | `tb_warp.py remove t3b_minigame_warp --tag v2` |
| T3b, control (no field fix) | `rt_mods.py use-build v2n --replace`, `tb_warp.py install t3b_minigame_warp --tag v2n` | `… remove t3b_minigame_warp --tag v2n` |
| T3b, 30fps reference | `rt_mods.py use-build smoke --empty-ok --replace`, `tb_warp.py install t3b_minigame_warp --tag smoke` | `… --tag smoke` |
| T3c, Option B | `rt_mods.py use-build v2b --replace`, `tb_warp.py install t3c_minigame_warp_fev --tag v2b` | `… remove t3c_minigame_warp_fev --tag v2b` (FEV's file comes back) |

If T1/T2 is still installed on the tag: `tb_build.py remove <bed> --tag <TAG>` first. Log proof after boot:
`LayeredFS replacement file in use for /FEvent/FEvent.dat` (plus `/BAI/BAI.dat` for v2/v2n/v2b). The save is not
touched; finish with `rt_mods.py use-patch` as usual.

### 7.5 What RT4 should see (predictions; nothing here was run)

Path as before: title → 「게임 시작」 → slot 1 → 「시작하기」 → 「마리오&루이지 RPG3」. **Do not press keys** until the minigame
shows: the hub loop of `i_tainai_01` (#60) reads A/B/X/Y/d-pad/touch, and an A or B press while the bros have control
starts the hub's own travel (cursor `$b049` = 19 → `i_challenge_01`).
1. Field fades in: upper `o_peach_t_04` (Bowser at the save block), lower `i_tainai_01` (the bros).
2. ≈ 1 s later (`wait(0x3c)` after the room's entry returns): lower screen fades to black (55 units ≈ 0.9 s), then the
   upper (16 units ≈ 0.27 s); both black while room 0x86 loads.
3. Lower: the adrenaline room `i_power_hip_SA_adorena_01_L` (entry #26); its #27 moves the upper screen to
   `i_tainai_SA_adorena_01_U` (`op06b(1, 0x3B0A, 4)` → `op18a(0xA9, …, 3, …)`), hand-shake `$C35B/$C35C`, both fade in
   (16 units); #29 BGM `0x100034C`; `$c396 = 1` → no tutorial; `$b07e = 0` → no skip offer; #69 starts #55 (Mario),
   #56 (Luigi) and actor 0x21. Expected within ≈ 10 s of the field appearing (well under a minute).
4. Measurements and controls: exactly §5's T3 table (stick beyond ±0.6 moves 6 units per pass, A/B shoot every 10
   passes while held, #77 fade 180 passes). Under `v2b` the 7 FEV sites of this room (`wait(2)` at +0x5233, +0x54A4,
   +0x87BA, +0x8830, +0x8B9D Mario's loop, +0x8E4C Luigi's, +0xC621 the #77 fade) give the 30fps timing.
5. Afterwards: a loss → #82 (`$b07e += 1`, `$b058 = 3`) → lower `i_power_hip_01` entry 12 → the game's retry question
   (#14, C++ message; 「yes」 replays through the full story lead-in, polls included). After 4 losses in one session the
   DX skip offer appears (`$b07e ≥ 4`); reload instead. A win → #75/#78 → the instance-3 story rooms (upper
   `o_peach_g_06` entry 0x42); stop there (that story event was already played in this save). Never save. Entering
   `i_tainai_01` again through #53–#55 re-runs the warp.
6. If the field stays in `i_tainai_01` with no fade after ≈ 5 s: the `$c59d` poll is waiting (resident script busy) or
   the load used a non-default entry (§6 question 1). Read `$c59d` (bit 0x1D of u32 0x3F99A8 + 4·0x2C = 0x3F9A58) and
   report it.

### 7.6 Trigger prompt for RT4 item 5 (`$7038`, FLD §4.4)

**Not the minigame.** Its shots read the HOLD word (`$3000 = $7037 & 1`, counter `$3007` reset to 10 on release,
#55 +0x8C62…+0x8D08); nothing in either adrenaline room reads `$7038`. A 16–20 ms tap is one 60 Hz frame, so with a
30 Hz script cadence (stock 30fps, `v2`'s even-frame VM, which latches trg/rls edges but not hold, or `v2b`'s `wait(2)`
loop) a tap is seen only when it falls on a script pass (≈ half the taps, the same as stock 30fps; likely); with
`v2n` every tap is seen. Use the minigame only for the timing items.

**Candidate: the hub confirm in the slot-1 lower room** `i_tainai_01.fev` #60 (no test bed needed; also the room T3b/T3c
start in). The loop at +0x5292 runs every frame on actor 8's thread from the room's arrival (`wait(1)` at its top).
Per pass, after the guards `$c365`, `$c59d`, `$c366`, `$c3c6` ≠ 1 (all 0 in the save) and only while
`$700e != 1` (+0x5317; `$700e` = u8 `[fld::System+0x1A70] + 0x9848`): +0x5458 `$3000 = $7038 & 0xC00` (X|Y; with
`$c36c = 0` a press only ends that pass), d-pad hold → cursor move (+0x54AB…), then +0x5743 `$3000 = $7038 & 3`
(A|B **trigger**), `$c2d9 != 1` (0 in the save), `$703C & 3` and +0x577F `jmpif($3000 != 0)` → +0x5D41 travel to the
destination in `$b049`. `$703B`/`$703C` (FLD open question 2) are the per-screen button-enable masks screen+0x2F80
(script layer) / +0x2F98 (system layer), `& 0xDFFB`, applied to the pad by `FUN_0036065C`; so A/B must be enabled for
the bros' screen (the bros have control).
- How to exercise: load slot 1 with the patch or any build (no bed). If `$700e` = 1 (Bowser has control, likely after
  a load at Bowser's save block), give control to the bros first (the game's own switch, `resident.fev` #4 +0xE0D…:
  the button the action icon shows, A/B by `$7009`; likely). Then one A tap with `rt_input.py`'s shortest hold.
- One registered tap: within the same frame the loop leaves +0x5292 for +0x5D41; case 19 (`$b049` = 19 in the save)
  calls +0x66B2 (sound `op233(…, 0x2400D1, …)`, lower fade `op26a(…, 16f)`) then `op18a(0x2E i_challenge_01, 40f, 415f,
  0f, 4, 1, -1, 3, 0)`: the lower screen fades out within ≈ 0.3 s and the bros travel. No fade = not registered.
- Counting: one tap per visit, so use a save state taken in `i_tainai_01` with the bros in control (load state → one
  tap → fade or not, repeat ≥ 20×). Expected: `v2` 20/20 (F3 latches the trigger of a skipped frame), `v2n` 20/20.
- Second candidate (repeatable, conditions not verified): `resident.fev` #4, which runs in every field room:
  +0x0F5C/+0x0F6C (`$7038 & $8011`, while `$700e == 1`) and +0x1236 (`$7038 & 0x400` = X, while `$700e == 0` and
  `$702e == 3`) start the screen switch (`$c59d` 1 → 0 around it, `op154`). If that is the Bowser/bros switch (likely),
  each registered tap flips `$700e` and can be counted by RPC without leaving the room.


### 7.7 Open points (for RT4 / the lead)

1. Same assumption as §6 question 1: a save load starts `i_tainai_01` through its default entry (#55; #53/#54 are
   wrapped too). If nothing happens, break at 0x310CF4 during the field start and report `r2`.
2. Left-out polls (§7.2): if RT4 sees the upper screen misbehave during the hand-over (e.g. the minigame's upper room
   never appears), the fallback is the game's two-room path with no left-out step: wrap `i_tainai_01` to run its own
   hub code from +0x60B4 (warp to `i_power_hip_01`) and wrap `i_power_hip_01`'s entry to jump into its lead-in +0x3BA8
   (all polls included). Not built; it needs one more changed entry.
3. `$c59c` stays 1 after the minigame until a room clears it, exactly as after the story's own lead-in (the minigame
   rooms never write it; `i_tainai_01` +0x4A38 and other rooms reset it).
4. Verified facts above are static (code/data); every runtime statement in §7.5/§7.6 is a prediction.

### 7.8 Status

**Complete** (2026-10-30, TB2): T3b and T3c built and `verify` OK, `selftest` OK; install/remove tested in a scratch
sandbox only. Trigger-prompt candidate documented (§7.6).
