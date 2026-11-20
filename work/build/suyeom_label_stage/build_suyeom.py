"""FONT2 (wave 5, 2026-10-30): narrower SUYEOM stat label (ST_HIGE_00_JP_ja, menu stat panels) -> staged MLyt.dat.

    .venv\\Scripts\\python work\\build\\suyeom_label_stage\\build_suyeom.py preview   candidates + sheets only
    .venv\\Scripts\\python work\\build\\suyeom_label_stage\\build_suyeom.py build     chosen label -> romfs/Lyt/JP/MLyt.dat

Problem (RT5 grab work/review/rt5_20261030/menu_gear_patch_7_R2.png, confirmed here): the installed label
(scripts/lyt_C_stat.py job ST_HIGE) puts six letters S U Y E O M on the full 42 px of the texture (ink x 0..41, the
M's last column even cut by the texture edge). In the menu stat rows (layout STATUS_SET: label pane x 14..56,
number pane SNUM_HT right-aligned at x 97) the hundreds digit starts at texel ~40.5 of the label, so 'SUYEOM126'
touches. The Japanese labels end at x 13..34 (SPEED 32, TSUNO 34: gap 7.5 / 5.5 texels to the hundreds digit).

Fix (same ST pixel letters as the installed label and the 3DX originals, white, alpha only, rows 2..8):
  * condensed letters: S without its faint left column, U / Y / O with one of their two counter columns removed,
    E and M (7 columns, faint right edge dropped) as installed, spacing as installed (one blank column after S,
    the rest abutting through their anti-aliased edge columns) -> ink x 0..37 (38 px);
  * then lyt_C_stat.hfit (area resampling, the C group's 장평 tool, IMAGE_TASK rule >= 80 %) from 38 to 33 px
    (87 %) -> ink x 0..32 = SPEED's right edge, so the gap to the number equals SPEED's.
Build = the installed MLyt.dat (patch/, baseline) with only the five ST_HIGE_00_JP_ja copies (MENU_ITEM/SHOP/MAIN/
EQUIP/STATUS, one texture by sha1) replaced in place (lytimg.rgba_to_bflim + sarc_replace + lib3dx.rebuild_bg4),
like work/img/kj_logo_natural_20261030/build_archive.py. Checks: the baseline copies decode to the installed input PNG
(work/img/ko/lyt/.../ST_HIGE_00_JP_ja.png); unchanged re-encode round-trips byte-identically; empty rebuild of the
BG4 = baseline; only those five BFLIMs differ, every other SARC file and archive entry byte-identical; the new
BFLIMs decode exactly to the quantised new PNG (LA4 lossless); header/size/format unchanged.
Outputs (stage only): ko/lyt/MLyt/MENU_ITEM_Lyt_JP_ja/ST_HIGE_00_JP_ja.png (the new build_lyt input, for the lead
to copy into work/img/ko/lyt on install), romfs/Lyt/JP/MLyt.dat, build_verify.json, candidates/, sheets in
work/review/menu_fonts_20261030/sheets/v2_suyeom_*.png. STbr_HIGE_00_JP_ja (battle result) is not changed: its
SUYEOM ends at x 56 of 60 and the result screen's hundreds digit starts at ~x 63 (layout BTL_STATUS_SET_RESULT).
"""
from __future__ import annotations

import hashlib
import json
import shutil
import sys
from pathlib import Path

import numpy as np
from PIL import Image, ImageDraw

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
sys.path.insert(0, str(ROOT / "scripts"))
import build_lyt  # noqa: E402
import lib3dx  # noqa: E402
import lyt_C_stat as C  # noqa: E402
import lytimg  # noqa: E402

NAME = "ST_HIGE_00_JP_ja"
REL = "MLyt/MENU_ITEM_Lyt_JP_ja/ST_HIGE_00_JP_ja.png"
INSTALLED_PNG = ROOT / "work/img/ko/lyt" / REL
PATCH_MLYT = ROOT / "patch/00040000001CA900/romfs/Lyt/JP/MLyt.dat"
OUT_PNG = HERE / "ko/lyt" / REL
OUT_DAT = HERE / "romfs/Lyt/JP/MLyt.dat"
CAND = HERE / "candidates"
SHEETS = ROOT / "work/review/menu_fonts_20261030/sheets"
GRAB = ROOT / "work/review/rt5_20261030/menu_gear_patch_7_R2.png"
TARGET_W = 33          # ink x 0..32, = SPEED
DIGIT_X = 40.5         # hundreds digit left edge in label texels (measured on the RT5 grab, see sheet)


