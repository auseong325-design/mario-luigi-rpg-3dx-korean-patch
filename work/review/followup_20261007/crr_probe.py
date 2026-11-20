import collections
import re
import sys
from pathlib import Path
ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT / 'scripts'))
import lib3dx
raw = lib3dx.romfs_path('.crr/static.crr').read_bytes()
print('debug histogram', collections.Counter(raw[0x5c0:0x5c0 + 0xb88]))
for m in re.finditer(rb'[ -~]{5,}', raw):
    print(hex(m.start()), m.group().decode('ascii'))
for n in range(0x500, len(raw), 16):
    if raw[n:n+16] != bytes([0xcc]) * 16 and raw[n:n+16] != bytes(16):
        print(hex(n), raw[n:n+16].hex(' '))
