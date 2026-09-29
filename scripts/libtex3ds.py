"""3DS (PICA200) texture codecs shared by every image workstream (Lyt BFLIM, FMdl BCH, Obj sprites).

    rgba = decode(data, "ETC1A4", w, h)          # -> uint8 array (h, w, 4), top row first
    data = encode(rgba, "ETC1A4")                # inverse; w and h must be multiples of 8

`w`/`h` are the STORED (tile-padded) dimensions. Pixels are stored in 8x8 tiles, tiles
row-major, Morton (Z) order inside a tile. PICA textures are stored bottom row first, so
decode()/encode() flip vertically by default (flip=False gives memory order).

Byte layouts (little-endian, as the GPU reads them):
    RGBA8 = A B G R | RGB8 = B G R | RGBA5551/RGB565/RGBA4 = u16 R..A high->low
    LA8 = A L | HILO8 = LO HI (-> G, R) | LA4 = L<<4|A | L4/A4 = low nibble first
    ETC1 = 4x4 blocks, 2x2 blocks per tile (TL TR BL BR), each block a byte-reversed ETC1 block;
    ETC1A4 = same, each block preceded by 8 bytes of 4-bit alpha (pixel (x, y) = nibble x*4+y).

ETC1 uses the pinned C extensions texture2ddecoder (decode) and etcpak (encode, first pass). By
default every ETC block with a visible pixel is then searched again (both flips, both modes, all
tables, base colours around the mean) with the error weighted by the stored alpha, and the better
block is kept, so the result is never worse than etcpak. LIBTEX3DS_ETC=fast skips the search.
"""

from __future__ import annotations

import os

import numpy as np

BPP = {"RGBA8": 32, "RGB8": 24, "RGBA5551": 16, "RGB565": 16, "RGBA4": 16, "LA8": 16, "HILO8": 16,
       "L8": 8, "A8": 8, "LA4": 8, "L4": 4, "A4": 4, "ETC1": 4, "ETC1A4": 8}

# BCLIM / BFLIM (CTR) 'format' byte
FLIM_FORMATS = {0: "L8", 1: "A8", 2: "LA4", 3: "LA8", 4: "HILO8", 5: "RGB565", 6: "RGB8", 7: "RGBA5551",
                8: "RGBA4", 9: "RGBA8", 10: "ETC1", 11: "ETC1A4", 12: "L4", 13: "A4"}
# PICA GPU format ids (BCH / CGFX textures)
PICA_FORMATS = {0: "RGBA8", 1: "RGB8", 2: "RGBA5551", 3: "RGB565", 4: "RGBA4", 5: "LA8", 6: "HILO8",
                7: "L8", 8: "A8", 9: "LA4", 10: "L4", 11: "A4", 12: "ETC1", 13: "ETC1A4"}

# ETC1 encoder: "hq" (default) = etcpak + alpha-weighted search per visible block, "fast" = etcpak only
ETC_QUALITY = os.environ.get("LIBTEX3DS_ETC", "hq")
# at most this many blocks per texture are searched again (worst etcpak error first); 5-10 ms each.
# Every text texture in this project (<= 256x64 = 1,024 blocks) is refined completely.
ETC_MAX_REFINE = int(os.environ.get("LIBTEX3DS_ETC_MAX", "2048"))
_ETC_FLOOR = 0.01            # error weight of a fully transparent ETC1A4 pixel (keeps its colour sane)
_ETC_MOD = np.array([[2, 8, -2, -8], [5, 17, -5, -17], [9, 29, -9, -29], [13, 42, -13, -42],
                     [18, 60, -18, -60], [24, 80, -24, -80], [33, 106, -33, -106], [47, 183, -47, -183]],
                    np.float32)  # [table][pixel index (msb<<1 | lsb)]
