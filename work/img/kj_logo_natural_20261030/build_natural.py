"""쿠파주니어 RPG mode-select logo, 2026-10-30: remove the remaining edit traces on R/P.

Keeps the accepted 2026-10-10 composition exactly: OA Hangul (x1.18, 4 deg, same material), the two
wind puffs at the same places, the same layer order. What changes is only how the R reaches the picture:

- before: the R silhouette was blanked to white in the plate and the separated R (R_clean.png) was laid
  on top. Its soft edge over that white left a white zigzag between R and P, and its re-traced outer
  edge differed from the original along the top and the left side above the word.
- now: the plate keeps the JP original's own pixels for R, P, the pink star and the clown car.
  The separated R is used only where the original R was under the 「Jr.」 text or the old lower puff
  (zone Z: pixels where the separated R over white differs from the original), and almost all of that
  is under the Hangul word and the moved lower puff anyway.

Original data is read only. Writes out/ (two texture halves, full picture, report, review sheets) and
affinity/ (the layer PNGs).
"""
from pathlib import Path
import hashlib
import importlib.util
import json
import sys

import numpy as np
from PIL import Image, ImageDraw
from scipy import ndimage as ndi
from shapely import affinity
from shapely.ops import unary_union

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
APPROVED = ROOT / 'work/img/kj_assembly_20261010'      # accepted composition recipe
PREVIOUS = ROOT / 'work/img/kj_R_faithful_20261010'    # installed 2026-10-10 (faithful R + corner)
R_FILE = PREVIOUS / 'R_clean.png'                       # R material accepted with the corner fix
OUT = HERE / 'out'
ASSETS = HERE / 'affinity'

# Rectangles that held the Japanese word, its furigana and the two old puffs (same as build_assembly.py).
TEXT_RECTS = [(146, 202, 48, 211), (127, 157, 49, 89), (187, 208, 201, 224)]
# Where the original R could be touched by 「Jr.」 (its white rim reaches x=210 from y=156) or by the
# old lower puff (x<=226 from y=187). Only here may the separated R replace original pixels.
ZONE_RECTS = [(156, 208, 197, 211), (187, 208, 197, 227)]
# The R and its neighbourhood: inside it the plate keeps the original instead of the text blanking.
R_AREA = (140, 208, 197, 262)
THRESHOLD = 12


def mask(rects):
    m = np.zeros((208, 400), bool)
    for y0, y1, x0, x1 in rects:
        m[y0:y1, x0:x1] = True
    return m


def load_approved():
    spec = importlib.util.spec_from_file_location('kj_approved_assembly', APPROVED / 'build_assembly.py')
    A = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(A)
    A.R_FILE = R_FILE
    return A


def word_layer(A):
    """The accepted Hangul word, rendered exactly as build_assembly.build() does."""
    B, D = A.B, A.D
    geoms0, old_scale = D.layout('OA')
    oldword = unary_union(geoms0)
    origin = (oldword.bounds[0], oldword.bounds[3])
    geoms = [affinity.rotate(g, A.WORD_ROTATION_DELTA, origin=oldword.centroid) for g in geoms0]
    geoms = [affinity.scale(g, A.SCALE, A.SCALE, origin=origin) for g in geoms]
    w = unary_union(geoms)
    dx, dy = A.WORD_RIGHT - w.bounds[2], A.WORD_BOTTOM - w.bounds[3]
    geoms = [affinity.translate(g, dx, dy) for g in geoms]
    word = unary_union(geoms)
    m = B.load_mat()
    m['y_top'] = word.bounds[1]
    m['y_span'] = 24.0 * A.SCALE
    chars = [s['ch'] for s in D.PLANS['OA']['syl']]
    labels, angles = B.labels_hr_of(geoms, [B.HATCH_DEG[c] for c in chars])
    colour_hr, mask_hr = B.word_colour(word, labels, angles, m)
    coverage = B.down(mask_hr.astype(float))
    rgb = B.down(colour_hr * mask_hr[..., None]) / np.maximum(coverage, 1e-9)[..., None]
    layer = np.zeros((208, 400, 4), float)
    x0, y0, x1, y1 = B.WIN
    layer[y0:y1, x0:x1, :3] = rgb
    layer[y0:y1, x0:x1, 3] = coverage * 255
    return layer


def save(path, a):
    path.parent.mkdir(parents=True, exist_ok=True)
    Image.fromarray(np.clip(np.rint(a), 0, 255).astype(np.uint8)).save(path)


