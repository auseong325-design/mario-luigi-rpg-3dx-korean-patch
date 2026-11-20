"""Replace only the two file-select texture halves in the installed MLyt baseline."""
from pathlib import Path
import sys,json,hashlib
import numpy as np
from PIL import Image
ROOT=Path(__file__).resolve().parents[3];OUT=Path(__file__).parent
sys.path.insert(0,str(ROOT/'scripts'))
import lib3dx,lytimg,build_lyt
NAMES=['LOAD_GAME_IMG_ML_L_00_JP_ja','LOAD_GAME_IMG_ML_R_00_JP_ja']
baseline=(OUT/'before_MLyt.dat').read_bytes();_,entries=lib3dx.read_bg4(baseline)
repl={};changes=[]
for slot,entry in enumerate(entries):
    if entry.size_flag or not entry.data:continue
    plain=lib3dx.bg4_plain(entry)
    if plain[:4]!=b'SARC':continue
    files={}
    for name,start,end in lytimg.sarc_list(plain):
        if Path(name).stem not in NAMES:continue
        assert entry.name=='MENU_FILE_LOAD_JP_ja'
        image=np.asarray(Image.open(OUT/(Path(name).stem+'.png')).convert('RGBA'))
        files[name]=lytimg.rgba_to_bflim(plain[start:end],image)
        assert np.array_equal(lytimg.bflim_to_rgba(files[name]),build_lyt.expected('RGB565',image))
        changes.append(f'{entry.name}/{name}')
    if files:repl[slot]=lytimg.sarc_replace(plain,files)
assert len(changes)==2 and len(repl)==1
rebuilt=lib3dx.rebuild_bg4(baseline,repl);_,new=lib3dx.read_bg4(rebuilt)
assert len(entries)==len(new)
for before,after in zip(entries,new):
    assert before.name==after.name and before.size_flag==after.size_flag
    if before.data==after.data:continue
    assert before.name=='MENU_FILE_LOAD_JP_ja'
    p,q=lib3dx.bg4_plain(before),lib3dx.bg4_plain(after)
    f_old,f_new=lytimg.sarc_list(p),lytimg.sarc_list(q)
    assert [f[0] for f in f_old]==[f[0] for f in f_new]
    changed=[]
    for (name,s,t),(n,u,v) in zip(f_old,f_new):
        if p[s:t]==q[u:v]:continue
        assert Path(name).stem in NAMES
        image=np.asarray(Image.open(OUT/(Path(name).stem+'.png')).convert('RGBA'))
        assert np.array_equal(lytimg.bflim_to_rgba(q[u:v]),build_lyt.expected('RGB565',image))
        changed.append(name)
    assert 1<=len(changed)<=2
(OUT/'after_MLyt.dat').write_bytes(rebuilt)
for name in NAMES:
    for directory in [ROOT/'work/img/ko/lyt/MLyt/MENU_FILE_LOAD_JP_ja',ROOT/'work/img/logo2/out']:
        target=directory/(name+'.png');temp=target.with_suffix('.fileload_logo.tmp')
        temp.write_bytes((OUT/(name+'.png')).read_bytes());temp.replace(target)
result={'changed_texture_copies':changes,'only_two_ML_textures_changed':True,
        'all_other_SARC_files_and_archive_entries_unchanged':True,
        'layouts_animations_character_art_and_KJ_logo_unchanged':True,'decoded_RGB565_matches_inputs':True,
        'before_sha256':hashlib.sha256(baseline).hexdigest(),'after_sha256':hashlib.sha256(rebuilt).hexdigest()}
(OUT/'build_verify.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf8')
print(json.dumps(result,indent=2))
