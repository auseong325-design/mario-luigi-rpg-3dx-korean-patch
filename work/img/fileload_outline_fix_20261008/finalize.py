from pathlib import Path
from datetime import datetime,timezone,timedelta
import json,hashlib,os,shutil,time,zipfile
from PIL import Image,ImageDraw,ImageFont
ROOT=Path(__file__).resolve().parents[3];OUT=Path(__file__).parent
REL=Path('Lyt/JP/MLyt.dat');PATCH=ROOT/'patch/00040000001CA900/romfs'
PACKAGE=ROOT/'work/sd_package';DISTRO=PACKAGE/'luma/titles/00040000001CA900/romfs'
BACKUP=ROOT/'work/build/prev_fileload_outline_fix_20261008'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
v=json.loads((OUT/'build_verify.json').read_text());before=json.loads((OUT/'before.json').read_text())
runtime=json.loads((OUT/'runtime_verify.json').read_text())
assert runtime['runtime_verified'] and v['only_ML_right_texture_changed']
assert sha(PATCH/REL)==v['after_sha256']
assert sha(PATCH/'FMdl/JP/FMdl.dat')==before['FMdl_sha256']
data=(OUT/'after_MLyt.dat').read_bytes();assert sha(OUT/'after_MLyt.dat')==v['after_sha256']
(BACKUP/REL.parent).mkdir(parents=True,exist_ok=True)
if not (BACKUP/REL).exists():shutil.copy2(OUT/'before_MLyt.dat',BACKUP/REL)
assert sha(BACKUP/REL)==v['before_sha256']
for name in before['texture_names']:
    target=BACKUP/'inputs'/(name+'.png');target.parent.mkdir(exist_ok=True)
    if not target.exists():shutil.copy2(OUT/('before_'+name+'.png'),target)
zpath=PACKAGE/'ml3dx_ko_luma.zip';prefix='luma/titles/00040000001CA900/romfs/'
arc=prefix+REL.as_posix();files=[p for p in PATCH.rglob('*') if p.is_file()]
with zipfile.ZipFile(zpath) as z:
    for path in files:
        rel=path.relative_to(PATCH)
        if rel==REL:
            assert sha(DISTRO/rel) in {v['before_sha256'],v['after_sha256']}
            assert hashlib.sha256(z.read(prefix+rel.as_posix())).hexdigest() in {v['before_sha256'],v['after_sha256']}
        else:assert z.read(prefix+rel.as_posix())==path.read_bytes()==(DISTRO/rel).read_bytes()
if not (BACKUP/zpath.name).exists():
    with zipfile.ZipFile(zpath) as z:assert hashlib.sha256(z.read(arc)).hexdigest()==v['before_sha256']
    shutil.copy2(zpath,BACKUP/zpath.name)
with zipfile.ZipFile(BACKUP/zpath.name) as z:assert hashlib.sha256(z.read(arc)).hexdigest()==v['before_sha256']
temp_zip=PACKAGE/'ml3dx_ko_luma.fileload_outline_fix_20261008.tmp.zip'
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
for target in [DISTRO/REL,ROOT/'work/build/lyt_stage/romfs'/REL]:
    target.parent.mkdir(parents=True,exist_ok=True)
    temp=target.with_name(target.name+'.fileload_outline_fix_20261008.tmp');temp.write_bytes(data)
    replace_retry(temp,target)
replace_retry(temp_zip,zpath)
junction=Path(os.environ['APPDATA'])/'Azahar/load/mods/00040000001CA900/romfs'
with zipfile.ZipFile(zpath) as z:
    for path in files:
        rel=path.relative_to(PATCH)
        assert sha(path)==sha(junction/rel)==sha(DISTRO/rel)
        assert z.read(prefix+rel.as_posix())==path.read_bytes()
    assert z.testzip() is None
font=ImageFont.truetype('C:/Windows/Fonts/malgun.ttf',18)
comparison=Image.new('RGB',(800,270),(25,25,25));draw=ImageDraw.Draw(comparison)
for i,(name,label) in enumerate([('runtime_before.png','갱신 전 · Azahar 실제 화면'),('runtime_after.png','갱신 후 · Azahar 실제 화면')]):
    im=Image.open(OUT/name);assert im.size==(400,480),im.size
    top=im.crop((0,0,400,240));comparison.paste(top,(i*400,30))
    draw.text((i*400+12,3),label,fill=(255,255,255),font=font)
    if i==1:top.save(OUT/'runtime_after_top.png')
comparison.save(OUT/'runtime_before_after.png')
result={'changed_patch_files':[REL.as_posix()],'changed_texture_copies':v['changed_texture_copies'],
        'all_patch_junction_sd_zip_files_match':True,'checked_patch_files':len(files),'zip_crc_check':'PASS',
        'MLyt_sha256':sha(PATCH/REL),'zip_sha256':sha(zpath),'FMdl_unchanged':True,
        'backup':str(BACKUP),'source_files_modified':False,'runtime_verified':True}
(OUT/'install.json').write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
print(json.dumps(result,ensure_ascii=False,indent=2))
