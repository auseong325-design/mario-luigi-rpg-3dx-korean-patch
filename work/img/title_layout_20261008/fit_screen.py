"""Register decoded title textures to the supplied screenshot; estimate the visible pose."""
from pathlib import Path
import json
import numpy as np
from PIL import Image
from scipy.ndimage import map_coordinates,gaussian_filter
from scipy.optimize import differential_evolution
OUT=Path(__file__).parent
bot=Image.open(OUT/'title_logo_JP_bottom_before.png').convert('RGBA')
top=Image.open(OUT/'title_logo_JP_top_before.png').convert('RGBA')
src=np.asarray(Image.alpha_composite(bot,top),float)
dst=np.asarray(Image.open('C:/Users/woose/Desktop/2026-10-08_12-08-56.994_top.png').convert('RGB'),float)
mask=(src[...,3]==255)&(src[...,:3].max(2)>155)&((src[...,:3].max(2)-src[...,:3].min(2))>80)
mask[:48]=0
yy,xx=np.nonzero(mask)
sel=np.arange(0,len(xx),4)
yy,xx=yy[sel],xx[sel];colors=src[yy,xx,:3]
ds=[gaussian_filter(dst[...,c],.45) for c in range(3)]
def loss(p):
    ax,ay,bx,by=p
    px=ax*(xx+.5)+bx;py=ay*(yy+.5)+by
    got=np.stack([map_coordinates(ch,[py-.5,px-.5],order=1,mode='constant',cval=0) for ch in ds],1)
    err=((got-colors)**2).mean(1)
    return float(np.minimum(err,6000).mean())
r=differential_evolution(loss,[(.62,.82),(.62,.82),(-5,40),(-35,0)],seed=3108,popsize=12,maxiter=70,tol=.002,polish=True)
ax,ay,bx,by=r.x
data={'scale_x':ax,'scale_y':ay,'offset_x':bx,'offset_y':by,'robust_rgb_error':r.fun,
      'note':'Approximate affine registration of supplied screenshot, not emulator camera verification.'}
(OUT/'screen_mapping.json').write_text(json.dumps(data,indent=2)+'\n',encoding='utf8')
print(json.dumps(data,indent=2))
Y,X=np.mgrid[:240,:400]
v=np.stack([map_coordinates(src[...,c],[(Y+.5-by)/ay-.5,(X+.5-bx)/ax-.5],order=1,mode='constant') for c in range(4)],2)
al=v[...,3:]/255
preview=np.uint8(np.clip(v[...,:3]*al+dst*(1-al),0,255))
Image.fromarray(preview).save(OUT/'registration_overlay.png')
