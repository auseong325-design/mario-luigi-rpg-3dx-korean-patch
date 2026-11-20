import struct
def sarc_list(b):
    hsz = struct.unpack_from('<H', b, 4)[0]
    data_off = struct.unpack_from('<I', b, 0xC)[0]
    sfat = hsz
    n = struct.unpack_from('<H', b, sfat + 6)[0]
    ents = []
    sfnt = sfat + 12 + 16 * n
    names_base = sfnt + 8
    for i in range(n):
        h, attr, s, e = struct.unpack_from('<IIII', b, sfat + 12 + 16 * i)
        name = ''
        if attr & 0x01000000:
            o = names_base + (attr & 0xFFFF) * 4
            name = b[o:b.find(b'\0', o)].decode('latin1')
        ents.append((name, data_off + s, data_off + e))
    return ents
