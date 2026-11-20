"""Inspect donor geometry and the original Japanese underside material."""
from pathlib import Path
import sys,json
import numpy as np
from PIL import Image
from scipy import ndimage as ndi
ROOT=Path(__file__).resolve().parents[3];OUT=Path(__file__).parent
sys.path.insert(0,str(ROOT/'work/img/logo2'))
import l2,seg_1dx,build_bottom as BB,model as M
a=l2.load(l2.KR1DX);jp,F,style,sil=BB.jp_inputs()
print('1DX alpha extrema',a[...,3].min(),a[...,3].max(),'opaque',int((a[...,3]==255).sum()),'zero',int((a[...,3]==0).sum()))
print('1DX corner colors',a[0,0],a[120,0],a[20,500])
for g in (1,3):
    print('JP ext rows',g,[(y,style['ext'][g][y].round(1).tolist()) for y in range(118,145,2)])
print('source body bounds')
for threshold in [5,64,128,192,250]:
    yy,xx=np.nonzero((a[...,3]>threshold)&(np.arange(a.shape[0])[:,None]<105))
    print(threshold,[int(xx.min()),int(yy.min()),int(xx.max()+1),int(yy.max()+1)])
ref=l2.load(OUT/'ref/luigi_stem.png')
face=(ref[...,1]>70)&(ref[...,1]>ref[...,0]*1.12)&(ref[...,1]>ref[...,2]*1.07)
lab,n=ndi.label(face)
for i,sl in enumerate(ndi.find_objects(lab),1):
    if (lab==i).sum()>100:print('ref green component',i,[sl[1].start,sl[0].start,sl[1].stop,sl[0].stop],int((lab==i).sum()))
raw,_=seg_1dx.syllables(fix_stem=False)
stem=np.where(np.arange(a.shape[1])[None,:]>=318,raw['ji'],0)
for y in range(32,62):
    xs=np.nonzero(stem[y]>.5)[0]
    if len(xs):print('donor stem',y,int(xs.min()),int(xs.max()))
rows=[
    [('1DX word (original)',l2.zoom_img(l2.comp_on(a)[10:104,:340],3))],
    [('current lower edge',l2.zoom_img(l2.comp_on(l2.load(OUT/'title_logo_JP_bottom_before.png'))[115:160,10:325],3))],
    [('JP lower edge',l2.zoom_img(l2.comp_on(jp)[105:144,45:282],4))],
    [('user rounded stem',l2.zoom_img(l2.comp_on(ref)[25:150,300:340],4)),('1DX raw ji',l2.zoom_img(l2.comp_on(a)[28:87,283:339],6))]
]
l2.sheet(rows,OUT/'inspection.png')
