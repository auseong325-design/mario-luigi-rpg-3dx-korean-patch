"""RT2: screenshot of the 3DS screens read from the game's framebuffers through RPC (no desktop capture).

STATUS: NOT USABLE with the test instance's hardware (OpenGL) renderer -- the framebuffer addresses from GSP
shared memory are found correctly, but guest memory there holds stale/unrelated data (the rendered image lives
in host GPU memory and is not written back for RPC reads).  Kept only for a software-renderer run; use a desktop
grab of the render window instead (HARNESS.md section 8.4).

The GSP shared memory of this game is mapped at 0x10000000. Per screen (top +0x200, bottom +0x240 for
GSP thread 0) it holds FrameBufferUpdate {u8 index, u8 dirty, u16, FrameBufferInfo[2]} with
FrameBufferInfo {active_fb, addr_left, addr_right, stride, format, shown_fb, unk} (0x1C bytes); the
addresses are the game's virtual addresses (linear heap).  Framebuffers are stored rotated: each
`stride`-byte line is one screen column, bottom-to-top.  Formats: 0 RGBA8, 1 RGB8 (BGR byte order),
2 RGB565, 3 RGB5A1, 4 RGBA4.

  rt_shot.py OUT.png [--scale 2]        top (400x240) above bottom (320x240, centred)
"""
from __future__ import annotations

import argparse
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import rt_rpc  # noqa: E402

GSP_SHMEM = 0x10000000
BPP = {0: 4, 1: 3, 2: 2, 3: 2, 4: 2}


def fb_info(rpc: rt_rpc.Rpc, screen: int) -> dict:
    base = GSP_SHMEM + 0x200 + 0x40 * screen
    raw = rpc.read(base, 4 + 2 * 0x1C)
    idx = raw[0]
    a, l, r, stride, fmt, shown, _ = struct.unpack_from("<7I", raw, 4 + 0x1C * (idx & 1))
    return {"index": idx, "active": a, "left": l, "right": r, "stride": stride, "format": fmt, "shown": shown}


def decode(rpc: rt_rpc.Rpc, info: dict, width: int):
    from PIL import Image

    fmt = info["format"] & 7
    bpp = BPP.get(fmt, 3)
    stride = info["stride"]
    raw = rpc.read(info["left"], stride * width)
    img = Image.new("RGB", (width, 240))
    px = img.load()
    for x in range(width):
        line = raw[x * stride:(x + 1) * stride]
        for i in range(240):
            o = i * bpp
            if fmt == 1:
                b, g, r = line[o], line[o + 1], line[o + 2]
            elif fmt == 0:
                r, g, b = line[o + 3], line[o + 2], line[o + 1]
            elif fmt == 2:
                v = line[o] | (line[o + 1] << 8)
                r, g, b = (v >> 11) << 3, ((v >> 5) & 63) << 2, (v & 31) << 3
            elif fmt == 3:
                v = line[o] | (line[o + 1] << 8)
                r, g, b = (v >> 11) << 3, ((v >> 6) & 31) << 3, ((v >> 1) & 31) << 3
            else:
                v = line[o] | (line[o + 1] << 8)
                r, g, b = (v >> 12) << 4, ((v >> 8) & 15) << 4, ((v >> 4) & 15) << 4
            px[x, 239 - i] = (r, g, b)
    return img


def main(argv=None) -> None:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("out")
    ap.add_argument("--scale", type=int, default=2)
    a = ap.parse_args(argv)
    from PIL import Image

    rpc = rt_rpc.Rpc(timeout=1.0)
    rpc.select_game()
    top_i, bot_i = fb_info(rpc, 0), fb_info(rpc, 1)
    top = decode(rpc, top_i, 400)
    bot = decode(rpc, bot_i, 320)
    out = Image.new("RGB", (400, 480))
    out.paste(top, (0, 0))
    out.paste(bot, (40, 240))
    if a.scale != 1:
        out = out.resize((400 * a.scale, 480 * a.scale), Image.NEAREST)
    out.save(a.out)
    nonblack = sum(1 for p in top.getdata() if p != (0, 0, 0)) + sum(1 for p in bot.getdata() if p != (0, 0, 0))
    print(f"saved {a.out}: top {top_i}, bottom {bot_i}; non-black pixels {nonblack}/{400 * 240 + 320 * 240}")


if __name__ == "__main__":
    main()
