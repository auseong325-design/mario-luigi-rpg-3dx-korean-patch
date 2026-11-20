"""Static orthographic preview of decoded BCH pieces at their rest pose."""
from pathlib import Path
import sys,json
import numpy as np
from PIL import Image,ImageDraw
ROOT=Path(__file__).resolve().parents[3]
OUT=Path(__file__).parent
sys.path.insert(0,str(ROOT/'scripts'))
from libbch import Bch

S=8
def world_vertices(model,mesh):
    index=mesh['submeshes'][0]['bone_indices'][0]
    vertices=np.array([v['position'][:3] for v in mesh['vertices']],float)
    while index>=0:
        bone=model['bones'][index]
        assert not any(bone['rotation']), 'Preview supports the unrotated assembly pose'
        vertices=vertices*np.array(bone['scale'])+np.array(bone['translation'])
        index=bone['parent']
    return vertices

def layer(b,model,mesh):
    name=mesh['texture0']
    t=b.texture(name); rgba=b.decode(t)
    points=world_vertices(model,mesh)
    left,right=points[:,0].min(),points[:,0].max()
    bottom,top=points[:,2].min(),points[:,2].max()
    im=Image.fromarray(rgba).resize((round((right-left)*S),round((top-bottom)*S)),Image.Resampling.NEAREST)
    out=Image.new('RGBA',(int(195*S),int(75*S)))
    out.alpha_composite(im,(round((left-290)*S),round((160-top)*S)))
    return out

rows=[]; metrics={}
for label,geom_file,bch_file in [('BEFORE','model_geometry.json','before_title.bch'),
                                 ('AFTER','after_geometry.json','after_title.bch')]:
    b=Bch((OUT/bch_file).read_bytes())
    geom=json.loads((OUT/geom_file).read_text(encoding='utf-8-sig'))
    model=next(m for m in geom['models'] if m['name']=='logo_pch')
    m,amp,l=[layer(b,model,mesh) for mesh in model['meshes']]
    arrays=[np.asarray(x) for x in (m,amp,l)]
    masks=[(a[...,3]>=128)&((a[...,0]>100)|(a[...,1]>100)) for a in arrays]
    metrics[label]={'amp_mario_face_overlap':int((masks[0]&masks[1]).sum()),
                    'amp_luigi_face_overlap':int((masks[1]&masks[2]).sum())}
    standalone=next(m for m in geom['models'] if m['name']=='logo_L')
    attached=[world_vertices(standalone,mesh).mean(axis=0) for mesh in standalone['meshes']]
    assembled=[world_vertices(model,mesh).mean(axis=0) for mesh in model['meshes']]
    np.testing.assert_allclose(attached[0]-attached[1],assembled[1]-assembled[2],atol=3e-5)
    row=Image.new('RGBA',m.size,(42,44,54,255))
    for image in (m,amp,l):row.alpha_composite(image)
    row=row.resize((780,300),Image.Resampling.LANCZOS).convert('RGB')
    ImageDraw.Draw(row).text((16,12),label,fill='white')
    rows.append(row)
sheet=Image.new('RGB',(780,600))
for i,row in enumerate(rows):sheet.paste(row,(0,i*300))
sheet.save(OUT/'assembly_before_after.png')
(OUT/'preview_metrics.json').write_text(json.dumps(metrics,indent=2),encoding='utf8')
assert metrics['BEFORE']['amp_mario_face_overlap']>0
assert metrics['AFTER']['amp_mario_face_overlap']==metrics['AFTER']['amp_luigi_face_overlap']==0
print(json.dumps(metrics,indent=2))
