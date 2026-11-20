"""Restore the R's inner corner (between the two legs) from the original Japanese R.

The 2026-10-10 notch round grew the green face into the dark V and removed the light rim
on the left leg's right edge. Only that V region is put back to the original pixels; the
left stem / bottom-left corner fixes the user asked for earlier and the R alpha are kept.
"""
from pathlib import Path
import json
import numpy as np
from PIL import Image
HERE=Path(__file__).parent;IMG=HERE.parent
S=IMG/'lyt/3DX/MLyt/MENU_FILE_LOAD_JP_ja'
jp=np.concatenate([np.asarray(Image.open(S/(n+'.png')).convert('RGBA')) for n in
    ['LOAD_GAME_IMG_KJ_L_00_JP_ja','LOAD_GAME_IMG_KJ_R_00_JP_ja']],1)[140:203,201:261]
cur=np.asarray(Image.open(IMG/'kj_R_notch_20261010/R_clean.png').convert('RGBA'))
H,W=cur.shape[:2];yy,xx=np.mgrid[:H,:W]
# V region: right of the left leg's outer stem fixes, left of the diagonal leg's face.
# Left boundary x=15; bottom: y<=53 under the left leg, y<=57 under the V (the white wind
# puff of the JP picture starts below/left of that and is never copied).
region=(xx>=15)&(xx<=31)&(yy>=38)&(((xx<21)&(yy<=53))|((xx>=21)&(yy<=57)))
# The diagonal leg's face (right of its light rim) is left as is.
def face_right_of_rim(y,x):
    return x-21>(y-40)*0.62+6
region&=~face_right_of_rim(yy,xx)
puff=jp[...,:3].min(2)>215
region&=~puff&(cur[...,3]==255)
# Keep the earlier left-leg bottom fill (x<21, y>=49) and the re-coloured face: copy a pixel
# only where the original or the current one is not green/yellow face (rim, outline, V).
def face(a):
    a=a[...,:3].astype(int);r,g,b=a[...,0],a[...,1],a[...,2]
    return (g>140)&(b<110)&(np.minimum(r,g)-b>90)
region&=~((xx<21)&(yy>=49))
region&=~(face(jp)&face(cur))
out=cur.copy();out[region,:3]=jp[region,:3]
assert np.array_equal(out[...,3],cur[...,3])
changed=np.any(out!=cur,2)
Image.fromarray(out).save(HERE/'R_clean.png')
al=np.zeros((208,400,4),np.uint8);al[140:203,201:261]=out
prev=np.asarray(Image.open(IMG/'kj_R_notch_20261010/R_clean_aligned.png').convert('RGBA'))
assert np.array_equal(prev[140:203,201:261],cur)
prev=prev.copy();prev[140:203,201:261]=out;Image.fromarray(prev).save(HERE/'R_clean_aligned.png')
yy2,xx2=np.nonzero(changed)
r={'changed_pixels':int(changed.sum()),'changed_bbox_R':[int(xx2.min()),int(yy2.min()),int(xx2.max()),int(yy2.max())],
   'source':'original JP R pixels','alpha_identical':True}
(HERE/'R_verify.json').write_text(json.dumps(r,indent=2));print(r)
def onblue(a):
    a=a.astype(float);al=a[...,3:]/255;return (a[...,:3]*al+np.array([60,120,220])*(1-al)).astype(np.uint8)
crop=lambda a:onblue(a)[28:60,10:46]
tiles=[crop(jp),crop(cur),crop(out)]
row=np.concatenate([np.pad(t,((0,0),(0,1),(0,0)),constant_values=255) for t in tiles],1)
Image.fromarray(row).resize((row.shape[1]*12,row.shape[0]*12),Image.NEAREST).save(HERE/'R_crotch_detail.png')
full=np.concatenate([np.pad(onblue(t),((0,0),(0,2),(0,0)),constant_values=255) for t in [jp,cur,out]],1)
Image.fromarray(full).resize((full.shape[1]*6,full.shape[0]*6),Image.NEAREST).save(HERE/'R_before_after.png')
