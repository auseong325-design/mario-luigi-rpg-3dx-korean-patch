from pathlib import Path
import struct,sys,re,json
ROOT=Path(__file__).resolve().parents[3];sys.path.insert(0,str(ROOT/'scripts'))
import lib3dx
d=lib3dx.romfs_path('RO/MainMenu.cro').read_bytes();P=Path(__file__).parent
u=lambda p:struct.unpack_from('<I',d,p)[0]
targets={m.start():m.group().decode('ascii') for m in re.finditer(rb'(?:[EN]_(?:birinpa|vacuum_blk|starvaccine_[rgy]|mkiller|pazzle[1-4])|m_item_ev_all)\b',d)}
print('codeprefix',d[0x180:0x1d0].hex(' '));print('targets',targets)
# PC-relative ARM literal loads followed by adding PC to the loaded register.
xrefs=[]
segoff=u(0x80+18*4);segcnt=u(0x80+19*4);segments=[struct.unpack_from('<3I',d,segoff+i*12) for i in range(segcnt)]
reloff=u(0x80+42*4);relcnt=u(0x80+43*4);print('segments',segments,'internal relocation',hex(reloff),relcnt)
for i in range(relcnt):
 tag,typ,sym,addend=struct.unpack_from('<IBB2xI',d,reloff+i*12)
 target=segments[sym][0]+addend
 if target in targets:
  site=segments[tag&15][0]+(tag>>4)
  print('relxref',hex(site),hex(target),typ,targets[target]);xrefs.append({'ldr':site,'add':site,'literal':site,'target':target,'label':targets[target],'reltype':typ})
for p in range(0x180,0x26000,4):
 ins=u(p)
 if (ins&0x0e0f0000)==0x020f0000 and ((ins>>21)&15) in (2,4):
  v=ins&255;rot=((ins>>8)&15)*2;v=((v>>rot)|(v<<(32-rot)))&0xffffffff if rot else v
  target=p+8+v*(1 if ((ins>>21)&15)==4 else -1)
  if target in targets: print('ADR',hex(p),hex(ins),hex(target),targets[target]);xrefs.append({'ldr':p,'add':p,'literal':p,'target':target,'label':targets[target],'adr':True})
 if (ins&0x0f7f0000)!=0x051f0000:continue
 rd=(ins>>12)&15;lp=p+8+(ins&4095)*(1 if ins&0x00800000 else -1)
 if not 0<=lp<len(d)-4:continue
 value=u(lp)
 if value>=0x80000000:value-=0x100000000
 for q in range(p+4,min(p+40,0x26000),4):
  add=u(q)
  if (add&0x0fe000f0)==0x00800000 and ((add>>16)&15)==15 and (add&15)==rd:
   target=q+8+value
   if target in targets:
    print('xref',hex(p),hex(q),'literal',hex(lp),hex(target),targets[target]);xrefs.append({'ldr':p,'add':q,'literal':lp,'target':target,'label':targets[target]})
   break
(P/'item_xrefs.json').write_text(json.dumps(xrefs,indent=2),encoding='utf-8')
for x in xrefs:
 p=x['ldr'];print('CONTEXT',x)
 for q in range(max(0x180,p-32),min(p+80,len(d)),4):print(hex(q),hex(u(q)))
print('EVENTTABLE')
relmap={}
for i in range(relcnt):
 tag,typ,sym,addend=struct.unpack_from('<IBB2xI',d,reloff+i*12)
 site=segments[tag&15][0]+(tag>>4);target=segments[sym][0]+addend
 if 0x24b00<=site<0x24f00:
  try: value=d[target:d.index(b'\0',target)].decode('ascii')
  except (UnicodeError,ValueError):value=hex(target)
  relmap[site]=value
for p in range(0x24b6c,0x24efc,20):
 vals=struct.unpack_from('<5I',d,p);print(hex(p),[relmap.get(p+k*4,hex(v)) for k,v in enumerate(vals)])
