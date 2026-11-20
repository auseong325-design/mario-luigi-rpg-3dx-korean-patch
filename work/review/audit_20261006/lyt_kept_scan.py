import csv, json, math, re
from pathlib import Path
from PIL import Image,ImageDraw,ImageFont

ROOT=Path(__file__).resolve().parents[3]
OUT=Path(__file__).parent/'lyt_kept_visual'
OUT.mkdir(exist_ok=True)
plan=json.loads((ROOT/'work/img/lyt_plan.json').read_text(encoding='utf-8'))
items=plan['items']
local=lambda r:'_jp_ja' in r['base'].lower()
selected=[]
for r in items:
    if r['action']=='keep' and (local(r) or r.get('jp') or r.get('ko')):
        selected.append(r)
print('plan items',len(items),'localized',sum(local(r) for r in items),'localized replace',sum(local(r) and r['action']=='replace' for r in items),
      'localized keep',sum(local(r) and r['action']=='keep' for r in items),'keep with metadata',sum(r['action']=='keep' and bool(r.get('jp') or r.get('ko')) for r in items),'union selected',len(selected))
font=ImageFont.truetype(str(ROOT/'fonts/NanumSquareRoundB.ttf'),13)
small=ImageFont.truetype(str(ROOT/'fonts/NanumSquareRoundB.ttf'),11)
fields=['seq','id','base','png','jp','ko','family','notes','localized']
manifest=[]
pages=[]
tiles=[]
for n,r in enumerate(selected,1):
    row={k:r.get(k,'') for k in fields if k not in ['seq','localized']}
    row.update(seq=n,localized=local(r));manifest.append(row)
    im=Image.open(ROOT/r['png']).convert('RGBA')
    scale=min(3,500/im.width,280/im.height)
    scale=max(1,scale)
    big=im.resize((round(im.width*scale),round(im.height*scale)),Image.Resampling.NEAREST)
    h=max(70,big.height)+62
    tile=Image.new('RGB',(540,h),(92,108,123));draw=ImageDraw.Draw(tile)
    draw.text((8,3),f'{n:02d} {r["base"]}',font=font,fill='white')
    draw.text((8,23),f'{im.width}x{im.height} {scale:.2f}x  JP:{r.get("jp", "")}  KO:{r.get("ko", "")}',font=small,fill='white')
    # source pixels unchanged: checkerboard below alpha, then integer/near-integer magnification
    bg=Image.new('RGB',big.size,(145,156,165));bd=ImageDraw.Draw(bg)
    for y in range(0,big.height,12):
        for x in range(0,big.width,12):
            if (x//12+y//12)%2:
                bd.rectangle((x,y,x+11,y+11),fill=(190,199,205))
    bg.paste(big,(0,0),big)
    tile.paste(bg,(8,48));tiles.append(tile)
    print(f'{n:02d}',r['base'],'JP='+r.get('jp',''),'KO='+r.get('ko',''),r['notes'])
for start in range(0,len(tiles),12):
    chunk=tiles[start:start+12]
    rowheights=[max(t.height for t in chunk[j:j+2]) for j in range(0,len(chunk),2)]
    canvas=Image.new('RGB',(1080,sum(rowheights)),(92,108,123))
    y=0
    for j,rh in enumerate(rowheights):
        for col,t in enumerate(chunk[j*2:j*2+2]):
            canvas.paste(t,(col*540,y))
        y+=rh
    p=OUT/f'kept_{start//12+1:02d}.png';canvas.save(p);pages.append(str(p))
(OUT/'index.json').write_text(json.dumps(dict(items=manifest,sheets=pages),ensure_ascii=False,indent=2),encoding='utf-8')
with (OUT.parent/'lyt_kept_items.tsv').open('w',encoding='utf-8',newline='') as f:
    w=csv.DictWriter(f,fieldnames=fields,delimiter='\t');w.writeheader();w.writerows(manifest)
print('sheets',len(pages))
print('\n'.join(pages))
