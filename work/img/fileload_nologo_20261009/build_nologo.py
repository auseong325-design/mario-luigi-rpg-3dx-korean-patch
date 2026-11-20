"""Mode-select (M&L RPG3) background without the logo.

Original JP art; logo removed to white; the Bowser area the logo covered is
refilled from the registered box-art Bowser (bowser_boxart.png), colour-matched
to the game art. Output: two halves split at x=144 (same as fileload_logo).
"""
from pathlib import Path
import cv2,numpy as np,json
from scipy import ndimage as ndi
from PIL import Image
HERE=Path(__file__).parent;ROOT=HERE.parents[2]
NAMES=['LOAD_GAME_IMG_ML_L_00_JP_ja','LOAD_GAME_IMG_ML_R_00_JP_ja']
SRC=ROOT/'work/img/lyt/3DX/MLyt/MENU_FILE_LOAD_JP_ja'
g=np.concatenate([np.asarray(Image.open(SRC/(n+'.png')).convert('RGB')) for n in NAMES],1).astype(np.float32)
H,W=g.shape[:2]
b=np.asarray(Image.open(HERE/'bowser_boxart.png').convert('RGBA')).astype(np.float32)
a=b[...,3:]/255;bw=b[...,:3]*a+255*(1-a)
M=np.load(HERE/'warp_best.npy');S=4
A=(np.diag([S,S,1.])@np.vstack([M,[0,0,1]]))[:2]
box=cv2.resize(cv2.warpAffine(bw,A,(W*S,H*S),flags=cv2.INTER_CUBIC,borderValue=(255,255,255)),(W,H),interpolation=cv2.INTER_AREA)
box=np.clip(box,0,255)
yy,xx=np.mgrid[:H,:W]
LOGO_Y=93
# colour match: affine RGB fit on clean Bowser pixels (below the logo, not white, not edges)
edge=ndi.gaussian_gradient_magnitude(g.mean(2),1)>25
fit=(yy>=LOGO_Y)&(xx>=262)&(box.min(2)<235)&(g.min(2)<235)&~ndi.binary_dilation(edge,iterations=1)
X=np.c_[box[fit],np.ones(fit.sum())];C,*_=np.linalg.lstsq(X,g[fit],rcond=None)
boxc=np.clip(np.c_[box.reshape(-1,3),np.ones(H*W)]@C,0,255).reshape(H,W,3)
white=box.min(2)>=250;boxc[white]=255   # keep pure white outside Bowser
# logo mask: in the logo band, anything not explained by the box-art Bowser/white
diff=np.abs(cv2.GaussianBlur(g,(0,0),.8)-cv2.GaussianBlur(boxc,(0,0),.8)).max(2)
logo=(diff>45)&(yy<LOGO_Y)
logo=ndi.binary_closing(logo,iterations=3)
logo=ndi.binary_fill_holes(logo)
lab,n=ndi.label(logo);sizes=ndi.sum(logo,lab,range(1,n+1))
logo=np.isin(lab,1+np.nonzero(sizes>=40)[0])
logo=ndi.binary_fill_holes(ndi.binary_dilation(logo,iterations=3))&(yy<LOGO_Y+2)
w=np.clip(ndi.gaussian_filter(logo.astype(float),.9)*1.6,0,1)
w[logo]=1;w[yy>=LOGO_Y+2]=0
out=g*(1-w[...,None])+boxc*w[...,None]
out=np.clip(np.rint(out),0,255).astype(np.uint8)
# drop faint box-art specks left in the white band
lab,n=ndi.label((out.min(2)<255)&(yy<LOGO_Y))
for i,sz in enumerate(ndi.sum(np.ones((H,W)),lab,range(1,n+1))):
    if sz<20:out[lab==i+1]=255
assert np.array_equal(out[LOGO_Y+2:],g[LOGO_Y+2:].astype(np.uint8))
rgba=np.dstack([out,np.full((H,W),255,np.uint8)])
Image.fromarray(rgba).save(HERE/'fileload_nologo.png')
for n,part in zip(NAMES,[rgba[:,:144],rgba[:,144:]]):Image.fromarray(part).save(HERE/(n+'.png'))
Image.fromarray((logo*255).astype(np.uint8)).save(HERE/'logo_mask.png')
cmp=np.concatenate([g.astype(np.uint8),out],0)
Image.fromarray(cmp).resize((W*3,H*6),Image.NEAREST).save(HERE/'before_after_x3.png')
json.dump({'warp_box_to_game':M.tolist(),'colour_affine':C.tolist(),'logo_mask_px':int(logo.sum()),
  'boxart_px_used':int((w>0).sum()),'rows_unchanged_from':LOGO_Y+2},open(HERE/'art_verify.json','w'),indent=2)
print('ok',int(logo.sum()))
