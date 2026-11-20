
<->SetMinigameWorkForTitle>  # veneer->_Z23SetMinigameWorkForTitlev
11800180: ldr      pc, [pc, #-4]
11800184: andseq   r4, r3, ip, lsr sp

<->_ZnwjP10MemAlcBasePKcj>  # veneer->_ZnwjP10MemAlcBasePKcj
11800188: ldr      pc, [pc, #-4]
1180018c: eoreq    r1, pc, r8, lsr #10

<->EtcSys:mg::MGSystem>  # veneer->EtcSys:_ZN2mg8MGSystemC1Ev
11800190: ldr      pc, [pc, #-4]
11800194: andne    r7, r4, ip, lsr r2

<->TaskMan::entry>  # veneer->_ZN7TaskMan5entryEP4Task
11800198: ldr      pc, [pc, #-4]
1180019c: .word    0x002f12b4

<Title:EntryTask>  # Title:EntryTask
118001a0: push     {r4, lr}
118001a4: bl       #0x11800180  ; ->SetMinigameWorkForTitle
118001a8: ldr      r0, [pc, #0x28]  ; =0x49f700 gMemAlc
118001ac: mov      r3, #0
118001b0: mov      r2, r3
118001b4: ldr      r1, [r0]
118001b8: ldr      r0, [pc, #0x1c]  ; =0x96ae8
118001bc: bl       #0x11800188  ; ->_ZnwjP10MemAlcBasePKcj
118001c0: cmp      r0, #0
118001c4: blne     #0x11800190  ; ->EtcSys:mg::MGSystem
118001c8: mov      r1, r0
118001cc: ldr      r0, [pc, #0xc]  ; =0x49c620 gTaskMainMan
118001d0: pop      {r4, lr}
118001d4: b        #0x11800198  ; ->TaskMan::entry
118001d8: subeq    pc, sb, r0, lsl #14
118001dc: andeq    r6, sb, r8, ror #21
118001e0: subeq    ip, sb, r0, lsr #12

<Title:nnroControlObject_>  # Title:nnroControlObject_
118001e4: ldr      r2, [pc, #0x80]  ; =0x118011ec
118001e8: cmp      r1, #5
118001ec: push     {r4, lr}
118001f0: ldrlo    pc, [pc, r1, lsl #2]
118001f4: b        #0x11800250
118001f8: orrne    r0, r0, ip, lsl #4
118001fc: orrne    r0, r0, r4, lsl r2
11800200: orrne    r0, r0, ip, lsl r2
11800204: orrne    r0, r0, r8, lsr #4
11800208: orrne    r0, r0, r8, lsr r2
1180020c: ldr      r1, [pc, #0x5c]  ; =0x0
11800210: b        #0x11800220
11800214: str      r0, [r2]
11800218: b        #0x11800248
1180021c: ldr      r1, [r2]
11800220: str      r1, [r0]
11800224: b        #0x11800248
11800228: ldr      r1, [pc, #0x44]  ; =0x11800290
1180022c: str      r1, [r0]
11800230: ldr      r1, [pc, #0x40]  ; =0x11800290
11800234: b        #0x11800244
11800238: ldr      r1, [pc, #0x3c]  ; =0x11801000
1180023c: str      r1, [r0]
11800240: ldr      r1, [pc, #0x38]  ; =0x11801000
11800244: str      r1, [r0, #4]
11800248: mov      r0, #0
1180024c: pop      {r4, pc}
11800250: ldr      r0, [pc, #0x2c]  ; =0x30000000
11800254: mov      r0, r0
11800258: ldr      r0, [pc, #0x28]  ; =0x30000027
1180025c: nop      
11800260: mov      r0, r0
11800264: ldr      r0, [pc, #0x20]  ; =0xd8e12c21
11800268: pop      {r4, pc}
1180026c: orrne    r1, r0, ip, ror #3
11800270: andeq    r0, r0, r0
11800274: .word    0x11800290
11800278: .word    0x11800290
1180027c: orrne    r1, r0, r0
11800280: orrne    r1, r0, r0
11800284: andlo    r0, r0, r0
11800288: andlo    r0, r0, r7, lsr #32
1180028c: stmle    r1!, {r0, r5, sl, fp, sp} ^
