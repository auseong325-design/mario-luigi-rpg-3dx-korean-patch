
<->SetMinigameWorkForStaffroll>  # veneer->_Z27SetMinigameWorkForStaffrollv
11000180: ldr      pc, [pc, #-4]
11000184: andseq   r5, r3, r4, ror #7

<->_ZnwjP10MemAlcBasePKcj>  # veneer->_ZnwjP10MemAlcBasePKcj
11000188: ldr      pc, [pc, #-4]
1100018c: eoreq    r1, pc, r8, lsr #10

<->EtcSys:mg::MGSystem>  # veneer->EtcSys:_ZN2mg8MGSystemC1Ev
11000190: ldr      pc, [pc, #-4]
11000194: andne    r7, r4, ip, lsr r2

<->TaskMan::entry>  # veneer->_ZN7TaskMan5entryEP4Task
11000198: ldr      pc, [pc, #-4]
1100019c: .word    0x002f12b4

<Staffroll:EntryTask>  # Staffroll:EntryTask
110001a0: push     {r4, lr}
110001a4: bl       #0x11000180  ; ->SetMinigameWorkForStaffroll
110001a8: ldr      r0, [pc, #0x28]  ; =0x49f700 gMemAlc
110001ac: mov      r3, #0
110001b0: mov      r2, r3
110001b4: ldr      r1, [r0]
110001b8: ldr      r0, [pc, #0x1c]  ; =0x96ae8
110001bc: bl       #0x11000188  ; ->_ZnwjP10MemAlcBasePKcj
110001c0: cmp      r0, #0
110001c4: blne     #0x11000190  ; ->EtcSys:mg::MGSystem
110001c8: mov      r1, r0
110001cc: ldr      r0, [pc, #0xc]  ; =0x49c620 gTaskMainMan
110001d0: pop      {r4, lr}
110001d4: b        #0x11000198  ; ->TaskMan::entry
110001d8: subeq    pc, sb, r0, lsl #14
110001dc: andeq    r6, sb, r8, ror #21
110001e0: subeq    ip, sb, r0, lsr #12

<Staffroll:nnroControlObject_>  # Staffroll:nnroControlObject_
110001e4: ldr      r2, [pc, #0x80]  ; =0x110011f4
110001e8: cmp      r1, #5
110001ec: push     {r4, lr}
110001f0: ldrlo    pc, [pc, r1, lsl #2]
110001f4: b        #0x11000250
110001f8: .word    0x1100020c
110001fc: .word    0x11000214
11000200: .word    0x1100021c
11000204: .word    0x11000228
11000208: .word    0x11000238
1100020c: ldr      r1, [pc, #0x5c]  ; =0x0
11000210: b        #0x11000220
11000214: str      r0, [r2]
11000218: b        #0x11000248
1100021c: ldr      r1, [r2]
11000220: str      r1, [r0]
11000224: b        #0x11000248
11000228: ldr      r1, [pc, #0x44]  ; =0x11000290
1100022c: str      r1, [r0]
11000230: ldr      r1, [pc, #0x40]  ; =0x11000290
11000234: b        #0x11000244
11000238: ldr      r1, [pc, #0x3c]  ; =0x11001000
1100023c: str      r1, [r0]
11000240: ldr      r1, [pc, #0x38]  ; =0x11001000
11000244: str      r1, [r0, #4]
11000248: mov      r0, #0
1100024c: pop      {r4, pc}
11000250: ldr      r0, [pc, #0x2c]  ; =0x30000000
11000254: mov      r0, r0
11000258: ldr      r0, [pc, #0x28]  ; =0x30000027
1100025c: nop      
11000260: mov      r0, r0
11000264: ldr      r0, [pc, #0x20]  ; =0xd8e12c21
11000268: pop      {r4, pc}
1100026c: strdne   r1, r2, [r0, -r4]
11000270: andeq    r0, r0, r0
11000274: swpne    r0, r0, [r0]
11000278: swpne    r0, r0, [r0]
1100027c: .word    0x11001000
11000280: .word    0x11001000
11000284: andlo    r0, r0, r0
11000288: andlo    r0, r0, r7, lsr #32
1100028c: stmle    r1!, {r0, r5, sl, fp, sp} ^
