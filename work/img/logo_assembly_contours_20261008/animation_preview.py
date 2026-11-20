from pathlib import Path
import json,sys
import numpy as np
from scipy import ndimage as ndi
from PIL import Image,ImageDraw
ROOT=Path(__file__).resolve().parents[3];OUT=Path(__file__).parent
sys.path.insert(0,str(ROOT/'work/img/logo2'))
import l2
original=json.loads((OUT/'original_geometry.json').read_text(encoding='utf-8-sig'))
previous=json.loads((OUT/'before_geometry.json').read_text(encoding='utf-8-sig'))
frames=json.loads((OUT/'animation_frames.json').read_text(encoding='utf-8-sig'))
new_masks=np.load(OUT/'intro_masks.npz')


def world(model,mesh,frame):
    v=np.array([p['position'][:3] for p in mesh['vertices']],float)
    index=mesh['submeshes'][0]['bone_indices'][0]
    while index>=0:
        bone=model['bones'][index]
        if bone['name'] in frame['bones']:
            a=frame['bones'][bone['name']]
            scale=np.array([a['ScaleX'],a['ScaleY'],a['ScaleZ']])
            rotation=np.array([a['RotationX'],a['RotationY'],a['RotationZ']])
            translation=np.array([a['TranslationX'],a['TranslationY'],a['TranslationZ']])
        else:
            scale=np.array(bone['scale']);rotation=np.array(bone['rotation']);translation=np.array(bone['translation'])
        assert abs(rotation[0])+abs(rotation[2])<1e-7
        theta=rotation[1];c,s=np.cos(theta),np.sin(theta)
        R=np.array([[c,0,s],[0,1,0],[-s,0,c]])
        v=(v*scale)@R.T+translation
        index=bone['parent']
    return v


def projection(model,mesh,frame,suffix='',S=4):
    v=world(model,mesh,frame)
    assert np.isfinite(v).all()
    name=mesh['texture0'];image=l2.load(OUT/(name+suffix+'.png'))
    Y,X=np.mgrid[:96*S,:212*S].astype(float)
    q=np.stack([290+(X+.5)/S,165-(Y+.5)/S],0).reshape(2,-1)
    verts=v[:,[0,2]]
    matrix=np.column_stack([verts[1]-verts[0],verts[2]-verts[0]])
    uv=(np.linalg.inv(matrix)@(q-verts[0,:,None])).reshape(2,*X.shape)
    H,W=image.shape[:2]
    cy,cx=uv[1]*H-.5,uv[0]*W-.5
    inside=(uv>=0).all(0)&(uv<=1).all(0)
    alpha=image[...,3]/255
    pm=np.concatenate([image[...,:3]*alpha[...,None],alpha[...,None]],2)
    sampled=np.stack([ndi.map_coordinates(pm[...,c],[cy,cx],order=1,mode='constant') for c in range(4)],2)
    sampled*=inside[...,None]
    rgb=np.divide(sampled[...,:3],np.maximum(sampled[...,3:],1e-9))
    if suffix:
        face=(sampled[...,3]>.5)&(rgb.max(2)>100)&(rgb.mean(2)>65)
    else:
        mask=new_masks[name].astype(float)
        face=ndi.map_coordinates(mask,[(cy+.5)*4-.5,(cx+.5)*4-.5],order=1,mode='constant')>.5
    return sampled,face,v


def panel(geometry,frame,suffix,label):
    model=next(m for m in geometry['models'] if m['name']=='logo_pch')
    H,W=96*4,212*4;result=np.tile(np.array([42,44,54.]),(H,W,1));faces={}
    for mesh in model['meshes']:
        p,mask,v=projection(model,mesh,frame,suffix)
        result=p[...,:3]+result*(1-p[...,3:])
        faces[mesh['texture0']]=mask
    image=Image.fromarray(np.uint8(np.clip(result,0,255))).resize((848,384),Image.Resampling.LANCZOS)
    ImageDraw.Draw(image).text((12,12),label,fill='white')
    overlap=[int((faces['title_logo_and_JP']&faces[key]).sum()) for key in ['title_logo_M_JP','title_logo_L_JP']]
    return image,overlap


stats={};models={m['name']:m for m in original['models']}
baseline_errors=[]
for frame in frames:
    for model in original['models']:
        for mesh in model['meshes']:assert np.isfinite(world(model,mesh,frame)).all()
    if frame['frame']<=159:
        baselines=[]
        config=json.loads((OUT/'intro_layout.json').read_text(encoding='utf8'))
        for mesh in models['logo_pch']['meshes']:
            v=world(models['logo_pch'],mesh,frame)
            H=64;W=64 if mesh['texture0']=='title_logo_and_JP' else 128
            t=config[mesh['texture0']]['baseline']/H
            point=v[0]*(1-t)+v[2]*t
            baselines.append(float(point[2]))
        baseline_errors.append(max(baselines)-min(baselines))
        _,overlap=panel(original,frame,'','ASSEMBLY')
        assert overlap==[0,0],(frame['frame'],overlap)
stats['assembled_frames_checked']=160
stats['full_animation_frames_checked']=len(frames)
stats['max_assembly_baseline_difference_world']=max(baseline_errors)
assert max(baseline_errors)<.15
stats['assembly_face_overlap_mario_amp']=0
stats['assembly_face_overlap_luigi_amp']=0
# The attached & uses the same unmodified relative quad position as the assembled copies.
L=models['logo_L'];pch=models['logo_pch']
attached=[world(L,mesh,frames[0]).mean(0) for mesh in L['meshes']]
assembled={mesh['texture0']:world(pch,mesh,frames[0]).mean(0) for mesh in pch['meshes']}
np.testing.assert_allclose(attached[0]-attached[1],assembled['title_logo_and_JP']-assembled['title_logo_L_JP'],atol=4e-5)
stats['attached_and_assembled_relative_positions_match']=True
stats['runtime_verified']=False
rows=[]
for g,s,label in [(original,'_before','BEFORE textures on original animation coordinates'),
                  (previous,'_before','Previous coordinate-only static preview'),
                  (original,'','AFTER common 1DX scale / baseline on original coordinates')]:
    image,_=panel(g,frames[0],s,label);rows.append(image)
sheet=Image.new('RGB',(848,384*3))
for i,row in enumerate(rows):sheet.paste(row,(0,i*384))
sheet.save(OUT/'intro_assembly_before_after.png')
rows=[]
for i in [0,100,159,180,209,240]:
    image,_=panel(original,frames[i],'',f'AFTER frame {i} (static projection)')
    rows.append(image.resize((424,192),Image.Resampling.LANCZOS))
sheet=Image.new('RGB',(848,576))
for i,row in enumerate(rows):sheet.paste(row,((i%2)*424,(i//2)*192))
sheet.save(OUT/'animation_samples.png')
(OUT/'animation_verify.json').write_text(json.dumps(stats,indent=2)+'\n',encoding='utf8')
print(json.dumps(stats,indent=2))
