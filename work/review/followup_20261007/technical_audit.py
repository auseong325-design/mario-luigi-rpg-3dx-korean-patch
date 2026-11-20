"""Independent read-back of installed text, fonts and image assets. Never edits originals."""
from pathlib import Path
import collections
import json
import re
import sys
import hashlib
import contextlib
import io

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT / 'scripts'))
import numpy as np
from PIL import Image
import lib3dx as L3
import libbffnt as LF
import build_font as BF
import build_patch as BP
import merge_ko as MK
import build_lyt as BL
import lytimg as LY
import build_obj as BO
import libobj as LO
import libhb as HB
import build_fmdl as FM
import build_staffroll as BS
import libstaffroll as SR

OUT = Path(__file__).resolve().parent
PATCH = ROOT / 'patch/00040000001CA900/romfs'
report = {'date':'2026-10-07', 'issues':[]}

def read_json(rel):
    return json.loads((ROOT / rel).read_text(encoding='utf-8-sig'))

def sha(data):
    return hashlib.sha256(data).hexdigest()

def save():
    (OUT / 'technical.json').write_text(json.dumps(report,ensure_ascii=False,indent=2),encoding='utf8')

def issues(scope, items):
    report['issues'].extend({'scope':scope, 'detail':item} for item in items)

ko = read_json('work/ko_final.json')
msgs = MK.jp_messages()
report['text'] = {'jp_files':len(list((ROOT/'text/jp').glob('*.json'))),
                  'jp_messages':len(msgs), 'final_messages':len(ko),
                  'unmerged':[m for m in msgs if m not in ko]}
extra_checks = []
rule_exceptions = []
report['text']['japanese_residue'] = []
report['text']['absolute_dialogue_width_errors'] = []
for mid,text in ko.items():
    own = MK.own_msg(mid)
    if not own:
        issues('text',[f'unknown final id {mid}']); continue
    _,view,_ = __import__('make_batches').to_view(text)
    residual = MK.JP_RESIDUE.findall(MK.visible(view).replace('[Next]',''))
    if residual: report['text']['japanese_residue'].append({'id':mid,'chars':sorted(set(residual))})
    errs,warns = MK.check_message(own,view)
    # to_view renumbers tags by appearance. Korean word order may legitimately
    # reorder tag indices; indices no longer exist in the compiled MSBT.
    errs = [e for e in errs if not e.startswith('placeholders differ')]
    if errs: issues('merged_message',[{'id':mid,'errors':errs}])
    psrc,pko = MK.pages(own['src']), MK.pages(view)
    if own['style'] == 6 and mid.startswith('FMsg/'):
        for pi,page in enumerate(pko):
            if any(MK.width(s)>336 for s in page):
                report['text']['absolute_dialogue_width_errors'].append({'id':mid,'page':pi+1,'ko':view})
            if len([s for s in page if s.strip()]) > 3:
                if any(k in own['src'] for k in [':choice}',':indent}']):
                    rule_exceptions.append({'id':mid,'page':pi+1,'kind':'original choice-menu layout','ko':view})
                else:
                    extra_checks.append({'id':mid,'page':pi+1,'kind':'FMsg style6 more than 3 lines','ko':view})
    for pi,(srcp,kop) in enumerate(zip(psrc,pko)):
        if len([s for s in kop if s.strip()]) > len([s for s in srcp if s.strip()]):
            if mid in {'Menu#534','Menu#535'}:
                # A runtime variable occupies the otherwise invisible first
                # source line. Source and translation both have two rows.
                rule_exceptions.append({'id':mid,'page':pi+1,'kind':'runtime variable fills source row','ko':view})
            else:
                extra_checks.append({'id':mid,'page':pi+1,'kind':'more lines than JP page','ko':view})
    if re.search(r'\{\d+:var\}(을|를|이|가|은|는|과|와|으로|로)(?![가-힣])',view):
        extra_checks.append({'id':mid,'kind':'variable particle','ko':view})
    if re.search(r'\{\d+:icon\}버튼',view):
        extra_checks.append({'id':mid,'kind':'button spacing','ko':view})
    if re.search(r'\.\.|\?!|\?\?|을\(를\)|이\(가\)',view):
        extra_checks.append({'id':mid,'kind':'style punctuation','ko':view})
report['text']['extra_rule_candidates'] = dict(collections.Counter(x['kind'] for x in extra_checks))
report['text']['rule_exception_counts'] = dict(collections.Counter(x['kind'] for x in rule_exceptions))
(OUT/'rule_exceptions.json').write_text(json.dumps(rule_exceptions,ensure_ascii=False,indent=1),encoding='utf8')
(OUT/'rule_candidates.json').write_text(json.dumps(extra_checks,ensure_ascii=False,indent=1),encoding='utf8')
_,intended,used = BP.build_all(ko)
built = {rel:(PATCH/rel).read_bytes() for rel in (*BP.MSG_BG4_FILES,*BP.MSG_MSBT_FILES)}
problems,checked = BP.verify_all(built,intended)
report['text']['installed_read_back_messages'] = checked
report['text']['installed_read_back_errors'] = problems
issues('installed_text',problems)
save(); print('text read back',checked,'errors',len(problems),flush=True)

