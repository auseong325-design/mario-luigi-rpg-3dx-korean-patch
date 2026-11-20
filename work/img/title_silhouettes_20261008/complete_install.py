"""Finish synchronization after CopyFile2 was blocked by a mapped SD preview."""
from pathlib import Path
import hashlib,json,os,subprocess,zipfile
ROOT=Path(__file__).resolve().parents[3];OUT=Path(__file__).parent
REL=Path('FMdl/JP/FMdl.dat')
PATCH=ROOT/'patch/00040000001CA900/romfs'
STAGE=ROOT/'work/build/fmdl_stage/romfs'
PACKAGE=ROOT/'work/sd_package'
DISTRO=PACKAGE/'luma/titles/00040000001CA900/romfs'
BACKUP=ROOT/'work/build/prev_title_silhouettes_20261008'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
build=json.loads((OUT/'build_verify.json').read_text(encoding='utf8'))
assert sha(STAGE/REL)==sha(PATCH/REL)==build['stage_sha256']
assert sha(BACKUP/REL)==build['before_fmdl_sha256']
assert sha(DISTRO/REL) in [build['before_fmdl_sha256'],build['stage_sha256']]
proc=subprocess.run(['powershell','-NoProfile','-Command',
                     '@(Get-Process -Name azahar,citra -ErrorAction SilentlyContinue).Count'],
                    capture_output=True,check=True,timeout=15)
assert proc.stdout.decode().strip()=='0'
zpath=PACKAGE/'ml3dx_ko_luma.zip'
assert sha(zpath)==sha(BACKUP/zpath.name)
temp=PACKAGE/'ml3dx_ko_luma.title_silhouettes_20261008.tmp.zip'
arc='luma/titles/00040000001CA900/romfs/'+REL.as_posix()
with zipfile.ZipFile(temp) as z:
    assert z.testzip() is None and z.read(arc)==(STAGE/REL).read_bytes()
destination=DISTRO/REL
atomic=destination.with_suffix('.silhouettes.tmp')
atomic.write_bytes((STAGE/REL).read_bytes());atomic.replace(destination)
temp.replace(zpath)
junction=Path(os.environ['APPDATA'])/'Azahar/load/mods/00040000001CA900/romfs'
with zipfile.ZipFile(zpath) as z:
    for p in PATCH.rglob('*'):
        if p.is_file():
            rel=p.relative_to(PATCH)
            assert sha(p)==sha(junction/rel)==sha(DISTRO/rel)
            assert z.read('luma/titles/00040000001CA900/romfs/'+rel.as_posix())==p.read_bytes()
result={'changed_patch_files':[REL.as_posix()],'stage_patch_junction_match':True,
        'all_sd_and_zip_files_match':True,'zip_crc_check':'PASS','backup':str(BACKUP),
        'fmdl_sha256':sha(PATCH/REL),'zip_sha256':sha(zpath),'azahar_launched':False,'runtime_verified':False}
(OUT/'install.json').write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
print(json.dumps(result,ensure_ascii=False,indent=2))
