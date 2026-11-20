16000180: mov      r0, r0

<->MsgDataAcsrBase>  # veneer->_ZN15MsgDataAcsrBaseD1Ev
16000184: ldr      pc, [pc, #-4]
16000188: .word    0x0026fdb4

<->_ZdlPv>  # veneer->_ZdlPv
1600018c: ldr      pc, [pc, #-4]
16000190: eoreq    r6, r8, r4, lsl r5

<->nn::fs::detail::FileBase::TrySetPosition>  # veneer->_ZN2nn2fs6detail8FileBase14TrySetPositionEx
16000194: ldr      pc, [pc, #-4]
16000198: eoreq    lr, r7, r8, lsr #24

<->nn::err::CTR::ThrowFatalErrAll>  # veneer->_ZN2nn3err3CTR16ThrowFatalErrAllENS_6ResultEj
1600019c: ldr      pc, [pc, #-4]
160001a0: eoreq    r6, r8, r0, lsr r5

<->nn::fs::detail::FileBase::TryRead>  # veneer->_ZN2nn2fs6detail8FileBase7TryReadEPiPvj
160001a4: ldr      pc, [pc, #-4]
160001a8: eoreq    r6, r8, r8, lsl #9

<->nn::fs::detail::FileBase::TrySeek>  # veneer->_ZN2nn2fs6detail8FileBase7TrySeekExNS0_12PositionBaseE
160001ac: ldr      pc, [pc, #-4]
160001b0: .word    0x002854d0

<->nndbgPanic>  # veneer->nndbgPanic
160001b4: ldr      pc, [pc, #-4]
160001b8: eoreq    r6, r8, ip, lsr #8

<->nn::fs::CTR::MPCore::detail::UserFileSystem::CloseFile>  # veneer->_ZN2nn2fs3CTR6MPCore6detail14UserFileSystem9CloseFileEPv
160001bc: ldr      pc, [pc, #-4]
160001c0: eoreq    r6, r8, r0, lsl r4

<->msys::MRenderQueueBase::enqueueMsg>  # veneer->_ZN4msys16MRenderQueueBase10enqueueMsgEP13MessageSimplejh
160001c4: ldr      pc, [pc, #-4]
160001c8: ldrshteq r8, [r2], -r0

<->msys::MMsg::applyAnime>  # veneer->_ZN4msys4MMsg10applyAnimeEv
160001cc: ldr      pc, [pc, #-4]
160001d0: ldrhteq  ip, [r2], -r8

<->msys::MMsg::playStr>  # veneer->_ZN4msys4MMsg7playStrEPKwPN13MessageSimple8InsParamEb
160001d4: ldr      pc, [pc, #-4]
160001d8: eorseq   ip, r2, ip, lsl #28

<->__cxa_guard_acquire>  # veneer->__cxa_guard_acquire
160001dc: ldr      pc, [pc, #-4]
160001e0: eoreq    r8, r8, r1, lsl r1

<->__cxa_guard_release>  # veneer->__cxa_guard_release
160001e4: ldr      pc, [pc, #-4]
160001e8: andseq   r1, r0, sb, lsr #17

<->__aeabi_vec_dtor>  # veneer->__aeabi_vec_dtor
160001ec: ldr      pc, [pc, #-4]
160001f0: eoreq    r8, r8, r1, lsr r2

<->MoveVBase>  # veneer->_ZN9MoveVBaseD1Ev
160001f4: ldr      pc, [pc, #-4]
160001f8: eoreq    r3, r5, r8, ror #11

<->MoveWorkF>  # veneer->_ZN9MoveWorkFC1Ev
160001fc: ldr      pc, [pc, #-4]
16000200: eoreq    r8, r7, r0, asr #25

<->MoveWorkF>  # veneer->_ZN9MoveWorkFD1Ev
16000204: ldr      pc, [pc, #-4]
16000208: mlaseq   r4, r4, r6, r0

<->Backup::format>  # veneer->_ZN6Backup6formatEv
1600020c: ldr      pc, [pc, #-4]
16000210: eorseq   sb, r3, r4, lsr sp

<->msys::MCamera::getProjMtx>  # veneer->_ZNK4msys7MCamera10getProjMtxERN2nn4math5MTX44Ej
16000214: ldr      pc, [pc, #-4]
16000218: eoreq    r6, r0, r8, lsl r7

<->msys::MCamera::getViewMtx>  # veneer->_ZNK4msys7MCamera10getViewMtxERN2nn4math5MTX34E
1600021c: ldr      pc, [pc, #-4]
16000220: eoreq    r6, r0, r4, ror #17

<->ad::fw::TaskBase::setULcdCameraInfoBase>  # veneer->_ZN2ad2fw8TaskBase21setULcdCameraInfoBaseERKN2nn4math5MTX34ERKNS3_5MTX44ENS3_14PivotDirectionE
16000224: ldr      pc, [pc, #-4]
16000228: andseq   fp, r0, r8, lsr r4

<->Grp::SetupProjLcdOrtho>  # veneer->_ZN3Grp17SetupProjLcdOrthoEPN2nn4math5MTX44Ejbbff
1600022c: ldr      pc, [pc, #-4]
16000230: eoreq    r4, r8, r0, asr #31

<->msys::MComSys::funcCalcMainNomal>  # veneer->_ZN4msys7MComSys17funcCalcMainNomalEv
16000234: ldr      pc, [pc, #-4]
16000238: eorseq   pc, r2, ip, lsr r1

<->msys::MComSys::funcDrawLower>  # veneer->_ZN4msys7MComSys13funcDrawLowerEP7CmdList
1600023c: ldr      pc, [pc, #-4]
16000240: ldrhteq  lr, [r2], -r8

<->msys::MComSys::funcDrawUpper>  # veneer->_ZN4msys7MComSys13funcDrawUpperEP7CmdList
16000244: ldr      pc, [pc, #-4]
16000248: eorseq   lr, r2, r0, ror #14

<->ad::lyt::LytDrawSys::GetInst>  # veneer->_ZN2ad3lyt10LytDrawSys7GetInstEv
1600024c: ldr      pc, [pc, #-4]
16000250: eoreq    r7, r8, r8, asr pc

<->ad::lyt::Initialize>  # veneer->_ZN2ad3lyt10InitializeEPN2nw2os10IAllocatorES4_
16000254: ldr      pc, [pc, #-4]
16000258: eoreq    r5, r8, r0, ror #11

<->ad::TransMultiSymbol::init>  # veneer->_ZN2ad16TransMultiSymbol4initEPKc
1600025c: ldr      pc, [pc, #-4]
16000260: .word    0x0026d7f8

<->BinGlu4Acs::getEntryAcs>  # veneer->_ZNK10BinGlu4Acs11getEntryAcsEPKc
16000264: ldr      pc, [pc, #-4]
16000268: eoreq    r5, r8, r8, ror #4

<->ad::fw::TaskBase::readCA>  # veneer->_ZN2ad2fw8TaskBase6readCAEPNS0_8ResourceEPNS0_11FileContextEPKcS7_S7_S7_S7_P10MemAlcBasejP11VramAlcBasejPNS0_11ResCacheArgE
1600026c: ldr      pc, [pc, #-4]
16000270: .word    0x0026daf8

<->msys::MComSys::readLytNum>  # veneer->_ZN4msys7MComSys10readLytNumEPN2ad2fw11FileContextEP10MemAlcBase
16000274: ldr      pc, [pc, #-4]
16000278: eorseq   sp, r2, r4, lsl fp

<->ad::fw::TaskBase::readLyt>  # veneer->_ZN2ad2fw8TaskBase7readLytEPNS0_8ResourceEPNS0_11FileContextEPKcP10MemAlcBasejPNS0_11ResCacheArgE
1600027c: ldr      pc, [pc, #-4]
16000280: eoreq    sb, r4, r8, asr #28

<->_ZnajP10MemAlcBasePKcj>  # veneer->_ZnajP10MemAlcBasePKcj
16000284: ldr      pc, [pc, #-4]
16000288: eoreq    r3, r8, r8, asr r5

<->MessageSys::GetPath>  # veneer->_ZN10MessageSys7GetPathEPwPKwb
1600028c: ldr      pc, [pc, #-4]
16000290: andseq   r2, r3, ip, lsr #20

<->nn::fs::CTR::MPCore::detail::UserFileSystem::TryOpenFile>  # veneer->_ZN2nn2fs3CTR6MPCore6detail14UserFileSystem11TryOpenFileEPPvPKwj
16000294: ldr      pc, [pc, #-4]
16000298: eoreq    r5, r8, ip, lsl #19

<->nn::fs::detail::FileBase::TryGetSize>  # veneer->_ZNK2nn2fs6detail8FileBase10TryGetSizeEPx
1600029c: ldr      pc, [pc, #-4]
160002a0: eoreq    r6, r8, r8, ror #10

<->MsgDataAcsrBase::init>  # veneer->_ZN15MsgDataAcsrBase4initEPKv
160002a4: ldr      pc, [pc, #-4]
160002a8: eoreq    r5, r8, r8, lsl #23

<->_ZdaPv>  # veneer->_ZdaPv
160002ac: ldr      pc, [pc, #-4]
160002b0: mlaeq    r8, ip, r2, r8

<->ad::lyt::LytResourceMan::init>  # veneer->_ZN2ad3lyt14LytResourceMan4initEv
160002b4: ldr      pc, [pc, #-4]
160002b8: eoreq    r0, r5, ip, lsl sp

<->ad::fw::Resource::getFileData>  # veneer->_ZN2ad2fw8Resource11getFileDataEv
160002bc: ldr      pc, [pc, #-4]
160002c0: eoreq    r1, r5, r0, lsl sp

<->ad::lyt::LytResourceMan::registerArc>  # veneer->_ZN2ad3lyt14LytResourceMan11registerArcEPvPKc
160002c4: ldr      pc, [pc, #-4]
160002c8: andseq   ip, r5, r0, lsl sb

<->msys::MLyt::init>  # veneer->_ZN4msys4MLyt4initEPN2ad3lyt11LytDrawDataEa
160002cc: ldr      pc, [pc, #-4]
160002d0: eorseq   ip, r2, r0, lsr #7

<->msys::MLyt::createLyt>  # veneer->_ZN4msys4MLyt9createLytEPN2ad3lyt14LytResourceManEPKc
160002d4: ldr      pc, [pc, #-4]
160002d8: eorseq   ip, r2, ip, lsl #15

<->MoveVBase::stop>  # veneer->_ZN9MoveVBase4stopEv
160002dc: ldr      pc, [pc, #-4]
160002e0: .word    0x00259dd8

<->msys::MDfxChr::init>  # veneer->_ZN4msys7MDfxChr4initEP10MemAlcBasePNS_7MDfxSysEPN2ad3h3d5SceneEj
160002e4: ldr      pc, [pc, #-4]
160002e8: eorseq   r0, r3, r0, asr #19

<->msys::MDfxChr::playDfx>  # veneer->_ZN4msys7MDfxChr7playDfxEj
160002ec: ldr      pc, [pc, #-4]
160002f0: eorseq   r0, r3, r4, ror #26

<->msys::MLyt::attachMChr>  # veneer->_ZN4msys4MLyt10attachMChrERNS_8MChrBaseEPKcS4_S4_S4_
160002f4: ldr      pc, [pc, #-4]
160002f8: eoreq    r7, r0, r8, ror #8

<->Backup::isBusyWriting>  # veneer->_ZN6Backup13isBusyWritingEv
160002fc: ldr      pc, [pc, #-4]
16000300: eorseq   sb, r3, r8, asr r5

<->Backup::term>  # veneer->_ZN6Backup4termEv
16000304: ldr      pc, [pc, #-4]
16000308: eorseq   sb, r3, r4, lsl #25

<->Backup::mount>  # veneer->_ZN6Backup5mountEv
1600030c: ldr      pc, [pc, #-4]
16000310: eorseq   sb, r3, ip, lsl #26

<->Backup::writeInitData>  # veneer->_ZN6Backup13writeInitDataEv
16000314: ldr      pc, [pc, #-4]
16000318: eoreq    r4, r8, ip, asr #12

<->CtrFS::unmountSaveData>  # veneer->_ZN5CtrFS15unmountSaveDataEv
1600031c: ldr      pc, [pc, #-4]
16000320: eoreq    r7, r0, ip, lsr pc

<->MoveC::moveFrm>  # veneer->_ZN5MoveC7moveFrmERKN2nn4util6Color8Ef
16000324: ldr      pc, [pc, #-4]
16000328: eoreq    fp, r6, r4, ror ip

<->msys::MComSys>  # veneer->_ZN4msys7MComSysC1Ev
1600032c: ldr      pc, [pc, #-4]
16000330: eorseq   pc, r2, r4, lsr #15

<->Backup>  # veneer->_ZN6BackupC1Ev
16000334: ldr      pc, [pc, #-4]
16000338: andseq   r0, r1, r4, ror #24

<->MsgDataAcsrBase>  # veneer->_ZN15MsgDataAcsrBaseC1EP12LMSBlockInfoj
1600033c: ldr      pc, [pc, #-4]
16000340: .word    0x0024b3b8

<->ad::fw::Resource>  # veneer->_ZN2ad2fw8ResourceC1Ev
16000344: ldr      pc, [pc, #-4]
16000348: eoreq    r0, r5, r8, lsl #11

<->__aeabi_vec_ctor_nocookie_nodtor>  # veneer->__aeabi_vec_ctor_nocookie_nodtor
1600034c: ldr      pc, [pc, #-4]
16000350: eoreq    r7, r8, sp, lsl r7

<->msys::MDfxChr>  # veneer->_ZN4msys7MDfxChrC1Ev
16000354: ldr      pc, [pc, #-4]
16000358: eorseq   r1, r3, ip, ror r3

<->FrameBuf::setClearColor>  # veneer->_ZN8FrameBuf13setClearColorEN2nn4util6Color8E
1600035c: ldr      pc, [pc, #-4]
16000360: .word    0x0024c8d4

<->MoveVBase>  # veneer->_ZN9MoveVBaseC1Ev
16000364: ldr      pc, [pc, #-4]
16000368: eoreq    sb, r5, r0, asr #14

<->ad::fw::TaskBase::term>  # veneer->_ZN2ad2fw8TaskBase4termEj
1600036c: ldr      pc, [pc, #-4]
16000370: eoreq    sl, r4, r8, asr r3

<->msys::MLyt::term>  # veneer->_ZN4msys4MLyt4termEv
16000374: ldr      pc, [pc, #-4]
16000378: eorseq   ip, r2, r8, asr #7

<->ad::fw::Resource::term>  # veneer->_ZN2ad2fw8Resource4termEv
1600037c: ldr      pc, [pc, #-4]
16000380: eoreq    r3, r3, r0, asr #6

<->msys::MDfxChr>  # veneer->_ZN4msys7MDfxChrD1Ev
16000384: ldr      pc, [pc, #-4]
16000388: eorseq   r1, r3, ip, asr #7

<->ad::fw::Resource>  # veneer->_ZN2ad2fw8ResourceD1Ev
1600038c: ldr      pc, [pc, #-4]
16000390: eoreq    sl, r4, r4, lsl #2

<->Backup>  # veneer->_ZN6BackupD1Ev
16000394: ldr      pc, [pc, #-4]
16000398: eorseq   sb, r3, r4, lsr pc

<->msys::MComSys>  # veneer->_ZN4msys7MComSysD1Ev
1600039c: ldr      pc, [pc, #-4]
160003a0: eorseq   r0, r3, r8, ror #1

<->ad::lyt::LytNumReel3::InitParam>  # veneer->_ZN2ad3lyt11LytNumReel39InitParamC1Ev
160003a4: ldr      pc, [pc, #-4]
160003a8: mlaeq    r5, r4, r1, r6

<->msys::MLytNumRes::set>  # veneer->_ZN4msys10MLytNumRes3setERN2ad3lyt11LytNumReel39InitParamENS_11eLytNumTypeENS_7eLytNumES7_
160003ac: ldr      pc, [pc, #-4]
160003b0: mlaeq    r0, r4, r5, r7

<->msys::MLytNum::init>  # veneer->_ZN4msys7MLytNum4initERN2ad3lyt11LytNumReel39InitParamEPNS2_11LytDrawDataERNS_4MLytEPKcSB_SB_SB_
160003b4: ldr      pc, [pc, #-4]
160003b8: ldrhteq  r1, [r3], -r8

<->ad::lyt::LytNumReel3::setValueInstant>  # veneer->_ZN2ad3lyt11LytNumReel315setValueInstantEi
160003bc: ldr      pc, [pc, #-4]
160003c0: eoreq    r7, r0, ip, asr r8

<->Message::init>  # veneer->_ZN7Message4initEv
160003c4: ldr      pc, [pc, #-4]
160003c8: eorseq   sp, r3, ip, lsr #24

<->Message::setMsgDat>  # veneer->_ZN7Message9setMsgDatEPKv
160003cc: ldr      pc, [pc, #-4]
160003d0: eorseq   sp, r3, r8, asr #27

<->Message::play>  # veneer->_ZN7Message4playEPNS_9PlayParamE
160003d4: ldr      pc, [pc, #-4]
160003d8: eoreq    sb, r5, r0, ror sb

<->ad::lyt::LytAnim::stopAndSetFrm>  # veneer->_ZN2ad3lyt7LytAnim13stopAndSetFrmEf
160003dc: ldr      pc, [pc, #-4]
160003e0: eoreq    pc, r6, r4, asr #28

<->MessageSimple::init>  # veneer->_ZN13MessageSimple4initEv
160003e4: ldr      pc, [pc, #-4]
160003e8: .word    0x002736b4

<->ad::lyt::Layout::FindPartsPaneByName>  # veneer->_ZN2ad3lyt6Layout19FindPartsPaneByNameEPKc
160003ec: ldr      pc, [pc, #-4]
160003f0: mlaeq    r6, r0, sp, r4

<->ad::lyt::LytAnim::init>  # veneer->_ZN2ad3lyt7LytAnim4initEPNS0_6LayoutEPKcS5_
160003f4: ldr      pc, [pc, #-4]
160003f8: eoreq    r4, r6, r4, lsl #30

<->ad::lyt::LytAnim::term>  # veneer->_ZN2ad3lyt7LytAnim4termEb
160003fc: ldr      pc, [pc, #-4]
16000400: mlaeq    r6, r0, lr, r4

<->LMS_GetTextIndexByLabel>  # veneer->LMS_GetTextIndexByLabel
16000404: ldr      pc, [pc, #-4]
16000408: eoreq    r6, r7, ip, ror #2

<->LMS_GetText>  # veneer->LMS_GetText
1600040c: ldr      pc, [pc, #-4]
16000410: eoreq    r6, r7, ip, lsl #12

<->Frm::play>  # veneer->_ZN3Frm4playEf
16000414: ldr      pc, [pc, #-4]
16000418: eoreq    sl, r7, r4, lsr #6

<->MessageSimple::term>  # veneer->_ZN13MessageSimple4termEv
1600041c: ldr      pc, [pc, #-4]
16000420: mulseq   r3, r0, r0

<->MessageSimple>  # veneer->_ZN13MessageSimpleD1Ev
16000424: ldr      pc, [pc, #-4]
16000428: eoreq    r6, r5, r8, ror r5

<->msys::MLyt::getParts>  # veneer->_ZN4msys4MLyt8getPartsEPKcS2_S2_
1600042c: ldr      pc, [pc, #-4]
16000430: eoreq    r7, r0, ip, ror #7

<->msys::MCellAnime::init>  # veneer->_ZN4msys10MCellAnime4initEPKN2ad2fw8ResourceE
16000434: ldr      pc, [pc, #-4]
16000438: .word    0x002079d8

<->CellAnime::play>  # veneer->_ZN9CellAnime4playEhsf
1600043c: ldr      pc, [pc, #-4]
16000440: eoreq    fp, r7, r0, ror #29

<->DataPcEquipFxParam>  # veneer->_ZN18DataPcEquipFxParamC1Ev
16000444: ldr      pc, [pc, #-4]
16000448: eoreq    ip, r7, r4, lsr #22

<->DataPc>  # veneer->_ZN6DataPcC1EhRK9DataPcPODPK18DataPcEquipFxParam
1600044c: ldr      pc, [pc, #-4]
16000450: eoreq    ip, r7, r4, lsl #21

<->DataPc::getLv>  # veneer->_ZNK6DataPc5getLvEv
16000454: ldr      pc, [pc, #-4]
16000458: eorseq   r2, r6, ip, ror #23

<->DataPc::getRank>  # veneer->_ZNK6DataPc7getRankEv
1600045c: ldr      pc, [pc, #-4]
16000460: eorseq   r2, r6, r0, lsl #24
16000464: push     {r4, lr}
16000468: bl       #0x16000184  ; ->MsgDataAcsrBase
1600046c: pop      {r4, lr}
16000470: b        #0x1600018c  ; ->_ZdlPv
16000474: mov      r2, #0
16000478: add      r1, r0, #4
1600047c: vldr     s0, [pc, #0x24]  ; =0x0 (0)
16000480: vldr     s1, [pc, #0x24]  ; =0x3f800000 (1)
16000484: strb     r2, [r0]
16000488: mov      r3, #1
1600048c: vstmia   r1, {s0, s1}
16000490: vstr     s0, [r0, #0xc]
16000494: strh     r3, [r0, #0x10]
16000498: strh     r2, [r0, #0x12]
1600049c: str      r2, [r0, #0x14]
160004a0: str      r2, [r0, #0x18]
160004a4: bx       lr
160004a8: andeq    r0, r0, r0
160004ac: svclo    #0x800000
160004b0: vldr     s0, [pc, #4]
160004b4: vstr     s0, [r0, #0xc]
160004b8: bx       lr
160004bc: andeq    r0, r0, r0
160004c0: b        #0x1600018c  ; ->_ZdlPv
160004c4: bx       lr
160004c8: add      r0, r0, #4
160004cc: push     {r4, lr}
160004d0: bl       #0x16000194  ; ->nn::fs::detail::FileBase::TrySetPosition
160004d4: mov      r1, pc
160004d8: lsrs     r2, r0, #0x1f
160004dc: beq      #0x160004e8
160004e0: pop      {r4, lr}
160004e4: b        #0x1600019c  ; ->nn::err::CTR::ThrowFatalErrAll
160004e8: pop      {r4, pc}
160004ec: add      r0, r0, #4
160004f0: b        #0x16000194  ; ->nn::fs::detail::FileBase::TrySetPosition
160004f4: push     {r3, lr}
160004f8: mov      r3, r2
160004fc: mov      r2, r1
16000500: mov      r1, sp
16000504: add      r0, r0, #4
16000508: bl       #0x160001a4  ; ->nn::fs::detail::FileBase::TryRead
1600050c: mov      r1, pc
16000510: lsrs     r2, r0, #0x1f
16000514: blne     #0x1600019c  ; ->nn::err::CTR::ThrowFatalErrAll
16000518: ldr      r0, [sp]
1600051c: pop      {r3, pc}
16000520: push     {r3, lr}
16000524: add      r0, r0, #4
16000528: ldr      r1, [sp, #8]
1600052c: str      r1, [sp]
16000530: bl       #0x160001ac  ; ->nn::fs::detail::FileBase::TrySeek
16000534: mov      r1, pc
16000538: lsrs     r2, r0, #0x1f
1600053c: beq      #0x16000548
16000540: pop      {r3, lr}
16000544: b        #0x1600019c  ; ->nn::err::CTR::ThrowFatalErrAll
16000548: pop      {r3, pc}
1600054c: add      r0, r0, #4
16000550: b        #0x160001a4  ; ->nn::fs::detail::FileBase::TryRead
16000554: push     {r3, lr}
16000558: add      r0, r0, #4
1600055c: ldr      r1, [sp, #8]
16000560: str      r1, [sp]
16000564: bl       #0x160001ac  ; ->nn::fs::detail::FileBase::TrySeek
16000568: pop      {r3, pc}
1600056c: push     {r4, r5, r6, lr}
16000570: mov      r4, r0
16000574: add      r5, r0, #4
16000578: ldr      r0, [r0, #4]
1600057c: bics     r1, r0, #1
16000580: beq      #0x160005a0
16000584: tst      r0, #1
16000588: blne     #0x160001b4  ; ->nndbgPanic
1600058c: ldr      r0, [r5]
16000590: bic      r0, r0, #1
16000594: bl       #0x160001bc  ; ->nn::fs::CTR::MPCore::detail::UserFileSystem::CloseFile
16000598: mov      r0, #0
1600059c: str      r0, [r5]
160005a0: mov      r0, r4
160005a4: pop      {r4, r5, r6, lr}
160005a8: b        #0x1600018c  ; ->_ZdlPv
160005ac: push     {r4, r5, r6, lr}
160005b0: mov      r4, r0
160005b4: add      r5, r0, #4
160005b8: ldr      r0, [r0, #4]
160005bc: bics     r1, r0, #1
160005c0: beq      #0x160005e0
160005c4: tst      r0, #1
160005c8: blne     #0x160001b4  ; ->nndbgPanic
160005cc: ldr      r0, [r5]
160005d0: bic      r0, r0, #1
160005d4: bl       #0x160001bc  ; ->nn::fs::CTR::MPCore::detail::UserFileSystem::CloseFile
160005d8: mov      r0, #0
160005dc: str      r0, [r5]
160005e0: mov      r0, r4
160005e4: pop      {r4, r5, r6, pc}
160005e8: vldr     s1, [pc, #0x24]  ; =0x3f800000 (1)
160005ec: mov      r2, #1
160005f0: vstr     s1, [r0, #4]
160005f4: vldr     s0, [pc, #0x14]  ; =0x0 (0)
160005f8: mov      r1, #0
160005fc: strh     r2, [r0, #0xc]
16000600: strh     r1, [r0, #0xe]
16000604: vstr     s0, [r0]
16000608: vstr     s0, [r0, #8]
1600060c: bx       lr
16000610: andeq    r0, r0, r0
16000614: svclo    #0x800000
16000618: vldr     s0, [pc, #4]
1600061c: vstr     s0, [r0, #8]
16000620: bx       lr
16000624: andeq    r0, r0, r0
16000628: mov      r1, #0
1600062c: strb     r1, [r0, #0x142]
16000630: bx       lr
16000634: bx       lr
16000638: mov      r1, #1
1600063c: strb     r1, [r0, #0x142]
16000640: bx       lr
16000644: bx       lr
16000648: mov      r0, #0
1600064c: bx       lr
16000650: bx       lr
16000654: ldrb     r2, [r0, #0x141]
16000658: mov      ip, r1
1600065c: cmp      r2, #0
16000660: beq      #0x1600067c
16000664: ldr      r2, [pc, #0x14]  ; =0x6c40
16000668: add      r1, r0, #0x14c
1600066c: mov      r3, #0xa
16000670: ldr      r2, [r2, r0]
16000674: mov      r0, ip
16000678: b        #0x160001c4  ; ->msys::MRenderQueueBase::enqueueMsg
1600067c: bx       lr
16000680: andeq    r6, r0, r0, asr #24
16000684: mov      r0, #0
16000688: bx       lr
1600068c: push     {r4, lr}
16000690: bl       #0x160012e8
16000694: pop      {r4, lr}
16000698: b        #0x1600018c  ; ->_ZdlPv
1600069c: push     {r4, lr}
160006a0: mov      r4, r0
160006a4: bl       #0x160001cc  ; ->msys::MMsg::applyAnime
160006a8: add      r1, r4, #0x6c00
160006ac: add      r0, r4, #0x5c00
160006b0: add      r1, r1, #0x58
160006b4: vldmia   r0, {s0, s1}
160006b8: add      r0, r4, #0x14c
160006bc: ldr      r2, [pc, #0x30]  ; =0x5988
160006c0: vldmia   r1, {s2, s3}
160006c4: add      r1, r4, #0x5c00
160006c8: vadd.f32 s0, s0, s2
160006cc: vadd.f32 s1, s1, s3
160006d0: vstmia   r1, {s0, s1}
160006d4: ldrb     r1, [r2, r4]
160006d8: tst      r1, #1
160006dc: beq      #0x160006f0
160006e0: ldr      r1, [r0]
160006e4: ldr      r1, [r1, #0x28]
160006e8: pop      {r4, lr}
160006ec: bx       r1
160006f0: pop      {r4, pc}
160006f4: andeq    r5, r0, r8, lsl #19
160006f8: push     {r4, r5, r6, lr}
160006fc: mov      r5, r0
16000700: bl       #0x160001d4  ; ->msys::MMsg::playStr
16000704: ldr      r0, [pc, #0x68]  ; =0x3f7eec _ZGVZN2nn4math4VEC34ZeroEvE4zero
16000708: add      r4, r5, #0x6c00
1600070c: add      r4, r4, #0x58
16000710: ldrb     r0, [r0]
16000714: tst      r0, #1
16000718: bne      #0x16000748
1600071c: ldr      r0, [pc, #0x50]  ; =0x3f7eec _ZGVZN2nn4math4VEC34ZeroEvE4zero
16000720: bl       #0x160001dc  ; ->__cxa_guard_acquire
16000724: cmp      r0, #0
16000728: beq      #0x16000748
1600072c: ldr      r1, [pc, #0x48]  ; =0x434c48 _ZZN2nn4math4VEC34ZeroEvE4zero
16000730: vldr     s0, [pc, #0x40]  ; =0x0 (0)
16000734: ldr      r0, [pc, #0x38]  ; =0x3f7eec _ZGVZN2nn4math4VEC34ZeroEvE4zero
16000738: vstr     s0, [r1]
1600073c: vstr     s0, [r1, #4]
16000740: vstr     s0, [r1, #8]
16000744: bl       #0x160001e4  ; ->__cxa_guard_release
16000748: ldr      r1, [pc, #0x2c]  ; =0x434c48 _ZZN2nn4math4VEC34ZeroEvE4zero
1600074c: ldr      r0, [r1]
16000750: str      r0, [r4]
16000754: ldr      r0, [r1, #4]
16000758: str      r0, [r4, #4]
1600075c: ldr      r0, [r1, #8]
16000760: ldr      r1, [pc, #0x18]  ; =0x5c08
16000764: str      r0, [r4, #8]
16000768: mov      r0, #0
1600076c: strb     r0, [r1, r5]
16000770: pop      {r4, r5, r6, pc}
16000774: eorseq   r7, pc, ip, ror #29
16000778: andeq    r0, r0, r0
1600077c: subeq    r4, r3, r8, asr #24
16000780: andeq    r5, r0, r8, lsl #24
16000784: push     {r4, lr}
16000788: mov      r4, r0
1600078c: ldr      r0, [pc, #0x24]  ; =0x160034e8
16000790: ldr      r1, [pc, #0x24]  ; =0x1600083c
16000794: mov      r3, #1
16000798: str      r0, [r4]
1600079c: mov      r2, #0x2c
160007a0: add      r0, r4, #0x30
160007a4: bl       #0x160001ec  ; ->__aeabi_vec_dtor
160007a8: mov      r0, r4
160007ac: bl       #0x160001f4  ; ->MoveVBase
160007b0: pop      {r4, lr}
160007b4: b        #0x1600018c  ; ->_ZdlPv
160007b8: strne    r3, [r0], -r8, ror #9
160007bc: .word    0x1600083c
160007c0: push     {r4, lr}
160007c4: mov      r4, r0
160007c8: ldr      r0, [pc, #0x20]  ; =0x160034e8
160007cc: ldr      r1, [pc, #0x20]  ; =0x1600083c
160007d0: mov      r3, #1
160007d4: str      r0, [r4]
160007d8: mov      r2, #0x2c
160007dc: add      r0, r4, #0x30
160007e0: bl       #0x160001ec  ; ->__aeabi_vec_dtor
160007e4: mov      r0, r4
160007e8: pop      {r4, lr}
160007ec: b        #0x160001f4  ; ->MoveVBase
160007f0: strne    r3, [r0], -r8, ror #9
160007f4: .word    0x1600083c
160007f8: push     {r4, lr}
160007fc: bl       #0x160001fc  ; ->MoveWorkF
16000800: mov      r1, r0
16000804: ldr      r0, [pc, #0x18]  ; =0x160034f8
16000808: vldr     s0, [pc, #0x18]  ; =0x0 (0)
1600080c: str      r0, [r1]
16000810: vstr     s0, [r1, #0x20]
16000814: vstr     s0, [r1, #0x24]
16000818: vstr     s0, [r1, #0x28]
1600081c: mov      r0, r1
16000820: pop      {r4, pc}
16000824: .word    0x160034f8
16000828: andeq    r0, r0, r0
1600082c: push     {r4, lr}
16000830: bl       #0x16000204  ; ->MoveWorkF
16000834: pop      {r4, lr}
16000838: b        #0x1600018c  ; ->_ZdlPv
1600083c: b        #0x16000204  ; ->MoveWorkF

<SaveLoad:save_load::SaveLoadSys::saveFormat>  # SaveLoad:_ZN9save_load11SaveLoadSys10saveFormatEv
16000840: ldr      r1, [pc, #0x14]  ; =0x3f40a8 Backup::_fs
16000844: mov      r2, #0
16000848: add      r0, r0, #0xe9000
1600084c: add      r0, r0, #0x50
16000850: ldr      r1, [r1]
16000854: strh     r2, [r1, #0x24]
16000858: b        #0x1600020c  ; ->Backup::format
1600085c: eorseq   r4, pc, r8, lsr #1
16000860: push     {r4, r5, lr}
16000864: mov      r5, r0
16000868: ldr      r0, [pc, #0x60]  ; =0x4ad54
1600086c: sub      sp, sp, #0x74
16000870: mov      r2, #0x400
16000874: add      r0, r0, r5
16000878: mov      r1, sp
1600087c: mov      r4, r0
16000880: bl       #0x16000214  ; ->msys::MCamera::getProjMtx
16000884: add      r1, sp, #0x40
16000888: mov      r0, r4
1600088c: bl       #0x1600021c  ; ->msys::MCamera::getViewMtx
16000890: ldr      r0, [r5, #4]
16000894: mov      r3, #1
16000898: mov      r2, sp
1600089c: add      r1, sp, #0x40
160008a0: bl       #0x16000224  ; ->ad::fw::TaskBase::setULcdCameraInfoBase
160008a4: add      r4, r4, #0x20
160008a8: mov      r3, #1
160008ac: vldmia   r4, {s0, s1}
160008b0: mov      r2, #0
160008b4: mov      r1, #0x400
160008b8: mov      r0, sp
160008bc: bl       #0x1600022c  ; ->Grp::SetupProjLcdOrtho
160008c0: mov      r0, r5
160008c4: bl       #0x16000234  ; ->msys::MComSys::funcCalcMainNomal
160008c8: add      sp, sp, #0x74
160008cc: pop      {r4, r5, pc}
160008d0: andeq    sl, r4, r4, asr sp

<SaveLoad:save_load::SaveLoadSys::funcDrawLower>  # SaveLoad:_ZN9save_load11SaveLoadSys13funcDrawLowerEP7CmdList
160008d4: push     {r4, r5, lr}
160008d8: mov      r4, r0
160008dc: ldr      r0, [pc, #0x2c]  ; =0x4ae34
160008e0: sub      sp, sp, #0x44
160008e4: mov      r5, r1
160008e8: ldr      r2, [pc, #0x1c]  ; =0x401
160008ec: mov      r1, sp
160008f0: add      r0, r0, r4
160008f4: bl       #0x16000214  ; ->msys::MCamera::getProjMtx
160008f8: mov      r1, r5
160008fc: mov      r0, r4
16000900: bl       #0x1600023c  ; ->msys::MComSys::funcDrawLower
16000904: add      sp, sp, #0x44
16000908: pop      {r4, r5, pc}
1600090c: andeq    r0, r0, r1, lsl #8
16000910: andeq    sl, r4, r4, lsr lr

<SaveLoad:save_load::SaveLoadSys::funcDrawUpper>  # SaveLoad:_ZN9save_load11SaveLoadSys13funcDrawUpperEP7CmdList
16000914: b        #0x16000244  ; ->msys::MComSys::funcDrawUpper

<SaveLoad:save_load::SaveLoadSys::funcCalcLoadData>  # SaveLoad:_ZN9save_load11SaveLoadSys16funcCalcLoadDataEv
16000918: push     {r4, r5, r6, r7, r8, sb, sl, fp, lr}
1600091c: sub      sp, sp, #0x84
16000920: mov      r4, r0
16000924: bl       #0x1600024c  ; ->ad::lyt::LytDrawSys::GetInst
16000928: mov      r6, r0
1600092c: ldr      r0, [pc, #0x2dc]  ; =0x3f634c ad::lyt::Layout::s_pAllocator
16000930: add      r5, r4, #0xc
16000934: ldr      r1, [r0]
16000938: add      r0, r6, #0x400
1600093c: add      r0, r0, #0x1f4
16000940: cmp      r1, r0
16000944: movne    r1, r0
16000948: blne     #0x16000254  ; ->ad::lyt::Initialize
1600094c: str      r5, [r6, #0x5f8]
16000950: bl       #0x1600024c  ; ->ad::lyt::LytDrawSys::GetInst
16000954: mov      r1, r0
16000958: mov      r0, #0x10000
1600095c: str      r0, [r1, #0x5fc]
16000960: ldr      r0, [pc, #0x2ac]  ; =0xe64f0
16000964: add      r1, pc, #0x2ac
16000968: ldr      r0, [r0, r4]
1600096c: ldr      r0, [r0, #0x44]
16000970: ldr      r2, [r0]
16000974: ldr      r2, [r2, #0xc]
16000978: blx      r2
1600097c: ldr      r2, [pc, #0x2a4]  ; =0x16003210
16000980: add      r3, sp, #0x70
16000984: mov      r5, #0
16000988: ldm      r2, {r0, r1, r2}
1600098c: stm      r3, {r0, r1, r2}
16000990: add      r1, r5, r5, lsl #4
16000994: ldr      r0, [r4, #4]
16000998: add      r2, r4, r1, lsl #2
1600099c: ldr      r6, [r4, #0x278]
160009a0: add      r1, r4, #0xc
160009a4: str      r1, [sp, #0x80]
160009a8: add      r1, sp, #0x70
160009ac: mov      sb, #0
160009b0: ldr      r7, [r1, r5, lsl #2]
160009b4: add      r1, r2, #0xfb000
160009b8: add      r1, r1, #0xb30
160009bc: str      r0, [sp, #0x38]
160009c0: str      r1, [sp, #0x24]
160009c4: ldr      r0, [r6, #0x24]
160009c8: mov      r8, #0x7f
160009cc: mov      sl, sb
160009d0: str      r0, [sp, #0x68]
160009d4: mov      fp, sb
160009d8: add      r0, sp, #0x3c
160009dc: mov      r1, r7
160009e0: bl       #0x1600025c  ; ->ad::TransMultiSymbol::init
160009e4: add      r2, sp, #0x3c
160009e8: add      r1, sp, #0x68
160009ec: add      r0, sp, #0x30
160009f0: bl       #0x16000264  ; ->BinGlu4Acs::getEntryAcs
160009f4: ldr      r1, [sp, #0x30]
160009f8: ldr      r0, [r6, #0x24]
160009fc: ldr      r1, [r1]
16000a00: bic      r1, r1, #0xc0000000
16000a04: add      r0, r0, r1
16000a08: add      r1, sp, #0x14
16000a0c: add      r2, r0, #0xc
16000a10: stm      r1, {r8, sb, sl, fp}
16000a14: add      r3, r0, #8
16000a18: add      ip, r0, #4
16000a1c: ldr      r1, [sp, #0x80]
16000a20: str      r3, [sp, #8]
16000a24: str      r2, [sp, #0xc]
16000a28: str      r1, [sp, #0x10]
16000a2c: stm      sp, {r0, ip}
16000a30: ldr      r0, [sp, #0x38]
16000a34: ldr      r1, [sp, #0x24]
16000a38: mov      r3, r7
16000a3c: mov      r2, r6
16000a40: bl       #0x1600026c  ; ->ad::fw::TaskBase::readCA
16000a44: add      r5, r5, #1
16000a48: cmp      r5, #3
16000a4c: blt      #0x16000990
16000a50: ldr      r0, [r4, #0x278]
16000a54: mov      r2, #0
16000a58: add      r1, r0, #0xa8
16000a5c: mov      r0, r4
16000a60: bl       #0x16000274  ; ->msys::MComSys::readLytNum
16000a64: ldr      r0, [r4, #4]
16000a68: mov      r8, #0
16000a6c: mov      r6, #0x7f
16000a70: add      r5, r4, #0xc
16000a74: stm      sp, {r5, r6, r8}
16000a78: ldr      r1, [r4, #0x278]
16000a7c: ldr      r3, [pc, #0x1a8]  ; =0x16003024
16000a80: add      r2, r1, #0xa8
16000a84: ldr      r1, [pc, #0x1a4]  ; =0xfbaa8
16000a88: add      r1, r1, r4
16000a8c: bl       #0x1600027c  ; ->ad::fw::TaskBase::readLyt
16000a90: ldr      r0, [r4, #4]
16000a94: stm      sp, {r5, r6, r8}
16000a98: ldr      r1, [r4, #0x278]
16000a9c: ldr      r3, [pc, #0x190]  ; =0x1600305c
16000aa0: add      r2, r1, #0xa8
16000aa4: ldr      r1, [pc, #0x18c]  ; =0xfbaec
16000aa8: add      r1, r1, r4
16000aac: bl       #0x1600027c  ; ->ad::fw::TaskBase::readLyt
16000ab0: mov      r3, #0x800000
16000ab4: mov      r2, #0
16000ab8: add      r1, r4, #0xc
16000abc: mov      r0, #0x200
16000ac0: bl       #0x16000284  ; ->_ZnajP10MemAlcBasePKcj
16000ac4: mov      r7, r0
16000ac8: mov      r2, #0
16000acc: add      r1, pc, #0x168
16000ad0: bl       #0x1600028c  ; ->MessageSys::GetPath
16000ad4: ldr      r5, [pc, #0x174]  ; =0x16003500
16000ad8: mov      r6, sp
16000adc: add      r0, sp, #4
16000ae0: ldr      r1, [r5, #4]
16000ae4: mov      r2, r1
16000ae8: str      r1, [sp]
16000aec: ldr      r2, [r2, #-0x30]
16000af0: ldr      r1, [r5, #8]
16000af4: str      r1, [sp, r2]
16000af8: mov      r2, #1
16000afc: mov      r1, r7
16000b00: str      r8, [sp, #4]
16000b04: str      r8, [sp, #0x10]
16000b08: str      r8, [sp, #0x14]
16000b0c: str      r8, [sp, #8]
16000b10: str      r8, [sp, #0xc]
16000b14: bl       #0x16000294  ; ->nn::fs::CTR::MPCore::detail::UserFileSystem::TryOpenFile
16000b18: tst      r0, #0x80000000
16000b1c: movne    r1, pc
16000b20: lsrsne   r2, r0, #0x1f
16000b24: blne     #0x1600019c  ; ->nn::err::CTR::ThrowFatalErrAll
16000b28: ldr      r0, [r5]
16000b2c: mov      r1, r0
16000b30: str      r0, [sp]
16000b34: ldr      r1, [r1, #-0x30]
16000b38: ldr      r0, [r5, #0xc]
16000b3c: str      r0, [r6, r1]
16000b40: add      r1, sp, #0x18
16000b44: add      r0, sp, #4
16000b48: bl       #0x1600029c  ; ->nn::fs::detail::FileBase::TryGetSize
16000b4c: mov      r1, pc
16000b50: lsrs     r2, r0, #0x1f
16000b54: blne     #0x1600019c  ; ->nn::err::CTR::ThrowFatalErrAll
16000b58: ldr      r2, [r4, #0xc]
16000b5c: ldr      r5, [sp, #0x18]
16000b60: add      r0, r4, #0xc
16000b64: ldr      r3, [r2, #0xc]
16000b68: mov      r1, r5
16000b6c: mov      r2, #0
16000b70: blx      r3
16000b74: add      r6, r4, #0xfb000
16000b78: add      ip, sp, #4
16000b7c: mov      r2, r0
16000b80: str      r0, [r6, #0xa38]
16000b84: mov      r3, r5
16000b88: add      r1, sp, #0x1c
16000b8c: mov      r0, ip
16000b90: bl       #0x160001a4  ; ->nn::fs::detail::FileBase::TryRead
16000b94: mov      r1, pc
16000b98: lsrs     r2, r0, #0x1f
16000b9c: blne     #0x1600019c  ; ->nn::err::CTR::ThrowFatalErrAll
16000ba0: ldr      r0, [pc, #0xac]  ; =0xfba3c
16000ba4: ldr      r1, [r6, #0xa38]
16000ba8: add      r0, r0, r4
16000bac: bl       #0x160002a4  ; ->MsgDataAcsrBase::init
16000bb0: ldr      r0, [sp, #4]
16000bb4: bics     r0, r0, #1
16000bb8: beq      #0x16000bd8
16000bbc: ldr      r0, [sp, #4]
16000bc0: tst      r0, #1
16000bc4: blne     #0x160001b4  ; ->nndbgPanic
16000bc8: ldr      r0, [sp, #4]
16000bcc: bic      r0, r0, #1
16000bd0: bl       #0x160001bc  ; ->nn::fs::CTR::MPCore::detail::UserFileSystem::CloseFile
16000bd4: str      r8, [sp, #4]
16000bd8: ldr      r0, [sp, #4]
16000bdc: bics     r0, r0, #1
16000be0: beq      #0x16000c00
16000be4: ldr      r0, [sp, #4]
16000be8: tst      r0, #1
16000bec: blne     #0x160001b4  ; ->nndbgPanic
16000bf0: ldr      r0, [sp, #4]
16000bf4: bic      r0, r0, #1
16000bf8: bl       #0x160001bc  ; ->nn::fs::CTR::MPCore::detail::UserFileSystem::CloseFile
16000bfc: str      r8, [sp, #4]
16000c00: mov      r0, r7
16000c04: bl       #0x160002ac  ; ->_ZdaPv
16000c08: add      sp, sp, #0x84
16000c0c: pop      {r4, r5, r6, r7, r8, sb, sl, fp, pc}
16000c10: eorseq   r6, pc, ip, asr #6
16000c14: strdeq   r6, r7, [lr], -r0
16000c18: stmdapl  r6, {r0, r2, r3, r6, sl, lr} ^
16000c1c: strbvc   r6, [lr, #-0x54d]!
16000c20: stmdavs  r3!, {r0, r6, sb, ip, sp, lr} ^
16000c24: rsbeq    r7, r5, sb, ror #12
16000c28: .word    0x16003210
16000c2c: strne    r3, [r0], -r4, lsr #32
16000c30: andeq    fp, pc, r8, lsr #21
16000c34: .word    0x1600305c
16000c38: andeq    fp, pc, ip, ror #21
16000c3c: rsbeq    r0, r5, sp, asr #32
16000c40: rsbseq   r0, r5, lr, rrx
16000c44: rsbeq    r0, sp, lr, lsr #32
16000c48: rsbeq    r0, r2, r3, ror r0
16000c4c: andeq    r0, r0, r4, ror r0
16000c50: strne    r3, [r0], -r0, lsl #10
16000c54: andeq    fp, pc, ip, lsr sl

<SaveLoad:save_load::SaveLoadSys::funcCalcCreateChr>  # SaveLoad:_ZN9save_load11SaveLoadSys17funcCalcCreateChrEv
16000c58: push     {r4, r5, r6, r7, r8, sb, sl, lr}
16000c5c: mov      r4, r0
16000c60: add      r0, r0, #0x7d0
16000c64: vpush    {d8}
16000c68: sub      sp, sp, #8
16000c6c: bl       #0x160002b4  ; ->ad::lyt::LytResourceMan::init
16000c70: add      r0, r4, #0x800
16000c74: add      r0, r0, #0x44
16000c78: bl       #0x160002bc  ; ->ad::fw::Resource::getFileData
16000c7c: mov      r1, r0
16000c80: ldr      r2, [pc, #0x2e0]  ; =0x1600361c
16000c84: add      r0, r4, #0x7d0
16000c88: bl       #0x160002c4  ; ->ad::lyt::LytResourceMan::registerArc
16000c8c: ldr      r0, [pc, #0x2d8]  ; =0xfbaa8
16000c90: add      r0, r0, r4
16000c94: bl       #0x160002bc  ; ->ad::fw::Resource::getFileData
16000c98: mov      r1, r0
16000c9c: add      r2, pc, #0x2cc
16000ca0: add      r0, r4, #0x7d0
16000ca4: bl       #0x160002c4  ; ->ad::lyt::LytResourceMan::registerArc
16000ca8: ldr      r0, [pc, #0x2c4]  ; =0xfbaec
16000cac: add      r0, r0, r4
16000cb0: bl       #0x160002bc  ; ->ad::fw::Resource::getFileData
16000cb4: mov      r1, r0
16000cb8: add      r2, pc, #0x2b0
16000cbc: add      r0, r4, #0x7d0
16000cc0: bl       #0x160002c4  ; ->ad::lyt::LytResourceMan::registerArc
16000cc4: ldr      r0, [pc, #0x2ac]  ; =0xfbbfc
16000cc8: add      r1, r4, #0xd3000
16000ccc: mov      r6, r1
16000cd0: add      r0, r0, r4
16000cd4: mov      r2, #1
16000cd8: mov      r8, r0
16000cdc: bl       #0x160002cc  ; ->msys::MLyt::init
16000ce0: ldr      r2, [pc, #0x294]  ; =0x1600303c
16000ce4: add      r1, r4, #0x7d0
16000ce8: mov      r0, r8
16000cec: bl       #0x160002d4  ; ->msys::MLyt::createLyt
16000cf0: ldr      r0, [pc, #0x288]  ; =0xfff04338
16000cf4: vldr     s16, [pc, #0x288]  ; =0x0 (0)
16000cf8: vldr     s17, [pc, #0x288]  ; =0xc3520000 (-210)
16000cfc: sub      r5, r4, r0
16000d00: mov      r0, r5
16000d04: bl       #0x160002dc  ; ->MoveVBase::stop
16000d08: vstr     s16, [r5, #0x1c]
16000d0c: add      r0, r5, #0x20
16000d10: mov      r1, #0x400
16000d14: vstmia   r0, {s16, s17}
16000d18: add      r2, r8, #4
16000d1c: ldr      r0, [r5, #0x1c]
16000d20: str      r0, [r5, #4]!
16000d24: add      r5, r5, #4
16000d28: adds     r0, r8, #4
16000d2c: vstmia   r5, {s16, s17}
16000d30: str      r1, [r8, #0x13c]
16000d34: ldm      r2, {r3, ip}
16000d38: ldr      r1, [pc, #0x24c]  ; =0xe64d8
16000d3c: str      ip, [r3, #4]
16000d40: ldr      r2, [r8, #4]
16000d44: add      r1, r1, r4
16000d48: str      r2, [ip]
16000d4c: beq      #0x16000d64
16000d50: ldr      r2, [r1]
16000d54: str      r1, [r0, #4]
16000d58: str      r2, [r0]
16000d5c: str      r0, [r2, #4]
16000d60: str      r0, [r1]
16000d64: ldr      r0, [pc, #0x224]  ; =0xfff0405c
16000d68: mov      r1, r6
16000d6c: mov      r2, #1
16000d70: sub      r0, r4, r0
16000d74: mov      r7, r0
16000d78: bl       #0x160002cc  ; ->msys::MLyt::init
16000d7c: ldr      r2, [pc, #0x210]  ; =0x1600304c
16000d80: add      r1, r4, #0x7d0
16000d84: mov      r0, r7
16000d88: bl       #0x160002d4  ; ->msys::MLyt::createLyt
16000d8c: add      r5, r4, #0xfc000
16000d90: add      r5, r5, #0x70
16000d94: mov      r0, r5
16000d98: bl       #0x160002dc  ; ->MoveVBase::stop
16000d9c: vstr     s16, [r5, #0x1c]
16000da0: add      r0, r5, #0x20
16000da4: ldr      sb, [pc, #0x1ec]  ; =0x401
16000da8: add      r1, r7, #4
16000dac: vstmia   r0, {s16, s17}
16000db0: ldr      r0, [r5, #0x1c]
16000db4: str      r0, [r5, #4]!
16000db8: add      r5, r5, #4
16000dbc: adds     r0, r7, #4
16000dc0: vstmia   r5, {s16, s17}
16000dc4: add      r5, r4, #0xe6000
16000dc8: str      sb, [r7, #0x13c]
16000dcc: ldrd     r2, r3, [r1]
16000dd0: add      r5, r5, #0x4e0
16000dd4: str      r3, [r2, #4]
16000dd8: ldr      r1, [r7, #4]
16000ddc: str      r1, [r3]
16000de0: beq      #0x16000df4
16000de4: ldr      r2, [r5]
16000de8: stm      r0, {r2, r5}
16000dec: str      r0, [r2, #4]
16000df0: str      r0, [r5]
16000df4: add      r0, r4, #0xfc000
16000df8: mov      r1, r6
16000dfc: add      r0, r0, #0x34c
16000e00: mov      r2, #0
16000e04: mov      r6, r0
16000e08: bl       #0x160002cc  ; ->msys::MLyt::init
16000e0c: ldr      r2, [pc, #0x188]  ; =0x1600306a
16000e10: add      r1, r4, #0x7d0
16000e14: mov      r0, r6
16000e18: bl       #0x160002d4  ; ->msys::MLyt::createLyt
16000e1c: ldr      r0, [pc, #0x17c]  ; =0xfc418
16000e20: vldr     s17, [pc, #0x17c]  ; =0xc347cccd (-199.8)
16000e24: add      sl, r4, r0
16000e28: mov      r0, sl
16000e2c: bl       #0x160002dc  ; ->MoveVBase::stop
16000e30: vstr     s16, [sl, #0x1c]
16000e34: add      r0, sl, #0x20
16000e38: vstmia   r0, {s16, s17}
16000e3c: ldr      r0, [sl, #0x1c]
16000e40: str      r0, [sl, #4]!
16000e44: add      sl, sl, #4
16000e48: mov      r0, #0
16000e4c: vstmia   sl, {s16, s17}
16000e50: strb     r0, [r6, #0x141]
16000e54: add      r0, r6, #4
16000e58: str      sb, [r6, #0x13c]
16000e5c: ldm      r0, {r1, r2}
16000e60: str      r2, [r1, #4]
16000e64: ldr      r0, [r6, #4]
16000e68: str      r0, [r2]
16000e6c: adds     r0, r6, #4
16000e70: beq      #0x16000e84
16000e74: ldr      r1, [r5]
16000e78: stm      r0, {r1, r5}
16000e7c: str      r0, [r1, #4]
16000e80: str      r0, [r5]
16000e84: add      sl, r4, #0xe6000
16000e88: mov      r0, #0x400
16000e8c: ldr      r2, [sl, #0x4f0]
16000e90: str      r0, [sp]
16000e94: ldr      r0, [pc, #0x10c]  ; =0xfc6f4
16000e98: add      r3, r4, #0x4a000
16000e9c: add      r3, r3, #0xaa0
16000ea0: add      r0, r0, r4
16000ea4: add      r1, r4, #0xc
16000ea8: mov      r5, r0
16000eac: bl       #0x160002e4  ; ->msys::MDfxChr::init
16000eb0: mov      r1, #0x16
16000eb4: mov      r0, r5
16000eb8: bl       #0x160002ec  ; ->msys::MDfxChr::playDfx
16000ebc: ldr      r0, [pc, #0xe8]  ; =0xfc848
16000ec0: ldr      r2, [pc, #0xe8]  ; =0x1600307a
16000ec4: ldr      r1, [r0, r4]
16000ec8: mov      r0, #0
16000ecc: mov      r6, r0
16000ed0: mov      r3, r0
16000ed4: strh     r0, [r1, #0xf2]
16000ed8: str      r0, [sp]
16000edc: str      r0, [sp, #4]
16000ee0: mov      r1, r5
16000ee4: mov      r0, r8
16000ee8: bl       #0x160002f4  ; ->msys::MLyt::attachMChr
16000eec: ldr      r0, [pc, #0xc0]  ; =0x4aba4
16000ef0: ldr      r2, [sl, #0x4f0]
16000ef4: add      r1, r4, #0xc
16000ef8: add      r3, r4, r0
16000efc: add      r0, r4, #0xfc000
16000f00: add      r0, r0, #0x870
16000f04: mov      r5, r0
16000f08: str      sb, [sp]
16000f0c: bl       #0x160002e4  ; ->msys::MDfxChr::init
16000f10: mov      r1, #0x17
16000f14: mov      r0, r5
16000f18: bl       #0x160002ec  ; ->msys::MDfxChr::playDfx
16000f1c: ldr      r0, [pc, #0x94]  ; =0xfc9bc
16000f20: ldr      r2, [pc, #0x94]  ; =0x1600308c
16000f24: mov      r3, #0
16000f28: add      r0, r0, r4
16000f2c: mov      r1, r5
16000f30: ldr      r0, [r0, #8]
16000f34: strh     r6, [r0, #0xf2]
16000f38: mov      r0, r7
16000f3c: str      r6, [sp]
16000f40: str      r6, [sp, #4]
16000f44: bl       #0x160002f4  ; ->msys::MLyt::attachMChr
16000f48: ldr      r0, [pc, #0x70]  ; =0x16003014
16000f4c: add      r4, r4, #0xc00
16000f50: add      r4, r4, #0x384
16000f54: ldm      r0, {r0, r1}
16000f58: stm      r4, {r0, r1}
16000f5c: add      sp, sp, #8
16000f60: vpop     {d8}
16000f64: pop      {r4, r5, r6, r7, r8, sb, sl, pc}
16000f68: .word    0x1600361c
16000f6c: andeq    fp, pc, r8, lsr #21
16000f70: andeq    r0, r0, lr, lsr #32
16000f74: andeq    fp, pc, ip, ror #21
16000f78: strdeq   fp, ip, [pc], -ip
16000f7c: .word    0x1600303c
16000f80: .word    0xfff04338
16000f84: andeq    r0, r0, r0
16000f88: cmpgt    r2, #0
16000f8c: ldrdeq   r6, r7, [lr], -r8
16000f90: .word    0xfff0405c
16000f94: strne    r3, [r0], -ip, asr #32
16000f98: andeq    r0, r0, r1, lsl #8
16000f9c: strne    r3, [r0], -sl, rrx
16000fa0: andeq    ip, pc, r8, lsl r4
16000fa4: movtgt   ip, #0x7ccd
16000fa8: strdeq   ip, sp, [pc], -r4
16000fac: andeq    ip, pc, r8, asr #16
16000fb0: .word    0x1600307a
16000fb4: andeq    sl, r4, r4, lsr #23
16000fb8: strheq   ip, [pc], -ip
16000fbc: strne    r3, [r0], -ip, lsl #1
16000fc0: .word    0x16003014

<SaveLoad:save_load::SaveLoadSys::saveIsBusyWriting>  # SaveLoad:_ZN9save_load11SaveLoadSys17saveIsBusyWritingEv
16000fc4: add      r0, r0, #0xe9000
16000fc8: add      r0, r0, #0x50
16000fcc: push     {r4, lr}
16000fd0: mov      r4, r0
16000fd4: bl       #0x160002fc  ; ->Backup::isBusyWriting
16000fd8: cmp      r0, #0
16000fdc: movne    r0, #1
16000fe0: bne      #0x16000ff0
16000fe4: mov      r0, r4
16000fe8: bl       #0x16000304  ; ->Backup::term
16000fec: mov      r0, #0
16000ff0: pop      {r4, pc}

<SaveLoad:save_load::SaveLoadSys::saveWriteInitData>  # SaveLoad:_ZN9save_load11SaveLoadSys17saveWriteInitDataEv
16000ff4: push     {r4, r5, r6, lr}
16000ff8: mov      r4, r0
16000ffc: add      r0, r0, #0xe9000
16001000: add      r0, r0, #0x50
16001004: mov      r5, r0
16001008: bl       #0x1600030c  ; ->Backup::mount
1600100c: cmp      r0, #0
16001010: beq      #0x1600103c
16001014: mov      r0, r5
16001018: bl       #0x16000314  ; ->Backup::writeInitData
1600101c: cmp      r0, #0
16001020: movne    r0, #1
16001024: bne      #0x1600103c
16001028: ldr      r0, [r4, #4]
1600102c: add      r0, r0, #0x400
16001030: add      r0, r0, #0x118
16001034: bl       #0x1600031c  ; ->CtrFS::unmountSaveData
16001038: mov      r0, #0
1600103c: pop      {r4, r5, r6, pc}
16001040: push     {r4, r5, r6, r7, r8, lr}
16001044: mov      r5, r0
16001048: add      r4, r5, #0x14
1600104c: ldr      r0, [pc, #0x120]  ; =0x3f7ee8 _ZGVZN2nn4math4VEC33OneEvE3one
16001050: vpush    {d8}
16001054: ldrb     r0, [r0]
16001058: tst      r0, #1
1600105c: bne      #0x1600108c
16001060: ldr      r0, [pc, #0x10c]  ; =0x3f7ee8 _ZGVZN2nn4math4VEC33OneEvE3one
16001064: bl       #0x160001dc  ; ->__cxa_guard_acquire
16001068: cmp      r0, #0
1600106c: beq      #0x1600108c
16001070: ldr      r0, [pc, #0x104]  ; =0x434c3c _ZZN2nn4math4VEC33OneEvE3one
16001074: vldr     s0, [pc, #0xfc]  ; =0x3f800000 (1)
16001078: vstr     s0, [r0]
1600107c: vstr     s0, [r0, #4]
16001080: vstr     s0, [r0, #8]
16001084: ldr      r0, [pc, #0xe8]  ; =0x3f7ee8 _ZGVZN2nn4math4VEC33OneEvE3one
16001088: bl       #0x160001e4  ; ->__cxa_guard_release
1600108c: ldr      r6, [pc, #0xe8]  ; =0x434c3c _ZZN2nn4math4VEC33OneEvE3one
16001090: mov      r0, r4
16001094: bl       #0x160002dc  ; ->MoveVBase::stop
16001098: ldm      r6, {r0, r1, r2}
1600109c: add      r3, r4, #0x1c
160010a0: ldr      r6, [pc, #0xd8]  ; =0x3f7eec _ZGVZN2nn4math4VEC34ZeroEvE4zero
160010a4: add      r4, r4, #4
160010a8: stm      r3, {r0, r1, r2}
160010ac: stm      r4, {r0, r1, r2}
160010b0: add      r4, r5, #0x70
160010b4: ldrb     r0, [r6]
160010b8: vldr     s16, [pc, #0xc4]  ; =0x0 (0)
160010bc: tst      r0, #1
160010c0: bne      #0x160010f0
160010c4: add      r0, r6, #0
160010c8: bl       #0x160001dc  ; ->__cxa_guard_acquire
160010cc: cmp      r0, #0
160010d0: nop      
160010d4: beq      #0x160010f0
160010d8: ldr      r0, [pc, #0xa8]  ; =0x434c48 _ZZN2nn4math4VEC34ZeroEvE4zero
160010dc: vstr     s16, [r0]
160010e0: vstr     s16, [r0, #4]
160010e4: vstr     s16, [r0, #8]
160010e8: add      r0, r6, #0
160010ec: bl       #0x160001e4  ; ->__cxa_guard_release
160010f0: ldr      r7, [pc, #0x90]  ; =0x434c48 _ZZN2nn4math4VEC34ZeroEvE4zero
160010f4: mov      r0, r4
160010f8: bl       #0x160002dc  ; ->MoveVBase::stop
160010fc: ldm      r7, {r0, r1, r2}
16001100: add      r3, r4, #0x1c
16001104: add      r4, r4, #4
16001108: stm      r3, {r0, r1, r2}
1600110c: stm      r4, {r0, r1, r2}
16001110: add      r4, r5, #0xcc
16001114: ldrb     r0, [r6]
16001118: tst      r0, #1
1600111c: bne      #0x1600114c
16001120: ldr      r0, [pc, #0x58]  ; =0x3f7eec _ZGVZN2nn4math4VEC34ZeroEvE4zero
16001124: bl       #0x160001dc  ; ->__cxa_guard_acquire
16001128: cmp      r0, #0
1600112c: nop      
16001130: beq      #0x1600114c
16001134: add      r0, r7, #0
16001138: vstr     s16, [r0]
1600113c: vstr     s16, [r0, #4]
16001140: vstr     s16, [r0, #8]
16001144: ldr      r0, [pc, #0x34]  ; =0x3f7eec _ZGVZN2nn4math4VEC34ZeroEvE4zero
16001148: bl       #0x160001e4  ; ->__cxa_guard_release
1600114c: ldr      r5, [pc, #0x34]  ; =0x434c48 _ZZN2nn4math4VEC34ZeroEvE4zero
16001150: mov      r0, r4
16001154: bl       #0x160002dc  ; ->MoveVBase::stop
16001158: ldm      r5, {r0, r1, r2}
1600115c: add      r3, r4, #0x1c
16001160: add      r4, r4, #4
16001164: stm      r3, {r0, r1, r2}
16001168: stm      r4, {r0, r1, r2}
1600116c: vpop     {d8}
16001170: pop      {r4, r5, r6, r7, r8, pc}
16001174: eorseq   r7, pc, r8, ror #29
16001178: svclo    #0x800000
1600117c: subeq    r4, r3, ip, lsr ip
16001180: eorseq   r7, pc, ip, ror #29
16001184: andeq    r0, r0, r0
16001188: subeq    r4, r3, r8, asr #24
1600118c: ldr      r1, [pc, #0x13c]  ; =0x3e435c
16001190: push     {r4, r5, r6, r7, r8, lr}
16001194: mov      r4, #0
16001198: str      r1, [r0]
1600119c: add      r1, r0, #4
160011a0: str      r1, [r0, #4]
160011a4: str      r1, [r0, #8]
160011a8: str      r4, [r0, #0xc]
160011ac: strb     r4, [r0, #0x10]
160011b0: add      r0, r0, #0x14
160011b4: bl       #0x16000364  ; ->MoveVBase
160011b8: ldr      r5, [pc, #0x114]  ; =0x160034e8
160011bc: ldr      r1, [pc, #0x114]  ; =0x160007f8
160011c0: mov      r3, #1
160011c4: mov      r2, #0x2c
160011c8: str      r5, [r0], #0x30
160011cc: bl       #0x1600034c  ; ->__aeabi_vec_ctor_nocookie_nodtor
160011d0: mov      r6, #1
160011d4: str      r0, [r0, #-8]
160011d8: strb     r6, [r0, #-4]
160011dc: add      r0, r0, #0x2c
160011e0: bl       #0x16000364  ; ->MoveVBase
160011e4: ldr      r1, [pc, #0xec]  ; =0x160007f8
160011e8: mov      r3, #1
160011ec: mov      r2, #0x2c
160011f0: str      r5, [r0], #0x30
160011f4: bl       #0x1600034c  ; ->__aeabi_vec_ctor_nocookie_nodtor
160011f8: str      r0, [r0, #-8]
160011fc: strb     r6, [r0, #-4]
16001200: add      r0, r0, #0x2c
16001204: bl       #0x16000364  ; ->MoveVBase
16001208: ldr      r1, [pc, #0xc8]  ; =0x160007f8
1600120c: mov      r3, #1
16001210: mov      r2, #0x2c
16001214: str      r5, [r0], #0x30
16001218: bl       #0x1600034c  ; ->__aeabi_vec_ctor_nocookie_nodtor
1600121c: str      r0, [r0, #-8]
16001220: strb     r6, [r0, #-4]
16001224: str      r4, [r0, #0x2c]
16001228: str      r4, [r0, #0x30]
1600122c: str      r4, [r0, #0x34]
16001230: strb     r4, [r0, #0x38]
16001234: strb     r4, [r0, #0x39]
16001238: str      r4, [r0, #0x3c]
1600123c: str      r4, [r0, #0x40]
16001240: strb     r6, [r0, #0x44]
16001244: strb     r6, [r0, #0x45]
16001248: add      r1, r0, #0x48
1600124c: strb     r6, [r0, #0x46]
16001250: str      r1, [r0, #0x48]
16001254: str      r1, [r0, #0x4c]
16001258: ldr      r1, [pc, #0x7c]  ; =0x3e4580
1600125c: add      r2, r0, #4
16001260: mvn      r7, #0
16001264: str      r1, [r0, #-0xfc]!
16001268: ldr      r1, [pc, #0x70]  ; =0x16000474
1600126c: strb     r7, [r0, #0x14c]
16001270: strh     r4, [r2, #0x4e]
16001274: str      r4, [r0, #0x150]!
16001278: mov      r3, #0xc
1600127c: mov      r2, #0x1c
16001280: add      r0, r0, #4
16001284: bl       #0x1600034c  ; ->__aeabi_vec_ctor_nocookie_nodtor
16001288: ldr      r1, [pc, #0x54]  ; =0x160005e8
1600128c: mov      r3, #0xc
16001290: mov      r2, #0x10
16001294: add      r0, r0, #0x15c
16001298: bl       #0x1600034c  ; ->__aeabi_vec_ctor_nocookie_nodtor
1600129c: sub      r5, r0, #0x2b0
160012a0: mov      r1, r7
160012a4: str      r4, [r5, #0x370]
160012a8: strb     r6, [r5, #0x374]
160012ac: str      r4, [r5, #0x378]
160012b0: str      r4, [r5, #0x37c]
160012b4: strb     r4, [r5, #0x380]
160012b8: str      r4, [r5, #0x384]
160012bc: sub      r0, r0, #0xc
160012c0: str      r4, [r5, #0x388]
160012c4: bl       #0x160025d8
160012c8: mov      r0, r5
160012cc: pop      {r4, r5, r6, r7, r8, pc}
160012d0: eorseq   r4, lr, ip, asr r3
160012d4: strne    r3, [r0], -r8, ror #9
160012d8: .word    0x160007f8
160012dc: eorseq   r4, lr, r0, lsl #11
160012e0: .word    0x16000474
160012e4: strne    r0, [r0], -r8, ror #11
160012e8: ldr      r1, [pc, #0x144]  ; =0x16003578
160012ec: push     {r4, r5, r6, lr}
160012f0: str      r1, [r0], #0x148
160012f4: ldr      r1, [r0], #-4
160012f8: cmp      r1, r0
160012fc: beq      #0x16001318
16001300: ldr      r2, [r1, #4]
16001304: str      r1, [r1, #4]
16001308: str      r1, [r1]
1600130c: cmp      r2, r0
16001310: mov      r1, r2
16001314: bne      #0x16001300
16001318: str      r0, [r0, #4]
1600131c: str      r0, [r0]
16001320: ldr      r2, [r0]
16001324: ldr      r1, [r0, #4]
16001328: str      r1, [r2, #4]
1600132c: ldr      r2, [r0], #-0x144
16001330: str      r2, [r1]
16001334: ldr      r1, [pc, #0xfc]  ; =0x3e435c
16001338: str      r1, [r0], #0x128
1600133c: mov      r5, r0
16001340: ldr      r2, [r0, #8]
16001344: cmp      r2, #0
16001348: beq      #0x160013a0
1600134c: ldr      r1, [r5]
16001350: mov      r4, r5
16001354: add      r0, r2, #0x254
16001358: cmp      r1, #0
1600135c: ldrne    r2, [r4, #4]
16001360: strne    r2, [r1, #4]
16001364: ldr      r1, [r4, #4]
16001368: cmp      r1, #0
1600136c: ldrne    r2, [r4]
16001370: strne    r2, [r1]
16001374: ldr      r1, [r0]
16001378: cmp      r1, r4
1600137c: ldreq    r1, [r4, #4]
16001380: streq    r1, [r0]
16001384: mov      r1, #0
16001388: str      r1, [r4, #4]
1600138c: str      r1, [r4]
16001390: str      r1, [r5, #8]
16001394: ldr      r1, [r0, #4]
16001398: sub      r1, r1, #1
1600139c: str      r1, [r0, #4]
160013a0: ldr      r6, [pc, #0x94]  ; =0x160034e8
160013a4: ldr      r1, [pc, #0x94]  ; =0x1600083c
160013a8: mov      r3, #1
160013ac: str      r6, [r5, #-0x5c]!
160013b0: mov      r2, #0x2c
160013b4: add      r0, r5, #0x30
160013b8: bl       #0x160001ec  ; ->__aeabi_vec_dtor
160013bc: mov      r0, r5
160013c0: nop      
160013c4: bl       #0x160001f4  ; ->MoveVBase
160013c8: sub      r4, r0, #0x5c
160013cc: str      r6, [r0, #-0x5c]
160013d0: ldr      r1, [pc, #0x68]  ; =0x1600083c
160013d4: mov      r3, #1
160013d8: mov      r2, #0x2c
160013dc: sub      r0, r0, #0x2c
160013e0: bl       #0x160001ec  ; ->__aeabi_vec_dtor
160013e4: mov      r0, r4
160013e8: nop      
160013ec: bl       #0x160001f4  ; ->MoveVBase
160013f0: sub      r4, r0, #0x5c
160013f4: str      r6, [r0, #-0x5c]
160013f8: ldr      r1, [pc, #0x40]  ; =0x1600083c
160013fc: mov      r3, #1
16001400: mov      r2, #0x2c
16001404: sub      r0, r0, #0x2c
16001408: bl       #0x160001ec  ; ->__aeabi_vec_dtor
1600140c: mov      r0, r4
16001410: nop      
16001414: bl       #0x160001f4  ; ->MoveVBase
16001418: sub      r1, r0, #0x10
1600141c: ldrd     r2, r3, [r1]
16001420: str      r3, [r2, #4]
16001424: ldr      r1, [r0, #-0x10]
16001428: sub      r0, r0, #0x14
1600142c: str      r1, [r3]
16001430: pop      {r4, r5, r6, pc}
16001434: .word    0x16003578
16001438: eorseq   r4, lr, ip, asr r3
1600143c: strne    r3, [r0], -r8, ror #9
16001440: .word    0x1600083c
16001444: push     {r4, r5, lr}
16001448: add      r1, r0, #0xf00
1600144c: mov      r4, r0
16001450: vpush    {d8}
16001454: add      r0, r0, #0xf00
16001458: ldrsb    r1, [r1, #0xd7]
1600145c: add      r0, r0, #0xcd
16001460: sub      sp, sp, #4
16001464: ldrsb    r0, [r1, r0]
16001468: mvn      r1, #0
1600146c: add      r0, r4, r0, lsl #2
16001470: ldr      r5, [r0, #0xf8c]
16001474: ldr      r0, [r5]
16001478: ldr      r2, [r0, #8]
1600147c: mov      r0, r5
16001480: blx      r2
16001484: ldrb     r0, [r5, #0x14]
16001488: cmp      r0, #0
1600148c: beq      #0x160014ec
16001490: mov      r0, #0
16001494: vldr     s16, [pc, #0x60]  ; =0x41800000 (16)
16001498: rev      r0, r0
1600149c: mov      r5, sp
160014a0: str      r0, [sp]
160014a4: ldr      r0, [pc, #0x4c]  ; =0x4acd4
160014a8: vmov.f32 s0, s16
160014ac: mov      r1, r5
160014b0: add      r0, r0, r4
160014b4: bl       #0x16000324  ; ->MoveC::moveFrm
160014b8: ldr      r0, [pc, #0x40]  ; =0x4ad14
160014bc: vmov.f32 s0, s16
160014c0: mov      r1, r5
160014c4: add      r0, r0, r4
160014c8: bl       #0x16000324  ; ->MoveC::moveFrm
160014cc: ldr      r1, [pc, #0x30]  ; =0x4af14
160014d0: mov      r0, #1
160014d4: strb     r0, [r1, r4]
160014d8: ldr      r1, [pc, #0x28]  ; =0x16003000
160014dc: add      r4, r4, #0xc00
160014e0: add      r4, r4, #0x384
160014e4: ldrd     r0, r1, [r1, #0x1c]
160014e8: stm      r4, {r0, r1}
160014ec: add      sp, sp, #4
160014f0: vpop     {d8}
160014f4: pop      {r4, r5, pc}
160014f8: ldrdeq   sl, fp, [r4], -r4
160014fc: orrmi    r0, r0, r0
16001500: andeq    sl, r4, r4, lsl sp
16001504: andeq    sl, r4, r4, lsl pc
16001508: strne    r3, [r0], -r0

<SaveLoad:save_load::SaveLoadSys>  # SaveLoad:_ZN9save_load11SaveLoadSysC1Ev
1600150c: push     {r3, r4, r5, lr}
16001510: bl       #0x1600032c  ; ->msys::MComSys
16001514: ldr      r1, [pc, #0xec]  ; =0x160035bc
16001518: str      r1, [r0], #0x50
1600151c: add      r0, r0, #0xe9000
16001520: bl       #0x16000334  ; ->Backup
16001524: ldr      r1, [pc, #0xe0]  ; =0xfba3c
16001528: sub      r0, r0, #0xe9000
1600152c: sub      r0, r0, #0x50
16001530: add      r0, r0, r1
16001534: mov      r2, #4
16001538: add      r1, r0, #0x2c
1600153c: bl       #0x1600033c  ; ->MsgDataAcsrBase
16001540: ldr      r1, [pc, #0xc8]  ; =0x160034d8
16001544: str      r1, [r0], #0x6c
16001548: bl       #0x16000344  ; ->ad::fw::Resource
1600154c: ldr      r2, [pc, #0xc0]  ; =0xfff04558
16001550: ldr      r1, [pc, #0xc0]  ; =0xfbaec
16001554: add      r0, r0, r2
16001558: add      r0, r0, r1
1600155c: bl       #0x16000344  ; ->ad::fw::Resource
16001560: ldr      r1, [pc, #0xb4]  ; =0xfff04514
16001564: mov      r3, #3
16001568: mov      r2, #0x44
1600156c: add      r0, r0, r1
16001570: add      r0, r0, #0xfb000
16001574: ldr      r1, [pc, #0xa4]  ; =0x250588 ad::fw::Resource
16001578: add      r0, r0, #0xb30
1600157c: bl       #0x1600034c  ; ->__aeabi_vec_ctor_nocookie_nodtor
16001580: ldr      r1, [pc, #0x9c]  ; =0xfbbfc
16001584: sub      r0, r0, #0xfb000
16001588: sub      r0, r0, #0xb30
1600158c: add      r0, r0, r1
16001590: bl       #0x1600118c
16001594: ldr      r1, [pc, #0x8c]  ; =0xfff04404
16001598: sub      r4, r1, #0x3a8
1600159c: add      r0, r0, r1
160015a0: sub      r0, r0, r4
160015a4: bl       #0x1600118c
160015a8: add      r0, r0, r4
160015ac: add      r0, r0, #0xfc000
160015b0: add      r0, r0, #0x34c
160015b4: bl       #0x1600118c
160015b8: ldr      r1, [pc, #0x6c]  ; =0xfc6f4
160015bc: sub      r0, r0, #0xfc000
160015c0: sub      r0, r0, #0x34c
160015c4: add      r0, r0, r1
160015c8: bl       #0x16000354  ; ->msys::MDfxChr
160015cc: sub      r1, r4, #0x750
160015d0: add      r0, r0, r1
160015d4: add      r0, r0, #0xfc000
160015d8: add      r0, r0, #0x870
160015dc: bl       #0x16000354  ; ->msys::MDfxChr
160015e0: ldr      r2, [pc, #0x48]  ; =0x808080ff
160015e4: sub      r4, r0, #0xfc000
160015e8: sub      r4, r4, #0x870
160015ec: mov      r1, sp
160015f0: rev      r0, r2
160015f4: str      r0, [sp]
160015f8: ldr      r0, [pc, #0x34]  ; =0x424fd4 gFrameBuf
160015fc: bl       #0x1600035c  ; ->FrameBuf::setClearColor
16001600: mov      r0, r4
16001604: pop      {r3, r4, r5, pc}
16001608: .word    0x160035bc
1600160c: andeq    fp, pc, ip, lsr sl
16001610: .word    0x160034d8
16001614: .word    0xfff04558
16001618: andeq    fp, pc, ip, ror #21
1600161c: .word    0xfff04514
16001620: eoreq    r0, r5, r8, lsl #11
16001624: strdeq   fp, ip, [pc], -ip
16001628: .word    0xfff04404
1600162c: strdeq   ip, sp, [pc], -r4
16001630: strdhi   r8, sb, [r0], pc
16001634: ldrdeq   r4, r5, [r2], #-0xf4
16001638: push     {r4, lr}
1600163c: bl       #0x16001648  ; SaveLoad:save_load::SaveLoadSys
16001640: pop      {r4, lr}
16001644: b        #0x1600018c  ; ->_ZdlPv

<SaveLoad:save_load::SaveLoadSys>  # SaveLoad:_ZN9save_load11SaveLoadSysD1Ev
16001648: push     {r4, r5, r6, r7, r8, lr}
1600164c: mov      r4, r0
16001650: mov      r1, #0
16001654: ldr      r0, [pc, #0x1e4]  ; =0x160035bc
16001658: str      r0, [r4]
1600165c: ldr      r0, [r4, #4]
16001660: bl       #0x1600036c  ; ->ad::fw::TaskBase::term
16001664: ldr      r0, [pc, #0x1d8]  ; =0xfbbfc
16001668: add      r0, r0, r4
1600166c: bl       #0x16000374  ; ->msys::MLyt::term
16001670: ldr      r7, [pc, #0x1d0]  ; =0xfff0405c
16001674: sub      r0, r4, r7
16001678: bl       #0x16000374  ; ->msys::MLyt::term
1600167c: add      r0, r4, #0xfc000
16001680: add      r0, r0, #0x34c
16001684: bl       #0x16000374  ; ->msys::MLyt::term
16001688: ldr      r6, [pc, #0x1bc]  ; =0xfbaa8
1600168c: add      r0, r4, r6
16001690: bl       #0x1600037c  ; ->ad::fw::Resource::term
16001694: add      r0, r6, #0x44
16001698: add      r0, r0, r4
1600169c: bl       #0x1600037c  ; ->ad::fw::Resource::term
160016a0: mov      r5, #0
160016a4: add      r0, r5, r5, lsl #4
160016a8: add      r0, r4, r0, lsl #2
160016ac: add      r0, r0, #0xfb000
160016b0: add      r0, r0, #0xb30
160016b4: bl       #0x1600037c  ; ->ad::fw::Resource::term
160016b8: add      r5, r5, #1
160016bc: cmp      r5, #3
160016c0: blt      #0x160016a4
160016c4: add      r0, r4, #0xfc000
160016c8: add      r0, r0, #0x870
160016cc: bl       #0x16000384  ; ->msys::MDfxChr
160016d0: ldr      r1, [pc, #0x178]  ; =0xfc6f4
160016d4: sub      r0, r0, #0xfc000
160016d8: sub      r0, r0, #0x870
160016dc: add      r0, r0, r1
160016e0: bl       #0x16000384  ; ->msys::MDfxChr
160016e4: ldr      r1, [pc, #0x168]  ; =0xfff0390c
160016e8: ldr      r5, [pc, #0x168]  ; =0x3e4580
160016ec: add      r4, r0, r1
160016f0: add      r4, r4, #0xfc000
160016f4: add      r4, r4, #0x34c
160016f8: mov      r0, r4
160016fc: str      r5, [r4]
16001700: bl       #0x16000374  ; ->msys::MLyt::term
16001704: ldr      r1, [pc, #0x150]  ; =0x16000618
16001708: mov      r3, #0xc
1600170c: mov      r2, #0x10
16001710: add      r0, r4, #0x2b0
16001714: bl       #0x160001ec  ; ->__aeabi_vec_dtor
16001718: ldr      r1, [pc, #0x140]  ; =0x160004b0
1600171c: mov      r3, #0xc
16001720: mov      r2, #0x1c
16001724: add      r0, r4, #0x154
16001728: bl       #0x160001ec  ; ->__aeabi_vec_dtor
1600172c: mov      r0, r4
16001730: nop      
16001734: bl       #0x160012e8
16001738: sub      r0, r0, #0xfc000
1600173c: sub      r0, r0, #0x34c
16001740: sub      r4, r0, r7
16001744: mov      r0, r4
16001748: str      r5, [r4]
1600174c: bl       #0x16000374  ; ->msys::MLyt::term
16001750: ldr      r1, [pc, #0x104]  ; =0x16000618
16001754: mov      r3, #0xc
16001758: mov      r2, #0x10
1600175c: add      r0, r4, #0x2b0
16001760: bl       #0x160001ec  ; ->__aeabi_vec_dtor
16001764: ldr      r1, [pc, #0xf4]  ; =0x160004b0
16001768: mov      r3, #0xc
1600176c: mov      r2, #0x1c
16001770: add      r0, r4, #0x154
16001774: bl       #0x160001ec  ; ->__aeabi_vec_dtor
16001778: mov      r0, r4
1600177c: nop      
16001780: bl       #0x160012e8
16001784: sub      r0, r0, #0x3a8
16001788: mov      r4, r0
1600178c: str      r5, [r0]
16001790: bl       #0x16000374  ; ->msys::MLyt::term
16001794: ldr      r1, [pc, #0xc0]  ; =0x16000618
16001798: mov      r3, #0xc
1600179c: mov      r2, #0x10
160017a0: add      r0, r4, #0x2b0
160017a4: bl       #0x160001ec  ; ->__aeabi_vec_dtor
160017a8: ldr      r1, [pc, #0xb0]  ; =0x160004b0
160017ac: mov      r3, #0xc
160017b0: mov      r2, #0x1c
160017b4: add      r0, r4, #0x154
160017b8: bl       #0x160001ec  ; ->__aeabi_vec_dtor
160017bc: mov      r0, r4
160017c0: nop      
160017c4: bl       #0x160012e8
160017c8: mov      r4, r0
160017cc: ldr      r0, [pc, #0x90]  ; =0xfff04404
160017d0: ldr      r1, [pc, #0x90]  ; =0x24a104 ad::fw::Resource
160017d4: mov      r3, #3
160017d8: add      r0, r0, r4
160017dc: add      r0, r0, #0xfb000
160017e0: mov      r2, #0x44
160017e4: add      r0, r0, #0xb30
160017e8: bl       #0x160001ec  ; ->__aeabi_vec_dtor
160017ec: sub      r0, r4, #0x110
160017f0: nop      
160017f4: bl       #0x1600038c  ; ->ad::fw::Resource
160017f8: ldr      r1, [pc, #0x6c]  ; =0xfff04514
160017fc: add      r0, r0, r1
16001800: add      r0, r0, r6
16001804: bl       #0x1600038c  ; ->ad::fw::Resource
16001808: ldr      r1, [pc, #0x60]  ; =0xfff04558
1600180c: add      r0, r0, r1
16001810: ldr      r1, [pc, #0x5c]  ; =0xfba3c
16001814: add      r0, r0, r1
16001818: bl       #0x16000184  ; ->MsgDataAcsrBase
1600181c: ldr      r1, [pc, #0x54]  ; =0xfff045c4
16001820: add      r0, r0, r1
16001824: add      r0, r0, #0xe9000
16001828: add      r0, r0, #0x50
1600182c: bl       #0x16000394  ; ->Backup
16001830: pop      {r4, r5, r6, r7, r8, lr}
16001834: sub      r0, r0, #0xe9000
16001838: sub      r0, r0, #0x50
1600183c: b        #0x1600039c  ; ->msys::MComSys
16001840: .word    0x160035bc
16001844: strdeq   fp, ip, [pc], -ip
16001848: .word    0xfff0405c
1600184c: andeq    fp, pc, r8, lsr #21
16001850: strdeq   ip, sp, [pc], -r4
16001854: .word    0xfff0390c
16001858: eorseq   r4, lr, r0, lsl #11
1600185c: .word    0x16000618
16001860: .word    0x160004b0
16001864: .word    0xfff04404
16001868: eoreq    sl, r4, r4, lsl #2
1600186c: .word    0xfff04514
16001870: .word    0xfff04558
16001874: andeq    fp, pc, ip, lsr sl
16001878: .word    0xfff045c4

<SaveLoad:save_load::SaveDateTime::init>  # SaveLoad:_ZN9save_load12SaveDateTime4initERNS_11SaveLoadSysERN4msys4MLytEPKcS7_
1600187c: push     {r0, r1, r2, r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
16001880: mov      r5, r1
16001884: mov      sl, r0
16001888: mov      sb, r3
1600188c: vpush    {d8}
16001890: sub      sp, sp, #0x5c
16001894: add      r0, sp, #0x10
16001898: vldr     s16, [sp, #0x98]
1600189c: bl       #0x160003a4  ; ->ad::lyt::LytNumReel3::InitParam
160018a0: mov      r0, #0xff
160018a4: str      r0, [sp]
160018a8: mov      r2, #0
160018ac: add      r0, r5, #0x800
160018b0: add      r1, sp, #0x10
160018b4: mov      r3, r2
160018b8: add      r0, r0, #0x44
160018bc: bl       #0x160003ac  ; ->msys::MLytNumRes::set
160018c0: ldr      fp, [pc, #0x78]  ; =0x16003000
160018c4: ldr      r8, [pc, #0x78]  ; =0x16006a08
160018c8: mov      r7, #0
160018cc: mov      r4, r7
160018d0: add      r2, r5, #0xd3000
160018d4: ldrb     r0, [fp, r4]
160018d8: add      r1, sp, #0x10
160018dc: str      r0, [sp, #0x44]
160018e0: ldr      r0, [r8, r4, lsl #2]
160018e4: stm      sp, {r0, sb}
160018e8: rsb      r0, r4, r4, lsl #3
160018ec: vstr     s16, [sp, #8]
160018f0: add      r0, r0, r0, lsl #2
160018f4: ldr      r3, [sp, #0x6c]
160018f8: add      r6, sl, r0, lsl #4
160018fc: mov      r0, r6
16001900: str      r7, [sp, #0xc]
16001904: bl       #0x160003b4  ; ->msys::MLytNum::init
16001908: vstr     s16, [sp]
1600190c: str      r7, [sp, #4]
16001910: ldr      r2, [r8, r4, lsl #2]
16001914: ldr      r0, [sp, #0x6c]
16001918: mov      r1, r6
1600191c: mov      r3, sb
16001920: bl       #0x160002f4  ; ->msys::MLyt::attachMChr
16001924: add      r4, r4, #1
16001928: cmp      r4, #5
1600192c: blt      #0x160018d0
16001930: add      sp, sp, #0x5c
16001934: vpop     {d8}
16001938: add      sp, sp, #0x10
1600193c: pop      {r4, r5, r6, r7, r8, sb, sl, fp, pc}
16001940: strne    r3, [r0], -r0
16001944: strne    r6, [r0], -r8, lsl #20

<SaveLoad:save_load::SaveDateTime::build>  # SaveLoad:_ZN9save_load12SaveDateTime5buildERK11GameWorkPOD
16001948: push     {r4, r5, r6, lr}
1600194c: mov      r6, r1
16001950: add      r1, r1, #0x2000
16001954: mov      r4, r0
16001958: ldr      r0, [pc, #0xd4]  ; =0x2710
1600195c: ldr      r1, [r1, #0x8b8]
16001960: cmp      r1, r0
16001964: blo      #0x16001980
16001968: ldr      r0, [pc, #0xc8]  ; =0xd1b71759
1600196c: mvn      r2, #0x270
16001970: umull    r3, r0, r0, r1
16001974: lsr      r0, r0, #0xd
16001978: mul      r0, r0, r2
1600197c: add      r1, r1, r0, lsl #4
16001980: add      r0, r4, #0x150
16001984: bl       #0x160003bc  ; ->ad::lyt::LytNumReel3::setValueInstant
16001988: add      r6, r6, #0x2800
1600198c: ldr      r5, [pc, #0xa8]  ; =0x51eb851f
16001990: ldrsb    r1, [r6, #0xbc]
16001994: cmp      r1, #0x64
16001998: blo      #0x160019b0
1600199c: umull    r3, r0, r5, r1
160019a0: mvn      r2, #0x18
160019a4: lsr      r0, r0, #5
160019a8: mul      r0, r0, r2
160019ac: add      r1, r1, r0, lsl #2
160019b0: add      r0, r4, #0x380
160019b4: bl       #0x160003bc  ; ->ad::lyt::LytNumReel3::setValueInstant
160019b8: ldrsb    r1, [r6, #0xbd]
160019bc: cmp      r1, #0x64
160019c0: blo      #0x160019d8
160019c4: umull    r3, r0, r5, r1
160019c8: mvn      r2, #0x18
160019cc: lsr      r0, r0, #5
160019d0: mul      r0, r0, r2
160019d4: add      r1, r1, r0, lsl #2
160019d8: add      r0, r4, #0x5b0
160019dc: bl       #0x160003bc  ; ->ad::lyt::LytNumReel3::setValueInstant
160019e0: ldrsb    r1, [r6, #0xbe]
160019e4: cmp      r1, #0x64
160019e8: blo      #0x16001a00
160019ec: umull    r3, r0, r5, r1
160019f0: mvn      r2, #0x18
160019f4: lsr      r0, r0, #5
160019f8: mul      r0, r0, r2
160019fc: add      r1, r1, r0, lsl #2
16001a00: add      r0, r4, #0x7e0
16001a04: bl       #0x160003bc  ; ->ad::lyt::LytNumReel3::setValueInstant
16001a08: ldrsb    r1, [r6, #0xbf]
16001a0c: cmp      r1, #0x64
16001a10: blo      #0x16001a28
16001a14: umull    r3, r0, r5, r1
16001a18: mvn      r2, #0x18
16001a1c: lsr      r0, r0, #5
16001a20: mul      r0, r0, r2
16001a24: add      r1, r1, r0, lsl #2
16001a28: add      r0, r4, #0xa10
16001a2c: pop      {r4, r5, r6, lr}
16001a30: b        #0x160003bc  ; ->ad::lyt::LytNumReel3::setValueInstant
16001a34: andeq    r2, r0, r0, lsl r7
16001a38: .word    0xd1b71759
16001a3c: mvnpl    r8, pc, lsl r5

<SaveLoad:save_load::MsgWnd::init>  # SaveLoad:_ZN9save_load6MsgWnd4initERN4msys9MPageBaseEPKvP10MemAlcBasej
16001a40: push     {r4, r5, r6, r7, r8, sb, sl, fp, lr}
16001a44: add      r5, r0, #0x6000
16001a48: mov      r4, r0
16001a4c: add      r8, r0, #0x6c00
16001a50: add      r0, r0, #0x6c00
16001a54: add      r0, r0, #0x2ec
16001a58: vpush    {d8}
16001a5c: sub      sp, sp, #4
16001a60: mov      sb, #0
16001a64: ldr      r7, [sp, #0x30]
16001a68: vldr     s16, [pc, #0x124]  ; =0x0 (0)
16001a6c: mov      fp, #1
16001a70: str      r7, [r5, #0xef4]
16001a74: str      r7, [r5, #0xeb0]
16001a78: stm      r0, {r3, sb}
16001a7c: mov      r6, r1
16001a80: vstr     s16, [r8, #0x2b4]
16001a84: vstr     s16, [r8, #0x2b8]
16001a88: strb     fp, [r5, #0xed8]
16001a8c: mvn      sl, #0
16001a90: strb     sb, [r5, #0xed9]
16001a94: add      r0, r4, #0x6c00
16001a98: add      r1, r5, #0xed0
16001a9c: str      sl, [r5, #0xee0]
16001aa0: add      r0, r0, #0x2e8
16001aa4: str      sl, [r5, #0xee4]
16001aa8: stm      r1, {r0, sb}
16001aac: add      r0, r4, #0x14c
16001ab0: str      r2, [sp]
16001ab4: bl       #0x160003c4  ; ->Message::init
16001ab8: ldr      r1, [sp]
16001abc: add      r0, r4, #0x14c
16001ac0: bl       #0x160003cc  ; ->Message::setMsgDat
16001ac4: mov      r0, r4
16001ac8: bl       #0x16001040
16001acc: str      r7, [r5, #0xefc]
16001ad0: vstr     s16, [r8, #0x300]
16001ad4: vstr     s16, [r8, #0x304]
16001ad8: strb     fp, [r5, #0xf24]
16001adc: strb     sb, [r5, #0xf25]
16001ae0: str      sl, [r5, #0xf2c]
16001ae4: str      sl, [r5, #0xf30]
16001ae8: add      r5, r5, #0xc00
16001aec: add      r0, r4, #0x6c00
16001af0: add      r5, r5, #0x31c
16001af4: add      r0, r0, #0x334
16001af8: stm      r5, {r0, sb}
16001afc: cmp      r7, #0x400
16001b00: beq      #0x16001b58
16001b04: sub      r0, r7, #0x400
16001b08: subs     r0, r0, #1
16001b0c: bne      #0x16001b4c
16001b10: add      r0, r4, #4
16001b14: add      r1, r6, #0xc
16001b18: ldrd     r2, r3, [r0]
16001b1c: str      r3, [r2, #4]
16001b20: ldr      r0, [r4, #4]
16001b24: str      r0, [r3]
16001b28: adds     r0, r4, #4
16001b2c: beq      #0x16001b44
16001b30: ldr      r2, [r1]
16001b34: str      r1, [r0, #4]
16001b38: str      r2, [r0]
16001b3c: str      r0, [r2, #4]
16001b40: str      r0, [r1]
16001b44: ldr      r0, [pc, #0x4c]  ; =0x401
16001b48: str      r0, [r4, #0x13c]
16001b4c: add      sp, sp, #4
16001b50: vpop     {d8}
16001b54: pop      {r4, r5, r6, r7, r8, sb, sl, fp, pc}
16001b58: add      r0, r4, #4
16001b5c: add      r1, r6, #4
16001b60: ldrd     r2, r3, [r0]
16001b64: str      r3, [r2, #4]
16001b68: ldr      r0, [r4, #4]
16001b6c: str      r0, [r3]
16001b70: adds     r0, r4, #4
16001b74: beq      #0x16001b8c
16001b78: ldr      r2, [r1]
16001b7c: str      r1, [r0, #4]
16001b80: str      r2, [r0]
16001b84: str      r0, [r2, #4]
16001b88: str      r0, [r1]
16001b8c: mov      r0, #0x400
16001b90: b        #0x16001b48
16001b94: andeq    r0, r0, r0
16001b98: andeq    r0, r0, r1, lsl #8

<SaveLoad:save_load::MsgWnd::play>  # SaveLoad:_ZN9save_load6MsgWnd4playEPKcPKN13MessageSimple8InsParamE
16001b9c: push     {r4, lr}
16001ba0: mov      r4, r0
16001ba4: add      r0, r0, #0x6000
16001ba8: vpush    {d8}
16001bac: str      r1, [r0, #0xef8]!
16001bb0: add      r1, r4, #0x6c00
16001bb4: str      r2, [r0, #0x30]
16001bb8: add      r1, r1, #0x2f8
16001bbc: add      r0, r4, #0x14c
16001bc0: bl       #0x160003d4  ; ->Message::play
16001bc4: add      r4, r4, #0xcc
16001bc8: vldr     s16, [pc, #0x2c]  ; =0x0 (0)
16001bcc: vldr     s17, [pc, #0x2c]  ; =0xc3340000 (-180)
16001bd0: mov      r0, r4
16001bd4: bl       #0x160002dc  ; ->MoveVBase::stop
16001bd8: vstr     s16, [r4, #0x1c]
16001bdc: add      r0, r4, #0x20
16001be0: vstmia   r0, {s16, s17}
16001be4: ldr      r0, [r4, #0x1c]
16001be8: str      r0, [r4, #4]!
16001bec: add      r4, r4, #4
16001bf0: vstmia   r4, {s16, s17}
16001bf4: vpop     {d8}
16001bf8: pop      {r4, pc}
16001bfc: andeq    r0, r0, r0
16001c00: teqgt    r4, #0

<SaveLoad:save_load::Summary::updateInput>  # SaveLoad:_ZN9save_load7Summary11updateInputEPKN4msys6MInputE
16001c04: push     {r4, r5, r6, lr}
16001c08: add      r2, r0, #0x6c00
16001c0c: add      r5, r0, #0x6c00
16001c10: vpush    {d8}
16001c14: add      r2, r2, #0x68
16001c18: ldr      r1, [r1, #4]
16001c1c: vldr     s17, [pc, #0x84]  ; =0x3f800000 (1)
16001c20: vldr     s16, [pc, #0x84]  ; =0x0 (0)
16001c24: tst      r1, #0x200
16001c28: add      r5, r5, #0x84
16001c2c: add      r4, r0, #0x6c00
16001c30: beq      #0x16001c54
16001c34: vmov.f32 s0, s17
16001c38: mov      r0, r2
16001c3c: bl       #0x160003dc  ; ->ad::lyt::LytAnim::stopAndSetFrm
16001c40: vmov.f32 s0, s16
16001c44: mov      r0, r5
16001c48: bl       #0x160003dc  ; ->ad::lyt::LytAnim::stopAndSetFrm
16001c4c: vldr     s0, [pc, #0x5c]  ; =0xc0000000 (-2)
16001c50: b        #0x16001c9c
16001c54: vmov.f32 s0, s16
16001c58: tst      r1, #0x100
16001c5c: mov      r0, r2
16001c60: beq      #0x16001c84
16001c64: bl       #0x160003dc  ; ->ad::lyt::LytAnim::stopAndSetFrm
16001c68: vmov.f32 s0, s17
16001c6c: mov      r0, r5
16001c70: bl       #0x160003dc  ; ->ad::lyt::LytAnim::stopAndSetFrm
16001c74: vldr     s0, [pc, #0x38]  ; =0x40000000 (2)
16001c78: vstr     s0, [r4, #0x64]
16001c7c: vpop     {d8}
16001c80: pop      {r4, r5, r6, pc}
16001c84: nop      
16001c88: bl       #0x160003dc  ; ->ad::lyt::LytAnim::stopAndSetFrm
16001c8c: vmov.f32 s0, s16
16001c90: mov      r0, r5
16001c94: bl       #0x160003dc  ; ->ad::lyt::LytAnim::stopAndSetFrm
16001c98: vldr     s0, [pc, #0x18]  ; =0xbf800000 (-1)
16001c9c: vstr     s0, [r4, #0x64]
16001ca0: vpop     {d8}
16001ca4: pop      {r4, r5, r6, pc}
16001ca8: svclo    #0x800000
16001cac: andeq    r0, r0, r0
16001cb0: andgt    r0, r0, r0
16001cb4: andmi    r0, r0, r0
16001cb8: svclt    #0x800000

<SaveLoad:save_load::Summary::init>  # SaveLoad:_ZN9save_load7Summary4initEP10MemAlcBaseRN2ad3lyt6LayoutEPPKc
16001cbc: push     {r4, r5, r6, r7, r8, sb, sl, lr}
16001cc0: mov      r6, r0
16001cc4: mov      r8, r3
16001cc8: add      r3, r0, #0x6c00
16001ccc: add      r0, r0, #0x4000
16001cd0: mov      sb, r2
16001cd4: add      r0, r0, #0x2c40
16001cd8: vpush    {d8}
16001cdc: mov      r2, #0x400
16001ce0: str      r2, [r0], #-0xc
16001ce4: mov      ip, #0
16001ce8: vldr     s16, [pc, #0xd8]  ; =0x0 (0)
16001cec: stm      r0, {r1, ip}
16001cf0: add      r0, r6, #0x14c
16001cf4: vstr     s16, [r3, #0x3c]
16001cf8: bl       #0x160003e4  ; ->MessageSimple::init
16001cfc: mov      r0, r6
16001d00: bl       #0x16001040
16001d04: add      r0, r6, #0x5000
16001d08: mov      r1, #1
16001d0c: strb     r1, [r0, #0xc08]
16001d10: add      r4, r6, #0xcc
16001d14: strb     r1, [r0, #0xc09]
16001d18: vldr     s17, [pc, #0xac]  ; =0x3c23d70a (0.01)
16001d1c: mov      r0, r4
16001d20: bl       #0x160002dc  ; ->MoveVBase::stop
16001d24: vstr     s16, [r4, #0x1c]
16001d28: add      r0, r4, #0x20
16001d2c: ldr      r7, [pc, #0x9c]  ; =0x160069f4
16001d30: mov      r5, #0
16001d34: vstmia   r0, {s16, s17}
16001d38: ldr      r0, [r4, #0x1c]
16001d3c: str      r0, [r4, #4]!
16001d40: add      r4, r4, #4
16001d44: vstmia   r4, {s16, s17}
16001d48: mov      r0, sb
16001d4c: ldr      r1, [r8, r5, lsl #2]
16001d50: bl       #0x160003ec  ; ->ad::lyt::Layout::FindPartsPaneByName
16001d54: ldr      sl, [r0, #0xac]
16001d58: rsb      r0, r5, r5, lsl #3
16001d5c: ldr      r2, [r7, r5, lsl #2]
16001d60: add      r0, r6, r0, lsl #2
16001d64: add      r4, r0, #0x6c00
16001d68: add      r4, r4, #0x68
16001d6c: add      r3, pc, #0x60
16001d70: mov      r1, sl
16001d74: mov      r0, r4
16001d78: bl       #0x160003f4  ; ->ad::lyt::LytAnim::init
16001d7c: vmov.f32 s0, s16
16001d80: mov      r0, r4
16001d84: bl       #0x160003dc  ; ->ad::lyt::LytAnim::stopAndSetFrm
16001d88: mov      r0, r4
16001d8c: mov      r1, #1
16001d90: bl       #0x160003fc  ; ->ad::lyt::LytAnim::term
16001d94: ldr      r2, [pc, #0x3c]  ; =0x16003005
16001d98: mov      r0, r4
16001d9c: add      r3, pc, #0x30
16001da0: mov      r1, sl
16001da4: bl       #0x160003f4  ; ->ad::lyt::LytAnim::init
16001da8: vmov.f32 s0, s16
16001dac: mov      r0, r4
16001db0: bl       #0x160003dc  ; ->ad::lyt::LytAnim::stopAndSetFrm
16001db4: add      r5, r5, #1
16001db8: cmp      r5, #2
16001dbc: blt      #0x16001d48
16001dc0: vpop     {d8}
16001dc4: pop      {r4, r5, r6, r7, r8, sb, sl, pc}
16001dc8: andeq    r0, r0, r0
16001dcc: stclo    p7, c13, [r3], #-0x28
16001dd0: .word    0x160069f4
16001dd4: andeq    r0, r0, r0
16001dd8: strne    r3, [r0], -r5

<SaveLoad:save_load::Summary::build>  # SaveLoad:_ZN9save_load7Summary5buildERNS_11SaveLoadSysEj
16001ddc: mov      r3, r1
16001de0: ldr      r1, [pc, #0xe0]  ; =0x160030d0
16001de4: push     {r4, r5, r6, lr}
16001de8: mov      r4, r0
16001dec: add      r0, r1, #0x140
16001df0: sub      r0, r0, #8
16001df4: cmp      r0, r1
16001df8: ldrhi    ip, [r0]
16001dfc: cmphi    ip, r2
16001e00: bhi      #0x16001df0
16001e04: ldr      r1, [r0, #4]
16001e08: ldr      r0, [pc, #0xbc]  ; =0xfba44
16001e0c: add      r0, r0, r3
16001e10: mov      r5, r0
16001e14: bl       #0x16000404  ; ->LMS_GetTextIndexByLabel
16001e18: mov      r1, r0
16001e1c: mov      r0, r5
16001e20: bl       #0x1600040c  ; ->LMS_GetText
16001e24: mov      r2, #0
16001e28: mov      r1, r0
16001e2c: mov      r3, r2
16001e30: mov      r0, r4
16001e34: bl       #0x160001d4  ; ->msys::MMsg::playStr
16001e38: ldr      r0, [pc, #0x90]  ; =0x3f7eec _ZGVZN2nn4math4VEC34ZeroEvE4zero
16001e3c: add      r5, r4, #0x6c00
16001e40: add      r5, r5, #0x58
16001e44: ldrb     r0, [r0]
16001e48: tst      r0, #1
16001e4c: bne      #0x16001e80
16001e50: ldr      r0, [pc, #0x78]  ; =0x3f7eec _ZGVZN2nn4math4VEC34ZeroEvE4zero
16001e54: bl       #0x160001dc  ; ->__cxa_guard_acquire
16001e58: cmp      r0, #0
16001e5c: nop      
16001e60: beq      #0x16001e80
16001e64: ldr      r0, [pc, #0x6c]  ; =0x434c48 _ZZN2nn4math4VEC34ZeroEvE4zero
16001e68: vldr     s0, [pc, #0x64]  ; =0x0 (0)
16001e6c: vstr     s0, [r0]
16001e70: vstr     s0, [r0, #4]
16001e74: vstr     s0, [r0, #8]
16001e78: ldr      r0, [pc, #0x50]  ; =0x3f7eec _ZGVZN2nn4math4VEC34ZeroEvE4zero
16001e7c: bl       #0x160001e4  ; ->__cxa_guard_release
16001e80: ldr      r0, [pc, #0x50]  ; =0x434c48 _ZZN2nn4math4VEC34ZeroEvE4zero
16001e84: vldr     s0, [pc, #0x54]  ; =0x41f00000 (30)
16001e88: ldr      r1, [r0]
16001e8c: str      r1, [r5]
16001e90: ldr      r1, [r0, #4]
16001e94: str      r1, [r5, #4]
16001e98: ldr      r0, [r0, #8]
16001e9c: mov      r1, #0
16001ea0: str      r0, [r5, #8]
16001ea4: ldr      r0, [pc, #0x30]  ; =0x5c08
16001ea8: strb     r1, [r0, r4]
16001eac: add      r0, r4, #0x6c00
16001eb0: add      r0, r0, #0x44
16001eb4: bl       #0x16000414  ; ->Frm::play
16001eb8: ldr      r1, [pc, #0x24]  ; =0x6c54
16001ebc: mov      r0, #1
16001ec0: strb     r0, [r1, r4]
16001ec4: pop      {r4, r5, r6, pc}
16001ec8: .word    0x160030d0
16001ecc: andeq    fp, pc, r4, asr #20
16001ed0: eorseq   r7, pc, ip, ror #29
16001ed4: andeq    r0, r0, r0
16001ed8: subeq    r4, r3, r8, asr #24
16001edc: andeq    r5, r0, r8, lsl #24
16001ee0: mvnsmi   r0, r0
16001ee4: andeq    r6, r0, r4, asr ip
16001ee8: push     {r4, lr}
16001eec: mov      r4, r0
16001ef0: ldr      r0, [pc, #0x50]  ; =0x160035dc
16001ef4: ldr      r1, [pc, #0x50]  ; =0x160004b0
16001ef8: mov      r3, #2
16001efc: str      r0, [r4]
16001f00: add      r0, r4, #0x6c00
16001f04: mov      r2, #0x1c
16001f08: add      r0, r0, #0x68
16001f0c: bl       #0x160001ec  ; ->__aeabi_vec_dtor
16001f10: add      r0, r4, #0x6c00
16001f14: add      r0, r0, #0x44
16001f18: vldr     s0, [pc, #0x30]  ; =0x0 (0)
16001f1c: vstr     s0, [r0, #8]
16001f20: ldr      r0, [pc, #0x2c]  ; =0x3e45c4
16001f24: str      r0, [r4]
16001f28: add      r0, r4, #0x14c
16001f2c: bl       #0x1600041c  ; ->MessageSimple::term
16001f30: add      r0, r4, #0x14c
16001f34: bl       #0x16000424  ; ->MessageSimple
16001f38: sub      r0, r0, #0x14c
16001f3c: bl       #0x160012e8
16001f40: pop      {r4, lr}
16001f44: b        #0x1600018c  ; ->_ZdlPv
16001f48: .word    0x160035dc
16001f4c: .word    0x160004b0
16001f50: andeq    r0, r0, r0
16001f54: eorseq   r4, lr, r4, asr #11
16001f58: push     {r4, lr}
16001f5c: mov      r4, r0
16001f60: ldr      r0, [pc, #0x4c]  ; =0x160035dc
16001f64: ldr      r1, [pc, #0x4c]  ; =0x160004b0
16001f68: mov      r3, #2
16001f6c: str      r0, [r4]
16001f70: add      r0, r4, #0x6c00
16001f74: mov      r2, #0x1c
16001f78: add      r0, r0, #0x68
16001f7c: bl       #0x160001ec  ; ->__aeabi_vec_dtor
16001f80: add      r0, r4, #0x6c00
16001f84: add      r0, r0, #0x44
16001f88: vldr     s0, [pc, #0x2c]  ; =0x0 (0)
16001f8c: vstr     s0, [r0, #8]
16001f90: ldr      r0, [pc, #0x28]  ; =0x3e45c4
16001f94: str      r0, [r4]
16001f98: add      r0, r4, #0x14c
16001f9c: bl       #0x1600041c  ; ->MessageSimple::term
16001fa0: add      r0, r4, #0x14c
16001fa4: bl       #0x16000424  ; ->MessageSimple
16001fa8: sub      r0, r0, #0x14c
16001fac: bl       #0x160012e8
16001fb0: pop      {r4, pc}
16001fb4: .word    0x160035dc
16001fb8: .word    0x160004b0
16001fbc: andeq    r0, r0, r0
16001fc0: eorseq   r4, lr, r4, asr #11

<SaveLoad:save_load::FilePanel::init>  # SaveLoad:_ZN9save_load9FilePanel4initENS0_5eModeERNS_11SaveLoadSysERN4msys4MLytEPKc
16001fc4: push     {r0, r1, r2, r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
16001fc8: mov      r4, r1
16001fcc: mov      r3, #0
16001fd0: mov      sb, r2
16001fd4: mov      r2, r3
16001fd8: vpush    {d8, d9}
16001fdc: sub      sp, sp, #0xb4
16001fe0: ldr      r6, [sp, #0xf8]
16001fe4: ldr      r0, [sp, #0xd0]
16001fe8: mov      r1, r6
16001fec: bl       #0x1600042c  ; ->msys::MLyt::getParts
16001ff0: ldr      r1, [r0, #0xac]
16001ff4: ldr      r0, [sp, #0xc4]
16001ff8: ldr      r2, [pc, #0x1e4]  ; =0x160069ec
16001ffc: vldr     s16, [pc, #0x1e4]  ; =0x0 (0)
16002000: vldr     s19, [pc, #0x1e4]  ; =0x3f800000 (1)
16002004: str      r1, [r0, #0xe10]
16002008: ldr      r2, [r2, r4, lsl #2]
1600200c: vstr     s16, [sp, #0x3c]
16002010: vstr     s19, [sp, #0x40]
16002014: mov      r4, #1
16002018: vstr     s16, [sp, #0x44]
1600201c: mov      r7, #0
16002020: strh     r4, [sp, #0x48]
16002024: add      r0, sp, #0x38
16002028: add      r3, pc, #0x1b0
1600202c: strh     r7, [sp, #0x4a]
16002030: bl       #0x160003f4  ; ->ad::lyt::LytAnim::init
16002034: vmov.f32 s0, s16
16002038: add      r0, sp, #0x38
1600203c: bl       #0x160003dc  ; ->ad::lyt::LytAnim::stopAndSetFrm
16002040: mov      r1, #1
16002044: add      r0, sp, #0x38
16002048: bl       #0x160003fc  ; ->ad::lyt::LytAnim::term
1600204c: add      r0, sb, #0x800
16002050: vstr     s16, [sp, #0x44]
16002054: add      r0, r0, #0x44
16002058: ldr      fp, [pc, #0x190]  ; =0x160069fc
1600205c: str      r0, [sp, #0xa0]
16002060: add      r0, sb, #0xd3000
16002064: mov      r8, #0
16002068: str      r0, [sp, #0xac]
1600206c: ldr      r0, [sp, #0xd0]
16002070: rsb      r1, r8, r8, lsl #4
16002074: and      r4, r8, #0xff
16002078: str      r0, [sp, #0x30]
1600207c: ldr      r0, [sp, #0xc4]
16002080: add      r1, r1, r1, lsl #2
16002084: mov      r3, #0
16002088: add      r5, r0, r1, lsl #4
1600208c: ldr      r1, [fp, r4, lsl #2]
16002090: ldr      r0, [sp, #0x30]
16002094: mov      r2, r6
16002098: bl       #0x1600042c  ; ->msys::MLyt::getParts
1600209c: ldr      r0, [r0, #0xac]
160020a0: str      r0, [r5]
160020a4: add      r0, sp, #0x58
160020a8: bl       #0x160003a4  ; ->ad::lyt::LytNumReel3::InitParam
160020ac: mov      r0, #0xff
160020b0: str      r0, [sp]
160020b4: ldr      r0, [sp, #0xa0]
160020b8: add      r1, sp, #0x58
160020bc: mov      r2, #2
160020c0: mov      r3, #1
160020c4: bl       #0x160003ac  ; ->msys::MLytNumRes::set
160020c8: ldr      r0, [pc, #0x124]  ; =0x1600302c
160020cc: ldr      r1, [fp, r4, lsl #2]
160020d0: ldr      r2, [sp, #0xac]
160020d4: stm      sp, {r0, r1, r6, r7}
160020d8: add      r1, sp, #0x58
160020dc: ldr      r3, [sp, #0x30]
160020e0: add      r0, r5, #4
160020e4: bl       #0x160003b4  ; ->msys::MLytNum::init
160020e8: strd     r6, r7, [sp]
160020ec: ldr      r3, [fp, r4, lsl #2]
160020f0: ldr      r2, [pc, #0xfc]  ; =0x1600302c
160020f4: ldr      r0, [sp, #0x30]
160020f8: add      r1, r5, #4
160020fc: bl       #0x160002f4  ; ->msys::MLyt::attachMChr
16002100: add      r0, r4, r4, lsl #4
16002104: add      r0, sb, r0, lsl #2
16002108: add      r1, r0, #0xfb000
1600210c: add      r1, r1, #0xb30
16002110: add      r0, r5, #0x234
16002114: bl       #0x16000434  ; ->msys::MCellAnime::init
16002118: ldr      r0, [pc, #0xd8]  ; =0x1600321c
1600211c: add      sl, r5, #0x300
16002120: add      r0, r0, r4, lsl #3
16002124: vldmia   r0, {s17, s18}
16002128: mov      r0, sl
1600212c: bl       #0x160002dc  ; ->MoveVBase::stop
16002130: vstr     s16, [sl, #0x24]
16002134: add      r0, sl, #0x1c
16002138: vmov.f32 s0, s19
1600213c: vstmia   r0, {s17, s18}
16002140: mov      r2, #0
16002144: vstr     s16, [sl, #0xc]
16002148: add      sl, sl, #4
1600214c: ldr      r0, [pc, #0xa8]  ; =0x1600300c
16002150: vstmia   sl, {s17, s18}
16002154: ldrb     r1, [r0, r4, lsl #1]
16002158: add      r0, r5, #0x380
1600215c: bl       #0x1600043c  ; ->CellAnime::play
16002160: strd     r6, r7, [sp]
16002164: ldr      r3, [fp, r4, lsl #2]
16002168: ldr      r2, [pc, #0x90]  ; =0x160030a7
1600216c: ldr      r0, [sp, #0x30]
16002170: add      r1, r5, #0x234
16002174: bl       #0x160002f4  ; ->msys::MLyt::attachMChr
16002178: ldr      r1, [r5]
1600217c: vstr     s16, [sp, #0x14]
16002180: vstr     s19, [sp, #0x18]
16002184: mov      ip, #1
16002188: vstr     s16, [sp, #0x1c]
1600218c: strh     ip, [sp, #0x20]
16002190: ldr      r2, [pc, #0x6c]  ; =0x16003034
16002194: ldr      r3, [pc, #0x6c]  ; =0x1600257c
16002198: add      r0, sp, #0x10
1600219c: strh     r7, [sp, #0x22]
160021a0: bl       #0x160003f4  ; ->ad::lyt::LytAnim::init
160021a4: vmov     s0, r4
160021a8: add      r0, sp, #0x10
160021ac: vcvt.f32.u32 s0, s0
160021b0: bl       #0x160003dc  ; ->ad::lyt::LytAnim::stopAndSetFrm
160021b4: mov      r1, #1
160021b8: add      r0, sp, #0x10
160021bc: bl       #0x160003fc  ; ->ad::lyt::LytAnim::term
160021c0: add      r8, r8, #1
160021c4: cmp      r8, #3
160021c8: vstr     s16, [sp, #0x1c]
160021cc: blt      #0x1600206c
160021d0: add      sp, sp, #0xb4
160021d4: vpop     {d8, d9}
160021d8: add      sp, sp, #0x10
160021dc: pop      {r4, r5, r6, r7, r8, sb, sl, fp, pc}
160021e0: andeq    r0, r0, r0
160021e4: strne    r6, [r0], -ip, ror #19
160021e8: andeq    r0, r0, r0
160021ec: svclo    #0x800000
160021f0: .word    0x160069fc
160021f4: strne    r3, [r0], -ip, lsr #32
160021f8: .word    0x1600321c
160021fc: strne    r3, [r0], -ip
16002200: strne    r3, [r0], -r7, lsr #1
16002204: .word    0x16003034
16002208: .word    0x1600257c

<SaveLoad:save_load::FilePanel::build>  # SaveLoad:_ZN9save_load9FilePanel5buildERK11GameWorkPOD
1600220c: push     {r4, r5, r6, r7, r8, sb, sl, fp, lr}
16002210: mov      r5, #0
16002214: mov      r8, r0
16002218: mov      r7, r1
1600221c: mov      sb, #1
16002220: ldr      r2, [pc, #0x194]  ; =0x1600309e
16002224: add      r3, pc, #0x194
16002228: vpush    {d8}
1600222c: sub      sp, sp, #0x104
16002230: ldr      r1, [r8, #0xe10]
16002234: vldr     s16, [pc, #0x188]  ; =0x0 (0)
16002238: vldr     s17, [pc, #0x188]  ; =0x3f800000 (1)
1600223c: add      r4, sp, #0xb4
16002240: add      r0, sp, #0xb0
16002244: vstmia   r4, {s16, s17}
16002248: vstr     s16, [sp, #0xbc]
1600224c: strh     sb, [sp, #0xc0]
16002250: strh     r5, [sp, #0xc2]
16002254: bl       #0x160003f4  ; ->ad::lyt::LytAnim::init
16002258: add      r0, r7, #0x2000
1600225c: ldrb     r1, [r0, #0x8b0]
16002260: tst      r1, #1
16002264: beq      #0x1600228c
16002268: vmov.f32 s0, s16
1600226c: add      r0, sp, #0xb0
16002270: bl       #0x160003dc  ; ->ad::lyt::LytAnim::stopAndSetFrm
16002274: mov      r1, #1
16002278: add      r0, sp, #0xb0
1600227c: bl       #0x160003fc  ; ->ad::lyt::LytAnim::term
16002280: add      sp, sp, #0x104
16002284: vpop     {d8}
16002288: pop      {r4, r5, r6, r7, r8, sb, sl, fp, pc}
1600228c: ldr      r0, [r0, #0x8b4]
16002290: ldr      r1, [pc, #0x134]  ; =0x4e20
16002294: cmp      r1, r0, lsr #8
16002298: movhi    r0, #1
1600229c: movls    r0, #2
160022a0: vmov     s0, r0
160022a4: add      r0, sp, #0xb0
160022a8: vcvt.f32.u32 s0, s0
160022ac: bl       #0x160003dc  ; ->ad::lyt::LytAnim::stopAndSetFrm
160022b0: add      r0, sp, #0xf8
160022b4: nop      
160022b8: bl       #0x16000444  ; ->DataPcEquipFxParam
160022bc: mov      r4, #0
160022c0: and      r1, r4, #0xff
160022c4: add      r0, r4, r4, lsl #2
160022c8: add      r0, r0, r4, lsl #3
160022cc: add      r3, sp, #0xf8
160022d0: add      r2, r7, r0, lsl #2
160022d4: mov      r0, sp
160022d8: bl       #0x1600044c  ; ->DataPc
160022dc: rsb      r0, r4, r4, lsl #4
160022e0: mov      sl, sp
160022e4: add      r0, r0, r0, lsl #2
160022e8: add      r6, r8, r0, lsl #4
160022ec: add      fp, r6, #4
160022f0: mov      r0, sl
160022f4: bl       #0x16000454  ; ->DataPc::getLv
160022f8: mov      r1, r0
160022fc: add      r0, fp, #0x150
16002300: bl       #0x160003bc  ; ->ad::lyt::LytNumReel3::setValueInstant
16002304: add      r0, sp, #0xd0
16002308: strb     r5, [sp, #0xcc]
1600230c: ldr      r3, [pc, #0xbc]  ; =0x1600257c
16002310: ldr      r2, [pc, #0xbc]  ; =0x160030ba
16002314: vstmia   r0, {s16, s17}
16002318: add      r0, sp, #0xcc
1600231c: vstr     s16, [sp, #0xd8]
16002320: strh     sb, [sp, #0xdc]
16002324: strh     r5, [sp, #0xde]
16002328: str      r5, [sp, #0xe0]
1600232c: str      r5, [sp, #0xe4]
16002330: ldr      r1, [r6]
16002334: bl       #0x160003f4  ; ->ad::lyt::LytAnim::init
16002338: mov      r0, sl
1600233c: nop      
16002340: bl       #0x16000454  ; ->DataPc::getLv
16002344: cmp      r0, #9
16002348: movhi    r0, #1
1600234c: movls    r0, #0
16002350: vmov     s0, r0
16002354: add      r0, sp, #0xcc
16002358: vcvt.f32.u32 s0, s0
1600235c: bl       #0x160003dc  ; ->ad::lyt::LytAnim::stopAndSetFrm
16002360: mov      r1, #1
16002364: add      r0, sp, #0xcc
16002368: bl       #0x160003fc  ; ->ad::lyt::LytAnim::term
1600236c: ldr      r3, [pc, #0x5c]  ; =0x1600257c
16002370: ldr      r2, [pc, #0x60]  ; =0x160030c7
16002374: ldr      r1, [r6]
16002378: add      r0, sp, #0xcc
1600237c: bl       #0x160003f4  ; ->ad::lyt::LytAnim::init
16002380: mov      r0, sl
16002384: nop      
16002388: bl       #0x1600045c  ; ->DataPc::getRank
1600238c: vmov     s0, r0
16002390: add      r0, sp, #0xcc
16002394: vcvt.f32.u32 s0, s0
16002398: bl       #0x160003dc  ; ->ad::lyt::LytAnim::stopAndSetFrm
1600239c: mov      r1, #1
160023a0: add      r0, sp, #0xcc
160023a4: bl       #0x160003fc  ; ->ad::lyt::LytAnim::term
160023a8: add      r4, r4, #1
160023ac: cmp      r4, #3
160023b0: vstr     s16, [sp, #0xd8]
160023b4: blt      #0x160022c0
160023b8: b        #0x16002274
160023bc: .word    0x1600309e
160023c0: andeq    r0, r0, r0
160023c4: andeq    r0, r0, r0
160023c8: svclo    #0x800000
160023cc: andeq    r4, r0, r0, lsr #28
160023d0: .word    0x1600257c
160023d4: .word    0x160030ba
160023d8: strne    r3, [r0], -r7, asr #1
160023dc: push     {r4, r5, r6, r7, r8, sb, sl, lr}
160023e0: mov      r4, r1
160023e4: mov      r6, r2
160023e8: mov      sl, r3
160023ec: ldr      r8, [pc, #0x168]  ; =0x160069fc
160023f0: mov      r5, r0
160023f4: vpush    {d8, d9}
160023f8: sub      sp, sp, #0x78
160023fc: mov      r3, #0
16002400: ldr      r7, [sp, #0xa8]
16002404: ldr      r1, [r8, r4, lsl #2]
16002408: mov      r0, sl
1600240c: mov      r2, r7
16002410: bl       #0x1600042c  ; ->msys::MLyt::getParts
16002414: ldr      r0, [r0, #0xac]
16002418: str      r0, [r5]
1600241c: add      r0, sp, #0x30
16002420: bl       #0x160003a4  ; ->ad::lyt::LytNumReel3::InitParam
16002424: mov      r0, #0xff
16002428: str      r0, [sp]
1600242c: add      r0, r6, #0x800
16002430: add      r1, sp, #0x30
16002434: mov      r2, #2
16002438: mov      r3, #1
1600243c: add      r0, r0, #0x44
16002440: bl       #0x160003ac  ; ->msys::MLytNumRes::set
16002444: ldr      r1, [pc, #0x114]  ; =0x1600302c
16002448: ldr      r0, [r8, r4, lsl #2]
1600244c: add      ip, sp, #4
16002450: str      r1, [sp]
16002454: mov      sb, #0
16002458: stm      ip, {r0, r7, sb}
1600245c: add      r2, r6, #0xd3000
16002460: mov      r3, sl
16002464: add      r1, sp, #0x30
16002468: add      r0, r5, #4
1600246c: bl       #0x160003b4  ; ->msys::MLytNum::init
16002470: stm      sp, {r7, sb}
16002474: ldr      r3, [r8, r4, lsl #2]
16002478: ldr      r2, [pc, #0xe0]  ; =0x1600302c
1600247c: add      r1, r5, #4
16002480: mov      r0, sl
16002484: bl       #0x160002f4  ; ->msys::MLyt::attachMChr
16002488: add      r0, r4, r4, lsl #4
1600248c: add      r0, r6, r0, lsl #2
16002490: add      r1, r0, #0xfb000
16002494: add      r1, r1, #0xb30
16002498: add      r0, r5, #0x234
1600249c: bl       #0x16000434  ; ->msys::MCellAnime::init
160024a0: ldr      r0, [pc, #0xbc]  ; =0x1600321c
160024a4: add      r6, r5, #0x300
160024a8: vldr     s16, [pc, #0xb8]  ; =0x0 (0)
160024ac: add      r0, r0, r4, lsl #3
160024b0: vldmia   r0, {s17, s18}
160024b4: mov      r0, r6
160024b8: bl       #0x160002dc  ; ->MoveVBase::stop
160024bc: vstr     s16, [r6, #0x24]
160024c0: add      r0, r6, #0x1c
160024c4: mov      r2, #0
160024c8: vstmia   r0, {s17, s18}
160024cc: vstr     s16, [r6, #0xc]
160024d0: add      r6, r6, #4
160024d4: ldr      r0, [pc, #0x94]  ; =0x1600300c
160024d8: vstmia   r6, {s17, s18}
160024dc: vldr     s17, [pc, #0x88]  ; =0x3f800000 (1)
160024e0: ldrb     r1, [r0, r4, lsl #1]
160024e4: vmov.f32 s0, s17
160024e8: add      r0, r5, #0x380
160024ec: bl       #0x1600043c  ; ->CellAnime::play
160024f0: stm      sp, {r7, sb}
160024f4: ldr      r3, [r8, r4, lsl #2]
160024f8: ldr      r2, [pc, #0x74]  ; =0x160030a7
160024fc: add      r1, r5, #0x234
16002500: mov      r0, sl
16002504: bl       #0x160002f4  ; ->msys::MLyt::attachMChr
16002508: ldr      r1, [r5]
1600250c: add      r8, sp, #0x14
16002510: mov      ip, #1
16002514: vstmia   r8, {s16, s17}
16002518: add      r0, sp, #0x10
1600251c: vstr     s16, [sp, #0x1c]
16002520: strh     ip, [sp, #0x20]
16002524: ldr      r2, [pc, #0x4c]  ; =0x16003034
16002528: add      r3, pc, #0x4c
1600252c: strh     sb, [sp, #0x22]
16002530: bl       #0x160003f4  ; ->ad::lyt::LytAnim::init
16002534: vmov     s0, r4
16002538: add      r0, sp, #0x10
1600253c: vcvt.f32.u32 s0, s0
16002540: bl       #0x160003dc  ; ->ad::lyt::LytAnim::stopAndSetFrm
16002544: mov      r1, #1
16002548: add      r0, sp, #0x10
1600254c: bl       #0x160003fc  ; ->ad::lyt::LytAnim::term
16002550: add      sp, sp, #0x78
16002554: vpop     {d8, d9}
16002558: pop      {r4, r5, r6, r7, r8, sb, sl, pc}
1600255c: .word    0x160069fc
16002560: strne    r3, [r0], -ip, lsr #32
16002564: .word    0x1600321c
16002568: andeq    r0, r0, r0
1600256c: svclo    #0x800000
16002570: strne    r3, [r0], -ip
16002574: strne    r3, [r0], -r7, lsr #1
16002578: .word    0x16003034
1600257c: andeq    r0, r0, r0
16002580: add      r0, r0, #4
16002584: b        #0x1600029c  ; ->nn::fs::detail::FileBase::TryGetSize
16002588: ldrd     r0, r1, [r0, #8]
1600258c: bx       lr
16002590: add      r0, r0, #8
16002594: ldm      r0, {r0, r2}
16002598: stm      r1, {r0, r2}
1600259c: mov      r0, #0
160025a0: bx       lr
160025a4: str      lr, [sp, #-4]!
160025a8: sub      sp, sp, #0xc
160025ac: mov      r1, sp
160025b0: add      r0, r0, #4
160025b4: bl       #0x1600029c  ; ->nn::fs::detail::FileBase::TryGetSize
160025b8: mov      r1, pc
160025bc: lsrs     r2, r0, #0x1f
160025c0: blne     #0x1600019c  ; ->nn::err::CTR::ThrowFatalErrAll
160025c4: ldrd     r0, r1, [sp]
160025c8: add      sp, sp, #0xc
160025cc: pop      {pc}
160025d0: mov      r0, #7
160025d4: bx       lr
160025d8: and      r1, r1, #0xff
160025dc: orr      r1, r1, r1, lsl #8
160025e0: orr      r1, r1, r1, lsl #16
160025e4: str      r1, [r0]
160025e8: str      r1, [r0, #4]
160025ec: str      r1, [r0, #8]
160025f0: bx       lr

<SaveLoad:nnroControlObject_>  # SaveLoad:nnroControlObject_
160025f4: ldr      r2, [pc, #0x80]  ; =0x16006a1c
160025f8: cmp      r1, #5
160025fc: push     {r4, lr}
16002600: ldrlo    pc, [pc, r1, lsl #2]
16002604: b        #0x16002660
16002608: .word    0x1600261c
1600260c: strne    r2, [r0], -r4, lsr #12
16002610: strne    r2, [r0], -ip, lsr #12
16002614: .word    0x16002638
16002618: strne    r2, [r0], -r8, asr #12
1600261c: ldr      r1, [pc, #0x5c]  ; =0x0
16002620: b        #0x16002630
16002624: str      r0, [r2]
16002628: b        #0x16002658
1600262c: ldr      r1, [r2]
16002630: str      r1, [r0]
16002634: b        #0x16002658
16002638: ldr      r1, [pc, #0x44]  ; =0x160026a0
1600263c: str      r1, [r0]
16002640: ldr      r1, [pc, #0x40]  ; =0x160026a0
16002644: b        #0x16002654
16002648: ldr      r1, [pc, #0x3c]  ; =0x16003a7c
1600264c: str      r1, [r0]
16002650: ldr      r1, [pc, #0x38]  ; =0x16003a7c
16002654: str      r1, [r0, #4]
16002658: mov      r0, #0
1600265c: pop      {r4, pc}
16002660: ldr      r0, [pc, #0x2c]  ; =0x30000000
16002664: mov      r0, r0
16002668: ldr      r0, [pc, #0x28]  ; =0x30000027
1600266c: nop      
16002670: mov      r0, r0
16002674: ldr      r0, [pc, #0x20]  ; =0xd8e12c21
16002678: pop      {r4, pc}
1600267c: .word    0x16006a1c
16002680: andeq    r0, r0, r0
16002684: strne    r2, [r0], -r0, lsr #13
16002688: strne    r2, [r0], -r0, lsr #13
1600268c: .word    0x16003a7c
16002690: .word    0x16003a7c
16002694: andlo    r0, r0, r0
16002698: andlo    r0, r0, r7, lsr #32
1600269c: stmle    r1!, {r0, r5, sl, fp, sp} ^
