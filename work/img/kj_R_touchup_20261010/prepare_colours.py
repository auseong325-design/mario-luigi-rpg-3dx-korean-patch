"""Measure original face colour and a smooth continuation field; writes numbers only.
Affinity's native RGBA writer applies these colours to the corrected geometry.
"""
from pathlib import Path
import json
import numpy as np
from PIL import Image
from scipy import ndimage as ndi
from scipy.sparse import lil_matrix
from scipy.sparse.linalg import spsolve
from shapely.geometry import Polygon, Point

HERE=Path(__file__).resolve().parent
ROOT=HERE.parents[2]
FACE=[[208.05,150.5],[235.4,147],[250.6,156.1],[247.5,171.3],
      [238.2,177.7],[253.3,189.1],[236.3,197.4],[223.7,181],
      [223.9,194.1],[213.15,194.0]]


def main():
    image=np.asarray(Image.open(ROOT/'work/img/kj_parts_20261009/source_original_JP.png').convert('RGB')).astype(float)
    rgb=image[140:203,201:261]
    yy,xx=np.mgrid[140:203,201:261]
    core=(rgb[...,1]>155)&(rgb[...,2]<60)&(rgb[...,0]+rgb[...,1]>230)
    core&=(xx>=216)&(xx<=251)&(yy>=150)&(yy<=195)
    core&=ndi.distance_transform_edt(core)>=1.75
    x,y=xx[core],yy[core]
    col=rgb[core]
    z=(y-175)/25
    best=None
    for deg in np.arange(58,60.01,.1):
        th=np.deg2rad(deg)
        for period in np.arange(3.61,3.81,.01):
            ph=2*np.pi*(x*np.cos(th)+y*np.sin(th))/period
            terms=np.column_stack([np.ones(len(x)),z,z*z,z*z*z,z**4,
                                   np.sin(ph),np.cos(ph),z*np.sin(ph),z*np.cos(ph)])
            coeff=np.linalg.lstsq(terms,col,rcond=None)[0]
            error=np.mean((terms@coeff-col)**2)
            if best is None or error<best[0]:best=error,float(deg),float(period),coeff
    error,deg,period,coeff=best
    zall=(yy-175)/25
    th=np.deg2rad(deg)
    phase=2*np.pi*(xx*np.cos(th)+yy*np.sin(th))/period
    terms=np.stack([np.ones(xx.shape),zall,zall*zall,zall**3,zall**4,
                    np.sin(phase),np.cos(phase),zall*np.sin(phase),zall*np.cos(phase)],2)
    # Measured local row colours keep the lower stem green. A high-order global
    # polynomial otherwise curls back toward yellow at the sparse lower edge.
    previous=json.loads((ROOT/'work/img/kj_R_polish_20261010/material_fit.json').read_text())
    base=ndi.gaussian_filter1d(np.asarray([r['base'] for r in previous['row_fit']]),1.4,axis=0)
    sine=ndi.gaussian_filter1d(np.asarray([r['sin'] for r in previous['row_fit']]),1.4,axis=0)
    cosine=ndi.gaussian_filter1d(np.asarray([r['cos'] for r in previous['row_fit']]),1.4,axis=0)
    deg,period=previous['hatch_angle'],previous['hatch_period']
    phase=2*np.pi*(xx*np.cos(np.deg2rad(deg))+yy*np.sin(np.deg2rad(deg)))/period
    fitted=base[:63,None,:]+sine[:63,None,:]*np.sin(phase)[...,None]+cosine[:63,None,:]*np.cos(phase)[...,None]
    error=float(np.mean((fitted[core]-col)**2))
    poly=Polygon(FACE)
    domain=np.array([[poly.contains(Point(x+.5,y+.5)) for x in range(201,261)] for y in range(140,203)])
    # The dark R counter is outside the surface domain.
    domain&=~((xx>=223)&(xx<=233)&(yy>=157)&(yy<=171)&(rgb.max(2)<150))
    trust=domain&(ndi.distance_transform_edt(domain)>=1.8)&(rgb[...,1]>145)&(rgb[...,2]<60)
    # The old Japanese word and the previous repair contaminate this zone.
    trust&=~((xx<=215)&(yy>=160))
    trust&=~((xx<=225)&(yy>=184))
    unknown=domain&~trust
    ids=np.full(domain.shape,-1,int)
    ids[unknown]=np.arange(unknown.sum())
    mat=lil_matrix((int(unknown.sum()),int(unknown.sum())))
    rhs=np.zeros((int(unknown.sum()),3))
    residual=rgb-fitted
    for iy,ix in zip(*np.nonzero(unknown)):
        i=ids[iy,ix]
        neighbours=[(iy+dy,ix+dx) for dy,dx in [(0,1),(0,-1),(1,0),(-1,0)]
                    if 0<=iy+dy<63 and 0<=ix+dx<60 and domain[iy+dy,ix+dx]]
        mat[i,i]=len(neighbours)
        for ny,nx in neighbours:
            if unknown[ny,nx]:mat[i,ids[ny,nx]]=-1
            else:rhs[i]+=residual[ny,nx]
    solved=spsolve(mat.tocsr(),rhs)
    correction=np.zeros_like(rgb)
    correction[trust]=residual[trust]
    correction[unknown]=solved
    field=np.clip(fitted+correction,0,255)
    field[trust]=rgb[trust]
    data=dict(face_contour=FACE,origin=[201,140],size=[60,63],
              surface_colours=np.round(field,5).tolist(),trusted=np.asarray(trust,int).tolist(),
              material=dict(angle=deg,period=period,raw_colour_rmse=float(np.sqrt(error)),
                            trusted_original_face_pixels=int(trust.sum()),
                            smoothly_continued_face_pixels=int(unknown.sum()),
                            method='smoothed measured row gradient and hatch plus harmonic original-colour residual extension'))
    (HERE/'colour_field.json').write_text(json.dumps(data,separators=(',',':')),encoding='utf8')
    print(json.dumps(data['material'],indent=2))


if __name__=='__main__':main()
