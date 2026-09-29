"""LZH8 / Nintendo CX "LH" (type 0x40) codec used by romfs/HB/*.z (3DX giant battles).

Layout (from Nintendo's UncompressLH as translated by Treeki, LHDecompressor.cpp):
  0x40, u24 LE size (0 -> u32 LE size follows)
  tree 1 (9-bit entries, literals 0..255 + lengths 0x100..0x1FF): u16 LE n, table size = (n+1)*4 bytes
      INCLUDING the size field; entries are packed MSB-first in a plain byte stream.
  tree 2 (5-bit entries, displacement bit lengths): u8 n, same rule.
  data: plain byte stream, bits MSB-first.
The loader reads entries while `consumed < size`, fetching whole bytes on demand; the next section
starts at the number of bytes actually consumed (can exceed the declared size by a byte).
Tree entry: low bits = offset to child pair (7 bits / 3 bits), (0x100 >> bit) / (0x10 >> bit) = that
child is a leaf. Children of node i: (i & ~1) + (offset + 1) * 2 + bit. Root = entry 1.
Symbol < 0x100: literal. Else length = (sym & 0xFF) + 3; then displacement length d:
disp = 0 if d == 0 else (1 << (d-1)) | next (d-1) bits; copy from out[pos - disp - 1].
"""
import heapq
import struct

LENBITS, DISPBITS = 9, 5


def _load_table(data, pos, nbits):
    """Exact emulation of LoadLHPiece. Returns (entries list, bytes consumed)."""
    count2 = (1 << nbits) * 2
    mask = (1 << nbits) - 1
    if nbits <= 8:
        n = data[pos]; off = 1
    else:
        n = data[pos] | (data[pos + 1] << 8); off = 2
    size = (n + 1) << 2
    copied = off
    tab = [0] * count2
    acc = 0; have = 0; idx = 1
    while copied < size:
        if have < nbits:
            k = (nbits + 7 - have) >> 3
            for _ in range(k):
                acc = ((acc << 8) | data[pos + copied]) & 0xFFFFFFFF
                copied += 1
            have += k * 8
        if idx < count2:
            tab[idx] = (acc >> (have - nbits)) & mask
            idx += 1
        have -= nbits
    # the reader may fetch one byte past the declared size while finishing the last entry;
    # the next section still starts at the declared size (checked on HB/life2.arc.z)
    return tab, size


def decompress(data):
    data = bytes(data)
    if data[0] != 0x40:
        raise ValueError("not LZH8")
    size = int.from_bytes(data[1:4], "little")
    pos = 4
    if size == 0:
        size = struct.unpack_from("<I", data, 4)[0]
        pos = 8
    ltab, lb = _load_table(data, pos, LENBITS)
    pos += lb
    dtab, db = _load_table(data, pos, DISPBITS)
    pos += db
    data_pos = pos
    out = bytearray(size)
    o = 0
    cur = 0; left = 0; p = pos
    while o < size:
        idx = 1
        while True:
            if left == 0:
                cur = data[p]; p += 1; left = 8
            left -= 1
            c = (cur >> left) & 1
            node = ltab[idx]
            nxt = (idx & ~1) + ((node & 0x7F) + 1) * 2 + c
            if node & (0x100 >> c):
                sym = ltab[nxt]
                break
            idx = nxt
        if sym < 0x100:
            out[o] = sym; o += 1
            continue
        length = (sym & 0xFF) + 3
        idx = 1
        while True:
            if left == 0:
                cur = data[p]; p += 1; left = 8
            left -= 1
            c = (cur >> left) & 1
            node = dtab[idx]
            nxt = (idx & ~1) + ((node & 0x7) + 1) * 2 + c
            if node & (0x10 >> c):
                dl = dtab[nxt]
                break
            idx = nxt
        disp = 0
        if dl:
            disp = 1
            for _ in range(dl - 1):
                if left == 0:
                    cur = data[p]; p += 1; left = 8
                left -= 1
                disp = (disp << 1) | ((cur >> left) & 1)
        src = o - disp - 1
        if src < 0:
            raise ValueError("bad back reference")
        if o + length > size:
            length = size - o
        for _ in range(length):
            out[o] = out[src]; o += 1; src += 1
    return bytes(out), {"data_pos": data_pos, "end": p, "len_table": lb, "disp_table": db}


# ---------------------------------------------------------------- encoder
class _BitWriter:
    def __init__(self):
        self.buf = bytearray()
        self.cur = 0
        self.n = 0

    def put(self, v, nbits):
        for i in range(nbits - 1, -1, -1):
            self.cur = (self.cur << 1) | ((v >> i) & 1)
            self.n += 1
            if self.n == 8:
                self.buf.append(self.cur)
                self.cur = 0
                self.n = 0

    def flush(self):
        if self.n:
            self.buf.append(self.cur << (8 - self.n))
            self.cur = 0
            self.n = 0
        return bytes(self.buf)


def _huffman(freqs):
    items = [(f, i, s) for i, (s, f) in enumerate(sorted(freqs.items()))]
    if len(items) == 1:
        s = items[0][2]
        return (s, s)
    heapq.heapify(items)
    cnt = len(items)
    while len(items) > 1:
        f1, _, a = heapq.heappop(items)
        f2, _, b = heapq.heappop(items)
        heapq.heappush(items, (f1 + f2, cnt, (a, b)))
        cnt += 1
    return items[0][2]


