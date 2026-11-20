# FONT — item/equipment icon menus: font inventory, standard, staged build (wave 5, 2026-10-30)

Worker FONT. Static analysis + offline rendering only (no emulator). Wrote only here and in
`work/build/menu_font_stage/`. Status: **done** — staged build verified offline; Azahar/real-hardware check is RT's / the
user's (nothing here was run in the game).
Confidence tags: **confirmed** (measured/decoded here), **likely**, **guess**.

> **Update (FONT2, 2026-10-30): v2 supersedes v1's letter/digit spacing — install from `work/build/menu_font_stage/v2/`,
> plus the SUYEOM label fix; see §10.** Sections 0–9 below describe v1 (glyph shapes/baseline unchanged in v2).

## 0. Result in one paragraph

The menus mix two typefaces **inside one string**: every Hangul syllable is a 1DX Korean glyph, but Latin letters,
digits and most ASCII punctuation are still the Japanese 3DX glyphs (rounder, wider, soft edges) and sit 1 px lower
(`font`, `font_btl`); the 1DX `! , : % ~` that build_font.py added sit 1–2 px lower than in 1DX. So `POW부츠DX`,
`파워팔찌SP`, `HP를 50 회복.`, `EXP가 2배.` look like two fonts of two sizes (**confirmed**: RT5 grabs + offline render).
Element sizes themselves (names 16 px, descriptions 12 px) are the original game's design (**confirmed** against the
Japanese grabs) and stay. **Standard chosen:** each Korean font uses one design and one baseline — the 1DX Korean font of
the same role for every glyph Korean text uses (Hangul, Latin, digits, punctuation), with 1DX's vertical relation
between them; sizes per element as in the original. Implemented as a byte-minimal post-process of the two installed
fonts (`font.bffnt`, `font_btl.bffnt`; 75 glyphs each), same file sizes, verified offline.

## 1. How the menus draw text (confirmed from code)

- **No layout text panes.** No `txt1` pane and no `fnl1` font list in any MLyt layout (`lyt_list.py` over the 32 SARCs
  of `Lyt/JP/MLyt.dat` → `mlyt_list.txt`). Menu text is drawn by the game's `MessageSimple` writer at attach panes
  (`INS_*`, `list_text`) or by `ad::ui::UIListWindowPlusLyt`. Label images (tabs `아이템`, `장비 중`, `SPEED`, …) are
  textures from the image workstream, not font text.
- **Font table** `MessageDrawer::_Font[i]` (stride 0x48), filled by `FUN_0010579c` from the name table at code
  0x3F41A4 (`font_table.txt`): 0 `font_l`, 1 `font`, 2 `font_btl`, 3 = second ResFont on the `font` data, 4 = second
  ResFont on the `font_btl` data, 5 system font, 6 `gaizi`, 7 `font_ruby`.
- **Font per message = its style.** Every Item/Menu/MenuKJ message starts with `[0009:0000:XX 00]` (XX = TSY1 style).
  `MessageSimple::GetFont` (0x270FD4) and the inlined copy in `UIListWindowPlusLyt::drawListStr` (0x1437BC):
  0/5/8 → 2 font_btl, 1/6/9 → 1 font, 2/7/10 → 0 font_l, 3/11 → 4 font_btl, else → 3 font. `MessageSimple::play`
  (0x275444) skips styles 13 and 255, which keep the writer's default (`MessageSimple::init` 0x2736B4 sets 3 = font;
  MainMenu sets 4 = font_btl for the top-screen panel `INS_TOP_PANEL_TEXT`, `MainMenu.c` line 3945, and for several
  setting texts, lines 10016/20422/20443/20463). List rows always use the mapping (style 13 → font).
- **Scale 1.0**: `msys::SetMListWndInitParam` (0x329E60) sets the list-string scales to `VEC2::One`; no text host pane
  of MENU_ITEM has a scale ≠ 1 (`lyt/MENU_ITEM.txt`). List rows are 28 px (`MENU_ITEM_L_LIST`: `ICON_K` 22×22 at
  x −124, `list_text` 260×28 at −110).
