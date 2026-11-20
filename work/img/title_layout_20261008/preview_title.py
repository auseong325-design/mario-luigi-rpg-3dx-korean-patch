from pathlib import Path
import json,sys
import numpy as np
from PIL import Image,ImageDraw
from scipy.ndimage import map_coordinates
OUT=Path(__file__).parent
mapping=json.loads((OUT/'screen_mapping.json').read_text(encoding='utf8'))
ax,ay,bx,by=[mapping[k] for k in ['scale_x','scale_y','offset_x','offset_y']]
Y,X=np.mgrid[:240,:400]
def project(src):
    return np.stack([map_coordinates(src[...,c],[(Y+.5-by)/ay-.5,(X+.5-bx)/ax-.5],order=1,mode='constant') for c in range(4)],axis=2)
def stack(suffix):
    a=Image.open(OUT/('title_logo_JP_bottom'+suffix+'.png')).convert('RGBA')
    b=Image.open(OUT/('title_logo_JP_top'+suffix+'.png')).convert('RGBA')
    return np.asarray(Image.alpha_composite(a,b),float)
rows=[]
for label,suffix in [('BEFORE (same screen projection)','_before'),('AFTER (estimated screen projection)','')]:
    v=project(stack(suffix));a=v[...,3:]/255
    canvas=np.uint8(np.clip(v[...,:3]*a+np.array([42,44,54])*(1-a),0,255))
    im=Image.fromarray(canvas)
    ImageDraw.Draw(im).text((8,218),label,fill='white')
    im.save(OUT/('screen_before.png' if suffix else 'screen_after.png'))
    rows.append(im)
sheet=Image.new('RGB',(800,240));sheet.paste(rows[0],(0,0));sheet.paste(rows[1],(400,0))
sheet.save(OUT/'title_before_after.png')
masks=np.load(OUT/'title_masks.npz')
sil=masks['sil']
yy,xx=np.nonzero(sil)
sil_box=[ax*xx.min()/4+bx,ay*yy.min()/4+by,ax*(xx.max()+1)/4+bx,ay*(yy.max()+1)/4+by]
metrics={'silhouette_estimated_screen_box':sil_box,'all_silhouettes_inside_screen':bool(sil_box[1]>8 and sil_box[0]>8 and sil_box[2]<392),
         'projection_note':mapping['note']}
assert metrics['all_silhouettes_inside_screen']
(OUT/'preview_metrics.json').write_text(json.dumps(metrics,indent=2)+'\n',encoding='utf8')
print(json.dumps(metrics,indent=2))
