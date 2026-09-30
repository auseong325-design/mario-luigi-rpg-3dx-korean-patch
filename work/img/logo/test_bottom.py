"""Validate the layer model: re-render the Japanese bottom logo from its own face mask."""
import sys, pickle
from pathlib import Path
import numpy as np
from scipy import ndimage as ndi
sys.path.insert(0, str(Path(__file__).parent))
import logo_lib as L

ROOT = Path(__file__).resolve().parents[3]
OUTD = ROOT / "work/img/logo/fit"
OUTD.mkdir(parents=True, exist_ok=True)
a = L.load(ROOT / "work/img/fmdl/3DX/fmd_title_JP_ja/title_logo_JP_bottom.png")
B1, glow = L.body_of(a)
cov = L.face_cov(a, glow)
F = L.up_hr(cov)
lab, n = ndi.label(F)
sizes = ndi.sum(F, lab, range(1, n + 1))
F = np.isin(lab, 1 + np.nonzero(sizes >= 10 * L.HR * L.HR)[0])
H, W = F.shape
yy, xx = np.mgrid[0:H, 0:W] / L.HR
el = np.zeros((H, W), int)
el[(xx < 145)] = 1
el[(xx >= 145) & (xx < 167) & (yy > 100)] = 2
el[(xx >= 145) & (xx < 167) & (yy <= 100)] = 1
el[(xx >= 167) & (xx < 275.5)] = 3
el[(xx >= 275.5) & (xx < 380)] = 4
el[(xx >= 380)] = 5
lab_hr = np.where(F, el, 0)
region = np.zeros(a.shape[:2], bool)
region[20:170, 25:400] = True
# body parts that are not letter outlines (Mario / Luigi silhouettes): original body minus model
st0 = L.fit_body(a, F, lab_hr, region)
K, _ = L.sweep(F, lab_hr, st0.sx)
Bm = L.body(F, K, st0.r_o, st0.D, st0.r_e)
Bo = L.up_hr(B1)
extra = Bo & ~ndi.binary_dilation(Bm, iterations=2 * L.HR)
lab2, n2 = ndi.label(extra)
sz = ndi.sum(extra, lab2, range(1, n2 + 1))
big = 1 + np.nonzero(sz >= 60 * L.HR * L.HR)[0]
print("extra comps kept (1x px)", [int(sz[i - 1] / L.HR ** 2) for i in big])
seed = np.isin(lab2, big)
Bx = Bo & ndi.binary_dilation(seed, iterations=3 * L.HR) & ~Bm | seed
Bx = Bo & (ndi.binary_dilation(seed, iterations=3 * L.HR))
st = L.fit_style(a, F, lab_hr, [1, 2, 3, 4, 5], region=region, B_extra_hr=Bx)
out, B_hr = L.render(a.shape[:2], F, lab_hr, st, {1: 1, 2: 2, 3: 3, 4: 4, 5: 5}, B_extra_hr=Bx)
L.save(out, OUTD / "rerender_bottom.png")
d = np.abs(out - a)
m = region
print("mean abs err RGB (alpha>0):", d[..., :3][(a[..., 3] > 0) & m].mean().round(2), "alpha:", d[..., 3][m].mean().round(2))
del st.B_model
pickle.dump(st, open(OUTD / "style_bottom.pkl", "wb"))
np.save(OUTD / "extra_bottom.npy", Bx)
np.save(OUTD / "F_bottom.npy", F)
np.save(OUTD / "lab_bottom.npy", lab_hr)
