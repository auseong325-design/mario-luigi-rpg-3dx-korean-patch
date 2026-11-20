from pathlib import Path
import hashlib,json,shutil,sys
import numpy as np
from PIL import Image
ROOT=Path(__file__).resolve().parents[3];OUT=Path(__file__).parent
sys.path.insert(0,str(ROOT/'scripts'))
import build_fmdl
PATCH=ROOT/'patch/00040000001CA900/romfs/FMdl/JP/FMdl.dat'
assert not (OUT/'before_title.bch').exists(),'Preserve original snapshot'
raw,models=build_fmdl.load(PATCH)
plain=models['fmd_title_JP_ja'][1]
(OUT/'before_title.bch').write_bytes(plain)
bch=models['fmd_title_JP_ja'][2]
for t in bch.textures:
    Image.fromarray(bch.decode(t)).save(OUT/(t.name+'_before.png'))
previous=ROOT/'work/img/title_1dx_shapes_20261008'
for name in ['title_masks.npz','layout_metrics.json','screen_mapping.json','run_checked.py','preview_title.py']:
    shutil.copy2(previous/name,OUT/('before_'+name if name in ['title_masks.npz','layout_metrics.json'] else name))
refs=OUT/'ref';refs.mkdir(exist_ok=True)
shutil.copy2(Path('C:/Users/woose/Downloads/4oH_-xfod8dvyzDIM3BXqxRKZ7QKy7PUhoG_ExOO9SrAv8ht4sJqnKe_KeJJzTbsg70HnqfaZ0NVYXjMF7nW5g.png'),refs/'luigi_stem.png')
shutil.copy2(Path('C:/Users/woose/AppData/Local/Temp/codex-clipboard-d09dd5d5-af0d-4621-8b59-4ec861d0e52b.png'),refs/'lower_shading_complaint.png')
result={'before_fmdl_sha256':hashlib.sha256(raw).hexdigest(),'before_bch_sha256':hashlib.sha256(plain).hexdigest()}
(OUT/'before.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf8')
for name,p in [('1DX',ROOT/'work/img/logo/src/1DX/kr_logo_rgba.png'),('reference',refs/'luigi_stem.png')]:
    a=np.asarray(Image.open(p).convert('RGBA'))
    print(name,a.shape,'alpha',np.unique(a[...,3],return_counts=True))
    c,n=np.unique(a[:100,:,:3].reshape(-1,3),axis=0,return_counts=True)
    print('top colors',list(zip(c[np.argsort(n)[-10:]].tolist(),n[np.argsort(n)[-10:]].tolist())))
print(json.dumps(result,indent=2))
