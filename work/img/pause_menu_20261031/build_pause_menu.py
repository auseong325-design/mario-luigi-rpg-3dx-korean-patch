"""Star (pause) menu labels: one lettering and one size for all six, 능력 -> 스테이터스 (2026-10-31 user request).

    .venv\\Scripts\\python work\\img\\pause_menu_20261031\\build_pause_menu.py preview   label PNGs + sheets + numbers
    .venv\\Scripts\\python work\\img\\pause_menu_20261031\\build_pause_menu.py build     + staged romfs/Lyt/JP/MLyt.dat

Request 1: the six labels under the star-menu icons use irregular lettering; rename 능력 to 스테이터스 like the
Korean RPG1 DX menu. Request 2 (same day, replaces the first lettering choice): the Japanese labels are plain and
even, so draw ALL labels (아이템 장비 스테이터스 기록 배지 가이드) in the lettering and size of the old 배지 / 능력.

Cause of the irregularity (REPORT.md): scripts/lyt_B.py made 아이템 / 장비 / 기록 / 가이드 from 1DX menu
pictures (rounded image lettering, each scaled by its own bounding box: 0.812 / 0.812 / 0.765 / 1.0, so 가이드 came
out larger and lower) and 배지 / 능력 from the 1DX dialogue bitmap font. Two designs, four sizes.

Recipe (v2, installed): exactly the old 배지 / 능력 recipe of lyt_B.make_one, for every label:
  lyt_B.compose(it, [("font", word, "font")], em=13, outline=1.85, stroke=2.4)
  = 1DX KR dialogue bitmap font `font` (17x18, Hangul em 15) reduced to em 13 (x0.867), thickened to the menu_top
  stroke 2.4 px (1 px gaps kept), 3DX black outline 1.85 px, LA4, centred at x 40.
  The only change: one vertical centre for all six (cy 12.0 = texture centre, the old 배지 value). lyt_B took cy from
  each Japanese word's box (11.5 or 12.0), which would leave a half-pixel step between neighbours.
  Check: with lyt_B's own cy the recipe reproduces the pre-change 배지 and 능력 PNGs pixel for pixel.
v1 (1DX menu-picture lettering at one scale) was installed for a few minutes and is superseded; its PNGs are kept in
work/build/prev_pause_menu_20261031b/ko_png/.
Build = the installed MLyt.dat (patch/) with only the TOP_MENU_TEXT_* textures of the changed labels replaced in place
(all copies), checked like work/build/suyeom_label_stage/build_suyeom.py.
"""
from __future__ import annotations

import hashlib
import json
import sys
from pathlib import Path

import numpy as np
from PIL import Image, ImageDraw

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
sys.path.insert(0, str(ROOT / "scripts"))
import build_lyt  # noqa: E402
import lib3dx  # noqa: E402
import lyt_B as B  # noqa: E402
import lytimg  # noqa: E402

JP = ROOT / "work/img/lyt/3DX/MLyt/MENU_MAIN_JP_ja"
KO = ROOT / "work/img/ko/lyt/MLyt/MENU_MAIN_JP_ja"
PRE = ROOT / "work/build/prev_pause_menu_20261031/ko_png"     # PNGs before 2026-10-31 (old 배지 / 능력 / ...)
OUT_KO = HERE / "ko/lyt/MLyt/MENU_MAIN_JP_ja"
PATCH_MLYT = ROOT / "patch/00040000001CA900/romfs/Lyt/JP/MLyt.dat"
OUT_DAT = HERE / "romfs/Lyt/JP/MLyt.dat"
SHEETS = HERE / "sheets"
W, H = 80, 24
EM, OUTLINE, STROKE = 13, 1.85, 2.4      # lyt_B FAMP["menu_top"]
CY = 12.0                                # one vertical centre for all labels (texture centre = old 배지)
BG = (40, 70, 140)

