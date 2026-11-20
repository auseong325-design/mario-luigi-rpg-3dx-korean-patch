"""Use the existing non-Japanese settings branch; write only a separate stage.

Run with run_ruby.py so the process has a hard wall-clock timeout.
This does not install the files or launch the game.
"""
import hashlib
import json
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
OUT = Path(__file__).resolve().parent
STAGE = ROOT / 'work/build/furigana_stage/romfs'
sys.path[:0] = [str(ROOT / 'scripts'), str(OUT / 'deps')]
import lib3dx
from capstone import Cs, CS_ARCH_ARM, CS_MODE_ARM

SOURCE_MAIN_SHA = 'cc42b47f9041206879da695a88b648f2825373fcf86bf690b8e5deb9f62d7aa6'
SOURCE_CRR_SHA = '97edb62cf31bfbd0d404a5e4baeee36ade056559088897d4b80234ec8ab50b72'
PATCH_OFFSET = 0x20C38
ORIGINAL_INSTRUCTION = bytes.fromhex('0100a003')  # moveq r0, #1
PATCHED_INSTRUCTION = bytes.fromhex('0000a003')   # moveq r0, #0


def sha(data):
    return hashlib.sha256(data).hexdigest()


def cro_ranges(raw):
    f = struct.unpack_from('<46I', raw, 0x80)
    assert raw[0x80:0x84] == b'CRO0'
    assert f[4] == len(raw)
    return [(0x80, f[12]), (f[12], f[16]), (f[16], f[14]), (f[14], f[14] + f[15])]


def check_cro(raw):
    return [hashlib.sha256(raw[a:b]).digest() == raw[n * 32:(n + 1) * 32]
            for n, (a, b) in enumerate(cro_ranges(raw))]


def module_signature_valid(crr):
    # CRR developer signature: RSA-2048 PKCS#1 v1.5, big-endian modulus/signature.
    # Nintendo signature of the embedded public key remains byte-for-byte intact.
    offset, count = struct.unpack_from('<II', crr, 0x350)
    payload = crr[0x340:offset + count * 32]
    modulus = int.from_bytes(crr[0x40:0x140], 'big')
    signature = int.from_bytes(crr[0x240:0x340], 'big')
    digestinfo = bytes.fromhex('3031300d060960864801650304020105000420') + hashlib.sha256(payload).digest()
    expected = b'\x00\x01' + b'\xff' * (256 - len(digestinfo) - 3) + b'\x00' + digestinfo
    return pow(signature, 65537, modulus).to_bytes(256, 'big') == expected


source_main = lib3dx.romfs_path('RO/MainMenu.cro')
source_crr = lib3dx.romfs_path('.crr/static.crr')
original = source_main.read_bytes()
original_crr = source_crr.read_bytes()
assert sha(original) == SOURCE_MAIN_SHA, 'Unsupported MainMenu.cro version'
assert sha(original_crr) == SOURCE_CRR_SHA, 'Unsupported CRR version'
assert len(original) == 0x37000
assert original[PATCH_OFFSET:PATCH_OFFSET + 4] == ORIGINAL_INSTRUCTION
assert original[0x20C34:0x20C44] == bytes.fromhex('000050e30100a0030000a0136608c4e5')
assert all(check_cro(original)), 'Original CRO section hashes do not match'

# Reject a patch that overlaps any loader relocation target.
fields = struct.unpack_from('<46I', original, 0x80)
segments = [struct.unpack_from('<3I', original, fields[18] + n * 12) for n in range(fields[19])]
relocations = []
for table, count in [(fields[30], fields[31]), (fields[42], fields[43]), (fields[44], fields[45])]:
    for n in range(count):
        tag = struct.unpack_from('<I', original, table + n * 12)[0]
        segment_index = tag & 15
        if segment_index >= len(segments):
            raise AssertionError(f'Unknown relocation segment {segment_index}')
        site = segments[segment_index][0] + (tag >> 4)
        relocations.append(site)
assert all(not PATCH_OFFSET - 3 <= site <= PATCH_OFFSET + 3 for site in relocations)

patched = bytearray(original)
patched[PATCH_OFFSET:PATCH_OFFSET + 4] = PATCHED_INSTRUCTION
for n, (a, b) in enumerate(cro_ranges(patched)):
    patched[n * 32:(n + 1) * 32] = hashlib.sha256(patched[a:b]).digest()
patched = bytes(patched)
assert all(check_cro(patched))
delta = [n for n, (a, b) in enumerate(zip(original, patched)) if a != b]
assert [n for n in delta if n >= 0x80] == [PATCH_OFFSET]
assert all(0x20 <= n < 0x40 or n == PATCH_OFFSET for n in delta)
assert original[:0x20] == patched[:0x20]
assert original[0x40:0x80] == patched[0x40:0x80]

