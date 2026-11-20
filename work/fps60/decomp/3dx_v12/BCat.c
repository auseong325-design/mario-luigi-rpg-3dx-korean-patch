// fps60 TG decompiled C: 3dx_v12.code.bin module BCat part 1 (Ghidra 12.2, ARM:LE:32:v6:hardfp)
// Addresses: static = runtime address; CRO = fixed analysis base (crolink.py), NOT runtime.

// FUNC 0x10800180 ->operator.new (BCat)
//   size 0x4 | file BCat+0x180 | callers(3) 0x10800528 0x1080321c 0x108028fc
// veneer/thunk -> 0x00287d40 operator.new (static)

// FUNC 0x10800188 ->msys::MTaskBase::MTaskBase (BCat)
//   size 0x4 | file BCat+0x188 | callers(1) 0x10800528
// veneer/thunk -> 0x00334688 msys::MTaskBase::MTaskBase (static)

// FUNC 0x10800190 ->TaskMan::entry (BCat)
//   size 0x4 | file BCat+0x190 | callers(1) 0x10800528
// veneer/thunk -> 0x00287b18 TaskMan::entry (static)

// FUNC 0x10800198 ->MsgDataAcsrBase::~MsgDataAcsrBase (BCat)
//   size 0x4 | file BCat+0x198 | callers(3) 0x108005a4 0x108005b4 0x10801c1c
// veneer/thunk -> 0x0026fdb4 MsgDataAcsrBase::~MsgDataAcsrBase (static)

// FUNC 0x108001a0 ->operator.delete (BCat)
//   size 0x4 | file BCat+0x1a0 | callers(15) 0x108006b4 0x10801c1c 0x10803964 0x108005a4 0x10800760 0x108026e8 0x1080294c 0x10802ad0 ...
// veneer/thunk -> 0x00286514 operator.delete (static)

// FUNC 0x108001a8 ->ad::lyt::DrawInfo::DrawInfo (BCat)
//   size 0x4 | file BCat+0x1a8 | callers(1) 0x108005ec
// veneer/thunk -> 0x00264fd4 ad::lyt::DrawInfo::DrawInfo (static)

// FUNC 0x108001b0 ->nn::gr::CTR::RenderState::WBuffer::WBuffer (BCat)
//   size 0x4 | file BCat+0x1b0 | callers(1) 0x108005ec
// veneer/thunk -> 0x00264fa0 nn::gr::CTR::RenderState::WBuffer::WBuffer (static)

// FUNC 0x108001b8 ->ad::lyt::DrawInfo::~DrawInfo (BCat)
//   size 0x4 | file BCat+0x1b8 | callers(1) 0x10800664
// veneer/thunk -> 0x00164660 ad::lyt::DrawInfo::~DrawInfo (static)

// FUNC 0x108001c0 ->nn::fs::detail::FileBase::TrySetPosition (BCat)
//   size 0x4 | file BCat+0x1c0 | callers(2) 0x108006bc 0x108006e0
// veneer/thunk -> 0x0027ec28 nn::fs::detail::FileBase::TrySetPosition (static)

// FUNC 0x108001c8 ->nn::err::CTR::ThrowFatalErrAll (BCat)
//   size 0x4 | file BCat+0x1c8 | callers(5) 0x108006e8 0x1080379c 0x108006bc 0x10800714 0x10802d14
// veneer/thunk -> 0x00286530 nn::err::CTR::ThrowFatalErrAll (static)

// FUNC 0x108001d0 ->nn::fs::detail::FileBase::TryRead (BCat)
//   size 0x4 | file BCat+0x1d0 | callers(3) 0x108006e8 0x10800740 0x10802d14
// veneer/thunk -> 0x00286488 nn::fs::detail::FileBase::TryRead (static)

// FUNC 0x108001d8 ->nn::fs::detail::FileBase::TrySeek (BCat)
//   size 0x4 | file BCat+0x1d8 | callers(2) 0x10800714 0x10800748
// veneer/thunk -> 0x002854d0 nn::fs::detail::FileBase::TrySeek (static)

// FUNC 0x108001e0 ->nndbgPanic (BCat)
//   size 0x4 | file BCat+0x1e0 | callers(3) 0x10800760 0x108007a0 0x10802d14
// veneer/thunk -> 0x0028642c nndbgPanic (static)

// FUNC 0x108001e8 ->nn::fs::CTR::MPCore::detail::UserFileSystem::CloseFile (BCat)
//   size 0x4 | file BCat+0x1e8 | callers(3) 0x10800760 0x108007a0 0x10802d14
// veneer/thunk -> 0x00286410 nn::fs::CTR::MPCore::detail::UserFileSystem::CloseFile (static)

// FUNC 0x108001f0 ->ad::lyt::LytResourceMan::init (BCat)
//   size 0x4 | file BCat+0x1f0 | callers(4) 0x10803424 0x10801918 0x10800828 0x10802d14
// veneer/thunk -> 0x00250d1c ad::lyt::LytResourceMan::init (static)

// FUNC 0x108001f8 ->ad::fw::Resource::getFileData (BCat)
//   size 0x4 | file BCat+0x1f8 | callers(2) 0x10800828 0x10802d14
// veneer/thunk -> 0x00251d10 ad::fw::Resource::getFileData (static)

// FUNC 0x10800200 ->ad::lyt::LytResourceMan::registerArc (BCat)
//   size 0x4 | file BCat+0x200 | callers(2) 0x10800828 0x10802d14
// veneer/thunk -> 0x0015c910 ad::lyt::LytResourceMan::registerArc (static)

// FUNC 0x10800208 ->ad::fw::TaskBase::isFps30 (BCat)
//   size 0x4 | file BCat+0x208 | callers(1) 0x10800828
// veneer/thunk -> 0x0025edd0 ad::fw::TaskBase::isFps30 (static)

// FUNC 0x10800210 ->msys::MCursorBase::init (BCat)
//   size 0x4 | file BCat+0x210 | callers(2) 0x1080396c 0x10800828
// veneer/thunk -> 0x00324464 msys::MCursorBase::init (static)

// FUNC 0x10800218 ->msys::MLyt::init (BCat)
//   size 0x4 | file BCat+0x218 | callers(2) 0x10800828 0x10802d14
// veneer/thunk -> 0x0032c3a0 msys::MLyt::init (static)

// FUNC 0x10800220 ->msys::MLyt::createLyt (BCat)
//   size 0x4 | file BCat+0x220 | callers(2) 0x10800828 0x10802d14
// veneer/thunk -> 0x0032c78c msys::MLyt::createLyt (static)

// FUNC 0x10800228 ->MoveVBase::stop (BCat)
//   size 0x4 | file BCat+0x228 | callers(3) 0x10802158 0x10800828 0x10802d14
// veneer/thunk -> 0x00259dd8 MoveVBase::stop (static)

// FUNC 0x10800230 ->msys::MLyt::build (BCat)
//   size 0x4 | file BCat+0x230 | callers(1) 0x10800828
// veneer/thunk -> 0x0032c460 msys::MLyt::build (static)

// FUNC 0x10800238 ->msys::MLyt::createLyt (BCat)
//   size 0x4 | file BCat+0x238 | callers(1) 0x10800828
// veneer/thunk -> 0x0032c8c0 msys::MLyt::createLyt (static)

// FUNC 0x10800240 ->MessageSimple::init (BCat)
//   size 0x4 | file BCat+0x240 | callers(1) 0x10800828
// veneer/thunk -> 0x002736b4 MessageSimple::init (static)

// FUNC 0x10800248 ->__cxa_guard_acquire (BCat)
//   size 0x4 | file BCat+0x248 | callers(1) 0x10800828
// veneer/thunk -> 0x00288110 __cxa_guard_acquire (static)

// FUNC 0x10800250 ->__cxa_guard_release (BCat)
//   size 0x4 | file BCat+0x250 | callers(1) 0x10800828
// veneer/thunk -> 0x001018a8 __cxa_guard_release (static)

// FUNC 0x10800258 ->msys::MLyt::attachMChr (BCat)
//   size 0x4 | file BCat+0x258 | callers(1) 0x10800828
// veneer/thunk -> 0x00207468 msys::MLyt::attachMChr (static)

// FUNC 0x10800260 ->msys::MCellAnime::init (BCat)
//   size 0x4 | file BCat+0x260 | callers(1) 0x10800828
// veneer/thunk -> 0x002079d8 msys::MCellAnime::init (static)

// FUNC 0x10800268 ->CellAnime::play (BCat)
//   size 0x4 | file BCat+0x268 | callers(2) 0x10801670 0x10800828
// veneer/thunk -> 0x0027bee0 CellAnime::play (static)

// FUNC 0x10800270 ->ad::ctrl::ButtonGroup::FindButtonByName (BCat)
//   size 0x4 | file BCat+0x270 | callers(1) 0x10800828
// veneer/thunk -> 0x00256680 ad::ctrl::ButtonGroup::FindButtonByName (static)

// FUNC 0x10800278 ->ad::ctrl::AnimButton::SetStateChangeCallback (BCat)
//   size 0x4 | file BCat+0x278 | callers(1) 0x10800828
// veneer/thunk -> 0x00256674 ad::ctrl::AnimButton::SetStateChangeCallback (static)

// FUNC 0x10800280 ->RandSys::get (BCat)
//   size 0x4 | file BCat+0x280 | callers(3) 0x10801670 0x10802490 0x10800828
// veneer/thunk -> 0x00273054 RandSys::get (static)

// FUNC 0x10800288 ->Frm::setFrm (BCat)
//   size 0x4 | file BCat+0x288 | callers(1) 0x10800828
// veneer/thunk -> 0x00262180 Frm::setFrm (static)

// FUNC 0x10800290 ->GetRegFlag (BCat)
//   size 0x4 | file BCat+0x290 | callers(2) 0x10802490 0x10800828
// veneer/thunk -> 0x002762cc GetRegFlag (static)

// FUNC 0x10800298 ->msys::MLyt::getParts (BCat)
//   size 0x4 | file BCat+0x298 | callers(1) 0x10800828
// veneer/thunk -> 0x002073ec msys::MLyt::getParts (static)

// FUNC 0x108002a0 ->ad::lyt::LytAnim::init (BCat)
//   size 0x4 | file BCat+0x2a0 | callers(1) 0x10800828
// veneer/thunk -> 0x00264f04 ad::lyt::LytAnim::init (static)

// FUNC 0x108002a8 ->ad::lyt::LytAnim::stopAndSetFrm (BCat)
//   size 0x4 | file BCat+0x2a8 | callers(1) 0x10800828
// veneer/thunk -> 0x0026fe44 ad::lyt::LytAnim::stopAndSetFrm (static)

// FUNC 0x108002b0 ->ad::lyt::LytAnim::term (BCat)
//   size 0x4 | file BCat+0x2b0 | callers(1) 0x10800828
// veneer/thunk -> 0x00264e90 ad::lyt::LytAnim::term (static)

// FUNC 0x108002b8 ->msys::MLyt::playAnimeFromNo (BCat)
//   size 0x4 | file BCat+0x2b8 | callers(1) 0x10801120
// veneer/thunk -> 0x0032bf98 msys::MLyt::playAnimeFromNo (static)

// FUNC 0x108002c0 ->MoveC::moveFrm (BCat)
//   size 0x4 | file BCat+0x2c0 | callers(3) 0x108011e0 0x10802d14 0x10803148
// veneer/thunk -> 0x0026bc74 MoveC::moveFrm (static)

// FUNC 0x108002c8 ->msys::MLyt::isBusyAnime (BCat)
//   size 0x4 | file BCat+0x2c8 | callers(1) 0x108012ec
// veneer/thunk -> 0x0032bb14 msys::MLyt::isBusyAnime (static)

// FUNC 0x108002d0 ->msys::MComSys::getNextPage (BCat)
//   size 0x4 | file BCat+0x2d0 | callers(1) 0x108012ec
// veneer/thunk -> 0x0032db64 msys::MComSys::getNextPage (static)

// FUNC 0x108002d8 ->MemAlc::initCore (BCat)
//   size 0x4 | file BCat+0x2d8 | callers(1) 0x10801370
// veneer/thunk -> 0x002855b4 MemAlc::initCore (static)

// FUNC 0x108002e0 ->ad::lyt::LytDrawSys::GetInst (BCat)
//   size 0x4 | file BCat+0x2e0 | callers(3) 0x1080321c 0x10801370 0x10802d14
// veneer/thunk -> 0x00287f58 ad::lyt::LytDrawSys::GetInst (static)

// FUNC 0x108002e8 ->ad::lyt::Initialize (BCat)
//   size 0x4 | file BCat+0x2e8 | callers(3) 0x1080321c 0x10801370 0x10802d14
// veneer/thunk -> 0x002855e0 ad::lyt::Initialize (static)

// FUNC 0x108002f0 ->bcat::GetBootInfo (BCat)
//   size 0x4 | file BCat+0x2f0 | callers(1) 0x10801370
// veneer/thunk -> 0x00323d3c bcat::GetBootInfo (static)

// FUNC 0x108002f8 ->ad::TransMultiSymbol::init (BCat)
//   size 0x4 | file BCat+0x2f8 | callers(1) 0x10801370
// veneer/thunk -> 0x0026d7f8 ad::TransMultiSymbol::init (static)

// FUNC 0x10800300 ->BinGlu4Acs::getEntryAcs (BCat)
//   size 0x4 | file BCat+0x300 | callers(1) 0x10801370
// veneer/thunk -> 0x00285268 BinGlu4Acs::getEntryAcs (static)

// FUNC 0x10800308 ->ad::fw::TaskBase::readCA (BCat)
//   size 0x4 | file BCat+0x308 | callers(1) 0x10801370
// veneer/thunk -> 0x0026daf8 ad::fw::TaskBase::readCA (static)

// FUNC 0x10800310 ->ad::fw::TaskBase::readLyt (BCat)
//   size 0x4 | file BCat+0x310 | callers(2) 0x10801370 0x10802d14
// veneer/thunk -> 0x00249e48 ad::fw::TaskBase::readLyt (static)

// FUNC 0x10800318 ->msys::MLyt::isEnableAnime (BCat)
//   size 0x4 | file BCat+0x318 | callers(1) 0x10801878
// veneer/thunk -> 0x0032bc6c msys::MLyt::isEnableAnime (static)

// FUNC 0x10800320 ->msys::MCursorBase::setVisible (BCat)
//   size 0x4 | file BCat+0x320 | callers(1) 0x10801878
// veneer/thunk -> 0x00324454 msys::MCursorBase::setVisible (static)

// FUNC 0x10800328 ->ad::ctrl::ButtonGroup::ButtonGroup (BCat)
//   size 0x4 | file BCat+0x328 | callers(2) 0x10803424 0x10801918
// veneer/thunk -> 0x001667d8 ad::ctrl::ButtonGroup::ButtonGroup (static)

// FUNC 0x10800330 ->ad::font::ResFont::ResFont (BCat)
//   size 0x4 | file BCat+0x330 | callers(2) 0x10803424 0x10801918
// veneer/thunk -> 0x0027542c ad::font::ResFont::ResFont (static)

// FUNC 0x10800338 ->ad::fw::Resource::Resource (BCat)
//   size 0x4 | file BCat+0x338 | callers(2) 0x10803424 0x10801918
// veneer/thunk -> 0x00250588 ad::fw::Resource::Resource (static)

// FUNC 0x10800340 ->msys::MCursorBase::MCursorBase (BCat)
//   size 0x4 | file BCat+0x340 | callers(1) 0x10801918
// veneer/thunk -> 0x00324550 msys::MCursorBase::MCursorBase (static)

// FUNC 0x10800348 ->__aeabi_vec_ctor_nocookie_nodtor (BCat)
//   size 0x4 | file BCat+0x348 | callers(3) 0x10803424 0x1080206c 0x10801918
// veneer/thunk -> 0x0028771c __aeabi_vec_ctor_nocookie_nodtor (static)

// FUNC 0x10800350 ->CellAnime::CellAnime (BCat)
//   size 0x4 | file BCat+0x350 | callers(2) 0x10801918 0x10803618
// veneer/thunk -> 0x0026be18 CellAnime::CellAnime (static)

// FUNC 0x10800358 ->MessageSimple::MessageSimple (BCat)
//   size 0x4 | file BCat+0x358 | callers(1) 0x10801918
// veneer/thunk -> 0x0027ceec MessageSimple::MessageSimple (static)

// FUNC 0x10800360 ->CellAnime::term (BCat)
//   size 0x4 | file BCat+0x360 | callers(1) 0x108026f8
// veneer/thunk -> 0x00259f88 CellAnime::term (static)

// FUNC 0x10800368 ->msys::MLyt::term (BCat)
//   size 0x4 | file BCat+0x368 | callers(2) 0x10801c1c 0x108026f8
// veneer/thunk -> 0x0032c3c8 msys::MLyt::term (static)

// FUNC 0x10800370 ->ad::fw::Resource::term (BCat)
//   size 0x4 | file BCat+0x370 | callers(2) 0x10801e50 0x108026f8
// veneer/thunk -> 0x00233340 ad::fw::Resource::term (static)

// FUNC 0x10800378 ->MessageSimple::term (BCat)
//   size 0x4 | file BCat+0x378 | callers(1) 0x108026f8
// veneer/thunk -> 0x00137090 MessageSimple::term (static)

