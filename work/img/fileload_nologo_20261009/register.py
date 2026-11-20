import cv2,numpy as np,json
from PIL import Image
g=np.asarray(Image.open('original_jp.png').convert('RGB')).astype(np.float32)
b=np.asarray(Image.open('bowser_boxart.png').convert('RGBA')).astype(np.float32)
bw=b[...,:3]*(b[...,3:]/255)+255*(1-b[...,3:]/255)
G=cv2.cvtColor(g.astype(np.uint8),cv2.COLOR_RGB2GRAY);B=cv2.cvtColor(bw.astype(np.uint8),cv2.COLOR_RGB2GRAY)
mask=np.zeros_like(G);mask[95:,260:]=255  # logo-free Bowser area
sift=cv2.SIFT_create()
Gu=cv2.resize(G,None,fx=3,fy=3,interpolation=cv2.INTER_CUBIC);mu=cv2.resize(mask,None,fx=3,fy=3,interpolation=cv2.INTER_NEAREST)
k1,d1=sift.detectAndCompute(B,None);k2,d2=sift.detectAndCompute(Gu,mu)
m=cv2.BFMatcher().knnMatch(d1,d2,k=2);good=[a for a,c in m if a.distance<.75*c.distance]
src=np.float32([k1[a.queryIdx].pt for a in good]);dst=np.float32([k2[a.trainIdx].pt for a in good])/3
M,inl=cv2.estimateAffinePartial2D(src,dst,method=cv2.RANSAC,ransacReprojThreshold=1.5)
print(len(good),int(inl.sum()),M)
# ECC refine (affine) on logo-free region
warp=M.astype(np.float32)
crit=(cv2.TERM_CRITERIA_EPS|cv2.TERM_CRITERIA_COUNT,500,1e-7)
Bs=cv2.GaussianBlur(B,(0,0),1.2)
try:
    cc,warp2=cv2.findTransformECC(G.astype(np.float32),Bs.astype(np.float32),cv2.invertAffineTransform(warp),cv2.MOTION_AFFINE,crit,mask,1)
    warp2=cv2.invertAffineTransform(warp2);print('ecc',cc,warp2)
except Exception as e: print('ecc fail',e);warp2=warp
np.save('warp.npy',warp2)
