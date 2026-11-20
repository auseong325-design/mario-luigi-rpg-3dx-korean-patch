"""R separated faithfully from the JP 쿠파Jr.RPG logo.

- Face, light rims, inner hole and both legs: the original pixels, unchanged.
- Dark outline: the original pixels wherever nothing covers them. Where the Jr. pieces
  (left), the wind puff (bottom-left), the pink star / clown car (top) or the P's outline
  (right) cover or merge with it, it is continued with the measured outline model:
  face dilated by 5.5 px, offset (-0.5,-0.5) (fit_outline.py, IoU 0.988 on uncovered parts).
- Output: R_clean.png (60x63 at picture (201,140)), R_clean_aligned.png (400x208).
"""
import numpy as np,json
from PIL import Image
from scipy import ndimage as ndi
IMG='../lyt/3DX/MLyt/MENU_FILE_LOAD_JP_ja/'
full=np.concatenate([np.asarray(Image.open(IMG+n+'.png').convert('RGB')) for n in ['LOAD_GAME_IMG_KJ_L_00_JP_ja','LOAD_GAME_IMG_KJ_R_00_JP_ja']],1).astype(float)
fit=json.load(open('outline_fit.json'))
OX,OY,W,H=201,140,60,63
c=full[OY:OY+H,OX:OX+W];yy,xx=np.mgrid[:H,:W]+np.array([OY,OX])[:,None,None]
r,g,b=c[...,0],c[...,1],c[...,2]
dark=np.maximum(np.maximum(r,g),b)<150
white=c.min(2)>225
bright=~dark&~white
lab,_=ndi.label(bright)
F=lab==lab[170-OY,215-OX]
inner=ndi.binary_fill_holes(F)                       # face + rims + the R's hole
# model alpha (smooth): distance from the face, shifted by the fitted offset
S=4
Fu=np.kron(F,np.ones((S,S),bool))
d=ndi.distance_transform_edt(~Fu)/S
d=ndi.shift(d,(fit['oy']*S,fit['ox']*S),order=1,mode='nearest')
d=np.minimum(d,ndi.distance_transform_edt(~Fu)/S+abs(fit['ox'])+abs(fit['oy']))
cov_hr=(d<=fit['rad']).astype(float)
model=cov_hr.reshape(H,S,W,S).mean((1,3))
model[inner]=1
# uncovered areas: use the original's own anti-aliased edge (dark red over white)
covered=np.zeros((H,W),bool)
covered|=(xx>=244)                                   # P / clown car side
covered|=(yy<=147)&(xx>=217)                         # pink star / clown car
covered|=(xx<=208)&(yy>=156)                         # Jr. pieces (they reach x=208)
covered|=(xx<=226)&(yy>=187)                         # wind puff
jp_alpha=np.clip(1-g/255.0,0,1)                      # dark red has g~0, white g=255
jp_alpha=np.where(dark|bright,np.maximum(jp_alpha,dark*1.0),jp_alpha)
near=ndi.binary_dilation(model>0,iterations=1)
alpha=np.where(covered,model,np.where(near,jp_alpha,0))
alpha[inner]=1
alpha[~ndi.binary_dilation(model>0,iterations=1)]=0
# colours: covered outline takes the nearest clearly dark, uncovered outline pixel
rgb=c.copy()
vis_dark=(r<95)&(g<=8)&(b<=8)&~covered&(model>=.999)&~inner
_,(iy,ix)=ndi.distance_transform_edt(~vis_dark,return_indices=True)
nearest_dark=c[iy,ix]
edge=(~inner)&(alpha<1)&~covered
un=(c-255*(1-alpha[...,None]))/np.maximum(alpha[...,None],1e-3)
rgb=np.where(edge[...,None],np.clip(un,0,255),rgb)
occl=covered&~inner&(alpha>0)
rgb=np.where(occl[...,None],nearest_dark,rgb)
# Keep the accepted first separation (kj_parts) for the outline above the legs: its top
# (star/clown), right (P) and left (Jr.) edges were fine. Rebuild only the leg zone.
prev=np.asarray(Image.open('../kj_parts_20261009/R_clean.png').convert('RGBA')).astype(float)
zone=(yy>=184)&(xx<=247)
alpha=np.where(zone,alpha,prev[...,3]/255)
rgb=np.where(zone[...,None],rgb,prev[...,:3])
alpha[inner]=1;rgb[inner]=c[inner]
out=np.dstack([np.clip(np.rint(rgb),0,255),np.rint(alpha*255)]).astype(np.uint8)
out[out[...,3]==0,:3]=0
Image.fromarray(out).save('R_clean.png')
al=np.zeros((208,400,4),np.uint8);al[OY:OY+H,OX:OX+W]=out;Image.fromarray(al).save('R_clean_aligned.png')
assert np.array_equal(out[inner,:3],c[inner].astype(np.uint8)),'face/rims/legs must be the original pixels'
print({'leg_zone_px':int(zone.sum()),'inner_px_original':int(inner.sum()),'alpha_px':int((out[...,3]>0).sum()),
       'covered_outline_px_rebuilt':int((occl&(alpha>0)).sum())})
def onblue(a):
    a=a.astype(float);al=a[...,3:]/255;return (a[...,:3]*al+np.array([60,120,220])*(1-al)).astype(np.uint8)
old=np.asarray(Image.open('../kj_R_crotch_20261010/R_clean.png').convert('RGBA'))
tiles=[c.astype(np.uint8),onblue(old),onblue(out)]
row=np.concatenate([np.pad(t,((0,0),(0,2),(0,0)),constant_values=255) for t in tiles],1)
Image.fromarray(row).resize((row.shape[1]*8,row.shape[0]*8),Image.NEAREST).save('R_compare.png')