def drop_col(a: np.ndarray, rows_cols: dict[range, int]) -> np.ndarray:
    """remove one column per row band: {row range: column index} (all bands must remove one column)."""
    out = np.zeros((a.shape[0], a.shape[1] - 1), int)
    for rr, c in rows_cols.items():
        for r in rr:
            out[r] = np.delete(a[r], c)
    return out


def letters():
    """condensed ST letters (12-row alpha arrays, ink rows 2..8)."""
    S = C.st_lv("S")[:, 1:]                                   # 7 -> 6: faint left column
    U = drop_col(C.st_lv("U"), {range(0, 12): 3})              # 7 -> 6: one counter column
    Y = drop_col(C.st_lv("Y"), {range(0, 6): 3, range(6, 12): 4})   # arms: counter column, stem: blank column
    E = C.st_lv("E")                                           # 6
    O = drop_col(C.st_lv("O"), {range(0, 12): 3})              # 7 -> 6
    M = C.st_lv("M")[:, :7]                                    # 8 -> 7: faint right column (cut in the installed one)
    return [("S", S), ("U", U), ("Y", Y), ("E", E), ("O", O), ("M", M)]


def compose(gap_after_s: int = 1) -> np.ndarray:
    a = np.zeros((12, 64), int)
    x = 0
    for i, (ch, g) in enumerate(letters()):
        w = g.shape[1]
        a[:, x:x + w] = np.maximum(a[:, x:x + w], g)
        x += w + (gap_after_s if ch == "S" else 0)
    cols = np.nonzero(a.any(0))[0]
    return a[:, :cols.max() + 1]


def to_la(alpha: np.ndarray, width: int = 42) -> np.ndarray:
    la = np.zeros((12, width, 2), int)
    la[..., 0] = 15
    la[:, :alpha.shape[1], 1] = alpha[:, :width]
    return la


def squeeze(alpha: np.ndarray, target: int) -> np.ndarray:
    la = to_la(alpha, max(42, alpha.shape[1]))
    out = C.hfit(la, target, 42, 0)
    return out


def candidates() -> dict[str, np.ndarray]:
    installed = C.load(INSTALLED_PNG)
    natural = C.st_word("SUYEOM", [0, 8, 15, 22, 28, 35])     # installed recipe (M cut at x 41)
    full = np.zeros((12, 43), int)                              # installed letters, full M -> 43 px
    for ch, x in zip("SUYEOM", [0, 8, 15, 22, 28, 35]):
        g = C.st_lv(ch)
        full[:, x:x + g.shape[1]] = np.maximum(full[:, x:x + g.shape[1]], g)
    cond = compose()
    out = {"installed": installed, "A_squeeze_installed_81pct": squeeze(full, 35),
           "B_condensed_crisp": to_la(cond), "C_condensed_87pct (chosen)": squeeze(cond, TARGET_W)}
    assert np.array_equal(natural[..., 1], installed[..., 1]), "installed label is not the lyt_C_stat recipe"
    for k, la in out.items():
        la[la[..., 1] == 0, 0] = 15
    return out


def ink(la):
    xs = np.nonzero(la[..., 1].any(0))[0]
    return int(xs.min()), int(xs.max())


def mock_rows(cands: dict[str, np.ndarray]) -> Image.Image:
    """the RT5 grab's SPEED / SUYEOM rows with each candidate drawn in place of the installed label
    (label texel 0 = screen x 571.4, 1.645 px per texel; vertical: the grab's label rows)."""
    g = Image.open(GRAB).convert("RGB")
    rows = []
    base = np.asarray(g, np.float32)
    x0, scale = 571.4, 1.645
    y_top = 656 - 2 * scale            # SUYEOM row: ink rows 2..8 start at screen y ~656
    for name, la in [("SPEED row (installed)", None)] + list(cands.items()):
        img = base.copy()
        if name == "installed":                    # the grab as RT5 recorded it
            crop = img[648:676, 545:690]
        elif la is not None:
            # erase the installed label (screen x 570..637, the hundreds digit starts at 638): per column, linear
            # blend between the row background just above and just below the label box
            top, bot = img[651, 570:638].copy(), img[673, 570:638].copy()
            for k, yy in enumerate(range(652, 673)):
                t = (k + 1) / 22
                img[yy, 570:638] = top * (1 - t) + bot * t
            # the installed M overlaps the hundreds digit '1' (x 638..645): take that '1' from the SPEED row above
            # ('137' has its '1' at the same x; row pitch 28 px)
            img[650:674, 634:648] = base[622:646, 634:648]
            a = la[..., 1].astype(np.float32) / 15.0
            big = np.asarray(Image.fromarray((a * 255).astype(np.uint8)).resize(
                (int(round(a.shape[1] * scale)), int(round(a.shape[0] * scale))), Image.BILINEAR), np.float32) / 255
            ys, xs = int(round(y_top)), int(round(x0))
            h, w = big.shape
            reg = img[ys:ys + h, xs:xs + w]
            reg[:] = reg * (1 - big[..., None]) + np.array([235, 240, 245]) * big[..., None]
            crop = img[648:676, 545:690]
        else:
            crop = img[620:648, 545:690]
        tile = Image.fromarray(np.clip(crop, 0, 255).astype(np.uint8)).resize((145 * 4, 28 * 4), Image.NEAREST)
        canvas = Image.new("RGB", (tile.width + 260, tile.height + 4), (30, 30, 30))
        canvas.paste(tile, (260, 2))
        ImageDraw.Draw(canvas).text((6, 40), name, fill=(255, 220, 90))
        rows.append(canvas)
    W = max(r.width for r in rows)
    H = sum(r.height for r in rows)
    out = Image.new("RGB", (W, H), (30, 30, 30))
    y = 0
    for r in rows:
        out.paste(r, (0, y))
        y += r.height
    return out