_ETC_SUB = {  # flip -> the two sub-blocks as pixel lists p = y*4 + x
    0: (np.array([y * 4 + x for x in (0, 1) for y in range(4)]), np.array([y * 4 + x for x in (2, 3) for y in range(4)])),
    1: (np.array([y * 4 + x for y in (0, 1) for x in range(4)]), np.array([y * 4 + x for y in (2, 3) for x in range(4)])),
}


def data_size(fmt: str, w: int, h: int) -> int:
    return w * h * BPP[fmt] // 8


def _pixel_order(w: int, h: int) -> np.ndarray:
    """Stream index -> flat index (row-major, memory orientation) for 8x8 Morton tiles."""
    if w % 8 or h % 8:
        raise ValueError(f"stored size {w}x{h} is not a multiple of 8")
    i = np.arange(64)
    mx = (i & 1) | ((i >> 1) & 2) | ((i >> 2) & 4)
    my = ((i >> 1) & 1) | ((i >> 2) & 2) | ((i >> 3) & 4)
    tiles = np.arange((w // 8) * (h // 8))
    tx, ty = tiles % (w // 8), tiles // (w // 8)
    x = (tx[:, None] * 8 + mx[None, :]).ravel()
    y = (ty[:, None] * 8 + my[None, :]).ravel()
    return y * w + x


def _block_order(w: int, h: int) -> np.ndarray:
    """ETC stream block index -> row-major 4x4 block index."""
    if w % 8 or h % 8:
        raise ValueError(f"stored size {w}x{h} is not a multiple of 8")
    bw = w // 4
    tiles = np.arange((w // 8) * (h // 8))
    tx, ty = tiles % (w // 8), tiles // (w // 8)
    sub = np.arange(4)
    bx = (tx[:, None] * 2 + (sub & 1)[None, :]).ravel()
    by = (ty[:, None] * 2 + (sub >> 1)[None, :]).ravel()
    return by * bw + bx


def _x4(v):
    return (v.astype(np.uint16) * 17).astype(np.uint8)


def _x5(v):
    return ((v.astype(np.uint16) << 3) | (v.astype(np.uint16) >> 2)).astype(np.uint8)


def _x6(v):
    return ((v.astype(np.uint16) << 2) | (v.astype(np.uint16) >> 4)).astype(np.uint8)


def _q(v, bits):
    """uint8 -> nearest n-bit value."""
    m = (1 << bits) - 1
    return ((v.astype(np.uint32) * m + 127) // 255).astype(np.uint16)


def _etc_standard(data: bytes, w: int, h: int, with_alpha: bool):
    """3DS ETC stream -> (standard row-major ETC1 blocks, alpha nibble array or None)."""
    nblk = (w // 4) * (h // 4)
    step = 16 if with_alpha else 8
    raw = np.frombuffer(data, np.uint8, nblk * step).reshape(nblk, step)
    color = raw[:, -8:][:, ::-1]                      # byte-reversed ETC1 block
    std = np.empty_like(color)
    std[_block_order(w, h)] = color
    alpha = None
    if with_alpha:
        a64 = raw[:, :8].copy().view("<u8").ravel()
        k = np.arange(16, dtype=np.uint64)            # nibble k = pixel (x=k//4, y=k%4)
        nib = ((a64[:, None] >> (k[None, :] * np.uint64(4))) & np.uint64(15)).astype(np.uint8)
        blk = np.empty((nblk, 4, 4), np.uint8)        # [block][y][x]
        blk[:, k % 4, k // 4] = nib
        alpha = np.empty_like(blk)
        alpha[_block_order(w, h)] = blk
    return std.tobytes(), alpha


def _blocks_to_image(blocks: np.ndarray, w: int, h: int) -> np.ndarray:
    """(nblk, 4, 4) row-major blocks -> (h, w) image."""
    return blocks.reshape(h // 4, w // 4, 4, 4).transpose(0, 2, 1, 3).reshape(h, w)


def _image_to_blocks(img: np.ndarray) -> np.ndarray:
    h, w = img.shape[:2]
    return img.reshape(h // 4, 4, w // 4, 4).transpose(0, 2, 1, 3).reshape(-1, 4, 4)


def decode(data: bytes, fmt: str, w: int, h: int, flip: bool = True) -> np.ndarray:
    """Tiled PICA pixel data -> RGBA uint8 (h, w, 4)."""
    need = data_size(fmt, w, h)
    if len(data) < need:
        raise ValueError(f"{fmt} {w}x{h} needs {need} bytes, got {len(data)}")
    data = bytes(data[:need])
    n = w * h
    out = np.zeros((n, 4), np.uint8)
    if fmt in ("ETC1", "ETC1A4"):
        import texture2ddecoder
        std, alpha = _etc_standard(data, w, h, fmt == "ETC1A4")
        bgra = np.frombuffer(texture2ddecoder.decode_etc1(std, w, h), np.uint8).reshape(h, w, 4)
        img = bgra[..., [2, 1, 0, 3]].copy()
        img[..., 3] = 255 if alpha is None else _x4(_blocks_to_image(alpha, w, h))
        return img[::-1].copy() if flip else img
    b = np.frombuffer(data, np.uint8)
    if fmt == "RGBA8":
        px = b.reshape(n, 4)
        s = px[:, [3, 2, 1, 0]]
    elif fmt == "RGB8":
        px = b.reshape(n, 3)
        s = np.concatenate([px[:, [2, 1, 0]], np.full((n, 1), 255, np.uint8)], 1)
    elif fmt in ("RGBA5551", "RGB565", "RGBA4"):
        v = b.view("<u2")
        s = np.empty((n, 4), np.uint8)
        if fmt == "RGBA5551":
            s[:, 0], s[:, 1], s[:, 2] = _x5(v >> 11 & 31), _x5(v >> 6 & 31), _x5(v >> 1 & 31)
            s[:, 3] = (v & 1) * 255
        elif fmt == "RGB565":
            s[:, 0], s[:, 1], s[:, 2], s[:, 3] = _x5(v >> 11 & 31), _x6(v >> 5 & 63), _x5(v & 31), 255
        else:
            s[:, 0], s[:, 1], s[:, 2], s[:, 3] = _x4(v >> 12 & 15), _x4(v >> 8 & 15), _x4(v >> 4 & 15), _x4(v & 15)
    elif fmt == "LA8":
        px = b.reshape(n, 2)
        s = np.stack([px[:, 1], px[:, 1], px[:, 1], px[:, 0]], 1)
    elif fmt == "HILO8":
        px = b.reshape(n, 2)
        s = np.stack([px[:, 1], px[:, 0], np.zeros(n, np.uint8), np.full(n, 255, np.uint8)], 1)
    elif fmt == "L8":
        s = np.stack([b, b, b, np.full(n, 255, np.uint8)], 1)
    elif fmt == "A8":
        s = np.stack([np.full(n, 255, np.uint8)] * 3 + [b], 1)
    elif fmt == "LA4":
        l, a = _x4(b >> 4), _x4(b & 15)
        s = np.stack([l, l, l, a], 1)
    elif fmt in ("L4", "A4"):
        nib = _x4(np.stack([b & 15, b >> 4], 1).ravel())
        full = np.full(n, 255, np.uint8)
        s = np.stack([nib, nib, nib, full], 1) if fmt == "L4" else np.stack([full, full, full, nib], 1)
    else:
        raise ValueError(f"unknown format {fmt}")
    out[_pixel_order(w, h)] = s
    img = out.reshape(h, w, 4)
    return img[::-1].copy() if flip else img


def _etc_grid(r: int) -> np.ndarray:
    a = np.arange(-r, r + 1)
    return np.stack(np.meshgrid(a, a, a, indexing="ij"), -1).reshape(-1, 3)


def _etc_expand(k: np.ndarray, bits: int) -> np.ndarray:
    k = k.astype(np.int32)
    return (k * 17 if bits == 4 else (k << 3) | (k >> 2)).astype(np.float32)


def _etc_search(xs: np.ndarray, ws: np.ndarray, bits: int, radius: int, chunk: int = 128):
    """Sub-blocks xs (n, 8, 3), weights ws (n, 8) -> for every base colour in a cube of `radius`
    steps around the weighted mean: coords K (n, c, 3), best weighted SSE (n, c), its table (n, c)."""
    n = xs.shape[0]
    maxv = (1 << bits) - 1
    mean = (xs * ws[..., None]).sum(1) / np.maximum(ws.sum(1, keepdims=True), 1e-12)
    grid = _etc_grid(radius)
    K = np.clip(np.rint(mean * maxv / 255.0).astype(np.int32)[:, None, :] + grid[None], 0, maxv)
    B = _etc_expand(K, bits)
    best = np.full(K.shape[:2], np.inf, np.float32)
    tab = np.zeros(K.shape[:2], np.int8)
    for s in range(0, n, chunk):
        e = slice(s, s + chunk)
        x = xs[e][:, None, :, None, :]                                   # (b, 1, 8, 1, 3)
        w = ws[e][:, None, :]
        for t in range(8):
            lv = np.clip(B[e][:, :, None, :] + _ETC_MOD[t][None, None, :, None], 0, 255)   # (b, c, 4, 3)
            d = lv[:, :, None, :, :] - x                                 # (b, c, 8, 4, 3)
            tot = ((d * d).sum(-1).min(-1) * w).sum(-1)
            better = tot < best[e]
            best[e] = np.where(better, tot, best[e])
            tab[e] = np.where(better, t, tab[e])
    return K.astype(np.int16), best, tab


def _etc_hq_blocks(X: np.ndarray, W: np.ndarray, r4: int = 2, r5: int = 3):
    """Blocks X (n, 16, 3) float (pixel p = y*4 + x), weights W (n, 16) -> (standard ETC1 words
    as uint64 (n,), weighted SSE (n,)). Both flips, individual (4:4:4) and differential (5:5:5 with
    a -4..+3 delta) modes, all 8 tables, every base colour within r4 / r5 steps of the mean."""
    n = X.shape[0]
    rows = np.arange(n)
    cands = []
    for flip in (0, 1):
        s0, s1 = _ETC_SUB[flip]
        xs = np.stack([X[:, s0], X[:, s1]], 1).reshape(2 * n, 8, 3)
        ws = np.stack([W[:, s0], W[:, s1]], 1).reshape(2 * n, 8)
        r2 = np.arange(2 * n)
        K4, E4, T4 = _etc_search(xs, ws, 4, r4)
        i4 = E4.argmin(1)
        cands.append((0, flip, E4[r2, i4].reshape(n, 2).sum(1), K4[r2, i4].reshape(n, 2, 3),
                      T4[r2, i4].reshape(n, 2)))
        K5, E5, T5 = _etc_search(xs, ws, 5, r5)
        c = K5.shape[1]
        K5, E5, T5 = K5.reshape(n, 2, c, 3), E5.reshape(n, 2, c), T5.reshape(n, 2, c)
        be = np.full(n, np.inf, np.float32)
        bi = np.zeros(n, np.int64)
        bj = np.zeros(n, np.int64)
        for s in range(0, n, 32):
            e = slice(s, s + 32)
            dd = K5[e, 1][:, None, :, :] - K5[e, 0][:, :, None, :]      # (b, c0, c1, 3)
            ok = ((dd >= -4) & (dd <= 3)).all(-1)
            tot = np.where(ok, E5[e, 0][:, :, None] + E5[e, 1][:, None, :], np.inf).reshape(ok.shape[0], -1)
            a = tot.argmin(1)
            be[e] = tot[np.arange(tot.shape[0]), a]
            bi[e], bj[e] = np.divmod(a, c)
        cands.append((1, flip, be, np.stack([K5[rows, 0, bi], K5[rows, 1, bj]], 1),
                      np.stack([T5[rows, 0, bi], T5[rows, 1, bj]], 1)))
    errs = np.stack([cd[2] for cd in cands], 1)
    choice = errs.argmin(1)
    words = np.zeros(n, np.uint64)
    p = np.arange(16)
    jbit = ((p % 4) * 4 + p // 4).astype(np.uint64)                      # index bit j = x*4 + y
    for ci, (diff, flip, _e, k, t) in enumerate(cands):
        sel = choice == ci
        if not sel.any():
            continue
        kk = k[sel].astype(np.int64)
        tt = t[sel].astype(np.int64)
        if diff:
            d = kk[:, 1] - kk[:, 0]
            hi = (kk[:, 0, 0] << 27) | ((d[:, 0] & 7) << 24) | (kk[:, 0, 1] << 19) | ((d[:, 1] & 7) << 16) | \
                 (kk[:, 0, 2] << 11) | ((d[:, 2] & 7) << 8) | 2
        else:
            hi = (kk[:, 0, 0] << 28) | (kk[:, 1, 0] << 24) | (kk[:, 0, 1] << 20) | (kk[:, 1, 1] << 16) | \
                 (kk[:, 0, 2] << 12) | (kk[:, 1, 2] << 8)
        hi = hi | (tt[:, 0] << 5) | (tt[:, 1] << 2) | flip
        sub_of = np.zeros(16, np.int64)
        sub_of[_ETC_SUB[flip][1]] = 1
        base = _etc_expand(kk, 5 if diff else 4)[:, sub_of]              # (m, 16, 3)
        lv = np.clip(base[:, :, None, :] + _ETC_MOD[tt[:, sub_of]][:, :, :, None], 0, 255)
        idx = ((lv - X[sel][:, :, None, :]) ** 2).sum(-1).argmin(-1).astype(np.uint64)
        lo = (((idx >> np.uint64(1)) << (jbit + np.uint64(16))) | ((idx & np.uint64(1)) << jbit)).sum(
            1, dtype=np.uint64)
        words[sel] = (hi.astype(np.uint64) << np.uint64(32)) | lo
    return words, errs[rows, choice]


def _etc1_encode(rgb: np.ndarray, weight: np.ndarray) -> np.ndarray:
    """(h, w, 3) uint8 + per-pixel error weight -> standard ETC1 blocks (nblk, 8) uint8, row-major.
    etcpak gives a fast first pass; unless LIBTEX3DS_ETC=fast, every block with a visible pixel
    (weight above the floor) that etcpak did not reproduce exactly is searched again with
    _etc_hq_blocks, and the lower weighted error wins. The result is never worse than etcpak."""
    import etcpak
    h, w = rgb.shape[:2]
    rgba = np.concatenate([rgb, np.full((h, w, 1), 255, np.uint8)], 2)
    std = np.frombuffer(etcpak.compress_etc1_rgb(np.ascontiguousarray(rgba).tobytes(), w, h),
                        np.uint8).reshape(-1, 8).copy()
    if ETC_QUALITY == "fast":
        return std
    import texture2ddecoder
    fast = np.frombuffer(texture2ddecoder.decode_etc1(std.tobytes(), w, h), np.uint8).reshape(h, w, 4)[..., [2, 1, 0]]
    blk = lambda a: a.reshape(h // 4, 4, w // 4, 4, -1).transpose(0, 2, 1, 3, 4).reshape((h // 4) * (w // 4), 16, -1)
    X = blk(rgb).astype(np.float32)
    Wt = blk(weight[..., None]).astype(np.float32)[..., 0]
    e_fast = (((blk(fast).astype(np.float32) - X) ** 2).sum(-1) * Wt).sum(-1)
    todo = np.flatnonzero((e_fast > 0) & (Wt.max(1) > _ETC_FLOOR * 1.5))
    if todo.size > ETC_MAX_REFINE:   # big textures: refine the worst blocks only (text textures fit whole)
        todo = todo[np.argsort(-e_fast[todo], kind="stable")[:ETC_MAX_REFINE]]
    if todo.size:
        words, e_hq = _etc_hq_blocks(X[todo], Wt[todo])
        better = e_hq < e_fast[todo]
        std[todo[better]] = words[better].astype(">u8").view(np.uint8).reshape(-1, 8)
    return std


def encode(rgba: np.ndarray, fmt: str, flip: bool = True) -> bytes:
    """RGBA uint8 (h, w, 4) -> tiled PICA pixel data. Inverse of decode()."""
    img = np.ascontiguousarray(rgba[::-1] if flip else rgba, np.uint8)
    h, w = img.shape[:2]
    if fmt in ("ETC1", "ETC1A4"):
        if fmt == "ETC1A4":   # colour error counts as much as the pixel is visible (stored 4-bit alpha)
            a = _q(img[..., 3], 4).astype(np.float32) / 15.0
            weight = np.maximum(a * a, _ETC_FLOOR)
        else:
            weight = np.ones((h, w), np.float32)
        std = _etc1_encode(img[..., :3], weight)
        color = std[_block_order(w, h)][:, ::-1]
        if fmt == "ETC1":
            return color.tobytes()
        a = _q(_image_to_blocks(img[..., 3])[_block_order(w, h)], 4).astype(np.uint64)  # [blk][y][x]
        k = np.arange(16)
        nib = a[:, k % 4, k // 4]                       # nibble k = pixel (x=k//4, y=k%4)
        a64 = (nib << (np.arange(16, dtype=np.uint64) * np.uint64(4))[None, :]).sum(1, dtype=np.uint64)
        alpha = a64.astype("<u8").view(np.uint8).reshape(-1, 8)
        return np.concatenate([alpha, color], 1).tobytes()
    s = img.reshape(-1, 4)[_pixel_order(w, h)]
    r, g, b, a = (s[:, i] for i in range(4))
    if fmt == "RGBA8":
        return np.stack([a, b, g, r], 1).tobytes()
    if fmt == "RGB8":
        return np.stack([b, g, r], 1).tobytes()
    if fmt == "RGBA5551":
        return (_q(r, 5) << 11 | _q(g, 5) << 6 | _q(b, 5) << 1 | (a >= 128)).astype("<u2").tobytes()
    if fmt == "RGB565":
        return (_q(r, 5) << 11 | _q(g, 6) << 5 | _q(b, 5)).astype("<u2").tobytes()
    if fmt == "RGBA4":
        return (_q(r, 4) << 12 | _q(g, 4) << 8 | _q(b, 4) << 4 | _q(a, 4)).astype("<u2").tobytes()
    if fmt == "LA8":
        return np.stack([a, r], 1).tobytes()
    if fmt == "HILO8":
        return np.stack([g, r], 1).tobytes()
    if fmt == "L8":
        return r.tobytes()
    if fmt == "A8":
        return a.tobytes()
    if fmt == "LA4":
        return (_q(r, 4) << 4 | _q(a, 4)).astype(np.uint8).tobytes()
    if fmt in ("L4", "A4"):
        v = _q(r if fmt == "L4" else a, 4).astype(np.uint8)
        return (v[0::2] | (v[1::2] << 4)).tobytes()
    raise ValueError(f"unknown format {fmt}")


def stored_size(w: int, h: int, nbytes: int, fmt: str) -> tuple[int, int]:
    """Smallest power-of-two (>= 8) stored size that matches `nbytes` for a w x h image."""
    def p2(v):
        return max(8, 1 << (int(v) - 1).bit_length())
    cand = [(p2(w), p2(h)), (p2(h), p2(w)), ((w + 7) // 8 * 8, (h + 7) // 8 * 8)]
    for sw, sh in cand:
        if data_size(fmt, sw, sh) == nbytes:
            return sw, sh
    raise ValueError(f"no stored size for {w}x{h} {fmt} in {nbytes} bytes")


def _selftest() -> None:
    rng = np.random.default_rng(1)
    lossless = {"RGBA8": 8, "RGB8": 8, "LA8": 8, "L8": 8, "A8": 8}
    for fmt in BPP:
        img = rng.integers(0, 256, (16, 24, 4), dtype=np.uint8) if fmt not in ("ETC1", "ETC1A4") else \
            np.kron(rng.integers(0, 256, (4, 6, 4), dtype=np.uint8), np.ones((4, 4, 1), np.uint8))
        enc = encode(img, fmt)
        assert len(enc) == data_size(fmt, 24, 16), fmt
        dec = decode(enc, fmt, 24, 16)
        assert encode(dec, fmt) == enc or fmt in ("ETC1", "ETC1A4"), f"{fmt}: re-encode changed bytes"
        if fmt in lossless:
            ch = {"RGBA8": [0, 1, 2, 3], "RGB8": [0, 1, 2], "LA8": [0, 3], "L8": [0], "A8": [3]}[fmt]
            assert (dec[..., ch] == img[..., ch]).all(), fmt
    # ETC1: flat colours must survive, orientation/channel order included
    img = np.zeros((16, 16, 4), np.uint8)
    img[:8, :8] = (255, 0, 0, 255); img[:8, 8:] = (0, 255, 0, 255)
    img[8:, :8] = (0, 0, 255, 255); img[8:, 8:] = (255, 255, 255, 0)
    for fmt in ("ETC1", "ETC1A4"):
        dec = decode(encode(img, fmt), fmt, 16, 16)
        err = np.abs(dec[..., :3].astype(int) - img[..., :3]).max()
        assert err <= 8, f"{fmt} colour error {err}"
        if fmt == "ETC1A4":
            assert (dec[..., 3] == img[..., 3]).all(), "ETC1A4 alpha"
    # HQ search: packed words decode to exactly the error the search predicted
    import texture2ddecoder
    edge = np.zeros((8, 8, 3), np.uint8)
    edge[:] = (13, 26, 54)
    edge[1:6, 1:5] = 255
    edge[6:, 3:] = 0
    X = edge.reshape(2, 4, 2, 4, 3).transpose(0, 2, 1, 3, 4).reshape(4, 16, 3).astype(np.float32)
    words, err = _etc_hq_blocks(X, np.ones((4, 16), np.float32))
    for b in range(4):
        d = np.frombuffer(texture2ddecoder.decode_etc1(words[b:b + 1].astype(">u8").tobytes(), 4, 4),
                          np.uint8).reshape(16, 4)[:, [2, 1, 0]].astype(np.float32)
        assert abs(((d - X[b]) ** 2).sum() - err[b]) < 1e-2, f"HQ block {b}: packed words do not match"
    # HQ is never worse than etcpak (alpha-weighted), and better on hard white/navy edges
    txt = np.zeros((16, 16, 4), np.uint8)
    txt[..., :3] = (13, 26, 54)
    txt[3:13, 2:14, 3] = 255
    txt[5:11, 4:12, :3] = 255
    txt[7:9, 6:10, :3] = (13, 26, 54)
    wq = np.maximum((txt[..., 3] / 255.0) ** 2, _ETC_FLOOR)
    global ETC_QUALITY
    saved, errs = ETC_QUALITY, {}
    try:
        for mode in ("fast", "hq"):
            ETC_QUALITY = mode
            d = decode(encode(txt, "ETC1A4"), "ETC1A4", 16, 16).astype(np.float64)
            errs[mode] = (((d[..., :3] - txt[..., :3]) ** 2).sum(-1) * wq).sum()
    finally:
        ETC_QUALITY = saved
    assert errs["hq"] <= errs["fast"], f"HQ ETC worse than etcpak: {errs}"
    print(f"libtex3ds selftest OK (ETC weighted SSE hq {errs['hq']:.0f} <= etcpak {errs['fast']:.0f})")


if __name__ == "__main__":
    _selftest()
