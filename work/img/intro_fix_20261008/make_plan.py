"""Derive & offsets from approved Korean layout and verify the original GPU uniforms."""
from pathlib import Path
import hashlib,json,struct,sys
import numpy as np
ROOT=Path(__file__).resolve().parents[3]
OUT=Path(__file__).parent
sys.path.insert(0,str(ROOT/'scripts'))
from libbch import Bch

b=Bch((OUT/'original_title.bch').read_bytes())
g=json.loads((OUT/'model_geometry.json').read_text(encoding='utf-8-sig'))
models={m['name']:m for m in g['models']}
final_scale=models['logo_title_bottom']['bones'][0]['scale'][0]
intro_scale=models['logo_pch']['bones'][5]['scale'][0]
layout=np.load(ROOT/'work/img/logo2/fit/kr_bottom_layout.npz')
dx=float(layout['amp_dx'])/4*final_scale/intro_scale

def face_bottom(name):
    a=b.decode(b.texture(name)) if name=='title_logo_and_JP' else Bch((OUT/'before_title.bch').read_bytes()).decode(b.texture(name))
    mask=(a[...,3]>0)&((a[...,0]>100)|(a[...,1]>100))
    return int(np.nonzero(mask)[0].max())+1
ma_bottom=(np.nonzero(layout['Fma'])[0].max()+1)/4
amp_bottom=(np.nonzero(layout['Famp'])[0].max()+1)/4
# Rest-pose quad tops are M=144 and &=153. Match the Korean faces' baseline difference.
m_baseline=144-intro_scale*face_bottom('title_logo_M_JP')
old_amp_baseline=153-intro_scale*face_bottom('title_logo_and_JP')
dz=(m_baseline-(amp_bottom-ma_bottom)*final_scale-old_amp_baseline)/intro_scale
edits=[]
for model,base,old_xyz in [('logo_L',0x45f0,[-64.00000762939453,2,12]),
                         ('logo_pch',0x5830,[4.76837158203125e-6,2,4.76837158203125e-6])]:
    assert struct.unpack_from('<II',b.data,base)==(0x80000006,0x804f02c0)
    w,z,y,x=struct.unpack_from('<4f',b.data,base+8)
    assert [x,y,z]==old_xyz and w==0
    # GPU uniform6 stores W,Z,Y,X. Keep depth Y and all geometry attributes intact.
    for axis,offset,old,delta in [('X',base+20,x,dx),('Z',base+12,z,dz)]:
        edits.append({'mesh':model+'/title_logo_and_JP','axis':axis,'offset':offset,
                      'before':struct.pack('<f',old).hex(),'after':struct.pack('<f',old+delta).hex(),
                      'old':old,'new':struct.unpack('<f',struct.pack('<f',old+delta))[0]})
plan={'description':'2026-10-08 intro &: Korean title spacing and baseline; two copies of the & mesh.',
      'derivation':{'final_scale':final_scale,'intro_scale':intro_scale,'final_amp_shift_px':float(layout['amp_dx'])/4,
                    'local_dx':dx,'local_dz':dz,'world_dx':dx*intro_scale,'world_dz':dz*intro_scale,
                    'ma_face_bottom':ma_bottom,'amp_face_bottom':amp_bottom},
      'models':{'fmd_title_JP_ja':{'original_command_sha256':hashlib.sha256(b.data[b.cmds:b.cmds+b.cmd_len]).hexdigest(),'edits':edits}}}
(ROOT/'work/img/fmdl_geometry_patches.json').write_text(json.dumps(plan,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
print(json.dumps(plan,ensure_ascii=False,indent=2))