def texel_sheet(cands: dict[str, np.ndarray]) -> Image.Image:
    """labels at 1x and 10x on the menu panel blue, with the JP SPEED / TSUNO / HIGE and the hundreds-digit edge."""
    z = 10
    items = [("JP SPEED", C.load(C.ST["SPEED"])), ("JP TSUNO", C.load(C.ST["TSUNO"])), ("JP HIGE", C.load(C.ST["HIGE"]))]
    items += list(cands.items())
    rows = []
    for name, la in items:
        rgb = C.on_bg(la, bg=(22, 52, 92))
        big = Image.fromarray(rgb).resize((42 * z, 12 * z), Image.NEAREST)
        d = ImageDraw.Draw(big)
        xd = int(DIGIT_X * z)
        d.line([(xd, 0), (xd, 12 * z)], fill=(255, 80, 80), width=2)
        x1 = ink(la)[1]
        d.line([((x1 + 1) * z, 0), ((x1 + 1) * z, 12 * z)], fill=(90, 200, 255), width=1)
        canvas = Image.new("RGB", (42 * z + 300, 12 * z + 6), (30, 30, 30))
        canvas.paste(Image.fromarray(rgb), (6, 30))
        canvas.paste(big, (300, 3))
        ImageDraw.Draw(canvas).text((60, 30), f"{name}\nink x {ink(la)[0]}..{x1}, gap to digit "
                                                f"{DIGIT_X - (x1 + 1):.1f}", fill=(255, 220, 90))
        rows.append(canvas)
    H = sum(r.height for r in rows)
    out = Image.new("RGB", (max(r.width for r in rows), H), (30, 30, 30))
    y = 0
    for r in rows:
        out.paste(r, (0, y))
        y += r.height
    return out


def save_la(la: np.ndarray, p: Path) -> None:
    C.save(la, p)