// FUNC 0x10800380 ->MessageSimple::~MessageSimple (BCat)
//   size 0x4 | file BCat+0x380 | callers(1) 0x108026f8
// veneer/thunk -> 0x00256578 MessageSimple::~MessageSimple (static)

// FUNC 0x10800388 ->__aeabi_vec_dtor (BCat)
//   size 0x4 | file BCat+0x388 | callers(5) 0x10801c1c 0x10801ef4 0x108026f8 0x108036b4 0x108036f0
// veneer/thunk -> 0x00288230 __aeabi_vec_dtor (static)

// FUNC 0x10800390 ->CellAnime::~CellAnime (BCat)
//   size 0x4 | file BCat+0x390 | callers(2) 0x108026f8 0x10803658
// veneer/thunk -> 0x0024fc94 CellAnime::~CellAnime (static)

// FUNC 0x10800398 ->ad::fw::Resource::~Resource (BCat)
//   size 0x4 | file BCat+0x398 | callers(3) 0x10801c1c 0x10801e50 0x108026f8
// veneer/thunk -> 0x0024a104 ad::fw::Resource::~Resource (static)

// FUNC 0x108003a0 ->msys::MCursorBase::~MCursorBase (BCat)
//   size 0x4 | file BCat+0x3a0 | callers(3) 0x108026f8 0x10803994 0x108039a4
// veneer/thunk -> 0x00324600 msys::MCursorBase::~MCursorBase (static)

// FUNC 0x108003a8 ->ad::fw::FileContext::term (BCat)
//   size 0x4 | file BCat+0x3a8 | callers(1) 0x10801c1c
// veneer/thunk -> 0x0013af88 ad::fw::FileContext::term (static)

// FUNC 0x108003b0 ->ad::fw::TaskBase::term (BCat)
//   size 0x4 | file BCat+0x3b0 | callers(1) 0x10801c1c
// veneer/thunk -> 0x0024a358 ad::fw::TaskBase::term (static)

// FUNC 0x108003b8 ->ad::ctrl::ButtonGroup::~ButtonGroup (BCat)
//   size 0x4 | file BCat+0x3b8 | callers(2) 0x10801c1c 0x10801e50
// veneer/thunk -> 0x00250928 ad::ctrl::ButtonGroup::~ButtonGroup (static)

// FUNC 0x108003c0 ->ad::lyt::LytResourceMan::term (BCat)
//   size 0x4 | file BCat+0x3c0 | callers(2) 0x10801c1c 0x10801e50
// veneer/thunk -> 0x00250938 ad::lyt::LytResourceMan::term (static)

// FUNC 0x108003c8 ->ad::font::ResFont::~ResFont (BCat)
//   size 0x4 | file BCat+0x3c8 | callers(2) 0x10801c1c 0x10801e50
// veneer/thunk -> 0x002508a8 ad::font::ResFont::~ResFont (static)

// FUNC 0x108003d0 ->msys::MComSys::~MComSys (BCat)
//   size 0x4 | file BCat+0x3d0 | callers(1) 0x10801c1c
// veneer/thunk -> 0x003300e8 msys::MComSys::~MComSys (static)

// FUNC 0x108003d8 ->ad::ctrl::ButtonGroup::FreeAll (BCat)
//   size 0x4 | file BCat+0x3d8 | callers(1) 0x10801e50
// veneer/thunk -> 0x002509d0 ad::ctrl::ButtonGroup::FreeAll (static)

// FUNC 0x108003e0 ->Mem::Free (BCat)
//   size 0x4 | file BCat+0x3e0 | callers(1) 0x10801e50
// veneer/thunk -> 0x00285d3c Mem::Free (static)

// FUNC 0x108003e8 ->MoveVBase::~MoveVBase (BCat)
//   size 0x4 | file BCat+0x3e8 | callers(3) 0x10801ef4 0x108036b4 0x108036f0
// veneer/thunk -> 0x002535e8 MoveVBase::~MoveVBase (static)

// FUNC 0x108003f0 ->MoveVBase::MoveVBase (BCat)
//   size 0x4 | file BCat+0x3f0 | callers(1) 0x1080206c
// veneer/thunk -> 0x00259740 MoveVBase::MoveVBase (static)

// FUNC 0x108003f8 ->strcmp (BCat)
//   size 0x4 | file BCat+0x3f8 | callers(1) 0x10802158
// veneer/thunk -> 0x002833b8 strcmp (static)

// FUNC 0x10800400 ->msys::MCtrlUserData::findExtUserDataByName (BCat)
//   size 0x4 | file BCat+0x400 | callers(1) 0x10802158
// veneer/thunk -> 0x0036203c msys::MCtrlUserData::findExtUserDataByName (static)

// FUNC 0x10800408 ->msys::MSndSe::play (BCat)
//   size 0x4 | file BCat+0x408 | callers(1) 0x108023f0
// veneer/thunk -> 0x0032d844 msys::MSndSe::play (static)

// FUNC 0x10800410 ->LMS_GetTextIndexByLabel (BCat)
//   size 0x4 | file BCat+0x410 | callers(1) 0x10802490
// veneer/thunk -> 0x0027616c LMS_GetTextIndexByLabel (static)

// FUNC 0x10800418 ->LMS_GetText (BCat)
//   size 0x4 | file BCat+0x418 | callers(1) 0x10802490
// veneer/thunk -> 0x0027660c LMS_GetText (static)

// FUNC 0x10800420 ->msys::MMsg::playStr (BCat)
//   size 0x4 | file BCat+0x420 | callers(1) 0x10802490
// veneer/thunk -> 0x0032ce0c msys::MMsg::playStr (static)

// FUNC 0x10800428 ->msys::MPageBase::updateInputAllChr (BCat)
//   size 0x4 | file BCat+0x428 | callers(1) 0x108029e8
// veneer/thunk -> 0x00334204 msys::MPageBase::updateInputAllChr (static)

// FUNC 0x10800430 ->ad::ctrl::ButtonGroup::Update (BCat)
//   size 0x4 | file BCat+0x430 | callers(1) 0x108029e8
// veneer/thunk -> 0x00250a40 ad::ctrl::ButtonGroup::Update (static)

// FUNC 0x10800438 ->VramAlcRange::merge (BCat)
//   size 0x4 | file BCat+0x438 | callers(1) 0x10802b74
// veneer/thunk -> 0x00102874 VramAlcRange::merge (static)

// FUNC 0x10800440 ->msys::MCamera::getProjMtx (BCat)
//   size 0x4 | file BCat+0x440 | callers(2) 0x10802cd0 0x10802c64
// veneer/thunk -> 0x00206718 msys::MCamera::getProjMtx (static)

// FUNC 0x10800448 ->msys::MCamera::getViewMtx (BCat)
//   size 0x4 | file BCat+0x448 | callers(1) 0x10802c64
// veneer/thunk -> 0x002068e4 msys::MCamera::getViewMtx (static)

// FUNC 0x10800450 ->ad::fw::TaskBase::setULcdCameraInfoBase (BCat)
//   size 0x4 | file BCat+0x450 | callers(1) 0x10802c64
// veneer/thunk -> 0x0010b438 ad::fw::TaskBase::setULcdCameraInfoBase (static)

// FUNC 0x10800458 ->ad::lyt::DrawInfo::SetProjectionMtx (BCat)
//   size 0x4 | file BCat+0x458 | callers(1) 0x10802c64
// veneer/thunk -> 0x0026510c ad::lyt::DrawInfo::SetProjectionMtx (static)

// FUNC 0x10800460 ->msys::MComSys::funcCalcMainNomal (BCat)
//   size 0x4 | file BCat+0x460 | callers(1) 0x10802c64
// veneer/thunk -> 0x0032f13c msys::MComSys::funcCalcMainNomal (static)

// FUNC 0x10800468 ->msys::MComSys::funcDrawLower (BCat)
//   size 0x4 | file BCat+0x468 | callers(1) 0x10802cd0
// veneer/thunk -> 0x0032e2b8 msys::MComSys::funcDrawLower (static)

// FUNC 0x10800470 ->msys::MComSys::funcDrawUpper (BCat)
//   size 0x4 | file BCat+0x470 | callers(1) 0x10802d10
// veneer/thunk -> 0x0032e760 msys::MComSys::funcDrawUpper (static)

// FUNC 0x10800478 ->MessageSys::GetPath (BCat)
//   size 0x4 | file BCat+0x478 | callers(1) 0x10802d14
// veneer/thunk -> 0x00132a2c MessageSys::GetPath (static)

// FUNC 0x10800480 ->nn::fs::CTR::MPCore::detail::UserFileSystem::TryOpenFile (BCat)
//   size 0x4 | file BCat+0x480 | callers(1) 0x10802d14
// veneer/thunk -> 0x0028598c nn::fs::CTR::MPCore::detail::UserFileSystem::TryOpenFile (static)

// FUNC 0x10800488 ->nn::fs::detail::FileBase::TryGetSize (BCat)
//   size 0x4 | file BCat+0x488 | callers(3) 0x1080379c 0x10803778 0x10802d14
// veneer/thunk -> 0x00286568 nn::fs::detail::FileBase::TryGetSize (static)

// FUNC 0x10800490 ->MsgDataAcsrBase::init (BCat)
//   size 0x4 | file BCat+0x490 | callers(1) 0x10802d14
// veneer/thunk -> 0x00285b88 MsgDataAcsrBase::init (static)

// FUNC 0x10800498 ->msys::MComSys::initBaseSys (BCat)
//   size 0x4 | file BCat+0x498 | callers(1) 0x1080321c
// veneer/thunk -> 0x0032db84 msys::MComSys::initBaseSys (static)

// FUNC 0x108004a0 ->msys::MComSys::entryPage (BCat)
//   size 0x4 | file BCat+0x4a0 | callers(1) 0x1080321c
// veneer/thunk -> 0x0032f548 msys::MComSys::entryPage (static)

// FUNC 0x108004a8 ->CtrJobMan::enqueue (BCat)
//   size 0x4 | file BCat+0x4a8 | callers(1) 0x1080321c
// veneer/thunk -> 0x0026dbe8 CtrJobMan::enqueue (static)

// FUNC 0x108004b0 ->Prim::disableDepthTest (BCat)
//   size 0x4 | file BCat+0x4b0 | callers(1) 0x1080321c
// veneer/thunk -> 0x00271c98 Prim::disableDepthTest (static)

// FUNC 0x108004b8 ->msys::MComSys::setupCamU (BCat)
//   size 0x4 | file BCat+0x4b8 | callers(1) 0x1080321c
// veneer/thunk -> 0x0032f674 msys::MComSys::setupCamU (static)

// FUNC 0x108004c0 ->msys::MComSys::setupCamL (BCat)
//   size 0x4 | file BCat+0x4c0 | callers(1) 0x1080321c
// veneer/thunk -> 0x0032f570 msys::MComSys::setupCamL (static)

// FUNC 0x108004c8 ->msys::MComSys::MComSys (BCat)
//   size 0x4 | file BCat+0x4c8 | callers(1) 0x10803424
// veneer/thunk -> 0x0032f7a4 msys::MComSys::MComSys (static)

// FUNC 0x108004d0 ->MsgDataAcsrBase::MsgDataAcsrBase (BCat)
//   size 0x4 | file BCat+0x4d0 | callers(1) 0x10803424
// veneer/thunk -> 0x0024b3b8 MsgDataAcsrBase::MsgDataAcsrBase (static)

// FUNC 0x108004d8 ->FrameBuf::setClearColor (BCat)
//   size 0x4 | file BCat+0x4d8 | callers(1) 0x10803424
// veneer/thunk -> 0x0024c8d4 FrameBuf::setClearColor (static)

// FUNC 0x108004e0 ->GameMain::Back (BCat)
//   size 0x4 | file BCat+0x4e0 | callers(1) 0x108035b0
// veneer/thunk -> 0x0033e354 GameMain::Back (static)

// FUNC 0x108004e8 ->ad::fw::TaskBase::~TaskBase (BCat)
//   size 0x4 | file BCat+0x4e8 | callers(2) 0x108035cc 0x108035f4
// veneer/thunk -> 0x0026d590 ad::fw::TaskBase::~TaskBase (static)

// FUNC 0x108004f0 ->msys::MPageBase::enqueueLowerChr (BCat)
//   size 0x4 | file BCat+0x4f0 | callers(1) 0x108036a4
// veneer/thunk -> 0x00334104 msys::MPageBase::enqueueLowerChr (static)

// FUNC 0x108004f8 ->msys::MPageBase::enqueueUpperChr (BCat)
//   size 0x4 | file BCat+0x4f8 | callers(1) 0x108036ac
// veneer/thunk -> 0x00334184 msys::MPageBase::enqueueUpperChr (static)

// FUNC 0x10800500 ->MoveWorkF::MoveWorkF (BCat)
//   size 0x4 | file BCat+0x500 | callers(1) 0x10803728
// veneer/thunk -> 0x00278cc0 MoveWorkF::MoveWorkF (static)

// FUNC 0x10800508 ->MoveWorkF::~MoveWorkF (BCat)
//   size 0x4 | file BCat+0x508 | callers(2) 0x1080375c 0x1080376c
// veneer/thunk -> 0x00340694 MoveWorkF::~MoveWorkF (static)

// FUNC 0x10800510 ->ad::fw::FileContext::initSingleFile (BCat)
//   size 0x4 | file BCat+0x510 | callers(1) 0x108038b8
// veneer/thunk -> 0x0013ad54 ad::fw::FileContext::initSingleFile (static)

// FUNC 0x10800518 ->ad::fw::FileContext::initArcFile (BCat)
//   size 0x4 | file BCat+0x518 | callers(1) 0x108038b8
// veneer/thunk -> 0x0013aca8 ad::fw::FileContext::initArcFile (static)

// FUNC 0x10800520 ->ad::fw::FileContext::initCAArcFile (BCat)
//   size 0x4 | file BCat+0x520 | callers(1) 0x108038b8
// veneer/thunk -> 0x0013acc0 ad::fw::FileContext::initCAArcFile (static)

// FUNC 0x10800528 BCat::EntryTask (BCat)
//   size 0x64 | file BCat+0x528 | callers(0)

void BCat::EntryTask(void)

{
  MTaskBase *this;
  undefined4 *puVar1;
  int iVar2;
  Task *pTVar3;
  
  this = operator_new(0xe9cec,gMemAlc,(char *)0x0,0);
  if (this == (MTaskBase *)0x0) {
    pTVar3 = (Task *)0x0;
  }
  else {
    puVar1 = (undefined4 *)msys::MTaskBase::MTaskBase(this);
    *puVar1 = &bcat::BCatTask::vtable;
    iVar2 = FUN_10803424(puVar1 + 0x161);
    pTVar3 = (Task *)(iVar2 + -0x584);
    FUN_1080321c(iVar2,pTVar3);
    *(int *)(iVar2 + -4) = iVar2;
  }
  TaskMan::entry((TaskMan *)&gTaskMainMan,pTVar3);
  return;
}


// FUNC 0x1080059c MemAlcH::vfunc_0x0 (BCat)
//   size 0x8 | file BCat+0x59c | callers(0) | datarefs 1

undefined4 MemAlcH::vfunc_0x0(void)

{
  return 0;
}


// FUNC 0x108005a4 FUN_108005a4 (BCat)
//   size 0x10 | file BCat+0x5a4 | callers(0) | datarefs 1

void FUN_108005a4(MsgDataAcsrBase *param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)MsgDataAcsrBase::~MsgDataAcsrBase(param_1);
  operator_delete(pvVar1);
  return;
}


// FUNC 0x108005b4 ->MsgDataAcsrBase::~MsgDataAcsrBase (BCat)
//   size 0x4 | file BCat+0x5b4 | callers(0) | datarefs 1
// veneer/thunk -> 0x0026fdb4 MsgDataAcsrBase::~MsgDataAcsrBase (static)

// FUNC 0x108005b8 FUN_108005b8 (BCat)
//   size 0xc | file BCat+0x5b8 | callers(0) | datarefs 1

void FUN_108005b8(int *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x108005c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x14))();
  return;
}


// FUNC 0x108005c4 bcat::BCatTask::vfunc_0x1c (BCat)
//   size 0x4 | file BCat+0x5c4 | callers(0) | datarefs 1

void bcat::BCatTask::vfunc_0x1c(void)

{
  return;
}


// FUNC 0x108005c8 bcat::BCatTask::vfunc_0x4c (BCat)
//   size 0x8 | file BCat+0x5c8 | callers(0) | datarefs 1

undefined4 * bcat::BCatTask::vfunc_0x4c(void)

{
  return &gFrameBuf;
}


// FUNC 0x108005d4 bcat::BCatTask::vfunc_0x3c (BCat)
//   size 0x4 | file BCat+0x5d4 | callers(0) | datarefs 1

void bcat::BCatTask::vfunc_0x3c(void)

{
  return;
}


// FUNC 0x108005d8 bcat::BCatTask::vfunc_0x40 (BCat)
//   size 0x4 | file BCat+0x5d8 | callers(0) | datarefs 1

void bcat::BCatTask::vfunc_0x40(void)

{
  return;
}


// FUNC 0x108005dc bcat::BCatTask::vfunc_0x30 (BCat)
//   size 0x4 | file BCat+0x5dc | callers(0) | datarefs 1

