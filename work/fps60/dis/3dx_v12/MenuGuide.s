
<MenuGuide:nnroControlObject_>  # MenuGuide:nnroControlObject_
15800180: ldr      r2, [pc, #0x80]  ; =0x15802594
15800184: cmp      r1, #5
15800188: push     {r4, lr}
1580018c: ldrlo    pc, [pc, r1, lsl #2]
15800190: b        #0x158001ec
15800194: strne    r0, [r0, #0x1a8]
15800198: strne    r0, [r0, #0x1b0]
1580019c: strne    r0, [r0, #0x1b8]
158001a0: strne    r0, [r0, #0x1c4]
158001a4: strne    r0, [r0, #0x1d4]
158001a8: ldr      r1, [pc, #0x5c]  ; =0x0
158001ac: b        #0x158001bc
158001b0: str      r0, [r2]
158001b4: b        #0x158001e4
158001b8: ldr      r1, [r2]
158001bc: str      r1, [r0]
158001c0: b        #0x158001e4
158001c4: ldr      r1, [pc, #0x44]  ; =0x1580022c
158001c8: str      r1, [r0]
158001cc: ldr      r1, [pc, #0x40]  ; =0x1580022c
158001d0: b        #0x158001e0
158001d4: ldr      r1, [pc, #0x3c]  ; =0x15801880
158001d8: str      r1, [r0]
158001dc: ldr      r1, [pc, #0x38]  ; =0x15801880
158001e0: str      r1, [r0, #4]
158001e4: mov      r0, #0
158001e8: pop      {r4, pc}
158001ec: ldr      r0, [pc, #0x2c]  ; =0x30000000
158001f0: mov      r0, r0
158001f4: ldr      r0, [pc, #0x28]  ; =0x30000027
158001f8: nop      
158001fc: mov      r0, r0
15800200: ldr      r0, [pc, #0x20]  ; =0xd8e12c21
15800204: pop      {r4, pc}
15800208: strne    r2, [r0, #0x594]
1580020c: andeq    r0, r0, r0
15800210: strne    r0, [r0, #0x22c]
15800214: strne    r0, [r0, #0x22c]
15800218: strne    r1, [r0, #0x880]
1580021c: strne    r1, [r0, #0x880]
15800220: andlo    r0, r0, r0
15800224: andlo    r0, r0, r7, lsr #32
15800228: stmle    r1!, {r0, r5, sl, fp, sp} ^
