"""Decode the read-only ROM afresh, and measure cutout/occlusion geometry.

Writes source PNGs and numeric masks, not a retouched R. Affinity performs the
actual cutout and stacks the reconstruction beneath the original pixels.
"""
from pathlib import Path
import sys,json,hashlib
import numpy as np
from PIL import Image
from scipy import ndimage as ndi
from scipy.optimize import minimize
import cv2
from shapely.geometry import Polygon,Point
from shapely import affinity

HERE=Path(__file__).resolve().parent
ROOT=HERE.parents[2]
sys.path.insert(0,str(ROOT/'scripts'))
import lib3dx,lytimg


def main():
    rom=lib3dx.romfs_path('Lyt/JP/MLyt.dat')
    original=rom.read_bytes()
    entries=lib3dx.read_bg4(original)[1]
    entry=next(e for e in entries if e.name=='MENU_FILE_LOAD_JP_ja')
    sarc=lib3dx.bg4_plain(entry)
    pieces={Path(n).stem:lytimg.bflim_to_rgba(sarc[a:b]) for n,a,b in lytimg.sarc_list(sarc) if Path(n).stem in ['LOAD_GAME_IMG_KJ_L_00_JP_ja','LOAD_GAME_IMG_KJ_R_00_JP_ja']}
    full=np.concatenate([pieces[n] for n in ['LOAD_GAME_IMG_KJ_L_00_JP_ja','LOAD_GAME_IMG_KJ_R_00_JP_ja']],1)
    Image.fromarray(full).save(HERE/'source_original_JP.png')
    c=full[140:203,201:261,:3].astype(float)
    Image.fromarray(c.astype('uint8')).save(HERE/'source_R_region.png')
    yy,xx=np.mgrid[140:203,201:261]
    bright=(c.max(2)>=150)&(c.min(2)<=225)
    labels,_=ndi.label(bright)
    face=labels==labels[170-140,215-201]
    inner=ndi.binary_fill_holes(face)
    jp_poly=cv2.findContours(inner.astype('uint8'),cv2.RETR_EXTERNAL,cv2.CHAIN_APPROX_SIMPLE)[0][0][:,0,:].astype(float)
    jp_poly+=np.array([201.5,140.5])
    ref=Image.open(HERE/'reference_1dx.png').convert('RGB')
    r=np.asarray(ref).astype(float)
    ref_crop=r[90:190,85:183]
    gold=(ref_crop[...,0]>170)&(ref_crop[...,1]>100)&(ref_crop[...,2]<180)
    lab,_=ndi.label(gold)
    gold=lab==lab[135-90,110-85]
    gold=ndi.binary_fill_holes(gold)
    # Fit only silhouettes, never transfer the reference's gold material.
    target=inner.astype(float)
    def projected(p):
        sx,sy,angle,tx,ty=p
        th=np.deg2rad(angle)
        forward=np.array([[sx*np.cos(th),-sy*np.sin(th)],[sx*np.sin(th),sy*np.cos(th)]])
        inv=np.linalg.inv(forward)
        xy=inv@(np.stack([xx-201,yy-140],0).reshape(2,-1)-np.array([tx,ty])[:,None])
        return ndi.map_coordinates(gold.astype(float),[xy[1],xy[0]],order=1,mode='constant').reshape(63,60)
    def loss(p):
        m=projected(p)
        return np.mean((m-target)**2)
    result=minimize(loss,[.66,.62,0,3,5],method='Powell',bounds=[(.45,.95),(.45,.9),(-8,8),(-10,15),(-10,20)],options={'maxiter':180})
    fit=projected(result.x)
    iou=float(((fit>.5)&inner).sum()/((fit>.5)|inner).sum())
    # Reference face contour, fitted to JP. Straight edges are simplified only
    # for the reconstruction underneath the source; the source face stays exact.
    contours=cv2.findContours(gold.astype('uint8'),cv2.RETR_EXTERNAL,cv2.CHAIN_APPROX_SIMPLE)[0]
    cont=max(contours,key=cv2.contourArea)
    cont=cv2.approxPolyDP(cont,2.5,True)[:,0,:].astype(float)+.5
    sx,sy,angle,tx,ty=result.x
    th=np.deg2rad(angle);matrix=np.array([[sx*np.cos(th),-sy*np.sin(th)],[sx*np.sin(th),sy*np.cos(th)]])
    ref_points=cont@matrix.T+np.array([201+tx,140+ty])
    ref_poly=Polygon(ref_points).buffer(0)
    jp_shape=Polygon(jp_poly).buffer(0)
    # Original outline thickness measured on the clear top/left edge is 5.5 px.
    # Mitered reference corners continue the covered straight stem/foot.
    ref_outer=ref_poly.buffer(5.5,join_style=2,mitre_limit=2)
    # Trace the source's already-visible outer straight segments. Dilating its
    # staircase pixels with miter joins makes false square spikes beside P.
    jp_outer=Polygon([[202.4,145.9],[234.6,141.2],[258.1,154.7],
                      [253.6,173.2],[244.1,177.3],[260.0,189.4],
                      [239.2,202.4],[233.0,200.5],[209.0,200.3],[202.6,193.6]])
    ref_outer=ref_outer.intersection(jp_outer.buffer(1.0))
    covered=(xx>=244)|((yy<=147)&(xx>=217))|((xx<=226)&(yy>=187))
    # Every visible original coloured face, rim and dark counter remains source.
    # Include the original subpixel green/cream rim just outside the bright
    # component; these edge pixels must not be mistaken for white matte.
    protected=ndi.binary_dilation(inner,iterations=1)
    covered&=~protected
    # The Jr. white rim reaches two pixels farther than its orange face. It
    # must be removed even when it touches the R's protective edge band.
    covered|=(xx<=210)&(yy>=156)&~inner
    alpha=np.zeros((63,60))
    N=8
    for ly in range(63):
        for lx in range(60):
            # Reference governs covered stem/foot; source governs other edges.
            poly=ref_outer if covered[ly,lx] and xx[ly,lx]<=226 and yy[ly,lx]>=156 else jp_outer
            alpha[ly,lx]=sum(poly.contains(Point(xx[ly,lx]+(sx+.5)/N,yy[ly,lx]+(sy+.5)/N)) for sy in range(N) for sx in range(N))/(N*N)
    alpha[inner]=1
    # A broad band permits copying every true visible edge from the source;
    # colour discrimination excludes pink/blue stars and neighbouring glyphs.
    near=ndi.distance_transform_edt(~inner)<8.0
    dark=(c.max(2)<150)
    body=np.array([[jp_outer.buffer(1).contains(Point(x+.5,y+.5)) for x in range(201,261)] for y in range(140,203)])
    vis=(~covered)&near&body&~((xx>=244)&~protected)
    original_alpha=np.clip(1-c[...,1]/255,0,1)
    original_alpha=np.where(protected|((c[...,1]<=8)&(c[...,2]<=8)),1,original_alpha)
    original_alpha=np.where(vis,original_alpha,0)
    original_alpha[inner]=1
    # No donor colours come from old repaired R assets.
    clean_dark=(c[...,0]>=45)&(c[...,0]<110)&(c[...,1]<=8)&(c[...,2]<=8)&~covered&~inner&(alpha>.99)
    indices=ndi.distance_transform_edt(~clean_dark,return_indices=True)[1]
    donor=c[indices[0],indices[1]]
    data=dict(origin=[201,140],size=[60,63],original_alpha=original_alpha.tolist(),
              restoration_alpha=np.where(covered,alpha,0).tolist(),
              restoration_rgb=donor.astype(int).tolist(),original_inner=inner.astype(int).tolist(),
              covered=covered.astype(int).tolist(),reference_face_points=ref_points.tolist(),
              reference_fit=dict(parameters=result.x.tolist(),face_iou=iou),
              original_visible_face_rim_counter_pixels=int(inner.sum()),
              source_ROM=str(rom),source_ROM_sha256=hashlib.sha256(original).hexdigest())
    (HERE/'cutout_geometry.json').write_text(json.dumps(data,separators=(',',':')),encoding='utf8')
    print(json.dumps({k:data[k] for k in ['reference_fit','original_visible_face_rim_counter_pixels','source_ROM','source_ROM_sha256']},indent=2))


if __name__=='__main__':main()

