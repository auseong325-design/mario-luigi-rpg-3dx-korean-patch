# BANNER — Korean HOME Menu banner (wave 5, 2026-10-30)

Worker BANNER (build only, no emulator). Writes only in `work/banner_20261030/`.
Originals (`exefs/`, `ml 1dx/`, root `*.cia`) are read-only. Nothing was installed.
Confidence tags: **confirmed** (measured here), **likely**, **guess**.

Status: **DONE** — Korean banner built, installable CIA built and verified offline. Not run on hardware
or emulator (Azahar has no HOME Menu banner); the HOME Menu result needs a real-console check.

Deliverables (`out/`): `00040000001CA900_ML3DX_KoreanBanner.cia` (sha256 `7e70eaee…0f2d`),
`INSTALL_KO.md` (Korean install steps, FBI), `SHA256SUMS.txt`, `banner/banner_ko.bin`, `logo/COMMON_ko_upright.png`.

## 1. Banner files (confirmed, `scripts/bnr.py info`, `extract/banners.json`)

| | 3DX `exefs/banner` | 1DX KR `ml 1dx/3exefs/banner` |
|---|---|---|
| size / sha256 | 153,096 B / `d6b5df0f…449f` | 149,336 B / `42dc68bc…c3e4` |
| CBMD CGFX slots | only slot 0 (common) at 0x88; regional slots 1–13 = 0 | same |
| CGFX (LZ11) | 144,640 B, compressed 42,926 B, 10 zero bytes, BCWAV at 0xA840 | 170,240 B, compressed 39,288 B, BCWAV at 0x9A00 |
| BCWAV | 110,024 B (`CWAV`) | 109,912 B |
| models | `COMMON` (CMDL) | `COMMON` (CMDL) |
| animations | material anim `COMMON` | skeletal `COMMON` + material `COMMON` |
| textures | `bunner_rem3_base` 64×64 ETC1A4, `bunner_rem3_bg` 128×128 ETC1A4, `bunner_rem3_bk` 64×32 A4, `bunner_rem3_chara` 128×128 RGBA4, **`COMMON_jp` 256×128 RGBA4** (CGFX data offset 79,104, 65,536 B) | **`COMMON_kr` 256×128 RGBA4**, `re_banner_a` 128×64 A8, `re_banner_chara` 128×256 RGBA4, `re_banner_ef` 32×8 A4, `re_banner_l` 32×16 A8 |

- The CGFX DATA block holds **15** (count, DICT offset) pairs (the first DICT starts at DATA+0x80), not 16.
- The logo is the only lettering: `COMMON_jp` = 「マリオ&ルイージRPG3 DX デラックス」 + ™, stored upside down
  (row 0 = bottom). The 1DX Korean banner uses the same slot name pattern (`COMMON_kr`, same size and format).
- All lossless textures re-encode byte-identically with `scripts/libtex3ds.py` (RGBA4/A4/A8: confirmed).

## 2. LZ11 compressor reproduced (confirmed)

`bnr.py lzcheck exefs/banner`: a greedy LZ11 coder with window 0x1000, **longest match, farthest
displacement on ties, no displacement 1** ("VRAM-safe") gives the original 42,926-byte stream
**byte for byte**. Nearest-on-ties or displacement 1 allowed do not (first difference at token 8/17).
So an unchanged CGFX re-compresses to the original bytes, and the banner rebuild needs no copied stream.

## 3. Model (confirmed, independent read with SPICA `tools/SwitchToolbox/SPICA.dll`, `scripts/spica_dump.ps1`)

`extract/3dx_spica.json`, `extract/1dx_spica.json`.

- 3DX model `COMMON`: one identity bone, 5 materials, 6 meshes. The logo is mesh 5, material `Mat_jp`,
  texture `COMMON_jp`, a single quad x −9.089…9.089, y −0.941…8.148, z 2.077 (front-most), UV 0…1,
  texcoord transform identity. The quad is exactly 2:1 like the 256×128 texture, so the logo is shown
  without stretching. v = 1 is the top edge (the stored image is bottom-up).
- The 3DX material animation `COMMON` (200 frames, loop): SPICA lists no element for it at all, so the
  logo is **likely** static. Either way the animation bytes are unchanged and the new texture keeps the
  JP layout (same size, format, name, UV use).
- 1DX: `COMMON_kr` on `Mat_re_title_01`, quad 16.90 × 8.45 (also 2:1).

## 4. How Nintendo made the JP banner logo (confirmed, `scripts/fit_jp.py`, `fit/fit_jp.json`)

