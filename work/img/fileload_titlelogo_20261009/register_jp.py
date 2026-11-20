"""Measure where the JP title textures sit in the JP file-select picture (word and numeral separately)."""
import cv2,numpy as np,json
from PIL import Image
from pathlib import Path
from scipy.optimize import minimize
ROOT=Path(__file__).resolve().parents[3]
JP=ROOT/'work/img/fmdl/3DX/fmd_title_JP_ja'
fl=np.asarray(Image.open(ROOT/'work/img/fileload_nologo_20261009/original_jp.png').convert('RGB')).astype(np.float32)
def over_white(p):
    a=np.asarray(Image.open(p).convert('RGBA')).astype(np.float32);al=a[...,3:]/255
    return a[...,:3]*al+255*(1-al),a[...,3]
bot,ab=over_white(JP/'title_logo_JP_bottom.png');top,at=over_white(JP/'title_logo_JP_top.png')
def warp(img,p,S=4):
    sx,sy,tx,ty=p;A=np.array([[sx*S,0,tx*S],[0,sy*S,ty*S]])
    return cv2.resize(cv2.warpAffine(img,A,(400*S,208*S),flags=cv2.INTER_LINEAR,borderValue=(255,255,255)),(400,208),interpolation=cv2.INTER_AREA)
res={}
for name,img,region,p0 in [('word',bot,(slice(5,92),slice(20,300)),[.62,.62,10,-30]),('numeral',top.copy(),(slice(5,92),slice(300,360)),None)]:
    if name=='numeral':img[:,:350]=255
    # coarse init from bounding boxes of dark ink
    ink=img.min(2)<120; fi=fl.min(2)<120; m=np.zeros_like(fi);m[region]=True;fi&=m
    if name=='numeral': fi[:, :303]=False
    yy,xx=np.nonzero(ink);fy,fx=np.nonzero(fi)
    s=(fx.max()-fx.min())/(xx.max()-xx.min());sy=(fy.max()-fy.min())/(yy.max()-yy.min())
    p0=[s,sy,fx.min()-s*xx.min(),fy.min()-sy*yy.min()]
    def cost(p):return np.abs(warp(img,p)-fl)[region].mean()
    r=minimize(cost,p0,method='Nelder-Mead',options=dict(maxiter=800,xatol=1e-4,fatol=1e-3))
    res[name]={'p0':[float(v) for v in p0],'p':[float(v) for v in r.x],'err':float(r.fun)}
    print(name,res[name])
json.dump(res,open('jp_registration.json','w'),indent=2)
