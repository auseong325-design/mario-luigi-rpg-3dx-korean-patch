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
assert len(old)==len(new)
changed=[]
names={'title_logo_JP_bottom','title_logo_JP_top','title_logo_and_JP'}
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
        assert t.name in names
        with Image.open(OUT/(t.name+'.png')) as image:
            assert np.array_equal(q.decode(q.texture(t.name)),np.array(image.convert('RGBA')))
        expected[t.offset:t.offset+t.size]=after[t.offset:t.offset+t.size]
        textures.append(t.name)
    assert set(textures)==names
    assert expected==after,'Geometry or animation changed'
    (OUT/'after_title.bch').write_bytes(after)
    changed.append({'model':a.name,'textures':textures})
assert len(changed)==1
# The DX/디럭스 image is compared separately from the half-pixel adjustment to numeral 3.
with Image.open(OUT/'title_logo_JP_top_before.png') as image:before_top=np.array(image.convert('RGBA'))
with Image.open(OUT/'title_logo_JP_top.png') as image:after_top=np.array(image.convert('RGBA'))
assert np.array_equal(before_top[:,:350],after_top[:,:350]),'DX/디럭스 changed'
layout=json.loads((OUT/'layout_metrics.json').read_text(encoding='utf8'))
assert layout['config']['silhouette_syllables']==['ri','o']
assert layout['center_difference_texture_px']<=1
assert json.loads((OUT/'preview_metrics.json').read_text(encoding='utf8'))['all_silhouettes_inside_screen']
result={'changed_models':changed,'only_three_title_textures_changed':True,
        'geometry_and_animation_bytes_equal':True,'dx_deluxe_pixels_preserved':True,
        'both_silhouettes_remain_over_mario':True,'decoded_pixels_match_inputs':True,
        'before_fmdl_sha256':sha(patch),'stage_sha256':sha(stage)}
(OUT/'build_verify.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf8')
print(json.dumps(result,indent=2))
