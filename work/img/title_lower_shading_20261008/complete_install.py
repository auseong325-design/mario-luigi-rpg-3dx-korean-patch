"""Resume the already-verified install without replacing any original backup."""
from pathlib import Path
import hashlib,json,os,time,zipfile
ROOT=Path(__file__).resolve().parents[3];OUT=Path(__file__).parent
REL=Path('FMdl/JP/FMdl.dat')
PATCH=ROOT/'patch/00040000001CA900/romfs'
STAGE=ROOT/'work/build/fmdl_stage/romfs'
PACKAGE=ROOT/'work/sd_package'
DISTRO=PACKAGE/'luma/titles/00040000001CA900/romfs'
BACKUP=ROOT/'work/build/prev_title_lower_shading_20261008'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
build=json.loads((OUT/'build_verify.json').read_text(encoding='utf8'))
assert sha(PATCH/REL)==sha(STAGE/REL)==build['stage_sha256']
assert sha(BACKUP/REL)==build['before_fmdl_sha256']
zpath=PACKAGE/'ml3dx_ko_luma.zip'
temp_zip=PACKAGE/'ml3dx_ko_luma.lower_shading_20261008.tmp.zip'
prefix='luma/titles/00040000001CA900/romfs/'
arc=prefix+REL.as_posix()
assert sha(zpath)==sha(BACKUP/zpath.name)
with zipfile.ZipFile(temp_zip) as z:
    assert z.testzip() is None and z.read(arc)==(STAGE/REL).read_bytes()
target=DISTRO/REL
temp=target.with_name(target.name+'.lower_shading_20261008.tmp')
assert sha(target)==build['before_fmdl_sha256'] and sha(temp)==build['stage_sha256']
method='same-directory atomic replacement after retry'
for attempt in range(5):
    try:
        temp.replace(target)
        break
    except PermissionError:
        if attempt<4:time.sleep(1)
else:
    # Some Windows readers allow writing but omit FILE_SHARE_DELETE. Resize before
    # writing: if the file is mapped and cannot grow, no existing bytes are touched.
    data=temp.read_bytes()
    with target.open('r+b') as f:
        os.ftruncate(f.fileno(),len(data))
        f.seek(0)
        assert f.write(data)==len(data)
        f.flush();os.fsync(f.fileno())
    assert sha(target)==build['stage_sha256']
    temp.unlink()
    method='verified in-place copy after resize; atomic replacement blocked by Windows reader'
assert sha(target)==build['stage_sha256']
temp_zip.replace(zpath)
junction=Path(os.environ['APPDATA'])/'Azahar/load/mods/00040000001CA900/romfs'
files=[p for p in PATCH.rglob('*') if p.is_file()]
with zipfile.ZipFile(zpath) as z:
    assert z.testzip() is None
    for path in files:
        rel=path.relative_to(PATCH)
        assert sha(path)==sha(junction/rel)==sha(DISTRO/rel)
        assert z.read(prefix+rel.as_posix())==path.read_bytes()
result={'changed_patch_files':[REL.as_posix()],'changed_title_textures':['title_logo_JP_bottom'],
        'stage_patch_junction_match':True,'all_sd_and_zip_files_match':True,
        'checked_patch_files':len(files),'zip_crc_check':'PASS','sd_install_method':method,
        'backup':str(BACKUP),'fmdl_sha256':sha(PATCH/REL),'zip_sha256':sha(zpath),
        'source_files_modified':False,'azahar_launched':False,'runtime_verified':False}
(OUT/'install.json').write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
print(json.dumps(result,ensure_ascii=False,indent=2))
