"""Check green-face continuity, exact edit bounds and independent alpha preservation."""
from pathlib import Path
import json
import numpy as np
from PIL import Image
from shapely.geometry import Polygon, Point

HERE=Path(__file__).resolve().parent
ROOT=HERE.parents[2]


def main():
    before=np.asarray(Image.open(ROOT/'work/img/kj_parts_20261009/R_clean.png').convert('RGBA'))
    after=np.asarray(Image.open(HERE/'R_clean.png').convert('RGBA'))
    full=np.asarray(Image.open(HERE/'R_clean_aligned.png').convert('RGBA'))
    assert np.array_equal(after,full[140:203,201:261])
    assert np.array_equal(before[...,3],after[...,3])
    changed=np.any(before!=after,2)
    yy,xx=np.mgrid[140:203,201:261]
    allowed=(xx>=206)&(xx<=224)&(yy>=164)&(yy<=196)
    assert not np.any(changed&~allowed)
    face=Polygon([(209,150.5),(235.4,147),(250.6,156.1),(247.5,171.3),
                  (238.2,177.7),(253.3,189.1),(236.3,197.4),(223.7,181),
                  (223.6,193.7),(214.5,193.3)]).buffer(-.75)
    interior=np.array([[face.contains(Point(x+.5,y+.5)) for x in range(201,261)]
                      for y in range(140,203)])&allowed
    beforeDark=before[...,:3].max(2)<150
    afterDark=after[...,:3].max(2)<150
    oldCount=int((interior&beforeDark).sum())
    newCount=int((interior&afterDark).sum())
    assert oldCount>0 and newCount==0,'Dark border pixels remain inside the corrected green face'
    assert np.all(after[...,1][interior]>145),'Broken green-face continuity'
    result=dict(R_changed_pixels=int(changed.sum()),edit_region=[206,164,224,196],
                maroon_pixels_inside_intended_green_face_before=oldCount,
                maroon_pixels_inside_intended_green_face_after=newCount,
                corrected_face_green_channel_above_145=True,
                alpha_and_outer_silhouette_identical=True,
                counter_bowl_right_leg_and_unaffected_face_pixels_identical=True,
                cropped_and_aligned_RGBA_equal=True)
    (HERE/'R_verify.json').write_text(json.dumps(result,indent=2),encoding='utf8')
    print(json.dumps(result,indent=2))


if __name__=='__main__':
    main()
