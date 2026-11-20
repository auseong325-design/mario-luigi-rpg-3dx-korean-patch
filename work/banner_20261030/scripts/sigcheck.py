"""Check which RSA signatures in a CIA are valid (public keys from the CIA's own cert chain and,
for the NCCH header, from the exheader access descriptor). Shows whether the input CIA already
relies on Luma's signature patches (then a rebuilt CIA needs nothing new).

  sigcheck.py <cia> [out.json]
"""
from __future__ import annotations

import hashlib
import json
import struct
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
import cia as C  # noqa: E402

DI_SHA256 = bytes.fromhex("3031300d060960864801650304020105000420")


def pkcs1_ok(sig: bytes, n: int, e: int, digest: bytes) -> bool:
    k = (n.bit_length() + 7) // 8
    m = pow(int.from_bytes(sig, "big"), e, n).to_bytes(k, "big")
    want = b"\x00\x01" + b"\xff" * (k - 3 - len(DI_SHA256) - 32) + b"\x00" + DI_SHA256 + digest
    return m == want


def parse_certs(b: bytes) -> dict:
    certs, p = {}, 0
    while p < len(b):
        st = struct.unpack_from(">I", b, p)[0]
        sig, pad = C.SIG_SIZES[st]
        body = p + 4 + sig + pad
        issuer = b[body:body + 0x40].rstrip(b"\0").decode()
        ktype = struct.unpack_from(">I", b, body + 0x40)[0]
        name = b[body + 0x44:body + 0x84].rstrip(b"\0").decode()
        kp = body + 0x88
        if ktype == 0:      # RSA-4096
            n = int.from_bytes(b[kp:kp + 0x200], "big"); e = struct.unpack_from(">I", b, kp + 0x200)[0]; ln = 0x200 + 4 + 0x34
        elif ktype == 1:    # RSA-2048
            n = int.from_bytes(b[kp:kp + 0x100], "big"); e = struct.unpack_from(">I", b, kp + 0x100)[0]; ln = 0x100 + 4 + 0x34
        else:               # ECC
            n, e, ln = None, None, 0x3C + 0x3C
        full = f"{issuer}-{name}"
        certs[full] = {"n": n, "e": e, "sig_type": st, "sig": b[p + 4:p + 4 + sig], "signed": b[body:kp + ln]}
        p = kp + ln
    return certs


def main(argv) -> int:
    path = Path(argv[1])
    c = C.Cia(path)
    certs = parse_certs(c.read(c.off_cert, c.cert_size))
    rep = {"certs": list(certs)}
    # TMD: signature over the 0xC4-byte header
    t = c.tmd
    sig_len = C.SIG_SIZES[c.tmd_sig_type][0]
    key = certs.get(c.issuer)
    rep["tmd_signed_by"] = c.issuer
    rep["tmd_signature_valid"] = bool(key and pkcs1_ok(t[4:4 + sig_len], key["n"], key["e"],
                                                      hashlib.sha256(t[c.tmd_hdr:c.tmd_hdr + 0xC4]).digest()))
    # ticket: signature over the body (from issuer to end)
    k = c.tik
    st = struct.unpack_from(">I", k, 0)[0]
    s, pad = C.SIG_SIZES[st]
    tb = 4 + s + pad
    tiss = k[tb:tb + 0x40].rstrip(b"\0").decode()
    key = certs.get(tiss)
    rep["ticket_signed_by"] = tiss
    rep["ticket_signature_valid"] = bool(key and pkcs1_ok(k[4:4 + s], key["n"], key["e"], hashlib.sha256(k[tb:]).digest()))
    # cert chain itself (CP/XS signed by CA)
    for name, ce in certs.items():
        issuer = name.rsplit("-", 1)[0]
        ik = certs.get(issuer)
        if ik and ik["n"]:
            rep[f"cert_{name}_valid"] = pkcs1_ok(ce["sig"], ik["n"], ik["e"], hashlib.sha256(ce["signed"]).digest())
    # NCCH header: signed 0x100..0x200 with the key in exheader ACI (+0x500)
    base = c.chunks[0]["cia_off"]
    nh = c.read(base, 0x200)
    ex = c.read(base + 0x200, 0x800)
    n_mod = int.from_bytes(ex[0x500:0x600], "big")
    rep["ncch_header_signature_valid"] = pkcs1_ok(nh[:0x100], n_mod, 65537, hashlib.sha256(nh[0x100:0x200]).digest())
    print(json.dumps(rep, indent=1))
    if len(argv) > 2:
        Path(argv[2]).write_text(json.dumps(rep, indent=1), encoding="utf-8")
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))