def build_archive(new_la: np.ndarray) -> dict:
    baseline = PATCH_MLYT.read_bytes()
    _, entries = lib3dx.read_bg4(baseline)
    if lib3dx.rebuild_bg4(baseline, {}) != baseline:
        raise SystemExit("empty BG4 rebuild differs from the baseline")
    new_png = np.asarray(Image.open(OUT_PNG).convert("RGBA"))
    inst_png = np.asarray(Image.open(INSTALLED_PNG).convert("RGBA"))
    repl, copies, old_sha = {}, [], set()
    for slot, e in enumerate(entries):
        if e.size_flag or not e.data:
            continue
        plain = lib3dx.bg4_plain(e)
        if plain[:4] != b"SARC":
            continue
        files = {}
        for fname, s, t in lytimg.sarc_list(plain):
            if Path(fname).stem != NAME:
                continue
            old = plain[s:t]
            old_sha.add(hashlib.sha1(old).hexdigest())
            hdr = lytimg.parse_bflim(old)
            if not np.array_equal(lytimg.bflim_to_rgba(old), build_lyt.expected(hdr["fmt_name"] if "fmt_name" in hdr
                                                                                   else "LA4", inst_png)):
                raise SystemExit(f"{e.name}/{fname}: baseline copy does not decode to the installed input PNG")
            if lytimg.rgba_to_bflim(old, lytimg.bflim_to_rgba(old)) != old:
                raise SystemExit(f"{e.name}/{fname}: unchanged re-encode is not byte-identical")
            new = lytimg.rgba_to_bflim(old, new_png)
            if len(new) != len(old) or lytimg.parse_bflim(new) != lytimg.parse_bflim(old):
                raise SystemExit(f"{e.name}/{fname}: BFLIM size / header changed")
            if not np.array_equal(lytimg.bflim_to_rgba(new), build_lyt.expected("LA4", new_png)):
                raise SystemExit(f"{e.name}/{fname}: new BFLIM does not decode to the new PNG")
            files[fname] = new
            copies.append(f"{e.name}/{fname}")
        if files:
            repl[slot] = lytimg.sarc_replace(plain, files)
    rebuilt = lib3dx.rebuild_bg4(baseline, repl)
    _, after = lib3dx.read_bg4(rebuilt)
    changed = []
    if len(after) != len(entries):
        raise SystemExit("entry count changed")
    for b, a in zip(entries, after):
        if b.name != a.name or b.size_flag != a.size_flag:
            raise SystemExit("entry names / flags changed")
        if b.data == a.data:
            continue
        p, q = lib3dx.bg4_plain(b), lib3dx.bg4_plain(a)
        fo, fn = lytimg.sarc_list(p), lytimg.sarc_list(q)
        if [f[0] for f in fo] != [f[0] for f in fn]:
            raise SystemExit(f"{b.name}: SARC file list changed")
        for (n1, s, t), (n2, u, v) in zip(fo, fn):
            if p[s:t] != q[u:v]:
                if Path(n1).stem != NAME:
                    raise SystemExit(f"{b.name}/{n1}: untouched file changed")
                if len(p[s:t]) != len(q[u:v]) or p[t - 40:t] != q[v - 40:v]:
                    raise SystemExit(f"{b.name}/{n1}: BFLIM size or footer changed")
                changed.append(f"{b.name}/{n1}")
    OUT_DAT.parent.mkdir(parents=True, exist_ok=True)
    OUT_DAT.write_bytes(rebuilt)
    return {"baseline": str(PATCH_MLYT.relative_to(ROOT)), "baseline_sha256": hashlib.sha256(baseline).hexdigest().upper(),
            "output": str(OUT_DAT.relative_to(ROOT)), "output_sha256": hashlib.sha256(rebuilt).hexdigest().upper(),
            "size": [len(baseline), len(rebuilt)], "texture_copies_replaced": copies, "changed_files": changed,
            "distinct_baseline_texture_sha1": sorted(old_sha), "empty_rebuild_equals_baseline": True,
            "baseline_copies_decode_to_installed_png": True, "unchanged_reencode_identical": True,
            "new_bflims_decode_to_new_png": True, "all_other_files_and_entries_identical": True}


def main():
    mode = sys.argv[1] if len(sys.argv) > 1 else "preview"
    CAND.mkdir(parents=True, exist_ok=True)
    cands = candidates()
    rep = {}
    for k, la in cands.items():
        safe = k.split(" ")[0]
        save_la(la, CAND / f"{safe}.png")
        rep[k] = {"ink_x": ink(la), "gap_to_hundreds_digit_texels": round(DIGIT_X - (ink(la)[1] + 1), 1)}
    for k in ("SPEED", "TSUNO", "HIGE", "DEF", "POW", "HP", "BP"):
        la = C.load(C.ST[k])
        rep["JP " + k] = {"ink_x": ink(la), "gap_to_hundreds_digit_texels": round(DIGIT_X - (ink(la)[1] + 1), 1)}
    SHEETS.mkdir(parents=True, exist_ok=True)
    texel_sheet(cands).save(SHEETS / "v2_suyeom_label_texels.png")
    mock_rows(cands).save(SHEETS / "v2_suyeom_label_rows.png")
    print(json.dumps(rep, ensure_ascii=False, indent=1))
    if mode == "build":
        chosen = cands["C_condensed_87pct (chosen)"]
        save_la(chosen, OUT_PNG)
        res = build_archive(chosen)
        res["label"] = {"png": str(OUT_PNG.relative_to(ROOT)), "png_sha256": hashlib.sha256(OUT_PNG.read_bytes()).hexdigest().upper(),
                        **rep["C_condensed_87pct (chosen)"]}
        res["candidates"] = rep
        (HERE / "build_verify.json").write_text(json.dumps(res, ensure_ascii=False, indent=1), "utf-8")
        print(json.dumps({k: res[k] for k in ("output_sha256", "texture_copies_replaced", "changed_files")}, indent=1))


if __name__ == "__main__":
    main()
