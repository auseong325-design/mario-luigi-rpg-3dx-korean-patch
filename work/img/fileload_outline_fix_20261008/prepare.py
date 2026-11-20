from pathlib import Path
import sys,json,hashlib
import numpy as np
from PIL import Image
ROOT=Path(__file__).resolve().parents[3];OUT=Path(__file__).parent
sys.path.insert(0,str(ROOT/'scripts'));sys.path.insert(0,str(ROOT/'work/img/logo2'))
import lib3dx,lytimg,build_fileload as FL,l2
names=FL.NAMES
_,entries=lib3dx.read_bg4((OUT/'before_MLyt.dat').read_bytes())
entry=next(e for e in entries if e.name=='MENU_FILE_LOAD_JP_ja')
plain=lib3dx.bg4_plain(entry);images={}
for name,start,end in lytimg.sarc_list(plain):
    base=Path(name).stem
    if base in names:
        img=lytimg.bflim_to_rgba(plain[start:end]);images[base]=img
        Image.fromarray(img).save(OUT/('before_'+base+'.png'))
assert set(images)==set(names)
Image.fromarray(np.concatenate([images[n] for n in names],axis=1)).save(OUT/'before_fileload.png')
original=np.concatenate([l2.load(FL.SRC/(n+'.png')) for n in names],axis=1)
seg=FL.segment(original);_,comps=FL.groups(seg['cov'])
result={'before_MLyt_sha256':hashlib.sha256((OUT/'before_MLyt.dat').read_bytes()).hexdigest(),
        'FMdl_sha256':hashlib.sha256((ROOT/'patch/00040000001CA900/romfs/FMdl/JP/FMdl.dat').read_bytes()).hexdigest(),
        'original_face_components':comps,'texture_names':names,'image_size':list(original.shape[:2])}
(OUT/'before.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf8')
print(json.dumps(result,indent=2))
