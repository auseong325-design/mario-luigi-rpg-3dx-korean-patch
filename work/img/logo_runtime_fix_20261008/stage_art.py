from pathlib import Path
import json,sys
import numpy as np
from PIL import Image
ROOT=Path(__file__).resolve().parents[3];OUT=Path(__file__).parent
sys.path.insert(0,str(ROOT/'scripts'))
import libbch
old=libbch.Bch((OUT/'before_title.bch').read_bytes())
names=['title_logo_M_JP','title_logo_L_JP','title_logo_and_JP']
result={}
for name in names:
    before=old.decode(old.texture(name))
    after=np.asarray(Image.open(OUT/(name+'.png')).convert('RGBA'))
    Image.fromarray(before).save(OUT/('before_'+name+'.png'))
    if name.endswith('and_JP'):
        expected=np.empty_like(before);expected[:]=[0,34,68,0]
        expected[:-24]=before[24:]
        assert not before[:24,:,3].any(),'The shift would crop artwork'
        assert np.array_equal(expected,after),'Unexpected ampersand artwork change'
        result[name]={'pixel_translation_y':-24,'identical_artwork':True,'cropped_pixels':0}
    else:
        assert np.array_equal(before,after),'Word artwork must remain unchanged'
        result[name]={'unchanged':True}
    target=ROOT/'work/img/fmdl_ko/fmd_title_JP_ja'/(name+'.png')
    temp=target.with_suffix('.runtime_fix.tmp');temp.write_bytes((OUT/(name+'.png')).read_bytes());temp.replace(target)
    target=ROOT/'work/img/logo2/out'/(name+'.png')
    temp=target.with_suffix('.runtime_fix.tmp');temp.write_bytes((OUT/(name+'.png')).read_bytes());temp.replace(target)
(OUT/'art_verify.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf8')
print(json.dumps(result,indent=2))
