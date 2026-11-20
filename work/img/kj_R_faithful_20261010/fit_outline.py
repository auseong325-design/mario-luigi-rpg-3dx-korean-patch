"""Fit the R's dark outline as a function of its face, on the parts nothing covers in the JP picture."""
import numpy as np,json
from PIL import Image
from scipy import ndimage as ndi
IMG='../lyt/3DX/MLyt/MENU_FILE_LOAD_JP_ja/'
full=np.concatenate([np.asarray(Image.open(IMG+n+'.png').convert('RGB')) for n in ['LOAD_GAME_IMG_KJ_L_00_JP_ja','LOAD_GAME_IMG_KJ_R_00_JP_ja']],1).astype(int)
X0,Y0=195,135;c=full[Y0:208,X0:270];H,W=c.shape[:2]
yy,xx=np.mgrid[:H,:W]+np.array([Y0,X0])[:,None,None]
r,g,b=c[...,0],c[...,1],c[...,2]
dark=np.maximum(np.maximum(r,g),b)<150
white=c.min(2)>225
# face + rims: everything bright that is not white, inside the letter; the R's component
bright=~dark&~white
lab,_=ndi.label(bright)
F=lab==lab[170-Y0,215-X0]
F=ndi.binary_fill_holes(F|ndi.binary_fill_holes(F))  # hole of R is dark: keep it out below
hole=ndi.binary_fill_holes(lab==lab[170-Y0,215-X0])&~(lab==lab[170-Y0,215-X0])
F=(lab==lab[170-Y0,215-X0])
print('face px',F.sum(),'bbox x',xx[F].min(),xx[F].max(),'y',yy[F].min(),yy[F].max())
# reliable (uncovered) area
rel=np.ones((H,W),bool)
rel&=~(xx>=244)                          # P / clown
rel&=~((yy<=147)&(xx>=217))              # pink star / clown
rel&=~((xx<=212)&(yy>=156))              # Jr. pieces
rel&=~((xx<=226)&(yy>=187))              # puff
Fh=F
best=None
for rad in np.arange(4,9.1,.5):
  for ox in np.arange(-1,3.1,.5):
    for oy in np.arange(-1,3.1,.5):
        d=ndi.distance_transform_edt(~Fh)
        Dm=ndi.shift((d<=rad).astype(float),(oy,ox),order=1)>.5
        Dm|=(d<=rad-max(abs(ox),abs(oy)))
        Dm|=Fh
        sil_jp=(dark|bright)&~white
        a=Dm&rel;bm=sil_jp&rel
        # compare only near the letter (within 12px)
        near=(d<=12)&rel
        iou=( (a&bm&near).sum() )/max(((a|bm)&near).sum(),1)
        if best is None or iou>best[0]:best=(iou,rad,ox,oy)
print('best iou,rad,ox,oy',best)
json.dump({'iou':best[0],'rad':best[1],'ox':best[2],'oy':best[3],'X0':X0,'Y0':Y0},open('outline_fit.json','w'),indent=2)
np.savez('face.npz',F=F,hole=hole)
