"""Assemble the accepted OA Hangul over the restored R, with separate wind puffs.

Original data is read only. Uses the existing official glyph geometry/material recipe;
the word receives one uniform scale and translation, never individual stroke changes.
"""
from pathlib import Path
import json
import sys

import numpy as np
from PIL import Image, ImageDraw
from scipy import ndimage as ndi
from shapely import affinity
from shapely.ops import unary_union

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
SOURCE = ROOT / 'work/img/kj_logo_20261009'
PARTS = ROOT / 'work/img/kj_parts_20261009'
R_FILE = PARTS / 'R_clean.png'
sys.path.insert(0, str(SOURCE))
import build_oa as B
import design as D
import export_layers as E
import glyphs as G

OUT = HERE / 'out'
ASSETS = HERE / 'affinity'
B.WIN = (30, 125, 230, 208)
SCALE = 1.18
WORD_RIGHT = 211.0
WORD_BOTTOM = 197.0
WORD_ROTATION_DELTA = 4.0
TOP_ORIGIN = (36, 139)
BOTTOM_ORIGIN = (214, 187)


def save(path, a):
    path.parent.mkdir(parents=True, exist_ok=True)
    Image.fromarray(np.clip(np.rint(a), 0, 255).astype(np.uint8)).save(path)


def aligned(asset, origin):
    source = R_FILE if asset == 'R_clean' else PARTS / (asset + '.png')
    im = np.asarray(Image.open(source).convert('RGBA'))
    dst = np.zeros((208, 400, 4), np.uint8)
    x, y = origin
    h, w = im.shape[:2]
    assert x >= 0 and y >= 0 and x + w <= 400 and y + h <= 208
    dst[y:y + h, x:x + w] = im
    return dst


def over(base, rgba):
    a = rgba[..., 3:] / 255.0
    return base * (1 - a) + rgba[..., :3] * a


