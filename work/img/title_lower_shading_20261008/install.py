from pathlib import Path
import hashlib,json,os,shutil,subprocess,zipfile
ROOT=Path(__file__).resolve().parents[3];OUT=Path(__file__).parent
REL=Path('FMdl/JP/FMdl.dat')
PATCH=ROOT/'patch/00040000001CA900/romfs'
STAGE=ROOT/'work/build/fmdl_stage/romfs'
PACKAGE=ROOT/'work/sd_package'
DISTRO=PACKAGE/'luma/titles/00040000001CA900/romfs'
BACKUP=ROOT/'work/build/prev_title_lower_shading_20261008'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
build=json.loads((OUT/'build_verify.json').read_text(encoding='utf8'))
art=json.loads((OUT/'art_verify.json').read_text(encoding='utf8'))
assert build['only_bottom_title_texture_changed'] and build['all_other_bch_bytes_equal']
assert build['decoded_pixels_match_input'] and build['intro_textures_coordinates_and_animation_equal']
assert art['only_ji_cap_mask_changed'] and art['ji_original_stem_preserved']
assert art['imported_1dx_underside_contour_exact'] and art['lower_body_follows_imported_contour']
assert art['all_other_glyph_masks_and_silhouettes_equal'] and art['dx_number_and_deluxe_pixels_equal']
assert sha(STAGE/REL)==build['stage_sha256'] and sha(PATCH/REL)==build['before_fmdl_sha256']
proc=subprocess.run(['powershell','-NoProfile','-Command',
                     '@(Get-Process -Name azahar,citra -ErrorAction SilentlyContinue).Count'],
                    capture_output=True,check=True,timeout=15)
assert proc.stdout.decode().strip()=='0','Game is running'
zpath=PACKAGE/'ml3dx_ko_luma.zip'
prefix='luma/titles/00040000001CA900/romfs/'
arc=prefix+REL.as_posix()
patch_files=[p for p in PATCH.rglob('*') if p.is_file()]
with zipfile.ZipFile(zpath) as z:
    for path in patch_files:
        rel=path.relative_to(PATCH)
        assert z.read(prefix+rel.as_posix())==path.read_bytes()
        assert sha(DISTRO/rel)==sha(path)
assert not (BACKUP/REL).exists() and not (BACKUP/zpath.name).exists(),'Preserve existing backups'
(BACKUP/REL.parent).mkdir(parents=True,exist_ok=True)
shutil.copy2(PATCH/REL,BACKUP/REL)
shutil.copy2(zpath,BACKUP/zpath.name)
data=(STAGE/REL).read_bytes()
temp_zip=PACKAGE/'ml3dx_ko_luma.lower_shading_20261008.tmp.zip'
assert not temp_zip.exists(),'Preserve existing temporary ZIP'
with zipfile.ZipFile(zpath) as old,zipfile.ZipFile(temp_zip,'w') as new:
    new.comment=old.comment
    for info in old.infolist():new.writestr(info,data if info.filename==arc else old.read(info.filename))
with zipfile.ZipFile(temp_zip) as z:
    assert z.testzip() is None and z.read(arc)==data
for target in [PATCH/REL,DISTRO/REL]:
    temp=target.with_name(target.name+'.lower_shading_20261008.tmp')
    assert not temp.exists()
    temp.write_bytes(data);temp.replace(target)
temp_zip.replace(zpath)
junction=Path(os.environ['APPDATA'])/'Azahar/load/mods/00040000001CA900/romfs'
with zipfile.ZipFile(zpath) as z:
    for path in patch_files:
        rel=path.relative_to(PATCH)
        assert sha(path)==sha(junction/rel)==sha(DISTRO/rel)
        assert z.read(prefix+rel.as_posix())==path.read_bytes()
    assert z.testzip() is None
result={'changed_patch_files':[REL.as_posix()],'changed_title_textures':['title_logo_JP_bottom'],
        'stage_patch_junction_match':sha(STAGE/REL)==sha(PATCH/REL),
        'all_sd_and_zip_files_match':True,'checked_patch_files':len(patch_files),'zip_crc_check':'PASS',
        'backup':str(BACKUP),'fmdl_sha256':sha(PATCH/REL),'zip_sha256':sha(zpath),
        'source_files_modified':False,'azahar_launched':False,'runtime_verified':False}
(OUT/'install.json').write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
print(json.dumps(result,ensure_ascii=False,indent=2))