The JP banner logo is the JP title-screen logo (v1.2 FMdl `fmd_title_JP_ja`, textures
`title_logo_JP_bottom` + `title_logo_JP_top` stacked, 512×256) **scaled uniformly** and shifted:
x = 0.5967·x′ − 24.16, y = 0.5936·y′ − 10.79 (x/y = 1.005). The word, the numeral plate and the DX block
fitted alone give the same transform within 0.6 px (no rearrangement). Only the **™** was redrawn
(bold navy 9×4 px on the white glow, JP banner x 241–249, y 69–72 upright). Overlay/difference:
`fit/fit_jp_overlay.png`. Transparent texels are white (255,255,255) in the JP texture.

Consequence for Korean: the installed Korean title logo (decoded from
`patch/00040000001CA900/romfs/FMdl/JP/FMdl.dat`, equal to `work/img/logo2/out/title_logo_JP_*.png`,
`extract/title_src.json`) is wider (1DX proportions; alpha bbox x 5–508 vs JP 48–463), so the same
recipe needs scale **0.5** instead of 0.597 to fit the 256-px texture with the JP margins (2 px).

## 5. Korean logo texture (confirmed, `scripts/make_logo.py`, `out/logo/`)

Same recipe as Nintendo's, applied to the installed Korean title logo:

1. stack `title_logo_JP_bottom` + `title_logo_JP_top` (installed Korean pixels) as on the title screen;
2. erase the thin title ™ (title px x 484–495, y 145–150) by interpolating the white glow between the
   rows above and below (at half size it would be a faint 3-px smudge, as `preview/v1_tm_x8.png` shows);
3. move up 10 title px (vertical centre like the JP banner: JP alpha box y 6–123, Korean 15–113),
   2×2 box filter in premultiplied alpha = uniform scale **0.5** (alpha box x 3–254, JP 2–254);
4. paste the JP banner's own banner-size ™ ink (navy, unmixed against the white glow, 31 px) at the
   Korean title ™ spot mapped to the banner, shift (+1, −2) px, on a 1–3 px white halo
   (the half-size glow there is too thin to back it the way the JP banner does);
5. straight alpha, transparent texels white (like the JP texture), RGBA4; encode → decode round trip equal.

Result `out/logo/COMMON_ko_upright.png` (256×128, top row first), bytes `out/logo/COMMON_ko_rgba4.bin`
(65,536 B, sha256 `cb055839…`). The lettering is exactly the installed title logo (1DX-based 마리오&루이지,
RPG, 3 plate, DX + flames, 디럭스, Mario/Luigi silhouettes over 리/오); 디럭스 is a plain 2×2
downsample like the JP banner's デラックス (the fit shows Nintendo did not redraw it).
Previews: `preview/logo_jp_ko_1dx_x3_cb055839.png` (JP / Korean / 1DX-KR, ×3),
`preview/logo_detail_x6_cb055839.png` (™ area).

## 6. Banner rebuild (confirmed, `scripts/build_banner.py`, `out/banner/banner_build.json`)

- Unchanged rebuild (decompress → LZ11 with the reproduced coder → CBMD): **byte-identical** to
  `exefs/banner` (sha256 `d6b5df0f…449f`).
- Korean: only the `COMMON_jp` pixel bytes change (CGFX bytes 79,104–144,639; 28,687 bytes differ),
  texture name kept (the material refers to it by name). The new compressed CGFX is 38,653 B (was 42,926 B),
  so it is followed by **4,283 zero bytes up to the original BCWAV offset 0xA840** (the original already
  had 10 zero bytes there). CBMD header (incl. 0x84), BCWAV offset, BCWAV bytes and file size (153,096 B)
  are unchanged, so the ExeFS layout does not change at all.
  `out/banner/banner_ko.bin` sha256 `d659b9fe…c8b6`; other 4 textures identical; decoded texture = logo PNG;
  CGFX 144,640 B ≤ 0x80000 limit (3dbrew CBMD).
- (An earlier compact variant with the BCWAV moved to 0x97C0 left a gap in the ExeFS; it was replaced by
  this one and no longer exists in `out/`.)

## 7. Can Luma3DS override the HOME banner? No (confirmed from sources)

