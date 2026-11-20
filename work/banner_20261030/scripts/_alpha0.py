import numpy as np
from PIL import Image
from pathlib import Path
from collections import Counter
W = Path(__file__).resolve().parent.parent
E = W / "extract"
for n in ["3dx_COMMON_jp", "1dx_COMMON_kr", "title_kr_title_logo_JP_top", "title_kr_title_logo_JP_bottom", "title_jp_title_logo_JP_top"]:
    a = np.asarray(Image.open(E / f"{n}.png").convert("RGBA"))
    z = a[a[..., 3] == 0][:, :3]
    c = Counter(map(tuple, z))
    print(n, "alpha0 px", len(z), "top rgb", c.most_common(4))
    lo = a[(a[..., 3] > 0) & (a[..., 3] < 60)][:, :3]
    c2 = Counter(map(tuple, lo))
    print("   low-alpha rgb", c2.most_common(4))
