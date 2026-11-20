from pathlib import Path
import sys,struct,json,re
ROOT=Path(__file__).resolve().parents[3];sys.path.insert(0,str(ROOT/'scripts'))
import lib3dx,libobj
P=Path(__file__).parent
obj=libobj.ObjDat('3DX','Menu');od=obj.objs['m_item_ev_all'];af=obj.anim(od.anim)
print('object',od,'anim',af.anim_num,'frames',len(af.frames),'anims',af.anims)
data=lib3dx.romfs_path('DB/DB.dat').read_bytes();print('DB',data[:32].hex(' '),len(data))
if data[:4]==b'BG4\0':
 _,ent=lib3dx.read_bg4(data)
 for e in ent:
  if e.size_flag:continue
  plain=lib3dx.bg4_plain(e);print('DBent',e.name,len(plain),plain[:32].hex(' '))
  if any(x in e.name.lower() for x in ('item','event')):
   (P/('DB_'+e.name.replace('/','_')+'.bin')).write_bytes(plain)
   print('strings',[(m.start(),m.group().decode('ascii')) for m in re.finditer(rb'[A-Za-z_][A-Za-z0-9_]{3,}',plain)])
cro=lib3dx.romfs_path('RO/MainMenu.cro').read_bytes()
for m in re.finditer(rb'[A-Za-z_][A-Za-z0-9_]{3,}',cro):
 s=m.group().decode('ascii')
 if any(x in s.lower() for x in ('birin','vaccine','mkiller','vacuum','pazzle','evitem','eventitem','m_item_ev')): print('CROstr',hex(m.start()),s)
menu=json.loads((ROOT/'text/jp/Menu.json').read_text(encoding='utf-8'))
rows=[m for m in menu['messages'] if m.get('label') and 'EventItem' in m['label']]
(P/'item_event_messages.json').write_text(json.dumps(rows,ensure_ascii=False,indent=2),encoding='utf-8')
print('eventmsg',len(rows))
for off in [0x27d70,0x27dd0,0x27e50,0x27ec0,0x27fa0,0x27fd8,0x28010,0x26aa0]:
 print('CROctx',hex(off))
 for p in range(off,off+144,16):
  b=cro[p:p+16];print(f'{p:08X}',b.hex(' '),''.join(chr(x) if 32<=x<127 else '.' for x in b),struct.unpack('<4I',b))
print('CROhdr',cro[:256].hex(' '))
for target in [0x27de4,0x27df0,0x27ed0,0x27ee0,0x27fb8,0x27fc8,0x27fe8,0x27ff4,0x28030,0x28040,0x1df80]:
 for delta in [0,0x180]:
  pattern=struct.pack('<I',target-delta)
  hits=[m.start() for m in re.finditer(re.escape(pattern),cro)]
  print('CROptr',hex(target),'minus',hex(delta),list(map(hex,hits)))
try:
 import capstone
 print('capstone available',capstone.__version__)
except ImportError:print('capstone absent')
print('DBoffsets',struct.unpack_from('<16I',data))
pairs=[]
for f in [22,24,26,28,30,34,36,38,40,42,44]:
 even=af.frames[f];odd=af.frames[f+1]
 a=[af.parts[even.first_part+k] for k in range(even.total_parts)]
 b=[af.parts[odd.first_part+k] for k in range(odd.total_parts)]
 identical_regions=[(p.buf,p.size,p.flip) for p in a]==[(p.buf,p.size,p.flip) for p in b]
 pairs.append({'even':f,'odd':f+1,'shared_pixel_regions':identical_regions,'even_parts':[(p.buf,p.size,p.x,p.y) for p in a],'odd_parts':[(p.buf,p.size,p.x,p.y) for p in b]})
print('ICONPAIRS',pairs)
(P/'item_icon_pairs.json').write_text(json.dumps(pairs,indent=2),encoding='utf-8')
