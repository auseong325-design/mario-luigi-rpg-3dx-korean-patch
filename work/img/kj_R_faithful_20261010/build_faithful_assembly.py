"""Keep the accepted composition (18% Hangul, two winds, plate); replace only the R with the
faithful separation (R_clean.png, exported from Affinity R_faithful_20261010.af)."""
from pathlib import Path
import hashlib,importlib.util,json
import numpy as np
from PIL import Image
HERE=Path(__file__).resolve().parent;ROOT=HERE.parents[2]
APPROVED=ROOT/'work/img/kj_assembly_20261010'
PREVIOUS=ROOT/'work/img/kj_R_crotch_20261010'

def main():
    spec=importlib.util.spec_from_file_location('kj_approved_assembly',APPROVED/'build_assembly.py')
    A=importlib.util.module_from_spec(spec);spec.loader.exec_module(A)
    A.R_FILE=HERE/'R_clean.png';A.OUT=HERE/'out';A.ASSETS=HERE/'affinity'
    A.build()
    before=np.asarray(Image.open(PREVIOUS/'out/fileload_KJ_assembled.png').convert('RGBA'))
    after=np.asarray(Image.open(HERE/'out/fileload_KJ_assembled.png').convert('RGBA'))
    R=np.asarray(Image.open(HERE/'R_clean.png').convert('RGBA'))
    old=np.asarray(Image.open(PREVIOUS/'R_clean.png').convert('RGBA'))
    allowed=np.zeros((208,400),bool)
    allowed[140:203,201:261]=(R[...,3]>0)|(old[...,3]>0)
    changed=np.any(before!=after,2)
    assert not np.any(changed&~allowed),'composition changed outside the R'
    sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
    for name in ['vectors.json','word_render.png','wind_top.png','wind_bottom.png']:
        assert sha(HERE/'affinity'/name)==sha(PREVIOUS/'affinity'/name),name
    yy,xx=np.nonzero(changed)
    r=dict(final_changed_pixels=int(changed.sum()),final_changed_bbox=[int(xx.min()),int(yy.min()),int(xx.max()),int(yy.max())],
           R_opaque_px=int((R[...,3]>0).sum()),word_winds_plate_unchanged=True)
    (HERE/'out/R_only_verify.json').write_text(json.dumps(r,indent=2));print(r)
if __name__=='__main__':main()
