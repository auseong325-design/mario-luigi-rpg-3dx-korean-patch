from pathlib import Path
import sys
import numpy as np
from scipy import ndimage as ndi
from PIL import Image
ROOT=Path(__file__).resolve().parents[3];OUT=Path(__file__).parent
sys.path.insert(0,str(ROOT/'work/img/logo2'))
import l2,build_fileload as OLD
a=np.asarray(Image.open(ROOT/'work/img/fileload_logo_20261008/fileload.png'))
z=np.load(ROOT/'work/img/fileload_logo_20261008/fileload_masks.npz')
B=l2.down(z['body'].astype(float));F=l2.down(np.logical_or.reduce([z[k] for k in ['ma','ri','o','amp','ru','i','ji']]).astype(float))
white=a[...,:3].min(2)>180
print('bright near right interface in opaque generated body',np.argwhere(white&(B>.95)&(np.arange(400)[None,:]>=295)).tolist())
labs,n=ndi.label(white)
for i,sl in enumerate(ndi.find_objects(labs)):
    if sl and 290<=sl[1].start<310 and sl[0].start<90:
        print('bright component',i+1,sl,np.argwhere(labs==i+1).tolist())
print('white at join in any non-bg component',[(int(y),int(x),bool(z['number_restore'][y,x]),bool(z['erase'][y,x])) for y,x in np.argwhere(white&ndi.binary_fill_holes(a[...,:3].min(2)<150)&(np.arange(400)[None,:]>=295)&(np.arange(400)[None,:]<305))])
print('mask keep ranges')
for y in [8,16,24,30,31,32,33,34,35,40,45,50,55,58,60,65,70,73,75,78,80,83]:
    xs=np.nonzero(z['number_restore'][y,:320])[0]
    print(y,xs.tolist())
