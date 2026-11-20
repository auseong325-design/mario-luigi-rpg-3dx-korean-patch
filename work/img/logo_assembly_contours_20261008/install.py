from pathlib import Path
import hashlib,json,os,shutil,subprocess,time,zipfile
ROOT=Path(__file__).resolve().parents[3];OUT=Path(__file__).parent
REL=Path('FMdl/JP/FMdl.dat')
PATCH=ROOT/'patch/00040000001CA900/romfs'
STAGE=OUT/'after_fmdl.dat'
PACKAGE=ROOT/'work/sd_package'
DISTRO=PACKAGE/'luma/titles/00040000001CA900/romfs'
BACKUP=ROOT/'work/build/prev_logo_assembly_contours_20261008'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
build=json.loads((OUT/'build_verify.json').read_text())
art=json.loads((OUT/'art_verify.json').read_text())
assert build['only_four_textures_and_four_restored_coordinates_changed']
assert build['original_command_section_restored'] and build['all_other_bch_bytes_equal']
assert build['independent_spica_original_geometry_match'] and build['decoded_pixels_match_input']
assert art['approved_ru_ji_lower_contours_restored'] and art['intro_common_scale_and_baseline']
assert sha(STAGE)==build['stage_sha256']
proc=subprocess.run(['powershell','-NoProfile','-Command',
                     '@(Get-Process -Name azahar,citra -ErrorAction SilentlyContinue).Count'],
                    capture_output=True,check=True,timeout=15)
assert proc.stdout.decode().strip()=='0','Game is running; preserve its open files'
zpath=PACKAGE/'ml3dx_ko_luma.zip';prefix='luma/titles/00040000001CA900/romfs/'
arc=prefix+REL.as_posix();data=STAGE.read_bytes()
patch_files=[p for p in PATCH.rglob('*') if p.is_file()]
with zipfile.ZipFile(zpath) as z:
    for path in patch_files:
        rel=path.relative_to(PATCH)
        if rel==REL:
            for payload in [path.read_bytes(),(DISTRO/rel).read_bytes(),z.read(prefix+rel.as_posix())]:
                assert hashlib.sha256(payload).hexdigest() in {build['before_fmdl_sha256'],build['stage_sha256']}
        else:
            assert z.read(prefix+rel.as_posix())==path.read_bytes()
            assert sha(DISTRO/rel)==sha(path)
(BACKUP/REL.parent).mkdir(parents=True,exist_ok=True)
if not (BACKUP/REL).exists():
    assert sha(PATCH/REL)==build['before_fmdl_sha256']
    shutil.copy2(PATCH/REL,BACKUP/REL)
assert sha(BACKUP/REL)==build['before_fmdl_sha256']
if not (BACKUP/zpath.name).exists():
    with zipfile.ZipFile(zpath) as z:
        assert hashlib.sha256(z.read(arc)).hexdigest()==build['before_fmdl_sha256']
    shutil.copy2(zpath,BACKUP/zpath.name)
with zipfile.ZipFile(BACKUP/zpath.name) as z:
    assert hashlib.sha256(z.read(arc)).hexdigest()==build['before_fmdl_sha256']
transaction={'before_fmdl_sha256':build['before_fmdl_sha256'],'new_fmdl_sha256':build['stage_sha256'],
             'backup':str(BACKUP),'state':'installing'}
(OUT/'install_transaction.json').write_text(json.dumps(transaction,indent=2)+'\n',encoding='utf8')
temp_zip=PACKAGE/'ml3dx_ko_luma.assembly_contours_20261008.tmp.zip'
if not temp_zip.exists():
    with zipfile.ZipFile(zpath) as old,zipfile.ZipFile(temp_zip,'w') as new:
        new.comment=old.comment
        for info in old.infolist():new.writestr(info,data if info.filename==arc else old.read(info.filename))
with zipfile.ZipFile(temp_zip) as z:
    assert z.testzip() is None and z.read(arc)==data
def replace_retry(temp,target):
    assert temp.parent.resolve()==target.parent.resolve()
    for attempt in range(15):
        try:temp.replace(target);return
        except OSError:
            if attempt==14:raise
            time.sleep(1)
for target in [PATCH/REL,DISTRO/REL]:
    if target.read_bytes()==data:continue
    temp=target.with_name(target.name+'.assembly_contours_20261008.tmp')
    if temp.exists():assert temp.read_bytes()==data
    else:temp.write_bytes(data)
    replace_retry(temp,target)
replace_retry(temp_zip,zpath)
junction=Path(os.environ['APPDATA'])/'Azahar/load/mods/00040000001CA900/romfs'
with zipfile.ZipFile(zpath) as z:
    for path in patch_files:
        rel=path.relative_to(PATCH)
        assert sha(path)==sha(junction/rel)==sha(DISTRO/rel)
        assert z.read(prefix+rel.as_posix())==path.read_bytes()
    assert z.testzip() is None
result={'changed_patch_files':[REL.as_posix()],
        'changed_title_textures':build['changed_models'][0]['textures'],
        'original_intro_coordinates_restored':True,'animation_data_unchanged':True,
        'stage_patch_junction_match':sha(STAGE)==sha(PATCH/REL),
        'all_sd_and_zip_files_match':True,'checked_patch_files':len(patch_files),'zip_crc_check':'PASS',
        'backup':str(BACKUP),'fmdl_sha256':sha(PATCH/REL),'zip_sha256':sha(zpath),
        'source_files_modified':False,'azahar_launched':False,'runtime_verified':False}
(OUT/'install.json').write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
transaction['state']='complete'
(OUT/'install_transaction.json').write_text(json.dumps(transaction,indent=2)+'\n',encoding='utf8')
print(json.dumps(result,ensure_ascii=False,indent=2))