void bcat::BCatTask::vfunc_0x30(void)

{
  return;
}


// FUNC 0x108005e0 bcat::BCatTask::vfunc_0x20 (BCat)
//   size 0x4 | file BCat+0x5e0 | callers(0) | datarefs 1

void bcat::BCatTask::vfunc_0x20(void)

{
  return;
}


// FUNC 0x108005e4 bcat::BCatTask::vfunc_0x38 (BCat)
//   size 0x4 | file BCat+0x5e4 | callers(0) | datarefs 1

void bcat::BCatTask::vfunc_0x38(void)

{
  return;
}


// FUNC 0x108005e8 bcat::BCatTask::vfunc_0x28 (BCat)
//   size 0x4 | file BCat+0x5e8 | callers(0) | datarefs 1

void bcat::BCatTask::vfunc_0x28(void)

{
  return;
}


// FUNC 0x108005ec FUN_108005ec (BCat)
//   size 0x78 | file BCat+0x5ec | callers(0) | datarefs 1

int FUN_108005ec(DrawInfo *param_1)

{
  int iVar1;
  
  iVar1 = ad::lyt::DrawInfo::DrawInfo(param_1);
  *(undefined1 *)(iVar1 + 200) = 1;
  *(undefined1 *)(iVar1 + 0xc9) = 0;
  *(undefined1 *)(iVar1 + 0xcc) = 0;
  *(undefined1 *)(iVar1 + 0xcd) = 0xff;
  *(undefined1 *)(iVar1 + 0xd0) = 1;
  *(undefined4 *)(iVar1 + 0xd4) = 0;
  *(undefined4 *)(iVar1 + 0xd8) = 0xff;
  *(undefined1 *)(iVar1 + 0xdc) = 0;
  *(undefined1 *)(iVar1 + 0xdd) = 0;
  *(undefined1 *)(iVar1 + 0xde) = 0;
  *(undefined1 *)(iVar1 + 0xe0) = 1;
  *(undefined1 *)(iVar1 + 0xe1) = 0;
  *(undefined1 *)(iVar1 + 0xe2) = 4;
  *(undefined1 *)(iVar1 + 0xe3) = 0xf;
  *(undefined1 *)(iVar1 + 0xe4) = 1;
  *(undefined1 *)(iVar1 + 0xe5) = 1;
  *(undefined1 *)(iVar1 + 0xe6) = 1;
  iVar1 = nn::gr::CTR::RenderState::WBuffer::WBuffer((WBuffer *)(iVar1 + 0xe8));
  *(undefined1 *)(iVar1 + -6) = 5;
  return iVar1 + -0xe8;
}


// FUNC 0x108006b4 ->operator.delete (BCat)
//   size 0x4 | file BCat+0x6b4 | callers(0) | datarefs 1
// veneer/thunk -> 0x00286514 operator.delete (static)

// FUNC 0x108006b8 nn::fs::IInputStream::vfunc_0x0 (BCat)
//   size 0x4 | file BCat+0x6b8 | callers(0) | datarefs 1

void nn::fs::IInputStream::vfunc_0x0(void)

{
  return;
}


// FUNC 0x108006bc nn::fs::FileInputStream::vfunc_0x1c (BCat)
//   size 0x24 | file BCat+0x6bc | callers(0) | datarefs 1

void nn::fs::FileInputStream::vfunc_0x1c(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = detail::FileBase::TrySetPosition(CONCAT44(param_2,param_1 + 4));
  if (iVar1 < 0) {
    err::CTR::ThrowFatalErrAll(iVar1,0x108006d0);
    return;
  }
  return;
}


// FUNC 0x108006e0 nn::fs::FileInputStream::vfunc_0x18 (BCat)
//   size 0x8 | file BCat+0x6e0 | callers(0) | datarefs 1

void nn::fs::FileInputStream::vfunc_0x18(int param_1,undefined4 param_2)

{
  detail::FileBase::TrySetPosition(CONCAT44(param_2,param_1 + 4));
  return;
}


// FUNC 0x108006e8 nn::fs::FileInputStream::vfunc_0x2c (BCat)
//   size 0x2c | file BCat+0x6e8 | callers(0) | datarefs 1

int nn::fs::FileInputStream::vfunc_0x2c(int param_1,void *param_2,uint param_3,int param_4)

{
  int iVar1;
  int local_8;
  
  local_8 = param_4;
  iVar1 = detail::FileBase::TryRead((FileBase *)(param_1 + 4),&local_8,param_2,param_3);
  if (iVar1 < 0) {
    err::CTR::ThrowFatalErrAll(iVar1,0x10800708);
  }
  return local_8;
}


// FUNC 0x10800714 nn::fs::FileInputStream::vfunc_0xc (BCat)
//   size 0x2c | file BCat+0x714 | callers(0) | datarefs 1

void nn::fs::FileInputStream::vfunc_0xc(int param_1)

{
  int iVar1;
  undefined4 in_stack_00000000;
  
  iVar1 = detail::FileBase::TrySeek(param_1 + 4);
  if (-(iVar1 >> 0x1f) == 0) {
    return;
  }
  err::CTR::ThrowFatalErrAll(iVar1,0x10800730,-(iVar1 >> 0x1f),in_stack_00000000);
  return;
}


// FUNC 0x10800740 nn::fs::FileInputStream::vfunc_0x28 (BCat)
//   size 0x8 | file BCat+0x740 | callers(0) | datarefs 1

void nn::fs::FileInputStream::vfunc_0x28(int param_1,int *param_2,void *param_3,uint param_4)

{
  detail::FileBase::TryRead((FileBase *)(param_1 + 4),param_2,param_3,param_4);
  return;
}


// FUNC 0x10800748 nn::fs::FileInputStream::vfunc_0x8 (BCat)
//   size 0x18 | file BCat+0x748 | callers(0) | datarefs 1

void nn::fs::FileInputStream::vfunc_0x8(int param_1)

{
  detail::FileBase::TrySeek(param_1 + 4);
  return;
}


// FUNC 0x10800760 nn::fs::FileInputStream::vfunc_0x4 (BCat)
//   size 0x40 | file BCat+0x760 | callers(0) | datarefs 1

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


// FUNC 0x108007a0 nn::fs::FileInputStream::vfunc_0x0 (BCat)
//   size 0x3c | file BCat+0x7a0 | callers(0) | datarefs 1

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


// FUNC 0x1080081c bcat::BCatTask::vfunc_0xc (BCat)
//   size 0xc | file BCat+0x81c | callers(0) | datarefs 1

void bcat::BCatTask::vfunc_0xc(int *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10800824. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 8))();
  return;
}


// FUNC 0x10800828 FUN_10800828 (BCat)
//   size 0x77c | file BCat+0x828 | callers(1) 0x1080106c

void FUN_10800828(void *param_1)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  void *pvVar5;
  int iVar6;
  MLyt *this;
  int *piVar7;
  AnimButton *pAVar8;
  int iVar9;
  int *piVar10;
  undefined4 uVar11;
  undefined4 *puVar12;
  int iVar13;
  uint uVar14;
  MCellAnime *this_00;
  uint in_fpscr;
  uint uVar15;
  float fVar16;
  float fVar17;
  LytAnim local_58 [4];
  undefined4 local_54;
  undefined4 uStack_50;
  undefined4 local_4c;
  undefined2 local_48;
  undefined2 local_46;
  undefined4 local_44;
  undefined4 local_40;
  
  if (*(int *)((int)param_1 + 8) == 0) {
    *(int *)((int)param_1 + 8) = msys::MComSys::_sys;
  }
  iVar13 = *(int *)((int)param_1 + 8);
  ad::lyt::LytResourceMan::init((LytResourceMan *)((int)param_1 + 0x58));
  pvVar5 = (void *)ad::fw::Resource::getFileData((Resource *)((int)param_1 + 0x110));
  ad::lyt::LytResourceMan::registerArc((LytResourceMan *)((int)param_1 + 0x58),pvVar5,".");
  pvVar5 = (void *)ad::fw::Resource::getFileData((Resource *)((int)param_1 + 0xcc));
  ad::lyt::LytResourceMan::registerArc((LytResourceMan *)((int)param_1 + 0x58),pvVar5,".");
  iVar6 = msys::MComSys::_sys;
  iVar9 = *(int *)((int)param_1 + 8);
  if (*(int *)((int)param_1 + 8) == 0) {
    *(int *)((int)param_1 + 8) = msys::MComSys::_sys;
    iVar9 = iVar6;
  }
  iVar2 = msys::MComSys::_sys;
  iVar6 = iVar9;
  if (iVar9 == 0) {
    *(int *)((int)param_1 + 8) = msys::MComSys::_sys;
    iVar6 = iVar2;
  }
  iVar6 = ad::fw::TaskBase::isFps30(*(TaskBase **)(iVar6 + 4));
  if (iVar6 == 0) {
    fVar16 = 1.0;
  }
  else {
    fVar16 = 2.0;
  }
  msys::MCursorBase::init((MCursorBase *)((int)param_1 + 0x160),(MLyt *)(iVar9 + 0xe91bc),fVar16);
  iVar9 = 0xf;
  puVar12 = (undefined4 *)((int)param_1 + 400);
  do {
    iVar9 = iVar9 + -1;
    *puVar12 = 0;
    puVar12 = puVar12 + 1;
  } while (iVar9 != 0);
  iVar13 = iVar13 + 0xd3000;
  this = (MLyt *)((int)param_1 + 0x5fc);
  msys::MLyt::init(this,iVar13,1);
  msys::MLyt::createLyt
            (this,(LytResourceMan *)((int)param_1 + 0x58),
             *(char **)(*(int *)((int)param_1 + 0x15c) + 4));
  MoveVBase::stop((MoveVBase *)((int)param_1 + 0x6c8));
  *(undefined4 *)((int)param_1 + 0x6e4) = 0;
  *(undefined4 *)((int)param_1 + 0x6e8) = 0;
  *(undefined4 *)((int)param_1 + 0x6ec) = 0xc3480000;
  *(undefined4 *)((int)param_1 + 0x6cc) = *(undefined4 *)((int)param_1 + 0x6e4);
  *(undefined4 *)((int)param_1 + 0x6d0) = 0;
  *(undefined4 *)((int)param_1 + 0x6d4) = 0xc3480000;
  *(undefined4 *)((int)param_1 + 0x738) = 0x400;
  puVar12 = *(undefined4 **)((int)param_1 + 0x604);
  iVar9 = *(int *)((int)param_1 + 4);
  *(undefined4 **)(*(int *)((int)param_1 + 0x600) + 4) = puVar12;
  piVar10 = (int *)((int)param_1 + 0x600);
  piVar7 = (int *)(iVar9 + 4);
  *puVar12 = *(undefined4 *)((int)param_1 + 0x600);
  if (piVar10 != (int *)0x0) {
    iVar9 = *piVar7;
    *(int **)((int)param_1 + 0x604) = piVar7;
    *piVar10 = iVar9;
    *(int **)(iVar9 + 4) = piVar10;
    *piVar7 = (int)piVar10;
  }
  *(undefined4 *)((int)param_1 + 0x738) = 0x400;
  msys::MLyt::build((MLyt *)((int)param_1 + 0x254),
                    *(MemAlcBase **)(*(int *)((int)param_1 + 4) + 0x18),
                    (AnimeName *)&PTR_s_FADE_IN_10804090,4);
  msys::MLyt::init((MLyt *)((int)param_1 + 0x254),iVar13,1);
  msys::MLyt::createLyt
            ((MLyt *)((int)param_1 + 0x254),(LytResourceMan *)((int)param_1 + 0x58),
             "SHOP_L_BLOCAT.bflyt",(ButtonGroup *)((int)param_1 + 0x3c),
             (MCursorBase *)((int)param_1 + 0x160));
  MoveVBase::stop((MoveVBase *)((int)param_1 + 800));
  *(undefined4 *)((int)param_1 + 0x33c) = 0;
  *(undefined4 *)((int)param_1 + 0x340) = 0;
  *(undefined4 *)((int)param_1 + 0x344) = 0xc347e666;
  *(undefined4 *)((int)param_1 + 0x324) = *(undefined4 *)((int)param_1 + 0x33c);
  *(undefined4 *)((int)param_1 + 0x328) = 0;
  *(undefined4 *)((int)param_1 + 0x32c) = 0xc347e666;
  *(undefined4 *)((int)param_1 + 0x390) = 0x401;
  piVar10 = (int *)(*(int *)((int)param_1 + 4) + 0xc);
  puVar12 = *(undefined4 **)((int)param_1 + 0x25c);
  *(undefined4 **)(*(int *)((int)param_1 + 600) + 4) = puVar12;
  *puVar12 = *(undefined4 *)((int)param_1 + 600);
  piVar7 = (int *)((int)param_1 + 600);
  if (piVar7 != (int *)0x0) {
    iVar9 = *piVar10;
    *(int **)((int)param_1 + 0x25c) = piVar10;
    *piVar7 = iVar9;
    *(int **)(iVar9 + 4) = piVar7;
    *piVar10 = (int)piVar7;
  }
  *(undefined4 *)((int)param_1 + 0x390) = 0x401;
  msys::MLyt::init((MLyt *)((int)param_1 + 0x9a4),iVar13,0);
  msys::MLyt::createLyt
            ((MLyt *)((int)param_1 + 0x9a4),(LytResourceMan *)((int)param_1 + 0x58),
             *(char **)(*(int *)((int)param_1 + 0x15c) + 8));
  MoveVBase::stop((MoveVBase *)((int)param_1 + 0xa70));
  *(undefined4 *)((int)param_1 + 0xa8c) = 0;
  *(undefined4 *)((int)param_1 + 0xa90) = 0;
  *(undefined4 *)((int)param_1 + 0xa94) = 0xc3480000;
  *(undefined4 *)((int)param_1 + 0xa74) = *(undefined4 *)((int)param_1 + 0xa8c);
  *(undefined4 *)((int)param_1 + 0xa78) = 0;
  *(undefined4 *)((int)param_1 + 0xa7c) = 0xc3480000;
  *(undefined4 *)((int)param_1 + 0xae0) = 0x401;
  piVar10 = (int *)(*(int *)((int)param_1 + 4) + 0xc);
  puVar12 = *(undefined4 **)((int)param_1 + 0x9ac);
  *(undefined4 **)(*(int *)((int)param_1 + 0x9a8) + 4) = puVar12;
  *puVar12 = *(undefined4 *)((int)param_1 + 0x9a8);
  piVar7 = (int *)((int)param_1 + 0x9a8);
  if (piVar7 != (int *)0x0) {
    iVar9 = *piVar10;
    *(int **)((int)param_1 + 0x9ac) = piVar10;
    *piVar7 = iVar9;
    *(int **)(iVar9 + 4) = piVar7;
    *piVar10 = (int)piVar7;
  }
  *(undefined4 *)((int)param_1 + 0xae0) = 0x401;
  uVar11 = *(undefined4 *)(*(int *)((int)param_1 + 4) + 0x18);
  *(undefined4 *)((int)param_1 + 0xa14c) = 0x401;
  *(undefined4 *)((int)param_1 + 0xa140) = uVar11;
  *(undefined4 *)((int)param_1 + 0xa144) = 0;
  *(undefined4 *)((int)param_1 + 0xa148) = 0;
  MessageSimple::init((MessageSimple *)((int)param_1 + 0x3658));
  if (((nn::math::VEC3::One()::one & 1) == 0) &&
     (iVar9 = __cxa_guard_acquire(&nn::math::VEC3::One()::one), iVar9 != 0)) {
    nn::math::VEC3::One()::one = 0x3f800000;
    DAT_00434c40 = 0x3f800000;
    DAT_00434c44 = 0x3f800000;
    __cxa_guard_release(&nn::math::VEC3::One()::one);
  }
  MoveVBase::stop((MoveVBase *)((int)param_1 + 0x3520));
  uVar4 = DAT_00434c44;
  uVar3 = DAT_00434c40;
  uVar11 = nn::math::VEC3::One()::one;
  *(undefined4 *)((int)param_1 + 0x353c) = nn::math::VEC3::One()::one;
  *(undefined4 *)((int)param_1 + 0x3540) = uVar3;
  *(undefined4 *)((int)param_1 + 0x3544) = uVar4;
  *(undefined4 *)((int)param_1 + 0x3524) = uVar11;
  *(undefined4 *)((int)param_1 + 0x3528) = uVar3;
  *(undefined4 *)((int)param_1 + 0x352c) = uVar4;
  if ((((byte)nn::math::VEC3::Zero()::zero & 1) == 0) &&
     (iVar9 = __cxa_guard_acquire(&nn::math::VEC3::Zero()::zero), iVar9 != 0)) {
    nn::math::VEC3::Zero()::zero = 0;
    DAT_00434c4c = 0;
    DAT_00434c50 = 0;
    __cxa_guard_release(&nn::math::VEC3::Zero()::zero);
  }
  MoveVBase::stop((MoveVBase *)((int)param_1 + 0x357c));
  uVar4 = DAT_00434c50;
  uVar3 = DAT_00434c4c;
  uVar11 = nn::math::VEC3::Zero()::zero;
  *(undefined4 *)((int)param_1 + 0x3598) = nn::math::VEC3::Zero()::zero;
  *(undefined4 *)((int)param_1 + 0x359c) = uVar3;
  *(undefined4 *)((int)param_1 + 0x35a0) = uVar4;
  *(undefined4 *)((int)param_1 + 0x3580) = uVar11;
  *(undefined4 *)((int)param_1 + 0x3584) = uVar3;
  *(undefined4 *)((int)param_1 + 0x3588) = uVar4;
  if ((((byte)nn::math::VEC3::Zero()::zero & 1) == 0) &&
     (iVar9 = __cxa_guard_acquire(&nn::math::VEC3::Zero()::zero), iVar9 != 0)) {
    nn::math::VEC3::Zero()::zero = 0;
    DAT_00434c4c = 0;
    DAT_00434c50 = 0;
    __cxa_guard_release(&nn::math::VEC3::Zero()::zero);
  }
  MoveVBase::stop((MoveVBase *)((int)param_1 + 0x35d8));
  uVar4 = DAT_00434c50;
  uVar3 = DAT_00434c4c;
  uVar11 = nn::math::VEC3::Zero()::zero;
  *(undefined4 *)((int)param_1 + 0x35f4) = nn::math::VEC3::Zero()::zero;
  *(undefined4 *)((int)param_1 + 0x35f8) = uVar3;
  *(undefined4 *)((int)param_1 + 0x35fc) = uVar4;
  *(undefined4 *)((int)param_1 + 0x35dc) = uVar11;
  *(undefined4 *)((int)param_1 + 0x35e0) = uVar3;
  *(undefined4 *)((int)param_1 + 0x35e4) = uVar4;
  *(undefined1 *)((int)param_1 + 0x9114) = 1;
  msys::MLyt::attachMChr
            ((MLyt *)((int)param_1 + 0x254),(MChrBase *)((int)param_1 + 0x350c),"INS_TOP_PANEL_TEXT"
             ,"BLOCAT_EXP_PNL",(char *)0x0,(char *)0x0);
  FUN_10802490(param_1,0);
  msys::MCellAnime::init((MCellAnime *)((int)param_1 + 0xd4c),(Resource *)((int)param_1 + 0x1cc));
  CellAnime::play((CellAnime *)((int)param_1 + 0xe98),'\f',0,1.0);
  uVar11 = VectorSignedToFloat((int)*(short *)(*(int *)((int)param_1 + 0x15c) + 0x10),
                               (byte)(in_fpscr >> 0x16) & 3);
  MoveVBase::stop((MoveVBase *)((int)param_1 + 0xe18));
  *(undefined4 *)((int)param_1 + 0xe34) = 0;
  *(undefined4 *)((int)param_1 + 0xe38) = uVar11;
  *(undefined4 *)((int)param_1 + 0xe3c) = 0;
  *(undefined4 *)((int)param_1 + 0xe1c) = *(undefined4 *)((int)param_1 + 0xe34);
  *(undefined4 *)((int)param_1 + 0xe20) = uVar11;
  *(undefined4 *)((int)param_1 + 0xe24) = 0;
  msys::MLyt::attachMChr
            (this,(MChrBase *)((int)param_1 + 0xd4c),"INS_obj",(char *)0x0,(char *)0x0,(char *)0x0);
  pAVar8 = (AnimButton *)
           ad::ctrl::ButtonGroup::FindButtonByName
                     ((ButtonGroup *)((int)param_1 + 0x3c),"btn_RETURN");
  *(AnimButton **)((int)param_1 + 0x154) = pAVar8;
  ad::ctrl::AnimButton::SetStateChangeCallback
            (pAVar8,(_func_void_AnimButton_ptr_State_State_void_ptr *)&LAB_108029d4,param_1);
  *(undefined4 *)(*(int *)((int)param_1 + 0x154) + 0x48) = 0;
  (**(code **)(**(int **)((int)param_1 + 0x154) + 0x28))(*(int **)((int)param_1 + 0x154),1);
  uVar14 = 0;
  do {
    this_00 = (MCellAnime *)((int)param_1 + uVar14 * 0x27c + 0xfc8);
    msys::MCellAnime::init(this_00,(Resource *)((int)param_1 + 0x210));
    bVar1 = **(byte **)((int)param_1 + uVar14 * 0x27c + 0x1118);
    iVar9 = RandSys::get((RandSys *)&gRand);
    CellAnime::play((CellAnime *)((int)param_1 + uVar14 * 0x27c + 0x1114),
                    (uchar)(iVar9 * (uint)bVar1 >> 0x10),0,1.0);
    uVar15 = VectorFloatToUnsigned(*(undefined4 *)((int)param_1 + uVar14 * 0x27c + 0x112c),3);
    iVar9 = RandSys::get((RandSys *)&gRand);
    fVar16 = (float)VectorUnsignedToFloat
                              (iVar9 * (uVar15 & 0xffff) >> 0x10,(byte)(in_fpscr >> 0x16) & 3);
    Frm::setFrm(fVar16);
    *(undefined2 *)((int)param_1 + uVar14 * 0x27c + 0x1130) = 1;
    MoveVBase::stop((MoveVBase *)((int)param_1 + uVar14 * 0x27c + 0x1094));
    *(undefined4 *)((int)param_1 + uVar14 * 0x27c + 0x10b0) = 0;
    *(undefined4 *)((int)param_1 + uVar14 * 0x27c + 0x10b4) = 0xc1a00000;
    *(undefined4 *)((int)param_1 + uVar14 * 0x27c + 0x10b8) = 0;
    *(undefined4 *)((int)param_1 + uVar14 * 0x27c + 0x1098) = 0;
    *(undefined4 *)((int)param_1 + uVar14 * 0x27c + 0x109c) = 0xc1a00000;
    *(undefined4 *)((int)param_1 + uVar14 * 0x27c + 0x10a0) = 0;
    msys::MLyt::attachMChr
              ((MLyt *)((int)param_1 + 0x254),(MChrBase *)this_00,"INS_OBJ_BLOCAT",
               (char *)(&DAT_108096f8)[uVar14],(char *)0x0,(char *)0x0);
    uVar14 = uVar14 + 1 & 0xff;
  } while (uVar14 < 0xf);
  local_58[0] = (LytAnim)0x0;
  local_54 = 0;
  uStack_50 = 0x3f800000;
  uVar14 = 0;
  local_4c = 0;
  local_48 = 1;
  local_46 = 0;
  local_44 = 0;
  local_40 = 0;
  do {
    fVar17 = (float)GetRegFlag((short)uVar14 + 0xc305,(GlobalEvent *)0x0,(LocalEvent *)0x0);
    fVar16 = 0.0;
    if (fVar17 != 0.0) {
      fVar16 = (float)GetRegFlag((short)uVar14 + 0xc4b6,(GlobalEvent *)0x0,(LocalEvent *)0x0);
      if (fVar16 == 0.0) {
        fVar16 = 1.0;
      }
      else {
        fVar16 = 2.0;
      }
    }
    iVar9 = msys::MLyt::getParts
                      ((MLyt *)((int)param_1 + 0x254),(char *)(&DAT_108096f8)[uVar14],(char *)0x0,
                       (char *)0x0);
    ad::lyt::LytAnim::init(local_58,*(Layout **)(iVar9 + 0xac),"SET_MARK","");
    ad::lyt::LytAnim::stopAndSetFrm(local_58,fVar16);
    ad::lyt::LytAnim::term(local_58,true);
    uVar14 = uVar14 + 1 & 0xff;
  } while (uVar14 < 0xf);
  local_4c = 0;
  uVar14 = 0;
  do {
    piVar7 = (int *)((int)param_1 + uVar14 * 4 + 0xa150);
    pAVar8 = (AnimButton *)
             ad::ctrl::ButtonGroup::FindButtonByName
                       ((ButtonGroup *)((int)param_1 + 0x3c),(char *)(&DAT_108096f8)[uVar14]);
    *piVar7 = (int)pAVar8;
    ad::ctrl::AnimButton::SetStateChangeCallback(pAVar8,FUN_108010c8,param_1);
    *(uint *)(*piVar7 + 8) = *(uint *)(*piVar7 + 8) & 0xffffffdf;
    *(uint *)(*piVar7 + 0x48) = uVar14;
    (**(code **)(*(int *)*piVar7 + 0x28))((int *)*piVar7,1);
    uVar11 = msys::MLyt::getParts
                       ((MLyt *)((int)param_1 + 0x254),(char *)(&DAT_108096f8)[uVar14],(char *)0x0,
                        (char *)0x0);
    *(undefined4 *)((int)param_1 + (char)uVar14 * 4 + 400) = uVar11;
    uVar14 = uVar14 + 1 & 0xff;
  } while (uVar14 < 0xf);
  *(code **)((int)param_1 + 0x10) = FUN_10801120;
  *(undefined4 *)((int)param_1 + 0x14) = 0;
  return;
}