used = BF.used_chars(ko)
wanted = sorted(set(used)|set(BF.EXTRA_WANTED))
priority = BF.font_span_chars(ko)
base_adv = BF.base_advances()
report['fonts'] = {'used_chars':len(used),'used_hangul':sum(BF.is_hangul(c) for c in used),'roles':{}}
for name,spec in BF.SPECS.items():
    res = BF.build_font(spec,wanted,used,priority,False,base_adv,use_donor=True)
    path = PATCH/spec.rel
    data = path.read_bytes()
    bad = BF.verify(spec,res,data,wanted,False,path)
    sources = collections.Counter(res.sources.get(c,'?') for c in res.added)
    info = {'installed_equals_rebuilt':data==res.data,'sha256':sha(data),'errors':bad,
            'sources':dict(sources),'fallback_hangul':{src:''.join(c for c in res.added if BF.is_hangul(c) and res.sources.get(c)==src)
            for src in sources if src.startswith('rendered')},
            'verification_notes':[s for s in res.problems if any(w in s for w in ['identical','unchanged','outside','model'])]}
    report['fonts']['roles'][name] = info
    issues('font_'+name,bad)
    if data!=res.data: issues('font_'+name,['installed file differs from deterministic build'])
    save(); print(name,'sources',dict(sources),'errors',len(bad),flush=True)

report['plans'] = {}
for name,rel in [('lyt','work/img/lyt_plan.json'),('obj','work/img/obj_plan.json'),('hb','work/img/hb_plan.json'),('fmdl','work/img/fmdl_plan.json')]:
    plan = read_json(rel)
    report['plans'][name] = {'items':len(plan['items']),'actions':dict(collections.Counter(x.get('action','') for x in plan['items'])),
                              'kept_japanese':[x for x in plan['items'] if x.get('jp') and re.search(r'[ぁ-ヿ一-鿿]',x['jp']) and x.get('action')!='replace']}

manifest = BL.load_manifest()
found,errors = BL.collect_pngs(BL.KO_DIR,manifest)
issues('lyt_input',errors)
planned = [r for r in read_json('work/img/lyt_plan.json')['items'] if r.get('action')=='replace']
missing = [r['id'] for r in planned if not (ROOT/r['ko_png']).exists()]
issues('lyt_missing',missing)
pics = {s:np.asarray(Image.open(p).convert('RGBA')) for s,(p,r) in found.items()}
stats = collections.Counter(); psnrs=[]
for dat in LY.LYT_DATS['3DX']:
    orig = L3.romfs_path(f'Lyt/JP/{dat}.dat').read_bytes()
    path = PATCH/f'Lyt/JP/{dat}.dat'
    actual = path.read_bytes() if path.exists() else orig
    _,a = L3.read_bg4(orig); _,b = L3.read_bg4(actual)
    if len(a)!=len(b): issues('lyt',[f'{dat}: entry count differs']); continue
    for old,new in zip(a,b):
        if old.name!=new.name: issues('lyt',[f'{dat}: name changed']); continue
        if old.size_flag or not old.data: continue
        ao,bo = L3.bg4_plain(old),L3.bg4_plain(new)
        if ao[:4]!=b'SARC':
            if ao!=bo: issues('lyt',[f'{dat}/{old.name}: non-SARC changed'])
            continue
        al,bl = LY.sarc_list(ao),LY.sarc_list(bo)
        if [x[0] for x in al]!=[x[0] for x in bl]: issues('lyt',[f'{dat}/{old.name}: SARC list changed']); continue
        for (fname,s,t),(_,bs,bt) in zip(al,bl):
            x,y = ao[s:t],bo[bs:bt]
            if not fname.endswith('.bflim'):
                if x!=y: issues('lyt',[f'{dat}/{old.name}/{fname}: layout/animation changed'])
                continue
            stats['textures']+=1
            key=BL.tex_sha(x)
            if key not in pics:
                if x!=y: issues('lyt',[f'{dat}/{old.name}/{fname}: unexpected texture changed'])
                continue
            stats['replacement_copies']+=1
            want=pics[key];got=LY.bflim_to_rgba(y);info=LY.parse_bflim(y)
            if LY.parse_bflim(x)!=info: issues('lyt',[f'{dat}/{old.name}/{fname}: texture metadata changed'])
            if info['fmt'] in BL.ETC:
                p=BL.psnr(got[...,:3],want[...,:3],want[...,3]);psnrs.append(float(p))
                if p<30: issues('lyt',[f'{dat}/{old.name}/{fname}: PSNR={p:.2f}'])
            elif not np.array_equal(got,BL.expected(info['fmt'],want)):
                issues('lyt',[f'{dat}/{old.name}/{fname}: installed PNG differs'])
