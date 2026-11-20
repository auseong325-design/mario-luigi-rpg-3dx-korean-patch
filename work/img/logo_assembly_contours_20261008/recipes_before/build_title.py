"""Restore the official 1DX glyph proportions and fit the title inside the visible screen.

Uses donor face masks and the established 3DX material renderer; original RPG/3/DX pixels
are translated without changing their shape. The prior intro pieces and coordinate fix stay in place.
"""
from pathlib import Path
import json,sys
import numpy as np
from scipy import ndimage as ndi
from PIL import Image
ROOT=Path(__file__).resolve().parents[3];OUT=Path(__file__).parent
sys.path.insert(0,str(ROOT/'work/img/logo2'))
import l2,build_bottom as BB,model as M
HR=l2.HR
CONFIG={'glyph_scale':None,'x_left':18.,'title_down':10.,'dx_center':256.,'silhouette_syllables':['ri','o'],
        'word_shape':'1DX glyphs and positions; ji stem cap restored from user reference'}

def shift_rgba(a,dx,dy):
    """Subpixel translation in premultiplied alpha; no resizing or reshaping."""
    alpha=a[...,3:]/255
    pm=np.concatenate([a[...,:3]*alpha,a[...,3:]],axis=2)
    pm=ndi.shift(pm,(dy,dx,0),order=1,mode='constant',cval=0,prefilter=False)
    return np.concatenate([pm[...,:3]*255/np.maximum(pm[...,3:],1e-9),pm[...,3:]],axis=2)

def box(mask,scale=1):
    yy,xx=np.nonzero(mask)
    return [float(xx.min()/scale),float(yy.min()/scale),float((xx.max()+1)/scale),float((yy.max()+1)/scale)]

