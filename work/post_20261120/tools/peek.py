import sys
from PIL import Image
names = sys.argv[1:]
ims = [Image.open(f'raw/{n}.png').crop((490, 0, 1123, 760)) for n in names]
s = Image.new('RGB', (sum(i.width for i in ims) + 10 * len(ims), 760), 'white'); x = 0
for i in ims: s.paste(i, (x, 0)); x += i.width + 10
s.resize((s.width // 2, s.height // 2)).save('_peek.png')
