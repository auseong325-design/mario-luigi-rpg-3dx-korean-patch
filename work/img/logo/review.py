"""Side-by-side review sheets (on a sky-blue and a dark background, like the title screen)."""
import numpy as np
from PIL import Image, ImageDraw


def _img(a):
    if isinstance(a, Image.Image):
        return a.convert("RGBA")
    return Image.fromarray(np.clip(np.rint(a), 0, 255).astype(np.uint8)).convert("RGBA")


def compose(a, bg):
    im = _img(a)
    base = Image.new("RGBA", im.size, bg)
    base.alpha_composite(im)
    return base


def sheet(items, out, scale=1, crop=None, bgs=((70, 130, 220, 255),), label_h=14, gap=6):
    """items = [(label, rgba)] -> rows = backgrounds, columns = items."""
    ims = []
    for lab, a in items:
        im = _img(a)
        if crop:
            im = im.crop(crop)
        if scale != 1:
            im = im.resize((im.width * scale, im.height * scale), Image.NEAREST)
        ims.append((lab, im))
    w = sum(im.width for _, im in ims) + gap * (len(ims) + 1)
    h = (max(im.height for _, im in ims) + label_h + gap) * len(bgs) + gap
    sh = Image.new("RGBA", (w, h), (30, 30, 30, 255))
    d = ImageDraw.Draw(sh)
    y = gap
    for bg in bgs:
        x = gap
        for lab, im in ims:
            d.text((x, y), lab, fill=(255, 230, 90, 255))
            sh.paste(compose(im, bg), (x, y + label_h))
            x += im.width + gap
        y += max(im.height for _, im in ims) + label_h + gap
    sh = sh.convert("RGB")
    if max(sh.size) > MAX_SIDE:            # viewer limit: never write a sheet over 1600 px
        f = MAX_SIDE / max(sh.size)
        sh = sh.resize((int(sh.width * f), int(sh.height * f)), Image.LANCZOS)
    sh.save(out)
    return out


MAX_SIDE = 1600
