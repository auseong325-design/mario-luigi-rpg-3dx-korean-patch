import json
import struct
from pathlib import Path

OUT = Path(__file__).resolve().parent
for filename in ['MENU_SET_JP_ja_MENU_SET_L_SET_PNL_hurigana.bflan', '1DX_MLYT_SET_KR_ko_MENU_SET_L_SET_PNL_hurigana.bflan']:
    raw = (OUT / filename).read_bytes()
    print(filename, len(raw))
    print('header', raw[:24].hex(' '))
    pos = struct.unpack_from('<H', raw, 6)[0]
    while pos < len(raw):
        magic, size = struct.unpack_from('<4sI', raw, pos)
        if magic == b'pai1':
            print('pai1', hex(pos), raw[pos:pos + 64].hex(' '))
            count = struct.unpack_from('<H', raw, pos + 14)[0]
            table = pos + struct.unpack_from('<I', raw, pos + 16)[0]
            for n in range(count):
                entry = pos + struct.unpack_from('<I', raw, table + n * 4)[0]
                print('content', n, hex(entry), raw[entry:entry + 28])
                count2 = raw[entry + 28]
                print('meta', count2, raw[entry + 20:entry + 44].hex(' '))
                next_entry = pos + struct.unpack_from('<I', raw, table + (n + 1) * 4)[0] if n + 1 < count else pos + size
                print(raw[entry:next_entry].hex(' '))
        pos += size
