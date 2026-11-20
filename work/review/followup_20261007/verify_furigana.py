"""Read-only verification of generated files and real ARM settings snippets.

Unicorn executes extracted instructions, not the game or a user session.
"""
import hashlib
import json
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
OUT = Path(__file__).resolve().parent
sys.path[:0] = [str(ROOT / 'scripts'), str(OUT / 'deps')]
import lib3dx
from unicorn import Uc, UC_ARCH_ARM, UC_MODE_ARM, UC_HOOK_CODE
from unicorn.arm_const import UC_ARM_REG_R0, UC_ARM_REG_R1, UC_ARM_REG_R2, UC_ARM_REG_R4, UC_ARM_REG_R5, UC_ARM_REG_R8, UC_ARM_REG_PC

STAGE = ROOT / 'work/build/furigana_stage/romfs'
original = lib3dx.romfs_path('RO/MainMenu.cro').read_bytes()
patched = (STAGE / 'RO/MainMenu.cro').read_bytes()
manifest = json.loads((OUT / 'furigana_build.json').read_text(encoding='utf-8'))
for rel, expected in [('RO/MainMenu.cro', manifest['patched_main_sha256']), ('.crr/static.crr', manifest['patched_crr_sha256'])]:
    assert hashlib.sha256((STAGE / rel).read_bytes()).hexdigest() == expected

CODE = 0x100000
DATA = 0x200000
STUB = 0x180000


def vm(raw, has_ruby=0):
    engine = Uc(UC_ARCH_ARM, UC_MODE_ARM)
    engine.mem_map(CODE, 0x40000)
    engine.mem_write(CODE, raw)
    engine.mem_map(DATA, 0x30000)
    engine.mem_write(DATA + 0x866, bytes([has_ruby]))
    engine.reg_write(UC_ARM_REG_R4, DATA)
    engine.reg_write(UC_ARM_REG_R5, DATA + 0x14000)
    engine.reg_write(UC_ARM_REG_R8, DATA + 0x800)
    return engine


predicate = []
for region in [0, 1, 2, 3, 4, 5, 6, 255]:
    values = []
    for raw in [original, patched]:
        engine = vm(raw)
        engine.reg_write(UC_ARM_REG_R0, region)
        engine.emu_start(CODE + 0x20C34, CODE + 0x20C44, timeout=100000, count=8)
        values.append(engine.mem_read(DATA + 0x866, 1)[0])
    assert values == [int(region == 0), 0]
    predicate.append({'region': region, 'original_has_ruby': values[0], 'patched_has_ruby': values[1]})

cursor = []
for has_ruby in [0, 1]:
    lower = 0 if has_ruby else 1
    for row in range(lower, 4):
        for direction, start in [('up', 0x21874), ('down', 0x218A8)]:
            engine = vm(patched, has_ruby)
            engine.reg_write(UC_ARM_REG_R1, DATA + 0x800)
            engine.reg_write(UC_ARM_REG_R2, row)
            engine.emu_start(CODE + start, CODE + 0x21950, timeout=100000, count=32)
            assert engine.reg_read(UC_ARM_REG_PC) == CODE + 0x21950
            after = engine.mem_read(DATA + 0x14D39, 1)[0]
            expected = row - 1 if direction == 'up' else row + 1
            if expected < lower:
                expected = 3
            if expected > 3:
                expected = lower
            assert after == expected
            cursor.append({'has_ruby': has_ruby, 'row': row, 'direction': direction, 'after': after})

# Exercise the actual loop that enables seven buttons, then disables only the
# first two when hasRuby is false. The external virtual function is stubbed;
# record the passed object and boolean instead of guessing at the UI library.
focus = []
for has_ruby in [0, 1]:
    engine = vm(patched, has_ruby)
    engine.mem_map(STUB, 0x1000)
    engine.mem_write(STUB, bytes.fromhex('1eff2fe1'))  # bx lr
    vtable = DATA + 0x22000
    engine.mem_write(vtable + 0x28, struct.pack('<I', STUB))
    pointers = []
    for n in range(7):
        pointer = DATA + 0x20000 + n * 0x100
        pointers.append(pointer)
        engine.mem_write(DATA + 0x14D88 + n * 4, struct.pack('<I', pointer))
        engine.mem_write(pointer, struct.pack('<I', vtable))
    calls = []

    def called(emu, address, size, unused):
        if address == STUB:
            calls.append({'button': pointers.index(emu.reg_read(UC_ARM_REG_R0)), 'boolean': emu.reg_read(UC_ARM_REG_R1)})

    engine.hook_add(UC_HOOK_CODE, called, begin=STUB, end=STUB)
    engine.reg_write(UC_ARM_REG_R5, 0)
    engine.emu_start(CODE + 0x21A60, CODE + 0x21AF4, timeout=100000, count=128)
    assert engine.reg_read(UC_ARM_REG_PC) == CODE + 0x21AF4
    state = {
        'has_ruby': has_ruby,
        'column': engine.mem_read(DATA + 0x14D38, 1)[0],
        'row': engine.mem_read(DATA + 0x14D39, 1)[0],
        'button_index': engine.mem_read(DATA + 0x14D54, 1)[0],
        'virtual_0x28_calls': calls,
    }
    assert state['column'] == 0
    assert (state['row'], state['button_index']) == ((0, 0) if has_ruby else (1, 2))
    assert calls[:7] == [{'button': n, 'boolean': 1} for n in range(7)]
    assert calls[7:] == ([] if has_ruby else [{'button': 1, 'boolean': 0}, {'button': 0, 'boolean': 0}])
    focus.append(state)