def build():
    OUT.mkdir(exist_ok=True)
    ASSETS.mkdir(exist_ok=True)
    original = np.asarray(Image.open(PARTS / 'source_original_JP.png').convert('RGB')).astype(float)
    old = np.asarray(Image.open(PARTS / 'source_claude_KO.png').convert('RGB')).astype(float)
    base = original.copy()
    # These rectangles contain the old word/puffs and the part of R restored by
    # R_clean. Stars, the clown car, P and G are outside these cleanup windows.
    base[146:202, 48:211] = 255
    base[127:157, 49:89] = 255
    base[187:208, 201:224] = 255
    r_layer = aligned('R_clean', (201, 140))
    # Clear the exact R silhouette so partial-alpha edge pixels are composited
    # once. The existing adjoining P outline stays outside this exact mask.
    base[r_layer[..., 3] > 0] = 255
    top_layer = aligned('wind_top', TOP_ORIGIN)
    bottom_layer = aligned('wind_bottom', BOTTOM_ORIGIN)
    geoms0, old_scale = D.layout('OA')
    oldword = unary_union(geoms0)
    origin = (oldword.bounds[0], oldword.bounds[3])
    geoms = [affinity.rotate(g, WORD_ROTATION_DELTA, origin=oldword.centroid)
             for g in geoms0]
    geoms = [affinity.scale(g, SCALE, SCALE, origin=origin) for g in geoms]
    w = unary_union(geoms)
    dx, dy = WORD_RIGHT - w.bounds[2], WORD_BOTTOM - w.bounds[3]
    geoms = [affinity.translate(g, dx, dy) for g in geoms]
    word = unary_union(geoms)
    m = B.load_mat()
    # The original edge thickness and fine hatch spacing match RPG's material.
    # Adapt the gradient's vertical range to the enlarged word.
    m['y_top'] = word.bounds[1]
    m['y_span'] = 24.0 * SCALE
    chars = [s['ch'] for s in D.PLANS['OA']['syl']]
    labels, angles = B.labels_hr_of(geoms, [B.HATCH_DEG[c] for c in chars])
    colour_hr, mask_hr = B.word_colour(word, labels, angles, m)
    coverage = B.down(mask_hr.astype(float))
    rgb = B.down(colour_hr * mask_hr[..., None]) / np.maximum(coverage, 1e-9)[..., None]
    word_layer = np.zeros((208, 400, 4), float)
    x0, y0, x1, y1 = B.WIN
    word_layer[y0:y1, x0:x1, :3] = rgb
    word_layer[y0:y1, x0:x1, 3] = coverage * 255
    # Upper smoke tail tucks under the word. The lower puff stays independently
    # in front. Crucially, the word covers the left stem of R.
    result = over(base, r_layer)
    result = over(result, top_layer)
    result = over(result, word_layer)
    result = over(result, bottom_layer)
    q = np.rint(B.q565(result)).astype(np.uint8)
    rgba = np.concatenate([q, np.full((208, 400, 1), 255, np.uint8)], 2)
    for name, im in zip(B.NAMES, (rgba[:, :144], rgba[:, 144:])):
        save(OUT / (name + '.png'), im)
    save(OUT / 'fileload_KJ_assembled.png', rgba)
    save(ASSETS / 'original.png', original)
    save(ASSETS / 'before.png', old)
    save(ASSETS / 'plate.png', base)
    save(ASSETS / 'R.png', r_layer)
    save(ASSETS / 'wind_top.png', top_layer)
    save(ASSETS / 'wind_bottom.png', bottom_layer)
    save(ASSETS / 'word_render.png', word_layer)
    save(ASSETS / 'final.png', rgba)
    # Exact material render is the visible word. Its official vector sources
    # remain in the editable document as a separate group.
    L = dict(geoms=geoms, chars=chars, m=m)
    shapes = E.shapes(L)
    vec = dict(size=[400, 208], rings={k: E.polys(v) for k, v in shapes.items()},
               letters=[dict(ch=c, id=E.ROM[c], polys=E.polys(g)) for c, g in zip(chars, geoms)])
    (ASSETS / 'vectors.json').write_text(json.dumps(vec, ensure_ascii=False), encoding='utf8')
    changed = np.any(q != old.astype(np.uint8), 2)
    yy, xx = np.nonzero(changed)
    # No edits outside the word + puffs + restored R. P/G and character artwork
    # keep exactly the previously installed pixels.
    allowed = np.zeros((208, 400), bool)
    allowed[125:208, 30:261] = True
    assert not np.any(changed & ~allowed), 'Unexpected change outside the logo assembly'
    fullcov = word_layer[..., 3] / 255
    assert all(fullcov[y, x] == 1 for x, y in
               [(206, 165), (207, 175), (209, 193), (210, 196)]), 'R repair must be hidden by the word'
    assert np.array_equal(q[:, 261:], old.astype(np.uint8)[:, 261:])
    report = dict(word_uniform_scale=SCALE, word_rotation_delta_degrees=WORD_ROTATION_DELTA,
                  previous_face_bounds=list(oldword.bounds),
                  assembled_face_bounds=list(word.bounds), glyphs_unchanged_except_uniform_transform=True,
                  old_geometry_scale=old_scale, new_geometry_scale=old_scale * SCALE,
                  letter_bounds={c: list(g.bounds) for c, g in zip(chars, geoms)},
                  layer_order=['plate', 'restored R', 'upper wind', 'Hangul word', 'lower wind'],
                  top_wind_origin=list(TOP_ORIGIN), bottom_wind_origin=list(BOTTOM_ORIGIN),
                  changed_pixels=int(changed.sum()), changed_bbox=[int(xx.min()), int(yy.min()), int(xx.max()), int(yy.max())],
                  P_G_and_character_art_unchanged=True,
                  R_left_strip_word_coverage={f'{x},{y}': float(fullcov[y, x])
                    for x, y in [(206, 165), (207, 175), (209, 193), (210, 196)]})
    (OUT / 'assembly.json').write_text(json.dumps(report, ensure_ascii=False, indent=2), encoding='utf8')
    # Full image and native pixel detail, before above / assembled below.
    sheet = Image.new('RGB', (800, 448), 'white')
    draw = ImageDraw.Draw(sheet)
    draw.text((12, 6), 'BEFORE', fill='black')
    draw.text((412, 6), 'ASSEMBLED (+18%)', fill='black')
    sheet.paste(Image.fromarray(old.astype(np.uint8)), (0, 28))
    sheet.paste(Image.fromarray(q), (400, 28))
    crop = (slice(130, 208), slice(35, 261))
    for i, im in enumerate([old.astype(np.uint8), q]):
        det = Image.fromarray(im[crop]).resize((678, 234), Image.Resampling.NEAREST)
        # Separate detail image avoids resizing the side-by-side full view.
        det.save(OUT / ('detail_before.png' if i == 0 else 'detail_after.png'))
    sheet.crop((0, 0, 800, 236)).save(OUT / 'before_after.png')
    print(json.dumps(report, ensure_ascii=False, indent=2))


if __name__ == '__main__':
    build()
