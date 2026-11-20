// fps60 TG decompiled C: 3dx_v12.code.bin module Colosseum part 1 (Ghidra 12.2, ARM:LE:32:v6:hardfp)
// Addresses: static = runtime address; CRO = fixed analysis base (crolink.py), NOT runtime.

// FUNC 0x11800180 ->operator.new (Colosseum)
//   size 0x4 | file Colosseum+0x180 | callers(4) 0x11800848 0x1180b2c8 0x11809ce8 0x11800888
// veneer/thunk -> 0x00287d40 operator.new (static)

// FUNC 0x11800188 ->TaskMan::entry (Colosseum)
//   size 0x4 | file Colosseum+0x188 | callers(1) 0x11800848
// veneer/thunk -> 0x00287b18 TaskMan::entry (static)

// FUNC 0x11800190 ->operator.delete (Colosseum)
//   size 0x4 | file Colosseum+0x190 | callers(19) 0x11801158 0x11800888 0x1180bb40 0x118010e0 0x11801204 0x11802d48 0x118084cc 0x11808908 ...
// veneer/thunk -> 0x00286514 operator.delete (static)

// FUNC 0x11800198 ->MsgDataAcsrBase::~MsgDataAcsrBase (Colosseum)
//   size 0x4 | file Colosseum+0x198 | callers(3) 0x118010e0 0x118010f0 0x11805724
// veneer/thunk -> 0x0026fdb4 MsgDataAcsrBase::~MsgDataAcsrBase (static)

// FUNC 0x118001a0 ->nn::fs::detail::FileBase::TrySetPosition (Colosseum)
//   size 0x4 | file Colosseum+0x1a0 | callers(2) 0x11801160 0x11801184
// veneer/thunk -> 0x0027ec28 nn::fs::detail::FileBase::TrySetPosition (static)

// FUNC 0x118001a8 ->nn::err::CTR::ThrowFatalErrAll (Colosseum)
//   size 0x4 | file Colosseum+0x1a8 | callers(5) 0x1180118c 0x1180b968 0x11801160 0x118011b8 0x1180adec
// veneer/thunk -> 0x00286530 nn::err::CTR::ThrowFatalErrAll (static)

// FUNC 0x118001b0 ->nn::fs::detail::FileBase::TryRead (Colosseum)
//   size 0x4 | file Colosseum+0x1b0 | callers(3) 0x1180118c 0x118011e4 0x1180adec
// veneer/thunk -> 0x00286488 nn::fs::detail::FileBase::TryRead (static)

// FUNC 0x118001b8 ->nn::fs::detail::FileBase::TrySeek (Colosseum)
//   size 0x4 | file Colosseum+0x1b8 | callers(2) 0x118011b8 0x118011ec
// veneer/thunk -> 0x002854d0 nn::fs::detail::FileBase::TrySeek (static)

// FUNC 0x118001c0 ->nndbgPanic (Colosseum)
//   size 0x4 | file Colosseum+0x1c0 | callers(3) 0x11801204 0x11801244 0x1180adec
// veneer/thunk -> 0x0028642c nndbgPanic (static)

// FUNC 0x118001c8 ->nn::fs::CTR::MPCore::detail::UserFileSystem::CloseFile (Colosseum)
//   size 0x4 | file Colosseum+0x1c8 | callers(3) 0x11801204 0x11801244 0x1180adec
// veneer/thunk -> 0x00286410 nn::fs::CTR::MPCore::detail::UserFileSystem::CloseFile (static)

// FUNC 0x118001d0 ->__c89vswprintf (Colosseum)
//   size 0x4 | file Colosseum+0x1d0 | callers(1) 0x11801280
// veneer/thunk -> 0x0010005c __c89vswprintf (static)

// FUNC 0x118001d8 ->ad::lyt::LytResourceMan::init (Colosseum)
//   size 0x4 | file Colosseum+0x1d8 | callers(3) 0x11809074 0x118012ec 0x1180b088
// veneer/thunk -> 0x00250d1c ad::lyt::LytResourceMan::init (static)

// FUNC 0x118001e0 ->ad::fw::Resource::getFileData (Colosseum)
//   size 0x4 | file Colosseum+0x1e0 | callers(2) 0x118012ec 0x1180b088
// veneer/thunk -> 0x00251d10 ad::fw::Resource::getFileData (static)

// FUNC 0x118001e8 ->ad::lyt::LytResourceMan::registerArc (Colosseum)
//   size 0x4 | file Colosseum+0x1e8 | callers(2) 0x118012ec 0x1180b088
// veneer/thunk -> 0x0015c910 ad::lyt::LytResourceMan::registerArc (static)

// FUNC 0x118001f0 ->msys::MLyt::init (Colosseum)
//   size 0x4 | file Colosseum+0x1f0 | callers(2) 0x118012ec 0x1180b088
// veneer/thunk -> 0x0032c3a0 msys::MLyt::init (static)

// FUNC 0x118001f8 ->msys::MLyt::createLyt (Colosseum)
//   size 0x4 | file Colosseum+0x1f8 | callers(2) 0x118012ec 0x1180b088
// veneer/thunk -> 0x0032c78c msys::MLyt::createLyt (static)

// FUNC 0x11800200 ->MoveVBase::stop (Colosseum)
//   size 0x4 | file Colosseum+0x200 | callers(7) 0x118012ec 0x11806968 0x11805cbc 0x1180657c 0x1180b088 0x11807390 0x11807a84
// veneer/thunk -> 0x00259dd8 MoveVBase::stop (static)

// FUNC 0x11800208 ->msys::MLyt::build (Colosseum)
//   size 0x4 | file Colosseum+0x208 | callers(1) 0x118012ec
// veneer/thunk -> 0x0032c460 msys::MLyt::build (static)

// FUNC 0x11800210 ->msys::MLyt::createLyt (Colosseum)
//   size 0x4 | file Colosseum+0x210 | callers(1) 0x118012ec
// veneer/thunk -> 0x0032c8c0 msys::MLyt::createLyt (static)

// FUNC 0x11800218 ->msys::MListWndPBase::setEnableInput (Colosseum)
//   size 0x4 | file Colosseum+0x218 | callers(2) 0x118012ec 0x118068b4
// veneer/thunk -> 0x00328638 msys::MListWndPBase::setEnableInput (static)

// FUNC 0x11800220 ->msys::MCellAnime::init (Colosseum)
//   size 0x4 | file Colosseum+0x220 | callers(1) 0x118012ec
// veneer/thunk -> 0x002079d8 msys::MCellAnime::init (static)

// FUNC 0x11800228 ->msys::MLyt::attachMChr (Colosseum)
//   size 0x4 | file Colosseum+0x228 | callers(4) 0x118012ec 0x118019c0 0x11807390 0x11807a84
// veneer/thunk -> 0x00207468 msys::MLyt::attachMChr (static)

// FUNC 0x11800230 ->msys::MDfxChr::init (Colosseum)
//   size 0x4 | file Colosseum+0x230 | callers(3) 0x118012ec 0x11807390 0x11807a84
// veneer/thunk -> 0x003309c0 msys::MDfxChr::init (static)

// FUNC 0x11800238 ->Backup::errorCode (Colosseum)
//   size 0x4 | file Colosseum+0x238 | callers(2) 0x118018b4 0x118029c0
// veneer/thunk -> 0x002063b8 Backup::errorCode (static)

// FUNC 0x11800240 ->Backup::isBusyFormat (Colosseum)
//   size 0x4 | file Colosseum+0x240 | callers(1) 0x118018b4
// veneer/thunk -> 0x00339378 Backup::isBusyFormat (static)

// FUNC 0x11800248 ->Backup::mount (Colosseum)
//   size 0x4 | file Colosseum+0x248 | callers(1) 0x118018b4
// veneer/thunk -> 0x00339d0c Backup::mount (static)

// FUNC 0x11800250 ->Backup::rewriteSaveData (Colosseum)
//   size 0x4 | file Colosseum+0x250 | callers(1) 0x118018b4
// veneer/thunk -> 0x00339c0c Backup::rewriteSaveData (static)

// FUNC 0x11800258 ->CtrFS::unmountSaveData (Colosseum)
//   size 0x4 | file Colosseum+0x258 | callers(1) 0x118018b4
// veneer/thunk -> 0x00207f3c CtrFS::unmountSaveData (static)

// FUNC 0x11800260 ->Backup::format (Colosseum)
//   size 0x4 | file Colosseum+0x260 | callers(2) 0x11807248 0x118018b4
// veneer/thunk -> 0x00339d34 Backup::format (static)

// FUNC 0x11800268 ->GameMain::Back (Colosseum)
//   size 0x4 | file Colosseum+0x268 | callers(2) 0x1180a000 0x118019b8
// veneer/thunk -> 0x0033e354 GameMain::Back (static)

// FUNC 0x11800270 ->ad::lyt::LytNumReel3::InitParam::InitParam (Colosseum)
//   size 0x4 | file Colosseum+0x270 | callers(3) 0x118012ec 0x118019c0 0x118020bc
// veneer/thunk -> 0x00256194 ad::lyt::LytNumReel3::InitParam::InitParam (static)

// FUNC 0x11800278 ->msys::MLytNumRes::set (Colosseum)
//   size 0x4 | file Colosseum+0x278 | callers(3) 0x118012ec 0x118019c0 0x118020bc
// veneer/thunk -> 0x00207594 msys::MLytNumRes::set (static)

// FUNC 0x11800280 ->msys::MLytNum::init (Colosseum)
//   size 0x4 | file Colosseum+0x280 | callers(3) 0x118012ec 0x118019c0 0x118020bc
// veneer/thunk -> 0x003316b8 msys::MLytNum::init (static)

// FUNC 0x11800288 ->MessageSimple::init (Colosseum)
//   size 0x4 | file Colosseum+0x288 | callers(2) 0x118012ec 0x118019c0
// veneer/thunk -> 0x002736b4 MessageSimple::init (static)

// FUNC 0x11800290 ->LMS_GetTextIndexByLabel (Colosseum)
//   size 0x4 | file Colosseum+0x290 | callers(11) 0x118012ec 0x118019c0 0x118020bc 0x11802ab4 0x11805e48 0x11806ab4 0x1180229c 0x118061f4 ...
// veneer/thunk -> 0x0027616c LMS_GetTextIndexByLabel (static)

// FUNC 0x11800298 ->LMS_GetText (Colosseum)
//   size 0x4 | file Colosseum+0x298 | callers(10) 0x118012ec 0x118019c0 0x11802ab4 0x11805e48 0x11806ab4 0x1180229c 0x118061f4 0x118023e8 ...
// veneer/thunk -> 0x0027660c LMS_GetText (static)

// FUNC 0x118002a0 ->msys::MMsg::playStr (Colosseum)
//   size 0x4 | file Colosseum+0x2a0 | callers(6) 0x118012ec 0x118019c0 0x118061f4 0x11805e48 0x11806e7c 0x11804fdc
// veneer/thunk -> 0x0032ce0c msys::MMsg::playStr (static)

// FUNC 0x118002a8 ->MessageWriter::setFontColor (Colosseum)
//   size 0x4 | file Colosseum+0x2a8 | callers(2) 0x118012ec 0x118019c0
// veneer/thunk -> 0x00270f0c MessageWriter::setFontColor (static)

// FUNC 0x118002b0 ->ad::lyt::LytAnim::init (Colosseum)
//   size 0x4 | file Colosseum+0x2b0 | callers(9) 0x118012ec 0x118019c0 0x118020bc 0x11802ab4 0x11805eb0 0x11805fa4 0x1180854c 0x1180449c ...
// veneer/thunk -> 0x00264f04 ad::lyt::LytAnim::init (static)

// FUNC 0x118002b8 ->ad::lyt::AnimTransform::GetFrameSize (Colosseum)
//   size 0x4 | file Colosseum+0x2b8 | callers(6) 0x118012ec 0x118019c0 0x1180854c 0x118061f4 0x11806474 0x11807d88
// veneer/thunk -> 0x0026fe38 ad::lyt::AnimTransform::GetFrameSize (static)

// FUNC 0x118002c0 ->ad::lyt::LytAnim::stopAndSetFrm (Colosseum)
//   size 0x4 | file Colosseum+0x2c0 | callers(15) 0x118012ec 0x118019c0 0x118020bc 0x11805eb0 0x11805fa4 0x1180854c 0x1180268c 0x118061f4 ...
// veneer/thunk -> 0x0026fe44 ad::lyt::LytAnim::stopAndSetFrm (static)

// FUNC 0x118002c8 ->ad::lyt::LytAnim::term (Colosseum)
//   size 0x4 | file Colosseum+0x2c8 | callers(8) 0x118012ec 0x118019c0 0x118020bc 0x11805eb0 0x11805fa4 0x1180854c 0x1180449c 0x11804fdc
// veneer/thunk -> 0x00264e90 ad::lyt::LytAnim::term (static)

// FUNC 0x118002d0 ->msys::MDfxChr::term (Colosseum)
//   size 0x4 | file Colosseum+0x2d0 | callers(2) 0x11801e4c 0x11807bcc
// veneer/thunk -> 0x00330c68 msys::MDfxChr::term (static)

// FUNC 0x118002d8 ->msys::MDfxChr::playDfx (Colosseum)
//   size 0x4 | file Colosseum+0x2d8 | callers(6) 0x118012ec 0x11807390 0x11801e4c 0x11808098 0x11806144 0x11807a84
// veneer/thunk -> 0x00330d64 msys::MDfxChr::playDfx (static)

// FUNC 0x118002e0 ->Mem::Fill (Colosseum)
//   size 0x4 | file Colosseum+0x2e0 | callers(1) 0x118020bc
// veneer/thunk -> 0x002849e8 Mem::Fill (static)

// FUNC 0x118002e8 ->nn::nstd::TSPrintf (Colosseum)
//   size 0x4 | file Colosseum+0x2e8 | callers(4) 0x118020bc 0x1180229c 0x118023e8 0x118025e4
// veneer/thunk -> 0x002765cc nn::nstd::TSPrintf (static)

// FUNC 0x118002f0 ->msys::MLyt::getParts (Colosseum)
//   size 0x4 | file Colosseum+0x2f0 | callers(3) 0x118012ec 0x118020bc 0x11805498
// veneer/thunk -> 0x002073ec msys::MLyt::getParts (static)

// FUNC 0x118002f8 ->msys::MLyt::getPane (Colosseum)
//   size 0x4 | file Colosseum+0x2f8 | callers(2) 0x1180229c 0x118023e8
// veneer/thunk -> 0x0032c688 msys::MLyt::getPane (static)

// FUNC 0x11800300 ->ad::lyt::LytNumReel3::setValueInstant (Colosseum)
//   size 0x4 | file Colosseum+0x300 | callers(5) 0x1180229c 0x118061f4 0x11806474 0x118023e8 0x11804208
// veneer/thunk -> 0x0020785c ad::lyt::LytNumReel3::setValueInstant (static)

// FUNC 0x11800308 ->msys::MListWndPBase::isTpNeutral (Colosseum)
//   size 0x4 | file Colosseum+0x308 | callers(3) 0x11809d64 0x1180268c 0x118053a8
// veneer/thunk -> 0x003620c8 msys::MListWndPBase::isTpNeutral (static)

// FUNC 0x11800310 ->msys::MListWndPBase::getCurNo (Colosseum)
//   size 0x4 | file Colosseum+0x310 | callers(8) 0x1180268c 0x11806474 0x1180406c 0x1180485c 0x11804c5c 0x11804fdc 0x11804d04 0x11807008
// veneer/thunk -> 0x003620e0 msys::MListWndPBase::getCurNo (static)

// FUNC 0x11800318 ->msys::MListWndPBase::getCurItem (Colosseum)
//   size 0x4 | file Colosseum+0x318 | callers(3) 0x1180268c 0x118053a8 0x11806e7c
// veneer/thunk -> 0x0025a0bc msys::MListWndPBase::getCurItem (static)

// FUNC 0x11800320 ->msys::MListWndPBase::getSelectItem (Colosseum)
//   size 0x4 | file Colosseum+0x320 | callers(2) 0x1180268c 0x118053a8
// veneer/thunk -> 0x003285f0 msys::MListWndPBase::getSelectItem (static)

// FUNC 0x11800328 ->msys::MLyt::getAnim (Colosseum)
//   size 0x4 | file Colosseum+0x328 | callers(5) 0x118012ec 0x11805eb0 0x1180268c 0x1180440c 0x11807d88
// veneer/thunk -> 0x0032c678 msys::MLyt::getAnim (static)

// FUNC 0x11800330 ->msys::MLyt::createAnime (Colosseum)
//   size 0x4 | file Colosseum+0x330 | callers(1) 0x1180268c
// veneer/thunk -> 0x00206c48 msys::MLyt::createAnime (static)

// FUNC 0x11800338 ->msys::MLyt::createAnimeAutoSlot (Colosseum)
//   size 0x4 | file Colosseum+0x338 | callers(10) 0x118012ec 0x11805eb0 0x1180268c 0x1180449c 0x11804b58 0x11804fdc 0x11804d04 0x11807d88 ...
// veneer/thunk -> 0x0032c308 msys::MLyt::createAnimeAutoSlot (static)

// FUNC 0x11800340 ->Backup::isBusyWriting (Colosseum)
//   size 0x4 | file Colosseum+0x340 | callers(1) 0x118029c0
// veneer/thunk -> 0x00339558 Backup::isBusyWriting (static)

// FUNC 0x11800348 ->Backup::term (Colosseum)
//   size 0x4 | file Colosseum+0x348 | callers(1) 0x118029c0
// veneer/thunk -> 0x00339c84 Backup::term (static)

// FUNC 0x11800350 ->msys::MLyt::playAnimeFromNo (Colosseum)
//   size 0x4 | file Colosseum+0x350 | callers(18) 0x1180406c 0x11802a54 0x1180449c 0x11804b58 0x11804c5c 0x11806e00 0x11806e7c 0x11804208 ...
// veneer/thunk -> 0x0032bf98 msys::MLyt::playAnimeFromNo (static)

// FUNC 0x11800358 ->msys::MListWndPBase::applyAnime (Colosseum)
//   size 0x4 | file Colosseum+0x358 | callers(2) 0x11802a98 0x11808530
// veneer/thunk -> 0x0032844c msys::MListWndPBase::applyAnime (static)

// FUNC 0x11800360 ->ad::lyt::Layout::Animate (Colosseum)
//   size 0x4 | file Colosseum+0x360 | callers(2) 0x11802a98 0x11808530
// veneer/thunk -> 0x00161aec ad::lyt::Layout::Animate (static)

// FUNC 0x11800368 ->ad::lyt::LytResourceMan::buildLayout (Colosseum)
//   size 0x4 | file Colosseum+0x368 | callers(2) 0x11802ab4 0x1180854c
// veneer/thunk -> 0x00256490 ad::lyt::LytResourceMan::buildLayout (static)

// FUNC 0x11800370 ->ad::lyt::LytAnim::playAuto (Colosseum)
//   size 0x4 | file Colosseum+0x370 | callers(2) 0x11802ab4 0x1180854c
// veneer/thunk -> 0x0025620c ad::lyt::LytAnim::playAuto (static)

// FUNC 0x11800378 ->ad::ui::UIListWindowPlusLyt::InitParam::InitParam (Colosseum)
//   size 0x4 | file Colosseum+0x378 | callers(2) 0x11802ab4 0x1180854c
// veneer/thunk -> 0x00146398 ad::ui::UIListWindowPlusLyt::InitParam::InitParam (static)

// FUNC 0x11800380 ->msys::SetMListWndInitParam (Colosseum)
//   size 0x4 | file Colosseum+0x380 | callers(2) 0x11802ab4 0x1180854c
// veneer/thunk -> 0x00329e60 msys::SetMListWndInitParam (static)

// FUNC 0x11800388 ->msys::MListWndPBase::init (Colosseum)
//   size 0x4 | file Colosseum+0x388 | callers(2) 0x11802ab4 0x1180854c
// veneer/thunk -> 0x00328698 msys::MListWndPBase::init (static)

// FUNC 0x11800390 ->msys::MListWndPBase::resetCur (Colosseum)
//   size 0x4 | file Colosseum+0x390 | callers(3) 0x11802ab4 0x11806ab4 0x11806e00
// veneer/thunk -> 0x003287c0 msys::MListWndPBase::resetCur (static)

// FUNC 0x11800398 ->ad::lyt::Layout::~Layout (Colosseum)
//   size 0x4 | file Colosseum+0x398 | callers(5) 0x11802d48 0x11802db8 0x11808908 0x118089a4 0x118097f0
// veneer/thunk -> 0x00262eec ad::lyt::Layout::~Layout (static)

// FUNC 0x118003a0 ->ad::ui::UIListWindowPlusLyt::~UIListWindowPlusLyt (Colosseum)
//   size 0x4 | file Colosseum+0x3a0 | callers(11) 0x11802d48 0x11802db8 0x11808908 0x118089a4 0x118097f0 0x1180b654 0x1180b664 0x1180b7f0 ...
// veneer/thunk -> 0x0025a3fc ad::ui::UIListWindowPlusLyt::~UIListWindowPlusLyt (static)

// FUNC 0x118003a8 ->msys::MListWndPBase::~MListWndPBase (Colosseum)
//   size 0x4 | file Colosseum+0x3a8 | callers(9) 0x11802d48 0x11808908 0x118097f0 0x1180b7f0 0x1180b834 0x11802db8 0x118089a4 0x1180b814 ...
// veneer/thunk -> 0x003288a0 msys::MListWndPBase::~MListWndPBase (static)

// FUNC 0x118003b0 ->ad::lyt::LytLocalize::LytLocalize (Colosseum)
//   size 0x4 | file Colosseum+0x3b0 | callers(1) 0x118012ec
// veneer/thunk -> 0x002563d4 ad::lyt::LytLocalize::LytLocalize (static)

// FUNC 0x118003b8 ->ad::lyt::LytLocalize::localize (Colosseum)
//   size 0x4 | file Colosseum+0x3b8 | callers(1) 0x118012ec
// veneer/thunk -> 0x00264e08 ad::lyt::LytLocalize::localize (static)

// FUNC 0x118003c0 ->Message::init (Colosseum)
//   size 0x4 | file Colosseum+0x3c0 | callers(1) 0x118012ec
// veneer/thunk -> 0x0033dc2c Message::init (static)

// FUNC 0x118003c8 ->Message::setMsgDat (Colosseum)
//   size 0x4 | file Colosseum+0x3c8 | callers(1) 0x118012ec
// veneer/thunk -> 0x0033ddc8 Message::setMsgDat (static)

// FUNC 0x118003d0 ->GameWork::getCoin (Colosseum)
//   size 0x4 | file Colosseum+0x3d0 | callers(4) 0x118012ec 0x11806ab4 0x1180485c 0x11804208
// veneer/thunk -> 0x00363120 GameWork::getCoin (static)

// FUNC 0x118003d8 ->ad::ctrl::ButtonGroup::FindButtonByName (Colosseum)
//   size 0x4 | file Colosseum+0x3d8 | callers(1) 0x118012ec
// veneer/thunk -> 0x00256680 ad::ctrl::ButtonGroup::FindButtonByName (static)

// FUNC 0x118003e0 ->ad::ctrl::AnimButton::SetStateChangeCallback (Colosseum)
//   size 0x4 | file Colosseum+0x3e0 | callers(1) 0x118012ec
// veneer/thunk -> 0x00256674 ad::ctrl::AnimButton::SetStateChangeCallback (static)

// FUNC 0x118003e8 ->ad::fw::TaskBase::isFps30 (Colosseum)
//   size 0x4 | file Colosseum+0x3e8 | callers(11) 0x118012ec 0x118082f0 0x11804fdc 0x11807390 0x11807118 0x118077c0 0x11807d88 0x11807edc ...
// veneer/thunk -> 0x0025edd0 ad::fw::TaskBase::isFps30 (static)

// FUNC 0x118003f0 ->msys::MCursorBase::setVisible (Colosseum)
//   size 0x4 | file Colosseum+0x3f0 | callers(7) 0x118012ec 0x11808a48 0x1180485c 0x11806e00 0x118076e0 0x1180532c 0x11806f04
// veneer/thunk -> 0x00324454 msys::MCursorBase::setVisible (static)

// FUNC 0x118003f8 ->msys::MLyt::setAnimeInfo (Colosseum)
//   size 0x4 | file Colosseum+0x3f8 | callers(2) 0x118012ec 0x1180440c
// veneer/thunk -> 0x0032bc40 msys::MLyt::setAnimeInfo (static)

// FUNC 0x11800400 ->GameMain::GameModeOld (Colosseum)
//   size 0x4 | file Colosseum+0x400 | callers(3) 0x118012ec 0x11804f10 0x11804d04
// veneer/thunk -> 0x0033e320 GameMain::GameModeOld (static)

// FUNC 0x11800408 ->msys::MListWndPBase::getListWnd (Colosseum)
//   size 0x4 | file Colosseum+0x408 | callers(1) 0x118012ec
// veneer/thunk -> 0x003620c0 msys::MListWndPBase::getListWnd (static)

// FUNC 0x11800410 ->col::GetBootInfo (Colosseum)
//   size 0x4 | file Colosseum+0x410 | callers(13) 0x11809074 0x118012ec 0x11804b58 0x11804f10 0x118055d0 0x118082f0 0x11807390 0x11804d04 ...
// veneer/thunk -> 0x002a1e64 col::GetBootInfo (static)

// FUNC 0x11800418 ->col::BootInfo::saveBgm (Colosseum)
//   size 0x4 | file Colosseum+0x418 | callers(1) 0x118012ec
// veneer/thunk -> 0x002a20c4 col::BootInfo::saveBgm (static)

// FUNC 0x11800420 ->hb::GetColiseumResult (Colosseum)
//   size 0x4 | file Colosseum+0x420 | callers(1) 0x118012ec
// veneer/thunk -> 0x0016c924 hb::GetColiseumResult (static)

// FUNC 0x11800428 ->btl::GetBootInfo (Colosseum)
//   size 0x4 | file Colosseum+0x428 | callers(3) 0x118012ec 0x118082f0 0x11807008
// veneer/thunk -> 0x00217ff8 btl::GetBootInfo (static)

// FUNC 0x11800430 ->col::BootInfo::dataPartyRestor (Colosseum)
//   size 0x4 | file Colosseum+0x430 | callers(1) 0x118012ec
// veneer/thunk -> 0x002a1fa0 col::BootInfo::dataPartyRestor (static)

// FUNC 0x11800438 ->msys::MLyt::stopAnimeAndSetEnd (Colosseum)
//   size 0x4 | file Colosseum+0x438 | callers(1) 0x118012ec
// veneer/thunk -> 0x0032c27c msys::MLyt::stopAnimeAndSetEnd (static)

// FUNC 0x11800440 ->Frm::play (Colosseum)
//   size 0x4 | file Colosseum+0x440 | callers(10) 0x118012ec 0x1180485c 0x11804b58 0x11804fdc 0x11807390 0x118077c0 0x11807d88 0x11807fac ...
// veneer/thunk -> 0x0027a324 Frm::play (static)

// FUNC 0x11800448 ->col::BootInfo::restoreBgm (Colosseum)
//   size 0x4 | file Colosseum+0x448 | callers(3) 0x118012ec 0x11804b58 0x11804d04
// veneer/thunk -> 0x002a1eb4 col::BootInfo::restoreBgm (static)

// FUNC 0x11800450 ->msys::MLyt::isEnableAnime (Colosseum)
//   size 0x4 | file Colosseum+0x450 | callers(10) 0x1180449c 0x118055d0 0x11804208 0x11807390 0x118076e0 0x11807928 0x118079c4 0x11806f04 ...
// veneer/thunk -> 0x0032bc6c msys::MLyt::isEnableAnime (static)

// FUNC 0x11800458 ->Message::close (Colosseum)
//   size 0x4 | file Colosseum+0x458 | callers(1) 0x11804208
// veneer/thunk -> 0x0024dcc8 Message::close (static)

// FUNC 0x11800460 ->Backup::GetSaveData1 (Colosseum)
//   size 0x4 | file Colosseum+0x460 | callers(1) 0x118042b8
// veneer/thunk -> 0x00339284 Backup::GetSaveData1 (static)

// FUNC 0x11800468 ->Mem::Copy (Colosseum)
//   size 0x4 | file Colosseum+0x468 | callers(2) 0x1180449c 0x118042b8
// veneer/thunk -> 0x0027fd08 Mem::Copy (static)

// FUNC 0x11800470 ->Backup::init (Colosseum)
//   size 0x4 | file Colosseum+0x470 | callers(1) 0x118042b8
// veneer/thunk -> 0x00339c54 Backup::init (static)

// FUNC 0x11800478 ->Backup::writeSaveData0 (Colosseum)
//   size 0x4 | file Colosseum+0x478 | callers(1) 0x118042b8
// veneer/thunk -> 0x00339aa0 Backup::writeSaveData0 (static)

// FUNC 0x11800480 ->MoveC::moveFrm (Colosseum)
//   size 0x4 | file Colosseum+0x480 | callers(3) 0x1180b200 0x11807118 0x11804334
// veneer/thunk -> 0x0026bc74 MoveC::moveFrm (static)

// FUNC 0x11800488 ->PutRegFlag (Colosseum)
//   size 0x4 | file Colosseum+0x488 | callers(1) 0x1180449c
// veneer/thunk -> 0x002731a0 PutRegFlag (static)

// FUNC 0x11800490 ->__aeabi_uidivmod (Colosseum)
//   size 0x4 | file Colosseum+0x490 | callers(2) 0x118061f4 0x1180449c
// veneer/thunk -> 0x00281628 __aeabi_uidivmod (static)

// FUNC 0x11800498 ->ad::db::GetItemMsg (Colosseum)
//   size 0x4 | file Colosseum+0x498 | callers(1) 0x1180449c
// veneer/thunk -> 0x0013a194 ad::db::GetItemMsg (static)

// FUNC 0x118004a0 ->GameWork::addCoin (Colosseum)
//   size 0x4 | file Colosseum+0x4a0 | callers(2) 0x11805d28 0x1180485c
// veneer/thunk -> 0x0022ec84 GameWork::addCoin (static)

// FUNC 0x118004a8 ->ad::lyt::LytNumReel3::setValue (Colosseum)
//   size 0x4 | file Colosseum+0x4a8 | callers(1) 0x1180485c
// veneer/thunk -> 0x0015a7c8 ad::lyt::LytNumReel3::setValue (static)

// FUNC 0x118004b0 ->msys::MSndSe::play (Colosseum)
//   size 0x4 | file Colosseum+0x4b0 | callers(3) 0x11805688 0x11806814 0x1180485c
// veneer/thunk -> 0x0032d844 msys::MSndSe::play (static)

// FUNC 0x118004b8 ->SndSys::start (Colosseum)
//   size 0x4 | file Colosseum+0x4b8 | callers(1) 0x11804b58
// veneer/thunk -> 0x0033c77c SndSys::start (static)

// FUNC 0x118004c0 ->SndSys::stopAllBgm (Colosseum)
//   size 0x4 | file Colosseum+0x4c0 | callers(2) 0x11807008 0x11804d04
// veneer/thunk -> 0x0033c450 SndSys::stopAllBgm (static)

// FUNC 0x118004c8 ->col::BootInfo::playBgm (Colosseum)
//   size 0x4 | file Colosseum+0x4c8 | callers(3) 0x11804f10 0x118055d0 0x11807390
// veneer/thunk -> 0x002a1fc0 col::BootInfo::playBgm (static)

// FUNC 0x118004d0 ->SndSeCtrl::stop (Colosseum)
//   size 0x4 | file Colosseum+0x4d0 | callers(1) 0x11804f88
// veneer/thunk -> 0x002832cc SndSeCtrl::stop (static)

// FUNC 0x118004d8 ->Frm::update (Colosseum)
//   size 0x4 | file Colosseum+0x4d8 | callers(10) 0x118082f0 0x11804fdc 0x11807390 0x11807118 0x118077c0 0x11807d88 0x11807edc 0x118083b8 ...
// veneer/thunk -> 0x0026aed4 Frm::update (static)

// FUNC 0x118004e0 ->ad::fw::TaskBase::term (Colosseum)
//   size 0x4 | file Colosseum+0x4e0 | callers(1) 0x11805724
// veneer/thunk -> 0x0024a358 ad::fw::TaskBase::term (static)

// FUNC 0x118004e8 ->msys::MLyt::term (Colosseum)
//   size 0x4 | file Colosseum+0x4e8 | callers(2) 0x11805724 0x118097f0
// veneer/thunk -> 0x0032c3c8 msys::MLyt::term (static)

// FUNC 0x118004f0 ->ad::fw::Resource::term (Colosseum)
//   size 0x4 | file Colosseum+0x4f0 | callers(2) 0x11805724 0x118097f0
// veneer/thunk -> 0x00233340 ad::fw::Resource::term (static)

// FUNC 0x118004f8 ->__aeabi_vec_dtor (Colosseum)
//   size 0x4 | file Colosseum+0x4f8 | callers(5) 0x11805724 0x118059d0 0x118097f0 0x1180b888 0x1180b8c4
// veneer/thunk -> 0x00288230 __aeabi_vec_dtor (static)

// FUNC 0x11800500 ->ad::fw::Resource::~Resource (Colosseum)
//   size 0x4 | file Colosseum+0x500 | callers(2) 0x11805724 0x118097f0
// veneer/thunk -> 0x0024a104 ad::fw::Resource::~Resource (static)

// FUNC 0x11800508 ->msys::MComSys::~MComSys (Colosseum)
//   size 0x4 | file Colosseum+0x508 | callers(1) 0x11805724
// veneer/thunk -> 0x003300e8 msys::MComSys::~MComSys (static)

// FUNC 0x11800510 ->MoveVBase::MoveVBase (Colosseum)
//   size 0x4 | file Colosseum+0x510 | callers(1) 0x118058e4
// veneer/thunk -> 0x00259740 MoveVBase::MoveVBase (static)

// FUNC 0x11800518 ->__aeabi_vec_ctor_nocookie_nodtor (Colosseum)
//   size 0x4 | file Colosseum+0x518 | callers(3) 0x1180b454 0x118058e4 0x11809074
// veneer/thunk -> 0x0028771c __aeabi_vec_ctor_nocookie_nodtor (static)

// FUNC 0x11800520 ->MoveVBase::~MoveVBase (Colosseum)
//   size 0x4 | file Colosseum+0x520 | callers(3) 0x118059d0 0x1180b888 0x1180b8c4
// veneer/thunk -> 0x002535e8 MoveVBase::~MoveVBase (static)

// FUNC 0x11800528 ->strcpy (Colosseum)
//   size 0x4 | file Colosseum+0x528 | callers(1) 0x11807008
// veneer/thunk -> 0x002697dc strcpy (static)

// FUNC 0x11800530 ->ad::Encount::GetInst (Colosseum)
//   size 0x4 | file Colosseum+0x530 | callers(1) 0x11807008
// veneer/thunk -> 0x00287f4c ad::Encount::GetInst (static)

// FUNC 0x11800538 ->ad::Encount::startLoadRes (Colosseum)
//   size 0x4 | file Colosseum+0x538 | callers(1) 0x11807008
// veneer/thunk -> 0x0016a80c ad::Encount::startLoadRes (static)

// FUNC 0x11800540 ->GameMain::Change (Colosseum)
//   size 0x4 | file Colosseum+0x540 | callers(1) 0x11807008
// veneer/thunk -> 0x0033e7fc GameMain::Change (static)

// FUNC 0x11800548 ->Message::play (Colosseum)
//   size 0x4 | file Colosseum+0x548 | callers(1) 0x11805cbc
// veneer/thunk -> 0x00259970 Message::play (static)

// FUNC 0x11800550 ->GameWork::addItem (Colosseum)
//   size 0x4 | file Colosseum+0x550 | callers(1) 0x11805d28
// veneer/thunk -> 0x0033edc8 GameWork::addItem (static)

// FUNC 0x11800558 ->strcmp (Colosseum)
//   size 0x4 | file Colosseum+0x558 | callers(1) 0x1180657c
// veneer/thunk -> 0x002833b8 strcmp (static)

// FUNC 0x11800560 ->msys::MCtrlUserData::findExtUserDataByName (Colosseum)
//   size 0x4 | file Colosseum+0x560 | callers(1) 0x1180657c
// veneer/thunk -> 0x0036203c msys::MCtrlUserData::findExtUserDataByName (static)

// FUNC 0x11800568 ->__cxa_guard_acquire (Colosseum)
//   size 0x4 | file Colosseum+0x568 | callers(4) 0x1180a158 0x11806968 0x11807390 0x11807a84
// veneer/thunk -> 0x00288110 __cxa_guard_acquire (static)

// FUNC 0x11800570 ->__cxa_guard_release (Colosseum)
//   size 0x4 | file Colosseum+0x570 | callers(4) 0x1180a158 0x11806968 0x11807390 0x11807a84
// veneer/thunk -> 0x001018a8 __cxa_guard_release (static)

// FUNC 0x11800578 ->hb::SetBootInfoColosseum (Colosseum)
//   size 0x4 | file Colosseum+0x578 | callers(1) 0x11807008
// veneer/thunk -> 0x0016ca68 hb::SetBootInfoColosseum (static)

// FUNC 0x11800580 ->col::BootInfo::dataPartyBackup (Colosseum)
//   size 0x4 | file Colosseum+0x580 | callers(1) 0x11807008
// veneer/thunk -> 0x002a1ef8 col::BootInfo::dataPartyBackup (static)

// FUNC 0x11800588 ->msys::MLyt::isBusyAnime (Colosseum)
//   size 0x4 | file Colosseum+0x588 | callers(5) 0x118082f0 0x11807118 0x11807d88 0x11808098 0x11807a84
// veneer/thunk -> 0x0032bb14 msys::MLyt::isBusyAnime (static)

// FUNC 0x11800590 ->msys::MLyt::getAnime (Colosseum)
//   size 0x4 | file Colosseum+0x590 | callers(2) 0x11808460 0x11807bcc
// veneer/thunk -> 0x0032c738 msys::MLyt::getAnime (static)

// FUNC 0x11800598 ->Message::term (Colosseum)
//   size 0x4 | file Colosseum+0x598 | callers(3) 0x118084cc 0x11808500 0x118097f0
// veneer/thunk -> 0x0033dc68 Message::term (static)

// FUNC 0x118005a0 ->Message::~Message (Colosseum)
//   size 0x4 | file Colosseum+0x5a0 | callers(3) 0x118084cc 0x11808500 0x118097f0
// veneer/thunk -> 0x00206538 Message::~Message (static)

// FUNC 0x118005a8 ->ad::lyt::LytDrawSys::GetInst (Colosseum)
//   size 0x4 | file Colosseum+0x5a8 | callers(2) 0x1180adec 0x11808d0c
// veneer/thunk -> 0x00287f58 ad::lyt::LytDrawSys::GetInst (static)

// FUNC 0x118005b0 ->ad::lyt::Initialize (Colosseum)
//   size 0x4 | file Colosseum+0x5b0 | callers(2) 0x1180adec 0x11808d0c
// veneer/thunk -> 0x002855e0 ad::lyt::Initialize (static)

// FUNC 0x118005b8 ->ad::TransMultiSymbol::init (Colosseum)
//   size 0x4 | file Colosseum+0x5b8 | callers(1) 0x11808d0c
// veneer/thunk -> 0x0026d7f8 ad::TransMultiSymbol::init (static)

// FUNC 0x118005c0 ->BinGlu4Acs::getEntryAcs (Colosseum)
//   size 0x4 | file Colosseum+0x5c0 | callers(1) 0x11808d0c
// veneer/thunk -> 0x00285268 BinGlu4Acs::getEntryAcs (static)

// FUNC 0x118005c8 ->ad::fw::TaskBase::readCA (Colosseum)
//   size 0x4 | file Colosseum+0x5c8 | callers(1) 0x11808d0c
// veneer/thunk -> 0x0026daf8 ad::fw::TaskBase::readCA (static)

// FUNC 0x118005d0 ->ad::fw::TaskBase::readLyt (Colosseum)
//   size 0x4 | file Colosseum+0x5d0 | callers(2) 0x1180adec 0x11808d0c
// veneer/thunk -> 0x00249e48 ad::fw::TaskBase::readLyt (static)

// FUNC 0x118005d8 ->Backup::Backup (Colosseum)
//   size 0x4 | file Colosseum+0x5d8 | callers(1) 0x11809074
// veneer/thunk -> 0x00110c64 Backup::Backup (static)

// FUNC 0x118005e0 ->ad::ctrl::ButtonGroup::ButtonGroup (Colosseum)
//   size 0x4 | file Colosseum+0x5e0 | callers(1) 0x11809074
// veneer/thunk -> 0x001667d8 ad::ctrl::ButtonGroup::ButtonGroup (static)

// FUNC 0x118005e8 ->ad::font::ResFont::ResFont (Colosseum)
//   size 0x4 | file Colosseum+0x5e8 | callers(1) 0x11809074
// veneer/thunk -> 0x0027542c ad::font::ResFont::ResFont (static)

// FUNC 0x118005f0 ->ad::fw::Resource::Resource (Colosseum)
//   size 0x4 | file Colosseum+0x5f0 | callers(2) 0x1180b454 0x11809074
// veneer/thunk -> 0x00250588 ad::fw::Resource::Resource (static)

// FUNC 0x118005f8 ->msys::MCursorBase::MCursorBase (Colosseum)
//   size 0x4 | file Colosseum+0x5f8 | callers(1) 0x11809074
// veneer/thunk -> 0x00324550 msys::MCursorBase::MCursorBase (static)

// FUNC 0x11800600 ->MessageSimple::MessageSimple (Colosseum)
//   size 0x4 | file Colosseum+0x600 | callers(1) 0x11809074
// veneer/thunk -> 0x0027ceec MessageSimple::MessageSimple (static)

// FUNC 0x11800608 ->msys::MLytNum::MLytNum (Colosseum)
//   size 0x4 | file Colosseum+0x608 | callers(1) 0x11809074
// veneer/thunk -> 0x003317a4 msys::MLytNum::MLytNum (static)

// FUNC 0x11800610 ->msys::MDfxChr::MDfxChr (Colosseum)
//   size 0x4 | file Colosseum+0x610 | callers(1) 0x11809074
// veneer/thunk -> 0x0033137c msys::MDfxChr::MDfxChr (static)

// FUNC 0x11800618 ->Message::Message (Colosseum)
//   size 0x4 | file Colosseum+0x618 | callers(1) 0x11809074
// veneer/thunk -> 0x00110d5c Message::Message (static)

// FUNC 0x11800620 ->msys::MListWndPBase::MListWndPBase (Colosseum)
//   size 0x4 | file Colosseum+0x620 | callers(1) 0x11809074
// veneer/thunk -> 0x00328800 msys::MListWndPBase::MListWndPBase (static)

// FUNC 0x11800628 ->ad::ui::UIListWindowPlusLyt::UIListWindowPlusLyt (Colosseum)
//   size 0x4 | file Colosseum+0x628 | callers(1) 0x11809074
// veneer/thunk -> 0x00146984 ad::ui::UIListWindowPlusLyt::UIListWindowPlusLyt (static)

// FUNC 0x11800630 ->ad::lyt::Layout::Layout (Colosseum)
//   size 0x4 | file Colosseum+0x630 | callers(1) 0x11809074
// veneer/thunk -> 0x00264ccc ad::lyt::Layout::Layout (static)

// FUNC 0x11800638 ->msys::MCursorBase::term (Colosseum)
//   size 0x4 | file Colosseum+0x638 | callers(1) 0x118097f0
// veneer/thunk -> 0x003244f0 msys::MCursorBase::term (static)

// FUNC 0x11800640 ->ad::ctrl::ButtonGroup::FreeAll (Colosseum)
//   size 0x4 | file Colosseum+0x640 | callers(1) 0x118097f0
// veneer/thunk -> 0x002509d0 ad::ctrl::ButtonGroup::FreeAll (static)

// FUNC 0x11800648 ->ad::lyt::LytResourceMan::term (Colosseum)
//   size 0x4 | file Colosseum+0x648 | callers(1) 0x118097f0
// veneer/thunk -> 0x00250938 ad::lyt::LytResourceMan::term (static)

// FUNC 0x11800650 ->msys::MLytNum::~MLytNum (Colosseum)
//   size 0x4 | file Colosseum+0x650 | callers(1) 0x118097f0
// veneer/thunk -> 0x00331840 msys::MLytNum::~MLytNum (static)

// FUNC 0x11800658 ->MessageSimple::term (Colosseum)
//   size 0x4 | file Colosseum+0x658 | callers(1) 0x118097f0
// veneer/thunk -> 0x00137090 MessageSimple::term (static)

// FUNC 0x11800660 ->MessageSimple::~MessageSimple (Colosseum)
//   size 0x4 | file Colosseum+0x660 | callers(1) 0x118097f0
// veneer/thunk -> 0x00256578 MessageSimple::~MessageSimple (static)

// FUNC 0x11800668 ->msys::MDfxChr::~MDfxChr (Colosseum)
//   size 0x4 | file Colosseum+0x668 | callers(1) 0x118097f0
// veneer/thunk -> 0x003313cc msys::MDfxChr::~MDfxChr (static)

// FUNC 0x11800670 ->msys::MCursorBase::~MCursorBase (Colosseum)
//   size 0x4 | file Colosseum+0x670 | callers(3) 0x118097f0 0x1180bb70 0x1180bb80
// veneer/thunk -> 0x00324600 msys::MCursorBase::~MCursorBase (static)

// FUNC 0x11800678 ->ad::font::ResFont::~ResFont (Colosseum)
//   size 0x4 | file Colosseum+0x678 | callers(1) 0x118097f0
// veneer/thunk -> 0x002508a8 ad::font::ResFont::~ResFont (static)

// FUNC 0x11800680 ->ad::ctrl::ButtonGroup::~ButtonGroup (Colosseum)
//   size 0x4 | file Colosseum+0x680 | callers(1) 0x118097f0
// veneer/thunk -> 0x00250928 ad::ctrl::ButtonGroup::~ButtonGroup (static)

// FUNC 0x11800688 ->Backup::~Backup (Colosseum)
//   size 0x4 | file Colosseum+0x688 | callers(1) 0x118097f0
// veneer/thunk -> 0x00339f34 Backup::~Backup (static)

// FUNC 0x11800690 ->msys::MPageBase::updateInputAllChr (Colosseum)
//   size 0x4 | file Colosseum+0x690 | callers(1) 0x11809d64
// veneer/thunk -> 0x00334204 msys::MPageBase::updateInputAllChr (static)

// FUNC 0x11800698 ->ad::ctrl::ButtonGroup::Update (Colosseum)
//   size 0x4 | file Colosseum+0x698 | callers(1) 0x11809d64
// veneer/thunk -> 0x00250a40 ad::ctrl::ButtonGroup::Update (static)

// FUNC 0x118006a0 ->msys::MTaskBase::MTaskBase (Colosseum)
//   size 0x4 | file Colosseum+0x6a0 | callers(1) 0x1180a01c
// veneer/thunk -> 0x00334688 msys::MTaskBase::MTaskBase (static)

// FUNC 0x118006a8 ->ad::fw::TaskBase::~TaskBase (Colosseum)
//   size 0x4 | file Colosseum+0x6a8 | callers(2) 0x1180a058 0x1180a080
// veneer/thunk -> 0x0026d590 ad::fw::TaskBase::~TaskBase (static)

// FUNC 0x118006b0 ->msys::MCamera::getProjMtx (Colosseum)
//   size 0x4 | file Colosseum+0x6b0 | callers(2) 0x1180a118 0x1180a0a4
// veneer/thunk -> 0x00206718 msys::MCamera::getProjMtx (static)

// FUNC 0x118006b8 ->msys::MCamera::getViewMtx (Colosseum)
//   size 0x4 | file Colosseum+0x6b8 | callers(1) 0x1180a0a4
// veneer/thunk -> 0x002068e4 msys::MCamera::getViewMtx (static)

// FUNC 0x118006c0 ->ad::fw::TaskBase::setULcdCameraInfoBase (Colosseum)
//   size 0x4 | file Colosseum+0x6c0 | callers(1) 0x1180a0a4
// veneer/thunk -> 0x0010b438 ad::fw::TaskBase::setULcdCameraInfoBase (static)

// FUNC 0x118006c8 ->Grp::SetupProjLcdOrtho (Colosseum)
//   size 0x4 | file Colosseum+0x6c8 | callers(2) 0x1180a158 0x1180a0a4
// veneer/thunk -> 0x00284fc0 Grp::SetupProjLcdOrtho (static)

// FUNC 0x118006d0 ->msys::MComSys::funcCalcMainNomal (Colosseum)
//   size 0x4 | file Colosseum+0x6d0 | callers(1) 0x1180a0a4
// veneer/thunk -> 0x0032f13c msys::MComSys::funcCalcMainNomal (static)

// FUNC 0x118006d8 ->msys::MComSys::funcDrawLower (Colosseum)
//   size 0x4 | file Colosseum+0x6d8 | callers(1) 0x1180a118
// veneer/thunk -> 0x0032e2b8 msys::MComSys::funcDrawLower (static)

// FUNC 0x118006e0 ->msys::MCamera::update (Colosseum)
//   size 0x4 | file Colosseum+0x6e0 | callers(1) 0x1180a158
// veneer/thunk -> 0x0032d990 msys::MCamera::update (static)

// FUNC 0x118006e8 ->ad::math::FastInverse (Colosseum)
//   size 0x4 | file Colosseum+0x6e8 | callers(1) 0x1180a158
// veneer/thunk -> 0x0027249c ad::math::FastInverse (static)

// FUNC 0x118006f0 ->CellAnimeState::setProj2dParallax (Colosseum)
//   size 0x4 | file Colosseum+0x6f0 | callers(1) 0x1180a158
// veneer/thunk -> 0x00230a5c CellAnimeState::setProj2dParallax (static)

// FUNC 0x118006f8 ->ad::math::CalcFar (Colosseum)
//   size 0x4 | file Colosseum+0x6f8 | callers(1) 0x1180a158
// veneer/thunk -> 0x00265d58 ad::math::CalcFar (static)

// FUNC 0x11800700 ->ad::math::CalcNear (Colosseum)
//   size 0x4 | file Colosseum+0x700 | callers(1) 0x1180a158
// veneer/thunk -> 0x00265d78 ad::math::CalcNear (static)

// FUNC 0x11800708 ->ad::math::WorldFrustum::WorldFrustum (Colosseum)
//   size 0x4 | file Colosseum+0x708 | callers(1) 0x1180a158
// veneer/thunk -> 0x0023d6ac ad::math::WorldFrustum::WorldFrustum (static)

// FUNC 0x11800710 ->Prim::setProj2dParallax (Colosseum)
//   size 0x4 | file Colosseum+0x710 | callers(1) 0x1180a158
// veneer/thunk -> 0x002066e8 Prim::setProj2dParallax (static)

// FUNC 0x11800718 ->ad::lyt::DrawInfo::SetProjectionMtx (Colosseum)
//   size 0x4 | file Colosseum+0x718 | callers(1) 0x1180a158
// veneer/thunk -> 0x0026510c ad::lyt::DrawInfo::SetProjectionMtx (static)

// FUNC 0x11800720 ->Grp::GetLcdWidth (Colosseum)
//   size 0x4 | file Colosseum+0x720 | callers(1) 0x1180a158
// veneer/thunk -> 0x00271e08 Grp::GetLcdWidth (static)

// FUNC 0x11800728 ->Grp::GetLcdHeight (Colosseum)
//   size 0x4 | file Colosseum+0x728 | callers(1) 0x1180a158
// veneer/thunk -> 0x00271de4 Grp::GetLcdHeight (static)

// FUNC 0x11800730 ->Prim::setProjMtx (Colosseum)
//   size 0x4 | file Colosseum+0x730 | callers(1) 0x1180a158
// veneer/thunk -> 0x00323884 Prim::setProjMtx (static)

// FUNC 0x11800738 ->ad::fw::DfxSys::setViewMtx (Colosseum)
//   size 0x4 | file Colosseum+0x738 | callers(1) 0x1180a158
// veneer/thunk -> 0x0024cb0c ad::fw::DfxSys::setViewMtx (static)

// FUNC 0x11800740 ->ad::dfx::Engine::setViewMtx (Colosseum)
//   size 0x4 | file Colosseum+0x740 | callers(1) 0x1180a158
// veneer/thunk -> 0x0024c9cc ad::dfx::Engine::setViewMtx (static)

// FUNC 0x11800748 ->msys::MComSys::getNextPage (Colosseum)
//   size 0x4 | file Colosseum+0x748 | callers(1) 0x1180a158
// veneer/thunk -> 0x0032db64 msys::MComSys::getNextPage (static)

// FUNC 0x11800750 ->ad::SimpleRectDrawer::draw (Colosseum)
//   size 0x4 | file Colosseum+0x750 | callers(1) 0x1180a158
// veneer/thunk -> 0x0024d330 ad::SimpleRectDrawer::draw (static)

// FUNC 0x11800758 ->msys::MComSys::readLytNum (Colosseum)
//   size 0x4 | file Colosseum+0x758 | callers(1) 0x1180adec
// veneer/thunk -> 0x0032db14 msys::MComSys::readLytNum (static)

// FUNC 0x11800760 ->operator.new[] (Colosseum)
//   size 0x4 | file Colosseum+0x760 | callers(1) 0x1180adec
// veneer/thunk -> 0x00283558 operator.new[] (static)

// FUNC 0x11800768 ->MessageSys::GetPath (Colosseum)
//   size 0x4 | file Colosseum+0x768 | callers(1) 0x1180adec
// veneer/thunk -> 0x00132a2c MessageSys::GetPath (static)

// FUNC 0x11800770 ->nn::fs::CTR::MPCore::detail::UserFileSystem::TryOpenFile (Colosseum)
//   size 0x4 | file Colosseum+0x770 | callers(1) 0x1180adec
// veneer/thunk -> 0x0028598c nn::fs::CTR::MPCore::detail::UserFileSystem::TryOpenFile (static)

// FUNC 0x11800778 ->nn::fs::detail::FileBase::TryGetSize (Colosseum)
//   size 0x4 | file Colosseum+0x778 | callers(3) 0x1180b968 0x1180b944 0x1180adec
// veneer/thunk -> 0x00286568 nn::fs::detail::FileBase::TryGetSize (static)

// FUNC 0x11800780 ->MsgDataAcsrBase::init (Colosseum)
//   size 0x4 | file Colosseum+0x780 | callers(1) 0x1180adec
// veneer/thunk -> 0x00285b88 MsgDataAcsrBase::init (static)

// FUNC 0x11800788 ->operator.delete[] (Colosseum)
//   size 0x4 | file Colosseum+0x788 | callers(1) 0x1180adec
// veneer/thunk -> 0x0028829c operator.delete[] (static)

// FUNC 0x11800790 ->msys::MLytNumRes::init (Colosseum)
//   size 0x4 | file Colosseum+0x790 | callers(1) 0x1180b088
// veneer/thunk -> 0x003240f4 msys::MLytNumRes::init (static)

// FUNC 0x11800798 ->msys::MComSys::initBaseSys (Colosseum)
//   size 0x4 | file Colosseum+0x798 | callers(1) 0x1180b2c8
// veneer/thunk -> 0x0032db84 msys::MComSys::initBaseSys (static)

// FUNC 0x118007a0 ->msys::MComSys::entryPage (Colosseum)
//   size 0x4 | file Colosseum+0x7a0 | callers(1) 0x1180b2c8
// veneer/thunk -> 0x0032f548 msys::MComSys::entryPage (static)

// FUNC 0x118007a8 ->Prim::enableDepthTest (Colosseum)
//   size 0x4 | file Colosseum+0x7a8 | callers(1) 0x1180b2c8
// veneer/thunk -> 0x0026cce8 Prim::enableDepthTest (static)

// FUNC 0x118007b0 ->CtrJobMan::enqueue (Colosseum)
//   size 0x4 | file Colosseum+0x7b0 | callers(1) 0x1180b2c8
// veneer/thunk -> 0x0026dbe8 CtrJobMan::enqueue (static)

// FUNC 0x118007b8 ->msys::MComSys::setupCamU (Colosseum)
//   size 0x4 | file Colosseum+0x7b8 | callers(1) 0x1180b2c8
// veneer/thunk -> 0x0032f674 msys::MComSys::setupCamU (static)

// FUNC 0x118007c0 ->msys::MComSys::setupCamL (Colosseum)
//   size 0x4 | file Colosseum+0x7c0 | callers(1) 0x1180b2c8
// veneer/thunk -> 0x0032f570 msys::MComSys::setupCamL (static)

// FUNC 0x118007c8 ->msys::MComSys::MComSys (Colosseum)
//   size 0x4 | file Colosseum+0x7c8 | callers(1) 0x1180b454
// veneer/thunk -> 0x0032f7a4 msys::MComSys::MComSys (static)

// FUNC 0x118007d0 ->MsgDataAcsrBase::MsgDataAcsrBase (Colosseum)
//   size 0x4 | file Colosseum+0x7d0 | callers(1) 0x1180b454
// veneer/thunk -> 0x0024b3b8 MsgDataAcsrBase::MsgDataAcsrBase (static)

// FUNC 0x118007d8 ->CellAnime::CellAnime (Colosseum)
//   size 0x4 | file Colosseum+0x7d8 | callers(1) 0x1180b57c
// veneer/thunk -> 0x0026be18 CellAnime::CellAnime (static)

// FUNC 0x118007e0 ->CellAnime::~CellAnime (Colosseum)
//   size 0x4 | file Colosseum+0x7e0 | callers(1) 0x1180b5bc
// veneer/thunk -> 0x0024fc94 CellAnime::~CellAnime (static)

// FUNC 0x118007e8 ->MoveVBase::update (Colosseum)
//   size 0x4 | file Colosseum+0x7e8 | callers(1) 0x1180b678
// veneer/thunk -> 0x002597d4 MoveVBase::update (static)

// FUNC 0x118007f0 ->CtrBtn::get (Colosseum)
//   size 0x4 | file Colosseum+0x7f0 | callers(1) 0x1180b678
// veneer/thunk -> 0x003627f0 CtrBtn::get (static)

// FUNC 0x118007f8 ->Message::func (Colosseum)
//   size 0x4 | file Colosseum+0x7f8 | callers(1) 0x1180b678
// veneer/thunk -> 0x00273be0 Message::func (static)

// FUNC 0x11800800 ->msys::MRenderQueueBase::enqueueMsg (Colosseum)
//   size 0x4 | file Colosseum+0x800 | callers(1) 0x1180b754
// veneer/thunk -> 0x00328df0 msys::MRenderQueueBase::enqueueMsg (static)

// FUNC 0x11800808 ->msys::MPageBase::enqueueLowerChr (Colosseum)
//   size 0x4 | file Colosseum+0x808 | callers(1) 0x1180b878
// veneer/thunk -> 0x00334104 msys::MPageBase::enqueueLowerChr (static)

// FUNC 0x11800810 ->msys::MPageBase::enqueueUpperChr (Colosseum)
//   size 0x4 | file Colosseum+0x810 | callers(1) 0x1180b880
// veneer/thunk -> 0x00334184 msys::MPageBase::enqueueUpperChr (static)

// FUNC 0x11800818 ->MoveWorkF::MoveWorkF (Colosseum)
//   size 0x4 | file Colosseum+0x818 | callers(1) 0x1180b8fc
// veneer/thunk -> 0x00278cc0 MoveWorkF::MoveWorkF (static)

// FUNC 0x11800820 ->MoveWorkF::~MoveWorkF (Colosseum)
//   size 0x4 | file Colosseum+0x820 | callers(2) 0x1180b930 0x1180b940
// veneer/thunk -> 0x00340694 MoveWorkF::~MoveWorkF (static)

// FUNC 0x11800828 ->ad::fw::FileContext::initSingleFile (Colosseum)
//   size 0x4 | file Colosseum+0x828 | callers(1) 0x1180ba94
// veneer/thunk -> 0x0013ad54 ad::fw::FileContext::initSingleFile (static)

// FUNC 0x11800830 ->ad::fw::FileContext::initArcFile (Colosseum)
//   size 0x4 | file Colosseum+0x830 | callers(1) 0x1180ba94
// veneer/thunk -> 0x0013aca8 ad::fw::FileContext::initArcFile (static)

// FUNC 0x11800838 ->ad::fw::FileContext::initCAArcFile (Colosseum)
//   size 0x4 | file Colosseum+0x838 | callers(1) 0x1180ba94
// veneer/thunk -> 0x0013acc0 ad::fw::FileContext::initCAArcFile (static)

// FUNC 0x11800840 ->msys::MCursorBase::init (Colosseum)
//   size 0x4 | file Colosseum+0x840 | callers(1) 0x1180bb48
// veneer/thunk -> 0x00324464 msys::MCursorBase::init (static)

// FUNC 0x11800848 Colosseum::EntryTask (Colosseum)
//   size 0x34 | file Colosseum+0x848 | callers(0)

void Colosseum::EntryTask(void)

{
  void *pvVar1;
  Task *pTVar2;
  
  pvVar1 = operator_new(0xe9a50,gMemAlc,(char *)0x0,0);
  pTVar2 = (Task *)0x0;
  if (pvVar1 != (void *)0x0) {
    pTVar2 = (Task *)FUN_1180a01c();
  }
  TaskMan::entry((TaskMan *)&gTaskMainMan,pTVar2);
  return;
}


// FUNC 0x11800888 FUN_11800888 (Colosseum)
//   size 0x850 | file Colosseum+0x888 | callers(1) 0x1180a158

/* WARNING: Removing unreachable block (ram,0x11800eb4) */
/* WARNING: Removing unreachable block (ram,0x11800eb8) */
/* WARNING: Removing unreachable block (ram,0x11800ec4) */
/* WARNING: Removing unreachable block (ram,0x11800a00) */
/* WARNING: Removing unreachable block (ram,0x118009c8) */
/* WARNING: Removing unreachable block (ram,0x118009d0) */
/* WARNING: Removing unreachable block (ram,0x118009dc) */
/* WARNING: Removing unreachable block (ram,0x11800aa8) */
/* WARNING: Removing unreachable block (ram,0x11800ab0) */
/* WARNING: Removing unreachable block (ram,0x11800abc) */
/* WARNING: Removing unreachable block (ram,0x11800adc) */
/* WARNING: Removing unreachable block (ram,0x11800ba0) */
/* WARNING: Removing unreachable block (ram,0x11800de4) */
/* WARNING: Removing unreachable block (ram,0x11800f64) */
/* WARNING: Removing unreachable block (ram,0x11800f68) */
/* WARNING: Removing unreachable block (ram,0x11800f74) */
/* WARNING: Removing unreachable block (ram,0x118010c4) */
/* WARNING: Removing unreachable block (ram,0x11800bec) */
/* WARNING: Removing unreachable block (ram,0x11800e00) */
/* WARNING: Removing unreachable block (ram,0x11800a24) */
/* WARNING: Removing unreachable block (ram,0x11800b04) */
/* WARNING: Removing unreachable block (ram,0x118010d4) */
/* WARNING: Removing unreachable block (ram,0x1180109c) */
/* WARNING: Removing unreachable block (ram,0x11800ee8) */
/* WARNING: Removing unreachable block (ram,0x11800f9c) */
/* WARNING: Removing unreachable block (ram,0x11800d0c) */
/* WARNING: Removing unreachable block (ram,0x11800c00) */
/* WARNING: Removing unreachable block (ram,0x11800ce4) */
/* WARNING: Removing unreachable block (ram,0x11800b70) */
/* WARNING: Removing unreachable block (ram,0x11800bd4) */
/* WARNING: Removing unreachable block (ram,0x11800bc0) */

int FUN_11800888(int param_1)

{
  int *piVar1;
  uint uVar2;
  undefined4 *puVar3;
  int *piVar4;
  MemAlcBase *pMVar5;
  char *pcVar6;
  int *piVar7;
  void *pvVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  undefined4 *puVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  int *local_2c;
  uint local_28;
  
  uVar2 = *(uint *)(param_1 + 0x18);
  uVar9 = uVar2 - *(int *)(param_1 + 0x14);
  iVar10 = (int)((longlong)(int)uVar9 * -0x6db6db6d + ((ulonglong)uVar9 << 0x20) >> 0x20);
  uVar9 = ((iVar10 >> 4) - (iVar10 >> 0x1f)) + 1;
  if (uVar9 <= *(uint *)(param_1 + 0x1c)) {
    uVar9 = *(int *)(param_1 + 0x14) + uVar9 * 0x1c;
    if (uVar2 < uVar9) {
      if (uVar9 <= uVar2) {
        for (; uVar2 != uVar9; uVar2 = uVar2 + 0x1c) {
        }
      }
    }
    else if (uVar2 < uVar9) {
      do {
        uVar2 = uVar2 - 0x1c;
      } while (uVar9 != uVar2);
    }
    *(uint *)(param_1 + 0x18) = uVar9;
    goto LAB_11800e04;
  }
  pMVar5 = *(MemAlcBase **)(param_1 + 4);
  pcVar6 = *(char **)(param_1 + 8);
  uVar2 = *(uint *)(param_1 + 0xc);
  local_2c = (undefined4 *)0x0;
  local_28 = 0;
  if (uVar9 == 0) goto LAB_11800b08;
  uVar11 = *(int *)(param_1 + 0x1c) * 2;
  if (uVar9 < uVar11) {
    if (pMVar5 == (MemAlcBase *)0x0) {
      if (uVar11 != 0) goto LAB_11800a30;
    }
    else {
      uVar11 = *(int *)(param_1 + 0x1c) * 0x38;
      local_2c = operator_new(uVar11,pMVar5,pcVar6,uVar2);
      if (local_2c == (undefined4 *)0x0) goto LAB_11800a30;
      local_28 = (uint)((ulonglong)uVar11 * 0x49249249 + 0x49249249 >> 0x23);
    }
LAB_11800b08:
    piVar4 = local_2c;
    puVar3 = *(undefined4 **)(param_1 + 0x14);
    puVar12 = *(undefined4 **)(param_1 + 0x18);
    uVar11 = (int)puVar12 - (int)puVar3;
    iVar10 = (int)((longlong)(int)uVar11 * -0x6db6db6d + ((ulonglong)uVar11 << 0x20) >> 0x20);
    if ((uint)((iVar10 >> 4) - (iVar10 >> 0x1f)) < uVar9) {
      iVar10 = (int)((longlong)(int)uVar11 * -0x6db6db6d + ((ulonglong)uVar11 << 0x20) >> 0x20);
      if (((uint)((iVar10 >> 4) - (iVar10 >> 0x1f)) <= local_28) && (puVar3 != puVar12)) {
        for (; puVar3 != puVar12; puVar3 = puVar3 + 7) {
          if (local_2c != (undefined4 *)0x0) {
            uVar13 = puVar3[1];
            uVar14 = puVar3[2];
            uVar15 = puVar3[3];
            uVar16 = puVar3[4];
            uVar17 = puVar3[5];
            uVar18 = puVar3[6];
            *local_2c = *puVar3;
            local_2c[1] = uVar13;
            local_2c[2] = uVar14;
            local_2c[3] = uVar15;
            local_2c[4] = uVar16;
            local_2c[5] = uVar17;
            local_2c[6] = uVar18;
          }
          local_2c = local_2c + 7;
        }
      }
      if (uVar9 <= local_28) {
        puVar3 = piVar4 + uVar9 * 7;
        if (local_2c < puVar3) {
          if (puVar3 < local_2c) {
            do {
              local_2c = local_2c + 7;
            } while (local_2c != puVar3);
          }
        }
        else if (local_2c < puVar3) {
          do {
            local_2c = local_2c + -7;
          } while (puVar3 != local_2c);
        }
        local_2c = puVar3;
      }
    }
    else {
      puVar12 = puVar3 + uVar9 * 7;
      iVar10 = (int)((longlong)((int)puVar12 - (int)puVar3) * -0x6db6db6d +
                     ((ulonglong)(uint)((int)puVar12 - (int)puVar3) << 0x20) >> 0x20);
      if (((uint)((iVar10 >> 4) - (iVar10 >> 0x1f)) <= local_28) && (puVar3 != puVar12)) {
        for (; puVar3 != puVar12; puVar3 = puVar3 + 7) {
          if (local_2c != (undefined4 *)0x0) {
            uVar13 = puVar3[1];
            uVar14 = puVar3[2];
            uVar15 = puVar3[3];
            uVar16 = puVar3[4];
            uVar17 = puVar3[5];
            uVar18 = puVar3[6];
            *local_2c = *puVar3;
            local_2c[1] = uVar13;
            local_2c[2] = uVar14;
            local_2c[3] = uVar15;
            local_2c[4] = uVar16;
            local_2c[5] = uVar17;
            local_2c[6] = uVar18;
          }
          local_2c = local_2c + 7;
        }
      }
    }
    *(MemAlcBase **)(param_1 + 4) = pMVar5;
    *(char **)(param_1 + 8) = pcVar6;
    *(uint *)(param_1 + 0xc) = uVar2;
    pvVar8 = *(void **)(param_1 + 0x10);
    *(int **)(param_1 + 0x10) = piVar4;
    uVar9 = *(uint *)(param_1 + 0x14);
    *(int **)(param_1 + 0x14) = piVar4;
    uVar2 = *(uint *)(param_1 + 0x18);
    *(int **)(param_1 + 0x18) = local_2c;
    *(uint *)(param_1 + 0x1c) = local_28;
    if (uVar2 < uVar9) {
      do {
        uVar2 = uVar2 - 0x1c;
      } while (uVar9 != uVar2);
    }
    if (pvVar8 != (void *)0x0) {
      operator_delete(pvVar8);
    }
  }
  else {
LAB_11800a30:
    if (pMVar5 != (MemAlcBase *)0x0) {
      local_2c = operator_new(uVar9 * 0x1c,pMVar5,pcVar6,uVar2);
      if (local_2c != (undefined4 *)0x0) {
        local_28 = (uint)((ulonglong)(uVar9 * 0x1c) * 0x49249249 + 0x49249249 >> 0x23);
        goto LAB_11800b08;
      }
    }
  }
LAB_11800e04:
  iVar10 = *(int *)(param_1 + 0x18) + -0x1c;
  piVar4 = *(int **)(param_1 + 0x34);
  uVar2 = ((int)piVar4 - *(int *)(param_1 + 0x30) >> 2) + 1;
  if (uVar2 <= *(uint *)(param_1 + 0x38)) {
    if (piVar4 != (int *)0x0) {
      *piVar4 = iVar10;
    }
    *(int *)(param_1 + 0x34) = *(int *)(param_1 + 0x34) + 4;
    return iVar10;
  }
  pMVar5 = *(MemAlcBase **)(param_1 + 0x20);
  pcVar6 = *(char **)(param_1 + 0x24);
  uVar11 = *(uint *)(param_1 + 0x28);
  local_2c = (int *)0x0;
  local_28 = 0;
  uVar9 = *(uint *)(param_1 + 0x38);
  if (uVar2 == 0) goto LAB_11800fa0;
  if (uVar2 < uVar9 * 2) {
    if (pMVar5 == (MemAlcBase *)0x0) {
      if (uVar9 * 2 == 0) goto LAB_11800fa0;
    }
    else {
      local_2c = operator_new(uVar9 << 3,pMVar5,pcVar6,uVar11);
      if (local_2c != (int *)0x0) {
        local_28 = (uVar9 & 0x1fffffff) << 1;
        goto LAB_11800fa0;
      }
    }
  }
  if (pMVar5 == (MemAlcBase *)0x0) {
    return iVar10;
  }
  local_2c = operator_new(uVar2 * 4,pMVar5,pcVar6,uVar11);
  if (local_2c == (int *)0x0) {
    return iVar10;
  }
  local_28 = uVar2 & 0x3fffffff;
LAB_11800fa0:
  piVar1 = local_2c;
  piVar4 = *(int **)(param_1 + 0x30);
  piVar7 = *(int **)(param_1 + 0x34);
  if (((uint)((int)piVar7 - (int)piVar4 >> 2) <= local_28) && (piVar4 != piVar7)) {
    do {
      if (local_2c != (int *)0x0) {
        *local_2c = *piVar4;
      }
      piVar4 = piVar4 + 1;
      local_2c = local_2c + 1;
    } while (piVar4 != piVar7);
  }
  if (((int)local_2c - (int)piVar1 >> 2) + 1U <= local_28) {
    if (local_2c != (int *)0x0) {
      *local_2c = iVar10;
    }
    local_2c = local_2c + 1;
  }
  *(MemAlcBase **)(param_1 + 0x20) = pMVar5;
  *(char **)(param_1 + 0x24) = pcVar6;
  *(uint *)(param_1 + 0x28) = uVar11;
  pvVar8 = *(void **)(param_1 + 0x2c);
  *(int **)(param_1 + 0x2c) = piVar1;
  *(int **)(param_1 + 0x30) = piVar1;
  *(int **)(param_1 + 0x34) = local_2c;
  *(uint *)(param_1 + 0x38) = local_28;
  if (pvVar8 != (void *)0x0) {
    operator_delete(pvVar8);
  }
  return iVar10;
}


// FUNC 0x118010e0 FUN_118010e0 (Colosseum)
//   size 0x10 | file Colosseum+0x10e0 | callers(0) | datarefs 1

void FUN_118010e0(MsgDataAcsrBase *param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)MsgDataAcsrBase::~MsgDataAcsrBase(param_1);
  operator_delete(pvVar1);
  return;
}


// FUNC 0x118010f0 ->MsgDataAcsrBase::~MsgDataAcsrBase (Colosseum)
//   size 0x4 | file Colosseum+0x10f0 | callers(0) | datarefs 1
// veneer/thunk -> 0x0026fdb4 MsgDataAcsrBase::~MsgDataAcsrBase (static)

// FUNC 0x118010f4 FUN_118010f4 (Colosseum)
//   size 0xc | file Colosseum+0x10f4 | callers(0) | datarefs 1

void FUN_118010f4(int *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x118010fc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x14))();
  return;
}


// FUNC 0x11801100 col::ColosseumTask::vfunc_0x1c (Colosseum)
//   size 0x4 | file Colosseum+0x1100 | callers(0) | datarefs 1

void col::ColosseumTask::vfunc_0x1c(void)

{
  return;
}


// FUNC 0x11801104 col::ColosseumTask::vfunc_0x4c (Colosseum)
//   size 0x8 | file Colosseum+0x1104 | callers(0) | datarefs 1

undefined4 * col::ColosseumTask::vfunc_0x4c(void)

{
  return &gFrameBuf;
}


// FUNC 0x11801110 col::ColosseumTask::vfunc_0x3c (Colosseum)
//   size 0x4 | file Colosseum+0x1110 | callers(0) | datarefs 1

void col::ColosseumTask::vfunc_0x3c(void)

{
  return;
}


// FUNC 0x11801114 col::ColosseumTask::vfunc_0x40 (Colosseum)
//   size 0x4 | file Colosseum+0x1114 | callers(0) | datarefs 1

void col::ColosseumTask::vfunc_0x40(void)

{
  return;
}


// FUNC 0x11801118 col::ColosseumTask::vfunc_0x30 (Colosseum)
//   size 0x4 | file Colosseum+0x1118 | callers(0) | datarefs 1

void col::ColosseumTask::vfunc_0x30(void)

{
  return;
}


// FUNC 0x1180111c col::ColosseumTask::vfunc_0x20 (Colosseum)
//   size 0x4 | file Colosseum+0x111c | callers(0) | datarefs 1

void col::ColosseumTask::vfunc_0x20(void)

{
  return;
}


// FUNC 0x11801120 col::ColosseumTask::vfunc_0x38 (Colosseum)
//   size 0x4 | file Colosseum+0x1120 | callers(0) | datarefs 1

void col::ColosseumTask::vfunc_0x38(void)

{
  return;
}


// FUNC 0x11801124 col::ColosseumTask::vfunc_0x28 (Colosseum)
//   size 0x4 | file Colosseum+0x1124 | callers(0) | datarefs 1

void col::ColosseumTask::vfunc_0x28(void)

{
  return;
}


// FUNC 0x11801128 msys::MListWndPCore::vfunc_0x1c (Colosseum)
//   size 0x20 | file Colosseum+0x1128 | callers(0) | datarefs 1

void msys::MListWndPCore::vfunc_0x1c(int *param_1,undefined4 param_2,undefined4 *param_3)

{
  (**(code **)(*param_1 + 0x18))(param_1,param_2,*param_3,param_3[1],param_3[2]);
  return;
}


// FUNC 0x11801158 ->operator.delete (Colosseum)
//   size 0x4 | file Colosseum+0x1158 | callers(0) | datarefs 1
// veneer/thunk -> 0x00286514 operator.delete (static)

// FUNC 0x1180115c nn::fs::IInputStream::vfunc_0x0 (Colosseum)
//   size 0x4 | file Colosseum+0x115c | callers(0) | datarefs 1

void nn::fs::IInputStream::vfunc_0x0(void)

{
  return;
}


// FUNC 0x11801160 nn::fs::FileInputStream::vfunc_0x1c (Colosseum)
//   size 0x24 | file Colosseum+0x1160 | callers(0) | datarefs 1

void nn::fs::FileInputStream::vfunc_0x1c(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = detail::FileBase::TrySetPosition(CONCAT44(param_2,param_1 + 4));
  if (iVar1 < 0) {
    err::CTR::ThrowFatalErrAll(iVar1,0x11801174);
    return;
  }
  return;
}


// FUNC 0x11801184 nn::fs::FileInputStream::vfunc_0x18 (Colosseum)
//   size 0x8 | file Colosseum+0x1184 | callers(0) | datarefs 1

void nn::fs::FileInputStream::vfunc_0x18(int param_1,undefined4 param_2)

{
  detail::FileBase::TrySetPosition(CONCAT44(param_2,param_1 + 4));
  return;
}


// FUNC 0x1180118c nn::fs::FileInputStream::vfunc_0x2c (Colosseum)
//   size 0x2c | file Colosseum+0x118c | callers(0) | datarefs 1

int nn::fs::FileInputStream::vfunc_0x2c(int param_1,void *param_2,uint param_3,int param_4)

{
  int iVar1;
  int local_8;
  
  local_8 = param_4;
  iVar1 = detail::FileBase::TryRead((FileBase *)(param_1 + 4),&local_8,param_2,param_3);
  if (iVar1 < 0) {
    err::CTR::ThrowFatalErrAll(iVar1,0x118011ac);
  }
  return local_8;
}


// FUNC 0x118011b8 nn::fs::FileInputStream::vfunc_0xc (Colosseum)
//   size 0x2c | file Colosseum+0x11b8 | callers(0) | datarefs 1

void nn::fs::FileInputStream::vfunc_0xc(int param_1)

{
  int iVar1;
  undefined4 in_stack_00000000;
  
  iVar1 = detail::FileBase::TrySeek(param_1 + 4);
  if (-(iVar1 >> 0x1f) == 0) {
    return;
  }
  err::CTR::ThrowFatalErrAll(iVar1,0x118011d4,-(iVar1 >> 0x1f),in_stack_00000000);
  return;
}


// FUNC 0x118011e4 nn::fs::FileInputStream::vfunc_0x28 (Colosseum)
//   size 0x8 | file Colosseum+0x11e4 | callers(0) | datarefs 1

void nn::fs::FileInputStream::vfunc_0x28(int param_1,int *param_2,void *param_3,uint param_4)

{
  detail::FileBase::TryRead((FileBase *)(param_1 + 4),param_2,param_3,param_4);
  return;
}


// FUNC 0x118011ec nn::fs::FileInputStream::vfunc_0x8 (Colosseum)
//   size 0x18 | file Colosseum+0x11ec | callers(0) | datarefs 1

void nn::fs::FileInputStream::vfunc_0x8(int param_1)

{
  detail::FileBase::TrySeek(param_1 + 4);
  return;
}


// FUNC 0x11801204 nn::fs::FileInputStream::vfunc_0x4 (Colosseum)
//   size 0x40 | file Colosseum+0x1204 | callers(0) | datarefs 1

void nn::fs::FileInputStream::vfunc_0x4(void *param_1)

{
  if ((*(uint *)((int)param_1 + 4) & 0xfffffffe) != 0) {
    if ((*(uint *)((int)param_1 + 4) & 1) != 0) {
      nndbgPanic();
    }
    CTR::MPCore::detail::UserFileSystem::CloseFile
              ((void *)(*(uint *)((int)param_1 + 4) & 0xfffffffe));
    *(uint *)((int)param_1 + 4) = 0;
  }
  operator_delete(param_1);
  return;
}


// FUNC 0x11801244 nn::fs::FileInputStream::vfunc_0x0 (Colosseum)
//   size 0x3c | file Colosseum+0x1244 | callers(0) | datarefs 1

int nn::fs::FileInputStream::vfunc_0x0(int param_1)

{
  if ((*(uint *)(param_1 + 4) & 0xfffffffe) != 0) {
    if ((*(uint *)(param_1 + 4) & 1) != 0) {
      nndbgPanic();
    }
    CTR::MPCore::detail::UserFileSystem::CloseFile((void *)(*(uint *)(param_1 + 4) & 0xfffffffe));
    *(uint *)(param_1 + 4) = 0;
  }
  return param_1;
}


// FUNC 0x11801280 FUN_11801280 (Colosseum)
//   size 0x2c | file Colosseum+0x1280 | callers(2) 0x118061f4 0x1180449c

void FUN_11801280(undefined4 param_1,uint param_2,int param_3,undefined4 param_4,undefined1 param_5)

{
  undefined1 uStack00000000;
  
  if (param_3 + 1U < param_2) {
    param_2 = param_3 + 1U;
  }
  __c89vswprintf(param_1,param_2,param_4,&param_5);
  return;
}


// FUNC 0x118012ec FUN_118012ec (Colosseum)
//   size 0x15b8 | file Colosseum+0x12ec | callers(0)

void FUN_118012ec(void *param_1)

{
  byte bVar1;
  short sVar2;
  short sVar3;
  char cVar4;
  short sVar5;
  LytResourceMan *this;
  void *pvVar6;
  MLyt *pMVar7;
  MLyt *pMVar8;
  MListWndPBase *this_00;
  int *piVar9;
  undefined4 uVar10;
  AnimButton *this_01;
  LytAnim *this_02;
  BootInfo *pBVar11;
  code *pcVar12;
  int iVar13;
  wchar_t *pwVar14;
  int *piVar15;
  int iVar16;
  int iVar17;
  uint uVar18;
  MCursorBase *pMVar19;
  uint uVar20;
  MDfxChr *pMVar21;
  MChrBase *pMVar22;
  char cVar23;
  short *psVar24;
  undefined4 *puVar25;
  bool bVar26;
  uint in_fpscr;
  undefined4 extraout_s0;
  float fVar27;
  undefined4 auStackY_328 [128];
  LytLocalize aLStack_108 [16];
  undefined4 local_f8;
  LytAnim local_e4 [4];
  undefined4 local_e0;
  undefined4 uStack_dc;
  undefined4 local_d8;
  undefined2 local_d4;
  undefined2 local_d2;
  AnimTransform *local_d0;
  undefined4 local_cc;
  MLyt *local_c8;
  LytAnim *local_c0;
  MChrBase *local_b4;
  InitParam aIStack_b0 [20];
  undefined4 local_9c;
  undefined1 local_7f;
  MCursorBase *local_68;
  int local_64;
  LytAnim aLStack_60 [4];
  undefined4 local_5c;
  int local_58;
  undefined4 local_54;
  undefined2 local_50;
  undefined2 local_4e;
  AnimTransform *local_4c;
  MChrBase *local_44;
  
  if (*(int *)((int)param_1 + 8) == 0) {
    *(int *)((int)param_1 + 8) = msys::MComSys::_sys;
  }
  this = (LytResourceMan *)((int)param_1 + 0x12a30);
  iVar17 = *(int *)((int)param_1 + 8);
  ad::lyt::LytResourceMan::init(this);
  pvVar6 = (void *)ad::fw::Resource::getFileData((Resource *)((int)param_1 + 0x12aa4));
  ad::lyt::LytResourceMan::registerArc(this,pvVar6,".");
  pMVar7 = (MLyt *)((int)param_1 + 0x12bb4);
  msys::MLyt::init(pMVar7,iVar17 + 0xd2f00,1);
  msys::MLyt::createLyt(pMVar7,this,"MINIGAME_COLISEUM_U.bflyt");
  MoveVBase::stop((MoveVBase *)((int)param_1 + 0x12c80));
  *(undefined4 *)((int)param_1 + 0x12c9c) = 0;
  *(undefined4 *)((int)param_1 + 0x12ca0) = 0;
  *(undefined4 *)((int)param_1 + 0x12ca4) = 0xc3480000;
  *(undefined4 *)((int)param_1 + 0x12c84) = *(undefined4 *)((int)param_1 + 0x12c9c);
  *(undefined4 *)((int)param_1 + 0x12c88) = 0;
  *(undefined4 *)((int)param_1 + 0x12c8c) = 0xc3480000;
  *(undefined4 *)((int)param_1 + 0x12cf0) = 0x400;
  pMVar8 = (MLyt *)((int)param_1 + 0x12f5c);
  msys::MLyt::build(pMVar8,*(MemAlcBase **)(*(int *)((int)param_1 + 4) + 0x18),
                    (AnimeName *)&PTR_s_1_to_0_1180c1f8,0xe);
  msys::MLyt::init(pMVar8,iVar17 + 0xd3000,1);
  msys::MLyt::createLyt
            (pMVar8,this,"MINIGAME_COLISEUM_L.bflyt",(ButtonGroup *)((int)param_1 + 0x12a14),
             (MCursorBase *)((int)param_1 + 0x13304));
  MoveVBase::stop((MoveVBase *)((int)param_1 + 0x13028));
  *(undefined4 *)((int)param_1 + 0x13044) = 0;
  *(undefined4 *)((int)param_1 + 0x13048) = 0;
  *(undefined4 *)((int)param_1 + 0x1304c) = 0xc3480000;
  *(undefined4 *)((int)param_1 + 0x1302c) = *(undefined4 *)((int)param_1 + 0x13044);
  *(undefined4 *)((int)param_1 + 0x13030) = 0;
  *(undefined4 *)((int)param_1 + 0x13034) = 0xc3480000;
  *(undefined4 *)((int)param_1 + 0x13098) = 0x401;
  this_00 = (MListWndPBase *)((int)param_1 + 0x3df84);
  FUN_1180854c(this_00,param_1);
  FUN_11806ab4(this_00,(int)*(char *)((int)param_1 + 0x61013));
  *(undefined1 *)((int)param_1 + 0x3e0c5) = 0;
  msys::MListWndPBase::setEnableInput(this_00,false);
  MoveVBase::stop((MoveVBase *)((int)param_1 + 0x3e050));
  *(undefined4 *)((int)param_1 + 0x3e06c) = 0;
  *(undefined4 *)((int)param_1 + 0x3e070) = 0;
  *(undefined4 *)((int)param_1 + 0x3e074) = 0xc3480000;
  *(undefined4 *)((int)param_1 + 0x3e054) = *(undefined4 *)((int)param_1 + 0x3e06c);
  *(undefined4 *)((int)param_1 + 0x3e058) = 0;
  *(undefined4 *)((int)param_1 + 0x3e05c) = 0xc3480000;
  msys::MCellAnime::init
            ((MCellAnime *)((int)param_1 + 0x1335c),(Resource *)((int)param_1 + 0x12b2c));
  msys::MLyt::attachMChr
            (pMVar8,(MChrBase *)((int)param_1 + 0x1335c),"INS_OBJ_DS",(char *)0x0,(char *)0x0,
             (char *)0x0);
  msys::MCellAnime::init
            ((MCellAnime *)((int)param_1 + 0x135d8),(Resource *)((int)param_1 + 0x12b70));
  msys::MLyt::attachMChr
            (pMVar8,(MChrBase *)((int)param_1 + 0x135d8),"INS_OBJ_TXT",(char *)0x0,(char *)0x0,
             (char *)0x0);
  uVar18 = 0;
  do {
    iVar13 = msys::MComSys::_sys;
    iVar17 = *(int *)((int)param_1 + 8);
    if (*(int *)((int)param_1 + 8) == 0) {
      *(int *)((int)param_1 + 8) = msys::MComSys::_sys;
      iVar17 = iVar13;
    }
    iVar16 = msys::MComSys::_sys;
    iVar13 = iVar17;
    if (iVar17 == 0) {
      *(int *)((int)param_1 + 8) = msys::MComSys::_sys;
      iVar13 = iVar16;
    }
    pMVar21 = (MDfxChr *)((int)param_1 + uVar18 * 0x17c + 0x35a08);
    msys::MDfxChr::init(pMVar21,*(MemAlcBase **)(*(int *)((int)param_1 + 4) + 0x18),
                        *(MDfxSys **)(iVar13 + 0xe64f0),(Scene *)(iVar17 + 0x4aaa0),0x400);
    MoveVBase::stop((MoveVBase *)((int)param_1 + uVar18 * 0x17c + 0x35ad4));
    *(undefined4 *)((int)param_1 + uVar18 * 0x17c + 0x35af0) = 0;
    *(undefined4 *)((int)param_1 + uVar18 * 0x17c + 0x35af4) = 0;
    *(undefined4 *)((int)param_1 + uVar18 * 0x17c + 0x35af8) = 0;
    *(undefined4 *)((int)param_1 + uVar18 * 0x17c + 0x35ad8) = 0;
    *(undefined4 *)((int)param_1 + uVar18 * 0x17c + 0x35adc) = 0;
    *(undefined4 *)((int)param_1 + uVar18 * 0x17c + 0x35ae0) = 0;
    msys::MLyt::attachMChr
              (pMVar7,(MChrBase *)pMVar21,(&PTR_s_RECORD_TOROPHY_01_11814460)[uVar18],(char *)0x0,
               (char *)0x0,(char *)0x0);
    iVar17 = msys::MComSys::_sys;
    uVar18 = uVar18 + 1 & 0xff;
  } while (uVar18 < 6);
  iVar13 = *(int *)((int)param_1 + 8);
  if (*(int *)((int)param_1 + 8) == 0) {
    *(int *)((int)param_1 + 8) = msys::MComSys::_sys;
    iVar13 = iVar17;
  }
  iVar16 = msys::MComSys::_sys;
  iVar17 = iVar13;
  if (iVar13 == 0) {
    *(int *)((int)param_1 + 8) = msys::MComSys::_sys;
    iVar17 = iVar16;
  }
  msys::MDfxChr::init((MDfxChr *)((int)param_1 + 0x362f0),
                      *(MemAlcBase **)(*(int *)((int)param_1 + 4) + 0x18),
                      *(MDfxSys **)(iVar17 + 0xe64f0),(Scene *)(iVar13 + 0x4aaa0),0x400);
  MoveVBase::stop((MoveVBase *)((int)param_1 + 0x363bc));
  *(undefined4 *)((int)param_1 + 0x363d8) = 0;
  *(undefined4 *)((int)param_1 + 0x363dc) = 0;
  *(undefined4 *)((int)param_1 + 0x363e0) = 0;
  *(undefined4 *)((int)param_1 + 0x363c0) = *(undefined4 *)((int)param_1 + 0x363d8);
  *(undefined4 *)((int)param_1 + 0x363c4) = *(undefined4 *)((int)param_1 + 0x363dc);
  *(undefined4 *)((int)param_1 + 0x363c8) = 0;
  msys::MLyt::attachMChr
            (pMVar7,(MChrBase *)((int)param_1 + 0x362f0),DAT_11814478,(char *)0x0,(char *)0x0,
             (char *)0x0);
  uVar18 = 0;
  do {
    iVar13 = msys::MComSys::_sys;
    iVar17 = *(int *)((int)param_1 + 8);
    if (*(int *)((int)param_1 + 8) == 0) {
      *(int *)((int)param_1 + 8) = msys::MComSys::_sys;
      iVar17 = iVar13;
    }
    iVar16 = msys::MComSys::_sys;
    iVar13 = iVar17;
    if (iVar17 == 0) {
      *(int *)((int)param_1 + 8) = msys::MComSys::_sys;
      iVar13 = iVar16;
    }
    pMVar21 = (MDfxChr *)((int)param_1 + uVar18 * 0x17c + 0x3646c);
    msys::MDfxChr::init(pMVar21,*(MemAlcBase **)(*(int *)((int)param_1 + 4) + 0x18),
                        *(MDfxSys **)(iVar13 + 0xe64f0),(Scene *)(iVar17 + 0x4aaa0),0x400);
    MoveVBase::stop((MoveVBase *)((int)param_1 + uVar18 * 0x17c + 0x36538));
    *(undefined4 *)((int)param_1 + uVar18 * 0x17c + 0x36554) = 0;
    *(undefined4 *)((int)param_1 + uVar18 * 0x17c + 0x36558) = 0;
    *(undefined4 *)((int)param_1 + uVar18 * 0x17c + 0x3655c) = 0;
    *(undefined4 *)((int)param_1 + uVar18 * 0x17c + 0x3653c) = 0;
    *(undefined4 *)((int)param_1 + uVar18 * 0x17c + 0x36540) = 0;
    *(undefined4 *)((int)param_1 + uVar18 * 0x17c + 0x36544) = 0;
    msys::MLyt::attachMChr
              (pMVar7,(MChrBase *)pMVar21,(char *)(&DAT_1181447c)[uVar18],(char *)0x0,(char *)0x0,
               (char *)0x0);
    iVar17 = msys::MComSys::_sys;
    uVar18 = uVar18 + 1 & 0xff;
  } while (uVar18 < 4);
  iVar13 = *(int *)((int)param_1 + 8);
  if (*(int *)((int)param_1 + 8) == 0) {
    *(int *)((int)param_1 + 8) = msys::MComSys::_sys;
    iVar13 = iVar17;
  }
  iVar16 = msys::MComSys::_sys;
  iVar17 = iVar13;
  if (iVar13 == 0) {
    *(int *)((int)param_1 + 8) = msys::MComSys::_sys;
    iVar17 = iVar16;
  }
  msys::MDfxChr::init((MDfxChr *)((int)param_1 + 0x36bd8),
                      *(MemAlcBase **)(*(int *)((int)param_1 + 4) + 0x18),
                      *(MDfxSys **)(iVar17 + 0xe64f0),(Scene *)(iVar13 + 0x4aba4),0x401);
  MoveVBase::stop((MoveVBase *)((int)param_1 + 0x36ca4));
  *(undefined4 *)((int)param_1 + 0x36cc0) = 0;
  *(undefined4 *)((int)param_1 + 0x36cc4) = 0;
  *(undefined4 *)((int)param_1 + 0x36cc8) = 0;
  *(undefined4 *)((int)param_1 + 0x36ca8) = *(undefined4 *)((int)param_1 + 0x36cc0);
  *(undefined4 *)((int)param_1 + 0x36cac) = *(undefined4 *)((int)param_1 + 0x36cc4);
  *(undefined4 *)((int)param_1 + 0x36cb0) = 0;
  msys::MLyt::attachMChr
            (pMVar8,(MChrBase *)((int)param_1 + 0x36bd8),"INS_TROPHY_EFFECT",(char *)0x0,(char *)0x0
             ,(char *)0x0);
  FUN_11802ab4((MListWndPBase *)((int)param_1 + 0x45110),param_1);
  MoveVBase::stop((MoveVBase *)((int)param_1 + 0x451dc));
  *(undefined4 *)((int)param_1 + 0x451f8) = 0;
  *(undefined4 *)((int)param_1 + 0x451fc) = 0;
  *(undefined4 *)((int)param_1 + 0x45200) = 0xc3480000;
  *(undefined4 *)((int)param_1 + 0x451e0) = *(undefined4 *)((int)param_1 + 0x451f8);
  *(undefined4 *)((int)param_1 + 0x451e4) = 0;
  *(undefined4 *)((int)param_1 + 0x451e8) = 0xc3480000;
  *(undefined1 *)((int)param_1 + 0x45251) = 0;
  msys::MListWndPBase::setEnableInput((MListWndPBase *)((int)param_1 + 0x45110),false);
  *(undefined **)((int)param_1 + 0x129fc) = &DAT_118043f0;
  *(undefined4 *)((int)param_1 + 0x12a00) = 0;
  if (*(char *)((int)param_1 + 0x132dc) == '\0') {
    return;
  }
  ad::lyt::LytLocalize::LytLocalize(aLStack_108);
  local_c8 = (MLyt *)((int)param_1 + 0x12bb4);
  ad::lyt::LytLocalize::localize(aLStack_108,*(Layout **)((int)param_1 + 0x12d04));
  pMVar8 = (MLyt *)((int)param_1 + 0x12f5c);
  ad::lyt::LytLocalize::localize(aLStack_108,*(Layout **)((int)param_1 + 0x130ac));
  local_f8 = 0;
  piVar9 = (int *)(*(int *)((int)param_1 + 4) + 4);
  puVar25 = *(undefined4 **)(local_c8 + 8);
  *(undefined4 **)(*(int *)(local_c8 + 4) + 4) = puVar25;
  *puVar25 = *(undefined4 *)(local_c8 + 4);
  pMVar7 = local_c8 + 4;
  if (pMVar7 != (MLyt *)0x0) {
    iVar17 = *piVar9;
    *(int **)(local_c8 + 8) = piVar9;
    *(int *)pMVar7 = iVar17;
    *(MLyt **)(iVar17 + 4) = pMVar7;
    *piVar9 = (int)pMVar7;
  }
  *(undefined4 *)(local_c8 + 0x13c) = 0x400;
  piVar15 = (int *)(*(int *)((int)param_1 + 4) + 0xc);
  puVar25 = *(undefined4 **)((int)param_1 + 0x12f64);
  *(undefined4 **)(*(int *)((int)param_1 + 0x12f60) + 4) = puVar25;
  *puVar25 = *(undefined4 *)((int)param_1 + 0x12f60);
  piVar9 = (int *)((int)param_1 + 0x12f60);
  if (piVar9 != (int *)0x0) {
    iVar17 = *piVar15;
    *(int **)((int)param_1 + 0x12f64) = piVar15;
    *piVar9 = iVar17;
    *(int **)(iVar17 + 4) = piVar9;
    *piVar15 = (int)piVar9;
  }
  *(undefined4 *)((int)param_1 + 0x13098) = 0x401;
  iVar17 = msys::MComSys::_sys;
  iVar16 = *(int *)((int)param_1 + 4);
  iVar13 = *(int *)((int)param_1 + 8);
  if (*(int *)((int)param_1 + 8) == 0) {
    *(int *)((int)param_1 + 8) = msys::MComSys::_sys;
    iVar13 = iVar17;
  }
  pvVar6 = *(void **)(iVar13 + 0xe904c);
  *(undefined4 *)((int)param_1 + 0x3df38) = *(undefined4 *)(iVar16 + 0x18);
  *(undefined4 *)((int)param_1 + 0x3df3c) = 0;
  *(undefined4 *)((int)param_1 + 0x3df40) = 0x401;
  *(undefined4 *)((int)param_1 + 0x3defc) = 0x401;
  *(undefined4 *)((int)param_1 + 0x3df00) = 0;
  *(undefined4 *)((int)param_1 + 0x3df04) = 0;
  *(undefined1 *)((int)param_1 + 0x3df24) = 1;
  *(undefined1 *)((int)param_1 + 0x3df25) = 0;
  *(undefined4 *)((int)param_1 + 0x3df2c) = 0xffffffff;
  *(undefined4 *)((int)param_1 + 0x3df30) = 0xffffffff;
  *(int *)((int)param_1 + 0x3df1c) = (int)param_1 + 0x3df34;
  *(undefined4 *)((int)param_1 + 0x3df20) = 0;
  Message::init((Message *)((int)param_1 + 0x37198));
  Message::setMsgDat((Message *)((int)param_1 + 0x37198),pvVar6);
  FUN_11806968((int)param_1 + 0x3704c);
  *(undefined4 *)((int)param_1 + 0x3df48) = 0x401;
  *(undefined4 *)((int)param_1 + 0x3df4c) = 0;
  *(undefined4 *)((int)param_1 + 0x3df50) = 0;
  *(undefined1 *)((int)param_1 + 0x3df70) = 1;
  *(undefined1 *)((int)param_1 + 0x3df71) = 0;
  *(undefined4 *)((int)param_1 + 0x3df78) = 0xffffffff;
  *(undefined4 *)((int)param_1 + 0x3df7c) = 0xffffffff;
  *(int *)((int)param_1 + 0x3df68) = (int)param_1 + 0x3df80;
  *(undefined4 *)((int)param_1 + 0x3df6c) = 0;
  piVar15 = (int *)(iVar16 + 0xc);
  puVar25 = *(undefined4 **)((int)param_1 + 0x37054);
  *(undefined4 **)(*(int *)((int)param_1 + 0x37050) + 4) = puVar25;
  *puVar25 = *(undefined4 *)((int)param_1 + 0x37050);
  piVar9 = (int *)((int)param_1 + 0x37050);
  if (piVar9 != (int *)0x0) {
    iVar17 = *piVar15;
    *(int **)((int)param_1 + 0x37054) = piVar15;
    *piVar9 = iVar17;
    *(int **)(iVar17 + 4) = piVar9;
    *piVar15 = (int)piVar9;
  }
  *(undefined4 *)((int)param_1 + 0x37188) = 0x401;
  local_44 = (MChrBase *)((int)param_1 + 0x3df84);
  msys::MLyt::attachMChr(pMVar8,local_44,"INS_LIST_MINIGAME",(char *)0x0,(char *)0x0,(char *)0x0);
  local_44[0x141] = (MChrBase)0x0;
  msys::MLyt::attachMChr
            (pMVar8,(MChrBase *)((int)param_1 + 0x45110),"INS_LIST",(char *)0x0,(char *)0x0,
             (char *)0x0);
  local_64 = (int)param_1 + 0x4c194;
  *(undefined1 *)((int)param_1 + 0x45251) = 0;
  FUN_118019c0(local_64,param_1);
  uVar10 = *(undefined4 *)(*(int *)((int)param_1 + 4) + 0x18);
  *(undefined4 *)((int)param_1 + 0x1a494) = 0x401;
  *(undefined4 *)((int)param_1 + 0x1a488) = uVar10;
  *(undefined4 *)((int)param_1 + 0x1a48c) = 0;
  *(undefined4 *)((int)param_1 + 0x1a490) = 0;
  MessageSimple::init((MessageSimple *)((int)param_1 + 0x139a0));
  FUN_11806968((MChrBase *)((int)param_1 + 0x13854));
  *(undefined1 *)((int)param_1 + 0x1945c) = 1;
  *(undefined1 *)((int)param_1 + 0x1945d) = 1;
  *(undefined1 *)((int)param_1 + 0x1a479) = 1;
  MessageWriter::setFontColor((MessageWriter *)((int)param_1 + 0x139a0),0xe6e6e6ff,false);
  *(undefined1 *)((int)param_1 + 0x1a478) = 3;
  *(undefined **)((int)param_1 + 0x191c8) = &DAT_003fc0f8;
  MoveVBase::stop((MoveVBase *)((int)param_1 + 0x13920));
  *(undefined4 *)((int)param_1 + 0x1393c) = 0;
  *(undefined4 *)((int)param_1 + 0x13940) = 0;
  *(undefined4 *)((int)param_1 + 0x13944) = 0x3c23d70a;
  *(undefined4 *)((int)param_1 + 0x13924) = *(undefined4 *)((int)param_1 + 0x1393c);
  *(undefined4 *)((int)param_1 + 0x13928) = 0;
  *(undefined4 *)((int)param_1 + 0x1392c) = 0x3c23d70a;
  msys::MLyt::attachMChr
            (pMVar8,(MChrBase *)((int)param_1 + 0x13854),"INS_TITLE_TEXT","GUIDE_TXT_base",
             (char *)0x0,(char *)0x0);
  uVar10 = *(undefined4 *)(*(int *)((int)param_1 + 4) + 0x18);
  *(undefined4 *)((int)param_1 + 0x210d8) = 0x401;
  *(undefined4 *)((int)param_1 + 0x210cc) = uVar10;
  *(undefined4 *)((int)param_1 + 0x210d0) = 0;
  pMVar22 = (MChrBase *)((int)param_1 + 0x1a498);
  *(undefined4 *)((int)param_1 + 0x210d4) = 0;
  MessageSimple::init((MessageSimple *)((int)param_1 + 0x1a5e4));
  FUN_11806968(pMVar22);
  *(undefined1 *)((int)param_1 + 0x200a0) = 0;
  *(undefined1 *)((int)param_1 + 0x200a1) = 1;
  *(undefined1 *)((int)param_1 + 0x210bd) = 1;
  MessageWriter::setFontColor((MessageWriter *)((int)param_1 + 0x1a5e4),0x373737ff,false);
  *(undefined1 *)((int)param_1 + 0x210bc) = 4;
  *(undefined **)((int)param_1 + 0x1fe0c) = &DAT_003fc140;
  MoveVBase::stop((MoveVBase *)((int)param_1 + 0x1a564));
  *(undefined4 *)((int)param_1 + 0x1a580) = 0xc30c0000;
  *(undefined4 *)((int)param_1 + 0x1a568) = 0xc30c0000;
  *(undefined4 *)((int)param_1 + 0x1a584) = 0;
  *(undefined4 *)((int)param_1 + 0x1a588) = 0x3c23d70a;
  *(undefined4 *)((int)param_1 + 0x1a56c) = 0;
  *(undefined4 *)((int)param_1 + 0x1a570) = 0x3c23d70a;
  msys::MLyt::attachMChr(pMVar8,pMVar22,"INS_TEXT_GUIDE","GUIDE_TXT_base",(char *)0x0,(char *)0x0);
  iVar17 = msys::MComSys::_sys;
  iVar13 = *(int *)((int)param_1 + 8);
  if (*(int *)((int)param_1 + 8) == 0) {
    *(int *)((int)param_1 + 8) = msys::MComSys::_sys;
    iVar13 = iVar17;
  }
  local_58 = (int)param_1 + 0x60b04;
  FUN_118020bc(local_58,iVar13,pMVar8,pMVar22);
  ad::lyt::LytNumReel3::InitParam::InitParam(aIStack_b0);
  iVar17 = msys::MComSys::_sys;
  iVar13 = *(int *)((int)param_1 + 8);
  if (*(int *)((int)param_1 + 8) == 0) {
    *(int *)((int)param_1 + 8) = msys::MComSys::_sys;
    iVar13 = iVar17;
  }
  msys::MLytNumRes::set((MLytNumRes *)(iVar13 + 0x844),aIStack_b0,0,2);
  local_7f = 0;
  local_9c = GameWork::getCoin((GameWork *)&gGameWork);
  iVar17 = msys::MComSys::_sys;
  iVar13 = *(int *)((int)param_1 + 8);
  if (*(int *)((int)param_1 + 8) == 0) {
    *(int *)((int)param_1 + 8) = msys::MComSys::_sys;
    iVar13 = iVar17;
  }
  msys::MLytNum::init((MLytNum *)((int)param_1 + 0x355a8),aIStack_b0,
                      (LytDrawData *)(iVar13 + 0xd3000),pMVar8,"INS_COUNT","btn_COIN_all",
                      (char *)0x0,(char *)0x0);
  uVar10 = *(undefined4 *)(*(int *)((int)param_1 + 4) + 0x18);
  *(undefined4 *)((int)param_1 + 0x2e960) = 0x401;
  *(undefined4 *)((int)param_1 + 0x2e954) = uVar10;
  *(undefined4 *)((int)param_1 + 0x2e958) = 0;
  *(undefined4 *)((int)param_1 + 0x2e95c) = 0;
  local_b4 = (MChrBase *)((int)param_1 + 0x27d20);
  MessageSimple::init((MessageSimple *)((int)param_1 + 0x27e6c));
  FUN_11806968((MChrBase *)((int)param_1 + 0x27d20));
  *(undefined1 *)((int)param_1 + 0x2d928) = 1;
  *(undefined1 *)((int)param_1 + 0x2d929) = 1;
  msys::MLyt::attachMChr(pMVar8,local_b4,"INS_ENEMY_NAME_TEXT",(char *)0x0,(char *)0x0,(char *)0x0);
  uVar10 = *(undefined4 *)(*(int *)((int)param_1 + 4) + 0x18);
  *(undefined4 *)((int)param_1 + 0x355a4) = 0x400;
  *(undefined4 *)((int)param_1 + 0x35598) = uVar10;
  *(undefined4 *)((int)param_1 + 0x3559c) = 0;
  *(undefined4 *)((int)param_1 + 0x355a0) = 0;
  MessageSimple::init((MessageSimple *)((int)param_1 + 0x2eab0));
  FUN_11806968((MChrBase *)((int)param_1 + 0x2e964));
  *(undefined1 *)((int)param_1 + 0x3456c) = 1;
  *(undefined1 *)((int)param_1 + 0x3456d) = 1;
  msys::MLyt::attachMChr
            (local_c8,(MChrBase *)((int)param_1 + 0x2e964),"INS_ENEMY_NAME_TEXT",(char *)0x0,
             (char *)0x0,(char *)0x0);
  iVar17 = 0;
  do {
    this_01 = (AnimButton *)
              ad::ctrl::ButtonGroup::FindButtonByName
                        ((ButtonGroup *)((int)param_1 + 0x12a14),(char *)auStackY_328[iVar17 + 0x80]
                        );
    *(AnimButton **)((int)param_1 + iVar17 * 4 + 0x13340) = this_01;
    ad::ctrl::AnimButton::SetStateChangeCallback
              (this_01,(_func_void_AnimButton_ptr_State_State_void_ptr *)&DAT_11808a3c,param_1);
    *(int *)(*(int *)((int)param_1 + iVar17 * 4 + 0x13340) + 0x48) = iVar17;
    piVar9 = *(int **)((int)param_1 + iVar17 * 4 + 0x13340);
    (**(code **)(*piVar9 + 0x28))(piVar9,0);
    iVar17 = iVar17 + 1;
  } while (iVar17 < 7);
  iVar17 = msys::MLyt::getParts(pMVar8,"btn_GUIDE",(char *)0x0,(char *)0x0);
  *(byte *)(iVar17 + 0x44) = *(byte *)(iVar17 + 0x44) & 0xfe;
  iVar17 = msys::MComSys::_sys;
  iVar13 = *(int *)((int)param_1 + 8);
  if (*(int *)((int)param_1 + 8) == 0) {
    *(int *)((int)param_1 + 8) = msys::MComSys::_sys;
    iVar13 = iVar17;
  }
  pMVar19 = (MCursorBase *)((int)param_1 + 0x13304);
  local_68 = pMVar19;
  iVar17 = ad::fw::TaskBase::isFps30(*(TaskBase **)(iVar13 + 4));
  uVar10 = extraout_s0;
  if (iVar17 != 0) {
    uVar10 = 0x40000000;
  }
  if (iVar17 == 0) {
    uVar10 = 0x3f800000;
  }
  (**(code **)(*(int *)pMVar19 + 8))(uVar10,pMVar19,iVar13 + 0xe9124);
  pMVar19 = local_68;
  uVar18 = 0;
  if (*(int *)(local_68 + 0x30) == 0) {
    cVar23 = '\0';
  }
  else if (*(int *)(local_68 + 0x34) == 0) {
    cVar23 = '\x01';
  }
  else if (*(int *)(local_68 + 0x38) == 0) {
    cVar23 = '\x02';
  }
  else {
    cVar23 = -1;
  }
  do {
    cVar4 = (char)uVar18;
    uVar10 = msys::MLyt::getParts
                       (pMVar8,(char *)auStackY_328[uVar18 + 0x80],(char *)0x0,(char *)0x0);
    uVar18 = uVar18 + 1;
    *(undefined4 *)(pMVar19 + (char)(cVar23 + cVar4) * 4 + 0x30) = uVar10;
  } while (uVar18 < 3);
  msys::MCursorBase::setVisible(local_68,false);
  uVar10 = *(undefined4 *)((int)param_1 + 0x13358);
  *(undefined4 *)(local_58 + 0x488) = *(undefined4 *)((int)param_1 + 0x13354);
  *(undefined4 *)(local_58 + 0x48c) = uVar10;
  msys::MLyt::setAnimeInfo(pMVar8,9,0);
  msys::MLyt::setAnimeInfo(pMVar8,10,0);
  sVar5 = msys::MLyt::createAnimeAutoSlot(pMVar8,"LOOP","btn_NEXTpage",(char *)0x0);
  uVar10 = msys::MLyt::getAnim(pMVar8,sVar5);
  *(undefined4 *)((int)param_1 + 0x60ff0) = uVar10;
  local_e4[0] = (LytAnim)0x0;
  local_e0 = 0;
  uStack_dc = 0x3f800000;
  local_d8 = 0;
  local_d4 = 1;
  local_d2 = 0;
  local_d0 = (AnimTransform *)0x0;
  local_cc = 0;
  ad::lyt::LytAnim::init(local_e4,*(Layout **)(local_c8 + 0x150),"FADE_IN","");
  uVar10 = ad::lyt::AnimTransform::GetFrameSize(local_d0);
  fVar27 = (float)VectorUnsignedToFloat(uVar10,(byte)(in_fpscr >> 0x16) & 3);
  ad::lyt::LytAnim::stopAndSetFrm(local_e4,fVar27);
  ad::lyt::LytAnim::term(local_e4,true);
  ad::lyt::LytAnim::init
            ((LytAnim *)((int)param_1 + 0x60fb8),*(Layout **)(local_c8 + 0x150),"SET_ML_K","");
  fVar27 = (float)VectorSignedToFloat((int)*(char *)((int)param_1 + 0x61013),
                                      (byte)(in_fpscr >> 0x16) & 3);
  ad::lyt::LytAnim::stopAndSetFrm((LytAnim *)((int)param_1 + 0x60fb8),fVar27);
  ad::lyt::LytAnim::init
            ((LytAnim *)((int)param_1 + 0x60fd4),*(Layout **)((int)param_1 + 0x130ac),"SET_BATTLE",
             "");
  fVar27 = (float)VectorSignedToFloat((int)*(char *)((int)param_1 + 0x61013),
                                      (byte)(in_fpscr >> 0x16) & 3);
  ad::lyt::LytAnim::stopAndSetFrm((LytAnim *)((int)param_1 + 0x60fd4),fVar27);
  this_02 = (LytAnim *)((int)param_1 + 0x60f9c);
  ad::lyt::LytAnim::init(this_02,*(Layout **)(local_c8 + 0x150),"SET_COMPLETE","");
  fVar27 = (float)VectorSignedToFloat((int)*(char *)((int)param_1 +
                                                    *(char *)((int)param_1 + 0x61013) + 0x61014),
                                      (byte)(in_fpscr >> 0x16) & 3);
  ad::lyt::LytAnim::stopAndSetFrm(this_02,fVar27);
  ad::lyt::LytAnim::init(local_e4,*(Layout **)((int)param_1 + 0x130ac),"FADE_IN","");
  uVar10 = ad::lyt::AnimTransform::GetFrameSize(local_d0);
  fVar27 = (float)VectorUnsignedToFloat(uVar10,(byte)(in_fpscr >> 0x16) & 3);
  ad::lyt::LytAnim::stopAndSetFrm(local_e4,fVar27);
  ad::lyt::LytAnim::term(local_e4,true);
  FUN_11805fa4(param_1);
  local_d8 = 0;
  uVar18 = 0;
  if (*(char *)((int)param_1 + 0x61013) == '\0') {
    do {
      msys::MDfxChr::playDfx((MDfxChr *)((int)param_1 + uVar18 * 0x17c + 0x35a08),0x29);
      uVar20 = uVar18 + 1 & 0xff;
      *(undefined2 *)(*(int *)((int)param_1 + uVar18 * 0x17c + 0x35b5c) + 0xf2) = 0xffff;
      uVar18 = uVar20;
    } while (uVar20 < 6);
    msys::MDfxChr::playDfx((MDfxChr *)((int)param_1 + 0x362f0),0x2b);
    *(undefined2 *)(*(int *)((int)param_1 + 0x36444) + 0xf2) = 0xffff;
  }
  else {
    do {
      msys::MDfxChr::playDfx((MDfxChr *)((int)param_1 + uVar18 * 0x17c + 0x3646c),0x2e);
      uVar20 = uVar18 + 1 & 0xff;
      *(undefined2 *)(*(int *)((int)param_1 + uVar18 * 0x17c + 0x365c0) + 0xf2) = 0xffff;
      uVar18 = uVar20;
    } while (uVar20 < 4);
  }
  iVar17 = GameMain::GameModeOld();
  if (iVar17 == 10 || iVar17 == 0) {
    *(undefined1 *)((int)param_1 + 0x61012) = 0;
    *(undefined1 *)((int)param_1 + 0x61011) = 0;
    iVar13 = col::GetBootInfo();
    cVar23 = *(char *)(iVar13 + 0x20d);
    uVar18 = (uint)cVar23;
    if (iVar17 == 10) {
      iVar17 = btl::GetBootInfo();
      bVar26 = *(char *)(iVar17 + 0xcd) == '\x01';
      *(bool *)((int)param_1 + 0x61010) = bVar26;
      if ((5 < (int)uVar18) && (uVar18 != 0xc && bVar26)) {
        iVar17 = col::GetBootInfo();
        cVar23 = *(char *)(iVar17 + 0x20d);
        *(char *)(iVar17 + 0x20d) = cVar23 + '\x01';
        iVar17 = msys::MComSys::_sys;
        iVar16 = (int)(char)(cVar23 + -5);
        iVar13 = *(int *)((int)param_1 + 8);
        if (*(int *)((int)param_1 + 8) == 0) {
          *(int *)((int)param_1 + 8) = msys::MComSys::_sys;
          iVar13 = iVar17;
        }
        uVar10 = LMS_GetTextIndexByLabel(iVar13 + 0xe9058,(&DAT_1180c270)[iVar16 * 7]);
        pwVar14 = (wchar_t *)LMS_GetText(iVar13 + 0xe9058,uVar10);
        msys::MMsg::playStr((MMsg *)local_b4,pwVar14,(InsParam *)0x0,false);
        ad::lyt::LytAnim::init
                  ((LytAnim *)(auStackY_328 + 0x81),*(Layout **)(local_c8 + 0x150),"3_to_4","");
        uVar10 = ad::lyt::AnimTransform::GetFrameSize((AnimTransform *)"btn_R");
        fVar27 = (float)VectorUnsignedToFloat(uVar10,(byte)(in_fpscr >> 0x16) & 3);
        ad::lyt::LytAnim::stopAndSetFrm((LytAnim *)(auStackY_328 + 0x81),fVar27);
        ad::lyt::LytAnim::term((LytAnim *)(auStackY_328 + 0x81),true);
        ad::lyt::LytAnim::init
                  ((LytAnim *)(auStackY_328 + 0x81),*(Layout **)((int)param_1 + 0x130ac),
                   "SET_ENEMY_IMG","");
        fVar27 = (float)VectorSignedToFloat(iVar16,(byte)(in_fpscr >> 0x16) & 3);
        ad::lyt::LytAnim::stopAndSetFrm((LytAnim *)(auStackY_328 + 0x81),fVar27);
        ad::lyt::LytAnim::term((LytAnim *)(auStackY_328 + 0x81),true);
        msys::MLyt::stopAnimeAndSetEnd(pMVar8,6,1,(char *)0x0,(char *)0x0);
        msys::MLyt::createAnimeAutoSlot(pMVar8,"4_to_5",(char *)0x0,(char *)0x0);
        ad::lyt::LytAnim::stopAndSetFrm(this_02,0.0);
        Frm::play((Frm *)((int)param_1 + 0x60ffc),60.0);
        *(code **)((int)param_1 + 0x12a04) = FUN_118082f0;
        *(undefined4 *)((int)param_1 + 0x12a08) = 0;
        goto LAB_11803f38;
      }
      pBVar11 = (BootInfo *)col::GetBootInfo();
      col::BootInfo::dataPartyRestor(pBVar11);
      if (*(char *)((int)param_1 + 0x61010) == '\0') {
        if (5 < (int)uVar18) {
          uVar18 = 6;
        }
        FUN_11805e48(local_64,&DAT_1180c274 + uVar18 * 0x1c);
        pBVar11 = (BootInfo *)col::GetBootInfo();
        col::BootInfo::restoreBgm(pBVar11);
      }
      else {
        if (5 < (int)uVar18) {
          uVar18 = 6;
        }
        piVar9 = (int *)msys::MListWndPBase::getListWnd((MListWndPBase *)local_44);
        (**(code **)(*piVar9 + 0x28))(piVar9,uVar18 & 0xff);
        puVar25 = &DAT_1180c268 + uVar18 * 7;
        bVar1 = (&DAT_1180c26c)[uVar18 * 0x1c];
        iVar17 = btl::GetBootInfo();
        uVar20 = (uint)bVar1 - (uint)*(byte *)(iVar17 + 0x129) & 0xff;
        if (*(char *)((int)param_1 + 0x61013) == '\0') {
          iVar17 = 0;
        }
        else {
          iVar17 = 10;
        }
        psVar24 = &DAT_003f9de0 + iVar17 + uVar18;
        sVar5 = *psVar24;
        *(byte *)((int)param_1 + 0x61011) = (byte)((uint)(int)sVar5 >> 0x1f);
        sVar2 = *psVar24;
        *(bool *)((int)param_1 + 0x61012) = (int)uVar20 < (int)sVar2;
        if (*(char *)((int)param_1 + 0x61010) != '\0') {
          sVar3 = (short)uVar20;
          if (sVar5 < 0) {
            ad::lyt::LytAnim::init
                      ((LytAnim *)(auStackY_328 + 0x80),*(Layout **)((int)param_1 + 0x130ac),
                       "CONGRATULATIONS_OFFON","");
            local_c0 = (LytAnim *)(auStackY_328 + 0x80);
            uVar10 = ad::lyt::AnimTransform::GetFrameSize((AnimTransform *)"btn_L");
            fVar27 = (float)VectorUnsignedToFloat(uVar10,(byte)(in_fpscr >> 0x16) & 3);
            ad::lyt::LytAnim::stopAndSetFrm(local_c0,fVar27);
            ad::lyt::LytAnim::term((LytAnim *)(auStackY_328 + 0x80),true);
            ad::lyt::LytAnim::init
                      ((LytAnim *)(auStackY_328 + 0x80),*(Layout **)((int)param_1 + 0x130ac),
                       "SET_TROPHY","");
            iVar17 = 0;
            if (*(char *)((int)param_1 + 0x61013) != '\0') {
              iVar17 = 7;
            }
            fVar27 = (float)VectorSignedToFloat(iVar17 + uVar18,(byte)(in_fpscr >> 0x16) & 3);
            ad::lyt::LytAnim::stopAndSetFrm((LytAnim *)(auStackY_328 + 0x80),fVar27);
            ad::lyt::LytAnim::term((LytAnim *)(auStackY_328 + 0x80),true);
            ad::lyt::LytAnim::init
                      ((LytAnim *)(auStackY_328 + 0x80),*(Layout **)((int)param_1 + 0x130ac),
                       "RESULT_WIN_POINT","");
            uVar10 = ad::lyt::AnimTransform::GetFrameSize((AnimTransform *)"btn_L");
            fVar27 = (float)VectorUnsignedToFloat(uVar10,(byte)(in_fpscr >> 0x16) & 3);
            ad::lyt::LytAnim::stopAndSetFrm((LytAnim *)(auStackY_328 + 0x80),fVar27);
            ad::lyt::LytAnim::term((LytAnim *)(auStackY_328 + 0x80),true);
            if (*(char *)((int)param_1 + 0x61013) == '\0') {
              FUN_11805eb0(param_1,&DAT_118143e8,uVar18);
            }
            else {
              FUN_11805eb0(param_1,&DAT_11814420,uVar18);
            }
            *psVar24 = sVar3;
            *(short *)((int)param_1 + uVar18 * 0x1c + 0x44f08) = sVar3;
            FUN_11806cf0(param_1);
            FUN_11805fa4(param_1);
          }
          else if ((int)uVar20 < (int)sVar2) {
            local_5c = 0;
            local_58 = 0x3f800000;
            local_54 = 0;
            local_50 = 1;
            local_4e = 0;
            ad::lyt::LytAnim::init
                      (aLStack_60,*(Layout **)((int)param_1 + 0x130ac),"RESULT_BEST_TURN_offon","");
            uVar10 = ad::lyt::AnimTransform::GetFrameSize(local_4c);
            fVar27 = (float)VectorUnsignedToFloat(uVar10,(byte)(in_fpscr >> 0x16) & 3);
            ad::lyt::LytAnim::stopAndSetFrm(aLStack_60,fVar27);
            ad::lyt::LytAnim::term(aLStack_60,true);
            local_54 = 0;
            *psVar24 = sVar3;
            *(short *)((int)param_1 + uVar18 * 0x1c + 0x44f08) = sVar3;
          }
          *(MListWndPBase *)(local_44 + 0x141) = (MListWndPBase)0x0;
          FUN_11805e48(local_64,puVar25 + 3);
        }
      }
    }
    else {
      iVar17 = hb::GetColiseumResult();
      *(bool *)((int)param_1 + 0x61010) = iVar17 == 1;
      if (iVar17 == 1) {
        piVar9 = (int *)msys::MListWndPBase::getListWnd((MListWndPBase *)local_44);
        (**(code **)(*piVar9 + 0x28))(piVar9,cVar23);
        iVar17 = 0;
        if (*(char *)((int)param_1 + 0x61013) != '\0') {
          iVar17 = 10;
        }
        iVar13 = (int)(short)(&DAT_003f9de0)[iVar17 + uVar18];
        *(byte *)((int)param_1 + 0x61011) = (byte)((uint)iVar13 >> 0x1f);
        *(undefined1 *)((int)param_1 + 0x61012) = 0;
        if (*(char *)((int)param_1 + 0x61010) != '\0') {
          if (iVar13 < 0) {
            ad::lyt::LytAnim::init
                      ((LytAnim *)(auStackY_328 + 0x80),*(Layout **)((int)param_1 + 0x130ac),
                       "CONGRATULATIONS_OFFON","");
            uVar10 = ad::lyt::AnimTransform::GetFrameSize((AnimTransform *)"btn_L");
            fVar27 = (float)VectorUnsignedToFloat(uVar10,(byte)(in_fpscr >> 0x16) & 3);
            ad::lyt::LytAnim::stopAndSetFrm((LytAnim *)(auStackY_328 + 0x80),fVar27);
            ad::lyt::LytAnim::term((LytAnim *)(auStackY_328 + 0x80),true);
            ad::lyt::LytAnim::init
                      ((LytAnim *)(auStackY_328 + 0x80),*(Layout **)((int)param_1 + 0x130ac),
                       "SET_TROPHY","");
            fVar27 = (float)VectorSignedToFloat(uVar18 + 7,(byte)(in_fpscr >> 0x16) & 3);
            ad::lyt::LytAnim::stopAndSetFrm((LytAnim *)(auStackY_328 + 0x80),fVar27);
            ad::lyt::LytAnim::term((LytAnim *)(auStackY_328 + 0x80),true);
            ad::lyt::LytAnim::init
                      ((LytAnim *)(auStackY_328 + 0x80),*(Layout **)((int)param_1 + 0x130ac),
                       "RESULT_WIN_POINT","");
            uVar10 = ad::lyt::AnimTransform::GetFrameSize((AnimTransform *)"btn_L");
            fVar27 = (float)VectorUnsignedToFloat(uVar10,(byte)(in_fpscr >> 0x16) & 3);
            ad::lyt::LytAnim::stopAndSetFrm((LytAnim *)(auStackY_328 + 0x80),fVar27);
            ad::lyt::LytAnim::term((LytAnim *)(auStackY_328 + 0x80),true);
            if (*(char *)((int)param_1 + 0x61013) == '\0') {
              FUN_11805eb0(param_1,&DAT_118143e8,uVar18);
            }
            else {
              FUN_11805eb0(param_1,&DAT_11814420,uVar18);
            }
            (&DAT_003f9de0)[iVar17 + uVar18] = 1;
            *(undefined2 *)((int)param_1 + uVar18 * 0x1c + 0x44f08) = 1;
          }
          *(MListWndPBase *)(local_44 + 0x141) = (MListWndPBase)0x0;
          FUN_11805e48(local_64,&DAT_1180c330 + uVar18 * 10);
        }
      }
      else {
        pBVar11 = (BootInfo *)col::GetBootInfo();
        col::BootInfo::restoreBgm(pBVar11);
        FUN_11805e48(local_64,&DAT_1180c330 + uVar18 * 10);
      }
    }
    pcVar12 = FUN_11804b58;
  }
  else {
    piVar9 = (int *)msys::MListWndPBase::getListWnd((MListWndPBase *)local_44);
    (**(code **)(*piVar9 + 0x28))(piVar9,0);
    pBVar11 = (BootInfo *)col::GetBootInfo();
    col::BootInfo::saveBgm(pBVar11);
    pcVar12 = FUN_11802a54;
  }
  *(code **)((int)param_1 + 0x12a04) = pcVar12;
  *(undefined4 *)((int)param_1 + 0x12a08) = 0;
LAB_11803f38:
  *(code **)((int)param_1 + 0x129fc) = FUN_11804f10;
  *(undefined4 *)((int)param_1 + 0x12a00) = 0;
  return;
}


// FUNC 0x118018b4 FUN_118018b4 (Colosseum)
//   size 0xd8 | file Colosseum+0x18b4 | callers(0) | datarefs 2

void FUN_118018b4(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = Backup::errorCode();
  if (iVar1 == 0) {
    iVar1 = Backup::isBusyFormat();
    if (iVar1 != 0) {
      return;
    }
    iVar1 = Backup::mount();
    if (iVar1 != 0) {
      iVar2 = Backup::rewriteSaveData((Backup *)(param_1 + 0x10));
      iVar1 = msys::MComSys::_sys;
      if (iVar2 != 0) {
        *(code **)(param_1 + 0x12a04) = FUN_118029c0;
        *(undefined4 *)(param_1 + 0x12a08) = 0;
        return;
      }
      iVar2 = *(int *)(param_1 + 8);
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar2 = iVar1;
      }
      CtrFS::unmountSaveData((CtrFS *)(*(int *)(iVar2 + 4) + 0x518));
    }
  }
  else if (iVar1 - 0x2001U < 2 || iVar1 == 0x2003) {
    *(undefined2 *)(Backup::_fs + 0x24) = 0;
    Backup::format();
    return;
  }
  *(code **)(param_1 + 0x12a04) = FUN_11806db4;
  *(undefined4 *)(param_1 + 0x12a08) = 0;
  return;
}


// FUNC 0x118019c0 FUN_118019c0 (Colosseum)
//   size 0x3c4 | file Colosseum+0x19c0 | callers(1) 0x118012ec

void FUN_118019c0(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  wchar_t *pwVar3;
  int iVar4;
  MLyt *this;
  MMsg *this_00;
  uint in_fpscr;
  float fVar5;
  InitParam aIStack_90 [20];
  undefined4 local_7c;
  undefined1 local_5f;
  LytAnim local_48 [4];
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined2 local_38;
  undefined2 local_36;
  AnimTransform *local_34;
  undefined4 local_30;
  
  *param_1 = param_2;
  ad::lyt::LytNumReel3::InitParam::InitParam(aIStack_90);
  iVar1 = msys::MComSys::_sys;
  iVar4 = *(int *)(param_2 + 8);
  if (*(int *)(param_2 + 8) == 0) {
    *(int *)(param_2 + 8) = msys::MComSys::_sys;
    iVar4 = iVar1;
  }
  msys::MLytNumRes::set((MLytNumRes *)(iVar4 + 0x844),aIStack_90,2,2,0x11);
  iVar1 = msys::MComSys::_sys;
  local_5f = 0;
  iVar4 = *(int *)(param_2 + 8);
  if (*(int *)(param_2 + 8) == 0) {
    *(int *)(param_2 + 8) = msys::MComSys::_sys;
    iVar4 = iVar1;
  }
  this = (MLyt *)(param_2 + 0x12f5c);
  msys::MLytNum::init((MLytNum *)(param_1 + 1),aIStack_90,(LytDrawData *)(iVar4 + 0xd3000),this,
                      "LV_DIGIT_01","pnl_MINIGAME_VCONDITION",(char *)0x0,(char *)0x0);
  msys::MLyt::attachMChr
            (this,(MChrBase *)(param_1 + 1),"LV_DIGIT_01","pnl_MINIGAME_VCONDITION",(char *)0x0,
             (char *)0x0);
  iVar1 = msys::MComSys::_sys;
  iVar4 = *(int *)(param_2 + 8);
  if (*(int *)(param_2 + 8) == 0) {
    *(int *)(param_2 + 8) = msys::MComSys::_sys;
    iVar4 = iVar1;
  }
  msys::MLytNumRes::set((MLytNumRes *)(iVar4 + 0x844),aIStack_90,0,2,0x11);
  iVar1 = msys::MComSys::_sys;
  local_5f = 0;
  local_7c = 0;
  iVar4 = *(int *)(param_2 + 8);
  if (*(int *)(param_2 + 8) == 0) {
    *(int *)(param_2 + 8) = msys::MComSys::_sys;
    iVar4 = iVar1;
  }
  msys::MLytNum::init((MLytNum *)(param_1 + 0x8d),aIStack_90,(LytDrawData *)(iVar4 + 0xd3000),this,
                      "COUNT","PRICE_ALL_1",(char *)0x0,(char *)0x0);
  iVar4 = *(int *)(*(int *)(param_2 + 4) + 0x18);
  param_1[0x5259] = 0x401;
  param_1[0x5256] = iVar4;
  param_1[0x5257] = 0;
  this_00 = (MMsg *)(param_1 + 0x3749);
  param_1[0x5258] = 0;
  MessageSimple::init((MessageSimple *)(param_1 + 0x379c));
  FUN_11806968(this_00);
  *(undefined1 *)(param_1 + 0x4e4b) = 0;
  *(undefined1 *)((int)param_1 + 0x1392d) = 1;
  iVar1 = msys::MComSys::_sys;
  iVar4 = *(int *)(param_2 + 8);
  if (*(int *)(param_2 + 8) == 0) {
    *(int *)(param_2 + 8) = msys::MComSys::_sys;
    iVar4 = iVar1;
  }
  uVar2 = LMS_GetTextIndexByLabel(iVar4 + 0xe9058,"MES_ShopMes_Info_Price");
  pwVar3 = (wchar_t *)LMS_GetText(iVar4 + 0xe9058,uVar2);
  msys::MMsg::playStr(this_00,pwVar3,(InsParam *)0x0,false);
  msys::MLyt::attachMChr
            (this,(MChrBase *)this_00,"INS_PRICE_TEXT","PRICE_ALL_1",(char *)0x0,(char *)0x0);
  iVar4 = *(int *)(*(int *)(param_2 + 4) + 0x18);
  param_1[0x1c37] = 0x401;
  param_1[0x1c34] = iVar4;
  param_1[0x1c35] = 0;
  param_1[0x1c36] = 0;
  MessageSimple::init((MessageSimple *)(param_1 + 0x17a));
  FUN_11806968((MChrBase *)(param_1 + 0x127));
  *(undefined1 *)(param_1 + 0x1c30) = 3;
  param_1[0x1784] = (int)&DAT_003fc0f8;
  MessageWriter::setFontColor((MessageWriter *)(param_1 + 0x17a),0xe6e6e6ff,true);
  *(undefined1 *)(param_1 + 0x1829) = 1;
  *(undefined1 *)((int)param_1 + 0x60a5) = 1;
  *(undefined1 *)((int)param_1 + 0x70c1) = 1;
  msys::MLyt::attachMChr
            (this,(MChrBase *)(param_1 + 0x127),"INS_TITLE",(char *)0x0,(char *)0x0,(char *)0x0);
  ad::lyt::LytAnim::init
            ((LytAnim *)(param_1 + 0x119),*(Layout **)(param_2 + 0x130ac),"SET_MODE",
             "pnl_MINIGAME_VCONDITION");
  ad::lyt::LytAnim::init
            ((LytAnim *)(param_1 + 0x120),*(Layout **)(param_2 + 0x130ac),"PRICE_onoff","");
  local_48[0] = (LytAnim)0x0;
  local_44 = 0;
  local_40 = 0x3f800000;
  local_3c = 0;
  local_38 = 1;
  local_36 = 0;
  local_34 = (AnimTransform *)0x0;
  local_30 = 0;
  ad::lyt::LytAnim::init
            (local_48,*(Layout **)(param_2 + 0x130ac),"SET_LV_DIGIT","pnl_MINIGAME_VCONDITION");
  uVar2 = ad::lyt::AnimTransform::GetFrameSize(local_34);
  fVar5 = (float)VectorUnsignedToFloat(uVar2,(byte)(in_fpscr >> 0x16) & 3);
  ad::lyt::LytAnim::stopAndSetFrm(local_48,fVar5);
  ad::lyt::LytAnim::term(local_48,false);
  local_3c = 0;
  iVar4 = *(int *)(*(int *)(param_2 + 4) + 0x18);
  param_1[0x3748] = 0x401;
  param_1[0x3745] = iVar4;
  param_1[0x3746] = 0;
  param_1[0x3747] = 0;
  MessageSimple::init((MessageSimple *)(param_1 + 0x1c8b));
  FUN_11806968((MChrBase *)(param_1 + 0x1c38));
  *(undefined1 *)(param_1 + 0x333a) = 1;
  *(undefined1 *)((int)param_1 + 0xcce9) = 1;
  *(undefined1 *)((int)param_1 + 0xdd05) = 1;
  MessageWriter::setFontColor((MessageWriter *)(param_1 + 0x1c8b),0xe6e6e6ff,true);
  msys::MLyt::attachMChr
            (this,(MChrBase *)(param_1 + 0x1c38),"INS_TEXT_CONDITION","pnl_MINIGAME_VCONDITION",
             (char *)0x0,(char *)0x0);
  *(undefined1 *)(param_1 + 0x525b) = 0xff;
  param_1[0x525a] = 0;
  *(undefined1 *)((int)param_1 + 0x1496d) = 1;
  return;
}


// FUNC 0x11801e4c FUN_11801e4c (Colosseum)
//   size 0x244 | file Colosseum+0x1e4c | callers(0) | datarefs 1

void FUN_11801e4c(int param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  bool bVar3;
  uint in_fpscr;
  float fVar4;
  
  uVar1 = *param_2;
  if ((uVar1 & 0x802) == 0) {
    if ((uVar1 & 0x401) == 0) {
      if ((uVar1 & 0x30) != 0) {
        FUN_11806814(param_1,0x110015,0,0,0);
        bVar3 = *(char *)(param_1 + 0x1331c) == '\0';
        *(bool *)(param_1 + 0x1331c) = bVar3;
        fVar4 = (float)VectorUnsignedToFloat((uint)bVar3,(byte)(in_fpscr >> 0x16) & 3);
        ad::lyt::LytAnim::stopAndSetFrm((LytAnim *)(param_1 + 0x60fb8),fVar4);
        fVar4 = (float)VectorUnsignedToFloat
                                 ((uint)(*(char *)(param_1 + 0x1331c) == '\x01'),
                                  (byte)(in_fpscr >> 0x16) & 3);
        ad::lyt::LytAnim::stopAndSetFrm((LytAnim *)(param_1 + 0x60fd4),fVar4);
        fVar4 = (float)VectorSignedToFloat((int)*(char *)((uint)(*(char *)(param_1 + 0x1331c) ==
                                                                '\x01') + param_1 + 0x61014),
                                           (byte)(in_fpscr >> 0x16) & 3);
        ad::lyt::LytAnim::stopAndSetFrm((LytAnim *)(param_1 + 0x60f9c),fVar4);
        uVar1 = 0;
        if (*(char *)(param_1 + 0x1331c) == '\0') {
          do {
            msys::MDfxChr::term((MDfxChr *)(param_1 + uVar1 * 0x17c + 0x3646c));
            uVar1 = uVar1 + 1 & 0xff;
          } while (uVar1 < 4);
          uVar1 = 0;
          do {
            iVar2 = param_1 + uVar1 * 0x17c;
            msys::MDfxChr::playDfx((MDfxChr *)(iVar2 + 0x35a08),0x29);
            uVar1 = uVar1 + 1 & 0xff;
            *(undefined2 *)(*(int *)(iVar2 + 0x35b5c) + 0xf2) = 0xffff;
          } while (uVar1 < 6);
          msys::MDfxChr::playDfx((MDfxChr *)(param_1 + 0x362f0),0x2b);
          *(undefined2 *)(*(int *)(param_1 + 0x36444) + 0xf2) = 0xffff;
        }
        else {
          do {
            msys::MDfxChr::term((MDfxChr *)(param_1 + uVar1 * 0x17c + 0x35a08));
            uVar1 = uVar1 + 1 & 0xff;
          } while (uVar1 < 6);
          msys::MDfxChr::term((MDfxChr *)(param_1 + 0x362f0));
          uVar1 = 0;
          do {
            iVar2 = param_1 + uVar1 * 0x17c;
            msys::MDfxChr::playDfx((MDfxChr *)(iVar2 + 0x3646c),0x2e);
            uVar1 = uVar1 + 1 & 0xff;
            *(undefined2 *)(*(int *)(iVar2 + 0x365c0) + 0xf2) = 0xffff;
          } while (uVar1 < 4);
        }
      }
    }
    else {
      (**(code **)(**(int **)(param_1 + *(char *)(param_1 + 0x1331c) * 4 + 0x13340) + 0x10))();
      FUN_118068b4(param_1,0);
    }
  }
  else {
    (**(code **)(**(int **)(param_1 + 0x1334c) + 0x10))();
    FUN_118068b4(param_1,0);
  }
  FUN_1180657c(param_1 + 0x13304);
  return;
}


// FUNC 0x118020bc FUN_118020bc (Colosseum)
//   size 0x198 | file Colosseum+0x20bc | callers(1) 0x118012ec

void FUN_118020bc(int *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  InitParam aIStack_c8 [72];
  LytAnim local_80 [4];
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined2 local_70;
  undefined2 local_6e;
  undefined4 local_6c;
  undefined4 local_68;
  char acStack_60 [64];
  
  *param_1 = param_2;
  param_1[8] = param_3;
  param_1[9] = param_4;
  Mem::Fill(param_1 + 1,0,0x10);
  uVar2 = 0;
  do {
    while( true ) {
      nn::nstd::TSPrintf(acStack_60,"%s_%02d",(&DAT_11814444)[uVar2 * 2],param_1[uVar2 + 1]);
      iVar1 = LMS_GetTextIndexByLabel(*param_1 + 0xe9058,acStack_60);
      if (iVar1 < 0) break;
      param_1[uVar2 + 1] = param_1[uVar2 + 1] + 1;
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 4);
  ad::lyt::LytNumReel3::InitParam::InitParam(aIStack_c8);
  msys::MLytNumRes::set((MLytNumRes *)(param_2 + 0x844),aIStack_c8,0,0xf,0xff);
  *(undefined1 *)((int)param_1 + 0x169) = 1;
  msys::MLytNum::init((MLytNum *)(param_1 + 10),aIStack_c8,(LytDrawData *)(param_2 + 0xd3000),
                      (MLyt *)param_1[8],"NUM_L","GUIDE_TXT_base",(char *)0x0,(char *)0x0);
  *(undefined1 *)((int)param_1 + 0x399) = 1;
  msys::MLytNum::init((MLytNum *)(param_1 + 0x96),aIStack_c8,(LytDrawData *)(param_2 + 0xd3000),
                      (MLyt *)param_1[8],"NUM_R","GUIDE_TXT_base",(char *)0x0,(char *)0x0);
  local_80[0] = (LytAnim)0x0;
  local_7c = 0;
  local_78 = 0x3f800000;
  local_74 = 0;
  local_70 = 1;
  local_6e = 0;
  local_6c = 0;
  local_68 = 0;
  iVar1 = msys::MLyt::getParts((MLyt *)param_1[8],"num_slash","GUIDE_TXT_base",(char *)0x0);
  ad::lyt::LytAnim::init(local_80,*(Layout **)(iVar1 + 0xac),"col_15","");
  ad::lyt::LytAnim::stopAndSetFrm(local_80,0.0);
  ad::lyt::LytAnim::term(local_80,true);
  return;
}


// FUNC 0x1180229c FUN_1180229c (Colosseum)
//   size 0x130 | file Colosseum+0x229c | callers(1) 0x11806e7c

void FUN_1180229c(int *param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int *piVar4;
  char acStack_50 [68];
  
  param_1[5] = 0;
  param_1[7] = (int)param_2;
  uVar3 = param_1[*param_2 + 1];
  iVar1 = msys::MLyt::getPane((MLyt *)param_1[8],"btn_L","GUIDE_TXT_base",(char *)0x0);
  *(byte *)(iVar1 + 0x44) = *(byte *)(iVar1 + 0x44) & 0xfe;
  iVar1 = msys::MLyt::getPane((MLyt *)param_1[8],"btn_R","GUIDE_TXT_base",(char *)0x0);
  *(byte *)(iVar1 + 0x44) = 1 < uVar3 | *(byte *)(iVar1 + 0x44) & 0xfe;
  (**(code **)(*(int *)param_1[0x122] + 0x28))((int *)param_1[0x122],0);
  (**(code **)(*(int *)param_1[0x123] + 0x28))((int *)param_1[0x123],1 < uVar3);
  ad::lyt::LytNumReel3::setValueInstant((LytNumReel3 *)(param_1 + 0x5e),1);
  ad::lyt::LytNumReel3::setValueInstant((LytNumReel3 *)(param_1 + 0xea),uVar3);
  nn::nstd::TSPrintf(acStack_50,"%s_%02d",(&DAT_11814444)[*(int *)param_1[7] * 2],param_1[5]);
  iVar1 = *param_1;
  piVar4 = (int *)param_1[9];
  uVar2 = LMS_GetTextIndexByLabel(iVar1 + 0xe9058,acStack_50);
  uVar2 = LMS_GetText(iVar1 + 0xe9058,uVar2);
  (**(code **)(*piVar4 + 0x3c))(piVar4,uVar2,0);
  return;
}


// FUNC 0x118023e8 FUN_118023e8 (Colosseum)
//   size 0x1d4 | file Colosseum+0x23e8 | callers(1) 0x11808a48

void FUN_118023e8(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  code *pcVar4;
  int *piVar5;
  char acStack_58 [68];
  
  iVar1 = param_1[5];
  param_1[5] = iVar1 + param_2;
  ad::lyt::LytNumReel3::setValueInstant((LytNumReel3 *)(param_1 + 0x5e),iVar1 + param_2 + 1);
  nn::nstd::TSPrintf(acStack_58,"%s_%02d",(&DAT_11814444)[*(int *)param_1[7] * 2],param_1[5]);
  iVar1 = *param_1;
  piVar5 = (int *)param_1[9];
  uVar2 = LMS_GetTextIndexByLabel(iVar1 + 0xe9058,acStack_58);
  uVar2 = LMS_GetText(iVar1 + 0xe9058,uVar2);
  (**(code **)(*piVar5 + 0x3c))(piVar5,uVar2,0);
  iVar1 = param_1[*(int *)param_1[7] + 1];
  if (param_1[5] == 0) {
    iVar3 = msys::MLyt::getPane((MLyt *)param_1[8],"btn_L","GUIDE_TXT_base",(char *)0x0);
    *(byte *)(iVar3 + 0x44) = *(byte *)(iVar3 + 0x44) & 0xfe;
    piVar5 = (int *)param_1[0x122];
    pcVar4 = *(code **)(*piVar5 + 0x28);
    uVar2 = 0;
  }
  else {
    if ((param_2 < 1) || (param_1[5] != param_2)) goto LAB_118024e0;
    iVar3 = msys::MLyt::getPane((MLyt *)param_1[8],"btn_L","GUIDE_TXT_base",(char *)0x0);
    *(byte *)(iVar3 + 0x44) = *(byte *)(iVar3 + 0x44) & 0xfe | 1;
    piVar5 = (int *)param_1[0x122];
    pcVar4 = *(code **)(*piVar5 + 0x28);
    uVar2 = 1;
  }
  (*pcVar4)(piVar5,uVar2);
LAB_118024e0:
  if (iVar1 - 1U <= (uint)param_1[5]) {
    iVar1 = msys::MLyt::getPane((MLyt *)param_1[8],"btn_R","GUIDE_TXT_base",(char *)0x0);
    *(byte *)(iVar1 + 0x44) = *(byte *)(iVar1 + 0x44) & 0xfe;
                    /* WARNING: Could not recover jumptable at 0x11802528. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*(int *)param_1[0x123] + 0x28))((int *)param_1[0x123],0);
    return;
  }
  if ((param_2 < 0) && (iVar1 - 1U <= (uint)(param_1[5] - param_2))) {
    iVar1 = msys::MLyt::getPane((MLyt *)param_1[8],"btn_R","GUIDE_TXT_base",(char *)0x0);
    *(byte *)(iVar1 + 0x44) = *(byte *)(iVar1 + 0x44) & 0xfe | 1;
                    /* WARNING: Could not recover jumptable at 0x118025b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*(int *)param_1[0x123] + 0x28))((int *)param_1[0x123],1);
    return;
  }
  return;
}


// FUNC 0x118025e4 FUN_118025e4 (Colosseum)
//   size 0x80 | file Colosseum+0x25e4 | callers(0)

void FUN_118025e4(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  char acStack_50 [68];
  
  nn::nstd::TSPrintf(acStack_50,"%s_%02d",(&DAT_11814444)[*(int *)param_1[7] * 2],param_1[5]);
  iVar1 = *param_1;
  piVar3 = (int *)param_1[9];
  uVar2 = LMS_GetTextIndexByLabel(iVar1 + 0xe9058,acStack_50);
  uVar2 = LMS_GetText(iVar1 + 0xe9058,uVar2);
  (**(code **)(*piVar3 + 0x3c))(piVar3,uVar2,0);
  return;
}


// FUNC 0x1180268c FUN_1180268c (Colosseum)
//   size 0x308 | file Colosseum+0x268c | callers(0) | datarefs 1

void FUN_1180268c(int param_1,uint *param_2)

{
  char cVar1;
  short sVar2;
  MListWndPBase *this;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  LytAnim *this_00;
  int iVar7;
  undefined4 uVar8;
  MLyt *this_01;
  
  this = (MListWndPBase *)(param_1 + 0x3df84);
  iVar3 = msys::MListWndPBase::isTpNeutral(this);
  if (iVar3 == 0) {
    return;
  }
  if (*(char *)(param_1 + 0x61013) == '\0') {
    uVar4 = msys::MListWndPBase::getCurNo(this);
    if (((uint)*(byte *)(param_1 + 0x6100c) & 1 << (uVar4 & 0xff)) == 0) goto LAB_118026fc;
LAB_118026f4:
    iVar3 = 1;
  }
  else {
    uVar4 = msys::MListWndPBase::getCurNo(this);
    if (((uint)*(byte *)(param_1 + 0x6100d) & 1 << (uVar4 & 0xff)) != 0) goto LAB_118026f4;
LAB_118026fc:
    iVar3 = 0;
  }
  piVar5 = (int *)msys::MListWndPBase::getCurItem();
  iVar6 = msys::MListWndPBase::getCurItem();
  if ((iVar6 == 0) || (iVar6 = msys::MListWndPBase::getSelectItem(this), iVar6 == 0)) {
    if ((*param_2 & 0x802) != 0) {
      (**(code **)(**(int **)(param_1 + 0x1334c) + 0x10))();
      FUN_118068b4(param_1,0);
    }
  }
  else if ((iVar3 == 0) ||
          (iVar6 = msys::MListWndPBase::getCurItem(), *(char *)(iVar6 + 0xe) == '\0')) {
    FUN_11806814(param_1,0x110018,0,0,0);
  }
  else {
    FUN_11806814(param_1,0x110016,0,0,0);
    FUN_118068b4(param_1,0);
    *(code **)(param_1 + 0x12a04) = FUN_11804c5c;
    *(undefined4 *)(param_1 + 0x12a08) = 0;
  }
  if ((piVar5 == (int *)0x0) || (*(int **)(param_1 + 0x45108) == piVar5)) goto LAB_11802914;
  this_01 = (MLyt *)(param_1 + 0x12bb4);
  if (-1 < *(int *)(param_1 + 0x4510c)) {
    this_00 = (LytAnim *)msys::MLyt::getAnim(this_01,(ushort)*(int *)(param_1 + 0x4510c) & 0xff);
    ad::lyt::LytAnim::stopAndSetFrm(this_00,0.0);
  }
  if ((short)piVar5[1] == -1) {
LAB_1180290c:
    *(undefined4 *)(param_1 + 0x4510c) = 0xffffffff;
  }
  else {
    cVar1 = *(char *)(param_1 + 0x61013);
    iVar6 = 0;
    if (cVar1 != '\0') {
      iVar6 = 10;
    }
    iVar7 = *piVar5;
    if ((short)(&DAT_003f9de0)[iVar6 + iVar7] < 0) goto LAB_1180290c;
    if ((int)*(uint *)(param_1 + 0x4510c) < 0) {
      if (cVar1 == '\0') {
        uVar8 = msys::MLyt::createAnimeAutoSlot
                          (this_01,(&PTR_s_LOOP_TROPHY_ML_01_1181448c)[iVar7],(char *)0x0,
                           (char *)0x0);
      }
      else {
        uVar8 = msys::MLyt::createAnimeAutoSlot
                          (this_01,*(char **)(&DAT_118144a8 + iVar7 * 4),(char *)0x0,(char *)0x0);
      }
      *(undefined4 *)(param_1 + 0x4510c) = uVar8;
    }
    else {
      uVar4 = *(uint *)(param_1 + 0x4510c) & 0xff;
      if (cVar1 == '\0') {
        msys::MLyt::createAnime
                  (this_01,uVar4,(&PTR_s_LOOP_TROPHY_ML_01_1181448c)[iVar7],
                   &msys::MLyt::createAnime(unsigned_char,char_const*,bool,signed)::string_literal,1
                   ,0xffffffff);
      }
      else {
        msys::MLyt::createAnime
                  (this_01,uVar4,*(undefined4 *)(&DAT_118144a8 + iVar7 * 4),
                   &msys::MLyt::createAnime(unsigned_char,char_const*,bool,signed)::string_literal,1
                   ,0xffffffff);
      }
    }
  }
  *(int **)(param_1 + 0x45108) = piVar5;
LAB_11802914:
  if (*(char *)(param_1 + 0x61013) == '\0') {
    iVar6 = msys::MListWndPBase::getCurNo(this);
    sVar2 = (&DAT_003f9de0)[iVar6];
    iVar6 = msys::MListWndPBase::getCurNo(this);
    FUN_118061f4(param_1 + 0x4c194,&DAT_1180c268 + iVar6 * 7,iVar3,((int)sVar2 >> 0x1f) + 1);
    return;
  }
  iVar6 = msys::MListWndPBase::getCurNo(this);
  FUN_11806474(param_1,iVar3,((int)(short)(&DAT_003f9df4)[iVar6] >> 0x1f) + 1);
  return;
}


// FUNC 0x118029c0 FUN_118029c0 (Colosseum)
//   size 0x8c | file Colosseum+0x29c0 | callers(0) | datarefs 4

void FUN_118029c0(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  FUN_11806144();
  iVar1 = Backup::errorCode();
  if (iVar1 == 0) {
    iVar1 = Backup::isBusyWriting((Backup *)(param_1 + 0x10));
    if (iVar1 == 0) {
      Backup::term();
      *(code **)(param_1 + 0x12a04) = FUN_11804d04;
      *(undefined4 *)(param_1 + 0x12a08) = 0;
      FUN_11804d04(param_1,param_2);
      return;
    }
  }
  else {
    if (iVar1 - 0x2001U < 2 || iVar1 == 0x2003) {
      puVar2 = &DAT_1180c1d0;
    }
    else {
      puVar2 = &DAT_1180c1d8;
    }
    uVar3 = puVar2[1];
    *(undefined4 *)(param_1 + 0x12a04) = *puVar2;
    *(undefined4 *)(param_1 + 0x12a08) = uVar3;
  }
  return;
}


// FUNC 0x11802a54 FUN_11802a54 (Colosseum)
//   size 0x40 | file Colosseum+0x2a54 | callers(0) | datarefs 1

void FUN_11802a54(int param_1)

{
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x12f5c),0,1,(char *)0x0,(char *)0x0);
  *(undefined1 **)(param_1 + 0x12a04) = &LAB_11804ef4;
  *(undefined4 *)(param_1 + 0x12a08) = 0;
  return;
}


// FUNC 0x11802a98 col::ColosseumPage::Core::ListWnd_Guide::vfunc_0x10 (Colosseum)
//   size 0x1c | file Colosseum+0x2a98 | callers(0) | datarefs 1

void col::ColosseumPage::Core::ListWnd_Guide::vfunc_0x10(MListWndPBase *param_1)

{
  msys::MListWndPBase::applyAnime(param_1);
  ad::lyt::Layout::Animate((Layout *)(param_1 + 0x6ff4));
  return;
}


// FUNC 0x11802ab4 FUN_11802ab4 (Colosseum)
//   size 0x228 | file Colosseum+0x2ab4 | callers(1) 0x118012ec

void FUN_11802ab4(MListWndPBase *param_1,int param_2)

{
  char cVar1;
  Layout *pLVar2;
  int iVar3;
  char cVar4;
  LytAnim *this;
  LytAnim *this_00;
  undefined4 uVar5;
  int iVar6;
  MListWndPBase *pMVar7;
  MListWndPBase *pMVar8;
  int iVar9;
  int local_1a0 [11];
  undefined4 local_174;
  undefined4 local_170;
  undefined4 local_168;
  LytAnim *local_144;
  LytAnim *local_140;
  undefined1 local_138;
  MListWndPBase *local_64;
  byte local_60;
  
  *(int *)(param_1 + 0x6ff0) = param_2;
  iVar3 = msys::MComSys::_sys;
  iVar9 = *(int *)(param_2 + 8);
  if (*(int *)(param_2 + 8) == 0) {
    *(int *)(param_2 + 8) = msys::MComSys::_sys;
    iVar9 = iVar3;
  }
  pLVar2 = (Layout *)(param_1 + 0x6ff4);
  cVar1 = *(char *)(param_2 + 0x61013);
  ad::lyt::LytResourceMan::buildLayout
            ((LytResourceMan *)(param_2 + 0x12a30),pLVar2,"MINIGAME_GUIDE_L_LIST.bflyt",
             (ControlCreator *)0x0,(TextSearcher *)0x0);
  this = (LytAnim *)(param_1 + 0x7030);
  ad::lyt::LytAnim::init(this,pLVar2,"touch","");
  this_00 = (LytAnim *)(param_1 + 0x704c);
  ad::lyt::LytAnim::init(this_00,pLVar2,"ATTENTION","");
  ad::lyt::LytAnim::playAuto(this_00,1.0);
  ad::ui::UIListWindowPlusLyt::InitParam::InitParam((InitParam *)local_1a0);
  msys::SetMListWndInitParam(local_1a0,1);
  local_1a0[0] = iVar9 + 0x4af6c;
  local_168 = (**(code **)(**(int **)(param_1 + 0x7004) + 0x2c))
                        (*(int **)(param_1 + 0x7004),"FRAME",1);
  local_170 = (**(code **)(**(int **)(param_1 + 0x7004) + 0x2c))
                        (*(int **)(param_1 + 0x7004),"list_cursor",1);
  local_174 = (**(code **)(**(int **)(param_1 + 0x7004) + 0x2c))
                        (*(int **)(param_1 + 0x7004),"list_scroll",1);
  pMVar7 = param_1 + 0x6f80;
  local_60 = 4;
  local_138 = 0;
  local_144 = this;
  local_140 = this_00;
  local_64 = pMVar7;
  msys::MListWndPBase::init
            (param_1,(InitParam *)local_1a0,(LytDrawData *)(iVar9 + 0xd3000),
             (Prim *)(iVar9 + 0xd3100),(MessageDrawer *)(iVar9 + 0x1487c),
             (ApplyingSceneInfo *)(iVar9 + 0x4af54));
  iVar9 = 0;
  *(undefined4 *)(param_1 + 0x13c) = 0x401;
  if (local_60 != 0) {
    do {
      if (cVar1 == '\0') {
        cVar4 = '\0';
      }
      else {
        cVar4 = '\a';
      }
      pMVar7[8] = (MListWndPBase)(cVar4 + (char)iVar9);
      iVar3 = msys::MComSys::_sys;
      iVar6 = *(int *)(*(int *)(param_1 + 0x6ff0) + 8);
      if (iVar6 == 0) {
        *(int *)(*(int *)(param_1 + 0x6ff0) + 8) = msys::MComSys::_sys;
        iVar6 = iVar3;
      }
      uVar5 = LMS_GetTextIndexByLabel(iVar6 + 0xe9058,(&DAT_11814440)[iVar9 * 2]);
      uVar5 = LMS_GetText(iVar6 + 0xe9058,uVar5);
      *(undefined4 *)(pMVar7 + 0x10) = uVar5;
      *(undefined2 *)(pMVar7 + 4) = 0xffff;
      pMVar7[0xe] = (MListWndPBase)0x1;
      *(int *)pMVar7 = iVar9;
      iVar9 = iVar9 + 1;
      pMVar8 = pMVar7 + 0x14;
      pMVar7[0xf] = (MListWndPBase)0x0;
      pMVar7 = pMVar7 + 0x1c;
      *(undefined4 *)pMVar8 = 0;
    } while (iVar9 < (int)(uint)local_60);
  }
  *(undefined4 *)(param_1 + 0x168) = 0x401;
  msys::MListWndPBase::resetCur(param_1);
  return;
}


// FUNC 0x11802d48 col::ColosseumPage::Core::ListWnd_Guide::vfunc_0x4 (Colosseum)
//   size 0x64 | file Colosseum+0x2d48 | callers(0) | datarefs 1

void col::ColosseumPage::Core::ListWnd_Guide::vfunc_0x4(undefined4 *param_1)

{
  int iVar1;
  void *pvVar2;
  
  *param_1 = &vtable;
  param_1[0x1c1d] = 0;
  param_1[0x1c16] = 0;
  param_1[0x1c0f] = 0;
  iVar1 = ad::lyt::Layout::~Layout((Layout *)(param_1 + 0x1bfd));
  *(undefined ***)(iVar1 + -0x6ff4) = &vtable_for_N4msys9MListWndPILi4EEE;
  iVar1 = ad::ui::UIListWindowPlusLyt::~UIListWindowPlusLyt
                    ((UIListWindowPlusLyt *)(iVar1 + -0x6df8));
  pvVar2 = (void *)msys::MListWndPBase::~MListWndPBase((MListWndPBase *)(iVar1 + -0x1fc));
  operator_delete(pvVar2);
  return;
}


// FUNC 0x11802db8 col::ColosseumPage::Core::ListWnd_Guide::vfunc_0x0 (Colosseum)
//   size 0x60 | file Colosseum+0x2db8 | callers(0) | datarefs 1

void col::ColosseumPage::Core::ListWnd_Guide::vfunc_0x0(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &vtable;
  param_1[0x1c1d] = 0;
  param_1[0x1c16] = 0;
  param_1[0x1c0f] = 0;
  iVar1 = ad::lyt::Layout::~Layout((Layout *)(param_1 + 0x1bfd));
  *(undefined ***)(iVar1 + -0x6ff4) = &vtable_for_N4msys9MListWndPILi4EEE;
  iVar1 = ad::ui::UIListWindowPlusLyt::~UIListWindowPlusLyt
                    ((UIListWindowPlusLyt *)(iVar1 + -0x6df8));
  msys::MListWndPBase::~MListWndPBase((MListWndPBase *)(iVar1 + -0x1fc));
  return;
}


// FUNC 0x1180406c FUN_1180406c (Colosseum)
//   size 0x188 | file Colosseum+0x406c | callers(0) | datarefs 2

void FUN_1180406c(int param_1)

{
  short sVar1;
  int iVar2;
  MListWndPBase *this;
  uint uVar3;
  undefined4 uVar4;
  
  iVar2 = FUN_11805d28();
  if (iVar2 != 0) {
    *(code **)(param_1 + 0x12a04) = FUN_1180449c;
    *(undefined4 *)(param_1 + 0x12a08) = 0;
    return;
  }
  *(undefined1 *)(param_1 + 0x1331c) = *(undefined1 *)(param_1 + 0x61013);
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x12f5c),3,1,(char *)0x0,(char *)0x0);
  this = (MListWndPBase *)(param_1 + 0x3df84);
  FUN_11806ab4(this,(int)*(char *)(param_1 + 0x61013));
  *(undefined1 *)(param_1 + 0x60b00) = 0xff;
  *(undefined4 *)(param_1 + 0x60afc) = 0;
  *(undefined1 *)(param_1 + 0x60b01) = 1;
  if (*(char *)(param_1 + 0x61013) == '\0') {
    uVar3 = msys::MListWndPBase::getCurNo(this);
    uVar3 = (uint)(((uint)*(byte *)(param_1 + 0x6100c) & 1 << (uVar3 & 0xff)) != 0);
    iVar2 = msys::MListWndPBase::getCurNo(this);
    sVar1 = (&DAT_003f9de0)[iVar2];
    iVar2 = msys::MListWndPBase::getCurNo(this);
    FUN_118061f4(param_1 + 0x4c194,&DAT_1180c268 + iVar2 * 7,uVar3,((int)sVar1 >> 0x1f) + 1);
    goto LAB_118041d0;
  }
  iVar2 = msys::MListWndPBase::getCurNo(this);
  sVar1 = (&DAT_003f9df4)[iVar2];
  if (*(char *)(param_1 + 0x61013) == '\0') {
    uVar3 = msys::MListWndPBase::getCurNo(this);
    if (((uint)*(byte *)(param_1 + 0x6100c) & 1 << (uVar3 & 0xff)) == 0) goto LAB_11804160;
LAB_11804158:
    uVar4 = 1;
  }
  else {
    uVar3 = msys::MListWndPBase::getCurNo(this);
    if (((uint)*(byte *)(param_1 + 0x6100d) & 1 << (uVar3 & 0xff)) != 0) goto LAB_11804158;
LAB_11804160:
    uVar4 = 0;
  }
  FUN_11806474(param_1,uVar4,((int)sVar1 >> 0x1f) + 1);
LAB_118041d0:
  *(undefined1 *)(param_1 + 0x3e0c5) = 1;
  *(code **)(param_1 + 0x12a04) = FUN_118055d0;
  *(undefined4 *)(param_1 + 0x12a08) = 0;
  *(undefined4 *)(param_1 + 0x45108) = 0;
  *(undefined4 *)(param_1 + 0x4510c) = 0xffffffff;
  return;
}


// FUNC 0x11804208 FUN_11804208 (Colosseum)
//   size 0xa0 | file Colosseum+0x4208 | callers(0) | datarefs 2

void FUN_11804208(int param_1)

{
  int iVar1;
  code *pcVar2;
  
  iVar1 = msys::MLyt::isEnableAnime((MLyt *)(param_1 + 0x12f5c));
  if ((iVar1 == 0) && (*(int *)(param_1 + 0x3dc94) == 0)) {
    iVar1 = GameWork::getCoin((GameWork *)&gGameWork);
    ad::lyt::LytNumReel3::setValueInstant((LytNumReel3 *)(param_1 + 0x356f8),iVar1);
    if (*(char *)(param_1 + 0x6100f) == '\0') {
      Message::close((Message *)(param_1 + 0x37198));
      msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x12f5c),8,0,(char *)0x0,(char *)0x0);
      pcVar2 = FUN_11804d04;
    }
    else {
      pcVar2 = FUN_1180449c;
    }
    *(code **)(param_1 + 0x12a04) = pcVar2;
    *(undefined4 *)(param_1 + 0x12a08) = 0;
  }
  return;
}


// FUNC 0x118042b8 FUN_118042b8 (Colosseum)
//   size 0x70 | file Colosseum+0x42b8 | callers(0) | datarefs 5

void FUN_118042b8(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = Backup::GetSaveData1(-1);
  Mem::Copy((void *)(iVar1 + 2000),&DAT_003f9dc0,0x40);
  iVar1 = msys::MComSys::_sys;
  iVar2 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar2 = iVar1;
  }
  Backup::init((Backup *)(param_1 + 0x10),(CtrFS *)(*(int *)(iVar2 + 4) + 0x518));
  Backup::writeSaveData0((short)param_1 + 0x10);
  *(code **)(param_1 + 0x12a04) = FUN_118029c0;
  *(undefined4 *)(param_1 + 0x12a08) = 0;
  return;
}


// FUNC 0x11804334 FUN_11804334 (Colosseum)
//   size 0xa8 | file Colosseum+0x4334 | callers(0) | datarefs 1

void FUN_11804334(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 local_1c;
  
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x12f5c),0,0,(char *)0x0,(char *)0x0);
  iVar1 = msys::MComSys::_sys;
  iVar2 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar2 = iVar1;
  }
  local_1c = 0xff000000;
  MoveC::moveFrm((MoveC *)(iVar2 + 0x4acd4),(Color8 *)&local_1c,16.0);
  MoveC::moveFrm((MoveC *)(iVar2 + 0x4ad14),(Color8 *)&local_1c,16.0);
  *(undefined1 **)(param_1 + 0x12a04) = &LAB_11806c98;
  *(undefined4 *)(param_1 + 0x12a08) = 0;
  return;
}


// FUNC 0x1180440c FUN_1180440c (Colosseum)
//   size 0x84 | file Colosseum+0x440c | callers(0) | datarefs 1

void FUN_1180440c(int param_1)

{
  LytAnim *this;
  
  if (-1 < *(int *)(param_1 + 0x4510c)) {
    this = (LytAnim *)
           msys::MLyt::getAnim((MLyt *)(param_1 + 0x12bb4),
                               (ushort)*(int *)(param_1 + 0x4510c) & 0xff);
    ad::lyt::LytAnim::stopAndSetFrm(this,0.0);
  }
  msys::MLyt::setAnimeInfo((MLyt *)(param_1 + 0x12f5c),3,2);
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x12f5c),3,0,(char *)0x0,(char *)0x0);
  *(undefined1 *)(param_1 + 0x3e0c5) = 0;
  *(code **)(param_1 + 0x12a04) = FUN_11806f04;
  *(undefined4 *)(param_1 + 0x12a08) = 0;
  return;
}


// FUNC 0x1180449c FUN_1180449c (Colosseum)
//   size 0x34c | file Colosseum+0x449c | callers(0) | datarefs 6

void FUN_1180449c(int param_1)

{
  short sVar1;
  MLyt *this;
  int iVar2;
  int iVar3;
  uint uVar4;
  short *psVar5;
  uint uVar6;
  uint uVar7;
  undefined2 *puVar8;
  short *psVar9;
  bool bVar10;
  LytAnim aLStack_25c [4];
  undefined4 local_258;
  undefined4 local_254;
  undefined4 uStack_250;
  undefined2 local_24c;
  undefined2 local_24a;
  short local_240 [64];
  undefined2 local_1c0 [64];
  undefined2 local_140;
  undefined2 local_c0;
  uint local_40;
  uint local_3c;
  undefined4 local_38;
  undefined4 local_34;
  
  this = (MLyt *)(param_1 + 0x12f5c);
  iVar2 = msys::MLyt::isEnableAnime(this);
  if (iVar2 == 0) {
    uVar7 = 0;
    do {
      if (((uint)*(byte *)(param_1 + 0x6100f) & 1 << uVar7) != 0) {
        *(byte *)(param_1 + 0x6100f) = *(byte *)(param_1 + 0x6100f) & ~(byte)(1 << uVar7);
        if (*(char *)(param_1 + 0x61013) != '\0') goto LAB_1180451c;
        if (uVar7 != 6) goto LAB_118045dc;
        PutRegFlag(0xc512,1.0,(GlobalEvent *)0x0,(LocalEvent *)0x0);
        break;
      }
      uVar7 = uVar7 + 1 & 0xff;
      if (*(char *)(param_1 + 0x61013) == '\0') {
        uVar4 = 7;
      }
      else {
        uVar4 = 4;
      }
    } while (uVar7 < uVar4);
    if (*(char *)(param_1 + 0x61013) == '\0') {
LAB_118045dc:
      puVar8 = (undefined2 *)(&DAT_1180c274 + uVar7 * 0x1c);
    }
    else {
LAB_1180451c:
      puVar8 = &DAT_1180c330 + uVar7 * 10;
    }
    local_258 = 0;
    local_254 = 0x3f800000;
    uStack_250 = 0;
    local_24c = 1;
    local_24a = 0;
    ad::lyt::LytAnim::init(aLStack_25c,*(Layout **)(param_1 + 0x130ac),"CONGRATULATIONS_OFFON","");
    ad::lyt::LytAnim::stopAndSetFrm(aLStack_25c,0.0);
    ad::lyt::LytAnim::term(aLStack_25c,true);
    if (*(char *)(param_1 + 0x61013) == '\0') {
      msys::MLyt::createAnimeAutoSlot((MLyt *)(param_1 + 0x12bb4),"5_to_6",(char *)0x0,(char *)0x0);
      msys::MLyt::playAnimeFromNo(this,6,0,(char *)0x0,(char *)0x0);
    }
    else {
      msys::MLyt::createAnimeAutoSlot
                ((MLyt *)(param_1 + 0x12bb4),"huge_5_to_6",(char *)0x0,(char *)0x0);
      msys::MLyt::playAnimeFromNo(this,7,0,(char *)0x0,(char *)0x0);
    }
    msys::MLyt::playAnimeFromNo(this,8,1,(char *)0x0,(char *)0x0);
    FUN_11805e48(param_1 + 0x4c194,puVar8);
    local_240[0] = 0;
    local_40 = 0;
    local_1c0[0] = 0;
    local_3c = 0;
    local_140 = 0;
    local_38 = 0;
    local_c0 = 0;
    local_34 = 0;
    sVar1 = puVar8[2];
    iVar2 = 10;
    uVar7 = 1;
    do {
      iVar3 = __aeabi_uidivmod((int)sVar1,iVar2);
      if (iVar3 == 0) break;
      uVar7 = uVar7 + 1;
      iVar2 = iVar2 * 10;
    } while (uVar7 < 0x40);
    FUN_11801280(local_240,0x40,0x3f,
                 &MessageSimple::InsParam::setNum(unsigned_char,int,bool)::string_literal,(int)sVar1
                );
    if (uVar7 != 0) {
      uVar4 = uVar7 & 1;
      if (uVar4 != 0) {
        local_240[0] = local_240[0] + -0x120;
      }
      uVar6 = (uint)(uVar4 != 0);
      for (; uVar4 < uVar7; uVar4 = uVar4 + 2) {
        psVar5 = local_240 + uVar6;
        psVar9 = local_240 + uVar6 + 1;
        *psVar5 = *psVar5 + -0x120;
        uVar6 = uVar6 + 2;
        *psVar9 = *psVar9 + -0x120;
      }
    }
    local_40 = uVar7;
    psVar5 = (short *)ad::db::GetItemMsg(puVar8[1],0);
    uVar7 = 0;
    do {
      sVar1 = psVar5[uVar7];
      if (sVar1 == 0) break;
      if (sVar1 == 0xe) {
        uVar7 = uVar7 + ((ushort)(psVar5 + uVar7)[3] >> 1) + 3;
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < 0x40);
    sVar1 = *psVar5;
    bVar10 = sVar1 == 0xe;
    if (bVar10) {
      sVar1 = psVar5[1];
    }
    if (bVar10 && sVar1 == 9) {
      uVar7 = uVar7 - 5;
      psVar5 = psVar5 + 5;
    }
    Mem::Copy(local_1c0,psVar5,uVar7 << 1);
    local_3c = uVar7;
    FUN_11805cbc(param_1 + 0x3704c,"MES_EMesColosseum_class_1_prize",local_240);
    FUN_11806814(param_1,0x110025,0,0,0);
    *(code **)(param_1 + 0x12a04) = FUN_11804208;
    *(undefined4 *)(param_1 + 0x12a08) = 0;
  }
  return;
}


// FUNC 0x1180485c FUN_1180485c (Colosseum)
//   size 0x1d4 | file Colosseum+0x485c | callers(0) | datarefs 1

void FUN_1180485c(int param_1)

{
  short sVar1;
  int iVar2;
  int *piVar3;
  short *psVar4;
  MSndSe *this;
  int *piVar5;
  MListWndPBase *this_00;
  
  this_00 = (MListWndPBase *)(param_1 + 0x3df84);
  if (*(char *)(param_1 + 0x61013) == '\0') {
    iVar2 = msys::MListWndPBase::getCurNo(this_00);
    sVar1 = (&DAT_003f9de0)[iVar2];
  }
  else {
    iVar2 = msys::MListWndPBase::getCurNo(this_00);
    sVar1 = (&DAT_003f9df4)[iVar2];
  }
  msys::MCursorBase::setVisible((MCursorBase *)(param_1 + 0x13304),false);
  ad::lyt::LytAnim::stopAndSetFrm((LytAnim *)(param_1 + 0x60f9c),0.0);
  *(undefined4 *)(param_1 + 0x60ff8) = 0;
  if (-1 < sVar1) {
    *(code **)(param_1 + 0x12a04) = FUN_11804fdc;
    *(undefined4 *)(param_1 + 0x12a08) = 0;
    return;
  }
  if (*(char *)(param_1 + 0x61013) == '\0') {
    iVar2 = msys::MListWndPBase::getCurNo(this_00);
    psVar4 = (short *)(&DAT_1180c274 + iVar2 * 0x1c);
  }
  else {
    iVar2 = msys::MListWndPBase::getCurNo(this_00);
    psVar4 = &DAT_1180c330 + iVar2 * 10;
  }
  GameWork::addCoin((GameWork *)&gGameWork,-(int)*psVar4);
  iVar2 = GameWork::getCoin((GameWork *)&gGameWork);
  ad::lyt::LytNumReel3::setValue((LytNumReel3 *)(param_1 + 0x356f8),iVar2);
  iVar2 = *(int *)(param_1 + 8);
  piVar3 = *(int **)(iVar2 + 0x49374);
  this = (MSndSe *)(piVar3 + -0x15);
  if ((MSndSe *)(iVar2 + 0x4931c) == this) {
    this = (MSndSe *)0x0;
  }
  else {
    piVar5 = (int *)piVar3[1];
    if (piVar5 != piVar3) {
      *(int **)(*piVar3 + 4) = piVar5;
      *piVar5 = *piVar3;
      *piVar3 = (int)piVar3;
      piVar3[1] = (int)piVar3;
    }
    piVar5 = (int *)piVar3[1];
    *(int **)(*piVar3 + 4) = piVar5;
    *piVar5 = *piVar3;
    if (piVar3 != (int *)0x0) {
      *piVar3 = iVar2 + 0x49368;
      piVar5 = *(int **)(iVar2 + 0x4936c);
      piVar3[1] = (int)piVar5;
      *piVar5 = (int)piVar3;
      *(int **)(iVar2 + 0x4936c) = piVar3;
    }
    msys::MSndSe::play(this,0x11001e,(MChrBase *)0x0,(VEC2 *)0x0,false);
  }
  *(MSndSe **)(param_1 + 0x60ff8) = this;
  Frm::play((Frm *)(param_1 + 0x60ffc),30.0);
  *(code **)(param_1 + 0x12a04) = FUN_11804f88;
  *(undefined4 *)(param_1 + 0x12a08) = 0;
  return;
}


// FUNC 0x11804a58 FUN_11804a58 (Colosseum)
//   size 0x74 | file Colosseum+0x4a58 | callers(0) | datarefs 1

void FUN_11804a58(int param_1,uint *param_2)

{
  if ((*param_2 & 0x802) == 0) {
    if ((*param_2 & 0x401) != 0) {
      (**(code **)(**(int **)(param_1 + 0x13348) + 0x10))();
      FUN_118068b4(param_1,0);
    }
  }
  else {
    (**(code **)(**(int **)(param_1 + 0x1334c) + 0x10))();
    FUN_118068b4(param_1,0);
  }
  FUN_1180657c(param_1 + 0x13304);
  return;
}


// FUNC 0x11804ad4 FUN_11804ad4 (Colosseum)
//   size 0x6c | file Colosseum+0x4ad4 | callers(0) | datarefs 2

void FUN_11804ad4(int param_1)

{
  int *piVar1;
  int iVar2;
  
  FUN_11805cbc(param_1 + 0x3704c,"menu_save_err_01",0);
  iVar2 = 0;
  do {
    piVar1 = *(int **)(param_1 + iVar2 * 4 + 0x13340);
    (**(code **)(*piVar1 + 0x28))(piVar1,0);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 7);
  FUN_118068b4(param_1,0);
  *(code **)(param_1 + 0x12a04) = FUN_11807248;
  *(undefined4 *)(param_1 + 0x12a08) = 0;
  return;
}


// FUNC 0x11804b58 FUN_11804b58 (Colosseum)
//   size 0xdc | file Colosseum+0x4b58 | callers(0) | datarefs 1

void FUN_11804b58(int param_1)

{
  BootInfo *this;
  
  if (*(char *)(param_1 + 0x61013) == '\0') {
    msys::MLyt::createAnimeAutoSlot((MLyt *)(param_1 + 0x12bb4),"5_to_6",(char *)0x0,(char *)0x0);
    msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x12f5c),6,0,(char *)0x0,(char *)0x0);
  }
  else {
    msys::MLyt::createAnimeAutoSlot
              ((MLyt *)(param_1 + 0x12bb4),"huge_5_to_6",(char *)0x0,(char *)0x0);
    msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x12f5c),7,0,(char *)0x0,(char *)0x0);
  }
  if (*(char *)(param_1 + 0x61010) == '\0') {
    this = (BootInfo *)col::GetBootInfo();
    col::BootInfo::restoreBgm(this);
  }
  else {
    SndSys::start((SndSys *)&gSndSys,0x100035b,(SoundHandle *)&gSndSys);
  }
  Frm::play((Frm *)(param_1 + 0x60ffc),60.0);
  *(code **)(param_1 + 0x12a04) = FUN_11807390;
  *(undefined4 *)(param_1 + 0x12a08) = 0;
  return;
}


// FUNC 0x11804c5c FUN_11804c5c (Colosseum)
//   size 0x9c | file Colosseum+0x4c5c | callers(0) | datarefs 1

void FUN_11804c5c(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined2 *puVar3;
  
  if (*(char *)(param_1 + 0x61013) == '\0') {
    uVar2 = 4;
  }
  else {
    uVar2 = 5;
  }
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x12f5c),uVar2,1,(char *)0x0,(char *)0x0);
  if (*(char *)(param_1 + 0x61013) == '\0') {
    iVar1 = msys::MListWndPBase::getCurNo((MListWndPBase *)(param_1 + 0x3df84));
    puVar3 = (undefined2 *)(&DAT_1180c274 + iVar1 * 0x1c);
  }
  else {
    iVar1 = msys::MListWndPBase::getCurNo((MListWndPBase *)(param_1 + 0x3df84));
    puVar3 = &DAT_1180c330 + iVar1 * 10;
  }
  FUN_11805e48(param_1 + 0x4c194,puVar3);
  *(code **)(param_1 + 0x12a04) = FUN_118076e0;
  *(undefined4 *)(param_1 + 0x12a08) = 0;
  return;
}


// FUNC 0x11804d04 FUN_11804d04 (Colosseum)
//   size 0x1cc | file Colosseum+0x4d04 | callers(1) 0x118029c0 | datarefs 5

void FUN_11804d04(int param_1)

{
  short sVar1;
  int iVar2;
  code *pcVar3;
  BootInfo *this;
  MListWndPBase *this_00;
  uint uVar4;
  char *pcVar5;
  undefined4 uVar6;
  
  iVar2 = FUN_11805d28();
  if (iVar2 != 0) {
    FUN_118068b4(param_1,0);
    pcVar3 = FUN_1180449c;
    goto LAB_11804ec8;
  }
  msys::MLyt::createAnimeAutoSlot((MLyt *)(param_1 + 0x12bb4),"6_to_2",(char *)0x0,(char *)0x0);
  if (*(char *)(param_1 + 0x61013) == '\0') {
    pcVar5 = "6_to_2";
  }
  else {
    pcVar5 = "huge_6_to_2";
  }
  msys::MLyt::createAnimeAutoSlot((MLyt *)(param_1 + 0x12f5c),pcVar5,(char *)0x0,(char *)0x0);
  iVar2 = GameMain::GameModeOld();
  if (((iVar2 == 10) || (iVar2 = GameMain::GameModeOld(), iVar2 == 0)) &&
     (*(char *)(param_1 + 0x61010) != '\0')) {
    SndSys::stopAllBgm((SndSys *)&gSndSys,0x10);
    this = (BootInfo *)col::GetBootInfo();
    col::BootInfo::restoreBgm(this);
  }
  this_00 = (MListWndPBase *)(param_1 + 0x3df84);
  FUN_11806ab4(this_00,(int)*(char *)(param_1 + 0x61013));
  *(undefined1 *)(param_1 + 0x3e0c5) = 1;
  if (*(char *)(param_1 + 0x61013) == '\0') {
    uVar4 = msys::MListWndPBase::getCurNo(this_00);
    if (((uint)*(byte *)(param_1 + 0x6100c) & 1 << (uVar4 & 0xff)) == 0) goto LAB_11804e30;
LAB_11804e28:
    uVar6 = 1;
  }
  else {
    uVar4 = msys::MListWndPBase::getCurNo(this_00);
    if (((uint)*(byte *)(param_1 + 0x6100d) & 1 << (uVar4 & 0xff)) != 0) goto LAB_11804e28;
LAB_11804e30:
    uVar6 = 0;
  }
  if (*(char *)(param_1 + 0x61013) == '\0') {
    iVar2 = msys::MListWndPBase::getCurNo(this_00);
    sVar1 = (&DAT_003f9de0)[iVar2];
    iVar2 = msys::MListWndPBase::getCurNo(this_00);
    FUN_118061f4(param_1 + 0x4c194,&DAT_1180c268 + iVar2 * 7,uVar6,((int)sVar1 >> 0x1f) + 1);
  }
  else {
    iVar2 = msys::MListWndPBase::getCurNo(this_00);
    FUN_11806474(param_1,uVar6,((int)(short)(&DAT_003f9df4)[iVar2] >> 0x1f) + 1);
  }
  FUN_118068b4(param_1,0);
  pcVar3 = FUN_118055d0;
LAB_11804ec8:
  *(code **)(param_1 + 0x12a04) = pcVar3;
  *(undefined4 *)(param_1 + 0x12a08) = 0;
  return;
}


// FUNC 0x11804f10 FUN_11804f10 (Colosseum)
//   size 0x70 | file Colosseum+0x4f10 | callers(0) | datarefs 2

void FUN_11804f10(int param_1)

{
  int iVar1;
  BootInfo *this;
  
  iVar1 = GameMain::GameModeOld();
  if (((iVar1 == 10) || (iVar1 = GameMain::GameModeOld(), iVar1 == 0)) &&
     (*(char *)(param_1 + 0x61010) == '\0')) {
    this = (BootInfo *)col::GetBootInfo();
    iVar1 = col::BootInfo::playBgm(this);
    if (iVar1 == 0) {
      return;
    }
  }
  *(undefined1 *)(*(int *)(param_1 + 4) + 0x14) = 1;
  *(undefined **)(param_1 + 0x129fc) = &DAT_11809070;
  *(undefined4 *)(param_1 + 0x12a00) = 0;
  return;
}


// FUNC 0x11804f88 FUN_11804f88 (Colosseum)
//   size 0x4c | file Colosseum+0x4f88 | callers(0) | datarefs 2

void FUN_11804f88(int param_1)

{
  if (*(int *)(param_1 + 0x3577c) == *(int *)(param_1 + 0x35774)) {
    if (*(SndSeCtrl **)(param_1 + 0x60ff8) != (SndSeCtrl *)0x0) {
      SndSeCtrl::stop(*(SndSeCtrl **)(param_1 + 0x60ff8),0);
    }
    *(code **)(param_1 + 0x12a04) = FUN_11804fdc;
    *(undefined4 *)(param_1 + 0x12a08) = 0;
  }
  return;
}


// FUNC 0x11804fdc FUN_11804fdc (Colosseum)
//   size 0x304 | file Colosseum+0x4fdc | callers(0) | datarefs 4

void FUN_11804fdc(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  wchar_t *pwVar4;
  MMsg *this;
  int iVar5;
  int iVar6;
  uint in_fpscr;
  float fVar7;
  LytAnim aLStack_64 [4];
  undefined4 local_60;
  undefined4 uStack_5c;
  undefined4 local_58;
  undefined2 local_54;
  undefined2 local_52;
  LytAnim aLStack_48 [4];
  undefined4 local_44;
  undefined4 uStack_40;
  undefined4 local_3c;
  undefined2 local_38;
  undefined2 local_36;
  
  iVar2 = msys::MComSys::_sys;
  fVar7 = 1.0;
  if ((*(byte *)(param_1 + 0x6100a) & 1) != 0) {
    iVar5 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar5 = iVar2;
    }
    iVar2 = ad::fw::TaskBase::isFps30(*(TaskBase **)(iVar5 + 4));
    if (iVar2 != 0) {
      fVar7 = 2.0;
    }
    iVar2 = Frm::update(fVar7);
    if (iVar2 != 0) {
      return;
    }
  }
  cVar1 = msys::MListWndPBase::getCurNo((MListWndPBase *)(param_1 + 0x3df84));
  iVar2 = (int)cVar1;
  if (*(char *)(param_1 + 0x61013) == '\0') {
    local_44 = 0;
    uStack_40 = 0x3f800000;
    local_3c = 0;
    local_38 = 1;
    local_36 = 0;
    ad::lyt::LytAnim::init(aLStack_48,*(Layout **)(param_1 + 0x130ac),"SET_ENEMY_IMG","");
    iVar5 = iVar2;
    if (5 < iVar2) {
      iVar5 = 0;
    }
    fVar7 = (float)VectorSignedToFloat(iVar5,(byte)(in_fpscr >> 0x16) & 3);
    ad::lyt::LytAnim::stopAndSetFrm(aLStack_48,fVar7);
    ad::lyt::LytAnim::term(aLStack_48,true);
    iVar6 = msys::MComSys::_sys;
    local_3c = 0;
    this = (MMsg *)(param_1 + 0x27d20);
    iVar5 = *(int *)(param_1 + 8);
    if (5 < iVar2) {
      if (iVar5 == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar5 = iVar6;
      }
      uVar3 = LMS_GetTextIndexByLabel(iVar5 + 0xe9058,"MES_EMesColosseum_class_7_enemy_1");
      pwVar4 = (wchar_t *)LMS_GetText(iVar5 + 0xe9058,uVar3);
      msys::MMsg::playStr(this,pwVar4,(InsParam *)0x0,false);
      goto LAB_1180521c;
    }
    iVar6 = iVar5;
    if (iVar5 == 0) {
      iVar6 = msys::MComSys::_sys;
    }
    if (iVar5 == 0) {
      *(int *)(param_1 + 8) = iVar6;
    }
    uVar3 = LMS_GetTextIndexByLabel(iVar6 + 0xe9058,*(undefined4 *)(&DAT_1180c280 + iVar2 * 0x1c));
    pwVar4 = (wchar_t *)LMS_GetText(iVar6 + 0xe9058,uVar3);
  }
  else {
    local_60 = 0;
    uStack_5c = 0x3f800000;
    local_58 = 0;
    local_54 = 1;
    local_52 = 0;
    ad::lyt::LytAnim::init(aLStack_64,*(Layout **)(param_1 + 0x12d04),"SET_ENEMY_IMG","");
    fVar7 = (float)VectorSignedToFloat(iVar2,(byte)(in_fpscr >> 0x16) & 3);
    ad::lyt::LytAnim::stopAndSetFrm(aLStack_64,fVar7);
    ad::lyt::LytAnim::term(aLStack_64,true);
    iVar6 = msys::MComSys::_sys;
    local_58 = 0;
    iVar5 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar5 = iVar6;
    }
    uVar3 = LMS_GetTextIndexByLabel(iVar5 + 0xe9058,*(undefined4 *)(&DAT_1180c33c + iVar2 * 10));
    pwVar4 = (wchar_t *)LMS_GetText(iVar5 + 0xe9058,uVar3);
    this = (MMsg *)(param_1 + 0x2e964);
  }
  msys::MMsg::playStr(this,pwVar4,(InsParam *)0x0,false);
LAB_1180521c:
  if (*(char *)(param_1 + 0x61013) == '\0') {
    *(code **)(param_1 + 0x12a04) = FUN_11807118;
    *(undefined4 *)(param_1 + 0x12a08) = 0;
    msys::MLyt::createAnimeAutoSlot((MLyt *)(param_1 + 0x12bb4),"3_to_4",(char *)0x0,(char *)0x0);
    msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x12f5c),6,1,(char *)0x0,(char *)0x0);
    Frm::play((Frm *)(param_1 + 0x60ffc),60.0);
    return;
  }
  *(code **)(param_1 + 0x12a04) = FUN_11807d88;
  *(undefined4 *)(param_1 + 0x12a08) = 0;
  msys::MLyt::createAnimeAutoSlot((MLyt *)(param_1 + 0x12bb4),"huge_3_to_4",(char *)0x0,(char *)0x0)
  ;
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x12f5c),7,1,(char *)0x0,(char *)0x0);
  Frm::play((Frm *)(param_1 + 0x60ffc),60.0);
  return;
}


// FUNC 0x1180532c FUN_1180532c (Colosseum)
//   size 0x6c | file Colosseum+0x532c | callers(0) | datarefs 1

void FUN_1180532c(int param_1)

{
  uint uVar1;
  
  msys::MCursorBase::setVisible((MCursorBase *)(param_1 + 0x13304),false);
  if (*(char *)(param_1 + 0x61013) == '\0') {
    uVar1 = 4;
  }
  else {
    uVar1 = 5;
  }
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x12f5c),uVar1,0,(char *)0x0,(char *)0x0);
  *(undefined1 *)(param_1 + 0x3e0c5) = 1;
  *(code **)(param_1 + 0x12a04) = FUN_118055d0;
  *(undefined4 *)(param_1 + 0x12a08) = 0;
  return;
}


// FUNC 0x118053a8 FUN_118053a8 (Colosseum)
//   size 0xdc | file Colosseum+0x53a8 | callers(0) | datarefs 2

void FUN_118053a8(int param_1,uint *param_2)

{
  int iVar1;
  
  iVar1 = msys::MListWndPBase::isTpNeutral((MListWndPBase *)(param_1 + 0x45110));
  if (iVar1 != 0) {
    iVar1 = msys::MListWndPBase::getCurItem();
    if ((iVar1 == 0) ||
       (iVar1 = msys::MListWndPBase::getSelectItem((MListWndPBase *)(param_1 + 0x45110)), iVar1 == 0
       )) {
      if ((*param_2 & 0x802) != 0) {
        (**(code **)(**(int **)(param_1 + 0x1334c) + 0x10))();
        FUN_118068b4(param_1,0);
        return;
      }
    }
    else {
      iVar1 = msys::MListWndPBase::getCurItem();
      if (*(char *)(iVar1 + 0xe) == '\0') {
        FUN_11806814(param_1,0x110018,0,0,0);
        return;
      }
      FUN_11806814(param_1,0x110016,0,0,0);
      FUN_118068b4(param_1,0);
      *(code **)(param_1 + 0x12a04) = FUN_11806e7c;
      *(undefined4 *)(param_1 + 0x12a08) = 0;
    }
  }
  return;
}


// FUNC 0x11805498 FUN_11805498 (Colosseum)
//   size 0x110 | file Colosseum+0x5498 | callers(0) | datarefs 1

void FUN_11805498(int param_1,uint *param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  
  if ((*param_2 & 0x802) == 0) {
    iVar3 = msys::MLyt::getParts((MLyt *)(param_1 + 0x12f5c),"btn_L","GUIDE_TXT_base",(char *)0x0);
    bVar1 = *(byte *)(iVar3 + 0x44);
    bVar4 = (bVar1 & 1) == 0;
    if (!bVar4) {
      bVar1 = (byte)*param_2;
    }
    if (bVar4 || (bVar1 & 0x20) == 0) {
      iVar3 = msys::MLyt::getParts((MLyt *)(param_1 + 0x12f5c),"btn_R","GUIDE_TXT_base",(char *)0x0)
      ;
      bVar1 = *(byte *)(iVar3 + 0x44);
      bVar4 = (bVar1 & 1) == 0;
      if (!bVar4) {
        bVar1 = (byte)*param_2;
      }
      if (bVar4 || (bVar1 & 0x10) == 0) {
        return;
      }
      (**(code **)(**(int **)(param_1 + 0x13358) + 0x10))();
      (**(code **)(**(int **)(param_1 + 0x13358) + 0xc))();
      iVar3 = *(int *)(param_1 + 8);
      iVar2 = msys::MComSys::_sys;
    }
    else {
      (**(code **)(**(int **)(param_1 + 0x13354) + 0x10))();
      (**(code **)(**(int **)(param_1 + 0x13354) + 0xc))();
      iVar3 = *(int *)(param_1 + 8);
      iVar2 = msys::MComSys::_sys;
    }
  }
  else {
    (**(code **)(**(int **)(param_1 + 0x1334c) + 0x10))();
    iVar3 = *(int *)(param_1 + 8);
    iVar2 = msys::MComSys::_sys;
  }
  msys::MComSys::_sys = iVar2;
  if (iVar3 == 0) {
    *(int *)(param_1 + 8) = iVar2;
    iVar3 = iVar2;
  }
  *(undefined1 *)(iVar3 + 0xe6508) = 0;
  return;
}


// FUNC 0x118055d0 FUN_118055d0 (Colosseum)
//   size 0xb0 | file Colosseum+0x55d0 | callers(0) | datarefs 5

void FUN_118055d0(int param_1)

{
  int iVar1;
  BootInfo *this;
  int *piVar2;
  
  iVar1 = msys::MLyt::isEnableAnime((MLyt *)(param_1 + 0x12f5c));
  if (iVar1 == 0) {
    this = (BootInfo *)col::GetBootInfo();
    iVar1 = col::BootInfo::playBgm(this);
    if (iVar1 != 0) {
      iVar1 = 0;
      do {
        piVar2 = *(int **)(param_1 + iVar1 * 4 + 0x13340);
        (**(code **)(*piVar2 + 0x28))(piVar2,0);
        iVar1 = iVar1 + 1;
      } while (iVar1 < 7);
      (**(code **)(**(int **)(param_1 + 0x1334c) + 0x28))(*(int **)(param_1 + 0x1334c),1);
      *(undefined4 *)(param_1 + 0x45108) = 0;
      *(undefined4 *)(param_1 + 0x4510c) = 0xffffffff;
      FUN_118068b4(param_1,1);
      *(code **)(param_1 + 0x12a04) = FUN_1180268c;
      *(undefined4 *)(param_1 + 0x12a08) = 0;
      *(code **)(param_1 + 0x12a0c) = FUN_1180440c;
      *(undefined4 *)(param_1 + 0x12a10) = 0;
    }
  }
  return;
}


// FUNC 0x11805688 FUN_11805688 (Colosseum)
//   size 0x98 | file Colosseum+0x5688 | callers(5) 0x1180b5f0 0x1180b604 0x1180b618 0x1180b62c 0x1180b640

void FUN_11805688(undefined4 param_1,uint param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  
  iVar1 = msys::MComSys::_sys;
  iVar3 = msys::MComSys::_sys + 0x49368;
  piVar2 = *(int **)(msys::MComSys::_sys + 0x49374);
  if ((MSndSe *)(msys::MComSys::_sys + 0x4931c) != (MSndSe *)(piVar2 + -0x15)) {
    piVar4 = (int *)piVar2[1];
    if (piVar4 != piVar2) {
      *(int **)(*piVar2 + 4) = piVar4;
      *piVar4 = *piVar2;
      *piVar2 = (int)piVar2;
      piVar2[1] = (int)piVar2;
    }
    piVar4 = (int *)piVar2[1];
    *(int **)(*piVar2 + 4) = piVar4;
    *piVar4 = *piVar2;
    if (piVar2 != (int *)0x0) {
      *piVar2 = iVar3;
      piVar4 = *(int **)(iVar1 + 0x4936c);
      piVar2[1] = (int)piVar4;
      *piVar4 = (int)piVar2;
      *(int **)(iVar1 + 0x4936c) = piVar2;
    }
    msys::MSndSe::play((MSndSe *)(piVar2 + -0x15),param_2,(MChrBase *)0x0,(VEC2 *)0x0,false);
  }
  return;
}


// FUNC 0x11805724 col::Colosseum::vfunc_0x0 (Colosseum)
//   size 0x150 | file Colosseum+0x5724 | callers(3) 0x1180a058 0x1180a080 0x1180b560 | datarefs 1

void col::Colosseum::vfunc_0x0(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;
  MLyt *this;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  
  *param_1 = &vtable;
  ad::fw::TaskBase::term((TaskBase *)param_1[1],0);
  this = (MLyt *)(param_1 + 0x3a449);
  msys::MLyt::term(this);
  ad::fw::Resource::term((Resource *)(param_1 + 0x3a438));
  *(undefined ***)this = &msys::MLyt::vtable;
  msys::MLyt::term(this);
  __aeabi_vec_dtor(param_1 + 0x3a4f5,&LAB_118012dc,0x10,0xc);
  __aeabi_vec_dtor(param_1 + 0x3a49e,&LAB_11801148,0x1c,0xc);
  iVar3 = msys::MChrBase::vfunc_0x0(this);
  iVar3 = ad::fw::Resource::~Resource((Resource *)(iVar3 + -0x44));
  *(undefined4 *)(iVar3 + -0x24) = &ColosseumPage::vtable;
  if (*(int **)(iVar3 + -4) != (int *)0x0) {
    (**(code **)(**(int **)(iVar3 + -4) + 4))();
  }
  *(undefined4 *)(iVar3 + -4) = 0;
  *(undefined4 *)(iVar3 + -0x24) = &msys::MPageBase::vtable;
  iVar8 = iVar3 + -0x18;
  iVar1 = *(int *)(iVar3 + -0x14);
  while (iVar1 != iVar8) {
    iVar5 = *(int *)(iVar1 + 4);
    *(int *)(iVar1 + 4) = iVar1;
    *(int *)iVar1 = iVar1;
    iVar1 = iVar5;
  }
  *(int *)(iVar3 + -0x14) = iVar8;
  *(int *)iVar8 = iVar8;
  puVar4 = *(undefined4 **)(iVar3 + -0x14);
  *(undefined4 **)(iVar3 + -0x14) = puVar4;
  *puVar4 = *(undefined4 *)(iVar3 + -0x18);
  piVar6 = (int *)(iVar3 + -0x20);
  piVar2 = *(int **)(iVar3 + -0x1c);
  while (piVar2 != piVar6) {
    piVar7 = (int *)piVar2[1];
    piVar2[1] = (int)piVar2;
    *piVar2 = (int)piVar2;
    piVar2 = piVar7;
  }
  *(int **)(iVar3 + -0x1c) = piVar6;
  *piVar6 = (int)piVar6;
  puVar4 = *(undefined4 **)(iVar3 + -0x1c);
  *(undefined4 **)(*piVar6 + 4) = puVar4;
  *puVar4 = *(undefined4 *)(iVar3 + -0x20);
  iVar3 = MsgDataAcsrBase::~MsgDataAcsrBase((MsgDataAcsrBase *)(iVar3 + -0x90));
  msys::MComSys::~MComSys((MComSys *)(iVar3 + -0xe9050));
  return;
}


// FUNC 0x1180588c FUN_1180588c (Colosseum)
//   size 0x34 | file Colosseum+0x588c | callers(1) 0x11809074 | datarefs 3

void FUN_1180588c(undefined1 *param_1)

{
  *param_1 = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0x3f800000;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined2 *)(param_1 + 0x10) = 1;
  *(undefined2 *)(param_1 + 0x12) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  return;
}


// FUNC 0x118058c8 FUN_118058c8 (Colosseum)
//   size 0x1c | file Colosseum+0x58c8 | callers(2) 0x1180b454 0x11809074

void FUN_118058c8(uint *param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = param_2 & 0xff | (param_2 & 0xff) << 8;
  uVar1 = uVar1 | uVar1 << 0x10;
  *param_1 = uVar1;
  param_1[1] = uVar1;
  param_1[2] = uVar1;
  return;
}


// FUNC 0x118058e4 FUN_118058e4 (Colosseum)
//   size 0xdc | file Colosseum+0x58e4 | callers(3) 0x1180b454 0x11809074 0x1180b57c

void FUN_118058e4(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  *param_1 = &msys::MChrBaseCore::vtable;
  param_1[1] = param_1 + 1;
  param_1[2] = param_1 + 1;
  param_1[3] = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  puVar1 = (undefined4 *)MoveVBase::MoveVBase((MoveVBase *)(param_1 + 5));
  *puVar1 = &vtable_for_5MoveVILj1EE;
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(puVar1 + 0xc,FUN_1180b8fc,0x2c,1);
  *(int *)(iVar2 + -8) = iVar2;
  *(undefined1 *)(iVar2 + -4) = 1;
  puVar1 = (undefined4 *)MoveVBase::MoveVBase((MoveVBase *)(iVar2 + 0x2c));
  *puVar1 = &vtable_for_5MoveVILj1EE;
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(puVar1 + 0xc,FUN_1180b8fc,0x2c,1);
  *(int *)(iVar2 + -8) = iVar2;
  *(undefined1 *)(iVar2 + -4) = 1;
  puVar1 = (undefined4 *)MoveVBase::MoveVBase((MoveVBase *)(iVar2 + 0x2c));
  *puVar1 = &vtable_for_5MoveVILj1EE;
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(puVar1 + 0xc,FUN_1180b8fc,0x2c,1);
  *(int *)(iVar2 + -8) = iVar2;
  *(undefined1 *)(iVar2 + -4) = 1;
  *(undefined4 *)(iVar2 + 0x2c) = 0;
  *(undefined4 *)(iVar2 + 0x30) = 0;
  *(undefined4 *)(iVar2 + 0x34) = 0;
  *(undefined1 *)(iVar2 + 0x38) = 0;
  *(undefined1 *)(iVar2 + 0x39) = 0;
  *(undefined4 *)(iVar2 + 0x3c) = 0;
  *(undefined4 *)(iVar2 + 0x40) = 0;
  *(undefined1 *)(iVar2 + 0x44) = 1;
  *(undefined1 *)(iVar2 + 0x45) = 1;
  *(undefined1 *)(iVar2 + 0x46) = 1;
  *(undefined ***)(iVar2 + -0xfc) = &msys::MChrBase::vtable;
  *(int *)(iVar2 + 0x48) = iVar2 + 0x48;
  *(int *)(iVar2 + 0x4c) = iVar2 + 0x48;
  return;
}


// FUNC 0x118059d0 msys::MChrBase::vfunc_0x0 (Colosseum)
//   size 0x14c | file Colosseum+0x59d0 | callers(6) 0x11805724 0x118084cc 0x11808500 0x118097f0 0x1180b7e0 0x1180b5c4 | datarefs 1

int msys::MChrBase::vfunc_0x0(undefined4 *param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  
  *param_1 = &vtable;
  piVar1 = param_1 + 0x51;
  piVar2 = (int *)param_1[0x52];
  while (piVar2 != piVar1) {
    piVar3 = (int *)piVar2[1];
    piVar2[1] = (int)piVar2;
    *piVar2 = (int)piVar2;
    piVar2 = piVar3;
  }
  param_1[0x52] = piVar1;
  *piVar1 = (int)piVar1;
  piVar2 = (int *)param_1[0x52];
  *(int **)(*piVar1 + 4) = piVar2;
  *piVar2 = *piVar1;
  piVar2 = param_1 + 0x4a;
  *param_1 = &MChrBaseCore::vtable;
  iVar4 = param_1[0x4c];
  if (iVar4 != 0) {
    if (*piVar2 != 0) {
      *(undefined4 *)(*piVar2 + 4) = param_1[0x4b];
    }
    if ((int *)param_1[0x4b] != (int *)0x0) {
      *(int *)param_1[0x4b] = *piVar2;
    }
    if (*(int **)(iVar4 + 0x254) == piVar2) {
      *(undefined4 *)(iVar4 + 0x254) = param_1[0x4b];
    }
    param_1[0x4b] = 0;
    *piVar2 = 0;
    param_1[0x4c] = 0;
    *(int *)(iVar4 + 600) = *(int *)(iVar4 + 600) + -1;
  }
  *(undefined ***)(param_1 + 0x33) = &vtable_for_5MoveVILj1EE;
  __aeabi_vec_dtor(param_1 + 0x3f,MoveWorkF::~MoveWorkF,0x2c,1);
  iVar4 = MoveVBase::~MoveVBase((MoveVBase *)(param_1 + 0x33));
  *(undefined ***)(iVar4 + -0x5c) = &vtable_for_5MoveVILj1EE;
  __aeabi_vec_dtor(iVar4 + -0x2c,MoveWorkF::~MoveWorkF,0x2c,1);
  iVar4 = MoveVBase::~MoveVBase((MoveVBase *)(iVar4 + -0x5c));
  *(undefined ***)(iVar4 + -0x5c) = &vtable_for_5MoveVILj1EE;
  __aeabi_vec_dtor(iVar4 + -0x2c,MoveWorkF::~MoveWorkF,0x2c,1);
  iVar4 = MoveVBase::~MoveVBase((MoveVBase *)(iVar4 + -0x5c));
  puVar5 = *(undefined4 **)(iVar4 + -0xc);
  *(undefined4 **)(*(int *)(iVar4 + -0x10) + 4) = puVar5;
  *puVar5 = *(undefined4 *)(iVar4 + -0x10);
  return iVar4 + -0x14;
}


// FUNC 0x11805cbc FUN_11805cbc (Colosseum)
//   size 0x60 | file Colosseum+0x5cbc | callers(4) 0x1180449c 0x11804ad4 0x11806db4 0x11807248

void FUN_11805cbc(int param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 0x6ef8) = param_2;
  *(undefined4 *)(param_1 + 0x6f28) = param_3;
  Message::play((Message *)(param_1 + 0x14c),(PlayParam *)(param_1 + 0x6ef8));
  MoveVBase::stop((MoveVBase *)(param_1 + 0xcc));
  *(undefined4 *)(param_1 + 0xf0) = 0xc3340000;
  *(undefined4 *)(param_1 + 0xe8) = 0;
  *(undefined4 *)(param_1 + 0xec) = 0xc1a00000;
  *(undefined4 *)(param_1 + 0xd8) = 0xc3340000;
  *(undefined4 *)(param_1 + 0xd0) = 0;
  *(undefined4 *)(param_1 + 0xd4) = 0xc1a00000;
  return;
}


// FUNC 0x11805d28 FUN_11805d28 (Colosseum)
//   size 0x114 | file Colosseum+0x5d28 | callers(2) 0x1180406c 0x11804d04

bool FUN_11805d28(int param_1)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  
  uVar6 = 0;
  *(undefined1 *)(param_1 + 0x6100f) = 0;
  if (*(char *)(param_1 + 0x61013) == '\0') {
    iVar4 = 0;
    uVar7 = 0;
  }
  else {
    iVar4 = 10;
    uVar7 = 10;
  }
  do {
    if (-1 < (short)(&DAT_003f9de0)[iVar4 + uVar6]) {
      if (*(char *)(param_1 + 0x61013) == '\0') {
        bVar3 = *(byte *)(param_1 + 0x6100c);
      }
      else {
        bVar3 = *(byte *)(param_1 + 0x6100d);
      }
      if (((uint)bVar3 & 1 << (uVar6 & 0xff)) != 0) {
        uVar1 = uVar7 >> 5;
        uVar2 = 1 << (uVar7 & 0x1f);
        if (((&DAT_003f9e00)[uVar1] & uVar2) == 0) {
          if (*(char *)(param_1 + 0x61013) == '\0') {
            puVar8 = &DAT_1180c268 + uVar6 * 7 + 3;
          }
          else {
            puVar8 = (undefined4 *)(&DAT_1180c32c + (uVar6 * 5 + 1) * 4);
          }
          GameWork::addCoin((GameWork *)&gGameWork,(int)*(short *)(puVar8 + 1));
          GameWork::addItem((GameWork *)&gGameWork,*(undefined2 *)((int)puVar8 + 2),1);
          (&DAT_003f9e00)[uVar1] = (&DAT_003f9e00)[uVar1] | uVar2;
          *(byte *)(param_1 + 0x6100f) = *(byte *)(param_1 + 0x6100f) | (byte)(1 << (uVar6 & 0xff));
        }
      }
    }
    uVar6 = uVar6 + 1;
    uVar7 = uVar7 + 1;
    if (*(char *)(param_1 + 0x61013) == '\0') {
      iVar5 = 7;
    }
    else {
      iVar5 = 4;
    }
  } while ((int)uVar6 < iVar5);
  return *(char *)(param_1 + 0x6100f) != '\0';
}


// FUNC 0x11805e48 FUN_11805e48 (Colosseum)
//   size 0x64 | file Colosseum+0x5e48 | callers(3) 0x118012ec 0x1180449c 0x11804c5c

void FUN_11805e48(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  wchar_t *pwVar3;
  int iVar4;
  
  iVar1 = msys::MComSys::_sys;
  iVar4 = *(int *)(*param_1 + 8);
  if (iVar4 == 0) {
    *(int *)(*param_1 + 8) = msys::MComSys::_sys;
    iVar4 = iVar1;
  }
  uVar2 = LMS_GetTextIndexByLabel(iVar4 + 0xe9058,*(undefined4 *)(param_2 + 8));
  pwVar3 = (wchar_t *)LMS_GetText(iVar4 + 0xe9058,uVar2);
  msys::MMsg::playStr((MMsg *)(param_1 + 0x127),pwVar3,(InsParam *)0x0,false);
  return;
}


// FUNC 0x11805eb0 FUN_11805eb0 (Colosseum)
//   size 0xd0 | file Colosseum+0x5eb0 | callers(1) 0x118012ec

void FUN_11805eb0(int param_1,int param_2,int param_3)

{
  short sVar1;
  int iVar2;
  uint in_fpscr;
  float fVar3;
  LytAnim local_30 [4];
  undefined4 local_2c;
  undefined4 uStack_28;
  undefined4 local_24;
  undefined2 local_20;
  undefined2 local_1e;
  undefined4 local_1c;
  undefined4 local_18;
  
  sVar1 = msys::MLyt::createAnimeAutoSlot
                    ((MLyt *)(param_1 + 0x12bb4),*(char **)(param_2 + param_3 * 8 + 4),(char *)0x0,
                     (char *)0x0);
  iVar2 = msys::MLyt::getAnim((MLyt *)(param_1 + 0x12bb4),sVar1);
  *(int *)(param_1 + 0x60ff4) = iVar2;
  *(ushort *)(iVar2 + 0x12) = *(ushort *)(iVar2 + 0x12) | 2;
  local_30[0] = (LytAnim)0x0;
  local_2c = 0;
  uStack_28 = 0x3f800000;
  local_24 = 0;
  local_20 = 1;
  local_1e = 0;
  local_1c = 0;
  local_18 = 0;
  ad::lyt::LytAnim::init(local_30,*(Layout **)(param_1 + 0x130ac),"SET_TROPHY","");
  iVar2 = 0;
  if (*(char *)(param_1 + 0x61013) != '\0') {
    iVar2 = 7;
  }
  fVar3 = (float)VectorSignedToFloat(iVar2 + param_3,(byte)(in_fpscr >> 0x16) & 3);
  ad::lyt::LytAnim::stopAndSetFrm(local_30,fVar3);
  ad::lyt::LytAnim::term(local_30,true);
  return;
}


// FUNC 0x11805fa4 FUN_11805fa4 (Colosseum)
//   size 0x180 | file Colosseum+0x5fa4 | callers(1) 0x118012ec

void FUN_11805fa4(int param_1)

{
  byte bVar1;
  uint uVar2;
  LytAnim local_50 [4];
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined2 local_40;
  undefined2 local_3e;
  undefined4 local_3c;
  undefined4 local_38;
  
  local_50[0] = (LytAnim)0x0;
  local_4c = 0;
  local_48 = 0x3f800000;
  uStack_44 = 0;
  uVar2 = 0;
  local_40 = 1;
  local_3e = 0;
  local_3c = 0;
  local_38 = 0;
  bVar1 = *(byte *)(param_1 + 0x6100c);
  do {
    ad::lyt::LytAnim::init
              (local_50,*(Layout **)(param_1 + 0x12d04),(char *)(&DAT_118143e8)[uVar2 * 2],"");
    if (((uint)bVar1 & 1 << (uVar2 & 0xff)) == 0) {
      ad::lyt::LytAnim::stopAndSetFrm(local_50,0.0);
    }
    else if ((short)(&DAT_003f9de0)[uVar2] < 0) {
      ad::lyt::LytAnim::stopAndSetFrm(local_50,1.0);
    }
    else {
      ad::lyt::LytAnim::stopAndSetFrm(local_50,2.0);
    }
    ad::lyt::LytAnim::term(local_50,true);
    uVar2 = uVar2 + 1;
  } while ((int)uVar2 < 7);
  bVar1 = *(byte *)(param_1 + 0x6100d);
  uVar2 = 0;
  do {
    ad::lyt::LytAnim::init
              (local_50,*(Layout **)(param_1 + 0x12d04),(char *)(&DAT_11814420)[uVar2 * 2],"");
    if (((uint)bVar1 & 1 << (uVar2 & 0xff)) == 0) {
      ad::lyt::LytAnim::stopAndSetFrm(local_50,0.0);
    }
    else if ((short)(&DAT_003f9df4)[uVar2] < 0) {
      ad::lyt::LytAnim::stopAndSetFrm(local_50,1.0);
    }
    else {
      ad::lyt::LytAnim::stopAndSetFrm(local_50,2.0);
    }
    ad::lyt::LytAnim::term(local_50,true);
    uVar2 = uVar2 + 1;
  } while ((int)uVar2 < 4);
  return;
}


// FUNC 0x11806144 FUN_11806144 (Colosseum)
//   size 0xa8 | file Colosseum+0x6144 | callers(3) 0x11808460 0x1180813c 0x118029c0

void FUN_11806144(int param_1)

{
  int iVar1;
  uint uVar2;
  MDfxChr *this;
  bool bVar3;
  
  this = (MDfxChr *)(param_1 + 0x36bd8);
  iVar1 = (**(code **)(*(int *)this + 0x24))(this);
  if (iVar1 == 0) {
    uVar2 = *(uint *)(param_1 + 0x36d2c);
    if (uVar2 != 0) {
      bVar3 = *(int *)(uVar2 + 4) != uVar2 + 4;
      if (!bVar3) {
        uVar2 = (uint)*(byte *)(uVar2 + 0x172);
      }
      if (bVar3 || uVar2 != 0) {
        return;
      }
    }
    iVar1 = col::GetBootInfo();
    if (*(char *)(iVar1 + 0x20d) == '\f') {
      msys::MDfxChr::playDfx(this,0x2b);
    }
    else {
      if (*(char *)(param_1 + 0x61013) == '\0') {
        uVar2 = 0x29;
      }
      else {
        uVar2 = 0x2e;
      }
      msys::MDfxChr::playDfx(this,uVar2);
    }
    *(undefined2 *)(*(int *)(param_1 + 0x36d2c) + 0xf2) = 0;
  }
  return;
}


// FUNC 0x118061f4 FUN_118061f4 (Colosseum)
//   size 0x248 | file Colosseum+0x61f4 | callers(3) 0x1180406c 0x1180268c 0x11804d04

void FUN_118061f4(int *param_1,int *param_2,int param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  wchar_t *pwVar4;
  uint uVar5;
  int iVar6;
  short *psVar7;
  uint uVar8;
  int iVar9;
  short *psVar10;
  uint in_fpscr;
  float fVar11;
  short local_250 [64];
  undefined2 local_1d0;
  undefined2 local_150;
  undefined2 local_d0;
  uint local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  
  if (param_1[0x525a] != *param_2) {
    *(undefined1 *)(param_1 + 0x525b) = 0xff;
    if (param_3 == 0) {
      *(undefined1 *)((int)param_1 + 0x145) = 0;
      uVar3 = ad::lyt::AnimTransform::GetFrameSize((AnimTransform *)param_1[0x11e]);
      fVar11 = (float)VectorUnsignedToFloat(uVar3,(byte)(in_fpscr >> 0x16) & 3);
      ad::lyt::LytAnim::stopAndSetFrm((LytAnim *)(param_1 + 0x119),fVar11);
      uVar3 = ad::lyt::AnimTransform::GetFrameSize((AnimTransform *)param_1[0x125]);
      fVar11 = (float)VectorUnsignedToFloat(uVar3,(byte)(in_fpscr >> 0x16) & 3);
      ad::lyt::LytAnim::stopAndSetFrm((LytAnim *)(param_1 + 0x120),fVar11);
    }
    else {
      ad::lyt::LytNumReel3::setValueInstant
                ((LytNumReel3 *)(param_1 + 0x55),(int)*(short *)((int)param_2 + 6));
      fVar11 = 0.0;
      *(undefined1 *)((int)param_1 + 0x145) = 1;
      ad::lyt::LytAnim::stopAndSetFrm((LytAnim *)(param_1 + 0x119),0.0);
      local_250[0] = 0;
      local_50 = 0;
      local_1d0 = 0;
      local_4c = 0;
      local_150 = 0;
      local_48 = 0;
      local_d0 = 0;
      local_44 = 0;
      iVar6 = param_2[1];
      iVar9 = 10;
      uVar8 = 1;
      do {
        iVar1 = __aeabi_uidivmod((int)(short)iVar6,iVar9);
        if (iVar1 == 0) break;
        uVar8 = uVar8 + 1;
        iVar9 = iVar9 * 10;
      } while (uVar8 < 0x40);
      FUN_11801280(local_250,0x40,0x3f,
                   &MessageSimple::InsParam::setNum(unsigned_char,int,bool)::string_literal,
                   (int)(short)iVar6);
      if (uVar8 != 0) {
        uVar2 = uVar8 & 1;
        if (uVar2 != 0) {
          local_250[0] = local_250[0] + -0x120;
        }
        uVar5 = (uint)(uVar2 != 0);
        for (; uVar2 < uVar8; uVar2 = uVar2 + 2) {
          psVar7 = local_250 + uVar5;
          psVar10 = local_250 + uVar5 + 1;
          *psVar7 = *psVar7 + -0x120;
          uVar5 = uVar5 + 2;
          *psVar10 = *psVar10 + -0x120;
        }
      }
      iVar9 = msys::MComSys::_sys;
      iVar6 = *(int *)(*param_1 + 8);
      if (iVar6 == 0) {
        *(int *)(*param_1 + 8) = msys::MComSys::_sys;
        iVar6 = iVar9;
      }
      local_50 = uVar8;
      uVar3 = LMS_GetTextIndexByLabel(iVar6 + 0xe9058,"MES_EMesColosseum_title_clear_turn_2");
      pwVar4 = (wchar_t *)LMS_GetText(iVar6 + 0xe9058,uVar3);
      msys::MMsg::playStr((MMsg *)(param_1 + 0x1c38),pwVar4,(InsParam *)local_250,false);
      ad::lyt::LytNumReel3::setValueInstant((LytNumReel3 *)(param_1 + 0xe1),(int)(short)param_2[3]);
      if (param_4 != 0) {
        uVar3 = ad::lyt::AnimTransform::GetFrameSize((AnimTransform *)param_1[0x125]);
        fVar11 = (float)VectorUnsignedToFloat(uVar3,(byte)(in_fpscr >> 0x16) & 3);
      }
      ad::lyt::LytAnim::stopAndSetFrm((LytAnim *)(param_1 + 0x120),fVar11);
    }
    param_1[0x525a] = *param_2;
    *(char *)((int)param_1 + 0x1496d) = (char)param_3;
  }
  return;
}


// FUNC 0x11806474 FUN_11806474 (Colosseum)
//   size 0x100 | file Colosseum+0x6474 | callers(3) 0x1180268c 0x1180406c 0x11804d04

void FUN_11806474(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint in_fpscr;
  float fVar3;
  
  iVar1 = msys::MListWndPBase::getCurNo((MListWndPBase *)(param_1 + 0x3df84));
  if (*(char *)(param_1 + 0x60b00) == (&DAT_1180c32c)[iVar1 * 0x14]) {
    return;
  }
  *(undefined4 *)(param_1 + 0x60afc) = 0;
  if (param_2 == 0) {
    *(undefined1 *)(param_1 + 0x4c2d9) = 0;
    uVar2 = ad::lyt::AnimTransform::GetFrameSize(*(AnimTransform **)(param_1 + 0x4c60c));
    fVar3 = (float)VectorUnsignedToFloat(uVar2,(byte)(in_fpscr >> 0x16) & 3);
    ad::lyt::LytAnim::stopAndSetFrm((LytAnim *)(param_1 + 0x4c5f8),fVar3);
    uVar2 = ad::lyt::AnimTransform::GetFrameSize(*(AnimTransform **)(param_1 + 0x4c628));
    fVar3 = (float)VectorUnsignedToFloat(uVar2,(byte)(in_fpscr >> 0x16) & 3);
  }
  else {
    uVar2 = ad::lyt::AnimTransform::GetFrameSize(*(AnimTransform **)(param_1 + 0x4c60c));
    fVar3 = (float)VectorUnsignedToFloat(uVar2,(byte)(in_fpscr >> 0x16) & 3);
    ad::lyt::LytAnim::stopAndSetFrm((LytAnim *)(param_1 + 0x4c5f8),fVar3);
    ad::lyt::LytNumReel3::setValueInstant
              ((LytNumReel3 *)(param_1 + 0x4c518),(int)(short)(&DAT_1180c330)[iVar1 * 10]);
    if (param_3 != 0) {
      uVar2 = ad::lyt::AnimTransform::GetFrameSize(*(AnimTransform **)(param_1 + 0x4c628));
      fVar3 = (float)VectorUnsignedToFloat(uVar2,(byte)(in_fpscr >> 0x16) & 3);
      ad::lyt::LytAnim::stopAndSetFrm((LytAnim *)(param_1 + 0x4c614),fVar3);
      goto LAB_11806564;
    }
    fVar3 = 0.0;
  }
  ad::lyt::LytAnim::stopAndSetFrm((LytAnim *)(param_1 + 0x4c614),fVar3);
LAB_11806564:
  *(undefined *)(param_1 + 0x60b00) = (&DAT_1180c32c)[iVar1 * 0x14];
  *(char *)(param_1 + 0x60b01) = (char)param_2;
  return;
}


// FUNC 0x1180657c FUN_1180657c (Colosseum)
//   size 0x280 | file Colosseum+0x657c | callers(5) 0x11806e00 0x118076e0 0x11804a58 0x11806f04 0x11801e4c

void FUN_1180657c(int param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int *piVar6;
  undefined4 extraout_r1;
  undefined4 uVar7;
  MCtrlUserData *pMVar8;
  int iVar9;
  int iVar10;
  MCtrlUserData *this;
  uint in_fpscr;
  undefined4 extraout_s0;
  undefined4 uVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float local_68 [6];
  char *local_50 [3];
  int local_44 [4];
  
  if (*(int *)(param_1 + 4) == 0) {
    return;
  }
  iVar2 = (int)*(char *)(param_1 + 0x18);
  if (-1 < iVar2) {
    if (iVar2 != *(char *)(param_1 + 0x19)) {
      *(char *)(param_1 + 0x19) = *(char *)(param_1 + 0x18);
      iVar10 = *(int *)(*(int *)(param_1 + 4) + 0x150);
      pMVar8 = *(MCtrlUserData **)(param_1 + 0x10);
      iVar2 = *(int *)(param_1 + 0x30 + iVar2 * 4);
      this = (MCtrlUserData *)0x0;
      if (pMVar8 != (MCtrlUserData *)(param_1 + 0x10)) {
        do {
          iVar3 = strcmp(*(char **)(pMVar8 + 8),(char *)(iVar2 + 0x80));
          if (iVar3 == 0) {
            this = pMVar8;
            break;
          }
          pMVar8 = *(MCtrlUserData **)pMVar8;
        } while (pMVar8 != (MCtrlUserData *)(param_1 + 0x10));
      }
      iVar3 = msys::MCtrlUserData::findExtUserDataByName(this,&DAT_003f7fab);
      fVar14 = *(float *)(iVar2 + 0x54);
      fVar15 = *(float *)(iVar2 + 100);
      piVar4 = *(int **)(*(int *)(iVar2 + 0xac) + 0x10);
      fVar16 = *(float *)(iVar2 + 0x74);
      iVar2 = (**(code **)(*piVar4 + 0x2c))(piVar4,*(undefined4 *)(this + 0xc),1);
      if (iVar2 != 0) {
        uVar5 = *(undefined4 *)(iVar2 + 0x3c);
        uVar7 = *(undefined4 *)(iVar2 + 0x40);
        uVar11 = extraout_s0;
      }
      else {
        uVar11 = 0;
        uVar5 = 0;
        uVar7 = extraout_r1;
      }
      iVar9 = 0;
      if (iVar2 != 0) {
        *(undefined4 *)(param_1 + 0x1c) = uVar5;
        *(undefined4 *)(param_1 + 0x20) = uVar7;
      }
      else {
        *(undefined4 *)(param_1 + 0x20) = uVar11;
        *(undefined4 *)(param_1 + 0x1c) = uVar11;
      }
      piVar4 = (int *)(iVar3 + *(int *)(iVar3 + 4));
      local_50[0] = s_SQ_CURSOR_S_003f7faf;
      local_50[1] = s_SQ_CURSOR_L_003f7fbb;
      local_50[2] = s_SQ_CURSOR_SS_003f7fc7;
      do {
        piVar6 = *(int **)(iVar10 + 0x10);
        iVar2 = (**(code **)(*piVar6 + 0x2c))(piVar6,local_68[iVar9 + 6],1);
        local_44[iVar9] = iVar2;
        iVar9 = iVar9 + 1;
        *(byte *)(iVar2 + 0x44) = *(byte *)(iVar2 + 0x44) & 0xfe;
      } while (iVar9 < 3);
      local_68[0] = 4.0;
      local_68[1] = 4.0;
      local_68[2] = 10.0;
      local_68[3] = 10.0;
      local_68[4] = 2.0;
      local_68[5] = 2.0;
      iVar2 = local_44[*piVar4];
      *(int *)(param_1 + 8) = iVar2;
      *(byte *)(iVar2 + 0x44) = *(byte *)(iVar2 + 0x44) & 0xfe | 1;
      fVar12 = (float)VectorSignedToFloat(piVar4[3],(byte)(in_fpscr >> 0x16) & 3);
      *(float *)(param_1 + 0x1c) = *(float *)(param_1 + 0x1c) + local_68[*piVar4 * 2] + fVar12;
      fVar12 = (float)VectorSignedToFloat(piVar4[4],(byte)(in_fpscr >> 0x16) & 3);
      *(float *)(param_1 + 0x20) = *(float *)(param_1 + 0x20) + local_68[*piVar4 * 2 + 1] + fVar12;
      iVar2 = *(int *)(param_1 + 4);
      fVar13 = (float)VectorSignedToFloat(piVar4[1],(byte)(in_fpscr >> 0x16) & 3);
      fVar12 = (float)VectorSignedToFloat(piVar4[2],(byte)(in_fpscr >> 0x16) & 3);
      fVar14 = fVar14 + fVar13;
      fVar15 = fVar15 + fVar12;
      fVar16 = fVar16 + 1.0;
      MoveVBase::stop((MoveVBase *)(iVar2 + 0xcc));
      *(float *)(iVar2 + 0xe8) = fVar14;
      *(float *)(iVar2 + 0xec) = fVar15;
      *(float *)(iVar2 + 0xf0) = fVar16;
      *(float *)(iVar2 + 0xd0) = fVar14;
      *(float *)(iVar2 + 0xd4) = fVar15;
      *(float *)(iVar2 + 0xd8) = fVar16;
    }
    fVar16 = *(float *)(param_1 + 0x1c);
    fVar14 = *(float *)(param_1 + 0x20);
    fVar15 = (float)VectorSignedToFloat((int)*(short *)(param_1 + 0x1a),(byte)(in_fpscr >> 0x16) & 3
                                       );
    sVar1 = (short)(int)(fVar15 - *(float *)(param_1 + 0x2c));
    *(short *)(param_1 + 0x1a) = sVar1;
    if (sVar1 < 0) {
      *(undefined2 *)(param_1 + 0x1a) = 0x1e;
    }
    else if (sVar1 < 0xf) {
      fVar16 = fVar16 + 2.0;
      fVar14 = fVar14 + 2.0;
    }
    iVar2 = *(int *)(param_1 + 8);
    *(float *)(iVar2 + 0x3c) = fVar16;
    *(float *)(iVar2 + 0x40) = fVar14;
    *(byte *)(iVar2 + 0x44) = *(byte *)(iVar2 + 0x44) & 0xef | 0x10;
    *(undefined1 *)(*(int *)(param_1 + 4) + 0x374) = 1;
  }
  return;
}


// FUNC 0x11806814 FUN_11806814 (Colosseum)
//   size 0x9c | file Colosseum+0x6814 | callers(7) 0x1180268c 0x118053a8 0x11808a48 0x1180449c 0x118077c0 0x11801e4c 0x1180813c

MSndSe * FUN_11806814(undefined4 param_1,uint param_2,MChrBase *param_3,VEC2 *param_4,bool param_5)

{
  int iVar1;
  int iVar2;
  MSndSe *this;
  int *piVar3;
  undefined4 *puVar4;
  int *piVar5;
  
  iVar1 = msys::MComSys::_sys;
  iVar2 = msys::MComSys::_sys + 0x49368;
  piVar5 = *(int **)(msys::MComSys::_sys + 0x49374);
  this = (MSndSe *)(piVar5 + -0x15);
  if ((MSndSe *)(msys::MComSys::_sys + 0x4931c) == this) {
    this = (MSndSe *)0x0;
  }
  else {
    piVar3 = (int *)piVar5[1];
    if (piVar3 != piVar5) {
      *(int **)(*piVar5 + 4) = piVar3;
      *piVar3 = *piVar5;
      *piVar5 = (int)piVar5;
      piVar5[1] = (int)piVar5;
    }
    piVar3 = (int *)piVar5[1];
    *(int **)(*piVar5 + 4) = piVar3;
    *piVar3 = *piVar5;
    if (piVar5 != (int *)0x0) {
      *piVar5 = iVar2;
      puVar4 = *(undefined4 **)(iVar1 + 0x4936c);
      piVar5[1] = (int)puVar4;
      *puVar4 = piVar5;
      *(int **)(iVar1 + 0x4936c) = piVar5;
    }
    msys::MSndSe::play(this,param_2,param_3,param_4,param_5);
  }
  return this;
}


// FUNC 0x118068b4 FUN_118068b4 (Colosseum)
//   size 0xa8 | file Colosseum+0x68b4 | callers(15) 0x1180268c 0x118053a8 0x11808a48 0x118055d0 0x11806e00 0x118076e0 0x11807928 0x118079c4 ...

void FUN_118068b4(int param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = msys::MComSys::_sys;
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  bVar1 = SUB41(param_2,0);
  *(bool *)(*(int *)(param_1 + 8) + 0xe6508) = bVar1;
  iVar3 = *(int *)(param_1 + 8);
  if (iVar3 == 0) {
    *(int *)(param_1 + 8) = iVar2;
    iVar3 = iVar2;
  }
  *(undefined1 *)(iVar3 + 0xe650a) = 1;
  if (param_2 == 0) {
    msys::MListWndPBase::setEnableInput((MListWndPBase *)(param_1 + 0x3df84),false);
  }
  else {
    if (*(char *)(param_1 + 0x3e0c5) != '\0') {
      msys::MListWndPBase::setEnableInput((MListWndPBase *)(param_1 + 0x3df84),bVar1);
    }
    if (*(char *)(param_1 + 0x45251) == '\0') {
      return;
    }
  }
  msys::MListWndPBase::setEnableInput((MListWndPBase *)(param_1 + 0x45110),bVar1);
  return;
}


// FUNC 0x11806968 FUN_11806968 (Colosseum)
//   size 0x134 | file Colosseum+0x6968 | callers(2) 0x118012ec 0x118019c0

void FUN_11806968(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (((nn::math::VEC3::One()::one & 1) == 0) &&
     (iVar4 = __cxa_guard_acquire(&nn::math::VEC3::One()::one), iVar4 != 0)) {
    nn::math::VEC3::One()::one = 0x3f800000;
    DAT_00434c40 = 0x3f800000;
    DAT_00434c44 = 0x3f800000;
    __cxa_guard_release(&nn::math::VEC3::One()::one);
  }
  MoveVBase::stop((MoveVBase *)(param_1 + 0x14));
  uVar3 = DAT_00434c44;
  uVar2 = DAT_00434c40;
  uVar1 = nn::math::VEC3::One()::one;
  *(undefined4 *)(param_1 + 0x30) = nn::math::VEC3::One()::one;
  *(undefined4 *)(param_1 + 0x34) = uVar2;
  *(undefined4 *)(param_1 + 0x38) = uVar3;
  *(undefined4 *)(param_1 + 0x18) = uVar1;
  *(undefined4 *)(param_1 + 0x1c) = uVar2;
  *(undefined4 *)(param_1 + 0x20) = uVar3;
  if ((((byte)nn::math::VEC3::Zero()::zero & 1) == 0) &&
     (iVar4 = __cxa_guard_acquire(&nn::math::VEC3::Zero()::zero), iVar4 != 0)) {
    nn::math::VEC3::Zero()::zero = 0;
    DAT_00434c4c = 0;
    DAT_00434c50 = 0;
    __cxa_guard_release(&nn::math::VEC3::Zero()::zero);
  }
  MoveVBase::stop((MoveVBase *)(param_1 + 0x70));
  uVar3 = DAT_00434c50;
  uVar2 = DAT_00434c4c;
  uVar1 = nn::math::VEC3::Zero()::zero;
  *(undefined4 *)(param_1 + 0x8c) = nn::math::VEC3::Zero()::zero;
  *(undefined4 *)(param_1 + 0x90) = uVar2;
  *(undefined4 *)(param_1 + 0x94) = uVar3;
  *(undefined4 *)(param_1 + 0x74) = uVar1;
  *(undefined4 *)(param_1 + 0x78) = uVar2;
  *(undefined4 *)(param_1 + 0x7c) = uVar3;
  if ((((byte)nn::math::VEC3::Zero()::zero & 1) == 0) &&
     (iVar4 = __cxa_guard_acquire(&nn::math::VEC3::Zero()::zero), iVar4 != 0)) {
    nn::math::VEC3::Zero()::zero = 0;
    DAT_00434c4c = 0;
    DAT_00434c50 = 0;
    __cxa_guard_release(&nn::math::VEC3::Zero()::zero);
  }
  MoveVBase::stop((MoveVBase *)(param_1 + 0xcc));
  uVar3 = DAT_00434c50;
  uVar2 = DAT_00434c4c;
  uVar1 = nn::math::VEC3::Zero()::zero;
  *(undefined4 *)(param_1 + 0xe8) = nn::math::VEC3::Zero()::zero;
  *(undefined4 *)(param_1 + 0xec) = uVar2;
  *(undefined4 *)(param_1 + 0xf0) = uVar3;
  *(undefined4 *)(param_1 + 0xd0) = uVar1;
  *(undefined4 *)(param_1 + 0xd4) = uVar2;
  *(undefined4 *)(param_1 + 0xd8) = uVar3;
  return;
}


// FUNC 0x11806ab4 FUN_11806ab4 (Colosseum)
//   size 0x1b4 | file Colosseum+0x6ab4 | callers(3) 0x118012ec 0x1180406c 0x11804d04

void FUN_11806ab4(MListWndPBase *param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  char cVar3;
  MListWndPBase MVar4;
  short sVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  MListWndPBase *pMVar9;
  MListWndPBase *pMVar10;
  uint uVar11;
  short *psVar12;
  int iVar13;
  short *psVar14;
  bool bVar15;
  
  uVar11 = 0;
  bVar15 = param_2 != 0;
  if (bVar15) {
    iVar13 = 4;
  }
  else {
    iVar13 = 7;
  }
  pMVar9 = param_1 + 0x6f80;
  *(char *)(*(int *)(param_1 + 0x154) + 0x144) = (char)iVar13;
  if (bVar15) {
    psVar12 = &DAT_003f9df4;
  }
  else {
    psVar12 = &DAT_003f9de0;
  }
  if (bVar15) {
    bVar1 = *(byte *)(*(int *)(param_1 + 0x7060) + 0x6100d);
  }
  else {
    bVar1 = *(byte *)(*(int *)(param_1 + 0x7060) + 0x6100c);
  }
  if (iVar13 != 0) {
    do {
      if (param_2 == 0) {
        psVar14 = (short *)(&DAT_1180c268 + uVar11 * 7 + 3);
      }
      else {
        psVar14 = (short *)(&DAT_1180c32c + (uVar11 * 5 + 1) * 4);
      }
      if (((uint)bVar1 & 1 << (uVar11 & 0xff)) == 0) {
        pMVar9[8] = (MListWndPBase)0xff;
        iVar2 = msys::MComSys::_sys;
        iVar8 = *(int *)(*(int *)(param_1 + 0x7060) + 8);
        if (iVar8 == 0) {
          *(int *)(*(int *)(param_1 + 0x7060) + 8) = msys::MComSys::_sys;
          iVar8 = iVar2;
        }
        uVar6 = LMS_GetTextIndexByLabel(iVar8 + 0xe9058,"MES_EMesColosseum_class_0");
        uVar6 = LMS_GetText(iVar8 + 0xe9058,uVar6);
        *(undefined4 *)(pMVar9 + 0x10) = uVar6;
        *(undefined2 *)(pMVar9 + 4) = 0xffff;
        pMVar9[0xe] = (MListWndPBase)0x1;
      }
      else {
        cVar3 = '\0';
        if (param_2 != 0) {
          cVar3 = '\a';
        }
        pMVar9[8] = (MListWndPBase)(cVar3 + (char)uVar11);
        iVar2 = msys::MComSys::_sys;
        iVar8 = *(int *)(*(int *)(param_1 + 0x7060) + 8);
        if (iVar8 == 0) {
          *(int *)(*(int *)(param_1 + 0x7060) + 8) = msys::MComSys::_sys;
          iVar8 = iVar2;
        }
        uVar6 = LMS_GetTextIndexByLabel(iVar8 + 0xe9058,*(undefined4 *)(psVar14 + 4));
        uVar6 = LMS_GetText(iVar8 + 0xe9058,uVar6);
        *(undefined4 *)(pMVar9 + 0x10) = uVar6;
        if ((param_2 != 0) || (sVar5 = *psVar12, sVar5 < 0)) {
          sVar5 = -1;
        }
        *(short *)(pMVar9 + 4) = sVar5;
        if ((*psVar12 < 0) &&
           (uVar7 = GameWork::getCoin((GameWork *)&gGameWork), uVar7 < (uint)(int)*psVar14)) {
          MVar4 = (MListWndPBase)0x0;
        }
        else {
          MVar4 = (MListWndPBase)0x1;
        }
        pMVar9[0xe] = MVar4;
      }
      *(uint *)pMVar9 = uVar11;
      pMVar10 = pMVar9 + 0x14;
      pMVar9[0xf] = (MListWndPBase)0x0;
      uVar11 = uVar11 + 1;
      psVar12 = psVar12 + 1;
      pMVar9 = pMVar9 + 0x1c;
      *(undefined4 *)pMVar10 = 0;
    } while ((int)uVar11 < iVar13);
  }
  msys::MListWndPBase::resetCur(param_1);
  return;
}


// FUNC 0x11806cf0 FUN_11806cf0 (Colosseum)
//   size 0xbc | file Colosseum+0x6cf0 | callers(2) 0x11809074 0x118012ec

void FUN_11806cf0(int param_1)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = (DAT_003f99b4 & 0xf) >> 3 | ((DAT_003f99b4 & 0x1ff) >> 8) << 1 |
          ((DAT_003f99bc & 0x7fffffff) >> 0x1e) << 2 | ((DAT_003f99c0 & 0x3fffff) >> 0x15) << 3 |
          ((DAT_003f99fc & 0x7ffff) >> 0x12) << 4 | ((DAT_003f99cc & 0xfffff) >> 0x13) << 5;
  uVar2 = 0;
  bVar1 = (byte)uVar3;
  *(byte *)(param_1 + 0x6100c) = bVar1;
  while( true ) {
    if ((short)(&DAT_003f9de0)[uVar2] < 0) {
      return;
    }
    if ((uVar3 & 1 << uVar2) == 0) break;
    uVar2 = uVar2 + 1 & 0xff;
    if (5 < uVar2) {
      *(byte *)(param_1 + 0x6100c) = bVar1 | 0x40;
      return;
    }
  }
  return;
}


// FUNC 0x11806db4 FUN_11806db4 (Colosseum)
//   size 0x34 | file Colosseum+0x6db4 | callers(0) | datarefs 4

void FUN_11806db4(int param_1)

{
  FUN_11805cbc(param_1 + 0x3704c,"menu_save_err_03",0);
  *(undefined **)(param_1 + 0x12a04) = &DAT_118053a4;
  *(undefined4 *)(param_1 + 0x12a08) = 0;
  return;
}


// FUNC 0x11806e00 FUN_11806e00 (Colosseum)
//   size 0x78 | file Colosseum+0x6e00 | callers(0) | datarefs 1

void FUN_11806e00(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_118068b4(param_1,0,param_3,param_4,param_4);
  msys::MCursorBase::setVisible((MCursorBase *)(param_1 + 0x13304),false);
  FUN_1180657c((MCursorBase *)(param_1 + 0x13304));
  *(undefined1 *)(param_1 + 0x45251) = 1;
  msys::MListWndPBase::resetCur((MListWndPBase *)(param_1 + 0x45110));
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x12f5c),1,1,(char *)0x0,(char *)0x0);
  *(code **)(param_1 + 0x12a04) = FUN_11807928;
  *(undefined4 *)(param_1 + 0x12a08) = 0;
  return;
}


// FUNC 0x11806e7c FUN_11806e7c (Colosseum)
//   size 0x80 | file Colosseum+0x6e7c | callers(0) | datarefs 2

void FUN_11806e7c(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = msys::MListWndPBase::getCurItem();
  msys::MMsg::playStr((MMsg *)(param_1 + 0x13854),*(wchar_t **)(iVar1 + 0x10),(InsParam *)0x0,false)
  ;
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x12f5c),2,1,(char *)0x0,(char *)0x0);
  uVar2 = msys::MListWndPBase::getCurItem();
  FUN_1180229c(param_1 + 0x60b04,uVar2);
  *(code **)(param_1 + 0x12a04) = FUN_118079c4;
  *(undefined4 *)(param_1 + 0x12a08) = 0;
  return;
}


// FUNC 0x11806f04 FUN_11806f04 (Colosseum)
//   size 0xfc | file Colosseum+0x6f04 | callers(0) | datarefs 6

void FUN_11806f04(int param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = msys::MLyt::isEnableAnime((MLyt *)(param_1 + 0x12f5c));
  if (iVar1 == 0) {
    iVar1 = 0;
    do {
      piVar2 = *(int **)(param_1 + iVar1 * 4 + 0x13340);
      (**(code **)(*piVar2 + 0x28))(piVar2,0);
      iVar1 = iVar1 + 1;
    } while (iVar1 < 7);
    (**(code **)(**(int **)(param_1 + 0x13340) + 0x28))(*(int **)(param_1 + 0x13340),1);
    (**(code **)(**(int **)(param_1 + 0x13344) + 0x28))(*(int **)(param_1 + 0x13344),1);
    (**(code **)(**(int **)(param_1 + 0x13350) + 0x28))(*(int **)(param_1 + 0x13350),1);
    (**(code **)(**(int **)(param_1 + 0x1334c) + 0x28))(*(int **)(param_1 + 0x1334c),1);
    msys::MCursorBase::setVisible((MCursorBase *)(param_1 + 0x13304),true);
    *(bool *)(param_1 + 0x1331c) = *(char *)(param_1 + 0x61013) != '\0';
    FUN_1180657c((MCursorBase *)(param_1 + 0x13304));
    FUN_118068b4(param_1,1);
    *(code **)(param_1 + 0x12a04) = FUN_11801e4c;
    *(undefined4 *)(param_1 + 0x12a08) = 0;
    *(code **)(param_1 + 0x12a0c) = FUN_11804334;
    *(undefined4 *)(param_1 + 0x12a10) = 0;
  }
  return;
}


// FUNC 0x11807008 FUN_11807008 (Colosseum)
//   size 0x270 | file Colosseum+0x7008 | callers(0) | datarefs 4

void FUN_11807008(int param_1)

{
  undefined1 uVar1;
  byte bVar2;
  char *__dest;
  Encount *pEVar3;
  MListWndPBase *this;
  int iVar4;
  int iVar5;
  BootInfo *this_00;
  undefined4 uVar6;
  char *pcVar7;
  char *__src;
  
  this = (MListWndPBase *)(param_1 + 0x3df84);
  bVar2 = msys::MListWndPBase::getCurNo(this);
  iVar4 = col::GetBootInfo();
  *(byte *)(iVar4 + 0x20d) = bVar2;
  iVar4 = col::GetBootInfo();
  *(undefined1 *)(iVar4 + 0x20c) = *(undefined1 *)(param_1 + 0x61013);
  if (*(char *)(param_1 + 0x61013) != '\0') {
    iVar4 = msys::MListWndPBase::getCurNo(this);
    uVar1 = (&DAT_1180c32c)[iVar4 * 0x14];
    SndSys::stopAllBgm((SndSys *)&gSndSys,0x10);
    hb::SetBootInfoColosseum(uVar1);
    iVar4 = msys::MComSys::_sys;
    iVar5 = *(int *)(param_1 + 8);
    if (iVar5 == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar5 = iVar4;
    }
    GameMain::Change(0,*(undefined4 *)(iVar5 + 4));
    return;
  }
  this_00 = (BootInfo *)col::GetBootInfo();
  col::BootInfo::dataPartyBackup(this_00);
  iVar4 = msys::MListWndPBase::getCurNo(this);
  __src = (char *)(&DAT_1180c268)[iVar4 * 7];
  uVar6 = *(undefined4 *)(&DAT_1180c26c + iVar4 * 0x1c);
  if (5 < bVar2) {
    __src = "scn_challenge_1.bai";
  }
  __dest = (char *)btl::GetBootInfo();
  *__dest = '\0';
  __dest[0x30] = '\0';
  __dest[0x60] = '\0';
  __dest[0x90] = '\0';
  __dest[0xc0] = '\0';
  __dest[0xc1] = '\0';
  __dest[0xc2] = '\0';
  __dest[0xc3] = '\0';
  __dest[0xc4] = '\0';
  __dest[0xc5] = '\0';
  __dest[0xc6] = '\0';
  __dest[199] = '\0';
  __dest[200] = '\x03';
  __dest[0xc9] = '\0';
  __dest[0xca] = '\0';
  __dest[0xcb] = '\0';
  __dest[0xcc] = '\0';
  __dest[0xcd] = '\0';
  __dest[0xce] = '\x01';
  __dest[0xcf] = '\x01';
  pcVar7 = __dest + 0x100;
  iVar4 = 4;
  __dest[0xd0] = '\0';
  do {
    iVar4 = iVar4 + -1;
    pcVar7[0] = '\0';
    pcVar7[1] = '\0';
    pcVar7[2] = '\0';
    pcVar7[3] = '\0';
    pcVar7 = pcVar7 + 4;
  } while (iVar4 != 0);
  pcVar7 = __dest + 0x114;
  iVar4 = 2;
  __dest[0x110] = '\0';
  do {
    iVar4 = iVar4 + -1;
    pcVar7[0] = '\0';
    pcVar7[1] = '\0';
    pcVar7[2] = '\0';
    pcVar7[3] = '\0';
    pcVar7 = pcVar7 + 4;
  } while (iVar4 != 0);
  __dest[0x11c] = '\0';
  __dest[0x11d] = '\0';
  __dest[0x11e] = 'd';
  __dest[0x11f] = '\0';
  __dest[0x120] = 'd';
  __dest[0x121] = '\0';
  __dest[0x122] = '\x01';
  __dest[0x124] = '\0';
  __dest[0x125] = '\0';
  __dest[0x126] = '\0';
  __dest[0x127] = '\0';
  __dest[0x128] = '\0';
  __dest[0x129] = '\0';
  strcpy(__dest,__src);
  strcpy(__dest + 0x30,"bmp_i_none_01");
  __dest[0xc0] = 'V';
  __dest[0xc1] = '\x03';
  __dest[0xc2] = '\0';
  __dest[0xc3] = '\x01';
  __dest[200] = '\x03';
  __dest[0xc9] = '\0';
  __dest[0xca] = '\0';
  __dest[0xcb] = '\0';
  __dest[0xcc] = '\x01';
  __dest[0xce] = '\x02';
  __dest[0x128] = 5 < bVar2;
  __dest[0x129] = (char)uVar6;
  __dest[0x110] = '\0';
  __dest[0x11e] = '\0';
  __dest[0x11f] = '\0';
  __dest[0x120] = '\0';
  __dest[0x121] = '\0';
  __dest[0x122] = '\0';
  pEVar3 = (Encount *)ad::Encount::GetInst();
  ad::Encount::startLoadRes(pEVar3,__dest[0xc9],__dest[200],__dest[0xcb],__dest[0xce],3);
  SndSys::stopAllBgm((SndSys *)&gSndSys,0x10);
  iVar4 = msys::MComSys::_sys;
  iVar5 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar5 = iVar4;
  }
  GameMain::Change(10,*(undefined4 *)(iVar5 + 4));
  return;
}


// FUNC 0x11807118 FUN_11807118 (Colosseum)
//   size 0x10c | file Colosseum+0x7118 | callers(0) | datarefs 3

void FUN_11807118(int param_1)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  float fVar4;
  undefined4 local_20 [2];
  
  iVar1 = msys::MLyt::isBusyAnime((MLyt *)(param_1 + 0x12bb4));
  if ((iVar1 == 0) &&
     (iVar2 = msys::MLyt::isBusyAnime((MLyt *)(param_1 + 0x12f5c)), iVar1 = msys::MComSys::_sys,
     iVar2 == 0)) {
    if ((*(byte *)(param_1 + 0x6100a) & 1) != 0) {
      iVar2 = *(int *)(param_1 + 8);
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar2 = iVar1;
      }
      iVar1 = ad::fw::TaskBase::isFps30(*(TaskBase **)(iVar2 + 4));
      if (iVar1 == 0) {
        fVar4 = 1.0;
      }
      else {
        fVar4 = 2.0;
      }
      iVar1 = Frm::update(fVar4);
      if (iVar1 != 0) {
        return;
      }
    }
    iVar1 = msys::MComSys::_sys;
    if (*(char *)(param_1 + 0x61013) == '\0') {
      pcVar3 = FUN_11807008;
    }
    else {
      iVar2 = *(int *)(param_1 + 8);
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar2 = iVar1;
      }
      local_20[0] = 0xff000000;
      MoveC::moveFrm((MoveC *)(iVar2 + 0x4acd4),(Color8 *)local_20,16.0);
      MoveC::moveFrm((MoveC *)(iVar2 + 0x4ad14),(Color8 *)local_20,16.0);
      pcVar3 = (code *)&LAB_11807688;
    }
    *(code **)(param_1 + 0x12a04) = pcVar3;
    *(undefined4 *)(param_1 + 0x12a08) = 0;
  }
  return;
}


// FUNC 0x11807248 FUN_11807248 (Colosseum)
//   size 0x80 | file Colosseum+0x7248 | callers(0) | datarefs 2

void FUN_11807248(int param_1)

{
  if (*(int *)(param_1 + 0x3dc94) == 0) {
    if (*(int *)(param_1 + 0x3df80) == 0) {
      FUN_11805cbc(param_1 + 0x3704c,"menu_save_err_03",0);
      *(undefined **)(param_1 + 0x12a04) = &DAT_118053a4;
      *(undefined4 *)(param_1 + 0x12a08) = 0;
      return;
    }
    FUN_11805cbc(param_1 + 0x3704c,"menu_save_err_02",0);
    *(undefined2 *)(Backup::_fs + 0x24) = 0;
    Backup::format();
    *(code **)(param_1 + 0x12a04) = FUN_118018b4;
    *(undefined4 *)(param_1 + 0x12a08) = 0;
  }
  return;
}


// FUNC 0x118072ec FUN_118072ec (Colosseum)
//   size 0x48 | file Colosseum+0x72ec | callers(0) | datarefs 1

void FUN_118072ec(int param_1)

{
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x12f5c),1,0,(char *)0x0,(char *)0x0);
  *(undefined1 *)(param_1 + 0x45251) = 0;
  *(code **)(param_1 + 0x12a04) = FUN_11806f04;
  *(undefined4 *)(param_1 + 0x12a08) = 0;
  return;
}


// FUNC 0x1180733c FUN_1180733c (Colosseum)
//   size 0x4c | file Colosseum+0x733c | callers(0) | datarefs 1

void FUN_1180733c(int param_1)

{
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x12f5c),2,0,(char *)0x0,(char *)0x0);
  *(undefined1 *)(param_1 + 0x45251) = 1;
  *(code **)(param_1 + 0x12a04) = FUN_11807928;
  *(undefined4 *)(param_1 + 0x12a08) = 0;
  return;
}


// FUNC 0x11807390 FUN_11807390 (Colosseum)
//   size 0x2bc | file Colosseum+0x7390 | callers(0) | datarefs 2

void FUN_11807390(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  BootInfo *this;
  int iVar5;
  MLyt *this_00;
  int iVar6;
  MDfxChr *pMVar7;
  float fVar8;
  
  if (*(char *)(param_1 + 0x61010) == '\0') {
    this = (BootInfo *)col::GetBootInfo();
    iVar5 = col::BootInfo::playBgm(this);
    if (iVar5 == 0) {
      return;
    }
  }
  this_00 = (MLyt *)(param_1 + 0x12f5c);
  iVar6 = msys::MLyt::isEnableAnime(this_00);
  iVar5 = msys::MComSys::_sys;
  if (iVar6 == 0) {
    if ((*(byte *)(param_1 + 0x6100a) & 1) != 0) {
      iVar6 = *(int *)(param_1 + 8);
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar6 = iVar5;
      }
      iVar5 = ad::fw::TaskBase::isFps30(*(TaskBase **)(iVar6 + 4));
      if (iVar5 == 0) {
        fVar8 = 1.0;
      }
      else {
        fVar8 = 2.0;
      }
      iVar5 = Frm::update(fVar8);
      if (iVar5 != 0) {
        return;
      }
    }
    Frm::play((Frm *)(param_1 + 0x60ffc),60.0);
    if (*(char *)(param_1 + 0x61010) == '\0') {
      msys::MLyt::playAnimeFromNo(this_00,0xc,1,(char *)0x0,(char *)0x0);
    }
    else {
      msys::MLyt::playAnimeFromNo(this_00,0xb,1,(char *)0x0,(char *)0x0);
      iVar6 = msys::MComSys::_sys;
      iVar5 = *(int *)(param_1 + 8);
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar5 = iVar6;
      }
      iVar1 = msys::MComSys::_sys;
      iVar6 = iVar5;
      if (iVar5 == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar6 = iVar1;
      }
      pMVar7 = (MDfxChr *)(param_1 + 0x36d54);
      msys::MDfxChr::init(pMVar7,*(MemAlcBase **)(*(int *)(param_1 + 4) + 0x18),
                          *(MDfxSys **)(iVar6 + 0xe64f0),(Scene *)(iVar5 + 0x4aaa0),0x400);
      msys::MDfxChr::playDfx(pMVar7,0x26);
      if ((((byte)nn::math::VEC3::Zero()::zero & 1) == 0) &&
         (iVar5 = __cxa_guard_acquire(&nn::math::VEC3::Zero()::zero), iVar5 != 0)) {
        nn::math::VEC3::Zero()::zero = 0;
        DAT_00434c4c = 0;
        DAT_00434c50 = 0;
        __cxa_guard_release(&nn::math::VEC3::Zero()::zero);
      }
      MoveVBase::stop((MoveVBase *)(param_1 + 0x36e20));
      uVar4 = DAT_00434c50;
      uVar3 = DAT_00434c4c;
      uVar2 = nn::math::VEC3::Zero()::zero;
      *(undefined4 *)(param_1 + 0x36e3c) = nn::math::VEC3::Zero()::zero;
      *(undefined4 *)(param_1 + 0x36e40) = uVar3;
      *(undefined4 *)(param_1 + 0x36e44) = uVar4;
      *(undefined4 *)(param_1 + 0x36e24) = uVar2;
      *(undefined4 *)(param_1 + 0x36e28) = uVar3;
      *(undefined4 *)(param_1 + 0x36e2c) = uVar4;
      msys::MLyt::attachMChr
                ((MLyt *)(param_1 + 0x12bb4),(MChrBase *)pMVar7,"INS_BG_EFFECT",(char *)0x0,
                 (char *)0x0,(char *)0x0);
      iVar6 = msys::MComSys::_sys;
      iVar5 = *(int *)(param_1 + 8);
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar5 = iVar6;
      }
      iVar1 = msys::MComSys::_sys;
      iVar6 = iVar5;
      if (iVar5 == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar6 = iVar1;
      }
      pMVar7 = (MDfxChr *)(param_1 + 0x36ed0);
      msys::MDfxChr::init(pMVar7,*(MemAlcBase **)(*(int *)(param_1 + 4) + 0x18),
                          *(MDfxSys **)(iVar6 + 0xe64f0),(Scene *)(iVar5 + 0x4aba4),0x401);
      msys::MDfxChr::playDfx(pMVar7,0x27);
      if ((((byte)nn::math::VEC3::Zero()::zero & 1) == 0) &&
         (iVar5 = __cxa_guard_acquire(&nn::math::VEC3::Zero()::zero), iVar5 != 0)) {
        nn::math::VEC3::Zero()::zero = 0;
        DAT_00434c4c = 0;
        DAT_00434c50 = 0;
        __cxa_guard_release(&nn::math::VEC3::Zero()::zero);
      }
      MoveVBase::stop((MoveVBase *)(param_1 + 0x36f9c));
      uVar4 = DAT_00434c50;
      uVar3 = DAT_00434c4c;
      uVar2 = nn::math::VEC3::Zero()::zero;
      *(undefined4 *)(param_1 + 0x36fb8) = nn::math::VEC3::Zero()::zero;
      *(undefined4 *)(param_1 + 0x36fbc) = uVar3;
      *(undefined4 *)(param_1 + 0x36fc0) = uVar4;
      *(undefined4 *)(param_1 + 0x36fa0) = uVar2;
      *(undefined4 *)(param_1 + 0x36fa4) = uVar3;
      *(undefined4 *)(param_1 + 0x36fa8) = uVar4;
      msys::MLyt::attachMChr
                (this_00,(MChrBase *)pMVar7,"INS_BG_EFFECT",(char *)0x0,(char *)0x0,(char *)0x0);
    }
    *(code **)(param_1 + 0x12a04) = FUN_118077c0;
    *(undefined4 *)(param_1 + 0x12a08) = 0;
  }
  return;
}


// FUNC 0x118076e0 FUN_118076e0 (Colosseum)
//   size 0xd8 | file Colosseum+0x76e0 | callers(0) | datarefs 2

void FUN_118076e0(int param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = msys::MLyt::isEnableAnime((MLyt *)(param_1 + 0x12f5c));
  if (iVar1 == 0) {
    iVar1 = 0;
    do {
      piVar2 = *(int **)(param_1 + iVar1 * 4 + 0x13340);
      (**(code **)(*piVar2 + 0x28))(piVar2,0);
      iVar1 = iVar1 + 1;
    } while (iVar1 < 7);
    (**(code **)(**(int **)(param_1 + 0x13348) + 0x28))(*(int **)(param_1 + 0x13348),1);
    (**(code **)(**(int **)(param_1 + 0x1334c) + 0x28))(*(int **)(param_1 + 0x1334c),1);
    *(undefined1 *)(param_1 + 0x1331c) = 2;
    msys::MCursorBase::setVisible((MCursorBase *)(param_1 + 0x13304),true);
    FUN_1180657c((MCursorBase *)(param_1 + 0x13304));
    *(undefined1 *)(param_1 + 0x3e0c5) = 0;
    FUN_118068b4(param_1,1);
    *(code **)(param_1 + 0x12a04) = FUN_11804a58;
    *(undefined4 *)(param_1 + 0x12a08) = 0;
    *(code **)(param_1 + 0x12a0c) = FUN_1180532c;
    *(undefined4 *)(param_1 + 0x12a10) = 0;
  }
  return;
}


// FUNC 0x118077c0 FUN_118077c0 (Colosseum)
//   size 0x148 | file Colosseum+0x77c0 | callers(0) | datarefs 2

void FUN_118077c0(int param_1)

{
  char cVar1;
  MLyt *this;
  int iVar2;
  int iVar3;
  code *pcVar4;
  bool bVar5;
  float fVar6;
  
  this = (MLyt *)(param_1 + 0x12f5c);
  iVar2 = msys::MLyt::isEnableAnime(this);
  iVar3 = msys::MComSys::_sys;
  if (iVar2 == 0) {
    if ((*(byte *)(param_1 + 0x6100a) & 1) != 0) {
      iVar2 = *(int *)(param_1 + 8);
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar2 = iVar3;
      }
      iVar3 = ad::fw::TaskBase::isFps30(*(TaskBase **)(iVar2 + 4));
      if (iVar3 == 0) {
        fVar6 = 1.0;
      }
      else {
        fVar6 = 2.0;
      }
      iVar3 = Frm::update(fVar6);
      if (iVar3 != 0) {
        return;
      }
    }
    bVar5 = *(char *)(param_1 + 0x61010) == '\0';
    cVar1 = '\0';
    if (!bVar5) {
      cVar1 = *(char *)(param_1 + 0x61011);
    }
    if (bVar5 || cVar1 == '\0') {
      msys::MLyt::playAnimeFromNo(this,0xd,1,(char *)0x0,(char *)0x0);
      pcVar4 = FUN_11808460;
    }
    else {
      iVar3 = col::GetBootInfo();
      if ((*(char *)(iVar3 + 0x20d) == '\f') || (*(char *)(param_1 + 0x61013) != '\0')) {
        msys::MLyt::playAnimeFromNo(this,10,1,(char *)0x0,(char *)0x0);
      }
      else {
        msys::MLyt::playAnimeFromNo(this,9,1,(char *)0x0,(char *)0x0);
      }
      Frm::play((Frm *)(param_1 + 0x60ffc),60.0);
      FUN_11806814(param_1,0x110023,0,0,0);
      pcVar4 = FUN_11808098;
    }
    *(code **)(param_1 + 0x12a04) = pcVar4;
    *(undefined4 *)(param_1 + 0x12a08) = 0;
  }
  return;
}


// FUNC 0x11807928 FUN_11807928 (Colosseum)
//   size 0x94 | file Colosseum+0x7928 | callers(0) | datarefs 4

void FUN_11807928(int param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = msys::MLyt::isEnableAnime((MLyt *)(param_1 + 0x12f5c));
  if (iVar1 == 0) {
    iVar1 = 0;
    do {
      piVar2 = *(int **)(param_1 + iVar1 * 4 + 0x13340);
      (**(code **)(*piVar2 + 0x28))(piVar2,0);
      iVar1 = iVar1 + 1;
    } while (iVar1 < 7);
    (**(code **)(**(int **)(param_1 + 0x1334c) + 0x28))(*(int **)(param_1 + 0x1334c),1);
    FUN_118068b4(param_1,1);
    *(code **)(param_1 + 0x12a0c) = FUN_118072ec;
    *(undefined4 *)(param_1 + 0x12a10) = 0;
    *(code **)(param_1 + 0x12a04) = FUN_118053a8;
    *(undefined4 *)(param_1 + 0x12a08) = 0;
  }
  return;
}


// FUNC 0x118079c4 FUN_118079c4 (Colosseum)
//   size 0xb4 | file Colosseum+0x79c4 | callers(0) | datarefs 2

void FUN_118079c4(int param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = msys::MLyt::isEnableAnime((MLyt *)(param_1 + 0x12f5c));
  if (iVar1 == 0) {
    iVar1 = 0;
    do {
      piVar2 = *(int **)(param_1 + iVar1 * 4 + 0x13340);
      (**(code **)(*piVar2 + 0x28))(piVar2,0);
      iVar1 = iVar1 + 1;
      if (6 < iVar1) break;
    } while (iVar1 != 5 && iVar1 != 6);
    (**(code **)(**(int **)(param_1 + 0x1334c) + 0x28))(*(int **)(param_1 + 0x1334c),1);
    *(undefined1 *)(param_1 + 0x45251) = 0;
    FUN_118068b4(param_1,1);
    *(code **)(param_1 + 0x12a0c) = FUN_1180733c;
    *(undefined4 *)(param_1 + 0x12a10) = 0;
    *(code **)(param_1 + 0x12a04) = FUN_11805498;
    *(undefined4 *)(param_1 + 0x12a08) = 0;
  }
  return;
}


// FUNC 0x11807a84 FUN_11807a84 (Colosseum)
//   size 0x120 | file Colosseum+0x7a84 | callers(0) | datarefs 2

void FUN_11807a84(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  MDfxChr *this;
  int iVar6;
  
  iVar5 = msys::MLyt::isBusyAnime((MLyt *)(param_1 + 0x12bb4));
  iVar6 = msys::MComSys::_sys;
  if (iVar5 == 0) {
    iVar5 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar5 = iVar6;
    }
    iVar1 = msys::MComSys::_sys;
    iVar6 = iVar5;
    if (iVar5 == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar6 = iVar1;
    }
    this = (MDfxChr *)(param_1 + 0x36a5c);
    msys::MDfxChr::init(this,*(MemAlcBase **)(*(int *)(param_1 + 4) + 0x18),
                        *(MDfxSys **)(iVar6 + 0xe64f0),(Scene *)(iVar5 + 0x4aaa0),0x400);
    msys::MDfxChr::playDfx(this,0x2c);
    if ((((byte)nn::math::VEC3::Zero()::zero & 1) == 0) &&
       (iVar6 = __cxa_guard_acquire(&nn::math::VEC3::Zero()::zero), iVar6 != 0)) {
      nn::math::VEC3::Zero()::zero = 0;
      DAT_00434c4c = 0;
      DAT_00434c50 = 0;
      __cxa_guard_release(&nn::math::VEC3::Zero()::zero);
    }
    MoveVBase::stop((MoveVBase *)(param_1 + 0x36b28));
    uVar4 = DAT_00434c50;
    uVar3 = DAT_00434c4c;
    uVar2 = nn::math::VEC3::Zero()::zero;
    *(undefined4 *)(param_1 + 0x36b44) = nn::math::VEC3::Zero()::zero;
    *(undefined4 *)(param_1 + 0x36b48) = uVar3;
    *(undefined4 *)(param_1 + 0x36b4c) = uVar4;
    *(undefined4 *)(param_1 + 0x36b2c) = uVar2;
    *(undefined4 *)(param_1 + 0x36b30) = uVar3;
    *(undefined4 *)(param_1 + 0x36b34) = uVar4;
    msys::MLyt::attachMChr
              ((MLyt *)(param_1 + 0x12bb4),(MChrBase *)this,"INS_COMPLETE_EFFECT",(char *)0x0,
               (char *)0x0,(char *)0x0);
    *(code **)(param_1 + 0x12a04) = FUN_11808010;
    *(undefined4 *)(param_1 + 0x12a08) = 0;
  }
  return;
}


// FUNC 0x11807bcc FUN_11807bcc (Colosseum)
//   size 0x194 | file Colosseum+0x7bcc | callers(0) | datarefs 2

void FUN_11807bcc(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  bool bVar5;
  float fVar6;
  undefined4 local_18;
  
  local_18 = param_4;
  iVar1 = msys::MLyt::getAnime((MLyt *)(param_1 + 0x12f5c),9);
  iVar3 = msys::MComSys::_sys;
  iVar2 = *(int *)(param_1 + 0x60ff4);
  bVar5 = iVar2 == 0;
  if (!bVar5) {
    bVar5 = *(float *)(iVar2 + 0xc) == 0.0;
  }
  if (!bVar5) {
    bVar5 = (*(byte *)(iVar2 + 0x12) & 1) == 0;
  }
  if (bVar5) {
    bVar5 = iVar1 == 0;
    if (!bVar5) {
      bVar5 = *(float *)(iVar1 + 0xc) == 0.0;
    }
    if (!bVar5) {
      bVar5 = (*(byte *)(iVar1 + 0x12) & 1) == 0;
    }
    if (bVar5) {
      if ((*(byte *)(param_1 + 0x6100a) & 1) != 0) {
        iVar1 = *(int *)(param_1 + 8);
        if (*(int *)(param_1 + 8) == 0) {
          *(int *)(param_1 + 8) = msys::MComSys::_sys;
          iVar1 = iVar3;
        }
        iVar3 = ad::fw::TaskBase::isFps30(*(TaskBase **)(iVar1 + 4));
        if (iVar3 == 0) {
          fVar6 = 1.0;
        }
        else {
          fVar6 = 2.0;
        }
        iVar3 = Frm::update(fVar6);
        if (iVar3 != 0) {
          return;
        }
      }
      uVar4 = 0;
      local_18 = CONCAT22(local_18._2_2_,*(undefined2 *)(param_1 + 0x61014));
      *(undefined1 *)(param_1 + 0x61014) = 1;
      do {
        if ((short)(&DAT_003f9de0)[uVar4] < 0) {
          *(undefined1 *)(param_1 + 0x61014) = 0;
          break;
        }
        uVar4 = uVar4 + 1 & 0xff;
      } while (uVar4 < 7);
      uVar4 = 0;
      *(undefined1 *)(param_1 + 0x61015) = 1;
      do {
        if ((short)(&DAT_003f9df4)[uVar4] < 0) {
          *(undefined1 *)(param_1 + 0x61015) = 0;
          break;
        }
        uVar4 = uVar4 + 1 & 0xff;
      } while (uVar4 < 4);
      msys::MDfxChr::term((MDfxChr *)(param_1 + 0x36bd8));
      if ((*(char *)((int)*(char *)(param_1 + 0x61013) + param_1 + 0x61014) != '\0') &&
         (*(char *)((int)&local_18 + (int)*(char *)(param_1 + 0x61013)) == '\0')) {
        *(code **)(param_1 + 0x12a04) = FUN_11807e7c;
        *(undefined4 *)(param_1 + 0x12a08) = 0;
        return;
      }
      *(code **)(param_1 + 0x12a04) = FUN_118042b8;
      *(undefined4 *)(param_1 + 0x12a08) = 0;
    }
  }
  return;
}


// FUNC 0x11807d88 FUN_11807d88 (Colosseum)
//   size 0xd0 | file Colosseum+0x7d88 | callers(0) | datarefs 1

void FUN_11807d88(int param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint in_fpscr;
  float fVar5;
  
  iVar2 = msys::MLyt::isBusyAnime((MLyt *)(param_1 + 0x12bb4));
  iVar3 = msys::MComSys::_sys;
  if (iVar2 == 0) {
    if ((*(byte *)(param_1 + 0x6100a) & 1) != 0) {
      iVar2 = *(int *)(param_1 + 8);
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar2 = iVar3;
      }
      iVar3 = ad::fw::TaskBase::isFps30(*(TaskBase **)(iVar2 + 4));
      if (iVar3 == 0) {
        fVar5 = 1.0;
      }
      else {
        fVar5 = 2.0;
      }
      iVar3 = Frm::update(fVar5);
      if (iVar3 != 0) {
        return;
      }
    }
    sVar1 = msys::MLyt::createAnimeAutoSlot
                      ((MLyt *)(param_1 + 0x12f5c),"TURN_ENEMY_IMG",(char *)0x0,(char *)0x0);
    iVar3 = msys::MLyt::getAnim((MLyt *)(param_1 + 0x12f5c),sVar1);
    uVar4 = ad::lyt::AnimTransform::GetFrameSize(*(AnimTransform **)(iVar3 + 0x14));
    fVar5 = (float)VectorUnsignedToFloat(uVar4,(byte)(in_fpscr >> 0x16) & 3);
    Frm::play((Frm *)(param_1 + 0x60ffc),fVar5);
    *(code **)(param_1 + 0x12a04) = FUN_11807edc;
    *(undefined4 *)(param_1 + 0x12a08) = 0;
  }
  return;
}


// FUNC 0x11807e7c FUN_11807e7c (Colosseum)
//   size 0x48 | file Colosseum+0x7e7c | callers(0) | datarefs 1

void FUN_11807e7c(int param_1)

{
  msys::MLyt::createAnimeAutoSlot((MLyt *)(param_1 + 0x12bb4),"COMPLETE_IN",(char *)0x0,(char *)0x0)
  ;
  Frm::play((Frm *)(param_1 + 0x60ffc),60.0);
  *(code **)(param_1 + 0x12a04) = FUN_11807a84;
  *(undefined4 *)(param_1 + 0x12a08) = 0;
  return;
}


// FUNC 0x11807edc FUN_11807edc (Colosseum)
//   size 0xb0 | file Colosseum+0x7edc | callers(0) | datarefs 2

void FUN_11807edc(int param_1)

{
  int iVar1;
  int iVar2;
  float fVar3;
  
  iVar2 = msys::MComSys::_sys;
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  else {
    iVar2 = *(int *)(param_1 + 8);
  }
  iVar2 = ad::fw::TaskBase::isFps30(*(TaskBase **)(iVar2 + 4));
  if (iVar2 == 0) {
    fVar3 = 1.0;
  }
  else {
    fVar3 = 2.0;
  }
  Frm::update(fVar3);
  iVar1 = msys::MComSys::_sys;
  iVar2 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar2 = iVar1;
  }
  *(float *)(iVar2 + 0x4ad68) =
       (*(float *)(param_1 + 0x60ffc) * -90.0) / *(float *)(param_1 + 0x61004);
  if (((*(byte *)(param_1 + 0x6100a) & 1) == 0) &&
     (iVar2 = msys::MLyt::isEnableAnime((MLyt *)(param_1 + 0x12bb4)), iVar2 == 0)) {
    *(code **)(param_1 + 0x12a04) = FUN_11807fac;
    *(undefined4 *)(param_1 + 0x12a08) = 0;
  }
  return;
}


// FUNC 0x11807fac FUN_11807fac (Colosseum)
//   size 0x48 | file Colosseum+0x7fac | callers(0) | datarefs 2

void FUN_11807fac(int param_1)

{
  msys::MLyt::createAnimeAutoSlot
            ((MLyt *)(param_1 + 0x12bb4),"TURN_ENEMY_NAME",(char *)0x0,(char *)0x0);
  Frm::play((Frm *)(param_1 + 0x60ffc),120.0);
  *(code **)(param_1 + 0x12a04) = FUN_11807118;
  *(undefined4 *)(param_1 + 0x12a08) = 0;
  return;
}


// FUNC 0x11808010 FUN_11808010 (Colosseum)
//   size 0x74 | file Colosseum+0x8010 | callers(0) | datarefs 2

void FUN_11808010(int param_1)

{
  int iVar1;
  int iVar2;
  float fVar3;
  
  iVar2 = msys::MComSys::_sys;
  if ((*(byte *)(param_1 + 0x6100a) & 1) != 0) {
    iVar1 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar1 = iVar2;
    }
    iVar2 = ad::fw::TaskBase::isFps30(*(TaskBase **)(iVar1 + 4));
    if (iVar2 == 0) {
      fVar3 = 1.0;
    }
    else {
      fVar3 = 2.0;
    }
    iVar2 = Frm::update(fVar3);
    if (iVar2 != 0) {
      return;
    }
  }
  *(code **)(param_1 + 0x12a04) = FUN_118042b8;
  *(undefined4 *)(param_1 + 0x12a08) = 0;
  return;
}


// FUNC 0x11808098 FUN_11808098 (Colosseum)
//   size 0x9c | file Colosseum+0x8098 | callers(0) | datarefs 2

void FUN_11808098(int param_1)

{
  int iVar1;
  MDfxChr *this;
  
  iVar1 = msys::MLyt::isBusyAnime((MLyt *)(param_1 + 0x12f5c));
  if (iVar1 == 0) {
    this = (MDfxChr *)(param_1 + 0x36bd8);
    if (*(char *)(param_1 + 0x61013) == '\0') {
      iVar1 = col::GetBootInfo();
      if (*(char *)(iVar1 + 0x20d) == '\f') {
        msys::MDfxChr::playDfx(this,0x2a);
      }
      else {
        msys::MDfxChr::playDfx(this,0x28);
      }
    }
    else {
      msys::MDfxChr::playDfx(this,0x2d);
    }
    *(code **)(param_1 + 0x12a04) = FUN_118083b8;
    *(undefined4 *)(param_1 + 0x12a08) = 0;
  }
  return;
}


// FUNC 0x1180813c FUN_1180813c (Colosseum)
//   size 0x194 | file Colosseum+0x813c | callers(0) | datarefs 2

void FUN_1180813c(int param_1,uint *param_2)

{
  MLyt *this;
  int iVar1;
  code *pcVar2;
  
  FUN_11806144();
  if ((*param_2 & 0xc03) == 0) {
    return;
  }
  FUN_118068b4(param_1,0);
  this = (MLyt *)(param_1 + 0x12f5c);
  msys::MLyt::playAnimeFromNo(this,0xd,0,(char *)0x0,(char *)0x0);
  FUN_11806814(param_1,0x110016,0,0,0);
  FUN_118068b4(param_1,0);
  if (*(char *)(param_1 + 0x61011) == '\0') {
    if (*(char *)(param_1 + 0x61012) != '\0') {
      msys::MLyt::playAnimeFromNo(this,0xb,0,(char *)0x0,(char *)0x0);
      *(code **)(param_1 + 0x12a04) = FUN_118042b8;
      *(undefined4 *)(param_1 + 0x12a08) = 0;
      return;
    }
    if (*(char *)(param_1 + 0x61010) != '\0') {
      msys::MLyt::playAnimeFromNo(this,0xb,0,(char *)0x0,(char *)0x0);
    }
    pcVar2 = FUN_11804d04;
  }
  else {
    iVar1 = col::GetBootInfo();
    if ((*(char *)(iVar1 + 0x20d) == '\f') || (*(char *)(param_1 + 0x61013) != '\0')) {
      msys::MLyt::playAnimeFromNo(this,10,0,(char *)0x0,(char *)0x0);
    }
    else {
      msys::MLyt::playAnimeFromNo(this,9,0,(char *)0x0,(char *)0x0);
    }
    msys::MLyt::playAnimeFromNo(this,0xb,0,(char *)0x0,(char *)0x0);
    *(ushort *)(*(int *)(param_1 + 0x60ff4) + 0x12) =
         *(ushort *)(*(int *)(param_1 + 0x60ff4) + 0x12) & 0xfffd;
    Frm::play((Frm *)(param_1 + 0x60ffc),60.0);
    pcVar2 = FUN_11807bcc;
  }
  *(code **)(param_1 + 0x12a04) = pcVar2;
  *(undefined4 *)(param_1 + 0x12a08) = 0;
  return;
}


// FUNC 0x118082f0 FUN_118082f0 (Colosseum)
//   size 0xb0 | file Colosseum+0x82f0 | callers(0) | datarefs 1

void FUN_118082f0(int param_1)

{
  char cVar1;
  char *__dest;
  Encount *pEVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  char *__src;
  float fVar6;
  
  iVar3 = msys::MLyt::isBusyAnime((MLyt *)(param_1 + 0x12f5c));
  iVar4 = msys::MComSys::_sys;
  if (iVar3 != 0) {
    return;
  }
  if ((*(byte *)(param_1 + 0x6100a) & 1) != 0) {
    iVar3 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar3 = iVar4;
    }
    iVar4 = ad::fw::TaskBase::isFps30(*(TaskBase **)(iVar3 + 4));
    if (iVar4 == 0) {
      fVar6 = 1.0;
    }
    else {
      fVar6 = 2.0;
    }
    iVar4 = Frm::update(fVar6);
    if (iVar4 != 0) {
      return;
    }
  }
  iVar4 = col::GetBootInfo();
  iVar3 = btl::GetBootInfo();
  cVar1 = *(char *)(iVar3 + 0x129);
  __src = (char *)(&DAT_1180c1c0)[*(char *)(iVar4 + 0x20d) * 7];
  __dest = (char *)btl::GetBootInfo();
  *__dest = '\0';
  __dest[0x30] = '\0';
  __dest[0x60] = '\0';
  __dest[0x90] = '\0';
  __dest[0xc0] = '\0';
  __dest[0xc1] = '\0';
  __dest[0xc2] = '\0';
  __dest[0xc3] = '\0';
  __dest[0xc4] = '\0';
  __dest[0xc5] = '\0';
  __dest[0xc6] = '\0';
  __dest[199] = '\0';
  __dest[200] = '\x03';
  __dest[0xc9] = '\0';
  __dest[0xca] = '\0';
  __dest[0xcb] = '\0';
  __dest[0xcc] = '\0';
  __dest[0xcd] = '\0';
  __dest[0xce] = '\x01';
  __dest[0xcf] = '\x01';
  pcVar5 = __dest + 0x100;
  iVar4 = 4;
  __dest[0xd0] = '\0';
  do {
    iVar4 = iVar4 + -1;
    pcVar5[0] = '\0';
    pcVar5[1] = '\0';
    pcVar5[2] = '\0';
    pcVar5[3] = '\0';
    pcVar5 = pcVar5 + 4;
  } while (iVar4 != 0);
  pcVar5 = __dest + 0x114;
  iVar4 = 2;
  __dest[0x110] = '\0';
  do {
    iVar4 = iVar4 + -1;
    pcVar5[0] = '\0';
    pcVar5[1] = '\0';
    pcVar5[2] = '\0';
    pcVar5[3] = '\0';
    pcVar5 = pcVar5 + 4;
  } while (iVar4 != 0);
  __dest[0x11c] = '\0';
  __dest[0x11d] = '\0';
  __dest[0x11e] = 'd';
  __dest[0x11f] = '\0';
  __dest[0x120] = 'd';
  __dest[0x121] = '\0';
  __dest[0x122] = '\x01';
  __dest[0x124] = '\0';
  __dest[0x125] = '\0';
  __dest[0x126] = '\0';
  __dest[0x127] = '\0';
  __dest[0x128] = '\0';
  __dest[0x129] = '\0';
  strcpy(__dest,__src);
  strcpy(__dest + 0x30,"bmp_i_none_01");
  __dest[0xc0] = 'V';
  __dest[0xc1] = '\x03';
  __dest[0xc2] = '\0';
  __dest[0xc3] = '\x01';
  __dest[200] = '\x03';
  __dest[0xc9] = '\0';
  __dest[0xca] = '\0';
  __dest[0xcb] = '\0';
  __dest[0xcc] = '\x01';
  __dest[0xce] = '\x02';
  __dest[0x128] = '\x01';
  __dest[0x129] = cVar1;
  __dest[0x110] = '\0';
  __dest[0x11e] = '\0';
  __dest[0x11f] = '\0';
  __dest[0x120] = '\0';
  __dest[0x121] = '\0';
  __dest[0x122] = '\0';
  pEVar2 = (Encount *)ad::Encount::GetInst();
  ad::Encount::startLoadRes(pEVar2,__dest[0xc9],__dest[200],__dest[0xcb],__dest[0xce],3);
  SndSys::stopAllBgm((SndSys *)&gSndSys,0x10);
  iVar4 = msys::MComSys::_sys;
  iVar3 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar3 = iVar4;
  }
  GameMain::Change(10,*(undefined4 *)(iVar3 + 4));
  return;
}


// FUNC 0x118083b8 FUN_118083b8 (Colosseum)
//   size 0x94 | file Colosseum+0x83b8 | callers(0) | datarefs 2

void FUN_118083b8(int param_1)

{
  int iVar1;
  int iVar2;
  float fVar3;
  
  iVar2 = msys::MComSys::_sys;
  if ((*(byte *)(param_1 + 0x6100a) & 1) != 0) {
    iVar1 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar1 = iVar2;
    }
    iVar2 = ad::fw::TaskBase::isFps30(*(TaskBase **)(iVar1 + 4));
    if (iVar2 == 0) {
      fVar3 = 1.0;
    }
    else {
      fVar3 = 2.0;
    }
    iVar2 = Frm::update(fVar3);
    if (iVar2 != 0) {
      return;
    }
  }
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x12f5c),0xd,1,(char *)0x0,(char *)0x0);
  *(code **)(param_1 + 0x12a04) = FUN_11808460;
  *(undefined4 *)(param_1 + 0x12a08) = 0;
  return;
}


// FUNC 0x11808460 FUN_11808460 (Colosseum)
//   size 0x64 | file Colosseum+0x8460 | callers(0) | datarefs 4

void FUN_11808460(int param_1)

{
  bool bVar1;
  uint uVar2;
  
  FUN_11806144();
  uVar2 = msys::MLyt::getAnime((MLyt *)(param_1 + 0x12f5c),0xd);
  if (uVar2 != 0) {
    bVar1 = *(float *)(uVar2 + 0xc) != 0.0;
    if (bVar1) {
      uVar2 = (uint)*(byte *)(uVar2 + 0x12);
    }
    if (bVar1 && (uVar2 & 1) != 0) {
      return;
    }
  }
  FUN_118068b4(param_1,1);
  *(code **)(param_1 + 0x12a04) = FUN_1180813c;
  *(undefined4 *)(param_1 + 0x12a08) = 0;
  return;
}


// FUNC 0x118084cc col::ColosseumPage::Core::MsgWnd::vfunc_0x4 (Colosseum)
//   size 0x30 | file Colosseum+0x84cc | callers(0) | datarefs 1

void col::ColosseumPage::Core::MsgWnd::vfunc_0x4(undefined4 *param_1)

{
  int iVar1;
  void *pvVar2;
  
  *param_1 = &msys::MMsgWnd::vtable;
  Message::term((Message *)(param_1 + 0x53));
  iVar1 = Message::~Message((Message *)(param_1 + 0x53));
  pvVar2 = (void *)msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  operator_delete(pvVar2);
  return;
}


// FUNC 0x11808500 col::ColosseumPage::Core::MsgWnd::vfunc_0x0 (Colosseum)
//   size 0x2c | file Colosseum+0x8500 | callers(0) | datarefs 1

void col::ColosseumPage::Core::MsgWnd::vfunc_0x0(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &msys::MMsgWnd::vtable;
  Message::term((Message *)(param_1 + 0x53));
  iVar1 = Message::~Message((Message *)(param_1 + 0x53));
  msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  return;
}


// FUNC 0x11808530 col::ColosseumPage::Core::ListWnd::vfunc_0x10 (Colosseum)
//   size 0x1c | file Colosseum+0x8530 | callers(0) | datarefs 1

void col::ColosseumPage::Core::ListWnd::vfunc_0x10(MListWndPBase *param_1)

{
  msys::MListWndPBase::applyAnime(param_1);
  ad::lyt::Layout::Animate((Layout *)(param_1 + 0x7064));
  return;
}


// FUNC 0x1180854c FUN_1180854c (Colosseum)
//   size 0x2ec | file Colosseum+0x854c | callers(1) 0x118012ec

void FUN_1180854c(MListWndPBase *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  LytAnim *this;
  LytAnim *this_00;
  undefined4 uVar4;
  Layout *pLVar5;
  Layout *pLVar6;
  code *pcVar7;
  uint in_fpscr;
  float fVar8;
  LytAnim local_1c8 [4];
  undefined4 local_1c4;
  undefined4 uStack_1c0;
  undefined4 local_1bc;
  undefined2 local_1b8;
  undefined2 local_1b6;
  AnimTransform *local_1b4;
  undefined4 local_1b0;
  LytAnim *local_1ac;
  int local_1a8 [8];
  undefined4 local_188;
  undefined4 local_17c;
  undefined4 local_178;
  undefined4 local_170;
  LytAnim *local_158;
  LytAnim *local_154;
  LytAnim *pLStack_150;
  LytAnim *local_14c;
  LytAnim *local_148;
  undefined1 local_140;
  MListWndPBase *local_6c;
  undefined1 local_68;
  LytAnim *local_30;
  
  *(int *)(param_1 + 0x7060) = param_2;
  iVar2 = msys::MComSys::_sys;
  iVar3 = *(int *)(param_2 + 8);
  if (*(int *)(param_2 + 8) == 0) {
    *(int *)(param_2 + 8) = msys::MComSys::_sys;
    iVar3 = iVar2;
  }
  pLVar5 = (Layout *)(param_1 + 0x7064);
  cVar1 = *(char *)(param_2 + 0x61013);
  ad::lyt::LytResourceMan::buildLayout
            ((LytResourceMan *)(param_2 + 0x12a30),pLVar5,"MINIGAME_L_LIST.bflyt",
             (ControlCreator *)0x0,(TextSearcher *)0x0);
  local_1ac = (LytAnim *)(param_1 + 0x70dc);
  ad::lyt::LytAnim::init(local_1ac,pLVar5,"touch","");
  local_30 = (LytAnim *)(param_1 + 0x714c);
  ad::lyt::LytAnim::init(local_30,pLVar5,"ATTENTION","");
  ad::lyt::LytAnim::playAuto(local_30,1.0);
  pLVar6 = (Layout *)(param_1 + 0x70a0);
  ad::lyt::LytResourceMan::buildLayout
            ((LytResourceMan *)(iVar3 + 2000),pLVar6,"NUM_G_s.bflyt",(ControlCreator *)0x0,
             (TextSearcher *)0x0);
  this = (LytAnim *)(param_1 + 0x70f8);
  ad::lyt::LytAnim::init(this,pLVar6,"num_set_U","");
  this_00 = (LytAnim *)(param_1 + 0x7114);
  ad::lyt::LytAnim::init(this_00,pLVar6,"col_s06","");
  ad::lyt::LytAnim::init((LytAnim *)(param_1 + 0x7130),pLVar6,"col_02","");
  ad::ui::UIListWindowPlusLyt::InitParam::InitParam((InitParam *)local_1a8);
  msys::SetMListWndInitParam(local_1a8,2);
  local_1a8[0] = iVar3 + 0x4af6c;
  pcVar7 = *(code **)(**(int **)(param_1 + 0x7074) + 0x2c);
  local_170 = (*pcVar7)(*(int **)(param_1 + 0x7074),"FRAME",1,pcVar7,this_00);
  local_178 = (**(code **)(**(int **)(param_1 + 0x7074) + 0x2c))
                        (*(int **)(param_1 + 0x7074),"list_cursor_Coliseum",1);
  local_17c = (**(code **)(**(int **)(param_1 + 0x7074) + 0x2c))
                        (*(int **)(param_1 + 0x7074),"list_scroll",1);
  local_140 = 0;
  local_148 = local_30;
  local_6c = param_1 + 0x6f80;
  local_14c = local_1ac;
  local_188 = *(undefined4 *)(param_1 + 0x70b0);
  if (cVar1 == '\0') {
    local_68 = 7;
  }
  else {
    local_68 = 4;
  }
  local_1c8[0] = (LytAnim)0x0;
  local_1c4 = 0;
  uStack_1c0 = 0x3f800000;
  local_1bc = 0;
  local_1b8 = 1;
  local_1b6 = 0;
  local_1b4 = (AnimTransform *)0x0;
  local_1b0 = 0;
  local_158 = this;
  local_154 = this_00;
  pLStack_150 = (LytAnim *)(param_1 + 0x7130);
  ad::lyt::LytAnim::init(local_1c8,pLVar5,"SET_LIST_COL","");
  ad::lyt::LytAnim::stopAndSetFrm(local_1c8,3.0);
  ad::lyt::LytAnim::term(local_1c8,true);
  ad::lyt::LytAnim::init(local_1c8,pLVar5,"ICON_offon","");
  ad::lyt::LytAnim::stopAndSetFrm(local_1c8,0.0);
  ad::lyt::LytAnim::term(local_1c8,true);
  ad::lyt::LytAnim::init(local_1c8,pLVar5,"SET_CURSOR_HIL","");
  uVar4 = ad::lyt::AnimTransform::GetFrameSize(local_1b4);
  fVar8 = (float)VectorUnsignedToFloat(uVar4,(byte)(in_fpscr >> 0x16) & 3);
  ad::lyt::LytAnim::stopAndSetFrm(local_1c8,fVar8);
  ad::lyt::LytAnim::term(local_1c8,true);
  local_1bc = 0;
  msys::MListWndPBase::init
            (param_1,(InitParam *)local_1a8,(LytDrawData *)(iVar3 + 0xd3000),
             (Prim *)(iVar3 + 0xd3100),(MessageDrawer *)(iVar3 + 0x1487c),
             (ApplyingSceneInfo *)(iVar3 + 0x4af54));
  *(undefined4 *)(param_1 + 0x13c) = 0x401;
  *(undefined4 *)(param_1 + 0x168) = 0x401;
  return;
}


// FUNC 0x11808908 col::ColosseumPage::Core::ListWnd::vfunc_0x4 (Colosseum)
//   size 0x90 | file Colosseum+0x8908 | callers(0) | datarefs 1

void col::ColosseumPage::Core::ListWnd::vfunc_0x4(undefined4 *param_1)

{
  int iVar1;
  void *pvVar2;
  
  *param_1 = &vtable;
  param_1[0x1c5d] = 0;
  param_1[0x1c56] = 0;
  param_1[0x1c4f] = 0;
  param_1[0x1c48] = 0;
  param_1[0x1c41] = 0;
  param_1[0x1c3a] = 0;
  iVar1 = ad::lyt::Layout::~Layout((Layout *)(param_1 + 0x1c28));
  iVar1 = ad::lyt::Layout::~Layout((Layout *)(iVar1 + -0x3c));
  *(undefined ***)(iVar1 + -0x7064) = &vtable_for_N4msys9MListWndPILi8EEE;
  iVar1 = ad::ui::UIListWindowPlusLyt::~UIListWindowPlusLyt
                    ((UIListWindowPlusLyt *)(iVar1 + -0x6e68));
  pvVar2 = (void *)msys::MListWndPBase::~MListWndPBase((MListWndPBase *)(iVar1 + -0x1fc));
  operator_delete(pvVar2);
  return;
}


// FUNC 0x118089a4 col::ColosseumPage::Core::ListWnd::vfunc_0x0 (Colosseum)
//   size 0x8c | file Colosseum+0x89a4 | callers(0) | datarefs 1

void col::ColosseumPage::Core::ListWnd::vfunc_0x0(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &vtable;
  param_1[0x1c5d] = 0;
  param_1[0x1c56] = 0;
  param_1[0x1c4f] = 0;
  param_1[0x1c48] = 0;
  param_1[0x1c41] = 0;
  param_1[0x1c3a] = 0;
  iVar1 = ad::lyt::Layout::~Layout((Layout *)(param_1 + 0x1c28));
  iVar1 = ad::lyt::Layout::~Layout((Layout *)(iVar1 + -0x3c));
  *(undefined ***)(iVar1 + -0x7064) = &vtable_for_N4msys9MListWndPILi8EEE;
  iVar1 = ad::ui::UIListWindowPlusLyt::~UIListWindowPlusLyt
                    ((UIListWindowPlusLyt *)(iVar1 + -0x6e68));
  msys::MListWndPBase::~MListWndPBase((MListWndPBase *)(iVar1 + -0x1fc));
  return;
}


// FUNC 0x11808a48 FUN_11808a48 (Colosseum)
//   size 0x278 | file Colosseum+0x8a48 | callers(0)

void FUN_11808a48(int param_1,int param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  uint in_fpscr;
  float fVar6;
  
  bVar1 = *(byte *)(param_2 + 0x48);
  uVar3 = (uint)bVar1;
  if (param_3 != 1) {
    if (param_3 != 4) {
      if (param_3 != 5) {
        return;
      }
      msys::MCursorBase::setVisible((MCursorBase *)(param_1 + 0x13304),false);
      switch(uVar3) {
      case 0:
        *(bool *)(param_1 + 0x61013) = *(char *)(param_1 + 0x1331c) == '\x01';
        *(code **)(param_1 + 0x12a04) = FUN_1180406c;
        *(undefined4 *)(param_1 + 0x12a08) = 0;
        return;
      case 1:
        *(bool *)(param_1 + 0x61013) = *(char *)(param_1 + 0x1331c) == '\x01';
        *(code **)(param_1 + 0x12a04) = FUN_1180406c;
        *(undefined4 *)(param_1 + 0x12a08) = 0;
        return;
      case 2:
        *(code **)(param_1 + 0x12a04) = FUN_1180485c;
        *(undefined4 *)(param_1 + 0x12a08) = 0;
        return;
      case 3:
        *(undefined4 *)(param_1 + 0x12a04) = *(undefined4 *)(param_1 + 0x12a0c);
        *(undefined4 *)(param_1 + 0x12a08) = *(undefined4 *)(param_1 + 0x12a10);
        return;
      case 4:
        *(code **)(param_1 + 0x12a04) = FUN_11806e00;
        *(undefined4 *)(param_1 + 0x12a08) = 0;
        return;
      case 5:
      case 6:
        goto switchD_11808aa0_caseD_5;
      default:
        return;
      }
    }
    if (uVar3 == 3) {
      FUN_11806814(param_1,0x110017,0,0,0);
    }
    else if (uVar3 == 4) {
      FUN_11806814(param_1,0x110016,0,0,0);
      *(bool *)(param_1 + 0x61013) = *(char *)(param_1 + 0x1331c) != '\0';
    }
    else if (uVar3 == 5 || uVar3 == 6) {
      FUN_11806814(param_1,0x11001c,0,0,0);
    }
    else {
      FUN_11806814(param_1,0x110016,0,0,0);
    }
    FUN_118068b4(param_1,0);
  }
  if (((int)*(char *)(param_1 + 0x1331c) == uVar3) || (1 < uVar3)) {
    return;
  }
  FUN_11806814(param_1,0x110015,0,0,0);
  *(byte *)(param_1 + 0x1331c) = bVar1;
  fVar6 = (float)VectorUnsignedToFloat((uint)(uVar3 == 1),(byte)(in_fpscr >> 0x16) & 3);
  ad::lyt::LytAnim::stopAndSetFrm((LytAnim *)(param_1 + 0x60fb8),fVar6);
  fVar6 = (float)VectorUnsignedToFloat((uint)(uVar3 == 1),(byte)(in_fpscr >> 0x16) & 3);
  ad::lyt::LytAnim::stopAndSetFrm((LytAnim *)(param_1 + 0x60fd4),fVar6);
  fVar6 = (float)VectorSignedToFloat((int)*(char *)((uint)(*(char *)(param_1 + 0x1331c) == '\x01') +
                                                    param_1 + 0x61014),(byte)(in_fpscr >> 0x16) & 3)
  ;
  ad::lyt::LytAnim::stopAndSetFrm((LytAnim *)(param_1 + 0x60f9c),fVar6);
  return;
switchD_11808aa0_caseD_5:
  if (*(int *)(param_1 + 0x13354) == param_2) {
    uVar5 = 0xffffffff;
  }
  else {
    uVar5 = 1;
  }
  FUN_118023e8(param_1 + 0x60b04,uVar5);
  iVar2 = msys::MComSys::_sys;
  iVar4 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar4 = iVar2;
  }
  *(undefined1 *)(iVar4 + 0xe6508) = 1;
  return;
}


// FUNC 0x11808d0c FUN_11808d0c (Colosseum)
//   size 0x324 | file Colosseum+0x8d0c | callers(0) | datarefs 1

void FUN_11808d0c(int param_1)

{
  int iVar1;
  IAllocator *pIVar2;
  int iVar3;
  char *pcVar4;
  uint *puVar5;
  undefined4 uVar6;
  FileContext *pFVar7;
  MemAlcBase *pMVar8;
  char acStackY_118 [128];
  uint *in_stack_ffffff70;
  TransMultiSymbol aTStack_70 [4];
  undefined4 local_6c;
  Resource *local_68;
  TaskBase *local_64;
  TransMultiSymbol aTStack_60 [32];
  Resource *local_40;
  TaskBase *local_3c;
  undefined4 local_38;
  
  iVar1 = ad::lyt::LytDrawSys::GetInst();
  uVar6 = *(undefined4 *)(*(int *)(param_1 + 4) + 0x18);
  pIVar2 = (IAllocator *)(iVar1 + 0x5f4);
  if (ad::lyt::Layout::s_pAllocator != pIVar2) {
    ad::lyt::Initialize(pIVar2,pIVar2);
  }
  *(undefined4 *)(iVar1 + 0x5f8) = uVar6;
  iVar1 = ad::lyt::LytDrawSys::GetInst();
  *(undefined4 *)(iVar1 + 0x5fc) = 0x10000;
  iVar3 = msys::MComSys::_sys;
  iVar1 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar1 = iVar3;
  }
  iVar3 = msys::MComSys::_sys;
  local_64 = *(TaskBase **)(iVar1 + 4);
  local_68 = (Resource *)(param_1 + 0x12ae8);
  if (iVar1 == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  else {
    iVar3 = *(int *)(param_1 + 8);
  }
  pFVar7 = *(FileContext **)(iVar3 + 0x278);
  pMVar8 = *(MemAlcBase **)(*(int *)(param_1 + 4) + 0x18);
  local_6c = *(undefined4 *)(pFVar7 + 0x24);
  ad::TransMultiSymbol::init(aTStack_60,"m_item_bra");
  BinGlu4Acs::getEntryAcs(acStackY_118 + 0x88);
  pcVar4 = (char *)((*in_stack_ffffff70 & 0x3fffffff) + *(int *)(pFVar7 + 0x24));
  puVar5 = (uint *)(pcVar4 + 8);
  ad::fw::TaskBase::readCA
            (local_64,local_68,pFVar7,"m_item_bra",pcVar4,pcVar4 + 4,(char *)puVar5,pcVar4 + 0xc,
             pMVar8,0x7f,(VramAlcBase *)0x0,0,(ResCacheArg *)0x0);
  iVar3 = msys::MComSys::_sys;
  iVar1 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar1 = iVar3;
  }
  iVar3 = msys::MComSys::_sys;
  local_3c = *(TaskBase **)(iVar1 + 4);
  local_40 = (Resource *)(param_1 + 0x12b2c);
  if (iVar1 == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  else {
    iVar3 = *(int *)(param_1 + 8);
  }
  pFVar7 = *(FileContext **)(iVar3 + 0x278);
  pMVar8 = *(MemAlcBase **)(*(int *)(param_1 + 4) + 0x18);
  local_38 = *(undefined4 *)(pFVar7 + 0x24);
  ad::TransMultiSymbol::init(aTStack_70,"m_bodyrot_icon");
  BinGlu4Acs::getEntryAcs(acStackY_118 + 0x88);
  pcVar4 = (char *)((*puVar5 & 0x3fffffff) + *(int *)(pFVar7 + 0x24));
  puVar5 = (uint *)(pcVar4 + 8);
  ad::fw::TaskBase::readCA
            (local_3c,local_40,pFVar7,"m_bodyrot_icon",pcVar4,pcVar4 + 4,(char *)puVar5,pcVar4 + 0xc
             ,pMVar8,0x7f,(VramAlcBase *)0x0,0,(ResCacheArg *)0x0);
  iVar3 = msys::MComSys::_sys;
  iVar1 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar1 = iVar3;
  }
  iVar3 = msys::MComSys::_sys;
  local_3c = *(TaskBase **)(iVar1 + 4);
  local_40 = (Resource *)(param_1 + 0x12b70);
  if (iVar1 == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  else {
    iVar3 = *(int *)(param_1 + 8);
  }
  pFVar7 = *(FileContext **)(iVar3 + 0x278);
  pMVar8 = *(MemAlcBase **)(*(int *)(param_1 + 4) + 0x18);
  local_38 = *(undefined4 *)(pFVar7 + 0x24);
  ad::TransMultiSymbol::init((TransMultiSymbol *)&local_6c,"?m_bodyrot");
  BinGlu4Acs::getEntryAcs(acStackY_118 + 0x88);
  pcVar4 = (char *)((*puVar5 & 0x3fffffff) + *(int *)(pFVar7 + 0x24));
  ad::fw::TaskBase::readCA
            (local_3c,local_40,pFVar7,"?m_bodyrot",pcVar4,pcVar4 + 4,pcVar4 + 8,pcVar4 + 0xc,pMVar8,
             0x7f,(VramAlcBase *)0x0,0,(ResCacheArg *)0x0);
  iVar3 = msys::MComSys::_sys;
  pMVar8 = *(MemAlcBase **)(*(int *)(param_1 + 4) + 0x18);
  iVar1 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar1 = iVar3;
  }
  iVar3 = msys::MComSys::_sys;
  if (iVar1 == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  else {
    iVar3 = iVar1;
  }
  ad::fw::TaskBase::readLyt
            (*(TaskBase **)(iVar3 + 4),(Resource *)(param_1 + 0x12aa4),
             (FileContext *)(*(int *)(iVar1 + 0x278) + 0xa8),"?COLISEUM",pMVar8,0x7f,
             (ResCacheArg *)0x0);
  *(undefined **)(param_1 + 0x129fc) = &DAT_11802670;
  *(undefined4 *)(param_1 + 0x12a00) = 0;
  return;
}


// FUNC 0x11809074 FUN_11809074 (Colosseum)
//   size 0x6f8 | file Colosseum+0x9074 | callers(1) 0x11809ce8

int FUN_11809074(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  
  *param_1 = &col::ColosseumPage::Core::vtable;
  param_1[1] = param_2;
  param_1[2] = 0;
  iVar1 = Backup::Backup((Backup *)(param_1 + 4));
  iVar1 = ad::ctrl::ButtonGroup::ButtonGroup((ButtonGroup *)(iVar1 + 0x12a04));
  *(undefined4 *)(iVar1 + 0x1c) = 0;
  iVar1 = ad::font::ResFont::ResFont((ResFont *)(iVar1 + 0x20));
  ad::lyt::LytResourceMan::init((LytResourceMan *)(iVar1 + -4));
  iVar1 = ad::fw::Resource::Resource((Resource *)(iVar1 + 0x70));
  iVar1 = ad::fw::Resource::Resource((Resource *)(iVar1 + 0x44));
  iVar1 = __aeabi_vec_ctor_nocookie_nodtor(iVar1 + 0x44,ad::fw::Resource::Resource,0x44,2);
  puVar2 = (undefined4 *)FUN_118058e4(iVar1 + 0x88);
  *puVar2 = &msys::MLyt::vtable;
  *(undefined1 *)(puVar2 + 0x53) = 0xff;
  *(undefined2 *)((int)puVar2 + 0x14e) = 0;
  puVar2[0x54] = 0;
  iVar1 = __aeabi_vec_ctor_nocookie_nodtor(puVar2 + 0x55,FUN_1180588c,0x1c,0xc);
  iVar1 = __aeabi_vec_ctor_nocookie_nodtor(iVar1 + 0x15c,&LAB_118012ac,0x10,0xc);
  *(undefined4 *)(iVar1 + 0xc0) = 0;
  *(undefined1 *)(iVar1 + 0xc4) = 1;
  *(undefined4 *)(iVar1 + 200) = 0;
  *(undefined4 *)(iVar1 + 0xcc) = 0;
  *(undefined1 *)(iVar1 + 0xd0) = 0;
  *(undefined4 *)(iVar1 + 0xd4) = 0;
  *(undefined4 *)(iVar1 + 0xd8) = 0;
  FUN_118058c8(iVar1 + -0xc,0xffffffff);
  puVar2 = (undefined4 *)FUN_118058e4(iVar1 + 0xf8);
  *puVar2 = &msys::MLyt::vtable;
  *(undefined1 *)(puVar2 + 0x53) = 0xff;
  *(undefined2 *)((int)puVar2 + 0x14e) = 0;
  puVar2[0x54] = 0;
  iVar1 = __aeabi_vec_ctor_nocookie_nodtor(puVar2 + 0x55,FUN_1180588c,0x1c,0xc);
  iVar1 = __aeabi_vec_ctor_nocookie_nodtor(iVar1 + 0x15c,&LAB_118012ac,0x10,0xc);
  *(undefined4 *)(iVar1 + 0xc0) = 0;
  *(undefined1 *)(iVar1 + 0xc4) = 1;
  *(undefined4 *)(iVar1 + 200) = 0;
  *(undefined4 *)(iVar1 + 0xcc) = 0;
  *(undefined1 *)(iVar1 + 0xd0) = 0;
  *(undefined4 *)(iVar1 + 0xd4) = 0;
  *(undefined4 *)(iVar1 + 0xd8) = 0;
  FUN_118058c8(iVar1 + -0xc,0xffffffff);
  puVar2 = (undefined4 *)msys::MCursorBase::MCursorBase((MCursorBase *)(iVar1 + 0xf8));
  *puVar2 = &vtable_for_N4msys7MCursorILj3EEE;
  puVar2[0xc] = 0;
  puVar2[0xd] = 0;
  puVar2[0xe] = 0;
  iVar1 = __aeabi_vec_ctor_nocookie_nodtor(puVar2 + 0x16,FUN_1180b57c,0x27c,2);
  puVar2 = (undefined4 *)FUN_118058e4(iVar1 + 0x4f8);
  *puVar2 = &msys::MMsg::vtable;
  iVar1 = MessageSimple::MessageSimple((MessageSimple *)(puVar2 + 0x53));
  *(undefined4 *)(iVar1 + 0x6ae0) = 0;
  *(undefined1 *)(iVar1 + 0x6ae4) = 0;
  *(undefined1 *)(iVar1 + 0x6ae5) = 0;
  *(undefined4 *)(iVar1 + 0x6ae8) = 0;
  *(undefined4 *)(iVar1 + 0x6aec) = 0;
  *(undefined4 *)(iVar1 + 0x6af4) = 0x400;
  puVar2 = (undefined4 *)FUN_118058e4(iVar1 + 0x6af8);
  *puVar2 = &msys::MMsg::vtable;
  iVar1 = MessageSimple::MessageSimple((MessageSimple *)(puVar2 + 0x53));
  *(undefined4 *)(iVar1 + 0x6ae0) = 0;
  *(undefined1 *)(iVar1 + 0x6ae4) = 0;
  *(undefined1 *)(iVar1 + 0x6ae5) = 0;
  *(undefined4 *)(iVar1 + 0x6ae8) = 0;
  *(undefined4 *)(iVar1 + 0x6aec) = 0;
  *(undefined4 *)(iVar1 + 0x6af4) = 0x400;
  puVar2 = (undefined4 *)FUN_118058e4(iVar1 + 0x6af8);
  *puVar2 = &msys::MMsg::vtable;
  iVar1 = MessageSimple::MessageSimple((MessageSimple *)(puVar2 + 0x53));
  *(undefined4 *)(iVar1 + 0x6ae0) = 0;
  *(undefined1 *)(iVar1 + 0x6ae4) = 0;
  *(undefined1 *)(iVar1 + 0x6ae5) = 0;
  *(undefined4 *)(iVar1 + 0x6ae8) = 0;
  *(undefined4 *)(iVar1 + 0x6aec) = 0;
  *(undefined4 *)(iVar1 + 0x6af4) = 0x400;
  puVar2 = (undefined4 *)FUN_118058e4(iVar1 + 0x6af8);
  *puVar2 = &msys::MMsg::vtable;
  iVar1 = MessageSimple::MessageSimple((MessageSimple *)(puVar2 + 0x53));
  *(undefined4 *)(iVar1 + 0x6ae0) = 0;
  *(undefined1 *)(iVar1 + 0x6ae4) = 0;
  *(undefined1 *)(iVar1 + 0x6ae5) = 0;
  *(undefined4 *)(iVar1 + 0x6ae8) = 0;
  *(undefined4 *)(iVar1 + 0x6aec) = 0;
  *(undefined4 *)(iVar1 + 0x6af4) = 0x400;
  puVar2 = (undefined4 *)FUN_118058e4(iVar1 + 0x6af8);
  *puVar2 = &msys::MMsg::vtable;
  iVar1 = MessageSimple::MessageSimple((MessageSimple *)(puVar2 + 0x53));
  *(undefined4 *)(iVar1 + 0x6ae0) = 0;
  *(undefined1 *)(iVar1 + 0x6ae4) = 0;
  *(undefined1 *)(iVar1 + 0x6ae5) = 0;
  *(undefined4 *)(iVar1 + 0x6ae8) = 0;
  *(undefined4 *)(iVar1 + 0x6aec) = 0;
  *(undefined4 *)(iVar1 + 0x6af4) = 0x400;
  iVar1 = msys::MLytNum::MLytNum((MLytNum *)(iVar1 + 0x6af8));
  iVar1 = msys::MLytNum::MLytNum((MLytNum *)(iVar1 + 0x230));
  iVar1 = __aeabi_vec_ctor_nocookie_nodtor(iVar1 + 0x230,msys::MDfxChr::MDfxChr,0x17c,6);
  iVar1 = msys::MDfxChr::MDfxChr((MDfxChr *)(iVar1 + 0x8e8));
  iVar1 = __aeabi_vec_ctor_nocookie_nodtor(iVar1 + 0x17c,msys::MDfxChr::MDfxChr,0x17c,4);
  iVar1 = msys::MDfxChr::MDfxChr((MDfxChr *)(iVar1 + 0x5f0));
  iVar1 = msys::MDfxChr::MDfxChr((MDfxChr *)(iVar1 + 0x17c));
  iVar1 = msys::MDfxChr::MDfxChr((MDfxChr *)(iVar1 + 0x17c));
  iVar1 = msys::MDfxChr::MDfxChr((MDfxChr *)(iVar1 + 0x17c));
  puVar2 = (undefined4 *)FUN_118058e4(iVar1 + 0x17c);
  *puVar2 = &msys::MMsgWnd::vtable;
  iVar1 = Message::Message((Message *)(puVar2 + 0x53));
  *(undefined4 *)(iVar1 + 28000) = 0;
  *(undefined4 *)(iVar1 + 0x6d64) = 0x400;
  *(undefined4 *)(iVar1 + 0x6d68) = 0;
  *(undefined4 *)(iVar1 + 0x6d6c) = 0;
  *(undefined4 *)(iVar1 + 0x6d70) = 0;
  *(undefined4 *)(iVar1 + 0x6d78) = 6;
  *(undefined4 *)(iVar1 + 0x6d74) = 0;
  *(undefined4 *)(iVar1 + 0x6d7c) = 0;
  *(undefined1 *)(iVar1 + 0x6d80) = 0;
  *(undefined4 *)(iVar1 + 0x6d84) = 0;
  *(undefined4 *)(iVar1 + 0x6d88) = 0;
  *(undefined1 *)(iVar1 + 0x6d8c) = 1;
  *(undefined1 *)(iVar1 + 0x6d8d) = 0;
  *(undefined1 *)(iVar1 + 0x6d8e) = 0;
  *(undefined4 *)(iVar1 + 0x6d90) = 0;
  *(undefined4 *)(iVar1 + 0x6d94) = 0x110003;
  *(undefined4 *)(iVar1 + 0x6d98) = 0x110004;
  *(undefined4 *)(iVar1 + 0x6da0) = 0;
  *(undefined4 *)(iVar1 + 0x6da4) = 0;
  *(undefined4 *)(iVar1 + 0x6da8) = 0x400;
  *(undefined ***)(iVar1 + -0x14c) = &col::ColosseumPage::Core::MsgWnd::vtable;
  *(undefined4 *)(iVar1 + 0x6dac) = 0;
  *(undefined4 *)(iVar1 + 0x6db0) = 0x400;
  *(undefined4 *)(iVar1 + 0x6db4) = 0;
  *(undefined4 *)(iVar1 + 0x6db8) = 0;
  *(undefined4 *)(iVar1 + 0x6dbc) = 0;
  *(undefined4 *)(iVar1 + 0x6dc4) = 6;
  *(undefined4 *)(iVar1 + 0x6dc0) = 0;
  *(undefined4 *)(iVar1 + 0x6dc8) = 0;
  *(undefined1 *)(iVar1 + 0x6dcc) = 0;
  *(undefined4 *)(iVar1 + 0x6dd0) = 0;
  *(undefined4 *)(iVar1 + 0x6dd4) = 0;
  *(undefined1 *)(iVar1 + 0x6dd8) = 1;
  *(undefined1 *)(iVar1 + 0x6dd9) = 0;
  *(undefined1 *)(iVar1 + 0x6dda) = 0;
  *(undefined4 *)(iVar1 + 0x6ddc) = 0;
  *(undefined4 *)(iVar1 + 0x6de0) = 0x110003;
  *(undefined4 *)(iVar1 + 0x6de4) = 0x110004;
  puVar2 = (undefined4 *)
           msys::MListWndPBase::MListWndPBase
                     ((MListWndPBase *)(iVar1 + 0x6dec),(MListWndPCore *)(iVar1 + 0x6fe8));
  *puVar2 = &vtable_for_N4msys9MListWndPILi8EEE;
  puVar2 = (undefined4 *)
           ad::ui::UIListWindowPlusLyt::UIListWindowPlusLyt((UIListWindowPlusLyt *)(puVar2 + 0x7f));
  *puVar2 = &msys::MListWndPCore::vtable;
  puVar2[-0x7f] = &col::ColosseumPage::Core::ListWnd::vtable;
  iVar1 = ad::lyt::Layout::Layout((Layout *)(puVar2 + 0x1b9a));
  iVar1 = ad::lyt::Layout::Layout((Layout *)(iVar1 + 0x3c));
  iVar1 = FUN_1180588c(iVar1 + 0x3c);
  iVar1 = FUN_1180588c(iVar1 + 0x1c);
  iVar1 = FUN_1180588c(iVar1 + 0x1c);
  iVar1 = FUN_1180588c(iVar1 + 0x1c);
  iVar1 = FUN_1180588c(iVar1 + 0x1c);
  iVar1 = FUN_1180588c(iVar1 + 0x1c);
  puVar2 = (undefined4 *)
           msys::MListWndPBase::MListWndPBase
                     ((MListWndPBase *)(iVar1 + 0x24),(MListWndPCore *)(iVar1 + 0x220));
  *puVar2 = &vtable_for_N4msys9MListWndPILi4EEE;
  puVar2 = (undefined4 *)
           ad::ui::UIListWindowPlusLyt::UIListWindowPlusLyt((UIListWindowPlusLyt *)(puVar2 + 0x7f));
  *puVar2 = &msys::MListWndPCore::vtable;
  puVar2[-0x7f] = &col::ColosseumPage::Core::ListWnd_Guide::vtable;
  iVar1 = ad::lyt::Layout::Layout((Layout *)(puVar2 + 0x1b7e));
  iVar1 = FUN_1180588c(iVar1 + 0x3c);
  iVar1 = FUN_1180588c(iVar1 + 0x1c);
  iVar1 = FUN_1180588c(iVar1 + 0x1c);
  iVar1 = msys::MLytNum::MLytNum((MLytNum *)(iVar1 + 0x20));
  iVar1 = msys::MLytNum::MLytNum((MLytNum *)(iVar1 + 0x230));
  iVar1 = FUN_1180588c(iVar1 + 0x230);
  iVar1 = FUN_1180588c(iVar1 + 0x1c);
  puVar2 = (undefined4 *)FUN_118058e4(iVar1 + 0x1c);
  *puVar2 = &msys::MMsg::vtable;
  iVar1 = MessageSimple::MessageSimple((MessageSimple *)(puVar2 + 0x53));
  *(undefined4 *)(iVar1 + 0x6ae0) = 0;
  *(undefined1 *)(iVar1 + 0x6ae4) = 0;
  *(undefined1 *)(iVar1 + 0x6ae5) = 0;
  *(undefined4 *)(iVar1 + 0x6ae8) = 0;
  *(undefined4 *)(iVar1 + 0x6aec) = 0;
  *(undefined4 *)(iVar1 + 0x6af4) = 0x400;
  puVar2 = (undefined4 *)FUN_118058e4(iVar1 + 0x6af8);
  *puVar2 = &msys::MMsg::vtable;
  iVar1 = MessageSimple::MessageSimple((MessageSimple *)(puVar2 + 0x53));
  *(undefined4 *)(iVar1 + 0x6ae0) = 0;
  *(undefined1 *)(iVar1 + 0x6ae4) = 0;
  *(undefined1 *)(iVar1 + 0x6ae5) = 0;
  *(undefined4 *)(iVar1 + 0x6ae8) = 0;
  *(undefined4 *)(iVar1 + 0x6aec) = 0;
  *(undefined4 *)(iVar1 + 0x6af4) = 0x400;
  puVar2 = (undefined4 *)FUN_118058e4(iVar1 + 0x6af8);
  *puVar2 = &msys::MMsg::vtable;
  iVar1 = MessageSimple::MessageSimple((MessageSimple *)(puVar2 + 0x53));
  *(undefined4 *)(iVar1 + 0x6ae0) = 0;
  *(undefined1 *)(iVar1 + 0x6ae4) = 0;
  *(undefined1 *)(iVar1 + 0x6ae5) = 0;
  *(undefined4 *)(iVar1 + 0x6ae8) = 0;
  *(undefined4 *)(iVar1 + 0x6aec) = 0;
  *(undefined4 *)(iVar1 + 0x6af4) = 0x400;
  *(undefined4 *)(iVar1 + 0x6b20) = 0;
  *(undefined4 *)(iVar1 + 0x6b24) = 0;
  iVar1 = msys::MLytNum::MLytNum((MLytNum *)(iVar1 + 0x6b28));
  iVar1 = msys::MLytNum::MLytNum((MLytNum *)(iVar1 + 0x230));
  iVar1 = FUN_1180588c(iVar1 + 0x240);
  iVar1 = FUN_1180588c(iVar1 + 0x1c);
  iVar1 = FUN_1180588c(iVar1 + 0x1c);
  *(undefined4 *)(iVar1 + 0x20) = 0;
  *(undefined4 *)(iVar1 + 0x28) = 0;
  *(undefined4 *)(iVar1 + 0x2c) = 0x3f800000;
  *(undefined4 *)(iVar1 + 0x30) = 0;
  *(undefined2 *)(iVar1 + 0x34) = 1;
  *(undefined2 *)(iVar1 + 0x36) = 0;
  iVar3 = col::GetBootInfo();
  *(undefined1 *)(iVar1 + 0x3f) = *(undefined1 *)(iVar3 + 0x20c);
  FUN_11806cf0(iVar1 + -0x60fd4);
  *(byte *)(iVar1 + 0x39) =
       (byte)((uint)DAT_003f99e0 >> 0x18) & 1 | (byte)(((DAT_003f9a2c & 0x3ffff) >> 0x11) << 1) |
       (DAT_003f9a30 >> 7) << 2 | (byte)(((DAT_003f9a04 & 0x7fffff) >> 0x16) << 3);
  uVar4 = 0;
  *(undefined1 *)(iVar1 + 0x40) = 1;
  do {
    if (((short)(&DAT_003f9de0)[uVar4] < 0) || (((uint)*(byte *)(iVar1 + 0x38) & 1 << uVar4) == 0))
    {
      *(undefined1 *)(iVar1 + 0x40) = 0;
      break;
    }
    uVar4 = uVar4 + 1 & 0xff;
  } while (uVar4 < 7);
  uVar4 = 0;
  *(undefined1 *)(iVar1 + 0x41) = 1;
  while ((-1 < (short)(&DAT_003f9df4)[uVar4] && (((uint)*(byte *)(iVar1 + 0x39) & 1 << uVar4) != 0))
        ) {
    uVar4 = uVar4 + 1 & 0xff;
    if (3 < uVar4) {
LAB_118097b8:
      *(code **)(iVar1 + -0x4e5d8) = FUN_11808d0c;
      *(undefined4 *)(iVar1 + -0x4e5d4) = 0;
      return iVar1 + -0x60fd4;
    }
  }
  *(undefined1 *)(iVar1 + 0x41) = 0;
  goto LAB_118097b8;
}


// FUNC 0x118097e0 col::ColosseumPage::Core::vfunc_0x4 (Colosseum)
//   size 0x10 | file Colosseum+0x97e0 | callers(0) | datarefs 1

void col::ColosseumPage::Core::vfunc_0x4(void)

{
  void *pvVar1;
  
  pvVar1 = (void *)vfunc_0x0();
  operator_delete(pvVar1);
  return;
}


// FUNC 0x118097f0 col::ColosseumPage::Core::vfunc_0x0 (Colosseum)
//   size 0x490 | file Colosseum+0x97f0 | callers(1) 0x118097e0 | datarefs 1

int col::ColosseumPage::Core::vfunc_0x0(undefined4 *param_1)

{
  int iVar1;
  MLyt *pMVar2;
  
  *param_1 = &vtable;
  msys::MCursorBase::term((MCursorBase *)(param_1 + 0x4cc1));
  msys::MLyt::term((MLyt *)(param_1 + 0x4aed));
  msys::MLyt::term((MLyt *)(param_1 + 0x4bd7));
  ad::ctrl::ButtonGroup::FreeAll((ButtonGroup *)(param_1 + 0x4a85));
  ad::fw::Resource::term((Resource *)(param_1 + 0x4aa9));
  ad::lyt::LytResourceMan::term((LytResourceMan *)(param_1 + 0x4a8c));
  param_1[0x18401] = 0;
  param_1[0x183f8] = 0;
  param_1[0x183f1] = 0;
  param_1[0x183ea] = 0;
  iVar1 = msys::MLytNum::~MLytNum((MLytNum *)(param_1 + 0x18357));
  iVar1 = msys::MLytNum::~MLytNum((MLytNum *)(iVar1 + -0x230));
  *(undefined ***)(iVar1 + -0x6c74) = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar1 = MessageSimple::~MessageSimple((MessageSimple *)(iVar1 + -0x6b28));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  *(undefined ***)(iVar1 + -0x6c44) = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar1 = MessageSimple::~MessageSimple((MessageSimple *)(iVar1 + -0x6af8));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  *(undefined ***)(iVar1 + -0x6c44) = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar1 = MessageSimple::~MessageSimple((MessageSimple *)(iVar1 + -0x6af8));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  *(undefined4 *)(iVar1 + -0x10) = 0;
  *(undefined4 *)(iVar1 + -0x2c) = 0;
  iVar1 = msys::MLytNum::~MLytNum((MLytNum *)(iVar1 + -0x268));
  iVar1 = msys::MLytNum::~MLytNum((MLytNum *)(iVar1 + -0x230));
  *(undefined ***)(iVar1 + -0x7088) = &ListWnd_Guide::vtable;
  *(undefined4 *)(iVar1 + -0x14) = 0;
  *(undefined4 *)(iVar1 + -0x30) = 0;
  *(undefined4 *)(iVar1 + -0x4c) = 0;
  iVar1 = ad::lyt::Layout::~Layout((Layout *)(iVar1 + -0x94));
  *(undefined ***)(iVar1 + -0x6ff4) = &vtable_for_N4msys9MListWndPILi4EEE;
  iVar1 = ad::ui::UIListWindowPlusLyt::~UIListWindowPlusLyt
                    ((UIListWindowPlusLyt *)(iVar1 + -0x6df8));
  iVar1 = msys::MListWndPBase::~MListWndPBase((MListWndPBase *)(iVar1 + -0x1fc));
  *(undefined ***)(iVar1 + -0x718c) = &ListWnd::vtable;
  *(undefined4 *)(iVar1 + -0x18) = 0;
  *(undefined4 *)(iVar1 + -0x34) = 0;
  *(undefined4 *)(iVar1 + -0x50) = 0;
  *(undefined4 *)(iVar1 + -0x6c) = 0;
  *(undefined4 *)(iVar1 + -0x88) = 0;
  *(undefined4 *)(iVar1 + -0xa4) = 0;
  iVar1 = ad::lyt::Layout::~Layout((Layout *)(iVar1 + -0xec));
  iVar1 = ad::lyt::Layout::~Layout((Layout *)(iVar1 + -0x3c));
  *(undefined ***)(iVar1 + -0x7064) = &vtable_for_N4msys9MListWndPILi8EEE;
  iVar1 = ad::ui::UIListWindowPlusLyt::~UIListWindowPlusLyt
                    ((UIListWindowPlusLyt *)(iVar1 + -0x6e68));
  iVar1 = msys::MListWndPBase::~MListWndPBase((MListWndPBase *)(iVar1 + -0x1fc));
  *(undefined ***)(iVar1 + -0x6f38) = &msys::MMsgWnd::vtable;
  Message::term((Message *)(iVar1 + -0x6dec));
  iVar1 = Message::~Message((Message *)(iVar1 + -0x6dec));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  iVar1 = msys::MDfxChr::~MDfxChr((MDfxChr *)(iVar1 + -0x17c));
  iVar1 = msys::MDfxChr::~MDfxChr((MDfxChr *)(iVar1 + -0x17c));
  iVar1 = msys::MDfxChr::~MDfxChr((MDfxChr *)(iVar1 + -0x17c));
  iVar1 = msys::MDfxChr::~MDfxChr((MDfxChr *)(iVar1 + -0x17c));
  __aeabi_vec_dtor(iVar1 + -0x5f0,msys::MDfxChr::~MDfxChr,0x17c,4);
  iVar1 = msys::MDfxChr::~MDfxChr((MDfxChr *)(iVar1 + -0x76c));
  __aeabi_vec_dtor(iVar1 + -0x8e8,msys::MDfxChr::~MDfxChr,0x17c,6);
  iVar1 = msys::MLytNum::~MLytNum((MLytNum *)(iVar1 + -0xb18));
  iVar1 = msys::MLytNum::~MLytNum((MLytNum *)(iVar1 + -0x230));
  *(undefined ***)(iVar1 + -0x6c44) = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar1 = MessageSimple::~MessageSimple((MessageSimple *)(iVar1 + -0x6af8));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  *(undefined ***)(iVar1 + -0x6c44) = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar1 = MessageSimple::~MessageSimple((MessageSimple *)(iVar1 + -0x6af8));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  *(undefined ***)(iVar1 + -0x6c44) = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar1 = MessageSimple::~MessageSimple((MessageSimple *)(iVar1 + -0x6af8));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  *(undefined ***)(iVar1 + -0x6c44) = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar1 = MessageSimple::~MessageSimple((MessageSimple *)(iVar1 + -0x6af8));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  *(undefined ***)(iVar1 + -0x6c44) = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar1 = MessageSimple::~MessageSimple((MessageSimple *)(iVar1 + -0x6af8));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  __aeabi_vec_dtor(iVar1 + -0x4f8,&LAB_1180b5b0,0x27c,2);
  iVar1 = msys::MCursorBase::~MCursorBase((MCursorBase *)(iVar1 + -0x550));
  pMVar2 = (MLyt *)(iVar1 + -0x3a8);
  *(undefined ***)pMVar2 = &msys::MLyt::vtable;
  msys::MLyt::term(pMVar2);
  __aeabi_vec_dtor(iVar1 + -0xf8,&LAB_118012dc,0x10,0xc);
  __aeabi_vec_dtor(iVar1 + -0x254,&LAB_11801148,0x1c,0xc);
  iVar1 = msys::MChrBase::vfunc_0x0(pMVar2);
  pMVar2 = (MLyt *)(iVar1 + -0x3a8);
  *(undefined ***)pMVar2 = &msys::MLyt::vtable;
  msys::MLyt::term(pMVar2);
  __aeabi_vec_dtor(iVar1 + -0xf8,&LAB_118012dc,0x10,0xc);
  __aeabi_vec_dtor(iVar1 + -0x254,&LAB_11801148,0x1c,0xc);
  iVar1 = msys::MChrBase::vfunc_0x0(pMVar2);
  __aeabi_vec_dtor(iVar1 + -0x88,ad::fw::Resource::~Resource,0x44,2);
  iVar1 = ad::fw::Resource::~Resource((Resource *)(iVar1 + -0xcc));
  iVar1 = ad::fw::Resource::~Resource((Resource *)(iVar1 + -0x44));
  ad::lyt::LytResourceMan::term((LytResourceMan *)(iVar1 + -0x74));
  iVar1 = ad::font::ResFont::~ResFont((ResFont *)(iVar1 + -0x70));
  iVar1 = ad::ctrl::ButtonGroup::~ButtonGroup((ButtonGroup *)(iVar1 + -0x20));
  iVar1 = Backup::~Backup((Backup *)(iVar1 + -0x12a04));
  return iVar1 + -0x10;
}


// FUNC 0x11809cd0 col::ColosseumPage::vfunc_0x28 (Colosseum)
//   size 0x14 | file Colosseum+0x9cd0 | callers(0) | datarefs 1

int col::ColosseumPage::vfunc_0x28(int param_1,int param_2)

{
  return *(int *)(param_1 + 0x20) + param_2 * 4 + 0x129f8;
}


// FUNC 0x11809ce8 col::ColosseumPage::vfunc_0x8 (Colosseum)
//   size 0x78 | file Colosseum+0x9ce8 | callers(0) | datarefs 1

void col::ColosseumPage::vfunc_0x8(int *param_1)

{
  int iVar1;
  void *pvVar2;
  code *UNRECOVERED_JUMPTABLE;
  bool bVar3;
  
  if (param_1[8] == 0) {
    (**(code **)(*param_1 + 0x2c))(param_1);
    pvVar2 = operator_new(0x61018,(MemAlcBase *)param_1[6],(char *)0x0,0);
    iVar1 = 0;
    if (pvVar2 != (void *)0x0) {
      iVar1 = FUN_11809074(pvVar2,param_1);
    }
    param_1[8] = iVar1;
  }
  else {
    iVar1 = param_1[8];
  }
  UNRECOVERED_JUMPTABLE = (code *)(iVar1 + 0x12000);
  bVar3 = (*(uint *)(iVar1 + 0x12a00) & 1) == 0;
  if (bVar3) {
    UNRECOVERED_JUMPTABLE = *(code **)(iVar1 + 0x129fc);
  }
  if (!bVar3) {
    UNRECOVERED_JUMPTABLE =
         *(code **)(*(int *)(iVar1 + ((int)*(uint *)(iVar1 + 0x12a00) >> 1)) +
                   *(int *)(UNRECOVERED_JUMPTABLE + 0x9fc));
  }
                    /* WARNING: Could not recover jumptable at 0x11809d5c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// FUNC 0x11809d64 col::ColosseumPage::vfunc_0x14 (Colosseum)
//   size 0xf8 | file Colosseum+0x9d64 | callers(0) | datarefs 1

undefined4 col::ColosseumPage::vfunc_0x14(int param_1,MInput *param_2)

{
  MInput MVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  code *extraout_r2;
  code *pcVar6;
  int *piVar7;
  VEC2 *pVVar8;
  bool bVar9;
  uint in_fpscr;
  undefined4 local_20;
  undefined4 uStack_1c;
  
  piVar7 = *(int **)(param_1 + 0x20);
  msys::MPageBase::updateInputAllChr((MPageBase *)piVar7[1],param_2);
  bVar9 = (piVar7[0x4a82] & 1U) == 0;
  pcVar6 = extraout_r2;
  if (bVar9) {
    pcVar6 = (code *)piVar7[0x4a81];
  }
  piVar3 = (int *)((int)piVar7 + (piVar7[0x4a82] >> 1));
  if (!bVar9) {
    pcVar6 = *(code **)(*piVar3 + piVar7[0x4a81]);
  }
  (*pcVar6)(piVar3,param_2);
  iVar4 = msys::MListWndPBase::isTpNeutral((MListWndPBase *)(piVar7 + 0xf7e1));
  MVar1 = param_2[0x11];
  bVar9 = MVar1 == (MInput)0x0;
  if (bVar9) {
    MVar1 = param_2[0x12];
  }
  pVVar8 = (VEC2 *)0x0;
  if ((!bVar9 || MVar1 != (MInput)0x0) && iVar4 != 0) {
    uStack_1c = VectorSignedToFloat(0x78 - (uint)*(ushort *)(param_2 + 0x16),
                                    (byte)(in_fpscr >> 0x16) & 3);
    local_20 = VectorSignedToFloat(*(ushort *)(param_2 + 0x14) - 0xa0,(byte)(in_fpscr >> 0x16) & 3);
    pVVar8 = (VEC2 *)&local_20;
  }
  bVar9 = (bool)(**(code **)(*piVar7 + 8))(piVar7,param_2);
  iVar2 = msys::MComSys::_sys;
  iVar5 = piVar7[2];
  if (piVar7[2] == 0) {
    piVar7[2] = msys::MComSys::_sys;
    iVar5 = iVar2;
  }
  ad::ctrl::ButtonGroup::Update
            ((ButtonGroup *)(piVar7 + 0x4a85),pVVar8,
             (bool)(*(byte *)(iVar5 + 0xe6508) & (byte)iVar4 & bVar9),bVar9);
  return 0xffffffff;
}


// FUNC 0x11809e60 col::ColosseumPage::vfunc_0xc (Colosseum)
//   size 0x4 | file Colosseum+0x9e60 | callers(0) | datarefs 1

void col::ColosseumPage::vfunc_0xc(void)

{
  return;
}


// FUNC 0x11809e64 col::ColosseumPage::vfunc_0x24 (Colosseum)
//   size 0x8 | file Colosseum+0x9e64 | callers(0) | datarefs 1

undefined4 col::ColosseumPage::vfunc_0x24(void)

{
  return 0;
}


// FUNC 0x11809e6c col::ColosseumPage::vfunc_0x4 (Colosseum)
//   size 0xc4 | file Colosseum+0x9e6c | callers(0) | datarefs 1

void col::ColosseumPage::vfunc_0x4(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  undefined4 *puVar6;
  
  *param_1 = &vtable;
  if ((int *)param_1[8] != (int *)0x0) {
    (**(code **)(*(int *)param_1[8] + 4))();
  }
  param_1[8] = 0;
  *param_1 = &msys::MPageBase::vtable;
  puVar6 = param_1 + 3;
  puVar2 = (undefined4 *)param_1[4];
  while (puVar2 != puVar6) {
    puVar1 = (undefined4 *)puVar2[1];
    puVar2[1] = puVar2;
    *puVar2 = puVar2;
    puVar2 = puVar1;
  }
  param_1[4] = puVar6;
  *puVar6 = puVar6;
  puVar2 = (undefined4 *)param_1[4];
  param_1[4] = puVar2;
  *puVar2 = param_1[3];
  piVar3 = param_1 + 1;
  piVar4 = (int *)param_1[2];
  while (piVar4 != piVar3) {
    piVar5 = (int *)piVar4[1];
    piVar4[1] = (int)piVar4;
    *piVar4 = (int)piVar4;
    piVar4 = piVar5;
  }
  param_1[2] = piVar3;
  *piVar3 = (int)piVar3;
  piVar4 = (int *)param_1[2];
  *(int **)(*piVar3 + 4) = piVar4;
  *piVar4 = *piVar3;
  operator_delete(param_1);
  return;
}


// FUNC 0x11809f38 col::ColosseumPage::vfunc_0x0 (Colosseum)
//   size 0xc0 | file Colosseum+0x9f38 | callers(0) | datarefs 1

undefined4 * col::ColosseumPage::vfunc_0x0(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  undefined4 *puVar6;
  
  *param_1 = &vtable;
  if ((int *)param_1[8] != (int *)0x0) {
    (**(code **)(*(int *)param_1[8] + 4))();
  }
  param_1[8] = 0;
  *param_1 = &msys::MPageBase::vtable;
  puVar6 = param_1 + 3;
  puVar2 = (undefined4 *)param_1[4];
  while (puVar2 != puVar6) {
    puVar1 = (undefined4 *)puVar2[1];
    puVar2[1] = puVar2;
    *puVar2 = puVar2;
    puVar2 = puVar1;
  }
  param_1[4] = puVar6;
  *puVar6 = puVar6;
  puVar2 = (undefined4 *)param_1[4];
  param_1[4] = puVar2;
  *puVar2 = param_1[3];
  piVar3 = param_1 + 1;
  piVar4 = (int *)param_1[2];
  while (piVar4 != piVar3) {
    piVar5 = (int *)piVar4[1];
    piVar4[1] = (int)piVar4;
    *piVar4 = (int)piVar4;
    piVar4 = piVar5;
  }
  param_1[2] = piVar3;
  *piVar3 = (int)piVar3;
  piVar4 = (int *)param_1[2];
  *(int **)(*piVar3 + 4) = piVar4;
  *piVar4 = *piVar3;
  return param_1;
}


// FUNC 0x1180a000 col::ColosseumTask::vfunc_0x10 (Colosseum)
//   size 0x1c | file Colosseum+0xa000 | callers(0) | datarefs 1

void col::ColosseumTask::vfunc_0x10(TaskMainBase *param_1)

{
  if (*(char *)(*(int *)(param_1 + 0x580) + 0xe9049) == '\0') {
    return;
  }
  GameMain::Back(param_1);
  return;
}


// FUNC 0x1180a01c FUN_1180a01c (Colosseum)
//   size 0x38 | file Colosseum+0xa01c | callers(1) 0x11800848

int FUN_1180a01c(MTaskBase *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)msys::MTaskBase::MTaskBase(param_1);
  *puVar1 = &col::ColosseumTask::vtable;
  iVar2 = FUN_1180b454(puVar1 + 0x161);
  FUN_1180b2c8(iVar2,iVar2 + -0x584);
  *(int *)(iVar2 + -4) = iVar2;
  return iVar2 + -0x584;
}


// FUNC 0x1180a058 col::ColosseumTask::vfunc_0x8 (Colosseum)
//   size 0x24 | file Colosseum+0xa058 | callers(0) | datarefs 1

void col::ColosseumTask::vfunc_0x8(undefined4 *param_1)

{
  int iVar1;
  void *pvVar2;
  
  *param_1 = &vtable;
  iVar1 = Colosseum::vfunc_0x0(param_1 + 0x161);
  pvVar2 = (void *)ad::fw::TaskBase::~TaskBase((TaskBase *)(iVar1 + -0x584));
  operator_delete(pvVar2);
  return;
}


// FUNC 0x1180a080 col::ColosseumTask::vfunc_0x4 (Colosseum)
//   size 0x20 | file Colosseum+0xa080 | callers(0) | datarefs 1

void col::ColosseumTask::vfunc_0x4(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &vtable;
  iVar1 = Colosseum::vfunc_0x0(param_1 + 0x161);
  ad::fw::TaskBase::~TaskBase((TaskBase *)(iVar1 + -0x584));
  return;
}


// FUNC 0x1180a0a4 FUN_1180a0a4 (Colosseum)
//   size 0x70 | file Colosseum+0xa0a4 | callers(0) | datarefs 2

void FUN_1180a0a4(MComSys *param_1)

{
  MTX44 aMStack_80 [64];
  MTX34 aMStack_40 [52];
  
  msys::MCamera::getProjMtx((MCamera *)(param_1 + 0x4ad54),aMStack_80,0x400);
  msys::MCamera::getViewMtx((MCamera *)(param_1 + 0x4ad54),aMStack_40);
  ad::fw::TaskBase::setULcdCameraInfoBase(*(TaskBase **)(param_1 + 4),aMStack_40,aMStack_80,1);
  Grp::SetupProjLcdOrtho
            (aMStack_80,0x400,false,true,*(float *)(param_1 + 0x4ad74),*(float *)(param_1 + 0x4ad78)
            );
  msys::MComSys::funcCalcMainNomal(param_1);
  return;
}


// FUNC 0x1180a118 col::Colosseum::vfunc_0x10 (Colosseum)
//   size 0x38 | file Colosseum+0xa118 | callers(0) | datarefs 1

void col::Colosseum::vfunc_0x10(MComSys *param_1,CmdList *param_2)

{
  MTX44 aMStack_50 [68];
  
  msys::MCamera::getProjMtx((MCamera *)(param_1 + 0x4ae34),aMStack_50,0x401);
  msys::MComSys::funcDrawLower(param_1,param_2);
  return;
}


// FUNC 0x1180a158 col::Colosseum::vfunc_0xc (Colosseum)
//   size 0xc1c | file Colosseum+0xa158 | callers(0) | datarefs 1

void col::Colosseum::vfunc_0xc(MComSys *param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  MTX44 *pMVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined1 *puVar8;
  int *piVar9;
  uint uVar10;
  undefined4 uVar11;
  int *piVar12;
  undefined4 uVar13;
  MComSys *pMVar14;
  MTX34 *pMVar15;
  MTX44 *pMVar16;
  int *piVar17;
  MComSys *pMVar18;
  int *piVar19;
  undefined4 uVar20;
  uint in_fpscr;
  float fVar21;
  undefined4 uVar22;
  float fVar23;
  undefined4 uVar24;
  float fVar25;
  undefined4 uVar26;
  undefined4 uVar27;
  undefined4 uVar28;
  undefined4 uVar29;
  undefined4 uVar30;
  MComSys *pMVar31;
  float fVar32;
  float local_1b8;
  undefined4 local_1b4;
  undefined4 local_1b0;
  float local_1ac;
  undefined4 local_1a8;
  float fStack_1a4;
  undefined4 local_1a0;
  float local_19c;
  undefined4 local_198;
  undefined4 local_194;
  undefined4 local_190;
  undefined4 local_18c;
  undefined4 local_188;
  undefined4 local_184;
  undefined4 local_180;
  undefined4 uStack_17c;
  undefined4 local_174;
  uint local_170;
  MComSys *local_16c;
  MComSys *local_168;
  float local_164;
  undefined4 uStack_160;
  undefined4 uStack_15c;
  undefined4 uStack_158;
  float local_154;
  undefined4 local_150;
  undefined4 uStack_14c;
  undefined4 uStack_148;
  float local_144;
  undefined4 local_140;
  undefined4 local_13c;
  undefined4 local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined4 local_12c;
  undefined4 local_128;
  undefined4 local_124;
  undefined4 local_120;
  undefined4 local_11c;
  float local_118;
  float fStack_114;
  undefined4 local_110;
  undefined4 local_10c;
  undefined4 local_108;
  undefined4 uStack_104;
  WorldFrustum aWStack_100 [40];
  float local_d8;
  float local_d4;
  float fStack_d0;
  float local_c0;
  float local_bc;
  float local_b8;
  float local_9c;
  float local_98;
  float local_94;
  MTX34 aMStack_80 [52];
  
  if (param_1[0x4af14] != (MComSys)0x0) {
    msys::MCamera::update((MCamera *)(param_1 + 0x4ad54),0x400);
    iVar2 = *(int *)(param_1 + 4);
    pMVar15 = (MTX34 *)(iVar2 + 0x20c);
    pMVar14 = param_1 + 0x4af18;
    uVar26 = *(undefined4 *)(iVar2 + 0x218);
    uVar27 = *(undefined4 *)(iVar2 + 0x21c);
    uVar28 = *(undefined4 *)(iVar2 + 0x220);
    uVar29 = *(undefined4 *)(iVar2 + 0x224);
    uVar30 = *(undefined4 *)(iVar2 + 0x228);
    uVar22 = *(undefined4 *)pMVar15;
    uVar24 = *(undefined4 *)(iVar2 + 0x210);
    *(undefined4 *)(param_1 + 0x98910) = *(undefined4 *)(iVar2 + 0x214);
    *(undefined4 *)(param_1 + 0x98908) = uVar22;
    *(undefined4 *)(param_1 + 0x9890c) = uVar24;
    *(undefined4 *)(param_1 + 0x98914) = uVar26;
    *(undefined4 *)(param_1 + 0x98918) = uVar27;
    *(undefined4 *)(param_1 + 0x9891c) = uVar28;
    *(undefined4 *)(param_1 + 0x98920) = uVar29;
    *(undefined4 *)(param_1 + 0x98924) = uVar30;
    uVar3 = *(undefined4 *)(iVar2 + 0x22c);
    uVar11 = *(undefined4 *)(iVar2 + 0x230);
    uVar13 = *(undefined4 *)(iVar2 + 0x234);
    uVar20 = *(undefined4 *)(iVar2 + 0x238);
    *(undefined4 *)(param_1 + 0x98928) = uVar3;
    *(undefined4 *)(param_1 + 0x9892c) = uVar11;
    *(undefined4 *)(param_1 + 0x98930) = uVar13;
    *(undefined4 *)(param_1 + 0x98934) = uVar20;
    *(undefined4 *)(param_1 + 0x98868) = uVar22;
    *(undefined4 *)(param_1 + 0x9886c) = uVar24;
    *(undefined4 *)(param_1 + 0x98870) = *(undefined4 *)(param_1 + 0x98910);
    *(undefined4 *)(param_1 + 0x98874) = uVar26;
    *(undefined4 *)(param_1 + 0x98878) = uVar27;
    *(undefined4 *)(param_1 + 0x9887c) = uVar28;
    *(undefined4 *)(param_1 + 0x98880) = uVar29;
    *(undefined4 *)(param_1 + 0x98884) = uVar30;
    *(undefined4 *)(param_1 + 0x98888) = uVar3;
    *(undefined4 *)(param_1 + 0x9888c) = *(undefined4 *)(param_1 + 0x9892c);
    *(undefined4 *)(param_1 + 0x98890) = *(undefined4 *)(param_1 + 0x98930);
    *(undefined4 *)(param_1 + 0x98894) = uVar20;
    uVar3 = *(undefined4 *)(iVar2 + 0x240);
    uVar11 = *(undefined4 *)(iVar2 + 0x244);
    uVar13 = *(undefined4 *)(iVar2 + 0x248);
    uVar20 = *(undefined4 *)(iVar2 + 0x24c);
    uVar22 = *(undefined4 *)(iVar2 + 0x250);
    uVar24 = *(undefined4 *)(iVar2 + 0x254);
    uVar26 = *(undefined4 *)(iVar2 + 600);
    *(undefined4 *)(param_1 + 0x98938) = *(undefined4 *)(iVar2 + 0x23c);
    *(undefined4 *)(param_1 + 0x9893c) = uVar3;
    *(undefined4 *)(param_1 + 0x98940) = uVar11;
    *(undefined4 *)(param_1 + 0x98944) = uVar13;
    *(undefined4 *)(param_1 + 0x98948) = uVar20;
    *(undefined4 *)(param_1 + 0x9894c) = uVar22;
    *(undefined4 *)(param_1 + 0x98950) = uVar24;
    *(undefined4 *)(param_1 + 0x98954) = uVar26;
    uVar3 = *(undefined4 *)(iVar2 + 0x260);
    uVar11 = *(undefined4 *)(iVar2 + 0x264);
    uVar13 = *(undefined4 *)(iVar2 + 0x268);
    uVar20 = *(undefined4 *)(iVar2 + 0x26c);
    uVar22 = *(undefined4 *)(iVar2 + 0x270);
    uVar24 = *(undefined4 *)(iVar2 + 0x274);
    uVar26 = *(undefined4 *)(iVar2 + 0x278);
    pMVar16 = (MTX44 *)(iVar2 + 0x23c);
    *(undefined4 *)(param_1 + 0x98958) = *(undefined4 *)(iVar2 + 0x25c);
    *(undefined4 *)(param_1 + 0x9895c) = uVar3;
    *(undefined4 *)(param_1 + 0x98960) = uVar11;
    *(undefined4 *)(param_1 + 0x98964) = uVar13;
    *(undefined4 *)(param_1 + 0x98968) = uVar20;
    *(undefined4 *)(param_1 + 0x9896c) = uVar22;
    *(undefined4 *)(param_1 + 0x98970) = uVar24;
    *(undefined4 *)(param_1 + 0x98974) = uVar26;
    *(undefined4 *)(param_1 + 0x988c8) = *(undefined4 *)(param_1 + 0x98938);
    *(undefined4 *)(param_1 + 0x988cc) = *(undefined4 *)(param_1 + 0x9893c);
    *(undefined4 *)(param_1 + 0x988d0) = *(undefined4 *)(param_1 + 0x98940);
    *(undefined4 *)(param_1 + 0x988d4) = *(undefined4 *)(param_1 + 0x98944);
    *(undefined4 *)(param_1 + 0x988d8) = *(undefined4 *)(param_1 + 0x98948);
    *(undefined4 *)(param_1 + 0x988dc) = *(undefined4 *)(param_1 + 0x9894c);
    *(undefined4 *)(param_1 + 0x988e0) = *(undefined4 *)(param_1 + 0x98950);
    *(undefined4 *)(param_1 + 0x988e4) = *(undefined4 *)(param_1 + 0x98954);
    *(undefined4 *)(param_1 + 0x988e8) = *(undefined4 *)(param_1 + 0x98958);
    *(undefined4 *)(param_1 + 0x988ec) = *(undefined4 *)(param_1 + 0x9895c);
    *(undefined4 *)(param_1 + 0x988f0) = *(undefined4 *)(param_1 + 0x98960);
    *(undefined4 *)(param_1 + 0x988f4) = *(undefined4 *)(param_1 + 0x98964);
    *(undefined4 *)(param_1 + 0x988f8) = *(undefined4 *)(param_1 + 0x98968);
    *(undefined4 *)(param_1 + 0x988fc) = *(undefined4 *)(param_1 + 0x9896c);
    *(undefined4 *)(param_1 + 0x98900) = *(undefined4 *)(param_1 + 0x98970);
    *(undefined4 *)(param_1 + 0x98904) = *(undefined4 *)(param_1 + 0x98974);
    ad::math::FastInverse((MTX34 *)(param_1 + 0x98898),(MTX34 *)(iVar2 + 0x20c));
    *(undefined4 *)(param_1 + 0x98978) = *(undefined4 *)(param_1 + 0x98868);
    *(undefined4 *)(param_1 + 0x9897c) = *(undefined4 *)(param_1 + 0x9886c);
    *(undefined4 *)(param_1 + 0x98980) = *(undefined4 *)(param_1 + 0x98870);
    *(undefined4 *)(param_1 + 0x98984) = *(undefined4 *)(param_1 + 0x98874);
    *(undefined4 *)(param_1 + 0x98988) = *(undefined4 *)(param_1 + 0x98878);
    *(undefined4 *)(param_1 + 0x9898c) = *(undefined4 *)(param_1 + 0x9887c);
    *(undefined4 *)(param_1 + 0x98990) = *(undefined4 *)(param_1 + 0x98880);
    *(undefined4 *)(param_1 + 0x98994) = *(undefined4 *)(param_1 + 0x98884);
    *(undefined4 *)(param_1 + 0x98998) = *(undefined4 *)(param_1 + 0x98888);
    *(undefined4 *)(param_1 + 0x9899c) = *(undefined4 *)(param_1 + 0x9888c);
    *(undefined4 *)(param_1 + 0x989a0) = *(undefined4 *)(param_1 + 0x98890);
    *(undefined4 *)(param_1 + 0x989a4) = *(undefined4 *)(param_1 + 0x98894);
    *(undefined4 *)(param_1 + 0x989a8) = *(undefined4 *)(param_1 + 0x98898);
    *(undefined4 *)(param_1 + 0x989ac) = *(undefined4 *)(param_1 + 0x9889c);
    *(undefined4 *)(param_1 + 0x989b0) = *(undefined4 *)(param_1 + 0x988a0);
    *(undefined4 *)(param_1 + 0x989b4) = *(undefined4 *)(param_1 + 0x988a4);
    *(undefined4 *)(param_1 + 0x989b8) = *(undefined4 *)(param_1 + 0x988a8);
    *(undefined4 *)(param_1 + 0x989bc) = *(undefined4 *)(param_1 + 0x988ac);
    *(undefined4 *)(param_1 + 0x989c0) = *(undefined4 *)(param_1 + 0x988b0);
    *(undefined4 *)(param_1 + 0x989c4) = *(undefined4 *)(param_1 + 0x988b4);
    *(undefined4 *)(param_1 + 0x989c8) = *(undefined4 *)(param_1 + 0x988b8);
    *(undefined4 *)(param_1 + 0x989cc) = *(undefined4 *)(param_1 + 0x988bc);
    *(undefined4 *)(param_1 + 0x989d0) = *(undefined4 *)(param_1 + 0x988c0);
    *(undefined4 *)(param_1 + 0x989d4) = *(undefined4 *)(param_1 + 0x988c4);
    *(float *)(param_1 + 0x98a1c) = *(float *)(param_1 + 0x4ad74);
    *(float *)(param_1 + 0x98a20) = *(float *)(param_1 + 0x4ad78);
    pMVar4 = (MTX44 *)(param_1 + 0x989dc);
    Grp::SetupProjLcdOrtho
              (pMVar4,0x400,false,true,*(float *)(param_1 + 0x4ad74),*(float *)(param_1 + 0x4ad78));
    CellAnimeState::setProj2dParallax((CellAnimeState *)(param_1 + 0x4af6c),pMVar4);
    iVar5 = *(int *)(param_1 + 4);
    fVar23 = *(float *)(iVar2 + 0x218) - *(float *)(iVar5 + 0x288);
    fVar25 = *(float *)(iVar2 + 0x228) - *(float *)(iVar5 + 0x298);
    fVar21 = *(float *)(iVar2 + 0x238) - *(float *)(iVar5 + 0x2a8);
    *(float *)(param_1 + 0x4b020) = SQRT(fVar23 * fVar23 + fVar25 * fVar25 + fVar21 * fVar21);
    iVar5 = *(int *)(param_1 + 0x98a24);
    uVar10 = *(uint *)(iVar5 + 0x14);
    uVar6 = *(uint *)(iVar5 + 0x18);
    if (uVar6 < uVar10) {
      do {
        uVar6 = uVar6 - 0x1c;
      } while (uVar10 != uVar6);
    }
    *(uint *)(iVar5 + 0x18) = uVar10;
    *(undefined4 *)(iVar5 + 0x34) = *(undefined4 *)(iVar5 + 0x30);
    *(MComSys **)(iVar5 + 0x3c) = param_1 + 0x4aaa4;
    ad::math::FastInverse(aMStack_80,pMVar15);
    fVar21 = (float)ad::math::CalcFar(pMVar16);
    fVar23 = (float)ad::math::CalcNear(pMVar16);
    ad::math::WorldFrustum::WorldFrustum(aWStack_100,aMStack_80,pMVar16,fVar23,fVar21);
    fVar25 = local_c0 - local_d8;
    fVar23 = local_bc - local_d4;
    fVar21 = local_b8 - fStack_d0;
    if (((CalcSortCameraForRemillionOrtho::calc(nn::math::MTX34_const&,nn::math::MTX44_const&)::
          sort_inv_view_base & 1) == 0) &&
       (iVar7 = __cxa_guard_acquire(&CalcSortCameraForRemillionOrtho::
                                     calc(nn::math::MTX34_const&,nn::math::MTX44_const&)::
                                     sort_inv_view_base), iVar7 != 0)) {
      CalcSortCameraForRemillionOrtho::calc(nn::math::MTX34_const&,nn::math::MTX44_const&)::
      sort_inv_view_base = 0x3f800000;
      DAT_00434d08 = (MComSys *)0x0;
      DAT_00434d0c = (MComSys *)0x0;
      DAT_00434d10 = 0;
      DAT_00434d14 = 0;
      DAT_00434d18 = 0x3f3504f3;
      DAT_00434d1c = 0x3f3504f3;
      DAT_00434d20 = 0;
      DAT_00434d24 = 0;
      DAT_00434d28 = 0xbf3504f3;
      DAT_00434d2c = 0x3f3504f3;
      DAT_00434d30 = 0;
      __cxa_guard_release(&CalcSortCameraForRemillionOrtho::
                           calc(nn::math::MTX34_const&,nn::math::MTX44_const&)::sort_inv_view_base);
    }
    local_170 = CalcSortCameraForRemillionOrtho::calc(nn::math::MTX34_const&,nn::math::MTX44_const&)
                ::sort_inv_view_base;
    local_16c = DAT_00434d08;
    local_168 = DAT_00434d0c;
    uStack_160 = DAT_00434d14;
    uStack_15c = DAT_00434d18;
    uStack_158 = DAT_00434d1c;
    local_150 = DAT_00434d24;
    uStack_14c = DAT_00434d28;
    uStack_148 = DAT_00434d2c;
    local_164 = local_d8 + fVar25 * 0.5;
    local_154 = local_d4 + fVar23 * 0.5;
    local_144 = fStack_d0 + fVar21 * 0.5;
    ad::math::FastInverse((MTX34 *)&local_170,(MTX34 *)&local_170);
    if (((CalcSortCameraForRemillionOrtho::calc(nn::math::MTX34_const&,nn::math::MTX44_const&)::
          sort_view_look & 1) == 0) &&
       (iVar7 = __cxa_guard_acquire(&CalcSortCameraForRemillionOrtho::
                                     calc(nn::math::MTX34_const&,nn::math::MTX44_const&)::
                                     sort_view_look), iVar7 != 0)) {
      CalcSortCameraForRemillionOrtho::calc(nn::math::MTX34_const&,nn::math::MTX44_const&)::
      sort_view_look = 0.0;
      DAT_00434cfc = -0.70710677;
      DAT_00434d00 = -0.70710677;
      __cxa_guard_release(&CalcSortCameraForRemillionOrtho::
                           calc(nn::math::MTX34_const&,nn::math::MTX44_const&)::sort_view_look);
    }
    pMVar31 = (MComSys *)0x40000000;
    local_13c = 0;
    local_138 = 0;
    local_130 = 0;
    local_128 = 0;
    local_120 = 0;
    local_11c = 0;
    local_110 = 0;
    local_10c = 0;
    local_108 = 0;
    uStack_104 = 0x3f800000;
    local_140 = 0x3f800000;
    local_134 = 0x80000000;
    local_12c = 0x3f800000;
    local_124 = 0x80000000;
    local_118 = 1.0 / ((local_9c - local_c0) *
                       CalcSortCameraForRemillionOrtho::
                       calc(nn::math::MTX34_const&,nn::math::MTX44_const&)::sort_view_look +
                       (local_98 - local_bc) * DAT_00434cfc + (local_94 - local_b8) * DAT_00434d00);
    fStack_114 = local_118 * 0.0;
    uVar3 = *(undefined4 *)(iVar2 + 0x210);
    uVar11 = *(undefined4 *)(iVar2 + 0x214);
    uVar13 = *(undefined4 *)(iVar2 + 0x218);
    uVar20 = *(undefined4 *)(iVar2 + 0x21c);
    uVar22 = *(undefined4 *)(iVar2 + 0x220);
    uVar24 = *(undefined4 *)(iVar2 + 0x224);
    uVar26 = *(undefined4 *)(iVar2 + 0x228);
    *(undefined4 *)(iVar5 + 0x4d950) = *(undefined4 *)pMVar15;
    *(undefined4 *)(iVar5 + 0x4d954) = uVar3;
    *(undefined4 *)(iVar5 + 0x4d958) = uVar11;
    *(undefined4 *)(iVar5 + 0x4d95c) = uVar13;
    *(undefined4 *)(iVar5 + 0x4d960) = uVar20;
    *(undefined4 *)(iVar5 + 0x4d964) = uVar22;
    *(undefined4 *)(iVar5 + 0x4d968) = uVar24;
    *(undefined4 *)(iVar5 + 0x4d96c) = uVar26;
    uVar3 = *(undefined4 *)(iVar2 + 0x230);
    uVar11 = *(undefined4 *)(iVar2 + 0x234);
    uVar13 = *(undefined4 *)(iVar2 + 0x238);
    *(undefined4 *)(iVar5 + 0x4d970) = *(undefined4 *)(iVar2 + 0x22c);
    *(undefined4 *)(iVar5 + 0x4d974) = uVar3;
    *(undefined4 *)(iVar5 + 0x4d978) = uVar11;
    *(undefined4 *)(iVar5 + 0x4d97c) = uVar13;
    uVar3 = *(undefined4 *)(iVar2 + 0x240);
    uVar11 = *(undefined4 *)(iVar2 + 0x244);
    uVar13 = *(undefined4 *)(iVar2 + 0x248);
    uVar20 = *(undefined4 *)(iVar2 + 0x24c);
    uVar22 = *(undefined4 *)(iVar2 + 0x250);
    uVar24 = *(undefined4 *)(iVar2 + 0x254);
    uVar26 = *(undefined4 *)(iVar2 + 600);
    *(undefined4 *)(iVar5 + 0x4d9b0) = *(undefined4 *)pMVar16;
    *(undefined4 *)(iVar5 + 0x4d9b4) = uVar3;
    *(undefined4 *)(iVar5 + 0x4d9b8) = uVar11;
    *(undefined4 *)(iVar5 + 0x4d9bc) = uVar13;
    *(undefined4 *)(iVar5 + 0x4d9c0) = uVar20;
    *(undefined4 *)(iVar5 + 0x4d9c4) = uVar22;
    *(undefined4 *)(iVar5 + 0x4d9c8) = uVar24;
    *(undefined4 *)(iVar5 + 0x4d9cc) = uVar26;
    uVar3 = *(undefined4 *)(iVar2 + 0x260);
    uVar11 = *(undefined4 *)(iVar2 + 0x264);
    uVar13 = *(undefined4 *)(iVar2 + 0x268);
    uVar20 = *(undefined4 *)(iVar2 + 0x26c);
    uVar22 = *(undefined4 *)(iVar2 + 0x270);
    uVar24 = *(undefined4 *)(iVar2 + 0x274);
    uVar26 = *(undefined4 *)(iVar2 + 0x278);
    *(undefined4 *)(iVar5 + 0x4d9d0) = *(undefined4 *)(iVar2 + 0x25c);
    *(undefined4 *)(iVar5 + 0x4d9d4) = uVar3;
    *(undefined4 *)(iVar5 + 0x4d9d8) = uVar11;
    *(undefined4 *)(iVar5 + 0x4d9dc) = uVar13;
    *(undefined4 *)(iVar5 + 0x4d9e0) = uVar20;
    *(undefined4 *)(iVar5 + 0x4d9e4) = uVar22;
    *(undefined4 *)(iVar5 + 0x4d9e8) = uVar24;
    *(undefined4 *)(iVar5 + 0x4d9ec) = uVar26;
    ad::math::FastInverse((MTX34 *)(iVar5 + 0x4d980),(MTX34 *)(iVar2 + 0x20c));
    *(uint *)(iVar5 + 0x4d9f0) = local_170;
    *(MComSys **)(iVar5 + 0x4d9f4) = local_16c;
    *(MComSys **)(iVar5 + 0x4d9f8) = local_168;
    *(float *)(iVar5 + 0x4d9fc) = local_164;
    *(undefined4 *)(iVar5 + 0x4da00) = uStack_160;
    *(undefined4 *)(iVar5 + 0x4da04) = uStack_15c;
    *(undefined4 *)(iVar5 + 0x4da08) = uStack_158;
    *(float *)(iVar5 + 0x4da0c) = local_154;
    *(undefined4 *)(iVar5 + 0x4da10) = local_150;
    *(undefined4 *)(iVar5 + 0x4da14) = uStack_14c;
    *(undefined4 *)(iVar5 + 0x4da18) = uStack_148;
    *(float *)(iVar5 + 0x4da1c) = local_144;
    *(undefined4 *)(iVar5 + 0x4da20) = local_140;
    *(undefined4 *)(iVar5 + 0x4da24) = local_13c;
    *(undefined4 *)(iVar5 + 0x4da28) = local_138;
    *(undefined4 *)(iVar5 + 0x4da2c) = local_134;
    *(undefined4 *)(iVar5 + 0x4da30) = local_130;
    *(undefined4 *)(iVar5 + 0x4da34) = local_12c;
    *(undefined4 *)(iVar5 + 0x4da38) = local_128;
    *(undefined4 *)(iVar5 + 0x4da3c) = local_124;
    *(undefined4 *)(iVar5 + 0x4da40) = local_120;
    *(undefined4 *)(iVar5 + 0x4da44) = local_11c;
    *(float *)(iVar5 + 0x4da48) = local_118;
    *(float *)(iVar5 + 0x4da4c) = fStack_114;
    *(undefined4 *)(iVar5 + 0x4da50) = local_110;
    *(undefined4 *)(iVar5 + 0x4da54) = local_10c;
    *(undefined4 *)(iVar5 + 0x4da58) = local_108;
    *(undefined4 *)(iVar5 + 0x4da5c) = uStack_104;
    *(undefined4 *)(iVar5 + 0x4da60) = *(undefined4 *)(iVar5 + 0x4d950);
    *(undefined4 *)(iVar5 + 0x4da64) = *(undefined4 *)(iVar5 + 0x4d954);
    *(undefined4 *)(iVar5 + 0x4da68) = *(undefined4 *)(iVar5 + 0x4d958);
    *(undefined4 *)(iVar5 + 0x4da6c) = *(undefined4 *)(iVar5 + 0x4d95c);
    *(undefined4 *)(iVar5 + 0x4da70) = *(undefined4 *)(iVar5 + 0x4d960);
    *(undefined4 *)(iVar5 + 0x4da74) = *(undefined4 *)(iVar5 + 0x4d964);
    *(undefined4 *)(iVar5 + 0x4da78) = *(undefined4 *)(iVar5 + 0x4d968);
    *(undefined4 *)(iVar5 + 0x4da7c) = *(undefined4 *)(iVar5 + 0x4d96c);
    *(undefined4 *)(iVar5 + 0x4da80) = *(undefined4 *)(iVar5 + 0x4d970);
    *(undefined4 *)(iVar5 + 0x4da84) = *(undefined4 *)(iVar5 + 0x4d974);
    *(undefined4 *)(iVar5 + 0x4da88) = *(undefined4 *)(iVar5 + 0x4d978);
    *(undefined4 *)(iVar5 + 0x4da8c) = *(undefined4 *)(iVar5 + 0x4d97c);
    *(undefined4 *)(iVar5 + 0x4da90) = *(undefined4 *)(iVar5 + 0x4d980);
    *(undefined4 *)(iVar5 + 0x4da94) = *(undefined4 *)(iVar5 + 0x4d984);
    *(undefined4 *)(iVar5 + 0x4da98) = *(undefined4 *)(iVar5 + 0x4d988);
    *(undefined4 *)(iVar5 + 0x4da9c) = *(undefined4 *)(iVar5 + 0x4d98c);
    *(undefined4 *)(iVar5 + 0x4daa0) = *(undefined4 *)(iVar5 + 0x4d990);
    *(undefined4 *)(iVar5 + 0x4daa4) = *(undefined4 *)(iVar5 + 0x4d994);
    *(undefined4 *)(iVar5 + 0x4daa8) = *(undefined4 *)(iVar5 + 0x4d998);
    *(undefined4 *)(iVar5 + 0x4daac) = *(undefined4 *)(iVar5 + 0x4d99c);
    *(undefined4 *)(iVar5 + 0x4dab0) = *(undefined4 *)(iVar5 + 0x4d9a0);
    *(undefined4 *)(iVar5 + 0x4dab4) = *(undefined4 *)(iVar5 + 0x4d9a4);
    *(undefined4 *)(iVar5 + 0x4dab8) = *(undefined4 *)(iVar5 + 0x4d9a8);
    *(undefined4 *)(iVar5 + 0x4dabc) = *(undefined4 *)(iVar5 + 0x4d9ac);
    iVar7 = *(int *)(param_1 + 4);
    fVar21 = *(float *)(iVar2 + 0x218) - *(float *)(iVar7 + 0x288);
    fVar23 = *(float *)(iVar2 + 0x228) - *(float *)(iVar7 + 0x298);
    fVar25 = *(float *)(iVar2 + 0x238) - *(float *)(iVar7 + 0x2a8);
    *(float *)(iVar5 + 0x108) = SQRT(fVar21 * fVar21 + fVar23 * fVar23 + fVar25 * fVar25);
    Prim::setProj2dParallax((Prim *)(param_1 + 0xd3100),pMVar4);
    Prim::setProj2dParallax((Prim *)(param_1 + 0xbfb7c),pMVar4);
    ad::lyt::DrawInfo::SetProjectionMtx((DrawInfo *)(param_1 + 0xd2f00),pMVar4);
    ad::lyt::DrawInfo::SetProjectionMtx((DrawInfo *)(param_1 + 0xd3000),pMVar4);
    uVar3 = Grp::GetLcdWidth(0x400);
    fVar32 = (float)VectorUnsignedToFloat(uVar3,(byte)(in_fpscr >> 0x16) & 3);
    uVar3 = Grp::GetLcdHeight(0x400);
    local_198 = 0;
    local_194 = 0;
    local_188 = 0;
    local_184 = 0;
    fVar21 = (float)VectorUnsignedToFloat(uVar3,(byte)(in_fpscr >> 0x16) & 3);
    fVar23 = 1.0 / (fVar32 * 0.5 - -(fVar32 * 0.5));
    local_190 = 0x3a833405;
    local_18c = 0x3a833405;
    fStack_1a4 = -(fVar23 * 2.0);
    fVar25 = 1.0 / (fVar21 * 0.5 - -(fVar21 * 0.5));
    local_19c = --((fVar32 * 0.5 + -(fVar32 * 0.5)) * fVar23);
    local_1b8 = -(fVar25 * 2.0);
    local_1b4 = 0x80000000;
    local_1ac = --((fVar21 * 0.5 + -(fVar21 * 0.5)) * fVar25);
    local_1b0 = 0x80000000;
    local_1a8 = 0x80000000;
    local_1a0 = 0x80000000;
    local_180 = 0;
    uStack_17c = 0x3f800000;
    Prim::setProjMtx((Prim *)(param_1 + 0x98a34),(MTX44 *)&local_1b8);
    ad::fw::DfxSys::setViewMtx(*(DfxSys **)(param_1 + 0xe64f0),pMVar15,'\0');
    uVar10 = *(uint *)(param_1 + 0x4af2c);
    uVar6 = *(uint *)(param_1 + 0x4af30);
    if (uVar6 < uVar10) {
      do {
        uVar6 = uVar6 - 0x1c;
      } while (uVar10 != uVar6);
    }
    *(uint *)(param_1 + 0x4af30) = uVar10;
    *(undefined4 *)(param_1 + 0x4af4c) = *(undefined4 *)(param_1 + 0x4af48);
    *(MComSys **)(param_1 + 0x4af54) = param_1 + 0x4aaa4;
    iVar5 = *(int *)(param_1 + 0xe64f0);
    iVar2 = *(int *)(iVar5 + 0x14);
    *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar2 + 4);
    *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(iVar2 + 4);
    iVar2 = *(int *)(iVar5 + 0x1c);
    *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar2 + 4);
    *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(iVar2 + 4);
    ad::dfx::Engine::setViewMtx(*(Engine **)(*(int *)(param_1 + 0xe64f0) + 0xc),pMVar15);
    pMVar18 = param_1 + 0xfd8;
    iVar2 = 0;
    if (param_1[0x43ab4] != (MComSys)0x0) {
      local_168 = param_1 + 0x98938;
      local_170 = 0x50000000;
      local_16c = param_1 + 0x4b008;
      do {
        if ((((byte)pMVar18[iVar2 * 28000 + 0x2c984] & 1) != 0) &&
           ((iVar5 = *(int *)(pMVar18 + iVar2 * 28000 + 0x2de08), iVar5 == 0x400 || (iVar5 != 0x401)
            ))) {
          if (iVar5 == 0x401) {
            pMVar31 = param_1 + 0x1487c;
          }
          if (iVar5 != 0x401) {
            pMVar31 = pMVar18;
          }
          fVar23 = (*(float *)(local_168 + 0x2c) +
                   -*(float *)(pMVar18 + iVar2 * 28000 + 0x2c9a4) * *(float *)(local_168 + 0x28)) /
                   (*(float *)(local_168 + 0x3c) +
                   -*(float *)(pMVar18 + iVar2 * 28000 + 0x2c9a4) * *(float *)(local_168 + 0x38));
          fVar21 = -1.0;
          if (((uint)fVar23 < 0xbf800001) && (fVar21 = fVar23, 0.0 < fVar23)) {
            fVar21 = 0.0;
          }
          uVar6 = local_170 | 0x87800000;
          uVar10 = VectorFloatToUnsigned((fVar21 + 1.0) * 16777215.0,3);
          local_164 = 0.0;
          puVar8 = (undefined1 *)FUN_11800888(pMVar14);
          uVar3 = (**(code **)(**(int **)local_16c + 0x10))();
          *puVar8 = 5;
          *(undefined4 *)(puVar8 + 0x18) = uVar3;
          *(MComSys **)(puVar8 + 8) = pMVar18 + iVar2 * 28000 + 0x27148;
          *(uint *)(puVar8 + 4) = (uVar10 & 0xffffff) << 3 | uVar6 & 0xf8000000 | 5;
          *(MComSys **)(puVar8 + 0xc) = pMVar31;
          *(float *)(puVar8 + 0x10) = local_164;
          *(undefined4 *)(puVar8 + 0x14) = 0;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < (int)(uint)(byte)param_1[0x43ab4]);
    }
    for (pMVar31 = *(MComSys **)(param_1 + 0xe64dc); pMVar31 != param_1 + 0xe64d8;
        pMVar31 = *(MComSys **)(pMVar31 + 4)) {
      if (pMVar31[0x13d] != (MComSys)0x0) {
        (**(code **)(*(int *)(pMVar31 + -4) + 0x14))(pMVar31 + -4,pMVar14,10);
        for (pMVar18 = *(MComSys **)(pMVar31 + 0x144); pMVar18 != pMVar31 + 0x140;
            pMVar18 = *(MComSys **)(pMVar18 + 4)) {
          FUN_1180b784(pMVar18 + -4,pMVar14,10);
        }
      }
    }
    iVar2 = msys::MComSys::getNextPage(param_1);
    if (iVar2 != 0) {
      piVar9 = (int *)msys::MComSys::getNextPage(param_1);
      (**(code **)(*piVar9 + 0x1c))(piVar9,param_2,pMVar14);
    }
    (**(code **)(**(int **)(param_1 + (char)param_1[(char)param_1[0xfd7] + 0xfcd] * 4 + 0xf8c) +
                0x1c))(*(int **)(param_1 + (char)param_1[(char)param_1[0xfd7] + 0xfcd] * 4 + 0xf8c),
                       param_2,pMVar14);
    piVar9 = *(int **)(param_1 + 0x4af48);
    piVar17 = *(int **)(param_1 + 0x4af4c);
    if (piVar9 != piVar17) {
      FUN_1180bb84(piVar9,piVar17,(int)piVar17 - (int)piVar9 >> 2);
      piVar19 = piVar9;
      if ((int)piVar17 - (int)piVar9 < 0x41) {
        while (piVar1 = piVar19 + 1, piVar1 != piVar17) {
          iVar2 = *piVar1;
          piVar12 = piVar1;
          if (*(uint *)(iVar2 + 4) < *(uint *)(*piVar9 + 4)) {
            piVar19 = piVar19 + 2;
            if (piVar9 < piVar1) {
              if (0 < (int)piVar1 - (int)piVar9) {
                iVar5 = (int)piVar1 - (int)piVar9 >> 2;
                iVar7 = 0;
                do {
                  iVar5 = iVar5 + -1;
                  piVar19[iVar7 + -1] = piVar1[iVar7 + -1];
                  iVar7 = iVar7 + -1;
                } while (iVar5 != 0);
              }
            }
            else {
              while (piVar9 != piVar12) {
                piVar19 = piVar19 + -1;
                *piVar19 = piVar12[-1];
                piVar12 = piVar12 + -1;
              }
            }
            *piVar9 = iVar2;
            piVar19 = piVar1;
          }
          else {
            while( true ) {
              if (*(uint *)(piVar12[-1] + 4) <= *(uint *)(iVar2 + 4)) break;
              *piVar12 = piVar12[-1];
              piVar12 = piVar12 + -1;
            }
            *piVar12 = iVar2;
            piVar19 = piVar1;
          }
        }
      }
      else {
        while (piVar1 = piVar19 + 1, piVar1 != piVar9 + 0x10) {
          iVar2 = *piVar1;
          piVar12 = piVar1;
          if (*(uint *)(iVar2 + 4) < *(uint *)(*piVar9 + 4)) {
            piVar19 = piVar19 + 2;
            if (piVar9 < piVar1) {
              if (0 < (int)piVar1 - (int)piVar9) {
                iVar5 = (int)piVar1 - (int)piVar9 >> 2;
                iVar7 = 0;
                do {
                  iVar5 = iVar5 + -1;
                  piVar19[iVar7 + -1] = piVar1[iVar7 + -1];
                  iVar7 = iVar7 + -1;
                } while (iVar5 != 0);
              }
            }
            else {
              while (piVar9 != piVar12) {
                piVar19 = piVar19 + -1;
                *piVar19 = piVar12[-1];
                piVar12 = piVar12 + -1;
              }
            }
            *piVar9 = iVar2;
            piVar19 = piVar1;
          }
          else {
            while( true ) {
              iVar5 = piVar12[-1];
              if (*(uint *)(iVar5 + 4) <= *(uint *)(iVar2 + 4)) break;
              *piVar12 = iVar5;
              piVar12 = piVar12 + -1;
            }
            *piVar12 = iVar2;
            piVar19 = piVar1;
          }
        }
        for (piVar9 = piVar9 + 0x10; piVar9 != piVar17; piVar9 = piVar9 + 1) {
          iVar2 = *piVar9;
          piVar19 = piVar9;
          while( true ) {
            if (*(uint *)(piVar19[-1] + 4) <= *(uint *)(iVar2 + 4)) break;
            *piVar19 = piVar19[-1];
            piVar19 = piVar19 + -1;
          }
          *piVar19 = iVar2;
        }
      }
    }
    uVar6 = 0xff;
    piVar9 = *(int **)(param_1 + 0x4b00c);
    pMVar14 = param_1 + 0x4af54;
    *(undefined2 *)(param_1 + 0x4af58) = 0xfffe;
    *(undefined2 *)(param_1 + 0x4af5a) = 0xfffe;
    piVar17 = *(int **)(param_1 + 0x4af48);
    piVar19 = *(int **)(param_1 + 0x4af4c);
    if (piVar17 != piVar19) {
      do {
        uVar10 = (uint)*(byte *)*piVar17;
        if (uVar10 == uVar6) {
          if ((uVar10 == 6) && (iVar2 = *(int *)((byte *)*piVar17 + 8), iVar2 != 0xff)) {
            *(char *)(piVar9 + 2) = (char)iVar2;
            if (uVar6 != 0xff) {
              (**(code **)(*piVar9 + 0xc))(piVar9,param_2);
            }
            (**(code **)(*piVar9 + 8))(piVar9,param_2,uVar6,pMVar14);
          }
        }
        else {
          if (uVar6 != 0xff) {
            (**(code **)(**(int **)(param_1 + uVar6 * 4 + 0x4aff4) + 0xc))
                      (*(int **)(param_1 + uVar6 * 4 + 0x4aff4),param_2);
          }
          (**(code **)(**(int **)(param_1 + uVar10 * 4 + 0x4aff4) + 8))
                    (*(int **)(param_1 + uVar10 * 4 + 0x4aff4),param_2,uVar6,pMVar14);
          uVar6 = uVar10;
        }
        (**(code **)(*piVar17 + 0x18))
                  (param_2,*piVar17,*(undefined4 *)(param_1 + uVar6 * 4 + 0x4aff4),pMVar14);
        piVar17 = piVar17 + 1;
      } while (piVar17 != piVar19);
      if (uVar6 != 0xff) {
        (**(code **)(**(int **)(param_1 + uVar6 * 4 + 0x4aff4) + 0xc))
                  (*(int **)(param_1 + uVar6 * 4 + 0x4aff4),param_2);
      }
    }
  }
  local_174 = *(undefined4 *)(param_1 + 0x4acd8);
  ad::SimpleRectDrawer::draw((SimpleRectDrawer *)(param_1 + 0x4acc8),param_2,&local_174,1);
  return;
}


// FUNC 0x1180adec FUN_1180adec (Colosseum)
//   size 0x258 | file Colosseum+0xadec | callers(0) | datarefs 1

void FUN_1180adec(MComSys *param_1)

{
  int iVar1;
  IAllocator *pIVar2;
  wchar_t *pwVar3;
  void *pvVar4;
  undefined4 uVar5;
  int iVar6;
  uint in_r12;
  bool bVar7;
  ulonglong uVar8;
  void *apvStackY_238 [128];
  uint uVar9;
  uint local_20 [2];
  
  iVar6 = *(int *)(param_1 + 0x278);
  iVar1 = iVar6;
  while( true ) {
    bVar7 = iVar1 != iVar6 + 0x1f8;
    if (bVar7) {
      in_r12 = (uint)*(byte *)(iVar1 + 4);
    }
    if (!bVar7 || in_r12 == 0) break;
    iVar1 = iVar1 + 0xa8;
  }
  if (iVar1 == iVar6 + 0x1f8) {
    iVar1 = ad::lyt::LytDrawSys::GetInst();
    pIVar2 = (IAllocator *)(iVar1 + 0x5f4);
    if (ad::lyt::Layout::s_pAllocator != pIVar2) {
      ad::lyt::Initialize(pIVar2,pIVar2);
    }
    *(MComSys **)(iVar1 + 0x5f8) = param_1 + 0xc;
    iVar1 = ad::lyt::LytDrawSys::GetInst();
    *(undefined4 *)(iVar1 + 0x5fc) = 0x10000;
    (**(code **)(**(int **)(*(int *)(param_1 + 0xe64f0) + 0x44) + 0xc))
              (*(int **)(*(int *)(param_1 + 0xe64f0) + 0x44),"MDFXMenuArchive");
    msys::MComSys::readLytNum
              (param_1,(FileContext *)(*(int *)(param_1 + 0x278) + 0x150),(MemAlcBase *)0x0);
    ad::fw::TaskBase::readLyt
              (*(TaskBase **)(param_1 + 4),(Resource *)(param_1 + 0xe90e0),
               (FileContext *)(*(int *)(param_1 + 0x278) + 0x150),"SQ_CURSOR_SET",
               (MemAlcBase *)(param_1 + 0xc),0x7f,(ResCacheArg *)0x0);
    pwVar3 = operator_new__(0x200,(MemAlcBase *)(param_1 + 0xc),(char *)0x0,0x800000);
    MessageSys::GetPath(pwVar3,(wchar_t *)L"Menu.msbt",false);
    uVar9 = 0;
    uVar8 = nn::fs::CTR::MPCore::detail::UserFileSystem::TryOpenFile(apvStackY_238 + 0x81,pwVar3,1);
    uVar5 = (undefined4)(uVar8 >> 0x20);
    bVar7 = (uVar8 & 0x80000000) != 0;
    if (bVar7) {
      uVar5 = 0x1180af48;
    }
    if (bVar7 && (int)uVar8 < 0) {
      nn::err::CTR::ThrowFatalErrAll((int)uVar8,uVar5);
    }
    iVar1 = nn::fs::detail::FileBase::TryGetSize
                      ((FileBase *)(apvStackY_238 + 0x81),(longlong *)local_20);
    if (iVar1 < 0) {
      nn::err::CTR::ThrowFatalErrAll(iVar1,0x1180af78);
    }
    pvVar4 = (void *)(**(code **)(*(int *)(param_1 + 0xc) + 0xc))(param_1 + 0xc,local_20[0],0);
    *(void **)(param_1 + 0xe904c) = pvVar4;
    iVar1 = nn::fs::detail::FileBase::TryRead
                      ((FileBase *)(apvStackY_238 + 0x81),(int *)local_20,pvVar4,local_20[0]);
    if (iVar1 < 0) {
      nn::err::CTR::ThrowFatalErrAll(iVar1,0x1180afbc);
    }
    MsgDataAcsrBase::init((MsgDataAcsrBase *)(param_1 + 0xe9050),*(void **)(param_1 + 0xe904c));
    if ((uVar9 & 0xfffffffe) != 0) {
      if ((uVar9 & 1) != 0) {
        nndbgPanic();
      }
      nn::fs::CTR::MPCore::detail::UserFileSystem::CloseFile((void *)(uVar9 & 0xfffffffe));
      uVar9 = 0;
    }
    if ((uVar9 & 0xfffffffe) != 0) {
      if ((uVar9 & 1) != 0) {
        nndbgPanic();
      }
      nn::fs::CTR::MPCore::detail::UserFileSystem::CloseFile((void *)(uVar9 & 0xfffffffe));
    }
    operator_delete__(pwVar3);
    *(code **)(param_1 + 0xf84) = FUN_1180b088;
    *(undefined4 *)(param_1 + 0xf88) = 0;
  }
  return;
}


// FUNC 0x1180b088 FUN_1180b088 (Colosseum)
//   size 0x14c | file Colosseum+0xb088 | callers(0) | datarefs 2

void FUN_1180b088(int param_1)

{
  int iVar1;
  void *pvVar2;
  int *piVar3;
  int *piVar4;
  undefined4 *puVar5;
  
  if ((*(char *)(param_1 + 0x848) != '\0') &&
     (iVar1 = (**(code **)(**(int **)(*(int *)(param_1 + 0xe64f0) + 0x44) + 0x10))(), iVar1 == 0)) {
    ad::lyt::LytResourceMan::init((LytResourceMan *)(param_1 + 2000));
    pvVar2 = (void *)ad::fw::Resource::getFileData((Resource *)(param_1 + 0x844));
    ad::lyt::LytResourceMan::registerArc((LytResourceMan *)(param_1 + 2000),pvVar2,".");
    pvVar2 = (void *)ad::fw::Resource::getFileData((Resource *)(param_1 + 0xe90e0));
    ad::lyt::LytResourceMan::registerArc((LytResourceMan *)(param_1 + 2000),pvVar2,".");
    msys::MLytNumRes::init((MLytNumRes *)(param_1 + 0x844),(LytResourceMan *)(param_1 + 2000),5);
    msys::MLyt::init((MLyt *)(param_1 + 0xe9124),param_1 + 0xd3000,0);
    msys::MLyt::createLyt
              ((MLyt *)(param_1 + 0xe9124),(LytResourceMan *)(param_1 + 2000),"SQ_CURSOR.bflyt");
    MoveVBase::stop((MoveVBase *)(param_1 + 0xe91f0));
    *(undefined4 *)(param_1 + 0xe920c) = 0;
    *(undefined4 *)(param_1 + 0xe9210) = 0;
    *(undefined4 *)(param_1 + 0xe9214) = 0xc347cccd;
    piVar4 = (int *)(param_1 + 0xe64e0);
    *(undefined4 *)(param_1 + 0xe91f4) = *(undefined4 *)(param_1 + 0xe920c);
    *(undefined4 *)(param_1 + 0xe91f8) = 0;
    *(undefined4 *)(param_1 + 0xe91fc) = 0xc347cccd;
    *(undefined1 *)(param_1 + 0xe9265) = 0;
    *(undefined4 *)(param_1 + 0xe9260) = 0x401;
    puVar5 = *(undefined4 **)(param_1 + 0xe912c);
    *(undefined4 **)(*(int *)(param_1 + 0xe9128) + 4) = puVar5;
    *puVar5 = *(undefined4 *)(param_1 + 0xe9128);
    piVar3 = (int *)(param_1 + 0xe9128);
    if (piVar3 != (int *)0x0) {
      *(int **)(param_1 + 0xe912c) = piVar4;
      *piVar3 = *piVar4;
      *(int **)(*piVar4 + 4) = piVar3;
      *piVar4 = (int)piVar3;
    }
    *(code **)(param_1 + 0xf84) = FUN_1180b200;
    *(undefined4 *)(param_1 + 0xf88) = 0;
  }
  return;
}


// FUNC 0x1180b200 FUN_1180b200 (Colosseum)
//   size 0xb4 | file Colosseum+0xb200 | callers(0) | datarefs 2

void FUN_1180b200(int param_1)

{
  int *piVar1;
  undefined4 local_18;
  
  piVar1 = *(int **)(param_1 + *(char *)((int)*(char *)(param_1 + 0xfd7) + param_1 + 0xfcd) * 4 +
                    0xf8c);
  (**(code **)(*piVar1 + 8))(piVar1,0xffffffff);
  if ((char)piVar1[5] != '\0') {
    local_18 = 0;
    MoveC::moveFrm((MoveC *)(param_1 + 0x4acd4),(Color8 *)&local_18,16.0);
    MoveC::moveFrm((MoveC *)(param_1 + 0x4ad14),(Color8 *)&local_18,16.0);
    *(undefined1 *)(param_1 + 0x4af14) = 1;
    *(code **)(param_1 + 0xf84) = FUN_1180a0a4;
    *(undefined4 *)(param_1 + 0xf88) = 0;
  }
  return;
}


// FUNC 0x1180b2c8 FUN_1180b2c8 (Colosseum)
//   size 0x16c | file Colosseum+0xb2c8 | callers(1) 0x1180a01c

void FUN_1180b2c8(MComSys *param_1,MTaskBase *param_2)

{
  Job *pJVar1;
  undefined4 uVar2;
  
  msys::MComSys::initBaseSys(param_1,param_2,0x200000,0x800000,0,0x100000,0x180000,3,'\0',false);
  msys::MComSys::entryPage(param_1,(MPageBase *)(param_1 + 0xe90bc));
  param_1[0xd30e0] = (MComSys)0x0;
  param_1[0xd30e1] = (MComSys)0x0;
  param_1[0xd30e2] = (MComSys)0x1;
  param_1[0xd2fe0] = (MComSys)0x1;
  param_1[0xd2fe1] = (MComSys)0x1;
  param_1[0xd2fe2] = (MComSys)0x1;
  param_1[0xbfb78] = (MComSys)0x1;
  Prim::enableDepthTest((Prim *)(param_1 + 0xac2d8),0,5);
  uVar2 = *(undefined4 *)(param_1 + 0x278);
  pJVar1 = operator_new(0x20,(MemAlcBase *)(param_2 + 0x55c),(char *)0x0,0);
  if (pJVar1 != (Job *)0x0) {
    *(undefined ***)pJVar1 = &vtable_for_N2ad2fw11FileContext7InitJobIPS1_EE;
    *(undefined4 *)(pJVar1 + 4) = 0;
    *(undefined4 *)(pJVar1 + 8) = uVar2;
    *(MComSys **)(pJVar1 + 0xc) = param_1 + 0xc;
    *(undefined **)(pJVar1 + 0x10) = &DAT_1180c398;
    *(undefined4 *)(pJVar1 + 0x14) = 3;
    uVar2 = *(undefined4 *)(param_2 + 0x4d8);
    *(undefined4 *)(pJVar1 + 0x18) = *(undefined4 *)(param_2 + 0x4d4);
    *(undefined4 *)(pJVar1 + 0x1c) = uVar2;
  }
  CtrJobMan::enqueue((CtrJobMan *)(param_2 + 0x4dc),pJVar1);
  *(code **)(param_1 + 0xf84) = FUN_1180adec;
  *(undefined4 *)(param_1 + 0xf88) = 0;
  msys::MComSys::setupCamU(param_1);
  msys::MComSys::setupCamL(param_1);
  param_1[0x4ad85] = (MComSys)0x1;
  param_1[0x4ae65] = (MComSys)0x1;
  return;
}


// FUNC 0x1180b454 FUN_1180b454 (Colosseum)
//   size 0xf4 | file Colosseum+0xb454 | callers(1) 0x1180a01c

int FUN_1180b454(MComSys *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar1 = (undefined4 *)msys::MComSys::MComSys(param_1);
  *puVar1 = &col::Colosseum::vtable;
  puVar1 = (undefined4 *)
           MsgDataAcsrBase::MsgDataAcsrBase
                     ((MsgDataAcsrBase *)(puVar1 + 0x3a414),(LMSBlockInfo *)(puVar1 + 0x3a41f),4);
  *puVar1 = &vtable_for_20MsgDataAcsrTmplFixedILh4EE;
  puVar2 = puVar1 + 0x1c;
  *puVar2 = puVar2;
  puVar1[0x1d] = puVar2;
  puVar1[0x1e] = puVar1 + 0x1e;
  puVar1[0x1f] = puVar1 + 0x1e;
  *(undefined1 *)(puVar1 + 0x20) = 0;
  puVar1[0x21] = 0;
  puVar1[0x1b] = &col::ColosseumPage::vtable;
  puVar1[0x22] = 0;
  puVar1[0x23] = 0;
  iVar3 = ad::fw::Resource::Resource((Resource *)(puVar1 + 0x24));
  puVar1 = (undefined4 *)FUN_118058e4(iVar3 + 0x44);
  *puVar1 = &msys::MLyt::vtable;
  *(undefined1 *)(puVar1 + 0x53) = 0xff;
  *(undefined2 *)((int)puVar1 + 0x14e) = 0;
  puVar1[0x54] = 0;
  iVar3 = __aeabi_vec_ctor_nocookie_nodtor(puVar1 + 0x55,FUN_1180588c,0x1c,0xc);
  iVar3 = __aeabi_vec_ctor_nocookie_nodtor(iVar3 + 0x15c,&LAB_118012ac,0x10,0xc);
  *(undefined4 *)(iVar3 + 0xc0) = 0;
  *(undefined1 *)(iVar3 + 0xc4) = 1;
  *(undefined4 *)(iVar3 + 200) = 0;
  *(undefined4 *)(iVar3 + 0xcc) = 0;
  *(undefined1 *)(iVar3 + 0xd0) = 0;
  *(undefined4 *)(iVar3 + 0xd4) = 0;
  *(undefined4 *)(iVar3 + 0xd8) = 0;
  FUN_118058c8(iVar3 + -0xc,0xffffffff);
  return iVar3 + -0xe93d4;
}


// FUNC 0x1180b560 col::Colosseum::vfunc_0x4 (Colosseum)
//   size 0x10 | file Colosseum+0xb560 | callers(0) | datarefs 1

void col::Colosseum::vfunc_0x4(void)

{
  void *pvVar1;
  
  pvVar1 = (void *)vfunc_0x0();
  operator_delete(pvVar1);
  return;
}


// FUNC 0x1180b570 col::ColosseumTask::vfunc_0xc (Colosseum)
//   size 0xc | file Colosseum+0xb570 | callers(0) | datarefs 1

void col::ColosseumTask::vfunc_0xc(int *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x1180b578. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 8))();
  return;
}


// FUNC 0x1180b57c FUN_1180b57c (Colosseum)
//   size 0x30 | file Colosseum+0xb57c | callers(0) | datarefs 1

int FUN_1180b57c(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)FUN_118058e4();
  *puVar1 = &msys::MCellAnime::vtable;
  iVar2 = CellAnime::CellAnime((CellAnime *)(puVar1 + 0x53));
  *(undefined1 *)(iVar2 + 300) = 0xff;
  *(undefined1 *)(iVar2 + 0x12d) = 0xff;
  *(undefined1 *)(iVar2 + 0x12e) = 0xff;
  *(undefined1 *)(iVar2 + 0x12f) = 0xff;
  return iVar2 + -0x14c;
}


// FUNC 0x1180b5d0 msys::MChrBase::vfunc_0x10 (Colosseum)
//   size 0xc | file Colosseum+0xb5d0 | callers(0) | datarefs 1

void msys::MChrBase::vfunc_0x10(int param_1)

{
  *(undefined1 *)(param_1 + 0x142) = 0;
  return;
}


// FUNC 0x1180b5dc FUN_1180b5dc (Colosseum)
//   size 0x4 | file Colosseum+0xb5dc | callers(0) | datarefs 2

void FUN_1180b5dc(void)

{
  return;
}


// FUNC 0x1180b5e0 msys::MChrBase::vfunc_0x8 (Colosseum)
//   size 0xc | file Colosseum+0xb5e0 | callers(0) | datarefs 1

void msys::MChrBase::vfunc_0x8(int param_1)

{
  *(undefined1 *)(param_1 + 0x142) = 1;
  return;
}


// FUNC 0x1180b5ec FUN_1180b5ec (Colosseum)
//   size 0x4 | file Colosseum+0xb5ec | callers(0) | datarefs 6

void FUN_1180b5ec(void)

{
  return;
}


// FUNC 0x1180b5f0 msys::MListWndPCore::vfunc_0x30 (Colosseum)
//   size 0x10 | file Colosseum+0xb5f0 | callers(0) | datarefs 1

void msys::MListWndPCore::vfunc_0x30(undefined4 param_1)

{
  FUN_11805688(param_1,0x110015);
  return;
}


// FUNC 0x1180b604 msys::MListWndPCore::vfunc_0x2c (Colosseum)
//   size 0x10 | file Colosseum+0xb604 | callers(0) | datarefs 1

void msys::MListWndPCore::vfunc_0x2c(undefined4 param_1)

{
  FUN_11805688(param_1,0x110015);
  return;
}


// FUNC 0x1180b618 msys::MListWndPCore::vfunc_0x34 (Colosseum)
//   size 0x10 | file Colosseum+0xb618 | callers(0) | datarefs 1

void msys::MListWndPCore::vfunc_0x34(undefined4 param_1)

{
  FUN_11805688(param_1,0x110015);
  return;
}


// FUNC 0x1180b62c msys::MListWndPCore::vfunc_0x38 (Colosseum)
//   size 0x10 | file Colosseum+0xb62c | callers(0) | datarefs 1

void msys::MListWndPCore::vfunc_0x38(undefined4 param_1)

{
  FUN_11805688(param_1,0x110015);
  return;
}


// FUNC 0x1180b640 msys::MListWndPCore::vfunc_0x3c (Colosseum)
//   size 0x10 | file Colosseum+0xb640 | callers(0) | datarefs 1

void msys::MListWndPCore::vfunc_0x3c(undefined4 param_1)

{
  FUN_11805688(param_1,0x110018);
  return;
}


// FUNC 0x1180b654 msys::MListWndPCore::vfunc_0x44 (Colosseum)
//   size 0x10 | file Colosseum+0xb654 | callers(0) | datarefs 1

void msys::MListWndPCore::vfunc_0x44(UIListWindowPlusLyt *param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)ad::ui::UIListWindowPlusLyt::~UIListWindowPlusLyt(param_1);
  operator_delete(pvVar1);
  return;
}


// FUNC 0x1180b664 ->ad::ui::UIListWindowPlusLyt::~UIListWindowPlusLyt (Colosseum)
//   size 0x4 | file Colosseum+0xb664 | callers(0) | datarefs 1
// veneer/thunk -> 0x0025a3fc ad::ui::UIListWindowPlusLyt::~UIListWindowPlusLyt (static)

// FUNC 0x1180b668 col::Colosseum::vfunc_0x14 (Colosseum)
//   size 0x8 | file Colosseum+0xb668 | callers(0) | datarefs 1

undefined4 col::Colosseum::vfunc_0x14(void)

{
  return 0;
}


// FUNC 0x1180b670 col::ColosseumPage::Core::MsgWnd::vfunc_0x20 (Colosseum)
//   size 0x8 | file Colosseum+0xb670 | callers(0) | datarefs 1

undefined4 col::ColosseumPage::Core::MsgWnd::vfunc_0x20(void)

{
  return 0;
}


// FUNC 0x1180b678 col::ColosseumPage::Core::MsgWnd::vfunc_0x8 (Colosseum)
//   size 0xd0 | file Colosseum+0xb678 | callers(0) | datarefs 1

void col::ColosseumPage::Core::MsgWnd::vfunc_0x8(float param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  iVar1 = (**(code **)(*param_2 + 0x24))(param_2);
  if (iVar1 != 0) {
    MoveVBase::update((MoveVBase *)(param_2 + 5),param_1);
    MoveVBase::update((MoveVBase *)(param_2 + 0x1c),param_1);
    MoveVBase::update((MoveVBase *)(param_2 + 0x33),param_1);
  }
  uVar2 = CtrBtn::get((CtrBtn *)&gBtn,0);
  uVar2 = uVar2 & 0xff00dffb;
  uVar3 = CtrBtn::get((CtrBtn *)&gBtn,2);
  uVar3 = uVar3 & 0xff00dffb;
  uVar4 = CtrBtn::get((CtrBtn *)&gBtn,4);
  uVar4 = uVar4 & 0xff00dffb;
  if (SUB41(param_2[0x50],0) == false) {
    uVar4 = 0;
    uVar3 = 0;
    uVar2 = 0;
  }
  Message::func((Message *)(param_2 + 0x53),uVar2,uVar3,uVar4,SUB41(param_2[0x50],0),param_1);
  *(undefined1 *)((int)param_2 + 0x142) = 1;
  return;
}


// FUNC 0x1180b750 col::ColosseumPage::Core::MsgWnd::vfunc_0x38 (Colosseum)
//   size 0x4 | file Colosseum+0xb750 | callers(0) | datarefs 1

void col::ColosseumPage::Core::MsgWnd::vfunc_0x38(void)

{
  return;
}


// FUNC 0x1180b754 col::ColosseumPage::Core::MsgWnd::vfunc_0x14 (Colosseum)
//   size 0x2c | file Colosseum+0xb754 | callers(0) | datarefs 1

void col::ColosseumPage::Core::MsgWnd::vfunc_0x14(int param_1,MRenderQueueBase *param_2)

{
  if (*(char *)(param_1 + 0x141) == '\0') {
    return;
  }
  msys::MRenderQueueBase::enqueueMsg
            (param_2,(MessageSimple *)(param_1 + 0x14c),*(uint *)(param_1 + 0x6ef4),'\n');
  return;
}


// FUNC 0x1180b784 FUN_1180b784 (Colosseum)
//   size 0x5c | file Colosseum+0xb784 | callers(2) 0x1180a158 0x1180b784

void FUN_1180b784(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  
  if (*(char *)((int)param_1 + 0x141) != '\0') {
    (**(code **)(*param_1 + 0x14))(param_1);
    for (piVar1 = (int *)param_1[0x52]; piVar1 != param_1 + 0x51; piVar1 = (int *)piVar1[1]) {
      FUN_1180b784(piVar1 + -1,param_2,param_3);
    }
  }
  return;
}


// FUNC 0x1180b7e0 msys::MChrBase::vfunc_0x4 (Colosseum)
//   size 0x10 | file Colosseum+0xb7e0 | callers(0) | datarefs 1

void msys::MChrBase::vfunc_0x4(void)

{
  void *pvVar1;
  
  pvVar1 = (void *)vfunc_0x0();
  operator_delete(pvVar1);
  return;
}


// FUNC 0x1180b7f0 FUN_1180b7f0 (Colosseum)
//   size 0x20 | file Colosseum+0xb7f0 | callers(0) | datarefs 1

void FUN_1180b7f0(undefined4 *param_1)

{
  int iVar1;
  void *pvVar2;
  
  *param_1 = &vtable_for_N4msys9MListWndPILi4EEE;
  iVar1 = ad::ui::UIListWindowPlusLyt::~UIListWindowPlusLyt((UIListWindowPlusLyt *)(param_1 + 0x7f))
  ;
  pvVar2 = (void *)msys::MListWndPBase::~MListWndPBase((MListWndPBase *)(iVar1 + -0x1fc));
  operator_delete(pvVar2);
  return;
}


// FUNC 0x1180b814 FUN_1180b814 (Colosseum)
//   size 0x1c | file Colosseum+0xb814 | callers(0) | datarefs 1

void FUN_1180b814(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &vtable_for_N4msys9MListWndPILi4EEE;
  iVar1 = ad::ui::UIListWindowPlusLyt::~UIListWindowPlusLyt((UIListWindowPlusLyt *)(param_1 + 0x7f))
  ;
  msys::MListWndPBase::~MListWndPBase((MListWndPBase *)(iVar1 + -0x1fc));
  return;
}


// FUNC 0x1180b834 FUN_1180b834 (Colosseum)
//   size 0x20 | file Colosseum+0xb834 | callers(0) | datarefs 1

void FUN_1180b834(undefined4 *param_1)

{
  int iVar1;
  void *pvVar2;
  
  *param_1 = &vtable_for_N4msys9MListWndPILi8EEE;
  iVar1 = ad::ui::UIListWindowPlusLyt::~UIListWindowPlusLyt((UIListWindowPlusLyt *)(param_1 + 0x7f))
  ;
  pvVar2 = (void *)msys::MListWndPBase::~MListWndPBase((MListWndPBase *)(iVar1 + -0x1fc));
  operator_delete(pvVar2);
  return;
}


// FUNC 0x1180b858 FUN_1180b858 (Colosseum)
//   size 0x1c | file Colosseum+0xb858 | callers(0) | datarefs 1

void FUN_1180b858(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &vtable_for_N4msys9MListWndPILi8EEE;
  iVar1 = ad::ui::UIListWindowPlusLyt::~UIListWindowPlusLyt((UIListWindowPlusLyt *)(param_1 + 0x7f))
  ;
  msys::MListWndPBase::~MListWndPBase((MListWndPBase *)(iVar1 + -0x1fc));
  return;
}


// FUNC 0x1180b878 col::ColosseumPage::vfunc_0x20 (Colosseum)
//   size 0x8 | file Colosseum+0xb878 | callers(0) | datarefs 1

void col::ColosseumPage::vfunc_0x20(MPageBase *param_1,undefined4 param_2,MRenderQueue *param_3)

{
  msys::MPageBase::enqueueLowerChr(param_1,param_3);
  return;
}


// FUNC 0x1180b880 col::ColosseumPage::vfunc_0x1c (Colosseum)
//   size 0x8 | file Colosseum+0xb880 | callers(0) | datarefs 1

void col::ColosseumPage::vfunc_0x1c(MPageBase *param_1,undefined4 param_2,MRenderQueue *param_3)

{
  msys::MPageBase::enqueueUpperChr(param_1,param_3);
  return;
}


// FUNC 0x1180b888 FUN_1180b888 (Colosseum)
//   size 0x34 | file Colosseum+0xb888 | callers(0) | datarefs 1

void FUN_1180b888(MoveVBase *param_1)

{
  void *pvVar1;
  
  *(undefined ***)param_1 = &vtable_for_5MoveVILj1EE;
  __aeabi_vec_dtor(param_1 + 0x30,MoveWorkF::~MoveWorkF,0x2c,1);
  pvVar1 = (void *)MoveVBase::~MoveVBase(param_1);
  operator_delete(pvVar1);
  return;
}


// FUNC 0x1180b8c4 FUN_1180b8c4 (Colosseum)
//   size 0x30 | file Colosseum+0xb8c4 | callers(0) | datarefs 1

void FUN_1180b8c4(MoveVBase *param_1)

{
  *(undefined ***)param_1 = &vtable_for_5MoveVILj1EE;
  __aeabi_vec_dtor(param_1 + 0x30,MoveWorkF::~MoveWorkF,0x2c,1);
  MoveVBase::~MoveVBase(param_1);
  return;
}


// FUNC 0x1180b8fc FUN_1180b8fc (Colosseum)
//   size 0x2c | file Colosseum+0xb8fc | callers(0) | datarefs 3

undefined4 * FUN_1180b8fc(MoveWorkF *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)MoveWorkF::MoveWorkF(param_1);
  *puVar1 = &MoveWorkV::vtable;
  puVar1[8] = 0;
  puVar1[9] = 0;
  puVar1[10] = 0;
  return puVar1;
}


// FUNC 0x1180b930 MoveWorkV::vfunc_0x4 (Colosseum)
//   size 0x10 | file Colosseum+0xb930 | callers(0) | datarefs 1

void MoveWorkV::vfunc_0x4(MoveWorkF *param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)MoveWorkF::~MoveWorkF(param_1);
  operator_delete(pvVar1);
  return;
}


// FUNC 0x1180b940 ->MoveWorkF::~MoveWorkF (Colosseum)
//   size 0x4 | file Colosseum+0xb940 | callers(0) | datarefs 6
// veneer/thunk -> 0x00340694 MoveWorkF::~MoveWorkF (static)

// FUNC 0x1180b944 nn::fs::FileInputStream::vfunc_0x20 (Colosseum)
//   size 0x8 | file Colosseum+0xb944 | callers(0) | datarefs 1

void nn::fs::FileInputStream::vfunc_0x20(int param_1,longlong *param_2)

{
  detail::FileBase::TryGetSize((FileBase *)(param_1 + 4),param_2);
  return;
}


// FUNC 0x1180b94c nn::fs::FileInputStream::vfunc_0x14 (Colosseum)
//   size 0x8 | file Colosseum+0xb94c | callers(0) | datarefs 1

undefined8 nn::fs::FileInputStream::vfunc_0x14(int param_1)

{
  return *(undefined8 *)(param_1 + 8);
}


// FUNC 0x1180b954 nn::fs::FileInputStream::vfunc_0x10 (Colosseum)
//   size 0x14 | file Colosseum+0xb954 | callers(0) | datarefs 1

undefined4 nn::fs::FileInputStream::vfunc_0x10(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 0xc);
  *param_2 = *(undefined4 *)(param_1 + 8);
  param_2[1] = uVar1;
  return 0;
}


// FUNC 0x1180b968 nn::fs::FileInputStream::vfunc_0x24 (Colosseum)
//   size 0x2c | file Colosseum+0xb968 | callers(0) | datarefs 1

longlong nn::fs::FileInputStream::vfunc_0x24(int param_1)

{
  int iVar1;
  longlong local_10;
  
  iVar1 = detail::FileBase::TryGetSize((FileBase *)(param_1 + 4),&local_10);
  if (iVar1 < 0) {
    err::CTR::ThrowFatalErrAll(iVar1,0x1180b984);
  }
  return local_10;
}


// FUNC 0x1180b994 FUN_1180b994 (Colosseum)
//   size 0x2c | file Colosseum+0xb994 | callers(0) | datarefs 1

bool FUN_1180b994(int *param_1,uint param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 8))();
  return (uVar1 & param_3) == param_2;
}


// FUNC 0x1180b9c0 FUN_1180b9c0 (Colosseum)
//   size 0x8 | file Colosseum+0xb9c0 | callers(0) | datarefs 1

undefined4 FUN_1180b9c0(void)

{
  return 0;
}


// FUNC 0x1180b9c8 col::ColosseumPage::Core::vfunc_0x8 (Colosseum)
//   size 0x10 | file Colosseum+0xb9c8 | callers(0) | datarefs 1

bool col::ColosseumPage::Core::vfunc_0x8(undefined4 param_1,int param_2)

{
  return *(char *)(param_2 + 0x12) != '\0';
}


// FUNC 0x1180b9d8 FUN_1180b9d8 (Colosseum)
//   size 0x8 | file Colosseum+0xb9d8 | callers(0) | datarefs 4

undefined4 FUN_1180b9d8(void)

{
  return 2;
}


// FUNC 0x1180b9e0 col::ColosseumPage::Core::MsgWnd::vfunc_0x1c (Colosseum)
//   size 0x8 | file Colosseum+0xb9e0 | callers(0) | datarefs 1

undefined4 col::ColosseumPage::Core::MsgWnd::vfunc_0x1c(void)

{
  return 7;
}


// FUNC 0x1180b9e8 Colosseum::nnroControlObject_ (Colosseum)
//   size 0x74 | file Colosseum+0xb9e8 | callers(0)

undefined4 Colosseum::nnroControlObject_(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined *puVar2;
  
  switch(param_2) {
  case 0:
    uVar1 = 0;
    break;
  case 1:
    DAT_118144b8 = param_1;
    return 0;
  case 2:
    uVar1 = DAT_118144b8;
    break;
  case 3:
    *param_1 = &DAT_1180bf2c;
    puVar2 = &DAT_1180bf2c;
    goto LAB_1180ba48;
  case 4:
    *param_1 = &DAT_1180d5c0;
    puVar2 = &DAT_1180d5c0;
LAB_1180ba48:
    param_1[1] = puVar2;
    return 0;
  default:
    return 0xd8e12c21;
  }
  *param_1 = uVar1;
  return 0;
}


// FUNC 0x1180ba94 FUN_1180ba94 (Colosseum)
//   size 0xac | file Colosseum+0xba94 | callers(0) | datarefs 1

void FUN_1180ba94(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  wchar_t *pwVar3;
  undefined4 *puVar4;
  
  pwVar3 = *(wchar_t **)(param_1 + 8);
  puVar2 = *(undefined4 **)(param_1 + 0x10);
  puVar4 = puVar2 + *(int *)(param_1 + 0x14) * 2;
  for (; puVar2 != puVar4; puVar2 = puVar2 + 2) {
    cVar1 = *(char *)(puVar2 + 1);
    if (cVar1 == '\x01') {
      ad::fw::FileContext::initSingleFile(pwVar3,SUB41(*puVar2,0));
    }
    else if (cVar1 == '\x12') {
      ad::fw::FileContext::initArcFile
                (pwVar3,(MemAlcBase *)*puVar2,SUB41(*(undefined4 *)(param_1 + 0xc),0));
    }
    else if (cVar1 == '\x13') {
      ad::fw::FileContext::initCAArcFile
                (pwVar3,(MemAlcBase *)*puVar2,*(DataAndSizeTmpl **)(param_1 + 0xc),
                 (bool)((char)param_1 + '\x18'));
    }
    pwVar3 = pwVar3 + 0x2a;
  }
  return;
}


// FUNC 0x1180bb40 ->operator.delete (Colosseum)
//   size 0x4 | file Colosseum+0xbb40 | callers(0) | datarefs 1
// veneer/thunk -> 0x00286514 operator.delete (static)

// FUNC 0x1180bb44 FUN_1180bb44 (Colosseum)
//   size 0x4 | file Colosseum+0xbb44 | callers(0) | datarefs 1

void FUN_1180bb44(void)

{
  return;
}


// FUNC 0x1180bb48 FUN_1180bb48 (Colosseum)
//   size 0x28 | file Colosseum+0xbb48 | callers(0) | datarefs 1

void FUN_1180bb48(float param_1,MCursorBase *param_2,MLyt *param_3)

{
  MCursorBase *pMVar1;
  int iVar2;
  
  msys::MCursorBase::init(param_2,param_3,param_1);
  iVar2 = 3;
  pMVar1 = param_2 + 0x30;
  do {
    iVar2 = iVar2 + -1;
    *(undefined4 *)pMVar1 = 0;
    pMVar1 = pMVar1 + 4;
  } while (iVar2 != 0);
  return;
}


// FUNC 0x1180bb70 FUN_1180bb70 (Colosseum)
//   size 0x10 | file Colosseum+0xbb70 | callers(0) | datarefs 1

void FUN_1180bb70(MCursorBase *param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)msys::MCursorBase::~MCursorBase(param_1);
  operator_delete(pvVar1);
  return;
}


// FUNC 0x1180bb80 ->msys::MCursorBase::~MCursorBase (Colosseum)
//   size 0x4 | file Colosseum+0xbb80 | callers(0) | datarefs 1
// veneer/thunk -> 0x00324600 msys::MCursorBase::~MCursorBase (static)

// FUNC 0x1180bb84 FUN_1180bb84 (Colosseum)
//   size 0x3a8 | file Colosseum+0xbb84 | callers(2) 0x1180a158 0x1180bb84

/* WARNING: Removing unreachable block (ram,0x1180bce8) */
/* WARNING: Removing unreachable block (ram,0x1180bd00) */
/* WARNING: Removing unreachable block (ram,0x1180bd1c) */
/* WARNING: Removing unreachable block (ram,0x1180bd34) */
/* WARNING: Removing unreachable block (ram,0x1180bd38) */
/* WARNING: Removing unreachable block (ram,0x1180bd50) */
/* WARNING: Removing unreachable block (ram,0x1180bd58) */
/* WARNING: Removing unreachable block (ram,0x1180bd68) */
/* WARNING: Removing unreachable block (ram,0x1180bd90) */
/* WARNING: Removing unreachable block (ram,0x1180bd98) */
/* WARNING: Removing unreachable block (ram,0x1180bd7c) */
/* WARNING: Removing unreachable block (ram,0x1180bdac) */
/* WARNING: Removing unreachable block (ram,0x1180bdb0) */
/* WARNING: Removing unreachable block (ram,0x1180bce0) */

void FUN_1180bb84(int *param_1,int *param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  bool bVar14;
  
  if ((int)param_2 - (int)param_1 < 0x41) {
    return;
  }
  do {
    if (param_3 == 0) {
      iVar6 = (int)param_2 - (int)param_1;
      iVar13 = iVar6 >> 2;
      if (7 < iVar6) {
        iVar9 = (iVar13 + -2) / 2;
        do {
          iVar10 = param_1[iVar9];
          iVar1 = iVar9;
          while( true ) {
            iVar7 = iVar1 * 2;
            iVar4 = iVar7 + 2;
            if (iVar13 <= iVar4) break;
            if (*(uint *)(param_1[iVar4] + 4) < *(uint *)(param_1[iVar7 + 1] + 4)) {
              iVar4 = iVar7 + 1;
            }
            param_1[iVar1] = param_1[iVar4];
            iVar1 = iVar4;
          }
          if (iVar4 == iVar13) {
            param_1[iVar1] = param_1[iVar7 + 1];
            iVar1 = iVar7 + 1;
          }
          while ((iVar7 = (iVar1 + -1) / 2, iVar9 < iVar1 &&
                 (*(uint *)(param_1[iVar7] + 4) < *(uint *)(iVar10 + 4)))) {
            param_1[iVar1] = param_1[iVar7];
            iVar1 = iVar7;
          }
          bVar14 = iVar9 != 0;
          if (bVar14) {
            iVar9 = iVar9 + -1;
          }
          param_1[iVar1] = iVar10;
        } while (bVar14);
      }
      while (4 < iVar6) {
        if (param_1 != param_2) {
          iVar10 = param_2[-1];
          iVar13 = (int)param_2 + (-4 - (int)param_1) >> 2;
          iVar6 = 0;
          param_2[-1] = *param_1;
          iVar1 = 2;
          iVar9 = iVar6;
          if (2 < iVar13) {
            do {
              iVar6 = iVar1;
              if (*(uint *)(param_1[iVar1] + 4) < *(uint *)(param_1[iVar1 + -1] + 4)) {
                iVar6 = iVar1 + -1;
              }
              param_1[iVar9] = param_1[iVar6];
              iVar1 = iVar6 * 2 + 2;
              iVar9 = iVar6;
            } while (iVar1 < iVar13);
          }
          if (iVar1 == iVar13) {
            param_1[iVar6] = param_1[iVar1 + -1];
            iVar6 = iVar1 + -1;
          }
          while ((iVar13 = (iVar6 + -1) / 2, 0 < iVar6 &&
                 (*(uint *)(param_1[iVar13] + 4) < *(uint *)(iVar10 + 4)))) {
            param_1[iVar6] = param_1[iVar13];
            iVar6 = iVar13;
          }
          param_1[iVar6] = iVar10;
        }
        param_2 = param_2 + -1;
        iVar6 = (int)param_2 - (int)param_1;
      }
      return;
    }
    piVar2 = param_1 + (((int)param_2 - (int)param_1 >> 2) - ((int)param_2 - (int)param_1 >> 0x1f)
                       >> 1);
    uVar11 = *(uint *)(*param_1 + 4);
    uVar5 = *(uint *)(*piVar2 + 4);
    uVar12 = *(uint *)(param_2[-1] + 4);
    if (uVar11 < uVar5) {
      if (uVar12 <= uVar5) {
        if (uVar12 <= uVar11) goto LAB_1180bea0;
LAB_1180beb0:
        piVar2 = param_2 + -1;
      }
    }
    else if (uVar11 < uVar12) {
LAB_1180bea0:
      piVar2 = param_1;
    }
    else if (uVar5 < uVar12) goto LAB_1180beb0;
    iVar13 = *piVar2;
    piVar2 = param_1;
    piVar8 = param_2;
    while( true ) {
      for (piVar3 = piVar2; *(uint *)(*piVar3 + 4) < *(uint *)(iVar13 + 4); piVar3 = piVar3 + 1) {
      }
      do {
        piVar8 = piVar8 + -1;
      } while (*(uint *)(iVar13 + 4) < *(uint *)(*piVar8 + 4));
      if (piVar8 <= piVar3) break;
      iVar6 = *piVar3;
      piVar2 = piVar3 + 1;
      *piVar3 = *piVar8;
      *piVar8 = iVar6;
    }
    param_3 = param_3 / 2;
    FUN_1180bb84(piVar3,param_2,param_3);
    param_2 = piVar3;
    if ((int)piVar3 - (int)param_1 < 0x41) {
      return;
    }
  } while( true );
}


