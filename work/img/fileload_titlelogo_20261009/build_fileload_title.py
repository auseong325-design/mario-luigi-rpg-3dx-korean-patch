"""Mode-select (M&L RPG3) logo = the main-title logo as shown on the title screen, minus
the parts the JP mode-select picture does not have (Mario/Luigi silhouettes, DX/deluxe,
outer glow, TM).

- Word + numeral keep their title-texture arrangement and are mapped with ONE transform
  whose x/y ratio is the measured on-screen ratio of the title (screen_registration.json,
  0.7323 : 0.7794 per 3DS pixel). Only a uniform scale is chosen to fit the picture.
- Word: latest title recipe re-rendered (render_title.py) with glow=False, no silhouettes.
- Numeral 3 + plate: installed title number layer, white glow unmixed over white, TM dropped.
- Stacking as on the title screen: the word, then the numeral plate over it (the plate hides
  the right part of the G; its left curl is the G's tail and continues the G).
- Background: logo-free picture from fileload_nologo_20261009.
"""
from pathlib import Path
import sys,json
import numpy as np,cv2
from scipy import ndimage as ndi
from PIL import Image
OUT=Path(__file__).parent;ROOT=OUT.parents[2]
sys.path.insert(0,str(OUT))
import render_title as RT
NAMES=['LOAD_GAME_IMG_ML_L_00_JP_ja','LOAD_GAME_IMG_ML_R_00_JP_ja']
NAVY=np.array([0,51,85],float)
TARGET_W=356        # logo body width in the 400 px picture
BOTTOM=90           # lowest body row (characters start at y~95)
TOP=3               # highest body row (plate spikes)

def warp_rgba(a,p,S=4):
    """premultiplied affine resample into the 400x208 canvas (4x supersampled)."""
    sx,sy,tx,ty=p;al=a[...,3:]/255
    pm=np.concatenate([a[...,:3]*al,a[...,3:]],2).astype(np.float32)
    A=np.array([[sx*S,0,tx*S],[0,sy*S,ty*S]],np.float32)
    w=cv2.warpAffine(pm,A,(400*S,208*S),flags=cv2.INTER_LINEAR,borderValue=0)
    return cv2.resize(w,(400,208),interpolation=cv2.INTER_AREA)

def strip_glow(top):
    """Remove the white glow. Opaque pixels are body as they are. A translucent pixel is
    body (navy rim / dark shading fringe, min channel ~0) over white glow; over white the
    glow vanishes, so body alpha = 1 - min(W)/255 and colour is unmixed from W."""
    al=top[...,3:]/255;W=top[...,:3]*al+255*(1-al)
    cov=np.clip((255-W.min(2))/(255-NAVY.min()),0,1)
    opaque=top[...,3]>=255
    cov[opaque&(W.min(2)<200)]=1                          # opaque glow is white: not body
    core=ndi.binary_fill_holes(cov>.5)
    lab,n=ndi.label(core);sizes=ndi.sum(core,lab,range(1,n+1))
    keep=lab==1+int(np.argmax(sizes))                    # the emblem; drops TM
    lab2,_=ndi.label(cov>.02);cov*=np.isin(lab2,np.unique(lab2[keep]))
    cov[keep&opaque]=1                                    # gloss/highlights inside the emblem
    rgb=(W-(1-cov[...,None])*255)/np.maximum(cov[...,None],1e-6)
    return np.dstack([np.clip(rgb,0,255),cov*255])

def body_box(layers):
    m=np.zeros(layers[0].shape[:2],bool)
    for l in layers:m|=(l[...,:3]*(l[...,3:]/255)+255*(1-l[...,3:]/255)).min(2)<128
    yy,xx=np.nonzero(m);return xx.min(),yy.min(),xx.max()+1,yy.max()+1

def main():
    reg=json.load(open(OUT/'screen_registration.json'))
    sw,sh=reg['screenshot_size'];p=reg['p_screenshot_px']
    sx3,sy3=p[0]*400/sw,p[1]*240/sh                       # per 3DS screen pixel
    word,rpg_dx=RT.render(glow=False,silhouettes=False)
    number=strip_glow(np.asarray(Image.open(ROOT/'work/img/title_layout_20261008/number_rgba.png').convert('RGBA'),float))
    bx=body_box([word,number])                            # texture px
    k=min(TARGET_W/((bx[2]-bx[0])*sx3),(BOTTOM-TOP)/((bx[3]-bx[1])*sy3))   # uniform only
    sx,sy=k*sx3,k*sy3
    jp=np.asarray(Image.open(ROOT/'work/img/fileload_nologo_20261009/original_jp.png').convert('RGB')).astype(float)
    nl=np.asarray(Image.open(ROOT/'work/img/fileload_nologo_20261009/fileload_nologo.png').convert('RGB')).astype(float)
    centre=193.                                           # JP logo centre (x 31..355)
    tx=centre-sx*(bx[0]+bx[2])/2;ty=BOTTOM-sy*bx[3]
    M=[sx,sy,tx,ty]
    wp,npm=warp_rgba(word,M),warp_rgba(number,M)
    # Title stacking: word (bottom texture) first, numeral plate (top texture) over it.
    # The plate's left curl is the G's tail drawn into the top texture; it lines up with the G.
    base=wp[...,:3]+nl*(1-wp[...,3:]/255)
    out=npm[...,:3]+base*(1-npm[...,3:]/255)
    out=np.clip(np.rint(out),0,255).astype(np.uint8)
    assert np.array_equal(out[95:],nl[95:].astype(np.uint8))
    rgba=np.dstack([out,np.full(out.shape[:2],255,np.uint8)])
    Image.fromarray(rgba).save(OUT/'fileload.png')
    for n,part in zip(NAMES,[rgba[:,:144],rgba[:,144:]]):Image.fromarray(part).save(OUT/(n+'.png'))
    kb=body_box([warp_rgba(word,M),npm])
    m={'map_texture_to_picture':M,'x_over_y':sx/sy,'title_screen_x_over_y':sx3/sy3,
       'scale_vs_title_screen':k,'logo_body_box':[int(v) for v in kb],'texture_body_box':[int(v) for v in bx],
       'glow':False,'silhouettes':False,'DX':False,'TM':False}
    (OUT/'art_metrics.json').write_text(json.dumps(m,indent=2)+'\n');print(m)
    Image.fromarray(np.concatenate([jp.astype(np.uint8),out],0)).resize((1200,1248),Image.NEAREST).save(OUT/'jp_vs_kr_x3.png')

if __name__=='__main__':main()
