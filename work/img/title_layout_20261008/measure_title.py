from pathlib import Path
import sys,json
import numpy as np
from PIL import Image
from scipy import ndimage as ndi
ROOT=Path(__file__).resolve().parents[3];OUT=Path(__file__).parent
sys.path.insert(0,str(ROOT/'scripts'))
import build_fmdl
_,models=build_fmdl.load(ROOT/'patch/00040000001CA900/romfs/FMdl/JP/FMdl.dat')
slot,plain,b=models['fmd_title_JP_ja']
(OUT/'before_title.bch').write_bytes(plain)
for name in ['title_logo_JP_bottom','title_logo_JP_top']:
    img=b.decode(b.texture(name));Image.fromarray(img).save(OUT/(name+'_before.png'))
    for threshold in [0,64,200,254]:
        yy,xx=np.nonzero(img[...,3]>threshold)
        print(name,threshold,[int(xx.min()),int(yy.min()),int(xx.max()+1),int(yy.max()+1)])
    if name.endswith('top'):
        for side,sel in [('3',np.indices(img.shape[:2])[1]>340),('DX',np.indices(img.shape[:2])[1]<340)]:
            yy,xx=np.nonzero((img[...,3]>64)&sel)
            print(side,'alpha64 box',[int(xx.min()),int(yy.min()),int(xx.max()+1),int(yy.max()+1)])
sys.path.insert(0,str(ROOT/'work/img/logo2'))
import l2,build_bottom
z=np.load(ROOT/'work/img/logo2/fit/jp_bottom.npz')
print('original sil components')
lab,n=ndi.label(z['sil'])
for i in range(1,n+1):
    yy,xx=np.nonzero(lab==i)
    if len(yy)>10: print(i,[xx.min()/4,yy.min()/4,(xx.max()+1)/4,(yy.max()+1)/4])
for sx in [.94,.90,.88]:
    build_bottom.P_LAY.update(sx=sx,sy=sx,x_left=18)
    placed,ampdx=build_bottom.build_masks({g:z[f'F{g}'] for g in range(1,7)},(256*4,512*4))
    yy,xx=np.nonzero(placed['ru']|placed['i']|placed['ji'])
    print('uniform layout',sx,'right',(xx.max()+1)/4,'ampdx',ampdx/4)