# menu order
LABELS = {
    "TOP_MENU_TEXT_1_00_JP_ja": "아이템",
    "TOP_MENU_TEXT_2_00_JP_ja": "장비",
    "TOP_MENU_TEXT_3_00_JP_ja": "스테이터스",
    "TOP_MENU_TEXT_4_00_JP_ja": "기록",
    "TOP_MENU_TEXT_5_00_JP_ja": "배지",
    "TOP_MENU_TEXT_6_00_JP_ja": "가이드",
}
OLD_WORDS = {"TOP_MENU_TEXT_3_00_JP_ja": "능력", "TOP_MENU_TEXT_5_00_JP_ja": "배지"}   # drawn with this recipe before


def load(p: Path) -> np.ndarray:
    return np.asarray(Image.open(p).convert("RGBA"), dtype=np.float64) / 255.0


def plan_items() -> dict:
    return {b: it for b, it in B.by_base().items() if b in LABELS}


def draw(it: dict, word: str, cy: float | None):
    return B.compose(it, [("font", word, "font")], em=EM, outline=OUTLINE, stroke=STROKE, cy=cy)


def saved_pixels(rgba: np.ndarray) -> np.ndarray:
    """the RGBA8 pixels T.save_png writes for `rgba` (what build_lyt reads back)."""
    import imgtext as T
    tmp = HERE / "_probe.png"
    T.save_png(rgba, tmp)
    px = np.asarray(Image.open(tmp).convert("RGBA")).copy()
    tmp.unlink()
    return px


def measure(rgba: np.ndarray) -> dict:
    import imgtext as T
    face = B.face_cov(rgba)
    fb = B.bbox(face)
    ab = B.bbox(rgba[..., 3])
    mid = float(((face > 0.2) & (face < 0.8)).sum() / max((face > 0.2).sum(), 1))
    return {"fill": list(fb), "fill_w": fb[2] - fb[0], "fill_h": fb[3] - fb[1], "ink": list(ab),
            "stroke": round(float(T.stroke_width(face)), 2), "soft_fill_share": round(mid, 3)}


def make_all() -> tuple[dict, dict]:
    items = plan_items()
    rep = {"recipe": {"font": "1DX KR font (dialogue)", "em": EM, "outline": OUTLINE, "stroke": STROKE, "cy": CY},
           "reproduce_old": {}, "labels": {}}
    # the recipe is lyt_B's: with lyt_B's own centre it must give the pre-change 배지 / 능력 PNGs byte for byte
    for base, word in OLD_WORDS.items():
        ko, _ = draw(items[base], word, None)
        same = bool(np.array_equal(saved_pixels(ko), np.asarray(Image.open(PRE / f"{base}.png").convert("RGBA"))))
        rep["reproduce_old"][f"{base} {word}"] = same
        if not same:
            raise SystemExit(f"recipe does not reproduce the old {word} ({base})")
    out = {}
    for base, word in LABELS.items():
        ko, info = draw(items[base], word, CY)
        out[base] = ko
        rep["labels"][base] = {"word": word, **{k: info[k] for k in ("sources", "hscale", "tracking", "width", "avail")},
                               **measure(ko)}
    return out, rep


# ----------------------------------------------------------------------------- sheets


def on_bg(rgba: np.ndarray, z: int) -> Image.Image:
    a = rgba[..., 3:4]
    rgb = rgba[..., :3] * a + np.array(BG, np.float64)[None, None] / 255 * (1 - a)
    im = Image.fromarray(np.clip(rgb * 255 + 0.5, 0, 255).astype(np.uint8))
    return im.resize((im.width * z, im.height * z), Image.NEAREST)


