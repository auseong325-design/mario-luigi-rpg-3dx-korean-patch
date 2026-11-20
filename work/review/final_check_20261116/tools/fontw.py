import struct, sys, collections, json
from pathlib import Path
ROOT = Path(__file__).resolve().parents[4]
def adv(path):
    d = Path(path).read_bytes()
    finf = struct.unpack_from("<H", d, 6)[0]
    assert d[finf:finf+4] == b"FINF"
    ptr_width, ptr_map = struct.unpack_from("<II", d, finf + 24)
    widths = {}; p = ptr_width
    while p:
        start, end, nxt = struct.unpack_from("<HHI", d, p)
        for i in range(end - start + 1):
            l, gw, cw = struct.unpack_from("<bBB", d, p + 8 + 3*i)
            widths[start+i] = (l, gw, cw)
        p = nxt
    cmap = {}; p = ptr_map
    while p:
        cs, ce, method, _r, nxt = struct.unpack_from("<HHHHI", d, p)
        body = p + 12
        if method == 0:
            base = struct.unpack_from("<H", d, body)[0]
            for c in range(cs, ce+1): cmap[c] = base + c - cs
        elif method == 1:
            for i, c in enumerate(range(cs, ce+1)):
                g = struct.unpack_from("<H", d, body + 2*i)[0]
                if g != 0xFFFF: cmap[c] = g
        else:
            n = struct.unpack_from("<H", d, body)[0]
            for i in range(n):
                c, g = struct.unpack_from("<HH", d, body + 2 + 4*i); cmap[c] = g
        p = nxt
    return {chr(c): widths.get(g, (0,0,16)) for c, g in cmap.items() if not 0xD800 <= c <= 0xDFFF}
if __name__ == '__main__':
    for name in ['font', 'font_btl', 'font_l']:
        orig = adv(ROOT/f'romfs/Msg/JP_ja/{name}.bffnt')
        pat = adv(ROOT/f'patch/00040000001CA900/romfs/Msg/JP_ja/{name}.bffnt')
        han = [v[2] for c, v in pat.items() if '가' <= c <= '힣']
        kan = [v[2] for c, v in orig.items() if '一' <= c <= '鿿']
        kana = [v[2] for c, v in orig.items() if '぀' <= c <= 'ヿ']
        print(name, 'hangul n', len(han), collections.Counter(han).most_common(6),
              '| kanji', collections.Counter(kan).most_common(3), '| kana', collections.Counter(kana).most_common(4))
        print('  space orig/pat', orig.get(' '), pat.get(' '), ' A', orig.get('A'), pat.get('A'), ' 0', orig.get('0'), pat.get('0'), ' ！', orig.get('！'), ' !', pat.get('!'), ' ?', orig.get('?'), pat.get('?'), '…', orig.get('…'), pat.get('…'))
