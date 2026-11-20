"""Read only DS script; all writes stay in this audit directory."""
import enum,io,json,sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
OUT=Path(__file__).resolve().parent
sys.path.insert(0,str(ROOT/'scripts'))
from libnds_kr import overlay,segmented_file,FEVENT_HEADER_OVERLAY3,DATA
from mnllib.bis.managers import FEventScriptManager
from mnllib.bis.script import FEventScript
from mnllib.script import Variable
from mnllib.script import CommandMetadata
m=FEventScriptManager(None)
ov6=overlay(6)
def valid(raw):
    count=raw[0]&127
    if count>30:return False
    if any(((raw[1+i//2]>>(4*(i%2)))&15)>8 for i in range(count)):return False
    return not any(raw[1+(count+1)//2:])
runs=[]
for align in range(0,16,4):
    start=None
    for p in range(align,len(ov6)-15,16):
        if valid(ov6[p:p+16]):
            if start is None:start=p
        elif start is not None:
            if (p-start)//16>=485:runs.append((start,(p-start)//16))
            start=None
print('metadata candidates',runs)
# The metadata table must cover all 0x1e5 command IDs. Require an isolated run.
candidates=[(start,length) for start,length in runs if length>=485]
if len(candidates)!=1:raise RuntimeError('No uniquely proven command table; stop rather than guessing')
start,length=candidates[0]
m.load_command_metadata_table(io.BytesIO(ov6[start:start+length*16]),length)
seg=segmented_file(overlay(3),FEVENT_HEADER_OVERLAY3,(DATA/'FEvent/FEvent.dat').read_bytes())
def serial(v):
    if isinstance(v,enum.Enum):return v.name
    if isinstance(v,Variable):return {'variable':v.number}
    if isinstance(v,bytes):return v.hex()
    if isinstance(v,(list,tuple)):return [serial(x) for x in v]
    if hasattr(v,'__dict__'):return {k:serial(x) for k,x in v.__dict__.items()}
    return v
out=[]
for subid in (0,1):
    raw=seg[0xDA*3+subid]
    if not raw:continue
    s=FEventScript.from_bytes(m,raw,index=0xDA*3+subid)
    rebuilt=s.to_bytes(m)
    mismatch=next((i for i,(a,b) in enumerate(zip(rebuilt,raw)) if a!=b),None)
    print('roundtrip',subid,len(raw),len(rebuilt),mismatch)
    if mismatch is not None:print('difference',raw[max(0,mismatch-8):mismatch+24].hex(),rebuilt[max(0,mismatch-8):mismatch+24].hex())
    assert raw==rebuilt+b'\0'*(len(raw)-len(rebuilt)),'Unexpected roundtrip content mismatch'
    parsed=serial(s)
    parsed['roundtrip_equal']=rebuilt==raw
    parsed['first_difference']=mismatch
    out.append(parsed)
(OUT/'chika_ds_script.json').write_text(json.dumps(out,ensure_ascii=False,indent=1),encoding='utf-8')
print('Parsed script chunks',len(out))
for s in out:print('header',s['header'],'subroutines',len(s['subroutines']))
