from pathlib import Path
import sys
import numpy as np
from scipy import ndimage as ndi
ROOT=Path(__file__).resolve().parents[3];OUT=Path(__file__).parent
sys.path.insert(0,str(ROOT/'work/img/logo2'))
import l2,seg_1dx,build_bottom as BB,model as M
a=l2.load(l2.KR1DX);raw,_=seg_1dx.syllables(fix_stem=False)
groups={1:np.maximum.reduce([raw[k] for k in ('ma','ri','o')]),2:raw['amp'],3:np.maximum.reduce([raw[k] for k in ('ru','i','ji')])}
lab=np.zeros(a.shape[:2],int)
for g,m in groups.items():lab[m>.3]=g
_,idx=ndi.distance_transform_edt(lab==0,return_indices=True)
own=lab[tuple(idx)]
ys=np.arange(a.shape[0])[:,None]
mask=(a[...,3]>250)&(lab==0)&(ys<100)&(np.arange(a.shape[1])[None,:]<338)
for g in groups:
    m=mask&(own==g)&(ys>idx[0])
    rgb=a[...,:3][m]
    navy=np.array([0,44,74])
    dif=rgb-navy
    d=np.sqrt((dif*dif).sum(1))
    print('1DX shadow',g,'n',len(rgb),'distance percentiles',np.percentile(d,[0,50,75,90,99]).round(2).tolist())
    print('colors strongest',np.median(rgb[d>=np.percentile(d,95)],axis=0))
    c,n=np.unique(rgb,axis=0,return_counts=True)
    print('frequent',list(zip(c[np.argsort(n)[-10:]].astype(int).tolist(),n[np.argsort(n)[-10:]].tolist())))
jp,F,st,sil=BB.jp_inputs();geo=M.geometry(F,M.Params())
dist=ndi.distance_transform_edt(~geo['F'],return_indices=True)
dd=l2.centre(dist[0]/l2.HR);nearest_y=l2.centre(dist[1][0].astype(float))/l2.HR
owner=geo['nlab'][2::4,2::4]
ys=np.arange(jp.shape[0])[:,None]
valid=(jp[...,3]>250)&(jp[...,:3].max(2)<190)&(jp[...,:3].mean(2)<90)&(ys>nearest_y+3)&(dd>3)
for gid in (1,2,3):
    rgb=jp[...,:3][valid&(owner==gid)]
    d=np.sqrt(((rgb-np.array([0,51,85]))**2).sum(1))
    print('JP shadow',gid,'strongest median',np.median(rgb[d>=np.percentile(d,95)],axis=0),'channel99',np.percentile(rgb,99,axis=0))
    c,n=np.unique(rgb,axis=0,return_counts=True)
    print('JP frequent',list(zip(c[np.argsort(n)[-10:]].astype(int).tolist(),n[np.argsort(n)[-10:]].tolist())))
