from pathlib import Path
import sys
import numpy as np
from PIL import Image
from scipy import ndimage as ndi
ROOT=Path(__file__).resolve().parents[3];OUT=Path(__file__).parent
sys.path.insert(0,str(ROOT/'work/img/logo2'))
import build_fileload as OLD,l2
original=np.concatenate([l2.load(OLD.SRC/(n+'.png')) for n in OLD.NAMES],axis=1)
current=np.asarray(Image.open(OUT/'before_fileload.png'))
Image.fromarray(np.uint8(original)).save(OUT/'original_fileload.png')
for name,a in [('original',original),('current',current)]:
    Image.fromarray(np.uint8(a[0:95,215:362])).resize((588,380),Image.Resampling.NEAREST).save(OUT/(name+'_rpg3.png'))
rgb=original[:95,:,:3]
color=(rgb.max(2)-rgb.min(2)>80)&(rgb.max(2)>140)
lab,n=ndi.label(color)
for i,sl in enumerate(ndi.find_objects(lab)):
    if sl and sl[1].start>=200 and ndi.sum(color,lab,i+1)>3:
        print('colored',i+1,sl,'pixels',int((lab==i+1).sum()))
seg=OLD.segment(original)
lab,comps=OLD.groups(seg['cov'])
print('faces',comps,'navy',seg['navy'])
after=Image.open(ROOT/'work/img/fileload_logo_20261008/fileload.png')
after.crop((215,0,362,95)).resize((588,380),Image.Resampling.NEAREST).save(OUT/'after_rpg3.png')
