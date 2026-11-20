"""Read-only SPBD audit; layout knowledge from upstream Switch-Toolbox PTCL_3DS.cs.
Only writes into this helper's directory; no source file is changed.
"""
from pathlib import Path
import struct,sys,json,hashlib,collections,math
ROOT=Path(__file__).resolve().parents[3]; sys.path.insert(0,str(ROOT/'scripts'))
import libtex3ds,libhb,lib3dx
from PIL import Image,ImageDraw
P=Path(__file__).parent;d=(P/'particle.ptcl').read_bytes()
u=lambda p:struct.unpack_from('<I',d,p)[0]
assert d[:4]==b'SPBD' and u(4)==51
original_compressed=lib3dx.romfs_path('HB/particle.ptcl.z').read_bytes()
assert libhb.unpack(original_compressed)==d,'audit input differs from original compressed particle'
count=u(8);names=u(16);texbase=u(20);texlen=u(24)
fmts={18:'ETC1A4',19:'ETC1',20:'HILO8',21:'L4',22:'A4',23:'L8',24:'A8',25:'LA4',26:'LA8',27:'RGBA5551',28:'RGBA4',29:'RGBA8',30:'RGB8',31:'RGB565'}
cstr=lambda off:d[off:d.index(b'\0',off)].decode('ascii')
unique={};uses=[];effects=[]
for i in range(count):
 r=struct.unpack_from('<7I',d,72+i*28)
 effect=cstr(names+r[2]); effects.append({'index':i,'name':effect,'emitters':r[4]})
 for e in range(r[4]):
  ep=u(r[5]+e*8); en=cstr(names+u(ep+56))
  for slot in range(2):
   p=ep+64+slot*124;w,h=struct.unpack_from('<HH',d,p)
   if not w or not h: continue
   fmt,size,offset=struct.unpack_from('<3I',d,p+108)
   assert fmt in fmts,(i,e,slot,fmt)
   fmtname=fmts[fmt];n=libtex3ds.data_size(fmtname,w,h)
   mips=max(1,u(p+20)); mip_sizes=[libtex3ds.data_size(fmtname,w>>lv,h>>lv) for lv in range(mips)]
   assert size==sum(mip_sizes),(i,e,slot,fmtname,w,h,size,mip_sizes,mips)
   assert 0<=offset and offset+size<=texlen
   t={'offset':offset,'absolute_offset':texbase+offset,'size':size,'base_size':n,'w':w,'h':h,'format':fmtname,'surface_format':fmt,'mipcount':mips}
   if offset in unique: assert all(unique[offset][k]==t[k] for k in t)
   else:unique[offset]=t
   uses.append({'effect':effect,'emitter':en,'slot':slot,'descriptor':p,'offset':offset})
items=sorted(unique.values(),key=lambda t:t['offset'])
dest=P/'particle_textures';dest.mkdir(exist_ok=True)
images=[]
mips_images=[]
for i,t in enumerate(items):
 t['index']=i;t['uses']=sum(x['offset']==t['offset'] for x in uses)
 raw=d[t['absolute_offset']:t['absolute_offset']+t['size']]
 t['sha256']=hashlib.sha256(raw).hexdigest()
 a=libtex3ds.decode(raw[:t['base_size']],t['format'],t['w'],t['h'],flip=False)
 im=Image.fromarray(a); im.save(dest/f't{i:03d}_{t["w"]}x{t["h"]}_{t["format"]}.png');images.append(im)
 p=t['base_size']
 for lv in range(1,t['mipcount']):
  w,h=t['w']>>lv,t['h']>>lv;n=libtex3ds.data_size(t['format'],w,h)
  mi=Image.fromarray(libtex3ds.decode(raw[p:p+n],t['format'],w,h,flip=False));p+=n
  mi.save(dest/f't{i:03d}_mip{lv}_{w}x{h}_{t["format"]}.png');mips_images.append((i,lv,mi))
 assert p==t['size']
intervals=[(t['offset'],t['offset']+t['size']) for t in items]
gaps=[];last=0
for a,b in intervals:
 assert a>=last
 if a>last:gaps.append((last,a))
 last=b
if last<texlen:gaps.append((last,texlen))
for page in range(math.ceil(len(items)/16)):
 subset=items[page*16:page*16+16];sheet=Image.new('RGB',(1280,1280),(30,30,30));draw=ImageDraw.Draw(sheet)
 for j,t in enumerate(subset):
  x=(j%4)*320;y=(j//4)*320;im=images[t['index']]
  # nearest neighbour enlarges small textures and fits large atlases.
  scale=min(288/im.width,275/im.height); view=im.resize((max(1,round(im.width*scale)),max(1,round(im.height*scale))),Image.Resampling.NEAREST)
  for cy in range(0,view.height,16):
   for cx in range(0,view.width,16):draw.rectangle((x+cx,y+30+cy,x+cx+15,y+30+cy+15),fill=(65,90,120) if ((cx//16+cy//16)%2) else(90,120,150))
  sheet.paste(view,(x,y+30),view)
  draw.text((x+2,y+3),f't{t["index"]:03d} {t["w"]}x{t["h"]} {t["format"]} @{t["offset"]:X}',fill='white')
 sheet.save(P/f'particle_sheet_{page:02d}.png')
ms=Image.new('RGB',(1120,560),(30,30,30));dr=ImageDraw.Draw(ms)
for j,(i,lv,im) in enumerate(mips_images):
 x=(j%4)*280;y=(j//4)*280;scale=min(256/im.width,240/im.height)
 view=im.resize((round(im.width*scale),round(im.height*scale)),Image.Resampling.NEAREST);ms.paste(view,(x,y+30),view)
 dr.text((x+2,y+3),f't{i:03d} mip{lv} {im.width}x{im.height}',fill='white')
ms.save(P/'particle_mips.png')
manifest={'source_sha256':hashlib.sha256(d).hexdigest(),'compressed_original_sha256':hashlib.sha256(original_compressed).hexdigest(),'original_unpack_exact_match':True,'version':u(4),'effect_sets':count,'emitters':sum(e['emitters'] for e in effects),'texture_refs':len(uses),'unique_textures':len(items),'extra_mips':len(mips_images),'texture_base':texbase,'texture_size':texlen,'decoded_bytes':sum(t['size'] for t in items),'gaps':gaps,'textures':items,'uses':uses,'effects':effects,'format_knowledge':'https://github.com/KillzXGaming/Switch-Toolbox/blob/master/File_Format_Library/FileFormats/Effects/PTCL_3DS.cs'}
(P/'particle_manifest.json').write_text(json.dumps(manifest,ensure_ascii=False,indent=2),encoding='utf-8')
print({k:v for k,v in manifest.items() if k not in ('textures','uses','effects')})
