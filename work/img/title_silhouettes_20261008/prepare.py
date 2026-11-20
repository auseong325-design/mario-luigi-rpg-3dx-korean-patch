from pathlib import Path
import json,sys,shutil
import numpy as np
from PIL import Image
ROOT=Path(__file__).resolve().parents[3];OUT=Path(__file__).parent
sys.path.insert(0,str(ROOT/'scripts'))
import build_fmdl
patch=ROOT/'patch/00040000001CA900/romfs/FMdl/JP/FMdl.dat'
_,models=build_fmdl.load(patch)
_,plain,bch=models['fmd_title_JP_ja']
assert not (OUT/'before_title.bch').exists(),'Preserve existing baseline'
(OUT/'before_title.bch').write_bytes(plain)
for name in ['title_logo_JP_bottom','title_logo_JP_top']:
    pixels=bch.decode(bch.texture(name))
    with Image.open(ROOT/f'work/img/fmdl_ko/fmd_title_JP_ja/{name}.png') as image:
        assert np.array_equal(pixels,np.array(image.convert('RGBA')))
    Image.fromarray(pixels).save(OUT/(name+'_before.png'))
shutil.copy2(ROOT/'work/img/title_layout_20261008/layout_metrics.json',OUT/'before_layout_metrics.json')
print('Saved installed title baseline for silhouette-only comparison')