- 1DX KR uses the same slot layout but loads separate **system** fonts into slots 3/4 (`font_sys`, `font_sys_btl`,
  table at 1DX code 0x0049C6C4, `font_table_1dx.txt`); 3DX has no file names for slots 3/4, so without a code patch
  menus and dialogue share one file per size.

## 2. Inventory: text elements of the icon menus (confirmed: code + RT5 grabs `work/review/rt5_20261030/`)

| screen (grab) | element | message (style) | font slot → file | size (Hangul adv) |
|---|---|---|---|---|
| 아이템 list (`menu_items_*`) | item name | `N_*` (13) | list map → 3 → `font` | 16 px |
| 아이템 list | count | — | Lyt digit images (`NUM_G_s`) | image |
| 아이템/장비 top panel | description | `E_*` gear (3), consumables (13), `EFF_Badge_*` (13) | 4 / writer 4 → `font_btl` | 12 px |
| 장비 slots `장비 중` (`menu_gear_*`) | gear name | `Ns_*`/`N_*` (13) | 3 → `font` | 16 px |
| 장비 list | gear name, count | `N_*` (13), images | `font`, image | 16 px |
| 장비 stat strip | numbers | — | images | image |
| 능력 page (`menu_stats_*`) | gear names | `N_*` (13) | writer 4 → `font_btl` | 12 px (same in JP, `menu_stats_orig_1.png`) |
| 배지 (`menu_badge_*`) | effect text, both screens | `EFF_Badge_*` (13) | `font_btl` | 12 px |
| 상점 (code, ShopMenu.c) | `갖고 있는 개수` (0), `지금 착용할까요?` (1), notices `F_*` (12) | 2 / 1 / 3 | font_btl / font / font | 12 / 16 / 16 |
| headers, tabs, buttons | `아이템`, `장비 중`, `마스터배지`… | — | Lyt textures (image workstream) | image |

What looks mixed (RT5 grabs, crops in `crops/`, JP vs KO in `crops/desc_jp_vs_ko_A.png`):
- **Latin/digits vs Hangul in one string — the reported problem (confirmed).** `POW부츠DX`, `POW글러브DX`, `파워팔찌SP`
  (`crops/gear8_slots.png`, `gear1_slots.png`), `HP를 50 회복.` (`items1_desc.png`), `POW가 증가하는 부츠.`,
  `배틀 종료 시 획득 EXP가 2배.`. In the Japanese original the 3DX Latin matches the 3DX kana. Scope (strings that mix
  Latin/digits with Hangul, `latin_census.txt`): 48 item names (`N_`/`Ns_`), 129 item/gear descriptions (`E_`), 103
  shop/field notices (`F_`), 20 badge effects, 173 Menu and 10 MenuKJ messages.
- Not font problems: consumable names look thinner/greyer than key items (`crops/rows_items_vs_key.png`) = the list's
  disabled colour (all HP full in this save); gear names smaller on 능력 than on 장비 = original design (JP identical).

## 3. Measurements (confirmed)

Rows relative to the cell baseline (alpha ≥ 8/15), `metrics.txt`:
| font | Latin caps | Hangul | note |
|---|---|---|---|
| shipped `font` | 12..1 (3DX) | 13..2 | Hangul 1 px above Latin; 3DX Latin also has faint rows 13..0 |
| shipped `font_btl` | 9..1 (3DX) | 10..2 | same 1 px offset |
| 1DX `font` / `font_btl` | 12..1 / 9..1 | 12..1 / 9..1 | one baseline |
| **staged** `font` / `font_btl` | **13..2 / 10..2** | 13..2 / 10..2 | one baseline, as 1DX |

- Why the offset exists: build_font.py moved Hangul +1 / −1 px to centre them on the 3DX kanji box and placed
  punctuation on the 3DX Latin baseline (`font_report.json` `donor_shift` font [1, 3], font_btl [−1, 0]). Moving the
  Hangul down instead is impossible in `font_btl`: 120+ syllables already touch the bottom row of the 13-row cell
  (`proto_sheet.py` run, e.g. 강 공 양 등 …). So the Latin moves to the Hangul.
