"""Package the runtime-verified logo and retain a recoverable previous release."""
from pathlib import Path
import hashlib,json,os,shutil,time,zipfile
from datetime import datetime,timezone,timedelta
from PIL import Image,ImageDraw,ImageFont
ROOT=Path(__file__).resolve().parents[3];OUT=Path(__file__).parent
REL=Path('FMdl/JP/FMdl.dat');PATCH=ROOT/'patch/00040000001CA900/romfs'
PACKAGE=ROOT/'work/sd_package';DISTRO=PACKAGE/'luma/titles/00040000001CA900/romfs'
BACKUP=ROOT/'work/build/prev_logo_runtime_fix_20261008'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
v=json.loads((OUT/'build_verify.json').read_text());data=(OUT/'after_fmdl.dat').read_bytes()
assert sha(PATCH/REL)==v['stage_sha256']
assert v['only_ampersand_texture_changed'] and v['geometry_and_animations_unchanged']
for name in ['runtime_before.png','runtime_after_assembly.png','runtime_after_title.png','runtime_sequence_06.png']:
    assert (OUT/name).is_file(),name
timestamp=datetime.now(timezone(timedelta(hours=9))).isoformat()
runtime={'timestamp':timestamp,'method':'Codex built-in computer-use @oai/sky in node_repl',
         'azahar_version':'2126.1.2','game_update':'v1.2 visible on title screen',
         'before_problem_reproduced':True,'after_assembly_alignment_verified':True,
         'held_assembly_and_attached_ampersand_verified':True,'original_separation_and_rotation_observed':True,
         'main_title_verified':True,'runtime_verified':True,'subagents_used':False,
         'orca_used_this_run':False,'native_input_scripts_used':False,
         'screenshots':['runtime_before.png','runtime_after_assembly.png','runtime_after_title.png'],
         'sequence':'runtime_sequence.json','fmdl_sha256':v['stage_sha256']}
(OUT/'runtime_verify.json').write_text(json.dumps(runtime,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
# Comparison uses actual Azahar screenshots, cropped to the 400x240 top screen.
font=ImageFont.truetype('C:/Windows/Fonts/malgun.ttf',18)
comparison=Image.new('RGB',(800,270),(25,25,25));draw=ImageDraw.Draw(comparison)
for index,(name,label) in enumerate([('runtime_before.png','수정 전 · Azahar 실제 화면'),
                                    ('runtime_after_assembly.png','수정 후 · Azahar 실제 화면')]):
    im=Image.open(OUT/name);assert im.size==(400,480)
    top=im.crop((0,0,400,240));comparison.paste(top,(index*400,30))
    draw.text((index*400+12,3),label,fill=(255,255,255),font=font)
    if index==1:top.save(OUT/'runtime_after_assembly_top.png')
comparison.save(OUT/'runtime_before_after.png')
Image.open(OUT/'runtime_after_title.png').crop((0,0,400,240)).save(OUT/'runtime_after_title_top.png')
# Backups include the previous release, plus the old inputs for the affected texture.
(BACKUP/REL.parent).mkdir(parents=True,exist_ok=True)
if not (BACKUP/REL).exists():shutil.copy2(OUT/'before_fmdl.dat',BACKUP/REL)
assert sha(BACKUP/REL)==v['before_fmdl_sha256']
for name in ['title_logo_M_JP','title_logo_L_JP','title_logo_and_JP']:
    target=BACKUP/'inputs'/(name+'.png');target.parent.mkdir(exist_ok=True)
    if not target.exists():shutil.copy2(OUT/('before_'+name+'.png'),target)
zpath=PACKAGE/'ml3dx_ko_luma.zip';prefix='luma/titles/00040000001CA900/romfs/'
arc=prefix+REL.as_posix();files=[p for p in PATCH.rglob('*') if p.is_file()]
with zipfile.ZipFile(zpath) as z:
    for path in files:
        rel=path.relative_to(PATCH)
        if rel==REL:
            assert sha(DISTRO/rel) in {v['before_fmdl_sha256'],v['stage_sha256']}
            assert hashlib.sha256(z.read(prefix+rel.as_posix())).hexdigest() in {v['before_fmdl_sha256'],v['stage_sha256']}
        else:
            assert z.read(prefix+rel.as_posix())==path.read_bytes()==(DISTRO/rel).read_bytes()
if not (BACKUP/zpath.name).exists():
    with zipfile.ZipFile(zpath) as z:assert hashlib.sha256(z.read(arc)).hexdigest()==v['before_fmdl_sha256']
    shutil.copy2(zpath,BACKUP/zpath.name)
with zipfile.ZipFile(BACKUP/zpath.name) as z:assert hashlib.sha256(z.read(arc)).hexdigest()==v['before_fmdl_sha256']
temp_zip=PACKAGE/'ml3dx_ko_luma.runtime_fix_20261008.tmp.zip'
with zipfile.ZipFile(zpath) as old,zipfile.ZipFile(temp_zip,'w') as new:
    new.comment=old.comment
    for info in old.infolist():new.writestr(info,data if info.filename==arc else old.read(info.filename))
with zipfile.ZipFile(temp_zip) as z:assert z.testzip() is None and z.read(arc)==data
def replace_retry(temp,target):
    assert temp.parent.resolve()==target.parent.resolve()
    for attempt in range(10):
        try:temp.replace(target);return
        except OSError:
            if attempt==9:raise
            time.sleep(.5)
for target in [DISTRO/REL,ROOT/'work/build/fmdl_stage/romfs'/REL]:
    temp=target.with_name(target.name+'.runtime_fix_20261008.tmp');temp.write_bytes(data)
    replace_retry(temp,target)
replace_retry(temp_zip,zpath)
junction=Path(os.environ['APPDATA'])/'Azahar/load/mods/00040000001CA900/romfs'
with zipfile.ZipFile(zpath) as z:
    for path in files:
        rel=path.relative_to(PATCH)
        assert sha(path)==sha(junction/rel)==sha(DISTRO/rel)
        assert z.read(prefix+rel.as_posix())==path.read_bytes()
    assert z.testzip() is None
result={'changed_patch_files':[REL.as_posix()],'changed_title_textures':['title_logo_and_JP'],
        'stage_patch_junction_match':True,'all_sd_and_zip_files_match':True,
        'default_stage_matches_installed':True,'checked_patch_files':len(files),'zip_crc_check':'PASS',
        'backup':str(BACKUP),'fmdl_sha256':sha(PATCH/REL),'zip_sha256':sha(zpath),
        'source_files_modified':False,'azahar_launched':True,'runtime_verified':True}
(OUT/'install.json').write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
print(json.dumps(result,ensure_ascii=False,indent=2))