# The CRR stores SHA-256 of the CRO's four hashes, sorted lexicographically.
assert original_crr[:4] == b'CRR0'
hash_offset, hash_count = struct.unpack_from('<II', original_crr, 0x350)
assert hash_offset == 0x360 and hash_count == 15
hashes = [original_crr[hash_offset + n * 32:hash_offset + (n + 1) * 32] for n in range(hash_count)]
assert len(set(hashes)) == hash_count and hashes == sorted(hashes)
debug_offset, debug_size = struct.unpack_from('<II', original_crr, 0x10)
assert set(original_crr[debug_offset:debug_offset + debug_size]) <= {0x00, 0xCC}, 'Unexpected CRR debug associations'

modules = {}
for path in sorted((ROOT / 'romfs/RO').glob('*.cro')):
    raw = lib3dx.romfs_path('RO/' + path.name).read_bytes()
    digest = hashlib.sha256(raw[:0x80]).digest()
    assert digest in hashes and all(check_cro(raw)), path.name
    modules[path.name] = {'source_sha256': sha(raw), 'original_crr_sha256': digest.hex()}
assert len(modules) == hash_count
assert {row['original_crr_sha256'] for row in modules.values()} == {h.hex() for h in hashes}

old_digest = hashlib.sha256(original[:0x80]).digest()
new_digest = hashlib.sha256(patched[:0x80]).digest()
assert hashes.count(old_digest) == 1
new_hashes = sorted(new_digest if h == old_digest else h for h in hashes)
patched_crr = bytearray(original_crr)
patched_crr[hash_offset:hash_offset + hash_count * 32] = b''.join(new_hashes)
patched_crr = bytes(patched_crr)
assert original_crr[:hash_offset] == patched_crr[:hash_offset]
assert original_crr[hash_offset + hash_count * 32:] == patched_crr[hash_offset + hash_count * 32:]
assert all(h in new_hashes for h in hashes if h != old_digest)
assert new_digest in new_hashes and old_digest not in new_hashes
assert patched_crr[0x40:0x340] == original_crr[0x40:0x340], 'Do not fabricate signatures'

modules['MainMenu.cro']['patched_crr_sha256'] = new_digest.hex()
arm = Cs(CS_ARCH_ARM, CS_MODE_ARM)
before = next(arm.disasm(ORIGINAL_INSTRUCTION, PATCH_OFFSET))
after = next(arm.disasm(PATCHED_INSTRUCTION, PATCH_OFFSET))
assert (before.mnemonic, before.op_str) == ('moveq', 'r0, #1')
assert (after.mnemonic, after.op_str) == ('moveq', 'r0, #0')

STAGE.mkdir(parents=True, exist_ok=True)
assert STAGE.resolve().is_relative_to((ROOT / 'work/build').resolve())
for rel, raw in [('RO/MainMenu.cro', patched), ('.crr/static.crr', patched_crr)]:
    target = STAGE / rel
    target.parent.mkdir(parents=True, exist_ok=True)
    target.write_bytes(raw)
    assert target.read_bytes() == raw
assert source_main.read_bytes() == original
assert source_crr.read_bytes() == original_crr

result = {
    'source_main': str(source_main), 'source_main_sha256': sha(original),
    'source_crr': str(source_crr), 'source_crr_sha256': sha(original_crr),
    'main_size': len(original), 'patch_offset': hex(PATCH_OFFSET),
    'before_instruction': ORIGINAL_INSTRUCTION.hex(), 'after_instruction': PATCHED_INSTRUCTION.hex(),
    'before_assembly': before.mnemonic + ' ' + before.op_str,
    'after_assembly': after.mnemonic + ' ' + after.op_str,
    'patched_main_sha256': sha(patched), 'patched_crr_sha256': sha(patched_crr),
    'cro_hash_ranges': [[hex(a), hex(b)] for a, b in cro_ranges(original)],
    'original_cro_hashes': [original[n * 32:(n + 1) * 32].hex() for n in range(4)],
    'patched_cro_hashes': [patched[n * 32:(n + 1) * 32].hex() for n in range(4)],
    'original_cro_hash_checks': check_cro(original), 'patched_cro_hash_checks': check_cro(patched),
    'main_delta_offsets': [hex(n) for n in delta], 'relocations_checked': len(relocations),
    'crr_hash_offset': hex(hash_offset), 'crr_hash_count': hash_count,
    'old_main_crr_digest': old_digest.hex(), 'new_main_crr_digest': new_digest.hex(),
    'old_main_crr_index': hashes.index(old_digest), 'new_main_crr_index': new_hashes.index(new_digest),
    'crr_original_module_signature_valid': module_signature_valid(original_crr),
    'crr_patched_module_signature_valid': module_signature_valid(patched_crr),
    'crr_signatures_preserved': True, 'crr_original_other_modules_match': True,
    'crr_patched_hash_table_sorted': new_hashes == sorted(new_hashes),
    'modules': modules, 'stage': str(STAGE), 'files': ['RO/MainMenu.cro', '.crr/static.crr'],
    'game_launched': False,
}
(OUT / 'furigana_build.json').write_text(json.dumps(result, ensure_ascii=False, indent=2) + '\n', encoding='utf-8')
print(json.dumps({key: value for key, value in result.items() if key != 'modules'}, ensure_ascii=False, indent=2))
