# fps60 build `v3b` (worker STAR2, 2026-10-30) — 스타&스타 throw cycle at 60fps

Analysis and measurements: `work/fps60/analysis/koikoi_star.md` §6–§11. Tools: `work/fps60/star/star2_baifix.py`
(BAI fix, checks), `star2_bp.py` / `star2_ana.py` (runtime breakpoint logger and classifier).

## Files to install (2, same places as v2)

| file | size | sha256 | change vs the shipped patch |
|---|---|---|---|
| `code.ips` | 552 B | `e5aa7d60686a9129508600e0a43f4391290dd09e9a9661db1c9de1d3b05d998a` | none (v2 byte for byte) |
| `romfs/BAI/BAI.dat` | 2,861,904 B | `8f3c1928b91f3b851c3f437bd06a0a200663822538967491a83794f025827261` | `atk_pc_sp_ml_star.bai` and `_easy.bai` only (146 plain bytes each) |

`code.bps`, `patched.code.bin`, `manifest.json`, `verify.txt` are the builder's records (`build_fps60.py --tag v3b
--credits-fix --field-vm30 --out work/fps60/build/v3b`, RESULT: ALL CHECKS PASSED, identical to v2). Ship `code.ips`
only, never together with `code.bps`. Luma's LayeredFS payload area 0x388BD8–0x388E0F is untouched (same code as v2).

## What the BAI change does

- Thread 0x30A4 (star from the bro's stock into his hand): `wait(0x12)` → `wait(0x10)` + `$1005 = 4 / $7012` +
  `wait($1005)`: 9 frames at 30fps (unchanged), 20 instead of 18 at 60fps. The throw cycle becomes 22 units at both
  rates (was 20 at 60fps because two one-frame thread hand-offs cost 1 unit instead of 2). Space from the same
  function: a duplicated `z += 1` and a recomputation of `$8014` removed, one `op025` written as `op016`.
- 0x727A (demonstration only): `$708a >= 50` → `>= 51`. `$708a` is odd at 30fps, so the window is unchanged there;
  at 60fps it now closes at the same unit.
- Everything else in BAI.dat is byte-identical to the shipped BTL2 file (`bai_verify.txt`).

`v3a` (`work/fps60/build/v3a/`, BAI sha256 `d44d656b…389e`) is the same without the 0x727A change; `v3b30` is a
test-only copy of the v3b BAI.dat without code (30fps check). `v3_ref60` = shipped code only (60fps reference).

## Verified in Azahar (test instance, New 3DS; demonstration of 스타&스타 in the T1 battle)

| build | stars caught per cycle | impact → 「EXCELLENT!」 (60-Hz units) |
|---|---|---|
| shipped 60fps (`v3_ref60`) | 47 | 330 (RT5: 331 frames in 3 of 3 cycles) |
| 30fps, shipped BAI (`star2_30`) | 43, 45, 45 | 210, 270, 270 (RT5: 204 and 234 units, i.e. 43 and 44 stars) |
| 30fps, v3b BAI (`v3b30`) | 45, 43, 45, 44 | 270, 210, 270, 240 |
| 60fps `v3a` | 45, 45, 44, 44, 45 | 270, 270, 240, 240, 270 |
| 60fps `v3b` | 44, 45, 44, 45 | 240, 270, 240, 270 |

Throw cycle measured 22 units in every gap at 60fps `v3a`/`v3b` and at 30fps; 20 in the shipped 60fps build.
The drop/hit sequence itself is the same at both rates (group delay 30, fall 88 units, 「EXCELLENT!」 in the frame of
the last hit). Spot check: 초록등껍질 demonstration on `v3b` at 60fps, GOOD/GREAT/EXCELLENT as usual, battle counter
59.7 frames/s. Not run on a real console.

## How RT/the lead can re-check

`rt_mods.py use-build v3b --ips --replace` + `tb_build.py install t1_battle --tag v3b`, boot, title `A w2500 A w2000
A w2500 A`, field `A w4000 A` (+ one more `A` if the bros did not switch), battle: `DLEFT A DUP`, touch 141 183 (시범).
Then `work/fps60/star/star2_bp.py run --secs 110 --only 'dmg,est' --out LOG` and `star2_ana.py LOG`
(stars, hits, impact → EXCELLENT per cycle). Pass: 22-unit throw cycle (`star2_bp.py run --secs 105 --work` +
`star2_ana.py`), stars 43–45 and impact → EXCELLENT 210–270 units at 60fps like 30fps, never 47 / 330.
Remove the bed and `rt_mods.py use-patch` afterwards.
