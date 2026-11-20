
<->_ZnwjP10MemAlcBasePKcj>  # veneer->_ZnwjP10MemAlcBasePKcj
10800180: ldr      pc, [pc, #-4]
10800184: eoreq    r1, pc, r8, lsr #10

<->EtcSys:mg::MGSystem>  # veneer->EtcSys:_ZN2mg8MGSystemC1Ev
10800188: ldr      pc, [pc, #-4]
1080018c: andne    r7, r4, ip, lsr r2

<->TaskMan::entry>  # veneer->_ZN7TaskMan5entryEP4Task
10800190: ldr      pc, [pc, #-4]
10800194: .word    0x002f12b4

<MiniGame:EntryTask>  # MiniGame:EntryTask
10800198: ldr      r0, [pc, #0x2c]  ; =0x49f700 gMemAlc
1080019c: push     {r4, lr}
108001a0: mov      r3, #0
108001a4: mov      r2, r3
108001a8: ldr      r1, [r0]
108001ac: ldr      r0, [pc, #0x1c]  ; =0x96ae8
108001b0: bl       #0x10800180  ; ->_ZnwjP10MemAlcBasePKcj
108001b4: cmp      r0, #0
108001b8: blne     #0x10800188  ; ->EtcSys:mg::MGSystem
108001bc: mov      r1, r0
108001c0: ldr      r0, [pc, #0xc]  ; =0x49c620 gTaskMainMan
108001c4: pop      {r4, lr}
108001c8: b        #0x10800190  ; ->TaskMan::entry
108001cc: subeq    pc, sb, r0, lsl #14
108001d0: andeq    r6, sb, r8, ror #21
108001d4: subeq    ip, sb, r0, lsr #12

<MiniGame:nnroControlObject_>  # MiniGame:nnroControlObject_
108001d8: ldr      r2, [pc, #0x80]  ; =0x108011c0
108001dc: cmp      r1, #5
108001e0: push     {r4, lr}
108001e4: ldrlo    pc, [pc, r1, lsl #2]
108001e8: b        #0x10800244
108001ec: addne    r0, r0, r0, lsl #4
108001f0: addne    r0, r0, r8, lsl #4
108001f4: addne    r0, r0, r0, lsl r2
108001f8: addne    r0, r0, ip, lsl r2
108001fc: addne    r0, r0, ip, lsr #4
10800200: ldr      r1, [pc, #0x5c]  ; =0x0
10800204: b        #0x10800214
10800208: str      r0, [r2]
1080020c: b        #0x1080023c
10800210: ldr      r1, [r2]
10800214: str      r1, [r0]
10800218: b        #0x1080023c
1080021c: ldr      r1, [pc, #0x44]  ; =0x10800284
10800220: str      r1, [r0]
10800224: ldr      r1, [pc, #0x40]  ; =0x10800284
10800228: b        #0x10800238
1080022c: ldr      r1, [pc, #0x3c]  ; =0x10801000
10800230: str      r1, [r0]
10800234: ldr      r1, [pc, #0x38]  ; =0x10801000
10800238: str      r1, [r0, #4]
1080023c: mov      r0, #0
10800240: pop      {r4, pc}
10800244: ldr      r0, [pc, #0x2c]  ; =0x30000000
10800248: mov      r0, r0
1080024c: ldr      r0, [pc, #0x28]  ; =0x30000027
10800250: nop      
10800254: mov      r0, r0
10800258: ldr      r0, [pc, #0x20]  ; =0xd8e12c21
1080025c: pop      {r4, pc}
10800260: addne    r1, r0, r0, asr #3
10800264: andeq    r0, r0, r0
10800268: addne    r0, r0, r4, lsl #5
1080026c: addne    r0, r0, r4, lsl #5
10800270: addne    r1, r0, r0
10800274: addne    r1, r0, r0
10800278: andlo    r0, r0, r0
1080027c: andlo    r0, r0, r7, lsr #32
10800280: stmle    r1!, {r0, r5, sl, fp, sp} ^
