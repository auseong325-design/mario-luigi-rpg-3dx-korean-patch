from pathlib import Path
import json,sys
import numpy as np
from PIL import Image,ImageDraw
ROOT=Path(__file__).resolve().parents[3];OUT=Path(__file__).parent
sys.path.insert(0,str(ROOT/'scripts'))
from libbch import Bch
g=json.loads((ROOT/'work/img/title_layout_20261008/after_geometry.json').read_text(encoding='utf-8-sig'))
model=next(m for m in g['models'] if m['name']=='logo_pch')
S=8
def vertices(mesh):
    index=mesh['submeshes'][0]['bone_indices'][0]
    v=np.array([p['position'][:3] for p in mesh['vertices']],float)
    while index>=0:
        bone=model['bones'][index];assert not any(bone['rotation'])
        v=v*np.array(bone['scale'])+np.array(bone['translation']);index=bone['parent']
    return v
def layer(b,mesh):
    v=vertices(mesh);left,right=v[:,0].min(),v[:,0].max();bottom,top=v[:,2].min(),v[:,2].max()
    tex=b.texture(mesh['texture0'])
    image=Image.fromarray(b.decode(tex)).resize((round((right-left)*S),round((top-bottom)*S)),Image.Resampling.NEAREST)
    out=Image.new('RGBA',(195*S,75*S));out.alpha_composite(image,(round((left-290)*S),round((160-top)*S)))
    return out
rows=[];stats={}
for label,filename in [('BEFORE','before_title.bch'),('AFTER','after_title.bch')]:
    b=Bch((OUT/filename).read_bytes())
    mario,amp,luigi=[layer(b,mesh) for mesh in model['meshes']]
    arrays=[np.asarray(image) for image in (mario,amp,luigi)]
    masks=[(a[...,3]>=128)&((a[...,0]>100)|(a[...,1]>100)) for a in arrays]
    stats[label]={'amp_mario_face_overlap':int((masks[0]&masks[1]).sum()),'amp_luigi_face_overlap':int((masks[1]&masks[2]).sum())}
    row=Image.new('RGBA',mario.size,(42,44,54,255))
    for image in (mario,amp,luigi):row.alpha_composite(image)
    row=row.resize((780,300),Image.Resampling.LANCZOS).convert('RGB')
    ImageDraw.Draw(row).text((16,12),label,fill='white');rows.append(row)
sheet=Image.new('RGB',(780,600))
for i,row in enumerate(rows):sheet.paste(row,(0,i*300))
sheet.save(OUT/'intro_before_after.png')
assert stats['AFTER']=={'amp_mario_face_overlap':0,'amp_luigi_face_overlap':0},stats
(OUT/'intro_preview_verify.json').write_text(json.dumps(stats,indent=2)+'\n',encoding='utf8')
print(json.dumps(stats,indent=2))