def left_edge(original):
    """R's left stem outline above the word: keep the original's own slanted edge.

    The stem edge is a straight slanted line. It is measured on rows 148-161, where nothing touches
    it (coverage = 1 - G/255 of x=202..205; dark outline G~0, white G=255), and continued down to
    row 172. In rows 156-172, x=196..edge+3, a pixel is replaced only where the original differs from
    that clean edge (the 「r」 of Jr. touches it from row 159); everything else stays original.
    Returns (window, replace, clean, fit): window = pixels this rule decides, replace = pixels to
    change, clean = their clean values, fit = the measured line.
    """
    rows = np.arange(148, 162)
    cov = lambda y, x: 1 - original[y, x, 1] / 255.0
    edges = np.array([206 - sum(cov(y, x) for x in range(202, 206)) for y in rows])
    b, a = np.polyfit(rows, edges, 1)
    window = np.zeros((208, 400), bool)
    replace = np.zeros((208, 400), bool)
    clean = original.copy()
    for y in range(156, 173):
        e = a + b * y
        for x in range(196, int(np.floor(e + 3)) + 1):
            window[y, x] = True
            c = float(np.clip(x + 1 - e, 0, 1))
            p = original[y, x]
            is_dark = p.max() < 0x70 and p[1] < 0x20
            dark = p if is_dark else np.array([0x4a, 0, 0], float)
            clean[y, x] = dark * c + 255 * (1 - c)
            if np.abs(clean[y, x] - p).max() > 24:
                replace[y, x] = True
    fit = dict(rows=[148, 161], edge_at_148=round(float(a + b * 148), 3), edge_at_172=round(float(a + b * 172), 3),
               slope_px_per_row=round(float(b), 4),
               max_fit_residual=round(float(np.abs(edges - (a + b * rows)).max()), 3))
    return window, replace, clean, fit


def compose(A, r_file=R_FILE):
    A.R_FILE = r_file
    original = np.asarray(Image.open(A.PARTS / 'source_original_JP.png').convert('RGB')).astype(float)
    text, zone, area = mask(TEXT_RECTS), mask(ZONE_RECTS), mask([R_AREA])
    r_layer = A.aligned('R_clean', (201, 140)).astype(float)
    r_on_white = A.over(np.full_like(original, 255.0), r_layer)
    diff = np.abs(r_on_white - original).max(2)
    Z = ndi.binary_dilation((diff > THRESHOLD) & zone, iterations=1) & zone
    window, replace, clean, fit = left_edge(original)
    Z &= ~window                       # the stem edge above the word follows the rule below
    base = original.copy()
    base[text] = 255
    keep = area & text & ~Z            # R's own pixels inside the old text rectangles
    base[keep] = original[keep]
    base[Z] = r_on_white[Z]
    base[replace] = clean[replace]
    Z |= replace
    compose.edge_fit = fit
    top = A.aligned('wind_top', A.TOP_ORIGIN).astype(float)
    bottom = A.aligned('wind_bottom', A.BOTTOM_ORIGIN).astype(float)
    word = word_layer(A)
    result = A.over(base, top)
    result = A.over(result, word)
    result = A.over(result, bottom)
    q = np.rint(A.B.q565(result)).astype(np.uint8)
    rgba = np.concatenate([q, np.full((208, 400, 1), 255, np.uint8)], 2)
    layers = dict(original=original, plate=base, R_zone=np.dstack([r_on_white, Z * 255.0]),
                  wind_top=top, word=word, wind_bottom=bottom)
    return rgba, Z, layers


