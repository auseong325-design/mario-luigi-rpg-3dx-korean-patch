from pathlib import Path
import hashlib,json,sys
import numpy as np
from PIL import Image
ROOT=Path(__file__).resolve().parents[3];OUT=Path(__file__).parent
sys.path.insert(0,str(ROOT/'scripts'))
import lib3dx,libbch
sha=lambda b:hashlib.sha256(b).hexdigest()
stage=ROOT/'work/build/fmdl_stage/romfs/FMdl/JP/FMdl.dat'
patch=ROOT/'patch/00040000001CA900/romfs/FMdl/JP/FMdl.dat'
_,old=lib3dx.read_bg4(patch.read_bytes());_,new=lib3dx.read_bg4(stage.read_bytes())
assert len(old)==len(new)
changed=[]
for i,(a,b) in enumerate(zip(old,new)):
    assert a.name==b.name and a.size_flag==b.size_flag
    if a.data==b.data:continue
    before,after=lib3dx.bg4_plain(a),lib3dx.bg4_plain(b)
    if before==after:continue
    assert a.name=='fmd_title_JP_ja',f'Unexpected changed model: {a.name}'
    p=libbch.Bch(before);q=libbch.Bch(after)
    expected=bytearray(before)
    textures=[]
    for t in p.textures:
        if before[t.offset:t.offset+t.size]==after[t.offset:t.offset+t.size]:continue
        assert t.name in ['title_logo_JP_bottom','title_logo_JP_top']
        image=np.asarray(Image.open(OUT/(t.name+'.png')).convert('RGBA'))
        assert np.array_equal(q.decode(q.texture(t.name)),image)
        expected[t.offset:t.offset+t.size]=after[t.offset:t.offset+t.size]
        textures.append(t.name)
    assert set(textures)=={'title_logo_JP_bottom','title_logo_JP_top'}
    assert after==expected,'Geometry, animations, or other textures changed'
    assert before==(OUT/'before_title.bch').read_bytes()
    (OUT/'after_title.bch').write_bytes(after)
    changed.append({'slot':i,'name':a.name,'changed_textures':textures,'bch_size':len(after)})
assert len(changed)==1
geometry=json.loads((ROOT/'work/img/fmdl_geometry_patches.json').read_text(encoding='utf8'))
bch=libbch.Bch((OUT/'after_title.bch').read_bytes())
for edit in geometry['models']['fmd_title_JP_ja']['edits']:
    offset=edit['offset'];want=bytes.fromhex(edit['after'])
    assert bch.data[offset:offset+len(want)]==want
metrics=json.loads((OUT/'layout_metrics.json').read_text(encoding='utf8'))
assert metrics['new_glyph_scale_x']==metrics['new_glyph_scale_y']
images={name:np.asarray(Image.open(OUT/(name+'.png')).convert('RGBA')) for name in ['title_logo_JP_bottom','title_logo_JP_top']}
assert all(not np.any(a[[0,-1],:,3]>64) and not np.any(a[:,[0,-1],3]>64) for a in images.values()),'Visible texture body meets canvas boundary'
print('Only the two main title textures changed; geometry, animations, intro pieces and & fix identical.')
result={'changed_models':changed,'only_two_title_textures_changed':True,'all_other_bch_bytes_identical':True,
        'intro_textures_and_coordinates_preserved':True,'all_textures_decoded_equal_to_inputs':True,
        'equal_x_y_glyph_scale':True,'no_alpha64_body_clipping_at_texture_edges':True,
        'before_fmdl_sha256':sha(patch.read_bytes()),'stage_sha256':sha(stage.read_bytes())}
(OUT/'build_verify.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf8')
print(json.dumps(result,indent=2))
