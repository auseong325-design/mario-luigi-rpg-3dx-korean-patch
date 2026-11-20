from pathlib import Path
import json,hashlib,os,time
ROOT=Path(__file__).resolve().parents[3];OUT=Path(__file__).parent
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
v=json.loads((OUT/'build_verify.json').read_text());before=json.loads((OUT/'before.json').read_text())
assert v['only_two_ML_textures_changed']
source=OUT/'after_MLyt.dat';assert sha(source)==v['after_sha256']
target=ROOT/'patch/00040000001CA900/romfs/Lyt/JP/MLyt.dat'
assert sha(target)==v['before_sha256']
temp=target.with_name(target.name+'.fileload_trial.tmp');temp.write_bytes(source.read_bytes())
for attempt in range(10):
    try:temp.replace(target);break
    except OSError:
        if attempt==9:raise
        time.sleep(.5)
junction=Path(os.environ['APPDATA'])/'Azahar/load/mods/00040000001CA900/romfs/Lyt/JP/MLyt.dat'
assert sha(junction)==sha(target)==v['after_sha256']
assert sha(ROOT/'patch/00040000001CA900/romfs/FMdl/JP/FMdl.dat')==before['FMdl_sha256']
result={'trial_installed':True,'emulation_stopped_with_codex_computer_use':True,
        'patch_and_junction_match':True,'main_title_and_intro_unchanged':True,'sha256':sha(target)}
(OUT/'trial_install.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf8')
print(json.dumps(result,indent=2))
