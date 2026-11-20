from pathlib import Path
import hashlib,json,sys
import numpy as np
from PIL import Image
ROOT=Path(__file__).resolve().parents[3];OUT=Path(__file__).parent
sys.path.insert(0,str(ROOT/'scripts'))
import lib3dx,libbch
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
stage=ROOT/'work/build/fmdl_stage/romfs/FMdl/JP/FMdl.dat'
patch=ROOT/'patch/00040000001CA900/romfs/FMdl/JP/FMdl.dat'
_,old=lib3dx.read_bg4(patch.read_bytes());_,new=lib3dx.read_bg4(stage.read_bytes())
assert sha(patch)==json.loads((OUT/'before.json').read_text())['before_fmdl_sha256']
assert len(old)==len(new)
changed=[]
for a,b in zip(old,new):
    assert a.name==b.name and a.size_flag==b.size_flag
    if a.data==b.data:continue
    before,after=lib3dx.bg4_plain(a),lib3dx.bg4_plain(b)
    if before==after:continue
    assert a.name=='fmd_title_JP_ja'
    assert before==(OUT/'before_title.bch').read_bytes()
    p=libbch.Bch(before);q=libbch.Bch(after)
    expected=bytearray(before);textures=[]
    for t in p.textures:
        if before[t.offset:t.offset+t.size]==after[t.offset:t.offset+t.size]:continue
        assert t.name=='title_logo_JP_bottom'
        with Image.open(OUT/(t.name+'.png')) as img:
            assert np.array_equal(q.decode(q.texture(t.name)),np.array(img.convert('RGBA')))
        expected[t.offset:t.offset+t.size]=after[t.offset:t.offset+t.size]
        textures.append(t.name)
    assert textures==['title_logo_JP_bottom']
    assert expected==after,'Changed geometry, animation or other BCH fields'
    (OUT/'after_title.bch').write_bytes(after)
    changed.append({'model':a.name,'textures':textures})
assert len(changed)==1
with Image.open(OUT/'title_logo_JP_bottom_before.png') as img:before_img=np.array(img.convert('RGBA'))
with Image.open(OUT/'title_logo_JP_bottom.png') as img:after_img=np.array(img.convert('RGBA'))
assert np.array_equal(before_img[:,333:],after_img[:,333:]),'Original RPG pixels beyond the seam changed'
result={'changed_models':changed,'only_bottom_title_texture_changed':True,
        'all_other_bch_bytes_equal':True,'decoded_pixels_match_input':True,
        'intro_textures_coordinates_and_animation_equal':True,'dx_deluxe_and_number_texture_equal':True,
        'rpg_original_pixels_after_seam_equal':True,
        'before_fmdl_sha256':sha(patch),'stage_sha256':sha(stage)}
(OUT/'build_verify.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf8')
print(json.dumps(result,indent=2))
