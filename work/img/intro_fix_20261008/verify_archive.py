from pathlib import Path
import hashlib,json,sys
ROOT=Path(__file__).resolve().parents[3]
OUT=Path(__file__).parent
sys.path.insert(0,str(ROOT/'scripts'))
import lib3dx,libbch
STAGE=ROOT/'work/build/fmdl_stage/romfs/FMdl/JP/FMdl.dat'
PATCH=ROOT/'patch/00040000001CA900/romfs/FMdl/JP/FMdl.dat'
sha=lambda b:hashlib.sha256(b).hexdigest()
_,old=lib3dx.read_bg4(PATCH.read_bytes())
_,new=lib3dx.read_bg4(STAGE.read_bytes())
assert len(old)==len(new)
plan=json.loads((ROOT/'work/img/fmdl_geometry_patches.json').read_text(encoding='utf8'))
changed=[]
for i,(a,b) in enumerate(zip(old,new)):
    assert a.name==b.name and a.size_flag==b.size_flag
    if a.data==b.data: continue
    before,after=lib3dx.bg4_plain(a),lib3dx.bg4_plain(b)
    if before==after:continue
    assert a.name=='fmd_title_JP_ja',f'unexpected model changed: {a.name}'
    expected=bytearray(before)
    for edit in plan['models'][a.name]['edits']:
        offset=edit['offset'];src=bytes.fromhex(edit['before']);dst=bytes.fromhex(edit['after'])
        assert expected[offset:offset+len(src)]==src
        expected[offset:offset+len(src)]=dst
    assert after==expected,'Unexpected changes beyond the four & coordinates'
    p=libbch.Bch(before);q=libbch.Bch(after)
    assert p.textures==q.textures
    for t in p.textures:assert before[t.offset:t.offset+t.size]==after[t.offset:t.offset+t.size]
    (OUT/'after_title.bch').write_bytes(after)
    changed.append({'slot':i,'name':a.name,'changed_bytes':sum(x!=y for x,y in zip(before,after)),
                    'bch_length':len(after),'before_sha256':sha(before),'after_sha256':sha(after)})
assert len(changed)==1
source=lib3dx.romfs_path('FMdl/JP/FMdl.dat')
_,original=lib3dx.read_bg4(source.read_bytes())
assert lib3dx.bg4_plain(original[changed[0]['slot']])==(OUT/'original_title.bch').read_bytes()
result={'changed_models':changed,'model_count':len(old),'only_four_coordinate_fields_changed':True,
        'all_texture_bytes_preserved':True,'all_other_model_and_animation_bytes_preserved':True,
        'original_v12_title_unchanged':True,'stage_sha256':sha(STAGE.read_bytes()),'before_fmdl_sha256':sha(PATCH.read_bytes())}
(OUT/'archive_verify.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf8')
print(json.dumps(result,indent=2))
