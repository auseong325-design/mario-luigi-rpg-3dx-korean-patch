import sys, struct, re
sys.path.insert(0, str(__import__('pathlib').Path(__file__).resolve().parents[4] / 'scripts'))
from lib3dx import blz_decompress, read_bg4, romfs_path
from bflyt_local import parse, load_sarc
from lyt_sarc import sarc_list
def sarc_files(s): return {n: s[a:b] for n, a, b in sarc_list(s)}
def entries(dat):
    _, ents = read_bg4(romfs_path(f'Lyt/JP/{dat}.dat').read_bytes())
    return [e.name for e in ents if e.data]
if __name__ == '__main__':
    dat = sys.argv[1]
    if len(sys.argv) == 2:
        print(entries(dat)); sys.exit()
    entry = sys.argv[2]; pat = sys.argv[3] if len(sys.argv) > 3 else ''
    files = sarc_files(load_sarc(dat, entry))
    for n, data in sorted(files.items()):
        if not n.endswith('.bflyt'): continue
        L = parse(data)
        for p in L['panes']:
            if pat and not re.search(pat, p.name): continue
            x, y, sx, sy = p.world()
            print(f"{n.rsplit('/',1)[-1][:-6]:28} {p.kind} {p.path()[-70:]:70} size {p.size[0]:.0f}x{p.size[1]:.0f} at ({x:.0f},{y:.0f}) s=({sx:.2f},{sy:.2f}) {p.part}")
