"""Read back the native R exports and check the user-reported boundary region."""
from pathlib import Path
import json
import numpy as np
from PIL import Image
from shapely.geometry import Polygon,Point

HERE=Path(__file__).resolve().parent
ROOT=HERE.parents[2]


def main():
    old=np.asarray(Image.open(ROOT/'work/img/kj_R_polish_20261010/R_clean.png').convert('RGBA'))
    new=np.asarray(Image.open(HERE/'R_clean.png').convert('RGBA'))
    aligned=np.asarray(Image.open(HERE/'R_clean_aligned.png').convert('RGBA'))
    assert np.array_equal(new,aligned[140:203,201:261])
    assert np.array_equal(old[...,3],new[...,3])
    yy,xx=np.mgrid[140:203,201:261]
    changed=np.any(old!=new,2)
    allowed=(xx>=206)&(xx<np.where(yy<182,219,228))&(yy>=154)&(yy<=198)
    assert not np.any(changed&~allowed)
    field=json.loads((HERE/'colour_field.json').read_text())
    face=Polygon(field['face_contour']).buffer(-.7)
    interior=np.array([[face.contains(Point(x+.5,y+.5)) for x in range(201,261)] for y in range(140,203)])
    region=interior&(xx>=209)&(xx<=215)&(yy>=161)&(yy<=193)
    old_dark=int((region&(old[...,:3].max(2)<150)).sum())
    new_dark=int((region&(new[...,:3].max(2)<150)).sum())
    assert new_dark==0 and old_dark>0
    # Compare colour steps inside the bottom surface, excluding the geometric
    # face/outline edge. A single channel is unsuitable for a green colour ramp.
    def max_row_step(a):
        rows=a[187-140:193-140,215-201:222-201,:3].astype(float).mean(1)
        return float(np.linalg.norm(np.diff(rows,axis=0),axis=1).max())
    old_step,new_step=max_row_step(old),max_row_step(new)
    assert new_step<old_step
    assert np.all(new[187-140:194-140,215-201:222-201,1]>150)
    result=dict(R_changed_pixels=int(changed.sum()),R_alpha_and_outer_silhouette_identical=True,
                cropped_and_aligned_RGBA_equal=True,edit_region=[206,154,227,198],
                dark_pixels_inside_widened_stem_before=old_dark,dark_pixels_inside_widened_stem_after=new_dark,
                bottom_interior_max_row_colour_step_before=old_step,bottom_interior_max_row_colour_step_after=new_step,
                supplied_crop_positions=json.loads((HERE/'located_details.json').read_text()),
                visual_review='Native Affinity proof: remaining stem gaps covered; horizontal pale repair ridge removed')
    (HERE/'R_verify.json').write_text(json.dumps(result,ensure_ascii=False,indent=2),encoding='utf8')
    print(json.dumps(result,ensure_ascii=False,indent=2))


if __name__=='__main__':main()
