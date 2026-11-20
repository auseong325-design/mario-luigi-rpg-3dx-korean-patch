"""Re-render the latest main-title word (title_layout_20261008/build_title.py recipe) with toggles.

render(glow, silhouettes) -> float RGBA 512x256 in the title texture frame (title_down applied).
With glow=True, silhouettes=True and q4 it must equal the installed title_logo_JP_bottom.png.
"""
from pathlib import Path
import sys
import numpy as np
ROOT=Path(__file__).resolve().parents[3];OUT=Path(__file__).parent
for d in ['work/img/logo2','work/img/title_layout_20261008','work/img/title_1dx_shapes_20261008','work/img/title_lower_shading_20261008']:
    sys.path.insert(0,str(ROOT/d))
import l2,build_bottom as BB,model as M,build_title as BT,donor_layout,material
HR=l2.HR

def render(glow=True,silhouettes=True,debug_dir=None):
    C=BT.CONFIG
    original,F_jp,style,sil_jp=BB.jp_inputs()
    shape=(256*HR,512*HR)
    placed,donor_info=donor_layout.masks(shape,x_left=C['x_left'],donor_masks=material.donors())
    F={1:placed['ma']|placed['ri']|placed['o'],2:placed['amp'],3:placed['ru']|placed['i']|placed['ji']}
    right=BT.box(F[3],HR)[2];rpg_dx=right-273.75
    for g in (4,5,6):F[g]=l2.shift_hr(F_jp[g],round(rpg_dx*HR),0)
    P=M.Params(glow=glow)
    O_jp=l2.dist_out(np.any(list(F_jp.values()),axis=0))<=P.r_o
    O_kr=l2.dist_out(np.any(list(F.values()),axis=0))<=P.r_o
    targets=[]
    for key in C['silhouette_syllables']:
        columns=np.nonzero(placed[key].any(axis=0))[0]
        tx,_=BB.blob_top(placed[key],columns.min()/HR,(columns.max()+1)/HR);targets.append(tx)
    sil,_=BB.move_silhouettes(sil_jp,O_jp,None,O_kr,targets)
    if not silhouettes:sil=np.zeros_like(sil)
    top_small=np.median([np.nonzero(placed[k].any(axis=1))[0].min() for k in ('ri','i','ji')])/HR
    ys=np.arange(256,dtype=float)
    src=np.clip(79+(ys-top_small)*49/(127.5-top_small),0,255)
    rs={k:dict(style[k]) for k in ('face','ext','rim')}
    head_top=min(np.nonzero(placed[k].any(axis=1))[0].min() for k in ('ma','ru'))/HR
    ramp=np.clip((top_small-ys)/max(top_small-head_top,1),0,1)
    for g in (1,3):
        tab=style['face'][g];face=np.stack([np.interp(src,ys,tab[:,c]) for c in range(3)],axis=1)
        rs['face'][g]=face+(255-face)*(BB.P_LAY['head_light'][g]*ramp)[:,None]
    amp_box=BT.box(F[2],HR);jp_amp_box=BT.box(F_jp[2],HR)
    amp_rows=jp_amp_box[1]+(ys-amp_box[1])*(jp_amp_box[3]-jp_amp_box[1])/(amp_box[3]-amp_box[1])
    rs['face'][2]=np.stack([np.interp(amp_rows,ys,style['face'][2][:,c]) for c in range(3)],axis=1)
    ext_rows=ys-(amp_box[3]-jp_amp_box[3])
    rs['ext'][2]=np.stack([np.interp(ext_rows,ys,style['ext'][2][:,c]) for c in range(3)],axis=1)
    geo,ext_override=material.geometry_and_shading(F,P,sil,donor_info,style,output_dir=debug_dir or OUT/'debug')
    bottom,geo=M.render(F,P,rs,extra_body=sil,geo=geo,ext_override=ext_override)
    accepted=l2.load(ROOT/'work/img/logo_assembly_contours_20261008/title_logo_JP_bottom_before.png')
    accepted=BT.shift_rgba(accepted,0,-C['title_down'])
    for group in (4,5,6):
        core=l2.down(F[group].astype(float))>.999
        bottom[core]=accepted[core]
    return BT.shift_rgba(bottom,0,C['title_down']),rpg_dx

if __name__=='__main__':
    (OUT/'debug').mkdir(exist_ok=True)
    b,_=render(True,True)
    ref=l2.load(ROOT/'work/img/logo2/out/title_logo_JP_bottom.png')
    inst=l2.load(ROOT/'work/img/title_layout_20261008/title_logo_JP_bottom.png')
    q=l2.q4(b);print('vs logo2/out max diff',np.abs(q-ref).max(),'vs title_layout',np.abs(q-inst).max())
