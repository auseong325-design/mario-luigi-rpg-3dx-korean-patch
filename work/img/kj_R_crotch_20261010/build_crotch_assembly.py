"""Keep the accepted composition; replace only the R inner-corner restoration."""
from pathlib import Path
import hashlib
import importlib.util
import json
import numpy as np
from PIL import Image

HERE=Path(__file__).resolve().parent
ROOT=HERE.parents[2]
APPROVED=ROOT/'work/img/kj_assembly_20261010'
PREVIOUS=ROOT/'work/img/kj_R_notch_20261010'


def main():
    spec=importlib.util.spec_from_file_location('kj_approved_assembly',APPROVED/'build_assembly.py')
    assembly=importlib.util.module_from_spec(spec)
    spec.loader.exec_module(assembly)
    assembly.R_FILE=HERE/'R_clean.png'
    assembly.OUT=HERE/'out'
    assembly.ASSETS=HERE/'affinity'
    assembly.build()
    before=np.asarray(Image.open(PREVIOUS/'out/fileload_KJ_assembled.png').convert('RGBA'))
    after=np.asarray(Image.open(HERE/'out/fileload_KJ_assembled.png').convert('RGBA'))
    old=np.asarray(Image.open(PREVIOUS/'R_clean.png').convert('RGBA'))
    new=np.asarray(Image.open(HERE/'R_clean.png').convert('RGBA'))
    assert np.array_equal(old[...,3],new[...,3]),'R outer alpha changed'
    rchanged=np.any(old!=new,2)
    allowed=np.zeros((208,400),bool)
    allowed[140:203,201:261]=rchanged
    changed=np.any(before!=after,2)
    assert not np.any(changed&~allowed),'Composition changed outside R'
    yy,xx=np.nonzero(changed)
    preserved=['vectors.json','word_render.png','wind_top.png','wind_bottom.png']
    sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
    for name in preserved:
        assert sha(HERE/'affinity'/name)==sha(PREVIOUS/'affinity'/name),name
    result=dict(R_asset_changed_pixels=int(rchanged.sum()),final_changed_pixels=int(changed.sum()),
                final_changed_bbox=[int(xx.min()),int(yy.min()),int(xx.max()),int(yy.max())],
                R_alpha_and_outer_silhouette_identical=True,
                Hangul_18_percent_scale_position_material_unchanged=True,
                both_wind_images_position_and_pixels_unchanged=True,
                P_G_and_character_art_identical=True,preserved_asset_files=preserved)
    (HERE/'out/R_only_verify.json').write_text(json.dumps(result,indent=2),encoding='utf8')
    print(json.dumps(result,indent=2))


if __name__=='__main__':main()