def main():
    original,F_jp,style,sil_jp=BB.jp_inputs()
    shape=(256*HR,512*HR)
    sys.path.insert(0,str(ROOT/'work/img/title_1dx_shapes_20261008'))
    import donor_layout
    sys.path.insert(0,str(ROOT/'work/img/title_lower_shading_20261008'))
    import material
    placed,donor_info=donor_layout.masks(shape,x_left=CONFIG['x_left'],donor_masks=material.donors())
    donor_info['stem_redesign']='rounded cap restored from supplied reference; original stem below row 54'
    CONFIG['glyph_scale']=donor_info['scale_x']
    F={1:placed['ma']|placed['ri']|placed['o'],2:placed['amp'],3:placed['ru']|placed['i']|placed['ji']}
    right=box(F[3],HR)[2]
    # Place RPG after the restored Korean word, preserving the old seam and original pixels.
    rpg_dx=right-273.75
    for g in (4,5,6):F[g]=l2.shift_hr(F_jp[g],round(rpg_dx*HR),0)
    P=M.Params()
    O_jp=l2.dist_out(np.any(list(F_jp.values()),axis=0))<=P.r_o
    O_kr=l2.dist_out(np.any(list(F.values()),axis=0))<=P.r_o
    targets=[]
    for key in CONFIG['silhouette_syllables']:
        columns=np.nonzero(placed[key].any(axis=0))[0]
        tx,_=BB.blob_top(placed[key],columns.min()/HR,(columns.max()+1)/HR)
        targets.append(tx)
    # Match 1DX: both figures stand over 마리오, Mario on 리 and Luigi on 오.
    silhouettes,moves=BB.move_silhouettes(sil_jp,O_jp,None,O_kr,targets)
    top_small=np.median([np.nonzero(placed[k].any(axis=1))[0].min() for k in ('ri','i','ji')])/HR
    ys=np.arange(256,dtype=float)
    src=np.clip(79+(ys-top_small)*49/(127.5-top_small),0,255)
    render_style={k:dict(style[k]) for k in ('face','ext','rim')}
    head_top=min(np.nonzero(placed[k].any(axis=1))[0].min() for k in ('ma','ru'))/HR
    ramp=np.clip((top_small-ys)/max(top_small-head_top,1),0,1)
    for g in (1,3):
        tab=style['face'][g]
        face=np.stack([np.interp(src,ys,tab[:,c]) for c in range(3)],axis=1)
        render_style['face'][g]=face+(255-face)*(BB.P_LAY['head_light'][g]*ramp)[:,None]
    # 1DX & shape, rendered with the original 3DX &'s measured white/cyan gradient.
    amp_box=box(F[2],HR);jp_amp_box=box(F_jp[2],HR)
    amp_rows=jp_amp_box[1]+(ys-amp_box[1])*(jp_amp_box[3]-jp_amp_box[1])/(amp_box[3]-amp_box[1])
    render_style['face'][2]=np.stack([np.interp(amp_rows,ys,style['face'][2][:,c]) for c in range(3)],axis=1)
    ext_rows=ys-(amp_box[3]-jp_amp_box[3])
    render_style['ext'][2]=np.stack([np.interp(ext_rows,ys,style['ext'][2][:,c]) for c in range(3)],axis=1)
    geo,ext_override=material.geometry_and_shading(F,P,silhouettes,donor_info,style)
    bottom,geo=M.render(F,P,render_style,extra_body=silhouettes,geo=geo,ext_override=ext_override)
    rpg=shift_rgba(original,rpg_dx,0)
    x=np.arange(512,dtype=float)
    weight=np.clip((x-(283+rpg_dx))/8,0,1)[None,:,None]
    pm_a=np.concatenate([rpg[...,:3]*rpg[...,3:]/255,rpg[...,3:]],axis=2)
    pm_b=np.concatenate([bottom[...,:3]*bottom[...,3:]/255,bottom[...,3:]],axis=2)
    pm=pm_b*(1-weight)+pm_a*weight
    bottom=np.concatenate([pm[...,:3]*255/np.maximum(pm[...,3:],1e-9),pm[...,3:]],axis=2)
    bottom=shift_rgba(bottom,0,CONFIG['title_down'])
    top=l2.load(OUT/'title_logo_JP_top_before.png')
    number=top.copy();number[:,:350]=0
    deluxe=top.copy();deluxe[:,350:]=0
    yy,xx=np.nonzero(deluxe[...,3]>64)
    dx_shift=CONFIG['dx_center']-(xx.min()+xx.max()+1)/2
    number=shift_rgba(number,rpg_dx,CONFIG['title_down'])
    deluxe=shift_rgba(deluxe,dx_shift,CONFIG['title_down'])
    l2.save(l2.q4(number),OUT/'number_rgba.png')
    l2.save(l2.q4(deluxe),OUT/'deluxe_rgba.png')
    a=Image.fromarray(l2.q4(deluxe).astype(np.uint8));b=Image.fromarray(l2.q4(number).astype(np.uint8))
    top=np.asarray(Image.alpha_composite(a,b),float)
    outputs={'title_logo_JP_bottom':l2.q4(bottom),'title_logo_JP_top':l2.q4(top)}
    for name,img in outputs.items():l2.save(img,OUT/(name+'.png'))
    shifted_sil=l2.shift_hr(silhouettes,0,round(CONFIG['title_down']*HR))
    main_box=box((outputs['title_logo_JP_bottom'][...,3]>64)|(l2.q4(number)[...,3]>64))
    np.savez_compressed(OUT/'title_masks.npz',**{f'F{g}':l2.shift_hr(mask,0,round(CONFIG['title_down']*HR)) for g,mask in F.items()},
                        **{name:l2.shift_hr(mask,0,round(CONFIG['title_down']*HR)) for name,mask in placed.items()},sil=shifted_sil)
    metrics={'config':CONFIG,'old_glyph_scale_x':.695,'old_glyph_scale_y':.94,
             'new_glyph_scale_x':donor_info['scale_x'],'new_glyph_scale_y':donor_info['scale_y'],
             'donor_layout':donor_info,'amp_material':'3DX measured face/extrusion row tables; shared 3DX gloss, outline and glow',
             'rpg_and_3_shift_x':rpg_dx,'amp_texture_box':amp_box,
             'silhouette_moves':moves,'silhouette_texture_box':box(shifted_sil,HR),
             'dx_shift_x':dx_shift,'dx_texture_center':CONFIG['dx_center'],
             'main_title_alpha64_box':main_box,'main_title_center':(main_box[0]+main_box[2])/2,
             'center_difference_texture_px':abs((main_box[0]+main_box[2])/2-CONFIG['dx_center']),
             'alpha64_boxes':{name:box(img[...,3]>64) for name,img in outputs.items()}}
    (OUT/'layout_metrics.json').write_text(json.dumps(metrics,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
    print(json.dumps(metrics,ensure_ascii=False,indent=2))

if __name__=='__main__':main()
