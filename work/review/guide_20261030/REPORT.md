# GUIDE — guide top-screen images missing on a real New 3DS (wave 5, 2026-10-30)

Static analysis only (no emulator). Status: **CANCELLED by the user (2026-10-30)**, see §4. No fix staged.
Confidence tags: **confirmed** (decoded/measured here), **likely**, **guess**.
Addresses: static = runtime address; CRO = analysis base of `work/fps60/decomp/3dx_v12` (MainMenu = 0x15000000 + file offset).

## 1. Where the guide comes from (code path)

- Guide data tables are data-only CROs loaded by `ad::guide::Man::Init` (static 0x0016A37C):
  `rom2:/RO/MenuGuide.cro` (type 0) or `rom2:/RO/KJGuide.cro` (type 1), read whole with `TryOpenFile/TryRead`
  into `gMemAlc2`, then linked with the RO service (FUN_00260a6c). **confirmed** (static.c 92673–92748).
  RT5 log (a): `CRO "MenuGuide" loaded at 0x004B3000` right after `CRO "MainMenu"`. **confirmed (Azahar)**
- `MenuGuide.cro` exports `gFldGuideData`(10), `gFldActGuideData`(15), `gBtlGuideData`(30), `gAtkGuideData`(22);
  `KJGuide.cro` exports `gKJMenuGuideData`(15), `gKJBtlGuideData`(15), `gKJAtcGuideData`(26), `gKJCmdGuideData`(22).
  Row = 16 bytes `{char* label; u8 pages|flags; u8 ?; u8 type; u8 parent(99=none); u16 flagA; u16 flagB; u32 flagC/attack}`.
  The u16/u32 words are **event flags** (`GetRegFlag`) for "guide exists" (`FldGuideAcs::IsExistGuide` 0x132F1C,
  `ActGuideAcs::IsExistGuide` 0x132A70, `BattleGuideDataAcs::checkGuideAppear` 0x1389A4), not picture ids. **confirmed**
- Both CROs are **not** in the patch (v1.0 = v1.2, SHA-256 `01CFDFFB…6330` / `05F5FEB5…976E`). **confirmed**
- Guide page = `main_menu::MainMenu_GuidePage` (MainMenu.cro). Init FUN_1500E6B0: reads `?MENU_GUIDE` =
  `Lyt/JP/MLyt.dat` entry `MENU_GUIDE_JP_ja` and builds **only** `MENU_GUIDE_L.bflyt` (320×240, bottom) into the page's
  bottom MLyt (+0x4B8); the page's top MLyt (+0x110, used by Item/Badge/Equip/Record/Status `*_U.bflyt`) is never
  built. Page text = Menu.msbt label `"%s_%d"` (e.g. `FldGuide_00_1`) played into `INS_TEXT_GUIDE` (FUN_15011AB0);
  page turn FUN_15015C5C only updates the page number, L/R buttons and that text. **confirmed**
- The top screen during the guide is the menu-wide `MENU_BG_U.bflyt` (`MLyt.dat` entry `MENU_BG`, no language suffix):
  sky `MENU_BG_U.bflim` + `INS_EFFECT_STAR_U` (DFX star effect, `MDFXMenuArchive`) + `MAP_ALL` (the map is played out
  with `MAP_OUT` when a sub page opens, MainMenu.c 2651). This is exactly the "starry background" RT5 grabbed. **confirmed**
- Search for any other picture source (all BG4 archives in romfs/romf2 decompressed, CRO strings, Obj `_CA_INFO_`
  sprite names, FMdl BCH names, guide message tags): no texture, sprite, layout or tag tied to a guide entry or page.
  Guide messages (731) use only `[0009:0000:..]` style, colour, ruby and icon tags; ATR1 = 0. **confirmed**

## 2. Runtime evidence from RT5 (Azahar 2126.1.2, New 3DS)

- (a) shipped patch (Korean + 60fps): starry top screen, no picture, on 7 pages of 4 categories. **confirmed (RT5)**
- (b) Korean only, no code.ips (30fps): identical (`guide_b_p1.png` = `guide_a_p1.png` layout). **confirmed (RT5)**
  → the 60fps code is not involved in Azahar.
- (c) no mods (original v1.2 Japanese): the same starry top screen, no picture (`guide_c_categories.png`,
  `guide_c_p1.png` … `guide_c_p6_btlattack.png`). **confirmed (RT5)**
- Comparison: the 1DX Korean guide does use a top screen (`MLYT_GUIDE_KR_ko/MENU_GUIDE_U.bflyt`, a "guide book"
  `GUIDEBOOK_base` with `INS_GUIDE_PARTS`, built by 1DX `menu::MainMenu_GuidePage`, 1dx static.c 502314). The 3DX guide
  archives have no `_U` layout and the 3DX page never builds one, so 3DX dropped that top-screen page. **confirmed**

## 3. Korean-patch files on the guide path (checked against the original)

- `RO/MainMenu.cro`: one changed instruction, file 0x20C38 `moveq r0,#1` → `#0` inside the **settings page** init
  FUN_15020BE8 (`ad::GetRegion()==0` → `hasRuby`, stored only to that page object +0x866). The guide page code
  (0x1500E6B0–0x15017B94) is untouched. **confirmed**
- `Lyt/JP/MLyt.dat` `MENU_GUIDE_JP_ja`: SARC rebuilt in place — same size 0x3F5A8, same header
  (hdr 0x14, data offset 0x2400), same 135 file names/offsets/sizes; only 10 BFLIM payloads changed
  (`LTIT_guide_1/2`, `LTIT_GUIDE_3/4`, `btn_text_guide_pnl_1..4`, `btn_GUIDE_EXAMPLE/PRACTICE`, all bottom screen). **confirmed**
- Same for `KLyt.dat KJ_GUIDE_JP_ja` (0x51CBC, 6 BFLIM) and `BLyt.dat btl_GUIDE_JP_ja` (0x1FFA8, 5 BFLIM). **confirmed**
- `MENU_BG` (top screen) is byte-identical after decompression. **confirmed**

## 4. Cancelled by the user (2026-10-30): the top screen is empty in the unmodified game on a real cartridge

Status of what was found so far:
- Cause: none. The empty (starry) top screen is original behaviour. The 3DX guide page builds only the bottom
  layout `MENU_GUIDE_L.bflyt`, and Azahar without mods (RT5 (c)) looks the same. Neither the Korean patch nor the
  60fps code is involved (RT5 (b) without `code.ips` looks the same). **confirmed**
- Korean files on the guide path: the guide SARCs were rebuilt in place (same size, offsets and header; only bottom-screen
  BFLIM pixels changed). The MainMenu.cro patch is one byte in the settings page only. **confirmed**
- `check_guide_files.py` (this folder) was written for the BFLIM header / SARC padding / BG4 alignment checks but was
  **not run** when the task was stopped. Its checks are unverified.
- `work/build/guide_fix_stage/` is empty: nothing was staged or built. Nothing in this folder is to be installed.
