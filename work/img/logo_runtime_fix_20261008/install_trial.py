"""Install the audited trial after stopping emulation with built-in Computer Use."""
from pathlib import Path
import hashlib,json,os,time
ROOT=Path(__file__).resolve().parents[3];OUT=Path(__file__).parent
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
v=json.loads((OUT/'build_verify.json').read_text())
assert v['only_ampersand_texture_changed'] and v['all_other_bch_bytes_equal']
source=OUT/'after_fmdl.dat';assert sha(source)==v['stage_sha256']
target=ROOT/'patch/00040000001CA900/romfs/FMdl/JP/FMdl.dat'
assert sha(target) in {v['before_fmdl_sha256'],v['stage_sha256']}
assert sha(OUT/'before_fmdl.dat')==v['before_fmdl_sha256']
temp=target.with_name(target.name+'.runtime_trial.tmp');temp.write_bytes(source.read_bytes())
for attempt in range(10):
    try:temp.replace(target);break
    except OSError:
        if attempt==9:raise
        time.sleep(.5)
junction=Path(os.environ['APPDATA'])/'Azahar/load/mods/00040000001CA900/romfs/FMdl/JP/FMdl.dat'
assert sha(junction)==sha(target)==v['stage_sha256']
result={'trial_installed':True,'emulation_stopped_with_codex_computer_use':True,
        'patch_and_azahar_junction_match':True,'sha256':sha(target),'runtime_verified':False}
(OUT/'trial_install.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf8')
print(json.dumps(result,indent=2))