# Parse every pane/track/key from the original row-hide animation. Its position
# curves have duplicate final-frame keys; retain both, with the last value shown
# separately for the native end-frame state. No layout is changed by this patch.
def parse_animation(path):
    raw = path.read_bytes()
    assert raw[:4] == b'FLAN'
    assert struct.unpack_from('<I', raw, 12)[0] == len(raw)
    blocks = []
    pos = struct.unpack_from('<H', raw, 6)[0]
    while pos < len(raw):
        magic, size = struct.unpack_from('<4sI', raw, pos)
        assert size >= 8 and pos + size <= len(raw)
        blocks.append((magic, pos, size))
        pos += size
    assert pos == len(raw)
    pai = next(pos for magic, pos, size in blocks if magic == b'pai1')
    count = struct.unpack_from('<H', raw, pai + 14)[0]
    table = pai + struct.unpack_from('<I', raw, pai + 16)[0]
    panes = []
    for n in range(count):
        content = pai + struct.unpack_from('<I', raw, table + n * 4)[0]
        name = raw[content:content + 28].split(b'\0')[0].decode('ascii')
        tracks = []
        for t in range(raw[content + 28]):
            tag = content + struct.unpack_from('<I', raw, content + 32 + t * 4)[0]
            kind = raw[tag:tag + 4].decode('ascii')
            assert kind in ['FLPA', 'FLVI']
            for k in range(raw[tag + 4]):
                curve = tag + struct.unpack_from('<I', raw, tag + 8 + k * 4)[0]
                index, target, interpolation, pad, keycount, unused, keyoffset = struct.unpack_from('<4BHHI', raw, curve)
                assert interpolation == (1 if kind == 'FLVI' else 2)
                keys = []
                for j in range(keycount):
                    key = curve + keyoffset + j * (8 if interpolation == 1 else 12)
                    if interpolation == 1:
                        frame, value, padding = struct.unpack_from('<fHH', raw, key)
                        assert padding == 0
                        keys.append({'frame': frame, 'value': value})
                    else:
                        frame, value, slope = struct.unpack_from('<fff', raw, key)
                        keys.append({'frame': frame, 'value': value, 'slope': slope})
                tracks.append({'kind': kind, 'index': index, 'target': target,
                               'target_name': 'visibility' if kind == 'FLVI' else {1: 'translation_y', 9: 'height'}[target],
                               'keys': keys, 'frame0_first_value': keys[0]['value'],
                               'frame1_last_value': keys[-1]['value']})
        panes.append({'pane': name, 'tracks': tracks})
    return {'file': str(path), 'sha256': hashlib.sha256(raw).hexdigest(), 'panes': panes}


animations = [parse_animation(OUT / filename) for filename in [
    'MENU_SET_JP_ja_MENU_SET_L_SET_PNL_hurigana.bflan',
    '1DX_MLYT_SET_KR_ko_MENU_SET_L_SET_PNL_hurigana.bflan']]
assert len(animations[0]['panes']) == 10
tracks = [(pane['pane'], track) for pane in animations[0]['panes'] for track in pane['tracks']]
assert len(tracks) == 13
assert sum(len(track['keys']) for name, track in tracks) == 37
visibility = {name: track for name, track in tracks if track['kind'] == 'FLVI'}
assert set(visibility) == {'PNL_RUBI', 'PANEL_BG_RUBI'}
assert all(track['keys'] == [{'frame': 0.0, 'value': 1}, {'frame': 1.0, 'value': 0}] for track in visibility.values())
assert any(pane['pane'] == 'PNL_hurigana' and pane['tracks'][0]['frame1_last_value'] == 0 for pane in animations[1]['panes'])

# A duplicate-key curve convention is left exactly as authored by the game.
# The executable chooses frame 1 only for the existing hasRuby=false branch.
imports = json.loads((OUT / 'MainMenu_import_sites.json').read_text(encoding='utf-8'))
assert imports[str(0xB54)] == '_ZN2ad9GetRegionEv'
relevant_imports = {hex(offset): imports.get(str(offset)) for offset in [0x274, 0x28C, 0x294, 0xB54]}
result = {'predicate': predicate, 'cursor': cursor, 'focus': focus, 'animations': animations,
          'relevant_imports': relevant_imports, 'arm_emulation_only': True,
          'no_game_execution': True, 'stage_hash_checks': True,
          'layout_files_changed': 0, 'translation_files_changed': 0}
(OUT / 'furigana_verify.json').write_text(json.dumps(result, ensure_ascii=False, indent=2) + '\n', encoding='utf-8')
print('predicate', predicate)
print('cursor', cursor)
print('focus', focus)
for animation in animations:
    print('animation', Path(animation['file']).name)
    for pane in animation['panes']:
        for track in pane['tracks']:
            print(pane['pane'], track['target_name'], track['frame0_first_value'], '->', track['frame1_last_value'])
print('imports', relevant_imports)
print('PASS: actual ARM predicate, all up/down rows, initial focus, seven enable/two disable calls, 10 panes/13 tracks/37 keys, stage hashes')