// FUNC 0x108010c8 FUN_108010c8 (BCat)
//   size 0x54 | file BCat+0x10c8 | callers(0) | datarefs 1

void FUN_108010c8(int param_1,undefined4 param_2,int param_3,int param_4)

{
  char cVar1;
  
  if ((param_3 == 1) && (cVar1 = *(char *)(param_1 + 0x48), *(char *)(param_4 + 0x178) != cVar1)) {
    FUN_10802490(param_4,(int)cVar1,1,param_4,param_4);
    *(char *)(param_4 + 0x178) = cVar1;
    FUN_108023f0(param_4,0x110015,0,0,0);
  }
  return;
}


// FUNC 0x10801120 FUN_10801120 (BCat)
//   size 0x7c | file BCat+0x1120 | callers(0) | datarefs 2

void FUN_10801120(int param_1)

{
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x254),0,0,(char *)0x0,(char *)0x0);
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x254),1,0,(char *)0x0,(char *)0x0);
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x254),2,0,"BLOCAT_EXP_PNL",(char *)0x0);
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x254),3,0,"BLOCAT_EXP_PNL",(char *)0x0);
  *(undefined1 **)(param_1 + 0x10) = &LAB_10801348;
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}


// FUNC 0x108011e0 bcat::BCat_MainPage::Core::vfunc_0x10 (BCat)
//   size 0xf4 | file BCat+0x11e0 | callers(0) | datarefs 1

void bcat::BCat_MainPage::Core::vfunc_0x10(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 local_1c;
  
  iVar2 = msys::MComSys::_sys;
  if (param_2 == 1) {
    return;
  }
  if (param_2 == 4) {
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
    }
    *(undefined1 *)(*(int *)(param_1 + 8) + 0xe6508) = 0;
    iVar1 = *(int *)(param_1 + 8);
    if (iVar1 == 0) {
      *(int *)(param_1 + 8) = iVar2;
      iVar1 = iVar2;
    }
    *(undefined1 *)(iVar1 + 0xe650a) = 1;
    FUN_108023f0(param_1,0x110017,0,0,0);
    return;
  }
  if (param_2 == 5) {
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
    }
    iVar2 = *(int *)(param_1 + 8);
    local_1c = 0xff000000;
    MoveC::moveFrm((MoveC *)(iVar2 + 0x4acd4),(Color8 *)&local_1c,16.0);
    MoveC::moveFrm((MoveC *)(iVar2 + 0x4ad14),(Color8 *)&local_1c,16.0);
    *(undefined1 **)(param_1 + 0x20) = &LAB_10801074;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x108012ec FUN_108012ec (BCat)
//   size 0x54 | file BCat+0x12ec | callers(0) | datarefs 1

void FUN_108012ec(int param_1)

{
  MComSys *pMVar1;
  int iVar2;
  MComSys *this;
  
  iVar2 = msys::MLyt::isBusyAnime((MLyt *)(param_1 + 0x254));
  pMVar1 = msys::MComSys::_sys;
  if (iVar2 == 0) {
    this = *(MComSys **)(param_1 + 8);
    if (*(MComSys **)(param_1 + 8) == (MComSys *)0x0) {
      *(MComSys **)(param_1 + 8) = msys::MComSys::_sys;
      this = pMVar1;
    }
    iVar2 = msys::MComSys::getNextPage(this);
    if (*(char *)(iVar2 + 0x14) != '\0') {
      *(undefined1 **)(param_1 + 0x18) = &LAB_10801360;
      *(undefined4 *)(param_1 + 0x1c) = 0;
    }
  }
  return;
}


// FUNC 0x10801370 FUN_10801370 (BCat)
//   size 0x2c8 | file BCat+0x1370 | callers(0) | datarefs 1

void FUN_10801370(int param_1)

{
  byte bVar1;
  int *piVar2;
  void *pvVar3;
  int iVar4;
  IAllocator *pIVar5;
  byte *pbVar6;
  int iVar7;
  uint *puVar8;
  char *pcVar9;
  undefined4 uVar10;
  FileContext *pFVar11;
  MemAlcBase *pMVar12;
  char acStackY_110 [128];
  uint *in_stack_ffffff70;
  uint uVar13;
  TransMultiSymbol aTStack_64 [4];
  Resource *local_60;
  TransMultiSymbol aTStack_5c [36];
  Resource *local_38;
  TaskBase *local_34;
  TaskBase *local_30;
  undefined4 local_2c;
  
  piVar2 = *(int **)(*(int *)(param_1 + 4) + 0x18);
  pvVar3 = (void *)(**(code **)(*piVar2 + 0xc))(piVar2,0x300000,0);
  MemAlc::initCore((MemAlc *)(param_1 + 0x28),pvVar3,0x300000);
  iVar4 = ad::lyt::LytDrawSys::GetInst();
  uVar10 = *(undefined4 *)(*(int *)(param_1 + 4) + 0x18);
  pIVar5 = (IAllocator *)(iVar4 + 0x5f4);
  if (ad::lyt::Layout::s_pAllocator != pIVar5) {
    ad::lyt::Initialize(pIVar5,pIVar5);
  }
  *(undefined4 *)(iVar4 + 0x5f8) = uVar10;
  iVar4 = ad::lyt::LytDrawSys::GetInst();
  *(undefined4 *)(iVar4 + 0x5fc) = 0x10000;
  pbVar6 = (byte *)bcat::GetBootInfo();
  bVar1 = *pbVar6;
  pMVar12 = (MemAlcBase *)(param_1 + 0x28);
  *(undefined **)(param_1 + 0x15c) = &DAT_108040b0 + (uint)bVar1 * 0x14;
  iVar7 = msys::MComSys::_sys;
  iVar4 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar4 = iVar7;
  }
  iVar7 = msys::MComSys::_sys;
  local_30 = *(TaskBase **)(iVar4 + 4);
  local_60 = (Resource *)(param_1 + 0x1cc);
  if (iVar4 == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  else {
    iVar7 = *(int *)(param_1 + 8);
  }
  pcVar9 = *(char **)(&DAT_108040bc + (uint)bVar1 * 0x14);
  pFVar11 = *(FileContext **)(iVar7 + 0x278);
  local_2c = *(undefined4 *)(pFVar11 + 0x24);
  ad::TransMultiSymbol::init(aTStack_5c,pcVar9);
  BinGlu4Acs::getEntryAcs(acStackY_110 + 0x80);
  puVar8 = (uint *)((*in_stack_ffffff70 & 0x3fffffff) + *(int *)(pFVar11 + 0x24));
  ad::fw::TaskBase::readCA
            (local_30,local_60,pFVar11,pcVar9,(char *)puVar8,(char *)(puVar8 + 1),
             (char *)(puVar8 + 2),(char *)(puVar8 + 3),pMVar12,0x7f,(VramAlcBase *)0x0,0,
             (ResCacheArg *)0x0);
  iVar7 = msys::MComSys::_sys;
  iVar4 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar4 = iVar7;
  }
  iVar7 = msys::MComSys::_sys;
  local_34 = *(TaskBase **)(iVar4 + 4);
  local_38 = (Resource *)(param_1 + 0x210);
  if (iVar4 == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  else {
    iVar7 = *(int *)(param_1 + 8);
  }
  pFVar11 = *(FileContext **)(iVar7 + 0x278);
  uVar13 = 0x7f;
  local_2c = *(undefined4 *)(pFVar11 + 0x24);
  ad::TransMultiSymbol::init(aTStack_64,"m_bcat_menu");
  BinGlu4Acs::getEntryAcs(acStackY_110 + 0x80);
  pcVar9 = (char *)((*puVar8 & 0x3fffffff) + *(int *)(pFVar11 + 0x24));
  ad::fw::TaskBase::readCA
            (local_34,local_38,pFVar11,"m_bcat_menu",pcVar9,pcVar9 + 4,pcVar9 + 8,pcVar9 + 0xc,
             (MemAlcBase *)(param_1 + 0x28),uVar13,(VramAlcBase *)0x0,0,(ResCacheArg *)0x0);
  iVar7 = msys::MComSys::_sys;
  iVar4 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar4 = iVar7;
  }
  iVar7 = msys::MComSys::_sys;
  if (iVar4 == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  else {
    iVar7 = iVar4;
  }
  ad::fw::TaskBase::readLyt
            (*(TaskBase **)(iVar7 + 4),(Resource *)(param_1 + 0xcc),
             (FileContext *)(*(int *)(iVar4 + 0x278) + 0xa8),
             (char *)**(undefined4 **)(param_1 + 0x15c),(MemAlcBase *)(param_1 + 0x28),0x7f,
             (ResCacheArg *)0x0);
  iVar7 = msys::MComSys::_sys;
  iVar4 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar4 = iVar7;
  }
  iVar7 = msys::MComSys::_sys;
  if (iVar4 == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  else {
    iVar7 = iVar4;
  }
  ad::fw::TaskBase::readLyt
            (*(TaskBase **)(iVar7 + 4),(Resource *)(param_1 + 0x110),
             (FileContext *)(*(int *)(iVar4 + 0x278) + 0xa8),"MENU_BCAT",
             (MemAlcBase *)(param_1 + 0x28),0x7f,(ResCacheArg *)0x0);
  *(undefined1 **)(param_1 + 0x10) = &LAB_10801060;
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}


