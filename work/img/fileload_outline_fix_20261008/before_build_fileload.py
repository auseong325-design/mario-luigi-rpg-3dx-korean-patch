"""Latest 1DX word geometry and 3DX title material on the file-select illustration.

The two opaque RGB565 halves share one 400x208 canvas. RPG is uniformly resized
with its original face/gloss; numeral 3 and character art retain their pixels.
"""
from pathlib import Path
import sys,json
import numpy as np
from scipy import ndimage as ndi
from PIL import Image
ROOT=Path(__file__).resolve().parents[3];OUT=Path(__file__).parent
sys.path.insert(0,str(ROOT/'work/img/logo2'))
import l2,layout,build_bottom as BB,build_fileload as OLD,model as M
sys.path.insert(0,str(ROOT/'work/img/title_1dx_shapes_20261008'))
sys.path.insert(0,str(ROOT/'work/img/title_lower_shading_20261008'))
import donor_layout,material
HR=l2.HR
NAMES=OLD.NAMES

def main():
    original=np.concatenate([l2.load(OLD.SRC/(n+'.png')) for n in NAMES],axis=1)
    H,W=original.shape[:2];shape=(H*HR,W*HR)
    _,jp,style,_=BB.jp_inputs()
    placed,info=donor_layout.masks(shape,x_left=26.,right=227.5,baseline=71.,donor_masks=material.donors())
    F={1:placed['ma']|placed['ri']|placed['o'],2:placed['amp'],3:placed['ru']|placed['i']|placed['ji']}
    seg=OLD.segment(original)
    yy,xx=np.mgrid[:H,:W]
    rpg_source=seg['cov']*(xx>=215)*(xx<299)*(yy>=32)
    # Preserve RPG's native face/gloss while bringing its proportions into balance.
    rpg_scale=.78;rpg_left=231.5
    F[4]=layout.resample(rpg_source,216.,72.,rpg_scale,rpg_scale,rpg_left,71.,shape)>.5
    rpg_rgb=np.stack([layout.resample(original[...,c],216.,72.,rpg_scale,rpg_scale,rpg_left,71.,shape,order=1) for c in range(3)],2)
    scale=info['scale_x']/.9095092024539877
    P=M.Params(r_o=5*scale,r_e=5*scale,D=6.5*scale,gl_a=1.1*scale,gl_d=2*scale,
               rim_w=1.5*scale,gl_soft=.25*scale,glow=False)
    y=np.arange(H,dtype=float)
    top_small=np.median([np.nonzero(placed[k].any(1))[0].min() for k in ('ri','i','ji')])/HR
    head_top=min(np.nonzero(placed[k].any(1))[0].min() for k in ('ma','ru'))/HR
    # The same measured title face and gloss, mapped to the uniformly scaled glyphs.
    src=np.clip(79+(y-top_small)*49/(70.5-top_small),0,255)
    render_style={k:dict(style[k]) for k in ('face','ext','rim')}
    for gid,light in [(1,.25),(3,0.)]:
        rows=np.stack([np.interp(src,np.arange(256),style['face'][gid][:,c]) for c in range(3)],1)
        ramp=np.clip((top_small-y)/max(top_small-head_top,1),0,1)
        render_style['face'][gid]=rows+(255-rows)*(light*ramp)[:,None]
    ay,ax=np.nonzero(F[2]);jy,jx=np.nonzero(jp[2])
    amp_top,amp_end=ay.min()/HR,(ay.max()+1)/HR
    amp_src=jy.min()/HR+(y-amp_top)*((jy.max()+1-jy.min())/HR)/(amp_end-amp_top)
    render_style['face'][2]=np.stack([np.interp(amp_src,np.arange(256),style['face'][2][:,c]) for c in range(3)],1)
    for gid in (1,2,3,4):
        render_style['ext'][gid]=np.stack([np.interp(128+(y-71.)/scale,np.arange(256),style['ext'][gid][:,c]) for c in range(3)],1)
    geo,ext_override=material.geometry_and_shading(F,P,np.zeros(shape,bool),info,style,output_dir=OUT)
    word,geo=M.render(F,P,render_style,geo=geo,ext_override=ext_override,face_override={4:(rpg_rgb,F[4])})
    # Erase the original word/RPG body and edge pixels, retaining numeral 3 and art.
    erase=ndi.binary_dilation(seg['body'],iterations=2)&(xx<301)&(yy<91)
    number_edge=(xx>=294)&(yy<32)
    erase[number_edge]=False
    base=original.copy();base[erase,:3]=255
    alpha=word[...,3:]/255
    out=base.copy();out[...,:3]=word[...,:3]*alpha+base[...,:3]*(1-alpha);out[...,3]=255
    # Number 3 and the character illustration remain exact original pixels.
    out[:,301:]=original[:,301:];out[number_edge]=original[number_edge]
    assert np.array_equal(out[91:],original[91:])
    assert np.array_equal(out[:,301:],original[:,301:])
    l2.save(out,OUT/'fileload.png')
    for name,image in zip(NAMES,[out[:,:144],out[:,144:]]):l2.save(image,OUT/(name+'.png'))
    np.savez_compressed(OUT/'fileload_masks.npz',**placed,erase=erase,body=geo['B'])
    metrics={'donor_layout':info,'same_uniform_scale_x_y':True,'amp_source':'1DX',
             'ji_stem':'latest rounded cap','underside':'latest 1DX light pattern with approved ru/ji contours',
             'material':'latest measured Japanese 3DX title material',
             'RPG_shape_gloss_preserved_with_uniform_scale':rpg_scale,
             'number3_and_character_art_preserved':True,'split_x':144,
             'body_bounds':[int(v) for v in [np.nonzero(word[...,3]>127)[1].min(),
                   np.nonzero(word[...,3]>127)[0].min(),np.nonzero(word[...,3]>127)[1].max()+1,
                   np.nonzero(word[...,3]>127)[0].max()+1]]}
    (OUT/'art_metrics.json').write_text(json.dumps(metrics,indent=2)+'\n',encoding='utf8')
    print(json.dumps(metrics,indent=2))

if __name__=='__main__':main()
