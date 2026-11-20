from pathlib import Path
import sys, struct
ROOT=Path(__file__).resolve().parents[3]
sys.path.insert(0,str(ROOT/'scripts'))
from libbch import Bch
p=Path(__file__).parent/'before_title.bch'
b=p.read_bytes(); c=Bch(b)
i=c.cmds
while i+8 <= c.cmds+c.cmd_len:
    param,hdr=struct.unpack_from('<II',b,i)
    rid,extra,consec=hdr&65535,(hdr>>20)&2047,hdr>>31
    values=[(i,param)]+[(i+8+4*k,struct.unpack_from('<I',b,i+8+4*k)[0]) for k in range(extra)]
    if rid==0x2c0 and (param&0xffff)==6:
        print('uniform6',hex(i),hex(param), 'header',hex(hdr))
        print('next',[(hex(i+4*k),hex(struct.unpack_from('<I',b,i+4*k)[0]),struct.unpack_from('<f',b,i+4*k)[0]) for k in range(18)])
    i += (2+extra+(extra%2))*4
