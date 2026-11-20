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
    face_labels,face_components=OLD.groups(seg['cov'])
    rpg_ids=[c[0] for c in face_components if c[1]>=215 and c[3]>=33 and c[4]-c[3]>20]
    assert len(rpg_ids)==2
    rpg_source=seg['cov']*np.isin(face_labels,rpg_ids)
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
    # Separate the original numeral by face ownership, rather than cutting at x=301.
    rgb=original[...,:3]
    colored=(rgb.max(2)-rgb.min(2)>80)&(rgb.max(2)>140)
    color_labels,_=ndi.label(colored)
    number_face=color_labels==color_labels[45,325]
    assert number_face.sum()>1000
    d_number=ndi.distance_transform_edt(~number_face)
    d_rpg=ndi.distance_transform_edt(rpg_source<.35)
    old_rpg_ink=(seg['cov']>.35)&(xx>=215)
    d_old_rpg=ndi.distance_transform_edt(~old_rpg_ink)
    number_side=(d_number<=d_rpg+1.5)&(xx>=292)&(yy<91)
    number_side|=(yy<33)&(xx>=292)
    original_ink=ndi.binary_dilation(~seg['bg'],iterations=1)
    number_restore=number_side&original_ink&(d_old_rpg>3)
    number_restore|=number_face
    # Erase the original word/RPG body, preserving the numeral's curved silhouette.
    erase=(ndi.binary_dilation(seg['body'],iterations=2)|(d_old_rpg<=7))&(yy<91)
    erase[number_restore]=False
    base=original.copy();base[erase,:3]=255
    alpha=word[...,3:]/255
    out=base.copy();out[...,:3]=word[...,:3]*alpha+base[...,:3]*(1-alpha);out[...,3]=255
    # Restore the entire numeral silhouette; new RPG may extend smoothly into white.
    out[number_restore]=original[number_restore]
    # Round only the meeting of the new G body and the retained flame silhouette.
    number_coverage=np.clip((255-rgb.min(2))/(255-seg['navy'].min()),0,1)*number_restore
    B_number=l2.up(number_coverage)>.5
    sd_g=l2.sdf(geo['B']);sd_number=l2.sdf(B_number)
    blend_radius=2.0
    blend=np.clip(.5+.5*(sd_g-sd_number)/blend_radius,0,1)
    joined_sd=sd_number+(sd_g-sd_number)*blend+blend_radius*blend*(1-blend)
    joined_body=joined_sd>0
    expanded=l2.dist_out(joined_body)<=6.0
    joined_body=l2.sdf(expanded)>6.0
    joined_body=ndi.binary_fill_holes(joined_body)
    joined=l2.down(joined_body.astype(float))
    union=1-(1-word[...,3]/255)*(1-number_coverage)
    join_region=(xx>=289)&(xx<310)&(yy>=24)&(yy<87)
    added=np.maximum(joined-union,0)*join_region
    added[ndi.binary_dilation(number_face,iterations=1)]=0
    bridge_alpha=added/np.maximum(1-union,1e-6)
    out[...,:3]=out[...,:3]*(1-bridge_alpha[...,None])+np.asarray(P.navy)*bridge_alpha[...,None]
    assert np.array_equal(out[91:],original[91:])
    assert np.array_equal(out[:,310:],original[:,310:])
    assert np.array_equal(out[number_face],original[number_face])
    l2.save(out,OUT/'fileload.png')
    for name,image in zip(NAMES,[out[:,:144],out[:,144:]]):l2.save(image,OUT/(name+'.png'))
    np.savez_compressed(OUT/'fileload_masks.npz',**placed,erase=erase,body=geo['B'],number_restore=number_restore,number_face=number_face,join_added=added)
    metrics={'donor_layout':info,'same_uniform_scale_x_y':True,'amp_source':'1DX',
             'ji_stem':'latest rounded cap','underside':'latest 1DX light pattern with approved ru/ji contours',
             'material':'latest measured Japanese 3DX title material',
             'RPG_shape_gloss_preserved_with_uniform_scale':rpg_scale,
             'number3_and_character_art_preserved':True,'split_x':144,
             'rpg_extraction':'two complete face components; numeral fragments excluded',
             'number_composition':'curved silhouette from semantic face ownership; no vertical crop',
             'join_cleanup':'smooth silhouette union, rounded concave junction and hole removal',
             'join_region':[289,24,310,87],
             'body_bounds':[int(v) for v in [np.nonzero(word[...,3]>127)[1].min(),
                   np.nonzero(word[...,3]>127)[0].min(),np.nonzero(word[...,3]>127)[1].max()+1,
                   np.nonzero(word[...,3]>127)[0].max()+1]]}
    (OUT/'art_metrics.json').write_text(json.dumps(metrics,indent=2)+'\n',encoding='utf8')
    print(json.dumps(metrics,indent=2))

if __name__=='__main__':main()
