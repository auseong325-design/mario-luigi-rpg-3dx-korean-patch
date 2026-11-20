"""Contact sheets of every layout replacement and all remaining Japanese placeholders."""
from pathlib import Path
from PIL import Image,ImageDraw,ImageFont
import json
root=Path(__file__).resolve().parents[3]
out=Path(__file__).resolve().parent/'visual'
out.mkdir(exist_ok=True)
font=ImageFont.truetype(str(root/'fonts/NanumSquareRoundB.ttf'),12)
plan=json.loads((root/'work/img/lyt_plan.json').read_text(encoding='utf8'))
groups={}
for r in plan['items']:
    if r['action']=='replace' and r.get('family')!='logo':groups.setdefault(r.get('family') or 'other',[]).append(r)
index=[]
for family,rows in groups.items():
    tiles=[]
    for r in rows:
        a=Image.open(root/r['png']).convert('RGBA');b=Image.open(root/r['ko_png']).convert('RGBA')
        s=min(3,680/(a.width+b.width+20))
        a=a.resize((round(a.width*s),round(a.height*s)),Image.Resampling.NEAREST)
        b=b.resize((round(b.width*s),round(b.height*s)),Image.Resampling.NEAREST)
        tile=Image.new('RGB',(720,max(a.height,b.height)+38),(90,106,125));dr=ImageDraw.Draw(tile)
        dr.text((4,2),r['base']+'   '+r['ko'],fill='white',font=font)
        tile.paste(a,(8,30),a);tile.paste(b,(18+a.width,30),b);tiles.append(tile)
    chunk=[];height=0;page=1
    for tile in tiles:
        if height+tile.height>1450 and chunk:
            canvas=Image.new('RGB',(720,height),(90,106,125));y=0
            for t in chunk:canvas.paste(t,(0,y));y+=t.height
            p=out/f'{family}_{page:02d}.png';canvas.save(p);index.append(str(p));page+=1;chunk=[];height=0
        chunk.append(tile);height+=tile.height
    if chunk:
        canvas=Image.new('RGB',(720,height),(90,106,125));y=0
        for t in chunk:canvas.paste(t,(0,y));y+=t.height
        p=out/f'{family}_{page:02d}.png';canvas.save(p);index.append(str(p))
placeholders=[]
for fi in [22,24,26,28,30,34,36,38,40,42,44]:
    p=root/f'work/img/obj/3DX/Menu/m_item_ev_all/f{fi:03d}.png'
    im=Image.open(p).convert('RGBA').resize((128,128),Image.Resampling.NEAREST)
    placeholders.append((fi,im))
canvas=Image.new('RGB',(700,3*165),(90,106,125));dr=ImageDraw.Draw(canvas)
for i,(fi,im) in enumerate(placeholders):
    x=(i%4)*175;y=(i//4)*165
    dr.text((x,y),f'm_item_ev_all f{fi:03d}',fill='white',font=font);canvas.paste(im,(x,y+24),im)
canvas.save(out/'untranslated_placeholders.png')
(out/'index.json').write_text(json.dumps(index,ensure_ascii=False,indent=1),encoding='utf8')
print('layouts',sum(map(len,groups.values())),'sheets',len(index))
print('\n'.join(index))