// FUNC 0x10801670 FUN_10801670 (BCat)
//   size 0x1f0 | file BCat+0x1670 | callers(0) | datarefs 2

void FUN_10801670(int param_1,uint *param_2)

{
  byte bVar1;
  char cVar2;
  undefined4 uVar3;
  char cVar4;
  char cVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  
  uVar3 = msys::MComSys::_sys;
  cVar2 = *(char *)(param_1 + 0x178);
  iVar8 = (int)cVar2 % 5;
  uVar6 = *param_2;
  iVar7 = ((short)cVar2 * 0x67 >> 9) - ((short)cVar2 * 0x67 >> 0x1f);
  if ((uVar6 & 0x20) == 0) {
    if ((uVar6 & 0x10) != 0) {
      cVar4 = (char)iVar8 + '\x01';
      goto LAB_108016c4;
    }
    if ((uVar6 & 0x40) == 0) {
      if ((uVar6 & 0x80) != 0) {
        cVar4 = (char)iVar7 + '\x01';
        goto LAB_108016e4;
      }
      if ((uVar6 & 0x802) != 0) {
        if (*(int *)(param_1 + 8) == 0) {
          *(undefined4 *)(param_1 + 8) = msys::MComSys::_sys;
        }
        *(undefined1 *)(*(int *)(param_1 + 8) + 0xe6508) = 0;
        if (*(int *)(param_1 + 8) == 0) {
          *(undefined4 *)(param_1 + 8) = uVar3;
        }
        *(undefined1 *)(*(int *)(param_1 + 8) + 0xe650a) = 1;
        (**(code **)(**(int **)(param_1 + 0x154) + 0x10))();
        (**(code **)(**(int **)(param_1 + 0x154) + 0xc))();
      }
    }
    else {
      cVar4 = (char)iVar7 + -1;
LAB_108016e4:
      iVar7 = (int)cVar4;
    }
  }
  else {
    cVar4 = (char)iVar8 + -1;
LAB_108016c4:
    iVar8 = (int)cVar4;
  }
  if (iVar8 < 0) {
    cVar5 = (char)iVar7 + -1;
    cVar4 = '\x04';
  }
  else {
    cVar4 = (char)iVar8;
    if (iVar8 < 5) goto LAB_10801788;
    cVar5 = (char)iVar7 + '\x01';
    cVar4 = '\0';
  }
  iVar7 = (int)cVar5;
LAB_10801788:
  if (iVar7 < 0) {
    iVar7 = 2;
  }
  else if (2 < iVar7) {
    iVar7 = 0;
  }
  cVar4 = (char)iVar7 * '\x05' + cVar4;
  if ((int)cVar4 != (int)cVar2) {
    FUN_108023f0(param_1,0x110015,0,0,0);
    FUN_10802490(param_1,(int)cVar4);
    *(char *)(param_1 + 0x178) = cVar4;
  }
  FUN_10802158(param_1 + 0x160);
  uVar6 = 0;
  do {
    iVar7 = param_1 + uVar6 * 0x27c;
    if ((*(byte *)(iVar7 + 0x1132) & 1) == 0) {
      bVar1 = **(byte **)(iVar7 + 0x1118);
      iVar8 = RandSys::get((RandSys *)&gRand);
      CellAnime::play((CellAnime *)(iVar7 + 0x1114),(uchar)(iVar8 * (uint)bVar1 >> 0x10),0,1.0);
      *(undefined2 *)(iVar7 + 0x1130) = 1;
    }
    uVar6 = uVar6 + 1 & 0xff;
  } while (uVar6 < 0xf);
  return;
}


// FUNC 0x10801878 FUN_10801878 (BCat)
//   size 0x80 | file BCat+0x1878 | callers(0) | datarefs 1

void FUN_10801878(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = msys::MLyt::isEnableAnime((MLyt *)(param_1 + 0x254));
  iVar1 = msys::MComSys::_sys;
  if (iVar2 == 0) {
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar1;
    }
    *(undefined1 *)(iVar2 + 0xe6508) = 1;
    iVar2 = msys::MComSys::_sys;
    iVar1 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar1 = iVar2;
    }
    *(undefined1 *)(iVar1 + 0xe650a) = 1;
    *(undefined1 *)(param_1 + 0x178) = 0;
    msys::MCursorBase::setVisible((MCursorBase *)(param_1 + 0x160),true);
    FUN_10802158(param_1 + 0x160);
    *(code **)(param_1 + 0x20) = FUN_10801670;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x10801918 FUN_10801918 (BCat)
//   size 0x2d8 | file BCat+0x1918 | callers(1) 0x108028fc

int FUN_10801918(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  *param_1 = &bcat::BCat_PageBase::Core::vtable;
  param_1[1] = param_2;
  param_1[2] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = &MemAlcH::vtable;
  param_1[0xd] = 0;
  iVar1 = ad::ctrl::ButtonGroup::ButtonGroup((ButtonGroup *)(param_1 + 0xf));
  *(undefined4 *)(iVar1 + 0x1c) = 0;
  iVar1 = ad::font::ResFont::ResFont((ResFont *)(iVar1 + 0x20));
  ad::lyt::LytResourceMan::init((LytResourceMan *)(iVar1 + -4));
  iVar1 = ad::fw::Resource::Resource((Resource *)(iVar1 + 0x70));
  iVar1 = ad::fw::Resource::Resource((Resource *)(iVar1 + 0x44));
  *(undefined1 *)(iVar1 + 0x48) = 0xff;
  *(undefined1 *)(iVar1 + 0x49) = 0xff;
  *(undefined ***)(iVar1 + -0x110) = &bcat::BCat_MainPage::Core::vtable;
  puVar2 = (undefined4 *)msys::MCursorBase::MCursorBase((MCursorBase *)(iVar1 + 0x50));
  *puVar2 = &vtable_for_N4msys7MCursorILj15EEE;
  puVar2[0xc] = 0;
  puVar2[0xd] = 0;
  puVar2[0xe] = 0;
  puVar2[0xf] = 0;
  puVar2[0x10] = 0;
  puVar2[0x11] = 0;
  puVar2[0x12] = 0;
  puVar2[0x13] = 0;
  puVar2[0x14] = 0;
  puVar2[0x15] = 0;
  puVar2[0x16] = 0;
  puVar2[0x17] = 0;
  puVar2[0x18] = 0;
  puVar2[0x19] = 0;
  puVar2[0x1a] = 0;
  iVar1 = ad::fw::Resource::Resource((Resource *)(puVar2 + 0x1b));
  iVar1 = ad::fw::Resource::Resource((Resource *)(iVar1 + 0x44));
  puVar2 = (undefined4 *)FUN_1080206c(iVar1 + 0x44);
  *puVar2 = &msys::MLyt::vtable;
  *(undefined1 *)(puVar2 + 0x53) = 0xff;
  *(undefined2 *)((int)puVar2 + 0x14e) = 0;
  puVar2[0x54] = 0;
  iVar1 = __aeabi_vec_ctor_nocookie_nodtor(puVar2 + 0x55,&LAB_10800668,0x1c,0xc);
  iVar1 = __aeabi_vec_ctor_nocookie_nodtor(iVar1 + 0x15c,&LAB_108007dc,0x10,0xc);
  *(undefined4 *)(iVar1 + 0xc0) = 0;
  *(undefined1 *)(iVar1 + 0xc4) = 1;
  *(undefined4 *)(iVar1 + 200) = 0;
  *(undefined4 *)(iVar1 + 0xcc) = 0;
  *(undefined1 *)(iVar1 + 0xd0) = 0;
  *(undefined4 *)(iVar1 + 0xd4) = 0;
  *(undefined4 *)(iVar1 + 0xd8) = 0;
  FUN_10802050(iVar1 + -0xc,0xffffffff);
  puVar2 = (undefined4 *)FUN_1080206c(iVar1 + 0xf8);
  *puVar2 = &msys::MLyt::vtable;
  *(undefined1 *)(puVar2 + 0x53) = 0xff;
  *(undefined2 *)((int)puVar2 + 0x14e) = 0;
  puVar2[0x54] = 0;
  iVar1 = __aeabi_vec_ctor_nocookie_nodtor(puVar2 + 0x55,&LAB_10800668,0x1c,0xc);
  iVar1 = __aeabi_vec_ctor_nocookie_nodtor(iVar1 + 0x15c,&LAB_108007dc,0x10,0xc);
  *(undefined4 *)(iVar1 + 0xc0) = 0;
  *(undefined1 *)(iVar1 + 0xc4) = 1;
  *(undefined4 *)(iVar1 + 200) = 0;
  *(undefined4 *)(iVar1 + 0xcc) = 0;
  *(undefined1 *)(iVar1 + 0xd0) = 0;
  *(undefined4 *)(iVar1 + 0xd4) = 0;
  *(undefined4 *)(iVar1 + 0xd8) = 0;
  FUN_10802050(iVar1 + -0xc,0xffffffff);
  puVar2 = (undefined4 *)FUN_1080206c(iVar1 + 0xf8);
  *puVar2 = &msys::MLyt::vtable;
  *(undefined1 *)(puVar2 + 0x53) = 0xff;
  *(undefined2 *)((int)puVar2 + 0x14e) = 0;
  puVar2[0x54] = 0;
  iVar1 = __aeabi_vec_ctor_nocookie_nodtor(puVar2 + 0x55,&LAB_10800668,0x1c,0xc);
  iVar1 = __aeabi_vec_ctor_nocookie_nodtor(iVar1 + 0x15c,&LAB_108007dc,0x10,0xc);
  *(undefined4 *)(iVar1 + 0xc0) = 0;
  *(undefined1 *)(iVar1 + 0xc4) = 1;
  *(undefined4 *)(iVar1 + 200) = 0;
  *(undefined4 *)(iVar1 + 0xcc) = 0;
  *(undefined1 *)(iVar1 + 0xd0) = 0;
  *(undefined4 *)(iVar1 + 0xd4) = 0;
  *(undefined4 *)(iVar1 + 0xd8) = 0;
  FUN_10802050(iVar1 + -0xc,0xffffffff);
  puVar2 = (undefined4 *)FUN_1080206c(iVar1 + 0xf8);
  *puVar2 = &msys::MCellAnime::vtable;
  iVar1 = CellAnime::CellAnime((CellAnime *)(puVar2 + 0x53));
  *(undefined1 *)(iVar1 + 300) = 0xff;
  *(undefined1 *)(iVar1 + 0x12d) = 0xff;
  *(undefined1 *)(iVar1 + 0x12e) = 0xff;
  *(undefined1 *)(iVar1 + 0x12f) = 0xff;
  iVar1 = __aeabi_vec_ctor_nocookie_nodtor(iVar1 + 0x130,FUN_10803618,0x27c,0xf);
  puVar2 = (undefined4 *)FUN_1080206c(iVar1 + 0x2544);
  *puVar2 = &msys::MMsg::vtable;
  iVar1 = MessageSimple::MessageSimple((MessageSimple *)(puVar2 + 0x53));
  *(undefined4 *)(iVar1 + 0x6ae0) = 0;
  *(undefined1 *)(iVar1 + 0x6ae4) = 0;
  *(undefined1 *)(iVar1 + 0x6ae5) = 0;
  *(undefined4 *)(iVar1 + 0x6ae8) = 0;
  *(undefined4 *)(iVar1 + 0x6aec) = 0;
  *(undefined4 *)(iVar1 + 0x6af4) = 0x400;
  *(code **)(iVar1 + -0x3648) = FUN_10801370;
  *(undefined4 *)(iVar1 + -0x3644) = 0;
  *(undefined1 **)(iVar1 + -0x3640) = &LAB_10801900;
  *(undefined4 *)(iVar1 + -0x363c) = 0;
  *(code **)(iVar1 + -0x3638) = FUN_10801878;
  *(undefined4 *)(iVar1 + -0x3634) = 0;
  return iVar1 + -0x3658;
}


// FUNC 0x10801c1c bcat::BCat::vfunc_0x0 (BCat)
//   size 0xec | file BCat+0x1c1c | callers(3) 0x108035a0 0x108035cc 0x108035f4 | datarefs 1

void bcat::BCat::vfunc_0x0(undefined4 *param_1)

{
  int iVar1;
  MLyt *this;
  
  *param_1 = &vtable;
  ad::fw::FileContext::term((FileContext *)(param_1[0x9e] + 0xa8));
  ad::fw::FileContext::term((FileContext *)param_1[0x9e]);
  operator_delete((void *)param_1[0x3a413]);
  param_1[0x3a413] = 0;
  ad::fw::TaskBase::term((TaskBase *)param_1[1],0);
  __aeabi_vec_dtor(param_1 + 0x3a559,&LAB_10800664,0x100,2);
  this = (MLyt *)(param_1 + 0x3a46f);
  *(undefined ***)this = &msys::MLyt::vtable;
  msys::MLyt::term(this);
  __aeabi_vec_dtor(param_1 + 0x3a51b,&LAB_1080080c,0x10,0xc);
  __aeabi_vec_dtor(param_1 + 0x3a4c4,&LAB_108006a4,0x1c,0xc);
  iVar1 = msys::MChrBase::vfunc_0x0(this);
  iVar1 = ad::ctrl::ButtonGroup::~ButtonGroup((ButtonGroup *)(iVar1 + -0x1c));
  iVar1 = MsgDataAcsrBase::~MsgDataAcsrBase((MsgDataAcsrBase *)(iVar1 + -0x6c));
  iVar1 = BCat_PageBase::vfunc_0x0(iVar1 + -0x28);
  iVar1 = ad::fw::Resource::~Resource((Resource *)(iVar1 + -0x44));
  ad::lyt::LytResourceMan::term((LytResourceMan *)(iVar1 + -0x74));
  iVar1 = ad::font::ResFont::~ResFont((ResFont *)(iVar1 + -0x70));
  msys::MComSys::~MComSys((MComSys *)(iVar1 + -0xe9058));
  return;
}


// FUNC 0x10801d20 bcat::BCat_MainPage::vfunc_0x0 (BCat)
//   size 0x4 | file BCat+0x1d20 | callers(0) | datarefs 1

undefined4 * bcat::BCat_MainPage::vfunc_0x0(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  undefined4 *puVar5;
  int *piVar6;
  
  *param_1 = &BCat_PageBase::vtable;
  puVar1 = param_1 + 1;
  puVar2 = (undefined4 *)param_1[2];
  while (puVar2 != puVar1) {
    puVar5 = (undefined4 *)puVar2[1];
    puVar2[1] = puVar2;
    *puVar2 = puVar2;
    puVar2 = puVar5;
  }
  param_1[2] = puVar1;
  *puVar1 = puVar1;
  puVar1 = param_1 + 3;
  puVar2 = (undefined4 *)param_1[4];
  while (puVar2 != puVar1) {
    puVar5 = (undefined4 *)puVar2[1];
    puVar2[1] = puVar2;
    *puVar2 = puVar2;
    puVar2 = puVar5;
  }
  param_1[4] = puVar1;
  *puVar1 = puVar1;
  if ((int *)param_1[8] != (int *)0x0) {
    (**(code **)(*(int *)param_1[8] + 4))();
  }
  *param_1 = &msys::MPageBase::vtable;
  param_1[8] = 0;
  puVar1 = param_1 + 3;
  puVar2 = (undefined4 *)param_1[4];
  while (puVar2 != puVar1) {
    puVar5 = (undefined4 *)puVar2[1];
    puVar2[1] = puVar2;
    *puVar2 = puVar2;
    puVar2 = puVar5;
  }
  param_1[4] = puVar1;
  *puVar1 = puVar1;
  puVar2 = (undefined4 *)param_1[4];
  param_1[4] = puVar2;
  *puVar2 = param_1[3];
  piVar3 = param_1 + 1;
  piVar4 = (int *)param_1[2];
  while (piVar4 != piVar3) {
    piVar6 = (int *)piVar4[1];
    piVar4[1] = (int)piVar4;
    *piVar4 = (int)piVar4;
    piVar4 = piVar6;
  }
  param_1[2] = piVar3;
  *piVar3 = (int)piVar3;
  piVar4 = (int *)param_1[2];
  *(int **)(*piVar3 + 4) = piVar4;
  *piVar4 = *piVar3;
  return param_1;
}


// FUNC 0x10801d24 bcat::BCat_PageBase::vfunc_0x0 (BCat)
//   size 0x124 | file BCat+0x1d24 | callers(3) 0x10801c1c 0x1080294c 0x10802c54 | datarefs 1

