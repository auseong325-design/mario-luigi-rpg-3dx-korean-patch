import sys
from pathlib import Path
from PIL import Image, ImageDraw, ImageFont
prefix, a, b, out = sys.argv[1], int(sys.argv[2]), int(sys.argv[3]), sys.argv[4]
font = ImageFont.truetype(r'C:\Windows\Fonts\malgunbd.ttf', 22)
items = [i for i in range(a, b + 1) if Path(f'raw/{prefix}{i}.png').exists() or Path(f'raw/{prefix}{i:02d}.png').exists()]
cols, tw, th = 10, 240, 144
s = Image.new('RGB', (cols * tw, ((len(items) + cols - 1) // cols) * th), 'white'); d = ImageDraw.Draw(s)
for k, i in enumerate(items):
    p = Path(f'raw/{prefix}{i}.png'); p = p if p.exists() else Path(f'raw/{prefix}{i:02d}.png')
    im = Image.open(p).crop((490, 0, 1123, 380)).resize((tw - 4, th - 4))
    x, y = (k % cols) * tw, (k // cols) * th
    s.paste(im, (x, y)); d.rectangle((x, y, x + 46, y + 28), fill='black'); d.text((x + 4, y + 1), str(i), font=font, fill='yellow')
s.save(out)
