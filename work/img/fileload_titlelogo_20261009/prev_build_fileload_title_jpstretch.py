"""Mode-select (M&L RPG3) logo = latest main-title logo, placed like the JP original.

- Word: latest title recipe re-rendered without glow and without the Mario/Luigi silhouettes.
- Numeral 3 (with its Bowser-emblem plate): the installed title number layer with the
  white glow removed (unmixed over white via the navy outline) and without the TM mark.
- Placement: the JP file-select logo equals the JP title textures under
  x' = sx*x + tx, y' = sy*y + ty (measured separately for word and numeral,
  jp_registration.json). The same maps are applied to the Korean title layers,
  then the whole logo is re-centred on the JP logo centre.
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
TARGET_W=350
NAVY=np.array([0,51,85],float)
reg=json.load(open(OUT/'jp_registration.json'))

def warp_rgba(a,p,dx=0.,S=4):
    """premultiplied affine resample into the 400x208 canvas (4x supersampled)."""
    sx,sy,tx,ty=p;al=a[...,3:]/255
    pm=np.concatenate([a[...,:3]*al,a[...,3:]],2).astype(np.float32)
    A=np.array([[sx*S,0,(tx+dx)*S],[0,sy*S,ty*S]],np.float32)
    w=cv2.warpAffine(pm,A,(400*S,208*S),flags=cv2.INTER_LINEAR,borderValue=0)
    return cv2.resize(w,(400,208),interpolation=cv2.INTER_AREA)  # premultiplied

def strip_glow(top):
    """Glow is white: over white it vanishes. Recover body coverage from the navy rim."""
    al=top[...,3:]/255;W=top[...,:3]*al+255*(1-al)
    cov=np.clip((255-W.min(2))/(255-NAVY.min()),0,1)
    body=ndi.binary_fill_holes(cov>.5)
    lab,n=ndi.label(body);sizes=ndi.sum(body,lab,range(1,n+1))
    keep=np.isin(lab,1+np.argsort(sizes)[::-1][:1])     # the emblem; drops TM
    near=ndi.binary_dilation(keep,iterations=2)
    cov=np.where(keep,1.,cov*near)
    lab2,n2=ndi.label(cov>0)                            # cut TM halo leftovers
    cov*=np.isin(lab2,np.unique(lab2[keep]))
    rgb=(W-(1-cov[...,None])*255)/np.maximum(cov[...,None],1e-6)
    return np.dstack([np.clip(rgb,0,255),cov*255]),int(n)

def main():
    word,rpg_dx=RT.render(glow=False,silhouettes=False)
    word_glow,_=RT.render(glow=True,silhouettes=False)
    word[...,3][word[...,3]<1]=0
    number=np.asarray(Image.open(ROOT/'work/img/title_layout_20261008/number_rgba.png').convert('RGBA'),float)
    number,_=strip_glow(number)
    jp=np.asarray(Image.open(ROOT/'work/img/fileload_nologo_20261009/original_jp.png').convert('RGB')).astype(float)
    nl=np.asarray(Image.open(ROOT/'work/img/fileload_nologo_20261009/fileload_nologo.png').convert('RGB')).astype(float)
    JP=ROOT/'work/img/fmdl/3DX/fmd_title_JP_ja'
    jw=np.asarray(Image.open(JP/'title_logo_JP_bottom.png').convert('RGBA'),float)
    jn=np.asarray(Image.open(JP/'title_logo_JP_top.png').convert('RGBA'),float);jn[:,:350]=0
    jw_sil=np.load(ROOT/'work/img/logo2/fit/jp_bottom.npz')['sil']
    jw[RT.l2.down(jw_sil.astype(float))>0,3]=0           # JP word box without silhouettes
    def bbox(layers):
        # body extent: dark navy rim over white (white glow does not count)
        m=np.zeros((208,400),bool)
        for l in layers:
            W=l[...,:3]+255*(1-l[...,3:]/255);m|=W.min(2)<128
        yy,xx=np.nonzero(m);return xx.min(),yy.min(),xx.max()+1,yy.max()+1
    jbox=bbox([warp_rgba(jw,reg['word']['p']),warp_rgba(jn,reg['numeral']['p'])])
    kbox=bbox([warp_rgba(word,reg['word']['p']),warp_rgba(number,reg['numeral']['p'])])
    centre=(jbox[0]+jbox[2])/2
    # same letter height as JP; squeeze only x so the longer Korean word fits (TARGET_W)
    kx=min(1.,TARGET_W/(kbox[2]-kbox[0]))
    def fit(p):
        sx,sy,tx,ty=p;return [sx*kx,sy,kx*tx+(1-kx)*centre,ty]
    wmap,nmap=fit(reg['word']['p']),fit(reg['numeral']['p'])
    k2=bbox([warp_rgba(word,wmap),warp_rgba(number,nmap)])
    dx=centre-(k2[0]+k2[2])/2
    wp=warp_rgba(word,wmap,dx);npm=warp_rgba(number,nmap,dx)
    al=np.maximum(wp[...,3],npm[...,3])>128;kx_=np.nonzero(al.any(0))[0]
    jx=np.array([jbox[0],jbox[2]-1])

    # Title stacking is numeral -> word+white glow; the glow hides the plate's left curl/fringe.
    # White glow is invisible on the white background, so apply it only there (never over Bowser).
    wg=warp_rgba(word_glow,wmap,dx)
    # The G's grey-teal underside runs on over the navy numeral plate and stops with a hard
    # edge there. Over the plate, merge those near-navy word pixels into the plate navy.
    for L in (wp,wg):
        a_=L[...,3:]/255;col=L[...,:3]/np.maximum(a_,1e-6)
        fix=(npm[...,3]>250)&(np.abs(col-NAVY).max(2)<90)&(L[...,3]>0)
        L[fix,:3]=NAVY*a_[fix]
    white=nl.min(2)>=250
    base=npm[...,:3]+nl*(1-npm[...,3:]/255)
    top_layer=np.where(white[...,None],wg,wp)
    out=top_layer[...,:3]+base*(1-top_layer[...,3:]/255)
    out=np.clip(np.rint(out),0,255).astype(np.uint8)
    assert np.array_equal(out[95:],nl[95:].astype(np.uint8))
    rgba=np.dstack([out,np.full(out.shape[:2],255,np.uint8)])
    Image.fromarray(rgba).save(OUT/'fileload.png')
    for n,part in zip(NAMES,[rgba[:,:144],rgba[:,144:]]):Image.fromarray(part).save(OUT/(n+'.png'))
    ink=np.nonzero(al)
    m={'word_map':wmap,'numeral_map':nmap,'x_squeeze':kx,'jp_logo_box':[int(v) for v in jbox],'centre_shift_x':float(dx),
       'jp_logo_x':[int(jx.min()),int(jx.max())+1],'kr_logo_box':[int(kx_.min()),int(ink[0].min()),int(kx_.max())+1,int(ink[0].max())+1],
       'glow':False,'silhouettes':False,'DX':False,'TM':False,'rpg_dx':float(rpg_dx)}
    (OUT/'art_metrics.json').write_text(json.dumps(m,indent=2)+'\n');print(m)
    cmp=np.concatenate([jp.astype(np.uint8),out],0)
    Image.fromarray(cmp).resize((1200,1248),Image.NEAREST).save(OUT/'jp_vs_kr_x3.png')

if __name__=='__main__':main()
