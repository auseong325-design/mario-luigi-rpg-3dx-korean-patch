import cv2,numpy as np
from PIL import Image
from scipy.optimize import minimize
g=np.asarray(Image.open('original_jp.png').convert('RGB')).astype(np.float32)
b=np.asarray(Image.open('bowser_boxart.png').convert('RGBA')).astype(np.float32)
bw=b[...,:3]*(b[...,3:]/255)+255*(1-b[...,3:]/255)
def warp(img,M,S=3):
    A=np.diag([S,S,1.])@np.vstack([M,[0,0,1]])
    w=cv2.warpAffine(img,A[:2],(400*S,208*S),flags=cv2.INTER_LINEAR,borderMode=cv2.BORDER_CONSTANT,borderValue=(255,255,255))
    return cv2.resize(w,(400,208),interpolation=cv2.INTER_AREA)
sl=(slice(95,208),slice(265,400))
def P(p):
    s,r,tx,ty=p;return np.array([[s*np.cos(r),-s*np.sin(r),tx],[s*np.sin(r),s*np.cos(r),ty]])
def cost(p):
    W=cv2.GaussianBlur(warp(bw,P(p)),(0,0),.7);return np.abs(W-cv2.GaussianBlur(g,(0,0),.7))[sl].mean()
M0=np.load('warp.npy');s0=np.hypot(M0[0,0],M0[1,0]);r0=np.arctan2(M0[1,0],M0[0,0])
p0=[s0,r0,M0[0,2],M0[1,2]];print('sift',cost(p0))
res=minimize(cost,p0,method='Nelder-Mead',options=dict(xatol=1e-5,fatol=1e-4,maxiter=600,initial_simplex=np.array(p0)+np.diag([.004,.01,1,1]).tolist()+[[0]*4] if False else None))
print(res.x,res.fun);np.save('warp_best.npy',P(res.x))
