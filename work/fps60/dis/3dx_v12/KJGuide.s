
<KJGuide:nnroControlObject_>  # KJGuide:nnroControlObject_
13000180: ldr      r2, [pc, #0x80]  ; =0x130025a8
13000184: cmp      r1, #5
13000188: push     {r4, lr}
1300018c: ldrlo    pc, [pc, r1, lsl #2]
13000190: b        #0x130001ec
13000194: movwne   r0, #0x1a8
13000198: movwne   r0, #0x1b0
1300019c: movwne   r0, #0x1b8
130001a0: movwne   r0, #0x1c4
130001a4: movwne   r0, #0x1d4
130001a8: ldr      r1, [pc, #0x5c]  ; =0x0
130001ac: b        #0x130001bc
130001b0: str      r0, [r2]
130001b4: b        #0x130001e4
130001b8: ldr      r1, [r2]
130001bc: str      r1, [r0]
130001c0: b        #0x130001e4
130001c4: ldr      r1, [pc, #0x44]  ; =0x1300022c
130001c8: str      r1, [r0]
130001cc: ldr      r1, [pc, #0x40]  ; =0x1300022c
130001d0: b        #0x130001e0
130001d4: ldr      r1, [pc, #0x3c]  ; =0x13001984
130001d8: str      r1, [r0]
130001dc: ldr      r1, [pc, #0x38]  ; =0x13001984
130001e0: str      r1, [r0, #4]
130001e4: mov      r0, #0
130001e8: pop      {r4, pc}
130001ec: ldr      r0, [pc, #0x2c]  ; =0x30000000
130001f0: mov      r0, r0
130001f4: ldr      r0, [pc, #0x28]  ; =0x30000027
130001f8: nop      
130001fc: mov      r0, r0
13000200: ldr      r0, [pc, #0x20]  ; =0xd8e12c21
13000204: pop      {r4, pc}
13000208: movwne   r2, #0x5a8
1300020c: andeq    r0, r0, r0
13000210: movwne   r0, #0x22c
13000214: movwne   r0, #0x22c
13000218: movwne   r1, #0x984
1300021c: movwne   r1, #0x984
13000220: andlo    r0, r0, r0
13000224: andlo    r0, r0, r7, lsr #32
13000228: stmle    r1!, {r0, r5, sl, fp, sp} ^
