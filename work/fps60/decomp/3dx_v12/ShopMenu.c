// fps60 TG decompiled C: 3dx_v12.code.bin module ShopMenu part 1 (Ghidra 12.2, ARM:LE:32:v6:hardfp)
// Addresses: static = runtime address; CRO = fixed analysis base (crolink.py), NOT runtime.

// FUNC 0x17000180 ->operator.new (ShopMenu)
//   size 0x4 | file ShopMenu+0x180 | callers(8) 0x170008a8 0x17014174 0x17000924 0x17007c74 0x1700d450 0x1700e720 0x17011254 0x17012678
// veneer/thunk -> 0x00287d40 operator.new (static)

// FUNC 0x17000188 ->msys::MTaskBase::MTaskBase (ShopMenu)
//   size 0x4 | file ShopMenu+0x188 | callers(1) 0x170008a8
// veneer/thunk -> 0x00334688 msys::MTaskBase::MTaskBase (static)

// FUNC 0x17000190 ->TaskMan::entry (ShopMenu)
//   size 0x4 | file ShopMenu+0x190 | callers(1) 0x170008a8
// veneer/thunk -> 0x00287b18 TaskMan::entry (static)

// FUNC 0x17000198 ->operator.delete (ShopMenu)
//   size 0x4 | file ShopMenu+0x198 | callers(30) 0x17001270 0x17000924 0x1700b4d8 0x17014ee0 0x1700117c 0x1700131c 0x17001628 0x170017a0 ...
// veneer/thunk -> 0x00286514 operator.delete (static)

// FUNC 0x170001a0 ->MsgDataAcsrBase::~MsgDataAcsrBase (ShopMenu)
//   size 0x4 | file ShopMenu+0x1a0 | callers(3) 0x1700117c 0x1700118c 0x1700b4d8
// veneer/thunk -> 0x0026fdb4 MsgDataAcsrBase::~MsgDataAcsrBase (static)

// FUNC 0x170001a8 ->ad::lyt::DrawInfo::DrawInfo (ShopMenu)
//   size 0x4 | file ShopMenu+0x1a8 | callers(1) 0x170011e4
// veneer/thunk -> 0x00264fd4 ad::lyt::DrawInfo::DrawInfo (static)

// FUNC 0x170001b0 ->nn::gr::CTR::RenderState::WBuffer::WBuffer (ShopMenu)
//   size 0x4 | file ShopMenu+0x1b0 | callers(1) 0x170011e4
// veneer/thunk -> 0x00264fa0 nn::gr::CTR::RenderState::WBuffer::WBuffer (static)

// FUNC 0x170001b8 ->ad::lyt::DrawInfo::~DrawInfo (ShopMenu)
//   size 0x4 | file ShopMenu+0x1b8 | callers(1) 0x1700125c
// veneer/thunk -> 0x00164660 ad::lyt::DrawInfo::~DrawInfo (static)

// FUNC 0x170001c0 ->nn::fs::detail::FileBase::TrySetPosition (ShopMenu)
//   size 0x4 | file ShopMenu+0x1c0 | callers(2) 0x17001278 0x1700129c
// veneer/thunk -> 0x0027ec28 nn::fs::detail::FileBase::TrySetPosition (static)

// FUNC 0x170001c8 ->nn::err::CTR::ThrowFatalErrAll (ShopMenu)
//   size 0x4 | file ShopMenu+0x1c8 | callers(5) 0x170012a4 0x17014cec 0x17001278 0x170012d0 0x17012c3c
// veneer/thunk -> 0x00286530 nn::err::CTR::ThrowFatalErrAll (static)

// FUNC 0x170001d0 ->nn::fs::detail::FileBase::TryRead (ShopMenu)
//   size 0x4 | file ShopMenu+0x1d0 | callers(3) 0x170012a4 0x170012fc 0x17012c3c
// veneer/thunk -> 0x00286488 nn::fs::detail::FileBase::TryRead (static)

// FUNC 0x170001d8 ->nn::fs::detail::FileBase::TrySeek (ShopMenu)
//   size 0x4 | file ShopMenu+0x1d8 | callers(2) 0x170012d0 0x17001304
// veneer/thunk -> 0x002854d0 nn::fs::detail::FileBase::TrySeek (static)

// FUNC 0x170001e0 ->nndbgPanic (ShopMenu)
//   size 0x4 | file ShopMenu+0x1e0 | callers(3) 0x1700131c 0x1700135c 0x17012c3c
// veneer/thunk -> 0x0028642c nndbgPanic (static)

// FUNC 0x170001e8 ->nn::fs::CTR::MPCore::detail::UserFileSystem::CloseFile (ShopMenu)
//   size 0x4 | file ShopMenu+0x1e8 | callers(3) 0x1700131c 0x1700135c 0x17012c3c
// veneer/thunk -> 0x00286410 nn::fs::CTR::MPCore::detail::UserFileSystem::CloseFile (static)

// FUNC 0x170001f0 ->CellAnime::CellAnime (ShopMenu)
//   size 0x4 | file ShopMenu+0x1f0 | callers(8) 0x170144fc 0x1700789c 0x1700d164 0x17010d74 0x17012388 0x170013e4 0x170037e4 0x1700d4f8
// veneer/thunk -> 0x0026be18 CellAnime::CellAnime (static)

// FUNC 0x170001f8 ->CellAnime::~CellAnime (ShopMenu)
//   size 0x4 | file ShopMenu+0x1f8 | callers(12) 0x1700b9d8 0x1700b4d8 0x1700b030 0x17007ad4 0x1700d294 0x1700d374 0x17011070 0x170124bc ...
// veneer/thunk -> 0x0024fc94 CellAnime::~CellAnime (static)

// FUNC 0x17000200 ->ad::lyt::LytNumReel2::update (ShopMenu)
//   size 0x4 | file ShopMenu+0x200 | callers(1) 0x1700147c
// veneer/thunk -> 0x00159ea0 ad::lyt::LytNumReel2::update (static)

// FUNC 0x17000208 ->ad::lyt::LytNumReel2::term (ShopMenu)
//   size 0x4 | file ShopMenu+0x208 | callers(3) 0x17001628 0x17001664 0x1700b4d8
// veneer/thunk -> 0x00159e18 ad::lyt::LytNumReel2::term (static)

// FUNC 0x17000210 ->ad::lyt::LytNumReel2::~LytNumReel2 (ShopMenu)
//   size 0x4 | file ShopMenu+0x210 | callers(3) 0x17001628 0x17001664 0x1700b4d8
// veneer/thunk -> 0x0015a114 ad::lyt::LytNumReel2::~LytNumReel2 (static)

// FUNC 0x17000218 ->ad::ui::UIListWindowPlusLyt::~UIListWindowPlusLyt (ShopMenu)
//   size 0x4 | file ShopMenu+0x218 | callers(6) 0x170017a0 0x170017b0 0x170017cc 0x170017f0 0x1700b9d8 0x1700b030
// veneer/thunk -> 0x0025a3fc ad::ui::UIListWindowPlusLyt::~UIListWindowPlusLyt (static)

// FUNC 0x17000220 ->msys::MListWndPBase::~MListWndPBase (ShopMenu)
//   size 0x4 | file ShopMenu+0x220 | callers(4) 0x170017cc 0x170017f0 0x1700b9d8 0x1700b030
// veneer/thunk -> 0x003288a0 msys::MListWndPBase::~MListWndPBase (static)

// FUNC 0x17000228 ->msys::MPageBase::enqueueLowerChr (ShopMenu)
//   size 0x4 | file ShopMenu+0x228 | callers(1) 0x17001810
// veneer/thunk -> 0x00334104 msys::MPageBase::enqueueLowerChr (static)

// FUNC 0x17000230 ->msys::MPageBase::enqueueUpperChr (ShopMenu)
//   size 0x4 | file ShopMenu+0x230 | callers(1) 0x17001818
// veneer/thunk -> 0x00334184 msys::MPageBase::enqueueUpperChr (static)

// FUNC 0x17000238 ->ad::lyt::LytAnim::stopAndSetFrm (ShopMenu)
//   size 0x4 | file ShopMenu+0x238 | callers(10) 0x17001820 0x17002d18 0x1700983c 0x1700fef4 0x17008df4 0x17009d94 0x17004c24 0x170031f0 ...
// veneer/thunk -> 0x0026fe44 ad::lyt::LytAnim::stopAndSetFrm (static)

// FUNC 0x17000240 ->CellAnime::play (ShopMenu)
//   size 0x4 | file ShopMenu+0x240 | callers(7) 0x17001850 0x17008410 0x1700e770 0x17008b20 0x17012c3c 0x1700a4cc 0x17003554
// veneer/thunk -> 0x0027bee0 CellAnime::play (static)

// FUNC 0x17000248 ->msys::MCellAnime::init (ShopMenu)
//   size 0x4 | file ShopMenu+0x248 | callers(8) 0x1700e770 0x17001b3c 0x17009d94 0x17012c3c 0x17001880 0x17003628 0x17001900 0x17001a24
// veneer/thunk -> 0x002079d8 msys::MCellAnime::init (static)

// FUNC 0x17000250 ->msys::MLyt::attachMChrF (ShopMenu)
//   size 0x4 | file ShopMenu+0x250 | callers(3) 0x1700e770 0x17009d94 0x17001880
// veneer/thunk -> 0x0032b908 msys::MLyt::attachMChrF (static)

// FUNC 0x17000258 ->msys::MLyt::getPane (ShopMenu)
//   size 0x4 | file ShopMenu+0x258 | callers(18) 0x17002f14 0x17003c7c 0x170099b8 0x1700ba88 0x1701004c 0x17007cc0 0x1700e770 0x17001b3c ...
// veneer/thunk -> 0x0032c688 msys::MLyt::getPane (static)

// FUNC 0x17000260 ->msys::MLyt::attachMChr (ShopMenu)
//   size 0x4 | file ShopMenu+0x260 | callers(14) 0x17002f14 0x1700ba88 0x17012b94 0x1700e770 0x17001b3c 0x170112a4 0x17012b04 0x17012c3c ...
// veneer/thunk -> 0x00207468 msys::MLyt::attachMChr (static)

// FUNC 0x17000268 ->MessageSimple::init (ShopMenu)
//   size 0x4 | file ShopMenu+0x268 | callers(10) 0x17002f14 0x1700ba88 0x17001b3c 0x17012c3c 0x17001e94 0x17002068 0x17003628 0x17001900 ...
// veneer/thunk -> 0x002736b4 MessageSimple::init (static)

// FUNC 0x17000270 ->MessageWriter::setFontColor (ShopMenu)
//   size 0x4 | file ShopMenu+0x270 | callers(8) 0x1700ba88 0x17001b3c 0x17012c3c 0x17001e94 0x17002068 0x17003628 0x17001900 0x17001a24
// veneer/thunk -> 0x00270f0c MessageWriter::setFontColor (static)

// FUNC 0x17000278 ->LMS_GetTextIndexByLabel (ShopMenu)
//   size 0x4 | file ShopMenu+0x278 | callers(11) 0x1700b110 0x1700917c 0x1700e770 0x17001b3c 0x1700a5b0 0x17009a4c 0x17008b20 0x17012c3c ...
// veneer/thunk -> 0x0027616c LMS_GetTextIndexByLabel (static)

// FUNC 0x17000280 ->LMS_GetText (ShopMenu)
//   size 0x4 | file ShopMenu+0x280 | callers(11) 0x1700b110 0x1700917c 0x1700e770 0x17001b3c 0x1700a5b0 0x17009a4c 0x17008b20 0x17012c3c ...
// veneer/thunk -> 0x0027660c LMS_GetText (static)

// FUNC 0x17000288 ->msys::MMsg::playStr (ShopMenu)
//   size 0x4 | file ShopMenu+0x288 | callers(10) 0x1700bc6c 0x1700979c 0x17008410 0x1700e770 0x17001b3c 0x17008b20 0x17012c3c 0x17002068 ...
// veneer/thunk -> 0x0032ce0c msys::MMsg::playStr (static)

// FUNC 0x17000290 ->msys::MDfxChr::init (ShopMenu)
//   size 0x4 | file ShopMenu+0x290 | callers(5) 0x17002f14 0x17003c7c 0x1700ba88 0x17007cc0 0x17001b3c
// veneer/thunk -> 0x003309c0 msys::MDfxChr::init (static)

// FUNC 0x17000298 ->msys::MLyt::getMPaneRef (ShopMenu)
//   size 0x4 | file ShopMenu+0x298 | callers(1) 0x17001e94
// veneer/thunk -> 0x0032ba20 msys::MLyt::getMPaneRef (static)

// FUNC 0x170002a0 ->msys::MChrBaseCore::setParent (ShopMenu)
//   size 0x4 | file ShopMenu+0x2a0 | callers(1) 0x17001e94
// veneer/thunk -> 0x003261c0 msys::MChrBaseCore::setParent (static)

// FUNC 0x170002a8 ->ad::lyt::LytNumReel3::InitParam::InitParam (ShopMenu)
//   size 0x4 | file ShopMenu+0x2a8 | callers(9) 0x17002f14 0x1700ba88 0x17009d94 0x170126c8 0x17012c3c 0x17001e94 0x17002068 0x17002a70 ...
// veneer/thunk -> 0x00256194 ad::lyt::LytNumReel3::InitParam::InitParam (static)

// FUNC 0x170002b0 ->msys::MLytNumRes::set (ShopMenu)
//   size 0x4 | file ShopMenu+0x2b0 | callers(9) 0x17002f14 0x1700ba88 0x17009d94 0x170126c8 0x17012c3c 0x17001e94 0x17002068 0x17002a70 ...
// veneer/thunk -> 0x00207594 msys::MLytNumRes::set (static)

// FUNC 0x170002b8 ->msys::MLytNum::init (ShopMenu)
//   size 0x4 | file ShopMenu+0x2b8 | callers(9) 0x17002f14 0x1700ba88 0x17009d94 0x170126c8 0x17012c3c 0x17001e94 0x17002068 0x17002a70 ...
// veneer/thunk -> 0x003316b8 msys::MLytNum::init (static)

// FUNC 0x170002c0 ->ad::fw::TaskBase::isFps30 (ShopMenu)
//   size 0x4 | file ShopMenu+0x2c0 | callers(16) 0x17007210 0x17012c3c 0x170058bc 0x17006130 0x170059ac 0x17006220 0x170051c8 0x1700572c ...
// veneer/thunk -> 0x0025edd0 ad::fw::TaskBase::isFps30 (static)

// FUNC 0x170002c8 ->GameWork::getItemNum (ShopMenu)
//   size 0x4 | file ShopMenu+0x2c8 | callers(8) 0x170082b8 0x1700917c 0x170099b8 0x1700c854 0x17008df4 0x17009a4c 0x1701276c 0x17002228
// veneer/thunk -> 0x003630e0 GameWork::getItemNum (static)

// FUNC 0x170002d0 ->GameWork::getUseItemMax (ShopMenu)
//   size 0x4 | file ShopMenu+0x2d0 | callers(1) 0x17002228
// veneer/thunk -> 0x00363118 GameWork::getUseItemMax (static)

// FUNC 0x170002d8 ->GameWork::getCoin (ShopMenu)
//   size 0x4 | file ShopMenu+0x2d8 | callers(9) 0x1700917c 0x1700c854 0x17009d94 0x170126c8 0x170031f0 0x17012c3c 0x17006dc4 0x17002228 ...
// veneer/thunk -> 0x00363120 GameWork::getCoin (static)

// FUNC 0x170002e0 ->ad::lyt::LytNumReel3::setValueInstant (ShopMenu)
//   size 0x4 | file ShopMenu+0x2e0 | callers(16) 0x1700bc6c 0x17002d18 0x170082b8 0x1700979c 0x1700c854 0x1700f718 0x17008df4 0x17011930 ...
// veneer/thunk -> 0x0020785c ad::lyt::LytNumReel3::setValueInstant (static)

// FUNC 0x170002e8 ->ad::lyt::LytResourceMan::buildLayout (ShopMenu)
//   size 0x4 | file ShopMenu+0x2e8 | callers(2) 0x1700252c 0x17003878
// veneer/thunk -> 0x00256490 ad::lyt::LytResourceMan::buildLayout (static)

// FUNC 0x170002f0 ->ad::lyt::LytAnim::init (ShopMenu)
//   size 0x4 | file ShopMenu+0x2f0 | callers(10) 0x17002f14 0x1700983c 0x17009d94 0x17004c08 0x170031f0 0x1700d580 0x17012c3c 0x1700252c ...
// veneer/thunk -> 0x00264f04 ad::lyt::LytAnim::init (static)

// FUNC 0x170002f8 ->ad::lyt::LytAnim::playAuto (ShopMenu)
//   size 0x4 | file ShopMenu+0x2f8 | callers(2) 0x1700252c 0x17003878
// veneer/thunk -> 0x0025620c ad::lyt::LytAnim::playAuto (static)

// FUNC 0x17000300 ->ad::lyt::LytLocalize::LytLocalize (ShopMenu)
//   size 0x4 | file ShopMenu+0x300 | callers(3) 0x17012c3c 0x1700252c 0x17003878
// veneer/thunk -> 0x002563d4 ad::lyt::LytLocalize::LytLocalize (static)

// FUNC 0x17000308 ->ad::lyt::LytLocalize::localize (ShopMenu)
//   size 0x4 | file ShopMenu+0x308 | callers(3) 0x17012c3c 0x1700252c 0x17003878
// veneer/thunk -> 0x00264e08 ad::lyt::LytLocalize::localize (static)

// FUNC 0x17000310 ->ad::fw::Resource::getCA_anm (ShopMenu)
//   size 0x4 | file ShopMenu+0x310 | callers(2) 0x1700252c 0x17003878
// veneer/thunk -> 0x0025abfc ad::fw::Resource::getCA_anm (static)

// FUNC 0x17000318 ->ad::fw::Resource::getCA_tex (ShopMenu)
//   size 0x4 | file ShopMenu+0x318 | callers(2) 0x1700252c 0x17003878
// veneer/thunk -> 0x0025ac08 ad::fw::Resource::getCA_tex (static)

// FUNC 0x17000320 ->ad::fw::Resource::getCA_canm (ShopMenu)
//   size 0x4 | file ShopMenu+0x320 | callers(2) 0x1700252c 0x17003878
// veneer/thunk -> 0x0025ac14 ad::fw::Resource::getCA_canm (static)

// FUNC 0x17000328 ->CellAnime::init (ShopMenu)
//   size 0x4 | file ShopMenu+0x328 | callers(2) 0x1700252c 0x17003878
// veneer/thunk -> 0x0027fa28 CellAnime::init (static)

// FUNC 0x17000330 ->shop::GetBootInfo (ShopMenu)
//   size 0x4 | file ShopMenu+0x330 | callers(20) 0x170074f8 0x1701042c 0x1700e770 0x170112a4 0x17004928 0x170049c4 0x17004a50 0x17004c3c ...
// veneer/thunk -> 0x00334714 shop::GetBootInfo (static)

// FUNC 0x17000338 ->operator.new[] (ShopMenu)
//   size 0x4 | file ShopMenu+0x338 | callers(1) 0x1700252c
// veneer/thunk -> 0x00283558 operator.new[] (static)

// FUNC 0x17000340 ->ad::ui::UIListWindowPlusLyt::InitParam::InitParam (ShopMenu)
//   size 0x4 | file ShopMenu+0x340 | callers(2) 0x1700252c 0x17003878
// veneer/thunk -> 0x00146398 ad::ui::UIListWindowPlusLyt::InitParam::InitParam (static)

// FUNC 0x17000348 ->msys::SetMListWndInitParam (ShopMenu)
//   size 0x4 | file ShopMenu+0x348 | callers(3) 0x1700917c 0x1700252c 0x17003878
// veneer/thunk -> 0x00329e60 msys::SetMListWndInitParam (static)

// FUNC 0x17000350 ->msys::MListWndPBase::init (ShopMenu)
//   size 0x4 | file ShopMenu+0x350 | callers(2) 0x1700252c 0x17003878
// veneer/thunk -> 0x00328698 msys::MListWndPBase::init (static)

// FUNC 0x17000358 ->GameMain::Back (ShopMenu)
//   size 0x4 | file ShopMenu+0x358 | callers(1) 0x170029b8
// veneer/thunk -> 0x0033e354 GameMain::Back (static)

// FUNC 0x17000360 ->ad::fw::TaskBase::~TaskBase (ShopMenu)
//   size 0x4 | file ShopMenu+0x360 | callers(2) 0x170029d4 0x170029fc
// veneer/thunk -> 0x0026d590 ad::fw::TaskBase::~TaskBase (static)

// FUNC 0x17000368 ->msys::MLyt::stopAndSetFrmInst (ShopMenu)
//   size 0x4 | file ShopMenu+0x368 | callers(4) 0x17004a7c 0x17012c3c 0x17002a70 0x17003628
// veneer/thunk -> 0x0032c13c msys::MLyt::stopAndSetFrmInst (static)

// FUNC 0x17000370 ->MoveVBase::stop (ShopMenu)
//   size 0x4 | file ShopMenu+0x370 | callers(18) 0x1700bc6c 0x1700ad98 0x1700bd6c 0x17003c7c 0x17002d18 0x1700ba88 0x170084fc 0x17008410 ...
// veneer/thunk -> 0x00259dd8 MoveVBase::stop (static)

// FUNC 0x17000378 ->msys::MDfxChr::playDfx (ShopMenu)
//   size 0x4 | file ShopMenu+0x378 | callers(8) 0x17002d18 0x1700c854 0x1700db3c 0x1700f718 0x17011930 0x17007210 0x17010894 0x17006848
// veneer/thunk -> 0x00330d64 msys::MDfxChr::playDfx (static)

// FUNC 0x17000380 ->ad::lyt::LytAnim::term (ShopMenu)
//   size 0x4 | file ShopMenu+0x380 | callers(4) 0x1700983c 0x17009d94 0x17004c30 0x170031f0
// veneer/thunk -> 0x00264e90 ad::lyt::LytAnim::term (static)

// FUNC 0x17000388 ->__aeabi_memset (ShopMenu)
//   size 0x4 | file ShopMenu+0x388 | callers(1) 0x170031f0
// veneer/thunk -> 0x0027ef28 __aeabi_memset (static)

// FUNC 0x17000390 ->RandSys::get (ShopMenu)
//   size 0x4 | file ShopMenu+0x390 | callers(1) 0x170031f0
// veneer/thunk -> 0x00273054 RandSys::get (static)

// FUNC 0x17000398 ->ad::db::GetItemData (ShopMenu)
//   size 0x4 | file ShopMenu+0x398 | callers(5) 0x1700917c 0x1700e770 0x17009a4c 0x17008b20 0x17003554
// veneer/thunk -> 0x00239a04 ad::db::GetItemData (static)

// FUNC 0x170003a0 ->ad::db::GetItemMsg (ShopMenu)
//   size 0x4 | file ShopMenu+0x3a0 | callers(4) 0x1700979c 0x1700e770 0x17008b20 0x17003554
// veneer/thunk -> 0x0013a194 ad::db::GetItemMsg (static)

// FUNC 0x170003a8 ->msys::MLyt::getParts (ShopMenu)
//   size 0x4 | file ShopMenu+0x3a8 | callers(3) 0x1700e770 0x17012c3c 0x17003628
// veneer/thunk -> 0x002073ec msys::MLyt::getParts (static)

// FUNC 0x170003b0 ->MessageSimple::MessageSimple (ShopMenu)
//   size 0x4 | file ShopMenu+0x3b0 | callers(8) 0x170144fc 0x1700789c 0x1700d164 0x1700e4e8 0x17010d74 0x17012388 0x170037a0 0x1700d4b4
// veneer/thunk -> 0x0027ceec MessageSimple::MessageSimple (static)

// FUNC 0x170003b8 ->MessageSimple::term (ShopMenu)
//   size 0x4 | file ShopMenu+0x3b8 | callers(11) 0x1700b4d8 0x17007ad4 0x1700d294 0x1700d374 0x1700e5dc 0x1700e680 0x17011070 0x170124bc ...
// veneer/thunk -> 0x00137090 MessageSimple::term (static)

// FUNC 0x170003c0 ->MessageSimple::~MessageSimple (ShopMenu)
//   size 0x4 | file ShopMenu+0x3c0 | callers(11) 0x1700b4d8 0x17007ad4 0x1700d294 0x1700d374 0x1700e5dc 0x1700e680 0x17011070 0x170124bc ...
// veneer/thunk -> 0x00256578 MessageSimple::~MessageSimple (static)

// FUNC 0x170003c8 ->__2sprintf (ShopMenu)
//   size 0x4 | file ShopMenu+0x3c8 | callers(1) 0x1700a5b0
// veneer/thunk -> 0x0010098c __2sprintf (static)

// FUNC 0x170003d0 ->Message::init (ShopMenu)
//   size 0x4 | file ShopMenu+0x3d0 | callers(2) 0x17003c7c 0x1700e770
// veneer/thunk -> 0x0033dc2c Message::init (static)

// FUNC 0x170003d8 ->Message::setMsgDat (ShopMenu)
//   size 0x4 | file ShopMenu+0x3d8 | callers(2) 0x17003c7c 0x1700e770
// veneer/thunk -> 0x0033ddc8 Message::setMsgDat (static)

// FUNC 0x170003e0 ->msys::MCursorBase::setVisible (ShopMenu)
//   size 0x4 | file ShopMenu+0x3e0 | callers(24) 0x17004e08 0x1700c6cc 0x1700ddfc 0x1700faa8 0x17011c1c 0x17004100 0x17004370 0x170045bc ...
// veneer/thunk -> 0x00324454 msys::MCursorBase::setVisible (static)

// FUNC 0x170003e8 ->msys::MLyt::playAnimeFromNo (ShopMenu)
//   size 0x4 | file ShopMenu+0x3e8 | callers(47) 0x17004e08 0x170074f8 0x17004370 0x1700c854 0x1700d11c 0x1700db3c 0x1700e4a0 0x1700f458 ...
// veneer/thunk -> 0x0032bf98 msys::MLyt::playAnimeFromNo (static)

// FUNC 0x170003f0 ->msys::MLyt::isEnableAnime (ShopMenu)
//   size 0x4 | file ShopMenu+0x3f0 | callers(34) 0x1700501c 0x17004310 0x17005478 0x17005c08 0x17007104 0x17007210 0x1700ccd0 0x1700cf40 ...
// veneer/thunk -> 0x0032bc6c msys::MLyt::isEnableAnime (static)

// FUNC 0x170003f8 ->msys::MLyt::setAnimeInfo (ShopMenu)
//   size 0x4 | file ShopMenu+0x3f8 | callers(13) 0x17004370 0x1700f458 0x1700f718 0x17004b2c 0x17004b54 0x17005c08 0x17007104 0x17007210 ...
// veneer/thunk -> 0x0032bc40 msys::MLyt::setAnimeInfo (static)

// FUNC 0x17000400 ->Frm::play (ShopMenu)
//   size 0x4 | file ShopMenu+0x400 | callers(14) 0x170045bc 0x17007210 0x17005150 0x170056b4 0x170058bc 0x17006130 0x170059ac 0x17006220 ...
// veneer/thunk -> 0x0027a324 Frm::play (static)

// FUNC 0x17000408 ->ad::ctrl::ButtonGroup::FindButtonByName (ShopMenu)
//   size 0x4 | file ShopMenu+0x408 | callers(9) 0x1700e770 0x170112a4 0x17009d94 0x17004734 0x17004788 0x170047f4 0x17004858 0x1700c18c ...
// veneer/thunk -> 0x00256680 ad::ctrl::ButtonGroup::FindButtonByName (static)

// FUNC 0x17000410 ->ad::ctrl::AnimButton::SetStateChangeCallback (ShopMenu)
//   size 0x4 | file ShopMenu+0x410 | callers(8) 0x1700e770 0x170112a4 0x17004744 0x170047a8 0x1700480c 0x17004870 0x1700c18c 0x1700d580
// veneer/thunk -> 0x00256674 ad::ctrl::AnimButton::SetStateChangeCallback (static)

// FUNC 0x17000418 ->Mem::Copy (ShopMenu)
//   size 0x4 | file ShopMenu+0x418 | callers(2) 0x17004100 0x170048ec
// veneer/thunk -> 0x0027fd08 Mem::Copy (static)

// FUNC 0x17000420 ->ad::lyt::AnimTransform::GetFrameSize (ShopMenu)
//   size 0x4 | file ShopMenu+0x420 | callers(3) 0x1700983c 0x17009d94 0x17004c14
// veneer/thunk -> 0x0026fe38 ad::lyt::AnimTransform::GetFrameSize (static)

// FUNC 0x17000428 ->DataPc::getHige (ShopMenu)
//   size 0x4 | file ShopMenu+0x428 | callers(3) 0x17004c9c 0x17004cbc 0x17004d60
// veneer/thunk -> 0x00207888 DataPc::getHige (static)

// FUNC 0x17000430 ->msys::MComSys::getNextPage (ShopMenu)
//   size 0x4 | file ShopMenu+0x430 | callers(5) 0x1700c7e4 0x1700df14 0x1700fbc0 0x17011d34 0x17004f98
// veneer/thunk -> 0x0032db64 msys::MComSys::getNextPage (static)

// FUNC 0x17000438 ->Frm::update (ShopMenu)
//   size 0x4 | file ShopMenu+0x438 | callers(13) 0x17007210 0x170058bc 0x17006130 0x170059ac 0x17006220 0x170051c8 0x1700572c 0x1700641c ...
// veneer/thunk -> 0x0026aed4 Frm::update (static)

// FUNC 0x17000440 ->ad::lyt::LytNumReel3::setValue (ShopMenu)
//   size 0x4 | file ShopMenu+0x440 | callers(7) 0x1700c854 0x1700db3c 0x1700f718 0x17011930 0x170058bc 0x17006130 0x17006dc4
// veneer/thunk -> 0x0015a7c8 ad::lyt::LytNumReel3::setValue (static)

// FUNC 0x17000448 ->MoveVBase::moveFrmAbs (ShopMenu)
//   size 0x4 | file ShopMenu+0x448 | callers(2) 0x1700641c 0x17005f40
// veneer/thunk -> 0x0025cd30 MoveVBase::moveFrmAbs (static)

// FUNC 0x17000450 ->msys::MDfxChr::term (ShopMenu)
//   size 0x4 | file ShopMenu+0x450 | callers(2) 0x17006dc4 0x1700604c
// veneer/thunk -> 0x00330c68 msys::MDfxChr::term (static)

// FUNC 0x17000458 ->SndSeCtrl::stop (ShopMenu)
//   size 0x4 | file ShopMenu+0x458 | callers(5) 0x1701042c 0x1700cda4 0x1700e088 0x17011edc 0x17006340
// veneer/thunk -> 0x002832cc SndSeCtrl::stop (static)

// FUNC 0x17000460 ->msys::MLyt::detachMChr (ShopMenu)
//   size 0x4 | file ShopMenu+0x460 | callers(5) 0x17012b94 0x1700e770 0x170112a4 0x17012b04 0x1700641c
// veneer/thunk -> 0x0032b8c0 msys::MLyt::detachMChr (static)

// FUNC 0x17000468 ->MoveVBase::jumpFT (ShopMenu)
//   size 0x4 | file ShopMenu+0x468 | callers(2) 0x17006564 0x17006604
// veneer/thunk -> 0x0025d1c8 MoveVBase::jumpFT (static)

// FUNC 0x17000470 ->msys::MChrBaseCore::isBusySRTMov (ShopMenu)
//   size 0x4 | file ShopMenu+0x470 | callers(1) 0x17006a20
// veneer/thunk -> 0x00361fd8 msys::MChrBaseCore::isBusySRTMov (static)

// FUNC 0x17000478 ->GameWork::addCoin (ShopMenu)
//   size 0x4 | file ShopMenu+0x478 | callers(5) 0x1700c854 0x1701042c 0x1700e088 0x17011edc 0x17006dc4
// veneer/thunk -> 0x0022ec84 GameWork::addCoin (static)

// FUNC 0x17000480 ->msys::MDfxChr::MDfxChr (ShopMenu)
//   size 0x4 | file ShopMenu+0x480 | callers(5) 0x1700789c 0x1700d164 0x1700e4e8 0x17010d74 0x17012388
// veneer/thunk -> 0x0033137c msys::MDfxChr::MDfxChr (static)

// FUNC 0x17000488 ->msys::MLytNum::MLytNum (ShopMenu)
//   size 0x4 | file ShopMenu+0x488 | callers(6) 0x170144fc 0x1700789c 0x1700d164 0x1700e4e8 0x17010d74 0x17012388
// veneer/thunk -> 0x003317a4 msys::MLytNum::MLytNum (static)

// FUNC 0x17000490 ->Mem::Fill (ShopMenu)
//   size 0x4 | file ShopMenu+0x490 | callers(1) 0x1700789c
// veneer/thunk -> 0x002849e8 Mem::Fill (static)

// FUNC 0x17000498 ->Message::Message (ShopMenu)
//   size 0x4 | file ShopMenu+0x498 | callers(2) 0x1700789c 0x17010d74
// veneer/thunk -> 0x00110d5c Message::Message (static)

// FUNC 0x170004a0 ->msys::MDfxChr::~MDfxChr (ShopMenu)
//   size 0x4 | file ShopMenu+0x4a0 | callers(8) 0x17007ad4 0x1700d294 0x1700d374 0x1700e5dc 0x1700e680 0x17011070 0x170124bc 0x1701259c
// veneer/thunk -> 0x003313cc msys::MDfxChr::~MDfxChr (static)

// FUNC 0x170004a8 ->Message::term (ShopMenu)
//   size 0x4 | file ShopMenu+0x4a8 | callers(2) 0x17007ad4 0x17011070
// veneer/thunk -> 0x0033dc68 Message::term (static)

// FUNC 0x170004b0 ->Message::~Message (ShopMenu)
//   size 0x4 | file ShopMenu+0x4b0 | callers(2) 0x17007ad4 0x17011070
// veneer/thunk -> 0x00206538 Message::~Message (static)

// FUNC 0x170004b8 ->msys::MLytNum::~MLytNum (ShopMenu)
//   size 0x4 | file ShopMenu+0x4b8 | callers(9) 0x1700b4d8 0x17007ad4 0x1700d294 0x1700d374 0x1700e5dc 0x1700e680 0x17011070 0x170124bc ...
// veneer/thunk -> 0x00331840 msys::MLytNum::~MLytNum (static)

// FUNC 0x170004c0 ->Mem::Free (ShopMenu)
//   size 0x4 | file ShopMenu+0x4c0 | callers(4) 0x17007ad4 0x17007eec 0x17007f44 0x170095f4
// veneer/thunk -> 0x00285d3c Mem::Free (static)

// FUNC 0x170004c8 ->msys::MPageBase::updateInputAllChr (ShopMenu)
//   size 0x4 | file ShopMenu+0x4c8 | callers(5) 0x17007e04 0x1700d008 0x1700e38c 0x17010c18 0x1701222c
// veneer/thunk -> 0x00334204 msys::MPageBase::updateInputAllChr (static)

// FUNC 0x170004d0 ->VramAlcRange::merge (ShopMenu)
//   size 0x4 | file ShopMenu+0x4d0 | callers(1) 0x17008028
// veneer/thunk -> 0x00102874 VramAlcRange::merge (static)

// FUNC 0x170004d8 ->MemAlc::initCore (ShopMenu)
//   size 0x4 | file ShopMenu+0x4d8 | callers(4) 0x1700e770 0x170112a4 0x1700c18c 0x1700d580
// veneer/thunk -> 0x002855b4 MemAlc::initCore (static)

// FUNC 0x170004e0 ->msys::MListWndPBase::resetCur (ShopMenu)
//   size 0x4 | file ShopMenu+0x4e0 | callers(4) 0x1700e770 0x170112a4 0x1700c18c 0x1700d580
// veneer/thunk -> 0x003287c0 msys::MListWndPBase::resetCur (static)

// FUNC 0x170004e8 ->msys::MListWndPBase::setEnableInput (ShopMenu)
//   size 0x4 | file ShopMenu+0x4e8 | callers(25) 0x1700c6cc 0x1700ddfc 0x1700faa8 0x17011c1c 0x1700c854 0x1700db3c 0x1700f718 0x17011930 ...
// veneer/thunk -> 0x00328638 msys::MListWndPBase::setEnableInput (static)

// FUNC 0x170004f0 ->msys::MListWndPBase::getItemNum (ShopMenu)
//   size 0x4 | file ShopMenu+0x4f0 | callers(2) 0x1700c18c 0x1700cda4
// veneer/thunk -> 0x003620b4 msys::MListWndPBase::getItemNum (static)

// FUNC 0x170004f8 ->msys::MListWndPBase::getCurItem (ShopMenu)
//   size 0x4 | file ShopMenu+0x4f8 | callers(14) 0x170082b8 0x1700db3c 0x17008f64 0x1700f718 0x1701042c 0x17008a74 0x1700e770 0x170112a4 ...
// veneer/thunk -> 0x0025a0bc msys::MListWndPBase::getCurItem (static)

// FUNC 0x17000500 ->msys::MListWndPBase::getSelectItem (ShopMenu)
//   size 0x4 | file ShopMenu+0x500 | callers(7) 0x1700c3f4 0x1700c538 0x1700d98c 0x1700d854 0x1700f204 0x17011780 0x170115ec
// veneer/thunk -> 0x003285f0 msys::MListWndPBase::getSelectItem (static)

// FUNC 0x17000508 ->msys::MListWndPBase::getListWnd (ShopMenu)
//   size 0x4 | file ShopMenu+0x508 | callers(13) 0x1700917c 0x1700f458 0x17008690 0x1700f718 0x1700fef4 0x17009a4c 0x1700c3f4 0x1700d98c ...
// veneer/thunk -> 0x003620c0 msys::MListWndPBase::getListWnd (static)

// FUNC 0x17000510 ->ad::ui::UIListWindowPlusLyt::getCurItem (ShopMenu)
//   size 0x4 | file ShopMenu+0x510 | callers(12) 0x1700f458 0x17008690 0x1700f718 0x1700fef4 0x17009a4c 0x1700c3f4 0x1700d98c 0x1700f204 ...
// veneer/thunk -> 0x0025a0c4 ad::ui::UIListWindowPlusLyt::getCurItem (static)

// FUNC 0x17000518 ->msys::MListWndPBase::getCurNo (ShopMenu)
//   size 0x4 | file ShopMenu+0x518 | callers(4) 0x1700c3f4 0x1700d98c 0x1700f204 0x17011780
// veneer/thunk -> 0x003620e0 msys::MListWndPBase::getCurNo (static)

// FUNC 0x17000520 ->__aeabi_vec_ctor_nocookie_nodtor (ShopMenu)
//   size 0x4 | file ShopMenu+0x520 | callers(7) 0x170144fc 0x17008110 0x1700c0a0 0x1700d164 0x1700e4e8 0x17010d74 0x17012388
// veneer/thunk -> 0x0028771c __aeabi_vec_ctor_nocookie_nodtor (static)

// FUNC 0x17000528 ->ad::TransMultiSymbol::init (ShopMenu)
//   size 0x4 | file ShopMenu+0x528 | callers(1) 0x170081a0
// veneer/thunk -> 0x0026d7f8 ad::TransMultiSymbol::init (static)

// FUNC 0x17000530 ->BinGlu4Acs::getEntryAcs (ShopMenu)
//   size 0x4 | file ShopMenu+0x530 | callers(1) 0x170081a0
// veneer/thunk -> 0x00285268 BinGlu4Acs::getEntryAcs (static)

// FUNC 0x17000538 ->ad::fw::TaskBase::readCA (ShopMenu)
//   size 0x4 | file ShopMenu+0x538 | callers(1) 0x170081a0
// veneer/thunk -> 0x0026daf8 ad::fw::TaskBase::readCA (static)

// FUNC 0x17000540 ->ad::db::GetUseItem (ShopMenu)
//   size 0x4 | file ShopMenu+0x540 | callers(1) 0x170082b8
// veneer/thunk -> 0x00236398 ad::db::GetUseItem (static)

// FUNC 0x17000548 ->msys::StatusPanel::setLow (ShopMenu)
//   size 0x4 | file ShopMenu+0x548 | callers(1) 0x170082b8
// veneer/thunk -> 0x00325b04 msys::StatusPanel::setLow (static)

// FUNC 0x17000550 ->msys::StatusPanel::setHi (ShopMenu)
//   size 0x4 | file ShopMenu+0x550 | callers(1) 0x170082b8
// veneer/thunk -> 0x003258b8 msys::StatusPanel::setHi (static)

// FUNC 0x17000558 ->msys::StatusPanel::resetHi (ShopMenu)
//   size 0x4 | file ShopMenu+0x558 | callers(1) 0x170082b8
// veneer/thunk -> 0x00325b54 msys::StatusPanel::resetHi (static)

// FUNC 0x17000560 ->MoveVBase::update (ShopMenu)
//   size 0x4 | file ShopMenu+0x560 | callers(6) 0x1700bc6c 0x170084fc 0x17008410 0x17010894 0x17009648 0x1700fc24
// veneer/thunk -> 0x002597d4 MoveVBase::update (static)

// FUNC 0x17000568 ->MoveVBase::moveSinAbs (ShopMenu)
//   size 0x4 | file ShopMenu+0x568 | callers(2) 0x1700bc6c 0x170084fc
// veneer/thunk -> 0x0025d0a8 MoveVBase::moveSinAbs (static)

// FUNC 0x17000570 ->ad::db::GetEquip (ShopMenu)
//   size 0x4 | file ShopMenu+0x570 | callers(3) 0x1700979c 0x17008690 0x17008910
// veneer/thunk -> 0x0013a6e4 ad::db::GetEquip (static)

// FUNC 0x17000578 ->Message::play (ShopMenu)
//   size 0x4 | file ShopMenu+0x578 | callers(2) 0x17008690 0x1700a5b0
// veneer/thunk -> 0x00259970 Message::play (static)

// FUNC 0x17000580 ->DataPc::getEquip (ShopMenu)
//   size 0x4 | file ShopMenu+0x580 | callers(3) 0x17008910 0x1700e770 0x17008b20
// veneer/thunk -> 0x00362c1c DataPc::getEquip (static)

// FUNC 0x17000588 ->__aeabi_memcpy4 (ShopMenu)
//   size 0x4 | file ShopMenu+0x588 | callers(2) 0x17008df4 0x17008b20
// veneer/thunk -> 0x00286f4c __aeabi_memcpy4 (static)

// FUNC 0x17000590 ->DataPc::setEquip (ShopMenu)
//   size 0x4 | file ShopMenu+0x590 | callers(3) 0x17008df4 0x17010894 0x17008b20
// veneer/thunk -> 0x0027c9d4 DataPc::setEquip (static)

// FUNC 0x17000598 ->msys::StatusPanel::setNewEquipParam (ShopMenu)
//   size 0x4 | file ShopMenu+0x598 | callers(2) 0x17008df4 0x17008b20
// veneer/thunk -> 0x00325128 msys::StatusPanel::setNewEquipParam (static)

// FUNC 0x170005a0 ->msys::StatusPanel::setParam (ShopMenu)
//   size 0x4 | file ShopMenu+0x5a0 | callers(3) 0x1700e770 0x17008b20 0x17012c3c
// veneer/thunk -> 0x00325ce0 msys::StatusPanel::setParam (static)

// FUNC 0x170005a8 ->msys::StatusPanel::setChr (ShopMenu)
//   size 0x4 | file ShopMenu+0x5a8 | callers(3) 0x1700e770 0x17008b20 0x17012c3c
// veneer/thunk -> 0x003259c0 msys::StatusPanel::setChr (static)

// FUNC 0x170005b0 ->GetRegFlag (ShopMenu)
//   size 0x4 | file ShopMenu+0x5b0 | callers(1) 0x1700917c
// veneer/thunk -> 0x002762cc GetRegFlag (static)

// FUNC 0x170005b8 ->PutRegFlag (ShopMenu)
//   size 0x4 | file ShopMenu+0x5b8 | callers(4) 0x1700917c 0x1700d98c 0x1700f204 0x17011780
// veneer/thunk -> 0x002731a0 PutRegFlag (static)

// FUNC 0x170005c0 ->ad::db::GetItemMsgAcs (ShopMenu)
//   size 0x4 | file ShopMenu+0x5c0 | callers(2) 0x1700917c 0x17009a4c
// veneer/thunk -> 0x0013a30c ad::db::GetItemMsgAcs (static)

// FUNC 0x170005c8 ->MoveVBase::isBusy (ShopMenu)
//   size 0x4 | file ShopMenu+0x5c8 | callers(2) 0x17010894 0x17009648
// veneer/thunk -> 0x0025d230 MoveVBase::isBusy (static)

// FUNC 0x170005d0 ->ad::db::GetUseItemIdList (ShopMenu)
//   size 0x4 | file ShopMenu+0x5d0 | callers(1) 0x17009a4c
// veneer/thunk -> 0x0013a4a4 ad::db::GetUseItemIdList (static)

// FUNC 0x170005d8 ->ad::db::GetEquipIdList (ShopMenu)
//   size 0x4 | file ShopMenu+0x5d8 | callers(1) 0x17009a4c
// veneer/thunk -> 0x00206de8 ad::db::GetEquipIdList (static)

// FUNC 0x170005e0 ->strcmp (ShopMenu)
//   size 0x4 | file ShopMenu+0x5e0 | callers(2) 0x1700ad98 0x1700a234
// veneer/thunk -> 0x002833b8 strcmp (static)

// FUNC 0x170005e8 ->msys::MCtrlUserData::findExtUserDataByName (ShopMenu)
//   size 0x4 | file ShopMenu+0x5e8 | callers(2) 0x1700ad98 0x1700a234
// veneer/thunk -> 0x0036203c msys::MCtrlUserData::findExtUserDataByName (static)

// FUNC 0x170005f0 ->msys::MChrBaseCore::getGlbMtx (ShopMenu)
//   size 0x4 | file ShopMenu+0x5f0 | callers(1) 0x1700a5b0
// veneer/thunk -> 0x0032606c msys::MChrBaseCore::getGlbMtx (static)

// FUNC 0x170005f8 ->Grp::GetLcdWidth (ShopMenu)
//   size 0x4 | file ShopMenu+0x5f8 | callers(1) 0x1700a5b0
// veneer/thunk -> 0x00271e08 Grp::GetLcdWidth (static)

// FUNC 0x17000600 ->Grp::GetLcdHeight (ShopMenu)
//   size 0x4 | file ShopMenu+0x600 | callers(1) 0x1700a5b0
// veneer/thunk -> 0x00271de4 Grp::GetLcdHeight (static)

// FUNC 0x17000608 ->MsgWndPosCalculator::calc (ShopMenu)
//   size 0x4 | file ShopMenu+0x608 | callers(1) 0x1700a5b0
// veneer/thunk -> 0x0024d828 MsgWndPosCalculator::calc (static)

// FUNC 0x17000610 ->MessageSimple::getMsgHeight (ShopMenu)
//   size 0x4 | file ShopMenu+0x610 | callers(1) 0x1700a5b0
// veneer/thunk -> 0x00136f24 MessageSimple::getMsgHeight (static)

// FUNC 0x17000618 ->ad::lyt::Layout::~Layout (ShopMenu)
//   size 0x4 | file ShopMenu+0x618 | callers(2) 0x1700b9d8 0x1700b030
// veneer/thunk -> 0x00262eec ad::lyt::Layout::~Layout (static)

// FUNC 0x17000620 ->__c89vswprintf (ShopMenu)
//   size 0x4 | file ShopMenu+0x620 | callers(1) 0x1700b0e4
// veneer/thunk -> 0x0010005c __c89vswprintf (static)

// FUNC 0x17000628 ->MessageSimple::play (ShopMenu)
//   size 0x4 | file ShopMenu+0x628 | callers(1) 0x1700b110
// veneer/thunk -> 0x00275444 MessageSimple::play (static)

// FUNC 0x17000630 ->__aeabi_uidivmod (ShopMenu)
//   size 0x4 | file ShopMenu+0x630 | callers(1) 0x1700b110
// veneer/thunk -> 0x00281628 __aeabi_uidivmod (static)

// FUNC 0x17000638 ->SndSys::merge (ShopMenu)
//   size 0x4 | file ShopMenu+0x638 | callers(1) 0x1700b4d8
// veneer/thunk -> 0x0033c6c4 SndSys::merge (static)

// FUNC 0x17000640 ->ad::fw::FileContext::term (ShopMenu)
//   size 0x4 | file ShopMenu+0x640 | callers(1) 0x1700b4d8
// veneer/thunk -> 0x0013af88 ad::fw::FileContext::term (static)

// FUNC 0x17000648 ->ad::fw::TaskBase::term (ShopMenu)
//   size 0x4 | file ShopMenu+0x648 | callers(1) 0x1700b4d8
// veneer/thunk -> 0x0024a358 ad::fw::TaskBase::term (static)

// FUNC 0x17000650 ->__aeabi_vec_dtor (ShopMenu)
//   size 0x4 | file ShopMenu+0x650 | callers(11) 0x1700bf44 0x1700b4d8 0x1700d294 0x1700d374 0x1700e5dc 0x1700e680 0x17011070 0x170124bc ...
// veneer/thunk -> 0x00288230 __aeabi_vec_dtor (static)

// FUNC 0x17000658 ->msys::StatusPanel::~StatusPanel (ShopMenu)
//   size 0x4 | file ShopMenu+0x658 | callers(1) 0x1700b4d8
// veneer/thunk -> 0x00325f7c msys::StatusPanel::~StatusPanel (static)

// FUNC 0x17000660 ->msys::MCursorBase::~MCursorBase (ShopMenu)
//   size 0x4 | file ShopMenu+0x660 | callers(5) 0x1700b4d8 0x17015098 0x170150a8 0x170150d4 0x170150e4
// veneer/thunk -> 0x00324600 msys::MCursorBase::~MCursorBase (static)

// FUNC 0x17000668 ->msys::MLyt::term (ShopMenu)
//   size 0x4 | file ShopMenu+0x668 | callers(1) 0x1700b4d8
// veneer/thunk -> 0x0032c3c8 msys::MLyt::term (static)

// FUNC 0x17000670 ->ad::ctrl::ButtonGroup::~ButtonGroup (ShopMenu)
//   size 0x4 | file ShopMenu+0x670 | callers(1) 0x1700b4d8
// veneer/thunk -> 0x00250928 ad::ctrl::ButtonGroup::~ButtonGroup (static)

// FUNC 0x17000678 ->ad::fw::Resource::~Resource (ShopMenu)
//   size 0x4 | file ShopMenu+0x678 | callers(1) 0x1700b4d8
// veneer/thunk -> 0x0024a104 ad::fw::Resource::~Resource (static)

// FUNC 0x17000680 ->ad::lyt::LytResourceMan::term (ShopMenu)
//   size 0x4 | file ShopMenu+0x680 | callers(1) 0x1700b4d8
// veneer/thunk -> 0x00250938 ad::lyt::LytResourceMan::term (static)

// FUNC 0x17000688 ->ad::font::ResFont::~ResFont (ShopMenu)
//   size 0x4 | file ShopMenu+0x688 | callers(1) 0x1700b4d8
// veneer/thunk -> 0x002508a8 ad::font::ResFont::~ResFont (static)

// FUNC 0x17000690 ->msys::MComSys::~MComSys (ShopMenu)
//   size 0x4 | file ShopMenu+0x690 | callers(1) 0x1700b4d8
// veneer/thunk -> 0x003300e8 msys::MComSys::~MComSys (static)

// FUNC 0x17000698 ->operator.delete[] (ShopMenu)
//   size 0x4 | file ShopMenu+0x698 | callers(1) 0x1700b9d8
// veneer/thunk -> 0x0028829c operator.delete[] (static)

// FUNC 0x170006a0 ->__cxa_guard_acquire (ShopMenu)
//   size 0x4 | file ShopMenu+0x6a0 | callers(1) 0x1700bd6c
// veneer/thunk -> 0x00288110 __cxa_guard_acquire (static)

// FUNC 0x170006a8 ->__cxa_guard_release (ShopMenu)
//   size 0x4 | file ShopMenu+0x6a8 | callers(1) 0x1700bd6c
// veneer/thunk -> 0x001018a8 __cxa_guard_release (static)

// FUNC 0x170006b0 ->msys::MSndSe::play (ShopMenu)
//   size 0x4 | file ShopMenu+0x6b0 | callers(1) 0x1700beb8
// veneer/thunk -> 0x0032d844 msys::MSndSe::play (static)

// FUNC 0x170006b8 ->MoveVBase::~MoveVBase (ShopMenu)
//   size 0x4 | file ShopMenu+0x6b8 | callers(10) 0x1700bf44 0x1700d294 0x1700d374 0x1700e5dc 0x1700e680 0x17011070 0x170124bc 0x1701259c ...
// veneer/thunk -> 0x002535e8 MoveVBase::~MoveVBase (static)

// FUNC 0x170006c0 ->MoveVBase::MoveVBase (ShopMenu)
//   size 0x4 | file ShopMenu+0x6c0 | callers(5) 0x1700c0a0 0x1700d164 0x1700e4e8 0x17010d74 0x17012388
// veneer/thunk -> 0x00259740 MoveVBase::MoveVBase (static)

// FUNC 0x170006c8 ->msys::MListWndPBase::setDispCursor (ShopMenu)
//   size 0x4 | file ShopMenu+0x6c8 | callers(13) 0x1700c854 0x1700db3c 0x1700f458 0x1700f718 0x17011930 0x1700ccd0 0x1700e184 0x17010608 ...
// veneer/thunk -> 0x00328604 msys::MListWndPBase::setDispCursor (static)

// FUNC 0x170006d0 ->msys::MListWndPBase::getCurPos (ShopMenu)
//   size 0x4 | file ShopMenu+0x6d0 | callers(4) 0x1700c538 0x1700d854 0x1700f088 0x170115ec
// veneer/thunk -> 0x003429d4 msys::MListWndPBase::getCurPos (static)

// FUNC 0x170006d8 ->GameWork::addItem (ShopMenu)
//   size 0x4 | file ShopMenu+0x6d8 | callers(4) 0x1700c854 0x1701042c 0x1700e088 0x17011edc
// veneer/thunk -> 0x0033edc8 GameWork::addItem (static)

// FUNC 0x170006e0 ->msys::MListWndPBase::isTpNeutral (ShopMenu)
//   size 0x4 | file ShopMenu+0x6e0 | callers(4) 0x1700d008 0x1700e38c 0x17010c18 0x1701222c
// veneer/thunk -> 0x003620c8 msys::MListWndPBase::isTpNeutral (static)

// FUNC 0x170006e8 ->DataPc::write (ShopMenu)
//   size 0x4 | file ShopMenu+0x6e8 | callers(1) 0x17010894
// veneer/thunk -> 0x0022ecbc DataPc::write (static)

// FUNC 0x170006f0 ->msys::MCamera::getProjMtx (ShopMenu)
//   size 0x4 | file ShopMenu+0x6f0 | callers(2) 0x17012ac0 0x17012a54
// veneer/thunk -> 0x00206718 msys::MCamera::getProjMtx (static)

// FUNC 0x170006f8 ->msys::MCamera::getViewMtx (ShopMenu)
//   size 0x4 | file ShopMenu+0x6f8 | callers(1) 0x17012a54
// veneer/thunk -> 0x002068e4 msys::MCamera::getViewMtx (static)

// FUNC 0x17000700 ->ad::fw::TaskBase::setULcdCameraInfoBase (ShopMenu)
//   size 0x4 | file ShopMenu+0x700 | callers(1) 0x17012a54
// veneer/thunk -> 0x0010b438 ad::fw::TaskBase::setULcdCameraInfoBase (static)

// FUNC 0x17000708 ->ad::lyt::DrawInfo::SetProjectionMtx (ShopMenu)
//   size 0x4 | file ShopMenu+0x708 | callers(1) 0x17012a54
// veneer/thunk -> 0x0026510c ad::lyt::DrawInfo::SetProjectionMtx (static)

// FUNC 0x17000710 ->msys::MComSys::funcCalcMainNomal (ShopMenu)
//   size 0x4 | file ShopMenu+0x710 | callers(1) 0x17012a54
// veneer/thunk -> 0x0032f13c msys::MComSys::funcCalcMainNomal (static)

// FUNC 0x17000718 ->msys::MComSys::funcDrawLower (ShopMenu)
//   size 0x4 | file ShopMenu+0x718 | callers(1) 0x17012ac0
// veneer/thunk -> 0x0032e2b8 msys::MComSys::funcDrawLower (static)

// FUNC 0x17000720 ->msys::MComSys::funcDrawUpper (ShopMenu)
//   size 0x4 | file ShopMenu+0x720 | callers(1) 0x17012b00
// veneer/thunk -> 0x0032e760 msys::MComSys::funcDrawUpper (static)

// FUNC 0x17000728 ->MoveC::moveFrm (ShopMenu)
//   size 0x4 | file ShopMenu+0x728 | callers(2) 0x17012c3c 0x170140a0
// veneer/thunk -> 0x0026bc74 MoveC::moveFrm (static)

// FUNC 0x17000730 ->ad::lyt::LytDrawSys::GetInst (ShopMenu)
//   size 0x4 | file ShopMenu+0x730 | callers(2) 0x17014174 0x17012c3c
// veneer/thunk -> 0x00287f58 ad::lyt::LytDrawSys::GetInst (static)

// FUNC 0x17000738 ->ad::lyt::Initialize (ShopMenu)
//   size 0x4 | file ShopMenu+0x738 | callers(2) 0x17014174 0x17012c3c
// veneer/thunk -> 0x002855e0 ad::lyt::Initialize (static)

// FUNC 0x17000740 ->msys::MComSys::readLytNum (ShopMenu)
//   size 0x4 | file ShopMenu+0x740 | callers(1) 0x17012c3c
// veneer/thunk -> 0x0032db14 msys::MComSys::readLytNum (static)

// FUNC 0x17000748 ->ad::fw::TaskBase::readLyt (ShopMenu)
//   size 0x4 | file ShopMenu+0x748 | callers(1) 0x17012c3c
// veneer/thunk -> 0x00249e48 ad::fw::TaskBase::readLyt (static)

// FUNC 0x17000750 ->MessageSys::GetPath (ShopMenu)
//   size 0x4 | file ShopMenu+0x750 | callers(1) 0x17012c3c
// veneer/thunk -> 0x00132a2c MessageSys::GetPath (static)

// FUNC 0x17000758 ->nn::fs::CTR::MPCore::detail::UserFileSystem::TryOpenFile (ShopMenu)
//   size 0x4 | file ShopMenu+0x758 | callers(1) 0x17012c3c
// veneer/thunk -> 0x0028598c nn::fs::CTR::MPCore::detail::UserFileSystem::TryOpenFile (static)

// FUNC 0x17000760 ->nn::fs::detail::FileBase::TryGetSize (ShopMenu)
//   size 0x4 | file ShopMenu+0x760 | callers(3) 0x17014cec 0x17014cc8 0x17012c3c
// veneer/thunk -> 0x00286568 nn::fs::detail::FileBase::TryGetSize (static)

// FUNC 0x17000768 ->MsgDataAcsrBase::init (ShopMenu)
//   size 0x4 | file ShopMenu+0x768 | callers(1) 0x17012c3c
// veneer/thunk -> 0x00285b88 MsgDataAcsrBase::init (static)

// FUNC 0x17000770 ->ad::lyt::LytResourceMan::init (ShopMenu)
//   size 0x4 | file ShopMenu+0x770 | callers(2) 0x170144fc 0x17012c3c
// veneer/thunk -> 0x00250d1c ad::lyt::LytResourceMan::init (static)

// FUNC 0x17000778 ->ad::fw::Resource::getFileData (ShopMenu)
//   size 0x4 | file ShopMenu+0x778 | callers(1) 0x17012c3c
// veneer/thunk -> 0x00251d10 ad::fw::Resource::getFileData (static)

// FUNC 0x17000780 ->ad::lyt::LytResourceMan::registerArc (ShopMenu)
//   size 0x4 | file ShopMenu+0x780 | callers(1) 0x17012c3c
// veneer/thunk -> 0x0015c910 ad::lyt::LytResourceMan::registerArc (static)

// FUNC 0x17000788 ->msys::MLytNumRes::init (ShopMenu)
//   size 0x4 | file ShopMenu+0x788 | callers(1) 0x17012c3c
// veneer/thunk -> 0x003240f4 msys::MLytNumRes::init (static)

// FUNC 0x17000790 ->msys::MLyt::init (ShopMenu)
//   size 0x4 | file ShopMenu+0x790 | callers(1) 0x17012c3c
// veneer/thunk -> 0x0032c3a0 msys::MLyt::init (static)

// FUNC 0x17000798 ->msys::MLyt::createLyt (ShopMenu)
//   size 0x4 | file ShopMenu+0x798 | callers(1) 0x17012c3c
// veneer/thunk -> 0x0032c78c msys::MLyt::createLyt (static)

// FUNC 0x170007a0 ->msys::MLyt::build (ShopMenu)
//   size 0x4 | file ShopMenu+0x7a0 | callers(1) 0x17012c3c
// veneer/thunk -> 0x0032c460 msys::MLyt::build (static)

// FUNC 0x170007a8 ->msys::MLyt::createLyt (ShopMenu)
//   size 0x4 | file ShopMenu+0x7a8 | callers(1) 0x17012c3c
// veneer/thunk -> 0x0032c8c0 msys::MLyt::createLyt (static)

// FUNC 0x170007b0 ->msys::MCursorBase::init (ShopMenu)
//   size 0x4 | file ShopMenu+0x7b0 | callers(3) 0x17015070 0x170150ac 0x17012c3c
// veneer/thunk -> 0x00324464 msys::MCursorBase::init (static)

// FUNC 0x170007b8 ->msys::StatusPanel::init (ShopMenu)
//   size 0x4 | file ShopMenu+0x7b8 | callers(1) 0x17012c3c
// veneer/thunk -> 0x00325390 msys::StatusPanel::init (static)

// FUNC 0x170007c0 ->msys::StatusPanel::setType (ShopMenu)
//   size 0x4 | file ShopMenu+0x7c0 | callers(1) 0x17012c3c
// veneer/thunk -> 0x00325b60 msys::StatusPanel::setType (static)

// FUNC 0x170007c8 ->msys::MLyt::stopAndSetEndInst (ShopMenu)
//   size 0x4 | file ShopMenu+0x7c8 | callers(1) 0x17012c3c
// veneer/thunk -> 0x0032c090 msys::MLyt::stopAndSetEndInst (static)

// FUNC 0x170007d0 ->SndSys::LoadSync (ShopMenu)
//   size 0x4 | file ShopMenu+0x7d0 | callers(1) 0x17014174
// veneer/thunk -> 0x0033c828 SndSys::LoadSync (static)

// FUNC 0x170007d8 ->msys::MComSys::initBaseSys (ShopMenu)
//   size 0x4 | file ShopMenu+0x7d8 | callers(1) 0x17014174
// veneer/thunk -> 0x0032db84 msys::MComSys::initBaseSys (static)

// FUNC 0x170007e0 ->msys::MComSys::entryPage (ShopMenu)
//   size 0x4 | file ShopMenu+0x7e0 | callers(1) 0x17014174
// veneer/thunk -> 0x0032f548 msys::MComSys::entryPage (static)

// FUNC 0x170007e8 ->CtrJobMan::enqueue (ShopMenu)
//   size 0x4 | file ShopMenu+0x7e8 | callers(1) 0x17014174
// veneer/thunk -> 0x0026dbe8 CtrJobMan::enqueue (static)

// FUNC 0x170007f0 ->Prim::disableDepthTest (ShopMenu)
//   size 0x4 | file ShopMenu+0x7f0 | callers(1) 0x17014174
// veneer/thunk -> 0x00271c98 Prim::disableDepthTest (static)

// FUNC 0x170007f8 ->msys::MComSys::setupCamU (ShopMenu)
//   size 0x4 | file ShopMenu+0x7f8 | callers(1) 0x17014174
// veneer/thunk -> 0x0032f674 msys::MComSys::setupCamU (static)

// FUNC 0x17000800 ->msys::MComSys::setupCamL (ShopMenu)
//   size 0x4 | file ShopMenu+0x800 | callers(1) 0x17014174
// veneer/thunk -> 0x0032f570 msys::MComSys::setupCamL (static)

// FUNC 0x17000808 ->DataPc::init (ShopMenu)
//   size 0x4 | file ShopMenu+0x808 | callers(1) 0x17014174
// veneer/thunk -> 0x0033bbdc DataPc::init (static)

// FUNC 0x17000810 ->msys::MComSys::MComSys (ShopMenu)
//   size 0x4 | file ShopMenu+0x810 | callers(1) 0x170144fc
// veneer/thunk -> 0x0032f7a4 msys::MComSys::MComSys (static)

// FUNC 0x17000818 ->ad::font::ResFont::ResFont (ShopMenu)
//   size 0x4 | file ShopMenu+0x818 | callers(1) 0x170144fc
// veneer/thunk -> 0x0027542c ad::font::ResFont::ResFont (static)

// FUNC 0x17000820 ->ad::fw::Resource::Resource (ShopMenu)
//   size 0x4 | file ShopMenu+0x820 | callers(1) 0x170144fc
// veneer/thunk -> 0x00250588 ad::fw::Resource::Resource (static)

// FUNC 0x17000828 ->MsgDataAcsrBase::MsgDataAcsrBase (ShopMenu)
//   size 0x4 | file ShopMenu+0x828 | callers(1) 0x170144fc
// veneer/thunk -> 0x0024b3b8 MsgDataAcsrBase::MsgDataAcsrBase (static)

// FUNC 0x17000830 ->ad::ctrl::ButtonGroup::ButtonGroup (ShopMenu)
//   size 0x4 | file ShopMenu+0x830 | callers(1) 0x170144fc
// veneer/thunk -> 0x001667d8 ad::ctrl::ButtonGroup::ButtonGroup (static)

// FUNC 0x17000838 ->ad::lyt::LytNumReel2::LytNumReel2 (ShopMenu)
//   size 0x4 | file ShopMenu+0x838 | callers(1) 0x170144fc
// veneer/thunk -> 0x0015a030 ad::lyt::LytNumReel2::LytNumReel2 (static)

// FUNC 0x17000840 ->DataPcEquipFxParam::DataPcEquipFxParam (ShopMenu)
//   size 0x4 | file ShopMenu+0x840 | callers(1) 0x170144fc
// veneer/thunk -> 0x0027cb24 DataPcEquipFxParam::DataPcEquipFxParam (static)

// FUNC 0x17000848 ->msys::MCursorBase::MCursorBase (ShopMenu)
//   size 0x4 | file ShopMenu+0x848 | callers(1) 0x170144fc
// veneer/thunk -> 0x00324550 msys::MCursorBase::MCursorBase (static)

// FUNC 0x17000850 ->__aeabi_memclr4 (ShopMenu)
//   size 0x4 | file ShopMenu+0x850 | callers(1) 0x170144fc
// veneer/thunk -> 0x002876c0 __aeabi_memclr4 (static)

// FUNC 0x17000858 ->msys::MListWndPBase::MListWndPBase (ShopMenu)
//   size 0x4 | file ShopMenu+0x858 | callers(1) 0x170144fc
// veneer/thunk -> 0x00328800 msys::MListWndPBase::MListWndPBase (static)

// FUNC 0x17000860 ->ad::ui::UIListWindowPlusLyt::UIListWindowPlusLyt (ShopMenu)
//   size 0x4 | file ShopMenu+0x860 | callers(1) 0x170144fc
// veneer/thunk -> 0x00146984 ad::ui::UIListWindowPlusLyt::UIListWindowPlusLyt (static)

// FUNC 0x17000868 ->ad::lyt::Layout::Layout (ShopMenu)
//   size 0x4 | file ShopMenu+0x868 | callers(1) 0x170144fc
// veneer/thunk -> 0x00264ccc ad::lyt::Layout::Layout (static)

// FUNC 0x17000870 ->msys::StatusPanel::StatusPanel (ShopMenu)
//   size 0x4 | file ShopMenu+0x870 | callers(1) 0x170144fc
// veneer/thunk -> 0x00325e10 msys::StatusPanel::StatusPanel (static)

// FUNC 0x17000878 ->FrameBuf::setClearColor (ShopMenu)
//   size 0x4 | file ShopMenu+0x878 | callers(1) 0x170144fc
// veneer/thunk -> 0x0024c8d4 FrameBuf::setClearColor (static)

// FUNC 0x17000880 ->MoveWorkF::MoveWorkF (ShopMenu)
//   size 0x4 | file ShopMenu+0x880 | callers(1) 0x17014c78
// veneer/thunk -> 0x00278cc0 MoveWorkF::MoveWorkF (static)

// FUNC 0x17000888 ->MoveWorkF::~MoveWorkF (ShopMenu)
//   size 0x4 | file ShopMenu+0x888 | callers(2) 0x17014cac 0x17014cbc
// veneer/thunk -> 0x00340694 MoveWorkF::~MoveWorkF (static)

// FUNC 0x17000890 ->ad::fw::FileContext::initSingleFile (ShopMenu)
//   size 0x4 | file ShopMenu+0x890 | callers(1) 0x17014e34
// veneer/thunk -> 0x0013ad54 ad::fw::FileContext::initSingleFile (static)

// FUNC 0x17000898 ->ad::fw::FileContext::initArcFile (ShopMenu)
//   size 0x4 | file ShopMenu+0x898 | callers(1) 0x17014e34
// veneer/thunk -> 0x0013aca8 ad::fw::FileContext::initArcFile (static)

// FUNC 0x170008a0 ->ad::fw::FileContext::initCAArcFile (ShopMenu)
//   size 0x4 | file ShopMenu+0x8a0 | callers(1) 0x17014e34
// veneer/thunk -> 0x0013acc0 ad::fw::FileContext::initCAArcFile (static)

// FUNC 0x170008a8 ShopMenu::EntryTask (ShopMenu)
//   size 0x64 | file ShopMenu+0x8a8 | callers(0)

void ShopMenu::EntryTask(void)

{
  MTaskBase *this;
  undefined4 *puVar1;
  int iVar2;
  Task *pTVar3;
  
  this = operator_new(0x13e37c,gMemAlc,(char *)0x0,0);
  if (this == (MTaskBase *)0x0) {
    pTVar3 = (Task *)0x0;
  }
  else {
    puVar1 = (undefined4 *)msys::MTaskBase::MTaskBase(this);
    *puVar1 = &shop::ShopMenuTask::vtable;
    iVar2 = FUN_170144fc(puVar1 + 0x161);
    pTVar3 = (Task *)(iVar2 + -0x584);
    FUN_17014174(iVar2,pTVar3);
    *(int *)(iVar2 + -4) = iVar2;
  }
  TaskMan::entry((TaskMan *)&gTaskMainMan,pTVar3);
  return;
}


// FUNC 0x1700091c MemAlcH::vfunc_0x0 (ShopMenu)
//   size 0x8 | file ShopMenu+0x91c | callers(0) | datarefs 1

undefined4 MemAlcH::vfunc_0x0(void)

{
  return 0;
}


// FUNC 0x17000924 FUN_17000924 (ShopMenu)
//   size 0x850 | file ShopMenu+0x924 | callers(1) 0x17001488

/* WARNING: Removing unreachable block (ram,0x17000f50) */
/* WARNING: Removing unreachable block (ram,0x17000f54) */
/* WARNING: Removing unreachable block (ram,0x17000f60) */
/* WARNING: Removing unreachable block (ram,0x17000a9c) */
/* WARNING: Removing unreachable block (ram,0x17000a64) */
/* WARNING: Removing unreachable block (ram,0x17000a6c) */
/* WARNING: Removing unreachable block (ram,0x17000a78) */
/* WARNING: Removing unreachable block (ram,0x17000b44) */
/* WARNING: Removing unreachable block (ram,0x17000b4c) */
/* WARNING: Removing unreachable block (ram,0x17000b58) */
/* WARNING: Removing unreachable block (ram,0x17000b78) */
/* WARNING: Removing unreachable block (ram,0x17000c3c) */
/* WARNING: Removing unreachable block (ram,0x17000e80) */
/* WARNING: Removing unreachable block (ram,0x17001000) */
/* WARNING: Removing unreachable block (ram,0x17001004) */
/* WARNING: Removing unreachable block (ram,0x17001010) */
/* WARNING: Removing unreachable block (ram,0x17001160) */
/* WARNING: Removing unreachable block (ram,0x17000c88) */
/* WARNING: Removing unreachable block (ram,0x17000e9c) */
/* WARNING: Removing unreachable block (ram,0x17000ac0) */
/* WARNING: Removing unreachable block (ram,0x17000ba0) */
/* WARNING: Removing unreachable block (ram,0x17001170) */
/* WARNING: Removing unreachable block (ram,0x17001138) */
/* WARNING: Removing unreachable block (ram,0x17000f84) */
/* WARNING: Removing unreachable block (ram,0x17001038) */
/* WARNING: Removing unreachable block (ram,0x17000da8) */
/* WARNING: Removing unreachable block (ram,0x17000c9c) */
/* WARNING: Removing unreachable block (ram,0x17000d80) */
/* WARNING: Removing unreachable block (ram,0x17000c0c) */
/* WARNING: Removing unreachable block (ram,0x17000c70) */
/* WARNING: Removing unreachable block (ram,0x17000c5c) */

int FUN_17000924(int param_1)

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
    goto LAB_17000ea0;
  }
  pMVar5 = *(MemAlcBase **)(param_1 + 4);
  pcVar6 = *(char **)(param_1 + 8);
  uVar2 = *(uint *)(param_1 + 0xc);
  local_2c = (undefined4 *)0x0;
  local_28 = 0;
  if (uVar9 == 0) goto LAB_17000ba4;
  uVar11 = *(int *)(param_1 + 0x1c) * 2;
  if (uVar9 < uVar11) {
    if (pMVar5 == (MemAlcBase *)0x0) {
      if (uVar11 != 0) goto LAB_17000acc;
    }
    else {
      uVar11 = *(int *)(param_1 + 0x1c) * 0x38;
      local_2c = operator_new(uVar11,pMVar5,pcVar6,uVar2);
      if (local_2c == (undefined4 *)0x0) goto LAB_17000acc;
      local_28 = (uint)((ulonglong)uVar11 * 0x49249249 + 0x49249249 >> 0x23);
    }
LAB_17000ba4:
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
LAB_17000acc:
    if (pMVar5 != (MemAlcBase *)0x0) {
      local_2c = operator_new(uVar9 * 0x1c,pMVar5,pcVar6,uVar2);
      if (local_2c != (undefined4 *)0x0) {
        local_28 = (uint)((ulonglong)(uVar9 * 0x1c) * 0x49249249 + 0x49249249 >> 0x23);
        goto LAB_17000ba4;
      }
    }
  }
LAB_17000ea0:
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
  if (uVar2 == 0) goto LAB_1700103c;
  if (uVar2 < uVar9 * 2) {
    if (pMVar5 == (MemAlcBase *)0x0) {
      if (uVar9 * 2 == 0) goto LAB_1700103c;
    }
    else {
      local_2c = operator_new(uVar9 << 3,pMVar5,pcVar6,uVar11);
      if (local_2c != (int *)0x0) {
        local_28 = (uVar9 & 0x1fffffff) << 1;
        goto LAB_1700103c;
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
LAB_1700103c:
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


// FUNC 0x1700117c FUN_1700117c (ShopMenu)
//   size 0x10 | file ShopMenu+0x117c | callers(0) | datarefs 1

void FUN_1700117c(MsgDataAcsrBase *param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)MsgDataAcsrBase::~MsgDataAcsrBase(param_1);
  operator_delete(pvVar1);
  return;
}


// FUNC 0x1700118c ->MsgDataAcsrBase::~MsgDataAcsrBase (ShopMenu)
//   size 0x4 | file ShopMenu+0x118c | callers(0) | datarefs 1
// veneer/thunk -> 0x0026fdb4 MsgDataAcsrBase::~MsgDataAcsrBase (static)

// FUNC 0x17001190 FUN_17001190 (ShopMenu)
//   size 0xc | file ShopMenu+0x1190 | callers(0) | datarefs 1

void FUN_17001190(int *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x17001198. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x14))();
  return;
}


// FUNC 0x1700119c shop::ShopMenuTask::vfunc_0x1c (ShopMenu)
//   size 0x4 | file ShopMenu+0x119c | callers(0) | datarefs 1

void shop::ShopMenuTask::vfunc_0x1c(void)

{
  return;
}


// FUNC 0x170011a0 shop::ShopMenuTask::vfunc_0x4c (ShopMenu)
//   size 0x8 | file ShopMenu+0x11a0 | callers(0) | datarefs 1

undefined4 * shop::ShopMenuTask::vfunc_0x4c(void)

{
  return &gFrameBuf;
}


// FUNC 0x170011ac shop::ShopMenuTask::vfunc_0x3c (ShopMenu)
//   size 0x4 | file ShopMenu+0x11ac | callers(0) | datarefs 1

void shop::ShopMenuTask::vfunc_0x3c(void)

{
  return;
}


// FUNC 0x170011b0 shop::ShopMenuTask::vfunc_0x40 (ShopMenu)
//   size 0x4 | file ShopMenu+0x11b0 | callers(0) | datarefs 1

void shop::ShopMenuTask::vfunc_0x40(void)

{
  return;
}


// FUNC 0x170011b4 shop::ShopMenuTask::vfunc_0x30 (ShopMenu)
//   size 0x4 | file ShopMenu+0x11b4 | callers(0) | datarefs 1

void shop::ShopMenuTask::vfunc_0x30(void)

{
  return;
}


// FUNC 0x170011b8 shop::ShopMenuTask::vfunc_0x20 (ShopMenu)
//   size 0x4 | file ShopMenu+0x11b8 | callers(0) | datarefs 1

void shop::ShopMenuTask::vfunc_0x20(void)

{
  return;
}


// FUNC 0x170011bc shop::ShopMenuTask::vfunc_0x38 (ShopMenu)
//   size 0x4 | file ShopMenu+0x11bc | callers(0) | datarefs 1

void shop::ShopMenuTask::vfunc_0x38(void)

{
  return;
}


// FUNC 0x170011c0 shop::ShopMenuTask::vfunc_0x28 (ShopMenu)
//   size 0x4 | file ShopMenu+0x11c0 | callers(0) | datarefs 1

void shop::ShopMenuTask::vfunc_0x28(void)

{
  return;
}


// FUNC 0x170011c4 msys::MListWndPCore::vfunc_0x1c (ShopMenu)
//   size 0x20 | file ShopMenu+0x11c4 | callers(0) | datarefs 1

void msys::MListWndPCore::vfunc_0x1c(int *param_1,undefined4 param_2,undefined4 *param_3)

{
  (**(code **)(*param_1 + 0x18))(param_1,param_2,*param_3,param_3[1],param_3[2]);
  return;
}


// FUNC 0x170011e4 FUN_170011e4 (ShopMenu)
//   size 0x78 | file ShopMenu+0x11e4 | callers(0) | datarefs 1

int FUN_170011e4(DrawInfo *param_1)

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


// FUNC 0x17001270 ->operator.delete (ShopMenu)
//   size 0x4 | file ShopMenu+0x1270 | callers(0) | datarefs 1
// veneer/thunk -> 0x00286514 operator.delete (static)

// FUNC 0x17001274 nn::fs::IInputStream::vfunc_0x0 (ShopMenu)
//   size 0x4 | file ShopMenu+0x1274 | callers(0) | datarefs 1

void nn::fs::IInputStream::vfunc_0x0(void)

{
  return;
}


// FUNC 0x17001278 nn::fs::FileInputStream::vfunc_0x1c (ShopMenu)
//   size 0x24 | file ShopMenu+0x1278 | callers(0) | datarefs 1

void nn::fs::FileInputStream::vfunc_0x1c(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = detail::FileBase::TrySetPosition(CONCAT44(param_2,param_1 + 4));
  if (iVar1 < 0) {
    err::CTR::ThrowFatalErrAll(iVar1,0x1700128c);
    return;
  }
  return;
}


// FUNC 0x1700129c nn::fs::FileInputStream::vfunc_0x18 (ShopMenu)
//   size 0x8 | file ShopMenu+0x129c | callers(0) | datarefs 1

void nn::fs::FileInputStream::vfunc_0x18(int param_1,undefined4 param_2)

{
  detail::FileBase::TrySetPosition(CONCAT44(param_2,param_1 + 4));
  return;
}


// FUNC 0x170012a4 nn::fs::FileInputStream::vfunc_0x2c (ShopMenu)
//   size 0x2c | file ShopMenu+0x12a4 | callers(0) | datarefs 1

int nn::fs::FileInputStream::vfunc_0x2c(int param_1,void *param_2,uint param_3,int param_4)

{
  int iVar1;
  int local_8;
  
  local_8 = param_4;
  iVar1 = detail::FileBase::TryRead((FileBase *)(param_1 + 4),&local_8,param_2,param_3);
  if (iVar1 < 0) {
    err::CTR::ThrowFatalErrAll(iVar1,0x170012c4);
  }
  return local_8;
}


// FUNC 0x170012d0 nn::fs::FileInputStream::vfunc_0xc (ShopMenu)
//   size 0x2c | file ShopMenu+0x12d0 | callers(0) | datarefs 1

void nn::fs::FileInputStream::vfunc_0xc(int param_1)

{
  int iVar1;
  undefined4 in_stack_00000000;
  
  iVar1 = detail::FileBase::TrySeek(param_1 + 4);
  if (-(iVar1 >> 0x1f) == 0) {
    return;
  }
  err::CTR::ThrowFatalErrAll(iVar1,0x170012ec,-(iVar1 >> 0x1f),in_stack_00000000);
  return;
}


// FUNC 0x170012fc nn::fs::FileInputStream::vfunc_0x28 (ShopMenu)
//   size 0x8 | file ShopMenu+0x12fc | callers(0) | datarefs 1

void nn::fs::FileInputStream::vfunc_0x28(int param_1,int *param_2,void *param_3,uint param_4)

{
  detail::FileBase::TryRead((FileBase *)(param_1 + 4),param_2,param_3,param_4);
  return;
}


// FUNC 0x17001304 nn::fs::FileInputStream::vfunc_0x8 (ShopMenu)
//   size 0x18 | file ShopMenu+0x1304 | callers(0) | datarefs 1

void nn::fs::FileInputStream::vfunc_0x8(int param_1)

{
  detail::FileBase::TrySeek(param_1 + 4);
  return;
}


// FUNC 0x1700131c nn::fs::FileInputStream::vfunc_0x4 (ShopMenu)
//   size 0x40 | file ShopMenu+0x131c | callers(0) | datarefs 1

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


// FUNC 0x1700135c nn::fs::FileInputStream::vfunc_0x0 (ShopMenu)
//   size 0x3c | file ShopMenu+0x135c | callers(0) | datarefs 1

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


// FUNC 0x170013d8 shop::ShopMenuTask::vfunc_0xc (ShopMenu)
//   size 0xc | file ShopMenu+0x13d8 | callers(0) | datarefs 1

void shop::ShopMenuTask::vfunc_0xc(int *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x170013e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 8))();
  return;
}


// FUNC 0x170013e4 FUN_170013e4 (ShopMenu)
//   size 0x30 | file ShopMenu+0x13e4 | callers(0) | datarefs 1

int FUN_170013e4(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)FUN_1700c0a0();
  *puVar1 = &msys::MCellAnime::vtable;
  iVar2 = CellAnime::CellAnime((CellAnime *)(puVar1 + 0x53));
  *(undefined1 *)(iVar2 + 300) = 0xff;
  *(undefined1 *)(iVar2 + 0x12d) = 0xff;
  *(undefined1 *)(iVar2 + 0x12e) = 0xff;
  *(undefined1 *)(iVar2 + 0x12f) = 0xff;
  return iVar2 + -0x14c;
}


// FUNC 0x17001438 msys::MChrBase::vfunc_0x10 (ShopMenu)
//   size 0xc | file ShopMenu+0x1438 | callers(0) | datarefs 1

void msys::MChrBase::vfunc_0x10(int param_1)

{
  *(undefined1 *)(param_1 + 0x142) = 0;
  return;
}


// FUNC 0x17001444 msys::MChrBase::vfunc_0xc (ShopMenu)
//   size 0x4 | file ShopMenu+0x1444 | callers(0) | datarefs 2

void msys::MChrBase::vfunc_0xc(void)

{
  return;
}


// FUNC 0x17001448 msys::MChrBase::vfunc_0x8 (ShopMenu)
//   size 0xc | file ShopMenu+0x1448 | callers(0) | datarefs 1

void msys::MChrBase::vfunc_0x8(int param_1)

{
  *(undefined1 *)(param_1 + 0x142) = 1;
  return;
}


// FUNC 0x17001454 FUN_17001454 (ShopMenu)
//   size 0x4 | file ShopMenu+0x1454 | callers(0) | datarefs 5

void FUN_17001454(void)

{
  return;
}


// FUNC 0x17001458 msys::MReelNumMan2::vfunc_0x10 (ShopMenu)
//   size 0xc | file ShopMenu+0x1458 | callers(0) | datarefs 1

void msys::MReelNumMan2::vfunc_0x10(int param_1)

{
  *(undefined1 *)(param_1 + 0x142) = 0;
  return;
}


// FUNC 0x17001464 msys::MReelNumMan2::vfunc_0x20 (ShopMenu)
//   size 0x18 | file ShopMenu+0x1464 | callers(0) | datarefs 1

bool msys::MReelNumMan2::vfunc_0x20(int param_1)

{
  return *(int *)(param_1 + 0x1e4) != *(int *)(param_1 + 0x1dc);
}


// FUNC 0x1700147c msys::MReelNumMan2::vfunc_0x8 (ShopMenu)
//   size 0x8 | file ShopMenu+0x147c | callers(0) | datarefs 1

void msys::MReelNumMan2::vfunc_0x8(float param_1)

{
  ad::lyt::LytNumReel2::update(param_1);
  return;
}


// FUNC 0x17001484 msys::MReelNumMan2::vfunc_0x38 (ShopMenu)
//   size 0x4 | file ShopMenu+0x1484 | callers(0) | datarefs 1

void msys::MReelNumMan2::vfunc_0x38(void)

{
  return;
}


// FUNC 0x17001488 msys::MReelNumMan2::vfunc_0x14 (ShopMenu)
//   size 0x188 | file ShopMenu+0x1488 | callers(0) | datarefs 1

void msys::MReelNumMan2::vfunc_0x14(int param_1,int param_2,uint param_3)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  int iVar4;
  float fVar5;
  uint uVar6;
  
  iVar4 = *(int *)(param_1 + 0x14c);
  if (*(char *)(param_1 + 0x230) == '\0') {
    return;
  }
  iVar1 = *(int *)(param_1 + 0x158);
  if (*(char *)(iVar4 + 200) == '\0') {
    fVar5 = *(float *)(param_2 + 0x4da1c) +
            *(float *)(iVar1 + 0x54) * *(float *)(param_2 + 0x4da10) +
            *(float *)(iVar1 + 100) * *(float *)(param_2 + 0x4da14) +
            *(float *)(iVar1 + 0x74) * *(float *)(param_2 + 0x4da18);
    fVar5 = (*(float *)(param_2 + 0x4da4c) + fVar5 * *(float *)(param_2 + 0x4da48)) /
            (*(float *)(param_2 + 0x4da5c) + fVar5 * *(float *)(param_2 + 0x4da58));
  }
  else {
    fVar5 = (*(float *)(param_2 + 0x4da4c) +
            *(float *)(iVar1 + 0x74) * *(float *)(param_2 + 0x4da48)) /
            (*(float *)(param_2 + 0x4da5c) +
            *(float *)(iVar1 + 0x74) * *(float *)(param_2 + 0x4da58));
  }
  if ((uint)fVar5 < 0xbf800001) {
    if (0.0 < fVar5) {
      fVar5 = 0.0;
    }
  }
  else {
    fVar5 = -1.0;
  }
  uVar6 = VectorFloatToUnsigned((fVar5 + 1.0) * 16777215.0,3);
  puVar2 = (undefined1 *)FUN_17000924(param_2);
  uVar3 = (**(code **)(**(int **)(param_2 + 0xec) + 0x10))();
  *puVar2 = 4;
  *(undefined4 *)(puVar2 + 0x18) = uVar3;
  *(uint *)(puVar2 + 4) = (uVar6 & 0xffffff) << 3 | (param_3 & 0xf) << 0x1b | 0x80000000 | 4;
  *(undefined4 *)(puVar2 + 8) = 3;
  *(int *)(puVar2 + 0xc) = param_1 + 0x150;
  *(int *)(puVar2 + 0x10) = iVar4;
  *(undefined4 *)(puVar2 + 0x14) = 0;
  return;
}


// FUNC 0x17001628 msys::MReelNumMan2::vfunc_0x4 (ShopMenu)
//   size 0x38 | file ShopMenu+0x1628 | callers(0) | datarefs 1

void msys::MReelNumMan2::vfunc_0x4(undefined4 *param_1)

{
  int iVar1;
  void *pvVar2;
  
  *param_1 = &vtable;
  ad::lyt::LytNumReel2::term((LytNumReel2 *)(param_1 + 0x54));
  *(undefined1 *)(param_1 + 0x8d) = 0;
  iVar1 = ad::lyt::LytNumReel2::~LytNumReel2((LytNumReel2 *)(param_1 + 0x54));
  pvVar2 = (void *)MChrBase::vfunc_0x0(iVar1 + -0x150);
  operator_delete(pvVar2);
  return;
}


// FUNC 0x17001664 msys::MReelNumMan2::vfunc_0x0 (ShopMenu)
//   size 0x34 | file ShopMenu+0x1664 | callers(0) | datarefs 1

void msys::MReelNumMan2::vfunc_0x0(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &vtable;
  ad::lyt::LytNumReel2::term((LytNumReel2 *)(param_1 + 0x54));
  *(undefined1 *)(param_1 + 0x8d) = 0;
  iVar1 = ad::lyt::LytNumReel2::~LytNumReel2((LytNumReel2 *)(param_1 + 0x54));
  MChrBase::vfunc_0x0(iVar1 + -0x150);
  return;
}


// FUNC 0x1700169c msys::MListWndPCore::vfunc_0x30 (ShopMenu)
//   size 0x2c | file ShopMenu+0x169c | callers(0) | datarefs 1

void msys::MListWndPCore::vfunc_0x30(void)

{
  FUN_1700beb8(MComSys::_sys + 0x49368,0x110015,0,0,0);
  return;
}


// FUNC 0x170016d0 msys::MListWndPCore::vfunc_0x2c (ShopMenu)
//   size 0x2c | file ShopMenu+0x16d0 | callers(0) | datarefs 1

void msys::MListWndPCore::vfunc_0x2c(void)

{
  FUN_1700beb8(MComSys::_sys + 0x49368,0x110015,0,0,0);
  return;
}


// FUNC 0x17001704 msys::MListWndPCore::vfunc_0x34 (ShopMenu)
//   size 0x2c | file ShopMenu+0x1704 | callers(0) | datarefs 1

void msys::MListWndPCore::vfunc_0x34(void)

{
  FUN_1700beb8(MComSys::_sys + 0x49368,0x110015,0,0,0);
  return;
}


// FUNC 0x17001738 msys::MListWndPCore::vfunc_0x38 (ShopMenu)
//   size 0x2c | file ShopMenu+0x1738 | callers(0) | datarefs 1

void msys::MListWndPCore::vfunc_0x38(void)

{
  FUN_1700beb8(MComSys::_sys + 0x49368,0x110015,0,0,0);
  return;
}


// FUNC 0x1700176c msys::MListWndPCore::vfunc_0x3c (ShopMenu)
//   size 0x2c | file ShopMenu+0x176c | callers(0) | datarefs 1

void msys::MListWndPCore::vfunc_0x3c(void)

{
  FUN_1700beb8(MComSys::_sys + 0x49368,0x110018,0,0,0);
  return;
}


// FUNC 0x170017a0 msys::MListWndPCore::vfunc_0x44 (ShopMenu)
//   size 0x10 | file ShopMenu+0x17a0 | callers(0) | datarefs 1

void msys::MListWndPCore::vfunc_0x44(UIListWindowPlusLyt *param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)ad::ui::UIListWindowPlusLyt::~UIListWindowPlusLyt(param_1);
  operator_delete(pvVar1);
  return;
}


// FUNC 0x170017b0 ->ad::ui::UIListWindowPlusLyt::~UIListWindowPlusLyt (ShopMenu)
//   size 0x4 | file ShopMenu+0x17b0 | callers(0) | datarefs 1
// veneer/thunk -> 0x0025a3fc ad::ui::UIListWindowPlusLyt::~UIListWindowPlusLyt (static)

// FUNC 0x170017b4 shop::ShopMenu::vfunc_0x14 (ShopMenu)
//   size 0x8 | file ShopMenu+0x17b4 | callers(0) | datarefs 1

undefined4 shop::ShopMenu::vfunc_0x14(void)

{
  return 0;
}


// FUNC 0x170017bc msys::MChrBase::vfunc_0x4 (ShopMenu)
//   size 0x10 | file ShopMenu+0x17bc | callers(0) | datarefs 1

void msys::MChrBase::vfunc_0x4(void)

{
  void *pvVar1;
  
  pvVar1 = (void *)vfunc_0x0();
  operator_delete(pvVar1);
  return;
}


// FUNC 0x170017cc FUN_170017cc (ShopMenu)
//   size 0x20 | file ShopMenu+0x17cc | callers(0) | datarefs 1

void FUN_170017cc(undefined4 *param_1)

{
  int iVar1;
  void *pvVar2;
  
  *param_1 = &vtable_for_N4msys9MListWndPILi256EEE;
  iVar1 = ad::ui::UIListWindowPlusLyt::~UIListWindowPlusLyt((UIListWindowPlusLyt *)(param_1 + 0x7f))
  ;
  pvVar2 = (void *)msys::MListWndPBase::~MListWndPBase((MListWndPBase *)(iVar1 + -0x1fc));
  operator_delete(pvVar2);
  return;
}


// FUNC 0x170017f0 FUN_170017f0 (ShopMenu)
//   size 0x1c | file ShopMenu+0x17f0 | callers(0) | datarefs 1

void FUN_170017f0(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &vtable_for_N4msys9MListWndPILi256EEE;
  iVar1 = ad::ui::UIListWindowPlusLyt::~UIListWindowPlusLyt((UIListWindowPlusLyt *)(param_1 + 0x7f))
  ;
  msys::MListWndPBase::~MListWndPBase((MListWndPBase *)(iVar1 + -0x1fc));
  return;
}


// FUNC 0x17001810 shop::ShopMenu_PageBase::vfunc_0x20 (ShopMenu)
//   size 0x8 | file ShopMenu+0x1810 | callers(0) | datarefs 6

void shop::ShopMenu_PageBase::vfunc_0x20
               (MPageBase *param_1,undefined4 param_2,MRenderQueue *param_3)

{
  msys::MPageBase::enqueueLowerChr(param_1,param_3);
  return;
}


// FUNC 0x17001818 shop::ShopMenu_PageBase::vfunc_0x1c (ShopMenu)
//   size 0x8 | file ShopMenu+0x1818 | callers(0) | datarefs 6

void shop::ShopMenu_PageBase::vfunc_0x1c
               (MPageBase *param_1,undefined4 param_2,MRenderQueue *param_3)

{
  msys::MPageBase::enqueueUpperChr(param_1,param_3);
  return;
}


// FUNC 0x17001820 shop::BuyPnlBase::ItemPnlPane::vfunc_0x0 (ShopMenu)
//   size 0x2c | file ShopMenu+0x1820 | callers(0) | datarefs 1

void shop::BuyPnlBase::ItemPnlPane::vfunc_0x0(int param_1,int param_2)

{
  uint in_fpscr;
  float fVar1;
  
  ItemPnlBase::vfunc_0x0();
  fVar1 = (float)VectorUnsignedToFloat((uint)*(byte *)(param_2 + 9),(byte)(in_fpscr >> 0x16) & 3);
  ad::lyt::LytAnim::stopAndSetFrm(*(LytAnim **)(param_1 + 0x7058),fVar1);
  return;
}


// FUNC 0x17001850 shop::BuyPnlBase::ItemPnlCA::vfunc_0x0 (ShopMenu)
//   size 0x2c | file ShopMenu+0x1850 | callers(0) | datarefs 1

void shop::BuyPnlBase::ItemPnlCA::vfunc_0x0(int param_1,int param_2)

{
  ItemPnlBase::vfunc_0x0();
  CellAnime::play((CellAnime *)(param_1 + 0x71a4),*(uchar *)(param_2 + 0xb),0,1.0);
  return;
}


// FUNC 0x17001880 FUN_17001880 (ShopMenu)
//   size 0x6c | file ShopMenu+0x1880 | callers(0)

void FUN_17001880(int param_1,undefined4 param_2,Resource *param_3,undefined4 param_4)

{
  FUN_1700ba88(param_1,param_2,param_4,param_4,param_4);
  msys::MCellAnime::init((MCellAnime *)(param_1 + 0x7058),param_3);
  *(byte *)(param_1 + 0x7247) = *(byte *)(param_1 + 0x7247) | 3;
  *(undefined1 *)(param_1 + 0x723c) = 0;
  *(undefined1 *)(param_1 + 0x723d) = 0;
  msys::MLyt::attachMChrF
            (*(MLyt **)(param_1 + 0x60),(MChrBase *)(param_1 + 0x7058),"INS_ICON_ITEM_list",
             (char *)0x0,(char *)0x0);
  return;
}


// FUNC 0x17001900 FUN_17001900 (ShopMenu)
//   size 0xec | file ShopMenu+0x1900 | callers(0)

void FUN_17001900(int param_1,int param_2,Resource *param_3,MLyt *param_4)

{
  undefined4 uVar1;
  
  *(MLyt **)(param_1 + 0x5c) = param_4;
  uVar1 = msys::MLyt::getPane(param_4,"NAME_BAR",(char *)0x0,(char *)0x0);
  *(undefined4 *)(param_1 + 0x60) = uVar1;
  msys::MCellAnime::init((MCellAnime *)(param_1 + 100),param_3);
  *(byte *)(param_1 + 0x253) = *(byte *)(param_1 + 0x253) | 3;
  *(undefined1 *)(param_1 + 0x248) = 0;
  *(undefined1 *)(param_1 + 0x249) = 0;
  msys::MLyt::attachMChr
            (param_4,(MChrBase *)(param_1 + 100),"INS_ICON_ITEM",(char *)0x0,(char *)0x0,(char *)0x0
            );
  *(undefined4 *)(param_1 + 0x6f20) = 0x401;
  *(int *)(param_1 + 0x6f14) = param_2 + 0xc;
  *(undefined4 *)(param_1 + 0x6f18) = 0;
  *(undefined4 *)(param_1 + 0x6f1c) = 0;
  MessageSimple::init((MessageSimple *)(param_1 + 0x42c));
  FUN_1700bd6c(param_1 + 0x2e0);
  MessageWriter::setFontColor((MessageWriter *)(param_1 + 0x42c),0xe6e6e6ff,true);
  msys::MLyt::attachMChr
            (param_4,(MChrBase *)(param_1 + 0x2e0),"INS_list_text",(char *)0x0,(char *)0x0,
             (char *)0x0);
  return;
}


// FUNC 0x17001a24 FUN_17001a24 (ShopMenu)
//   size 0xec | file ShopMenu+0x1a24 | callers(0)

void FUN_17001a24(int param_1,int param_2,Resource *param_3,MLyt *param_4)

{
  undefined4 uVar1;
  
  *(MLyt **)(param_1 + 0x5c) = param_4;
  uVar1 = msys::MLyt::getPane(param_4,"NAME_BAR",(char *)0x0,(char *)0x0);
  *(undefined4 *)(param_1 + 0x60) = uVar1;
  msys::MCellAnime::init((MCellAnime *)(param_1 + 100),param_3);
  *(byte *)(param_1 + 0x253) = *(byte *)(param_1 + 0x253) | 3;
  *(undefined1 *)(param_1 + 0x248) = 0;
  *(undefined1 *)(param_1 + 0x249) = 0;
  msys::MLyt::attachMChr
            (param_4,(MChrBase *)(param_1 + 100),"INS_ICON",(char *)0x0,(char *)0x0,(char *)0x0);
  *(undefined4 *)(param_1 + 0x6f20) = 0x400;
  *(int *)(param_1 + 0x6f14) = param_2 + 0xc;
  *(undefined4 *)(param_1 + 0x6f18) = 0;
  *(undefined4 *)(param_1 + 0x6f1c) = 0;
  MessageSimple::init((MessageSimple *)(param_1 + 0x42c));
  FUN_1700bd6c(param_1 + 0x2e0);
  MessageWriter::setFontColor((MessageWriter *)(param_1 + 0x42c),0xe6e6e6ff,true);
  msys::MLyt::attachMChr
            (param_4,(MChrBase *)(param_1 + 0x2e0),"INS_list_text_top",(char *)0x0,(char *)0x0,
             (char *)0x0);
  return;
}


// FUNC 0x17001b3c FUN_17001b3c (ShopMenu)
//   size 0x2f8 | file ShopMenu+0x1b3c | callers(1) 0x1700e770

void FUN_17001b3c(MMsg *param_1,int param_2,Resource *param_3)

{
  undefined4 uVar1;
  wchar_t *pwVar2;
  MMsg *pMVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  MemAlcBase *pMVar7;
  MLyt *pMVar8;
  
  pMVar8 = (MLyt *)(param_2 + 0xea034);
  *(MLyt **)(param_1 + 0x6e1c) = pMVar8;
  uVar1 = msys::MLyt::getPane(pMVar8,"NAME_BAR",(char *)0x0,(char *)0x0);
  *(undefined4 *)(param_1 + 0x6e20) = uVar1;
  msys::MCellAnime::init((MCellAnime *)(param_1 + 0x6e24),param_3);
  param_1[0x7013] = (MMsg)((byte)param_1[0x7013] | 3);
  param_1[0x7008] = (MMsg)0x0;
  param_1[0x7009] = (MMsg)0x0;
  msys::MLyt::attachMChr
            (pMVar8,(MChrBase *)(param_1 + 0x6e24),"INS_ICON",(char *)0x0,(char *)0x0,(char *)0x0);
  pMVar7 = (MemAlcBase *)(param_2 + 0xc);
  *(MemAlcBase **)(param_1 + 0xdcd4) = pMVar7;
  *(undefined4 *)(param_1 + 0xdcd8) = 0;
  *(undefined4 *)(param_1 + 0xdce0) = 0x400;
  *(undefined4 *)(param_1 + 0xdcdc) = 0;
  MessageSimple::init((MessageSimple *)(param_1 + 0x71ec));
  FUN_1700bd6c(param_1 + 0x70a0);
  MessageWriter::setFontColor((MessageWriter *)(param_1 + 0x71ec),0xe6e6e6ff,true);
  msys::MLyt::attachMChr
            (pMVar8,(MChrBase *)(param_1 + 0x70a0),"INS_list_text_top",(char *)0x0,(char *)0x0,
             (char *)0x0);
  pMVar8 = (MLyt *)(param_2 + 0xea3dc);
  *(MLyt **)(param_1 + 0xdd40) = pMVar8;
  uVar1 = msys::MLyt::getPane(pMVar8,"NAME_BAR",(char *)0x0,(char *)0x0);
  *(undefined4 *)(param_1 + 0xdd44) = uVar1;
  msys::MCellAnime::init((MCellAnime *)(param_1 + 0xdd48),param_3);
  param_1[0xdf37] = (MMsg)((byte)param_1[0xdf37] | 3);
  param_1[0xdf2c] = (MMsg)0x0;
  param_1[0xdf2d] = (MMsg)0x0;
  msys::MLyt::attachMChr
            (pMVar8,(MChrBase *)(param_1 + 0xdd48),"INS_ICON_ITEM",(char *)0x0,(char *)0x0,
             (char *)0x0);
  *(MemAlcBase **)(param_1 + 0x14bf8) = pMVar7;
  *(undefined4 *)(param_1 + 0x14bfc) = 0;
  *(undefined4 *)(param_1 + 0x14c04) = 0x401;
  *(undefined4 *)(param_1 + 0x14c00) = 0;
  MessageSimple::init((MessageSimple *)(param_1 + 0xe110));
  FUN_1700bd6c(param_1 + 0xdfc4);
  MessageWriter::setFontColor((MessageWriter *)(param_1 + 0xe110),0xe6e6e6ff,true);
  msys::MLyt::attachMChr
            (pMVar8,(MChrBase *)(param_1 + 0xdfc4),"INS_list_text",(char *)0x0,(char *)0x0,
             (char *)0x0);
  *(MemAlcBase **)(param_1 + 0x6c34) = pMVar7;
  *(undefined4 *)(param_1 + 0x6c38) = 0;
  *(undefined4 *)(param_1 + 0x6c40) = 0x401;
  *(undefined4 *)(param_1 + 0x6c3c) = 0;
  MessageSimple::init((MessageSimple *)(param_1 + 0x14c));
  FUN_1700bd6c(param_1);
  param_1[0x5c08] = (MMsg)0x1;
  uVar1 = LMS_GetTextIndexByLabel(param_2 + 0xe93ec,"MES_ShopMes_Info_Equip");
  pwVar2 = (wchar_t *)LMS_GetText(param_2 + 0xe93ec,uVar1);
  msys::MMsg::playStr(param_1,pwVar2,(InsParam *)0x0,false);
  msys::MLyt::attachMChr
            (pMVar8,(MChrBase *)param_1,"INS_EQUIP_now_text",(char *)0x0,(char *)0x0,(char *)0x0);
  msys::MDfxChr::init((MDfxChr *)(param_1 + 0x6c44),pMVar7,*(MDfxSys **)(param_2 + 0xe64f0),
                      (Scene *)(param_2 + 0x4aaa0),0x400);
  *(undefined4 *)(param_1 + 0x6d80) = 0x400;
  piVar4 = (int *)(param_2 + 0xe64d8);
  puVar6 = *(undefined4 **)(param_1 + 0x6c4c);
  *(undefined4 **)(*(int *)(param_1 + 0x6c48) + 4) = puVar6;
  *puVar6 = *(undefined4 *)(param_1 + 0x6c48);
  pMVar3 = param_1 + 0x6c48;
  if (pMVar3 != (MMsg *)0x0) {
    iVar5 = *piVar4;
    *(int **)(param_1 + 0x6c4c) = piVar4;
    *(int *)pMVar3 = iVar5;
    *(MMsg **)(iVar5 + 4) = pMVar3;
    *piVar4 = (int)pMVar3;
  }
  return;
}


// FUNC 0x17001e94 FUN_17001e94 (ShopMenu)
//   size 0x188 | file ShopMenu+0x1e94 | callers(1) 0x17012c3c

void FUN_17001e94(int *param_1,int param_2)

{
  MPaneRef *pMVar1;
  undefined4 *puVar2;
  uint uVar3;
  int *piVar4;
  InitParam aIStack_88 [72];
  char *local_40 [7];
  
  *param_1 = param_2;
  param_1[0x1e59] = 0x400;
  param_1[0x1e56] = param_2 + 0xc;
  param_1[0x1e57] = 0;
  param_1[0x1e58] = 0;
  MessageSimple::init((MessageSimple *)(param_1 + 0x39c));
  FUN_1700bd6c((MChrBaseCore *)(param_1 + 0x349));
  *(undefined1 *)(param_1 + 0x1a4b) = 1;
  *(undefined1 *)((int)param_1 + 0x7949) = 1;
  *(undefined1 *)(param_1 + 0x1e52) = 4;
  param_1[0x19a6] = (int)&DAT_003fc140;
  MessageWriter::setFontColor((MessageWriter *)(param_1 + 0x39c),0x373737ff,true);
  pMVar1 = (MPaneRef *)
           msys::MLyt::getMPaneRef
                     ((MLyt *)(param_2 + 0xea034),"INS_TOP_PANEL_TEXT","EXP_PNL_U_down",(char *)0x0,
                      (char *)0x0);
  piVar4 = (int *)param_1[0x34b];
  *(int **)(param_1[0x34a] + 4) = piVar4;
  *piVar4 = param_1[0x34a];
  piVar4 = param_1 + 0x34a;
  if (piVar4 != (int *)0x0) {
    *piVar4 = (int)(pMVar1 + 0x10);
    puVar2 = *(undefined4 **)(pMVar1 + 0x14);
    param_1[0x34b] = (int)puVar2;
    *puVar2 = piVar4;
    *(int **)(pMVar1 + 0x14) = piVar4;
  }
  msys::MChrBaseCore::setParent((MChrBaseCore *)(param_1 + 0x349),pMVar1);
  local_40[0] = "SNUM_HP";
  local_40[1] = "SNUM_BP";
  local_40[2] = "SNUM_POW";
  local_40[3] = "SNUM_DEF";
  local_40[4] = "SNUM_SPEED";
  local_40[5] = "SNUM_HT";
  ad::lyt::LytNumReel3::InitParam::InitParam(aIStack_88);
  uVar3 = 0;
  do {
    msys::MLytNumRes::set((MLytNumRes *)(param_2 + 0x844),aIStack_88,0,0,0xff);
    msys::MLytNum::init((MLytNum *)(param_1 + uVar3 * 0x8c + 1),aIStack_88,
                        (LytDrawData *)(param_2 + 0xd3000),(MLyt *)(param_2 + 0xea034),
                        local_40[uVar3],"PNL_STATUS_SET","EXP_PNL_U_down",(char *)0x0);
    uVar3 = uVar3 + 1;
  } while (uVar3 < 6);
  return;
}


// FUNC 0x17002068 FUN_17002068 (ShopMenu)
//   size 0x16c | file ShopMenu+0x2068 | callers(1) 0x17012c3c

void FUN_17002068(MMsg *param_1,int param_2,MLyt *param_3)

{
  undefined4 uVar1;
  wchar_t *pwVar2;
  int iVar3;
  InitParam aIStack_68 [20];
  undefined4 local_54;
  
  uVar1 = msys::MLyt::getPane(param_3,"LBL_HAVE",(char *)0x0,(char *)0x0);
  *(undefined4 *)(param_1 + 0x6e74) = uVar1;
  *(undefined4 *)(param_1 + 0x6c40) = 0x401;
  *(int *)(param_1 + 0x6c34) = param_2 + 0xc;
  *(undefined4 *)(param_1 + 0x6c38) = 0;
  *(undefined4 *)(param_1 + 0x6c3c) = 0;
  MessageSimple::init((MessageSimple *)(param_1 + 0x14c));
  FUN_1700bd6c(param_1);
  MessageWriter::setFontColor((MessageWriter *)(param_1 + 0x14c),0xe6e6e6ff,true);
  uVar1 = LMS_GetTextIndexByLabel(param_2 + 0xe93ec,"MES_ShopMes_Info_Stock");
  pwVar2 = (wchar_t *)LMS_GetText(param_2 + 0xe93ec,uVar1);
  msys::MMsg::playStr(param_1,pwVar2,(InsParam *)0x0,false);
  msys::MLyt::attachMChr(param_3,(MChrBase *)param_1,"INS_text","LBL_HAVE",(char *)0x0,(char *)0x0);
  iVar3 = msys::MLyt::getPane(param_3,"BASE","LBL_HAVE",(char *)0x0);
  *(float *)(iVar3 + 0x3c) = *(float *)(param_1 + 0x6c3c) + 56.0;
  *(undefined4 *)(iVar3 + 0x40) = *(undefined4 *)(iVar3 + 0x40);
  *(byte *)(iVar3 + 0x44) = *(byte *)(iVar3 + 0x44) & 0xef | 0x10;
  ad::lyt::LytNumReel3::InitParam::InitParam(aIStack_68);
  local_54 = 0;
  msys::MLytNumRes::set((MLytNumRes *)(param_2 + 0x844),aIStack_68,0,0,0xff);
  msys::MLytNum::init((MLytNum *)(param_1 + 0x6c44),aIStack_68,(LytDrawData *)(param_2 + 0xd3000),
                      param_3,"HAVE_num","LBL_HAVE",(char *)0x0,(char *)0x0);
  return;
}


// FUNC 0x17002228 FUN_17002228 (ShopMenu)
//   size 0x268 | file ShopMenu+0x2228 | callers(1) 0x170121ec

undefined4 FUN_17002228(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  char cVar2;
  short sVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  undefined2 uVar9;
  int iVar10;
  int *piVar11;
  uint uVar12;
  int *piVar13;
  int iVar14;
  uint in_fpscr;
  float fVar15;
  float fVar16;
  
  cVar1 = (char)param_1[0x1cb8];
  piVar11 = (int *)param_1[0x1dd2];
  piVar13 = (int *)param_1[0x1dd1];
  sVar3 = *(short *)((int)param_1 + 0x72e2);
  if (cVar1 == '\0') {
    bVar4 = *(byte *)(param_2 + 4) & 0x40;
joined_r0x17002278:
    if (bVar4 != 0) goto LAB_170022f0;
LAB_170022a0:
    if (sVar3 != -1) {
      (**(code **)(*piVar11 + 0x28))(piVar11,1,*(code **)(*piVar11 + 0x28),param_4,param_4);
      (**(code **)(*piVar13 + 0x28))(piVar13,1);
      if ((char)param_1[0x1cb8] == '\0') {
        (**(code **)(*piVar13 + 0xc))(piVar13);
      }
      if ((char)param_1[0x1cb8] == '\x01') {
        (**(code **)(*piVar11 + 0xc))(piVar11);
      }
      return 0;
    }
  }
  else {
    if (cVar1 == '\x01') {
      bVar4 = *(byte *)(param_2 + 4) & 0x80;
      goto joined_r0x17002278;
    }
    if (cVar1 == '\x02') {
      if ((char)piVar13[1] == '\x01' || (char)piVar13[1] == '\x03') goto LAB_170022f0;
      goto LAB_170022a0;
    }
    if ((cVar1 != '\x03') || ((char)piVar11[1] != '\x01' && (char)piVar11[1] != '\x03'))
    goto LAB_170022a0;
LAB_170022f0:
    if (sVar3 != -1) {
      if (0 < sVar3) {
        iVar5 = ad::fw::TaskBase::isFps30(*(TaskBase **)(*param_1 + 4));
        if (iVar5 == 0) {
          fVar15 = 1.0;
        }
        else {
          fVar15 = 2.0;
        }
        fVar16 = (float)VectorSignedToFloat((int)*(short *)((int)param_1 + 0x72e2),
                                            (byte)(in_fpscr >> 0x16) & 3);
        sVar3 = (short)(int)(fVar16 - fVar15);
        *(short *)((int)param_1 + 0x72e2) = sVar3;
        if (sVar3 < 0) {
          *(undefined2 *)((int)param_1 + 0x72e2) = 0;
          return 1;
        }
        return 1;
      }
      uVar9 = *(undefined2 *)(*(int *)(*param_1 + 0xe904c) + 0x18);
      goto LAB_1700239c;
    }
  }
  uVar9 = *(undefined2 *)(*(int *)(*param_1 + 0xe904c) + 0x14);
LAB_1700239c:
  *(undefined2 *)((int)param_1 + 0x72e2) = uVar9;
  cVar2 = (char)param_1[0x1db8];
  uVar12 = 0xffffffff;
  iVar10 = (int)cVar2;
  iVar5 = iVar10;
  if (cVar1 == '\0' || cVar1 == '\x02') {
    iVar14 = (int)(char)(cVar2 + '\x01');
    iVar8 = GameWork::getItemNum((GameWork *)&gGameWork,*(ushort *)param_1[2]);
    iVar6 = GameWork::getUseItemMax();
    if (iVar8 + iVar14 <= iVar6) {
      uVar12 = (uint)*(ushort *)(param_1[2] + 4) * iVar14;
      uVar7 = GameWork::getCoin((GameWork *)&gGameWork);
      if (uVar12 <= uVar7) {
        iVar5 = iVar14;
      }
    }
  }
  else if (cVar1 == '\x01' || cVar1 == '\x03') {
    iVar8 = (int)(char)(cVar2 + -1);
    if (0 < iVar8) {
      iVar5 = iVar8;
    }
    uVar12 = (uint)*(ushort *)(param_1[2] + 4) * iVar8;
  }
  if (iVar5 != iVar10) {
    ad::lyt::LytNumReel3::setValueInstant((LytNumReel3 *)(param_1 + 0x1d99),iVar5);
    ad::lyt::LytNumReel3::setValueInstant((LytNumReel3 *)(param_1 + 0x1d0d),uVar12);
    FUN_1700beb8(*param_1 + 0x49368,0x11001f,0,0,0);
  }
  return 1;
}


// FUNC 0x170024a0 FUN_170024a0 (ShopMenu)
//   size 0x7c | file ShopMenu+0x24a0 | callers(0)

void FUN_170024a0(MLytNum *param_1,int param_2,MLyt *param_3)

{
  InitParam aIStack_58 [20];
  undefined4 local_44;
  
  ad::lyt::LytNumReel3::InitParam::InitParam(aIStack_58);
  local_44 = GameWork::getCoin((GameWork *)&gGameWork);
  msys::MLytNumRes::set((MLytNumRes *)(param_2 + 0x844),aIStack_58,0,0,0xff);
  msys::MLytNum::init(param_1,aIStack_58,(LytDrawData *)(param_2 + 0xd3000),param_3,"count_num",
                      (char *)0x0,(char *)0x0,(char *)0x0);
  return;
}


// FUNC 0x1700252c FUN_1700252c (ShopMenu)
//   size 0x3c4 | file ShopMenu+0x252c | callers(1) 0x17012c3c

void FUN_1700252c(MListWndPBase *param_1,int param_2,LytResourceMan *param_3,undefined4 param_4,
                 Resource *param_5)

{
  byte bVar1;
  undefined4 *puVar2;
  void *pvVar3;
  ushort *puVar4;
  MListWndPBase *pMVar5;
  Layout *pLVar6;
  int local_1f8 [2];
  CellAnime *local_1f0;
  undefined4 local_1e4;
  undefined4 local_1e0;
  undefined4 local_1d8;
  undefined4 local_1d4;
  undefined4 local_1cc;
  undefined4 local_1c8;
  undefined4 local_1c0;
  LytAnim *local_1bc;
  LytAnim *local_1b8;
  undefined4 local_1b0;
  LytAnim *local_1a8;
  LytAnim *local_1a4;
  LytAnim *local_1a0;
  LytAnim *local_19c;
  LytAnim *local_198;
  undefined1 auStack_124 [104];
  MListWndPBase *local_bc;
  LytLocalize aLStack_80 [16];
  undefined4 local_70;
  LytAnim *local_5c;
  LytAnim *local_58;
  LytAnim *local_54;
  Layout *local_50;
  LytAnim *local_4c;
  LytAnim *local_44;
  LytAnim *local_3c;
  LytAnim *local_38;
  
  *(int *)(param_1 + 0x8b80) = param_2;
  *(undefined4 *)(param_1 + 0x8e0c) = param_4;
  pLVar6 = (Layout *)(param_1 + 0x8b84);
  ad::lyt::LytResourceMan::buildLayout
            (param_3,pLVar6,"SHOP_L_LIST_BUY.bflyt",(ControlCreator *)0x0,(TextSearcher *)0x0);
  local_38 = (LytAnim *)(param_1 + 0x8bc0);
  ad::lyt::LytAnim::init(local_38,pLVar6,"touch","");
  local_5c = (LytAnim *)(param_1 + 0x8ca4);
  ad::lyt::LytAnim::init(local_5c,pLVar6,"ATTENTION","");
  ad::lyt::LytAnim::playAuto(local_5c,1.0);
  ad::lyt::LytLocalize::LytLocalize(aLStack_80);
  ad::lyt::LytLocalize::localize(aLStack_80,pLVar6);
  local_70 = 0;
  local_50 = (Layout *)(param_1 + 0x8c14);
  ad::lyt::LytResourceMan::buildLayout
            ((LytResourceMan *)(param_2 + 2000),local_50,"NUM_G_s.bflyt",(ControlCreator *)0x0,
             (TextSearcher *)0x0);
  local_4c = (LytAnim *)(param_1 + 0x8c50);
  ad::lyt::LytAnim::init(local_4c,local_50,"num_set_U","");
  local_54 = (LytAnim *)(param_1 + 0x8bdc);
  ad::lyt::LytAnim::init(local_54,local_50,"col_02","");
  local_58 = (LytAnim *)(param_1 + 0x8bf8);
  ad::lyt::LytAnim::init(local_58,local_50,"col_s06","");
  local_3c = (LytAnim *)(param_1 + 0x8c6c);
  ad::lyt::LytAnim::init(local_3c,pLVar6,"SET_ICON","");
  local_44 = (LytAnim *)(param_1 + 0x8c88);
  ad::lyt::LytAnim::init(local_44,pLVar6,"SET_BADGE","");
  local_1f0 = (CellAnime *)ad::fw::Resource::getCA_anm(param_5);
  puVar2 = (undefined4 *)ad::fw::Resource::getCA_tex(param_5);
  pvVar3 = (void *)ad::fw::Resource::getCA_canm(param_5);
  CellAnime::init((CellAnime *)(param_1 + 0x8cdc),local_1f0,(void *)*puVar2,pvVar3,'\0',0,1.0);
  param_1[0x8d7f] = (MListWndPBase)((byte)param_1[0x8d7f] | 3);
  param_1[0x8d74] = (MListWndPBase)0x0;
  param_1[0x8d75] = (MListWndPBase)0x0;
  puVar4 = (ushort *)shop::GetBootInfo();
  bVar1 = (&DAT_17016749)[(*puVar4 & 0xffff0fff) * 4];
  *(uint *)(param_1 + 0x8e10) = (uint)bVar1;
  pvVar3 = operator_new__((uint)bVar1 << 2,(MemAlcBase *)(*(int *)(param_1 + 0x8b80) + 0xc),
                          (char *)0x0,0);
  *(void **)(param_1 + 0x8e08) = pvVar3;
  local_bc = param_1 + 0x6f80;
  pMVar5 = local_bc;
  if (param_1 + *(int *)(param_1 + 0x8e10) * 0x1c + 0x6f80 != local_bc) {
    do {
      pMVar5[8] = (MListWndPBase)0xff;
      pMVar5[6] = (MListWndPBase)0xff;
      pMVar5[0xf] = (MListWndPBase)0x0;
      *(undefined4 *)(pMVar5 + 0x14) = 0;
      pMVar5 = pMVar5 + 0x1c;
    } while (param_1 + *(int *)(param_1 + 0x8e10) * 0x1c + 0x6f80 != pMVar5);
  }
  ad::ui::UIListWindowPlusLyt::InitParam::InitParam((InitParam *)local_1f8);
  msys::SetMListWndInitParam(local_1f8,0);
  FUN_1700ba74(auStack_124,param_4);
  local_1f8[0] = param_2 + 0x4af6c;
  local_1f0 = (CellAnime *)(param_1 + 0x8cdc);
  local_1c0 = (**(code **)(**(int **)(param_1 + 0x8b94) + 0x2c))
                        (*(int **)(param_1 + 0x8b94),"FRAME",1);
  local_1c8 = (**(code **)(**(int **)(param_1 + 0x8b94) + 0x2c))
                        (*(int **)(param_1 + 0x8b94),"list_cursor",1);
  local_1cc = (**(code **)(**(int **)(param_1 + 0x8b94) + 0x2c))
                        (*(int **)(param_1 + 0x8b94),"list_scroll",1);
  local_19c = local_38;
  local_1d4 = (**(code **)(**(int **)(param_1 + 0x8b94) + 0x2c))
                        (*(int **)(param_1 + 0x8b94),"SOLDOUT",1);
  local_1b0 = 0;
  local_1e4 = (**(code **)(**(int **)(param_1 + 0x8b94) + 0x2c))
                        (*(int **)(param_1 + 0x8b94),"ICONL",1);
  local_1bc = local_3c;
  local_1e0 = (**(code **)(**(int **)(param_1 + 0x8b94) + 0x2c))
                        (*(int **)(param_1 + 0x8b94),"BADGE",1);
  local_1b8 = local_44;
  local_1d8 = *(undefined4 *)(local_50 + 0x10);
  local_1a8 = local_4c;
  local_1a4 = local_54;
  local_1a0 = local_58;
  local_198 = local_5c;
  msys::MListWndPBase::init
            (param_1,(InitParam *)local_1f8,(LytDrawData *)(param_2 + 0xd3000),
             (Prim *)(param_2 + 0xd3100),(MessageDrawer *)(param_2 + 0x1487c),
             (ApplyingSceneInfo *)(param_2 + 0x4af54));
  *(undefined4 *)(param_1 + 0x13c) = 0x401;
  *(undefined4 *)(param_1 + 0x168) = 0x401;
  return;
}


// FUNC 0x170029a8 shop::MListWndShop::vfunc_0x4 (ShopMenu)
//   size 0x10 | file ShopMenu+0x29a8 | callers(0) | datarefs 1

void shop::MListWndShop::vfunc_0x4(void)

{
  void *pvVar1;
  
  pvVar1 = (void *)vfunc_0x0();
  operator_delete(pvVar1);
  return;
}


// FUNC 0x170029b8 shop::ShopMenuTask::vfunc_0x10 (ShopMenu)
//   size 0x1c | file ShopMenu+0x29b8 | callers(0) | datarefs 1

void shop::ShopMenuTask::vfunc_0x10(TaskMainBase *param_1)

{
  if (*(char *)(*(int *)(param_1 + 0x580) + 0xe9049) == '\0') {
    return;
  }
  GameMain::Back(param_1);
  return;
}


// FUNC 0x170029d4 shop::ShopMenuTask::vfunc_0x8 (ShopMenu)
//   size 0x24 | file ShopMenu+0x29d4 | callers(0) | datarefs 1

void shop::ShopMenuTask::vfunc_0x8(undefined4 *param_1)

{
  int iVar1;
  void *pvVar2;
  
  *param_1 = &vtable;
  iVar1 = ShopMenu::vfunc_0x0(param_1 + 0x161);
  pvVar2 = (void *)ad::fw::TaskBase::~TaskBase((TaskBase *)(iVar1 + -0x584));
  operator_delete(pvVar2);
  return;
}


// FUNC 0x170029fc shop::ShopMenuTask::vfunc_0x4 (ShopMenu)
//   size 0x20 | file ShopMenu+0x29fc | callers(0) | datarefs 1

void shop::ShopMenuTask::vfunc_0x4(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &vtable;
  iVar1 = ShopMenu::vfunc_0x0(param_1 + 0x161);
  ad::fw::TaskBase::~TaskBase((TaskBase *)(iVar1 + -0x584));
  return;
}


// FUNC 0x17002a20 FUN_17002a20 (ShopMenu)
//   size 0x38 | file ShopMenu+0x2a20 | callers(0)

void FUN_17002a20(int *param_1,byte param_2)

{
  int iVar1;
  
  iVar1 = msys::MLyt::getPane((MLyt *)(*param_1 + 0xea3dc),"TOP_HIGE_percent_base",(char *)0x0,
                              (char *)0x0);
  *(byte *)(iVar1 + 0x44) = *(byte *)(iVar1 + 0x44) & 0xfe | param_2;
  return;
}


// FUNC 0x17002a70 FUN_17002a70 (ShopMenu)
//   size 0x178 | file ShopMenu+0x2a70 | callers(1) 0x17012c3c

void FUN_17002a70(int *param_1,int param_2)

{
  ushort *puVar1;
  byte *pbVar2;
  uint uVar3;
  int iVar4;
  bool bVar5;
  float fVar6;
  InitParam aIStack_68 [20];
  uint local_54;
  
  *param_1 = param_2;
  ad::lyt::LytNumReel3::InitParam::InitParam(aIStack_68);
  fVar6 = 0.0;
  puVar1 = (ushort *)shop::GetBootInfo();
  switch((&DAT_1701674b)[(*puVar1 & 0xffff0fff) * 4]) {
  case 4:
  case 5:
  case 6:
    fVar6 = 1.0;
  }
  pbVar2 = (byte *)shop::GetBootInfo();
  uVar3 = (uint)*pbVar2;
  if (8 < uVar3) {
    uVar3 = 9;
  }
  local_54 = DAT_003f9e14 >> ((uVar3 & 0x7f) << 1) & 3;
  bVar5 = local_54 != 0;
  iVar4 = msys::MLyt::getPane((MLyt *)(*param_1 + 0xea3dc),"TOP_HIGE_percent_base",(char *)0x0,
                              (char *)0x0);
  *(byte *)(iVar4 + 0x44) = *(byte *)(iVar4 + 0x44) & 0xfe | bVar5;
  msys::MLytNumRes::set((MLytNumRes *)(param_2 + 0x844),aIStack_68,3,3,0xff);
  msys::MLytNum::init((MLytNum *)(param_1 + 1),aIStack_68,(LytDrawData *)(param_2 + 0xd3000),
                      (MLyt *)(param_2 + 0xea3dc),"LV_NUM","TOP_HIGE_percent_base",(char *)0x0,
                      (char *)0x0);
  msys::MLyt::stopAndSetFrmInst
            ((MLyt *)(param_2 + 0xea3dc),"SET_HIGE_TSUNO",fVar6,"TOP_HIGE_percent_base",(char *)0x0)
  ;
  msys::MLytNum::init((MLytNum *)(param_1 + 0x8d),aIStack_68,(LytDrawData *)(param_2 + 0xd3000),
                      (MLyt *)(param_2 + 0xea034),"LV_NUM","TOP_HIGE_percent_base",(char *)0x0,
                      (char *)0x0);
  msys::MLyt::stopAndSetFrmInst
            ((MLyt *)(param_2 + 0xea034),"SET_HIGE_TSUNO",fVar6,"TOP_HIGE_percent_base",(char *)0x0)
  ;
  return;
}


// FUNC 0x17002c30 FUN_17002c30 (ShopMenu)
//   size 0xa8 | file ShopMenu+0x2c30 | callers(0)

void FUN_17002c30(MMsg *param_1,int param_2,MLyt *param_3)

{
  undefined4 uVar1;
  wchar_t *pwVar2;
  
  *(undefined4 *)(param_1 + 0x6c40) = 0x401;
  *(int *)(param_1 + 0x6c34) = param_2 + 0xc;
  *(undefined4 *)(param_1 + 0x6c38) = 0;
  *(undefined4 *)(param_1 + 0x6c3c) = 0;
  MessageSimple::init((MessageSimple *)(param_1 + 0x14c));
  FUN_1700bd6c(param_1);
  uVar1 = LMS_GetTextIndexByLabel(param_2 + 0xe93ec,"MES_ShopMes_Info_Price");
  pwVar2 = (wchar_t *)LMS_GetText(param_2 + 0xe93ec,uVar1);
  msys::MMsg::playStr(param_1,pwVar2,(InsParam *)0x0,false);
  msys::MLyt::attachMChr
            (param_3,(MChrBase *)param_1,"INS_PRICE_TEXT","lbl_PRICE_ALL",(char *)0x0,(char *)0x0);
  return;
}


// FUNC 0x17002d18 FUN_17002d18 (ShopMenu)
//   size 0x1e0 | file ShopMenu+0x2d18 | callers(1) 0x170045bc

undefined4 FUN_17002d18(int *param_1)

{
  byte bVar1;
  char cVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  float fVar6;
  int iVar7;
  int iVar8;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  bVar1 = *(char *)(*param_1 + 0xeb8dc) - 0x1a;
  *(byte *)(param_1 + 1) = bVar1;
  *(byte *)(param_1[bVar1 + 0x1c99] + 0x44) = *(byte *)(param_1[bVar1 + 0x1c99] + 0x44) & 0xfe;
  iVar7 = *(int *)(param_1[bVar1 + 0x1c99] + 0x54);
  iVar8 = *(int *)(param_1[bVar1 + 0x1c99] + 100);
  MoveVBase::stop((MoveVBase *)(param_1 + 0x35));
  param_1[0x3c] = iVar7;
  param_1[0x3d] = iVar8;
  param_1[0x3e] = 0x43340000;
  param_1[0x36] = iVar7;
  param_1[0x37] = iVar8;
  param_1[0x38] = 0x43340000;
  msys::MDfxChr::playDfx((MDfxChr *)(param_1 + 2),0x34);
  iVar8 = param_1[bVar1 + 0x1c99];
  fVar6 = 0.0;
  iVar7 = param_1[0x1c97];
  uVar3 = *(undefined4 *)(iVar8 + 100);
  uVar5 = *(undefined4 *)(iVar8 + 0x74);
  *(undefined4 *)(iVar7 + 0x1c) = *(undefined4 *)(iVar8 + 0x54);
  *(undefined4 *)(iVar7 + 0x20) = uVar3;
  *(undefined4 *)(iVar7 + 0x24) = uVar5;
  *(byte *)(iVar7 + 0x44) = *(byte *)(iVar7 + 0x44) & 0xef | 0x10;
  *(byte *)(param_1[0x1c97] + 0x44) = *(byte *)(param_1[0x1c97] + 0x44) & 0xfe | 1;
  if (-1 < (char)param_1[1]) {
    cVar2 = *(char *)((int)param_1 + (char)param_1[1] + 0x7229);
    if (cVar2 == '\0') {
      fVar6 = 2.0;
    }
    else {
      if (cVar2 == '\x01') {
        fVar6 = 1.0;
      }
      if ((cVar2 != '\x01' && cVar2 != '\x02') && (cVar2 == '\x03')) {
        fVar6 = 3.0;
      }
    }
  }
  ad::lyt::LytAnim::stopAndSetFrm((LytAnim *)(param_1 + 0x1c90),fVar6);
  iVar7 = (int)(char)param_1[1];
  if ((iVar7 < 0) || (*(char *)((int)param_1 + iVar7 + 0x7229) < '\x03')) {
    if (iVar7 < 0) {
      cVar2 = -1;
    }
    else {
      cVar2 = *(char *)((int)param_1 + iVar7 + 0x7229);
    }
    iVar7 = *(int *)(*param_1 + 0xe904c);
    local_30 = *(undefined4 *)(iVar7 + 0x68);
    local_2c = *(undefined4 *)(iVar7 + 0x6c);
    local_28 = *(undefined4 *)(iVar7 + 0x70);
    uVar4 = (uint)(*(int *)(*param_1 + 0xea030) * (int)*(char *)(&local_30 + cVar2)) / 100;
    if (uVar4 == 0) {
      uVar4 = 1;
    }
    ad::lyt::LytNumReel3::setValueInstant((LytNumReel3 *)(param_1 + 0x1c52),uVar4);
  }
  else {
    ad::lyt::LytNumReel3::setValueInstant((LytNumReel3 *)(param_1 + 0x1c52),0);
  }
  FUN_1700b110(param_1,2);
  *(undefined4 *)(*param_1 + 0xea030) = 0;
  return 0;
}


// FUNC 0x17002f14 FUN_17002f14 (ShopMenu)
//   size 0x234 | file ShopMenu+0x2f14 | callers(1) 0x17003c7c

void FUN_17002f14(int *param_1,int param_2)

{
  MLyt *this;
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  InitParam aIStack_68 [20];
  undefined4 local_54;
  
  *param_1 = param_2;
  *(undefined1 *)(param_1 + 1) = 0xff;
  this = (MLyt *)(param_2 + 0xea3dc);
  *(undefined1 *)(param_1 + 0x1c8a) = 0;
  iVar1 = msys::MLyt::getPane(this,"SCRATCH_SILVER_under",(char *)0x0,(char *)0x0);
  param_1[0x1c97] = iVar1;
  *(byte *)(iVar1 + 0x44) = *(byte *)(iVar1 + 0x44) & 0xfe;
  iVar1 = msys::MLyt::getPane(this,"SCRATCH_HFADE_ALL",(char *)0x0,(char *)0x0);
  param_1[0x1c98] = iVar1;
  ad::lyt::LytAnim::init
            ((LytAnim *)(param_1 + 0x1c90),*(Layout **)(param_2 + 0xea52c),"SET_SCRATCH_PRIZE","");
  param_1[0x1b71] = 0x401;
  param_1[0x1b6e] = param_2 + 0xc;
  param_1[0x1b6f] = 0;
  param_1[0x1b70] = 0;
  MessageSimple::init((MessageSimple *)(param_1 + 0xb4));
  FUN_1700bd6c(param_1 + 0x61);
  *(undefined1 *)(param_1 + 0x1763) = 1;
  msys::MLyt::attachMChr
            ((MLyt *)(*param_1 + 0xea3dc),(MChrBase *)(param_1 + 0x61),"INS_TOP_PANEL_TEXT",
             "SCRATCH_EXP_PNL",(char *)0x0,(char *)0x0);
  ad::lyt::LytNumReel3::InitParam::InitParam(aIStack_68);
  local_54 = 0;
  msys::MLytNumRes::set((MLytNumRes *)(param_2 + 0x844),aIStack_68,0,2,0x11);
  msys::MLytNum::init((MLytNum *)(param_1 + 0x1b72),aIStack_68,(LytDrawData *)(param_2 + 0xd3000),
                      this,"INS_COUNT","SCRATCH_COIN",(char *)0x0,(char *)0x0);
  msys::MLytNum::init((MLytNum *)(param_1 + 0x1bfe),aIStack_68,(LytDrawData *)(param_2 + 0xd3000),
                      this,"INS_COUNT_PLUS","SCRATCH_COIN",(char *)0x0,(char *)0x0);
  iVar1 = 0;
  do {
    iVar2 = msys::MLyt::getPane((MLyt *)(*param_1 + 0xea3dc),(char *)(&DAT_17021d8c)[iVar1],
                                (char *)0x0,(char *)0x0);
    iVar5 = iVar1 + 1;
    param_1[iVar1 + 0x1c99] = iVar2;
    iVar1 = iVar5;
  } while (iVar5 < 0x14);
  msys::MDfxChr::init((MDfxChr *)(param_1 + 2),
                      *(MemAlcBase **)
                       (*(int *)(param_2 + *(char *)((int)*(char *)(param_2 + 0xfd7) +
                                                    param_2 + 0xfcd) * 4 + 0xf8c) + 0x18),
                      *(MDfxSys **)(param_2 + 0xe64f0),(Scene *)(param_2 + 0x4aba4),0x401);
  piVar3 = param_1 + 3;
  param_1[0x51] = 0x401;
  piVar4 = (int *)(param_2 + 0xe64e0);
  piVar6 = (int *)param_1[4];
  *(int **)(*piVar3 + 4) = piVar6;
  *piVar6 = *piVar3;
  if (param_1 + 0x51 != (int *)0x0) {
    iVar1 = *piVar4;
    param_1[4] = (int)piVar4;
    *piVar3 = iVar1;
    *(int **)(iVar1 + 4) = piVar3;
    *piVar4 = (int)piVar3;
  }
  return;
}


// FUNC 0x170031f0 FUN_170031f0 (ShopMenu)
//   size 0x33c | file ShopMenu+0x31f0 | callers(1) 0x17005c08

void FUN_170031f0(int *param_1,char param_2)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  byte *pbVar6;
  byte *pbVar7;
  uint uVar8;
  byte bVar9;
  uint in_fpscr;
  float fVar10;
  undefined4 uVar11;
  uint local_b8 [15];
  byte bStack_79;
  byte local_78 [20];
  LytAnim local_64 [4];
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined2 local_54;
  undefined2 local_52;
  undefined4 local_50;
  undefined4 local_4c;
  RandSys *local_44;
  uint local_3c;
  
  local_3c = (uint)(byte)(param_2 - 1);
  local_b8[1] = 0;
  local_b8[0] = 0;
  local_b8[6] = 0;
  local_b8[2] = 0;
  local_b8[3] = 0;
  local_b8[4] = 0;
  local_b8[5] = 0;
  local_b8[0xb] = 0;
  local_b8[7] = 0;
  local_b8[8] = 0;
  local_b8[9] = 0;
  local_b8[10] = 0;
  *(char *)(param_1 + 0x1c8a) = param_2;
  local_64[0] = (LytAnim)0x0;
  local_60 = 0;
  local_5c = 0x3f800000;
  local_58 = 0;
  local_54 = 1;
  local_52 = 0;
  local_50 = 0;
  local_4c = 0;
  ad::lyt::LytAnim::init(local_64,*(Layout **)(*param_1 + 0xea52c),"SET_SCRATCH_BLOCK","");
  fVar10 = (float)VectorSignedToFloat(*(byte *)(param_1 + 0x1c8a) - 1,(byte)(in_fpscr >> 0x16) & 3);
  ad::lyt::LytAnim::stopAndSetFrm(local_64,fVar10);
  ad::lyt::LytAnim::term(local_64,true);
  local_58 = 0;
  uVar2 = 0;
  do {
    iVar3 = uVar2 + 0x1c99;
    uVar2 = uVar2 + 1 & 0xff;
    *(byte *)(param_1[iVar3] + 0x44) = *(byte *)(param_1[iVar3] + 0x44) & 0xfe | 1;
  } while (uVar2 < 0x14);
  *(undefined1 *)(param_1 + 1) = 0xff;
  iVar3 = *(int *)(*param_1 + 0xe904c);
  local_b8[0] = *(uint *)(iVar3 + 0x44);
  local_b8[1] = *(undefined4 *)(iVar3 + 0x48);
  local_b8[2] = *(undefined4 *)(iVar3 + 0x4c);
  local_b8[3] = *(undefined4 *)(iVar3 + 0x50);
  local_b8[4] = *(undefined4 *)(iVar3 + 0x54);
  local_b8[5] = *(undefined4 *)(iVar3 + 0x58);
  local_b8[6] = *(undefined4 *)(iVar3 + 0x5c);
  local_b8[7] = *(undefined4 *)(iVar3 + 0x60);
  local_b8[8] = *(undefined4 *)(iVar3 + 100);
  iVar3 = (int)param_1 + 0x7229;
  __aeabi_memset(iVar3,0x14,3);
  local_44 = (RandSys *)&gRand;
  uVar4 = local_3c * -5 + 0x14;
  uVar2 = uVar4 & 0xffff;
  if (uVar2 != 0) {
    bVar9 = (uVar4 & 1) != 0;
    pbVar6 = &bStack_79;
    if ((bool)bVar9) {
      local_78[0] = 0;
      pbVar6 = local_78;
    }
    for (uVar4 = uVar2 >> 1; uVar4 != 0; uVar4 = uVar4 - 1 & 0xffff) {
      bVar1 = bVar9 + 1;
      pbVar6[1] = bVar9;
      bVar9 = bVar9 + 2;
      pbVar6 = pbVar6 + 2;
      *pbVar6 = bVar1;
    }
    if (1 < uVar2) {
      uVar4 = RandSys::get(local_44);
      bVar9 = local_78[1];
      pbVar6 = local_78 + ((uVar4 & 0x7fffffff) >> 0xf);
      local_78[1] = *pbVar6;
      *pbVar6 = bVar9;
      uVar11 = *(undefined4 *)local_44;
      uVar4 = 2;
      pbVar6 = local_78 + 2;
      if (2 < uVar2) {
        do {
          uVar8 = uVar4 + 1;
          iVar5 = RandSys::get(local_44);
          bVar9 = *pbVar6;
          uVar4 = uVar8 & 0xffff;
          pbVar7 = local_78 + (iVar5 * (uVar8 & 0xffff) >> 0x10);
          *pbVar6 = *pbVar7;
          *pbVar7 = bVar9;
          pbVar6 = pbVar6 + 1;
        } while (uVar4 < uVar2);
      }
      *(undefined4 *)local_44 = uVar11;
    }
  }
  uVar2 = 0;
  uVar4 = 0;
  uVar8 = local_b8[local_3c * 3];
  if (uVar8 != 0) {
    do {
      pbVar6 = local_78 + uVar2;
      uVar4 = uVar4 + 1 & 0xff;
      uVar2 = uVar2 + 1 & 0xff;
      *(undefined1 *)((uint)*pbVar6 + iVar3) = 0;
    } while (uVar4 < uVar8);
  }
  uVar4 = 0;
  uVar8 = local_b8[local_3c * 3 + 1];
  if (uVar8 != 0) {
    do {
      pbVar6 = local_78 + uVar2;
      uVar4 = uVar4 + 1 & 0xff;
      uVar2 = uVar2 + 1 & 0xff;
      *(undefined1 *)((uint)*pbVar6 + iVar3) = 1;
    } while (uVar4 < uVar8);
  }
  uVar8 = local_b8[local_3c * 3 + 2];
  uVar4 = 0;
  if (uVar8 != 0) {
    do {
      pbVar6 = local_78 + uVar2;
      uVar4 = uVar4 + 1 & 0xff;
      uVar2 = uVar2 + 1 & 0xff;
      *(undefined1 *)((uint)*pbVar6 + iVar3) = 2;
    } while (uVar4 < uVar8);
  }
  iVar3 = GameWork::getCoin((GameWork *)&gGameWork);
  ad::lyt::LytNumReel3::setValueInstant((LytNumReel3 *)(param_1 + 0x1bc6),iVar3);
  return;
}


// FUNC 0x17003554 FUN_17003554 (ShopMenu)
//   size 0xb4 | file ShopMenu+0x3554 | callers(0)

void FUN_17003554(int *param_1,int param_2)

{
  int iVar1;
  wchar_t *pwVar2;
  undefined4 uVar3;
  
  if (param_2 == 0) {
    *(undefined1 *)((int)param_1 + 0x6da5) = 0;
    iVar1 = *param_1;
    uVar3 = LMS_GetTextIndexByLabel(iVar1 + 0xe93ec,"Menu_Sys_invalid_equip_name");
    pwVar2 = (wchar_t *)LMS_GetText(iVar1 + 0xe93ec,uVar3);
    msys::MMsg::playStr((MMsg *)(param_1 + 8),pwVar2,(InsParam *)0x0,false);
    return;
  }
  *(undefined1 *)((int)param_1 + 0x6da5) = 1;
  iVar1 = ad::db::GetItemData((ushort)param_2);
  CellAnime::play((CellAnime *)(param_1 + 0x1b6c),*(char *)(iVar1 + 0x60) + '\x01',0,1.0);
  pwVar2 = (wchar_t *)ad::db::GetItemMsg(param_2,0);
  msys::MMsg::playStr((MMsg *)(param_1 + 8),pwVar2,(InsParam *)0x0,false);
  return;
}


// FUNC 0x17003628 FUN_17003628 (ShopMenu)
//   size 0x124 | file ShopMenu+0x3628 | callers(0)

void FUN_17003628(int *param_1,int param_2,int param_3,Resource *param_4)

{
  MLyt *this;
  int iVar1;
  uint in_fpscr;
  float fVar2;
  
  *param_1 = param_2;
  fVar2 = (float)VectorUnsignedToFloat(param_3,(byte)(in_fpscr >> 0x16) & 3);
  this = (MLyt *)(param_2 + 0xea034);
  msys::MLyt::stopAndSetFrmInst(this,"SET_ICON",fVar2,(char *)(&DAT_17021d74)[param_3],(char *)0x0);
  msys::MCellAnime::init((MCellAnime *)(param_1 + 0x1b19),param_4);
  *(byte *)((int)param_1 + 0x6e53) = *(byte *)((int)param_1 + 0x6e53) | 3;
  msys::MLyt::attachMChr
            (this,(MChrBase *)(param_1 + 0x1b19),"INS_ICON_OBJ",(char *)(&DAT_17021d74)[param_3],
             (char *)0x0,(char *)0x0);
  param_1[0x1b18] = 0x400;
  param_1[0x1b15] = param_2 + 0xc;
  param_1[0x1b16] = 0;
  param_1[0x1b17] = 0;
  MessageSimple::init((MessageSimple *)(param_1 + 0x5b));
  FUN_1700bd6c(param_1 + 8);
  MessageWriter::setFontColor((MessageWriter *)(param_1 + 0x5b),0xe6e6e6ff,true);
  msys::MLyt::attachMChr
            (this,(MChrBase *)(param_1 + 8),"list_text_top",(char *)(&DAT_17021d74)[param_3],
             (char *)0x0,(char *)0x0);
  iVar1 = msys::MLyt::getParts(this,(char *)(&DAT_17021d74)[param_3],(char *)0x0,(char *)0x0);
  ad::lyt::LytAnim::init((LytAnim *)(param_1 + 1),*(Layout **)(iVar1 + 0xac),"SET_COL","");
  return;
}


// FUNC 0x17003878 FUN_17003878 (ShopMenu)
//   size 0x328 | file ShopMenu+0x3878 | callers(1) 0x17012c3c

void FUN_17003878(MListWndPBase *param_1,int param_2,LytResourceMan *param_3,undefined4 param_4,
                 Resource *param_5)

{
  undefined4 *puVar1;
  void *pvVar2;
  MListWndPBase *pMVar3;
  Layout *pLVar4;
  void *local_1e0 [2];
  CellAnime *local_1d8;
  undefined4 local_1cc;
  undefined4 local_1c0;
  undefined4 local_1b4;
  undefined4 local_1b0;
  undefined4 local_1a8;
  LytAnim *local_1a4;
  LytAnim *local_190;
  LytAnim *local_18c;
  LytAnim *local_188;
  LytAnim *local_184;
  LytAnim *local_180;
  undefined1 auStack_10c [104];
  MListWndPBase *local_a4;
  LytAnim *local_68;
  LytAnim *local_64;
  LytLocalize aLStack_60 [16];
  undefined4 local_50;
  LytAnim *local_40;
  Layout *local_3c;
  LytAnim *local_38;
  LytAnim *local_34;
  LytAnim *local_30;
  
  *(int *)(param_1 + 0x8b80) = param_2;
  *(undefined4 *)(param_1 + 0x8dec) = param_4;
  pLVar4 = (Layout *)(param_1 + 0x8b84);
  ad::lyt::LytResourceMan::buildLayout
            (param_3,pLVar4,"SHOP_L_LIST_SELL.bflyt",(ControlCreator *)0x0,(TextSearcher *)0x0);
  local_30 = (LytAnim *)(param_1 + 0x8bc0);
  ad::lyt::LytAnim::init(local_30,pLVar4,"touch","");
  local_68 = (LytAnim *)(param_1 + 0x8c88);
  ad::lyt::LytAnim::init(local_68,pLVar4,"ATTENTION","");
  ad::lyt::LytAnim::playAuto(local_68,1.0);
  ad::lyt::LytLocalize::LytLocalize(aLStack_60);
  ad::lyt::LytLocalize::localize(aLStack_60,pLVar4);
  local_50 = 0;
  local_3c = (Layout *)(param_1 + 0x8c14);
  ad::lyt::LytResourceMan::buildLayout
            ((LytResourceMan *)(param_2 + 2000),local_3c,"NUM_G_s.bflyt",(ControlCreator *)0x0,
             (TextSearcher *)0x0);
  local_38 = (LytAnim *)(param_1 + 0x8c50);
  ad::lyt::LytAnim::init(local_38,local_3c,"num_set_U","");
  local_40 = (LytAnim *)(param_1 + 0x8bdc);
  ad::lyt::LytAnim::init(local_40,local_3c,"col_02","");
  local_64 = (LytAnim *)(param_1 + 0x8bf8);
  ad::lyt::LytAnim::init(local_64,local_3c,"col_s06","");
  local_34 = (LytAnim *)(param_1 + 0x8c6c);
  ad::lyt::LytAnim::init(local_34,pLVar4,"SET_ICON","");
  local_1e0[0] = (void *)ad::fw::Resource::getCA_anm(param_5);
  puVar1 = (undefined4 *)ad::fw::Resource::getCA_tex(param_5);
  pvVar2 = (void *)ad::fw::Resource::getCA_canm(param_5);
  CellAnime::init((CellAnime *)(param_1 + 0x8cc0),local_1e0[0],(void *)*puVar1,pvVar2,'\0',0,1.0);
  param_1[0x8d63] = (MListWndPBase)((byte)param_1[0x8d63] | 3);
  param_1[0x8d58] = (MListWndPBase)0x0;
  param_1[0x8d59] = (MListWndPBase)0x0;
  *(undefined4 *)(param_1 + 0x8df0) = 0x100;
  local_a4 = param_1 + 0x6f80;
  pMVar3 = local_a4;
  if (param_1 + 0x8b80 != local_a4) {
    do {
      pMVar3[8] = (MListWndPBase)0xff;
      pMVar3[6] = (MListWndPBase)0xff;
      pMVar3[0xf] = (MListWndPBase)0x0;
      *(undefined4 *)(pMVar3 + 0x14) = 0;
      pMVar3 = pMVar3 + 0x1c;
    } while (param_1 + *(int *)(param_1 + 0x8df0) * 0x1c + 0x6f80 != pMVar3);
  }
  ad::ui::UIListWindowPlusLyt::InitParam::InitParam((InitParam *)local_1e0);
  msys::SetMListWndInitParam(local_1e0,0);
  FUN_1700ba74(auStack_10c,param_4);
  local_1e0[0] = (void *)(param_2 + 0x4af6c);
  local_1d8 = (CellAnime *)(param_1 + 0x8cc0);
  local_1a8 = (**(code **)(**(int **)(param_1 + 0x8b94) + 0x2c))
                        (*(int **)(param_1 + 0x8b94),"FRAME",1);
  local_1b0 = (**(code **)(**(int **)(param_1 + 0x8b94) + 0x2c))
                        (*(int **)(param_1 + 0x8b94),"list_cursor",1);
  local_1b4 = (**(code **)(**(int **)(param_1 + 0x8b94) + 0x2c))
                        (*(int **)(param_1 + 0x8b94),"list_scroll",1);
  local_184 = local_30;
  local_1cc = (**(code **)(**(int **)(param_1 + 0x8b94) + 0x2c))
                        (*(int **)(param_1 + 0x8b94),"ICONL",1);
  local_1a4 = local_34;
  local_1c0 = *(undefined4 *)(local_3c + 0x10);
  local_190 = local_38;
  local_18c = local_40;
  local_188 = local_64;
  local_180 = local_68;
  msys::MListWndPBase::init
            (param_1,(InitParam *)local_1e0,(LytDrawData *)(param_2 + 0xd3000),
             (Prim *)(param_2 + 0xd3100),(MessageDrawer *)(param_2 + 0x1487c),
             (ApplyingSceneInfo *)(param_2 + 0x4af54));
  *(undefined4 *)(param_1 + 0x13c) = 0x401;
  *(undefined4 *)(param_1 + 0x168) = 0x401;
  return;
}


// FUNC 0x17003c40 shop::MListWndShopSell::vfunc_0x4 (ShopMenu)
//   size 0x10 | file ShopMenu+0x3c40 | callers(0) | datarefs 1

void shop::MListWndShopSell::vfunc_0x4(void)

{
  void *pvVar1;
  
  pvVar1 = (void *)vfunc_0x0();
  operator_delete(pvVar1);
  return;
}


// FUNC 0x17003c7c FUN_17003c7c (ShopMenu)
//   size 0x29c | file ShopMenu+0x3c7c | callers(0)

void FUN_17003c7c(int param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  MDfxSys *pMVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  void *pvVar9;
  int *piVar10;
  
  iVar5 = msys::MComSys::_sys;
  uVar7 = *(undefined4 *)(*(int *)(param_1 + 4) + 0x18);
  iVar4 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar4 = iVar5;
  }
  pvVar9 = *(void **)(iVar4 + 0xe93e0);
  *(undefined4 *)(param_1 + 0xe684) = 0x400;
  *(undefined4 *)(param_1 + 0xe640) = 0x400;
  *(undefined4 *)(param_1 + 0xe67c) = uVar7;
  *(undefined4 *)(param_1 + 0xe680) = 0;
  *(undefined4 *)(param_1 + 0xe644) = 0;
  *(undefined4 *)(param_1 + 0xe648) = 0;
  *(undefined1 *)(param_1 + 0xe668) = 1;
  *(undefined1 *)(param_1 + 0xe669) = 0;
  *(undefined4 *)(param_1 + 0xe670) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xe674) = 0xffffffff;
  *(int *)(param_1 + 0xe660) = param_1 + 59000;
  *(undefined4 *)(param_1 + 0xe664) = 0;
  Message::init((Message *)(param_1 + 0x78dc));
  Message::setMsgDat((Message *)(param_1 + 0x78dc),pvVar9);
  FUN_1700bd6c(param_1 + 0x7790);
  MoveVBase::stop((MoveVBase *)(param_1 + 0x785c));
  *(undefined4 *)(param_1 + 0x7878) = 0;
  *(undefined4 *)(param_1 + 0x787c) = 0;
  *(undefined4 *)(param_1 + 0x7880) = 0xc347cccd;
  *(undefined4 *)(param_1 + 0x7860) = *(undefined4 *)(param_1 + 0x7878);
  *(undefined4 *)(param_1 + 0x7864) = 0;
  *(undefined4 *)(param_1 + 0x7868) = 0xc347cccd;
  piVar3 = (int *)(*(int *)(param_1 + 4) + 4);
  puVar8 = *(undefined4 **)(param_1 + 0x7798);
  *(undefined4 **)(*(int *)(param_1 + 0x7794) + 4) = puVar8;
  *puVar8 = *(undefined4 *)(param_1 + 0x7794);
  piVar2 = (int *)(param_1 + 0x7794);
  if (piVar2 != (int *)0x0) {
    iVar4 = *piVar3;
    *(int **)(param_1 + 0x7798) = piVar3;
    *piVar2 = iVar4;
    *(int **)(iVar4 + 4) = piVar2;
    *piVar3 = (int)piVar2;
  }
  *(undefined4 *)(param_1 + 0x78cc) = 0x400;
  iVar5 = msys::MComSys::_sys;
  iVar4 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar4 = iVar5;
  }
  FUN_17002f14(param_1 + 0x334,iVar4);
  iVar5 = msys::MComSys::_sys;
  iVar4 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar4 = iVar5;
  }
  uVar7 = msys::MLyt::getPane((MLyt *)(iVar4 + 0xea034),"BLOCK_13",(char *)0x0,(char *)0x0);
  *(undefined4 *)(param_1 + 0x7788) = uVar7;
  msys::MDfxChr::init((MDfxChr *)(param_1 + 0x75f0),
                      *(MemAlcBase **)
                       (*(int *)(iVar4 + *(char *)((int)*(char *)(iVar4 + 0xfd7) + iVar4 + 0xfcd) *
                                         4 + 0xf8c) + 0x18),*(MDfxSys **)(iVar4 + 0xe64f0),
                      (Scene *)(iVar4 + 0x4aba4),0x400);
  piVar2 = (int *)(param_1 + 0x75f4);
  *(undefined4 *)(param_1 + 0x772c) = 0x400;
  piVar10 = *(int **)(param_1 + 0x75f8);
  piVar3 = (int *)(iVar4 + 0xe64d8);
  *(int **)(*piVar2 + 4) = piVar10;
  *piVar10 = *piVar2;
  if ((undefined4 *)(param_1 + 0x772c) != (undefined4 *)0x0) {
    iVar5 = *piVar3;
    *(int **)(param_1 + 0x75f8) = piVar3;
    *piVar2 = iVar5;
    *(int **)(iVar5 + 4) = piVar2;
    *piVar3 = (int)piVar2;
  }
  *(int *)(param_1 + 0x75e8) = iVar4;
  *(undefined1 *)(param_1 + 0x75ec) = 0xff;
  iVar5 = msys::MComSys::_sys;
  iVar4 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar4 = iVar5;
  }
  iVar1 = msys::MComSys::_sys;
  iVar5 = iVar4;
  if (iVar4 == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar5 = iVar1;
  }
  iVar1 = msys::MComSys::_sys;
  pMVar6 = *(MDfxSys **)(iVar5 + 0xe64f0);
  if (iVar5 == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar5 = iVar1;
  }
  msys::MDfxChr::init((MDfxChr *)(param_1 + 0xe710),(MemAlcBase *)(iVar5 + 0xc),pMVar6,
                      (Scene *)(iVar4 + 0x4aba4),0x401);
  piVar3 = (int *)(*(int *)(param_1 + 4) + 0xc);
  puVar8 = *(undefined4 **)(param_1 + 0xe718);
  *(undefined4 **)(*(int *)(param_1 + 0xe714) + 4) = puVar8;
  *puVar8 = *(undefined4 *)(param_1 + 0xe714);
  piVar2 = (int *)(param_1 + 0xe714);
  if (piVar2 != (int *)0x0) {
    iVar4 = *piVar3;
    *(int **)(param_1 + 0xe718) = piVar3;
    *piVar2 = iVar4;
    *(int **)(iVar4 + 4) = piVar2;
    *piVar3 = (int)piVar2;
  }
  *(undefined4 *)(param_1 + 0xe84c) = 0x401;
  *(undefined1 **)(param_1 + 0x10) = &LAB_17005004;
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}


// FUNC 0x17003f40 FUN_17003f40 (ShopMenu)
//   size 0x1a4 | file ShopMenu+0x3f40 | callers(0) | datarefs 4

void FUN_17003f40(int param_1,uint *param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  uVar2 = *param_2;
  if ((uVar2 & 0x401) == 0) {
    if ((uVar2 & 0x20) == 0) {
      if ((uVar2 & 0x10) == 0) {
        if ((uVar2 & 0x802) != 0) {
          (**(code **)(**(int **)(param_1 + 0x78) + 0x10))();
          (**(code **)(**(int **)(param_1 + 0x78) + 0xc))();
          iVar4 = msys::MComSys::_sys;
          iVar3 = *(int *)(param_1 + 8);
          if (*(int *)(param_1 + 8) == 0) {
            *(int *)(param_1 + 8) = msys::MComSys::_sys;
            iVar3 = iVar4;
          }
          *(undefined1 *)(iVar3 + 0xe6508) = 0;
        }
        goto LAB_170040d8;
      }
      cVar1 = *(char *)(*(int *)(param_1 + 0x58) + 0x18);
      *(short *)(param_1 + *(short *)(param_1 + 0x7e) * 2 + 0x90) = (short)cVar1;
      iVar4 = cVar1 + 1;
      *(short *)(param_1 + *(short *)(param_1 + 0x7e) * 2 + 0x90) = (short)iVar4;
      iVar3 = param_1 + *(short *)(param_1 + 0x7e) * 2;
      if ((int)*(short *)(iVar3 + 0x88) + (int)*(short *)(iVar3 + 0x80) <= iVar4) {
        *(short *)(iVar3 + 0x90) = *(short *)(iVar3 + 0x80);
      }
    }
    else {
      cVar1 = *(char *)(*(int *)(param_1 + 0x58) + 0x18);
      *(short *)(param_1 + *(short *)(param_1 + 0x7e) * 2 + 0x90) = (short)cVar1;
      iVar4 = cVar1 + -1;
      *(short *)(param_1 + *(short *)(param_1 + 0x7e) * 2 + 0x90) = (short)iVar4;
      iVar3 = param_1 + *(short *)(param_1 + 0x7e) * 2;
      if (iVar4 < *(short *)(iVar3 + 0x80)) {
        *(short *)(iVar3 + 0x90) = *(short *)(iVar3 + 0x88) + *(short *)(iVar3 + 0x80) + -1;
      }
    }
    FUN_1700beb8(msys::MComSys::_sys + 0x49368,0x110015,0,0,0);
    *(undefined1 *)(*(int *)(param_1 + 0x58) + 0x18) =
         *(undefined1 *)(param_1 + *(short *)(param_1 + 0x7e) * 2 + 0x90);
  }
  else {
    (**(code **)(**(int **)(param_1 + *(char *)(*(int *)(param_1 + 0x58) + 0x18) * 4 + 0xe88c) +
                0x10))();
    iVar4 = msys::MComSys::_sys;
    iVar3 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar3 = iVar4;
    }
    *(undefined1 *)(iVar3 + 0xe6508) = 0;
    iVar4 = msys::MComSys::_sys;
    iVar3 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar3 = iVar4;
    }
    *(undefined1 *)(iVar3 + 0xe650a) = 1;
  }
LAB_170040d8:
  FUN_1700ad98(*(undefined4 *)(param_1 + 0x58));
  return;
}


// FUNC 0x17004100 FUN_17004100 (ShopMenu)
//   size 0x2cc | file ShopMenu+0x4100 | callers(0)

void FUN_17004100(int param_1,int param_2,int param_3)

{
  byte bVar1;
  short sVar2;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  
  bVar1 = *(byte *)(param_2 + 0x48);
  if (param_3 != 1) {
    if (param_3 != 4) {
      if (param_3 != 5) {
        return;
      }
      msys::MCursorBase::setVisible(*(MCursorBase **)(param_1 + 0x58),false);
      iVar4 = msys::MComSys::_sys;
      switch((uint)bVar1) {
      case 0:
      case 1:
      case 3:
      case 5:
      case 7:
      case 8:
      case 10:
      case 0xc:
      case 0xf:
      case 0x10:
      case 0x11:
      case 0x12:
        if (*(int *)(param_1 + 8) == 0) {
          *(int *)(param_1 + 8) = msys::MComSys::_sys;
        }
        else {
          iVar4 = *(int *)(param_1 + 8);
        }
        break;
      case 2:
      case 4:
      case 6:
      case 9:
      case 0xb:
      case 0xe:
        FUN_1700a944(param_1,7);
        msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x44),0xb,0,(char *)0x0,(char *)0x0);
        msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x48),10,0,(char *)0x0,(char *)0x0);
        *(code **)(param_1 + 0x20) = FUN_17005478;
        *(undefined4 *)(param_1 + 0x24) = 0;
        return;
      case 0xd:
        FUN_1700a944(param_1,5);
        msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x44),8,0,(char *)0x0,(char *)0x0);
        msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x48),9,0,(char *)0x0,(char *)0x0);
        *(code **)(param_1 + 0x20) = FUN_17005478;
        *(undefined4 *)(param_1 + 0x24) = 0;
        return;
      default:
        goto switchD_1700413c_default;
      }
      Mem::Copy((void *)(iVar4 + 0xea028),(void *)(param_1 + 0x90),6);
      iVar4 = msys::MComSys::_sys;
      switch(*(undefined2 *)(param_1 + *(short *)(param_1 + 0x7e) * 2 + 0x90)) {
      case 0:
      case 1:
      case 7:
      case 8:
      case 0xf:
      case 0x10:
        sVar2 = *(short *)(param_1 + *(short *)(param_1 + 0x7e) * 2 + 0x90);
        iVar5 = *(int *)(param_1 + 8);
        if ((sVar2 == 7 || sVar2 == 0) || sVar2 == 0xf) {
          if (iVar5 == 0) {
            *(int *)(param_1 + 8) = msys::MComSys::_sys;
            iVar5 = iVar4;
          }
          uVar3 = 0;
        }
        else {
          if (iVar5 == 0) {
            *(int *)(param_1 + 8) = msys::MComSys::_sys;
            iVar5 = iVar4;
          }
          uVar3 = 1;
        }
        *(undefined1 *)(iVar5 + 0xea02e) = uVar3;
        uVar3 = 1;
        break;
      default:
        return;
      case 3:
      case 10:
      case 0xc:
        uVar3 = 2;
        break;
      case 5:
        uVar3 = 3;
        break;
      case 0x11:
      case 0x12:
        sVar2 = *(short *)(param_1 + *(short *)(param_1 + 0x7e) * 2 + 0x90);
        if (sVar2 == 0x12) {
          iVar5 = *(int *)(param_1 + 8);
          if (*(int *)(param_1 + 8) == 0) {
            *(int *)(param_1 + 8) = msys::MComSys::_sys;
            iVar5 = iVar4;
          }
          uVar3 = 1;
LAB_17007748:
          *(undefined1 *)(iVar5 + 0xea02e) = uVar3;
        }
        else if (sVar2 == 0x11) {
          iVar5 = *(int *)(param_1 + 8);
          if (*(int *)(param_1 + 8) == 0) {
            *(int *)(param_1 + 8) = msys::MComSys::_sys;
            iVar5 = iVar4;
          }
          uVar3 = 0;
          goto LAB_17007748;
        }
        uVar3 = 4;
      }
      *(undefined1 *)(param_1 + 0x7d) = uVar3;
      return;
    }
    FUN_1700beb8(msys::MComSys::_sys + 0x49368,0x110016,0,0,0);
    iVar5 = msys::MComSys::_sys;
    iVar4 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar4 = iVar5;
    }
    *(undefined1 *)(iVar4 + 0xe6508) = 0;
    iVar5 = msys::MComSys::_sys;
    iVar4 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar4 = iVar5;
    }
    *(undefined1 *)(iVar4 + 0xe650a) = 1;
  }
  *(ushort *)(param_1 + *(short *)(param_1 + 0x7e) * 2 + 0x90) = (ushort)bVar1;
  if ((uint)bVar1 != (int)*(char *)(*(int *)(param_1 + 0x58) + 0x18)) {
    FUN_1700beb8(msys::MComSys::_sys + 0x49368,0x110015,0,0,0);
  }
  *(undefined1 *)(*(int *)(param_1 + 0x58) + 0x18) =
       *(undefined1 *)(param_1 + *(short *)(param_1 + 0x7e) * 2 + 0x90);
  msys::MCursorBase::setVisible(*(MCursorBase **)(param_1 + 0x58),true);
  FUN_1700ad98(*(undefined4 *)(param_1 + 0x58));
switchD_1700413c_default:
  return;
}


// FUNC 0x17004310 FUN_17004310 (ShopMenu)
//   size 0x50 | file ShopMenu+0x4310 | callers(0) | datarefs 2

void FUN_17004310(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = msys::MLyt::isEnableAnime(*(MLyt **)(param_1 + 0x44));
  if ((iVar1 == 0) &&
     (iVar2 = msys::MLyt::isEnableAnime(*(MLyt **)(param_1 + 0x48)), iVar1 = msys::MComSys::_sys,
     iVar2 == 0)) {
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar1;
    }
    *(undefined1 *)(iVar2 + 0xe9049) = 1;
  }
  return;
}


// FUNC 0x17004370 FUN_17004370 (ShopMenu)
//   size 0x228 | file ShopMenu+0x4370 | callers(0)

void FUN_17004370(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  code *pcVar3;
  int iVar4;
  
  iVar2 = msys::MComSys::_sys;
  cVar1 = *(char *)(param_2 + 0x48);
  if (param_3 == 1) {
LAB_17004448:
    if (*(char *)(*(int *)(param_1 + 0x58) + 0x18) != (char)(cVar1 + '\x18')) {
      *(char *)(*(int *)(param_1 + 0x58) + 0x18) = cVar1 + '\x18';
      msys::MCursorBase::setVisible(*(MCursorBase **)(param_1 + 0x58),true);
      FUN_1700ad98(*(undefined4 *)(param_1 + 0x58));
      FUN_1700beb8(msys::MComSys::_sys + 0x49368,0x110015,0,0,0);
    }
    return;
  }
  if (param_3 == 4) {
    FUN_1700beb8(msys::MComSys::_sys + 0x49368,0x110016,0,0,0);
    iVar4 = msys::MComSys::_sys;
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar4;
    }
    *(undefined1 *)(iVar2 + 0xe6508) = 0;
    iVar4 = msys::MComSys::_sys;
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar4;
    }
    *(undefined1 *)(iVar2 + 0xe650a) = 1;
    goto LAB_17004448;
  }
  if (param_3 != 5) {
    return;
  }
  if (cVar1 == '\0') {
    msys::MLyt::setAnimeInfo(*(MLyt **)(param_1 + 0x44),0x13,0xffffffff);
    msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x44),0x13,0,(char *)0x0,(char *)0x0);
    msys::MLyt::setAnimeInfo(*(MLyt **)(param_1 + 0x48),0x14,0xffffffff);
    msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x48),0x14,0,(char *)0x0,(char *)0x0);
    msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x48),0x1b,1,"SCRATCH_EXP_PNL",(char *)0x0);
    pcVar3 = FUN_17007104;
  }
  else {
    if (cVar1 != '\x01') {
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
      }
      *(undefined1 *)(*(int *)(param_1 + 8) + 0xe6508) = 1;
      iVar4 = *(int *)(param_1 + 8);
      if (iVar4 == 0) {
        *(int *)(param_1 + 8) = iVar2;
        iVar4 = iVar2;
      }
      *(undefined1 *)(iVar4 + 0xe650a) = 1;
      goto LAB_17004588;
    }
    *(undefined4 *)(*(int *)(param_1 + 8) + 0xea030) = 0;
    msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x44),0x12,1,(char *)0x0,(char *)0x0);
    msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x48),0x13,1,(char *)0x0,(char *)0x0);
    msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x48),0x1b,1,"SCRATCH_EXP_PNL",(char *)0x0);
    *(undefined1 *)(param_1 + 0x5f9) = 0;
    FUN_1700a944(param_1,*(undefined1 *)(param_1 + 0xa8));
    pcVar3 = FUN_17005478;
  }
  *(code **)(param_1 + 0x20) = pcVar3;
  *(undefined4 *)(param_1 + 0x24) = 0;
LAB_17004588:
  msys::MCursorBase::setVisible(*(MCursorBase **)(param_1 + 0x58),false);
  return;
}


// FUNC 0x170045bc FUN_170045bc (ShopMenu)
//   size 0x114 | file ShopMenu+0x45bc | callers(0)

void FUN_170045bc(int param_1,int param_2,int param_3)

{
  int iVar1;
  char cVar2;
  int iVar3;
  
  iVar1 = msys::MComSys::_sys;
  cVar2 = *(char *)(param_2 + 0x48);
  if (param_3 != 1) {
    if (param_3 != 4) {
      if (param_3 == 5) {
        FUN_1700beb8(msys::MComSys::_sys + 0x49368,0x110022,0,0,0);
        FUN_17002d18(param_1 + 0x334);
        msys::MCursorBase::setVisible(*(MCursorBase **)(param_1 + 0x58),false);
        FUN_1700ad98(*(undefined4 *)(param_1 + 0x58));
        Frm::play((Frm *)(param_1 + 0x98),30.0);
        *(code **)(param_1 + 0x20) = FUN_17007210;
        *(undefined4 *)(param_1 + 0x24) = 0;
        msys::MCursorBase::setVisible(*(MCursorBase **)(param_1 + 0x58),false);
        return;
      }
      return;
    }
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
    }
    *(undefined1 *)(*(int *)(param_1 + 8) + 0xe6508) = 0;
    iVar3 = *(int *)(param_1 + 8);
    if (iVar3 == 0) {
      *(int *)(param_1 + 8) = iVar1;
      iVar3 = iVar1;
    }
    *(undefined1 *)(iVar3 + 0xe650a) = 1;
  }
  cVar2 = cVar2 + '\x1a';
  if (*(char *)(*(int *)(param_1 + 0x58) + 0x18) != cVar2) {
    *(char *)(*(int *)(param_1 + 0x58) + 0x18) = cVar2;
    FUN_1700ad98(*(undefined4 *)(param_1 + 0x58));
    FUN_1700beb8(msys::MComSys::_sys + 0x49368,0x110015,0,0,0);
  }
  return;
}


// FUNC 0x17004e08 shop::ShopMenu_TopPage::Core::vfunc_0x10 (ShopMenu)
//   size 0x184 | file ShopMenu+0x4e08 | callers(0) | datarefs 1

void shop::ShopMenu_TopPage::Core::vfunc_0x10(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  iVar2 = msys::MComSys::_sys;
  cVar1 = *(char *)(*(int *)(param_1 + 0x78) + 0x48);
  if (param_2 == 4) {
    FUN_1700beb8(msys::MComSys::_sys + 0x49368,0x110017,0,0,0);
    iVar3 = msys::MComSys::_sys;
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar3;
    }
    *(undefined1 *)(iVar2 + 0xe6508) = 0;
    iVar3 = msys::MComSys::_sys;
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar3;
    }
    *(undefined1 *)(iVar2 + 0xe650a) = 1;
  }
  else if (param_2 == 5) {
    if (cVar1 == '\0') {
      FUN_170074f8(param_1);
    }
    else if (cVar1 == '\x01' || cVar1 == '\x02') {
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
      }
      else {
        iVar2 = *(int *)(param_1 + 8);
      }
      *(undefined1 *)(iVar2 + 0xe6508) = 0;
      msys::MCursorBase::setVisible(*(MCursorBase **)(param_1 + 0x58),false);
      FUN_1700ad98(*(undefined4 *)(param_1 + 0x58));
      if (*(short *)(param_1 + 0x90) == 0xd) {
        uVar4 = 8;
        uVar5 = 9;
      }
      else {
        uVar4 = 0xb;
        uVar5 = 10;
      }
      msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x44),uVar4,1,(char *)0x0,(char *)0x0);
      msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x48),uVar5,1,(char *)0x0,(char *)0x0);
      *(code **)(param_1 + 0x20) = FUN_1700501c;
      *(undefined4 *)(param_1 + 0x24) = 0;
    }
    else {
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
      }
      *(undefined1 *)(*(int *)(param_1 + 8) + 0xe6508) = 1;
      iVar3 = *(int *)(param_1 + 8);
      if (iVar3 == 0) {
        *(int *)(param_1 + 8) = iVar2;
        iVar3 = iVar2;
      }
      *(undefined1 *)(iVar3 + 0xe650a) = 1;
    }
    msys::MCursorBase::setVisible(*(MCursorBase **)(param_1 + 0x58),false);
    FUN_1700ad98(*(undefined4 *)(param_1 + 0x58));
    return;
  }
  return;
}


// FUNC 0x17004f98 FUN_17004f98 (ShopMenu)
//   size 0x64 | file ShopMenu+0x4f98 | callers(0) | datarefs 2

void FUN_17004f98(int param_1)

{
  MComSys *pMVar1;
  int iVar2;
  MComSys *this;
  
  iVar2 = msys::MLyt::isEnableAnime(*(MLyt **)(param_1 + 0x44));
  if ((iVar2 == 0) &&
     (iVar2 = msys::MLyt::isEnableAnime(*(MLyt **)(param_1 + 0x48)), pMVar1 = msys::MComSys::_sys,
     iVar2 == 0)) {
    this = *(MComSys **)(param_1 + 8);
    if (*(MComSys **)(param_1 + 8) == (MComSys *)0x0) {
      *(MComSys **)(param_1 + 8) = msys::MComSys::_sys;
      this = pMVar1;
    }
    iVar2 = msys::MComSys::getNextPage(this);
    if (*(char *)(iVar2 + 0x14) != '\0') {
      *(undefined1 **)(param_1 + 0x18) = &LAB_170074cc;
      *(undefined4 *)(param_1 + 0x1c) = 0;
    }
  }
  return;
}


// FUNC 0x1700501c FUN_1700501c (ShopMenu)
//   size 0xf8 | file ShopMenu+0x501c | callers(0) | datarefs 1

void FUN_1700501c(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_r5;
  
  iVar1 = msys::MLyt::isEnableAnime(*(MLyt **)(param_1 + 0x48));
  if ((iVar1 == 0) && (iVar1 = msys::MLyt::isEnableAnime(*(MLyt **)(param_1 + 0x44)), iVar1 == 0)) {
    switch(*(undefined2 *)(param_1 + 0x90)) {
    case 2:
      unaff_r5 = 0;
      break;
    case 4:
      unaff_r5 = 1;
      break;
    case 6:
      unaff_r5 = 2;
      break;
    case 9:
      unaff_r5 = 3;
      break;
    case 0xb:
      unaff_r5 = 6;
      break;
    case 0xd:
    case 0xe:
      unaff_r5 = 4;
    }
    FUN_1700a944(param_1,unaff_r5);
    *(undefined1 *)(*(int *)(param_1 + 0x58) + 0x18) =
         *(undefined1 *)(param_1 + *(short *)(param_1 + 0x7e) * 2 + 0x90);
    msys::MCursorBase::setVisible(*(MCursorBase **)(param_1 + 0x58),true);
    FUN_1700ad98(*(undefined4 *)(param_1 + 0x58));
    iVar1 = msys::MComSys::_sys;
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar1;
    }
    *(undefined1 *)(iVar2 + 0xe6508) = 1;
    iVar1 = msys::MComSys::_sys;
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar1;
    }
    *(undefined1 *)(iVar2 + 0xe650a) = 1;
    *(code **)(param_1 + 0x20) = FUN_17003f40;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x17005150 FUN_17005150 (ShopMenu)
//   size 0x70 | file ShopMenu+0x5150 | callers(0) | datarefs 1

void FUN_17005150(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_1700a550();
  if (iVar1 == 0) {
    FUN_1700a4cc(param_1,3);
    msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x44),0x17,0,(char *)0x0,(char *)0x0);
    msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x48),0x1a,0,(char *)0x0,(char *)0x0);
    Frm::play((Frm *)(param_1 + 0x98),30.0);
    *(code **)(param_1 + 0x20) = FUN_170058bc;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x170051c8 FUN_170051c8 (ShopMenu)
//   size 0xc8 | file ShopMenu+0x51c8 | callers(0) | datarefs 2

void FUN_170051c8(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  code *pcVar4;
  undefined4 unaff_r5;
  float fVar5;
  
  iVar2 = msys::MLyt::isEnableAnime(*(MLyt **)(param_1 + 0x44));
  if ((iVar2 == 0) &&
     (iVar3 = msys::MLyt::isEnableAnime(*(MLyt **)(param_1 + 0x48)), iVar2 = msys::MComSys::_sys,
     iVar3 == 0)) {
    iVar3 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar3 = iVar2;
    }
    iVar2 = ad::fw::TaskBase::isFps30(*(TaskBase **)(iVar3 + 4));
    if (iVar2 == 0) {
      fVar5 = 1.0;
    }
    else {
      fVar5 = 2.0;
    }
    iVar2 = Frm::update(fVar5);
    if (iVar2 == 0) {
      FUN_1700a4cc(param_1,2);
      cVar1 = *(char *)(param_1 + 0xa9);
      if (cVar1 == '\x01') {
        FUN_1700a5b0(param_1,10);
        pcVar4 = FUN_17005d74;
      }
      else {
        if (cVar1 == '\x02') {
          unaff_r5 = 0xc;
        }
        else if (cVar1 == '\x03') {
          unaff_r5 = 0xe;
        }
        FUN_1700a5b0(param_1,unaff_r5);
        pcVar4 = FUN_170052a0;
      }
      *(code **)(param_1 + 0x20) = pcVar4;
      *(undefined4 *)(param_1 + 0x24) = 0;
    }
  }
  return;
}


// FUNC 0x170052a0 FUN_170052a0 (ShopMenu)
//   size 0x30 | file ShopMenu+0x52a0 | callers(0) | datarefs 2

void FUN_170052a0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_1700a550();
  if (iVar1 == 0) {
    FUN_1700a4cc(param_1,3);
    *(code **)(param_1 + 0x20) = FUN_17005478;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x17005478 FUN_17005478 (ShopMenu)
//   size 0x180 | file ShopMenu+0x5478 | callers(0) | datarefs 17

void FUN_17005478(int param_1)

{
  byte bVar1;
  undefined1 uVar2;
  byte *pbVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  ushort *puVar7;
  
  bVar1 = *(byte *)(param_1 + 0xa9);
  pbVar3 = (byte *)shop::GetBootInfo();
  uVar4 = (uint)*pbVar3;
  if (8 < uVar4) {
    uVar4 = 9;
  }
  DAT_003f9e14 = DAT_003f9e14 & ~(3 << (uVar4 << 1 & 0xff)) | (uint)bVar1 << (uVar4 << 1 & 0xff);
  iVar5 = msys::MLyt::isEnableAnime(*(MLyt **)(param_1 + 0x44));
  if (iVar5 != 0) {
    return;
  }
  iVar6 = msys::MLyt::isEnableAnime(*(MLyt **)(param_1 + 0x48));
  iVar5 = msys::MComSys::_sys;
  if (iVar6 != 0) {
    return;
  }
  iVar6 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar6 = iVar5;
  }
  *(undefined1 *)(iVar6 + 0xe6508) = 1;
  iVar6 = msys::MComSys::_sys;
  iVar5 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar5 = iVar6;
  }
  *(undefined1 *)(iVar5 + 0xe650a) = 1;
  if (*(short *)(param_1 + 0x7e) != 0) goto LAB_170055a4;
  if (*(char *)(param_1 + 0x7c) == '\x04') {
    *(undefined1 *)(param_1 + 0xa8) = 7;
    goto switchD_1700554c_caseD_0;
  }
  puVar7 = (ushort *)shop::GetBootInfo();
  switch((&DAT_1701674b)[(*puVar7 & 0xffff0fff) * 4]) {
  default:
    goto switchD_1700554c_caseD_0;
  case 1:
    uVar2 = 1;
    break;
  case 2:
    uVar2 = 0;
    break;
  case 3:
    uVar2 = 2;
    break;
  case 4:
    if (*(char *)(param_1 + 0x7c) == '\x01') {
      uVar2 = 5;
    }
    else {
      uVar2 = 4;
    }
    break;
  case 5:
    uVar2 = 6;
    break;
  case 6:
    *(undefined1 *)(param_1 + 0xa8) = 3;
    goto switchD_1700554c_caseD_0;
  }
  *(undefined1 *)(param_1 + 0xa8) = uVar2;
switchD_1700554c_caseD_0:
  FUN_1700a944(param_1,*(undefined1 *)(param_1 + 0xa8));
LAB_170055a4:
  iVar5 = param_1 + *(short *)(param_1 + 0x7e) * 2;
  if (*(short *)(iVar5 + 0x90) == -1) {
    *(undefined2 *)(iVar5 + 0x90) = *(undefined2 *)(iVar5 + 0x80);
  }
  *(undefined1 *)(*(int *)(param_1 + 0x58) + 0x18) =
       *(undefined1 *)(param_1 + *(short *)(param_1 + 0x7e) * 2 + 0x90);
  msys::MCursorBase::setVisible(*(MCursorBase **)(param_1 + 0x58),true);
  FUN_1700ad98(*(undefined4 *)(param_1 + 0x58));
  *(undefined1 *)(param_1 + 0x7c) = 0xff;
  *(code **)(param_1 + 0x20) = FUN_17003f40;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


// FUNC 0x17005624 FUN_17005624 (ShopMenu)
//   size 0x44 | file ShopMenu+0x5624 | callers(0) | datarefs 2

void FUN_17005624(int param_1)

{
  int iVar1;
  
  iVar1 = msys::MLyt::isEnableAnime(*(MLyt **)(param_1 + 0x44));
  if ((iVar1 != 0) || (iVar1 = msys::MLyt::isEnableAnime(*(MLyt **)(param_1 + 0x48)), iVar1 != 0)) {
    *(undefined1 *)(*(int *)(param_1 + 4) + 0x14) = 1;
  }
  *(undefined **)(param_1 + 0x10) = &DAT_170074f4;
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}


// FUNC 0x1700566c FUN_1700566c (ShopMenu)
//   size 0x44 | file ShopMenu+0x566c | callers(0) | datarefs 4

void FUN_1700566c(int param_1)

{
  int iVar1;
  
  iVar1 = msys::MLyt::isEnableAnime(*(MLyt **)(param_1 + 0x44));
  if ((iVar1 == 0) && (iVar1 = msys::MLyt::isEnableAnime(*(MLyt **)(param_1 + 0x48)), iVar1 == 0)) {
    FUN_1700a944(param_1,*(undefined1 *)(param_1 + 0xa8));
    *(code **)(param_1 + 0x20) = FUN_17005478;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x170056b4 FUN_170056b4 (ShopMenu)
//   size 0x70 | file ShopMenu+0x56b4 | callers(0) | datarefs 1

void FUN_170056b4(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_1700a550();
  if (iVar1 == 0) {
    FUN_1700a4cc(param_1,3);
    msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x44),0x17,0,(char *)0x0,(char *)0x0);
    msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x48),0x1a,0,(char *)0x0,(char *)0x0);
    Frm::play((Frm *)(param_1 + 0x98),30.0);
    *(code **)(param_1 + 0x20) = FUN_17006130;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x1700572c FUN_1700572c (ShopMenu)
//   size 0xb4 | file ShopMenu+0x572c | callers(0) | datarefs 2

void FUN_1700572c(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 unaff_r5;
  float fVar4;
  
  iVar2 = msys::MLyt::isEnableAnime(*(MLyt **)(param_1 + 0x44));
  if ((iVar2 == 0) &&
     (iVar3 = msys::MLyt::isEnableAnime(*(MLyt **)(param_1 + 0x48)), iVar2 = msys::MComSys::_sys,
     iVar3 == 0)) {
    iVar3 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar3 = iVar2;
    }
    iVar2 = ad::fw::TaskBase::isFps30(*(TaskBase **)(iVar3 + 4));
    if (iVar2 == 0) {
      fVar4 = 1.0;
    }
    else {
      fVar4 = 2.0;
    }
    iVar2 = Frm::update(fVar4);
    if (iVar2 == 0) {
      cVar1 = *(char *)(param_1 + 0xa9);
      if (cVar1 == '\0') {
        unaff_r5 = 0x10;
      }
      else if (cVar1 == '\x01') {
        unaff_r5 = 0x11;
      }
      else if (cVar1 == '\x02') {
        unaff_r5 = 0x12;
      }
      FUN_1700a4cc(param_1,2);
      FUN_1700a5b0(param_1,unaff_r5);
      *(code **)(param_1 + 0x20) = FUN_170057f0;
      *(undefined4 *)(param_1 + 0x24) = 0;
    }
  }
  return;
}


// FUNC 0x170057f0 FUN_170057f0 (ShopMenu)
//   size 0x30 | file ShopMenu+0x57f0 | callers(0) | datarefs 2

void FUN_170057f0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_1700a550();
  if (iVar1 == 0) {
    FUN_1700a4cc(param_1,3);
    *(code **)(param_1 + 0x20) = FUN_17005478;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x17005824 FUN_17005824 (ShopMenu)
//   size 0x84 | file ShopMenu+0x5824 | callers(0)

void FUN_17005824(int param_1)

{
  *(undefined4 *)(*(int *)(param_1 + 8) + 0xea030) = 0;
  msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x44),0x12,1,(char *)0x0,(char *)0x0);
  msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x48),0x13,1,(char *)0x0,(char *)0x0);
  msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x48),0x1b,1,"SCRATCH_EXP_PNL",(char *)0x0);
  *(undefined1 *)(param_1 + 0x5f9) = 0;
  FUN_1700a944(param_1,*(undefined1 *)(param_1 + 0xa8));
  *(code **)(param_1 + 0x20) = FUN_17005478;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


// FUNC 0x170058bc FUN_170058bc (ShopMenu)
//   size 0xd4 | file ShopMenu+0x58bc | callers(0) | datarefs 2

void FUN_170058bc(int param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  
  iVar2 = msys::MLyt::isEnableAnime(*(MLyt **)(param_1 + 0x44));
  if ((iVar2 == 0) &&
     (iVar3 = msys::MLyt::isEnableAnime(*(MLyt **)(param_1 + 0x48)), iVar2 = msys::MComSys::_sys,
     iVar3 == 0)) {
    iVar3 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar3 = iVar2;
    }
    iVar2 = ad::fw::TaskBase::isFps30(*(TaskBase **)(iVar3 + 4));
    if (iVar2 == 0) {
      fVar4 = 1.0;
    }
    else {
      fVar4 = 2.0;
    }
    iVar2 = Frm::update(fVar4);
    if (iVar2 == 0) {
      FUN_1700beb8(msys::MComSys::_sys + 0x49368,0x110020,0,0,0);
      iVar3 = msys::MComSys::_sys;
      iVar2 = *(int *)(param_1 + 8);
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar2 = iVar3;
      }
      bVar1 = *(byte *)(param_1 + 0xa9);
      ad::lyt::LytNumReel3::setValue((LytNumReel3 *)(iVar2 + 0xebdb0),(uint)bVar1);
      ad::lyt::LytNumReel3::setValue((LytNumReel3 *)(iVar2 + 0xebb80),(uint)bVar1);
      Frm::play((Frm *)(param_1 + 0x98),30.0);
      *(code **)(param_1 + 0x20) = FUN_170059ac;
      *(undefined4 *)(param_1 + 0x24) = 0;
    }
  }
  return;
}


// FUNC 0x170059ac FUN_170059ac (ShopMenu)
//   size 0x130 | file ShopMenu+0x59ac | callers(0) | datarefs 2

void FUN_170059ac(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  float fVar4;
  
  iVar1 = msys::MComSys::_sys;
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  iVar2 = *(int *)(param_1 + 8);
  if ((*(int *)(iVar2 + 0xebe34) == *(int *)(iVar2 + 0xebe2c)) &&
     (*(int *)(iVar2 + 0xebc04) == *(int *)(iVar2 + 0xebbfc))) {
    if (iVar2 == 0) {
      *(int *)(param_1 + 8) = iVar1;
    }
    iVar1 = ad::fw::TaskBase::isFps30(*(TaskBase **)(*(int *)(param_1 + 8) + 4));
    if (iVar1 == 0) {
      fVar4 = 1.0;
    }
    else {
      fVar4 = 2.0;
    }
    iVar2 = Frm::update(fVar4);
    iVar1 = msys::MComSys::_sys;
    if (iVar2 == 0) {
      iVar2 = *(int *)(param_1 + 8);
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar2 = iVar1;
      }
      uVar3 = (uint)*(byte *)(param_1 + 0xa9);
      iVar1 = msys::MLyt::getPane((MLyt *)(*(int *)(iVar2 + 0xeba2c) + 0xea3dc),
                                  "TOP_HIGE_percent_base",(char *)0x0,(char *)0x0);
      *(byte *)(iVar1 + 0x44) = *(byte *)(iVar1 + 0x44) & 0xfe | uVar3 != 0;
      ad::lyt::LytNumReel3::setValueInstant((LytNumReel3 *)(iVar2 + 0xebdb0),uVar3);
      ad::lyt::LytNumReel3::setValueInstant((LytNumReel3 *)(iVar2 + 0xebb80),uVar3);
      msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x44),0x17,1,(char *)0x0,(char *)0x0);
      msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x48),0x1a,1,(char *)0x0,(char *)0x0);
      Frm::play((Frm *)(param_1 + 0x98),30.0);
      *(code **)(param_1 + 0x20) = FUN_170051c8;
      *(undefined4 *)(param_1 + 0x24) = 0;
    }
  }
  return;
}


// FUNC 0x17005af8 FUN_17005af8 (ShopMenu)
//   size 0x100 | file ShopMenu+0x5af8 | callers(0) | datarefs 2

void FUN_17005af8(int param_1,uint *param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  cVar1 = *(char *)(*(int *)(param_1 + 0x58) + 0x18);
  uVar3 = *param_2;
  iVar6 = (int)(char)(cVar1 + -0x18);
  iVar5 = iVar6;
  if ((uVar3 & 0x401) != 0) {
    iVar4 = param_1 + iVar6 * 4;
    (**(code **)(**(int **)(iVar4 + 0xe8d8) + 0x10))();
    (**(code **)(**(int **)(iVar4 + 0xe8d8) + 0xc))();
    iVar2 = msys::MComSys::_sys;
    iVar4 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar4 = iVar2;
    }
    *(undefined1 *)(iVar4 + 0xe6508) = 0;
    goto LAB_17005bb4;
  }
  if ((uVar3 & 0x802) == 0) {
    if ((uVar3 & 0x20) == 0) {
      if (((uVar3 & 0x10) != 0) && (iVar5 = (int)(char)(cVar1 + -0x17), 1 < iVar5)) {
        iVar5 = 0;
      }
      goto LAB_17005bb4;
    }
    iVar5 = (int)(char)(cVar1 + -0x19);
    if (-1 < (char)(cVar1 + -0x19)) goto LAB_17005bb4;
  }
  iVar5 = 1;
LAB_17005bb4:
  if (iVar5 != iVar6) {
    FUN_1700beb8(msys::MComSys::_sys + 0x49368,0x110015,0,0,0);
    *(char *)(*(int *)(param_1 + 0x58) + 0x18) = (char)iVar5 + '\x18';
  }
  FUN_1700ad98(*(undefined4 *)(param_1 + 0x58));
  return;
}


// FUNC 0x17005c08 FUN_17005c08 (ShopMenu)
//   size 0x2cc | file ShopMenu+0x5c08 | callers(0) | datarefs 1

void FUN_17005c08(int param_1)

{
  char cVar1;
  undefined1 uVar2;
  ushort *puVar3;
  char *pcVar4;
  uint uVar5;
  code *pcVar6;
  int iVar7;
  byte *pbVar8;
  uint uVar9;
  int iVar10;
  undefined4 unaff_r7;
  
  iVar7 = msys::MLyt::isEnableAnime(*(MLyt **)(param_1 + 0x44));
  if (iVar7 != 0) {
    return;
  }
  iVar7 = msys::MLyt::isEnableAnime(*(MLyt **)(param_1 + 0x48));
  if (iVar7 != 0) {
    return;
  }
  if (*(char *)(param_1 + 0x7c) == -1) {
    pbVar8 = (byte *)shop::GetBootInfo();
    uVar9 = (uint)*pbVar8;
    if (8 < uVar9) {
      uVar9 = 9;
    }
    if ((DAT_003f9e14 >> ((uVar9 & 0x7f) << 1) & 3) != (uint)*(byte *)(param_1 + 0xa9)) {
      *(undefined4 *)(param_1 + 0xe6bc) = 0xffffffff;
      *(int *)(param_1 + 0xe6ac) = param_1 + 0xe6c4;
      *(undefined4 *)(param_1 + 0xe6c0) = 0xffffffff;
      *(int *)(param_1 + 0xe688) = param_1 + 0xe6c8;
      *(undefined4 *)(param_1 + 0xe68c) = 0x400;
      *(undefined1 *)(param_1 + 0xe6b4) = 0;
      puVar3 = (ushort *)shop::GetBootInfo();
      switch((&DAT_1701674b)[(*puVar3 & 0xffff0fff) * 4]) {
      case 1:
      case 2:
      case 3:
        *(undefined1 *)(param_1 + 0xe708) = 0;
        *(undefined1 *)(param_1 + 0xe709) = 0;
        *(undefined4 *)(param_1 + 0xe6bc) = 0x110003;
        *(undefined4 *)(param_1 + 0xe6c0) = 0x110004;
        pcVar4 = (char *)shop::GetBootInfo();
        cVar1 = *pcVar4;
        if (cVar1 == '\x04') {
          uVar2 = 2;
        }
        else {
          if (cVar1 != '\x05') {
            if (cVar1 == '\x06') {
              *(undefined1 *)(param_1 + 0xe709) = 1;
            }
            else {
              *(undefined1 *)(param_1 + 0xe709) = 0;
            }
            break;
          }
          uVar2 = 3;
        }
        *(undefined1 *)(param_1 + 0xe709) = uVar2;
        break;
      case 4:
      case 5:
        *(undefined1 *)(param_1 + 0xe708) = 1;
        *(undefined1 *)(param_1 + 0xe709) = 4;
        *(undefined4 *)(param_1 + 0xe6bc) = 0x110003;
        *(undefined4 *)(param_1 + 0xe6c0) = 0x110004;
        break;
      case 6:
        *(undefined1 *)(param_1 + 0xe708) = 1;
        *(undefined1 *)(param_1 + 0xe709) = 5;
      }
      pbVar8 = (byte *)shop::GetBootInfo();
      uVar9 = (uint)*pbVar8;
      if (8 < uVar9) {
        uVar9 = 9;
      }
      uVar5 = (uint)*(byte *)(param_1 + 0xa9);
      if ((DAT_003f9e14 >> ((uVar9 & 0x7f) << 1) & 3) < uVar5) {
        if (uVar5 == 1) {
          unaff_r7 = 9;
        }
        else if (uVar5 == 2) {
          unaff_r7 = 0xb;
        }
        else if (uVar5 == 3) {
          unaff_r7 = 0xd;
        }
        pcVar6 = FUN_17005150;
      }
      else {
        unaff_r7 = 0xf;
        pcVar6 = FUN_170056b4;
      }
      *(code **)(param_1 + 0x20) = pcVar6;
      *(undefined4 *)(param_1 + 0x24) = 0;
      FUN_1700a4cc(param_1,2);
      FUN_1700a5b0(param_1,unaff_r7);
      return;
    }
  }
  pbVar8 = (byte *)shop::GetBootInfo();
  iVar7 = msys::MComSys::_sys;
  uVar9 = (uint)*pbVar8;
  if (8 < uVar9) {
    uVar9 = 9;
  }
  if ((DAT_003f9e14 >> ((uVar9 & 0x7f) << 1) & 3) != 0) {
    iVar10 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar10 = iVar7;
    }
    if (*(int *)(iVar10 + 0xea030) != 0) {
      msys::MLyt::setAnimeInfo(*(MLyt **)(param_1 + 0x44),0x12,0xffffffff);
      msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x44),0x12,0,(char *)0x0,(char *)0x0);
      msys::MLyt::setAnimeInfo(*(MLyt **)(param_1 + 0x48),0x13,0xffffffff);
      msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x48),0x13,0,(char *)0x0,(char *)0x0);
      msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x48),0x1b,0,"SCRATCH_EXP_PNL",(char *)0x0);
      *(undefined1 *)(param_1 + 0x5f9) = 0;
      FUN_170031f0(param_1 + 0x334,*(undefined1 *)(param_1 + 0xa9));
      pcVar6 = FUN_17007404;
      goto LAB_17005d58;
    }
  }
  pcVar6 = FUN_17005478;
LAB_17005d58:
  *(code **)(param_1 + 0x20) = pcVar6;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


// FUNC 0x17005d74 FUN_17005d74 (ShopMenu)
//   size 0x60 | file ShopMenu+0x5d74 | callers(0) | datarefs 2

void FUN_17005d74(int param_1)

{
  code *pcVar1;
  
  if (*(int *)(param_1 + 0xe6c4) == 0) {
    FUN_1700a5b0(param_1,0);
    pcVar1 = FUN_1700630c;
  }
  else {
    if (*(int *)(param_1 + 0xe6c4) != 1) goto LAB_17005dc8;
    FUN_1700a5b0(param_1,1);
    pcVar1 = FUN_17005dd8;
  }
  *(code **)(param_1 + 0x20) = pcVar1;
  *(undefined4 *)(param_1 + 0x24) = 0;
LAB_17005dc8:
  FUN_1700a550(param_1);
  return;
}


// FUNC 0x17005dd8 FUN_17005dd8 (ShopMenu)
//   size 0x94 | file ShopMenu+0x5dd8 | callers(0) | datarefs 2

void FUN_17005dd8(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_1700a550();
  if (iVar1 == 0) {
    *(undefined1 *)(param_1 + 0x778c) = 0;
    iVar1 = msys::MLyt::getPane((MLyt *)(*(int *)(param_1 + 0x75e8) + 0xea034),"SCRATCH_PRIZE_MARK",
                                (char *)0x0,(char *)0x0);
    *(byte *)(iVar1 + 0x44) = *(byte *)(iVar1 + 0x44) & 0xfe;
    *(byte *)(*(int *)(param_1 + 0x7788) + 0x44) =
         *(byte *)(*(int *)(param_1 + 0x7788) + 0x44) & 0xfe | 1;
    msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x44),0x18,0,(char *)0x0,(char *)0x0);
    Frm::play((Frm *)(param_1 + 0x98),30.0);
    *(code **)(param_1 + 0x20) = FUN_1700641c;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x17005e78 FUN_17005e78 (ShopMenu)
//   size 0x30 | file ShopMenu+0x5e78 | callers(0) | datarefs 2

void FUN_17005e78(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_1700a550();
  if (iVar1 == 0) {
    FUN_1700a5b0(param_1,3);
    *(code **)(param_1 + 0x20) = FUN_17006750;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x17005eac FUN_17005eac (ShopMenu)
//   size 0x54 | file ShopMenu+0x5eac | callers(0) | datarefs 2

void FUN_17005eac(int param_1)

{
  *(undefined1 *)(*(int *)(param_1 + 8) + 0xeb9c4) = 7;
  msys::MCursorBase::setVisible((MCursorBase *)(*(int *)(param_1 + 8) + 0xeb9ac),true);
  FUN_1700a234(*(int *)(param_1 + 8) + 0xeb9ac);
  Frm::play((Frm *)(param_1 + 0x98),30.0);
  *(code **)(param_1 + 0x20) = FUN_17006784;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


// FUNC 0x17005f0c FUN_17005f0c (ShopMenu)
//   size 0x30 | file ShopMenu+0x5f0c | callers(0) | datarefs 2

void FUN_17005f0c(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_1700a550();
  if (iVar1 == 0) {
    FUN_1700a5b0(param_1,5);
    *(code **)(param_1 + 0x20) = FUN_17005f40;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x17005f40 FUN_17005f40 (ShopMenu)
//   size 0x94 | file ShopMenu+0x5f40 | callers(0) | datarefs 2

void FUN_17005f40(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_1700a550();
  if (iVar1 == 0) {
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
    }
    iVar1 = msys::MComSys::_sys;
    iVar2 = *(int *)(param_1 + 8);
    if (iVar2 == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar1;
    }
    MoveVBase::moveFrmAbs((VEC3 *)(iVar2 + 0xeb714),60.0);
    FUN_1700a4cc(param_1,1);
    *(code **)(param_1 + 0x20) = FUN_17006a20;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x17005fe8 FUN_17005fe8 (ShopMenu)
//   size 0x60 | file ShopMenu+0x5fe8 | callers(0) | datarefs 2

void FUN_17005fe8(int param_1)

{
  code *pcVar1;
  
  if (*(int *)(param_1 + 0xe6c4) == 0) {
    FUN_1700a5b0(param_1,7);
    pcVar1 = FUN_17005dd8;
  }
  else {
    if (*(int *)(param_1 + 0xe6c4) != 1) goto LAB_1700603c;
    FUN_1700a5b0(param_1,8);
    pcVar1 = FUN_1700630c;
  }
  *(code **)(param_1 + 0x20) = pcVar1;
  *(undefined4 *)(param_1 + 0x24) = 0;
LAB_1700603c:
  FUN_1700a550(param_1);
  return;
}


// FUNC 0x1700604c FUN_1700604c (ShopMenu)
//   size 0xd0 | file ShopMenu+0x604c | callers(0) | datarefs 2

void FUN_1700604c(int param_1,uint *param_2)

{
  if ((*param_2 & 0x401) != 0) {
    FUN_1700beb8(msys::MComSys::_sys + 0x49368,0x110016,0,0,0);
    msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x48),0x1e,1,(char *)0x0,(char *)0x0);
    if (*(int *)(param_1 + 0xe864) != 0) {
      msys::MDfxChr::term((MDfxChr *)(param_1 + 0xe710));
    }
    msys::MLyt::setAnimeInfo(*(MLyt **)(param_1 + 0x44),0x16,0xffffffff);
    msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x44),0x16,0,(char *)0x0,(char *)0x0);
    msys::MLyt::setAnimeInfo(*(MLyt **)(param_1 + 0x48),0x19,0xffffffff);
    msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x48),0x19,0,(char *)0x0,(char *)0x0);
    *(code **)(param_1 + 0x20) = FUN_1700566c;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x17006130 FUN_17006130 (ShopMenu)
//   size 0xd4 | file ShopMenu+0x6130 | callers(0) | datarefs 2

void FUN_17006130(int param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  
  iVar2 = msys::MLyt::isEnableAnime(*(MLyt **)(param_1 + 0x44));
  if ((iVar2 == 0) &&
     (iVar3 = msys::MLyt::isEnableAnime(*(MLyt **)(param_1 + 0x48)), iVar2 = msys::MComSys::_sys,
     iVar3 == 0)) {
    iVar3 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar3 = iVar2;
    }
    iVar2 = ad::fw::TaskBase::isFps30(*(TaskBase **)(iVar3 + 4));
    if (iVar2 == 0) {
      fVar4 = 1.0;
    }
    else {
      fVar4 = 2.0;
    }
    iVar2 = Frm::update(fVar4);
    if (iVar2 == 0) {
      FUN_1700beb8(msys::MComSys::_sys + 0x49368,0x110021,0,0,0);
      iVar3 = msys::MComSys::_sys;
      iVar2 = *(int *)(param_1 + 8);
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar2 = iVar3;
      }
      bVar1 = *(byte *)(param_1 + 0xa9);
      ad::lyt::LytNumReel3::setValue((LytNumReel3 *)(iVar2 + 0xebdb0),(uint)bVar1);
      ad::lyt::LytNumReel3::setValue((LytNumReel3 *)(iVar2 + 0xebb80),(uint)bVar1);
      Frm::play((Frm *)(param_1 + 0x98),30.0);
      *(code **)(param_1 + 0x20) = FUN_17006220;
      *(undefined4 *)(param_1 + 0x24) = 0;
    }
  }
  return;
}


// FUNC 0x17006220 FUN_17006220 (ShopMenu)
//   size 0xd4 | file ShopMenu+0x6220 | callers(0) | datarefs 2

void FUN_17006220(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  float fVar3;
  
  uVar1 = msys::MComSys::_sys;
  if (*(int *)(param_1 + 8) == 0) {
    *(undefined4 *)(param_1 + 8) = msys::MComSys::_sys;
  }
  iVar2 = *(int *)(param_1 + 8);
  if ((*(int *)(iVar2 + 0xebe34) == *(int *)(iVar2 + 0xebe2c)) &&
     (*(int *)(iVar2 + 0xebc04) == *(int *)(iVar2 + 0xebbfc))) {
    if (iVar2 == 0) {
      *(undefined4 *)(param_1 + 8) = uVar1;
    }
    iVar2 = ad::fw::TaskBase::isFps30(*(TaskBase **)(*(int *)(param_1 + 8) + 4));
    if (iVar2 == 0) {
      fVar3 = 1.0;
    }
    else {
      fVar3 = 2.0;
    }
    iVar2 = Frm::update(fVar3);
    if (iVar2 == 0) {
      msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x44),0x17,1,(char *)0x0,(char *)0x0);
      if (*(char *)(param_1 + 0xa9) != '\0') {
        msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x48),0x1a,1,(char *)0x0,(char *)0x0);
      }
      Frm::play((Frm *)(param_1 + 0x98),30.0);
      *(code **)(param_1 + 0x20) = FUN_1700572c;
      *(undefined4 *)(param_1 + 0x24) = 0;
    }
  }
  return;
}


// FUNC 0x1700630c FUN_1700630c (ShopMenu)
//   size 0x30 | file ShopMenu+0x630c | callers(0) | datarefs 2

void FUN_1700630c(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_1700a550();
  if (iVar1 == 0) {
    FUN_1700a4cc(param_1,3);
    *(code **)(param_1 + 0x20) = FUN_17005478;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x17006340 FUN_17006340 (ShopMenu)
//   size 0x98 | file ShopMenu+0x6340 | callers(0) | datarefs 2

void FUN_17006340(int param_1)

{
  int iVar1;
  
  iVar1 = msys::MLyt::isEnableAnime(*(MLyt **)(param_1 + 0x44));
  if ((((iVar1 == 0) && (iVar1 = msys::MLyt::isEnableAnime(*(MLyt **)(param_1 + 0x48)), iVar1 == 0))
      && (*(int *)(param_1 + 0x72d0) == *(int *)(param_1 + 0x72c8))) &&
     (*(int *)(param_1 + 0x7500) == *(int *)(param_1 + 0x74f8))) {
    SndSeCtrl::stop(*(SndSeCtrl **)(param_1 + 0xe70c),0);
    msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x48),0x1e,0,(char *)0x0,(char *)0x0);
    *(code **)(param_1 + 0x20) = FUN_170063e0;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x170063e0 FUN_170063e0 (ShopMenu)
//   size 0x38 | file ShopMenu+0x63e0 | callers(0) | datarefs 2

void FUN_170063e0(int param_1)

{
  int iVar1;
  
  iVar1 = msys::MLyt::isEnableAnime(*(MLyt **)(param_1 + 0x44));
  if ((iVar1 == 0) && (iVar1 = msys::MLyt::isEnableAnime(*(MLyt **)(param_1 + 0x48)), iVar1 == 0)) {
    *(code **)(param_1 + 0x20) = FUN_1700604c;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x1700641c FUN_1700641c (ShopMenu)
//   size 0x120 | file ShopMenu+0x641c | callers(0) | datarefs 2

void FUN_1700641c(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  undefined4 *puVar5;
  float fVar6;
  
  iVar1 = msys::MLyt::isEnableAnime(*(MLyt **)(param_1 + 0x44));
  iVar2 = msys::MComSys::_sys;
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar1 = iVar2;
    }
    iVar2 = ad::fw::TaskBase::isFps30(*(TaskBase **)(iVar1 + 4));
    if (iVar2 == 0) {
      fVar6 = 1.0;
    }
    else {
      fVar6 = 2.0;
    }
    iVar2 = Frm::update(fVar6);
    if (iVar2 == 0) {
      iVar1 = *(int *)(param_1 + 8);
      iVar2 = iVar1;
      if (iVar1 == 0) {
        iVar2 = msys::MComSys::_sys;
      }
      if (iVar1 == 0) {
        *(int *)(param_1 + 8) = iVar2;
      }
      msys::MLyt::detachMChr(*(MLyt **)(param_1 + 0x44),(MChrBase *)(iVar2 + 0xeb648));
      piVar4 = (int *)(*(int *)(param_1 + 4) + 4);
      puVar5 = *(undefined4 **)(iVar2 + 0xeb650);
      *(undefined4 **)(*(int *)(iVar2 + 0xeb64c) + 4) = puVar5;
      *puVar5 = *(undefined4 *)(iVar2 + 0xeb64c);
      piVar3 = (int *)(iVar2 + 0xeb64c);
      if (piVar3 != (int *)0x0) {
        iVar1 = *piVar4;
        *(int **)(iVar2 + 0xeb650) = piVar4;
        *piVar3 = iVar1;
        *(int **)(iVar1 + 4) = piVar3;
        *piVar4 = (int)piVar3;
      }
      *(undefined4 *)(iVar2 + 0xeb784) = 0x400;
      MoveVBase::stop((MoveVBase *)(iVar2 + 0xeb714));
      *(undefined4 *)(iVar2 + 0xeb730) = 0xc35c0000;
      *(undefined4 *)(iVar2 + 0xeb734) = 0xc2200000;
      *(undefined4 *)(iVar2 + 0xeb738) = 0xc347cccd;
      *(undefined4 *)(iVar2 + 0xeb718) = 0xc35c0000;
      *(undefined4 *)(iVar2 + 0xeb71c) = 0xc2200000;
      *(undefined4 *)(iVar2 + 0xeb720) = 0xc347cccd;
      MoveVBase::moveFrmAbs((VEC3 *)(iVar2 + 0xeb714),60.0);
      FUN_1700a4cc(param_1,0);
      *(code **)(param_1 + 0x20) = FUN_17006564;
      *(undefined4 *)(param_1 + 0x24) = 0;
    }
  }
  return;
}


// FUNC 0x17006564 FUN_17006564 (ShopMenu)
//   size 0x88 | file ShopMenu+0x6564 | callers(0) | datarefs 2

void FUN_17006564(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 local_10;
  
  iVar1 = msys::MComSys::_sys;
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  else {
    iVar1 = *(int *)(param_1 + 8);
  }
  iVar2 = (**(code **)(*(int *)(iVar1 + 0xeb648) + 0x24))((int *)(iVar1 + 0xeb648));
  if (iVar2 == 0) {
    FUN_1700a4cc(param_1,3);
    local_18 = 0;
    uStack_14 = 0x3f800000;
    local_10 = 0;
    MoveVBase::jumpFT((MoveVBase *)(iVar1 + 0xeb714),0.0,20.0,20.0,(VEC3 *)&local_18);
    *(code **)(param_1 + 0x20) = FUN_17006604;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x17006604 FUN_17006604 (ShopMenu)
//   size 0x88 | file ShopMenu+0x6604 | callers(0) | datarefs 2

void FUN_17006604(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 local_10;
  
  iVar1 = msys::MComSys::_sys;
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  else {
    iVar1 = *(int *)(param_1 + 8);
  }
  iVar2 = (**(code **)(*(int *)(iVar1 + 0xeb648) + 0x24))((int *)(iVar1 + 0xeb648));
  if (iVar2 == 0) {
    local_18 = 0;
    uStack_14 = 0x3f800000;
    local_10 = 0;
    MoveVBase::jumpFT((MoveVBase *)(iVar1 + 0xeb714),0.0,20.0,20.0,(VEC3 *)&local_18);
    Frm::play((Frm *)(param_1 + 0x98),30.0);
    *(code **)(param_1 + 0x20) = FUN_170066a8;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x170066a8 FUN_170066a8 (ShopMenu)
//   size 0x94 | file ShopMenu+0x66a8 | callers(0) | datarefs 2

void FUN_170066a8(int param_1)

{
  int iVar1;
  int iVar2;
  float fVar3;
  
  iVar1 = msys::MComSys::_sys;
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  else {
    iVar1 = *(int *)(param_1 + 8);
  }
  iVar2 = (**(code **)(*(int *)(iVar1 + 0xeb648) + 0x24))();
  iVar1 = msys::MComSys::_sys;
  if (iVar2 == 0) {
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar1;
    }
    iVar1 = ad::fw::TaskBase::isFps30(*(TaskBase **)(iVar2 + 4));
    if (iVar1 == 0) {
      fVar3 = 1.0;
    }
    else {
      fVar3 = 2.0;
    }
    iVar1 = Frm::update(fVar3);
    if (iVar1 == 0) {
      FUN_1700a4cc(param_1,2);
      FUN_1700a5b0(param_1,2);
      *(code **)(param_1 + 0x20) = FUN_17005e78;
      *(undefined4 *)(param_1 + 0x24) = 0;
    }
  }
  return;
}


// FUNC 0x17006750 FUN_17006750 (ShopMenu)
//   size 0x30 | file ShopMenu+0x6750 | callers(0) | datarefs 2

void FUN_17006750(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_1700a550();
  if (iVar1 == 0) {
    FUN_1700a4cc(param_1,3);
    *(code **)(param_1 + 0x20) = FUN_17005eac;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x17006784 FUN_17006784 (ShopMenu)
//   size 0xa8 | file ShopMenu+0x6784 | callers(0) | datarefs 2

void FUN_17006784(int param_1)

{
  int iVar1;
  int iVar2;
  float fVar3;
  
  FUN_1700a234(*(int *)(param_1 + 8) + 0xeb9ac);
  iVar1 = msys::MComSys::_sys;
  iVar2 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar2 = iVar1;
  }
  iVar2 = ad::fw::TaskBase::isFps30(*(TaskBase **)(iVar2 + 4));
  if (iVar2 == 0) {
    fVar3 = 1.0;
  }
  else {
    fVar3 = 2.0;
  }
  iVar2 = Frm::update(fVar3);
  if (iVar2 == 0) {
    FUN_1700beb8(msys::MComSys::_sys + 0x49368,0x110015,0,0,0);
    *(undefined1 *)(*(int *)(param_1 + 8) + 0xeb9c4) = 0xc;
    FUN_1700a234(*(int *)(param_1 + 8) + 0xeb9ac);
    Frm::play((Frm *)(param_1 + 0x98),30.0);
    *(code **)(param_1 + 0x20) = FUN_17006848;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x17006848 FUN_17006848 (ShopMenu)
//   size 0x104 | file ShopMenu+0x6848 | callers(0) | datarefs 2

void FUN_17006848(int param_1)

{
  int iVar1;
  int iVar2;
  float fVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  FUN_1700a234(*(int *)(param_1 + 8) + 0xeb9ac);
  iVar1 = msys::MComSys::_sys;
  iVar2 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar2 = iVar1;
  }
  iVar2 = ad::fw::TaskBase::isFps30(*(TaskBase **)(iVar2 + 4));
  if (iVar2 == 0) {
    fVar3 = 1.0;
  }
  else {
    fVar3 = 2.0;
  }
  iVar2 = Frm::update(fVar3);
  if (iVar2 == 0) {
    FUN_1700beb8(msys::MComSys::_sys + 0x49368,0x110022,0,0,0);
    *(byte *)(*(int *)(param_1 + 0x7788) + 0x44) =
         *(byte *)(*(int *)(param_1 + 0x7788) + 0x44) & 0xfe;
    uVar4 = *(undefined4 *)(*(int *)(param_1 + 0x7788) + 0x54);
    uVar5 = *(undefined4 *)(*(int *)(param_1 + 0x7788) + 100);
    MoveVBase::stop((MoveVBase *)(param_1 + 0x76bc));
    *(undefined4 *)(param_1 + 0x76d8) = uVar4;
    *(undefined4 *)(param_1 + 0x76dc) = uVar5;
    *(undefined4 *)(param_1 + 0x76e0) = 0x43340000;
    *(undefined4 *)(param_1 + 0x76c0) = uVar4;
    *(undefined4 *)(param_1 + 0x76c4) = uVar5;
    *(undefined4 *)(param_1 + 0x76c8) = 0x43340000;
    msys::MDfxChr::playDfx((MDfxChr *)(param_1 + 0x75f0),0x34);
    msys::MCursorBase::setVisible((MCursorBase *)(*(int *)(param_1 + 8) + 0xeb9ac),false);
    Frm::play((Frm *)(param_1 + 0x98),30.0);
    *(code **)(param_1 + 0x20) = FUN_1700696c;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x1700696c FUN_1700696c (ShopMenu)
//   size 0x90 | file ShopMenu+0x696c | callers(0) | datarefs 2

void FUN_1700696c(int param_1)

{
  int iVar1;
  float fVar2;
  
  iVar1 = msys::MComSys::_sys;
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  else {
    iVar1 = *(int *)(param_1 + 8);
  }
  iVar1 = ad::fw::TaskBase::isFps30(*(TaskBase **)(iVar1 + 4));
  if (iVar1 == 0) {
    fVar2 = 1.0;
  }
  else {
    fVar2 = 2.0;
  }
  iVar1 = Frm::update(fVar2);
  if (iVar1 == 0) {
    iVar1 = msys::MLyt::getPane(*(MLyt **)(param_1 + 0x44),"SCRATCH_PRIZE_MARK",(char *)0x0,
                                (char *)0x0);
    *(byte *)(iVar1 + 0x44) = *(byte *)(iVar1 + 0x44) & 0xfe | 1;
    FUN_1700a4cc(param_1,2);
    FUN_1700a5b0(param_1,4);
    *(code **)(param_1 + 0x20) = FUN_17005f0c;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x17006a20 FUN_17006a20 (ShopMenu)
//   size 0x168 | file ShopMenu+0x6a20 | callers(0) | datarefs 2

void FUN_17006a20(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  byte *pbVar5;
  int *piVar6;
  uint in_fpscr;
  undefined4 uVar7;
  
  iVar2 = msys::MComSys::_sys;
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  else {
    iVar2 = *(int *)(param_1 + 8);
  }
  iVar3 = msys::MChrBaseCore::isBusySRTMov((MChrBaseCore *)(iVar2 + 0xeb648));
  iVar2 = msys::MComSys::_sys;
  if (iVar3 == 0) {
    iVar3 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar3 = iVar2;
    }
    piVar6 = *(int **)(iVar3 + 0xeb650);
    piVar4 = (int *)(iVar3 + 0xeb64c);
    if (piVar6 != piVar4) {
      *(int **)(*piVar4 + 4) = piVar6;
      *piVar6 = *piVar4;
      if (piVar4 != (int *)0x0) {
        *piVar4 = (int)piVar4;
        *(int **)(iVar3 + 0xeb650) = piVar4;
      }
    }
    *(undefined4 *)(iVar3 + 0xeb784) = 0;
    iVar3 = *(int *)(param_1 + 8);
    iVar2 = iVar3;
    if (iVar3 == 0) {
      iVar2 = msys::MComSys::_sys;
    }
    if (iVar3 == 0) {
      *(int *)(param_1 + 8) = iVar2;
    }
    pbVar5 = (byte *)shop::GetBootInfo();
    uVar7 = VectorSignedToFloat((int)*(short *)(&DAT_1701679c + (uint)*pbVar5 * 0x14),
                                (byte)(in_fpscr >> 0x16) & 3);
    MoveVBase::stop((MoveVBase *)(iVar2 + 0xeb714));
    *(undefined4 *)(iVar2 + 0xeb730) = 0;
    *(undefined4 *)(iVar2 + 0xeb734) = uVar7;
    *(undefined4 *)(iVar2 + 0xeb738) = 0;
    *(undefined4 *)(iVar2 + 0xeb718) = 0;
    *(undefined4 *)(iVar2 + 0xeb71c) = uVar7;
    *(undefined4 *)(iVar2 + 0xeb720) = 0;
    FUN_1700a4cc(param_1,3);
    iVar3 = msys::MComSys::_sys;
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar3;
    }
    iVar1 = msys::MComSys::_sys;
    iVar3 = iVar2;
    if (iVar2 == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar3 = iVar1;
    }
    msys::MLyt::attachMChr
              ((MLyt *)(iVar3 + 0xea784),(MChrBase *)(iVar2 + 0xeb648),"INS_obj",(char *)0x0,
               (char *)0x0,(char *)0x0);
    msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x44),0x18,1,(char *)0x0,(char *)0x0);
    Frm::play((Frm *)(param_1 + 0x98),30.0);
    *(code **)(param_1 + 0x20) = FUN_17006bb0;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x17006bb0 FUN_17006bb0 (ShopMenu)
//   size 0x80 | file ShopMenu+0x6bb0 | callers(0) | datarefs 2

void FUN_17006bb0(int param_1)

{
  int iVar1;
  int iVar2;
  float fVar3;
  
  iVar1 = msys::MLyt::isEnableAnime(*(MLyt **)(param_1 + 0x44));
  iVar2 = msys::MComSys::_sys;
  if (iVar1 == 0) {
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
    if (iVar2 == 0) {
      FUN_1700a4cc(param_1,2);
      FUN_1700a5b0(param_1,6);
      *(code **)(param_1 + 0x20) = FUN_17005fe8;
      *(undefined4 *)(param_1 + 0x24) = 0;
    }
  }
  return;
}


// FUNC 0x17006c40 FUN_17006c40 (ShopMenu)
//   size 0x174 | file ShopMenu+0x6c40 | callers(0) | datarefs 2

void FUN_17006c40(int param_1,uint *param_2)

{
  char cVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  char cVar8;
  int iVar9;
  
  cVar2 = *(char *)(*(int *)(param_1 + 0x58) + 0x18);
  cVar1 = cVar2 + -0x1a;
  iVar9 = (int)cVar1 % 5;
  uVar3 = *param_2;
  iVar6 = (short)cVar1 * 0x67 >> 9;
  uVar7 = iVar6 - ((short)cVar1 * 0x67 >> 0x1f);
  if ((uVar3 & 0x20) == 0) {
    if ((uVar3 & 0x10) != 0) {
      cVar2 = (char)iVar9 + '\x01';
      goto LAB_17006c98;
    }
    if ((uVar3 & 0x40) == 0) {
      if ((uVar3 & 0x80) != 0) {
        cVar2 = (char)uVar7 + '\x01';
        goto LAB_17006cb8;
      }
      iVar6 = 0x401;
      if ((uVar3 & 0x401) != 0) {
        (**(code **)(**(int **)(param_1 + cVar2 * 4 + 0xe878) + 0x10))();
        iVar5 = msys::MComSys::_sys;
        iVar6 = *(int *)(param_1 + 8);
        if (*(int *)(param_1 + 8) == 0) {
          *(int *)(param_1 + 8) = msys::MComSys::_sys;
          iVar6 = iVar5;
        }
        *(undefined1 *)(iVar6 + 0xe6508) = 0;
        iVar4 = *(int *)(param_1 + 8);
        iVar5 = iVar4;
        if (iVar4 == 0) {
          iVar5 = msys::MComSys::_sys;
        }
        iVar6 = iVar5 + 0xe6000;
        if (iVar4 == 0) {
          *(int *)(param_1 + 8) = iVar5;
        }
        *(undefined1 *)(iVar5 + 0xe650a) = 1;
      }
    }
    else {
      cVar2 = (char)uVar7 + -1;
LAB_17006cb8:
      uVar7 = (uint)cVar2;
    }
  }
  else {
    cVar2 = (char)iVar9 + -1;
LAB_17006c98:
    iVar9 = (int)cVar2;
  }
  cVar2 = (char)iVar6;
  if (iVar9 < 0) {
    cVar2 = (char)uVar7 + -1;
  }
  if (iVar9 < 0) {
    cVar8 = '\x04';
  }
  else {
    cVar8 = (char)iVar9;
    if (iVar9 < 5) goto LAB_17006d54;
    cVar2 = (char)uVar7 + '\x01';
    cVar8 = '\0';
  }
  uVar7 = (uint)cVar2;
LAB_17006d54:
  if ((int)uVar7 < 0) {
    uVar7 = (uint)(char)((char)-(uint)*(byte *)(param_1 + 0xa9) + '\x04');
  }
  if (-(uint)*(byte *)(param_1 + 0xa9) + 5 <= uVar7) {
    uVar7 = 0;
  }
  cVar8 = (char)uVar7 * '\x05' + cVar8;
  if ((int)cVar8 != (int)cVar1) {
    FUN_1700beb8(msys::MComSys::_sys + 0x49368,0x110015,0,0,0);
    *(char *)(*(int *)(param_1 + 0x58) + 0x18) = cVar8 + '\x1a';
  }
  FUN_1700ad98(*(undefined4 *)(param_1 + 0x58));
  return;
}


// FUNC 0x17006dc4 FUN_17006dc4 (ShopMenu)
//   size 0x184 | file ShopMenu+0x6dc4 | callers(0) | datarefs 2

void FUN_17006dc4(int param_1,uint *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  code *pcVar4;
  
  if ((*param_2 & 0x401) != 0) {
    FUN_1700beb8(msys::MComSys::_sys + 0x49368,0x110016,0,0,0);
    msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x48),0x1e,1,(char *)0x0,(char *)0x0);
    if ((*(char *)(param_1 + 0x338) < 0) ||
       (*(char *)((int)*(char *)(param_1 + 0x338) + param_1 + 0x755d) != '\x03')) {
      ad::lyt::LytNumReel3::setValue
                ((LytNumReel3 *)(param_1 + 0x724c),
                 *(int *)(param_1 + 0x72c8) + *(int *)(param_1 + 0x74f8));
      GameWork::addCoin((GameWork *)&gGameWork,*(int *)(param_1 + 0x74f8));
      iVar1 = *(int *)(param_1 + 0x334);
      iVar2 = GameWork::getCoin((GameWork *)&gGameWork);
      ad::lyt::LytNumReel3::setValueInstant((LytNumReel3 *)(iVar1 + 0xfdbf8),iVar2);
      ad::lyt::LytNumReel3::setValue((LytNumReel3 *)(param_1 + 0x747c),0);
      uVar3 = FUN_1700beb8(msys::MComSys::_sys + 0x49368,0x11001e,0,0,0);
      *(undefined4 *)(param_1 + 0xe70c) = uVar3;
      pcVar4 = FUN_17006340;
    }
    else {
      if (*(int *)(param_1 + 0xe864) != 0) {
        msys::MDfxChr::term((MDfxChr *)(param_1 + 0xe710));
      }
      msys::MLyt::setAnimeInfo(*(MLyt **)(param_1 + 0x44),0x16,0xffffffff);
      msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x44),0x16,0,(char *)0x0,(char *)0x0);
      msys::MLyt::setAnimeInfo(*(MLyt **)(param_1 + 0x48),0x19,0xffffffff);
      msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x48),0x19,0,(char *)0x0,(char *)0x0);
      pcVar4 = FUN_1700566c;
    }
    *(code **)(param_1 + 0x20) = pcVar4;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x17006f68 FUN_17006f68 (ShopMenu)
//   size 0xa0 | file ShopMenu+0x6f68 | callers(0) | datarefs 2

void FUN_17006f68(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = msys::MLyt::isEnableAnime(*(MLyt **)(param_1 + 0x44));
  if ((iVar1 == 0) &&
     (iVar2 = msys::MLyt::isEnableAnime(*(MLyt **)(param_1 + 0x48)), iVar1 = msys::MComSys::_sys,
     iVar2 == 0)) {
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
    FUN_1700a944(param_1,9);
    *(undefined1 *)(*(int *)(param_1 + 0x58) + 0x18) = 0x21;
    msys::MCursorBase::setVisible(*(MCursorBase **)(param_1 + 0x58),true);
    FUN_1700ad98(*(undefined4 *)(param_1 + 0x58));
    *(code **)(param_1 + 0x20) = FUN_17006c40;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x17007010 FUN_17007010 (ShopMenu)
//   size 0x80 | file ShopMenu+0x7010 | callers(0) | datarefs 2

void FUN_17007010(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = msys::MLyt::isEnableAnime(*(MLyt **)(param_1 + 0x44));
  if ((iVar1 == 0) &&
     (iVar2 = msys::MLyt::isEnableAnime(*(MLyt **)(param_1 + 0x48)), iVar1 = msys::MComSys::_sys,
     iVar2 == 0)) {
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
    FUN_1700a944(param_1,10);
    *(code **)(param_1 + 0x20) = FUN_17006dc4;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x17007098 FUN_17007098 (ShopMenu)
//   size 0x68 | file ShopMenu+0x7098 | callers(0) | datarefs 2

void FUN_17007098(int param_1)

{
  int iVar1;
  
  iVar1 = msys::MLyt::isEnableAnime(*(MLyt **)(param_1 + 0x44));
  if ((iVar1 == 0) && (iVar1 = msys::MLyt::isEnableAnime(*(MLyt **)(param_1 + 0x48)), iVar1 == 0)) {
    FUN_1700b110(param_1 + 0x334,2);
    *(undefined1 *)(param_1 + 0x5f9) = 1;
    msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x48),0x1e,0,(char *)0x0,(char *)0x0);
    *(code **)(param_1 + 0x20) = FUN_17007010;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x17007104 FUN_17007104 (ShopMenu)
//   size 0x104 | file ShopMenu+0x7104 | callers(0) | datarefs 1

void FUN_17007104(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = msys::MLyt::isEnableAnime(*(MLyt **)(param_1 + 0x44));
  if (iVar1 == 0) {
    iVar2 = msys::MLyt::isEnableAnime(*(MLyt **)(param_1 + 0x48));
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
      iVar2 = msys::MComSys::_sys;
      iVar1 = *(int *)(param_1 + 8);
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar1 = iVar2;
      }
      *(undefined1 *)(iVar1 + 0xe6508) = 0;
      iVar1 = msys::MComSys::_sys;
      iVar2 = *(int *)(param_1 + 8);
      if (iVar2 == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar2 = iVar1;
      }
      *(undefined1 *)(iVar2 + 0xe650a) = 1;
      msys::MLyt::setAnimeInfo(*(MLyt **)(param_1 + 0x44),0x13,0xffffffff);
      msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x44),0x14,0,(char *)0x0,(char *)0x0);
      msys::MLyt::setAnimeInfo(*(MLyt **)(param_1 + 0x48),0x15,0xffffffff);
      msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x48),0x15,0,(char *)0x0,(char *)0x0);
      *(code **)(param_1 + 0x20) = FUN_17006f68;
      *(undefined4 *)(param_1 + 0x24) = 0;
    }
  }
  return;
}


// FUNC 0x17007210 FUN_17007210 (ShopMenu)
//   size 0x1b8 | file ShopMenu+0x7210 | callers(0) | datarefs 1

void FUN_17007210(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  float fVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  iVar2 = msys::MLyt::isEnableAnime(*(MLyt **)(param_1 + 0x44));
  if (iVar2 != 0) {
    return;
  }
  iVar3 = msys::MLyt::isEnableAnime(*(MLyt **)(param_1 + 0x48));
  iVar2 = msys::MComSys::_sys;
  if (iVar3 != 0) {
    return;
  }
  iVar3 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar3 = iVar2;
  }
  iVar2 = ad::fw::TaskBase::isFps30(*(TaskBase **)(iVar3 + 4));
  if (iVar2 == 0) {
    fVar5 = 1.0;
  }
  else {
    fVar5 = 2.0;
  }
  iVar2 = Frm::update(fVar5);
  if (iVar2 != 0) {
    return;
  }
  msys::MLyt::setAnimeInfo(*(MLyt **)(param_1 + 0x44),0x15,0xffffffff);
  msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x44),0x15,0,(char *)0x0,(char *)0x0);
  msys::MLyt::setAnimeInfo(*(MLyt **)(param_1 + 0x48),0x18,0xffffffff);
  msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x48),0x18,0,(char *)0x0,(char *)0x0);
  msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x48),0x1b,0,"SCRATCH_EXP_PNL",(char *)0x0);
  iVar3 = msys::MComSys::_sys;
  iVar2 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar2 = iVar3;
  }
  Frm::play((Frm *)(param_1 + 0x98),*(float *)(*(int *)(iVar2 + 0xe904c) + 0x74));
  *(undefined1 *)(param_1 + 0x5f9) = 0;
  iVar2 = msys::MLyt::getPane(*(MLyt **)(param_1 + 0x48),"SCRATCH_PRIZE_MARK",(char *)0x0,
                              (char *)0x0);
  uVar6 = *(undefined4 *)(iVar2 + 0x54);
  uVar7 = *(undefined4 *)(iVar2 + 100);
  MoveVBase::stop((MoveVBase *)(param_1 + 0xe7dc));
  *(undefined4 *)(param_1 + 0xe7f8) = uVar6;
  *(undefined4 *)(param_1 + 0xe7fc) = uVar7;
  *(undefined4 *)(param_1 + 0xe800) = 0x43340000;
  *(undefined4 *)(param_1 + 0xe7e0) = uVar6;
  *(undefined4 *)(param_1 + 0xe7e4) = uVar7;
  *(undefined4 *)(param_1 + 0xe7e8) = 0x43340000;
  if (-1 < *(char *)(param_1 + 0x338)) {
    cVar1 = *(char *)((int)*(char *)(param_1 + 0x338) + param_1 + 0x755d);
    if (cVar1 == '\0') {
      uVar4 = 0x35;
    }
    else {
      if (cVar1 != '\x01' && cVar1 != '\x02') goto LAB_1700739c;
      uVar4 = 0x36;
    }
    msys::MDfxChr::playDfx((MDfxChr *)(param_1 + 0xe710),uVar4);
  }
LAB_1700739c:
  if (*(int *)(param_1 + 0xe864) != 0) {
    *(undefined2 *)(*(int *)(param_1 + 0xe864) + 0xf2) = 0xffff;
  }
  *(code **)(param_1 + 0x20) = FUN_17007098;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


// FUNC 0x17007404 FUN_17007404 (ShopMenu)
//   size 0xc0 | file ShopMenu+0x7404 | callers(0) | datarefs 2

void FUN_17007404(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = msys::MLyt::isEnableAnime(*(MLyt **)(param_1 + 0x44));
  if ((iVar2 == 0) && (iVar2 = msys::MLyt::isEnableAnime(*(MLyt **)(param_1 + 0x48)), iVar2 == 0)) {
    *(undefined1 *)(param_1 + 0x5f9) = 1;
    FUN_1700b110(param_1 + 0x334,0);
    FUN_1700a944(param_1,8);
    *(undefined2 *)(param_1 + *(short *)(param_1 + 0x7e) * 2 + 0x90) = 0x18;
    *(undefined1 *)(*(int *)(param_1 + 0x58) + 0x18) = 0x18;
    msys::MCursorBase::setVisible(*(MCursorBase **)(param_1 + 0x58),true);
    FUN_1700ad98(*(undefined4 *)(param_1 + 0x58));
    iVar1 = msys::MComSys::_sys;
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar1;
    }
    *(undefined1 *)(iVar2 + 0xe6508) = 1;
    iVar1 = msys::MComSys::_sys;
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar1;
    }
    *(undefined1 *)(iVar2 + 0xe650a) = 1;
    *(code **)(param_1 + 0x20) = FUN_17005af8;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x170074f8 FUN_170074f8 (ShopMenu)
//   size 0xf0 | file ShopMenu+0x74f8 | callers(1) 0x17004e08

void FUN_170074f8(int param_1)

{
  int iVar1;
  ushort *puVar2;
  uint unaff_r5;
  uint unaff_r6;
  
  iVar1 = msys::MComSys::_sys;
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  else {
    iVar1 = *(int *)(param_1 + 8);
  }
  *(undefined1 *)(iVar1 + 0xe6508) = 0;
  puVar2 = (ushort *)shop::GetBootInfo();
  switch((&DAT_1701674b)[(*puVar2 & 0xffff0fff) * 4]) {
  case 1:
  case 5:
    unaff_r6 = 3;
    unaff_r5 = 4;
    break;
  case 2:
  case 6:
    unaff_r6 = 1;
    unaff_r5 = 1;
    break;
  case 3:
    unaff_r6 = 5;
    unaff_r5 = 6;
    break;
  case 4:
    unaff_r6 = 7;
    unaff_r5 = 8;
  }
  msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x44),0,0,(char *)0x0,(char *)0x0);
  msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x44),unaff_r6,1,(char *)0x0,(char *)0x0);
  msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x48),0,0,(char *)0x0,(char *)0x0);
  msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x48),unaff_r5,1,(char *)0x0,(char *)0x0);
  *(code **)(param_1 + 0x20) = FUN_17004310;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


// FUNC 0x1700789c FUN_1700789c (ShopMenu)
//   size 0x208 | file ShopMenu+0x789c | callers(1) 0x17007c74

void FUN_1700789c(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)FUN_1700a0e8();
  *puVar1 = &shop::ShopMenu_TopPage::Core::vtable;
  *(undefined2 *)((int)puVar1 + 0x7e) = 0;
  puVar1[0x26] = 0;
  puVar1[0x27] = 0x3f800000;
  puVar1[0x28] = 0;
  *(undefined2 *)(puVar1 + 0x29) = 1;
  *(undefined2 *)((int)puVar1 + 0xa6) = 0;
  puVar1 = (undefined4 *)FUN_1700c0a0(puVar1 + 0x2c);
  *puVar1 = &msys::MCellAnime::vtable;
  iVar2 = CellAnime::CellAnime((CellAnime *)(puVar1 + 0x53));
  *(undefined1 *)(iVar2 + 300) = 0xff;
  *(undefined1 *)(iVar2 + 0x12d) = 0xff;
  *(undefined1 *)(iVar2 + 0x12e) = 0xff;
  *(undefined1 *)(iVar2 + 0x12f) = 0xff;
  iVar2 = msys::MDfxChr::MDfxChr((MDfxChr *)(iVar2 + 0x140));
  puVar1 = (undefined4 *)FUN_1700c0a0(iVar2 + 0x17c);
  *puVar1 = &msys::MMsg::vtable;
  iVar2 = MessageSimple::MessageSimple((MessageSimple *)(puVar1 + 0x53));
  *(undefined4 *)(iVar2 + 0x6ae0) = 0;
  *(undefined1 *)(iVar2 + 0x6ae4) = 0;
  *(undefined1 *)(iVar2 + 0x6ae5) = 0;
  *(undefined4 *)(iVar2 + 0x6ae8) = 0;
  *(undefined4 *)(iVar2 + 0x6aec) = 0;
  *(undefined4 *)(iVar2 + 0x6af4) = 0x400;
  iVar2 = msys::MLytNum::MLytNum((MLytNum *)(iVar2 + 0x6af8));
  iVar2 = msys::MLytNum::MLytNum((MLytNum *)(iVar2 + 0x230));
  iVar2 = FUN_1700b0a8(iVar2 + 0x248);
  Mem::Fill((void *)(iVar2 + -0x17),0,0x14);
  iVar2 = msys::MDfxChr::MDfxChr((MDfxChr *)(iVar2 + 0x7c));
  iVar2 = FUN_1700b0a8(iVar2 + 0x17c);
  puVar1 = (undefined4 *)FUN_1700c0a0(iVar2 + 0x24);
  *puVar1 = &msys::MMsgWnd::vtable;
  iVar2 = Message::Message((Message *)(puVar1 + 0x53));
  *(undefined4 *)(iVar2 + 28000) = 0;
  *(undefined4 *)(iVar2 + 0x6d64) = 0x400;
  *(undefined4 *)(iVar2 + 0x6d68) = 0;
  *(undefined4 *)(iVar2 + 0x6d6c) = 0;
  *(undefined4 *)(iVar2 + 0x6d70) = 0;
  *(undefined4 *)(iVar2 + 0x6d78) = 6;
  *(undefined4 *)(iVar2 + 0x6d74) = 0;
  *(undefined4 *)(iVar2 + 0x6d7c) = 0;
  *(undefined1 *)(iVar2 + 0x6d80) = 0;
  *(undefined4 *)(iVar2 + 0x6d84) = 0;
  *(undefined4 *)(iVar2 + 0x6d88) = 0;
  *(undefined1 *)(iVar2 + 0x6d8c) = 1;
  *(undefined1 *)(iVar2 + 0x6d8d) = 0;
  *(undefined1 *)(iVar2 + 0x6d8e) = 0;
  *(undefined4 *)(iVar2 + 0x6d90) = 0;
  *(undefined4 *)(iVar2 + 0x6d94) = 0x110003;
  *(undefined4 *)(iVar2 + 0x6d98) = 0x110004;
  *(undefined4 *)(iVar2 + 0x6da0) = 0;
  *(undefined4 *)(iVar2 + 0x6da4) = 0;
  *(undefined4 *)(iVar2 + 0x6da8) = 0x400;
  *(undefined4 *)(iVar2 + 0x6dac) = 0;
  *(undefined4 *)(iVar2 + 0x6db0) = 0x400;
  *(undefined4 *)(iVar2 + 0x6db4) = 0;
  *(undefined4 *)(iVar2 + 0x6db8) = 0;
  *(undefined4 *)(iVar2 + 0x6dbc) = 0;
  *(undefined4 *)(iVar2 + 0x6dc4) = 6;
  *(undefined4 *)(iVar2 + 0x6dc0) = 0;
  *(undefined4 *)(iVar2 + 0x6dc8) = 0;
  *(undefined1 *)(iVar2 + 0x6dcc) = 0;
  *(undefined4 *)(iVar2 + 0x6dd0) = 0;
  *(undefined4 *)(iVar2 + 0x6dd4) = 0;
  *(undefined1 *)(iVar2 + 0x6dd8) = 1;
  *(undefined1 *)(iVar2 + 0x6dd9) = 0;
  *(undefined1 *)(iVar2 + 0x6dda) = 0;
  *(undefined4 *)(iVar2 + 0x6ddc) = 0;
  *(undefined4 *)(iVar2 + 0x6de0) = 0x110003;
  *(undefined4 *)(iVar2 + 0x6de4) = 0x110004;
  iVar2 = msys::MDfxChr::MDfxChr((MDfxChr *)(iVar2 + 0x6e34));
  *(undefined2 *)(iVar2 + -0xe690) = 0xffff;
  *(undefined2 *)(iVar2 + -0xe68e) = 0xffff;
  *(undefined2 *)(iVar2 + -0xe688) = 0xffff;
  *(undefined2 *)(iVar2 + -0xe686) = 0xffff;
  *(undefined2 *)(iVar2 + -0xe680) = 0xffff;
  *(undefined2 *)(iVar2 + -0xe67e) = 0xffff;
  *(undefined1 *)(iVar2 + -5) = 0;
  *(undefined1 **)(iVar2 + -0xe700) = &LAB_170074dc;
  *(undefined4 *)(iVar2 + -0xe6fc) = 0;
  *(undefined1 **)(iVar2 + -0xe6f8) = &LAB_17007778;
  *(undefined4 *)(iVar2 + -0xe6f4) = 0;
  *(code **)(iVar2 + -0xe6f0) = FUN_17005c08;
  *(undefined4 *)(iVar2 + -0xe6ec) = 0;
  return;
}


// FUNC 0x17007ac4 shop::ShopMenu_TopPage::Core::vfunc_0x4 (ShopMenu)
//   size 0x10 | file ShopMenu+0x7ac4 | callers(0) | datarefs 1

void shop::ShopMenu_TopPage::Core::vfunc_0x4(void)

{
  void *pvVar1;
  
  pvVar1 = (void *)vfunc_0x0();
  operator_delete(pvVar1);
  return;
}


// FUNC 0x17007ad4 shop::ShopMenu_TopPage::Core::vfunc_0x0 (ShopMenu)
//   size 0x180 | file ShopMenu+0x7ad4 | callers(1) 0x17007ac4 | datarefs 1

undefined4 * shop::ShopMenu_TopPage::Core::vfunc_0x0(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  *param_1 = &vtable;
  iVar1 = msys::MDfxChr::~MDfxChr((MDfxChr *)(param_1 + 0x39c4));
  *(undefined ***)(iVar1 + -0x6f80) = &msys::MMsgWnd::vtable;
  Message::term((Message *)(iVar1 + -0x6e34));
  iVar1 = Message::~Message((Message *)(iVar1 + -0x6e34));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  piVar2 = (int *)(iVar1 + -0x19c);
  piVar3 = *(int **)(iVar1 + -0x198);
  if (piVar3 != piVar2) {
    *(int **)(*piVar2 + 4) = piVar3;
    *piVar3 = *piVar2;
    if (piVar2 != (int *)0x0) {
      *piVar2 = (int)piVar2;
      *(int **)(iVar1 + -0x198) = piVar2;
    }
  }
  *(undefined4 *)(iVar1 + -0x18) = 0;
  iVar1 = msys::MDfxChr::~MDfxChr((MDfxChr *)(iVar1 + -0x1a0));
  piVar2 = (int *)(iVar1 + -0x72b0);
  piVar3 = *(int **)(iVar1 + -0x72ac);
  if (piVar3 != piVar2) {
    *(int **)(*piVar2 + 4) = piVar3;
    *piVar3 = *piVar2;
    if (piVar2 != (int *)0x0) {
      *piVar2 = (int)piVar2;
      *(int **)(iVar1 + -0x72ac) = piVar2;
    }
  }
  *(undefined4 *)(iVar1 + -0x70) = 0;
  iVar1 = msys::MLytNum::~MLytNum((MLytNum *)(iVar1 + -0x2c4));
  iVar1 = msys::MLytNum::~MLytNum((MLytNum *)(iVar1 + -0x230));
  *(undefined ***)(iVar1 + -0x6c44) = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar1 = MessageSimple::~MessageSimple((MessageSimple *)(iVar1 + -0x6af8));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  iVar1 = msys::MDfxChr::~MDfxChr((MDfxChr *)(iVar1 + -0x17c));
  *(undefined ***)(iVar1 + -0x28c) = &msys::MCellAnime::vtable;
  iVar1 = CellAnime::~CellAnime((CellAnime *)(iVar1 + -0x140));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  *(undefined4 *)(iVar1 + -0x10) = 0;
  *(undefined4 *)(iVar1 + -0xb0) = &ShopMenu_PageBase::Core::vtable;
  Mem::Free(*(void **)(iVar1 + -0x7c));
  *(undefined ***)(iVar1 + -0x88) = &MemAlcH::vtable;
  *(undefined4 *)(iVar1 + -0x7c) = 0;
  Mem::Free((void *)0x0);
  *(undefined ***)(iVar1 + -0x88) = &MemAlc::vtable;
  *(undefined4 *)(iVar1 + -0x7c) = 0;
  return (undefined4 *)(iVar1 + -0xb0);
}


// FUNC 0x17007c74 shop::ShopMenu_TopPage::vfunc_0x30 (ShopMenu)
//   size 0x30 | file ShopMenu+0x7c74 | callers(0) | datarefs 1

void shop::ShopMenu_TopPage::vfunc_0x30(int param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(0xe930,*(MemAlcBase **)(param_1 + 0x18),(char *)0x0,0);
  uVar2 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_1700789c(pvVar1,param_1);
  }
  *(undefined4 *)(param_1 + 0x20) = uVar2;
  return;
}


// FUNC 0x17007ca8 shop::ShopMenu_TopPage::vfunc_0x24 (ShopMenu)
//   size 0x8 | file ShopMenu+0x7ca8 | callers(0) | datarefs 1

undefined4 shop::ShopMenu_TopPage::vfunc_0x24(void)

{
  return 0;
}


// FUNC 0x17007cb0 shop::ShopMenu_TopPage::vfunc_0x4 (ShopMenu)
//   size 0x10 | file ShopMenu+0x7cb0 | callers(0) | datarefs 1

void shop::ShopMenu_TopPage::vfunc_0x4(void)

{
  void *pvVar1;
  
  pvVar1 = (void *)ShopMenu_PageBase::vfunc_0x0();
  operator_delete(pvVar1);
  return;
}


// FUNC 0x17007cc0 FUN_17007cc0 (ShopMenu)
//   size 0xb0 | file ShopMenu+0x7cc0 | callers(0)

void FUN_17007cc0(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  
  iVar1 = msys::MLyt::getPane((MLyt *)(param_2 + 0xea034),"BLOCK_13",(char *)0x0,(char *)0x0);
  param_1[0x68] = iVar1;
  msys::MDfxChr::init((MDfxChr *)(param_1 + 2),
                      *(MemAlcBase **)
                       (*(int *)(param_2 + *(char *)((int)*(char *)(param_2 + 0xfd7) +
                                                    param_2 + 0xfcd) * 4 + 0xf8c) + 0x18),
                      *(MDfxSys **)(param_2 + 0xe64f0),(Scene *)(param_2 + 0x4aba4),0x400);
  piVar3 = param_1 + 3;
  param_1[0x51] = 0x400;
  piVar4 = (int *)param_1[4];
  piVar2 = (int *)(param_2 + 0xe64d8);
  *(int **)(*piVar3 + 4) = piVar4;
  *piVar4 = *piVar3;
  if (param_1 + 0x51 != (int *)0x0) {
    iVar1 = *piVar2;
    param_1[4] = (int)piVar2;
    *piVar3 = iVar1;
    *(int **)(iVar1 + 4) = piVar3;
    *piVar2 = (int)piVar3;
  }
  *param_1 = param_2;
  *(undefined1 *)(param_1 + 1) = 0xff;
  return;
}


// FUNC 0x17007d8c FUN_17007d8c (ShopMenu)
//   size 0x50 | file ShopMenu+0x7d8c | callers(0)

void FUN_17007d8c(int *param_1)

{
  int iVar1;
  
  *(undefined1 *)(param_1 + 0x69) = 0;
  iVar1 = msys::MLyt::getPane((MLyt *)(*param_1 + 0xea034),"SCRATCH_PRIZE_MARK",(char *)0x0,
                              (char *)0x0);
  *(byte *)(iVar1 + 0x44) = *(byte *)(iVar1 + 0x44) & 0xfe;
  *(byte *)(param_1[0x68] + 0x44) = *(byte *)(param_1[0x68] + 0x44) & 0xfe | 1;
  return;
}


// FUNC 0x17007e04 shop::ShopMenu_PageBase::Core::vfunc_0x8 (ShopMenu)
//   size 0xe4 | file ShopMenu+0x7e04 | callers(0) | datarefs 2

int shop::ShopMenu_PageBase::Core::vfunc_0x8(int *param_1,MInput *param_2)

{
  MInput MVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  code *extraout_r2;
  code *pcVar6;
  undefined4 *puVar7;
  bool bVar8;
  uint in_fpscr;
  undefined4 local_20;
  undefined4 uStack_1c;
  
  msys::MPageBase::updateInputAllChr((MPageBase *)param_1[1],param_2);
  bVar8 = (param_1[9] & 1U) == 0;
  pcVar6 = extraout_r2;
  if (bVar8) {
    pcVar6 = (code *)param_1[8];
  }
  piVar3 = (int *)((int)param_1 + (param_1[9] >> 1));
  if (!bVar8) {
    pcVar6 = *(code **)(*piVar3 + param_1[8]);
  }
  (*pcVar6)(piVar3,param_2);
  MVar1 = param_2[0x11];
  bVar8 = MVar1 == (MInput)0x0;
  if (bVar8) {
    MVar1 = param_2[0x12];
  }
  puVar7 = (undefined4 *)(undefined1 *)0x0;
  if (!bVar8 || MVar1 != (MInput)0x0) {
    uStack_1c = VectorSignedToFloat(0x78 - (uint)*(ushort *)(param_2 + 0x16),
                                    (byte)(in_fpscr >> 0x16) & 3);
    local_20 = VectorSignedToFloat(*(ushort *)(param_2 + 0x14) - 0xa0,(byte)(in_fpscr >> 0x16) & 3);
    puVar7 = &local_20;
  }
  uVar4 = (**(code **)(*param_1 + 0xc))(param_1,param_2);
  iVar2 = msys::MComSys::_sys;
  iVar5 = param_1[2];
  if (param_1[2] == 0) {
    param_1[2] = msys::MComSys::_sys;
    iVar5 = iVar2;
  }
  (**(code **)(*(int *)param_1[0x10] + 8))
            ((int *)param_1[0x10],puVar7,(int)*(char *)(iVar5 + 0xe6508) & uVar4);
  return (int)*(char *)((int)param_1 + 0x7d);
}


// FUNC 0x17007eec shop::ShopMenu_PageBase::Core::vfunc_0x4 (ShopMenu)
//   size 0x4c | file ShopMenu+0x7eec | callers(0) | datarefs 1

void shop::ShopMenu_PageBase::Core::vfunc_0x4(undefined4 *param_1)

{
  *param_1 = &vtable;
  Mem::Free((void *)param_1[0xd]);
  param_1[0xd] = 0;
  param_1[10] = &MemAlcH::vtable;
  Mem::Free((void *)0x0);
  param_1[10] = &MemAlc::vtable;
  param_1[0xd] = 0;
  operator_delete(param_1);
  return;
}


// FUNC 0x17007f44 shop::ShopMenu_PageBase::Core::vfunc_0x0 (ShopMenu)
//   size 0x48 | file ShopMenu+0x7f44 | callers(0) | datarefs 1

undefined4 * shop::ShopMenu_PageBase::Core::vfunc_0x0(undefined4 *param_1)

{
  *param_1 = &vtable;
  Mem::Free((void *)param_1[0xd]);
  param_1[0xd] = 0;
  param_1[10] = &MemAlcH::vtable;
  Mem::Free((void *)0x0);
  param_1[10] = &MemAlc::vtable;
  param_1[0xd] = 0;
  return param_1;
}


// FUNC 0x17007f98 shop::ShopMenu_PageBase::vfunc_0x28 (ShopMenu)
//   size 0x14 | file ShopMenu+0x7f98 | callers(0) | datarefs 6

int shop::ShopMenu_PageBase::vfunc_0x28(int param_1,int param_2)

{
  return *(int *)(param_1 + 0x20) + param_2 * 4 + 0xc;
}


// FUNC 0x17007fac shop::ShopMenu_PageBase::vfunc_0x8 (ShopMenu)
//   size 0x6c | file ShopMenu+0x7fac | callers(0) | datarefs 6

void shop::ShopMenu_PageBase::vfunc_0x8(int *param_1,undefined1 param_2)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  if (param_1[8] == 0) {
    (**(code **)(*param_1 + 0x2c))(param_1);
    (**(code **)(*param_1 + 0x30))(param_1);
    *(undefined1 *)(param_1[8] + 0x7c) = param_2;
  }
  iVar1 = param_1[8];
  if ((*(uint *)(iVar1 + 0x14) & 1) == 0) {
    UNRECOVERED_JUMPTABLE = *(code **)(iVar1 + 0x10);
  }
  else {
    UNRECOVERED_JUMPTABLE =
         *(code **)(*(int *)(iVar1 + ((int)*(uint *)(iVar1 + 0x14) >> 1)) + *(int *)(iVar1 + 0x10));
  }
                    /* WARNING: Could not recover jumptable at 0x17008014. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// FUNC 0x17008018 shop::ShopMenu_PageBase::vfunc_0x14 (ShopMenu)
//   size 0x10 | file ShopMenu+0x8018 | callers(0) | datarefs 6

void shop::ShopMenu_PageBase::vfunc_0x14(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x17008024. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(param_1 + 0x20) + 8))();
  return;
}


// FUNC 0x17008028 shop::ShopMenu_PageBase::vfunc_0xc (ShopMenu)
//   size 0xd8 | file ShopMenu+0x8028 | callers(0) | datarefs 6

void shop::ShopMenu_PageBase::vfunc_0xc(int param_1)

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


// FUNC 0x17008100 shop::ShopMenu_PageBase::vfunc_0x4 (ShopMenu)
//   size 0x10 | file ShopMenu+0x8100 | callers(0) | datarefs 1

void shop::ShopMenu_PageBase::vfunc_0x4(void)

{
  void *pvVar1;
  
  pvVar1 = (void *)vfunc_0x0();
  operator_delete(pvVar1);
  return;
}


// FUNC 0x17008110 FUN_17008110 (ShopMenu)
//   size 0x84 | file ShopMenu+0x8110 | callers(1) 0x170144fc

int FUN_17008110(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)FUN_1700c0a0();
  *puVar1 = &msys::MLyt::vtable;
  *(undefined1 *)(puVar1 + 0x53) = 0xff;
  *(undefined2 *)((int)puVar1 + 0x14e) = 0;
  puVar1[0x54] = 0;
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(puVar1 + 0x55,FUN_1700b0a8,0x1c,0xc);
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(iVar2 + 0x15c,&LAB_17001398,0x10,0xc);
  *(undefined4 *)(iVar2 + 0xc0) = 0;
  *(undefined1 *)(iVar2 + 0xc4) = 1;
  *(undefined4 *)(iVar2 + 200) = 0;
  *(undefined4 *)(iVar2 + 0xcc) = 0;
  *(undefined1 *)(iVar2 + 0xd0) = 0;
  *(undefined4 *)(iVar2 + 0xd4) = 0;
  *(undefined4 *)(iVar2 + 0xd8) = 0;
  FUN_17014d6c(iVar2 + -0xc,0xffffffff);
  return iVar2 + -0x2b0;
}


// FUNC 0x170081a0 FUN_170081a0 (ShopMenu)
//   size 0xa0 | file ShopMenu+0x81a0 | callers(1) 0x17012c3c

void FUN_170081a0(TaskBase *param_1,Resource *param_2,FileContext *param_3,char *param_4,
                 MemAlcBase *param_5,uint param_6,VramAlcBase *param_7,uint param_8,
                 ResCacheArg *param_9)

{
  char *pcVar1;
  char acStackY_100 [128];
  uint *in_stack_ffffff80;
  TransMultiSymbol aTStack_5c [44];
  undefined4 local_30;
  
  local_30 = *(undefined4 *)(param_3 + 0x24);
  ad::TransMultiSymbol::init(aTStack_5c,param_4);
  BinGlu4Acs::getEntryAcs(acStackY_100 + 0x80);
  pcVar1 = (char *)(*(int *)(param_3 + 0x24) + (*in_stack_ffffff80 & 0x3fffffff));
  ad::fw::TaskBase::readCA
            (param_1,param_2,param_3,param_4,pcVar1,pcVar1 + 4,pcVar1 + 8,pcVar1 + 0xc,param_5,
             param_6,param_7,param_8,param_9);
  return;
}


// FUNC 0x17008240 FUN_17008240 (ShopMenu)
//   size 0x78 | file ShopMenu+0x8240 | callers(6) 0x17011930 0x170112a4 0x17011fe4 0x170115ec 0x17011d98 0x170121ec

void FUN_17008240(int param_1,int param_2)

{
  int *piVar1;
  uint uVar2;
  
  if (param_2 == 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x78) + 0x48) = 0;
  }
  (**(code **)(**(int **)(param_1 + 0x78) + 0x28))(*(int **)(param_1 + 0x78),param_2 == 0);
  uVar2 = 0;
  do {
    piVar1 = *(int **)(param_1 + uVar2 * 4 + 0x77cc);
    (**(code **)(*piVar1 + 0x28))(piVar1,param_2 == 1);
    uVar2 = uVar2 + 1 & 0xff;
  } while (uVar2 < 2);
  return;
}


// FUNC 0x170082b8 FUN_170082b8 (ShopMenu)
//   size 0x154 | file ShopMenu+0x82b8 | callers(2) 0x170112a4 0x17011780

void FUN_170082b8(int param_1,ushort param_2)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  ushort *puVar4;
  int iVar5;
  
  FUN_1700979c(*(undefined4 *)(param_1 + 100));
  iVar5 = *(int *)(param_1 + 0x60);
  iVar3 = GameWork::getItemNum((GameWork *)&gGameWork,param_2);
  ad::lyt::LytNumReel3::setValueInstant((LytNumReel3 *)(iVar5 + 0x6d94),iVar3);
  puVar4 = (ushort *)msys::MListWndPBase::getCurItem();
  iVar3 = ad::db::GetUseItem(*puVar4);
  uVar1 = *(ushort *)(iVar3 + 0x6a);
  if ((uVar1 & 0x20) == 0) {
    msys::StatusPanel::resetHi(*(StatusPanel **)(param_1 + 0x68));
    msys::StatusPanel::resetHi((StatusPanel *)(*(int *)(param_1 + 0x68) + 0x2034));
    msys::StatusPanel::resetHi((StatusPanel *)(*(int *)(param_1 + 0x68) + 0x4068));
    return;
  }
  uVar2 = uVar1 >> 9;
  if (uVar2 == 0) {
    msys::StatusPanel::setHi(*(StatusPanel **)(param_1 + 0x68),uVar1 & 0x1f);
    msys::StatusPanel::setHi
              ((StatusPanel *)(*(int *)(param_1 + 0x68) + 0x2034),*(byte *)(iVar3 + 0x6a) & 0x1f);
    msys::StatusPanel::setHi
              ((StatusPanel *)(*(int *)(param_1 + 0x68) + 0x4068),*(byte *)(iVar3 + 0x6a) & 0x1f);
    return;
  }
  if (uVar2 == 1) {
    msys::StatusPanel::setHi(*(StatusPanel **)(param_1 + 0x68),uVar1 & 0x1f);
    msys::StatusPanel::setHi
              ((StatusPanel *)(*(int *)(param_1 + 0x68) + 0x2034),*(byte *)(iVar3 + 0x6a) & 0x1f);
    msys::StatusPanel::setLow((StatusPanel *)(*(int *)(param_1 + 0x68) + 0x4068));
    return;
  }
  if (uVar2 == 2) {
    msys::StatusPanel::setLow(*(StatusPanel **)(param_1 + 0x68));
    msys::StatusPanel::setLow((StatusPanel *)(*(int *)(param_1 + 0x68) + 0x2034));
    msys::StatusPanel::setHi
              ((StatusPanel *)(*(int *)(param_1 + 0x68) + 0x4068),*(byte *)(iVar3 + 0x6a) & 0x1f);
    return;
  }
  return;
}


// FUNC 0x17008410 FUN_17008410 (ShopMenu)
//   size 0xa8 | file ShopMenu+0x8410 | callers(1) 0x1701042c

void FUN_17008410(MoveVBase *param_1,int param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  CellAnime::play((CellAnime *)(param_1 + 0x1b0),*(uchar *)(param_2 + 0xb),0,1.0);
  msys::MMsg::playStr((MMsg *)(param_1 + 0x2e0),*(wchar_t **)(param_2 + 0x10),(InsParam *)0x0,false)
  ;
  uVar3 = *param_3;
  uVar4 = param_3[1];
  MoveVBase::stop(param_1);
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x1c) = uVar3;
  *(undefined4 *)(param_1 + 0x20) = uVar4;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 4) = uVar3;
  *(undefined4 *)(param_1 + 8) = uVar4;
  iVar2 = *(int *)(param_1 + 0x60);
  puVar1 = (undefined4 *)MoveVBase::update(param_1,1.0);
  uVar3 = puVar1[1];
  uVar4 = puVar1[2];
  *(undefined4 *)(iVar2 + 0x1c) = *puVar1;
  *(undefined4 *)(iVar2 + 0x20) = uVar3;
  *(undefined4 *)(iVar2 + 0x24) = uVar4;
  *(byte *)(iVar2 + 0x44) = *(byte *)(iVar2 + 0x44) & 0xef | 0x10;
  *(undefined1 *)(*(int *)(param_1 + 0x5c) + 0x374) = 1;
  return;
}


// FUNC 0x170084c0 FUN_170084c0 (ShopMenu)
//   size 0x38 | file ShopMenu+0x84c0 | callers(4) 0x1701042c 0x170107fc 0x17010894 0x17010b64

void FUN_170084c0(int param_1,byte param_2)

{
  *(byte *)(*(int *)(param_1 + 0x6e20) + 0x44) =
       *(byte *)(*(int *)(param_1 + 0x6e20) + 0x44) & 0xfe | param_2;
  *(byte *)(*(int *)(param_1 + 0xdd44) + 0x44) =
       param_2 | *(byte *)(*(int *)(param_1 + 0xdd44) + 0x44) & 0xfe;
  return;
}


// FUNC 0x170084fc FUN_170084fc (ShopMenu)
//   size 0xbc | file ShopMenu+0x84fc | callers(2) 0x1701004c 0x17010148

void FUN_170084fc(float param_1,MoveVBase *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  
  uVar3 = *param_3;
  if (param_1 == 0.0) {
    uVar2 = param_3[1];
    MoveVBase::stop(param_2);
    *(undefined4 *)(param_2 + 0x1c) = uVar3;
    *(undefined4 *)(param_2 + 0x20) = uVar2;
    *(undefined4 *)(param_2 + 0x24) = 0;
    *(undefined4 *)(param_2 + 4) = uVar3;
    *(undefined4 *)(param_2 + 8) = uVar2;
    *(undefined4 *)(param_2 + 0xc) = 0;
  }
  else {
    MoveVBase::moveSinAbs((VEC3 *)param_2,param_1);
  }
  *(byte *)(*(int *)(param_2 + 0x60) + 0x44) = *(byte *)(*(int *)(param_2 + 0x60) + 0x44) & 0xfe | 1
  ;
  iVar4 = *(int *)(param_2 + 0x60);
  puVar1 = (undefined4 *)MoveVBase::update(param_2,1.0);
  uVar3 = puVar1[1];
  uVar2 = puVar1[2];
  *(undefined4 *)(iVar4 + 0x1c) = *puVar1;
  *(undefined4 *)(iVar4 + 0x20) = uVar3;
  *(undefined4 *)(iVar4 + 0x24) = uVar2;
  *(byte *)(iVar4 + 0x44) = *(byte *)(iVar4 + 0x44) & 0xef | 0x10;
  *(undefined1 *)(*(int *)(param_2 + 0x5c) + 0x374) = 1;
  return;
}


// FUNC 0x170085c0 FUN_170085c0 (ShopMenu)
//   size 0xc8 | file ShopMenu+0x85c0 | callers(2) 0x17010148 0x1700fc24

undefined4 FUN_170085c0(int param_1,int param_2,uint param_3)

{
  bool bVar1;
  short sVar2;
  int iVar3;
  int *piVar4;
  uint in_fpscr;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  
  sVar2 = *(short *)(param_1 + 0x84);
  if (sVar2 != 0) {
    param_3 = (uint)*(byte *)(param_2 + 0x11);
  }
  if (sVar2 != 0 && param_3 != 0) {
    if (sVar2 == 1) {
      iVar3 = *(int *)(param_1 + 0x22e7c);
    }
    else {
      iVar3 = *(int *)(param_1 + 0x22e78);
    }
    piVar4 = *(int **)(*(int *)(iVar3 + 0xac) + 0x10);
    iVar3 = (**(code **)(*piVar4 + 0x2c))(piVar4,&DAT_17008688,1);
    fVar8 = *(float *)(iVar3 + 0x3c) * 0.5;
    fVar7 = *(float *)(iVar3 + 0x40) * 0.5;
    fVar5 = (float)VectorSignedToFloat(*(ushort *)(param_2 + 0x14) - 0xa0,
                                       (byte)(in_fpscr >> 0x16) & 3);
    fVar6 = (float)VectorSignedToFloat(0x78 - (uint)*(ushort *)(param_2 + 0x16),
                                       (byte)(in_fpscr >> 0x16) & 3);
    bVar1 = *(float *)(iVar3 + 0x54) - fVar8 < fVar5;
    if ((bVar1 && (bVar1 && fVar5 < *(float *)(iVar3 + 0x54) + fVar8)) &&
       (bVar1 = *(float *)(iVar3 + 100) - fVar7 < fVar6,
       bVar1 && (bVar1 && fVar6 < *(float *)(iVar3 + 100) + fVar7))) {
      return 1;
    }
  }
  return 0;
}


// FUNC 0x17008690 FUN_17008690 (ShopMenu)
//   size 0x164 | file ShopMenu+0x8690 | callers(2) 0x1700f458 0x1700f718

void FUN_17008690(int param_1)

{
  ushort *puVar1;
  int iVar2;
  int *piVar3;
  char *local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined1 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined1 local_20;
  undefined1 local_1f;
  undefined1 local_1e;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  FUN_1700beb8(msys::MComSys::_sys + 0x49368,0x110018,0,0,0);
  *(undefined4 *)(param_1 + 0x1bf70) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(param_1 + 0x1bf74) = *(undefined4 *)(param_1 + 0x24);
  local_48 = 0x400;
  local_4c = (char *)0x0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_34 = 6;
  local_38 = 0;
  local_30 = 0;
  local_20 = 1;
  local_2c = 0;
  local_28 = 0;
  local_1f = 0;
  local_24 = 0;
  local_1e = 0;
  local_14 = 0x110004;
  local_18 = 0x110003;
  local_1c = 0;
  msys::MListWndPBase::getListWnd(*(MListWndPBase **)(param_1 + 0x50));
  puVar1 = (ushort *)ad::ui::UIListWindowPlusLyt::getCurItem();
  iVar2 = ad::db::GetEquip(*puVar1);
  switch(*(undefined1 *)(iVar2 + 0x6a)) {
  case 1:
    local_4c = "MES_ShopMes_Menu_no_equip_pants";
    break;
  case 2:
    local_4c = "MES_ShopMes_Menu_no_equip_glove";
    break;
  case 3:
    local_4c = "MES_ShopMes_Menu_no_equip_boots";
    break;
  case 4:
    local_4c = "MES_ShopMes_Menu_no_equip_acce";
    break;
  case 6:
    local_4c = "MES_ShopMes_Menu_no_equip_bangle";
    break;
  case 7:
    local_4c = "MES_ShopMes_Menu_no_equip_kiba";
    break;
  case 8:
    local_4c = "MES_ShopMes_Menu_no_equip_ring";
  }
  local_18 = 0xffffffff;
  local_14 = 0xffffffff;
  local_20 = 0;
  Message::play((Message *)(param_1 + 0x1c0c4),(PlayParam *)&local_4c);
  iVar2 = 0;
  do {
    piVar3 = *(int **)(param_1 + iVar2 * 4 + 0x22e90);
    (**(code **)(*piVar3 + 0x28))(piVar3,0);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 2);
  *(code **)(param_1 + 0x20) = FUN_170106dc;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


// FUNC 0x17008910 FUN_17008910 (ShopMenu)
//   size 0x88 | file ShopMenu+0x8910 | callers(4) 0x1700f458 0x1700f718 0x17008df4 0x17008a74

uint FUN_17008910(int param_1,int param_2,ushort param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = ad::db::GetEquip(param_3);
  cVar1 = *(char *)(iVar3 + 0x6a);
  uVar4 = 0;
  while( true ) {
    iVar2 = msys::MComSys::_sys;
    iVar3 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar3 = iVar2;
    }
    iVar3 = DataPc::getEquip((DataPc *)(iVar3 + param_2 * 0xb0 + 0xe9e10),(uchar)uVar4);
    if ((iVar3 != 0) && (iVar3 = ad::db::GetEquip((ushort)iVar3), cVar1 == *(char *)(iVar3 + 0x6a)))
    break;
    uVar4 = uVar4 + 1 & 0xff;
    if (2 < uVar4) {
      return 0xffffffff;
    }
  }
  return uVar4;
}


// FUNC 0x1700899c FUN_1700899c (ShopMenu)
//   size 0xcc | file ShopMenu+0x899c | callers(3) 0x1700f204 0x17010148 0x1700fc24

void FUN_1700899c(int param_1,uint *param_2)

{
  undefined2 *puVar1;
  uint uVar2;
  int iVar3;
  undefined1 unaff_r5;
  
  FUN_1700beb8(msys::MComSys::_sys + 0x49368,0x110015,0,0);
  if ((ushort)DAT_17021c70 == *(ushort *)(param_1 + 0x82)) {
    iVar3 = 0;
  }
  else if ((ushort)DAT_17021c71 == *(ushort *)(param_1 + 0x82)) {
    iVar3 = 1;
  }
  else {
    iVar3 = 2;
  }
  if ((*param_2 & 0x200) == 0) {
    if ((*param_2 & 0x100) == 0) goto LAB_17008a24;
    uVar2 = iVar3 + 1;
    if (1 < uVar2) {
      uVar2 = 0;
    }
  }
  else {
    uVar2 = iVar3 - 1;
    if ((int)uVar2 < 0) {
      uVar2 = 1;
    }
  }
  unaff_r5 = (&DAT_17021c70)[uVar2];
LAB_17008a24:
  FUN_17008b20(param_1,unaff_r5);
  msys::MListWndPBase::getListWnd(*(MListWndPBase **)(param_1 + 0x50));
  puVar1 = (undefined2 *)ad::ui::UIListWindowPlusLyt::getCurItem();
  FUN_17008df4(param_1,*puVar1);
  FUN_17008f64(param_1,0);
  return;
}


// FUNC 0x17008a74 FUN_17008a74 (ShopMenu)
//   size 0xa4 | file ShopMenu+0x8a74 | callers(4) 0x1701042c 0x1700f088 0x17010148 0x1700fc24

void FUN_17008a74(int param_1,undefined4 *param_2)

{
  undefined2 *puVar1;
  int iVar2;
  undefined4 uVar3;
  byte bVar4;
  
  puVar1 = (undefined2 *)msys::MListWndPBase::getCurItem();
  FUN_17008910(param_1,*(undefined1 *)(param_1 + 0x82),*puVar1);
  iVar2 = *(int *)(param_1 + 0x22e78);
  bVar4 = *(byte *)(iVar2 + 0x44) & 0xfe;
  if (*(short *)(param_1 + 0x84) == 0) {
    *(byte *)(iVar2 + 0x44) = bVar4;
    *(byte *)(*(int *)(param_1 + 0x22e7c) + 0x44) =
         *(byte *)(*(int *)(param_1 + 0x22e7c) + 0x44) & 0xfe;
    *param_2 = 0;
    param_2[1] = 0x42300000;
    return;
  }
  *(byte *)(iVar2 + 0x44) = bVar4 | 1;
  *(byte *)(*(int *)(param_1 + 0x22e7c) + 0x44) =
       *(byte *)(*(int *)(param_1 + 0x22e7c) + 0x44) & 0xfe | 1;
  uVar3 = *(undefined4 *)(*(int *)(param_1 + *(short *)(param_1 + 0x84) * 4 + 0x22e74) + 100);
  *param_2 = 0;
  param_2[1] = uVar3;
  return;
}


// FUNC 0x17008b20 FUN_17008b20 (ShopMenu)
//   size 0x2b4 | file ShopMenu+0x8b20 | callers(2) 0x17010894 0x1700899c

void FUN_17008b20(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  ushort *puVar3;
  int iVar4;
  wchar_t *pwVar5;
  undefined4 uVar6;
  uint uVar7;
  StatusPanel *this;
  int *piVar8;
  DataPc *this_00;
  undefined8 uVar9;
  DataPc aDStack_e0 [180];
  
  iVar2 = msys::MComSys::_sys;
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  else {
    iVar2 = *(int *)(param_1 + 8);
  }
  this = *(StatusPanel **)(param_1 + 0x6c);
  this_00 = (DataPc *)(iVar2 + param_2 * 0xb0 + 0xe9e10);
  uVar9 = msys::MListWndPBase::getCurItem();
  uVar7 = (uint)((ulonglong)uVar9 >> 0x20);
  puVar3 = (ushort *)uVar9;
  if (puVar3 != (ushort *)0x0) {
    uVar7 = (uint)(byte)puVar3[7];
  }
  if (puVar3 == (ushort *)0x0 || uVar7 == 0) {
    msys::StatusPanel::setParam(this,this_00);
  }
  else {
    uVar1 = *puVar3;
    __aeabi_memcpy4(aDStack_e0,this_00,0xb0);
    DataPc::setEquip(aDStack_e0,uVar1,*(uchar *)(param_1 + 0x84));
    msys::StatusPanel::setNewEquipParam(this,this_00,aDStack_e0);
  }
  msys::StatusPanel::setParam(this,this_00);
  msys::StatusPanel::setChr(this,(uchar)param_2);
  uVar7 = 0;
  *(undefined1 *)(*(int *)(param_1 + 0x4c) + *(short *)(param_1 + 0x82) * 0x27c + 0x141) = 0;
  *(undefined1 *)(*(int *)(param_1 + 0x4c) + param_2 * 0x27c + 0x141) = 1;
  do {
    iVar2 = DataPc::getEquip(this_00,(uchar)uVar7);
    piVar8 = (int *)(*(int *)(param_1 + 0x70) + uVar7 * 0x6ee0);
    if (iVar2 == 0) {
      *(undefined1 *)((int)piVar8 + 0x6da5) = 0;
      iVar4 = *piVar8;
      uVar6 = LMS_GetTextIndexByLabel(iVar4 + 0xe93ec,"Menu_Sys_invalid_equip_name");
      pwVar5 = (wchar_t *)LMS_GetText(iVar4 + 0xe93ec,uVar6);
      msys::MMsg::playStr((MMsg *)(piVar8 + 8),pwVar5,(InsParam *)0x0,false);
    }
    else {
      *(undefined1 *)((int)piVar8 + 0x6da5) = 1;
      iVar4 = ad::db::GetItemData((ushort)iVar2);
      CellAnime::play((CellAnime *)(piVar8 + 0x1b6c),*(char *)(iVar4 + 0x60) + '\x01',0,1.0);
      pwVar5 = (wchar_t *)ad::db::GetItemMsg(iVar2,0);
      msys::MMsg::playStr((MMsg *)(piVar8 + 8),pwVar5,(InsParam *)0x0,false);
    }
    if (uVar7 != 0) {
      piVar8 = (int *)(*(int *)(param_1 + 0x74) + uVar7 * 0x6ec4 + -0x6ec4);
      if (iVar2 == 0) {
        *(undefined1 *)((int)piVar8 + 0x6d89) = 0;
        iVar2 = *piVar8;
        uVar6 = LMS_GetTextIndexByLabel(iVar2 + 0xe93ec,"Menu_Sys_invalid_equip_name");
        pwVar5 = (wchar_t *)LMS_GetText(iVar2 + 0xe93ec,uVar6);
        msys::MMsg::playStr((MMsg *)(piVar8 + 1),pwVar5,(InsParam *)0x0,false);
      }
      else {
        *(undefined1 *)((int)piVar8 + 0x6d89) = 1;
        iVar4 = ad::db::GetItemData((ushort)iVar2);
        CellAnime::play((CellAnime *)(piVar8 + 0x1b65),*(char *)(iVar4 + 0x60) + '\x01',0,1.0);
        pwVar5 = (wchar_t *)ad::db::GetItemMsg(iVar2,0);
        msys::MMsg::playStr((MMsg *)(piVar8 + 1),pwVar5,(InsParam *)0x0,false);
      }
    }
    uVar7 = uVar7 + 1 & 0xff;
  } while (uVar7 < 3);
  *(short *)(param_1 + 0x82) = (short)param_2;
  return;
}


// FUNC 0x17008df4 FUN_17008df4 (ShopMenu)
//   size 0x15c | file ShopMenu+0x8df4 | callers(6) 0x1700fef4 0x1700e770 0x1700f204 0x1700899c 0x17010148 0x1700fc24

void FUN_17008df4(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  DataPc aDStack_d0 [180];
  
  iVar2 = FUN_17008910(param_1,*(undefined1 *)(param_1 + 0x82),param_2);
  uVar4 = 0;
  do {
    if ((int)*(short *)(param_1 + 0x84) == uVar4) {
      ad::lyt::LytAnim::stopAndSetFrm
                ((LytAnim *)(*(int *)(param_1 + 0x70) + uVar4 * 0x6ee0 + 4),1.0);
    }
    else {
      ad::lyt::LytAnim::stopAndSetFrm
                ((LytAnim *)(*(int *)(param_1 + 0x70) + uVar4 * 0x6ee0 + 4),0.0);
    }
    uVar4 = uVar4 + 1 & 0xff;
  } while (uVar4 < 3);
  FUN_1700979c(*(undefined4 *)(param_1 + 100),param_2);
  iVar1 = msys::MComSys::_sys;
  iVar3 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar3 = iVar1;
  }
  __aeabi_memcpy4(aDStack_d0,iVar3 + *(short *)(param_1 + 0x82) * 0xb0 + 0xe9e10,0xb0);
  if ((iVar2 < 1) || (*(short *)(param_1 + 0x84) == iVar2)) {
    DataPc::setEquip(aDStack_d0,(ushort)param_2,*(uchar *)(param_1 + 0x84));
  }
  iVar3 = msys::MComSys::_sys;
  iVar2 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar2 = iVar3;
  }
  msys::StatusPanel::setNewEquipParam
            (*(StatusPanel **)(param_1 + 0x6c),
             (DataPc *)(iVar2 + *(short *)(param_1 + 0x82) * 0xb0 + 0xe9e10),aDStack_d0);
  iVar3 = *(int *)(param_1 + 0x60);
  iVar2 = GameWork::getItemNum((GameWork *)&gGameWork,(ushort)param_2);
  ad::lyt::LytNumReel3::setValueInstant((LytNumReel3 *)(iVar3 + 0x6d94),iVar2);
  return;
}


// FUNC 0x17008f64 FUN_17008f64 (ShopMenu)
//   size 0x130 | file ShopMenu+0x8f64 | callers(10) 0x1700f458 0x1700f718 0x1700e770 0x17010608 0x17010abc 0x1700f204 0x1700f088 0x17010148 ...

void FUN_17008f64(int param_1,int param_2)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  int *piVar4;
  byte bVar5;
  uint uVar6;
  undefined4 uVar7;
  bool bVar8;
  bool bVar9;
  
  uVar7 = 0;
  bVar5 = 0;
  bVar8 = false;
  bVar9 = false;
  iVar3 = msys::MListWndPBase::getCurItem();
  bVar2 = 0;
  if (iVar3 != 0) {
    cVar1 = *(char *)(param_1 + 0x84);
    msys::MListWndPBase::getCurItem();
    if (cVar1 == '\0') {
      bVar2 = 0;
    }
    else {
      bVar2 = 1;
    }
  }
  if (param_2 == 0) {
    uVar7 = 1;
    *(undefined4 *)(*(int *)(param_1 + 0x78) + 0x48) = 1;
    bVar5 = bVar2;
  }
  else {
    bVar8 = param_2 == 1;
    if (!bVar8) {
      bVar9 = param_2 == 2;
    }
  }
  (**(code **)(**(int **)(param_1 + 0x78) + 0x28))(*(int **)(param_1 + 0x78),uVar7);
  uVar6 = 0;
  do {
    iVar3 = param_1 + uVar6 * 4;
    piVar4 = *(int **)(iVar3 + 0x22e80);
    (**(code **)(*piVar4 + 0x28))(piVar4,bVar5);
    iVar3 = *(int *)(iVar3 + 0x22e70);
    uVar6 = uVar6 + 1 & 0xff;
    *(byte *)(iVar3 + 0x44) = *(byte *)(iVar3 + 0x44) & 0xfe | bVar5;
  } while (uVar6 < 2);
  uVar6 = 0;
  do {
    piVar4 = *(int **)(param_1 + uVar6 * 4 + 0x22e88);
    (**(code **)(*piVar4 + 0x28))(piVar4,bVar8);
    uVar6 = uVar6 + 1 & 0xff;
  } while (uVar6 < 2);
  uVar6 = 0;
  do {
    piVar4 = *(int **)(param_1 + uVar6 * 4 + 0x22e90);
    (**(code **)(*piVar4 + 0x28))(piVar4,bVar9);
    uVar6 = uVar6 + 1 & 0xff;
  } while (uVar6 < 2);
  return;
}


// FUNC 0x17009094 FUN_17009094 (ShopMenu)
//   size 0x6c | file ShopMenu+0x9094 | callers(4) 0x1700f458 0x1700f718 0x1700e770 0x17010b64

void FUN_17009094(int param_1)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
  iVar1 = msys::MComSys::_sys;
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  else {
    iVar1 = *(int *)(param_1 + 8);
  }
  if (*(char *)(iVar1 + 0xea02e) == '\x01') {
    iVar1 = 0;
    do {
      iVar2 = **(int **)(param_1 + iVar1 * 4 + 0x22e80);
      if (*(short *)(param_1 + 0x84) + -1 == iVar1) {
        pcVar3 = *(code **)(iVar2 + 0x20);
      }
      else {
        pcVar3 = *(code **)(iVar2 + 0x18);
      }
      (*pcVar3)();
      iVar1 = iVar1 + 1;
    } while (iVar1 < 2);
  }
  return;
}


// FUNC 0x17009104 FUN_17009104 (ShopMenu)
//   size 0x78 | file ShopMenu+0x9104 | callers(4) 0x1700db3c 0x1700d580 0x1700e184 0x1700d854

void FUN_17009104(int param_1,int param_2)

{
  int *piVar1;
  uint uVar2;
  
  if (param_2 == 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x78) + 0x48) = 0;
  }
  (**(code **)(**(int **)(param_1 + 0x78) + 0x28))(*(int **)(param_1 + 0x78),param_2 == 0);
  uVar2 = 0;
  do {
    piVar1 = *(int **)(param_1 + uVar2 * 4 + 0x7104);
    (**(code **)(*piVar1 + 0x28))(piVar1,param_2 == 1);
    uVar2 = uVar2 + 1 & 0xff;
  } while (uVar2 < 2);
  return;
}


// FUNC 0x1700917c FUN_1700917c (ShopMenu)
//   size 0x460 | file ShopMenu+0x917c | callers(7) 0x1701042c 0x1700e770 0x170112a4 0x1700d580 0x1700e088 0x17010894 0x17011edc

int FUN_1700917c(MListWndPBase *param_1,uint param_2,uint param_3,int param_4)

{
  ushort uVar1;
  MListWndPBase MVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  char cVar6;
  uint uVar7;
  ushort *puVar8;
  undefined4 uVar9;
  int iVar10;
  MListWndPBase MVar11;
  ushort *puVar12;
  bool bVar13;
  byte bVar14;
  uint in_fpscr;
  float fVar15;
  float fVar16;
  undefined4 uVar17;
  
  iVar10 = 0;
  if ((&DAT_1701674b)[(param_2 & 0xfff) * 4] == '\x04') {
    if (param_3 == 0x1000) {
      param_2 = 7;
    }
    else {
      param_2 = 8;
    }
  }
  bVar14 = (&DAT_17016749)[(param_2 & 0xfff) * 4];
  *(uint *)(param_1 + 0x8e10) = (uint)bVar14;
  puVar8 = (ushort *)(&DAT_17016550 + (uint)(byte)(&DAT_17016748)[(param_2 & 0xfff) * 4] * 6);
  puVar12 = puVar8 + (uint)bVar14 * 3;
  iVar3 = msys::MListWndPBase::getListWnd(param_1);
  uVar9 = *(undefined4 *)(param_1 + 0x8e0c);
  msys::SetMListWndInitParam(iVar3 + 4,0);
  FUN_1700ba74(iVar3 + 0xd8,uVar9);
  if (puVar12 != puVar8) {
    do {
      if (puVar8[1] == 0) {
LAB_17009248:
        *(ushort **)(*(int *)(param_1 + 0x8e08) + iVar10 * 4) = puVar8;
        iVar3 = ad::db::GetItemData(*puVar8);
        uVar4 = GameWork::getItemNum((GameWork *)&gGameWork,*puVar8);
        MVar11 = (MListWndPBase)0x1;
        uVar7 = *puVar8 & 0xf000;
        if (uVar7 == param_3) {
          param_1[iVar10 * 0x1c + 0x6f86] = (MListWndPBase)0xff;
          param_1[iVar10 * 0x1c + 0x6f8b] = (MListWndPBase)0xff;
          param_1[iVar10 * 0x1c + 0x6f89] = (MListWndPBase)0xff;
          if (uVar7 == 0x1000) {
            param_1[iVar10 * 0x1c + 0x6f8b] = (MListWndPBase)(*(char *)(iVar3 + 0x60) + '\x01');
            fVar15 = (float)VectorUnsignedToFloat
                                      ((uint)*(ushort *)(iVar3 + 100),(byte)(in_fpscr >> 0x16) & 3);
            uVar9 = GameWork::getCoin((GameWork *)&gGameWork);
            fVar16 = (float)VectorUnsignedToFloat(uVar9,(byte)(in_fpscr >> 0x16) & 3);
            uVar7 = in_fpscr & 0xfffffff | (uint)(fVar16 < fVar15) << 0x1f;
            in_fpscr = uVar7 | (uint)(NAN(fVar16) || NAN(fVar15)) << 0x1c;
            if (((byte)(uVar7 >> 0x1f) != ((byte)(in_fpscr >> 0x1c) & 1)) || (0x62 < uVar4)) {
              MVar11 = (MListWndPBase)0x0;
            }
            goto LAB_17009520;
          }
          if (uVar7 == 0x2000) {
            cVar6 = *(char *)(iVar3 + 0x6a);
            if (param_4 == 0) {
              if (cVar6 == '\0' || cVar6 == '\x05') goto LAB_17009314;
            }
            else if (cVar6 != '\0' && cVar6 != '\x05') {
LAB_17009314:
              uVar1 = *puVar8;
              fVar15 = (float)VectorUnsignedToFloat
                                        ((uint)*(ushort *)(iVar3 + 100),(byte)(in_fpscr >> 0x16) & 3
                                        );
              bVar14 = DAT_003f9614 == uVar1 || (DAT_003f9612 == uVar1 || DAT_003f9610 == uVar1);
              if (DAT_003f9644 == uVar1) {
                bVar14 = bVar14 | 2;
              }
              if (DAT_003f9646 == uVar1) {
                bVar14 = bVar14 | 2;
              }
              if (DAT_003f9648 == uVar1) {
                bVar14 = bVar14 | 2;
              }
              if (DAT_003f9678 == uVar1) {
                bVar14 = bVar14 | 4;
              }
              if (DAT_003f967a == uVar1) {
                bVar14 = bVar14 | 4;
              }
              if (DAT_003f967c == uVar1) {
                bVar14 = bVar14 | 4;
              }
              uVar9 = GameWork::getCoin((GameWork *)&gGameWork);
              fVar16 = (float)VectorUnsignedToFloat(uVar9,(byte)(in_fpscr >> 0x16) & 3);
              uVar7 = in_fpscr & 0xfffffff | (uint)(fVar16 < fVar15) << 0x1f;
              in_fpscr = uVar7 | (uint)(NAN(fVar16) || NAN(fVar15)) << 0x1c;
              if (((byte)(uVar7 >> 0x1f) != ((byte)(in_fpscr >> 0x1c) & 1)) ||
                 (MVar11 = (MListWndPBase)0x1, 8 < uVar4)) {
                MVar11 = (MListWndPBase)0x0;
              }
              param_1[iVar10 * 0x1c + 0x6f8b] = (MListWndPBase)(*(char *)(iVar3 + 0x60) + '\x01');
              goto LAB_170093d0;
            }
            goto LAB_170095a0;
          }
          fVar15 = 0.0;
          if (uVar7 == 0x3000) {
            uVar1 = *puVar8;
            fVar15 = (float)VectorUnsignedToFloat
                                      ((uint)*(ushort *)(iVar3 + 100),(byte)(in_fpscr >> 0x16) & 3);
            bVar14 = DAT_003f9616 == uVar1;
            if (DAT_003f964a == uVar1) {
              bVar14 = bVar14 | 2;
            }
            if (DAT_003f967e == uVar1) {
              bVar14 = bVar14 | 4;
            }
            uVar9 = GameWork::getCoin((GameWork *)&gGameWork);
            fVar16 = (float)VectorUnsignedToFloat(uVar9,(byte)(in_fpscr >> 0x16) & 3);
            uVar7 = in_fpscr & 0xfffffff | (uint)(fVar15 == fVar16) << 0x1e;
            in_fpscr = uVar7 | (uint)(fVar16 <= fVar15) << 0x1d;
            bVar13 = SUB41(uVar7 >> 0x1e,0);
            if (!(bool)((byte)(in_fpscr >> 0x1d) & 1) || bVar13) {
              bVar13 = uVar4 == 0;
            }
            if ((!bVar13) && (MVar11 = (MListWndPBase)0x0, uVar4 != 0)) {
              param_1[iVar10 * 0x1c + 0x6f86] = (MListWndPBase)0x0;
              fVar15 = 65535.0;
            }
            cVar6 = '\0';
            if (*(char *)(iVar3 + 0x67) != '\0') {
              cVar6 = '\x06';
            }
            param_1[iVar10 * 0x1c + 0x6f89] = (MListWndPBase)(*(char *)(iVar3 + 0x66) + cVar6);
LAB_170093d0:
            if (bVar14 == 0) goto LAB_17009520;
            if (bVar14 == 1) {
              MVar2 = (MListWndPBase)0x1;
LAB_170095ec:
              param_1[iVar10 * 0x1c + 0x6f88] = MVar2;
            }
            else {
              if (bVar14 == 2) {
                MVar2 = (MListWndPBase)0x2;
                goto LAB_170095ec;
              }
              if (bVar14 == 3) {
                MVar2 = (MListWndPBase)0x3;
                goto LAB_170095ec;
              }
              if (bVar14 == 4) {
                MVar2 = (MListWndPBase)0x4;
                goto LAB_170095ec;
              }
              param_1[iVar10 * 0x1c + 0x6f88] = (MListWndPBase)0xff;
            }
            if (puVar8[2] != 0) {
              PutRegFlag(puVar8[2],1.0,(GlobalEvent *)0x0,(LocalEvent *)0x0);
            }
          }
          else {
LAB_17009520:
            if (puVar8[2] == 0) {
LAB_17009548:
              MVar2 = (MListWndPBase)0xff;
            }
            else {
              fVar16 = (float)GetRegFlag(puVar8[2],(GlobalEvent *)0x0,(LocalEvent *)0x0);
              in_fpscr = in_fpscr & 0xfffffff;
              if (fVar16 != 0.0) goto LAB_17009548;
              MVar2 = (MListWndPBase)0x0;
            }
            param_1[iVar10 * 0x1c + 0x6f88] = MVar2;
          }
          *(uint *)(param_1 + iVar10 * 0x1c + 0x6f80) = (uint)*puVar8;
          iVar5 = ad::db::GetItemMsgAcs();
          uVar9 = LMS_GetTextIndexByLabel(iVar5 + 8,iVar3);
          uVar9 = LMS_GetText(iVar5 + 8,uVar9);
          uVar17 = VectorFloatToUnsigned(fVar15,3);
          *(undefined4 *)(param_1 + iVar10 * 0x1c + 0x6f90) = uVar9;
          *(short *)(param_1 + iVar10 * 0x1c + 0x6f84) = (short)uVar17;
          param_1[iVar10 * 0x1c + 0x6f8e] = MVar11;
          iVar10 = (int)(short)((short)iVar10 + 1);
        }
      }
      else {
        fVar15 = (float)GetRegFlag(puVar8[1],(GlobalEvent *)0x0,(LocalEvent *)0x0);
        in_fpscr = in_fpscr & 0xfffffff;
        if (fVar15 != 0.0) goto LAB_17009248;
      }
LAB_170095a0:
      puVar8 = puVar8 + 3;
    } while (puVar12 != puVar8);
  }
  iVar3 = msys::MListWndPBase::getListWnd(param_1);
  *(char *)(iVar3 + 0x144) = (char)iVar10;
  return iVar10;
}


// FUNC 0x170095f4 FUN_170095f4 (ShopMenu)
//   size 0x48 | file ShopMenu+0x95f4 | callers(7) 0x1700d294 0x1700e5dc 0x170124bc 0x1700d374 0x1700e680 0x17011070 0x1701259c

undefined4 * FUN_170095f4(undefined4 *param_1)

{
  *param_1 = &shop::ShopMenu_PageBase::Core::vtable;
  Mem::Free((void *)param_1[0xd]);
  param_1[10] = &MemAlcH::vtable;
  param_1[0xd] = 0;
  Mem::Free((void *)0x0);
  param_1[10] = &MemAlc::vtable;
  param_1[0xd] = 0;
  return param_1;
}


// FUNC 0x17009648 FUN_17009648 (ShopMenu)
//   size 0x4c | file ShopMenu+0x9648 | callers(4) 0x1700ce94 0x1700e258 0x17010750 0x170120b8

void FUN_17009648(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = *(int *)(param_1 + 4);
  iVar4 = *(int *)(iVar5 + 100);
  puVar1 = (undefined4 *)MoveVBase::update((MoveVBase *)(iVar5 + 4),1.0);
  uVar2 = puVar1[1];
  uVar3 = puVar1[2];
  *(undefined4 *)(iVar4 + 0x1c) = *puVar1;
  *(undefined4 *)(iVar4 + 0x20) = uVar2;
  *(undefined4 *)(iVar4 + 0x24) = uVar3;
  *(byte *)(iVar4 + 0x44) = *(byte *)(iVar4 + 0x44) & 0xef | 0x10;
  *(undefined1 *)(*(int *)(iVar5 + 0x60) + 0x374) = 1;
  MoveVBase::isBusy((MoveVBase *)(iVar5 + 4));
  return;
}


// FUNC 0x17009698 FUN_17009698 (ShopMenu)
//   size 0x100 | file ShopMenu+0x9698 | callers(2) 0x1700cb7c 0x17011d98

undefined4 FUN_17009698(int param_1,uint *param_2)

{
  char cVar1;
  uint uVar2;
  int *piVar3;
  code *pcVar4;
  int *piVar5;
  int *piVar6;
  bool bVar7;
  
  uVar2 = *param_2;
  piVar5 = *(int **)(param_1 + 0x7748);
  piVar6 = *(int **)(param_1 + 0x7744);
  if ((uVar2 & 0xc0) == 0) {
    bVar7 = (char)piVar6[1] != '\x01';
    cVar1 = '\x01';
    if (bVar7) {
      cVar1 = (char)piVar5[1];
    }
    if (bVar7 && cVar1 != '\x01') {
      return 0;
    }
  }
  if ((uVar2 & 0x40) == 0) {
    if ((uVar2 & 0x80) != 0) {
      *(undefined1 *)(param_1 + 0x72e0) = 1;
      pcVar4 = *(code **)(*piVar5 + 8);
      piVar3 = piVar5;
      goto LAB_1700970c;
    }
    if ((char)piVar6[1] == '\x01') {
      *(undefined1 *)(param_1 + 0x72e0) = 2;
      goto LAB_1700975c;
    }
    if ((char)piVar5[1] != '\x01') goto LAB_1700973c;
    *(undefined1 *)(param_1 + 0x72e0) = 3;
LAB_17009770:
    pcVar4 = *(code **)(*piVar6 + 0x28);
    piVar5 = piVar6;
  }
  else {
    *(undefined1 *)(param_1 + 0x72e0) = 0;
    pcVar4 = *(code **)(*piVar6 + 8);
    piVar3 = piVar6;
LAB_1700970c:
    (*pcVar4)(piVar3);
LAB_1700973c:
    cVar1 = *(char *)(param_1 + 0x72e0);
    if (cVar1 != '\0' && cVar1 != '\x02') {
      if (cVar1 != '\x01' && cVar1 != '\x03') goto LAB_17009784;
      goto LAB_17009770;
    }
LAB_1700975c:
    pcVar4 = *(code **)(*piVar5 + 0x28);
  }
  (*pcVar4)(piVar5,0);
LAB_17009784:
  *(undefined2 *)(param_1 + 0x72e2) = 0xffff;
  return 1;
}


// FUNC 0x1700979c FUN_1700979c (ShopMenu)
//   size 0xa0 | file ShopMenu+0x979c | callers(5) 0x170082b8 0x170099b8 0x17008df4 0x1700d580 0x1700d98c

void FUN_1700979c(int param_1,uint param_2)

{
  wchar_t *pwVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  pwVar1 = (wchar_t *)ad::db::GetItemMsg(param_2,2);
  msys::MMsg::playStr((MMsg *)(param_1 + 0xd24),pwVar1,(InsParam *)0x0,false);
  if ((param_2 & 0xf000) == 0x2000) {
    iVar2 = ad::db::GetEquip((ushort)param_2);
    uVar5 = 0;
    do {
      iVar4 = (int)*(short *)(iVar2 + uVar5 * 2 + 0x6c);
      iVar3 = param_1 + uVar5 * 0x230;
      if (iVar4 == 0) {
        *(undefined4 *)(iVar3 + 0x174) = 0xb;
        *(undefined4 *)(iVar3 + 0x180) = 0xb;
        *(undefined4 *)(iVar3 + 0x18c) = 0xb;
      }
      else {
        ad::lyt::LytNumReel3::setValueInstant((LytNumReel3 *)(iVar3 + 0x154),iVar4);
      }
      uVar5 = uVar5 + 1 & 0xff;
    } while (uVar5 < 6);
  }
  return;
}


// FUNC 0x1700983c FUN_1700983c (ShopMenu)
//   size 0xc8 | file ShopMenu+0x983c | callers(4) 0x1700e770 0x170112a4 0x1700c18c 0x1700d580

void FUN_1700983c(int *param_1,int param_2)

{
  undefined4 uVar1;
  uint in_fpscr;
  float fVar2;
  LytAnim local_28 [4];
  undefined4 local_24;
  undefined4 uStack_20;
  undefined4 local_1c;
  undefined2 local_18;
  undefined2 local_16;
  AnimTransform *local_14;
  undefined4 local_10;
  
  local_28[0] = (LytAnim)0x0;
  local_24 = 0;
  uStack_20 = 0x3f800000;
  local_1c = 0;
  local_18 = 1;
  local_16 = 0;
  local_14 = (AnimTransform *)0x0;
  local_10 = 0;
  if (param_2 == 0) {
    ad::lyt::LytAnim::init
              (local_28,*(Layout **)(*param_1 + 0xea184),"SET_PANEL_PLANE","EXP_PNL_U_down");
  }
  else if (param_2 == 1) {
    ad::lyt::LytAnim::init
              (local_28,*(Layout **)(*param_1 + 0xea184),"SET_PANEL_STATUS","EXP_PNL_U_down");
  }
  uVar1 = ad::lyt::AnimTransform::GetFrameSize(local_14);
  fVar2 = (float)VectorUnsignedToFloat(uVar1,(byte)(in_fpscr >> 0x16) & 3);
  ad::lyt::LytAnim::stopAndSetFrm(local_28,fVar2);
  ad::lyt::LytAnim::term(local_28,true);
  return;
}


// FUNC 0x17009940 FUN_17009940 (ShopMenu)
//   size 0x78 | file ShopMenu+0x9940 | callers(6) 0x1700c854 0x1700c18c 0x1700ccd0 0x1700c538 0x1700cb7c 0x1700cfc8

void FUN_17009940(int param_1,int param_2)

{
  int *piVar1;
  uint uVar2;
  
  if (param_2 == 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x78) + 0x48) = 0;
  }
  (**(code **)(**(int **)(param_1 + 0x78) + 0x28))(*(int **)(param_1 + 0x78),param_2 == 0);
  uVar2 = 0;
  do {
    piVar1 = *(int **)(param_1 + uVar2 * 4 + 0x77cc);
    (**(code **)(*piVar1 + 0x28))(piVar1,param_2 == 1);
    uVar2 = uVar2 + 1 & 0xff;
  } while (uVar2 < 2);
  return;
}


// FUNC 0x170099b8 FUN_170099b8 (ShopMenu)
//   size 0x8c | file ShopMenu+0x99b8 | callers(3) 0x1700c18c 0x1700cda4 0x1700c3f4

void FUN_170099b8(int param_1,int param_2)

{
  MLyt *this;
  int iVar1;
  int iVar2;
  
  this = (MLyt *)(**(int **)(param_1 + 100) + 0xea034);
  if (param_2 == 0) {
    iVar1 = msys::MLyt::getPane(this,"EXP_PNL_U_down",(char *)0x0,(char *)0x0);
    *(undefined1 *)(iVar1 + 0x45) = 0;
    ad::lyt::LytNumReel3::setValueInstant((LytNumReel3 *)(*(int *)(param_1 + 0x60) + 0x6d94),0);
    return;
  }
  iVar1 = msys::MLyt::getPane(this,"EXP_PNL_U_down",(char *)0x0,(char *)0x0);
  *(undefined1 *)(iVar1 + 0x45) = 0xff;
  FUN_1700979c(*(undefined4 *)(param_1 + 100),param_2);
  iVar2 = *(int *)(param_1 + 0x60);
  iVar1 = GameWork::getItemNum((GameWork *)&gGameWork,(ushort)param_2);
  ad::lyt::LytNumReel3::setValueInstant((LytNumReel3 *)(iVar2 + 0x6d94),iVar1);
  return;
}


// FUNC 0x17009a4c FUN_17009a4c (ShopMenu)
//   size 0x334 | file ShopMenu+0x9a4c | callers(2) 0x1700c18c 0x1700cda4

int FUN_17009a4c(MListWndPBase *param_1,int param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  ushort uVar3;
  char cVar4;
  char cVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  byte bVar9;
  ushort *unaff_r5;
  undefined4 uVar10;
  int iVar11;
  ushort *unaff_r9;
  uint in_fpscr;
  float fVar12;
  
  iVar11 = 0;
  iVar6 = msys::MListWndPBase::getListWnd(param_1);
  if (*(char *)(iVar6 + 0x144) != '\0') {
    msys::MListWndPBase::getListWnd(param_1);
    puVar7 = (undefined4 *)ad::ui::UIListWindowPlusLyt::getCurItem();
    uVar10 = *puVar7;
    iVar6 = msys::MListWndPBase::getListWnd(param_1);
    *(undefined4 *)(iVar6 + 0x14c) = uVar10;
  }
  if (param_2 == 0x1000) {
    puVar7 = (undefined4 *)ad::db::GetUseItemIdList();
    unaff_r5 = (ushort *)*puVar7;
    iVar6 = ad::db::GetUseItemIdList();
  }
  else {
    if (param_2 != 0x2000) goto LAB_17009ad8;
    puVar7 = (undefined4 *)ad::db::GetEquipIdList();
    unaff_r5 = (ushort *)*puVar7;
    iVar6 = ad::db::GetEquipIdList();
  }
  unaff_r9 = *(ushort **)(iVar6 + 4);
LAB_17009ad8:
  if (unaff_r5 != unaff_r9) {
    iVar6 = iVar11;
    do {
      cVar4 = GameWork::getItemNum((GameWork *)&gGameWork,*unaff_r5);
      iVar8 = ad::db::GetItemData(*unaff_r5);
      iVar11 = iVar6;
      if (cVar4 != '\0') {
        param_1[iVar6 * 0x1c + 0x6f8b] = (MListWndPBase)(*(char *)(iVar8 + 0x60) + '\x01');
        uVar3 = *unaff_r5;
        if ((uVar3 & 0xf000) == 0x1000) {
          uVar3 = *(ushort *)(iVar8 + 100);
          param_1[iVar6 * 0x1c + 0x6f8e] = (MListWndPBase)0x1;
          fVar12 = (float)VectorUnsignedToFloat((uint)uVar3,(byte)(in_fpscr >> 0x16) & 3);
LAB_17009c8c:
          param_1[iVar6 * 0x1c + 0x6f88] = (MListWndPBase)0xff;
        }
        else {
          fVar12 = 0.0;
          if ((uVar3 & 0xf000) != 0x2000) goto LAB_17009c8c;
          fVar12 = (float)VectorUnsignedToFloat
                                    ((uint)*(ushort *)(iVar8 + 100),(byte)(in_fpscr >> 0x16) & 3);
          cVar5 = cVar4;
          if (DAT_003f9610 == uVar3) {
            cVar5 = cVar4 + -1;
          }
          if (DAT_003f9612 == uVar3) {
            cVar5 = cVar5 + -1;
          }
          if (DAT_003f9614 == uVar3) {
            cVar5 = cVar5 + -1;
          }
          bVar9 = DAT_003f9614 == uVar3 || (DAT_003f9612 == uVar3 || DAT_003f9610 == uVar3);
          if (DAT_003f9644 == uVar3) {
            cVar5 = cVar5 + -1;
            bVar9 = bVar9 | 2;
          }
          if (DAT_003f9646 == uVar3) {
            cVar5 = cVar5 + -1;
            bVar9 = bVar9 | 2;
          }
          if (DAT_003f9648 == uVar3) {
            cVar5 = cVar5 + -1;
            bVar9 = bVar9 | 2;
          }
          if (DAT_003f9678 == uVar3) {
            cVar5 = cVar5 + -1;
            bVar9 = bVar9 | 4;
          }
          if (DAT_003f967a == uVar3) {
            cVar5 = cVar5 + -1;
            bVar9 = bVar9 | 4;
          }
          if (DAT_003f967c == uVar3) {
            cVar5 = cVar5 + -1;
            bVar9 = bVar9 | 4;
          }
          param_1[iVar6 * 0x1c + 0x6f8e] = (MListWndPBase)('\0' < cVar5);
          if (bVar9 == 0) goto LAB_17009c8c;
          if (bVar9 == 1) {
            param_1[iVar6 * 0x1c + 0x6f88] = (MListWndPBase)0x1;
          }
          else if (bVar9 == 2) {
            param_1[iVar6 * 0x1c + 0x6f88] = (MListWndPBase)0x2;
          }
          else if (bVar9 == 3) {
            param_1[iVar6 * 0x1c + 0x6f88] = (MListWndPBase)0x3;
          }
          else {
            if (bVar9 != 4) goto LAB_17009c8c;
            param_1[iVar6 * 0x1c + 0x6f88] = (MListWndPBase)0x4;
          }
        }
        uVar10 = VectorFloatToUnsigned(fVar12 * 0.25,3);
        *(short *)(param_1 + iVar6 * 0x1c + 0x6f84) = (short)uVar10;
        *(uint *)(param_1 + iVar6 * 0x1c + 0x6f80) = (uint)*unaff_r5;
        iVar11 = ad::db::GetItemMsgAcs();
        if (cVar4 != '\x01') {
          iVar8 = iVar8 + 0x18;
        }
        uVar10 = LMS_GetTextIndexByLabel(iVar11 + 8,iVar8);
        uVar10 = LMS_GetText(iVar11 + 8,uVar10);
        iVar11 = (int)(short)((short)iVar6 + 1);
        *(undefined4 *)(param_1 + iVar6 * 0x1c + 0x6f90) = uVar10;
      }
      unaff_r5 = unaff_r5 + 1;
      iVar6 = iVar11;
    } while (unaff_r5 != unaff_r9);
  }
  iVar6 = msys::MListWndPBase::getListWnd(param_1);
  *(char *)(iVar6 + 0x144) = (char)iVar11;
  iVar6 = msys::MListWndPBase::getListWnd(param_1);
  uVar1 = *(undefined1 *)(iVar6 + 0x6b);
  iVar6 = msys::MListWndPBase::getListWnd(param_1);
  uVar2 = *(undefined1 *)(iVar6 + 0x144);
  iVar6 = msys::MListWndPBase::getListWnd(param_1);
  FUN_17014ee8(iVar6 + 0x148,param_1 + 0x6f80,uVar2,uVar1);
  return iVar11;
}


// FUNC 0x17009d94 FUN_17009d94 (ShopMenu)
//   size 0x200 | file ShopMenu+0x9d94 | callers(2) 0x170112a4 0x1700c18c

void FUN_17009d94(int *param_1,int param_2,ButtonGroup *param_3,Resource *param_4,MLyt *param_5)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  uint in_fpscr;
  float fVar4;
  LytAnim aLStackY_f8 [128];
  undefined2 local_68;
  undefined2 local_66;
  AnimTransform *local_64;
  undefined4 local_60;
  undefined4 local_54;
  
  iVar3 = 0;
  *param_1 = param_2;
  param_1[2] = 0;
  FUN_1700ba88(param_1 + 3,param_2,param_5);
  msys::MCellAnime::init((MCellAnime *)(param_1 + 0x1c19),param_4);
  *(byte *)((int)param_1 + 0x7253) = *(byte *)((int)param_1 + 0x7253) | 3;
  *(undefined1 *)(param_1 + 0x1c92) = 0;
  *(undefined1 *)((int)param_1 + 0x7249) = 0;
  msys::MLyt::attachMChrF
            ((MLyt *)param_1[0x1b],(MChrBase *)(param_1 + 0x1c19),"INS_ICON_ITEM_list",(char *)0x0,
             (char *)0x0);
  param_1[1] = (int)(param_1 + 3);
  ad::lyt::LytNumReel3::InitParam::InitParam((InitParam *)&local_68);
  local_54 = 0;
  msys::MLytNumRes::set((MLytNumRes *)(param_2 + 0x844),&local_68,0,2);
  msys::MLytNum::init((MLytNum *)(param_1 + 0x1cb9),(InitParam *)&local_68,
                      (LytDrawData *)(param_2 + 0xd3000),param_5,"COUNT","lbl_PRICE_ALL",(char *)0x0
                      ,(char *)0x0);
  ad::lyt::LytNumReel3::InitParam::InitParam((InitParam *)&local_68);
  local_54 = GameWork::getCoin((GameWork *)&gGameWork);
  msys::MLytNumRes::set((MLytNumRes *)(param_2 + 0x844),&local_68,0);
  msys::MLytNum::init((MLytNum *)(param_1 + 0x1d45),(InitParam *)&local_68,
                      (LytDrawData *)(param_2 + 0xd3000),param_5,"count_num",(char *)0x0,(char *)0x0
                      ,(char *)0x0);
  local_68 = 1;
  local_66 = 0;
  local_64 = (AnimTransform *)0x0;
  local_60 = 0;
  do {
    piVar1 = (int *)ad::ctrl::ButtonGroup::FindButtonByName(param_3,(char *)(&DAT_17021c74)[iVar3]);
    param_1[iVar3 + 0x1dd1] = (int)piVar1;
    (**(code **)(*piVar1 + 0x28))(piVar1,0);
    ad::lyt::LytAnim::init
              (aLStackY_f8 + 0x80,*(Layout **)(param_5 + 0x150),(char *)(&DAT_17021c7c)[iVar3],
               (char *)(&DAT_17021c74)[iVar3]);
    uVar2 = ad::lyt::AnimTransform::GetFrameSize(local_64);
    fVar4 = (float)VectorUnsignedToFloat(uVar2,(byte)(in_fpscr >> 0x16) & 3);
    ad::lyt::LytAnim::stopAndSetFrm(aLStackY_f8 + 0x80,fVar4);
    ad::lyt::LytAnim::term(aLStackY_f8 + 0x80,true);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 2);
  return;
}


// FUNC 0x17009fb8 shop::ShopMenu_TopPage::vfunc_0x0 (ShopMenu)
//   size 0x4 | file ShopMenu+0x9fb8 | callers(0) | datarefs 1

undefined4 * shop::ShopMenu_TopPage::vfunc_0x0(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  undefined4 *puVar5;
  int *piVar6;
  
  *param_1 = &ShopMenu_PageBase::vtable;
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


// FUNC 0x17009fbc shop::ShopMenu_PageBase::vfunc_0x0 (ShopMenu)
//   size 0x124 | file ShopMenu+0x9fbc | callers(11) 0x1700b4d8 0x17007cb0 0x17008100 0x1700d48c 0x1700d49c 0x1700e75c 0x1700e76c 0x17011290 ... | datarefs 1

undefined4 * shop::ShopMenu_PageBase::vfunc_0x0(undefined4 *param_1)

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


// FUNC 0x1700a0e8 FUN_1700a0e8 (ShopMenu)
//   size 0x11c | file ShopMenu+0xa0e8 | callers(5) 0x1700789c 0x1700d164 0x1700e4e8 0x17010d74 0x17012388

undefined4 * FUN_1700a0e8(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  *param_1 = &shop::ShopMenu_PageBase::Core::vtable;
  param_1[1] = param_2;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = &MemAlcH::vtable;
  param_1[0xd] = 0;
  iVar1 = msys::MComSys::_sys;
  iVar2 = msys::MComSys::_sys + 0xe9194;
  param_1[2] = msys::MComSys::_sys;
  param_1[0xf] = iVar2;
  param_1[0x10] = iVar1 + 0xe9450;
  param_1[0x11] = iVar1 + 0xea034;
  param_1[0x12] = iVar1 + 0xea3dc;
  param_1[0x13] = iVar1 + 0xeaed4;
  param_1[0x14] = iVar1 + 0xebe90;
  param_1[0x15] = iVar1 + 0xf4cac;
  param_1[0x16] = iVar1 + 0xeb8c4;
  param_1[0x17] = iVar1 + 0xfdaa0;
  param_1[0x18] = iVar1 + 0xfdcd8;
  param_1[0x19] = iVar1 + 0x104b50;
  param_1[0x1a] = iVar1 + 0x1130fc;
  param_1[0x1b] = iVar1 + 0x119198;
  param_1[0x1c] = iVar1 + 0x11b1cc;
  param_1[0x1d] = FUN_0012fe6c + iVar1;
  *(undefined1 *)(param_1 + 0x1f) = 0xff;
  *(undefined1 *)((int)param_1 + 0x7d) = 0xff;
  return param_1;
}


// FUNC 0x1700a234 FUN_1700a234 (ShopMenu)
//   size 0x280 | file ShopMenu+0xa234 | callers(3) 0x17005eac 0x17006784 0x17006848

void FUN_1700a234(int param_1)

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
      iVar3 = msys::MCtrlUserData::findExtUserDataByName
                        (this,(char *)&msys::MCursor<20u>::update()::string_literal);
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
      local_50[0] = msys::MCursor<20u>::update()::string_literal;
      local_50[1] = msys::MCursor<20u>::update()::string_literal;
      local_50[2] = msys::MCursor<20u>::update()::string_literal;
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


// FUNC 0x1700a4cc FUN_1700a4cc (ShopMenu)
//   size 0x70 | file ShopMenu+0xa4cc | callers(16) 0x17005c08 0x17005150 0x170056b4 0x170051c8 0x1700572c 0x170052a0 0x170057f0 0x1700630c ...

void FUN_1700a4cc(int param_1,int param_2)

{
  int iVar1;
  ushort *puVar2;
  int iVar3;
  
  iVar1 = msys::MComSys::_sys;
  iVar3 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar3 = iVar1;
  }
  puVar2 = (ushort *)shop::GetBootInfo();
  CellAnime::play((CellAnime *)(iVar3 + 0xeb794),
                  (&UNK_17016378)
                  [param_2 + (uint)(byte)(&DAT_1701679e)
                                         [(uint)(byte)(&DAT_1701674a)[(*puVar2 & 0xffff0fff) * 4] *
                                          0x14] * 4],0,1.0);
  return;
}


// FUNC 0x1700a550 FUN_1700a550 (ShopMenu)
//   size 0x5c | file ShopMenu+0xa550 | callers(12) 0x17005150 0x170056b4 0x170052a0 0x170057f0 0x17005d74 0x17005dd8 0x1700630c 0x17005e78 ...

undefined4 FUN_1700a550(int param_1)

{
  int iVar1;
  
  if (((*(int *)(param_1 + 0xe3d8) == 0) && ((*(byte *)(param_1 + 0xd118) & 1) == 0)) &&
     ((*(char *)(param_1 + 0xe70b) == '\0' ||
      (iVar1 = FUN_1700a5b0(param_1,*(undefined1 *)(param_1 + 0xe70a)), iVar1 == 0)))) {
    return 0;
  }
  return 1;
}


// FUNC 0x1700a5b0 FUN_1700a5b0 (ShopMenu)
//   size 0x340 | file ShopMenu+0xa5b0 | callers(11) 0x1700a550 0x17005c08 0x170051c8 0x1700572c 0x17005d74 0x170066a8 0x17005e78 0x1700696c ...

undefined4 FUN_1700a5b0(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  Message *this;
  uint uVar4;
  uint uVar5;
  wchar_t *pwVar6;
  uint in_fpscr;
  undefined4 uVar7;
  undefined4 uVar8;
  Message *local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 uStack_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 uStack_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined1 local_98;
  undefined1 local_97;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined1 local_84;
  undefined1 local_83;
  undefined4 local_80;
  undefined4 uStack_7c;
  undefined1 local_78;
  undefined1 local_77;
  undefined4 local_74;
  MTX34 aMStack_70 [52];
  
  iVar2 = param_1 + 0xe6c8;
  __2sprintf(iVar2,&DAT_17003c70,
             (&PTR_s_MES_tuto_yo_scrratch_tuto_no_ml_17021cdc)
             [param_2 * 2 + (uint)*(byte *)(param_1 + 0xe708)],
             (&PTR_DAT_17021cc4)[*(byte *)(param_1 + 0xe709)]);
  if (*(byte *)(param_1 + 0xe70a) != param_2) {
    *(undefined1 *)(param_1 + 0xe70b) = 0;
  }
  iVar1 = msys::MComSys::_sys;
  iVar3 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar3 = iVar1;
  }
  iVar3 = LMS_GetTextIndexByLabel(iVar3 + 0xe93ec,iVar2);
  if (iVar3 < 0) {
    *(char *)(param_1 + 0xe70b) = *(char *)(param_1 + 0xe70b) + '\x01';
    __2sprintf(iVar2,"%s_%d");
    iVar1 = msys::MComSys::_sys;
    iVar3 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar3 = iVar1;
    }
    iVar3 = LMS_GetTextIndexByLabel(iVar3 + 0xe93ec,iVar2);
    if (iVar3 < 0) {
      *(undefined1 *)(param_1 + 0xe70b) = 0;
      return 0;
    }
  }
  if (*(char *)(param_1 + 0xe709) == '\x05') {
    FUN_1700beb8(msys::MComSys::_sys + 0x49368,0x12005e,0,0,0);
  }
  this = (Message *)(param_1 + 0x78dc);
  Message::play(this,(PlayParam *)(param_1 + 0xe688));
  iVar1 = msys::MComSys::_sys;
  iVar3 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar3 = iVar1;
  }
  iVar3 = msys::MChrBaseCore::getGlbMtx((MChrBaseCore *)(iVar3 + 0xeb648),aMStack_70);
  uVar7 = *(undefined4 *)(iVar3 + 0xc);
  uVar8 = *(undefined4 *)(iVar3 + 0x1c);
  local_c8 = 0;
  local_c4 = 0;
  local_b8 = 0x41000000;
  local_b4 = 0;
  local_b0 = 0;
  local_ac = 0;
  local_c0 = 0xc1000000;
  local_bc = 0x42000000;
  local_a0 = 0x41000000;
  local_9c = 0;
  local_a8 = 0xc1000000;
  uStack_a4 = 0x42000000;
  local_d8 = 0xc3480000;
  local_d4 = 0x42f00000;
  local_d0 = 0x43480000;
  uStack_cc = 0xc2f00000;
  local_98 = 5;
  local_97 = 8;
  local_94 = 0x45800000;
  local_90 = 0xc1a00000;
  local_8c = 0;
  local_88 = 0;
  local_84 = 0;
  local_83 = 0;
  local_dc = this;
  uVar4 = Grp::GetLcdWidth(0x400);
  uVar5 = Grp::GetLcdHeight(0x400);
  local_d8 = VectorSignedToFloat((int)-uVar4 / 2,(byte)(in_fpscr >> 0x16) & 3);
  local_d4 = VectorUnsignedToFloat(uVar5 >> 1,(byte)(in_fpscr >> 0x16) & 3);
  uStack_cc = VectorSignedToFloat((int)-uVar5 / 2,(byte)(in_fpscr >> 0x16) & 3);
  local_d0 = VectorUnsignedToFloat(uVar4 >> 1,(byte)(in_fpscr >> 0x16) & 3);
  local_bc = 0x42200000;
  local_b8 = 0x41700000;
  local_b4 = 0;
  local_c0 = 0xc1700000;
  local_84 = 0;
  local_c8 = uVar7;
  local_c4 = uVar8;
  MsgWndPosCalculator::calc((MsgWndPosCalculator *)&local_dc,(Result *)&local_80);
  uVar7 = *(undefined4 *)(param_1 + 0x7868);
  MoveVBase::stop((MoveVBase *)(param_1 + 0x785c));
  *(undefined4 *)(param_1 + 0x7880) = uVar7;
  *(undefined4 *)(param_1 + 0x7878) = local_80;
  *(undefined4 *)(param_1 + 0x787c) = uStack_7c;
  *(undefined4 *)(param_1 + 0x7868) = uVar7;
  *(undefined4 *)(param_1 + 0x7860) = local_80;
  *(undefined4 *)(param_1 + 0x7864) = uStack_7c;
  *(undefined1 *)(param_1 + 0xd11e) = local_77;
  iVar1 = msys::MComSys::_sys;
  iVar3 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar3 = iVar1;
  }
  uVar7 = LMS_GetTextIndexByLabel(iVar3 + 0xe93ec,iVar2);
  pwVar6 = (wchar_t *)LMS_GetText(iVar3 + 0xe93ec,uVar7);
  uVar7 = MessageSimple::getMsgHeight((MessageSimple *)this,pwVar6);
  uVar4 = VectorFloatToUnsigned(uVar7,3);
  if (uVar4 < 0x47) {
    *(undefined4 *)(param_1 + 0xd120) = local_74;
  }
  else {
    *(undefined4 *)(param_1 + 0xd120) = 0x42200000;
    local_78 = 3;
  }
  *(undefined1 *)(param_1 + 0xd11d) = local_78;
  *(char *)(param_1 + 0xe70a) = (char)param_2;
  *(undefined1 *)(param_1 + 0xe3e2) = 1;
  return 1;
}


// FUNC 0x1700a944 FUN_1700a944 (ShopMenu)
//   size 0x42c | file ShopMenu+0xa944 | callers(11) 0x17004370 0x1700501c 0x17004100 0x1700496c 0x170049ac 0x17005478 0x17006f68 0x17007404 ...

void FUN_1700a944(int param_1,undefined4 param_2)

{
  byte bVar1;
  bool bVar2;
  int *piVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  uVar9 = 0;
  uVar8 = 0;
  uVar7 = 0;
  uVar6 = 0;
  bVar2 = false;
  uVar5 = 0;
  local_28 = 0;
  local_2c = 0;
  local_30 = 0;
  local_34 = 0;
  local_38 = 0;
  switch(param_2) {
  case 0:
    *(undefined2 *)(param_1 + 0x7e) = 0;
    *(undefined2 *)(param_1 + 0x92) = 0xffff;
    *(undefined2 *)(param_1 + 0x80) = 0;
    *(undefined2 *)(param_1 + 0x88) = 3;
    uVar9 = 1;
    uVar5 = 1;
    *(undefined4 *)(*(int *)(param_1 + 0x78) + 0x48) = 0;
    break;
  case 1:
    *(undefined2 *)(param_1 + 0x7e) = 0;
    *(undefined2 *)(param_1 + 0x92) = 0xffff;
    *(undefined2 *)(param_1 + 0x80) = 3;
    *(undefined2 *)(param_1 + 0x88) = 2;
    uVar8 = 1;
    uVar5 = 1;
    *(undefined4 *)(*(int *)(param_1 + 0x78) + 0x48) = 0;
    break;
  case 2:
    *(undefined2 *)(param_1 + 0x7e) = 0;
    *(undefined2 *)(param_1 + 0x92) = 0xffff;
    *(undefined2 *)(param_1 + 0x80) = 5;
    *(undefined2 *)(param_1 + 0x88) = 2;
    uVar5 = 1;
    local_28 = 1;
    *(undefined4 *)(*(int *)(param_1 + 0x78) + 0x48) = 0;
    break;
  case 3:
    *(undefined2 *)(param_1 + 0x7e) = 0;
    *(undefined2 *)(param_1 + 0x92) = 0xffff;
    *(undefined2 *)(param_1 + 0x80) = 7;
    *(undefined2 *)(param_1 + 0x88) = 3;
    uVar5 = 1;
    local_2c = 1;
    *(undefined4 *)(*(int *)(param_1 + 0x78) + 0x48) = 0;
    break;
  case 4:
    *(undefined2 *)(param_1 + 0x7e) = 0;
    *(undefined2 *)(param_1 + 0x92) = 0xffff;
    *(undefined2 *)(param_1 + 0x80) = 0xc;
    *(undefined2 *)(param_1 + 0x88) = 3;
    uVar7 = 1;
    uVar5 = 1;
    *(undefined4 *)(*(int *)(param_1 + 0x78) + 0x48) = 0;
    break;
  case 5:
    *(undefined2 *)(param_1 + 0x7e) = 1;
    *(undefined2 *)(param_1 + 0x82) = 0xf;
    *(undefined2 *)(param_1 + 0x8a) = 2;
    local_30 = 1;
    uVar5 = 1;
    *(undefined4 *)(*(int *)(param_1 + 0x78) + 0x48) = 1;
    break;
  case 6:
    *(undefined2 *)(param_1 + 0x7e) = 0;
    *(undefined2 *)(param_1 + 0x92) = 0xffff;
    *(undefined2 *)(param_1 + 0x80) = 10;
    *(undefined2 *)(param_1 + 0x88) = 2;
    uVar5 = 1;
    local_34 = 1;
    *(undefined4 *)(*(int *)(param_1 + 0x78) + 0x48) = 0;
    break;
  case 7:
    *(undefined2 *)(param_1 + 0x7e) = 1;
    *(undefined2 *)(param_1 + 0x82) = 0x11;
    *(undefined2 *)(param_1 + 0x8a) = 2;
    local_38 = 1;
    uVar5 = 1;
    *(undefined4 *)(*(int *)(param_1 + 0x78) + 0x48) = 2;
    break;
  case 8:
    *(undefined2 *)(param_1 + 0x7e) = 2;
    *(undefined2 *)(param_1 + 0x84) = 0x18;
    uVar6 = 1;
    *(undefined2 *)(param_1 + 0x8c) = 2;
    break;
  case 9:
    *(undefined2 *)(param_1 + 0x7e) = 3;
    *(undefined2 *)(param_1 + 0x86) = 0x1a;
    bVar2 = true;
    *(undefined2 *)(param_1 + 0x8e) = 0x14;
  }
  uVar4 = 0;
  do {
    piVar3 = *(int **)(param_1 + uVar4 * 4 + 0xe88c);
    (**(code **)(*piVar3 + 0x28))(piVar3,uVar9);
    uVar4 = uVar4 + 1 & 0xff;
  } while (uVar4 < 3);
  uVar4 = 3;
  do {
    piVar3 = *(int **)(param_1 + uVar4 * 4 + 0xe88c);
    (**(code **)(*piVar3 + 0x28))(piVar3,uVar8);
    uVar4 = uVar4 + 1 & 0xff;
  } while (uVar4 < 5);
  uVar4 = 5;
  do {
    piVar3 = *(int **)(param_1 + uVar4 * 4 + 0xe88c);
    (**(code **)(*piVar3 + 0x28))(piVar3,local_28);
    uVar4 = uVar4 + 1 & 0xff;
  } while (uVar4 < 7);
  uVar4 = 7;
  do {
    piVar3 = *(int **)(param_1 + uVar4 * 4 + 0xe88c);
    (**(code **)(*piVar3 + 0x28))(piVar3,local_2c);
    uVar4 = uVar4 + 1 & 0xff;
  } while (uVar4 < 10);
  uVar4 = 10;
  do {
    piVar3 = *(int **)(param_1 + uVar4 * 4 + 0xe88c);
    (**(code **)(*piVar3 + 0x28))(piVar3,local_34);
    uVar4 = uVar4 + 1 & 0xff;
  } while (uVar4 < 0xc);
  uVar4 = 0xc;
  do {
    piVar3 = *(int **)(param_1 + uVar4 * 4 + 0xe88c);
    (**(code **)(*piVar3 + 0x28))(piVar3,uVar7);
    uVar4 = uVar4 + 1 & 0xff;
  } while (uVar4 < 0xf);
  uVar4 = 0xf;
  do {
    piVar3 = *(int **)(param_1 + uVar4 * 4 + 0xe88c);
    (**(code **)(*piVar3 + 0x28))(piVar3,local_30);
    uVar4 = uVar4 + 1 & 0xff;
  } while (uVar4 < 0x11);
  uVar4 = 0x11;
  do {
    piVar3 = *(int **)(param_1 + uVar4 * 4 + 0xe88c);
    (**(code **)(*piVar3 + 0x28))(piVar3,local_38);
    uVar4 = uVar4 + 1 & 0xff;
  } while (uVar4 < 0x13);
  uVar4 = 0;
  do {
    piVar3 = *(int **)(param_1 + uVar4 * 4 + 0xe8d8);
    (**(code **)(*piVar3 + 0x28))(piVar3,uVar6);
    uVar4 = uVar4 + 1 & 0xff;
  } while (uVar4 < 2);
  bVar1 = *(byte *)(param_1 + 0xa9);
  uVar4 = 0;
  do {
    piVar3 = *(int **)(param_1 + uVar4 * 4 + 0xe8e0);
    (**(code **)(*piVar3 + 0x28))(piVar3,bVar2 && uVar4 < ((5 - (uint)bVar1) * 5 & 0xff));
    uVar4 = uVar4 + 1 & 0xff;
  } while (uVar4 < 0x14);
                    /* WARNING: Could not recover jumptable at 0x1700ad94. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(param_1 + 0x78) + 0x28))(*(int **)(param_1 + 0x78),uVar5);
  return;
}


// FUNC 0x1700ad98 FUN_1700ad98 (ShopMenu)
//   size 0x280 | file ShopMenu+0xad98 | callers(32) 0x17004e08 0x1700c6cc 0x1700ddfc 0x1700faa8 0x17011c1c 0x17004100 0x17004370 0x170045bc ...

void FUN_1700ad98(int param_1)

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
      iVar3 = msys::MCtrlUserData::findExtUserDataByName(this,&DAT_17021fc9);
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
      local_50[0] = s_SQ_CURSOR_S_17021fcd;
      local_50[1] = s_SQ_CURSOR_L_17021fd9;
      local_50[2] = s_SQ_CURSOR_SS_17021fe5;
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


// FUNC 0x1700b030 shop::MListWndShopSell::vfunc_0x0 (ShopMenu)
//   size 0x6c | file ShopMenu+0xb030 | callers(2) 0x1700b4d8 0x17003c40 | datarefs 1

void shop::MListWndShopSell::vfunc_0x0(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &vtable;
  iVar1 = CellAnime::~CellAnime((CellAnime *)(param_1 + 0x2330));
  *(undefined4 *)(iVar1 + -0x10) = 0;
  *(undefined4 *)(iVar1 + -0x2c) = 0;
  *(undefined4 *)(iVar1 + -0x48) = 0;
  *(undefined4 *)(iVar1 + -100) = 0;
  iVar1 = ad::lyt::Layout::~Layout((Layout *)(iVar1 + -0xac));
  *(undefined4 *)(iVar1 + -0x10) = 0;
  *(undefined4 *)(iVar1 + -0x2c) = 0;
  *(undefined4 *)(iVar1 + -0x48) = 0;
  iVar1 = ad::lyt::Layout::~Layout((Layout *)(iVar1 + -0x90));
  *(undefined ***)(iVar1 + -0x8b84) = &vtable_for_N4msys9MListWndPILi256EEE;
  iVar1 = ad::ui::UIListWindowPlusLyt::~UIListWindowPlusLyt
                    ((UIListWindowPlusLyt *)(iVar1 + -0x8988));
  msys::MListWndPBase::~MListWndPBase((MListWndPBase *)(iVar1 + -0x1fc));
  return;
}


// FUNC 0x1700b0a8 FUN_1700b0a8 (ShopMenu)
//   size 0x34 | file ShopMenu+0xb0a8 | callers(4) 0x170144fc 0x1700789c 0x1700e4e8 0x1700378c | datarefs 1

void FUN_1700b0a8(undefined1 *param_1)

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


// FUNC 0x1700b0e4 FUN_1700b0e4 (ShopMenu)
//   size 0x2c | file ShopMenu+0xb0e4 | callers(1) 0x1700b110

void FUN_1700b0e4(undefined4 param_1,uint param_2,int param_3,undefined4 param_4,undefined1 param_5)

{
  undefined1 uStack00000000;
  
  if (param_3 + 1U < param_2) {
    param_2 = param_3 + 1U;
  }
  __c89vswprintf(param_1,param_2,param_4,&param_5);
  return;
}


// FUNC 0x1700b110 FUN_1700b110 (ShopMenu)
//   size 0x354 | file ShopMenu+0xb110 | callers(3) 0x17002d18 0x17007098 0x17007404

void FUN_1700b110(int *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  wchar_t *pwVar5;
  uint uVar6;
  short *psVar7;
  short *psVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  short local_240 [64];
  short local_1c0 [64];
  undefined2 local_140;
  undefined2 local_c0;
  uint local_40;
  uint local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  if (param_2 == 0) {
    iVar10 = *param_1;
    uVar4 = LMS_GetTextIndexByLabel(iVar10 + 0xe93ec,"MES_tuto_yo_scrconf_00");
    pwVar5 = (wchar_t *)LMS_GetText(iVar10 + 0xe93ec,uVar4);
    MessageSimple::play((MessageSimple *)(param_1 + 0xb4),pwVar5,(InsParam *)0x0,false);
    return;
  }
  if (param_2 == 1) {
    iVar10 = *param_1;
    uVar4 = LMS_GetTextIndexByLabel(iVar10 + 0xe93ec,"MES_ShopMes_Info_Scratch");
    pwVar5 = (wchar_t *)LMS_GetText(iVar10 + 0xe93ec,uVar4);
    MessageSimple::play((MessageSimple *)(param_1 + 0xb4),pwVar5,(InsParam *)0x0,false);
    return;
  }
  if (param_2 == 2) {
    if ((-1 < (char)param_1[1]) && ('\x02' < *(char *)((int)param_1 + (char)param_1[1] + 0x7229))) {
      iVar10 = *param_1;
      uVar4 = LMS_GetTextIndexByLabel(iVar10 + 0xe93ec,"MES_tuto_yo_scrres_fail_00");
      pwVar5 = (wchar_t *)LMS_GetText(iVar10 + 0xe93ec,uVar4);
      MessageSimple::play((MessageSimple *)(param_1 + 0xb4),pwVar5,(InsParam *)0x0,false);
      return;
    }
    local_240[0] = 0;
    local_40 = 0;
    local_1c0[0] = 0;
    local_3c = 0;
    local_140 = 0;
    local_38 = 0;
    local_c0 = 0;
    local_34 = 0;
    if ((char)param_1[1] < 0) {
      cVar1 = -1;
    }
    else {
      cVar1 = *(char *)((int)param_1 + (char)param_1[1] + 0x7229);
    }
    iVar10 = 10;
    uVar9 = 1;
    iVar11 = cVar1 + 1;
    do {
      iVar2 = __aeabi_uidivmod(iVar11,iVar10);
      if (iVar2 == 0) break;
      uVar9 = uVar9 + 1;
      iVar10 = iVar10 * 10;
    } while (uVar9 < 0x40);
    FUN_1700b0e4(local_240,0x40,0x3f,
                 &MessageSimple::InsParam::setNum(unsigned_char,int,bool)::string_literal,iVar11);
    if (uVar9 != 0) {
      uVar3 = uVar9 & 1;
      if (uVar3 != 0) {
        local_240[0] = local_240[0] + -0x120;
      }
      uVar6 = (uint)(uVar3 != 0);
      for (; uVar3 < uVar9; uVar3 = uVar3 + 2) {
        psVar7 = local_240 + uVar6;
        psVar8 = local_240 + uVar6 + 1;
        *psVar7 = *psVar7 + -0x120;
        uVar6 = uVar6 + 2;
        *psVar8 = *psVar8 + -0x120;
      }
    }
    local_40 = uVar9;
    iVar10 = 10;
    uVar9 = 1;
    iVar11 = *(int *)(*param_1 + 0xe904c);
    local_30 = *(undefined4 *)(iVar11 + 0x68);
    local_2c = *(undefined4 *)(iVar11 + 0x6c);
    local_28 = *(undefined4 *)(iVar11 + 0x70);
    cVar1 = *(char *)(&local_30 + cVar1);
    do {
      iVar11 = __aeabi_uidivmod((int)cVar1,iVar10);
      if (iVar11 == 0) break;
      uVar9 = uVar9 + 1;
      iVar10 = iVar10 * 10;
    } while (uVar9 < 0x40);
    FUN_1700b0e4(local_1c0,0x40,0x3f,
                 &MessageSimple::InsParam::setNum(unsigned_char,int,bool)::string_literal,(int)cVar1
                );
    if (uVar9 != 0) {
      uVar3 = uVar9 & 1;
      if (uVar3 != 0) {
        local_1c0[0] = local_1c0[0] + -0x120;
      }
      uVar6 = (uint)(uVar3 != 0);
      for (; uVar3 < uVar9; uVar3 = uVar3 + 2) {
        psVar7 = local_1c0 + uVar6;
        psVar8 = local_1c0 + uVar6 + 1;
        *psVar7 = *psVar7 + -0x120;
        uVar6 = uVar6 + 2;
        *psVar8 = *psVar8 + -0x120;
      }
    }
    iVar10 = *param_1;
    local_3c = uVar9;
    uVar4 = LMS_GetTextIndexByLabel(iVar10 + 0xe93ec,"MES_tuto_yo_scrres_suc_00");
    pwVar5 = (wchar_t *)LMS_GetText(iVar10 + 0xe93ec,uVar4);
    MessageSimple::play((MessageSimple *)(param_1 + 0xb4),pwVar5,(InsParam *)local_240,false);
  }
  return;
}


// FUNC 0x1700b4d8 shop::ShopMenu::vfunc_0x0 (ShopMenu)
//   size 0x478 | file ShopMenu+0xb4d8 | callers(3) 0x170029d4 0x170029fc 0x17014bf4 | datarefs 1

void shop::ShopMenu::vfunc_0x0(undefined4 *param_1)

{
  int iVar1;
  MLyt *pMVar2;
  
  *param_1 = &vtable;
  SndSys::merge((SndSys *)&gSndSys,1,true,0);
  ad::fw::FileContext::term((FileContext *)(param_1[0x9e] + 0xa8));
  ad::fw::FileContext::term((FileContext *)param_1[0x9e]);
  operator_delete((void *)param_1[0x3a413]);
  param_1[0x3a413] = 0;
  ad::fw::TaskBase::term((TaskBase *)param_1[1],0);
  __aeabi_vec_dtor(param_1 + 0x4f6fd,&LAB_1700125c,0x100,2);
  __aeabi_vec_dtor(param_1 + 0x4bf9b,&LAB_1700d528,0x6ec4,2);
  __aeabi_vec_dtor(param_1 + 0x46c73,&LAB_17003814,0x6ee0,3);
  iVar1 = msys::StatusPanel::~StatusPanel((StatusPanel *)(param_1 + 0x46466));
  __aeabi_vec_dtor(iVar1 + -0x609c,msys::StatusPanel::~StatusPanel,0x2034,3);
  *(undefined ***)(iVar1 + -0xcce0) = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar1 = MessageSimple::~MessageSimple((MessageSimple *)(iVar1 + -0xcb94));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  *(undefined ***)(iVar1 + -0x6c44) = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar1 = MessageSimple::~MessageSimple((MessageSimple *)(iVar1 + -0x6af8));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  __aeabi_vec_dtor(iVar1 + -0xd20,msys::MLytNum::~MLytNum,0x230,6);
  iVar1 = msys::MLytNum::~MLytNum((MLytNum *)(iVar1 + -0xf58));
  *(undefined ***)(iVar1 + -0x6c44) = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar1 = MessageSimple::~MessageSimple((MessageSimple *)(iVar1 + -0x6af8));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  iVar1 = msys::MLytNum::~MLytNum((MLytNum *)(iVar1 + -0x230));
  iVar1 = MListWndShopSell::vfunc_0x0(iVar1 + -0x8dfc);
  iVar1 = MListWndShop::vfunc_0x0(iVar1 + -0x8e1c);
  iVar1 = msys::MLytNum::~MLytNum((MLytNum *)(iVar1 + -0x230));
  iVar1 = msys::MLytNum::~MLytNum((MLytNum *)(iVar1 + -0x230));
  iVar1 = msys::MCursorBase::~MCursorBase((MCursorBase *)(iVar1 + -0x84));
  iVar1 = msys::MCursorBase::~MCursorBase((MCursorBase *)(iVar1 + -0xe8));
  *(undefined ***)(iVar1 + -0x27c) = &msys::MCellAnime::vtable;
  iVar1 = CellAnime::~CellAnime((CellAnime *)(iVar1 + -0x130));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  __aeabi_vec_dtor(iVar1 + -0x774,&LAB_17001418,0x27c,3);
  pMVar2 = (MLyt *)(iVar1 + -0xb1c);
  *(undefined ***)pMVar2 = &msys::MLyt::vtable;
  msys::MLyt::term(pMVar2);
  __aeabi_vec_dtor(iVar1 + -0x86c,&LAB_170013c8,0x10,0xc);
  __aeabi_vec_dtor(iVar1 + -0x9c8,&LAB_17001260,0x1c,0xc);
  iVar1 = msys::MChrBase::vfunc_0x0(pMVar2);
  pMVar2 = (MLyt *)(iVar1 + -0x3a8);
  *(undefined ***)pMVar2 = &msys::MLyt::vtable;
  msys::MLyt::term(pMVar2);
  __aeabi_vec_dtor(iVar1 + -0xf8,&LAB_170013c8,0x10,0xc);
  __aeabi_vec_dtor(iVar1 + -0x254,&LAB_17001260,0x1c,0xc);
  iVar1 = msys::MChrBase::vfunc_0x0(pMVar2);
  pMVar2 = (MLyt *)(iVar1 + -0x3a8);
  *(undefined ***)pMVar2 = &msys::MLyt::vtable;
  msys::MLyt::term(pMVar2);
  __aeabi_vec_dtor(iVar1 + -0xf8,&LAB_170013c8,0x10,0xc);
  __aeabi_vec_dtor(iVar1 + -0x254,&LAB_17001260,0x1c,0xc);
  iVar1 = msys::MChrBase::vfunc_0x0(pMVar2);
  pMVar2 = (MLyt *)(iVar1 + -0x3a8);
  *(undefined ***)pMVar2 = &msys::MLyt::vtable;
  msys::MLyt::term(pMVar2);
  __aeabi_vec_dtor(iVar1 + -0xf8,&LAB_170013c8,0x10,0xc);
  __aeabi_vec_dtor(iVar1 + -0x254,&LAB_17001260,0x1c,0xc);
  iVar1 = msys::MChrBase::vfunc_0x0(pMVar2);
  *(undefined ***)(iVar1 + -0x45c) = &msys::MReelNumMan2::vtable;
  ad::lyt::LytNumReel2::term((LytNumReel2 *)(iVar1 + -0x30c));
  *(undefined1 *)(iVar1 + -0x228) = 0;
  iVar1 = ad::lyt::LytNumReel2::~LytNumReel2((LytNumReel2 *)(iVar1 + -0x30c));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x150);
  pMVar2 = (MLyt *)(iVar1 + -0x3a8);
  *(undefined ***)pMVar2 = &msys::MLyt::vtable;
  msys::MLyt::term(pMVar2);
  __aeabi_vec_dtor(iVar1 + -0xf8,&LAB_170013c8,0x10,0xc);
  __aeabi_vec_dtor(iVar1 + -0x254,&LAB_17001260,0x1c,0xc);
  iVar1 = msys::MChrBase::vfunc_0x0(pMVar2);
  pMVar2 = (MLyt *)(iVar1 + -0x3a8);
  *(undefined ***)pMVar2 = &msys::MLyt::vtable;
  msys::MLyt::term(pMVar2);
  __aeabi_vec_dtor(iVar1 + -0xf8,&LAB_170013c8,0x10,0xc);
  __aeabi_vec_dtor(iVar1 + -0x254,&LAB_17001260,0x1c,0xc);
  iVar1 = msys::MChrBase::vfunc_0x0(pMVar2);
  iVar1 = ad::ctrl::ButtonGroup::~ButtonGroup((ButtonGroup *)(iVar1 + -0x1c));
  iVar1 = ad::ctrl::ButtonGroup::~ButtonGroup((ButtonGroup *)(iVar1 + -0x1c));
  iVar1 = MsgDataAcsrBase::~MsgDataAcsrBase((MsgDataAcsrBase *)(iVar1 + -0x6c));
  iVar1 = ShopMenu_PageBase::vfunc_0x0(iVar1 + -0x28);
  iVar1 = ShopMenu_PageBase::vfunc_0x0(iVar1 + -0x24);
  iVar1 = ShopMenu_PageBase::vfunc_0x0(iVar1 + -0x24);
  iVar1 = ShopMenu_PageBase::vfunc_0x0(iVar1 + -0x24);
  iVar1 = ShopMenu_PageBase::vfunc_0x0(iVar1 + -0x24);
  __aeabi_vec_dtor(iVar1 + -0x198,ad::fw::Resource::~Resource,0x44,6);
  iVar1 = ad::fw::Resource::~Resource((Resource *)(iVar1 + -0x1dc));
  iVar1 = ad::fw::Resource::~Resource((Resource *)(iVar1 + -0x44));
  iVar1 = ad::fw::Resource::~Resource((Resource *)(iVar1 + -0x44));
  ad::lyt::LytResourceMan::term((LytResourceMan *)(iVar1 + -0x74));
  iVar1 = ad::font::ResFont::~ResFont((ResFont *)(iVar1 + -0x70));
  msys::MComSys::~MComSys((MComSys *)(iVar1 + -0xe9058));
  return;
}


// FUNC 0x1700b9d8 shop::MListWndShop::vfunc_0x0 (ShopMenu)
//   size 0x90 | file ShopMenu+0xb9d8 | callers(2) 0x170029a8 0x1700b4d8 | datarefs 1

void shop::MListWndShop::vfunc_0x0(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &vtable;
  operator_delete__((void *)param_1[0x2382]);
  param_1[0x2382] = 0;
  iVar1 = CellAnime::~CellAnime((CellAnime *)(param_1 + 0x2337));
  *(undefined4 *)(iVar1 + -0x10) = 0;
  *(undefined4 *)(iVar1 + -0x2c) = 0;
  *(undefined4 *)(iVar1 + -0x48) = 0;
  *(undefined4 *)(iVar1 + -100) = 0;
  *(undefined4 *)(iVar1 + -0x80) = 0;
  iVar1 = ad::lyt::Layout::~Layout((Layout *)(iVar1 + -200));
  *(undefined4 *)(iVar1 + -0x10) = 0;
  *(undefined4 *)(iVar1 + -0x2c) = 0;
  *(undefined4 *)(iVar1 + -0x48) = 0;
  iVar1 = ad::lyt::Layout::~Layout((Layout *)(iVar1 + -0x90));
  *(undefined ***)(iVar1 + -0x8b84) = &vtable_for_N4msys9MListWndPILi256EEE;
  iVar1 = ad::ui::UIListWindowPlusLyt::~UIListWindowPlusLyt
                    ((UIListWindowPlusLyt *)(iVar1 + -0x8988));
  msys::MListWndPBase::~MListWndPBase((MListWndPBase *)(iVar1 + -0x1fc));
  return;
}


// FUNC 0x1700ba74 FUN_1700ba74 (ShopMenu)
//   size 0x14 | file ShopMenu+0xba74 | callers(3) 0x1700917c 0x1700252c 0x17003878

void FUN_1700ba74(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = param_2[1];
  *param_1 = *param_2;
  param_1[1] = uVar1;
  return;
}


// FUNC 0x1700ba88 FUN_1700ba88 (ShopMenu)
//   size 0x18c | file ShopMenu+0xba88 | callers(4) 0x1700e770 0x17009d94 0x1700d580 0x17001880

void FUN_1700ba88(int param_1,int param_2,MLyt *param_3)

{
  undefined4 uVar1;
  InitParam aIStack_70 [4];
  undefined4 local_6c;
  undefined4 local_5c;
  
  *(MLyt **)(param_1 + 0x60) = param_3;
  uVar1 = msys::MLyt::getPane(param_3,"NAME_BAR_list",(char *)0x0,(char *)0x0);
  *(undefined4 *)(param_1 + 100) = uVar1;
  msys::MDfxChr::init((MDfxChr *)(param_1 + 0x6edc),(MemAlcBase *)(param_2 + 0xc),
                      *(MDfxSys **)(param_2 + 0xe64f0),(Scene *)(param_2 + 0x4aba4),0x401);
  msys::MLyt::attachMChr
            (param_3,(MChrBase *)(param_1 + 0x6edc),"INS_ICON_ITEM_list",(char *)0x0,(char *)0x0,
             (char *)0x0);
  MoveVBase::stop((MoveVBase *)(param_1 + 0x6fa8));
  *(undefined4 *)(param_1 + 0x6fc4) = 0;
  *(undefined4 *)(param_1 + 0x6fc8) = 0;
  *(undefined4 *)(param_1 + 0x6fcc) = 0;
  *(undefined4 *)(param_1 + 0x6fac) = *(undefined4 *)(param_1 + 0x6fc4);
  *(undefined4 *)(param_1 + 0x6fb0) = *(undefined4 *)(param_1 + 0x6fc8);
  *(undefined4 *)(param_1 + 0x6fb4) = 0;
  *(MemAlcBase **)(param_1 + 0x6c9c) = (MemAlcBase *)(param_2 + 0xc);
  *(undefined4 *)(param_1 + 0x6ca0) = 0;
  *(undefined4 *)(param_1 + 0x6ca8) = 0x401;
  *(undefined4 *)(param_1 + 0x6ca4) = 0;
  MessageSimple::init((MessageSimple *)(param_1 + 0x1b4));
  FUN_1700bd6c(param_1 + 0x68);
  MessageWriter::setFontColor((MessageWriter *)(param_1 + 0x1b4),0xe6e6e6ff,true);
  msys::MLyt::attachMChr
            (param_3,(MChrBase *)(param_1 + 0x68),"INS_list_text_list",(char *)0x0,(char *)0x0,
             (char *)0x0);
  ad::lyt::LytNumReel3::InitParam::InitParam(aIStack_70);
  local_6c = msys::MLyt::getPane(param_3,"COUNT_list",(char *)0x0,(char *)0x0);
  local_5c = 1;
  msys::MLytNumRes::set((MLytNumRes *)(param_2 + 0x844),aIStack_70,0,2,0x11);
  msys::MLytNum::init((MLytNum *)(param_1 + 0x6cac),aIStack_70,(LytDrawData *)(param_2 + 0xd3000),
                      param_3,"COUNT_list",(char *)0x0,(char *)0x0,(char *)0x0);
  return;
}


// FUNC 0x1700bc6c shop::BuyPnlBase::ItemPnlBase::vfunc_0x0 (ShopMenu)
//   size 0xf8 | file ShopMenu+0xbc6c | callers(2) 0x17001820 0x17001850 | datarefs 1

void shop::BuyPnlBase::ItemPnlBase::vfunc_0x0
               (float param_1,int param_2,int param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  
  msys::MMsg::playStr((MMsg *)(param_2 + 0x68),*(wchar_t **)(param_3 + 0x10),(InsParam *)0x0,false);
  ad::lyt::LytNumReel3::setValueInstant
            ((LytNumReel3 *)(param_2 + 0x6dfc),(uint)*(ushort *)(param_3 + 4));
  uVar1 = *param_4;
  uVar2 = param_4[1];
  MoveVBase::stop((MoveVBase *)(param_2 + 4));
  *(undefined4 *)(param_2 + 0x20) = uVar1;
  *(undefined4 *)(param_2 + 0x24) = uVar2;
  *(undefined4 *)(param_2 + 0x28) = 0;
  *(undefined4 *)(param_2 + 8) = uVar1;
  *(undefined4 *)(param_2 + 0xc) = uVar2;
  *(undefined4 *)(param_2 + 0x10) = 0;
  MoveVBase::moveSinAbs((VEC3 *)(param_2 + 4),param_1);
  *(byte *)(*(int *)(param_2 + 100) + 0x44) = *(byte *)(*(int *)(param_2 + 100) + 0x44) & 0xfe | 1;
  iVar4 = *(int *)(param_2 + 100);
  puVar3 = (undefined4 *)MoveVBase::update((MoveVBase *)(param_2 + 4),1.0);
  uVar1 = puVar3[1];
  uVar2 = puVar3[2];
  *(undefined4 *)(iVar4 + 0x1c) = *puVar3;
  *(undefined4 *)(iVar4 + 0x20) = uVar1;
  *(undefined4 *)(iVar4 + 0x24) = uVar2;
  *(byte *)(iVar4 + 0x44) = *(byte *)(iVar4 + 0x44) & 0xef | 0x10;
  *(undefined1 *)(*(int *)(param_2 + 0x60) + 0x374) = 1;
  return;
}


// FUNC 0x1700bd6c FUN_1700bd6c (ShopMenu)
//   size 0x134 | file ShopMenu+0xbd6c | callers(12) 0x17002f14 0x17003c7c 0x1700ba88 0x1700e770 0x17001b3c 0x17012c3c 0x17001e94 0x17002068 ...

void FUN_1700bd6c(int param_1)

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


// FUNC 0x1700beb8 FUN_1700beb8 (ShopMenu)
//   size 0x8c | file ShopMenu+0xbeb8 | callers(43) 0x1700169c 0x170016d0 0x17001704 0x17001738 0x1700176c 0x17004e08 0x1700c6cc 0x1700ddfc ...

MSndSe * FUN_1700beb8(int param_1,uint param_2,MChrBase *param_3,VEC2 *param_4,bool param_5)

{
  MSndSe *this;
  int *piVar1;
  undefined4 *puVar2;
  int *piVar3;
  
  piVar3 = *(int **)(param_1 + 0xc);
  this = (MSndSe *)(piVar3 + -0x15);
  if ((MSndSe *)(param_1 + -0x4c) == this) {
    this = (MSndSe *)0x0;
  }
  else {
    piVar1 = (int *)piVar3[1];
    if (piVar1 != piVar3) {
      *(int **)(*piVar3 + 4) = piVar1;
      *piVar1 = *piVar3;
      *piVar3 = (int)piVar3;
      piVar3[1] = (int)piVar3;
    }
    piVar1 = (int *)piVar3[1];
    *(int **)(*piVar3 + 4) = piVar1;
    *piVar1 = *piVar3;
    if (piVar3 != (int *)0x0) {
      *piVar3 = param_1;
      puVar2 = *(undefined4 **)(param_1 + 4);
      piVar3[1] = (int)puVar2;
      *puVar2 = piVar3;
      *(int **)(param_1 + 4) = piVar3;
    }
    msys::MSndSe::play(this,param_2,param_3,param_4,param_5);
  }
  return this;
}


// FUNC 0x1700bf44 msys::MChrBase::vfunc_0x0 (ShopMenu)
//   size 0x14c | file ShopMenu+0xbf44 | callers(17) 0x17001628 0x17001664 0x170017bc 0x1700b4d8 0x17007ad4 0x1700d294 0x1700d374 0x1700e5dc ... | datarefs 1

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


// FUNC 0x1700c0a0 FUN_1700c0a0 (ShopMenu)
//   size 0xdc | file ShopMenu+0xc0a0 | callers(12) 0x170144fc 0x17008110 0x1700789c 0x1700d164 0x1700e4e8 0x17010d74 0x17012388 0x170013e4 ...

void FUN_1700c0a0(undefined4 *param_1)

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
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(puVar1 + 0xc,FUN_17014c78,0x2c,1);
  *(int *)(iVar2 + -8) = iVar2;
  *(undefined1 *)(iVar2 + -4) = 1;
  puVar1 = (undefined4 *)MoveVBase::MoveVBase((MoveVBase *)(iVar2 + 0x2c));
  *puVar1 = &vtable_for_5MoveVILj1EE;
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(puVar1 + 0xc,FUN_17014c78,0x2c,1);
  *(int *)(iVar2 + -8) = iVar2;
  *(undefined1 *)(iVar2 + -4) = 1;
  puVar1 = (undefined4 *)MoveVBase::MoveVBase((MoveVBase *)(iVar2 + 0x2c));
  *puVar1 = &vtable_for_5MoveVILj1EE;
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(puVar1 + 0xc,FUN_17014c78,0x2c,1);
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


// FUNC 0x1700c18c FUN_1700c18c (ShopMenu)
//   size 0x240 | file ShopMenu+0xc18c | callers(0) | datarefs 1

void FUN_1700c18c(void *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  void *pvVar3;
  AnimButton *pAVar4;
  int iVar5;
  undefined2 *puVar6;
  undefined4 uVar7;
  code *pcVar8;
  
  piVar2 = *(int **)(*(int *)((int)param_1 + 4) + 0x18);
  pcVar8 = *(code **)(*piVar2 + 0xc);
  pvVar3 = (void *)(*pcVar8)(piVar2,0x80,0,pcVar8,param_4);
  MemAlc::initCore((MemAlc *)((int)param_1 + 0x28),pvVar3,0x80);
  pAVar4 = (AnimButton *)
           ad::ctrl::ButtonGroup::FindButtonByName
                     (*(ButtonGroup **)((int)param_1 + 0x40),"btn_RETURN");
  *(AnimButton **)((int)param_1 + 0x78) = pAVar4;
  ad::ctrl::AnimButton::SetStateChangeCallback
            (pAVar4,(_func_void_AnimButton_ptr_State_State_void_ptr *)&LAB_17007df0,param_1);
  *(undefined4 *)(*(int *)((int)param_1 + 0x78) + 0x48) = 0;
  (**(code **)(**(int **)((int)param_1 + 0x78) + 0x28))(*(int **)((int)param_1 + 0x78),1);
  iVar5 = *(int *)((int)param_1 + 0x40);
  for (piVar2 = *(int **)(iVar5 + 8); piVar2 != (int *)(iVar5 + 8); piVar2 = (int *)*piVar2) {
    (**(code **)(piVar2[-5] + 0x28))(piVar2 + -5,0);
  }
  iVar5 = 0;
  do {
    pAVar4 = (AnimButton *)
             ad::ctrl::ButtonGroup::FindButtonByName
                       (*(ButtonGroup **)((int)param_1 + 0x40),(char *)(&DAT_17021cbc)[iVar5]);
    *(AnimButton **)((int)param_1 + iVar5 * 4 + 0x77cc) = pAVar4;
    ad::ctrl::AnimButton::SetStateChangeCallback
              (pAVar4,(_func_void_AnimButton_ptr_State_State_void_ptr *)&DAT_1700c848,param_1);
    *(int *)(*(int *)((int)param_1 + iVar5 * 4 + 0x77cc) + 0x48) = iVar5;
    piVar2 = *(int **)((int)param_1 + iVar5 * 4 + 0x77cc);
    (**(code **)(*piVar2 + 0x28))(piVar2,0);
    iVar1 = msys::MComSys::_sys;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 2);
  iVar5 = *(int *)((int)param_1 + 8);
  if (*(int *)((int)param_1 + 8) == 0) {
    *(int *)((int)param_1 + 8) = msys::MComSys::_sys;
    iVar5 = iVar1;
  }
  FUN_17009d94((int)param_1 + 0x80,iVar5,*(undefined4 *)((int)param_1 + 0x40),
               *(undefined4 *)((int)param_1 + 0x3c),*(undefined4 *)((int)param_1 + 0x48));
  iVar1 = msys::MComSys::_sys;
  iVar5 = *(int *)((int)param_1 + 8);
  if (*(int *)((int)param_1 + 8) == 0) {
    *(int *)((int)param_1 + 8) = msys::MComSys::_sys;
    iVar5 = iVar1;
  }
  if (*(char *)(iVar5 + 0xea02e) == '\x01') {
    uVar7 = 0x2000;
  }
  else {
    uVar7 = 0x1000;
  }
  FUN_17009a4c((MListWndPBase *)(iVar5 + 0xf4cac),uVar7);
  msys::MListWndPBase::resetCur((MListWndPBase *)(iVar5 + 0xf4cac));
  *(byte *)(*(int *)(iVar5 + 0x104b4c) + 0x44) =
       *(byte *)(*(int *)(iVar5 + 0x104b4c) + 0x44) & 0xfe | 1;
  msys::MListWndPBase::setEnableInput((MListWndPBase *)(iVar5 + 0xebe90),false);
  iVar5 = msys::MListWndPBase::getItemNum(*(MListWndPBase **)((int)param_1 + 0x54));
  if (iVar5 == 0) {
    FUN_170099b8(param_1,0);
  }
  else {
    puVar6 = (undefined2 *)msys::MListWndPBase::getCurItem();
    FUN_170099b8(param_1,*puVar6);
  }
  FUN_17009940(param_1,0);
  iVar1 = msys::MComSys::_sys;
  iVar5 = *(int *)((int)param_1 + 8);
  if (*(int *)((int)param_1 + 8) == 0) {
    *(int *)((int)param_1 + 8) = msys::MComSys::_sys;
    iVar5 = iVar1;
  }
  FUN_1700983c(*(undefined4 *)((int)param_1 + 100),*(char *)(iVar5 + 0xea02e) != '\0');
  *(undefined1 *)(*(int *)((int)param_1 + 4) + 0x14) = 1;
  *(undefined **)((int)param_1 + 0x10) = &DAT_1700d118;
  *(undefined4 *)((int)param_1 + 0x14) = 0;
  return;
}


// FUNC 0x1700c3f4 FUN_1700c3f4 (ShopMenu)
//   size 0x13c | file ShopMenu+0xc3f4 | callers(0) | datarefs 4

void FUN_1700c3f4(int param_1,uint *param_2)

{
  int iVar1;
  int iVar2;
  undefined2 *puVar3;
  
  iVar1 = msys::MListWndPBase::getSelectItem(*(MListWndPBase **)(param_1 + 0x54));
  if ((iVar1 == 0) ||
     (iVar1 = msys::MListWndPBase::getSelectItem(*(MListWndPBase **)(param_1 + 0x54)),
     *(char *)(iVar1 + 0xe) == '\0')) {
    iVar1 = (**(code **)(**(int **)(param_1 + 0x54) + 0x20))();
    if ((iVar1 == 0) &&
       ((iVar1 = msys::MListWndPBase::getListWnd(*(MListWndPBase **)(param_1 + 0x54)),
        *(int *)(iVar1 + 0x1cc) == 0 && ((*param_2 & 0x802) != 0)))) {
      (**(code **)(**(int **)(param_1 + 0x78) + 0x10))();
      (**(code **)(**(int **)(param_1 + 0x78) + 0xc))();
      iVar1 = msys::MComSys::_sys;
      iVar2 = *(int *)(param_1 + 8);
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar2 = iVar1;
      }
      *(undefined1 *)(iVar2 + 0xe6508) = 0;
    }
  }
  else {
    FUN_1700c538(param_1);
  }
  iVar1 = msys::MListWndPBase::getListWnd(*(MListWndPBase **)(param_1 + 0x54));
  if ((*(char *)(iVar1 + 0x144) != '\0') &&
     (iVar1 = msys::MListWndPBase::getListWnd(*(MListWndPBase **)(param_1 + 0x54)),
     *(int *)(iVar1 + 0x1cc) == 0)) {
    msys::MListWndPBase::getListWnd(*(MListWndPBase **)(param_1 + 0x54));
    puVar3 = (undefined2 *)ad::ui::UIListWindowPlusLyt::getCurItem();
    iVar1 = msys::MListWndPBase::getCurNo(*(MListWndPBase **)(param_1 + 0x54));
    if (iVar1 != *(short *)(param_1 + 0x7e)) {
      if (puVar3 != (undefined2 *)0x0) {
        FUN_170099b8(param_1,*puVar3);
      }
      iVar1 = msys::MListWndPBase::getListWnd(*(MListWndPBase **)(param_1 + 0x54));
      *(ushort *)(param_1 + 0x7e) = (ushort)*(byte *)(iVar1 + 0x149);
    }
  }
  return;
}


// FUNC 0x1700c538 FUN_1700c538 (ShopMenu)
//   size 0x180 | file ShopMenu+0xc538 | callers(1) 0x1700c3f4

void FUN_1700c538(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  uint in_fpscr;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 uStack_1c;
  
  FUN_1700beb8(msys::MComSys::_sys + 0x49368,0x110016,0,0,0);
  iVar1 = msys::MComSys::_sys;
  iVar5 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar5 = iVar1;
  }
  *(undefined1 *)(iVar5 + 0xe6508) = 0;
  msys::MListWndPBase::setEnableInput(*(MListWndPBase **)(param_1 + 0x54),false);
  msys::MListWndPBase::setDispCursor(*(MListWndPBase **)(param_1 + 0x54),false);
  msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x44),0x11,0,(char *)0x0,(char *)0x0);
  msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x48),0x12,0,(char *)0x0,(char *)0x0);
  local_28 = msys::MListWndPBase::getCurPos(*(MListWndPBase **)(param_1 + 0x54));
  local_20 = 0;
  uStack_1c = 0x42840000;
  iVar2 = msys::MListWndPBase::getSelectItem(*(MListWndPBase **)(param_1 + 0x54));
  iVar1 = msys::MComSys::_sys;
  iVar5 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar5 = iVar1;
  }
  uVar3 = *(undefined4 *)(*(int *)(iVar5 + 0xe904c) + 0x10);
  *(int *)(param_1 + 0x88) = iVar2;
  uVar3 = VectorSignedToFloat(uVar3,(byte)(in_fpscr >> 0x16) & 3);
  (**(code **)**(undefined4 **)(param_1 + 0x84))
            (uVar3,*(undefined4 **)(param_1 + 0x84),iVar2,&local_28,&local_20);
  ad::lyt::LytNumReel3::setValueInstant((LytNumReel3 *)(param_1 + 0x76e4),1);
  ad::lyt::LytNumReel3::setValueInstant
            ((LytNumReel3 *)(param_1 + 0x74b4),(uint)*(ushort *)(iVar2 + 4));
  iVar5 = 0;
  do {
    piVar4 = *(int **)(param_1 + iVar5 * 4 + 0x77c4);
    (**(code **)(*piVar4 + 0x28))(piVar4,1);
    iVar5 = iVar5 + 1;
  } while (iVar5 < 2);
  FUN_17009940(param_1,1);
  *(code **)(param_1 + 0x20) = FUN_1700ce94;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


// FUNC 0x1700c6cc shop::ShopMenu_SellPage::Core::vfunc_0x10 (ShopMenu)
//   size 0x110 | file ShopMenu+0xc6cc | callers(0) | datarefs 1

void shop::ShopMenu_SellPage::Core::vfunc_0x10(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = msys::MComSys::_sys;
  if (param_2 == 4) {
    FUN_1700beb8(msys::MComSys::_sys + 0x49368,0x110017,0,0,0);
    iVar2 = msys::MComSys::_sys;
    iVar1 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar1 = iVar2;
    }
    *(undefined1 *)(iVar1 + 0xe6508) = 0;
    iVar2 = msys::MComSys::_sys;
    iVar1 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar1 = iVar2;
    }
    *(undefined1 *)(iVar1 + 0xe650a) = 1;
  }
  else if (param_2 == 5) {
    if (*(char *)(*(int *)(param_1 + 0x78) + 0x48) == '\0') {
      iVar2 = *(int *)(param_1 + 8);
      if (iVar2 == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar2 = iVar1;
      }
      *(undefined1 *)(iVar2 + 0xe6508) = 0;
      msys::MListWndPBase::setEnableInput(*(MListWndPBase **)(param_1 + 0x54),false);
      *(undefined1 *)(param_1 + 0x7d) = 0;
    }
    else {
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
      }
      *(undefined1 *)(*(int *)(param_1 + 8) + 0xe6508) = 1;
      iVar2 = *(int *)(param_1 + 8);
      if (iVar2 == 0) {
        *(int *)(param_1 + 8) = iVar1;
        iVar2 = iVar1;
      }
      *(undefined1 *)(iVar2 + 0xe650a) = 1;
    }
    msys::MCursorBase::setVisible(*(MCursorBase **)(param_1 + 0x58),false);
    FUN_1700ad98(*(undefined4 *)(param_1 + 0x58));
    return;
  }
  return;
}


// FUNC 0x1700c7e4 FUN_1700c7e4 (ShopMenu)
//   size 0x5c | file ShopMenu+0xc7e4 | callers(0) | datarefs 2

void FUN_1700c7e4(int param_1)

{
  MComSys *pMVar1;
  int iVar2;
  MComSys *this;
  
  iVar2 = (**(code **)(**(int **)(param_1 + 0x48) + 0x20))();
  pMVar1 = msys::MComSys::_sys;
  if (iVar2 == 0) {
    this = *(MComSys **)(param_1 + 8);
    if (*(MComSys **)(param_1 + 8) == (MComSys *)0x0) {
      *(MComSys **)(param_1 + 8) = msys::MComSys::_sys;
      this = pMVar1;
    }
    iVar2 = msys::MComSys::getNextPage(this);
    if (*(char *)(iVar2 + 0x14) != '\0') {
      *(undefined1 **)(param_1 + 0x18) = &LAB_1700d108;
      *(undefined4 *)(param_1 + 0x1c) = 0;
    }
  }
  return;
}


// FUNC 0x1700c854 FUN_1700c854 (ShopMenu)
//   size 0x2fc | file ShopMenu+0xc854 | callers(0)

void FUN_1700c854(int param_1,int param_2,int param_3)

{
  char cVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  code *pcVar6;
  int unaff_r5;
  int *piVar7;
  
  iVar3 = msys::MComSys::_sys;
  pcVar2 = *(code **)(param_1 + 0x20);
  pcVar6 = FUN_1700cb7c;
  if (pcVar2 == FUN_1700cb7c) {
    pcVar6 = *(code **)(param_1 + 0x24);
  }
  if ((pcVar2 == FUN_1700cb7c && pcVar6 == (code *)0x0) ||
     ((pcVar2 == (code *)0x0 &&
      ((*(uint *)(param_1 + 0x24) & 1) == 0 || *(uint *)(param_1 + 0x24) == 0)))) {
    cVar1 = *(char *)(param_2 + 0x48);
    if (param_3 != 1) {
      if (param_3 != 4) {
        if (param_3 != 5) {
          return;
        }
        if (cVar1 == '\0') {
          if (*(int *)(param_1 + 8) == 0) {
            *(int *)(param_1 + 8) = msys::MComSys::_sys;
          }
          else {
            iVar3 = *(int *)(param_1 + 8);
          }
          *(undefined1 *)(iVar3 + 0xe6508) = 0;
          msys::MListWndPBase::setDispCursor(*(MListWndPBase **)(param_1 + 0x54),true);
          GameWork::addItem((GameWork *)&gGameWork,**(undefined2 **)(param_1 + 0x88),
                            (int)-*(char *)(param_1 + 0x7760));
          GameWork::addCoin((GameWork *)&gGameWork,*(int *)(param_1 + 30000));
          iVar4 = *(int *)(param_1 + 0x60);
          iVar3 = GameWork::getItemNum((GameWork *)&gGameWork,**(ushort **)(param_1 + 0x88));
          ad::lyt::LytNumReel3::setValueInstant((LytNumReel3 *)(iVar4 + 0x6d94),iVar3);
          piVar7 = *(int **)(param_1 + 0x5c);
          iVar3 = GameWork::getCoin((GameWork *)&gGameWork);
          iVar4 = FUN_1700beb8(*piVar7 + 0x49368,0x11001e,0,0,0);
          piVar7[1] = iVar4;
          ad::lyt::LytNumReel3::setValue((LytNumReel3 *)(piVar7 + 0x56),iVar3);
          msys::MDfxChr::playDfx((MDfxChr *)(*(int *)(param_1 + 0x84) + 0x6edc),0x25);
          FUN_17009940(param_1,0);
          *(code **)(param_1 + 0x20) = FUN_1700cda4;
          *(undefined4 *)(param_1 + 0x24) = 0;
        }
        else if (cVar1 == '\x01') {
          if (*(int *)(param_1 + 8) == 0) {
            *(int *)(param_1 + 8) = msys::MComSys::_sys;
          }
          else {
            iVar3 = *(int *)(param_1 + 8);
          }
          *(undefined1 *)(iVar3 + 0xe6508) = 0;
          msys::MListWndPBase::setEnableInput(*(MListWndPBase **)(param_1 + 0x54),false);
          msys::MListWndPBase::setDispCursor(*(MListWndPBase **)(param_1 + 0x54),true);
          msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x44),0x11,1,(char *)0x0,(char *)0x0);
          msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x48),0x12,1,(char *)0x0,(char *)0x0);
          FUN_17009940(param_1,0);
          *(code **)(param_1 + 0x20) = FUN_1700cf40;
          *(undefined4 *)(param_1 + 0x24) = 0;
        }
        else {
          if (*(int *)(param_1 + 8) == 0) {
            *(int *)(param_1 + 8) = msys::MComSys::_sys;
          }
          *(undefined1 *)(*(int *)(param_1 + 8) + 0xe6508) = 1;
          iVar4 = *(int *)(param_1 + 8);
          if (iVar4 == 0) {
            *(int *)(param_1 + 8) = iVar3;
            iVar4 = iVar3;
          }
          *(undefined1 *)(iVar4 + 0xe650a) = 1;
        }
        msys::MCursorBase::setVisible(*(MCursorBase **)(param_1 + 0x58),false);
        return;
      }
      if (cVar1 == '\0') {
        uVar5 = 0x110016;
      }
      else {
        uVar5 = 0x110017;
      }
      FUN_1700beb8(msys::MComSys::_sys + 0x49368,uVar5,0,0,0);
      iVar4 = msys::MComSys::_sys;
      iVar3 = *(int *)(param_1 + 8);
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar3 = iVar4;
      }
      *(undefined1 *)(iVar3 + 0xe6508) = 0;
      iVar4 = msys::MComSys::_sys;
      iVar3 = *(int *)(param_1 + 8);
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar3 = iVar4;
      }
      *(undefined1 *)(iVar3 + 0xe650a) = 1;
    }
    if (cVar1 == '\0') {
      unaff_r5 = 0x15;
    }
    else if (cVar1 == '\x01') {
      unaff_r5 = 0x14;
    }
    if (unaff_r5 != *(char *)(*(int *)(param_1 + 0x58) + 0x18)) {
      *(char *)(*(int *)(param_1 + 0x58) + 0x18) = (char)unaff_r5;
      msys::MCursorBase::setVisible(*(MCursorBase **)(param_1 + 0x58),true);
      FUN_1700ad98(*(undefined4 *)(param_1 + 0x58));
      FUN_1700beb8(msys::MComSys::_sys + 0x49368,0x110015,0,0,0);
    }
  }
  return;
}


// FUNC 0x1700cb7c FUN_1700cb7c (ShopMenu)
//   size 0x140 | file ShopMenu+0xcb7c | callers(0) | datarefs 3

void FUN_1700cb7c(int param_1,uint *param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined1 uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar2 = *param_2;
  uVar6 = (uint)(*(char *)(*(int *)(param_1 + 0x58) + 0x18) != '\x15');
  uVar5 = uVar6;
  if ((uVar2 & 0x401) == 0) {
    if ((uVar2 & 0x802) == 0) {
      if ((uVar2 & 0x20) == 0) {
        if ((uVar2 & 0x10) == 0) {
          iVar3 = FUN_17009698(param_1 + 0x80);
          if (iVar3 != 0) {
            FUN_17009940(param_1,2);
            *(code **)(param_1 + 0x20) = FUN_1700cfc8;
            *(undefined4 *)(param_1 + 0x24) = 0;
          }
        }
        else {
          uVar5 = uVar6 + 1;
          if (1 < uVar5) {
            uVar5 = 0;
          }
        }
      }
      else {
        uVar5 = uVar6 - 1;
        if ((int)(uVar6 - 1) < 0) goto LAB_1700cc14;
      }
    }
    else {
LAB_1700cc14:
      uVar5 = 1;
    }
  }
  else {
    iVar3 = param_1 + uVar6 * 4;
    (**(code **)(**(int **)(iVar3 + 0x77cc) + 0x10))();
    (**(code **)(**(int **)(iVar3 + 0x77cc) + 0xc))();
    iVar1 = msys::MComSys::_sys;
    iVar3 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar3 = iVar1;
    }
    *(undefined1 *)(iVar3 + 0xe6508) = 0;
  }
  if (uVar5 != uVar6) {
    FUN_1700beb8(msys::MComSys::_sys + 0x49368,0x110015,0,0,0);
    if (uVar5 == 0) {
      iVar3 = *(int *)(param_1 + 0x58);
      uVar4 = 0x15;
    }
    else {
      if (uVar5 != 1) goto LAB_1700ccb0;
      iVar3 = *(int *)(param_1 + 0x58);
      uVar4 = 0x14;
    }
    *(undefined1 *)(iVar3 + 0x18) = uVar4;
  }
LAB_1700ccb0:
  FUN_1700ad98(*(undefined4 *)(param_1 + 0x58));
  return;
}


// FUNC 0x1700ccd0 FUN_1700ccd0 (ShopMenu)
//   size 0xbc | file ShopMenu+0xccd0 | callers(0) | datarefs 1

void FUN_1700ccd0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = msys::MLyt::isEnableAnime(*(MLyt **)(param_1 + 0x48));
  if ((iVar2 == 0) && (iVar2 = msys::MLyt::isEnableAnime(*(MLyt **)(param_1 + 0x44)), iVar2 == 0)) {
    msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x44),0x19,0,"EXP_PNL_U_down",(char *)0x0);
    msys::MListWndPBase::setEnableInput(*(MListWndPBase **)(param_1 + 0x54),true);
    msys::MListWndPBase::setDispCursor(*(MListWndPBase **)(param_1 + 0x54),true);
    FUN_17009940(param_1,0);
    *(undefined2 *)(param_1 + 0x7e) = 0xffff;
    iVar1 = msys::MComSys::_sys;
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar1;
    }
    *(undefined1 *)(iVar2 + 0xe6508) = 1;
    iVar1 = msys::MComSys::_sys;
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar1;
    }
    *(undefined1 *)(iVar2 + 0xe650a) = 1;
    *(code **)(param_1 + 0x20) = FUN_1700c3f4;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x1700cda4 FUN_1700cda4 (ShopMenu)
//   size 0xe8 | file ShopMenu+0xcda4 | callers(0) | datarefs 1

void FUN_1700cda4(int param_1)

{
  int iVar1;
  int iVar2;
  undefined2 *puVar3;
  undefined4 uVar4;
  
  iVar1 = *(int *)(param_1 + 0x5c);
  if (*(int *)(iVar1 + 0x1dc) == *(int *)(iVar1 + 0x1d4)) {
    SndSeCtrl::stop(*(SndSeCtrl **)(iVar1 + 4),0);
    iVar1 = msys::MComSys::_sys;
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar1;
    }
    if (*(char *)(iVar2 + 0xea02e) == '\x01') {
      uVar4 = 0x2000;
    }
    else {
      uVar4 = 0x1000;
    }
    FUN_17009a4c(*(undefined4 *)(param_1 + 0x54),uVar4);
    iVar1 = msys::MListWndPBase::getItemNum(*(MListWndPBase **)(param_1 + 0x54));
    if (iVar1 == 0) {
      FUN_170099b8(param_1,0);
    }
    else {
      puVar3 = (undefined2 *)msys::MListWndPBase::getCurItem();
      FUN_170099b8(param_1,*puVar3);
    }
    msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x44),0x11,1,(char *)0x0,(char *)0x0);
    msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x48),0x12,1,(char *)0x0,(char *)0x0);
    *(code **)(param_1 + 0x20) = FUN_1700cf40;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x1700ce94 FUN_1700ce94 (ShopMenu)
//   size 0xa4 | file ShopMenu+0xce94 | callers(0) | datarefs 2

void FUN_1700ce94(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_17009648(param_1 + 0x80);
  if (((iVar1 == 0) && (iVar1 = msys::MLyt::isEnableAnime(*(MLyt **)(param_1 + 0x48)), iVar1 == 0))
     && (iVar2 = msys::MLyt::isEnableAnime(*(MLyt **)(param_1 + 0x44)), iVar1 = msys::MComSys::_sys,
        iVar2 == 0)) {
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
    *(undefined1 *)(*(int *)(param_1 + 0x58) + 0x18) = 0x15;
    msys::MCursorBase::setVisible(*(MCursorBase **)(param_1 + 0x58),true);
    FUN_1700ad98(*(undefined4 *)(param_1 + 0x58));
    *(code **)(param_1 + 0x20) = FUN_1700cb7c;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x1700cf40 FUN_1700cf40 (ShopMenu)
//   size 0x80 | file ShopMenu+0xcf40 | callers(0) | datarefs 3

void FUN_1700cf40(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = msys::MLyt::isEnableAnime(*(MLyt **)(param_1 + 0x48));
  if ((iVar1 == 0) &&
     (iVar2 = msys::MLyt::isEnableAnime(*(MLyt **)(param_1 + 0x44)), iVar1 = msys::MComSys::_sys,
     iVar2 == 0)) {
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
    msys::MListWndPBase::setEnableInput(*(MListWndPBase **)(param_1 + 0x54),true);
    *(code **)(param_1 + 0x20) = FUN_1700c3f4;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x1700cfc8 FUN_1700cfc8 (ShopMenu)
//   size 0x3c | file ShopMenu+0xcfc8 | callers(0) | datarefs 1

void FUN_1700cfc8(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_1701276c(param_1 + 0x80);
  if (iVar1 == 0) {
    FUN_17009940(param_1,1);
    *(code **)(param_1 + 0x20) = FUN_1700cb7c;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  FUN_1700ad98(*(undefined4 *)(param_1 + 0x58));
  return;
}


// FUNC 0x1700d008 shop::ShopMenu_SellPage::Core::vfunc_0x8 (ShopMenu)
//   size 0xfc | file ShopMenu+0xd008 | callers(0) | datarefs 1

int shop::ShopMenu_SellPage::Core::vfunc_0x8(int *param_1,MInput *param_2)

{
  MInput MVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  code *extraout_r2;
  code *pcVar7;
  undefined4 *puVar8;
  bool bVar9;
  uint in_fpscr;
  undefined4 local_20;
  undefined4 local_1c;
  
  msys::MPageBase::updateInputAllChr((MPageBase *)param_1[1],param_2);
  bVar9 = (param_1[9] & 1U) == 0;
  pcVar7 = extraout_r2;
  if (bVar9) {
    pcVar7 = (code *)param_1[8];
  }
  piVar3 = (int *)((int)param_1 + (param_1[9] >> 1));
  if (!bVar9) {
    pcVar7 = *(code **)(*piVar3 + param_1[8]);
  }
  (*pcVar7)(piVar3,param_2);
  uVar4 = msys::MListWndPBase::isTpNeutral((MListWndPBase *)param_1[0x14]);
  MVar1 = param_2[0x11];
  bVar9 = MVar1 == (MInput)0x0;
  if (bVar9) {
    MVar1 = param_2[0x12];
  }
  puVar8 = (undefined4 *)(undefined1 *)0x0;
  if ((!bVar9 || MVar1 != (MInput)0x0) && uVar4 != 0) {
    local_20 = VectorSignedToFloat(*(ushort *)(param_2 + 0x14) - 0xa0,(byte)(in_fpscr >> 0x16) & 3);
    local_1c = VectorSignedToFloat(0x78 - (uint)*(ushort *)(param_2 + 0x16),
                                   (byte)(in_fpscr >> 0x16) & 3);
    puVar8 = &local_20;
  }
  uVar5 = (**(code **)(*param_1 + 0xc))(param_1,param_2);
  iVar2 = msys::MComSys::_sys;
  iVar6 = param_1[2];
  if (param_1[2] == 0) {
    param_1[2] = msys::MComSys::_sys;
    iVar6 = iVar2;
  }
  (**(code **)(*(int *)param_1[0x10] + 8))
            ((int *)param_1[0x10],puVar8,(int)*(char *)(iVar6 + 0xe6508) & uVar4 & uVar5);
  return (int)*(char *)((int)param_1 + 0x7d);
}


// FUNC 0x1700d11c FUN_1700d11c (ShopMenu)
//   size 0x34 | file ShopMenu+0xd11c | callers(0) | datarefs 1

void FUN_1700d11c(int param_1)

{
  msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x44),0x19,1,"EXP_PNL_U_down",(char *)0x0);
  *(code **)(param_1 + 0x18) = FUN_1700c7e4;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  return;
}


// FUNC 0x1700d164 FUN_1700d164 (ShopMenu)
//   size 0x110 | file ShopMenu+0xd164 | callers(1) 0x1700d450

void FUN_1700d164(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)FUN_1700a0e8();
  *puVar1 = &shop::ShopMenu_SellPage::Core::vtable;
  puVar1[0x23] = &shop::BuyPnlBase::ItemPnlBase::vtable;
  puVar1 = (undefined4 *)MoveVBase::MoveVBase((MoveVBase *)(puVar1 + 0x24));
  *puVar1 = &vtable_for_5MoveVILj1EE;
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(puVar1 + 0xc,FUN_17014c78,0x2c,1);
  *(int *)(iVar2 + -8) = iVar2;
  *(undefined1 *)(iVar2 + -4) = 1;
  puVar1 = (undefined4 *)FUN_1700c0a0(iVar2 + 0x34);
  *puVar1 = &msys::MMsg::vtable;
  iVar2 = MessageSimple::MessageSimple((MessageSimple *)(puVar1 + 0x53));
  *(undefined4 *)(iVar2 + 0x6ae0) = 0;
  *(undefined1 *)(iVar2 + 0x6ae4) = 0;
  *(undefined1 *)(iVar2 + 0x6ae5) = 0;
  *(undefined4 *)(iVar2 + 0x6ae8) = 0;
  *(undefined4 *)(iVar2 + 0x6aec) = 0;
  *(undefined4 *)(iVar2 + 0x6af4) = 0x400;
  iVar2 = msys::MLytNum::MLytNum((MLytNum *)(iVar2 + 0x6af8));
  iVar2 = msys::MDfxChr::MDfxChr((MDfxChr *)(iVar2 + 0x230));
  *(undefined ***)(iVar2 + -0x6edc) = &shop::BuyPnlBase::ItemPnlCA::vtable;
  puVar1 = (undefined4 *)FUN_1700c0a0(iVar2 + 0x17c);
  *puVar1 = &msys::MCellAnime::vtable;
  iVar2 = CellAnime::CellAnime((CellAnime *)(puVar1 + 0x53));
  *(undefined1 *)(iVar2 + 300) = 0xff;
  *(undefined1 *)(iVar2 + 0x12d) = 0xff;
  *(undefined1 *)(iVar2 + 0x12e) = 0xff;
  *(undefined1 *)(iVar2 + 0x12f) = 0xff;
  iVar2 = msys::MLytNum::MLytNum((MLytNum *)(iVar2 + 0x134));
  iVar2 = msys::MLytNum::MLytNum((MLytNum *)(iVar2 + 0x230));
  *(code **)(iVar2 + -0x7584) = FUN_1700c18c;
  *(undefined4 *)(iVar2 + -0x7580) = 0;
  *(code **)(iVar2 + -0x757c) = FUN_1700d11c;
  *(undefined4 *)(iVar2 + -0x7578) = 0;
  *(code **)(iVar2 + -0x7574) = FUN_1700ccd0;
  *(undefined4 *)(iVar2 + -0x7570) = 0;
  return;
}


// FUNC 0x1700d294 shop::ShopMenu_SellPage::Core::vfunc_0x4 (ShopMenu)
//   size 0xc4 | file ShopMenu+0xd294 | callers(0) | datarefs 1

void shop::ShopMenu_SellPage::Core::vfunc_0x4(undefined4 *param_1)

{
  int iVar1;
  void *pvVar2;
  
  *param_1 = &vtable;
  iVar1 = msys::MLytNum::~MLytNum((MLytNum *)(param_1 + 0x1d65));
  iVar1 = msys::MLytNum::~MLytNum((MLytNum *)(iVar1 + -0x230));
  *(undefined ***)(iVar1 + -0x72d8) = &BuyPnlBase::ItemPnlCA::vtable;
  *(undefined ***)(iVar1 + -0x280) = &msys::MCellAnime::vtable;
  iVar1 = CellAnime::~CellAnime((CellAnime *)(iVar1 + -0x134));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  *(undefined ***)(iVar1 + -0x7058) = &BuyPnlBase::ItemPnlBase::vtable;
  iVar1 = msys::MDfxChr::~MDfxChr((MDfxChr *)(iVar1 + -0x17c));
  iVar1 = msys::MLytNum::~MLytNum((MLytNum *)(iVar1 + -0x230));
  *(undefined ***)(iVar1 + -0x6c44) = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar1 = MessageSimple::~MessageSimple((MessageSimple *)(iVar1 + -0x6af8));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  *(undefined ***)(iVar1 + -100) = &vtable_for_5MoveVILj1EE;
  __aeabi_vec_dtor(iVar1 + -0x34,MoveWorkF::~MoveWorkF,0x2c,1);
  iVar1 = MoveVBase::~MoveVBase((MoveVBase *)(iVar1 + -100));
  pvVar2 = (void *)FUN_170095f4(iVar1 + -0x90);
  operator_delete(pvVar2);
  return;
}


// FUNC 0x1700d374 shop::ShopMenu_SellPage::Core::vfunc_0x0 (ShopMenu)
//   size 0xc0 | file ShopMenu+0xd374 | callers(0) | datarefs 1

void shop::ShopMenu_SellPage::Core::vfunc_0x0(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &vtable;
  iVar1 = msys::MLytNum::~MLytNum((MLytNum *)(param_1 + 0x1d65));
  iVar1 = msys::MLytNum::~MLytNum((MLytNum *)(iVar1 + -0x230));
  *(undefined ***)(iVar1 + -0x72d8) = &BuyPnlBase::ItemPnlCA::vtable;
  *(undefined ***)(iVar1 + -0x280) = &msys::MCellAnime::vtable;
  iVar1 = CellAnime::~CellAnime((CellAnime *)(iVar1 + -0x134));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  *(undefined ***)(iVar1 + -0x7058) = &BuyPnlBase::ItemPnlBase::vtable;
  iVar1 = msys::MDfxChr::~MDfxChr((MDfxChr *)(iVar1 + -0x17c));
  iVar1 = msys::MLytNum::~MLytNum((MLytNum *)(iVar1 + -0x230));
  *(undefined ***)(iVar1 + -0x6c44) = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar1 = MessageSimple::~MessageSimple((MessageSimple *)(iVar1 + -0x6af8));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  *(undefined ***)(iVar1 + -100) = &vtable_for_5MoveVILj1EE;
  __aeabi_vec_dtor(iVar1 + -0x34,MoveWorkF::~MoveWorkF,0x2c,1);
  iVar1 = MoveVBase::~MoveVBase((MoveVBase *)(iVar1 + -100));
  FUN_170095f4(iVar1 + -0x90);
  return;
}


// FUNC 0x1700d450 shop::ShopMenu_SellPage::vfunc_0x30 (ShopMenu)
//   size 0x30 | file ShopMenu+0xd450 | callers(0) | datarefs 1

void shop::ShopMenu_SellPage::vfunc_0x30(int param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(0x77d4,*(MemAlcBase **)(param_1 + 0x18),(char *)0x0,0);
  uVar2 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_1700d164(pvVar1,param_1);
  }
  *(undefined4 *)(param_1 + 0x20) = uVar2;
  return;
}


// FUNC 0x1700d484 shop::ShopMenu_SellPage::vfunc_0x24 (ShopMenu)
//   size 0x8 | file ShopMenu+0xd484 | callers(0) | datarefs 1

undefined4 shop::ShopMenu_SellPage::vfunc_0x24(void)

{
  return 4;
}


// FUNC 0x1700d48c shop::ShopMenu_SellPage::vfunc_0x4 (ShopMenu)
//   size 0x10 | file ShopMenu+0xd48c | callers(0) | datarefs 1

void shop::ShopMenu_SellPage::vfunc_0x4(void)

{
  void *pvVar1;
  
  pvVar1 = (void *)ShopMenu_PageBase::vfunc_0x0();
  operator_delete(pvVar1);
  return;
}


// FUNC 0x1700d49c ->shop::ShopMenu_PageBase::vfunc_0x0 (ShopMenu)
//   size 0x4 | file ShopMenu+0xd49c | callers(0) | datarefs 1
// veneer/thunk -> 0x17009fbc shop::ShopMenu_PageBase::vfunc_0x0 (ShopMenu)

// FUNC 0x1700d580 FUN_1700d580 (ShopMenu)
//   size 0x298 | file ShopMenu+0xd580 | callers(0) | datarefs 1

void FUN_1700d580(void *param_1)

{
  int iVar1;
  int *piVar2;
  void *pvVar3;
  AnimButton *pAVar4;
  int iVar5;
  short *psVar6;
  undefined2 *puVar7;
  
  piVar2 = *(int **)(*(int *)((int)param_1 + 4) + 0x18);
  pvVar3 = (void *)(**(code **)(*piVar2 + 0xc))(piVar2,0x80,0);
  MemAlc::initCore((MemAlc *)((int)param_1 + 0x28),pvVar3,0x80);
  pAVar4 = (AnimButton *)
           ad::ctrl::ButtonGroup::FindButtonByName
                     (*(ButtonGroup **)((int)param_1 + 0x40),"btn_RETURN");
  *(AnimButton **)((int)param_1 + 0x78) = pAVar4;
  ad::ctrl::AnimButton::SetStateChangeCallback
            (pAVar4,(_func_void_AnimButton_ptr_State_State_void_ptr *)&LAB_17007df0,param_1);
  *(undefined4 *)(*(int *)((int)param_1 + 0x78) + 0x48) = 0;
  (**(code **)(**(int **)((int)param_1 + 0x78) + 0x28))(*(int **)((int)param_1 + 0x78),1);
  iVar5 = *(int *)((int)param_1 + 0x40);
  for (piVar2 = *(int **)(iVar5 + 8); piVar2 != (int *)(iVar5 + 8); piVar2 = (int *)*piVar2) {
    (**(code **)(piVar2[-5] + 0x28))(piVar2 + -5,0);
  }
  pAVar4 = (AnimButton *)
           ad::ctrl::ButtonGroup::FindButtonByName
                     (*(ButtonGroup **)((int)param_1 + 0x40),"btn_RETURN");
  *(AnimButton **)((int)param_1 + 0x78) = pAVar4;
  ad::ctrl::AnimButton::SetStateChangeCallback
            (pAVar4,(_func_void_AnimButton_ptr_State_State_void_ptr *)&LAB_17007df0,param_1);
  *(undefined4 *)(*(int *)((int)param_1 + 0x78) + 0x48) = 0;
  (**(code **)(**(int **)((int)param_1 + 0x78) + 0x28))(*(int **)((int)param_1 + 0x78),1);
  iVar5 = *(int *)((int)param_1 + 0x40);
  for (piVar2 = *(int **)(iVar5 + 8); piVar2 != (int *)(iVar5 + 8); piVar2 = (int *)*piVar2) {
    (**(code **)(piVar2[-5] + 0x28))(piVar2 + -5,0);
  }
  iVar5 = 0;
  do {
    pAVar4 = (AnimButton *)
             ad::ctrl::ButtonGroup::FindButtonByName
                       (*(ButtonGroup **)((int)param_1 + 0x40),(char *)(&DAT_17021cb4)[iVar5]);
    *(AnimButton **)((int)param_1 + iVar5 * 4 + 0x7104) = pAVar4;
    ad::ctrl::AnimButton::SetStateChangeCallback
              (pAVar4,(_func_void_AnimButton_ptr_State_State_void_ptr *)&DAT_1700db30,param_1);
    *(int *)(*(int *)((int)param_1 + iVar5 * 4 + 0x7104) + 0x48) = iVar5;
    piVar2 = *(int **)((int)param_1 + iVar5 * 4 + 0x7104);
    (**(code **)(*piVar2 + 0x28))(piVar2,0);
    iVar5 = iVar5 + 1;
  } while (iVar5 < 2);
  ad::lyt::LytAnim::init
            ((LytAnim *)((int)param_1 + 0x80),*(Layout **)(*(int *)((int)param_1 + 0x48) + 0x150),
             "SET_BADGE","");
  iVar1 = msys::MComSys::_sys;
  iVar5 = *(int *)((int)param_1 + 8);
  if (*(int *)((int)param_1 + 8) == 0) {
    *(int *)((int)param_1 + 8) = msys::MComSys::_sys;
    iVar5 = iVar1;
  }
  *(int *)((int)param_1 + 0x9c) = iVar5;
  *(undefined4 *)((int)param_1 + 0xa4) = 0;
  FUN_1700ba88((int)param_1 + 0xa8,iVar5,*(undefined4 *)((int)param_1 + 0x48));
  *(int *)((int)param_1 + 0x7100) = (int)param_1 + 0x80;
  *(int *)((int)param_1 + 0xa0) = (int)param_1 + 0xa8;
  iVar1 = msys::MComSys::_sys;
  iVar5 = *(int *)((int)param_1 + 8);
  if (*(int *)((int)param_1 + 8) == 0) {
    *(int *)((int)param_1 + 8) = msys::MComSys::_sys;
    iVar5 = iVar1;
  }
  psVar6 = (short *)shop::GetBootInfo();
  FUN_1700917c((MListWndPBase *)(iVar5 + 0xebe90),(int)*psVar6,0x3000,0);
  msys::MListWndPBase::resetCur((MListWndPBase *)(iVar5 + 0xebe90));
  *(byte *)(*(int *)(iVar5 + 0x104b4c) + 0x44) = *(byte *)(*(int *)(iVar5 + 0x104b4c) + 0x44) & 0xfe
  ;
  msys::MListWndPBase::setEnableInput((MListWndPBase *)(iVar5 + 0xf4cac),false);
  puVar7 = (undefined2 *)msys::MListWndPBase::getCurItem();
  FUN_1700979c(*(undefined4 *)((int)param_1 + 100),*puVar7);
  FUN_17009104(param_1,0);
  FUN_1700983c(*(undefined4 *)((int)param_1 + 100),0);
  *(undefined1 *)(*(int *)((int)param_1 + 4) + 0x14) = 1;
  *(undefined **)((int)param_1 + 0x10) = &DAT_1700e49c;
  *(undefined4 *)((int)param_1 + 0x14) = 0;
  return;
}


// FUNC 0x1700d854 FUN_1700d854 (ShopMenu)
//   size 0x124 | file ShopMenu+0xd854 | callers(1) 0x1700d98c

void FUN_1700d854(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint in_fpscr;
  undefined8 local_20;
  undefined4 local_18;
  undefined4 uStack_14;
  
  FUN_1700beb8(msys::MComSys::_sys + 0x49368,0x110016,0,0,0);
  iVar2 = msys::MComSys::_sys;
  iVar1 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar1 = iVar2;
  }
  *(undefined1 *)(iVar1 + 0xe6508) = 0;
  msys::MListWndPBase::setEnableInput(*(MListWndPBase **)(param_1 + 0x50),false);
  msys::MListWndPBase::setDispCursor(*(MListWndPBase **)(param_1 + 0x50),false);
  msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x44),0x10,0,(char *)0x0,(char *)0x0);
  msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x48),0x11,0,(char *)0x0,(char *)0x0);
  local_20 = msys::MListWndPBase::getCurPos(*(MListWndPBase **)(param_1 + 0x50));
  local_18 = 0;
  uStack_14 = 0x42300000;
  uVar3 = msys::MListWndPBase::getSelectItem(*(MListWndPBase **)(param_1 + 0x50));
  iVar2 = msys::MComSys::_sys;
  iVar1 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar1 = iVar2;
  }
  uVar4 = *(undefined4 *)(*(int *)(iVar1 + 0xe904c) + 0x10);
  *(undefined4 *)(param_1 + 0xa4) = uVar3;
  uVar4 = VectorSignedToFloat(uVar4,(byte)(in_fpscr >> 0x16) & 3);
  (**(code **)**(undefined4 **)(param_1 + 0xa0))
            (uVar4,*(undefined4 **)(param_1 + 0xa0),uVar3,&local_20,&local_18);
  FUN_17009104(param_1,1);
  *(code **)(param_1 + 0x20) = FUN_1700e258;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


// FUNC 0x1700d98c FUN_1700d98c (ShopMenu)
//   size 0x194 | file ShopMenu+0xd98c | callers(0) | datarefs 4

void FUN_1700d98c(int param_1,uint *param_2)

{
  int iVar1;
  int iVar2;
  undefined2 *puVar3;
  MListWndPBase *pMVar4;
  
  iVar1 = msys::MListWndPBase::getSelectItem(*(MListWndPBase **)(param_1 + 0x50));
  if ((iVar1 == 0) ||
     (iVar1 = msys::MListWndPBase::getSelectItem(*(MListWndPBase **)(param_1 + 0x50)),
     *(char *)(iVar1 + 0xe) == '\0')) {
    iVar1 = (**(code **)(**(int **)(param_1 + 0x50) + 0x20))();
    if ((iVar1 == 0) &&
       ((iVar1 = msys::MListWndPBase::getListWnd(*(MListWndPBase **)(param_1 + 0x50)),
        *(int *)(iVar1 + 0x1cc) == 0 && ((*param_2 & 0x802) != 0)))) {
      (**(code **)(**(int **)(param_1 + 0x78) + 0x10))();
      (**(code **)(**(int **)(param_1 + 0x78) + 0xc))();
      iVar1 = msys::MComSys::_sys;
      iVar2 = *(int *)(param_1 + 8);
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar2 = iVar1;
      }
      *(undefined1 *)(iVar2 + 0xe6508) = 0;
    }
  }
  else {
    FUN_1700d854(param_1);
  }
  iVar1 = msys::MListWndPBase::getListWnd(*(MListWndPBase **)(param_1 + 0x50));
  if ((*(char *)(iVar1 + 0x144) != '\0') &&
     (iVar1 = msys::MListWndPBase::getListWnd(*(MListWndPBase **)(param_1 + 0x50)),
     *(int *)(iVar1 + 0x1cc) == 0)) {
    msys::MListWndPBase::getListWnd(*(MListWndPBase **)(param_1 + 0x50));
    puVar3 = (undefined2 *)ad::ui::UIListWindowPlusLyt::getCurItem();
    iVar1 = msys::MListWndPBase::getCurNo(*(MListWndPBase **)(param_1 + 0x50));
    if (iVar1 != *(short *)(param_1 + 0x7e)) {
      if (puVar3 != (undefined2 *)0x0) {
        FUN_1700979c(*(undefined4 *)(param_1 + 100),*puVar3);
        pMVar4 = *(MListWndPBase **)(param_1 + 0x50);
        iVar1 = msys::MListWndPBase::getListWnd(pMVar4);
        if (*(short *)(*(int *)(*(int *)(pMVar4 + 0x8e08) + (uint)*(byte *)(iVar1 + 0x149) * 4) + 4)
            != 0) {
          pMVar4 = *(MListWndPBase **)(param_1 + 0x50);
          iVar1 = msys::MListWndPBase::getListWnd(pMVar4);
          PutRegFlag(*(ushort *)
                      (*(int *)(*(int *)(pMVar4 + 0x8e08) + (uint)*(byte *)(iVar1 + 0x149) * 4) + 4)
                     ,1.0,(GlobalEvent *)0x0,(LocalEvent *)0x0);
        }
      }
      iVar1 = msys::MListWndPBase::getListWnd(*(MListWndPBase **)(param_1 + 0x50));
      *(ushort *)(param_1 + 0x7e) = (ushort)*(byte *)(iVar1 + 0x149);
    }
  }
  return;
}


// FUNC 0x1700db3c FUN_1700db3c (ShopMenu)
//   size 0x2a0 | file ShopMenu+0xdb3c | callers(0)

void FUN_1700db3c(int param_1,int param_2,int param_3)

{
  char cVar1;
  ushort uVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  code *pcVar7;
  int *piVar8;
  
  iVar4 = msys::MComSys::_sys;
  pcVar3 = *(code **)(param_1 + 0x20);
  pcVar7 = FUN_1700df78;
  if (pcVar3 == FUN_1700df78) {
    pcVar7 = *(code **)(param_1 + 0x24);
  }
  if ((pcVar3 == FUN_1700df78 && pcVar7 == (code *)0x0) ||
     ((pcVar3 == (code *)0x0 &&
      ((*(uint *)(param_1 + 0x24) & 1) == 0 || *(uint *)(param_1 + 0x24) == 0)))) {
    cVar1 = *(char *)(param_2 + 0x48);
    if (param_3 != 1) {
      if (param_3 != 4) {
        if (param_3 != 5) {
          return;
        }
        if (cVar1 == '\0') {
          if (*(int *)(param_1 + 8) == 0) {
            *(int *)(param_1 + 8) = msys::MComSys::_sys;
          }
          else {
            iVar4 = *(int *)(param_1 + 8);
          }
          *(undefined1 *)(iVar4 + 0xe6508) = 0;
          msys::MListWndPBase::setDispCursor(*(MListWndPBase **)(param_1 + 0x50),true);
          piVar8 = *(int **)(param_1 + 0x5c);
          iVar5 = piVar8[0x75];
          iVar4 = msys::MListWndPBase::getCurItem();
          uVar2 = *(ushort *)(iVar4 + 4);
          iVar4 = FUN_1700beb8(*piVar8 + 0x49368,0x11001e,0,0,0);
          piVar8[1] = iVar4;
          ad::lyt::LytNumReel3::setValue((LytNumReel3 *)(piVar8 + 0x56),iVar5 - (uint)uVar2);
          msys::MDfxChr::playDfx((MDfxChr *)(*(int *)(param_1 + 0xa0) + 0x6edc),0x24);
          FUN_17009104(param_1,0);
          *(code **)(param_1 + 0x20) = FUN_1700e088;
          *(undefined4 *)(param_1 + 0x24) = 0;
        }
        else if (cVar1 == '\x01') {
          if (*(int *)(param_1 + 8) == 0) {
            *(int *)(param_1 + 8) = msys::MComSys::_sys;
          }
          else {
            iVar4 = *(int *)(param_1 + 8);
          }
          *(undefined1 *)(iVar4 + 0xe6508) = 0;
          msys::MListWndPBase::setEnableInput(*(MListWndPBase **)(param_1 + 0x50),false);
          msys::MListWndPBase::setDispCursor(*(MListWndPBase **)(param_1 + 0x50),true);
          msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x44),0x10,1,(char *)0x0,(char *)0x0);
          msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x48),0x11,1,(char *)0x0,(char *)0x0);
          FUN_17009104(param_1,0);
          *(code **)(param_1 + 0x20) = FUN_1700e304;
          *(undefined4 *)(param_1 + 0x24) = 0;
        }
        else {
          if (*(int *)(param_1 + 8) == 0) {
            *(int *)(param_1 + 8) = msys::MComSys::_sys;
          }
          *(undefined1 *)(*(int *)(param_1 + 8) + 0xe6508) = 1;
          iVar5 = *(int *)(param_1 + 8);
          if (iVar5 == 0) {
            *(int *)(param_1 + 8) = iVar4;
            iVar5 = iVar4;
          }
          *(undefined1 *)(iVar5 + 0xe650a) = 1;
        }
        msys::MCursorBase::setVisible(*(MCursorBase **)(param_1 + 0x58),false);
        return;
      }
      if (cVar1 == '\0') {
        uVar6 = 0x110016;
      }
      else {
        uVar6 = 0x110017;
      }
      FUN_1700beb8(msys::MComSys::_sys + 0x49368,uVar6,0,0,0);
      iVar5 = msys::MComSys::_sys;
      iVar4 = *(int *)(param_1 + 8);
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar4 = iVar5;
      }
      *(undefined1 *)(iVar4 + 0xe6508) = 0;
      iVar5 = msys::MComSys::_sys;
      iVar4 = *(int *)(param_1 + 8);
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar4 = iVar5;
      }
      *(undefined1 *)(iVar4 + 0xe650a) = 1;
    }
    if ((char)(cVar1 + '\x13') != *(char *)(*(int *)(param_1 + 0x58) + 0x18)) {
      FUN_1700beb8(msys::MComSys::_sys + 0x49368,0x110015,0,0,0);
      *(char *)(*(int *)(param_1 + 0x58) + 0x18) = cVar1 + '\x13';
      msys::MCursorBase::setVisible(*(MCursorBase **)(param_1 + 0x58),true);
      FUN_1700ad98(*(undefined4 *)(param_1 + 0x58));
    }
  }
  return;
}


// FUNC 0x1700ddfc shop::ShopMenu_BadgePage::Core::vfunc_0x10 (ShopMenu)
//   size 0x110 | file ShopMenu+0xddfc | callers(0) | datarefs 1

void shop::ShopMenu_BadgePage::Core::vfunc_0x10(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = msys::MComSys::_sys;
  if (param_2 == 4) {
    FUN_1700beb8(msys::MComSys::_sys + 0x49368,0x110017,0,0,0);
    iVar2 = msys::MComSys::_sys;
    iVar1 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar1 = iVar2;
    }
    *(undefined1 *)(iVar1 + 0xe6508) = 0;
    iVar2 = msys::MComSys::_sys;
    iVar1 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar1 = iVar2;
    }
    *(undefined1 *)(iVar1 + 0xe650a) = 1;
  }
  else if (param_2 == 5) {
    if (*(char *)(*(int *)(param_1 + 0x78) + 0x48) == '\0') {
      iVar2 = *(int *)(param_1 + 8);
      if (iVar2 == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar2 = iVar1;
      }
      *(undefined1 *)(iVar2 + 0xe6508) = 0;
      msys::MListWndPBase::setEnableInput(*(MListWndPBase **)(param_1 + 0x50),false);
      *(undefined1 *)(param_1 + 0x7d) = 0;
    }
    else {
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
      }
      *(undefined1 *)(*(int *)(param_1 + 8) + 0xe6508) = 1;
      iVar2 = *(int *)(param_1 + 8);
      if (iVar2 == 0) {
        *(int *)(param_1 + 8) = iVar1;
        iVar2 = iVar1;
      }
      *(undefined1 *)(iVar2 + 0xe650a) = 1;
    }
    msys::MCursorBase::setVisible(*(MCursorBase **)(param_1 + 0x58),false);
    FUN_1700ad98(*(undefined4 *)(param_1 + 0x58));
    return;
  }
  return;
}


// FUNC 0x1700df14 FUN_1700df14 (ShopMenu)
//   size 0x5c | file ShopMenu+0xdf14 | callers(0) | datarefs 2

void FUN_1700df14(int param_1)

{
  MComSys *pMVar1;
  int iVar2;
  MComSys *this;
  
  iVar2 = (**(code **)(**(int **)(param_1 + 0x48) + 0x20))();
  pMVar1 = msys::MComSys::_sys;
  if (iVar2 == 0) {
    this = *(MComSys **)(param_1 + 8);
    if (*(MComSys **)(param_1 + 8) == (MComSys *)0x0) {
      *(MComSys **)(param_1 + 8) = msys::MComSys::_sys;
      this = pMVar1;
    }
    iVar2 = msys::MComSys::getNextPage(this);
    if (*(char *)(iVar2 + 0x14) != '\0') {
      *(undefined1 **)(param_1 + 0x18) = &LAB_1700e48c;
      *(undefined4 *)(param_1 + 0x1c) = 0;
    }
  }
  return;
}


// FUNC 0x1700df78 FUN_1700df78 (ShopMenu)
//   size 0x100 | file ShopMenu+0xdf78 | callers(0) | datarefs 2

void FUN_1700df78(int param_1,uint *param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  cVar1 = *(char *)(*(int *)(param_1 + 0x58) + 0x18);
  uVar3 = *param_2;
  iVar6 = (int)(char)(cVar1 + -0x13);
  iVar5 = iVar6;
  if ((uVar3 & 0x401) != 0) {
    iVar4 = param_1 + iVar6 * 4;
    (**(code **)(**(int **)(iVar4 + 0x7104) + 0x10))();
    (**(code **)(**(int **)(iVar4 + 0x7104) + 0xc))();
    iVar2 = msys::MComSys::_sys;
    iVar4 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar4 = iVar2;
    }
    *(undefined1 *)(iVar4 + 0xe6508) = 0;
    goto LAB_1700e034;
  }
  if ((uVar3 & 0x802) == 0) {
    if ((uVar3 & 0x20) == 0) {
      if (((uVar3 & 0x10) != 0) && (iVar5 = (int)(char)(cVar1 + -0x12), 1 < iVar5)) {
        iVar5 = 0;
      }
      goto LAB_1700e034;
    }
    iVar5 = (int)(char)(cVar1 + -0x14);
    if (-1 < (char)(cVar1 + -0x14)) goto LAB_1700e034;
  }
  iVar5 = 1;
LAB_1700e034:
  if (iVar5 != iVar6) {
    FUN_1700beb8(msys::MComSys::_sys + 0x49368,0x110015,0,0,0);
    *(char *)(*(int *)(param_1 + 0x58) + 0x18) = (char)iVar5 + '\x13';
  }
  FUN_1700ad98(*(undefined4 *)(param_1 + 0x58));
  return;
}


// FUNC 0x1700e088 FUN_1700e088 (ShopMenu)
//   size 0xf0 | file ShopMenu+0xe088 | callers(0) | datarefs 1

void FUN_1700e088(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  short *psVar4;
  undefined4 *puVar5;
  
  iVar3 = *(int *)(param_1 + 0x5c);
  if (*(int *)(iVar3 + 0x1dc) == *(int *)(iVar3 + 0x1d4)) {
    SndSeCtrl::stop(*(SndSeCtrl **)(iVar3 + 4),0);
    GameWork::addItem((GameWork *)&gGameWork,**(undefined2 **)(param_1 + 0xa4),1);
    GameWork::addCoin((GameWork *)&gGameWork,-(uint)*(ushort *)(*(int *)(param_1 + 0xa4) + 4));
    puVar5 = msys::MComSys::_sys;
    puVar1 = *(undefined4 **)(param_1 + 8);
    if (*(undefined4 **)(param_1 + 8) == (undefined4 *)0x0) {
      *(undefined4 **)(param_1 + 8) = msys::MComSys::_sys;
      puVar1 = puVar5;
    }
    puVar2 = msys::MComSys::_sys;
    puVar5 = &msys::MComSys::_sys;
    if (puVar1 == (undefined4 *)0x0) {
      *(undefined4 **)(param_1 + 8) = msys::MComSys::_sys;
      puVar5 = puVar2;
    }
    if (puVar1 != (undefined4 *)0x0) {
      puVar5 = puVar1;
    }
    puVar1[0x3a80c] = puVar5[0x3a80c] + (uint)*(ushort *)(*(int *)(param_1 + 0xa4) + 4);
    psVar4 = (short *)shop::GetBootInfo();
    FUN_1700917c(*(undefined4 *)(param_1 + 0x50),(int)*psVar4,0x3000,0,param_4);
    msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x44),0x10,1,(char *)0x0,(char *)0x0);
    msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x48),0x11,1,(char *)0x0,(char *)0x0);
    *(code **)(param_1 + 0x20) = FUN_1700e304;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x1700e184 FUN_1700e184 (ShopMenu)
//   size 0xbc | file ShopMenu+0xe184 | callers(0) | datarefs 1

void FUN_1700e184(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = msys::MLyt::isEnableAnime(*(MLyt **)(param_1 + 0x48));
  if ((iVar2 == 0) && (iVar2 = msys::MLyt::isEnableAnime(*(MLyt **)(param_1 + 0x44)), iVar2 == 0)) {
    msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x44),0x19,0,"EXP_PNL_U_down",(char *)0x0);
    msys::MListWndPBase::setEnableInput(*(MListWndPBase **)(param_1 + 0x50),true);
    msys::MListWndPBase::setDispCursor(*(MListWndPBase **)(param_1 + 0x50),true);
    FUN_17009104(param_1,0);
    *(undefined2 *)(param_1 + 0x7e) = 0xffff;
    iVar1 = msys::MComSys::_sys;
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar1;
    }
    *(undefined1 *)(iVar2 + 0xe6508) = 1;
    iVar1 = msys::MComSys::_sys;
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar1;
    }
    *(undefined1 *)(iVar2 + 0xe650a) = 1;
    *(code **)(param_1 + 0x20) = FUN_1700d98c;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x1700e258 FUN_1700e258 (ShopMenu)
//   size 0xa4 | file ShopMenu+0xe258 | callers(0) | datarefs 2

void FUN_1700e258(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_17009648(param_1 + 0x9c);
  if (((iVar1 == 0) && (iVar1 = msys::MLyt::isEnableAnime(*(MLyt **)(param_1 + 0x48)), iVar1 == 0))
     && (iVar2 = msys::MLyt::isEnableAnime(*(MLyt **)(param_1 + 0x44)), iVar1 = msys::MComSys::_sys,
        iVar2 == 0)) {
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
    *(undefined1 *)(*(int *)(param_1 + 0x58) + 0x18) = 0x13;
    msys::MCursorBase::setVisible(*(MCursorBase **)(param_1 + 0x58),true);
    FUN_1700ad98(*(undefined4 *)(param_1 + 0x58));
    *(code **)(param_1 + 0x20) = FUN_1700df78;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x1700e304 FUN_1700e304 (ShopMenu)
//   size 0x80 | file ShopMenu+0xe304 | callers(0) | datarefs 3

void FUN_1700e304(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = msys::MLyt::isEnableAnime(*(MLyt **)(param_1 + 0x48));
  if ((iVar1 == 0) &&
     (iVar2 = msys::MLyt::isEnableAnime(*(MLyt **)(param_1 + 0x44)), iVar1 = msys::MComSys::_sys,
     iVar2 == 0)) {
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
    msys::MListWndPBase::setEnableInput(*(MListWndPBase **)(param_1 + 0x50),true);
    *(code **)(param_1 + 0x20) = FUN_1700d98c;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x1700e38c shop::ShopMenu_BadgePage::Core::vfunc_0x8 (ShopMenu)
//   size 0xfc | file ShopMenu+0xe38c | callers(0) | datarefs 1

int shop::ShopMenu_BadgePage::Core::vfunc_0x8(int *param_1,MInput *param_2)

{
  MInput MVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  code *extraout_r2;
  code *pcVar7;
  undefined4 *puVar8;
  bool bVar9;
  uint in_fpscr;
  undefined4 local_20;
  undefined4 local_1c;
  
  msys::MPageBase::updateInputAllChr((MPageBase *)param_1[1],param_2);
  bVar9 = (param_1[9] & 1U) == 0;
  pcVar7 = extraout_r2;
  if (bVar9) {
    pcVar7 = (code *)param_1[8];
  }
  piVar3 = (int *)((int)param_1 + (param_1[9] >> 1));
  if (!bVar9) {
    pcVar7 = *(code **)(*piVar3 + param_1[8]);
  }
  (*pcVar7)(piVar3,param_2);
  uVar4 = msys::MListWndPBase::isTpNeutral((MListWndPBase *)param_1[0x14]);
  MVar1 = param_2[0x11];
  bVar9 = MVar1 == (MInput)0x0;
  if (bVar9) {
    MVar1 = param_2[0x12];
  }
  puVar8 = (undefined4 *)(undefined1 *)0x0;
  if ((!bVar9 || MVar1 != (MInput)0x0) && uVar4 != 0) {
    local_20 = VectorSignedToFloat(*(ushort *)(param_2 + 0x14) - 0xa0,(byte)(in_fpscr >> 0x16) & 3);
    local_1c = VectorSignedToFloat(0x78 - (uint)*(ushort *)(param_2 + 0x16),
                                   (byte)(in_fpscr >> 0x16) & 3);
    puVar8 = &local_20;
  }
  uVar5 = (**(code **)(*param_1 + 0xc))(param_1,param_2);
  iVar2 = msys::MComSys::_sys;
  iVar6 = param_1[2];
  if (param_1[2] == 0) {
    param_1[2] = msys::MComSys::_sys;
    iVar6 = iVar2;
  }
  (**(code **)(*(int *)param_1[0x10] + 8))
            ((int *)param_1[0x10],puVar8,(int)*(char *)(iVar6 + 0xe6508) & uVar4 & uVar5);
  return (int)*(char *)((int)param_1 + 0x7d);
}


// FUNC 0x1700e4a0 FUN_1700e4a0 (ShopMenu)
//   size 0x34 | file ShopMenu+0xe4a0 | callers(0) | datarefs 1

void FUN_1700e4a0(int param_1)

{
  msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x44),0x19,1,"EXP_PNL_U_down",(char *)0x0);
  *(code **)(param_1 + 0x18) = FUN_1700df14;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  return;
}


// FUNC 0x1700e4e8 FUN_1700e4e8 (ShopMenu)
//   size 0xd8 | file ShopMenu+0xe4e8 | callers(1) 0x1700e720

void FUN_1700e4e8(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)FUN_1700a0e8();
  *puVar1 = &shop::ShopMenu_BadgePage::Core::vtable;
  iVar2 = FUN_1700b0a8(puVar1 + 0x20);
  *(undefined ***)(iVar2 + 0x28) = &shop::BuyPnlBase::ItemPnlBase::vtable;
  puVar1 = (undefined4 *)MoveVBase::MoveVBase((MoveVBase *)(iVar2 + 0x2c));
  *puVar1 = &vtable_for_5MoveVILj1EE;
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(puVar1 + 0xc,FUN_17014c78,0x2c,1);
  *(int *)(iVar2 + -8) = iVar2;
  *(undefined1 *)(iVar2 + -4) = 1;
  puVar1 = (undefined4 *)FUN_1700c0a0(iVar2 + 0x34);
  *puVar1 = &msys::MMsg::vtable;
  iVar2 = MessageSimple::MessageSimple((MessageSimple *)(puVar1 + 0x53));
  *(undefined4 *)(iVar2 + 0x6ae0) = 0;
  *(undefined1 *)(iVar2 + 0x6ae4) = 0;
  *(undefined1 *)(iVar2 + 0x6ae5) = 0;
  *(undefined4 *)(iVar2 + 0x6ae8) = 0;
  *(undefined4 *)(iVar2 + 0x6aec) = 0;
  *(undefined4 *)(iVar2 + 0x6af4) = 0x400;
  iVar2 = msys::MLytNum::MLytNum((MLytNum *)(iVar2 + 0x6af8));
  iVar2 = msys::MDfxChr::MDfxChr((MDfxChr *)(iVar2 + 0x230));
  *(undefined ***)(iVar2 + -0x6edc) = &shop::BuyPnlBase::ItemPnlPane::vtable;
  *(code **)(iVar2 + -0x6f74) = FUN_1700d580;
  *(undefined4 *)(iVar2 + -0x6f70) = 0;
  *(code **)(iVar2 + -0x6f6c) = FUN_1700e4a0;
  *(undefined4 *)(iVar2 + -0x6f68) = 0;
  *(code **)(iVar2 + -0x6f64) = FUN_1700e184;
  *(undefined4 *)(iVar2 + -0x6f60) = 0;
  return;
}


// FUNC 0x1700e5dc shop::ShopMenu_BadgePage::Core::vfunc_0x4 (ShopMenu)
//   size 0x8c | file ShopMenu+0xe5dc | callers(0) | datarefs 1

void shop::ShopMenu_BadgePage::Core::vfunc_0x4(undefined4 *param_1)

{
  int iVar1;
  void *pvVar2;
  
  *param_1 = &vtable;
  param_1[0x2a] = &BuyPnlBase::ItemPnlBase::vtable;
  iVar1 = msys::MDfxChr::~MDfxChr((MDfxChr *)(param_1 + 0x1be1));
  iVar1 = msys::MLytNum::~MLytNum((MLytNum *)(iVar1 + -0x230));
  *(undefined ***)(iVar1 + -0x6c44) = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar1 = MessageSimple::~MessageSimple((MessageSimple *)(iVar1 + -0x6af8));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  *(undefined ***)(iVar1 + -100) = &vtable_for_5MoveVILj1EE;
  __aeabi_vec_dtor(iVar1 + -0x34,MoveWorkF::~MoveWorkF,0x2c,1);
  iVar1 = MoveVBase::~MoveVBase((MoveVBase *)(iVar1 + -100));
  *(undefined4 *)(iVar1 + -0x20) = 0;
  pvVar2 = (void *)FUN_170095f4(iVar1 + -0xac);
  operator_delete(pvVar2);
  return;
}


// FUNC 0x1700e680 shop::ShopMenu_BadgePage::Core::vfunc_0x0 (ShopMenu)
//   size 0x88 | file ShopMenu+0xe680 | callers(0) | datarefs 1

void shop::ShopMenu_BadgePage::Core::vfunc_0x0(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &vtable;
  param_1[0x2a] = &BuyPnlBase::ItemPnlBase::vtable;
  iVar1 = msys::MDfxChr::~MDfxChr((MDfxChr *)(param_1 + 0x1be1));
  iVar1 = msys::MLytNum::~MLytNum((MLytNum *)(iVar1 + -0x230));
  *(undefined ***)(iVar1 + -0x6c44) = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar1 = MessageSimple::~MessageSimple((MessageSimple *)(iVar1 + -0x6af8));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  *(undefined ***)(iVar1 + -100) = &vtable_for_5MoveVILj1EE;
  __aeabi_vec_dtor(iVar1 + -0x34,MoveWorkF::~MoveWorkF,0x2c,1);
  iVar1 = MoveVBase::~MoveVBase((MoveVBase *)(iVar1 + -100));
  *(undefined4 *)(iVar1 + -0x20) = 0;
  FUN_170095f4(iVar1 + -0xac);
  return;
}


// FUNC 0x1700e720 shop::ShopMenu_BadgePage::vfunc_0x30 (ShopMenu)
//   size 0x30 | file ShopMenu+0xe720 | callers(0) | datarefs 1

void shop::ShopMenu_BadgePage::vfunc_0x30(int param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(0x710c,*(MemAlcBase **)(param_1 + 0x18),(char *)0x0,0);
  uVar2 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_1700e4e8(pvVar1,param_1);
  }
  *(undefined4 *)(param_1 + 0x20) = uVar2;
  return;
}


// FUNC 0x1700e754 shop::ShopMenu_BadgePage::vfunc_0x24 (ShopMenu)
//   size 0x8 | file ShopMenu+0xe754 | callers(0) | datarefs 1

undefined4 shop::ShopMenu_BadgePage::vfunc_0x24(void)

{
  return 3;
}


// FUNC 0x1700e75c shop::ShopMenu_BadgePage::vfunc_0x4 (ShopMenu)
//   size 0x10 | file ShopMenu+0xe75c | callers(0) | datarefs 1

void shop::ShopMenu_BadgePage::vfunc_0x4(void)

{
  void *pvVar1;
  
  pvVar1 = (void *)ShopMenu_PageBase::vfunc_0x0();
  operator_delete(pvVar1);
  return;
}


// FUNC 0x1700e76c ->shop::ShopMenu_PageBase::vfunc_0x0 (ShopMenu)
//   size 0x4 | file ShopMenu+0xe76c | callers(0) | datarefs 1
// veneer/thunk -> 0x17009fbc shop::ShopMenu_PageBase::vfunc_0x0 (ShopMenu)

// FUNC 0x1700e770 FUN_1700e770 (ShopMenu)
//   size 0x890 | file ShopMenu+0xe770 | callers(0) | datarefs 1

void FUN_1700e770(void *param_1)

{
  char cVar1;
  int *piVar2;
  void *pvVar3;
  ushort *puVar4;
  int iVar5;
  int iVar6;
  wchar_t *pwVar7;
  AnimButton *pAVar8;
  undefined4 uVar9;
  short *psVar10;
  undefined2 *puVar11;
  int *piVar12;
  undefined4 *puVar13;
  MChrBase *pMVar14;
  uint uVar15;
  Resource *pRVar16;
  
  piVar2 = *(int **)(*(int *)((int)param_1 + 4) + 0x18);
  pvVar3 = (void *)(**(code **)(*piVar2 + 0xc))(piVar2,0x80,0);
  MemAlc::initCore((MemAlc *)((int)param_1 + 0x28),pvVar3,0x80);
  puVar4 = (ushort *)shop::GetBootInfo();
  cVar1 = (&DAT_1701674b)[(*puVar4 & 0xffff0fff) * 4];
  if (cVar1 == '\x02') {
    *(undefined2 *)((int)param_1 + 0x82) = 0;
  }
  else if (cVar1 == '\x04' || cVar1 == '\x06') {
    *(undefined2 *)((int)param_1 + 0x82) = 2;
  }
  iVar5 = *(int *)((int)param_1 + 8);
  uVar15 = 0;
  iVar6 = iVar5;
  if (iVar5 == 0) {
    iVar6 = msys::MComSys::_sys;
  }
  if (iVar5 == 0) {
    *(int *)((int)param_1 + 8) = iVar6;
  }
  do {
    iVar5 = iVar6 + uVar15 * 0x27c;
    pMVar14 = (MChrBase *)(iVar5 + 0xeaed4);
    *(undefined1 *)(iVar5 + 0xeb015) = 0;
    msys::MLyt::detachMChr((MLyt *)(iVar6 + 0xea034),pMVar14);
    msys::MLyt::attachMChr
              ((MLyt *)(iVar6 + 0xea034),pMVar14,"INS_STATUS_CHARA_OBJ","STATUS_EQUIP_SET",
               (char *)0x0,(char *)0x0);
    uVar15 = uVar15 + 1 & 0xff;
  } while (uVar15 < 3);
  iVar6 = msys::MLyt::getPane(*(MLyt **)((int)param_1 + 0x44),"EQUIP_LR",(char *)0x0,(char *)0x0);
  *(byte *)(iVar6 + 0x44) = *(short *)((int)param_1 + 0x82) == 0 | *(byte *)(iVar6 + 0x44) & 0xfe;
  msys::StatusPanel::setChr(*(StatusPanel **)((int)param_1 + 0x6c),*(uchar *)((int)param_1 + 0x82));
  iVar5 = msys::MComSys::_sys;
  iVar6 = *(int *)((int)param_1 + 8);
  if (*(int *)((int)param_1 + 8) == 0) {
    *(int *)((int)param_1 + 8) = msys::MComSys::_sys;
    iVar6 = iVar5;
  }
  msys::StatusPanel::setParam
            (*(StatusPanel **)((int)param_1 + 0x6c),
             (DataPc *)(iVar6 + *(short *)((int)param_1 + 0x82) * 0xb0 + 0xe9e10));
  uVar15 = 0;
  *(undefined1 *)(*(int *)((int)param_1 + 0x4c) + *(short *)((int)param_1 + 0x82) * 0x27c + 0x141) =
       1;
  do {
    iVar5 = msys::MComSys::_sys;
    piVar2 = (int *)(*(int *)((int)param_1 + 0x70) + uVar15 * 0x6ee0);
    iVar6 = *(int *)((int)param_1 + 8);
    if (*(int *)((int)param_1 + 8) == 0) {
      *(int *)((int)param_1 + 8) = msys::MComSys::_sys;
      iVar6 = iVar5;
    }
    iVar6 = DataPc::getEquip((DataPc *)(iVar6 + *(short *)((int)param_1 + 0x82) * 0xb0 + 0xe9e10),
                             (uchar)uVar15);
    if (iVar6 == 0) {
      *(undefined1 *)((int)piVar2 + 0x6da5) = 0;
      iVar6 = *piVar2;
      uVar9 = LMS_GetTextIndexByLabel(iVar6 + 0xe93ec,"Menu_Sys_invalid_equip_name");
      pwVar7 = (wchar_t *)LMS_GetText(iVar6 + 0xe93ec,uVar9);
      msys::MMsg::playStr((MMsg *)(piVar2 + 8),pwVar7,(InsParam *)0x0,false);
    }
    else {
      *(undefined1 *)((int)piVar2 + 0x6da5) = 1;
      iVar5 = ad::db::GetItemData((ushort)iVar6);
      CellAnime::play((CellAnime *)(piVar2 + 0x1b6c),*(char *)(iVar5 + 0x60) + '\x01',0,1.0);
      pwVar7 = (wchar_t *)ad::db::GetItemMsg(iVar6,0);
      msys::MMsg::playStr((MMsg *)(piVar2 + 8),pwVar7,(InsParam *)0x0,false);
    }
    iVar6 = msys::MComSys::_sys;
    if (uVar15 != 0) {
      piVar2 = (int *)(*(int *)((int)param_1 + 0x74) + uVar15 * 0x6ec4 + -0x6ec4);
      iVar5 = *(int *)((int)param_1 + 8);
      if (*(int *)((int)param_1 + 8) == 0) {
        *(int *)((int)param_1 + 8) = msys::MComSys::_sys;
        iVar5 = iVar6;
      }
      iVar6 = DataPc::getEquip((DataPc *)(iVar5 + *(short *)((int)param_1 + 0x82) * 0xb0 + 0xe9e10),
                               (uchar)uVar15);
      if (iVar6 == 0) {
        *(undefined1 *)((int)piVar2 + 0x6d89) = 0;
        iVar6 = *piVar2;
        uVar9 = LMS_GetTextIndexByLabel(iVar6 + 0xe93ec,"Menu_Sys_invalid_equip_name");
        pwVar7 = (wchar_t *)LMS_GetText(iVar6 + 0xe93ec,uVar9);
        msys::MMsg::playStr((MMsg *)(piVar2 + 1),pwVar7,(InsParam *)0x0,false);
      }
      else {
        *(undefined1 *)((int)piVar2 + 0x6d89) = 1;
        iVar5 = ad::db::GetItemData((ushort)iVar6);
        CellAnime::play((CellAnime *)(piVar2 + 0x1b65),*(char *)(iVar5 + 0x60) + '\x01',0,1.0);
        pwVar7 = (wchar_t *)ad::db::GetItemMsg(iVar6,0);
        msys::MMsg::playStr((MMsg *)(piVar2 + 1),pwVar7,(InsParam *)0x0,false);
      }
    }
    iVar6 = msys::MComSys::_sys;
    uVar15 = uVar15 + 1 & 0xff;
  } while (uVar15 < 3);
  iVar5 = *(int *)((int)param_1 + 8);
  if (*(int *)((int)param_1 + 8) == 0) {
    *(int *)((int)param_1 + 8) = msys::MComSys::_sys;
    iVar5 = iVar6;
  }
  pRVar16 = *(Resource **)((int)param_1 + 0x3c);
  *(int *)((int)param_1 + 0x88) = iVar5;
  *(undefined4 *)((int)param_1 + 0x90) = 0;
  FUN_1700ba88((int)param_1 + 0x94,iVar5,*(undefined4 *)((int)param_1 + 0x48));
  msys::MCellAnime::init((MCellAnime *)((int)param_1 + 0x70ec),pRVar16);
  *(byte *)((int)param_1 + 0x72db) = *(byte *)((int)param_1 + 0x72db) | 3;
  *(undefined1 *)((int)param_1 + 0x72d0) = 0;
  *(undefined1 *)((int)param_1 + 0x72d1) = 0;
  msys::MLyt::attachMChrF
            (*(MLyt **)((int)param_1 + 0xf4),(MChrBase *)((int)param_1 + 0x70ec),
             "INS_ICON_ITEM_list",(char *)0x0,(char *)0x0);
  *(int *)((int)param_1 + 0x8c) = (int)param_1 + 0x94;
  iVar5 = msys::MComSys::_sys;
  iVar6 = *(int *)((int)param_1 + 8);
  if (*(int *)((int)param_1 + 8) == 0) {
    *(int *)((int)param_1 + 8) = msys::MComSys::_sys;
    iVar6 = iVar5;
  }
  FUN_17001b3c((int)param_1 + 0x7368,iVar6,*(undefined4 *)((int)param_1 + 0x3c));
  pAVar8 = (AnimButton *)
           ad::ctrl::ButtonGroup::FindButtonByName
                     (*(ButtonGroup **)((int)param_1 + 0x40),"btn_RETURN");
  *(AnimButton **)((int)param_1 + 0x78) = pAVar8;
  ad::ctrl::AnimButton::SetStateChangeCallback
            (pAVar8,(_func_void_AnimButton_ptr_State_State_void_ptr *)&LAB_17007df0,param_1);
  *(uint *)(*(int *)((int)param_1 + 0x78) + 8) =
       *(uint *)(*(int *)((int)param_1 + 0x78) + 8) & 0xffffffdf;
  *(undefined4 *)(*(int *)((int)param_1 + 0x78) + 0x48) = 0;
  (**(code **)(**(int **)((int)param_1 + 0x78) + 0x28))(*(int **)((int)param_1 + 0x78),1);
  iVar6 = *(int *)((int)param_1 + 0x40);
  for (piVar2 = *(int **)(iVar6 + 8); piVar2 != (int *)(iVar6 + 8); piVar2 = (int *)*piVar2) {
    (**(code **)(piVar2[-5] + 0x28))(piVar2 + -5,0);
  }
  iVar6 = 0;
  do {
    pAVar8 = (AnimButton *)
             ad::ctrl::ButtonGroup::FindButtonByName
                       (*(ButtonGroup **)((int)param_1 + 0x40),(char *)(&DAT_17021c94)[iVar6]);
    *(AnimButton **)((int)param_1 + iVar6 * 4 + 0x22e80) = pAVar8;
    ad::ctrl::AnimButton::SetStateChangeCallback
              (pAVar8,(_func_void_AnimButton_ptr_State_State_void_ptr *)&DAT_1700fee8,param_1);
    iVar5 = *(int *)((int)param_1 + iVar6 * 4 + 0x22e80);
    *(uint *)(iVar5 + 8) = *(uint *)(iVar5 + 8) & 0xffffffdf;
    *(int *)(*(int *)((int)param_1 + iVar6 * 4 + 0x22e80) + 0x48) = iVar6;
    piVar2 = *(int **)((int)param_1 + iVar6 * 4 + 0x22e80);
    (**(code **)(*piVar2 + 0x28))(piVar2,0);
    uVar9 = msys::MLyt::getPane(*(MLyt **)((int)param_1 + 0x48),(char *)(&DAT_17021c94)[iVar6],
                                (char *)0x0,(char *)0x0);
    iVar5 = iVar6 + 1;
    *(undefined4 *)((int)param_1 + iVar6 * 4 + 0x22e70) = uVar9;
    iVar6 = iVar5;
  } while (iVar5 < 2);
  iVar6 = 0;
  do {
    uVar9 = msys::MLyt::getPane(*(MLyt **)((int)param_1 + 0x48),(char *)(&DAT_17021c9c)[iVar6],
                                (char *)0x0,(char *)0x0);
    iVar5 = iVar6 * 4;
    iVar6 = iVar6 + 1;
    *(undefined4 *)((int)param_1 + iVar5 + 0x22e78) = uVar9;
  } while (iVar6 < 2);
  iVar6 = 0;
  do {
    pAVar8 = (AnimButton *)
             ad::ctrl::ButtonGroup::FindButtonByName
                       (*(ButtonGroup **)((int)param_1 + 0x40),(char *)(&DAT_17021ca4)[iVar6]);
    *(AnimButton **)((int)param_1 + iVar6 * 4 + 0x22e88) = pAVar8;
    ad::ctrl::AnimButton::SetStateChangeCallback
              (pAVar8,(_func_void_AnimButton_ptr_State_State_void_ptr *)&DAT_1700f70c,param_1);
    iVar5 = *(int *)((int)param_1 + iVar6 * 4 + 0x22e88);
    *(uint *)(iVar5 + 8) = *(uint *)(iVar5 + 8) & 0xffffffdf;
    *(int *)(*(int *)((int)param_1 + iVar6 * 4 + 0x22e88) + 0x48) = iVar6;
    piVar2 = *(int **)((int)param_1 + iVar6 * 4 + 0x22e88);
    (**(code **)(*piVar2 + 0x28))(piVar2,0);
    iVar6 = iVar6 + 1;
  } while (iVar6 < 2);
  iVar6 = 0;
  do {
    pAVar8 = (AnimButton *)
             ad::ctrl::ButtonGroup::FindButtonByName
                       (*(ButtonGroup **)((int)param_1 + 0x40),(char *)(&DAT_17021cac)[iVar6]);
    *(AnimButton **)((int)param_1 + iVar6 * 4 + 0x22e90) = pAVar8;
    ad::ctrl::AnimButton::SetStateChangeCallback
              (pAVar8,(_func_void_AnimButton_ptr_State_State_void_ptr *)&DAT_1700f44c,param_1);
    iVar5 = *(int *)((int)param_1 + iVar6 * 4 + 0x22e90);
    *(uint *)(iVar5 + 8) = *(uint *)(iVar5 + 8) & 0xffffffdf;
    *(int *)(*(int *)((int)param_1 + iVar6 * 4 + 0x22e90) + 0x48) = iVar6;
    piVar2 = *(int **)((int)param_1 + iVar6 * 4 + 0x22e90);
    (**(code **)(*piVar2 + 0x28))(piVar2,0);
    iVar6 = iVar6 + 1;
  } while (iVar6 < 2);
  iVar6 = 0;
  do {
    cVar1 = (char)iVar6;
    iVar5 = *(int *)((int)param_1 + 0x58);
    uVar9 = msys::MLyt::getParts
                      (*(MLyt **)((int)param_1 + 0x48),(char *)(&DAT_17021cac)[iVar6],(char *)0x0,
                       (char *)0x0);
    iVar6 = iVar6 + 1;
    *(undefined4 *)(iVar5 + 0x30 + (char)(cVar1 + '\x16') * 4) = uVar9;
    iVar5 = msys::MComSys::_sys;
  } while (iVar6 < 2);
  uVar9 = *(undefined4 *)(*(int *)((int)param_1 + 4) + 0x18);
  iVar6 = *(int *)((int)param_1 + 8);
  if (*(int *)((int)param_1 + 8) == 0) {
    *(int *)((int)param_1 + 8) = msys::MComSys::_sys;
    iVar6 = iVar5;
  }
  pvVar3 = *(void **)(iVar6 + 0xe93e0);
  *(undefined4 *)((int)param_1 + 0x22e6c) = 0x401;
  *(undefined4 *)((int)param_1 + 0x22e28) = 0x401;
  *(undefined4 *)((int)param_1 + 0x22e64) = uVar9;
  *(undefined4 *)((int)param_1 + 0x22e68) = 0;
  *(undefined4 *)((int)param_1 + 0x22e2c) = 0;
  *(undefined4 *)((int)param_1 + 0x22e30) = 0;
  *(undefined1 *)((int)param_1 + 0x22e50) = 1;
  *(undefined1 *)((int)param_1 + 0x22e51) = 0;
  *(undefined4 *)((int)param_1 + 0x22e58) = 0xffffffff;
  *(int *)((int)param_1 + 0x22e48) = (int)param_1 + 0x22e60;
  *(undefined4 *)((int)param_1 + 0x22e4c) = 0;
  *(undefined4 *)((int)param_1 + 0x22e5c) = 0xffffffff;
  Message::init((Message *)((int)param_1 + 0x1c0c4));
  Message::setMsgDat((Message *)((int)param_1 + 0x1c0c4),pvVar3);
  FUN_1700bd6c((int)param_1 + 0x1bf78);
  MoveVBase::stop((MoveVBase *)((int)param_1 + 0x1c044));
  *(undefined4 *)((int)param_1 + 0x1c060) = 0;
  *(undefined4 *)((int)param_1 + 0x1c064) = 0;
  *(undefined4 *)((int)param_1 + 0x1c068) = 0xc3430000;
  *(undefined4 *)((int)param_1 + 0x1c048) = *(undefined4 *)((int)param_1 + 0x1c060);
  *(undefined4 *)((int)param_1 + 0x1c04c) = 0;
  *(undefined4 *)((int)param_1 + 0x1c050) = 0xc3430000;
  piVar12 = (int *)(*(int *)((int)param_1 + 4) + 0xc);
  puVar13 = *(undefined4 **)((int)param_1 + 0x1bf80);
  *(undefined4 **)(*(int *)((int)param_1 + 0x1bf7c) + 4) = puVar13;
  *puVar13 = *(undefined4 *)((int)param_1 + 0x1bf7c);
  piVar2 = (int *)((int)param_1 + 0x1bf7c);
  if (piVar2 != (int *)0x0) {
    iVar6 = *piVar12;
    *(int **)((int)param_1 + 0x1bf80) = piVar12;
    *piVar2 = iVar6;
    *(int **)(iVar6 + 4) = piVar2;
    *piVar12 = (int)piVar2;
  }
  *(undefined4 *)((int)param_1 + 0x1c0b4) = 0x401;
  iVar5 = msys::MComSys::_sys;
  iVar6 = *(int *)((int)param_1 + 8);
  if (*(int *)((int)param_1 + 8) == 0) {
    *(int *)((int)param_1 + 8) = msys::MComSys::_sys;
    iVar6 = iVar5;
  }
  cVar1 = *(char *)(iVar6 + 0xea02e);
  psVar10 = (short *)shop::GetBootInfo();
  FUN_1700917c((MListWndPBase *)(iVar6 + 0xebe90),(int)*psVar10,0x2000,cVar1 == '\x01');
  msys::MListWndPBase::resetCur((MListWndPBase *)(iVar6 + 0xebe90));
  *(byte *)(*(int *)(iVar6 + 0x104b4c) + 0x44) =
       *(byte *)(*(int *)(iVar6 + 0x104b4c) + 0x44) & 0xfe | 1;
  msys::MListWndPBase::setEnableInput((MListWndPBase *)(iVar6 + 0xf4cac),false);
  iVar5 = msys::MComSys::_sys;
  iVar6 = *(int *)((int)param_1 + 8);
  if (*(int *)((int)param_1 + 8) == 0) {
    *(int *)((int)param_1 + 8) = msys::MComSys::_sys;
    iVar6 = iVar5;
  }
  if (*(char *)(iVar6 + 0xea02e) == '\0') {
    *(undefined2 *)((int)param_1 + 0x84) = 0;
  }
  else {
    *(undefined2 *)((int)param_1 + 0x84) = 1;
  }
  FUN_17009094(param_1);
  FUN_17008f64(param_1,0);
  FUN_1700983c(*(undefined4 *)((int)param_1 + 100),1);
  puVar11 = (undefined2 *)msys::MListWndPBase::getCurItem();
  FUN_17008df4(param_1,*puVar11);
  *(undefined1 *)(*(int *)((int)param_1 + 4) + 0x14) = 1;
  *(undefined **)((int)param_1 + 0x10) = &DAT_17010d28;
  *(undefined4 *)((int)param_1 + 0x14) = 0;
  return;
}


// FUNC 0x1700f088 FUN_1700f088 (ShopMenu)
//   size 0x16c | file ShopMenu+0xf088 | callers(1) 0x1700f204

void FUN_1700f088(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint in_fpscr;
  undefined8 local_20;
  undefined1 auStack_18 [8];
  
  FUN_1700beb8(msys::MComSys::_sys + 0x49368,0x110016,0,0,0);
  iVar1 = msys::MComSys::_sys;
  iVar2 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar2 = iVar1;
  }
  *(undefined1 *)(iVar2 + 0xe6508) = 0;
  msys::MListWndPBase::setEnableInput(*(MListWndPBase **)(param_1 + 0x50),false);
  msys::MListWndPBase::setDispCursor(*(MListWndPBase **)(param_1 + 0x50),false);
  iVar2 = *(int *)(*(int *)(param_1 + 0x8c) + 100);
  *(byte *)(iVar2 + 0x44) = *(byte *)(iVar2 + 0x44) & 0xfe | 1;
  *(byte *)(*(int *)(param_1 + 0x150ac) + 0x44) =
       *(byte *)(*(int *)(param_1 + 0x150ac) + 0x44) & 0xfe;
  msys::MLyt::setAnimeInfo(*(MLyt **)(param_1 + 0x44),0xd,1);
  msys::MLyt::setAnimeInfo(*(MLyt **)(param_1 + 0x48),0xe,1);
  msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x44),0xd,0,(char *)0x0,(char *)0x0);
  msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x48),0xe,0,(char *)0x0,(char *)0x0);
  local_20 = msys::MListWndPBase::getCurPos(*(MListWndPBase **)(param_1 + 0x50));
  FUN_17008a74(param_1,auStack_18);
  uVar3 = msys::MListWndPBase::getCurItem();
  iVar1 = msys::MComSys::_sys;
  iVar2 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar2 = iVar1;
  }
  uVar4 = *(undefined4 *)(*(int *)(iVar2 + 0xe904c) + 0x10);
  *(undefined4 *)(param_1 + 0x90) = uVar3;
  uVar4 = VectorSignedToFloat(uVar4,(byte)(in_fpscr >> 0x16) & 3);
  (**(code **)**(undefined4 **)(param_1 + 0x8c))
            (uVar4,*(undefined4 **)(param_1 + 0x8c),uVar3,&local_20,auStack_18);
  FUN_17008f64(param_1,1);
  *(code **)(param_1 + 0x20) = FUN_17010750;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


// FUNC 0x1700f204 FUN_1700f204 (ShopMenu)
//   size 0x238 | file ShopMenu+0xf204 | callers(0) | datarefs 4

void FUN_1700f204(int param_1,uint *param_2)

{
  char cVar1;
  int iVar2;
  undefined2 uVar3;
  int iVar4;
  int *piVar5;
  undefined2 *puVar6;
  uint uVar7;
  MListWndPBase *pMVar8;
  
  iVar4 = msys::MListWndPBase::getSelectItem(*(MListWndPBase **)(param_1 + 0x50));
  if ((iVar4 == 0) ||
     (iVar4 = msys::MListWndPBase::getSelectItem(*(MListWndPBase **)(param_1 + 0x50)),
     *(char *)(iVar4 + 0xe) == '\0')) {
    iVar4 = (**(code **)(**(int **)(param_1 + 0x50) + 0x20))();
    if ((iVar4 == 0) &&
       (iVar4 = msys::MListWndPBase::getListWnd(*(MListWndPBase **)(param_1 + 0x50)),
       *(int *)(iVar4 + 0x1cc) == 0)) {
      uVar7 = *param_2;
      if ((uVar7 & 0x802) == 0) {
        if (*(short *)(param_1 + 0x84) == 0 || (uVar7 & 0x30) == 0) {
          if (*(short *)(param_1 + 0x82) != 2 && (uVar7 & 0x300) != 0) {
            FUN_1700899c(param_1,param_2);
            FUN_17008f64(param_1,0);
          }
          goto LAB_1700f368;
        }
        cVar1 = (char)*(short *)(param_1 + 0x84);
        iVar4 = (int)cVar1;
        if ((uVar7 & 0x20) == 0) {
          if (((uVar7 & 0x10) != 0) && (iVar4 = (int)(char)(cVar1 + '\x01'), 2 < iVar4)) {
            iVar4 = 1;
          }
        }
        else {
          iVar4 = (int)(char)(cVar1 + -1);
          if (iVar4 < 1) {
            iVar4 = 2;
          }
        }
        piVar5 = *(int **)(param_1 + iVar4 * 4 + 0x22e7c);
        if ((*(byte *)(piVar5 + 2) & 0x10) == 0) goto LAB_1700f368;
        (**(code **)(*piVar5 + 0x10))();
        iVar4 = *(int *)(param_1 + 8);
      }
      else {
        (**(code **)(**(int **)(param_1 + 0x78) + 0x10))();
        (**(code **)(**(int **)(param_1 + 0x78) + 0xc))();
        iVar4 = *(int *)(param_1 + 8);
      }
      iVar2 = msys::MComSys::_sys;
      if (iVar4 == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar4 = iVar2;
      }
      *(undefined1 *)(iVar4 + 0xe6508) = 0;
    }
  }
  else {
    FUN_1700f088(param_1);
  }
LAB_1700f368:
  iVar4 = msys::MListWndPBase::getListWnd(*(MListWndPBase **)(param_1 + 0x50));
  if ((*(char *)(iVar4 + 0x144) != '\0') &&
     (iVar4 = msys::MListWndPBase::getListWnd(*(MListWndPBase **)(param_1 + 0x50)),
     *(int *)(iVar4 + 0x1cc) == 0)) {
    msys::MListWndPBase::getListWnd(*(MListWndPBase **)(param_1 + 0x50));
    puVar6 = (undefined2 *)ad::ui::UIListWindowPlusLyt::getCurItem();
    iVar4 = msys::MListWndPBase::getCurNo(*(MListWndPBase **)(param_1 + 0x50));
    if (iVar4 != *(short *)(param_1 + 0x80)) {
      if (puVar6 != (undefined2 *)0x0) {
        FUN_17008df4(param_1,*puVar6);
        pMVar8 = *(MListWndPBase **)(param_1 + 0x50);
        iVar4 = msys::MListWndPBase::getListWnd(pMVar8);
        if (*(short *)(*(int *)(*(int *)(pMVar8 + 0x8e08) + (uint)*(byte *)(iVar4 + 0x149) * 4) + 4)
            != 0) {
          pMVar8 = *(MListWndPBase **)(param_1 + 0x50);
          iVar4 = msys::MListWndPBase::getListWnd(pMVar8);
          PutRegFlag(*(ushort *)
                      (*(int *)(*(int *)(pMVar8 + 0x8e08) + (uint)*(byte *)(iVar4 + 0x149) * 4) + 4)
                     ,1.0,(GlobalEvent *)0x0,(LocalEvent *)0x0);
        }
      }
      uVar3 = msys::MListWndPBase::getCurNo(*(MListWndPBase **)(param_1 + 0x50));
      *(undefined2 *)(param_1 + 0x80) = uVar3;
    }
  }
  return;
}


// FUNC 0x1700f458 FUN_1700f458 (ShopMenu)
//   size 0x29c | file ShopMenu+0xf458 | callers(0)

void FUN_1700f458(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  code *pcVar3;
  undefined2 *puVar4;
  int iVar5;
  undefined4 uVar6;
  code *pcVar7;
  
  iVar5 = msys::MComSys::_sys;
  pcVar3 = *(code **)(param_1 + 0x20);
  pcVar7 = FUN_17010148;
  if (pcVar3 == FUN_17010148) {
    pcVar7 = *(code **)(param_1 + 0x24);
  }
  if (pcVar3 != FUN_17010148 || pcVar7 != (code *)0x0) {
    if (pcVar3 != (code *)0x0) {
      return;
    }
    if ((*(uint *)(param_1 + 0x24) & 1) != 0 && *(uint *)(param_1 + 0x24) != 0) {
      return;
    }
  }
  cVar1 = *(char *)(param_2 + 0x48);
  if (param_3 == 1) {
    if ((char)(cVar1 + '\x16') == *(char *)(*(int *)(param_1 + 0x58) + 0x18)) {
      return;
    }
    FUN_1700beb8(msys::MComSys::_sys + 0x49368,0x110015,0,0,0);
    *(char *)(*(int *)(param_1 + 0x58) + 0x18) = cVar1 + '\x16';
    msys::MCursorBase::setVisible(*(MCursorBase **)(param_1 + 0x58),true);
    FUN_1700ad98(*(undefined4 *)(param_1 + 0x58));
    return;
  }
  if (param_3 == 4) {
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
    }
    *(undefined1 *)(*(int *)(param_1 + 8) + 0xe6508) = 0;
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = iVar5;
    }
    else {
      iVar5 = *(int *)(param_1 + 8);
    }
LAB_1700f530:
    *(undefined1 *)(iVar5 + 0xe650a) = 1;
    return;
  }
  if (param_3 != 5) {
    return;
  }
  msys::MListWndPBase::getListWnd(*(MListWndPBase **)(param_1 + 0x50));
  puVar4 = (undefined2 *)ad::ui::UIListWindowPlusLyt::getCurItem();
  iVar5 = FUN_17008910(param_1,*(undefined1 *)(param_1 + 0x82),*puVar4);
  if ((iVar5 < 1) || (*(short *)(param_1 + 0x84) == iVar5)) {
    if (cVar1 == '\0') {
      uVar6 = 0x110016;
      goto LAB_1700f5e0;
    }
  }
  else if (cVar1 == '\0') {
    FUN_17008690(param_1);
    iVar2 = msys::MComSys::_sys;
    iVar5 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar5 = iVar2;
    }
    *(undefined1 *)(iVar5 + 0xe6508) = 1;
    iVar2 = msys::MComSys::_sys;
    iVar5 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar5 = iVar2;
    }
    goto LAB_1700f530;
  }
  uVar6 = 0x110017;
LAB_1700f5e0:
  FUN_1700beb8(msys::MComSys::_sys + 0x49368,uVar6,0,0,0);
  iVar5 = msys::MComSys::_sys;
  if (cVar1 == '\0') {
    FUN_1701004c(param_1);
  }
  else if (cVar1 == '\x01') {
    msys::MListWndPBase::setDispCursor(*(MListWndPBase **)(param_1 + 0x50),true);
    msys::MLyt::setAnimeInfo(*(MLyt **)(param_1 + 0x44),0xe,0);
    msys::MLyt::setAnimeInfo(*(MLyt **)(param_1 + 0x48),0xf,0);
    msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x44),0xe,1,(char *)0x0,(char *)0x0);
    msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x48),0xf,1,(char *)0x0,(char *)0x0);
    FUN_17008f64(param_1,0);
    FUN_17009094(param_1);
    *(code **)(param_1 + 0x20) = FUN_170107fc;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  else {
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar5;
    }
    *(undefined1 *)(iVar2 + 0xe6508) = 1;
    iVar2 = msys::MComSys::_sys;
    iVar5 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar5 = iVar2;
    }
    *(undefined1 *)(iVar5 + 0xe650a) = 1;
  }
  msys::MCursorBase::setVisible(*(MCursorBase **)(param_1 + 0x58),false);
  return;
}


// FUNC 0x1700f718 FUN_1700f718 (ShopMenu)
//   size 0x36c | file ShopMenu+0xf718 | callers(0)

void FUN_1700f718(int param_1,int param_2,int param_3)

{
  char cVar1;
  ushort uVar2;
  code *pcVar3;
  undefined2 *puVar4;
  int iVar5;
  undefined4 uVar6;
  code *pcVar7;
  int *piVar8;
  int iVar9;
  
  iVar5 = msys::MComSys::_sys;
  pcVar3 = *(code **)(param_1 + 0x20);
  pcVar7 = FUN_1700fc24;
  if (pcVar3 == FUN_1700fc24) {
    pcVar7 = *(code **)(param_1 + 0x24);
  }
  if (pcVar3 != FUN_1700fc24 || pcVar7 != (code *)0x0) {
    if (pcVar3 != (code *)0x0) {
      return;
    }
    if ((*(uint *)(param_1 + 0x24) & 1) != 0 && *(uint *)(param_1 + 0x24) != 0) {
      return;
    }
  }
  cVar1 = *(char *)(param_2 + 0x48);
  if (param_3 == 1) {
    if ((char)(cVar1 + '\x13') == *(char *)(*(int *)(param_1 + 0x58) + 0x18)) {
      return;
    }
    FUN_1700beb8(msys::MComSys::_sys + 0x49368,0x110015,0,0,0);
    *(char *)(*(int *)(param_1 + 0x58) + 0x18) = cVar1 + '\x13';
    msys::MCursorBase::setVisible(*(MCursorBase **)(param_1 + 0x58),true);
    FUN_1700ad98(*(undefined4 *)(param_1 + 0x58));
    return;
  }
  if (param_3 == 4) {
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
    }
    *(undefined1 *)(*(int *)(param_1 + 8) + 0xe6508) = 0;
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = iVar5;
    }
    else {
      iVar5 = *(int *)(param_1 + 8);
    }
LAB_1700f7f0:
    *(undefined1 *)(iVar5 + 0xe650a) = 1;
    return;
  }
  if (param_3 != 5) {
    return;
  }
  msys::MListWndPBase::getListWnd(*(MListWndPBase **)(param_1 + 0x50));
  puVar4 = (undefined2 *)ad::ui::UIListWindowPlusLyt::getCurItem();
  iVar5 = FUN_17008910(param_1,*(undefined1 *)(param_1 + 0x82),*puVar4);
  if ((iVar5 < 1) || (*(short *)(param_1 + 0x84) == iVar5)) {
    if (cVar1 == '\0') {
      uVar6 = 0x110016;
      goto LAB_1700f8a0;
    }
  }
  else if (cVar1 == '\0') {
    FUN_17008690(param_1);
    iVar9 = msys::MComSys::_sys;
    iVar5 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar5 = iVar9;
    }
    *(undefined1 *)(iVar5 + 0xe6508) = 1;
    iVar9 = msys::MComSys::_sys;
    iVar5 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar5 = iVar9;
    }
    goto LAB_1700f7f0;
  }
  uVar6 = 0x110017;
LAB_1700f8a0:
  FUN_1700beb8(msys::MComSys::_sys + 0x49368,uVar6,0,0,0);
  iVar5 = msys::MComSys::_sys;
  if (cVar1 == '\0') {
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
    }
    *(undefined1 *)(*(int *)(param_1 + 8) + 0xe6508) = 0;
    msys::MListWndPBase::setDispCursor(*(MListWndPBase **)(param_1 + 0x50),true);
    ad::lyt::LytNumReel3::setValueInstant
              ((LytNumReel3 *)(*(int *)(param_1 + 0x60) + 0x6d94),
               *(int *)(*(int *)(param_1 + 0x60) + 0x6e10) + 1);
    piVar8 = *(int **)(param_1 + 0x5c);
    iVar9 = piVar8[0x75];
    iVar5 = msys::MListWndPBase::getCurItem();
    uVar2 = *(ushort *)(iVar5 + 4);
    iVar5 = FUN_1700beb8(*piVar8 + 0x49368,0x11001e,0,0,0);
    piVar8[1] = iVar5;
    ad::lyt::LytNumReel3::setValue((LytNumReel3 *)(piVar8 + 0x56),iVar9 - (uint)uVar2);
    msys::MDfxChr::playDfx((MDfxChr *)(*(int *)(param_1 + 0x8c) + 0x6edc),0x24);
    *(code **)(param_1 + 0x20) = FUN_1701042c;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  else if (cVar1 == '\x01') {
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
    }
    *(undefined1 *)(*(int *)(param_1 + 8) + 0xe6508) = 0;
    msys::MListWndPBase::setEnableInput(*(MListWndPBase **)(param_1 + 0x50),false);
    msys::MListWndPBase::setDispCursor(*(MListWndPBase **)(param_1 + 0x50),true);
    msys::MLyt::setAnimeInfo(*(MLyt **)(param_1 + 0x44),0xd,0);
    msys::MLyt::setAnimeInfo(*(MLyt **)(param_1 + 0x48),0xe,0);
    msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x44),0xd,1,(char *)0x0,(char *)0x0);
    msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x48),0xe,1,(char *)0x0,(char *)0x0);
    FUN_17008f64(param_1,0);
    FUN_17009094(param_1);
    *(code **)(param_1 + 0x20) = FUN_170107fc;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  else {
    iVar9 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar9 = iVar5;
    }
    *(undefined1 *)(iVar9 + 0xe6508) = 1;
    iVar9 = msys::MComSys::_sys;
    iVar5 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar5 = iVar9;
    }
    *(undefined1 *)(iVar5 + 0xe650a) = 1;
  }
  msys::MCursorBase::setVisible(*(MCursorBase **)(param_1 + 0x58),false);
  return;
}


// FUNC 0x1700faa8 shop::ShopMenu_EquipPage::Core::vfunc_0x10 (ShopMenu)
//   size 0x110 | file ShopMenu+0xfaa8 | callers(0) | datarefs 1

void shop::ShopMenu_EquipPage::Core::vfunc_0x10(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = msys::MComSys::_sys;
  if (param_2 == 4) {
    FUN_1700beb8(msys::MComSys::_sys + 0x49368,0x110017,0,0,0);
    iVar2 = msys::MComSys::_sys;
    iVar1 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar1 = iVar2;
    }
    *(undefined1 *)(iVar1 + 0xe6508) = 0;
    iVar2 = msys::MComSys::_sys;
    iVar1 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar1 = iVar2;
    }
    *(undefined1 *)(iVar1 + 0xe650a) = 1;
  }
  else if (param_2 == 5) {
    if (*(char *)(*(int *)(param_1 + 0x78) + 0x48) == '\x01') {
      iVar2 = *(int *)(param_1 + 8);
      if (iVar2 == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar2 = iVar1;
      }
      *(undefined1 *)(iVar2 + 0xe6508) = 0;
      msys::MListWndPBase::setEnableInput(*(MListWndPBase **)(param_1 + 0x50),false);
      *(undefined1 *)(param_1 + 0x7d) = 0;
    }
    else {
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
      }
      *(undefined1 *)(*(int *)(param_1 + 8) + 0xe6508) = 1;
      iVar2 = *(int *)(param_1 + 8);
      if (iVar2 == 0) {
        *(int *)(param_1 + 8) = iVar1;
        iVar2 = iVar1;
      }
      *(undefined1 *)(iVar2 + 0xe650a) = 1;
    }
    msys::MCursorBase::setVisible(*(MCursorBase **)(param_1 + 0x58),false);
    FUN_1700ad98(*(undefined4 *)(param_1 + 0x58));
    return;
  }
  return;
}


// FUNC 0x1700fbc0 FUN_1700fbc0 (ShopMenu)
//   size 0x5c | file ShopMenu+0xfbc0 | callers(0) | datarefs 2

void FUN_1700fbc0(int param_1)

{
  MComSys *pMVar1;
  int iVar2;
  MComSys *this;
  
  iVar2 = (**(code **)(**(int **)(param_1 + 0x48) + 0x20))();
  pMVar1 = msys::MComSys::_sys;
  if (iVar2 == 0) {
    this = *(MComSys **)(param_1 + 8);
    if (*(MComSys **)(param_1 + 8) == (MComSys *)0x0) {
      *(MComSys **)(param_1 + 8) = msys::MComSys::_sys;
      this = pMVar1;
    }
    iVar2 = msys::MComSys::getNextPage(this);
    if (*(char *)(iVar2 + 0x14) != '\0') {
      *(undefined1 **)(param_1 + 0x18) = &LAB_17010d18;
      *(undefined4 *)(param_1 + 0x1c) = 0;
    }
  }
  return;
}


// FUNC 0x1700fc24 FUN_1700fc24 (ShopMenu)
//   size 0x2a4 | file ShopMenu+0xfc24 | callers(0) | datarefs 2

void FUN_1700fc24(int param_1,uint *param_2)

{
  char cVar1;
  undefined2 uVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined2 *puVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined4 local_40;
  undefined4 uStack_3c;
  
  cVar1 = *(char *)(*(int *)(param_1 + 0x58) + 0x18);
  uVar3 = *param_2;
  iVar10 = (int)(char)(cVar1 + -0x13);
  iVar9 = iVar10;
  if ((uVar3 & 0x401) != 0) {
    iVar4 = param_1 + iVar10 * 4;
    (**(code **)(**(int **)(iVar4 + 0x22e88) + 0x10))();
    (**(code **)(**(int **)(iVar4 + 0x22e88) + 0xc))();
    iVar11 = msys::MComSys::_sys;
    iVar4 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar4 = iVar11;
    }
    *(undefined1 *)(iVar4 + 0xe6508) = 0;
    goto LAB_1700fe80;
  }
  if ((uVar3 & 0x802) == 0) {
    if ((uVar3 & 0x20) == 0) {
      if ((uVar3 & 0x10) == 0) {
        if (*(short *)(param_1 + 0x82) == 2 || (uVar3 & 0x300) == 0) {
          if (((*(byte *)(*(int *)(param_1 + 0x22e78) + 0x44) & 1) != 0) &&
             (((uVar3 & 0xc0) != 0 || (iVar4 = FUN_170085c0(param_1), iVar4 != 0)))) {
            if (*(short *)(param_1 + 0x84) == 1) {
              uVar2 = 2;
            }
            else {
              uVar2 = 1;
            }
            *(undefined2 *)(param_1 + 0x84) = uVar2;
            FUN_17008a74(param_1,&local_40);
            iVar4 = *(int *)(param_1 + 0x8c);
            MoveVBase::stop((MoveVBase *)(iVar4 + 4));
            *(undefined4 *)(iVar4 + 0x28) = 0;
            *(undefined4 *)(iVar4 + 0x20) = local_40;
            *(undefined4 *)(iVar4 + 0x24) = uStack_3c;
            *(undefined4 *)(iVar4 + 0x10) = 0;
            *(undefined4 *)(iVar4 + 8) = local_40;
            *(undefined4 *)(iVar4 + 0xc) = uStack_3c;
            iVar11 = *(int *)(iVar4 + 100);
            puVar5 = (undefined4 *)MoveVBase::update((MoveVBase *)(iVar4 + 4),1.0);
            uVar7 = puVar5[1];
            uVar8 = puVar5[2];
            *(undefined4 *)(iVar11 + 0x1c) = *puVar5;
            *(undefined4 *)(iVar11 + 0x20) = uVar7;
            *(undefined4 *)(iVar11 + 0x24) = uVar8;
            *(byte *)(iVar11 + 0x44) = *(byte *)(iVar11 + 0x44) & 0xef | 0x10;
            uVar3 = 0;
            *(undefined1 *)(*(int *)(iVar4 + 0x60) + 0x374) = 1;
            do {
              if ((int)*(short *)(param_1 + 0x84) == uVar3) {
                ad::lyt::LytAnim::stopAndSetFrm
                          ((LytAnim *)(*(int *)(param_1 + 0x70) + uVar3 * 0x6ee0 + 4),1.0);
              }
              else {
                ad::lyt::LytAnim::stopAndSetFrm
                          ((LytAnim *)(*(int *)(param_1 + 0x70) + uVar3 * 0x6ee0 + 4),0.0);
              }
              uVar3 = uVar3 + 1 & 0xff;
            } while (uVar3 < 3);
            FUN_1700beb8(msys::MComSys::_sys + 0x49368,0x110015,0,0,0);
            msys::MListWndPBase::getListWnd(*(MListWndPBase **)(param_1 + 0x50));
            puVar6 = (undefined2 *)ad::ui::UIListWindowPlusLyt::getCurItem();
            FUN_17008df4(param_1,*puVar6);
          }
        }
        else {
          FUN_1700899c(param_1);
          FUN_17008f64(param_1,1);
        }
      }
      else {
        iVar9 = (int)(char)(cVar1 + -0x12);
        if (1 < iVar9) {
          iVar9 = 0;
        }
      }
      goto LAB_1700fe80;
    }
    iVar9 = (int)(char)(cVar1 + -0x14);
    if (-1 < (char)(cVar1 + -0x14)) goto LAB_1700fe80;
  }
  iVar9 = 1;
LAB_1700fe80:
  if (iVar9 != iVar10) {
    FUN_1700beb8(msys::MComSys::_sys + 0x49368,0x110015,0,0,0);
    *(char *)(*(int *)(param_1 + 0x58) + 0x18) = (char)iVar9 + '\x13';
  }
  FUN_1700ad98(*(undefined4 *)(param_1 + 0x58));
  return;
}


// FUNC 0x1700fef4 FUN_1700fef4 (ShopMenu)
//   size 0x144 | file ShopMenu+0xfef4 | callers(0)

void FUN_1700fef4(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined2 *puVar3;
  uint uVar4;
  
  if (param_3 == 4) {
    FUN_1700beb8(msys::MComSys::_sys + 0x49368,0x110015,0,0,0);
    iVar2 = msys::MComSys::_sys;
    iVar1 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar1 = iVar2;
    }
    *(undefined1 *)(iVar1 + 0xe6508) = 0;
                    /* WARNING: Could not recover jumptable at 0x1700ffc8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(param_1 + *(short *)(param_1 + 0x84) * 4 + 0x22e7c) + 0x18))();
    return;
  }
  if (param_3 == 5) {
    uVar4 = 0;
    *(ushort *)(param_1 + 0x84) = *(byte *)(param_2 + 0x48) + 1;
    do {
      if ((int)*(short *)(param_1 + 0x84) == uVar4) {
        ad::lyt::LytAnim::stopAndSetFrm
                  ((LytAnim *)(*(int *)(param_1 + 0x70) + uVar4 * 0x6ee0 + 4),1.0);
      }
      else {
        ad::lyt::LytAnim::stopAndSetFrm
                  ((LytAnim *)(*(int *)(param_1 + 0x70) + uVar4 * 0x6ee0 + 4),0.0);
      }
      uVar4 = uVar4 + 1 & 0xff;
    } while (uVar4 < 3);
    msys::MListWndPBase::getListWnd(*(MListWndPBase **)(param_1 + 0x50));
    puVar3 = (undefined2 *)ad::ui::UIListWindowPlusLyt::getCurItem();
    FUN_17008df4(param_1,*puVar3);
    iVar2 = msys::MComSys::_sys;
    iVar1 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar1 = iVar2;
    }
    *(undefined1 *)(iVar1 + 0xe6508) = 1;
  }
  return;
}


// FUNC 0x1701004c FUN_1701004c (ShopMenu)
//   size 0xe8 | file ShopMenu+0x1004c | callers(1) 0x1700f458

void FUN_1701004c(int param_1)

{
  int iVar1;
  int iVar2;
  uint in_fpscr;
  undefined4 uVar3;
  undefined4 local_28;
  float local_24;
  undefined4 local_20;
  float local_1c;
  
  iVar2 = msys::MLyt::getPane(*(MLyt **)(param_1 + 0x44),
                              *(char **)(&DAT_17021e78 + *(short *)(param_1 + 0x84) * 4),(char *)0x0
                              ,(char *)0x0);
  iVar1 = msys::MComSys::_sys;
  local_28 = *(undefined4 *)(iVar2 + 0x54);
  local_24 = *(float *)(iVar2 + 100) + 240.0;
  iVar2 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar2 = iVar1;
  }
  uVar3 = VectorSignedToFloat(*(undefined4 *)(*(int *)(iVar2 + 0xe904c) + 0x10),
                              (byte)(in_fpscr >> 0x16) & 3);
  local_1c = local_24 - 240.0;
  local_20 = local_28;
  FUN_170084fc(uVar3,param_1 + 0xe128,&local_20);
  FUN_170084fc(uVar3,param_1 + 0x1504c,&local_28);
  *(byte *)(*(int *)(param_1 + 0xe188) + 0x44) =
       *(byte *)(*(int *)(param_1 + 0xe188) + 0x44) & 0xfe | 1;
  *(code **)(param_1 + 0x20) = FUN_17010894;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


// FUNC 0x17010148 FUN_17010148 (ShopMenu)
//   size 0x2c0 | file ShopMenu+0x10148 | callers(0) | datarefs 2

void FUN_17010148(int param_1,uint *param_2)

{
  char cVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined2 *puVar6;
  int iVar7;
  int iVar8;
  undefined4 local_40;
  float local_3c;
  undefined4 local_38;
  float fStack_34;
  
  cVar1 = *(char *)(*(int *)(param_1 + 0x58) + 0x18);
  uVar4 = *param_2;
  iVar7 = (int)(char)(cVar1 + -0x16);
  iVar8 = iVar7;
  if ((uVar4 & 0x401) != 0) {
    iVar5 = param_1 + iVar7 * 4;
    (**(code **)(**(int **)(iVar5 + 0x22e90) + 0x10))();
    (**(code **)(**(int **)(iVar5 + 0x22e90) + 0xc))();
    iVar3 = msys::MComSys::_sys;
    iVar5 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar5 = iVar3;
    }
    *(undefined1 *)(iVar5 + 0xe6508) = 0;
    goto LAB_170103c0;
  }
  if ((uVar4 & 0x802) == 0) {
    if ((uVar4 & 0x20) == 0) {
      if ((uVar4 & 0x10) == 0) {
        if (*(short *)(param_1 + 0x82) == 2 || (uVar4 & 0x300) == 0) {
          if (((*(byte *)(*(int *)(param_1 + 0x22e78) + 0x44) & 1) != 0) &&
             (((uVar4 & 0xc0) != 0 || (iVar5 = FUN_170085c0(param_1,param_2), iVar5 != 0)))) {
            sVar2 = *(short *)(param_1 + 0x84);
            if (sVar2 == 1) {
              iVar5 = 2;
            }
            else {
              iVar5 = 1;
            }
            *(short *)(param_1 + 0x84) = (short)iVar5;
            if (iVar5 != (char)sVar2) {
              local_40 = 0;
              FUN_1700beb8(msys::MComSys::_sys + 0x49368,0x110015,0,0);
            }
            FUN_17008a74(param_1,&local_38);
            local_40 = local_38;
            local_3c = fStack_34 - 240.0;
            FUN_170084fc(0,param_1 + 0xe128,&local_40);
            FUN_170084fc(0,param_1 + 0x1504c,&local_38);
            uVar4 = 0;
            do {
              if ((int)*(short *)(param_1 + 0x84) == uVar4) {
                ad::lyt::LytAnim::stopAndSetFrm
                          ((LytAnim *)(*(int *)(param_1 + 0x70) + uVar4 * 0x6ee0 + 4),1.0);
              }
              else {
                ad::lyt::LytAnim::stopAndSetFrm
                          ((LytAnim *)(*(int *)(param_1 + 0x70) + uVar4 * 0x6ee0 + 4),0.0);
              }
              uVar4 = uVar4 + 1 & 0xff;
            } while (uVar4 < 3);
            msys::MListWndPBase::getListWnd(*(MListWndPBase **)(param_1 + 0x50));
            puVar6 = (undefined2 *)ad::ui::UIListWindowPlusLyt::getCurItem();
            FUN_17008df4(param_1,*puVar6);
            local_40 = 0;
            FUN_1700beb8(msys::MComSys::_sys + 0x49368,0x110015,0);
          }
        }
        else {
          FUN_1700899c(param_1,param_2);
          FUN_17008f64(param_1,2);
        }
      }
      else {
        iVar8 = (int)(char)(cVar1 + -0x15);
        if (1 < iVar8) {
          iVar8 = 0;
        }
      }
      goto LAB_170103c0;
    }
    iVar8 = (int)(char)(cVar1 + -0x17);
    if (-1 < (char)(cVar1 + -0x17)) goto LAB_170103c0;
  }
  iVar8 = 1;
LAB_170103c0:
  if (iVar8 != iVar7) {
    local_40 = 0;
    FUN_1700beb8(msys::MComSys::_sys + 0x49368,0x110015,0);
    *(char *)(*(int *)(param_1 + 0x58) + 0x18) = (char)iVar8 + '\x16';
  }
  FUN_1700ad98(*(undefined4 *)(param_1 + 0x58));
  return;
}


// FUNC 0x1701042c FUN_1701042c (ShopMenu)
//   size 0x1c8 | file ShopMenu+0x1042c | callers(0) | datarefs 1

void FUN_1701042c(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  short *psVar5;
  int extraout_r1;
  int iVar6;
  undefined1 auStackY_b0 [128];
  undefined1 local_28 [12];
  
  iVar3 = *(int *)(param_1 + 0x5c);
  if (*(int *)(iVar3 + 0x1dc) == *(int *)(iVar3 + 0x1d4)) {
    SndSeCtrl::stop(*(SndSeCtrl **)(iVar3 + 4),0);
    GameWork::addItem((GameWork *)&gGameWork,**(undefined2 **)(param_1 + 0x90),1);
    GameWork::addCoin((GameWork *)&gGameWork,-(uint)*(ushort *)(*(int *)(param_1 + 0x90) + 4));
    iVar6 = msys::MComSys::_sys;
    iVar3 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar3 = iVar6;
    }
    iVar2 = msys::MComSys::_sys;
    iVar6 = extraout_r1;
    if (iVar3 == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar6 = iVar2;
    }
    if (iVar3 != 0) {
      iVar6 = iVar3;
    }
    *(uint *)(iVar3 + 0xea030) =
         (uint)*(ushort *)(*(int *)(param_1 + 0x90) + 4) + *(int *)(iVar6 + 0xea030);
    iVar3 = *(int *)(*(int *)(param_1 + 0x8c) + 100);
    *(byte *)(iVar3 + 0x44) = *(byte *)(iVar3 + 0x44) & 0xfe;
    *(byte *)(*(int *)(param_1 + 0x150ac) + 0x44) =
         *(byte *)(*(int *)(param_1 + 0x150ac) + 0x44) & 0xfe | 1;
    FUN_17008a74(param_1,local_28);
    FUN_170084c0(param_1 + 0x7368,1);
    uVar4 = msys::MListWndPBase::getCurItem();
    FUN_17008410(param_1 + 0xe128,uVar4,auStackY_b0 + 0x80);
    FUN_17008410(param_1 + 0x1504c,uVar4,local_28);
    iVar6 = msys::MComSys::_sys;
    iVar3 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar3 = iVar6;
    }
    cVar1 = *(char *)(iVar3 + 0xea02e);
    psVar5 = (short *)shop::GetBootInfo();
    FUN_1700917c(*(undefined4 *)(param_1 + 0x50),(int)*psVar5,0x2000,cVar1 == '\x01');
    msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x44),0xe,0,(char *)0x0,(char *)0x0);
    msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x48),0xf,0,(char *)0x0,(char *)0x0);
    (**(code **)(**(int **)(param_1 + 0x48) + 0x10))();
    *(code **)(param_1 + 0x20) = FUN_17010abc;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x17010608 FUN_17010608 (ShopMenu)
//   size 0xbc | file ShopMenu+0x10608 | callers(0) | datarefs 3

void FUN_17010608(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = msys::MLyt::isEnableAnime(*(MLyt **)(param_1 + 0x48));
  if ((iVar2 == 0) && (iVar2 = msys::MLyt::isEnableAnime(*(MLyt **)(param_1 + 0x44)), iVar2 == 0)) {
    msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x44),0x19,0,"EXP_PNL_U_down",(char *)0x0);
    msys::MListWndPBase::setEnableInput(*(MListWndPBase **)(param_1 + 0x50),true);
    msys::MListWndPBase::setDispCursor(*(MListWndPBase **)(param_1 + 0x50),true);
    FUN_17008f64(param_1,0);
    *(undefined2 *)(param_1 + 0x80) = 0xffff;
    iVar1 = msys::MComSys::_sys;
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar1;
    }
    *(undefined1 *)(iVar2 + 0xe6508) = 1;
    iVar1 = msys::MComSys::_sys;
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar1;
    }
    *(undefined1 *)(iVar2 + 0xe650a) = 1;
    *(code **)(param_1 + 0x20) = FUN_1700f204;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x170106dc FUN_170106dc (ShopMenu)
//   size 0x70 | file ShopMenu+0x106dc | callers(0) | datarefs 2

void FUN_170106dc(int param_1)

{
  int *piVar1;
  int iVar2;
  
  if ((*(int *)(param_1 + 0x22bc0) == 0) && ((*(byte *)(param_1 + 0x21900) & 1) == 0)) {
    iVar2 = 0;
    do {
      piVar1 = *(int **)(param_1 + iVar2 * 4 + 0x22e90);
      (**(code **)(*piVar1 + 0x28))(piVar1,1);
      iVar2 = iVar2 + 1;
    } while (iVar2 < 2);
    *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_1 + 0x1bf70);
    *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(param_1 + 0x1bf74);
  }
  return;
}


// FUNC 0x17010750 FUN_17010750 (ShopMenu)
//   size 0xa4 | file ShopMenu+0x10750 | callers(0) | datarefs 2

void FUN_17010750(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_17009648(param_1 + 0x88);
  if (((iVar1 == 0) && (iVar1 = msys::MLyt::isEnableAnime(*(MLyt **)(param_1 + 0x48)), iVar1 == 0))
     && (iVar2 = msys::MLyt::isEnableAnime(*(MLyt **)(param_1 + 0x44)), iVar1 = msys::MComSys::_sys,
        iVar2 == 0)) {
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
    *(undefined1 *)(*(int *)(param_1 + 0x58) + 0x18) = 0x13;
    msys::MCursorBase::setVisible(*(MCursorBase **)(param_1 + 0x58),true);
    FUN_1700ad98(*(undefined4 *)(param_1 + 0x58));
    *(code **)(param_1 + 0x20) = FUN_1700fc24;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x170107fc FUN_170107fc (ShopMenu)
//   size 0x90 | file ShopMenu+0x107fc | callers(0) | datarefs 2

void FUN_170107fc(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = msys::MLyt::isEnableAnime(*(MLyt **)(param_1 + 0x48));
  if ((iVar2 == 0) && (iVar2 = msys::MLyt::isEnableAnime(*(MLyt **)(param_1 + 0x44)), iVar2 == 0)) {
    FUN_170084c0(param_1 + 0x7368,0);
    iVar1 = msys::MComSys::_sys;
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar1;
    }
    *(undefined1 *)(iVar2 + 0xe6508) = 1;
    iVar1 = msys::MComSys::_sys;
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar1;
    }
    *(undefined1 *)(iVar2 + 0xe650a) = 1;
    msys::MListWndPBase::setEnableInput(*(MListWndPBase **)(param_1 + 0x50),true);
    *(code **)(param_1 + 0x20) = FUN_1700f204;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x17010894 FUN_17010894 (ShopMenu)
//   size 0x210 | file ShopMenu+0x10894 | callers(0) | datarefs 2

void FUN_17010894(int param_1)

{
  char cVar1;
  ushort uVar2;
  undefined4 *puVar3;
  ushort *puVar4;
  short *psVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  
  iVar8 = *(int *)(param_1 + 0xe188);
  puVar3 = (undefined4 *)MoveVBase::update((MoveVBase *)(param_1 + 0xe128),1.0);
  uVar6 = puVar3[1];
  uVar7 = puVar3[2];
  *(undefined4 *)(iVar8 + 0x1c) = *puVar3;
  *(undefined4 *)(iVar8 + 0x20) = uVar6;
  *(undefined4 *)(iVar8 + 0x24) = uVar7;
  *(byte *)(iVar8 + 0x44) = *(byte *)(iVar8 + 0x44) & 0xef | 0x10;
  *(undefined1 *)(*(int *)(param_1 + 0xe184) + 0x374) = 1;
  iVar8 = MoveVBase::isBusy((MoveVBase *)(param_1 + 0xe128));
  iVar9 = *(int *)(param_1 + 0x150ac);
  puVar3 = (undefined4 *)MoveVBase::update((MoveVBase *)(param_1 + 0x1504c),1.0);
  uVar6 = puVar3[1];
  uVar7 = puVar3[2];
  *(undefined4 *)(iVar9 + 0x1c) = *puVar3;
  *(undefined4 *)(iVar9 + 0x20) = uVar6;
  *(undefined4 *)(iVar9 + 0x24) = uVar7;
  *(byte *)(iVar9 + 0x44) = *(byte *)(iVar9 + 0x44) & 0xef | 0x10;
  *(undefined1 *)(*(int *)(param_1 + 0x150a8) + 0x374) = 1;
  iVar9 = MoveVBase::isBusy((MoveVBase *)(param_1 + 0x1504c));
  if (iVar9 == 0 && iVar8 == 0) {
    FUN_170084c0(param_1 + 0x7368,0);
    puVar4 = (ushort *)msys::MListWndPBase::getCurItem();
    iVar9 = msys::MComSys::_sys;
    uVar2 = *puVar4;
    iVar8 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar8 = iVar9;
    }
    DataPc::setEquip((DataPc *)(iVar8 + *(short *)(param_1 + 0x82) * 0xb0 + 0xe9e10),uVar2,
                     *(uchar *)(param_1 + 0x84));
    iVar9 = msys::MComSys::_sys;
    iVar8 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar8 = iVar9;
    }
    DataPc::write((DataPc *)(iVar8 + *(short *)(param_1 + 0x82) * 0xb0 + 0xe9e10),
                  (DataPcPOD *)(&gGameWork + *(short *)(param_1 + 0x82) * 0x34));
    FUN_17008b20(param_1,*(undefined1 *)(param_1 + 0x82));
    iVar9 = msys::MComSys::_sys;
    iVar8 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar8 = iVar9;
    }
    cVar1 = *(char *)(iVar8 + 0xea02e);
    psVar5 = (short *)shop::GetBootInfo();
    FUN_1700917c(*(undefined4 *)(param_1 + 0x50),(int)*psVar5,0x2000,cVar1 == '\x01');
    FUN_1700beb8(msys::MComSys::_sys + 0x49368,0x11001b,0,0,0);
    uVar6 = *(undefined4 *)(param_1 + 0xe12c);
    uVar7 = *(undefined4 *)(param_1 + 0xe130);
    MoveVBase::stop((MoveVBase *)(param_1 + 0xe078));
    *(undefined4 *)(param_1 + 0xe094) = uVar6;
    *(undefined4 *)(param_1 + 0xe098) = uVar7;
    *(undefined4 *)(param_1 + 0xe09c) = 0x43340000;
    *(undefined4 *)(param_1 + 0xe07c) = uVar6;
    *(undefined4 *)(param_1 + 0xe080) = uVar7;
    *(undefined4 *)(param_1 + 0xe084) = 0x43340000;
    msys::MDfxChr::playDfx((MDfxChr *)(param_1 + 0xdfac),0x13);
    *(code **)(param_1 + 0x20) = FUN_17010b64;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x17010abc FUN_17010abc (ShopMenu)
//   size 0xa0 | file ShopMenu+0x10abc | callers(0) | datarefs 2

void FUN_17010abc(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = msys::MLyt::isEnableAnime(*(MLyt **)(param_1 + 0x48));
  if ((iVar2 == 0) && (iVar2 = msys::MLyt::isEnableAnime(*(MLyt **)(param_1 + 0x44)), iVar2 == 0)) {
    *(undefined1 *)(*(int *)(param_1 + 0x58) + 0x18) = 0x16;
    msys::MCursorBase::setVisible(*(MCursorBase **)(param_1 + 0x58),true);
    FUN_1700ad98(*(undefined4 *)(param_1 + 0x58));
    FUN_17008f64(param_1,2);
    iVar1 = msys::MComSys::_sys;
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar1;
    }
    *(undefined1 *)(iVar2 + 0xe6508) = 1;
    iVar1 = msys::MComSys::_sys;
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar1;
    }
    *(undefined1 *)(iVar2 + 0xe650a) = 1;
    *(code **)(param_1 + 0x20) = FUN_17010148;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x17010b64 FUN_17010b64 (ShopMenu)
//   size 0xb0 | file ShopMenu+0x10b64 | callers(0) | datarefs 2

void FUN_17010b64(int param_1)

{
  int iVar1;
  uint uVar2;
  bool bVar3;
  
  iVar1 = (**(code **)(*(int *)(param_1 + 0xdfac) + 0x24))((int *)(param_1 + 0xdfac));
  if (iVar1 == 0) {
    uVar2 = *(uint *)(param_1 + 0xe100);
    if (uVar2 != 0) {
      bVar3 = *(int *)(uVar2 + 4) != uVar2 + 4;
      if (!bVar3) {
        uVar2 = (uint)*(byte *)(uVar2 + 0x172);
      }
      if (bVar3 || uVar2 != 0) {
        return;
      }
    }
    msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x44),0xe,1,(char *)0x0,(char *)0x0);
    msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x48),0xf,1,(char *)0x0,(char *)0x0);
    FUN_170084c0(param_1 + 0x7368,0);
    FUN_17009094(param_1);
    *(code **)(param_1 + 0x20) = FUN_17010608;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x17010c18 shop::ShopMenu_EquipPage::Core::vfunc_0x8 (ShopMenu)
//   size 0xfc | file ShopMenu+0x10c18 | callers(0) | datarefs 1

int shop::ShopMenu_EquipPage::Core::vfunc_0x8(int *param_1,MInput *param_2)

{
  MInput MVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  code *extraout_r2;
  code *pcVar7;
  undefined4 *puVar8;
  bool bVar9;
  uint in_fpscr;
  undefined4 local_20;
  undefined4 local_1c;
  
  msys::MPageBase::updateInputAllChr((MPageBase *)param_1[1],param_2);
  bVar9 = (param_1[9] & 1U) == 0;
  pcVar7 = extraout_r2;
  if (bVar9) {
    pcVar7 = (code *)param_1[8];
  }
  piVar3 = (int *)((int)param_1 + (param_1[9] >> 1));
  if (!bVar9) {
    pcVar7 = *(code **)(*piVar3 + param_1[8]);
  }
  (*pcVar7)(piVar3,param_2);
  uVar4 = msys::MListWndPBase::isTpNeutral((MListWndPBase *)param_1[0x14]);
  MVar1 = param_2[0x11];
  bVar9 = MVar1 == (MInput)0x0;
  if (bVar9) {
    MVar1 = param_2[0x12];
  }
  puVar8 = (undefined4 *)(undefined1 *)0x0;
  if ((!bVar9 || MVar1 != (MInput)0x0) && uVar4 != 0) {
    local_20 = VectorSignedToFloat(*(ushort *)(param_2 + 0x14) - 0xa0,(byte)(in_fpscr >> 0x16) & 3);
    local_1c = VectorSignedToFloat(0x78 - (uint)*(ushort *)(param_2 + 0x16),
                                   (byte)(in_fpscr >> 0x16) & 3);
    puVar8 = &local_20;
  }
  uVar5 = (**(code **)(*param_1 + 0xc))(param_1,param_2);
  iVar2 = msys::MComSys::_sys;
  iVar6 = param_1[2];
  if (param_1[2] == 0) {
    param_1[2] = msys::MComSys::_sys;
    iVar6 = iVar2;
  }
  (**(code **)(*(int *)param_1[0x10] + 8))
            ((int *)param_1[0x10],puVar8,(int)*(char *)(iVar6 + 0xe6508) & uVar4 & uVar5);
  return (int)*(char *)((int)param_1 + 0x7d);
}


// FUNC 0x17010d2c FUN_17010d2c (ShopMenu)
//   size 0x34 | file ShopMenu+0x10d2c | callers(0) | datarefs 1

void FUN_17010d2c(int param_1)

{
  msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x44),0x19,1,"EXP_PNL_U_down",(char *)0x0);
  *(code **)(param_1 + 0x18) = FUN_1700fbc0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  return;
}


// FUNC 0x17010d74 FUN_17010d74 (ShopMenu)
//   size 0x2c0 | file ShopMenu+0x10d74 | callers(1) 0x17011254

void FUN_17010d74(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)FUN_1700a0e8();
  *puVar1 = &shop::ShopMenu_EquipPage::Core::vtable;
  puVar1[0x25] = &shop::BuyPnlBase::ItemPnlBase::vtable;
  puVar1 = (undefined4 *)MoveVBase::MoveVBase((MoveVBase *)(puVar1 + 0x26));
  *puVar1 = &vtable_for_5MoveVILj1EE;
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(puVar1 + 0xc,FUN_17014c78,0x2c,1);
  *(int *)(iVar2 + -8) = iVar2;
  *(undefined1 *)(iVar2 + -4) = 1;
  puVar1 = (undefined4 *)FUN_1700c0a0(iVar2 + 0x34);
  *puVar1 = &msys::MMsg::vtable;
  iVar2 = MessageSimple::MessageSimple((MessageSimple *)(puVar1 + 0x53));
  *(undefined4 *)(iVar2 + 0x6ae0) = 0;
  *(undefined1 *)(iVar2 + 0x6ae4) = 0;
  *(undefined1 *)(iVar2 + 0x6ae5) = 0;
  *(undefined4 *)(iVar2 + 0x6ae8) = 0;
  *(undefined4 *)(iVar2 + 0x6aec) = 0;
  *(undefined4 *)(iVar2 + 0x6af4) = 0x400;
  iVar2 = msys::MLytNum::MLytNum((MLytNum *)(iVar2 + 0x6af8));
  iVar2 = msys::MDfxChr::MDfxChr((MDfxChr *)(iVar2 + 0x230));
  *(undefined ***)(iVar2 + -0x6edc) = &shop::BuyPnlBase::ItemPnlCA::vtable;
  puVar1 = (undefined4 *)FUN_1700c0a0(iVar2 + 0x17c);
  *puVar1 = &msys::MCellAnime::vtable;
  iVar2 = CellAnime::CellAnime((CellAnime *)(puVar1 + 0x53));
  *(undefined1 *)(iVar2 + 300) = 0xff;
  *(undefined1 *)(iVar2 + 0x12d) = 0xff;
  *(undefined1 *)(iVar2 + 0x12e) = 0xff;
  *(undefined1 *)(iVar2 + 0x12f) = 0xff;
  puVar1 = (undefined4 *)FUN_1700c0a0(iVar2 + 0x130);
  *puVar1 = &msys::MMsg::vtable;
  iVar2 = MessageSimple::MessageSimple((MessageSimple *)(puVar1 + 0x53));
  *(undefined4 *)(iVar2 + 0x6ae0) = 0;
  *(undefined1 *)(iVar2 + 0x6ae4) = 0;
  *(undefined1 *)(iVar2 + 0x6ae5) = 0;
  *(undefined4 *)(iVar2 + 0x6ae8) = 0;
  *(undefined4 *)(iVar2 + 0x6aec) = 0;
  *(undefined4 *)(iVar2 + 0x6af4) = 0x400;
  iVar2 = msys::MDfxChr::MDfxChr((MDfxChr *)(iVar2 + 0x6af8));
  puVar1 = (undefined4 *)MoveVBase::MoveVBase((MoveVBase *)(iVar2 + 0x17c));
  *puVar1 = &vtable_for_5MoveVILj1EE;
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(puVar1 + 0xc,FUN_17014c78,0x2c,1);
  *(int *)(iVar2 + -8) = iVar2;
  *(undefined1 *)(iVar2 + -4) = 1;
  puVar1 = (undefined4 *)FUN_1700c0a0(iVar2 + 0x34);
  *puVar1 = &msys::MCellAnime::vtable;
  iVar2 = CellAnime::CellAnime((CellAnime *)(puVar1 + 0x53));
  *(undefined1 *)(iVar2 + 300) = 0xff;
  *(undefined1 *)(iVar2 + 0x12d) = 0xff;
  *(undefined1 *)(iVar2 + 0x12e) = 0xff;
  *(undefined1 *)(iVar2 + 0x12f) = 0xff;
  puVar1 = (undefined4 *)FUN_1700c0a0(iVar2 + 0x130);
  *puVar1 = &msys::MMsg::vtable;
  iVar2 = MessageSimple::MessageSimple((MessageSimple *)(puVar1 + 0x53));
  *(undefined4 *)(iVar2 + 0x6ae0) = 0;
  *(undefined1 *)(iVar2 + 0x6ae4) = 0;
  *(undefined1 *)(iVar2 + 0x6ae5) = 0;
  *(undefined4 *)(iVar2 + 0x6ae8) = 0;
  *(undefined4 *)(iVar2 + 0x6aec) = 0;
  *(undefined4 *)(iVar2 + 0x6af4) = 0x400;
  puVar1 = (undefined4 *)MoveVBase::MoveVBase((MoveVBase *)(iVar2 + 0x6af8));
  *puVar1 = &vtable_for_5MoveVILj1EE;
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(puVar1 + 0xc,FUN_17014c78,0x2c,1);
  *(int *)(iVar2 + -8) = iVar2;
  *(undefined1 *)(iVar2 + -4) = 1;
  puVar1 = (undefined4 *)FUN_1700c0a0(iVar2 + 0x34);
  *puVar1 = &msys::MCellAnime::vtable;
  iVar2 = CellAnime::CellAnime((CellAnime *)(puVar1 + 0x53));
  *(undefined1 *)(iVar2 + 300) = 0xff;
  *(undefined1 *)(iVar2 + 0x12d) = 0xff;
  *(undefined1 *)(iVar2 + 0x12e) = 0xff;
  *(undefined1 *)(iVar2 + 0x12f) = 0xff;
  puVar1 = (undefined4 *)FUN_1700c0a0(iVar2 + 0x130);
  *puVar1 = &msys::MMsg::vtable;
  iVar2 = MessageSimple::MessageSimple((MessageSimple *)(puVar1 + 0x53));
  *(undefined4 *)(iVar2 + 0x6ae0) = 0;
  *(undefined1 *)(iVar2 + 0x6ae4) = 0;
  *(undefined1 *)(iVar2 + 0x6ae5) = 0;
  *(undefined4 *)(iVar2 + 0x6ae8) = 0;
  *(undefined4 *)(iVar2 + 0x6aec) = 0;
  *(undefined4 *)(iVar2 + 0x6af4) = 0x400;
  puVar1 = (undefined4 *)FUN_1700c0a0(iVar2 + 0x6b00);
  *puVar1 = &msys::MMsgWnd::vtable;
  iVar2 = Message::Message((Message *)(puVar1 + 0x53));
  *(undefined4 *)(iVar2 + 28000) = 0;
  *(undefined4 *)(iVar2 + 0x6d64) = 0x400;
  *(undefined4 *)(iVar2 + 0x6d68) = 0;
  *(undefined4 *)(iVar2 + 0x6d6c) = 0;
  *(undefined4 *)(iVar2 + 0x6d70) = 0;
  *(undefined4 *)(iVar2 + 0x6d78) = 6;
  *(undefined4 *)(iVar2 + 0x6d74) = 0;
  *(undefined4 *)(iVar2 + 0x6d7c) = 0;
  *(undefined1 *)(iVar2 + 0x6d80) = 0;
  *(undefined4 *)(iVar2 + 0x6d84) = 0;
  *(undefined4 *)(iVar2 + 0x6d88) = 0;
  *(undefined1 *)(iVar2 + 0x6d8c) = 1;
  *(undefined1 *)(iVar2 + 0x6d8d) = 0;
  *(undefined1 *)(iVar2 + 0x6d8e) = 0;
  *(undefined4 *)(iVar2 + 0x6d90) = 0;
  *(undefined4 *)(iVar2 + 0x6d94) = 0x110003;
  *(undefined4 *)(iVar2 + 0x6d98) = 0x110004;
  *(undefined4 *)(iVar2 + 0x6da0) = 0;
  *(undefined4 *)(iVar2 + 0x6da4) = 0;
  *(undefined4 *)(iVar2 + 0x6da8) = 0x400;
  *(code **)(iVar2 + -0x1c0b4) = FUN_1700e770;
  *(undefined4 *)(iVar2 + -0x1c0b0) = 0;
  *(code **)(iVar2 + -0x1c0ac) = FUN_17010d2c;
  *(undefined4 *)(iVar2 + -0x1c0a8) = 0;
  *(code **)(iVar2 + -0x1c0a4) = FUN_17010608;
  *(undefined4 *)(iVar2 + -0x1c0a0) = 0;
  return;
}


// FUNC 0x17011060 shop::ShopMenu_EquipPage::Core::vfunc_0x4 (ShopMenu)
//   size 0x10 | file ShopMenu+0x11060 | callers(0) | datarefs 1

void shop::ShopMenu_EquipPage::Core::vfunc_0x4(void)

{
  void *pvVar1;
  
  pvVar1 = (void *)vfunc_0x0();
  operator_delete(pvVar1);
  return;
}


// FUNC 0x17011070 shop::ShopMenu_EquipPage::Core::vfunc_0x0 (ShopMenu)
//   size 0x1c4 | file ShopMenu+0x11070 | callers(1) 0x17011060 | datarefs 1

void shop::ShopMenu_EquipPage::Core::vfunc_0x0(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &vtable;
  param_1[0x6fde] = &msys::MMsgWnd::vtable;
  Message::term((Message *)(param_1 + 0x7031));
  iVar1 = Message::~Message((Message *)(param_1 + 0x7031));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  *(undefined ***)(iVar1 + -0x6c4c) = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar1 = MessageSimple::~MessageSimple((MessageSimple *)(iVar1 + -0x6b00));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  *(undefined ***)(iVar1 + -0x27c) = &msys::MCellAnime::vtable;
  iVar1 = CellAnime::~CellAnime((CellAnime *)(iVar1 + -0x130));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  *(undefined ***)(iVar1 + -100) = &vtable_for_5MoveVILj1EE;
  __aeabi_vec_dtor(iVar1 + -0x34,MoveWorkF::~MoveWorkF,0x2c,1);
  iVar1 = MoveVBase::~MoveVBase((MoveVBase *)(iVar1 + -100));
  *(undefined ***)(iVar1 + -0x6c44) = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar1 = MessageSimple::~MessageSimple((MessageSimple *)(iVar1 + -0x6af8));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  *(undefined ***)(iVar1 + -0x27c) = &msys::MCellAnime::vtable;
  iVar1 = CellAnime::~CellAnime((CellAnime *)(iVar1 + -0x130));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  *(undefined ***)(iVar1 + -100) = &vtable_for_5MoveVILj1EE;
  __aeabi_vec_dtor(iVar1 + -0x34,MoveWorkF::~MoveWorkF,0x2c,1);
  iVar1 = MoveVBase::~MoveVBase((MoveVBase *)(iVar1 + -100));
  iVar1 = msys::MDfxChr::~MDfxChr((MDfxChr *)(iVar1 + -0x17c));
  *(undefined ***)(iVar1 + -0x6c44) = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar1 = MessageSimple::~MessageSimple((MessageSimple *)(iVar1 + -0x6af8));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  *(undefined ***)(iVar1 + -0x72d4) = &BuyPnlBase::ItemPnlCA::vtable;
  *(undefined ***)(iVar1 + -0x27c) = &msys::MCellAnime::vtable;
  iVar1 = CellAnime::~CellAnime((CellAnime *)(iVar1 + -0x130));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  *(undefined ***)(iVar1 + -0x7058) = &BuyPnlBase::ItemPnlBase::vtable;
  iVar1 = msys::MDfxChr::~MDfxChr((MDfxChr *)(iVar1 + -0x17c));
  iVar1 = msys::MLytNum::~MLytNum((MLytNum *)(iVar1 + -0x230));
  *(undefined ***)(iVar1 + -0x6c44) = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar1 = MessageSimple::~MessageSimple((MessageSimple *)(iVar1 + -0x6af8));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  *(undefined ***)(iVar1 + -100) = &vtable_for_5MoveVILj1EE;
  __aeabi_vec_dtor(iVar1 + -0x34,MoveWorkF::~MoveWorkF,0x2c,1);
  iVar1 = MoveVBase::~MoveVBase((MoveVBase *)(iVar1 + -100));
  FUN_170095f4(iVar1 + -0x98);
  return;
}


// FUNC 0x17011254 shop::ShopMenu_EquipPage::vfunc_0x30 (ShopMenu)
//   size 0x30 | file ShopMenu+0x11254 | callers(0) | datarefs 1

void shop::ShopMenu_EquipPage::vfunc_0x30(int param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(0x22e98,*(MemAlcBase **)(param_1 + 0x18),(char *)0x0,0);
  uVar2 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_17010d74(pvVar1,param_1);
  }
  *(undefined4 *)(param_1 + 0x20) = uVar2;
  return;
}


// FUNC 0x17011288 shop::ShopMenu_EquipPage::vfunc_0x24 (ShopMenu)
//   size 0x8 | file ShopMenu+0x11288 | callers(0) | datarefs 1

undefined4 shop::ShopMenu_EquipPage::vfunc_0x24(void)

{
  return 1;
}


// FUNC 0x17011290 shop::ShopMenu_EquipPage::vfunc_0x4 (ShopMenu)
//   size 0x10 | file ShopMenu+0x11290 | callers(0) | datarefs 1

void shop::ShopMenu_EquipPage::vfunc_0x4(void)

{
  void *pvVar1;
  
  pvVar1 = (void *)ShopMenu_PageBase::vfunc_0x0();
  operator_delete(pvVar1);
  return;
}


// FUNC 0x170112a0 ->shop::ShopMenu_PageBase::vfunc_0x0 (ShopMenu)
//   size 0x4 | file ShopMenu+0x112a0 | callers(0) | datarefs 1
// veneer/thunk -> 0x17009fbc shop::ShopMenu_PageBase::vfunc_0x0 (ShopMenu)

// FUNC 0x170112a4 FUN_170112a4 (ShopMenu)
//   size 0x314 | file ShopMenu+0x112a4 | callers(0) | datarefs 1

void FUN_170112a4(void *param_1)

{
  int *piVar1;
  void *pvVar2;
  AnimButton *pAVar3;
  int iVar4;
  int iVar5;
  short *psVar6;
  undefined2 *puVar7;
  uint uVar8;
  MChrBase *pMVar9;
  char *local_34 [4];
  
  piVar1 = *(int **)(*(int *)((int)param_1 + 4) + 0x18);
  pvVar2 = (void *)(**(code **)(*piVar1 + 0xc))(piVar1,0x80,0);
  MemAlc::initCore((MemAlc *)((int)param_1 + 0x28),pvVar2,0x80);
  pAVar3 = (AnimButton *)
           ad::ctrl::ButtonGroup::FindButtonByName
                     (*(ButtonGroup **)((int)param_1 + 0x40),"btn_RETURN");
  *(AnimButton **)((int)param_1 + 0x78) = pAVar3;
  ad::ctrl::AnimButton::SetStateChangeCallback
            (pAVar3,(_func_void_AnimButton_ptr_State_State_void_ptr *)&LAB_17007df0,param_1);
  *(undefined4 *)(*(int *)((int)param_1 + 0x78) + 0x48) = 0;
  (**(code **)(**(int **)((int)param_1 + 0x78) + 0x28))(*(int **)((int)param_1 + 0x78),1);
  iVar4 = *(int *)((int)param_1 + 0x40);
  for (piVar1 = *(int **)(iVar4 + 8); piVar1 != (int *)(iVar4 + 8); piVar1 = (int *)*piVar1) {
    (**(code **)(piVar1[-5] + 0x28))(piVar1 + -5,0);
  }
  pAVar3 = (AnimButton *)
           ad::ctrl::ButtonGroup::FindButtonByName
                     (*(ButtonGroup **)((int)param_1 + 0x40),"btn_RETURN");
  *(AnimButton **)((int)param_1 + 0x78) = pAVar3;
  ad::ctrl::AnimButton::SetStateChangeCallback
            (pAVar3,(_func_void_AnimButton_ptr_State_State_void_ptr *)&LAB_17007df0,param_1);
  *(undefined4 *)(*(int *)((int)param_1 + 0x78) + 0x48) = 0;
  (**(code **)(**(int **)((int)param_1 + 0x78) + 0x28))(*(int **)((int)param_1 + 0x78),1);
  iVar4 = *(int *)((int)param_1 + 0x40);
  for (piVar1 = *(int **)(iVar4 + 8); piVar1 != (int *)(iVar4 + 8); piVar1 = (int *)*piVar1) {
    (**(code **)(piVar1[-5] + 0x28))(piVar1 + -5,0);
  }
  iVar4 = 0;
  do {
    pAVar3 = (AnimButton *)
             ad::ctrl::ButtonGroup::FindButtonByName
                       (*(ButtonGroup **)((int)param_1 + 0x40),(char *)(&DAT_17021c8c)[iVar4]);
    *(AnimButton **)((int)param_1 + iVar4 * 4 + 0x77cc) = pAVar3;
    ad::ctrl::AnimButton::SetStateChangeCallback
              (pAVar3,(_func_void_AnimButton_ptr_State_State_void_ptr *)&DAT_17011924,param_1);
    *(int *)(*(int *)((int)param_1 + iVar4 * 4 + 0x77cc) + 0x48) = iVar4;
    piVar1 = *(int **)((int)param_1 + iVar4 * 4 + 0x77cc);
    (**(code **)(*piVar1 + 0x28))(piVar1,0);
    iVar5 = msys::MComSys::_sys;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 2);
  iVar4 = *(int *)((int)param_1 + 8);
  if (*(int *)((int)param_1 + 8) == 0) {
    *(int *)((int)param_1 + 8) = msys::MComSys::_sys;
    iVar4 = iVar5;
  }
  FUN_17009d94((int)param_1 + 0x80,iVar4,*(undefined4 *)((int)param_1 + 0x40),
               *(undefined4 *)((int)param_1 + 0x3c),*(undefined4 *)((int)param_1 + 0x48));
  iVar4 = msys::MComSys::_sys;
  iVar5 = *(int *)((int)param_1 + 8);
  if (*(int *)((int)param_1 + 8) == 0) {
    *(int *)((int)param_1 + 8) = msys::MComSys::_sys;
    iVar5 = iVar4;
  }
  local_34[0] = "STATUS_M";
  local_34[1] = "STATUS_L";
  local_34[2] = "STATUS_K";
  uVar8 = 0;
  do {
    iVar4 = iVar5 + uVar8 * 0x27c;
    pMVar9 = (MChrBase *)(iVar4 + 0xeaed4);
    *(undefined1 *)(iVar4 + 0xeb015) = 1;
    msys::MLyt::detachMChr((MLyt *)(iVar5 + 0xea034),pMVar9);
    msys::MLyt::attachMChr
              ((MLyt *)(iVar5 + 0xea034),pMVar9,"INS_STATUS_CHARA_OBJ",local_34[uVar8],(char *)0x0,
               (char *)0x0);
    iVar4 = msys::MComSys::_sys;
    uVar8 = uVar8 + 1 & 0xff;
  } while (uVar8 < 3);
  iVar5 = *(int *)((int)param_1 + 8);
  if (*(int *)((int)param_1 + 8) == 0) {
    *(int *)((int)param_1 + 8) = msys::MComSys::_sys;
    iVar5 = iVar4;
  }
  psVar6 = (short *)shop::GetBootInfo();
  FUN_1700917c((MListWndPBase *)(iVar5 + 0xebe90),(int)*psVar6,0x1000,0);
  msys::MListWndPBase::resetCur((MListWndPBase *)(iVar5 + 0xebe90));
  *(byte *)(*(int *)(iVar5 + 0x104b4c) + 0x44) =
       *(byte *)(*(int *)(iVar5 + 0x104b4c) + 0x44) & 0xfe | 1;
  msys::MListWndPBase::setEnableInput((MListWndPBase *)(iVar5 + 0xf4cac),false);
  puVar7 = (undefined2 *)msys::MListWndPBase::getCurItem();
  FUN_170082b8(param_1,*puVar7);
  FUN_17008240(param_1,0);
  FUN_1700983c(*(undefined4 *)((int)param_1 + 100),0);
  *(undefined1 *)(*(int *)((int)param_1 + 4) + 0x14) = 1;
  *(undefined **)((int)param_1 + 0x10) = &DAT_1701233c;
  *(undefined4 *)((int)param_1 + 0x14) = 0;
  return;
}


// FUNC 0x170115ec FUN_170115ec (ShopMenu)
//   size 0x180 | file ShopMenu+0x115ec | callers(1) 0x17011780

void FUN_170115ec(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  uint in_fpscr;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 uStack_1c;
  
  FUN_1700beb8(msys::MComSys::_sys + 0x49368,0x110016,0,0,0);
  iVar1 = msys::MComSys::_sys;
  iVar5 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar5 = iVar1;
  }
  *(undefined1 *)(iVar5 + 0xe6508) = 0;
  msys::MListWndPBase::setEnableInput(*(MListWndPBase **)(param_1 + 0x50),false);
  msys::MListWndPBase::setDispCursor(*(MListWndPBase **)(param_1 + 0x50),false);
  msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x44),0xf,0,(char *)0x0,(char *)0x0);
  msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x48),0x10,0,(char *)0x0,(char *)0x0);
  local_28 = msys::MListWndPBase::getCurPos(*(MListWndPBase **)(param_1 + 0x50));
  local_20 = 0;
  uStack_1c = 0x42840000;
  iVar2 = msys::MListWndPBase::getSelectItem(*(MListWndPBase **)(param_1 + 0x50));
  iVar1 = msys::MComSys::_sys;
  iVar5 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar5 = iVar1;
  }
  uVar3 = *(undefined4 *)(*(int *)(iVar5 + 0xe904c) + 0x10);
  *(int *)(param_1 + 0x88) = iVar2;
  uVar3 = VectorSignedToFloat(uVar3,(byte)(in_fpscr >> 0x16) & 3);
  (**(code **)**(undefined4 **)(param_1 + 0x84))
            (uVar3,*(undefined4 **)(param_1 + 0x84),iVar2,&local_28,&local_20);
  ad::lyt::LytNumReel3::setValueInstant((LytNumReel3 *)(param_1 + 0x76e4),1);
  ad::lyt::LytNumReel3::setValueInstant
            ((LytNumReel3 *)(param_1 + 0x74b4),(uint)*(ushort *)(iVar2 + 4));
  FUN_17008240(param_1,1);
  iVar5 = 0;
  do {
    piVar4 = *(int **)(param_1 + iVar5 * 4 + 0x77c4);
    (**(code **)(*piVar4 + 0x28))(piVar4,1);
    iVar5 = iVar5 + 1;
  } while (iVar5 < 2);
  *(code **)(param_1 + 0x20) = FUN_170120b8;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


// FUNC 0x17011780 FUN_17011780 (ShopMenu)
//   size 0x194 | file ShopMenu+0x11780 | callers(0) | datarefs 4

void FUN_17011780(int param_1,uint *param_2)

{
  int iVar1;
  int iVar2;
  undefined2 *puVar3;
  MListWndPBase *pMVar4;
  
  iVar1 = msys::MListWndPBase::getSelectItem(*(MListWndPBase **)(param_1 + 0x50));
  if ((iVar1 == 0) ||
     (iVar1 = msys::MListWndPBase::getSelectItem(*(MListWndPBase **)(param_1 + 0x50)),
     *(char *)(iVar1 + 0xe) == '\0')) {
    iVar1 = (**(code **)(**(int **)(param_1 + 0x50) + 0x20))();
    if ((iVar1 == 0) &&
       ((iVar1 = msys::MListWndPBase::getListWnd(*(MListWndPBase **)(param_1 + 0x50)),
        *(int *)(iVar1 + 0x1cc) == 0 && ((*param_2 & 0x802) != 0)))) {
      (**(code **)(**(int **)(param_1 + 0x78) + 0x10))();
      (**(code **)(**(int **)(param_1 + 0x78) + 0xc))();
      iVar1 = msys::MComSys::_sys;
      iVar2 = *(int *)(param_1 + 8);
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar2 = iVar1;
      }
      *(undefined1 *)(iVar2 + 0xe6508) = 0;
    }
  }
  else {
    FUN_170115ec(param_1);
  }
  iVar1 = msys::MListWndPBase::getListWnd(*(MListWndPBase **)(param_1 + 0x50));
  if ((*(char *)(iVar1 + 0x144) != '\0') &&
     (iVar1 = msys::MListWndPBase::getListWnd(*(MListWndPBase **)(param_1 + 0x50)),
     *(int *)(iVar1 + 0x1cc) == 0)) {
    msys::MListWndPBase::getListWnd(*(MListWndPBase **)(param_1 + 0x50));
    puVar3 = (undefined2 *)ad::ui::UIListWindowPlusLyt::getCurItem();
    iVar1 = msys::MListWndPBase::getCurNo(*(MListWndPBase **)(param_1 + 0x50));
    if (iVar1 != *(short *)(param_1 + 0x7e)) {
      if (puVar3 != (undefined2 *)0x0) {
        FUN_170082b8(param_1,*puVar3);
        pMVar4 = *(MListWndPBase **)(param_1 + 0x50);
        iVar1 = msys::MListWndPBase::getListWnd(pMVar4);
        if (*(short *)(*(int *)(*(int *)(pMVar4 + 0x8e08) + (uint)*(byte *)(iVar1 + 0x149) * 4) + 4)
            != 0) {
          pMVar4 = *(MListWndPBase **)(param_1 + 0x50);
          iVar1 = msys::MListWndPBase::getListWnd(pMVar4);
          PutRegFlag(*(ushort *)
                      (*(int *)(*(int *)(pMVar4 + 0x8e08) + (uint)*(byte *)(iVar1 + 0x149) * 4) + 4)
                     ,1.0,(GlobalEvent *)0x0,(LocalEvent *)0x0);
        }
      }
      iVar1 = msys::MListWndPBase::getListWnd(*(MListWndPBase **)(param_1 + 0x50));
      *(ushort *)(param_1 + 0x7e) = (ushort)*(byte *)(iVar1 + 0x149);
    }
  }
  return;
}


// FUNC 0x17011930 FUN_17011930 (ShopMenu)
//   size 0x2c0 | file ShopMenu+0x11930 | callers(0)

void FUN_17011930(int param_1,int param_2,int param_3)

{
  char cVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  code *pcVar7;
  int *piVar8;
  
  iVar3 = msys::MComSys::_sys;
  pcVar2 = *(code **)(param_1 + 0x20);
  pcVar7 = FUN_17011d98;
  if (pcVar2 == FUN_17011d98) {
    pcVar7 = *(code **)(param_1 + 0x24);
  }
  if ((pcVar2 == FUN_17011d98 && pcVar7 == (code *)0x0) ||
     ((pcVar2 == (code *)0x0 &&
      ((*(uint *)(param_1 + 0x24) & 1) == 0 || *(uint *)(param_1 + 0x24) == 0)))) {
    cVar1 = *(char *)(param_2 + 0x48);
    if (param_3 != 1) {
      if (param_3 != 4) {
        if (param_3 != 5) {
          return;
        }
        if (cVar1 == '\0') {
          if (*(int *)(param_1 + 8) == 0) {
            *(int *)(param_1 + 8) = msys::MComSys::_sys;
          }
          else {
            iVar3 = *(int *)(param_1 + 8);
          }
          *(undefined1 *)(iVar3 + 0xe6508) = 0;
          msys::MListWndPBase::setDispCursor(*(MListWndPBase **)(param_1 + 0x50),true);
          ad::lyt::LytNumReel3::setValueInstant
                    ((LytNumReel3 *)(*(int *)(param_1 + 0x60) + 0x6d94),
                     *(int *)(*(int *)(param_1 + 0x60) + 0x6e10) + *(int *)(param_1 + 0x7760));
          piVar8 = *(int **)(param_1 + 0x5c);
          iVar6 = piVar8[0x75];
          iVar3 = *(int *)(param_1 + 30000);
          iVar4 = FUN_1700beb8(*piVar8 + 0x49368,0x11001e,0,0,0);
          piVar8[1] = iVar4;
          ad::lyt::LytNumReel3::setValue((LytNumReel3 *)(piVar8 + 0x56),iVar6 - iVar3);
          msys::MDfxChr::playDfx((MDfxChr *)(*(int *)(param_1 + 0x84) + 0x6edc),0x24);
          FUN_17008240(param_1,0);
          *(code **)(param_1 + 0x20) = FUN_17011edc;
          *(undefined4 *)(param_1 + 0x24) = 0;
        }
        else if (cVar1 == '\x01') {
          if (*(int *)(param_1 + 8) == 0) {
            *(int *)(param_1 + 8) = msys::MComSys::_sys;
          }
          else {
            iVar3 = *(int *)(param_1 + 8);
          }
          *(undefined1 *)(iVar3 + 0xe6508) = 0;
          msys::MListWndPBase::setEnableInput(*(MListWndPBase **)(param_1 + 0x50),false);
          msys::MListWndPBase::setDispCursor(*(MListWndPBase **)(param_1 + 0x50),true);
          msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x44),0xf,1,(char *)0x0,(char *)0x0);
          msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x48),0x10,1,(char *)0x0,(char *)0x0);
          FUN_17008240(param_1,0);
          *(code **)(param_1 + 0x20) = FUN_17012164;
          *(undefined4 *)(param_1 + 0x24) = 0;
        }
        else {
          if (*(int *)(param_1 + 8) == 0) {
            *(int *)(param_1 + 8) = msys::MComSys::_sys;
          }
          *(undefined1 *)(*(int *)(param_1 + 8) + 0xe6508) = 1;
          iVar4 = *(int *)(param_1 + 8);
          if (iVar4 == 0) {
            *(int *)(param_1 + 8) = iVar3;
            iVar4 = iVar3;
          }
          *(undefined1 *)(iVar4 + 0xe650a) = 1;
        }
        msys::MCursorBase::setVisible(*(MCursorBase **)(param_1 + 0x58),false);
        return;
      }
      if (cVar1 == '\0') {
        uVar5 = 0x110016;
      }
      else {
        uVar5 = 0x110017;
      }
      FUN_1700beb8(msys::MComSys::_sys + 0x49368,uVar5,0,0,0);
      iVar4 = msys::MComSys::_sys;
      iVar3 = *(int *)(param_1 + 8);
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar3 = iVar4;
      }
      *(undefined1 *)(iVar3 + 0xe6508) = 0;
      iVar4 = msys::MComSys::_sys;
      iVar3 = *(int *)(param_1 + 8);
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar3 = iVar4;
      }
      *(undefined1 *)(iVar3 + 0xe650a) = 1;
    }
    if ((char)(cVar1 + '\x13') != *(char *)(*(int *)(param_1 + 0x58) + 0x18)) {
      FUN_1700beb8(msys::MComSys::_sys + 0x49368,0x110015,0,0,0);
      *(char *)(*(int *)(param_1 + 0x58) + 0x18) = cVar1 + '\x13';
      msys::MCursorBase::setVisible(*(MCursorBase **)(param_1 + 0x58),true);
      FUN_1700ad98(*(undefined4 *)(param_1 + 0x58));
    }
  }
  return;
}


// FUNC 0x17011c1c shop::ShopMenu_UseItemPage::Core::vfunc_0x10 (ShopMenu)
//   size 0x110 | file ShopMenu+0x11c1c | callers(0) | datarefs 1

void shop::ShopMenu_UseItemPage::Core::vfunc_0x10(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = msys::MComSys::_sys;
  if (param_2 == 4) {
    FUN_1700beb8(msys::MComSys::_sys + 0x49368,0x110017,0,0,0);
    iVar2 = msys::MComSys::_sys;
    iVar1 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar1 = iVar2;
    }
    *(undefined1 *)(iVar1 + 0xe6508) = 0;
    iVar2 = msys::MComSys::_sys;
    iVar1 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar1 = iVar2;
    }
    *(undefined1 *)(iVar1 + 0xe650a) = 1;
  }
  else if (param_2 == 5) {
    if (*(char *)(*(int *)(param_1 + 0x78) + 0x48) == '\0') {
      iVar2 = *(int *)(param_1 + 8);
      if (iVar2 == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar2 = iVar1;
      }
      *(undefined1 *)(iVar2 + 0xe6508) = 0;
      msys::MListWndPBase::setEnableInput(*(MListWndPBase **)(param_1 + 0x50),false);
      *(undefined1 *)(param_1 + 0x7d) = 0;
    }
    else {
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
      }
      *(undefined1 *)(*(int *)(param_1 + 8) + 0xe6508) = 1;
      iVar2 = *(int *)(param_1 + 8);
      if (iVar2 == 0) {
        *(int *)(param_1 + 8) = iVar1;
        iVar2 = iVar1;
      }
      *(undefined1 *)(iVar2 + 0xe650a) = 1;
    }
    msys::MCursorBase::setVisible(*(MCursorBase **)(param_1 + 0x58),false);
    FUN_1700ad98(*(undefined4 *)(param_1 + 0x58));
    return;
  }
  return;
}


// FUNC 0x17011d34 FUN_17011d34 (ShopMenu)
//   size 0x5c | file ShopMenu+0x11d34 | callers(0) | datarefs 2

void FUN_17011d34(int param_1)

{
  MComSys *pMVar1;
  int iVar2;
  MComSys *this;
  
  iVar2 = (**(code **)(**(int **)(param_1 + 0x48) + 0x20))();
  pMVar1 = msys::MComSys::_sys;
  if (iVar2 == 0) {
    this = *(MComSys **)(param_1 + 8);
    if (*(MComSys **)(param_1 + 8) == (MComSys *)0x0) {
      *(MComSys **)(param_1 + 8) = msys::MComSys::_sys;
      this = pMVar1;
    }
    iVar2 = msys::MComSys::getNextPage(this);
    if (*(char *)(iVar2 + 0x14) != '\0') {
      *(undefined1 **)(param_1 + 0x18) = &LAB_1701232c;
      *(undefined4 *)(param_1 + 0x1c) = 0;
    }
  }
  return;
}


// FUNC 0x17011d98 FUN_17011d98 (ShopMenu)
//   size 0x130 | file ShopMenu+0x11d98 | callers(0) | datarefs 3

void FUN_17011d98(int param_1,uint *param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  cVar1 = *(char *)(*(int *)(param_1 + 0x58) + 0x18);
  uVar3 = *param_2;
  iVar6 = (int)(char)(cVar1 + -0x13);
  iVar5 = iVar6;
  if ((uVar3 & 0x401) != 0) {
    iVar4 = param_1 + iVar6 * 4;
    (**(code **)(**(int **)(iVar4 + 0x77cc) + 0x10))();
    (**(code **)(**(int **)(iVar4 + 0x77cc) + 0xc))();
    iVar2 = msys::MComSys::_sys;
    iVar4 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar4 = iVar2;
    }
    *(undefined1 *)(iVar4 + 0xe6508) = 0;
    goto LAB_17011e84;
  }
  if ((uVar3 & 0x802) == 0) {
    if ((uVar3 & 0x20) == 0) {
      if ((uVar3 & 0x10) == 0) {
        iVar4 = FUN_17009698(param_1 + 0x80);
        if (iVar4 != 0) {
          FUN_17008240(param_1,2);
          *(code **)(param_1 + 0x20) = FUN_170121ec;
          *(undefined4 *)(param_1 + 0x24) = 0;
        }
      }
      else {
        iVar5 = (int)(char)(cVar1 + -0x12);
        if (1 < iVar5) {
          iVar5 = 0;
        }
      }
      goto LAB_17011e84;
    }
    iVar5 = (int)(char)(cVar1 + -0x14);
    if (-1 < (char)(cVar1 + -0x14)) goto LAB_17011e84;
  }
  iVar5 = 1;
LAB_17011e84:
  if (iVar5 != iVar6) {
    FUN_1700beb8(msys::MComSys::_sys + 0x49368,0x110015,0,0,0);
    *(char *)(*(int *)(param_1 + 0x58) + 0x18) = (char)iVar5 + '\x13';
  }
  FUN_1700ad98(*(undefined4 *)(param_1 + 0x58));
  return;
}


// FUNC 0x17011edc FUN_17011edc (ShopMenu)
//   size 0xf8 | file ShopMenu+0x11edc | callers(0) | datarefs 1

void FUN_17011edc(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  short *psVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0x5c);
  if (*(int *)(iVar1 + 0x1dc) == *(int *)(iVar1 + 0x1d4)) {
    SndSeCtrl::stop(*(SndSeCtrl **)(iVar1 + 4),0);
    GameWork::addItem((GameWork *)&gGameWork,**(undefined2 **)(param_1 + 0x88),
                      (int)*(char *)(param_1 + 0x7760));
    GameWork::addCoin((GameWork *)&gGameWork,-*(int *)(param_1 + 30000));
    iVar3 = msys::MComSys::_sys;
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
    *(int *)(iVar1 + 0xea030) = *(int *)(iVar3 + 0xea030) + *(int *)(param_1 + 30000);
    psVar2 = (short *)shop::GetBootInfo();
    FUN_1700917c(*(undefined4 *)(param_1 + 0x50),(int)*psVar2,0x1000,0,param_4);
    msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x44),0xf,1,(char *)0x0,(char *)0x0);
    msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x48),0x10,1,(char *)0x0,(char *)0x0);
    *(code **)(param_1 + 0x20) = FUN_17012164;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x17011fe4 FUN_17011fe4 (ShopMenu)
//   size 0xbc | file ShopMenu+0x11fe4 | callers(0) | datarefs 1

void FUN_17011fe4(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = msys::MLyt::isEnableAnime(*(MLyt **)(param_1 + 0x48));
  if ((iVar2 == 0) && (iVar2 = msys::MLyt::isEnableAnime(*(MLyt **)(param_1 + 0x44)), iVar2 == 0)) {
    msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x44),0x19,0,"EXP_PNL_U_down",(char *)0x0);
    msys::MListWndPBase::setEnableInput(*(MListWndPBase **)(param_1 + 0x50),true);
    msys::MListWndPBase::setDispCursor(*(MListWndPBase **)(param_1 + 0x50),true);
    FUN_17008240(param_1,0);
    *(undefined2 *)(param_1 + 0x7e) = 0xffff;
    iVar1 = msys::MComSys::_sys;
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar1;
    }
    *(undefined1 *)(iVar2 + 0xe6508) = 1;
    iVar1 = msys::MComSys::_sys;
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar1;
    }
    *(undefined1 *)(iVar2 + 0xe650a) = 1;
    *(code **)(param_1 + 0x20) = FUN_17011780;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x170120b8 FUN_170120b8 (ShopMenu)
//   size 0xa4 | file ShopMenu+0x120b8 | callers(0) | datarefs 2

void FUN_170120b8(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_17009648(param_1 + 0x80);
  if (((iVar1 == 0) && (iVar1 = msys::MLyt::isEnableAnime(*(MLyt **)(param_1 + 0x48)), iVar1 == 0))
     && (iVar2 = msys::MLyt::isEnableAnime(*(MLyt **)(param_1 + 0x44)), iVar1 = msys::MComSys::_sys,
        iVar2 == 0)) {
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
    *(undefined1 *)(*(int *)(param_1 + 0x58) + 0x18) = 0x13;
    msys::MCursorBase::setVisible(*(MCursorBase **)(param_1 + 0x58),true);
    FUN_1700ad98(*(undefined4 *)(param_1 + 0x58));
    *(code **)(param_1 + 0x20) = FUN_17011d98;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x17012164 FUN_17012164 (ShopMenu)
//   size 0x80 | file ShopMenu+0x12164 | callers(0) | datarefs 3

void FUN_17012164(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = msys::MLyt::isEnableAnime(*(MLyt **)(param_1 + 0x48));
  if ((iVar1 == 0) &&
     (iVar2 = msys::MLyt::isEnableAnime(*(MLyt **)(param_1 + 0x44)), iVar1 = msys::MComSys::_sys,
     iVar2 == 0)) {
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
    msys::MListWndPBase::setEnableInput(*(MListWndPBase **)(param_1 + 0x50),true);
    *(code **)(param_1 + 0x20) = FUN_17011780;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x170121ec FUN_170121ec (ShopMenu)
//   size 0x3c | file ShopMenu+0x121ec | callers(0) | datarefs 1

void FUN_170121ec(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_17002228(param_1 + 0x80);
  if (iVar1 == 0) {
    FUN_17008240(param_1,1);
    *(code **)(param_1 + 0x20) = FUN_17011d98;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  FUN_1700ad98(*(undefined4 *)(param_1 + 0x58));
  return;
}


// FUNC 0x1701222c shop::ShopMenu_UseItemPage::Core::vfunc_0x8 (ShopMenu)
//   size 0xfc | file ShopMenu+0x1222c | callers(0) | datarefs 1

int shop::ShopMenu_UseItemPage::Core::vfunc_0x8(int *param_1,MInput *param_2)

{
  MInput MVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  code *extraout_r2;
  code *pcVar7;
  undefined4 *puVar8;
  bool bVar9;
  uint in_fpscr;
  undefined4 local_20;
  undefined4 local_1c;
  
  msys::MPageBase::updateInputAllChr((MPageBase *)param_1[1],param_2);
  bVar9 = (param_1[9] & 1U) == 0;
  pcVar7 = extraout_r2;
  if (bVar9) {
    pcVar7 = (code *)param_1[8];
  }
  piVar3 = (int *)((int)param_1 + (param_1[9] >> 1));
  if (!bVar9) {
    pcVar7 = *(code **)(*piVar3 + param_1[8]);
  }
  (*pcVar7)(piVar3,param_2);
  uVar4 = msys::MListWndPBase::isTpNeutral((MListWndPBase *)param_1[0x14]);
  MVar1 = param_2[0x11];
  bVar9 = MVar1 == (MInput)0x0;
  if (bVar9) {
    MVar1 = param_2[0x12];
  }
  puVar8 = (undefined4 *)(undefined1 *)0x0;
  if ((!bVar9 || MVar1 != (MInput)0x0) && uVar4 != 0) {
    local_20 = VectorSignedToFloat(*(ushort *)(param_2 + 0x14) - 0xa0,(byte)(in_fpscr >> 0x16) & 3);
    local_1c = VectorSignedToFloat(0x78 - (uint)*(ushort *)(param_2 + 0x16),
                                   (byte)(in_fpscr >> 0x16) & 3);
    puVar8 = &local_20;
  }
  uVar5 = (**(code **)(*param_1 + 0xc))(param_1,param_2);
  iVar2 = msys::MComSys::_sys;
  iVar6 = param_1[2];
  if (param_1[2] == 0) {
    param_1[2] = msys::MComSys::_sys;
    iVar6 = iVar2;
  }
  (**(code **)(*(int *)param_1[0x10] + 8))
            ((int *)param_1[0x10],puVar8,(int)*(char *)(iVar6 + 0xe6508) & uVar4 & uVar5);
  return (int)*(char *)((int)param_1 + 0x7d);
}


// FUNC 0x17012340 FUN_17012340 (ShopMenu)
//   size 0x34 | file ShopMenu+0x12340 | callers(0) | datarefs 1

void FUN_17012340(int param_1)

{
  msys::MLyt::playAnimeFromNo(*(MLyt **)(param_1 + 0x44),0x19,1,"EXP_PNL_U_down",(char *)0x0);
  *(code **)(param_1 + 0x18) = FUN_17011d34;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  return;
}


// FUNC 0x17012388 FUN_17012388 (ShopMenu)
//   size 0x114 | file ShopMenu+0x12388 | callers(1) 0x17012678

void FUN_17012388(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)FUN_1700a0e8();
  *puVar1 = &shop::ShopMenu_UseItemPage::Core::vtable;
  puVar1[0x23] = &shop::BuyPnlBase::ItemPnlBase::vtable;
  puVar1 = (undefined4 *)MoveVBase::MoveVBase((MoveVBase *)(puVar1 + 0x24));
  *puVar1 = &vtable_for_5MoveVILj1EE;
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(puVar1 + 0xc,FUN_17014c78,0x2c,1);
  *(int *)(iVar2 + -8) = iVar2;
  *(undefined1 *)(iVar2 + -4) = 1;
  puVar1 = (undefined4 *)FUN_1700c0a0(iVar2 + 0x34);
  *puVar1 = &msys::MMsg::vtable;
  iVar2 = MessageSimple::MessageSimple((MessageSimple *)(puVar1 + 0x53));
  *(undefined4 *)(iVar2 + 0x6ae0) = 0;
  *(undefined1 *)(iVar2 + 0x6ae4) = 0;
  *(undefined1 *)(iVar2 + 0x6ae5) = 0;
  *(undefined4 *)(iVar2 + 0x6ae8) = 0;
  *(undefined4 *)(iVar2 + 0x6aec) = 0;
  *(undefined4 *)(iVar2 + 0x6af4) = 0x400;
  iVar2 = msys::MLytNum::MLytNum((MLytNum *)(iVar2 + 0x6af8));
  iVar2 = msys::MDfxChr::MDfxChr((MDfxChr *)(iVar2 + 0x230));
  *(undefined ***)(iVar2 + -0x6edc) = &shop::BuyPnlBase::ItemPnlCA::vtable;
  puVar1 = (undefined4 *)FUN_1700c0a0(iVar2 + 0x17c);
  *puVar1 = &msys::MCellAnime::vtable;
  iVar2 = CellAnime::CellAnime((CellAnime *)(puVar1 + 0x53));
  *(undefined1 *)(iVar2 + 300) = 0xff;
  *(undefined1 *)(iVar2 + 0x12d) = 0xff;
  *(undefined1 *)(iVar2 + 0x12e) = 0xff;
  *(undefined1 *)(iVar2 + 0x12f) = 0xff;
  iVar2 = msys::MLytNum::MLytNum((MLytNum *)(iVar2 + 0x134));
  iVar2 = msys::MLytNum::MLytNum((MLytNum *)(iVar2 + 0x230));
  *(code **)(iVar2 + -0x7584) = FUN_170112a4;
  *(undefined4 *)(iVar2 + -0x7580) = 0;
  *(code **)(iVar2 + -0x757c) = FUN_17012340;
  *(undefined4 *)(iVar2 + -0x7578) = 0;
  *(code **)(iVar2 + -0x7574) = FUN_17011fe4;
  *(undefined4 *)(iVar2 + -0x7570) = 0;
  return;
}


// FUNC 0x170124bc shop::ShopMenu_UseItemPage::Core::vfunc_0x4 (ShopMenu)
//   size 0xc4 | file ShopMenu+0x124bc | callers(0) | datarefs 1

void shop::ShopMenu_UseItemPage::Core::vfunc_0x4(undefined4 *param_1)

{
  int iVar1;
  void *pvVar2;
  
  *param_1 = &vtable;
  iVar1 = msys::MLytNum::~MLytNum((MLytNum *)(param_1 + 0x1d65));
  iVar1 = msys::MLytNum::~MLytNum((MLytNum *)(iVar1 + -0x230));
  *(undefined ***)(iVar1 + -0x72d8) = &BuyPnlBase::ItemPnlCA::vtable;
  *(undefined ***)(iVar1 + -0x280) = &msys::MCellAnime::vtable;
  iVar1 = CellAnime::~CellAnime((CellAnime *)(iVar1 + -0x134));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  *(undefined ***)(iVar1 + -0x7058) = &BuyPnlBase::ItemPnlBase::vtable;
  iVar1 = msys::MDfxChr::~MDfxChr((MDfxChr *)(iVar1 + -0x17c));
  iVar1 = msys::MLytNum::~MLytNum((MLytNum *)(iVar1 + -0x230));
  *(undefined ***)(iVar1 + -0x6c44) = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar1 = MessageSimple::~MessageSimple((MessageSimple *)(iVar1 + -0x6af8));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  *(undefined ***)(iVar1 + -100) = &vtable_for_5MoveVILj1EE;
  __aeabi_vec_dtor(iVar1 + -0x34,MoveWorkF::~MoveWorkF,0x2c,1);
  iVar1 = MoveVBase::~MoveVBase((MoveVBase *)(iVar1 + -100));
  pvVar2 = (void *)FUN_170095f4(iVar1 + -0x90);
  operator_delete(pvVar2);
  return;
}


// FUNC 0x1701259c shop::ShopMenu_UseItemPage::Core::vfunc_0x0 (ShopMenu)
//   size 0xc0 | file ShopMenu+0x1259c | callers(0) | datarefs 1

void shop::ShopMenu_UseItemPage::Core::vfunc_0x0(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &vtable;
  iVar1 = msys::MLytNum::~MLytNum((MLytNum *)(param_1 + 0x1d65));
  iVar1 = msys::MLytNum::~MLytNum((MLytNum *)(iVar1 + -0x230));
  *(undefined ***)(iVar1 + -0x72d8) = &BuyPnlBase::ItemPnlCA::vtable;
  *(undefined ***)(iVar1 + -0x280) = &msys::MCellAnime::vtable;
  iVar1 = CellAnime::~CellAnime((CellAnime *)(iVar1 + -0x134));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  *(undefined ***)(iVar1 + -0x7058) = &BuyPnlBase::ItemPnlBase::vtable;
  iVar1 = msys::MDfxChr::~MDfxChr((MDfxChr *)(iVar1 + -0x17c));
  iVar1 = msys::MLytNum::~MLytNum((MLytNum *)(iVar1 + -0x230));
  *(undefined ***)(iVar1 + -0x6c44) = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar1 = MessageSimple::~MessageSimple((MessageSimple *)(iVar1 + -0x6af8));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  *(undefined ***)(iVar1 + -100) = &vtable_for_5MoveVILj1EE;
  __aeabi_vec_dtor(iVar1 + -0x34,MoveWorkF::~MoveWorkF,0x2c,1);
  iVar1 = MoveVBase::~MoveVBase((MoveVBase *)(iVar1 + -100));
  FUN_170095f4(iVar1 + -0x90);
  return;
}


// FUNC 0x17012678 shop::ShopMenu_UseItemPage::vfunc_0x30 (ShopMenu)
//   size 0x30 | file ShopMenu+0x12678 | callers(0) | datarefs 1

void shop::ShopMenu_UseItemPage::vfunc_0x30(int param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(0x77d4,*(MemAlcBase **)(param_1 + 0x18),(char *)0x0,0);
  uVar2 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_17012388(pvVar1,param_1);
  }
  *(undefined4 *)(param_1 + 0x20) = uVar2;
  return;
}


// FUNC 0x170126ac shop::ShopMenu_UseItemPage::vfunc_0x24 (ShopMenu)
//   size 0x8 | file ShopMenu+0x126ac | callers(0) | datarefs 1

undefined4 shop::ShopMenu_UseItemPage::vfunc_0x24(void)

{
  return 2;
}


// FUNC 0x170126b4 shop::ShopMenu_UseItemPage::vfunc_0x4 (ShopMenu)
//   size 0x10 | file ShopMenu+0x126b4 | callers(0) | datarefs 1

void shop::ShopMenu_UseItemPage::vfunc_0x4(void)

{
  void *pvVar1;
  
  pvVar1 = (void *)ShopMenu_PageBase::vfunc_0x0();
  operator_delete(pvVar1);
  return;
}


// FUNC 0x170126c4 ->shop::ShopMenu_PageBase::vfunc_0x0 (ShopMenu)
//   size 0x4 | file ShopMenu+0x126c4 | callers(0) | datarefs 1
// veneer/thunk -> 0x17009fbc shop::ShopMenu_PageBase::vfunc_0x0 (ShopMenu)

// FUNC 0x170126c8 FUN_170126c8 (ShopMenu)
//   size 0x84 | file ShopMenu+0x126c8 | callers(0)

void FUN_170126c8(int *param_1,int param_2,MLyt *param_3)

{
  InitParam aIStack_58 [20];
  undefined4 local_44;
  
  *param_1 = param_2;
  ad::lyt::LytNumReel3::InitParam::InitParam(aIStack_58);
  local_44 = GameWork::getCoin((GameWork *)&gGameWork);
  msys::MLytNumRes::set((MLytNumRes *)(param_2 + 0x844),aIStack_58,0,2,0x11);
  msys::MLytNum::init((MLytNum *)(param_1 + 2),aIStack_58,(LytDrawData *)(param_2 + 0xd3000),param_3
                      ,"INS_COUNT","COIN_ALL_base",(char *)0x0,(char *)0x0);
  return;
}


// FUNC 0x1701276c FUN_1701276c (ShopMenu)
//   size 0x2d8 | file ShopMenu+0x1276c | callers(1) 0x1700cfc8

/* WARNING: Type propagation algorithm not settling */

undefined4 FUN_1701276c(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  char cVar2;
  short sVar3;
  byte bVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined2 uVar8;
  int iVar9;
  uint uVar10;
  int *piVar11;
  int iVar12;
  int *piVar13;
  uint in_fpscr;
  float fVar14;
  float fVar15;
  
  cVar1 = (char)param_1[0x1cb8];
  piVar11 = (int *)param_1[0x1dd2];
  piVar13 = (int *)param_1[0x1dd1];
  sVar3 = *(short *)((int)param_1 + 0x72e2);
  if (cVar1 == '\0') {
    bVar4 = *(byte *)(param_2 + 4) & 0x40;
joined_r0x170127bc:
    if (bVar4 != 0) goto LAB_17012834;
LAB_170127e4:
    if (sVar3 != -1) {
      (**(code **)(*piVar11 + 0x28))(piVar11,1,*(code **)(*piVar11 + 0x28),param_4,param_4);
      (**(code **)(*piVar13 + 0x28))(piVar13,1);
      if ((char)param_1[0x1cb8] == '\0') {
        (**(code **)(*piVar13 + 0xc))(piVar13);
      }
      if ((char)param_1[0x1cb8] == '\x01') {
        (**(code **)(*piVar11 + 0xc))(piVar11);
      }
      return 0;
    }
  }
  else {
    if (cVar1 == '\x01') {
      bVar4 = *(byte *)(param_2 + 4) & 0x80;
      goto joined_r0x170127bc;
    }
    if (cVar1 == '\x02') {
      if ((char)piVar13[1] == '\x01' || (char)piVar13[1] == '\x03') goto LAB_17012834;
      goto LAB_170127e4;
    }
    if ((cVar1 != '\x03') || ((char)piVar11[1] != '\x01' && (char)piVar11[1] != '\x03'))
    goto LAB_170127e4;
LAB_17012834:
    if (sVar3 != -1) {
      if (0 < sVar3) {
        iVar5 = ad::fw::TaskBase::isFps30(*(TaskBase **)(*param_1 + 4));
        if (iVar5 == 0) {
          fVar14 = 1.0;
        }
        else {
          fVar14 = 2.0;
        }
        fVar15 = (float)VectorSignedToFloat((int)*(short *)((int)param_1 + 0x72e2),
                                            (byte)(in_fpscr >> 0x16) & 3);
        sVar3 = (short)(int)(fVar15 - fVar14);
        *(short *)((int)param_1 + 0x72e2) = sVar3;
        if (sVar3 < 0) {
          *(undefined2 *)((int)param_1 + 0x72e2) = 0;
          return 1;
        }
        return 1;
      }
      uVar8 = *(undefined2 *)(*(int *)(*param_1 + 0xe904c) + 0x18);
      goto LAB_170128e0;
    }
  }
  uVar8 = *(undefined2 *)(*(int *)(*param_1 + 0xe904c) + 0x14);
LAB_170128e0:
  *(undefined2 *)((int)param_1 + 0x72e2) = uVar8;
  cVar2 = (char)param_1[0x1db8];
  iVar9 = -1;
  iVar12 = (int)cVar2;
  iVar5 = iVar12;
  if (cVar1 == '\0' || cVar1 == '\x02') {
    uVar10 = 0;
    iVar9 = (int)(char)(cVar2 + '\x01');
    uVar6 = *(uint *)param_1[2];
    if ((uVar6 & 0xf000) == 0x2000) {
      uVar10 = (uint)(DAT_003f9610 == uVar6);
      if (DAT_003f9612 == uVar6) {
        uVar10 = uVar10 + 1;
      }
      if (DAT_003f9614 == uVar6) {
        uVar10 = uVar10 + 1;
      }
      if (DAT_003f9644 == uVar6) {
        uVar10 = uVar10 + 1;
      }
      if (DAT_003f9646 == uVar6) {
        uVar10 = uVar10 + 1;
      }
      if (DAT_003f9648 == uVar6) {
        uVar10 = uVar10 + 1;
      }
      if (DAT_003f9678 == uVar6) {
        uVar10 = uVar10 + 1;
      }
      if (DAT_003f967a == uVar6) {
        uVar10 = (uint)(char)((char)uVar10 + '\x01');
      }
      if (DAT_003f967c == uVar6) {
        uVar10 = (uint)(char)((char)uVar10 + '\x01');
      }
    }
    iVar7 = GameWork::getItemNum((GameWork *)&gGameWork,(ushort)uVar6);
    if (iVar9 <= (int)(iVar7 - uVar10)) {
      iVar5 = iVar9;
    }
    iVar9 = (uint)*(ushort *)(param_1[2] + 4) * iVar9;
  }
  else if (cVar1 == '\x01' || cVar1 == '\x03') {
    iVar9 = (int)(char)(cVar2 + -1);
    if (0 < iVar9) {
      iVar5 = iVar9;
    }
    iVar9 = (uint)*(ushort *)(param_1[2] + 4) * iVar9;
  }
  if (iVar5 != iVar12) {
    ad::lyt::LytNumReel3::setValueInstant((LytNumReel3 *)(param_1 + 0x1d99),iVar5);
    ad::lyt::LytNumReel3::setValueInstant((LytNumReel3 *)(param_1 + 0x1d0d),iVar9);
    FUN_1700beb8(*param_1 + 0x49368,0x11001f,0,0,0);
  }
  return 1;
}


// FUNC 0x17012a54 FUN_17012a54 (ShopMenu)
//   size 0x64 | file ShopMenu+0x12a54 | callers(0) | datarefs 4

void FUN_17012a54(MComSys *param_1)

{
  MTX44 aMStack_80 [64];
  MTX34 aMStack_40 [52];
  
  msys::MCamera::getProjMtx((MCamera *)(param_1 + 0x4ad54),aMStack_80,0x400);
  msys::MCamera::getViewMtx((MCamera *)(param_1 + 0x4ad54),aMStack_40);
  ad::fw::TaskBase::setULcdCameraInfoBase(*(TaskBase **)(param_1 + 4),aMStack_40,aMStack_80,1);
  ad::lyt::DrawInfo::SetProjectionMtx((DrawInfo *)(param_1 + 0x13dbf4),aMStack_80);
  msys::MComSys::funcCalcMainNomal(param_1);
  return;
}


// FUNC 0x17012ac0 shop::ShopMenu::vfunc_0x10 (ShopMenu)
//   size 0x38 | file ShopMenu+0x12ac0 | callers(0) | datarefs 1

void shop::ShopMenu::vfunc_0x10(MComSys *param_1,CmdList *param_2)

{
  MTX44 aMStack_50 [68];
  
  msys::MCamera::getProjMtx((MCamera *)(param_1 + 0x4ae34),aMStack_50,0x401);
  msys::MComSys::funcDrawLower(param_1,param_2);
  return;
}


// FUNC 0x17012b00 ->msys::MComSys::funcDrawUpper (ShopMenu)
//   size 0x4 | file ShopMenu+0x12b00 | callers(0) | datarefs 1
// veneer/thunk -> 0x0032e760 msys::MComSys::funcDrawUpper (static)

// FUNC 0x17012b04 FUN_17012b04 (ShopMenu)
//   size 0x74 | file ShopMenu+0x12b04 | callers(0)

void FUN_17012b04(int param_1)

{
  int iVar1;
  MChrBase *pMVar2;
  uint uVar3;
  
  uVar3 = 0;
  do {
    iVar1 = param_1 + uVar3 * 0x27c;
    pMVar2 = (MChrBase *)(iVar1 + 0xeaed4);
    *(undefined1 *)(iVar1 + 0xeb015) = 0;
    msys::MLyt::detachMChr((MLyt *)(param_1 + 0xea034),pMVar2);
    msys::MLyt::attachMChr
              ((MLyt *)(param_1 + 0xea034),pMVar2,"INS_STATUS_CHARA_OBJ","STATUS_EQUIP_SET",
               (char *)0x0,(char *)0x0);
    uVar3 = uVar3 + 1 & 0xff;
  } while (uVar3 < 3);
  return;
}


// FUNC 0x17012b94 FUN_17012b94 (ShopMenu)
//   size 0x88 | file ShopMenu+0x12b94 | callers(0)

void FUN_17012b94(int param_1)

{
  int iVar1;
  MChrBase *pMVar2;
  uint uVar3;
  char *local_30 [3];
  
  local_30[0] = "STATUS_M";
  local_30[1] = "STATUS_L";
  local_30[2] = "STATUS_K";
  uVar3 = 0;
  do {
    iVar1 = param_1 + uVar3 * 0x27c;
    pMVar2 = (MChrBase *)(iVar1 + 0xeaed4);
    *(undefined1 *)(iVar1 + 0xeb015) = 1;
    msys::MLyt::detachMChr((MLyt *)(param_1 + 0xea034),pMVar2);
    msys::MLyt::attachMChr
              ((MLyt *)(param_1 + 0xea034),pMVar2,"INS_STATUS_CHARA_OBJ",local_30[uVar3],(char *)0x0
               ,(char *)0x0);
    uVar3 = uVar3 + 1 & 0xff;
  } while (uVar3 < 3);
  return;
}


// FUNC 0x17012c3c FUN_17012c3c (ShopMenu)
//   size 0x11f8 | file ShopMenu+0x12c3c | callers(0) | datarefs 2

void FUN_17012c3c(MComSys *param_1)

{
  char cVar1;
  MComSys MVar2;
  byte bVar3;
  int iVar4;
  IAllocator *pIVar5;
  void *pvVar6;
  Resource *this;
  MComSys *pMVar7;
  MLyt *pMVar8;
  ushort *puVar9;
  MLyt *this_00;
  MCursorBase *pMVar10;
  MListWndPBase *pMVar11;
  wchar_t *pwVar12;
  int iVar13;
  LytDrawData *pLVar14;
  MComSys *pMVar15;
  undefined4 *puVar16;
  MLyt *pMVar17;
  uint uVar18;
  uint uVar19;
  StatusPanel *this_01;
  MemAlcBase *pMVar20;
  int *piVar21;
  MMsg *this_02;
  Resource *pRVar22;
  uint in_r12;
  bool bVar23;
  uint in_fpscr;
  float fVar24;
  undefined4 uVar25;
  ulonglong uVar26;
  longlong alStackY_698 [128];
  LytLocalize aLStack_280 [16];
  undefined4 local_270;
  wchar_t wStack_260;
  MComSys *local_25c;
  MComSys *local_254;
  char *local_248 [2];
  MLyt *local_240;
  MCursorBase *local_23c;
  undefined4 local_234;
  undefined **local_60;
  void *local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  MComSys *local_48 [4];
  MComSys *local_38;
  
  iVar13 = *(int *)(param_1 + 0x278);
  iVar4 = iVar13;
  while( true ) {
    bVar23 = iVar4 != iVar13 + 0x150;
    if (bVar23) {
      in_r12 = (uint)*(byte *)(iVar4 + 4);
    }
    if (!bVar23 || in_r12 == 0) break;
    iVar4 = iVar4 + 0xa8;
  }
  if (iVar4 == iVar13 + 0x150) {
    local_254 = param_1 + 0xe92a4;
    local_38 = param_1 + 0xe9000;
    MVar2 = param_1[0xe9050];
    local_25c = param_1 + 0xe9150;
    local_48[3] = param_1 + 0xe93e4;
    pRVar22 = (Resource *)(param_1 + 0xe9194);
    pMVar20 = (MemAlcBase *)(param_1 + 0xc);
    if (MVar2 == (MComSys)0x0) {
      iVar4 = ad::lyt::LytDrawSys::GetInst();
      pIVar5 = (IAllocator *)(iVar4 + 0x5f4);
      if (ad::lyt::Layout::s_pAllocator != pIVar5) {
        ad::lyt::Initialize(pIVar5,pIVar5);
      }
      *(MComSys **)(iVar4 + 0x5f8) = param_1 + 0xc;
      iVar4 = ad::lyt::LytDrawSys::GetInst();
      *(undefined4 *)(iVar4 + 0x5fc) = 0x10000;
      FUN_170081a0(*(undefined4 *)(param_1 + 4),pRVar22,*(undefined4 *)(param_1 + 0x278),
                   "m_item_all");
      puVar9 = (ushort *)shop::GetBootInfo();
      bVar3 = (&DAT_1701674a)[(*puVar9 & 0xffff0fff) * 4];
      FUN_170081a0(*(undefined4 *)(param_1 + 4),param_1 + 0xe91d8,*(undefined4 *)(param_1 + 0x278),
                   "menu_mario");
      FUN_170081a0(*(undefined4 *)(param_1 + 4),param_1 + 0xe921c,*(undefined4 *)(param_1 + 0x278),
                   "menu_luigi");
      FUN_170081a0(*(undefined4 *)(param_1 + 4),param_1 + 0xe9260,*(undefined4 *)(param_1 + 0x278),
                   "menu_koopa");
      FUN_170081a0(*(undefined4 *)(param_1 + 4),local_254,*(undefined4 *)(param_1 + 0x278),
                   *(undefined4 *)(&DAT_17016798 + (uint)bVar3 * 0x14));
      FUN_170081a0(*(undefined4 *)(param_1 + 4),param_1 + 0xe92e8,*(undefined4 *)(param_1 + 0x278),
                   "?m_touch_start");
      msys::MComSys::readLytNum
                (param_1,(FileContext *)(*(int *)(param_1 + 0x278) + 0xa8),(MemAlcBase *)0x0);
      ad::fw::TaskBase::readLyt
                (*(TaskBase **)(param_1 + 4),(Resource *)(param_1 + 0xe910c),
                 (FileContext *)(*(int *)(param_1 + 0x278) + 0xa8),
                 *(char **)(&DAT_1701678c + (uint)bVar3 * 0x14),pMVar20,0x7f,(ResCacheArg *)0x0);
      ad::fw::TaskBase::readLyt
                (*(TaskBase **)(param_1 + 4),(Resource *)local_25c,
                 (FileContext *)(*(int *)(param_1 + 0x278) + 0xa8),"?MENU_SHOP_Lyt",pMVar20,0x7f,
                 (ResCacheArg *)0x0);
      ad::fw::TaskBase::readLyt
                (*(TaskBase **)(param_1 + 4),(Resource *)(param_1 + 0xe90c8),
                 (FileContext *)(*(int *)(param_1 + 0x278) + 0xa8),"SQ_CURSOR_SET",pMVar20,0x7f,
                 (ResCacheArg *)0x0);
      (**(code **)(**(int **)(*(int *)(param_1 + 0xe64f0) + 0x44) + 0xc))
                (*(int **)(*(int *)(param_1 + 0xe64f0) + 0x44),"MDFXMenuArchive");
      MessageSys::GetPath(&wStack_260,(wchar_t *)L"Menu.msbt",false);
      local_60 = &nn::fs::IInputStream::vtable;
      local_5c = (void *)0x0;
      local_50 = 0;
      local_4c = 0;
      local_58 = 0;
      local_54 = 0;
      uVar26 = nn::fs::CTR::MPCore::detail::UserFileSystem::TryOpenFile(&local_5c,&wStack_260,1);
      uVar25 = (undefined4)(uVar26 >> 0x20);
      bVar23 = (uVar26 & 0x80000000) != 0;
      if (bVar23) {
        uVar25 = 0x17012ff4;
      }
      if (bVar23 && (int)uVar26 < 0) {
        nn::err::CTR::ThrowFatalErrAll((int)uVar26,uVar25);
      }
      local_60 = &nn::fs::FileInputStream::vtable;
      iVar4 = nn::fs::detail::FileBase::TryGetSize((FileBase *)&local_5c,alStackY_698 + 0x80);
      if (iVar4 < 0) {
        nn::err::CTR::ThrowFatalErrAll(iVar4,0x17013024);
      }
      pvVar6 = (void *)(**(code **)(*(int *)(param_1 + 0xc) + 0xc))(param_1 + 0xc,pMVar20,0);
      *(void **)(local_38 + 0x3e0) = pvVar6;
      iVar4 = nn::fs::detail::FileBase::TryRead
                        ((FileBase *)&local_5c,(int *)((int)alStackY_698 + 0x404),pvVar6,
                         (uint)pMVar20);
      if (iVar4 < 0) {
        nn::err::CTR::ThrowFatalErrAll(iVar4,0x17013068);
      }
      MsgDataAcsrBase::init((MsgDataAcsrBase *)local_48[3],*(void **)(local_38 + 0x3e0));
      if (((uint)local_5c & 0xfffffffe) != 0) {
        if (((uint)local_5c & 1) != 0) {
          nndbgPanic();
        }
        nn::fs::CTR::MPCore::detail::UserFileSystem::CloseFile
                  ((void *)((uint)local_5c & 0xfffffffe));
      }
      local_38[0x50] = (MComSys)0x1;
      return;
    }
    if (MVar2 == (MComSys)0x1) {
      if (param_1[0xe90cc] != (MComSys)0x0) {
        ad::lyt::LytResourceMan::init((LytResourceMan *)(param_1 + 2000));
        pvVar6 = (void *)ad::fw::Resource::getFileData((Resource *)(param_1 + 0xe90c8));
        ad::lyt::LytResourceMan::registerArc((LytResourceMan *)(param_1 + 2000),pvVar6,".");
        pvVar6 = (void *)ad::fw::Resource::getFileData((Resource *)(param_1 + 0xe910c));
        ad::lyt::LytResourceMan::registerArc((LytResourceMan *)(param_1 + 2000),pvVar6,".");
        pvVar6 = (void *)ad::fw::Resource::getFileData((Resource *)local_25c);
        ad::lyt::LytResourceMan::registerArc((LytResourceMan *)(param_1 + 2000),pvVar6,".");
        this = (Resource *)(param_1 + 0x844);
        pvVar6 = (void *)ad::fw::Resource::getFileData(this);
        ad::lyt::LytResourceMan::registerArc((LytResourceMan *)(param_1 + 2000),pvVar6,".");
        msys::MLytNumRes::init((MLytNumRes *)this,(LytResourceMan *)(param_1 + 2000),9);
        pLVar14 = (LytDrawData *)(param_1 + 0xd3000);
        pMVar17 = (MLyt *)(param_1 + 0xe9488);
        msys::MLyt::init(pMVar17,pLVar14,0);
        msys::MLyt::createLyt(pMVar17,(LytResourceMan *)(param_1 + 2000),"SQ_CURSOR.bflyt");
        MoveVBase::stop((MoveVBase *)(param_1 + 0xe9554));
        *(undefined4 *)(param_1 + 0xe9570) = 0;
        *(undefined4 *)(param_1 + 0xe9574) = 0;
        *(undefined4 *)(param_1 + 0xe9578) = 0xc347cccd;
        *(undefined4 *)(param_1 + 0xe9558) = *(undefined4 *)(param_1 + 0xe9570);
        *(undefined4 *)(param_1 + 0xe955c) = 0;
        *(undefined4 *)(param_1 + 0xe9560) = 0xc347cccd;
        param_1[0xe95c9] = (MComSys)0x0;
        *(undefined4 *)(param_1 + 0xe95c4) = 0x401;
        pMVar7 = param_1 + 0xe64e0;
        puVar16 = *(undefined4 **)(param_1 + 0xe9490);
        *(undefined4 **)(*(int *)(param_1 + 0xe948c) + 4) = puVar16;
        *puVar16 = *(undefined4 *)(param_1 + 0xe948c);
        pMVar15 = param_1 + 0xe948c;
        if (pMVar15 != (MComSys *)0x0) {
          *(MComSys **)(param_1 + 0xe9490) = pMVar7;
          *(int *)pMVar15 = *(int *)pMVar7;
          *(MComSys **)(*(int *)pMVar7 + 4) = pMVar15;
          *(MComSys **)pMVar7 = pMVar15;
        }
        local_240 = (MLyt *)(param_1 + 0xe9830);
        msys::MLyt::init(local_240,pLVar14,0);
        msys::MLyt::createLyt(local_240,(LytResourceMan *)(param_1 + 2000),"SQ_CURSOR.bflyt");
        MoveVBase::stop((MoveVBase *)(param_1 + 0xe98fc));
        *(undefined4 *)(param_1 + 0xe9918) = 0;
        *(undefined4 *)(param_1 + 0xe991c) = 0;
        *(undefined4 *)(param_1 + 0xe9920) = 0xc347cccd;
        *(undefined4 *)(param_1 + 0xe9900) = *(undefined4 *)(param_1 + 0xe9918);
        *(undefined4 *)(param_1 + 0xe9904) = 0;
        *(undefined4 *)(param_1 + 0xe9908) = 0xc347cccd;
        local_240[0x141] = (MLyt)0x0;
        *(undefined4 *)(local_240 + 0x13c) = 0x400;
        local_25c = param_1 + 0xe64d8;
        puVar16 = *(undefined4 **)(local_240 + 8);
        *(undefined4 **)(*(int *)(local_240 + 4) + 4) = puVar16;
        pMVar8 = local_240 + 4;
        *puVar16 = *(undefined4 *)(local_240 + 4);
        if (pMVar8 != (MLyt *)0x0) {
          iVar4 = *(int *)local_25c;
          *(MComSys **)(local_240 + 8) = local_25c;
          *(int *)pMVar8 = iVar4;
          *(MLyt **)(iVar4 + 4) = pMVar8;
          *(MLyt **)local_25c = pMVar8;
        }
        puVar9 = (ushort *)shop::GetBootInfo();
        local_248[0] = &DAT_1701678c +
                       (uint)(byte)(&DAT_1701674a)[(*puVar9 & 0xffff0fff) * 4] * 0x14;
        pMVar8 = (MLyt *)(param_1 + 0xea784);
        msys::MLyt::init(pMVar8,pLVar14,1);
        msys::MLyt::createLyt
                  (pMVar8,(LytResourceMan *)(param_1 + 2000),*(char **)(local_248[0] + 4));
        MoveVBase::stop((MoveVBase *)(param_1 + 0xea850));
        *(undefined4 *)(param_1 + 0xea86c) = 0;
        *(undefined4 *)(param_1 + 0xea870) = 0;
        *(undefined4 *)(param_1 + 0xea874) = 0xc348199a;
        *(undefined4 *)(param_1 + 0xea854) = *(undefined4 *)(param_1 + 0xea86c);
        *(undefined4 *)(param_1 + 0xea858) = 0;
        *(undefined4 *)(param_1 + 0xea85c) = 0xc348199a;
        *(undefined4 *)(param_1 + 0xea8c0) = 0x400;
        puVar16 = *(undefined4 **)(param_1 + 0xea78c);
        *(undefined4 **)(*(int *)(param_1 + 0xea788) + 4) = puVar16;
        *puVar16 = *(undefined4 *)(param_1 + 0xea788);
        pMVar15 = param_1 + 0xea788;
        if (pMVar15 != (MComSys *)0x0) {
          iVar4 = *(int *)local_25c;
          *(int *)pMVar15 = iVar4;
          *(MComSys **)(param_1 + 0xea78c) = local_25c;
          *(MComSys **)(iVar4 + 4) = pMVar15;
          *(MComSys **)local_25c = pMVar15;
        }
        msys::MLyt::init((MLyt *)(param_1 + 0xeab2c),pLVar14,1);
        msys::MLyt::createLyt
                  ((MLyt *)(param_1 + 0xeab2c),(LytResourceMan *)(param_1 + 2000),
                   *(char **)(local_248[0] + 8));
        MoveVBase::stop((MoveVBase *)(param_1 + 0xeabf8));
        *(undefined4 *)(param_1 + 0xeac14) = 0;
        *(undefined4 *)(param_1 + 0xeac18) = 0;
        *(undefined4 *)(param_1 + 0xeac1c) = 0xc348199a;
        *(undefined4 *)(param_1 + 0xeabfc) = *(undefined4 *)(param_1 + 0xeac14);
        *(undefined4 *)(param_1 + 0xeac00) = 0;
        *(undefined4 *)(param_1 + 0xeac04) = 0xc348199a;
        *(undefined4 *)(param_1 + 0xeac68) = 0x401;
        puVar16 = *(undefined4 **)(param_1 + 0xeab34);
        pMVar15 = param_1 + 0xeab30;
        *(undefined4 **)(*(int *)(param_1 + 0xeab30) + 4) = puVar16;
        *puVar16 = *(undefined4 *)(param_1 + 0xeab30);
        if (pMVar15 != (MComSys *)0x0) {
          iVar4 = *(int *)pMVar7;
          *(MComSys **)(param_1 + 0xeab34) = pMVar7;
          *(int *)pMVar15 = iVar4;
          *(MComSys **)(iVar4 + 4) = pMVar15;
          *(MComSys **)pMVar7 = pMVar15;
        }
        this_00 = (MLyt *)(param_1 + 0xea034);
        msys::MLyt::build(this_00,pMVar20,(AnimeName *)&PTR_s_FADE_OUT_17016380,0x1b);
        msys::MLyt::init(this_00,pLVar14,1);
        local_23c = (MCursorBase *)(param_1 + 0xeb9ac);
        msys::MLyt::createLyt
                  (this_00,(LytResourceMan *)(param_1 + 2000),"SHOP_U_n.bflyt",
                   (ButtonGroup *)(param_1 + 0xe946c),local_23c);
        MoveVBase::stop((MoveVBase *)(param_1 + 0xea100));
        *(undefined4 *)(param_1 + 0xea11c) = 0;
        *(undefined4 *)(param_1 + 0xea120) = 0;
        *(undefined4 *)(param_1 + 0xea124) = 0xc3480000;
        *(undefined4 *)(param_1 + 0xea104) = *(undefined4 *)(param_1 + 0xea11c);
        *(undefined4 *)(param_1 + 0xea108) = 0;
        *(undefined4 *)(param_1 + 0xea10c) = 0xc3480000;
        *(undefined4 *)(param_1 + 0xea170) = 0x400;
        puVar16 = *(undefined4 **)(param_1 + 0xea03c);
        *(undefined4 **)(*(int *)(param_1 + 0xea038) + 4) = puVar16;
        pMVar15 = param_1 + 0xea038;
        *puVar16 = *(undefined4 *)(param_1 + 0xea038);
        if (pMVar15 != (MComSys *)0x0) {
          iVar4 = *(int *)local_25c;
          *(MComSys **)(param_1 + 0xea03c) = local_25c;
          *(int *)pMVar15 = iVar4;
          *(MComSys **)(iVar4 + 4) = pMVar15;
          *(MComSys **)local_25c = pMVar15;
        }
        iVar4 = ad::fw::TaskBase::isFps30(*(TaskBase **)(param_1 + 4));
        if (iVar4 == 0) {
          fVar24 = 1.0;
        }
        else {
          fVar24 = 2.0;
        }
        msys::MCursorBase::init((MCursorBase *)(param_1 + 0xeb8c4),pMVar17,fVar24);
        pMVar10 = local_23c;
        iVar4 = 0x2e;
        pMVar15 = param_1 + 0xeb8f4;
        do {
          iVar4 = iVar4 + -1;
          *(undefined4 *)pMVar15 = 0;
          pMVar15 = pMVar15 + 4;
        } while (iVar4 != 0);
        pMVar17 = local_240;
        iVar4 = ad::fw::TaskBase::isFps30(*(TaskBase **)(param_1 + 4));
        fVar24 = 2.0;
        if (iVar4 == 0) {
          fVar24 = 1.0;
        }
        msys::MCursorBase::init(pMVar10,pMVar17,fVar24);
        iVar4 = 0x14;
        pMVar10 = pMVar10 + 0x30;
        do {
          iVar4 = iVar4 + -1;
          *(undefined4 *)pMVar10 = 0;
          pMVar10 = pMVar10 + 4;
        } while (iVar4 != 0);
        pMVar17 = (MLyt *)(param_1 + 0xea3dc);
        msys::MLyt::build(pMVar17,pMVar20,(AnimeName *)&PTR_s_FADE_OUT_17016458,0x1f);
        msys::MLyt::init(pMVar17,pLVar14,1);
        msys::MLyt::createLyt
                  (pMVar17,(LytResourceMan *)(param_1 + 2000),"SHOP_L_n.bflyt",
                   (ButtonGroup *)(param_1 + 0xe9450),(MCursorBase *)(param_1 + 0xeb8c4));
        MoveVBase::stop((MoveVBase *)(param_1 + 0xea4a8));
        *(undefined4 *)(param_1 + 0xea4c4) = 0;
        *(undefined4 *)(param_1 + 0xea4c8) = 0;
        *(undefined4 *)(param_1 + 0xea4cc) = 0xc3480000;
        *(undefined4 *)(param_1 + 0xea4ac) = *(undefined4 *)(param_1 + 0xea4c4);
        *(undefined4 *)(param_1 + 0xea4b0) = 0;
        *(undefined4 *)(param_1 + 0xea4b4) = 0xc3480000;
        *(undefined4 *)(param_1 + 0xea518) = 0x401;
        param_1[0xd30c4] = (MComSys)((byte)param_1[0xd30c4] | 6);
        (**(code **)(**(int **)(param_1 + 0xea52c) + 0x30))(*(int **)(param_1 + 0xea52c),pLVar14,1);
        param_1[0xd30c4] = (MComSys)((byte)param_1[0xd30c4] & 0xf9);
        *(undefined4 *)(param_1 + 0xea518) = 0x401;
        puVar16 = *(undefined4 **)(param_1 + 0xea3e4);
        *(undefined4 **)(*(int *)(param_1 + 0xea3e0) + 4) = puVar16;
        pMVar15 = param_1 + 0xea3e0;
        *puVar16 = *(undefined4 *)(param_1 + 0xea3e0);
        if (pMVar15 != (MComSys *)0x0) {
          iVar4 = *(int *)pMVar7;
          *(MComSys **)(param_1 + 0xea3e4) = pMVar7;
          *(int *)pMVar15 = iVar4;
          *(MComSys **)(iVar4 + 4) = pMVar15;
          *(MComSys **)pMVar7 = pMVar15;
        }
        pMVar11 = (MListWndPBase *)(param_1 + 0xebe90);
        FUN_1700252c(pMVar11,param_1,param_1 + 2000,*(undefined4 *)(local_38 + 0x4c));
        msys::MListWndPBase::setEnableInput(pMVar11,false);
        uVar18 = 0;
        param_1[0xebfd0] = (MComSys)0x1;
        msys::MLyt::attachMChr
                  (pMVar17,(MChrBase *)pMVar11,"INS_SHOP_L_LIST_BUY",(char *)0x0,(char *)0x0,
                   (char *)0x0);
        pMVar11 = (MListWndPBase *)(param_1 + 0xf4cac);
        FUN_17003878(pMVar11,param_1,param_1 + 2000,*(undefined4 *)(local_38 + 0x4c));
        msys::MListWndPBase::setEnableInput(pMVar11,false);
        param_1[0xf4dec] = (MComSys)0x1;
        msys::MLyt::attachMChr
                  (pMVar17,(MChrBase *)pMVar11,"INS_SHOP_L_LIST_SELL",(char *)0x0,(char *)0x0,
                   (char *)0x0);
        do {
          msys::MCellAnime::init
                    ((MCellAnime *)(param_1 + uVar18 * 0x27c + 0xeaed4),
                     (Resource *)(param_1 + uVar18 * 0x44 + 0xe91d8));
          CellAnime::play((CellAnime *)(param_1 + uVar18 * 0x27c + 0xeb020),'\0',0,1.0);
          uVar18 = uVar18 + 1 & 0xff;
        } while (uVar18 < 3);
        iVar4 = *(int *)(local_38 + 0x4c);
        local_48[0] = (MComSys *)
                      VectorSignedToFloat(*(undefined4 *)(iVar4 + 0x20),(byte)(in_fpscr >> 0x16) & 3
                                         );
        local_48[1] = (MComSys *)
                      VectorSignedToFloat(*(undefined4 *)(iVar4 + 0x24),(byte)(in_fpscr >> 0x16) & 3
                                         );
        local_48[2] = (MComSys *)
                      VectorSignedToFloat(*(undefined4 *)(iVar4 + 0x28),(byte)(in_fpscr >> 0x16) & 3
                                         );
        uVar18 = 0;
        do {
          param_1[uVar18 * 0x27c + 0xeb015] = (MComSys)0x0;
          pMVar7 = local_48[uVar18];
          MoveVBase::stop((MoveVBase *)(param_1 + uVar18 * 0x27c + 0xeafa0));
          *(undefined4 *)(param_1 + uVar18 * 0x27c + 0xeafbc) = 0;
          *(MComSys **)(param_1 + uVar18 * 0x27c + 0xeafc0) = pMVar7;
          *(undefined4 *)(param_1 + uVar18 * 0x27c + 0xeafc4) = 0;
          *(undefined4 *)(param_1 + uVar18 * 0x27c + 0xeafa4) = 0;
          *(MComSys **)(param_1 + uVar18 * 0x27c + 0xeafa8) = pMVar7;
          uVar19 = uVar18 + 1 & 0xff;
          *(undefined4 *)(param_1 + uVar18 * 0x27c + 0xeafac) = 0;
          uVar18 = uVar19;
        } while (uVar19 < 3);
        msys::MCellAnime::init((MCellAnime *)(param_1 + 0xeb648),(Resource *)local_254);
        puVar9 = (ushort *)shop::GetBootInfo();
        CellAnime::play((CellAnime *)(param_1 + 0xeb794),
                        (&DAT_1701637b)
                        [(uint)(byte)(&DAT_1701679e)
                                     [(uint)(byte)(&DAT_1701674a)[(*puVar9 & 0xffff0fff) * 4] * 0x14
                                     ] * 4],0,1.0);
        uVar25 = VectorSignedToFloat((int)*(short *)(local_248[0] + 0x10),
                                     (byte)(in_fpscr >> 0x16) & 3);
        MoveVBase::stop((MoveVBase *)(param_1 + 0xeb714));
        *(undefined4 *)(param_1 + 0xeb730) = 0;
        *(undefined4 *)(param_1 + 0xeb734) = uVar25;
        *(undefined4 *)(param_1 + 0xeb738) = 0;
        *(undefined4 *)(param_1 + 0xeb718) = *(undefined4 *)(param_1 + 0xeb730);
        *(undefined4 *)(param_1 + 0xeb71c) = uVar25;
        *(undefined4 *)(param_1 + 0xeb720) = 0;
        msys::MLyt::attachMChr
                  (pMVar8,(MChrBase *)(param_1 + 0xeb648),"INS_obj",(char *)0x0,(char *)0x0,
                   (char *)0x0);
        uVar18 = 0;
        local_248[0] = "STATUS_M";
        local_248[1] = "STATUS_L";
        local_240 = (MLyt *)0x17017ea8;
        do {
          this_01 = (StatusPanel *)(param_1 + uVar18 * 0x2034 + 0x1130fc);
          msys::StatusPanel::init(this_01,param_1,this_00,local_248[uVar18]);
          msys::StatusPanel::setChr(this_01,(uchar)uVar18);
          msys::StatusPanel::setType(this_01,1);
          msys::StatusPanel::setParam(this_01,(DataPc *)(param_1 + uVar18 * 0xb0 + 0xe9e10));
          uVar18 = uVar18 + 1 & 0xff;
        } while (uVar18 < 3);
        msys::StatusPanel::init
                  ((StatusPanel *)(param_1 + 0x119198),param_1,this_00,"STATUS_EQUIP_SET");
        msys::StatusPanel::setType((StatusPanel *)(param_1 + 0x119198),3);
        msys::MLyt::stopAndSetEndInst(this_00,"L","btn_L",(char *)0x0);
        msys::MLyt::stopAndSetEndInst(this_00,"R","btn_R",(char *)0x0);
        msys::MLyt::stopAndSetFrmInst(pMVar17,"SET_ICON",0.0,"tab_01",(char *)0x0);
        msys::MLyt::stopAndSetFrmInst(pMVar17,"SET_ICON",1.0,"tab_02",(char *)0x0);
        FUN_17002a70(param_1 + 0xeba2c,param_1);
        FUN_17002068(param_1 + 0xfdcd8,param_1,pMVar17);
        *(MComSys **)(param_1 + 0xfdaa0) = param_1;
        ad::lyt::LytNumReel3::InitParam::InitParam((InitParam *)local_248);
        local_234 = GameWork::getCoin((GameWork *)&gGameWork);
        msys::MLytNumRes::set((MLytNumRes *)this,local_248,0,2);
        msys::MLytNum::init((MLytNum *)(param_1 + 0xfdaa8),(InitParam *)local_248,pLVar14,pMVar17,
                            "INS_COUNT","COIN_ALL_base",(char *)0x0,(char *)0x0);
        FUN_17001e94(param_1 + 0x104b50,param_1);
        this_02 = (MMsg *)(param_1 + 0x10c4b8);
        *(MemAlcBase **)(param_1 + 0x1130ec) = pMVar20;
        *(undefined4 *)(param_1 + 0x1130f0) = 0;
        *(undefined4 *)(param_1 + 0x1130f8) = 0x401;
        *(undefined4 *)(param_1 + 0x1130f4) = 0;
        MessageSimple::init((MessageSimple *)(param_1 + 0x10c604));
        FUN_1700bd6c(this_02);
        pMVar7 = local_48[3];
        uVar25 = LMS_GetTextIndexByLabel(local_48[3] + 8,"MES_ShopMes_Info_Price");
        pwVar12 = (wchar_t *)LMS_GetText(pMVar7 + 8,uVar25);
        msys::MMsg::playStr(this_02,pwVar12,(InsParam *)0x0,false);
        msys::MLyt::attachMChr
                  (pMVar17,(MChrBase *)this_02,"INS_PRICE_TEXT","lbl_PRICE_ALL",(char *)0x0,
                   (char *)0x0);
        uVar18 = 0;
        do {
          fVar24 = (float)VectorUnsignedToFloat(uVar18,(byte)(in_fpscr >> 0x16) & 3);
          *(MComSys **)(param_1 + uVar18 * 0x6ee0 + 0x11b1cc) = param_1;
          pMVar8 = this_00;
          msys::MLyt::stopAndSetFrmInst
                    (this_00,"SET_ICON",fVar24,(char *)(&DAT_17021d74)[uVar18],(char *)0x0);
          msys::MCellAnime::init((MCellAnime *)(param_1 + uVar18 * 0x6ee0 + 0x121e30),pRVar22);
          param_1[uVar18 * 0x6ee0 + 0x12201f] =
               (MComSys)((byte)param_1[uVar18 * 0x6ee0 + 0x12201f] | 3);
          msys::MLyt::attachMChr
                    (pMVar8,(MChrBase *)(param_1 + uVar18 * 0x6ee0 + 0x121e30),"INS_ICON_OBJ",
                     (char *)(&DAT_17021d74)[uVar18],(char *)0x0,(char *)0x0);
          *(MemAlcBase **)(param_1 + uVar18 * 0x6ee0 + 0x121e20) = pMVar20;
          *(undefined4 *)(param_1 + uVar18 * 0x6ee0 + 0x121e24) = 0;
          *(undefined4 *)(param_1 + uVar18 * 0x6ee0 + 0x121e2c) = 0x400;
          *(undefined4 *)(param_1 + uVar18 * 0x6ee0 + 0x121e28) = 0;
          MessageSimple::init((MessageSimple *)(param_1 + uVar18 * 0x6ee0 + 0x11b338));
          FUN_1700bd6c(param_1 + uVar18 * 0x6ee0 + 0x11b1ec);
          MessageWriter::setFontColor
                    ((MessageWriter *)(param_1 + uVar18 * 0x6ee0 + 0x11b338),0xe6e6e6ff,true);
          msys::MLyt::attachMChr
                    (pMVar8,(MChrBase *)(param_1 + uVar18 * 0x6ee0 + 0x11b1ec),"list_text_top",
                     (char *)(&DAT_17021d74)[uVar18],(char *)0x0,(char *)0x0);
          iVar4 = msys::MLyt::getParts
                            (pMVar8,(char *)(&DAT_17021d74)[uVar18],(char *)0x0,(char *)0x0);
          ad::lyt::LytAnim::init
                    ((LytAnim *)(param_1 + uVar18 * 0x6ee0 + 0x11b1d0),*(Layout **)(iVar4 + 0xac),
                     "SET_COL","");
          if (uVar18 != 0) {
            fVar24 = (float)VectorUnsignedToFloat(uVar18,(byte)(in_fpscr >> 0x16) & 3);
            *(MComSys **)(param_1 + uVar18 * 0x6ec4 + 0x128fa8) = param_1;
            local_25c = (MComSys *)pMVar17;
            msys::MLyt::stopAndSetFrmInst
                      (pMVar17,"SET_ICON",fVar24,(char *)(&DAT_17021d80)[uVar18],(char *)0x0);
            msys::MCellAnime::init((MCellAnime *)(param_1 + uVar18 * 0x6ec4 + 0x12fbf0),pRVar22);
            param_1[uVar18 * 0x6ec4 + 0x12fddf] =
                 (MComSys)((byte)param_1[uVar18 * 0x6ec4 + 0x12fddf] | 3);
            msys::MLyt::attachMChr
                      ((MLyt *)local_25c,(MChrBase *)(param_1 + uVar18 * 0x6ec4 + 0x12fbf0),
                       "INS_ICON_OBJ",(char *)(&DAT_17021d80)[uVar18],(char *)0x0,(char *)0x0);
            *(MemAlcBase **)(param_1 + uVar18 * 0x6ec4 + 0x12fbe0) = pMVar20;
            *(undefined4 *)(param_1 + uVar18 * 0x6ec4 + 0x12fbe4) = 0;
            *(undefined4 *)(param_1 + uVar18 * 0x6ec4 + 0x12fbec) = 0x401;
            *(undefined4 *)(param_1 + uVar18 * 0x6ec4 + 0x12fbe8) = 0;
            MessageSimple::init((MessageSimple *)(param_1 + uVar18 * 0x6ec4 + 0x1290f8));
            FUN_1700bd6c(param_1 + uVar18 * 0x6ec4 + 0x128fac);
            MessageWriter::setFontColor
                      ((MessageWriter *)(param_1 + uVar18 * 0x6ec4 + 0x1290f8),0xe6e6e6ff,true);
            msys::MLyt::attachMChr
                      ((MLyt *)local_25c,(MChrBase *)(param_1 + uVar18 * 0x6ec4 + 0x128fac),
                       "list_text_top",(char *)(&DAT_17021d80)[uVar18],(char *)0x0,(char *)0x0);
          }
          uVar18 = uVar18 + 1 & 0xff;
        } while (uVar18 < 3);
        ad::lyt::LytLocalize::LytLocalize(aLStack_280);
        ad::lyt::LytLocalize::localize(aLStack_280,*(Layout **)(param_1 + 0xea184));
        ad::lyt::LytLocalize::localize(aLStack_280,*(Layout **)(param_1 + 0xea52c));
        iVar4 = 0;
        local_270 = 0;
        do {
          cVar1 = (char)iVar4;
          uVar25 = msys::MLyt::getParts
                             (pMVar17,(char *)(&DAT_17021e84)[iVar4],(char *)0x0,(char *)0x0);
          iVar4 = iVar4 + 1;
          *(undefined4 *)(param_1 + cVar1 * 4 + 0xeb8f4) = uVar25;
        } while (iVar4 < 0x2e);
        iVar4 = 0;
        do {
          cVar1 = (char)iVar4;
          uVar25 = msys::MLyt::getParts
                             (this_00,(char *)(&DAT_17021f3c)[iVar4],(char *)0x0,(char *)0x0);
          iVar4 = iVar4 + 1;
          *(undefined4 *)(param_1 + cVar1 * 4 + 0xeb9dc) = uVar25;
        } while (iVar4 < 0x14);
        msys::MLyt::playAnimeFromNo(this_00,0x1a,0,"EXP_PNL_U_down",(char *)0x0);
        msys::MLyt::playAnimeFromNo(pMVar17,0x1c,0,"SCRATCH_EXP_PNL",(char *)0x0);
        msys::MLyt::playAnimeFromNo(pMVar17,0x1d,0,"btn_NEXTpage",(char *)0x0);
        puVar9 = (ushort *)shop::GetBootInfo();
        fVar24 = (float)VectorUnsignedToFloat
                                  ((uint)(byte)(&DAT_1701674a)[(*puVar9 & 0xffff0fff) * 4],
                                   (byte)(in_fpscr >> 0x16) & 3);
        msys::MLyt::stopAndSetFrmInst(pMVar17,"SET_BG",fVar24,(char *)0x0,(char *)0x0);
        local_38[0x50] = (MComSys)0x2;
        return;
      }
    }
    else if (MVar2 == (MComSys)0x2) {
      *(code **)(param_1 + 0xf84) = FUN_170140a0;
      *(undefined4 *)(param_1 + 0xf88) = 0;
      piVar21 = *(int **)(param_1 + (char)param_1[(char)param_1[0xfd7] + 0xfcd] * 4 + 0xf8c);
      (**(code **)(*piVar21 + 8))(piVar21,0xffffffff);
      if ((char)piVar21[5] != '\0') {
        MoveC::moveFrm((MoveC *)(param_1 + 0x4acd4),(Color8 *)(alStackY_698 + 0x81),16.0);
        MoveC::moveFrm((MoveC *)(param_1 + 0x4ad14),(Color8 *)(alStackY_698 + 0x81),16.0);
        param_1[0xe6508] = (MComSys)0x1;
        param_1[0x4af14] = (MComSys)0x1;
        *(code **)(param_1 + 0xf84) = FUN_17012a54;
        *(undefined4 *)(param_1 + 0xf88) = 0;
      }
    }
  }
  return;
}


// FUNC 0x170140a0 FUN_170140a0 (ShopMenu)
//   size 0xbc | file ShopMenu+0x140a0 | callers(0) | datarefs 1

void FUN_170140a0(int param_1)

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
    *(code **)(param_1 + 0xf84) = FUN_17012a54;
    *(undefined4 *)(param_1 + 0xf88) = 0;
  }
  return;
}


// FUNC 0x17014174 FUN_17014174 (ShopMenu)
//   size 0x340 | file ShopMenu+0x14174 | callers(1) 0x170008a8

void FUN_17014174(MComSys *param_1,MTaskBase *param_2)

{
  int iVar1;
  IAllocator *pIVar2;
  undefined4 *puVar3;
  Job *pJVar4;
  uint uVar5;
  undefined4 uVar6;
  
  SndSys::LoadSync(0x6000187,0);
  msys::MComSys::initBaseSys
            (param_1,param_2,0x600000,0x200000,0x200000,0x100000,0x180000,2,'\0',false);
  iVar1 = ad::lyt::LytDrawSys::GetInst();
  pIVar2 = (IAllocator *)(iVar1 + 0x5f4);
  if (ad::lyt::Layout::s_pAllocator != pIVar2) {
    ad::lyt::Initialize(pIVar2,pIVar2);
  }
  *(MComSys **)(iVar1 + 0x5f8) = param_1 + 0xc;
  puVar3 = operator_new(0x78,(MemAlcBase *)(param_1 + 0xc),(char *)0x0,0);
  if (puVar3 != (undefined4 *)0x0) {
    *puVar3 = 0x437f0000;
    puVar3[1] = 0;
    puVar3[2] = 0x40a00000;
    puVar3[3] = 0x42700000;
    puVar3[4] = 0x10;
    puVar3[5] = 0x14;
    puVar3[6] = 2;
    puVar3[7] = 0x14;
    puVar3[8] = 0x3c;
    puVar3[9] = 0x3c;
    puVar3[10] = 0x19;
    puVar3[0xb] = 0x3c;
    puVar3[0xc] = 0x5a;
    puVar3[0xd] = 0x82;
    puVar3[0xe] = 0x1e;
    puVar3[0xf] = 0x2d;
    puVar3[0x10] = 0x3c;
    puVar3[0x11] = 1;
    puVar3[0x12] = 2;
    puVar3[0x13] = 6;
    puVar3[0x14] = 1;
    puVar3[0x15] = 2;
    puVar3[0x16] = 8;
    puVar3[0x17] = 1;
    puVar3[0x18] = 3;
    puVar3[0x19] = 6;
    puVar3[0x1a] = 0x28;
    puVar3[0x1b] = 0x14;
    puVar3[0x1c] = 10;
    puVar3[0x1d] = 0x41f00000;
  }
  *(undefined4 **)(param_1 + 0xe904c) = puVar3;
  msys::MComSys::entryPage(param_1,(MPageBase *)(param_1 + 0xe932c));
  msys::MComSys::entryPage(param_1,(MPageBase *)(param_1 + 0xe9350));
  msys::MComSys::entryPage(param_1,(MPageBase *)(param_1 + 0xe9374));
  msys::MComSys::entryPage(param_1,(MPageBase *)(param_1 + 0xe9398));
  msys::MComSys::entryPage(param_1,(MPageBase *)(param_1 + 0xe93bc));
  iVar1 = *(int *)(param_1 + 4);
  uVar6 = *(undefined4 *)(param_1 + 0x278);
  pJVar4 = operator_new(0x20,(MemAlcBase *)(iVar1 + 0x55c),(char *)0x0,0);
  if (pJVar4 != (Job *)0x0) {
    *(undefined ***)pJVar4 = &vtable_for_N2ad2fw11FileContext7InitJobIPS1_EE;
    *(undefined4 *)(pJVar4 + 4) = 0;
    *(undefined4 *)(pJVar4 + 8) = uVar6;
    *(undefined4 *)(pJVar4 + 0x14) = 2;
    *(undefined **)(pJVar4 + 0x10) = &DAT_170168f8;
    *(MComSys **)(pJVar4 + 0xc) = param_1 + 0xc;
    uVar6 = *(undefined4 *)(iVar1 + 0x4d8);
    *(undefined4 *)(pJVar4 + 0x18) = *(undefined4 *)(iVar1 + 0x4d4);
    *(undefined4 *)(pJVar4 + 0x1c) = uVar6;
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
  uVar5 = 0;
  do {
    DataPc::init((DataPc *)(param_1 + uVar5 * 0xb0 + 0xe9e10),(uchar)uVar5,
                 (DataPcPOD *)(&gGameWork + uVar5 * 0x34),(DataPcEquipFxParam *)(param_1 + 0xea020))
    ;
    uVar5 = uVar5 + 1 & 0xff;
  } while (uVar5 < 3);
  param_1[0x4ad85] = (MComSys)0x1;
  param_1[0x4ae65] = (MComSys)0x1;
  param_1[0xe6508] = (MComSys)0x0;
  *(undefined4 *)(param_1 + 0xea030) = 0;
  param_1[0xe9050] = (MComSys)0x0;
  *(code **)(param_1 + 0xf84) = FUN_17012c3c;
  *(undefined4 *)(param_1 + 0xf88) = 0;
  return;
}


// FUNC 0x170144fc FUN_170144fc (ShopMenu)
//   size 0x614 | file ShopMenu+0x144fc | callers(1) 0x170008a8

int FUN_170144fc(MComSys *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 local_18;
  
  local_18 = param_4;
  puVar1 = (undefined4 *)msys::MComSys::MComSys(param_1);
  *puVar1 = &shop::ShopMenu::vtable;
  puVar1[0x3a415] = 0;
  iVar2 = ad::font::ResFont::ResFont((ResFont *)(puVar1 + 0x3a416));
  ad::lyt::LytResourceMan::init((LytResourceMan *)(iVar2 + -4));
  iVar2 = ad::fw::Resource::Resource((Resource *)(iVar2 + 0x70));
  iVar2 = ad::fw::Resource::Resource((Resource *)(iVar2 + 0x44));
  iVar2 = ad::fw::Resource::Resource((Resource *)(iVar2 + 0x44));
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(iVar2 + 0x44,ad::fw::Resource::Resource,0x44,6);
  iVar3 = iVar2 + 0x19c;
  *(int *)iVar3 = iVar3;
  *(int *)(iVar2 + 0x1a0) = iVar3;
  *(int *)(iVar2 + 0x1a4) = iVar2 + 0x1a4;
  *(int *)(iVar2 + 0x1a8) = iVar2 + 0x1a4;
  *(undefined1 *)(iVar2 + 0x1ac) = 0;
  *(undefined4 *)(iVar2 + 0x1b0) = 0;
  *(undefined4 *)(iVar2 + 0x1b4) = 0;
  *(undefined ***)(iVar2 + 0x198) = &shop::ShopMenu_TopPage::vtable;
  iVar3 = iVar2 + 0x1c0;
  *(undefined4 *)(iVar2 + 0x1b8) = 0;
  *(int *)iVar3 = iVar3;
  *(int *)(iVar2 + 0x1c4) = iVar3;
  iVar3 = iVar2 + 0x1c8;
  *(int *)iVar3 = iVar3;
  *(int *)(iVar2 + 0x1cc) = iVar3;
  *(undefined1 *)(iVar2 + 0x1d0) = 0;
  *(undefined4 *)(iVar2 + 0x1d4) = 0;
  *(undefined4 *)(iVar2 + 0x1d8) = 0;
  *(undefined ***)(iVar2 + 0x1bc) = &shop::ShopMenu_EquipPage::vtable;
  iVar3 = iVar2 + 0x1e4;
  *(undefined4 *)(iVar2 + 0x1dc) = 0;
  *(int *)iVar3 = iVar3;
  *(int *)(iVar2 + 0x1e8) = iVar3;
  iVar3 = iVar2 + 0x1ec;
  *(int *)iVar3 = iVar3;
  *(int *)(iVar2 + 0x1f0) = iVar3;
  *(undefined1 *)(iVar2 + 500) = 0;
  *(undefined4 *)(iVar2 + 0x1f8) = 0;
  *(undefined4 *)(iVar2 + 0x1fc) = 0;
  *(undefined ***)(iVar2 + 0x1e0) = &shop::ShopMenu_UseItemPage::vtable;
  iVar3 = iVar2 + 0x208;
  *(undefined4 *)(iVar2 + 0x200) = 0;
  *(int *)iVar3 = iVar3;
  *(int *)(iVar2 + 0x20c) = iVar3;
  iVar3 = iVar2 + 0x210;
  *(int *)iVar3 = iVar3;
  *(int *)(iVar2 + 0x214) = iVar3;
  *(undefined1 *)(iVar2 + 0x218) = 0;
  *(undefined4 *)(iVar2 + 0x21c) = 0;
  *(undefined4 *)(iVar2 + 0x220) = 0;
  *(undefined ***)(iVar2 + 0x204) = &shop::ShopMenu_BadgePage::vtable;
  iVar3 = iVar2 + 0x22c;
  *(undefined4 *)(iVar2 + 0x224) = 0;
  *(int *)iVar3 = iVar3;
  *(int *)(iVar2 + 0x230) = iVar3;
  iVar3 = iVar2 + 0x234;
  *(int *)iVar3 = iVar3;
  *(int *)(iVar2 + 0x238) = iVar3;
  *(undefined1 *)(iVar2 + 0x23c) = 0;
  *(undefined4 *)(iVar2 + 0x240) = 0;
  *(undefined4 *)(iVar2 + 0x244) = 0;
  *(undefined ***)(iVar2 + 0x228) = &shop::ShopMenu_SellPage::vtable;
  *(undefined4 *)(iVar2 + 0x248) = 0;
  puVar1 = (undefined4 *)
           MsgDataAcsrBase::MsgDataAcsrBase
                     ((MsgDataAcsrBase *)(iVar2 + 0x250),(LMSBlockInfo *)(iVar2 + 0x27c),4);
  *puVar1 = &vtable_for_20MsgDataAcsrTmplFixedILh4EE;
  iVar2 = ad::ctrl::ButtonGroup::ButtonGroup((ButtonGroup *)(puVar1 + 0x1b));
  iVar2 = ad::ctrl::ButtonGroup::ButtonGroup((ButtonGroup *)(iVar2 + 0x1c));
  iVar2 = FUN_17008110(iVar2 + 0x1c);
  iVar2 = FUN_17008110(iVar2 + 0x3a8);
  puVar1 = (undefined4 *)FUN_1700c0a0(iVar2 + 0x3a8);
  *puVar1 = &msys::MReelNumMan2::vtable;
  iVar2 = ad::lyt::LytNumReel2::LytNumReel2((LytNumReel2 *)(puVar1 + 0x54));
  *(undefined1 *)(iVar2 + 0xe4) = 0;
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(iVar2 + 0xe8,DataPc::DataPc,0xb0,3);
  iVar2 = DataPcEquipFxParam::DataPcEquipFxParam((DataPcEquipFxParam *)(iVar2 + 0x210));
  iVar2 = FUN_17008110(iVar2 + 0x14);
  iVar2 = FUN_17008110(iVar2 + 0x3a8);
  iVar2 = FUN_17008110(iVar2 + 0x3a8);
  iVar2 = FUN_17008110(iVar2 + 0x3a8);
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(iVar2 + 0x3a8,FUN_170013e4,0x27c,3);
  puVar1 = (undefined4 *)FUN_1700c0a0(iVar2 + 0x774);
  *puVar1 = &msys::MCellAnime::vtable;
  iVar2 = CellAnime::CellAnime((CellAnime *)(puVar1 + 0x53));
  *(undefined1 *)(iVar2 + 300) = 0xff;
  *(undefined1 *)(iVar2 + 0x12d) = 0xff;
  *(undefined1 *)(iVar2 + 0x12e) = 0xff;
  *(undefined1 *)(iVar2 + 0x12f) = 0xff;
  puVar1 = (undefined4 *)msys::MCursorBase::MCursorBase((MCursorBase *)(iVar2 + 0x130));
  *puVar1 = &vtable_for_N4msys7MCursorILj46EEE;
  __aeabi_memclr4(puVar1 + 0xc,0xb8);
  puVar1 = (undefined4 *)msys::MCursorBase::MCursorBase((MCursorBase *)(puVar1 + 0x3a));
  *puVar1 = &vtable_for_N4msys7MCursorILj20EEE;
  __aeabi_memclr4(puVar1 + 0xc,0x50);
  iVar2 = msys::MLytNum::MLytNum((MLytNum *)(puVar1 + 0x21));
  iVar2 = msys::MLytNum::MLytNum((MLytNum *)(iVar2 + 0x230));
  puVar1 = (undefined4 *)
           msys::MListWndPBase::MListWndPBase
                     ((MListWndPBase *)(iVar2 + 0x230),(MListWndPCore *)(iVar2 + 0x42c));
  *puVar1 = &vtable_for_N4msys9MListWndPILi256EEE;
  puVar1 = (undefined4 *)
           ad::ui::UIListWindowPlusLyt::UIListWindowPlusLyt((UIListWindowPlusLyt *)(puVar1 + 0x7f));
  puVar1[-0x7f] = &shop::MListWndShop::vtable;
  *puVar1 = &msys::MListWndPCore::vtable;
  iVar2 = ad::lyt::Layout::Layout((Layout *)(puVar1 + 0x2262));
  iVar2 = FUN_1700b0a8(iVar2 + 0x3c);
  iVar2 = FUN_1700b0a8(iVar2 + 0x1c);
  iVar2 = FUN_1700b0a8(iVar2 + 0x1c);
  iVar2 = ad::lyt::Layout::Layout((Layout *)(iVar2 + 0x1c));
  iVar2 = FUN_1700b0a8(iVar2 + 0x3c);
  iVar2 = FUN_1700b0a8(iVar2 + 0x1c);
  iVar2 = FUN_1700b0a8(iVar2 + 0x1c);
  iVar2 = FUN_1700b0a8(iVar2 + 0x1c);
  iVar2 = FUN_1700b0a8(iVar2 + 0x1c);
  iVar2 = CellAnime::CellAnime((CellAnime *)(iVar2 + 0x1c));
  *(undefined4 *)(iVar2 + 0x134) = 0;
  puVar1 = (undefined4 *)
           msys::MListWndPBase::MListWndPBase
                     ((MListWndPBase *)(iVar2 + 0x140),(MListWndPCore *)(iVar2 + 0x33c));
  *puVar1 = &vtable_for_N4msys9MListWndPILi256EEE;
  puVar1 = (undefined4 *)
           ad::ui::UIListWindowPlusLyt::UIListWindowPlusLyt((UIListWindowPlusLyt *)(puVar1 + 0x7f));
  puVar1[-0x7f] = &shop::MListWndShopSell::vtable;
  *puVar1 = &msys::MListWndPCore::vtable;
  iVar2 = ad::lyt::Layout::Layout((Layout *)(puVar1 + 0x2262));
  iVar2 = FUN_1700b0a8(iVar2 + 0x3c);
  iVar2 = FUN_1700b0a8(iVar2 + 0x1c);
  iVar2 = FUN_1700b0a8(iVar2 + 0x1c);
  iVar2 = ad::lyt::Layout::Layout((Layout *)(iVar2 + 0x1c));
  iVar2 = FUN_1700b0a8(iVar2 + 0x3c);
  iVar2 = FUN_1700b0a8(iVar2 + 0x1c);
  iVar2 = FUN_1700b0a8(iVar2 + 0x1c);
  iVar2 = FUN_1700b0a8(iVar2 + 0x1c);
  iVar2 = CellAnime::CellAnime((CellAnime *)(iVar2 + 0x1c));
  *(undefined4 *)(iVar2 + 0x130) = 0;
  iVar2 = msys::MLytNum::MLytNum((MLytNum *)(iVar2 + 0x13c));
  puVar1 = (undefined4 *)FUN_1700c0a0(iVar2 + 0x230);
  *puVar1 = &msys::MMsg::vtable;
  iVar2 = MessageSimple::MessageSimple((MessageSimple *)(puVar1 + 0x53));
  *(undefined4 *)(iVar2 + 0x6ae0) = 0;
  *(undefined1 *)(iVar2 + 0x6ae4) = 0;
  *(undefined1 *)(iVar2 + 0x6ae5) = 0;
  *(undefined4 *)(iVar2 + 0x6ae8) = 0;
  *(undefined4 *)(iVar2 + 0x6aec) = 0;
  *(undefined4 *)(iVar2 + 0x6af4) = 0x400;
  iVar2 = msys::MLytNum::MLytNum((MLytNum *)(iVar2 + 0x6af8));
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(iVar2 + 0x238,msys::MLytNum::MLytNum,0x230,6);
  puVar1 = (undefined4 *)FUN_1700c0a0(iVar2 + 0xd20);
  *puVar1 = &msys::MMsg::vtable;
  iVar2 = MessageSimple::MessageSimple((MessageSimple *)(puVar1 + 0x53));
  *(undefined4 *)(iVar2 + 0x6ae0) = 0;
  *(undefined1 *)(iVar2 + 0x6ae4) = 0;
  *(undefined1 *)(iVar2 + 0x6ae5) = 0;
  *(undefined4 *)(iVar2 + 0x6ae8) = 0;
  *(undefined4 *)(iVar2 + 0x6aec) = 0;
  *(undefined4 *)(iVar2 + 0x6af4) = 0x400;
  puVar1 = (undefined4 *)FUN_1700c0a0(iVar2 + 0x6af8);
  *puVar1 = &msys::MMsg::vtable;
  iVar2 = MessageSimple::MessageSimple((MessageSimple *)(puVar1 + 0x53));
  *(undefined4 *)(iVar2 + 0x6ae0) = 0;
  *(undefined1 *)(iVar2 + 0x6ae4) = 0;
  *(undefined1 *)(iVar2 + 0x6ae5) = 0;
  *(undefined4 *)(iVar2 + 0x6ae8) = 0;
  *(undefined4 *)(iVar2 + 0x6aec) = 0;
  *(undefined4 *)(iVar2 + 0x6af4) = 0x400;
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(iVar2 + 0x6af8,msys::StatusPanel::StatusPanel,0x2034,3);
  iVar2 = msys::StatusPanel::StatusPanel((StatusPanel *)(iVar2 + 0x609c));
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(iVar2 + 0x2034,&LAB_17003784,0x6ee0,3);
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(iVar2 + 0x14ca0,&LAB_1700d4a0,0x6ec4,2);
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(iVar2 + 0xdd88,FUN_170011e4,0x100,2);
  local_18 = 0xff808080;
  FrameBuf::setClearColor((FrameBuf *)&gFrameBuf,&local_18);
  return iVar2 + -0x13dbf4;
}


// FUNC 0x17014bf4 shop::ShopMenu::vfunc_0x4 (ShopMenu)
//   size 0x10 | file ShopMenu+0x14bf4 | callers(0) | datarefs 1

void shop::ShopMenu::vfunc_0x4(void)

{
  void *pvVar1;
  
  pvVar1 = (void *)vfunc_0x0();
  operator_delete(pvVar1);
  return;
}


// FUNC 0x17014c04 FUN_17014c04 (ShopMenu)
//   size 0x34 | file ShopMenu+0x14c04 | callers(0) | datarefs 1

void FUN_17014c04(MoveVBase *param_1)

{
  void *pvVar1;
  
  *(undefined ***)param_1 = &vtable_for_5MoveVILj1EE;
  __aeabi_vec_dtor(param_1 + 0x30,MoveWorkF::~MoveWorkF,0x2c,1);
  pvVar1 = (void *)MoveVBase::~MoveVBase(param_1);
  operator_delete(pvVar1);
  return;
}


// FUNC 0x17014c40 FUN_17014c40 (ShopMenu)
//   size 0x30 | file ShopMenu+0x14c40 | callers(0) | datarefs 1

void FUN_17014c40(MoveVBase *param_1)

{
  *(undefined ***)param_1 = &vtable_for_5MoveVILj1EE;
  __aeabi_vec_dtor(param_1 + 0x30,MoveWorkF::~MoveWorkF,0x2c,1);
  MoveVBase::~MoveVBase(param_1);
  return;
}


// FUNC 0x17014c78 FUN_17014c78 (ShopMenu)
//   size 0x2c | file ShopMenu+0x14c78 | callers(0) | datarefs 9

undefined4 * FUN_17014c78(MoveWorkF *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)MoveWorkF::MoveWorkF(param_1);
  *puVar1 = &MoveWorkV::vtable;
  puVar1[8] = 0;
  puVar1[9] = 0;
  puVar1[10] = 0;
  return puVar1;
}


// FUNC 0x17014cac MoveWorkV::vfunc_0x4 (ShopMenu)
//   size 0x10 | file ShopMenu+0x14cac | callers(0) | datarefs 1

void MoveWorkV::vfunc_0x4(MoveWorkF *param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)MoveWorkF::~MoveWorkF(param_1);
  operator_delete(pvVar1);
  return;
}


// FUNC 0x17014cbc ->MoveWorkF::~MoveWorkF (ShopMenu)
//   size 0x4 | file ShopMenu+0x14cbc | callers(0) | datarefs 15
// veneer/thunk -> 0x00340694 MoveWorkF::~MoveWorkF (static)

// FUNC 0x17014cc0 MemAlcH::vfunc_0x10 (ShopMenu)
//   size 0x4 | file ShopMenu+0x14cc0 | callers(0) | datarefs 1

void MemAlcH::vfunc_0x10(void)

{
  return;
}


// FUNC 0x17014cc4 MemAlcH::vfunc_0x14 (ShopMenu)
//   size 0x4 | file ShopMenu+0x14cc4 | callers(0) | datarefs 1

void MemAlcH::vfunc_0x14(void)

{
  return;
}


// FUNC 0x17014cc8 nn::fs::FileInputStream::vfunc_0x20 (ShopMenu)
//   size 0x8 | file ShopMenu+0x14cc8 | callers(0) | datarefs 1

void nn::fs::FileInputStream::vfunc_0x20(int param_1,longlong *param_2)

{
  detail::FileBase::TryGetSize((FileBase *)(param_1 + 4),param_2);
  return;
}


// FUNC 0x17014cd0 nn::fs::FileInputStream::vfunc_0x14 (ShopMenu)
//   size 0x8 | file ShopMenu+0x14cd0 | callers(0) | datarefs 1

undefined8 nn::fs::FileInputStream::vfunc_0x14(int param_1)

{
  return *(undefined8 *)(param_1 + 8);
}


// FUNC 0x17014cd8 nn::fs::FileInputStream::vfunc_0x10 (ShopMenu)
//   size 0x14 | file ShopMenu+0x14cd8 | callers(0) | datarefs 1

undefined4 nn::fs::FileInputStream::vfunc_0x10(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 0xc);
  *param_2 = *(undefined4 *)(param_1 + 8);
  param_2[1] = uVar1;
  return 0;
}


// FUNC 0x17014cec nn::fs::FileInputStream::vfunc_0x24 (ShopMenu)
//   size 0x2c | file ShopMenu+0x14cec | callers(0) | datarefs 1

longlong nn::fs::FileInputStream::vfunc_0x24(int param_1)

{
  int iVar1;
  longlong local_10;
  
  iVar1 = detail::FileBase::TryGetSize((FileBase *)(param_1 + 4),&local_10);
  if (iVar1 < 0) {
    err::CTR::ThrowFatalErrAll(iVar1,0x17014d08);
  }
  return local_10;
}


// FUNC 0x17014d18 FUN_17014d18 (ShopMenu)
//   size 0x2c | file ShopMenu+0x14d18 | callers(0) | datarefs 1

bool FUN_17014d18(int *param_1,uint param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 8))();
  return (uVar1 & param_3) == param_2;
}


// FUNC 0x17014d44 FUN_17014d44 (ShopMenu)
//   size 0x8 | file ShopMenu+0x14d44 | callers(0) | datarefs 1

undefined4 FUN_17014d44(void)

{
  return 0;
}


// FUNC 0x17014d4c msys::MReelNumMan2::vfunc_0x1c (ShopMenu)
//   size 0x8 | file ShopMenu+0x14d4c | callers(0) | datarefs 1

undefined4 msys::MReelNumMan2::vfunc_0x1c(void)

{
  return 5;
}


// FUNC 0x17014d54 FUN_17014d54 (ShopMenu)
//   size 0x8 | file ShopMenu+0x14d54 | callers(0) | datarefs 3

undefined4 FUN_17014d54(void)

{
  return 2;
}


// FUNC 0x17014d5c shop::ShopMenu_PageBase::Core::vfunc_0xc (ShopMenu)
//   size 0x10 | file ShopMenu+0x14d5c | callers(0) | datarefs 6

bool shop::ShopMenu_PageBase::Core::vfunc_0xc(undefined4 param_1,int param_2)

{
  return *(char *)(param_2 + 0x12) != '\0';
}


// FUNC 0x17014d6c FUN_17014d6c (ShopMenu)
//   size 0x1c | file ShopMenu+0x14d6c | callers(1) 0x17008110

void FUN_17014d6c(uint *param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = param_2 & 0xff | (param_2 & 0xff) << 8;
  uVar1 = uVar1 | uVar1 << 0x10;
  *param_1 = uVar1;
  param_1[1] = uVar1;
  param_1[2] = uVar1;
  return;
}


// FUNC 0x17014d88 ShopMenu::nnroControlObject_ (ShopMenu)
//   size 0x74 | file ShopMenu+0x14d88 | callers(0)

undefined4 ShopMenu::nnroControlObject_(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined *puVar2;
  
  switch(param_2) {
  case 0:
    uVar1 = 0;
    break;
  case 1:
    DAT_17021f8c = param_1;
    return 0;
  case 2:
    uVar1 = DAT_17021f8c;
    break;
  case 3:
    *param_1 = &DAT_170150e8;
    puVar2 = &DAT_170150e8;
    goto LAB_17014de8;
  case 4:
    *param_1 = &DAT_170184c4;
    puVar2 = &DAT_170184c4;
LAB_17014de8:
    param_1[1] = puVar2;
    return 0;
  default:
    return 0xd8e12c21;
  }
  *param_1 = uVar1;
  return 0;
}


// FUNC 0x17014e34 FUN_17014e34 (ShopMenu)
//   size 0xac | file ShopMenu+0x14e34 | callers(0) | datarefs 1

void FUN_17014e34(int param_1)

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


// FUNC 0x17014ee0 ->operator.delete (ShopMenu)
//   size 0x4 | file ShopMenu+0x14ee0 | callers(0) | datarefs 1
// veneer/thunk -> 0x00286514 operator.delete (static)

// FUNC 0x17014ee4 FUN_17014ee4 (ShopMenu)
//   size 0x4 | file ShopMenu+0x14ee4 | callers(0) | datarefs 1

void FUN_17014ee4(void)

{
  return;
}


// FUNC 0x17014ee8 FUN_17014ee8 (ShopMenu)
//   size 0x184 | file ShopMenu+0x14ee8 | callers(1) 0x17009a4c

void FUN_17014ee8(byte *param_1,int *param_2,uint param_3,uint param_4)

{
  uint uVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  bool bVar9;
  bool bVar10;
  
  if (param_3 == 0) {
    param_1[1] = 0;
    *param_1 = 0;
    return;
  }
  piVar5 = param_2 + param_3 * 7;
  piVar7 = param_2;
  if (param_2 < piVar5) {
    uVar4 = (int)piVar5 - (int)param_2;
    iVar8 = (int)((longlong)(int)uVar4 * -0x6db6db6d + ((ulonglong)uVar4 << 0x20) >> 0x20);
    iVar6 = 1;
    if (1 < ((iVar8 >> 4) - (iVar8 >> 0x1f)) + 1) {
      do {
        if (*piVar7 == *(int *)(param_1 + 4)) goto LAB_17014f7c;
        iVar6 = iVar6 + 1;
        piVar7 = piVar7 + 7;
        iVar8 = (int)((longlong)(int)uVar4 * -0x6db6db6d + ((ulonglong)uVar4 << 0x20) >> 0x20);
      } while (iVar6 < ((iVar8 >> 4) - (iVar8 >> 0x1f)) + 1);
    }
  }
  else if (param_2 != piVar5) {
    do {
      if (*piVar7 == *(int *)(param_1 + 4)) goto LAB_17014f7c;
      piVar7 = piVar7 + 7;
    } while (piVar7 != piVar5);
  }
LAB_17015010:
  uVar3 = (uint)*param_1;
  uVar4 = uVar3;
  if (((int)param_3 < (int)(uVar3 + param_4)) && (uVar4 = param_3 - param_4, (int)uVar4 < 0)) {
    uVar4 = 0;
  }
  uVar3 = (param_1[1] - uVar3) + uVar4;
  if ((int)uVar3 < (int)(param_3 - 1)) {
    if ((int)uVar3 <= (int)uVar4) {
      uVar3 = uVar4;
    }
  }
  else {
    uVar3 = param_3 - 1;
  }
  *param_1 = (byte)uVar4;
  param_1[1] = (byte)uVar3;
  *(int *)(param_1 + 4) = param_2[uVar3 * 7];
  return;
LAB_17014f7c:
  iVar8 = (int)((longlong)((int)piVar7 - (int)param_2) * -0x6db6db6d +
                ((ulonglong)(uint)((int)piVar7 - (int)param_2) << 0x20) >> 0x20);
  uVar4 = (iVar8 >> 4) - (iVar8 >> 0x1f);
  if (uVar4 != 0xffffffff) {
    if (param_1[1] != uVar4) {
      param_1[1] = (byte)uVar4;
      uVar3 = (uint)*param_1;
      if ((int)uVar4 < (int)(uint)*param_1) {
        uVar3 = uVar4;
      }
      uVar1 = uVar3 + param_4;
      if ((int)param_3 < (int)(uVar3 + param_4)) {
        uVar1 = param_3;
      }
      if ((int)uVar1 <= (int)uVar4) {
        uVar1 = uVar4 + 1;
        uVar3 = uVar1 - param_4;
      }
      bVar10 = SBORROW4(uVar1,param_4);
      iVar8 = uVar1 - param_4;
      bVar9 = uVar1 == param_4;
      if ((int)uVar1 < (int)param_4) {
        uVar3 = 0;
      }
      else {
        uVar1 = uVar1 - param_4;
        bVar10 = SBORROW4(uVar3,uVar1);
        iVar8 = uVar3 - uVar1;
        bVar9 = uVar3 == uVar1;
      }
      bVar2 = (byte)uVar3;
      if (!bVar9 && iVar8 < 0 == bVar10) {
        bVar2 = (byte)uVar1;
      }
      *param_1 = bVar2;
    }
    return;
  }
  goto LAB_17015010;
}


// FUNC 0x17015070 FUN_17015070 (ShopMenu)
//   size 0x28 | file ShopMenu+0x15070 | callers(0) | datarefs 1

void FUN_17015070(float param_1,MCursorBase *param_2,MLyt *param_3)

{
  MCursorBase *pMVar1;
  int iVar2;
  
  msys::MCursorBase::init(param_2,param_3,param_1);
  iVar2 = 0x14;
  pMVar1 = param_2 + 0x30;
  do {
    iVar2 = iVar2 + -1;
    *(undefined4 *)pMVar1 = 0;
    pMVar1 = pMVar1 + 4;
  } while (iVar2 != 0);
  return;
}


// FUNC 0x17015098 FUN_17015098 (ShopMenu)
//   size 0x10 | file ShopMenu+0x15098 | callers(0) | datarefs 1

void FUN_17015098(MCursorBase *param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)msys::MCursorBase::~MCursorBase(param_1);
  operator_delete(pvVar1);
  return;
}


// FUNC 0x170150a8 ->msys::MCursorBase::~MCursorBase (ShopMenu)
//   size 0x4 | file ShopMenu+0x150a8 | callers(0) | datarefs 1
// veneer/thunk -> 0x00324600 msys::MCursorBase::~MCursorBase (static)

// FUNC 0x170150ac FUN_170150ac (ShopMenu)
//   size 0x28 | file ShopMenu+0x150ac | callers(0) | datarefs 1

void FUN_170150ac(float param_1,MCursorBase *param_2,MLyt *param_3)

{
  MCursorBase *pMVar1;
  int iVar2;
  
  msys::MCursorBase::init(param_2,param_3,param_1);
  iVar2 = 0x2e;
  pMVar1 = param_2 + 0x30;
  do {
    iVar2 = iVar2 + -1;
    *(undefined4 *)pMVar1 = 0;
    pMVar1 = pMVar1 + 4;
  } while (iVar2 != 0);
  return;
}


// FUNC 0x170150d4 FUN_170150d4 (ShopMenu)
//   size 0x10 | file ShopMenu+0x150d4 | callers(0) | datarefs 1

void FUN_170150d4(MCursorBase *param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)msys::MCursorBase::~MCursorBase(param_1);
  operator_delete(pvVar1);
  return;
}


// FUNC 0x170150e4 ->msys::MCursorBase::~MCursorBase (ShopMenu)
//   size 0x4 | file ShopMenu+0x150e4 | callers(0) | datarefs 1
// veneer/thunk -> 0x00324600 msys::MCursorBase::~MCursorBase (static)