def build():
    OUT.mkdir(exist_ok=True)
    A = load_approved()
    rgba, Z, L = compose(A)
    installed = np.asarray(Image.open(PREVIOUS / 'out/fileload_KJ_assembled.png').convert('RGBA'))
    original = L['original']
    q = rgba[..., :3]
    # Visible share of every layer stack position (1 = nothing in front of the plate).
    front = (1 - L['wind_top'][..., 3] / 255) * (1 - L['word'][..., 3] / 255) * (1 - L['wind_bottom'][..., 3] / 255)
    area = mask([R_AREA])
    changed = np.any(q != installed[..., :3], 2)
    yy, xx = np.nonzero(changed)
    # 1) nothing changes outside the R neighbourhood
    assert not np.any(changed & ~area), 'change outside the R area'
    # 2) word and puffs are the accepted ones: pixels fully covered by them are unchanged
    full_front = front == 0
    assert not np.any(changed & full_front), 'a fully covered pixel changed'
    # 3) every visible plate pixel of the R area outside Z is the JP original (RGB565 rounding only)
    vis = area & (front > 0) & ~Z
    o565 = np.rint(A.B.q565(original)).astype(int)
    exact = (front == 1) & vis
    assert np.abs(q[exact].astype(int) - o565[exact]).max() <= 0, 'visible R/P pixel is not the original'
    # 4) the white seam between R and P is gone: in the seam band no pixel is lighter than the original
    seam = np.zeros((208, 400), bool)
    seam[150:202, 236:252] = True
    lighter = (q.astype(int).sum(2) - o565.sum(2)) > 30
    assert not np.any(seam & lighter), 'R/P seam still lighter than the original'
    # 5) no piece of 「r」 is left of the stem edge where the plate shows: there it is white
    fit = compose.edge_fit
    slope = (fit['edge_at_172'] - fit['edge_at_148']) / 24
    left_of_edge = np.zeros((208, 400), bool)
    for y in range(156, 173):
        left_of_edge[y, 196:int(np.floor(fit['edge_at_148'] + slope * (y - 148) - 0.5))] = True
    shows = left_of_edge & (front > 0)
    plate = np.rint(L['plate']).astype(int)
    assert plate[shows].min() >= 0xF0, 'a Jr. remnant is still visible left of the R stem'
    zvis = Z & (front > 0)
    zy, zx = np.nonzero(zvis)
    report = dict(
        composition='kj_assembly_20261010 (OA x1.18, 4 deg, winds at %s / %s)' % (A.TOP_ORIGIN, A.BOTTOM_ORIGIN),
        r_material=str(R_FILE.relative_to(ROOT)),
        stem_edge_fit=fit,
        stem_edge_replaced_pixels=int((Z & left_of_edge).sum()),
        no_Jr_remnant_left_of_stem=True,
        zone_Z_pixels=int(Z.sum()),
        zone_Z_visible_pixels=int(zvis.sum()),
        zone_Z_visible_bbox=[int(zx.min()), int(zy.min()), int(zx.max()), int(zy.max())] if zvis.any() else None,
        changed_vs_installed=int(changed.sum()),
        changed_vs_installed_bbox=[int(xx.min()), int(yy.min()), int(xx.max()), int(yy.max())],
        unchanged_outside_R_area=True,
        fully_covered_pixels_unchanged=True,
        visible_R_P_pixels_outside_Z_equal_original=True,
        R_P_seam_not_lighter_than_original=True)
    for name, im in zip(A.B.NAMES, (rgba[:, :144], rgba[:, 144:])):
        save(OUT / (name + '.png'), im)
    save(OUT / 'fileload_KJ_assembled.png', rgba)
    for k, v in L.items():
        save(ASSETS / f'{k}.png', v)
    save(ASSETS / 'final.png', rgba)
    (OUT / 'natural.json').write_text(json.dumps(report, ensure_ascii=False, indent=2), encoding='utf8')
    sheets(installed[..., :3], q, original.astype(np.uint8))
    print(json.dumps(report, ensure_ascii=False, indent=2))


def sheets(before, after, original):
    """Review pictures: full logo before/after/original at 2x, and R detail at 8x."""
    def panel(im, box, k, label):
        x0, y0, x1, y1 = box
        p = Image.fromarray(im[y0:y1, x0:x1]).resize(((x1 - x0) * k, (y1 - y0) * k), Image.NEAREST)
        canvas = Image.new('RGB', (p.width, p.height + 18), (255, 255, 255))
        canvas.paste(p, (0, 18))
        ImageDraw.Draw(canvas).text((4, 3), label, fill=(0, 0, 0))
        return canvas

    def stack(panels, path, vertical=True):
        w = max(p.width for p in panels) if vertical else sum(p.width for p in panels) + 8 * (len(panels) - 1)
        h = sum(p.height for p in panels) + 8 * (len(panels) - 1) if vertical else max(p.height for p in panels)
        out = Image.new('RGB', (w, h), (60, 60, 60))
        pos = 0
        for p in panels:
            out.paste(p, (0, pos) if vertical else (pos, 0))
            pos += (p.height if vertical else p.width) + 8
        out.save(path)

    full = (30, 120, 340, 208)
    stack([panel(before, full, 2, 'BEFORE (installed 2026-10-10)'), panel(after, full, 2, 'AFTER'),
           panel(original, full, 2, 'JP ORIGINAL')], OUT / 'before_after.png')
    detail = (196, 134, 262, 208)
    stack([panel(before, detail, 7, 'BEFORE'), panel(after, detail, 7, 'AFTER'),
           panel(original, detail, 7, 'JP ORIGINAL')], OUT / 'R_detail.png', vertical=False)


if __name__ == '__main__':
    build()
