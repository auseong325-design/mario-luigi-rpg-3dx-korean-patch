"""Read-only colour analysis of the original R; exports numeric reconstruction parameters.
The raster repair itself is performed in Affinity by affinity_refine_R.js.
"""
from pathlib import Path
import json
import numpy as np
from PIL import Image

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
SOURCE = ROOT / 'work/img/kj_parts_20261009/source_original_JP.png'


def main():
    rgb = np.asarray(Image.open(SOURCE).convert('RGB')).astype(float)
    yy, xx = np.mgrid[:208, :400]
    mask = ((xx >= 216) & (xx <= 251) & (yy >= 150) & (yy <= 195)
            & (rgb[..., 1] > 155) & (rgb[..., 2] < 75)
            & (rgb[..., 0] + rgb[..., 1] > 230))
    # Trim shape edges and highlight pixels before fitting the original material.
    from scipy import ndimage as ndi
    mask &= ndi.distance_transform_edt(mask) >= 2
    y, x = yy[mask], xx[mask]
    col = rgb[mask]
    row_terms = np.column_stack([np.ones(len(y)), (y - 175) / 25,
                               ((y - 175) / 25) ** 2, ((y - 175) / 25) ** 3])
    best = None
    for deg in np.arange(37, 68, 1):
        angle = np.deg2rad(deg)
        for period in np.arange(2.3, 4.11, .1):
            phase = 2 * np.pi * (x * np.cos(angle) + y * np.sin(angle)) / period
            terms = np.column_stack([row_terms, np.sin(phase), np.cos(phase)])
            coeff = np.linalg.lstsq(terms, col, rcond=None)[0]
            err = np.mean((terms @ coeff - col) ** 2)
            if best is None or err < best[0]:
                best = err, float(deg), float(period), coeff
    err, deg, period, coeff = best
    # Per-row fit with the globally fitted hatch wave, preserving the measured
    # original nonlinear yellow-to-green gradient rather than a new palette.
    theta = np.deg2rad(deg)
    rows = []
    for cy in range(140, 204):
        near = abs(y - cy) <= 3
        py = y[near] - cy
        phase = 2 * np.pi * (x[near] * np.cos(theta) + y[near] * np.sin(theta)) / period
        if near.sum() >= 12:
            terms = np.column_stack([np.ones(near.sum()), py, np.sin(phase), np.cos(phase)])
            cc = np.linalg.lstsq(terms, col[near], rcond=None)[0]
            rows.append(dict(y=cy, base=cc[0].tolist(), sin=cc[2].tolist(), cos=cc[3].tolist()))
        else:
            z = (cy - 175) / 25
            rows.append(dict(y=cy, base=(np.array([1, z, z*z, z*z*z]) @ coeff[:4]).tolist(),
                             sin=coeff[4].tolist(), cos=coeff[5].tolist()))
    data = dict(source=str(SOURCE),samples=int(mask.sum()),hatch_angle=deg,hatch_period=period,
                colour_rmse=float(np.sqrt(err)),row_fit=rows)
    (HERE / 'material_fit.json').write_text(json.dumps(data,indent=2),encoding='utf8')
    print(json.dumps({k:v for k,v in data.items() if k!='row_fit'},indent=2))


if __name__ == '__main__':
    main()