- Luma3DS game patching = external `code.bin`/`exheader.bin`, IPS/BPS code patches, **LayeredFS (files
  inside the RomFS of a game)**, locale emulation — nothing for ExeFS `banner`/`icon`
  ([Luma3DS wiki, Optional features](https://github.com/LumaTeam/Luma3DS/wiki/Optional-features)).
- LayeredFS works by patching the **game's own code** at load time: `patchLayeredFs()` hooks the game's
  `fsOpenFileDirectly`/`fsTryOpenFile` and mounts `/luma/titles/<TID>/romfs`
  ([loader/source/patcher.c](https://raw.githubusercontent.com/LumaTeam/Luma3DS/master/sysmodules/loader/source/patcher.c)).
  HOME Menu reads the banner itself, from the installed title's ExeFS, so the redirect never sees it.
- The game cannot supply a banner either: no ExBanner (3dbrew: banners come from ExeFS:/banner or an
  optional extdata ExBanner, [CBMD](https://www.3dbrew.org/wiki/CBMD)); the exheader extdata ID is 0 and
  the v1.2 code + all CROs contain no `banner`/`extdata` strings (`out/exbanner_scan.json`; confirmed for
  the data, conclusion likely).
- So the only way is a re-installed base title with a new ExeFS banner.

## 8. Base CIA facts (confirmed, `scripts/cia.py info`, `out/cia/original_cia_info.json`)

Root file `00040000001CA900.00000002 … (CTR-P-A3RJ) (J).standard.cia`: 699,835,328 B, sha256 `850f61d3…610a`.
Title 00040000001CA900 **v0** (v1.0 base; the v1.2 update is the separate title 0004000E001CA900), 1 content
(no manual), content type 0 = **not title-key encrypted**, NCCH flags[7] = 0x04 **NoCrypto** (decrypted),
no seed. ExeFS: `.code` 1,913,764 B, `banner` 153,096 B at 0x1D3400, `icon` 14,016 B at 0x1F8C00 (tightly
packed); every hash in the CIA verifies (TMD info/chunk records, content SHA-256, ExeFS superblock, ExeFS
files, RomFS superblock); ExeFS files equal `exefs/`.
Signatures (`scripts/sigcheck.py`, `out/cia/original_sigcheck.json`): the cert chain is valid (proves the
checker), but the **TMD, ticket and NCCH-header signatures of the original are already invalid** (a GodMode9
"standard" = decrypted build). So the original already needs the signature patches that Luma3DS applies
to NATIVE_FIRM on every boot (`patchSignatureChecks()` in
[arm9/source/firm.c](https://raw.githubusercontent.com/LumaTeam/Luma3DS/master/arm9/source/firm.c));
the rebuilt CIA needs nothing new.

## 9. Modified CIA (confirmed, `scripts/cia.py build`, `out/cia/*.json`)

Builder: keeps every byte except what depends on the banner, and **recomputes** (does not copy) the ExeFS
banner hash, the NCCH ExeFS superblock hash, the TMD content SHA-256 and the TMD content-info hashes.

- **Unchanged rebuild** (`cia.py build <cia> exefs/banner -`): output sha256 `850f61d3…610a`
  = original, 0 changed bytes (`out/cia/identity_build.json`). Together with the byte-identical banner
  rebuild (§6) the whole chain CGFX → LZ11 → CBMD → ExeFS → NCCH → TMD → CIA reproduces the original.
- **Korean CIA** `out/00040000001CA900_ML3DX_KoreanBanner.cia`: 699,835,328 B (same size),
  sha256 `7e70eaee4d262f7669aeb03d4c4b217edfd7f79ee1e2edd0c301e92d0ae00f2d`.
  Changed bytes, all and only (`out/cia/korean_build.json`):

  | CIA offset | bytes | what |
  |---|---|---|
  | 0x2FA4–0x2FE8 | 68 | TMD: content-info-records hash (header) + info record 0 hash |
  | 0x38D4–0x38F4 | 32 | TMD: content 0 SHA-256 (`3c3c28e2…0f0e`) |
  | 0x3AC0–0x3AE0 | 32 | NCCH header 0x1C0: ExeFS superblock hash |
  | 0x66C1–0x66E0 | 31 | ExeFS header: banner SHA-256 |
  | 0x1DF3DB–0x1E4336 | 20,315 | ExeFS banner: compressed CGFX from the logo texture on, + zero padding |

- Independent read-back (`scripts/cia.py info` on the output, `out/cia/korean_cia_info.json`): every hash
  verifies, ExeFS still packed, sizes and offsets unchanged. `scripts/verify_final.py`
  (`out/cia/final_verify.json`): banner from the CIA = `banner_ko.bin`; `.code`, `icon`, exheader, logo,
  RomFS region, certs, ticket and meta byte-identical to the original; logo decoded from the CIA = logo PNG
  (`out/cia/logo_read_back_from_cia.png`). Signature status identical to the original
  (`out/cia/korean_sigcheck.json`).
- SPICA (separate parser) on the banner taken from the Korean CIA: models, meshes, materials and animations
  equal the original; 4 textures byte-equal; `COMMON_jp` raw = `cb055839…` = the new texture
  (`extract/ko_spica.json`).
- Scene mock-up: `preview/banner_mockup_jp_ko.png` (orthographic bind-pose approximation, not the HOME
  camera; the white cloud is the alpha-only `bunner_rem3_bk` texture drawn without its material colour).

## 10. Install (for the lead/user; nothing was installed here)

`out/INSTALL_KO.md`: copy the CIA to `SD:/cias/`, FBI → SD → cias → `Install CIA`, reboot. Install **over**
the existing title; do not delete the title first (deleting it deletes the save). The v1.2 update
(0004000E001CA900) and `luma/titles/00040000001CA900/` stay as they are. Revert = install the original
root CIA the same way. Checkpoint save backup recommended first.

- Save kept when installing over an installed title: **likely** (AM replaces the title's content; the save
  lives in the separate `title/00040000/001ca900/data/` folder and is removed only by deleting the title).
- The v1.2 update is a separate title and is not touched by installing the base: **confirmed** by the TMD
  (title ID 00040000001CA900 v0 only).
- The CIA's ticket is byte-identical to the original standard CIA's; on a console where the game came from
  the eShop it would replace that ticket (**likely**, AM imports the CIA ticket); the game still runs on Luma.
- Only for an SD-installed game. A game-card copy cannot get a new banner this way.

## 11. Rebuild

`scripts/run_all.ps1` runs everything in order (each python step via `scripts/run.ps1` with a timeout):
`extract.py` → `title_src.py` → `fit_jp.py` → `make_logo.py` → `build_banner.py` → `cia.py build` (identity,
hash only) → `cia.py build` (Korean) → `cia.py info` → `sigcheck.py` → `verify_final.py` → SPICA dump → `mockup.py`.
Libraries: `bnr.py` (LZ11 + CBMD + CGFX), `cia.py` (CIA/TMD/NCCH/ExeFS). `scripts/_*.py` are one-off
inspection helpers (previews `preview/v1_*`, `tm_title_kr_jp_x8.png`).

## 12. Open points

1. Real-console check: HOME Menu → select the game → the top-screen banner shows the Korean logo; the game
   still starts with the Korean patch, 60fps code and the existing save. Not done (no hardware here).
2. Design choice to confirm: the Korean title logo is wider (1DX proportions), so in the banner it is
   shown at 0.5× of the title texture vs the JP 0.597× (≈16 % smaller lettering, centred, same margins).
   디럭스 is the plain downsample like the JP デラックス; ™ is the JP banner's own ™ on a small halo.
3. Not in scope, unchanged: the HOME Menu title text (SMDH `icon`, Japanese column 「マリオ＆ルイージRPG3 DX」).
   The same builder could replace ExeFS `icon` in the same way if wanted (the v1.2 update also carries an icon,
   `exefs2/icon`, so which one HOME shows would need checking first).

## 13. Korean HOME title (2026-11-20, user request)

- The game's SMDH (`exefs/icon`, identical to the v1.2 update's `exefs2/icon`) had English text in the Korean
  column (「Mario & Luigi: Bowser's In…」), so a Korean-language console showed the English name.
  `scripts/make_icon.py` writes 「마리오&루이지 RPG3 DX」 into the Korean short and long title and keeps
  「Nintendo」 as publisher, like the 1DX Korean SMDH. Only that slot changes (97 bytes, 0xE08–0xEFD); icons,
  other languages, ratings, region lockout (Japan only) and flags are unchanged (`out/icon/icon.json`).
  The title text is the AGENTS.md form (no space before 3); all 6 Hangul also occur in the 1DX name.
- `scripts/cia.py` now replaces any ExeFS files (`cia.py replace <cia> <out> <report> name=file ...`);
  `build` calls it. Regression: replacing only the banner reproduces the 10-30 CIA byte for byte
  (sha256 `7e70eaee…2f2d`).
- `out/00040000001CA900_ML3DX_KoreanBanner_Name.cia` (banner + icon, sha256 `c25d7dc7…41bd1`) and
  `out/0004000E001CA900_ML3DX_v1.2_KoreanName.cia` (icon only, sha256 `a2a0047d…1db5`). Changed bytes = the
  replaced ExeFS slots and the dependent hashes only (`out/cia_name/*_build.json`). Read back with
  `cia.py info`: every hash verifies, sizes equal the originals, ticket, certs, `.code` and RomFS hash
  unchanged, the Korean title reads back from both (`out/cia_name/*_info.json`).
- The update gets the same icon because which title's SMDH the HOME Menu shows when an update is installed
  is **unconfirmed**; with both replaced it does not matter. Not checked on hardware (no console here).
- Hangul in the SMDH shows only on Korean-region consoles (their system font has Hangul).
- `preview/home_preview_ko.png` (`scripts/preview_home.py`): JP vs Korean banner scene plus the HOME title
  text. Same front-view approximation as `mockup.py`, but `bunner_rem3_bk` is drawn as a dark drop shadow
  under the characters (an alpha-only silhouette texture; the shade is assumed, the combiner is not in the
  dump). `out/INSTALL_KO.md` now covers both CIAs and replaces the banner-only CIA.
