"""Measure the on-screen mapping of the KR title textures from the user's title screenshot."""
import cv2,numpy as np,json
from PIL import Image
from pathlib import Path
from scipy.optimize import minimize
ROOT=Path(__file__).resolve().parents[3]
scr=np.asarray(Image.open('title_screen_user.webp').convert('RGB')).astype(np.float32)
H,W=scr.shape[:2]
L=ROOT/'work/img/logo2/out'
b=np.asarray(Image.open(L/'title_logo_JP_bottom.png').convert('RGBA')).astype(np.float32)
t=np.asarray(Image.open(L/'title_logo_JP_top.png').convert('RGBA')).astype(np.float32)
def comp(a,b):
    aa=a[...,3:]/255;ba=b[...,3:]/255;oa=ba+aa*(1-ba)
    rgb=(b[...,:3]*ba+a[...,:3]*aa*(1-ba))/np.maximum(oa,1e-6);return np.dstack([rgb,oa*255])
tex=comp(b,t)            # top over bottom; only opaque body pixels are compared
op=(tex[...,3]>=250).astype(np.float32)
def warp(img,p,flags=cv2.INTER_LINEAR):
    sx,sy,tx,ty=p;A=np.array([[sx,0,tx],[0,sy,ty]],np.float32)
    return cv2.warpAffine(img,A,(W,H),flags=flags,borderValue=0)
def cost(p):
    m=warp(op,p)>.99;r=warp(tex[...,:3],p)
    return float(np.abs(r[m]-scr[m]).mean()) if m.sum()>1000 else 1e9
m0=json.load(open(ROOT/'work/img/title_layout_20261008/screen_mapping.json'))
k=W/400
p0=[m0['scale_x']*k,m0['scale_y']*k,m0['offset_x']*k,m0['offset_y']*k]
print('p0',p0,cost(p0))
best=None
for dx in (-6,0,6):
  for dy in (-6,0,6):
    q=[p0[0],p0[1],p0[2]+dx,p0[3]+dy];r=minimize(cost,q,method='Nelder-Mead',options=dict(maxiter=600,xatol=1e-4,fatol=1e-3,initial_simplex=None))
    if best is None or r.fun<best.fun:best=r
p=best.x;print('fit',p.tolist(),best.fun,'aspect sx/sy',p[0]/p[1])
json.dump({'p_screenshot_px':p.tolist(),'err':best.fun,'aspect_x_over_y':p[0]/p[1],'screenshot_size':[W,H]},open('screen_registration.json','w'),indent=2)
v=warp(tex,p);a=v[...,3:]/255;o=v[...,:3]*a+scr*(1-a)
Image.fromarray(np.concatenate([scr,o],1).astype(np.uint8)).save('screen_registration_check.png')
