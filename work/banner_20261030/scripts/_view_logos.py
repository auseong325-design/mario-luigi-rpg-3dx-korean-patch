import numpy as np
from PIL import Image
from pathlib import Path
E = Path(__file__).resolve().parent.parent / "extract"
P = Path(__file__).resolve().parent.parent / "preview"
P.mkdir(exist_ok=True)
rows = []
for n in ["3dx_COMMON_jp", "1dx_COMMON_kr"]:
    a = np.asarray(Image.open(E / f"{n}.png").convert("RGBA"), float)
    a = a[::-1]  # upright
    Image.fromarray(np.uint8(a)).save(P / f"{n}_upright.png")
    al = a[..., 3:] / 255
    bg = np.array([52, 52, 64], float)
    rows.append(np.uint8(a[..., :3] * al + bg * (1 - al)))
sheet = Image.fromarray(np.concatenate(rows, 0)).resize((768, 768), Image.NEAREST)
sheet.save(P / "jp_vs_1dxkr_upright_x3.png")