def sheet_labels(new: dict, path: Path) -> None:
    """rows = labels in menu order; columns = JP, before 2026-10-31, new (4x)."""
    z = 4
    cw, ch = W * z, H * z
    cols = ["JP", "KO before 10-31", "KO new"]
    img = Image.new("RGB", (40 + 3 * (cw + 12), 22 + len(LABELS) * (ch + 10)), (24, 24, 30))
    d = ImageDraw.Draw(img)
    for c, name in enumerate(cols):
        d.text((40 + c * (cw + 12), 5), name, fill=(255, 220, 90))
    for r, base in enumerate(LABELS):
        y = 20 + r * (ch + 10)
        d.text((4, y + 40), base.split("_")[3], fill=(255, 255, 255))
        before = PRE / f"{base}.png" if (PRE / f"{base}.png").exists() else KO / f"{base}.png"
        for c, rgba in enumerate([load(JP / f"{base}.png"), load(before), new[base]]):
            img.paste(on_bg(rgba, z), (40 + c * (cw + 12), y))
    img.save(path)


def sheet_row(new: dict, path: Path) -> None:
    """the six labels in one row as the menu shows them (1x, then 3x): JP, before 10-31, new."""
    def row(get, z):
        im = Image.new("RGB", (len(LABELS) * W * z, H * z), BG)
        for i, b in enumerate(LABELS):
            im.paste(on_bg(get(b), z), (i * W * z, 0))
        return im

    def before(b):
        p = PRE / f"{b}.png"
        return load(p if p.exists() else KO / f"{b}.png")
    jp = lambda b: load(JP / f"{b}.png")  # noqa: E731
    nw = lambda b: new[b]  # noqa: E731
    parts = [("JP 1x", row(jp, 1)), ("before 1x", row(before, 1)), ("new 1x", row(nw, 1)),
             ("JP 3x", row(jp, 3)), ("before 3x", row(before, 3)), ("new 3x", row(nw, 3))]
    wmax = max(p.width for _, p in parts) + 110
    img = Image.new("RGB", (wmax, sum(p.height + 8 for _, p in parts) + 6), (24, 24, 30))
    d = ImageDraw.Draw(img)
    y = 4
    for name, p in parts:
        d.text((4, y + p.height // 2 - 5), name, fill=(255, 220, 90))
        img.paste(p, (106, y))
        y += p.height + 8
    img.save(path)


# ----------------------------------------------------------------------------- archive


def build_archive(new_png: dict[str, Path]) -> dict:
    baseline = PATCH_MLYT.read_bytes()
    _, entries = lib3dx.read_bg4(baseline)
    if lib3dx.rebuild_bg4(baseline, {}) != baseline:
        raise SystemExit("empty BG4 rebuild differs from the baseline")
    new_rgba = {t: np.asarray(Image.open(p).convert("RGBA")) for t, p in new_png.items()}
    inst_rgba = {t: np.asarray(Image.open(KO / f"{t}.png").convert("RGBA")) for t in new_png}
    repl, copies, old_sha = {}, [], {}
    for slot, e in enumerate(entries):
        if e.size_flag or not e.data:
            continue
        plain = lib3dx.bg4_plain(e)
        if plain[:4] != b"SARC":
            continue
        files = {}
        for fname, s, t in lytimg.sarc_list(plain):
            stem_ = Path(fname).stem
            if stem_ not in new_png:
                continue
            old = plain[s:t]
            old_sha.setdefault(stem_, set()).add(hashlib.sha1(old).hexdigest())
            fmt = lytimg.parse_bflim(old)["fmt"]
            if fmt != "LA4":
                raise SystemExit(f"{e.name}/{fname}: format {fmt}, expected LA4")
            if not np.array_equal(lytimg.bflim_to_rgba(old), build_lyt.expected("LA4", inst_rgba[stem_])):
                raise SystemExit(f"{e.name}/{fname}: baseline copy does not decode to the installed input PNG")
            if lytimg.rgba_to_bflim(old, lytimg.bflim_to_rgba(old)) != old:
                raise SystemExit(f"{e.name}/{fname}: unchanged re-encode is not byte-identical")
            new = lytimg.rgba_to_bflim(old, new_rgba[stem_])
            if len(new) != len(old) or lytimg.parse_bflim(new) != lytimg.parse_bflim(old):
                raise SystemExit(f"{e.name}/{fname}: BFLIM size / header changed")
            if not np.array_equal(lytimg.bflim_to_rgba(new), build_lyt.expected("LA4", new_rgba[stem_])):
                raise SystemExit(f"{e.name}/{fname}: new BFLIM does not decode to the new PNG")
            files[fname] = new
            copies.append(f"{e.name}/{fname}")
        if files:
            repl[slot] = lytimg.sarc_replace(plain, files)
    missing = sorted(set(new_png) - set(old_sha))
    if missing:
        raise SystemExit(f"textures not found in MLyt.dat: {missing}")
    rebuilt = lib3dx.rebuild_bg4(baseline, repl)
    _, after = lib3dx.read_bg4(rebuilt)
    if len(after) != len(entries):
        raise SystemExit("entry count changed")
    changed = []
    for b0, a0 in zip(entries, after):
        if b0.name != a0.name or b0.size_flag != a0.size_flag:
            raise SystemExit("entry names / flags changed")
        if b0.data == a0.data:
            continue
        p, q = lib3dx.bg4_plain(b0), lib3dx.bg4_plain(a0)
        fo, fn = lytimg.sarc_list(p), lytimg.sarc_list(q)
        if [f[0] for f in fo] != [f[0] for f in fn]:
            raise SystemExit(f"{b0.name}: SARC file list changed")
        for (n1, s, t), (_, u, v) in zip(fo, fn):
            if p[s:t] != q[u:v]:
                if Path(n1).stem not in new_png:
                    raise SystemExit(f"{b0.name}/{n1}: untouched file changed")
                if len(p[s:t]) != len(q[u:v]) or p[t - 40:t] != q[v - 40:v]:
                    raise SystemExit(f"{b0.name}/{n1}: BFLIM size or footer changed")
                changed.append(f"{b0.name}/{n1}")
    unchanged_new = sorted(set(c for c in copies) - set(changed))     # texture already identical to the new PNG
    OUT_DAT.parent.mkdir(parents=True, exist_ok=True)
    OUT_DAT.write_bytes(rebuilt)
    return {"baseline": str(PATCH_MLYT.relative_to(ROOT)),
            "baseline_sha256": hashlib.sha256(baseline).hexdigest().upper(),
            "output": str(OUT_DAT.relative_to(ROOT)), "output_sha256": hashlib.sha256(rebuilt).hexdigest().upper(),
            "size": [len(baseline), len(rebuilt)], "texture_copies_written": copies, "changed_files": changed,
            "written_but_identical": unchanged_new,
            "distinct_baseline_texture_sha1": {k: sorted(v) for k, v in old_sha.items()},
            "empty_rebuild_equals_baseline": True, "baseline_copies_decode_to_installed_png": True,
            "unchanged_reencode_identical": True, "new_bflims_decode_to_new_png": True,
            "all_other_files_and_entries_identical": True}


def main() -> None:
    mode = sys.argv[1] if len(sys.argv) > 1 else "preview"
    import imgtext as T
    new, rep = make_all()
    OUT_KO.mkdir(parents=True, exist_ok=True)
    SHEETS.mkdir(parents=True, exist_ok=True)
    for old in OUT_KO.glob("*.png"):
        old.unlink()
    paths = {}
    for t, rgba in new.items():
        p = OUT_KO / f"{t}.png"
        T.save_png(rgba, p)
        paths[t] = p
        rep["labels"][t]["png"] = str(p.relative_to(ROOT))
        rep["labels"][t]["png_sha256"] = hashlib.sha256(p.read_bytes()).hexdigest().upper()
    sheet_labels(new, SHEETS / "labels_4x.png")
    sheet_row(new, SHEETS / "menu_row.png")
    if mode == "build":
        rep["archive"] = build_archive(paths)
    (HERE / ("build_verify.json" if mode == "build" else "preview.json")).write_text(
        json.dumps(rep, ensure_ascii=False, indent=1), "utf-8")
    print(json.dumps(rep, ensure_ascii=False, indent=1))


if __name__ == "__main__":
    main()
