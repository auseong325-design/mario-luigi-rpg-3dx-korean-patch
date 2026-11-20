from PIL import Image
import glob, os
for p in sorted(glob.glob(r"C:\AI-Projects\mario-luigi-rpg-3dx-korean-patch\work\img\logo2\out\*.png")):
    im = Image.open(p); print(os.path.basename(p), im.size, im.mode)
