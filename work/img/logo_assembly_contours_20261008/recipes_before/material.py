"""1DX underside geometry/light pattern recolored with the measured 3DX material.

The user's reference supplies only the rounded ji-stem cap. Face colors, highlights,
and all title positioning continue to use the established 3DX renderer.
"""
from pathlib import Path
import json,sys
import numpy as np
from PIL import Image
from scipy import ndimage as ndi
from scipy.interpolate import PchipInterpolator
ROOT=Path(__file__).resolve().parents[3];OUT=Path(__file__).parent
sys.path.insert(0,str(ROOT/'work/img/logo2'))
import l2,seg_1dx,layout,model as M
HR=l2.HR


def donors():
    raw,_=seg_1dx.syllables(fix_stem=False)
    ref=l2.load(OUT/'ref/luigi_stem.png')
    navy=np.array([0.,20.,24.])
    distance=np.sqrt(((ref[...,:3]-navy)**2).sum(2))
    cov=np.clip((distance-45)/85,0,1)*(ref[...,3]/255)
    yy,xx=np.mgrid[:cov.shape[0],:cov.shape[1]]
    cov*=((xx>=303)&(xx<339)&(yy>=30)&(yy<91))
    lab,_=ndi.label(cov>.3)
    label=int(lab[60,320]);assert label>0
    cap=cov*ndi.binary_dilation(lab==label,iterations=1)
    # Place the reference cap on the existing stem; retain the original stem below row 54.
    ry,rx=np.nonzero(cap>.5)
    scale=.42
    donor_y,donor_x=np.mgrid[:raw['ji'].shape[0],:raw['ji'].shape[1]].astype(float)
    refx=(donor_x+.5-332.0)/scale+(rx.max()+1)
    refy=(donor_y+.5-37.0)/scale+ry.min()
    new=ndi.map_coordinates(cap,[refy-.5,refx-.5],order=3,mode='constant')
    new=np.clip(new,0,1)*(donor_y<54)*(donor_x>=318)*(donor_x<332)
    new=np.where(new>=.025,new,0)
    fixed={name:mask.copy() for name,mask in raw.items()}
    fixed['ji']=np.maximum(raw['ji'],new)
    np.savez_compressed(OUT/'donor_masks.npz',**fixed)
    np.savez_compressed(OUT/'stem_cap.npz',reference=cap,added=new,original=raw['ji'],restored=fixed['ji'])
    info={'reference':'ref/luigi_stem.png','reference_cap_box':[int(rx.min()),int(ry.min()),int(rx.max()+1),int(ry.max()+1)],
          'reference_scale':scale,'source_cap_top':37.,'source_right_edge':332.,'original_stem_unchanged_below_row':54,
          'operation':'union with rounded reference cap; no color or highlight copied'}
    (OUT/'stem_metrics.json').write_text(json.dumps(info,indent=2)+'\n',encoding='utf8')
    return fixed


def _palette(style,g):
    # Retain the Japanese navy -> burgundy / forest-green / cyan color progression.
    limits={1:(120,138),2:(128,142),3:(118,136)}
    start,end=limits[g]
    curve=style['ext'][g][start:end+1].copy()
    curve[0]=np.array([0,51,85])
    curve=ndi.gaussian_filter1d(curve,.7,axis=0,mode='nearest')
    curve[0]=np.array([0,51,85])
    return PchipInterpolator(np.linspace(0,1,len(curve)),curve,axis=0)


def geometry_and_shading(F,P,sil,donor_info,style):
    g=M.geometry(F,P,extra_body=sil)
    a=l2.load(l2.KR1DX)
    raw,_=seg_1dx.syllables(fix_stem=False)
    groups={1:np.maximum.reduce([raw[k] for k in ('ma','ri','o')]),2:raw['amp'],
            3:np.maximum.reduce([raw[k] for k in ('ru','i','ji')])}
    lab=np.zeros(a.shape[:2],np.int16)
    for gid,mask in groups.items():lab[mask>.2]=gid
    _,idx=ndi.distance_transform_edt(lab==0,return_indices=True)
    owner=lab[tuple(idx)]
    ys,xs=np.mgrid[:a.shape[0],:a.shape[1]]
    support=(ys<100)&(xs<338)&(ys>idx[0])&(lab==0)
    navy=np.array([0,44,74])
    directions={1:np.array([90,-28,-50]),2:np.array([41,25,8]),3:np.array([41,33,-50])}
    colors=np.tile(np.array(P.navy,float),a.shape[:2]+(1,))
    for gid in groups:
        direction=directions[gid]
        progress=np.clip(((a[...,:3]-navy)*direction).sum(2)/(direction@direction),0,1)
        # Sparse face-edge pixels can be brighter than the dark underside; exclude them.
        progress=np.where(support,progress,0)
        colors[owner==gid]=_palette(style,gid)(progress[owner==gid])
    # Reconstruct shadow colors on their own support so letters/glow never bleed into the field.
    valid=support&(a[...,3]>220)
    _,nearest=ndi.distance_transform_edt(~valid,return_indices=True)
    colors=colors[tuple(nearest)]
    colors=ndi.gaussian_filter(colors,(.65,.65,0),mode='nearest')
    shape=g['F'].shape
    transform=(donor_info['donor_left'],donor_info['source_baseline'],donor_info['scale_x'],
               donor_info['scale_y'],donor_info['left'],donor_info['baseline'],shape)
    body_cov=(a[...,3]/255)*(ys<100)*(xs<338)
    body=layout.resample(body_cov,*transform,order=1)>.5
    rgb=np.stack([layout.resample(colors[...,c],*transform,order=1) for c in range(3)],2)
    # Change the lower part of the word only. RPG/3 and the upper outline keep their own geometry.
    _,nearest_face=ndi.distance_transform_edt(~g['F'],return_indices=True)
    hy,hx=np.mgrid[:shape[0],:shape[1]]
    lower=(hy>nearest_face[0])&(g['nlab']<=3)&(g['nlab']>0)
    g['O']=np.where(lower,g['O']&body,g['O'])
    g['E']=np.where(lower,body,g['E'])
    g['B']=g['O']|g['E']|sil
    shade_mask=lower&body&~g['F']
    np.savez_compressed(OUT/'underside.npz',donor_body=body,lower=lower,shade_mask=shade_mask,
                        rgb=rgb.astype(np.float32),body=g['B'])
    meta={'geometry_source':'1DX alpha silhouette, same affine as all seven main-title glyphs',
          'pattern_source':'1DX underside color progression, converted to measured Japanese 3DX palettes',
          'palette_rows':{'mario':[120,138],'amp':[128,142],'luigi':[118,136]},
          'gradient_mapping':'2D donor light field; no destination global-row cutoff',
          'color_field_smoothing_source_px':.65,'shade_pixels_hr':int(shade_mask.sum())}
    (OUT/'material_metrics.json').write_text(json.dumps(meta,indent=2)+'\n',encoding='utf8')
    return g,(rgb,shade_mask)