- Spacing (ink gap ≤ 0 between neighbours at alpha ≥ 4, all Korean lines, `pair_gaps_all.txt`, `pair_gaps_staged.txt`):
  | variant | `font` pairs / occurrences | `font_btl` |
  |---|---|---|
  | shipped | 58 / 692 | 71 / 594 |
  | 1DX KR itself | 6 / 24 | 31 / 205 |
  | 1DX glyphs squeezed onto the 3DX advances (`variants/min`) | 35 / 329 | 144 / 1,282 |
  | **staged** (1DX metrics for letters/digits) | **11 / 60** | **41 / 388** |
- Tone and weight of 3DX Latin and 1DX Hangul are similar (`tone.txt`, ~40 % full-alpha pixels); the mismatch is shape,
  width and position.

## 4. Standard (decision)

1. **Size per element = the original game** (no code change): list rows, slots, item/gear names, notices → `font`
   (16 px Hangul); descriptions, badge effects, help, 능력-page gear names → `font_btl` (12 px); big titles → `font_l`.
2. **One design and one baseline per font**: every glyph Korean text uses comes from the 1DX Korean font of the same
   role, with 1DX's vertical relation to the Hangul.
   - Hangul: unchanged (1DX copy / composed / rendered as installed).
   - ASCII letters and digits (62): 1DX pixels, moved by the Hangul's shift (`font` +1, `font_btl` −1 vs the 1DX cell);
     **1DX CWDH** (advance and bearings) — the spacing the Korean 1DX uses.
   - ASCII punctuation in both fonts (`! % & ( ) + , . / : = ? ~`, 13): 1DX pixels on the same shift; advance stays
     the installed one (= merge_ko model) and grows only if the glyph core would touch (`+`, `/`, `=`); free bearing
     kept on the side 1DX has it (trailing marks keep their left bearing, `(` its right one).
   - Space keeps 5 / 4 px; full-width symbols (`…「」―↑☆♪`) unchanged (kanji-box glyphs, already centred like Hangul).
   - `font_l` unchanged (not used by these menus; only style 2/7/10 text such as `Menu_KJ_manu_gide_15`).
3. Rejected: (a) 1DX metrics for punctuation too — changes 12,200 lines (every `. ! ?`), 3 lines over the Japanese
   maximum (`real_width_1dx.txt`); (b) 1DX glyphs on 3DX advances — crowded (§3); (c) loading 1DX `font_sys` into slots
   3/4 for menus only — needs a code patch + ~0.8 MB more font memory; not static-verifiable, not in scope.

## 5. Staged build — `work/build/menu_font_stage/`

`build_menu_font.py` (inputs: installed `patch/…/Msg/JP_ja/font.bffnt`, `font_btl.bffnt` + 1DX `ml 1dx/3romfs/Msg/KR_ko/`
same names, all read-only) → `romfs/Msg/JP_ja/font.bffnt`, `font_btl.bffnt`, `manifest.json` (every changed glyph: old/new
CWDH, 1DX CWDH, rows).

| file | installed sha256 | staged sha256 | size |
|---|---|---|---|
| `font.bffnt` | `461125B9…4209941` | `09A5858EE6994B1A181302542C731341B9F796F0CDD6C575558CA2F466C2CD0A` | 549,096 (same) |
| `font_btl.bffnt` | `87428160…2BA117681` | `2D6A0B1934061AA29EF6166ABCE66EF9CF85DDE20D341056DAB736645C3709EB` | 284,936 (same) |

Verification (all **confirmed**, built in `build_menu_font.py`):
- Installed fonts round-trip byte-identically through libbffnt; staged output round-trips too.
- Same header metrics, sheet count/size/format, file size; CMAP identical; CWDH identical except the 75 listed glyphs;
  every other glyph cell and every pixel outside the cells identical; each replaced cell equals the 1DX ink exactly.
- `--check` rebuild = staged bytes; applying the builder to its own output gives the same bytes (idempotent).
- Widths: real pixel widths of all 22,868 (line, font) pairs in the font the game uses (`real_width.py` →
  `real_width.txt`): 1,354 lines change, max +18 px (`9898 88241 983`), **0 lines newly wider than the widest Japanese
  line of their (file, style)**. merge_ko model with the new advances (`width_impact.py staged` → `width_impact.txt`):
  0 lines over limit. HugeBattle layout TextBoxes (`font.bffnt`, `hb_fonts.txt`): 11 lines +2..7 px, widest 216 of
  240 px (`hb_text_check.txt`).
