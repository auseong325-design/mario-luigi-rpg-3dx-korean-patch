"""One uniform 1DX word transform across the original animated intro quads.

Place glyphs in the textures themselves. Original bones/animations/mesh offsets
remain in use, including the two copies of the ampersand.
"""
from pathlib import Path
import json,sys
import numpy as np
from scipy import ndimage as ndi
ROOT=Path(__file__).resolve().parents[3];OUT=Path(__file__).parent
sys.path.insert(0,str(ROOT/'work/img/logo2'))
sys.path.insert(0,str(ROOT/'work/img/title_lower_shading_20261008'))
import l2,layout,model as M,material,build_bottom as BB
HR=l2.HR
K=.60;BASE=43.5;LEFT=20.
INTRO_SCALE=.75
# The animated assembly roots and unmodified texture quad bounds, from independent SPICA parsing.
QUADS={1:{'name':'title_logo_M_JP','size':(64,128),'left':293.,'top':144.,'donor':['ma','ri','o']},
       2:{'name':'title_logo_and_JP','size':(64,64),'left':355.,'top':153.,'donor':['amp']},
       3:{'name':'title_logo_L_JP','size':(64,128),'left':379.,'top':144.,'donor':['ru','i','ji']}}


def main():
    donor=material.donors()
    _,_,style,_=BB.jp_inputs()
    metrics={};masks={}
    for gid,cfg in QUADS.items():
        height,width=cfg['size'];shape=(height*HR,width*HR)
        left=LEFT+(QUADS[1]['left']-cfg['left'])/INTRO_SCALE
        baseline=BASE+(cfg['top']-QUADS[1]['top'])/INTRO_SCALE
        source=np.maximum.reduce([donor[name] for name in cfg['donor']])
        face=layout.resample(source,6.,81.,K,K,left,baseline,shape)>.5
        assert face.any()
        P=M.Params(r_o=3.,r_e=3.,D=3. if gid==2 else 3.5,sx=.75,
                   navy=(0,34,68),glow=False,blur=.5,gl_a=.8,gl_d=1.5,gl_k=1.)
        ys=np.arange(height,dtype=float)
        src=81.+(ys-baseline)/K
        jp=79.+(src-41.)*49./40.
        if gid==2:
            jp=106.+(src-47.)*25.5/35.
        tab=style['face'][gid]
        rows=np.stack([np.interp(jp,np.arange(256),tab[:,c]) for c in range(3)],1)
        if gid==1:
            light=.25*np.clip((41.-src)/(41.-16.),0,1)
            rows=rows+(255-rows)*light[:,None]
        face_bottom=(np.nonzero(face)[0].max()+1)/HR
        ext_y=ys-face_bottom+128.
        ext=np.stack([np.interp(ext_y,np.arange(256),style['ext'][gid][:,c]) for c in range(3)],1)
        st={'face':{gid:rows},'ext':{gid:ext},'rim':{gid:style['rim'][gid]} if gid in style['rim'] else {}}
        image,geo=M.render({gid:face},P,st)
        image=l2.q4(image);image[image[...,3]==0,:3]=P.navy
        edge=np.concatenate([image[0,:,3],image[-1,:,3],image[:,0,3],image[:,-1,3]])
        assert edge.max()<=34,(cfg['name'],'edge clipping',edge.max())
        l2.save(image,OUT/(cfg['name']+'.png'))
        masks[cfg['name']]=face
        metrics[cfg['name']]={'scale_x':K,'scale_y':K,'left_anchor':left,'baseline':baseline,
                             'world_donor_baseline':cfg['top']-INTRO_SCALE*baseline,
                             'edge_alpha_max':float(edge.max()),'params':P.__dict__}
    np.savez_compressed(OUT/'intro_masks.npz',**masks)
    metrics['method']='same source affine across original quads; coordinates and animation keys unmodified'
    (OUT/'intro_layout.json').write_text(json.dumps(metrics,indent=2)+'\n',encoding='utf8')
    print(json.dumps(metrics,indent=2))


if __name__=='__main__':main()