undefined4 * bcat::BCat_PageBase::vfunc_0x0(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  undefined4 *puVar5;
  int *piVar6;
  
  *param_1 = &vtable;
  puVar1 = param_1 + 1;
  puVar2 = (undefined4 *)param_1[2];
  while (puVar2 != puVar1) {
    puVar5 = (undefined4 *)puVar2[1];
    puVar2[1] = puVar2;
    *puVar2 = puVar2;
    puVar2 = puVar5;
  }
  param_1[2] = puVar1;
  *puVar1 = puVar1;
  puVar1 = param_1 + 3;
  puVar2 = (undefined4 *)param_1[4];
  while (puVar2 != puVar1) {
    puVar5 = (undefined4 *)puVar2[1];
    puVar2[1] = puVar2;
    *puVar2 = puVar2;
    puVar2 = puVar5;
  }
  param_1[4] = puVar1;
  *puVar1 = puVar1;
  if ((int *)param_1[8] != (int *)0x0) {
    (**(code **)(*(int *)param_1[8] + 4))();
  }
  *param_1 = &msys::MPageBase::vtable;
  param_1[8] = 0;
  puVar1 = param_1 + 3;
  puVar2 = (undefined4 *)param_1[4];
  while (puVar2 != puVar1) {
    puVar5 = (undefined4 *)puVar2[1];
    puVar2[1] = puVar2;
    *puVar2 = puVar2;
    puVar2 = puVar5;
  }
  param_1[4] = puVar1;
  *puVar1 = puVar1;
  puVar2 = (undefined4 *)param_1[4];
  param_1[4] = puVar2;
  *puVar2 = param_1[3];
  piVar3 = param_1 + 1;
  piVar4 = (int *)param_1[2];
  while (piVar4 != piVar3) {
    piVar6 = (int *)piVar4[1];
    piVar4[1] = (int)piVar4;
    *piVar4 = (int)piVar4;
    piVar4 = piVar6;
  }
  param_1[2] = piVar3;
  *piVar3 = (int)piVar3;
  piVar4 = (int *)param_1[2];
  *(int **)(*piVar3 + 4) = piVar4;
  *piVar4 = *piVar3;
  return param_1;
}


// FUNC 0x10801e50 bcat::BCat_PageBase::Core::vfunc_0x0 (BCat)
//   size 0x98 | file BCat+0x1e50 | callers(2) 0x10802ad0 0x108026f8 | datarefs 1

int bcat::BCat_PageBase::Core::vfunc_0x0(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &vtable;
  ad::ctrl::ButtonGroup::FreeAll((ButtonGroup *)(param_1 + 0xf));
  ad::fw::Resource::term((Resource *)(param_1 + 0x44));
  ad::fw::Resource::term((Resource *)(param_1 + 0x33));
  ad::lyt::LytResourceMan::term((LytResourceMan *)(param_1 + 0x16));
  Mem::Free((void *)param_1[0xd]);
  param_1[0xd] = 0;
  iVar1 = ad::fw::Resource::~Resource((Resource *)(param_1 + 0x44));
  iVar1 = ad::fw::Resource::~Resource((Resource *)(iVar1 + -0x44));
  ad::lyt::LytResourceMan::term((LytResourceMan *)(iVar1 + -0x74));
  iVar1 = ad::font::ResFont::~ResFont((ResFont *)(iVar1 + -0x70));
  iVar1 = ad::ctrl::ButtonGroup::~ButtonGroup((ButtonGroup *)(iVar1 + -0x20));
  *(undefined4 *)(iVar1 + -0x14) = &MemAlcH::vtable;
  Mem::Free(*(void **)(iVar1 + -8));
  *(undefined4 *)(iVar1 + -0x14) = &MemAlc::vtable;
  *(undefined4 *)(iVar1 + -8) = 0;
  return iVar1 + -0x3c;
}


// FUNC 0x10801ef4 msys::MChrBase::vfunc_0x0 (BCat)
//   size 0x14c | file BCat+0x1ef4 | callers(4) 0x10801c1c 0x108026f8 0x10803694 0x10803660 | datarefs 1

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


// FUNC 0x10802050 FUN_10802050 (BCat)
//   size 0x1c | file BCat+0x2050 | callers(2) 0x10803424 0x10801918

void FUN_10802050(uint *param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = param_2 & 0xff | (param_2 & 0xff) << 8;
  uVar1 = uVar1 | uVar1 << 0x10;
  *param_1 = uVar1;
  param_1[1] = uVar1;
  param_1[2] = uVar1;
  return;
}


// FUNC 0x1080206c FUN_1080206c (BCat)
//   size 0xdc | file BCat+0x206c | callers(3) 0x10803424 0x10801918 0x10803618

void FUN_1080206c(undefined4 *param_1)

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
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(puVar1 + 0xc,FUN_10803728,0x2c,1);
  *(int *)(iVar2 + -8) = iVar2;
  *(undefined1 *)(iVar2 + -4) = 1;
  puVar1 = (undefined4 *)MoveVBase::MoveVBase((MoveVBase *)(iVar2 + 0x2c));
  *puVar1 = &vtable_for_5MoveVILj1EE;
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(puVar1 + 0xc,FUN_10803728,0x2c,1);
  *(int *)(iVar2 + -8) = iVar2;
  *(undefined1 *)(iVar2 + -4) = 1;
  puVar1 = (undefined4 *)MoveVBase::MoveVBase((MoveVBase *)(iVar2 + 0x2c));
  *puVar1 = &vtable_for_5MoveVILj1EE;
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(puVar1 + 0xc,FUN_10803728,0x2c,1);
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


// FUNC 0x10802158 FUN_10802158 (BCat)
//   size 0x280 | file BCat+0x2158 | callers(2) 0x10801670 0x10801878

void FUN_10802158(int param_1)

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
      iVar3 = msys::MCtrlUserData::findExtUserDataByName(this,&DAT_10809774);
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
      local_50[0] = s_SQ_CURSOR_S_10809778;
      local_50[1] = s_SQ_CURSOR_L_10809784;
      local_50[2] = s_SQ_CURSOR_SS_10809790;
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


// FUNC 0x108023f0 FUN_108023f0 (BCat)
//   size 0x9c | file BCat+0x23f0 | callers(4) 0x108011e0 0x1080295c 0x10801670 0x108010c8

MSndSe * FUN_108023f0(undefined4 param_1,uint param_2,MChrBase *param_3,VEC2 *param_4,bool param_5)

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


// FUNC 0x10802490 FUN_10802490 (BCat)
//   size 0x1e4 | file BCat+0x2490 | callers(3) 0x10801670 0x10800828 0x108010c8

void FUN_10802490(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  wchar_t *pwVar4;
  MMsg *this;
  float fVar5;
  
  fVar5 = (float)GetRegFlag((short)param_2 + 0xc305,(GlobalEvent *)0x0,(LocalEvent *)0x0);
  this = (MMsg *)(param_1 + 0x350c);
  if (fVar5 != 0.0) {
    fVar5 = (float)GetRegFlag((short)param_2 + 0xc4b6,(GlobalEvent *)0x0,(LocalEvent *)0x0);
    iVar2 = msys::MComSys::_sys;
    iVar1 = *(int *)(param_1 + 8);
    if (fVar5 == 0.0) {
      if (iVar1 == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar1 = iVar2;
      }
      uVar3 = LMS_GetTextIndexByLabel
                        (iVar1 + 0xe913c,"MES_Menu_reitem_01_Ekubon_brilock_shop_06_hur");
      pwVar4 = (wchar_t *)LMS_GetText(iVar1 + 0xe913c,uVar3);
      msys::MMsg::playStr(this,pwVar4,(InsParam *)0x0,false);
      return;
    }
    if (iVar1 == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar1 = iVar2;
    }
    iVar2 = RandSys::get((RandSys *)&gRand);
    uVar3 = LMS_GetTextIndexByLabel
                      (iVar1 + 0xe913c,
                       (&PTR_s_MES_Menu_reitem_01_Ekubon_briloc_10809734)
                       [(uint)(iVar2 * 0xd) >> 0x10]);
    pwVar4 = (wchar_t *)LMS_GetText(iVar1 + 0xe913c,uVar3);
    msys::MMsg::playStr(this,pwVar4,(InsParam *)0x0,false);
    return;
  }
  if ((*(ushort *)(&DAT_10804208 + param_2 * 8) == 0) ||
     (fVar5 = (float)GetRegFlag(*(ushort *)(&DAT_10804208 + param_2 * 8),(GlobalEvent *)0x0,
                                (LocalEvent *)0x0), iVar1 = msys::MComSys::_sys, fVar5 != 0.0)) {
    iVar2 = msys::MComSys::_sys;
    iVar1 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar1 = iVar2;
    }
    uVar3 = LMS_GetTextIndexByLabel(iVar1 + 0xe913c,*(undefined4 *)(&DAT_10804204 + param_2 * 8));
    pwVar4 = (wchar_t *)LMS_GetText(iVar1 + 0xe913c,uVar3);
    msys::MMsg::playStr(this,pwVar4,(InsParam *)0x0,false);
    return;
  }
  iVar2 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar2 = iVar1;
  }
  uVar3 = LMS_GetTextIndexByLabel(iVar2 + 0xe913c,"MES_Menu_reitem_01_Ekubon_brilock_shop_06_12");
  pwVar4 = (wchar_t *)LMS_GetText(iVar2 + 0xe913c,uVar3);
  msys::MMsg::playStr(this,pwVar4,(InsParam *)0x0,false);
  return;
}


// FUNC 0x108026e8 bcat::BCat_MainPage::Core::vfunc_0x4 (BCat)
//   size 0x10 | file BCat+0x26e8 | callers(0) | datarefs 1

void bcat::BCat_MainPage::Core::vfunc_0x4(void)

{
  void *pvVar1;
  
  pvVar1 = (void *)vfunc_0x0();
  operator_delete(pvVar1);
  return;
}


// FUNC 0x108026f8 bcat::BCat_MainPage::Core::vfunc_0x0 (BCat)
//   size 0x1e8 | file BCat+0x26f8 | callers(1) 0x108026e8 | datarefs 1

void bcat::BCat_MainPage::Core::vfunc_0x0(undefined4 *param_1)

{
  int iVar1;
  MLyt *pMVar2;
  uint uVar3;
  
  *param_1 = &vtable;
  CellAnime::term((CellAnime *)(param_1 + 0x3a6));
  uVar3 = 0;
  do {
    CellAnime::term((CellAnime *)(param_1 + uVar3 * 0x9f + 0x445));
    uVar3 = uVar3 + 1 & 0xff;
  } while (uVar3 < 0xf);
  msys::MLyt::term((MLyt *)(param_1 + 0x95));
  msys::MLyt::term((MLyt *)(param_1 + 0x17f));
  msys::MLyt::term((MLyt *)(param_1 + 0x269));
  ad::fw::Resource::term((Resource *)(param_1 + 0x84));
  ad::fw::Resource::term((Resource *)(param_1 + 0x73));
  param_1[0xd43] = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar1 = MessageSimple::~MessageSimple((MessageSimple *)(param_1 + 0xd96));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  __aeabi_vec_dtor(iVar1 + -0x2544,&LAB_1080364c,0x27c,0xf);
  *(undefined ***)(iVar1 + -0x27c0) = &msys::MCellAnime::vtable;
  iVar1 = CellAnime::~CellAnime((CellAnime *)(iVar1 + -0x2674));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  pMVar2 = (MLyt *)(iVar1 + -0x3a8);
  *(undefined ***)pMVar2 = &msys::MLyt::vtable;
  msys::MLyt::term(pMVar2);
  __aeabi_vec_dtor(iVar1 + -0xf8,&LAB_1080080c,0x10,0xc);
  __aeabi_vec_dtor(iVar1 + -0x254,&LAB_108006a4,0x1c,0xc);
  iVar1 = msys::MChrBase::vfunc_0x0(pMVar2);
  *(undefined ***)(iVar1 + -0x3a8) = &msys::MLyt::vtable;
  msys::MLyt::term((MLyt *)(iVar1 + -0x3a8));
  __aeabi_vec_dtor(iVar1 + -0xf8,&LAB_1080080c,0x10,0xc);
  __aeabi_vec_dtor(iVar1 + -0x254,&LAB_108006a4,0x1c,0xc);
  iVar1 = msys::MChrBase::vfunc_0x0((MLyt *)(iVar1 + -0x3a8));
  pMVar2 = (MLyt *)(iVar1 + -0x3a8);
  *(undefined ***)pMVar2 = &msys::MLyt::vtable;
  msys::MLyt::term(pMVar2);
  __aeabi_vec_dtor(iVar1 + -0xf8,&LAB_1080080c,0x10,0xc);
  __aeabi_vec_dtor(iVar1 + -0x254,&LAB_108006a4,0x1c,0xc);
  iVar1 = msys::MChrBase::vfunc_0x0(pMVar2);
  iVar1 = ad::fw::Resource::~Resource((Resource *)(iVar1 + -0x44));
  iVar1 = ad::fw::Resource::~Resource((Resource *)(iVar1 + -0x44));
  iVar1 = msys::MCursorBase::~MCursorBase((MCursorBase *)(iVar1 + -0x6c));
  BCat_PageBase::Core::vfunc_0x0(iVar1 + -0x160);
  return;
}


// FUNC 0x108028fc bcat::BCat_MainPage::vfunc_0x30 (BCat)
//   size 0x30 | file BCat+0x28fc | callers(0) | datarefs 1

void bcat::BCat_MainPage::vfunc_0x30(int param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(0xa18c,*(MemAlcBase **)(param_1 + 0x18),(char *)0x0,0);
  uVar2 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_10801918(pvVar1,param_1);
  }
  *(undefined4 *)(param_1 + 0x20) = uVar2;
  return;
}


// FUNC 0x10802930 bcat::BCat_MainPage::vfunc_0x28 (BCat)
//   size 0x14 | file BCat+0x2930 | callers(0) | datarefs 1

int bcat::BCat_MainPage::vfunc_0x28(int param_1,int param_2)

{
  return *(int *)(param_1 + 0x20) + param_2 * 4 + 0xc;
}


// FUNC 0x10802944 bcat::BCat_MainPage::vfunc_0x24 (BCat)
//   size 0x8 | file BCat+0x2944 | callers(0) | datarefs 1

undefined4 bcat::BCat_MainPage::vfunc_0x24(void)

{
  return 0;
}


// FUNC 0x1080294c bcat::BCat_MainPage::vfunc_0x4 (BCat)
//   size 0x10 | file BCat+0x294c | callers(0) | datarefs 1

void bcat::BCat_MainPage::vfunc_0x4(void)

{
  void *pvVar1;
  
  pvVar1 = (void *)BCat_PageBase::vfunc_0x0();
  operator_delete(pvVar1);
  return;
}


// FUNC 0x1080295c bcat::BCat_PageBase::Core::vfunc_0x10 (BCat)
//   size 0x70 | file BCat+0x295c | callers(0) | datarefs 1

void bcat::BCat_PageBase::Core::vfunc_0x10(int param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = msys::MComSys::_sys;
  if (param_2 == 1) {
    return;
  }
  if (param_2 != 4) {
    return;
  }
  if (*(int *)(param_1 + 8) == 0) {
    *(undefined4 *)(param_1 + 8) = msys::MComSys::_sys;
  }
  *(undefined1 *)(*(int *)(param_1 + 8) + 0xe6508) = 0;
  if (*(int *)(param_1 + 8) == 0) {
    *(undefined4 *)(param_1 + 8) = uVar1;
  }
  *(undefined1 *)(*(int *)(param_1 + 8) + 0xe650a) = 1;
  FUN_108023f0(param_1,0x110017,0,0,0);
  return;
}


// FUNC 0x108029e8 bcat::BCat_PageBase::Core::vfunc_0x8 (BCat)
//   size 0xe4 | file BCat+0x29e8 | callers(0) | datarefs 2

int bcat::BCat_PageBase::Core::vfunc_0x8(int *param_1,MInput *param_2)

{
  MInput MVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  code *extraout_r2;
  code *pcVar5;
  VEC2 *pVVar6;
  bool bVar7;
  uint in_fpscr;
  undefined4 local_20;
  undefined4 local_1c;
  
  msys::MPageBase::updateInputAllChr((MPageBase *)param_1[1],param_2);
  bVar7 = (param_1[9] & 1U) == 0;
  pcVar5 = extraout_r2;
  if (bVar7) {
    pcVar5 = (code *)param_1[8];
  }
  piVar3 = (int *)((int)param_1 + (param_1[9] >> 1));
  if (!bVar7) {
    pcVar5 = *(code **)(*piVar3 + param_1[8]);
  }
  (*pcVar5)(piVar3,param_2);
  MVar1 = param_2[0x11];
  bVar7 = MVar1 == (MInput)0x0;
  if (bVar7) {
    MVar1 = param_2[0x12];
  }
  pVVar6 = (VEC2 *)0x0;
  if (!bVar7 || MVar1 != (MInput)0x0) {
    local_20 = VectorSignedToFloat(*(ushort *)(param_2 + 0x14) - 0xa0,(byte)(in_fpscr >> 0x16) & 3);
    local_1c = VectorSignedToFloat(0x78 - (uint)*(ushort *)(param_2 + 0x16),
                                   (byte)(in_fpscr >> 0x16) & 3);
    pVVar6 = (VEC2 *)&local_20;
  }
  bVar7 = (bool)(**(code **)(*param_1 + 0xc))(param_1,param_2);
  iVar2 = msys::MComSys::_sys;
  iVar4 = param_1[2];
  if (param_1[2] == 0) {
    param_1[2] = msys::MComSys::_sys;
    iVar4 = iVar2;
  }
  ad::ctrl::ButtonGroup::Update
            ((ButtonGroup *)(param_1 + 0xf),pVVar6,(bool)(*(byte *)(iVar4 + 0xe6508) & bVar7),bVar7)
  ;
  return (int)*(char *)((int)param_1 + 0x159);
}


