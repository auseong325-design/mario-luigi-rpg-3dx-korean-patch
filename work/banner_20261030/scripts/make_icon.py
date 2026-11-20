"""Korean HOME Menu title: put 「마리오&루이지 RPG3 DX」 into the Korean column of the game's SMDH (ExeFS icon).

Only the Korean title slot (index 7: short, long and publisher) changes; the icons, the other languages,
ratings, region lockout and flags stay byte-identical. The layout follows the 1DX Korean SMDH, which puts the
same text in the short and long fields and "Nintendo" as publisher. The base and the v1.2 update carry the
same icon (checked below), so one file serves both.

Reads exefs/icon and exefs2/icon (read-only); writes out/icon/icon_ko.bin and out/icon/icon.json.
"""
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
OUT = Path(__file__).resolve().parents[1] / 'out' / 'icon'
LANGS = ['ja', 'en', 'fr', 'de', 'it', 'es', 'zh-CN', 'ko', 'nl', 'pt', 'ru', 'zh-TW']
KO = 7
TITLE = '마리오&루이지 RPG3 DX'
PUBLISHER = 'Nintendo'


def field(text, size):
    data = text.encode('utf-16-le')
    assert len(data) + 2 <= size, (text, size)
    return data + bytes(size - len(data))


def titles(data):
    rows = {}
    for i, lang in enumerate(LANGS):
        o = 8 + i * 0x200
        get = lambda a, n: data[o + a:o + a + n].decode('utf-16-le').split('\0')[0]
        rows[lang] = {'short': get(0, 0x80), 'long': get(0x80, 0x100), 'publisher': get(0x180, 0x80)}
    return rows


def main():
    base, update = (ROOT / 'exefs' / 'icon').read_bytes(), (ROOT / 'exefs2' / 'icon').read_bytes()
    assert base[:4] == b'SMDH' and len(base) == 0x36C0, len(base)
    assert base == update, 'the update carries a different icon; build one per title'
    reference = (ROOT / 'ml 1dx' / '3exefs' / 'icon').read_bytes()
    ko_1dx = titles(reference)['ko']
    assert ko_1dx['short'] == ko_1dx['long'] and ko_1dx['publisher'] == PUBLISHER, ko_1dx
    out = bytearray(base)
    o = 8 + KO * 0x200
    out[o:o + 0x200] = field(TITLE, 0x80) + field(TITLE, 0x100) + field(PUBLISHER, 0x80)
    changed = [i for i in range(len(out)) if out[i] != base[i]]
    assert changed and o <= changed[0] and changed[-1] < o + 0x200, 'only the Korean title slot may change'
    hangul = sorted({c for c in TITLE if '가' <= c <= '힣'})
    in_1dx_name = sorted(c for c in hangul if c in ko_1dx['short'])
    OUT.mkdir(parents=True, exist_ok=True)
    (OUT / 'icon_ko.bin').write_bytes(bytes(out))
    report = {'source': 'exefs/icon (== exefs2/icon)', 'source_sha256': hashlib.sha256(base).hexdigest(),
              'output': 'out/icon/icon_ko.bin', 'output_sha256': hashlib.sha256(out).hexdigest(),
              'changed_bytes': len(changed), 'changed_range': [hex(changed[0]), hex(changed[-1] + 1)],
              'korean_slot_before': titles(base)['ko'], 'korean_slot_after': titles(bytes(out))['ko'],
              'reference_1dx_korean_slot': ko_1dx,
              'hangul_also_in_1dx_name': f'{len(in_1dx_name)}/{len(hangul)} ({"".join(in_1dx_name)})',
              'unchanged': 'icons (24x24, 48x48), other 11 languages, ratings, region lockout, flags'}
    (OUT / 'icon.json').write_text(json.dumps(report, ensure_ascii=False, indent=1), encoding='utf-8')
    print(json.dumps(report, ensure_ascii=False, indent=1))


if __name__ == '__main__':
    main()