report['lyt']={'unique_replacements':len(found),'planned':len(planned),'missing':missing,
               **dict(stats),'min_etc_psnr':min(psnrs) if psnrs else None}
save();print('lyt',report['lyt'],flush=True)

report['obj']={}
for dat in LO.DATS_3DX:
    od=LO.ObjDat('3DX',dat); log=[]
    writes=BO.collect(od,BO.KO/dat,log)
    data=(PATCH/f'Obj/JP/{dat}.dat').read_bytes()
    try: BO.verify(od,data,writes);bad=[]
    except Exception as exc: bad=[str(exc)]
    report['obj'][dat]={'input_pngs':len(log),'regions':sum(len(w) for w in writes.values()),'errors':bad}
    issues('obj_'+dat,bad)
save();print('obj',report['obj'],flush=True)

report['fmdl']={'input_pngs':len(FM.ko_images())}
expected=FM.build(FM.ko_images(),None,verbose=False)
actual=(PATCH/FM.SRC_REL).read_bytes()
report['fmdl']['installed_equals_rebuilt']=expected==actual
if expected!=actual: issues('fmdl',['installed FMdl differs from current input PNG build'])
save();print('fmdl',report['fmdl'],flush=True)

hb_manifest=read_json('work/img/hb/_manifest.json')
hb_pics={p.stem:np.asarray(Image.open(p).convert('RGBA')) for p in (ROOT/'work/img/hb_ko').glob('*.png')}
hb_want={r['sha1']:hb_pics[r['name']] for r in hb_manifest if r['name'] in hb_pics}
hs=collections.Counter();psnrs=[]
for rel in HB.arc_rels():
    src=L3.romfs_path(rel).read_bytes();p=PATCH/rel
    got=p.read_bytes() if p.exists() else src
    a,b=HB.unpack(src),HB.unpack(got)
    ae,be=HB.sarc_entries(a),HB.sarc_entries(b)
    if [e['hash'] for e in ae]!=[e['hash'] for e in be]: issues('hb',[f'{rel}: file hashes/order differ']);continue
    hs['archives']+=1;hs['installed_archives']+=p.exists()
    for x,y in zip(ae,be):
        old,new=a[x['start']:x['end']],b[y['start']:y['end']]
        key=HB.sha16(old)
        if key not in hb_want:
            if old!=new: issues('hb',[f'{rel}:{x["hash"]:08x} unexpected change'])
            continue
        hs['replacement_copies']+=1
        want=hb_want[key];decoded=LY.bflim_to_rgba(new);info=LY.parse_bflim(new)
        if LY.parse_bflim(old)!=info: issues('hb',[f'{rel}:{x["hash"]:08x} metadata changed'])
        if info['fmt'] in BL.ETC:
            q=BL.psnr(decoded[...,:3],want[...,:3],want[...,3]);psnrs.append(float(q))
            if q<30: issues('hb',[f'{rel}:{x["hash"]:08x} PSNR {q}'])
        elif not np.array_equal(decoded,BL.expected(info['fmt'],want)):
            issues('hb',[f'{rel}:{x["hash"]:08x} installed PNG differs'])
report['hb']={**dict(hs),'input_pngs':len(hb_pics),'min_etc_psnr':min(psnrs) if psnrs else None}
save();print('hb',report['hb'],flush=True)

orig=SR.read(L3.romfs_path(BS.SR_REL).read_bytes())
expected,bad=BS.load_ko(orig)
actual=SR.read((PATCH/BS.SR_REL).read_bytes())
if actual!=expected: bad.append('installed staffroll differs from JSON')
needed=set(''.join(x.text for x in actual))
base=LF.parse(L3.romfs_path(BS.FONT_REL).read_bytes())
donor=LF.parse(BS.KR_FONT.read_bytes())
oldmap=base.char_map();newfont=LF.parse((PATCH/BS.FONT_REL).read_bytes())
added={ch:newfont.lookup(ord(ch)) for ch in needed if ord(ch) not in oldmap}
bad+=BS.verify_font(base,(PATCH/BS.FONT_REL).read_bytes(),donor,added,needed)
_,_,layout_warnings=BS.Renderer(newfont).scroll(actual)
report['staffroll']={'lines':len(actual),'changed_lines':[i for i,(a,b) in enumerate(zip(orig,actual)) if a.text!=b.text],
                      'new_glyphs':''.join(sorted(added)),'errors':bad,'layout_warnings':layout_warnings,
                      'roles':sorted(set(x.text for x in actual if x.color==SR.TEAL_3DX))}
issues('staffroll',bad)
save();print('staffroll',report['staffroll'],flush=True)
print('TOTAL',len(report['issues']),'issues',flush=True)