- Touching glyph pairs: `font` 11 pairs / 60 occurrences, `font_btl` 41 / 388 (shipped 58 / 692 and 71 / 594).
- Sheets: `sheets/final_v1_1.png`…`_3.png` (JP original / KO shipped / KO staged for the RT5 screens' strings and two
  dialogue pages), `sheets/protoB_*.png` (variants), `sheets/specimen_*`, `mixed_*`.

## 6. For the lead (not done here)

1. Install = copy the two staged files over `patch/00040000001CA900/romfs/Msg/JP_ja/` (+ junction/SD/ZIP sync; file count
   stays 38). Re-run `build_menu_font.py` after any future `build_font.py` run (it post-processes the installed fonts).
2. `scripts/merge_ko.py` width model reads ASCII advances from the original 3DX font: add the 52 values in
   `work/build/menu_font_stage/merge_ko_ascii_widths.json` (`"font"`) after `EXTRA_ASCII_WIDTH`, e.g.
   `adv.update(json.load(open(ROOT/"work/build/menu_font_stage/merge_ko_ascii_widths.json"))["font"])`. Checked here: no
   current line exceeds a limit with them.
3. AGENTS.md §7 rule "영문·숫자·?·.·공백은 3DX 원래 글리프" changes to: letters/digits/punctuation = 1DX glyphs on the
   Hangul baseline (1DX CWDH for letters/digits), space 3DX.

## 7. How RT should verify (Azahar, then New 3DS)

Build = patch romfs with the two staged fonts (rt_mods overlay). Same screens as RT5 §2 under `use-patch` vs staged:
1. 장비, MARIO slots: `퍼펙트웨어 / POW부츠DX / POW글러브DX` — Latin same height, weight and bottom line as Hangul; text
   inside the slot boxes. 2. 장비 list (`POW부츠DX 2`), KOOPA `파워팔찌SP`, top description `POW가 증가하는 부츠.`
3. 아이템 `슈퍼버섯` description `HP를 50 회복.` (digits same size as Hangul). 4. 배지 `배틀 종료 시 획득 EXP가 2배.`
5. 능력 page gear list (`font_btl`), 기록 `Excellent 횟수`. 6. A dialogue page with `! ? .` (save-block shop
   `오우! 신사!`) and descenders `g p y ( )` — nothing clipped at the line top/bottom. 7. A giant-battle guide page.
Pass = no string shows two typefaces; no clipping/overflow; nothing else on screen moves. File sizes and sheet counts
are unchanged, so font memory use is unchanged (**confirmed** statically; runtime not run).

## 8. Notes / open
- `font_l` still mixes 3DX Latin with 1DX Hangul (and 1DX glyphs upscaled ×1.5); same rule could be applied later with
  1DX `font_l` Latin (digits `0 5–9` need +1–3 px). Not in these menus.
- Menu-only lighter 1DX system design (`font_sys*`) would need a code patch (§4.3c); not proposed.
- Image text (headers/tabs, `SUYEOM` stat label touching its number on 장비/능력) belongs to the image workstream.

## 9. Files
Tools `tools/` (bflyt pane reader, BFFNT renderer, census/metrics/width/gap checks); data `styles.txt`, `metrics.txt`,
`tone.txt`, `fit_check.txt`, `charuse.txt`, `latin_census.txt`, `real_width*.txt`, `width_impact.txt`,
`pair_gaps*.txt`, `hb_*.txt`, `font_info.txt`, `font_table*.txt`, `cmp_1dx_fonts.txt`; images `crops/`, `sheets/`.


## 10. v2 — tight Latin/digit advances, width re-check, SUYEOM label (FONT2, 2026-10-30) — done (staged, offline)

Worker FONT2 (continues FONT). Offline only (no emulator). Writes: `work/build/menu_font_stage/` (new files only:
`v2_spacing.py`, `v2_spacing*.json/txt`, `build_menu_font_v2.py`, `v2/`), `work/build/suyeom_label_stage/`, this
folder (`tools/v2_*.py`, `v2_*.txt`, `sheets/v2_*.png`). v1 files are untouched.

