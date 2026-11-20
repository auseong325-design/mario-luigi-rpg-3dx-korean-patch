"""Use the same unmodified 1DX & in the 64x64 intro quad, preserving its placement."""
from pathlib import Path
import json,sys
import numpy as np
from scipy import ndimage as ndi
ROOT=Path(__file__).resolve().parents[3];OUT=Path(__file__).parent
sys.path.insert(0,str(ROOT/'work/img/logo2'))
import l2,layout,seg_1dx,model as M

def fill_rows(rows,fallback):
    y=np.arange(len(rows));ok=np.isfinite(rows[:,0])
    if not ok.any():return np.tile(fallback,(len(rows),1))
    return np.stack([np.interp(y,y[ok],rows[ok,c]) for c in range(3)],axis=1)

original=l2.load(OUT/'title_logo_and_JP_before.png')
face=(original[...,3]>=250)&((original[...,0]>100)|(original[...,1]>100))
yy,xx=np.nonzero(face)
old_box=[int(xx.min()),int(yy.min()),int(xx.max()+1),int(yy.max()+1)]
donor=seg_1dx.syllables(fix_stem=False)[0]['amp']
dy,dx=np.nonzero(donor>.5)
donor_box=[int(dx.min()),int(dy.min()),int(dx.max()+1),int(dy.max()+1)]
scale=(old_box[3]-old_box[1])/(donor_box[3]-donor_box[1])
left=(old_box[0]+old_box[2])/2-scale*(donor_box[2]-donor_box[0])/2
F=layout.resample(donor,donor_box[0],donor_box[1],scale,scale,left,old_box[1],(64*4,64*4))>.5
opaque=original[...,3]>=250
dark=opaque&(original[...,:3].max(axis=2)<100)
colors,counts=np.unique(original[...,:3][dark],axis=0,return_counts=True)
navy=colors[counts.argmax()]
face_rows=np.full((64,3),np.nan)
ext_rows=np.full((64,3),np.nan)
for y in range(64):
    pixels=original[y,:,:3][face[y]]
    if len(pixels):
        # Exclude the bright specular samples when fitting the underlying face gradient.
        cutoff=np.percentile(pixels.mean(axis=1),60)
        face_rows[y]=np.median(pixels[pixels.mean(axis=1)<=cutoff+4],axis=0)
    extrusion=opaque[y]&~face[y]&~dark[y]
    if extrusion.any():ext_rows[y]=np.median(original[y,:,:3][extrusion],axis=0)
style={'face':{2:fill_rows(face_rows,[220,230,235])},'ext':{2:fill_rows(ext_rows,navy)}}
P=M.Params(r_o=3.5,r_e=3.5,D=6.0,sx=.75,navy=tuple(navy),glow=False,blur=.75,gl_a=1.,gl_d=2.)
out,geo=M.render({2:F},P,style)
q=l2.q4(out);q[q[...,3]==0,:3]=navy
l2.save(q,OUT/'title_logo_and_JP.png')
np.savez_compressed(OUT/'intro_amp_mask.npz',amp=F)
info={'donor_box':donor_box,'old_intro_face_box':old_box,'uniform_scale':scale,
      'face_left':left,'face_top':old_box[1],'navy':navy.tolist(),'geometry_offsets_unchanged':True,
      'material':'3DX intro & colors measured from original; no glow, shared crescent highlight'}
(OUT/'intro_amp_metrics.json').write_text(json.dumps(info,indent=2)+'\n',encoding='utf8')
print(json.dumps(info,indent=2))
