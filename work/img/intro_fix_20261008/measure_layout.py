from pathlib import Path
import sys,json
import numpy as np
ROOT=Path(__file__).resolve().parents[3]
OUT=Path(__file__).resolve().parent
sys.path.insert(0,str(ROOT/'work/img/logo2'))
import l2
def box(m,hr=1):
    ys,xs=np.nonzero(m)
    return [xs.min()/hr,ys.min()/hr,(xs.max()+1)/hr,(ys.max()+1)/hr]
jp=np.load(ROOT/'work/img/logo2/fit/jp_bottom.npz')
kr=np.load(ROOT/'work/img/logo2/fit/kr_bottom_layout.npz')
for g,key,name in [(1,'Fma','title_logo_M_JP'),(2,'Famp','title_logo_and_JP'),(3,'Flu','title_logo_L_JP')]:
    print(name,'mainjp',box(jp[f'F{g}'],4),'mainkr',box(kr[key],4))
    if g!=2:
        p=np.load(ROOT/f'work/img/logo2/fit/piece_{name}.npz')
        print(' piecejpface',box(p['F'],4))
    for kind,base in [('jp',l2.JP_DIR),('kr',ROOT/'work/img/fmdl_ko/fmd_title_JP_ja')]:
        path=base/f'{name}.png'
        if not path.exists():continue
        a=l2.load(path)
        mask=(a[...,3]>0)&((a[...,0]>100)|(a[...,1]>100))
        print(' ',kind,'alpha',box(a[...,3]>0),'faceapprox',box(mask))