### 10.1 Why v1 looks letter-spaced (confirmed, `v2_measure.txt`, `v2_optical.txt`)
Core ink (alpha >= 4/15) box gap between neighbours, frequency-weighted over the Korean text:

| font | Hangul-Hangul | JP original kana-kana | JP original Latin-Latin | v1 Latin-Latin | shipped (3DX) Latin-Latin |
|---|---|---|---|---|---|
| `font` | 2.17 px | 2.11 | **1.06** | **2.46** | 1.16 |
| `font_btl` | 1.71 | 1.55 | **1.02** | **1.91** | 1.05 |

The Japanese original sets its Latin 1 px apart next to 2 px kana gaps, and that reads as even spacing (Latin letters
have open counters and straight edges, kana/Hangul fill their box). v1 copied the 1DX bearings (1–2 px on each side),
so Latin got the Hangul's numeric gap (2–3 px) and reads as letter-spaced. A white-area model (`tools/v2_optical.py`)
says the same: JP Latin-Latin has about half the white of kana-kana. So "a Hangul-like gap" for Latin = the JP
original's Latin letterfit, not the Hangul's 2 px.

### 10.2 Decision: v2 rule (confirmed by build + checks; looks: sheets, not run in the game)
Pixels and rows stay exactly v1 (1DX shapes on the Hangul baseline). Only CWDH (left, char) of the 62 letters and
digits changes, per font, from the table `work/build/menu_font_stage/v2_spacing.json` (made by `v2_spacing.py`):
1. **Base = the Japanese original's Latin letterfit**: the core ink (alpha >= 4/15) starts at the pen and leaves
   1 px on the right (the JP 3DX font does this for most of its Latin), so letters/digits sit 1 px apart.
   One-stroke glyphs get more white, as JP does: `I i l` 1/1 px, digit `1` 1/2 px (otherwise `1111`, `Ill` read as bars).
2. **Nothing is clipped**: every ink pixel (alpha > 0) lies inside [pen, pen + advance); glyph width = v1 ink width.
3. **Nothing touches**: no core pixel of a letter/digit is 8-adjacent to a core pixel of its neighbour, checked for
   every pair in the Korean text drawn with that font (style -> font as `MessageSimple::GetFont`; style 13/255 ->
   both, except battle names = BMsg style 13 without `KJ` in the label -> `font_btl` only: drawn through
   `MonName_Lv` (style 0) or the target window whose default font slot is 4 (`Battle.c` line 12882), **likely**),
   the runtime pairs around string variables (one-line style-13 names x the characters next to `[0003:0001]`),
   the characters next to number variables x every digit, and all digit x digit pairs (611 / 378 pairs). 0 touch.
   Where a pair would touch, the Latin glyph gets 1 px on that side: `font` 2 3 4 (퍼즐피스2/3/4), C (울트라C),
   D (글러브DX); `font_btl` 2 3 4, D, S (이빨SP), X (비삐더스X). A local search then takes pixels back where safe
   (only `font` B moved). So `DX` is 1 px apart in `font` (menus) and 2 px in `font_btl`.
4. Space (5 / 4 px) and punctuation stay as v1: next to the tighter Latin they do not look loose (`FULL!` keeps
   3 px before `!`, the 1DX design). Full-width symbols, Hangul, everything else: untouched.

Rejected (sheets `v2_candidates_*`): white-area models `optical`/`jpchar` (Latin-Latin 1.4–2.0 px, still loose),
`box` (rule 1 without the one-stroke exception: `1111`, `Ill` cramped), `stem` (no fit: `DX` 2 px in the menus).

Result on the Korean text (core box gap, frequency-weighted; `v2_spacing.txt`):

| font | Latin-Latin v2 (v1 / JP original) | Latin→Hangul | Hangul→Latin | Hangul-Hangul |
|---|---|---|---|---|
| `font` | **1.10** (2.46 / 1.06), 90 % at 1 px | 1.77 | 1.66 | 2.17 |
| `font_btl` | **1.21** (1.91 / 1.02), 79 % at 1 px | 1.33 | 1.78 | 1.71 |

