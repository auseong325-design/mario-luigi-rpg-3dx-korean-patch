"""Use the approved assembly unchanged, replacing only the corrected R asset."""
from pathlib import Path
import hashlib
import importlib.util
import json
import numpy as np
from PIL import Image, ImageDraw

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
PREVIOUS = ROOT / 'work/img/kj_assembly_20261010'


def main():
    spec = importlib.util.spec_from_file_location('kj_approved_assembly', PREVIOUS / 'build_assembly.py')
    assembly = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(assembly)
    assembly.R_FILE = HERE / 'R_clean.png'
    assembly.OUT = HERE / 'out'
    assembly.ASSETS = HERE / 'affinity'
    assembly.build()
    before = np.asarray(Image.open(PREVIOUS / 'out/fileload_KJ_assembled.png').convert('RGBA'))
    after = np.asarray(Image.open(HERE / 'out/fileload_KJ_assembled.png').convert('RGBA'))
    oldR = np.asarray(Image.open(ROOT / 'work/img/kj_parts_20261009/R_clean.png').convert('RGBA'))
    newR = np.asarray(Image.open(HERE / 'R_clean.png').convert('RGBA'))
    assert np.array_equal(oldR[...,3],newR[...,3]), 'R outer silhouette/alpha changed'
    rChanged = np.any(oldR != newR,2)
    allowed = np.zeros((208,400),bool)
    allowed[140:203,201:261] = rChanged
    changed = np.any(before != after,2)
    assert not np.any(changed & ~allowed), 'Non-R assembly pixels changed'
    yy,xx = np.nonzero(changed)
    oldRGBA = Image.fromarray(before)
    newRGBA = Image.fromarray(after)
    proof = Image.new('RGB',(800,236),'white')
    d = ImageDraw.Draw(proof)
    d.text((8,8),'BEFORE R REPAIR',fill='black')
    d.text((408,8),'REFINED R',fill='black')
    proof.paste(oldRGBA,(0,28));proof.paste(newRGBA,(400,28))
    proof.save(HERE / 'out/assembly_before_after.png')
    # All vector and smoke material inputs must stay identical to the approved
    # composition; only R.png and its corresponding plate/final can differ.
    preserved=['vectors.json','word_render.png','wind_top.png','wind_bottom.png']
    sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
    for name in preserved:
        assert sha(HERE / 'affinity' / name) == sha(PREVIOUS / 'affinity' / name),name
    result=dict(R_asset_changed_pixels=int(rChanged.sum()),final_changed_pixels=int(changed.sum()),
                final_changed_bbox=[int(xx.min()),int(yy.min()),int(xx.max()),int(yy.max())] if len(xx) else None,
                R_alpha_and_outer_silhouette_identical=True,
                Hangul_18_percent_scale_position_material_unchanged=True,
                both_wind_images_position_and_pixels_unchanged=True,
                P_G_and_character_art_identical=True,preserved_asset_files=preserved)
    (HERE / 'out/R_only_verify.json').write_text(json.dumps(result,indent=2),encoding='utf8')
    print(json.dumps(result,indent=2))


if __name__ == '__main__':
    main()
