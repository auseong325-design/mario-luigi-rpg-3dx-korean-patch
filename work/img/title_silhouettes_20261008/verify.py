from pathlib import Path
import hashlib,json,sys
import numpy as np
from PIL import Image
ROOT=Path(__file__).resolve().parents[3];OUT=Path(__file__).parent
sys.path.insert(0,str(ROOT/'scripts'))
import lib3dx,libbch
stage=ROOT/'work/build/fmdl_stage/romfs/FMdl/JP/FMdl.dat'
patch=ROOT/'patch/00040000001CA900/romfs/FMdl/JP/FMdl.dat'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
_,old=lib3dx.read_bg4(patch.read_bytes());_,new=lib3dx.read_bg4(stage.read_bytes())
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
    texture=p.texture('title_logo_JP_bottom')
    expected=bytearray(before)
    expected[texture.offset:texture.offset+texture.size]=after[texture.offset:texture.offset+texture.size]
    assert expected==after,'Changes outside the bottom title texture'
    pixels=q.decode(q.texture(texture.name))
    with Image.open(OUT/(texture.name+'.png')) as image:assert np.array_equal(pixels,np.array(image.convert('RGBA')))
    previous=p.decode(texture)
    pixel_diff=np.any(pixels!=previous,axis=2)
    # Only the old/new Luigi figure and their surrounding outlines/glow may differ.
    allowed=np.zeros(pixel_diff.shape,bool)
    allowed[24:116,105:180]=True;allowed[30:116,213:288]=True
    assert not np.any(pixel_diff&~allowed),'Pixels changed outside Luigi silhouette regions'
    (OUT/'after_title.bch').write_bytes(after)
    changed.append(a.name)
assert changed==['fmd_title_JP_ja']
before_metrics=json.loads((OUT/'before_layout_metrics.json').read_text(encoding='utf8'))
after_metrics=json.loads((OUT/'layout_metrics.json').read_text(encoding='utf8'))
assert after_metrics['config']['silhouette_syllables']==['ri','o']
assert before_metrics['silhouette_moves'][0]==after_metrics['silhouette_moves'][0]
for key in ['glyph_scale','x_left','title_down','dx_center']:assert before_metrics['config'][key]==after_metrics['config'][key]
assert after_metrics['center_difference_texture_px']==before_metrics['center_difference_texture_px']
preview=json.loads((OUT/'preview_metrics.json').read_text(encoding='utf8'))
assert preview['all_silhouettes_inside_screen']
result={'only_bottom_title_texture_changed':True,'pixel_changes_limited_to_luigi_regions':True,
        'all_other_bch_bytes_equal':True,'mario_position_and_title_dx_layout_preserved':True,
        'decoded_pixels_match_input':True,'before_fmdl_sha256':sha(patch),'stage_sha256':sha(stage)}
(OUT/'build_verify.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf8')
print(json.dumps(result,indent=2))
