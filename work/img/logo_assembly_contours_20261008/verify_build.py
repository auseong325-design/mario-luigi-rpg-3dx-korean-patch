from pathlib import Path
import hashlib,json,sys,subprocess
import numpy as np
from PIL import Image
ROOT=Path(__file__).resolve().parents[3];OUT=Path(__file__).parent
sys.path.insert(0,str(ROOT/'scripts'))
import lib3dx,libbch
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
stage=OUT/'after_fmdl.dat'
patch=ROOT/'patch/00040000001CA900/romfs/FMdl/JP/FMdl.dat'
baseline=json.loads((OUT/'before.json').read_text())
assert sha(patch)==baseline['before_fmdl_sha256']
_,old=lib3dx.read_bg4((OUT/'before_fmdl.dat').read_bytes());_,new=lib3dx.read_bg4(stage.read_bytes())
assert len(old)==len(new)
changes=[];names={'title_logo_JP_bottom','title_logo_M_JP','title_logo_L_JP','title_logo_and_JP'}
original=(OUT/'original_title.bch').read_bytes()
old_plan=json.loads((OUT/'recipes_before/fmdl_geometry_patches.json').read_text())
for a,b in zip(old,new):
    assert a.name==b.name and a.size_flag==b.size_flag
    if a.data==b.data:continue
    before,after=lib3dx.bg4_plain(a),lib3dx.bg4_plain(b)
    if before==after:continue
    assert a.name=='fmd_title_JP_ja','Unexpected changed model: '+a.name
    assert before==(OUT/'before_title.bch').read_bytes()
    p=libbch.Bch(before);q=libbch.Bch(after);expected=bytearray(before);textures=[]
    for t in p.textures:
        if before[t.offset:t.offset+t.size]==after[t.offset:t.offset+t.size]:continue
        assert t.name in names
        with Image.open(OUT/(t.name+'.png')) as im:img=np.array(im.convert('RGBA'))
        assert np.array_equal(q.decode(q.texture(t.name)),img)
        expected[t.offset:t.offset+t.size]=after[t.offset:t.offset+t.size]
        textures.append(t.name)
    assert set(textures)==names
    for edit in old_plan['models']['fmd_title_JP_ja']['edits']:
        at=edit['offset'];assert before[at:at+4]==bytes.fromhex(edit['after'])
        assert after[at:at+4]==original[at:at+4]==bytes.fromhex(edit['before'])
        expected[at:at+4]=original[at:at+4]
    assert bytes(expected)==after,'Changed bones, animation or other BCH bytes'
    assert after[q.cmds:q.cmds+q.cmd_len]==original[q.cmds:q.cmds+q.cmd_len]
    (OUT/'after_title.bch').write_bytes(after)
    changes.append({'model':a.name,'textures':textures})
assert len(changes)==1
# Independent SPICA parser confirms original mesh commands and unchanged animation structure.
proc=subprocess.run(['powershell','-NoProfile','-File',str(ROOT/'work/img/intro_fix_20261008/inspect_title.ps1'),
                    '-InputBch',str(OUT/'after_title.bch'),'-OutputJson',str(OUT/'after_geometry.json')],
                   capture_output=True,check=True,timeout=40,cwd=ROOT)
(OUT/'spica_after.log').write_bytes(proc.stdout+proc.stderr)
read=lambda name:json.loads((OUT/name).read_text(encoding='utf-8-sig'))
got=read('after_geometry.json');orig=read('original_geometry.json');prior=read('before_geometry.json')
assert got==orig,'SPICA original model or animation differs'
for key in ['skeletal_animations','visibility_animations']:assert got[key]==prior[key]
result={'changed_models':changes,'decoded_pixels_match_input':True,
        'only_four_textures_and_four_restored_coordinates_changed':True,
        'original_command_section_restored':True,'all_other_bch_bytes_equal':True,
        'independent_spica_original_geometry_match':True,'skeletal_and_visibility_animations_equal':True,
        'dx_deluxe_number_texture_equal':True,'before_fmdl_sha256':baseline['before_fmdl_sha256'],
        'stage_sha256':sha(stage),'runtime_verified':False}
(OUT/'build_verify.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf8')
print(json.dumps(result,indent=2))
