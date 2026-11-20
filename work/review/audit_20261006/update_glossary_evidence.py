"""Record the verified 1DX source without changing the established translation."""
from pathlib import Path
import csv, io, json
ROOT=Path(__file__).resolve().parents[3]
OUT=Path(__file__).resolve().parent
row={'jp':'トゲダメージ','ko':'가시 대미지','type':'term','basis':'official',
     'source':'1DX-KR:BMsg.dat:k_sys#223',
     'note':'RPG1 DX 한국판 가이드 제목 KGGuide_BB14; #32·#766 본문에도 같은 표기. 일반 ダメージ=타격과 구분 [gl_kj; review: 2026-10-06 공식 근거 확인]'}
changes=[]
for name in ['glossary.tsv','glossary_overrides.tsv']:
    p=ROOT/'text'/name
    backup=OUT/'glossary_backup'/name
    raw=(backup if backup.exists() else p).read_text(encoding='utf8')
    records=list(csv.DictReader(io.StringIO(raw),delimiter='\t'))
    before=[r.copy() for r in records if r['jp']==row['jp']]
    assert len(before)==(1 if name=='glossary.tsv' else 0), (name,before)
    (OUT/'glossary_backup').mkdir(exist_ok=True)
    if not backup.exists(): backup.write_bytes(p.read_bytes())
    # Preserve unrelated raw lines, blank separators and quotation marks.
    new_line='\t'.join(row[k] for k in ['jp','ko','type','basis','source','note'])
    lines=raw.splitlines()
    if before:
        lines=[new_line if line.startswith(row['jp']+'\t') else line for line in lines]
    else: lines.append(new_line)
    p.write_text('\n'.join(lines)+'\n',encoding='utf8',newline='')
    changes.append({'file':name,'before':before,'after':row})
(OUT/'glossary_changes.json').write_text(json.dumps(changes,ensure_ascii=False,indent=2),encoding='utf8')
print('Verified 1DX source recorded in glossary and rebuild-safe override; Korean term unchanged.')