// FUNC 0x10802ad0 bcat::BCat_PageBase::Core::vfunc_0x4 (BCat)
//   size 0x10 | file BCat+0x2ad0 | callers(0) | datarefs 1

void bcat::BCat_PageBase::Core::vfunc_0x4(void)

{
  void *pvVar1;
  
  pvVar1 = (void *)vfunc_0x0();
  operator_delete(pvVar1);
  return;
}


// FUNC 0x10802ae0 bcat::BCat_PageBase::vfunc_0x30 (BCat)
//   size 0x4 | file BCat+0x2ae0 | callers(0) | datarefs 1

void bcat::BCat_PageBase::vfunc_0x30(void)

{
  return;
}


// FUNC 0x10802ae4 bcat::BCat_PageBase::vfunc_0x28 (BCat)
//   size 0x14 | file BCat+0x2ae4 | callers(0) | datarefs 1

int bcat::BCat_PageBase::vfunc_0x28(int param_1,int param_2)

{
  return *(int *)(param_1 + 0x20) + param_2 * 4 + 0xc;
}


// FUNC 0x10802af8 bcat::BCat_PageBase::vfunc_0x8 (BCat)
//   size 0x6c | file BCat+0x2af8 | callers(0) | datarefs 2

void bcat::BCat_PageBase::vfunc_0x8(int *param_1,undefined1 param_2)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  if (param_1[8] == 0) {
    (**(code **)(*param_1 + 0x2c))(param_1);
    (**(code **)(*param_1 + 0x30))(param_1);
    *(undefined1 *)(param_1[8] + 0x158) = param_2;
  }
  iVar1 = param_1[8];
  if ((*(uint *)(iVar1 + 0x14) & 1) == 0) {
    UNRECOVERED_JUMPTABLE = *(code **)(iVar1 + 0x10);
  }
  else {
    UNRECOVERED_JUMPTABLE =
         *(code **)(*(int *)(iVar1 + ((int)*(uint *)(iVar1 + 0x14) >> 1)) + *(int *)(iVar1 + 0x10));
  }
                    /* WARNING: Could not recover jumptable at 0x10802b60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// FUNC 0x10802b64 bcat::BCat_PageBase::vfunc_0x14 (BCat)
//   size 0x10 | file BCat+0x2b64 | callers(0) | datarefs 2

void bcat::BCat_PageBase::vfunc_0x14(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10802b70. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(param_1 + 0x20) + 8))();
  return;
}


// FUNC 0x10802b74 bcat::BCat_PageBase::vfunc_0xc (BCat)
//   size 0xd8 | file BCat+0x2b74 | callers(0) | datarefs 2

void bcat::BCat_PageBase::vfunc_0xc(int param_1)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  int *piVar4;
  int iVar5;
  
  iVar1 = *(int *)(param_1 + 0x20);
  if (iVar1 != 0) {
    piVar4 = (int *)(iVar1 + ((int)*(uint *)(iVar1 + 0x1c) >> 1));
    if ((*(uint *)(iVar1 + 0x1c) & 1) == 0) {
      pcVar3 = *(code **)(iVar1 + 0x18);
    }
    else {
      pcVar3 = *(code **)(*piVar4 + *(int *)(iVar1 + 0x18));
    }
    (*pcVar3)(piVar4);
    if (*(char *)(param_1 + 0x14) == '\0') {
      iVar2 = param_1 + 4;
      iVar1 = *(int *)(param_1 + 8);
      while (iVar1 != iVar2) {
        iVar5 = *(int *)(iVar1 + 4);
        *(int *)(iVar1 + 4) = iVar1;
        *(int *)iVar1 = iVar1;
        iVar1 = iVar5;
      }
      *(int *)(param_1 + 8) = iVar2;
      *(int *)iVar2 = iVar2;
      iVar2 = param_1 + 0xc;
      iVar1 = *(int *)(param_1 + 0x10);
      while (iVar1 != iVar2) {
        iVar5 = *(int *)(iVar1 + 4);
        *(int *)(iVar1 + 4) = iVar1;
        *(int *)iVar1 = iVar1;
        iVar1 = iVar5;
      }
      *(int *)(param_1 + 0x10) = iVar2;
      *(int *)iVar2 = iVar2;
      if (*(int **)(param_1 + 0x20) != (int *)0x0) {
        (**(code **)(**(int **)(param_1 + 0x20) + 4))();
      }
      *(undefined4 *)(param_1 + 0x20) = 0;
      VramAlcRange::merge(*(VramAlcRange **)(param_1 + 0x1c));
      return;
    }
  }
  return;
}


// FUNC 0x10802c4c bcat::BCat_PageBase::vfunc_0x24 (BCat)
//   size 0x8 | file BCat+0x2c4c | callers(0) | datarefs 1

undefined4 bcat::BCat_PageBase::vfunc_0x24(void)

{
  return 0;
}


// FUNC 0x10802c54 bcat::BCat_PageBase::vfunc_0x4 (BCat)
//   size 0x10 | file BCat+0x2c54 | callers(0) | datarefs 1

void bcat::BCat_PageBase::vfunc_0x4(void)

{
  void *pvVar1;
  
  pvVar1 = (void *)vfunc_0x0();
  operator_delete(pvVar1);
  return;
}


// FUNC 0x10802c64 FUN_10802c64 (BCat)
//   size 0x64 | file BCat+0x2c64 | callers(0) | datarefs 4

void FUN_10802c64(MComSys *param_1)

{
  MTX44 aMStack_80 [64];
  MTX34 aMStack_40 [52];
  
  msys::MCamera::getProjMtx((MCamera *)(param_1 + 0x4ad54),aMStack_80,0x400);
  msys::MCamera::getViewMtx((MCamera *)(param_1 + 0x4ad54),aMStack_40);
  ad::fw::TaskBase::setULcdCameraInfoBase(*(TaskBase **)(param_1 + 4),aMStack_40,aMStack_80,1);
  ad::lyt::DrawInfo::SetProjectionMtx((DrawInfo *)(param_1 + 0xe9564),aMStack_80);
  msys::MComSys::funcCalcMainNomal(param_1);
  return;
}


// FUNC 0x10802cd0 bcat::BCat::vfunc_0x10 (BCat)
//   size 0x38 | file BCat+0x2cd0 | callers(0) | datarefs 1

void bcat::BCat::vfunc_0x10(MComSys *param_1,CmdList *param_2)

{
  MTX44 aMStack_50 [68];
  
  msys::MCamera::getProjMtx((MCamera *)(param_1 + 0x4ae34),aMStack_50,0x401);
  msys::MComSys::funcDrawLower(param_1,param_2);
  return;
}


// FUNC 0x10802d10 ->msys::MComSys::funcDrawUpper (BCat)
//   size 0x4 | file BCat+0x2d10 | callers(0) | datarefs 1
// veneer/thunk -> 0x0032e760 msys::MComSys::funcDrawUpper (static)

// FUNC 0x10802d14 FUN_10802d14 (BCat)
//   size 0x3c0 | file BCat+0x2d14 | callers(0) | datarefs 2

void FUN_10802d14(int param_1)

{
  char cVar1;
  int iVar2;
  IAllocator *pIVar3;
  void *pvVar4;
  undefined4 uVar5;
  int *piVar6;
  int iVar7;
  undefined4 *puVar8;
  int *piVar9;
  uint in_r12;
  bool bVar10;
  ulonglong uVar11;
  wchar_t awStackY_450 [128];
  void *local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  uint local_38 [3];
  
  iVar7 = *(int *)(param_1 + 0x278);
  iVar2 = iVar7;
  while( true ) {
    bVar10 = iVar2 != iVar7 + 0x150;
    if (bVar10) {
      in_r12 = (uint)*(byte *)(iVar2 + 4);
    }
    if (!bVar10 || in_r12 == 0) break;
    iVar2 = iVar2 + 0xa8;
  }
  if (iVar2 == iVar7 + 0x150) {
    cVar1 = *(char *)(param_1 + 0xe9050);
    if (cVar1 == '\0') {
      iVar2 = ad::lyt::LytDrawSys::GetInst();
      pIVar3 = (IAllocator *)(iVar2 + 0x5f4);
      if (ad::lyt::Layout::s_pAllocator != pIVar3) {
        ad::lyt::Initialize(pIVar3,pIVar3);
      }
      *(int *)(iVar2 + 0x5f8) = param_1 + 0xc;
      iVar2 = ad::lyt::LytDrawSys::GetInst();
      *(undefined4 *)(iVar2 + 0x5fc) = 0x10000;
      ad::fw::TaskBase::readLyt
                (*(TaskBase **)(param_1 + 4),(Resource *)(param_1 + 0xe90c8),
                 (FileContext *)(*(int *)(param_1 + 0x278) + 0xa8),"SQ_CURSOR_SET",
                 (MemAlcBase *)(param_1 + 0xc),0x7f,(ResCacheArg *)0x0);
      piVar9 = *(int **)(*(int *)(param_1 + 0xe64f0) + 0x44);
      (**(code **)(*piVar9 + 0xc))(piVar9,"MDFXMenuArchive");
      MessageSys::GetPath(awStackY_450 + 0x80,(wchar_t *)L"Menu.msbt",false);
      local_4c = (void *)0x0;
      local_40 = 0;
      local_3c = 0;
      local_48 = 0;
      local_44 = 0;
      uVar11 = nn::fs::CTR::MPCore::detail::UserFileSystem::TryOpenFile
                         (&local_4c,awStackY_450 + 0x80,1);
      uVar5 = (undefined4)(uVar11 >> 0x20);
      bVar10 = (uVar11 & 0x80000000) != 0;
      if (bVar10) {
        uVar5 = 0x10802f30;
      }
      if (bVar10 && (int)uVar11 < 0) {
        nn::err::CTR::ThrowFatalErrAll((int)uVar11,uVar5);
      }
      iVar2 = nn::fs::detail::FileBase::TryGetSize((FileBase *)&local_4c,(longlong *)local_38);
      if (iVar2 < 0) {
        nn::err::CTR::ThrowFatalErrAll(iVar2,0x10802f60);
      }
      pvVar4 = (void *)(**(code **)(*(int *)(param_1 + 0xc) + 0xc))(param_1 + 0xc,local_38[0],0);
      *(void **)(param_1 + 0xe9130) = pvVar4;
      iVar2 = nn::fs::detail::FileBase::TryRead
                        ((FileBase *)&local_4c,(int *)local_38,pvVar4,local_38[0]);
      if (iVar2 < 0) {
        nn::err::CTR::ThrowFatalErrAll(iVar2,0x10802fa0);
      }
      MsgDataAcsrBase::init((MsgDataAcsrBase *)(param_1 + 0xe9134),*(void **)(param_1 + 0xe9130));
      if (((uint)local_4c & 0xfffffffe) != 0) {
        if (((uint)local_4c & 1) != 0) {
          nndbgPanic();
        }
        nn::fs::CTR::MPCore::detail::UserFileSystem::CloseFile
                  ((void *)((uint)local_4c & 0xfffffffe));
      }
      *(undefined1 *)(param_1 + 0xe9050) = 1;
      return;
    }
    if (cVar1 == '\x01') {
      if (*(char *)(param_1 + 0xe90cc) != '\0') {
        ad::lyt::LytResourceMan::init((LytResourceMan *)(param_1 + 2000));
        pvVar4 = (void *)ad::fw::Resource::getFileData((Resource *)(param_1 + 0xe90c8));
        ad::lyt::LytResourceMan::registerArc((LytResourceMan *)(param_1 + 2000),pvVar4,".");
        msys::MLyt::init((MLyt *)(param_1 + 0xe91bc),param_1 + 0xd3000,0);
        msys::MLyt::createLyt
                  ((MLyt *)(param_1 + 0xe91bc),(LytResourceMan *)(param_1 + 2000),"SQ_CURSOR.bflyt")
        ;
        MoveVBase::stop((MoveVBase *)(param_1 + 0xe9288));
        *(undefined4 *)(param_1 + 0xe92a4) = 0;
        *(undefined4 *)(param_1 + 0xe92a8) = 0;
        *(undefined4 *)(param_1 + 0xe92ac) = 0xc347cccd;
        piVar6 = (int *)(param_1 + 0xe64e0);
        *(undefined4 *)(param_1 + 0xe928c) = *(undefined4 *)(param_1 + 0xe92a4);
        *(undefined4 *)(param_1 + 0xe9290) = 0;
        *(undefined4 *)(param_1 + 0xe9294) = 0xc347cccd;
        *(undefined1 *)(param_1 + 0xe92fd) = 0;
        *(undefined4 *)(param_1 + 0xe92f8) = 0x401;
        puVar8 = *(undefined4 **)(param_1 + 0xe91c4);
        *(undefined4 **)(*(int *)(param_1 + 0xe91c0) + 4) = puVar8;
        *puVar8 = *(undefined4 *)(param_1 + 0xe91c0);
        piVar9 = (int *)(param_1 + 0xe91c0);
        if (piVar9 != (int *)0x0) {
          *(int **)(param_1 + 0xe91c4) = piVar6;
          *piVar9 = *piVar6;
          *(int **)(*piVar6 + 4) = piVar9;
          *piVar6 = (int)piVar9;
        }
        *(undefined1 *)(param_1 + 0xe9050) = 2;
        return;
      }
    }
    else if (cVar1 == '\x02') {
      *(code **)(param_1 + 0xf84) = FUN_10803148;
      *(undefined4 *)(param_1 + 0xf88) = 0;
      piVar9 = *(int **)(param_1 + *(char *)((int)*(char *)(param_1 + 0xfd7) + param_1 + 0xfcd) * 4
                        + 0xf8c);
      (**(code **)(*piVar9 + 8))(piVar9,0xffffffff);
      if ((char)piVar9[5] != '\0') {
        MoveC::moveFrm((MoveC *)(param_1 + 0x4acd4),(Color8 *)(awStackY_450 + 0x80),16.0);
        MoveC::moveFrm((MoveC *)(param_1 + 0x4ad14),(Color8 *)(awStackY_450 + 0x80),16.0);
        *(undefined1 *)(param_1 + 0xe6508) = 1;
        *(undefined1 *)(param_1 + 0x4af14) = 1;
        *(code **)(param_1 + 0xf84) = FUN_10802c64;
        *(undefined4 *)(param_1 + 0xf88) = 0;
      }
    }
  }
  return;
}


// FUNC 0x10803148 FUN_10803148 (BCat)
//   size 0xbc | file BCat+0x3148 | callers(0) | datarefs 1

void FUN_10803148(int param_1)

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
    *(undefined1 *)(param_1 + 0xe6508) = 1;
    *(undefined1 *)(param_1 + 0x4af14) = 1;
    *(code **)(param_1 + 0xf84) = FUN_10802c64;
    *(undefined4 *)(param_1 + 0xf88) = 0;
  }
  return;
}


// FUNC 0x1080321c FUN_1080321c (BCat)
//   size 0x1dc | file BCat+0x321c | callers(1) 0x10800528

void FUN_1080321c(MComSys *param_1,MTaskBase *param_2)

{
  int iVar1;
  IAllocator *pIVar2;
  undefined4 *puVar3;
  Job *pJVar4;
  undefined4 uVar5;
  
  msys::MComSys::initBaseSys
            (param_1,param_2,0x100000,0x400000,0x400000,0x100000,0x180000,2,'\0',false);
  iVar1 = ad::lyt::LytDrawSys::GetInst();
  pIVar2 = (IAllocator *)(iVar1 + 0x5f4);
  if (ad::lyt::Layout::s_pAllocator != pIVar2) {
    ad::lyt::Initialize(pIVar2,pIVar2);
  }
  *(MComSys **)(iVar1 + 0x5f8) = param_1 + 0xc;
  puVar3 = operator_new(4,(MemAlcBase *)(param_1 + 0xc),(char *)0x0,0);
  if (puVar3 != (undefined4 *)0x0) {
    *puVar3 = 0x41e80000;
  }
  *(undefined4 **)(param_1 + 0xe904c) = puVar3;
  msys::MComSys::entryPage(param_1,(MPageBase *)(param_1 + 0xe910c));
  iVar1 = *(int *)(param_1 + 4);
  uVar5 = *(undefined4 *)(param_1 + 0x278);
  pJVar4 = operator_new(0x20,(MemAlcBase *)(iVar1 + 0x55c),(char *)0x0,0);
  if (pJVar4 != (Job *)0x0) {
    *(undefined ***)pJVar4 = &vtable_for_N2ad2fw11FileContext7InitJobIPS1_EE;
    *(undefined4 *)(pJVar4 + 4) = 0;
    *(undefined4 *)(pJVar4 + 8) = uVar5;
    *(undefined4 *)(pJVar4 + 0x14) = 2;
    *(undefined **)(pJVar4 + 0x10) = &DAT_1080427c;
    *(MComSys **)(pJVar4 + 0xc) = param_1 + 0xc;
    uVar5 = *(undefined4 *)(iVar1 + 0x4d8);
    *(undefined4 *)(pJVar4 + 0x18) = *(undefined4 *)(iVar1 + 0x4d4);
    *(undefined4 *)(pJVar4 + 0x1c) = uVar5;
  }
  CtrJobMan::enqueue((CtrJobMan *)(iVar1 + 0x4dc),pJVar4);
  param_1[0xd30e0] = (MComSys)0x0;
  param_1[0xd30e1] = (MComSys)0x0;
  param_1[0xd30e2] = (MComSys)0x1;
  param_1[0xd30c9] = (MComSys)0x1;
  param_1[0xd2fe0] = (MComSys)0x1;
  param_1[0xd2fe1] = (MComSys)0x1;
  param_1[0xd2fe2] = (MComSys)0x1;
  param_1[0xd2fc9] = (MComSys)0x1;
  param_1[0xbfb78] = (MComSys)0x0;
  Prim::disableDepthTest((Prim *)(param_1 + 0xac2d8));
  msys::MComSys::setupCamU(param_1);
  msys::MComSys::setupCamL(param_1);
  param_1[0x4ad85] = (MComSys)0x1;
  param_1[0x4ae65] = (MComSys)0x1;
  param_1[0xe6508] = (MComSys)0x0;
  param_1[0xe9050] = (MComSys)0x0;
  *(code **)(param_1 + 0xf84) = FUN_10802d14;
  *(undefined4 *)(param_1 + 0xf88) = 0;
  return;
}


// FUNC 0x10803424 FUN_10803424 (BCat)
//   size 0x150 | file BCat+0x3424 | callers(1) 0x10800528

int FUN_10803424(MComSys *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_18;
  
  local_18 = param_4;
  puVar1 = (undefined4 *)msys::MComSys::MComSys(param_1);
  *puVar1 = &bcat::BCat::vtable;
  puVar1[0x3a415] = 0;
  iVar2 = ad::font::ResFont::ResFont((ResFont *)(puVar1 + 0x3a416));
  ad::lyt::LytResourceMan::init((LytResourceMan *)(iVar2 + -4));
  iVar2 = ad::fw::Resource::Resource((Resource *)(iVar2 + 0x70));
  *(int *)(iVar2 + 0x48) = iVar2 + 0x48;
  *(int *)(iVar2 + 0x4c) = iVar2 + 0x48;
  *(int *)(iVar2 + 0x50) = iVar2 + 0x50;
  *(int *)(iVar2 + 0x54) = iVar2 + 0x50;
  *(undefined1 *)(iVar2 + 0x58) = 0;
  *(undefined4 *)(iVar2 + 0x5c) = 0;
  *(undefined4 *)(iVar2 + 0x60) = 0;
  *(undefined ***)(iVar2 + 0x44) = &bcat::BCat_MainPage::vtable;
  *(undefined4 *)(iVar2 + 100) = 0;
  puVar1 = (undefined4 *)
           MsgDataAcsrBase::MsgDataAcsrBase
                     ((MsgDataAcsrBase *)(iVar2 + 0x6c),(LMSBlockInfo *)(iVar2 + 0x98),4);
  *puVar1 = &vtable_for_20MsgDataAcsrTmplFixedILh4EE;
  iVar2 = ad::ctrl::ButtonGroup::ButtonGroup((ButtonGroup *)(puVar1 + 0x1b));
  puVar1 = (undefined4 *)FUN_1080206c(iVar2 + 0x1c);
  *puVar1 = &msys::MLyt::vtable;
  *(undefined1 *)(puVar1 + 0x53) = 0xff;
  *(undefined2 *)((int)puVar1 + 0x14e) = 0;
  puVar1[0x54] = 0;
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(puVar1 + 0x55,&LAB_10800668,0x1c,0xc);
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(iVar2 + 0x15c,&LAB_108007dc,0x10,0xc);
  *(undefined4 *)(iVar2 + 0xc0) = 0;
  *(undefined1 *)(iVar2 + 0xc4) = 1;
  *(undefined4 *)(iVar2 + 200) = 0;
  *(undefined4 *)(iVar2 + 0xcc) = 0;
  *(undefined1 *)(iVar2 + 0xd0) = 0;
  *(undefined4 *)(iVar2 + 0xd4) = 0;
  *(undefined4 *)(iVar2 + 0xd8) = 0;
  FUN_10802050(iVar2 + -0xc,0xffffffff);
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(iVar2 + 0xf8,FUN_108005ec,0x100,2);
  local_18 = 0xff808080;
  FrameBuf::setClearColor((FrameBuf *)&gFrameBuf,&local_18);
  return iVar2 + -0xe9564;
}


// FUNC 0x108035a0 bcat::BCat::vfunc_0x4 (BCat)
//   size 0x10 | file BCat+0x35a0 | callers(0) | datarefs 1

void bcat::BCat::vfunc_0x4(void)

{
  void *pvVar1;
  
  pvVar1 = (void *)vfunc_0x0();
  operator_delete(pvVar1);
  return;
}


// FUNC 0x108035b0 bcat::BCatTask::vfunc_0x10 (BCat)
//   size 0x1c | file BCat+0x35b0 | callers(0) | datarefs 1

void bcat::BCatTask::vfunc_0x10(TaskMainBase *param_1)

{
  if (*(char *)(*(int *)(param_1 + 0x580) + 0xe9049) == '\0') {
    return;
  }
  GameMain::Back(param_1);
  return;
}


// FUNC 0x108035cc bcat::BCatTask::vfunc_0x8 (BCat)
//   size 0x24 | file BCat+0x35cc | callers(0) | datarefs 1

void bcat::BCatTask::vfunc_0x8(undefined4 *param_1)

{
  int iVar1;
  void *pvVar2;
  
  *param_1 = &vtable;
  iVar1 = BCat::vfunc_0x0(param_1 + 0x161);
  pvVar2 = (void *)ad::fw::TaskBase::~TaskBase((TaskBase *)(iVar1 + -0x584));
  operator_delete(pvVar2);
  return;
}


// FUNC 0x108035f4 bcat::BCatTask::vfunc_0x4 (BCat)
//   size 0x20 | file BCat+0x35f4 | callers(0) | datarefs 1

void bcat::BCatTask::vfunc_0x4(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &vtable;
  iVar1 = BCat::vfunc_0x0(param_1 + 0x161);
  ad::fw::TaskBase::~TaskBase((TaskBase *)(iVar1 + -0x584));
  return;
}


// FUNC 0x10803618 FUN_10803618 (BCat)
//   size 0x30 | file BCat+0x3618 | callers(0) | datarefs 1

int FUN_10803618(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)FUN_1080206c();
  *puVar1 = &msys::MCellAnime::vtable;
  iVar2 = CellAnime::CellAnime((CellAnime *)(puVar1 + 0x53));
  *(undefined1 *)(iVar2 + 300) = 0xff;
  *(undefined1 *)(iVar2 + 0x12d) = 0xff;
  *(undefined1 *)(iVar2 + 0x12e) = 0xff;
  *(undefined1 *)(iVar2 + 0x12f) = 0xff;
  return iVar2 + -0x14c;
}


// FUNC 0x1080366c msys::MChrBase::vfunc_0x10 (BCat)
//   size 0xc | file BCat+0x366c | callers(0) | datarefs 1

void msys::MChrBase::vfunc_0x10(int param_1)

{
  *(undefined1 *)(param_1 + 0x142) = 0;
  return;
}


// FUNC 0x10803678 msys::MChrBase::vfunc_0xc (BCat)
//   size 0x4 | file BCat+0x3678 | callers(0) | datarefs 1

void msys::MChrBase::vfunc_0xc(void)

{
  return;
}


// FUNC 0x1080367c msys::MChrBase::vfunc_0x8 (BCat)
//   size 0xc | file BCat+0x367c | callers(0) | datarefs 1

void msys::MChrBase::vfunc_0x8(int param_1)

{
  *(undefined1 *)(param_1 + 0x142) = 1;
  return;
}


// FUNC 0x10803688 msys::MChrBase::vfunc_0x18 (BCat)
//   size 0x4 | file BCat+0x3688 | callers(0) | datarefs 1

void msys::MChrBase::vfunc_0x18(void)

{
  return;
}


// FUNC 0x1080368c bcat::BCat::vfunc_0x14 (BCat)
//   size 0x8 | file BCat+0x368c | callers(0) | datarefs 1

undefined4 bcat::BCat::vfunc_0x14(void)

{
  return 0;
}


// FUNC 0x10803694 msys::MChrBase::vfunc_0x4 (BCat)
//   size 0x10 | file BCat+0x3694 | callers(0) | datarefs 1

void msys::MChrBase::vfunc_0x4(void)

{
  void *pvVar1;
  
  pvVar1 = (void *)vfunc_0x0();
  operator_delete(pvVar1);
  return;
}


// FUNC 0x108036a4 bcat::BCat_PageBase::vfunc_0x20 (BCat)
//   size 0x8 | file BCat+0x36a4 | callers(0) | datarefs 2

void bcat::BCat_PageBase::vfunc_0x20(MPageBase *param_1,undefined4 param_2,MRenderQueue *param_3)

{
  msys::MPageBase::enqueueLowerChr(param_1,param_3);
  return;
}


// FUNC 0x108036ac bcat::BCat_PageBase::vfunc_0x1c (BCat)
//   size 0x8 | file BCat+0x36ac | callers(0) | datarefs 2

void bcat::BCat_PageBase::vfunc_0x1c(MPageBase *param_1,undefined4 param_2,MRenderQueue *param_3)

{
  msys::MPageBase::enqueueUpperChr(param_1,param_3);
  return;
}


// FUNC 0x108036b4 FUN_108036b4 (BCat)
//   size 0x34 | file BCat+0x36b4 | callers(0) | datarefs 1

void FUN_108036b4(MoveVBase *param_1)

{
  void *pvVar1;
  
  *(undefined ***)param_1 = &vtable_for_5MoveVILj1EE;
  __aeabi_vec_dtor(param_1 + 0x30,MoveWorkF::~MoveWorkF,0x2c,1);
  pvVar1 = (void *)MoveVBase::~MoveVBase(param_1);
  operator_delete(pvVar1);
  return;
}


// FUNC 0x108036f0 FUN_108036f0 (BCat)
//   size 0x30 | file BCat+0x36f0 | callers(0) | datarefs 1

void FUN_108036f0(MoveVBase *param_1)

{
  *(undefined ***)param_1 = &vtable_for_5MoveVILj1EE;
  __aeabi_vec_dtor(param_1 + 0x30,MoveWorkF::~MoveWorkF,0x2c,1);
  MoveVBase::~MoveVBase(param_1);
  return;
}


// FUNC 0x10803728 FUN_10803728 (BCat)
//   size 0x2c | file BCat+0x3728 | callers(0) | datarefs 3

undefined4 * FUN_10803728(MoveWorkF *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)MoveWorkF::MoveWorkF(param_1);
  *puVar1 = &MoveWorkV::vtable;
  puVar1[8] = 0;
  puVar1[9] = 0;
  puVar1[10] = 0;
  return puVar1;
}


// FUNC 0x1080375c MoveWorkV::vfunc_0x4 (BCat)
//   size 0x10 | file BCat+0x375c | callers(0) | datarefs 1

void MoveWorkV::vfunc_0x4(MoveWorkF *param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)MoveWorkF::~MoveWorkF(param_1);
  operator_delete(pvVar1);
  return;
}


// FUNC 0x1080376c ->MoveWorkF::~MoveWorkF (BCat)
//   size 0x4 | file BCat+0x376c | callers(0) | datarefs 6
// veneer/thunk -> 0x00340694 MoveWorkF::~MoveWorkF (static)

// FUNC 0x10803770 MemAlcH::vfunc_0x10 (BCat)
//   size 0x4 | file BCat+0x3770 | callers(0) | datarefs 1

void MemAlcH::vfunc_0x10(void)

{
  return;
}


// FUNC 0x10803774 MemAlcH::vfunc_0x14 (BCat)
//   size 0x4 | file BCat+0x3774 | callers(0) | datarefs 1

void MemAlcH::vfunc_0x14(void)

{
  return;
}


// FUNC 0x10803778 nn::fs::FileInputStream::vfunc_0x20 (BCat)
//   size 0x8 | file BCat+0x3778 | callers(0) | datarefs 1

void nn::fs::FileInputStream::vfunc_0x20(int param_1,longlong *param_2)

{
  detail::FileBase::TryGetSize((FileBase *)(param_1 + 4),param_2);
  return;
}


// FUNC 0x10803780 nn::fs::FileInputStream::vfunc_0x14 (BCat)
//   size 0x8 | file BCat+0x3780 | callers(0) | datarefs 1

undefined8 nn::fs::FileInputStream::vfunc_0x14(int param_1)

{
  return *(undefined8 *)(param_1 + 8);
}


// FUNC 0x10803788 nn::fs::FileInputStream::vfunc_0x10 (BCat)
//   size 0x14 | file BCat+0x3788 | callers(0) | datarefs 1

undefined4 nn::fs::FileInputStream::vfunc_0x10(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 0xc);
  *param_2 = *(undefined4 *)(param_1 + 8);
  param_2[1] = uVar1;
  return 0;
}


// FUNC 0x1080379c nn::fs::FileInputStream::vfunc_0x24 (BCat)
//   size 0x2c | file BCat+0x379c | callers(0) | datarefs 1

longlong nn::fs::FileInputStream::vfunc_0x24(int param_1)

{
  int iVar1;
  longlong local_10;
  
  iVar1 = detail::FileBase::TryGetSize((FileBase *)(param_1 + 4),&local_10);
  if (iVar1 < 0) {
    err::CTR::ThrowFatalErrAll(iVar1,0x108037b8);
  }
  return local_10;
}


// FUNC 0x108037c8 FUN_108037c8 (BCat)
//   size 0x2c | file BCat+0x37c8 | callers(0) | datarefs 1

bool FUN_108037c8(int *param_1,uint param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 8))();
  return (uVar1 & param_3) == param_2;
}


// FUNC 0x108037f4 FUN_108037f4 (BCat)
//   size 0x8 | file BCat+0x37f4 | callers(0) | datarefs 1

undefined4 FUN_108037f4(void)

{
  return 0;
}


// FUNC 0x108037fc bcat::BCat_PageBase::Core::vfunc_0xc (BCat)
//   size 0x10 | file BCat+0x37fc | callers(0) | datarefs 2

bool bcat::BCat_PageBase::Core::vfunc_0xc(undefined4 param_1,int param_2)

{
  return *(char *)(param_2 + 0x12) != '\0';
}


// FUNC 0x1080380c BCat::nnroControlObject_ (BCat)
//   size 0x74 | file BCat+0x380c | callers(0)

undefined4 BCat::nnroControlObject_(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined *puVar2;
  
  switch(param_2) {
  case 0:
    uVar1 = 0;
    break;
  case 1:
    DAT_10809768 = param_1;
    return 0;
  case 2:
    uVar1 = DAT_10809768;
    break;
  case 3:
    *param_1 = &DAT_108039a8;
    puVar2 = &DAT_108039a8;
    goto LAB_1080386c;
  case 4:
    *param_1 = &DAT_108051f0;
    puVar2 = &DAT_108051f0;
LAB_1080386c:
    param_1[1] = puVar2;
    return 0;
  default:
    return 0xd8e12c21;
  }
  *param_1 = uVar1;
  return 0;
}


// FUNC 0x108038b8 FUN_108038b8 (BCat)
//   size 0xac | file BCat+0x38b8 | callers(0) | datarefs 1

void FUN_108038b8(int param_1)

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


// FUNC 0x10803964 ->operator.delete (BCat)
//   size 0x4 | file BCat+0x3964 | callers(0) | datarefs 1
// veneer/thunk -> 0x00286514 operator.delete (static)

// FUNC 0x10803968 FUN_10803968 (BCat)
//   size 0x4 | file BCat+0x3968 | callers(0) | datarefs 1

void FUN_10803968(void)

{
  return;
}


// FUNC 0x1080396c FUN_1080396c (BCat)
//   size 0x28 | file BCat+0x396c | callers(0) | datarefs 1

void FUN_1080396c(float param_1,MCursorBase *param_2,MLyt *param_3)

{
  MCursorBase *pMVar1;
  int iVar2;
  
  msys::MCursorBase::init(param_2,param_3,param_1);
  iVar2 = 0xf;
  pMVar1 = param_2 + 0x30;
  do {
    iVar2 = iVar2 + -1;
    *(undefined4 *)pMVar1 = 0;
    pMVar1 = pMVar1 + 4;
  } while (iVar2 != 0);
  return;
}


// FUNC 0x10803994 FUN_10803994 (BCat)
//   size 0x10 | file BCat+0x3994 | callers(0) | datarefs 1

void FUN_10803994(MCursorBase *param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)msys::MCursorBase::~MCursorBase(param_1);
  operator_delete(pvVar1);
  return;
}


// FUNC 0x108039a4 ->msys::MCursorBase::~MCursorBase (BCat)
//   size 0x4 | file BCat+0x39a4 | callers(0) | datarefs 1
// veneer/thunk -> 0x00324600 msys::MCursorBase::~MCursorBase (static)

