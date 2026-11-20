from pathlib import Path
import hashlib,json,sys,shutil
import numpy as np
from PIL import Image
ROOT=Path(__file__).resolve().parents[3];OUT=Path(__file__).parent
sys.path.insert(0,str(ROOT/'scripts'))
import build_fmdl
_,models=build_fmdl.load(ROOT/'patch/00040000001CA900/romfs/FMdl/JP/FMdl.dat')
_,plain,bch=models['fmd_title_JP_ja']
assert not (OUT/'before_title.bch').exists(),'Preserve existing baseline'
(OUT/'before_title.bch').write_bytes(plain)
for name in ['title_logo_JP_bottom','title_logo_JP_top','title_logo_and_JP']:
    Image.fromarray(bch.decode(bch.texture(name))).save(OUT/(name+'_before.png'))
SOURCE=ROOT/'work/img/title_layout_20261008'
for name in ['layout_metrics.json','title_masks.npz','screen_mapping.json']:
    shutil.copy2(SOURCE/name,OUT/('before_'+name if name!='screen_mapping.json' else name))
sys.path.insert(0,str(ROOT/'work/img/logo2'))
import l2,seg_1dx
masks,info=seg_1dx.syllables(fix_stem=False)
np.savez_compressed(OUT/'donor_1dx_raw.npz',**masks)
rows={}
for name,mask in masks.items():
    yy,xx=np.nonzero(mask>.5)
    rows[name]={'box':[int(xx.min()),int(yy.min()),int(xx.max()+1),int(yy.max()+1)]}
meta={'donor':'work/img/logo/src/1DX/kr_logo_rgba.png','sha256':hashlib.sha256(l2.KR1DX.read_bytes()).hexdigest(),
      'raw_masks_no_stem_redesign':True,'components':info,'glyphs':rows}
(OUT/'donor.json').write_text(json.dumps(meta,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
print(json.dumps(rows,indent=2))
