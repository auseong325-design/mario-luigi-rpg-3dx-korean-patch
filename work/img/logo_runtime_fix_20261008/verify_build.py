from pathlib import Path
import hashlib,json,sys
import numpy as np
from PIL import Image
ROOT=Path(__file__).resolve().parents[3];OUT=Path(__file__).parent
sys.path.insert(0,str(ROOT/'scripts'))
import lib3dx,libbch
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
stage=OUT/'after_fmdl.dat'
_,old=lib3dx.read_bg4((OUT/'before_fmdl.dat').read_bytes())
_,new=lib3dx.read_bg4(stage.read_bytes())
assert len(old)==len(new)
changes=[]
for a,b in zip(old,new):
    assert a.name==b.name and a.size_flag==b.size_flag
    if a.data==b.data:continue
    before,after=lib3dx.bg4_plain(a),lib3dx.bg4_plain(b)
    assert a.name=='fmd_title_JP_ja','Unexpected changed model: '+a.name
    assert before==(OUT/'before_title.bch').read_bytes()
    p=libbch.Bch(before);q=libbch.Bch(after);expected=bytearray(before);textures=[]
    for t in p.textures:
        if before[t.offset:t.offset+t.size]==after[t.offset:t.offset+t.size]:continue
        assert t.name=='title_logo_and_JP','Unexpected changed texture: '+t.name
        img=np.array(Image.open(OUT/(t.name+'.png')).convert('RGBA'))
        assert np.array_equal(q.decode(q.texture(t.name)),img)
        expected[t.offset:t.offset+t.size]=after[t.offset:t.offset+t.size]
        textures.append(t.name)
    assert textures==['title_logo_and_JP']
    assert bytes(expected)==after,'Changed geometry, bones, animation or other BCH bytes'
    (OUT/'after_title.bch').write_bytes(after)
    changes.append({'model':a.name,'textures':textures})
assert len(changes)==1
result={'changed_models':changes,'only_ampersand_texture_changed':True,
        'decoded_pixels_match_input':True,'all_other_bch_bytes_equal':True,
        'all_other_models_equal':True,'geometry_and_animations_unchanged':True,
        'main_title_textures_unchanged':True,'mario_and_luigi_textures_unchanged':True,
        'before_fmdl_sha256':sha(OUT/'before_fmdl.dat'),'stage_sha256':sha(stage)}
(OUT/'build_verify.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf8')
print(json.dumps(result,indent=2))
