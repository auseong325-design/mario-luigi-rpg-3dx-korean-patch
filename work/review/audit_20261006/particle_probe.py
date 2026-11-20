from pathlib import Path
import struct,re,sys,json
ROOT=Path(__file__).resolve().parents[3]
sys.path.insert(0,str(ROOT/'scripts'))
d=(Path(__file__).parent/'particle.ptcl').read_bytes()
print('size',len(d),hex(len(d)))
for p in range(0,512,16):
 b=d[p:p+16]
 print(f'{p:08x}',b.hex(' '), ''.join(chr(x) if 32<=x<127 else '.' for x in b), struct.unpack('<4I',b))
records=[struct.unpack_from('<7I',d,0x48+i*28) for i in range(322)]
print('effect counts',[r[4] for r in records[:20]],sum(r[4] for r in records),records[-3:])
print('record starts', [hex(r[5]) for r in records[:20]])
for off in [0x2380,0x109b00,0x109b00+1360,0x118530,0x11a000,0x11b000,0x11c000]:
 print('SECTION',hex(off))
 for p in range(off,min(len(d),off+256),16):
  b=d[p:p+16]
  print(f'{p:08x}',b.hex(' '),struct.unpack('<4I',b))
print('texture pointers before data')
for p in range(0,0x11c380,4):
 v=struct.unpack_from('<I',d,p)[0]
 if 0x11c380<=v<0x225e80 and v%128==0: print(hex(p),hex(v))
print('last string region',repr(d[0x228e00:0x229170]))
print('last emitter before texture')
for p in range(0x11c290,0x11c380,16): print(hex(p),struct.unpack_from('<4I',d,p))
print('MATCs',len(list(re.finditer(b'MATC',d))))
