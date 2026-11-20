
<->_ZnwjP10MemAlcBasePKcj>  # veneer->_ZnwjP10MemAlcBasePKcj
11800180: ldr      pc, [pc, #-4]
11800184: eoreq    r7, r8, r0, asr #26

<->TaskMan::entry>  # veneer->_ZN7TaskMan5entryEP4Task
11800188: ldr      pc, [pc, #-4]
1180018c: eoreq    r7, r8, r8, lsl fp

<->_ZdlPv>  # veneer->_ZdlPv
11800190: ldr      pc, [pc, #-4]
11800194: eoreq    r6, r8, r4, lsl r5

<->MsgDataAcsrBase>  # veneer->_ZN15MsgDataAcsrBaseD1Ev
11800198: ldr      pc, [pc, #-4]
1180019c: .word    0x0026fdb4

<->nn::fs::detail::FileBase::TrySetPosition>  # veneer->_ZN2nn2fs6detail8FileBase14TrySetPositionEx
118001a0: ldr      pc, [pc, #-4]
118001a4: eoreq    lr, r7, r8, lsr #24

<->nn::err::CTR::ThrowFatalErrAll>  # veneer->_ZN2nn3err3CTR16ThrowFatalErrAllENS_6ResultEj
118001a8: ldr      pc, [pc, #-4]
118001ac: eoreq    r6, r8, r0, lsr r5

<->nn::fs::detail::FileBase::TryRead>  # veneer->_ZN2nn2fs6detail8FileBase7TryReadEPiPvj
118001b0: ldr      pc, [pc, #-4]
118001b4: eoreq    r6, r8, r8, lsl #9

<->nn::fs::detail::FileBase::TrySeek>  # veneer->_ZN2nn2fs6detail8FileBase7TrySeekExNS0_12PositionBaseE
118001b8: ldr      pc, [pc, #-4]
118001bc: .word    0x002854d0

<->nndbgPanic>  # veneer->nndbgPanic
118001c0: ldr      pc, [pc, #-4]
118001c4: eoreq    r6, r8, ip, lsr #8

<->nn::fs::CTR::MPCore::detail::UserFileSystem::CloseFile>  # veneer->_ZN2nn2fs3CTR6MPCore6detail14UserFileSystem9CloseFileEPv
118001c8: ldr      pc, [pc, #-4]
118001cc: eoreq    r6, r8, r0, lsl r4

<->__c89vswprintf>  # veneer->__c89vswprintf
118001d0: ldr      pc, [pc, #-4]
118001d4: andseq   r0, r0, sp, asr r0

<->ad::lyt::LytResourceMan::init>  # veneer->_ZN2ad3lyt14LytResourceMan4initEv
118001d8: ldr      pc, [pc, #-4]
118001dc: eoreq    r0, r5, ip, lsl sp

<->ad::fw::Resource::getFileData>  # veneer->_ZN2ad2fw8Resource11getFileDataEv
118001e0: ldr      pc, [pc, #-4]
118001e4: eoreq    r1, r5, r0, lsl sp

<->ad::lyt::LytResourceMan::registerArc>  # veneer->_ZN2ad3lyt14LytResourceMan11registerArcEPvPKc
118001e8: ldr      pc, [pc, #-4]
118001ec: andseq   ip, r5, r0, lsl sb

<->msys::MLyt::init>  # veneer->_ZN4msys4MLyt4initEPN2ad3lyt11LytDrawDataEa
118001f0: ldr      pc, [pc, #-4]
118001f4: eorseq   ip, r2, r0, lsr #7

<->msys::MLyt::createLyt>  # veneer->_ZN4msys4MLyt9createLytEPN2ad3lyt14LytResourceManEPKc
118001f8: ldr      pc, [pc, #-4]
118001fc: eorseq   ip, r2, ip, lsl #15

<->MoveVBase::stop>  # veneer->_ZN9MoveVBase4stopEv
11800200: ldr      pc, [pc, #-4]
11800204: .word    0x00259dd8

<->msys::MLyt::build>  # veneer->_ZN4msys4MLyt5buildEP10MemAlcBasePKNS0_9AnimeNameEt
11800208: ldr      pc, [pc, #-4]
1180020c: eorseq   ip, r2, r0, ror #8

<->msys::MLyt::createLyt>  # veneer->_ZN4msys4MLyt9createLytEPN2ad3lyt14LytResourceManEPKcPNS1_4ctrl11ButtonGroupEPNS_11MCursorBaseE
11800210: ldr      pc, [pc, #-4]
11800214: eorseq   ip, r2, r0, asr #17

<->msys::MListWndPBase::setEnableInput>  # veneer->_ZN4msys13MListWndPBase14setEnableInputEb
11800218: ldr      pc, [pc, #-4]
1180021c: eorseq   r8, r2, r8, lsr r6

<->msys::MCellAnime::init>  # veneer->_ZN4msys10MCellAnime4initEPKN2ad2fw8ResourceE
11800220: ldr      pc, [pc, #-4]
11800224: .word    0x002079d8

<->msys::MLyt::attachMChr>  # veneer->_ZN4msys4MLyt10attachMChrERNS_8MChrBaseEPKcS4_S4_S4_
11800228: ldr      pc, [pc, #-4]
1180022c: eoreq    r7, r0, r8, ror #8

<->msys::MDfxChr::init>  # veneer->_ZN4msys7MDfxChr4initEP10MemAlcBasePNS_7MDfxSysEPN2ad3h3d5SceneEj
11800230: ldr      pc, [pc, #-4]
11800234: eorseq   r0, r3, r0, asr #19

<->Backup::errorCode>  # veneer->_ZNK6Backup9errorCodeEv
11800238: ldr      pc, [pc, #-4]
1180023c: .word    0x002063b8

<->Backup::isBusyFormat>  # veneer->_ZN6Backup12isBusyFormatEv
11800240: ldr      pc, [pc, #-4]
11800244: eorseq   sb, r3, r8, ror r3

<->Backup::mount>  # veneer->_ZN6Backup5mountEv
11800248: ldr      pc, [pc, #-4]
1180024c: eorseq   sb, r3, ip, lsl #26

<->Backup::rewriteSaveData>  # veneer->_ZN6Backup15rewriteSaveDataEv
11800250: ldr      pc, [pc, #-4]
11800254: eorseq   sb, r3, ip, lsl #24

<->CtrFS::unmountSaveData>  # veneer->_ZN5CtrFS15unmountSaveDataEv
11800258: ldr      pc, [pc, #-4]
1180025c: eoreq    r7, r0, ip, lsr pc

<->Backup::format>  # veneer->_ZN6Backup6formatEv
11800260: ldr      pc, [pc, #-4]
11800264: eorseq   sb, r3, r4, lsr sp

<->GameMain::Back>  # veneer->_ZN8GameMain4BackEP12TaskMainBase
11800268: ldr      pc, [pc, #-4]
1180026c: eorseq   lr, r3, r4, asr r3

<->ad::lyt::LytNumReel3::InitParam>  # veneer->_ZN2ad3lyt11LytNumReel39InitParamC1Ev
11800270: ldr      pc, [pc, #-4]
11800274: mlaeq    r5, r4, r1, r6

<->msys::MLytNumRes::set>  # veneer->_ZN4msys10MLytNumRes3setERN2ad3lyt11LytNumReel39InitParamENS_11eLytNumTypeENS_7eLytNumES7_
11800278: ldr      pc, [pc, #-4]
1180027c: mlaeq    r0, r4, r5, r7

<->msys::MLytNum::init>  # veneer->_ZN4msys7MLytNum4initERN2ad3lyt11LytNumReel39InitParamEPNS2_11LytDrawDataERNS_4MLytEPKcSB_SB_SB_
11800280: ldr      pc, [pc, #-4]
11800284: ldrhteq  r1, [r3], -r8

<->MessageSimple::init>  # veneer->_ZN13MessageSimple4initEv
11800288: ldr      pc, [pc, #-4]
1180028c: .word    0x002736b4

<->LMS_GetTextIndexByLabel>  # veneer->LMS_GetTextIndexByLabel
11800290: ldr      pc, [pc, #-4]
11800294: eoreq    r6, r7, ip, ror #2

<->LMS_GetText>  # veneer->LMS_GetText
11800298: ldr      pc, [pc, #-4]
1180029c: eoreq    r6, r7, ip, lsl #12

<->msys::MMsg::playStr>  # veneer->_ZN4msys4MMsg7playStrEPKwPN13MessageSimple8InsParamEb
118002a0: ldr      pc, [pc, #-4]
118002a4: eorseq   ip, r2, ip, lsl #28

<->MessageWriter::setFontColor>  # veneer->_ZN13MessageWriter12setFontColorEjb
118002a8: ldr      pc, [pc, #-4]
118002ac: eoreq    r0, r7, ip, lsl #30

<->ad::lyt::LytAnim::init>  # veneer->_ZN2ad3lyt7LytAnim4initEPNS0_6LayoutEPKcS5_
118002b0: ldr      pc, [pc, #-4]
118002b4: eoreq    r4, r6, r4, lsl #30

<->ad::lyt::AnimTransform::GetFrameSize>  # veneer->_ZNK2ad3lyt13AnimTransform12GetFrameSizeEv
118002b8: ldr      pc, [pc, #-4]
118002bc: eoreq    pc, r6, r8, lsr lr

<->ad::lyt::LytAnim::stopAndSetFrm>  # veneer->_ZN2ad3lyt7LytAnim13stopAndSetFrmEf
118002c0: ldr      pc, [pc, #-4]
118002c4: eoreq    pc, r6, r4, asr #28

<->ad::lyt::LytAnim::term>  # veneer->_ZN2ad3lyt7LytAnim4termEb
118002c8: ldr      pc, [pc, #-4]
118002cc: mlaeq    r6, r0, lr, r4

<->msys::MDfxChr::term>  # veneer->_ZN4msys7MDfxChr4termEv
118002d0: ldr      pc, [pc, #-4]
118002d4: eorseq   r0, r3, r8, ror #24

<->msys::MDfxChr::playDfx>  # veneer->_ZN4msys7MDfxChr7playDfxEj
118002d8: ldr      pc, [pc, #-4]
118002dc: eorseq   r0, r3, r4, ror #26

<->Mem::Fill>  # veneer->_ZN3Mem4FillEPvjj
118002e0: ldr      pc, [pc, #-4]
118002e4: eoreq    r4, r8, r8, ror #19

<->nn::nstd::TSPrintf>  # veneer->_ZN2nn4nstd8TSPrintfEPcPKcz
118002e8: ldr      pc, [pc, #-4]
118002ec: eoreq    r6, r7, ip, asr #11

<->msys::MLyt::getParts>  # veneer->_ZN4msys4MLyt8getPartsEPKcS2_S2_
118002f0: ldr      pc, [pc, #-4]
118002f4: eoreq    r7, r0, ip, ror #7

<->msys::MLyt::getPane>  # veneer->_ZN4msys4MLyt7getPaneEPKcS2_S2_
118002f8: ldr      pc, [pc, #-4]
118002fc: eorseq   ip, r2, r8, lsl #13

<->ad::lyt::LytNumReel3::setValueInstant>  # veneer->_ZN2ad3lyt11LytNumReel315setValueInstantEi
11800300: ldr      pc, [pc, #-4]
11800304: eoreq    r7, r0, ip, asr r8

<->msys::MListWndPBase::isTpNeutral>  # veneer->_ZNK4msys13MListWndPBase11isTpNeutralEv
11800308: ldr      pc, [pc, #-4]
1180030c: eorseq   r2, r6, r8, asr #1

<->msys::MListWndPBase::getCurNo>  # veneer->_ZNK4msys13MListWndPBase8getCurNoEv
11800310: ldr      pc, [pc, #-4]
11800314: eorseq   r2, r6, r0, ror #1

<->msys::MListWndPBase::getCurItem>  # veneer->_ZNK4msys13MListWndPBase10getCurItemEv
11800318: ldr      pc, [pc, #-4]
1180031c: strhteq  sl, [r5], -ip

<->msys::MListWndPBase::getSelectItem>  # veneer->_ZN4msys13MListWndPBase13getSelectItemEv
11800320: ldr      pc, [pc, #-4]
11800324: ldrshteq r8, [r2], -r0

<->msys::MLyt::getAnim>  # veneer->_ZN4msys4MLyt7getAnimEs
11800328: ldr      pc, [pc, #-4]
1180032c: eorseq   ip, r2, r8, ror r6

<->msys::MLyt::createAnime>  # veneer->_ZN4msys4MLyt11createAnimeEhPKcS2_ba
11800330: ldr      pc, [pc, #-4]
11800334: eoreq    r6, r0, r8, asr #24

<->msys::MLyt::createAnimeAutoSlot>  # veneer->_ZN4msys4MLyt19createAnimeAutoSlotEPKcS2_S2_
11800338: ldr      pc, [pc, #-4]
1180033c: eorseq   ip, r2, r8, lsl #6

<->Backup::isBusyWriting>  # veneer->_ZN6Backup13isBusyWritingEv
11800340: ldr      pc, [pc, #-4]
11800344: eorseq   sb, r3, r8, asr r5

<->Backup::term>  # veneer->_ZN6Backup4termEv
11800348: ldr      pc, [pc, #-4]
1180034c: eorseq   sb, r3, r4, lsl #25

<->msys::MLyt::playAnimeFromNo>  # veneer->_ZN4msys4MLyt15playAnimeFromNoEjjPKcS2_
11800350: ldr      pc, [pc, #-4]
11800354: mlaseq   r2, r8, pc, fp

<->msys::MListWndPBase::applyAnime>  # veneer->_ZN4msys13MListWndPBase10applyAnimeEv
11800358: ldr      pc, [pc, #-4]
1180035c: eorseq   r8, r2, ip, asr #8

<->ad::lyt::Layout::Animate>  # veneer->_ZN2ad3lyt6Layout7AnimateEv
11800360: ldr      pc, [pc, #-4]
11800364: andseq   r1, r6, ip, ror #21

<->ad::lyt::LytResourceMan::buildLayout>  # veneer->_ZN2ad3lyt14LytResourceMan11buildLayoutERNS0_6LayoutEPKcPNS0_14ControlCreatorEPNS0_12TextSearcherE
11800368: ldr      pc, [pc, #-4]
1180036c: mlaeq    r5, r0, r4, r6

<->ad::lyt::LytAnim::playAuto>  # veneer->_ZN2ad3lyt7LytAnim8playAutoEf
11800370: ldr      pc, [pc, #-4]
11800374: eoreq    r6, r5, ip, lsl #4

<->ad::ui::UIListWindowPlusLyt::InitParam>  # veneer->_ZN2ad2ui19UIListWindowPlusLyt9InitParamC1Ev
11800378: ldr      pc, [pc, #-4]
1180037c: mulseq   r4, r8, r3

<->msys::SetMListWndInitParam>  # veneer->_ZN4msys20SetMListWndInitParamERN2ad2ui19UIListWindowPlusLyt9InitParamENS_13eMListWndTypeE
11800380: ldr      pc, [pc, #-4]
11800384: eorseq   sb, r2, r0, ror #28

<->msys::MListWndPBase::init>  # veneer->_ZN4msys13MListWndPBase4initERN2ad2ui19UIListWindowPlusLyt9InitParamEPNS1_3lyt11LytDrawDataEP4PrimP13MessageDrawerPNS1_17ApplyingSceneInfoE
11800388: ldr      pc, [pc, #-4]
1180038c: mlaseq   r2, r8, r6, r8

<->msys::MListWndPBase::resetCur>  # veneer->_ZN4msys13MListWndPBase8resetCurEv
11800390: ldr      pc, [pc, #-4]
11800394: eorseq   r8, r2, r0, asr #15

<->ad::lyt::Layout>  # veneer->_ZN2ad3lyt6LayoutD1Ev
11800398: ldr      pc, [pc, #-4]
1180039c: eoreq    r2, r6, ip, ror #29

<->ad::ui::UIListWindowPlusLyt>  # veneer->_ZN2ad2ui19UIListWindowPlusLytD1Ev
118003a0: ldr      pc, [pc, #-4]
118003a4: .word    0x0025a3fc

<->msys::MListWndPBase>  # veneer->_ZN4msys13MListWndPBaseD1Ev
118003a8: ldr      pc, [pc, #-4]
118003ac: eorseq   r8, r2, r0, lsr #17

<->ad::lyt::LytLocalize>  # veneer->_ZN2ad3lyt11LytLocalizeC1Ev
118003b0: ldr      pc, [pc, #-4]
118003b4: .word    0x002563d4

<->ad::lyt::LytLocalize::localize>  # veneer->_ZN2ad3lyt11LytLocalize8localizeEPNS0_6LayoutE
118003b8: ldr      pc, [pc, #-4]
118003bc: eoreq    r4, r6, r8, lsl #28

<->Message::init>  # veneer->_ZN7Message4initEv
118003c0: ldr      pc, [pc, #-4]
118003c4: eorseq   sp, r3, ip, lsr #24

<->Message::setMsgDat>  # veneer->_ZN7Message9setMsgDatEPKv
118003c8: ldr      pc, [pc, #-4]
118003cc: eorseq   sp, r3, r8, asr #27

<->GameWork::getCoin>  # veneer->_ZNK8GameWork7getCoinEv
118003d0: ldr      pc, [pc, #-4]
118003d4: eorseq   r3, r6, r0, lsr #2

<->ad::ctrl::ButtonGroup::FindButtonByName>  # veneer->_ZN2ad4ctrl11ButtonGroup16FindButtonByNameEPKc
118003d8: ldr      pc, [pc, #-4]
118003dc: eoreq    r6, r5, r0, lsl #13

<->ad::ctrl::AnimButton::SetStateChangeCallback>  # veneer->_ZN2ad4ctrl10AnimButton22SetStateChangeCallbackEPFvPS1_NS0_10ButtonBase5StateES4_PvES5_
118003e0: ldr      pc, [pc, #-4]
118003e4: eoreq    r6, r5, r4, ror r6

<->ad::fw::TaskBase::isFps30>  # veneer->_ZNK2ad2fw8TaskBase7isFps30Ev
118003e8: ldr      pc, [pc, #-4]
118003ec: .word    0x0025edd0

<->msys::MCursorBase::setVisible>  # veneer->_ZN4msys11MCursorBase10setVisibleEb
118003f0: ldr      pc, [pc, #-4]
118003f4: eorseq   r4, r2, r4, asr r4

<->msys::MLyt::setAnimeInfo>  # veneer->_ZN4msys4MLyt12setAnimeInfoEjj
118003f8: ldr      pc, [pc, #-4]
118003fc: eorseq   fp, r2, r0, asr #24

<->GameMain::GameModeOld>  # veneer->_ZN8GameMain11GameModeOldEv
11800400: ldr      pc, [pc, #-4]
11800404: eorseq   lr, r3, r0, lsr #6

<->msys::MListWndPBase::getListWnd>  # veneer->_ZNK4msys13MListWndPBase10getListWndEv
11800408: ldr      pc, [pc, #-4]
1180040c: eorseq   r2, r6, r0, asr #1

<->col::GetBootInfo>  # veneer->_ZN3col11GetBootInfoEv
11800410: ldr      pc, [pc, #-4]
11800414: eoreq    r1, sl, r4, ror #28

<->col::BootInfo::saveBgm>  # veneer->_ZN3col8BootInfo7saveBgmEv
11800418: ldr      pc, [pc, #-4]
1180041c: eoreq    r2, sl, r4, asr #1

<->hb::GetColiseumResult>  # veneer->_ZN2hb17GetColiseumResultEv
11800420: ldr      pc, [pc, #-4]
11800424: andseq   ip, r6, r4, lsr #18

<->btl::GetBootInfo>  # veneer->_ZN3btl11GetBootInfoEv
11800428: ldr      pc, [pc, #-4]
1180042c: .word    0x00217ff8

<->col::BootInfo::dataPartyRestor>  # veneer->_ZN3col8BootInfo15dataPartyRestorEv
11800430: ldr      pc, [pc, #-4]
11800434: eoreq    r1, sl, r0, lsr #31

<->msys::MLyt::stopAnimeAndSetEnd>  # veneer->_ZN4msys4MLyt18stopAnimeAndSetEndEjjPKcS2_
11800438: ldr      pc, [pc, #-4]
1180043c: eorseq   ip, r2, ip, ror r2

<->Frm::play>  # veneer->_ZN3Frm4playEf
11800440: ldr      pc, [pc, #-4]
11800444: eoreq    sl, r7, r4, lsr #6

<->col::BootInfo::restoreBgm>  # veneer->_ZN3col8BootInfo10restoreBgmEv
11800448: ldr      pc, [pc, #-4]
1180044c: .word    0x002a1eb4

<->msys::MLyt::isEnableAnime>  # veneer->_ZN4msys4MLyt13isEnableAnimeEv
11800450: ldr      pc, [pc, #-4]
11800454: eorseq   fp, r2, ip, ror #24

<->Message::close>  # veneer->_ZN7Message5closeEv
11800458: ldr      pc, [pc, #-4]
1180045c: eoreq    sp, r4, r8, asr #25

<->Backup::GetSaveData1>  # veneer->_ZN6Backup12GetSaveData1Es
11800460: ldr      pc, [pc, #-4]
11800464: eorseq   sb, r3, r4, lsl #5

<->Mem::Copy>  # veneer->_ZN3Mem4CopyEPvPKvj
11800468: ldr      pc, [pc, #-4]
1180046c: eoreq    pc, r7, r8, lsl #26

<->Backup::init>  # veneer->_ZN6Backup4initEP5CtrFS
11800470: ldr      pc, [pc, #-4]
11800474: eorseq   sb, r3, r4, asr ip

<->Backup::writeSaveData0>  # veneer->_ZN6Backup14writeSaveData0Es
11800478: ldr      pc, [pc, #-4]
1180047c: eorseq   sb, r3, r0, lsr #21

<->MoveC::moveFrm>  # veneer->_ZN5MoveC7moveFrmERKN2nn4util6Color8Ef
11800480: ldr      pc, [pc, #-4]
11800484: eoreq    fp, r6, r4, ror ip

<->PutRegFlag>  # veneer->_Z10PutRegFlagtfP11GlobalEventP10LocalEvent
11800488: ldr      pc, [pc, #-4]
1180048c: eoreq    r3, r7, r0, lsr #3

<->__aeabi_uidivmod>  # veneer->__aeabi_uidivmod
11800490: ldr      pc, [pc, #-4]
11800494: eoreq    r1, r8, r8, lsr #12

<->ad::db::GetItemMsg>  # veneer->_ZN2ad2db10GetItemMsgEt14eDBItemMsgType
11800498: ldr      pc, [pc, #-4]
1180049c: mulseq   r3, r4, r1

<->GameWork::addCoin>  # veneer->_ZN8GameWork7addCoinEi
118004a0: ldr      pc, [pc, #-4]
118004a4: eoreq    lr, r2, r4, lsl #25

<->ad::lyt::LytNumReel3::setValue>  # veneer->_ZN2ad3lyt11LytNumReel38setValueEi
118004a8: ldr      pc, [pc, #-4]
118004ac: andseq   sl, r5, r8, asr #15

<->msys::MSndSe::play>  # veneer->_ZN4msys6MSndSe4playEjPKNS_8MChrBaseEPKN2nn4math4VEC2Eb
118004b0: ldr      pc, [pc, #-4]
118004b4: eorseq   sp, r2, r4, asr #16

<->SndSys::start>  # veneer->_ZN6SndSys5startEjPN2nw3snd11SoundHandleE
118004b8: ldr      pc, [pc, #-4]
118004bc: eorseq   ip, r3, ip, ror r7

<->SndSys::stopAllBgm>  # veneer->_ZN6SndSys10stopAllBgmEi
118004c0: ldr      pc, [pc, #-4]
118004c4: eorseq   ip, r3, r0, asr r4

<->col::BootInfo::playBgm>  # veneer->_ZN3col8BootInfo7playBgmEv
118004c8: ldr      pc, [pc, #-4]
118004cc: eoreq    r1, sl, r0, asr #31

<->SndSeCtrl::stop>  # veneer->_ZN9SndSeCtrl4stopEi
118004d0: ldr      pc, [pc, #-4]
118004d4: eoreq    r3, r8, ip, asr #5

<->Frm::update>  # veneer->_ZN3Frm6updateEf
118004d8: ldr      pc, [pc, #-4]
118004dc: .word    0x0026aed4

<->ad::fw::TaskBase::term>  # veneer->_ZN2ad2fw8TaskBase4termEj
118004e0: ldr      pc, [pc, #-4]
118004e4: eoreq    sl, r4, r8, asr r3

<->msys::MLyt::term>  # veneer->_ZN4msys4MLyt4termEv
118004e8: ldr      pc, [pc, #-4]
118004ec: eorseq   ip, r2, r8, asr #7

<->ad::fw::Resource::term>  # veneer->_ZN2ad2fw8Resource4termEv
118004f0: ldr      pc, [pc, #-4]
118004f4: eoreq    r3, r3, r0, asr #6

<->__aeabi_vec_dtor>  # veneer->__aeabi_vec_dtor
118004f8: ldr      pc, [pc, #-4]
118004fc: eoreq    r8, r8, r1, lsr r2

<->ad::fw::Resource>  # veneer->_ZN2ad2fw8ResourceD1Ev
11800500: ldr      pc, [pc, #-4]
11800504: eoreq    sl, r4, r4, lsl #2

<->msys::MComSys>  # veneer->_ZN4msys7MComSysD1Ev
11800508: ldr      pc, [pc, #-4]
1180050c: eorseq   r0, r3, r8, ror #1

<->MoveVBase>  # veneer->_ZN9MoveVBaseC1Ev
11800510: ldr      pc, [pc, #-4]
11800514: eoreq    sb, r5, r0, asr #14

<->__aeabi_vec_ctor_nocookie_nodtor>  # veneer->__aeabi_vec_ctor_nocookie_nodtor
11800518: ldr      pc, [pc, #-4]
1180051c: eoreq    r7, r8, sp, lsl r7

<->MoveVBase>  # veneer->_ZN9MoveVBaseD1Ev
11800520: ldr      pc, [pc, #-4]
11800524: eoreq    r3, r5, r8, ror #11

<->strcpy>  # veneer->strcpy
11800528: ldr      pc, [pc, #-4]
1180052c: .word    0x002697dc

<->ad::Encount::GetInst>  # veneer->_ZN2ad7Encount7GetInstEv
11800530: ldr      pc, [pc, #-4]
11800534: eoreq    r7, r8, ip, asr #30

<->ad::Encount::startLoadRes>  # veneer->_ZN2ad7Encount12startLoadResEN3btl12eEncountTypeEhhNS1_12eEntryFxTypeENS0_8eAnmTypeE
11800538: ldr      pc, [pc, #-4]
1180053c: andseq   sl, r6, ip, lsl #16

<->GameMain::Change>  # veneer->_ZN8GameMain6ChangeE9GAME_MODEP12TaskMainBase
11800540: ldr      pc, [pc, #-4]
11800544: ldrshteq lr, [r3], -ip

<->Message::play>  # veneer->_ZN7Message4playEPNS_9PlayParamE
11800548: ldr      pc, [pc, #-4]
1180054c: eoreq    sb, r5, r0, ror sb

<->GameWork::addItem>  # veneer->_ZN8GameWork7addItemEta
11800550: ldr      pc, [pc, #-4]
11800554: eorseq   lr, r3, r8, asr #27

<->strcmp>  # veneer->strcmp
11800558: ldr      pc, [pc, #-4]
1180055c: .word    0x002833b8

<->msys::MCtrlUserData::findExtUserDataByName>  # veneer->_ZNK4msys13MCtrlUserData21findExtUserDataByNameEPKc
11800560: ldr      pc, [pc, #-4]
11800564: eorseq   r2, r6, ip, lsr r0

<->__cxa_guard_acquire>  # veneer->__cxa_guard_acquire
11800568: ldr      pc, [pc, #-4]
1180056c: eoreq    r8, r8, r1, lsl r1

<->__cxa_guard_release>  # veneer->__cxa_guard_release
11800570: ldr      pc, [pc, #-4]
11800574: andseq   r1, r0, sb, lsr #17

<->hb::SetBootInfoColosseum>  # veneer->_ZN2hb20SetBootInfoColosseumENS_4boot8eSubModeE
11800578: ldr      pc, [pc, #-4]
1180057c: andseq   ip, r6, r8, ror #20

<->col::BootInfo::dataPartyBackup>  # veneer->_ZN3col8BootInfo15dataPartyBackupEv
11800580: ldr      pc, [pc, #-4]
11800584: .word    0x002a1ef8

<->msys::MLyt::isBusyAnime>  # veneer->_ZN4msys4MLyt11isBusyAnimeEv
11800588: ldr      pc, [pc, #-4]
1180058c: eorseq   fp, r2, r4, lsl fp

<->msys::MLyt::getAnime>  # veneer->_ZN4msys4MLyt8getAnimeEj
11800590: ldr      pc, [pc, #-4]
11800594: eorseq   ip, r2, r8, lsr r7

<->Message::term>  # veneer->_ZN7Message4termEv
11800598: ldr      pc, [pc, #-4]
1180059c: eorseq   sp, r3, r8, ror #24

<->Message>  # veneer->_ZN7MessageD1Ev
118005a0: ldr      pc, [pc, #-4]
118005a4: eoreq    r6, r0, r8, lsr r5

<->ad::lyt::LytDrawSys::GetInst>  # veneer->_ZN2ad3lyt10LytDrawSys7GetInstEv
118005a8: ldr      pc, [pc, #-4]
118005ac: eoreq    r7, r8, r8, asr pc

<->ad::lyt::Initialize>  # veneer->_ZN2ad3lyt10InitializeEPN2nw2os10IAllocatorES4_
118005b0: ldr      pc, [pc, #-4]
118005b4: eoreq    r5, r8, r0, ror #11

<->ad::TransMultiSymbol::init>  # veneer->_ZN2ad16TransMultiSymbol4initEPKc
118005b8: ldr      pc, [pc, #-4]
118005bc: .word    0x0026d7f8

<->BinGlu4Acs::getEntryAcs>  # veneer->_ZNK10BinGlu4Acs11getEntryAcsEPKc
118005c0: ldr      pc, [pc, #-4]
118005c4: eoreq    r5, r8, r8, ror #4

<->ad::fw::TaskBase::readCA>  # veneer->_ZN2ad2fw8TaskBase6readCAEPNS0_8ResourceEPNS0_11FileContextEPKcS7_S7_S7_S7_P10MemAlcBasejP11VramAlcBasejPNS0_11ResCacheArgE
118005c8: ldr      pc, [pc, #-4]
118005cc: .word    0x0026daf8

<->ad::fw::TaskBase::readLyt>  # veneer->_ZN2ad2fw8TaskBase7readLytEPNS0_8ResourceEPNS0_11FileContextEPKcP10MemAlcBasejPNS0_11ResCacheArgE
118005d0: ldr      pc, [pc, #-4]
118005d4: eoreq    sb, r4, r8, asr #28

<->Backup>  # veneer->_ZN6BackupC1Ev
118005d8: ldr      pc, [pc, #-4]
118005dc: andseq   r0, r1, r4, ror #24

<->ad::ctrl::ButtonGroup>  # veneer->_ZN2ad4ctrl11ButtonGroupC1Ev
118005e0: ldr      pc, [pc, #-4]
118005e4: ldrsbeq  r6, [r6], -r8

<->ad::font::ResFont>  # veneer->_ZN2ad4font7ResFontC1Ev
118005e8: ldr      pc, [pc, #-4]
118005ec: eoreq    r5, r7, ip, lsr #8

<->ad::fw::Resource>  # veneer->_ZN2ad2fw8ResourceC1Ev
118005f0: ldr      pc, [pc, #-4]
118005f4: eoreq    r0, r5, r8, lsl #11

<->msys::MCursorBase>  # veneer->_ZN4msys11MCursorBaseC1Ev
118005f8: ldr      pc, [pc, #-4]
118005fc: eorseq   r4, r2, r0, asr r5

<->MessageSimple>  # veneer->_ZN13MessageSimpleC1Ev
11800600: ldr      pc, [pc, #-4]
11800604: eoreq    ip, r7, ip, ror #29

<->msys::MLytNum>  # veneer->_ZN4msys7MLytNumC1Ev
11800608: ldr      pc, [pc, #-4]
1180060c: eorseq   r1, r3, r4, lsr #15

<->msys::MDfxChr>  # veneer->_ZN4msys7MDfxChrC1Ev
11800610: ldr      pc, [pc, #-4]
11800614: eorseq   r1, r3, ip, ror r3

<->Message>  # veneer->_ZN7MessageC1Ev
11800618: ldr      pc, [pc, #-4]
1180061c: andseq   r0, r1, ip, asr sp

<->msys::MListWndPBase>  # veneer->_ZN4msys13MListWndPBaseC1EPNS_13MListWndPCoreE
11800620: ldr      pc, [pc, #-4]
11800624: eorseq   r8, r2, r0, lsl #16

<->ad::ui::UIListWindowPlusLyt>  # veneer->_ZN2ad2ui19UIListWindowPlusLytC1Ev
11800628: ldr      pc, [pc, #-4]
1180062c: andseq   r6, r4, r4, lsl #19

<->ad::lyt::Layout>  # veneer->_ZN2ad3lyt6LayoutC1Ev
11800630: ldr      pc, [pc, #-4]
11800634: eoreq    r4, r6, ip, asr #25

<->msys::MCursorBase::term>  # veneer->_ZN4msys11MCursorBase4termEv
11800638: ldr      pc, [pc, #-4]
1180063c: ldrshteq r4, [r2], -r0

<->ad::ctrl::ButtonGroup::FreeAll>  # veneer->_ZN2ad4ctrl11ButtonGroup7FreeAllEv
11800640: ldr      pc, [pc, #-4]
11800644: .word    0x002509d0

<->ad::lyt::LytResourceMan::term>  # veneer->_ZN2ad3lyt14LytResourceMan4termEv
11800648: ldr      pc, [pc, #-4]
1180064c: eoreq    r0, r5, r8, lsr sb

<->msys::MLytNum>  # veneer->_ZN4msys7MLytNumD1Ev
11800650: ldr      pc, [pc, #-4]
11800654: eorseq   r1, r3, r0, asr #16

<->MessageSimple::term>  # veneer->_ZN13MessageSimple4termEv
11800658: ldr      pc, [pc, #-4]
1180065c: mulseq   r3, r0, r0

<->MessageSimple>  # veneer->_ZN13MessageSimpleD1Ev
11800660: ldr      pc, [pc, #-4]
11800664: eoreq    r6, r5, r8, ror r5

<->msys::MDfxChr>  # veneer->_ZN4msys7MDfxChrD1Ev
11800668: ldr      pc, [pc, #-4]
1180066c: eorseq   r1, r3, ip, asr #7

<->msys::MCursorBase>  # veneer->_ZN4msys11MCursorBaseD1Ev
11800670: ldr      pc, [pc, #-4]
11800674: eorseq   r4, r2, r0, lsl #12

<->ad::font::ResFont>  # veneer->_ZN2ad4font7ResFontD1Ev
11800678: ldr      pc, [pc, #-4]
1180067c: eoreq    r0, r5, r8, lsr #17

<->ad::ctrl::ButtonGroup>  # veneer->_ZN2ad4ctrl11ButtonGroupD1Ev
11800680: ldr      pc, [pc, #-4]
11800684: eoreq    r0, r5, r8, lsr #18

<->Backup>  # veneer->_ZN6BackupD1Ev
11800688: ldr      pc, [pc, #-4]
1180068c: eorseq   sb, r3, r4, lsr pc

<->msys::MPageBase::updateInputAllChr>  # veneer->_ZN4msys9MPageBase17updateInputAllChrEPNS_6MInputE
11800690: ldr      pc, [pc, #-4]
11800694: eorseq   r4, r3, r4, lsl #4

<->ad::ctrl::ButtonGroup::Update>  # veneer->_ZN2ad4ctrl11ButtonGroup6UpdateEPKN2nn4math4VEC2Ebb
11800698: ldr      pc, [pc, #-4]
1180069c: eoreq    r0, r5, r0, asr #20

<->msys::MTaskBase>  # veneer->_ZN4msys9MTaskBaseC1Ev
118006a0: ldr      pc, [pc, #-4]
118006a4: eorseq   r4, r3, r8, lsl #13

<->ad::fw::TaskBase>  # veneer->_ZN2ad2fw8TaskBaseD1Ev
118006a8: ldr      pc, [pc, #-4]
118006ac: mlaeq    r6, r0, r5, sp

<->msys::MCamera::getProjMtx>  # veneer->_ZNK4msys7MCamera10getProjMtxERN2nn4math5MTX44Ej
118006b0: ldr      pc, [pc, #-4]
118006b4: eoreq    r6, r0, r8, lsl r7

<->msys::MCamera::getViewMtx>  # veneer->_ZNK4msys7MCamera10getViewMtxERN2nn4math5MTX34E
118006b8: ldr      pc, [pc, #-4]
118006bc: eoreq    r6, r0, r4, ror #17

<->ad::fw::TaskBase::setULcdCameraInfoBase>  # veneer->_ZN2ad2fw8TaskBase21setULcdCameraInfoBaseERKN2nn4math5MTX34ERKNS3_5MTX44ENS3_14PivotDirectionE
118006c0: ldr      pc, [pc, #-4]
118006c4: andseq   fp, r0, r8, lsr r4

<->Grp::SetupProjLcdOrtho>  # veneer->_ZN3Grp17SetupProjLcdOrthoEPN2nn4math5MTX44Ejbbff
118006c8: ldr      pc, [pc, #-4]
118006cc: eoreq    r4, r8, r0, asr #31

<->msys::MComSys::funcCalcMainNomal>  # veneer->_ZN4msys7MComSys17funcCalcMainNomalEv
118006d0: ldr      pc, [pc, #-4]
118006d4: eorseq   pc, r2, ip, lsr r1

<->msys::MComSys::funcDrawLower>  # veneer->_ZN4msys7MComSys13funcDrawLowerEP7CmdList
118006d8: ldr      pc, [pc, #-4]
118006dc: ldrhteq  lr, [r2], -r8

<->msys::MCamera::update>  # veneer->_ZN4msys7MCamera6updateEj
118006e0: ldr      pc, [pc, #-4]
118006e4: mlaseq   r2, r0, sb, sp

<->ad::math::FastInverse>  # veneer->_ZN2ad4math11FastInverseEPN2nn4math5MTX34ERKS3_
118006e8: ldr      pc, [pc, #-4]
118006ec: mlaeq    r7, ip, r4, r2

<->CellAnimeState::setProj2dParallax>  # veneer->_ZN14CellAnimeState17setProj2dParallaxERKN2nn4math5MTX44E
118006f0: ldr      pc, [pc, #-4]
118006f4: eoreq    r0, r3, ip, asr sl

<->ad::math::CalcFar>  # veneer->_ZN2ad4math7CalcFarERKN2nn4math5MTX44E
118006f8: ldr      pc, [pc, #-4]
118006fc: eoreq    r5, r6, r8, asr sp

<->ad::math::CalcNear>  # veneer->_ZN2ad4math8CalcNearERKN2nn4math5MTX44E
11800700: ldr      pc, [pc, #-4]
11800704: eoreq    r5, r6, r8, ror sp

<->ad::math::WorldFrustum>  # veneer->_ZN2ad4math12WorldFrustumC1ERKN2nn4math5MTX34ERKNS3_5MTX44Eff
11800708: ldr      pc, [pc, #-4]
1180070c: eoreq    sp, r3, ip, lsr #13

<->Prim::setProj2dParallax>  # veneer->_ZN4Prim17setProj2dParallaxERKN2nn4math5MTX44E
11800710: ldr      pc, [pc, #-4]
11800714: eoreq    r6, r0, r8, ror #13

<->ad::lyt::DrawInfo::SetProjectionMtx>  # veneer->_ZN2ad3lyt8DrawInfo16SetProjectionMtxERKN2nn4math5MTX44E
11800718: ldr      pc, [pc, #-4]
1180071c: eoreq    r5, r6, ip, lsl #2

<->Grp::GetLcdWidth>  # veneer->_ZN3Grp11GetLcdWidthEj
11800720: ldr      pc, [pc, #-4]
11800724: eoreq    r1, r7, r8, lsl #28

<->Grp::GetLcdHeight>  # veneer->_ZN3Grp12GetLcdHeightEj
11800728: ldr      pc, [pc, #-4]
1180072c: eoreq    r1, r7, r4, ror #27

<->Prim::setProjMtx>  # veneer->_ZN4Prim10setProjMtxERKN2nn4math5MTX44E
11800730: ldr      pc, [pc, #-4]
11800734: eorseq   r3, r2, r4, lsl #17

<->ad::fw::DfxSys::setViewMtx>  # veneer->_ZN2ad2fw6DfxSys10setViewMtxERKN2nn4math5MTX34Eh
11800738: ldr      pc, [pc, #-4]
1180073c: eoreq    ip, r4, ip, lsl #22

<->ad::dfx::Engine::setViewMtx>  # veneer->_ZN2ad3dfx6Engine10setViewMtxERKN2nn4math5MTX34E
11800740: ldr      pc, [pc, #-4]
11800744: eoreq    ip, r4, ip, asr #19

<->msys::MComSys::getNextPage>  # veneer->_ZN4msys7MComSys11getNextPageEv
11800748: ldr      pc, [pc, #-4]
1180074c: eorseq   sp, r2, r4, ror #22

<->ad::SimpleRectDrawer::draw>  # veneer->_ZNK2ad16SimpleRectDrawer4drawEP11CmdListBaseN2nn4util6Color8EN4Prim12eBlendPresetE
11800750: ldr      pc, [pc, #-4]
11800754: eoreq    sp, r4, r0, lsr r3

<->msys::MComSys::readLytNum>  # veneer->_ZN4msys7MComSys10readLytNumEPN2ad2fw11FileContextEP10MemAlcBase
11800758: ldr      pc, [pc, #-4]
1180075c: eorseq   sp, r2, r4, lsl fp

<->_ZnajP10MemAlcBasePKcj>  # veneer->_ZnajP10MemAlcBasePKcj
11800760: ldr      pc, [pc, #-4]
11800764: eoreq    r3, r8, r8, asr r5

<->MessageSys::GetPath>  # veneer->_ZN10MessageSys7GetPathEPwPKwb
11800768: ldr      pc, [pc, #-4]
1180076c: andseq   r2, r3, ip, lsr #20

<->nn::fs::CTR::MPCore::detail::UserFileSystem::TryOpenFile>  # veneer->_ZN2nn2fs3CTR6MPCore6detail14UserFileSystem11TryOpenFileEPPvPKwj
11800770: ldr      pc, [pc, #-4]
11800774: eoreq    r5, r8, ip, lsl #19

<->nn::fs::detail::FileBase::TryGetSize>  # veneer->_ZNK2nn2fs6detail8FileBase10TryGetSizeEPx
11800778: ldr      pc, [pc, #-4]
1180077c: eoreq    r6, r8, r8, ror #10

<->MsgDataAcsrBase::init>  # veneer->_ZN15MsgDataAcsrBase4initEPKv
11800780: ldr      pc, [pc, #-4]
11800784: eoreq    r5, r8, r8, lsl #23

<->_ZdaPv>  # veneer->_ZdaPv
11800788: ldr      pc, [pc, #-4]
1180078c: mlaeq    r8, ip, r2, r8

<->msys::MLytNumRes::init>  # veneer->_ZN4msys10MLytNumRes4initERN2ad3lyt14LytResourceManEj
11800790: ldr      pc, [pc, #-4]
11800794: ldrshteq r4, [r2], -r4

<->msys::MComSys::initBaseSys>  # veneer->_ZN4msys7MComSys11initBaseSysEPNS_9MTaskBaseEjjjjjjhb
11800798: ldr      pc, [pc, #-4]
1180079c: eorseq   sp, r2, r4, lsl #23

<->msys::MComSys::entryPage>  # veneer->_ZN4msys7MComSys9entryPageEPNS_9MPageBaseE
118007a0: ldr      pc, [pc, #-4]
118007a4: eorseq   pc, r2, r8, asr #10

<->Prim::enableDepthTest>  # veneer->_ZN4Prim15enableDepthTestEb17PicaDataDepthTest
118007a8: ldr      pc, [pc, #-4]
118007ac: eoreq    ip, r6, r8, ror #25

<->CtrJobMan::enqueue>  # veneer->_ZN9CtrJobMan7enqueueEP3Job
118007b0: ldr      pc, [pc, #-4]
118007b4: eoreq    sp, r6, r8, ror #23

<->msys::MComSys::setupCamU>  # veneer->_ZN4msys7MComSys9setupCamUEv
118007b8: ldr      pc, [pc, #-4]
118007bc: eorseq   pc, r2, r4, ror r6

<->msys::MComSys::setupCamL>  # veneer->_ZN4msys7MComSys9setupCamLEv
118007c0: ldr      pc, [pc, #-4]
118007c4: eorseq   pc, r2, r0, ror r5

<->msys::MComSys>  # veneer->_ZN4msys7MComSysC1Ev
118007c8: ldr      pc, [pc, #-4]
118007cc: eorseq   pc, r2, r4, lsr #15

<->MsgDataAcsrBase>  # veneer->_ZN15MsgDataAcsrBaseC1EP12LMSBlockInfoj
118007d0: ldr      pc, [pc, #-4]
118007d4: .word    0x0024b3b8

<->CellAnime>  # veneer->_ZN9CellAnimeC1Ev
118007d8: ldr      pc, [pc, #-4]
118007dc: eoreq    fp, r6, r8, lsl lr

<->CellAnime>  # veneer->_ZN9CellAnimeD1Ev
118007e0: ldr      pc, [pc, #-4]
118007e4: mlaeq    r4, r4, ip, pc

<->MoveVBase::update>  # veneer->_ZN9MoveVBase6updateEf
118007e8: ldr      pc, [pc, #-4]
118007ec: .word    0x002597d4

<->CtrBtn::get>  # veneer->_ZNK6CtrBtn3getEi
118007f0: ldr      pc, [pc, #-4]
118007f4: ldrshteq r2, [r6], -r0

<->Message::func>  # veneer->_ZN7Message4funcEjjjbf
118007f8: ldr      pc, [pc, #-4]
118007fc: eoreq    r3, r7, r0, ror #23

<->msys::MRenderQueueBase::enqueueMsg>  # veneer->_ZN4msys16MRenderQueueBase10enqueueMsgEP13MessageSimplejh
11800800: ldr      pc, [pc, #-4]
11800804: ldrshteq r8, [r2], -r0

<->msys::MPageBase::enqueueLowerChr>  # veneer->_ZN4msys9MPageBase15enqueueLowerChrEPNS_12MRenderQueueE
11800808: ldr      pc, [pc, #-4]
1180080c: eorseq   r4, r3, r4, lsl #2

<->msys::MPageBase::enqueueUpperChr>  # veneer->_ZN4msys9MPageBase15enqueueUpperChrEPNS_12MRenderQueueE
11800810: ldr      pc, [pc, #-4]
11800814: eorseq   r4, r3, r4, lsl #3

<->MoveWorkF>  # veneer->_ZN9MoveWorkFC1Ev
11800818: ldr      pc, [pc, #-4]
1180081c: eoreq    r8, r7, r0, asr #25

<->MoveWorkF>  # veneer->_ZN9MoveWorkFD1Ev
11800820: ldr      pc, [pc, #-4]
11800824: mlaseq   r4, r4, r6, r0

<->ad::fw::FileContext::initSingleFile>  # veneer->_ZN2ad2fw11FileContext14initSingleFileEPKwb
11800828: ldr      pc, [pc, #-4]
1180082c: andseq   sl, r3, r4, asr sp

<->ad::fw::FileContext::initArcFile>  # veneer->_ZN2ad2fw11FileContext11initArcFileEPKwP10MemAlcBaseb
11800830: ldr      pc, [pc, #-4]
11800834: andseq   sl, r3, r8, lsr #25

<->ad::fw::FileContext::initCAArcFile>  # veneer->_ZN2ad2fw11FileContext13initCAArcFileEPKwP10MemAlcBaseRNS0_15DataAndSizeTmplIPvEEb
11800838: ldr      pc, [pc, #-4]
1180083c: andseq   sl, r3, r0, asr #25

<->msys::MCursorBase::init>  # veneer->_ZN4msys11MCursorBase4initEPNS_4MLytEf
11800840: ldr      pc, [pc, #-4]
11800844: eorseq   r4, r2, r4, ror #8

<Colosseum:EntryTask>  # Colosseum:EntryTask
11800848: ldr      r0, [pc, #0x2c]  ; =0x3f638c gMemAlc
1180084c: push     {r4, lr}
11800850: mov      r3, #0
11800854: mov      r2, r3
11800858: ldr      r1, [r0]
1180085c: ldr      r0, [pc, #0x1c]  ; =0xe9a50
11800860: bl       #0x11800180  ; ->_ZnwjP10MemAlcBasePKcj
11800864: cmp      r0, #0
11800868: blne     #0x1180a01c
1180086c: mov      r1, r0
11800870: ldr      r0, [pc, #0xc]  ; =0x3f4130 gTaskMainMan
11800874: pop      {r4, lr}
11800878: b        #0x11800188  ; ->TaskMan::entry
1180087c: eorseq   r6, pc, ip, lsl #7
11800880: andeq    sb, lr, r0, asr sl
11800884: eorseq   r4, pc, r0, lsr r1
11800888: push     {r4, r5, r6, r7, r8, sb, sl, fp, lr}
1180088c: add      r5, r0, #4
11800890: mov      r8, r0
11800894: mov      r4, #0
11800898: mov      r3, r4
1180089c: ldr      r0, [r0, #0x18]
118008a0: ldr      r1, [r8, #0x14]
118008a4: ldr      r7, [pc, #0x82c]  ; =0x92492493
118008a8: sub      sp, sp, #0x1c
118008ac: sub      r2, r0, r1
118008b0: smlal    r3, r2, r7, r2
118008b4: asr      r3, r2, #4
118008b8: sub      r2, r3, r2, asr #31
118008bc: add      r6, r2, #1
118008c0: ldr      r2, [r5, #0x18]
118008c4: cmp      r6, r2
118008c8: bhi      #0x11800914
118008cc: rsb      r2, r6, r6, lsl #3
118008d0: add      r1, r1, r2, lsl #2
118008d4: cmp      r1, r0
118008d8: bls      #0x118008f8
118008dc: bhi      #0x1180090c
118008e0: cmp      r0, r1
118008e4: beq      #0x1180090c
118008e8: add      r0, r0, #0x1c
118008ec: cmp      r0, r1
118008f0: bne      #0x118008e8
118008f4: b        #0x1180090c
118008f8: cmp      r0, r1
118008fc: bhs      #0x1180090c
11800900: sub      r0, r0, #0x1c
11800904: cmp      r1, r0
11800908: bne      #0x11800900
1180090c: str      r1, [r5, #0x14]
11800910: b        #0x11800e04
11800914: ldm      r5, {r0, r1, r2}
11800918: movs     fp, r6
1180091c: stm      sp, {r0, r1, r2}
11800920: add      r1, sp, #0xc
11800924: mov      r0, #0
11800928: stm      r1, {r0, r4}
1180092c: str      r4, [sp, #0x14]
11800930: str      r4, [sp, #0x18]
11800934: ldr      r0, [r5, #0x18]
11800938: beq      #0x11800b08
1180093c: ldr      sl, [pc, #0x798]  ; =0x49249249
11800940: lsl      r0, r0, #1
11800944: cmp      fp, r0
11800948: bhs      #0x11800a30
1180094c: ldr      r1, [sp]
11800950: cmp      r1, #0
11800954: beq      #0x11800a28
11800958: rsb      r0, r0, r0, lsl #3
1180095c: mov      r3, r2
11800960: lsl      sb, r0, #2
11800964: ldr      r2, [sp, #4]
11800968: mov      r0, sb
1180096c: bl       #0x11800180  ; ->_ZnwjP10MemAlcBasePKcj
11800970: movs     r1, r0
11800974: nop      
11800978: beq      #0x11800a30
1180097c: ldr      fp, [sp, #0x10]
11800980: ldr      ip, [sp, #0x14]
11800984: mov      r2, r4
11800988: mov      lr, sl
1180098c: sub      ip, ip, fp
11800990: mov      r3, #0
11800994: umlal    lr, r3, sb, sl
11800998: smlal    r2, ip, r7, ip
1180099c: lsr      r2, r3, #3
118009a0: asr      lr, ip, #4
118009a4: sub      r3, lr, ip, asr #31
118009a8: cmp      r3, r2
118009ac: bhi      #0x11800a14
118009b0: ldr      ip, [sp, #0x14]
118009b4: str      r2, [sp, #0x18]
118009b8: mov      r3, r1
118009bc: cmp      fp, ip
118009c0: mov      r2, fp
118009c4: beq      #0x118009ec
118009c8: cmp      r0, #0
118009cc: beq      #0x118009dc
118009d0: vldmia   r2, {s0, s1, s2, s3, s4, s5, s6}
118009d4: vstmia   r0, {s0, s1, s2, s3, s4, s5}
118009d8: vstr     s6, [r0, #0x18]
118009dc: add      r2, r2, #0x1c
118009e0: cmp      r2, ip
118009e4: add      r0, r0, #0x1c
118009e8: bne      #0x118009c8
118009ec: mov      ip, r0
118009f0: ldr      r0, [sp, #0x14]
118009f4: ldr      r2, [sp, #0x10]
118009f8: cmp      r2, r0
118009fc: bls      #0x11800a0c
11800a00: sub      r0, r0, #0x1c
11800a04: cmp      r2, r0
11800a08: bne      #0x11800a00
11800a0c: add      r0, sp, #0x10
11800a10: stm      r0, {r3, ip}
11800a14: ldr      r0, [sp, #0xc]
11800a18: str      r1, [sp, #0xc]
11800a1c: cmp      r0, #0
11800a20: beq      #0x11800b08
11800a24: b        #0x11800b00
11800a28: cmp      r0, #0
11800a2c: beq      #0x11800b08
11800a30: ldr      r0, [sp]
11800a34: cmp      r0, #0
11800a38: beq      #0x11800b88
11800a3c: rsb      r0, fp, fp, lsl #3
11800a40: ldm      sp, {r1, r2, r3}
11800a44: lsl      sb, r0, #2
11800a48: mov      r0, sb
11800a4c: bl       #0x11800180  ; ->_ZnwjP10MemAlcBasePKcj
11800a50: movs     r1, r0
11800a54: nop      
11800a58: beq      #0x11800b88
11800a5c: ldr      fp, [sp, #0x10]
11800a60: ldr      lr, [sp, #0x14]
11800a64: ldr      ip, [pc, #0x670]  ; =0x49249249
11800a68: mov      r2, r4
11800a6c: sub      lr, lr, fp
11800a70: mov      r3, #0
11800a74: umlal    ip, r3, sb, sl
11800a78: smlal    r2, lr, r7, lr
11800a7c: lsr      r2, r3, #3
11800a80: asr      ip, lr, #4
11800a84: sub      r3, ip, lr, asr #31
11800a88: cmp      r3, r2
11800a8c: bhi      #0x11800af0
11800a90: ldr      lr, [sp, #0x14]
11800a94: mov      ip, r1
11800a98: mov      r3, fp
11800a9c: cmp      fp, lr
11800aa0: str      r2, [sp, #0x18]
11800aa4: beq      #0x11800acc
11800aa8: movs     r2, r0
11800aac: beq      #0x11800abc
11800ab0: vldmia   r3, {s0, s1, s2, s3, s4, s5, s6}
11800ab4: vstmia   r2, {s0, s1, s2, s3, s4, s5}
11800ab8: vstr     s6, [r0, #0x18]
11800abc: add      r3, r3, #0x1c
11800ac0: cmp      r3, lr
11800ac4: add      r0, r2, #0x1c
11800ac8: bne      #0x11800aa8
11800acc: ldr      r2, [sp, #0x14]
11800ad0: ldr      r3, [sp, #0x10]
11800ad4: cmp      r3, r2
11800ad8: bls      #0x11800ae8
11800adc: sub      r2, r2, #0x1c
11800ae0: cmp      r3, r2
11800ae4: bne      #0x11800adc
11800ae8: str      r0, [sp, #0x14]
11800aec: str      ip, [sp, #0x10]
11800af0: ldr      r0, [sp, #0xc]
11800af4: str      r1, [sp, #0xc]
11800af8: cmp      r0, #0
11800afc: beq      #0x11800b08
11800b00: nop      
11800b04: bl       #0x11800190  ; ->_ZdlPv
11800b08: add      r0, r5, #0x10
11800b0c: mov      ip, r4
11800b10: ldm      r0, {r0, lr}
11800b14: mov      r2, r4
11800b18: sub      r3, lr, r0
11800b1c: mov      r1, r3
11800b20: smlal    ip, r3, r7, r1
11800b24: asr      ip, r3, #4
11800b28: sub      r3, ip, r3, asr #31
11800b2c: cmp      r3, r6
11800b30: mov      ip, sp
11800b34: bhs      #0x11800ca0
11800b38: mov      sb, r2
11800b3c: smlal    sb, r1, r7, r1
11800b40: add      r3, ip, #0x10
11800b44: asr      r7, r1, #4
11800b48: sub      r1, r7, r1, asr #31
11800b4c: ldr      r7, [sp, #0x18]
11800b50: cmp      r7, r1
11800b54: blo      #0x11800c40
11800b58: cmp      r0, lr
11800b5c: bne      #0x11800bf0
11800b60: ldr      r0, [sp, #0x14]
11800b64: ldr      r1, [sp, #0x10]
11800b68: cmp      r1, r0
11800b6c: bls      #0x11800b7c
11800b70: sub      r0, r0, #0x1c
11800b74: cmp      r1, r0
11800b78: bne      #0x11800b70
11800b7c: ldr      r0, [r3]
11800b80: str      r0, [r3, #4]
11800b84: b        #0x11800c40
11800b88: ldr      r0, [sp, #0x14]
11800b8c: ldr      r1, [sp, #0x10]
11800b90: mov      r5, sp
11800b94: str      r4, [sp, #0x18]
11800b98: cmp      r1, r0
11800b9c: bls      #0x11800bac
11800ba0: sub      r0, r0, #0x1c
11800ba4: cmp      r1, r0
11800ba8: bne      #0x11800ba0
11800bac: ldr      r0, [sp, #0xc]
11800bb0: str      r4, [sp, #0x10]
11800bb4: str      r4, [sp, #0x14]
11800bb8: cmp      r0, #0
11800bbc: str      r4, [sp, #0xc]
11800bc0: blne     #0x11800190  ; ->_ZdlPv
11800bc4: ldr      r1, [r5, #0x10]!
11800bc8: ldr      r0, [r5, #4]
11800bcc: cmp      r1, r0
11800bd0: bls      #0x11800be0
11800bd4: sub      r0, r0, #0x1c
11800bd8: cmp      r1, r0
11800bdc: bne      #0x11800bd4
11800be0: ldr      r0, [r5, #-4]
11800be4: cmp      r0, #0
11800be8: beq      #0x11800e04
11800bec: b        #0x11800dfc
11800bf0: ldr      r1, [sp, #0x14]
11800bf4: ldr      r7, [sp, #0x10]
11800bf8: cmp      r7, r1
11800bfc: bls      #0x11800c0c
11800c00: sub      r1, r1, #0x1c
11800c04: cmp      r7, r1
11800c08: bne      #0x11800c00
11800c0c: ldr      r1, [r3]
11800c10: cmp      r0, lr
11800c14: beq      #0x11800c3c
11800c18: cmp      r1, #0
11800c1c: beq      #0x11800c2c
11800c20: vldmia   r0, {s0, s1, s2, s3, s4, s5, s6}
11800c24: vstmia   r1, {s0, s1, s2, s3, s4, s5}
11800c28: vstr     s6, [r1, #0x18]
11800c2c: add      r0, r0, #0x1c
11800c30: cmp      r0, lr
11800c34: add      r1, r1, #0x1c
11800c38: bne      #0x11800c18
11800c3c: str      r1, [r3, #4]
11800c40: ldr      r0, [sp, #0x18]
11800c44: cmp      r0, r6
11800c48: blo      #0x11800d4c
11800c4c: ldr      r1, [sp, #0x10]
11800c50: ldr      r0, [sp, #0x14]
11800c54: rsb      ip, r6, r6, lsl #3
11800c58: add      ip, r1, ip, lsl #2
11800c5c: cmp      r0, ip
11800c60: mov      r1, r0
11800c64: mov      r0, ip
11800c68: bhs      #0x11800c84
11800c6c: cmp      r1, r0
11800c70: bls      #0x11800c98
11800c74: add      r1, r1, #0x1c
11800c78: cmp      r1, r0
11800c7c: bne      #0x11800c74
11800c80: b        #0x11800c98
11800c84: cmp      r0, r1
11800c88: bls      #0x11800c98
11800c8c: sub      r1, r1, #0x1c
11800c90: cmp      r0, r1
11800c94: bne      #0x11800c8c
11800c98: str      r0, [r3, #4]
11800c9c: b        #0x11800d4c
11800ca0: rsb      r1, r6, r6, lsl #3
11800ca4: mov      lr, r2
11800ca8: add      r3, r0, r1, lsl #2
11800cac: sub      r1, r3, r0
11800cb0: add      ip, ip, #0x10
11800cb4: smlal    lr, r1, r7, r1
11800cb8: asr      lr, r1, #4
11800cbc: sub      r1, lr, r1, asr #31
11800cc0: ldr      lr, [sp, #0x18]
11800cc4: cmp      lr, r1
11800cc8: blo      #0x11800d4c
11800ccc: cmp      r0, r3
11800cd0: bne      #0x11800cfc
11800cd4: ldr      r0, [sp, #0x14]
11800cd8: ldr      r1, [sp, #0x10]
11800cdc: cmp      r1, r0
11800ce0: bls      #0x11800cf0
11800ce4: sub      r0, r0, #0x1c
11800ce8: cmp      r1, r0
11800cec: bne      #0x11800ce4
11800cf0: ldr      r0, [ip]
11800cf4: str      r0, [ip, #4]
11800cf8: b        #0x11800d4c
11800cfc: ldr      r1, [sp, #0x14]
11800d00: ldr      lr, [sp, #0x10]
11800d04: cmp      lr, r1
11800d08: bls      #0x11800d18
11800d0c: sub      r1, r1, #0x1c
11800d10: cmp      lr, r1
11800d14: bne      #0x11800d0c
11800d18: ldr      r1, [ip]
11800d1c: cmp      r0, r3
11800d20: beq      #0x11800d48
11800d24: cmp      r1, #0
11800d28: beq      #0x11800d38
11800d2c: vldmia   r0, {s0, s1, s2, s3, s4, s5, s6}
11800d30: vstmia   r1, {s0, s1, s2, s3, s4, s5}
11800d34: vstr     s6, [r1, #0x18]
11800d38: add      r0, r0, #0x1c
11800d3c: cmp      r0, r3
11800d40: add      r1, r1, #0x1c
11800d44: bne      #0x11800d24
11800d48: str      r1, [ip, #4]
11800d4c: ldm      r5, {r6, ip, lr}
11800d50: ldm      sp, {r0, r1, r3}
11800d54: stm      sp, {r6, ip, lr}
11800d58: stm      r5, {r0, r1, r3}
11800d5c: ldr      r1, [r5, #0xc]
11800d60: ldr      r0, [sp, #0xc]
11800d64: str      r1, [sp, #0xc]
11800d68: str      r0, [r5, #0xc]
11800d6c: ldr      r1, [r5, #0x10]
11800d70: ldr      r0, [sp, #0x10]
11800d74: str      r1, [sp, #0x10]
11800d78: str      r0, [r5, #0x10]
11800d7c: ldr      r1, [r5, #0x14]
11800d80: ldr      r0, [sp, #0x14]
11800d84: str      r1, [sp, #0x14]
11800d88: str      r0, [r5, #0x14]
11800d8c: ldr      r0, [sp, #0x18]
11800d90: ldr      r1, [r5, #0x18]
11800d94: str      r0, [r5, #0x18]
11800d98: ldr      r0, [sp, #0x14]
11800d9c: ldr      r1, [sp, #0x10]
11800da0: mov      r5, sp
11800da4: str      r2, [sp, #0x18]
11800da8: cmp      r1, r0
11800dac: bls      #0x11800dbc
11800db0: sub      r0, r0, #0x1c
11800db4: cmp      r1, r0
11800db8: bne      #0x11800db0
11800dbc: ldr      r0, [sp, #0xc]
11800dc0: str      r2, [sp, #0x10]
11800dc4: str      r2, [sp, #0x14]
11800dc8: cmp      r0, #0
11800dcc: str      r2, [sp, #0xc]
11800dd0: blne     #0x11800190  ; ->_ZdlPv
11800dd4: ldr      r1, [r5, #0x10]!
11800dd8: ldr      r0, [r5, #4]
11800ddc: cmp      r1, r0
11800de0: bls      #0x11800df0
11800de4: sub      r0, r0, #0x1c
11800de8: cmp      r1, r0
11800dec: bne      #0x11800de4
11800df0: ldr      r0, [r5, #-4]
11800df4: cmp      r0, #0
11800df8: beq      #0x11800e04
11800dfc: nop      
11800e00: bl       #0x11800190  ; ->_ZdlPv
11800e04: ldr      r0, [r8, #0x18]
11800e08: add      r5, r8, #0x20
11800e0c: ldr      r2, [r8, #0x30]
11800e10: sub      r6, r0, #0x1c
11800e14: ldrd     r0, r1, [r5, #0x14]
11800e18: mov      r7, #1
11800e1c: sub      r2, r0, r2
11800e20: add      r8, r7, r2, asr #2
11800e24: cmp      r8, r1
11800e28: bls      #0x11800eec
11800e2c: ldm      r5, {r0, r1, r2}
11800e30: cmp      r8, #0
11800e34: stm      sp, {r0, r1, r2, r4}
11800e38: str      r4, [sp, #0x10]
11800e3c: str      r4, [sp, #0x14]
11800e40: str      r4, [sp, #0x18]
11800e44: ldr      r0, [r5, #0x18]
11800e48: bls      #0x11800fa0
11800e4c: lsl      r0, r0, #1
11800e50: cmp      r0, r8
11800e54: bls      #0x11800f0c
11800e58: ldr      r1, [sp]
11800e5c: cmp      r1, #0
11800e60: beq      #0x11800f04
11800e64: lsl      sb, r0, #2
11800e68: mov      r3, r2
11800e6c: ldr      r2, [sp, #4]
11800e70: mov      r0, sb
11800e74: bl       #0x11800180  ; ->_ZnwjP10MemAlcBasePKcj
11800e78: movs     r3, r0
11800e7c: nop      
11800e80: beq      #0x11800f0c
11800e84: ldr      r2, [sp, #0x14]
11800e88: ldr      ip, [sp, #0x10]
11800e8c: lsr      r1, sb, #2
11800e90: sub      r2, r2, ip
11800e94: cmp      r1, r2, asr #2
11800e98: blo      #0x11800ed8
11800e9c: str      r1, [sp, #0x18]
11800ea0: mov      r1, ip
11800ea4: ldr      ip, [sp, #0x14]
11800ea8: mov      r2, r3
11800eac: cmp      r1, ip
11800eb0: beq      #0x11800ed0
11800eb4: cmp      r0, #0
11800eb8: ldrne    r8, [r1]
11800ebc: add      r1, r1, #4
11800ec0: strne    r8, [r0]
11800ec4: cmp      r1, ip
11800ec8: add      r0, r0, #4
11800ecc: bne      #0x11800eb4
11800ed0: str      r0, [sp, #0x14]
11800ed4: str      r2, [sp, #0x10]
11800ed8: ldr      r0, [sp, #0xc]
11800edc: str      r3, [sp, #0xc]
11800ee0: cmp      r0, #0
11800ee4: beq      #0x11800fa0
11800ee8: b        #0x11800f98
11800eec: cmp      r0, #0
11800ef0: strne    r6, [r0]
11800ef4: ldr      r0, [r5, #0x14]
11800ef8: add      r0, r0, #4
11800efc: str      r0, [r5, #0x14]
11800f00: b        #0x118010a0
11800f04: cmp      r0, #0
11800f08: beq      #0x11800fa0
11800f0c: ldr      r0, [sp]
11800f10: cmp      r0, #0
11800f14: beq      #0x118010ac
11800f18: lsl      r8, r8, #2
11800f1c: mov      r1, r0
11800f20: mov      r0, r8
11800f24: ldrd     r2, r3, [sp, #4]
11800f28: bl       #0x11800180  ; ->_ZnwjP10MemAlcBasePKcj
11800f2c: movs     r1, r0
11800f30: nop      
11800f34: beq      #0x118010ac
11800f38: ldr      r3, [sp, #0x14]
11800f3c: ldr      ip, [sp, #0x10]
11800f40: lsr      r2, r8, #2
11800f44: sub      r3, r3, ip
11800f48: cmp      r2, r3, asr #2
11800f4c: blo      #0x11800f88
11800f50: str      r2, [sp, #0x18]
11800f54: ldrd     r2, r3, [sp, #0x10]
11800f58: mov      ip, r1
11800f5c: cmp      r2, r3
11800f60: beq      #0x11800f80
11800f64: cmp      r0, #0
11800f68: ldrne    r8, [r2]
11800f6c: add      r2, r2, #4
11800f70: strne    r8, [r0]
11800f74: cmp      r2, r3
11800f78: add      r0, r0, #4
11800f7c: bne      #0x11800f64
11800f80: str      r0, [sp, #0x14]
11800f84: str      ip, [sp, #0x10]
11800f88: ldr      r0, [sp, #0xc]
11800f8c: str      r1, [sp, #0xc]
11800f90: cmp      r0, #0
11800f94: beq      #0x11800fa0
11800f98: nop      
11800f9c: bl       #0x11800190  ; ->_ZdlPv
11800fa0: ldrd     r0, r1, [r5, #0x10]
11800fa4: ldr      ip, [sp, #0x18]
11800fa8: add      r3, sp, #0x10
11800fac: sub      r2, r1, r0
11800fb0: asr      r2, r2, #2
11800fb4: cmp      ip, r2
11800fb8: blo      #0x11800ff0
11800fbc: cmp      r0, r1
11800fc0: ldreq    r0, [sp, #0x10]
11800fc4: ldrne    r2, [sp, #0x10]
11800fc8: streq    r0, [sp, #0x14]
11800fcc: beq      #0x11800ff0
11800fd0: cmp      r2, #0
11800fd4: ldrne    lr, [r0]
11800fd8: add      r0, r0, #4
11800fdc: strne    lr, [r2]
11800fe0: cmp      r0, r1
11800fe4: add      r2, r2, #4
11800fe8: bne      #0x11800fd0
11800fec: str      r2, [r3, #4]
11800ff0: ldr      r1, [sp, #0x14]
11800ff4: ldr      r2, [sp, #0x10]
11800ff8: ldr      r0, [sp, #0x18]
11800ffc: sub      r1, r1, r2
11801000: add      r1, r7, r1, asr #2
11801004: cmp      r1, r0
11801008: bhi      #0x11801024
1180100c: ldr      r0, [sp, #0x14]
11801010: cmp      r0, #0
11801014: strne    r6, [r0]
11801018: ldr      r0, [sp, #0x14]
1180101c: add      r0, r0, #4
11801020: str      r0, [sp, #0x14]
11801024: ldm      r5, {r3, ip, lr}
11801028: ldm      sp, {r0, r1, r2}
1180102c: stm      sp, {r3, ip, lr}
11801030: stm      r5, {r0, r1, r2}
11801034: ldr      r1, [r5, #0xc]
11801038: ldr      r0, [sp, #0xc]
1180103c: str      r1, [sp, #0xc]
11801040: str      r0, [r5, #0xc]
11801044: ldr      r1, [r5, #0x10]
11801048: ldr      r0, [sp, #0x10]
1180104c: str      r1, [sp, #0x10]
11801050: str      r0, [r5, #0x10]
11801054: ldr      r1, [r5, #0x14]
11801058: ldr      r0, [sp, #0x14]
1180105c: str      r1, [sp, #0x14]
11801060: str      r0, [r5, #0x14]
11801064: ldr      r0, [sp, #0x18]
11801068: ldr      r1, [r5, #0x18]
1180106c: str      r0, [r5, #0x18]
11801070: ldr      r0, [sp, #0xc]
11801074: str      r4, [sp, #0x18]
11801078: str      r4, [sp, #0x10]
1180107c: cmp      r0, #0
11801080: str      r4, [sp, #0x14]
11801084: str      r4, [sp, #0xc]
11801088: blne     #0x11800190  ; ->_ZdlPv
1180108c: ldr      r0, [sp, #0xc]
11801090: cmp      r0, #0
11801094: beq      #0x118010a0
11801098: nop      
1180109c: bl       #0x11800190  ; ->_ZdlPv
118010a0: add      sp, sp, #0x1c
118010a4: mov      r0, r6
118010a8: pop      {r4, r5, r6, r7, r8, sb, sl, fp, pc}
118010ac: ldr      r0, [sp, #0xc]
118010b0: str      r4, [sp, #0x18]
118010b4: str      r4, [sp, #0x10]
118010b8: cmp      r0, #0
118010bc: str      r4, [sp, #0x14]
118010c0: str      r4, [sp, #0xc]
118010c4: blne     #0x11800190  ; ->_ZdlPv
118010c8: ldr      r0, [sp, #0xc]
118010cc: cmp      r0, #0
118010d0: beq      #0x118010a0
118010d4: b        #0x11801098
118010d8: subls    r2, sb, #0x93000000
118010dc: stmdbmi  r4!, {r0, r3, r6, sb, ip, pc}
118010e0: push     {r4, lr}
118010e4: bl       #0x11800198  ; ->MsgDataAcsrBase
118010e8: pop      {r4, lr}
118010ec: b        #0x11800190  ; ->_ZdlPv
118010f0: b        #0x11800198  ; ->MsgDataAcsrBase
118010f4: ldr      r1, [r0]
118010f8: ldr      r1, [r1, #0x14]
118010fc: bx       r1
11801100: bx       lr
11801104: ldr      r0, [pc]
11801108: bx       lr
1180110c: ldrdeq   r4, r5, [r2], #-0xf4
11801110: bx       lr
11801114: bx       lr
11801118: bx       lr
1180111c: bx       lr
11801120: bx       lr
11801124: bx       lr
11801128: push     {r3, lr}
1180112c: ldr      r3, [r2, #8]
11801130: str      r3, [sp]
11801134: ldr      ip, [r0]
11801138: ldrd     r2, r3, [r2]
1180113c: ldr      ip, [ip, #0x18]
11801140: blx      ip
11801144: pop      {r3, pc}
11801148: vldr     s0, [pc, #4]
1180114c: vstr     s0, [r0, #0xc]
11801150: bx       lr
11801154: andeq    r0, r0, r0
11801158: b        #0x11800190  ; ->_ZdlPv
1180115c: bx       lr
11801160: add      r0, r0, #4
11801164: push     {r4, lr}
11801168: bl       #0x118001a0  ; ->nn::fs::detail::FileBase::TrySetPosition
1180116c: mov      r1, pc
11801170: lsrs     r2, r0, #0x1f
11801174: beq      #0x11801180
11801178: pop      {r4, lr}
1180117c: b        #0x118001a8  ; ->nn::err::CTR::ThrowFatalErrAll
11801180: pop      {r4, pc}
11801184: add      r0, r0, #4
11801188: b        #0x118001a0  ; ->nn::fs::detail::FileBase::TrySetPosition
1180118c: push     {r3, lr}
11801190: mov      r3, r2
11801194: mov      r2, r1
11801198: mov      r1, sp
1180119c: add      r0, r0, #4
118011a0: bl       #0x118001b0  ; ->nn::fs::detail::FileBase::TryRead
118011a4: mov      r1, pc
118011a8: lsrs     r2, r0, #0x1f
118011ac: blne     #0x118001a8  ; ->nn::err::CTR::ThrowFatalErrAll
118011b0: ldr      r0, [sp]
118011b4: pop      {r3, pc}
118011b8: push     {r3, lr}
118011bc: add      r0, r0, #4
118011c0: ldr      r1, [sp, #8]
118011c4: str      r1, [sp]
118011c8: bl       #0x118001b8  ; ->nn::fs::detail::FileBase::TrySeek
118011cc: mov      r1, pc
118011d0: lsrs     r2, r0, #0x1f
118011d4: beq      #0x118011e0
118011d8: pop      {r3, lr}
118011dc: b        #0x118001a8  ; ->nn::err::CTR::ThrowFatalErrAll
118011e0: pop      {r3, pc}
118011e4: add      r0, r0, #4
118011e8: b        #0x118001b0  ; ->nn::fs::detail::FileBase::TryRead
118011ec: push     {r3, lr}
118011f0: add      r0, r0, #4
118011f4: ldr      r1, [sp, #8]
118011f8: str      r1, [sp]
118011fc: bl       #0x118001b8  ; ->nn::fs::detail::FileBase::TrySeek
11801200: pop      {r3, pc}
11801204: push     {r4, r5, r6, lr}
11801208: mov      r4, r0
1180120c: add      r5, r0, #4
11801210: ldr      r0, [r0, #4]
11801214: bics     r1, r0, #1
11801218: beq      #0x11801238
1180121c: tst      r0, #1
11801220: blne     #0x118001c0  ; ->nndbgPanic
11801224: ldr      r0, [r5]
11801228: bic      r0, r0, #1
1180122c: bl       #0x118001c8  ; ->nn::fs::CTR::MPCore::detail::UserFileSystem::CloseFile
11801230: mov      r0, #0
11801234: str      r0, [r5]
11801238: mov      r0, r4
1180123c: pop      {r4, r5, r6, lr}
11801240: b        #0x11800190  ; ->_ZdlPv
11801244: push     {r4, r5, r6, lr}
11801248: mov      r4, r0
1180124c: add      r5, r0, #4
11801250: ldr      r0, [r0, #4]
11801254: bics     r1, r0, #1
11801258: beq      #0x11801278
1180125c: tst      r0, #1
11801260: blne     #0x118001c0  ; ->nndbgPanic
11801264: ldr      r0, [r5]
11801268: bic      r0, r0, #1
1180126c: bl       #0x118001c8  ; ->nn::fs::CTR::MPCore::detail::UserFileSystem::CloseFile
11801270: mov      r0, #0
11801274: str      r0, [r5]
11801278: mov      r0, r4
1180127c: pop      {r4, r5, r6, pc}
11801280: push     {r0, r1, r2, r3}
11801284: push     {r4, lr}
11801288: add      r4, r2, #1
1180128c: ldr      ip, [sp, #0x14]
11801290: cmp      r1, r4
11801294: add      r3, sp, #0x18
11801298: movhi    r1, r4
1180129c: mov      r2, ip
118012a0: bl       #0x118001d0  ; ->__c89vswprintf
118012a4: pop      {r4}
118012a8: ldr      pc, [sp], #0x14
118012ac: vldr     s1, [pc, #0x24]  ; =0x3f800000 (1)
118012b0: mov      r2, #1
118012b4: vstr     s1, [r0, #4]
118012b8: vldr     s0, [pc, #0x14]  ; =0x0 (0)
118012bc: mov      r1, #0
118012c0: strh     r2, [r0, #0xc]
118012c4: strh     r1, [r0, #0xe]
118012c8: vstr     s0, [r0]
118012cc: vstr     s0, [r0, #8]
118012d0: bx       lr
118012d4: andeq    r0, r0, r0
118012d8: svclo    #0x800000
118012dc: vldr     s0, [pc, #4]
118012e0: vstr     s0, [r0, #8]
118012e4: bx       lr
118012e8: andeq    r0, r0, r0
118012ec: push     {r4, r5, r6, r7, r8, sb, sl, fp, lr}
118012f0: mov      r4, r0
118012f4: ldr      r6, [pc, #0x3d4]  ; =0x3f62a8 msys::MComSys::_sys
118012f8: vpush    {d8}
118012fc: sub      sp, sp, #0x14
11801300: ldr      r0, [r0, #8]
11801304: cmp      r0, #0
11801308: ldreq    r0, [r6]
1180130c: streq    r0, [r4, #8]
11801310: add      r0, r4, #0x12000
11801314: add      r0, r0, #0xa30
11801318: ldr      r5, [r4, #8]
1180131c: mov      r8, r0
11801320: bl       #0x118001d8  ; ->ad::lyt::LytResourceMan::init
11801324: add      r0, r4, #0x12800
11801328: add      r0, r0, #0x2a4
1180132c: bl       #0x118001e0  ; ->ad::fw::Resource::getFileData
11801330: mov      r1, r0
11801334: add      r2, pc, #0x398
11801338: mov      r0, r8
1180133c: bl       #0x118001e8  ; ->ad::lyt::LytResourceMan::registerArc
11801340: add      r0, r4, #0x12800
11801344: add      r1, r5, #0xd0000
11801348: add      r0, r0, #0x3b4
1180134c: add      r1, r1, #0x2f00
11801350: mov      r2, #1
11801354: str      r0, [sp, #0xc]
11801358: bl       #0x118001f0  ; ->msys::MLyt::init
1180135c: ldr      r0, [sp, #0xc]
11801360: add      r2, pc, #0x370
11801364: mov      r1, r8
11801368: bl       #0x118001f8  ; ->msys::MLyt::createLyt
1180136c: add      r7, r4, #0x10000
11801370: add      r7, r7, #0x2c80
11801374: vldr     s16, [pc, #0x378]  ; =0x0 (0)
11801378: vldr     s17, [pc, #0x378]  ; =0xc3480000 (-200)
1180137c: mov      r0, r7
11801380: bl       #0x11800200  ; ->MoveVBase::stop
11801384: vstr     s16, [r7, #0x1c]
11801388: add      r0, r7, #0x20
1180138c: mov      r1, #0x400
11801390: vstmia   r0, {s16, s17}
11801394: mov      r3, #0xe
11801398: ldr      r0, [r7, #0x1c]
1180139c: ldr      r2, [pc, #0x358]  ; =0x1180c1f8
118013a0: str      r0, [r7, #4]!
118013a4: add      r7, r7, #4
118013a8: vstmia   r7, {s16, s17}
118013ac: ldr      r0, [sp, #0xc]
118013b0: str      r1, [r0, #0x13c]
118013b4: ldr      r0, [r4, #4]
118013b8: ldr      r1, [r0, #0x18]
118013bc: add      r0, r4, #0x12c00
118013c0: add      r0, r0, #0x35c
118013c4: str      r0, [sp, #8]
118013c8: bl       #0x11800208  ; ->msys::MLyt::build
118013cc: ldr      r0, [sp, #8]
118013d0: add      r1, r5, #0xd3000
118013d4: mov      r2, #1
118013d8: bl       #0x118001f0  ; ->msys::MLyt::init
118013dc: add      r0, r4, #0x13000
118013e0: add      r0, r0, #0x304
118013e4: add      r3, r4, #0x12800
118013e8: str      r0, [sp]
118013ec: ldr      r0, [sp, #8]
118013f0: add      r3, r3, #0x214
118013f4: add      r2, pc, #0x304
118013f8: mov      r1, r8
118013fc: bl       #0x11800210  ; ->msys::MLyt::createLyt
11801400: add      r5, r4, #0x13000
11801404: add      r5, r5, #0x28
11801408: mov      r0, r5
1180140c: bl       #0x11800200  ; ->MoveVBase::stop
11801410: vstr     s16, [r5, #0x1c]
11801414: add      r0, r5, #0x20
11801418: ldr      r1, [pc, #0x2fc]  ; =0x401
1180141c: vstmia   r0, {s16, s17}
11801420: ldr      r0, [r5, #0x1c]
11801424: str      r0, [r5, #4]!
11801428: add      r5, r5, #4
1180142c: vstmia   r5, {s16, s17}
11801430: ldr      r0, [sp, #8]
11801434: str      r1, [r0, #0x13c]
11801438: add      r0, r4, #0x3dc00
1180143c: add      r0, r0, #0x384
11801440: mov      r1, r4
11801444: mov      r5, r0
11801448: bl       #0x1180854c
1180144c: ldr      r0, [pc, #0x2cc]  ; =0x61013
11801450: ldrsb    r1, [r0, r4]
11801454: mov      r0, r5
11801458: bl       #0x11806ab4
1180145c: mov      r0, #0
11801460: mov      r1, r0
11801464: strb     r0, [r5, #0x141]
11801468: mov      r0, r5
1180146c: bl       #0x11800218  ; ->msys::MListWndPBase::setEnableInput
11801470: add      r5, r4, #0x3e000
11801474: add      r5, r5, #0x50
11801478: mov      r0, r5
1180147c: bl       #0x11800200  ; ->MoveVBase::stop
11801480: vstr     s16, [r5, #0x1c]
11801484: add      r0, r5, #0x20
11801488: add      r1, r4, #0x12800
1180148c: vstmia   r0, {s16, s17}
11801490: add      r1, r1, #0x32c
11801494: ldr      r0, [r5, #0x1c]
11801498: str      r0, [r5, #4]!
1180149c: add      r5, r5, #4
118014a0: add      r0, r4, #0x13000
118014a4: vstmia   r5, {s16, s17}
118014a8: add      r0, r0, #0x35c
118014ac: mov      r5, r0
118014b0: bl       #0x11800220  ; ->msys::MCellAnime::init
118014b4: mov      r8, #0
118014b8: ldr      r0, [sp, #8]
118014bc: mov      r3, r8
118014c0: add      r2, pc, #0x25c
118014c4: mov      r1, r5
118014c8: str      r8, [sp]
118014cc: str      r8, [sp, #4]
118014d0: bl       #0x11800228  ; ->msys::MLyt::attachMChr
118014d4: add      r0, r4, #0x13400
118014d8: add      r1, r4, #0x12000
118014dc: add      r0, r0, #0x1d8
118014e0: add      r1, r1, #0xb70
118014e4: mov      r5, r0
118014e8: bl       #0x11800220  ; ->msys::MCellAnime::init
118014ec: ldr      r0, [sp, #8]
118014f0: mov      r3, #0
118014f4: add      r2, pc, #0x234
118014f8: mov      r1, r5
118014fc: str      r8, [sp]
11801500: str      r8, [sp, #4]
11801504: bl       #0x11800228  ; ->msys::MLyt::attachMChr
11801508: ldr      fp, [pc, #0x22c]  ; =0x11814460
1180150c: mov      r5, #0
11801510: mov      sb, #0x400
11801514: ldr      r0, [r4, #8]
11801518: cmp      r0, #0
1180151c: ldreq    r0, [r6]
11801520: streq    r0, [r4, #8]
11801524: cmp      r0, #0
11801528: add      r3, r0, #0x4a000
1180152c: ldreq    r0, [r6]
11801530: add      r3, r3, #0xaa0
11801534: streq    r0, [r4, #8]
11801538: add      r0, r0, #0xe6000
1180153c: ldr      r2, [r0, #0x4f0]
11801540: ldr      r0, [r4, #4]
11801544: ldr      r1, [r0, #0x18]
11801548: rsb      r0, r5, r5, lsl #5
1180154c: add      r0, r0, r5, lsl #6
11801550: str      sb, [sp]
11801554: add      sl, r4, r0, lsl #2
11801558: add      r7, sl, #0x35800
1180155c: add      r7, r7, #0x208
11801560: mov      r0, r7
11801564: bl       #0x11800230  ; ->msys::MDfxChr::init
11801568: add      sl, sl, #0x35800
1180156c: add      sl, sl, #0x2d4
11801570: mov      r0, sl
11801574: bl       #0x11800200  ; ->MoveVBase::stop
11801578: vstr     s16, [sl, #0x1c]
1180157c: vstr     s16, [sl, #0x20]
11801580: vstr     s16, [sl, #0x24]
11801584: vstr     s16, [sl, #4]
11801588: vstr     s16, [sl, #8]
1180158c: vstr     s16, [sl, #0xc]
11801590: str      r8, [sp]
11801594: str      r8, [sp, #4]
11801598: ldr      r2, [fp, r5, lsl #2]
1180159c: ldr      r0, [sp, #0xc]
118015a0: mov      r1, r7
118015a4: mov      r3, #0
118015a8: bl       #0x11800228  ; ->msys::MLyt::attachMChr
118015ac: add      r0, r5, #1
118015b0: and      r5, r0, #0xff
118015b4: cmp      r5, #6
118015b8: blo      #0x11801514
118015bc: ldr      r0, [r4, #8]
118015c0: cmp      r0, #0
118015c4: ldreq    r0, [r6]
118015c8: streq    r0, [r4, #8]
118015cc: cmp      r0, #0
118015d0: add      r3, r0, #0x4a000
118015d4: ldreq    r0, [r6]
118015d8: add      r3, r3, #0xaa0
118015dc: streq    r0, [r4, #8]
118015e0: add      r0, r0, #0xe6000
118015e4: ldr      r2, [r0, #0x4f0]
118015e8: ldr      r0, [r4, #4]
118015ec: ldr      r1, [r0, #0x18]
118015f0: add      r0, r4, #0x36000
118015f4: add      r0, r0, #0x2f0
118015f8: mov      r7, r0
118015fc: str      sb, [sp]
11801600: bl       #0x11800230  ; ->msys::MDfxChr::init
11801604: add      r5, r4, #0x36000
11801608: add      r5, r5, #0x3bc
1180160c: mov      r0, r5
11801610: bl       #0x11800200  ; ->MoveVBase::stop
11801614: vstr     s16, [r5, #0x1c]
11801618: vstr     s16, [r5, #0x20]
1180161c: vstr     s16, [r5, #0x24]
11801620: ldrd     r0, r1, [r5, #0x1c]
11801624: mov      r3, #0
11801628: strd     r0, r1, [r5, #4]
1180162c: vstr     s16, [r5, #0xc]
11801630: str      r8, [sp]
11801634: str      r8, [sp, #4]
11801638: ldr      r2, [fp, #0x18]
1180163c: ldr      r0, [sp, #0xc]
11801640: mov      r1, r7
11801644: bl       #0x11800228  ; ->msys::MLyt::attachMChr
11801648: ldr      sl, [pc, #0xf0]  ; =0x1181447c
1180164c: mov      r5, #0
11801650: ldr      r0, [r4, #8]
11801654: cmp      r0, #0
11801658: ldreq    r0, [r6]
1180165c: streq    r0, [r4, #8]
11801660: cmp      r0, #0
11801664: add      r3, r0, #0x4a000
11801668: ldreq    r0, [r6]
1180166c: add      r3, r3, #0xaa0
11801670: streq    r0, [r4, #8]
11801674: add      r0, r0, #0xe6000
11801678: ldr      r2, [r0, #0x4f0]
1180167c: ldr      r0, [r4, #4]
11801680: ldr      r1, [r0, #0x18]
11801684: rsb      r0, r5, r5, lsl #5
11801688: add      r0, r0, r5, lsl #6
1180168c: str      sb, [sp]
11801690: add      fp, r4, r0, lsl #2
11801694: add      r7, fp, #0x36400
11801698: add      r7, r7, #0x6c
1180169c: mov      r0, r7
118016a0: bl       #0x11800230  ; ->msys::MDfxChr::init
118016a4: add      fp, fp, #0x36400
118016a8: add      fp, fp, #0x138
118016ac: mov      r0, fp
118016b0: bl       #0x11800200  ; ->MoveVBase::stop
118016b4: vstr     s16, [fp, #0x1c]
118016b8: vstr     s16, [fp, #0x20]
118016bc: vstr     s16, [fp, #0x24]
118016c0: vstr     s16, [fp, #4]
118016c4: vstr     s16, [fp, #8]
118016c8: vstr     s16, [fp, #0xc]
118016cc: b        #0x11801744
118016d0: eorseq   r6, pc, r8, lsr #5
118016d4: andeq    r0, r0, lr, lsr #32
118016d8: stmdbmi  lr, {r0, r2, r3, r6, r8, fp, lr} ^
118016dc: strbmi   r4, [sp, #-0x147]
118016e0: mcrrmi   p3, #5, r4, pc, c15
118016e4: strbpl   r5, [r5, #-0x349]
118016e8: cdphs    p15, #5, c5, c5, c13, #2
118016ec: stmdbvc  ip!, {r1, r5, r6, sb, sl, sp, lr} ^
118016f0: andeq    r0, r0, r4, ror r0
118016f4: andeq    r0, r0, r0
118016f8: movtgt   r0, #0x8000
118016fc: strdne   ip, sp, [r0, r8]
11801700: stmdbmi  lr, {r0, r2, r3, r6, r8, fp, lr} ^
11801704: strbmi   r4, [sp, #-0x147]
11801708: mcrrmi   p3, #5, r4, pc, c15
1180170c: strbpl   r5, [r5, #-0x349]
11801710: cdphs    p15, #4, c5, c12, c13, #2
11801714: stmdbvc  ip!, {r1, r5, r6, sb, sl, sp, lr} ^
11801718: andeq    r0, r0, r4, ror r0
1180171c: andeq    r0, r0, r1, lsl #8
11801720: andeq    r1, r6, r3, lsl r0
11801724: svcpl    #0x534e49
11801728: svcpl    #0x4a424f
1180172c: andeq    r5, r0, r4, asr #6
11801730: svcpl    #0x534e49
11801734: svcpl    #0x4a424f
11801738: subseq   r5, r4, r4, asr r8
1180173c: orrne    r4, r1, r0, ror #8
11801740: orrne    r4, r1, ip, ror r4
11801744: str      r8, [sp]
11801748: str      r8, [sp, #4]
1180174c: ldr      r2, [sl, r5, lsl #2]
11801750: ldr      r0, [sp, #0xc]
11801754: mov      r1, r7
11801758: mov      r3, #0
1180175c: bl       #0x11800228  ; ->msys::MLyt::attachMChr
11801760: add      r0, r5, #1
11801764: and      r5, r0, #0xff
11801768: cmp      r5, #4
1180176c: blo      #0x11801650
11801770: ldr      r0, [r4, #8]
11801774: ldr      r1, [pc, #0x118]  ; =0x4aba4
11801778: cmp      r0, #0
1180177c: ldreq    r0, [r6]
11801780: streq    r0, [r4, #8]
11801784: cmp      r0, #0
11801788: add      r3, r0, r1
1180178c: ldreq    r0, [r6]
11801790: streq    r0, [r4, #8]
11801794: add      r0, r0, #0xe6000
11801798: ldr      r2, [r0, #0x4f0]
1180179c: ldr      r0, [r4, #4]
118017a0: ldr      r1, [r0, #0x18]
118017a4: ldr      r0, [pc, #-0x90]  ; =0x401
118017a8: str      r0, [sp]
118017ac: add      r0, r4, #0x36800
118017b0: add      r0, r0, #0x3d8
118017b4: mov      r6, r0
118017b8: bl       #0x11800230  ; ->msys::MDfxChr::init
118017bc: add      r5, r4, #0x36c00
118017c0: add      r5, r5, #0xa4
118017c4: mov      r0, r5
118017c8: bl       #0x11800200  ; ->MoveVBase::stop
118017cc: vstr     s16, [r5, #0x1c]
118017d0: vstr     s16, [r5, #0x20]
118017d4: vstr     s16, [r5, #0x24]
118017d8: ldrd     r0, r1, [r5, #0x1c]
118017dc: mov      r3, #0
118017e0: add      r2, pc, #0xb0
118017e4: strd     r0, r1, [r5, #4]
118017e8: vstr     s16, [r5, #0xc]
118017ec: ldr      r0, [sp, #8]
118017f0: mov      r1, r6
118017f4: str      r8, [sp]
118017f8: str      r8, [sp, #4]
118017fc: bl       #0x11800228  ; ->msys::MLyt::attachMChr
11801800: add      r0, r4, #0x45000
11801804: add      r0, r0, #0x110
11801808: mov      r1, r4
1180180c: mov      r6, r0
11801810: bl       #0x11802ab4
11801814: add      r5, r4, #0x45000
11801818: add      r5, r5, #0x1dc
1180181c: mov      r0, r5
11801820: bl       #0x11800200  ; ->MoveVBase::stop
11801824: vstr     s16, [r5, #0x1c]
11801828: add      r1, r5, #0x20
1180182c: vstmia   r1, {s16, s17}
11801830: mov      r1, #0
11801834: ldr      r0, [r5, #0x1c]
11801838: str      r0, [r5, #4]!
1180183c: add      r5, r5, #4
11801840: mov      r0, r6
11801844: vstmia   r5, {s16, s17}
11801848: strb     r8, [r6, #0x141]
1180184c: bl       #0x11800218  ; ->msys::MListWndPBase::setEnableInput
11801850: ldr      r1, [pc, #0x54]  ; =0x1180c000
11801854: add      r2, r4, #0x12800
11801858: add      r2, r2, #0x1fc
1180185c: ldrd     r0, r1, [r1, #0x48]
11801860: strd     r0, r1, [r2]
11801864: ldr      r1, [pc, #0x44]  ; =0x132dc
11801868: mov      r0, r4
1180186c: ldrb     r1, [r1, r4]
11801870: cmp      r1, #0
11801874: beq      #0x11801888
11801878: add      sp, sp, #0x14
1180187c: vpop     {d8}
11801880: pop      {r4, r5, r6, r7, r8, sb, sl, fp, lr}
11801884: b        #0x11802e24
11801888: add      sp, sp, #0x14
1180188c: vpop     {d8}
11801890: pop      {r4, r5, r6, r7, r8, sb, sl, fp, pc}
11801894: andeq    sl, r4, r4, lsr #23
11801898: svcpl    #0x534e49
1180189c: subpl    r5, pc, r4, asr r2
118018a0: ldrbmi   r5, [pc, #-0x948]  ; =0xa000006
118018a4: movtmi   r4, #0x5646
118018a8: andeq    r0, r0, r4, asr r0
118018ac: orrne    ip, r0, r0
118018b0: ldrdeq   r3, r4, [r1], -ip
118018b4: push     {r4, r5, r6, lr}
118018b8: mov      r4, r0
118018bc: add      r0, r0, #0x10
118018c0: bl       #0x11800238  ; ->Backup::errorCode
118018c4: add      r5, r4, #0x10000
118018c8: cmp      r0, #0
118018cc: add      r5, r5, #0x2a00
118018d0: beq      #0x118018ec
118018d4: sub      r0, r0, #1
118018d8: subs     r0, r0, #0x2000
118018dc: cmpne    r0, #1
118018e0: cmpne    r0, #2
118018e4: beq      #0x11801970
118018e8: b        #0x11801960
118018ec: add      r0, r4, #0x10
118018f0: bl       #0x11800240  ; ->Backup::isBusyFormat
118018f4: cmp      r0, #0
118018f8: nop      
118018fc: bne      #0x11801934
11801900: add      r0, r4, #0x10
11801904: bl       #0x11800248  ; ->Backup::mount
11801908: cmp      r0, #0
1180190c: nop      
11801910: beq      #0x11801960
11801914: add      r0, r4, #0x10
11801918: bl       #0x11800250  ; ->Backup::rewriteSaveData
1180191c: cmp      r0, #0
11801920: nop      
11801924: beq      #0x11801938
11801928: ldr      r1, [pc, #0x5c]  ; =0x1180c1c8
1180192c: ldm      r1, {r0, r1}
11801930: strd     r0, r1, [r5, #4]
11801934: pop      {r4, r5, r6, pc}
11801938: ldr      r0, [r4, #8]
1180193c: cmp      r0, #0
11801940: bne      #0x11801950
11801944: ldr      r0, [pc, #0x44]  ; =0x3f62a8 msys::MComSys::_sys
11801948: ldr      r0, [r0]
1180194c: str      r0, [r4, #8]
11801950: ldr      r0, [r0, #4]
11801954: add      r0, r0, #0x400
11801958: add      r0, r0, #0x118
1180195c: bl       #0x11800258  ; ->CtrFS::unmountSaveData
11801960: ldr      r1, [pc, #0x2c]  ; =0x1180c1d8
11801964: ldm      r1, {r0, r1}
11801968: strd     r0, r1, [r5, #4]
1180196c: pop      {r4, r5, r6, pc}
11801970: ldr      r0, [pc, #0x20]  ; =0x3f40a8 Backup::_fs
11801974: mov      r1, #0
11801978: ldr      r0, [r0]
1180197c: strh     r1, [r0, #0x24]
11801980: add      r0, r4, #0x10
11801984: pop      {r4, r5, r6, lr}
11801988: b        #0x11800260  ; ->Backup::format
1180198c: orrne    ip, r0, r8, asr #3
11801990: eorseq   r6, pc, r8, lsr #5
11801994: ldrdne   ip, sp, [r0, r8]
11801998: eorseq   r4, pc, r8, lsr #1
1180199c: ldr      r1, [r0, #8]
118019a0: cmp      r1, #0
118019a4: bne      #0x118019b4
118019a8: ldr      r1, [pc, #0xc]  ; =0x3f62a8 msys::MComSys::_sys
118019ac: ldr      r1, [r1]
118019b0: str      r1, [r0, #8]
118019b4: ldr      r0, [r1, #4]
118019b8: b        #0x11800268  ; ->GameMain::Back
118019bc: eorseq   r6, pc, r8, lsr #5
118019c0: push     {r4, r5, r6, r7, r8, sb, sl, fp, lr}
118019c4: mov      r5, r0
118019c8: mov      r4, r1
118019cc: vpush    {d8}
118019d0: sub      sp, sp, #0x74
118019d4: str      r1, [r0]
118019d8: add      r0, sp, #0x10
118019dc: bl       #0x11800270  ; ->ad::lyt::LytNumReel3::InitParam
118019e0: ldr      sb, [pc, #0x39c]  ; =0x3f62a8 msys::MComSys::_sys
118019e4: ldr      r0, [r4, #8]
118019e8: mov      r2, #2
118019ec: mov      ip, #0x11
118019f0: cmp      r0, #0
118019f4: ldreq    r0, [sb]
118019f8: add      r1, sp, #0x10
118019fc: mov      r3, r2
11801a00: streq    r0, [r4, #8]
11801a04: add      r0, r0, #0x800
11801a08: add      r0, r0, #0x44
11801a0c: str      ip, [sp]
11801a10: bl       #0x11800278  ; ->msys::MLytNumRes::set
11801a14: mov      r6, #0
11801a18: strb     r6, [sp, #0x41]
11801a1c: ldr      r0, [r4, #8]
11801a20: add      r1, pc, #0x378
11801a24: add      r3, sp, #4
11801a28: cmp      r0, #0
11801a2c: ldreq    r0, [sb]
11801a30: streq    r0, [r4, #8]
11801a34: add      r2, r0, #0xd3000
11801a38: str      r1, [sp]
11801a3c: add      r0, pc, #0x344
11801a40: stm      r3, {r0, r6}
11801a44: add      r3, r4, #0x12c00
11801a48: add      r3, r3, #0x35c
11801a4c: mov      r7, r3
11801a50: add      r1, sp, #0x10
11801a54: add      r0, r5, #4
11801a58: str      r6, [sp, #0xc]
11801a5c: bl       #0x11800280  ; ->msys::MLytNum::init
11801a60: add      r3, pc, #0x320
11801a64: add      r2, pc, #0x334
11801a68: add      r1, r5, #4
11801a6c: mov      r0, r7
11801a70: str      r6, [sp]
11801a74: str      r6, [sp, #4]
11801a78: bl       #0x11800228  ; ->msys::MLyt::attachMChr
11801a7c: ldr      r0, [r4, #8]
11801a80: mov      r3, #0x11
11801a84: mov      ip, #2
11801a88: cmp      r0, #0
11801a8c: ldreq    r0, [sb]
11801a90: add      r1, sp, #0x10
11801a94: mov      r2, #0
11801a98: streq    r0, [r4, #8]
11801a9c: add      r0, r0, #0x800
11801aa0: str      r3, [sp]
11801aa4: mov      r3, ip
11801aa8: add      r0, r0, #0x44
11801aac: bl       #0x11800278  ; ->msys::MLytNumRes::set
11801ab0: strb     r6, [sp, #0x41]
11801ab4: str      r6, [sp, #0x24]
11801ab8: ldr      r0, [r4, #8]
11801abc: add      r1, pc, #0x2f4
11801ac0: add      r3, sp, #4
11801ac4: cmp      r0, #0
11801ac8: ldreq    r0, [sb]
11801acc: streq    r0, [r4, #8]
11801ad0: add      r2, r0, #0xd3000
11801ad4: str      r1, [sp]
11801ad8: add      r0, pc, #0x2cc
11801adc: stm      r3, {r0, r6}
11801ae0: mov      r3, r7
11801ae4: add      r1, sp, #0x10
11801ae8: add      r0, r5, #0x234
11801aec: str      r6, [sp, #0xc]
11801af0: bl       #0x11800280  ; ->msys::MLytNum::init
11801af4: ldr      r0, [r4, #4]
11801af8: ldr      sl, [pc, #0x2c0]  ; =0x401
11801afc: add      r2, r5, #0x14800
11801b00: add      r8, r5, #0xdc00
11801b04: ldr      r1, [r0, #0x18]
11801b08: add      r0, r5, #0x14800
11801b0c: add      r0, r0, #0x164
11801b10: vldr     s16, [pc, #0x2ac]  ; =0x0 (0)
11801b14: str      sl, [r0], #-0xc
11801b18: add      r2, r2, #0x124
11801b1c: stm      r0, {r1, r6}
11801b20: add      r8, r8, #0x124
11801b24: add      r0, r5, #0xd000
11801b28: mov      fp, r8
11801b2c: vstr     s16, [r2, #0x3c]
11801b30: add      r0, r0, #0xe70
11801b34: bl       #0x11800288  ; ->MessageSimple::init
11801b38: mov      r0, r8
11801b3c: bl       #0x11806968
11801b40: add      r0, r5, #0x13000
11801b44: mov      r8, #1
11801b48: strb     r6, [r0, #0x92c]
11801b4c: strb     r8, [r0, #0x92d]
11801b50: ldr      r0, [r4, #8]
11801b54: add      r1, pc, #0x26c
11801b58: cmp      r0, #0
11801b5c: ldreq    r0, [sb]
11801b60: add      sb, r0, #0xe9000
11801b64: streq    r0, [r4, #8]
11801b68: add      r0, r0, #0xe9000
11801b6c: add      sb, sb, #0x50
11801b70: add      r0, r0, #0x58
11801b74: bl       #0x11800290  ; ->LMS_GetTextIndexByLabel
11801b78: mov      r1, r0
11801b7c: add      r0, sb, #8
11801b80: bl       #0x11800298  ; ->LMS_GetText
11801b84: mov      r1, r0
11801b88: mov      r3, #0
11801b8c: mov      r2, r3
11801b90: mov      r0, fp
11801b94: bl       #0x118002a0  ; ->msys::MMsg::playStr
11801b98: add      r3, pc, #0x20c
11801b9c: add      r2, pc, #0x23c
11801ba0: mov      r1, fp
11801ba4: mov      r0, r7
11801ba8: str      r6, [sp]
11801bac: str      r6, [sp, #4]
11801bb0: bl       #0x11800228  ; ->msys::MLyt::attachMChr
11801bb4: ldr      r0, [r4, #4]
11801bb8: add      r1, r5, #0x7000
11801bbc: add      r1, r1, #0xdc
11801bc0: add      r2, r5, #0x7000
11801bc4: ldr      r0, [r0, #0x18]
11801bc8: str      sl, [r1], #-0xc
11801bcc: add      r2, r2, #0x9c
11801bd0: stm      r1, {r0, r6}
11801bd4: add      sb, r5, #0x400
11801bd8: add      r0, r5, #0x400
11801bdc: add      sb, sb, #0x9c
11801be0: vstr     s16, [r2, #0x3c]
11801be4: add      r0, r0, #0x1e8
11801be8: bl       #0x11800288  ; ->MessageSimple::init
11801bec: mov      r0, sb
11801bf0: bl       #0x11806968
11801bf4: add      fp, r5, #0x6400
11801bf8: add      fp, fp, #0x1e8
11801bfc: mov      r1, #3
11801c00: strb     r1, [fp, #0xad8]
11801c04: ldr      r1, [pc, #0x1e4]  ; =0x5e10
11801c08: ldr      r2, [pc, #0x1e4]  ; =0x3fc0f8
11801c0c: add      r0, r5, #0x400
11801c10: add      r0, r0, #0x1e8
11801c14: str      r2, [r1, r5]
11801c18: ldr      r1, [pc, #0x1d8]  ; =0xe6e6e6ff
11801c1c: mov      r2, #1
11801c20: bl       #0x118002a8  ; ->MessageWriter::setFontColor
11801c24: add      r0, r5, #0x6000
11801c28: mov      r3, #0
11801c2c: strb     r8, [r0, #0xa4]
11801c30: strb     r8, [r0, #0xa5]
11801c34: strb     r8, [fp, #0xad9]
11801c38: add      r2, pc, #0x1bc
11801c3c: mov      r1, sb
11801c40: mov      r0, r7
11801c44: str      r6, [sp]
11801c48: str      r6, [sp, #4]
11801c4c: bl       #0x11800228  ; ->msys::MLyt::attachMChr
11801c50: add      r0, r5, #0x400
11801c54: ldr      r1, [r7, #0x150]
11801c58: add      r3, pc, #0x128
11801c5c: add      r2, pc, #0x1a4
11801c60: add      r0, r0, #0x64
11801c64: bl       #0x118002b0  ; ->ad::lyt::LytAnim::init
11801c68: ldr      r1, [r7, #0x150]
11801c6c: add      r3, pc, #0x19c
11801c70: add      r2, pc, #0x19c
11801c74: add      r0, r5, #0x480
11801c78: bl       #0x118002b0  ; ->ad::lyt::LytAnim::init
11801c7c: vldr     s0, [pc, #0x19c]  ; =0x3f800000 (1)
11801c80: strb     r6, [sp, #0x58]
11801c84: vstr     s16, [sp, #0x5c]
11801c88: vstr     s0, [sp, #0x60]
11801c8c: vstr     s16, [sp, #0x64]
11801c90: strh     r8, [sp, #0x68]
11801c94: strh     r6, [sp, #0x6a]
11801c98: str      r6, [sp, #0x6c]
11801c9c: str      r6, [sp, #0x70]
11801ca0: ldr      r1, [r7, #0x150]
11801ca4: add      r3, pc, #0xdc
11801ca8: add      r2, pc, #0x174
11801cac: add      r0, sp, #0x58
11801cb0: bl       #0x118002b0  ; ->ad::lyt::LytAnim::init
11801cb4: ldr      r0, [sp, #0x6c]
11801cb8: add      sb, sp, #0x58
11801cbc: bl       #0x118002b8  ; ->ad::lyt::AnimTransform::GetFrameSize
11801cc0: vmov     s0, r0
11801cc4: mov      r0, sb
11801cc8: vcvt.f32.u32 s0, s0
11801ccc: bl       #0x118002c0  ; ->ad::lyt::LytAnim::stopAndSetFrm
11801cd0: mov      r1, #0
11801cd4: add      r0, sp, #0x58
11801cd8: bl       #0x118002c8  ; ->ad::lyt::LytAnim::term
11801cdc: vstr     s16, [sp, #0x64]
11801ce0: ldr      r0, [r4, #4]
11801ce4: add      r2, r5, #0xd000
11801ce8: add      r2, r2, #0xce0
11801cec: add      sb, r5, #0x7000
11801cf0: ldr      r1, [r0, #0x18]
11801cf4: add      r0, r5, #0xd000
11801cf8: add      r0, r0, #0xd20
11801cfc: add      sb, sb, #0xe0
11801d00: str      sl, [r0], #-0xc
11801d04: stm      r0, {r1, r6}
11801d08: add      r0, r5, #0x7000
11801d0c: vstr     s16, [r2, #0x3c]
11801d10: add      r0, r0, #0x22c
11801d14: bl       #0x11800288  ; ->MessageSimple::init
11801d18: mov      r0, sb
11801d1c: bl       #0x11806968
11801d20: add      r0, r5, #0xc000
11801d24: ldr      r1, [pc, #0x108]  ; =0xdd05
11801d28: strb     r8, [r0, #0xce8]
11801d2c: strb     r8, [r0, #0xce9]
11801d30: add      r0, r5, #0x7000
11801d34: strb     r8, [r1, r5]
11801d38: ldr      r1, [pc, #0xb8]  ; =0xe6e6e6ff
11801d3c: add      r0, r0, #0x22c
11801d40: mov      r2, #1
11801d44: bl       #0x118002a8  ; ->MessageWriter::setFontColor
11801d48: add      r3, pc, #0x38
11801d4c: add      r2, pc, #0xe4
11801d50: mov      r1, sb
11801d54: mov      r0, r7
11801d58: str      r6, [sp]
11801d5c: str      r6, [sp, #4]
11801d60: bl       #0x11800228  ; ->msys::MLyt::attachMChr
11801d64: add      r0, r5, #0x14000
11801d68: mov      r1, #0xff
11801d6c: strb     r1, [r0, #0x96c]
11801d70: str      r6, [r0, #0x968]
11801d74: strb     r8, [r0, #0x96d]
11801d78: add      sp, sp, #0x74
11801d7c: vpop     {d8}
11801d80: pop      {r4, r5, r6, r7, r8, sb, sl, fp, pc}
11801d84: eorseq   r6, pc, r8, lsr #5
11801d88: svcpl    #0x6c6e70
11801d8c: stmdbmi  lr, {r0, r2, r3, r6, r8, fp, lr} ^
11801d90: strbmi   r4, [sp, #-0x147]
11801d94: svcmi    #0x43565f
11801d98: strbpl   r4, [sb], #-0x44e
11801d9c: subeq    r4, lr, sb, asr #30
11801da0: ldrbmi   r5, [pc], #-0x64c
11801da4: strbpl   r4, [sb], #-0x749
11801da8: eorseq   r3, r1, pc, asr r0
11801dac: movtmi   r5, #0x9250
11801db0: mcrrmi   p15, #4, r5, r1, c5
11801db4: eorseq   r5, r1, ip, asr #30
11801db8: cdpmi    p15, #5, c4, c5, c3, #2
11801dbc: andeq    r0, r0, r4, asr r0
11801dc0: andeq    r0, r0, r1, lsl #8
11801dc4: andeq    r0, r0, r0
11801dc8: svcpl    #0x53454d
11801dcc: rsbvc    r6, pc, r3, asr r8
11801dd0: svcpl    #0x73654d
11801dd4: svcvs    #0x666e49
11801dd8: ldmdbvs  r2!, {r0, r1, r2, r3, r4, r6, ip, lr} ^
11801ddc: andeq    r6, r0, r3, ror #10
11801de0: svcpl    #0x534e49
11801de4: movtmi   r5, #0x9250
11801de8: ldrbmi   r5, [r4, #-0xf45]
11801dec: andeq    r5, r0, r8, asr r4
11801df0: andeq    r5, r0, r0, lsl lr
11801df4: ldrshteq ip, [pc], -r8
11801df8: .word    0xe6e6e6ff
11801dfc: svcpl    #0x534e49
11801e00: mrrcmi   p9, #5, r4, r4, c4
11801e04: andeq    r0, r0, r5, asr #32
11801e08: svcpl    #0x544553
11801e0c: strbmi   r4, [r4, #-0xf4d]
11801e10: andeq    r0, r0, r0
11801e14: movtmi   r5, #0x9250
11801e18: cdpvs    p15, #6, c5, c15, c5, #2
11801e1c: rsbeq    r6, r6, pc, ror #12
11801e20: svclo    #0x800000
11801e24: svcpl    #0x544553
11801e28: ldrbmi   r5, [pc], #-0x64c
11801e2c: strbpl   r4, [sb], #-0x749
11801e30: andeq    r0, r0, r0
11801e34: andeq    sp, r0, r5, lsl #26
11801e38: svcpl    #0x534e49
11801e3c: ldrbpl   r4, [r8], #-0x554
11801e40: mcrmi    p3, #2, r4, c15, c15, #2
11801e44: ldmdbmi  r4, {r2, r6, r8, fp, lr} ^
11801e48: andeq    r4, r0, pc, asr #28
11801e4c: push     {r3, r4, r5, r6, r7, r8, sb, lr}
11801e50: mov      r4, r0
11801e54: add      r6, r4, #0x13000
11801e58: add      r6, r6, #0x304
11801e5c: ldr      r2, [pc, #0x22c]  ; =0x802
11801e60: ldr      r0, [r1]
11801e64: tst      r0, r2
11801e68: beq      #0x11801e90
11801e6c: ldr      r0, [pc, #0x220]  ; =0x1334c
11801e70: ldr      r0, [r0, r4]
11801e74: ldr      r1, [r0]
11801e78: ldr      r1, [r1, #0x10]
11801e7c: blx      r1
11801e80: mov      r1, #0
11801e84: mov      r0, r4
11801e88: bl       #0x118068b4
11801e8c: b        #0x11801ffc
11801e90: ldr      r1, [pc, #0x200]  ; =0x401
11801e94: tst      r0, r1
11801e98: beq      #0x11801ed0
11801e9c: ldrsb    r0, [r6, #0x18]
11801ea0: add      r0, r4, r0, lsl #2
11801ea4: add      r0, r0, #0x13000
11801ea8: ldr      r0, [r0, #0x340]
11801eac: ldr      r1, [r0]
11801eb0: ldr      r1, [r1, #0x10]
11801eb4: blx      r1
11801eb8: mov      r1, #0
11801ebc: mov      r0, r4
11801ec0: bl       #0x118068b4
11801ec4: nop      
11801ec8: nop      
11801ecc: b        #0x11801ffc
11801ed0: tst      r0, #0x30
11801ed4: beq      #0x11801ffc
11801ed8: mov      r0, #0
11801edc: mov      r3, r0
11801ee0: mov      r2, r0
11801ee4: str      r0, [sp]
11801ee8: ldr      r1, [pc, #0x1ac]  ; =0x110015
11801eec: mov      r0, r4
11801ef0: bl       #0x11806814
11801ef4: ldrb     r0, [r6, #0x18]
11801ef8: cmp      r0, #0
11801efc: moveq    r0, #1
11801f00: movne    r0, #0
11801f04: cmp      r0, #0
11801f08: strb     r0, [r6, #0x18]
11801f0c: movne    r0, #1
11801f10: vmov     s0, r0
11801f14: ldr      r0, [pc, #0x184]  ; =0x60fb8
11801f18: add      r0, r0, r4
11801f1c: vcvt.f32.u32 s0, s0
11801f20: bl       #0x118002c0  ; ->ad::lyt::LytAnim::stopAndSetFrm
11801f24: ldrb     r0, [r6, #0x18]
11801f28: cmp      r0, #1
11801f2c: movne    r0, #0
11801f30: vmov     s0, r0
11801f34: ldr      r0, [pc, #0x168]  ; =0xfff9f02c
11801f38: sub      r0, r4, r0
11801f3c: vcvt.f32.u32 s0, s0
11801f40: bl       #0x118002c0  ; ->ad::lyt::LytAnim::stopAndSetFrm
11801f44: ldrb     r0, [r6, #0x18]
11801f48: cmp      r0, #1
11801f4c: movne    r0, #0
11801f50: add      r0, r0, r4
11801f54: add      r0, r0, #0x61000
11801f58: ldrsb    r0, [r0, #0x14]
11801f5c: vmov     s0, r0
11801f60: ldr      r0, [pc, #0x140]  ; =0x60f9c
11801f64: add      r0, r0, r4
11801f68: vcvt.f32.s32 s0, s0
11801f6c: bl       #0x118002c0  ; ->ad::lyt::LytAnim::stopAndSetFrm
11801f70: ldr      r0, [pc, #0x134]  ; =0x1331c
11801f74: add      r7, r4, #0x36000
11801f78: add      r7, r7, #0x2f0
11801f7c: mov      r5, #0
11801f80: ldrb     r0, [r0, r4]
11801f84: cmp      r0, #0
11801f88: beq      #0x11802008
11801f8c: rsb      r0, r5, r5, lsl #5
11801f90: add      r0, r0, r5, lsl #6
11801f94: add      r0, r4, r0, lsl #2
11801f98: add      r0, r0, #0x35800
11801f9c: add      r0, r0, #0x208
11801fa0: bl       #0x118002d0  ; ->msys::MDfxChr::term
11801fa4: add      r0, r5, #1
11801fa8: and      r5, r0, #0xff
11801fac: cmp      r5, #6
11801fb0: blo      #0x11801f8c
11801fb4: mov      r0, r7
11801fb8: bl       #0x118002d0  ; ->msys::MDfxChr::term
11801fbc: mov      r5, #0
11801fc0: mov      r1, #0x2e
11801fc4: rsb      r0, r5, r5, lsl #5
11801fc8: add      r0, r0, r5, lsl #6
11801fcc: add      r7, r4, r0, lsl #2
11801fd0: add      r0, r7, #0x36400
11801fd4: add      r0, r0, #0x6c
11801fd8: bl       #0x118002d8  ; ->msys::MDfxChr::playDfx
11801fdc: ldr      r1, [pc, #0xcc]  ; =0x365c0
11801fe0: add      r2, r5, #1
11801fe4: mvn      r0, #0
11801fe8: and      r5, r2, #0xff
11801fec: ldr      r1, [r1, r7]
11801ff0: cmp      r5, #4
11801ff4: strh     r0, [r1, #0xf2]
11801ff8: blo      #0x11801fc0
11801ffc: mov      r0, r6
11802000: bl       #0x1180657c
11802004: pop      {r3, r4, r5, r6, r7, r8, sb, pc}
11802008: rsb      r0, r5, r5, lsl #5
1180200c: add      r0, r0, r5, lsl #6
11802010: add      r0, r4, r0, lsl #2
11802014: add      r0, r0, #0x36400
11802018: add      r0, r0, #0x6c
1180201c: bl       #0x118002d0  ; ->msys::MDfxChr::term
11802020: add      r0, r5, #1
11802024: and      r5, r0, #0xff
11802028: cmp      r5, #4
1180202c: blo      #0x11802008
11802030: mov      r5, #0
11802034: mov      r1, #0x29
11802038: rsb      r0, r5, r5, lsl #5
1180203c: add      r0, r0, r5, lsl #6
11802040: add      r8, r4, r0, lsl #2
11802044: add      r0, r8, #0x35800
11802048: add      r0, r0, #0x208
1180204c: bl       #0x118002d8  ; ->msys::MDfxChr::playDfx
11802050: ldr      r1, [pc, #0x5c]  ; =0x35b5c
11802054: add      r2, r5, #1
11802058: mvn      r0, #0
1180205c: and      r5, r2, #0xff
11802060: ldr      r1, [r1, r8]
11802064: cmp      r5, #6
11802068: strh     r0, [r1, #0xf2]
1180206c: blo      #0x11802034
11802070: mov      r1, #0x2b
11802074: mov      r0, r7
11802078: bl       #0x118002d8  ; ->msys::MDfxChr::playDfx
1180207c: ldr      r0, [pc, #0x34]  ; =0x36444
11802080: ldr      r1, [r0, r4]
11802084: mvn      r0, #0
11802088: strh     r0, [r1, #0xf2]
1180208c: b        #0x11801ffc
11802090: andeq    r0, r0, r2, lsl #16
11802094: andeq    r3, r1, ip, asr #6
11802098: andeq    r0, r0, r1, lsl #8
1180209c: andseq   r0, r1, r5, lsl r0
118020a0: strheq   r0, [r6], -r8
118020a4: .word    0xfff9f02c
118020a8: muleq    r6, ip, pc
118020ac: andeq    r3, r1, ip, lsl r3
118020b0: andeq    r6, r3, r0, asr #11
118020b4: andeq    r5, r3, ip, asr fp
118020b8: andeq    r6, r3, r4, asr #8
118020bc: push     {r4, r5, r6, r7, r8, lr}
118020c0: mov      r4, r0
118020c4: mov      r7, r1
118020c8: vpush    {d8}
118020cc: sub      sp, sp, #0xb8
118020d0: str      r1, [r0], #4
118020d4: strd     r2, r3, [r4, #0x20]
118020d8: mov      r2, #0x10
118020dc: mov      r1, #0
118020e0: bl       #0x118002e0  ; ->Mem::Fill
118020e4: ldr      r8, [pc, #0x168]  ; =0x11814440
118020e8: mov      r5, #0
118020ec: ldr      r1, [pc, #0x164]  ; =0x11802668
118020f0: add      r0, r8, r5, lsl #3
118020f4: add      r6, r4, r5, lsl #2
118020f8: ldr      r2, [r0, #4]
118020fc: ldr      r3, [r6, #4]
11802100: add      r0, sp, #0x78
11802104: bl       #0x118002e8  ; ->nn::nstd::TSPrintf
11802108: ldr      r0, [r4]
1180210c: add      r1, sp, #0x78
11802110: add      r0, r0, #0xe9000
11802114: add      r0, r0, #0x58
11802118: bl       #0x11800290  ; ->LMS_GetTextIndexByLabel
1180211c: asr      r0, r0, #0x1f
11802120: cmn      r0, #1
11802124: beq      #0x11802138
11802128: ldr      r0, [r6, #4]
1180212c: add      r0, r0, #1
11802130: str      r0, [r6, #4]
11802134: b        #0x118020ec
11802138: add      r5, r5, #1
1180213c: cmp      r5, #4
11802140: blo      #0x118020ec
11802144: add      r0, sp, #0x10
11802148: bl       #0x11800270  ; ->ad::lyt::LytNumReel3::InitParam
1180214c: mov      r0, #0xff
11802150: str      r0, [sp]
11802154: add      r0, r7, #0x800
11802158: add      r1, sp, #0x10
1180215c: mov      r2, #0
11802160: mov      r3, #0xf
11802164: add      r0, r0, #0x44
11802168: bl       #0x11800278  ; ->msys::MLytNumRes::set
1180216c: mov      r1, #1
11802170: strb     r1, [r4, #0x169]
11802174: add      r1, pc, #0xf0
11802178: add      r2, sp, #4
1180217c: str      r1, [sp]
11802180: mov      r5, #0
11802184: add      r0, pc, #0xd0
11802188: stm      r2, {r0, r5}
1180218c: add      r6, r7, #0xd3000
11802190: str      r5, [sp, #0xc]
11802194: ldr      r3, [r4, #0x20]
11802198: mov      r2, r6
1180219c: add      r1, sp, #0x10
118021a0: add      r0, r4, #0x28
118021a4: bl       #0x11800280  ; ->msys::MLytNum::init
118021a8: mov      r1, #1
118021ac: strb     r1, [r4, #0x399]
118021b0: add      r1, pc, #0xbc
118021b4: add      r3, sp, #4
118021b8: str      r1, [sp]
118021bc: add      r0, pc, #0x98
118021c0: stm      r3, {r0, r5}
118021c4: mov      r2, r6
118021c8: str      r5, [sp, #0xc]
118021cc: ldr      r3, [r4, #0x20]
118021d0: add      r1, sp, #0x10
118021d4: add      r0, r4, #0x258
118021d8: bl       #0x11800280  ; ->msys::MLytNum::init
118021dc: vldr     s16, [pc, #0x98]  ; =0x0 (0)
118021e0: vldr     s0, [pc, #0x98]  ; =0x3f800000 (1)
118021e4: strb     r5, [sp, #0x58]
118021e8: vstr     s16, [sp, #0x5c]
118021ec: vstr     s0, [sp, #0x60]
118021f0: vstr     s16, [sp, #0x64]
118021f4: mov      r0, #1
118021f8: strh     r0, [sp, #0x68]
118021fc: strh     r5, [sp, #0x6a]
11802200: str      r5, [sp, #0x6c]
11802204: str      r5, [sp, #0x70]
11802208: ldr      r0, [r4, #0x20]
1180220c: mov      r3, #0
11802210: add      r2, pc, #0x44
11802214: add      r1, pc, #0x68
11802218: bl       #0x118002f0  ; ->msys::MLyt::getParts
1180221c: ldr      r1, [r0, #0xac]
11802220: add      r3, pc, #0x68
11802224: add      r2, pc, #0x68
11802228: add      r0, sp, #0x58
1180222c: bl       #0x118002b0  ; ->ad::lyt::LytAnim::init
11802230: vmov.f32 s0, s16
11802234: add      r0, sp, #0x58
11802238: bl       #0x118002c0  ; ->ad::lyt::LytAnim::stopAndSetFrm
1180223c: mov      r1, #1
11802240: add      r0, sp, #0x58
11802244: bl       #0x118002c8  ; ->ad::lyt::LytAnim::term
11802248: add      sp, sp, #0xb8
1180224c: vpop     {d8}
11802250: pop      {r4, r5, r6, r7, r8, pc}
11802254: orrne    r4, r1, r0, asr #8
11802258: orrne    r2, r0, r8, ror #12
1180225c: strbmi   r5, [sb], #-0x547
11802260: ldmdapl  r4, {r0, r2, r6, r8, sb, sl, fp, ip, lr} ^
11802264: qdsubvs  r5, r4, r2
11802268: andeq    r6, r0, r3, ror r5
1180226c: svcpl    #0x4d554e
11802270: andeq    r0, r0, ip, asr #32
11802274: svcpl    #0x4d554e
11802278: andeq    r0, r0, r2, asr r0
1180227c: andeq    r0, r0, r0
11802280: svclo    #0x800000
11802284: svcpl    #0x6d756e
11802288: .word    0x73616c73
1180228c: andeq    r0, r0, r8, rrx
11802290: andeq    r0, r0, r0
11802294: svcpl    #0x6c6f63
11802298: andeq    r3, r0, r1, lsr r5
1180229c: push     {r4, r5, lr}
118022a0: mov      r4, r0
118022a4: sub      sp, sp, #0x44
118022a8: mov      r0, #0
118022ac: str      r0, [r4, #0x14]
118022b0: str      r1, [r4, #0x1c]
118022b4: ldr      r0, [r1]
118022b8: ldr      r2, [pc, #0x10c]  ; =0x1180225c
118022bc: mov      r3, #0
118022c0: add      r1, pc, #0x108
118022c4: add      r0, r4, r0, lsl #2
118022c8: ldr      r5, [r0, #4]
118022cc: ldr      r0, [r4, #0x20]
118022d0: bl       #0x118002f8  ; ->msys::MLyt::getPane
118022d4: ldrb     r1, [r0, #0x44]
118022d8: ldr      r2, [pc, #0xec]  ; =0x1180225c
118022dc: mov      r3, #0
118022e0: and      r1, r1, #0xfe
118022e4: strb     r1, [r0, #0x44]
118022e8: ldr      r0, [r4, #0x20]
118022ec: add      r1, pc, #0xe4
118022f0: bl       #0x118002f8  ; ->msys::MLyt::getPane
118022f4: ldrb     r2, [r0, #0x44]
118022f8: cmp      r5, #1
118022fc: movhi    r1, #1
11802300: movls    r1, #0
11802304: and      r2, r2, #0xfe
11802308: orr      r1, r1, r2
1180230c: strb     r1, [r0, #0x44]
11802310: ldr      r0, [r4, #0x488]
11802314: ldr      r1, [r0]
11802318: ldr      r2, [r1, #0x28]
1180231c: mov      r1, #0
11802320: blx      r2
11802324: ldr      r0, [r4, #0x48c]
11802328: cmp      r5, #1
1180232c: movhi    r1, #1
11802330: movls    r1, #0
11802334: ldr      r2, [r0]
11802338: ldr      r2, [r2, #0x28]
1180233c: blx      r2
11802340: add      r0, r4, #0x178
11802344: mov      r1, #1
11802348: bl       #0x11800300  ; ->ad::lyt::LytNumReel3::setValueInstant
1180234c: mov      r1, r5
11802350: add      r0, r4, #0x3a8
11802354: bl       #0x11800300  ; ->ad::lyt::LytNumReel3::setValueInstant
11802358: ldr      r0, [r4, #0x1c]
1180235c: ldr      r1, [pc, #0x7c]  ; =0x11814440
11802360: ldr      r3, [r4, #0x14]
11802364: ldr      r0, [r0]
11802368: add      r0, r1, r0, lsl #3
1180236c: ldr      r1, [pc, #0x70]  ; =0x11802668
11802370: ldr      r2, [r0, #4]
11802374: mov      r0, sp
11802378: bl       #0x118002e8  ; ->nn::nstd::TSPrintf
1180237c: ldr      r0, [r4], #0x24
11802380: mov      r1, sp
11802384: ldr      r5, [r4]
11802388: add      r4, r0, #0xe9000
1180238c: add      r0, r0, #0xe9000
11802390: add      r4, r4, #0x50
11802394: add      r0, r0, #0x58
11802398: bl       #0x11800290  ; ->LMS_GetTextIndexByLabel
1180239c: mov      r1, r0
118023a0: add      r0, r4, #8
118023a4: bl       #0x11800298  ; ->LMS_GetText
118023a8: mov      r1, r0
118023ac: ldr      r0, [r5]
118023b0: mov      r3, #0
118023b4: mov      r2, r3
118023b8: ldr      ip, [r0, #0x3c]
118023bc: mov      r0, r5
118023c0: blx      ip
118023c4: add      sp, sp, #0x44
118023c8: pop      {r4, r5, pc}
118023cc: orrne    r2, r0, ip, asr r2
118023d0: svcpl    #0x6e7462
118023d4: andeq    r0, r0, ip, asr #32
118023d8: svcpl    #0x6e7462
118023dc: andeq    r0, r0, r2, asr r0
118023e0: orrne    r4, r1, r0, asr #8
118023e4: orrne    r2, r0, r8, ror #12
118023e8: push     {r4, r5, r6, r7, lr}
118023ec: mov      r4, r0
118023f0: mov      r5, r1
118023f4: ldr      r0, [r0, #0x14]
118023f8: sub      sp, sp, #0x44
118023fc: add      r0, r0, r5
11802400: add      r1, r0, #1
11802404: str      r0, [r4, #0x14]
11802408: add      r0, r4, #0x178
1180240c: bl       #0x11800300  ; ->ad::lyt::LytNumReel3::setValueInstant
11802410: ldr      r0, [r4, #0x1c]
11802414: ldr      r1, [pc, #0x1a0]  ; =0x11814440
11802418: ldr      r3, [r4, #0x14]
1180241c: ldr      r0, [r0]
11802420: add      r0, r1, r0, lsl #3
11802424: ldr      r1, [pc, #0x194]  ; =0x11802668
11802428: ldr      r2, [r0, #4]
1180242c: mov      r0, sp
11802430: bl       #0x118002e8  ; ->nn::nstd::TSPrintf
11802434: ldr      r0, [r4]
11802438: ldr      r7, [r4, #0x24]
1180243c: mov      r1, sp
11802440: add      r6, r0, #0xe9000
11802444: add      r0, r0, #0xe9000
11802448: add      r6, r6, #0x50
1180244c: add      r0, r0, #0x58
11802450: bl       #0x11800290  ; ->LMS_GetTextIndexByLabel
11802454: mov      r1, r0
11802458: add      r0, r6, #8
1180245c: bl       #0x11800298  ; ->LMS_GetText
11802460: mov      r1, r0
11802464: ldr      r0, [r7]
11802468: mov      r3, #0
1180246c: mov      r2, r3
11802470: ldr      ip, [r0, #0x3c]
11802474: mov      r0, r7
11802478: blx      ip
1180247c: ldr      r0, [r4, #0x1c]
11802480: ldr      r1, [r0]
11802484: ldr      r0, [r4, #0x14]
11802488: add      r1, r4, r1, lsl #2
1180248c: cmp      r0, #0
11802490: ldr      r6, [r1, #4]
11802494: beq      #0x1180252c
11802498: cmp      r5, #0
1180249c: ble      #0x118024e0
118024a0: cmp      r0, r5
118024a4: bne      #0x118024e0
118024a8: ldr      r0, [r4, #0x20]
118024ac: mov      r3, #0
118024b0: add      r2, pc, #0x10c
118024b4: add      r1, pc, #0x118
118024b8: bl       #0x118002f8  ; ->msys::MLyt::getPane
118024bc: ldrb     r1, [r0, #0x44]
118024c0: and      r1, r1, #0xfe
118024c4: orr      r1, r1, #1
118024c8: strb     r1, [r0, #0x44]
118024cc: ldr      r0, [r4, #0x488]
118024d0: ldr      r1, [r0]
118024d4: ldr      r2, [r1, #0x28]
118024d8: mov      r1, #1
118024dc: blx      r2
118024e0: ldr      r0, [r4, #0x14]
118024e4: sub      r1, r6, #1
118024e8: cmp      r0, r1
118024ec: blo      #0x11802560
118024f0: ldr      r0, [r4, #0x20]
118024f4: mov      r3, #0
118024f8: add      r2, pc, #0xc4
118024fc: add      r1, pc, #0xd8
11802500: bl       #0x118002f8  ; ->msys::MLyt::getPane
11802504: ldrb     r1, [r0, #0x44]
11802508: and      r1, r1, #0xfe
1180250c: strb     r1, [r0, #0x44]
11802510: ldr      r0, [r4, #0x48c]
11802514: ldr      r1, [r0]
11802518: ldr      r2, [r1, #0x28]
1180251c: add      sp, sp, #0x44
11802520: mov      r1, #0
11802524: pop      {r4, r5, r6, r7, lr}
11802528: bx       r2
1180252c: ldr      r0, [r4, #0x20]
11802530: mov      r3, #0
11802534: add      r2, pc, #0x88
11802538: add      r1, pc, #0x94
1180253c: bl       #0x118002f8  ; ->msys::MLyt::getPane
11802540: ldrb     r1, [r0, #0x44]
11802544: and      r1, r1, #0xfe
11802548: strb     r1, [r0, #0x44]
1180254c: ldr      r0, [r4, #0x488]
11802550: ldr      r1, [r0]
11802554: ldr      r2, [r1, #0x28]
11802558: mov      r1, #0
1180255c: b        #0x118024dc
11802560: cmp      r5, #0
11802564: bge      #0x118025b4
11802568: sub      r0, r0, r5
1180256c: cmp      r0, r1
11802570: blo      #0x118025b4
11802574: ldr      r0, [r4, #0x20]
11802578: mov      r3, #0
1180257c: add      r2, pc, #0x40
11802580: add      r1, pc, #0x54
11802584: bl       #0x118002f8  ; ->msys::MLyt::getPane
11802588: ldrb     r1, [r0, #0x44]
1180258c: and      r1, r1, #0xfe
11802590: orr      r1, r1, #1
11802594: strb     r1, [r0, #0x44]
11802598: ldr      r0, [r4, #0x48c]
1180259c: ldr      r1, [r0]
118025a0: ldr      r2, [r1, #0x28]
118025a4: add      sp, sp, #0x44
118025a8: mov      r1, #1
118025ac: pop      {r4, r5, r6, r7, lr}
118025b0: bx       r2
118025b4: add      sp, sp, #0x44
118025b8: pop      {r4, r5, r6, r7, pc}
118025bc: orrne    r4, r1, r0, asr #8
118025c0: orrne    r2, r0, r8, ror #12
118025c4: strbmi   r5, [sb], #-0x547
118025c8: ldmdapl  r4, {r0, r2, r6, r8, sb, sl, fp, ip, lr} ^
118025cc: qdsubvs  r5, r4, r2
118025d0: andeq    r6, r0, r3, ror r5
118025d4: svcpl    #0x6e7462
118025d8: andeq    r0, r0, ip, asr #32
118025dc: svcpl    #0x6e7462
118025e0: andeq    r0, r0, r2, asr r0
118025e4: push     {r4, r5, lr}
118025e8: mov      r4, r0
118025ec: ldr      r0, [r0, #0x1c]
118025f0: ldr      r1, [pc, #0x6c]  ; =0x11814440
118025f4: sub      sp, sp, #0x44
118025f8: ldr      r3, [r4, #0x14]
118025fc: ldr      r0, [r0]
11802600: add      r0, r1, r0, lsl #3
11802604: add      r1, pc, #0x5c
11802608: ldr      r2, [r0, #4]
1180260c: mov      r0, sp
11802610: bl       #0x118002e8  ; ->nn::nstd::TSPrintf
11802614: ldr      r0, [r4], #0x24
11802618: mov      r1, sp
1180261c: ldr      r5, [r4]
11802620: add      r4, r0, #0xe9000
11802624: add      r0, r0, #0xe9000
11802628: add      r4, r4, #0x50
1180262c: add      r0, r0, #0x58
11802630: bl       #0x11800290  ; ->LMS_GetTextIndexByLabel
11802634: mov      r1, r0
11802638: add      r0, r4, #8
1180263c: bl       #0x11800298  ; ->LMS_GetText
11802640: mov      r1, r0
11802644: ldr      r0, [r5]
11802648: mov      r3, #0
1180264c: mov      r2, r3
11802650: ldr      ip, [r0, #0x3c]
11802654: mov      r0, r5
11802658: blx      ip
1180265c: add      sp, sp, #0x44
11802660: pop      {r4, r5, pc}
11802664: orrne    r4, r1, r0, asr #8
11802668: ldrbhs   r7, [pc, #-0x325]  ; =0xa01005eb
1180266c: rsbeq    r3, r4, r0, lsr r2
11802670: ldr      r1, [pc, #0x10]  ; =0x12aa8
11802674: ldrb     r1, [r1, r0]
11802678: cmp      r1, #0
1180267c: beq      #0x11802684
11802680: b        #0x118012ec
11802684: bx       lr
11802688: andeq    r2, r1, r8, lsr #21
1180268c: push     {r4, r5, r6, r7, r8, sb, sl, fp, lr}
11802690: mov      r4, r0
11802694: sub      sp, sp, #0xc
11802698: add      r0, r0, #0x3dc00
1180269c: add      r0, r0, #0x384
118026a0: mov      r7, r1
118026a4: str      r0, [sp, #8]
118026a8: bl       #0x11800308  ; ->msys::MListWndPBase::isTpNeutral
118026ac: cmp      r0, #0
118026b0: beq      #0x11802944
118026b4: add      sb, r4, #0x61000
118026b8: mov      r8, #1
118026bc: ldrb     r0, [sb, #0x13]
118026c0: cmp      r0, #0
118026c4: ldr      r0, [sp, #8]
118026c8: beq      #0x118026e0
118026cc: bl       #0x11800310  ; ->msys::MListWndPBase::getCurNo
118026d0: ldrb     r1, [sb, #0xd]
118026d4: tst      r1, r8, lsl r0
118026d8: beq      #0x118026fc
118026dc: b        #0x118026f4
118026e0: nop      
118026e4: bl       #0x11800310  ; ->msys::MListWndPBase::getCurNo
118026e8: ldrb     r1, [sb, #0xc]
118026ec: tst      r1, r8, lsl r0
118026f0: beq      #0x118026fc
118026f4: mov      r5, #1
118026f8: b        #0x11802700
118026fc: mov      r5, #0
11802700: ldr      r0, [sp, #8]
11802704: bl       #0x11800318  ; ->msys::MListWndPBase::getCurItem
11802708: mov      r6, r0
1180270c: ldr      r0, [sp, #8]
11802710: bl       #0x11800318  ; ->msys::MListWndPBase::getCurItem
11802714: cmp      r0, #0
11802718: mov      sl, #0
1180271c: beq      #0x118027b0
11802720: ldr      r0, [sp, #8]
11802724: bl       #0x11800320  ; ->msys::MListWndPBase::getSelectItem
11802728: cmp      r0, #0
1180272c: nop      
11802730: beq      #0x118027b0
11802734: cmp      r5, #0
11802738: beq      #0x1180278c
1180273c: ldr      r0, [sp, #8]
11802740: bl       #0x11800318  ; ->msys::MListWndPBase::getCurItem
11802744: ldrb     r0, [r0, #0xe]
11802748: cmp      r0, #0
1180274c: beq      #0x1180278c
11802750: mov      r3, #0
11802754: ldr      r1, [pc, #0x238]  ; =0x110016
11802758: mov      r2, r3
1180275c: mov      r0, r4
11802760: str      sl, [sp]
11802764: bl       #0x11806814
11802768: mov      r1, #0
1180276c: mov      r0, r4
11802770: bl       #0x118068b4
11802774: ldr      r1, [pc, #0x21c]  ; =0x1180c000
11802778: add      r2, r4, #0x10000
1180277c: add      r2, r2, #0x2a00
11802780: ldrd     r0, r1, [r1, #0xc8]
11802784: strd     r0, r1, [r2, #4]
11802788: b        #0x118027e0
1180278c: mov      r3, #0
11802790: ldr      r1, [pc, #0x204]  ; =0x110018
11802794: mov      r2, r3
11802798: mov      r0, r4
1180279c: str      sl, [sp]
118027a0: bl       #0x11806814
118027a4: nop      
118027a8: nop      
118027ac: b        #0x118027e0
118027b0: ldr      r0, [r7]
118027b4: ldr      r1, [pc, #0x1e4]  ; =0x802
118027b8: tst      r0, r1
118027bc: beq      #0x118027e0
118027c0: ldr      r0, [pc, #0x1dc]  ; =0x1334c
118027c4: ldr      r0, [r0, r4]
118027c8: ldr      r1, [r0]
118027cc: ldr      r1, [r1, #0x10]
118027d0: blx      r1
118027d4: mov      r1, #0
118027d8: mov      r0, r4
118027dc: bl       #0x118068b4
118027e0: ldr      sl, [pc, #0x1c0]  ; =0x3f95f0 gGameWork
118027e4: cmp      r6, #0
118027e8: beq      #0x11802914
118027ec: add      r7, r4, #0x45000
118027f0: ldr      r0, [r7, #0x108]
118027f4: cmp      r0, r6
118027f8: beq      #0x11802914
118027fc: ldr      r0, [r7, #0x10c]
11802800: add      fp, r4, #0x12800
11802804: add      fp, fp, #0x3b4
11802808: cmp      r0, #0
1180280c: blt      #0x11802828
11802810: and      r1, r0, #0xff
11802814: mov      r0, fp
11802818: bl       #0x11800328  ; ->msys::MLyt::getAnim
1180281c: vldr     s0, [pc, #0x188]  ; =0x0 (0)
11802820: nop      
11802824: bl       #0x118002c0  ; ->ad::lyt::LytAnim::stopAndSetFrm
11802828: ldrh     r0, [r6, #4]
1180282c: mvn      r3, #0
11802830: subs     r1, r0, r3, lsr #16
11802834: beq      #0x1180290c
11802838: ldrsb    r1, [sb, #0x13]
1180283c: adds     r0, r1, #0
11802840: movne    r0, #0xa
11802844: add      r0, sl, r0, lsl #1
11802848: add      r2, r0, #0x7f0
1180284c: ldr      r0, [r6]
11802850: add      r2, r2, r0, lsl #1
11802854: ldrsh    r2, [r2]
11802858: cmp      r2, #0
1180285c: blt      #0x1180290c
11802860: ldr      ip, [pc, #0x148]  ; =0x118144a8
11802864: ldr      r2, [r7, #0x10c]
11802868: sub      lr, ip, #0x1c
1180286c: cmp      r2, #0
11802870: blt      #0x118028c8
11802874: cmp      r1, #0
11802878: and      r1, r2, #0xff
1180287c: beq      #0x118028a4
11802880: ldr      r2, [ip, r0, lsl #2]
11802884: str      r3, [sp, #4]
11802888: ldr      r3, [pc, #0x124]  ; =0x3f7f58 _ZZN4msys4MLyt11createAnimeEhPKcbaEs
1180288c: mov      r0, fp
11802890: str      r8, [sp]
11802894: bl       #0x11800330  ; ->msys::MLyt::createAnime
11802898: nop      
1180289c: nop      
118028a0: b        #0x11802910
118028a4: ldr      r2, [lr, r0, lsl #2]
118028a8: str      r3, [sp, #4]
118028ac: ldr      r3, [pc, #0x100]  ; =0x3f7f58 _ZZN4msys4MLyt11createAnimeEhPKcbaEs
118028b0: mov      r0, fp
118028b4: str      r8, [sp]
118028b8: bl       #0x11800330  ; ->msys::MLyt::createAnime
118028bc: nop      
118028c0: nop      
118028c4: b        #0x11802910
118028c8: cmp      r1, #0
118028cc: beq      #0x118028f0
118028d0: ldr      r1, [ip, r0, lsl #2]
118028d4: mov      r3, #0
118028d8: mov      r2, r3
118028dc: mov      r0, fp
118028e0: bl       #0x11800338  ; ->msys::MLyt::createAnimeAutoSlot
118028e4: nop      
118028e8: nop      
118028ec: b        #0x11802904
118028f0: ldr      r1, [lr, r0, lsl #2]
118028f4: mov      r3, #0
118028f8: mov      r2, r3
118028fc: mov      r0, fp
11802900: bl       #0x11800338  ; ->msys::MLyt::createAnimeAutoSlot
11802904: str      r0, [r7, #0x10c]
11802908: b        #0x11802910
1180290c: str      r3, [r7, #0x10c]
11802910: str      r6, [r7, #0x108]
11802914: ldrb     r0, [sb, #0x13]
11802918: cmp      r0, #0
1180291c: beq      #0x1180294c
11802920: ldr      r6, [pc, #0x90]  ; =0x3f9df4
11802924: ldr      r0, [sp, #8]
11802928: bl       #0x11800310  ; ->msys::MListWndPBase::getCurNo
1180292c: add      r0, r6, r0, lsl #1
11802930: mov      r1, r5
11802934: ldrsh    r0, [r0]
11802938: add      r2, r8, r0, asr #31
1180293c: mov      r0, r4
11802940: bl       #0x11806474
11802944: add      sp, sp, #0xc
11802948: pop      {r4, r5, r6, r7, r8, sb, sl, fp, pc}
1180294c: ldr      r0, [sp, #8]
11802950: add      r6, sl, #0x7f0
11802954: bl       #0x11800310  ; ->msys::MListWndPBase::getCurNo
11802958: add      r0, r6, r0, lsl #1
1180295c: ldr      r7, [pc, #0x58]  ; =0x1180c268
11802960: ldrsh    r0, [r0]
11802964: add      r6, r8, r0, asr #31
11802968: ldr      r0, [sp, #8]
1180296c: bl       #0x11800310  ; ->msys::MListWndPBase::getCurNo
11802970: rsb      r0, r0, r0, lsl #3
11802974: add      sp, sp, #0xc
11802978: add      r1, r7, r0, lsl #2
1180297c: mov      r3, r6
11802980: mov      r2, r5
11802984: add      r0, r4, #0x4c000
11802988: pop      {r4, r5, r6, r7, r8, sb, sl, fp, lr}
1180298c: add      r0, r0, #0x194
11802990: b        #0x118061f4
11802994: andseq   r0, r1, r6, lsl r0
11802998: orrne    ip, r0, r0
1180299c: andseq   r0, r1, r8, lsl r0
118029a0: andeq    r0, r0, r2, lsl #16
118029a4: andeq    r3, r1, ip, asr #6
118029a8: ldrshteq sb, [pc], -r0
118029ac: andeq    r0, r0, r0
118029b0: orrne    r4, r1, r8, lsr #9
118029b4: eorseq   r7, pc, r8, asr pc
118029b8: ldrshteq sb, [pc], -r4
118029bc: orrne    ip, r0, r8, ror #4
118029c0: push     {r4, r5, r6, lr}
118029c4: mov      r6, r1
118029c8: mov      r4, r0
118029cc: bl       #0x11806144
118029d0: add      r0, r4, #0x10
118029d4: bl       #0x11800238  ; ->Backup::errorCode
118029d8: add      r5, r4, #0x10000
118029dc: cmp      r0, #0
118029e0: add      r5, r5, #0x2a00
118029e4: beq      #0x11802a10
118029e8: sub      r0, r0, #1
118029ec: ldr      r1, [pc, #0x58]  ; =0x1180c000
118029f0: subs     r0, r0, #0x2000
118029f4: cmpne    r0, #1
118029f8: cmpne    r0, #2
118029fc: addeq    r1, r1, #0x1d0
11802a00: addne    r1, r1, #0x1d8
11802a04: ldm      r1, {r0, r1}
11802a08: strd     r0, r1, [r5, #4]
11802a0c: pop      {r4, r5, r6, pc}
11802a10: add      r0, r4, #0x10
11802a14: bl       #0x11800340  ; ->Backup::isBusyWriting
11802a18: cmp      r0, #0
11802a1c: nop      
11802a20: bne      #0x11802a0c
11802a24: add      r0, r4, #0x10
11802a28: bl       #0x11800348  ; ->Backup::term
11802a2c: ldr      r1, [pc, #0x1c]  ; =0x1180c0d8
11802a30: add      r5, r5, #4
11802a34: ldm      r1, {r0, r2}
11802a38: mov      r1, r6
11802a3c: stm      r5, {r0, r2}
11802a40: mov      r0, r4
11802a44: pop      {r4, r5, r6, lr}
11802a48: b        #0x11804d04
11802a4c: orrne    ip, r0, r0
11802a50: ldrdne   ip, sp, [r0, r8]
11802a54: push     {r3, r4, r5, lr}
11802a58: mov      r4, r0
11802a5c: mov      r0, #0
11802a60: mov      r3, r0
11802a64: mov      r1, r0
11802a68: str      r0, [sp]
11802a6c: add      r0, r4, #0x12c00
11802a70: mov      r2, #1
11802a74: add      r0, r0, #0x35c
11802a78: bl       #0x11800350  ; ->msys::MLyt::playAnimeFromNo
11802a7c: ldr      r0, [pc, #0x10]  ; =0x1180c078
11802a80: add      r2, r4, #0x10000
11802a84: add      r2, r2, #0x2a00
11802a88: ldm      r0, {r0, r1}
11802a8c: strd     r0, r1, [r2, #4]
11802a90: pop      {r3, r4, r5, pc}
11802a94: orrne    ip, r0, r8, ror r0
11802a98: push     {r4, lr}
11802a9c: mov      r4, r0
11802aa0: bl       #0x11800358  ; ->msys::MListWndPBase::applyAnime
11802aa4: add      r0, r4, #0x6c00
11802aa8: pop      {r4, lr}
11802aac: add      r0, r0, #0x3f4
11802ab0: b        #0x11800360  ; ->ad::lyt::Layout::Animate
11802ab4: push     {r4, r5, r6, r7, r8, sb, sl, fp, lr}
11802ab8: sub      sp, sp, #0x184
11802abc: add      r8, r0, #0x6000
11802ac0: mov      r6, r0
11802ac4: mov      ip, r1
11802ac8: str      r1, [r8, #0xff0]
11802acc: ldr      fp, [pc, #0x208]  ; =0x3f62a8 msys::MComSys::_sys
11802ad0: ldr      r0, [r1, #8]
11802ad4: mov      sl, #0
11802ad8: add      r1, r6, #0x6c00
11802adc: cmp      r0, #0
11802ae0: ldreq    r0, [fp]
11802ae4: add      r1, r1, #0x3f4
11802ae8: mov      r3, sl
11802aec: mov      r5, r0
11802af0: streq    r0, [ip, #8]
11802af4: ldr      r0, [pc, #0x1e4]  ; =0x61013
11802af8: add      r2, pc, #0x1e4
11802afc: mov      r4, r1
11802b00: ldrsb    r7, [r0, ip]
11802b04: add      r0, ip, #0x12000
11802b08: add      r0, r0, #0xa30
11802b0c: str      sl, [sp]
11802b10: bl       #0x11800368  ; ->ad::lyt::LytResourceMan::buildLayout
11802b14: add      r0, r6, #0x7000
11802b18: add      r0, r0, #0x30
11802b1c: ldr      r3, [pc, #0x1dc]  ; =0x11802290
11802b20: add      r2, pc, #0x1dc
11802b24: mov      r1, r4
11802b28: str      r0, [sp]
11802b2c: bl       #0x118002b0  ; ->ad::lyt::LytAnim::init
11802b30: add      r0, r6, #0x7000
11802b34: add      r0, r0, #0x4c
11802b38: ldr      r3, [pc, #0x1c0]  ; =0x11802290
11802b3c: add      r2, pc, #0x1c8
11802b40: mov      r1, r4
11802b44: str      r0, [sp, #4]
11802b48: bl       #0x118002b0  ; ->ad::lyt::LytAnim::init
11802b4c: ldr      r0, [sp, #4]
11802b50: vldr     s0, [pc, #0x1c0]  ; =0x3f800000 (1)
11802b54: bl       #0x11800370  ; ->ad::lyt::LytAnim::playAuto
11802b58: add      r0, sp, #8
11802b5c: bl       #0x11800378  ; ->ad::ui::UIListWindowPlusLyt::InitParam
11802b60: mov      r1, #1
11802b64: add      r0, sp, #8
11802b68: bl       #0x11800380  ; ->msys::SetMListWndInitParam
11802b6c: ldr      r0, [pc, #0x1a8]  ; =0xfffb50e8
11802b70: mov      r2, #1
11802b74: sub      sb, r5, r0
11802b78: add      r0, sb, #0x54
11802b7c: str      r0, [sp, #8]
11802b80: ldr      r0, [r4, #0x10]
11802b84: ldr      r1, [r0]
11802b88: ldr      r3, [r1, #0x2c]
11802b8c: add      r1, pc, #0x18c
11802b90: blx      r3
11802b94: str      r0, [sp, #0x40]
11802b98: ldr      r0, [r4, #0x10]
11802b9c: mov      r2, #1
11802ba0: ldr      r1, [r0]
11802ba4: ldr      r3, [r1, #0x2c]
11802ba8: add      r1, pc, #0x178
11802bac: blx      r3
11802bb0: str      r0, [sp, #0x38]
11802bb4: ldr      r0, [r4, #0x10]
11802bb8: mov      r2, #1
11802bbc: ldr      r1, [r0]
11802bc0: ldr      r3, [r1, #0x2c]
11802bc4: add      r1, pc, #0x168
11802bc8: blx      r3
11802bcc: str      r0, [sp, #0x34]
11802bd0: ldr      r0, [sp, #4]
11802bd4: mov      r1, #4
11802bd8: add      r4, r6, #0x4000
11802bdc: str      r0, [sp, #0x68]
11802be0: ldr      r0, [sp]
11802be4: add      r4, r4, #0x2f80
11802be8: strb     r1, [sp, #0x148]
11802bec: str      r0, [sp, #0x64]
11802bf0: add      r0, r5, #0x14800
11802bf4: add      r1, sb, #0x3c
11802bf8: add      r0, r0, #0x7c
11802bfc: str      r4, [sp, #0x144]
11802c00: strd     r0, r1, [sp]
11802c04: add      r3, r5, #0xd0000
11802c08: add      r3, r3, #0x3100
11802c0c: add      r2, r5, #0xd3000
11802c10: add      r1, sp, #8
11802c14: mov      r0, r6
11802c18: strb     sl, [sp, #0x70]
11802c1c: bl       #0x11800388  ; ->msys::MListWndPBase::init
11802c20: ldr      r0, [pc, #0x118]  ; =0x401
11802c24: mov      r5, #0
11802c28: str      r0, [r6, #0x13c]
11802c2c: ldrb     r0, [sp, #0x148]
11802c30: cmp      r0, #0
11802c34: movgt    sb, #1
11802c38: ble      #0x11802cc4
11802c3c: cmp      r7, #0
11802c40: movne    r0, #7
11802c44: moveq    r0, #0
11802c48: add      r0, r0, r5
11802c4c: strb     r0, [r4, #8]
11802c50: ldr      r0, [r8, #0xff0]
11802c54: ldr      r1, [r0, #8]
11802c58: cmp      r1, #0
11802c5c: bne      #0x11802c6c
11802c60: ldr      r1, [pc, #0x74]  ; =0x3f62a8 msys::MComSys::_sys
11802c64: ldr      r1, [r1]
11802c68: str      r1, [r0, #8]
11802c6c: mov      r0, r1
11802c70: ldr      r1, [pc, #0xcc]  ; =0x11814440
11802c74: add      fp, r0, #0xe9000
11802c78: add      r0, r0, #0xe9000
11802c7c: ldr      r1, [r1, r5, lsl #3]
11802c80: add      fp, fp, #0x50
11802c84: add      r0, r0, #0x58
11802c88: bl       #0x11800290  ; ->LMS_GetTextIndexByLabel
11802c8c: mov      r1, r0
11802c90: add      r0, fp, #8
11802c94: bl       #0x11800298  ; ->LMS_GetText
11802c98: mvn      r1, #0
11802c9c: str      r0, [r4, #0x10]
11802ca0: strh     r1, [r4, #4]
11802ca4: strb     sb, [r4, #0xe]
11802ca8: str      r5, [r4], #0xf
11802cac: add      r5, r5, #1
11802cb0: strb     sl, [r4], #5
11802cb4: str      sl, [r4], #8
11802cb8: ldrb     r0, [sp, #0x148]
11802cbc: cmp      r0, r5
11802cc0: bgt      #0x11802c3c
11802cc4: ldr      r0, [pc, #0x74]  ; =0x401
11802cc8: str      r0, [r6, #0x168]
11802ccc: mov      r0, r6
11802cd0: bl       #0x11800390  ; ->msys::MListWndPBase::resetCur
11802cd4: add      sp, sp, #0x184
11802cd8: pop      {r4, r5, r6, r7, r8, sb, sl, fp, pc}
11802cdc: eorseq   r6, pc, r8, lsr #5
11802ce0: andeq    r1, r6, r3, lsl r0
11802ce4: stmdbmi  lr, {r0, r2, r3, r6, r8, fp, lr} ^
11802ce8: strbmi   r4, [sp, #-0x147]
11802cec: ldmdbmi  r5, {r0, r1, r2, r3, r4, r6, r8, sb, sl, lr} ^
11802cf0: mrrcmi   p5, #4, r4, pc, c4
11802cf4: movtpl   r4, #0x9c5f
11802cf8: uqsaxvs  r2, r2, r4
11802cfc: rsbseq   r7, r4, ip, ror #18
11802d00: .word    0x11802290
11802d04: cmnvs    r5, #116, #30
11802d08: andeq    r0, r0, r8, rrx
11802d0c: ldrbmi   r5, [r4, #-0x441]
11802d10: svcmi    #0x49544e
11802d14: andeq    r0, r0, lr, asr #32
11802d18: svclo    #0x800000
11802d1c: .word    0xfffb50e8
11802d20: stclmi   p2, c5, [r1, #-0x118]
11802d24: andeq    r0, r0, r5, asr #32
11802d28: ldrbtvc  r6, [r3], #-0x96c
11802d2c: rsbsvc   r6, r5, #0x7c000001
11802d30: rsbseq   r6, r2, r3, ror pc
11802d34: ldrbtvc  r6, [r3], #-0x96c
11802d38: rsbvc    r7, r3, #0x7c000001
11802d3c: rsbeq    r6, ip, pc, ror #24
11802d40: andeq    r0, r0, r1, lsl #8
11802d44: orrne    r4, r1, r0, asr #8
11802d48: ldr      r1, [pc, #0x5c]  ; =0x1180c8d0
11802d4c: push     {r4, lr}
11802d50: vldr     s0, [pc, #0x58]  ; =0x0 (0)
11802d54: str      r1, [r0]
11802d58: add      r1, r0, #0x7000
11802d5c: add      r1, r1, #0x68
11802d60: vstr     s0, [r1, #0xc]
11802d64: add      r1, r0, #0x7000
11802d68: add      r1, r1, #0x4c
11802d6c: vstr     s0, [r1, #0xc]
11802d70: add      r1, r0, #0x7000
11802d74: add      r1, r1, #0x30
11802d78: add      r0, r0, #0x6c00
11802d7c: vstr     s0, [r1, #0xc]
11802d80: add      r0, r0, #0x3f4
11802d84: bl       #0x11800398  ; ->ad::lyt::Layout
11802d88: ldr      r1, [pc, #0x24]  ; =0x1180cb14
11802d8c: sub      r0, r0, #0x6c00
11802d90: sub      r0, r0, #0x3f4
11802d94: str      r1, [r0], #0x1fc
11802d98: bl       #0x118003a0  ; ->ad::ui::UIListWindowPlusLyt
11802d9c: sub      r0, r0, #0x1fc
11802da0: bl       #0x118003a8  ; ->msys::MListWndPBase
11802da4: pop      {r4, lr}
11802da8: b        #0x11800190  ; ->_ZdlPv
11802dac: ldrdne   ip, sp, [r0, r0]
11802db0: andeq    r0, r0, r0
11802db4: orrne    ip, r0, r4, lsl fp
11802db8: ldr      r1, [pc, #0x58]  ; =0x1180c8d0
11802dbc: push     {r4, lr}
11802dc0: vldr     s0, [pc, #0x54]  ; =0x0 (0)
11802dc4: str      r1, [r0]
11802dc8: add      r1, r0, #0x7000
11802dcc: add      r1, r1, #0x68
11802dd0: vstr     s0, [r1, #0xc]
11802dd4: add      r1, r0, #0x7000
11802dd8: add      r1, r1, #0x4c
11802ddc: vstr     s0, [r1, #0xc]
11802de0: add      r1, r0, #0x7000
11802de4: add      r1, r1, #0x30
11802de8: add      r0, r0, #0x6c00
11802dec: vstr     s0, [r1, #0xc]
11802df0: add      r0, r0, #0x3f4
11802df4: bl       #0x11800398  ; ->ad::lyt::Layout
11802df8: ldr      r1, [pc, #0x20]  ; =0x1180cb14
11802dfc: sub      r0, r0, #0x6c00
11802e00: sub      r0, r0, #0x3f4
11802e04: str      r1, [r0], #0x1fc
11802e08: bl       #0x118003a0  ; ->ad::ui::UIListWindowPlusLyt
11802e0c: pop      {r4, lr}
11802e10: sub      r0, r0, #0x1fc
11802e14: b        #0x118003a8  ; ->msys::MListWndPBase
11802e18: ldrdne   ip, sp, [r0, r0]
11802e1c: andeq    r0, r0, r0
11802e20: orrne    ip, r0, r4, lsl fp
11802e24: push     {r4, r5, r6, r7, r8, sb, sl, fp, lr}
11802e28: mov      r4, r0
11802e2c: vpush    {d8, d9}
11802e30: sub      sp, sp, #0xf4
11802e34: add      r0, sp, #0x20
11802e38: bl       #0x118003b0  ; ->ad::lyt::LytLocalize
11802e3c: add      r2, r4, #0x12800
11802e40: add      r2, r2, #0x3b4
11802e44: str      r2, [sp, #0x60]
11802e48: ldr      r1, [r2, #0x150]
11802e4c: add      r0, sp, #0x20
11802e50: bl       #0x118003b8  ; ->ad::lyt::LytLocalize::localize
11802e54: add      r5, r4, #0x12c00
11802e58: add      r5, r5, #0x35c
11802e5c: add      r0, sp, #0x20
11802e60: ldr      r1, [r5, #0x150]
11802e64: bl       #0x118003b8  ; ->ad::lyt::LytLocalize::localize
11802e68: vldr     s16, [pc, #0x39c]  ; =0x0 (0)
11802e6c: vstr     s16, [sp, #0x30]
11802e70: ldr      r2, [sp, #0x60]
11802e74: ldr      r0, [r4, #4]
11802e78: add      r1, r2, #4
11802e7c: add      r0, r0, #4
11802e80: ldm      r1, {r3, ip}
11802e84: str      ip, [r3, #4]
11802e88: ldr      r1, [r2, #4]
11802e8c: str      r1, [ip]
11802e90: adds     r1, r2, #4
11802e94: beq      #0x11802eac
11802e98: ldr      r3, [r0]
11802e9c: str      r0, [r1, #4]
11802ea0: str      r3, [r1]
11802ea4: str      r1, [r3, #4]
11802ea8: str      r1, [r0]
11802eac: mov      r0, #0x400
11802eb0: str      r0, [r2, #0x13c]
11802eb4: ldr      r0, [r4, #4]
11802eb8: add      r1, r0, #0xc
11802ebc: add      r0, r5, #4
11802ec0: ldrd     r2, r3, [r0]
11802ec4: str      r3, [r2, #4]
11802ec8: ldr      r0, [r5, #4]
11802ecc: str      r0, [r3]
11802ed0: adds     r0, r5, #4
11802ed4: beq      #0x11802eec
11802ed8: ldr      r2, [r1]
11802edc: str      r1, [r0, #4]
11802ee0: str      r2, [r0]
11802ee4: str      r0, [r2, #4]
11802ee8: str      r0, [r1]
11802eec: ldr      sb, [pc, #0x31c]  ; =0x401
11802ef0: add      r8, r4, #0x37000
11802ef4: add      r8, r8, #0x4c
11802ef8: str      sb, [r5, #0x13c]
11802efc: ldr      r2, [r4, #4]
11802f00: str      r2, [sp, #0xc]
11802f04: ldr      r0, [r4, #8]
11802f08: cmp      r0, #0
11802f0c: bne      #0x11802f1c
11802f10: ldr      r0, [pc, #0x2fc]  ; =0x3f62a8 msys::MComSys::_sys
11802f14: ldr      r0, [r0]
11802f18: str      r0, [r4, #8]
11802f1c: add      r0, r0, #0xe9000
11802f20: add      r7, r8, #0x6c00
11802f24: ldr      r1, [r0, #0x4c]
11802f28: ldr      r0, [r2, #0x18]
11802f2c: add      r7, r7, #0x2ec
11802f30: str      r1, [sp]
11802f34: mov      r6, #0
11802f38: stm      r7!, {r0, r6, sb}
11802f3c: add      fp, r8, #0x6c00
11802f40: str      sb, [r7, #-0x48]
11802f44: vstr     s16, [fp, #0x2b4]
11802f48: mov      r1, #1
11802f4c: vstr     s16, [fp, #0x2b8]
11802f50: strb     r1, [r7, #-0x20]
11802f54: mvn      sl, #0
11802f58: strb     r6, [r7, #-0x1f]
11802f5c: str      sl, [r7, #-0x18]
11802f60: sub      r1, r7, #0x28
11802f64: str      sl, [r7, #-0x14]
11802f68: add      r2, r8, #0x6c00
11802f6c: add      r2, r2, #0x2e8
11802f70: sub      r7, r7, #0xc00
11802f74: add      r0, r8, #0x14c
11802f78: sub      r7, r7, #0x2f8
11802f7c: stm      r1, {r2, r6}
11802f80: bl       #0x118003c0  ; ->Message::init
11802f84: ldr      r1, [sp]
11802f88: add      r0, r8, #0x14c
11802f8c: bl       #0x118003c8  ; ->Message::setMsgDat
11802f90: mov      r0, r8
11802f94: nop      
11802f98: bl       #0x11806968
11802f9c: str      sb, [r7, #0xefc]
11802fa0: vstr     s16, [fp, #0x300]
11802fa4: mov      r0, #1
11802fa8: vstr     s16, [fp, #0x304]
11802fac: strb     r0, [r7, #0xf24]
11802fb0: strb     r6, [r7, #0xf25]
11802fb4: str      sl, [r7, #0xf2c]
11802fb8: str      sl, [r7, #0xf30]
11802fbc: add      r7, r7, #0xc00
11802fc0: add      r1, r8, #0x6c00
11802fc4: add      r7, r7, #0x31c
11802fc8: add      r1, r1, #0x334
11802fcc: stm      r7, {r1, r6}
11802fd0: ldr      r0, [sp, #0xc]
11802fd4: add      r1, r0, #0xc
11802fd8: add      r0, r8, #4
11802fdc: ldrd     r2, r3, [r0]
11802fe0: str      r3, [r2, #4]
11802fe4: ldr      r0, [r8, #4]
11802fe8: str      r0, [r3]
11802fec: adds     r0, r8, #4
11802ff0: beq      #0x11803008
11802ff4: ldr      r2, [r1]
11802ff8: str      r1, [r0, #4]
11802ffc: str      r2, [r0]
11803000: str      r0, [r2, #4]
11803004: str      r0, [r1]
11803008: str      sb, [r8, #0x13c]
1180300c: add      r1, r4, #0x3dc00
11803010: add      r1, r1, #0x384
11803014: mov      r3, #0
11803018: add      r2, pc, #0x1f8
1180301c: mov      r0, r5
11803020: str      r6, [sp]
11803024: str      r1, [sp, #0xe4]
11803028: str      r6, [sp, #4]
1180302c: bl       #0x11800228  ; ->msys::MLyt::attachMChr
11803030: ldr      r0, [sp, #0xe4]
11803034: add      r1, r4, #0x45000
11803038: add      r1, r1, #0x110
1180303c: mov      r3, #0
11803040: strb     r6, [r0, #0x141]
11803044: add      r2, pc, #0x1e0
11803048: mov      r7, r1
1180304c: mov      r0, r5
11803050: str      r6, [sp]
11803054: str      r6, [sp, #4]
11803058: bl       #0x11800228  ; ->msys::MLyt::attachMChr
1180305c: add      r0, r4, #0x4c000
11803060: add      r0, r0, #0x194
11803064: strb     r6, [r7, #0x141]
11803068: mov      r1, r4
1180306c: str      r0, [sp, #0xc4]
11803070: bl       #0x118019c0
11803074: ldr      r0, [r4, #4]
11803078: add      r1, r4, #0x1a400
1180307c: add      r1, r1, #0x94
11803080: add      r2, r4, #0x1a400
11803084: ldr      r0, [r0, #0x18]
11803088: str      sb, [r1], #-0xc
1180308c: add      r7, r4, #0x13800
11803090: stm      r1, {r0, r6}
11803094: add      r2, r2, #0x54
11803098: add      r7, r7, #0x54
1180309c: add      r0, r4, #0x13000
118030a0: mov      fp, r7
118030a4: vstr     s16, [r2, #0x3c]
118030a8: add      r0, r0, #0x9a0
118030ac: bl       #0x11800288  ; ->MessageSimple::init
118030b0: mov      r0, r7
118030b4: nop      
118030b8: bl       #0x11806968
118030bc: add      r0, r4, #0x19000
118030c0: mov      r7, #1
118030c4: add      sl, r4, #0x19000
118030c8: strb     r7, [r0, #0x45c]
118030cc: add      r8, r4, #0x13000
118030d0: add      sl, sl, #0x9a0
118030d4: strb     r7, [r0, #0x45d]
118030d8: add      r8, r8, #0x9a0
118030dc: ldr      r1, [pc, #0x154]  ; =0xe6e6e6ff
118030e0: mov      r2, #0
118030e4: mov      r0, r8
118030e8: strb     r7, [sl, #0xad9]
118030ec: bl       #0x118002a8  ; ->MessageWriter::setFontColor
118030f0: mov      r0, #3
118030f4: strb     r0, [sl, #0xad8]
118030f8: ldr      r0, [pc, #0x13c]  ; =0x5828
118030fc: ldr      r1, [pc, #0x13c]  ; =0x3fc0f8
11803100: vldr     s17, [pc, #0x13c]  ; =0x3c23d70a (0.01)
11803104: str      r1, [r0, r8]
11803108: add      r8, r4, #0x13000
1180310c: add      r8, r8, #0x920
11803110: mov      r0, r8
11803114: bl       #0x11800200  ; ->MoveVBase::stop
11803118: vstr     s16, [r8, #0x1c]
1180311c: add      r0, r8, #0x20
11803120: add      r3, pc, #0x120
11803124: vstmia   r0, {s16, s17}
11803128: add      r2, pc, #0x128
1180312c: ldr      r0, [r8, #0x1c]
11803130: mov      r1, fp
11803134: str      r0, [r8, #4]!
11803138: add      r8, r8, #4
1180313c: mov      r0, r5
11803140: vstmia   r8, {s16, s17}
11803144: str      r6, [sp]
11803148: str      r6, [sp, #4]
1180314c: bl       #0x11800228  ; ->msys::MLyt::attachMChr
11803150: ldr      r0, [r4, #4]
11803154: add      r1, r4, #0x21000
11803158: add      r1, r1, #0xd8
1180315c: add      r2, r4, #0x21000
11803160: ldr      r0, [r0, #0x18]
11803164: str      sb, [r1], #-0xc
11803168: add      r8, r4, #0x1a400
1180316c: stm      r1, {r0, r6}
11803170: add      r2, r2, #0x98
11803174: add      r8, r8, #0x98
11803178: add      r0, r4, #0x1a400
1180317c: mov      fp, r8
11803180: vstr     s16, [r2, #0x3c]
11803184: add      r0, r0, #0x1e4
11803188: bl       #0x11800288  ; ->MessageSimple::init
1180318c: mov      r0, r8
11803190: nop      
11803194: bl       #0x11806968
11803198: add      r0, r4, #0x20000
1180319c: add      sl, r4, #0x20400
118031a0: strb     r6, [r0, #0xa0]
118031a4: add      r8, r4, #0x1a400
118031a8: add      sl, sl, #0x1e4
118031ac: strb     r7, [r0, #0xa1]
118031b0: add      r8, r8, #0x1e4
118031b4: ldr      r1, [pc, #0xac]  ; =0x373737ff
118031b8: mov      r2, #0
118031bc: mov      r0, r8
118031c0: strb     r7, [sl, #0xad9]
118031c4: bl       #0x118002a8  ; ->MessageWriter::setFontColor
118031c8: mov      r0, #4
118031cc: ldr      r1, [pc, #0x68]  ; =0x5828
118031d0: strb     r0, [sl, #0xad8]
118031d4: ldr      r0, [pc, #0x90]  ; =0x3fc140
118031d8: vldr     s18, [pc, #0x90]  ; =0xc30c0000 (-140)
118031dc: str      r0, [r1, r8]
118031e0: add      r8, r4, #0x1a400
118031e4: add      r8, r8, #0x164
118031e8: mov      r0, r8
118031ec: bl       #0x11800200  ; ->MoveVBase::stop
118031f0: vstr     s18, [r8, #0x1c]
118031f4: vstr     s18, [r8, #4]
118031f8: add      r0, r8, #0x20
118031fc: add      r8, r8, #8
11803200: vstmia   r0, {s16, s17}
11803204: vstmia   r8, {s16, s17}
11803208: b        #0x11803274
1180320c: andeq    r0, r0, r0
11803210: andeq    r0, r0, r1, lsl #8
11803214: eorseq   r6, pc, r8, lsr #5
11803218: svcpl    #0x534e49
1180321c: ldrbpl   r4, [r3], #-0x94c
11803220: mcrmi    p13, #2, r4, c9, c15, #2
11803224: stclmi   p7, c4, [r1, #-0x124]
11803228: andeq    r0, r0, r5, asr #32
1180322c: svcpl    #0x534e49
11803230: ldrbpl   r4, [r3], #-0x94c
11803234: andeq    r0, r0, r0
11803238: .word    0xe6e6e6ff
1180323c: andeq    r5, r0, r8, lsr #16
11803240: ldrshteq ip, [pc], -r8
11803244: stclo    p7, c13, [r3], #-0x28
11803248: strbmi   r5, [sb], #-0x547
1180324c: ldmdapl  r4, {r0, r2, r6, r8, sb, sl, fp, ip, lr} ^
11803250: qdsubvs  r5, r4, r2
11803254: andeq    r6, r0, r3, ror r5
11803258: svcpl    #0x534e49
1180325c: mrrcmi   p9, #5, r4, r4, c4
11803260: ldrbmi   r5, [r4, #-0xf45]
11803264: andeq    r5, r0, r8, asr r4
11803268: .word    0x373737ff
1180326c: eorseq   ip, pc, r0, asr #2
11803270: movwgt   r0, #0xc000
11803274: sub      r3, pc, #0x34
11803278: add      r2, pc, #0x3a8
1180327c: mov      r1, fp
11803280: mov      r0, r5
11803284: str      r6, [sp]
11803288: str      r6, [sp, #4]
1180328c: bl       #0x11800228  ; ->msys::MLyt::attachMChr
11803290: ldr      r0, [r4, #8]
11803294: cmp      r0, #0
11803298: bne      #0x118032a8
1180329c: ldr      r0, [pc, #-0x90]  ; =0x3f62a8 msys::MComSys::_sys
118032a0: ldr      r0, [r0]
118032a4: str      r0, [r4, #8]
118032a8: mov      r1, r0
118032ac: ldr      r0, [pc, #0x384]  ; =0x60b04
118032b0: mov      r3, fp
118032b4: mov      r2, r5
118032b8: add      r0, r0, r4
118032bc: str      r0, [sp, #0xd0]
118032c0: bl       #0x118020bc
118032c4: add      r0, sp, #0x78
118032c8: nop      
118032cc: bl       #0x11800270  ; ->ad::lyt::LytNumReel3::InitParam
118032d0: ldr      r0, [r4, #8]
118032d4: cmp      r0, #0
118032d8: bne      #0x118032e8
118032dc: ldr      r0, [pc, #-0xd0]  ; =0x3f62a8 msys::MComSys::_sys
118032e0: ldr      r0, [r0]
118032e4: str      r0, [r4, #8]
118032e8: mov      ip, #0x11
118032ec: add      r0, r0, #0x800
118032f0: add      r1, sp, #0x78
118032f4: mov      r2, #0
118032f8: mov      r3, #2
118032fc: add      r0, r0, #0x44
11803300: str      ip, [sp]
11803304: bl       #0x11800278  ; ->msys::MLytNumRes::set
11803308: ldr      r0, [pc, #0x32c]  ; =0x3f95f0 gGameWork
1180330c: strb     r6, [sp, #0xa9]
11803310: bl       #0x118003d0  ; ->GameWork::getCoin
11803314: str      r0, [sp, #0x8c]
11803318: ldr      r0, [r4, #8]
1180331c: cmp      r0, #0
11803320: bne      #0x11803330
11803324: ldr      r0, [pc, #-0x118]  ; =0x3f62a8 msys::MComSys::_sys
11803328: ldr      r0, [r0]
1180332c: str      r0, [r4, #8]
11803330: add      r1, pc, #0x318
11803334: add      r2, r0, #0xd3000
11803338: add      r3, sp, #4
1180333c: str      r1, [sp]
11803340: add      r0, pc, #0x2f8
11803344: stm      r3, {r0, r6}
11803348: add      r0, r4, #0x35400
1180334c: mov      r3, r5
11803350: add      r1, sp, #0x78
11803354: add      r0, r0, #0x1a8
11803358: str      r6, [sp, #0xc]
1180335c: bl       #0x11800280  ; ->msys::MLytNum::init
11803360: add      r8, r4, #0x27000
11803364: add      r8, r8, #0xd20
11803368: str      r8, [sp, #0x74]
1180336c: ldr      r0, [r4, #4]
11803370: add      r1, r4, #0x2e000
11803374: add      r1, r1, #0x960
11803378: add      r2, r4, #0x2e000
1180337c: ldr      r0, [r0, #0x18]
11803380: str      sb, [r1], #-0xc
11803384: add      r2, r2, #0x920
11803388: stm      r1, {r0, r6}
1180338c: add      r0, r4, #0x27c00
11803390: vstr     s16, [r2, #0x3c]
11803394: add      r0, r0, #0x26c
11803398: bl       #0x11800288  ; ->MessageSimple::init
1180339c: mov      r0, r8
118033a0: nop      
118033a4: bl       #0x11806968
118033a8: add      r0, r4, #0x2d000
118033ac: mov      r3, #0
118033b0: strb     r7, [r0, #0x928]
118033b4: strb     r7, [r0, #0x929]
118033b8: ldr      r1, [sp, #0x74]
118033bc: add      r2, pc, #0x298
118033c0: mov      r0, r5
118033c4: str      r6, [sp]
118033c8: str      r6, [sp, #4]
118033cc: bl       #0x11800228  ; ->msys::MLyt::attachMChr
118033d0: ldr      r0, [r4, #4]
118033d4: add      r2, r4, #0x35400
118033d8: add      r2, r2, #0x1a4
118033dc: add      r3, r4, #0x35400
118033e0: ldr      r1, [r0, #0x18]
118033e4: mov      r0, #0x400
118033e8: str      r0, [r2], #-0xc
118033ec: add      r3, r3, #0x164
118033f0: stm      r2, {r1, r6}
118033f4: add      r8, r4, #0x2e800
118033f8: add      r0, r4, #0x2e000
118033fc: add      r8, r8, #0x164
11803400: vstr     s16, [r3, #0x3c]
11803404: add      r0, r0, #0xab0
11803408: bl       #0x11800288  ; ->MessageSimple::init
1180340c: mov      r0, r8
11803410: nop      
11803414: bl       #0x11806968
11803418: add      r0, r4, #0x34000
1180341c: mov      r3, #0
11803420: strb     r7, [r0, #0x56c]
11803424: strb     r7, [r0, #0x56d]
11803428: ldr      r0, [sp, #0x60]
1180342c: add      r2, pc, #0x228
11803430: mov      r1, r8
11803434: str      r6, [sp]
11803438: str      r6, [sp, #4]
1180343c: bl       #0x11800228  ; ->msys::MLyt::attachMChr
11803440: ldr      r0, [pc, #0x228]  ; =0x1180c37c
11803444: add      fp, r4, #0x12800
11803448: mov      sl, sp
1180344c: add      fp, fp, #0x214
11803450: vldmia   r0, {s0, s1, s2, s3, s4, s5, s6}
11803454: mov      r8, #0
11803458: vstmia   sp, {s0, s1, s2, s3, s4, s5, s6}
1180345c: mov      r0, fp
11803460: ldr      r1, [sl, r8, lsl #2]
11803464: bl       #0x118003d8  ; ->ad::ctrl::ButtonGroup::FindButtonByName
11803468: add      r1, r4, r8, lsl #2
1180346c: add      sb, r1, #0x13000
11803470: ldr      r1, [pc, #0x1fc]  ; =0x11808a3c
11803474: mov      r2, r4
11803478: str      r0, [sb, #0x340]
1180347c: bl       #0x118003e0  ; ->ad::ctrl::AnimButton::SetStateChangeCallback
11803480: ldr      r0, [sb, #0x340]
11803484: str      r8, [r0, #0x48]
11803488: ldr      r0, [sb, #0x340]
1180348c: ldr      r1, [r0]
11803490: ldr      r2, [r1, #0x28]
11803494: mov      r1, #0
11803498: blx      r2
1180349c: add      r8, r8, #1
118034a0: cmp      r8, #7
118034a4: blt      #0x1180345c
118034a8: mov      r3, #0
118034ac: mov      r2, r3
118034b0: add      r1, pc, #0x1c0
118034b4: mov      r0, r5
118034b8: bl       #0x118002f0  ; ->msys::MLyt::getParts
118034bc: ldrb     r1, [r0, #0x44]
118034c0: and      r1, r1, #0xfe
118034c4: strb     r1, [r0, #0x44]
118034c8: ldr      r0, [r4, #8]
118034cc: cmp      r0, #0
118034d0: bne      #0x118034e0
118034d4: ldr      r0, [pc, #-0x2c8]  ; =0x3f62a8 msys::MComSys::_sys
118034d8: ldr      r0, [r0]
118034dc: str      r0, [r4, #8]
118034e0: add      r6, r4, #0x13000
118034e4: add      r6, r6, #0x304
118034e8: mov      r7, r0
118034ec: str      r6, [sp, #0xc0]
118034f0: ldr      r0, [r0, #4]
118034f4: bl       #0x118003e8  ; ->ad::fw::TaskBase::isFps30
118034f8: cmp      r0, #0
118034fc: ldr      r0, [r6]
11803500: vldr     s17, [pc, #0x17c]  ; =0x3f800000 (1)
11803504: add      r1, r7, #0xe9000
11803508: vldrne   s0, [pc, #0x178]  ; =0x40000000 (2)
1180350c: ldr      r2, [r0, #8]
11803510: vmoveq.f32 s0, s17
11803514: add      r1, r1, #0x124
11803518: mov      r0, r6
1180351c: blx      r2
11803520: ldr      r7, [sp, #0xc0]
11803524: mov      fp, sp
11803528: mov      sl, #3
1180352c: mov      r0, r7
11803530: mov      r6, #0
11803534: ldr      r1, [r0, #0x30]!
11803538: cmp      r1, #0
1180353c: moveq    sb, #0
11803540: beq      #0x11803564
11803544: ldr      r1, [r0, #4]
11803548: cmp      r1, #0
1180354c: moveq    sb, #1
11803550: beq      #0x11803564
11803554: ldr      r0, [r0, #8]
11803558: cmp      r0, #0
1180355c: moveq    sb, #2
11803560: mvnne    sb, #0
11803564: add      r0, sb, r6
11803568: mov      r3, #0
1180356c: sxtb     r8, r0
11803570: ldr      r1, [fp, r6, lsl #2]
11803574: mov      r2, r3
11803578: mov      r0, r5
1180357c: bl       #0x118002f0  ; ->msys::MLyt::getParts
11803580: add      r1, r7, #0x30
11803584: add      r6, r6, #1
11803588: cmp      r6, sl
1180358c: str      r0, [r1, r8, lsl #2]
11803590: blo      #0x11803564
11803594: ldr      r0, [sp, #0xc0]
11803598: mov      r1, #0
1180359c: bl       #0x118003f0  ; ->msys::MCursorBase::setVisible
118035a0: add      r2, r4, #0x13000
118035a4: ldr      r0, [sp, #0xd0]
118035a8: add      r2, r2, #0x354
118035ac: ldm      r2, {r1, r2}
118035b0: add      r0, r0, #0x400
118035b4: add      r0, r0, #0x88
118035b8: stm      r0, {r1, r2}
118035bc: mov      r2, #0
118035c0: mov      r1, #9
118035c4: mov      r0, r5
118035c8: bl       #0x118003f8  ; ->msys::MLyt::setAnimeInfo
118035cc: mov      r2, #0
118035d0: mov      r1, #0xa
118035d4: mov      r0, r5
118035d8: bl       #0x118003f8  ; ->msys::MLyt::setAnimeInfo
118035dc: mov      r3, #0
118035e0: add      r2, pc, #0xa4
118035e4: add      r1, pc, #0xb0
118035e8: mov      r0, r5
118035ec: bl       #0x11800338  ; ->msys::MLyt::createAnimeAutoSlot
118035f0: sxth     r1, r0
118035f4: mov      r0, r5
118035f8: bl       #0x11800328  ; ->msys::MLyt::getAnim
118035fc: ldr      r1, [pc, #0xa0]  ; =0x60ff0
11803600: mov      sl, #0
11803604: str      r0, [r1, r4]
11803608: add      r1, sp, #0x48
1180360c: strb     sl, [sp, #0x44]
11803610: mov      r0, #1
11803614: vstmia   r1, {s16, s17}
11803618: vstr     s16, [sp, #0x50]
1180361c: strh     r0, [sp, #0x54]
11803620: strh     sl, [sp, #0x56]
11803624: b        #0x118036a8
11803628: svcpl    #0x534e49
1180362c: ldrbpl   r4, [r8], #-0x554
11803630: ldmdbmi  r5, {r0, r1, r2, r3, r4, r6, r8, sb, sl, lr} ^
11803634: andeq    r4, r0, r4, asr #10
11803638: andeq    r0, r6, r4, lsl #22
1180363c: ldrshteq sb, [pc], -r0
11803640: svcpl    #0x6e7462
11803644: cdpmi    p15, #4, c4, c9, c3, #2
11803648: stclvs   p1, c6, [ip], #-0x17c
1180364c: andeq    r0, r0, r0
11803650: svcpl    #0x534e49
11803654: cdpmi    p15, #5, c4, c5, c3, #2
11803658: andeq    r0, r0, r4, asr r0
1180365c: svcpl    #0x534e49
11803660: stclmi   p14, c4, [r5, #-0x114]
11803664: qdaddmi  r5, sb, lr
11803668: ldrbpl   r4, [pc], #-0x54d
1180366c: subseq   r5, r4, r5, asr #16
11803670: orrne    ip, r0, ip, ror r3
11803674: orrne    r8, r0, ip, lsr sl
11803678: svcpl    #0x6e7462
1180367c: strbmi   r5, [sb], #-0x547
11803680: andeq    r0, r0, r5, asr #32
11803684: svclo    #0x800000
11803688: andmi    r0, r0, r0
1180368c: svcpl    #0x6e7462
11803690: ldrbpl   r4, [r8], #-0x54e
11803694: strbvs   r6, [r7, #-0x170]!
11803698: andeq    r0, r0, r0
1180369c: subpl    r4, pc, ip, asr #30
118036a0: andeq    r0, r0, r0
118036a4: strdeq   r0, r1, [r6], -r0
118036a8: ldr      r0, [sp, #0x60]
118036ac: str      sl, [sp, #0x58]
118036b0: str      sl, [sp, #0x5c]
118036b4: sub      r3, pc, #0x70
118036b8: ldr      r1, [r0, #0x150]
118036bc: add      r2, pc, #0x3b0
118036c0: add      r0, sp, #0x44
118036c4: bl       #0x118002b0  ; ->ad::lyt::LytAnim::init
118036c8: ldr      r0, [sp, #0x58]
118036cc: add      r6, sp, #0x44
118036d0: bl       #0x118002b8  ; ->ad::lyt::AnimTransform::GetFrameSize
118036d4: vmov     s0, r0
118036d8: mov      r0, r6
118036dc: vcvt.f32.u32 s0, s0
118036e0: bl       #0x118002c0  ; ->ad::lyt::LytAnim::stopAndSetFrm
118036e4: mov      r1, #1
118036e8: add      r0, sp, #0x44
118036ec: bl       #0x118002c8  ; ->ad::lyt::LytAnim::term
118036f0: ldr      r0, [sp, #0x60]
118036f4: sub      r3, pc, #0xb0
118036f8: add      r2, pc, #0x37c
118036fc: ldr      r1, [r0, #0x150]
11803700: ldr      r0, [pc, #0x380]  ; =0x60fb8
11803704: add      r0, r0, r4
11803708: mov      r6, r0
1180370c: bl       #0x118002b0  ; ->ad::lyt::LytAnim::init
11803710: add      r7, r4, #0x61000
11803714: ldrsb    r0, [r7, #0x13]
11803718: vmov     s0, r0
1180371c: mov      r0, r6
11803720: vcvt.f32.s32 s0, s0
11803724: bl       #0x118002c0  ; ->ad::lyt::LytAnim::stopAndSetFrm
11803728: ldr      r0, [pc, #0x368]  ; =0xfff9f02c
1180372c: ldr      r1, [r5, #0x150]
11803730: add      r3, pc, #0x34c
11803734: sub      r0, r4, r0
11803738: add      r2, pc, #0x34c
1180373c: mov      r6, r0
11803740: bl       #0x118002b0  ; ->ad::lyt::LytAnim::init
11803744: ldrsb    r0, [r7, #0x13]
11803748: vmov     s0, r0
1180374c: mov      r0, r6
11803750: vcvt.f32.s32 s0, s0
11803754: bl       #0x118002c0  ; ->ad::lyt::LytAnim::stopAndSetFrm
11803758: ldr      r0, [sp, #0x60]
1180375c: add      r3, pc, #0x320
11803760: add      r2, pc, #0x334
11803764: ldr      r1, [r0, #0x150]
11803768: ldr      r0, [pc, #0x33c]  ; =0x60f9c
1180376c: add      r0, r0, r4
11803770: mov      r8, r0
11803774: bl       #0x118002b0  ; ->ad::lyt::LytAnim::init
11803778: ldrsb    r0, [r7, #0x13]
1180377c: add      r1, r4, #0x61000
11803780: add      r1, r1, #0x14
11803784: ldrsb    r0, [r0, r1]
11803788: vmov     s0, r0
1180378c: mov      r0, r8
11803790: vcvt.f32.s32 s0, s0
11803794: bl       #0x118002c0  ; ->ad::lyt::LytAnim::stopAndSetFrm
11803798: ldr      r1, [r5, #0x150]
1180379c: add      r3, pc, #0x2e0
118037a0: add      r2, pc, #0x2cc
118037a4: add      r0, sp, #0x44
118037a8: bl       #0x118002b0  ; ->ad::lyt::LytAnim::init
118037ac: ldr      r0, [sp, #0x58]
118037b0: add      r6, sp, #0x44
118037b4: bl       #0x118002b8  ; ->ad::lyt::AnimTransform::GetFrameSize
118037b8: vmov     s0, r0
118037bc: mov      r0, r6
118037c0: vcvt.f32.u32 s0, s0
118037c4: bl       #0x118002c0  ; ->ad::lyt::LytAnim::stopAndSetFrm
118037c8: mov      r1, #1
118037cc: add      r0, sp, #0x44
118037d0: bl       #0x118002c8  ; ->ad::lyt::LytAnim::term
118037d4: mov      r0, r4
118037d8: nop      
118037dc: bl       #0x11805fa4
118037e0: vstr     s16, [sp, #0x50]
118037e4: ldrb     r0, [r7, #0x13]
118037e8: mov      r6, #0
118037ec: cmp      r0, #0
118037f0: beq      #0x11803884
118037f4: rsb      r0, r6, r6, lsl #5
118037f8: add      r0, r0, r6, lsl #6
118037fc: mov      r1, #0x2e
11803800: add      sb, r4, r0, lsl #2
11803804: add      r0, sb, #0x36400
11803808: add      r0, r0, #0x6c
1180380c: bl       #0x118002d8  ; ->msys::MDfxChr::playDfx
11803810: ldr      r1, [pc, #0x298]  ; =0x365c0
11803814: add      r2, r6, #1
11803818: mvn      r0, #0
1180381c: and      r6, r2, #0xff
11803820: ldr      r1, [r1, sb]
11803824: cmp      r6, #4
11803828: strh     r0, [r1, #0xf2]
1180382c: blo      #0x118037f4
11803830: nop      
11803834: bl       #0x11800400  ; ->GameMain::GameModeOld
11803838: cmp      r0, #0xa
1180383c: mov      r6, r0
11803840: add      sb, r4, #0x10000
11803844: cmpne    r6, #0
11803848: add      sb, sb, #0x2a00
1180384c: beq      #0x118038e4
11803850: ldr      r0, [sp, #0xe4]
11803854: bl       #0x11800408  ; ->msys::MListWndPBase::getListWnd
11803858: ldr      r1, [r0]
1180385c: ldr      r2, [r1, #0x28]
11803860: mov      r1, #0
11803864: blx      r2
11803868: bl       #0x11800410  ; ->col::GetBootInfo
1180386c: nop      
11803870: nop      
11803874: bl       #0x11800418  ; ->col::BootInfo::saveBgm
11803878: ldr      r0, [pc, #0x234]  ; =0x1180c060
1180387c: ldm      r0, {r0, r1}
11803880: b        #0x11803f34
11803884: rsb      r0, r6, r6, lsl #5
11803888: add      r0, r0, r6, lsl #6
1180388c: mov      r1, #0x29
11803890: add      sb, r4, r0, lsl #2
11803894: add      r0, sb, #0x35800
11803898: add      r0, r0, #0x208
1180389c: bl       #0x118002d8  ; ->msys::MDfxChr::playDfx
118038a0: ldr      r1, [pc, #0x210]  ; =0x35b5c
118038a4: add      r2, r6, #1
118038a8: mvn      r0, #0
118038ac: and      r6, r2, #0xff
118038b0: ldr      r1, [r1, sb]
118038b4: cmp      r6, #6
118038b8: strh     r0, [r1, #0xf2]
118038bc: blo      #0x11803884
118038c0: add      r0, r4, #0x36000
118038c4: mov      r1, #0x2b
118038c8: add      r0, r0, #0x2f0
118038cc: bl       #0x118002d8  ; ->msys::MDfxChr::playDfx
118038d0: ldr      r0, [pc, #0x1e4]  ; =0x36444
118038d4: ldr      r1, [r0, r4]
118038d8: mvn      r0, #0
118038dc: strh     r0, [r1, #0xf2]
118038e0: b        #0x11803830
118038e4: mov      r0, #0
118038e8: strb     r0, [r7, #0x12]
118038ec: strb     r0, [r7, #0x11]
118038f0: bl       #0x11800410  ; ->col::GetBootInfo
118038f4: cmp      r6, #0xa
118038f8: ldr      r6, [pc, #0x1c0]  ; =0x20d
118038fc: ldrsb    r6, [r0, r6]
11803900: beq      #0x11803b04
11803904: bl       #0x11800420  ; ->hb::GetColiseumResult
11803908: cmp      r0, #1
1180390c: ldr      fp, [pc, #0x1b0]  ; =0x1180c32c
11803910: movne    r0, #0
11803914: cmp      r0, #0
11803918: strb     r0, [r7, #0x10]
1180391c: beq      #0x11804038
11803920: ldr      r0, [sp, #0xe4]
11803924: and      r8, r6, #0xff
11803928: bl       #0x11800408  ; ->msys::MListWndPBase::getListWnd
1180392c: ldr      r1, [r0]
11803930: ldr      r2, [r1, #0x28]
11803934: mov      r1, r8
11803938: blx      r2
1180393c: ldrb     r0, [r7, #0x13]
11803940: mov      r2, #0
11803944: adds     r1, r0, #0
11803948: ldr      r0, [pc, #-0x314]  ; =0x3f95f0 gGameWork
1180394c: movne    r1, #0xa
11803950: add      r0, r0, r1, lsl #1
11803954: add      r0, r0, #0x7f0
11803958: add      sl, r0, r6, lsl #1
1180395c: ldrsh    r0, [sl]
11803960: lsr      r0, r0, #0x1f
11803964: strb     r0, [r7, #0x11]
11803968: strb     r2, [r7, #0x12]
1180396c: ldrb     r1, [r7, #0x10]
11803970: cmp      r1, #0
11803974: beq      #0x11803f2c
11803978: cmp      r0, #0
1180397c: beq      #0x1180400c
11803980: ldr      r1, [r5, #0x150]
11803984: add      lr, sp, #4
11803988: mov      r8, #1
1180398c: vstmia   lr, {s16, s17}
11803990: add      ip, pc, #0x130
11803994: vstr     s16, [sp, #0xc]
11803998: strh     r8, [sp, #0x10]
1180399c: strh     r2, [sp, #0x12]
118039a0: mov      r0, sp
118039a4: add      r3, pc, #0xd8
118039a8: mov      r2, ip
118039ac: bl       #0x118002b0  ; ->ad::lyt::LytAnim::init
118039b0: ldr      r0, [sp, #0x14]
118039b4: str      sp, [sp, #0x1c]
118039b8: bl       #0x118002b8  ; ->ad::lyt::AnimTransform::GetFrameSize
118039bc: vmov     s0, r0
118039c0: ldr      r0, [sp, #0x1c]
118039c4: vcvt.f32.u32 s0, s0
118039c8: bl       #0x118002c0  ; ->ad::lyt::LytAnim::stopAndSetFrm
118039cc: mov      r1, #1
118039d0: mov      r0, sp
118039d4: bl       #0x118002c8  ; ->ad::lyt::LytAnim::term
118039d8: ldr      r1, [r5, #0x150]
118039dc: add      r3, pc, #0xa0
118039e0: add      r2, pc, #0xf8
118039e4: mov      r0, sp
118039e8: bl       #0x118002b0  ; ->ad::lyt::LytAnim::init
118039ec: add      r0, r6, #7
118039f0: vmov     s0, r0
118039f4: mov      r0, sp
118039f8: vcvt.f32.s32 s0, s0
118039fc: bl       #0x118002c0  ; ->ad::lyt::LytAnim::stopAndSetFrm
11803a00: mov      r1, #1
11803a04: mov      r0, sp
11803a08: bl       #0x118002c8  ; ->ad::lyt::LytAnim::term
11803a0c: ldr      r1, [r5, #0x150]
11803a10: add      r3, pc, #0x6c
11803a14: add      r2, pc, #0xd0
11803a18: mov      r0, sp
11803a1c: bl       #0x118002b0  ; ->ad::lyt::LytAnim::init
11803a20: ldr      r0, [sp, #0x14]
11803a24: mov      r5, sp
11803a28: bl       #0x118002b8  ; ->ad::lyt::AnimTransform::GetFrameSize
11803a2c: vmov     s0, r0
11803a30: mov      r0, r5
11803a34: vcvt.f32.u32 s0, s0
11803a38: bl       #0x118002c0  ; ->ad::lyt::LytAnim::stopAndSetFrm
11803a3c: mov      r1, #1
11803a40: mov      r0, sp
11803a44: bl       #0x118002c8  ; ->ad::lyt::LytAnim::term
11803a48: vstr     s16, [sp, #0xc]
11803a4c: ldrb     r0, [r7, #0x13]
11803a50: mov      r2, r6
11803a54: cmp      r0, #0
11803a58: beq      #0x11803fe8
11803a5c: ldr      r1, [pc, #0x9c]  ; =0x11814420
11803a60: mov      r0, r4
11803a64: bl       #0x11805eb0
11803a68: nop      
11803a6c: nop      
11803a70: b        #0x11803ff4
11803a74: strbmi   r4, [r4, #-0x146]
11803a78: subeq    r4, lr, pc, asr sb
11803a7c: svcpl    #0x544553
11803a80: blmi     #0x12fd6bbc
11803a84: andeq    r0, r0, r0
11803a88: strheq   r0, [r6], -r8
11803a8c: svcpl    #0x544553
11803a90: ldrbpl   r4, [r4], #-0x142
11803a94: andeq    r4, r0, ip, asr #10
11803a98: .word    0xfff9f02c
11803a9c: svcpl    #0x544553
11803aa0: subpl    r4, sp, r3, asr #30
11803aa4: ldrbmi   r4, [r4, #-0x54c]
11803aa8: andeq    r0, r0, r0
11803aac: muleq    r6, ip, pc
11803ab0: andeq    r6, r3, r0, asr #11
11803ab4: orrne    ip, r0, r0, rrx
11803ab8: andeq    r5, r3, ip, asr fp
11803abc: andeq    r6, r3, r4, asr #8
11803ac0: andeq    r0, r0, sp, lsl #4
11803ac4: orrne    ip, r0, ip, lsr #6
11803ac8: strbmi   r4, [lr, -r3, asr #30]
11803acc: ldrbpl   r4, [r4, #-0x152]
11803ad0: ldmdbmi  r4, {r2, r3, r6, r8, lr} ^
11803ad4: svcpl    #0x534e4f
11803ad8: svcmi    #0x46464f
11803adc: andeq    r0, r0, lr, asr #32
11803ae0: svcpl    #0x544553
11803ae4: subpl    r5, pc, r4, asr r2
11803ae8: andeq    r5, r0, r8, asr #18
11803aec: ldrbpl   r4, [r3, #-0x552]
11803af0: ldrbpl   r5, [pc, -ip, asr #8]
11803af4: subspl   r4, pc, sb, asr #28
11803af8: strbpl   r4, [lr], #-0x94f
11803afc: andeq    r0, r0, r0
11803b00: orrne    r4, r1, r0, lsr #8
11803b04: nop      
11803b08: bl       #0x11800428  ; ->btl::GetBootInfo
11803b0c: ldrb     r0, [r0, #0xcd]
11803b10: cmp      r0, #1
11803b14: movne    r0, #0
11803b18: cmp      r6, #6
11803b1c: strb     r0, [r7, #0x10]
11803b20: blt      #0x11803b30
11803b24: cmp      r6, #0xc
11803b28: cmpne    r0, #0
11803b2c: bne      #0x11803b58
11803b30: mov      sl, #0
11803b34: bl       #0x11800410  ; ->col::GetBootInfo
11803b38: nop      
11803b3c: nop      
11803b40: bl       #0x11800430  ; ->col::BootInfo::dataPartyRestor
11803b44: ldrb     r0, [r7, #0x10]
11803b48: cmp      r0, #0
11803b4c: beq      #0x11803fa4
11803b50: cmp      sl, #0
11803b54: beq      #0x11803cbc
11803b58: nop      
11803b5c: bl       #0x11800410  ; ->col::GetBootInfo
11803b60: ldrb     r1, [r0, #0x20d]
11803b64: add      r1, r1, #1
11803b68: strb     r1, [r0, #0x20d]
11803b6c: sub      r0, r1, #6
11803b70: sxtb     r7, r0
11803b74: ldr      r0, [r4, #8]
11803b78: cmp      r0, #0
11803b7c: bne      #0x11803b8c
11803b80: ldr      r0, [pc, #-0x974]  ; =0x3f62a8 msys::MComSys::_sys
11803b84: ldr      r0, [r0]
11803b88: str      r0, [r4, #8]
11803b8c: ldr      r1, [pc, #0x3c4]  ; =0x1180c268
11803b90: rsb      r2, r7, r7, lsl #3
11803b94: add      r6, r0, #0xe9000
11803b98: add      r1, r1, r2, lsl #2
11803b9c: add      r0, r0, #0xe9000
11803ba0: ldr      r1, [r1, #8]
11803ba4: add      r6, r6, #0x50
11803ba8: add      r0, r0, #0x58
11803bac: bl       #0x11800290  ; ->LMS_GetTextIndexByLabel
11803bb0: mov      r1, r0
11803bb4: add      r0, r6, #8
11803bb8: bl       #0x11800298  ; ->LMS_GetText
11803bbc: mov      r1, r0
11803bc0: mov      r3, #0
11803bc4: ldr      r0, [sp, #0x74]
11803bc8: mov      r2, r3
11803bcc: bl       #0x118002a0  ; ->msys::MMsg::playStr
11803bd0: ldr      r0, [sp, #0x60]
11803bd4: add      sl, sp, #8
11803bd8: add      ip, sp, #4
11803bdc: mov      r6, #0
11803be0: ldr      r1, [r0, #0x150]
11803be4: mov      r0, #1
11803be8: vstmia   sl, {s16, s17}
11803bec: add      r2, pc, #0x368
11803bf0: vstr     s16, [sp, #0x10]
11803bf4: strh     r0, [sp, #0x14]
11803bf8: sub      r3, pc, #0x17c
11803bfc: mov      r0, ip
11803c00: strh     r6, [sp, #0x16]
11803c04: bl       #0x118002b0  ; ->ad::lyt::LytAnim::init
11803c08: ldr      r0, [sp, #0x18]
11803c0c: add      sl, sp, #4
11803c10: bl       #0x118002b8  ; ->ad::lyt::AnimTransform::GetFrameSize
11803c14: vmov     s0, r0
11803c18: mov      r0, sl
11803c1c: vcvt.f32.u32 s0, s0
11803c20: bl       #0x118002c0  ; ->ad::lyt::LytAnim::stopAndSetFrm
11803c24: mov      r1, #1
11803c28: add      r0, sp, #4
11803c2c: bl       #0x118002c8  ; ->ad::lyt::LytAnim::term
11803c30: ldr      r1, [r5, #0x150]
11803c34: sub      r3, pc, #0x1b8
11803c38: add      r2, pc, #0x324
11803c3c: add      r0, sp, #4
11803c40: bl       #0x118002b0  ; ->ad::lyt::LytAnim::init
11803c44: vmov     s0, r7
11803c48: add      r0, sp, #4
11803c4c: vcvt.f32.s32 s0, s0
11803c50: bl       #0x118002c0  ; ->ad::lyt::LytAnim::stopAndSetFrm
11803c54: mov      r1, #1
11803c58: add      r0, sp, #4
11803c5c: bl       #0x118002c8  ; ->ad::lyt::LytAnim::term
11803c60: mov      r3, #0
11803c64: mov      r2, #1
11803c68: mov      r1, #6
11803c6c: mov      r0, r5
11803c70: str      r6, [sp]
11803c74: bl       #0x11800438  ; ->msys::MLyt::stopAnimeAndSetEnd
11803c78: mov      r3, #0
11803c7c: mov      r2, r3
11803c80: add      r1, pc, #0x2ec
11803c84: mov      r0, r5
11803c88: bl       #0x11800338  ; ->msys::MLyt::createAnimeAutoSlot
11803c8c: vmov.f32 s0, s16
11803c90: mov      r0, r8
11803c94: bl       #0x118002c0  ; ->ad::lyt::LytAnim::stopAndSetFrm
11803c98: ldr      r0, [pc, #0x2e0]  ; =0x60ffc
11803c9c: vldr     s0, [pc, #0x2d8]  ; =0x42700000 (60)
11803ca0: add      r0, r0, r4
11803ca4: bl       #0x11800440  ; ->Frm::play
11803ca8: ldr      r1, [pc, #0x2d4]  ; =0x1180c000
11803cac: ldrd     r0, r1, [r1, #0x50]
11803cb0: strd     r0, r1, [sb, #4]
11803cb4: vstr     s16, [sp, #0x10]
11803cb8: b        #0x11803f38
11803cbc: cmp      r6, #6
11803cc0: movge    r6, #6
11803cc4: ldr      r0, [sp, #0xe4]
11803cc8: and      r8, r6, #0xff
11803ccc: bl       #0x11800408  ; ->msys::MListWndPBase::getListWnd
11803cd0: ldr      r1, [r0]
11803cd4: ldr      r2, [r1, #0x28]
11803cd8: mov      r1, r8
11803cdc: blx      r2
11803ce0: ldr      r0, [pc, #0x270]  ; =0x1180c268
11803ce4: rsb      fp, r6, r6, lsl #3
11803ce8: add      r0, r0, fp, lsl #2
11803cec: str      r0, [sp, #0xec]
11803cf0: ldrb     r8, [r0, #4]
11803cf4: bl       #0x11800428  ; ->btl::GetBootInfo
11803cf8: ldrb     r0, [r0, #0x129]
11803cfc: sub      r0, r8, r0
11803d00: and      r8, r0, #0xff
11803d04: ldrb     r0, [r7, #0x13]
11803d08: cmp      r0, #0
11803d0c: ldr      r0, [pc, #-0x6d8]  ; =0x3f95f0 gGameWork
11803d10: movne    r1, #0xa
11803d14: moveq    r1, #0
11803d18: add      r0, r0, r1, lsl #1
11803d1c: add      r0, r0, #0x7f0
11803d20: add      sl, r0, r6, lsl #1
11803d24: ldrsh    r0, [sl]
11803d28: lsr      r0, r0, #0x1f
11803d2c: strb     r0, [r7, #0x11]
11803d30: ldrsh    r1, [sl]
11803d34: ldrb     r2, [r7, #0x10]
11803d38: cmp      r1, r8
11803d3c: movgt    r1, #1
11803d40: movle    r1, #0
11803d44: cmp      r2, #0
11803d48: strb     r1, [r7, #0x12]
11803d4c: beq      #0x11803f2c
11803d50: cmp      r0, #0
11803d54: beq      #0x11803e98
11803d58: ldr      r1, [r5, #0x150]
11803d5c: vstr     s16, [sp, #4]
11803d60: vstr     s17, [sp, #8]
11803d64: mov      ip, #1
11803d68: vstr     s16, [sp, #0xc]
11803d6c: mov      lr, #0
11803d70: strh     ip, [sp, #0x10]
11803d74: mov      r0, sp
11803d78: sub      r2, pc, #0x2b8
11803d7c: sub      r3, pc, #0x300
11803d80: strh     lr, [sp, #0x12]
11803d84: bl       #0x118002b0  ; ->ad::lyt::LytAnim::init
11803d88: ldr      r0, [sp, #0x14]
11803d8c: str      sp, [sp, #0x68]
11803d90: bl       #0x118002b8  ; ->ad::lyt::AnimTransform::GetFrameSize
11803d94: vmov     s0, r0
11803d98: ldr      r0, [sp, #0x68]
11803d9c: vcvt.f32.u32 s0, s0
11803da0: bl       #0x118002c0  ; ->ad::lyt::LytAnim::stopAndSetFrm
11803da4: mov      r1, #1
11803da8: mov      r0, sp
11803dac: bl       #0x118002c8  ; ->ad::lyt::LytAnim::term
11803db0: ldr      r1, [r5, #0x150]
11803db4: sub      r3, pc, #0x338
11803db8: sub      r2, pc, #0x2e0
11803dbc: mov      r0, sp
11803dc0: bl       #0x118002b0  ; ->ad::lyt::LytAnim::init
11803dc4: ldrb     r0, [r7, #0x13]
11803dc8: cmp      r0, #0
11803dcc: movne    r0, #7
11803dd0: add      r0, r0, r6
11803dd4: vmov     s0, r0
11803dd8: mov      r0, sp
11803ddc: vcvt.f32.s32 s0, s0
11803de0: bl       #0x118002c0  ; ->ad::lyt::LytAnim::stopAndSetFrm
11803de4: mov      r1, #1
11803de8: mov      r0, sp
11803dec: bl       #0x118002c8  ; ->ad::lyt::LytAnim::term
11803df0: ldr      r1, [r5, #0x150]
11803df4: sub      r3, pc, #0x378
11803df8: sub      r2, pc, #0x314
11803dfc: mov      r0, sp
11803e00: bl       #0x118002b0  ; ->ad::lyt::LytAnim::init
11803e04: ldr      r0, [sp, #0x14]
11803e08: mov      r5, sp
11803e0c: bl       #0x118002b8  ; ->ad::lyt::AnimTransform::GetFrameSize
11803e10: vmov     s0, r0
11803e14: mov      r0, r5
11803e18: vcvt.f32.u32 s0, s0
11803e1c: bl       #0x118002c0  ; ->ad::lyt::LytAnim::stopAndSetFrm
11803e20: mov      r1, #1
11803e24: mov      r0, sp
11803e28: bl       #0x118002c8  ; ->ad::lyt::LytAnim::term
11803e2c: vstr     s16, [sp, #0xc]
11803e30: ldrb     r0, [r7, #0x13]
11803e34: mov      r2, r6
11803e38: cmp      r0, #0
11803e3c: beq      #0x11803e58
11803e40: ldr      r1, [pc, #-0x348]  ; =0x11814420
11803e44: mov      r0, r4
11803e48: bl       #0x11805eb0
11803e4c: nop      
11803e50: nop      
11803e54: b        #0x11803e64
11803e58: ldr      r1, [pc, #0x128]  ; =0x118143e8
11803e5c: mov      r0, r4
11803e60: bl       #0x11805eb0
11803e64: add      r0, r4, fp, lsl #2
11803e68: add      r0, r0, #0x40000
11803e6c: add      r0, r0, #0x4f00
11803e70: strh     r8, [sl]
11803e74: strh     r8, [r0, #8]
11803e78: mov      r0, r4
11803e7c: bl       #0x11806cf0
11803e80: mov      r0, r4
11803e84: nop      
11803e88: bl       #0x11805fa4
11803e8c: nop      
11803e90: nop      
11803e94: b        #0x11803f10
11803e98: cmp      r1, #0
11803e9c: beq      #0x11803f10
11803ea0: ldr      r1, [r5, #0x150]
11803ea4: add      r6, sp, #0xcc
11803ea8: mov      ip, #1
11803eac: vstmia   r6, {s16, s17}
11803eb0: mov      r5, #0
11803eb4: vstr     s16, [sp, #0xd4]
11803eb8: strh     ip, [sp, #0xd8]
11803ebc: add      r0, sp, #0xc8
11803ec0: add      r2, pc, #0xc4
11803ec4: sub      r3, pc, #0x3d0
11803ec8: strh     r5, [sp, #0xda]
11803ecc: bl       #0x118002b0  ; ->ad::lyt::LytAnim::init
11803ed0: ldr      r0, [sp, #0xdc]
11803ed4: add      r5, sp, #0xc8
11803ed8: bl       #0x118002b8  ; ->ad::lyt::AnimTransform::GetFrameSize
11803edc: vmov     s0, r0
11803ee0: mov      r0, r5
11803ee4: vcvt.f32.u32 s0, s0
11803ee8: bl       #0x118002c0  ; ->ad::lyt::LytAnim::stopAndSetFrm
11803eec: mov      r1, #1
11803ef0: add      r0, sp, #0xc8
11803ef4: bl       #0x118002c8  ; ->ad::lyt::LytAnim::term
11803ef8: add      r0, r4, fp, lsl #2
11803efc: add      r0, r0, #0x40000
11803f00: vstr     s16, [sp, #0xd4]
11803f04: add      r0, r0, #0x4f00
11803f08: strh     r8, [sl]
11803f0c: strh     r8, [r0, #8]
11803f10: ldr      r0, [sp, #0xe4]
11803f14: mov      r1, #0
11803f18: strb     r1, [r0, #0x141]
11803f1c: ldr      r0, [sp, #0xec]
11803f20: add      r1, r0, #0xc
11803f24: ldr      r0, [sp, #0xc4]
11803f28: bl       #0x11805e48
11803f2c: ldr      r1, [pc, #0x50]  ; =0x1180c000
11803f30: ldrd     r0, r1, [r1, #0x58]
11803f34: strd     r0, r1, [sb, #4]
11803f38: ldr      r1, [pc, #0x44]  ; =0x1180c000
11803f3c: add      r2, r4, #0x12800
11803f40: add      r2, r2, #0x1fc
11803f44: ldrd     r0, r1, [r1, #0x68]
11803f48: strd     r0, r1, [r2]
11803f4c: add      sp, sp, #0xf4
11803f50: vpop     {d8, d9}
11803f54: pop      {r4, r5, r6, r7, r8, sb, sl, fp, pc}
11803f58: orrne    ip, r0, r8, ror #4
11803f5c: svcvs    #0x745f33
11803f60: andeq    r3, r0, pc, asr r4
11803f64: svcpl    #0x544553
11803f68: stclmi   p14, c4, [r5, #-0x114]
11803f6c: stclmi   p15, c5, [sb, #-0x164]
11803f70: andeq    r0, r0, r7, asr #32
11803f74: svcvs    #0x745f34
11803f78: andeq    r3, r0, pc, asr r5
11803f7c: rsbsmi   r0, r0, #0
11803f80: strdeq   r0, r1, [r6], -ip
11803f84: orrne    ip, r0, r0
11803f88: orrne    r4, r1, r8, ror #7
11803f8c: ldrbpl   r4, [r3, #-0x552]
11803f90: subsmi   r5, pc, #76, #8
11803f94: svcpl    #0x545345
11803f98: mrcmi    p5, #2, r5, c2, c4, #2
11803f9c: uqsaxvs  r6, r6, pc
11803fa0: andeq    r6, r0, pc, ror #28
11803fa4: cmp      r6, #6
11803fa8: movge    r6, #6
11803fac: ldr      r0, [pc, #-0x5c]  ; =0x1180c268
11803fb0: rsb      r1, r6, r6, lsl #3
11803fb4: add      r0, r0, r1, lsl #2
11803fb8: add      r1, r0, #0xc
11803fbc: ldr      r0, [sp, #0xc4]
11803fc0: bl       #0x11805e48
11803fc4: nop      
11803fc8: nop      
11803fcc: bl       #0x11800410  ; ->col::GetBootInfo
11803fd0: nop      
11803fd4: nop      
11803fd8: bl       #0x11800448  ; ->col::BootInfo::restoreBgm
11803fdc: nop      
11803fe0: nop      
11803fe4: b        #0x11803f2c
11803fe8: ldr      r1, [pc, #-0x68]  ; =0x118143e8
11803fec: mov      r0, r4
11803ff0: bl       #0x11805eb0
11803ff4: rsb      r0, r6, r6, lsl #3
11803ff8: strh     r8, [sl]
11803ffc: add      r0, r4, r0, lsl #2
11804000: add      r0, r0, #0x40000
11804004: add      r0, r0, #0x4f00
11804008: strh     r8, [r0, #8]
1180400c: ldr      r0, [sp, #0xe4]
11804010: mov      r1, #0
11804014: strb     r1, [r0, #0x141]
11804018: add      r0, r6, r6, lsl #2
1180401c: add      r0, fp, r0, lsl #2
11804020: add      r1, r0, #4
11804024: ldr      r0, [sp, #0xc4]
11804028: bl       #0x11805e48
1180402c: nop      
11804030: nop      
11804034: b        #0x11803f2c
11804038: nop      
1180403c: bl       #0x11800410  ; ->col::GetBootInfo
11804040: nop      
11804044: nop      
11804048: bl       #0x11800448  ; ->col::BootInfo::restoreBgm
1180404c: add      r0, r6, r6, lsl #2
11804050: add      r0, fp, r0, lsl #2
11804054: add      r1, r0, #4
11804058: ldr      r0, [sp, #0xc4]
1180405c: bl       #0x11805e48
11804060: nop      
11804064: nop      
11804068: b        #0x11803f2c
1180406c: push     {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
11804070: mov      r5, r0
11804074: bl       #0x11805d28
11804078: ldr      sl, [pc, #0x174]  ; =0x1180c000
1180407c: cmp      r0, #0
11804080: add      sb, r5, #0x10000
11804084: add      sb, sb, #0x2a00
11804088: ldrdne   r0, r1, [sl, #0xa8]
1180408c: strdne   r0, r1, [sb, #4]
11804090: bne      #0x118041f0
11804094: add      r4, r5, #0x61000
11804098: ldr      r0, [pc, #0x158]  ; =0x1331c
1180409c: ldrb     r1, [r4, #0x13]
118040a0: mov      r7, #0
118040a4: mov      r3, r7
118040a8: strb     r1, [r0, r5]
118040ac: add      r0, r5, #0x12c00
118040b0: mov      r2, #1
118040b4: mov      r1, #3
118040b8: add      r0, r0, #0x35c
118040bc: str      r7, [sp]
118040c0: bl       #0x11800350  ; ->msys::MLyt::playAnimeFromNo
118040c4: add      r0, r5, #0x3dc00
118040c8: add      r0, r0, #0x384
118040cc: ldrsb    r1, [r4, #0x13]
118040d0: mov      r8, r0
118040d4: bl       #0x11806ab4
118040d8: add      r0, r5, #0x60000
118040dc: add      r0, r0, #0x194
118040e0: mov      r1, #0xff
118040e4: strb     r1, [r0, #0x96c]
118040e8: mov      r6, #1
118040ec: str      r7, [r0, #0x968]
118040f0: strb     r6, [r0, #0x96d]
118040f4: ldrb     r0, [r4, #0x13]
118040f8: add      fp, r5, #0x4c000
118040fc: add      fp, fp, #0x194
11804100: cmp      r0, #0
11804104: beq      #0x1180417c
11804108: ldr      fp, [pc, #0xec]  ; =0x3f9df4
1180410c: mov      r0, r8
11804110: bl       #0x11800310  ; ->msys::MListWndPBase::getCurNo
11804114: add      r0, fp, r0, lsl #1
11804118: ldrsh    r0, [r0]
1180411c: add      fp, r6, r0, asr #31
11804120: ldrb     r0, [r4, #0x13]
11804124: cmp      r0, #0
11804128: mov      r0, r8
1180412c: beq      #0x11804144
11804130: bl       #0x11800310  ; ->msys::MListWndPBase::getCurNo
11804134: ldrb     r1, [r4, #0xd]
11804138: tst      r1, r6, lsl r0
1180413c: beq      #0x11804160
11804140: b        #0x11804158
11804144: nop      
11804148: bl       #0x11800310  ; ->msys::MListWndPBase::getCurNo
1180414c: ldrb     r1, [r4, #0xc]
11804150: tst      r1, r6, lsl r0
11804154: beq      #0x11804160
11804158: mov      r1, #1
1180415c: b        #0x11804164
11804160: mov      r1, #0
11804164: mov      r2, fp
11804168: mov      r0, r5
1180416c: bl       #0x11806474
11804170: nop      
11804174: nop      
11804178: b        #0x118041d0
1180417c: mov      r0, r8
11804180: bl       #0x11800310  ; ->msys::MListWndPBase::getCurNo
11804184: ldrb     r1, [r4, #0xc]
11804188: ldr      r4, [pc, #0x70]  ; =0x3f9de0
1180418c: ands     r0, r1, r6, lsl r0
11804190: movne    r0, #1
11804194: str      r0, [sp]
11804198: mov      r0, r8
1180419c: bl       #0x11800310  ; ->msys::MListWndPBase::getCurNo
118041a0: add      r0, r4, r0, lsl #1
118041a4: ldrsh    r0, [r0]
118041a8: add      r4, r6, r0, asr #31
118041ac: ldr      r6, [pc, #0x50]  ; =0x1180c268
118041b0: mov      r0, r8
118041b4: bl       #0x11800310  ; ->msys::MListWndPBase::getCurNo
118041b8: rsb      r0, r0, r0, lsl #3
118041bc: ldr      r2, [sp]
118041c0: add      r1, r6, r0, lsl #2
118041c4: mov      r3, r4
118041c8: mov      r0, fp
118041cc: bl       #0x118061f4
118041d0: mov      r0, #1
118041d4: strb     r0, [r8, #0x141]
118041d8: ldrd     r0, r1, [sl, #0xb0]
118041dc: strd     r0, r1, [sb, #4]
118041e0: add      r0, r5, #0x45000
118041e4: mvn      r1, #0
118041e8: str      r7, [r0, #0x108]!
118041ec: str      r1, [r0, #4]
118041f0: pop      {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
118041f4: orrne    ip, r0, r0
118041f8: andeq    r3, r1, ip, lsl r3
118041fc: ldrshteq sb, [pc], -r4
11804200: eorseq   sb, pc, r0, ror #27
11804204: orrne    ip, r0, r8, ror #4
11804208: push     {r3, r4, r5, r6, r7, lr}
1180420c: mov      r4, r0
11804210: add      r0, r0, #0x12c00
11804214: add      r0, r0, #0x35c
11804218: mov      r7, r0
1180421c: bl       #0x11800450  ; ->msys::MLyt::isEnableAnime
11804220: cmp      r0, #0
11804224: bne      #0x118042a4
11804228: ldr      r0, [pc, #0x78]  ; =0x3dc94
1180422c: ldr      r0, [r0, r4]
11804230: cmp      r0, #0
11804234: bne      #0x118042a4
11804238: add      r5, r4, #0x35400
1180423c: ldr      r0, [pc, #0x68]  ; =0x3f95f0 gGameWork
11804240: add      r5, r5, #0x1a8
11804244: bl       #0x118003d0  ; ->GameWork::getCoin
11804248: mov      r1, r0
1180424c: add      r0, r5, #0x150
11804250: bl       #0x11800300  ; ->ad::lyt::LytNumReel3::setValueInstant
11804254: ldr      r0, [pc, #0x54]  ; =0x6100f
11804258: ldr      r6, [pc, #0x54]  ; =0x1180c000
1180425c: add      r5, r4, #0x10000
11804260: add      r5, r5, #0x2a00
11804264: ldrb     r0, [r0, r4]
11804268: cmp      r0, #0
1180426c: ldrdne   r0, r1, [r6, #0xa8]
11804270: bne      #0x118042a0
11804274: add      r0, r4, #0x37000
11804278: add      r0, r0, #0x198
1180427c: bl       #0x11800458  ; ->Message::close
11804280: mov      r0, #0
11804284: mov      r3, r0
11804288: mov      r2, r0
1180428c: str      r0, [sp]
11804290: mov      r1, #8
11804294: mov      r0, r7
11804298: bl       #0x11800350  ; ->msys::MLyt::playAnimeFromNo
1180429c: ldrd     r0, r1, [r6, #0xd8]
118042a0: strd     r0, r1, [r5, #4]
118042a4: pop      {r3, r4, r5, r6, r7, pc}
118042a8: muleq    r3, r4, ip
118042ac: ldrshteq sb, [pc], -r0
118042b0: andeq    r1, r6, pc
118042b4: orrne    ip, r0, r0
118042b8: push     {r4, lr}
118042bc: mov      r4, r0
118042c0: mvn      r0, #0
118042c4: bl       #0x11800460  ; ->Backup::GetSaveData1
118042c8: ldr      r1, [pc, #0x58]  ; =0x3f9dc0
118042cc: mov      r2, #0x40
118042d0: add      r0, r0, #0x7d0
118042d4: bl       #0x11800468  ; ->Mem::Copy
118042d8: ldr      r0, [r4, #8]
118042dc: cmp      r0, #0
118042e0: bne      #0x118042f0
118042e4: ldr      r0, [pc, #0x40]  ; =0x3f62a8 msys::MComSys::_sys
118042e8: ldr      r0, [r0]
118042ec: str      r0, [r4, #8]
118042f0: ldr      r0, [r0, #4]
118042f4: add      r1, r0, #0x400
118042f8: add      r1, r1, #0x118
118042fc: add      r0, r4, #0x10
11804300: bl       #0x11800470  ; ->Backup::init
11804304: mvn      r1, #0
11804308: add      r0, r4, #0x10
1180430c: bl       #0x11800478  ; ->Backup::writeSaveData0
11804310: ldr      r1, [pc, #0x18]  ; =0x1180c1c8
11804314: add      r2, r4, #0x10000
11804318: add      r2, r2, #0x2a00
1180431c: ldm      r1, {r0, r1}
11804320: strd     r0, r1, [r2, #4]
11804324: pop      {r4, pc}
11804328: eorseq   sb, pc, r0, asr #27
1180432c: eorseq   r6, pc, r8, lsr #5
11804330: orrne    ip, r0, r8, asr #3
11804334: push     {r4, r5, r6, lr}
11804338: mov      r5, r0
1180433c: mov      r0, #0
11804340: vpush    {d8}
11804344: sub      sp, sp, #8
11804348: mov      r3, r0
1180434c: mov      r2, r0
11804350: mov      r1, r0
11804354: str      r0, [sp]
11804358: add      r0, r5, #0x12c00
1180435c: add      r0, r0, #0x35c
11804360: bl       #0x11800350  ; ->msys::MLyt::playAnimeFromNo
11804364: ldr      r0, [r5, #8]
11804368: cmp      r0, #0
1180436c: bne      #0x1180437c
11804370: ldr      r0, [pc, #0x64]  ; =0x3f62a8 msys::MComSys::_sys
11804374: ldr      r0, [r0]
11804378: str      r0, [r5, #8]
1180437c: mov      r4, r0
11804380: mov      r0, #0xff
11804384: vldr     s16, [pc, #0x58]  ; =0x41800000 (16)
11804388: rev      r0, r0
1180438c: add      r6, sp, #4
11804390: str      r0, [sp, #4]
11804394: ldr      r0, [pc, #0x44]  ; =0x4acd4
11804398: vmov.f32 s0, s16
1180439c: mov      r1, r6
118043a0: add      r0, r0, r4
118043a4: bl       #0x11800480  ; ->MoveC::moveFrm
118043a8: ldr      r0, [pc, #0x38]  ; =0x4ad14
118043ac: vmov.f32 s0, s16
118043b0: mov      r1, r6
118043b4: add      r0, r0, r4
118043b8: bl       #0x11800480  ; ->MoveC::moveFrm
118043bc: ldr      r1, [pc, #0x28]  ; =0x1180c000
118043c0: add      r2, r5, #0x10000
118043c4: add      r2, r2, #0x2a00
118043c8: ldrd     r0, r1, [r1, #0x98]
118043cc: strd     r0, r1, [r2, #4]
118043d0: add      sp, sp, #8
118043d4: vpop     {d8}
118043d8: pop      {r4, r5, r6, pc}
118043dc: eorseq   r6, pc, r8, lsr #5
118043e0: ldrdeq   sl, fp, [r4], -r4
118043e4: orrmi    r0, r0, r0
118043e8: andeq    sl, r4, r4, lsl sp
118043ec: orrne    ip, r0, r0
118043f0: ldr      r1, [pc, #0x10]  ; =0x132dc
118043f4: ldrb     r1, [r1, r0]
118043f8: cmp      r1, #0
118043fc: beq      #0x11804404
11804400: b        #0x11802e24
11804404: bx       lr
11804408: ldrdeq   r3, r4, [r1], -ip
1180440c: push     {r3, r4, r5, r6, r7, lr}
11804410: mov      r4, r0
11804414: add      r0, r0, #0x45000
11804418: ldr      r0, [r0, #0x10c]
1180441c: cmp      r0, #0
11804420: blt      #0x1180443c
11804424: and      r1, r0, #0xff
11804428: add      r0, r4, #0x12800
1180442c: add      r0, r0, #0x3b4
11804430: bl       #0x11800328  ; ->msys::MLyt::getAnim
11804434: vldr     s0, [pc, #0x54]  ; =0x0 (0)
11804438: bl       #0x118002c0  ; ->ad::lyt::LytAnim::stopAndSetFrm
1180443c: add      r0, r4, #0x12c00
11804440: add      r0, r0, #0x35c
11804444: mov      r2, #2
11804448: mov      r1, #3
1180444c: mov      r6, r0
11804450: bl       #0x118003f8  ; ->msys::MLyt::setAnimeInfo
11804454: mov      r5, #0
11804458: mov      r3, r5
1180445c: mov      r2, r5
11804460: mov      r1, #3
11804464: mov      r0, r6
11804468: str      r5, [sp]
1180446c: bl       #0x11800350  ; ->msys::MLyt::playAnimeFromNo
11804470: ldr      r0, [pc, #0x1c]  ; =0x3e0c5
11804474: ldr      r1, [pc, #0x1c]  ; =0x1180c000
11804478: add      r2, r4, #0x10000
1180447c: add      r2, r2, #0x2a00
11804480: strb     r5, [r0, r4]
11804484: ldrd     r0, r1, [r1, #0x80]
11804488: strd     r0, r1, [r2, #4]
1180448c: pop      {r3, r4, r5, r6, r7, pc}
11804490: andeq    r0, r0, r0
11804494: andeq    lr, r3, r5, asr #1
11804498: orrne    ip, r0, r0
1180449c: push     {r4, r5, r6, r7, r8, sb, sl, fp, lr}
118044a0: mov      r6, r0
118044a4: add      r0, r0, #0x12c00
118044a8: add      r0, r0, #0x35c
118044ac: mov      sb, r0
118044b0: vpush    {d8}
118044b4: sub      sp, sp, #0x234
118044b8: bl       #0x11800450  ; ->msys::MLyt::isEnableAnime
118044bc: cmp      r0, #0
118044c0: bne      #0x118047dc
118044c4: add      r5, r6, #0x61000
118044c8: vldr     s16, [pc, #0x318]  ; =0x3f800000 (1)
118044cc: ldrsb    r2, [r5, #0x13]
118044d0: ldrb     r0, [r5, #0xf]
118044d4: mov      r4, #0
118044d8: mov      r8, #1
118044dc: tst      r0, r8, lsl r4
118044e0: beq      #0x118045bc
118044e4: cmp      r2, #0
118044e8: bic      r0, r0, r8, lsl r4
118044ec: strb     r0, [r5, #0xf]
118044f0: bne      #0x1180451c
118044f4: cmp      r4, #6
118044f8: bne      #0x118045dc
118044fc: vmov.f32 s0, s16
11804500: mov      r2, #0
11804504: ldr      r0, [pc, #0x2e0]  ; =0xc512
11804508: mov      r1, r2
1180450c: bl       #0x11800488  ; ->PutRegFlag
11804510: ldrb     r0, [r5, #0x13]
11804514: cmp      r0, #0
11804518: beq      #0x118045dc
1180451c: ldr      r0, [pc, #0x2cc]  ; =0x1180c32c
11804520: add      r1, r4, r4, lsl #2
11804524: add      r0, r0, r1, lsl #2
11804528: add      r7, r0, #4
1180452c: vldr     s17, [pc, #0x2dc]  ; =0x0 (0)
11804530: ldr      r1, [sb, #0x150]
11804534: vstr     s17, [sp, #8]
11804538: add      r4, sp, #0xc
1180453c: mov      fp, #0
11804540: vstmia   r4, {s16, s17}
11804544: add      r0, sp, #4
11804548: strh     r8, [sp, #0x14]
1180454c: add      r2, pc, #0x2a0
11804550: add      r3, pc, #0x2b4
11804554: strh     fp, [sp, #0x16]
11804558: bl       #0x118002b0  ; ->ad::lyt::LytAnim::init
1180455c: vmov.f32 s0, s17
11804560: add      r0, sp, #4
11804564: bl       #0x118002c0  ; ->ad::lyt::LytAnim::stopAndSetFrm
11804568: mov      r1, #1
1180456c: add      r0, sp, #4
11804570: bl       #0x118002c8  ; ->ad::lyt::LytAnim::term
11804574: ldrb     r1, [r5, #0x13]
11804578: add      r0, r6, #0x12800
1180457c: mov      r3, #0
11804580: cmp      r1, #0
11804584: add      r0, r0, #0x3b4
11804588: mov      r2, r3
1180458c: beq      #0x118045f0
11804590: add      r1, pc, #0x27c
11804594: bl       #0x11800338  ; ->msys::MLyt::createAnimeAutoSlot
11804598: mov      r3, #0
1180459c: mov      r2, r3
118045a0: mov      r1, #7
118045a4: mov      r0, sb
118045a8: str      fp, [sp]
118045ac: bl       #0x11800350  ; ->msys::MLyt::playAnimeFromNo
118045b0: nop      
118045b4: nop      
118045b8: b        #0x11804610
118045bc: add      r1, r4, #1
118045c0: cmp      r2, #0
118045c4: and      r4, r1, #0xff
118045c8: movne    r1, #4
118045cc: moveq    r1, #7
118045d0: cmp      r1, r4
118045d4: bhi      #0x118044dc
118045d8: b        #0x11804510
118045dc: ldr      r0, [pc, #0x23c]  ; =0x1180c268
118045e0: rsb      r1, r4, r4, lsl #3
118045e4: add      r0, r0, r1, lsl #2
118045e8: add      r7, r0, #0xc
118045ec: b        #0x1180452c
118045f0: add      r1, pc, #0x22c
118045f4: bl       #0x11800338  ; ->msys::MLyt::createAnimeAutoSlot
118045f8: mov      r3, #0
118045fc: mov      r2, r3
11804600: mov      r1, #6
11804604: mov      r0, sb
11804608: str      fp, [sp]
1180460c: bl       #0x11800350  ; ->msys::MLyt::playAnimeFromNo
11804610: mov      r3, #0
11804614: mov      r2, #1
11804618: mov      r1, #8
1180461c: mov      r0, sb
11804620: str      fp, [sp]
11804624: bl       #0x11800350  ; ->msys::MLyt::playAnimeFromNo
11804628: add      r0, r6, #0x4c000
1180462c: mov      r1, r7
11804630: add      r0, r0, #0x194
11804634: bl       #0x11805e48
11804638: add      r0, sp, #0x100
1180463c: strh     fp, [sp, #0x20]
11804640: str      fp, [sp, #0x220]
11804644: strh     fp, [sp, #0xa0]
11804648: str      fp, [sp, #0x224]
1180464c: strh     fp, [r0, #0x20]
11804650: str      fp, [sp, #0x228]
11804654: strh     fp, [r0, #0xa0]
11804658: str      fp, [sp, #0x22c]
1180465c: ldrsh    sl, [r7, #4]
11804660: add      sb, sp, #0x20
11804664: mov      r8, #0
11804668: mov      r5, #0xa
1180466c: mov      r4, #1
11804670: mov      r1, r5
11804674: mov      r0, sl
11804678: bl       #0x11800490  ; ->__aeabi_uidivmod
1180467c: cmp      r0, #0
11804680: nop      
11804684: beq      #0x1180469c
11804688: add      r0, r5, r5, lsl #2
1180468c: add      r4, r4, #1
11804690: cmp      r4, #0x40
11804694: lsl      r5, r0, #1
11804698: blo      #0x11804670
1180469c: add      r5, sb, r8, lsl #7
118046a0: ldr      r3, [pc, #0x184]  ; =0x3f7ce4 _ZZN13MessageSimple8InsParam6setNumEhibEs
118046a4: mov      r2, #0x3f
118046a8: mov      r1, #0x40
118046ac: mov      r0, r5
118046b0: str      sl, [sp]
118046b4: bl       #0x11801280
118046b8: ldr      r2, [pc, #0x170]  ; =0xfee0
118046bc: cmp      r4, #0
118046c0: beq      #0x1180471c
118046c4: ands     r0, r4, #1
118046c8: mov      r1, #0
118046cc: beq      #0x118046e0
118046d0: ldrh     r3, [r5]
118046d4: mov      r1, #1
118046d8: sub      r3, r3, #0x120
118046dc: strh     r3, [r5]
118046e0: cmp      r0, r4
118046e4: bhs      #0x1180471c
118046e8: add      r3, r5, r1, lsl #1
118046ec: add      r1, r1, #1
118046f0: ldrh     sl, [r3]
118046f4: add      ip, r5, r1, lsl #1
118046f8: add      r0, r0, #2
118046fc: add      sl, sl, r2
11804700: strh     sl, [r3]
11804704: ldrh     r3, [ip]
11804708: cmp      r0, r4
1180470c: add      r1, r1, #1
11804710: add      r3, r3, r2
11804714: strh     r3, [ip]
11804718: blo      #0x118046e8
1180471c: add      r0, sb, r8, lsl #2
11804720: add      r8, sp, #0x20
11804724: str      r4, [r0, #0x200]
11804728: ldrh     r0, [r7, #2]
1180472c: mov      r5, #1
11804730: mov      r1, #0
11804734: bl       #0x11800498  ; ->ad::db::GetItemMsg
11804738: mov      r1, r0
1180473c: mov      r4, #0
11804740: add      r0, r1, r4, lsl #1
11804744: ldrh     r2, [r0]
11804748: cmp      r2, #0
1180474c: beq      #0x11804770
11804750: cmp      r2, #0xe
11804754: bne      #0x11804764
11804758: ldrh     r0, [r0, #6]
1180475c: add      r0, r4, r0, lsr #1
11804760: add      r4, r0, #3
11804764: add      r4, r4, #1
11804768: cmp      r4, #0x40
1180476c: blo      #0x11804740
11804770: ldrh     r0, [r1]
11804774: cmp      r0, #0xe
11804778: ldrheq   r0, [r1, #2]
1180477c: cmpeq    r0, #9
11804780: subeq    r4, r4, #5
11804784: addeq    r1, r1, #0xa
11804788: lsl      r2, r4, #1
1180478c: add      r0, r8, r5, lsl #7
11804790: bl       #0x11800468  ; ->Mem::Copy
11804794: add      r0, r8, r5, lsl #2
11804798: add      r2, sp, #0x20
1180479c: str      r4, [r0, #0x200]
118047a0: add      r0, r6, #0x37000
118047a4: add      r1, pc, #0x88
118047a8: add      r0, r0, #0x4c
118047ac: bl       #0x11805cbc
118047b0: mov      r3, #0
118047b4: ldr      r1, [pc, #0x98]  ; =0x110025
118047b8: mov      r2, r3
118047bc: mov      r0, r6
118047c0: str      fp, [sp]
118047c4: bl       #0x11806814
118047c8: ldr      r1, [pc, #0x88]  ; =0x1180c000
118047cc: add      r2, r6, #0x10000
118047d0: add      r2, r2, #0x2a00
118047d4: ldrd     r0, r1, [r1, #0xd0]
118047d8: strd     r0, r1, [r2, #4]
118047dc: add      sp, sp, #0x234
118047e0: vpop     {d8}
118047e4: pop      {r4, r5, r6, r7, r8, sb, sl, fp, pc}
118047e8: svclo    #0x800000
118047ec: andeq    ip, r0, r2, lsl r5
118047f0: orrne    ip, r0, ip, lsr #6
118047f4: strbmi   r4, [lr, -r3, asr #30]
118047f8: ldrbpl   r4, [r4, #-0x152]
118047fc: ldmdbmi  r4, {r2, r3, r6, r8, lr} ^
11804800: svcpl    #0x534e4f
11804804: svcmi    #0x46464f
11804808: andeq    r0, r0, lr, asr #32
1180480c: andeq    r0, r0, r0
11804810: andeq    r0, r0, r0
11804814: strbvs   r7, [r7, #-0x568]!
11804818: ldrbvc   r3, [pc], #-0x55f
1180481c: eorseq   r5, r6, pc, ror #30
11804820: orrne    ip, r0, r8, ror #4
11804824: svcvs    #0x745f35
11804828: andeq    r3, r0, pc, asr r6
1180482c: eorseq   r7, pc, r4, ror #25
11804830: andeq    pc, r0, r0, ror #29
11804834: svcpl    #0x53454d
11804838: .word    0x73654d45
1180483c: svcvs    #0x6c6f43
11804840: strbvc   r7, [r5, #-0x373]!
11804844: stclvs   p15, c5, [r3], #-0x1b4
11804848: svcpl    #0x737361
1180484c: rsbsvc   r5, r0, #49, #30
11804850: rsbeq    r7, r5, sb, ror #20
11804854: andseq   r0, r1, r5, lsr #32
11804858: orrne    ip, r0, r0
1180485c: push     {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
11804860: mov      r5, r0
11804864: mov      r4, #1
11804868: add      sb, r0, #0x61000
1180486c: add      sl, r0, #0x3dc00
11804870: ldrb     r0, [sb, #0x13]
11804874: mov      r8, #0
11804878: add      sl, sl, #0x384
1180487c: cmp      r0, #0
11804880: ldr      r0, [pc, #0x1a8]  ; =0x3f95f0 gGameWork
11804884: beq      #0x118048a8
11804888: add      r6, r0, #0x800
1180488c: add      r6, r6, #4
11804890: mov      r0, sl
11804894: bl       #0x11800310  ; ->msys::MListWndPBase::getCurNo
11804898: add      r0, r6, r0, lsl #1
1180489c: ldrsh    r0, [r0]
118048a0: add      r4, r4, r0, asr #31
118048a4: b        #0x118048c0
118048a8: add      r6, r0, #0x7f0
118048ac: mov      r0, sl
118048b0: bl       #0x11800310  ; ->msys::MListWndPBase::getCurNo
118048b4: add      r0, r6, r0, lsl #1
118048b8: ldrsh    r0, [r0]
118048bc: add      r4, r4, r0, asr #31
118048c0: add      r0, r5, #0x13000
118048c4: mov      r1, #0
118048c8: add      r0, r0, #0x304
118048cc: bl       #0x118003f0  ; ->msys::MCursorBase::setVisible
118048d0: ldr      r0, [pc, #0x160]  ; =0x60f9c
118048d4: vldr     s0, [pc, #0x158]  ; =0x0 (0)
118048d8: add      r0, r0, r5
118048dc: bl       #0x118002c0  ; ->ad::lyt::LytAnim::stopAndSetFrm
118048e0: add      r7, r5, #0x60000
118048e4: add      r6, r5, #0x10000
118048e8: cmp      r4, #0
118048ec: add      r6, r6, #0x2a00
118048f0: str      r8, [r7, #0xff8]
118048f4: beq      #0x11804908
118048f8: ldr      r1, [pc, #0x13c]  ; =0x1180c130
118048fc: ldm      r1, {r0, r1}
11804900: strd     r0, r1, [r6, #4]
11804904: pop      {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
11804908: ldrb     r0, [sb, #0x13]
1180490c: cmp      r0, #0
11804910: beq      #0x11804a14
11804914: ldr      r4, [pc, #0x124]  ; =0x1180c32c
11804918: mov      r0, sl
1180491c: bl       #0x11800310  ; ->msys::MListWndPBase::getCurNo
11804920: add      r0, r0, r0, lsl #2
11804924: add      r0, r4, r0, lsl #2
11804928: add      r0, r0, #4
1180492c: ldrsh    r0, [r0]
11804930: rsb      r1, r0, #0
11804934: ldr      r0, [pc, #0xf4]  ; =0x3f95f0 gGameWork
11804938: bl       #0x118004a0  ; ->GameWork::addCoin
1180493c: add      r4, r5, #0x35400
11804940: ldr      r0, [pc, #0xe8]  ; =0x3f95f0 gGameWork
11804944: add      r4, r4, #0x1a8
11804948: bl       #0x118003d0  ; ->GameWork::getCoin
1180494c: mov      r1, r0
11804950: add      r0, r4, #0x150
11804954: bl       #0x118004a8  ; ->ad::lyt::LytNumReel3::setValue
11804958: ldr      r0, [r5, #8]
1180495c: ldr      r1, [pc, #0xe0]  ; =0x11001e
11804960: mov      r2, #0
11804964: add      ip, r0, #0x49000
11804968: add      ip, ip, #0x368
1180496c: mov      r3, r2
11804970: ldr      r0, [ip, #0xc]
11804974: mov      sb, r2
11804978: sub      r4, r0, #0x54
1180497c: sub      r0, ip, #0x4c
11804980: cmp      r0, r4
11804984: moveq    r4, r8
11804988: beq      #0x118049f0
1180498c: ldr      r8, [r4, #0x58]
11804990: add      r0, r4, #0x54
11804994: cmp      r8, r0
11804998: beq      #0x118049b4
1180499c: ldr      sl, [r0]
118049a0: str      r8, [sl, #4]
118049a4: ldr      sl, [r0]
118049a8: str      sl, [r8]
118049ac: str      r0, [r0]
118049b0: str      r0, [r0, #4]
118049b4: add      r0, r4, #0x54
118049b8: ldm      r0, {r8, sl}
118049bc: str      sl, [r8, #4]
118049c0: ldr      r0, [r4, #0x54]
118049c4: str      r0, [sl]
118049c8: adds     r0, r4, #0x54
118049cc: beq      #0x118049e4
118049d0: str      ip, [r0]
118049d4: ldr      r8, [ip, #4]
118049d8: str      r8, [r0, #4]
118049dc: str      r0, [r8]
118049e0: str      r0, [ip, #4]
118049e4: mov      r0, r4
118049e8: str      sb, [sp]
118049ec: bl       #0x118004b0  ; ->msys::MSndSe::play
118049f0: ldr      r0, [pc, #0x54]  ; =0x60ffc
118049f4: vldr     s0, [pc, #0x4c]  ; =0x41f00000 (30)
118049f8: str      r4, [r7, #0xff8]
118049fc: add      r0, r0, r5
11804a00: bl       #0x11800440  ; ->Frm::play
11804a04: ldr      r1, [pc, #0x44]  ; =0x1180c138
11804a08: ldm      r1, {r0, r1}
11804a0c: strd     r0, r1, [r6, #4]
11804a10: pop      {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
11804a14: ldr      r4, [pc, #0x38]  ; =0x1180c268
11804a18: mov      r0, sl
11804a1c: bl       #0x11800310  ; ->msys::MListWndPBase::getCurNo
11804a20: rsb      r0, r0, r0, lsl #3
11804a24: add      r0, r4, r0, lsl #2
11804a28: add      r0, r0, #0xc
11804a2c: b        #0x1180492c
11804a30: ldrshteq sb, [pc], -r0
11804a34: andeq    r0, r0, r0
11804a38: muleq    r6, ip, pc
11804a3c: orrne    ip, r0, r0, lsr r1
11804a40: orrne    ip, r0, ip, lsr #6
11804a44: andseq   r0, r1, lr, lsl r0
11804a48: mvnsmi   r0, r0
11804a4c: strdeq   r0, r1, [r6], -ip
11804a50: orrne    ip, r0, r8, lsr r1
11804a54: orrne    ip, r0, r8, ror #4
11804a58: push     {r4, lr}
11804a5c: ldr      r1, [r1]
11804a60: ldr      r2, [pc, #0x64]  ; =0x802
11804a64: mov      r4, r0
11804a68: add      r0, r0, #0x13000
11804a6c: tst      r1, r2
11804a70: beq      #0x11804a94
11804a74: ldr      r0, [r0, #0x34c]
11804a78: ldr      r1, [r0]
11804a7c: ldr      r1, [r1, #0x10]
11804a80: blx      r1
11804a84: mov      r1, #0
11804a88: mov      r0, r4
11804a8c: bl       #0x118068b4
11804a90: b        #0x11804abc
11804a94: ldr      r2, [pc, #0x34]  ; =0x401
11804a98: tst      r1, r2
11804a9c: beq      #0x11804abc
11804aa0: ldr      r0, [r0, #0x348]
11804aa4: ldr      r1, [r0]
11804aa8: ldr      r1, [r1, #0x10]
11804aac: blx      r1
11804ab0: mov      r1, #0
11804ab4: mov      r0, r4
11804ab8: bl       #0x118068b4
11804abc: add      r0, r4, #0x13000
11804ac0: add      r0, r0, #0x304
11804ac4: bl       #0x1180657c
11804ac8: pop      {r4, pc}
11804acc: andeq    r0, r0, r2, lsl #16
11804ad0: andeq    r0, r0, r1, lsl #8
11804ad4: push     {r4, r5, r6, lr}
11804ad8: mov      r4, r0
11804adc: add      r0, r0, #0x37000
11804ae0: mov      r2, #0
11804ae4: add      r1, pc, #0x54
11804ae8: add      r0, r0, #0x4c
11804aec: bl       #0x11805cbc
11804af0: mov      r5, #0
11804af4: add      r0, r4, r5, lsl #2
11804af8: add      r0, r0, #0x13000
11804afc: ldr      r0, [r0, #0x340]
11804b00: ldr      r1, [r0]
11804b04: ldr      r2, [r1, #0x28]
11804b08: mov      r1, #0
11804b0c: blx      r2
11804b10: add      r5, r5, #1
11804b14: cmp      r5, #7
11804b18: blt      #0x11804af4
11804b1c: mov      r1, #0
11804b20: mov      r0, r4
11804b24: bl       #0x118068b4
11804b28: ldr      r1, [pc, #0x24]  ; =0x1180c1e0
11804b2c: add      r2, r4, #0x10000
11804b30: add      r2, r2, #0x2a00
11804b34: ldm      r1, {r0, r1}
11804b38: strd     r0, r1, [r2, #4]
11804b3c: pop      {r4, r5, r6, pc}
11804b40: strbvc   r6, [lr, #-0x56d]!
11804b44: uqsaxvc  r7, r1, pc
11804b48: rsbvc    r5, r5, #0x194
11804b4c: teqlo    r0, r2, ror pc
11804b50: andeq    r0, r0, r0
11804b54: orrne    ip, r0, r0, ror #3
11804b58: push     {r3, r4, r5, r6, r7, lr}
11804b5c: add      r5, r0, #0x61000
11804b60: mov      r4, r0
11804b64: ldrb     r1, [r5, #0x13]
11804b68: mov      r6, #0
11804b6c: add      r0, r0, #0x12800
11804b70: add      r7, r4, #0x12c00
11804b74: cmp      r1, #0
11804b78: add      r0, r0, #0x3b4
11804b7c: add      r7, r7, #0x35c
11804b80: mov      r3, r6
11804b84: mov      r2, r6
11804b88: beq      #0x11804bb0
11804b8c: add      r1, pc, #0xa0
11804b90: bl       #0x11800338  ; ->msys::MLyt::createAnimeAutoSlot
11804b94: mov      r3, #0
11804b98: mov      r2, r3
11804b9c: mov      r1, #7
11804ba0: mov      r0, r7
11804ba4: str      r6, [sp]
11804ba8: bl       #0x11800350  ; ->msys::MLyt::playAnimeFromNo
11804bac: b        #0x11804bd0
11804bb0: add      r1, pc, #0x88
11804bb4: bl       #0x11800338  ; ->msys::MLyt::createAnimeAutoSlot
11804bb8: mov      r3, #0
11804bbc: mov      r2, r3
11804bc0: mov      r1, #6
11804bc4: mov      r0, r7
11804bc8: str      r6, [sp]
11804bcc: bl       #0x11800350  ; ->msys::MLyt::playAnimeFromNo
11804bd0: ldrb     r0, [r5, #0x10]
11804bd4: cmp      r0, #0
11804bd8: beq      #0x11804bf8
11804bdc: ldr      r0, [pc, #0x64]  ; =0x3fbf9c gSndSys
11804be0: ldr      r1, [pc, #0x64]  ; =0x100035b
11804be4: mov      r2, r0
11804be8: bl       #0x118004b8  ; ->SndSys::start
11804bec: nop      
11804bf0: nop      
11804bf4: b        #0x11804c0c
11804bf8: nop      
11804bfc: bl       #0x11800410  ; ->col::GetBootInfo
11804c00: nop      
11804c04: nop      
11804c08: bl       #0x11800448  ; ->col::BootInfo::restoreBgm
11804c0c: ldr      r0, [pc, #0x40]  ; =0x60ffc
11804c10: vldr     s0, [pc, #0x38]  ; =0x42700000 (60)
11804c14: add      r0, r0, r4
11804c18: bl       #0x11800440  ; ->Frm::play
11804c1c: ldr      r1, [pc, #0x34]  ; =0x1180c170
11804c20: add      r2, r4, #0x10000
11804c24: add      r2, r2, #0x2a00
11804c28: ldm      r1, {r0, r1}
11804c2c: strd     r0, r1, [r2, #4]
11804c30: pop      {r3, r4, r5, r6, r7, pc}
11804c34: strbvs   r7, [r7, #-0x568]!
11804c38: ldrbvc   r3, [pc], #-0x55f
11804c3c: eorseq   r5, r6, pc, ror #30
11804c40: svcvs    #0x745f35
11804c44: andeq    r3, r0, pc, asr r6
11804c48: mlaseq   pc, ip, pc, fp
11804c4c: qaddeq   r0, fp, r0
11804c50: rsbsmi   r0, r0, #0
11804c54: strdeq   r0, r1, [r6], -ip
11804c58: orrne    ip, r0, r0, ror r1
11804c5c: push     {r3, r4, r5, lr}
11804c60: add      r5, r0, #0x61000
11804c64: mov      r1, #0
11804c68: ldrb     r2, [r5, #0x13]
11804c6c: mov      r4, r0
11804c70: mov      r3, r1
11804c74: cmp      r2, #0
11804c78: str      r1, [sp]
11804c7c: add      r0, r0, #0x12c00
11804c80: add      r0, r0, #0x35c
11804c84: mov      r2, #1
11804c88: movne    r1, #5
11804c8c: moveq    r1, #4
11804c90: bl       #0x11800350  ; ->msys::MLyt::playAnimeFromNo
11804c94: ldrb     r1, [r5, #0x13]
11804c98: add      r0, r4, #0x3dc00
11804c9c: add      r0, r0, #0x384
11804ca0: cmp      r1, #0
11804ca4: beq      #0x11804cc0
11804ca8: ldr      r5, [pc, #0x48]  ; =0x1180c32c
11804cac: bl       #0x11800310  ; ->msys::MListWndPBase::getCurNo
11804cb0: add      r0, r0, r0, lsl #2
11804cb4: add      r0, r5, r0, lsl #2
11804cb8: add      r1, r0, #4
11804cbc: b        #0x11804cd4
11804cc0: ldr      r5, [pc, #0x34]  ; =0x1180c268
11804cc4: bl       #0x11800310  ; ->msys::MListWndPBase::getCurNo
11804cc8: rsb      r0, r0, r0, lsl #3
11804ccc: add      r0, r5, r0, lsl #2
11804cd0: add      r1, r0, #0xc
11804cd4: add      r0, r4, #0x4c000
11804cd8: add      r0, r0, #0x194
11804cdc: bl       #0x11805e48
11804ce0: ldr      r1, [pc, #0x18]  ; =0x1180c000
11804ce4: add      r2, r4, #0x10000
11804ce8: add      r2, r2, #0x2a00
11804cec: ldrd     r0, r1, [r1, #0xe0]
11804cf0: strd     r0, r1, [r2, #4]
11804cf4: pop      {r3, r4, r5, pc}
11804cf8: orrne    ip, r0, ip, lsr #6
11804cfc: orrne    ip, r0, r8, ror #4
11804d00: orrne    ip, r0, r0
11804d04: push     {r4, r5, r6, r7, r8, sb, sl, lr}
11804d08: mov      r4, r0
11804d0c: bl       #0x11805d28
11804d10: ldr      sl, [pc, #0x1b8]  ; =0x1180c000
11804d14: add      sb, r4, #0x10000
11804d18: cmp      r0, #0
11804d1c: add      sb, sb, #0x2a00
11804d20: beq      #0x11804d38
11804d24: mov      r1, #0
11804d28: mov      r0, r4
11804d2c: bl       #0x118068b4
11804d30: ldrd     r0, r1, [sl, #0xa8]
11804d34: b        #0x11804ec8
11804d38: mov      r3, #0
11804d3c: add      r0, r4, #0x12800
11804d40: mov      r2, r3
11804d44: add      r1, pc, #0x188
11804d48: add      r0, r0, #0x3b4
11804d4c: bl       #0x11800338  ; ->msys::MLyt::createAnimeAutoSlot
11804d50: add      r5, r4, #0x61000
11804d54: add      r0, r4, #0x12c00
11804d58: ldrb     r1, [r5, #0x13]
11804d5c: mov      r3, #0
11804d60: add      r0, r0, #0x35c
11804d64: cmp      r1, #0
11804d68: mov      r2, r3
11804d6c: addne    r1, pc, #0x168
11804d70: addeq    r1, pc, #0x15c
11804d74: bl       #0x11800338  ; ->msys::MLyt::createAnimeAutoSlot
11804d78: nop      
11804d7c: nop      
11804d80: bl       #0x11800400  ; ->GameMain::GameModeOld
11804d84: cmp      r0, #0xa
11804d88: nop      
11804d8c: beq      #0x11804da0
11804d90: bl       #0x11800400  ; ->GameMain::GameModeOld
11804d94: cmp      r0, #0
11804d98: nop      
11804d9c: bne      #0x11804dd0
11804da0: ldrb     r0, [r5, #0x10]
11804da4: cmp      r0, #0
11804da8: beq      #0x11804dd0
11804dac: ldr      r0, [pc, #0x134]  ; =0x3fbf9c gSndSys
11804db0: mov      r1, #0x10
11804db4: bl       #0x118004c0  ; ->SndSys::stopAllBgm
11804db8: nop      
11804dbc: nop      
11804dc0: bl       #0x11800410  ; ->col::GetBootInfo
11804dc4: nop      
11804dc8: nop      
11804dcc: bl       #0x11800448  ; ->col::BootInfo::restoreBgm
11804dd0: add      r0, r4, #0x3dc00
11804dd4: add      r0, r0, #0x384
11804dd8: ldrsb    r1, [r5, #0x13]
11804ddc: mov      r8, r0
11804de0: bl       #0x11806ab4
11804de4: mov      r0, #1
11804de8: strb     r0, [r8, #0x141]
11804dec: ldrb     r0, [r5, #0x13]
11804df0: mov      r7, #1
11804df4: cmp      r0, #0
11804df8: mov      r0, r8
11804dfc: beq      #0x11804e14
11804e00: bl       #0x11800310  ; ->msys::MListWndPBase::getCurNo
11804e04: ldrb     r1, [r5, #0xd]
11804e08: tst      r1, r7, lsl r0
11804e0c: beq      #0x11804e30
11804e10: b        #0x11804e28
11804e14: nop      
11804e18: bl       #0x11800310  ; ->msys::MListWndPBase::getCurNo
11804e1c: ldrb     r1, [r5, #0xc]
11804e20: tst      r1, r7, lsl r0
11804e24: beq      #0x11804e30
11804e28: mov      r6, #1
11804e2c: b        #0x11804e34
11804e30: mov      r6, #0
11804e34: ldrb     r0, [r5, #0x13]
11804e38: cmp      r0, #0
11804e3c: ldr      r0, [pc, #0xa8]  ; =0x3f95f0 gGameWork
11804e40: beq      #0x11804e78
11804e44: add      r5, r0, #0x800
11804e48: add      r5, r5, #4
11804e4c: mov      r0, r8
11804e50: bl       #0x11800310  ; ->msys::MListWndPBase::getCurNo
11804e54: add      r0, r5, r0, lsl #1
11804e58: mov      r1, r6
11804e5c: ldrsh    r0, [r0]
11804e60: add      r2, r7, r0, asr #31
11804e64: mov      r0, r4
11804e68: bl       #0x11806474
11804e6c: nop      
11804e70: nop      
11804e74: b        #0x11804eb8
11804e78: add      r5, r0, #0x7f0
11804e7c: mov      r0, r8
11804e80: bl       #0x11800310  ; ->msys::MListWndPBase::getCurNo
11804e84: add      r0, r5, r0, lsl #1
11804e88: ldrsh    r0, [r0]
11804e8c: add      r5, r7, r0, asr #31
11804e90: ldr      r7, [pc, #0x58]  ; =0x1180c268
11804e94: mov      r0, r8
11804e98: bl       #0x11800310  ; ->msys::MListWndPBase::getCurNo
11804e9c: rsb      r0, r0, r0, lsl #3
11804ea0: mov      r3, r5
11804ea4: add      r1, r7, r0, lsl #2
11804ea8: add      r0, r4, #0x4c000
11804eac: mov      r2, r6
11804eb0: add      r0, r0, #0x194
11804eb4: bl       #0x118061f4
11804eb8: mov      r1, #0
11804ebc: mov      r0, r4
11804ec0: bl       #0x118068b4
11804ec4: ldrd     r0, r1, [sl, #0xb0]
11804ec8: strd     r0, r1, [sb, #4]
11804ecc: pop      {r4, r5, r6, r7, r8, sb, sl, pc}
11804ed0: orrne    ip, r0, r0
11804ed4: svcvs    #0x745f36
11804ed8: andeq    r3, r0, pc, asr r2
11804edc: strbvs   r7, [r7, #-0x568]!
11804ee0: ldrbvc   r3, [pc], #-0x65f
11804ee4: eorseq   r5, r2, pc, ror #30
11804ee8: mlaseq   pc, ip, pc, fp
11804eec: ldrshteq sb, [pc], -r0
11804ef0: orrne    ip, r0, r8, ror #4
11804ef4: add      r2, r0, #0x10000
11804ef8: ldr      r0, [pc, #0xc]  ; =0x1180c080
11804efc: add      r2, r2, #0x2a00
11804f00: ldm      r0, {r0, r1}
11804f04: strd     r0, r1, [r2, #4]
11804f08: bx       lr
11804f0c: orrne    ip, r0, r0, lsl #1
11804f10: push     {r4, lr}
11804f14: mov      r4, r0
11804f18: bl       #0x11800400  ; ->GameMain::GameModeOld
11804f1c: cmp      r0, #0xa
11804f20: beq      #0x11804f30
11804f24: bl       #0x11800400  ; ->GameMain::GameModeOld
11804f28: cmp      r0, #0
11804f2c: bne      #0x11804f5c
11804f30: ldr      r0, [pc, #0x48]  ; =0x61010
11804f34: ldrb     r0, [r0, r4]
11804f38: cmp      r0, #0
11804f3c: bne      #0x11804f5c
11804f40: bl       #0x11800410  ; ->col::GetBootInfo
11804f44: nop      
11804f48: nop      
11804f4c: bl       #0x118004c8  ; ->col::BootInfo::playBgm
11804f50: cmp      r0, #0
11804f54: nop      
11804f58: beq      #0x11804f7c
11804f5c: ldr      r1, [r4, #4]
11804f60: mov      r0, #1
11804f64: strb     r0, [r1, #0x14]
11804f68: ldr      r1, [pc, #0x14]  ; =0x1180c000
11804f6c: add      r2, r4, #0x12800
11804f70: add      r2, r2, #0x1fc
11804f74: ldrd     r0, r1, [r1, #0x70]
11804f78: strd     r0, r1, [r2]
11804f7c: pop      {r4, pc}
11804f80: andeq    r1, r6, r0, lsl r0
11804f84: orrne    ip, r0, r0
11804f88: push     {r4, lr}
11804f8c: mov      r4, r0
11804f90: add      r0, r0, #0x35400
11804f94: add      r0, r0, #0x1a8
11804f98: ldr      r1, [r0, #0x1d4]
11804f9c: ldr      r0, [r0, #0x1cc]
11804fa0: cmp      r1, r0
11804fa4: bne      #0x11804fd0
11804fa8: ldr      r0, [pc, #0x24]  ; =0x60ff8
11804fac: ldr      r0, [r0, r4]
11804fb0: cmp      r0, #0
11804fb4: movne    r1, #0
11804fb8: blne     #0x118004d0  ; ->SndSeCtrl::stop
11804fbc: ldr      r1, [pc, #0x14]  ; =0x1180c130
11804fc0: add      r2, r4, #0x10000
11804fc4: add      r2, r2, #0x2a00
11804fc8: ldm      r1, {r0, r1}
11804fcc: strd     r0, r1, [r2, #4]
11804fd0: pop      {r4, pc}
11804fd4: strdeq   r0, r1, [r6], -r8
11804fd8: orrne    ip, r0, r0, lsr r1
11804fdc: push     {r4, r5, r6, r7, r8, sb, sl, fp, lr}
11804fe0: mov      r4, r0
11804fe4: add      sl, r4, #0x61000
11804fe8: ldr      r0, [pc, #0x2f0]  ; =0x60ffc
11804fec: ldr      fp, [pc, #0x2f0]  ; =0x3f62a8 msys::MComSys::_sys
11804ff0: vpush    {d8}
11804ff4: sub      sp, sp, #0x3c
11804ff8: ldrb     r1, [sl, #0xa]
11804ffc: vldr     s17, [pc, #0x2e4]  ; =0x3f800000 (1)
11805000: add      r6, r4, r0
11805004: tst      r1, #1
11805008: beq      #0x11805040
1180500c: ldr      r0, [r4, #8]
11805010: cmp      r0, #0
11805014: ldreq    r0, [fp]
11805018: streq    r0, [r4, #8]
1180501c: ldr      r0, [r0, #4]
11805020: bl       #0x118003e8  ; ->ad::fw::TaskBase::isFps30
11805024: cmp      r0, #0
11805028: vmoveq.f32 s0, s17
1180502c: vldrne   s0, [pc, #0x2b8]  ; =0x40000000 (2)
11805030: mov      r0, r6
11805034: bl       #0x118004d8  ; ->Frm::update
11805038: cmp      r0, #0
1180503c: bne      #0x11805280
11805040: add      r0, r4, #0x3dc00
11805044: add      r0, r0, #0x384
11805048: bl       #0x11800310  ; ->msys::MListWndPBase::getCurNo
1180504c: ldrb     r1, [sl, #0x13]
11805050: add      r8, r4, #0x12800
11805054: add      r7, r4, #0x12c00
11805058: vldr     s16, [pc, #0x290]  ; =0x0 (0)
1180505c: cmp      r1, #0
11805060: mov      ip, #1
11805064: add      r8, r8, #0x3b4
11805068: add      r7, r7, #0x35c
1180506c: mov      sb, #0
11805070: sxtb     r5, r0
11805074: beq      #0x11805118
11805078: ldr      r1, [r8, #0x150]
1180507c: add      lr, sp, #8
11805080: add      r0, sp, #4
11805084: vstmia   lr, {s16, s17}
11805088: add      r2, pc, #0x264
1180508c: vstr     s16, [sp, #0x10]
11805090: strh     ip, [sp, #0x14]
11805094: add      r3, pc, #0x268
11805098: strh     sb, [sp, #0x16]
1180509c: bl       #0x118002b0  ; ->ad::lyt::LytAnim::init
118050a0: vmov     s0, r5
118050a4: add      r0, sp, #4
118050a8: vcvt.f32.s32 s0, s0
118050ac: bl       #0x118002c0  ; ->ad::lyt::LytAnim::stopAndSetFrm
118050b0: mov      r1, #1
118050b4: add      r0, sp, #4
118050b8: bl       #0x118002c8  ; ->ad::lyt::LytAnim::term
118050bc: vstr     s16, [sp, #0x10]
118050c0: ldr      r0, [r4, #8]
118050c4: add      r2, r5, r5, lsl #2
118050c8: ldr      r1, [pc, #0x238]  ; =0x1180c32c
118050cc: cmp      r0, #0
118050d0: ldreq    r0, [fp]
118050d4: add      r1, r1, r2, lsl #2
118050d8: add      r5, r0, #0xe9000
118050dc: streq    r0, [r4, #8]
118050e0: add      r0, r0, #0xe9000
118050e4: ldr      r1, [r1, #0x10]
118050e8: add      r5, r5, #0x50
118050ec: add      r0, r0, #0x58
118050f0: bl       #0x11800290  ; ->LMS_GetTextIndexByLabel
118050f4: mov      r1, r0
118050f8: add      r0, r5, #8
118050fc: bl       #0x11800298  ; ->LMS_GetText
11805100: mov      r1, r0
11805104: mov      r3, #0
11805108: add      r0, r4, #0x2e800
1180510c: mov      r2, r3
11805110: add      r0, r0, #0x164
11805114: b        #0x118051cc
11805118: ldr      r1, [r7, #0x150]
1180511c: add      lr, sp, #0x24
11805120: add      r0, sp, #0x20
11805124: vstmia   lr, {s16, s17}
11805128: add      r2, pc, #0x1c4
1180512c: vstr     s16, [sp, #0x2c]
11805130: strh     ip, [sp, #0x30]
11805134: add      r3, pc, #0x1c8
11805138: strh     sb, [sp, #0x32]
1180513c: bl       #0x118002b0  ; ->ad::lyt::LytAnim::init
11805140: cmp      r5, #6
11805144: movlt    r0, r5
11805148: movge    r0, #0
1180514c: vmov     s0, r0
11805150: add      r0, sp, #0x20
11805154: vcvt.f32.s32 s0, s0
11805158: bl       #0x118002c0  ; ->ad::lyt::LytAnim::stopAndSetFrm
1180515c: mov      r1, #1
11805160: add      r0, sp, #0x20
11805164: bl       #0x118002c8  ; ->ad::lyt::LytAnim::term
11805168: add      r0, r4, #0x27000
1180516c: vstr     s16, [sp, #0x2c]
11805170: add      r0, r0, #0xd20
11805174: str      r0, [sp]
11805178: ldr      r0, [pc, #0x18c]  ; =0x1180c268
1180517c: ldr      r1, [r4, #8]
11805180: cmp      r5, #6
11805184: bge      #0x118051d4
11805188: cmp      r1, #0
1180518c: ldreq    r1, [fp]
11805190: rsb      r2, r5, r5, lsl #3
11805194: add      r0, r0, r2, lsl #2
11805198: add      r5, r1, #0xe9000
1180519c: streq    r1, [r4, #8]
118051a0: ldr      r1, [r0, #0x18]
118051a4: add      r5, r5, #0x50
118051a8: add      r0, r5, #8
118051ac: bl       #0x11800290  ; ->LMS_GetTextIndexByLabel
118051b0: mov      r1, r0
118051b4: add      r0, r5, #8
118051b8: bl       #0x11800298  ; ->LMS_GetText
118051bc: mov      r1, r0
118051c0: mov      r3, #0
118051c4: ldr      r0, [sp]
118051c8: mov      r2, r3
118051cc: bl       #0x118002a0  ; ->msys::MMsg::playStr
118051d0: b        #0x1180521c
118051d4: cmp      r1, #0
118051d8: ldreq    r1, [fp]
118051dc: mov      r2, r1
118051e0: streq    r1, [r4, #8]
118051e4: ldr      r1, [r0, #8]
118051e8: add      r5, r2, #0xe9000
118051ec: add      r0, r2, #0xe9000
118051f0: add      r5, r5, #0x50
118051f4: add      r0, r0, #0x58
118051f8: bl       #0x11800290  ; ->LMS_GetTextIndexByLabel
118051fc: mov      r1, r0
11805200: add      r0, r5, #8
11805204: bl       #0x11800298  ; ->LMS_GetText
11805208: mov      r1, r0
1180520c: mov      r3, #0
11805210: ldr      r0, [sp]
11805214: mov      r2, r3
11805218: bl       #0x118002a0  ; ->msys::MMsg::playStr
1180521c: ldrb     r1, [sl, #0x13]
11805220: ldr      r2, [pc, #0xec]  ; =0x1180c000
11805224: add      r0, r4, #0x10000
11805228: vldr     s16, [pc, #0xe0]  ; =0x42700000 (60)
1180522c: cmp      r1, #0
11805230: add      r0, r0, #0x2a00
11805234: beq      #0x1180528c
11805238: add      r2, r2, #0x140
1180523c: add      r0, r0, #4
11805240: ldm      r2, {r1, r2}
11805244: mov      r3, #0
11805248: stm      r0, {r1, r2}
1180524c: mov      r2, r3
11805250: add      r1, pc, #0xc0
11805254: mov      r0, r8
11805258: bl       #0x11800338  ; ->msys::MLyt::createAnimeAutoSlot
1180525c: mov      r3, #0
11805260: mov      r2, #1
11805264: mov      r1, #7
11805268: mov      r0, r7
1180526c: str      sb, [sp]
11805270: bl       #0x11800350  ; ->msys::MLyt::playAnimeFromNo
11805274: vmov.f32 s0, s16
11805278: mov      r0, r6
1180527c: bl       #0x11800440  ; ->Frm::play
11805280: add      sp, sp, #0x3c
11805284: vpop     {d8}
11805288: pop      {r4, r5, r6, r7, r8, sb, sl, fp, pc}
1180528c: add      r2, r2, #0x148
11805290: add      r0, r0, #4
11805294: ldm      r2, {r1, r2}
11805298: mov      r3, #0
1180529c: stm      r0, {r1, r2}
118052a0: mov      r2, r3
118052a4: add      r1, pc, #0x78
118052a8: mov      r0, r8
118052ac: bl       #0x11800338  ; ->msys::MLyt::createAnimeAutoSlot
118052b0: mov      r3, #0
118052b4: mov      r2, #1
118052b8: mov      r1, #6
118052bc: mov      r0, r7
118052c0: str      sb, [sp]
118052c4: bl       #0x11800350  ; ->msys::MLyt::playAnimeFromNo
118052c8: vmov.f32 s0, s16
118052cc: mov      r0, r6
118052d0: bl       #0x11800440  ; ->Frm::play
118052d4: add      sp, sp, #0x3c
118052d8: vpop     {d8}
118052dc: pop      {r4, r5, r6, r7, r8, sb, sl, fp, pc}
118052e0: strdeq   r0, r1, [r6], -ip
118052e4: eorseq   r6, pc, r8, lsr #5
118052e8: svclo    #0x800000
118052ec: andmi    r0, r0, r0
118052f0: andeq    r0, r0, r0
118052f4: svcpl    #0x544553
118052f8: stclmi   p14, c4, [r5, #-0x114]
118052fc: stclmi   p15, c5, [sb, #-0x164]
11805300: andeq    r0, r0, r7, asr #32
11805304: andeq    r0, r0, r0
11805308: orrne    ip, r0, ip, lsr #6
1180530c: orrne    ip, r0, r8, ror #4
11805310: rsbsmi   r0, r0, #0
11805314: orrne    ip, r0, r0
11805318: strbvs   r7, [r7, #-0x568]!
1180531c: ldrbvc   r3, [pc], #-0x35f
11805320: eorseq   r5, r4, pc, ror #30
11805324: svcvs    #0x745f33
11805328: andeq    r3, r0, pc, asr r4
1180532c: push     {r3, r4, r5, lr}
11805330: mov      r4, r0
11805334: add      r0, r0, #0x13000
11805338: mov      r1, #0
1180533c: add      r0, r0, #0x304
11805340: bl       #0x118003f0  ; ->msys::MCursorBase::setVisible
11805344: ldr      r1, [pc, #0x4c]  ; =0x61013
11805348: add      r0, r4, #0x12c00
1180534c: add      r0, r0, #0x35c
11805350: ldrb     r2, [r1, r4]
11805354: mov      r1, #0
11805358: mov      r3, r1
1180535c: cmp      r2, #0
11805360: mov      r2, r1
11805364: str      r1, [sp]
11805368: movne    r1, #5
1180536c: moveq    r1, #4
11805370: bl       #0x11800350  ; ->msys::MLyt::playAnimeFromNo
11805374: ldr      r0, [pc, #0x20]  ; =0x3e0c5
11805378: mov      r1, #1
1180537c: add      r2, r4, #0x10000
11805380: add      r2, r2, #0x2a00
11805384: strb     r1, [r0, r4]
11805388: ldr      r1, [pc, #0x10]  ; =0x1180c000
1180538c: ldrd     r0, r1, [r1, #0xb0]
11805390: strd     r0, r1, [r2, #4]
11805394: pop      {r3, r4, r5, pc}
11805398: andeq    r1, r6, r3, lsl r0
1180539c: andeq    lr, r3, r5, asr #1
118053a0: orrne    ip, r0, r0
118053a4: bx       lr
118053a8: push     {r3, r4, r5, r6, r7, lr}
118053ac: mov      r4, r0
118053b0: add      r0, r0, #0x45000
118053b4: add      r0, r0, #0x110
118053b8: mov      r5, r1
118053bc: mov      r6, r0
118053c0: bl       #0x11800308  ; ->msys::MListWndPBase::isTpNeutral
118053c4: cmp      r0, #0
118053c8: beq      #0x1180543c
118053cc: mov      r0, r6
118053d0: bl       #0x11800318  ; ->msys::MListWndPBase::getCurItem
118053d4: cmp      r0, #0
118053d8: beq      #0x11805450
118053dc: mov      r0, r6
118053e0: bl       #0x11800320  ; ->msys::MListWndPBase::getSelectItem
118053e4: cmp      r0, #0
118053e8: beq      #0x11805450
118053ec: mov      r0, r6
118053f0: bl       #0x11800318  ; ->msys::MListWndPBase::getCurItem
118053f4: ldrb     r1, [r0, #0xe]
118053f8: mov      r0, #0
118053fc: mov      r3, r0
11805400: cmp      r1, #0
11805404: mov      r2, r0
11805408: str      r0, [sp]
1180540c: beq      #0x11805440
11805410: ldr      r1, [pc, #0x6c]  ; =0x110016
11805414: mov      r0, r4
11805418: bl       #0x11806814
1180541c: mov      r1, #0
11805420: mov      r0, r4
11805424: bl       #0x118068b4
11805428: ldr      r1, [pc, #0x58]  ; =0x1180c110
1180542c: add      r2, r4, #0x10000
11805430: add      r2, r2, #0x2a00
11805434: ldm      r1, {r0, r1}
11805438: strd     r0, r1, [r2, #4]
1180543c: pop      {r3, r4, r5, r6, r7, pc}
11805440: ldr      r1, [pc, #0x44]  ; =0x110018
11805444: mov      r0, r4
11805448: bl       #0x11806814
1180544c: pop      {r3, r4, r5, r6, r7, pc}
11805450: ldr      r0, [r5]
11805454: ldr      r1, [pc, #0x34]  ; =0x802
11805458: tst      r0, r1
1180545c: beq      #0x1180543c
11805460: ldr      r0, [pc, #0x2c]  ; =0x1334c
11805464: ldr      r0, [r0, r4]
11805468: ldr      r1, [r0]
1180546c: ldr      r1, [r1, #0x10]
11805470: blx      r1
11805474: mov      r0, r4
11805478: pop      {r3, r4, r5, r6, r7, lr}
1180547c: mov      r1, #0
11805480: b        #0x118068b4
11805484: andseq   r0, r1, r6, lsl r0
11805488: orrne    ip, r0, r0, lsl r1
1180548c: andseq   r0, r1, r8, lsl r0
11805490: andeq    r0, r0, r2, lsl #16
11805494: andeq    r3, r1, ip, asr #6
11805498: push     {r4, r5, r6, r7, r8, lr}
1180549c: mov      r4, r0
118054a0: mov      r6, r1
118054a4: ldr      r0, [r1]
118054a8: ldr      r1, [pc, #0xf8]  ; =0x802
118054ac: ldr      r7, [pc, #0xf8]  ; =0x3f62a8 msys::MComSys::_sys
118054b0: add      r5, r4, #0x13000
118054b4: tst      r0, r1
118054b8: beq      #0x118054e8
118054bc: ldr      r0, [r5, #0x34c]
118054c0: ldr      r1, [r0]
118054c4: ldr      r1, [r1, #0x10]
118054c8: blx      r1
118054cc: ldr      r0, [r4, #8]
118054d0: cmp      r0, #0
118054d4: beq      #0x1180559c
118054d8: add      r1, r0, #0xe6000
118054dc: mov      r0, #0
118054e0: strb     r0, [r1, #0x508]
118054e4: pop      {r4, r5, r6, r7, r8, pc}
118054e8: add      r0, r4, #0x12c00
118054ec: add      r0, r0, #0x35c
118054f0: mov      r3, #0
118054f4: add      r2, pc, #0xb4
118054f8: add      r1, pc, #0xc0
118054fc: mov      r8, r0
11805500: bl       #0x118002f0  ; ->msys::MLyt::getParts
11805504: ldrb     r0, [r0, #0x44]
11805508: tst      r0, #1
1180550c: ldrbne   r0, [r6]
11805510: tstne    r0, #0x20
11805514: beq      #0x11805548
11805518: ldr      r0, [r5, #0x354]
1180551c: ldr      r1, [r0]
11805520: ldr      r1, [r1, #0x10]
11805524: blx      r1
11805528: ldr      r0, [r5, #0x354]
1180552c: ldr      r1, [r0]
11805530: ldr      r1, [r1, #0xc]
11805534: blx      r1
11805538: ldr      r0, [r4, #8]
1180553c: cmp      r0, #0
11805540: beq      #0x1180559c
11805544: b        #0x118054d8
11805548: mov      r3, #0
1180554c: add      r2, pc, #0x5c
11805550: add      r1, pc, #0x70
11805554: mov      r0, r8
11805558: bl       #0x118002f0  ; ->msys::MLyt::getParts
1180555c: ldrb     r0, [r0, #0x44]
11805560: tst      r0, #1
11805564: ldrbne   r0, [r6]
11805568: tstne    r0, #0x10
1180556c: beq      #0x118054e4
11805570: ldr      r0, [r5, #0x358]
11805574: ldr      r1, [r0]
11805578: ldr      r1, [r1, #0x10]
1180557c: blx      r1
11805580: ldr      r0, [r5, #0x358]
11805584: ldr      r1, [r0]
11805588: ldr      r1, [r1, #0xc]
1180558c: blx      r1
11805590: ldr      r0, [r4, #8]
11805594: cmp      r0, #0
11805598: bne      #0x118054d8
1180559c: ldr      r0, [r7]
118055a0: str      r0, [r4, #8]
118055a4: b        #0x118054d8
118055a8: andeq    r0, r0, r2, lsl #16
118055ac: eorseq   r6, pc, r8, lsr #5
118055b0: strbmi   r5, [sb], #-0x547
118055b4: ldmdapl  r4, {r0, r2, r6, r8, sb, sl, fp, ip, lr} ^
118055b8: qdsubvs  r5, r4, r2
118055bc: andeq    r6, r0, r3, ror r5
118055c0: svcpl    #0x6e7462
118055c4: andeq    r0, r0, ip, asr #32
118055c8: svcpl    #0x6e7462
118055cc: andeq    r0, r0, r2, asr r0
118055d0: push     {r4, r5, r6, lr}
118055d4: mov      r4, r0
118055d8: add      r0, r0, #0x12c00
118055dc: add      r0, r0, #0x35c
118055e0: bl       #0x11800450  ; ->msys::MLyt::isEnableAnime
118055e4: cmp      r0, #0
118055e8: bne      #0x1180567c
118055ec: bl       #0x11800410  ; ->col::GetBootInfo
118055f0: bl       #0x118004c8  ; ->col::BootInfo::playBgm
118055f4: cmp      r0, #0
118055f8: movne    r5, #0
118055fc: beq      #0x1180567c
11805600: add      r0, r4, r5, lsl #2
11805604: add      r0, r0, #0x13000
11805608: ldr      r0, [r0, #0x340]
1180560c: ldr      r1, [r0]
11805610: ldr      r2, [r1, #0x28]
11805614: mov      r1, #0
11805618: blx      r2
1180561c: add      r5, r5, #1
11805620: cmp      r5, #7
11805624: blt      #0x11805600
11805628: ldr      r0, [pc, #0x50]  ; =0x1334c
1180562c: ldr      r0, [r0, r4]
11805630: ldr      r1, [r0]
11805634: ldr      r2, [r1, #0x28]
11805638: mov      r1, #1
1180563c: blx      r2
11805640: add      r0, r4, #0x45000
11805644: add      r0, r0, #0x108
11805648: mov      r1, #0
1180564c: mvn      r2, #0
11805650: stm      r0, {r1, r2}
11805654: mov      r1, #1
11805658: mov      r0, r4
1180565c: bl       #0x118068b4
11805660: ldr      r2, [pc, #0x1c]  ; =0x1180c0b8
11805664: add      r0, r4, #0x12800
11805668: add      r0, r0, #0x204
1180566c: ldm      r2!, {r1, r3}
11805670: stm      r0!, {r1, r3}
11805674: ldm      r2, {r1, r2}
11805678: stm      r0, {r1, r2}
1180567c: pop      {r4, r5, r6, pc}
11805680: andeq    r3, r1, ip, asr #6
11805684: strhne   ip, [r0, r8]
11805688: ldr      r0, [pc, #0x90]  ; =0x3f62a8 msys::MComSys::_sys
1180568c: push     {r3, r4, r5, r6, r7, lr}
11805690: mov      r2, #0
11805694: mov      r3, r2
11805698: ldr      r0, [r0]
1180569c: mov      r5, r2
118056a0: add      r4, r0, #0x49000
118056a4: add      r4, r4, #0x368
118056a8: sub      ip, r4, #0x4c
118056ac: ldr      r0, [r4, #0xc]
118056b0: sub      r0, r0, #0x54
118056b4: cmp      ip, r0
118056b8: beq      #0x1180571c
118056bc: ldr      r6, [r0, #0x58]
118056c0: add      ip, r0, #0x54
118056c4: cmp      r6, ip
118056c8: beq      #0x118056e4
118056cc: ldr      r7, [ip]
118056d0: str      r6, [r7, #4]
118056d4: ldr      r7, [ip]
118056d8: str      r7, [r6]
118056dc: str      ip, [ip]
118056e0: str      ip, [ip, #4]
118056e4: add      ip, r0, #0x54
118056e8: ldrd     r6, r7, [ip]
118056ec: str      r7, [r6, #4]
118056f0: ldr      ip, [r0, #0x54]
118056f4: str      ip, [r7]
118056f8: adds     ip, r0, #0x54
118056fc: beq      #0x11805714
11805700: str      r4, [ip]
11805704: ldr      r6, [r4, #4]
11805708: str      r6, [ip, #4]
1180570c: str      ip, [r6]
11805710: str      ip, [r4, #4]
11805714: str      r5, [sp]
11805718: bl       #0x118004b0  ; ->msys::MSndSe::play
1180571c: pop      {r3, r4, r5, r6, r7, pc}
11805720: eorseq   r6, pc, r8, lsr #5
11805724: push     {r4, r5, r6, lr}
11805728: mov      r5, r0
1180572c: ldr      r0, [pc, #0x140]  ; =0x1180ca44
11805730: mov      r1, #0
11805734: str      r0, [r5]
11805738: ldr      r0, [r5, #4]
1180573c: bl       #0x118004e0  ; ->ad::fw::TaskBase::term
11805740: add      r0, r5, #0xe9000
11805744: add      r0, r0, #0x124
11805748: mov      r4, r0
1180574c: bl       #0x118004e8  ; ->msys::MLyt::term
11805750: add      r0, r5, #0xe9000
11805754: add      r0, r0, #0xe0
11805758: bl       #0x118004f0  ; ->ad::fw::Resource::term
1180575c: ldr      r0, [pc, #0x114]  ; =0x3e4580
11805760: str      r0, [r4]
11805764: mov      r0, r4
11805768: bl       #0x118004e8  ; ->msys::MLyt::term
1180576c: ldr      r1, [pc, #0x108]  ; =0x118012dc
11805770: mov      r3, #0xc
11805774: mov      r2, #0x10
11805778: add      r0, r4, #0x2b0
1180577c: bl       #0x118004f8  ; ->__aeabi_vec_dtor
11805780: ldr      r1, [pc, #0xf8]  ; =0x11801148
11805784: mov      r3, #0xc
11805788: mov      r2, #0x1c
1180578c: add      r0, r4, #0x154
11805790: bl       #0x118004f8  ; ->__aeabi_vec_dtor
11805794: mov      r0, r4
11805798: bl       #0x118059d0
1180579c: sub      r0, r0, #0x44
118057a0: bl       #0x11800500  ; ->ad::fw::Resource
118057a4: sub      r4, r0, #0x24
118057a8: ldr      r0, [pc, #0xd4]  ; =0x1180c9b0
118057ac: str      r0, [r4]
118057b0: ldr      r0, [r4, #0x20]
118057b4: cmp      r0, #0
118057b8: beq      #0x118057c8
118057bc: ldr      r1, [r0]
118057c0: ldr      r1, [r1, #4]
118057c4: blx      r1
118057c8: mov      r0, #0
118057cc: str      r0, [r4, #0x20]
118057d0: ldr      r0, [pc, #0xb0]  ; =0x3e483c
118057d4: str      r0, [r4], #0x10
118057d8: ldr      r0, [r4], #-4
118057dc: cmp      r0, r4
118057e0: beq      #0x118057fc
118057e4: ldr      r1, [r0, #4]
118057e8: str      r0, [r0, #4]
118057ec: str      r0, [r0]
118057f0: cmp      r1, r4
118057f4: mov      r0, r1
118057f8: bne      #0x118057e4
118057fc: str      r4, [r4, #4]
11805800: mov      r1, r4
11805804: str      r4, [r4]
11805808: ldr      r0, [r4, #4]!
1180580c: str      r0, [r1, #4]
11805810: ldr      r1, [r4, #-4]
11805814: str      r1, [r0]
11805818: ldr      r0, [r4, #-8]
1180581c: sub      r1, r4, #0xc
11805820: cmp      r0, r1
11805824: beq      #0x11805840
11805828: ldr      r2, [r0, #4]
1180582c: str      r0, [r0, #4]
11805830: str      r0, [r0]
11805834: cmp      r2, r1
11805838: mov      r0, r2
1180583c: bne      #0x11805828
11805840: str      r1, [r1, #4]
11805844: str      r1, [r1]
11805848: ldr      r2, [r1], #4
1180584c: ldr      r0, [r1], #4
11805850: str      r0, [r2, #4]
11805854: ldr      r2, [r1, #-8]
11805858: str      r2, [r0]
1180585c: sub      r0, r1, #0x78
11805860: bl       #0x11800198  ; ->MsgDataAcsrBase
11805864: pop      {r4, r5, r6, lr}
11805868: sub      r0, r0, #0xe9000
1180586c: sub      r0, r0, #0x50
11805870: b        #0x11800508  ; ->msys::MComSys
11805874: orrne    ip, r0, r4, asr #20
11805878: eorseq   r4, lr, r0, lsl #11
1180587c: ldrdne   r1, r2, [r0, ip]
11805880: orrne    r1, r0, r8, asr #2
11805884: strhne   ip, [r0, r0]
11805888: eorseq   r4, lr, ip, lsr r8
1180588c: mov      r2, #0
11805890: add      r1, r0, #4
11805894: vldr     s0, [pc, #0x24]  ; =0x0 (0)
11805898: vldr     s1, [pc, #0x24]  ; =0x3f800000 (1)
1180589c: strb     r2, [r0]
118058a0: mov      r3, #1
118058a4: vstmia   r1, {s0, s1}
118058a8: vstr     s0, [r0, #0xc]
118058ac: strh     r3, [r0, #0x10]
118058b0: strh     r2, [r0, #0x12]
118058b4: str      r2, [r0, #0x14]
118058b8: str      r2, [r0, #0x18]
118058bc: bx       lr
118058c0: andeq    r0, r0, r0
118058c4: svclo    #0x800000
118058c8: and      r1, r1, #0xff
118058cc: orr      r1, r1, r1, lsl #8
118058d0: orr      r1, r1, r1, lsl #16
118058d4: str      r1, [r0]
118058d8: str      r1, [r0, #4]
118058dc: str      r1, [r0, #8]
118058e0: bx       lr
118058e4: mov      r1, r0
118058e8: ldr      r0, [pc, #0xd0]  ; =0x3e435c
118058ec: push     {r4, r5, r6, lr}
118058f0: mov      r5, #0
118058f4: str      r0, [r1]
118058f8: add      r0, r1, #4
118058fc: str      r0, [r1, #4]
11805900: str      r0, [r1, #8]
11805904: str      r5, [r1, #0xc]
11805908: add      r0, r1, #0x14
1180590c: strb     r5, [r1, #0x10]
11805910: bl       #0x11800510  ; ->MoveVBase
11805914: ldr      r6, [pc, #0xa8]  ; =0x1180c820
11805918: ldr      r1, [pc, #0xa8]  ; =0x1180b8fc
1180591c: mov      r3, #1
11805920: mov      r2, #0x2c
11805924: str      r6, [r0], #0x30
11805928: bl       #0x11800518  ; ->__aeabi_vec_ctor_nocookie_nodtor
1180592c: mov      r4, #1
11805930: str      r0, [r0, #-8]
11805934: strb     r4, [r0, #-4]
11805938: add      r0, r0, #0x2c
1180593c: bl       #0x11800510  ; ->MoveVBase
11805940: ldr      r1, [pc, #0x80]  ; =0x1180b8fc
11805944: mov      r3, #1
11805948: mov      r2, #0x2c
1180594c: str      r6, [r0], #0x30
11805950: bl       #0x11800518  ; ->__aeabi_vec_ctor_nocookie_nodtor
11805954: str      r0, [r0, #-8]
11805958: strb     r4, [r0, #-4]
1180595c: add      r0, r0, #0x2c
11805960: bl       #0x11800510  ; ->MoveVBase
11805964: ldr      r1, [pc, #0x5c]  ; =0x1180b8fc
11805968: mov      r3, #1
1180596c: mov      r2, #0x2c
11805970: str      r6, [r0], #0x30
11805974: bl       #0x11800518  ; ->__aeabi_vec_ctor_nocookie_nodtor
11805978: str      r0, [r0, #-8]
1180597c: strb     r4, [r0, #-4]
11805980: str      r5, [r0, #0x2c]
11805984: str      r5, [r0, #0x30]
11805988: str      r5, [r0, #0x34]
1180598c: strb     r5, [r0, #0x38]
11805990: strb     r5, [r0, #0x39]
11805994: str      r5, [r0, #0x3c]
11805998: str      r5, [r0, #0x40]
1180599c: ldr      r1, [pc, #0x28]  ; =0x1180cad0
118059a0: strb     r4, [r0, #0x44]
118059a4: strb     r4, [r0, #0x45]
118059a8: strb     r4, [r0, #0x46]
118059ac: str      r1, [r0, #-0xfc]!
118059b0: add      r1, r0, #0x144
118059b4: str      r1, [r0, #0x144]
118059b8: str      r1, [r0, #0x148]
118059bc: pop      {r4, r5, r6, pc}
118059c0: eorseq   r4, lr, ip, asr r3
118059c4: orrne    ip, r0, r0, lsr #16
118059c8: strdne   fp, ip, [r0, ip]
118059cc: ldrdne   ip, sp, [r0, r0]
118059d0: ldr      r1, [pc, #0x144]  ; =0x1180cad0
118059d4: push     {r4, r5, r6, lr}
118059d8: str      r1, [r0], #0x148
118059dc: ldr      r1, [r0], #-4
118059e0: cmp      r1, r0
118059e4: beq      #0x11805a00
118059e8: ldr      r2, [r1, #4]
118059ec: str      r1, [r1, #4]
118059f0: str      r1, [r1]
118059f4: cmp      r2, r0
118059f8: mov      r1, r2
118059fc: bne      #0x118059e8
11805a00: str      r0, [r0, #4]
11805a04: str      r0, [r0]
11805a08: ldr      r2, [r0]
11805a0c: ldr      r1, [r0, #4]
11805a10: str      r1, [r2, #4]
11805a14: ldr      r2, [r0], #-0x144
11805a18: str      r2, [r1]
11805a1c: ldr      r1, [pc, #0xfc]  ; =0x3e435c
11805a20: str      r1, [r0], #0x128
11805a24: mov      r5, r0
11805a28: ldr      r2, [r0, #8]
11805a2c: cmp      r2, #0
11805a30: beq      #0x11805a88
11805a34: ldr      r1, [r5]
11805a38: mov      r4, r5
11805a3c: add      r0, r2, #0x254
11805a40: cmp      r1, #0
11805a44: ldrne    r2, [r4, #4]
11805a48: strne    r2, [r1, #4]
11805a4c: ldr      r1, [r4, #4]
11805a50: cmp      r1, #0
11805a54: ldrne    r2, [r4]
11805a58: strne    r2, [r1]
11805a5c: ldr      r1, [r0]
11805a60: cmp      r1, r4
11805a64: ldreq    r1, [r4, #4]
11805a68: streq    r1, [r0]
11805a6c: mov      r1, #0
11805a70: str      r1, [r4, #4]
11805a74: str      r1, [r4]
11805a78: str      r1, [r5, #8]
11805a7c: ldr      r1, [r0, #4]
11805a80: sub      r1, r1, #1
11805a84: str      r1, [r0, #4]
11805a88: ldr      r6, [pc, #0x94]  ; =0x1180c820
11805a8c: ldr      r1, [pc, #0x94]  ; =0x1180b940
11805a90: mov      r3, #1
11805a94: str      r6, [r5, #-0x5c]!
11805a98: mov      r2, #0x2c
11805a9c: add      r0, r5, #0x30
11805aa0: bl       #0x118004f8  ; ->__aeabi_vec_dtor
11805aa4: mov      r0, r5
11805aa8: nop      
11805aac: bl       #0x11800520  ; ->MoveVBase
11805ab0: sub      r4, r0, #0x5c
11805ab4: str      r6, [r0, #-0x5c]
11805ab8: ldr      r1, [pc, #0x68]  ; =0x1180b940
11805abc: mov      r3, #1
11805ac0: mov      r2, #0x2c
11805ac4: sub      r0, r0, #0x2c
11805ac8: bl       #0x118004f8  ; ->__aeabi_vec_dtor
11805acc: mov      r0, r4
11805ad0: nop      
11805ad4: bl       #0x11800520  ; ->MoveVBase
11805ad8: sub      r4, r0, #0x5c
11805adc: str      r6, [r0, #-0x5c]
11805ae0: ldr      r1, [pc, #0x40]  ; =0x1180b940
11805ae4: mov      r3, #1
11805ae8: mov      r2, #0x2c
11805aec: sub      r0, r0, #0x2c
11805af0: bl       #0x118004f8  ; ->__aeabi_vec_dtor
11805af4: mov      r0, r4
11805af8: nop      
11805afc: bl       #0x11800520  ; ->MoveVBase
11805b00: sub      r1, r0, #0x10
11805b04: ldrd     r2, r3, [r1]
11805b08: str      r3, [r2, #4]
11805b0c: ldr      r1, [r0, #-0x10]
11805b10: sub      r0, r0, #0x14
11805b14: str      r1, [r3]
11805b18: pop      {r4, r5, r6, pc}
11805b1c: ldrdne   ip, sp, [r0, r0]
11805b20: eorseq   r4, lr, ip, asr r3
11805b24: orrne    ip, r0, r0, lsr #16
11805b28: orrne    fp, r0, r0, asr #18
11805b2c: push     {r4, r5, r6, r7, r8, sb, sl, fp, lr}
11805b30: sub      sp, sp, #0xc
11805b34: mov      r7, r0
11805b38: mov      sl, r3
11805b3c: mov      fp, r2
11805b40: mov      sb, r1
11805b44: bl       #0x11800428  ; ->btl::GetBootInfo
11805b48: mov      r5, #0
11805b4c: strb     r5, [r0]
11805b50: strb     r5, [r0, #0x30]
11805b54: strb     r5, [r0, #0x60]
11805b58: strb     r5, [r0, #0x90]
11805b5c: str      r5, [r0, #0xc0]
11805b60: mov      r8, #3
11805b64: str      r5, [r0, #0xc4]
11805b68: strb     r8, [r0, #0xc8]
11805b6c: vldr     s1, [pc, #0x128]  ; =0x0 (0)
11805b70: strb     r5, [r0, #0xc9]
11805b74: strb     r5, [r0, #0xca]
11805b78: strb     r5, [r0, #0xcb]
11805b7c: vmov.f32 s0, s1
11805b80: strb     r5, [r0, #0xcc]
11805b84: mov      r6, #1
11805b88: strb     r5, [r0, #0xcd]
11805b8c: strb     r6, [r0, #0xce]
11805b90: strb     r6, [r0, #0xcf]
11805b94: mov      r4, r0
11805b98: add      r1, r0, #0x100
11805b9c: mov      r2, #4
11805ba0: strb     r5, [r0, #0xd0]
11805ba4: subs     r2, r2, #1
11805ba8: vstmia   r1!, {s0}
11805bac: bne      #0x11805ba4
11805bb0: vmov.f32 s0, s1
11805bb4: add      r1, r0, #0x114
11805bb8: mov      r2, #2
11805bbc: strb     r5, [r0, #0x110]
11805bc0: subs     r2, r2, #1
11805bc4: vstmia   r1!, {s0}
11805bc8: bne      #0x11805bc0
11805bcc: add      r3, r0, #0x100
11805bd0: strb     r5, [r0, #0x11c]
11805bd4: mov      r1, #0x64
11805bd8: strb     r5, [r0, #0x11d]
11805bdc: strh     r1, [r3, #0x1e]
11805be0: strh     r1, [r3, #0x20]
11805be4: strb     r6, [r0, #0x122]
11805be8: str      r5, [r0, #0x124]
11805bec: strb     r5, [r0, #0x128]
11805bf0: mov      r1, sb
11805bf4: strb     r5, [r4, #0x129]
11805bf8: bl       #0x11800528  ; ->strcpy
11805bfc: add      r1, pc, #0x9c
11805c00: add      r0, r4, #0x30
11805c04: bl       #0x11800528  ; ->strcpy
11805c08: ldr      r0, [pc, #0xa0]  ; =0x1000356
11805c0c: add      r1, r4, #0x100
11805c10: str      r0, [r4, #0xc0]
11805c14: strb     r8, [r4, #0xc8]
11805c18: strb     r5, [r4, #0xc9]
11805c1c: strb     r5, [r4, #0xca]
11805c20: strb     r5, [r4, #0xcb]
11805c24: mov      r0, #2
11805c28: strb     r6, [r4, #0xcc]
11805c2c: strb     r0, [r4, #0xce]
11805c30: strb     sl, [r4, #0x128]
11805c34: strb     fp, [r4, #0x129]
11805c38: strb     r5, [r4, #0x110]
11805c3c: strh     r5, [r1, #0x1e]
11805c40: strh     r5, [r1, #0x20]
11805c44: strb     r5, [r4, #0x122]
11805c48: bl       #0x11800530  ; ->ad::Encount::GetInst
11805c4c: ldrb     r1, [r4, #0xce]
11805c50: stm      sp, {r1, r8}
11805c54: ldrb     r3, [r4, #0xcb]
11805c58: ldrb     r2, [r4, #0xc8]
11805c5c: ldrb     r1, [r4, #0xc9]
11805c60: bl       #0x11800538  ; ->ad::Encount::startLoadRes
11805c64: ldr      r0, [pc, #0x48]  ; =0x3fbf9c gSndSys
11805c68: mov      r1, #0x10
11805c6c: bl       #0x118004c0  ; ->SndSys::stopAllBgm
11805c70: ldr      r0, [r7, #8]
11805c74: cmp      r0, #0
11805c78: bne      #0x11805c88
11805c7c: ldr      r0, [pc, #0x34]  ; =0x3f62a8 msys::MComSys::_sys
11805c80: ldr      r0, [r0]
11805c84: str      r0, [r7, #8]
11805c88: ldr      r1, [r0, #4]
11805c8c: add      sp, sp, #0xc
11805c90: mov      r0, #0xa
11805c94: pop      {r4, r5, r6, r7, r8, sb, sl, fp, lr}
11805c98: b        #0x11800540  ; ->GameMain::Change
11805c9c: andeq    r0, r0, r0
11805ca0: svcpl    #0x706d62
11805ca4: svcvs    #0x6e5f69
11805ca8: subslo   r6, pc, lr, ror #10
11805cac: andeq    r0, r0, r1, lsr r0
11805cb0: qaddeq   r0, r6, r0
11805cb4: mlaseq   pc, ip, pc, fp
11805cb8: eorseq   r6, pc, r8, lsr #5
11805cbc: push     {r4, lr}
11805cc0: mov      r4, r0
11805cc4: vpush    {d8, d9}
11805cc8: add      r0, r0, #0x6000
11805ccc: str      r1, [r0, #0xef8]!
11805cd0: add      r1, r4, #0x6c00
11805cd4: str      r2, [r0, #0x30]
11805cd8: add      r1, r1, #0x2f8
11805cdc: add      r0, r4, #0x14c
11805ce0: bl       #0x11800548  ; ->Message::play
11805ce4: add      r4, r4, #0xcc
11805ce8: vldr     s17, [pc, #0x2c]  ; =0x0 (0)
11805cec: vldr     s18, [pc, #0x2c]  ; =0xc1a00000 (-20)
11805cf0: vldr     s16, [pc, #0x2c]  ; =0xc3340000 (-180)
11805cf4: mov      r0, r4
11805cf8: bl       #0x11800200  ; ->MoveVBase::stop
11805cfc: vstr     s16, [r4, #0x24]
11805d00: add      r0, r4, #0x1c
11805d04: vstmia   r0, {s17, s18}
11805d08: vstr     s16, [r4, #0xc]
11805d0c: add      r4, r4, #4
11805d10: vstmia   r4, {s17, s18}
11805d14: vpop     {d8, d9}
11805d18: pop      {r4, pc}
11805d1c: andeq    r0, r0, r0
11805d20: movgt    r0, r0
11805d24: teqgt    r4, #0
11805d28: push     {r4, r5, r6, r7, r8, sb, sl, fp, ip, lr}
11805d2c: add      r5, r0, #0x61000
11805d30: mov      r1, #0
11805d34: mov      r4, #0
11805d38: ldrsb    r0, [r5, #0x13]
11805d3c: ldr      r7, [pc, #0xf8]  ; =0x3f95f0 gGameWork
11805d40: strb     r1, [r5, #0xf]
11805d44: cmp      r0, #0
11805d48: movne    r0, #0xa
11805d4c: moveq    r0, #0
11805d50: movne    r6, #0xa
11805d54: add      r0, r7, r0, lsl #1
11805d58: moveq    r6, #0
11805d5c: add      sl, r0, #0x7f0
11805d60: add      r0, sl, r4, lsl #1
11805d64: ldrsh    r0, [r0]
11805d68: cmp      r0, #0
11805d6c: blt      #0x11805e0c
11805d70: ldrsb    r1, [r5, #0x13]
11805d74: mov      r0, #1
11805d78: cmp      r1, #0
11805d7c: ldrbne   r2, [r5, #0xd]
11805d80: ldrbeq   r2, [r5, #0xc]
11805d84: and      r0, r2, r0, lsl r4
11805d88: cmp      r0, #0
11805d8c: beq      #0x11805e0c
11805d90: lsr      sb, r6, #5
11805d94: add      r0, r7, #0x810
11805d98: and      r2, r6, #0x1f
11805d9c: ldr      r3, [r0, sb, lsl #2]
11805da0: mov      r0, #1
11805da4: lsl      fp, r0, r2
11805da8: tst      r3, fp
11805dac: bne      #0x11805e0c
11805db0: cmp      r1, #0
11805db4: ldrne    r0, [pc, #0x84]  ; =0x1180c32c
11805db8: ldreq    r0, [pc, #0x84]  ; =0x1180c268
11805dbc: addne    r1, r4, r4, lsl #2
11805dc0: rsbeq    r1, r4, r4, lsl #3
11805dc4: add      r0, r0, r1, lsl #2
11805dc8: addne    r8, r0, #4
11805dcc: addeq    r8, r0, #0xc
11805dd0: ldr      r0, [pc, #0x64]  ; =0x3f95f0 gGameWork
11805dd4: ldrsh    r1, [r8, #4]
11805dd8: bl       #0x118004a0  ; ->GameWork::addCoin
11805ddc: ldrh     r1, [r8, #2]
11805de0: ldr      r0, [pc, #0x54]  ; =0x3f95f0 gGameWork
11805de4: mov      r2, #1
11805de8: bl       #0x11800550  ; ->GameWork::addItem
11805dec: add      r0, r7, #0x810
11805df0: mov      r1, #1
11805df4: ldr      r2, [r0, sb, lsl #2]
11805df8: orr      r2, r2, fp
11805dfc: str      r2, [r0, sb, lsl #2]
11805e00: ldrb     r0, [r5, #0xf]
11805e04: orr      r0, r0, r1, lsl r4
11805e08: strb     r0, [r5, #0xf]
11805e0c: ldrb     r0, [r5, #0x13]
11805e10: add      r4, r4, #1
11805e14: add      r6, r6, #1
11805e18: cmp      r0, #0
11805e1c: movne    r0, #4
11805e20: moveq    r0, #7
11805e24: cmp      r0, r4
11805e28: bgt      #0x11805d60
11805e2c: ldrb     r0, [r5, #0xf]
11805e30: cmp      r0, #0
11805e34: movne    r0, #1
11805e38: pop      {r4, r5, r6, r7, r8, sb, sl, fp, ip, pc}
11805e3c: ldrshteq sb, [pc], -r0
11805e40: orrne    ip, r0, ip, lsr #6
11805e44: orrne    ip, r0, r8, ror #4
11805e48: push     {r4, r5, r6, lr}
11805e4c: mov      r5, r0
11805e50: ldr      r0, [r0]
11805e54: ldr      r2, [r0, #8]
11805e58: cmp      r2, #0
11805e5c: bne      #0x11805e6c
11805e60: ldr      r2, [pc, #0x44]  ; =0x3f62a8 msys::MComSys::_sys
11805e64: ldr      r2, [r2]
11805e68: str      r2, [r0, #8]
11805e6c: add      r4, r2, #0xe9000
11805e70: add      r0, r2, #0xe9000
11805e74: ldr      r1, [r1, #8]
11805e78: add      r4, r4, #0x50
11805e7c: add      r0, r0, #0x58
11805e80: bl       #0x11800290  ; ->LMS_GetTextIndexByLabel
11805e84: mov      r1, r0
11805e88: add      r0, r4, #8
11805e8c: bl       #0x11800298  ; ->LMS_GetText
11805e90: mov      r1, r0
11805e94: add      r0, r5, #0x400
11805e98: pop      {r4, r5, r6, lr}
11805e9c: mov      r3, #0
11805ea0: mov      r2, r3
11805ea4: add      r0, r0, #0x9c
11805ea8: b        #0x118002a0  ; ->msys::MMsg::playStr
11805eac: eorseq   r6, pc, r8, lsr #5
11805eb0: push     {r4, r5, r6, lr}
11805eb4: mov      r5, r2
11805eb8: mov      r4, r0
11805ebc: add      r0, r1, r5, lsl #3
11805ec0: mov      r3, #0
11805ec4: ldr      r1, [r0, #4]
11805ec8: add      r0, r4, #0x12800
11805ecc: add      r0, r0, #0x3b4
11805ed0: sub      sp, sp, #0x20
11805ed4: mov      r2, r3
11805ed8: mov      r6, r0
11805edc: bl       #0x11800338  ; ->msys::MLyt::createAnimeAutoSlot
11805ee0: sxth     r1, r0
11805ee4: mov      r0, r6
11805ee8: bl       #0x11800328  ; ->msys::MLyt::getAnim
11805eec: ldr      r1, [pc, #0x8c]  ; =0x60ff4
11805ef0: vldr     s0, [pc, #0x8c]  ; =0x0 (0)
11805ef4: vldr     s1, [pc, #0x8c]  ; =0x3f800000 (1)
11805ef8: add      r2, sp, #4
11805efc: str      r0, [r1, r4]
11805f00: ldrh     r1, [r0, #0x12]
11805f04: add      r3, pc, #0x84
11805f08: orr      r1, r1, #2
11805f0c: strh     r1, [r0, #0x12]
11805f10: mov      r0, #0
11805f14: strb     r0, [sp]
11805f18: mov      r1, #1
11805f1c: vstmia   r2, {s0, s1}
11805f20: add      r2, pc, #0x6c
11805f24: vstr     s0, [sp, #0xc]
11805f28: strh     r1, [sp, #0x10]
11805f2c: strh     r0, [sp, #0x12]
11805f30: str      r0, [sp, #0x14]
11805f34: str      r0, [sp, #0x18]
11805f38: ldr      r0, [pc, #0x4c]  ; =0x130ac
11805f3c: ldr      r1, [r0, r4]
11805f40: mov      r0, sp
11805f44: bl       #0x118002b0  ; ->ad::lyt::LytAnim::init
11805f48: ldr      r0, [pc, #0x50]  ; =0x61013
11805f4c: ldrb     r0, [r0, r4]
11805f50: cmp      r0, #0
11805f54: movne    r0, #7
11805f58: add      r0, r0, r5
11805f5c: vmov     s0, r0
11805f60: mov      r0, sp
11805f64: vcvt.f32.s32 s0, s0
11805f68: bl       #0x118002c0  ; ->ad::lyt::LytAnim::stopAndSetFrm
11805f6c: mov      r1, #1
11805f70: mov      r0, sp
11805f74: bl       #0x118002c8  ; ->ad::lyt::LytAnim::term
11805f78: add      sp, sp, #0x20
11805f7c: pop      {r4, r5, r6, pc}
11805f80: strdeq   r0, r1, [r6], -r4
11805f84: andeq    r0, r0, r0
11805f88: svclo    #0x800000
11805f8c: andeq    r3, r1, ip, lsr #1
11805f90: andeq    r0, r0, r0
11805f94: svcpl    #0x544553
11805f98: subpl    r5, pc, r4, asr r2
11805f9c: andeq    r5, r0, r8, asr #18
11805fa0: andeq    r1, r6, r3, lsl r0
11805fa4: push     {r4, r5, r6, r7, r8, sb, sl, lr}
11805fa8: mov      r1, #0
11805fac: mov      r6, #1
11805fb0: add      sb, r0, #0x61000
11805fb4: ldr      r8, [pc, #0x170]  ; =0x3f9de0
11805fb8: ldr      sl, [pc, #0x170]  ; =0x118143e8
11805fbc: add      r4, r0, #0x12800
11805fc0: vpush    {d8, d9}
11805fc4: sub      sp, sp, #0x20
11805fc8: add      r2, sp, #8
11805fcc: vldr     s17, [pc, #0x150]  ; =0x0 (0)
11805fd0: strb     r1, [sp]
11805fd4: vldr     s16, [pc, #0x14c]  ; =0x3f800000 (1)
11805fd8: vstr     s17, [sp, #4]
11805fdc: vldr     s18, [pc, #0x150]  ; =0x40000000 (2)
11805fe0: add      r4, r4, #0x3b4
11805fe4: vstmia   r2, {s16, s17}
11805fe8: mov      r5, #0
11805fec: strh     r6, [sp, #0x10]
11805ff0: strh     r1, [sp, #0x12]
11805ff4: str      r1, [sp, #0x14]
11805ff8: str      r1, [sp, #0x18]
11805ffc: ldrb     r7, [sb, #0xc]
11806000: ldr      r2, [sl, r5, lsl #3]
11806004: ldr      r1, [r4, #0x150]
11806008: add      r3, pc, #0x128
1180600c: mov      r0, sp
11806010: bl       #0x118002b0  ; ->ad::lyt::LytAnim::init
11806014: tst      r7, r6, lsl r5
11806018: nop      
1180601c: beq      #0x11806060
11806020: add      r0, r8, r5, lsl #1
11806024: ldrsh    r0, [r0]
11806028: cmp      r0, #0
1180602c: blt      #0x11806048
11806030: vmov.f32 s0, s18
11806034: mov      r0, sp
11806038: bl       #0x118002c0  ; ->ad::lyt::LytAnim::stopAndSetFrm
1180603c: nop      
11806040: nop      
11806044: b        #0x1180606c
11806048: vmov.f32 s0, s16
1180604c: mov      r0, sp
11806050: bl       #0x118002c0  ; ->ad::lyt::LytAnim::stopAndSetFrm
11806054: nop      
11806058: nop      
1180605c: b        #0x1180606c
11806060: vmov.f32 s0, s17
11806064: mov      r0, sp
11806068: bl       #0x118002c0  ; ->ad::lyt::LytAnim::stopAndSetFrm
1180606c: mov      r1, #1
11806070: mov      r0, sp
11806074: bl       #0x118002c8  ; ->ad::lyt::LytAnim::term
11806078: add      r5, r5, #1
1180607c: cmp      r5, #7
11806080: blt      #0x11806000
11806084: ldrb     r7, [sb, #0xd]
11806088: ldr      r8, [pc, #0xac]  ; =0x3f9df4
1180608c: ldr      sb, [pc, #0xac]  ; =0x11814420
11806090: mov      r5, #0
11806094: ldr      r1, [r4, #0x150]
11806098: ldr      r2, [sb, r5, lsl #3]
1180609c: add      r3, pc, #0x94
118060a0: mov      r0, sp
118060a4: bl       #0x118002b0  ; ->ad::lyt::LytAnim::init
118060a8: tst      r7, r6, lsl r5
118060ac: nop      
118060b0: beq      #0x118060f4
118060b4: add      r0, r8, r5, lsl #1
118060b8: ldrsh    r0, [r0]
118060bc: cmp      r0, #0
118060c0: blt      #0x118060dc
118060c4: vmov.f32 s0, s18
118060c8: mov      r0, sp
118060cc: bl       #0x118002c0  ; ->ad::lyt::LytAnim::stopAndSetFrm
118060d0: nop      
118060d4: nop      
118060d8: b        #0x11806100
118060dc: vmov.f32 s0, s16
118060e0: mov      r0, sp
118060e4: bl       #0x118002c0  ; ->ad::lyt::LytAnim::stopAndSetFrm
118060e8: nop      
118060ec: nop      
118060f0: b        #0x11806100
118060f4: vmov.f32 s0, s17
118060f8: mov      r0, sp
118060fc: bl       #0x118002c0  ; ->ad::lyt::LytAnim::stopAndSetFrm
11806100: mov      r1, #1
11806104: mov      r0, sp
11806108: bl       #0x118002c8  ; ->ad::lyt::LytAnim::term
1180610c: add      r5, r5, #1
11806110: cmp      r5, #4
11806114: blt      #0x11806094
11806118: add      sp, sp, #0x20
1180611c: vpop     {d8, d9}
11806120: pop      {r4, r5, r6, r7, r8, sb, sl, pc}
11806124: andeq    r0, r0, r0
11806128: svclo    #0x800000
1180612c: eorseq   sb, pc, r0, ror #27
11806130: orrne    r4, r1, r8, ror #7
11806134: andmi    r0, r0, r0
11806138: andeq    r0, r0, r0
1180613c: ldrshteq sb, [pc], -r4
11806140: orrne    r4, r1, r0, lsr #8
11806144: push     {r4, r5, r6, lr}
11806148: add      r5, r0, #0x36800
1180614c: add      r5, r5, #0x3d8
11806150: mov      r4, r0
11806154: ldr      r0, [r5]
11806158: ldr      r1, [r0, #0x24]
1180615c: mov      r0, r5
11806160: blx      r1
11806164: cmp      r0, #0
11806168: bne      #0x118061d0
1180616c: ldr      r0, [r5, #0x154]
11806170: cmp      r0, #0
11806174: beq      #0x11806190
11806178: ldr      r1, [r0, #4]
1180617c: add      r2, r0, #4
11806180: cmp      r1, r2
11806184: ldrbeq   r0, [r0, #0x172]
11806188: cmpeq    r0, #0
1180618c: bne      #0x118061d0
11806190: nop      
11806194: bl       #0x11800410  ; ->col::GetBootInfo
11806198: ldrb     r0, [r0, #0x20d]
1180619c: cmp      r0, #0xc
118061a0: beq      #0x118061d4
118061a4: ldr      r0, [pc, #0x40]  ; =0x61013
118061a8: ldrb     r0, [r0, r4]
118061ac: cmp      r0, #0
118061b0: moveq    r1, #0x29
118061b4: movne    r1, #0x2e
118061b8: mov      r0, r5
118061bc: bl       #0x118002d8  ; ->msys::MDfxChr::playDfx
118061c0: ldr      r0, [pc, #0x28]  ; =0x36d2c
118061c4: ldr      r1, [r0, r4]
118061c8: mov      r0, #0
118061cc: strh     r0, [r1, #0xf2]
118061d0: pop      {r4, r5, r6, pc}
118061d4: mov      r1, #0x2b
118061d8: mov      r0, r5
118061dc: bl       #0x118002d8  ; ->msys::MDfxChr::playDfx
118061e0: nop      
118061e4: nop      
118061e8: b        #0x118061c0
118061ec: andeq    r1, r6, r3, lsl r0
118061f0: andeq    r6, r3, ip, lsr #26
118061f4: push     {r0, r1, r2, r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
118061f8: mov      r4, r0
118061fc: add      r8, r0, #0x14000
11806200: mov      r7, r1
11806204: vpush    {d8}
11806208: sub      sp, sp, #0x21c
1180620c: ldr      r0, [r1]
11806210: ldr      r1, [r8, #0x968]
11806214: cmp      r1, r0
11806218: beq      #0x1180642c
1180621c: mov      r0, #0xff
11806220: strb     r0, [r8, #0x96c]
11806224: ldr      r0, [sp, #0x22c]
11806228: add      r5, r4, #0x400
1180622c: add      r5, r5, #0x64
11806230: cmp      r0, #0
11806234: beq      #0x118063e0
11806238: ldrsh    r1, [r7, #6]
1180623c: add      r0, r4, #0x154
11806240: bl       #0x11800300  ; ->ad::lyt::LytNumReel3::setValueInstant
11806244: vldr     s16, [pc, #0x1f0]  ; =0x0 (0)
11806248: mov      r1, #1
1180624c: mov      r0, r5
11806250: vmov.f32 s0, s16
11806254: strb     r1, [r4, #0x145]
11806258: bl       #0x118002c0  ; ->ad::lyt::LytAnim::stopAndSetFrm
1180625c: mov      r0, #0
11806260: add      r1, sp, #0x100
11806264: strh     r0, [sp, #8]
11806268: str      r0, [sp, #0x208]
1180626c: strh     r0, [sp, #0x88]
11806270: str      r0, [sp, #0x20c]
11806274: strh     r0, [r1, #8]
11806278: str      r0, [sp, #0x210]
1180627c: strh     r0, [r1, #0x88]
11806280: str      r0, [sp, #0x214]
11806284: ldrsh    sl, [r7, #4]
11806288: add      fp, sp, #8
1180628c: mov      sb, r0
11806290: mov      r6, #0xa
11806294: mov      r5, #1
11806298: mov      r1, r6
1180629c: mov      r0, sl
118062a0: bl       #0x11800490  ; ->__aeabi_uidivmod
118062a4: cmp      r0, #0
118062a8: nop      
118062ac: beq      #0x118062c4
118062b0: add      r0, r6, r6, lsl #2
118062b4: add      r5, r5, #1
118062b8: cmp      r5, #0x40
118062bc: lsl      r6, r0, #1
118062c0: blo      #0x11806298
118062c4: add      r0, fp, sb, lsl #7
118062c8: ldr      r3, [pc, #0x170]  ; =0x3f7ce4 _ZZN13MessageSimple8InsParam6setNumEhibEs
118062cc: mov      r6, r0
118062d0: mov      r2, #0x3f
118062d4: mov      r1, #0x40
118062d8: str      sl, [sp]
118062dc: bl       #0x11801280
118062e0: ldr      r2, [pc, #0x15c]  ; =0xfee0
118062e4: cmp      r5, #0
118062e8: beq      #0x11806344
118062ec: ands     r0, r5, #1
118062f0: mov      r1, #0
118062f4: beq      #0x11806308
118062f8: ldrh     r3, [r6]
118062fc: mov      r1, #1
11806300: sub      r3, r3, #0x120
11806304: strh     r3, [r6]
11806308: cmp      r0, r5
1180630c: bhs      #0x11806344
11806310: add      r3, r6, r1, lsl #1
11806314: add      r1, r1, #1
11806318: ldrh     sl, [r3]
1180631c: add      ip, r6, r1, lsl #1
11806320: add      r0, r0, #2
11806324: add      sl, sl, r2
11806328: strh     sl, [r3]
1180632c: ldrh     r3, [ip]
11806330: cmp      r0, r5
11806334: add      r1, r1, #1
11806338: add      r3, r3, r2
1180633c: strh     r3, [ip]
11806340: blo      #0x11806310
11806344: add      r0, fp, sb, lsl #2
11806348: str      r5, [r0, #0x200]
1180634c: ldr      r0, [r4]
11806350: ldr      r1, [r0, #8]
11806354: cmp      r1, #0
11806358: bne      #0x11806368
1180635c: ldr      r1, [pc, #0xe4]  ; =0x3f62a8 msys::MComSys::_sys
11806360: ldr      r1, [r1]
11806364: str      r1, [r0, #8]
11806368: add      r5, r1, #0xe9000
1180636c: add      r5, r5, #0x50
11806370: add      r1, pc, #0xd4
11806374: add      r0, r5, #8
11806378: bl       #0x11800290  ; ->LMS_GetTextIndexByLabel
1180637c: mov      r1, r0
11806380: add      r0, r5, #8
11806384: bl       #0x11800298  ; ->LMS_GetText
11806388: mov      r1, r0
1180638c: add      r0, r4, #0x7000
11806390: mov      r3, #0
11806394: add      r2, sp, #8
11806398: add      r0, r0, #0xe0
1180639c: bl       #0x118002a0  ; ->msys::MMsg::playStr
118063a0: ldrsh    r1, [r7, #0xc]
118063a4: add      r0, r4, #0x384
118063a8: bl       #0x11800300  ; ->ad::lyt::LytNumReel3::setValueInstant
118063ac: ldr      r0, [sp, #0x230]
118063b0: cmp      r0, #0
118063b4: vmoveq.f32 s0, s16
118063b8: addeq    r0, r4, #0x480
118063bc: beq      #0x118063d8
118063c0: ldr      r0, [r4, #0x494]
118063c4: add      r4, r4, #0x480
118063c8: bl       #0x118002b8  ; ->ad::lyt::AnimTransform::GetFrameSize
118063cc: vmov     s0, r0
118063d0: mov      r0, r4
118063d4: vcvt.f32.u32 s0, s0
118063d8: bl       #0x118002c0  ; ->ad::lyt::LytAnim::stopAndSetFrm
118063dc: b        #0x1180641c
118063e0: mov      r1, #0
118063e4: strb     r1, [r4, #0x145]
118063e8: ldr      r0, [r5, #0x14]
118063ec: bl       #0x118002b8  ; ->ad::lyt::AnimTransform::GetFrameSize
118063f0: vmov     s0, r0
118063f4: mov      r0, r5
118063f8: vcvt.f32.u32 s0, s0
118063fc: bl       #0x118002c0  ; ->ad::lyt::LytAnim::stopAndSetFrm
11806400: ldr      r0, [r4, #0x494]
11806404: add      r4, r4, #0x480
11806408: bl       #0x118002b8  ; ->ad::lyt::AnimTransform::GetFrameSize
1180640c: vmov     s0, r0
11806410: mov      r0, r4
11806414: vcvt.f32.u32 s0, s0
11806418: bl       #0x118002c0  ; ->ad::lyt::LytAnim::stopAndSetFrm
1180641c: ldr      r0, [r7]
11806420: str      r0, [r8, #0x968]
11806424: ldr      r0, [sp, #0x22c]
11806428: strb     r0, [r8, #0x96d]
1180642c: add      sp, sp, #0x21c
11806430: vpop     {d8}
11806434: add      sp, sp, #0x10
11806438: pop      {r4, r5, r6, r7, r8, sb, sl, fp, pc}
1180643c: andeq    r0, r0, r0
11806440: eorseq   r7, pc, r4, ror #25
11806444: andeq    pc, r0, r0, ror #29
11806448: eorseq   r6, pc, r8, lsr #5
1180644c: svcpl    #0x53454d
11806450: .word    0x73654d45
11806454: svcvs    #0x6c6f43
11806458: strbvc   r7, [r5, #-0x373]!
1180645c: ldmdbvs  r4!, {r0, r2, r3, r5, r6, r8, sb, sl, fp, ip, lr} ^
11806460: svcpl    #0x656c74
11806464: .word    0x61656c63
11806468: ldrbvc   r5, [r4, #-0xf72]!
1180646c: subslo   r6, pc, #0x720
11806470: andeq    r0, r0, r0
11806474: push     {r4, r5, r6, r7, r8, sb, sl, lr}
11806478: add      r5, r0, #0x4c000
1180647c: mov      r4, r0
11806480: add      r0, r0, #0x3dc00
11806484: ldr      r6, [pc, #0xe8]  ; =0x1180c32c
11806488: mov      sb, r2
1180648c: mov      r7, r1
11806490: add      r5, r5, #0x194
11806494: add      r0, r0, #0x384
11806498: bl       #0x11800310  ; ->msys::MListWndPBase::getCurNo
1180649c: add      r0, r0, r0, lsl #2
118064a0: add      r8, r5, #0x14000
118064a4: ldrb     r0, [r6, r0, lsl #2]!
118064a8: ldrb     r1, [r8, #0x96c]
118064ac: cmp      r1, r0
118064b0: beq      #0x11806570
118064b4: add      r1, r4, #0x4c000
118064b8: add      r1, r1, #0x194
118064bc: mov      r0, #0
118064c0: add      r4, r1, #0x400
118064c4: cmp      r7, #0
118064c8: add      r4, r4, #0x64
118064cc: str      r0, [r8, #0x968]
118064d0: beq      #0x11806528
118064d4: ldr      r0, [r4, #0x14]
118064d8: bl       #0x118002b8  ; ->ad::lyt::AnimTransform::GetFrameSize
118064dc: vmov     s0, r0
118064e0: mov      r0, r4
118064e4: vcvt.f32.u32 s0, s0
118064e8: bl       #0x118002c0  ; ->ad::lyt::LytAnim::stopAndSetFrm
118064ec: ldrsh    r1, [r6, #4]
118064f0: add      r0, r5, #0x384
118064f4: bl       #0x11800300  ; ->ad::lyt::LytNumReel3::setValueInstant
118064f8: cmp      sb, #0
118064fc: vldreq   s0, [pc, #0x74]  ; =0x0 (0)
11806500: addeq    r0, r5, #0x480
11806504: beq      #0x11806560
11806508: ldr      r0, [r5, #0x494]
1180650c: add      r4, r5, #0x480
11806510: bl       #0x118002b8  ; ->ad::lyt::AnimTransform::GetFrameSize
11806514: vmov     s0, r0
11806518: mov      r0, r4
1180651c: vcvt.f32.u32 s0, s0
11806520: bl       #0x118002c0  ; ->ad::lyt::LytAnim::stopAndSetFrm
11806524: b        #0x11806564
11806528: mov      r1, #0
1180652c: strb     r1, [r5, #0x145]
11806530: ldr      r0, [r4, #0x14]
11806534: bl       #0x118002b8  ; ->ad::lyt::AnimTransform::GetFrameSize
11806538: vmov     s0, r0
1180653c: mov      r0, r4
11806540: vcvt.f32.u32 s0, s0
11806544: bl       #0x118002c0  ; ->ad::lyt::LytAnim::stopAndSetFrm
11806548: ldr      r0, [r5, #0x494]
1180654c: add      r4, r5, #0x480
11806550: bl       #0x118002b8  ; ->ad::lyt::AnimTransform::GetFrameSize
11806554: vmov     s0, r0
11806558: mov      r0, r4
1180655c: vcvt.f32.u32 s0, s0
11806560: bl       #0x118002c0  ; ->ad::lyt::LytAnim::stopAndSetFrm
11806564: ldrb     r0, [r6]
11806568: strb     r0, [r8, #0x96c]
1180656c: strb     r7, [r8, #0x96d]
11806570: pop      {r4, r5, r6, r7, r8, sb, sl, pc}
11806574: orrne    ip, r0, ip, lsr #6
11806578: andeq    r0, r0, r0
1180657c: ldr      r1, [r0, #4]
11806580: cmp      r1, #0
11806584: bxeq     lr
11806588: push     {r4, r5, r6, r7, r8, sb, sl, fp, lr}
1180658c: mov      r5, r0
11806590: vpush    {d8, d9}
11806594: sub      sp, sp, #0x34
11806598: ldrsb    r0, [r0, #0x18]
1180659c: cmp      r0, #0
118065a0: blt      #0x118067e8
118065a4: ldrsb    r2, [r5, #0x19]
118065a8: mov      sl, #1
118065ac: cmp      r0, r2
118065b0: beq      #0x11806774
118065b4: strb     r0, [r5, #0x19]
118065b8: ldr      r7, [r1, #0x150]
118065bc: add      r1, r5, #0x30
118065c0: ldr      r4, [r5, #0x10]
118065c4: ldr      sb, [r1, r0, lsl #2]
118065c8: add      r0, r5, #0x10
118065cc: cmp      r4, r0
118065d0: add      r6, r5, #0xc
118065d4: add      fp, sb, #0x80
118065d8: mov      r8, #0
118065dc: beq      #0x11806608
118065e0: ldr      r0, [r4, #8]
118065e4: mov      r1, fp
118065e8: bl       #0x11800558  ; ->strcmp
118065ec: cmp      r0, #0
118065f0: nop      
118065f4: beq      #0x118067f4
118065f8: ldr      r4, [r4]
118065fc: add      r0, r6, #4
11806600: cmp      r4, r0
11806604: bne      #0x118065e0
11806608: ldr      r1, [pc, #0x1ec]  ; =0x3f7fab _ZZN4msys7MCursorILj3EE6updateEvEs
1180660c: mov      r0, r8
11806610: bl       #0x11800560  ; ->msys::MCtrlUserData::findExtUserDataByName
11806614: mov      r6, r0
11806618: ldr      r0, [sb, #0xac]
1180661c: ldr      r1, [r8, #0xc]
11806620: vldr     s16, [sb, #0x54]
11806624: vldr     s17, [sb, #0x64]
11806628: ldr      r0, [r0, #0x10]
1180662c: vldr     s19, [sb, #0x74]
11806630: ldr      r2, [r0]
11806634: ldr      r3, [r2, #0x2c]
11806638: mov      r2, #1
1180663c: blx      r3
11806640: cmp      r0, #0
11806644: addne    r0, r0, #0x3c
11806648: ldr      r2, [pc, #0x1b4]  ; =0x3e4ca4 __ARM__ZN4msys7MCursorILj3EE6updateEv_anon0
1180664c: ldmne    r0, {r0, r1}
11806650: add      sb, sp, #0x18
11806654: vldreq   s0, [pc, #0x1a4]  ; =0x0 (0)
11806658: mov      r4, #0
1180665c: strdne   r0, r1, [r5, #0x1c]
11806660: vstreq   s0, [r5, #0x20]
11806664: vstreq   s0, [r5, #0x1c]
11806668: ldr      r0, [r2], #4
1180666c: ldr      r3, [r6, #4]
11806670: ldm      r2, {r1, r2}
11806674: add      r8, sp, #0x24
11806678: add      r6, r6, r3
1180667c: stm      sb, {r0, r1, r2}
11806680: ldr      r0, [r7, #0x10]
11806684: ldr      r1, [sb, r4, lsl #2]
11806688: ldr      r2, [r0]
1180668c: ldr      r3, [r2, #0x2c]
11806690: mov      r2, #1
11806694: blx      r3
11806698: mov      r1, r0
1180669c: str      r1, [r8, r4, lsl #2]
118066a0: ldrb     r1, [r0, #0x44]!
118066a4: add      r4, r4, #1
118066a8: cmp      r4, #3
118066ac: and      r1, r1, #0xfe
118066b0: strb     r1, [r0]
118066b4: blt      #0x11806680
118066b8: ldr      r4, [pc, #0x148]  ; =0x3e4cb0 __ARM__ZN4msys7MCursorILj3EE6updateEv_anon1
118066bc: ldm      r4, {r0, r1, r2, r3, r4, ip}
118066c0: stm      sp, {r0, r1, r2, r3, r4, ip}
118066c4: ldr      r0, [r6]
118066c8: ldr      r0, [r8, r0, lsl #2]
118066cc: str      r0, [r5, #8]
118066d0: ldrb     r1, [r0, #0x44]
118066d4: and      r1, r1, #0xfe
118066d8: orr      r1, r1, #1
118066dc: strb     r1, [r0, #0x44]
118066e0: ldr      r1, [r6]
118066e4: mov      r0, sp
118066e8: vldr     s0, [r6, #0xc]
118066ec: vldr     s1, [r5, #0x1c]
118066f0: add      r1, r0, r1, lsl #3
118066f4: vcvt.f32.s32 s0, s0
118066f8: vldr     s2, [r1]
118066fc: vadd.f32 s1, s1, s2
11806700: vadd.f32 s0, s1, s0
11806704: vstr     s0, [r5, #0x1c]
11806708: ldr      r1, [r6]
1180670c: vldr     s0, [r6, #0x10]
11806710: vldr     s1, [r5, #0x20]
11806714: add      r0, r0, r1, lsl #3
11806718: vcvt.f32.s32 s0, s0
1180671c: vldr     s2, [r0, #4]
11806720: vadd.f32 s1, s1, s2
11806724: vadd.f32 s0, s1, s0
11806728: vldr     s1, [pc, #0xdc]  ; =0x3f800000 (1)
1180672c: vstr     s0, [r5, #0x20]
11806730: vldr     s2, [r6, #4]
11806734: vldr     s0, [r6, #8]
11806738: ldr      r0, [r5, #4]
1180673c: vcvt.f32.s32 s2, s2
11806740: vcvt.f32.s32 s0, s0
11806744: add      r4, r0, #0xcc
11806748: mov      r0, r4
1180674c: vadd.f32 s18, s16, s2
11806750: vadd.f32 s17, s17, s0
11806754: vadd.f32 s16, s19, s1
11806758: bl       #0x11800200  ; ->MoveVBase::stop
1180675c: vstr     s18, [r4, #0x1c]
11806760: vstr     s17, [r4, #0x20]
11806764: vstr     s16, [r4, #0x24]
11806768: vstr     s18, [r4, #4]
1180676c: vstr     s17, [r4, #8]
11806770: vstr     s16, [r4, #0xc]
11806774: ldrsh    r0, [r5, #0x1a]
11806778: vldr     s3, [r5, #0x2c]
1180677c: vldr     s1, [r5, #0x1c]
11806780: vmov     s2, r0
11806784: vldr     s0, [r5, #0x20]
11806788: vcvt.f32.s32 s2, s2
1180678c: vsub.f32 s2, s2, s3
11806790: vcvt.s32.f32 s2, s2
11806794: vmov     r0, s2
11806798: sxth     r0, r0
1180679c: cmp      r0, #0
118067a0: strh     r0, [r5, #0x1a]
118067a4: movlt    r0, #0x1e
118067a8: strhlt   r0, [r5, #0x1a]
118067ac: blt      #0x118067c4
118067b0: cmp      r0, #0xf
118067b4: bge      #0x118067c4
118067b8: vldr     s2, [pc, #0x50]  ; =0x40000000 (2)
118067bc: vadd.f32 s1, s1, s2
118067c0: vadd.f32 s0, s0, s2
118067c4: ldr      r0, [r5, #8]
118067c8: vstr     s1, [r0, #0x3c]
118067cc: vstr     s0, [r0, #0x40]
118067d0: ldrb     r1, [r0, #0x44]
118067d4: and      r1, r1, #0xef
118067d8: orr      r1, r1, #0x10
118067dc: strb     r1, [r0, #0x44]
118067e0: ldr      r0, [r5, #4]
118067e4: strb     sl, [r0, #0x374]
118067e8: add      sp, sp, #0x34
118067ec: vpop     {d8, d9}
118067f0: pop      {r4, r5, r6, r7, r8, sb, sl, fp, pc}
118067f4: mov      r8, r4
118067f8: b        #0x11806608
118067fc: eorseq   r7, pc, fp, lsr #31
11806800: andeq    r0, r0, r0
11806804: eorseq   r4, lr, r4, lsr #25
11806808: ldrhteq  r4, [lr], -r0
1180680c: svclo    #0x800000
11806810: andmi    r0, r0, r0
11806814: ldr      r0, [pc, #0x94]  ; =0x3f62a8 msys::MComSys::_sys
11806818: push     {r3, r4, r5, r6, r7, lr}
1180681c: ldr      r0, [r0]
11806820: vldr     s0, [sp, #0x18]
11806824: add      r0, r0, #0x49000
11806828: add      r0, r0, #0x368
1180682c: ldr      ip, [r0, #0xc]
11806830: sub      r4, ip, #0x54
11806834: sub      ip, r0, #0x4c
11806838: cmp      ip, r4
1180683c: moveq    r4, #0
11806840: beq      #0x118068a8
11806844: ldr      r5, [r4, #0x58]
11806848: add      ip, r4, #0x54
1180684c: cmp      r5, ip
11806850: beq      #0x1180686c
11806854: ldr      r6, [ip]
11806858: str      r5, [r6, #4]
1180685c: ldr      r6, [ip]
11806860: str      r6, [r5]
11806864: str      ip, [ip]
11806868: str      ip, [ip, #4]
1180686c: add      ip, r4, #0x54
11806870: ldm      ip, {r5, r6}
11806874: str      r6, [r5, #4]
11806878: ldr      ip, [r4, #0x54]
1180687c: str      ip, [r6]
11806880: adds     ip, r4, #0x54
11806884: beq      #0x1180689c
11806888: str      r0, [ip]
1180688c: ldr      r5, [r0, #4]
11806890: str      r5, [ip, #4]
11806894: str      ip, [r5]
11806898: str      ip, [r0, #4]
1180689c: vstr     s0, [sp]
118068a0: mov      r0, r4
118068a4: bl       #0x118004b0  ; ->msys::MSndSe::play
118068a8: mov      r0, r4
118068ac: pop      {r3, r4, r5, r6, r7, pc}
118068b0: eorseq   r6, pc, r8, lsr #5
118068b4: push     {r4, r5, r6, lr}
118068b8: mov      r5, r1
118068bc: ldr      r1, [r0, #8]
118068c0: mov      r4, r0
118068c4: ldr      r0, [pc, #0x90]  ; =0x3f62a8 msys::MComSys::_sys
118068c8: cmp      r1, #0
118068cc: ldr      r0, [r0]
118068d0: streq    r0, [r4, #8]
118068d4: ldr      r1, [r4, #8]
118068d8: add      r1, r1, #0xe6000
118068dc: strb     r5, [r1, #0x508]
118068e0: ldr      r1, [r4, #8]
118068e4: cmp      r1, #0
118068e8: streq    r0, [r4, #8]
118068ec: movne    r0, r1
118068f0: add      r1, r0, #0xe6000
118068f4: mov      r0, #1
118068f8: strb     r0, [r1, #0x50a]
118068fc: add      r0, r4, #0x3dc00
11806900: cmp      r5, #0
11806904: add      r0, r0, #0x384
11806908: beq      #0x11806944
1180690c: ldr      r1, [pc, #0x4c]  ; =0x3e0c5
11806910: ldrb     r1, [r1, r4]
11806914: cmp      r1, #0
11806918: movne    r1, r5
1180691c: blne     #0x11800218  ; ->msys::MListWndPBase::setEnableInput
11806920: ldr      r0, [pc, #0x3c]  ; =0x45251
11806924: ldrb     r0, [r0, r4]
11806928: cmp      r0, #0
1180692c: beq      #0x11806958
11806930: mov      r1, r5
11806934: add      r0, r4, #0x45000
11806938: pop      {r4, r5, r6, lr}
1180693c: add      r0, r0, #0x110
11806940: b        #0x11800218  ; ->msys::MListWndPBase::setEnableInput
11806944: mov      r1, r5
11806948: bl       #0x11800218  ; ->msys::MListWndPBase::setEnableInput
1180694c: nop      
11806950: nop      
11806954: b        #0x11806930
11806958: pop      {r4, r5, r6, pc}
1180695c: eorseq   r6, pc, r8, lsr #5
11806960: andeq    lr, r3, r5, asr #1
11806964: andeq    r5, r4, r1, asr r2
11806968: push     {r4, r5, r6, r7, r8, lr}
1180696c: mov      r5, r0
11806970: add      r4, r5, #0x14
11806974: ldr      r0, [pc, #0x120]  ; =0x3f7ee8 _ZGVZN2nn4math4VEC33OneEvE3one
11806978: vpush    {d8}
1180697c: ldrb     r0, [r0]
11806980: tst      r0, #1
11806984: bne      #0x118069b4
11806988: ldr      r0, [pc, #0x10c]  ; =0x3f7ee8 _ZGVZN2nn4math4VEC33OneEvE3one
1180698c: bl       #0x11800568  ; ->__cxa_guard_acquire
11806990: cmp      r0, #0
11806994: beq      #0x118069b4
11806998: ldr      r0, [pc, #0x104]  ; =0x434c3c _ZZN2nn4math4VEC33OneEvE3one
1180699c: vldr     s0, [pc, #0xfc]  ; =0x3f800000 (1)
118069a0: vstr     s0, [r0]
118069a4: vstr     s0, [r0, #4]
118069a8: vstr     s0, [r0, #8]
118069ac: ldr      r0, [pc, #0xe8]  ; =0x3f7ee8 _ZGVZN2nn4math4VEC33OneEvE3one
118069b0: bl       #0x11800570  ; ->__cxa_guard_release
118069b4: ldr      r6, [pc, #0xe8]  ; =0x434c3c _ZZN2nn4math4VEC33OneEvE3one
118069b8: mov      r0, r4
118069bc: bl       #0x11800200  ; ->MoveVBase::stop
118069c0: ldm      r6, {r0, r1, r2}
118069c4: add      r3, r4, #0x1c
118069c8: ldr      r6, [pc, #0xd8]  ; =0x3f7eec _ZGVZN2nn4math4VEC34ZeroEvE4zero
118069cc: add      r4, r4, #4
118069d0: stm      r3, {r0, r1, r2}
118069d4: stm      r4, {r0, r1, r2}
118069d8: add      r4, r5, #0x70
118069dc: ldrb     r0, [r6]
118069e0: vldr     s16, [pc, #0xc4]  ; =0x0 (0)
118069e4: tst      r0, #1
118069e8: bne      #0x11806a18
118069ec: add      r0, r6, #0
118069f0: bl       #0x11800568  ; ->__cxa_guard_acquire
118069f4: cmp      r0, #0
118069f8: nop      
118069fc: beq      #0x11806a18
11806a00: ldr      r0, [pc, #0xa8]  ; =0x434c48 _ZZN2nn4math4VEC34ZeroEvE4zero
11806a04: vstr     s16, [r0]
11806a08: vstr     s16, [r0, #4]
11806a0c: vstr     s16, [r0, #8]
11806a10: add      r0, r6, #0
11806a14: bl       #0x11800570  ; ->__cxa_guard_release
11806a18: ldr      r7, [pc, #0x90]  ; =0x434c48 _ZZN2nn4math4VEC34ZeroEvE4zero
11806a1c: mov      r0, r4
11806a20: bl       #0x11800200  ; ->MoveVBase::stop
11806a24: ldm      r7, {r0, r1, r2}
11806a28: add      r3, r4, #0x1c
11806a2c: add      r4, r4, #4
11806a30: stm      r3, {r0, r1, r2}
11806a34: stm      r4, {r0, r1, r2}
11806a38: add      r4, r5, #0xcc
11806a3c: ldrb     r0, [r6]
11806a40: tst      r0, #1
11806a44: bne      #0x11806a74
11806a48: ldr      r0, [pc, #0x58]  ; =0x3f7eec _ZGVZN2nn4math4VEC34ZeroEvE4zero
11806a4c: bl       #0x11800568  ; ->__cxa_guard_acquire
11806a50: cmp      r0, #0
11806a54: nop      
11806a58: beq      #0x11806a74
11806a5c: add      r0, r7, #0
11806a60: vstr     s16, [r0]
11806a64: vstr     s16, [r0, #4]
11806a68: vstr     s16, [r0, #8]
11806a6c: ldr      r0, [pc, #0x34]  ; =0x3f7eec _ZGVZN2nn4math4VEC34ZeroEvE4zero
11806a70: bl       #0x11800570  ; ->__cxa_guard_release
11806a74: ldr      r5, [pc, #0x34]  ; =0x434c48 _ZZN2nn4math4VEC34ZeroEvE4zero
11806a78: mov      r0, r4
11806a7c: bl       #0x11800200  ; ->MoveVBase::stop
11806a80: ldm      r5, {r0, r1, r2}
11806a84: add      r3, r4, #0x1c
11806a88: add      r4, r4, #4
11806a8c: stm      r3, {r0, r1, r2}
11806a90: stm      r4, {r0, r1, r2}
11806a94: vpop     {d8}
11806a98: pop      {r4, r5, r6, r7, r8, pc}
11806a9c: eorseq   r7, pc, r8, ror #29
11806aa0: svclo    #0x800000
11806aa4: subeq    r4, r3, ip, lsr ip
11806aa8: eorseq   r7, pc, ip, ror #29
11806aac: andeq    r0, r0, r0
11806ab0: subeq    r4, r3, r8, asr #24
11806ab4: push     {r0, r1, r4, r5, r6, r7, r8, sb, sl, fp, lr}
11806ab8: sub      sp, sp, #4
11806abc: mov      r5, #0
11806ac0: subs     r7, r1, #0
11806ac4: movne    r8, #4
11806ac8: moveq    r8, #7
11806acc: ldr      r0, [sp, #4]
11806ad0: add      sb, r0, #0x7000
11806ad4: ldr      r2, [r0, #0x154]
11806ad8: add      r4, r0, #0x4000
11806adc: ldr      r0, [pc, #0x184]  ; =0x3f95f0 gGameWork
11806ae0: add      r4, r4, #0x2f80
11806ae4: strb     r8, [r2, #0x144]
11806ae8: addne    r6, r0, #0x800
11806aec: addne    r6, r6, #4
11806af0: addeq    r6, r0, #0x7f0
11806af4: ldr      r0, [sb, #0x60]
11806af8: add      r0, r0, #0x61000
11806afc: ldrbne   r0, [r0, #0xd]
11806b00: ldrbeq   r0, [r0, #0xc]
11806b04: cmp      r8, #0
11806b08: str      r0, [sp]
11806b0c: ble      #0x11806c58
11806b10: cmp      r7, #0
11806b14: ldreq    r0, [pc, #0x150]  ; =0x1180c268
11806b18: ldrne    r0, [pc, #0x150]  ; =0x1180c32c
11806b1c: rsbeq    r1, r5, r5, lsl #3
11806b20: addne    r1, r5, r5, lsl #2
11806b24: mov      fp, #1
11806b28: add      r0, r0, r1, lsl #2
11806b2c: addeq    sl, r0, #0xc
11806b30: addne    sl, r0, #4
11806b34: ldr      r0, [sp]
11806b38: tst      r0, fp, lsl r5
11806b3c: beq      #0x11806be4
11806b40: adds     r0, r7, #0
11806b44: movne    r0, #7
11806b48: add      r0, r0, r5
11806b4c: strb     r0, [r4, #8]
11806b50: ldr      r0, [sb, #0x60]
11806b54: ldr      r1, [r0, #8]
11806b58: cmp      r1, #0
11806b5c: bne      #0x11806b6c
11806b60: ldr      r1, [pc, #0x10c]  ; =0x3f62a8 msys::MComSys::_sys
11806b64: ldr      r1, [r1]
11806b68: str      r1, [r0, #8]
11806b6c: mov      r0, r1
11806b70: add      fp, r0, #0xe9000
11806b74: add      r0, r0, #0xe9000
11806b78: ldr      r1, [sl, #8]
11806b7c: add      fp, fp, #0x50
11806b80: add      r0, r0, #0x58
11806b84: bl       #0x11800290  ; ->LMS_GetTextIndexByLabel
11806b88: mov      r1, r0
11806b8c: add      r0, fp, #8
11806b90: bl       #0x11800298  ; ->LMS_GetText
11806b94: cmp      r7, #0
11806b98: str      r0, [r4, #0x10]
11806b9c: bne      #0x11806bac
11806ba0: ldrsh    r0, [r6]
11806ba4: cmp      r0, #0
11806ba8: bge      #0x11806bb0
11806bac: ldr      r0, [pc, #0xc4]  ; =0xffff
11806bb0: strh     r0, [r4, #4]
11806bb4: ldrsh    r0, [r6]
11806bb8: cmp      r0, #0
11806bbc: bge      #0x11806bd8
11806bc0: ldr      r0, [pc, #0xa0]  ; =0x3f95f0 gGameWork
11806bc4: bl       #0x118003d0  ; ->GameWork::getCoin
11806bc8: ldrsh    r1, [sl]
11806bcc: cmp      r0, r1
11806bd0: movlo    r0, #0
11806bd4: blo      #0x11806bdc
11806bd8: mov      r0, #1
11806bdc: strb     r0, [r4, #0xe]
11806be0: b        #0x11806c38
11806be4: mov      r0, #0xff
11806be8: strb     r0, [r4, #8]
11806bec: ldr      r0, [sb, #0x60]
11806bf0: ldr      r1, [r0, #8]
11806bf4: cmp      r1, #0
11806bf8: bne      #0x11806c08
11806bfc: ldr      r1, [pc, #0x70]  ; =0x3f62a8 msys::MComSys::_sys
11806c00: ldr      r1, [r1]
11806c04: str      r1, [r0, #8]
11806c08: add      sl, r1, #0xe9000
11806c0c: add      sl, sl, #0x50
11806c10: add      r1, pc, #0x64
11806c14: add      r0, sl, #8
11806c18: bl       #0x11800290  ; ->LMS_GetTextIndexByLabel
11806c1c: mov      r1, r0
11806c20: add      r0, sl, #8
11806c24: bl       #0x11800298  ; ->LMS_GetText
11806c28: mvn      r1, #0
11806c2c: str      r0, [r4, #0x10]
11806c30: strh     r1, [r4, #4]
11806c34: strb     fp, [r4, #0xe]
11806c38: str      r5, [r4], #0xf
11806c3c: mov      r0, #0
11806c40: strb     r0, [r4], #5
11806c44: add      r5, r5, #1
11806c48: cmp      r5, r8
11806c4c: add      r6, r6, #2
11806c50: str      r0, [r4], #8
11806c54: blt      #0x11806b10
11806c58: ldr      r0, [sp, #4]
11806c5c: add      sp, sp, #0xc
11806c60: pop      {r4, r5, r6, r7, r8, sb, sl, fp, lr}
11806c64: b        #0x11800390  ; ->msys::MListWndPBase::resetCur
11806c68: ldrshteq sb, [pc], -r0
11806c6c: orrne    ip, r0, r8, ror #4
11806c70: orrne    ip, r0, ip, lsr #6
11806c74: eorseq   r6, pc, r8, lsr #5
11806c78: .word    0x0000ffff
11806c7c: svcpl    #0x53454d
11806c80: .word    0x73654d45
11806c84: svcvs    #0x6c6f43
11806c88: strbvc   r7, [r5, #-0x373]!
11806c8c: stclvs   p15, c5, [r3], #-0x1b4
11806c90: svcpl    #0x737361
11806c94: andeq    r0, r0, r0, lsr r0
11806c98: ldr      r1, [r0, #8]
11806c9c: cmp      r1, #0
11806ca0: bne      #0x11806cb0
11806ca4: ldr      r1, [pc, #0x38]  ; =0x3f62a8 msys::MComSys::_sys
11806ca8: ldr      r1, [r1]
11806cac: str      r1, [r0, #8]
11806cb0: ldr      r2, [pc, #0x30]  ; =0x4ad14
11806cb4: add      r1, r1, r2
11806cb8: add      r1, r1, #0x2c
11806cbc: vldmia   r1, {s0, s1}
11806cc0: vcmpe.f32 s0, s1
11806cc4: vmrs     apsr_nzcv, fpscr
11806cc8: blo      #0x11806ce0
11806ccc: add      r2, r0, #0x10000
11806cd0: ldr      r0, [pc, #0x14]  ; =0x1180c0a0
11806cd4: add      r2, r2, #0x2a00
11806cd8: ldm      r0, {r0, r1}
11806cdc: strd     r0, r1, [r2, #4]
11806ce0: bx       lr
11806ce4: eorseq   r6, pc, r8, lsr #5
11806ce8: andeq    sl, r4, r4, lsl sp
11806cec: orrne    ip, r0, r0, lsr #1
11806cf0: ldr      r1, [pc, #0xb4]  ; =0x3f95f0 gGameWork
11806cf4: str      r4, [sp, #-4]!
11806cf8: mov      ip, #1
11806cfc: ldr      r1, [r1, #0x3c4]
11806d00: lsl      r2, r1, #0x1c
11806d04: lsl      r1, r1, #0x17
11806d08: lsr      r2, r2, #0x1f
11806d0c: lsr      r1, r1, #0x1f
11806d10: orr      r2, r2, r1, lsl #1
11806d14: ldr      r1, [pc, #0x90]  ; =0x3f95f0 gGameWork
11806d18: ldr      r1, [r1, #0x3cc]
11806d1c: lsl      r1, r1, #1
11806d20: lsr      r1, r1, #0x1f
11806d24: orr      r2, r2, r1, lsl #2
11806d28: ldr      r1, [pc, #0x7c]  ; =0x3f95f0 gGameWork
11806d2c: ldr      r1, [r1, #0x3d0]
11806d30: lsl      r1, r1, #0xa
11806d34: lsr      r1, r1, #0x1f
11806d38: orr      r2, r2, r1, lsl #3
11806d3c: ldr      r1, [pc, #0x68]  ; =0x3f95f0 gGameWork
11806d40: ldr      r1, [r1, #0x40c]
11806d44: lsl      r1, r1, #0xd
11806d48: lsr      r1, r1, #0x1f
11806d4c: orr      r3, r2, r1, lsl #4
11806d50: ldr      r1, [pc, #0x54]  ; =0x3f95f0 gGameWork
11806d54: ldr      r2, [pc, #0x54]  ; =0x3f9de0
11806d58: ldr      r1, [r1, #0x3dc]
11806d5c: lsl      r1, r1, #0xc
11806d60: lsr      r1, r1, #0x1f
11806d64: orr      r1, r3, r1, lsl #5
11806d68: add      r3, r0, #0x61000
11806d6c: mov      r0, #0
11806d70: strb     r1, [r3, #0xc]
11806d74: add      r4, r2, r0, lsl #1
11806d78: ldrsh    r4, [r4]
11806d7c: cmp      r4, #0
11806d80: blt      #0x11806da4
11806d84: tst      r1, ip, lsl r0
11806d88: beq      #0x11806da4
11806d8c: add      r0, r0, #1
11806d90: and      r0, r0, #0xff
11806d94: cmp      r0, #6
11806d98: blo      #0x11806d74
11806d9c: orr      r0, r1, #0x40
11806da0: strb     r0, [r3, #0xc]
11806da4: pop      {r4}
11806da8: bx       lr
11806dac: ldrshteq sb, [pc], -r0
11806db0: eorseq   sb, pc, r0, ror #27
11806db4: push     {r4, lr}
11806db8: mov      r4, r0
11806dbc: add      r0, r0, #0x37000
11806dc0: mov      r2, #0
11806dc4: add      r1, pc, #0x1c
11806dc8: add      r0, r0, #0x4c
11806dcc: bl       #0x11805cbc
11806dd0: ldr      r0, [pc, #0x24]  ; =0x1180c1f0
11806dd4: add      r2, r4, #0x10000
11806dd8: add      r2, r2, #0x2a00
11806ddc: ldm      r0, {r0, r1}
11806de0: strd     r0, r1, [r2, #4]
11806de4: pop      {r4, pc}
11806de8: strbvc   r6, [lr, #-0x56d]!
11806dec: uqsaxvc  r7, r1, pc
11806df0: rsbvc    r5, r5, #0x194
11806df4: teqlo    r0, #0x1c8
11806df8: andeq    r0, r0, r0
11806dfc: strdne   ip, sp, [r0, r0]
11806e00: push     {r3, r4, r5, lr}
11806e04: mov      r4, r0
11806e08: mov      r1, #0
11806e0c: bl       #0x118068b4
11806e10: add      r0, r4, #0x13000
11806e14: add      r0, r0, #0x304
11806e18: mov      r1, #0
11806e1c: mov      r5, r0
11806e20: bl       #0x118003f0  ; ->msys::MCursorBase::setVisible
11806e24: mov      r0, r5
11806e28: bl       #0x1180657c
11806e2c: add      r0, r4, #0x45000
11806e30: add      r0, r0, #0x110
11806e34: mov      r1, #1
11806e38: strb     r1, [r0, #0x141]
11806e3c: bl       #0x11800390  ; ->msys::MListWndPBase::resetCur
11806e40: mov      r0, #0
11806e44: mov      r3, r0
11806e48: str      r0, [sp]
11806e4c: mov      r2, #1
11806e50: add      r0, r4, #0x12c00
11806e54: mov      r1, r2
11806e58: add      r0, r0, #0x35c
11806e5c: bl       #0x11800350  ; ->msys::MLyt::playAnimeFromNo
11806e60: ldr      r1, [pc, #0x10]  ; =0x1180c000
11806e64: add      r2, r4, #0x10000
11806e68: add      r2, r2, #0x2a00
11806e6c: ldrd     r0, r1, [r1, #0xf8]
11806e70: strd     r0, r1, [r2, #4]
11806e74: pop      {r3, r4, r5, pc}
11806e78: orrne    ip, r0, r0
11806e7c: push     {r3, r4, r5, lr}
11806e80: mov      r4, r0
11806e84: add      r0, r0, #0x45000
11806e88: add      r0, r0, #0x110
11806e8c: mov      r5, r0
11806e90: bl       #0x11800318  ; ->msys::MListWndPBase::getCurItem
11806e94: ldr      r1, [r0, #0x10]
11806e98: mov      r3, #0
11806e9c: add      r0, r4, #0x13800
11806ea0: mov      r2, r3
11806ea4: add      r0, r0, #0x54
11806ea8: bl       #0x118002a0  ; ->msys::MMsg::playStr
11806eac: mov      r0, #0
11806eb0: mov      r3, r0
11806eb4: str      r0, [sp]
11806eb8: add      r0, r4, #0x12c00
11806ebc: mov      r2, #1
11806ec0: mov      r1, #2
11806ec4: add      r0, r0, #0x35c
11806ec8: bl       #0x11800350  ; ->msys::MLyt::playAnimeFromNo
11806ecc: mov      r0, r5
11806ed0: bl       #0x11800318  ; ->msys::MListWndPBase::getCurItem
11806ed4: mov      r1, r0
11806ed8: ldr      r0, [pc, #0x1c]  ; =0x60b04
11806edc: add      r0, r0, r4
11806ee0: bl       #0x1180229c
11806ee4: ldr      r0, [pc, #0x14]  ; =0x1180c118
11806ee8: add      r2, r4, #0x10000
11806eec: add      r2, r2, #0x2a00
11806ef0: ldm      r0, {r0, r1}
11806ef4: strd     r0, r1, [r2, #4]
11806ef8: pop      {r3, r4, r5, pc}
11806efc: andeq    r0, r6, r4, lsl #22
11806f00: orrne    ip, r0, r8, lsl r1
11806f04: push     {r4, r5, r6, lr}
11806f08: mov      r4, r0
11806f0c: add      r0, r0, #0x12c00
11806f10: add      r0, r0, #0x35c
11806f14: bl       #0x11800450  ; ->msys::MLyt::isEnableAnime
11806f18: cmp      r0, #0
11806f1c: moveq    r5, #0
11806f20: bne      #0x11806ffc
11806f24: add      r0, r4, r5, lsl #2
11806f28: add      r0, r0, #0x13000
11806f2c: ldr      r0, [r0, #0x340]
11806f30: ldr      r1, [r0]
11806f34: ldr      r2, [r1, #0x28]
11806f38: mov      r1, #0
11806f3c: blx      r2
11806f40: add      r5, r5, #1
11806f44: cmp      r5, #7
11806f48: blt      #0x11806f24
11806f4c: add      r5, r4, #0x13000
11806f50: ldr      r0, [r5, #0x340]
11806f54: ldr      r1, [r0]
11806f58: ldr      r2, [r1, #0x28]
11806f5c: mov      r1, #1
11806f60: blx      r2
11806f64: ldr      r0, [r5, #0x344]
11806f68: ldr      r1, [r0]
11806f6c: ldr      r2, [r1, #0x28]
11806f70: mov      r1, #1
11806f74: blx      r2
11806f78: ldr      r0, [r5, #0x350]
11806f7c: ldr      r1, [r0]
11806f80: ldr      r2, [r1, #0x28]
11806f84: mov      r1, #1
11806f88: blx      r2
11806f8c: ldr      r0, [r5, #0x34c]
11806f90: ldr      r1, [r0]
11806f94: ldr      r2, [r1, #0x28]
11806f98: mov      r1, #1
11806f9c: blx      r2
11806fa0: add      r0, r4, #0x13000
11806fa4: add      r0, r0, #0x304
11806fa8: mov      r1, #1
11806fac: mov      r5, r0
11806fb0: bl       #0x118003f0  ; ->msys::MCursorBase::setVisible
11806fb4: ldr      r0, [pc, #0x44]  ; =0x61013
11806fb8: ldrb     r0, [r0, r4]
11806fbc: cmp      r0, #0
11806fc0: movne    r0, #1
11806fc4: strb     r0, [r5, #0x18]
11806fc8: mov      r0, r5
11806fcc: bl       #0x1180657c
11806fd0: mov      r1, #1
11806fd4: mov      r0, r4
11806fd8: bl       #0x118068b4
11806fdc: ldr      r1, [pc, #0x20]  ; =0x1180c000
11806fe0: add      r0, r4, #0x12800
11806fe4: add      r0, r0, #0x204
11806fe8: ldrd     r2, r3, [r1, #0x88]
11806fec: add      r1, r1, #0x90
11806ff0: strd     r2, r3, [r0], #8
11806ff4: ldm      r1, {r1, r2}
11806ff8: stm      r0, {r1, r2}
11806ffc: pop      {r4, r5, r6, pc}
11807000: andeq    r1, r6, r3, lsl r0
11807004: orrne    ip, r0, r0
11807008: push     {r4, r5, r6, r7, r8, lr}
1180700c: mov      r4, r0
11807010: add      r0, r0, #0x3dc00
11807014: add      r0, r0, #0x384
11807018: mov      r6, r0
1180701c: bl       #0x11800310  ; ->msys::MListWndPBase::getCurNo
11807020: mov      r5, r0
11807024: bl       #0x11800410  ; ->col::GetBootInfo
11807028: strb     r5, [r0, #0x20d]
1180702c: and      r5, r5, #0xff
11807030: bl       #0x11800410  ; ->col::GetBootInfo
11807034: mov      r1, r0
11807038: add      r0, r4, #0x61000
1180703c: ldrb     r2, [r0, #0x13]
11807040: strb     r2, [r1, #0x20c]
11807044: ldrb     r0, [r0, #0x13]
11807048: cmp      r0, #0
1180704c: beq      #0x11807088
11807050: ldr      r5, [pc, #0xb0]  ; =0x1180c32c
11807054: mov      r0, r6
11807058: bl       #0x11800310  ; ->msys::MListWndPBase::getCurNo
1180705c: add      r0, r0, r0, lsl #2
11807060: mov      r1, #0x10
11807064: ldrb     r5, [r5, r0, lsl #2]
11807068: ldr      r0, [pc, #0x9c]  ; =0x3fbf9c gSndSys
1180706c: bl       #0x118004c0  ; ->SndSys::stopAllBgm
11807070: mov      r0, r5
11807074: bl       #0x11800578  ; ->hb::SetBootInfoColosseum
11807078: ldr      r0, [r4, #8]
1180707c: cmp      r0, #0
11807080: beq      #0x118070ec
11807084: b        #0x118070f8
11807088: nop      
1180708c: bl       #0x11800410  ; ->col::GetBootInfo
11807090: nop      
11807094: nop      
11807098: bl       #0x11800580  ; ->col::BootInfo::dataPartyBackup
1180709c: ldr      r7, [pc, #0x6c]  ; =0x1180c268
118070a0: mov      r0, r6
118070a4: bl       #0x11800310  ; ->msys::MListWndPBase::getCurNo
118070a8: rsb      r0, r0, r0, lsl #3
118070ac: cmp      r5, #6
118070b0: add      r0, r7, r0, lsl #2
118070b4: ldr      r1, [r0]
118070b8: ldr      r0, [r0, #4]
118070bc: blo      #0x118070d8
118070c0: and      r2, r0, #0xff
118070c4: ldr      r1, [r7]
118070c8: mov      r0, r4
118070cc: pop      {r4, r5, r6, r7, r8, lr}
118070d0: mov      r3, #1
118070d4: b        #0x11805b2c
118070d8: and      r2, r0, #0xff
118070dc: mov      r0, r4
118070e0: pop      {r4, r5, r6, r7, r8, lr}
118070e4: mov      r3, #0
118070e8: b        #0x11805b2c
118070ec: ldr      r0, [pc, #0x20]  ; =0x3f62a8 msys::MComSys::_sys
118070f0: ldr      r0, [r0]
118070f4: str      r0, [r4, #8]
118070f8: ldr      r1, [r0, #4]
118070fc: pop      {r4, r5, r6, r7, r8, lr}
11807100: mov      r0, #0
11807104: b        #0x11800540  ; ->GameMain::Change
11807108: orrne    ip, r0, ip, lsr #6
1180710c: mlaseq   pc, ip, pc, fp
11807110: orrne    ip, r0, r8, ror #4
11807114: eorseq   r6, pc, r8, lsr #5
11807118: push     {r4, r5, r6, lr}
1180711c: mov      r4, r0
11807120: add      r0, r0, #0x12800
11807124: vpush    {d8}
11807128: sub      sp, sp, #8
1180712c: add      r0, r0, #0x3b4
11807130: bl       #0x11800588  ; ->msys::MLyt::isBusyAnime
11807134: cmp      r0, #0
11807138: bne      #0x1180720c
1180713c: add      r0, r4, #0x12c00
11807140: add      r0, r0, #0x35c
11807144: bl       #0x11800588  ; ->msys::MLyt::isBusyAnime
11807148: cmp      r0, #0
1180714c: bne      #0x1180720c
11807150: add      r5, r4, #0x61000
11807154: ldr      r6, [pc, #0xc8]  ; =0x3f62a8 msys::MComSys::_sys
11807158: ldrb     r0, [r5, #0xa]
1180715c: tst      r0, #1
11807160: beq      #0x1180719c
11807164: ldr      r0, [r4, #8]
11807168: cmp      r0, #0
1180716c: ldreq    r0, [r6]
11807170: streq    r0, [r4, #8]
11807174: ldr      r0, [r0, #4]
11807178: bl       #0x118003e8  ; ->ad::fw::TaskBase::isFps30
1180717c: cmp      r0, #0
11807180: ldr      r0, [pc, #0xa8]  ; =0x60ffc
11807184: vldrne   s0, [pc, #0x9c]  ; =0x40000000 (2)
11807188: vldreq   s0, [pc, #0x9c]  ; =0x3f800000 (1)
1180718c: add      r0, r0, r4
11807190: bl       #0x118004d8  ; ->Frm::update
11807194: cmp      r0, #0
11807198: bne      #0x1180720c
1180719c: ldrb     r0, [r5, #0x13]
118071a0: add      r5, r4, #0x10000
118071a4: add      r5, r5, #0x2a00
118071a8: cmp      r0, #0
118071ac: beq      #0x11807218
118071b0: ldr      r0, [r4, #8]
118071b4: vldr     s16, [pc, #0x7c]  ; =0x41800000 (16)
118071b8: cmp      r0, #0
118071bc: ldreq    r0, [r6]
118071c0: vmov.f32 s0, s16
118071c4: mov      r6, sp
118071c8: streq    r0, [r4, #8]
118071cc: mov      r4, r0
118071d0: mov      r0, #0xff
118071d4: mov      r1, r6
118071d8: rev      r0, r0
118071dc: str      r0, [sp]
118071e0: ldr      r0, [pc, #0x4c]  ; =0x4acd4
118071e4: add      r0, r0, r4
118071e8: bl       #0x11800480  ; ->MoveC::moveFrm
118071ec: ldr      r0, [pc, #0x48]  ; =0x4ad14
118071f0: vmov.f32 s0, s16
118071f4: mov      r1, r6
118071f8: add      r0, r0, r4
118071fc: bl       #0x11800480  ; ->MoveC::moveFrm
11807200: ldr      r1, [pc, #0x38]  ; =0x1180c160
11807204: ldm      r1, {r0, r1}
11807208: strd     r0, r1, [r5, #4]
1180720c: add      sp, sp, #8
11807210: vpop     {d8}
11807214: pop      {r4, r5, r6, pc}
11807218: ldr      r0, [pc, #0x24]  ; =0x1180c168
1180721c: ldm      r0, {r0, r1}
11807220: b        #0x11807208
11807224: eorseq   r6, pc, r8, lsr #5
11807228: andmi    r0, r0, r0
1180722c: svclo    #0x800000
11807230: strdeq   r0, r1, [r6], -ip
11807234: ldrdeq   sl, fp, [r4], -r4
11807238: orrmi    r0, r0, r0
1180723c: andeq    sl, r4, r4, lsl sp
11807240: orrne    ip, r0, r0, ror #2
11807244: orrne    ip, r0, r8, ror #2
11807248: push     {r4, r5, r6, lr}
1180724c: mov      r4, r0
11807250: add      r0, r0, #0x3d000
11807254: ldr      r1, [r0, #0xc94]
11807258: cmp      r1, #0
1180725c: bne      #0x118072ac
11807260: ldr      r1, [r0, #0xf80]
11807264: add      r0, r4, #0x37000
11807268: add      r5, r4, #0x10000
1180726c: cmp      r1, #0
11807270: add      r0, r0, #0x4c
11807274: add      r5, r5, #0x2a00
11807278: mov      r2, #0
1180727c: beq      #0x118072b0
11807280: add      r1, pc, #0x40
11807284: bl       #0x11805cbc
11807288: ldr      r0, [pc, #0x4c]  ; =0x3f40a8 Backup::_fs
1180728c: mov      r1, #0
11807290: ldr      r0, [r0]
11807294: strh     r1, [r0, #0x24]
11807298: add      r0, r4, #0x10
1180729c: bl       #0x11800260  ; ->Backup::format
118072a0: ldr      r1, [pc, #0x38]  ; =0x1180c1e8
118072a4: ldm      r1, {r0, r1}
118072a8: strd     r0, r1, [r5, #4]
118072ac: pop      {r4, r5, r6, pc}
118072b0: ldr      r1, [pc, #0x2c]  ; =0x11806de8
118072b4: bl       #0x11805cbc
118072b8: ldr      r1, [pc, #0x28]  ; =0x1180c1f0
118072bc: ldm      r1, {r0, r1}
118072c0: strd     r0, r1, [r5, #4]
118072c4: pop      {r4, r5, r6, pc}
118072c8: strbvc   r6, [lr, #-0x56d]!
118072cc: uqsaxvc  r7, r1, pc
118072d0: rsbvc    r5, r5, #0x194
118072d4: eorslo   r5, r0, #0x1c8
118072d8: andeq    r0, r0, r0
118072dc: eorseq   r4, pc, r8, lsr #1
118072e0: orrne    ip, r0, r8, ror #3
118072e4: orrne    r6, r0, r8, ror #27
118072e8: strdne   ip, sp, [r0, r0]
118072ec: push     {r3, r4, r5, lr}
118072f0: mov      r5, #0
118072f4: mov      r4, r0
118072f8: add      r0, r0, #0x12c00
118072fc: mov      r3, r5
11807300: mov      r2, r5
11807304: mov      r1, #1
11807308: add      r0, r0, #0x35c
1180730c: str      r5, [sp]
11807310: bl       #0x11800350  ; ->msys::MLyt::playAnimeFromNo
11807314: ldr      r0, [pc, #0x18]  ; =0x45251
11807318: add      r2, r4, #0x10000
1180731c: add      r2, r2, #0x2a00
11807320: strb     r5, [r0, r4]
11807324: ldr      r0, [pc, #0xc]  ; =0x1180c080
11807328: ldm      r0, {r0, r1}
1180732c: strd     r0, r1, [r2, #4]
11807330: pop      {r3, r4, r5, pc}
11807334: andeq    r5, r4, r1, asr r2
11807338: orrne    ip, r0, r0, lsl #1
1180733c: push     {r3, r4, r5, lr}
11807340: mov      r4, r0
11807344: mov      r0, #0
11807348: mov      r3, r0
1180734c: mov      r2, r0
11807350: str      r0, [sp]
11807354: add      r0, r4, #0x12c00
11807358: mov      r1, #2
1180735c: add      r0, r0, #0x35c
11807360: bl       #0x11800350  ; ->msys::MLyt::playAnimeFromNo
11807364: ldr      r0, [pc, #0x1c]  ; =0x45251
11807368: mov      r1, #1
1180736c: add      r2, r4, #0x10000
11807370: add      r2, r2, #0x2a00
11807374: strb     r1, [r0, r4]
11807378: ldr      r1, [pc, #0xc]  ; =0x1180c000
1180737c: ldrd     r0, r1, [r1, #0xf8]
11807380: strd     r0, r1, [r2, #4]
11807384: pop      {r3, r4, r5, pc}
11807388: andeq    r5, r4, r1, asr r2
1180738c: orrne    ip, r0, r0
11807390: push     {r4, r5, r6, r7, r8, sb, sl, fp, lr}
11807394: mov      r4, r0
11807398: add      r7, r0, #0x61000
1180739c: vpush    {d8}
118073a0: sub      sp, sp, #0xc
118073a4: ldrb     r0, [r7, #0x10]
118073a8: cmp      r0, #0
118073ac: bne      #0x118073c0
118073b0: bl       #0x11800410  ; ->col::GetBootInfo
118073b4: bl       #0x118004c8  ; ->col::BootInfo::playBgm
118073b8: cmp      r0, #0
118073bc: beq      #0x11807640
118073c0: add      r0, r4, #0x12c00
118073c4: add      r0, r0, #0x35c
118073c8: mov      r8, r0
118073cc: bl       #0x11800450  ; ->msys::MLyt::isEnableAnime
118073d0: cmp      r0, #0
118073d4: nop      
118073d8: bne      #0x11807640
118073dc: ldrb     r1, [r7, #0xa]
118073e0: ldr      r0, [pc, #0x264]  ; =0x60ffc
118073e4: ldr      r6, [pc, #0x264]  ; =0x3f62a8 msys::MComSys::_sys
118073e8: tst      r1, #1
118073ec: add      r5, r4, r0
118073f0: beq      #0x1180742c
118073f4: ldr      r0, [r4, #8]
118073f8: cmp      r0, #0
118073fc: ldreq    r0, [r6]
11807400: streq    r0, [r4, #8]
11807404: ldr      r0, [r0, #4]
11807408: bl       #0x118003e8  ; ->ad::fw::TaskBase::isFps30
1180740c: cmp      r0, #0
11807410: vldrne   s0, [pc, #0x23c]  ; =0x40000000 (2)
11807414: vldreq   s0, [pc, #0x23c]  ; =0x3f800000 (1)
11807418: mov      r0, r5
1180741c: bl       #0x118004d8  ; ->Frm::update
11807420: cmp      r0, #0
11807424: nop      
11807428: bne      #0x11807640
1180742c: mov      r0, r5
11807430: vldr     s0, [pc, #0x224]  ; =0x42700000 (60)
11807434: bl       #0x11800440  ; ->Frm::play
11807438: ldrb     r0, [r7, #0x10]
1180743c: mov      r5, #0
11807440: mov      r3, r5
11807444: cmp      r0, #0
11807448: mov      r2, #1
1180744c: str      r5, [sp]
11807450: beq      #0x11807620
11807454: mov      r1, #0xb
11807458: mov      r0, r8
1180745c: bl       #0x11800350  ; ->msys::MLyt::playAnimeFromNo
11807460: ldr      r0, [r4, #8]
11807464: cmp      r0, #0
11807468: ldreq    r0, [r6]
1180746c: streq    r0, [r4, #8]
11807470: cmp      r0, #0
11807474: add      r3, r0, #0x4a000
11807478: ldreq    r0, [r6]
1180747c: add      r3, r3, #0xaa0
11807480: streq    r0, [r4, #8]
11807484: add      r0, r0, #0xe6000
11807488: ldr      r2, [r0, #0x4f0]
1180748c: ldr      r0, [r4, #4]
11807490: ldr      r1, [r0, #0x18]
11807494: mov      r0, #0x400
11807498: str      r0, [sp]
1180749c: add      r0, r4, #0x36c00
118074a0: add      r0, r0, #0x154
118074a4: mov      sl, r0
118074a8: bl       #0x11800230  ; ->msys::MDfxChr::init
118074ac: mov      r1, #0x26
118074b0: mov      r0, sl
118074b4: bl       #0x118002d8  ; ->msys::MDfxChr::playDfx
118074b8: ldr      sb, [pc, #0x1a0]  ; =0x3f7eec _ZGVZN2nn4math4VEC34ZeroEvE4zero
118074bc: vldr     s16, [pc, #0x1a0]  ; =0x0 (0)
118074c0: add      r7, r4, #0x36000
118074c4: add      r7, r7, #0xe20
118074c8: ldrb     r0, [sb]
118074cc: tst      r0, #1
118074d0: bne      #0x11807500
118074d4: add      r0, sb, #0
118074d8: bl       #0x11800568  ; ->__cxa_guard_acquire
118074dc: cmp      r0, #0
118074e0: nop      
118074e4: beq      #0x11807500
118074e8: ldr      r0, [pc, #0x178]  ; =0x434c48 _ZZN2nn4math4VEC34ZeroEvE4zero
118074ec: vstr     s16, [r0]
118074f0: vstr     s16, [r0, #4]
118074f4: vstr     s16, [r0, #8]
118074f8: add      r0, sb, #0
118074fc: bl       #0x11800570  ; ->__cxa_guard_release
11807500: ldr      fp, [pc, #0x160]  ; =0x434c48 _ZZN2nn4math4VEC34ZeroEvE4zero
11807504: mov      r0, r7
11807508: bl       #0x11800200  ; ->MoveVBase::stop
1180750c: ldm      fp, {r0, r1, r2}
11807510: add      r3, r7, #0x1c
11807514: add      r7, r7, #4
11807518: stm      r3, {r0, r1, r2}
1180751c: mov      r3, #0
11807520: stm      r7, {r0, r1, r2}
11807524: add      r0, r4, #0x12800
11807528: add      r2, pc, #0x13c
1180752c: mov      r1, sl
11807530: add      r0, r0, #0x3b4
11807534: str      r5, [sp]
11807538: str      r5, [sp, #4]
1180753c: bl       #0x11800228  ; ->msys::MLyt::attachMChr
11807540: ldr      r0, [r4, #8]
11807544: ldr      r1, [pc, #0x130]  ; =0x4aba4
11807548: cmp      r0, #0
1180754c: ldreq    r0, [r6]
11807550: streq    r0, [r4, #8]
11807554: cmp      r0, #0
11807558: add      r3, r0, r1
1180755c: ldreq    r0, [r6]
11807560: streq    r0, [r4, #8]
11807564: add      r0, r0, #0xe6000
11807568: ldr      r2, [r0, #0x4f0]
1180756c: ldr      r0, [r4, #4]
11807570: ldr      r1, [r0, #0x18]
11807574: ldr      r0, [pc, #0x104]  ; =0x401
11807578: str      r0, [sp]
1180757c: add      r0, r4, #0x36000
11807580: add      r0, r0, #0xed0
11807584: mov      r7, r0
11807588: bl       #0x11800230  ; ->msys::MDfxChr::init
1180758c: mov      r1, #0x27
11807590: mov      r0, r7
11807594: bl       #0x118002d8  ; ->msys::MDfxChr::playDfx
11807598: ldrb     r0, [sb]
1180759c: add      r6, r4, #0x36c00
118075a0: add      r6, r6, #0x39c
118075a4: tst      r0, #1
118075a8: bne      #0x118075d8
118075ac: ldr      r0, [pc, #0xac]  ; =0x3f7eec _ZGVZN2nn4math4VEC34ZeroEvE4zero
118075b0: bl       #0x11800568  ; ->__cxa_guard_acquire
118075b4: cmp      r0, #0
118075b8: nop      
118075bc: beq      #0x118075d8
118075c0: ldr      r0, [pc, #0xa0]  ; =0x434c48 _ZZN2nn4math4VEC34ZeroEvE4zero
118075c4: vstr     s16, [r0]
118075c8: vstr     s16, [r0, #4]
118075cc: vstr     s16, [r0, #8]
118075d0: ldr      r0, [pc, #0x88]  ; =0x3f7eec _ZGVZN2nn4math4VEC34ZeroEvE4zero
118075d4: bl       #0x11800570  ; ->__cxa_guard_release
118075d8: ldr      sb, [pc, #0x88]  ; =0x434c48 _ZZN2nn4math4VEC34ZeroEvE4zero
118075dc: mov      r0, r6
118075e0: bl       #0x11800200  ; ->MoveVBase::stop
118075e4: ldm      sb, {r0, r1, r2}
118075e8: add      r3, r6, #0x1c
118075ec: add      r6, r6, #4
118075f0: stm      r3, {r0, r1, r2}
118075f4: mov      r3, #0
118075f8: stm      r6, {r0, r1, r2}
118075fc: add      r2, pc, #0x68
11807600: mov      r1, r7
11807604: mov      r0, r8
11807608: str      r5, [sp]
1180760c: str      r5, [sp, #4]
11807610: bl       #0x11800228  ; ->msys::MLyt::attachMChr
11807614: nop      
11807618: nop      
1180761c: b        #0x1180762c
11807620: mov      r1, #0xc
11807624: mov      r0, r8
11807628: bl       #0x11800350  ; ->msys::MLyt::playAnimeFromNo
1180762c: ldr      r0, [pc, #0x50]  ; =0x1180c178
11807630: add      r2, r4, #0x10000
11807634: add      r2, r2, #0x2a00
11807638: ldm      r0, {r0, r1}
1180763c: strd     r0, r1, [r2, #4]
11807640: add      sp, sp, #0xc
11807644: vpop     {d8}
11807648: pop      {r4, r5, r6, r7, r8, sb, sl, fp, pc}
1180764c: strdeq   r0, r1, [r6], -ip
11807650: eorseq   r6, pc, r8, lsr #5
11807654: andmi    r0, r0, r0
11807658: svclo    #0x800000
1180765c: rsbsmi   r0, r0, #0
11807660: eorseq   r7, pc, ip, ror #29
11807664: andeq    r0, r0, r0
11807668: subeq    r4, r3, r8, asr #24
1180766c: svcpl    #0x534e49
11807670: ldrbmi   r4, [pc, #-0x742]  ; =0x1000e591
11807674: movtmi   r4, #0x5646
11807678: andeq    r0, r0, r4, asr r0
1180767c: andeq    sl, r4, r4, lsr #23
11807680: andeq    r0, r0, r1, lsl #8
11807684: orrne    ip, r0, r8, ror r1
11807688: ldr      r1, [r0, #8]
1180768c: cmp      r1, #0
11807690: bne      #0x118076a0
11807694: ldr      r1, [pc, #0x38]  ; =0x3f62a8 msys::MComSys::_sys
11807698: ldr      r1, [r1]
1180769c: str      r1, [r0, #8]
118076a0: ldr      r2, [pc, #0x30]  ; =0x4acd4
118076a4: add      r1, r1, r2
118076a8: add      r1, r1, #0x2c
118076ac: vldmia   r1, {s0, s1}
118076b0: vcmpe.f32 s0, s1
118076b4: vmrs     apsr_nzcv, fpscr
118076b8: blo      #0x118076d0
118076bc: add      r2, r0, #0x10000
118076c0: ldr      r0, [pc, #0x14]  ; =0x1180c168
118076c4: add      r2, r2, #0x2a00
118076c8: ldm      r0, {r0, r1}
118076cc: strd     r0, r1, [r2, #4]
118076d0: bx       lr
118076d4: eorseq   r6, pc, r8, lsr #5
118076d8: ldrdeq   sl, fp, [r4], -r4
118076dc: orrne    ip, r0, r8, ror #2
118076e0: push     {r4, r5, r6, lr}
118076e4: mov      r4, r0
118076e8: add      r0, r0, #0x12c00
118076ec: add      r0, r0, #0x35c
118076f0: bl       #0x11800450  ; ->msys::MLyt::isEnableAnime
118076f4: cmp      r0, #0
118076f8: moveq    r5, #0
118076fc: bne      #0x118077b4
11807700: add      r0, r4, r5, lsl #2
11807704: add      r0, r0, #0x13000
11807708: ldr      r0, [r0, #0x340]
1180770c: ldr      r1, [r0]
11807710: ldr      r2, [r1, #0x28]
11807714: mov      r1, #0
11807718: blx      r2
1180771c: add      r5, r5, #1
11807720: cmp      r5, #7
11807724: blt      #0x11807700
11807728: add      r5, r4, #0x13000
1180772c: ldr      r0, [r5, #0x348]
11807730: ldr      r1, [r0]
11807734: ldr      r2, [r1, #0x28]
11807738: mov      r1, #1
1180773c: blx      r2
11807740: ldr      r0, [r5, #0x34c]
11807744: ldr      r1, [r0]
11807748: ldr      r2, [r1, #0x28]
1180774c: mov      r1, #1
11807750: blx      r2
11807754: add      r5, r4, #0x13000
11807758: add      r5, r5, #0x304
1180775c: mov      r0, #2
11807760: strb     r0, [r5, #0x18]
11807764: mov      r1, #1
11807768: mov      r0, r5
1180776c: bl       #0x118003f0  ; ->msys::MCursorBase::setVisible
11807770: mov      r0, r5
11807774: nop      
11807778: bl       #0x1180657c
1180777c: ldr      r0, [pc, #0x34]  ; =0x3e0c5
11807780: mov      r1, #0
11807784: strb     r1, [r0, r4]
11807788: mov      r1, #1
1180778c: mov      r0, r4
11807790: bl       #0x118068b4
11807794: ldr      r1, [pc, #0x20]  ; =0x1180c000
11807798: add      r0, r4, #0x12800
1180779c: add      r0, r0, #0x204
118077a0: ldrd     r2, r3, [r1, #0xe8]
118077a4: add      r1, r1, #0xf0
118077a8: strd     r2, r3, [r0], #8
118077ac: ldm      r1, {r1, r2}
118077b0: stm      r0, {r1, r2}
118077b4: pop      {r4, r5, r6, pc}
118077b8: andeq    lr, r3, r5, asr #1
118077bc: orrne    ip, r0, r0
118077c0: push     {r3, r4, r5, r6, r7, r8, sb, lr}
118077c4: mov      r4, r0
118077c8: add      r0, r0, #0x12c00
118077cc: add      r0, r0, #0x35c
118077d0: mov      sb, r0
118077d4: bl       #0x11800450  ; ->msys::MLyt::isEnableAnime
118077d8: cmp      r0, #0
118077dc: bne      #0x118078e0
118077e0: add      r5, r4, #0x61000
118077e4: ldr      r0, [pc, #0x11c]  ; =0x60ffc
118077e8: ldrb     r1, [r5, #0xa]
118077ec: add      r6, r4, r0
118077f0: tst      r1, #1
118077f4: beq      #0x11807838
118077f8: ldr      r0, [r4, #8]
118077fc: cmp      r0, #0
11807800: bne      #0x11807810
11807804: ldr      r0, [pc, #0x100]  ; =0x3f62a8 msys::MComSys::_sys
11807808: ldr      r0, [r0]
1180780c: str      r0, [r4, #8]
11807810: ldr      r0, [r0, #4]
11807814: bl       #0x118003e8  ; ->ad::fw::TaskBase::isFps30
11807818: cmp      r0, #0
1180781c: vldrne   s0, [pc, #0xec]  ; =0x40000000 (2)
11807820: vldreq   s0, [pc, #0xec]  ; =0x3f800000 (1)
11807824: mov      r0, r6
11807828: bl       #0x118004d8  ; ->Frm::update
1180782c: cmp      r0, #0
11807830: nop      
11807834: bne      #0x118078e0
11807838: ldrb     r0, [r5, #0x10]
1180783c: add      r8, r4, #0x10000
11807840: add      r8, r8, #0x2a00
11807844: cmp      r0, #0
11807848: ldrbne   r0, [r5, #0x11]
1180784c: mov      r7, #0
11807850: cmpne    r0, #0
11807854: beq      #0x118078e4
11807858: bl       #0x11800410  ; ->col::GetBootInfo
1180785c: ldrb     r0, [r0, #0x20d]
11807860: cmp      r0, #0xc
11807864: beq      #0x11807874
11807868: ldrb     r0, [r5, #0x13]
1180786c: cmp      r0, #0
11807870: beq      #0x11807898
11807874: mov      r3, #0
11807878: mov      r2, #1
1180787c: mov      r1, #0xa
11807880: mov      r0, sb
11807884: str      r7, [sp]
11807888: bl       #0x11800350  ; ->msys::MLyt::playAnimeFromNo
1180788c: nop      
11807890: nop      
11807894: b        #0x118078b0
11807898: mov      r3, #0
1180789c: mov      r2, #1
118078a0: mov      r1, #9
118078a4: mov      r0, sb
118078a8: str      r7, [sp]
118078ac: bl       #0x11800350  ; ->msys::MLyt::playAnimeFromNo
118078b0: vldr     s0, [pc, #0x60]  ; =0x42700000 (60)
118078b4: mov      r0, r6
118078b8: bl       #0x11800440  ; ->Frm::play
118078bc: mov      r3, #0
118078c0: ldr      r1, [pc, #0x54]  ; =0x110023
118078c4: mov      r2, r3
118078c8: mov      r0, r4
118078cc: str      r7, [sp]
118078d0: bl       #0x11806814
118078d4: ldr      r0, [pc, #0x44]  ; =0x1180c180
118078d8: ldm      r0, {r0, r1}
118078dc: strd     r0, r1, [r8, #4]
118078e0: pop      {r3, r4, r5, r6, r7, r8, sb, pc}
118078e4: mov      r3, #0
118078e8: mov      r2, #1
118078ec: mov      r1, #0xd
118078f0: mov      r0, sb
118078f4: str      r7, [sp]
118078f8: bl       #0x11800350  ; ->msys::MLyt::playAnimeFromNo
118078fc: ldr      r1, [pc, #0x20]  ; =0x1180c188
11807900: ldm      r1, {r0, r1}
11807904: b        #0x118078dc
11807908: strdeq   r0, r1, [r6], -ip
1180790c: eorseq   r6, pc, r8, lsr #5
11807910: andmi    r0, r0, r0
11807914: svclo    #0x800000
11807918: rsbsmi   r0, r0, #0
1180791c: andseq   r0, r1, r3, lsr #32
11807920: orrne    ip, r0, r0, lsl #3
11807924: orrne    ip, r0, r8, lsl #3
11807928: push     {r4, r5, r6, lr}
1180792c: mov      r4, r0
11807930: add      r0, r0, #0x12c00
11807934: add      r0, r0, #0x35c
11807938: bl       #0x11800450  ; ->msys::MLyt::isEnableAnime
1180793c: cmp      r0, #0
11807940: moveq    r5, #0
11807944: bne      #0x118079b8
11807948: add      r0, r4, r5, lsl #2
1180794c: add      r0, r0, #0x13000
11807950: ldr      r0, [r0, #0x340]
11807954: ldr      r1, [r0]
11807958: ldr      r2, [r1, #0x28]
1180795c: mov      r1, #0
11807960: blx      r2
11807964: add      r5, r5, #1
11807968: cmp      r5, #7
1180796c: blt      #0x11807948
11807970: ldr      r0, [pc, #0x44]  ; =0x1334c
11807974: ldr      r0, [r0, r4]
11807978: ldr      r1, [r0]
1180797c: ldr      r2, [r1, #0x28]
11807980: mov      r1, #1
11807984: blx      r2
11807988: mov      r1, #1
1180798c: mov      r0, r4
11807990: bl       #0x118068b4
11807994: ldr      r3, [pc, #0x24]  ; =0x1180c000
11807998: add      r1, r4, #0x12800
1180799c: add      r1, r1, #0x20c
118079a0: add      r0, r3, #0x108
118079a4: add      r3, r3, #0x100
118079a8: ldm      r3, {r2, r3}
118079ac: strd     r2, r3, [r1], #-8
118079b0: ldm      r0, {r0, r2}
118079b4: stm      r1, {r0, r2}
118079b8: pop      {r4, r5, r6, pc}
118079bc: andeq    r3, r1, ip, asr #6
118079c0: orrne    ip, r0, r0
118079c4: push     {r4, r5, r6, lr}
118079c8: mov      r4, r0
118079cc: add      r0, r0, #0x12c00
118079d0: add      r0, r0, #0x35c
118079d4: bl       #0x11800450  ; ->msys::MLyt::isEnableAnime
118079d8: cmp      r0, #0
118079dc: moveq    r5, #0
118079e0: bne      #0x11807a74
118079e4: add      r0, r4, r5, lsl #2
118079e8: add      r0, r0, #0x13000
118079ec: ldr      r0, [r0, #0x340]
118079f0: ldr      r1, [r0]
118079f4: ldr      r2, [r1, #0x28]
118079f8: mov      r1, #0
118079fc: blx      r2
11807a00: add      r5, r5, #1
11807a04: cmp      r5, #7
11807a08: bge      #0x11807a18
11807a0c: cmp      r5, #5
11807a10: cmpne    r5, #6
11807a14: bne      #0x118079e4
11807a18: ldr      r0, [pc, #0x58]  ; =0x1334c
11807a1c: ldr      r0, [r0, r4]
11807a20: ldr      r1, [r0]
11807a24: ldr      r2, [r1, #0x28]
11807a28: mov      r1, #1
11807a2c: blx      r2
11807a30: ldr      r1, [pc, #0x44]  ; =0x45251
11807a34: mov      r0, #0
11807a38: strb     r0, [r1, r4]
11807a3c: mov      r1, #1
11807a40: mov      r0, r4
11807a44: bl       #0x118068b4
11807a48: ldr      r3, [pc, #0x30]  ; =0x1180c000
11807a4c: add      r0, r4, #0x12800
11807a50: add      r0, r0, #0x20c
11807a54: add      r2, r3, #0x128
11807a58: add      r3, r3, #0x120
11807a5c: ldm      r3, {r1, r3}
11807a60: stm      r0, {r1, r3}
11807a64: add      r0, r4, #0x12800
11807a68: ldm      r2, {r1, r2}
11807a6c: add      r0, r0, #0x204
11807a70: stm      r0, {r1, r2}
11807a74: pop      {r4, r5, r6, pc}
11807a78: andeq    r3, r1, ip, asr #6
11807a7c: andeq    r5, r4, r1, asr r2
11807a80: orrne    ip, r0, r0
11807a84: push     {r4, r5, r6, r7, r8, lr}
11807a88: mov      r4, r0
11807a8c: add      r0, r0, #0x12800
11807a90: add      r0, r0, #0x3b4
11807a94: sub      sp, sp, #8
11807a98: mov      r6, r0
11807a9c: bl       #0x11800588  ; ->msys::MLyt::isBusyAnime
11807aa0: cmp      r0, #0
11807aa4: bne      #0x11807b9c
11807aa8: ldr      r1, [pc, #0xf4]  ; =0x3f62a8 msys::MComSys::_sys
11807aac: ldr      r0, [r4, #8]
11807ab0: cmp      r0, #0
11807ab4: ldreq    r0, [r1]
11807ab8: streq    r0, [r4, #8]
11807abc: cmp      r0, #0
11807ac0: add      r3, r0, #0x4a000
11807ac4: ldreq    r0, [r1]
11807ac8: add      r3, r3, #0xaa0
11807acc: streq    r0, [r4, #8]
11807ad0: add      r0, r0, #0xe6000
11807ad4: ldr      r2, [r0, #0x4f0]
11807ad8: ldr      r0, [r4, #4]
11807adc: ldr      r1, [r0, #0x18]
11807ae0: mov      r0, #0x400
11807ae4: str      r0, [sp]
11807ae8: add      r0, r4, #0x36800
11807aec: add      r0, r0, #0x25c
11807af0: mov      r8, r0
11807af4: bl       #0x11800230  ; ->msys::MDfxChr::init
11807af8: mov      r1, #0x2c
11807afc: mov      r0, r8
11807b00: bl       #0x118002d8  ; ->msys::MDfxChr::playDfx
11807b04: ldr      r0, [pc, #0x9c]  ; =0x3f7eec _ZGVZN2nn4math4VEC34ZeroEvE4zero
11807b08: add      r5, r4, #0x36800
11807b0c: add      r5, r5, #0x328
11807b10: ldrb     r0, [r0]
11807b14: tst      r0, #1
11807b18: bne      #0x11807b48
11807b1c: ldr      r0, [pc, #0x84]  ; =0x3f7eec _ZGVZN2nn4math4VEC34ZeroEvE4zero
11807b20: bl       #0x11800568  ; ->__cxa_guard_acquire
11807b24: cmp      r0, #0
11807b28: beq      #0x11807b48
11807b2c: ldr      r0, [pc, #0x7c]  ; =0x434c48 _ZZN2nn4math4VEC34ZeroEvE4zero
11807b30: vldr     s0, [pc, #0x74]  ; =0x0 (0)
11807b34: vstr     s0, [r0]
11807b38: vstr     s0, [r0, #4]
11807b3c: vstr     s0, [r0, #8]
11807b40: ldr      r0, [pc, #0x60]  ; =0x3f7eec _ZGVZN2nn4math4VEC34ZeroEvE4zero
11807b44: bl       #0x11800570  ; ->__cxa_guard_release
11807b48: ldr      r7, [pc, #0x60]  ; =0x434c48 _ZZN2nn4math4VEC34ZeroEvE4zero
11807b4c: mov      r0, r5
11807b50: bl       #0x11800200  ; ->MoveVBase::stop
11807b54: ldm      r7, {r0, r1, r2}
11807b58: add      r3, r5, #0x1c
11807b5c: add      r5, r5, #4
11807b60: stm      r3, {r0, r1, r2}
11807b64: stm      r5, {r0, r1, r2}
11807b68: mov      r0, #0
11807b6c: mov      r3, r0
11807b70: str      r0, [sp]
11807b74: str      r0, [sp, #4]
11807b78: add      r2, pc, #0x34
11807b7c: mov      r1, r8
11807b80: mov      r0, r6
11807b84: bl       #0x11800228  ; ->msys::MLyt::attachMChr
11807b88: ldr      r1, [pc, #0x38]  ; =0x1180c1c0
11807b8c: add      r2, r4, #0x10000
11807b90: add      r2, r2, #0x2a00
11807b94: ldm      r1, {r0, r1}
11807b98: strd     r0, r1, [r2, #4]
11807b9c: add      sp, sp, #8
11807ba0: pop      {r4, r5, r6, r7, r8, pc}
11807ba4: eorseq   r6, pc, r8, lsr #5
11807ba8: eorseq   r7, pc, ip, ror #29
11807bac: andeq    r0, r0, r0
11807bb0: subeq    r4, r3, r8, asr #24
11807bb4: svcpl    #0x534e49
11807bb8: subpl    r4, sp, r3, asr #30
11807bbc: ldrbmi   r4, [r4, #-0x54c]
11807bc0: .word    0x4646455f
11807bc4: subseq   r4, r4, r5, asr #6
11807bc8: orrne    ip, r0, r0, asr #3
11807bcc: push     {r3, r4, r5, r6, r7, lr}
11807bd0: mov      r4, r0
11807bd4: add      r0, r0, #0x12c00
11807bd8: mov      r1, #9
11807bdc: add      r0, r0, #0x35c
11807be0: bl       #0x11800590  ; ->msys::MLyt::getAnime
11807be4: mov      r1, r0
11807be8: ldr      r0, [pc, #0x170]  ; =0x60ff4
11807bec: vldr     s0, [pc, #0x170]  ; =0x0 (0)
11807bf0: mov      r7, #1
11807bf4: mov      r6, #0
11807bf8: ldr      r0, [r0, r4]
11807bfc: cmp      r0, #0
11807c00: vldrne   s1, [r0, #0xc]
11807c04: vcmpne.f32 s1, s0
11807c08: vmrsne   apsr_nzcv, fpscr
11807c0c: ldrbne   r0, [r0, #0x12]
11807c10: tstne    r0, #1
11807c14: bne      #0x11807d48
11807c18: cmp      r1, #0
11807c1c: vldrne   s1, [r1, #0xc]
11807c20: vcmpne.f32 s1, s0
11807c24: vmrsne   apsr_nzcv, fpscr
11807c28: ldrbne   r0, [r1, #0x12]
11807c2c: tstne    r0, #1
11807c30: bne      #0x11807d48
11807c34: add      r5, r4, #0x61000
11807c38: ldrb     r0, [r5, #0xa]
11807c3c: tst      r0, #1
11807c40: beq      #0x11807c88
11807c44: ldr      r0, [r4, #8]
11807c48: cmp      r0, #0
11807c4c: bne      #0x11807c5c
11807c50: ldr      r0, [pc, #0x110]  ; =0x3f62a8 msys::MComSys::_sys
11807c54: ldr      r0, [r0]
11807c58: str      r0, [r4, #8]
11807c5c: ldr      r0, [r0, #4]
11807c60: bl       #0x118003e8  ; ->ad::fw::TaskBase::isFps30
11807c64: cmp      r0, #0
11807c68: ldr      r0, [pc, #0x104]  ; =0x60ffc
11807c6c: vldrne   s0, [pc, #0xf8]  ; =0x40000000 (2)
11807c70: vldreq   s0, [pc, #0xf8]  ; =0x3f800000 (1)
11807c74: add      r0, r0, r4
11807c78: bl       #0x118004d8  ; ->Frm::update
11807c7c: cmp      r0, #0
11807c80: nop      
11807c84: bne      #0x11807d48
11807c88: ldrb     r2, [r5, #0x14]
11807c8c: ldr      r1, [pc, #0xe4]  ; =0x3f9de0
11807c90: mov      r0, #0
11807c94: strb     r2, [sp]
11807c98: ldrb     r2, [r5, #0x15]
11807c9c: strb     r2, [sp, #1]
11807ca0: strb     r7, [r5, #0x14]
11807ca4: add      r2, r1, r0, lsl #1
11807ca8: ldrsh    r2, [r2]
11807cac: cmp      r2, #0
11807cb0: bge      #0x11807cbc
11807cb4: strb     r6, [r5, #0x14]
11807cb8: b        #0x11807ccc
11807cbc: add      r0, r0, #1
11807cc0: and      r0, r0, #0xff
11807cc4: cmp      r0, #7
11807cc8: blo      #0x11807ca4
11807ccc: ldr      r1, [pc, #0xa8]  ; =0x3f9df4
11807cd0: mov      r0, #0
11807cd4: strb     r7, [r5, #0x15]
11807cd8: add      r2, r1, r0, lsl #1
11807cdc: ldrsh    r2, [r2]
11807ce0: cmp      r2, #0
11807ce4: bge      #0x11807cf0
11807ce8: strb     r6, [r5, #0x15]
11807cec: b        #0x11807d00
11807cf0: add      r0, r0, #1
11807cf4: and      r0, r0, #0xff
11807cf8: cmp      r0, #4
11807cfc: blo      #0x11807cd8
11807d00: add      r0, r4, #0x36800
11807d04: add      r0, r0, #0x3d8
11807d08: bl       #0x118002d0  ; ->msys::MDfxChr::term
11807d0c: ldrsb    r1, [r5, #0x13]
11807d10: add      r2, r4, #0x61000
11807d14: add      r2, r2, #0x14
11807d18: add      r0, r4, #0x10000
11807d1c: ldrb     r2, [r1, r2]
11807d20: add      r0, r0, #0x2a00
11807d24: cmp      r2, #0
11807d28: beq      #0x11807d38
11807d2c: ldrb     r1, [sp, r1]
11807d30: cmp      r1, #0
11807d34: beq      #0x11807d4c
11807d38: ldr      r2, [pc, #0x40]  ; =0x1180c1a8
11807d3c: add      r0, r0, #4
11807d40: ldm      r2, {r1, r2}
11807d44: stm      r0, {r1, r2}
11807d48: pop      {r3, r4, r5, r6, r7, pc}
11807d4c: ldr      r1, [pc, #0x30]  ; =0x1180c1b0
11807d50: add      r0, r0, #4
11807d54: ldm      r1, {r1, r2}
11807d58: stm      r0, {r1, r2}
11807d5c: pop      {r3, r4, r5, r6, r7, pc}
11807d60: strdeq   r0, r1, [r6], -r4
11807d64: andeq    r0, r0, r0
11807d68: eorseq   r6, pc, r8, lsr #5
11807d6c: andmi    r0, r0, r0
11807d70: svclo    #0x800000
11807d74: strdeq   r0, r1, [r6], -ip
11807d78: eorseq   sb, pc, r0, ror #27
11807d7c: ldrshteq sb, [pc], -r4
11807d80: orrne    ip, r0, r8, lsr #3
11807d84: strhne   ip, [r0, r0]
11807d88: push     {r4, r5, r6, lr}
11807d8c: mov      r4, r0
11807d90: add      r0, r0, #0x12800
11807d94: add      r0, r0, #0x3b4
11807d98: bl       #0x11800588  ; ->msys::MLyt::isBusyAnime
11807d9c: cmp      r0, #0
11807da0: bne      #0x11807e54
11807da4: ldr      r1, [pc, #0xac]  ; =0x6100a
11807da8: sub      r0, r1, #0xe
11807dac: ldrb     r1, [r1, r4]
11807db0: add      r5, r4, r0
11807db4: tst      r1, #1
11807db8: beq      #0x11807dfc
11807dbc: ldr      r0, [r4, #8]
11807dc0: cmp      r0, #0
11807dc4: bne      #0x11807dd4
11807dc8: ldr      r0, [pc, #0x8c]  ; =0x3f62a8 msys::MComSys::_sys
11807dcc: ldr      r0, [r0]
11807dd0: str      r0, [r4, #8]
11807dd4: ldr      r0, [r0, #4]
11807dd8: bl       #0x118003e8  ; ->ad::fw::TaskBase::isFps30
11807ddc: cmp      r0, #0
11807de0: vldrne   s0, [pc, #0x78]  ; =0x40000000 (2)
11807de4: vldreq   s0, [pc, #0x78]  ; =0x3f800000 (1)
11807de8: mov      r0, r5
11807dec: bl       #0x118004d8  ; ->Frm::update
11807df0: cmp      r0, #0
11807df4: nop      
11807df8: bne      #0x11807e54
11807dfc: add      r0, r4, #0x12c00
11807e00: mov      r3, #0
11807e04: add      r0, r0, #0x35c
11807e08: mov      r2, r3
11807e0c: add      r1, pc, #0x54
11807e10: mov      r6, r0
11807e14: bl       #0x11800338  ; ->msys::MLyt::createAnimeAutoSlot
11807e18: sxth     r1, r0
11807e1c: mov      r0, r6
11807e20: bl       #0x11800328  ; ->msys::MLyt::getAnim
11807e24: ldr      r0, [r0, #0x14]
11807e28: nop      
11807e2c: bl       #0x118002b8  ; ->ad::lyt::AnimTransform::GetFrameSize
11807e30: vmov     s0, r0
11807e34: mov      r0, r5
11807e38: vcvt.f32.u32 s0, s0
11807e3c: bl       #0x11800440  ; ->Frm::play
11807e40: ldr      r1, [pc, #0x30]  ; =0x1180c150
11807e44: add      r2, r4, #0x10000
11807e48: add      r2, r2, #0x2a00
11807e4c: ldm      r1, {r0, r1}
11807e50: strd     r0, r1, [r2, #4]
11807e54: pop      {r4, r5, r6, pc}
11807e58: andeq    r1, r6, sl
11807e5c: eorseq   r6, pc, r8, lsr #5
11807e60: andmi    r0, r0, r0
11807e64: svclo    #0x800000
11807e68: mrcmi    p5, #2, r5, c2, c4, #2
11807e6c: strbmi   r4, [lr, #-0x55f]
11807e70: ldmdbmi  pc, {r0, r2, r3, r6, r8, fp, ip, lr} ^
11807e74: andeq    r4, r0, sp, asr #14
11807e78: orrne    ip, r0, r0, asr r1
11807e7c: push     {r4, lr}
11807e80: mov      r4, r0
11807e84: mov      r3, #0
11807e88: add      r0, r0, #0x12800
11807e8c: mov      r2, r3
11807e90: add      r1, pc, #0x2c
11807e94: add      r0, r0, #0x3b4
11807e98: bl       #0x11800338  ; ->msys::MLyt::createAnimeAutoSlot
11807e9c: ldr      r0, [pc, #0x30]  ; =0x60ffc
11807ea0: vldr     s0, [pc, #0x28]  ; =0x42700000 (60)
11807ea4: add      r0, r0, r4
11807ea8: bl       #0x11800440  ; ->Frm::play
11807eac: ldr      r0, [pc, #0x24]  ; =0x1180c1b8
11807eb0: add      r2, r4, #0x10000
11807eb4: add      r2, r2, #0x2a00
11807eb8: ldm      r0, {r0, r1}
11807ebc: strd     r0, r1, [r2, #4]
11807ec0: pop      {r4, pc}
11807ec4: subpl    r4, sp, r3, asr #30
11807ec8: ldrbmi   r4, [r4, #-0x54c]
11807ecc: subeq    r4, lr, pc, asr sb
11807ed0: rsbsmi   r0, r0, #0
11807ed4: strdeq   r0, r1, [r6], -ip
11807ed8: strhne   ip, [r0, r8]
11807edc: push     {r4, r5, r6, lr}
11807ee0: mov      r4, r0
11807ee4: ldr      r0, [r0, #8]
11807ee8: ldr      r6, [pc, #0x9c]  ; =0x3f62a8 msys::MComSys::_sys
11807eec: cmp      r0, #0
11807ef0: ldreq    r0, [r6]
11807ef4: streq    r0, [r4, #8]
11807ef8: ldrne    r0, [r4, #8]
11807efc: ldr      r0, [r0, #4]
11807f00: bl       #0x118003e8  ; ->ad::fw::TaskBase::isFps30
11807f04: cmp      r0, #0
11807f08: ldr      r0, [pc, #0x88]  ; =0x60ffc
11807f0c: vldrne   s0, [pc, #0x7c]  ; =0x40000000 (2)
11807f10: vldreq   s0, [pc, #0x7c]  ; =0x3f800000 (1)
11807f14: add      r0, r0, r4
11807f18: mov      r5, r0
11807f1c: bl       #0x118004d8  ; ->Frm::update
11807f20: vldr     s0, [r5]
11807f24: vldr     s1, [pc, #0x70]  ; =0xc2b40000 (-90)
11807f28: ldr      r0, [r4, #8]
11807f2c: ldr      r1, [pc, #0x6c]  ; =0x4ad54
11807f30: vmul.f32 s1, s0, s1
11807f34: vldr     s0, [r5, #8]
11807f38: cmp      r0, #0
11807f3c: ldreq    r0, [r6]
11807f40: streq    r0, [r4, #8]
11807f44: add      r0, r0, r1
11807f48: vdiv.f32 s2, s1, s0
11807f4c: vstr     s2, [r0, #0x14]
11807f50: ldr      r0, [pc, #0x4c]  ; =0x6100a
11807f54: ldrb     r0, [r0, r4]
11807f58: tst      r0, #1
11807f5c: bne      #0x11807f88
11807f60: add      r0, r4, #0x12800
11807f64: add      r0, r0, #0x3b4
11807f68: bl       #0x11800450  ; ->msys::MLyt::isEnableAnime
11807f6c: cmp      r0, #0
11807f70: bne      #0x11807f88
11807f74: ldr      r0, [pc, #0x2c]  ; =0x1180c158
11807f78: add      r2, r4, #0x10000
11807f7c: add      r2, r2, #0x2a00
11807f80: ldm      r0, {r0, r1}
11807f84: strd     r0, r1, [r2, #4]
11807f88: pop      {r4, r5, r6, pc}
11807f8c: eorseq   r6, pc, r8, lsr #5
11807f90: andmi    r0, r0, r0
11807f94: svclo    #0x800000
11807f98: strdeq   r0, r1, [r6], -ip
11807f9c: adcsgt   r0, r4, #0
11807fa0: andeq    sl, r4, r4, asr sp
11807fa4: andeq    r1, r6, sl
11807fa8: orrne    ip, r0, r8, asr r1
11807fac: push     {r4, lr}
11807fb0: mov      r4, r0
11807fb4: mov      r3, #0
11807fb8: add      r0, r0, #0x12800
11807fbc: mov      r2, r3
11807fc0: add      r1, pc, #0x2c
11807fc4: add      r0, r0, #0x3b4
11807fc8: bl       #0x11800338  ; ->msys::MLyt::createAnimeAutoSlot
11807fcc: ldr      r0, [pc, #0x34]  ; =0x60ffc
11807fd0: vldr     s0, [pc, #0x2c]  ; =0x42f00000 (120)
11807fd4: add      r0, r0, r4
11807fd8: bl       #0x11800440  ; ->Frm::play
11807fdc: ldr      r0, [pc, #0x28]  ; =0x1180c148
11807fe0: add      r2, r4, #0x10000
11807fe4: add      r2, r2, #0x2a00
11807fe8: ldm      r0, {r0, r1}
11807fec: strd     r0, r1, [r2, #4]
11807ff0: pop      {r4, pc}
11807ff4: mrcmi    p5, #2, r5, c2, c4, #2
11807ff8: strbmi   r4, [lr, #-0x55f]
11807ffc: vnmlami.f16 s11, s30, s26
11808000: subeq    r4, r5, r1, asr #26
11808004: rscsmi   r0, r0, #0
11808008: strdeq   r0, r1, [r6], -ip
1180800c: orrne    ip, r0, r8, asr #2
11808010: push     {r4, lr}
11808014: mov      r4, r0
11808018: add      r0, r0, #0x61000
1180801c: ldrb     r0, [r0, #0xa]
11808020: tst      r0, #1
11808024: beq      #0x1180806c
11808028: ldr      r0, [r4, #8]
1180802c: cmp      r0, #0
11808030: bne      #0x11808040
11808034: ldr      r0, [pc, #0x48]  ; =0x3f62a8 msys::MComSys::_sys
11808038: ldr      r0, [r0]
1180803c: str      r0, [r4, #8]
11808040: ldr      r0, [r0, #4]
11808044: bl       #0x118003e8  ; ->ad::fw::TaskBase::isFps30
11808048: cmp      r0, #0
1180804c: ldr      r0, [pc, #0x3c]  ; =0x60ffc
11808050: vldrne   s0, [pc, #0x30]  ; =0x40000000 (2)
11808054: vldreq   s0, [pc, #0x30]  ; =0x3f800000 (1)
11808058: add      r0, r0, r4
1180805c: bl       #0x118004d8  ; ->Frm::update
11808060: cmp      r0, #0
11808064: nop      
11808068: bne      #0x11808080
1180806c: ldr      r0, [pc, #0x20]  ; =0x1180c1a8
11808070: add      r2, r4, #0x10000
11808074: add      r2, r2, #0x2a00
11808078: ldm      r0, {r0, r1}
1180807c: strd     r0, r1, [r2, #4]
11808080: pop      {r4, pc}
11808084: eorseq   r6, pc, r8, lsr #5
11808088: andmi    r0, r0, r0
1180808c: svclo    #0x800000
11808090: strdeq   r0, r1, [r6], -ip
11808094: orrne    ip, r0, r8, lsr #3
11808098: push     {r4, r5, r6, lr}
1180809c: mov      r4, r0
118080a0: add      r0, r0, #0x12c00
118080a4: add      r0, r0, #0x35c
118080a8: bl       #0x11800588  ; ->msys::MLyt::isBusyAnime
118080ac: cmp      r0, #0
118080b0: bne      #0x118080ec
118080b4: ldr      r0, [pc, #0x78]  ; =0x61013
118080b8: add      r5, r4, #0x36800
118080bc: add      r5, r5, #0x3d8
118080c0: ldrb     r0, [r0, r4]
118080c4: cmp      r0, #0
118080c8: beq      #0x118080f0
118080cc: mov      r1, #0x2d
118080d0: mov      r0, r5
118080d4: bl       #0x118002d8  ; ->msys::MDfxChr::playDfx
118080d8: ldr      r0, [pc, #0x58]  ; =0x1180c190
118080dc: add      r2, r4, #0x10000
118080e0: add      r2, r2, #0x2a00
118080e4: ldm      r0, {r0, r1}
118080e8: strd     r0, r1, [r2, #4]
118080ec: pop      {r4, r5, r6, pc}
118080f0: nop      
118080f4: bl       #0x11800410  ; ->col::GetBootInfo
118080f8: ldrb     r0, [r0, #0x20d]
118080fc: cmp      r0, #0xc
11808100: beq      #0x1180811c
11808104: mov      r1, #0x28
11808108: mov      r0, r5
1180810c: bl       #0x118002d8  ; ->msys::MDfxChr::playDfx
11808110: nop      
11808114: nop      
11808118: b        #0x118080d8
1180811c: mov      r1, #0x2a
11808120: mov      r0, r5
11808124: bl       #0x118002d8  ; ->msys::MDfxChr::playDfx
11808128: nop      
1180812c: nop      
11808130: b        #0x118080d8
11808134: andeq    r1, r6, r3, lsl r0
11808138: .word    0x1180c190
1180813c: push     {r3, r4, r5, r6, r7, r8, sb, lr}
11808140: mov      r4, r1
11808144: mov      r5, r0
11808148: bl       #0x11806144
1180814c: ldr      r0, [r4]
11808150: ldr      r1, [pc, #0x178]  ; =0xc03
11808154: tst      r0, r1
11808158: beq      #0x11808298
1180815c: mov      r1, #0
11808160: mov      r0, r5
11808164: bl       #0x118068b4
11808168: mov      r4, #0
1180816c: add      r0, r5, #0x12c00
11808170: add      r0, r0, #0x35c
11808174: mov      r3, r4
11808178: mov      r2, r4
1180817c: mov      r1, #0xd
11808180: mov      r8, r0
11808184: str      r4, [sp]
11808188: bl       #0x11800350  ; ->msys::MLyt::playAnimeFromNo
1180818c: mov      r3, #0
11808190: ldr      r1, [pc, #0x13c]  ; =0x110016
11808194: mov      r2, r3
11808198: mov      r0, r5
1180819c: str      r4, [sp]
118081a0: bl       #0x11806814
118081a4: mov      r1, #0
118081a8: mov      r0, r5
118081ac: bl       #0x118068b4
118081b0: add      r7, r5, #0x61000
118081b4: add      r6, r5, #0x10000
118081b8: ldrb     r0, [r7, #0x11]
118081bc: add      r6, r6, #0x2a00
118081c0: cmp      r0, #0
118081c4: beq      #0x11808268
118081c8: bl       #0x11800410  ; ->col::GetBootInfo
118081cc: ldrb     r0, [r0, #0x20d]
118081d0: cmp      r0, #0xc
118081d4: beq      #0x118081e4
118081d8: ldrb     r0, [r7, #0x13]
118081dc: cmp      r0, #0
118081e0: beq      #0x11808208
118081e4: mov      r3, #0
118081e8: mov      r2, r3
118081ec: mov      r1, #0xa
118081f0: mov      r0, r8
118081f4: str      r4, [sp]
118081f8: bl       #0x11800350  ; ->msys::MLyt::playAnimeFromNo
118081fc: nop      
11808200: nop      
11808204: b        #0x11808220
11808208: mov      r3, #0
1180820c: mov      r2, r3
11808210: mov      r1, #9
11808214: mov      r0, r8
11808218: str      r4, [sp]
1180821c: bl       #0x11800350  ; ->msys::MLyt::playAnimeFromNo
11808220: mov      r3, #0
11808224: mov      r2, r3
11808228: mov      r1, #0xb
1180822c: mov      r0, r8
11808230: str      r4, [sp]
11808234: bl       #0x11800350  ; ->msys::MLyt::playAnimeFromNo
11808238: ldr      r0, [pc, #0x98]  ; =0x60ff4
1180823c: vldr     s0, [pc, #0x98]  ; =0x42700000 (60)
11808240: ldr      r0, [r0, r5]
11808244: ldrh     r1, [r0, #0x12]
11808248: bic      r1, r1, #2
1180824c: strh     r1, [r0, #0x12]
11808250: ldr      r0, [pc, #0x88]  ; =0x60ffc
11808254: add      r0, r0, r5
11808258: bl       #0x11800440  ; ->Frm::play
1180825c: ldr      r1, [pc, #0x80]  ; =0x1180c1a0
11808260: ldm      r1, {r0, r1}
11808264: b        #0x118082c8
11808268: ldrb     r0, [r7, #0x12]
1180826c: cmp      r0, #0
11808270: beq      #0x1180829c
11808274: mov      r3, #0
11808278: mov      r2, r3
1180827c: mov      r1, #0xb
11808280: mov      r0, r8
11808284: str      r4, [sp]
11808288: bl       #0x11800350  ; ->msys::MLyt::playAnimeFromNo
1180828c: ldr      r1, [pc, #0x54]  ; =0x1180c1a8
11808290: ldm      r1, {r0, r1}
11808294: strd     r0, r1, [r6, #4]
11808298: pop      {r3, r4, r5, r6, r7, r8, sb, pc}
1180829c: ldrb     r0, [r7, #0x10]
118082a0: cmp      r0, #0
118082a4: beq      #0x118082c0
118082a8: mov      r3, #0
118082ac: mov      r2, r3
118082b0: mov      r1, #0xb
118082b4: mov      r0, r8
118082b8: str      r4, [sp]
118082bc: bl       #0x11800350  ; ->msys::MLyt::playAnimeFromNo
118082c0: ldr      r1, [pc, #0x24]  ; =0x1180c000
118082c4: ldrd     r0, r1, [r1, #0xd8]
118082c8: strd     r0, r1, [r6, #4]
118082cc: pop      {r3, r4, r5, r6, r7, r8, sb, pc}
118082d0: andeq    r0, r0, r3, lsl #24
118082d4: andseq   r0, r1, r6, lsl r0
118082d8: strdeq   r0, r1, [r6], -r4
118082dc: rsbsmi   r0, r0, #0
118082e0: strdeq   r0, r1, [r6], -ip
118082e4: orrne    ip, r0, r0, lsr #3
118082e8: orrne    ip, r0, r8, lsr #3
118082ec: orrne    ip, r0, r0
118082f0: push     {r4, r5, r6, lr}
118082f4: mov      r4, r0
118082f8: add      r0, r0, #0x12c00
118082fc: add      r0, r0, #0x35c
11808300: bl       #0x11800588  ; ->msys::MLyt::isBusyAnime
11808304: cmp      r0, #0
11808308: bne      #0x1180839c
1180830c: ldr      r0, [pc, #0x8c]  ; =0x6100a
11808310: ldrb     r0, [r0, r4]
11808314: tst      r0, #1
11808318: beq      #0x11808360
1180831c: ldr      r0, [r4, #8]
11808320: cmp      r0, #0
11808324: bne      #0x11808334
11808328: ldr      r0, [pc, #0x74]  ; =0x3f62a8 msys::MComSys::_sys
1180832c: ldr      r0, [r0]
11808330: str      r0, [r4, #8]
11808334: ldr      r0, [r0, #4]
11808338: bl       #0x118003e8  ; ->ad::fw::TaskBase::isFps30
1180833c: cmp      r0, #0
11808340: ldr      r0, [pc, #0x68]  ; =0x60ffc
11808344: vldrne   s0, [pc, #0x5c]  ; =0x40000000 (2)
11808348: vldreq   s0, [pc, #0x5c]  ; =0x3f800000 (1)
1180834c: add      r0, r0, r4
11808350: bl       #0x118004d8  ; ->Frm::update
11808354: cmp      r0, #0
11808358: nop      
1180835c: bne      #0x1180839c
11808360: nop      
11808364: bl       #0x11800410  ; ->col::GetBootInfo
11808368: add      r5, r0, #0x200
1180836c: add      r5, r5, #0xd
11808370: bl       #0x11800428  ; ->btl::GetBootInfo
11808374: ldrsb    r1, [r5]
11808378: ldrb     r2, [r0, #0x129]
1180837c: ldr      r0, [pc, #0x30]  ; =0x1180c268
11808380: mov      r3, #1
11808384: rsb      r1, r1, r1, lsl #3
11808388: add      r0, r0, r1, lsl #2
1180838c: ldr      r1, [r0, #-0xa8]
11808390: mov      r0, r4
11808394: pop      {r4, r5, r6, lr}
11808398: b        #0x11805b2c
1180839c: pop      {r4, r5, r6, pc}
118083a0: andeq    r1, r6, sl
118083a4: eorseq   r6, pc, r8, lsr #5
118083a8: andmi    r0, r0, r0
118083ac: svclo    #0x800000
118083b0: strdeq   r0, r1, [r6], -ip
118083b4: orrne    ip, r0, r8, ror #4
118083b8: push     {r3, r4, r5, lr}
118083bc: mov      r4, r0
118083c0: add      r0, r0, #0x61000
118083c4: ldrb     r0, [r0, #0xa]
118083c8: tst      r0, #1
118083cc: beq      #0x11808414
118083d0: ldr      r0, [r4, #8]
118083d4: cmp      r0, #0
118083d8: bne      #0x118083e8
118083dc: ldr      r0, [pc, #0x68]  ; =0x3f62a8 msys::MComSys::_sys
118083e0: ldr      r0, [r0]
118083e4: str      r0, [r4, #8]
118083e8: ldr      r0, [r0, #4]
118083ec: bl       #0x118003e8  ; ->ad::fw::TaskBase::isFps30
118083f0: cmp      r0, #0
118083f4: ldr      r0, [pc, #0x5c]  ; =0x60ffc
118083f8: vldrne   s0, [pc, #0x50]  ; =0x40000000 (2)
118083fc: vldreq   s0, [pc, #0x50]  ; =0x3f800000 (1)
11808400: add      r0, r0, r4
11808404: bl       #0x118004d8  ; ->Frm::update
11808408: cmp      r0, #0
1180840c: nop      
11808410: bne      #0x11808448
11808414: mov      r0, #0
11808418: mov      r3, r0
1180841c: str      r0, [sp]
11808420: add      r0, r4, #0x12c00
11808424: mov      r2, #1
11808428: mov      r1, #0xd
1180842c: add      r0, r0, #0x35c
11808430: bl       #0x11800350  ; ->msys::MLyt::playAnimeFromNo
11808434: ldr      r0, [pc, #0x20]  ; =0x1180c188
11808438: add      r2, r4, #0x10000
1180843c: add      r2, r2, #0x2a00
11808440: ldm      r0, {r0, r1}
11808444: strd     r0, r1, [r2, #4]
11808448: pop      {r3, r4, r5, pc}
1180844c: eorseq   r6, pc, r8, lsr #5
11808450: andmi    r0, r0, r0
11808454: svclo    #0x800000
11808458: strdeq   r0, r1, [r6], -ip
1180845c: orrne    ip, r0, r8, lsl #3
11808460: push     {r4, lr}
11808464: mov      r4, r0
11808468: bl       #0x11806144
1180846c: add      r0, r4, #0x12c00
11808470: mov      r1, #0xd
11808474: add      r0, r0, #0x35c
11808478: bl       #0x11800590  ; ->msys::MLyt::getAnime
1180847c: cmp      r0, #0
11808480: beq      #0x118084a0
11808484: vldr     s0, [r0, #0xc]
11808488: vldr     s1, [pc, #0x34]  ; =0x0 (0)
1180848c: vcmp.f32 s0, s1
11808490: vmrs     apsr_nzcv, fpscr
11808494: ldrbne   r0, [r0, #0x12]
11808498: tstne    r0, #1
1180849c: bne      #0x118084c0
118084a0: mov      r1, #1
118084a4: mov      r0, r4
118084a8: bl       #0x118068b4
118084ac: ldr      r1, [pc, #0x14]  ; =0x1180c198
118084b0: add      r2, r4, #0x10000
118084b4: add      r2, r2, #0x2a00
118084b8: ldm      r1, {r0, r1}
118084bc: strd     r0, r1, [r2, #4]
118084c0: pop      {r4, pc}
118084c4: andeq    r0, r0, r0
118084c8: .word    0x1180c198
118084cc: push     {r4, lr}
118084d0: mov      r4, r0
118084d4: ldr      r0, [pc, #0x20]  ; =0x3e4730
118084d8: str      r0, [r4]
118084dc: add      r0, r4, #0x14c
118084e0: bl       #0x11800598  ; ->Message::term
118084e4: add      r0, r4, #0x14c
118084e8: bl       #0x118005a0  ; ->Message
118084ec: sub      r0, r0, #0x14c
118084f0: bl       #0x118059d0
118084f4: pop      {r4, lr}
118084f8: b        #0x11800190  ; ->_ZdlPv
118084fc: eorseq   r4, lr, r0, lsr r7
11808500: push     {r4, lr}
11808504: mov      r4, r0
11808508: ldr      r0, [pc, #0x1c]  ; =0x3e4730
1180850c: str      r0, [r4]
11808510: add      r0, r4, #0x14c
11808514: bl       #0x11800598  ; ->Message::term
11808518: add      r0, r4, #0x14c
1180851c: bl       #0x118005a0  ; ->Message
11808520: sub      r0, r0, #0x14c
11808524: bl       #0x118059d0
11808528: pop      {r4, pc}
1180852c: eorseq   r4, lr, r0, lsr r7
11808530: push     {r4, lr}
11808534: mov      r4, r0
11808538: bl       #0x11800358  ; ->msys::MListWndPBase::applyAnime
1180853c: add      r0, r4, #0x7000
11808540: pop      {r4, lr}
11808544: add      r0, r0, #0x64
11808548: b        #0x11800360  ; ->ad::lyt::Layout::Animate
1180854c: push     {r4, r5, r6, r7, r8, sb, sl, fp, lr}
11808550: mov      r5, r0
11808554: add      r0, r0, #0x7000
11808558: mov      ip, r1
1180855c: vpush    {d8}
11808560: sub      sp, sp, #0x1a4
11808564: str      r1, [r0, #0x60]
11808568: ldr      r0, [r1, #8]
1180856c: cmp      r0, #0
11808570: bne      #0x11808580
11808574: ldr      r0, [pc, #0x2bc]  ; =0x3f62a8 msys::MComSys::_sys
11808578: ldr      r0, [r0]
1180857c: str      r0, [ip, #8]
11808580: mov      r4, r0
11808584: ldr      r0, [pc, #0x2b0]  ; =0x61013
11808588: mov      r7, #0
1180858c: add      r1, r5, #0x7000
11808590: add      r1, r1, #0x64
11808594: ldrb     sl, [r0, ip]
11808598: add      r0, ip, #0x12000
1180859c: mov      r3, r7
118085a0: add      r2, pc, #0x298
118085a4: mov      r6, r1
118085a8: add      r0, r0, #0xa30
118085ac: str      r7, [sp]
118085b0: bl       #0x11800368  ; ->ad::lyt::LytResourceMan::buildLayout
118085b4: add      r0, r5, #0x7000
118085b8: add      r0, r0, #0xdc
118085bc: add      r3, pc, #0x294
118085c0: add      r2, pc, #0x294
118085c4: mov      r1, r6
118085c8: str      r0, [sp, #0x24]
118085cc: bl       #0x118002b0  ; ->ad::lyt::LytAnim::init
118085d0: add      r0, r5, #0x7000
118085d4: add      r0, r0, #0x14c
118085d8: add      r3, pc, #0x278
118085dc: add      r2, pc, #0x280
118085e0: mov      r1, r6
118085e4: str      r0, [sp, #0x1a0]
118085e8: bl       #0x118002b0  ; ->ad::lyt::LytAnim::init
118085ec: vldr     s17, [pc, #0x27c]  ; =0x3f800000 (1)
118085f0: ldr      r0, [sp, #0x1a0]
118085f4: vmov.f32 s0, s17
118085f8: bl       #0x11800370  ; ->ad::lyt::LytAnim::playAuto
118085fc: add      r1, r5, #0x7000
11808600: add      r1, r1, #0xa0
11808604: add      r0, r4, #0x7d0
11808608: mov      r3, #0
1180860c: add      r2, pc, #0x260
11808610: mov      sb, r1
11808614: str      r7, [sp]
11808618: bl       #0x11800368  ; ->ad::lyt::LytResourceMan::buildLayout
1180861c: add      r0, r5, #0x7000
11808620: add      r0, r0, #0xf8
11808624: add      r3, pc, #0x22c
11808628: add      r2, pc, #0x254
1180862c: mov      r1, sb
11808630: str      r0, [sp, #4]
11808634: bl       #0x118002b0  ; ->ad::lyt::LytAnim::init
11808638: add      r0, r5, #0x7000
1180863c: add      r0, r0, #0x114
11808640: add      r3, pc, #0x210
11808644: add      r2, pc, #0x244
11808648: mov      r1, sb
1180864c: str      r0, [sp]
11808650: bl       #0x118002b0  ; ->ad::lyt::LytAnim::init
11808654: add      r0, r5, #0x7000
11808658: add      r0, r0, #0x130
1180865c: add      r3, pc, #0x1f4
11808660: add      r2, pc, #0x230
11808664: mov      r1, sb
11808668: mov      fp, r0
1180866c: bl       #0x118002b0  ; ->ad::lyt::LytAnim::init
11808670: add      r0, sp, #0x28
11808674: nop      
11808678: bl       #0x11800378  ; ->ad::ui::UIListWindowPlusLyt::InitParam
1180867c: mov      r1, #2
11808680: add      r0, sp, #0x28
11808684: bl       #0x11800380  ; ->msys::SetMListWndInitParam
11808688: ldr      r0, [pc, #0x210]  ; =0xfffb50e8
1180868c: mov      r2, #1
11808690: sub      r8, r4, r0
11808694: add      r0, r8, #0x54
11808698: str      r0, [sp, #0x28]
1180869c: ldr      r0, [r6, #0x10]
118086a0: ldr      r1, [r0]
118086a4: ldr      r3, [r1, #0x2c]
118086a8: add      r1, pc, #0x1f4
118086ac: blx      r3
118086b0: str      r0, [sp, #0x60]
118086b4: ldr      r0, [r6, #0x10]
118086b8: mov      r2, #1
118086bc: ldr      r1, [r0]
118086c0: ldr      r3, [r1, #0x2c]
118086c4: add      r1, pc, #0x1e0
118086c8: blx      r3
118086cc: str      r0, [sp, #0x58]
118086d0: ldr      r0, [r6, #0x10]
118086d4: mov      r2, #1
118086d8: ldr      r1, [r0]
118086dc: ldr      r3, [r1, #0x2c]
118086e0: add      r1, pc, #0x1dc
118086e4: blx      r3
118086e8: str      r0, [sp, #0x54]
118086ec: ldr      r0, [sp, #0x1a0]
118086f0: strb     r7, [sp, #0x90]
118086f4: add      r1, r5, #0x4000
118086f8: str      r0, [sp, #0x88]
118086fc: ldr      r0, [sp, #0x24]
11808700: add      r1, r1, #0x2f80
11808704: add      r2, sp, #0x7c
11808708: str      r0, [sp, #0x84]
1180870c: ldr      r0, [sb, #0x10]
11808710: str      r1, [sp, #0x164]
11808714: cmp      sl, #0
11808718: str      r0, [sp, #0x48]
1180871c: ldr      r0, [sp, #4]
11808720: add      r1, sp, #0xc
11808724: vldr     s16, [pc, #0x1a4]  ; =0x0 (0)
11808728: str      r0, [sp, #0x78]
1180872c: ldr      r0, [sp]
11808730: add      r3, pc, #0x120
11808734: stm      r2, {r0, fp}
11808738: movne    r0, #4
1180873c: moveq    r0, #7
11808740: strb     r0, [sp, #0x168]
11808744: strb     r7, [sp, #8]
11808748: mov      r0, #1
1180874c: vstmia   r1, {s16, s17}
11808750: add      r2, pc, #0x17c
11808754: vstr     s16, [sp, #0x14]
11808758: strh     r0, [sp, #0x18]
1180875c: mov      r1, r6
11808760: add      r0, sp, #8
11808764: strh     r7, [sp, #0x1a]
11808768: str      r7, [sp, #0x1c]
1180876c: str      r7, [sp, #0x20]
11808770: bl       #0x118002b0  ; ->ad::lyt::LytAnim::init
11808774: vldr     s0, [pc, #0x168]  ; =0x40400000 (3)
11808778: add      r0, sp, #8
1180877c: bl       #0x118002c0  ; ->ad::lyt::LytAnim::stopAndSetFrm
11808780: mov      r1, #1
11808784: add      r0, sp, #8
11808788: bl       #0x118002c8  ; ->ad::lyt::LytAnim::term
1180878c: add      r3, pc, #0xc4
11808790: add      r2, pc, #0x150
11808794: mov      r1, r6
11808798: add      r0, sp, #8
1180879c: bl       #0x118002b0  ; ->ad::lyt::LytAnim::init
118087a0: vmov.f32 s0, s16
118087a4: add      r0, sp, #8
118087a8: bl       #0x118002c0  ; ->ad::lyt::LytAnim::stopAndSetFrm
118087ac: mov      r1, #1
118087b0: add      r0, sp, #8
118087b4: bl       #0x118002c8  ; ->ad::lyt::LytAnim::term
118087b8: add      r3, pc, #0x98
118087bc: add      r2, pc, #0x130
118087c0: mov      r1, r6
118087c4: add      r0, sp, #8
118087c8: bl       #0x118002b0  ; ->ad::lyt::LytAnim::init
118087cc: ldr      r0, [sp, #0x1c]
118087d0: add      r6, sp, #8
118087d4: bl       #0x118002b8  ; ->ad::lyt::AnimTransform::GetFrameSize
118087d8: vmov     s0, r0
118087dc: mov      r0, r6
118087e0: vcvt.f32.u32 s0, s0
118087e4: bl       #0x118002c0  ; ->ad::lyt::LytAnim::stopAndSetFrm
118087e8: mov      r1, #1
118087ec: add      r0, sp, #8
118087f0: bl       #0x118002c8  ; ->ad::lyt::LytAnim::term
118087f4: add      r0, r4, #0x14800
118087f8: vstr     s16, [sp, #0x14]
118087fc: add      r1, r8, #0x3c
11808800: add      r0, r0, #0x7c
11808804: strd     r0, r1, [sp]
11808808: add      r3, r4, #0xd0000
1180880c: add      r3, r3, #0x3100
11808810: add      r2, r4, #0xd3000
11808814: add      r1, sp, #0x28
11808818: mov      r0, r5
1180881c: bl       #0x11800388  ; ->msys::MListWndPBase::init
11808820: ldr      r0, [pc, #0xdc]  ; =0x401
11808824: str      r0, [r5, #0x13c]
11808828: str      r0, [r5, #0x168]
1180882c: add      sp, sp, #0x1a4
11808830: vpop     {d8}
11808834: pop      {r4, r5, r6, r7, r8, sb, sl, fp, pc}
11808838: eorseq   r6, pc, r8, lsr #5
1180883c: andeq    r1, r6, r3, lsl r0
11808840: stmdbmi  lr, {r0, r2, r3, r6, r8, fp, lr} ^
11808844: strbmi   r4, [sp, #-0x147]
11808848: mrrcmi   p12, #5, r4, pc, c15
1180884c: cdphs    p3, #5, c5, c4, c9, #2
11808850: stmdbvc  ip!, {r1, r5, r6, sb, sl, sp, lr} ^
11808854: andeq    r0, r0, r4, ror r0
11808858: andeq    r0, r0, r0
1180885c: cmnvs    r5, #116, #30
11808860: andeq    r0, r0, r8, rrx
11808864: ldrbmi   r5, [r4, #-0x441]
11808868: svcmi    #0x49544e
1180886c: andeq    r0, r0, lr, asr #32
11808870: svclo    #0x800000
11808874: svcpl    #0x4d554e
11808878: cdphs    p15, #7, c5, c3, c7, #2
1180887c: stmdbvc  ip!, {r1, r5, r6, sb, sl, sp, lr} ^
11808880: andeq    r0, r0, r4, ror r0
11808884: svcpl    #0x6d756e
11808888: svcpl    #0x746573
1180888c: andeq    r0, r0, r5, asr r0
11808890: svcpl    #0x6c6f63
11808894: eorseq   r3, r6, r3, ror r0
11808898: svcpl    #0x6c6f63
1180889c: andeq    r3, r0, r0, lsr r2
118088a0: .word    0xfffb50e8
118088a4: stclmi   p2, c5, [r1, #-0x118]
118088a8: andeq    r0, r0, r5, asr #32
118088ac: ldrbtvc  r6, [r3], #-0x96c
118088b0: rsbsvc   r6, r5, #0x7c000001
118088b4: svcpl    #0x726f73
118088b8: stmdbvs  ip!, {r0, r1, r6, r8, sb, sl, fp, sp, lr} ^
118088bc: ldclvs   p5, c6, [r5, #-0x1cc]!
118088c0: andeq    r0, r0, r0
118088c4: ldrbtvc  r6, [r3], #-0x96c
118088c8: rsbvc    r7, r3, #0x7c000001
118088cc: rsbeq    r6, ip, pc, ror #24
118088d0: andeq    r0, r0, r0
118088d4: svcpl    #0x544553
118088d8: ldrbpl   r4, [r3], #-0x94c
118088dc: mcrrmi   p3, #5, r4, pc, c15
118088e0: andeq    r0, r0, r0
118088e4: submi    r0, r0, r0
118088e8: cdpmi    p3, #4, c4, c15, c9, #2
118088ec: uqsaxvs  r6, r6, pc
118088f0: andeq    r6, r0, pc, ror #28
118088f4: svcpl    #0x544553
118088f8: cmppl    r2, #0x10c00000
118088fc: ldmdami  pc, {r0, r1, r2, r3, r6, sb, ip, lr} ^
11808900: andeq    r4, r0, sb, asr #24
11808904: andeq    r0, r0, r1, lsl #8
11808908: ldr      r1, [pc, #0x88]  ; =0x1180c958
1180890c: push     {r4, lr}
11808910: vldr     s0, [pc, #0x84]  ; =0x0 (0)
11808914: str      r1, [r0]
11808918: add      r1, r0, #0x7000
1180891c: add      r1, r1, #0x168
11808920: vstr     s0, [r1, #0xc]
11808924: add      r1, r0, #0x7000
11808928: add      r1, r1, #0x14c
1180892c: vstr     s0, [r1, #0xc]
11808930: add      r1, r0, #0x7000
11808934: add      r1, r1, #0x130
11808938: vstr     s0, [r1, #0xc]
1180893c: add      r1, r0, #0x7000
11808940: add      r1, r1, #0x114
11808944: vstr     s0, [r1, #0xc]
11808948: add      r1, r0, #0x7000
1180894c: add      r1, r1, #0xf8
11808950: vstr     s0, [r1, #0xc]
11808954: add      r1, r0, #0x7000
11808958: add      r1, r1, #0xdc
1180895c: add      r0, r0, #0x7000
11808960: vstr     s0, [r1, #0xc]
11808964: add      r0, r0, #0xa0
11808968: bl       #0x11800398  ; ->ad::lyt::Layout
1180896c: sub      r0, r0, #0x3c
11808970: bl       #0x11800398  ; ->ad::lyt::Layout
11808974: ldr      r1, [pc, #0x24]  ; =0x1180cb58
11808978: sub      r0, r0, #0x7000
1180897c: sub      r0, r0, #0x64
11808980: str      r1, [r0], #0x1fc
11808984: bl       #0x118003a0  ; ->ad::ui::UIListWindowPlusLyt
11808988: sub      r0, r0, #0x1fc
1180898c: bl       #0x118003a8  ; ->msys::MListWndPBase
11808990: pop      {r4, lr}
11808994: b        #0x11800190  ; ->_ZdlPv
11808998: orrne    ip, r0, r8, asr sb
1180899c: andeq    r0, r0, r0
118089a0: orrne    ip, r0, r8, asr fp
118089a4: ldr      r1, [pc, #0x84]  ; =0x1180c958
118089a8: push     {r4, lr}
118089ac: vldr     s0, [pc, #0x80]  ; =0x0 (0)
118089b0: str      r1, [r0]
118089b4: add      r1, r0, #0x7000
118089b8: add      r1, r1, #0x168
118089bc: vstr     s0, [r1, #0xc]
118089c0: add      r1, r0, #0x7000
118089c4: add      r1, r1, #0x14c
118089c8: vstr     s0, [r1, #0xc]
118089cc: add      r1, r0, #0x7000
118089d0: add      r1, r1, #0x130
118089d4: vstr     s0, [r1, #0xc]
118089d8: add      r1, r0, #0x7000
118089dc: add      r1, r1, #0x114
118089e0: vstr     s0, [r1, #0xc]
118089e4: add      r1, r0, #0x7000
118089e8: add      r1, r1, #0xf8
118089ec: vstr     s0, [r1, #0xc]
118089f0: add      r1, r0, #0x7000
118089f4: add      r1, r1, #0xdc
118089f8: add      r0, r0, #0x7000
118089fc: vstr     s0, [r1, #0xc]
11808a00: add      r0, r0, #0xa0
11808a04: bl       #0x11800398  ; ->ad::lyt::Layout
11808a08: sub      r0, r0, #0x3c
11808a0c: bl       #0x11800398  ; ->ad::lyt::Layout
11808a10: ldr      r1, [pc, #0x20]  ; =0x1180cb58
11808a14: sub      r0, r0, #0x7000
11808a18: sub      r0, r0, #0x64
11808a1c: str      r1, [r0], #0x1fc
11808a20: bl       #0x118003a0  ; ->ad::ui::UIListWindowPlusLyt
11808a24: pop      {r4, lr}
11808a28: sub      r0, r0, #0x1fc
11808a2c: b        #0x118003a8  ; ->msys::MListWndPBase
11808a30: orrne    ip, r0, r8, asr sb
11808a34: andeq    r0, r0, r0
11808a38: orrne    ip, r0, r8, asr fp
11808a3c: mov      r1, r0
11808a40: mov      r0, r3
11808a44: mov      r0, r0
11808a48: push     {r3, r4, r5, r6, r7, r8, sb, lr}
11808a4c: mov      r5, r0
11808a50: add      r4, r5, #0x13000
11808a54: cmp      r2, #1
11808a58: ldrb     r0, [r1, #0x48]
11808a5c: mov      sb, r1
11808a60: add      r4, r4, #0x304
11808a64: mov      r7, #0
11808a68: and      r6, r0, #0xff
11808a6c: beq      #0x11808b04
11808a70: cmp      r2, #4
11808a74: add      r8, r5, #0x61000
11808a78: beq      #0x11808ac4
11808a7c: cmp      r2, #5
11808a80: bne      #0x11808c30
11808a84: mov      r1, #0
11808a88: mov      r0, r4
11808a8c: bl       #0x118003f0  ; ->msys::MCursorBase::setVisible
11808a90: ldr      r2, [pc, #0x244]  ; =0x1180c000
11808a94: add      r0, r5, #0x10000
11808a98: cmp      r6, #7
11808a9c: add      r0, r0, #0x2a00
11808aa0: ldrlo    pc, [pc, r6, lsl #2]
11808aa4: b        #0x11808c30
11808aa8: orrne    r8, r0, r0, lsl ip
11808aac: orrne    r8, r0, r4, lsr ip
11808ab0: orrne    r8, r0, ip, ror #24
11808ab4: orrne    r8, r0, r8, asr ip
11808ab8: orrne    r8, r0, r0, lsl #25
11808abc: .word    0x11808c94
11808ac0: .word    0x11808c94
11808ac4: cmp      r6, #3
11808ac8: beq      #0x11808bec
11808acc: ldr      r1, [pc, #0x20c]  ; =0x110016
11808ad0: cmp      r6, #4
11808ad4: beq      #0x11808bac
11808ad8: cmp      r6, #5
11808adc: mov      r3, #0
11808ae0: cmpne    r6, #6
11808ae4: mov      r2, r3
11808ae8: str      r7, [sp]
11808aec: beq      #0x11808bd4
11808af0: mov      r0, r5
11808af4: bl       #0x11806814
11808af8: mov      r1, #0
11808afc: mov      r0, r5
11808b00: bl       #0x118068b4
11808b04: ldr      r0, [pc, #0x1d8]  ; =0x1331c
11808b08: ldrsb    r0, [r0, r5]
11808b0c: cmp      r0, r6
11808b10: beq      #0x11808c30
11808b14: cmp      r6, #0
11808b18: cmpne    r6, #1
11808b1c: bne      #0x11808c30
11808b20: mov      r3, #0
11808b24: ldr      r1, [pc, #0x1bc]  ; =0x110015
11808b28: mov      r2, r3
11808b2c: mov      r0, r5
11808b30: str      r7, [sp]
11808b34: bl       #0x11806814
11808b38: cmp      r6, #1
11808b3c: moveq    r0, #1
11808b40: movne    r0, #0
11808b44: vmov     s0, r0
11808b48: ldr      r0, [pc, #0x19c]  ; =0x60fb8
11808b4c: strb     r6, [r4, #0x18]
11808b50: add      r0, r0, r5
11808b54: vcvt.f32.u32 s0, s0
11808b58: bl       #0x118002c0  ; ->ad::lyt::LytAnim::stopAndSetFrm
11808b5c: cmp      r6, #1
11808b60: moveq    r0, #1
11808b64: movne    r0, #0
11808b68: vmov     s0, r0
11808b6c: ldr      r0, [pc, #0x17c]  ; =0xfff9f02c
11808b70: sub      r0, r5, r0
11808b74: vcvt.f32.u32 s0, s0
11808b78: bl       #0x118002c0  ; ->ad::lyt::LytAnim::stopAndSetFrm
11808b7c: ldrb     r0, [r4, #0x18]
11808b80: cmp      r0, #1
11808b84: movne    r0, #0
11808b88: add      r0, r0, r5
11808b8c: add      r0, r0, #0x61000
11808b90: ldrsb    r0, [r0, #0x14]
11808b94: vmov     s0, r0
11808b98: ldr      r0, [pc, #0x154]  ; =0x60f9c
11808b9c: add      r0, r0, r5
11808ba0: pop      {r3, r4, r5, r6, r7, r8, sb, lr}
11808ba4: vcvt.f32.s32 s0, s0
11808ba8: b        #0x118002c0  ; ->ad::lyt::LytAnim::stopAndSetFrm
11808bac: mov      r3, #0
11808bb0: mov      r2, r3
11808bb4: mov      r0, r5
11808bb8: str      r7, [sp]
11808bbc: bl       #0x11806814
11808bc0: ldrb     r0, [r4, #0x18]
11808bc4: cmp      r0, #0
11808bc8: movne    r0, #1
11808bcc: strb     r0, [r8, #0x13]
11808bd0: b        #0x11808af8
11808bd4: ldr      r1, [pc, #0x11c]  ; =0x11001c
11808bd8: mov      r0, r5
11808bdc: bl       #0x11806814
11808be0: nop      
11808be4: nop      
11808be8: b        #0x11808af8
11808bec: mov      r3, #0
11808bf0: ldr      r1, [pc, #0x104]  ; =0x110017
11808bf4: mov      r2, r3
11808bf8: mov      r0, r5
11808bfc: str      r7, [sp]
11808c00: bl       #0x11806814
11808c04: nop      
11808c08: nop      
11808c0c: b        #0x11808af8
11808c10: ldrb     r1, [r4, #0x18]
11808c14: add      r2, r2, #0x28
11808c18: add      r0, r0, #4
11808c1c: cmp      r1, #1
11808c20: movne    r1, #0
11808c24: strb     r1, [r8, #0x13]
11808c28: ldm      r2, {r1, r3}
11808c2c: stm      r0, {r1, r3}
11808c30: pop      {r3, r4, r5, r6, r7, r8, sb, pc}
11808c34: ldrb     r1, [r4, #0x18]
11808c38: add      r2, r2, #0x28
11808c3c: add      r0, r0, #4
11808c40: cmp      r1, #1
11808c44: movne    r1, #0
11808c48: strb     r1, [r8, #0x13]
11808c4c: ldm      r2, {r1, r2}
11808c50: stm      r0, {r1, r2}
11808c54: pop      {r3, r4, r5, r6, r7, r8, sb, pc}
11808c58: add      r1, r0, #0xc
11808c5c: add      r0, r0, #4
11808c60: ldm      r1, {r1, r2}
11808c64: stm      r0, {r1, r2}
11808c68: pop      {r3, r4, r5, r6, r7, r8, sb, pc}
11808c6c: add      r2, r2, #0x30
11808c70: add      r0, r0, #4
11808c74: ldm      r2, {r1, r2}
11808c78: stm      r0, {r1, r2}
11808c7c: pop      {r3, r4, r5, r6, r7, r8, sb, pc}
11808c80: add      r2, r2, #0x38
11808c84: add      r0, r0, #4
11808c88: ldm      r2, {r1, r2}
11808c8c: stm      r0, {r1, r2}
11808c90: pop      {r3, r4, r5, r6, r7, r8, sb, pc}
11808c94: ldr      r1, [pc, #0x64]  ; =0x13354
11808c98: ldr      r0, [pc, #0x64]  ; =0x60b04
11808c9c: ldr      r1, [r1, r5]
11808ca0: add      r0, r0, r5
11808ca4: cmp      r1, sb
11808ca8: mvneq    r1, #0
11808cac: movne    r1, #1
11808cb0: bl       #0x118023e8
11808cb4: ldr      r0, [r5, #8]
11808cb8: cmp      r0, #0
11808cbc: bne      #0x11808ccc
11808cc0: ldr      r0, [pc, #0x40]  ; =0x3f62a8 msys::MComSys::_sys
11808cc4: ldr      r0, [r0]
11808cc8: str      r0, [r5, #8]
11808ccc: add      r1, r0, #0xe6000
11808cd0: mov      r0, #1
11808cd4: strb     r0, [r1, #0x508]
11808cd8: pop      {r3, r4, r5, r6, r7, r8, sb, pc}
11808cdc: orrne    ip, r0, r0
11808ce0: andseq   r0, r1, r6, lsl r0
11808ce4: andeq    r3, r1, ip, lsl r3
11808ce8: andseq   r0, r1, r5, lsl r0
11808cec: strheq   r0, [r6], -r8
11808cf0: .word    0xfff9f02c
11808cf4: muleq    r6, ip, pc
11808cf8: andseq   r0, r1, ip, lsl r0
11808cfc: andseq   r0, r1, r7, lsl r0
11808d00: andeq    r3, r1, r4, asr r3
11808d04: andeq    r0, r6, r4, lsl #22
11808d08: eorseq   r6, pc, r8, lsr #5
11808d0c: push     {r4, r5, r6, r7, r8, sb, sl, fp, lr}
11808d10: mov      r4, r0
11808d14: vpush    {d8}
11808d18: sub      sp, sp, #0x6c
11808d1c: bl       #0x118005a8  ; ->ad::lyt::LytDrawSys::GetInst
11808d20: mov      r6, r0
11808d24: ldr      r0, [r4, #4]
11808d28: ldr      r5, [r0, #0x18]
11808d2c: ldr      r0, [pc, #0x2fc]  ; =0x3f634c ad::lyt::Layout::s_pAllocator
11808d30: ldr      r1, [r0]
11808d34: add      r0, r6, #0x400
11808d38: add      r0, r0, #0x1f4
11808d3c: cmp      r1, r0
11808d40: movne    r1, r0
11808d44: blne     #0x118005b0  ; ->ad::lyt::Initialize
11808d48: str      r5, [r6, #0x5f8]
11808d4c: bl       #0x118005a8  ; ->ad::lyt::LytDrawSys::GetInst
11808d50: mov      r1, r0
11808d54: mov      r0, #0x10000
11808d58: str      r0, [r1, #0x5fc]
11808d5c: ldr      r5, [pc, #0x2d0]  ; =0x3f62a8 msys::MComSys::_sys
11808d60: ldr      r0, [r4, #8]
11808d64: mov      sb, #0
11808d68: mov      r8, #0x7f
11808d6c: cmp      r0, #0
11808d70: ldreq    r0, [r5]
11808d74: mov      sl, sb
11808d78: mov      fp, sb
11808d7c: streq    r0, [r4, #8]
11808d80: ldr      r1, [r0, #4]
11808d84: cmp      r0, #0
11808d88: str      r1, [sp, #0x34]
11808d8c: add      r1, r4, #0x12800
11808d90: add      r1, r1, #0x2e8
11808d94: str      r1, [sp, #0x30]
11808d98: ldreq    r0, [r5]
11808d9c: add      r1, pc, #0x294
11808da0: mov      r6, r1
11808da4: streq    r0, [r4, #8]
11808da8: ldrne    r0, [r4, #8]
11808dac: ldr      r7, [r0, #0x278]
11808db0: ldr      r0, [r4, #4]
11808db4: vldr     s16, [r0, #0x18]
11808db8: ldr      r0, [r7, #0x24]
11808dbc: str      r0, [sp, #0x2c]
11808dc0: add      r0, sp, #0x38
11808dc4: bl       #0x118005b8  ; ->ad::TransMultiSymbol::init
11808dc8: add      r2, sp, #0x38
11808dcc: add      r1, sp, #0x2c
11808dd0: add      r0, sp, #8
11808dd4: bl       #0x118005c0  ; ->BinGlu4Acs::getEntryAcs
11808dd8: ldr      r0, [sp, #8]
11808ddc: ldr      r1, [r7, #0x24]
11808de0: ldr      r0, [r0]
11808de4: bic      r0, r0, #0xc0000000
11808de8: add      r0, r0, r1
11808dec: add      r1, r0, #8
11808df0: str      r1, [sp, #8]
11808df4: add      r2, r0, #0xc
11808df8: add      r3, r0, #4
11808dfc: add      r1, sp, #0x14
11808e00: str      r2, [sp, #0xc]
11808e04: str      r3, [sp, #4]
11808e08: stm      r1, {r8, sb, sl, fp}
11808e0c: mov      r3, r6
11808e10: mov      r2, r7
11808e14: vstr     s16, [sp, #0x10]
11808e18: str      r0, [sp]
11808e1c: ldr      r0, [sp, #0x34]
11808e20: ldr      r1, [sp, #0x30]
11808e24: bl       #0x118005c8  ; ->ad::fw::TaskBase::readCA
11808e28: ldr      r0, [r4, #8]
11808e2c: mov      sb, #0
11808e30: mov      r8, #0x7f
11808e34: cmp      r0, #0
11808e38: ldreq    r0, [r5]
11808e3c: mov      sl, sb
11808e40: mov      fp, sb
11808e44: streq    r0, [r4, #8]
11808e48: ldr      r1, [r0, #4]
11808e4c: cmp      r0, #0
11808e50: str      r1, [sp, #0x5c]
11808e54: add      r1, r4, #0x12800
11808e58: add      r1, r1, #0x32c
11808e5c: str      r1, [sp, #0x58]
11808e60: ldreq    r0, [r5]
11808e64: add      r1, pc, #0x1d8
11808e68: mov      r6, r1
11808e6c: streq    r0, [r4, #8]
11808e70: ldrne    r0, [r4, #8]
11808e74: ldr      r7, [r0, #0x278]
11808e78: ldr      r0, [r4, #4]
11808e7c: vldr     s16, [r0, #0x18]
11808e80: ldr      r0, [r7, #0x24]
11808e84: str      r0, [sp, #0x60]
11808e88: add      r0, sp, #0x28
11808e8c: bl       #0x118005b8  ; ->ad::TransMultiSymbol::init
11808e90: add      r2, sp, #0x28
11808e94: add      r1, sp, #0x60
11808e98: add      r0, sp, #8
11808e9c: bl       #0x118005c0  ; ->BinGlu4Acs::getEntryAcs
11808ea0: ldr      r0, [sp, #8]
11808ea4: ldr      r1, [r7, #0x24]
11808ea8: ldr      r0, [r0]
11808eac: bic      r0, r0, #0xc0000000
11808eb0: add      r0, r0, r1
11808eb4: add      r1, r0, #8
11808eb8: str      r1, [sp, #8]
11808ebc: add      r2, r0, #0xc
11808ec0: add      r3, r0, #4
11808ec4: add      r1, sp, #0x14
11808ec8: str      r2, [sp, #0xc]
11808ecc: str      r3, [sp, #4]
11808ed0: stm      r1, {r8, sb, sl, fp}
11808ed4: mov      r3, r6
11808ed8: mov      r2, r7
11808edc: vstr     s16, [sp, #0x10]
11808ee0: str      r0, [sp]
11808ee4: ldr      r0, [sp, #0x5c]
11808ee8: ldr      r1, [sp, #0x58]
11808eec: bl       #0x118005c8  ; ->ad::fw::TaskBase::readCA
11808ef0: ldr      r0, [r4, #8]
11808ef4: mov      sb, #0
11808ef8: mov      r8, #0x7f
11808efc: cmp      r0, #0
11808f00: ldreq    r0, [r5]
11808f04: mov      sl, sb
11808f08: mov      fp, sb
11808f0c: streq    r0, [r4, #8]
11808f10: ldr      r1, [r0, #4]
11808f14: cmp      r0, #0
11808f18: str      r1, [sp, #0x5c]
11808f1c: add      r1, r4, #0x12000
11808f20: add      r1, r1, #0xb70
11808f24: str      r1, [sp, #0x58]
11808f28: ldreq    r0, [r5]
11808f2c: add      r1, pc, #0x120
11808f30: mov      r6, r1
11808f34: streq    r0, [r4, #8]
11808f38: ldrne    r0, [r4, #8]
11808f3c: ldr      r7, [r0, #0x278]
11808f40: ldr      r0, [r4, #4]
11808f44: vldr     s16, [r0, #0x18]
11808f48: ldr      r0, [r7, #0x24]
11808f4c: str      r0, [sp, #0x60]
11808f50: add      r0, sp, #0x2c
11808f54: bl       #0x118005b8  ; ->ad::TransMultiSymbol::init
11808f58: add      r2, sp, #0x2c
11808f5c: add      r1, sp, #0x60
11808f60: add      r0, sp, #8
11808f64: bl       #0x118005c0  ; ->BinGlu4Acs::getEntryAcs
11808f68: ldr      r0, [sp, #8]
11808f6c: ldr      r1, [r7, #0x24]
11808f70: ldr      r0, [r0]
11808f74: bic      r0, r0, #0xc0000000
11808f78: add      r0, r0, r1
11808f7c: add      r1, r0, #8
11808f80: str      r1, [sp, #8]
11808f84: add      r2, r0, #0xc
11808f88: add      r3, r0, #4
11808f8c: add      r1, sp, #0x14
11808f90: str      r2, [sp, #0xc]
11808f94: str      r3, [sp, #4]
11808f98: stm      r1, {r8, sb, sl, fp}
11808f9c: mov      r3, r6
11808fa0: mov      r2, r7
11808fa4: vstr     s16, [sp, #0x10]
11808fa8: str      r0, [sp]
11808fac: ldr      r0, [sp, #0x5c]
11808fb0: ldr      r1, [sp, #0x58]
11808fb4: bl       #0x118005c8  ; ->ad::fw::TaskBase::readCA
11808fb8: ldr      r0, [r4, #4]
11808fbc: mov      r3, #0x7f
11808fc0: ldr      r1, [r0, #0x18]
11808fc4: ldr      r0, [r4, #8]
11808fc8: cmp      r0, #0
11808fcc: ldreq    r0, [r5]
11808fd0: streq    r0, [r4, #8]
11808fd4: cmp      r0, #0
11808fd8: ldreq    r2, [r5]
11808fdc: streq    r2, [r4, #8]
11808fe0: movne    r2, r0
11808fe4: ldr      ip, [r2, #4]
11808fe8: mov      r2, #0
11808fec: str      r2, [sp, #8]
11808ff0: stm      sp, {r1, r3}
11808ff4: ldr      r0, [r0, #0x278]
11808ff8: add      r1, r4, #0x12800
11808ffc: add      r3, pc, #0x5c
11809000: add      r2, r0, #0xa8
11809004: add      r1, r1, #0x2a4
11809008: mov      r0, ip
1180900c: bl       #0x118005d0  ; ->ad::fw::TaskBase::readLyt
11809010: ldr      r1, [pc, #0x54]  ; =0x1180c000
11809014: add      r2, r4, #0x12800
11809018: add      r2, r2, #0x1fc
1180901c: ldrd     r0, r1, [r1, #0x40]
11809020: strd     r0, r1, [r2]
11809024: add      sp, sp, #0x6c
11809028: vpop     {d8}
1180902c: pop      {r4, r5, r6, r7, r8, sb, sl, fp, pc}
11809030: eorseq   r6, pc, ip, asr #6
11809034: eorseq   r6, pc, r8, lsr #5
11809038: strbtvc  r5, [sb], #-0xf6d
1180903c: subsvs   r6, pc, #0x1940
11809040: andeq    r6, r0, r2, ror r1
11809044: svcvs    #0x625f6d
11809048: svcvs    #0x727964
1180904c: .word    0x63695f74
11809050: andeq    r6, r0, pc, ror #28
11809054: subsvs   r6, pc, #0xfc0
11809058: rsbsvc   r6, sb, #0x6f000000
1180905c: andeq    r7, r0, pc, ror #8
11809060: mcrrmi   p3, #3, r4, pc, c15
11809064: strbpl   r5, [r5, #-0x349]
11809068: andeq    r0, r0, sp, asr #32
1180906c: orrne    ip, r0, r0
11809070: bx       lr
11809074: push     {r4, r5, r6, r7, r8, lr}
11809078: mov      r4, #0
1180907c: ldr      r2, [pc, #0x678]  ; =0x1180c99c
11809080: vpush    {d8}
11809084: str      r2, [r0], #4
11809088: stm      r0, {r1, r4}
1180908c: add      r0, r0, #0xc
11809090: bl       #0x118005d8  ; ->Backup
11809094: add      r0, r0, #0x12800
11809098: add      r0, r0, #0x204
1180909c: bl       #0x118005e0  ; ->ad::ctrl::ButtonGroup
118090a0: str      r4, [r0, #0x1c]!
118090a4: add      r0, r0, #4
118090a8: bl       #0x118005e8  ; ->ad::font::ResFont
118090ac: sub      r5, r0, #4
118090b0: mov      r0, r5
118090b4: bl       #0x118001d8  ; ->ad::lyt::LytResourceMan::init
118090b8: add      r0, r5, #0x74
118090bc: bl       #0x118005f0  ; ->ad::fw::Resource
118090c0: add      r0, r0, #0x44
118090c4: bl       #0x118005f0  ; ->ad::fw::Resource
118090c8: ldr      r1, [pc, #0x630]  ; =0x250588 ad::fw::Resource
118090cc: mov      r3, #2
118090d0: mov      r2, #0x44
118090d4: add      r0, r0, #0x44
118090d8: bl       #0x11800518  ; ->__aeabi_vec_ctor_nocookie_nodtor
118090dc: add      r0, r0, #0x88
118090e0: bl       #0x118058e4
118090e4: ldr      r8, [pc, #0x618]  ; =0x3e4580
118090e8: add      r1, r0, #0x100
118090ec: mvn      r6, #0
118090f0: str      r8, [r0], #0x14c
118090f4: mov      r3, #0xc
118090f8: strb     r6, [r0], #4
118090fc: strh     r4, [r1, #0x4e]
11809100: ldr      r1, [pc, #0x600]  ; =0x1180588c
11809104: mov      r2, #0x1c
11809108: str      r4, [r0], #4
1180910c: bl       #0x11800518  ; ->__aeabi_vec_ctor_nocookie_nodtor
11809110: ldr      r1, [pc, #0x5f4]  ; =0x118012ac
11809114: mov      r3, #0xc
11809118: mov      r2, #0x10
1180911c: add      r0, r0, #0x15c
11809120: bl       #0x11800518  ; ->__aeabi_vec_ctor_nocookie_nodtor
11809124: mov      r7, #1
11809128: str      r4, [r0, #0xc0]
1180912c: sub      r5, r0, #0x2b0
11809130: strb     r7, [r0, #0xc4]
11809134: str      r4, [r5, #0x378]
11809138: str      r4, [r5, #0x37c]
1180913c: strb     r4, [r5, #0x380]
11809140: str      r4, [r5, #0x384]
11809144: sub      r0, r0, #0xc
11809148: mov      r1, r6
1180914c: str      r4, [r5, #0x388]
11809150: bl       #0x118058c8
11809154: add      r0, r5, #0x3a8
11809158: bl       #0x118058e4
1180915c: add      r1, r0, #0x100
11809160: str      r8, [r0], #0x14c
11809164: mov      r3, #0xc
11809168: strb     r6, [r0], #4
1180916c: strh     r4, [r1, #0x4e]
11809170: ldr      r1, [pc, #0x590]  ; =0x1180588c
11809174: mov      r2, #0x1c
11809178: str      r4, [r0], #4
1180917c: bl       #0x11800518  ; ->__aeabi_vec_ctor_nocookie_nodtor
11809180: ldr      r1, [pc, #0x584]  ; =0x118012ac
11809184: mov      r3, #0xc
11809188: mov      r2, #0x10
1180918c: add      r0, r0, #0x15c
11809190: bl       #0x11800518  ; ->__aeabi_vec_ctor_nocookie_nodtor
11809194: sub      r5, r0, #0x2b0
11809198: str      r4, [r0, #0xc0]
1180919c: strb     r7, [r5, #0x374]
118091a0: str      r4, [r5, #0x378]
118091a4: str      r4, [r5, #0x37c]
118091a8: strb     r4, [r5, #0x380]
118091ac: str      r4, [r5, #0x384]
118091b0: mov      r1, r6
118091b4: sub      r0, r0, #0xc
118091b8: str      r4, [r5, #0x388]
118091bc: bl       #0x118058c8
118091c0: add      r0, r5, #0x3a8
118091c4: bl       #0x118005f8  ; ->msys::MCursorBase
118091c8: ldr      r1, [pc, #0x540]  ; =0x1180cabc
118091cc: mov      r3, #2
118091d0: mov      r2, #0x27c
118091d4: str      r1, [r0], #0x30
118091d8: ldr      r1, [pc, #0x534]  ; =0x1180b57c
118091dc: str      r4, [r0], #4
118091e0: str      r4, [r0], #4
118091e4: str      r4, [r0], #0x20
118091e8: bl       #0x11800518  ; ->__aeabi_vec_ctor_nocookie_nodtor
118091ec: add      r0, r0, #0x400
118091f0: add      r0, r0, #0xf8
118091f4: bl       #0x118058e4
118091f8: ldr      r6, [pc, #0x518]  ; =0x3e45c4
118091fc: str      r6, [r0], #0x14c
11809200: bl       #0x11800600  ; ->MessageSimple
11809204: sub      r1, r0, #0x14c
11809208: add      r0, r0, #0x5c00
1180920c: add      r0, r0, #0x2b4
11809210: mov      r5, #0x400
11809214: str      r4, [r0, #0xc2c]
11809218: strb     r4, [r0, #0xc30]
1180921c: strb     r4, [r0, #0xc31]
11809220: str      r4, [r0, #0xc34]
11809224: str      r4, [r0, #0xc38]!
11809228: str      r5, [r0, #8]
1180922c: add      r0, r1, #0x6c00
11809230: add      r0, r0, #0x44
11809234: bl       #0x118058e4
11809238: str      r6, [r0], #0x14c
1180923c: bl       #0x11800600  ; ->MessageSimple
11809240: add      r1, r0, #0x5c00
11809244: add      r1, r1, #0x2b4
11809248: add      r0, r0, #0x6800
1180924c: str      r4, [r1, #0xc2c]
11809250: strb     r4, [r1, #0xc30]
11809254: strb     r4, [r1, #0xc31]
11809258: str      r4, [r1, #0xc34]
1180925c: str      r4, [r1, #0xc38]!
11809260: add      r0, r0, #0x2f8
11809264: str      r5, [r1, #8]
11809268: bl       #0x118058e4
1180926c: str      r6, [r0], #0x14c
11809270: bl       #0x11800600  ; ->MessageSimple
11809274: sub      r1, r0, #0x14c
11809278: add      r0, r0, #0x5c00
1180927c: add      r0, r0, #0x2b4
11809280: str      r4, [r0, #0xc2c]
11809284: strb     r4, [r0, #0xc30]
11809288: strb     r4, [r0, #0xc31]
1180928c: str      r4, [r0, #0xc34]
11809290: str      r4, [r0, #0xc38]!
11809294: str      r5, [r0, #8]
11809298: add      r0, r1, #0x6c00
1180929c: add      r0, r0, #0x44
118092a0: bl       #0x118058e4
118092a4: str      r6, [r0], #0x14c
118092a8: bl       #0x11800600  ; ->MessageSimple
118092ac: sub      r1, r0, #0x14c
118092b0: add      r0, r0, #0x5c00
118092b4: add      r0, r0, #0x2b4
118092b8: str      r4, [r0, #0xc2c]
118092bc: strb     r4, [r0, #0xc30]
118092c0: strb     r4, [r0, #0xc31]
118092c4: str      r4, [r0, #0xc34]
118092c8: str      r4, [r0, #0xc38]!
118092cc: str      r5, [r0, #8]
118092d0: add      r0, r1, #0x6c00
118092d4: add      r0, r0, #0x44
118092d8: bl       #0x118058e4
118092dc: str      r6, [r0], #0x14c
118092e0: bl       #0x11800600  ; ->MessageSimple
118092e4: sub      r1, r0, #0x14c
118092e8: add      r0, r0, #0x5c00
118092ec: add      r0, r0, #0x2b4
118092f0: str      r4, [r0, #0xc2c]
118092f4: strb     r4, [r0, #0xc30]
118092f8: strb     r4, [r0, #0xc31]
118092fc: str      r4, [r0, #0xc34]
11809300: str      r4, [r0, #0xc38]!
11809304: str      r5, [r0, #8]
11809308: add      r0, r1, #0x6c00
1180930c: add      r0, r0, #0x44
11809310: bl       #0x11800608  ; ->msys::MLytNum
11809314: add      r0, r0, #0x230
11809318: bl       #0x11800608  ; ->msys::MLytNum
1180931c: ldr      r1, [pc, #0x3f8]  ; =0x33137c msys::MDfxChr
11809320: mov      r3, #6
11809324: mov      r2, #0x17c
11809328: add      r0, r0, #0x230
1180932c: bl       #0x11800518  ; ->__aeabi_vec_ctor_nocookie_nodtor
11809330: add      r0, r0, #0x800
11809334: add      r0, r0, #0xe8
11809338: bl       #0x11800610  ; ->msys::MDfxChr
1180933c: ldr      r1, [pc, #0x3d8]  ; =0x33137c msys::MDfxChr
11809340: mov      r3, #4
11809344: mov      r2, #0x17c
11809348: add      r0, r0, #0x17c
1180934c: bl       #0x11800518  ; ->__aeabi_vec_ctor_nocookie_nodtor
11809350: add      r0, r0, #0x5f0
11809354: bl       #0x11800610  ; ->msys::MDfxChr
11809358: add      r0, r0, #0x17c
1180935c: bl       #0x11800610  ; ->msys::MDfxChr
11809360: add      r0, r0, #0x17c
11809364: bl       #0x11800610  ; ->msys::MDfxChr
11809368: add      r0, r0, #0x17c
1180936c: bl       #0x11800610  ; ->msys::MDfxChr
11809370: add      r0, r0, #0x17c
11809374: bl       #0x118058e4
11809378: ldr      r1, [pc, #0x3a0]  ; =0x3e4730
1180937c: str      r1, [r0], #0x14c
11809380: bl       #0x11800618  ; ->Message
11809384: add      ip, r0, #0x6000
11809388: add      ip, ip, #0xd60
1180938c: vldr     s16, [pc, #0x390]  ; =0x0 (0)
11809390: strd     r4, r5, [ip]
11809394: vstr     s16, [ip, #8]
11809398: vstr     s16, [ip, #0xc]
1180939c: mov      r3, #6
118093a0: vstr     s16, [ip, #0x10]
118093a4: str      r3, [ip, #0x18]
118093a8: str      r4, [ip, #0x14]
118093ac: vstr     s16, [ip, #0x1c]
118093b0: strb     r4, [ip, #0x20]
118093b4: str      r4, [ip, #0x24]
118093b8: str      r4, [ip, #0x28]
118093bc: strb     r7, [ip, #0x2c]
118093c0: strb     r4, [ip, #0x2d]
118093c4: strb     r4, [ip, #0x2e]
118093c8: ldr      r1, [pc, #0x358]  ; =0x110003
118093cc: str      r4, [ip, #0x30]
118093d0: add      ip, r0, #0x6c00
118093d4: add      ip, ip, #0x194
118093d8: add      r2, r1, #1
118093dc: stm      ip, {r1, r2}
118093e0: add      ip, r0, #0x6000
118093e4: add      ip, ip, #0xda0
118093e8: str      r4, [ip], #4
118093ec: stm      ip, {r4, r5}
118093f0: ldr      ip, [pc, #0x334]  ; =0x1180c914
118093f4: str      ip, [r0, #-0x14c]
118093f8: add      ip, r0, #0x6c00
118093fc: add      ip, ip, #0x1ac
11809400: strd     r4, r5, [ip]
11809404: vstr     s16, [ip, #8]
11809408: vstr     s16, [ip, #0xc]
1180940c: vstr     s16, [ip, #0x10]
11809410: str      r3, [ip, #0x18]
11809414: str      r4, [ip, #0x14]
11809418: vstr     s16, [ip, #0x1c]
1180941c: strb     r4, [ip, #0x20]
11809420: str      r4, [ip, #0x24]
11809424: str      r4, [ip, #0x28]
11809428: strb     r7, [ip, #0x2c]
1180942c: strb     r4, [ip, #0x2d]
11809430: strb     r4, [ip, #0x2e]
11809434: str      r4, [ip, #0x30]
11809438: add      ip, r0, #0x6000
1180943c: add      ip, ip, #0xde0
11809440: stm      ip, {r1, r2}
11809444: add      r1, r0, #0x6c00
11809448: add      r0, r0, #0x6c00
1180944c: add      r1, r1, #0x3e8
11809450: add      r0, r0, #0x1ec
11809454: bl       #0x11800620  ; ->msys::MListWndPBase
11809458: ldr      r1, [pc, #0x2d0]  ; =0x1180cb58
1180945c: str      r1, [r0], #0x1fc
11809460: bl       #0x11800628  ; ->ad::ui::UIListWindowPlusLyt
11809464: ldr      r8, [pc, #0x2c8]  ; =0x1180ca64
11809468: ldr      r1, [pc, #0x2c8]  ; =0x1180c958
1180946c: str      r8, [r0]
11809470: str      r1, [r0, #-0x1fc]
11809474: sub      r0, r0, #0x198
11809478: add      r0, r0, #0x7000
1180947c: bl       #0x11800630  ; ->ad::lyt::Layout
11809480: add      r0, r0, #0x3c
11809484: bl       #0x11800630  ; ->ad::lyt::Layout
11809488: add      r0, r0, #0x3c
1180948c: bl       #0x1180588c
11809490: add      r0, r0, #0x1c
11809494: bl       #0x1180588c
11809498: add      r0, r0, #0x1c
1180949c: bl       #0x1180588c
118094a0: add      r0, r0, #0x1c
118094a4: bl       #0x1180588c
118094a8: add      r0, r0, #0x1c
118094ac: bl       #0x1180588c
118094b0: add      r0, r0, #0x1c
118094b4: bl       #0x1180588c
118094b8: add      r1, r0, #0x220
118094bc: add      r0, r0, #0x24
118094c0: bl       #0x11800620  ; ->msys::MListWndPBase
118094c4: ldr      r1, [pc, #0x270]  ; =0x1180cb14
118094c8: str      r1, [r0], #0x1fc
118094cc: bl       #0x11800628  ; ->ad::ui::UIListWindowPlusLyt
118094d0: ldr      r1, [pc, #0x268]  ; =0x1180c8d0
118094d4: str      r8, [r0], #-0x1fc
118094d8: str      r1, [r0], #-0xc
118094dc: add      r0, r0, #0x7000
118094e0: bl       #0x11800630  ; ->ad::lyt::Layout
118094e4: add      r0, r0, #0x3c
118094e8: bl       #0x1180588c
118094ec: add      r0, r0, #0x1c
118094f0: bl       #0x1180588c
118094f4: add      r0, r0, #0x1c
118094f8: bl       #0x1180588c
118094fc: add      r0, r0, #0x20
11809500: bl       #0x11800608  ; ->msys::MLytNum
11809504: add      r0, r0, #0x230
11809508: bl       #0x11800608  ; ->msys::MLytNum
1180950c: add      r0, r0, #0x230
11809510: bl       #0x1180588c
11809514: add      r0, r0, #0x1c
11809518: bl       #0x1180588c
1180951c: add      r0, r0, #0x1c
11809520: bl       #0x118058e4
11809524: str      r6, [r0], #0x14c
11809528: bl       #0x11800600  ; ->MessageSimple
1180952c: sub      r1, r0, #0x14c
11809530: add      r0, r0, #0x5c00
11809534: add      r0, r0, #0x2b4
11809538: str      r4, [r0, #0xc2c]
1180953c: strb     r4, [r0, #0xc30]
11809540: strb     r4, [r0, #0xc31]
11809544: str      r4, [r0, #0xc34]
11809548: str      r4, [r0, #0xc38]!
1180954c: str      r5, [r0, #8]
11809550: add      r0, r1, #0x6c00
11809554: add      r0, r0, #0x44
11809558: bl       #0x118058e4
1180955c: str      r6, [r0], #0x14c
11809560: bl       #0x11800600  ; ->MessageSimple
11809564: sub      r1, r0, #0x14c
11809568: add      r0, r0, #0x5c00
1180956c: add      r0, r0, #0x2b4
11809570: str      r4, [r0, #0xc2c]
11809574: strb     r4, [r0, #0xc30]
11809578: strb     r4, [r0, #0xc31]
1180957c: str      r4, [r0, #0xc34]
11809580: str      r4, [r0, #0xc38]!
11809584: str      r5, [r0, #8]
11809588: add      r0, r1, #0x6c00
1180958c: add      r0, r0, #0x44
11809590: bl       #0x118058e4
11809594: str      r6, [r0], #0x14c
11809598: bl       #0x11800600  ; ->MessageSimple
1180959c: sub      r1, r0, #0x14c
118095a0: add      r0, r0, #0x5c00
118095a4: add      r0, r0, #0x2b4
118095a8: str      r4, [r0, #0xc2c]
118095ac: strb     r4, [r0, #0xc30]
118095b0: strb     r4, [r0, #0xc31]
118095b4: str      r4, [r0, #0xc34]
118095b8: str      r4, [r0, #0xc38]!
118095bc: str      r5, [r0, #8]
118095c0: sub      r0, r1, #0xdc00
118095c4: ldr      r1, [pc, #0x178]  ; =0x60b04
118095c8: sub      r0, r0, #0x124
118095cc: sub      r0, r0, #0x4c000
118095d0: sub      r0, r0, #0x194
118095d4: add      r0, r0, r1
118095d8: str      r4, [r0, #0x20]
118095dc: str      r4, [r0, #0x24]!
118095e0: add      r0, r0, #4
118095e4: bl       #0x11800608  ; ->msys::MLytNum
118095e8: add      r0, r0, #0x230
118095ec: bl       #0x11800608  ; ->msys::MLytNum
118095f0: ldr      r2, [pc, #0x150]  ; =0xfff9f4fc
118095f4: ldr      r1, [pc, #0x150]  ; =0x60f9c
118095f8: sub      r0, r0, #0x258
118095fc: add      r0, r0, r2
11809600: add      r0, r0, r1
11809604: bl       #0x1180588c
11809608: ldr      r2, [pc, #0x140]  ; =0xfff9f064
1180960c: ldr      r1, [pc, #0x140]  ; =0x60fb8
11809610: add      r0, r0, r2
11809614: add      r0, r0, r1
11809618: bl       #0x1180588c
1180961c: ldr      r1, [pc, #0x134]  ; =0xfff9f048
11809620: sub      r5, r1, #0x1c
11809624: add      r0, r0, r1
11809628: sub      r0, r0, r5
1180962c: bl       #0x1180588c
11809630: add      r0, r0, r5
11809634: rsb      r1, r5, r7, lsl #5
11809638: vldr     s0, [pc, #0x11c]  ; =0x3f800000 (1)
1180963c: str      r4, [r1, r0]
11809640: orr      r1, r1, r1, asr #14
11809644: add      r0, r0, r1
11809648: sub      r1, r4, r1
1180964c: vstr     s16, [r0]
11809650: vstr     s0, [r0, #4]
11809654: vstr     s16, [r0, #8]
11809658: strh     r7, [r0, #0xc]
1180965c: add      r6, r0, r1
11809660: strh     r4, [r0, #0xe]
11809664: bl       #0x11800410  ; ->col::GetBootInfo
11809668: ldrb     r0, [r0, #0x20c]
1180966c: add      r5, r6, #0x61000
11809670: strb     r0, [r5, #0x13]
11809674: mov      r0, r6
11809678: bl       #0x11806cf0
1180967c: ldr      r1, [pc, #0xdc]  ; =0x3f95f0 gGameWork
11809680: ldr      r0, [pc, #0xd8]  ; =0x3f95f0 gGameWork
11809684: ldr      r1, [r1, #0x43c]
11809688: ldr      r0, [r0, #0x3f0]
1180968c: lsl      r1, r1, #0xe
11809690: lsl      r0, r0, #7
11809694: lsr      r1, r1, #0x1f
11809698: lsr      r0, r0, #0x1f
1180969c: orr      r1, r0, r1, lsl #1
118096a0: ldr      r0, [pc, #0xb8]  ; =0x3f95f0 gGameWork
118096a4: ldrb     r0, [r0, #0x440]
118096a8: lsl      r0, r0, #0x18
118096ac: lsr      r0, r0, #0x1f
118096b0: orr      r1, r1, r0, lsl #2
118096b4: ldr      r0, [pc, #0xa4]  ; =0x3f95f0 gGameWork
118096b8: ldr      r0, [r0, #0x414]
118096bc: lsl      r0, r0, #9
118096c0: lsr      r0, r0, #0x1f
118096c4: orr      r1, r1, r0, lsl #3
118096c8: ldr      r0, [pc, #0x94]  ; =0x3f9de0
118096cc: strb     r1, [r5, #0xd]
118096d0: mov      r1, #0
118096d4: strb     r7, [r5, #0x14]
118096d8: add      r2, r0, r1, lsl #1
118096dc: ldrsh    r2, [r2]
118096e0: cmp      r2, #0
118096e4: blt      #0x118096f4
118096e8: ldrb     r2, [r5, #0xc]
118096ec: tst      r2, r7, lsl r1
118096f0: bne      #0x11809768
118096f4: strb     r4, [r5, #0x14]
118096f8: b        #0x11809778
118096fc: .word    0x1180c99c
11809700: eoreq    r0, r5, r8, lsl #11
11809704: eorseq   r4, lr, r0, lsl #11
11809708: orrne    r5, r0, ip, lsl #17
1180970c: orrne    r1, r0, ip, lsr #5
11809710: strhne   ip, [r0, ip]
11809714: orrne    fp, r0, ip, ror r5
11809718: eorseq   r4, lr, r4, asr #11
1180971c: eorseq   r1, r3, ip, ror r3
11809720: eorseq   r4, lr, r0, lsr r7
11809724: andeq    r0, r0, r0
11809728: andseq   r0, r1, r3
1180972c: orrne    ip, r0, r4, lsl sb
11809730: orrne    ip, r0, r8, asr fp
11809734: orrne    ip, r0, r4, ror #20
11809738: orrne    ip, r0, r8, asr sb
1180973c: orrne    ip, r0, r4, lsl fp
11809740: ldrdne   ip, sp, [r0, r0]
11809744: andeq    r0, r6, r4, lsl #22
11809748: .word    0xfff9f4fc
1180974c: muleq    r6, ip, pc
11809750: .word    0xfff9f064
11809754: strheq   r0, [r6], -r8
11809758: .word    0xfff9f048
1180975c: svclo    #0x800000
11809760: ldrshteq sb, [pc], -r0
11809764: eorseq   sb, pc, r0, ror #27
11809768: add      r1, r1, #1
1180976c: and      r1, r1, #0xff
11809770: cmp      r1, #7
11809774: blo      #0x118096d8
11809778: ldr      r2, [pc, #0x58]  ; =0x3f9df4
1180977c: mov      r1, #0
11809780: strb     r7, [r5, #0x15]
11809784: add      r0, r2, r1, lsl #1
11809788: ldrsh    r0, [r0]
1180978c: cmp      r0, #0
11809790: blt      #0x118097a0
11809794: ldrb     r0, [r5, #0xd]
11809798: tst      r0, r7, lsl r1
1180979c: bne      #0x118097a8
118097a0: strb     r4, [r5, #0x15]
118097a4: b        #0x118097b8
118097a8: add      r0, r1, #1
118097ac: and      r1, r0, #0xff
118097b0: cmp      r1, #4
118097b4: blo      #0x11809784
118097b8: ldr      r1, [pc, #0x1c]  ; =0x1180c000
118097bc: add      r2, r6, #0x12800
118097c0: add      r2, r2, #0x1fc
118097c4: ldrd     r0, r1, [r1, #0x20]
118097c8: strd     r0, r1, [r2]
118097cc: mov      r0, r6
118097d0: vpop     {d8}
118097d4: pop      {r4, r5, r6, r7, r8, pc}
118097d8: ldrshteq sb, [pc], -r4
118097dc: orrne    ip, r0, r0
118097e0: push     {r4, lr}
118097e4: bl       #0x118097f0
118097e8: pop      {r4, lr}
118097ec: b        #0x11800190  ; ->_ZdlPv
118097f0: push     {r4, r5, r6, lr}
118097f4: mov      r4, r0
118097f8: ldr      r0, [pc, #0x428]  ; =0x1180c99c
118097fc: vpush    {d8}
11809800: str      r0, [r4]
11809804: add      r0, r4, #0x13000
11809808: add      r0, r0, #0x304
1180980c: bl       #0x11800638  ; ->msys::MCursorBase::term
11809810: add      r0, r4, #0x12800
11809814: add      r0, r0, #0x3b4
11809818: bl       #0x118004e8  ; ->msys::MLyt::term
1180981c: add      r0, r4, #0x12c00
11809820: add      r0, r0, #0x35c
11809824: bl       #0x118004e8  ; ->msys::MLyt::term
11809828: add      r0, r4, #0x12800
1180982c: add      r0, r0, #0x214
11809830: bl       #0x11800640  ; ->ad::ctrl::ButtonGroup::FreeAll
11809834: add      r0, r4, #0x12800
11809838: add      r0, r0, #0x2a4
1180983c: bl       #0x118004f0  ; ->ad::fw::Resource::term
11809840: add      r0, r4, #0x12000
11809844: add      r0, r0, #0xa30
11809848: bl       #0x11800648  ; ->ad::lyt::LytResourceMan::term
1180984c: ldr      r0, [pc, #0x3d8]  ; =0x60ffc
11809850: ldr      r1, [pc, #0x3dc]  ; =0xfff9f02c
11809854: vldr     s16, [pc, #0x3d4]  ; =0x0 (0)
11809858: add      r0, r0, r4
1180985c: vstr     s16, [r0, #8]
11809860: sub      r0, r4, r1
11809864: vstr     s16, [r0, #0xc]
11809868: add      r0, r0, r1
1180986c: ldr      r1, [pc, #0x3c4]  ; =0x60fb8
11809870: add      r0, r0, r1
11809874: rsb      r1, r1, r1, asr #19
11809878: vstr     s16, [r0, #0xc]
1180987c: add      r0, r0, r1
11809880: ldr      r1, [pc, #0x3b4]  ; =0x60f9c
11809884: add      r0, r0, r1
11809888: rsb      r1, r1, r1, asr #19
1180988c: vstr     s16, [r0, #0xc]
11809890: add      r0, r0, r1
11809894: ldr      r1, [pc, #0x3a4]  ; =0x60b04
11809898: add      r0, r0, r1
1180989c: add      r0, r0, #0x258
118098a0: bl       #0x11800650  ; ->msys::MLytNum
118098a4: sub      r0, r0, #0x230
118098a8: bl       #0x11800650  ; ->msys::MLytNum
118098ac: ldr      r1, [pc, #0x390]  ; =0xfff9f4fc
118098b0: sub      r0, r0, #0x28
118098b4: ldr      r4, [pc, #0x38c]  ; =0x3e45c4
118098b8: add      r0, r0, r1
118098bc: add      r5, r0, #0x4c000
118098c0: add      r5, r5, #0x194
118098c4: add      r5, r5, #0xdc00
118098c8: add      r5, r5, #0x124
118098cc: add      r0, r5, #0x14c
118098d0: str      r4, [r5]
118098d4: bl       #0x11800658  ; ->MessageSimple::term
118098d8: add      r0, r5, #0x14c
118098dc: bl       #0x11800660  ; ->MessageSimple
118098e0: sub      r0, r0, #0x14c
118098e4: bl       #0x118059d0
118098e8: sub      r5, r0, #0x6c00
118098ec: sub      r5, r5, #0x44
118098f0: sub      r0, r0, #0x6800
118098f4: sub      r0, r0, #0x2f8
118098f8: str      r4, [r5]
118098fc: bl       #0x11800658  ; ->MessageSimple::term
11809900: add      r0, r5, #0x14c
11809904: bl       #0x11800660  ; ->MessageSimple
11809908: sub      r0, r0, #0x14c
1180990c: bl       #0x118059d0
11809910: sub      r5, r0, #0x6c00
11809914: sub      r5, r5, #0x44
11809918: sub      r0, r0, #0x6800
1180991c: sub      r0, r0, #0x2f8
11809920: str      r4, [r5]
11809924: bl       #0x11800658  ; ->MessageSimple::term
11809928: add      r0, r5, #0x14c
1180992c: bl       #0x11800660  ; ->MessageSimple
11809930: sub      r0, r0, #0x14c
11809934: bl       #0x118059d0
11809938: vstr     s16, [r0, #-0x10]
1180993c: vstr     s16, [r0, #-0x2c]
11809940: sub      r0, r0, #0x268
11809944: bl       #0x11800650  ; ->msys::MLytNum
11809948: sub      r0, r0, #0x230
1180994c: bl       #0x11800650  ; ->msys::MLytNum
11809950: ldr      r1, [pc, #0x2f4]  ; =0x1180c8d0
11809954: sub      r0, r0, #0x7000
11809958: sub      r0, r0, #0x88
1180995c: str      r1, [r0]
11809960: add      r1, r0, #0x7000
11809964: add      r1, r1, #0x68
11809968: vstr     s16, [r1, #0xc]
1180996c: add      r1, r0, #0x7000
11809970: add      r1, r1, #0x4c
11809974: vstr     s16, [r1, #0xc]
11809978: add      r1, r0, #0x7000
1180997c: add      r1, r1, #0x30
11809980: add      r0, r0, #0x6c00
11809984: vstr     s16, [r1, #0xc]
11809988: add      r0, r0, #0x3f4
1180998c: bl       #0x11800398  ; ->ad::lyt::Layout
11809990: ldr      r1, [pc, #0x2b8]  ; =0x1180cb14
11809994: sub      r0, r0, #0x6c00
11809998: sub      r0, r0, #0x3f4
1180999c: str      r1, [r0], #0x1fc
118099a0: bl       #0x118003a0  ; ->ad::ui::UIListWindowPlusLyt
118099a4: sub      r0, r0, #0x1fc
118099a8: bl       #0x118003a8  ; ->msys::MListWndPBase
118099ac: ldr      r2, [pc, #0x2a0]  ; =0x1180c958
118099b0: sub      r1, r0, #0x7000
118099b4: sub      r1, r1, #0x18c
118099b8: str      r2, [r1]
118099bc: vstr     s16, [r0, #-0x18]
118099c0: vstr     s16, [r0, #-0x34]
118099c4: vstr     s16, [r0, #-0x50]
118099c8: vstr     s16, [r0, #-0x6c]
118099cc: vstr     s16, [r0, #-0x88]
118099d0: vstr     s16, [r0, #-0xa4]
118099d4: sub      r0, r0, #0xec
118099d8: bl       #0x11800398  ; ->ad::lyt::Layout
118099dc: sub      r0, r0, #0x3c
118099e0: bl       #0x11800398  ; ->ad::lyt::Layout
118099e4: ldr      r1, [pc, #0x26c]  ; =0x1180cb58
118099e8: sub      r0, r0, #0x7000
118099ec: sub      r0, r0, #0x64
118099f0: str      r1, [r0], #0x1fc
118099f4: bl       #0x118003a0  ; ->ad::ui::UIListWindowPlusLyt
118099f8: sub      r0, r0, #0x1fc
118099fc: bl       #0x118003a8  ; ->msys::MListWndPBase
11809a00: sub      r5, r0, #0x6c00
11809a04: ldr      r1, [pc, #0x250]  ; =0x3e4730
11809a08: sub      r5, r5, #0x338
11809a0c: sub      r0, r0, #0x6c00
11809a10: sub      r0, r0, #0x1ec
11809a14: str      r1, [r5]
11809a18: bl       #0x11800598  ; ->Message::term
11809a1c: add      r0, r5, #0x14c
11809a20: bl       #0x118005a0  ; ->Message
11809a24: sub      r0, r0, #0x14c
11809a28: bl       #0x118059d0
11809a2c: sub      r0, r0, #0x17c
11809a30: bl       #0x11800668  ; ->msys::MDfxChr
11809a34: sub      r0, r0, #0x17c
11809a38: bl       #0x11800668  ; ->msys::MDfxChr
11809a3c: sub      r0, r0, #0x17c
11809a40: bl       #0x11800668  ; ->msys::MDfxChr
11809a44: sub      r0, r0, #0x17c
11809a48: bl       #0x11800668  ; ->msys::MDfxChr
11809a4c: sub      r5, r0, #0x36800
11809a50: ldr      r1, [pc, #0x208]  ; =0x3313cc msys::MDfxChr
11809a54: sub      r5, r5, #0x25c
11809a58: mov      r3, #4
11809a5c: mov      r2, #0x17c
11809a60: sub      r0, r0, #0x5f0
11809a64: bl       #0x118004f8  ; ->__aeabi_vec_dtor
11809a68: add      r0, r5, #0x36000
11809a6c: add      r0, r0, #0x2f0
11809a70: bl       #0x11800668  ; ->msys::MDfxChr
11809a74: sub      r5, r0, #0x36000
11809a78: sub      r0, r0, #0x800
11809a7c: ldr      r1, [pc, #0x1dc]  ; =0x3313cc msys::MDfxChr
11809a80: sub      r5, r5, #0x2f0
11809a84: mov      r3, #6
11809a88: mov      r2, #0x17c
11809a8c: sub      r0, r0, #0xe8
11809a90: bl       #0x118004f8  ; ->__aeabi_vec_dtor
11809a94: add      r0, r5, #0x35400
11809a98: add      r0, r0, #0x3d8
11809a9c: bl       #0x11800650  ; ->msys::MLytNum
11809aa0: sub      r0, r0, #0x230
11809aa4: bl       #0x11800650  ; ->msys::MLytNum
11809aa8: sub      r5, r0, #0x6c00
11809aac: sub      r5, r5, #0x44
11809ab0: sub      r0, r0, #0x6800
11809ab4: sub      r0, r0, #0x2f8
11809ab8: str      r4, [r5]
11809abc: bl       #0x11800658  ; ->MessageSimple::term
11809ac0: add      r0, r5, #0x14c
11809ac4: bl       #0x11800660  ; ->MessageSimple
11809ac8: sub      r0, r0, #0x14c
11809acc: bl       #0x118059d0
11809ad0: sub      r5, r0, #0x6c00
11809ad4: sub      r5, r5, #0x44
11809ad8: sub      r0, r0, #0x6800
11809adc: sub      r0, r0, #0x2f8
11809ae0: str      r4, [r5]
11809ae4: bl       #0x11800658  ; ->MessageSimple::term
11809ae8: add      r0, r5, #0x14c
11809aec: bl       #0x11800660  ; ->MessageSimple
11809af0: sub      r0, r0, #0x14c
11809af4: bl       #0x118059d0
11809af8: sub      r5, r0, #0x6c00
11809afc: sub      r5, r5, #0x44
11809b00: sub      r0, r0, #0x6800
11809b04: sub      r0, r0, #0x2f8
11809b08: str      r4, [r5]
11809b0c: bl       #0x11800658  ; ->MessageSimple::term
11809b10: add      r0, r5, #0x14c
11809b14: bl       #0x11800660  ; ->MessageSimple
11809b18: sub      r0, r0, #0x14c
11809b1c: bl       #0x118059d0
11809b20: sub      r5, r0, #0x6c00
11809b24: sub      r5, r5, #0x44
11809b28: sub      r0, r0, #0x6800
11809b2c: sub      r0, r0, #0x2f8
11809b30: str      r4, [r5]
11809b34: bl       #0x11800658  ; ->MessageSimple::term
11809b38: add      r0, r5, #0x14c
11809b3c: bl       #0x11800660  ; ->MessageSimple
11809b40: sub      r0, r0, #0x14c
11809b44: bl       #0x118059d0
11809b48: sub      r5, r0, #0x6c00
11809b4c: sub      r5, r5, #0x44
11809b50: sub      r0, r0, #0x6800
11809b54: sub      r0, r0, #0x2f8
11809b58: str      r4, [r5]
11809b5c: bl       #0x11800658  ; ->MessageSimple::term
11809b60: add      r0, r5, #0x14c
11809b64: bl       #0x11800660  ; ->MessageSimple
11809b68: sub      r0, r0, #0x14c
11809b6c: bl       #0x118059d0
11809b70: mov      r4, r0
11809b74: sub      r0, r0, #0x400
11809b78: ldr      r1, [pc, #0xe4]  ; =0x1180b5b0
11809b7c: sub      r0, r0, #0xf8
11809b80: mov      r3, #2
11809b84: mov      r2, #0x27c
11809b88: bl       #0x118004f8  ; ->__aeabi_vec_dtor
11809b8c: sub      r0, r4, #0x550
11809b90: bl       #0x11800670  ; ->msys::MCursorBase
11809b94: ldr      r5, [pc, #0xcc]  ; =0x3e4580
11809b98: sub      r0, r0, #0x3a8
11809b9c: mov      r4, r0
11809ba0: str      r5, [r0]
11809ba4: bl       #0x118004e8  ; ->msys::MLyt::term
11809ba8: ldr      r1, [pc, #0xbc]  ; =0x118012dc
11809bac: mov      r3, #0xc
11809bb0: mov      r2, #0x10
11809bb4: add      r0, r4, #0x2b0
11809bb8: bl       #0x118004f8  ; ->__aeabi_vec_dtor
11809bbc: ldr      r1, [pc, #0xac]  ; =0x11801148
11809bc0: mov      r3, #0xc
11809bc4: mov      r2, #0x1c
11809bc8: add      r0, r4, #0x154
11809bcc: bl       #0x118004f8  ; ->__aeabi_vec_dtor
11809bd0: mov      r0, r4
11809bd4: bl       #0x118059d0
11809bd8: sub      r0, r0, #0x3a8
11809bdc: mov      r4, r0
11809be0: str      r5, [r0]
11809be4: bl       #0x118004e8  ; ->msys::MLyt::term
11809be8: ldr      r1, [pc, #0x7c]  ; =0x118012dc
11809bec: mov      r3, #0xc
11809bf0: mov      r2, #0x10
11809bf4: add      r0, r4, #0x2b0
11809bf8: bl       #0x118004f8  ; ->__aeabi_vec_dtor
11809bfc: ldr      r1, [pc, #0x6c]  ; =0x11801148
11809c00: mov      r3, #0xc
11809c04: mov      r2, #0x1c
11809c08: add      r0, r4, #0x154
11809c0c: bl       #0x118004f8  ; ->__aeabi_vec_dtor
11809c10: mov      r0, r4
11809c14: bl       #0x118059d0
11809c18: sub      r4, r0, #0x12800
11809c1c: sub      r4, r4, #0x3b4
11809c20: mov      r3, #2
11809c24: b        #0x11809c74
11809c28: .word    0x1180c99c
11809c2c: strdeq   r0, r1, [r6], -ip
11809c30: andeq    r0, r0, r0
11809c34: .word    0xfff9f02c
11809c38: strheq   r0, [r6], -r8
11809c3c: muleq    r6, ip, pc
11809c40: andeq    r0, r6, r4, lsl #22
11809c44: .word    0xfff9f4fc
11809c48: eorseq   r4, lr, r4, asr #11
11809c4c: ldrdne   ip, sp, [r0, r0]
11809c50: orrne    ip, r0, r4, lsl fp
11809c54: orrne    ip, r0, r8, asr sb
11809c58: orrne    ip, r0, r8, asr fp
11809c5c: eorseq   r4, lr, r0, lsr r7
11809c60: eorseq   r1, r3, ip, asr #7
11809c64: strhne   fp, [r0, r0]
11809c68: eorseq   r4, lr, r0, lsl #11
11809c6c: ldrdne   r1, r2, [r0, ip]
11809c70: orrne    r1, r0, r8, asr #2
11809c74: ldr      r1, [pc, #0x50]  ; =0x24a104 ad::fw::Resource
11809c78: mov      r2, #0x44
11809c7c: sub      r0, r0, #0x88
11809c80: bl       #0x118004f8  ; ->__aeabi_vec_dtor
11809c84: add      r0, r4, #0x12800
11809c88: add      r0, r0, #0x2e8
11809c8c: bl       #0x11800500  ; ->ad::fw::Resource
11809c90: sub      r0, r0, #0x44
11809c94: bl       #0x11800500  ; ->ad::fw::Resource
11809c98: sub      r4, r0, #0x74
11809c9c: mov      r0, r4
11809ca0: bl       #0x11800648  ; ->ad::lyt::LytResourceMan::term
11809ca4: add      r0, r4, #4
11809ca8: bl       #0x11800678  ; ->ad::font::ResFont
11809cac: sub      r0, r0, #0x20
11809cb0: bl       #0x11800680  ; ->ad::ctrl::ButtonGroup
11809cb4: sub      r0, r0, #0x12800
11809cb8: sub      r0, r0, #0x204
11809cbc: bl       #0x11800688  ; ->Backup
11809cc0: vpop     {d8}
11809cc4: sub      r0, r0, #0x10
11809cc8: pop      {r4, r5, r6, pc}
11809ccc: eoreq    sl, r4, r4, lsl #2
11809cd0: ldr      r2, [pc, #0xc]  ; =0x129f8
11809cd4: ldr      r0, [r0, #0x20]
11809cd8: add      r1, r2, r1, lsl #2
11809cdc: add      r0, r0, r1
11809ce0: bx       lr
11809ce4: strdeq   r2, r3, [r1], -r8
11809ce8: push     {r4, lr}
11809cec: mov      r4, r0
11809cf0: ldr      r0, [r0, #0x20]
11809cf4: cmp      r0, #0
11809cf8: ldrne    r0, [r4, #0x20]
11809cfc: bne      #0x11809d34
11809d00: ldr      r0, [r4]
11809d04: ldr      r1, [r0, #0x2c]
11809d08: mov      r0, r4
11809d0c: blx      r1
11809d10: mov      r3, #0
11809d14: ldr      r1, [r4, #0x18]
11809d18: ldr      r0, [pc, #0x40]  ; =0x61018
11809d1c: mov      r2, r3
11809d20: bl       #0x11800180  ; ->_ZnwjP10MemAlcBasePKcj
11809d24: cmp      r0, #0
11809d28: movne    r1, r4
11809d2c: blne     #0x11809074
11809d30: str      r0, [r4, #0x20]
11809d34: add      r1, r0, #0x12000
11809d38: ldr      r2, [r1, #0xa00]
11809d3c: tst      r2, #1
11809d40: ldreq    r1, [r1, #0x9fc]
11809d44: add      r0, r0, r2, asr #1
11809d48: beq      #0x11809d58
11809d4c: ldr      r2, [r0]
11809d50: ldr      r1, [r1, #0x9fc]
11809d54: ldr      r1, [r2, r1]
11809d58: pop      {r4, lr}
11809d5c: bx       r1
11809d60: andeq    r1, r6, r8, lsl r0
11809d64: push     {r4, r5, r6, r7, lr}
11809d68: sub      sp, sp, #0xc
11809d6c: mov      r5, r1
11809d70: ldr      r4, [r0, #0x20]
11809d74: ldr      r0, [r4, #4]
11809d78: bl       #0x11800690  ; ->msys::MPageBase::updateInputAllChr
11809d7c: add      r1, r4, #0x12000
11809d80: ldr      r0, [r1, #0xa08]
11809d84: tst      r0, #1
11809d88: ldreq    r2, [r1, #0xa04]
11809d8c: add      r0, r4, r0, asr #1
11809d90: beq      #0x11809da0
11809d94: ldr      r2, [r0]
11809d98: ldr      r1, [r1, #0xa04]
11809d9c: ldr      r2, [r2, r1]
11809da0: mov      r1, r5
11809da4: blx      r2
11809da8: add      r0, r4, #0x3dc00
11809dac: mov      r7, #0
11809db0: add      r0, r0, #0x384
11809db4: bl       #0x11800308  ; ->msys::MListWndPBase::isTpNeutral
11809db8: mov      r6, r0
11809dbc: ldrb     r0, [r5, #0x11]
11809dc0: cmp      r0, #0
11809dc4: ldrbeq   r0, [r5, #0x12]
11809dc8: cmpeq    r0, #0
11809dcc: cmpne    r6, #0
11809dd0: beq      #0x11809dfc
11809dd4: ldrh     r1, [r5, #0x14]
11809dd8: ldrh     r2, [r5, #0x16]
11809ddc: mov      r7, sp
11809de0: sub      r0, r1, #0xa0
11809de4: rsb      r1, r2, #0x78
11809de8: vmov     s1, r1
11809dec: vmov     s0, r0
11809df0: vcvt.f32.s32 s1, s1
11809df4: vcvt.f32.s32 s0, s0
11809df8: vstmia   sp, {s0, s1}
11809dfc: mov      r1, r5
11809e00: ldr      r0, [r4]
11809e04: ldr      r2, [r0, #8]
11809e08: mov      r0, r4
11809e0c: blx      r2
11809e10: mov      r3, r0
11809e14: ldr      r0, [r4, #8]
11809e18: cmp      r0, #0
11809e1c: bne      #0x11809e2c
11809e20: ldr      r0, [pc, #0x34]  ; =0x3f62a8 msys::MComSys::_sys
11809e24: ldr      r0, [r0]
11809e28: str      r0, [r4, #8]
11809e2c: add      r0, r0, #0xe0000
11809e30: add      r0, r0, #0x6500
11809e34: mov      r1, r7
11809e38: ldrsb    r0, [r0, #8]
11809e3c: and      r0, r0, r6
11809e40: and      r2, r0, r3
11809e44: add      r0, r4, #0x12800
11809e48: add      r0, r0, #0x214
11809e4c: bl       #0x11800698  ; ->ad::ctrl::ButtonGroup::Update
11809e50: add      sp, sp, #0xc
11809e54: mvn      r0, #0
11809e58: pop      {r4, r5, r6, r7, pc}
11809e5c: eorseq   r6, pc, r8, lsr #5
11809e60: bx       lr
11809e64: mov      r0, #0
11809e68: bx       lr
11809e6c: ldr      r1, [pc, #0xbc]  ; =0x1180c9b0
11809e70: push     {r4, lr}
11809e74: mov      r4, r0
11809e78: str      r1, [r0]
11809e7c: ldr      r0, [r0, #0x20]
11809e80: cmp      r0, #0
11809e84: beq      #0x11809e94
11809e88: ldr      r1, [r0]
11809e8c: ldr      r1, [r1, #4]
11809e90: blx      r1
11809e94: mov      r0, #0
11809e98: str      r0, [r4, #0x20]
11809e9c: ldr      r0, [pc, #0x90]  ; =0x3e483c
11809ea0: str      r0, [r4], #0x10
11809ea4: ldr      r1, [r4], #-4
11809ea8: cmp      r1, r4
11809eac: beq      #0x11809ec8
11809eb0: ldr      r0, [r1, #4]
11809eb4: str      r1, [r1, #4]
11809eb8: str      r1, [r1]
11809ebc: cmp      r0, r4
11809ec0: mov      r1, r0
11809ec4: bne      #0x11809eb0
11809ec8: str      r4, [r4, #4]
11809ecc: mov      r1, r4
11809ed0: str      r4, [r4]
11809ed4: ldr      r0, [r4, #4]!
11809ed8: str      r0, [r1, #4]
11809edc: ldr      r1, [r4, #-4]
11809ee0: str      r1, [r0]
11809ee4: ldr      r1, [r4, #-8]
11809ee8: sub      r0, r4, #0xc
11809eec: cmp      r1, r0
11809ef0: beq      #0x11809f0c
11809ef4: ldr      r2, [r1, #4]
11809ef8: str      r1, [r1, #4]
11809efc: str      r1, [r1]
11809f00: cmp      r2, r0
11809f04: mov      r1, r2
11809f08: bne      #0x11809ef4
11809f0c: str      r0, [r0, #4]
11809f10: str      r0, [r0]
11809f14: ldr      r2, [r0]
11809f18: ldr      r1, [r0, #4]
11809f1c: str      r1, [r2, #4]
11809f20: ldr      r2, [r0], #-4
11809f24: str      r2, [r1]
11809f28: pop      {r4, lr}
11809f2c: b        #0x11800190  ; ->_ZdlPv
11809f30: strhne   ip, [r0, r0]
11809f34: eorseq   r4, lr, ip, lsr r8
11809f38: push     {r4, lr}
11809f3c: mov      r4, r0
11809f40: ldr      r0, [pc, #0xb0]  ; =0x1180c9b0
11809f44: str      r0, [r4]
11809f48: ldr      r0, [r4, #0x20]
11809f4c: cmp      r0, #0
11809f50: beq      #0x11809f60
11809f54: ldr      r1, [r0]
11809f58: ldr      r1, [r1, #4]
11809f5c: blx      r1
11809f60: mov      r0, #0
11809f64: str      r0, [r4, #0x20]
11809f68: ldr      r0, [pc, #0x8c]  ; =0x3e483c
11809f6c: str      r0, [r4], #0x10
11809f70: ldr      r1, [r4], #-4
11809f74: cmp      r1, r4
11809f78: beq      #0x11809f94
11809f7c: ldr      r0, [r1, #4]
11809f80: str      r1, [r1, #4]
11809f84: str      r1, [r1]
11809f88: cmp      r0, r4
11809f8c: mov      r1, r0
11809f90: bne      #0x11809f7c
11809f94: str      r4, [r4, #4]
11809f98: mov      r1, r4
11809f9c: str      r4, [r4]
11809fa0: ldr      r0, [r4, #4]!
11809fa4: str      r0, [r1, #4]
11809fa8: ldr      r1, [r4, #-4]
11809fac: str      r1, [r0]
11809fb0: ldr      r1, [r4, #-8]
11809fb4: sub      r0, r4, #0xc
11809fb8: cmp      r1, r0
11809fbc: beq      #0x11809fd8
11809fc0: ldr      r2, [r1, #4]
11809fc4: str      r1, [r1, #4]
11809fc8: str      r1, [r1]
11809fcc: cmp      r2, r0
11809fd0: mov      r1, r2
11809fd4: bne      #0x11809fc0
11809fd8: str      r0, [r0, #4]
11809fdc: str      r0, [r0]
11809fe0: ldr      r2, [r0]
11809fe4: ldr      r1, [r0, #4]
11809fe8: str      r1, [r2, #4]
11809fec: ldr      r2, [r0], #-4
11809ff0: str      r2, [r1]
11809ff4: pop      {r4, pc}
11809ff8: strhne   ip, [r0, r0]
11809ffc: eorseq   r4, lr, ip, lsr r8
1180a000: ldr      r1, [r0, #0x580]
1180a004: add      r1, r1, #0xe9000
1180a008: ldrb     r1, [r1, #0x49]
1180a00c: cmp      r1, #0
1180a010: beq      #0x1180a018
1180a014: b        #0x11800268  ; ->GameMain::Back
1180a018: bx       lr
1180a01c: push     {r4, lr}
1180a020: bl       #0x118006a0  ; ->msys::MTaskBase
1180a024: ldr      r1, [pc, #0x28]  ; =0x1180c9e8
1180a028: str      r1, [r0], #0x584
1180a02c: bl       #0x1180b454
1180a030: sub      r4, r0, #0x400
1180a034: sub      r4, r4, #0x184
1180a038: mov      r1, r4
1180a03c: bl       #0x1180b2c8
1180a040: add      r0, r4, #0x400
1180a044: add      r0, r0, #0x184
1180a048: str      r0, [r4, #0x580]
1180a04c: mov      r0, r4
1180a050: pop      {r4, pc}
1180a054: orrne    ip, r0, r8, ror #19
1180a058: ldr      r1, [pc, #0x1c]  ; =0x1180c9e8
1180a05c: push     {r4, lr}
1180a060: str      r1, [r0], #0x584
1180a064: bl       #0x11805724
1180a068: sub      r0, r0, #0x400
1180a06c: sub      r0, r0, #0x184
1180a070: bl       #0x118006a8  ; ->ad::fw::TaskBase
1180a074: pop      {r4, lr}
1180a078: b        #0x11800190  ; ->_ZdlPv
1180a07c: orrne    ip, r0, r8, ror #19
1180a080: ldr      r1, [pc, #0x18]  ; =0x1180c9e8
1180a084: push     {r4, lr}
1180a088: str      r1, [r0], #0x584
1180a08c: bl       #0x11805724
1180a090: sub      r0, r0, #0x400
1180a094: pop      {r4, lr}
1180a098: sub      r0, r0, #0x184
1180a09c: b        #0x118006a8  ; ->ad::fw::TaskBase
1180a0a0: orrne    ip, r0, r8, ror #19
1180a0a4: push     {r4, r5, lr}
1180a0a8: mov      r5, r0
1180a0ac: ldr      r0, [pc, #0x60]  ; =0x4ad54
1180a0b0: sub      sp, sp, #0x74
1180a0b4: mov      r2, #0x400
1180a0b8: add      r0, r0, r5
1180a0bc: mov      r1, sp
1180a0c0: mov      r4, r0
1180a0c4: bl       #0x118006b0  ; ->msys::MCamera::getProjMtx
1180a0c8: add      r1, sp, #0x40
1180a0cc: mov      r0, r4
1180a0d0: bl       #0x118006b8  ; ->msys::MCamera::getViewMtx
1180a0d4: ldr      r0, [r5, #4]
1180a0d8: mov      r3, #1
1180a0dc: mov      r2, sp
1180a0e0: add      r1, sp, #0x40
1180a0e4: bl       #0x118006c0  ; ->ad::fw::TaskBase::setULcdCameraInfoBase
1180a0e8: add      r4, r4, #0x20
1180a0ec: mov      r3, #1
1180a0f0: vldmia   r4, {s0, s1}
1180a0f4: mov      r2, #0
1180a0f8: mov      r1, #0x400
1180a0fc: mov      r0, sp
1180a100: bl       #0x118006c8  ; ->Grp::SetupProjLcdOrtho
1180a104: mov      r0, r5
1180a108: bl       #0x118006d0  ; ->msys::MComSys::funcCalcMainNomal
1180a10c: add      sp, sp, #0x74
1180a110: pop      {r4, r5, pc}
1180a114: andeq    sl, r4, r4, asr sp
1180a118: push     {r4, r5, lr}
1180a11c: mov      r4, r0
1180a120: ldr      r0, [pc, #0x2c]  ; =0x4ae34
1180a124: sub      sp, sp, #0x44
1180a128: mov      r5, r1
1180a12c: ldr      r2, [pc, #0x1c]  ; =0x401
1180a130: mov      r1, sp
1180a134: add      r0, r0, r4
1180a138: bl       #0x118006b0  ; ->msys::MCamera::getProjMtx
1180a13c: mov      r1, r5
1180a140: mov      r0, r4
1180a144: bl       #0x118006d8  ; ->msys::MComSys::funcDrawLower
1180a148: add      sp, sp, #0x44
1180a14c: pop      {r4, r5, pc}
1180a150: andeq    r0, r0, r1, lsl #8
1180a154: andeq    sl, r4, r4, lsr lr
1180a158: push     {r0, r1, r4, r5, r6, r7, r8, sb, sl, fp, lr}
1180a15c: mov      r5, r0
1180a160: add      r0, r0, #0x40000
1180a164: add      r0, r0, #0xaf00
1180a168: vpush    {d8, d9, d10, d11}
1180a16c: sub      sp, sp, #0x19c
1180a170: ldrb     r0, [r0, #0x14]
1180a174: cmp      r0, #0
1180a178: beq      #0x1180ada8
1180a17c: ldr      r0, [pc, #0x5ac]  ; =0x4ad54
1180a180: mov      r1, #0x400
1180a184: add      r0, r0, r5
1180a188: mov      r7, r0
1180a18c: bl       #0x118006e0  ; ->msys::MCamera::update
1180a190: ldr      r0, [r5, #4]
1180a194: add      r6, r0, #0x20c
1180a198: add      r8, r0, #0x23c
1180a19c: ldr      r0, [pc, #0x590]  ; =0xfffb50e8
1180a1a0: add      r1, r6, #0xc
1180a1a4: vldr     s0, [r6, #8]
1180a1a8: sub      r4, r5, r0
1180a1ac: add      sb, r4, #0x4d000
1180a1b0: vldmia   r1!, {s3, s4, s5, s6, s7}
1180a1b4: add      sb, sb, #0x950
1180a1b8: add      r0, r4, #0x4d000
1180a1bc: add      r0, r0, #0x9f0
1180a1c0: vldmia   r6, {s1, s2}
1180a1c4: vstr     s0, [sb, #0xa8]
1180a1c8: add      sb, sb, #0xac
1180a1cc: vstmia   r0, {s1, s2}
1180a1d0: vmov.f32 s0, s1
1180a1d4: vmov.f32 s1, s2
1180a1d8: vstmia   sb!, {s3, s4, s5, s6, s7}
1180a1dc: ldm      r1, {r0, r2, r3, ip}
1180a1e0: sub      r1, r1, #0x20
1180a1e4: stm      sb!, {r0, r2, r3, ip}
1180a1e8: mov      r2, r0
1180a1ec: vldr     s2, [sb, #-0x28]
1180a1f0: sub      sb, sb, #0xd0
1180a1f4: add      r0, sb, #0xc4
1180a1f8: vstmia   sb, {s0, s1, s2, s3, s4, s5, s6, s7}
1180a1fc: add      sl, sb, #0x24
1180a200: ldm      r0, {r0, r3}
1180a204: str      r2, [sb, #0x20]
1180a208: add      sb, sb, #0xd0
1180a20c: stm      sl, {r0, r3, ip}
1180a210: vldmia   r8!, {s0, s1, s2, s3, s4, s5, s6, s7}
1180a214: vstmia   sb!, {s0, s1, s2, s3, s4, s5, s6, s7}
1180a218: vldmia   r8, {s0, s1, s2, s3, s4, s5, s6, s7}
1180a21c: sub      r8, r8, #0x20
1180a220: vstmia   sb, {s0, s1, s2, s3, s4, s5, s6, s7}
1180a224: sub      sb, sb, #0x20
1180a228: vldmia   sb, {s0, s1, s2, s3, s4, s5, s6, s7}
1180a22c: sub      sb, sb, #0x70
1180a230: vstmia   sb, {s0, s1, s2, s3, s4, s5, s6, s7}
1180a234: add      sb, sb, #0x90
1180a238: vldmia   sb!, {s0, s1, s2, s3, s4, s5, s6, s7}
1180a23c: sub      r2, sb, #0x90
1180a240: sub      r0, sb, #0xe0
1180a244: sub      sb, sb, #0x110
1180a248: vstmia   r2, {s0, s1, s2, s3, s4, s5, s6, s7}
1180a24c: bl       #0x118006e8  ; ->ad::math::FastInverse
1180a250: ldm      sb, {r0, r1, r2, r3, sl, fp, ip, lr}
1180a254: add      sb, sb, #0x110
1180a258: stm      sb, {r0, r1, r2, r3, sl, fp, ip, lr}
1180a25c: sub      sb, sb, #0xf0
1180a260: ldm      sb, {r0, r1, r2, r3}
1180a264: add      sb, sb, #0x110
1180a268: stm      sb, {r0, r1, r2, r3}
1180a26c: sub      sb, sb, #0x100
1180a270: ldm      sb, {r0, r1, r2, r3, sl, fp, ip, lr}
1180a274: add      sb, sb, #0x110
1180a278: stm      sb, {r0, r1, r2, r3, sl, fp, ip, lr}
1180a27c: sub      sb, sb, #0xf0
1180a280: mov      ip, #0x400
1180a284: ldm      sb, {r0, r1, r2, r3}
1180a288: add      sb, sb, #0x110
1180a28c: stm      sb, {r0, r1, r2, r3}
1180a290: add      r0, r4, #0x40000
1180a294: add      r0, r0, #0xd800
1180a298: ldr      r1, [r7, #0x20]
1180a29c: vldr     s1, [r7, #0x24]
1180a2a0: mov      r3, #1
1180a2a4: str      r1, [r0, #0x304]
1180a2a8: vstr     s1, [r0, #0x308]
1180a2ac: ldr      r0, [pc, #0x484]  ; =0x4dac4
1180a2b0: vmov     s0, r1
1180a2b4: mov      r2, #0
1180a2b8: add      r0, r0, r4
1180a2bc: mov      r1, ip
1180a2c0: mov      r7, r0
1180a2c4: bl       #0x118006c8  ; ->Grp::SetupProjLcdOrtho
1180a2c8: add      r0, r4, #0x54
1180a2cc: mov      r1, r7
1180a2d0: bl       #0x118006f0  ; ->CellAnimeState::setProj2dParallax
1180a2d4: ldr      r0, [r5, #4]
1180a2d8: vldr     s1, [r6, #0xc]
1180a2dc: vldr     s4, [r6, #0x1c]
1180a2e0: vldr     s5, [r6, #0x2c]
1180a2e4: vldr     s0, [r0, #0x288]
1180a2e8: vldr     s2, [r0, #0x298]
1180a2ec: vldr     s3, [r0, #0x2a8]
1180a2f0: vsub.f32 s1, s1, s0
1180a2f4: vsub.f32 s2, s4, s2
1180a2f8: vsub.f32 s0, s5, s3
1180a2fc: ldr      r0, [pc, #0x438]  ; =0x98a24
1180a300: vmul.f32 s1, s1, s1
1180a304: vmla.f32 s1, s2, s2
1180a308: vmla.f32 s1, s0, s0
1180a30c: vsqrt.f32 s0, s1
1180a310: vstr     s0, [r4, #0x108]
1180a314: ldr      sl, [r0, r5]
1180a318: ldr      r1, [sl, #0x14]
1180a31c: ldr      r0, [sl, #0x18]
1180a320: mov      r2, r1
1180a324: cmp      r1, r0
1180a328: bls      #0x1180a338
1180a32c: sub      r0, r0, #0x1c
1180a330: cmp      r1, r0
1180a334: bne      #0x1180a32c
1180a338: str      r2, [sl, #0x18]
1180a33c: ldr      r0, [sl, #0x30]
1180a340: add      sb, sl, #0x4d000
1180a344: add      sb, sb, #0x950
1180a348: str      r0, [sl, #0x34]
1180a34c: ldr      r0, [pc, #0x3ec]  ; =0x4aaa4
1180a350: mov      r1, r6
1180a354: add      fp, r5, r0
1180a358: add      r0, sp, #0x78
1180a35c: str      fp, [sl, #0x3c]
1180a360: str      r0, [sp, #0xc]
1180a364: add      r0, sp, #0x168
1180a368: bl       #0x118006e8  ; ->ad::math::FastInverse
1180a36c: mov      r0, r8
1180a370: nop      
1180a374: bl       #0x118006f8  ; ->ad::math::CalcFar
1180a378: vmov.f32 s16, s0
1180a37c: mov      r0, r8
1180a380: bl       #0x11800700  ; ->ad::math::CalcNear
1180a384: vmov.f32 s1, s16
1180a388: mov      r2, r8
1180a38c: add      r1, sp, #0x168
1180a390: add      r0, sp, #0xe8
1180a394: bl       #0x11800708  ; ->ad::math::WorldFrustum
1180a398: add      r1, sp, #0x114
1180a39c: vldr     s2, [sp, #0x128]
1180a3a0: vldr     s1, [sp, #0x12c]
1180a3a4: vldr     s0, [sp, #0x130]
1180a3a8: vldr     s17, [sp, #0x110]
1180a3ac: vldr     s20, [pc, #0x390]  ; =0x3f000000 (0.5)
1180a3b0: ldr      r0, [pc, #0x39c]  ; =0x3f7f04 _ZGVZN31CalcSortCameraForRemillionOrtho4calcERKN2nn4math5MTX34ERKNS1_5MTX44EE18sort_inv_view_base
1180a3b4: vsub.f32 s2, s2, s17
1180a3b8: vldmia   r1, {s21, s22}
1180a3bc: vldr     s16, [pc, #0x384]  ; =0xbf3504f3 (-0.707107)
1180a3c0: ldrb     r0, [r0]
1180a3c4: vldr     s18, [pc, #0x380]  ; =0x0 (0)
1180a3c8: vsub.f32 s1, s1, s21
1180a3cc: vsub.f32 s0, s0, s22
1180a3d0: vldr     s19, [pc, #0x378]  ; =0x3f800000 (1)
1180a3d4: tst      r0, #1
1180a3d8: vmla.f32 s17, s20, s2
1180a3dc: vmla.f32 s21, s20, s1
1180a3e0: vmla.f32 s22, s20, s0
1180a3e4: bne      #0x1180a43c
1180a3e8: ldr      r0, [pc, #0x364]  ; =0x3f7f04 _ZGVZN31CalcSortCameraForRemillionOrtho4calcERKN2nn4math5MTX34ERKNS1_5MTX44EE18sort_inv_view_base
1180a3ec: bl       #0x11800568  ; ->__cxa_guard_acquire
1180a3f0: cmp      r0, #0
1180a3f4: nop      
1180a3f8: beq      #0x1180a43c
1180a3fc: ldr      r0, [pc, #0x358]  ; =0x434d04 _ZZN31CalcSortCameraForRemillionOrtho4calcERKN2nn4math5MTX34ERKNS1_5MTX44EE18sort_inv_view_base
1180a400: vldr     s0, [pc, #0x350]  ; =0x3f3504f3 (0.707107)
1180a404: vstr     s19, [r0]
1180a408: vstr     s18, [r0, #4]
1180a40c: vstr     s18, [r0, #8]
1180a410: vstr     s18, [r0, #0xc]
1180a414: vstr     s18, [r0, #0x10]
1180a418: vstr     s0, [r0, #0x14]
1180a41c: vstr     s0, [r0, #0x18]
1180a420: vstr     s18, [r0, #0x1c]
1180a424: vstr     s18, [r0, #0x20]
1180a428: vstr     s16, [r0, #0x24]
1180a42c: vstr     s0, [r0, #0x28]
1180a430: vstr     s18, [r0, #0x2c]
1180a434: ldr      r0, [pc, #0x318]  ; =0x3f7f04 _ZGVZN31CalcSortCameraForRemillionOrtho4calcERKN2nn4math5MTX34ERKNS1_5MTX44EE18sort_inv_view_base
1180a438: bl       #0x11800570  ; ->__cxa_guard_release
1180a43c: ldr      r0, [pc, #0x318]  ; =0x434d04 _ZZN31CalcSortCameraForRemillionOrtho4calcERKN2nn4math5MTX34ERKNS1_5MTX44EE18sort_inv_view_base
1180a440: add      r1, sp, #0x78
1180a444: add      ip, sp, #0x98
1180a448: vldmia   r0!, {s0, s1, s2, s3, s4, s5, s6, s7}
1180a44c: vstmia   r1, {s0, s1, s2, s3, s4, s5, s6, s7}
1180a450: ldm      r0, {r0, r1, r2, r3}
1180a454: stm      ip, {r0, r1, r2, r3}
1180a458: vstr     s17, [sp, #0x84]
1180a45c: vstr     s21, [sp, #0x94]
1180a460: vstr     s22, [sp, #0xa4]
1180a464: ldr      r1, [sp, #0xc]
1180a468: mov      r0, r1
1180a46c: bl       #0x118006e8  ; ->ad::math::FastInverse
1180a470: vldr     s4, [sp, #0x14c]
1180a474: vldr     s5, [sp, #0x128]
1180a478: vldr     s2, [sp, #0x150]
1180a47c: vldr     s3, [sp, #0x12c]
1180a480: vldr     s0, [sp, #0x154]
1180a484: vldr     s1, [sp, #0x130]
1180a488: vsub.f32 s22, s4, s5
1180a48c: vsub.f32 s17, s2, s3
1180a490: vsub.f32 s21, s0, s1
1180a494: ldr      r0, [pc, #0x2c4]  ; =0x3f7f00 _ZGVZN31CalcSortCameraForRemillionOrtho4calcERKN2nn4math5MTX34ERKNS1_5MTX44EE14sort_view_look
1180a498: ldrb     r0, [r0]
1180a49c: tst      r0, #1
1180a4a0: bne      #0x1180a4d0
1180a4a4: ldr      r0, [pc, #0x2b4]  ; =0x3f7f00 _ZGVZN31CalcSortCameraForRemillionOrtho4calcERKN2nn4math5MTX34ERKNS1_5MTX44EE14sort_view_look
1180a4a8: bl       #0x11800568  ; ->__cxa_guard_acquire
1180a4ac: cmp      r0, #0
1180a4b0: nop      
1180a4b4: beq      #0x1180a4d0
1180a4b8: ldr      r0, [pc, #0x2a4]  ; =0x434cf8 _ZZN31CalcSortCameraForRemillionOrtho4calcERKN2nn4math5MTX34ERKNS1_5MTX44EE14sort_view_look
1180a4bc: vstr     s18, [r0]
1180a4c0: vstr     s16, [r0, #4]
1180a4c4: vstr     s16, [r0, #8]
1180a4c8: ldr      r0, [pc, #0x290]  ; =0x3f7f00 _ZGVZN31CalcSortCameraForRemillionOrtho4calcERKN2nn4math5MTX34ERKNS1_5MTX44EE14sort_view_look
1180a4cc: bl       #0x11800570  ; ->__cxa_guard_release
1180a4d0: ldr      r0, [pc, #0x28c]  ; =0x434cf8 _ZZN31CalcSortCameraForRemillionOrtho4calcERKN2nn4math5MTX34ERKNS1_5MTX44EE14sort_view_look
1180a4d4: vnmul.f32 s3, s18, s20
1180a4d8: mov      r1, r6
1180a4dc: vldr     s16, [pc, #0x288]  ; =0x40000000 (2)
1180a4e0: vldr     s0, [r0, #8]
1180a4e4: vldmia   r0, {s1, s2}
1180a4e8: add      r0, sp, #0xe0
1180a4ec: vstr     s18, [sp, #0xac]
1180a4f0: vstr     s18, [sp, #0xb0]
1180a4f4: vmul.f32 s1, s22, s1
1180a4f8: vstr     s18, [sp, #0xb8]
1180a4fc: vstr     s18, [sp, #0xc0]
1180a500: vstr     s18, [sp, #0xc8]
1180a504: vstr     s18, [sp, #0xcc]
1180a508: vstr     s18, [sp, #0xd8]
1180a50c: vstr     s18, [sp, #0xdc]
1180a510: vstmia   r0, {s18, s19}
1180a514: add      r0, sp, #0xd0
1180a518: vmla.f32 s1, s17, s2
1180a51c: vnmul.f32 s2, s18, s20
1180a520: vstr     s19, [sp, #0xa8]
1180a524: vmla.f32 s1, s21, s0
1180a528: vstr     s2, [sp, #0xb4]
1180a52c: vstr     s19, [sp, #0xbc]
1180a530: vstr     s3, [sp, #0xc4]
1180a534: vldr     s21, [pc, #0x22c]  ; =0xbf800000 (-1)
1180a538: vdiv.f32 s0, s19, s1
1180a53c: vmul.f32 s1, s18, s0
1180a540: vstmia   r0, {s0, s1}
1180a544: vldmia   r1!, {s0, s1, s2, s3, s4, s5, s6, s7}
1180a548: vstmia   sb!, {s0, s1, s2, s3, s4, s5, s6, s7}
1180a54c: ldm      r1, {r0, r2, r3, ip}
1180a550: sub      r1, r1, #0x20
1180a554: stm      sb, {r0, r2, r3, ip}
1180a558: add      sb, sb, #0x40
1180a55c: vldmia   r8!, {s0, s1, s2, s3, s4, s5, s6, s7}
1180a560: vstmia   sb!, {s0, s1, s2, s3, s4, s5, s6, s7}
1180a564: sub      r0, sb, #0x50
1180a568: vldmia   r8, {s0, s1, s2, s3, s4, s5, s6, s7}
1180a56c: vstmia   sb, {s0, s1, s2, s3, s4, s5, s6, s7}
1180a570: sub      sb, sb, #0x80
1180a574: bl       #0x118006e8  ; ->ad::math::FastInverse
1180a578: add      r1, sp, #0x78
1180a57c: add      sb, sb, #0xa0
1180a580: vldmia   r1, {s0, s1, s2, s3, s4, s5, s6, s7}
1180a584: add      ip, sp, #0x98
1180a588: vstmia   sb!, {s0, s1, s2, s3, s4, s5, s6, s7}
1180a58c: ldm      ip, {r0, r1, r2, r3}
1180a590: stm      sb!, {r0, r1, r2, r3}
1180a594: add      r0, sp, #0xa8
1180a598: vldmia   r0, {s0, s1, s2, s3, s4, s5, s6, s7}
1180a59c: add      r0, sp, #0xc8
1180a5a0: vstmia   sb!, {s0, s1, s2, s3, s4, s5, s6, s7}
1180a5a4: vldmia   r0, {s0, s1, s2, s3, s4, s5, s6, s7}
1180a5a8: vstmia   sb, {s0, s1, s2, s3, s4, s5, s6, s7}
1180a5ac: sub      sb, sb, #0xf0
1180a5b0: add      r0, sb, #0x110
1180a5b4: add      ip, sb, #0x130
1180a5b8: vldmia   sb, {s0, s1, s2, s3, s4, s5, s6, s7}
1180a5bc: vstmia   r0, {s0, s1, s2, s3, s4, s5, s6, s7}
1180a5c0: add      r0, sb, #0x20
1180a5c4: ldm      r0, {r0, r1, r2, r3}
1180a5c8: stm      ip, {r0, r1, r2, r3}
1180a5cc: add      r0, sb, #0x30
1180a5d0: vldmia   r0, {s0, s1, s2, s3, s4, s5, s6, s7}
1180a5d4: add      r0, sb, #0x140
1180a5d8: vstmia   r0, {s0, s1, s2, s3, s4, s5, s6, s7}
1180a5dc: add      r0, sb, #0x50
1180a5e0: add      sb, sb, #0x160
1180a5e4: ldm      r0, {r0, r1, r2, r3}
1180a5e8: stm      sb, {r0, r1, r2, r3}
1180a5ec: mov      r1, r7
1180a5f0: ldr      r0, [r5, #4]
1180a5f4: vldr     s0, [r6, #0xc]
1180a5f8: vldr     s5, [r6, #0x1c]
1180a5fc: vldr     s3, [r6, #0x2c]
1180a600: vldr     s1, [r0, #0x288]
1180a604: vldr     s2, [r0, #0x298]
1180a608: vldr     s4, [r0, #0x2a8]
1180a60c: vsub.f32 s0, s0, s1
1180a610: vsub.f32 s1, s5, s2
1180a614: vsub.f32 s2, s3, s4
1180a618: add      r0, r5, #0xd0000
1180a61c: add      r0, r0, #0x3100
1180a620: vmul.f32 s3, s0, s0
1180a624: vmla.f32 s3, s1, s1
1180a628: vmla.f32 s3, s2, s2
1180a62c: vsqrt.f32 s0, s3
1180a630: vstr     s0, [sl, #0x108]
1180a634: bl       #0x11800710  ; ->Prim::setProj2dParallax
1180a638: ldr      r0, [pc, #0x130]  ; =0xbfb7c
1180a63c: mov      r1, r7
1180a640: add      r0, r0, r5
1180a644: bl       #0x11800710  ; ->Prim::setProj2dParallax
1180a648: add      r0, r5, #0xd0000
1180a64c: add      r0, r0, #0x2f00
1180a650: mov      r1, r7
1180a654: bl       #0x11800718  ; ->ad::lyt::DrawInfo::SetProjectionMtx
1180a658: add      r0, r5, #0xd3000
1180a65c: mov      r1, r7
1180a660: bl       #0x11800718  ; ->ad::lyt::DrawInfo::SetProjectionMtx
1180a664: mov      r0, #0x400
1180a668: nop      
1180a66c: bl       #0x11800720  ; ->Grp::GetLcdWidth
1180a670: vmov     s0, r0
1180a674: mov      r0, #0x400
1180a678: vcvt.f32.u32 s22, s0
1180a67c: vmul.f32 s17, s22, s20
1180a680: bl       #0x11800728  ; ->Grp::GetLcdHeight
1180a684: vmov     s0, r0
1180a688: vnmul.f32 s1, s22, s20
1180a68c: vstr     s18, [sp, #0x50]
1180a690: vstr     s18, [sp, #0x54]
1180a694: vstr     s18, [sp, #0x60]
1180a698: vstr     s18, [sp, #0x64]
1180a69c: vcvt.f32.u32 s0, s0
1180a6a0: add      r0, sp, #0x40
1180a6a4: add      r2, sp, #0x68
1180a6a8: add      r1, sp, #0x30
1180a6ac: vsub.f32 s7, s17, s1
1180a6b0: vadd.f32 s6, s17, s1
1180a6b4: vmul.f32 s2, s0, s20
1180a6b8: vnmul.f32 s0, s0, s20
1180a6bc: vsub.f32 s4, s2, s0
1180a6c0: vadd.f32 s5, s2, s0
1180a6c4: vdiv.f32 s2, s19, s7
1180a6c8: vldr     s0, [pc, #0xa4]  ; =0x3a833405 (0.001001)
1180a6cc: vstr     s0, [sp, #0x58]
1180a6d0: vstr     s0, [sp, #0x5c]
1180a6d4: vldr     s0, [pc, #0x9c]  ; =0x80000000 (-0)
1180a6d8: vnmul.f32 s1, s2, s16
1180a6dc: vnmul.f32 s2, s6, s2
1180a6e0: vdiv.f32 s3, s19, s4
1180a6e4: vneg.f32 s2, s2
1180a6e8: vnmul.f32 s4, s3, s16
1180a6ec: vnmul.f32 s3, s5, s3
1180a6f0: vstr     s4, [sp, #0x30]
1180a6f4: vstr     s0, [sp, #0x34]
1180a6f8: vneg.f32 s3, s3
1180a6fc: vstr     s0, [sp, #0x38]
1180a700: vstr     s3, [sp, #0x3c]
1180a704: vstmia   r0, {s0, s1}
1180a708: ldr      r0, [pc, #0x6c]  ; =0x98a34
1180a70c: vstr     s0, [sp, #0x48]
1180a710: vstr     s2, [sp, #0x4c]
1180a714: add      r0, r0, r5
1180a718: vstmia   r2, {s18, s19}
1180a71c: bl       #0x11800730  ; ->Prim::setProjMtx
1180a720: add      r7, r5, #0xe6000
1180a724: mov      r2, #0
1180a728: mov      r1, r6
1180a72c: b        #0x1180a780
1180a730: andeq    sl, r4, r4, asr sp
1180a734: .word    0xfffb50e8
1180a738: andeq    sp, r4, r4, asr #21
1180a73c: andeq    r8, sb, r4, lsr #20
1180a740: andeq    sl, r4, r4, lsr #21
1180a744: svclo    #0
1180a748: svclt    #0x3504f3
1180a74c: andeq    r0, r0, r0
1180a750: svclo    #0x800000
1180a754: eorseq   r7, pc, r4, lsl #30
1180a758: svclo    #0x3504f3
1180a75c: subeq    r4, r3, r4, lsl #26
1180a760: eorseq   r7, pc, r0, lsl #30
1180a764: strdeq   r4, r5, [r3], #-0xc8
1180a768: svclt    #0x800000
1180a76c: andmi    r0, r0, r0
1180a770: andeq    pc, fp, ip, ror fp
1180a774: blo      #0xf8d7790
1180a778: andhi    r0, r0, r0
1180a77c: andeq    r8, sb, r4, lsr sl
1180a780: ldr      r0, [r7, #0x4f0]
1180a784: bl       #0x11800738  ; ->ad::fw::DfxSys::setViewMtx
1180a788: ldr      r1, [r4, #0x14]
1180a78c: ldr      r0, [r4, #0x18]
1180a790: mov      r2, r1
1180a794: cmp      r1, r0
1180a798: bls      #0x1180a7a8
1180a79c: sub      r0, r0, #0x1c
1180a7a0: cmp      r1, r0
1180a7a4: bne      #0x1180a79c
1180a7a8: str      r2, [r4, #0x18]
1180a7ac: ldr      r0, [r4, #0x30]
1180a7b0: str      r0, [r4, #0x34]
1180a7b4: str      fp, [r4, #0x3c]
1180a7b8: ldr      r1, [r7, #0x4f0]
1180a7bc: ldr      r0, [r1, #0x14]
1180a7c0: ldr      r2, [r0, #4]
1180a7c4: str      r2, [r0, #0xc]
1180a7c8: str      r2, [r0, #0x10]
1180a7cc: ldr      r0, [r1, #0x1c]
1180a7d0: ldr      r1, [r0, #4]
1180a7d4: str      r1, [r0, #0xc]
1180a7d8: str      r1, [r0, #0x10]
1180a7dc: ldr      r0, [r7, #0x4f0]
1180a7e0: mov      r1, r6
1180a7e4: ldr      r0, [r0, #0xc]
1180a7e8: bl       #0x11800740  ; ->ad::dfx::Engine::setViewMtx
1180a7ec: add      sb, r5, #0xc00
1180a7f0: add      sb, sb, #0x3d8
1180a7f4: mov      r0, #0x400
1180a7f8: add      sl, sb, #0x42000
1180a7fc: str      r0, [sp, #0x2c]
1180a800: ldrb     r0, [sl, #0xadc]
1180a804: mov      r1, #0xa
1180a808: mov      r7, #0
1180a80c: cmp      r0, #0
1180a810: ble      #0x1180a988
1180a814: mov      r2, #0x78000000
1180a818: add      r0, r4, #0x4d000
1180a81c: and      r1, r2, r1, lsl #27
1180a820: add      r0, r0, #0xa20
1180a824: str      r1, [sp, #0x78]
1180a828: add      r1, sb, #0x13800
1180a82c: str      r0, [sp, #0x80]
1180a830: add      r1, r1, #0xa4
1180a834: add      r0, r4, #0xf0
1180a838: vldr     s20, [pc, #0x2e0]  ; =0x4b7fffff (1.67772e+07)
1180a83c: str      r0, [sp, #0x7c]
1180a840: str      r1, [sp, #0x14]
1180a844: ldr      r0, [pc, #0x2d8]  ; =0x36b
1180a848: mul      r0, r7, r0
1180a84c: add      r0, sb, r0, lsl #5
1180a850: add      r8, r0, #0x27000
1180a854: add      r0, r0, #0x2c000
1180a858: add      r0, r0, #0x148
1180a85c: add      r8, r8, #0x148
1180a860: ldrb     r0, [r0, #0x83c]
1180a864: tst      r0, #1
1180a868: beq      #0x1180a978
1180a86c: ldr      r0, [pc, #0x2b4]  ; =0x6cc0
1180a870: ldr      r1, [sp, #0x2c]
1180a874: ldr      r0, [r0, r8]
1180a878: cmp      r0, r1
1180a87c: beq      #0x1180a88c
1180a880: mvn      r1, #0x400
1180a884: cmn      r0, r1
1180a888: beq      #0x1180a978
1180a88c: mvn      r1, #0x400
1180a890: cmn      r0, r1
1180a894: add      r1, r8, #0x5800
1180a898: ldr      r2, [pc, #0x28c]  ; =0xbf800000
1180a89c: vldr     s0, [r1, #0x5c]
1180a8a0: ldr      r1, [sp, #0x80]
1180a8a4: vldreq   s16, [sp, #0x14]
1180a8a8: vneg.f32 s0, s0
1180a8ac: vmovne   s16, sb
1180a8b0: vldr     s3, [r1, #0x28]
1180a8b4: vldr     s1, [r1, #0x2c]
1180a8b8: vldr     s4, [r1, #0x38]
1180a8bc: vldr     s2, [r1, #0x3c]
1180a8c0: vmla.f32 s1, s0, s3
1180a8c4: mov      r0, r4
1180a8c8: vmla.f32 s2, s0, s4
1180a8cc: vdiv.f32 s17, s1, s2
1180a8d0: vmov     r1, s17
1180a8d4: cmp      r1, r2
1180a8d8: vmovhi.f32 s17, s21
1180a8dc: bhi      #0x1180a8ec
1180a8e0: vcmpe.f32 s17, s18
1180a8e4: vmrs     apsr_nzcv, fpscr
1180a8e8: vmovgt.f32 s17, s18
1180a8ec: bic      r2, r2, #0x78000000
1180a8f0: orr      r6, r2, #0x80000000
1180a8f4: ldr      r2, [sp, #0x78]
1180a8f8: mvn      ip, #0xf8000000
1180a8fc: ldr      r3, [pc, #0x22c]  ; =0xf8000007
1180a900: vadd.f32 s0, s17, s19
1180a904: orr      r2, r2, r6
1180a908: and      r2, r2, r3
1180a90c: vmul.f32 s0, s0, s20
1180a910: vcvt.u32.f32 s0, s0
1180a914: vmov     r1, s0
1180a918: and      r1, ip, r1, lsl #3
1180a91c: orr      r1, r1, r2
1180a920: mov      ip, #0
1180a924: bic      r1, r1, #7
1180a928: orr      fp, r1, #5
1180a92c: str      ip, [sp, #0x84]
1180a930: str      ip, [sp, #0x1c]
1180a934: bl       #0x11800888
1180a938: mov      r6, r0
1180a93c: ldr      r0, [sp, #0x7c]
1180a940: ldr      r0, [r0]
1180a944: ldr      r1, [r0]
1180a948: ldr      r1, [r1, #0x10]
1180a94c: blx      r1
1180a950: ldr      r1, [sp, #0x1c]
1180a954: ldr      ip, [sp, #0x84]
1180a958: mov      r3, #5
1180a95c: strb     r3, [r6]
1180a960: str      r0, [r6, #0x18]
1180a964: str      r8, [r6, #8]
1180a968: str      fp, [r6, #4]
1180a96c: vstr     s16, [r6, #0xc]
1180a970: str      ip, [r6, #0x10]!
1180a974: str      r1, [r6, #4]
1180a978: ldrb     r0, [sl, #0xadc]
1180a97c: add      r7, r7, #1
1180a980: cmp      r0, r7
1180a984: bgt      #0x1180a844
1180a988: ldr      r0, [pc, #0x1a4]  ; =0xe64d8
1180a98c: add      sb, r5, r0
1180a990: ldr      r7, [sb, #4]
1180a994: cmp      r7, sb
1180a998: beq      #0x1180aa00
1180a99c: ldrb     r0, [r7, #0x13d]
1180a9a0: cmp      r0, #0
1180a9a4: beq      #0x1180a9f4
1180a9a8: ldr      r0, [r7, #-4]
1180a9ac: sub      r8, r7, #4
1180a9b0: mov      sl, #0xa
1180a9b4: mov      r2, sl
1180a9b8: ldr      r3, [r0, #0x14]
1180a9bc: mov      r1, r4
1180a9c0: mov      r0, r8
1180a9c4: blx      r3
1180a9c8: ldr      r6, [r8, #0x148]
1180a9cc: add      r8, r8, #0x144
1180a9d0: cmp      r6, r8
1180a9d4: beq      #0x1180a9f4
1180a9d8: sub      r0, r6, #4
1180a9dc: mov      r2, sl
1180a9e0: mov      r1, r4
1180a9e4: bl       #0x1180b784
1180a9e8: ldr      r6, [r6, #4]
1180a9ec: cmp      r6, r8
1180a9f0: bne      #0x1180a9d8
1180a9f4: ldr      r7, [r7, #4]
1180a9f8: cmp      r7, sb
1180a9fc: bne      #0x1180a99c
1180aa00: mov      r0, r5
1180aa04: bl       #0x11800748  ; ->msys::MComSys::getNextPage
1180aa08: cmp      r0, #0
1180aa0c: nop      
1180aa10: beq      #0x1180aa30
1180aa14: mov      r0, r5
1180aa18: bl       #0x11800748  ; ->msys::MComSys::getNextPage
1180aa1c: ldr      r1, [r0]
1180aa20: mov      r2, r4
1180aa24: ldr      r3, [r1, #0x1c]
1180aa28: ldr      r1, [sp, #0x1c0]
1180aa2c: blx      r3
1180aa30: ldr      r1, [pc, #0x100]  ; =0xfd7
1180aa34: add      r0, r5, #0xf00
1180aa38: add      r0, r0, #0xcd
1180aa3c: mov      r2, r4
1180aa40: ldrsb    r1, [r1, r5]
1180aa44: ldrsb    r0, [r1, r0]
1180aa48: add      r0, r5, r0, lsl #2
1180aa4c: ldr      r0, [r0, #0xf8c]
1180aa50: ldr      r1, [r0]
1180aa54: ldr      r3, [r1, #0x1c]
1180aa58: ldr      r1, [sp, #0x1c0]
1180aa5c: blx      r3
1180aa60: add      r6, r4, #0x30
1180aa64: ldm      r6, {r6, r8}
1180aa68: cmp      r6, r8
1180aa6c: beq      #0x1180ac6c
1180aa70: sub      r7, r8, r6
1180aa74: mov      r1, r8
1180aa78: asr      r2, r7, #2
1180aa7c: mov      r0, r6
1180aa80: bl       #0x1180bb84
1180aa84: cmp      r7, #0x40
1180aa88: mov      lr, r8
1180aa8c: ble      #0x1180abb0
1180aa90: add      sb, r6, #0x40
1180aa94: add      ip, r6, #4
1180aa98: cmp      ip, sb
1180aa9c: beq      #0x1180ab68
1180aaa0: ldr      r1, [r6]
1180aaa4: ldr      r8, [ip]
1180aaa8: mov      r7, r6
1180aaac: mov      r0, ip
1180aab0: ldr      r1, [r1, #4]
1180aab4: ldr      r2, [r8, #4]
1180aab8: cmp      r2, r1
1180aabc: movhs    r2, ip
1180aac0: bhs      #0x1180ab3c
1180aac4: cmp      r7, r0
1180aac8: add      r1, r0, #4
1180aacc: blo      #0x1180aae8
1180aad0: beq      #0x1180ab18
1180aad4: ldr      r2, [r0, #-4]!
1180aad8: cmp      r7, r0
1180aadc: str      r2, [r1, #-4]!
1180aae0: bne      #0x1180aad4
1180aae4: b        #0x1180ab18
1180aae8: sub      r2, r0, r7
1180aaec: cmp      r2, #0
1180aaf0: asrgt    r3, r2, #2
1180aaf4: movgt    r2, #0
1180aaf8: ble      #0x1180ab18
1180aafc: add      sl, r0, r2, lsl #2
1180ab00: add      fp, r1, r2, lsl #2
1180ab04: ldr      sl, [sl, #-4]
1180ab08: subs     r3, r3, #1
1180ab0c: sub      r2, r2, #1
1180ab10: str      sl, [fp, #-4]
1180ab14: bne      #0x1180aafc
1180ab18: str      r8, [r7]
1180ab1c: b        #0x1180ab5c
1180ab20: blmi     #0x1380ab24
1180ab24: andeq    r0, r0, fp, ror #6
1180ab28: andeq    r6, r0, r0, asr #25
1180ab2c: svclt    #0x800000
1180ab30: .word    0xf8000007
1180ab34: ldrdeq   r6, r7, [lr], -r8
1180ab38: ldrdeq   r0, r1, [r0], -r7
1180ab3c: ldr      r1, [r2, #-4]!
1180ab40: ldr      r3, [r8, #4]
1180ab44: ldr      r7, [r1, #4]
1180ab48: cmp      r3, r7
1180ab4c: strlo    r1, [r0]
1180ab50: movlo    r0, r2
1180ab54: blo      #0x1180ab3c
1180ab58: str      r8, [r0]
1180ab5c: add      ip, ip, #4
1180ab60: cmp      ip, sb
1180ab64: bne      #0x1180aaa0
1180ab68: add      r6, r6, #0x40
1180ab6c: cmp      r6, lr
1180ab70: beq      #0x1180ac6c
1180ab74: ldr      r3, [r6]
1180ab78: mov      r1, r6
1180ab7c: sub      r0, r1, #4
1180ab80: ldr      r2, [r1, #-4]
1180ab84: ldr      ip, [r3, #4]
1180ab88: ldr      r7, [r2, #4]
1180ab8c: cmp      ip, r7
1180ab90: strlo    r2, [r1]
1180ab94: movlo    r1, r0
1180ab98: blo      #0x1180ab7c
1180ab9c: add      r6, r6, #4
1180aba0: cmp      r6, lr
1180aba4: str      r3, [r1]
1180aba8: bne      #0x1180ab74
1180abac: b        #0x1180ac6c
1180abb0: add      r7, r6, #4
1180abb4: cmp      r7, lr
1180abb8: beq      #0x1180ac6c
1180abbc: ldr      r3, [r6]
1180abc0: ldr      r2, [r7]
1180abc4: mov      r1, r6
1180abc8: mov      r0, r7
1180abcc: ldr      r3, [r3, #4]
1180abd0: ldr      ip, [r2, #4]
1180abd4: cmp      ip, r3
1180abd8: movhs    ip, r7
1180abdc: bhs      #0x1180ac3c
1180abe0: cmp      r1, r0
1180abe4: add      r3, r0, #4
1180abe8: blo      #0x1180ac04
1180abec: beq      #0x1180ac34
1180abf0: ldr      r8, [r0, #-4]!
1180abf4: cmp      r1, r0
1180abf8: str      r8, [r3, #-4]!
1180abfc: bne      #0x1180abf0
1180ac00: b        #0x1180ac34
1180ac04: sub      ip, r0, r1
1180ac08: cmp      ip, #0
1180ac0c: asrgt    r8, ip, #2
1180ac10: movgt    ip, #0
1180ac14: ble      #0x1180ac34
1180ac18: add      sb, r0, ip, lsl #2
1180ac1c: add      sl, r3, ip, lsl #2
1180ac20: ldr      sb, [sb, #-4]
1180ac24: subs     r8, r8, #1
1180ac28: sub      ip, ip, #1
1180ac2c: str      sb, [sl, #-4]
1180ac30: bne      #0x1180ac18
1180ac34: str      r2, [r1]
1180ac38: b        #0x1180ac60
1180ac3c: ldr      r1, [ip, #-4]
1180ac40: ldr      r3, [r2, #4]
1180ac44: sub      r0, ip, #4
1180ac48: ldr      r8, [r1, #4]
1180ac4c: cmp      r3, r8
1180ac50: strlo    r1, [ip]
1180ac54: movlo    ip, r0
1180ac58: blo      #0x1180ac3c
1180ac5c: str      r2, [ip]
1180ac60: add      r7, r7, #4
1180ac64: cmp      r7, lr
1180ac68: bne      #0x1180abbc
1180ac6c: mov      r6, #0xff
1180ac70: str      r6, [sp, #0x2c]
1180ac74: ldr      r0, [r4, #0xf4]
1180ac78: ldr      sb, [sp, #0x1c0]
1180ac7c: add      r7, r4, #0x30
1180ac80: str      r0, [sp, #0x14]
1180ac84: ldr      r0, [pc, #0x154]  ; =0xfffe
1180ac88: add      fp, r4, #0x3c
1180ac8c: strh     r0, [r4, #0x40]
1180ac90: strh     r0, [r4, #0x42]
1180ac94: ldm      r7, {r7, sl}
1180ac98: cmp      r7, sl
1180ac9c: beq      #0x1180ada8
1180aca0: ldr      r0, [r7]
1180aca4: ldrb     r8, [r0]
1180aca8: cmp      r8, r6
1180acac: beq      #0x1180ad00
1180acb0: cmp      r6, #0xff
1180acb4: beq      #0x1180acd0
1180acb8: add      r0, r4, #0xdc
1180acbc: ldr      r0, [r0, r6, lsl #2]
1180acc0: ldr      r1, [r0]
1180acc4: ldr      r2, [r1, #0xc]
1180acc8: mov      r1, sb
1180accc: blx      r2
1180acd0: add      r0, r4, #0xdc
1180acd4: mov      r3, fp
1180acd8: ldr      r0, [r0, r8, lsl #2]
1180acdc: mov      r2, r6
1180ace0: ldr      r1, [r0]
1180ace4: ldr      ip, [r1, #8]
1180ace8: mov      r1, sb
1180acec: blx      ip
1180acf0: mov      r0, #0xff
1180acf4: mov      r6, r8
1180acf8: str      r0, [sp, #0x2c]
1180acfc: b        #0x1180ad60
1180ad00: cmp      r8, #6
1180ad04: bne      #0x1180ad60
1180ad08: ldr      r0, [r0, #8]
1180ad0c: ldr      r1, [sp, #0x2c]
1180ad10: cmp      r1, r0
1180ad14: beq      #0x1180ad60
1180ad18: ldr      r1, [sp, #0x14]
1180ad1c: cmp      r6, #0xff
1180ad20: strb     r0, [r1, #8]
1180ad24: beq      #0x1180ad40
1180ad28: ldr      r0, [sp, #0x14]
1180ad2c: mov      r1, sb
1180ad30: ldr      r0, [r0]
1180ad34: ldr      r2, [r0, #0xc]
1180ad38: ldr      r0, [sp, #0x14]
1180ad3c: blx      r2
1180ad40: ldr      r0, [sp, #0x14]
1180ad44: mov      r3, fp
1180ad48: mov      r2, r6
1180ad4c: mov      r1, sb
1180ad50: ldr      r0, [r0]
1180ad54: ldr      ip, [r0, #8]
1180ad58: ldr      r0, [sp, #0x14]
1180ad5c: blx      ip
1180ad60: ldr      r1, [r7]
1180ad64: add      r2, r4, #0xdc
1180ad68: mov      r0, sb
1180ad6c: ldr      r2, [r2, r6, lsl #2]
1180ad70: ldr      ip, [r1, #0x18]
1180ad74: mov      r3, fp
1180ad78: blx      ip
1180ad7c: add      r7, r7, #4
1180ad80: cmp      r7, sl
1180ad84: bne      #0x1180aca0
1180ad88: cmp      r6, #0xff
1180ad8c: beq      #0x1180ada8
1180ad90: add      r0, r4, #0xdc
1180ad94: ldr      r0, [r0, r6, lsl #2]
1180ad98: ldr      r1, [r0]
1180ad9c: ldr      r2, [r1, #0xc]
1180ada0: mov      r1, sb
1180ada4: blx      r2
1180ada8: ldr      r0, [pc, #0x34]  ; =0x4acd4
1180adac: ldr      r1, [sp, #0x1c0]
1180adb0: mov      r3, #1
1180adb4: add      r0, r0, r5
1180adb8: add      r2, sp, #0x74
1180adbc: ldr      r0, [r0, #4]
1180adc0: str      r0, [sp, #0x74]
1180adc4: ldr      r0, [pc, #0x1c]  ; =0x4acc8
1180adc8: add      r0, r0, r5
1180adcc: bl       #0x11800750  ; ->ad::SimpleRectDrawer::draw
1180add0: add      sp, sp, #0x19c
1180add4: vpop     {d8, d9, d10, d11}
1180add8: add      sp, sp, #8
1180addc: pop      {r4, r5, r6, r7, r8, sb, sl, fp, pc}
1180ade0: .word    0x0000fffe
1180ade4: ldrdeq   sl, fp, [r4], -r4
1180ade8: andeq    sl, r4, r8, asr #25
1180adec: push     {r4, r5, r6, r7, r8, lr}
1180adf0: mov      r4, r0
1180adf4: sub      sp, sp, #0x20
1180adf8: ldr      r3, [r0, #0x278]
1180adfc: mov      r2, #3
1180ae00: add      r1, r3, #0x1f8
1180ae04: mov      r0, r3
1180ae08: cmp      r0, r1
1180ae0c: ldrbne   ip, [r0, #4]
1180ae10: cmpne    ip, #0
1180ae14: addne    r0, r0, #0xa8
1180ae18: bne      #0x1180ae08
1180ae1c: rsb      r1, r2, r2, lsl #3
1180ae20: mov      r6, #0
1180ae24: add      r1, r1, r1, lsl #1
1180ae28: add      r1, r3, r1, lsl #3
1180ae2c: cmp      r0, r1
1180ae30: bne      #0x1180b03c
1180ae34: bl       #0x118005a8  ; ->ad::lyt::LytDrawSys::GetInst
1180ae38: mov      r7, r0
1180ae3c: ldr      r0, [pc, #0x200]  ; =0x3f634c ad::lyt::Layout::s_pAllocator
1180ae40: add      r5, r4, #0xc
1180ae44: ldr      r1, [r0]
1180ae48: add      r0, r7, #0x400
1180ae4c: add      r0, r0, #0x1f4
1180ae50: cmp      r1, r0
1180ae54: movne    r1, r0
1180ae58: blne     #0x118005b0  ; ->ad::lyt::Initialize
1180ae5c: str      r5, [r7, #0x5f8]
1180ae60: nop      
1180ae64: bl       #0x118005a8  ; ->ad::lyt::LytDrawSys::GetInst
1180ae68: mov      r1, r0
1180ae6c: mov      r0, #0x10000
1180ae70: str      r0, [r1, #0x5fc]
1180ae74: ldr      r0, [pc, #0x1cc]  ; =0xe64f0
1180ae78: add      r1, pc, #0x1cc
1180ae7c: ldr      r0, [r0, r4]
1180ae80: ldr      r0, [r0, #0x44]
1180ae84: ldr      r2, [r0]
1180ae88: ldr      r2, [r2, #0xc]
1180ae8c: blx      r2
1180ae90: ldr      r0, [r4, #0x278]
1180ae94: mov      r2, #0
1180ae98: add      r1, r0, #0x150
1180ae9c: mov      r0, r4
1180aea0: bl       #0x11800758  ; ->msys::MComSys::readLytNum
1180aea4: ldr      r0, [r4, #4]
1180aea8: add      r2, r4, #0xc
1180aeac: add      r3, sp, #4
1180aeb0: mov      r1, #0x7f
1180aeb4: str      r2, [sp]
1180aeb8: stm      r3, {r1, r6}
1180aebc: add      r3, pc, #0x198
1180aec0: ldr      r1, [r4, #0x278]
1180aec4: add      r2, r1, #0x150
1180aec8: add      r1, r4, #0xe9000
1180aecc: add      r1, r1, #0xe0
1180aed0: bl       #0x118005d0  ; ->ad::fw::TaskBase::readLyt
1180aed4: mov      r3, #0x800000
1180aed8: mov      r2, #0
1180aedc: add      r1, r4, #0xc
1180aee0: mov      r0, #0x200
1180aee4: bl       #0x11800760  ; ->_ZnajP10MemAlcBasePKcj
1180aee8: mov      r5, r0
1180aeec: mov      r2, #0
1180aef0: add      r1, pc, #0x174
1180aef4: bl       #0x11800768  ; ->MessageSys::GetPath
1180aef8: ldr      r8, [pc, #0x180]  ; =0x1180c858
1180aefc: mov      r7, sp
1180af00: add      r0, sp, #4
1180af04: ldr      r1, [r8, #4]
1180af08: mov      r2, r1
1180af0c: str      r1, [sp]
1180af10: ldr      r2, [r2, #-0x30]
1180af14: ldr      r1, [r8, #8]
1180af18: str      r1, [sp, r2]
1180af1c: mov      r2, #1
1180af20: mov      r1, r5
1180af24: str      r6, [sp, #4]
1180af28: str      r6, [sp, #0x10]
1180af2c: str      r6, [sp, #0x14]
1180af30: str      r6, [sp, #8]
1180af34: str      r6, [sp, #0xc]
1180af38: bl       #0x11800770  ; ->nn::fs::CTR::MPCore::detail::UserFileSystem::TryOpenFile
1180af3c: tst      r0, #0x80000000
1180af40: movne    r1, pc
1180af44: lsrsne   r2, r0, #0x1f
1180af48: blne     #0x118001a8  ; ->nn::err::CTR::ThrowFatalErrAll
1180af4c: ldr      r0, [r8]
1180af50: mov      r1, r0
1180af54: str      r0, [sp]
1180af58: ldr      r1, [r1, #-0x30]
1180af5c: ldr      r0, [r8, #0xc]
1180af60: str      r0, [r7, r1]
1180af64: add      r1, sp, #0x18
1180af68: add      r0, sp, #4
1180af6c: bl       #0x11800778  ; ->nn::fs::detail::FileBase::TryGetSize
1180af70: mov      r1, pc
1180af74: lsrs     r2, r0, #0x1f
1180af78: blne     #0x118001a8  ; ->nn::err::CTR::ThrowFatalErrAll
1180af7c: ldr      r2, [r4, #0xc]
1180af80: ldr      r7, [sp, #0x18]
1180af84: add      r0, r4, #0xc
1180af88: ldr      r3, [r2, #0xc]
1180af8c: mov      r1, r7
1180af90: mov      r2, #0
1180af94: blx      r3
1180af98: add      r8, r4, #0xe9000
1180af9c: mov      r2, r0
1180afa0: str      r0, [r8, #0x4c]
1180afa4: mov      r3, r7
1180afa8: add      r0, sp, #4
1180afac: add      r1, sp, #0x18
1180afb0: bl       #0x118001b0  ; ->nn::fs::detail::FileBase::TryRead
1180afb4: mov      r1, pc
1180afb8: lsrs     r2, r0, #0x1f
1180afbc: blne     #0x118001a8  ; ->nn::err::CTR::ThrowFatalErrAll
1180afc0: add      r0, r4, #0xe9000
1180afc4: ldr      r1, [r8, #0x4c]
1180afc8: add      r0, r0, #0x50
1180afcc: bl       #0x11800780  ; ->MsgDataAcsrBase::init
1180afd0: ldr      r0, [sp, #4]
1180afd4: bics     r0, r0, #1
1180afd8: beq      #0x1180aff8
1180afdc: ldr      r0, [sp, #4]
1180afe0: tst      r0, #1
1180afe4: blne     #0x118001c0  ; ->nndbgPanic
1180afe8: ldr      r0, [sp, #4]
1180afec: bic      r0, r0, #1
1180aff0: bl       #0x118001c8  ; ->nn::fs::CTR::MPCore::detail::UserFileSystem::CloseFile
1180aff4: str      r6, [sp, #4]
1180aff8: ldr      r0, [sp, #4]
1180affc: bics     r0, r0, #1
1180b000: beq      #0x1180b020
1180b004: ldr      r0, [sp, #4]
1180b008: tst      r0, #1
1180b00c: blne     #0x118001c0  ; ->nndbgPanic
1180b010: ldr      r0, [sp, #4]
1180b014: bic      r0, r0, #1
1180b018: bl       #0x118001c8  ; ->nn::fs::CTR::MPCore::detail::UserFileSystem::CloseFile
1180b01c: str      r6, [sp, #4]
1180b020: mov      r0, r5
1180b024: bl       #0x11800788  ; ->_ZdaPv
1180b028: ldr      r1, [pc, #0x54]  ; =0x1180c000
1180b02c: add      r4, r4, #0xc00
1180b030: add      r4, r4, #0x384
1180b034: ldrd     r0, r1, [r1, #8]
1180b038: stm      r4, {r0, r1}
1180b03c: add      sp, sp, #0x20
1180b040: pop      {r4, r5, r6, r7, r8, pc}
1180b044: eorseq   r6, pc, ip, asr #6
1180b048: strdeq   r6, r7, [lr], -r0
1180b04c: stmdapl  r6, {r0, r2, r3, r6, sl, lr} ^
1180b050: strbvc   r6, [lr, #-0x54d]!
1180b054: stmdavs  r3!, {r0, r6, sb, ip, sp, lr} ^
1180b058: rsbeq    r7, r5, sb, ror #12
1180b05c: cmpmi    pc, #0xc0000014
1180b060: svcmi    #0x535255
1180b064: ldrbmi   r5, [r3, #-0xf52]
1180b068: andeq    r0, r0, r4, asr r0
1180b06c: rsbeq    r0, r5, sp, asr #32
1180b070: rsbseq   r0, r5, lr, rrx
1180b074: rsbeq    r0, sp, lr, lsr #32
1180b078: rsbeq    r0, r2, r3, ror r0
1180b07c: andeq    r0, r0, r4, ror r0
1180b080: orrne    ip, r0, r8, asr r8
1180b084: orrne    ip, r0, r0
1180b088: push     {r4, r5, r6, lr}
1180b08c: mov      r4, r0
1180b090: add      r5, r0, #0x800
1180b094: vpush    {d8}
1180b098: add      r5, r5, #0x44
1180b09c: ldrb     r0, [r0, #0x848]
1180b0a0: cmp      r0, #0
1180b0a4: beq      #0x1180b1cc
1180b0a8: ldr      r0, [pc, #0x124]  ; =0xe64f0
1180b0ac: ldr      r0, [r0, r4]
1180b0b0: ldr      r0, [r0, #0x44]
1180b0b4: ldr      r1, [r0]
1180b0b8: ldr      r1, [r1, #0x10]
1180b0bc: blx      r1
1180b0c0: cmp      r0, #0
1180b0c4: bne      #0x1180b1cc
1180b0c8: add      r0, r4, #0x7d0
1180b0cc: bl       #0x118001d8  ; ->ad::lyt::LytResourceMan::init
1180b0d0: mov      r0, r5
1180b0d4: bl       #0x118001e0  ; ->ad::fw::Resource::getFileData
1180b0d8: mov      r1, r0
1180b0dc: ldr      r2, [pc, #0xf4]  ; =0x1180cbb8
1180b0e0: add      r0, r4, #0x7d0
1180b0e4: bl       #0x118001e8  ; ->ad::lyt::LytResourceMan::registerArc
1180b0e8: add      r0, r4, #0xe9000
1180b0ec: add      r0, r0, #0xe0
1180b0f0: bl       #0x118001e0  ; ->ad::fw::Resource::getFileData
1180b0f4: mov      r1, r0
1180b0f8: add      r2, pc, #0xdc
1180b0fc: add      r0, r4, #0x7d0
1180b100: bl       #0x118001e8  ; ->ad::lyt::LytResourceMan::registerArc
1180b104: mov      r2, #5
1180b108: add      r1, r4, #0x7d0
1180b10c: mov      r0, r5
1180b110: bl       #0x11800790  ; ->msys::MLytNumRes::init
1180b114: add      r0, r4, #0xe9000
1180b118: add      r0, r0, #0x124
1180b11c: add      r1, r4, #0xd3000
1180b120: mov      r2, #0
1180b124: mov      r5, r0
1180b128: bl       #0x118001f0  ; ->msys::MLyt::init
1180b12c: add      r2, pc, #0xac
1180b130: add      r1, r4, #0x7d0
1180b134: mov      r0, r5
1180b138: bl       #0x118001f8  ; ->msys::MLyt::createLyt
1180b13c: add      r6, r4, #0xe9000
1180b140: add      r6, r6, #0x1f0
1180b144: vldr     s16, [pc, #0xa4]  ; =0x0 (0)
1180b148: vldr     s17, [pc, #0xa4]  ; =0xc347cccd (-199.8)
1180b14c: mov      r0, r6
1180b150: bl       #0x11800200  ; ->MoveVBase::stop
1180b154: vstr     s16, [r6, #0x1c]
1180b158: add      r0, r6, #0x20
1180b15c: add      r1, r4, #0xe6000
1180b160: vstmia   r0, {s16, s17}
1180b164: add      r1, r1, #0x4e0
1180b168: ldr      r0, [r6, #0x1c]
1180b16c: str      r0, [r6, #4]!
1180b170: add      r6, r6, #4
1180b174: mov      r0, #0
1180b178: vstmia   r6, {s16, s17}
1180b17c: strb     r0, [r5, #0x141]
1180b180: ldr      r0, [pc, #0x70]  ; =0x401
1180b184: str      r0, [r5, #0x13c]
1180b188: add      r0, r5, #4
1180b18c: ldrd     r2, r3, [r0]
1180b190: str      r3, [r2, #4]
1180b194: ldr      r0, [r5, #4]
1180b198: str      r0, [r3]
1180b19c: adds     r0, r5, #4
1180b1a0: beq      #0x1180b1b8
1180b1a4: ldr      r2, [r1]
1180b1a8: str      r1, [r0, #4]
1180b1ac: str      r2, [r0]
1180b1b0: str      r0, [r2, #4]
1180b1b4: str      r0, [r1]
1180b1b8: ldr      r1, [pc, #0x3c]  ; =0x1180c000
1180b1bc: add      r4, r4, #0xc00
1180b1c0: add      r4, r4, #0x384
1180b1c4: ldrd     r0, r1, [r1, #0x10]
1180b1c8: stm      r4, {r0, r1}
1180b1cc: vpop     {d8}
1180b1d0: pop      {r4, r5, r6, pc}
1180b1d4: strdeq   r6, r7, [lr], -r0
1180b1d8: strhne   ip, [r0, r8]
1180b1dc: andeq    r0, r0, lr, lsr #32
1180b1e0: cmpmi    pc, #0xc0000014
1180b1e4: svcmi    #0x535255
1180b1e8: uqsaxvs  r2, r2, r2
1180b1ec: rsbseq   r7, r4, ip, ror #18
1180b1f0: andeq    r0, r0, r0
1180b1f4: movtgt   ip, #0x7ccd
1180b1f8: andeq    r0, r0, r1, lsl #8
1180b1fc: orrne    ip, r0, r0
1180b200: push     {r4, r5, lr}
1180b204: add      r1, r0, #0xf00
1180b208: mov      r4, r0
1180b20c: vpush    {d8}
1180b210: add      r0, r0, #0xf00
1180b214: ldrsb    r1, [r1, #0xd7]
1180b218: add      r0, r0, #0xcd
1180b21c: sub      sp, sp, #4
1180b220: ldrsb    r0, [r1, r0]
1180b224: mvn      r1, #0
1180b228: add      r0, r4, r0, lsl #2
1180b22c: ldr      r5, [r0, #0xf8c]
1180b230: ldr      r0, [r5]
1180b234: ldr      r2, [r0, #8]
1180b238: mov      r0, r5
1180b23c: blx      r2
1180b240: ldrb     r0, [r5, #0x14]
1180b244: cmp      r0, #0
1180b248: beq      #0x1180b2a8
1180b24c: mov      r0, #0
1180b250: vldr     s16, [pc, #0x60]  ; =0x41800000 (16)
1180b254: rev      r0, r0
1180b258: mov      r5, sp
1180b25c: str      r0, [sp]
1180b260: ldr      r0, [pc, #0x4c]  ; =0x4acd4
1180b264: vmov.f32 s0, s16
1180b268: mov      r1, r5
1180b26c: add      r0, r0, r4
1180b270: bl       #0x11800480  ; ->MoveC::moveFrm
1180b274: ldr      r0, [pc, #0x40]  ; =0x4ad14
1180b278: vmov.f32 s0, s16
1180b27c: mov      r1, r5
1180b280: add      r0, r0, r4
1180b284: bl       #0x11800480  ; ->MoveC::moveFrm
1180b288: ldr      r1, [pc, #0x30]  ; =0x4af14
1180b28c: mov      r0, #1
1180b290: strb     r0, [r1, r4]
1180b294: ldr      r1, [pc, #0x28]  ; =0x1180c000
1180b298: add      r4, r4, #0xc00
1180b29c: add      r4, r4, #0x384
1180b2a0: ldrd     r0, r1, [r1, #0x18]
1180b2a4: stm      r4, {r0, r1}
1180b2a8: add      sp, sp, #4
1180b2ac: vpop     {d8}
1180b2b0: pop      {r4, r5, pc}
1180b2b4: ldrdeq   sl, fp, [r4], -r4
1180b2b8: orrmi    r0, r0, r0
1180b2bc: andeq    sl, r4, r4, lsl sp
1180b2c0: andeq    sl, r4, r4, lsl pc
1180b2c4: orrne    ip, r0, r0
1180b2c8: push     {r4, r5, r6, r7, r8, sb, sl, lr}
1180b2cc: mov      r5, r1
1180b2d0: mov      r1, #0x180000
1180b2d4: mov      r4, r0
1180b2d8: mov      r6, #0
1180b2dc: vpush    {d8}
1180b2e0: sub      sp, sp, #0x18
1180b2e4: add      r3, sp, #0xc
1180b2e8: str      r1, [sp, #8]
1180b2ec: mov      r0, #3
1180b2f0: stm      r3, {r0, r6}
1180b2f4: mov      r2, #0x100000
1180b2f8: str      r6, [sp, #0x14]
1180b2fc: str      r2, [sp, #4]
1180b300: mov      r3, #0x800000
1180b304: mov      r2, #0x200000
1180b308: mov      r1, r5
1180b30c: mov      r0, r4
1180b310: str      r6, [sp]
1180b314: bl       #0x11800798  ; ->msys::MComSys::initBaseSys
1180b318: add      r1, r4, #0xe9000
1180b31c: add      r1, r1, #0xbc
1180b320: mov      r0, r4
1180b324: bl       #0x118007a0  ; ->msys::MComSys::entryPage
1180b328: add      r1, r4, #0xd3000
1180b32c: add      r1, r1, #0xcc
1180b330: mov      r0, #1
1180b334: strb     r6, [r1, #0x14]
1180b338: strb     r6, [r1, #0x15]
1180b33c: strb     r0, [r1, #0x16]
1180b340: ldr      r0, [pc, #0xec]  ; =0xd2fcc
1180b344: mov      r7, #1
1180b348: ldr      r1, [pc, #0xec]  ; =0x27150
1180b34c: add      r0, r0, r4
1180b350: mov      r2, #5
1180b354: strb     r7, [r0, #0x14]
1180b358: strb     r7, [r0, #0x15]
1180b35c: strb     r7, [r0, #0x16]
1180b360: ldr      r0, [pc, #0xd0]  ; =0x98a28
1180b364: add      r0, r0, r4
1180b368: strb     r7, [r1, r0]
1180b36c: add      r0, r0, #0x13000
1180b370: mov      r1, r6
1180b374: add      r0, r0, #0x8b0
1180b378: bl       #0x118007a8  ; ->Prim::enableDepthTest
1180b37c: mov      r3, #0
1180b380: add      r1, r5, #0x400
1180b384: ldr      r8, [pc, #0xb4]  ; =0x1180c398
1180b388: vldr     s16, [r4, #0x278]
1180b38c: add      sb, r4, #0xc
1180b390: mov      sl, #3
1180b394: mov      r2, r3
1180b398: add      r1, r1, #0x15c
1180b39c: mov      r0, #0x20
1180b3a0: bl       #0x11800180  ; ->_ZnwjP10MemAlcBasePKcj
1180b3a4: cmp      r0, #0
1180b3a8: beq      #0x1180b3d8
1180b3ac: ldr      r1, [pc, #0x90]  ; =0x1180c840
1180b3b0: stm      r0, {r1, r6}
1180b3b4: add      r1, r5, #0x400
1180b3b8: vstr     s16, [r0, #8]
1180b3bc: str      sb, [r0, #0xc]!
1180b3c0: add      r0, r0, #4
1180b3c4: add      r1, r1, #0xd4
1180b3c8: stm      r0!, {r8, sl}
1180b3cc: ldm      r1, {r1, r2}
1180b3d0: stm      r0, {r1, r2}
1180b3d4: sub      r0, r0, #0x18
1180b3d8: mov      r1, r0
1180b3dc: add      r0, r5, #0x400
1180b3e0: add      r0, r0, #0xdc
1180b3e4: bl       #0x118007b0  ; ->CtrJobMan::enqueue
1180b3e8: ldr      r1, [pc, #0x58]  ; =0x1180c000
1180b3ec: add      r2, r4, #0xc00
1180b3f0: add      r2, r2, #0x384
1180b3f4: ldrd     r0, r1, [r1]
1180b3f8: stm      r2, {r0, r1}
1180b3fc: mov      r0, r4
1180b400: bl       #0x118007b8  ; ->msys::MComSys::setupCamU
1180b404: mov      r0, r4
1180b408: nop      
1180b40c: bl       #0x118007c0  ; ->msys::MComSys::setupCamL
1180b410: ldr      r0, [pc, #0x34]  ; =0x4ad54
1180b414: ldr      r1, [pc, #0x34]  ; =0x4ae34
1180b418: add      r0, r0, r4
1180b41c: add      r1, r1, r4
1180b420: strb     r7, [r0, #0x31]
1180b424: strb     r7, [r1, #0x31]
1180b428: add      sp, sp, #0x18
1180b42c: vpop     {d8}
1180b430: pop      {r4, r5, r6, r7, r8, sb, sl, pc}
1180b434: andeq    r2, sp, ip, asr #31
1180b438: andeq    r8, sb, r8, lsr #20
1180b43c: andeq    r7, r2, r0, asr r1
1180b440: .word    0x1180c398
1180b444: orrne    ip, r0, r0, asr #16
1180b448: orrne    ip, r0, r0
1180b44c: andeq    sl, r4, r4, asr sp
1180b450: andeq    sl, r4, r4, lsr lr
1180b454: push     {r4, r5, r6, lr}
1180b458: bl       #0x118007c8  ; ->msys::MComSys
1180b45c: ldr      r1, [pc, #0xe4]  ; =0x1180ca44
1180b460: mov      r2, #4
1180b464: str      r1, [r0]
1180b468: add      r1, r0, #0xe9000
1180b46c: add      r0, r0, #0xe9000
1180b470: add      r1, r1, #0x7c
1180b474: add      r0, r0, #0x50
1180b478: bl       #0x118007d0  ; ->MsgDataAcsrBase
1180b47c: ldr      r1, [pc, #0xc8]  ; =0x1180c810
1180b480: mov      r5, #0
1180b484: str      r1, [r0], #0x6c
1180b488: mov      r2, r0
1180b48c: add      r0, r0, #4
1180b490: add      r1, r2, #0xc
1180b494: str      r0, [r0]
1180b498: str      r0, [r0, #4]
1180b49c: str      r1, [r2, #0xc]
1180b4a0: str      r1, [r2, #0x10]
1180b4a4: strb     r5, [r2, #0x14]
1180b4a8: ldr      r1, [pc, #0xa0]  ; =0x1180c9b0
1180b4ac: str      r5, [r2, #0x18]
1180b4b0: add      r0, r2, #0x24
1180b4b4: str      r1, [r2]
1180b4b8: str      r5, [r2, #0x1c]
1180b4bc: str      r5, [r2, #0x20]
1180b4c0: bl       #0x118005f0  ; ->ad::fw::Resource
1180b4c4: add      r0, r0, #0x44
1180b4c8: bl       #0x118058e4
1180b4cc: ldr      r1, [pc, #0x80]  ; =0x3e4580
1180b4d0: add      r2, r0, #0x100
1180b4d4: mvn      r6, #0
1180b4d8: str      r1, [r0], #0x14c
1180b4dc: ldr      r1, [pc, #0x74]  ; =0x1180588c
1180b4e0: strb     r6, [r0], #4
1180b4e4: strh     r5, [r2, #0x4e]
1180b4e8: mov      r3, #0xc
1180b4ec: mov      r2, #0x1c
1180b4f0: str      r5, [r0], #4
1180b4f4: bl       #0x11800518  ; ->__aeabi_vec_ctor_nocookie_nodtor
1180b4f8: ldr      r1, [pc, #0x5c]  ; =0x118012ac
1180b4fc: mov      r3, #0xc
1180b500: mov      r2, #0x10
1180b504: add      r0, r0, #0x15c
1180b508: bl       #0x11800518  ; ->__aeabi_vec_ctor_nocookie_nodtor
1180b50c: sub      r4, r0, #0x2b0
1180b510: mov      r2, #1
1180b514: str      r5, [r4, #0x370]
1180b518: strb     r2, [r4, #0x374]
1180b51c: str      r5, [r4, #0x378]
1180b520: str      r5, [r4, #0x37c]
1180b524: strb     r5, [r4, #0x380]
1180b528: str      r5, [r4, #0x384]
1180b52c: mov      r1, r6
1180b530: sub      r0, r0, #0xc
1180b534: str      r5, [r4, #0x388]
1180b538: bl       #0x118058c8
1180b53c: sub      r0, r4, #0xe9000
1180b540: sub      r0, r0, #0x124
1180b544: pop      {r4, r5, r6, pc}
1180b548: orrne    ip, r0, r4, asr #20
1180b54c: orrne    ip, r0, r0, lsl r8
1180b550: strhne   ip, [r0, r0]
1180b554: eorseq   r4, lr, r0, lsl #11
1180b558: orrne    r5, r0, ip, lsl #17
1180b55c: orrne    r1, r0, ip, lsr #5
1180b560: push     {r4, lr}
1180b564: bl       #0x11805724
1180b568: pop      {r4, lr}
1180b56c: b        #0x11800190  ; ->_ZdlPv
1180b570: ldr      r1, [r0]
1180b574: ldr      r1, [r1, #8]
1180b578: bx       r1
1180b57c: push     {r4, lr}
1180b580: bl       #0x118058e4
1180b584: ldr      r1, [pc, #0x20]  ; =0x3e42dc
1180b588: str      r1, [r0], #0x14c
1180b58c: bl       #0x118007d8  ; ->CellAnime
1180b590: mov      r2, #0xff
1180b594: strb     r2, [r0, #0x12c]
1180b598: strb     r2, [r0, #0x12d]
1180b59c: strb     r2, [r0, #0x12e]
1180b5a0: strb     r2, [r0, #0x12f]
1180b5a4: sub      r0, r0, #0x14c
1180b5a8: pop      {r4, pc}
1180b5ac: ldrsbteq r4, [lr], -ip
1180b5b0: ldr      r1, [pc, #0x14]  ; =0x3e42dc
1180b5b4: push     {r4, lr}
1180b5b8: str      r1, [r0], #0x14c
1180b5bc: bl       #0x118007e0  ; ->CellAnime
1180b5c0: sub      r0, r0, #0x14c
1180b5c4: bl       #0x118059d0
1180b5c8: pop      {r4, pc}
1180b5cc: ldrsbteq r4, [lr], -ip
1180b5d0: mov      r1, #0
1180b5d4: strb     r1, [r0, #0x142]
1180b5d8: bx       lr
1180b5dc: bx       lr
1180b5e0: mov      r1, #1
1180b5e4: strb     r1, [r0, #0x142]
1180b5e8: bx       lr
1180b5ec: bx       lr
1180b5f0: ldr      r1, [pc, #8]
1180b5f4: push     {r4, lr}
1180b5f8: bl       #0x11805688
1180b5fc: pop      {r4, pc}
1180b600: andseq   r0, r1, r5, lsl r0
1180b604: ldr      r1, [pc, #8]
1180b608: push     {r4, lr}
1180b60c: bl       #0x11805688
1180b610: pop      {r4, pc}
1180b614: andseq   r0, r1, r5, lsl r0
1180b618: ldr      r1, [pc, #8]
1180b61c: push     {r4, lr}
1180b620: bl       #0x11805688
1180b624: pop      {r4, pc}
1180b628: andseq   r0, r1, r5, lsl r0
1180b62c: ldr      r1, [pc, #8]
1180b630: push     {r4, lr}
1180b634: bl       #0x11805688
1180b638: pop      {r4, pc}
1180b63c: andseq   r0, r1, r5, lsl r0
1180b640: ldr      r1, [pc, #8]
1180b644: push     {r4, lr}
1180b648: bl       #0x11805688
1180b64c: pop      {r4, pc}
1180b650: andseq   r0, r1, r8, lsl r0
1180b654: push     {r4, lr}
1180b658: bl       #0x118003a0  ; ->ad::ui::UIListWindowPlusLyt
1180b65c: pop      {r4, lr}
1180b660: b        #0x11800190  ; ->_ZdlPv
1180b664: b        #0x118003a0  ; ->ad::ui::UIListWindowPlusLyt
1180b668: mov      r0, #0
1180b66c: bx       lr
1180b670: mov      r0, #0
1180b674: bx       lr
1180b678: push     {r4, r5, r6, r7, lr}
1180b67c: mov      r4, r0
1180b680: vpush    {d8}
1180b684: vmov.f32 s16, s0
1180b688: ldr      r0, [r0]
1180b68c: sub      sp, sp, #4
1180b690: ldr      r1, [r0, #0x24]
1180b694: mov      r0, r4
1180b698: blx      r1
1180b69c: cmp      r0, #0
1180b6a0: beq      #0x1180b6c8
1180b6a4: vmov.f32 s0, s16
1180b6a8: add      r0, r4, #0x14
1180b6ac: bl       #0x118007e8  ; ->MoveVBase::update
1180b6b0: vmov.f32 s0, s16
1180b6b4: add      r0, r4, #0x70
1180b6b8: bl       #0x118007e8  ; ->MoveVBase::update
1180b6bc: vmov.f32 s0, s16
1180b6c0: add      r0, r4, #0xcc
1180b6c4: bl       #0x118007e8  ; ->MoveVBase::update
1180b6c8: ldr      r0, [pc, #0x78]  ; =0x4238d0 gBtn
1180b6cc: mov      r1, #0
1180b6d0: bl       #0x118007f0  ; ->CtrBtn::get
1180b6d4: ldr      r7, [pc, #0x70]  ; =0xff2004
1180b6d8: mov      r1, #2
1180b6dc: bic      r6, r0, r7
1180b6e0: ldr      r0, [pc, #0x60]  ; =0x4238d0 gBtn
1180b6e4: bl       #0x118007f0  ; ->CtrBtn::get
1180b6e8: bic      r5, r0, r7
1180b6ec: ldr      r0, [pc, #0x54]  ; =0x4238d0 gBtn
1180b6f0: mov      r1, #4
1180b6f4: bl       #0x118007f0  ; ->CtrBtn::get
1180b6f8: mov      r1, r0
1180b6fc: mov      r0, #0x140
1180b700: bic      r3, r1, r7
1180b704: ldrsb    r0, [r0, r4]
1180b708: cmp      r0, #0
1180b70c: bne      #0x1180b71c
1180b710: mov      r3, #0
1180b714: mov      r5, r3
1180b718: mov      r6, r3
1180b71c: vmov.f32 s0, s16
1180b720: str      r0, [sp]
1180b724: mov      r2, r5
1180b728: mov      r1, r6
1180b72c: add      r0, r4, #0x14c
1180b730: bl       #0x118007f8  ; ->Message::func
1180b734: mov      r0, #1
1180b738: strb     r0, [r4, #0x142]
1180b73c: add      sp, sp, #4
1180b740: vpop     {d8}
1180b744: pop      {r4, r5, r6, r7, pc}
1180b748: ldrdeq   r3, r4, [r2], #-0x80
1180b74c: rscseq   r2, pc, r4
1180b750: bx       lr
1180b754: ldrb     r2, [r0, #0x141]
1180b758: mov      ip, r1
1180b75c: cmp      r2, #0
1180b760: beq      #0x1180b77c
1180b764: ldr      r2, [pc, #0x14]  ; =0x6ef4
1180b768: add      r1, r0, #0x14c
1180b76c: mov      r3, #0xa
1180b770: ldr      r2, [r2, r0]
1180b774: mov      r0, ip
1180b778: b        #0x11800800  ; ->msys::MRenderQueueBase::enqueueMsg
1180b77c: bx       lr
1180b780: strdeq   r6, r7, [r0], -r4
1180b784: push     {r4, r5, r6, r7, r8, lr}
1180b788: mov      r5, r0
1180b78c: mov      r6, r2
1180b790: ldrb     r0, [r0, #0x141]
1180b794: mov      r7, r1
1180b798: cmp      r0, #0
1180b79c: beq      #0x1180b7dc
1180b7a0: ldr      r0, [r5]
1180b7a4: ldr      r3, [r0, #0x14]
1180b7a8: mov      r0, r5
1180b7ac: blx      r3
1180b7b0: ldr      r4, [r5, #0x148]
1180b7b4: add      r5, r5, #0x144
1180b7b8: cmp      r4, r5
1180b7bc: beq      #0x1180b7dc
1180b7c0: sub      r0, r4, #4
1180b7c4: mov      r2, r6
1180b7c8: mov      r1, r7
1180b7cc: bl       #0x1180b784
1180b7d0: ldr      r4, [r4, #4]
1180b7d4: cmp      r4, r5
1180b7d8: bne      #0x1180b7c0
1180b7dc: pop      {r4, r5, r6, r7, r8, pc}
1180b7e0: push     {r4, lr}
1180b7e4: bl       #0x118059d0
1180b7e8: pop      {r4, lr}
1180b7ec: b        #0x11800190  ; ->_ZdlPv
1180b7f0: ldr      r1, [pc, #0x18]  ; =0x1180cb14
1180b7f4: push     {r4, lr}
1180b7f8: str      r1, [r0], #0x1fc
1180b7fc: bl       #0x118003a0  ; ->ad::ui::UIListWindowPlusLyt
1180b800: sub      r0, r0, #0x1fc
1180b804: bl       #0x118003a8  ; ->msys::MListWndPBase
1180b808: pop      {r4, lr}
1180b80c: b        #0x11800190  ; ->_ZdlPv
1180b810: orrne    ip, r0, r4, lsl fp
1180b814: ldr      r1, [pc, #0x14]  ; =0x1180cb14
1180b818: push     {r4, lr}
1180b81c: str      r1, [r0], #0x1fc
1180b820: bl       #0x118003a0  ; ->ad::ui::UIListWindowPlusLyt
1180b824: pop      {r4, lr}
1180b828: sub      r0, r0, #0x1fc
1180b82c: b        #0x118003a8  ; ->msys::MListWndPBase
1180b830: orrne    ip, r0, r4, lsl fp
1180b834: ldr      r1, [pc, #0x18]  ; =0x1180cb58
1180b838: push     {r4, lr}
1180b83c: str      r1, [r0], #0x1fc
1180b840: bl       #0x118003a0  ; ->ad::ui::UIListWindowPlusLyt
1180b844: sub      r0, r0, #0x1fc
1180b848: bl       #0x118003a8  ; ->msys::MListWndPBase
1180b84c: pop      {r4, lr}
1180b850: b        #0x11800190  ; ->_ZdlPv
1180b854: orrne    ip, r0, r8, asr fp
1180b858: ldr      r1, [pc, #0x14]  ; =0x1180cb58
1180b85c: push     {r4, lr}
1180b860: str      r1, [r0], #0x1fc
1180b864: bl       #0x118003a0  ; ->ad::ui::UIListWindowPlusLyt
1180b868: pop      {r4, lr}
1180b86c: sub      r0, r0, #0x1fc
1180b870: b        #0x118003a8  ; ->msys::MListWndPBase
1180b874: orrne    ip, r0, r8, asr fp
1180b878: mov      r1, r2
1180b87c: b        #0x11800808  ; ->msys::MPageBase::enqueueLowerChr
1180b880: mov      r1, r2
1180b884: b        #0x11800810  ; ->msys::MPageBase::enqueueUpperChr
1180b888: push     {r4, lr}
1180b88c: mov      r4, r0
1180b890: ldr      r0, [pc, #0x24]  ; =0x1180c820
1180b894: ldr      r1, [pc, #0x24]  ; =0x1180b940
1180b898: mov      r3, #1
1180b89c: str      r0, [r4]
1180b8a0: mov      r2, #0x2c
1180b8a4: add      r0, r4, #0x30
1180b8a8: bl       #0x118004f8  ; ->__aeabi_vec_dtor
1180b8ac: mov      r0, r4
1180b8b0: bl       #0x11800520  ; ->MoveVBase
1180b8b4: pop      {r4, lr}
1180b8b8: b        #0x11800190  ; ->_ZdlPv
1180b8bc: orrne    ip, r0, r0, lsr #16
1180b8c0: orrne    fp, r0, r0, asr #18
1180b8c4: push     {r4, lr}
1180b8c8: mov      r4, r0
1180b8cc: ldr      r0, [pc, #0x20]  ; =0x1180c820
1180b8d0: ldr      r1, [pc, #0x20]  ; =0x1180b940
1180b8d4: mov      r3, #1
1180b8d8: str      r0, [r4]
1180b8dc: mov      r2, #0x2c
1180b8e0: add      r0, r4, #0x30
1180b8e4: bl       #0x118004f8  ; ->__aeabi_vec_dtor
1180b8e8: mov      r0, r4
1180b8ec: pop      {r4, lr}
1180b8f0: b        #0x11800520  ; ->MoveVBase
1180b8f4: orrne    ip, r0, r0, lsr #16
1180b8f8: orrne    fp, r0, r0, asr #18
1180b8fc: push     {r4, lr}
1180b900: bl       #0x11800818  ; ->MoveWorkF
1180b904: mov      r1, r0
1180b908: ldr      r0, [pc, #0x18]  ; =0x1180c830
1180b90c: vldr     s0, [pc, #0x18]  ; =0x0 (0)
1180b910: str      r0, [r1]
1180b914: vstr     s0, [r1, #0x20]
1180b918: vstr     s0, [r1, #0x24]
1180b91c: vstr     s0, [r1, #0x28]
1180b920: mov      r0, r1
1180b924: pop      {r4, pc}
1180b928: orrne    ip, r0, r0, lsr r8
1180b92c: andeq    r0, r0, r0
1180b930: push     {r4, lr}
1180b934: bl       #0x11800820  ; ->MoveWorkF
1180b938: pop      {r4, lr}
1180b93c: b        #0x11800190  ; ->_ZdlPv
1180b940: b        #0x11800820  ; ->MoveWorkF
1180b944: add      r0, r0, #4
1180b948: b        #0x11800778  ; ->nn::fs::detail::FileBase::TryGetSize
1180b94c: ldrd     r0, r1, [r0, #8]
1180b950: bx       lr
1180b954: add      r0, r0, #8
1180b958: ldm      r0, {r0, r2}
1180b95c: stm      r1, {r0, r2}
1180b960: mov      r0, #0
1180b964: bx       lr
1180b968: str      lr, [sp, #-4]!
1180b96c: sub      sp, sp, #0xc
1180b970: mov      r1, sp
1180b974: add      r0, r0, #4
1180b978: bl       #0x11800778  ; ->nn::fs::detail::FileBase::TryGetSize
1180b97c: mov      r1, pc
1180b980: lsrs     r2, r0, #0x1f
1180b984: blne     #0x118001a8  ; ->nn::err::CTR::ThrowFatalErrAll
1180b988: ldrd     r0, r1, [sp]
1180b98c: add      sp, sp, #0xc
1180b990: pop      {pc}
1180b994: push     {r4, r5, r6, lr}
1180b998: mov      r5, r1
1180b99c: ldr      r1, [r0]
1180b9a0: mov      r4, r2
1180b9a4: ldr      r1, [r1, #8]
1180b9a8: blx      r1
1180b9ac: and      r0, r0, r4
1180b9b0: cmp      r0, r5
1180b9b4: moveq    r0, #1
1180b9b8: movne    r0, #0
1180b9bc: pop      {r4, r5, r6, pc}
1180b9c0: mov      r0, #0
1180b9c4: bx       lr
1180b9c8: ldrb     r0, [r1, #0x12]
1180b9cc: cmp      r0, #0
1180b9d0: movne    r0, #1
1180b9d4: bx       lr
1180b9d8: mov      r0, #2
1180b9dc: bx       lr
1180b9e0: mov      r0, #7
1180b9e4: bx       lr

<Colosseum:nnroControlObject_>  # Colosseum:nnroControlObject_
1180b9e8: ldr      r2, [pc, #0x80]  ; =0x118144b8
1180b9ec: cmp      r1, #5
1180b9f0: push     {r4, lr}
1180b9f4: ldrlo    pc, [pc, r1, lsl #2]
1180b9f8: b        #0x1180ba54
1180b9fc: orrne    fp, r0, r0, lsl sl
1180ba00: orrne    fp, r0, r8, lsl sl
1180ba04: orrne    fp, r0, r0, lsr #20
1180ba08: orrne    fp, r0, ip, lsr #20
1180ba0c: orrne    fp, r0, ip, lsr sl
1180ba10: ldr      r1, [pc, #0x5c]  ; =0x0
1180ba14: b        #0x1180ba24
1180ba18: str      r0, [r2]
1180ba1c: b        #0x1180ba4c
1180ba20: ldr      r1, [r2]
1180ba24: str      r1, [r0]
1180ba28: b        #0x1180ba4c
1180ba2c: ldr      r1, [pc, #0x44]  ; =0x1180bf2c
1180ba30: str      r1, [r0]
1180ba34: ldr      r1, [pc, #0x40]  ; =0x1180bf2c
1180ba38: b        #0x1180ba48
1180ba3c: ldr      r1, [pc, #0x3c]  ; =0x1180d5c0
1180ba40: str      r1, [r0]
1180ba44: ldr      r1, [pc, #0x38]  ; =0x1180d5c0
1180ba48: str      r1, [r0, #4]
1180ba4c: mov      r0, #0
1180ba50: pop      {r4, pc}
1180ba54: ldr      r0, [pc, #0x2c]  ; =0x30000000
1180ba58: mov      r0, r0
1180ba5c: ldr      r0, [pc, #0x28]  ; =0x30000027
1180ba60: nop      
1180ba64: mov      r0, r0
1180ba68: ldr      r0, [pc, #0x20]  ; =0xd8e12c21
1180ba6c: pop      {r4, pc}
1180ba70: strhne   r4, [r1, r8]
1180ba74: andeq    r0, r0, r0
1180ba78: orrne    fp, r0, ip, lsr #30
1180ba7c: orrne    fp, r0, ip, lsr #30
1180ba80: orrne    sp, r0, r0, asr #11
1180ba84: orrne    sp, r0, r0, asr #11
1180ba88: andlo    r0, r0, r0
1180ba8c: andlo    r0, r0, r7, lsr #32
1180ba90: stmle    r1!, {r0, r5, sl, fp, sp} ^
1180ba94: push     {r3, r4, r5, r6, r7, r8, sb, lr}
1180ba98: mov      r5, r0
1180ba9c: ldr      r6, [r0, #8]
1180baa0: ldr      r0, [r0, #0x14]
1180baa4: ldr      r4, [r5, #0x10]
1180baa8: add      r7, r4, r0, lsl #3
1180baac: cmp      r4, r7
1180bab0: movne    r8, #0
1180bab4: beq      #0x1180bb3c
1180bab8: ldrb     r0, [r4, #4]
1180babc: cmp      r0, #1
1180bac0: beq      #0x1180bad8
1180bac4: cmp      r0, #0x12
1180bac8: beq      #0x1180baf4
1180bacc: cmp      r0, #0x13
1180bad0: beq      #0x1180bb14
1180bad4: b        #0x1180bb2c
1180bad8: ldr      r1, [r4]
1180badc: mov      r2, #0
1180bae0: mov      r0, r6
1180bae4: bl       #0x11800828  ; ->ad::fw::FileContext::initSingleFile
1180bae8: nop      
1180baec: nop      
1180baf0: b        #0x1180bb2c
1180baf4: ldr      r2, [r5, #0xc]
1180baf8: ldr      r1, [r4]
1180bafc: mov      r3, #0
1180bb00: mov      r0, r6
1180bb04: bl       #0x11800830  ; ->ad::fw::FileContext::initArcFile
1180bb08: nop      
1180bb0c: nop      
1180bb10: b        #0x1180bb2c
1180bb14: str      r8, [sp]
1180bb18: ldr      r1, [r4]
1180bb1c: ldr      r2, [r5, #0xc]
1180bb20: add      r3, r5, #0x18
1180bb24: mov      r0, r6
1180bb28: bl       #0x11800838  ; ->ad::fw::FileContext::initCAArcFile
1180bb2c: add      r4, r4, #8
1180bb30: cmp      r4, r7
1180bb34: add      r6, r6, #0xa8
1180bb38: bne      #0x1180bab8
1180bb3c: pop      {r3, r4, r5, r6, r7, r8, sb, pc}
1180bb40: b        #0x11800190  ; ->_ZdlPv
1180bb44: bx       lr
1180bb48: push     {r4, lr}
1180bb4c: mov      r4, r0
1180bb50: bl       #0x11800840  ; ->msys::MCursorBase::init
1180bb54: mov      r2, #0
1180bb58: add      r0, r4, #0x30
1180bb5c: mov      r1, #3
1180bb60: subs     r1, r1, #1
1180bb64: str      r2, [r0], #4
1180bb68: bne      #0x1180bb60
1180bb6c: pop      {r4, pc}
1180bb70: push     {r4, lr}
1180bb74: bl       #0x11800670  ; ->msys::MCursorBase
1180bb78: pop      {r4, lr}
1180bb7c: b        #0x11800190  ; ->_ZdlPv
1180bb80: b        #0x11800670  ; ->msys::MCursorBase
1180bb84: push     {r0, r1, r2, r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
1180bb88: sub      sp, sp, #4
1180bb8c: mov      r4, r0
1180bb90: sub      r0, r1, r4
1180bb94: cmp      r0, #0x40
1180bb98: mov      r5, r2
1180bb9c: ble      #0x1180be90
1180bba0: cmp      r5, #0
1180bba4: beq      #0x1180bbf8
1180bba8: sub      r2, r1, r4
1180bbac: mov      r3, r1
1180bbb0: asr      r2, r2, #2
1180bbb4: mov      r0, r4
1180bbb8: add      r2, r2, r2, lsr #31
1180bbbc: asr      ip, r2, #1
1180bbc0: ldr      r2, [r4]
1180bbc4: add      r6, r4, ip, lsl #2
1180bbc8: ldr      lr, [r6]
1180bbcc: ldr      ip, [r2, #4]
1180bbd0: ldr      r2, [lr, #4]
1180bbd4: ldr      lr, [r1, #-4]
1180bbd8: cmp      ip, r2
1180bbdc: ldr      lr, [lr, #4]
1180bbe0: bhs      #0x1180be98
1180bbe4: cmp      r2, lr
1180bbe8: blo      #0x1180beb4
1180bbec: cmp      ip, lr
1180bbf0: blo      #0x1180beb0
1180bbf4: b        #0x1180bea0
1180bbf8: sub      sb, r1, r4
1180bbfc: cmp      sb, #8
1180bc00: mov      r5, r4
1180bc04: mov      lr, r1
1180bc08: blt      #0x1180bcd8
1180bc0c: asr      r2, sb, #2
1180bc10: sub      r0, r2, #2
1180bc14: add      r0, r0, r0, lsr #31
1180bc18: asr      r6, r0, #1
1180bc1c: mov      r0, r6
1180bc20: mov      r8, #2
1180bc24: ldr      r7, [r4, r0, lsl #2]
1180bc28: add      r1, r8, r0, lsl #1
1180bc2c: cmp      r1, r2
1180bc30: bge      #0x1180bc68
1180bc34: add      ip, r4, r1, lsl #2
1180bc38: ldr      r3, [r4, r1, lsl #2]
1180bc3c: ldr      ip, [ip, #-4]
1180bc40: ldr      r3, [r3, #4]
1180bc44: ldr      ip, [ip, #4]
1180bc48: cmp      r3, ip
1180bc4c: sublo    r1, r1, #1
1180bc50: ldr      r3, [r4, r1, lsl #2]
1180bc54: str      r3, [r4, r0, lsl #2]
1180bc58: mov      r0, r1
1180bc5c: add      r1, r8, r0, lsl #1
1180bc60: cmp      r1, r2
1180bc64: blt      #0x1180bc34
1180bc68: nop      
1180bc6c: bne      #0x1180bc80
1180bc70: add      r3, r4, r1, lsl #2
1180bc74: ldr      ip, [r3, #-4]
1180bc78: str      ip, [r4, r0, lsl #2]
1180bc7c: sub      r0, r1, #1
1180bc80: sub      r3, r0, #1
1180bc84: mov      r1, r4
1180bc88: add      r3, r3, r3, lsr #31
1180bc8c: mov      r8, r6
1180bc90: asr      r3, r3, #1
1180bc94: b        #0x1180bcac
1180bc98: str      ip, [r1, r0, lsl #2]
1180bc9c: mov      r0, r3
1180bca0: sub      r3, r3, #1
1180bca4: add      r3, r3, r3, lsr #31
1180bca8: asr      r3, r3, #1
1180bcac: cmp      r0, r8
1180bcb0: ble      #0x1180bcc8
1180bcb4: ldr      ip, [r1, r3, lsl #2]
1180bcb8: ldr      fp, [r7, #4]
1180bcbc: ldr      sl, [ip, #4]
1180bcc0: cmp      sl, fp
1180bcc4: blo      #0x1180bc98
1180bcc8: cmp      r6, #0
1180bccc: subne    r6, r8, #1
1180bcd0: str      r7, [r4, r0, lsl #2]
1180bcd4: bne      #0x1180bc1c
1180bcd8: cmp      lr, lr
1180bcdc: mov      r2, lr
1180bce0: movlo    r8, #2
1180bce4: bhs      #0x1180bdbc
1180bce8: ldr      r6, [r2]
1180bcec: ldr      r1, [r5]
1180bcf0: ldr      r0, [r6, #4]
1180bcf4: ldr      r3, [r1, #4]
1180bcf8: cmp      r0, r3
1180bcfc: bhs      #0x1180bdb0
1180bd00: asr      r3, sb, #2
1180bd04: mov      r0, #0
1180bd08: str      r1, [r2]
1180bd0c: cmp      r3, #2
1180bd10: mov      r7, r0
1180bd14: mov      r1, #2
1180bd18: ble      #0x1180bd50
1180bd1c: add      ip, r5, r1, lsl #2
1180bd20: ldr      r4, [r5, r1, lsl #2]
1180bd24: ldr      ip, [ip, #-4]
1180bd28: ldr      r4, [r4, #4]
1180bd2c: ldr      ip, [ip, #4]
1180bd30: cmp      r4, ip
1180bd34: sublo    r1, r1, #1
1180bd38: ldr      ip, [r5, r1, lsl #2]
1180bd3c: str      ip, [r5, r0, lsl #2]
1180bd40: mov      r0, r1
1180bd44: add      r1, r8, r0, lsl #1
1180bd48: cmp      r1, r3
1180bd4c: blt      #0x1180bd1c
1180bd50: cmp      r1, r3
1180bd54: bne      #0x1180bd68
1180bd58: add      r3, r5, r1, lsl #2
1180bd5c: ldr      ip, [r3, #-4]
1180bd60: str      ip, [r5, r0, lsl #2]
1180bd64: sub      r0, r1, #1
1180bd68: sub      r3, r0, #1
1180bd6c: mov      r1, r5
1180bd70: add      r3, r3, r3, lsr #31
1180bd74: asr      r3, r3, #1
1180bd78: b        #0x1180bd90
1180bd7c: str      ip, [r1, r0, lsl #2]
1180bd80: mov      r0, r3
1180bd84: sub      r3, r3, #1
1180bd88: add      r3, r3, r3, lsr #31
1180bd8c: asr      r3, r3, #1
1180bd90: cmp      r0, r7
1180bd94: ble      #0x1180bdac
1180bd98: ldr      ip, [r1, r3, lsl #2]
1180bd9c: ldr      sl, [r6, #4]
1180bda0: ldr      r4, [ip, #4]
1180bda4: cmp      r4, sl
1180bda8: blo      #0x1180bd7c
1180bdac: str      r6, [r5, r0, lsl #2]
1180bdb0: add      r2, r2, #4
1180bdb4: cmp      r2, lr
1180bdb8: blo      #0x1180bce8
1180bdbc: cmp      sb, #4
1180bdc0: movgt    r6, #2
1180bdc4: ble      #0x1180be90
1180bdc8: cmp      r5, lr
1180bdcc: beq      #0x1180be80
1180bdd0: sub      r0, lr, #4
1180bdd4: ldr      r1, [r5]
1180bdd8: sub      r0, r0, r5
1180bddc: ldr      r3, [lr, #-4]
1180bde0: asr      r7, r0, #2
1180bde4: mov      r2, #0
1180bde8: str      r1, [lr, #-4]
1180bdec: cmp      r7, #2
1180bdf0: mov      r1, r5
1180bdf4: mov      ip, r2
1180bdf8: mov      r0, #2
1180bdfc: ble      #0x1180be34
1180be00: add      r4, r1, r0, lsl #2
1180be04: ldr      r8, [r1, r0, lsl #2]
1180be08: ldr      r4, [r4, #-4]
1180be0c: ldr      r8, [r8, #4]
1180be10: ldr      r4, [r4, #4]
1180be14: cmp      r8, r4
1180be18: sublo    r0, r0, #1
1180be1c: ldr      r4, [r1, r0, lsl #2]
1180be20: str      r4, [r1, r2, lsl #2]
1180be24: mov      r2, r0
1180be28: add      r0, r6, r2, lsl #1
1180be2c: cmp      r0, r7
1180be30: blt      #0x1180be00
1180be34: cmp      r0, r7
1180be38: bne      #0x1180be4c
1180be3c: add      r4, r1, r0, lsl #2
1180be40: ldr      r4, [r4, #-4]
1180be44: str      r4, [r1, r2, lsl #2]
1180be48: sub      r2, r0, #1
1180be4c: sub      r0, r2, #1
1180be50: cmp      r2, ip
1180be54: add      r0, r0, r0, lsr #31
1180be58: asr      r0, r0, #1
1180be5c: ble      #0x1180be7c
1180be60: ldr      r4, [r1, r0, lsl #2]
1180be64: ldr      r8, [r3, #4]
1180be68: ldr      r7, [r4, #4]
1180be6c: cmp      r7, r8
1180be70: strlo    r4, [r1, r2, lsl #2]
1180be74: movlo    r2, r0
1180be78: blo      #0x1180be4c
1180be7c: str      r3, [r5, r2, lsl #2]
1180be80: sub      lr, lr, #4
1180be84: sub      r0, lr, r5
1180be88: cmp      r0, #4
1180be8c: bgt      #0x1180bdc8
1180be90: add      sp, sp, #0x14
1180be94: pop      {r4, r5, r6, r7, r8, sb, sl, fp, pc}
1180be98: cmp      ip, lr
1180be9c: bhs      #0x1180bea8
1180bea0: mov      r6, r0
1180bea4: b        #0x1180beb4
1180bea8: cmp      lr, r2
1180beac: bls      #0x1180beb4
1180beb0: sub      r6, r1, #4
1180beb4: ldr      lr, [r6]
1180beb8: ldr      ip, [lr, #4]
1180bebc: ldr      r2, [r0]
1180bec0: ldr      r2, [r2, #4]
1180bec4: cmp      r2, ip
1180bec8: addlo    r0, r0, #4
1180becc: blo      #0x1180bebc
1180bed0: ldr      r2, [r3, #-4]!
1180bed4: ldr      r2, [r2, #4]
1180bed8: cmp      ip, r2
1180bedc: blo      #0x1180bed0
1180bee0: cmp      r3, r0
1180bee4: bhi      #0x1180bf18
1180bee8: mov      r6, r0
1180beec: add      r0, r5, r5, lsr #31
1180bef0: asr      r5, r0, #1
1180bef4: mov      r2, r5
1180bef8: mov      r0, r6
1180befc: bl       #0x1180bb84
1180bf00: sub      r0, r6, r4
1180bf04: cmp      r0, #0x40
1180bf08: mov      r1, r6
1180bf0c: bgt      #0x1180bba0
1180bf10: add      sp, sp, #0x14
1180bf14: pop      {r4, r5, r6, r7, r8, sb, sl, fp, pc}
1180bf18: ldr      ip, [r3]
1180bf1c: ldr      r2, [r0]
1180bf20: str      ip, [r0], #4
1180bf24: str      r2, [r3]
1180bf28: b        #0x1180beb8
