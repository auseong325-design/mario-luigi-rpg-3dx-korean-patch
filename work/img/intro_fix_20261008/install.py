"""Install the independently checked intro fix and refresh the SD distribution."""
from pathlib import Path
import hashlib,json,os,shutil,subprocess,zipfile
ROOT=Path(__file__).resolve().parents[3];OUT=Path(__file__).parent
REL=Path('FMdl/JP/FMdl.dat')
PATCH=ROOT/'patch/00040000001CA900/romfs'
STAGE=ROOT/'work/build/fmdl_stage/romfs'
PACKAGE=ROOT/'work/sd_package'
DISTRO=PACKAGE/'luma/titles/00040000001CA900/romfs'
BACKUP=ROOT/'work/build/prev_intro_fix_20261008'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
archive=json.loads((OUT/'archive_verify.json').read_text(encoding='utf8'))
geometry=json.loads((OUT/'geometry_verify.json').read_text(encoding='utf8'))
preview=json.loads((OUT/'preview_metrics.json').read_text(encoding='utf8'))
assert archive['only_four_coordinate_fields_changed'] and geometry['independent_spica_readback']
assert all(v==0 for v in preview['AFTER'].values())
assert sha(STAGE/REL)==archive['stage_sha256']
assert sha(PATCH/REL)==archive['before_fmdl_sha256']
proc=subprocess.run(['powershell','-NoProfile','-Command',
                     '@(Get-Process -Name azahar,citra -ErrorAction SilentlyContinue).Count'],
                    capture_output=True,check=True,timeout=15)
assert proc.stdout.decode().strip()=='0','Game is running'
zpath=PACKAGE/'ml3dx_ko_luma.zip'
arc='luma/titles/00040000001CA900/romfs/'+REL.as_posix()
with zipfile.ZipFile(zpath) as z:
    for p in PATCH.rglob('*'):
        if p.is_file():
            path=p.relative_to(PATCH)
            assert z.read('luma/titles/00040000001CA900/romfs/'+path.as_posix())==p.read_bytes()
            assert sha(DISTRO/path)==sha(p)
assert not BACKUP.exists(),'Backup already exists; preserve it and inspect before rerunning'
(BACKUP/REL.parent).mkdir(parents=True)
shutil.copy2(PATCH/REL,BACKUP/REL)
shutil.copy2(zpath,BACKUP/zpath.name)
temp=PACKAGE/'ml3dx_ko_luma.intro_20261008.tmp.zip'
with zipfile.ZipFile(zpath) as old,zipfile.ZipFile(temp,'w',compression=zipfile.ZIP_DEFLATED) as new:
    for info in old.infolist():new.writestr(info,(STAGE/REL).read_bytes() if info.filename==arc else old.read(info.filename))
with zipfile.ZipFile(temp) as z:
    assert z.testzip() is None
    assert z.read(arc)==(STAGE/REL).read_bytes()
shutil.copy2(STAGE/REL,PATCH/REL)
shutil.copy2(STAGE/REL,DISTRO/REL)
temp.replace(zpath)
junction=Path(os.environ['APPDATA'])/'Azahar/load/mods/00040000001CA900/romfs'
with zipfile.ZipFile(zpath) as z:
    for p in PATCH.rglob('*'):
        if p.is_file():
            path=p.relative_to(PATCH)
            assert sha(p)==sha(junction/path)==sha(DISTRO/path)
            assert z.read('luma/titles/00040000001CA900/romfs/'+path.as_posix())==p.read_bytes()
result={'changed_patch_files':[REL.as_posix()],'stage_patch_junction_match':True,
        'all_sd_and_zip_files_match':True,'zip_crc_check':'PASS','backup':str(BACKUP),
        'fmdl_sha256':sha(PATCH/REL),'zip_sha256':sha(zpath),'azahar_launched':False,'runtime_verified':False}
(OUT/'install.json').write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
print(json.dumps(result,ensure_ascii=False,indent=2))
