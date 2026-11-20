from pathlib import Path
import hashlib,json,shutil,sys
import numpy as np
from PIL import Image
ROOT=Path(__file__).resolve().parents[3];OUT=Path(__file__).parent
sys.path.insert(0,str(ROOT/'scripts'))
import build_fmdl,lib3dx
PATCH=ROOT/'patch/00040000001CA900/romfs/FMdl/JP/FMdl.dat'
assert not (OUT/'before_title.bch').exists(),'Preserve snapshot'
raw,models=build_fmdl.load(PATCH)
(OUT/'before_fmdl.dat').write_bytes(raw)
_,plain,bch=models['fmd_title_JP_ja']
(OUT/'before_title.bch').write_bytes(plain)
_,orig=build_fmdl.load(lib3dx.romfs_path('FMdl/JP/FMdl.dat'))
(OUT/'original_title.bch').write_bytes(orig['fmd_title_JP_ja'][1])
for t in bch.textures:Image.fromarray(bch.decode(t)).save(OUT/(t.name+'_before.png'))
source=ROOT/'work/img/title_lower_shading_20261008'
for name in ['title_masks.npz','layout_metrics.json','screen_mapping.json','run_checked.py','preview_title.py']:
    shutil.copy2(source/name,OUT/('before_'+name if name in ['title_masks.npz','layout_metrics.json'] else name))
backup=OUT/'recipes_before';backup.mkdir()
for folder,name in [('title_layout_20261008','build_title.py'),('title_lower_shading_20261008','material.py')]:
    shutil.copy2(ROOT/f'work/img/{folder}/{name}',backup/name)
shutil.copy2(ROOT/'work/img/fmdl_geometry_patches.json',backup/'fmdl_geometry_patches.json')
refs=OUT/'ref';refs.mkdir()
ids=['c64fca69-3489-4465-a131-e04f2b3067f1','e478db05-cb29-4b8b-9f16-9d5cc0ed65fe','4af9ae68-a525-46c5-9f78-dad16f144083','9842df91-3ae2-4cf4-ae74-a81b8fa7e99c','076efc19-65c1-4d92-85bb-b5f08da1ffbe','0348db1d-dfa3-4f6d-a01a-bcad905d11ec']
for i,key in enumerate(ids,1):shutil.copy2(Path(f'C:/Users/woose/AppData/Local/Temp/codex-clipboard-{key}.png'),refs/f'user_{i}.png')
info={'before_fmdl_sha256':hashlib.sha256(raw).hexdigest(),'before_bch_sha256':hashlib.sha256(plain).hexdigest()}
(OUT/'before.json').write_text(json.dumps(info,indent=2)+'\n',encoding='utf8')
print(json.dumps(info,indent=2))