def _size(t):
    return 0 if not isinstance(t, tuple) else 1 + _size(t[0]) + _size(t[1])


def _layout(tree, offmask, leafbit):
    """Place a binary tree in the CX table. Returns (table, codes) or None if an offset overflows."""
    tab = [0, 0]
    codes = {}
    pending = [(tree, 1, 0, 0)]
    sizes = {}

    def sz(t):
        k = id(t)
        if k not in sizes:
            sizes[k] = _size(t)
        return sizes[k]

    while pending:
        nextpair = len(tab) // 2
        forced = None
        for j, (t, ti, c, l) in enumerate(pending):
            if nextpair - (ti // 2) - 1 >= offmask:
                forced = j
                break
        if forced is None:
            j = min(range(len(pending)), key=lambda k: (sz(pending[k][0]), -k))
        else:
            j = forced
        t, ti, c, l = pending.pop(j)
        pair = len(tab)
        off = pair // 2 - ti // 2 - 1
        if off < 0 or off > offmask:
            return None
        node = off
        tab.extend([0, 0])
        for bit in (0, 1):
            ch = t[bit]
            if isinstance(ch, tuple):
                pending.append((ch, pair + bit, (c << 1) | bit, l + 1))
            else:
                node |= leafbit >> bit
                tab[pair + bit] = ch
                codes.setdefault(ch, ((c << 1) | bit, l + 1))
        tab[ti] = node
    return tab, codes


def _make_tree(freqs, offmask, leafbit):
    f = dict(freqs)
    for attempt in range(40):
        tree = _huffman(f)
        r = _layout(tree, offmask, leafbit)
        if r is not None:
            return r
        m = max(f.values())
        f = {s: max(v, m >> max(1, 16 - attempt)) for s, v in f.items()}
    raise RuntimeError("tree layout failed")


def _table_bytes(tab, nbits):
    size_len = 2 if nbits > 8 else 1
    bw = _BitWriter()
    for v in tab[1:]:
        bw.put(v, nbits)
    body = bw.flush()
    total = (size_len + len(body) + 3) // 4 * 4
    while True:
        blob = bytearray(total)
        n = total // 4 - 1
        blob[:size_len] = struct.pack("<H", n) if size_len == 2 else bytes([n])
        blob[size_len:size_len + len(body)] = body
        probe = bytes(blob) + b"\0\0\0\0"
        t2, used = _load_table(probe, 0, nbits)
        if used == total and t2[1:len(tab)] == tab[1:]:
            return bytes(blob)
        total += 4


def _find_matches(data, window=0x8000, maxlen=258, chain=128):
    n = len(data)
    head = {}
    prev = [-1] * n
    toks = []

    def insert(i):
        if i + 3 <= n:
            k = data[i:i + 3]
            prev[i] = head.get(k, -1)
            head[k] = i

    def best(i):
        if i + 3 > n:
            return 0, 0
        j = head.get(data[i:i + 3], -1)
        bl, bd, c = 0, 0, 0
        lim = min(maxlen, n - i)
        while j >= 0 and i - j <= window and c < chain:
            if data[j + bl] == data[i + bl] if bl < lim else False:
                l = 0
                while l < lim and data[j + l] == data[i + l]:
                    l += 1
                if l > bl:
                    bl, bd = l, i - j
                    if l == lim:
                        break
            j = prev[j]
            c += 1
        return bl, bd

    i = 0
    pend = None
    while i < n:
        l, d = best(i)
        insert(i)
        if l >= 3:
            if i + 1 < n:
                l2, d2 = best(i + 1)
                if l2 > l + 1:
                    toks.append(("L", data[i]))
                    i += 1
                    continue
            toks.append(("M", l, d))
            for k in range(i + 1, i + l):
                insert(k)
            i += l
        else:
            toks.append(("L", data[i]))
            i += 1
    return toks


def compress(data):
    data = bytes(data)
    toks = _find_matches(data)
    lf, df = {}, {}
    for t in toks:
        if t[0] == "L":
            lf[t[1]] = lf.get(t[1], 0) + 1
        else:
            s = 0x100 + t[1] - 3
            lf[s] = lf.get(s, 0) + 1
            dl = (t[2] - 1).bit_length()
            df[dl] = df.get(dl, 0) + 1
    if not df:
        df = {0: 1}
    if not lf:
        lf = {0: 1}
    ltab, lcodes = _make_tree(lf, 0x7F, 0x100)
    dtab, dcodes = _make_tree(df, 0x7, 0x10)
    bw = _BitWriter()
    for t in toks:
        if t[0] == "L":
            bw.put(*lcodes[t[1]])
        else:
            bw.put(*lcodes[0x100 + t[1] - 3])
            disp = t[2] - 1
            dl = disp.bit_length()
            bw.put(*dcodes[dl])
            if dl > 1:
                bw.put(disp & ((1 << (dl - 1)) - 1), dl - 1)
    body = bw.flush()
    if 0 < len(data) < 0x1000000:
        hdr = bytes([0x40]) + len(data).to_bytes(3, "little")
    else:
        hdr = b"\x40\0\0\0" + struct.pack("<I", len(data))
    out = hdr + _table_bytes(ltab, LENBITS) + _table_bytes(dtab, DISPBITS) + body
    out += b"\0" * (-len(out) % 4)  # originals are all 4-byte multiples
    return out


def compress_checked(data):
    c = compress(data)
    d, _ = decompress(c)
    if d != bytes(data):
        raise RuntimeError("LZH8 round trip failed")
    return c