Advances shipped(3DX) / v1 / v2, `font`: 0 11/13/12, 1 9/9/8, 2 11/11/11, 3 11/12/11, 4 11/12/12, 5 11/12/10,
6 10/12/10, 7 10/11/11, 8 10/12/11, 9 10/12/10, A 14/14/13, B 12/13/10, C 13/14/13, D 12/13/12, E 11/12/11,
F 10/12/11, G 13/14/12, H 11/13/11, I 5/6/5, L 9/11/10, M 14/15/13, O 13/14/12, P 11/12/11, S 12/12/12,
U 12/13/11, W 16/16/16, X 11/12/11, e 11/11/10, l 6/6/5, n 10/12/9 … (all 62 in `v2/manifest.json`); sum of the
62 advances 655 / 724 / **642**. `font_btl` sum 494 / 550 / **510** (the 1DX `font_btl` shapes are wider than 3DX's).

Box-gap metric of v1's report (`tools/pair_gaps.py`, gap <= 0 at alpha >= 4, `v2_pair_gaps.txt`): `font` 14 pairs /
68 occurrences (v1 11/60), `font_btl` 32 / 373 (v1 41/388). The letter/digit ones in `font` (`파7` x12, `타X` x3,
`.0` x3, `파X` x2, `스X` x1 = battle name, drawn in `font_btl`) have 0 px box gap but no contact (8x zoom checked);
all others are punctuation/Hangul pairs that v1 already had (`―!` x128, `아~` x88, `.)` …), not changed here.

### 10.3 Width checks (confirmed, `v2_width_check.txt`, tool `tools/v2_width_check.py`)
- Real pixel widths, all 22,868 (line, font) pairs: **0 lines newly wider than the widest Japanese line of their
  (source, style)** (the one line over, `Menu#628` font_btl, is over in shipped and v1 too: style 13 counted in both
  fonts). vs shipped: 698 lines wider (max +6 px, `Excellent 횟수가 500회를 넘는다`, `=== 알림 ===` in font_btl),
  210 narrower. vs v1: 1,205 narrower (max −17 px), 38 wider by <= 2 px (`SS컴퍼니` in font_btl).
- `scripts/merge_ko.py` model with the v2 table: 18,510 translator lines, **0 over limit** (current model 0).
- HugeBattle TextBoxes (240 px, `font`): widest Korean line 234 px; `Excellent` lines 149 → 144 px.
- Runtime numbers:
  - **Image digits, not affected**: pause-menu HP/SP/POW/DEF/SPEED/SUYEOM, LV, EXP/NEXT (`NUM_G_s.bflyt`, panes
    `SNUM_*`, `MainMenu.c` 4183/8017/9558–9563), 기록 counts incl. Excellent 횟수 (`MENU_RECORD_L_LIST` +
    `NUM_G_s`/`NUM_G_s_slash`, `MainMenu.c` 17250–17266), item/gear counts (list `NUM_G_s`), shop prices and coins
    (`msys::MLytNum`, `ShopMenu.c` 8546–8556), battle-result stats (`BTL_STATUS_SET_RESULT` `SNUM_*_DIGIT_n`),
    battle HP/SP counters (`ad::ui::SlotDigits`, `Battle.c` 11297, **likely**). **confirmed** from code + RT5 grabs.
  - **Font-drawn numbers = message number variables** `[0003:0000:…]`, filled by
    `MessageSimple::InsParam::setNum(idx, value, fullwidth)` (static `FUN_0024ef48`; module copies Battle
    `FUN_11028778`, KJMenu `FUN_138268a8`, KJRPG `FUN_14028c58`; inline copies in ShopMenu/Colosseum/AttackMiniGame).
    Every call site passes fullwidth = 1 (digits + 0xFEE0 → U+FF10..FF19, the unchanged 3DX full-width glyphs, 16 /
    12 px; disassembly: `mov r3,#1` before each `bl`, e.g. static 0x18b72c–0x18b768, 0x2e884c–0x2e8888, 0x327cbc–
    0x327d04, Battle 0x110561b8–0x110561f4, KJMenu 13 sites, KJRPG 5) — **except one**: Battle `FUN_11027d84`
    (0x11027eb4, `mov r3,#0`) = enemy level in the target window, `BMsg/b_sys#1215 MonName_Lv` `{name} LV{level}`,
    style 0 = `font_btl`. Widest realistic value: `블리자드메타보스 LV100` = 142 px with v2 (shipped 139, v1 145)
    against the Japanese original's widest `ガラクタモンスターX LV100` = 161 px → fits (**confirmed** offline).
- `merge_ko_ascii_widths.json` regenerated for v2: `work/build/menu_font_stage/v2/merge_ko_ascii_widths.json`
  (36 `font` advances that differ from the current model, + `font_btl` reference). The root-level file is v1's.

### 10.4 SUYEOM stat label (confirmed offline; `work/build/suyeom_label_stage/`)
- Cause: the installed `ST_HIGE_00_JP_ja` (42×12 LA4, alpha-only white pixel letters, `scripts/lyt_C_stat.py` job
  `ST_HIGE`) spreads S U Y E O M over all 42 px (ink x 0..41; the M's last column is cut by the texture edge). In the
  menu stat rows (layout `STATUS_SET`: label pane x 14..56, number `SNUM_HT` right-aligned at 97) the hundreds digit
  starts at label texel ~40.5 (measured on `menu_gear_patch_7_R2.png`), so `SUYEOM126` touches. Japanese labels end
  at x 13..34 (SPEED 32 → 7.5 texels to the digit, TSUNO 34 → 5.5).
- Fix: same ST letters, condensed (S without its faint left column; U, Y, O one counter column less; E; M without the
  cut column; installed spacing) → 38 px, then `lyt_C_stat.hfit` (the C group's 장평 tool, >= 80 % rule) to 33 px
  (87 %) → **ink x 0..32 = SPEED's width, 7.5 texels to the number like SPEED** (`sheets/v2_suyeom_label_texels.png`,
  in-place mock on the RT5 grab `sheets/v2_suyeom_label_rows.png`; candidates A = installed letters squeezed 81 %
  (soft), B = condensed without squeeze (gap 2.5) kept in `candidates/`).
- Build `build_suyeom.py build`: baseline = installed `patch/…/Lyt/JP/MLyt.dat` (`FEC2BAC8…62F7`, = lyt_stage);
  the five copies of the one texture (MENU_ITEM / MENU_SHOP / MENU_MAIN / MENU_EQUIP / MENU_STATUS) replaced in place
  → `romfs/Lyt/JP/MLyt.dat` `14F0AA9A6C228D990BABAD0802D910E42F7EFD70619FEA983333C9FA4CDF5987` (5,110,228 B; BG4
  slot re-compression +128 B). Checks (`build_verify.json`): empty BG4 rebuild = baseline; baseline copies decode to
  the installed input PNG; unchanged re-encode byte-identical; only those five BFLIMs differ (same size/header/
  footer), every other SARC file and archive entry byte-identical; new BFLIMs decode exactly to the new PNG; rebuild
  reproducible (same hash twice). New build_lyt input: `ko/lyt/MLyt/MENU_ITEM_Lyt_JP_ja/ST_HIGE_00_JP_ja.png`.
- Not changed: `STbr_HIGE_00_JP_ja` (battle result, 60×16). Layout `BTL_STATUS_SET_RESULT`: label pane from x 9, its
  SUYEOM ink ends at x 9 + 57 = 66; the hundreds-digit pane `SNUM_HIGE_DIGIT_3` is at x 81 with a 13 px digit pitch,
  so about 8–9 px stay free if the digit is centred on its pane → no contact (**likely**; no grab of this screen).
  It is still wider than the Japanese STbr labels (SPEED ends at 43), if the lead wants it matched later.

### 10.5 Files
| file | sha256 / note |
|---|---|
| `work/build/menu_font_stage/v2/romfs/Msg/JP_ja/font.bffnt` | `A786316C26FE260F8C1DDEE90BA9FFF5494EEE67155BE2AD67FA37845FE569B2`, 549,096 B (= installed size) |
| `work/build/menu_font_stage/v2/romfs/Msg/JP_ja/font_btl.bffnt` | `6C058D36905FC09CABF7DA95D54F9132A285054205D357F086FF1029EA9F62B7`, 284,936 B |
| `work/build/menu_font_stage/v2/manifest.json`, `v2/merge_ko_ascii_widths.json` | per-glyph v1→v2 CWDH, verify result; merge_ko table |
| `work/build/menu_font_stage/build_menu_font_v2.py` (`--check`), `v2_spacing.py` (+ `v2_spacing*.json/txt`) | builder (v1 transform + table) / table derivation and no-touch report |
| `work/build/suyeom_label_stage/` | `build_suyeom.py`, `romfs/Lyt/JP/MLyt.dat`, `ko/lyt/…/ST_HIGE_00_JP_ja.png`, `build_verify.json`, `candidates/` |
| `sheets/v2_final_1..5.png` | JP original / KO shipped / KO v1 / KO v2 for the RT5 menu strings + dialogue |
| `sheets/v2_specimen_font.png`, `v2_specimen_font_btl_1..2.png` | digits, names, letter pairs: JP 3DX / v1 / v2 |
| `sheets/v2_candidates_*.png`, `v2_suyeom_label_*.png` | rule candidates; SUYEOM label texels and in-place mock |
| `v2_measure.txt`, `v2_optical.txt`, `v2_width_check.txt`, `v2_pair_gaps.txt`, `tools/v2_*.py` | measurements |

v2 builder verification (`build_menu_font_v2.py --check`, 0 errors): the in-memory v1 transform equals the staged v1
files; header/TGLP/KRNG/CMAP/sheet count/file size equal to installed; sheet pixels equal to v1; CWDH equal to
installed except the 75 v1 glyphs, equal to v1 except the 62 letters/digits; every letter/digit ink inside its
advance box; output round-trips through libbffnt; rebuild = staged bytes.

### 10.6 For the lead (install; nothing installed here)
1. Fonts: copy the two `v2/romfs/Msg/JP_ja/*.bffnt` over `patch/00040000001CA900/romfs/Msg/JP_ja/` (+ junction / SD /
   ZIP; file count stays 38). Re-run `build_menu_font.py` then `build_menu_font_v2.py` after any `build_font.py` run.
2. `scripts/merge_ko.py`: `adv.update(json.load(open(ROOT/"work/build/menu_font_stage/v2/merge_ko_ascii_widths.json",
   encoding="utf-8"))["font"])` after `EXTRA_ASCII_WIDTH` (checked: 0 lines over limit).
3. SUYEOM: copy `work/build/suyeom_label_stage/romfs/Lyt/JP/MLyt.dat` over `patch/…/romfs/Lyt/JP/MLyt.dat` (+ lyt_stage,
   SD, ZIP) and `ko/lyt/MLyt/MENU_ITEM_Lyt_JP_ja/ST_HIGE_00_JP_ja.png` over `work/img/ko/lyt/…` so build_lyt reproduces
   it; optionally put the condense+hfit recipe into `lyt_C_stat.py` job `ST_HIGE`. Baseline was MLyt `FEC2BAC8…`; if
   MLyt changes before install, re-run `build_suyeom.py build`.
4. AGENTS.md §7 text: letters/digits = 1DX glyphs on the Hangul baseline with JP-original letterfit (0/1 px core
   bearings, no touching), space and punctuation as v1.

### 10.7 What RT should check (Azahar, then New 3DS; build = patch + the two v2 fonts + the staged MLyt.dat)
1. 장비 MARIO/LUIGI slots and lists: `POW부츠DX`, `POW글러브DX`, `파워팔찌SP`, `1UP버섯DX` — Latin as tight as the Hangul,
   no letter touching a neighbour, `DX` 1 px apart; the left stat column `SUYEOM 126` with a gap like `SPEED 137`.
2. Top description `POW가 증가하는 부츠.`, 아이템 `HP를 50 회복.`, 배지 `배틀 종료 시 획득 EXP가 2배.`, 기록 `Excellent 횟수`,
   능력 gear list (font_btl) — `Excellent` / `POW` not letter-spaced; `SUYEOM` on the 능력 panel still left of its number.
3. A battle: target an enemy (`{name} LV{n}` window, e.g. 비삐더스X / 블리자드메타보스) — name + level inside the window,
   `스X` not touching; a shop / Colosseum prize message with numbers (full-width digits, unchanged).
4. Dialogue with `! ? .` and numbers (`9898 88241 983` puzzle page, `342승 341패`), a giant-battle guide page.
Pass = no letter/digit touches or is cut, Latin looks as tight as in the Japanese original, nothing else moves.
