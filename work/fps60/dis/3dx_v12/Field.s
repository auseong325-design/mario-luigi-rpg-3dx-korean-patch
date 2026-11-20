
<->_ZnwjP10MemAlcBasePKcj>  # veneer->_ZnwjP10MemAlcBasePKcj
12000180: ldr      pc, [pc, #-4]
12000184: eoreq    r7, r8, r0, asr #26

<->_ZdlPv>  # veneer->_ZdlPv
12000188: ldr      pc, [pc, #-4]
1200018c: eoreq    r6, r8, r4, lsl r5

<->nn::fs::detail::FileBase::TrySetPosition>  # veneer->_ZN2nn2fs6detail8FileBase14TrySetPositionEx
12000190: ldr      pc, [pc, #-4]
12000194: eoreq    lr, r7, r8, lsr #24

<->nn::err::CTR::ThrowFatalErrAll>  # veneer->_ZN2nn3err3CTR16ThrowFatalErrAllENS_6ResultEj
12000198: ldr      pc, [pc, #-4]
1200019c: eoreq    r6, r8, r0, lsr r5

<->nn::fs::detail::FileBase::TryRead>  # veneer->_ZN2nn2fs6detail8FileBase7TryReadEPiPvj
120001a0: ldr      pc, [pc, #-4]
120001a4: eoreq    r6, r8, r8, lsl #9

<->nn::fs::detail::FileBase::TrySeek>  # veneer->_ZN2nn2fs6detail8FileBase7TrySeekExNS0_12PositionBaseE
120001a8: ldr      pc, [pc, #-4]
120001ac: .word    0x002854d0

<->nndbgPanic>  # veneer->nndbgPanic
120001b0: ldr      pc, [pc, #-4]
120001b4: eoreq    r6, r8, ip, lsr #8

<->nn::fs::CTR::MPCore::detail::UserFileSystem::CloseFile>  # veneer->_ZN2nn2fs3CTR6MPCore6detail14UserFileSystem9CloseFileEPv
120001b8: ldr      pc, [pc, #-4]
120001bc: eoreq    r6, r8, r0, lsl r4

<->fld::GetParamStaffroll>  # veneer->_ZN3fld17GetParamStaffrollEv
120001c0: ldr      pc, [pc, #-4]
120001c4: eoreq    r4, sp, r8, asr r7

<->mbsinit>  # veneer->mbsinit
120001c8: ldr      pc, [pc, #-4]
120001cc: andseq   r0, r0, r5, lsr #1

<->mbrlen>  # veneer->mbrlen
120001d0: ldr      pc, [pc, #-4]
120001d4: ldrheq   r0, [r0], -r7

<->mbrtowc>  # veneer->mbrtowc
120001d8: ldr      pc, [pc, #-4]
120001dc: ldrsheq  r0, [r0], -sb

<->nn::fs::CTR::MPCore::detail::UserFileSystem::TryOpenFile>  # veneer->_ZN2nn2fs3CTR6MPCore6detail14UserFileSystem11TryOpenFileEPPvPKwj
120001e0: ldr      pc, [pc, #-4]
120001e4: eoreq    r5, r8, ip, lsl #19

<->nn::fs::detail::FileBase::TryGetSize>  # veneer->_ZNK2nn2fs6detail8FileBase10TryGetSizeEPx
120001e8: ldr      pc, [pc, #-4]
120001ec: eoreq    r6, r8, r8, ror #10

<->nn::cx::UncompressBLZ>  # veneer->_ZN2nn2cx13UncompressBLZEPvjj
120001f0: ldr      pc, [pc, #-4]
120001f4: mulseq   r0, r8, r1

<->nw::font::ResFont::RemoveResource>  # veneer->_ZN2nw4font7ResFont14RemoveResourceEv
120001f8: ldr      pc, [pc, #-4]
120001fc: andseq   sb, r0, r0, lsl #5

<->MessageDrawer::SetFontEx>  # veneer->_ZN13MessageDrawer9SetFontExEPv
12000200: ldr      pc, [pc, #-4]
12000204: ldrsheq  r6, [r3], -r8

<->nw::font::ResFontBase::GetLineFeed>  # veneer->_ZNK2nw4font11ResFontBase11GetLineFeedEv
12000208: ldr      pc, [pc, #-4]
1200020c: ldrhteq  r0, [r5], -r4

<->wcslen>  # veneer->wcslen
12000210: ldr      pc, [pc, #-4]
12000214: eoreq    r3, r8, r5, asr #10

<->Mem::Copy>  # veneer->_ZN3Mem4CopyEPvPKvj
12000218: ldr      pc, [pc, #-4]
1200021c: eoreq    pc, r7, r8, lsl #26

<->fld::MsgSys::getComMsgSys>  # veneer->_ZN3fld6MsgSys12getComMsgSysEv
12000220: ldr      pc, [pc, #-4]
12000224: eoreq    fp, pc, r8, asr #28

<->__aeabi_uidivmod>  # veneer->__aeabi_uidivmod
12000228: ldr      pc, [pc, #-4]
1200022c: eoreq    r1, r8, r8, lsr #12

<->MessageSimple::play>  # veneer->_ZN13MessageSimple4playEPKwPKNS_8InsParamEb
12000230: ldr      pc, [pc, #-4]
12000234: eoreq    r5, r7, r4, asr #8

<->Mem::Free>  # veneer->_ZN3Mem4FreeEPv
12000238: ldr      pc, [pc, #-4]
1200023c: eoreq    r5, r8, ip, lsr sp

<Field:CreateStaffrollCtrl>  # Field:CreateStaffrollCtrl
12000240: mov      r3, r1
12000244: mov      r1, r0
12000248: mov      r2, #0
1200024c: mov      r0, #0x2c
12000250: push     {r4, lr}
12000254: bl       #0x12000180  ; ->_ZnwjP10MemAlcBasePKcj
12000258: cmp      r0, #0
1200025c: beq      #0x12000278
12000260: ldr      r1, [pc, #0x14]  ; =0x12002274
12000264: mov      r2, #0
12000268: str      r1, [r0]
1200026c: strb     r2, [r0, #0x18]
12000270: str      r2, [r0, #0x1c]
12000274: str      r2, [r0, #0x20]
12000278: pop      {r4, pc}
1200027c: andne    r2, r0, #116, #4
12000280: b        #0x12000188  ; ->_ZdlPv
12000284: bx       lr
12000288: add      r0, r0, #4
1200028c: push     {r4, lr}
12000290: bl       #0x12000190  ; ->nn::fs::detail::FileBase::TrySetPosition
12000294: mov      r1, pc
12000298: lsrs     r2, r0, #0x1f
1200029c: beq      #0x120002a8
120002a0: pop      {r4, lr}
120002a4: b        #0x12000198  ; ->nn::err::CTR::ThrowFatalErrAll
120002a8: pop      {r4, pc}
120002ac: add      r0, r0, #4
120002b0: b        #0x12000190  ; ->nn::fs::detail::FileBase::TrySetPosition
120002b4: push     {r3, lr}
120002b8: mov      r3, r2
120002bc: mov      r2, r1
120002c0: mov      r1, sp
120002c4: add      r0, r0, #4
120002c8: bl       #0x120001a0  ; ->nn::fs::detail::FileBase::TryRead
120002cc: mov      r1, pc
120002d0: lsrs     r2, r0, #0x1f
120002d4: blne     #0x12000198  ; ->nn::err::CTR::ThrowFatalErrAll
120002d8: ldr      r0, [sp]
120002dc: pop      {r3, pc}
120002e0: push     {r3, lr}
120002e4: add      r0, r0, #4
120002e8: ldr      r1, [sp, #8]
120002ec: str      r1, [sp]
120002f0: bl       #0x120001a8  ; ->nn::fs::detail::FileBase::TrySeek
120002f4: mov      r1, pc
120002f8: lsrs     r2, r0, #0x1f
120002fc: beq      #0x12000308
12000300: pop      {r3, lr}
12000304: b        #0x12000198  ; ->nn::err::CTR::ThrowFatalErrAll
12000308: pop      {r3, pc}
1200030c: add      r0, r0, #4
12000310: b        #0x120001a0  ; ->nn::fs::detail::FileBase::TryRead
12000314: push     {r3, lr}
12000318: add      r0, r0, #4
1200031c: ldr      r1, [sp, #8]
12000320: str      r1, [sp]
12000324: bl       #0x120001a8  ; ->nn::fs::detail::FileBase::TrySeek
12000328: pop      {r3, pc}
1200032c: push     {r4, r5, r6, lr}
12000330: mov      r4, r0
12000334: add      r5, r0, #4
12000338: ldr      r0, [r0, #4]
1200033c: bics     r1, r0, #1
12000340: beq      #0x12000360
12000344: tst      r0, #1
12000348: blne     #0x120001b0  ; ->nndbgPanic
1200034c: ldr      r0, [r5]
12000350: bic      r0, r0, #1
12000354: bl       #0x120001b8  ; ->nn::fs::CTR::MPCore::detail::UserFileSystem::CloseFile
12000358: mov      r0, #0
1200035c: str      r0, [r5]
12000360: mov      r0, r4
12000364: pop      {r4, r5, r6, lr}
12000368: b        #0x12000188  ; ->_ZdlPv
1200036c: push     {r4, r5, r6, lr}
12000370: mov      r4, r0
12000374: add      r5, r0, #4
12000378: ldr      r0, [r0, #4]
1200037c: bics     r1, r0, #1
12000380: beq      #0x120003a0
12000384: tst      r0, #1
12000388: blne     #0x120001b0  ; ->nndbgPanic
1200038c: ldr      r0, [r5]
12000390: bic      r0, r0, #1
12000394: bl       #0x120001b8  ; ->nn::fs::CTR::MPCore::detail::UserFileSystem::CloseFile
12000398: mov      r0, #0
1200039c: str      r0, [r5]
120003a0: mov      r0, r4
120003a4: pop      {r4, r5, r6, pc}

<Field:fld::StaffrollCtrl::init>  # Field:_ZN3fld13StaffrollCtrl4initEPNS_6SystemEP10MemAlcBasej
120003a8: push     {r0, r1, r2, r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
120003ac: mov      r4, r0
120003b0: add      r0, pc, #0x38c
120003b4: add      r5, pc, #0x3a8
120003b8: mov      fp, #0
120003bc: vpush    {d8}
120003c0: sub      sp, sp, #0x23c
120003c4: str      r0, [sp, #0x20c]
120003c8: add      r0, r4, #0x10
120003cc: stm      r0, {r1, fp}
120003d0: bl       #0x120001c0  ; ->fld::GetParamStaffroll
120003d4: ldr      r0, [r0, #0x18]
120003d8: ldr      sb, [pc, #0x3a4]  ; =0x120021fc
120003dc: add      r6, sp, #0x214
120003e0: str      r0, [r4, #0x28]
120003e4: add      r0, sp, #0x210
120003e8: ldr      r1, [sb, #4]
120003ec: mov      r7, sp
120003f0: mov      r2, r1
120003f4: str      r1, [sp, #0x210]
120003f8: ldr      r2, [r2, #-0x30]
120003fc: ldr      r1, [sb, #8]
12000400: str      r1, [r0, r2]
12000404: add      r2, sp, #0x22c
12000408: mov      r0, #1
1200040c: str      fp, [sp, #0x214]
12000410: stm      r2, {r0, fp}
12000414: add      r0, sp, #0x230
12000418: str      fp, [sp, #0x234]
1200041c: bl       #0x120001c8  ; ->mbsinit
12000420: ldr      sl, [pc, #0x360]  ; =0x105
12000424: add      r2, sp, #0x230
12000428: mov      r0, r5
1200042c: mov      r1, sl
12000430: bl       #0x120001d0  ; ->mbrlen
12000434: movs     r8, r0
12000438: nop      
1200043c: beq      #0x12000464
12000440: mov      r2, r0
12000444: add      r3, sp, #0x230
12000448: mov      r1, r5
1200044c: mov      r0, r7
12000450: bl       #0x120001d8  ; ->mbrtowc
12000454: cmp      r0, #0
12000458: addne    r5, r5, r8
1200045c: addne    r7, r7, #2
12000460: bne      #0x12000424
12000464: strh     fp, [r7]
12000468: ldr      r2, [sp, #0x22c]
1200046c: str      fp, [r6, #0xc]
12000470: str      fp, [r6, #0x10]
12000474: str      fp, [r6, #4]
12000478: mov      r1, sp
1200047c: mov      r0, r6
12000480: str      fp, [r6, #8]
12000484: bl       #0x120001e0  ; ->nn::fs::CTR::MPCore::detail::UserFileSystem::TryOpenFile
12000488: tst      r0, #0x80000000
1200048c: movne    r1, pc
12000490: lsrsne   r2, r0, #0x1f
12000494: blne     #0x12000198  ; ->nn::err::CTR::ThrowFatalErrAll
12000498: ldr      r0, [sb]
1200049c: str      r0, [r6, #-4]!
120004a0: ldr      r0, [r0, #-0x30]
120004a4: ldr      r1, [sb, #0xc]
120004a8: str      r1, [r6, r0]
120004ac: add      r0, sp, #0x214
120004b0: mov      r1, sp
120004b4: bl       #0x120001e8  ; ->nn::fs::detail::FileBase::TryGetSize
120004b8: mov      r1, pc
120004bc: lsrs     r2, r0, #0x1f
120004c0: blne     #0x12000198  ; ->nn::err::CTR::ThrowFatalErrAll
120004c4: ldr      r5, [sp]
120004c8: mov      r1, #2
120004cc: add      r0, sp, #0x214
120004d0: mvn      r2, #3
120004d4: mvn      r3, #0
120004d8: str      r1, [sp]
120004dc: bl       #0x120001a8  ; ->nn::fs::detail::FileBase::TrySeek
120004e0: mov      r1, pc
120004e4: lsrs     r2, r0, #0x1f
120004e8: blne     #0x12000198  ; ->nn::err::CTR::ThrowFatalErrAll
120004ec: add      r0, sp, #0x214
120004f0: add      r2, sp, #0x228
120004f4: mov      r3, #4
120004f8: mov      r1, sp
120004fc: bl       #0x120001a0  ; ->nn::fs::detail::FileBase::TryRead
12000500: mov      r1, pc
12000504: lsrs     r2, r0, #0x1f
12000508: blne     #0x12000198  ; ->nn::err::CTR::ThrowFatalErrAll
1200050c: ldr      r0, [sp, #0x228]
12000510: add      r6, sp, #0x24c
12000514: add      r1, r0, r5
12000518: ldr      r0, [sp, #0x24c]
1200051c: str      r1, [sp, #0x228]
12000520: ldr      r0, [r0]
12000524: ldr      r3, [r0, #0xc]
12000528: ldm      r6, {r0, r2}
1200052c: blx      r3
12000530: mov      r1, #0
12000534: str      r0, [r4, #0xc]
12000538: add      r0, sp, #0x214
1200053c: mov      r2, r1
12000540: mov      r3, r1
12000544: str      r1, [sp]
12000548: bl       #0x120001a8  ; ->nn::fs::detail::FileBase::TrySeek
1200054c: mov      r1, pc
12000550: lsrs     r2, r0, #0x1f
12000554: blne     #0x12000198  ; ->nn::err::CTR::ThrowFatalErrAll
12000558: ldr      r2, [r4, #0xc]
1200055c: add      r0, sp, #0x214
12000560: mov      r3, r5
12000564: mov      r1, sp
12000568: bl       #0x120001a0  ; ->nn::fs::detail::FileBase::TryRead
1200056c: mov      r1, pc
12000570: lsrs     r2, r0, #0x1f
12000574: blne     #0x12000198  ; ->nn::err::CTR::ThrowFatalErrAll
12000578: ldr      r0, [r4, #0xc]
1200057c: ldr      r2, [sp, #0x228]
12000580: mov      r1, r5
12000584: bl       #0x120001f0  ; ->nn::cx::UncompressBLZ
12000588: ldr      r0, [r4, #0xc]
1200058c: ldr      r1, [r0], #4
12000590: str      r0, [r4, #0x20]
12000594: str      r1, [r4, #0x1c]
12000598: ldr      r0, [sp, #0x214]
1200059c: bics     r0, r0, #1
120005a0: beq      #0x120005c0
120005a4: ldr      r0, [sp, #0x214]
120005a8: tst      r0, #1
120005ac: blne     #0x120001b0  ; ->nndbgPanic
120005b0: ldr      r0, [sp, #0x214]
120005b4: bic      r0, r0, #1
120005b8: bl       #0x120001b8  ; ->nn::fs::CTR::MPCore::detail::UserFileSystem::CloseFile
120005bc: str      fp, [sp, #0x214]
120005c0: ldr      r7, [pc, #0x1bc]  ; =0x120021fc
120005c4: add      r0, sp, #0x210
120005c8: ldr      r6, [sp, #0x20c]
120005cc: add      r5, sp, #0x214
120005d0: ldr      r1, [r7, #4]
120005d4: mov      r8, sp
120005d8: mov      r2, r1
120005dc: str      r1, [sp, #0x210]
120005e0: ldr      r2, [r2, #-0x30]
120005e4: ldr      r1, [r7, #8]
120005e8: str      r1, [r0, r2]
120005ec: mov      r0, #1
120005f0: str      r0, [sp, #0x20c]
120005f4: str      fp, [sp, #0x214]
120005f8: add      r0, sp, #0x228
120005fc: str      fp, [sp, #0x228]
12000600: str      fp, [sp, #0x22c]
12000604: bl       #0x120001c8  ; ->mbsinit
12000608: add      r2, sp, #0x228
1200060c: mov      r1, sl
12000610: mov      r0, r6
12000614: bl       #0x120001d0  ; ->mbrlen
12000618: movs     sb, r0
1200061c: nop      
12000620: beq      #0x12000648
12000624: mov      r2, r0
12000628: add      r3, sp, #0x228
1200062c: mov      r1, r6
12000630: mov      r0, r8
12000634: bl       #0x120001d8  ; ->mbrtowc
12000638: cmp      r0, #0
1200063c: addne    r6, r6, sb
12000640: addne    r8, r8, #2
12000644: bne      #0x12000608
12000648: strh     fp, [r8]
1200064c: ldr      r2, [sp, #0x20c]
12000650: str      fp, [r5, #0xc]
12000654: str      fp, [r5, #0x10]
12000658: str      fp, [r5, #4]
1200065c: mov      r1, sp
12000660: mov      r0, r5
12000664: str      fp, [r5, #8]
12000668: bl       #0x120001e0  ; ->nn::fs::CTR::MPCore::detail::UserFileSystem::TryOpenFile
1200066c: tst      r0, #0x80000000
12000670: movne    r1, pc
12000674: lsrsne   r2, r0, #0x1f
12000678: blne     #0x12000198  ; ->nn::err::CTR::ThrowFatalErrAll
1200067c: ldr      r0, [r7]
12000680: str      r0, [r5, #-4]!
12000684: ldr      r0, [r0, #-0x30]
12000688: ldr      r1, [r7, #0xc]
1200068c: str      r1, [r5, r0]
12000690: add      r0, sp, #0x214
12000694: mov      r1, sp
12000698: bl       #0x120001e8  ; ->nn::fs::detail::FileBase::TryGetSize
1200069c: mov      r1, pc
120006a0: lsrs     r2, r0, #0x1f
120006a4: blne     #0x12000198  ; ->nn::err::CTR::ThrowFatalErrAll
120006a8: ldr      r0, [sp, #0x24c]
120006ac: ldr      r5, [sp]
120006b0: add      r6, sp, #0x24c
120006b4: ldr      r0, [r0]
120006b8: mov      r1, r5
120006bc: ldr      r3, [r0, #0xc]
120006c0: ldm      r6, {r0, r2}
120006c4: blx      r3
120006c8: add      ip, sp, #0x214
120006cc: mov      r2, r0
120006d0: str      r0, [r4, #8]
120006d4: mov      r3, r5
120006d8: mov      r1, sp
120006dc: mov      r0, ip
120006e0: bl       #0x120001a0  ; ->nn::fs::detail::FileBase::TryRead
120006e4: mov      r1, pc
120006e8: lsrs     r2, r0, #0x1f
120006ec: blne     #0x12000198  ; ->nn::err::CTR::ThrowFatalErrAll
120006f0: ldr      r0, [sp, #0x214]
120006f4: bics     r0, r0, #1
120006f8: beq      #0x12000718
120006fc: ldr      r0, [sp, #0x214]
12000700: tst      r0, #1
12000704: blne     #0x120001b0  ; ->nndbgPanic
12000708: ldr      r0, [sp, #0x214]
1200070c: bic      r0, r0, #1
12000710: bl       #0x120001b8  ; ->nn::fs::CTR::MPCore::detail::UserFileSystem::CloseFile
12000714: str      fp, [sp, #0x214]
12000718: ldr      r0, [pc, #0x6c]  ; =0x3fc260
1200071c: bl       #0x120001f8  ; ->nw::font::ResFont::RemoveResource
12000720: cmp      r0, #0
12000724: nop      
12000728: blne     #0x12000188  ; ->_ZdlPv
1200072c: ldr      r0, [r4, #8]
12000730: nop      
12000734: bl       #0x12000200  ; ->MessageDrawer::SetFontEx
12000738: nop      
1200073c: nop      
12000740: b        #0x12000790
12000744: blo      #0x13b5c514
12000748: cmnvs    r4, pc, lsr #6
1200074c: svcvs    #0x726666
12000750: stcvs    p12, c6, [pc, #-0x1b0]!
12000754: svcvs    #0x697261
12000758: mcrvs    p6, #3, r6, c15, c15, #2
1200075c: uqsub16vs r2, r2, r4
12000760: rsbseq   r6, r4, r6, ror #28
12000764: blo      #0x13b5c534
12000768: cmnvs    r4, pc, lsr #6
1200076c: svcvs    #0x726666
12000770: bmi      #0x12bdb928
12000774: ldrbvc   r2, [r3], #-0xf50
12000778: rsbvc    r6, r6, #0x6100000
1200077c: cdphs    p12, #6, c6, c12, c15, #3
12000780: rsbeq    r6, lr, r2, ror #18
12000784: andne    r2, r0, #252, #2
12000788: andeq    r0, r0, r5, lsl #2
1200078c: eorseq   ip, pc, r0, ror #4
12000790: ldr      r0, [sp, #0x214]
12000794: bics     r0, r0, #1
12000798: beq      #0x120007b8
1200079c: ldr      r0, [sp, #0x214]
120007a0: tst      r0, #1
120007a4: blne     #0x120001b0  ; ->nndbgPanic
120007a8: ldr      r0, [sp, #0x214]
120007ac: bic      r0, r0, #1
120007b0: bl       #0x120001b8  ; ->nn::fs::CTR::MPCore::detail::UserFileSystem::CloseFile
120007b4: str      fp, [sp, #0x214]
120007b8: vldr     s0, [pc, #0xac]  ; =0x0 (0)
120007bc: ldr      r3, [r4, #0x1c]
120007c0: add      r0, r4, #0x1c
120007c4: vmov.f32 s16, s0
120007c8: cmp      r3, #0
120007cc: beq      #0x12000838
120007d0: tst      r3, #1
120007d4: mov      r2, r0
120007d8: mov      r1, #0
120007dc: mov      r5, #0x5c
120007e0: beq      #0x120007f4
120007e4: ldr      r0, [r2, #4]
120007e8: mov      r1, #1
120007ec: vldr     s1, [r0, #0x5c]
120007f0: vadd.f32 s16, s1, s16
120007f4: lsrs     r0, r3, #1
120007f8: ldrne    r2, [r2, #4]
120007fc: movne    ip, #0xbc
12000800: beq      #0x12000834
12000804: add      r3, r1, r1, lsl #1
12000808: subs     r0, r0, #1
1200080c: add      r6, r5, r3, lsl #5
12000810: add      r3, ip, r3, lsl #5
12000814: add      r6, r6, r2
12000818: add      r3, r3, r2
1200081c: vldr     s2, [r6]
12000820: vldr     s1, [r3]
12000824: add      r1, r1, #2
12000828: vadd.f32 s16, s2, s16
1200082c: vadd.f32 s0, s1, s0
12000830: bne      #0x12000804
12000834: vadd.f32 s16, s16, s0
12000838: nop      
1200083c: bl       #0x120001c0  ; ->fld::GetParamStaffroll
12000840: vldr     s1, [pc, #0x28]  ; =0x43f00000 (480)
12000844: vldr     s0, [r0, #0x14]
12000848: mov      r0, #1
1200084c: vsub.f32 s1, s16, s1
12000850: vsub.f32 s0, s1, s0
12000854: vstr     s0, [r4, #0x24]
12000858: strb     r0, [r4, #0x18]
1200085c: add      sp, sp, #0x23c
12000860: vpop     {d8}
12000864: add      sp, sp, #0x10
12000868: pop      {r4, r5, r6, r7, r8, sb, sl, fp, pc}
1200086c: andeq    r0, r0, r0
12000870: mvnsmi   r0, #0
12000874: push     {r4, r5, r6, r7, r8, sb, sl, fp, ip, lr}
12000878: mov      r4, r1
1200087c: mov      r8, r3
12000880: mov      sb, r0
12000884: mov      r7, r2
12000888: ldr      r0, [pc, #0xf4]  ; =0x3fc260
1200088c: vpush    {d8}
12000890: ldr      sl, [sp, #0x30]
12000894: bl       #0x12000208  ; ->nw::font::ResFontBase::GetLineFeed
12000898: vmov     s0, r0
1200089c: cmp      r7, r8
120008a0: vldrls   s17, [pc, #0xe0]  ; =0x42c80000 (100)
120008a4: mov      r5, r7
120008a8: vcvt.f32.s32 s16, s0
120008ac: bhi      #0x12000974
120008b0: ldr      r3, [sb, #0x20]
120008b4: mov      r1, #0xe
120008b8: strh     r1, [r4], #2
120008bc: mov      r0, #0
120008c0: strh     r0, [r4], #2
120008c4: mov      r2, #2
120008c8: add      ip, r5, r5, lsl #1
120008cc: strh     r2, [r4], #2
120008d0: add      r6, r3, ip, lsl #5
120008d4: strh     r2, [r4], #2
120008d8: vldr     s0, [r6, #0x5c]
120008dc: cmp      r5, r7
120008e0: vmul.f32 s1, s0, s17
120008e4: vdiv.f32 s0, s1, s16
120008e8: vcvt.u32.f32 s0, s0
120008ec: vmov     r2, s0
120008f0: strh     r2, [r4], #2
120008f4: strh     r1, [r4], #2
120008f8: mov      r1, #3
120008fc: strh     r0, [r4], #2
12000900: mov      r0, #4
12000904: strh     r1, [r4], #2
12000908: strh     r0, [r4], #2
1200090c: ldr      r0, [r6, #0x58]
12000910: lsr      r0, r0, #0x10
12000914: strh     r0, [r4], #2
12000918: ldrb     r0, [r6, #0x58]
1200091c: add      r0, r0, sl, lsl #8
12000920: strh     r0, [r4], #2
12000924: beq      #0x12000930
12000928: mov      r0, #0xa
1200092c: strh     r0, [r4], #2
12000930: mov      r0, r6
12000934: bl       #0x12000210  ; ->wcslen
12000938: movs     fp, r0
1200093c: nop      
12000940: beq      #0x12000960
12000944: lsl      r2, fp, #1
12000948: mov      r1, r6
1200094c: mov      r0, r4
12000950: bl       #0x12000218  ; ->Mem::Copy
12000954: add      r4, r4, fp, lsl #1
12000958: nop      
1200095c: b        #0x12000968
12000960: mov      r0, #0x20
12000964: strh     r0, [r4], #2
12000968: add      r5, r5, #1
1200096c: cmp      r5, r8
12000970: bls      #0x120008b0
12000974: mov      r0, #0
12000978: strh     r0, [r4]
1200097c: vpop     {d8}
12000980: pop      {r4, r5, r6, r7, r8, sb, sl, fp, ip, pc}
12000984: eorseq   ip, pc, r0, ror #4
12000988: sbcmi    r0, r8, #0

<Field:fld::StaffrollCtrl::update>  # Field:_ZN3fld13StaffrollCtrl6updateEv
1200098c: push     {r4, r5, r6, r7, r8, sb, sl, fp, ip, lr}
12000990: mov      r4, r0
12000994: vpush    {d8, d9}
12000998: sub      sp, sp, #0x1040
1200099c: ldr      r0, [r0, #0x10]
120009a0: add      r0, r0, #0x1000
120009a4: ldr      r0, [r0, #0xb30]
120009a8: bl       #0x12000220  ; ->fld::MsgSys::getComMsgSys
120009ac: mov      r5, r0
120009b0: bl       #0x120001c0  ; ->fld::GetParamStaffroll
120009b4: ldr      r6, [r0]
120009b8: bl       #0x120001c0  ; ->fld::GetParamStaffroll
120009bc: ldr      r0, [r0, #4]
120009c0: ldr      r1, [r4, #0x14]
120009c4: vldr     s3, [r4, #0x28]
120009c8: add      r0, r0, r6
120009cc: vmov     s0, r1
120009d0: vmov     s1, r0
120009d4: vldr     s2, [r4, #0x24]
120009d8: vcvt.f32.u32 s4, s0
120009dc: vcvt.f32.u32 s0, s1
120009e0: vnmls.f32 s0, s4, s3
120009e4: vcvt.u32.f32 s16, s0
120009e8: vcvt.f32.u32 s0, s16
120009ec: vcmpe.f32 s2, s0
120009f0: vmrs     apsr_nzcv, fpscr
120009f4: vcvtlo.u32.f32 s16, s2
120009f8: cmp      r1, r6
120009fc: movhs    r0, #0xff
12000a00: bhs      #0x12000a10
12000a04: rsb      r0, r1, r1, lsl #8
12000a08: mov      r1, r6
12000a0c: bl       #0x12000228  ; ->__aeabi_uidivmod
12000a10: vcvt.f32.u32 s16, s16
12000a14: and      r6, r0, #0xff
12000a18: ldr      r0, [r4, #0x1c]
12000a1c: vldr     s17, [pc, #0x39c]  ; =0x0 (0)
12000a20: mov      r7, #0
12000a24: cmp      r0, #0
12000a28: vldrhi   s19, [pc, #0x394]  ; =0x43700000 (240)
12000a2c: add      sl, sp, #4
12000a30: add      sb, sp, #0x10
12000a34: mov      r8, r7
12000a38: bls      #0x12000ab4
12000a3c: ldr      r0, [r4, #0x20]
12000a40: add      r1, r8, r8, lsl #1
12000a44: add      r0, r0, r1, lsl #5
12000a48: vldr     s0, [r0, #0x5c]
12000a4c: vadd.f32 s18, s17, s0
12000a50: vcmpe.f32 s18, s16
12000a54: vmrs     apsr_nzcv, fpscr
12000a58: ble      #0x12000aa0
12000a5c: vsub.f32 s0, s16, s17
12000a60: add      r0, sb, r7, lsl #2
12000a64: str      r8, [sl, r7, lsl #2]
12000a68: cmp      r7, #0
12000a6c: vstr     s0, [r0]
12000a70: beq      #0x12000a84
12000a74: cmp      r7, #1
12000a78: vaddeq.f32 s16, s16, s19
12000a7c: beq      #0x12000a98
12000a80: b        #0x12000abc
12000a84: nop      
12000a88: bl       #0x120001c0  ; ->fld::GetParamStaffroll
12000a8c: vadd.f32 s1, s16, s19
12000a90: vldr     s0, [r0, #0x14]
12000a94: vadd.f32 s16, s0, s1
12000a98: add      r0, r7, #1
12000a9c: and      r7, r0, #0xff
12000aa0: vmov.f32 s17, s18
12000aa4: ldr      r0, [r4, #0x1c]
12000aa8: add      r8, r8, #1
12000aac: cmp      r0, r8
12000ab0: bhi      #0x12000a3c
12000ab4: sub      r0, r0, #1
12000ab8: str      r0, [sp, #0xc]
12000abc: ldr      r0, [sp, #8]
12000ac0: ldr      r2, [sp, #4]
12000ac4: add      r1, sp, #0x20
12000ac8: sub      r3, r0, #1
12000acc: mov      r0, r4
12000ad0: str      r6, [sp]
12000ad4: bl       #0x12000874
12000ad8: add      r7, r5, #0x2dc00
12000adc: add      r7, r7, #0x2a8
12000ae0: ldr      r0, [r7]
12000ae4: ldr      r1, [r0]
12000ae8: mov      r0, r7
12000aec: blx      r1
12000af0: add      r8, r7, #0x6000
12000af4: mov      r0, #0x400
12000af8: add      sb, r7, #0x5000
12000afc: str      r0, [r8, #0xcc0]
12000b00: ldr      r0, [sb, #0x83c]
12000b04: mov      fp, #0
12000b08: orr      r0, r0, #0x10
12000b0c: str      r0, [sb, #0x83c]
12000b10: strb     fp, [sb, #0xabd]
12000b14: bl       #0x120001c0  ; ->fld::GetParamStaffroll
12000b18: vldr     s17, [pc, #0x2a8]  ; =0x42f00000 (120)
12000b1c: vldr     s0, [sp, #0x10]
12000b20: ldr      r0, [r0, #8]
12000b24: add      r1, r7, #0x5800
12000b28: vadd.f32 s0, s0, s17
12000b2c: str      r0, [r1, #0x2b4]
12000b30: vstr     s0, [r1, #0x2b8]
12000b34: ldrb     r0, [sb, #0x83c]
12000b38: tst      r0, #1
12000b3c: beq      #0x12000b50
12000b40: ldr      r0, [r7]
12000b44: ldr      r1, [r0, #0x28]
12000b48: mov      r0, r7
12000b4c: blx      r1
12000b50: mov      r0, #8
12000b54: strb     r0, [r8, #0xad8]
12000b58: ldr      r8, [pc, #0x26c]  ; =0x3fc260
12000b5c: mov      r3, #0
12000b60: mov      r2, r3
12000b64: str      r8, [sb, #0x828]
12000b68: add      sb, sp, #0x20
12000b6c: mov      r1, sb
12000b70: mov      r0, r7
12000b74: bl       #0x12000230  ; ->MessageSimple::play
12000b78: lsl      r2, r6, #8
12000b7c: mov      r0, #0
12000b80: add      r1, sb, r0, lsl #1
12000b84: ldrh     r3, [r1]
12000b88: cmp      r3, #0xe
12000b8c: beq      #0x12000df4
12000b90: add      r0, r0, #1
12000b94: cmp      r0, #0x400
12000b98: blt      #0x12000b80
12000b9c: add      r7, r5, #0x27000
12000ba0: add      r7, r7, #0x148
12000ba4: ldr      r0, [r7]
12000ba8: ldr      r1, [r0]
12000bac: mov      r0, r7
12000bb0: blx      r1
12000bb4: add      sl, r7, #0x6000
12000bb8: mov      r0, #0x400
12000bbc: add      sb, r7, #0x5000
12000bc0: str      r0, [sl, #0xcc0]
12000bc4: ldr      r0, [sb, #0x83c]
12000bc8: orr      r0, r0, #0x10
12000bcc: str      r0, [sb, #0x83c]
12000bd0: strb     fp, [sb, #0xabd]
12000bd4: bl       #0x120001c0  ; ->fld::GetParamStaffroll
12000bd8: vldr     s16, [r0, #8]
12000bdc: nop      
12000be0: bl       #0x120001c0  ; ->fld::GetParamStaffroll
12000be4: vldr     s0, [r0, #0xc]
12000be8: vadd.f32 s16, s16, s0
12000bec: bl       #0x120001c0  ; ->fld::GetParamStaffroll
12000bf0: vldr     s0, [r0, #0x10]
12000bf4: vldr     s1, [sp, #0x10]
12000bf8: add      r0, r7, #0x5800
12000bfc: vadd.f32 s0, s0, s1
12000c00: vstr     s16, [r0, #0x2b4]
12000c04: vadd.f32 s0, s0, s17
12000c08: vstr     s0, [r0, #0x2b8]
12000c0c: ldrb     r0, [sb, #0x83c]
12000c10: tst      r0, #1
12000c14: beq      #0x12000c28
12000c18: ldr      r0, [r7]
12000c1c: ldr      r1, [r0, #0x28]
12000c20: mov      r0, r7
12000c24: blx      r1
12000c28: mov      r0, #8
12000c2c: strb     r0, [sl, #0xad8]
12000c30: mov      r3, #0
12000c34: mov      r2, r3
12000c38: add      r1, sp, #0x20
12000c3c: mov      r0, r7
12000c40: str      r8, [sb, #0x828]
12000c44: bl       #0x12000230  ; ->MessageSimple::play
12000c48: ldrd     r2, r3, [sp, #8]
12000c4c: add      r1, sp, #0x820
12000c50: mov      r0, r4
12000c54: str      r6, [sp]
12000c58: bl       #0x12000874
12000c5c: add      sl, r5, #0x3b800
12000c60: add      sl, sl, #0x168
12000c64: ldr      r0, [sl]
12000c68: ldr      r1, [r0]
12000c6c: mov      r0, sl
12000c70: blx      r1
12000c74: ldr      r0, [pc, #0x154]  ; =0x401
12000c78: add      r7, sl, #0x6000
12000c7c: add      fp, sl, #0x5000
12000c80: str      r0, [r7, #0xcc0]
12000c84: ldr      r1, [fp, #0x83c]
12000c88: mov      r0, #0
12000c8c: orr      r1, r1, #0x10
12000c90: str      r1, [fp, #0x83c]
12000c94: strb     r0, [fp, #0xabd]
12000c98: bl       #0x120001c0  ; ->fld::GetParamStaffroll
12000c9c: vldr     s0, [sp, #0x14]
12000ca0: ldr      r0, [r0, #8]
12000ca4: add      r1, sl, #0x5800
12000ca8: vadd.f32 s0, s0, s17
12000cac: str      r0, [r1, #0x2b4]
12000cb0: vstr     s0, [r1, #0x2b8]
12000cb4: ldrb     r0, [fp, #0x83c]
12000cb8: tst      r0, #1
12000cbc: beq      #0x12000cd0
12000cc0: ldr      r0, [sl]
12000cc4: ldr      r1, [r0, #0x28]
12000cc8: mov      r0, sl
12000ccc: blx      r1
12000cd0: mov      sb, #8
12000cd4: strb     sb, [r7, #0xad8]
12000cd8: mov      r3, #0
12000cdc: add      r7, sp, #0x820
12000ce0: mov      r2, r3
12000ce4: mov      r1, r7
12000ce8: mov      r0, sl
12000cec: str      r8, [fp, #0x828]
12000cf0: bl       #0x12000230  ; ->MessageSimple::play
12000cf4: mov      fp, #0
12000cf8: lsl      r2, r6, #8
12000cfc: mov      r0, fp
12000d00: add      r1, r7, r0, lsl #1
12000d04: ldrh     r3, [r1]
12000d08: cmp      r3, #0xe
12000d0c: beq      #0x12000e1c
12000d10: add      r0, r0, #1
12000d14: cmp      r0, #0x400
12000d18: blt      #0x12000d00
12000d1c: add      r5, r5, #0x34c00
12000d20: add      r5, r5, #8
12000d24: ldr      r0, [r5]
12000d28: ldr      r1, [r0]
12000d2c: mov      r0, r5
12000d30: blx      r1
12000d34: ldr      r0, [pc, #0x94]  ; =0x401
12000d38: add      sl, r5, #0x6000
12000d3c: add      r6, r5, #0x5000
12000d40: str      r0, [sl, #0xcc0]
12000d44: ldr      r0, [r6, #0x83c]
12000d48: orr      r0, r0, #0x10
12000d4c: str      r0, [r6, #0x83c]
12000d50: strb     fp, [r6, #0xabd]
12000d54: bl       #0x120001c0  ; ->fld::GetParamStaffroll
12000d58: vldr     s16, [r0, #8]
12000d5c: nop      
12000d60: bl       #0x120001c0  ; ->fld::GetParamStaffroll
12000d64: vldr     s0, [r0, #0xc]
12000d68: vadd.f32 s16, s16, s0
12000d6c: bl       #0x120001c0  ; ->fld::GetParamStaffroll
12000d70: vldr     s0, [r0, #0x10]
12000d74: vldr     s1, [sp, #0x14]
12000d78: add      r0, r5, #0x5800
12000d7c: vadd.f32 s0, s0, s1
12000d80: vstr     s16, [r0, #0x2b4]
12000d84: vadd.f32 s0, s0, s17
12000d88: vstr     s0, [r0, #0x2b8]
12000d8c: ldrb     r0, [r6, #0x83c]
12000d90: tst      r0, #1
12000d94: beq      #0x12000da8
12000d98: ldr      r0, [r5]
12000d9c: ldr      r1, [r0, #0x28]
12000da0: mov      r0, r5
12000da4: blx      r1
12000da8: mov      r3, #0
12000dac: mov      r2, r3
12000db0: mov      r1, r7
12000db4: mov      r0, r5
12000db8: strb     sb, [sl, #0xad8]
12000dbc: b        #0x12000dd4
12000dc0: andeq    r0, r0, r0
12000dc4: cmnmi    r0, #0
12000dc8: rscsmi   r0, r0, #0
12000dcc: eorseq   ip, pc, r0, ror #4
12000dd0: andeq    r0, r0, r1, lsl #8
12000dd4: str      r8, [r6, #0x828]
12000dd8: bl       #0x12000230  ; ->MessageSimple::play
12000ddc: ldr      r0, [r4, #0x14]
12000de0: add      r0, r0, #1
12000de4: str      r0, [r4, #0x14]
12000de8: add      sp, sp, #0x1040
12000dec: vpop     {d8, d9}
12000df0: pop      {r4, r5, r6, r7, r8, sb, sl, fp, ip, pc}
12000df4: ldrh     r3, [r1, #2]
12000df8: cmp      r3, #0
12000dfc: ldrheq   r3, [r1, #4]
12000e00: cmpeq    r3, #3
12000e04: strheq   r2, [r1, #0xa]
12000e08: strheq   fp, [r1, #8]
12000e0c: ldrh     r1, [r1, #6]
12000e10: add      r0, r0, r1, lsr #1
12000e14: add      r0, r0, #2
12000e18: b        #0x12000b90
12000e1c: ldrh     r3, [r1, #2]
12000e20: cmp      r3, #0
12000e24: ldrheq   r3, [r1, #4]
12000e28: cmpeq    r3, #3
12000e2c: strheq   r2, [r1, #0xa]
12000e30: strheq   fp, [r1, #8]
12000e34: ldrh     r1, [r1, #6]
12000e38: add      r0, r0, r1, lsr #1
12000e3c: add      r0, r0, #2
12000e40: b        #0x12000d10
12000e44: push     {r4, r5, r6, lr}
12000e48: mov      r4, r0
12000e4c: ldr      r0, [pc, #0xa0]  ; =0x12002274
12000e50: str      r0, [r4]
12000e54: ldrb     r0, [r4, #0x18]
12000e58: cmp      r0, #0
12000e5c: beq      #0x12000ee8
12000e60: ldr      r0, [r4, #0x10]
12000e64: add      r0, r0, #0x1000
12000e68: ldr      r0, [r0, #0xb30]
12000e6c: bl       #0x12000220  ; ->fld::MsgSys::getComMsgSys
12000e70: cmp      r0, #0
12000e74: beq      #0x12000eb8
12000e78: add      r3, r0, #0x2c000
12000e7c: add      r1, r0, #0x33000
12000e80: ldr      ip, [r3, #0x984]
12000e84: add      r2, r0, #0x3a000
12000e88: add      r0, r0, #0x41000
12000e8c: bic      ip, ip, #0x10
12000e90: str      ip, [r3, #0x984]
12000e94: ldr      r3, [r1, #0x6e4]
12000e98: bic      r3, r3, #0x10
12000e9c: str      r3, [r1, #0x6e4]
12000ea0: ldr      r1, [r2, #0x444]
12000ea4: bic      r1, r1, #0x10
12000ea8: str      r1, [r2, #0x444]
12000eac: ldr      r1, [r0, #0x1a4]
12000eb0: bic      r1, r1, #0x10
12000eb4: str      r1, [r0, #0x1a4]
12000eb8: ldr      r0, [pc, #0x38]  ; =0x3fc260
12000ebc: bl       #0x120001f8  ; ->nw::font::ResFont::RemoveResource
12000ec0: ldr      r0, [r4, #8]
12000ec4: nop      
12000ec8: bl       #0x12000238  ; ->Mem::Free
12000ecc: mov      r5, #0
12000ed0: str      r5, [r4, #8]
12000ed4: ldr      r0, [r4, #0xc]
12000ed8: bl       #0x12000238  ; ->Mem::Free
12000edc: str      r5, [r4, #0xc]
12000ee0: str      r5, [r4, #8]
12000ee4: strb     r5, [r4, #0x18]
12000ee8: mov      r0, r4
12000eec: pop      {r4, r5, r6, lr}
12000ef0: b        #0x12000188  ; ->_ZdlPv
12000ef4: andne    r2, r0, #116, #4
12000ef8: eorseq   ip, pc, r0, ror #4
12000efc: push     {r4, r5, r6, lr}
12000f00: mov      r4, r0
12000f04: ldr      r0, [pc, #0x9c]  ; =0x12002274
12000f08: str      r0, [r4]
12000f0c: ldrb     r0, [r4, #0x18]
12000f10: cmp      r0, #0
12000f14: beq      #0x12000fa0
12000f18: ldr      r0, [r4, #0x10]
12000f1c: add      r0, r0, #0x1000
12000f20: ldr      r0, [r0, #0xb30]
12000f24: bl       #0x12000220  ; ->fld::MsgSys::getComMsgSys
12000f28: cmp      r0, #0
12000f2c: beq      #0x12000f70
12000f30: add      r3, r0, #0x2c000
12000f34: add      r2, r0, #0x33000
12000f38: ldr      ip, [r3, #0x984]
12000f3c: add      r1, r0, #0x3a000
12000f40: add      r0, r0, #0x41000
12000f44: bic      ip, ip, #0x10
12000f48: str      ip, [r3, #0x984]
12000f4c: ldr      r3, [r2, #0x6e4]
12000f50: bic      r3, r3, #0x10
12000f54: str      r3, [r2, #0x6e4]
12000f58: ldr      r2, [r1, #0x444]
12000f5c: bic      r2, r2, #0x10
12000f60: str      r2, [r1, #0x444]
12000f64: ldr      r1, [r0, #0x1a4]
12000f68: bic      r1, r1, #0x10
12000f6c: str      r1, [r0, #0x1a4]
12000f70: ldr      r0, [pc, #0x34]  ; =0x3fc260
12000f74: bl       #0x120001f8  ; ->nw::font::ResFont::RemoveResource
12000f78: ldr      r0, [r4, #8]
12000f7c: nop      
12000f80: bl       #0x12000238  ; ->Mem::Free
12000f84: mov      r5, #0
12000f88: str      r5, [r4, #8]
12000f8c: ldr      r0, [r4, #0xc]
12000f90: bl       #0x12000238  ; ->Mem::Free
12000f94: str      r5, [r4, #0xc]
12000f98: str      r5, [r4, #8]
12000f9c: strb     r5, [r4, #0x18]
12000fa0: mov      r0, r4
12000fa4: pop      {r4, r5, r6, pc}
12000fa8: andne    r2, r0, #116, #4
12000fac: eorseq   ip, pc, r0, ror #4
12000fb0: add      r0, r0, #4
12000fb4: b        #0x120001e8  ; ->nn::fs::detail::FileBase::TryGetSize
12000fb8: ldrd     r0, r1, [r0, #8]
12000fbc: bx       lr
12000fc0: add      r0, r0, #8
12000fc4: ldm      r0, {r0, r2}
12000fc8: stm      r1, {r0, r2}
12000fcc: mov      r0, #0
12000fd0: bx       lr
12000fd4: str      lr, [sp, #-4]!
12000fd8: sub      sp, sp, #0xc
12000fdc: mov      r1, sp
12000fe0: add      r0, r0, #4
12000fe4: bl       #0x120001e8  ; ->nn::fs::detail::FileBase::TryGetSize
12000fe8: mov      r1, pc
12000fec: lsrs     r2, r0, #0x1f
12000ff0: blne     #0x12000198  ; ->nn::err::CTR::ThrowFatalErrAll
12000ff4: ldrd     r0, r1, [sp]
12000ff8: add      sp, sp, #0xc
12000ffc: pop      {pc}

<Field:fld::StaffrollCtrl::isFinish>  # Field:_ZNK3fld13StaffrollCtrl8isFinishEv
12001000: vldr     s0, [r0, #0x14]
12001004: vldr     s1, [r0, #0x28]
12001008: vldr     s2, [r0, #0x24]
1200100c: vcvt.f32.u32 s0, s0
12001010: vmul.f32 s0, s0, s1
12001014: vcmpe.f32 s0, s2
12001018: vmrs     apsr_nzcv, fpscr
1200101c: movgt    r0, #1
12001020: movle    r0, #0
12001024: bx       lr

<Field:nnroControlObject_>  # Field:nnroControlObject_
12001028: ldr      r2, [pc, #0x80]  ; =0x12003a2c
1200102c: cmp      r1, #5
12001030: push     {r4, lr}
12001034: ldrlo    pc, [pc, r1, lsl #2]
12001038: b        #0x12001094
1200103c: andne    r1, r0, #0x50
12001040: andne    r1, r0, #0x58
12001044: andne    r1, r0, #0x60
12001048: andne    r1, r0, #0x6c
1200104c: andne    r1, r0, #0x7c
12001050: ldr      r1, [pc, #0x5c]  ; =0x0
12001054: b        #0x12001064
12001058: str      r0, [r2]
1200105c: b        #0x1200108c
12001060: ldr      r1, [r2]
12001064: str      r1, [r0]
12001068: b        #0x1200108c
1200106c: ldr      r1, [pc, #0x44]  ; =0x120010d4
12001070: str      r1, [r0]
12001074: ldr      r1, [pc, #0x40]  ; =0x120010d4
12001078: b        #0x12001088
1200107c: ldr      r1, [pc, #0x3c]  ; =0x1200227c
12001080: str      r1, [r0]
12001084: ldr      r1, [pc, #0x38]  ; =0x1200227c
12001088: str      r1, [r0, #4]
1200108c: mov      r0, #0
12001090: pop      {r4, pc}
12001094: ldr      r0, [pc, #0x2c]  ; =0x30000000
12001098: mov      r0, r0
1200109c: ldr      r0, [pc, #0x28]  ; =0x30000027
120010a0: nop      
120010a4: mov      r0, r0
120010a8: ldr      r0, [pc, #0x20]  ; =0xd8e12c21
120010ac: pop      {r4, pc}
120010b0: andne    r3, r0, #44, #20
120010b4: andeq    r0, r0, r0
120010b8: andne    r1, r0, #0xd4
120010bc: andne    r1, r0, #0xd4
120010c0: andne    r2, r0, #124, #4
120010c4: andne    r2, r0, #124, #4
120010c8: andlo    r0, r0, r0
120010cc: andlo    r0, r0, r7, lsr #32
120010d0: stmle    r1!, {r0, r5, sl, fp, sp} ^
