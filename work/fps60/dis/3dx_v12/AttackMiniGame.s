
<->_ZnwjP10MemAlcBasePKcj>  # veneer->_ZnwjP10MemAlcBasePKcj
10000180: ldr      pc, [pc, #-4]
10000184: eoreq    r7, r8, r0, asr #26

<->TaskMan::entry>  # veneer->_ZN7TaskMan5entryEP4Task
10000188: ldr      pc, [pc, #-4]
1000018c: eoreq    r7, r8, r8, lsl fp

<->MsgDataAcsrBase>  # veneer->_ZN15MsgDataAcsrBaseD1Ev
10000190: ldr      pc, [pc, #-4]
10000194: .word    0x0026fdb4

<->_ZdlPv>  # veneer->_ZdlPv
10000198: ldr      pc, [pc, #-4]
1000019c: eoreq    r6, r8, r4, lsl r5

<->nn::fs::detail::FileBase::TrySetPosition>  # veneer->_ZN2nn2fs6detail8FileBase14TrySetPositionEx
100001a0: ldr      pc, [pc, #-4]
100001a4: eoreq    lr, r7, r8, lsr #24

<->nn::err::CTR::ThrowFatalErrAll>  # veneer->_ZN2nn3err3CTR16ThrowFatalErrAllENS_6ResultEj
100001a8: ldr      pc, [pc, #-4]
100001ac: eoreq    r6, r8, r0, lsr r5

<->nn::fs::detail::FileBase::TryRead>  # veneer->_ZN2nn2fs6detail8FileBase7TryReadEPiPvj
100001b0: ldr      pc, [pc, #-4]
100001b4: eoreq    r6, r8, r8, lsl #9

<->nn::fs::detail::FileBase::TrySeek>  # veneer->_ZN2nn2fs6detail8FileBase7TrySeekExNS0_12PositionBaseE
100001b8: ldr      pc, [pc, #-4]
100001bc: .word    0x002854d0

<->nndbgPanic>  # veneer->nndbgPanic
100001c0: ldr      pc, [pc, #-4]
100001c4: eoreq    r6, r8, ip, lsr #8

<->nn::fs::CTR::MPCore::detail::UserFileSystem::CloseFile>  # veneer->_ZN2nn2fs3CTR6MPCore6detail14UserFileSystem9CloseFileEPv
100001c8: ldr      pc, [pc, #-4]
100001cc: eoreq    r6, r8, r0, lsl r4

<->ad::ui::UIListWindowPlusLyt>  # veneer->_ZN2ad2ui19UIListWindowPlusLytD1Ev
100001d0: ldr      pc, [pc, #-4]
100001d4: .word    0x0025a3fc

<->MoveVBase::update>  # veneer->_ZN9MoveVBase6updateEf
100001d8: ldr      pc, [pc, #-4]
100001dc: .word    0x002597d4

<->CtrBtn::get>  # veneer->_ZNK6CtrBtn3getEi
100001e0: ldr      pc, [pc, #-4]
100001e4: ldrshteq r2, [r6], -r0

<->Message::func>  # veneer->_ZN7Message4funcEjjjbf
100001e8: ldr      pc, [pc, #-4]
100001ec: eoreq    r3, r7, r0, ror #23

<->msys::MRenderQueueBase::enqueueMsg>  # veneer->_ZN4msys16MRenderQueueBase10enqueueMsgEP13MessageSimplejh
100001f0: ldr      pc, [pc, #-4]
100001f4: ldrshteq r8, [r2], -r0

<->msys::MListWndPBase>  # veneer->_ZN4msys13MListWndPBaseD1Ev
100001f8: ldr      pc, [pc, #-4]
100001fc: eorseq   r8, r2, r0, lsr #17

<->msys::MPageBase::enqueueLowerChr>  # veneer->_ZN4msys9MPageBase15enqueueLowerChrEPNS_12MRenderQueueE
10000200: ldr      pc, [pc, #-4]
10000204: eorseq   r4, r3, r4, lsl #2

<->msys::MPageBase::enqueueUpperChr>  # veneer->_ZN4msys9MPageBase15enqueueUpperChrEPNS_12MRenderQueueE
10000208: ldr      pc, [pc, #-4]
1000020c: eorseq   r4, r3, r4, lsl #3

<->__aeabi_vec_dtor>  # veneer->__aeabi_vec_dtor
10000210: ldr      pc, [pc, #-4]
10000214: eoreq    r8, r8, r1, lsr r2

<->MoveVBase>  # veneer->_ZN9MoveVBaseD1Ev
10000218: ldr      pc, [pc, #-4]
1000021c: eoreq    r3, r5, r8, ror #11

<->msys::MCamera::getProjMtx>  # veneer->_ZNK4msys7MCamera10getProjMtxERN2nn4math5MTX44Ej
10000220: ldr      pc, [pc, #-4]
10000224: eoreq    r6, r0, r8, lsl r7

<->msys::MCamera::getViewMtx>  # veneer->_ZNK4msys7MCamera10getViewMtxERN2nn4math5MTX34E
10000228: ldr      pc, [pc, #-4]
1000022c: eoreq    r6, r0, r4, ror #17

<->ad::fw::TaskBase::setULcdCameraInfoBase>  # veneer->_ZN2ad2fw8TaskBase21setULcdCameraInfoBaseERKN2nn4math5MTX34ERKNS3_5MTX44ENS3_14PivotDirectionE
10000230: ldr      pc, [pc, #-4]
10000234: andseq   fp, r0, r8, lsr r4

<->Grp::SetupProjLcdOrtho>  # veneer->_ZN3Grp17SetupProjLcdOrthoEPN2nn4math5MTX44Ejbbff
10000238: ldr      pc, [pc, #-4]
1000023c: eoreq    r4, r8, r0, asr #31

<->msys::MComSys::funcCalcMainNomal>  # veneer->_ZN4msys7MComSys17funcCalcMainNomalEv
10000240: ldr      pc, [pc, #-4]
10000244: eorseq   pc, r2, ip, lsr r1

<->msys::MComSys::funcDrawLower>  # veneer->_ZN4msys7MComSys13funcDrawLowerEP7CmdList
10000248: ldr      pc, [pc, #-4]
1000024c: ldrhteq  lr, [r2], -r8

<->msys::MComSys::funcDrawUpper>  # veneer->_ZN4msys7MComSys13funcDrawUpperEP7CmdList
10000250: ldr      pc, [pc, #-4]
10000254: eorseq   lr, r2, r0, ror #14

<->ad::lyt::LytDrawSys::GetInst>  # veneer->_ZN2ad3lyt10LytDrawSys7GetInstEv
10000258: ldr      pc, [pc, #-4]
1000025c: eoreq    r7, r8, r8, asr pc

<->ad::lyt::Initialize>  # veneer->_ZN2ad3lyt10InitializeEPN2nw2os10IAllocatorES4_
10000260: ldr      pc, [pc, #-4]
10000264: eoreq    r5, r8, r0, ror #11

<->msys::MComSys::readLytNum>  # veneer->_ZN4msys7MComSys10readLytNumEPN2ad2fw11FileContextEP10MemAlcBase
10000268: ldr      pc, [pc, #-4]
1000026c: eorseq   sp, r2, r4, lsl fp

<->ad::fw::TaskBase::readLyt>  # veneer->_ZN2ad2fw8TaskBase7readLytEPNS0_8ResourceEPNS0_11FileContextEPKcP10MemAlcBasejPNS0_11ResCacheArgE
10000270: ldr      pc, [pc, #-4]
10000274: eoreq    sb, r4, r8, asr #28

<->_ZnajP10MemAlcBasePKcj>  # veneer->_ZnajP10MemAlcBasePKcj
10000278: ldr      pc, [pc, #-4]
1000027c: eoreq    r3, r8, r8, asr r5

<->MessageSys::GetPath>  # veneer->_ZN10MessageSys7GetPathEPwPKwb
10000280: ldr      pc, [pc, #-4]
10000284: andseq   r2, r3, ip, lsr #20

<->nn::fs::CTR::MPCore::detail::UserFileSystem::TryOpenFile>  # veneer->_ZN2nn2fs3CTR6MPCore6detail14UserFileSystem11TryOpenFileEPPvPKwj
10000288: ldr      pc, [pc, #-4]
1000028c: eoreq    r5, r8, ip, lsl #19

<->nn::fs::detail::FileBase::TryGetSize>  # veneer->_ZNK2nn2fs6detail8FileBase10TryGetSizeEPx
10000290: ldr      pc, [pc, #-4]
10000294: eoreq    r6, r8, r8, ror #10

<->MsgDataAcsrBase::init>  # veneer->_ZN15MsgDataAcsrBase4initEPKv
10000298: ldr      pc, [pc, #-4]
1000029c: eoreq    r5, r8, r8, lsl #23

<->_ZdaPv>  # veneer->_ZdaPv
100002a0: ldr      pc, [pc, #-4]
100002a4: mlaeq    r8, ip, r2, r8

<->ad::lyt::LytResourceMan::init>  # veneer->_ZN2ad3lyt14LytResourceMan4initEv
100002a8: ldr      pc, [pc, #-4]
100002ac: eoreq    r0, r5, ip, lsl sp

<->ad::fw::Resource::getFileData>  # veneer->_ZN2ad2fw8Resource11getFileDataEv
100002b0: ldr      pc, [pc, #-4]
100002b4: eoreq    r1, r5, r0, lsl sp

<->ad::lyt::LytResourceMan::registerArc>  # veneer->_ZN2ad3lyt14LytResourceMan11registerArcEPvPKc
100002b8: ldr      pc, [pc, #-4]
100002bc: andseq   ip, r5, r0, lsl sb

<->msys::MLytNumRes::init>  # veneer->_ZN4msys10MLytNumRes4initERN2ad3lyt14LytResourceManEj
100002c0: ldr      pc, [pc, #-4]
100002c4: ldrshteq r4, [r2], -r4

<->msys::MLyt::init>  # veneer->_ZN4msys4MLyt4initEPN2ad3lyt11LytDrawDataEa
100002c8: ldr      pc, [pc, #-4]
100002cc: eorseq   ip, r2, r0, lsr #7

<->msys::MLyt::createLyt>  # veneer->_ZN4msys4MLyt9createLytEPN2ad3lyt14LytResourceManEPKc
100002d0: ldr      pc, [pc, #-4]
100002d4: eorseq   ip, r2, ip, lsl #15

<->MoveVBase::stop>  # veneer->_ZN9MoveVBase4stopEv
100002d8: ldr      pc, [pc, #-4]
100002dc: .word    0x00259dd8

<->MoveC::moveFrm>  # veneer->_ZN5MoveC7moveFrmERKN2nn4util6Color8Ef
100002e0: ldr      pc, [pc, #-4]
100002e4: eoreq    fp, r6, r4, ror ip

<->msys::MComSys::initBaseSys>  # veneer->_ZN4msys7MComSys11initBaseSysEPNS_9MTaskBaseEjjjjjjhb
100002e8: ldr      pc, [pc, #-4]
100002ec: eorseq   sp, r2, r4, lsl #23

<->msys::MComSys::entryPage>  # veneer->_ZN4msys7MComSys9entryPageEPNS_9MPageBaseE
100002f0: ldr      pc, [pc, #-4]
100002f4: eorseq   pc, r2, r8, asr #10

<->Prim::enableDepthTest>  # veneer->_ZN4Prim15enableDepthTestEb17PicaDataDepthTest
100002f8: ldr      pc, [pc, #-4]
100002fc: eoreq    ip, r6, r8, ror #25

<->CtrJobMan::enqueue>  # veneer->_ZN9CtrJobMan7enqueueEP3Job
10000300: ldr      pc, [pc, #-4]
10000304: eoreq    sp, r6, r8, ror #23

<->msys::MComSys::setupCamU>  # veneer->_ZN4msys7MComSys9setupCamUEv
10000308: ldr      pc, [pc, #-4]
1000030c: eorseq   pc, r2, r4, ror r6

<->msys::MComSys::setupCamL>  # veneer->_ZN4msys7MComSys9setupCamLEv
10000310: ldr      pc, [pc, #-4]
10000314: eorseq   pc, r2, r0, ror r5

<->msys::MComSys>  # veneer->_ZN4msys7MComSysC1Ev
10000318: ldr      pc, [pc, #-4]
1000031c: eorseq   pc, r2, r4, lsr #15

<->MsgDataAcsrBase>  # veneer->_ZN15MsgDataAcsrBaseC1EP12LMSBlockInfoj
10000320: ldr      pc, [pc, #-4]
10000324: .word    0x0024b3b8

<->ad::fw::Resource>  # veneer->_ZN2ad2fw8ResourceC1Ev
10000328: ldr      pc, [pc, #-4]
1000032c: eoreq    r0, r5, r8, lsl #11

<->__aeabi_vec_ctor_nocookie_nodtor>  # veneer->__aeabi_vec_ctor_nocookie_nodtor
10000330: ldr      pc, [pc, #-4]
10000334: eoreq    r7, r8, sp, lsl r7

<->msys::MLyt::build>  # veneer->_ZN4msys4MLyt5buildEP10MemAlcBasePKNS0_9AnimeNameEt
10000338: ldr      pc, [pc, #-4]
1000033c: eorseq   ip, r2, r0, ror #8

<->msys::MLyt::createLyt>  # veneer->_ZN4msys4MLyt9createLytEPN2ad3lyt14LytResourceManEPKcPNS1_4ctrl11ButtonGroupEPNS_11MCursorBaseE
10000340: ldr      pc, [pc, #-4]
10000344: eorseq   ip, r2, r0, asr #17

<->Backup::errorCode>  # veneer->_ZNK6Backup9errorCodeEv
10000348: ldr      pc, [pc, #-4]
1000034c: .word    0x002063b8

<->Backup::isBusyFormat>  # veneer->_ZN6Backup12isBusyFormatEv
10000350: ldr      pc, [pc, #-4]
10000354: eorseq   sb, r3, r8, ror r3

<->Backup::mount>  # veneer->_ZN6Backup5mountEv
10000358: ldr      pc, [pc, #-4]
1000035c: eorseq   sb, r3, ip, lsl #26

<->Backup::rewriteSaveData>  # veneer->_ZN6Backup15rewriteSaveDataEv
10000360: ldr      pc, [pc, #-4]
10000364: eorseq   sb, r3, ip, lsl #24

<->CtrFS::unmountSaveData>  # veneer->_ZN5CtrFS15unmountSaveDataEv
10000368: ldr      pc, [pc, #-4]
1000036c: eoreq    r7, r0, ip, lsr pc

<->Backup::format>  # veneer->_ZN6Backup6formatEv
10000370: ldr      pc, [pc, #-4]
10000374: eorseq   sb, r3, r4, lsr sp

<->GameMain::Back>  # veneer->_ZN8GameMain4BackEP12TaskMainBase
10000378: ldr      pc, [pc, #-4]
1000037c: eorseq   lr, r3, r4, asr r3

<->msys::MListWndPBase::isTpNeutral>  # veneer->_ZNK4msys13MListWndPBase11isTpNeutralEv
10000380: ldr      pc, [pc, #-4]
10000384: eorseq   r2, r6, r8, asr #1

<->msys::MListWndPBase::getCurNo>  # veneer->_ZNK4msys13MListWndPBase8getCurNoEv
10000388: ldr      pc, [pc, #-4]
1000038c: eorseq   r2, r6, r0, ror #1

<->ad::db::GetPcAttack>  # veneer->_ZN2ad2db11GetPcAttackEt
10000390: ldr      pc, [pc, #-4]
10000394: eoreq    r7, r3, r0, ror #4

<->msys::MListWndPBase::getCurItem>  # veneer->_ZNK4msys13MListWndPBase10getCurItemEv
10000398: ldr      pc, [pc, #-4]
1000039c: strhteq  sl, [r5], -ip

<->msys::MListWndPBase::getSelectItem>  # veneer->_ZN4msys13MListWndPBase13getSelectItemEv
100003a0: ldr      pc, [pc, #-4]
100003a4: ldrshteq r8, [r2], -r0

<->msys::MLyt::getAnim>  # veneer->_ZN4msys4MLyt7getAnimEs
100003a8: ldr      pc, [pc, #-4]
100003ac: eorseq   ip, r2, r8, ror r6

<->ad::lyt::LytAnim::stopAndSetFrm>  # veneer->_ZN2ad3lyt7LytAnim13stopAndSetFrmEf
100003b0: ldr      pc, [pc, #-4]
100003b4: eoreq    pc, r6, r4, asr #28

<->msys::MLyt::createAnime>  # veneer->_ZN4msys4MLyt11createAnimeEhPKcS2_ba
100003b8: ldr      pc, [pc, #-4]
100003bc: eoreq    r6, r0, r8, asr #24

<->msys::MLyt::createAnimeAutoSlot>  # veneer->_ZN4msys4MLyt19createAnimeAutoSlotEPKcS2_S2_
100003c0: ldr      pc, [pc, #-4]
100003c4: eorseq   ip, r2, r8, lsl #6

<->msys::MLyt::getAnime>  # veneer->_ZN4msys4MLyt8getAnimeEj
100003c8: ldr      pc, [pc, #-4]
100003cc: eorseq   ip, r2, r8, lsr r7

<->LMS_GetTextIndexByLabel>  # veneer->LMS_GetTextIndexByLabel
100003d0: ldr      pc, [pc, #-4]
100003d4: eoreq    r6, r7, ip, ror #2

<->LMS_GetText>  # veneer->LMS_GetText
100003d8: ldr      pc, [pc, #-4]
100003dc: eoreq    r6, r7, ip, lsl #12

<->msys::MMsg::playStr>  # veneer->_ZN4msys4MMsg7playStrEPKwPN13MessageSimple8InsParamEb
100003e0: ldr      pc, [pc, #-4]
100003e4: eorseq   ip, r2, ip, lsl #28

<->msys::MLyt::playAnimeFromNo>  # veneer->_ZN4msys4MLyt15playAnimeFromNoEjjPKcS2_
100003e8: ldr      pc, [pc, #-4]
100003ec: mlaseq   r2, r8, pc, fp

<->Backup::isBusyWriting>  # veneer->_ZN6Backup13isBusyWritingEv
100003f0: ldr      pc, [pc, #-4]
100003f4: eorseq   sb, r3, r8, asr r5

<->Backup::term>  # veneer->_ZN6Backup4termEv
100003f8: ldr      pc, [pc, #-4]
100003fc: eorseq   sb, r3, r4, lsl #25

<->Message::close>  # veneer->_ZN7Message5closeEv
10000400: ldr      pc, [pc, #-4]
10000404: eoreq    sp, r4, r8, asr #25

<->ad::lyt::LytLocalize>  # veneer->_ZN2ad3lyt11LytLocalizeC1Ev
10000408: ldr      pc, [pc, #-4]
1000040c: .word    0x002563d4

<->ad::lyt::LytLocalize::localize>  # veneer->_ZN2ad3lyt11LytLocalize8localizeEPNS0_6LayoutE
10000410: ldr      pc, [pc, #-4]
10000414: eoreq    r4, r6, r8, lsl #28

<->Message::init>  # veneer->_ZN7Message4initEv
10000418: ldr      pc, [pc, #-4]
1000041c: eorseq   sp, r3, ip, lsr #24

<->Message::setMsgDat>  # veneer->_ZN7Message9setMsgDatEPKv
10000420: ldr      pc, [pc, #-4]
10000424: eorseq   sp, r3, r8, asr #27

<->msys::MLyt::attachMChr>  # veneer->_ZN4msys4MLyt10attachMChrERNS_8MChrBaseEPKcS4_S4_S4_
10000428: ldr      pc, [pc, #-4]
1000042c: eoreq    r7, r0, r8, ror #8

<->MessageSimple::init>  # veneer->_ZN13MessageSimple4initEv
10000430: ldr      pc, [pc, #-4]
10000434: .word    0x002736b4

<->ad::ctrl::ButtonGroup::FindButtonByName>  # veneer->_ZN2ad4ctrl11ButtonGroup16FindButtonByNameEPKc
10000438: ldr      pc, [pc, #-4]
1000043c: eoreq    r6, r5, r0, lsl #13

<->ad::ctrl::AnimButton::SetStateChangeCallback>  # veneer->_ZN2ad4ctrl10AnimButton22SetStateChangeCallbackEPFvPS1_NS0_10ButtonBase5StateES4_PvES5_
10000440: ldr      pc, [pc, #-4]
10000444: eoreq    r6, r5, r4, ror r6

<->msys::MLyt::getParts>  # veneer->_ZN4msys4MLyt8getPartsEPKcS2_S2_
10000448: ldr      pc, [pc, #-4]
1000044c: eoreq    r7, r0, ip, ror #7

<->ad::fw::TaskBase::isFps30>  # veneer->_ZNK2ad2fw8TaskBase7isFps30Ev
10000450: ldr      pc, [pc, #-4]
10000454: .word    0x0025edd0

<->msys::MCursorBase::setVisible>  # veneer->_ZN4msys11MCursorBase10setVisibleEb
10000458: ldr      pc, [pc, #-4]
1000045c: eorseq   r4, r2, r4, asr r4

<->msys::MLyt::setAnimeInfo>  # veneer->_ZN4msys4MLyt12setAnimeInfoEjj
10000460: ldr      pc, [pc, #-4]
10000464: eorseq   fp, r2, r0, asr #24

<->ad::lyt::LytAnim::init>  # veneer->_ZN2ad3lyt7LytAnim4initEPNS0_6LayoutEPKcS5_
10000468: ldr      pc, [pc, #-4]
1000046c: eoreq    r4, r6, r4, lsl #30

<->ad::lyt::AnimTransform::GetFrameSize>  # veneer->_ZNK2ad3lyt13AnimTransform12GetFrameSizeEv
10000470: ldr      pc, [pc, #-4]
10000474: eoreq    pc, r6, r8, lsr lr

<->ad::lyt::LytAnim::term>  # veneer->_ZN2ad3lyt7LytAnim4termEb
10000478: ldr      pc, [pc, #-4]
1000047c: mlaeq    r6, r0, lr, r4

<->msys::MLyt::stopAnimeAndSetEnd>  # veneer->_ZN4msys4MLyt18stopAnimeAndSetEndEjjPKcS2_
10000480: ldr      pc, [pc, #-4]
10000484: eorseq   ip, r2, ip, ror r2

<->GameMain::GameModeOld>  # veneer->_ZN8GameMain11GameModeOldEv
10000488: ldr      pc, [pc, #-4]
1000048c: eorseq   lr, r3, r0, lsr #6

<->atk_mg::GetBootInfo>  # veneer->_ZN6atk_mg11GetBootInfoEv
10000490: ldr      pc, [pc, #-4]
10000494: eorseq   ip, r3, r4, asr #17

<->atk_mg::BootInfo::saveBgm>  # veneer->_ZN6atk_mg8BootInfo7saveBgmEv
10000498: ldr      pc, [pc, #-4]
1000049c: mlaseq   r3, r0, sl, ip

<->btl::GetBootInfo>  # veneer->_ZN3btl11GetBootInfoEv
100004a0: ldr      pc, [pc, #-4]
100004a4: .word    0x00217ff8

<->msys::MListWndPBase::getListWnd>  # veneer->_ZNK4msys13MListWndPBase10getListWndEv
100004a8: ldr      pc, [pc, #-4]
100004ac: eorseq   r2, r6, r0, asr #1

<->ad::lyt::LytNumReel3::InitParam>  # veneer->_ZN2ad3lyt11LytNumReel39InitParamC1Ev
100004b0: ldr      pc, [pc, #-4]
100004b4: mlaeq    r5, r4, r1, r6

<->msys::MLytNumRes::set>  # veneer->_ZN4msys10MLytNumRes3setERN2ad3lyt11LytNumReel39InitParamENS_11eLytNumTypeENS_7eLytNumES7_
100004b8: ldr      pc, [pc, #-4]
100004bc: mlaeq    r0, r4, r5, r7

<->msys::MLytNum::init>  # veneer->_ZN4msys7MLytNum4initERN2ad3lyt11LytNumReel39InitParamEPNS2_11LytDrawDataERNS_4MLytEPKcSB_SB_SB_
100004c0: ldr      pc, [pc, #-4]
100004c4: ldrhteq  r1, [r3], -r8

<->SndSys::start>  # veneer->_ZN6SndSys5startEjPN2nw3snd11SoundHandleE
100004c8: ldr      pc, [pc, #-4]
100004cc: eorseq   ip, r3, ip, ror r7

<->msys::MLyt::isEnableAnime>  # veneer->_ZN4msys4MLyt13isEnableAnimeEv
100004d0: ldr      pc, [pc, #-4]
100004d4: eorseq   fp, r2, ip, ror #24

<->msys::MDfxChr::term>  # veneer->_ZN4msys7MDfxChr4termEv
100004d8: ldr      pc, [pc, #-4]
100004dc: eorseq   r0, r3, r8, ror #24

<->msys::MLyt::detachMChr>  # veneer->_ZN4msys4MLyt10detachMChrERNS_8MChrBaseE
100004e0: ldr      pc, [pc, #-4]
100004e4: eorseq   fp, r2, r0, asr #17

<->Mem::Free>  # veneer->_ZN3Mem4FreeEPv
100004e8: ldr      pc, [pc, #-4]
100004ec: eoreq    r5, r8, ip, lsr sp

<->Backup::GetSaveData1>  # veneer->_ZN6Backup12GetSaveData1Es
100004f0: ldr      pc, [pc, #-4]
100004f4: eorseq   sb, r3, r4, lsl #5

<->Mem::Copy>  # veneer->_ZN3Mem4CopyEPvPKvj
100004f8: ldr      pc, [pc, #-4]
100004fc: eoreq    pc, r7, r8, lsl #26

<->Backup::init>  # veneer->_ZN6Backup4initEP5CtrFS
10000500: ldr      pc, [pc, #-4]
10000504: eorseq   sb, r3, r4, asr ip

<->Backup::writeSaveData0>  # veneer->_ZN6Backup14writeSaveData0Es
10000508: ldr      pc, [pc, #-4]
1000050c: eorseq   sb, r3, r0, lsr #21

<->msys::MCellAnime::init>  # veneer->_ZN4msys10MCellAnime4initEPKN2ad2fw8ResourceE
10000510: ldr      pc, [pc, #-4]
10000514: .word    0x002079d8

<->MessageWriter::setFontColor>  # veneer->_ZN13MessageWriter12setFontColorEjb
10000518: ldr      pc, [pc, #-4]
1000051c: eoreq    r0, r7, ip, lsl #30

<->SndSys::stopAllBgm>  # veneer->_ZN6SndSys10stopAllBgmEi
10000520: ldr      pc, [pc, #-4]
10000524: eorseq   ip, r3, r0, asr r4

<->atk_mg::BootInfo::restoreBgm>  # veneer->_ZN6atk_mg8BootInfo10restoreBgmEv
10000528: ldr      pc, [pc, #-4]
1000052c: eorseq   ip, r3, r0, lsl sb

<->msys::MLyt::isBusyTblAnime>  # veneer->_ZN4msys4MLyt14isBusyTblAnimeEi
10000530: ldr      pc, [pc, #-4]
10000534: mlaseq   r2, r4, sp, fp

<->msys::MDfxChr::init>  # veneer->_ZN4msys7MDfxChr4initEP10MemAlcBasePNS_7MDfxSysEPN2ad3h3d5SceneEj
10000538: ldr      pc, [pc, #-4]
1000053c: eorseq   r0, r3, r0, asr #19

<->msys::MDfxChr::playDfx>  # veneer->_ZN4msys7MDfxChr7playDfxEj
10000540: ldr      pc, [pc, #-4]
10000544: eorseq   r0, r3, r4, ror #26

<->__cxa_guard_acquire>  # veneer->__cxa_guard_acquire
10000548: ldr      pc, [pc, #-4]
1000054c: eoreq    r8, r8, r1, lsl r1

<->__cxa_guard_release>  # veneer->__cxa_guard_release
10000550: ldr      pc, [pc, #-4]
10000554: andseq   r1, r0, sb, lsr #17

<->ad::lyt::LytAnim::stop>  # veneer->_ZN2ad3lyt7LytAnim4stopEv
10000558: ldr      pc, [pc, #-4]
1000055c: eoreq    r1, r5, r8, ror r8

<->__c89vswprintf>  # veneer->__c89vswprintf
10000560: ldr      pc, [pc, #-4]
10000564: andseq   r0, r0, sp, asr r0

<->strcmp>  # veneer->strcmp
10000568: ldr      pc, [pc, #-4]
1000056c: .word    0x002833b8

<->msys::MCtrlUserData::findExtUserDataByName>  # veneer->_ZNK4msys13MCtrlUserData21findExtUserDataByNameEPKc
10000570: ldr      pc, [pc, #-4]
10000574: eorseq   r2, r6, ip, lsr r0

<->Message::play>  # veneer->_ZN7Message4playEPNS_9PlayParamE
10000578: ldr      pc, [pc, #-4]
1000057c: eoreq    sb, r5, r0, ror sb

<->ad::lyt::LytNumReel3::setValueInstant>  # veneer->_ZN2ad3lyt11LytNumReel315setValueInstantEi
10000580: ldr      pc, [pc, #-4]
10000584: eoreq    r7, r0, ip, asr r8

<->CellAnime::play>  # veneer->_ZN9CellAnime4playEhsf
10000588: ldr      pc, [pc, #-4]
1000058c: eoreq    fp, r7, r0, ror #29

<->ad::db::GetItemMsgAcs>  # veneer->_ZN2ad2db13GetItemMsgAcsEv
10000590: ldr      pc, [pc, #-4]
10000594: andseq   sl, r3, ip, lsl #6

<->MessageSimple::getLineWidth>  # veneer->_ZN13MessageSimple12getLineWidthEPKwPPwPbPfPPN2nw4font4FontE
10000598: ldr      pc, [pc, #-4]
1000059c: eoreq    r1, r7, r8, ror r3

<->msys::MListWndPBase::setEnableInput>  # veneer->_ZN4msys13MListWndPBase14setEnableInputEb
100005a0: ldr      pc, [pc, #-4]
100005a4: eorseq   r8, r2, r8, lsr r6

<->msys::MSndSe::play>  # veneer->_ZN4msys6MSndSe4playEjPKNS_8MChrBaseEPKN2nn4math4VEC2Eb
100005a8: ldr      pc, [pc, #-4]
100005ac: eorseq   sp, r2, r4, asr #16

<->ad::fw::TaskBase::term>  # veneer->_ZN2ad2fw8TaskBase4termEj
100005b0: ldr      pc, [pc, #-4]
100005b4: eoreq    sl, r4, r8, asr r3

<->msys::MLyt::term>  # veneer->_ZN4msys4MLyt4termEv
100005b8: ldr      pc, [pc, #-4]
100005bc: eorseq   ip, r2, r8, asr #7

<->ad::fw::Resource::term>  # veneer->_ZN2ad2fw8Resource4termEv
100005c0: ldr      pc, [pc, #-4]
100005c4: eoreq    r3, r3, r0, asr #6

<->ad::fw::Resource>  # veneer->_ZN2ad2fw8ResourceD1Ev
100005c8: ldr      pc, [pc, #-4]
100005cc: eoreq    sl, r4, r4, lsl #2

<->msys::MComSys>  # veneer->_ZN4msys7MComSysD1Ev
100005d0: ldr      pc, [pc, #-4]
100005d4: eorseq   r0, r3, r8, ror #1

<->MoveVBase>  # veneer->_ZN9MoveVBaseC1Ev
100005d8: ldr      pc, [pc, #-4]
100005dc: eoreq    sb, r5, r0, asr #14

<->msys::MLyt::getPane>  # veneer->_ZN4msys4MLyt7getPaneEPKcS2_S2_
100005e0: ldr      pc, [pc, #-4]
100005e4: eorseq   ip, r2, r8, lsl #13

<->__aeabi_uidivmod>  # veneer->__aeabi_uidivmod
100005e8: ldr      pc, [pc, #-4]
100005ec: eoreq    r1, r8, r8, lsr #12

<->atk_mg::BootInfo::playBgm>  # veneer->_ZN6atk_mg8BootInfo7playBgmEv
100005f0: ldr      pc, [pc, #-4]
100005f4: mlaseq   r3, r4, sb, ip

<->btl::BootInfo::setModePcAtkMiniGame>  # veneer->_ZN3btl8BootInfo20setModePcAtkMiniGameEt
100005f8: ldr      pc, [pc, #-4]
100005fc: eoreq    sp, sb, r0, asr #3

<->GameMain::Change>  # veneer->_ZN8GameMain6ChangeE9GAME_MODEP12TaskMainBase
10000600: ldr      pc, [pc, #-4]
10000604: ldrshteq lr, [r3], -ip

<->Message::term>  # veneer->_ZN7Message4termEv
10000608: ldr      pc, [pc, #-4]
1000060c: eorseq   sp, r3, r8, ror #24

<->Message>  # veneer->_ZN7MessageD1Ev
10000610: ldr      pc, [pc, #-4]
10000614: eoreq    r6, r0, r8, lsr r5

<->msys::MListWndPBase::applyAnime>  # veneer->_ZN4msys13MListWndPBase10applyAnimeEv
10000618: ldr      pc, [pc, #-4]
1000061c: eorseq   r8, r2, ip, asr #8

<->ad::lyt::Layout::Animate>  # veneer->_ZN2ad3lyt6Layout7AnimateEv
10000620: ldr      pc, [pc, #-4]
10000624: andseq   r1, r6, ip, ror #21

<->ad::lyt::LytResourceMan::buildLayout>  # veneer->_ZN2ad3lyt14LytResourceMan11buildLayoutERNS0_6LayoutEPKcPNS0_14ControlCreatorEPNS0_12TextSearcherE
10000628: ldr      pc, [pc, #-4]
1000062c: mlaeq    r5, r0, r4, r6

<->ad::lyt::LytAnim::playAuto>  # veneer->_ZN2ad3lyt7LytAnim8playAutoEf
10000630: ldr      pc, [pc, #-4]
10000634: eoreq    r6, r5, ip, lsl #4

<->ad::fw::Resource::getCA_anm>  # veneer->_ZNK2ad2fw8Resource9getCA_anmEv
10000638: ldr      pc, [pc, #-4]
1000063c: .word    0x0025abfc

<->ad::fw::Resource::getCA_tex>  # veneer->_ZNK2ad2fw8Resource9getCA_texEv
10000640: ldr      pc, [pc, #-4]
10000644: eoreq    sl, r5, r8, lsl #24

<->ad::fw::Resource::getCA_canm>  # veneer->_ZNK2ad2fw8Resource10getCA_canmEv
10000648: ldr      pc, [pc, #-4]
1000064c: eoreq    sl, r5, r4, lsl ip

<->CellAnime::init>  # veneer->_ZN9CellAnime4initEPKvS1_S1_hsf
10000650: ldr      pc, [pc, #-4]
10000654: eoreq    pc, r7, r8, lsr #20

<->ad::ui::UIListWindowPlusLyt::InitParam>  # veneer->_ZN2ad2ui19UIListWindowPlusLyt9InitParamC1Ev
10000658: ldr      pc, [pc, #-4]
1000065c: mulseq   r4, r8, r3

<->msys::SetMListWndInitParam>  # veneer->_ZN4msys20SetMListWndInitParamERN2ad2ui19UIListWindowPlusLyt9InitParamENS_13eMListWndTypeE
10000660: ldr      pc, [pc, #-4]
10000664: eorseq   sb, r2, r0, ror #28

<->msys::MListWndPBase::init>  # veneer->_ZN4msys13MListWndPBase4initERN2ad2ui19UIListWindowPlusLyt9InitParamEPNS1_3lyt11LytDrawDataEP4PrimP13MessageDrawerPNS1_17ApplyingSceneInfoE
10000668: ldr      pc, [pc, #-4]
1000066c: mlaseq   r2, r8, r6, r8

<->CellAnime>  # veneer->_ZN9CellAnimeD1Ev
10000670: ldr      pc, [pc, #-4]
10000674: mlaeq    r4, r4, ip, pc

<->ad::lyt::Layout>  # veneer->_ZN2ad3lyt6LayoutD1Ev
10000678: ldr      pc, [pc, #-4]
1000067c: eoreq    r2, r6, ip, ror #29

<->Mem::Fill>  # veneer->_ZN3Mem4FillEPvjj
10000680: ldr      pc, [pc, #-4]
10000684: eoreq    r4, r8, r8, ror #19

<->GameWork::addItem>  # veneer->_ZN8GameWork7addItemEta
10000688: ldr      pc, [pc, #-4]
1000068c: eorseq   lr, r3, r8, asr #27

<->GameWork::addCoin>  # veneer->_ZN8GameWork7addCoinEi
10000690: ldr      pc, [pc, #-4]
10000694: eoreq    lr, r2, r4, lsl #25

<->ad::TransMultiSymbol::init>  # veneer->_ZN2ad16TransMultiSymbol4initEPKc
10000698: ldr      pc, [pc, #-4]
1000069c: .word    0x0026d7f8

<->BinGlu4Acs::getEntryAcs>  # veneer->_ZNK10BinGlu4Acs11getEntryAcsEPKc
100006a0: ldr      pc, [pc, #-4]
100006a4: eoreq    r5, r8, r8, ror #4

<->ad::fw::TaskBase::readCA>  # veneer->_ZN2ad2fw8TaskBase6readCAEPNS0_8ResourceEPNS0_11FileContextEPKcS7_S7_S7_S7_P10MemAlcBasejP11VramAlcBasejPNS0_11ResCacheArgE
100006a8: ldr      pc, [pc, #-4]
100006ac: .word    0x0026daf8

<->Backup>  # veneer->_ZN6BackupC1Ev
100006b0: ldr      pc, [pc, #-4]
100006b4: andseq   r0, r1, r4, ror #24

<->ad::ctrl::ButtonGroup>  # veneer->_ZN2ad4ctrl11ButtonGroupC1Ev
100006b8: ldr      pc, [pc, #-4]
100006bc: ldrsbeq  r6, [r6], -r8

<->ad::font::ResFont>  # veneer->_ZN2ad4font7ResFontC1Ev
100006c0: ldr      pc, [pc, #-4]
100006c4: eoreq    r5, r7, ip, lsr #8

<->msys::MCursorBase>  # veneer->_ZN4msys11MCursorBaseC1Ev
100006c8: ldr      pc, [pc, #-4]
100006cc: eorseq   r4, r2, r0, asr r5

<->MessageSimple>  # veneer->_ZN13MessageSimpleC1Ev
100006d0: ldr      pc, [pc, #-4]
100006d4: eoreq    ip, r7, ip, ror #29

<->msys::MLytNum>  # veneer->_ZN4msys7MLytNumC1Ev
100006d8: ldr      pc, [pc, #-4]
100006dc: eorseq   r1, r3, r4, lsr #15

<->Message>  # veneer->_ZN7MessageC1Ev
100006e0: ldr      pc, [pc, #-4]
100006e4: andseq   r0, r1, ip, asr sp

<->msys::MListWndPBase>  # veneer->_ZN4msys13MListWndPBaseC1EPNS_13MListWndPCoreE
100006e8: ldr      pc, [pc, #-4]
100006ec: eorseq   r8, r2, r0, lsl #16

<->ad::ui::UIListWindowPlusLyt>  # veneer->_ZN2ad2ui19UIListWindowPlusLytC1Ev
100006f0: ldr      pc, [pc, #-4]
100006f4: andseq   r6, r4, r4, lsl #19

<->ad::lyt::Layout>  # veneer->_ZN2ad3lyt6LayoutC1Ev
100006f8: ldr      pc, [pc, #-4]
100006fc: eoreq    r4, r6, ip, asr #25

<->CellAnime>  # veneer->_ZN9CellAnimeC1Ev
10000700: ldr      pc, [pc, #-4]
10000704: eoreq    fp, r6, r8, lsl lr

<->msys::MCursorBase::term>  # veneer->_ZN4msys11MCursorBase4termEv
10000708: ldr      pc, [pc, #-4]
1000070c: ldrshteq r4, [r2], -r0

<->ad::ctrl::ButtonGroup::FreeAll>  # veneer->_ZN2ad4ctrl11ButtonGroup7FreeAllEv
10000710: ldr      pc, [pc, #-4]
10000714: .word    0x002509d0

<->ad::lyt::LytResourceMan::term>  # veneer->_ZN2ad3lyt14LytResourceMan4termEv
10000718: ldr      pc, [pc, #-4]
1000071c: eoreq    r0, r5, r8, lsr sb

<->MessageSimple::term>  # veneer->_ZN13MessageSimple4termEv
10000720: ldr      pc, [pc, #-4]
10000724: mulseq   r3, r0, r0

<->MessageSimple>  # veneer->_ZN13MessageSimpleD1Ev
10000728: ldr      pc, [pc, #-4]
1000072c: eoreq    r6, r5, r8, ror r5

<->msys::MLytNum>  # veneer->_ZN4msys7MLytNumD1Ev
10000730: ldr      pc, [pc, #-4]
10000734: eorseq   r1, r3, r0, asr #16

<->msys::MCursorBase>  # veneer->_ZN4msys11MCursorBaseD1Ev
10000738: ldr      pc, [pc, #-4]
1000073c: eorseq   r4, r2, r0, lsl #12

<->ad::font::ResFont>  # veneer->_ZN2ad4font7ResFontD1Ev
10000740: ldr      pc, [pc, #-4]
10000744: eoreq    r0, r5, r8, lsr #17

<->ad::ctrl::ButtonGroup>  # veneer->_ZN2ad4ctrl11ButtonGroupD1Ev
10000748: ldr      pc, [pc, #-4]
1000074c: eoreq    r0, r5, r8, lsr #18

<->Backup>  # veneer->_ZN6BackupD1Ev
10000750: ldr      pc, [pc, #-4]
10000754: eorseq   sb, r3, r4, lsr pc

<->msys::MPageBase::updateInputAllChr>  # veneer->_ZN4msys9MPageBase17updateInputAllChrEPNS_6MInputE
10000758: ldr      pc, [pc, #-4]
1000075c: eorseq   r4, r3, r4, lsl #4

<->ad::ctrl::ButtonGroup::Update>  # veneer->_ZN2ad4ctrl11ButtonGroup6UpdateEPKN2nn4math4VEC2Ebb
10000760: ldr      pc, [pc, #-4]
10000764: eoreq    r0, r5, r0, asr #20

<->msys::MTaskBase>  # veneer->_ZN4msys9MTaskBaseC1Ev
10000768: ldr      pc, [pc, #-4]
1000076c: eorseq   r4, r3, r8, lsl #13

<->ad::fw::TaskBase>  # veneer->_ZN2ad2fw8TaskBaseD1Ev
10000770: ldr      pc, [pc, #-4]
10000774: mlaeq    r6, r0, r5, sp

<->MoveWorkF>  # veneer->_ZN9MoveWorkFC1Ev
10000778: ldr      pc, [pc, #-4]
1000077c: eoreq    r8, r7, r0, asr #25

<->MoveWorkF>  # veneer->_ZN9MoveWorkFD1Ev
10000780: ldr      pc, [pc, #-4]
10000784: mlaseq   r4, r4, r6, r0

<->ad::fw::FileContext::initSingleFile>  # veneer->_ZN2ad2fw11FileContext14initSingleFileEPKwb
10000788: ldr      pc, [pc, #-4]
1000078c: andseq   sl, r3, r4, asr sp

<->ad::fw::FileContext::initArcFile>  # veneer->_ZN2ad2fw11FileContext11initArcFileEPKwP10MemAlcBaseb
10000790: ldr      pc, [pc, #-4]
10000794: andseq   sl, r3, r8, lsr #25

<->ad::fw::FileContext::initCAArcFile>  # veneer->_ZN2ad2fw11FileContext13initCAArcFileEPKwP10MemAlcBaseRNS0_15DataAndSizeTmplIPvEEb
10000798: ldr      pc, [pc, #-4]
1000079c: andseq   sl, r3, r0, asr #25

<->msys::MCursorBase::init>  # veneer->_ZN4msys11MCursorBase4initEPNS_4MLytEf
100007a0: ldr      pc, [pc, #-4]
100007a4: eorseq   r4, r2, r4, ror #8

<AttackMiniGame:EntryTask>  # AttackMiniGame:EntryTask
100007a8: ldr      r0, [pc, #0x2c]  ; =0x3f638c gMemAlc
100007ac: push     {r4, lr}
100007b0: mov      r3, #0
100007b4: mov      r2, r3
100007b8: ldr      r1, [r0]
100007bc: ldr      r0, [pc, #0x1c]  ; =0xe9a50
100007c0: bl       #0x10000180  ; ->_ZnwjP10MemAlcBasePKcj
100007c4: cmp      r0, #0
100007c8: blne     #0x10007814
100007cc: mov      r1, r0
100007d0: ldr      r0, [pc, #0xc]  ; =0x3f4130 gTaskMainMan
100007d4: pop      {r4, lr}
100007d8: b        #0x10000188  ; ->TaskMan::entry
100007dc: eorseq   r6, pc, ip, lsl #7
100007e0: andeq    sb, lr, r0, asr sl
100007e4: eorseq   r4, pc, r0, lsr r1
100007e8: push     {r4, lr}
100007ec: bl       #0x10000190  ; ->MsgDataAcsrBase
100007f0: pop      {r4, lr}
100007f4: b        #0x10000198  ; ->_ZdlPv
100007f8: b        #0x10000190  ; ->MsgDataAcsrBase
100007fc: ldr      r1, [r0]
10000800: ldr      r1, [r1, #0x14]
10000804: bx       r1
10000808: bx       lr
1000080c: ldr      r0, [pc]
10000810: bx       lr
10000814: ldrdeq   r4, r5, [r2], #-0xf4
10000818: bx       lr
1000081c: bx       lr
10000820: bx       lr
10000824: bx       lr
10000828: bx       lr
1000082c: bx       lr
10000830: push     {r3, lr}
10000834: ldr      r3, [r2, #8]
10000838: str      r3, [sp]
1000083c: ldr      ip, [r0]
10000840: ldrd     r2, r3, [r2]
10000844: ldr      ip, [ip, #0x18]
10000848: blx      ip
1000084c: pop      {r3, pc}
10000850: vldr     s0, [pc, #4]
10000854: vstr     s0, [r0, #0xc]
10000858: bx       lr
1000085c: andeq    r0, r0, r0
10000860: b        #0x10000198  ; ->_ZdlPv
10000864: bx       lr
10000868: add      r0, r0, #4
1000086c: push     {r4, lr}
10000870: bl       #0x100001a0  ; ->nn::fs::detail::FileBase::TrySetPosition
10000874: mov      r1, pc
10000878: lsrs     r2, r0, #0x1f
1000087c: beq      #0x10000888
10000880: pop      {r4, lr}
10000884: b        #0x100001a8  ; ->nn::err::CTR::ThrowFatalErrAll
10000888: pop      {r4, pc}
1000088c: add      r0, r0, #4
10000890: b        #0x100001a0  ; ->nn::fs::detail::FileBase::TrySetPosition
10000894: push     {r3, lr}
10000898: mov      r3, r2
1000089c: mov      r2, r1
100008a0: mov      r1, sp
100008a4: add      r0, r0, #4
100008a8: bl       #0x100001b0  ; ->nn::fs::detail::FileBase::TryRead
100008ac: mov      r1, pc
100008b0: lsrs     r2, r0, #0x1f
100008b4: blne     #0x100001a8  ; ->nn::err::CTR::ThrowFatalErrAll
100008b8: ldr      r0, [sp]
100008bc: pop      {r3, pc}
100008c0: push     {r3, lr}
100008c4: add      r0, r0, #4
100008c8: ldr      r1, [sp, #8]
100008cc: str      r1, [sp]
100008d0: bl       #0x100001b8  ; ->nn::fs::detail::FileBase::TrySeek
100008d4: mov      r1, pc
100008d8: lsrs     r2, r0, #0x1f
100008dc: beq      #0x100008e8
100008e0: pop      {r3, lr}
100008e4: b        #0x100001a8  ; ->nn::err::CTR::ThrowFatalErrAll
100008e8: pop      {r3, pc}
100008ec: add      r0, r0, #4
100008f0: b        #0x100001b0  ; ->nn::fs::detail::FileBase::TryRead
100008f4: push     {r3, lr}
100008f8: add      r0, r0, #4
100008fc: ldr      r1, [sp, #8]
10000900: str      r1, [sp]
10000904: bl       #0x100001b8  ; ->nn::fs::detail::FileBase::TrySeek
10000908: pop      {r3, pc}
1000090c: push     {r4, r5, r6, lr}
10000910: mov      r4, r0
10000914: add      r5, r0, #4
10000918: ldr      r0, [r0, #4]
1000091c: bics     r1, r0, #1
10000920: beq      #0x10000940
10000924: tst      r0, #1
10000928: blne     #0x100001c0  ; ->nndbgPanic
1000092c: ldr      r0, [r5]
10000930: bic      r0, r0, #1
10000934: bl       #0x100001c8  ; ->nn::fs::CTR::MPCore::detail::UserFileSystem::CloseFile
10000938: mov      r0, #0
1000093c: str      r0, [r5]
10000940: mov      r0, r4
10000944: pop      {r4, r5, r6, lr}
10000948: b        #0x10000198  ; ->_ZdlPv
1000094c: push     {r4, r5, r6, lr}
10000950: mov      r4, r0
10000954: add      r5, r0, #4
10000958: ldr      r0, [r0, #4]
1000095c: bics     r1, r0, #1
10000960: beq      #0x10000980
10000964: tst      r0, #1
10000968: blne     #0x100001c0  ; ->nndbgPanic
1000096c: ldr      r0, [r5]
10000970: bic      r0, r0, #1
10000974: bl       #0x100001c8  ; ->nn::fs::CTR::MPCore::detail::UserFileSystem::CloseFile
10000978: mov      r0, #0
1000097c: str      r0, [r5]
10000980: mov      r0, r4
10000984: pop      {r4, r5, r6, pc}
10000988: vldr     s1, [pc, #0x24]  ; =0x3f800000 (1)
1000098c: mov      r2, #1
10000990: vstr     s1, [r0, #4]
10000994: vldr     s0, [pc, #0x14]  ; =0x0 (0)
10000998: mov      r1, #0
1000099c: strh     r2, [r0, #0xc]
100009a0: strh     r1, [r0, #0xe]
100009a4: vstr     s0, [r0]
100009a8: vstr     s0, [r0, #8]
100009ac: bx       lr
100009b0: andeq    r0, r0, r0
100009b4: svclo    #0x800000
100009b8: vldr     s0, [pc, #4]
100009bc: vstr     s0, [r0, #8]
100009c0: bx       lr
100009c4: andeq    r0, r0, r0
100009c8: ldr      r1, [r0]
100009cc: ldr      r1, [r1, #8]
100009d0: bx       r1
100009d4: mov      r1, #0
100009d8: strb     r1, [r0, #0x142]
100009dc: bx       lr
100009e0: bx       lr
100009e4: mov      r1, #1
100009e8: strb     r1, [r0, #0x142]
100009ec: bx       lr
100009f0: bx       lr
100009f4: ldr      r1, [pc, #8]
100009f8: push     {r4, lr}
100009fc: bl       #0x10004240
10000a00: pop      {r4, pc}
10000a04: andseq   r0, r1, r5, lsl r0
10000a08: ldr      r1, [pc, #8]
10000a0c: push     {r4, lr}
10000a10: bl       #0x10004240
10000a14: pop      {r4, pc}
10000a18: andseq   r0, r1, r5, lsl r0
10000a1c: ldr      r1, [pc, #8]
10000a20: push     {r4, lr}
10000a24: bl       #0x10004240
10000a28: pop      {r4, pc}
10000a2c: andseq   r0, r1, r5, lsl r0
10000a30: ldr      r1, [pc, #8]
10000a34: push     {r4, lr}
10000a38: bl       #0x10004240
10000a3c: pop      {r4, pc}
10000a40: andseq   r0, r1, r5, lsl r0
10000a44: ldr      r1, [pc, #8]
10000a48: push     {r4, lr}
10000a4c: bl       #0x10004240
10000a50: pop      {r4, pc}
10000a54: andseq   r0, r1, r8, lsl r0
10000a58: push     {r4, lr}
10000a5c: bl       #0x100001d0  ; ->ad::ui::UIListWindowPlusLyt
10000a60: pop      {r4, lr}
10000a64: b        #0x10000198  ; ->_ZdlPv
10000a68: b        #0x100001d0  ; ->ad::ui::UIListWindowPlusLyt
10000a6c: mov      r0, #0
10000a70: bx       lr
10000a74: mov      r0, #0
10000a78: bx       lr
10000a7c: push     {r4, r5, r6, r7, lr}
10000a80: mov      r4, r0
10000a84: vpush    {d8}
10000a88: vmov.f32 s16, s0
10000a8c: ldr      r0, [r0]
10000a90: sub      sp, sp, #4
10000a94: ldr      r1, [r0, #0x24]
10000a98: mov      r0, r4
10000a9c: blx      r1
10000aa0: cmp      r0, #0
10000aa4: beq      #0x10000acc
10000aa8: vmov.f32 s0, s16
10000aac: add      r0, r4, #0x14
10000ab0: bl       #0x100001d8  ; ->MoveVBase::update
10000ab4: vmov.f32 s0, s16
10000ab8: add      r0, r4, #0x70
10000abc: bl       #0x100001d8  ; ->MoveVBase::update
10000ac0: vmov.f32 s0, s16
10000ac4: add      r0, r4, #0xcc
10000ac8: bl       #0x100001d8  ; ->MoveVBase::update
10000acc: ldr      r0, [pc, #0x78]  ; =0x4238d0 gBtn
10000ad0: mov      r1, #0
10000ad4: bl       #0x100001e0  ; ->CtrBtn::get
10000ad8: ldr      r7, [pc, #0x70]  ; =0xff2004
10000adc: mov      r1, #2
10000ae0: bic      r6, r0, r7
10000ae4: ldr      r0, [pc, #0x60]  ; =0x4238d0 gBtn
10000ae8: bl       #0x100001e0  ; ->CtrBtn::get
10000aec: bic      r5, r0, r7
10000af0: ldr      r0, [pc, #0x54]  ; =0x4238d0 gBtn
10000af4: mov      r1, #4
10000af8: bl       #0x100001e0  ; ->CtrBtn::get
10000afc: mov      r1, r0
10000b00: mov      r0, #0x140
10000b04: bic      r3, r1, r7
10000b08: ldrsb    r0, [r0, r4]
10000b0c: cmp      r0, #0
10000b10: bne      #0x10000b20
10000b14: mov      r3, #0
10000b18: mov      r5, r3
10000b1c: mov      r6, r3
10000b20: vmov.f32 s0, s16
10000b24: str      r0, [sp]
10000b28: mov      r2, r5
10000b2c: mov      r1, r6
10000b30: add      r0, r4, #0x14c
10000b34: bl       #0x100001e8  ; ->Message::func
10000b38: mov      r0, #1
10000b3c: strb     r0, [r4, #0x142]
10000b40: add      sp, sp, #4
10000b44: vpop     {d8}
10000b48: pop      {r4, r5, r6, r7, pc}
10000b4c: ldrdeq   r3, r4, [r2], #-0x80
10000b50: rscseq   r2, pc, r4
10000b54: bx       lr
10000b58: ldrb     r2, [r0, #0x141]
10000b5c: mov      ip, r1
10000b60: cmp      r2, #0
10000b64: beq      #0x10000b80
10000b68: ldr      r2, [pc, #0x14]  ; =0x6ef4
10000b6c: add      r1, r0, #0x14c
10000b70: mov      r3, #0xa
10000b74: ldr      r2, [r2, r0]
10000b78: mov      r0, ip
10000b7c: b        #0x100001f0  ; ->msys::MRenderQueueBase::enqueueMsg
10000b80: bx       lr
10000b84: strdeq   r6, r7, [r0], -r4
10000b88: push     {r4, lr}
10000b8c: bl       #0x100040e4
10000b90: pop      {r4, lr}
10000b94: b        #0x10000198  ; ->_ZdlPv
10000b98: ldr      r1, [pc, #0x18]  ; =0x100088d8
10000b9c: push     {r4, lr}
10000ba0: str      r1, [r0], #0x1fc
10000ba4: bl       #0x100001d0  ; ->ad::ui::UIListWindowPlusLyt
10000ba8: sub      r0, r0, #0x1fc
10000bac: bl       #0x100001f8  ; ->msys::MListWndPBase
10000bb0: pop      {r4, lr}
10000bb4: b        #0x10000198  ; ->_ZdlPv
10000bb8: ldrdne   r8, sb, [r0], -r8
10000bbc: ldr      r1, [pc, #0x14]  ; =0x100088d8
10000bc0: push     {r4, lr}
10000bc4: str      r1, [r0], #0x1fc
10000bc8: bl       #0x100001d0  ; ->ad::ui::UIListWindowPlusLyt
10000bcc: pop      {r4, lr}
10000bd0: sub      r0, r0, #0x1fc
10000bd4: b        #0x100001f8  ; ->msys::MListWndPBase
10000bd8: ldrdne   r8, sb, [r0], -r8
10000bdc: mov      r1, r2
10000be0: b        #0x10000200  ; ->msys::MPageBase::enqueueLowerChr
10000be4: mov      r1, r2
10000be8: b        #0x10000208  ; ->msys::MPageBase::enqueueUpperChr
10000bec: push     {r4, lr}
10000bf0: mov      r4, r0
10000bf4: ldr      r0, [pc, #0x24]  ; =0x10008778
10000bf8: ldr      r1, [pc, #0x24]  ; =0x100078e0
10000bfc: mov      r3, #1
10000c00: str      r0, [r4]
10000c04: mov      r2, #0x2c
10000c08: add      r0, r4, #0x30
10000c0c: bl       #0x10000210  ; ->__aeabi_vec_dtor
10000c10: mov      r0, r4
10000c14: bl       #0x10000218  ; ->MoveVBase
10000c18: pop      {r4, lr}
10000c1c: b        #0x10000198  ; ->_ZdlPv
10000c20: andne    r8, r0, r8, ror r7
10000c24: andne    r7, r0, r0, ror #17
10000c28: push     {r4, lr}
10000c2c: mov      r4, r0
10000c30: ldr      r0, [pc, #0x20]  ; =0x10008778
10000c34: ldr      r1, [pc, #0x20]  ; =0x100078e0
10000c38: mov      r3, #1
10000c3c: str      r0, [r4]
10000c40: mov      r2, #0x2c
10000c44: add      r0, r4, #0x30
10000c48: bl       #0x10000210  ; ->__aeabi_vec_dtor
10000c4c: mov      r0, r4
10000c50: pop      {r4, lr}
10000c54: b        #0x10000218  ; ->MoveVBase
10000c58: andne    r8, r0, r8, ror r7
10000c5c: andne    r7, r0, r0, ror #17
10000c60: push     {r4, r5, lr}
10000c64: mov      r5, r0
10000c68: ldr      r0, [pc, #0x60]  ; =0x4ad54
10000c6c: sub      sp, sp, #0x74
10000c70: mov      r2, #0x400
10000c74: add      r0, r0, r5
10000c78: mov      r1, sp
10000c7c: mov      r4, r0
10000c80: bl       #0x10000220  ; ->msys::MCamera::getProjMtx
10000c84: add      r1, sp, #0x40
10000c88: mov      r0, r4
10000c8c: bl       #0x10000228  ; ->msys::MCamera::getViewMtx
10000c90: ldr      r0, [r5, #4]
10000c94: mov      r3, #1
10000c98: mov      r2, sp
10000c9c: add      r1, sp, #0x40
10000ca0: bl       #0x10000230  ; ->ad::fw::TaskBase::setULcdCameraInfoBase
10000ca4: add      r4, r4, #0x20
10000ca8: mov      r3, #1
10000cac: vldmia   r4, {s0, s1}
10000cb0: mov      r2, #0
10000cb4: mov      r1, #0x400
10000cb8: mov      r0, sp
10000cbc: bl       #0x10000238  ; ->Grp::SetupProjLcdOrtho
10000cc0: mov      r0, r5
10000cc4: bl       #0x10000240  ; ->msys::MComSys::funcCalcMainNomal
10000cc8: add      sp, sp, #0x74
10000ccc: pop      {r4, r5, pc}
10000cd0: andeq    sl, r4, r4, asr sp
10000cd4: push     {r4, r5, lr}
10000cd8: mov      r4, r0
10000cdc: ldr      r0, [pc, #0x2c]  ; =0x4ae34
10000ce0: sub      sp, sp, #0x44
10000ce4: mov      r5, r1
10000ce8: ldr      r2, [pc, #0x1c]  ; =0x401
10000cec: mov      r1, sp
10000cf0: add      r0, r0, r4
10000cf4: bl       #0x10000220  ; ->msys::MCamera::getProjMtx
10000cf8: mov      r1, r5
10000cfc: mov      r0, r4
10000d00: bl       #0x10000248  ; ->msys::MComSys::funcDrawLower
10000d04: add      sp, sp, #0x44
10000d08: pop      {r4, r5, pc}
10000d0c: andeq    r0, r0, r1, lsl #8
10000d10: andeq    sl, r4, r4, lsr lr
10000d14: b        #0x10000250  ; ->msys::MComSys::funcDrawUpper
10000d18: push     {r4, r5, r6, r7, r8, lr}
10000d1c: mov      r4, r0
10000d20: sub      sp, sp, #0x20
10000d24: ldr      r3, [r0, #0x278]
10000d28: mov      r2, #3
10000d2c: add      r1, r3, #0x1f8
10000d30: mov      r0, r3
10000d34: cmp      r0, r1
10000d38: ldrbne   ip, [r0, #4]
10000d3c: cmpne    ip, #0
10000d40: addne    r0, r0, #0xa8
10000d44: bne      #0x10000d34
10000d48: rsb      r1, r2, r2, lsl #3
10000d4c: mov      r6, #0
10000d50: add      r1, r1, r1, lsl #1
10000d54: add      r1, r3, r1, lsl #3
10000d58: cmp      r0, r1
10000d5c: bne      #0x10000f68
10000d60: bl       #0x10000258  ; ->ad::lyt::LytDrawSys::GetInst
10000d64: mov      r7, r0
10000d68: ldr      r0, [pc, #0x200]  ; =0x3f634c ad::lyt::Layout::s_pAllocator
10000d6c: add      r5, r4, #0xc
10000d70: ldr      r1, [r0]
10000d74: add      r0, r7, #0x400
10000d78: add      r0, r0, #0x1f4
10000d7c: cmp      r1, r0
10000d80: movne    r1, r0
10000d84: blne     #0x10000260  ; ->ad::lyt::Initialize
10000d88: str      r5, [r7, #0x5f8]
10000d8c: nop      
10000d90: bl       #0x10000258  ; ->ad::lyt::LytDrawSys::GetInst
10000d94: mov      r1, r0
10000d98: mov      r0, #0x10000
10000d9c: str      r0, [r1, #0x5fc]
10000da0: ldr      r0, [pc, #0x1cc]  ; =0xe64f0
10000da4: add      r1, pc, #0x1cc
10000da8: ldr      r0, [r0, r4]
10000dac: ldr      r0, [r0, #0x44]
10000db0: ldr      r2, [r0]
10000db4: ldr      r2, [r2, #0xc]
10000db8: blx      r2
10000dbc: ldr      r0, [r4, #0x278]
10000dc0: mov      r2, #0
10000dc4: add      r1, r0, #0x150
10000dc8: mov      r0, r4
10000dcc: bl       #0x10000268  ; ->msys::MComSys::readLytNum
10000dd0: ldr      r0, [r4, #4]
10000dd4: add      r2, r4, #0xc
10000dd8: add      r3, sp, #4
10000ddc: mov      r1, #0x7f
10000de0: str      r2, [sp]
10000de4: stm      r3, {r1, r6}
10000de8: add      r3, pc, #0x198
10000dec: ldr      r1, [r4, #0x278]
10000df0: add      r2, r1, #0x150
10000df4: add      r1, r4, #0xe9000
10000df8: add      r1, r1, #0xe0
10000dfc: bl       #0x10000270  ; ->ad::fw::TaskBase::readLyt
10000e00: mov      r3, #0x800000
10000e04: mov      r2, #0
10000e08: add      r1, r4, #0xc
10000e0c: mov      r0, #0x200
10000e10: bl       #0x10000278  ; ->_ZnajP10MemAlcBasePKcj
10000e14: mov      r5, r0
10000e18: mov      r2, #0
10000e1c: add      r1, pc, #0x174
10000e20: bl       #0x10000280  ; ->MessageSys::GetPath
10000e24: ldr      r8, [pc, #0x180]  ; =0x100087b0
10000e28: mov      r7, sp
10000e2c: add      r0, sp, #4
10000e30: ldr      r1, [r8, #4]
10000e34: mov      r2, r1
10000e38: str      r1, [sp]
10000e3c: ldr      r2, [r2, #-0x30]
10000e40: ldr      r1, [r8, #8]
10000e44: str      r1, [sp, r2]
10000e48: mov      r2, #1
10000e4c: mov      r1, r5
10000e50: str      r6, [sp, #4]
10000e54: str      r6, [sp, #0x10]
10000e58: str      r6, [sp, #0x14]
10000e5c: str      r6, [sp, #8]
10000e60: str      r6, [sp, #0xc]
10000e64: bl       #0x10000288  ; ->nn::fs::CTR::MPCore::detail::UserFileSystem::TryOpenFile
10000e68: tst      r0, #0x80000000
10000e6c: movne    r1, pc
10000e70: lsrsne   r2, r0, #0x1f
10000e74: blne     #0x100001a8  ; ->nn::err::CTR::ThrowFatalErrAll
10000e78: ldr      r0, [r8]
10000e7c: mov      r1, r0
10000e80: str      r0, [sp]
10000e84: ldr      r1, [r1, #-0x30]
10000e88: ldr      r0, [r8, #0xc]
10000e8c: str      r0, [r7, r1]
10000e90: add      r1, sp, #0x18
10000e94: add      r0, sp, #4
10000e98: bl       #0x10000290  ; ->nn::fs::detail::FileBase::TryGetSize
10000e9c: mov      r1, pc
10000ea0: lsrs     r2, r0, #0x1f
10000ea4: blne     #0x100001a8  ; ->nn::err::CTR::ThrowFatalErrAll
10000ea8: ldr      r2, [r4, #0xc]
10000eac: ldr      r7, [sp, #0x18]
10000eb0: add      r0, r4, #0xc
10000eb4: ldr      r3, [r2, #0xc]
10000eb8: mov      r1, r7
10000ebc: mov      r2, #0
10000ec0: blx      r3
10000ec4: add      r8, r4, #0xe9000
10000ec8: mov      r2, r0
10000ecc: str      r0, [r8, #0x4c]
10000ed0: mov      r3, r7
10000ed4: add      r0, sp, #4
10000ed8: add      r1, sp, #0x18
10000edc: bl       #0x100001b0  ; ->nn::fs::detail::FileBase::TryRead
10000ee0: mov      r1, pc
10000ee4: lsrs     r2, r0, #0x1f
10000ee8: blne     #0x100001a8  ; ->nn::err::CTR::ThrowFatalErrAll
10000eec: add      r0, r4, #0xe9000
10000ef0: ldr      r1, [r8, #0x4c]
10000ef4: add      r0, r0, #0x50
10000ef8: bl       #0x10000298  ; ->MsgDataAcsrBase::init
10000efc: ldr      r0, [sp, #4]
10000f00: bics     r0, r0, #1
10000f04: beq      #0x10000f24
10000f08: ldr      r0, [sp, #4]
10000f0c: tst      r0, #1
10000f10: blne     #0x100001c0  ; ->nndbgPanic
10000f14: ldr      r0, [sp, #4]
10000f18: bic      r0, r0, #1
10000f1c: bl       #0x100001c8  ; ->nn::fs::CTR::MPCore::detail::UserFileSystem::CloseFile
10000f20: str      r6, [sp, #4]
10000f24: ldr      r0, [sp, #4]
10000f28: bics     r0, r0, #1
10000f2c: beq      #0x10000f4c
10000f30: ldr      r0, [sp, #4]
10000f34: tst      r0, #1
10000f38: blne     #0x100001c0  ; ->nndbgPanic
10000f3c: ldr      r0, [sp, #4]
10000f40: bic      r0, r0, #1
10000f44: bl       #0x100001c8  ; ->nn::fs::CTR::MPCore::detail::UserFileSystem::CloseFile
10000f48: str      r6, [sp, #4]
10000f4c: mov      r0, r5
10000f50: bl       #0x100002a0  ; ->_ZdaPv
10000f54: ldr      r1, [pc, #0x54]  ; =0x10008000
10000f58: add      r4, r4, #0xc00
10000f5c: add      r4, r4, #0x384
10000f60: ldrd     r0, r1, [r1, #0xc]
10000f64: stm      r4, {r0, r1}
10000f68: add      sp, sp, #0x20
10000f6c: pop      {r4, r5, r6, r7, r8, pc}
10000f70: eorseq   r6, pc, ip, asr #6
10000f74: strdeq   r6, r7, [lr], -r0
10000f78: stmdapl  r6, {r0, r2, r3, r6, sl, lr} ^
10000f7c: strbvc   r6, [lr, #-0x54d]!
10000f80: stmdavs  r3!, {r0, r6, sb, ip, sp, lr} ^
10000f84: rsbeq    r7, r5, sb, ror #12
10000f88: cmpmi    pc, #0xc0000014
10000f8c: svcmi    #0x535255
10000f90: ldrbmi   r5, [r3, #-0xf52]
10000f94: andeq    r0, r0, r4, asr r0
10000f98: rsbeq    r0, r5, sp, asr #32
10000f9c: rsbseq   r0, r5, lr, rrx
10000fa0: rsbeq    r0, sp, lr, lsr #32
10000fa4: rsbeq    r0, r2, r3, ror r0
10000fa8: andeq    r0, r0, r4, ror r0
10000fac: strhne   r8, [r0], -r0
10000fb0: andne    r8, r0, r0
10000fb4: push     {r4, r5, r6, lr}
10000fb8: mov      r4, r0
10000fbc: add      r5, r0, #0x800
10000fc0: vpush    {d8}
10000fc4: add      r5, r5, #0x44
10000fc8: ldrb     r0, [r0, #0x848]
10000fcc: cmp      r0, #0
10000fd0: beq      #0x100010f8
10000fd4: ldr      r0, [pc, #0x124]  ; =0xe64f0
10000fd8: ldr      r0, [r0, r4]
10000fdc: ldr      r0, [r0, #0x44]
10000fe0: ldr      r1, [r0]
10000fe4: ldr      r1, [r1, #0x10]
10000fe8: blx      r1
10000fec: cmp      r0, #0
10000ff0: bne      #0x100010f8
10000ff4: add      r0, r4, #0x7d0
10000ff8: bl       #0x100002a8  ; ->ad::lyt::LytResourceMan::init
10000ffc: mov      r0, r5
10001000: bl       #0x100002b0  ; ->ad::fw::Resource::getFileData
10001004: mov      r1, r0
10001008: ldr      r2, [pc, #0xf4]  ; =0x10008a88
1000100c: add      r0, r4, #0x7d0
10001010: bl       #0x100002b8  ; ->ad::lyt::LytResourceMan::registerArc
10001014: add      r0, r4, #0xe9000
10001018: add      r0, r0, #0xe0
1000101c: bl       #0x100002b0  ; ->ad::fw::Resource::getFileData
10001020: mov      r1, r0
10001024: add      r2, pc, #0xdc
10001028: add      r0, r4, #0x7d0
1000102c: bl       #0x100002b8  ; ->ad::lyt::LytResourceMan::registerArc
10001030: mov      r2, #6
10001034: add      r1, r4, #0x7d0
10001038: mov      r0, r5
1000103c: bl       #0x100002c0  ; ->msys::MLytNumRes::init
10001040: add      r0, r4, #0xe9000
10001044: add      r0, r0, #0x124
10001048: add      r1, r4, #0xd3000
1000104c: mov      r2, #0
10001050: mov      r5, r0
10001054: bl       #0x100002c8  ; ->msys::MLyt::init
10001058: add      r2, pc, #0xac
1000105c: add      r1, r4, #0x7d0
10001060: mov      r0, r5
10001064: bl       #0x100002d0  ; ->msys::MLyt::createLyt
10001068: add      r6, r4, #0xe9000
1000106c: add      r6, r6, #0x1f0
10001070: vldr     s16, [pc, #0xa4]  ; =0x0 (0)
10001074: vldr     s17, [pc, #0xa4]  ; =0xc347cccd (-199.8)
10001078: mov      r0, r6
1000107c: bl       #0x100002d8  ; ->MoveVBase::stop
10001080: vstr     s16, [r6, #0x1c]
10001084: add      r0, r6, #0x20
10001088: add      r1, r4, #0xe6000
1000108c: vstmia   r0, {s16, s17}
10001090: add      r1, r1, #0x4e0
10001094: ldr      r0, [r6, #0x1c]
10001098: str      r0, [r6, #4]!
1000109c: add      r6, r6, #4
100010a0: mov      r0, #0
100010a4: vstmia   r6, {s16, s17}
100010a8: strb     r0, [r5, #0x141]
100010ac: ldr      r0, [pc, #0x70]  ; =0x401
100010b0: str      r0, [r5, #0x13c]
100010b4: add      r0, r5, #4
100010b8: ldrd     r2, r3, [r0]
100010bc: str      r3, [r2, #4]
100010c0: ldr      r0, [r5, #4]
100010c4: str      r0, [r3]
100010c8: adds     r0, r5, #4
100010cc: beq      #0x100010e4
100010d0: ldr      r2, [r1]
100010d4: str      r1, [r0, #4]
100010d8: str      r2, [r0]
100010dc: str      r0, [r2, #4]
100010e0: str      r0, [r1]
100010e4: ldr      r1, [pc, #0x3c]  ; =0x10008000
100010e8: add      r4, r4, #0xc00
100010ec: add      r4, r4, #0x384
100010f0: ldrd     r0, r1, [r1, #0x14]
100010f4: stm      r4, {r0, r1}
100010f8: vpop     {d8}
100010fc: pop      {r4, r5, r6, pc}
10001100: strdeq   r6, r7, [lr], -r0
10001104: andne    r8, r0, r8, lsl #21
10001108: andeq    r0, r0, lr, lsr #32
1000110c: cmpmi    pc, #0xc0000014
10001110: svcmi    #0x535255
10001114: uqsaxvs  r2, r2, r2
10001118: rsbseq   r7, r4, ip, ror #18
1000111c: andeq    r0, r0, r0
10001120: movtgt   ip, #0x7ccd
10001124: andeq    r0, r0, r1, lsl #8
10001128: andne    r8, r0, r0
1000112c: push     {r4, r5, lr}
10001130: add      r1, r0, #0xf00
10001134: mov      r4, r0
10001138: vpush    {d8}
1000113c: add      r0, r0, #0xf00
10001140: ldrsb    r1, [r1, #0xd7]
10001144: add      r0, r0, #0xcd
10001148: sub      sp, sp, #4
1000114c: ldrsb    r0, [r1, r0]
10001150: mvn      r1, #0
10001154: add      r0, r4, r0, lsl #2
10001158: ldr      r5, [r0, #0xf8c]
1000115c: ldr      r0, [r5]
10001160: ldr      r2, [r0, #8]
10001164: mov      r0, r5
10001168: blx      r2
1000116c: ldrb     r0, [r5, #0x14]
10001170: cmp      r0, #0
10001174: beq      #0x100011d4
10001178: mov      r0, #0
1000117c: vldr     s16, [pc, #0x60]  ; =0x41800000 (16)
10001180: rev      r0, r0
10001184: mov      r5, sp
10001188: str      r0, [sp]
1000118c: ldr      r0, [pc, #0x4c]  ; =0x4acd4
10001190: vmov.f32 s0, s16
10001194: mov      r1, r5
10001198: add      r0, r0, r4
1000119c: bl       #0x100002e0  ; ->MoveC::moveFrm
100011a0: ldr      r0, [pc, #0x40]  ; =0x4ad14
100011a4: vmov.f32 s0, s16
100011a8: mov      r1, r5
100011ac: add      r0, r0, r4
100011b0: bl       #0x100002e0  ; ->MoveC::moveFrm
100011b4: ldr      r1, [pc, #0x30]  ; =0x4af14
100011b8: mov      r0, #1
100011bc: strb     r0, [r1, r4]
100011c0: ldr      r1, [pc, #0x28]  ; =0x10008000
100011c4: add      r4, r4, #0xc00
100011c8: add      r4, r4, #0x384
100011cc: ldrd     r0, r1, [r1, #0x1c]
100011d0: stm      r4, {r0, r1}
100011d4: add      sp, sp, #4
100011d8: vpop     {d8}
100011dc: pop      {r4, r5, pc}
100011e0: ldrdeq   sl, fp, [r4], -r4
100011e4: orrmi    r0, r0, r0
100011e8: andeq    sl, r4, r4, lsl sp
100011ec: andeq    sl, r4, r4, lsl pc
100011f0: andne    r8, r0, r0
100011f4: push     {r4, r5, r6, r7, r8, sb, sl, lr}
100011f8: mov      r5, r1
100011fc: mov      r1, #0x180000
10001200: mov      r4, r0
10001204: mov      r6, #0
10001208: vpush    {d8}
1000120c: sub      sp, sp, #0x18
10001210: add      r3, sp, #0xc
10001214: str      r1, [sp, #8]
10001218: mov      r0, #3
1000121c: stm      r3, {r0, r6}
10001220: mov      r2, #0x100000
10001224: str      r6, [sp, #0x14]
10001228: str      r2, [sp, #4]
1000122c: mov      r3, #0x800000
10001230: mov      r2, #0x200000
10001234: mov      r1, r5
10001238: mov      r0, r4
1000123c: str      r6, [sp]
10001240: bl       #0x100002e8  ; ->msys::MComSys::initBaseSys
10001244: add      r1, r4, #0xe9000
10001248: add      r1, r1, #0xbc
1000124c: mov      r0, r4
10001250: bl       #0x100002f0  ; ->msys::MComSys::entryPage
10001254: add      r1, r4, #0xd3000
10001258: add      r1, r1, #0xcc
1000125c: mov      r0, #1
10001260: strb     r6, [r1, #0x14]
10001264: strb     r6, [r1, #0x15]
10001268: strb     r0, [r1, #0x16]
1000126c: ldr      r0, [pc, #0xec]  ; =0xd2fcc
10001270: mov      r7, #1
10001274: ldr      r1, [pc, #0xec]  ; =0x27150
10001278: add      r0, r0, r4
1000127c: mov      r2, #5
10001280: strb     r7, [r0, #0x14]
10001284: strb     r7, [r0, #0x15]
10001288: strb     r7, [r0, #0x16]
1000128c: ldr      r0, [pc, #0xd0]  ; =0x98a28
10001290: add      r0, r0, r4
10001294: strb     r7, [r1, r0]
10001298: add      r0, r0, #0x13000
1000129c: mov      r1, r6
100012a0: add      r0, r0, #0x8b0
100012a4: bl       #0x100002f8  ; ->Prim::enableDepthTest
100012a8: mov      r3, #0
100012ac: add      r1, r5, #0x400
100012b0: ldr      r8, [pc, #0xb4]  ; =0x10008318
100012b4: vldr     s16, [r4, #0x278]
100012b8: add      sb, r4, #0xc
100012bc: mov      sl, #3
100012c0: mov      r2, r3
100012c4: add      r1, r1, #0x15c
100012c8: mov      r0, #0x20
100012cc: bl       #0x10000180  ; ->_ZnwjP10MemAlcBasePKcj
100012d0: cmp      r0, #0
100012d4: beq      #0x10001304
100012d8: ldr      r1, [pc, #0x90]  ; =0x10008798
100012dc: stm      r0, {r1, r6}
100012e0: add      r1, r5, #0x400
100012e4: vstr     s16, [r0, #8]
100012e8: str      sb, [r0, #0xc]!
100012ec: add      r0, r0, #4
100012f0: add      r1, r1, #0xd4
100012f4: stm      r0!, {r8, sl}
100012f8: ldm      r1, {r1, r2}
100012fc: stm      r0, {r1, r2}
10001300: sub      r0, r0, #0x18
10001304: mov      r1, r0
10001308: add      r0, r5, #0x400
1000130c: add      r0, r0, #0xdc
10001310: bl       #0x10000300  ; ->CtrJobMan::enqueue
10001314: ldr      r1, [pc, #0x58]  ; =0x10008000
10001318: add      r2, r4, #0xc00
1000131c: add      r2, r2, #0x384
10001320: ldrd     r0, r1, [r1, #4]
10001324: stm      r2, {r0, r1}
10001328: mov      r0, r4
1000132c: bl       #0x10000308  ; ->msys::MComSys::setupCamU
10001330: mov      r0, r4
10001334: nop      
10001338: bl       #0x10000310  ; ->msys::MComSys::setupCamL
1000133c: ldr      r0, [pc, #0x34]  ; =0x4ad54
10001340: ldr      r1, [pc, #0x34]  ; =0x4ae34
10001344: add      r0, r0, r4
10001348: add      r1, r1, r4
1000134c: strb     r7, [r0, #0x31]
10001350: strb     r7, [r1, #0x31]
10001354: add      sp, sp, #0x18
10001358: vpop     {d8}
1000135c: pop      {r4, r5, r6, r7, r8, sb, sl, pc}
10001360: andeq    r2, sp, ip, asr #31
10001364: andeq    r8, sb, r8, lsr #20
10001368: andeq    r7, r2, r0, asr r1
1000136c: andne    r8, r0, r8, lsl r3
10001370: mulne    r0, r8, r7
10001374: andne    r8, r0, r0
10001378: andeq    sl, r4, r4, asr sp
1000137c: andeq    sl, r4, r4, lsr lr
10001380: push     {r4, r5, r6, lr}
10001384: bl       #0x10000318  ; ->msys::MComSys
10001388: ldr      r1, [pc, #0xe4]  ; =0x1000891c
1000138c: mov      r2, #4
10001390: str      r1, [r0]
10001394: add      r1, r0, #0xe9000
10001398: add      r0, r0, #0xe9000
1000139c: add      r1, r1, #0x7c
100013a0: add      r0, r0, #0x50
100013a4: bl       #0x10000320  ; ->MsgDataAcsrBase
100013a8: ldr      r1, [pc, #0xc8]  ; =0x10008768
100013ac: mov      r5, #0
100013b0: str      r1, [r0], #0x6c
100013b4: mov      r2, r0
100013b8: add      r0, r0, #4
100013bc: add      r1, r2, #0xc
100013c0: str      r0, [r0]
100013c4: str      r0, [r0, #4]
100013c8: str      r1, [r2, #0xc]
100013cc: str      r1, [r2, #0x10]
100013d0: strb     r5, [r2, #0x14]
100013d4: ldr      r1, [pc, #0xa0]  ; =0x100089d8
100013d8: str      r5, [r2, #0x18]
100013dc: add      r0, r2, #0x24
100013e0: str      r1, [r2]
100013e4: str      r5, [r2, #0x1c]
100013e8: str      r5, [r2, #0x20]
100013ec: bl       #0x10000328  ; ->ad::fw::Resource
100013f0: add      r0, r0, #0x44
100013f4: bl       #0x10003ff8
100013f8: ldr      r1, [pc, #0x80]  ; =0x3e4580
100013fc: add      r2, r0, #0x100
10001400: mvn      r6, #0
10001404: str      r1, [r0], #0x14c
10001408: ldr      r1, [pc, #0x74]  ; =0x100035e0
1000140c: strb     r6, [r0], #4
10001410: strh     r5, [r2, #0x4e]
10001414: mov      r3, #0xc
10001418: mov      r2, #0x1c
1000141c: str      r5, [r0], #4
10001420: bl       #0x10000330  ; ->__aeabi_vec_ctor_nocookie_nodtor
10001424: ldr      r1, [pc, #0x5c]  ; =0x10000988
10001428: mov      r3, #0xc
1000142c: mov      r2, #0x10
10001430: add      r0, r0, #0x15c
10001434: bl       #0x10000330  ; ->__aeabi_vec_ctor_nocookie_nodtor
10001438: sub      r4, r0, #0x2b0
1000143c: mov      r2, #1
10001440: str      r5, [r4, #0x370]
10001444: strb     r2, [r4, #0x374]
10001448: str      r5, [r4, #0x378]
1000144c: str      r5, [r4, #0x37c]
10001450: strb     r5, [r4, #0x380]
10001454: str      r5, [r4, #0x384]
10001458: mov      r1, r6
1000145c: sub      r0, r0, #0xc
10001460: str      r5, [r4, #0x388]
10001464: bl       #0x10003fdc
10001468: sub      r0, r4, #0xe9000
1000146c: sub      r0, r0, #0x124
10001470: pop      {r4, r5, r6, pc}
10001474: andne    r8, r0, ip, lsl sb
10001478: andne    r8, r0, r8, ror #14
1000147c: ldrdne   r8, sb, [r0], -r8
10001480: eorseq   r4, lr, r0, lsl #11
10001484: andne    r3, r0, r0, ror #11
10001488: andne    r0, r0, r8, lsl #19
1000148c: push     {r4, lr}
10001490: bl       #0x10003e74
10001494: pop      {r4, lr}
10001498: b        #0x10000198  ; ->_ZdlPv
1000149c: push     {r4, r5, r6, r7, r8, lr}
100014a0: mov      r4, r0
100014a4: vpush    {d8}
100014a8: sub      sp, sp, #8
100014ac: ldr      r0, [r0, #8]
100014b0: cmp      r0, #0
100014b4: bne      #0x100014c4
100014b8: ldr      r0, [pc, #0x1bc]  ; =0x3f62a8 msys::MComSys::_sys
100014bc: ldr      r0, [r0]
100014c0: str      r0, [r4, #8]
100014c4: add      r0, r4, #0x12000
100014c8: add      r0, r0, #0xa30
100014cc: ldr      r5, [r4, #8]
100014d0: mov      r8, r0
100014d4: bl       #0x100002a8  ; ->ad::lyt::LytResourceMan::init
100014d8: add      r0, r4, #0x12800
100014dc: add      r0, r0, #0x2a4
100014e0: bl       #0x100002b0  ; ->ad::fw::Resource::getFileData
100014e4: mov      r1, r0
100014e8: add      r2, pc, #0x190
100014ec: mov      r0, r8
100014f0: bl       #0x100002b8  ; ->ad::lyt::LytResourceMan::registerArc
100014f4: ldr      r0, [r4, #4]
100014f8: ldr      r2, [pc, #0x184]  ; =0x100081b4
100014fc: mov      r3, #4
10001500: ldr      r1, [r0, #0x18]
10001504: add      r0, r4, #0x12800
10001508: add      r0, r0, #0x32c
1000150c: mov      r7, r0
10001510: bl       #0x10000338  ; ->msys::MLyt::build
10001514: add      r6, r5, #0xd3000
10001518: mov      r2, #1
1000151c: mov      r1, r6
10001520: mov      r0, r7
10001524: bl       #0x100002c8  ; ->msys::MLyt::init
10001528: add      r2, pc, #0x158
1000152c: mov      r1, r8
10001530: mov      r0, r7
10001534: bl       #0x100002d0  ; ->msys::MLyt::createLyt
10001538: add      r5, r4, #0x12800
1000153c: add      r5, r5, #0x3f8
10001540: vldr     s16, [pc, #0x158]  ; =0x0 (0)
10001544: vldr     s17, [pc, #0x158]  ; =0xc3480000 (-200)
10001548: mov      r0, r5
1000154c: bl       #0x100002d8  ; ->MoveVBase::stop
10001550: vstr     s16, [r5, #0x1c]
10001554: add      r0, r5, #0x20
10001558: ldr      r2, [pc, #0x148]  ; =0x100081d4
1000155c: mov      r3, #7
10001560: vstmia   r0, {s16, s17}
10001564: ldr      r0, [r5, #0x1c]
10001568: str      r0, [r5, #4]!
1000156c: add      r5, r5, #4
10001570: mov      r0, #0x400
10001574: vstmia   r5, {s16, s17}
10001578: str      r0, [r7, #0x13c]
1000157c: ldr      r0, [r4, #4]
10001580: ldr      r1, [r0, #0x18]
10001584: add      r0, r4, #0x12c00
10001588: add      r0, r0, #0x2d4
1000158c: mov      r7, r0
10001590: bl       #0x10000338  ; ->msys::MLyt::build
10001594: mov      r1, r6
10001598: mov      r2, #1
1000159c: mov      r0, r7
100015a0: bl       #0x100002c8  ; ->msys::MLyt::init
100015a4: add      r0, r4, #0x13000
100015a8: add      r0, r0, #0x27c
100015ac: add      r3, r4, #0x12800
100015b0: str      r0, [sp]
100015b4: add      r3, r3, #0x214
100015b8: add      r2, pc, #0xec
100015bc: mov      r1, r8
100015c0: mov      r0, r7
100015c4: bl       #0x10000340  ; ->msys::MLyt::createLyt
100015c8: add      r5, r4, #0x12000
100015cc: add      r5, r5, #0xfa0
100015d0: mov      r0, r5
100015d4: bl       #0x100002d8  ; ->MoveVBase::stop
100015d8: vstr     s16, [r5, #0x1c]
100015dc: add      r0, r5, #0x20
100015e0: mov      r1, r4
100015e4: vstmia   r0, {s16, s17}
100015e8: ldr      r0, [r5, #0x1c]
100015ec: str      r0, [r5, #4]!
100015f0: add      r5, r5, #4
100015f4: ldr      r0, [pc, #0xcc]  ; =0x401
100015f8: vstmia   r5, {s16, s17}
100015fc: str      r0, [r7, #0x13c]
10001600: add      r0, r4, #0x28000
10001604: add      r0, r0, #0xb90
10001608: bl       #0x10005918
1000160c: add      r5, r4, #0x28c00
10001610: add      r5, r5, #0x5c
10001614: mov      r0, r5
10001618: bl       #0x100002d8  ; ->MoveVBase::stop
1000161c: vstr     s16, [r5, #0x1c]
10001620: add      r0, r5, #0x20
10001624: ldr      r1, [pc, #0xa0]  ; =0x10008000
10001628: add      r2, r4, #0x12800
1000162c: vstmia   r0, {s16, s17}
10001630: add      r2, r2, #0x1fc
10001634: ldr      r0, [r5, #0x1c]
10001638: str      r0, [r5, #4]!
1000163c: add      r5, r5, #4
10001640: vstmia   r5, {s16, s17}
10001644: ldrd     r0, r1, [r1, #0x4c]
10001648: strd     r0, r1, [r2]
1000164c: ldr      r1, [pc, #0x7c]  ; =0x13254
10001650: mov      r0, r4
10001654: ldrb     r1, [r1, r4]
10001658: cmp      r1, #0
1000165c: beq      #0x10001670
10001660: add      sp, sp, #8
10001664: vpop     {d8}
10001668: pop      {r4, r5, r6, r7, r8, lr}
1000166c: b        #0x10001df8
10001670: add      sp, sp, #8
10001674: vpop     {d8}
10001678: pop      {r4, r5, r6, r7, r8, pc}
1000167c: eorseq   r6, pc, r8, lsr #5
10001680: andeq    r0, r0, lr, lsr #32
10001684: strhne   r8, [r0], -r4
10001688: stmdbmi  lr, {r0, r2, r3, r6, r8, fp, lr} ^
1000168c: strbmi   r4, [sp, #-0x147]
10001690: ldrbpl   r4, [r4], #-0x15f
10001694: svcpl    #0x4b4341
10001698: uqsaxvs  r2, r2, r5
1000169c: rsbseq   r7, r4, ip, ror #18
100016a0: andeq    r0, r0, r0
100016a4: movtgt   r0, #0x8000
100016a8: ldrdne   r8, sb, [r0], -r4
100016ac: stmdbmi  lr, {r0, r2, r3, r6, r8, fp, lr} ^
100016b0: strbmi   r4, [sp, #-0x147]
100016b4: ldrbpl   r4, [r4], #-0x15f
100016b8: svcpl    #0x4b4341
100016bc: cdphs    p15, #6, c5, c14, c12, #2
100016c0: stmdbvc  ip!, {r1, r5, r6, sb, sl, sp, lr} ^
100016c4: andeq    r0, r0, r4, ror r0
100016c8: andeq    r0, r0, r1, lsl #8
100016cc: andne    r8, r0, r0
100016d0: andeq    r3, r1, r4, asr r2
100016d4: push     {r4, r5, r6, lr}
100016d8: mov      r4, r0
100016dc: add      r0, r0, #0x10
100016e0: bl       #0x10000348  ; ->Backup::errorCode
100016e4: add      r5, r4, #0x10000
100016e8: cmp      r0, #0
100016ec: add      r5, r5, #0x2a00
100016f0: beq      #0x1000170c
100016f4: sub      r0, r0, #1
100016f8: subs     r0, r0, #0x2000
100016fc: cmpne    r0, #1
10001700: cmpne    r0, #2
10001704: beq      #0x10001790
10001708: b        #0x10001780
1000170c: add      r0, r4, #0x10
10001710: bl       #0x10000350  ; ->Backup::isBusyFormat
10001714: cmp      r0, #0
10001718: nop      
1000171c: bne      #0x10001754
10001720: add      r0, r4, #0x10
10001724: bl       #0x10000358  ; ->Backup::mount
10001728: cmp      r0, #0
1000172c: nop      
10001730: beq      #0x10001780
10001734: add      r0, r4, #0x10
10001738: bl       #0x10000360  ; ->Backup::rewriteSaveData
1000173c: cmp      r0, #0
10001740: nop      
10001744: beq      #0x10001758
10001748: ldr      r1, [pc, #0x5c]  ; =0x1000815c
1000174c: ldm      r1, {r0, r1}
10001750: strd     r0, r1, [r5, #4]
10001754: pop      {r4, r5, r6, pc}
10001758: ldr      r0, [r4, #8]
1000175c: cmp      r0, #0
10001760: bne      #0x10001770
10001764: ldr      r0, [pc, #0x44]  ; =0x3f62a8 msys::MComSys::_sys
10001768: ldr      r0, [r0]
1000176c: str      r0, [r4, #8]
10001770: ldr      r0, [r0, #4]
10001774: add      r0, r0, #0x400
10001778: add      r0, r0, #0x118
1000177c: bl       #0x10000368  ; ->CtrFS::unmountSaveData
10001780: ldr      r1, [pc, #0x2c]  ; =0x1000817c
10001784: ldm      r1, {r0, r1}
10001788: strd     r0, r1, [r5, #4]
1000178c: pop      {r4, r5, r6, pc}
10001790: ldr      r0, [pc, #0x20]  ; =0x3f40a8 Backup::_fs
10001794: mov      r1, #0
10001798: ldr      r0, [r0]
1000179c: strh     r1, [r0, #0x24]
100017a0: add      r0, r4, #0x10
100017a4: pop      {r4, r5, r6, lr}
100017a8: b        #0x10000370  ; ->Backup::format
100017ac: andne    r8, r0, ip, asr r1
100017b0: eorseq   r6, pc, r8, lsr #5
100017b4: andne    r8, r0, ip, ror r1
100017b8: eorseq   r4, pc, r8, lsr #1
100017bc: ldr      r1, [r0, #8]
100017c0: cmp      r1, #0
100017c4: bne      #0x100017d4
100017c8: ldr      r1, [pc, #0xc]  ; =0x3f62a8 msys::MComSys::_sys
100017cc: ldr      r1, [r1]
100017d0: str      r1, [r0, #8]
100017d4: ldr      r0, [r1, #4]
100017d8: b        #0x10000378  ; ->GameMain::Back
100017dc: eorseq   r6, pc, r8, lsr #5
100017e0: push     {r4, r5, r6, r7, r8, sb, sl, fp, lr}
100017e4: mov      r4, r0
100017e8: add      r0, r0, #0x28000
100017ec: add      r0, r0, #0xb90
100017f0: mov      r7, r1
100017f4: vpush    {d8}
100017f8: sub      sp, sp, #0x2c
100017fc: str      r0, [sp, #0x1c]
10001800: bl       #0x10000380  ; ->msys::MListWndPBase::isTpNeutral
10001804: cmp      r0, #0
10001808: beq      #0x10001b34
1000180c: ldr      r0, [sp, #0x1c]
10001810: bl       #0x10000388  ; ->msys::MListWndPBase::getCurNo
10001814: add      sl, r4, #0x44000
10001818: add      r0, r0, r0, lsl #1
1000181c: ldr      r1, [sl, #0xc68]
10001820: add      r0, r1, r0, lsl #3
10001824: ldrh     r0, [r0, #0x12]
10001828: bl       #0x10000390  ; ->ad::db::GetPcAttack
1000182c: ldrh     r0, [r0, #0xe]
10001830: ldr      r1, [pc, #0x308]  ; =0x7fff87f
10001834: ldr      r2, [pc, #0x308]  ; =0x3f95f0 gGameWork
10001838: and      r1, r1, r0, lsr #5
1000183c: and      r0, r0, #0x1f
10001840: add      r1, r2, r1, lsl #2
10001844: ldr      r1, [r1, #0x20c]
10001848: lsr      r0, r1, r0
1000184c: tst      r0, #1
10001850: ldr      r0, [sp, #0x1c]
10001854: moveq    r6, #0
10001858: movne    r6, #1
1000185c: bl       #0x10000398  ; ->msys::MListWndPBase::getCurItem
10001860: movs     r5, r0
10001864: mov      sb, #0
10001868: beq      #0x100018d8
1000186c: ldr      r0, [sp, #0x1c]
10001870: bl       #0x100003a0  ; ->msys::MListWndPBase::getSelectItem
10001874: cmp      r0, #0
10001878: beq      #0x100018d8
1000187c: mov      r3, #0
10001880: cmp      r6, #0
10001884: mov      r2, r3
10001888: str      sb, [sp]
1000188c: beq      #0x100018c0
10001890: ldr      r1, [pc, #0x2b0]  ; =0x110016
10001894: mov      r0, r4
10001898: bl       #0x10003dd4
1000189c: mov      r1, #0
100018a0: mov      r0, r4
100018a4: bl       #0x10003d68
100018a8: ldr      r0, [pc, #0x29c]  ; =0x100080bc
100018ac: add      r2, r4, #0x10000
100018b0: add      r2, r2, #0x2a00
100018b4: ldm      r0, {r0, r1}
100018b8: strd     r0, r1, [r2, #4]
100018bc: b        #0x10001908
100018c0: ldr      r1, [pc, #0x288]  ; =0x110018
100018c4: mov      r0, r4
100018c8: bl       #0x10003dd4
100018cc: nop      
100018d0: nop      
100018d4: b        #0x10001908
100018d8: ldr      r0, [r7]
100018dc: ldr      r1, [pc, #0x270]  ; =0x802
100018e0: tst      r0, r1
100018e4: beq      #0x10001908
100018e8: ldr      r0, [pc, #0x268]  ; =0x132c4
100018ec: ldr      r0, [r0, r4]
100018f0: ldr      r1, [r0]
100018f4: ldr      r1, [r1, #0x10]
100018f8: blx      r1
100018fc: mov      r1, #0
10001900: mov      r0, r4
10001904: bl       #0x10003d68
10001908: ldr      r0, [sp, #0x1c]
1000190c: bl       #0x10000388  ; ->msys::MListWndPBase::getCurNo
10001910: ldr      r1, [sl, #0xc68]
10001914: add      r0, r0, r0, lsl #1
10001918: mov      r2, r6
1000191c: add      r1, r1, r0, lsl #3
10001920: add      r0, r4, #0x2fc00
10001924: add      r0, r0, #0x228
10001928: bl       #0x10003b24
1000192c: add      r0, r4, #0x12800
10001930: vldr     s16, [pc, #0x224]  ; =0x0 (0)
10001934: add      r8, r4, #0x40000
10001938: add      r0, r0, #0x32c
1000193c: cmp      r5, #0
10001940: mov      fp, #1
10001944: add      r8, r8, #0x4c00
10001948: str      r0, [sp, #8]
1000194c: beq      #0x10001a64
10001950: add      r7, r4, #0x2f000
10001954: ldr      r0, [r7, #0xe20]
10001958: cmp      r0, r5
1000195c: beq      #0x10001a64
10001960: ldr      r0, [r7, #0xe24]
10001964: cmp      r0, #0
10001968: blt      #0x10001984
1000196c: and      r1, r0, #0xff
10001970: ldr      r0, [sp, #8]
10001974: bl       #0x100003a8  ; ->msys::MLyt::getAnim
10001978: vmov.f32 s0, s16
1000197c: nop      
10001980: bl       #0x100003b0  ; ->ad::lyt::LytAnim::stopAndSetFrm
10001984: ldrh     r2, [r5, #4]
10001988: mvn      r1, #0
1000198c: subs     r0, r2, r1, lsr #16
10001990: beq      #0x10001a5c
10001994: ldr      r0, [r5]
10001998: ldr      r3, [sl, #0xc68]
1000199c: add      ip, r0, r0, lsl #1
100019a0: add      r3, r3, ip, lsl #3
100019a4: ldrsh    r3, [r3]
100019a8: cmp      r3, r2
100019ac: bgt      #0x10001a5c
100019b0: ldr      r3, [pc, #0x1a8]  ; =0x1000e670
100019b4: ldr      r2, [r7, #0xe24]
100019b8: sub      ip, r3, #0x18
100019bc: cmp      r2, #0
100019c0: blt      #0x10001a14
100019c4: ldrb     sl, [r8, #0x70]
100019c8: str      r1, [sp, #4]
100019cc: and      r1, r2, #0xff
100019d0: cmp      sl, #0
100019d4: str      fp, [sp]
100019d8: beq      #0x100019f8
100019dc: ldr      r2, [r3, r0, lsl #2]
100019e0: ldr      r0, [sp, #8]
100019e4: add      r3, pc, #0x178
100019e8: bl       #0x100003b8  ; ->msys::MLyt::createAnime
100019ec: nop      
100019f0: nop      
100019f4: b        #0x10001a60
100019f8: ldr      r2, [ip, r0, lsl #2]
100019fc: ldr      r0, [sp, #8]
10001a00: add      r3, pc, #0x174
10001a04: bl       #0x100003b8  ; ->msys::MLyt::createAnime
10001a08: nop      
10001a0c: nop      
10001a10: b        #0x10001a60
10001a14: ldrb     r1, [r8, #0x70]
10001a18: cmp      r1, #0
10001a1c: beq      #0x10001a40
10001a20: ldr      r1, [r3, r0, lsl #2]
10001a24: ldr      r0, [sp, #8]
10001a28: mov      r3, #0
10001a2c: add      r2, pc, #0x130
10001a30: bl       #0x100003c0  ; ->msys::MLyt::createAnimeAutoSlot
10001a34: nop      
10001a38: nop      
10001a3c: b        #0x10001a54
10001a40: ldr      r1, [ip, r0, lsl #2]
10001a44: ldr      r0, [sp, #8]
10001a48: mov      r3, #0
10001a4c: add      r2, pc, #0x128
10001a50: bl       #0x100003c0  ; ->msys::MLyt::createAnimeAutoSlot
10001a54: str      r0, [r7, #0xe24]
10001a58: b        #0x10001a60
10001a5c: str      r1, [r7, #0xe24]
10001a60: str      r5, [r7, #0xe20]
10001a64: cmp      r6, #0
10001a68: addeq    r5, pc, #0x124
10001a6c: beq      #0x10001a80
10001a70: ldrb     r0, [r8, #0x70]
10001a74: cmp      r0, #0
10001a78: addne    r5, pc, #0x128
10001a7c: beq      #0x10001ac0
10001a80: ldr      r0, [sp, #8]
10001a84: mov      r6, #1
10001a88: mov      r1, #3
10001a8c: mov      r7, r0
10001a90: bl       #0x100003c8  ; ->msys::MLyt::getAnime
10001a94: cmp      r0, #0
10001a98: vldrne   s0, [r0, #0xc]
10001a9c: vcmpne.f32 s0, s16
10001aa0: vmrsne   apsr_nzcv, fpscr
10001aa4: ldrbne   r0, [r0, #0x12]
10001aa8: tstne    r0, #1
10001aac: bne      #0x10001b34
10001ab0: ldr      r0, [r4, #8]
10001ab4: cmp      r0, #0
10001ab8: bne      #0x10001ae4
10001abc: b        #0x10001ad8
10001ac0: ldr      r0, [sp, #0x1c]
10001ac4: bl       #0x10000388  ; ->msys::MListWndPBase::getCurNo
10001ac8: cmp      r0, #5
10001acc: addlo    r5, pc, #0xe8
10001ad0: addhs    r5, pc, #0xf8
10001ad4: b        #0x10001a80
10001ad8: ldr      r0, [pc, #0x104]  ; =0x3f62a8 msys::MComSys::_sys
10001adc: ldr      r0, [r0]
10001ae0: str      r0, [r4, #8]
10001ae4: add      r0, r0, #0xe9000
10001ae8: mov      r1, r5
10001aec: add      r0, r0, #0x58
10001af0: mov      r5, r0
10001af4: bl       #0x100003d0  ; ->LMS_GetTextIndexByLabel
10001af8: mov      r1, r0
10001afc: mov      r0, r5
10001b00: bl       #0x100003d8  ; ->LMS_GetText
10001b04: mov      r1, r0
10001b08: mov      r3, #0
10001b0c: add      r0, r4, #0x13000
10001b10: mov      r2, r3
10001b14: add      r0, r0, #0x2c8
10001b18: bl       #0x100003e0  ; ->msys::MMsg::playStr
10001b1c: ldr      r3, [pc, #0xc4]  ; =0x10001dec
10001b20: mov      r2, r6
10001b24: mov      r1, #3
10001b28: mov      r0, r7
10001b2c: str      sb, [sp]
10001b30: bl       #0x100003e8  ; ->msys::MLyt::playAnimeFromNo
10001b34: add      sp, sp, #0x2c
10001b38: vpop     {d8}
10001b3c: pop      {r4, r5, r6, r7, r8, sb, sl, fp, pc}
10001b40: .word    0x07fff87f
10001b44: ldrshteq sb, [pc], -r0
10001b48: andseq   r0, r1, r6, lsl r0
10001b4c: strhne   r8, [r0], -ip
10001b50: andseq   r0, r1, r8, lsl r0
10001b54: andeq    r0, r0, r2, lsl #16
10001b58: andeq    r3, r1, r4, asr #5
10001b5c: andeq    r0, r0, r0
10001b60: andne    lr, r0, r0, ror r6
10001b64: svcpl    #0x6c6e70
10001b68: stmdbmi  lr, {r0, r2, r3, r6, r8, fp, lr} ^
10001b6c: strbmi   r4, [sp, #-0x147]
10001b70: strbmi   r4, [r5], #-0xd5f
10001b74: blmi     #0x117d4c80
10001b78: andeq    r0, r0, r0
10001b7c: svcpl    #0x6c6e70
10001b80: stmdbmi  lr, {r0, r2, r3, r6, r8, fp, lr} ^
10001b84: strbmi   r4, [sp, #-0x147]
10001b88: strbmi   r4, [r5], #-0xd5f
10001b8c: ldclmi   p12, c4, [pc, #-0x104]
10001b90: andeq    r0, r0, ip, asr #32
10001b94: svcpl    #0x53454d
10001b98: stmdbvs  lr!, {r0, r2, r3, r6, r8, fp, sp, lr} ^
10001b9c: strbvs   r6, [sp, #-0x147]!
10001ba0: rsblo    r4, r7, pc, asr sp
10001ba4: andeq    r0, r0, r8, lsr r0
10001ba8: svcpl    #0x53454d
10001bac: stmdbvs  lr!, {r0, r2, r3, r6, r8, fp, sp, lr} ^
10001bb0: strbvs   r6, [sp, #-0x147]!
10001bb4: rsblo    r4, r7, pc, asr sp
10001bb8: andeq    r0, r0, r7, lsr r0
10001bbc: svcpl    #0x53454d
10001bc0: stmdbvs  lr!, {r0, r2, r3, r6, r8, fp, sp, lr} ^
10001bc4: strbvs   r6, [sp, #-0x147]!
10001bc8: rsblo    r4, r7, pc, asr sp
10001bcc: andeq    r0, r0, r5, lsr r0
10001bd0: svcpl    #0x53454d
10001bd4: stmdbvs  lr!, {r0, r2, r3, r6, r8, fp, sp, lr} ^
10001bd8: strbvs   r6, [sp, #-0x147]!
10001bdc: rsblo    r4, r7, pc, asr sp
10001be0: andeq    r0, r0, r6, lsr r0
10001be4: eorseq   r6, pc, r8, lsr #5
10001be8: andne    r1, r0, ip, ror #27
10001bec: ldr      r1, [pc, #0x10]  ; =0x12aa8
10001bf0: ldrb     r1, [r1, r0]
10001bf4: cmp      r1, #0
10001bf8: beq      #0x10001c00
10001bfc: b        #0x1000149c
10001c00: bx       lr
10001c04: andeq    r2, r1, r8, lsr #21
10001c08: push     {r4, r5, r6, lr}
10001c0c: mov      r4, r0
10001c10: add      r0, r0, #0x10
10001c14: bl       #0x10000348  ; ->Backup::errorCode
10001c18: add      r5, r4, #0x10000
10001c1c: cmp      r0, #0
10001c20: add      r5, r5, #0x2a00
10001c24: beq      #0x10001c48
10001c28: sub      r0, r0, #1
10001c2c: subs     r0, r0, #0x2000
10001c30: cmpne    r0, #1
10001c34: cmpne    r0, #2
10001c38: beq      #0x10001c9c
10001c3c: ldr      r1, [pc, #0x68]  ; =0x1000817c
10001c40: ldm      r1, {r0, r1}
10001c44: b        #0x10001ca4
10001c48: add      r0, r4, #0x10
10001c4c: bl       #0x100003f0  ; ->Backup::isBusyWriting
10001c50: cmp      r0, #0
10001c54: nop      
10001c58: bne      #0x10001ca8
10001c5c: add      r0, r4, #0x10
10001c60: bl       #0x100003f8  ; ->Backup::term
10001c64: add      r0, r4, #0x21c00
10001c68: add      r0, r0, #0x1a4
10001c6c: bl       #0x10000400  ; ->Message::close
10001c70: ldr      r0, [pc, #0x38]  ; =0x10008064
10001c74: ldm      r0, {r0, r1}
10001c78: strd     r0, r1, [r5, #0xc]
10001c7c: mov      r0, r4
10001c80: bl       #0x10005f98
10001c84: ldr      r1, [pc, #0x28]  ; =0x10008000
10001c88: cmp      r0, #0
10001c8c: addne    r1, r1, #0x164
10001c90: addeq    r1, r1, #0x16c
10001c94: ldm      r1, {r0, r1}
10001c98: b        #0x10001ca4
10001c9c: ldr      r0, [pc, #0x14]  ; =0x10008174
10001ca0: ldm      r0, {r0, r1}
10001ca4: strd     r0, r1, [r5, #4]
10001ca8: pop      {r4, r5, r6, pc}
10001cac: andne    r8, r0, ip, ror r1
10001cb0: andne    r8, r0, r4, rrx
10001cb4: andne    r8, r0, r0
10001cb8: andne    r8, r0, r4, ror r1
10001cbc: push     {r4, r5, r6, lr}
10001cc0: mov      r5, r0
10001cc4: bl       #0x10005f98
10001cc8: ldr      r6, [pc, #0x50]  ; =0x10008000
10001ccc: cmp      r0, #0
10001cd0: add      r4, r5, #0x10000
10001cd4: add      r4, r4, #0x2a00
10001cd8: ldrdeq   r0, r1, [r6, #0x94]
10001cdc: beq      #0x10001d18
10001ce0: add      r0, r5, #0x44000
10001ce4: add      r0, r0, #0xc00
10001ce8: add      r0, r0, #0x68
10001cec: mov      r2, #1
10001cf0: ldm      r0, {r0, r1}
10001cf4: ldrsb    r1, [r1, #8]
10001cf8: add      r1, r1, r1, lsl #1
10001cfc: add      r1, r0, r1, lsl #3
10001d00: add      r0, r5, #0x2fc00
10001d04: add      r0, r0, #0x228
10001d08: bl       #0x10003b24
10001d0c: ldrd     r0, r1, [r6, #0x84]
10001d10: strd     r0, r1, [r4, #0xc]
10001d14: ldrd     r0, r1, [r6, #0x8c]
10001d18: strd     r0, r1, [r4, #4]
10001d1c: pop      {r4, r5, r6, pc}
10001d20: andne    r8, r0, r0
10001d24: push     {r3, r4, r5, r6, r7, r8, sb, lr}
10001d28: mov      r4, r0
10001d2c: add      r0, r0, #0x12800
10001d30: mov      r5, r1
10001d34: add      r0, r0, #0x32c
10001d38: mov      r6, r2
10001d3c: mov      r1, #3
10001d40: mov      r8, r0
10001d44: bl       #0x100003c8  ; ->msys::MLyt::getAnime
10001d48: cmp      r0, #0
10001d4c: mov      r7, #0
10001d50: beq      #0x10001d70
10001d54: vldr     s0, [r0, #0xc]
10001d58: vldr     s1, [pc, #0x84]  ; =0x0 (0)
10001d5c: vcmp.f32 s0, s1
10001d60: vmrs     apsr_nzcv, fpscr
10001d64: ldrbne   r0, [r0, #0x12]
10001d68: tstne    r0, #1
10001d6c: bne      #0x10001de0
10001d70: cmp      r6, #0
10001d74: beq      #0x10001dc8
10001d78: ldr      r0, [r4, #8]
10001d7c: cmp      r0, #0
10001d80: bne      #0x10001d90
10001d84: ldr      r0, [pc, #0x5c]  ; =0x3f62a8 msys::MComSys::_sys
10001d88: ldr      r0, [r0]
10001d8c: str      r0, [r4, #8]
10001d90: add      r0, r0, #0xe9000
10001d94: mov      r1, r5
10001d98: add      r0, r0, #0x58
10001d9c: mov      r5, r0
10001da0: bl       #0x100003d0  ; ->LMS_GetTextIndexByLabel
10001da4: mov      r1, r0
10001da8: mov      r0, r5
10001dac: bl       #0x100003d8  ; ->LMS_GetText
10001db0: mov      r1, r0
10001db4: mov      r3, #0
10001db8: add      r0, r4, #0x13000
10001dbc: mov      r2, r3
10001dc0: add      r0, r0, #0x2c8
10001dc4: bl       #0x100003e0  ; ->msys::MMsg::playStr
10001dc8: add      r3, pc, #0x1c
10001dcc: mov      r2, r6
10001dd0: mov      r1, #3
10001dd4: mov      r0, r8
10001dd8: str      r7, [sp]
10001ddc: bl       #0x100003e8  ; ->msys::MLyt::playAnimeFromNo
10001de0: pop      {r3, r4, r5, r6, r7, r8, sb, pc}
10001de4: andeq    r0, r0, r0
10001de8: eorseq   r6, pc, r8, lsr #5
10001dec: svcpl    #0x505845
10001df0: svcpl    #0x4c4e50
10001df4: andeq    r0, r0, r5, asr r0
10001df8: push     {r4, r5, r6, r7, r8, sb, sl, fp, lr}
10001dfc: mov      r4, r0
10001e00: vpush    {d8}
10001e04: sub      sp, sp, #0xdc
10001e08: add      r0, sp, #0x58
10001e0c: bl       #0x10000408  ; ->ad::lyt::LytLocalize
10001e10: add      r5, r4, #0x12800
10001e14: add      r5, r5, #0x32c
10001e18: add      r0, sp, #0x58
10001e1c: ldr      r1, [r5, #0x150]
10001e20: bl       #0x10000410  ; ->ad::lyt::LytLocalize::localize
10001e24: add      r0, r4, #0x12c00
10001e28: add      r0, r0, #0x2d4
10001e2c: str      r0, [sp, #0x48]
10001e30: ldr      r1, [r0, #0x150]
10001e34: add      r0, sp, #0x58
10001e38: bl       #0x10000410  ; ->ad::lyt::LytLocalize::localize
10001e3c: vldr     s16, [pc, #0x398]  ; =0x0 (0)
10001e40: vstr     s16, [sp, #0x68]
10001e44: ldr      r0, [r4, #4]
10001e48: add      r1, r0, #4
10001e4c: add      r0, r5, #4
10001e50: ldrd     r2, r3, [r0]
10001e54: str      r3, [r2, #4]
10001e58: ldr      r0, [r5, #4]
10001e5c: str      r0, [r3]
10001e60: adds     r0, r5, #4
10001e64: beq      #0x10001e7c
10001e68: ldr      r2, [r1]
10001e6c: str      r1, [r0, #4]
10001e70: str      r2, [r0]
10001e74: str      r0, [r2, #4]
10001e78: str      r0, [r1]
10001e7c: mov      r0, #0x400
10001e80: str      r0, [r5, #0x13c]
10001e84: ldr      r1, [r4, #4]
10001e88: ldr      r0, [sp, #0x48]
10001e8c: add      r2, r1, #0xc
10001e90: add      r1, r0, #4
10001e94: ldm      r1, {r3, ip}
10001e98: str      ip, [r3, #4]
10001e9c: ldr      r1, [r0, #4]
10001ea0: str      r1, [ip]
10001ea4: adds     r1, r0, #4
10001ea8: beq      #0x10001ec0
10001eac: ldr      r3, [r2]
10001eb0: str      r2, [r1, #4]
10001eb4: str      r3, [r1]
10001eb8: str      r1, [r3, #4]
10001ebc: str      r1, [r2]
10001ec0: ldr      sb, [pc, #0x318]  ; =0x401
10001ec4: add      r7, r4, #0x21c00
10001ec8: add      r7, r7, #0x58
10001ecc: str      sb, [r0, #0x13c]
10001ed0: ldr      r0, [r4, #4]
10001ed4: str      r0, [sp, #0x10]
10001ed8: ldr      r1, [r4, #8]
10001edc: cmp      r1, #0
10001ee0: bne      #0x10001ef0
10001ee4: ldr      r1, [pc, #0x2f8]  ; =0x3f62a8 msys::MComSys::_sys
10001ee8: ldr      r1, [r1]
10001eec: str      r1, [r4, #8]
10001ef0: add      r1, r1, #0xe9000
10001ef4: ldr      r0, [r0, #0x18]
10001ef8: ldr      r1, [r1, #0x4c]
10001efc: add      r6, r7, #0x6c00
10001f00: add      r6, r6, #0x2ec
10001f04: mov      r8, #0
10001f08: str      r1, [sp, #0xc]
10001f0c: stm      r6!, {r0, r8, sb}
10001f10: add      sl, r7, #0x6c00
10001f14: str      sb, [r6, #-0x48]
10001f18: vstr     s16, [sl, #0x2b4]
10001f1c: mov      r2, #1
10001f20: vstr     s16, [sl, #0x2b8]
10001f24: strb     r2, [r6, #-0x20]
10001f28: mvn      fp, #0
10001f2c: strb     r8, [r6, #-0x1f]
10001f30: str      fp, [r6, #-0x18]
10001f34: sub      r2, r6, #0x28
10001f38: str      fp, [r6, #-0x14]
10001f3c: add      r3, r7, #0x6c00
10001f40: add      r3, r3, #0x2e8
10001f44: sub      r6, r6, #0xc00
10001f48: add      r0, r7, #0x14c
10001f4c: sub      r6, r6, #0x2f8
10001f50: stm      r2, {r3, r8}
10001f54: bl       #0x10000418  ; ->Message::init
10001f58: ldr      r1, [sp, #0xc]
10001f5c: add      r0, r7, #0x14c
10001f60: bl       #0x10000420  ; ->Message::setMsgDat
10001f64: mov      r0, r7
10001f68: nop      
10001f6c: bl       #0x100039d8
10001f70: str      sb, [r6, #0xefc]
10001f74: vstr     s16, [sl, #0x300]
10001f78: mov      r1, #1
10001f7c: vstr     s16, [sl, #0x304]
10001f80: strb     r1, [r6, #0xf24]
10001f84: strb     r8, [r6, #0xf25]
10001f88: str      fp, [r6, #0xf2c]
10001f8c: str      fp, [r6, #0xf30]
10001f90: add      r6, r6, #0xc00
10001f94: add      r2, r7, #0x6c00
10001f98: add      r6, r6, #0x31c
10001f9c: add      r2, r2, #0x334
10001fa0: stm      r6, {r2, r8}
10001fa4: ldr      r0, [sp, #0x10]
10001fa8: add      r1, r0, #0xc
10001fac: add      r0, r7, #4
10001fb0: ldrd     r2, r3, [r0]
10001fb4: str      r3, [r2, #4]
10001fb8: ldr      r0, [r7, #4]
10001fbc: str      r0, [r3]
10001fc0: adds     r0, r7, #4
10001fc4: beq      #0x10001fdc
10001fc8: ldr      r2, [r1]
10001fcc: str      r1, [r0, #4]
10001fd0: str      r2, [r0]
10001fd4: str      r0, [r2, #4]
10001fd8: str      r0, [r1]
10001fdc: str      sb, [r7, #0x13c]
10001fe0: add      r1, r4, #0x28000
10001fe4: add      r1, r1, #0xb90
10001fe8: str      r8, [sp]
10001fec: ldr      r0, [sp, #0x48]
10001ff0: mov      r3, #0
10001ff4: add      r2, pc, #0x1ec
10001ff8: str      r1, [sp, #0xc8]
10001ffc: str      r8, [sp, #4]
10002000: bl       #0x10000428  ; ->msys::MLyt::attachMChr
10002004: ldr      r0, [sp, #0xc8]
10002008: mov      r1, r4
1000200c: strb     r8, [r0, #0x141]
10002010: add      r0, r4, #0x2fc00
10002014: add      r0, r0, #0x228
10002018: str      r0, [sp, #0x78]
1000201c: bl       #0x10002cec
10002020: ldr      r0, [r4, #4]
10002024: add      r1, r4, #0x1fc00
10002028: add      r1, r1, #0x30c
1000202c: add      r6, r4, #0x19c00
10002030: ldr      r0, [r0, #0x18]
10002034: add      r6, r6, #0x30c
10002038: str      r0, [r1, #0xc34]
1000203c: add      r0, r4, #0x20800
10002040: str      r8, [r1, #0xc38]!
10002044: add      r0, r0, #0x30c
10002048: str      sb, [r1, #8]
1000204c: vstr     s16, [r0, #0x3c]
10002050: add      r0, r4, #0x1a000
10002054: add      r0, r0, #0x58
10002058: bl       #0x10000430  ; ->MessageSimple::init
1000205c: mov      r0, r6
10002060: nop      
10002064: bl       #0x100039d8
10002068: add      r0, r4, #0x1f000
1000206c: mov      sb, #1
10002070: strb     sb, [r0, #0xb14]
10002074: strb     sb, [r0, #0xb15]
10002078: ldr      r0, [r4, #8]
1000207c: cmp      r0, #0
10002080: bne      #0x10002090
10002084: ldr      r0, [pc, #0x158]  ; =0x3f62a8 msys::MComSys::_sys
10002088: ldr      r0, [r0]
1000208c: str      r0, [r4, #8]
10002090: add      r0, r0, #0xe9000
10002094: add      r0, r0, #0x58
10002098: add      r1, pc, #0x15c
1000209c: mov      r7, r0
100020a0: bl       #0x100003d0  ; ->LMS_GetTextIndexByLabel
100020a4: mov      r1, r0
100020a8: mov      r0, r7
100020ac: bl       #0x100003d8  ; ->LMS_GetText
100020b0: mov      r1, r0
100020b4: mov      r3, #0
100020b8: mov      r2, r3
100020bc: mov      r0, r6
100020c0: bl       #0x100003e0  ; ->msys::MMsg::playStr
100020c4: ldr      r0, [sp, #0x48]
100020c8: mov      r3, #0
100020cc: add      r2, pc, #0x148
100020d0: mov      r1, r6
100020d4: str      r8, [sp]
100020d8: str      r8, [sp, #4]
100020dc: bl       #0x10000428  ; ->msys::MLyt::attachMChr
100020e0: ldr      r0, [pc, #0x148]  ; =0x10008308
100020e4: add      fp, sp, #0x80
100020e8: add      sl, r4, #0x12800
100020ec: add      sl, sl, #0x214
100020f0: ldm      r0, {r0, r1, r2, r3}
100020f4: mov      r6, #0
100020f8: stm      fp, {r0, r1, r2, r3}
100020fc: mov      r0, sl
10002100: ldr      r1, [fp, r6, lsl #2]
10002104: bl       #0x10000438  ; ->ad::ctrl::ButtonGroup::FindButtonByName
10002108: add      r1, r4, r6, lsl #2
1000210c: add      r7, r1, #0x13000
10002110: ldr      r1, [pc, #0x11c]  ; =0x10006490
10002114: mov      r2, r4
10002118: str      r0, [r7, #0x2b8]
1000211c: bl       #0x10000440  ; ->ad::ctrl::AnimButton::SetStateChangeCallback
10002120: ldr      r0, [r7, #0x2b8]
10002124: mov      r1, #0
10002128: str      r6, [r0, #0x48]
1000212c: ldr      r2, [r7, #0x2b8]
10002130: ldr      r0, [r2]
10002134: ldr      r3, [r0, #0x28]
10002138: mov      r0, r2
1000213c: blx      r3
10002140: add      r6, r6, #1
10002144: cmp      r6, #4
10002148: blt      #0x100020fc
1000214c: mov      r3, #0
10002150: ldr      r0, [sp, #0x48]
10002154: mov      r2, r3
10002158: add      r1, pc, #0xd8
1000215c: bl       #0x10000448  ; ->msys::MLyt::getParts
10002160: ldrb     r1, [r0, #0x44]
10002164: and      r1, r1, #0xfe
10002168: strb     r1, [r0, #0x44]
1000216c: ldr      r0, [r4, #8]
10002170: cmp      r0, #0
10002174: bne      #0x10002184
10002178: ldr      r0, [pc, #0x64]  ; =0x3f62a8 msys::MComSys::_sys
1000217c: ldr      r0, [r0]
10002180: str      r0, [r4, #8]
10002184: add      r7, r4, #0x13000
10002188: add      r7, r7, #0x27c
1000218c: mov      r6, r0
10002190: str      r7, [sp, #0x14]
10002194: ldr      r0, [r0, #4]
10002198: bl       #0x10000450  ; ->ad::fw::TaskBase::isFps30
1000219c: cmp      r0, #0
100021a0: ldr      r0, [r7]
100021a4: vldr     s17, [pc, #0x98]  ; =0x3f800000 (1)
100021a8: add      r1, r6, #0xe9000
100021ac: vldrne   s0, [pc, #0x94]  ; =0x40000000 (2)
100021b0: ldr      r2, [r0, #8]
100021b4: vmoveq.f32 s0, s17
100021b8: add      r1, r1, #0x124
100021bc: mov      r0, r7
100021c0: blx      r2
100021c4: ldr      r0, [sp, #0x48]
100021c8: ldr      r7, [sp, #0x14]
100021cc: add      r8, sp, #0x80
100021d0: mov      sl, #3
100021d4: mov      r6, #0
100021d8: b        #0x1000224c
100021dc: andeq    r0, r0, r0
100021e0: andeq    r0, r0, r1, lsl #8
100021e4: eorseq   r6, pc, r8, lsr #5
100021e8: svcpl    #0x534e49
100021ec: ldrbpl   r4, [r3], #-0x94c
100021f0: mcrmi    p13, #2, r4, c9, c15, #2
100021f4: stclmi   p7, c4, [r1, #-0x124]
100021f8: andeq    r0, r0, r5, asr #32
100021fc: svcpl    #0x53454d
10002200: ldrbtmi  r6, [r3], #-0x54d
10002204: ldclmi   p4, c7, [pc, #-0x184]
10002208: strbmi   r6, [sb, -sb, ror #28]!
1000220c: svcpl    #0x656d61
10002210: svcpl    #0x646e65
10002214: svcvs    #0x666e69
10002218: andeq    r0, r0, r3, lsr r0
1000221c: svcpl    #0x534e49
10002220: stmdami  r3, {r1, r4, r6, r8, sl, lr} ^
10002224: cdpmi    p2, #4, c5, c1, c1, #2
10002228: ldrbpl   r4, [pc], #-0x547
1000222c: subseq   r5, r4, r5, asr #16
10002230: andne    r8, r0, r8, lsl #6
10002234: mulne    r0, r0, r4
10002238: svcpl    #0x6e7462
1000223c: strbmi   r5, [sb], #-0x547
10002240: andeq    r0, r0, r5, asr #32
10002244: svclo    #0x800000
10002248: andmi    r0, r0, r0
1000224c: str      r0, [sp, #0xc]
10002250: ldr      r1, [r7, #0x30]
10002254: add      r0, r7, #0x30
10002258: cmp      r1, #0
1000225c: moveq    fp, #0
10002260: beq      #0x10002284
10002264: ldr      r1, [r0, #4]
10002268: cmp      r1, #0
1000226c: moveq    fp, #1
10002270: beq      #0x10002284
10002274: ldr      r0, [r0, #8]
10002278: cmp      r0, #0
1000227c: moveq    fp, #2
10002280: mvnne    fp, #0
10002284: add      r0, fp, r6
10002288: mov      r3, #0
1000228c: sxtb     sb, r0
10002290: ldr      r1, [r8, r6, lsl #2]
10002294: ldr      r0, [sp, #0xc]
10002298: mov      r2, r3
1000229c: bl       #0x10000448  ; ->msys::MLyt::getParts
100022a0: mov      r1, r0
100022a4: add      r0, r7, #0x30
100022a8: add      r6, r6, #1
100022ac: cmp      r6, sl
100022b0: str      r1, [r0, sb, lsl #2]
100022b4: blo      #0x10002284
100022b8: ldr      r0, [sp, #0x14]
100022bc: mov      r1, #0
100022c0: bl       #0x10000458  ; ->msys::MCursorBase::setVisible
100022c4: add      r8, r4, #0x40000
100022c8: add      r8, r8, #0x4c00
100022cc: mov      r2, #0
100022d0: ldrb     r0, [r8, #0x70]
100022d4: cmp      r0, #0
100022d8: ldr      r0, [pc, #0x404]  ; =0x3f95f0 gGameWork
100022dc: movne    r1, #0xa
100022e0: moveq    r1, #0
100022e4: add      r0, r0, r1, lsl #1
100022e8: add      sb, r0, #0x7d0
100022ec: ldr      r0, [sp, #0x48]
100022f0: mov      r1, #3
100022f4: bl       #0x10000460  ; ->msys::MLyt::setAnimeInfo
100022f8: ldr      r0, [sp, #0x48]
100022fc: mov      r2, #0
10002300: mov      r1, #4
10002304: bl       #0x10000460  ; ->msys::MLyt::setAnimeInfo
10002308: ldr      r0, [sp, #0x48]
1000230c: mov      r2, #0
10002310: mov      r1, #5
10002314: bl       #0x10000460  ; ->msys::MLyt::setAnimeInfo
10002318: mov      r7, #0
1000231c: add      r0, sp, #0x30
10002320: strb     r7, [sp, #0x2c]
10002324: mov      sl, #1
10002328: vstmia   r0, {s16, s17}
1000232c: add      r3, pc, #0x3b4
10002330: vstr     s16, [sp, #0x38]
10002334: strh     sl, [sp, #0x3c]
10002338: strh     r7, [sp, #0x3e]
1000233c: str      r7, [sp, #0x40]
10002340: str      r7, [sp, #0x44]
10002344: ldr      r1, [r5, #0x150]
10002348: add      r2, pc, #0x39c
1000234c: add      r0, sp, #0x2c
10002350: bl       #0x10000468  ; ->ad::lyt::LytAnim::init
10002354: ldr      r0, [sp, #0x40]
10002358: add      r6, sp, #0x2c
1000235c: bl       #0x10000470  ; ->ad::lyt::AnimTransform::GetFrameSize
10002360: vmov     s0, r0
10002364: mov      r0, r6
10002368: vcvt.f32.u32 s0, s0
1000236c: bl       #0x100003b0  ; ->ad::lyt::LytAnim::stopAndSetFrm
10002370: mov      r1, #1
10002374: add      r0, sp, #0x2c
10002378: bl       #0x10000478  ; ->ad::lyt::LytAnim::term
1000237c: ldr      r1, [r5, #0x150]
10002380: add      r3, pc, #0x360
10002384: add      r2, pc, #0x368
10002388: add      r0, sp, #0x2c
1000238c: bl       #0x10000468  ; ->ad::lyt::LytAnim::init
10002390: ldrsb    r0, [r8, #0x70]
10002394: vmov     s0, r0
10002398: add      r0, sp, #0x2c
1000239c: vcvt.f32.s32 s0, s0
100023a0: bl       #0x100003b0  ; ->ad::lyt::LytAnim::stopAndSetFrm
100023a4: mov      r1, #1
100023a8: add      r0, sp, #0x2c
100023ac: bl       #0x10000478  ; ->ad::lyt::LytAnim::term
100023b0: ldr      r0, [sp, #0x48]
100023b4: add      r3, pc, #0x32c
100023b8: add      r2, pc, #0x32c
100023bc: ldr      r1, [r0, #0x150]
100023c0: add      r0, sp, #0x2c
100023c4: bl       #0x10000468  ; ->ad::lyt::LytAnim::init
100023c8: ldr      r0, [sp, #0x40]
100023cc: add      r6, sp, #0x2c
100023d0: bl       #0x10000470  ; ->ad::lyt::AnimTransform::GetFrameSize
100023d4: vmov     s0, r0
100023d8: mov      r0, r6
100023dc: vcvt.f32.u32 s0, s0
100023e0: bl       #0x100003b0  ; ->ad::lyt::LytAnim::stopAndSetFrm
100023e4: mov      r1, #1
100023e8: add      r0, sp, #0x2c
100023ec: bl       #0x10000478  ; ->ad::lyt::LytAnim::term
100023f0: ldr      r0, [sp, #0x48]
100023f4: add      r3, pc, #0x2ec
100023f8: add      r2, pc, #0x2f4
100023fc: ldr      r1, [r0, #0x150]
10002400: add      r0, sp, #0x2c
10002404: bl       #0x10000468  ; ->ad::lyt::LytAnim::init
10002408: ldrsb    r0, [r8, #0x70]
1000240c: vmov     s0, r0
10002410: add      r0, sp, #0x2c
10002414: vcvt.f32.s32 s0, s0
10002418: bl       #0x100003b0  ; ->ad::lyt::LytAnim::stopAndSetFrm
1000241c: mov      r1, #1
10002420: add      r0, sp, #0x2c
10002424: bl       #0x10000478  ; ->ad::lyt::LytAnim::term
10002428: ldrb     r0, [r8, #0x70]
1000242c: cmp      r0, #0
10002430: beq      #0x10002488
10002434: mov      r0, #4
10002438: str      r0, [sp]
1000243c: ldr      r3, [pc, #0x2c0]  ; =0x1000e618
10002440: add      r2, pc, #0x2c0
10002444: mov      r1, sb
10002448: mov      r0, r4
1000244c: bl       #0x10006944
10002450: ldr      r1, [r5, #0x150]
10002454: add      r3, pc, #0x2ac
10002458: add      r2, pc, #0x2c0
1000245c: add      r0, sp, #0x2c
10002460: bl       #0x10000468  ; ->ad::lyt::LytAnim::init
10002464: vmov.f32 s0, s16
10002468: add      r0, sp, #0x2c
1000246c: bl       #0x100003b0  ; ->ad::lyt::LytAnim::stopAndSetFrm
10002470: mov      r1, #1
10002474: add      r0, sp, #0x2c
10002478: bl       #0x10000478  ; ->ad::lyt::LytAnim::term
1000247c: nop      
10002480: nop      
10002484: b        #0x100024d0
10002488: mov      r0, #6
1000248c: str      r0, [sp]
10002490: ldr      r3, [pc, #0x294]  ; =0x1000e5b8
10002494: add      r2, pc, #0x294
10002498: mov      r1, sb
1000249c: mov      r0, r4
100024a0: bl       #0x10006944
100024a4: ldr      r1, [r5, #0x150]
100024a8: add      r3, pc, #0x280
100024ac: add      r2, pc, #0x26c
100024b0: add      r0, sp, #0x2c
100024b4: bl       #0x10000468  ; ->ad::lyt::LytAnim::init
100024b8: vmov.f32 s0, s16
100024bc: add      r0, sp, #0x2c
100024c0: bl       #0x100003b0  ; ->ad::lyt::LytAnim::stopAndSetFrm
100024c4: mov      r1, #1
100024c8: add      r0, sp, #0x2c
100024cc: bl       #0x10000478  ; ->ad::lyt::LytAnim::term
100024d0: ldr      r0, [r4, #4]
100024d4: add      r1, r4, #0x19c00
100024d8: add      r1, r1, #0x308
100024dc: mov      r2, #0x400
100024e0: ldr      r0, [r0, #0x18]
100024e4: str      r2, [r1], #-0xc
100024e8: mov      r7, #0
100024ec: stm      r1, {r0, r7}
100024f0: add      r3, r4, #0x19c00
100024f4: add      r3, r3, #0x2c8
100024f8: add      r6, r4, #0x13000
100024fc: add      r0, r4, #0x13400
10002500: add      r6, r6, #0x2c8
10002504: vstr     s16, [r3, #0x3c]
10002508: add      r0, r0, #0x14
1000250c: bl       #0x10000430  ; ->MessageSimple::init
10002510: mov      r0, r6
10002514: nop      
10002518: bl       #0x100039d8
1000251c: add      r1, r4, #0x18000
10002520: mov      r0, #1
10002524: strb     r0, [r1, #0xed0]
10002528: strb     r0, [r1, #0xed1]
1000252c: add      r3, pc, #0x214
10002530: add      r2, pc, #0x21c
10002534: mov      r1, r6
10002538: mov      r0, r5
1000253c: str      r7, [sp]
10002540: str      r7, [sp, #4]
10002544: bl       #0x10000428  ; ->msys::MLyt::attachMChr
10002548: mov      r3, #0
1000254c: add      r2, pc, #0x1f4
10002550: add      r1, pc, #0x210
10002554: mov      r0, r5
10002558: bl       #0x100003c0  ; ->msys::MLyt::createAnimeAutoSlot
1000255c: ldr      r1, [r5, #0x150]
10002560: add      r3, pc, #0x1e0
10002564: add      r2, pc, #0x20c
10002568: add      r0, sp, #0x2c
1000256c: bl       #0x10000468  ; ->ad::lyt::LytAnim::init
10002570: ldr      r0, [sp, #0x40]
10002574: add      r6, sp, #0x2c
10002578: bl       #0x10000470  ; ->ad::lyt::AnimTransform::GetFrameSize
1000257c: vmov     s0, r0
10002580: mov      r0, r6
10002584: vcvt.f32.u32 s0, s0
10002588: bl       #0x100003b0  ; ->ad::lyt::LytAnim::stopAndSetFrm
1000258c: mov      r1, #1
10002590: add      r0, sp, #0x2c
10002594: bl       #0x10000478  ; ->ad::lyt::LytAnim::term
10002598: add      r3, pc, #0x1a8
1000259c: mov      r2, #0
100025a0: mov      r1, #3
100025a4: mov      r0, r5
100025a8: str      r7, [sp]
100025ac: bl       #0x10000480  ; ->msys::MLyt::stopAnimeAndSetEnd
100025b0: vstr     s16, [sp, #0x38]
100025b4: nop      
100025b8: bl       #0x10000488  ; ->GameMain::GameModeOld
100025bc: cmp      r0, #0xa
100025c0: add      fp, r4, #0x10000
100025c4: add      fp, fp, #0x2a00
100025c8: add      sl, r4, #0x44000
100025cc: moveq    r6, #0x12
100025d0: moveq    r5, #0
100025d4: beq      #0x100025f8
100025d8: bl       #0x10000490  ; ->atk_mg::GetBootInfo
100025dc: nop      
100025e0: nop      
100025e4: bl       #0x10000498  ; ->atk_mg::BootInfo::saveBgm
100025e8: ldr      r1, [pc, #0x198]  ; =0x10008000
100025ec: ldrd     r0, r1, [r1, #0x54]
100025f0: strd     r0, r1, [fp, #4]
100025f4: b        #0x10002964
100025f8: nop      
100025fc: bl       #0x100004a0  ; ->btl::GetBootInfo
10002600: ldr      r1, [sl, #0xc68]
10002604: add      r2, r5, r5, lsl #1
10002608: vldr     s1, [r0, #0x114]
1000260c: add      r0, r6, r2, lsl #3
10002610: ldrh     r0, [r1, r0]
10002614: vmov     s0, r0
10002618: vcvt.f32.u32 s0, s0
1000261c: vcmp.f32 s1, s0
10002620: vmrs     apsr_nzcv, fpscr
10002624: addne    r5, r5, #1
10002628: bne      #0x100025f8
1000262c: bl       #0x100004a0  ; ->btl::GetBootInfo
10002630: ldr      r7, [r0, #0x124]
10002634: ldr      r0, [sp, #0xc8]
10002638: and      r6, r5, #0xff
1000263c: bl       #0x100004a8  ; ->msys::MListWndPBase::getListWnd
10002640: ldr      r1, [r0]
10002644: ldr      r2, [r1, #0x28]
10002648: mov      r1, r6
1000264c: blx      r2
10002650: add      r0, sp, #0x80
10002654: bl       #0x100004b0  ; ->ad::lyt::LytNumReel3::InitParam
10002658: ldr      r0, [r4, #8]
1000265c: cmp      r0, #0
10002660: bne      #0x10002670
10002664: ldr      r0, [pc, #-0x488]  ; =0x3f62a8 msys::MComSys::_sys
10002668: ldr      r0, [r0]
1000266c: str      r0, [r4, #8]
10002670: mov      r1, #0xff
10002674: add      ip, sp, #0x80
10002678: mov      r2, #2
1000267c: add      r0, r0, #0x800
10002680: str      r1, [sp]
10002684: mov      r3, r2
10002688: mov      r1, ip
1000268c: add      r0, r0, #0x44
10002690: bl       #0x100004b8  ; ->msys::MLytNumRes::set
10002694: mov      r0, #2
10002698: strb     r0, [sp, #0xb1]
1000269c: str      r7, [sp, #0x94]
100026a0: ldr      r0, [r4, #8]
100026a4: cmp      r0, #0
100026a8: bne      #0x100026b8
100026ac: ldr      r0, [pc, #-0x4d0]  ; =0x3f62a8 msys::MComSys::_sys
100026b0: ldr      r0, [r0]
100026b4: str      r0, [r4, #8]
100026b8: add      r2, r0, #0xd3000
100026bc: add      r0, pc, #0xc8
100026c0: mov      r6, #0
100026c4: stm      sp, {r0, r6}
100026c8: add      r0, r4, #0x20000
100026cc: str      r6, [sp, #0xc]
100026d0: ldr      r3, [sp, #0x48]
100026d4: add      r1, sp, #0x80
100026d8: add      r0, r0, #0xb50
100026dc: str      r6, [sp, #8]
100026e0: b        #0x10002790
100026e4: ldrshteq sb, [pc], -r0
100026e8: andeq    r0, r0, r0
100026ec: strbmi   r4, [r4, #-0x146]
100026f0: subeq    r4, lr, pc, asr sb
100026f4: svcpl    #0x544553
100026f8: stmdbmi  lr, {r0, r2, r3, r6, r8, fp, lr} ^
100026fc: strbmi   r4, [sp, #-0x147]
10002700: andeq    r0, r0, r0
10002704: andne    lr, r0, r8, lsl r6
10002708: svcpl    #0x6c6e70
1000270c: stmdbmi  lr, {r0, r2, r3, r6, r8, fp, lr} ^
10002710: strbmi   r4, [sp, #-0x147]
10002714: strbmi   r4, [r5], #-0xd5f
10002718: blmi     #0x117d5824
1000271c: andeq    r0, r0, r0
10002720: svcpl    #0x544553
10002724: ldrbmi   r4, [r3, #-0x142]
10002728: andeq    r0, r0, r0
1000272c: strhne   lr, [r0], -r8
10002730: svcpl    #0x6c6e70
10002734: stmdbmi  lr, {r0, r2, r3, r6, r8, fp, lr} ^
10002738: strbmi   r4, [sp, #-0x147]
1000273c: strbmi   r4, [r5], #-0xd5f
10002740: ldclmi   p12, c4, [pc, #-0x104]
10002744: andeq    r0, r0, ip, asr #32
10002748: svcpl    #0x505845
1000274c: svcpl    #0x4c4e50
10002750: andeq    r0, r0, r5, asr r0
10002754: svcpl    #0x534e49
10002758: svcpl    #0x504f54
1000275c: strbmi   r4, [lr, #-0x150]
10002760: ldrbmi   r5, [r4, #-0xf4c]
10002764: andeq    r5, r0, r8, asr r4
10002768: svcpl    #0x505845
1000276c: svcvs    #0x727261
10002770: svcvs    #0x6c5f77
10002774: andeq    r7, r0, pc, rrx
10002778: svcpl    #0x544553
1000277c: strbmi   r4, [lr, #-0x150]
10002780: mrrcmi   p15, #4, r5, r0, c12
10002784: subeq    r4, r5, r1, asr #28
10002788: andne    r8, r0, r0
1000278c: subeq    r5, sp, lr, asr #10
10002790: str      r0, [sp, #0x7c]
10002794: bl       #0x100004c0  ; ->msys::MLytNum::init
10002798: str      r6, [sp, #4]
1000279c: ldr      r0, [sp, #0x48]
100027a0: ldr      r1, [sp, #0x7c]
100027a4: mov      r3, #0
100027a8: sub      r2, pc, #0x24
100027ac: str      r6, [sp]
100027b0: bl       #0x10000428  ; ->msys::MLyt::attachMChr
100027b4: ldr      r1, [sl, #0xc68]
100027b8: add      r0, r5, r5, lsl #1
100027bc: str      r0, [sp, #8]
100027c0: add      sb, sb, r5, lsl #1
100027c4: add      r0, r1, r0, lsl #3
100027c8: ldrsh    r1, [sb]
100027cc: ldrsh    r2, [r0]
100027d0: cmp      r2, r1
100027d4: mvngt    r1, #0
100027d8: bgt      #0x100027fc
100027dc: ldrsh    r3, [r0, #2]
100027e0: cmp      r3, r1
100027e4: movgt    r1, #0
100027e8: bgt      #0x100027fc
100027ec: ldrsh    r3, [r0, #4]
100027f0: cmp      r3, r1
100027f4: movgt    r1, #1
100027f8: movle    r1, #2
100027fc: cmp      r2, r7
10002800: mvngt    r6, #0
10002804: str      r1, [sp, #0xc]
10002808: bgt      #0x1000282c
1000280c: ldrsh    r2, [r0, #2]
10002810: cmp      r2, r7
10002814: movgt    r6, #0
10002818: bgt      #0x1000282c
1000281c: ldrsh    r1, [r0, #4]
10002820: cmp      r1, r7
10002824: movgt    r6, #1
10002828: movle    r6, #2
1000282c: ldr      r0, [sp, #0x48]
10002830: add      ip, sp, #0x10
10002834: mov      lr, #0
10002838: add      r2, pc, #0x1d4
1000283c: ldr      r1, [r0, #0x150]
10002840: vstr     s16, [sp, #0x14]
10002844: vstr     s17, [sp, #0x18]
10002848: mov      r0, #1
1000284c: vstr     s16, [sp, #0x1c]
10002850: strh     r0, [sp, #0x20]
10002854: sub      r3, pc, #0x174
10002858: mov      r0, ip
1000285c: strh     lr, [sp, #0x22]
10002860: bl       #0x10000468  ; ->ad::lyt::LytAnim::init
10002864: ldrsh    r0, [sb]
10002868: cmp      r7, r0
1000286c: ble      #0x100029fc
10002870: cmp      r7, #0
10002874: vmovle.f32 s0, s16
10002878: addle    r0, sp, #0x10
1000287c: ble      #0x10002910
10002880: ldr      r0, [sp, #0xc]
10002884: cmp      r6, r0
10002888: ble      #0x100028f8
1000288c: ldrb     r0, [r8, #0x70]
10002890: cmp      r0, #0
10002894: ldr      r0, [sp, #8]
10002898: add      r0, r0, r6
1000289c: beq      #0x100028d0
100028a0: sxth     r0, r0
100028a4: str      r0, [sp, #4]
100028a8: ldr      r0, [pc, #-0x1ac]  ; =0x1000e618
100028ac: sxth     r3, r5
100028b0: sub      r1, pc, #0x1b0
100028b4: add      r2, r0, r5, lsl #4
100028b8: mov      r0, r4
100028bc: str      r6, [sp]
100028c0: bl       #0x100065ec
100028c4: nop      
100028c8: nop      
100028cc: b        #0x100028f8
100028d0: add      r0, r0, #0xc
100028d4: sxth     r3, r5
100028d8: sxth     r0, r0
100028dc: str      r0, [sp, #4]
100028e0: ldr      r0, [pc, #-0x1bc]  ; =0x1000e5b8
100028e4: sub      r1, pc, #0x1bc
100028e8: str      r6, [sp]
100028ec: add      r2, r0, r5, lsl #4
100028f0: mov      r0, r4
100028f4: bl       #0x100065ec
100028f8: ldr      r0, [sp, #0x24]
100028fc: add      r6, sp, #0x10
10002900: bl       #0x10000470  ; ->ad::lyt::AnimTransform::GetFrameSize
10002904: vmov     s0, r0
10002908: mov      r0, r6
1000290c: vcvt.f32.u32 s0, s0
10002910: bl       #0x100003b0  ; ->ad::lyt::LytAnim::stopAndSetFrm
10002914: rsb      r0, r5, r5, lsl #3
10002918: strh     r7, [sb]
1000291c: add      r0, r4, r0, lsl #2
10002920: add      r0, r0, #0x20000
10002924: add      r0, r0, #0xfb00
10002928: strh     r7, [r0, #0x14]
1000292c: ldr      r0, [pc, #0xf8]  ; =0x1000805c
10002930: ldm      r0, {r0, r1}
10002934: strd     r0, r1, [fp, #0xc]
10002938: mov      r1, #1
1000293c: add      r0, sp, #0x10
10002940: bl       #0x10000478  ; ->ad::lyt::LytAnim::term
10002944: ldr      r0, [pc, #0xe4]  ; =0x3fbf9c gSndSys
10002948: ldr      r1, [pc, #0xe4]  ; =0x100035b
1000294c: mov      r2, r0
10002950: bl       #0x100004c8  ; ->SndSys::start
10002954: ldr      r1, [pc, #-0x1d4]  ; =0x10008000
10002958: ldrd     r0, r1, [r1, #0x6c]
1000295c: strd     r0, r1, [fp, #4]
10002960: vstr     s16, [sp, #0x1c]
10002964: mov      r1, #0
10002968: mov      r0, r4
1000296c: bl       #0x10003d68
10002970: ldr      r0, [sp, #0xc8]
10002974: nop      
10002978: bl       #0x10000388  ; ->msys::MListWndPBase::getCurNo
1000297c: ldr      r1, [sl, #0xc68]
10002980: add      r0, r0, r0, lsl #1
10002984: add      r0, r1, r0, lsl #3
10002988: ldrh     r0, [r0, #0x12]
1000298c: bl       #0x10000390  ; ->ad::db::GetPcAttack
10002990: ldrh     r0, [r0, #0xe]
10002994: ldr      r1, [pc, #0x9c]  ; =0x7fff87f
10002998: ldr      r2, [pc, #-0x2bc]  ; =0x3f95f0 gGameWork
1000299c: and      r1, r1, r0, lsr #5
100029a0: and      r0, r0, #0x1f
100029a4: add      r1, r2, r1, lsl #2
100029a8: ldr      r1, [r1, #0x20c]
100029ac: lsr      r0, r1, r0
100029b0: tst      r0, #1
100029b4: ldr      r0, [sp, #0xc8]
100029b8: movne    r5, #1
100029bc: moveq    r5, #0
100029c0: bl       #0x10000388  ; ->msys::MListWndPBase::getCurNo
100029c4: ldr      r1, [sl, #0xc68]
100029c8: add      r0, r0, r0, lsl #1
100029cc: mov      r2, r5
100029d0: add      r1, r1, r0, lsl #3
100029d4: ldr      r0, [sp, #0x78]
100029d8: bl       #0x10003b24
100029dc: ldr      r1, [pc, #-0x25c]  ; =0x10008000
100029e0: add      r2, r4, #0x12800
100029e4: add      r2, r2, #0x1fc
100029e8: ldrd     r0, r1, [r1, #0x74]
100029ec: strd     r0, r1, [r2]
100029f0: add      sp, sp, #0xdc
100029f4: vpop     {d8}
100029f8: pop      {r4, r5, r6, r7, r8, sb, sl, fp, pc}
100029fc: vmov.f32 s0, s16
10002a00: add      r0, sp, #0x10
10002a04: bl       #0x100003b0  ; ->ad::lyt::LytAnim::stopAndSetFrm
10002a08: ldr      r1, [pc, #-0x288]  ; =0x10008000
10002a0c: ldrd     r0, r1, [r1, #0x64]
10002a10: b        #0x10002934
10002a14: strbmi   r4, [lr, -r3, asr #30]
10002a18: ldrbpl   r4, [r4, #-0x152]
10002a1c: ldmdbmi  r4, {r2, r3, r6, r8, lr} ^
10002a20: svcpl    #0x534e4f
10002a24: strbmi   r4, [pc], -pc, asr #28
10002a28: andeq    r0, r0, r6, asr #32
10002a2c: andne    r8, r0, ip, asr r0
10002a30: mlaseq   pc, ip, pc, fp
10002a34: qaddeq   r0, fp, r0
10002a38: .word    0x07fff87f
10002a3c: push     {r3, r4, r5, r6, r7, r8, sb, lr}
10002a40: mov      r4, r0
10002a44: add      r0, r0, #0x12800
10002a48: add      r0, r0, #0x32c
10002a4c: mov      sb, r0
10002a50: bl       #0x100004d0  ; ->msys::MLyt::isEnableAnime
10002a54: cmp      r0, #0
10002a58: bne      #0x10002b18
10002a5c: ldr      r0, [pc, #0xb8]  ; =0x288a0
10002a60: ldr      r0, [r0, r4]
10002a64: cmp      r0, #0
10002a68: bne      #0x10002b18
10002a6c: add      r6, r4, #0x44000
10002a70: ldr      r7, [pc, #0xa8]  ; =0x10008000
10002a74: ldr      r0, [r6, #0xc6c]
10002a78: add      r5, r4, #0x10000
10002a7c: add      r5, r5, #0x2a00
10002a80: ldrh     r1, [r0, #0x7a]
10002a84: ldrh     r0, [r0, #0x78]
10002a88: cmp      r1, r0
10002a8c: ldrdlo   r0, r1, [r7, #0xe4]
10002a90: blo      #0x10002b14
10002a94: mov      r8, #0
10002a98: add      r0, r4, #0x12c00
10002a9c: mov      r3, r8
10002aa0: mov      r2, r8
10002aa4: mov      r1, #6
10002aa8: add      r0, r0, #0x2d4
10002aac: str      r8, [sp]
10002ab0: bl       #0x100003e8  ; ->msys::MLyt::playAnimeFromNo
10002ab4: ldr      r0, [r6, #0xc6c]
10002ab8: mvn      r1, #7
10002abc: ldrh     r2, [r0, #0x7a]
10002ac0: add      r2, r2, r2, lsl #1
10002ac4: add      r1, r1, r2, lsl #2
10002ac8: ldr      r0, [r0, r1]
10002acc: cmp      r0, #0
10002ad0: bne      #0x10002af0
10002ad4: add      r0, r4, #0x21000
10002ad8: add      r0, r0, #0x78
10002adc: mov      r6, r0
10002ae0: bl       #0x100004d8  ; ->msys::MDfxChr::term
10002ae4: mov      r1, r6
10002ae8: mov      r0, sb
10002aec: bl       #0x100004e0  ; ->msys::MLyt::detachMChr
10002af0: ldr      r0, [pc, #0x2c]  ; =0x44c6c
10002af4: add      r6, r4, r0
10002af8: ldr      r0, [r6]
10002afc: bl       #0x100004e8  ; ->Mem::Free
10002b00: add      r0, r4, #0x21c00
10002b04: add      r0, r0, #0x1a4
10002b08: str      r8, [r6]
10002b0c: bl       #0x10000400  ; ->Message::close
10002b10: ldrd     r0, r1, [r7, #0xf4]
10002b14: strd     r0, r1, [r5, #4]
10002b18: pop      {r3, r4, r5, r6, r7, r8, sb, pc}
10002b1c: andeq    r8, r2, r0, lsr #17
10002b20: andne    r8, r0, r0
10002b24: andeq    r4, r4, ip, ror #24
10002b28: push     {r3, r4, r5, lr}
10002b2c: mov      r4, r0
10002b30: bl       #0x1000394c
10002b34: mov      r0, #0
10002b38: mov      r3, r0
10002b3c: str      r0, [sp]
10002b40: add      r0, r4, #0x12c00
10002b44: mov      r2, #1
10002b48: mov      r1, #6
10002b4c: add      r0, r0, #0x2d4
10002b50: bl       #0x100003e8  ; ->msys::MLyt::playAnimeFromNo
10002b54: ldr      r0, [pc, #0x10]  ; =0x10008144
10002b58: add      r2, r4, #0x10000
10002b5c: add      r2, r2, #0x2a00
10002b60: ldm      r0, {r0, r1}
10002b64: strd     r0, r1, [r2, #4]
10002b68: pop      {r3, r4, r5, pc}
10002b6c: andne    r8, r0, r4, asr #2
10002b70: push     {r4, lr}
10002b74: mov      r4, r0
10002b78: mvn      r0, #0
10002b7c: bl       #0x100004f0  ; ->Backup::GetSaveData1
10002b80: ldr      r1, [pc, #0x58]  ; =0x3f9dc0
10002b84: mov      r2, #0x40
10002b88: add      r0, r0, #0x7d0
10002b8c: bl       #0x100004f8  ; ->Mem::Copy
10002b90: ldr      r0, [r4, #8]
10002b94: cmp      r0, #0
10002b98: bne      #0x10002ba8
10002b9c: ldr      r0, [pc, #0x40]  ; =0x3f62a8 msys::MComSys::_sys
10002ba0: ldr      r0, [r0]
10002ba4: str      r0, [r4, #8]
10002ba8: ldr      r0, [r0, #4]
10002bac: add      r1, r0, #0x400
10002bb0: add      r1, r1, #0x118
10002bb4: add      r0, r4, #0x10
10002bb8: bl       #0x10000500  ; ->Backup::init
10002bbc: mvn      r1, #0
10002bc0: add      r0, r4, #0x10
10002bc4: bl       #0x10000508  ; ->Backup::writeSaveData0
10002bc8: ldr      r1, [pc, #0x18]  ; =0x1000815c
10002bcc: add      r2, r4, #0x10000
10002bd0: add      r2, r2, #0x2a00
10002bd4: ldm      r1, {r0, r1}
10002bd8: strd     r0, r1, [r2, #4]
10002bdc: pop      {r4, pc}
10002be0: eorseq   sb, pc, r0, asr #27
10002be4: eorseq   r6, pc, r8, lsr #5
10002be8: andne    r8, r0, ip, asr r1
10002bec: push     {r4, r5, r6, lr}
10002bf0: mov      r4, r0
10002bf4: mov      r5, #0
10002bf8: vpush    {d8}
10002bfc: sub      sp, sp, #8
10002c00: add      r0, r0, #0x12800
10002c04: add      r0, r0, #0x32c
10002c08: add      r3, pc, #0xbc
10002c0c: mov      r2, r5
10002c10: mov      r1, #3
10002c14: mov      r6, r0
10002c18: str      r5, [sp]
10002c1c: bl       #0x100003e8  ; ->msys::MLyt::playAnimeFromNo
10002c20: mov      r3, #0
10002c24: mov      r2, r3
10002c28: mov      r1, r3
10002c2c: mov      r0, r6
10002c30: str      r5, [sp]
10002c34: bl       #0x100003e8  ; ->msys::MLyt::playAnimeFromNo
10002c38: mov      r3, #0
10002c3c: add      r0, r4, #0x12c00
10002c40: mov      r2, r3
10002c44: mov      r1, r3
10002c48: add      r0, r0, #0x2d4
10002c4c: str      r5, [sp]
10002c50: bl       #0x100003e8  ; ->msys::MLyt::playAnimeFromNo
10002c54: ldr      r0, [r4, #8]
10002c58: cmp      r0, #0
10002c5c: bne      #0x10002c6c
10002c60: ldr      r0, [pc, #0x70]  ; =0x3f62a8 msys::MComSys::_sys
10002c64: ldr      r0, [r0]
10002c68: str      r0, [r4, #8]
10002c6c: mov      r5, r0
10002c70: mov      r0, #0xff
10002c74: vldr     s16, [pc, #0x64]  ; =0x41800000 (16)
10002c78: rev      r0, r0
10002c7c: add      r6, sp, #4
10002c80: str      r0, [sp, #4]
10002c84: ldr      r0, [pc, #0x50]  ; =0x4acd4
10002c88: vmov.f32 s0, s16
10002c8c: mov      r1, r6
10002c90: add      r0, r0, r5
10002c94: bl       #0x100002e0  ; ->MoveC::moveFrm
10002c98: ldr      r0, [pc, #0x44]  ; =0x4ad14
10002c9c: vmov.f32 s0, s16
10002ca0: mov      r1, r6
10002ca4: add      r0, r0, r5
10002ca8: bl       #0x100002e0  ; ->MoveC::moveFrm
10002cac: ldr      r1, [pc, #0x34]  ; =0x10008000
10002cb0: add      r2, r4, #0x10000
10002cb4: add      r2, r2, #0x2a00
10002cb8: ldrd     r0, r1, [r1, #0xc4]
10002cbc: strd     r0, r1, [r2, #4]
10002cc0: add      sp, sp, #8
10002cc4: vpop     {d8}
10002cc8: pop      {r4, r5, r6, pc}
10002ccc: svcpl    #0x505845
10002cd0: svcpl    #0x4c4e50
10002cd4: andeq    r0, r0, r5, asr r0
10002cd8: eorseq   r6, pc, r8, lsr #5
10002cdc: ldrdeq   sl, fp, [r4], -r4
10002ce0: orrmi    r0, r0, r0
10002ce4: andeq    sl, r4, r4, lsl sp
10002ce8: andne    r8, r0, r0
10002cec: push     {r4, r5, r6, r7, r8, sb, sl, fp, lr}
10002cf0: mov      r4, r0
10002cf4: mov      r5, r1
10002cf8: vpush    {d8}
10002cfc: sub      sp, sp, #0x5c
10002d00: add      r0, sp, #0x10
10002d04: bl       #0x100004b0  ; ->ad::lyt::LytNumReel3::InitParam
10002d08: ldr      fp, [pc, #0x294]  ; =0x3f62a8 msys::MComSys::_sys
10002d0c: ldr      r0, [r5, #8]
10002d10: mov      ip, #0x11
10002d14: add      r1, sp, #0x10
10002d18: cmp      r0, #0
10002d1c: ldreq    r0, [fp]
10002d20: mov      r2, #1
10002d24: mov      r3, #0xe
10002d28: streq    r0, [r5, #8]
10002d2c: add      r0, r0, #0x800
10002d30: add      r0, r0, #0x44
10002d34: str      ip, [sp]
10002d38: bl       #0x100004b8  ; ->msys::MLytNumRes::set
10002d3c: ldr      sb, [pc, #0x264]  ; =0x1000e680
10002d40: mov      r0, #2
10002d44: mov      r8, #0
10002d48: add      sl, r5, #0x12c00
10002d4c: mov      r6, r8
10002d50: add      sl, sl, #0x2d4
10002d54: strb     r0, [sp, #0x41]
10002d58: ldr      r0, [r5, #8]
10002d5c: add      r1, pc, #0x248
10002d60: mov      r3, sl
10002d64: cmp      r0, #0
10002d68: ldreq    r0, [fp]
10002d6c: add      r2, r0, #0xd3000
10002d70: streq    r0, [r5, #8]
10002d74: ldr      r0, [sb, r6, lsl #2]
10002d78: stm      sp, {r0, r1, r8}
10002d7c: rsb      r0, r6, r6, lsl #3
10002d80: add      r1, sp, #0x10
10002d84: add      r0, r0, r0, lsl #2
10002d88: str      r8, [sp, #0xc]
10002d8c: add      r7, r4, r0, lsl #4
10002d90: mov      r0, r7
10002d94: bl       #0x100004c0  ; ->msys::MLytNum::init
10002d98: str      r8, [sp]
10002d9c: str      r8, [sp, #4]
10002da0: ldr      r2, [sb, r6, lsl #2]
10002da4: mov      r1, r7
10002da8: add      r3, pc, #0x1fc
10002dac: mov      r0, sl
10002db0: bl       #0x10000428  ; ->msys::MLyt::attachMChr
10002db4: add      r6, r6, #1
10002db8: cmp      r6, #3
10002dbc: blt      #0x10002d58
10002dc0: add      r0, r5, #0x12800
10002dc4: add      r0, r0, #0x32c
10002dc8: str      r0, [sp, #8]
10002dcc: ldr      r1, [r0, #0x150]
10002dd0: add      r0, r4, #0x400
10002dd4: add      r3, pc, #0x1e4
10002dd8: add      r2, pc, #0x1f0
10002ddc: add      r0, r0, #0x2c8
10002de0: bl       #0x10000468  ; ->ad::lyt::LytAnim::init
10002de4: ldr      r1, [sl, #0x150]
10002de8: add      r3, pc, #0x1bc
10002dec: add      r2, pc, #0x1e4
10002df0: add      r0, r4, #0x690
10002df4: bl       #0x10000468  ; ->ad::lyt::LytAnim::init
10002df8: add      r0, r4, #0x400
10002dfc: ldr      r1, [sl, #0x150]
10002e00: add      r3, pc, #0x1a4
10002e04: add      r2, pc, #0x1d8
10002e08: add      r0, r0, #0x2ac
10002e0c: bl       #0x10000468  ; ->ad::lyt::LytAnim::init
10002e10: add      r0, r4, #0x400
10002e14: add      r1, r5, #0x12800
10002e18: add      r0, r0, #0x2e4
10002e1c: add      r1, r1, #0x2e8
10002e20: mov      r6, r0
10002e24: bl       #0x10000510  ; ->msys::MCellAnime::init
10002e28: mov      r3, #0
10002e2c: add      r2, pc, #0x1bc
10002e30: mov      r1, r6
10002e34: mov      r0, sl
10002e38: str      r8, [sp]
10002e3c: str      r8, [sp, #4]
10002e40: bl       #0x10000428  ; ->msys::MLyt::attachMChr
10002e44: ldr      r0, [r5, #4]
10002e48: mov      r2, #0x400
10002e4c: add      r3, r4, #0x7000
10002e50: vldr     s16, [pc, #0x1a4]  ; =0x0 (0)
10002e54: ldr      r1, [r0, #0x18]
10002e58: add      r0, r4, #0x7000
10002e5c: add      r0, r0, #0x5a0
10002e60: add      r3, r3, #0x560
10002e64: str      r2, [r0], #-0xc
10002e68: add      r6, r4, #0x960
10002e6c: stm      r0, {r1, r8}
10002e70: add      r0, r4, #0x800
10002e74: vstr     s16, [r3, #0x3c]
10002e78: add      r0, r0, #0x2ac
10002e7c: bl       #0x10000430  ; ->MessageSimple::init
10002e80: mov      r0, r6
10002e84: nop      
10002e88: bl       #0x100039d8
10002e8c: ldr      r1, [pc, #0x16c]  ; =0x62d4
10002e90: add      r6, r4, #0x6800
10002e94: ldr      sb, [pc, #0x168]  ; =0x3fc0f8
10002e98: add      r6, r6, #0x2ac
10002e9c: mov      fp, #3
10002ea0: strb     fp, [r6, #0xad8]
10002ea4: add      r0, r4, #0x800
10002ea8: str      sb, [r1, r4]
10002eac: add      r0, r0, #0x2ac
10002eb0: mov      r2, #1
10002eb4: mvn      r1, #0
10002eb8: bl       #0x10000518  ; ->MessageWriter::setFontColor
10002ebc: add      r0, r4, #0x6000
10002ec0: mov      r7, #1
10002ec4: strb     r7, [r0, #0x568]
10002ec8: strb     r7, [r0, #0x569]
10002ecc: strb     r7, [r6, #0xad9]
10002ed0: ldr      r0, [sp, #8]
10002ed4: add      r3, pc, #0xe4
10002ed8: add      r2, pc, #0x128
10002edc: add      r1, r4, #0x960
10002ee0: str      r8, [sp]
10002ee4: str      r8, [sp, #4]
10002ee8: bl       #0x10000428  ; ->msys::MLyt::attachMChr
10002eec: ldr      r0, [r5, #4]
10002ef0: orr      r2, r7, r7, lsl #10
10002ef4: add      r3, r4, #0xe000
10002ef8: add      r3, r3, #0x1a4
10002efc: ldr      r1, [r0, #0x18]
10002f00: add      r0, r4, #0xe000
10002f04: add      r0, r0, #0x1e4
10002f08: add      r6, r4, #0x7400
10002f0c: str      r2, [r0], #-0xc
10002f10: add      r6, r6, #0x1a4
10002f14: stm      r0, {r1, r8}
10002f18: add      r0, r4, #0x7000
10002f1c: vstr     s16, [r3, #0x3c]
10002f20: add      r0, r0, #0x6f0
10002f24: bl       #0x10000430  ; ->MessageSimple::init
10002f28: mov      r0, r6
10002f2c: nop      
10002f30: bl       #0x100039d8
10002f34: ldr      r1, [pc, #0xe0]  ; =0xcf18
10002f38: add      r5, r4, #0xd000
10002f3c: add      r5, r5, #0x6f0
10002f40: add      r0, r4, #0x7000
10002f44: strb     fp, [r5, #0xad8]
10002f48: str      sb, [r1, r4]
10002f4c: ldr      r1, [pc, #0xcc]  ; =0xe6e6e6ff
10002f50: add      r0, r0, #0x6f0
10002f54: mov      r2, #1
10002f58: bl       #0x10000518  ; ->MessageWriter::setFontColor
10002f5c: add      r0, r4, #0xd000
10002f60: mov      r3, #0
10002f64: strb     r8, [r0, #0x1ac]
10002f68: strb     r7, [r0, #0x1ad]
10002f6c: strb     r7, [r5, #0xad9]
10002f70: add      r2, pc, #0x78
10002f74: mov      r1, r6
10002f78: mov      r0, sl
10002f7c: str      r8, [sp]
10002f80: str      r8, [sp, #4]
10002f84: bl       #0x10000428  ; ->msys::MLyt::attachMChr
10002f88: ldr      r0, [pc, #0x94]  ; =0x14e2c
10002f8c: orr      r1, r0, r0, asr #13
10002f90: strh     r8, [r0, r4]
10002f94: strb     r7, [r1, r4]
10002f98: add      sp, sp, #0x5c
10002f9c: vpop     {d8}
10002fa0: pop      {r4, r5, r6, r7, r8, sb, sl, fp, pc}
10002fa4: eorseq   r6, pc, r8, lsr #5
10002fa8: andne    lr, r0, r0, lsl #13
10002fac: svcpl    #0x6c6e70
10002fb0: stmdbmi  lr, {r0, r2, r3, r6, r8, fp, lr} ^
10002fb4: strbmi   r4, [sp, #-0x147]
10002fb8: cmpmi    r3, #0x17c0
10002fbc: subeq    r5, r5, pc, asr #4
10002fc0: svcpl    #0x6c6e70
10002fc4: svcpl    #0x4b4c4d
10002fc8: movtmi   r5, #0x5053
10002fcc: subeq    r4, ip, sb, asr #2
10002fd0: svcpl    #0x544553
10002fd4: subeq    r4, r7, sb, asr #26
10002fd8: svcpl    #0x544553
10002fdc: .word    0x4144454d
10002fe0: andeq    r0, r0, ip, asr #32
10002fe4: .word    0x4144454d
10002fe8: cdpmi    p15, #4, c5, c15, c12, #2
10002fec: subeq    r4, r6, pc, asr #12
10002ff0: svcpl    #0x534e49
10002ff4: mrrcmi   p9, #5, r4, r4, c4
10002ff8: andeq    r0, r0, r5, asr #32
10002ffc: andeq    r0, r0, r0
10003000: ldrdeq   r6, r7, [r0], -r4
10003004: ldrshteq ip, [pc], -r8
10003008: svcpl    #0x534e49
1000300c: cmpmi    r4, r1, asr #8
10003010: ldrbpl   r4, [pc], #-0xb43
10003014: strbmi   r5, [ip, #-0x449]
10003018: andeq    r0, r0, r0
1000301c: andeq    ip, r0, r8, lsl pc
10003020: .word    0xe6e6e6ff
10003024: andeq    r4, r1, ip, lsr #28
10003028: ldr      r1, [pc, #0x10]  ; =0x13254
1000302c: ldrb     r1, [r1, r0]
10003030: cmp      r1, #0
10003034: beq      #0x1000303c
10003038: b        #0x10001df8
1000303c: bx       lr
10003040: andeq    r3, r1, r4, asr r2
10003044: push     {r3, r4, r5, r6, r7, lr}
10003048: mov      r5, #0
1000304c: mov      r4, r0
10003050: add      r0, r0, #0x12800
10003054: mov      r3, r5
10003058: mov      r2, r5
1000305c: mov      r1, #2
10003060: add      r0, r0, #0x32c
10003064: str      r5, [sp]
10003068: bl       #0x100003e8  ; ->msys::MLyt::playAnimeFromNo
1000306c: add      r0, r4, #0x12c00
10003070: mov      r3, #0
10003074: add      r0, r0, #0x2d4
10003078: mov      r2, r3
1000307c: mov      r1, #2
10003080: mov      r6, r0
10003084: str      r5, [sp]
10003088: bl       #0x100003e8  ; ->msys::MLyt::playAnimeFromNo
1000308c: mov      r3, #0
10003090: mov      r2, #1
10003094: mov      r1, #5
10003098: mov      r0, r6
1000309c: str      r5, [sp]
100030a0: bl       #0x100003e8  ; ->msys::MLyt::playAnimeFromNo
100030a4: ldr      r1, [pc, #0x10]  ; =0x10008000
100030a8: add      r2, r4, #0x10000
100030ac: add      r2, r2, #0x2a00
100030b0: ldrd     r0, r1, [r1, #0xd4]
100030b4: strd     r0, r1, [r2, #4]
100030b8: pop      {r3, r4, r5, r6, r7, pc}
100030bc: andne    r8, r0, r0
100030c0: push     {r4, r5, r6, lr}
100030c4: mov      r4, r0
100030c8: add      r0, r0, #0x12800
100030cc: mov      r3, #0
100030d0: add      r0, r0, #0x32c
100030d4: mov      r2, r3
100030d8: add      r1, pc, #0x84
100030dc: mov      r5, r0
100030e0: bl       #0x100003c0  ; ->msys::MLyt::createAnimeAutoSlot
100030e4: add      r0, r4, #0x12c00
100030e8: mov      r3, #0
100030ec: add      r0, r0, #0x2d4
100030f0: mov      r2, r3
100030f4: add      r1, pc, #0x68
100030f8: mov      r6, r0
100030fc: bl       #0x100003c0  ; ->msys::MLyt::createAnimeAutoSlot
10003100: mov      r2, #1
10003104: mov      r1, #0
10003108: mov      r0, r5
1000310c: bl       #0x10000460  ; ->msys::MLyt::setAnimeInfo
10003110: mov      r2, #1
10003114: mov      r1, #0
10003118: mov      r0, r6
1000311c: bl       #0x10000460  ; ->msys::MLyt::setAnimeInfo
10003120: ldr      r0, [pc, #0x44]  ; =0x3fbf9c gSndSys
10003124: mov      r1, #0x10
10003128: bl       #0x10000520  ; ->SndSys::stopAllBgm
1000312c: bl       #0x10000490  ; ->atk_mg::GetBootInfo
10003130: bl       #0x10000528  ; ->atk_mg::BootInfo::restoreBgm
10003134: ldr      r0, [pc, #0x34]  ; =0x28cd1
10003138: mov      r1, #1
1000313c: strb     r1, [r0, r4]
10003140: mov      r1, #0
10003144: mov      r0, r4
10003148: bl       #0x10003d68
1000314c: ldr      r1, [pc, #0x20]  ; =0x10008194
10003150: add      r2, r4, #0x10000
10003154: add      r2, r2, #0x2a00
10003158: ldm      r1, {r0, r1}
1000315c: strd     r0, r1, [r2, #4]
10003160: pop      {r4, r5, r6, pc}
10003164: svcvs    #0x745f35
10003168: andeq    r3, r0, pc, asr r1
1000316c: mlaseq   pc, ip, pc, fp
10003170: ldrdeq   r8, sb, [r2], -r1
10003174: mulne    r0, r4, r1
10003178: push     {r4, r5, r6, r7, r8, sb, lr}
1000317c: mov      r4, r0
10003180: add      r0, r0, #0x13000
10003184: sub      sp, sp, #0xc
10003188: ldr      r0, [r0, #0x25c]
1000318c: mov      r6, r1
10003190: ldrh     r0, [r0, #0x10]
10003194: cmp      r0, #1
10003198: bne      #0x10003298
1000319c: add      r0, r4, #0x12c00
100031a0: add      r0, r0, #0x2d4
100031a4: mov      r1, #4
100031a8: mov      r7, r0
100031ac: bl       #0x10000530  ; ->msys::MLyt::isBusyTblAnime
100031b0: cmp      r0, #0
100031b4: bne      #0x100032e4
100031b8: ldr      r1, [pc, #0x12c]  ; =0x3f62a8 msys::MComSys::_sys
100031bc: ldr      r0, [r4, #8]
100031c0: ldr      r2, [pc, #0x128]  ; =0x4aba4
100031c4: cmp      r0, #0
100031c8: ldreq    r0, [r1]
100031cc: streq    r0, [r4, #8]
100031d0: cmp      r0, #0
100031d4: add      r3, r0, r2
100031d8: ldreq    r0, [r1]
100031dc: streq    r0, [r4, #8]
100031e0: add      r0, r0, #0xe6000
100031e4: ldr      r2, [r0, #0x4f0]
100031e8: ldr      r0, [r4, #4]
100031ec: ldr      r1, [r0, #0x18]
100031f0: ldr      r0, [pc, #0xfc]  ; =0x401
100031f4: str      r0, [sp]
100031f8: add      r0, r4, #0x21000
100031fc: add      r0, r0, #0x1f4
10003200: mov      sb, r0
10003204: bl       #0x10000538  ; ->msys::MDfxChr::init
10003208: mov      r1, #0x2f
1000320c: mov      r0, sb
10003210: bl       #0x10000540  ; ->msys::MDfxChr::playDfx
10003214: ldr      r0, [pc, #0xdc]  ; =0x3f7eec _ZGVZN2nn4math4VEC34ZeroEvE4zero
10003218: add      r5, r4, #0x20000
1000321c: add      r5, r5, #0x12c0
10003220: ldrb     r0, [r0]
10003224: tst      r0, #1
10003228: bne      #0x10003258
1000322c: ldr      r0, [pc, #0xc4]  ; =0x3f7eec _ZGVZN2nn4math4VEC34ZeroEvE4zero
10003230: bl       #0x10000548  ; ->__cxa_guard_acquire
10003234: cmp      r0, #0
10003238: beq      #0x10003258
1000323c: ldr      r0, [pc, #0xbc]  ; =0x434c48 _ZZN2nn4math4VEC34ZeroEvE4zero
10003240: vldr     s0, [pc, #0xb4]  ; =0x0 (0)
10003244: vstr     s0, [r0]
10003248: vstr     s0, [r0, #4]
1000324c: vstr     s0, [r0, #8]
10003250: ldr      r0, [pc, #0xa0]  ; =0x3f7eec _ZGVZN2nn4math4VEC34ZeroEvE4zero
10003254: bl       #0x10000550  ; ->__cxa_guard_release
10003258: ldr      r8, [pc, #0xa0]  ; =0x434c48 _ZZN2nn4math4VEC34ZeroEvE4zero
1000325c: mov      r0, r5
10003260: bl       #0x100002d8  ; ->MoveVBase::stop
10003264: ldm      r8, {r0, r1, r2}
10003268: add      r3, r5, #0x1c
1000326c: add      r5, r5, #4
10003270: stm      r3, {r0, r1, r2}
10003274: stm      r5, {r0, r1, r2}
10003278: mov      r0, #0
1000327c: mov      r3, r0
10003280: str      r0, [sp]
10003284: str      r0, [sp, #4]
10003288: add      r2, pc, #0x74
1000328c: mov      r1, sb
10003290: mov      r0, r7
10003294: bl       #0x10000428  ; ->msys::MLyt::attachMChr
10003298: ldr      r0, [pc, #0x7c]  ; =0x10008000
1000329c: add      r3, r4, #0x10000
100032a0: add      r3, r3, #0x2a00
100032a4: mov      r1, r6
100032a8: ldr      r2, [r0, #0x13c]
100032ac: ldr      r0, [r0, #0x140]
100032b0: str      r2, [r3, #4]
100032b4: add      r2, r4, #0x12000
100032b8: tst      r0, #1
100032bc: str      r0, [r3, #8]
100032c0: ldreq    r2, [r2, #0xa04]
100032c4: add      r0, r4, r0, asr #1
100032c8: beq      #0x100032d8
100032cc: ldr      r3, [r0]
100032d0: ldr      r2, [r2, #0xa04]
100032d4: ldr      r2, [r3, r2]
100032d8: add      sp, sp, #0xc
100032dc: pop      {r4, r5, r6, r7, r8, sb, lr}
100032e0: bx       r2
100032e4: add      sp, sp, #0xc
100032e8: pop      {r4, r5, r6, r7, r8, sb, pc}
100032ec: eorseq   r6, pc, r8, lsr #5
100032f0: andeq    sl, r4, r4, lsr #23
100032f4: andeq    r0, r0, r1, lsl #8
100032f8: eorseq   r7, pc, ip, ror #29
100032fc: andeq    r0, r0, r0
10003300: subeq    r4, r3, r8, asr #24
10003304: svcpl    #0x534e49
10003308: .word    0x4144454d
1000330c: strbmi   r5, [r5], -ip, asr #30
10003310: strbpl   r4, [r3], #-0x546
10003314: subpl    r5, pc, pc, asr r4
10003318: andeq    r0, r0, r0
1000331c: andne    r8, r0, r0
10003320: push     {r4, r5, r6, lr}
10003324: mov      r4, r0
10003328: mov      r5, #0
1000332c: vpush    {d8}
10003330: sub      sp, sp, #8
10003334: add      r0, r0, #0x12800
10003338: mov      r3, r5
1000333c: mov      r2, #1
10003340: mov      r1, #2
10003344: add      r0, r0, #0x32c
10003348: str      r5, [sp]
1000334c: bl       #0x100003e8  ; ->msys::MLyt::playAnimeFromNo
10003350: add      r0, r4, #0x12c00
10003354: mov      r3, #0
10003358: mov      r2, #1
1000335c: mov      r1, #2
10003360: add      r0, r0, #0x2d4
10003364: str      r5, [sp]
10003368: bl       #0x100003e8  ; ->msys::MLyt::playAnimeFromNo
1000336c: ldr      r0, [pc, #0x7c]  ; =0x3fbf9c gSndSys
10003370: mov      r1, #0x10
10003374: bl       #0x10000520  ; ->SndSys::stopAllBgm
10003378: ldr      r0, [r4, #8]
1000337c: cmp      r0, #0
10003380: bne      #0x10003390
10003384: ldr      r0, [pc, #0x68]  ; =0x3f62a8 msys::MComSys::_sys
10003388: ldr      r0, [r0]
1000338c: str      r0, [r4, #8]
10003390: mov      r5, r0
10003394: mov      r0, #0xff
10003398: vldr     s16, [pc, #0x5c]  ; =0x41800000 (16)
1000339c: rev      r0, r0
100033a0: add      r6, sp, #4
100033a4: str      r0, [sp, #4]
100033a8: ldr      r0, [pc, #0x48]  ; =0x4acd4
100033ac: vmov.f32 s0, s16
100033b0: mov      r1, r6
100033b4: add      r0, r0, r5
100033b8: bl       #0x100002e0  ; ->MoveC::moveFrm
100033bc: ldr      r0, [pc, #0x3c]  ; =0x4ad14
100033c0: vmov.f32 s0, s16
100033c4: mov      r1, r6
100033c8: add      r0, r0, r5
100033cc: bl       #0x100002e0  ; ->MoveC::moveFrm
100033d0: ldr      r1, [pc, #0x2c]  ; =0x10008114
100033d4: add      r2, r4, #0x10000
100033d8: add      r2, r2, #0x2a00
100033dc: ldm      r1, {r0, r1}
100033e0: strd     r0, r1, [r2, #4]
100033e4: add      sp, sp, #8
100033e8: vpop     {d8}
100033ec: pop      {r4, r5, r6, pc}
100033f0: mlaseq   pc, ip, pc, fp
100033f4: eorseq   r6, pc, r8, lsr #5
100033f8: ldrdeq   sl, fp, [r4], -r4
100033fc: orrmi    r0, r0, r0
10003400: andeq    sl, r4, r4, lsl sp
10003404: andne    r8, r0, r4, lsl r1
10003408: push     {r4, r5, r6, lr}
1000340c: mov      r4, r0
10003410: add      r0, r0, #0x21c00
10003414: mov      r2, #0
10003418: add      r1, pc, #0x54
1000341c: add      r0, r0, #0x58
10003420: bl       #0x100038e0
10003424: mov      r5, #0
10003428: add      r0, r4, r5, lsl #2
1000342c: add      r0, r0, #0x13000
10003430: ldr      r0, [r0, #0x2b8]
10003434: ldr      r1, [r0]
10003438: ldr      r2, [r1, #0x28]
1000343c: mov      r1, #0
10003440: blx      r2
10003444: add      r5, r5, #1
10003448: cmp      r5, #4
1000344c: blt      #0x10003428
10003450: mov      r1, #0
10003454: mov      r0, r4
10003458: bl       #0x10003d68
1000345c: ldr      r1, [pc, #0x24]  ; =0x1000819c
10003460: add      r2, r4, #0x10000
10003464: add      r2, r2, #0x2a00
10003468: ldm      r1, {r0, r1}
1000346c: strd     r0, r1, [r2, #4]
10003470: pop      {r4, r5, r6, pc}
10003474: strbvc   r6, [lr, #-0x56d]!
10003478: uqsaxvc  r7, r1, pc
1000347c: rsbvc    r5, r5, #0x194
10003480: teqlo    r0, r2, ror pc
10003484: andeq    r0, r0, r0
10003488: mulne    r0, ip, r1
1000348c: push     {r3, r4, r5, r6, r7, lr}
10003490: mov      r4, r0
10003494: add      r0, r0, #0x12c00
10003498: add      r0, r0, #0x2d4
1000349c: mov      r5, r0
100034a0: bl       #0x100004d0  ; ->msys::MLyt::isEnableAnime
100034a4: cmp      r0, #0
100034a8: bne      #0x100034fc
100034ac: mov      r6, #0
100034b0: mov      r3, r6
100034b4: mov      r2, r6
100034b8: mov      r1, #5
100034bc: mov      r0, r5
100034c0: str      r6, [sp]
100034c4: bl       #0x100003e8  ; ->msys::MLyt::playAnimeFromNo
100034c8: add      r5, r4, #0x44000
100034cc: ldr      r0, [r5, #0xc5c]
100034d0: bl       #0x10000558  ; ->ad::lyt::LytAnim::stop
100034d4: ldr      r0, [r5, #0xc5c]
100034d8: mov      r1, #1
100034dc: bl       #0x10000478  ; ->ad::lyt::LytAnim::term
100034e0: add      r0, r4, #0x12800
100034e4: add      r0, r0, #0x20c
100034e8: str      r6, [r5, #0xc5c]
100034ec: ldm      r0, {r1, r2}
100034f0: add      r0, r4, #0x12800
100034f4: add      r0, r0, #0x204
100034f8: stm      r0, {r1, r2}
100034fc: pop      {r3, r4, r5, r6, r7, pc}
10003500: push     {r3, r4, r5, r6, r7, lr}
10003504: mov      r5, r0
10003508: add      r4, r5, #0x13000
1000350c: ldr      r0, [r1]
10003510: ldr      r2, [pc, #0xb8]  ; =0x802
10003514: ldr      r1, [pc, #0xb8]  ; =0x110015
10003518: add      r4, r4, #0x27c
1000351c: tst      r0, r2
10003520: mov      r6, #0
10003524: beq      #0x10003554
10003528: ldr      r2, [pc, #0xa8]  ; =0x13294
1000352c: ldrb     r2, [r2, r5]
10003530: cmp      r2, #0
10003534: beq      #0x10003554
10003538: mov      r3, #0
1000353c: mov      r2, r3
10003540: mov      r0, r5
10003544: str      r6, [sp]
10003548: bl       #0x10003dd4
1000354c: strb     r6, [r4, #0x18]
10003550: b        #0x100035c4
10003554: ldr      r2, [pc, #0x80]  ; =0x401
10003558: tst      r0, r2
1000355c: beq      #0x10003594
10003560: ldrsb    r0, [r4, #0x18]
10003564: add      r0, r5, r0, lsl #2
10003568: add      r0, r0, #0x13000
1000356c: ldr      r0, [r0, #0x2b8]
10003570: ldr      r1, [r0]
10003574: ldr      r1, [r1, #0x10]
10003578: blx      r1
1000357c: mov      r1, #0
10003580: mov      r0, r5
10003584: bl       #0x10003d68
10003588: nop      
1000358c: nop      
10003590: b        #0x100035c4
10003594: tst      r0, #0x30
10003598: beq      #0x100035c4
1000359c: mov      r3, #0
100035a0: mov      r2, r3
100035a4: mov      r0, r5
100035a8: str      r6, [sp]
100035ac: bl       #0x10003dd4
100035b0: ldrb     r0, [r4, #0x18]
100035b4: cmp      r0, #0
100035b8: moveq    r0, #1
100035bc: movne    r0, #0
100035c0: strb     r0, [r4, #0x18]
100035c4: mov      r0, r4
100035c8: bl       #0x10003648
100035cc: pop      {r3, r4, r5, r6, r7, pc}
100035d0: andeq    r0, r0, r2, lsl #16
100035d4: andseq   r0, r1, r5, lsl r0
100035d8: muleq    r1, r4, r2
100035dc: andeq    r0, r0, r1, lsl #8
100035e0: mov      r2, #0
100035e4: add      r1, r0, #4
100035e8: vldr     s0, [pc, #0x24]  ; =0x0 (0)
100035ec: vldr     s1, [pc, #0x24]  ; =0x3f800000 (1)
100035f0: strb     r2, [r0]
100035f4: mov      r3, #1
100035f8: vstmia   r1, {s0, s1}
100035fc: vstr     s0, [r0, #0xc]
10003600: strh     r3, [r0, #0x10]
10003604: strh     r2, [r0, #0x12]
10003608: str      r2, [r0, #0x14]
1000360c: str      r2, [r0, #0x18]
10003610: bx       lr
10003614: andeq    r0, r0, r0
10003618: svclo    #0x800000
1000361c: push     {r0, r1, r2, r3}
10003620: push     {r4, lr}
10003624: add      r4, r2, #1
10003628: ldr      ip, [sp, #0x14]
1000362c: cmp      r1, r4
10003630: add      r3, sp, #0x18
10003634: movhi    r1, r4
10003638: mov      r2, ip
1000363c: bl       #0x10000560  ; ->__c89vswprintf
10003640: pop      {r4}
10003644: ldr      pc, [sp], #0x14
10003648: ldr      r1, [r0, #4]
1000364c: cmp      r1, #0
10003650: bxeq     lr
10003654: push     {r4, r5, r6, r7, r8, sb, sl, fp, lr}
10003658: mov      r5, r0
1000365c: vpush    {d8, d9}
10003660: sub      sp, sp, #0x34
10003664: ldrsb    r0, [r0, #0x18]
10003668: cmp      r0, #0
1000366c: blt      #0x100038b4
10003670: ldrsb    r2, [r5, #0x19]
10003674: mov      sl, #1
10003678: cmp      r0, r2
1000367c: beq      #0x10003840
10003680: strb     r0, [r5, #0x19]
10003684: ldr      r7, [r1, #0x150]
10003688: add      r1, r5, #0x30
1000368c: ldr      r4, [r5, #0x10]
10003690: ldr      sb, [r1, r0, lsl #2]
10003694: add      r0, r5, #0x10
10003698: cmp      r4, r0
1000369c: add      r6, r5, #0xc
100036a0: add      fp, sb, #0x80
100036a4: mov      r8, #0
100036a8: beq      #0x100036d4
100036ac: ldr      r0, [r4, #8]
100036b0: mov      r1, fp
100036b4: bl       #0x10000568  ; ->strcmp
100036b8: cmp      r0, #0
100036bc: nop      
100036c0: beq      #0x100038c0
100036c4: ldr      r4, [r4]
100036c8: add      r0, r6, #4
100036cc: cmp      r4, r0
100036d0: bne      #0x100036ac
100036d4: ldr      r1, [pc, #0x1ec]  ; =0x3f7fab _ZZN4msys7MCursorILj3EE6updateEvEs
100036d8: mov      r0, r8
100036dc: bl       #0x10000570  ; ->msys::MCtrlUserData::findExtUserDataByName
100036e0: mov      r6, r0
100036e4: ldr      r0, [sb, #0xac]
100036e8: ldr      r1, [r8, #0xc]
100036ec: vldr     s16, [sb, #0x54]
100036f0: vldr     s17, [sb, #0x64]
100036f4: ldr      r0, [r0, #0x10]
100036f8: vldr     s19, [sb, #0x74]
100036fc: ldr      r2, [r0]
10003700: ldr      r3, [r2, #0x2c]
10003704: mov      r2, #1
10003708: blx      r3
1000370c: cmp      r0, #0
10003710: addne    r0, r0, #0x3c
10003714: ldr      r2, [pc, #0x1b4]  ; =0x3e4ca4 __ARM__ZN4msys7MCursorILj3EE6updateEv_anon0
10003718: ldmne    r0, {r0, r1}
1000371c: add      sb, sp, #0x18
10003720: vldreq   s0, [pc, #0x1a4]  ; =0x0 (0)
10003724: mov      r4, #0
10003728: strdne   r0, r1, [r5, #0x1c]
1000372c: vstreq   s0, [r5, #0x20]
10003730: vstreq   s0, [r5, #0x1c]
10003734: ldr      r0, [r2], #4
10003738: ldr      r3, [r6, #4]
1000373c: ldm      r2, {r1, r2}
10003740: add      r8, sp, #0x24
10003744: add      r6, r6, r3
10003748: stm      sb, {r0, r1, r2}
1000374c: ldr      r0, [r7, #0x10]
10003750: ldr      r1, [sb, r4, lsl #2]
10003754: ldr      r2, [r0]
10003758: ldr      r3, [r2, #0x2c]
1000375c: mov      r2, #1
10003760: blx      r3
10003764: mov      r1, r0
10003768: str      r1, [r8, r4, lsl #2]
1000376c: ldrb     r1, [r0, #0x44]!
10003770: add      r4, r4, #1
10003774: cmp      r4, #3
10003778: and      r1, r1, #0xfe
1000377c: strb     r1, [r0]
10003780: blt      #0x1000374c
10003784: ldr      r4, [pc, #0x148]  ; =0x3e4cb0 __ARM__ZN4msys7MCursorILj3EE6updateEv_anon1
10003788: ldm      r4, {r0, r1, r2, r3, r4, ip}
1000378c: stm      sp, {r0, r1, r2, r3, r4, ip}
10003790: ldr      r0, [r6]
10003794: ldr      r0, [r8, r0, lsl #2]
10003798: str      r0, [r5, #8]
1000379c: ldrb     r1, [r0, #0x44]
100037a0: and      r1, r1, #0xfe
100037a4: orr      r1, r1, #1
100037a8: strb     r1, [r0, #0x44]
100037ac: ldr      r1, [r6]
100037b0: mov      r0, sp
100037b4: vldr     s0, [r6, #0xc]
100037b8: vldr     s1, [r5, #0x1c]
100037bc: add      r1, r0, r1, lsl #3
100037c0: vcvt.f32.s32 s0, s0
100037c4: vldr     s2, [r1]
100037c8: vadd.f32 s1, s1, s2
100037cc: vadd.f32 s0, s1, s0
100037d0: vstr     s0, [r5, #0x1c]
100037d4: ldr      r1, [r6]
100037d8: vldr     s0, [r6, #0x10]
100037dc: vldr     s1, [r5, #0x20]
100037e0: add      r0, r0, r1, lsl #3
100037e4: vcvt.f32.s32 s0, s0
100037e8: vldr     s2, [r0, #4]
100037ec: vadd.f32 s1, s1, s2
100037f0: vadd.f32 s0, s1, s0
100037f4: vldr     s1, [pc, #0xdc]  ; =0x3f800000 (1)
100037f8: vstr     s0, [r5, #0x20]
100037fc: vldr     s2, [r6, #4]
10003800: vldr     s0, [r6, #8]
10003804: ldr      r0, [r5, #4]
10003808: vcvt.f32.s32 s2, s2
1000380c: vcvt.f32.s32 s0, s0
10003810: add      r4, r0, #0xcc
10003814: mov      r0, r4
10003818: vadd.f32 s18, s16, s2
1000381c: vadd.f32 s17, s17, s0
10003820: vadd.f32 s16, s19, s1
10003824: bl       #0x100002d8  ; ->MoveVBase::stop
10003828: vstr     s18, [r4, #0x1c]
1000382c: vstr     s17, [r4, #0x20]
10003830: vstr     s16, [r4, #0x24]
10003834: vstr     s18, [r4, #4]
10003838: vstr     s17, [r4, #8]
1000383c: vstr     s16, [r4, #0xc]
10003840: ldrsh    r0, [r5, #0x1a]
10003844: vldr     s3, [r5, #0x2c]
10003848: vldr     s1, [r5, #0x1c]
1000384c: vmov     s2, r0
10003850: vldr     s0, [r5, #0x20]
10003854: vcvt.f32.s32 s2, s2
10003858: vsub.f32 s2, s2, s3
1000385c: vcvt.s32.f32 s2, s2
10003860: vmov     r0, s2
10003864: sxth     r0, r0
10003868: cmp      r0, #0
1000386c: strh     r0, [r5, #0x1a]
10003870: movlt    r0, #0x1e
10003874: strhlt   r0, [r5, #0x1a]
10003878: blt      #0x10003890
1000387c: cmp      r0, #0xf
10003880: bge      #0x10003890
10003884: vldr     s2, [pc, #0x50]  ; =0x40000000 (2)
10003888: vadd.f32 s1, s1, s2
1000388c: vadd.f32 s0, s0, s2
10003890: ldr      r0, [r5, #8]
10003894: vstr     s1, [r0, #0x3c]
10003898: vstr     s0, [r0, #0x40]
1000389c: ldrb     r1, [r0, #0x44]
100038a0: and      r1, r1, #0xef
100038a4: orr      r1, r1, #0x10
100038a8: strb     r1, [r0, #0x44]
100038ac: ldr      r0, [r5, #4]
100038b0: strb     sl, [r0, #0x374]
100038b4: add      sp, sp, #0x34
100038b8: vpop     {d8, d9}
100038bc: pop      {r4, r5, r6, r7, r8, sb, sl, fp, pc}
100038c0: mov      r8, r4
100038c4: b        #0x100036d4
100038c8: eorseq   r7, pc, fp, lsr #31
100038cc: andeq    r0, r0, r0
100038d0: eorseq   r4, lr, r4, lsr #25
100038d4: ldrhteq  r4, [lr], -r0
100038d8: svclo    #0x800000
100038dc: andmi    r0, r0, r0
100038e0: push     {r4, lr}
100038e4: mov      r4, r0
100038e8: vpush    {d8, d9}
100038ec: add      r0, r0, #0x6000
100038f0: str      r1, [r0, #0xef8]!
100038f4: add      r1, r4, #0x6c00
100038f8: str      r2, [r0, #0x30]
100038fc: add      r1, r1, #0x2f8
10003900: add      r0, r4, #0x14c
10003904: bl       #0x10000578  ; ->Message::play
10003908: add      r4, r4, #0xcc
1000390c: vldr     s17, [pc, #0x2c]  ; =0x0 (0)
10003910: vldr     s18, [pc, #0x2c]  ; =0xc1a00000 (-20)
10003914: vldr     s16, [pc, #0x2c]  ; =0xc3340000 (-180)
10003918: mov      r0, r4
1000391c: bl       #0x100002d8  ; ->MoveVBase::stop
10003920: vstr     s16, [r4, #0x24]
10003924: add      r0, r4, #0x1c
10003928: vstmia   r0, {s17, s18}
1000392c: vstr     s16, [r4, #0xc]
10003930: add      r4, r4, #4
10003934: vstmia   r4, {s17, s18}
10003938: vpop     {d8, d9}
1000393c: pop      {r4, pc}
10003940: andeq    r0, r0, r0
10003944: movgt    r0, r0
10003948: teqgt    r4, #0
1000394c: push     {r4, r5, r6, lr}
10003950: mov      r4, r0
10003954: add      r0, r0, #0x13000
10003958: ldr      r0, [r0, #0x25c]
1000395c: ldrh     r0, [r0, #0x10]
10003960: cmp      r0, #1
10003964: bne      #0x100039cc
10003968: add      r5, r4, #0x21000
1000396c: add      r5, r5, #0x1f4
10003970: ldr      r0, [r5]
10003974: ldr      r1, [r0, #0x24]
10003978: mov      r0, r5
1000397c: blx      r1
10003980: cmp      r0, #0
10003984: bne      #0x100039cc
10003988: ldr      r0, [r5, #0x154]
1000398c: cmp      r0, #0
10003990: beq      #0x100039ac
10003994: ldr      r1, [r0, #4]
10003998: add      r2, r0, #4
1000399c: cmp      r1, r2
100039a0: ldrbeq   r0, [r0, #0x172]
100039a4: cmpeq    r0, #0
100039a8: bne      #0x100039cc
100039ac: ldr      r0, [pc, #0x1c]  ; =0x44c64
100039b0: ldr      r1, [r0, r4]
100039b4: mov      r0, r5
100039b8: bl       #0x10000540  ; ->msys::MDfxChr::playDfx
100039bc: ldr      r0, [pc, #0x10]  ; =0x21348
100039c0: ldr      r1, [r0, r4]
100039c4: mov      r0, #0
100039c8: strh     r0, [r1, #0xf2]
100039cc: pop      {r4, r5, r6, pc}
100039d0: andeq    r4, r4, r4, ror #24
100039d4: andeq    r1, r2, r8, asr #6
100039d8: push     {r4, r5, r6, r7, r8, lr}
100039dc: mov      r5, r0
100039e0: add      r4, r5, #0x14
100039e4: ldr      r0, [pc, #0x120]  ; =0x3f7ee8 _ZGVZN2nn4math4VEC33OneEvE3one
100039e8: vpush    {d8}
100039ec: ldrb     r0, [r0]
100039f0: tst      r0, #1
100039f4: bne      #0x10003a24
100039f8: ldr      r0, [pc, #0x10c]  ; =0x3f7ee8 _ZGVZN2nn4math4VEC33OneEvE3one
100039fc: bl       #0x10000548  ; ->__cxa_guard_acquire
10003a00: cmp      r0, #0
10003a04: beq      #0x10003a24
10003a08: ldr      r0, [pc, #0x104]  ; =0x434c3c _ZZN2nn4math4VEC33OneEvE3one
10003a0c: vldr     s0, [pc, #0xfc]  ; =0x3f800000 (1)
10003a10: vstr     s0, [r0]
10003a14: vstr     s0, [r0, #4]
10003a18: vstr     s0, [r0, #8]
10003a1c: ldr      r0, [pc, #0xe8]  ; =0x3f7ee8 _ZGVZN2nn4math4VEC33OneEvE3one
10003a20: bl       #0x10000550  ; ->__cxa_guard_release
10003a24: ldr      r6, [pc, #0xe8]  ; =0x434c3c _ZZN2nn4math4VEC33OneEvE3one
10003a28: mov      r0, r4
10003a2c: bl       #0x100002d8  ; ->MoveVBase::stop
10003a30: ldm      r6, {r0, r1, r2}
10003a34: add      r3, r4, #0x1c
10003a38: ldr      r6, [pc, #0xd8]  ; =0x3f7eec _ZGVZN2nn4math4VEC34ZeroEvE4zero
10003a3c: add      r4, r4, #4
10003a40: stm      r3, {r0, r1, r2}
10003a44: stm      r4, {r0, r1, r2}
10003a48: add      r4, r5, #0x70
10003a4c: ldrb     r0, [r6]
10003a50: vldr     s16, [pc, #0xc4]  ; =0x0 (0)
10003a54: tst      r0, #1
10003a58: bne      #0x10003a88
10003a5c: add      r0, r6, #0
10003a60: bl       #0x10000548  ; ->__cxa_guard_acquire
10003a64: cmp      r0, #0
10003a68: nop      
10003a6c: beq      #0x10003a88
10003a70: ldr      r0, [pc, #0xa8]  ; =0x434c48 _ZZN2nn4math4VEC34ZeroEvE4zero
10003a74: vstr     s16, [r0]
10003a78: vstr     s16, [r0, #4]
10003a7c: vstr     s16, [r0, #8]
10003a80: add      r0, r6, #0
10003a84: bl       #0x10000550  ; ->__cxa_guard_release
10003a88: ldr      r7, [pc, #0x90]  ; =0x434c48 _ZZN2nn4math4VEC34ZeroEvE4zero
10003a8c: mov      r0, r4
10003a90: bl       #0x100002d8  ; ->MoveVBase::stop
10003a94: ldm      r7, {r0, r1, r2}
10003a98: add      r3, r4, #0x1c
10003a9c: add      r4, r4, #4
10003aa0: stm      r3, {r0, r1, r2}
10003aa4: stm      r4, {r0, r1, r2}
10003aa8: add      r4, r5, #0xcc
10003aac: ldrb     r0, [r6]
10003ab0: tst      r0, #1
10003ab4: bne      #0x10003ae4
10003ab8: ldr      r0, [pc, #0x58]  ; =0x3f7eec _ZGVZN2nn4math4VEC34ZeroEvE4zero
10003abc: bl       #0x10000548  ; ->__cxa_guard_acquire
10003ac0: cmp      r0, #0
10003ac4: nop      
10003ac8: beq      #0x10003ae4
10003acc: add      r0, r7, #0
10003ad0: vstr     s16, [r0]
10003ad4: vstr     s16, [r0, #4]
10003ad8: vstr     s16, [r0, #8]
10003adc: ldr      r0, [pc, #0x34]  ; =0x3f7eec _ZGVZN2nn4math4VEC34ZeroEvE4zero
10003ae0: bl       #0x10000550  ; ->__cxa_guard_release
10003ae4: ldr      r5, [pc, #0x34]  ; =0x434c48 _ZZN2nn4math4VEC34ZeroEvE4zero
10003ae8: mov      r0, r4
10003aec: bl       #0x100002d8  ; ->MoveVBase::stop
10003af0: ldm      r5, {r0, r1, r2}
10003af4: add      r3, r4, #0x1c
10003af8: add      r4, r4, #4
10003afc: stm      r3, {r0, r1, r2}
10003b00: stm      r4, {r0, r1, r2}
10003b04: vpop     {d8}
10003b08: pop      {r4, r5, r6, r7, r8, pc}
10003b0c: eorseq   r7, pc, r8, ror #29
10003b10: svclo    #0x800000
10003b14: subeq    r4, r3, ip, lsr ip
10003b18: eorseq   r7, pc, ip, ror #29
10003b1c: andeq    r0, r0, r0
10003b20: subeq    r4, r3, r8, asr #24
10003b24: push     {r4, r5, r6, r7, r8, sb, sl, fp, lr}
10003b28: mov      r4, r0
10003b2c: mov      r8, r2
10003b30: add      sl, r0, #0x10000
10003b34: add      sl, sl, #0x4e00
10003b38: add      sb, r0, #0x400
10003b3c: vpush    {d8, d9}
10003b40: sub      sp, sp, #0xc
10003b44: mov      r5, r1
10003b48: ldrsb    r0, [sl, #0x2e]
10003b4c: add      sb, sb, #0x2ac
10003b50: cmp      r0, r8
10003b54: bne      #0x10003b74
10003b58: cmp      r8, #0
10003b5c: beq      #0x10003d40
10003b60: ldrh     r0, [sl, #0x2c]
10003b64: ldrh     r1, [r5, #0x12]
10003b68: cmp      r0, r1
10003b6c: beq      #0x10003d40
10003b70: b        #0x10003b7c
10003b74: cmp      r8, #0
10003b78: beq      #0x10003d08
10003b7c: mov      fp, #1
10003b80: mov      r6, #0
10003b84: rsb      r0, r6, r6, lsl #3
10003b88: add      r1, r5, r6, lsl #1
10003b8c: add      r0, r0, r0, lsl #2
10003b90: ldrsh    r1, [r1]
10003b94: add      r7, r4, r0, lsl #4
10003b98: add      r0, r7, #0x150
10003b9c: bl       #0x10000580  ; ->ad::lyt::LytNumReel3::setValueInstant
10003ba0: add      r6, r6, #1
10003ba4: cmp      r6, #3
10003ba8: strb     fp, [r7, #0x141]
10003bac: blt      #0x10003b84
10003bb0: ldrb     r0, [r5, #0x14]
10003bb4: vmov     s0, r0
10003bb8: add      r0, r4, #0x400
10003bbc: add      r0, r0, #0x2c8
10003bc0: vcvt.f32.u32 s0, s0
10003bc4: bl       #0x100003b0  ; ->ad::lyt::LytAnim::stopAndSetFrm
10003bc8: ldrb     r0, [r5, #0x15]
10003bcc: vmov     s0, r0
10003bd0: add      r0, r4, #0x690
10003bd4: vcvt.f32.u32 s0, s0
10003bd8: bl       #0x100003b0  ; ->ad::lyt::LytAnim::stopAndSetFrm
10003bdc: vldr     s18, [pc, #0x168]  ; =0x0 (0)
10003be0: mov      r0, sb
10003be4: vmov.f32 s0, s18
10003be8: bl       #0x100003b0  ; ->ad::lyt::LytAnim::stopAndSetFrm
10003bec: ldrh     r0, [r5, #0x12]
10003bf0: nop      
10003bf4: bl       #0x10000390  ; ->ad::db::GetPcAttack
10003bf8: ldrb     r1, [r0, #8]
10003bfc: mov      r7, r0
10003c00: vldr     s0, [pc, #0x148]  ; =0x3f800000 (1)
10003c04: mov      r2, #0
10003c08: add      r0, r4, #0x830
10003c0c: bl       #0x10000588  ; ->CellAnime::play
10003c10: nop      
10003c14: nop      
10003c18: bl       #0x10000590  ; ->ad::db::GetItemMsgAcs
10003c1c: mov      r6, r0
10003c20: ldr      r1, [r7]
10003c24: add      r0, r0, #8
10003c28: bl       #0x100003d0  ; ->LMS_GetTextIndexByLabel
10003c2c: mov      r1, r0
10003c30: add      r0, r6, #8
10003c34: bl       #0x100003d8  ; ->LMS_GetText
10003c38: mov      r1, #0
10003c3c: mov      r3, r1
10003c40: mov      r2, r1
10003c44: str      r1, [sp]
10003c48: str      r1, [sp, #4]
10003c4c: mov      r6, r0
10003c50: mov      r1, r0
10003c54: add      r0, r4, #0x7000
10003c58: add      r0, r0, #0x6f0
10003c5c: bl       #0x10000598  ; ->MessageSimple::getLineWidth
10003c60: vldr     s2, [pc, #0xec]  ; =0x41b80000 (23)
10003c64: vldr     s1, [pc, #0xec]  ; =0x3f000000 (0.5)
10003c68: mov      r3, #0
10003c6c: vsub.f32 s0, s2, s0
10003c70: mov      r2, r3
10003c74: mov      r1, r6
10003c78: add      r0, r4, #0x960
10003c7c: vmul.f32 s17, s0, s1
10003c80: bl       #0x100003e0  ; ->msys::MMsg::playStr
10003c84: mov      r3, #0
10003c88: add      r0, r4, #0x7400
10003c8c: mov      r2, r3
10003c90: mov      r1, r6
10003c94: add      r0, r0, #0x1a4
10003c98: bl       #0x100003e0  ; ->msys::MMsg::playStr
10003c9c: add      r6, r4, #0x7000
10003ca0: vmov.f32 s16, s18
10003ca4: add      r6, r6, #0x670
10003ca8: mov      r0, r6
10003cac: bl       #0x100002d8  ; ->MoveVBase::stop
10003cb0: add      r0, r6, #0x1c
10003cb4: vldr     s3, [pc, #0xa0]  ; =0xc1500000 (-13)
10003cb8: vldr     s2, [pc, #0xa0]  ; =0xbf800000 (-1)
10003cbc: vstmia   r0, {s17, s18}
10003cc0: add      r0, r4, #0x7400
10003cc4: vstr     s18, [r6, #0x24]
10003cc8: ldr      r1, [r6, #0x20]
10003ccc: vstr     s17, [r6, #4]
10003cd0: add      r0, r0, #0x274
10003cd4: str      r1, [r6, #8]
10003cd8: vstr     s18, [r6, #0xc]
10003cdc: add      r6, r4, #0x7b0
10003ce0: vldmia   r0, {s0, s1}
10003ce4: mov      r0, r6
10003ce8: vadd.f32 s16, s0, s3
10003cec: vadd.f32 s17, s1, s2
10003cf0: bl       #0x100002d8  ; ->MoveVBase::stop
10003cf4: add      r0, r6, #0x1c
10003cf8: add      r6, r6, #4
10003cfc: vstmia   r0, {s16, s17, s18}
10003d00: vstmia   r6, {s16, s17, s18}
10003d04: b        #0x10003d30
10003d08: mov      r1, #0
10003d0c: strb     r1, [r4, #0x141]
10003d10: strb     r1, [r4, #0x371]
10003d14: strb     r1, [r4, #0x5a1]
10003d18: ldr      r0, [sb, #0x14]
10003d1c: bl       #0x10000470  ; ->ad::lyt::AnimTransform::GetFrameSize
10003d20: vmov     s0, r0
10003d24: mov      r0, sb
10003d28: vcvt.f32.u32 s0, s0
10003d2c: bl       #0x100003b0  ; ->ad::lyt::LytAnim::stopAndSetFrm
10003d30: ldrh     r0, [r5, #0x12]
10003d34: ldr      r1, [pc, #0x28]  ; =0x14e2e
10003d38: strh     r0, [sl, #0x2c]
10003d3c: strb     r8, [r1, r4]
10003d40: add      sp, sp, #0xc
10003d44: vpop     {d8, d9}
10003d48: pop      {r4, r5, r6, r7, r8, sb, sl, fp, pc}
10003d4c: andeq    r0, r0, r0
10003d50: svclo    #0x800000
10003d54: movsmi   r0, r0
10003d58: svclo    #0
10003d5c: cmpgt    r0, r0
10003d60: svclt    #0x800000
10003d64: andeq    r4, r1, lr, lsr #28
10003d68: ldr      r2, [pc, #0x5c]  ; =0x3f62a8 msys::MComSys::_sys
10003d6c: ldr      r3, [r0, #8]
10003d70: ldr      r2, [r2]
10003d74: cmp      r3, #0
10003d78: streq    r2, [r0, #8]
10003d7c: ldr      r3, [r0, #8]
10003d80: add      r3, r3, #0xe6000
10003d84: strb     r1, [r3, #0x508]
10003d88: ldr      r3, [r0, #8]
10003d8c: cmp      r3, #0
10003d90: streq    r2, [r0, #8]
10003d94: movne    r2, r3
10003d98: add      r3, r2, #0xe6000
10003d9c: mov      r2, #1
10003da0: cmp      r1, #0
10003da4: strb     r2, [r3, #0x50a]
10003da8: beq      #0x10003dbc
10003dac: ldr      r2, [pc, #0x1c]  ; =0x28cd1
10003db0: ldrb     r2, [r2, r0]
10003db4: cmp      r2, #0
10003db8: beq      #0x10003dc8
10003dbc: add      r0, r0, #0x28000
10003dc0: add      r0, r0, #0xb90
10003dc4: b        #0x100005a0  ; ->msys::MListWndPBase::setEnableInput
10003dc8: bx       lr
10003dcc: eorseq   r6, pc, r8, lsr #5
10003dd0: ldrdeq   r8, sb, [r2], -r1
10003dd4: ldr      r0, [pc, #0x94]  ; =0x3f62a8 msys::MComSys::_sys
10003dd8: push     {r3, r4, r5, r6, r7, lr}
10003ddc: ldr      r0, [r0]
10003de0: vldr     s0, [sp, #0x18]
10003de4: add      r0, r0, #0x49000
10003de8: add      r0, r0, #0x368
10003dec: ldr      ip, [r0, #0xc]
10003df0: sub      r4, ip, #0x54
10003df4: sub      ip, r0, #0x4c
10003df8: cmp      ip, r4
10003dfc: moveq    r4, #0
10003e00: beq      #0x10003e68
10003e04: ldr      r5, [r4, #0x58]
10003e08: add      ip, r4, #0x54
10003e0c: cmp      r5, ip
10003e10: beq      #0x10003e2c
10003e14: ldr      r6, [ip]
10003e18: str      r5, [r6, #4]
10003e1c: ldr      r6, [ip]
10003e20: str      r6, [r5]
10003e24: str      ip, [ip]
10003e28: str      ip, [ip, #4]
10003e2c: add      ip, r4, #0x54
10003e30: ldm      ip, {r5, r6}
10003e34: str      r6, [r5, #4]
10003e38: ldr      ip, [r4, #0x54]
10003e3c: str      ip, [r6]
10003e40: adds     ip, r4, #0x54
10003e44: beq      #0x10003e5c
10003e48: str      r0, [ip]
10003e4c: ldr      r5, [r0, #4]
10003e50: str      r5, [ip, #4]
10003e54: str      ip, [r5]
10003e58: str      ip, [r0, #4]
10003e5c: vstr     s0, [sp]
10003e60: mov      r0, r4
10003e64: bl       #0x100005a8  ; ->msys::MSndSe::play
10003e68: mov      r0, r4
10003e6c: pop      {r3, r4, r5, r6, r7, pc}
10003e70: eorseq   r6, pc, r8, lsr #5
10003e74: push     {r4, r5, r6, lr}
10003e78: mov      r5, r0
10003e7c: ldr      r0, [pc, #0x140]  ; =0x1000891c
10003e80: mov      r1, #0
10003e84: str      r0, [r5]
10003e88: ldr      r0, [r5, #4]
10003e8c: bl       #0x100005b0  ; ->ad::fw::TaskBase::term
10003e90: add      r0, r5, #0xe9000
10003e94: add      r0, r0, #0x124
10003e98: mov      r4, r0
10003e9c: bl       #0x100005b8  ; ->msys::MLyt::term
10003ea0: add      r0, r5, #0xe9000
10003ea4: add      r0, r0, #0xe0
10003ea8: bl       #0x100005c0  ; ->ad::fw::Resource::term
10003eac: ldr      r0, [pc, #0x114]  ; =0x3e4580
10003eb0: str      r0, [r4]
10003eb4: mov      r0, r4
10003eb8: bl       #0x100005b8  ; ->msys::MLyt::term
10003ebc: ldr      r1, [pc, #0x108]  ; =0x100009b8
10003ec0: mov      r3, #0xc
10003ec4: mov      r2, #0x10
10003ec8: add      r0, r4, #0x2b0
10003ecc: bl       #0x10000210  ; ->__aeabi_vec_dtor
10003ed0: ldr      r1, [pc, #0xf8]  ; =0x10000850
10003ed4: mov      r3, #0xc
10003ed8: mov      r2, #0x1c
10003edc: add      r0, r4, #0x154
10003ee0: bl       #0x10000210  ; ->__aeabi_vec_dtor
10003ee4: mov      r0, r4
10003ee8: bl       #0x100040e4
10003eec: sub      r0, r0, #0x44
10003ef0: bl       #0x100005c8  ; ->ad::fw::Resource
10003ef4: sub      r4, r0, #0x24
10003ef8: ldr      r0, [pc, #0xd4]  ; =0x100089d8
10003efc: str      r0, [r4]
10003f00: ldr      r0, [r4, #0x20]
10003f04: cmp      r0, #0
10003f08: beq      #0x10003f18
10003f0c: ldr      r1, [r0]
10003f10: ldr      r1, [r1, #4]
10003f14: blx      r1
10003f18: mov      r0, #0
10003f1c: str      r0, [r4, #0x20]
10003f20: ldr      r0, [pc, #0xb0]  ; =0x3e483c
10003f24: str      r0, [r4], #0x10
10003f28: ldr      r0, [r4], #-4
10003f2c: cmp      r0, r4
10003f30: beq      #0x10003f4c
10003f34: ldr      r1, [r0, #4]
10003f38: str      r0, [r0, #4]
10003f3c: str      r0, [r0]
10003f40: cmp      r1, r4
10003f44: mov      r0, r1
10003f48: bne      #0x10003f34
10003f4c: str      r4, [r4, #4]
10003f50: mov      r1, r4
10003f54: str      r4, [r4]
10003f58: ldr      r0, [r4, #4]!
10003f5c: str      r0, [r1, #4]
10003f60: ldr      r1, [r4, #-4]
10003f64: str      r1, [r0]
10003f68: ldr      r0, [r4, #-8]
10003f6c: sub      r1, r4, #0xc
10003f70: cmp      r0, r1
10003f74: beq      #0x10003f90
10003f78: ldr      r2, [r0, #4]
10003f7c: str      r0, [r0, #4]
10003f80: str      r0, [r0]
10003f84: cmp      r2, r1
10003f88: mov      r0, r2
10003f8c: bne      #0x10003f78
10003f90: str      r1, [r1, #4]
10003f94: str      r1, [r1]
10003f98: ldr      r2, [r1], #4
10003f9c: ldr      r0, [r1], #4
10003fa0: str      r0, [r2, #4]
10003fa4: ldr      r2, [r1, #-8]
10003fa8: str      r2, [r0]
10003fac: sub      r0, r1, #0x78
10003fb0: bl       #0x10000190  ; ->MsgDataAcsrBase
10003fb4: pop      {r4, r5, r6, lr}
10003fb8: sub      r0, r0, #0xe9000
10003fbc: sub      r0, r0, #0x50
10003fc0: b        #0x100005d0  ; ->msys::MComSys
10003fc4: andne    r8, r0, ip, lsl sb
10003fc8: eorseq   r4, lr, r0, lsl #11
10003fcc: strhne   r0, [r0], -r8
10003fd0: andne    r0, r0, r0, asr r8
10003fd4: ldrdne   r8, sb, [r0], -r8
10003fd8: eorseq   r4, lr, ip, lsr r8
10003fdc: and      r1, r1, #0xff
10003fe0: orr      r1, r1, r1, lsl #8
10003fe4: orr      r1, r1, r1, lsl #16
10003fe8: str      r1, [r0]
10003fec: str      r1, [r0, #4]
10003ff0: str      r1, [r0, #8]
10003ff4: bx       lr
10003ff8: mov      r1, r0
10003ffc: ldr      r0, [pc, #0xd0]  ; =0x3e435c
10004000: push     {r4, r5, r6, lr}
10004004: mov      r5, #0
10004008: str      r0, [r1]
1000400c: add      r0, r1, #4
10004010: str      r0, [r1, #4]
10004014: str      r0, [r1, #8]
10004018: str      r5, [r1, #0xc]
1000401c: add      r0, r1, #0x14
10004020: strb     r5, [r1, #0x10]
10004024: bl       #0x100005d8  ; ->MoveVBase
10004028: ldr      r6, [pc, #0xa8]  ; =0x10008778
1000402c: ldr      r1, [pc, #0xa8]  ; =0x1000789c
10004030: mov      r3, #1
10004034: mov      r2, #0x2c
10004038: str      r6, [r0], #0x30
1000403c: bl       #0x10000330  ; ->__aeabi_vec_ctor_nocookie_nodtor
10004040: mov      r4, #1
10004044: str      r0, [r0, #-8]
10004048: strb     r4, [r0, #-4]
1000404c: add      r0, r0, #0x2c
10004050: bl       #0x100005d8  ; ->MoveVBase
10004054: ldr      r1, [pc, #0x80]  ; =0x1000789c
10004058: mov      r3, #1
1000405c: mov      r2, #0x2c
10004060: str      r6, [r0], #0x30
10004064: bl       #0x10000330  ; ->__aeabi_vec_ctor_nocookie_nodtor
10004068: str      r0, [r0, #-8]
1000406c: strb     r4, [r0, #-4]
10004070: add      r0, r0, #0x2c
10004074: bl       #0x100005d8  ; ->MoveVBase
10004078: ldr      r1, [pc, #0x5c]  ; =0x1000789c
1000407c: mov      r3, #1
10004080: mov      r2, #0x2c
10004084: str      r6, [r0], #0x30
10004088: bl       #0x10000330  ; ->__aeabi_vec_ctor_nocookie_nodtor
1000408c: str      r0, [r0, #-8]
10004090: strb     r4, [r0, #-4]
10004094: str      r5, [r0, #0x2c]
10004098: str      r5, [r0, #0x30]
1000409c: str      r5, [r0, #0x34]
100040a0: strb     r5, [r0, #0x38]
100040a4: strb     r5, [r0, #0x39]
100040a8: str      r5, [r0, #0x3c]
100040ac: str      r5, [r0, #0x40]
100040b0: ldr      r1, [pc, #0x28]  ; =0x10008894
100040b4: strb     r4, [r0, #0x44]
100040b8: strb     r4, [r0, #0x45]
100040bc: strb     r4, [r0, #0x46]
100040c0: str      r1, [r0, #-0xfc]!
100040c4: add      r1, r0, #0x144
100040c8: str      r1, [r0, #0x144]
100040cc: str      r1, [r0, #0x148]
100040d0: pop      {r4, r5, r6, pc}
100040d4: eorseq   r4, lr, ip, asr r3
100040d8: andne    r8, r0, r8, ror r7
100040dc: mulne    r0, ip, r8
100040e0: mulne    r0, r4, r8
100040e4: ldr      r1, [pc, #0x144]  ; =0x10008894
100040e8: push     {r4, r5, r6, lr}
100040ec: str      r1, [r0], #0x148
100040f0: ldr      r1, [r0], #-4
100040f4: cmp      r1, r0
100040f8: beq      #0x10004114
100040fc: ldr      r2, [r1, #4]
10004100: str      r1, [r1, #4]
10004104: str      r1, [r1]
10004108: cmp      r2, r0
1000410c: mov      r1, r2
10004110: bne      #0x100040fc
10004114: str      r0, [r0, #4]
10004118: str      r0, [r0]
1000411c: ldr      r2, [r0]
10004120: ldr      r1, [r0, #4]
10004124: str      r1, [r2, #4]
10004128: ldr      r2, [r0], #-0x144
1000412c: str      r2, [r1]
10004130: ldr      r1, [pc, #0xfc]  ; =0x3e435c
10004134: str      r1, [r0], #0x128
10004138: mov      r5, r0
1000413c: ldr      r2, [r0, #8]
10004140: cmp      r2, #0
10004144: beq      #0x1000419c
10004148: ldr      r1, [r5]
1000414c: mov      r4, r5
10004150: add      r0, r2, #0x254
10004154: cmp      r1, #0
10004158: ldrne    r2, [r4, #4]
1000415c: strne    r2, [r1, #4]
10004160: ldr      r1, [r4, #4]
10004164: cmp      r1, #0
10004168: ldrne    r2, [r4]
1000416c: strne    r2, [r1]
10004170: ldr      r1, [r0]
10004174: cmp      r1, r4
10004178: ldreq    r1, [r4, #4]
1000417c: streq    r1, [r0]
10004180: mov      r1, #0
10004184: str      r1, [r4, #4]
10004188: str      r1, [r4]
1000418c: str      r1, [r5, #8]
10004190: ldr      r1, [r0, #4]
10004194: sub      r1, r1, #1
10004198: str      r1, [r0, #4]
1000419c: ldr      r6, [pc, #0x94]  ; =0x10008778
100041a0: ldr      r1, [pc, #0x94]  ; =0x100078e0
100041a4: mov      r3, #1
100041a8: str      r6, [r5, #-0x5c]!
100041ac: mov      r2, #0x2c
100041b0: add      r0, r5, #0x30
100041b4: bl       #0x10000210  ; ->__aeabi_vec_dtor
100041b8: mov      r0, r5
100041bc: nop      
100041c0: bl       #0x10000218  ; ->MoveVBase
100041c4: sub      r4, r0, #0x5c
100041c8: str      r6, [r0, #-0x5c]
100041cc: ldr      r1, [pc, #0x68]  ; =0x100078e0
100041d0: mov      r3, #1
100041d4: mov      r2, #0x2c
100041d8: sub      r0, r0, #0x2c
100041dc: bl       #0x10000210  ; ->__aeabi_vec_dtor
100041e0: mov      r0, r4
100041e4: nop      
100041e8: bl       #0x10000218  ; ->MoveVBase
100041ec: sub      r4, r0, #0x5c
100041f0: str      r6, [r0, #-0x5c]
100041f4: ldr      r1, [pc, #0x40]  ; =0x100078e0
100041f8: mov      r3, #1
100041fc: mov      r2, #0x2c
10004200: sub      r0, r0, #0x2c
10004204: bl       #0x10000210  ; ->__aeabi_vec_dtor
10004208: mov      r0, r4
1000420c: nop      
10004210: bl       #0x10000218  ; ->MoveVBase
10004214: sub      r1, r0, #0x10
10004218: ldrd     r2, r3, [r1]
1000421c: str      r3, [r2, #4]
10004220: ldr      r1, [r0, #-0x10]
10004224: sub      r0, r0, #0x14
10004228: str      r1, [r3]
1000422c: pop      {r4, r5, r6, pc}
10004230: mulne    r0, r4, r8
10004234: eorseq   r4, lr, ip, asr r3
10004238: andne    r8, r0, r8, ror r7
1000423c: andne    r7, r0, r0, ror #17
10004240: ldr      r0, [pc, #0x90]  ; =0x3f62a8 msys::MComSys::_sys
10004244: push     {r3, r4, r5, r6, r7, lr}
10004248: mov      r2, #0
1000424c: mov      r3, r2
10004250: ldr      r0, [r0]
10004254: mov      r5, r2
10004258: add      r4, r0, #0x49000
1000425c: add      r4, r4, #0x368
10004260: sub      ip, r4, #0x4c
10004264: ldr      r0, [r4, #0xc]
10004268: sub      r0, r0, #0x54
1000426c: cmp      ip, r0
10004270: beq      #0x100042d4
10004274: ldr      r6, [r0, #0x58]
10004278: add      ip, r0, #0x54
1000427c: cmp      r6, ip
10004280: beq      #0x1000429c
10004284: ldr      r7, [ip]
10004288: str      r6, [r7, #4]
1000428c: ldr      r7, [ip]
10004290: str      r7, [r6]
10004294: str      ip, [ip]
10004298: str      ip, [ip, #4]
1000429c: add      ip, r0, #0x54
100042a0: ldrd     r6, r7, [ip]
100042a4: str      r7, [r6, #4]
100042a8: ldr      ip, [r0, #0x54]
100042ac: str      ip, [r7]
100042b0: adds     ip, r0, #0x54
100042b4: beq      #0x100042cc
100042b8: str      r4, [ip]
100042bc: ldr      r6, [r4, #4]
100042c0: str      r6, [ip, #4]
100042c4: str      ip, [r6]
100042c8: str      ip, [r4, #4]
100042cc: str      r5, [sp]
100042d0: bl       #0x100005a8  ; ->msys::MSndSe::play
100042d4: pop      {r3, r4, r5, r6, r7, pc}
100042d8: eorseq   r6, pc, r8, lsr #5
100042dc: push     {r4, r5, r6, lr}
100042e0: mov      r4, r0
100042e4: bl       #0x1000394c
100042e8: add      r0, r4, #0x12c00
100042ec: add      r0, r0, #0x2d4
100042f0: mov      r5, r0
100042f4: bl       #0x100004d0  ; ->msys::MLyt::isEnableAnime
100042f8: cmp      r0, #0
100042fc: bne      #0x10004348
10004300: mov      r3, #0
10004304: add      r2, pc, #0x40
10004308: add      r1, pc, #0x4c
1000430c: mov      r0, r5
10004310: bl       #0x100003c0  ; ->msys::MLyt::createAnimeAutoSlot
10004314: sxth     r1, r0
10004318: mov      r0, r5
1000431c: bl       #0x100003a8  ; ->msys::MLyt::getAnim
10004320: ldr      r1, [pc, #0x3c]  ; =0x44c5c
10004324: str      r0, [r1, r4]
10004328: mov      r1, #1
1000432c: mov      r0, r4
10004330: bl       #0x10003d68
10004334: ldr      r1, [pc, #0x2c]  ; =0x1000814c
10004338: add      r2, r4, #0x10000
1000433c: add      r2, r2, #0x2a00
10004340: ldm      r1, {r0, r1}
10004344: strd     r0, r1, [r2, #4]
10004348: pop      {r4, r5, r6, pc}
1000434c: svcpl    #0x6e7462
10004350: ldrbpl   r4, [r8], #-0x54e
10004354: strbvs   r6, [r7, #-0x170]!
10004358: andeq    r0, r0, r0
1000435c: subpl    r4, pc, ip, asr #30
10004360: andeq    r0, r0, r0
10004364: andeq    r4, r4, ip, asr ip
10004368: andne    r8, r0, ip, asr #2
1000436c: push     {r3, r4, r5, r6, r7, lr}
10004370: mov      r4, r0
10004374: ldr      r0, [r1]
10004378: ldr      r1, [pc, #0xf4]  ; =0xc03
1000437c: tst      r0, r1
10004380: beq      #0x10004468
10004384: mov      r5, #0
10004388: add      r0, r4, #0x12c00
1000438c: add      r0, r0, #0x2d4
10004390: mov      r3, r5
10004394: mov      r2, r5
10004398: mov      r1, #3
1000439c: mov      r6, r0
100043a0: str      r5, [sp]
100043a4: bl       #0x100003e8  ; ->msys::MLyt::playAnimeFromNo
100043a8: mov      r3, #0
100043ac: mov      r2, r3
100043b0: mov      r1, #6
100043b4: mov      r0, r6
100043b8: str      r5, [sp]
100043bc: bl       #0x100003e8  ; ->msys::MLyt::playAnimeFromNo
100043c0: mov      r3, #0
100043c4: ldr      r1, [pc, #0xac]  ; =0x110016
100043c8: mov      r2, r3
100043cc: mov      r0, r4
100043d0: str      r5, [sp]
100043d4: bl       #0x10003dd4
100043d8: mov      r1, #0
100043dc: mov      r0, r4
100043e0: bl       #0x10003d68
100043e4: ldr      r0, [pc, #0x90]  ; =0x1325c
100043e8: ldr      r0, [r0, r4]
100043ec: ldrh     r0, [r0, #0x10]
100043f0: cmp      r0, #1
100043f4: bne      #0x10004450
100043f8: mov      r3, #0
100043fc: mov      r2, r3
10004400: mov      r1, #4
10004404: mov      r0, r6
10004408: str      r5, [sp]
1000440c: bl       #0x100003e8  ; ->msys::MLyt::playAnimeFromNo
10004410: add      r5, r4, #0x44000
10004414: ldr      r0, [r5, #0xc58]
10004418: ldrh     r1, [r0, #0x12]
1000441c: bic      r1, r1, #2
10004420: strh     r1, [r0, #0x12]
10004424: add      r0, r4, #0x21000
10004428: add      r0, r0, #0x1f4
1000442c: mov      r7, r0
10004430: bl       #0x100004d8  ; ->msys::MDfxChr::term
10004434: mov      r1, r7
10004438: mov      r0, r6
1000443c: bl       #0x100004e0  ; ->msys::MLyt::detachMChr
10004440: ldr      r0, [r5, #0xc60]
10004444: mov      r1, #1
10004448: ldr      r0, [r0, #0x154]
1000444c: strb     r1, [r0, #0x170]
10004450: ldr      r0, [pc, #0x28]  ; =0x10008154
10004454: add      r2, r4, #0x10000
10004458: add      r2, r2, #0x2a00
1000445c: ldm      r0, {r0, r1}
10004460: strd     r0, r1, [r2, #4]
10004464: pop      {r3, r4, r5, r6, r7, pc}
10004468: mov      r0, r4
1000446c: pop      {r3, r4, r5, r6, r7, lr}
10004470: b        #0x1000394c
10004474: andeq    r0, r0, r3, lsl #24
10004478: andseq   r0, r1, r6, lsl r0
1000447c: andeq    r3, r1, ip, asr r2
10004480: andne    r8, r0, r4, asr r1
10004484: push     {r4, r5, r6, lr}
10004488: mov      r4, r0
1000448c: add      r0, r0, #0x12c00
10004490: add      r0, r0, #0x2d4
10004494: bl       #0x100004d0  ; ->msys::MLyt::isEnableAnime
10004498: cmp      r0, #0
1000449c: bne      #0x100044d8
100044a0: add      r5, r4, #0x44000
100044a4: ldr      r0, [r5, #0xc5c]
100044a8: bl       #0x10000558  ; ->ad::lyt::LytAnim::stop
100044ac: ldr      r0, [r5, #0xc5c]
100044b0: mov      r1, #1
100044b4: bl       #0x10000478  ; ->ad::lyt::LytAnim::term
100044b8: add      r0, r4, #0x12800
100044bc: mov      r1, #0
100044c0: add      r0, r0, #0x20c
100044c4: str      r1, [r5, #0xc5c]
100044c8: ldm      r0, {r1, r2}
100044cc: add      r0, r4, #0x12800
100044d0: add      r0, r0, #0x204
100044d4: stm      r0, {r1, r2}
100044d8: pop      {r4, r5, r6, pc}
100044dc: push     {r3, r4, r5, lr}
100044e0: mov      r5, #0
100044e4: mov      r4, r0
100044e8: add      r0, r0, #0x12800
100044ec: mov      r3, r5
100044f0: mov      r2, r5
100044f4: mov      r1, #2
100044f8: add      r0, r0, #0x32c
100044fc: str      r5, [sp]
10004500: bl       #0x100003e8  ; ->msys::MLyt::playAnimeFromNo
10004504: mov      r3, #0
10004508: add      r0, r4, #0x12c00
1000450c: mov      r2, r3
10004510: mov      r1, #2
10004514: add      r0, r0, #0x2d4
10004518: str      r5, [sp]
1000451c: bl       #0x100003e8  ; ->msys::MLyt::playAnimeFromNo
10004520: ldr      r0, [pc, #0x10]  ; =0x10008124
10004524: add      r2, r4, #0x10000
10004528: add      r2, r2, #0x2a00
1000452c: ldm      r0, {r0, r1}
10004530: strd     r0, r1, [r2, #4]
10004534: pop      {r3, r4, r5, pc}
10004538: andne    r8, r0, r4, lsr #2
1000453c: push     {r3, r4, r5, lr}
10004540: mov      r4, r0
10004544: add      r0, r0, #0x12c00
10004548: add      r0, r0, #0x2d4
1000454c: mov      r5, r0
10004550: bl       #0x100004d0  ; ->msys::MLyt::isEnableAnime
10004554: cmp      r0, #0
10004558: bne      #0x1000458c
1000455c: mov      r0, #0
10004560: mov      r3, r0
10004564: str      r0, [sp]
10004568: mov      r2, #1
1000456c: mov      r1, #6
10004570: mov      r0, r5
10004574: bl       #0x100003e8  ; ->msys::MLyt::playAnimeFromNo
10004578: ldr      r0, [pc, #0x10]  ; =0x100080dc
1000457c: add      r2, r4, #0x10000
10004580: add      r2, r2, #0x2a00
10004584: ldm      r0, {r0, r1}
10004588: strd     r0, r1, [r2, #4]
1000458c: pop      {r3, r4, r5, pc}
10004590: ldrdne   r8, sb, [r0], -ip
10004594: push     {r4, r5, r6, lr}
10004598: mov      r4, r0
1000459c: add      r0, r0, #0x12c00
100045a0: add      r0, r0, #0x2d4
100045a4: mov      r5, r0
100045a8: bl       #0x100004d0  ; ->msys::MLyt::isEnableAnime
100045ac: cmp      r0, #0
100045b0: bne      #0x100045f0
100045b4: mov      r3, #0
100045b8: add      r2, pc, #0x34
100045bc: add      r1, pc, #0x40
100045c0: mov      r0, r5
100045c4: bl       #0x100003c0  ; ->msys::MLyt::createAnimeAutoSlot
100045c8: sxth     r1, r0
100045cc: mov      r0, r5
100045d0: bl       #0x100003a8  ; ->msys::MLyt::getAnim
100045d4: ldr      r1, [pc, #0x30]  ; =0x44c5c
100045d8: add      r2, r4, #0x10000
100045dc: add      r2, r2, #0x2a00
100045e0: str      r0, [r1, r4]
100045e4: ldr      r1, [pc, #0x24]  ; =0x10008000
100045e8: ldrd     r0, r1, [r1, #0xe4]
100045ec: strd     r0, r1, [r2, #4]
100045f0: pop      {r4, r5, r6, pc}
100045f4: svcpl    #0x6e7462
100045f8: ldrbpl   r4, [r8], #-0x54e
100045fc: strbvs   r6, [r7, #-0x170]!
10004600: andeq    r0, r0, r0
10004604: subpl    r4, pc, ip, asr #30
10004608: andeq    r0, r0, r0
1000460c: andeq    r4, r4, ip, asr ip
10004610: andne    r8, r0, r0
10004614: push     {r4, lr}
10004618: mov      r4, r0
1000461c: mov      r3, #0
10004620: add      r0, r0, #0x12800
10004624: mov      r2, r3
10004628: add      r1, pc, #0x34
1000462c: add      r0, r0, #0x32c
10004630: bl       #0x100003c0  ; ->msys::MLyt::createAnimeAutoSlot
10004634: mov      r3, #0
10004638: add      r0, r4, #0x12c00
1000463c: mov      r2, r3
10004640: add      r1, pc, #0x1c
10004644: add      r0, r0, #0x2d4
10004648: bl       #0x100003c0  ; ->msys::MLyt::createAnimeAutoSlot
1000464c: ldr      r0, [pc, #0x18]  ; =0x10008184
10004650: add      r2, r4, #0x10000
10004654: add      r2, r2, #0x2a00
10004658: ldm      r0, {r0, r1}
1000465c: strd     r0, r1, [r2, #4]
10004660: pop      {r4, pc}
10004664: svcvs    #0x745f34
10004668: andeq    r3, r0, pc, asr r5
1000466c: andne    r8, r0, r4, lsl #3
10004670: push     {r4, lr}
10004674: mov      r4, r0
10004678: bl       #0x1000394c
1000467c: add      r0, r4, #0x12c00
10004680: mov      r1, #3
10004684: add      r0, r0, #0x2d4
10004688: bl       #0x100003c8  ; ->msys::MLyt::getAnime
1000468c: cmp      r0, #0
10004690: beq      #0x100046b0
10004694: vldr     s0, [r0, #0xc]
10004698: vldr     s1, [pc, #0x28]  ; =0x0 (0)
1000469c: vcmp.f32 s0, s1
100046a0: vmrs     apsr_nzcv, fpscr
100046a4: ldrbne   r0, [r0, #0x12]
100046a8: tstne    r0, #1
100046ac: bne      #0x100046c4
100046b0: ldr      r1, [pc, #0x14]  ; =0x10008134
100046b4: add      r2, r4, #0x10000
100046b8: add      r2, r2, #0x2a00
100046bc: ldm      r1, {r0, r1}
100046c0: strd     r0, r1, [r2, #4]
100046c4: pop      {r4, pc}
100046c8: andeq    r0, r0, r0
100046cc: andne    r8, r0, r4, lsr r1
100046d0: push     {r3, r4, r5, lr}
100046d4: mov      r5, #0
100046d8: mov      r4, r0
100046dc: add      r0, r0, #0x12800
100046e0: mov      r3, r5
100046e4: mov      r2, #1
100046e8: mov      r1, r5
100046ec: add      r0, r0, #0x32c
100046f0: str      r5, [sp]
100046f4: bl       #0x100003e8  ; ->msys::MLyt::playAnimeFromNo
100046f8: add      r0, r4, #0x12c00
100046fc: mov      r3, #0
10004700: add      r0, r0, #0x2d4
10004704: str      r5, [sp]
10004708: mov      r2, #1
1000470c: mov      r1, r3
10004710: mov      r5, r0
10004714: bl       #0x100003e8  ; ->msys::MLyt::playAnimeFromNo
10004718: mov      r3, #0
1000471c: mov      r2, r3
10004720: add      r1, pc, #0x38
10004724: mov      r0, r5
10004728: bl       #0x100005e0  ; ->msys::MLyt::getPane
1000472c: ldrb     r1, [r0, #0x44]
10004730: mov      r2, #1
10004734: and      r1, r1, #0xfe
10004738: orr      r1, r1, #1
1000473c: strb     r1, [r0, #0x44]
10004740: ldr      r0, [pc, #0x20]  ; =0x28cd1
10004744: ldr      r1, [pc, #0x20]  ; =0x10008000
10004748: strb     r2, [r0, r4]
1000474c: add      r2, r4, #0x10000
10004750: ldrd     r0, r1, [r1, #0x9c]
10004754: add      r2, r2, #0x2a00
10004758: strd     r0, r1, [r2, #4]
1000475c: pop      {r3, r4, r5, pc}
10004760: strbmi   r4, [r7, #-0x150]
10004764: andeq    r3, r0, pc, asr r2
10004768: ldrdeq   r8, sb, [r2], -r1
1000476c: andne    r8, r0, r0
10004770: ldr      r2, [r0, #4]
10004774: mov      r1, #1
10004778: strb     r1, [r2, #0x14]
1000477c: ldr      r1, [pc, #0x10]  ; =0x10008000
10004780: add      r2, r0, #0x12800
10004784: add      r2, r2, #0x1fc
10004788: ldrd     r0, r1, [r1, #0x7c]
1000478c: strd     r0, r1, [r2]
10004790: bx       lr
10004794: andne    r8, r0, r0
10004798: push     {r4, lr}
1000479c: ldr      r1, [r1]
100047a0: ldr      r2, [pc, #0x64]  ; =0x802
100047a4: mov      r4, r0
100047a8: add      r0, r0, #0x13000
100047ac: tst      r1, r2
100047b0: beq      #0x100047d4
100047b4: ldr      r0, [r0, #0x2c4]
100047b8: ldr      r1, [r0]
100047bc: ldr      r1, [r1, #0x10]
100047c0: blx      r1
100047c4: mov      r1, #0
100047c8: mov      r0, r4
100047cc: bl       #0x10003d68
100047d0: b        #0x100047fc
100047d4: ldr      r2, [pc, #0x34]  ; =0x401
100047d8: tst      r1, r2
100047dc: beq      #0x100047fc
100047e0: ldr      r0, [r0, #0x2c0]
100047e4: ldr      r1, [r0]
100047e8: ldr      r1, [r1, #0x10]
100047ec: blx      r1
100047f0: mov      r1, #0
100047f4: mov      r0, r4
100047f8: bl       #0x10003d68
100047fc: add      r0, r4, #0x13000
10004800: add      r0, r0, #0x27c
10004804: bl       #0x10003648
10004808: pop      {r4, pc}
1000480c: andeq    r0, r0, r2, lsl #16
10004810: andeq    r0, r0, r1, lsl #8
10004814: bx       lr
10004818: push     {r4, r5, r6, lr}
1000481c: mov      r4, r0
10004820: mov      r3, #0
10004824: vpush    {d8}
10004828: add      r0, r0, #0x12800
1000482c: sub      sp, sp, #8
10004830: mov      r2, r3
10004834: add      r1, pc, #0xa0
10004838: add      r0, r0, #0x32c
1000483c: bl       #0x100003c0  ; ->msys::MLyt::createAnimeAutoSlot
10004840: mov      r3, #0
10004844: add      r0, r4, #0x12c00
10004848: mov      r2, r3
1000484c: add      r1, pc, #0x88
10004850: add      r0, r0, #0x2d4
10004854: bl       #0x100003c0  ; ->msys::MLyt::createAnimeAutoSlot
10004858: ldr      r0, [r4, #8]
1000485c: cmp      r0, #0
10004860: bne      #0x10004870
10004864: ldr      r0, [pc, #0x78]  ; =0x3f62a8 msys::MComSys::_sys
10004868: ldr      r0, [r0]
1000486c: str      r0, [r4, #8]
10004870: mov      r5, r0
10004874: mov      r0, #0xff
10004878: vldr     s16, [pc, #0x6c]  ; =0x41800000 (16)
1000487c: rev      r0, r0
10004880: mov      r6, sp
10004884: str      r0, [sp]
10004888: ldr      r0, [pc, #0x58]  ; =0x4acd4
1000488c: vmov.f32 s0, s16
10004890: mov      r1, r6
10004894: add      r0, r0, r5
10004898: bl       #0x100002e0  ; ->MoveC::moveFrm
1000489c: ldr      r0, [pc, #0x4c]  ; =0x4ad14
100048a0: vmov.f32 s0, s16
100048a4: mov      r1, r6
100048a8: add      r0, r0, r5
100048ac: bl       #0x100002e0  ; ->MoveC::moveFrm
100048b0: ldr      r0, [pc, #0x3c]  ; =0x3fbf9c gSndSys
100048b4: mov      r1, #0x10
100048b8: bl       #0x10000520  ; ->SndSys::stopAllBgm
100048bc: ldr      r1, [pc, #0x34]  ; =0x10008114
100048c0: add      r2, r4, #0x10000
100048c4: add      r2, r2, #0x2a00
100048c8: ldm      r1, {r0, r1}
100048cc: strd     r0, r1, [r2, #4]
100048d0: add      sp, sp, #8
100048d4: vpop     {d8}
100048d8: pop      {r4, r5, r6, pc}
100048dc: svcvs    #0x745f35
100048e0: andeq    r3, r0, pc, asr r3
100048e4: eorseq   r6, pc, r8, lsr #5
100048e8: ldrdeq   sl, fp, [r4], -r4
100048ec: orrmi    r0, r0, r0
100048f0: andeq    sl, r4, r4, lsl sp
100048f4: mlaseq   pc, ip, pc, fp
100048f8: andne    r8, r0, r4, lsl r1
100048fc: ldr      r1, [r0, #8]
10004900: cmp      r1, #0
10004904: bne      #0x10004914
10004908: ldr      r1, [pc, #0x38]  ; =0x3f62a8 msys::MComSys::_sys
1000490c: ldr      r1, [r1]
10004910: str      r1, [r0, #8]
10004914: ldr      r2, [pc, #0x30]  ; =0x4ad14
10004918: add      r1, r1, r2
1000491c: add      r1, r1, #0x2c
10004920: vldmia   r1, {s0, s1}
10004924: vcmpe.f32 s0, s1
10004928: vmrs     apsr_nzcv, fpscr
1000492c: blo      #0x10004944
10004930: add      r2, r0, #0x10000
10004934: ldr      r0, [pc, #0x14]  ; =0x100080cc
10004938: add      r2, r2, #0x2a00
1000493c: ldm      r0, {r0, r1}
10004940: strd     r0, r1, [r2, #4]
10004944: bx       lr
10004948: eorseq   r6, pc, r8, lsr #5
1000494c: andeq    sl, r4, r4, lsl sp
10004950: andne    r8, r0, ip, asr #1
10004954: push     {r3, r4, r5, r6, r7, lr}
10004958: mov      r4, r0
1000495c: mov      r5, #0
10004960: add      r0, r0, #0x12800
10004964: add      r0, r0, #0x32c
10004968: add      r3, pc, #0x5c
1000496c: mov      r2, r5
10004970: mov      r1, #3
10004974: mov      r6, r0
10004978: str      r5, [sp]
1000497c: bl       #0x100003e8  ; ->msys::MLyt::playAnimeFromNo
10004980: mov      r2, #1
10004984: mov      r3, #0
10004988: mov      r1, r2
1000498c: mov      r0, r6
10004990: str      r5, [sp]
10004994: bl       #0x100003e8  ; ->msys::MLyt::playAnimeFromNo
10004998: mov      r2, #1
1000499c: add      r0, r4, #0x12c00
100049a0: mov      r3, #0
100049a4: mov      r1, r2
100049a8: add      r0, r0, #0x2d4
100049ac: str      r5, [sp]
100049b0: bl       #0x100003e8  ; ->msys::MLyt::playAnimeFromNo
100049b4: ldr      r0, [pc, #0x1c]  ; =0x100080fc
100049b8: add      r2, r4, #0x10000
100049bc: add      r2, r2, #0x2a00
100049c0: ldm      r0, {r0, r1}
100049c4: strd     r0, r1, [r2, #4]
100049c8: pop      {r3, r4, r5, r6, r7, pc}
100049cc: svcpl    #0x505845
100049d0: svcpl    #0x4c4e50
100049d4: andeq    r0, r0, r5, asr r0
100049d8: strdne   r8, sb, [r0], -ip
100049dc: push     {r4, lr}
100049e0: mov      r4, r0
100049e4: add      r0, r0, #0x21c00
100049e8: mov      r2, #0
100049ec: add      r1, pc, #0x1c
100049f0: add      r0, r0, #0x58
100049f4: bl       #0x100038e0
100049f8: ldr      r0, [pc, #0x24]  ; =0x100081ac
100049fc: add      r2, r4, #0x10000
10004a00: add      r2, r2, #0x2a00
10004a04: ldm      r0, {r0, r1}
10004a08: strd     r0, r1, [r2, #4]
10004a0c: pop      {r4, pc}
10004a10: strbvc   r6, [lr, #-0x56d]!
10004a14: uqsaxvc  r7, r1, pc
10004a18: rsbvc    r5, r5, #0x194
10004a1c: teqlo    r0, #0x1c8
10004a20: andeq    r0, r0, r0
10004a24: andne    r8, r0, ip, lsr #3
10004a28: push     {r4, r5, r6, r7, r8, sb, sl, fp, lr}
10004a2c: mov      r4, r0
10004a30: add      r7, r0, #0x44000
10004a34: sub      sp, sp, #0x21c
10004a38: add      r1, r4, #0x21c00
10004a3c: ldr      r0, [r7, #0xc6c]
10004a40: add      r1, r1, #0x58
10004a44: str      r1, [sp, #4]
10004a48: mov      r5, #4
10004a4c: ldrh     r1, [r0, #0x7a]
10004a50: mov      fp, #0
10004a54: add      r1, r1, r1, lsl #1
10004a58: add      r2, r5, r1, lsl #2
10004a5c: ldr      r2, [r0, r2]
10004a60: cmp      r2, #0
10004a64: beq      #0x10004ac0
10004a68: add      r0, sp, #0x100
10004a6c: strh     fp, [sp, #8]
10004a70: str      fp, [sp, #0x208]
10004a74: strh     fp, [sp, #0x88]
10004a78: str      fp, [sp, #0x20c]
10004a7c: strh     fp, [r0, #8]
10004a80: str      fp, [sp, #0x210]
10004a84: strh     fp, [r0, #0x88]
10004a88: str      fp, [sp, #0x214]
10004a8c: ldr      r0, [r7, #0xc6c]
10004a90: mov      r2, #9
10004a94: ldrh     r1, [r0, #0x7a]
10004a98: add      r1, r1, r1, lsl #1
10004a9c: add      r2, r2, r1, lsl #2
10004aa0: ldrb     r2, [r0, r2]
10004aa4: cmp      r2, #0
10004aa8: beq      #0x10004bf8
10004aac: cmp      r2, #1
10004ab0: beq      #0x10004d58
10004ab4: cmp      r2, #2
10004ab8: beq      #0x10004f40
10004abc: b        #0x10005028
10004ac0: ldr      r1, [r0, r1, lsl #2]
10004ac4: ldr      r0, [sp, #4]
10004ac8: mov      r2, #0
10004acc: bl       #0x100038e0
10004ad0: add      r0, r4, #0x12800
10004ad4: mov      r3, #0
10004ad8: add      r0, r0, #0x32c
10004adc: mov      r2, r3
10004ae0: add      r1, pc, #0x3bc
10004ae4: mov      r6, r0
10004ae8: bl       #0x100003c0  ; ->msys::MLyt::createAnimeAutoSlot
10004aec: ldr      r1, [pc, #0x3bc]  ; =0x3f62a8 msys::MComSys::_sys
10004af0: ldr      r0, [r4, #8]
10004af4: cmp      r0, #0
10004af8: ldreq    r0, [r1]
10004afc: streq    r0, [r4, #8]
10004b00: cmp      r0, #0
10004b04: add      r3, r0, #0x4a000
10004b08: ldreq    r0, [r1]
10004b0c: add      r3, r3, #0xaa0
10004b10: streq    r0, [r4, #8]
10004b14: add      r0, r0, #0xe6000
10004b18: ldr      r2, [r0, #0x4f0]
10004b1c: ldr      r0, [r4, #4]
10004b20: ldr      r1, [r0, #0x18]
10004b24: mov      r0, #0x400
10004b28: str      r0, [sp]
10004b2c: add      r0, r4, #0x21000
10004b30: add      r0, r0, #0x78
10004b34: mov      r8, r0
10004b38: bl       #0x10000538  ; ->msys::MDfxChr::init
10004b3c: mov      r1, #0x33
10004b40: mov      r0, r8
10004b44: bl       #0x10000540  ; ->msys::MDfxChr::playDfx
10004b48: ldr      r0, [pc, #0x364]  ; =0x3f7eec _ZGVZN2nn4math4VEC34ZeroEvE4zero
10004b4c: add      r5, r4, #0x21000
10004b50: add      r5, r5, #0x144
10004b54: ldrb     r0, [r0]
10004b58: tst      r0, #1
10004b5c: bne      #0x10004b90
10004b60: ldr      r0, [pc, #0x34c]  ; =0x3f7eec _ZGVZN2nn4math4VEC34ZeroEvE4zero
10004b64: bl       #0x10000548  ; ->__cxa_guard_acquire
10004b68: cmp      r0, #0
10004b6c: nop      
10004b70: beq      #0x10004b90
10004b74: ldr      r0, [pc, #0x340]  ; =0x434c48 _ZZN2nn4math4VEC34ZeroEvE4zero
10004b78: vldr     s0, [pc, #0x338]  ; =0x0 (0)
10004b7c: vstr     s0, [r0]
10004b80: vstr     s0, [r0, #4]
10004b84: vstr     s0, [r0, #8]
10004b88: ldr      r0, [pc, #0x324]  ; =0x3f7eec _ZGVZN2nn4math4VEC34ZeroEvE4zero
10004b8c: bl       #0x10000550  ; ->__cxa_guard_release
10004b90: ldr      sb, [pc, #0x324]  ; =0x434c48 _ZZN2nn4math4VEC34ZeroEvE4zero
10004b94: mov      r0, r5
10004b98: bl       #0x100002d8  ; ->MoveVBase::stop
10004b9c: ldm      sb, {r0, r1, r2}
10004ba0: add      r3, r5, #0x1c
10004ba4: add      r5, r5, #4
10004ba8: stm      r3, {r0, r1, r2}
10004bac: mov      r3, #0
10004bb0: stm      r5, {r0, r1, r2}
10004bb4: add      r2, pc, #0x304
10004bb8: mov      r1, r8
10004bbc: mov      r0, r6
10004bc0: str      fp, [sp]
10004bc4: str      fp, [sp, #4]
10004bc8: bl       #0x10000428  ; ->msys::MLyt::attachMChr
10004bcc: mov      r3, #0
10004bd0: add      r0, r4, #0x12c00
10004bd4: mov      r2, r3
10004bd8: add      r1, pc, #0x2f4
10004bdc: add      r0, r0, #0x2d4
10004be0: bl       #0x100005e0  ; ->msys::MLyt::getPane
10004be4: add      r1, r0, #0x44
10004be8: ldrb     r0, [r0, #0x44]
10004bec: and      r0, r0, #0xfe
10004bf0: strb     r0, [r1]
10004bf4: b        #0x1000505c
10004bf8: ldr      r1, [r0, r1, lsl #2]
10004bfc: mov      sb, #0
10004c00: add      r8, sp, #8
10004c04: mov      r6, sb
10004c08: add      r2, r1, r6, lsl #1
10004c0c: ldrh     r0, [r2]
10004c10: cmp      r0, #0
10004c14: beq      #0x10004c38
10004c18: cmp      r0, #0xe
10004c1c: bne      #0x10004c2c
10004c20: ldrh     r0, [r2, #6]
10004c24: add      r0, r6, r0, lsr #1
10004c28: add      r6, r0, #3
10004c2c: add      r6, r6, #1
10004c30: cmp      r6, #0x40
10004c34: blo      #0x10004c08
10004c38: ldrh     r0, [r1]
10004c3c: cmp      r0, #0xe
10004c40: ldrheq   r0, [r1, #2]
10004c44: cmpeq    r0, #9
10004c48: subeq    r6, r6, #5
10004c4c: addeq    r1, r1, #0xa
10004c50: lsl      r2, r6, #1
10004c54: add      r0, r8, sb, lsl #7
10004c58: bl       #0x100004f8  ; ->Mem::Copy
10004c5c: add      r0, r8, sb, lsl #2
10004c60: mov      r8, #1
10004c64: str      r6, [r0, #0x200]
10004c68: ldr      r0, [r7, #0xc6c]
10004c6c: add      sb, sp, #8
10004c70: mov      r6, #0xa
10004c74: ldrh     r1, [r0, #0x7a]
10004c78: add      r1, r1, r1, lsl #1
10004c7c: add      r1, r5, r1, lsl #2
10004c80: mov      r5, r8
10004c84: ldr      sl, [r0, r1]
10004c88: mov      r1, r6
10004c8c: mov      r0, sl
10004c90: bl       #0x100005e8  ; ->__aeabi_uidivmod
10004c94: cmp      r0, #0
10004c98: nop      
10004c9c: beq      #0x10004cb4
10004ca0: add      r0, r6, r6, lsl #2
10004ca4: add      r5, r5, #1
10004ca8: cmp      r5, #0x40
10004cac: lsl      r6, r0, #1
10004cb0: blo      #0x10004c88
10004cb4: add      r0, sb, r8, lsl #7
10004cb8: ldr      r3, [pc, #0x21c]  ; =0x3f7ce4 _ZZN13MessageSimple8InsParam6setNumEhibEs
10004cbc: mov      r6, r0
10004cc0: mov      r2, #0x3f
10004cc4: mov      r1, #0x40
10004cc8: str      sl, [sp]
10004ccc: bl       #0x1000361c
10004cd0: ldr      r2, [pc, #0x208]  ; =0xfee0
10004cd4: cmp      r5, #0
10004cd8: beq      #0x10004d34
10004cdc: ands     r0, r5, #1
10004ce0: mov      r1, #0
10004ce4: beq      #0x10004cf8
10004ce8: ldrh     r3, [r6]
10004cec: mov      r1, #1
10004cf0: sub      r3, r3, #0x120
10004cf4: strh     r3, [r6]
10004cf8: cmp      r0, r5
10004cfc: bhs      #0x10004d34
10004d00: add      ip, r6, r1, lsl #1
10004d04: add      r1, r1, #1
10004d08: ldrh     sl, [ip]
10004d0c: add      r3, r6, r1, lsl #1
10004d10: add      r0, r0, #2
10004d14: add      sl, sl, r2
10004d18: strh     sl, [ip]
10004d1c: ldrh     ip, [r3]
10004d20: cmp      r0, r5
10004d24: add      r1, r1, #1
10004d28: add      ip, ip, r2
10004d2c: strh     ip, [r3]
10004d30: blo      #0x10004d00
10004d34: add      r0, sb, r8, lsl #2
10004d38: add      r2, sp, #8
10004d3c: str      r5, [r0, #0x200]
10004d40: ldr      r0, [sp, #4]
10004d44: add      r1, pc, #0x198
10004d48: bl       #0x100038e0
10004d4c: nop      
10004d50: nop      
10004d54: b        #0x10005028
10004d58: ldr      r1, [r0, r1, lsl #2]
10004d5c: mov      sb, #0
10004d60: add      r8, sp, #8
10004d64: mov      r6, sb
10004d68: add      r2, r1, r6, lsl #1
10004d6c: ldrh     r0, [r2]
10004d70: cmp      r0, #0
10004d74: beq      #0x10004d98
10004d78: cmp      r0, #0xe
10004d7c: bne      #0x10004d8c
10004d80: ldrh     r0, [r2, #6]
10004d84: add      r0, r6, r0, lsr #1
10004d88: add      r6, r0, #3
10004d8c: add      r6, r6, #1
10004d90: cmp      r6, #0x40
10004d94: blo      #0x10004d68
10004d98: ldrh     r0, [r1]
10004d9c: cmp      r0, #0xe
10004da0: ldrheq   r0, [r1, #2]
10004da4: cmpeq    r0, #9
10004da8: subeq    r6, r6, #5
10004dac: addeq    r1, r1, #0xa
10004db0: lsl      r2, r6, #1
10004db4: add      r0, r8, sb, lsl #7
10004db8: bl       #0x100004f8  ; ->Mem::Copy
10004dbc: add      r0, r8, sb, lsl #2
10004dc0: mov      r8, #1
10004dc4: str      r6, [r0, #0x200]
10004dc8: ldr      r0, [r7, #0xc6c]
10004dcc: add      sb, sp, #8
10004dd0: mov      r6, #0xa
10004dd4: ldrh     r1, [r0, #0x7a]
10004dd8: add      r1, r1, r1, lsl #1
10004ddc: add      r1, r5, r1, lsl #2
10004de0: mov      r5, r8
10004de4: ldr      sl, [r0, r1]
10004de8: mov      r1, r6
10004dec: mov      r0, sl
10004df0: bl       #0x100005e8  ; ->__aeabi_uidivmod
10004df4: cmp      r0, #0
10004df8: nop      
10004dfc: beq      #0x10004e14
10004e00: add      r0, r6, r6, lsl #2
10004e04: add      r5, r5, #1
10004e08: cmp      r5, #0x40
10004e0c: lsl      r6, r0, #1
10004e10: blo      #0x10004de8
10004e14: add      r0, sb, r8, lsl #7
10004e18: ldr      r3, [pc, #0xbc]  ; =0x3f7ce4 _ZZN13MessageSimple8InsParam6setNumEhibEs
10004e1c: mov      r6, r0
10004e20: mov      r2, #0x3f
10004e24: mov      r1, #0x40
10004e28: str      sl, [sp]
10004e2c: bl       #0x1000361c
10004e30: ldr      r2, [pc, #0xa8]  ; =0xfee0
10004e34: cmp      r5, #0
10004e38: beq      #0x10004e94
10004e3c: ands     r0, r5, #1
10004e40: mov      r1, #0
10004e44: beq      #0x10004e58
10004e48: ldrh     r3, [r6]
10004e4c: mov      r1, #1
10004e50: sub      r3, r3, #0x120
10004e54: strh     r3, [r6]
10004e58: cmp      r0, r5
10004e5c: bhs      #0x10004e94
10004e60: add      r3, r6, r1, lsl #1
10004e64: add      r1, r1, #1
10004e68: ldrh     sl, [r3]
10004e6c: add      ip, r6, r1, lsl #1
10004e70: add      r0, r0, #2
10004e74: add      sl, sl, r2
10004e78: strh     sl, [r3]
10004e7c: ldrh     r3, [ip]
10004e80: cmp      r0, r5
10004e84: add      r1, r1, #1
10004e88: add      r3, r3, r2
10004e8c: strh     r3, [ip]
10004e90: blo      #0x10004e60
10004e94: add      r0, sb, r8, lsl #2
10004e98: add      r2, sp, #8
10004e9c: add      r1, pc, #0x64
10004ea0: b        #0x10004f28
10004ea4: subpl    r4, sp, r3, asr #30
10004ea8: ldrbmi   r4, [r4, #-0x54c]
10004eac: subeq    r4, lr, pc, asr sb
10004eb0: eorseq   r6, pc, r8, lsr #5
10004eb4: eorseq   r7, pc, ip, ror #29
10004eb8: andeq    r0, r0, r0
10004ebc: subeq    r4, r3, r8, asr #24
10004ec0: svcpl    #0x534e49
10004ec4: subpl    r4, sp, r3, asr #30
10004ec8: ldrbmi   r4, [r4, #-0x54c]
10004ecc: .word    0x4646455f
10004ed0: subseq   r4, r4, r5, asr #6
10004ed4: strbmi   r4, [r7, #-0x150]
10004ed8: andeq    r3, r0, pc, asr r2
10004edc: eorseq   r7, pc, r4, ror #25
10004ee0: andeq    pc, r0, r0, ror #29
10004ee4: svcpl    #0x53454d
10004ee8: ldrbtmi  r6, [r3], #-0x54d
10004eec: ldclmi   p4, c7, [pc, #-0x184]
10004ef0: strbmi   r6, [sb, -sb, ror #28]!
10004ef4: svcpl    #0x656d61
10004ef8: svcpl    #0x646e65
10004efc: svcvs    #0x666e69
10004f00: cmpvs    pc, r1, lsr r0
10004f04: andeq    r6, r0, r4, ror #8
10004f08: svcpl    #0x53454d
10004f0c: ldrbtmi  r6, [r3], #-0x54d
10004f10: ldclmi   p4, c7, [pc, #-0x184]
10004f14: strbmi   r6, [sb, -sb, ror #28]!
10004f18: svcpl    #0x656d61
10004f1c: svcpl    #0x646e65
10004f20: svcvs    #0x666e69
10004f24: andeq    r3, r0, r1, lsr r0
10004f28: str      r5, [r0, #0x200]
10004f2c: ldr      r0, [sp, #4]
10004f30: bl       #0x100038e0
10004f34: nop      
10004f38: nop      
10004f3c: b        #0x10005028
10004f40: add      r1, r5, r1, lsl #2
10004f44: add      sb, sp, #8
10004f48: ldr      sl, [r0, r1]
10004f4c: mov      r8, #0
10004f50: mov      r6, #0xa
10004f54: mov      r5, #1
10004f58: mov      r1, r6
10004f5c: mov      r0, sl
10004f60: bl       #0x100005e8  ; ->__aeabi_uidivmod
10004f64: cmp      r0, #0
10004f68: nop      
10004f6c: beq      #0x10004f84
10004f70: add      r0, r6, r6, lsl #2
10004f74: add      r5, r5, #1
10004f78: cmp      r5, #0x40
10004f7c: lsl      r6, r0, #1
10004f80: blo      #0x10004f58
10004f84: add      r0, sb, r8, lsl #7
10004f88: ldr      r3, [pc, #-0xb4]  ; =0x3f7ce4 _ZZN13MessageSimple8InsParam6setNumEhibEs
10004f8c: mov      r6, r0
10004f90: mov      r2, #0x3f
10004f94: mov      r1, #0x40
10004f98: str      sl, [sp]
10004f9c: bl       #0x1000361c
10004fa0: ldr      r2, [pc, #-0xc8]  ; =0xfee0
10004fa4: cmp      r5, #0
10004fa8: beq      #0x10005004
10004fac: ands     r0, r5, #1
10004fb0: mov      r1, #0
10004fb4: beq      #0x10004fc8
10004fb8: ldrh     r3, [r6]
10004fbc: mov      r1, #1
10004fc0: sub      r3, r3, #0x120
10004fc4: strh     r3, [r6]
10004fc8: cmp      r0, r5
10004fcc: bhs      #0x10005004
10004fd0: add      r3, r6, r1, lsl #1
10004fd4: add      r1, r1, #1
10004fd8: ldrh     sl, [r3]
10004fdc: add      ip, r6, r1, lsl #1
10004fe0: add      r0, r0, #2
10004fe4: add      sl, sl, r2
10004fe8: strh     sl, [r3]
10004fec: ldrh     r3, [ip]
10004ff0: cmp      r0, r5
10004ff4: add      r1, r1, #1
10004ff8: add      r3, r3, r2
10004ffc: strh     r3, [ip]
10005000: blo      #0x10004fd0
10005004: add      r0, sb, r8, lsl #2
10005008: add      r2, sp, #8
1000500c: str      r5, [r0, #0x200]
10005010: ldr      r0, [r7, #0xc6c]
10005014: ldrh     r1, [r0, #0x7a]
10005018: add      r1, r1, r1, lsl #1
1000501c: ldr      r1, [r0, r1, lsl #2]
10005020: ldr      r0, [sp, #4]
10005024: bl       #0x100038e0
10005028: ldr      r0, [r7, #0xc6c]
1000502c: mov      r1, #8
10005030: ldr      r2, [r7, #0xc68]
10005034: ldrh     r3, [r0, #0x7a]
10005038: add      r3, r3, r3, lsl #1
1000503c: add      r1, r1, r3, lsl #2
10005040: ldrsb    r0, [r0, r1]
10005044: add      r0, r0, r0, lsl #1
10005048: add      r1, r2, r0, lsl #3
1000504c: add      r0, r4, #0x2fc00
10005050: mov      r2, #1
10005054: add      r0, r0, #0x228
10005058: bl       #0x10003b24
1000505c: mov      r3, #0
10005060: ldr      r1, [pc, #0x38]  ; =0x110025
10005064: mov      r2, r3
10005068: mov      r0, r4
1000506c: str      fp, [sp]
10005070: bl       #0x10003dd4
10005074: ldr      r0, [r7, #0xc6c]
10005078: add      r2, r4, #0x10000
1000507c: add      r2, r2, #0x2a00
10005080: ldrh     r1, [r0, #0x7a]
10005084: add      r1, r1, #1
10005088: strh     r1, [r0, #0x7a]
1000508c: ldr      r1, [pc, #0x10]  ; =0x10008000
10005090: ldrd     r0, r1, [r1, #0xec]
10005094: strd     r0, r1, [r2, #4]
10005098: add      sp, sp, #0x21c
1000509c: pop      {r4, r5, r6, r7, r8, sb, sl, fp, pc}
100050a0: andseq   r0, r1, r5, lsr #32
100050a4: andne    r8, r0, r0
100050a8: push     {r4, r5, r6, lr}
100050ac: mov      r4, r0
100050b0: add      r0, r0, #0x12c00
100050b4: add      r0, r0, #0x2d4
100050b8: bl       #0x100004d0  ; ->msys::MLyt::isEnableAnime
100050bc: cmp      r0, #0
100050c0: moveq    r5, #0
100050c4: bne      #0x10005148
100050c8: add      r0, r4, r5, lsl #2
100050cc: add      r0, r0, #0x13000
100050d0: ldr      r0, [r0, #0x2b8]
100050d4: ldr      r1, [r0]
100050d8: ldr      r2, [r1, #0x28]
100050dc: mov      r1, #0
100050e0: blx      r2
100050e4: add      r5, r5, #1
100050e8: cmp      r5, #4
100050ec: blt      #0x100050c8
100050f0: ldr      r0, [pc, #0x54]  ; =0x132c4
100050f4: ldr      r0, [r0, r4]
100050f8: ldr      r1, [r0]
100050fc: ldr      r2, [r1, #0x28]
10005100: mov      r1, #1
10005104: blx      r2
10005108: add      r0, r4, #0x2f000
1000510c: add      r0, r0, #0xe20
10005110: mov      r1, #0
10005114: mvn      r2, #0
10005118: stm      r0, {r1, r2}
1000511c: mov      r1, #1
10005120: mov      r0, r4
10005124: bl       #0x10003d68
10005128: ldr      r0, [pc, #0x20]  ; =0x10008000
1000512c: add      r1, r4, #0x12800
10005130: add      r1, r1, #0x204
10005134: ldrd     r2, r3, [r0, #0xa4]
10005138: add      r0, r0, #0xac
1000513c: strd     r2, r3, [r1], #8
10005140: ldm      r0, {r0, r2}
10005144: stm      r1, {r0, r2}
10005148: pop      {r4, r5, r6, pc}
1000514c: andeq    r3, r1, r4, asr #5
10005150: andne    r8, r0, r0
10005154: push     {r4, r5, r6, lr}
10005158: mov      r5, r1
1000515c: mov      r4, r0
10005160: bl       #0x10000490  ; ->atk_mg::GetBootInfo
10005164: bl       #0x100005f0  ; ->atk_mg::BootInfo::playBgm
10005168: cmp      r0, #0
1000516c: beq      #0x100051b8
10005170: ldr      r0, [pc, #0x44]  ; =0x10008000
10005174: add      r3, r4, #0x10000
10005178: add      r3, r3, #0x2a00
1000517c: mov      r1, r5
10005180: ldr      r2, [r0, #0xb4]
10005184: ldr      r0, [r0, #0xb8]
10005188: str      r2, [r3, #4]
1000518c: add      r2, r4, #0x12000
10005190: tst      r0, #1
10005194: str      r0, [r3, #8]
10005198: ldreq    r2, [r2, #0xa04]
1000519c: add      r0, r4, r0, asr #1
100051a0: beq      #0x100051b0
100051a4: ldr      r3, [r0]
100051a8: ldr      r2, [r2, #0xa04]
100051ac: ldr      r2, [r3, r2]
100051b0: pop      {r4, r5, r6, lr}
100051b4: bx       r2
100051b8: pop      {r4, r5, r6, pc}
100051bc: andne    r8, r0, r0
100051c0: push     {r4, r5, r6, lr}
100051c4: mov      r4, r0
100051c8: add      r0, r0, #0x28000
100051cc: add      r0, r0, #0xb90
100051d0: bl       #0x10000388  ; ->msys::MListWndPBase::getCurNo
100051d4: ldr      r1, [pc, #0x44]  ; =0x44c68
100051d8: add      r0, r0, r0, lsl #1
100051dc: ldr      r2, [r1, r4]
100051e0: mov      r1, #0x12
100051e4: add      r0, r1, r0, lsl #3
100051e8: ldrh     r5, [r2, r0]
100051ec: bl       #0x100004a0  ; ->btl::GetBootInfo
100051f0: mov      r1, r5
100051f4: bl       #0x100005f8  ; ->btl::BootInfo::setModePcAtkMiniGame
100051f8: ldr      r0, [r4, #8]
100051fc: cmp      r0, #0
10005200: bne      #0x10005210
10005204: ldr      r0, [pc, #0x18]  ; =0x3f62a8 msys::MComSys::_sys
10005208: ldr      r0, [r0]
1000520c: str      r0, [r4, #8]
10005210: ldr      r1, [r0, #4]
10005214: pop      {r4, r5, r6, lr}
10005218: mov      r0, #0xa
1000521c: b        #0x10000600  ; ->GameMain::Change
10005220: andeq    r4, r4, r8, ror #24
10005224: eorseq   r6, pc, r8, lsr #5
10005228: ldr      r1, [r0, #8]
1000522c: cmp      r1, #0
10005230: bne      #0x10005240
10005234: ldr      r1, [pc, #0x38]  ; =0x3f62a8 msys::MComSys::_sys
10005238: ldr      r1, [r1]
1000523c: str      r1, [r0, #8]
10005240: ldr      r2, [pc, #0x30]  ; =0x4ad14
10005244: add      r1, r1, r2
10005248: add      r1, r1, #0x2c
1000524c: vldmia   r1, {s0, s1}
10005250: vcmpe.f32 s0, s1
10005254: vmrs     apsr_nzcv, fpscr
10005258: blo      #0x10005270
1000525c: add      r2, r0, #0x10000
10005260: ldr      r0, [pc, #0x14]  ; =0x1000811c
10005264: add      r2, r2, #0x2a00
10005268: ldm      r0, {r0, r1}
1000526c: strd     r0, r1, [r2, #4]
10005270: bx       lr
10005274: eorseq   r6, pc, r8, lsr #5
10005278: andeq    sl, r4, r4, lsl sp
1000527c: andne    r8, r0, ip, lsl r1
10005280: push     {r3, r4, r5, r6, r7, lr}
10005284: mov      r4, r0
10005288: mov      r5, #0
1000528c: add      r0, r0, #0x12800
10005290: add      r0, r0, #0x32c
10005294: mov      r3, r5
10005298: mov      r2, r5
1000529c: mov      r1, #1
100052a0: mov      r6, r0
100052a4: str      r5, [sp]
100052a8: bl       #0x100003e8  ; ->msys::MLyt::playAnimeFromNo
100052ac: add      r0, r4, #0x12c00
100052b0: mov      r3, #0
100052b4: add      r0, r0, #0x2d4
100052b8: str      r5, [sp]
100052bc: mov      r2, r3
100052c0: mov      r1, #1
100052c4: mov      r5, r0
100052c8: bl       #0x100003e8  ; ->msys::MLyt::playAnimeFromNo
100052cc: mov      r2, #1
100052d0: mov      r1, #0
100052d4: mov      r0, r6
100052d8: bl       #0x10000460  ; ->msys::MLyt::setAnimeInfo
100052dc: mov      r2, #1
100052e0: mov      r1, #0
100052e4: mov      r0, r5
100052e8: bl       #0x10000460  ; ->msys::MLyt::setAnimeInfo
100052ec: ldr      r0, [pc, #0x1c]  ; =0x28cd1
100052f0: mov      r1, #1
100052f4: add      r2, r4, #0x10000
100052f8: add      r2, r2, #0x2a00
100052fc: strb     r1, [r0, r4]
10005300: ldr      r1, [pc, #0xc]  ; =0x10008000
10005304: ldrd     r0, r1, [r1, #0x94]
10005308: strd     r0, r1, [r2, #4]
1000530c: pop      {r3, r4, r5, r6, r7, pc}
10005310: ldrdeq   r8, sb, [r2], -r1
10005314: andne    r8, r0, r0
10005318: push     {r4, r5, r6, lr}
1000531c: mov      r4, r0
10005320: add      r0, r0, #0x28000
10005324: ldr      r1, [r0, #0x8a0]
10005328: cmp      r1, #0
1000532c: bne      #0x1000537c
10005330: ldr      r1, [r0, #0xb8c]
10005334: add      r0, r4, #0x21c00
10005338: add      r5, r4, #0x10000
1000533c: cmp      r1, #0
10005340: add      r0, r0, #0x58
10005344: add      r5, r5, #0x2a00
10005348: mov      r2, #0
1000534c: beq      #0x10005380
10005350: add      r1, pc, #0x40
10005354: bl       #0x100038e0
10005358: ldr      r0, [pc, #0x4c]  ; =0x3f40a8 Backup::_fs
1000535c: mov      r1, #0
10005360: ldr      r0, [r0]
10005364: strh     r1, [r0, #0x24]
10005368: add      r0, r4, #0x10
1000536c: bl       #0x10000370  ; ->Backup::format
10005370: ldr      r1, [pc, #0x38]  ; =0x100081a4
10005374: ldm      r1, {r0, r1}
10005378: strd     r0, r1, [r5, #4]
1000537c: pop      {r4, r5, r6, pc}
10005380: ldr      r1, [pc, #0x2c]  ; =0x10004a10
10005384: bl       #0x100038e0
10005388: ldr      r1, [pc, #0x28]  ; =0x100081ac
1000538c: ldm      r1, {r0, r1}
10005390: strd     r0, r1, [r5, #4]
10005394: pop      {r4, r5, r6, pc}
10005398: strbvc   r6, [lr, #-0x56d]!
1000539c: uqsaxvc  r7, r1, pc
100053a0: rsbvc    r5, r5, #0x194
100053a4: eorslo   r5, r0, #0x1c8
100053a8: andeq    r0, r0, r0
100053ac: eorseq   r4, pc, r8, lsr #1
100053b0: andne    r8, r0, r4, lsr #3
100053b4: andne    r4, r0, r0, lsl sl
100053b8: andne    r8, r0, ip, lsr #3
100053bc: push     {r4, r5, r6, r7, r8, sb, sl, fp, lr}
100053c0: mov      r4, r0
100053c4: add      r0, r0, #0x12c00
100053c8: add      r0, r0, #0x2d4
100053cc: mov      r1, #2
100053d0: vpush    {d8}
100053d4: sub      sp, sp, #0xc
100053d8: str      r0, [sp, #8]
100053dc: bl       #0x100003c8  ; ->msys::MLyt::getAnime
100053e0: cmp      r0, #0
100053e4: vldr     s16, [pc, #0x2b0]  ; =0x0 (0)
100053e8: vldrne   s0, [r0, #0xc]
100053ec: mov      r5, #0
100053f0: vcmpne.f32 s0, s16
100053f4: vmrsne   apsr_nzcv, fpscr
100053f8: ldrbne   r0, [r0, #0x12]
100053fc: tstne    r0, #1
10005400: bne      #0x1000544c
10005404: ldr      r0, [sp, #8]
10005408: mov      r3, #0
1000540c: mov      r2, #1
10005410: mov      r1, #3
10005414: str      r5, [sp]
10005418: bl       #0x100003e8  ; ->msys::MLyt::playAnimeFromNo
1000541c: add      r0, r4, #0x12000
10005420: ldr      r2, [pc, #0x278]  ; =0x10002b70
10005424: ldr      r1, [r0, #0xa0c]
10005428: add      r7, r4, #0x10000
1000542c: add      r7, r7, #0x2a00
10005430: cmp      r1, r2
10005434: ldreq    r0, [r0, #0xa10]
10005438: cmpeq    r0, #0
1000543c: beq      #0x10005458
10005440: ldr      r1, [pc, #0x25c]  ; =0x10008134
10005444: ldm      r1, {r0, r1}
10005448: strd     r0, r1, [r7, #4]
1000544c: add      sp, sp, #0xc
10005450: vpop     {d8}
10005454: pop      {r4, r5, r6, r7, r8, sb, sl, fp, pc}
10005458: nop      
1000545c: bl       #0x100004a0  ; ->btl::GetBootInfo
10005460: ldr      r0, [r0, #0x124]
10005464: cmp      r0, #0
10005468: beq      #0x10005684
1000546c: ldr      r0, [pc, #0x234]  ; =0x1325c
10005470: ldr      r0, [r0, r4]
10005474: ldrh     r0, [r0, #0x10]
10005478: cmp      r0, #1
1000547c: bne      #0x100054bc
10005480: ldr      r0, [sp, #8]
10005484: mov      r1, #4
10005488: bl       #0x100003c8  ; ->msys::MLyt::getAnime
1000548c: cmp      r0, #0
10005490: nop      
10005494: beq      #0x100054a4
10005498: ldrh     r1, [r0, #0x12]
1000549c: bic      r1, r1, #2
100054a0: strh     r1, [r0, #0x12]
100054a4: mov      r3, #0
100054a8: ldr      r1, [pc, #0x1fc]  ; =0x110024
100054ac: mov      r2, r3
100054b0: mov      r0, r4
100054b4: str      r5, [sp]
100054b8: bl       #0x10003dd4
100054bc: mov      r3, #0
100054c0: ldr      r0, [sp, #8]
100054c4: mov      r2, r3
100054c8: add      r1, pc, #0x1e0
100054cc: bl       #0x100003c0  ; ->msys::MLyt::createAnimeAutoSlot
100054d0: ldr      r8, [pc, #0x1e4]  ; =0x3f62a8 msys::MComSys::_sys
100054d4: ldr      r0, [r4, #8]
100054d8: cmp      r0, #0
100054dc: ldreq    r0, [r8]
100054e0: streq    r0, [r4, #8]
100054e4: cmp      r0, #0
100054e8: add      r3, r0, #0x4a000
100054ec: ldreq    r0, [r8]
100054f0: add      r3, r3, #0xaa0
100054f4: streq    r0, [r4, #8]
100054f8: add      r0, r0, #0xe6000
100054fc: ldr      r2, [r0, #0x4f0]
10005500: ldr      r0, [r4, #4]
10005504: ldr      r1, [r0, #0x18]
10005508: mov      r0, #0x400
1000550c: str      r0, [sp]
10005510: add      r0, r4, #0x20000
10005514: add      r0, r0, #0xd80
10005518: mov      sl, r0
1000551c: bl       #0x10000538  ; ->msys::MDfxChr::init
10005520: mov      r1, #0x26
10005524: mov      r0, sl
10005528: bl       #0x10000540  ; ->msys::MDfxChr::playDfx
1000552c: ldr      sb, [pc, #0x18c]  ; =0x3f7eec _ZGVZN2nn4math4VEC34ZeroEvE4zero
10005530: add      r6, r4, #0x20c00
10005534: add      r6, r6, #0x24c
10005538: ldrb     r0, [sb]
1000553c: tst      r0, #1
10005540: bne      #0x10005570
10005544: add      r0, sb, #0
10005548: bl       #0x10000548  ; ->__cxa_guard_acquire
1000554c: cmp      r0, #0
10005550: nop      
10005554: beq      #0x10005570
10005558: ldr      r0, [pc, #0x164]  ; =0x434c48 _ZZN2nn4math4VEC34ZeroEvE4zero
1000555c: vstr     s16, [r0]
10005560: vstr     s16, [r0, #4]
10005564: vstr     s16, [r0, #8]
10005568: add      r0, sb, #0
1000556c: bl       #0x10000550  ; ->__cxa_guard_release
10005570: ldr      fp, [pc, #0x14c]  ; =0x434c48 _ZZN2nn4math4VEC34ZeroEvE4zero
10005574: mov      r0, r6
10005578: bl       #0x100002d8  ; ->MoveVBase::stop
1000557c: ldm      fp, {r0, r1, r2}
10005580: add      r3, r6, #0x1c
10005584: add      r6, r6, #4
10005588: stm      r3, {r0, r1, r2}
1000558c: mov      r3, #0
10005590: stm      r6, {r0, r1, r2}
10005594: add      r0, r4, #0x12800
10005598: add      r2, pc, #0x128
1000559c: mov      r1, sl
100055a0: add      r0, r0, #0x32c
100055a4: str      r5, [sp]
100055a8: str      r5, [sp, #4]
100055ac: bl       #0x10000428  ; ->msys::MLyt::attachMChr
100055b0: ldr      r0, [r4, #8]
100055b4: ldr      r1, [pc, #0x11c]  ; =0x4aba4
100055b8: cmp      r0, #0
100055bc: ldreq    r0, [r8]
100055c0: streq    r0, [r4, #8]
100055c4: cmp      r0, #0
100055c8: add      r3, r0, r1
100055cc: ldreq    r0, [r8]
100055d0: streq    r0, [r4, #8]
100055d4: add      r0, r0, #0xe6000
100055d8: ldr      r2, [r0, #0x4f0]
100055dc: ldr      r0, [r4, #4]
100055e0: ldr      r1, [r0, #0x18]
100055e4: ldr      r0, [pc, #0xf0]  ; =0x401
100055e8: str      r0, [sp]
100055ec: add      r0, r4, #0x20c00
100055f0: add      r0, r0, #0x2fc
100055f4: mov      r6, r0
100055f8: bl       #0x10000538  ; ->msys::MDfxChr::init
100055fc: mov      r1, #0x27
10005600: mov      r0, r6
10005604: bl       #0x10000540  ; ->msys::MDfxChr::playDfx
10005608: ldrb     r0, [sb]
1000560c: add      r4, r4, #0x20c00
10005610: add      r4, r4, #0x3c8
10005614: tst      r0, #1
10005618: bne      #0x10005648
1000561c: ldr      r0, [pc, #0x9c]  ; =0x3f7eec _ZGVZN2nn4math4VEC34ZeroEvE4zero
10005620: bl       #0x10000548  ; ->__cxa_guard_acquire
10005624: cmp      r0, #0
10005628: nop      
1000562c: beq      #0x10005648
10005630: ldr      r0, [pc, #0x8c]  ; =0x434c48 _ZZN2nn4math4VEC34ZeroEvE4zero
10005634: vstr     s16, [r0]
10005638: vstr     s16, [r0, #4]
1000563c: vstr     s16, [r0, #8]
10005640: ldr      r0, [pc, #0x78]  ; =0x3f7eec _ZGVZN2nn4math4VEC34ZeroEvE4zero
10005644: bl       #0x10000550  ; ->__cxa_guard_release
10005648: ldr      r8, [pc, #0x74]  ; =0x434c48 _ZZN2nn4math4VEC34ZeroEvE4zero
1000564c: mov      r0, r4
10005650: bl       #0x100002d8  ; ->MoveVBase::stop
10005654: ldm      r8, {r0, r1, r2}
10005658: add      r3, r4, #0x1c
1000565c: add      r4, r4, #4
10005660: stm      r3, {r0, r1, r2}
10005664: mov      r3, #0
10005668: stm      r4, {r0, r1, r2}
1000566c: add      r2, pc, #0x54
10005670: ldr      r0, [sp, #8]
10005674: mov      r1, r6
10005678: str      r5, [sp]
1000567c: str      r5, [sp, #4]
10005680: bl       #0x10000428  ; ->msys::MLyt::attachMChr
10005684: ldr      r1, [pc, #0x54]  ; =0x1000812c
10005688: ldm      r1, {r0, r1}
1000568c: strd     r0, r1, [r7, #4]
10005690: add      sp, sp, #0xc
10005694: vpop     {d8}
10005698: pop      {r4, r5, r6, r7, r8, sb, sl, fp, pc}
1000569c: andeq    r0, r0, r0
100056a0: andne    r2, r0, r0, ror fp
100056a4: andne    r8, r0, r4, lsr r1
100056a8: andeq    r3, r1, ip, asr r2
100056ac: andseq   r0, r1, r4, lsr #32
100056b0: svcmi    #0x435342
100056b4: ldmdbmi  pc, {r1, r4, r6, r8, sl, lr} ^
100056b8: andeq    r0, r0, lr, asr #32
100056bc: eorseq   r6, pc, r8, lsr #5
100056c0: eorseq   r7, pc, ip, ror #29
100056c4: subeq    r4, r3, r8, asr #24
100056c8: svcpl    #0x534e49
100056cc: ldrbmi   r4, [pc, #-0x742]  ; =0x1040e3a0
100056d0: movtmi   r4, #0x5646
100056d4: andeq    r0, r0, r4, asr r0
100056d8: andeq    sl, r4, r4, lsr #23
100056dc: andeq    r0, r0, r1, lsl #8
100056e0: andne    r8, r0, ip, lsr #2
100056e4: push     {r4, r5, r6, lr}
100056e8: mov      r4, r0
100056ec: add      r0, r0, #0x12c00
100056f0: add      r0, r0, #0x2d4
100056f4: mov      r6, r0
100056f8: bl       #0x100004d0  ; ->msys::MLyt::isEnableAnime
100056fc: cmp      r0, #0
10005700: bne      #0x100057a0
10005704: add      r5, r4, #0x13000
10005708: add      r5, r5, #0x27c
1000570c: mov      r0, #0
10005710: strb     r0, [r5, #0x18]
10005714: mov      r1, #0xff
10005718: strb     r1, [r5, #0x19]
1000571c: mov      r1, #1
10005720: mov      r0, r5
10005724: bl       #0x10000458  ; ->msys::MCursorBase::setVisible
10005728: mov      r0, r5
1000572c: bl       #0x10003648
10005730: mov      r3, #0
10005734: mov      r2, r3
10005738: add      r1, pc, #0x64
1000573c: mov      r0, r6
10005740: bl       #0x100005e0  ; ->msys::MLyt::getPane
10005744: ldrb     r1, [r0, #0x44]
10005748: add      r5, r4, #0x13000
1000574c: and      r1, r1, #0xfe
10005750: orr      r1, r1, #1
10005754: strb     r1, [r0, #0x44]
10005758: ldr      r0, [r5, #0x2b8]
1000575c: ldr      r1, [r0]
10005760: ldr      r2, [r1, #0x28]
10005764: mov      r1, #1
10005768: blx      r2
1000576c: ldr      r0, [r5, #0x2bc]
10005770: ldr      r1, [r0]
10005774: ldr      r2, [r1, #0x28]
10005778: mov      r1, #1
1000577c: blx      r2
10005780: mov      r1, #1
10005784: mov      r0, r4
10005788: bl       #0x10003d68
1000578c: ldr      r1, [pc, #0x18]  ; =0x1000818c
10005790: add      r2, r4, #0x10000
10005794: add      r2, r2, #0x2a00
10005798: ldm      r1, {r0, r1}
1000579c: strd     r0, r1, [r2, #4]
100057a0: pop      {r4, r5, r6, pc}
100057a4: strbmi   r4, [r7, #-0x150]
100057a8: andeq    r3, r0, pc, asr r2
100057ac: andne    r8, r0, ip, lsl #3
100057b0: push     {r4, r5, r6, lr}
100057b4: mov      r4, r0
100057b8: add      r0, r0, #0x12c00
100057bc: add      r0, r0, #0x2d4
100057c0: bl       #0x100004d0  ; ->msys::MLyt::isEnableAnime
100057c4: cmp      r0, #0
100057c8: bne      #0x1000588c
100057cc: add      r5, r4, #0x13000
100057d0: add      r5, r5, #0x27c
100057d4: mov      r0, #2
100057d8: strb     r0, [r5, #0x18]
100057dc: mov      r1, #0xff
100057e0: strb     r1, [r5, #0x19]
100057e4: mov      r1, #1
100057e8: mov      r0, r5
100057ec: bl       #0x10000458  ; ->msys::MCursorBase::setVisible
100057f0: mov      r0, r5
100057f4: bl       #0x10003648
100057f8: mov      r5, #0
100057fc: add      r0, r4, r5, lsl #2
10005800: add      r0, r0, #0x13000
10005804: ldr      r0, [r0, #0x2b8]
10005808: ldr      r1, [r0]
1000580c: ldr      r2, [r1, #0x28]
10005810: mov      r1, #0
10005814: blx      r2
10005818: add      r5, r5, #1
1000581c: cmp      r5, #4
10005820: blt      #0x100057fc
10005824: add      r5, r4, #0x13000
10005828: ldr      r0, [r5, #0x2c0]
1000582c: ldr      r1, [r0]
10005830: ldr      r2, [r1, #0x28]
10005834: mov      r1, #1
10005838: blx      r2
1000583c: ldr      r0, [r5, #0x2c4]
10005840: ldr      r1, [r0]
10005844: ldr      r2, [r1, #0x28]
10005848: mov      r1, #1
1000584c: blx      r2
10005850: ldr      r0, [pc, #0x38]  ; =0x28cd1
10005854: mov      r1, #0
10005858: strb     r1, [r0, r4]
1000585c: mov      r1, #1
10005860: mov      r0, r4
10005864: bl       #0x10003d68
10005868: ldr      r3, [pc, #0x24]  ; =0x10008000
1000586c: add      r0, r4, #0x12800
10005870: add      r0, r0, #0x204
10005874: add      r1, r3, #0x10c
10005878: add      r3, r3, #0x104
1000587c: ldm      r3, {r2, r3}
10005880: strd     r2, r3, [r0], #8
10005884: ldm      r1, {r1, r2}
10005888: stm      r0, {r1, r2}
1000588c: pop      {r4, r5, r6, pc}
10005890: ldrdeq   r8, sb, [r2], -r1
10005894: andne    r8, r0, r0
10005898: push     {r4, lr}
1000589c: mov      r4, r0
100058a0: ldr      r0, [pc, #0x20]  ; =0x3e4730
100058a4: str      r0, [r4]
100058a8: add      r0, r4, #0x14c
100058ac: bl       #0x10000608  ; ->Message::term
100058b0: add      r0, r4, #0x14c
100058b4: bl       #0x10000610  ; ->Message
100058b8: sub      r0, r0, #0x14c
100058bc: bl       #0x100040e4
100058c0: pop      {r4, lr}
100058c4: b        #0x10000198  ; ->_ZdlPv
100058c8: eorseq   r4, lr, r0, lsr r7
100058cc: push     {r4, lr}
100058d0: mov      r4, r0
100058d4: ldr      r0, [pc, #0x1c]  ; =0x3e4730
100058d8: str      r0, [r4]
100058dc: add      r0, r4, #0x14c
100058e0: bl       #0x10000608  ; ->Message::term
100058e4: add      r0, r4, #0x14c
100058e8: bl       #0x10000610  ; ->Message
100058ec: sub      r0, r0, #0x14c
100058f0: bl       #0x100040e4
100058f4: pop      {r4, pc}
100058f8: eorseq   r4, lr, r0, lsr r7
100058fc: push     {r4, lr}
10005900: mov      r4, r0
10005904: bl       #0x10000618  ; ->msys::MListWndPBase::applyAnime
10005908: add      r0, r4, #0x7000
1000590c: pop      {r4, lr}
10005910: add      r0, r0, #0x60
10005914: b        #0x10000620  ; ->ad::lyt::Layout::Animate
10005918: push     {r4, r5, r6, r7, r8, sb, sl, fp, lr}
1000591c: mov      r4, r0
10005920: mov      r8, r1
10005924: vpush    {d8}
10005928: sub      sp, sp, #0x1ec
1000592c: ldr      r0, [r1, #8]
10005930: cmp      r0, #0
10005934: bne      #0x10005944
10005938: ldr      r0, [pc, #0x3c8]  ; =0x3f62a8 msys::MComSys::_sys
1000593c: ldr      r0, [r0]
10005940: str      r0, [r8, #8]
10005944: mov      r5, r0
10005948: ldr      r0, [pc, #0x3bc]  ; =0x44c70
1000594c: mov      r7, #0
10005950: add      r1, r4, #0x7000
10005954: add      r1, r1, #0x60
10005958: ldrsb    sb, [r0, r8]
1000595c: add      r0, r8, #0x12000
10005960: mov      r3, r7
10005964: add      r2, pc, #0x3a4
10005968: mov      r6, r1
1000596c: add      r0, r0, #0xa30
10005970: str      r7, [sp]
10005974: bl       #0x10000628  ; ->ad::lyt::LytResourceMan::buildLayout
10005978: add      r0, sp, #0x1a8
1000597c: nop      
10005980: bl       #0x10000408  ; ->ad::lyt::LytLocalize
10005984: mov      r1, r6
10005988: add      r0, sp, #0x1a8
1000598c: bl       #0x10000410  ; ->ad::lyt::LytLocalize::localize
10005990: vldr     s16, [pc, #0x390]  ; =0x0 (0)
10005994: add      r0, r4, #0x7000
10005998: vstr     s16, [sp, #0x1b8]
1000599c: add      r0, r0, #0xd8
100059a0: add      r3, pc, #0x384
100059a4: add      r2, pc, #0x384
100059a8: mov      r1, r6
100059ac: str      r0, [sp, #0x1e4]
100059b0: bl       #0x10000468  ; ->ad::lyt::LytAnim::init
100059b4: add      r0, r4, #0x7000
100059b8: add      r0, r0, #0x148
100059bc: add      r3, pc, #0x368
100059c0: add      r2, pc, #0x370
100059c4: mov      r1, r6
100059c8: str      r0, [sp, #0x1e8]
100059cc: bl       #0x10000468  ; ->ad::lyt::LytAnim::init
100059d0: vldr     s17, [pc, #0x36c]  ; =0x3f800000 (1)
100059d4: ldr      r0, [sp, #0x1e8]
100059d8: vmov.f32 s0, s17
100059dc: bl       #0x10000630  ; ->ad::lyt::LytAnim::playAuto
100059e0: add      r1, r4, #0x7000
100059e4: add      r1, r1, #0x9c
100059e8: add      r0, r5, #0x7d0
100059ec: mov      r3, #0
100059f0: add      r2, pc, #0x350
100059f4: mov      fp, r1
100059f8: str      r7, [sp]
100059fc: bl       #0x10000628  ; ->ad::lyt::LytResourceMan::buildLayout
10005a00: add      r0, r4, #0x7000
10005a04: add      r0, r0, #0xf4
10005a08: add      r3, pc, #0x31c
10005a0c: add      r2, pc, #0x344
10005a10: mov      r1, fp
10005a14: str      r0, [sp, #0x1dc]
10005a18: bl       #0x10000468  ; ->ad::lyt::LytAnim::init
10005a1c: add      r0, r4, #0x7000
10005a20: add      r0, r0, #0x110
10005a24: add      r3, pc, #0x300
10005a28: add      r2, pc, #0x334
10005a2c: mov      r1, fp
10005a30: str      r0, [sp, #0x1d8]
10005a34: bl       #0x10000468  ; ->ad::lyt::LytAnim::init
10005a38: add      r0, r4, #0x7000
10005a3c: add      r0, r0, #0x12c
10005a40: add      r3, pc, #0x2e4
10005a44: add      r2, pc, #0x320
10005a48: mov      r1, fp
10005a4c: str      r0, [sp, #0x1d4]
10005a50: bl       #0x10000468  ; ->ad::lyt::LytAnim::init
10005a54: add      r0, r8, #0x12800
10005a58: add      r0, r0, #0x2e8
10005a5c: str      r0, [sp, #4]
10005a60: bl       #0x10000638  ; ->ad::fw::Resource::getCA_anm
10005a64: str      r0, [sp, #0x1a0]
10005a68: ldr      r0, [sp, #4]
10005a6c: bl       #0x10000640  ; ->ad::fw::Resource::getCA_tex
10005a70: mov      sl, r0
10005a74: ldr      r0, [sp, #4]
10005a78: bl       #0x10000648  ; ->ad::fw::Resource::getCA_canm
10005a7c: ldr      r2, [sl]
10005a80: mov      r3, r0
10005a84: vmov.f32 s0, s17
10005a88: add      r0, r4, #0x7000
10005a8c: add      r0, r0, #0x164
10005a90: ldr      r1, [sp, #0x1a0]
10005a94: mov      sl, r0
10005a98: str      r7, [sp]
10005a9c: str      r7, [sp, #4]
10005aa0: bl       #0x10000650  ; ->CellAnime::init
10005aa4: add      r0, r4, #0x7200
10005aa8: add      r0, r0, #7
10005aac: ldrb     r1, [r0]
10005ab0: orr      r1, r1, #3
10005ab4: strb     r1, [r0]
10005ab8: strb     r7, [sl, #0x98]
10005abc: add      r0, sp, #0x28
10005ac0: strb     r7, [sl, #0x99]
10005ac4: bl       #0x10000658  ; ->ad::ui::UIListWindowPlusLyt::InitParam
10005ac8: mov      r1, #2
10005acc: add      r0, sp, #0x28
10005ad0: bl       #0x10000660  ; ->msys::SetMListWndInitParam
10005ad4: ldr      r0, [pc, #0x298]  ; =0xfffb50e8
10005ad8: str      sl, [sp, #0x30]
10005adc: mov      r2, #1
10005ae0: sub      r0, r5, r0
10005ae4: str      r0, [sp, #0x1c8]
10005ae8: add      r0, r0, #0x54
10005aec: str      r0, [sp, #0x28]
10005af0: ldr      r0, [r6, #0x10]
10005af4: ldr      r1, [r0]
10005af8: ldr      r3, [r1, #0x2c]
10005afc: add      r1, pc, #0x274
10005b00: blx      r3
10005b04: str      r0, [sp, #0x60]
10005b08: ldr      r0, [r6, #0x10]
10005b0c: cmp      sb, #0
10005b10: addne    r1, pc, #0x268
10005b14: addeq    r1, pc, #0x274
10005b18: ldr      r2, [r0]
10005b1c: ldr      r3, [r2, #0x2c]
10005b20: mov      r2, #1
10005b24: blx      r3
10005b28: str      r0, [sp, #0x58]
10005b2c: ldr      r0, [r6, #0x10]
10005b30: mov      r2, #1
10005b34: ldr      r1, [r0]
10005b38: ldr      r3, [r1, #0x2c]
10005b3c: add      r1, pc, #0x264
10005b40: blx      r3
10005b44: str      r0, [sp, #0x54]
10005b48: ldr      r0, [sp, #0x1e8]
10005b4c: cmp      sb, #0
10005b50: add      sl, r4, #0x4000
10005b54: str      r0, [sp, #0x88]
10005b58: ldr      r0, [sp, #0x1e4]
10005b5c: strb     r7, [sp, #0x90]
10005b60: add      sl, sl, #0x2f80
10005b64: str      r0, [sp, #0x84]
10005b68: ldr      r0, [fp, #0x10]
10005b6c: add      r1, sp, #0xc
10005b70: mov      r7, #1
10005b74: str      r0, [sp, #0x48]
10005b78: ldr      r0, [sp, #0x1dc]
10005b7c: str      sl, [sp, #0x164]
10005b80: add      r3, pc, #0x1a4
10005b84: str      r0, [sp, #0x78]
10005b88: ldr      r0, [sp, #0x1d8]
10005b8c: add      r2, pc, #0x220
10005b90: str      r0, [sp, #0x7c]
10005b94: ldr      r0, [sp, #0x1d4]
10005b98: str      r0, [sp, #0x80]
10005b9c: movne    r0, #4
10005ba0: moveq    r0, #6
10005ba4: strb     r0, [sp, #0x168]
10005ba8: mov      r0, #0
10005bac: strb     r0, [sp, #8]
10005bb0: vstmia   r1, {s16, s17}
10005bb4: mov      r1, r6
10005bb8: vstr     s16, [sp, #0x14]
10005bbc: strh     r7, [sp, #0x18]
10005bc0: strh     r0, [sp, #0x1a]
10005bc4: str      r0, [sp, #0x1c]
10005bc8: str      r0, [sp, #0x20]
10005bcc: add      r0, sp, #8
10005bd0: bl       #0x10000468  ; ->ad::lyt::LytAnim::init
10005bd4: vmov     s0, sb
10005bd8: add      r0, sp, #8
10005bdc: vcvt.f32.u32 s0, s0
10005be0: bl       #0x100003b0  ; ->ad::lyt::LytAnim::stopAndSetFrm
10005be4: mov      r1, #1
10005be8: add      r0, sp, #8
10005bec: bl       #0x10000478  ; ->ad::lyt::LytAnim::term
10005bf0: add      r3, pc, #0x134
10005bf4: add      r2, pc, #0x1c8
10005bf8: mov      r1, r6
10005bfc: add      r0, sp, #8
10005c00: bl       #0x10000468  ; ->ad::lyt::LytAnim::init
10005c04: vmov.f32 s0, s16
10005c08: add      r0, sp, #8
10005c0c: bl       #0x100003b0  ; ->ad::lyt::LytAnim::stopAndSetFrm
10005c10: mov      r1, #1
10005c14: add      r0, sp, #8
10005c18: bl       #0x10000478  ; ->ad::lyt::LytAnim::term
10005c1c: add      r3, pc, #0x108
10005c20: add      r2, pc, #0x1a8
10005c24: mov      r1, r6
10005c28: add      r0, sp, #8
10005c2c: bl       #0x10000468  ; ->ad::lyt::LytAnim::init
10005c30: ldr      r0, [sp, #0x1c]
10005c34: add      r6, sp, #8
10005c38: bl       #0x10000470  ; ->ad::lyt::AnimTransform::GetFrameSize
10005c3c: vmov     s0, r0
10005c40: mov      r0, r6
10005c44: vcvt.f32.u32 s0, s0
10005c48: bl       #0x100003b0  ; ->ad::lyt::LytAnim::stopAndSetFrm
10005c4c: mov      r1, #1
10005c50: add      r0, sp, #8
10005c54: bl       #0x10000478  ; ->ad::lyt::LytAnim::term
10005c58: cmp      sb, #0
10005c5c: vstr     s16, [sp, #0x14]
10005c60: ldrb     r1, [sp, #0x168]
10005c64: movne    r2, #0xa
10005c68: moveq    r2, #0
10005c6c: ldr      r0, [pc, #0x16c]  ; =0x3f95f0 gGameWork
10005c70: cmp      r1, #0
10005c74: addgt    fp, r8, #0x44000
10005c78: add      r2, r0, r2, lsl #1
10005c7c: addgt    r8, r5, #0xe9000
10005c80: mov      r6, #0
10005c84: add      sb, r2, #0x7d0
10005c88: addgt    r8, r8, #0x50
10005c8c: ble      #0x10005e5c
10005c90: ldr      r0, [fp, #0xc68]
10005c94: add      r1, r6, r6, lsl #1
10005c98: mov      r2, #0x12
10005c9c: add      r1, r2, r1, lsl #3
10005ca0: ldrh     r0, [r0, r1]
10005ca4: bl       #0x10000390  ; ->ad::db::GetPcAttack
10005ca8: mov      r7, r0
10005cac: ldrh     r0, [r0, #0xe]
10005cb0: ldr      r1, [pc, #0x12c]  ; =0x7fff87f
10005cb4: ldr      r2, [pc, #0x124]  ; =0x3f95f0 gGameWork
10005cb8: and      r1, r1, r0, lsr #5
10005cbc: and      r0, r0, #0x1f
10005cc0: add      r1, r2, r1, lsl #2
10005cc4: ldr      r1, [r1, #0x20c]
10005cc8: lsr      r0, r1, r0
10005ccc: tst      r0, #1
10005cd0: beq      #0x10005e00
10005cd4: ldrb     r0, [r7, #8]
10005cd8: strb     r0, [sl, #0xb]
10005cdc: bl       #0x10000590  ; ->ad::db::GetItemMsgAcs
10005ce0: ldr      r1, [r7]
10005ce4: mov      r7, r0
10005ce8: add      r0, r0, #8
10005cec: bl       #0x100003d0  ; ->LMS_GetTextIndexByLabel
10005cf0: mov      r1, r0
10005cf4: add      r0, r7, #8
10005cf8: bl       #0x100003d8  ; ->LMS_GetText
10005cfc: nop      
10005d00: nop      
10005d04: b        #0x10005de8
10005d08: eorseq   r6, pc, r8, lsr #5
10005d0c: andeq    r4, r4, r0, ror ip
10005d10: stmdbmi  lr, {r0, r2, r3, r6, r8, fp, lr} ^
10005d14: strbmi   r4, [sp, #-0x147]
10005d18: mrrcmi   p12, #5, r4, pc, c15
10005d1c: cdphs    p3, #5, c5, c4, c9, #2
10005d20: stmdbvc  ip!, {r1, r5, r6, sb, sl, sp, lr} ^
10005d24: andeq    r0, r0, r4, ror r0
10005d28: andeq    r0, r0, r0
10005d2c: andeq    r0, r0, r0
10005d30: cmnvs    r5, #116, #30
10005d34: andeq    r0, r0, r8, rrx
10005d38: ldrbmi   r5, [r4, #-0x441]
10005d3c: svcmi    #0x49544e
10005d40: andeq    r0, r0, lr, asr #32
10005d44: svclo    #0x800000
10005d48: svcpl    #0x4d554e
10005d4c: cdphs    p15, #7, c5, c3, c7, #2
10005d50: stmdbvc  ip!, {r1, r5, r6, sb, sl, sp, lr} ^
10005d54: andeq    r0, r0, r4, ror r0
10005d58: svcpl    #0x6d756e
10005d5c: svcpl    #0x746573
10005d60: andeq    r0, r0, r5, asr r0
10005d64: svcpl    #0x6c6f63
10005d68: eorseq   r3, r6, r3, ror r0
10005d6c: svcpl    #0x6c6f63
10005d70: andeq    r3, r0, r0, lsr r2
10005d74: .word    0xfffb50e8
10005d78: stclmi   p2, c5, [r1, #-0x118]
10005d7c: andeq    r0, r0, r5, asr #32
10005d80: ldrbtvc  r6, [r3], #-0x96c
10005d84: rsbsvc   r6, r5, #0x7c000001
10005d88: svcpl    #0x726f73
10005d8c: rsbeq    r6, sb, r2, asr #24
10005d90: ldrbtvc  r6, [r3], #-0x96c
10005d94: rsbsvc   r6, r5, #0x7c000001
10005d98: svcpl    #0x726f73
10005d9c: stclvs   p8, c6, [pc], #-0x10c
10005da0: ldrbvs   r7, [r4, #-0x365]!
10005da4: andeq    r0, r0, r0
10005da8: ldrbtvc  r6, [r3], #-0x96c
10005dac: rsbvc    r7, r3, #0x7c000001
10005db0: rsbeq    r6, ip, pc, ror #24
10005db4: svcpl    #0x544553
10005db8: ldrbpl   r4, [r3], #-0x94c
10005dbc: mcrrmi   p3, #5, r4, pc, c15
10005dc0: andeq    r0, r0, r0
10005dc4: cdpmi    p3, #4, c4, c15, c9, #2
10005dc8: uqsaxvs  r6, r6, pc
10005dcc: andeq    r6, r0, pc, ror #28
10005dd0: svcpl    #0x544553
10005dd4: cmppl    r2, #0x10c00000
10005dd8: ldmdami  pc, {r0, r1, r2, r3, r6, sb, ip, lr} ^
10005ddc: andeq    r4, r0, sb, asr #24
10005de0: ldrshteq sb, [pc], -r0
10005de4: .word    0x07fff87f
10005de8: str      r0, [sl, #0x10]
10005dec: ldrsh    r0, [sb]
10005df0: cmp      r0, #0
10005df4: ldrlt    r0, [pc, #0xa4]  ; =0xffff
10005df8: strh     r0, [sl, #4]
10005dfc: b        #0x10005e30
10005e00: mov      r0, #0xff
10005e04: strb     r0, [sl, #0xb]
10005e08: add      r1, pc, #0x94
10005e0c: add      r0, r8, #8
10005e10: bl       #0x100003d0  ; ->LMS_GetTextIndexByLabel
10005e14: mov      r1, r0
10005e18: add      r0, r8, #8
10005e1c: bl       #0x100003d8  ; ->LMS_GetText
10005e20: mov      r1, r0
10005e24: mvn      r0, #0
10005e28: str      r1, [sl, #0x10]
10005e2c: strh     r0, [sl, #4]
10005e30: str      r6, [sl], #0xe
10005e34: mov      r1, #1
10005e38: strb     r1, [sl], #0xe
10005e3c: mov      r0, #0
10005e40: strb     r0, [sl, #-0xd]
10005e44: str      r0, [sl, #-8]
10005e48: ldrb     r0, [sp, #0x168]
10005e4c: add      r6, r6, #1
10005e50: add      sb, sb, #2
10005e54: cmp      r0, r6
10005e58: bgt      #0x10005c90
10005e5c: ldr      r0, [sp, #0x1c8]
10005e60: add      r3, r5, #0xd0000
10005e64: add      r3, r3, #0x3100
10005e68: add      r1, r0, #0x3c
10005e6c: add      r0, r5, #0x14800
10005e70: add      r0, r0, #0x7c
10005e74: strd     r0, r1, [sp]
10005e78: add      r2, r5, #0xd3000
10005e7c: add      r1, sp, #0x28
10005e80: mov      r0, r4
10005e84: bl       #0x10000668  ; ->msys::MListWndPBase::init
10005e88: ldr      r0, [pc, #0x30]  ; =0x401
10005e8c: str      r0, [r4, #0x13c]
10005e90: str      r0, [r4, #0x168]
10005e94: add      sp, sp, #0x1ec
10005e98: vpop     {d8}
10005e9c: pop      {r4, r5, r6, r7, r8, sb, sl, fp, pc}
10005ea0: .word    0x0000ffff
10005ea4: svcpl    #0x53454d
10005ea8: .word    0x73654d45
10005eac: svcvs    #0x6c6f43
10005eb0: strbvc   r7, [r5, #-0x373]!
10005eb4: stclvs   p15, c5, [r3], #-0x1b4
10005eb8: svcpl    #0x737361
10005ebc: andeq    r0, r0, r0, lsr r0
10005ec0: andeq    r0, r0, r1, lsl #8
10005ec4: ldr      r1, [pc, #0x58]  ; =0x10008980
10005ec8: push     {r4, lr}
10005ecc: str      r1, [r0], #0x164
10005ed0: add      r0, r0, #0x7000
10005ed4: bl       #0x10000670  ; ->CellAnime
10005ed8: vldr     s0, [pc, #0x48]  ; =0x0 (0)
10005edc: vstr     s0, [r0, #-0x10]
10005ee0: vstr     s0, [r0, #-0x2c]
10005ee4: vstr     s0, [r0, #-0x48]
10005ee8: vstr     s0, [r0, #-0x64]
10005eec: vstr     s0, [r0, #-0x80]
10005ef0: sub      r0, r0, #0xc8
10005ef4: bl       #0x10000678  ; ->ad::lyt::Layout
10005ef8: sub      r0, r0, #0x3c
10005efc: bl       #0x10000678  ; ->ad::lyt::Layout
10005f00: ldr      r1, [pc, #0x24]  ; =0x100088d8
10005f04: sub      r0, r0, #0x7000
10005f08: sub      r0, r0, #0x60
10005f0c: str      r1, [r0], #0x1fc
10005f10: bl       #0x100001d0  ; ->ad::ui::UIListWindowPlusLyt
10005f14: sub      r0, r0, #0x1fc
10005f18: bl       #0x100001f8  ; ->msys::MListWndPBase
10005f1c: pop      {r4, lr}
10005f20: b        #0x10000198  ; ->_ZdlPv
10005f24: andne    r8, r0, r0, lsl #19
10005f28: andeq    r0, r0, r0
10005f2c: ldrdne   r8, sb, [r0], -r8
10005f30: ldr      r1, [pc, #0x54]  ; =0x10008980
10005f34: push     {r4, lr}
10005f38: str      r1, [r0], #0x164
10005f3c: add      r0, r0, #0x7000
10005f40: bl       #0x10000670  ; ->CellAnime
10005f44: vldr     s0, [pc, #0x44]  ; =0x0 (0)
10005f48: vstr     s0, [r0, #-0x10]
10005f4c: vstr     s0, [r0, #-0x2c]
10005f50: vstr     s0, [r0, #-0x48]
10005f54: vstr     s0, [r0, #-0x64]
10005f58: vstr     s0, [r0, #-0x80]
10005f5c: sub      r0, r0, #0xc8
10005f60: bl       #0x10000678  ; ->ad::lyt::Layout
10005f64: sub      r0, r0, #0x3c
10005f68: bl       #0x10000678  ; ->ad::lyt::Layout
10005f6c: ldr      r1, [pc, #0x20]  ; =0x100088d8
10005f70: sub      r0, r0, #0x7000
10005f74: sub      r0, r0, #0x60
10005f78: str      r1, [r0], #0x1fc
10005f7c: bl       #0x100001d0  ; ->ad::ui::UIListWindowPlusLyt
10005f80: pop      {r4, lr}
10005f84: sub      r0, r0, #0x1fc
10005f88: b        #0x100001f8  ; ->msys::MListWndPBase
10005f8c: andne    r8, r0, r0, lsl #19
10005f90: andeq    r0, r0, r0
10005f94: ldrdne   r8, sb, [r0], -r8
10005f98: push     {r0, r4, r5, r6, r7, r8, sb, sl, fp, lr}
10005f9c: sub      sp, sp, #8
10005fa0: mov      sl, #1
10005fa4: ldr      r0, [sp, #8]
10005fa8: ldr      r6, [pc, #0x48c]  ; =0x3f95f0 gGameWork
10005fac: add      sb, r0, #0x40000
10005fb0: add      sb, sb, #0x4c00
10005fb4: add      r1, r6, #0x810
10005fb8: ldrb     r0, [sb, #0x70]
10005fbc: cmp      r0, #0
10005fc0: movne    r0, #0x3f
10005fc4: moveq    r0, #0x2d
10005fc8: lsr      r2, r0, #5
10005fcc: and      r0, r0, #0x1f
10005fd0: ldr      r1, [r1, r2, lsl #2]
10005fd4: tst      r1, sl, lsl r0
10005fd8: bne      #0x10006430
10005fdc: ldr      r0, [sp, #8]
10005fe0: mov      r2, #0
10005fe4: ldr      r0, [r0, #4]
10005fe8: ldr      r0, [r0, #0x18]
10005fec: ldr      r1, [r0]
10005ff0: ldr      r3, [r1, #0xc]
10005ff4: mov      r1, #0x7c
10005ff8: blx      r3
10005ffc: ldr      r1, [sp, #8]
10006000: mov      r2, #0x7c
10006004: add      r4, r1, #0x44000
10006008: mov      r1, #0
1000600c: str      r0, [r4, #0xc6c]
10006010: bl       #0x10000680  ; ->Mem::Fill
10006014: ldrsb    r0, [sb, #0x70]
10006018: mov      r3, #0
1000601c: mov      r7, r3
10006020: cmp      r0, #0
10006024: movne    r0, #0xa
10006028: moveq    r0, #0
1000602c: movne    r5, #0x2e
10006030: add      r0, r6, r0, lsl #1
10006034: moveq    r5, #0x10
10006038: add      r8, r0, #0x7d0
1000603c: str      r3, [sp]
10006040: ldr      r1, [r4, #0xc68]
10006044: add      r6, r7, r7, lsl #1
10006048: mov      r0, #0x12
1000604c: add      sl, r0, r6, lsl #3
10006050: ldrh     r0, [r1, sl]
10006054: bl       #0x10000390  ; ->ad::db::GetPcAttack
10006058: ldrh     r1, [r0, #0xe]
1000605c: ldr      r2, [pc, #0x3dc]  ; =0x7fff87f
10006060: ldr      r0, [pc, #0x3d4]  ; =0x3f95f0 gGameWork
10006064: and      r2, r2, r1, lsr #5
10006068: and      r1, r1, #0x1f
1000606c: add      r2, r0, r2, lsl #2
10006070: ldr      r2, [r2, #0x20c]
10006074: lsr      r1, r2, r1
10006078: tst      r1, #1
1000607c: beq      #0x10006334
10006080: ldr      r1, [r4, #0xc68]
10006084: ldrsh    r2, [r8]
10006088: add      r1, r1, r6, lsl #3
1000608c: ldrsh    r1, [r1]
10006090: cmp      r1, r2
10006094: bgt      #0x10006334
10006098: lsr      r2, r5, #5
1000609c: add      r0, r0, #0x810
100060a0: and      r3, r5, #0x1f
100060a4: ldr      r1, [r0, r2, lsl #2]
100060a8: mov      r0, #1
100060ac: lsl      r0, r0, r3
100060b0: tst      r1, r0
100060b4: bne      #0x10006110
100060b8: orr      ip, r1, r0
100060bc: ldr      r0, [pc, #0x380]  ; =0x3f9e00
100060c0: mov      r1, #4
100060c4: mov      r3, #6
100060c8: add      lr, r3, r6, lsl #3
100060cc: str      ip, [r0, r2, lsl #2]
100060d0: ldr      r0, [r4, #0xc6c]
100060d4: ldr      fp, [r4, #0xc68]
100060d8: mov      r3, #9
100060dc: mov      r2, #0
100060e0: ldrh     ip, [r0, #0x78]
100060e4: ldrsh    fp, [fp, lr]
100060e8: add      ip, ip, ip, lsl #1
100060ec: add      r1, r1, ip, lsl #2
100060f0: ldr      ip, [r0, r1]
100060f4: add      ip, ip, fp
100060f8: str      ip, [r0, r1]
100060fc: ldr      r0, [r4, #0xc6c]
10006100: ldrh     r1, [r0, #0x78]
10006104: add      r1, r1, r1, lsl #1
10006108: add      r1, r3, r1, lsl #2
1000610c: strb     r2, [r0, r1]
10006110: ldr      r2, [r4, #0xc68]
10006114: mov      r0, #2
10006118: add      r0, r0, r6, lsl #3
1000611c: ldrsh    r1, [r8]
10006120: ldrsh    r0, [r2, r0]
10006124: cmp      r0, r1
10006128: bgt      #0x10006290
1000612c: ldr      r2, [pc, #0x310]  ; =0x3f9e00
10006130: add      r0, r5, #1
10006134: and      ip, r0, #0x1f
10006138: lsr      r1, r0, #5
1000613c: mov      r3, #1
10006140: ldr      r0, [r2, r1, lsl #2]
10006144: lsl      r2, r3, ip
10006148: tst      r0, r2
1000614c: bne      #0x100061b0
10006150: orr      ip, r0, r2
10006154: ldr      r0, [pc, #0x2e8]  ; =0x3f9e00
10006158: mov      r2, #4
1000615c: mov      r3, #8
10006160: add      lr, r3, r6, lsl #3
10006164: str      ip, [r0, r1, lsl #2]
10006168: ldr      r0, [r4, #0xc6c]
1000616c: mov      r3, #9
10006170: mov      r1, #1
10006174: str      r0, [sp, #4]
10006178: ldrh     ip, [r0, #0x78]
1000617c: ldr      fp, [r4, #0xc68]
10006180: add      ip, ip, ip, lsl #1
10006184: ldrsh    fp, [fp, lr]
10006188: add      r2, r2, ip, lsl #2
1000618c: ldr      r0, [r0, r2]
10006190: add      ip, r0, fp
10006194: ldr      r0, [sp, #4]
10006198: str      ip, [r0, r2]
1000619c: ldr      r0, [r4, #0xc6c]
100061a0: ldrh     r2, [r0, #0x78]
100061a4: add      r2, r2, r2, lsl #1
100061a8: add      r2, r3, r2, lsl #2
100061ac: strb     r1, [r0, r2]
100061b0: ldr      r0, [r4, #0xc68]
100061b4: mov      fp, #4
100061b8: add      r1, fp, r6, lsl #3
100061bc: ldrsh    r2, [r8]
100061c0: ldrsh    r0, [r0, r1]
100061c4: cmp      r0, r2
100061c8: bgt      #0x10006290
100061cc: ldr      r2, [pc, #0x268]  ; =0x3f95f0 gGameWork
100061d0: add      r1, r5, #2
100061d4: mov      ip, #1
100061d8: add      r3, r2, #0x810
100061dc: lsr      r0, r1, #5
100061e0: and      r1, r1, #0x1f
100061e4: ldr      r3, [r3, r0, lsl #2]
100061e8: lsl      r1, ip, r1
100061ec: tst      r3, r1
100061f0: bne      #0x10006284
100061f4: orr      r3, r3, r1
100061f8: add      r1, r2, #0x810
100061fc: mov      r2, #1
10006200: str      r3, [r1, r0, lsl #2]
10006204: ldr      r1, [r4, #0xc68]
10006208: mov      r0, #0x10
1000620c: add      r0, r0, r6, lsl #3
10006210: ldrh     r1, [r1, r0]
10006214: ldr      r0, [pc, #0x220]  ; =0x3f95f0 gGameWork
10006218: bl       #0x10000688  ; ->GameWork::addItem
1000621c: ldr      r0, [r4, #0xc6c]
10006220: ldr      r3, [r4, #0xc68]
10006224: mov      r1, #0xa
10006228: add      r1, r1, r6, lsl #3
1000622c: ldrh     ip, [r0, #0x78]
10006230: ldrsh    r3, [r3, r1]
10006234: mov      r2, #0xc
10006238: add      r6, r2, r6, lsl #3
1000623c: add      ip, ip, ip, lsl #1
10006240: mov      r2, #9
10006244: add      ip, fp, ip, lsl #2
10006248: mov      r1, #2
1000624c: ldr      fp, [r0, ip]
10006250: add      r3, r3, fp
10006254: str      r3, [r0, ip]
10006258: ldr      r0, [r4, #0xc6c]
1000625c: ldr      ip, [r4, #0xc68]
10006260: ldrh     r3, [r0, #0x78]
10006264: ldr      ip, [ip, r6]
10006268: add      r3, r3, r3, lsl #1
1000626c: str      ip, [r0, r3, lsl #2]
10006270: ldr      r0, [r4, #0xc6c]
10006274: ldrh     r3, [r0, #0x78]
10006278: add      r3, r3, r3, lsl #1
1000627c: add      r2, r2, r3, lsl #2
10006280: strb     r1, [r0, r2]
10006284: ldr      r0, [sp]
10006288: add      r0, r0, #1
1000628c: str      r0, [sp]
10006290: ldr      r0, [r4, #0xc6c]
10006294: mov      r1, #4
10006298: ldrh     r2, [r0, #0x78]
1000629c: add      r2, r2, r2, lsl #1
100062a0: add      r1, r1, r2, lsl #2
100062a4: ldr      r1, [r0, r1]
100062a8: cmp      r1, #0
100062ac: beq      #0x10006334
100062b0: ldr      r0, [pc, #0x184]  ; =0x3f95f0 gGameWork
100062b4: bl       #0x10000690  ; ->GameWork::addCoin
100062b8: ldr      r0, [r4, #0xc6c]
100062bc: ldrh     r1, [r0, #0x78]
100062c0: add      r1, r1, r1, lsl #1
100062c4: ldr      r0, [r0, r1, lsl #2]
100062c8: cmp      r0, #0
100062cc: bne      #0x1000630c
100062d0: bl       #0x10000590  ; ->ad::db::GetItemMsgAcs
100062d4: mov      r6, r0
100062d8: ldr      r0, [r4, #0xc68]
100062dc: ldrh     r0, [r0, sl]
100062e0: bl       #0x10000390  ; ->ad::db::GetPcAttack
100062e4: ldr      r1, [r0]
100062e8: add      r0, r6, #8
100062ec: bl       #0x100003d0  ; ->LMS_GetTextIndexByLabel
100062f0: mov      r1, r0
100062f4: add      r0, r6, #8
100062f8: bl       #0x100003d8  ; ->LMS_GetText
100062fc: ldr      r1, [r4, #0xc6c]
10006300: ldrh     r2, [r1, #0x78]
10006304: add      r2, r2, r2, lsl #1
10006308: str      r0, [r1, r2, lsl #2]
1000630c: ldr      r0, [r4, #0xc6c]
10006310: mov      r1, #8
10006314: ldrh     r2, [r0, #0x78]
10006318: add      r2, r2, r2, lsl #1
1000631c: add      r1, r1, r2, lsl #2
10006320: strb     r7, [r0, r1]
10006324: ldr      r1, [r4, #0xc6c]
10006328: ldrh     r0, [r1, #0x78]
1000632c: add      r0, r0, #1
10006330: strh     r0, [r1, #0x78]
10006334: ldrb     r0, [sb, #0x70]
10006338: add      r7, r7, #1
1000633c: add      r5, r5, #3
10006340: cmp      r0, #0
10006344: movne    r0, #4
10006348: moveq    r0, #6
1000634c: cmp      r0, r7
10006350: add      r8, r8, #2
10006354: bhi      #0x10006040
10006358: ldrsb    r0, [sb, #0x70]
1000635c: ldr      r1, [sp]
10006360: cmp      r0, #0
10006364: movne    r2, #4
10006368: moveq    r2, #6
1000636c: cmp      r2, r1
10006370: bhi      #0x10006404
10006374: cmp      r0, #0
10006378: ldr      r1, [pc, #0xc4]  ; =0x3f9e00
1000637c: movne    r0, #0x3f
10006380: moveq    r0, #0x2d
10006384: and      r3, r0, #0x1f
10006388: lsr      r2, r0, #5
1000638c: mov      r0, #1
10006390: ldr      ip, [r1, r2, lsl #2]
10006394: orr      r0, ip, r0, lsl r3
10006398: str      r0, [r1, r2, lsl #2]
1000639c: ldrsb    r0, [sb, #0x70]
100063a0: ldr      r1, [pc, #0xa0]  ; =0x10008000
100063a4: mov      r2, #1
100063a8: add      r0, r1, r0, lsl #1
100063ac: ldrh     r1, [r0]
100063b0: ldr      r0, [pc, #0x84]  ; =0x3f95f0 gGameWork
100063b4: bl       #0x10000688  ; ->GameWork::addItem
100063b8: ldrb     r0, [sb, #0x70]
100063bc: mov      r1, #8
100063c0: mvn      r2, #0
100063c4: cmp      r0, #0
100063c8: ldr      r0, [r4, #0xc6c]
100063cc: addne    r3, pc, #0x78
100063d0: addeq    r3, pc, #0x94
100063d4: ldrh     ip, [r0, #0x78]
100063d8: add      ip, ip, ip, lsl #1
100063dc: str      r3, [r0, ip, lsl #2]
100063e0: ldr      r0, [r4, #0xc6c]
100063e4: ldrh     r3, [r0, #0x78]
100063e8: add      r3, r3, r3, lsl #1
100063ec: add      r1, r1, r3, lsl #2
100063f0: strb     r2, [r0, r1]
100063f4: ldr      r0, [r4, #0xc6c]
100063f8: ldrh     r1, [r0, #0x78]
100063fc: add      r1, r1, #1
10006400: strh     r1, [r0, #0x78]
10006404: ldr      r0, [r4, #0xc6c]
10006408: ldrh     r1, [r0, #0x78]
1000640c: cmp      r1, #0
10006410: movne    r0, #1
10006414: bne      #0x10006434
10006418: ldr      r2, [pc, #0x6c]  ; =0x44c6c
1000641c: ldr      r1, [sp, #8]
10006420: add      r4, r1, r2
10006424: bl       #0x100004e8  ; ->Mem::Free
10006428: mov      r0, #0
1000642c: str      r0, [r4]
10006430: mov      r0, #0
10006434: add      sp, sp, #0xc
10006438: pop      {r4, r5, r6, r7, r8, sb, sl, fp, pc}
1000643c: ldrshteq sb, [pc], -r0
10006440: .word    0x07fff87f
10006444: eorseq   sb, pc, r0, lsl #28
10006448: andne    r8, r0, r0
1000644c: svcpl    #0x53454d
10006450: ldrbtmi  r6, [r3], #-0x54d
10006454: ldclmi   p4, c7, [pc, #-0x184]
10006458: strbmi   r6, [sb, -sb, ror #28]!
1000645c: svcpl    #0x656d61
10006460: svcpl    #0x646e65
10006464: svcvs    #0x666e69
10006468: andeq    r3, r0, r2, lsr r0
1000646c: svcpl    #0x53454d
10006470: ldrbtmi  r6, [r3], #-0x54d
10006474: ldclmi   p4, c7, [pc, #-0x184]
10006478: strbmi   r6, [sb, -sb, ror #28]!
1000647c: svcpl    #0x656d61
10006480: svcpl    #0x646e65
10006484: svcvs    #0x666e69
10006488: andeq    r0, r0, r4, lsr r0
1000648c: andeq    r4, r4, ip, ror #24
10006490: mov      r1, r0
10006494: mov      r0, r3
10006498: mov      r0, r0
1000649c: push     {r3, r4, r5, r6, r7, lr}
100064a0: cmp      r2, #1
100064a4: mov      r6, r0
100064a8: ldrb     r0, [r1, #0x48]
100064ac: add      r5, r6, #0x13000
100064b0: add      r5, r5, #0x27c
100064b4: mov      r7, #0
100064b8: and      r4, r0, #0xff
100064bc: beq      #0x1000654c
100064c0: cmp      r2, #4
100064c4: beq      #0x1000651c
100064c8: cmp      r2, #5
100064cc: bne      #0x10006518
100064d0: mov      r1, #0
100064d4: mov      r0, r5
100064d8: bl       #0x10000458  ; ->msys::MCursorBase::setVisible
100064dc: ldr      r1, [pc, #0xf4]  ; =0x10008000
100064e0: add      r0, r6, #0x10000
100064e4: cmp      r4, #0
100064e8: add      r0, r0, #0x2a00
100064ec: beq      #0x1000659c
100064f0: cmp      r4, #1
100064f4: beq      #0x100065b0
100064f8: cmp      r4, #2
100064fc: beq      #0x100065c4
10006500: cmp      r4, #3
10006504: bne      #0x10006518
10006508: add      r1, r0, #0xc
1000650c: add      r0, r0, #4
10006510: ldm      r1, {r1, r2}
10006514: stm      r0, {r1, r2}
10006518: pop      {r3, r4, r5, r6, r7, pc}
1000651c: cmp      r4, #0
10006520: mov      r3, #0
10006524: cmpne    r4, #3
10006528: mov      r2, r3
1000652c: str      r7, [sp]
10006530: beq      #0x10006584
10006534: ldr      r1, [pc, #0xa0]  ; =0x110016
10006538: mov      r0, r6
1000653c: bl       #0x10003dd4
10006540: mov      r1, #0
10006544: mov      r0, r6
10006548: bl       #0x10003d68
1000654c: cmp      r4, #3
10006550: bhs      #0x10006518
10006554: ldr      r0, [pc, #0x84]  ; =0x13294
10006558: ldrsb    r0, [r0, r6]
1000655c: cmp      r0, r4
10006560: beq      #0x10006518
10006564: mov      r3, #0
10006568: ldr      r1, [pc, #0x74]  ; =0x110015
1000656c: mov      r2, r3
10006570: mov      r0, r6
10006574: str      r7, [sp]
10006578: bl       #0x10003dd4
1000657c: strb     r4, [r5, #0x18]
10006580: pop      {r3, r4, r5, r6, r7, pc}
10006584: ldr      r1, [pc, #0x5c]  ; =0x110017
10006588: mov      r0, r6
1000658c: bl       #0x10003dd4
10006590: nop      
10006594: nop      
10006598: b        #0x10006540
1000659c: add      r1, r1, #0x2c
100065a0: add      r0, r0, #4
100065a4: ldm      r1, {r1, r2}
100065a8: stm      r0, {r1, r2}
100065ac: pop      {r3, r4, r5, r6, r7, pc}
100065b0: add      r1, r1, #0x34
100065b4: add      r0, r0, #4
100065b8: ldm      r1, {r1, r2}
100065bc: stm      r0, {r1, r2}
100065c0: pop      {r3, r4, r5, r6, r7, pc}
100065c4: add      r1, r1, #0x3c
100065c8: add      r0, r0, #4
100065cc: ldm      r1, {r1, r2}
100065d0: stm      r0, {r1, r2}
100065d4: pop      {r3, r4, r5, r6, r7, pc}
100065d8: andne    r8, r0, r0
100065dc: andseq   r0, r1, r6, lsl r0
100065e0: muleq    r1, r4, r2
100065e4: andseq   r0, r1, r5, lsl r0
100065e8: andseq   r0, r1, r7, lsl r0
100065ec: push     {r4, r5, r6, r7, r8, sb, sl, lr}
100065f0: mov      r5, r0
100065f4: mov      r8, r1
100065f8: add      r4, r5, #0x44000
100065fc: ldr      r0, [pc, #0x168]  ; =0x1000820c
10006600: mov      r7, r2
10006604: vpush    {d8}
10006608: sub      sp, sp, #0x20
1000660c: ldr      r6, [sp, #0x48]
10006610: vldr     s16, [sp, #0x4c]
10006614: ldr      r1, [r0, r6, lsl #2]
10006618: rsb      r0, r3, r3, lsl #5
1000661c: add      r0, r0, r3, lsl #6
10006620: str      r1, [r4, #0xc64]
10006624: add      sl, r5, r0, lsl #2
10006628: add      r0, sl, #0x21000
1000662c: add      r0, r0, #0x370
10006630: mov      sb, r0
10006634: bl       #0x10000540  ; ->msys::MDfxChr::playDfx
10006638: add      r2, sl, #0x21400
1000663c: add      r2, r2, #0xbc
10006640: mov      r0, #0
10006644: ldr      r1, [r2, #8]
10006648: mov      r3, #0
1000664c: strh     r0, [r1, #0xf2]
10006650: ldr      r0, [r2, #8]
10006654: mov      r1, #0
10006658: mov      r2, r8
1000665c: strb     r1, [r0, #0x170]
10006660: add      r0, r5, #0x12800
10006664: str      sb, [r4, #0xc60]
10006668: add      r0, r0, #0x32c
1000666c: ldr      r1, [r7, #8]
10006670: mov      sb, r0
10006674: bl       #0x100003c0  ; ->msys::MLyt::createAnimeAutoSlot
10006678: sxth     r1, r0
1000667c: mov      r0, sb
10006680: bl       #0x100003a8  ; ->msys::MLyt::getAnim
10006684: str      r0, [r4, #0xc58]
10006688: ldrh     r1, [r0, #0x12]
1000668c: mov      r4, #0
10006690: mov      r3, r4
10006694: orr      r1, r1, #2
10006698: strh     r1, [r0, #0x12]
1000669c: add      r0, r5, #0x12c00
100066a0: add      r0, r0, #0x2d4
100066a4: mov      r2, #1
100066a8: mov      r1, #4
100066ac: mov      r5, r0
100066b0: str      r4, [sp]
100066b4: bl       #0x100003e8  ; ->msys::MLyt::playAnimeFromNo
100066b8: mov      r1, #4
100066bc: mov      r0, r5
100066c0: bl       #0x100003c8  ; ->msys::MLyt::getAnime
100066c4: cmp      r0, #0
100066c8: beq      #0x100066d8
100066cc: ldrh     r1, [r0, #0x12]
100066d0: orr      r1, r1, #2
100066d4: strh     r1, [r0, #0x12]
100066d8: vldr     s0, [pc, #0x90]  ; =0x0 (0)
100066dc: vldr     s1, [pc, #0x90]  ; =0x3f800000 (1)
100066e0: add      r1, sp, #4
100066e4: strb     r4, [sp]
100066e8: mov      r0, #1
100066ec: vstmia   r1, {s0, s1}
100066f0: mov      r3, r8
100066f4: vstr     s0, [sp, #0xc]
100066f8: strh     r0, [sp, #0x10]
100066fc: strh     r4, [sp, #0x12]
10006700: str      r4, [sp, #0x14]
10006704: str      r4, [sp, #0x18]
10006708: ldr      r1, [sb, #0x150]
1000670c: ldr      r2, [r7]
10006710: mov      r0, sp
10006714: bl       #0x10000468  ; ->ad::lyt::LytAnim::init
10006718: vmov     s0, r6
1000671c: mov      r0, sp
10006720: vcvt.f32.s32 s0, s0
10006724: bl       #0x100003b0  ; ->ad::lyt::LytAnim::stopAndSetFrm
10006728: mov      r1, #1
1000672c: mov      r0, sp
10006730: bl       #0x10000478  ; ->ad::lyt::LytAnim::term
10006734: ldr      r1, [r5, #0x150]
10006738: add      r3, pc, #0x38
1000673c: add      r2, pc, #0x38
10006740: mov      r0, sp
10006744: bl       #0x10000468  ; ->ad::lyt::LytAnim::init
10006748: vcvt.f32.s32 s0, s16
1000674c: mov      r0, sp
10006750: bl       #0x100003b0  ; ->ad::lyt::LytAnim::stopAndSetFrm
10006754: mov      r1, #1
10006758: mov      r0, sp
1000675c: bl       #0x10000478  ; ->ad::lyt::LytAnim::term
10006760: add      sp, sp, #0x20
10006764: vpop     {d8}
10006768: pop      {r4, r5, r6, r7, r8, sb, sl, pc}
1000676c: andne    r8, r0, ip, lsl #4
10006770: andeq    r0, r0, r0
10006774: svclo    #0x800000
10006778: andeq    r0, r0, r0
1000677c: svcpl    #0x544553
10006780: .word    0x4144454d
10006784: andeq    r0, r0, ip, asr #32
10006788: push     {r4, r5, r6, r7, r8, sb, sl, fp, lr}
1000678c: mov      r4, r0
10006790: vpush    {d8}
10006794: sub      sp, sp, #0x5c
10006798: bl       #0x10000258  ; ->ad::lyt::LytDrawSys::GetInst
1000679c: mov      r6, r0
100067a0: ldr      r0, [r4, #4]
100067a4: ldr      r5, [r0, #0x18]
100067a8: ldr      r0, [pc, #0x16c]  ; =0x3f634c ad::lyt::Layout::s_pAllocator
100067ac: ldr      r1, [r0]
100067b0: add      r0, r6, #0x400
100067b4: add      r0, r0, #0x1f4
100067b8: cmp      r1, r0
100067bc: movne    r1, r0
100067c0: blne     #0x10000260  ; ->ad::lyt::Initialize
100067c4: str      r5, [r6, #0x5f8]
100067c8: bl       #0x10000258  ; ->ad::lyt::LytDrawSys::GetInst
100067cc: mov      r1, r0
100067d0: mov      r0, #0x10000
100067d4: str      r0, [r1, #0x5fc]
100067d8: ldr      r7, [pc, #0x140]  ; =0x3f62a8 msys::MComSys::_sys
100067dc: ldr      r0, [r4, #8]
100067e0: mov      sb, #0
100067e4: mov      r8, #0x7f
100067e8: cmp      r0, #0
100067ec: ldreq    r0, [r7]
100067f0: mov      sl, sb
100067f4: mov      fp, sb
100067f8: streq    r0, [r4, #8]
100067fc: ldr      r1, [r0, #4]
10006800: cmp      r0, #0
10006804: str      r1, [sp, #0x54]
10006808: add      r1, r4, #0x12800
1000680c: add      r1, r1, #0x2e8
10006810: str      r1, [sp, #0x50]
10006814: ldreq    r0, [r7]
10006818: add      r1, pc, #0x104
1000681c: mov      r5, r1
10006820: streq    r0, [r4, #8]
10006824: ldrne    r0, [r4, #8]
10006828: ldr      r6, [r0, #0x278]
1000682c: ldr      r0, [r4, #4]
10006830: vldr     s16, [r0, #0x18]
10006834: ldr      r0, [r6, #0x24]
10006838: str      r0, [sp, #0x58]
1000683c: add      r0, sp, #0x24
10006840: bl       #0x10000698  ; ->ad::TransMultiSymbol::init
10006844: add      r2, sp, #0x24
10006848: add      r1, sp, #0x58
1000684c: mov      r0, sp
10006850: bl       #0x100006a0  ; ->BinGlu4Acs::getEntryAcs
10006854: ldr      r0, [sp]
10006858: ldr      r1, [r6, #0x24]
1000685c: ldr      r0, [r0]
10006860: bic      r0, r0, #0xc0000000
10006864: add      r0, r0, r1
10006868: add      r1, r0, #8
1000686c: str      r1, [sp, #8]
10006870: add      r2, r0, #0xc
10006874: add      r3, r0, #4
10006878: add      r1, sp, #0x14
1000687c: str      r2, [sp, #0xc]
10006880: str      r3, [sp, #4]
10006884: stm      r1, {r8, sb, sl, fp}
10006888: mov      r3, r5
1000688c: mov      r2, r6
10006890: vstr     s16, [sp, #0x10]
10006894: str      r0, [sp]
10006898: ldr      r0, [sp, #0x54]
1000689c: ldr      r1, [sp, #0x50]
100068a0: bl       #0x100006a8  ; ->ad::fw::TaskBase::readCA
100068a4: ldr      r0, [r4, #4]
100068a8: mov      r3, #0x7f
100068ac: ldr      r1, [r0, #0x18]
100068b0: ldr      r0, [r4, #8]
100068b4: cmp      r0, #0
100068b8: ldreq    r0, [r7]
100068bc: streq    r0, [r4, #8]
100068c0: cmp      r0, #0
100068c4: ldreq    r2, [r7]
100068c8: streq    r2, [r4, #8]
100068cc: movne    r2, r0
100068d0: ldr      ip, [r2, #4]
100068d4: mov      r2, #0
100068d8: str      r2, [sp, #8]
100068dc: stm      sp, {r1, r3}
100068e0: ldr      r0, [r0, #0x278]
100068e4: add      r1, r4, #0x12800
100068e8: add      r3, pc, #0x40
100068ec: add      r2, r0, #0xa8
100068f0: add      r1, r1, #0x2a4
100068f4: mov      r0, ip
100068f8: bl       #0x10000270  ; ->ad::fw::TaskBase::readLyt
100068fc: ldr      r1, [pc, #0x38]  ; =0x10008000
10006900: add      r2, r4, #0x12800
10006904: add      r2, r2, #0x1fc
10006908: ldrd     r0, r1, [r1, #0x44]
1000690c: strd     r0, r1, [r2]
10006910: add      sp, sp, #0x5c
10006914: vpop     {d8}
10006918: pop      {r4, r5, r6, r7, r8, sb, sl, fp, pc}
1000691c: eorseq   r6, pc, ip, asr #6
10006920: eorseq   r6, pc, r8, lsr #5
10006924: strbtvc  r5, [sb], #-0xf6d
10006928: subsvs   r6, pc, #0x1940
1000692c: andeq    r6, r0, r2, ror r1
10006930: mcrmi    p13, #2, r4, c9, c15, #1
10006934: stclmi   p7, c4, [r1, #-0x124]
10006938: andeq    r0, r0, r5, asr #32
1000693c: andne    r8, r0, r0
10006940: bx       lr
10006944: push     {r0, r1, r2, r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
10006948: mov      r5, r0
1000694c: mov      r0, #0
10006950: mov      sb, r1
10006954: mov      r1, #1
10006958: vldr     s0, [pc, #0x314]  ; =0x3f800000 (1)
1000695c: ldr      r2, [pc, #0x314]  ; =0x44c68
10006960: add      r4, r5, #0x12800
10006964: vpush    {d8}
10006968: sub      sp, sp, #0x2c
1000696c: vldr     s16, [pc, #0x2fc]  ; =0x0 (0)
10006970: strb     r0, [sp, #8]
10006974: vstr     s16, [sp, #0xc]
10006978: vstr     s0, [sp, #0x10]
1000697c: vstr     s16, [sp, #0x14]
10006980: strh     r1, [sp, #0x18]
10006984: strh     r0, [sp, #0x1a]
10006988: ldr      r1, [sp, #0x68]
1000698c: str      r0, [sp, #0x1c]
10006990: str      r0, [sp, #0x20]
10006994: ldr      r7, [r2, r5]
10006998: cmp      r1, #0
1000699c: add      r4, r4, #0x32c
100069a0: mov      r8, r0
100069a4: bls      #0x10006c00
100069a8: ldr      r0, [r5, #8]
100069ac: cmp      r0, #0
100069b0: bne      #0x100069c0
100069b4: ldr      r0, [pc, #0x2c0]  ; =0x3f62a8 msys::MComSys::_sys
100069b8: ldr      r0, [r0]
100069bc: str      r0, [r5, #8]
100069c0: add      r3, r0, #0x4a000
100069c4: cmp      r0, #0
100069c8: add      r3, r3, #0xaa0
100069cc: bne      #0x100069dc
100069d0: ldr      r0, [pc, #0x2a4]  ; =0x3f62a8 msys::MComSys::_sys
100069d4: ldr      r0, [r0]
100069d8: str      r0, [r5, #8]
100069dc: add      r0, r0, #0xe6000
100069e0: ldr      r2, [r0, #0x4f0]
100069e4: ldr      r0, [r5, #4]
100069e8: ldr      r1, [r0, #0x18]
100069ec: mov      r0, #0x400
100069f0: str      r0, [sp]
100069f4: rsb      r0, r8, r8, lsl #5
100069f8: add      r0, r0, r8, lsl #6
100069fc: add      sl, r5, r0, lsl #2
10006a00: add      r0, sl, #0x21000
10006a04: add      r0, r0, #0x370
10006a08: mov      r6, r0
10006a0c: str      sl, [sp, #0x24]
10006a10: bl       #0x10000538  ; ->msys::MDfxChr::init
10006a14: ldr      r0, [pc, #0x264]  ; =0x3f7eec _ZGVZN2nn4math4VEC34ZeroEvE4zero
10006a18: add      sl, sl, #0x21400
10006a1c: add      sl, sl, #0x3c
10006a20: ldrb     r0, [r0]
10006a24: tst      r0, #1
10006a28: bne      #0x10006a58
10006a2c: ldr      r0, [pc, #0x24c]  ; =0x3f7eec _ZGVZN2nn4math4VEC34ZeroEvE4zero
10006a30: bl       #0x10000548  ; ->__cxa_guard_acquire
10006a34: cmp      r0, #0
10006a38: nop      
10006a3c: beq      #0x10006a58
10006a40: ldr      r0, [pc, #0x23c]  ; =0x434c48 _ZZN2nn4math4VEC34ZeroEvE4zero
10006a44: vstr     s16, [r0]
10006a48: vstr     s16, [r0, #4]
10006a4c: vstr     s16, [r0, #8]
10006a50: ldr      r0, [pc, #0x228]  ; =0x3f7eec _ZGVZN2nn4math4VEC34ZeroEvE4zero
10006a54: bl       #0x10000550  ; ->__cxa_guard_release
10006a58: ldr      fp, [pc, #0x224]  ; =0x434c48 _ZZN2nn4math4VEC34ZeroEvE4zero
10006a5c: mov      r0, sl
10006a60: bl       #0x100002d8  ; ->MoveVBase::stop
10006a64: ldm      fp, {r0, r1, r2}
10006a68: add      r3, sl, #0x1c
10006a6c: add      sl, sl, #4
10006a70: stm      r3, {r0, r1, r2}
10006a74: stm      sl, {r0, r1, r2}
10006a78: mov      r0, #0
10006a7c: str      r0, [sp]
10006a80: str      r0, [sp, #4]
10006a84: ldr      r0, [sp, #0x40]
10006a88: ldr      r3, [sp, #0x3c]
10006a8c: mov      r1, r6
10006a90: add      sl, r0, r8, lsl #4
10006a94: mov      r0, r4
10006a98: ldr      r2, [sl, #0xc]
10006a9c: bl       #0x10000428  ; ->msys::MLyt::attachMChr
10006aa0: ldr      r1, [r4, #0x150]
10006aa4: ldr      r2, [sl, #8]
10006aa8: ldr      r3, [sp, #0x3c]
10006aac: add      r0, sp, #8
10006ab0: bl       #0x10000468  ; ->ad::lyt::LytAnim::init
10006ab4: ldrh     r0, [r7, #0x12]
10006ab8: nop      
10006abc: bl       #0x10000390  ; ->ad::db::GetPcAttack
10006ac0: ldrh     r0, [r0, #0xe]
10006ac4: ldr      r1, [pc, #0x1bc]  ; =0x7fff87f
10006ac8: ldr      r2, [pc, #0x1bc]  ; =0x3f95f0 gGameWork
10006acc: and      r1, r1, r0, lsr #5
10006ad0: and      r0, r0, #0x1f
10006ad4: add      r1, r2, r1, lsl #2
10006ad8: ldr      r1, [r1, #0x20c]
10006adc: lsr      r0, r1, r0
10006ae0: tst      r0, #1
10006ae4: beq      #0x10006b94
10006ae8: ldrsh    r0, [sb]
10006aec: ldrsh    r1, [r7]
10006af0: cmp      r1, r0
10006af4: bgt      #0x10006b94
10006af8: ldr      r0, [sp, #0x1c]
10006afc: add      fp, sp, #8
10006b00: bl       #0x10000470  ; ->ad::lyt::AnimTransform::GetFrameSize
10006b04: vmov     s0, r0
10006b08: mov      r0, fp
10006b0c: vcvt.f32.u32 s0, s0
10006b10: bl       #0x100003b0  ; ->ad::lyt::LytAnim::stopAndSetFrm
10006b14: mov      r1, #1
10006b18: add      r0, sp, #8
10006b1c: bl       #0x10000478  ; ->ad::lyt::LytAnim::term
10006b20: ldr      r1, [r4, #0x150]
10006b24: ldr      r2, [sl]
10006b28: ldr      r3, [sp, #0x3c]
10006b2c: add      r0, sp, #8
10006b30: bl       #0x10000468  ; ->ad::lyt::LytAnim::init
10006b34: ldrsh    r0, [sb]
10006b38: ldrsh    r1, [r7, #4]
10006b3c: cmp      r0, r1
10006b40: movge    fp, #2
10006b44: bge      #0x10006b58
10006b48: ldrsh    r1, [r7, #2]
10006b4c: cmp      r1, r0
10006b50: movle    fp, #1
10006b54: movgt    fp, #0
10006b58: vmov     s0, fp
10006b5c: add      r0, sp, #8
10006b60: vcvt.f32.u32 s0, s0
10006b64: bl       #0x100003b0  ; ->ad::lyt::LytAnim::stopAndSetFrm
10006b68: ldr      r1, [pc, #0x120]  ; =0x1000820c
10006b6c: mov      r0, r6
10006b70: ldr      r1, [r1, fp, lsl #2]
10006b74: bl       #0x10000540  ; ->msys::MDfxChr::playDfx
10006b78: ldr      r0, [sp, #0x24]
10006b7c: mov      r1, #0
10006b80: add      r0, r0, #0x21400
10006b84: add      r0, r0, #0xbc
10006b88: ldr      r0, [r0, #8]
10006b8c: strh     r1, [r0, #0xf2]
10006b90: b        #0x10006ba0
10006b94: vmov.f32 s0, s16
10006b98: add      r0, sp, #8
10006b9c: bl       #0x100003b0  ; ->ad::lyt::LytAnim::stopAndSetFrm
10006ba0: mov      r1, #1
10006ba4: add      r0, sp, #8
10006ba8: bl       #0x10000478  ; ->ad::lyt::LytAnim::term
10006bac: ldr      r1, [r4, #0x150]
10006bb0: ldr      r2, [sl, #4]
10006bb4: ldr      r3, [sp, #0x3c]
10006bb8: add      r0, sp, #8
10006bbc: bl       #0x10000468  ; ->ad::lyt::LytAnim::init
10006bc0: ldr      r0, [sp, #0x1c]
10006bc4: add      r6, sp, #8
10006bc8: bl       #0x10000470  ; ->ad::lyt::AnimTransform::GetFrameSize
10006bcc: vmov     s0, r0
10006bd0: mov      r0, r6
10006bd4: vcvt.f32.u32 s0, s0
10006bd8: bl       #0x100003b0  ; ->ad::lyt::LytAnim::stopAndSetFrm
10006bdc: mov      r1, #1
10006be0: add      r0, sp, #8
10006be4: bl       #0x10000478  ; ->ad::lyt::LytAnim::term
10006be8: ldr      r0, [sp, #0x68]
10006bec: add      r8, r8, #1
10006bf0: add      r7, r7, #0x18
10006bf4: cmp      r8, r0
10006bf8: add      sb, sb, #2
10006bfc: blo      #0x100069a8
10006c00: ldr      r1, [r4, #0x150]
10006c04: add      r3, pc, #0x88
10006c08: add      r2, pc, #0x88
10006c0c: add      r0, sp, #8
10006c10: bl       #0x10000468  ; ->ad::lyt::LytAnim::init
10006c14: ldr      r0, [pc, #0x8c]  ; =0x44c70
10006c18: ldr      r1, [pc, #0x8c]  ; =0x3f9e00
10006c1c: ldrb     r2, [r0, r5]
10006c20: cmp      r2, #0
10006c24: movne    r0, #0x3f
10006c28: moveq    r0, #0x2d
10006c2c: and      r3, r0, #0x1f
10006c30: lsr      r2, r0, #5
10006c34: mov      r0, #1
10006c38: ldr      r1, [r1, r2, lsl #2]
10006c3c: ands     r0, r1, r0, lsl r3
10006c40: movne    r0, #1
10006c44: vmov     s0, r0
10006c48: add      r0, sp, #8
10006c4c: vcvt.f32.u32 s0, s0
10006c50: bl       #0x100003b0  ; ->ad::lyt::LytAnim::stopAndSetFrm
10006c54: mov      r1, #1
10006c58: add      r0, sp, #8
10006c5c: bl       #0x10000478  ; ->ad::lyt::LytAnim::term
10006c60: add      sp, sp, #0x2c
10006c64: vpop     {d8}
10006c68: add      sp, sp, #0x10
10006c6c: pop      {r4, r5, r6, r7, r8, sb, sl, fp, pc}
10006c70: andeq    r0, r0, r0
10006c74: svclo    #0x800000
10006c78: andeq    r4, r4, r8, ror #24
10006c7c: eorseq   r6, pc, r8, lsr #5
10006c80: eorseq   r7, pc, ip, ror #29
10006c84: subeq    r4, r3, r8, asr #24
10006c88: .word    0x07fff87f
10006c8c: ldrshteq sb, [pc], -r0
10006c90: andne    r8, r0, ip, lsl #4
10006c94: andeq    r0, r0, r0
10006c98: svcpl    #0x544553
10006c9c: subpl    r4, sp, r3, asr #30
10006ca0: ldrbmi   r4, [r4, #-0x54c]
10006ca4: andeq    r0, r0, r0
10006ca8: andeq    r4, r4, r0, ror ip
10006cac: eorseq   sb, pc, r0, lsl #28
10006cb0: ldr      r2, [pc, #0x490]  ; =0x100089c4
10006cb4: push     {r4, r5, r6, r7, r8, lr}
10006cb8: mov      r4, #0
10006cbc: str      r2, [r0], #4
10006cc0: stm      r0, {r1, r4}
10006cc4: add      r0, r0, #0xc
10006cc8: bl       #0x100006b0  ; ->Backup
10006ccc: add      r0, r0, #0x12800
10006cd0: add      r0, r0, #0x204
10006cd4: bl       #0x100006b8  ; ->ad::ctrl::ButtonGroup
10006cd8: str      r4, [r0, #0x1c]!
10006cdc: add      r0, r0, #4
10006ce0: bl       #0x100006c0  ; ->ad::font::ResFont
10006ce4: sub      r5, r0, #4
10006ce8: mov      r0, r5
10006cec: bl       #0x100002a8  ; ->ad::lyt::LytResourceMan::init
10006cf0: add      r0, r5, #0x74
10006cf4: bl       #0x10000328  ; ->ad::fw::Resource
10006cf8: add      r0, r0, #0x44
10006cfc: bl       #0x10000328  ; ->ad::fw::Resource
10006d00: add      r0, r0, #0x44
10006d04: bl       #0x10003ff8
10006d08: ldr      r8, [pc, #0x43c]  ; =0x3e4580
10006d0c: add      r1, r0, #0x100
10006d10: mvn      r7, #0
10006d14: str      r8, [r0], #0x14c
10006d18: mov      r3, #0xc
10006d1c: strb     r7, [r0], #4
10006d20: strh     r4, [r1, #0x4e]
10006d24: ldr      r1, [pc, #0x424]  ; =0x100035e0
10006d28: mov      r2, #0x1c
10006d2c: str      r4, [r0], #4
10006d30: bl       #0x10000330  ; ->__aeabi_vec_ctor_nocookie_nodtor
10006d34: ldr      r1, [pc, #0x418]  ; =0x10000988
10006d38: mov      r3, #0xc
10006d3c: mov      r2, #0x10
10006d40: add      r0, r0, #0x15c
10006d44: bl       #0x10000330  ; ->__aeabi_vec_ctor_nocookie_nodtor
10006d48: mov      r6, #1
10006d4c: str      r4, [r0, #0xc0]
10006d50: sub      r5, r0, #0x2b0
10006d54: strb     r6, [r0, #0xc4]
10006d58: str      r4, [r5, #0x378]
10006d5c: str      r4, [r5, #0x37c]
10006d60: strb     r4, [r5, #0x380]
10006d64: str      r4, [r5, #0x384]
10006d68: sub      r0, r0, #0xc
10006d6c: mov      r1, r7
10006d70: str      r4, [r5, #0x388]
10006d74: bl       #0x10003fdc
10006d78: add      r0, r5, #0x3a8
10006d7c: bl       #0x10003ff8
10006d80: add      r1, r0, #0x100
10006d84: str      r8, [r0], #0x14c
10006d88: mov      r3, #0xc
10006d8c: strb     r7, [r0], #4
10006d90: strh     r4, [r1, #0x4e]
10006d94: ldr      r1, [pc, #0x3b4]  ; =0x100035e0
10006d98: mov      r2, #0x1c
10006d9c: str      r4, [r0], #4
10006da0: bl       #0x10000330  ; ->__aeabi_vec_ctor_nocookie_nodtor
10006da4: ldr      r1, [pc, #0x3a8]  ; =0x10000988
10006da8: mov      r3, #0xc
10006dac: mov      r2, #0x10
10006db0: add      r0, r0, #0x15c
10006db4: bl       #0x10000330  ; ->__aeabi_vec_ctor_nocookie_nodtor
10006db8: sub      r5, r0, #0x2b0
10006dbc: str      r4, [r0, #0xc0]
10006dc0: strb     r6, [r5, #0x374]
10006dc4: str      r4, [r5, #0x378]
10006dc8: str      r4, [r5, #0x37c]
10006dcc: strb     r4, [r5, #0x380]
10006dd0: str      r4, [r5, #0x384]
10006dd4: mov      r1, r7
10006dd8: sub      r0, r0, #0xc
10006ddc: str      r4, [r5, #0x388]
10006de0: bl       #0x10003fdc
10006de4: add      r0, r5, #0x3a8
10006de8: bl       #0x100006c8  ; ->msys::MCursorBase
10006dec: ldr      r1, [pc, #0x364]  ; =0x10008880
10006df0: str      r1, [r0], #0x30
10006df4: str      r4, [r0], #4
10006df8: str      r4, [r0], #4
10006dfc: str      r4, [r0], #0x14
10006e00: bl       #0x10003ff8
10006e04: ldr      r7, [pc, #0x350]  ; =0x3e45c4
10006e08: str      r7, [r0], #0x14c
10006e0c: bl       #0x100006d0  ; ->MessageSimple
10006e10: sub      r1, r0, #0x14c
10006e14: add      r0, r0, #0x5c00
10006e18: add      r0, r0, #0x2b4
10006e1c: mov      r5, #0x400
10006e20: str      r4, [r0, #0xc2c]
10006e24: strb     r4, [r0, #0xc30]
10006e28: strb     r4, [r0, #0xc31]
10006e2c: str      r4, [r0, #0xc34]
10006e30: str      r4, [r0, #0xc38]!
10006e34: str      r5, [r0, #8]
10006e38: add      r0, r1, #0x6c00
10006e3c: add      r0, r0, #0x44
10006e40: bl       #0x10003ff8
10006e44: str      r7, [r0], #0x14c
10006e48: bl       #0x100006d0  ; ->MessageSimple
10006e4c: sub      r1, r0, #0x14c
10006e50: add      r0, r0, #0x5c00
10006e54: add      r0, r0, #0x2b4
10006e58: str      r4, [r0, #0xc2c]
10006e5c: strb     r4, [r0, #0xc30]
10006e60: strb     r4, [r0, #0xc31]
10006e64: str      r4, [r0, #0xc34]
10006e68: str      r4, [r0, #0xc38]!
10006e6c: str      r5, [r0, #8]
10006e70: add      r0, r1, #0x6c00
10006e74: add      r0, r0, #0x44
10006e78: bl       #0x100006d8  ; ->msys::MLytNum
10006e7c: ldr      r1, [pc, #0x2dc]  ; =0x33137c msys::MDfxChr
10006e80: mov      r3, #4
10006e84: mov      r2, #0x17c
10006e88: add      r0, r0, #0x230
10006e8c: bl       #0x10000330  ; ->__aeabi_vec_ctor_nocookie_nodtor
10006e90: ldr      r1, [pc, #0x2c8]  ; =0x33137c msys::MDfxChr
10006e94: mov      r3, #6
10006e98: mov      r2, #0x17c
10006e9c: add      r0, r0, #0x5f0
10006ea0: bl       #0x10000330  ; ->__aeabi_vec_ctor_nocookie_nodtor
10006ea4: add      r0, r0, #0x800
10006ea8: add      r0, r0, #0xe8
10006eac: bl       #0x10003ff8
10006eb0: ldr      r1, [pc, #0x2ac]  ; =0x3e4730
10006eb4: str      r1, [r0], #0x14c
10006eb8: bl       #0x100006e0  ; ->Message
10006ebc: add      r1, r0, #0x6000
10006ec0: add      r1, r1, #0xd60
10006ec4: vldr     s0, [pc, #0x29c]  ; =0x0 (0)
10006ec8: strd     r4, r5, [r1]
10006ecc: vstr     s0, [r1, #8]
10006ed0: vstr     s0, [r1, #0xc]
10006ed4: mov      r2, #6
10006ed8: vstr     s0, [r1, #0x10]
10006edc: str      r2, [r1, #0x18]
10006ee0: str      r4, [r1, #0x14]
10006ee4: vstr     s0, [r1, #0x1c]
10006ee8: strb     r4, [r1, #0x20]
10006eec: str      r4, [r1, #0x24]
10006ef0: str      r4, [r1, #0x28]
10006ef4: strb     r6, [r1, #0x2c]
10006ef8: strb     r4, [r1, #0x2d]
10006efc: strb     r4, [r1, #0x2e]
10006f00: ldr      r3, [pc, #0x264]  ; =0x110003
10006f04: str      r4, [r1, #0x30]
10006f08: add      r1, r0, #0x6c00
10006f0c: add      r1, r1, #0x194
10006f10: add      ip, r3, r2, asr #2
10006f14: stm      r1, {r3, ip}
10006f18: add      r1, r0, #0x6000
10006f1c: add      r1, r1, #0xda0
10006f20: ldr      lr, [pc, #0x248]  ; =0x1000893c
10006f24: str      r4, [r1], #4
10006f28: stm      r1, {r4, r5}
10006f2c: sub      r1, r0, #0x14c
10006f30: str      lr, [r0, #-0x14c]
10006f34: add      r0, r0, #0x6c00
10006f38: add      r0, r0, #0x1ac
10006f3c: stm      r0, {r4, r5}
10006f40: vstr     s0, [r0, #8]
10006f44: vstr     s0, [r0, #0xc]
10006f48: vstr     s0, [r0, #0x10]
10006f4c: str      r2, [r0, #0x18]
10006f50: str      r4, [r0, #0x14]
10006f54: vstr     s0, [r0, #0x1c]
10006f58: strb     r4, [r0, #0x20]
10006f5c: str      r4, [r0, #0x24]
10006f60: str      r4, [r0, #0x28]
10006f64: strb     r6, [r0, #0x2c]
10006f68: strb     r4, [r0, #0x2d]
10006f6c: strb     r4, [r0, #0x2e]
10006f70: str      r4, [r0, #0x30]!
10006f74: add      r0, r0, #4
10006f78: stm      r0, {r3, ip}
10006f7c: add      r0, r1, #0x6c00
10006f80: add      r1, r1, #0x7000
10006f84: add      r0, r0, #0x338
10006f88: add      r1, r1, #0x134
10006f8c: bl       #0x100006e8  ; ->msys::MListWndPBase
10006f90: ldr      r1, [pc, #0x1dc]  ; =0x100088d8
10006f94: str      r1, [r0], #0x1fc
10006f98: bl       #0x100006f0  ; ->ad::ui::UIListWindowPlusLyt
10006f9c: ldr      r1, [pc, #0x1d4]  ; =0x10008828
10006fa0: str      r1, [r0], #-0x1fc
10006fa4: ldr      r1, [pc, #0x1d0]  ; =0x10008980
10006fa8: str      r1, [r0], #-0xfa0
10006fac: add      r0, r0, #0x8000
10006fb0: bl       #0x100006f8  ; ->ad::lyt::Layout
10006fb4: add      r0, r0, #0x3c
10006fb8: bl       #0x100006f8  ; ->ad::lyt::Layout
10006fbc: add      r0, r0, #0x3c
10006fc0: bl       #0x100035e0
10006fc4: add      r0, r0, #0x1c
10006fc8: bl       #0x100035e0
10006fcc: add      r0, r0, #0x1c
10006fd0: bl       #0x100035e0
10006fd4: add      r0, r0, #0x1c
10006fd8: bl       #0x100035e0
10006fdc: add      r0, r0, #0x1c
10006fe0: bl       #0x100035e0
10006fe4: add      r0, r0, #0x1c
10006fe8: bl       #0x10000700  ; ->CellAnime
10006fec: ldr      r1, [pc, #0x18c]  ; =0x3317a4 msys::MLytNum
10006ff0: mov      r3, #3
10006ff4: mov      r2, #0x230
10006ff8: add      r0, r0, #0x134
10006ffc: bl       #0x10000330  ; ->__aeabi_vec_ctor_nocookie_nodtor
10007000: add      r0, r0, #0x690
10007004: bl       #0x100035e0
10007008: add      r0, r0, #0x1c
1000700c: bl       #0x100035e0
10007010: add      r0, r0, #0x1c
10007014: bl       #0x100035e0
10007018: add      r0, r0, #0x1c
1000701c: bl       #0x10003ff8
10007020: ldr      r1, [pc, #0x15c]  ; =0x3e42dc
10007024: str      r1, [r0], #0x14c
10007028: bl       #0x10000700  ; ->CellAnime
1000702c: sub      r2, r0, #0x14c
10007030: mov      r1, #0xff
10007034: strb     r1, [r0, #0x12c]!
10007038: strb     r1, [r0, #1]
1000703c: strb     r1, [r0, #2]
10007040: strb     r1, [r0, #3]
10007044: add      r0, r2, #0x27c
10007048: bl       #0x10003ff8
1000704c: str      r7, [r0], #0x14c
10007050: bl       #0x100006d0  ; ->MessageSimple
10007054: sub      r1, r0, #0x14c
10007058: add      r0, r0, #0x5c00
1000705c: add      r0, r0, #0x2b4
10007060: str      r4, [r0, #0xc2c]
10007064: strb     r4, [r0, #0xc30]
10007068: strb     r4, [r0, #0xc31]
1000706c: str      r4, [r0, #0xc34]
10007070: str      r4, [r0, #0xc38]!
10007074: str      r5, [r0, #8]
10007078: add      r0, r1, #0x6c00
1000707c: add      r0, r0, #0x44
10007080: bl       #0x10003ff8
10007084: str      r7, [r0], #0x14c
10007088: bl       #0x100006d0  ; ->MessageSimple
1000708c: sub      r1, r0, #0x14c
10007090: add      r0, r0, #0x5c00
10007094: add      r0, r0, #0x2b4
10007098: str      r4, [r0, #0xc2c]
1000709c: strb     r4, [r0, #0xc30]
100070a0: strb     r4, [r0, #0xc31]
100070a4: str      r4, [r0, #0xc34]
100070a8: str      r4, [r0, #0xc38]!
100070ac: str      r5, [r0, #8]
100070b0: add      r0, r1, #0x6c00
100070b4: add      r0, r0, #0x44
100070b8: bl       #0x10003ff8
100070bc: str      r7, [r0], #0x14c
100070c0: bl       #0x100006d0  ; ->MessageSimple
100070c4: sub      r1, r0, #0x14c
100070c8: add      r0, r0, #0x5c00
100070cc: add      r0, r0, #0x2b4
100070d0: add      r6, r1, #0x5000
100070d4: str      r4, [r0, #0xc2c]
100070d8: strb     r4, [r0, #0xc30]
100070dc: strb     r4, [r0, #0xc31]
100070e0: str      r4, [r0, #0xc34]
100070e4: str      r4, [r0, #0xc38]!
100070e8: add      r6, r6, #0xff0
100070ec: str      r5, [r0, #8]
100070f0: sub      r5, r1, #0x3e000
100070f4: str      r4, [r6, #0xc58]
100070f8: sub      r5, r5, #0x10
100070fc: str      r4, [r6, #0xc6c]
10007100: bl       #0x10000490  ; ->atk_mg::GetBootInfo
10007104: ldrb     r0, [r0, #0x10]
10007108: ldr      r1, [pc, #0x78]  ; =0x10008218
1000710c: add      r2, r5, #0x12800
10007110: cmp      r0, #0
10007114: movne    r0, #1
10007118: cmp      r0, #0
1000711c: strb     r0, [r6, #0xc70]
10007120: movne    r0, #6
10007124: add      r2, r2, #0x1fc
10007128: add      r0, r0, r0, lsl #1
1000712c: add      r0, r1, r0, lsl #3
10007130: sub      r1, r1, #0x218
10007134: str      r0, [r6, #0xc68]
10007138: ldrd     r0, r1, [r1, #0x24]
1000713c: strd     r0, r1, [r2]
10007140: mov      r0, r5
10007144: pop      {r4, r5, r6, r7, r8, pc}
10007148: andne    r8, r0, r4, asr #19
1000714c: eorseq   r4, lr, r0, lsl #11
10007150: andne    r3, r0, r0, ror #11
10007154: andne    r0, r0, r8, lsl #19
10007158: andne    r8, r0, r0, lsl #17
1000715c: eorseq   r4, lr, r4, asr #11
10007160: eorseq   r1, r3, ip, ror r3
10007164: eorseq   r4, lr, r0, lsr r7
10007168: andeq    r0, r0, r0
1000716c: andseq   r0, r1, r3
10007170: andne    r8, r0, ip, lsr sb
10007174: ldrdne   r8, sb, [r0], -r8
10007178: andne    r8, r0, r8, lsr #16
1000717c: andne    r8, r0, r0, lsl #19
10007180: eorseq   r1, r3, r4, lsr #15
10007184: ldrsbteq r4, [lr], -ip
10007188: andne    r8, r0, r8, lsl r2
1000718c: push     {r4, lr}
10007190: bl       #0x1000719c
10007194: pop      {r4, lr}
10007198: b        #0x10000198  ; ->_ZdlPv
1000719c: push     {r4, r5, r6, lr}
100071a0: mov      r4, r0
100071a4: ldr      r0, [pc, #0x2ec]  ; =0x100089c4
100071a8: vpush    {d8}
100071ac: str      r0, [r4]
100071b0: add      r0, r4, #0x13000
100071b4: add      r0, r0, #0x27c
100071b8: bl       #0x10000708  ; ->msys::MCursorBase::term
100071bc: add      r0, r4, #0x12800
100071c0: add      r0, r0, #0x32c
100071c4: bl       #0x100005b8  ; ->msys::MLyt::term
100071c8: add      r0, r4, #0x12c00
100071cc: add      r0, r0, #0x2d4
100071d0: bl       #0x100005b8  ; ->msys::MLyt::term
100071d4: add      r0, r4, #0x12800
100071d8: add      r0, r0, #0x214
100071dc: bl       #0x10000710  ; ->ad::ctrl::ButtonGroup::FreeAll
100071e0: add      r0, r4, #0x12800
100071e4: add      r0, r0, #0x2a4
100071e8: bl       #0x100005c0  ; ->ad::fw::Resource::term
100071ec: add      r0, r4, #0x12000
100071f0: add      r0, r0, #0xa30
100071f4: bl       #0x10000718  ; ->ad::lyt::LytResourceMan::term
100071f8: ldr      r5, [pc, #0x29c]  ; =0x3e45c4
100071fc: add      r4, r4, #0x3e000
10007200: add      r4, r4, #0x10
10007204: add      r0, r4, #0x14c
10007208: str      r5, [r4]
1000720c: bl       #0x10000720  ; ->MessageSimple::term
10007210: add      r0, r4, #0x14c
10007214: bl       #0x10000728  ; ->MessageSimple
10007218: sub      r0, r0, #0x14c
1000721c: bl       #0x100040e4
10007220: sub      r4, r0, #0x6c00
10007224: sub      r4, r4, #0x44
10007228: sub      r0, r0, #0x6800
1000722c: sub      r0, r0, #0x2f8
10007230: str      r5, [r4]
10007234: bl       #0x10000720  ; ->MessageSimple::term
10007238: add      r0, r4, #0x14c
1000723c: bl       #0x10000728  ; ->MessageSimple
10007240: sub      r0, r0, #0x14c
10007244: bl       #0x100040e4
10007248: sub      r4, r0, #0x6c00
1000724c: sub      r4, r4, #0x44
10007250: sub      r0, r0, #0x6800
10007254: sub      r0, r0, #0x2f8
10007258: str      r5, [r4]
1000725c: bl       #0x10000720  ; ->MessageSimple::term
10007260: add      r0, r4, #0x14c
10007264: bl       #0x10000728  ; ->MessageSimple
10007268: sub      r0, r0, #0x14c
1000726c: bl       #0x100040e4
10007270: ldr      r1, [pc, #0x228]  ; =0x3e42dc
10007274: str      r1, [r0, #-0x27c]
10007278: sub      r0, r0, #0x130
1000727c: bl       #0x10000670  ; ->CellAnime
10007280: sub      r0, r0, #0x14c
10007284: bl       #0x100040e4
10007288: vldr     s16, [pc, #0x214]  ; =0x0 (0)
1000728c: sub      r4, r0, #0x400
10007290: vstr     s16, [r0, #-0x10]
10007294: vstr     s16, [r0, #-0x2c]
10007298: sub      r4, r4, #0x2e4
1000729c: vstr     s16, [r0, #-0x48]
100072a0: ldr      r1, [pc, #0x200]  ; =0x331840 msys::MLytNum
100072a4: mov      r3, #3
100072a8: mov      r2, #0x230
100072ac: mov      r0, r4
100072b0: bl       #0x10000210  ; ->__aeabi_vec_dtor
100072b4: ldr      r1, [pc, #0x1f0]  ; =0x10008980
100072b8: sub      r0, r4, #0x7000
100072bc: sub      r0, r0, #0x298
100072c0: str      r1, [r0], #0x164
100072c4: add      r0, r0, #0x7000
100072c8: bl       #0x10000670  ; ->CellAnime
100072cc: vstr     s16, [r0, #-0x10]
100072d0: vstr     s16, [r0, #-0x2c]
100072d4: vstr     s16, [r0, #-0x48]
100072d8: vstr     s16, [r0, #-0x64]
100072dc: vstr     s16, [r0, #-0x80]
100072e0: sub      r0, r0, #0xc8
100072e4: bl       #0x10000678  ; ->ad::lyt::Layout
100072e8: sub      r0, r0, #0x3c
100072ec: bl       #0x10000678  ; ->ad::lyt::Layout
100072f0: ldr      r1, [pc, #0x1b8]  ; =0x100088d8
100072f4: sub      r0, r0, #0x7000
100072f8: sub      r0, r0, #0x60
100072fc: str      r1, [r0], #0x1fc
10007300: bl       #0x100001d0  ; ->ad::ui::UIListWindowPlusLyt
10007304: sub      r0, r0, #0x1fc
10007308: bl       #0x100001f8  ; ->msys::MListWndPBase
1000730c: sub      r4, r0, #0x6c00
10007310: ldr      r0, [pc, #0x19c]  ; =0x3e4730
10007314: sub      r4, r4, #0x338
10007318: str      r0, [r4]
1000731c: add      r0, r4, #0x14c
10007320: bl       #0x10000608  ; ->Message::term
10007324: add      r0, r4, #0x14c
10007328: bl       #0x10000610  ; ->Message
1000732c: sub      r0, r0, #0x14c
10007330: bl       #0x100040e4
10007334: sub      r4, r0, #0x21c00
10007338: sub      r0, r0, #0x800
1000733c: ldr      r1, [pc, #0x174]  ; =0x3313cc msys::MDfxChr
10007340: sub      r4, r4, #0x58
10007344: mov      r3, #6
10007348: mov      r2, #0x17c
1000734c: sub      r0, r0, #0xe8
10007350: bl       #0x10000210  ; ->__aeabi_vec_dtor
10007354: add      r0, r4, #0x20000
10007358: ldr      r1, [pc, #0x158]  ; =0x3313cc msys::MDfxChr
1000735c: mov      r3, #4
10007360: mov      r2, #0x17c
10007364: add      r0, r0, #0xd80
10007368: bl       #0x10000210  ; ->__aeabi_vec_dtor
1000736c: add      r0, r4, #0x20000
10007370: add      r0, r0, #0xb50
10007374: bl       #0x10000730  ; ->msys::MLytNum
10007378: sub      r4, r0, #0x6c00
1000737c: sub      r4, r4, #0x44
10007380: sub      r0, r0, #0x6800
10007384: sub      r0, r0, #0x2f8
10007388: str      r5, [r4]
1000738c: bl       #0x10000720  ; ->MessageSimple::term
10007390: add      r0, r4, #0x14c
10007394: bl       #0x10000728  ; ->MessageSimple
10007398: sub      r0, r0, #0x14c
1000739c: bl       #0x100040e4
100073a0: sub      r4, r0, #0x6c00
100073a4: sub      r4, r4, #0x44
100073a8: sub      r0, r0, #0x6800
100073ac: sub      r0, r0, #0x2f8
100073b0: str      r5, [r4]
100073b4: bl       #0x10000720  ; ->MessageSimple::term
100073b8: add      r0, r4, #0x14c
100073bc: bl       #0x10000728  ; ->MessageSimple
100073c0: sub      r0, r0, #0x14c
100073c4: bl       #0x100040e4
100073c8: sub      r0, r0, #0x4c
100073cc: bl       #0x10000738  ; ->msys::MCursorBase
100073d0: ldr      r5, [pc, #0xe4]  ; =0x3e4580
100073d4: sub      r0, r0, #0x3a8
100073d8: mov      r4, r0
100073dc: str      r5, [r0]
100073e0: bl       #0x100005b8  ; ->msys::MLyt::term
100073e4: ldr      r1, [pc, #0xd4]  ; =0x100009b8
100073e8: mov      r3, #0xc
100073ec: mov      r2, #0x10
100073f0: add      r0, r4, #0x2b0
100073f4: bl       #0x10000210  ; ->__aeabi_vec_dtor
100073f8: ldr      r1, [pc, #0xc4]  ; =0x10000850
100073fc: mov      r3, #0xc
10007400: mov      r2, #0x1c
10007404: add      r0, r4, #0x154
10007408: bl       #0x10000210  ; ->__aeabi_vec_dtor
1000740c: mov      r0, r4
10007410: bl       #0x100040e4
10007414: sub      r0, r0, #0x3a8
10007418: mov      r4, r0
1000741c: str      r5, [r0]
10007420: bl       #0x100005b8  ; ->msys::MLyt::term
10007424: ldr      r1, [pc, #0x94]  ; =0x100009b8
10007428: mov      r3, #0xc
1000742c: mov      r2, #0x10
10007430: add      r0, r4, #0x2b0
10007434: bl       #0x10000210  ; ->__aeabi_vec_dtor
10007438: ldr      r1, [pc, #0x84]  ; =0x10000850
1000743c: mov      r3, #0xc
10007440: mov      r2, #0x1c
10007444: add      r0, r4, #0x154
10007448: bl       #0x10000210  ; ->__aeabi_vec_dtor
1000744c: mov      r0, r4
10007450: bl       #0x100040e4
10007454: sub      r0, r0, #0x44
10007458: bl       #0x100005c8  ; ->ad::fw::Resource
1000745c: sub      r0, r0, #0x44
10007460: bl       #0x100005c8  ; ->ad::fw::Resource
10007464: sub      r4, r0, #0x74
10007468: mov      r0, r4
1000746c: bl       #0x10000718  ; ->ad::lyt::LytResourceMan::term
10007470: add      r0, r4, #4
10007474: bl       #0x10000740  ; ->ad::font::ResFont
10007478: sub      r0, r0, #0x20
1000747c: bl       #0x10000748  ; ->ad::ctrl::ButtonGroup
10007480: sub      r0, r0, #0x12800
10007484: sub      r0, r0, #0x204
10007488: bl       #0x10000750  ; ->Backup
1000748c: vpop     {d8}
10007490: sub      r0, r0, #0x10
10007494: pop      {r4, r5, r6, pc}
10007498: andne    r8, r0, r4, asr #19
1000749c: eorseq   r4, lr, r4, asr #11
100074a0: ldrsbteq r4, [lr], -ip
100074a4: andeq    r0, r0, r0
100074a8: eorseq   r1, r3, r0, asr #16
100074ac: andne    r8, r0, r0, lsl #19
100074b0: ldrdne   r8, sb, [r0], -r8
100074b4: eorseq   r4, lr, r0, lsr r7
100074b8: eorseq   r1, r3, ip, asr #7
100074bc: eorseq   r4, lr, r0, lsl #11
100074c0: strhne   r0, [r0], -r8
100074c4: andne    r0, r0, r0, asr r8
100074c8: ldr      r2, [pc, #0xc]  ; =0x129f8
100074cc: ldr      r0, [r0, #0x20]
100074d0: add      r1, r2, r1, lsl #2
100074d4: add      r0, r0, r1
100074d8: bx       lr
100074dc: strdeq   r2, r3, [r1], -r8
100074e0: push     {r4, lr}
100074e4: mov      r4, r0
100074e8: ldr      r0, [r0, #0x20]
100074ec: cmp      r0, #0
100074f0: ldrne    r0, [r4, #0x20]
100074f4: bne      #0x1000752c
100074f8: ldr      r0, [r4]
100074fc: ldr      r1, [r0, #0x2c]
10007500: mov      r0, r4
10007504: blx      r1
10007508: mov      r3, #0
1000750c: ldr      r1, [r4, #0x18]
10007510: ldr      r0, [pc, #0x40]  ; =0x44c78
10007514: mov      r2, r3
10007518: bl       #0x10000180  ; ->_ZnwjP10MemAlcBasePKcj
1000751c: cmp      r0, #0
10007520: movne    r1, r4
10007524: blne     #0x10006cb0
10007528: str      r0, [r4, #0x20]
1000752c: add      r1, r0, #0x12000
10007530: ldr      r2, [r1, #0xa00]
10007534: tst      r2, #1
10007538: ldreq    r1, [r1, #0x9fc]
1000753c: add      r0, r0, r2, asr #1
10007540: beq      #0x10007550
10007544: ldr      r2, [r0]
10007548: ldr      r1, [r1, #0x9fc]
1000754c: ldr      r1, [r2, r1]
10007550: pop      {r4, lr}
10007554: bx       r1
10007558: andeq    r4, r4, r8, ror ip
1000755c: push     {r4, r5, r6, r7, lr}
10007560: sub      sp, sp, #0xc
10007564: mov      r5, r1
10007568: ldr      r4, [r0, #0x20]
1000756c: ldr      r0, [r4, #4]
10007570: bl       #0x10000758  ; ->msys::MPageBase::updateInputAllChr
10007574: add      r1, r4, #0x12000
10007578: ldr      r0, [r1, #0xa08]
1000757c: tst      r0, #1
10007580: ldreq    r2, [r1, #0xa04]
10007584: add      r0, r4, r0, asr #1
10007588: beq      #0x10007598
1000758c: ldr      r2, [r0]
10007590: ldr      r1, [r1, #0xa04]
10007594: ldr      r2, [r2, r1]
10007598: mov      r1, r5
1000759c: blx      r2
100075a0: add      r0, r4, #0x28000
100075a4: mov      r7, #0
100075a8: add      r0, r0, #0xb90
100075ac: bl       #0x10000380  ; ->msys::MListWndPBase::isTpNeutral
100075b0: mov      r6, r0
100075b4: ldrb     r0, [r5, #0x11]
100075b8: cmp      r0, #0
100075bc: ldrbeq   r0, [r5, #0x12]
100075c0: cmpeq    r0, #0
100075c4: cmpne    r6, #0
100075c8: beq      #0x100075f4
100075cc: ldrh     r1, [r5, #0x14]
100075d0: ldrh     r2, [r5, #0x16]
100075d4: mov      r7, sp
100075d8: sub      r0, r1, #0xa0
100075dc: rsb      r1, r2, #0x78
100075e0: vmov     s1, r1
100075e4: vmov     s0, r0
100075e8: vcvt.f32.s32 s1, s1
100075ec: vcvt.f32.s32 s0, s0
100075f0: vstmia   sp, {s0, s1}
100075f4: mov      r1, r5
100075f8: ldr      r0, [r4]
100075fc: ldr      r2, [r0, #8]
10007600: mov      r0, r4
10007604: blx      r2
10007608: mov      r3, r0
1000760c: ldr      r0, [r4, #8]
10007610: cmp      r0, #0
10007614: bne      #0x10007624
10007618: ldr      r0, [pc, #0x34]  ; =0x3f62a8 msys::MComSys::_sys
1000761c: ldr      r0, [r0]
10007620: str      r0, [r4, #8]
10007624: add      r0, r0, #0xe0000
10007628: add      r0, r0, #0x6500
1000762c: mov      r1, r7
10007630: ldrsb    r0, [r0, #8]
10007634: and      r0, r0, r6
10007638: and      r2, r0, r3
1000763c: add      r0, r4, #0x12800
10007640: add      r0, r0, #0x214
10007644: bl       #0x10000760  ; ->ad::ctrl::ButtonGroup::Update
10007648: add      sp, sp, #0xc
1000764c: mvn      r0, #0
10007650: pop      {r4, r5, r6, r7, pc}
10007654: eorseq   r6, pc, r8, lsr #5
10007658: bx       lr
1000765c: mov      r0, #0
10007660: bx       lr
10007664: ldr      r1, [pc, #0xbc]  ; =0x100089d8
10007668: push     {r4, lr}
1000766c: mov      r4, r0
10007670: str      r1, [r0]
10007674: ldr      r0, [r0, #0x20]
10007678: cmp      r0, #0
1000767c: beq      #0x1000768c
10007680: ldr      r1, [r0]
10007684: ldr      r1, [r1, #4]
10007688: blx      r1
1000768c: mov      r0, #0
10007690: str      r0, [r4, #0x20]
10007694: ldr      r0, [pc, #0x90]  ; =0x3e483c
10007698: str      r0, [r4], #0x10
1000769c: ldr      r1, [r4], #-4
100076a0: cmp      r1, r4
100076a4: beq      #0x100076c0
100076a8: ldr      r0, [r1, #4]
100076ac: str      r1, [r1, #4]
100076b0: str      r1, [r1]
100076b4: cmp      r0, r4
100076b8: mov      r1, r0
100076bc: bne      #0x100076a8
100076c0: str      r4, [r4, #4]
100076c4: mov      r1, r4
100076c8: str      r4, [r4]
100076cc: ldr      r0, [r4, #4]!
100076d0: str      r0, [r1, #4]
100076d4: ldr      r1, [r4, #-4]
100076d8: str      r1, [r0]
100076dc: ldr      r1, [r4, #-8]
100076e0: sub      r0, r4, #0xc
100076e4: cmp      r1, r0
100076e8: beq      #0x10007704
100076ec: ldr      r2, [r1, #4]
100076f0: str      r1, [r1, #4]
100076f4: str      r1, [r1]
100076f8: cmp      r2, r0
100076fc: mov      r1, r2
10007700: bne      #0x100076ec
10007704: str      r0, [r0, #4]
10007708: str      r0, [r0]
1000770c: ldr      r2, [r0]
10007710: ldr      r1, [r0, #4]
10007714: str      r1, [r2, #4]
10007718: ldr      r2, [r0], #-4
1000771c: str      r2, [r1]
10007720: pop      {r4, lr}
10007724: b        #0x10000198  ; ->_ZdlPv
10007728: ldrdne   r8, sb, [r0], -r8
1000772c: eorseq   r4, lr, ip, lsr r8
10007730: push     {r4, lr}
10007734: mov      r4, r0
10007738: ldr      r0, [pc, #0xb0]  ; =0x100089d8
1000773c: str      r0, [r4]
10007740: ldr      r0, [r4, #0x20]
10007744: cmp      r0, #0
10007748: beq      #0x10007758
1000774c: ldr      r1, [r0]
10007750: ldr      r1, [r1, #4]
10007754: blx      r1
10007758: mov      r0, #0
1000775c: str      r0, [r4, #0x20]
10007760: ldr      r0, [pc, #0x8c]  ; =0x3e483c
10007764: str      r0, [r4], #0x10
10007768: ldr      r1, [r4], #-4
1000776c: cmp      r1, r4
10007770: beq      #0x1000778c
10007774: ldr      r0, [r1, #4]
10007778: str      r1, [r1, #4]
1000777c: str      r1, [r1]
10007780: cmp      r0, r4
10007784: mov      r1, r0
10007788: bne      #0x10007774
1000778c: str      r4, [r4, #4]
10007790: mov      r1, r4
10007794: str      r4, [r4]
10007798: ldr      r0, [r4, #4]!
1000779c: str      r0, [r1, #4]
100077a0: ldr      r1, [r4, #-4]
100077a4: str      r1, [r0]
100077a8: ldr      r1, [r4, #-8]
100077ac: sub      r0, r4, #0xc
100077b0: cmp      r1, r0
100077b4: beq      #0x100077d0
100077b8: ldr      r2, [r1, #4]
100077bc: str      r1, [r1, #4]
100077c0: str      r1, [r1]
100077c4: cmp      r2, r0
100077c8: mov      r1, r2
100077cc: bne      #0x100077b8
100077d0: str      r0, [r0, #4]
100077d4: str      r0, [r0]
100077d8: ldr      r2, [r0]
100077dc: ldr      r1, [r0, #4]
100077e0: str      r1, [r2, #4]
100077e4: ldr      r2, [r0], #-4
100077e8: str      r2, [r1]
100077ec: pop      {r4, pc}
100077f0: ldrdne   r8, sb, [r0], -r8
100077f4: eorseq   r4, lr, ip, lsr r8
100077f8: ldr      r1, [r0, #0x580]
100077fc: add      r1, r1, #0xe9000
10007800: ldrb     r1, [r1, #0x49]
10007804: cmp      r1, #0
10007808: beq      #0x10007810
1000780c: b        #0x10000378  ; ->GameMain::Back
10007810: bx       lr
10007814: push     {r4, lr}
10007818: bl       #0x10000768  ; ->msys::MTaskBase
1000781c: ldr      r1, [pc, #0x28]  ; =0x10008a10
10007820: str      r1, [r0], #0x584
10007824: bl       #0x10001380
10007828: sub      r4, r0, #0x400
1000782c: sub      r4, r4, #0x184
10007830: mov      r1, r4
10007834: bl       #0x100011f4
10007838: add      r0, r4, #0x400
1000783c: add      r0, r0, #0x184
10007840: str      r0, [r4, #0x580]
10007844: mov      r0, r4
10007848: pop      {r4, pc}
1000784c: andne    r8, r0, r0, lsl sl
10007850: ldr      r1, [pc, #0x1c]  ; =0x10008a10
10007854: push     {r4, lr}
10007858: str      r1, [r0], #0x584
1000785c: bl       #0x10003e74
10007860: sub      r0, r0, #0x400
10007864: sub      r0, r0, #0x184
10007868: bl       #0x10000770  ; ->ad::fw::TaskBase
1000786c: pop      {r4, lr}
10007870: b        #0x10000198  ; ->_ZdlPv
10007874: andne    r8, r0, r0, lsl sl
10007878: ldr      r1, [pc, #0x18]  ; =0x10008a10
1000787c: push     {r4, lr}
10007880: str      r1, [r0], #0x584
10007884: bl       #0x10003e74
10007888: sub      r0, r0, #0x400
1000788c: pop      {r4, lr}
10007890: sub      r0, r0, #0x184
10007894: b        #0x10000770  ; ->ad::fw::TaskBase
10007898: andne    r8, r0, r0, lsl sl
1000789c: push     {r4, lr}
100078a0: bl       #0x10000778  ; ->MoveWorkF
100078a4: mov      r1, r0
100078a8: ldr      r0, [pc, #0x18]  ; =0x10008788
100078ac: vldr     s0, [pc, #0x18]  ; =0x0 (0)
100078b0: str      r0, [r1]
100078b4: vstr     s0, [r1, #0x20]
100078b8: vstr     s0, [r1, #0x24]
100078bc: vstr     s0, [r1, #0x28]
100078c0: mov      r0, r1
100078c4: pop      {r4, pc}
100078c8: andne    r8, r0, r8, lsl #15
100078cc: andeq    r0, r0, r0
100078d0: push     {r4, lr}
100078d4: bl       #0x10000780  ; ->MoveWorkF
100078d8: pop      {r4, lr}
100078dc: b        #0x10000198  ; ->_ZdlPv
100078e0: b        #0x10000780  ; ->MoveWorkF
100078e4: add      r0, r0, #4
100078e8: b        #0x10000290  ; ->nn::fs::detail::FileBase::TryGetSize
100078ec: ldrd     r0, r1, [r0, #8]
100078f0: bx       lr
100078f4: add      r0, r0, #8
100078f8: ldm      r0, {r0, r2}
100078fc: stm      r1, {r0, r2}
10007900: mov      r0, #0
10007904: bx       lr
10007908: str      lr, [sp, #-4]!
1000790c: sub      sp, sp, #0xc
10007910: mov      r1, sp
10007914: add      r0, r0, #4
10007918: bl       #0x10000290  ; ->nn::fs::detail::FileBase::TryGetSize
1000791c: mov      r1, pc
10007920: lsrs     r2, r0, #0x1f
10007924: blne     #0x100001a8  ; ->nn::err::CTR::ThrowFatalErrAll
10007928: ldrd     r0, r1, [sp]
1000792c: add      sp, sp, #0xc
10007930: pop      {pc}
10007934: push     {r4, r5, r6, lr}
10007938: mov      r5, r1
1000793c: ldr      r1, [r0]
10007940: mov      r4, r2
10007944: ldr      r1, [r1, #8]
10007948: blx      r1
1000794c: and      r0, r0, r4
10007950: cmp      r0, r5
10007954: moveq    r0, #1
10007958: movne    r0, #0
1000795c: pop      {r4, r5, r6, pc}
10007960: mov      r0, #0
10007964: bx       lr
10007968: mov      r0, #2
1000796c: bx       lr
10007970: mov      r0, #7
10007974: bx       lr
10007978: ldrb     r0, [r1, #0x12]
1000797c: cmp      r0, #0
10007980: movne    r0, #1
10007984: bx       lr

<AttackMiniGame:nnroControlObject_>  # AttackMiniGame:nnroControlObject_
10007988: ldr      r2, [pc, #0x80]  ; =0x1000e68c
1000798c: cmp      r1, #5
10007990: push     {r4, lr}
10007994: ldrlo    pc, [pc, r1, lsl #2]
10007998: b        #0x100079f4
1000799c: strhne   r7, [r0], -r0
100079a0: strhne   r7, [r0], -r8
100079a4: andne    r7, r0, r0, asr #19
100079a8: andne    r7, r0, ip, asr #19
100079ac: ldrdne   r7, r8, [r0], -ip
100079b0: ldr      r1, [pc, #0x5c]  ; =0x0
100079b4: b        #0x100079c4
100079b8: str      r0, [r2]
100079bc: b        #0x100079ec
100079c0: ldr      r1, [r2]
100079c4: str      r1, [r0]
100079c8: b        #0x100079ec
100079cc: ldr      r1, [pc, #0x44]  ; =0x10007b24
100079d0: str      r1, [r0]
100079d4: ldr      r1, [pc, #0x40]  ; =0x10007b24
100079d8: b        #0x100079e8
100079dc: ldr      r1, [pc, #0x3c]  ; =0x10008ffc
100079e0: str      r1, [r0]
100079e4: ldr      r1, [pc, #0x38]  ; =0x10008ffc
100079e8: str      r1, [r0, #4]
100079ec: mov      r0, #0
100079f0: pop      {r4, pc}
100079f4: ldr      r0, [pc, #0x2c]  ; =0x30000000
100079f8: mov      r0, r0
100079fc: ldr      r0, [pc, #0x28]  ; =0x30000027
10007a00: nop      
10007a04: mov      r0, r0
10007a08: ldr      r0, [pc, #0x20]  ; =0xd8e12c21
10007a0c: pop      {r4, pc}
10007a10: andne    lr, r0, ip, lsl #13
10007a14: andeq    r0, r0, r0
10007a18: andne    r7, r0, r4, lsr #22
10007a1c: andne    r7, r0, r4, lsr #22
10007a20: strdne   r8, sb, [r0], -ip
10007a24: strdne   r8, sb, [r0], -ip
10007a28: andlo    r0, r0, r0
10007a2c: andlo    r0, r0, r7, lsr #32
10007a30: stmle    r1!, {r0, r5, sl, fp, sp} ^
10007a34: push     {r3, r4, r5, r6, r7, r8, sb, lr}
10007a38: mov      r5, r0
10007a3c: ldr      r6, [r0, #8]
10007a40: ldr      r0, [r0, #0x14]
10007a44: ldr      r4, [r5, #0x10]
10007a48: add      r7, r4, r0, lsl #3
10007a4c: cmp      r4, r7
10007a50: movne    r8, #0
10007a54: beq      #0x10007adc
10007a58: ldrb     r0, [r4, #4]
10007a5c: cmp      r0, #1
10007a60: beq      #0x10007a78
10007a64: cmp      r0, #0x12
10007a68: beq      #0x10007a94
10007a6c: cmp      r0, #0x13
10007a70: beq      #0x10007ab4
10007a74: b        #0x10007acc
10007a78: ldr      r1, [r4]
10007a7c: mov      r2, #0
10007a80: mov      r0, r6
10007a84: bl       #0x10000788  ; ->ad::fw::FileContext::initSingleFile
10007a88: nop      
10007a8c: nop      
10007a90: b        #0x10007acc
10007a94: ldr      r2, [r5, #0xc]
10007a98: ldr      r1, [r4]
10007a9c: mov      r3, #0
10007aa0: mov      r0, r6
10007aa4: bl       #0x10000790  ; ->ad::fw::FileContext::initArcFile
10007aa8: nop      
10007aac: nop      
10007ab0: b        #0x10007acc
10007ab4: str      r8, [sp]
10007ab8: ldr      r1, [r4]
10007abc: ldr      r2, [r5, #0xc]
10007ac0: add      r3, r5, #0x18
10007ac4: mov      r0, r6
10007ac8: bl       #0x10000798  ; ->ad::fw::FileContext::initCAArcFile
10007acc: add      r4, r4, #8
10007ad0: cmp      r4, r7
10007ad4: add      r6, r6, #0xa8
10007ad8: bne      #0x10007a58
10007adc: pop      {r3, r4, r5, r6, r7, r8, sb, pc}
10007ae0: b        #0x10000198  ; ->_ZdlPv
10007ae4: bx       lr
10007ae8: push     {r4, lr}
10007aec: mov      r4, r0
10007af0: bl       #0x100007a0  ; ->msys::MCursorBase::init
10007af4: mov      r2, #0
10007af8: add      r0, r4, #0x30
10007afc: mov      r1, #3
10007b00: subs     r1, r1, #1
10007b04: str      r2, [r0], #4
10007b08: bne      #0x10007b00
10007b0c: pop      {r4, pc}
10007b10: push     {r4, lr}
10007b14: bl       #0x10000738  ; ->msys::MCursorBase
10007b18: pop      {r4, lr}
10007b1c: b        #0x10000198  ; ->_ZdlPv
10007b20: b        #0x10000738  ; ->msys::MCursorBase
