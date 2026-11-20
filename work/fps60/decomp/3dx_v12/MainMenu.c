// fps60 TG decompiled C: 3dx_v12.code.bin module MainMenu part 1 (Ghidra 12.2, ARM:LE:32:v6:hardfp)
// Addresses: static = runtime address; CRO = fixed analysis base (crolink.py), NOT runtime.

// FUNC 0x15000180 ->operator.new (MainMenu)
//   size 0x4 | file MainMenu+0x180 | callers(19) 0x15000c68 0x15022eb0 0x15003e90 0x15007bc0 0x150096f0 0x1500e660 0x1501796c 0x1501ec98 ...
// veneer/thunk -> 0x00287d40 operator.new (static)

// FUNC 0x15000188 ->TaskMan::entry (MainMenu)
//   size 0x4 | file MainMenu+0x188 | callers(1) 0x15000c68
// veneer/thunk -> 0x00287b18 TaskMan::entry (static)

// FUNC 0x15000190 ->MsgDataAcsrBase::~MsgDataAcsrBase (MainMenu)
//   size 0x4 | file MainMenu+0x190 | callers(3) 0x15000cb0 0x15000cc0 0x15015468
// veneer/thunk -> 0x0026fdb4 MsgDataAcsrBase::~MsgDataAcsrBase (static)

// FUNC 0x15000198 ->operator.delete (MainMenu)
//   size 0x4 | file MainMenu+0x198 | callers(61) 0x15000d28 0x15015468 0x15007968 0x15008174 0x15009048 0x150090cc 0x150091d0 0x15009254 ...
// veneer/thunk -> 0x00286514 operator.delete (static)

// FUNC 0x150001a0 ->nn::fs::detail::FileBase::TrySetPosition (MainMenu)
//   size 0x4 | file MainMenu+0x1a0 | callers(2) 0x15000d30 0x15000d54
// veneer/thunk -> 0x0027ec28 nn::fs::detail::FileBase::TrySetPosition (static)

// FUNC 0x150001a8 ->nn::err::CTR::ThrowFatalErrAll (MainMenu)
//   size 0x4 | file MainMenu+0x1a8 | callers(5) 0x15000d5c 0x1502352c 0x15000d30 0x15000d88 0x15022040
// veneer/thunk -> 0x00286530 nn::err::CTR::ThrowFatalErrAll (static)

// FUNC 0x150001b0 ->nn::fs::detail::FileBase::TryRead (MainMenu)
//   size 0x4 | file MainMenu+0x1b0 | callers(3) 0x15000d5c 0x15000db4 0x15022040
// veneer/thunk -> 0x00286488 nn::fs::detail::FileBase::TryRead (static)

// FUNC 0x150001b8 ->nn::fs::detail::FileBase::TrySeek (MainMenu)
//   size 0x4 | file MainMenu+0x1b8 | callers(2) 0x15000d88 0x15000dbc
// veneer/thunk -> 0x002854d0 nn::fs::detail::FileBase::TrySeek (static)

// FUNC 0x150001c0 ->nndbgPanic (MainMenu)
//   size 0x4 | file MainMenu+0x1c0 | callers(3) 0x15000dd4 0x15000e14 0x15022040
// veneer/thunk -> 0x0028642c nndbgPanic (static)

// FUNC 0x150001c8 ->nn::fs::CTR::MPCore::detail::UserFileSystem::CloseFile (MainMenu)
//   size 0x4 | file MainMenu+0x1c8 | callers(3) 0x15000dd4 0x15000e14 0x15022040
// veneer/thunk -> 0x00286410 nn::fs::CTR::MPCore::detail::UserFileSystem::CloseFile (static)

// FUNC 0x150001d0 ->CellAnime::~CellAnime (MainMenu)
//   size 0x4 | file MainMenu+0x1d0 | callers(17) 0x15015468 0x15004bac 0x15004c2c 0x15007968 0x1500a824 0x1500a8d8 0x15012114 0x1500c200 ...
// veneer/thunk -> 0x0024fc94 CellAnime::~CellAnime (static)

// FUNC 0x150001d8 ->ad::ui::UIListWindowPlusLyt::~UIListWindowPlusLyt (MainMenu)
//   size 0x4 | file MainMenu+0x1d8 | callers(28) 0x15000fe0 0x15000ff0 0x15000ff4 0x15001018 0x15001118 0x1500113c 0x1500115c 0x15001180 ...
// veneer/thunk -> 0x0025a3fc ad::ui::UIListWindowPlusLyt::~UIListWindowPlusLyt (static)

// FUNC 0x150001e0 ->msys::MListWndPBase::~MListWndPBase (MainMenu)
//   size 0x4 | file MainMenu+0x1e0 | callers(26) 0x15000ff4 0x15001118 0x1500115c 0x150011a0 0x150011e4 0x15001228 0x15004bac 0x15007968 ...
// veneer/thunk -> 0x003288a0 msys::MListWndPBase::~MListWndPBase (static)

// FUNC 0x150001e8 ->MoveVBase::update (MainMenu)
//   size 0x4 | file MainMenu+0x1e8 | callers(7) 0x15001040 0x1500c0e0 0x1500c440 0x15006d44 0x150062cc 0x1500d000 0x1500c9c8
// veneer/thunk -> 0x002597d4 MoveVBase::update (static)

// FUNC 0x150001f0 ->msys::MRenderQueueBase::enqueueMsg (MainMenu)
//   size 0x4 | file MainMenu+0x1f0 | callers(1) 0x150010a0
// veneer/thunk -> 0x00328df0 msys::MRenderQueueBase::enqueueMsg (static)

// FUNC 0x150001f8 ->MessageSimple::term (MainMenu)
//   size 0x4 | file MainMenu+0x1f8 | callers(17) 0x15007968 0x1500a824 0x1500a8d8 0x1500c200 0x1500c2b4 0x1500c488 0x1500c520 0x1500e2ec ...
// veneer/thunk -> 0x00137090 MessageSimple::term (static)

// FUNC 0x15000200 ->MessageSimple::~MessageSimple (MainMenu)
//   size 0x4 | file MainMenu+0x200 | callers(17) 0x15007968 0x1500a824 0x1500a8d8 0x1500c200 0x1500c2b4 0x1500c488 0x1500c520 0x1500e2ec ...
// veneer/thunk -> 0x00256578 MessageSimple::~MessageSimple (static)

// FUNC 0x15000208 ->msys::MPageBase::enqueueLowerChr (MainMenu)
//   size 0x4 | file MainMenu+0x208 | callers(1) 0x1500126c
// veneer/thunk -> 0x00334104 msys::MPageBase::enqueueLowerChr (static)

// FUNC 0x15000210 ->msys::MPageBase::enqueueUpperChr (MainMenu)
//   size 0x4 | file MainMenu+0x210 | callers(1) 0x15001274
// veneer/thunk -> 0x00334184 msys::MPageBase::enqueueUpperChr (static)

// FUNC 0x15000218 ->__aeabi_vec_dtor (MainMenu)
//   size 0x4 | file MainMenu+0x218 | callers(23) 0x15015898 0x1500127c 0x150012b8 0x15015468 0x150152a0 0x15003d48 0x15007968 0x15009048 ...
// veneer/thunk -> 0x00288230 __aeabi_vec_dtor (static)

// FUNC 0x15000220 ->MoveVBase::~MoveVBase (MainMenu)
//   size 0x4 | file MainMenu+0x220 | callers(11) 0x15015898 0x1500127c 0x15007968 0x1500a824 0x1500a8d8 0x1500c200 0x1500c2b4 0x1500c488 ...
// veneer/thunk -> 0x002535e8 MoveVBase::~MoveVBase (static)

// FUNC 0x15000228 ->MoveWorkF::MoveWorkF (MainMenu)
//   size 0x4 | file MainMenu+0x228 | callers(1) 0x150012f0
// veneer/thunk -> 0x00278cc0 MoveWorkF::MoveWorkF (static)

// FUNC 0x15000230 ->MoveWorkF::~MoveWorkF (MainMenu)
//   size 0x4 | file MainMenu+0x230 | callers(2) 0x15001324 0x15001334
// veneer/thunk -> 0x00340694 MoveWorkF::~MoveWorkF (static)

// FUNC 0x15000238 ->GameMain::Back (MainMenu)
//   size 0x4 | file MainMenu+0x238 | callers(1) 0x15001338
// veneer/thunk -> 0x0033e354 GameMain::Back (static)

// FUNC 0x15000240 ->msys::MTaskBase::MTaskBase (MainMenu)
//   size 0x4 | file MainMenu+0x240 | callers(1) 0x15001354
// veneer/thunk -> 0x00334688 msys::MTaskBase::MTaskBase (static)

// FUNC 0x15000248 ->ad::fw::TaskBase::~TaskBase (MainMenu)
//   size 0x4 | file MainMenu+0x248 | callers(2) 0x15001390 0x150013b8
// veneer/thunk -> 0x0026d590 ad::fw::TaskBase::~TaskBase (static)

// FUNC 0x15000250 ->msys::MPageBase::updateInputAllChr (MainMenu)
//   size 0x4 | file MainMenu+0x250 | callers(6) 0x150013f0 0x1500664c 0x1500d7a8 0x15016c60 0x1501cbb0 0x15020014
// veneer/thunk -> 0x00334204 msys::MPageBase::updateInputAllChr (static)

// FUNC 0x15000258 ->ad::ctrl::ButtonGroup::Update (MainMenu)
//   size 0x4 | file MainMenu+0x258 | callers(6) 0x150013f0 0x1500664c 0x1500d7a8 0x15016c60 0x1501cbb0 0x15020014
// veneer/thunk -> 0x00250a40 ad::ctrl::ButtonGroup::Update (static)

// FUNC 0x15000260 ->VramAlcRange::merge (MainMenu)
//   size 0x4 | file MainMenu+0x260 | callers(1) 0x15001578
// veneer/thunk -> 0x00102874 VramAlcRange::merge (static)

// FUNC 0x15000268 ->msys::MLyt::getParts (MainMenu)
//   size 0x4 | file MainMenu+0x268 | callers(26) 0x1501b504 0x1500fc98 0x1501ece8 0x1500f5d8 0x1500fb18 0x1501f198 0x15020394 0x15021310 ...
// veneer/thunk -> 0x002073ec msys::MLyt::getParts (static)

// FUNC 0x15000270 ->ad::lyt::LytAnim::init (MainMenu)
//   size 0x4 | file MainMenu+0x270 | callers(56) 0x15007fec 0x15008074 0x1500a994 0x1500c378 0x1500db40 0x15017348 0x1500fc98 0x1501ece8 ...
// veneer/thunk -> 0x00264f04 ad::lyt::LytAnim::init (static)

// FUNC 0x15000278 ->ad::lyt::LytAnim::playAuto (MainMenu)
//   size 0x4 | file MainMenu+0x278 | callers(16) 0x1501b504 0x15008074 0x15001d68 0x15001f6c 0x15014940 0x15001660 0x1500479c 0x1500b494 ...
// veneer/thunk -> 0x0025620c ad::lyt::LytAnim::playAuto (static)

// FUNC 0x15000280 ->ad::lyt::AnimTransform::GetFrameSize (MainMenu)
//   size 0x4 | file MainMenu+0x280 | callers(15) 0x15023600 0x15014da0 0x15014940 0x15013bb0 0x1500db40 0x1501f9ac 0x15022040 0x150016f0 ...
// veneer/thunk -> 0x0026fe38 ad::lyt::AnimTransform::GetFrameSize (static)

// FUNC 0x15000288 ->ad::lyt::LytAnim::stopAndSetFrm (MainMenu)
//   size 0x4 | file MainMenu+0x288 | callers(60) 0x15012444 0x1501b504 0x15007fec 0x15014da0 0x1500a994 0x1500c378 0x1500db40 0x15017348 ...
// veneer/thunk -> 0x0026fe44 ad::lyt::LytAnim::stopAndSetFrm (static)

// FUNC 0x15000290 ->ad::lyt::LytAnim::term (MainMenu)
//   size 0x4 | file MainMenu+0x290 | callers(41) 0x15003d48 0x15007fec 0x15008074 0x1500db40 0x15017348 0x1500fc98 0x1501ece8 0x1500f5d8 ...
// veneer/thunk -> 0x00264e90 ad::lyt::LytAnim::term (static)

// FUNC 0x15000298 ->GetRegFlag (MainMenu)
//   size 0x4 | file MainMenu+0x298 | callers(20) 0x1500359c 0x15014940 0x150043e4 0x1500f5d8 0x15010ac4 0x1501c07c 0x15011800 0x15020be8 ...
// veneer/thunk -> 0x002762cc GetRegFlag (static)

// FUNC 0x150002a0 ->ad::lyt::LytResourceMan::init (MainMenu)
//   size 0x4 | file MainMenu+0x2a0 | callers(10) 0x15014438 0x15003edc 0x15007c10 0x1500e6b0 0x1501ece8 0x15020be8 0x15022040 0x15001b2c ...
// veneer/thunk -> 0x00250d1c ad::lyt::LytResourceMan::init (static)

// FUNC 0x150002a8 ->ad::fw::Resource::getFileData (MainMenu)
//   size 0x4 | file MainMenu+0x2a8 | callers(9) 0x15003edc 0x15007c10 0x1500e6b0 0x1501ece8 0x15020be8 0x15022040 0x15001b34 0x150097f0 ...
// veneer/thunk -> 0x00251d10 ad::fw::Resource::getFileData (static)

// FUNC 0x150002b0 ->ad::lyt::LytResourceMan::registerArc (MainMenu)
//   size 0x4 | file MainMenu+0x2b0 | callers(9) 0x15003edc 0x15007c10 0x1500e6b0 0x1501ece8 0x15020be8 0x15022040 0x15001b44 0x15009800 ...
// veneer/thunk -> 0x0015c910 ad::lyt::LytResourceMan::registerArc (static)

// FUNC 0x150002b8 ->msys::MLyt::build (MainMenu)
//   size 0x4 | file MainMenu+0x2b8 | callers(10) 0x15003edc 0x1500e6b0 0x1501ece8 0x15020be8 0x15001b5c 0x15001bd8 0x15009818 0x15009894 ...
// veneer/thunk -> 0x0032c460 msys::MLyt::build (static)

// FUNC 0x150002c0 ->msys::MLyt::init (MainMenu)
//   size 0x4 | file MainMenu+0x2c0 | callers(12) 0x15003edc 0x15007c10 0x1500e6b0 0x1501ece8 0x15020be8 0x15022040 0x15001b70 0x15001be8 ...
// veneer/thunk -> 0x0032c3a0 msys::MLyt::init (static)

// FUNC 0x150002c8 ->msys::MLyt::createLyt (MainMenu)
//   size 0x4 | file MainMenu+0x2c8 | callers(7) 0x15003edc 0x15007c10 0x1501ece8 0x15022040 0x15001b80 0x1500983c 0x15017fdc
// veneer/thunk -> 0x0032c78c msys::MLyt::createLyt (static)

// FUNC 0x150002d0 ->MoveVBase::stop (MainMenu)
//   size 0x4 | file MainMenu+0x2d0 | callers(49) 0x15014558 0x150142ec 0x1500bef8 0x1500c0e0 0x15014e10 0x150131d0 0x15014cc4 0x15002fd4 ...
// veneer/thunk -> 0x00259dd8 MoveVBase::stop (static)

// FUNC 0x150002d8 ->msys::MLyt::createLyt (MainMenu)
//   size 0x4 | file MainMenu+0x2d8 | callers(7) 0x15003edc 0x1500e6b0 0x1501ece8 0x15020be8 0x15001c08 0x150098c8 0x15018064
// veneer/thunk -> 0x0032c8c0 msys::MLyt::createLyt (static)

// FUNC 0x150002e0 ->msys::MDfxChr::init (MainMenu)
//   size 0x4 | file MainMenu+0x2e0 | callers(12) 0x1500bef8 0x15003edc 0x15022040 0x15001ca8 0x15018218 0x15018270 0x15018950 0x15018a1c ...
// veneer/thunk -> 0x003309c0 msys::MDfxChr::init (static)

// FUNC 0x150002e8 ->nngxWaitCmdlistDone (MainMenu)
//   size 0x4 | file MainMenu+0x2e8 | callers(1) 0x15001d68
// veneer/thunk -> 0x002879f0 nngxWaitCmdlistDone (static)

// FUNC 0x150002f0 ->nn::applet::CTR::JumpToManual (MainMenu)
//   size 0x4 | file MainMenu+0x2f0 | callers(1) 0x15001d68
// veneer/thunk -> 0x001a6df8 nn::applet::CTR::JumpToManual (static)

// FUNC 0x150002f8 ->nn::applet::CTR::detail::WaitForStarting (MainMenu)
//   size 0x4 | file MainMenu+0x2f8 | callers(1) 0x15001d68
// veneer/thunk -> 0x00281f30 nn::applet::CTR::detail::WaitForStarting (static)

// FUNC 0x15000300 ->nn::applet::CTR::detail::GetOrderToCloseState (MainMenu)
//   size 0x4 | file MainMenu+0x300 | callers(1) 0x15001d68
// veneer/thunk -> 0x002839e0 nn::applet::CTR::detail::GetOrderToCloseState (static)

// FUNC 0x15000308 ->msys::MCursorBase::setVisible (MainMenu)
//   size 0x4 | file MainMenu+0x308 | callers(26) 0x15002d7c 0x1500bbb8 0x1501629c 0x1501b504 0x1502166c 0x15001d68 0x1500a994 0x1500f0c4 ...
// veneer/thunk -> 0x00324454 msys::MCursorBase::setVisible (static)

// FUNC 0x15000310 ->nn::applet::CTR::IsReceivedWakeupByCancel (MainMenu)
//   size 0x4 | file MainMenu+0x310 | callers(1) 0x15001d68
// veneer/thunk -> 0x002839d0 nn::applet::CTR::IsReceivedWakeupByCancel (static)

// FUNC 0x15000318 ->nn::applet::CTR::detail::CloseApplication (MainMenu)
//   size 0x4 | file MainMenu+0x318 | callers(1) 0x15001d68
// veneer/thunk -> 0x0010ed40 nn::applet::CTR::detail::CloseApplication (static)

// FUNC 0x15000320 ->main_menu::GetBootInfo (MainMenu)
//   size 0x4 | file MainMenu+0x320 | callers(21) 0x15022eb0 0x1501b504 0x1501e89c 0x15001f6c 0x15008af0 0x1501664c 0x1501aac0 0x15010ac4 ...
// veneer/thunk -> 0x002152f0 main_menu::GetBootInfo (static)

// FUNC 0x15000328 ->msys::MComSys::setEvArg (MainMenu)
//   size 0x4 | file MainMenu+0x328 | callers(2) 0x15001f6c 0x1500387c
// veneer/thunk -> 0x0032f53c msys::MComSys::setEvArg (static)

// FUNC 0x15000330 ->msys::MLyt::isBusyAnime (MainMenu)
//   size 0x4 | file MainMenu+0x330 | callers(34) 0x150022a0 0x1501c07c 0x1501f800 0x1501f91c 0x1500387c 0x15005848 0x150062cc 0x1500c5b4 ...
// veneer/thunk -> 0x0032bb14 msys::MLyt::isBusyAnime (static)

// FUNC 0x15000338 ->ad::lyt::LytLocalize::LytLocalize (MainMenu)
//   size 0x4 | file MainMenu+0x338 | callers(10) 0x1501ece8 0x1501aac0 0x15021310 0x15007c10 0x1500b494 0x1500b988 0x1501f9ac 0x15004e44 ...
// veneer/thunk -> 0x002563d4 ad::lyt::LytLocalize::LytLocalize (static)

// FUNC 0x15000340 ->ad::lyt::LytLocalize::localize (MainMenu)
//   size 0x4 | file MainMenu+0x340 | callers(12) 0x1501ece8 0x1501aac0 0x15021310 0x15007c10 0x1500b494 0x1500b988 0x1501f9ac 0x15004e50 ...
// veneer/thunk -> 0x00264e08 ad::lyt::LytLocalize::localize (static)

// FUNC 0x15000348 ->ad::ctrl::ButtonGroup::FindButtonByName (MainMenu)
//   size 0x4 | file MainMenu+0x348 | callers(17) 0x1501ece8 0x1501aac0 0x15021310 0x1500e6b0 0x15004eb4 0x15004f80 0x1500503c 0x15009d18 ...
// veneer/thunk -> 0x00256680 ad::ctrl::ButtonGroup::FindButtonByName (static)

// FUNC 0x15000350 ->ad::ctrl::AnimButton::SetStateChangeCallback (MainMenu)
//   size 0x4 | file MainMenu+0x350 | callers(17) 0x1501ece8 0x1501aac0 0x15021310 0x1500e6b0 0x15004ec4 0x15004f98 0x15005054 0x15009d28 ...
// veneer/thunk -> 0x00256674 ad::ctrl::AnimButton::SetStateChangeCallback (static)

// FUNC 0x15000358 ->ad::fw::TaskBase::isFps30 (MainMenu)
//   size 0x4 | file MainMenu+0x358 | callers(19) 0x15014940 0x15006d44 0x1501ece8 0x1501d920 0x15021310 0x1500e6b0 0x15021dac 0x150147a8 ...
// veneer/thunk -> 0x0025edd0 ad::fw::TaskBase::isFps30 (static)

// FUNC 0x15000360 ->msys::MCursorBase::init (MainMenu)
//   size 0x4 | file MainMenu+0x360 | callers(10) 0x15023914 0x15023950 0x1502398c 0x1501ece8 0x15021310 0x1500e6b0 0x15004f48 0x15009da4 ...
// veneer/thunk -> 0x00324464 msys::MCursorBase::init (static)

// FUNC 0x15000368 ->msys::StatusPanel::init (MainMenu)
//   size 0x4 | file MainMenu+0x368 | callers(5) 0x15005198 0x15005324 0x1500a2f0 0x1500a394 0x150025f0
// veneer/thunk -> 0x00325390 msys::StatusPanel::init (static)

// FUNC 0x15000370 ->msys::StatusPanel::setChr (MainMenu)
//   size 0x4 | file MainMenu+0x370 | callers(6) 0x15012af4 0x150051a4 0x15005330 0x1500a2fc 0x1500a3a0 0x150025fc
// veneer/thunk -> 0x003259c0 msys::StatusPanel::setChr (static)

// FUNC 0x15000378 ->msys::StatusPanel::setType (MainMenu)
//   size 0x4 | file MainMenu+0x378 | callers(6) 0x15006d44 0x150051b0 0x1500533c 0x1500a308 0x1500a3ac 0x15002608
// veneer/thunk -> 0x00325b60 msys::StatusPanel::setType (static)

// FUNC 0x15000380 ->msys::StatusPanel::setParam (MainMenu)
//   size 0x4 | file MainMenu+0x380 | callers(9) 0x15012af4 0x15005730 0x15011f6c 0x150051dc 0x15005364 0x1500a328 0x1500a3c8 0x15002630 ...
// veneer/thunk -> 0x00325ce0 msys::StatusPanel::setParam (static)

// FUNC 0x15000388 ->ad::lyt::LytNumReel3::InitParam::InitParam (MainMenu)
//   size 0x4 | file MainMenu+0x388 | callers(9) 0x1500a5c0 0x1500db40 0x1501f198 0x15020394 0x1500674c 0x15015ae0 0x15018620 0x15018fc8 ...
// veneer/thunk -> 0x00256194 ad::lyt::LytNumReel3::InitParam::InitParam (static)

// FUNC 0x15000390 ->msys::MLytNumRes::set (MainMenu)
//   size 0x4 | file MainMenu+0x390 | callers(9) 0x1500a5c0 0x1500db40 0x1501f198 0x15020394 0x1500674c 0x15015ae0 0x1501864c 0x15018fe4 ...
// veneer/thunk -> 0x00207594 msys::MLytNumRes::set (static)

// FUNC 0x15000398 ->GameWork::getCoin (MainMenu)
//   size 0x4 | file MainMenu+0x398 | callers(1) 0x15002678
// veneer/thunk -> 0x00363120 GameWork::getCoin (static)

// FUNC 0x150003a0 ->msys::MLytNum::init (MainMenu)
//   size 0x4 | file MainMenu+0x3a0 | callers(9) 0x1500a5c0 0x1500db40 0x1501f198 0x15020394 0x1500674c 0x15015ae0 0x15018708 0x15019400 ...
// veneer/thunk -> 0x003316b8 msys::MLytNum::init (static)

// FUNC 0x150003a8 ->msys::MLyt::getPane (MainMenu)
//   size 0x4 | file MainMenu+0x3a8 | callers(16) 0x1500a5c0 0x1500bef8 0x1500db40 0x1500f458 0x1500f5d8 0x15011be4 0x1500674c 0x1500e6b0 ...
// veneer/thunk -> 0x0032c688 msys::MLyt::getPane (static)

// FUNC 0x150003b0 ->ad::db::GetBadgeEffect (MainMenu)
//   size 0x4 | file MainMenu+0x3b0 | callers(1) 0x15002810
// veneer/thunk -> 0x00237518 ad::db::GetBadgeEffect (static)

// FUNC 0x150003b8 ->msys::MLyt::playAnimeFromNo (MainMenu)
//   size 0x4 | file MainMenu+0x3b8 | callers(33) 0x15002d7c 0x15005590 0x1500bbb8 0x1501629c 0x1501b504 0x1502166c 0x15006d44 0x1500a994 ...
// veneer/thunk -> 0x0032bf98 msys::MLyt::playAnimeFromNo (static)

// FUNC 0x150003c0 ->msys::MLyt::stopAnimeAndSetEnd (MainMenu)
//   size 0x4 | file MainMenu+0x3c0 | callers(5) 0x1501aac0 0x1500b988 0x1500e6b0 0x150029b4 0x150029cc
// veneer/thunk -> 0x0032c27c msys::MLyt::stopAnimeAndSetEnd (static)

// FUNC 0x150003c8 ->ad::dfx::Unit::killForce (MainMenu)
//   size 0x4 | file MainMenu+0x3c8 | callers(2) 0x15002d7c 0x15003a94
// veneer/thunk -> 0x0026e088 ad::dfx::Unit::killForce (static)

// FUNC 0x150003d0 ->msys::MComSys::getNextPage (MainMenu)
//   size 0x4 | file MainMenu+0x3d0 | callers(6) 0x15008180 0x1501f91c 0x15002f40 0x150056ac 0x1500be88 0x15016404
// veneer/thunk -> 0x0032db64 msys::MComSys::getNextPage (static)

// FUNC 0x150003d8 ->CellAnime::play (MainMenu)
//   size 0x4 | file MainMenu+0x3d8 | callers(29) 0x15002d7c 0x1500a790 0x15012af4 0x1500c19c 0x150148b0 0x1500590c 0x15006d44 0x1500fc98 ...
// veneer/thunk -> 0x0027bee0 CellAnime::play (static)

// FUNC 0x150003e0 ->msys::MDfxChr::playDfx (MainMenu)
//   size 0x4 | file MainMenu+0x3e0 | callers(13) 0x1500c0e0 0x15014cc4 0x15013088 0x15022040 0x1500387c 0x1501c24c 0x1501c528 0x1501c71c ...
// veneer/thunk -> 0x00330d64 msys::MDfxChr::playDfx (static)

// FUNC 0x150003e8 ->ad::fw::TaskBase::readLyt (MainMenu)
//   size 0x4 | file MainMenu+0x3e8 | callers(10) 0x15003510 0x15006a60 0x15009374 0x1500d8bc 0x15016f28 0x1501dd60 0x15020358 0x1502178c ...
// veneer/thunk -> 0x00249e48 ad::fw::TaskBase::readLyt (static)

// FUNC 0x150003f0 ->msys::MCursorBase::MCursorBase (MainMenu)
//   size 0x4 | file MainMenu+0x3f0 | callers(7) 0x15003c14 0x150076c0 0x1500df8c 0x150176ac 0x1501e420 0x150207d8 0x15021ccc
// veneer/thunk -> 0x00324550 msys::MCursorBase::MCursorBase (static)

// FUNC 0x150003f8 ->__aeabi_vec_ctor_nocookie_nodtor (MainMenu)
//   size 0x4 | file MainMenu+0x3f8 | callers(8) 0x150231f4 0x150153d8 0x150159f4 0x15003c14 0x150076c0 0x1500df8c 0x1501e420 0x150207d8
// veneer/thunk -> 0x0028771c __aeabi_vec_ctor_nocookie_nodtor (static)

// FUNC 0x15000400 ->msys::MLytNum::MLytNum (MainMenu)
//   size 0x4 | file MainMenu+0x400 | callers(4) 0x15003c14 0x150076c0 0x1500df8c 0x150176ac
// veneer/thunk -> 0x003317a4 msys::MLytNum::MLytNum (static)

// FUNC 0x15000408 ->msys::MCursorBase::term (MainMenu)
//   size 0x4 | file MainMenu+0x408 | callers(8) 0x15003d48 0x15007968 0x1500e2ec 0x1501783c 0x1501e89c 0x150209d0 0x15021b60 0x15021c18
// veneer/thunk -> 0x003244f0 msys::MCursorBase::term (static)

// FUNC 0x15000410 ->msys::MLytNum::~MLytNum (MainMenu)
//   size 0x4 | file MainMenu+0x410 | callers(6) 0x15003d48 0x15007968 0x1500a824 0x1500a8d8 0x1500e2ec 0x1501783c
// veneer/thunk -> 0x00331840 msys::MLytNum::~MLytNum (static)

// FUNC 0x15000418 ->msys::MCursorBase::~MCursorBase (MainMenu)
//   size 0x4 | file MainMenu+0x418 | callers(14) 0x15003d48 0x15007968 0x1500e2ec 0x1501783c 0x1501e89c 0x150209d0 0x15021b60 0x15021c18 ...
// veneer/thunk -> 0x00324600 msys::MCursorBase::~MCursorBase (static)

// FUNC 0x15000420 ->msys::MCellAnime::init (MainMenu)
//   size 0x4 | file MainMenu+0x420 | callers(12) 0x1500a5c0 0x1500bef8 0x1500c408 0x1500fc98 0x1501ece8 0x15003edc 0x1500674c 0x15022040 ...
// veneer/thunk -> 0x002079d8 msys::MCellAnime::init (static)

// FUNC 0x15000428 ->msys::MLyt::attachMChr (MainMenu)
//   size 0x4 | file MainMenu+0x428 | callers(23) 0x1500a5c0 0x1500bef8 0x1501ece8 0x1501f198 0x15020394 0x15003edc 0x1500674c 0x1500e6b0 ...
// veneer/thunk -> 0x00207468 msys::MLyt::attachMChr (static)

// FUNC 0x15000430 ->msys::MChrBaseCore::setParent (MainMenu)
//   size 0x4 | file MainMenu+0x430 | callers(1) 0x15003edc
// veneer/thunk -> 0x003261b0 msys::MChrBaseCore::setParent (static)

// FUNC 0x15000438 ->MessageSimple::init (MainMenu)
//   size 0x4 | file MainMenu+0x438 | callers(12) 0x1500a5c0 0x1500bef8 0x1500db40 0x1501ece8 0x15020394 0x15003edc 0x1500674c 0x1500e6b0 ...
// veneer/thunk -> 0x002736b4 MessageSimple::init (static)

// FUNC 0x15000440 ->MessageWriter::setFontColor (MainMenu)
//   size 0x4 | file MainMenu+0x440 | callers(12) 0x1500a5c0 0x1500bef8 0x1500db40 0x1501ece8 0x15020394 0x15003edc 0x1500674c 0x1500e6b0 ...
// veneer/thunk -> 0x00270f0c MessageWriter::setFontColor (static)

// FUNC 0x15000448 ->msys::MLyt::getMPaneRef (MainMenu)
//   size 0x4 | file MainMenu+0x448 | callers(4) 0x1500db40 0x15003edc 0x15022040 0x15019c30
// veneer/thunk -> 0x0032ba20 msys::MLyt::getMPaneRef (static)

// FUNC 0x15000450 ->msys::MChrBaseCore::setParent (MainMenu)
//   size 0x4 | file MainMenu+0x450 | callers(4) 0x1500db40 0x15003edc 0x15019358 0x15019c74
// veneer/thunk -> 0x003261c0 msys::MChrBaseCore::setParent (static)

// FUNC 0x15000458 ->msys::MListWndPBase::getListWnd (MainMenu)
//   size 0x4 | file MainMenu+0x458 | callers(30) 0x15005590 0x1500a5c0 0x150124a8 0x1500bef8 0x15016c60 0x15004cbc 0x150138ec 0x15013bb0 ...
// veneer/thunk -> 0x003620c0 msys::MListWndPBase::getListWnd (static)

// FUNC 0x15000460 ->ad::db::GetUseItemIdList (MainMenu)
//   size 0x4 | file MainMenu+0x460 | callers(1) 0x150043e4
// veneer/thunk -> 0x0013a4a4 ad::db::GetUseItemIdList (static)

// FUNC 0x15000468 ->GameWork::getItemNum (MainMenu)
//   size 0x4 | file MainMenu+0x468 | callers(2) 0x1500ae40 0x150043e4
// veneer/thunk -> 0x003630e0 GameWork::getItemNum (static)

// FUNC 0x15000470 ->ad::db::GetUseItem (MainMenu)
//   size 0x4 | file MainMenu+0x470 | callers(5) 0x150138ec 0x150043e4 0x1500590c 0x15006d44 0x150063b0
// veneer/thunk -> 0x00236398 ad::db::GetUseItem (static)

// FUNC 0x15000478 ->ad::db::GetItemMsgAcs (MainMenu)
//   size 0x4 | file MainMenu+0x478 | callers(4) 0x1500ae40 0x150043e4 0x1500590c 0x15010b9c
// veneer/thunk -> 0x0013a30c ad::db::GetItemMsgAcs (static)

// FUNC 0x15000480 ->LMS_GetTextIndexByLabel (MainMenu)
//   size 0x4 | file MainMenu+0x480 | callers(17) 0x15014558 0x15012af4 0x1500ae40 0x15013ad0 0x150043e4 0x1500590c 0x15017348 0x15011d88 ...
// veneer/thunk -> 0x0027616c LMS_GetTextIndexByLabel (static)

// FUNC 0x15000488 ->LMS_GetText (MainMenu)
//   size 0x4 | file MainMenu+0x488 | callers(17) 0x15014558 0x15012af4 0x1500ae40 0x15013ad0 0x150043e4 0x1500590c 0x15017348 0x15011d88 ...
// veneer/thunk -> 0x0027660c LMS_GetText (static)

// FUNC 0x15000490 ->__2sprintf (MainMenu)
//   size 0x4 | file MainMenu+0x490 | callers(2) 0x15013ad0 0x150043e4
// veneer/thunk -> 0x0010098c __2sprintf (static)

// FUNC 0x15000498 ->Mem::Fill (MainMenu)
//   size 0x4 | file MainMenu+0x498 | callers(13) 0x15022eb0 0x150076c0 0x150176ac 0x1501e420 0x15017348 0x15011d88 0x15011e78 0x15010b9c ...
// veneer/thunk -> 0x002849e8 Mem::Fill (static)

// FUNC 0x150004a0 ->ad::lyt::LytResourceMan::buildLayout (MainMenu)
//   size 0x4 | file MainMenu+0x4a0 | callers(6) 0x1500479c 0x1500b494 0x15015ef8 0x1501f9ac 0x1501a164 0x1501bad0
// veneer/thunk -> 0x00256490 ad::lyt::LytResourceMan::buildLayout (static)

// FUNC 0x150004a8 ->ad::fw::Resource::getCA_anm (MainMenu)
//   size 0x4 | file MainMenu+0x4a8 | callers(3) 0x1500479c 0x1500b494 0x1501bad0
// veneer/thunk -> 0x0025abfc ad::fw::Resource::getCA_anm (static)

// FUNC 0x150004b0 ->ad::fw::Resource::getCA_tex (MainMenu)
//   size 0x4 | file MainMenu+0x4b0 | callers(3) 0x1500479c 0x1500b494 0x1501bad0
// veneer/thunk -> 0x0025ac08 ad::fw::Resource::getCA_tex (static)

// FUNC 0x150004b8 ->ad::fw::Resource::getCA_canm (MainMenu)
//   size 0x4 | file MainMenu+0x4b8 | callers(3) 0x1500479c 0x1500b494 0x1501bad0
// veneer/thunk -> 0x0025ac14 ad::fw::Resource::getCA_canm (static)

// FUNC 0x150004c0 ->CellAnime::init (MainMenu)
//   size 0x4 | file MainMenu+0x4c0 | callers(3) 0x1500479c 0x1500b494 0x1501bad0
// veneer/thunk -> 0x0027fa28 CellAnime::init (static)

// FUNC 0x150004c8 ->ad::ui::UIListWindowPlusLyt::InitParam::InitParam (MainMenu)
//   size 0x4 | file MainMenu+0x4c8 | callers(6) 0x1500479c 0x1500b494 0x15015ef8 0x1501f9ac 0x1501a164 0x1501bad0
// veneer/thunk -> 0x00146398 ad::ui::UIListWindowPlusLyt::InitParam::InitParam (static)

// FUNC 0x150004d0 ->msys::SetMListWndInitParam (MainMenu)
//   size 0x4 | file MainMenu+0x4d0 | callers(6) 0x1500479c 0x1500b494 0x15015ef8 0x1501f9ac 0x1501a164 0x1501bad0
// veneer/thunk -> 0x00329e60 msys::SetMListWndInitParam (static)

// FUNC 0x150004d8 ->msys::MListWndPBase::init (MainMenu)
//   size 0x4 | file MainMenu+0x4d8 | callers(6) 0x1500479c 0x1500b494 0x15015ef8 0x1501f9ac 0x1501a164 0x1501bad0
// veneer/thunk -> 0x00328698 msys::MListWndPBase::init (static)

// FUNC 0x150004e0 ->ad::lyt::Layout::~Layout (MainMenu)
//   size 0x4 | file MainMenu+0x4e0 | callers(14) 0x15004bac 0x15004c2c 0x15007968 0x15012114 0x150107e0 0x15016110 0x1501618c 0x1501783c ...
// veneer/thunk -> 0x00262eec ad::lyt::Layout::~Layout (static)

// FUNC 0x150004e8 ->ad::ui::UIListWindowPlusLyt::getCurItem (MainMenu)
//   size 0x4 | file MainMenu+0x4e8 | callers(8) 0x15004cbc 0x150138ec 0x1500590c 0x15016ff0 0x1500e6b0 0x15006188 0x1500d000 0x1500c9c8
// veneer/thunk -> 0x0025a0c4 ad::ui::UIListWindowPlusLyt::getCurItem (static)

// FUNC 0x150004f0 ->msys::MLyt::setAnimeInfo (MainMenu)
//   size 0x4 | file MainMenu+0x4f0 | callers(7) 0x1501f830 0x150053b0 0x150053c0 0x150053d0 0x150053e0 0x150053f0 0x15005400
// veneer/thunk -> 0x0032bc40 msys::MLyt::setAnimeInfo (static)

// FUNC 0x150004f8 ->msys::MLyt::stopAnimeAndSetSt (MainMenu)
//   size 0x4 | file MainMenu+0x4f8 | callers(5) 0x1501aac0 0x1500b988 0x15005418 0x15005448 0x15016510
// veneer/thunk -> 0x0032c1e4 msys::MLyt::stopAnimeAndSetSt (static)

// FUNC 0x15000500 ->msys::MListWndPBase::setEnableInput (MainMenu)
//   size 0x4 | file MainMenu+0x500 | callers(17) 0x15006d44 0x1501c07c 0x1501dfd0 0x1500fc2c 0x1501a650 0x1500d5fc 0x1500d700 0x15016204 ...
// veneer/thunk -> 0x00328638 msys::MListWndPBase::setEnableInput (static)

// FUNC 0x15000508 ->ad::db::GetItemMsgCore (MainMenu)
//   size 0x4 | file MainMenu+0x508 | callers(3) 0x1500590c 0x1500f458 0x1500f5d8
// veneer/thunk -> 0x0013a324 ad::db::GetItemMsgCore (static)

// FUNC 0x15000510 ->msys::MMsg::playStr (MainMenu)
//   size 0x4 | file MainMenu+0x510 | callers(20) 0x1500a790 0x15012af4 0x1500c19c 0x15013ad0 0x1500590c 0x15006d44 0x15012a2c 0x1500f458 ...
// veneer/thunk -> 0x0032ce0c msys::MMsg::playStr (static)

// FUNC 0x15000518 ->ad::lyt::LytNumReel3::setValueInstant (MainMenu)
//   size 0x4 | file MainMenu+0x518 | callers(9) 0x1500a790 0x1500590c 0x15006d44 0x15012a2c 0x1500fc98 0x1500f458 0x15011be4 0x15015c5c ...
// veneer/thunk -> 0x0020785c ad::lyt::LytNumReel3::setValueInstant (static)

// FUNC 0x15000520 ->Frm::play (MainMenu)
//   size 0x4 | file MainMenu+0x520 | callers(8) 0x150148b0 0x1500590c 0x15006d44 0x1501cf00 0x1501153c 0x1501a400 0x15008c24 0x15008d2c
// veneer/thunk -> 0x0027a324 Frm::play (static)

// FUNC 0x15000528 ->Frm::update (MainMenu)
//   size 0x4 | file MainMenu+0x528 | callers(6) 0x150147a8 0x150062cc 0x15006534 0x1501153c 0x15008c24 0x15008d2c
// veneer/thunk -> 0x0026aed4 Frm::update (static)

// FUNC 0x15000530 ->MoveVBase::isBusy (MainMenu)
//   size 0x4 | file MainMenu+0x530 | callers(3) 0x1500c0e0 0x150062cc 0x1500c9c8
// veneer/thunk -> 0x0025d230 MoveVBase::isBusy (static)

// FUNC 0x15000538 ->msys::MListWndPBase::getCurItem (MainMenu)
//   size 0x4 | file MainMenu+0x538 | callers(13) 0x15012af4 0x150138ec 0x1501c07c 0x1501d920 0x1501a650 0x15016ac8 0x1501ccd8 0x150063b0 ...
// veneer/thunk -> 0x0025a0bc msys::MListWndPBase::getCurItem (static)

// FUNC 0x15000540 ->msys::MDfxChr::term (MainMenu)
//   size 0x4 | file MainMenu+0x540 | callers(4) 0x1501b504 0x15006534 0x1501cf00 0x1501d53c
// veneer/thunk -> 0x00330c68 msys::MDfxChr::term (static)

// FUNC 0x15000548 ->msys::MListWndPBase::isTpNeutral (MainMenu)
//   size 0x4 | file MainMenu+0x548 | callers(5) 0x1500664c 0x1500d7a8 0x1501cbb0 0x15020014 0x1501fd94
// veneer/thunk -> 0x003620c8 msys::MListWndPBase::isTpNeutral (static)

// FUNC 0x15000550 ->msys::MListWndPBase::getSelectItem (MainMenu)
//   size 0x4 | file MainMenu+0x550 | callers(5) 0x15006d44 0x15016ff0 0x1501ccd8 0x1500d000 0x1501cf00
// veneer/thunk -> 0x003285f0 msys::MListWndPBase::getSelectItem (static)

// FUNC 0x15000558 ->ad::ui::UIListWindowPlusLyt::getCurPos (MainMenu)
//   size 0x4 | file MainMenu+0x558 | callers(2) 0x15006d44 0x1500d000
// veneer/thunk -> 0x003429dc ad::ui::UIListWindowPlusLyt::getCurPos (static)

// FUNC 0x15000560 ->MoveVBase::moveAbs (MainMenu)
//   size 0x4 | file MainMenu+0x560 | callers(2) 0x150148b0 0x15006d44
// veneer/thunk -> 0x002344bc MoveVBase::moveAbs (static)

// FUNC 0x15000568 ->DataPc::getHpMax (MainMenu)
//   size 0x4 | file MainMenu+0x568 | callers(5) 0x1500fc98 0x15013eb8 0x15013468 0x15006d44 0x1500c9c8
// veneer/thunk -> 0x0022c860 DataPc::getHpMax (static)

// FUNC 0x15000570 ->DataPc::getHpNow (MainMenu)
//   size 0x4 | file MainMenu+0x570 | callers(5) 0x1500fc98 0x15013eb8 0x15013468 0x15006d44 0x1500c9c8
// veneer/thunk -> 0x00362c2c DataPc::getHpNow (static)

// FUNC 0x15000578 ->DataPc::getBpMax (MainMenu)
//   size 0x4 | file MainMenu+0x578 | callers(5) 0x1500fc98 0x15013eb8 0x15013468 0x15006d44 0x1500c9c8
// veneer/thunk -> 0x0022c80c DataPc::getBpMax (static)

// FUNC 0x15000580 ->DataPc::getBpNow (MainMenu)
//   size 0x4 | file MainMenu+0x580 | callers(5) 0x1500fc98 0x15013eb8 0x15013468 0x15006d44 0x1500c9c8
// veneer/thunk -> 0x00362c14 DataPc::getBpNow (static)

// FUNC 0x15000588 ->msys::MListWndPBase::isBusyAnime (MainMenu)
//   size 0x4 | file MainMenu+0x588 | callers(8) 0x15006d44 0x15016ff0 0x1501d920 0x1501ccd8 0x1500d000 0x15019ce0 0x1501cf00 0x1501d53c
// veneer/thunk -> 0x0025ae18 msys::MListWndPBase::isBusyAnime (static)

// FUNC 0x15000590 ->ad::fw::Resource::Resource (MainMenu)
//   size 0x4 | file MainMenu+0x590 | callers(6) 0x150231f4 0x15014438 0x150076c0 0x15009458 0x1500df8c 0x1501e420
// veneer/thunk -> 0x00250588 ad::fw::Resource::Resource (static)

// FUNC 0x15000598 ->MoveVBase::MoveVBase (MainMenu)
//   size 0x4 | file MainMenu+0x598 | callers(3) 0x150159f4 0x150076c0 0x1500df8c
// veneer/thunk -> 0x00259740 MoveVBase::MoveVBase (static)

// FUNC 0x150005a0 ->msys::MListWndPBase::MListWndPBase (MainMenu)
//   size 0x4 | file MainMenu+0x5a0 | callers(5) 0x150076c0 0x1500df8c 0x150176ac 0x1501e420 0x150207d8
// veneer/thunk -> 0x00328800 msys::MListWndPBase::MListWndPBase (static)

// FUNC 0x150005a8 ->ad::ui::UIListWindowPlusLyt::UIListWindowPlusLyt (MainMenu)
//   size 0x4 | file MainMenu+0x5a8 | callers(5) 0x150076c0 0x1500df8c 0x150176ac 0x1501e420 0x150207d8
// veneer/thunk -> 0x00146984 ad::ui::UIListWindowPlusLyt::UIListWindowPlusLyt (static)

// FUNC 0x150005b0 ->ad::lyt::Layout::Layout (MainMenu)
//   size 0x4 | file MainMenu+0x5b0 | callers(5) 0x150076c0 0x1500df8c 0x150176ac 0x1501e420 0x150207d8
// veneer/thunk -> 0x00264ccc ad::lyt::Layout::Layout (static)

// FUNC 0x150005b8 ->CellAnime::CellAnime (MainMenu)
//   size 0x4 | file MainMenu+0x5b8 | callers(4) 0x15012f6c 0x150076c0 0x1500df8c 0x1501e420
// veneer/thunk -> 0x0026be18 CellAnime::CellAnime (static)

// FUNC 0x150005c0 ->ad::fw::Resource::~Resource (MainMenu)
//   size 0x4 | file MainMenu+0x5c0 | callers(6) 0x15015468 0x150152a0 0x15007968 0x15009548 0x1500e2ec 0x1501e89c
// veneer/thunk -> 0x0024a104 ad::fw::Resource::~Resource (static)

// FUNC 0x150005c8 ->badge::ChangeBadgeUlcd::InitParam::InitParam (MainMenu)
//   size 0x4 | file MainMenu+0x5c8 | callers(1) 0x15007c10
// veneer/thunk -> 0x003368cc badge::ChangeBadgeUlcd::InitParam::InitParam (static)

// FUNC 0x150005d0 ->badge::ChangeBadgeUlcd::ChangeBadgeUlcd (MainMenu)
//   size 0x4 | file MainMenu+0x5d0 | callers(1) 0x15007c10
// veneer/thunk -> 0x0033698c badge::ChangeBadgeUlcd::ChangeBadgeUlcd (static)

// FUNC 0x150005d8 ->badge::ChangeBadgeUlcd::~ChangeBadgeUlcd (MainMenu)
//   size 0x4 | file MainMenu+0x5d8 | callers(4) 0x150091d0 0x15009254 0x15009548 0x15007c10
// veneer/thunk -> 0x00336c38 badge::ChangeBadgeUlcd::~ChangeBadgeUlcd (static)

// FUNC 0x150005e0 ->msys::MLyt::createLyt (MainMenu)
//   size 0x4 | file MainMenu+0x5e0 | callers(2) 0x15007c10 0x15008f28
// veneer/thunk -> 0x0032c8d8 msys::MLyt::createLyt (static)

// FUNC 0x150005e8 ->badge::ChangeBadgeLlcd::InitParam::InitParam (MainMenu)
//   size 0x4 | file MainMenu+0x5e8 | callers(2) 0x15007c10 0x15008f28
// veneer/thunk -> 0x00335c9c badge::ChangeBadgeLlcd::InitParam::InitParam (static)

// FUNC 0x150005f0 ->badge::ChangeBadgeLlcd::ChangeBadgeLlcd (MainMenu)
//   size 0x4 | file MainMenu+0x5f0 | callers(2) 0x15007c10 0x15008f28
// veneer/thunk -> 0x00335e74 badge::ChangeBadgeLlcd::ChangeBadgeLlcd (static)

// FUNC 0x150005f8 ->badge::ChangeBadgeLlcd::~ChangeBadgeLlcd (MainMenu)
//   size 0x4 | file MainMenu+0x5f8 | callers(5) 0x15009048 0x150090cc 0x15009548 0x15007c10 0x15008f28
// veneer/thunk -> 0x00336598 badge::ChangeBadgeLlcd::~ChangeBadgeLlcd (static)

// FUNC 0x15000600 ->badge::ChangeBadgeUlcd::appear (MainMenu)
//   size 0x4 | file MainMenu+0x600 | callers(1) 0x15007f20
// veneer/thunk -> 0x003367c4 badge::ChangeBadgeUlcd::appear (static)

// FUNC 0x15000608 ->badge::ChangeBadgeLlcd::appear (MainMenu)
//   size 0x4 | file MainMenu+0x608 | callers(1) 0x15007f20
// veneer/thunk -> 0x003353a0 badge::ChangeBadgeLlcd::appear (static)

// FUNC 0x15000610 ->msys::MLyt::getAnim (MainMenu)
//   size 0x4 | file MainMenu+0x610 | callers(14) 0x15007fec 0x15008074 0x150080ec 0x15008124 0x1501b504 0x150235d0 0x15023600 0x15023648 ...
// veneer/thunk -> 0x0032c678 msys::MLyt::getAnim (static)

// FUNC 0x15000618 ->ad::lyt::LytAnim::play (MainMenu)
//   size 0x4 | file MainMenu+0x618 | callers(1) 0x15008074
// veneer/thunk -> 0x0025629c ad::lyt::LytAnim::play (static)

// FUNC 0x15000620 ->ad::lyt::LytAnim::stop (MainMenu)
//   size 0x4 | file MainMenu+0x620 | callers(3) 0x1501b504 0x150080ec 0x1501cf00
// veneer/thunk -> 0x00251878 ad::lyt::LytAnim::stop (static)

// FUNC 0x15000628 ->Frm::setFrm (MainMenu)
//   size 0x4 | file MainMenu+0x628 | callers(2) 0x15008124 0x15014940
// veneer/thunk -> 0x00262180 Frm::setFrm (static)

// FUNC 0x15000630 ->main_menu::BootInfo::setBootPage (MainMenu)
//   size 0x4 | file MainMenu+0x630 | callers(2) 0x1501b270 0x150089f8
// veneer/thunk -> 0x003416c4 main_menu::BootInfo::setBootPage (static)

// FUNC 0x15000638 ->MoveC::moveFrm (MainMenu)
//   size 0x4 | file MainMenu+0x638 | callers(7) 0x1501664c 0x15021dac 0x15022040 0x15016bb8 0x15022dd8 0x1501b270 0x150089f8
// veneer/thunk -> 0x0026bc74 MoveC::moveFrm (static)

// FUNC 0x15000640 ->main_menu::BootInfo::stopRcordBgm (MainMenu)
//   size 0x4 | file MainMenu+0x640 | callers(4) 0x1501e89c 0x15021dac 0x1501b270 0x150089f8
// veneer/thunk -> 0x003416cc main_menu::BootInfo::stopRcordBgm (static)

// FUNC 0x15000648 ->main_menu::BootInfo::restoreBgm (MainMenu)
//   size 0x4 | file MainMenu+0x648 | callers(6) 0x1501b504 0x1501e89c 0x1500e6b0 0x15021dac 0x1501b270 0x150089f8
// veneer/thunk -> 0x0034167c main_menu::BootInfo::restoreBgm (static)

// FUNC 0x15000650 ->msys::MLyt::applyAnime (MainMenu)
//   size 0x4 | file MainMenu+0x650 | callers(2) 0x15008e94 0x15009148
// veneer/thunk -> 0x0032b70c msys::MLyt::applyAnime (static)

// FUNC 0x15000658 ->msys::MLyt::updateInput (MainMenu)
//   size 0x4 | file MainMenu+0x658 | callers(2) 0x15008e98 0x1500914c
// veneer/thunk -> 0x0032bb84 msys::MLyt::updateInput (static)

// FUNC 0x15000660 ->badge::ChangeBadgeLlcd::UpdateParam::UpdateParam (MainMenu)
//   size 0x4 | file MainMenu+0x660 | callers(1) 0x15008e98
// veneer/thunk -> 0x00334cfc badge::ChangeBadgeLlcd::UpdateParam::UpdateParam (static)

// FUNC 0x15000668 ->badge::ChangeBadgeLlcd::update (MainMenu)
//   size 0x4 | file MainMenu+0x668 | callers(1) 0x15008e98
// veneer/thunk -> 0x003354f0 badge::ChangeBadgeLlcd::update (static)

// FUNC 0x15000670 ->msys::MLyt::updateAnimeFrm (MainMenu)
//   size 0x4 | file MainMenu+0x670 | callers(2) 0x15008f24 0x1500917c
// veneer/thunk -> 0x0032be0c msys::MLyt::updateAnimeFrm (static)

// FUNC 0x15000678 ->msys::MLyt::enqueue (MainMenu)
//   size 0x4 | file MainMenu+0x678 | callers(2) 0x15008ff4 0x15009180
// veneer/thunk -> 0x0032c4bc msys::MLyt::enqueue (static)

// FUNC 0x15000680 ->badge::ChangeBadgeLlcd::drawOverlayMsg (MainMenu)
//   size 0x4 | file MainMenu+0x680 | callers(1) 0x15008ff4
// veneer/thunk -> 0x00335218 badge::ChangeBadgeLlcd::drawOverlayMsg (static)

// FUNC 0x15000688 ->msys::MLyt::term (MainMenu)
//   size 0x4 | file MainMenu+0x688 | callers(7) 0x15015468 0x150152a0 0x15009048 0x150090cc 0x150091d0 0x15009254 0x15009548
// veneer/thunk -> 0x0032c3c8 msys::MLyt::term (static)

// FUNC 0x15000690 ->badge::ChangeBadgeUlcd::UpdateParam::UpdateParam (MainMenu)
//   size 0x4 | file MainMenu+0x690 | callers(1) 0x1500914c
// veneer/thunk -> 0x003365f0 badge::ChangeBadgeUlcd::UpdateParam::UpdateParam (static)

// FUNC 0x15000698 ->badge::ChangeBadgeUlcd::update (MainMenu)
//   size 0x4 | file MainMenu+0x698 | callers(1) 0x1500914c
// veneer/thunk -> 0x00336838 badge::ChangeBadgeUlcd::update (static)

// FUNC 0x150006a0 ->badge::ChangeBadgeUlcd::drawOverlayMsg (MainMenu)
//   size 0x4 | file MainMenu+0x6a0 | callers(1) 0x15009180
// veneer/thunk -> 0x00336600 badge::ChangeBadgeUlcd::drawOverlayMsg (static)

// FUNC 0x150006a8 ->ad::ctrl::ButtonGroup::ButtonGroup (MainMenu)
//   size 0x4 | file MainMenu+0x6a8 | callers(2) 0x15014438 0x15009458
// veneer/thunk -> 0x001667d8 ad::ctrl::ButtonGroup::ButtonGroup (static)

// FUNC 0x150006b0 ->ad::ctrl::ButtonGroup::FreeAll (MainMenu)
//   size 0x4 | file MainMenu+0x6b0 | callers(2) 0x150152a0 0x15009548
// veneer/thunk -> 0x002509d0 ad::ctrl::ButtonGroup::FreeAll (static)

// FUNC 0x150006b8 ->nw::ut::internal::LinkListImpl::erase (MainMenu)
//   size 0x4 | file MainMenu+0x6b8 | callers(1) 0x15009548
// veneer/thunk -> 0x002815dc nw::ut::internal::LinkListImpl::erase (static)

// FUNC 0x150006c0 ->ad::lyt::Layout::FreeMemory (MainMenu)
//   size 0x4 | file MainMenu+0x6c0 | callers(1) 0x15009548
// veneer/thunk -> 0x00207c3c ad::lyt::Layout::FreeMemory (static)

// FUNC 0x150006c8 ->ad::ctrl::ButtonGroup::~ButtonGroup (MainMenu)
//   size 0x4 | file MainMenu+0x6c8 | callers(2) 0x150152a0 0x15009548
// veneer/thunk -> 0x00250928 ad::ctrl::ButtonGroup::~ButtonGroup (static)

// FUNC 0x150006d0 ->DataPc::getEquip (MainMenu)
//   size 0x4 | file MainMenu+0x6d0 | callers(9) 0x15012af4 0x150124a8 0x1500ae40 0x1500a480 0x1500a994 0x1500ddf0 0x1500b988 0x1500d5fc ...
// veneer/thunk -> 0x00362c1c DataPc::getEquip (static)

// FUNC 0x150006d8 ->ad::db::GetEquipIdList (MainMenu)
//   size 0x4 | file MainMenu+0x6d8 | callers(2) 0x1500ae40 0x1500b494
// veneer/thunk -> 0x00206de8 ad::db::GetEquipIdList (static)

// FUNC 0x150006e0 ->ad::db::GetEquip (MainMenu)
//   size 0x4 | file MainMenu+0x6e0 | callers(5) 0x150124a8 0x1500ae40 0x15012a2c 0x1500f458 0x1500f5d8
// veneer/thunk -> 0x0013a6e4 ad::db::GetEquip (static)

// FUNC 0x150006e8 ->msys::GetEquipCheckedFlagNo (MainMenu)
//   size 0x4 | file MainMenu+0x6e8 | callers(1) 0x1500ae40
// veneer/thunk -> 0x0032a304 msys::GetEquipCheckedFlagNo (static)

// FUNC 0x150006f0 ->operator.new[] (MainMenu)
//   size 0x4 | file MainMenu+0x6f0 | callers(1) 0x1500b494
// veneer/thunk -> 0x00283558 operator.new[] (static)

// FUNC 0x150006f8 ->msys::MDfxChr::~MDfxChr (MainMenu)
//   size 0x4 | file MainMenu+0x6f8 | callers(5) 0x15015468 0x1500c200 0x1500c2b4 0x1500e2ec 0x1501e89c
// veneer/thunk -> 0x003313cc msys::MDfxChr::~MDfxChr (static)

// FUNC 0x15000700 ->DataPc::setEquip (MainMenu)
//   size 0x4 | file MainMenu+0x700 | callers(3) 0x15012af4 0x15011f6c 0x1500c9c8
// veneer/thunk -> 0x0027c9d4 DataPc::setEquip (static)

// FUNC 0x15000708 ->DataPc::setHpNow (MainMenu)
//   size 0x4 | file MainMenu+0x708 | callers(2) 0x15013468 0x1500c9c8
// veneer/thunk -> 0x0022ed20 DataPc::setHpNow (static)

// FUNC 0x15000710 ->DataPc::setBpNow (MainMenu)
//   size 0x4 | file MainMenu+0x710 | callers(2) 0x15013468 0x1500c9c8
// veneer/thunk -> 0x0022ece0 DataPc::setBpNow (static)

// FUNC 0x15000718 ->DataPc::write (MainMenu)
//   size 0x4 | file MainMenu+0x718 | callers(3) 0x1500f2c8 0x15013468 0x1500c9c8
// veneer/thunk -> 0x0022ecbc DataPc::write (static)

// FUNC 0x15000720 ->MoveVBase::moveSinAbs (MainMenu)
//   size 0x4 | file MainMenu+0x720 | callers(1) 0x1500d000
// veneer/thunk -> 0x0025d0a8 MoveVBase::moveSinAbs (static)

// FUNC 0x15000728 ->msys::PutEquipCheckedFlag (MainMenu)
//   size 0x4 | file MainMenu+0x728 | callers(1) 0x1500d000
// veneer/thunk -> 0x00329a38 msys::PutEquipCheckedFlag (static)

// FUNC 0x15000730 ->Mem::Copy (MainMenu)
//   size 0x4 | file MainMenu+0x730 | callers(3) 0x1500d8bc 0x1500e6b0 0x15016ac8
// veneer/thunk -> 0x0027fd08 Mem::Copy (static)

// FUNC 0x15000738 ->msys::MDfxChr::MDfxChr (MainMenu)
//   size 0x4 | file MainMenu+0x738 | callers(3) 0x150231f4 0x1500df8c 0x1501e420
// veneer/thunk -> 0x0033137c msys::MDfxChr::MDfxChr (static)

// FUNC 0x15000740 ->msys::StatusPanel::StatusPanel (MainMenu)
//   size 0x4 | file MainMenu+0x740 | callers(1) 0x1500df8c
// veneer/thunk -> 0x00325e10 msys::StatusPanel::StatusPanel (static)

// FUNC 0x15000748 ->ad::fw::Resource::term (MainMenu)
//   size 0x4 | file MainMenu+0x748 | callers(4) 0x15015468 0x150152a0 0x1500e2ec 0x1501e89c
// veneer/thunk -> 0x00233340 ad::fw::Resource::term (static)

// FUNC 0x15000750 ->msys::StatusPanel::~StatusPanel (MainMenu)
//   size 0x4 | file MainMenu+0x750 | callers(1) 0x1500e2ec
// veneer/thunk -> 0x00325f7c msys::StatusPanel::~StatusPanel (static)

// FUNC 0x15000758 ->GameMain::popStack (MainMenu)
//   size 0x4 | file MainMenu+0x758 | callers(1) 0x1500e6b0
// veneer/thunk -> 0x0033e968 GameMain::popStack (static)

// FUNC 0x15000760 ->fld::GetBootInfo (MainMenu)
//   size 0x4 | file MainMenu+0x760 | callers(1) 0x1500e6b0
// veneer/thunk -> 0x002a8d3c fld::GetBootInfo (static)

// FUNC 0x15000768 ->fld::BootInfo::backScenarioMode (MainMenu)
//   size 0x4 | file MainMenu+0x768 | callers(1) 0x1500e6b0
// veneer/thunk -> 0x0030dcd8 fld::BootInfo::backScenarioMode (static)

// FUNC 0x15000770 ->msys::MListWndPBase::normalizeState (MainMenu)
//   size 0x4 | file MainMenu+0x770 | callers(1) 0x1500e6b0
// veneer/thunk -> 0x00328614 msys::MListWndPBase::normalizeState (static)

// FUNC 0x15000778 ->msys::MListWndPBase::resetCur (MainMenu)
//   size 0x4 | file MainMenu+0x778 | callers(6) 0x1500f0c4 0x15017348 0x15011d88 0x15011e78 0x1500f2c8 0x1501a650
// veneer/thunk -> 0x003287c0 msys::MListWndPBase::resetCur (static)

// FUNC 0x15000780 ->ad::db::GetBtlGuideList (MainMenu)
//   size 0x4 | file MainMenu+0x780 | callers(4) 0x15017348 0x15011ab0 0x15011be4 0x15015c5c
// veneer/thunk -> 0x0013a38c ad::db::GetBtlGuideList (static)

// FUNC 0x15000788 ->ad::db::GetAtkGuideList (MainMenu)
//   size 0x4 | file MainMenu+0x788 | callers(7) 0x15022eb0 0x15011e78 0x15011ab0 0x1501664c 0x15011be4 0x15015c5c 0x1501b270
// veneer/thunk -> 0x0013a34c ad::db::GetAtkGuideList (static)

// FUNC 0x15000790 ->ad::db::GetFldGuideList (MainMenu)
//   size 0x4 | file MainMenu+0x790 | callers(4) 0x15017348 0x15011ab0 0x15011be4 0x15015c5c
// veneer/thunk -> 0x0013a3cc ad::db::GetFldGuideList (static)

// FUNC 0x15000798 ->ad::db::GetFldActGuideList (MainMenu)
//   size 0x4 | file MainMenu+0x798 | callers(4) 0x15011d88 0x15011ab0 0x15011be4 0x15015c5c
// veneer/thunk -> 0x0013a4fc ad::db::GetFldActGuideList (static)

// FUNC 0x150007a0 ->DataPc::getAcquireRankUpBonusNum (MainMenu)
//   size 0x4 | file MainMenu+0x7a0 | callers(1) 0x1500f2c8
// veneer/thunk -> 0x002528e0 DataPc::getAcquireRankUpBonusNum (static)

// FUNC 0x150007a8 ->ad::db::GetPcRankUpBonus (MainMenu)
//   size 0x4 | file MainMenu+0x7a8 | callers(1) 0x1500f2c8
// veneer/thunk -> 0x0013a40c ad::db::GetPcRankUpBonus (static)

// FUNC 0x150007b0 ->ad::db::GetItemMsg (MainMenu)
//   size 0x4 | file MainMenu+0x7b0 | callers(6) 0x15012af4 0x15013ad0 0x15012a2c 0x1500f458 0x1500f5d8 0x1501204c
// veneer/thunk -> 0x0013a194 ad::db::GetItemMsg (static)

// FUNC 0x150007b8 ->DataPc::getLv (MainMenu)
//   size 0x4 | file MainMenu+0x7b8 | callers(1) 0x1500fc98
// veneer/thunk -> 0x00362bec DataPc::getLv (static)

// FUNC 0x150007c0 ->DataPc::getExpNextLv (MainMenu)
//   size 0x4 | file MainMenu+0x7c0 | callers(1) 0x1500fc98
// veneer/thunk -> 0x00362afc DataPc::getExpNextLv (static)

// FUNC 0x150007c8 ->DataPc::getRank (MainMenu)
//   size 0x4 | file MainMenu+0x7c8 | callers(1) 0x1500fc98
// veneer/thunk -> 0x00362c00 DataPc::getRank (static)

// FUNC 0x150007d0 ->CellAnime::term (MainMenu)
//   size 0x4 | file MainMenu+0x7d0 | callers(1) 0x1500fc98
// veneer/thunk -> 0x00259f88 CellAnime::term (static)

// FUNC 0x150007d8 ->DataPc::getPow (MainMenu)
//   size 0x4 | file MainMenu+0x7d8 | callers(2) 0x1500fc98 0x15013eb8
// veneer/thunk -> 0x00207984 DataPc::getPow (static)

// FUNC 0x150007e0 ->DataPc::getDef (MainMenu)
//   size 0x4 | file MainMenu+0x7e0 | callers(2) 0x1500fc98 0x15013eb8
// veneer/thunk -> 0x00207930 DataPc::getDef (static)

// FUNC 0x150007e8 ->DataPc::getSpd (MainMenu)
//   size 0x4 | file MainMenu+0x7e8 | callers(2) 0x1500fc98 0x15013eb8
// veneer/thunk -> 0x002078dc DataPc::getSpd (static)

// FUNC 0x150007f0 ->DataPc::getHige (MainMenu)
//   size 0x4 | file MainMenu+0x7f0 | callers(2) 0x1500fc98 0x15013eb8
// veneer/thunk -> 0x00207888 DataPc::getHige (static)

// FUNC 0x150007f8 ->DataPc::getExpNow (MainMenu)
//   size 0x4 | file MainMenu+0x7f8 | callers(1) 0x1500fc98
// veneer/thunk -> 0x00362c34 DataPc::getExpNow (static)

// FUNC 0x15000800 ->__cxa_guard_acquire (MainMenu)
//   size 0x4 | file MainMenu+0x800 | callers(8) 0x150142ec 0x1501ece8 0x15022040 0x150191dc 0x15019238 0x150192ac 0x1501a164 0x1501cf00
// veneer/thunk -> 0x00288110 __cxa_guard_acquire (static)

// FUNC 0x15000808 ->__cxa_guard_release (MainMenu)
//   size 0x4 | file MainMenu+0x808 | callers(8) 0x150142ec 0x1501ece8 0x15022040 0x15019200 0x15019260 0x150192d4 0x1501a164 0x1501cf00
// veneer/thunk -> 0x001018a8 __cxa_guard_release (static)

// FUNC 0x15000810 ->Message::Message (MainMenu)
//   size 0x4 | file MainMenu+0x810 | callers(1) 0x15010740
// veneer/thunk -> 0x00110d5c Message::Message (static)

// FUNC 0x15000818 ->Grp::GetLcdWidth (MainMenu)
//   size 0x4 | file MainMenu+0x818 | callers(2) 0x15014558 0x15010874
// veneer/thunk -> 0x00271e08 Grp::GetLcdWidth (static)

// FUNC 0x15000820 ->Grp::GetLcdHeight (MainMenu)
//   size 0x4 | file MainMenu+0x820 | callers(2) 0x15014558 0x15010874
// veneer/thunk -> 0x00271de4 Grp::GetLcdHeight (static)

// FUNC 0x15000828 ->MsgWndPosCalculator::calc (MainMenu)
//   size 0x4 | file MainMenu+0x828 | callers(2) 0x15014558 0x15010874
// veneer/thunk -> 0x0024d828 MsgWndPosCalculator::calc (static)

// FUNC 0x15000830 ->MessageSimple::getMsgHeight (MainMenu)
//   size 0x4 | file MainMenu+0x830 | callers(2) 0x15014558 0x15010874
// veneer/thunk -> 0x00136f24 MessageSimple::getMsgHeight (static)

// FUNC 0x15000838 ->msys::GetRecodAreaNoListNum (MainMenu)
//   size 0x4 | file MainMenu+0x838 | callers(3) 0x15010b9c 0x15017bf8 0x15017ca8
// veneer/thunk -> 0x0032a38c msys::GetRecodAreaNoListNum (static)

// FUNC 0x15000840 ->msys::GetRecodAreaNoList (MainMenu)
//   size 0x4 | file MainMenu+0x840 | callers(2) 0x15010b9c 0x15017c1c
// veneer/thunk -> 0x0032960c msys::GetRecodAreaNoList (static)

// FUNC 0x15000848 ->msys::GetBlkHlwFlagNoList (MainMenu)
//   size 0x4 | file MainMenu+0x848 | callers(1) 0x15010b9c
// veneer/thunk -> 0x00329a00 msys::GetBlkHlwFlagNoList (static)

// FUNC 0x15000850 ->nn::math::CntBit1 (MainMenu)
//   size 0x4 | file MainMenu+0x850 | callers(1) 0x15010b9c
// veneer/thunk -> 0x00276b38 nn::math::CntBit1 (static)

// FUNC 0x15000858 ->ad::db::GetPcAttack (MainMenu)
//   size 0x4 | file MainMenu+0x858 | callers(2) 0x15010b9c 0x150195d4
// veneer/thunk -> 0x00237260 ad::db::GetPcAttack (static)

// FUNC 0x15000860 ->SndSys::stop (MainMenu)
//   size 0x4 | file MainMenu+0x860 | callers(4) 0x1501b504 0x1501cf00 0x1501153c 0x1501a400
// veneer/thunk -> 0x0024dd04 SndSys::stop (static)

// FUNC 0x15000868 ->SndSys::start (MainMenu)
//   size 0x4 | file MainMenu+0x868 | callers(1) 0x1501153c
// veneer/thunk -> 0x0033c77c SndSys::start (static)

// FUNC 0x15000870 ->RandSys::get (MainMenu)
//   size 0x4 | file MainMenu+0x870 | callers(3) 0x15014940 0x1501163c 0x15019f90
// veneer/thunk -> 0x00273054 RandSys::get (static)

// FUNC 0x15000878 ->nn::nstd::TSPrintf (MainMenu)
//   size 0x4 | file MainMenu+0x878 | callers(1) 0x15011ab0
// veneer/thunk -> 0x002765cc nn::nstd::TSPrintf (static)

// FUNC 0x15000880 ->ActGuideAcs::IsExistGuide (MainMenu)
//   size 0x4 | file MainMenu+0x880 | callers(1) 0x15011d88
// veneer/thunk -> 0x00132a70 ActGuideAcs::IsExistGuide (static)

// FUNC 0x15000888 ->ActGuideAcs::IsReadedGuide (MainMenu)
//   size 0x4 | file MainMenu+0x888 | callers(1) 0x15011d88
// veneer/thunk -> 0x00132b0c ActGuideAcs::IsReadedGuide (static)

// FUNC 0x15000890 ->BattleAttackGuideDataAcs::IsExistGuide (MainMenu)
//   size 0x4 | file MainMenu+0x890 | callers(3) 0x15022eb0 0x15011e78 0x1501b270
// veneer/thunk -> 0x00139944 BattleAttackGuideDataAcs::IsExistGuide (static)

// FUNC 0x15000898 ->BattleAttackGuideDataAcs::IsReadedGuide (MainMenu)
//   size 0x4 | file MainMenu+0x898 | callers(1) 0x15011e78
// veneer/thunk -> 0x00139ac4 BattleAttackGuideDataAcs::IsReadedGuide (static)

// FUNC 0x150008a0 ->__aeabi_memcpy4 (MainMenu)
//   size 0x4 | file MainMenu+0x8a0 | callers(3) 0x15012af4 0x15011f6c 0x15019420
// veneer/thunk -> 0x00286f4c __aeabi_memcpy4 (static)

// FUNC 0x150008a8 ->msys::StatusPanel::setNewEquipParam (MainMenu)
//   size 0x4 | file MainMenu+0x8a8 | callers(2) 0x15012af4 0x15011f6c
// veneer/thunk -> 0x00325128 msys::StatusPanel::setNewEquipParam (static)

// FUNC 0x150008b0 ->ad::db::GetItemData (MainMenu)
//   size 0x4 | file MainMenu+0x8b0 | callers(2) 0x15012af4 0x1501204c
// veneer/thunk -> 0x00239a04 ad::db::GetItemData (static)

// FUNC 0x150008b8 ->operator.delete[] (MainMenu)
//   size 0x4 | file MainMenu+0x8b8 | callers(1) 0x15012114
// veneer/thunk -> 0x0028829c operator.delete[] (static)

// FUNC 0x150008c0 ->strcmp (MainMenu)
//   size 0x4 | file MainMenu+0x8c0 | callers(3) 0x15014e10 0x150131d0 0x150121ac
// veneer/thunk -> 0x002833b8 strcmp (static)

// FUNC 0x150008c8 ->msys::MCtrlUserData::findExtUserDataByName (MainMenu)
//   size 0x4 | file MainMenu+0x8c8 | callers(3) 0x15014e10 0x150131d0 0x150121ac
// veneer/thunk -> 0x0036203c msys::MCtrlUserData::findExtUserDataByName (static)

// FUNC 0x150008d0 ->MessageSimple::MessageSimple (MainMenu)
//   size 0x4 | file MainMenu+0x8d0 | callers(1) 0x15012fa0
// veneer/thunk -> 0x0027ceec MessageSimple::MessageSimple (static)

// FUNC 0x150008d8 ->ad::TransMultiSymbol::init (MainMenu)
//   size 0x4 | file MainMenu+0x8d8 | callers(2) 0x15012fe8 0x15020358
// veneer/thunk -> 0x0026d7f8 ad::TransMultiSymbol::init (static)

// FUNC 0x150008e0 ->BinGlu4Acs::getEntryAcs (MainMenu)
//   size 0x4 | file MainMenu+0x8e0 | callers(2) 0x15012fe8 0x15020358
// veneer/thunk -> 0x00285268 BinGlu4Acs::getEntryAcs (static)

// FUNC 0x150008e8 ->ad::fw::TaskBase::readCA (MainMenu)
//   size 0x4 | file MainMenu+0x8e8 | callers(2) 0x15012fe8 0x15020358
// veneer/thunk -> 0x0026daf8 ad::fw::TaskBase::readCA (static)

// FUNC 0x150008f0 ->msys::MDfxChr::setCA (MainMenu)
//   size 0x4 | file MainMenu+0x8f0 | callers(1) 0x15013088
// veneer/thunk -> 0x00330c7c msys::MDfxChr::setCA (static)

// FUNC 0x150008f8 ->DataPc::addStatus (MainMenu)
//   size 0x4 | file MainMenu+0x8f8 | callers(1) 0x15013468
// veneer/thunk -> 0x0033bd28 DataPc::addStatus (static)

// FUNC 0x15000900 ->msys::StatusPanel::setLow (MainMenu)
//   size 0x4 | file MainMenu+0x900 | callers(1) 0x150138ec
// veneer/thunk -> 0x00325b04 msys::StatusPanel::setLow (static)

// FUNC 0x15000908 ->msys::StatusPanel::setHi (MainMenu)
//   size 0x4 | file MainMenu+0x908 | callers(1) 0x150138ec
// veneer/thunk -> 0x003258b8 msys::StatusPanel::setHi (static)

// FUNC 0x15000910 ->msys::StatusPanel::resetHi (MainMenu)
//   size 0x4 | file MainMenu+0x910 | callers(1) 0x150138ec
// veneer/thunk -> 0x00325b54 msys::StatusPanel::resetHi (static)

// FUNC 0x15000918 ->ad::ui::UIListWindowPlusLyt::updateInstant (MainMenu)
//   size 0x4 | file MainMenu+0x918 | callers(1) 0x15013bb0
// veneer/thunk -> 0x00145720 ad::ui::UIListWindowPlusLyt::updateInstant (static)

// FUNC 0x15000920 ->ad::font::ResFont::ResFont (MainMenu)
//   size 0x4 | file MainMenu+0x920 | callers(1) 0x15014438
// veneer/thunk -> 0x0027542c ad::font::ResFont::ResFont (static)

// FUNC 0x15000928 ->MemAlc::initCore (MainMenu)
//   size 0x4 | file MainMenu+0x928 | callers(1) 0x150144d8
// veneer/thunk -> 0x002855b4 MemAlc::initCore (static)

// FUNC 0x15000930 ->ad::lyt::LytDrawSys::GetInst (MainMenu)
//   size 0x4 | file MainMenu+0x930 | callers(2) 0x150144d8 0x15022040
// veneer/thunk -> 0x00287f58 ad::lyt::LytDrawSys::GetInst (static)

// FUNC 0x15000938 ->ad::lyt::Initialize (MainMenu)
//   size 0x4 | file MainMenu+0x938 | callers(2) 0x150144d8 0x15022040
// veneer/thunk -> 0x002855e0 ad::lyt::Initialize (static)

// FUNC 0x15000940 ->Message::play (MainMenu)
//   size 0x4 | file MainMenu+0x940 | callers(5) 0x15014558 0x1501c07c 0x1501ccd8 0x1501b024 0x1501b204
// veneer/thunk -> 0x00259970 Message::play (static)

// FUNC 0x15000948 ->msys::MChrBaseCore::getGlbMtx (MainMenu)
//   size 0x4 | file MainMenu+0x948 | callers(1) 0x15014558
// veneer/thunk -> 0x0032606c msys::MChrBaseCore::getGlbMtx (static)

// FUNC 0x15000950 ->msys::MChrBaseCore::isBusySRTMov (MainMenu)
//   size 0x4 | file MainMenu+0x950 | callers(2) 0x150147a8 0x1501ae30
// veneer/thunk -> 0x00361fd8 msys::MChrBaseCore::isBusySRTMov (static)

// FUNC 0x15000958 ->msys::MChrBaseCore::jumpFT (MainMenu)
//   size 0x4 | file MainMenu+0x958 | callers(1) 0x150147a8
// veneer/thunk -> 0x0025d1c0 msys::MChrBaseCore::jumpFT (static)

// FUNC 0x15000960 ->ad::lyt::LytAnim::update (MainMenu)
//   size 0x4 | file MainMenu+0x960 | callers(2) 0x15014940 0x15021dac
// veneer/thunk -> 0x0025631c ad::lyt::LytAnim::update (static)

// FUNC 0x15000968 ->ad::dfx::Unit::kill (MainMenu)
//   size 0x4 | file MainMenu+0x968 | callers(2) 0x15014cc4 0x1501afac
// veneer/thunk -> 0x0025cf2c ad::dfx::Unit::kill (static)

// FUNC 0x15000970 ->ad::lyt::LytResourceMan::term (MainMenu)
//   size 0x4 | file MainMenu+0x970 | callers(2) 0x15015468 0x150152a0
// veneer/thunk -> 0x00250938 ad::lyt::LytResourceMan::term (static)

// FUNC 0x15000978 ->Mem::Free (MainMenu)
//   size 0x4 | file MainMenu+0x978 | callers(1) 0x150152a0
// veneer/thunk -> 0x00285d3c Mem::Free (static)

// FUNC 0x15000980 ->ad::font::ResFont::~ResFont (MainMenu)
//   size 0x4 | file MainMenu+0x980 | callers(1) 0x150152a0
// veneer/thunk -> 0x002508a8 ad::font::ResFont::~ResFont (static)

// FUNC 0x15000988 ->ad::guide::Man::Term (MainMenu)
//   size 0x4 | file MainMenu+0x988 | callers(1) 0x15015468
// veneer/thunk -> 0x0016a3fc ad::guide::Man::Term (static)

// FUNC 0x15000990 ->msys::MMapIconMan::term (MainMenu)
//   size 0x4 | file MainMenu+0x990 | callers(1) 0x15015468
// veneer/thunk -> 0x00324a54 msys::MMapIconMan::term (static)

// FUNC 0x15000998 ->ad::fw::TaskBase::term (MainMenu)
//   size 0x4 | file MainMenu+0x998 | callers(1) 0x15015468
// veneer/thunk -> 0x0024a358 ad::fw::TaskBase::term (static)

// FUNC 0x150009a0 ->MsgDataAcsrBase::term (MainMenu)
//   size 0x4 | file MainMenu+0x9a0 | callers(1) 0x15015468
// veneer/thunk -> 0x0013790c MsgDataAcsrBase::term (static)

// FUNC 0x150009a8 ->msys::MLytNumRes::term (MainMenu)
//   size 0x4 | file MainMenu+0x9a8 | callers(1) 0x15015468
// veneer/thunk -> 0x00233128 msys::MLytNumRes::term (static)

// FUNC 0x150009b0 ->Message::term (MainMenu)
//   size 0x4 | file MainMenu+0x9b0 | callers(2) 0x15015468 0x1501e89c
// veneer/thunk -> 0x0033dc68 Message::term (static)

// FUNC 0x150009b8 ->Message::~Message (MainMenu)
//   size 0x4 | file MainMenu+0x9b8 | callers(2) 0x15015468 0x1501e89c
// veneer/thunk -> 0x00206538 Message::~Message (static)

// FUNC 0x150009c0 ->msys::MComSys::~MComSys (MainMenu)
//   size 0x4 | file MainMenu+0x9c0 | callers(1) 0x15015468
// veneer/thunk -> 0x003300e8 msys::MComSys::~MComSys (static)

// FUNC 0x150009c8 ->msys::MSndSe::play (MainMenu)
//   size 0x4 | file MainMenu+0x9c8 | callers(1) 0x1501580c
// veneer/thunk -> 0x0032d844 msys::MSndSe::play (static)

// FUNC 0x150009d0 ->BattleGuideDataAcs::loadFromGameWork (MainMenu)
//   size 0x4 | file MainMenu+0x9d0 | callers(1) 0x15015ef8
// veneer/thunk -> 0x00138b70 BattleGuideDataAcs::loadFromGameWork (static)

// FUNC 0x150009d8 ->BattleGuideDataAcs::checkGuideAppear (MainMenu)
//   size 0x4 | file MainMenu+0x9d8 | callers(1) 0x15015ef8
// veneer/thunk -> 0x001389a4 BattleGuideDataAcs::checkGuideAppear (static)

// FUNC 0x150009e0 ->BattleGuideDataAcs::saveToGameWork (MainMenu)
//   size 0x4 | file MainMenu+0x9e0 | callers(3) 0x15016110 0x1501618c 0x1501783c
// veneer/thunk -> 0x00138990 BattleGuideDataAcs::saveToGameWork (static)

// FUNC 0x150009e8 ->msys::MListWndPBase::getCurNo (MainMenu)
//   size 0x4 | file MainMenu+0x9e8 | callers(1) 0x15016548
// veneer/thunk -> 0x003620e0 msys::MListWndPBase::getCurNo (static)

// FUNC 0x150009f0 ->BattleAttackGuideDataAcs::MarkReadedGuide (MainMenu)
//   size 0x4 | file MainMenu+0x9f0 | callers(1) 0x15016548
// veneer/thunk -> 0x00139ae8 BattleAttackGuideDataAcs::MarkReadedGuide (static)

// FUNC 0x150009f8 ->FldGuideAcs::MarkReadedGuide (MainMenu)
//   size 0x4 | file MainMenu+0x9f8 | callers(1) 0x15016548
// veneer/thunk -> 0x00133000 FldGuideAcs::MarkReadedGuide (static)

// FUNC 0x15000a00 ->ActGuideAcs::MarkReadedGuide (MainMenu)
//   size 0x4 | file MainMenu+0xa00 | callers(1) 0x15016548
// veneer/thunk -> 0x00132b30 ActGuideAcs::MarkReadedGuide (static)

// FUNC 0x15000a08 ->btl::GetBootInfo (MainMenu)
//   size 0x4 | file MainMenu+0xa08 | callers(1) 0x1501664c
// veneer/thunk -> 0x00217ff8 btl::GetBootInfo (static)

// FUNC 0x15000a10 ->btl::BootInfo::setModePcAtkPractice (MainMenu)
//   size 0x4 | file MainMenu+0xa10 | callers(1) 0x1501664c
// veneer/thunk -> 0x0029d3b4 btl::BootInfo::setModePcAtkPractice (static)

// FUNC 0x15000a18 ->btl::BootInfo::setModePcAtkExample (MainMenu)
//   size 0x4 | file MainMenu+0xa18 | callers(1) 0x1501664c
// veneer/thunk -> 0x0029d100 btl::BootInfo::setModePcAtkExample (static)

// FUNC 0x15000a20 ->main_menu::BootInfo::playBgm (MainMenu)
//   size 0x4 | file MainMenu+0xa20 | callers(3) 0x15021dac 0x1501cb84 0x15016968
// veneer/thunk -> 0x0034172c main_menu::BootInfo::playBgm (static)

// FUNC 0x15000a28 ->main_menu::BootInfo::saveBgm (MainMenu)
//   size 0x4 | file MainMenu+0xa28 | callers(2) 0x1501dfd0 0x15016ac8
// veneer/thunk -> 0x00341804 main_menu::BootInfo::saveBgm (static)

// FUNC 0x15000a30 ->SndSys::stopAllBgm (MainMenu)
//   size 0x4 | file MainMenu+0xa30 | callers(2) 0x1501dfd0 0x15016ac8
// veneer/thunk -> 0x0033c450 SndSys::stopAllBgm (static)

// FUNC 0x15000a38 ->GameMain::Change (MainMenu)
//   size 0x4 | file MainMenu+0xa38 | callers(1) 0x15016ac8
// veneer/thunk -> 0x0033e7fc GameMain::Change (static)

// FUNC 0x15000a40 ->FldGuideAcs::IsExistGuide (MainMenu)
//   size 0x4 | file MainMenu+0xa40 | callers(1) 0x15017348
// veneer/thunk -> 0x00132f1c FldGuideAcs::IsExistGuide (static)

// FUNC 0x15000a48 ->FldGuideAcs::IsReadedGuide (MainMenu)
//   size 0x4 | file MainMenu+0xa48 | callers(1) 0x15017348
// veneer/thunk -> 0x00132fdc FldGuideAcs::IsReadedGuide (static)

// FUNC 0x15000a50 ->__hardfp_log10f (MainMenu)
//   size 0x4 | file MainMenu+0xa50 | callers(1) 0x150179bc
// veneer/thunk -> 0x00364290 __hardfp_log10f (static)

// FUNC 0x15000a58 ->msys::GetBlkHlwFlagNoList (MainMenu)
//   size 0x4 | file MainMenu+0xa58 | callers(3) 0x15017c28 0x15017c34 0x15017c4c
// veneer/thunk -> 0x00329a2c msys::GetBlkHlwFlagNoList (static)

// FUNC 0x15000a60 ->Message::init (MainMenu)
//   size 0x4 | file MainMenu+0xa60 | callers(3) 0x15022040 0x15018120 0x150182f8
// veneer/thunk -> 0x0033dc2c Message::init (static)

// FUNC 0x15000a68 ->Message::setMsgDat (MainMenu)
//   size 0x4 | file MainMenu+0xa68 | callers(3) 0x15022040 0x1501812c 0x15018304
// veneer/thunk -> 0x0033ddc8 Message::setMsgDat (static)

// FUNC 0x15000a70 ->msys::GetBlkHlwItemGetRate (MainMenu)
//   size 0x4 | file MainMenu+0xa70 | callers(2) 0x1501857c 0x15018588
// veneer/thunk -> 0x00329ae4 msys::GetBlkHlwItemGetRate (static)

// FUNC 0x15000a78 ->ad::lyt::Layout::FindPartsPaneByName (MainMenu)
//   size 0x4 | file MainMenu+0xa78 | callers(3) 0x1501f198 0x15018690 0x15019170
// veneer/thunk -> 0x00264d90 ad::lyt::Layout::FindPartsPaneByName (static)

// FUNC 0x15000a80 ->nn::snd::CTR::OutputCapture::Initialize (MainMenu)
//   size 0x4 | file MainMenu+0xa80 | callers(1) 0x15018e5c
// veneer/thunk -> 0x001a5118 nn::snd::CTR::OutputCapture::Initialize (static)

// FUNC 0x15000a88 ->nn::snd::CTR::SetOutputCapture (MainMenu)
//   size 0x4 | file MainMenu+0xa88 | callers(1) 0x15018e68
// veneer/thunk -> 0x001a5350 nn::snd::CTR::SetOutputCapture (static)

// FUNC 0x15000a90 ->nn::snd::CTR::OutputCapture::Enable (MainMenu)
//   size 0x4 | file MainMenu+0xa90 | callers(2) 0x1501e89c 0x15018e74
// veneer/thunk -> 0x001a520c nn::snd::CTR::OutputCapture::Enable (static)

// FUNC 0x15000a98 ->msys::MLyt::getMPaneRef (MainMenu)
//   size 0x4 | file MainMenu+0xa98 | callers(1) 0x15019318
// veneer/thunk -> 0x0032bad0 msys::MLyt::getMPaneRef (static)

// FUNC 0x15000aa0 ->msys::MMapIconMan::setRecordArea (MainMenu)
//   size 0x4 | file MainMenu+0xaa0 | callers(2) 0x1501a650 0x15019ce0
// veneer/thunk -> 0x00324654 msys::MMapIconMan::setRecordArea (static)

// FUNC 0x15000aa8 ->nw::snd::StreamSoundHandle::StreamSoundHandle (MainMenu)
//   size 0x4 | file MainMenu+0xaa8 | callers(1) 0x1501a400
// veneer/thunk -> 0x001c65a8 nw::snd::StreamSoundHandle::StreamSoundHandle (static)

// FUNC 0x15000ab0 ->nw::snd::internal::StreamSound::GetPlaySamplePosition (MainMenu)
//   size 0x4 | file MainMenu+0xab0 | callers(1) 0x1501a400
// veneer/thunk -> 0x0034c380 nw::snd::internal::StreamSound::GetPlaySamplePosition (static)

// FUNC 0x15000ab8 ->nw::snd::StreamSoundHandle::DetachSound (MainMenu)
//   size 0x4 | file MainMenu+0xab8 | callers(1) 0x1501a400
// veneer/thunk -> 0x001c6570 nw::snd::StreamSoundHandle::DetachSound (static)

// FUNC 0x15000ac0 ->msys::MListWndPBase::getItemNum (MainMenu)
//   size 0x4 | file MainMenu+0xac0 | callers(1) 0x1501aac0
// veneer/thunk -> 0x003620b4 msys::MListWndPBase::getItemNum (static)

// FUNC 0x15000ac8 ->PutRegFlag (MainMenu)
//   size 0x4 | file MainMenu+0xac8 | callers(2) 0x1501aac0 0x150210c0
// veneer/thunk -> 0x002731a0 PutRegFlag (static)

// FUNC 0x15000ad0 ->msys::MListWndPBase::getCurPos (MainMenu)
//   size 0x4 | file MainMenu+0xad0 | callers(2) 0x1501c24c 0x1501ae30
// veneer/thunk -> 0x003429d4 msys::MListWndPBase::getCurPos (static)

// FUNC 0x15000ad8 ->MoveVBase::moveCosSinAbs (MainMenu)
//   size 0x4 | file MainMenu+0xad8 | callers(2) 0x1501c24c 0x1501ae30
// veneer/thunk -> 0x003403fc MoveVBase::moveCosSinAbs (static)

// FUNC 0x15000ae0 ->msys::MMapIconMan::setUp (MainMenu)
//   size 0x4 | file MainMenu+0xae0 | callers(2) 0x1501b504 0x15022040
// veneer/thunk -> 0x00324a90 msys::MMapIconMan::setUp (static)

// FUNC 0x15000ae8 ->Message::close (MainMenu)
//   size 0x4 | file MainMenu+0xae8 | callers(3) 0x1501b504 0x1501c07c 0x1501ccd8
// veneer/thunk -> 0x0024dcc8 Message::close (static)

// FUNC 0x15000af0 ->nn::applet::CTR::EnableSleep (MainMenu)
//   size 0x4 | file MainMenu+0xaf0 | callers(2) 0x1501b504 0x1501e89c
// veneer/thunk -> 0x002838a8 nn::applet::CTR::EnableSleep (static)

// FUNC 0x15000af8 ->msys::MListWndPFractionCore::InitParamEx::InitParamEx (MainMenu)
//   size 0x4 | file MainMenu+0xaf8 | callers(2) 0x1501e420 0x1501bad0
// veneer/thunk -> 0x0032a394 msys::MListWndPFractionCore::InitParamEx::InitParamEx (static)

// FUNC 0x15000b00 ->msys::MListWndPFractionCore::initEx (MainMenu)
//   size 0x4 | file MainMenu+0xb00 | callers(1) 0x1501bad0
// veneer/thunk -> 0x0032b6e8 msys::MListWndPFractionCore::initEx (static)

// FUNC 0x15000b08 ->CellAnime::playEvColorAnm (MainMenu)
//   size 0x4 | file MainMenu+0xb08 | callers(1) 0x1501c24c
// veneer/thunk -> 0x00256a54 CellAnime::playEvColorAnm (static)

// FUNC 0x15000b10 ->nn::snd::CTR::OutputCapture::Read (MainMenu)
//   size 0x4 | file MainMenu+0xb10 | callers(1) 0x1501cf00
// veneer/thunk -> 0x001a5130 nn::snd::CTR::OutputCapture::Read (static)

// FUNC 0x15000b18 ->msys::MLyt::createAnimeAutoSlot (MainMenu)
//   size 0x4 | file MainMenu+0xb18 | callers(5) 0x1501d920 0x1501f830 0x15020134 0x1501cf00 0x1501d53c
// veneer/thunk -> 0x0032c308 msys::MLyt::createAnimeAutoSlot (static)

// FUNC 0x15000b20 ->msys::MLyt::createAnime (MainMenu)
//   size 0x4 | file MainMenu+0xb20 | callers(3) 0x1501d920 0x15022040 0x1501d53c
// veneer/thunk -> 0x00206c48 msys::MLyt::createAnime (static)

// FUNC 0x15000b28 ->nn::snd::CTR::OutputCapture::Finalize (MainMenu)
//   size 0x4 | file MainMenu+0xb28 | callers(1) 0x1501e89c
// veneer/thunk -> 0x001a5214 nn::snd::CTR::OutputCapture::Finalize (static)

// FUNC 0x15000b30 ->ad::fw::TaskBase::isReadable (MainMenu)
//   size 0x4 | file MainMenu+0xb30 | callers(2) 0x15020358 0x1501f0e4
// veneer/thunk -> 0x00222f44 ad::fw::TaskBase::isReadable (static)

// FUNC 0x15000b38 ->msys::MListWndPBase::applyAnime (MainMenu)
//   size 0x4 | file MainMenu+0xb38 | callers(1) 0x1501f990
// veneer/thunk -> 0x0032844c msys::MListWndPBase::applyAnime (static)

// FUNC 0x15000b40 ->ad::lyt::Layout::Animate (MainMenu)
//   size 0x4 | file MainMenu+0xb40 | callers(1) 0x1501f990
// veneer/thunk -> 0x00161aec ad::lyt::Layout::Animate (static)

// FUNC 0x15000b48 ->msys::MListWndPBase::isEnableInput (MainMenu)
//   size 0x4 | file MainMenu+0xb48 | callers(1) 0x15020014
// veneer/thunk -> 0x003285f8 msys::MListWndPBase::isEnableInput (static)

// FUNC 0x15000b50 ->ad::GetRegion (MainMenu)
//   size 0x4 | file MainMenu+0xb50 | callers(1) 0x15020be8
// veneer/thunk -> 0x00285d18 ad::GetRegion (static)

// FUNC 0x15000b58 ->msys::MCamera::getProjMtx (MainMenu)
//   size 0x4 | file MainMenu+0xb58 | callers(1) 0x15021dac
// veneer/thunk -> 0x00206718 msys::MCamera::getProjMtx (static)

// FUNC 0x15000b60 ->msys::MCamera::getViewMtx (MainMenu)
//   size 0x4 | file MainMenu+0xb60 | callers(1) 0x15021dac
// veneer/thunk -> 0x002068e4 msys::MCamera::getViewMtx (static)

// FUNC 0x15000b68 ->ad::fw::TaskBase::setULcdCameraInfoBase (MainMenu)
//   size 0x4 | file MainMenu+0xb68 | callers(1) 0x15021dac
// veneer/thunk -> 0x0010b438 ad::fw::TaskBase::setULcdCameraInfoBase (static)

// FUNC 0x15000b70 ->ad::h3d::Scene::updateLight (MainMenu)
//   size 0x4 | file MainMenu+0xb70 | callers(1) 0x15021dac
// veneer/thunk -> 0x0015760c ad::h3d::Scene::updateLight (static)

// FUNC 0x15000b78 ->msys::MComSys::funcCalcMainNomal (MainMenu)
//   size 0x4 | file MainMenu+0xb78 | callers(1) 0x15021dac
// veneer/thunk -> 0x0032f13c msys::MComSys::funcCalcMainNomal (static)

// FUNC 0x15000b80 ->CtrBtn::get (MainMenu)
//   size 0x4 | file MainMenu+0xb80 | callers(1) 0x15021dac
// veneer/thunk -> 0x003627f0 CtrBtn::get (static)

// FUNC 0x15000b88 ->msys::MComSys::funcDrawLower (MainMenu)
//   size 0x4 | file MainMenu+0xb88 | callers(1) 0x15022038
// veneer/thunk -> 0x0032e2b8 msys::MComSys::funcDrawLower (static)

// FUNC 0x15000b90 ->msys::MComSys::funcDrawUpper (MainMenu)
//   size 0x4 | file MainMenu+0xb90 | callers(1) 0x1502203c
// veneer/thunk -> 0x0032e760 msys::MComSys::funcDrawUpper (static)

// FUNC 0x15000b98 ->msys::MComSys::readLytNum (MainMenu)
//   size 0x4 | file MainMenu+0xb98 | callers(1) 0x15022040
// veneer/thunk -> 0x0032db14 msys::MComSys::readLytNum (static)

// FUNC 0x15000ba0 ->ad::fw::TaskBase::readArcFile (MainMenu)
//   size 0x4 | file MainMenu+0xba0 | callers(1) 0x15022040
// veneer/thunk -> 0x00251e8c ad::fw::TaskBase::readArcFile (static)

// FUNC 0x15000ba8 ->MessageSys::GetPath (MainMenu)
//   size 0x4 | file MainMenu+0xba8 | callers(1) 0x15022040
// veneer/thunk -> 0x00132a2c MessageSys::GetPath (static)

// FUNC 0x15000bb0 ->nn::fs::CTR::MPCore::detail::UserFileSystem::TryOpenFile (MainMenu)
//   size 0x4 | file MainMenu+0xbb0 | callers(1) 0x15022040
// veneer/thunk -> 0x0028598c nn::fs::CTR::MPCore::detail::UserFileSystem::TryOpenFile (static)

// FUNC 0x15000bb8 ->nn::fs::detail::FileBase::TryGetSize (MainMenu)
//   size 0x4 | file MainMenu+0xbb8 | callers(3) 0x1502352c 0x15023508 0x15022040
// veneer/thunk -> 0x00286568 nn::fs::detail::FileBase::TryGetSize (static)

// FUNC 0x15000bc0 ->MsgDataAcsrBase::init (MainMenu)
//   size 0x4 | file MainMenu+0xbc0 | callers(1) 0x15022040
// veneer/thunk -> 0x00285b88 MsgDataAcsrBase::init (static)

// FUNC 0x15000bc8 ->msys::MLytNumRes::init (MainMenu)
//   size 0x4 | file MainMenu+0xbc8 | callers(1) 0x15022040
// veneer/thunk -> 0x003240f4 msys::MLytNumRes::init (static)

// FUNC 0x15000bd0 ->Frm::setSpd (MainMenu)
//   size 0x4 | file MainMenu+0xbd0 | callers(1) 0x15022040
// veneer/thunk -> 0x0027a2a4 Frm::setSpd (static)

// FUNC 0x15000bd8 ->msys::MMapIconMan::init (MainMenu)
//   size 0x4 | file MainMenu+0xbd8 | callers(1) 0x15022040
// veneer/thunk -> 0x00324930 msys::MMapIconMan::init (static)

// FUNC 0x15000be0 ->ad::guide::Man::Init (MainMenu)
//   size 0x4 | file MainMenu+0xbe0 | callers(1) 0x15022eb0
// veneer/thunk -> 0x0016a37c ad::guide::Man::Init (static)

// FUNC 0x15000be8 ->msys::MComSys::initBaseSys (MainMenu)
//   size 0x4 | file MainMenu+0xbe8 | callers(1) 0x15022eb0
// veneer/thunk -> 0x0032db84 msys::MComSys::initBaseSys (static)

// FUNC 0x15000bf0 ->msys::MComSys::entryPage (MainMenu)
//   size 0x4 | file MainMenu+0xbf0 | callers(1) 0x15022eb0
// veneer/thunk -> 0x0032f548 msys::MComSys::entryPage (static)

// FUNC 0x15000bf8 ->CtrJobMan::enqueue (MainMenu)
//   size 0x4 | file MainMenu+0xbf8 | callers(1) 0x15022eb0
// veneer/thunk -> 0x0026dbe8 CtrJobMan::enqueue (static)

// FUNC 0x15000c00 ->Prim::disableDepthTest (MainMenu)
//   size 0x4 | file MainMenu+0xc00 | callers(1) 0x15022eb0
// veneer/thunk -> 0x00271c98 Prim::disableDepthTest (static)

// FUNC 0x15000c08 ->msys::MComSys::setupCamU (MainMenu)
//   size 0x4 | file MainMenu+0xc08 | callers(1) 0x15022eb0
// veneer/thunk -> 0x0032f674 msys::MComSys::setupCamU (static)

// FUNC 0x15000c10 ->msys::MComSys::setupCamL (MainMenu)
//   size 0x4 | file MainMenu+0xc10 | callers(1) 0x15022eb0
// veneer/thunk -> 0x0032f570 msys::MComSys::setupCamL (static)

// FUNC 0x15000c18 ->DataPc::init (MainMenu)
//   size 0x4 | file MainMenu+0xc18 | callers(1) 0x15022eb0
// veneer/thunk -> 0x0033bbdc DataPc::init (static)

// FUNC 0x15000c20 ->msys::MComSys::MComSys (MainMenu)
//   size 0x4 | file MainMenu+0xc20 | callers(1) 0x150231f4
// veneer/thunk -> 0x0032f7a4 msys::MComSys::MComSys (static)

// FUNC 0x15000c28 ->menu_map::ParamMapPlacePos::ParamMapPlacePos (MainMenu)
//   size 0x4 | file MainMenu+0xc28 | callers(1) 0x150231f4
// veneer/thunk -> 0x0033f3e8 menu_map::ParamMapPlacePos::ParamMapPlacePos (static)

// FUNC 0x15000c30 ->DataPcEquipFxParam::DataPcEquipFxParam (MainMenu)
//   size 0x4 | file MainMenu+0xc30 | callers(1) 0x150231f4
// veneer/thunk -> 0x0027cb24 DataPcEquipFxParam::DataPcEquipFxParam (static)

// FUNC 0x15000c38 ->MsgDataAcsrBase::MsgDataAcsrBase (MainMenu)
//   size 0x4 | file MainMenu+0xc38 | callers(1) 0x150231f4
// veneer/thunk -> 0x0024b3b8 MsgDataAcsrBase::MsgDataAcsrBase (static)

// FUNC 0x15000c40 ->FrameBuf::setClearColor (MainMenu)
//   size 0x4 | file MainMenu+0xc40 | callers(1) 0x150231f4
// veneer/thunk -> 0x0024c8d4 FrameBuf::setClearColor (static)

// FUNC 0x15000c48 ->msys::MLyt::isEnableAnime (MainMenu)
//   size 0x4 | file MainMenu+0xc48 | callers(1) 0x150235f8
// veneer/thunk -> 0x0032bc6c msys::MLyt::isEnableAnime (static)

// FUNC 0x15000c50 ->ad::fw::FileContext::initSingleFile (MainMenu)
//   size 0x4 | file MainMenu+0xc50 | callers(1) 0x15023860
// veneer/thunk -> 0x0013ad54 ad::fw::FileContext::initSingleFile (static)

// FUNC 0x15000c58 ->ad::fw::FileContext::initArcFile (MainMenu)
//   size 0x4 | file MainMenu+0xc58 | callers(1) 0x15023860
// veneer/thunk -> 0x0013aca8 ad::fw::FileContext::initArcFile (static)

// FUNC 0x15000c60 ->ad::fw::FileContext::initCAArcFile (MainMenu)
//   size 0x4 | file MainMenu+0xc60 | callers(1) 0x15023860
// veneer/thunk -> 0x0013acc0 ad::fw::FileContext::initCAArcFile (static)

// FUNC 0x15000c68 MainMenu::EntryTask (MainMenu)
//   size 0x34 | file MainMenu+0xc68 | callers(0)

void MainMenu::EntryTask(void)

{
  void *pvVar1;
  Task *pTVar2;
  
  pvVar1 = operator_new(0xf26c4,gMemAlc,(char *)0x0,0);
  pTVar2 = (Task *)0x0;
  if (pvVar1 != (void *)0x0) {
    pTVar2 = (Task *)FUN_15001354();
  }
  TaskMan::entry((TaskMan *)&gTaskMainMan,pTVar2);
  return;
}


// FUNC 0x15000ca8 MemAlcH::vfunc_0x0 (MainMenu)
//   size 0x8 | file MainMenu+0xca8 | callers(0) | datarefs 1

undefined4 MemAlcH::vfunc_0x0(void)

{
  return 0;
}


// FUNC 0x15000cb0 FUN_15000cb0 (MainMenu)
//   size 0x10 | file MainMenu+0xcb0 | callers(0) | datarefs 1

void FUN_15000cb0(MsgDataAcsrBase *param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)MsgDataAcsrBase::~MsgDataAcsrBase(param_1);
  operator_delete(pvVar1);
  return;
}


// FUNC 0x15000cc0 ->MsgDataAcsrBase::~MsgDataAcsrBase (MainMenu)
//   size 0x4 | file MainMenu+0xcc0 | callers(0) | datarefs 1
// veneer/thunk -> 0x0026fdb4 MsgDataAcsrBase::~MsgDataAcsrBase (static)

// FUNC 0x15000cc4 FUN_15000cc4 (MainMenu)
//   size 0xc | file MainMenu+0xcc4 | callers(0) | datarefs 1

void FUN_15000cc4(int *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x15000ccc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x14))();
  return;
}


// FUNC 0x15000cd0 main_menu::MainMenuTask::vfunc_0x1c (MainMenu)
//   size 0x4 | file MainMenu+0xcd0 | callers(0) | datarefs 1

void main_menu::MainMenuTask::vfunc_0x1c(void)

{
  return;
}


// FUNC 0x15000cd4 main_menu::MainMenuTask::vfunc_0x4c (MainMenu)
//   size 0x8 | file MainMenu+0xcd4 | callers(0) | datarefs 1

undefined4 * main_menu::MainMenuTask::vfunc_0x4c(void)

{
  return &gFrameBuf;
}


// FUNC 0x15000ce0 main_menu::MainMenuTask::vfunc_0x3c (MainMenu)
//   size 0x4 | file MainMenu+0xce0 | callers(0) | datarefs 1

void main_menu::MainMenuTask::vfunc_0x3c(void)

{
  return;
}


// FUNC 0x15000ce4 main_menu::MainMenuTask::vfunc_0x40 (MainMenu)
//   size 0x4 | file MainMenu+0xce4 | callers(0) | datarefs 1

void main_menu::MainMenuTask::vfunc_0x40(void)

{
  return;
}


// FUNC 0x15000ce8 main_menu::MainMenuTask::vfunc_0x30 (MainMenu)
//   size 0x4 | file MainMenu+0xce8 | callers(0) | datarefs 1

void main_menu::MainMenuTask::vfunc_0x30(void)

{
  return;
}


// FUNC 0x15000cec main_menu::MainMenuTask::vfunc_0x20 (MainMenu)
//   size 0x4 | file MainMenu+0xcec | callers(0) | datarefs 1

void main_menu::MainMenuTask::vfunc_0x20(void)

{
  return;
}


// FUNC 0x15000cf0 main_menu::MainMenuTask::vfunc_0x38 (MainMenu)
//   size 0x4 | file MainMenu+0xcf0 | callers(0) | datarefs 1

void main_menu::MainMenuTask::vfunc_0x38(void)

{
  return;
}


// FUNC 0x15000cf4 main_menu::MainMenuTask::vfunc_0x28 (MainMenu)
//   size 0x4 | file MainMenu+0xcf4 | callers(0) | datarefs 1

void main_menu::MainMenuTask::vfunc_0x28(void)

{
  return;
}


// FUNC 0x15000cf8 msys::MListWndPCore::vfunc_0x1c (MainMenu)
//   size 0x20 | file MainMenu+0xcf8 | callers(0) | datarefs 1

void msys::MListWndPCore::vfunc_0x1c(int *param_1,undefined4 param_2,undefined4 *param_3)

{
  (**(code **)(*param_1 + 0x18))(param_1,param_2,*param_3,param_3[1],param_3[2]);
  return;
}


// FUNC 0x15000d28 ->operator.delete (MainMenu)
//   size 0x4 | file MainMenu+0xd28 | callers(0) | datarefs 1
// veneer/thunk -> 0x00286514 operator.delete (static)

// FUNC 0x15000d2c nn::fs::IInputStream::vfunc_0x0 (MainMenu)
//   size 0x4 | file MainMenu+0xd2c | callers(0) | datarefs 1

void nn::fs::IInputStream::vfunc_0x0(void)

{
  return;
}


// FUNC 0x15000d30 nn::fs::FileInputStream::vfunc_0x1c (MainMenu)
//   size 0x24 | file MainMenu+0xd30 | callers(0) | datarefs 1

void nn::fs::FileInputStream::vfunc_0x1c(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = detail::FileBase::TrySetPosition(CONCAT44(param_2,param_1 + 4));
  if (iVar1 < 0) {
    err::CTR::ThrowFatalErrAll(iVar1,0x15000d44);
    return;
  }
  return;
}


// FUNC 0x15000d54 nn::fs::FileInputStream::vfunc_0x18 (MainMenu)
//   size 0x8 | file MainMenu+0xd54 | callers(0) | datarefs 1

void nn::fs::FileInputStream::vfunc_0x18(int param_1,undefined4 param_2)

{
  detail::FileBase::TrySetPosition(CONCAT44(param_2,param_1 + 4));
  return;
}


// FUNC 0x15000d5c nn::fs::FileInputStream::vfunc_0x2c (MainMenu)
//   size 0x2c | file MainMenu+0xd5c | callers(0) | datarefs 1

int nn::fs::FileInputStream::vfunc_0x2c(int param_1,void *param_2,uint param_3,int param_4)

{
  int iVar1;
  int local_8;
  
  local_8 = param_4;
  iVar1 = detail::FileBase::TryRead((FileBase *)(param_1 + 4),&local_8,param_2,param_3);
  if (iVar1 < 0) {
    err::CTR::ThrowFatalErrAll(iVar1,0x15000d7c);
  }
  return local_8;
}


// FUNC 0x15000d88 nn::fs::FileInputStream::vfunc_0xc (MainMenu)
//   size 0x2c | file MainMenu+0xd88 | callers(0) | datarefs 1

void nn::fs::FileInputStream::vfunc_0xc(int param_1)

{
  int iVar1;
  undefined4 in_stack_00000000;
  
  iVar1 = detail::FileBase::TrySeek(param_1 + 4);
  if (-(iVar1 >> 0x1f) == 0) {
    return;
  }
  err::CTR::ThrowFatalErrAll(iVar1,0x15000da4,-(iVar1 >> 0x1f),in_stack_00000000);
  return;
}


// FUNC 0x15000db4 nn::fs::FileInputStream::vfunc_0x28 (MainMenu)
//   size 0x8 | file MainMenu+0xdb4 | callers(0) | datarefs 1

void nn::fs::FileInputStream::vfunc_0x28(int param_1,int *param_2,void *param_3,uint param_4)

{
  detail::FileBase::TryRead((FileBase *)(param_1 + 4),param_2,param_3,param_4);
  return;
}


// FUNC 0x15000dbc nn::fs::FileInputStream::vfunc_0x8 (MainMenu)
//   size 0x18 | file MainMenu+0xdbc | callers(0) | datarefs 1

void nn::fs::FileInputStream::vfunc_0x8(int param_1)

{
  detail::FileBase::TrySeek(param_1 + 4);
  return;
}


// FUNC 0x15000dd4 nn::fs::FileInputStream::vfunc_0x4 (MainMenu)
//   size 0x40 | file MainMenu+0xdd4 | callers(0) | datarefs 1

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


// FUNC 0x15000e14 nn::fs::FileInputStream::vfunc_0x0 (MainMenu)
//   size 0x3c | file MainMenu+0xe14 | callers(0) | datarefs 1

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


// FUNC 0x15000e90 main_menu::MainMenuTask::vfunc_0xc (MainMenu)
//   size 0xc | file MainMenu+0xe90 | callers(0) | datarefs 1

void main_menu::MainMenuTask::vfunc_0xc(int *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x15000e98. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 8))();
  return;
}


// FUNC 0x15000ebc msys::MChrBase::vfunc_0x10 (MainMenu)
//   size 0xc | file MainMenu+0xebc | callers(0) | datarefs 1

void msys::MChrBase::vfunc_0x10(int param_1)

{
  *(undefined1 *)(param_1 + 0x142) = 0;
  return;
}


// FUNC 0x15000ec8 FUN_15000ec8 (MainMenu)
//   size 0x4 | file MainMenu+0xec8 | callers(0) | datarefs 2

void FUN_15000ec8(void)

{
  return;
}


// FUNC 0x15000ecc msys::MChrBase::vfunc_0x8 (MainMenu)
//   size 0xc | file MainMenu+0xecc | callers(0) | datarefs 1

void msys::MChrBase::vfunc_0x8(int param_1)

{
  *(undefined1 *)(param_1 + 0x142) = 1;
  return;
}


// FUNC 0x15000ed8 FUN_15000ed8 (MainMenu)
//   size 0x4 | file MainMenu+0xed8 | callers(0) | datarefs 16

void FUN_15000ed8(void)

{
  return;
}


// FUNC 0x15000edc msys::MListWndPCore::vfunc_0x30 (MainMenu)
//   size 0x2c | file MainMenu+0xedc | callers(0) | datarefs 1

void msys::MListWndPCore::vfunc_0x30(void)

{
  FUN_1501580c(MComSys::_sys + 0x49368,0x110015,0,0,0);
  return;
}


// FUNC 0x15000f10 msys::MListWndPCore::vfunc_0x2c (MainMenu)
//   size 0x2c | file MainMenu+0xf10 | callers(0) | datarefs 1

void msys::MListWndPCore::vfunc_0x2c(void)

{
  FUN_1501580c(MComSys::_sys + 0x49368,0x110015,0,0,0);
  return;
}


// FUNC 0x15000f44 msys::MListWndPCore::vfunc_0x34 (MainMenu)
//   size 0x2c | file MainMenu+0xf44 | callers(0) | datarefs 1

void msys::MListWndPCore::vfunc_0x34(void)

{
  FUN_1501580c(MComSys::_sys + 0x49368,0x110015,0,0,0);
  return;
}


// FUNC 0x15000f78 msys::MListWndPCore::vfunc_0x38 (MainMenu)
//   size 0x2c | file MainMenu+0xf78 | callers(0) | datarefs 1

void msys::MListWndPCore::vfunc_0x38(void)

{
  FUN_1501580c(MComSys::_sys + 0x49368,0x110015,0,0,0);
  return;
}


// FUNC 0x15000fac msys::MListWndPCore::vfunc_0x3c (MainMenu)
//   size 0x2c | file MainMenu+0xfac | callers(0) | datarefs 1

void msys::MListWndPCore::vfunc_0x3c(void)

{
  FUN_1501580c(MComSys::_sys + 0x49368,0x110018,0,0,0);
  return;
}


// FUNC 0x15000fe0 msys::MListWndPCore::vfunc_0x44 (MainMenu)
//   size 0x10 | file MainMenu+0xfe0 | callers(0) | datarefs 1

void msys::MListWndPCore::vfunc_0x44(UIListWindowPlusLyt *param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)ad::ui::UIListWindowPlusLyt::~UIListWindowPlusLyt(param_1);
  operator_delete(pvVar1);
  return;
}


// FUNC 0x15000ff0 ->ad::ui::UIListWindowPlusLyt::~UIListWindowPlusLyt (MainMenu)
//   size 0x4 | file MainMenu+0xff0 | callers(0) | datarefs 1
// veneer/thunk -> 0x0025a3fc ad::ui::UIListWindowPlusLyt::~UIListWindowPlusLyt (static)

// FUNC 0x15000ff4 FUN_15000ff4 (MainMenu)
//   size 0x20 | file MainMenu+0xff4 | callers(0) | datarefs 1

void FUN_15000ff4(undefined4 *param_1)

{
  int iVar1;
  void *pvVar2;
  
  *param_1 = &vtable_for_N4msys17MListWndPFractionILi32EEE;
  iVar1 = ad::ui::UIListWindowPlusLyt::~UIListWindowPlusLyt((UIListWindowPlusLyt *)(param_1 + 0x7f))
  ;
  pvVar2 = (void *)msys::MListWndPBase::~MListWndPBase((MListWndPBase *)(iVar1 + -0x1fc));
  operator_delete(pvVar2);
  return;
}


// FUNC 0x15001018 FUN_15001018 (MainMenu)
//   size 0x1c | file MainMenu+0x1018 | callers(0) | datarefs 1

void FUN_15001018(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &vtable_for_N4msys17MListWndPFractionILi32EEE;
  iVar1 = ad::ui::UIListWindowPlusLyt::~UIListWindowPlusLyt((UIListWindowPlusLyt *)(param_1 + 0x7f))
  ;
  msys::MListWndPBase::~MListWndPBase((MListWndPBase *)(iVar1 + -0x1fc));
  return;
}


// FUNC 0x15001038 main_menu::MainMenu_StatusPage::Core::ExpMsgWnd::vfunc_0x20 (MainMenu)
//   size 0x8 | file MainMenu+0x1038 | callers(0) | datarefs 1

undefined4 main_menu::MainMenu_StatusPage::Core::ExpMsgWnd::vfunc_0x20(void)

{
  return 0;
}


// FUNC 0x15001040 main_menu::MainMenu_StatusPage::Core::ExpMsgWnd::vfunc_0x8 (MainMenu)
//   size 0x5c | file MainMenu+0x1040 | callers(0) | datarefs 1

void main_menu::MainMenu_StatusPage::Core::ExpMsgWnd::vfunc_0x8(float param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_2 + 0x24))(param_2);
  if (iVar1 != 0) {
    MoveVBase::update((MoveVBase *)(param_2 + 5),param_1);
    MoveVBase::update((MoveVBase *)(param_2 + 0x1c),param_1);
    MoveVBase::update((MoveVBase *)(param_2 + 0x33),param_1);
  }
  *(undefined1 *)((int)param_2 + 0x142) = 1;
  return;
}


// FUNC 0x1500109c main_menu::MainMenu_StatusPage::Core::ExpMsgWnd::vfunc_0x38 (MainMenu)
//   size 0x4 | file MainMenu+0x109c | callers(0) | datarefs 1

void main_menu::MainMenu_StatusPage::Core::ExpMsgWnd::vfunc_0x38(void)

{
  return;
}


// FUNC 0x150010a0 main_menu::MainMenu_StatusPage::Core::ExpMsgWnd::vfunc_0x14 (MainMenu)
//   size 0x2c | file MainMenu+0x10a0 | callers(0) | datarefs 1

void main_menu::MainMenu_StatusPage::Core::ExpMsgWnd::vfunc_0x14
               (int param_1,MRenderQueueBase *param_2)

{
  if (*(char *)(param_1 + 0x141) == '\0') {
    return;
  }
  msys::MRenderQueueBase::enqueueMsg
            (param_2,(MessageSimple *)(param_1 + 0x14c),*(uint *)(param_1 + 0x6c40),'\n');
  return;
}


// FUNC 0x150010d0 FUN_150010d0 (MainMenu)
//   size 0x2c | file MainMenu+0x10d0 | callers(0) | datarefs 2

void FUN_150010d0(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar1 = MessageSimple::~MessageSimple((MessageSimple *)(param_1 + 0x53));
  msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  return;
}


// FUNC 0x15001100 main_menu::MainMenu::vfunc_0x14 (MainMenu)
//   size 0x8 | file MainMenu+0x1100 | callers(0) | datarefs 1

undefined4 main_menu::MainMenu::vfunc_0x14(void)

{
  return 0;
}


// FUNC 0x15001108 msys::MChrBase::vfunc_0x4 (MainMenu)
//   size 0x10 | file MainMenu+0x1108 | callers(0) | datarefs 1

void msys::MChrBase::vfunc_0x4(void)

{
  void *pvVar1;
  
  pvVar1 = (void *)vfunc_0x0();
  operator_delete(pvVar1);
  return;
}


// FUNC 0x15001118 FUN_15001118 (MainMenu)
//   size 0x20 | file MainMenu+0x1118 | callers(0) | datarefs 1

void FUN_15001118(undefined4 *param_1)

{
  int iVar1;
  void *pvVar2;
  
  *param_1 = &vtable_for_N4msys9MListWndPILi128EEE;
  iVar1 = ad::ui::UIListWindowPlusLyt::~UIListWindowPlusLyt((UIListWindowPlusLyt *)(param_1 + 0x7f))
  ;
  pvVar2 = (void *)msys::MListWndPBase::~MListWndPBase((MListWndPBase *)(iVar1 + -0x1fc));
  operator_delete(pvVar2);
  return;
}


// FUNC 0x1500113c FUN_1500113c (MainMenu)
//   size 0x1c | file MainMenu+0x113c | callers(0) | datarefs 1

void FUN_1500113c(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &vtable_for_N4msys9MListWndPILi128EEE;
  iVar1 = ad::ui::UIListWindowPlusLyt::~UIListWindowPlusLyt((UIListWindowPlusLyt *)(param_1 + 0x7f))
  ;
  msys::MListWndPBase::~MListWndPBase((MListWndPBase *)(iVar1 + -0x1fc));
  return;
}


// FUNC 0x1500115c FUN_1500115c (MainMenu)
//   size 0x20 | file MainMenu+0x115c | callers(0) | datarefs 1

void FUN_1500115c(undefined4 *param_1)

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


// FUNC 0x15001180 FUN_15001180 (MainMenu)
//   size 0x1c | file MainMenu+0x1180 | callers(0) | datarefs 1

void FUN_15001180(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &vtable_for_N4msys9MListWndPILi256EEE;
  iVar1 = ad::ui::UIListWindowPlusLyt::~UIListWindowPlusLyt((UIListWindowPlusLyt *)(param_1 + 0x7f))
  ;
  msys::MListWndPBase::~MListWndPBase((MListWndPBase *)(iVar1 + -0x1fc));
  return;
}


// FUNC 0x150011a0 FUN_150011a0 (MainMenu)
//   size 0x20 | file MainMenu+0x11a0 | callers(0) | datarefs 1

void FUN_150011a0(undefined4 *param_1)

{
  int iVar1;
  void *pvVar2;
  
  *param_1 = &vtable_for_N4msys9MListWndPILi56EEE;
  iVar1 = ad::ui::UIListWindowPlusLyt::~UIListWindowPlusLyt((UIListWindowPlusLyt *)(param_1 + 0x7f))
  ;
  pvVar2 = (void *)msys::MListWndPBase::~MListWndPBase((MListWndPBase *)(iVar1 + -0x1fc));
  operator_delete(pvVar2);
  return;
}


// FUNC 0x150011c4 FUN_150011c4 (MainMenu)
//   size 0x1c | file MainMenu+0x11c4 | callers(0) | datarefs 1

void FUN_150011c4(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &vtable_for_N4msys9MListWndPILi56EEE;
  iVar1 = ad::ui::UIListWindowPlusLyt::~UIListWindowPlusLyt((UIListWindowPlusLyt *)(param_1 + 0x7f))
  ;
  msys::MListWndPBase::~MListWndPBase((MListWndPBase *)(iVar1 + -0x1fc));
  return;
}


// FUNC 0x150011e4 FUN_150011e4 (MainMenu)
//   size 0x20 | file MainMenu+0x11e4 | callers(0) | datarefs 1

void FUN_150011e4(undefined4 *param_1)

{
  int iVar1;
  void *pvVar2;
  
  *param_1 = &vtable_for_N4msys9MListWndPILi64EEE;
  iVar1 = ad::ui::UIListWindowPlusLyt::~UIListWindowPlusLyt((UIListWindowPlusLyt *)(param_1 + 0x7f))
  ;
  pvVar2 = (void *)msys::MListWndPBase::~MListWndPBase((MListWndPBase *)(iVar1 + -0x1fc));
  operator_delete(pvVar2);
  return;
}


// FUNC 0x15001208 FUN_15001208 (MainMenu)
//   size 0x1c | file MainMenu+0x1208 | callers(0) | datarefs 1

void FUN_15001208(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &vtable_for_N4msys9MListWndPILi64EEE;
  iVar1 = ad::ui::UIListWindowPlusLyt::~UIListWindowPlusLyt((UIListWindowPlusLyt *)(param_1 + 0x7f))
  ;
  msys::MListWndPBase::~MListWndPBase((MListWndPBase *)(iVar1 + -0x1fc));
  return;
}


// FUNC 0x15001228 FUN_15001228 (MainMenu)
//   size 0x20 | file MainMenu+0x1228 | callers(0) | datarefs 1

void FUN_15001228(undefined4 *param_1)

{
  int iVar1;
  void *pvVar2;
  
  *param_1 = &vtable_for_N4msys9MListWndPILi6EEE;
  iVar1 = ad::ui::UIListWindowPlusLyt::~UIListWindowPlusLyt((UIListWindowPlusLyt *)(param_1 + 0x7f))
  ;
  pvVar2 = (void *)msys::MListWndPBase::~MListWndPBase((MListWndPBase *)(iVar1 + -0x1fc));
  operator_delete(pvVar2);
  return;
}


// FUNC 0x1500124c FUN_1500124c (MainMenu)
//   size 0x1c | file MainMenu+0x124c | callers(0) | datarefs 1

void FUN_1500124c(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &vtable_for_N4msys9MListWndPILi6EEE;
  iVar1 = ad::ui::UIListWindowPlusLyt::~UIListWindowPlusLyt((UIListWindowPlusLyt *)(param_1 + 0x7f))
  ;
  msys::MListWndPBase::~MListWndPBase((MListWndPBase *)(iVar1 + -0x1fc));
  return;
}


// FUNC 0x1500126c main_menu::MainMenuPageBase::vfunc_0x20 (MainMenu)
//   size 0x8 | file MainMenu+0x126c | callers(0) | datarefs 9

void main_menu::MainMenuPageBase::vfunc_0x20
               (MPageBase *param_1,undefined4 param_2,MRenderQueue *param_3)

{
  msys::MPageBase::enqueueLowerChr(param_1,param_3);
  return;
}


// FUNC 0x15001274 main_menu::MainMenuPageBase::vfunc_0x1c (MainMenu)
//   size 0x8 | file MainMenu+0x1274 | callers(0) | datarefs 9

void main_menu::MainMenuPageBase::vfunc_0x1c
               (MPageBase *param_1,undefined4 param_2,MRenderQueue *param_3)

{
  msys::MPageBase::enqueueUpperChr(param_1,param_3);
  return;
}


// FUNC 0x1500127c FUN_1500127c (MainMenu)
//   size 0x34 | file MainMenu+0x127c | callers(0) | datarefs 1

void FUN_1500127c(MoveVBase *param_1)

{
  void *pvVar1;
  
  *(undefined ***)param_1 = &vtable_for_5MoveVILj1EE;
  __aeabi_vec_dtor(param_1 + 0x30,MoveWorkF::~MoveWorkF,0x2c,1);
  pvVar1 = (void *)MoveVBase::~MoveVBase(param_1);
  operator_delete(pvVar1);
  return;
}


// FUNC 0x150012b8 FUN_150012b8 (MainMenu)
//   size 0x30 | file MainMenu+0x12b8 | callers(0) | datarefs 1

void FUN_150012b8(MoveVBase *param_1)

{
  *(undefined ***)param_1 = &vtable_for_5MoveVILj1EE;
  __aeabi_vec_dtor(param_1 + 0x30,MoveWorkF::~MoveWorkF,0x2c,1);
  MoveVBase::~MoveVBase(param_1);
  return;
}


// FUNC 0x150012f0 FUN_150012f0 (MainMenu)
//   size 0x2c | file MainMenu+0x12f0 | callers(0) | datarefs 6

undefined4 * FUN_150012f0(MoveWorkF *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)MoveWorkF::MoveWorkF(param_1);
  *puVar1 = &MoveWorkV::vtable;
  puVar1[8] = 0;
  puVar1[9] = 0;
  puVar1[10] = 0;
  return puVar1;
}


// FUNC 0x15001324 MoveWorkV::vfunc_0x4 (MainMenu)
//   size 0x10 | file MainMenu+0x1324 | callers(0) | datarefs 1

void MoveWorkV::vfunc_0x4(MoveWorkF *param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)MoveWorkF::~MoveWorkF(param_1);
  operator_delete(pvVar1);
  return;
}


// FUNC 0x15001334 ->MoveWorkF::~MoveWorkF (MainMenu)
//   size 0x4 | file MainMenu+0x1334 | callers(0) | datarefs 15
// veneer/thunk -> 0x00340694 MoveWorkF::~MoveWorkF (static)

// FUNC 0x15001338 main_menu::MainMenuTask::vfunc_0x10 (MainMenu)
//   size 0x1c | file MainMenu+0x1338 | callers(0) | datarefs 1

void main_menu::MainMenuTask::vfunc_0x10(TaskMainBase *param_1)

{
  if (*(char *)(*(int *)(param_1 + 0x580) + 0xe9049) == '\0') {
    return;
  }
  GameMain::Back(param_1);
  return;
}


// FUNC 0x15001354 FUN_15001354 (MainMenu)
//   size 0x38 | file MainMenu+0x1354 | callers(1) 0x15000c68

int FUN_15001354(MTaskBase *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)msys::MTaskBase::MTaskBase(param_1);
  *puVar1 = &main_menu::MainMenuTask::vtable;
  iVar2 = FUN_150231f4(puVar1 + 0x161);
  FUN_15022eb0(iVar2,iVar2 + -0x584);
  *(int *)(iVar2 + -4) = iVar2;
  return iVar2 + -0x584;
}


// FUNC 0x15001390 main_menu::MainMenuTask::vfunc_0x8 (MainMenu)
//   size 0x24 | file MainMenu+0x1390 | callers(0) | datarefs 1

void main_menu::MainMenuTask::vfunc_0x8(undefined4 *param_1)

{
  int iVar1;
  void *pvVar2;
  
  *param_1 = &vtable;
  iVar1 = MainMenu::vfunc_0x0(param_1 + 0x161);
  pvVar2 = (void *)ad::fw::TaskBase::~TaskBase((TaskBase *)(iVar1 + -0x584));
  operator_delete(pvVar2);
  return;
}


// FUNC 0x150013b8 main_menu::MainMenuTask::vfunc_0x4 (MainMenu)
//   size 0x20 | file MainMenu+0x13b8 | callers(0) | datarefs 1

void main_menu::MainMenuTask::vfunc_0x4(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &vtable;
  iVar1 = MainMenu::vfunc_0x0(param_1 + 0x161);
  ad::fw::TaskBase::~TaskBase((TaskBase *)(iVar1 + -0x584));
  return;
}


// FUNC 0x150013f0 main_menu::MainMenuPageBase::Core::vfunc_0x8 (MainMenu)
//   size 0xe4 | file MainMenu+0x13f0 | callers(0) | datarefs 4

int main_menu::MainMenuPageBase::Core::vfunc_0x8(int *param_1,MInput *param_2)

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
  return (int)*(char *)((int)param_1 + 0x865);
}


// FUNC 0x150014d8 main_menu::MainMenuPageBase::Core::vfunc_0x4 (MainMenu)
//   size 0x10 | file MainMenu+0x14d8 | callers(0) | datarefs 1

void main_menu::MainMenuPageBase::Core::vfunc_0x4(void)

{
  void *pvVar1;
  
  pvVar1 = (void *)vfunc_0x0();
  operator_delete(pvVar1);
  return;
}


// FUNC 0x150014e8 main_menu::MainMenuPageBase::vfunc_0x28 (MainMenu)
//   size 0x14 | file MainMenu+0x14e8 | callers(0) | datarefs 9

int main_menu::MainMenuPageBase::vfunc_0x28(int param_1,int param_2)

{
  return *(int *)(param_1 + 0x20) + param_2 * 4 + 0xc;
}


// FUNC 0x150014fc main_menu::MainMenuPageBase::vfunc_0x8 (MainMenu)
//   size 0x6c | file MainMenu+0x14fc | callers(0) | datarefs 9

void main_menu::MainMenuPageBase::vfunc_0x8(int *param_1,undefined1 param_2)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  if (param_1[8] == 0) {
    (**(code **)(*param_1 + 0x2c))(param_1);
    (**(code **)(*param_1 + 0x30))(param_1);
    *(undefined1 *)(param_1[8] + 0x864) = param_2;
  }
  iVar1 = param_1[8];
  if ((*(uint *)(iVar1 + 0x14) & 1) == 0) {
    UNRECOVERED_JUMPTABLE = *(code **)(iVar1 + 0x10);
  }
  else {
    UNRECOVERED_JUMPTABLE =
         *(code **)(*(int *)(iVar1 + ((int)*(uint *)(iVar1 + 0x14) >> 1)) + *(int *)(iVar1 + 0x10));
  }
                    /* WARNING: Could not recover jumptable at 0x15001564. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// FUNC 0x15001568 main_menu::MainMenuPageBase::vfunc_0x14 (MainMenu)
//   size 0x10 | file MainMenu+0x1568 | callers(0) | datarefs 9

void main_menu::MainMenuPageBase::vfunc_0x14(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x15001574. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(param_1 + 0x20) + 8))();
  return;
}


// FUNC 0x15001578 main_menu::MainMenuPageBase::vfunc_0xc (MainMenu)
//   size 0xd8 | file MainMenu+0x1578 | callers(0) | datarefs 9

void main_menu::MainMenuPageBase::vfunc_0xc(int param_1)

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


// FUNC 0x15001650 main_menu::MainMenuPageBase::vfunc_0x4 (MainMenu)
//   size 0x10 | file MainMenu+0x1650 | callers(0) | datarefs 1

void main_menu::MainMenuPageBase::vfunc_0x4(void)

{
  void *pvVar1;
  
  pvVar1 = (void *)vfunc_0x0();
  operator_delete(pvVar1);
  return;
}


// FUNC 0x15001660 FUN_15001660 (MainMenu)
//   size 0x7c | file MainMenu+0x1660 | callers(0)

void FUN_15001660(int *param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    iVar1 = msys::MLyt::getParts
                      ((MLyt *)(*param_1 + 0x4b8),(char *)(&DAT_150361f8)[uVar2],(char *)0x0,
                       (char *)0x0);
    ad::lyt::LytAnim::init
              ((LytAnim *)(param_1 + uVar2 * 7 + 5),*(Layout **)(iVar1 + 0xac),"2to3","");
    ad::lyt::LytAnim::playAuto((LytAnim *)(param_1 + uVar2 * 7 + 5),1.0);
    uVar2 = uVar2 + 1 & 0xff;
  } while (uVar2 < 6);
  *(undefined2 *)((int)param_1 + 6) = 0x32;
  return;
}


// FUNC 0x150016f0 FUN_150016f0 (MainMenu)
//   size 0x394 | file MainMenu+0x16f0 | callers(1) 0x15001c48

void FUN_150016f0(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  Layout *pLVar6;
  uint in_fpscr;
  float fVar7;
  LytAnim aLStack_48 [4];
  undefined4 local_44;
  undefined4 uStack_40;
  undefined4 local_3c;
  undefined2 local_38;
  undefined2 local_36;
  AnimTransform *local_34;
  
  uVar5 = 0;
  param_1[3] = 2;
  param_1[2] = 0;
  *(undefined2 *)(param_1 + 1) = 0;
  *(undefined2 *)((int)param_1 + 6) = 0;
  *(undefined2 *)(param_1 + 4) = 0;
  do {
    iVar1 = msys::MLyt::getParts
                      ((MLyt *)(*param_1 + 0x4b8),(char *)(&DAT_150361f8)[uVar5],(char *)0x0,
                       (char *)0x0);
    pLVar6 = *(Layout **)(iVar1 + 0xac);
    local_44 = 0;
    uStack_40 = 0x3f800000;
    local_3c = 0;
    local_38 = 1;
    local_36 = 0;
    ad::lyt::LytAnim::init(aLStack_48,pLVar6,(&PTR_s_ICON_ITEM_15036210)[uVar5],"");
    uVar2 = ad::lyt::AnimTransform::GetFrameSize(local_34);
    fVar7 = (float)VectorUnsignedToFloat(uVar2,(byte)(in_fpscr >> 0x16) & 3);
    ad::lyt::LytAnim::stopAndSetFrm(aLStack_48,fVar7);
    ad::lyt::LytAnim::term(aLStack_48,true);
    ad::lyt::LytAnim::init((LytAnim *)(param_1 + uVar5 * 7 + 0x83),pLVar6,"SET_OPEN_cOFF","");
    ad::lyt::LytAnim::init((LytAnim *)(param_1 + uVar5 * 7 + 0x59),pLVar6,"SET_OPEN_cON","");
    ad::lyt::LytAnim::init((LytAnim *)(param_1 + uVar5 * 7 + 0x2f),pLVar6,"1to2","");
    uVar4 = 0;
    do {
      ad::lyt::LytAnim::init
                ((LytAnim *)(param_1 + uVar5 * 0x2a + uVar4 * 7 + 0xad),pLVar6,"TWINCLE",
                 (char *)(&DAT_15036228)[uVar4]);
      uVar4 = uVar4 + 1 & 0xff;
    } while (uVar4 < 6);
    if (*(char *)(*param_1 + 0x864) == -1) {
      if (uVar5 == 0) {
        ad::lyt::LytAnim::init((LytAnim *)(param_1 + 5),pLVar6,"0to1_cON","");
        ad::lyt::LytAnim::stopAndSetFrm((LytAnim *)(param_1 + 5),0.0);
        goto LAB_15001948;
      }
      if (uVar5 != 4) {
LAB_15001918:
        if ((int)*(char *)(*param_1 + 0x864) == (uint)(byte)(&DAT_15024006)[uVar5]) {
          pcVar3 = "0to1_cON";
        }
        else {
          pcVar3 = "0to1_cOFF";
        }
        ad::lyt::LytAnim::init((LytAnim *)(param_1 + uVar5 * 7 + 5),pLVar6,pcVar3,"");
        goto LAB_15001948;
      }
      fVar7 = (float)GetRegFlag(0xd00c,(GlobalEvent *)0x0,(LocalEvent *)0x0);
      in_fpscr = in_fpscr & 0xfffffff;
      if (fVar7 != 0.0) goto LAB_15001918;
      ad::lyt::LytAnim::init(aLStack_48,pLVar6,"SET_CLOSE","");
      uVar2 = ad::lyt::AnimTransform::GetFrameSize(local_34);
      fVar7 = (float)VectorUnsignedToFloat(uVar2,(byte)(in_fpscr >> 0x16) & 3);
      ad::lyt::LytAnim::stopAndSetFrm(aLStack_48,fVar7);
      ad::lyt::LytAnim::term(aLStack_48,true);
      ad::lyt::LytAnim::init(aLStack_48,pLVar6,"0to1_cOFF","");
      ad::lyt::LytAnim::stopAndSetFrm(aLStack_48,0.0);
      ad::lyt::LytAnim::term(aLStack_48,true);
    }
    else {
      if (uVar5 == 4) {
        fVar7 = (float)GetRegFlag(0xd00c,(GlobalEvent *)0x0,(LocalEvent *)0x0);
        in_fpscr = in_fpscr & 0xfffffff;
        if (fVar7 != 0.0) goto LAB_150019d8;
        ad::lyt::LytAnim::init(aLStack_48,pLVar6,"SET_CLOSE","");
        uVar2 = ad::lyt::AnimTransform::GetFrameSize(local_34);
        fVar7 = (float)VectorUnsignedToFloat(uVar2,(byte)(in_fpscr >> 0x16) & 3);
        ad::lyt::LytAnim::stopAndSetFrm(aLStack_48,fVar7);
        ad::lyt::LytAnim::term(aLStack_48,true);
      }
      else {
LAB_150019d8:
        if ((int)*(char *)(*param_1 + 0x864) == (uint)(byte)(&DAT_15024006)[uVar5]) {
          pcVar3 = "0to1_cON";
        }
        else {
          pcVar3 = "0to1_cOFF";
        }
        ad::lyt::LytAnim::init(aLStack_48,pLVar6,pcVar3,"");
        if ((int)*(char *)(*param_1 + 0x864) == (uint)(byte)(&DAT_15024006)[uVar5]) {
          *(short *)(param_1 + 4) = (short)uVar5;
        }
        uVar2 = ad::lyt::AnimTransform::GetFrameSize(local_34);
        fVar7 = (float)VectorUnsignedToFloat(uVar2,(byte)(in_fpscr >> 0x16) & 3);
        ad::lyt::LytAnim::stopAndSetFrm(aLStack_48,fVar7);
        ad::lyt::LytAnim::term(aLStack_48,true);
        uVar2 = ad::lyt::AnimTransform::GetFrameSize((AnimTransform *)param_1[uVar5 * 7 + 0x34]);
        fVar7 = (float)VectorUnsignedToFloat(uVar2,(byte)(in_fpscr >> 0x16) & 3);
        ad::lyt::LytAnim::stopAndSetFrm((LytAnim *)(param_1 + uVar5 * 7 + 0x2f),fVar7);
      }
      ad::lyt::LytAnim::init((LytAnim *)(param_1 + uVar5 * 7 + 5),pLVar6,"3to2","");
LAB_15001948:
      ad::lyt::LytAnim::stopAndSetFrm((LytAnim *)(param_1 + uVar5 * 7 + 5),0.0);
    }
    local_3c = 0;
    uVar5 = uVar5 + 1 & 0xff;
    if (5 < uVar5) {
      return;
    }
  } while( true );
}


// FUNC 0x15001d68 FUN_15001d68 (MainMenu)
//   size 0x1d0 | file MainMenu+0x1d68 | callers(0)

void FUN_15001d68(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  code *pcVar4;
  
  pcVar4 = FUN_1500359c;
  pcVar3 = *(code **)(param_1 + 0x20);
  if (pcVar3 == FUN_1500359c) {
    pcVar4 = *(code **)(param_1 + 0x24);
  }
  if (pcVar3 == FUN_1500359c && pcVar4 == (code *)0x0) {
    if (param_3 != 1) {
      if (param_3 == 4) {
        FUN_1501580c(msys::MComSys::_sys + 0x49368,0x110016,0,0,0);
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
      else if (param_3 == 5) {
        if (*(char *)(param_2 + 0x48) == '\0') {
          msys::MCursorBase::setVisible((MCursorBase *)(param_1 + 0x868),false);
          FUN_15014e10((MCursorBase *)(param_1 + 0x868));
          iVar2 = msys::MComSys::_sys;
          iVar1 = *(int *)(param_1 + 8);
          if (*(int *)(param_1 + 8) == 0) {
            *(int *)(param_1 + 8) = msys::MComSys::_sys;
            iVar1 = iVar2;
          }
          ad::lyt::LytAnim::playAuto((LytAnim *)(iVar1 + 0xe9e44),1.0);
          *(undefined1 *)(param_1 + 0x865) = 7;
          return;
        }
        if (*(char *)(param_2 + 0x48) == '\x01') {
          nngxWaitCmdlistDone();
          nn::applet::CTR::JumpToManual();
          nn::applet::CTR::detail::WaitForStarting(0,0,0,0,0);
          iVar1 = nn::applet::CTR::detail::GetOrderToCloseState();
          if ((iVar1 != 0) || (iVar1 = nn::applet::CTR::IsReceivedWakeupByCancel(), iVar1 != 0)) {
            nn::applet::CTR::detail::CloseApplication(0,0,nn::applet::CTR::HANDLE_NONE);
          }
          *(undefined1 **)(param_1 + 0x20) = &LAB_150034a4;
          *(undefined4 *)(param_1 + 0x24) = 0;
          return;
        }
      }
    }
  }
  else {
    pcVar4 = FUN_15002a9c;
    if (pcVar3 == FUN_15002a9c) {
      pcVar4 = *(code **)(param_1 + 0x24);
    }
    if ((pcVar3 == FUN_15002a9c && pcVar4 == (code *)0x0) && param_3 == 4) {
      FUN_1501580c(msys::MComSys::_sys + 0x49368,0x110018,0,0,0);
      iVar1 = msys::MComSys::_sys;
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
      }
      *(undefined1 *)(*(int *)(param_1 + 8) + 0xe6508) = 0;
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = iVar1;
      }
      *(undefined1 *)(*(int *)(param_1 + 8) + 0xe650a) = 1;
      iVar2 = *(int *)(param_1 + 8);
      if (iVar2 == 0) {
        *(int *)(param_1 + 8) = iVar1;
        iVar2 = iVar1;
      }
      CellAnime::play((CellAnime *)(iVar2 + 0xf2010),'\x14',0,1.0);
      iVar2 = msys::MComSys::_sys;
      iVar1 = *(int *)(param_1 + 8);
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar1 = iVar2;
      }
      FUN_15014558(iVar1,"MES_menu_tuto_badge_change_no_here");
      *(code **)(param_1 + 0x20) = FUN_150033a8;
      *(undefined4 *)(param_1 + 0x24) = 0;
      return;
    }
  }
  return;
}


// FUNC 0x15001f6c FUN_15001f6c (MainMenu)
//   size 0x300 | file MainMenu+0x1f6c | callers(0)

void FUN_15001f6c(int param_1,int param_2,int param_3)

{
  char cVar1;
  byte bVar2;
  MComSys *pMVar3;
  MComSys *pMVar4;
  MCursorBase *this;
  code *pcVar5;
  int iVar6;
  uint uVar7;
  int unaff_lr;
  bool bVar8;
  
  pcVar5 = *(code **)(param_1 + 0x20);
  if (pcVar5 == FUN_1500359c) {
    unaff_lr = *(int *)(param_1 + 0x24);
  }
  iVar6 = param_1 + 0x6c48;
  this = (MCursorBase *)(param_1 + 0x868);
  pMVar3 = msys::MComSys::_sys + 0x49368;
  if (pcVar5 == FUN_1500359c && unaff_lr == 0) {
    bVar2 = *(byte *)(param_2 + 0x48);
    uVar7 = (uint)bVar2;
    if (param_3 != 1) {
      if (param_3 != 4) {
        if (param_3 != 5) {
          return;
        }
        if (*(int *)(param_1 + 8) == 0) {
          *(MComSys **)(param_1 + 8) = msys::MComSys::_sys;
        }
        ad::lyt::LytAnim::playAuto((LytAnim *)(*(int *)(param_1 + 8) + 0xe9e44),1.0);
        *(undefined *)(param_1 + 0x865) = (&DAT_15024000)[uVar7];
        iVar6 = main_menu::GetBootInfo();
        if (*(char *)(iVar6 + 0x2c) == '\0') goto LAB_1500225c;
        pMVar3 = *(MComSys **)(param_1 + 8);
        goto joined_r0x15002070;
      }
      FUN_1501580c(pMVar3,0x110016,0,0,0);
      pMVar4 = msys::MComSys::_sys;
      pMVar3 = *(MComSys **)(param_1 + 8);
      if (*(MComSys **)(param_1 + 8) == (MComSys *)0x0) {
        *(MComSys **)(param_1 + 8) = msys::MComSys::_sys;
        pMVar3 = pMVar4;
      }
      pMVar3[0xe6508] = (MComSys)0x0;
      pMVar4 = msys::MComSys::_sys;
      pMVar3 = *(MComSys **)(param_1 + 8);
      if (*(MComSys **)(param_1 + 8) == (MComSys *)0x0) {
        *(MComSys **)(param_1 + 8) = msys::MComSys::_sys;
        pMVar3 = pMVar4;
      }
      pMVar3[0xe650a] = (MComSys)0x1;
    }
    if (uVar7 != *(byte *)(param_1 + 0x880)) {
      *(byte *)(param_1 + 0x880) = bVar2;
      FUN_15014e10(this);
      FUN_15014da0(iVar6,uVar7);
      FUN_1501580c(msys::MComSys::_sys + 0x49368,0x110015,0,0);
      FUN_15014cc4(param_1);
      return;
    }
  }
  else {
    bVar8 = pcVar5 != FUN_15002a9c;
    if (!bVar8) {
      pcVar5 = *(code **)(param_1 + 0x24);
    }
    if (bVar8 || pcVar5 != (code *)0x0) {
      return;
    }
    cVar1 = *(char *)(param_2 + 0x48);
    if (cVar1 != '\x04') {
      if (param_3 == 1) {
        if (cVar1 == *(char *)(param_1 + 0x880)) {
          return;
        }
        *(char *)(param_1 + 0x880) = cVar1;
        FUN_15014e10(this);
        FUN_15014da0(iVar6,cVar1);
        FUN_1501580c(msys::MComSys::_sys + 0x49368,0x110015,0,0,0);
        return;
      }
      if (param_3 != 4) {
        return;
      }
      FUN_1501580c(pMVar3,0x110018,0,0,0);
      pMVar3 = msys::MComSys::_sys;
      if (*(int *)(param_1 + 8) == 0) {
        *(MComSys **)(param_1 + 8) = msys::MComSys::_sys;
      }
      *(undefined1 *)(*(int *)(param_1 + 8) + 0xe6508) = 0;
      if (*(int *)(param_1 + 8) == 0) {
        *(MComSys **)(param_1 + 8) = pMVar3;
      }
      *(undefined1 *)(*(int *)(param_1 + 8) + 0xe650a) = 1;
      pMVar4 = *(MComSys **)(param_1 + 8);
      if (pMVar4 == (MComSys *)0x0) {
        *(MComSys **)(param_1 + 8) = pMVar3;
        pMVar4 = pMVar3;
      }
      CellAnime::play((CellAnime *)(pMVar4 + 0xf2010),'\x14',0,1.0);
      pMVar4 = msys::MComSys::_sys;
      pMVar3 = *(MComSys **)(param_1 + 8);
      if (*(MComSys **)(param_1 + 8) == (MComSys *)0x0) {
        *(MComSys **)(param_1 + 8) = msys::MComSys::_sys;
        pMVar3 = pMVar4;
      }
      FUN_15014558(pMVar3,"MES_menu_tuto_badge_change_no_here");
      *(code **)(param_1 + 0x20) = FUN_150033a8;
      *(undefined4 *)(param_1 + 0x24) = 0;
      return;
    }
    if (param_3 != 1) {
      if (param_3 != 4) {
        if (param_3 != 5) {
          return;
        }
        if (*(int *)(param_1 + 8) == 0) {
          *(MComSys **)(param_1 + 8) = msys::MComSys::_sys;
        }
        ad::lyt::LytAnim::playAuto((LytAnim *)(*(int *)(param_1 + 8) + 0xe9e44),1.0);
        *(undefined1 *)(param_1 + 0x865) = 5;
        iVar6 = main_menu::GetBootInfo();
        if (*(char *)(iVar6 + 0x2c) == '\0') goto LAB_1500225c;
        pMVar3 = *(MComSys **)(param_1 + 8);
joined_r0x15002070:
        pMVar4 = msys::MComSys::_sys;
        if (pMVar3 == (MComSys *)0x0) {
          *(MComSys **)(param_1 + 8) = msys::MComSys::_sys;
          pMVar3 = pMVar4;
        }
        msys::MComSys::setEvArg(pMVar3,2);
LAB_1500225c:
        msys::MCursorBase::setVisible(this,false);
        return;
      }
      FUN_1501580c(pMVar3,0x110016,0,0,0);
      pMVar4 = msys::MComSys::_sys;
      pMVar3 = *(MComSys **)(param_1 + 8);
      if (*(MComSys **)(param_1 + 8) == (MComSys *)0x0) {
        *(MComSys **)(param_1 + 8) = msys::MComSys::_sys;
        pMVar3 = pMVar4;
      }
      pMVar3[0xe6508] = (MComSys)0x0;
      pMVar4 = msys::MComSys::_sys;
      pMVar3 = *(MComSys **)(param_1 + 8);
      if (*(MComSys **)(param_1 + 8) == (MComSys *)0x0) {
        *(MComSys **)(param_1 + 8) = msys::MComSys::_sys;
        pMVar3 = pMVar4;
      }
      pMVar3[0xe650a] = (MComSys)0x1;
    }
    if (*(char *)(param_1 + 0x880) != '\x04') {
      *(undefined1 *)(param_1 + 0x880) = 4;
      FUN_15014e10(this);
      FUN_15014da0(iVar6,4);
      FUN_1501580c(msys::MComSys::_sys + 0x49368,0x110015,0,0,0);
      return;
    }
  }
  return;
}


// FUNC 0x150022a0 FUN_150022a0 (MainMenu)
//   size 0x3c | file MainMenu+0x22a0 | callers(0) | datarefs 2

void FUN_150022a0(int param_1)

{
  int iVar1;
  
  iVar1 = msys::MLyt::isBusyAnime((MLyt *)(param_1 + 0x110));
  if ((iVar1 == 0) && (iVar1 = msys::MLyt::isBusyAnime((MLyt *)(param_1 + 0x4b8)), iVar1 == 0)) {
    *(undefined1 **)(param_1 + 0x20) = &LAB_15002a6c;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x15002a9c FUN_15002a9c (MainMenu)
//   size 0x2c4 | file MainMenu+0x2a9c | callers(0) | datarefs 4

void FUN_15002a9c(int param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float fVar6;
  
  iVar2 = (int)*(char *)(param_1 + 0x880);
  iVar4 = iVar2 % 3;
  iVar5 = (short)*(char *)(param_1 + 0x880) * 0x56;
  uVar1 = *param_2;
  iVar5 = (int)(char)((char)((uint)iVar5 >> 8) - (char)(iVar5 >> 0x1f));
  if ((uVar1 & 0x20) == 0) {
    if ((uVar1 & 0x10) == 0) {
      if ((uVar1 & 0x40) == 0) {
        if ((uVar1 & 0x80) == 0) {
          iVar3 = iVar2;
          if ((uVar1 & 0x401) == 0) {
            if ((uVar1 & 0x802) == 0) goto LAB_15002ce0;
            (**(code **)(**(int **)(param_1 + 0x860) + 0x10))();
            iVar4 = msys::MComSys::_sys;
            iVar5 = *(int *)(param_1 + 8);
            if (*(int *)(param_1 + 8) == 0) {
              *(int *)(param_1 + 8) = msys::MComSys::_sys;
              iVar5 = iVar4;
            }
            *(undefined1 *)(iVar5 + 0xe6508) = 0;
            iVar5 = *(int *)(param_1 + 8);
          }
          else {
            (**(code **)(**(int **)(param_1 + iVar2 * 4 + 0x751c) + 0x10))();
            iVar4 = msys::MComSys::_sys;
            iVar5 = *(int *)(param_1 + 8);
            if (*(int *)(param_1 + 8) == 0) {
              *(int *)(param_1 + 8) = msys::MComSys::_sys;
              iVar5 = iVar4;
            }
            *(undefined1 *)(iVar5 + 0xe6508) = 0;
            iVar5 = *(int *)(param_1 + 8);
          }
          iVar4 = msys::MComSys::_sys;
          if (iVar5 == 0) {
            *(int *)(param_1 + 8) = msys::MComSys::_sys;
            iVar5 = iVar4;
          }
          *(undefined1 *)(iVar5 + 0xe650a) = 1;
        }
        else {
          do {
            iVar5 = (int)(char)((char)iVar5 + '\x01');
            if (1 < iVar5) {
              iVar5 = 0;
            }
            uVar1 = iVar5 * 3 + iVar4;
            iVar3 = (int)(char)uVar1;
          } while (((uVar1 & 0xff) == 4) &&
                  (fVar6 = (float)GetRegFlag(0xd00c,(GlobalEvent *)0x0,(LocalEvent *)0x0),
                  fVar6 == 0.0));
        }
      }
      else {
        do {
          iVar5 = (int)(char)((char)iVar5 + -1);
          if (iVar5 < 0) {
            iVar5 = 1;
          }
          uVar1 = iVar5 * 3 + iVar4;
          iVar3 = (int)(char)uVar1;
        } while (((uVar1 & 0xff) == 4) &&
                (fVar6 = (float)GetRegFlag(0xd00c,(GlobalEvent *)0x0,(LocalEvent *)0x0),
                fVar6 == 0.0));
      }
    }
    else {
      do {
        iVar4 = (int)(char)((char)iVar4 + '\x01');
        if (2 < iVar4) {
          iVar4 = 0;
        }
        uVar1 = iVar5 * 3 + iVar4;
        iVar3 = (int)(char)uVar1;
      } while (((uVar1 & 0xff) == 4) &&
              (fVar6 = (float)GetRegFlag(0xd00c,(GlobalEvent *)0x0,(LocalEvent *)0x0), fVar6 == 0.0)
              );
    }
  }
  else {
    do {
      iVar4 = (int)(char)((char)iVar4 + -1);
      if (iVar4 < 0) {
        iVar4 = 2;
      }
      uVar1 = iVar5 * 3 + iVar4;
      iVar3 = (int)(char)uVar1;
    } while (((uVar1 & 0xff) == 4) &&
            (fVar6 = (float)GetRegFlag(0xd00c,(GlobalEvent *)0x0,(LocalEvent *)0x0), fVar6 == 0.0));
  }
LAB_15002ce0:
  if (iVar2 != iVar3) {
    FUN_1501580c(msys::MComSys::_sys + 0x49368,0x110015,0,0,0);
    *(char *)(param_1 + 0x880) = (char)iVar3;
    FUN_15014da0(param_1 + 0x6c48,iVar3);
  }
  FUN_15014940(param_1 + 0x6c48);
  FUN_15014e10(param_1 + 0x868);
  if (iVar2 == iVar3) {
    return;
  }
  FUN_15014cc4(param_1);
  return;
}


// FUNC 0x15002d7c main_menu::MainMenu_TopPage::Core::vfunc_0x10 (MainMenu)
//   size 0x240 | file MainMenu+0x2d7c | callers(0) | datarefs 1

/* WARNING: Removing unreachable block (ram,0x15002f18) */

void main_menu::MainMenu_TopPage::Core::vfunc_0x10(int param_1,int param_2)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  code *pcVar4;
  undefined *puVar5;
  int *piVar6;
  uint uVar7;
  int iVar8;
  bool bVar9;
  
  pcVar1 = *(code **)(param_1 + 0x20);
  pcVar4 = FUN_1500359c;
  if (pcVar1 == FUN_1500359c) {
    pcVar4 = *(code **)(param_1 + 0x24);
  }
  if (pcVar1 == FUN_1500359c && pcVar4 == (code *)0x0) {
    if (param_2 == 4) {
      FUN_1501580c(msys::MComSys::_sys + 0x49368,0x110017,0,0,0);
      iVar3 = msys::MComSys::_sys;
      iVar8 = *(int *)(param_1 + 8);
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar8 = iVar3;
      }
      *(undefined1 *)(iVar8 + 0xe6508) = 0;
      return;
    }
    if (param_2 == 5) {
      uVar7 = 0;
      msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x110),0,0,(char *)0x0,(char *)0x0);
      msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x4b8),0,0,(char *)0x0,(char *)0x0);
      do {
        iVar8 = param_1 + uVar7 * 0x17c;
        if (*(Unit **)(iVar8 + 0xa08) == (Unit *)0x0) {
          puVar5 = (undefined *)0x0;
        }
        else {
          puVar5 = &DAT_1502385c;
        }
        if (puVar5 != (undefined *)0x0) {
          ad::dfx::Unit::killForce(*(Unit **)(iVar8 + 0xa08));
        }
        piVar6 = *(int **)(iVar8 + 0x8bc);
        piVar2 = (int *)(iVar8 + 0x8b8);
        if (piVar6 != piVar2) {
          *(int **)(*piVar2 + 4) = piVar6;
          *piVar6 = *piVar2;
          if (piVar2 != (int *)0x0) {
            *piVar2 = (int)piVar2;
            *(int **)(iVar8 + 0x8bc) = piVar2;
          }
        }
        *(undefined4 *)(iVar8 + 0x9f0) = 0;
        uVar7 = uVar7 + 1 & 0xff;
      } while (uVar7 < 2);
      msys::MCursorBase::setVisible((MCursorBase *)(param_1 + 0x868),false);
      *(code **)(param_1 + 0x20) = FUN_150022a0;
      *(undefined4 *)(param_1 + 0x24) = 0;
    }
  }
  else {
    bVar9 = pcVar1 == FUN_15002a9c;
    if (bVar9) {
      pcVar1 = *(code **)(param_1 + 0x24);
    }
    if ((bVar9 && pcVar1 == (code *)0x0) && param_2 == 4) {
      FUN_1501580c(msys::MComSys::_sys + 0x49368,0x110018,0,0,0);
      iVar8 = msys::MComSys::_sys;
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
      }
      *(undefined1 *)(*(int *)(param_1 + 8) + 0xe6508) = 0;
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = iVar8;
      }
      *(undefined1 *)(*(int *)(param_1 + 8) + 0xe650a) = 1;
      iVar3 = *(int *)(param_1 + 8);
      if (iVar3 == 0) {
        *(int *)(param_1 + 8) = iVar8;
        iVar3 = iVar8;
      }
      CellAnime::play((CellAnime *)(iVar3 + 0xf2010),'\x14',0,1.0);
      iVar3 = msys::MComSys::_sys;
      iVar8 = *(int *)(param_1 + 8);
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar8 = iVar3;
      }
      FUN_15014558(iVar8,"MES_menu_tuto_badge_change_no_here");
      *(code **)(param_1 + 0x20) = FUN_150033a8;
      *(undefined4 *)(param_1 + 0x24) = 0;
      return;
    }
  }
  return;
}


// FUNC 0x15002f40 FUN_15002f40 (MainMenu)
//   size 0x74 | file MainMenu+0x2f40 | callers(0) | datarefs 2

void FUN_15002f40(int param_1)

{
  MComSys *pMVar1;
  int iVar2;
  MComSys *this;
  
  FUN_15014940(param_1 + 0x6c48);
  iVar2 = msys::MLyt::isBusyAnime((MLyt *)(param_1 + 0x4b8));
  pMVar1 = msys::MComSys::_sys;
  if ((iVar2 == 0) && (*(short *)(param_1 + 0x6c4e) == 100)) {
    this = *(MComSys **)(param_1 + 8);
    if (*(MComSys **)(param_1 + 8) == (MComSys *)0x0) {
      *(MComSys **)(param_1 + 8) = msys::MComSys::_sys;
      this = pMVar1;
    }
    iVar2 = msys::MComSys::getNextPage(this);
    if (*(char *)(iVar2 + 0x14) != '\0') {
      *(undefined1 **)(param_1 + 0x18) = &LAB_15003500;
      *(undefined4 *)(param_1 + 0x1c) = 0;
    }
  }
  return;
}


// FUNC 0x15002fd4 FUN_15002fd4 (MainMenu)
//   size 0xb0 | file MainMenu+0x2fd4 | callers(0) | datarefs 2

void FUN_15002fd4(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = msys::MComSys::_sys;
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  else {
    iVar2 = *(int *)(param_1 + 8);
  }
  MoveVBase::stop((MoveVBase *)(iVar2 + 0xf1f90));
  *(undefined4 *)(iVar2 + 0xf1fac) = 0xc3340000;
  *(undefined4 *)(iVar2 + 0xf1f94) = 0xc3340000;
  *(undefined4 *)(iVar2 + 0xf1fb0) = 0xc2340000;
  *(undefined4 *)(iVar2 + 0xf1fb4) = 0xc2c60000;
  *(undefined4 *)(iVar2 + 0xf1f98) = 0xc2340000;
  *(undefined4 *)(iVar2 + 0xf1f9c) = 0xc2c60000;
  iVar1 = msys::MComSys::_sys;
  iVar2 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar2 = iVar1;
  }
  *(undefined1 *)(iVar2 + 0xf2005) = 1;
  iVar1 = msys::MComSys::_sys;
  iVar2 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar2 = iVar1;
  }
  FUN_150148b0(0xc1f00000,0xc2340000,iVar2,2);
  *(code **)(param_1 + 0x20) = FUN_150030a0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


// FUNC 0x150030a0 FUN_150030a0 (MainMenu)
//   size 0x7c | file MainMenu+0x30a0 | callers(0) | datarefs 2

void FUN_150030a0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = msys::MComSys::_sys;
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  else {
    iVar1 = *(int *)(param_1 + 8);
  }
  iVar2 = FUN_150147a8(iVar1);
  iVar1 = msys::MComSys::_sys;
  if (iVar2 == 0) {
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar1;
    }
    CellAnime::play((CellAnime *)(iVar2 + 0xf2010),'\x14',0,1.0);
    iVar2 = msys::MComSys::_sys;
    iVar1 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar1 = iVar2;
    }
    FUN_15014558(iVar1,"MES_menu_tuto_badge_change_farst");
    *(code **)(param_1 + 0x20) = FUN_1500314c;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x1500314c FUN_1500314c (MainMenu)
//   size 0x140 | file MainMenu+0x314c | callers(0) | datarefs 2

void FUN_1500314c(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  iVar1 = msys::MComSys::_sys;
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  iVar2 = *(int *)(param_1 + 8);
  if (*(int *)(iVar2 + 0xf1bc0) == 0) {
    if (iVar2 == 0) {
      *(int *)(param_1 + 8) = iVar1;
      iVar2 = iVar1;
    }
    CellAnime::play((CellAnime *)(iVar2 + 0xf2010),'\f',0,1.0);
    msys::MCursorBase::setVisible((MCursorBase *)(param_1 + 0x868),true);
    FUN_15014e10((MCursorBase *)(param_1 + 0x868));
    iVar2 = msys::MComSys::_sys;
    iVar1 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar1 = iVar2;
    }
    *(undefined1 *)(iVar1 + 0xe6508) = 1;
    iVar2 = msys::MComSys::_sys;
    iVar1 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar1 = iVar2;
    }
    *(undefined1 *)(iVar1 + 0xe650a) = 1;
    *(undefined1 *)(param_1 + 0x8b0) = 0;
    msys::MDfxChr::playDfx((MDfxChr *)(param_1 + 0x8b4),0x12);
    *(undefined2 *)(*(int *)(param_1 + (uint)*(byte *)(param_1 + 0x8b0) * 0x17c + 0xa08) + 0xf2) = 0
    ;
    iVar2 = msys::MComSys::_sys;
    iVar1 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar1 = iVar2;
    }
    uVar3 = *(undefined4 *)(iVar1 + 0xe9b6c);
    uVar4 = *(undefined4 *)(iVar1 + 0xe9b70);
    iVar1 = param_1 + (uint)*(byte *)(param_1 + 0x8b0) * 0x17c;
    MoveVBase::stop((MoveVBase *)(iVar1 + 0x980));
    *(undefined4 *)(iVar1 + 0x99c) = uVar3;
    *(undefined4 *)(iVar1 + 0x9a0) = uVar4;
    *(undefined4 *)(iVar1 + 0x9a4) = 0x43480000;
    *(undefined4 *)(iVar1 + 0x984) = uVar3;
    *(undefined4 *)(iVar1 + 0x988) = uVar4;
    *(undefined4 *)(iVar1 + 0x98c) = 0x43480000;
    *(code **)(param_1 + 0x20) = FUN_15002a9c;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x150032a4 FUN_150032a4 (MainMenu)
//   size 0xf4 | file MainMenu+0x32a4 | callers(0) | datarefs 1

void FUN_150032a4(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int *piVar4;
  float fVar5;
  
  FUN_15014940(param_1 + 0x6c48);
  iVar1 = msys::MLyt::isBusyAnime((MLyt *)(param_1 + 0x110));
  if (((iVar1 == 0) && (iVar1 = msys::MLyt::isBusyAnime((MLyt *)(param_1 + 0x4b8)), iVar1 == 0)) &&
     (*(short *)(param_1 + 0x6c4e) == 100)) {
    uVar3 = 0;
    do {
      piVar4 = *(int **)(param_1 + uVar3 * 4 + 0x751c);
      if ((uVar3 == 4) &&
         (fVar5 = (float)GetRegFlag(0xd00c,(GlobalEvent *)0x0,(LocalEvent *)0x0), fVar5 == 0.0)) {
        uVar2 = 0;
      }
      else {
        uVar2 = 1;
      }
      (**(code **)(*piVar4 + 0x28))(piVar4,uVar2);
      uVar3 = uVar3 + 1 & 0xff;
    } while (uVar3 < 6);
    uVar3 = 0;
    do {
      piVar4 = *(int **)(param_1 + uVar3 * 4 + 0x7534);
      (**(code **)(*piVar4 + 0x28))(piVar4,1);
      uVar3 = uVar3 + 1 & 0xff;
    } while (uVar3 < 2);
    *(code **)(param_1 + 0x20) = FUN_15002fd4;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x150033a8 FUN_150033a8 (MainMenu)
//   size 0xc8 | file MainMenu+0x33a8 | callers(0) | datarefs 2

void FUN_150033a8(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = msys::MComSys::_sys;
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  iVar2 = *(int *)(param_1 + 8);
  if (*(int *)(iVar2 + 0xf1bc0) == 0) {
    if (iVar2 == 0) {
      *(int *)(param_1 + 8) = iVar1;
      iVar2 = iVar1;
    }
    CellAnime::play((CellAnime *)(iVar2 + 0xf2010),'\f',0,1.0);
    uVar3 = 0;
    do {
      (**(code **)(**(int **)(param_1 + uVar3 * 4 + 0x751c) + 0x18))();
      iVar1 = msys::MComSys::_sys;
      uVar3 = uVar3 + 1 & 0xff;
    } while (uVar3 < 6);
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
    *(code **)(param_1 + 0x20) = FUN_15002a9c;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x15003510 FUN_15003510 (MainMenu)
//   size 0x74 | file MainMenu+0x3510 | callers(0) | datarefs 1

void FUN_15003510(int param_1)

{
  int iVar1;
  int iVar2;
  
  FUN_150144d8();
  iVar2 = msys::MComSys::_sys;
  iVar1 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar1 = iVar2;
  }
  iVar2 = msys::MComSys::_sys;
  if (iVar1 == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  else {
    iVar2 = iVar1;
  }
  ad::fw::TaskBase::readLyt
            (*(TaskBase **)(iVar2 + 4),(Resource *)(param_1 + 0xcc),
             (FileContext *)(*(int *)(iVar1 + 0x278) + 0x150),"?MENU_MAIN",
             (MemAlcBase *)(param_1 + 0x28),0x7f,(ResCacheArg *)0x0);
  *(undefined1 **)(param_1 + 0x10) = &LAB_1500228c;
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}


// FUNC 0x1500359c FUN_1500359c (MainMenu)
//   size 0x2c4 | file MainMenu+0x359c | callers(0) | datarefs 3

void FUN_1500359c(int param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float fVar6;
  
  iVar2 = (int)*(char *)(param_1 + 0x880);
  iVar4 = iVar2 % 3;
  iVar5 = (short)*(char *)(param_1 + 0x880) * 0x56;
  uVar1 = *param_2;
  iVar5 = (int)(char)((char)((uint)iVar5 >> 8) - (char)(iVar5 >> 0x1f));
  if ((uVar1 & 0x20) == 0) {
    if ((uVar1 & 0x10) == 0) {
      if ((uVar1 & 0x40) == 0) {
        if ((uVar1 & 0x80) == 0) {
          iVar3 = iVar2;
          if ((uVar1 & 0x401) == 0) {
            if ((uVar1 & 0x802) == 0) goto LAB_150037e0;
            (**(code **)(**(int **)(param_1 + 0x860) + 0x10))();
            iVar4 = msys::MComSys::_sys;
            iVar5 = *(int *)(param_1 + 8);
            if (*(int *)(param_1 + 8) == 0) {
              *(int *)(param_1 + 8) = msys::MComSys::_sys;
              iVar5 = iVar4;
            }
            *(undefined1 *)(iVar5 + 0xe6508) = 0;
            iVar5 = *(int *)(param_1 + 8);
          }
          else {
            (**(code **)(**(int **)(param_1 + iVar2 * 4 + 0x751c) + 0x10))();
            iVar4 = msys::MComSys::_sys;
            iVar5 = *(int *)(param_1 + 8);
            if (*(int *)(param_1 + 8) == 0) {
              *(int *)(param_1 + 8) = msys::MComSys::_sys;
              iVar5 = iVar4;
            }
            *(undefined1 *)(iVar5 + 0xe6508) = 0;
            iVar5 = *(int *)(param_1 + 8);
          }
          iVar4 = msys::MComSys::_sys;
          if (iVar5 == 0) {
            *(int *)(param_1 + 8) = msys::MComSys::_sys;
            iVar5 = iVar4;
          }
          *(undefined1 *)(iVar5 + 0xe650a) = 1;
        }
        else {
          do {
            iVar5 = (int)(char)((char)iVar5 + '\x01');
            if (1 < iVar5) {
              iVar5 = 0;
            }
            uVar1 = iVar5 * 3 + iVar4;
            iVar3 = (int)(char)uVar1;
          } while (((uVar1 & 0xff) == 4) &&
                  (fVar6 = (float)GetRegFlag(0xd00c,(GlobalEvent *)0x0,(LocalEvent *)0x0),
                  fVar6 == 0.0));
        }
      }
      else {
        do {
          iVar5 = (int)(char)((char)iVar5 + -1);
          if (iVar5 < 0) {
            iVar5 = 1;
          }
          uVar1 = iVar5 * 3 + iVar4;
          iVar3 = (int)(char)uVar1;
        } while (((uVar1 & 0xff) == 4) &&
                (fVar6 = (float)GetRegFlag(0xd00c,(GlobalEvent *)0x0,(LocalEvent *)0x0),
                fVar6 == 0.0));
      }
    }
    else {
      do {
        iVar4 = (int)(char)((char)iVar4 + '\x01');
        if (2 < iVar4) {
          iVar4 = 0;
        }
        uVar1 = iVar5 * 3 + iVar4;
        iVar3 = (int)(char)uVar1;
      } while (((uVar1 & 0xff) == 4) &&
              (fVar6 = (float)GetRegFlag(0xd00c,(GlobalEvent *)0x0,(LocalEvent *)0x0), fVar6 == 0.0)
              );
    }
  }
  else {
    do {
      iVar4 = (int)(char)((char)iVar4 + -1);
      if (iVar4 < 0) {
        iVar4 = 2;
      }
      uVar1 = iVar5 * 3 + iVar4;
      iVar3 = (int)(char)uVar1;
    } while (((uVar1 & 0xff) == 4) &&
            (fVar6 = (float)GetRegFlag(0xd00c,(GlobalEvent *)0x0,(LocalEvent *)0x0), fVar6 == 0.0));
  }
LAB_150037e0:
  if (iVar2 != iVar3) {
    FUN_1501580c(msys::MComSys::_sys + 0x49368,0x110015,0,0,0);
    *(char *)(param_1 + 0x880) = (char)iVar3;
    FUN_15014da0(param_1 + 0x6c48,iVar3);
  }
  FUN_15014940(param_1 + 0x6c48);
  FUN_15014e10(param_1 + 0x868);
  if (iVar2 == iVar3) {
    return;
  }
  FUN_15014cc4(param_1);
  return;
}


// FUNC 0x1500387c FUN_1500387c (MainMenu)
//   size 0x1fc | file MainMenu+0x387c | callers(0) | datarefs 1

void FUN_1500387c(int param_1)

{
  int iVar1;
  MComSys *pMVar2;
  MComSys *pMVar3;
  uint uVar4;
  int *piVar5;
  undefined4 uVar6;
  float fVar7;
  undefined4 uVar8;
  
  FUN_15014940(param_1 + 0x6c48);
  iVar1 = msys::MLyt::isBusyAnime((MLyt *)(param_1 + 0x110));
  if (((iVar1 == 0) && (iVar1 = msys::MLyt::isBusyAnime((MLyt *)(param_1 + 0x4b8)), iVar1 == 0)) &&
     (*(short *)(param_1 + 0x6c4e) == 100)) {
    msys::MCursorBase::setVisible((MCursorBase *)(param_1 + 0x868),true);
    FUN_15014e10((MCursorBase *)(param_1 + 0x868));
    *(undefined1 *)(param_1 + 0x8b0) = 0;
    msys::MDfxChr::playDfx((MDfxChr *)(param_1 + 0x8b4),0x12);
    *(undefined2 *)(*(int *)(param_1 + (uint)*(byte *)(param_1 + 0x8b0) * 0x17c + 0xa08) + 0xf2) = 0
    ;
    pMVar2 = msys::MComSys::_sys;
    pMVar3 = *(MComSys **)(param_1 + 8);
    if (*(MComSys **)(param_1 + 8) == (MComSys *)0x0) {
      *(MComSys **)(param_1 + 8) = msys::MComSys::_sys;
      pMVar3 = pMVar2;
    }
    uVar6 = *(undefined4 *)(pMVar3 + 0xe9b6c);
    uVar8 = *(undefined4 *)(pMVar3 + 0xe9b70);
    iVar1 = param_1 + (uint)*(byte *)(param_1 + 0x8b0) * 0x17c;
    MoveVBase::stop((MoveVBase *)(iVar1 + 0x980));
    *(undefined4 *)(iVar1 + 0x99c) = uVar6;
    *(undefined4 *)(iVar1 + 0x9a0) = uVar8;
    *(undefined4 *)(iVar1 + 0x9a4) = 0x43480000;
    *(undefined4 *)(iVar1 + 0x984) = uVar6;
    *(undefined4 *)(iVar1 + 0x988) = uVar8;
    *(undefined4 *)(iVar1 + 0x98c) = 0x43480000;
    iVar1 = main_menu::GetBootInfo();
    pMVar3 = msys::MComSys::_sys;
    if (*(char *)(iVar1 + 0x2c) != '\0') {
      pMVar2 = *(MComSys **)(param_1 + 8);
      if (*(MComSys **)(param_1 + 8) == (MComSys *)0x0) {
        *(MComSys **)(param_1 + 8) = msys::MComSys::_sys;
        pMVar2 = pMVar3;
      }
      msys::MComSys::setEvArg(pMVar2,1);
    }
    pMVar2 = *(MComSys **)(param_1 + 8);
    pMVar3 = pMVar2;
    if (pMVar2 == (MComSys *)0x0) {
      pMVar3 = msys::MComSys::_sys;
    }
    uVar4 = 0;
    if (pMVar2 == (MComSys *)0x0) {
      *(MComSys **)(param_1 + 8) = pMVar3;
    }
    pMVar3[0xe6508] = (MComSys)0x1;
    pMVar2 = msys::MComSys::_sys;
    pMVar3 = *(MComSys **)(param_1 + 8);
    if (*(MComSys **)(param_1 + 8) == (MComSys *)0x0) {
      *(MComSys **)(param_1 + 8) = msys::MComSys::_sys;
      pMVar3 = pMVar2;
    }
    pMVar3[0xe650a] = (MComSys)0x1;
    do {
      piVar5 = *(int **)(param_1 + uVar4 * 4 + 0x751c);
      if ((uVar4 == 4) &&
         (fVar7 = (float)GetRegFlag(0xd00c,(GlobalEvent *)0x0,(LocalEvent *)0x0), fVar7 == 0.0)) {
        uVar6 = 0;
      }
      else {
        uVar6 = 1;
      }
      (**(code **)(*piVar5 + 0x28))(piVar5,uVar6);
      uVar4 = uVar4 + 1 & 0xff;
    } while (uVar4 < 6);
    uVar4 = 0;
    do {
      piVar5 = *(int **)(param_1 + uVar4 * 4 + 0x7534);
      (**(code **)(*piVar5 + 0x28))(piVar5,1);
      uVar4 = uVar4 + 1 & 0xff;
    } while (uVar4 < 2);
    *(code **)(param_1 + 0x20) = FUN_1500359c;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x15003a94 FUN_15003a94 (MainMenu)
//   size 0x168 | file MainMenu+0x3a94 | callers(0) | datarefs 1

/* WARNING: Removing unreachable block (ram,0x15003bf0) */

void FUN_15003a94(int param_1)

{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  uint uVar4;
  int *piVar5;
  
  piVar5 = (int *)(param_1 + 0x6c48);
  uVar4 = 0;
  do {
    iVar1 = msys::MLyt::getParts
                      ((MLyt *)(*piVar5 + 0x4b8),(char *)(&DAT_150361f8)[uVar4],(char *)0x0,
                       (char *)0x0);
    ad::lyt::LytAnim::init((LytAnim *)(piVar5 + uVar4 * 7 + 5),*(Layout **)(iVar1 + 0xac),"2to3","")
    ;
    ad::lyt::LytAnim::playAuto((LytAnim *)(piVar5 + uVar4 * 7 + 5),1.0);
    uVar4 = uVar4 + 1 & 0xff;
  } while (uVar4 < 6);
  uVar4 = 0;
  *(undefined2 *)(param_1 + 0x6c4e) = 0x32;
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x110),2,1,(char *)0x0,(char *)0x0);
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x4b8),2,1,(char *)0x0,(char *)0x0);
  do {
    iVar1 = param_1 + uVar4 * 0x17c;
    if (*(Unit **)(iVar1 + 0xa08) == (Unit *)0x0) {
      puVar2 = (undefined *)0x0;
    }
    else {
      puVar2 = &DAT_1502385c;
    }
    if (puVar2 != (undefined *)0x0) {
      ad::dfx::Unit::killForce(*(Unit **)(iVar1 + 0xa08));
    }
    piVar3 = *(int **)(iVar1 + 0x8bc);
    piVar5 = (int *)(iVar1 + 0x8b8);
    if (piVar3 != piVar5) {
      *(int **)(*piVar5 + 4) = piVar3;
      *piVar3 = *piVar5;
      if (piVar5 != (int *)0x0) {
        *piVar5 = (int)piVar5;
        *(int **)(iVar1 + 0x8bc) = piVar5;
      }
    }
    *(undefined4 *)(iVar1 + 0x9f0) = 0;
    uVar4 = uVar4 + 1 & 0xff;
  } while (uVar4 < 2);
  *(code **)(param_1 + 0x18) = FUN_15002f40;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  return;
}


// FUNC 0x15003c14 FUN_15003c14 (MainMenu)
//   size 0x108 | file MainMenu+0x3c14 | callers(1) 0x15003e90

void FUN_15003c14(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)FUN_15014438();
  *puVar1 = &main_menu::MainMenu_TopPage::Core::vtable;
  puVar1 = (undefined4 *)msys::MCursorBase::MCursorBase((MCursorBase *)(puVar1 + 0x21a));
  *puVar1 = &vtable_for_N4msys7MCursorILj6EEE;
  puVar1[0xc] = 0;
  puVar1[0xd] = 0;
  puVar1[0xe] = 0;
  puVar1[0xf] = 0;
  puVar1[0x10] = 0;
  puVar1[0x11] = 0;
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(puVar1 + 0x13,msys::MDfxChr::MDfxChr,0x17c,2);
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(iVar2 + 0x2f8,msys::StatusPanel::StatusPanel,0x2034,3);
  *(int *)(iVar2 + 0x609c) = iVar2 + -0xbac;
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(iVar2 + 0x60b0,FUN_15012f30,0x1c,6);
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(iVar2 + 0xa8,FUN_15012f30,0x1c,6);
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(iVar2 + 0xa8,FUN_15012f30,0x1c,6);
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(iVar2 + 0xa8,FUN_15012f30,0x1c,6);
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(iVar2 + 0xa8,FUN_15012f30,0x1c,0x24);
  iVar2 = msys::MLytNum::MLytNum((MLytNum *)(iVar2 + 0x3f0));
  *(code **)(iVar2 + -0x72dc) = FUN_15003510;
  *(undefined4 *)(iVar2 + -0x72d8) = 0;
  *(code **)(iVar2 + -0x72d4) = FUN_15003a94;
  *(undefined4 *)(iVar2 + -0x72d0) = 0;
  *(code **)(iVar2 + -0x72cc) = FUN_1500387c;
  *(undefined4 *)(iVar2 + -0x72c8) = 0;
  return;
}


// FUNC 0x15003d38 main_menu::MainMenu_TopPage::Core::vfunc_0x4 (MainMenu)
//   size 0x10 | file MainMenu+0x3d38 | callers(0) | datarefs 1

void main_menu::MainMenu_TopPage::Core::vfunc_0x4(void)

{
  void *pvVar1;
  
  pvVar1 = (void *)vfunc_0x0();
  operator_delete(pvVar1);
  return;
}


// FUNC 0x15003d48 main_menu::MainMenu_TopPage::Core::vfunc_0x0 (MainMenu)
//   size 0x130 | file MainMenu+0x3d48 | callers(1) 0x15003d38 | datarefs 1

void main_menu::MainMenu_TopPage::Core::vfunc_0x0(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  
  *param_1 = &vtable;
  msys::MCursorBase::term((MCursorBase *)(param_1 + 0x21a));
  iVar1 = msys::MLytNum::~MLytNum((MLytNum *)(param_1 + 0x1cbb));
  piVar2 = (int *)(iVar1 + -0x6a4);
  uVar3 = 0;
  do {
    ad::lyt::LytAnim::term((LytAnim *)(piVar2 + uVar3 * 7 + 5),*(bool *)(*piVar2 + 0x838));
    ad::lyt::LytAnim::term((LytAnim *)(piVar2 + uVar3 * 7 + 0x2f),*(bool *)(*piVar2 + 0x838));
    uVar3 = uVar3 + 1 & 0xff;
  } while (uVar3 < 6);
  __aeabi_vec_dtor(iVar1 + -0x3f0,&LAB_15000d18,0x1c,0x24);
  __aeabi_vec_dtor(iVar1 + -0x498,&LAB_15000d18,0x1c,6);
  __aeabi_vec_dtor(iVar1 + -0x540,&LAB_15000d18,0x1c,6);
  __aeabi_vec_dtor(iVar1 + -0x5e8,&LAB_15000d18,0x1c,6);
  __aeabi_vec_dtor(iVar1 + -0x690,&LAB_15000d18,0x1c,6);
  __aeabi_vec_dtor(iVar1 + -0x6740,msys::StatusPanel::~StatusPanel,0x2034,3);
  __aeabi_vec_dtor(iVar1 + -0x6a38,msys::MDfxChr::~MDfxChr,0x17c,2);
  iVar1 = msys::MCursorBase::~MCursorBase((MCursorBase *)(iVar1 + -0x6a84));
  MainMenuPageBase::Core::vfunc_0x0(iVar1 + -0x868);
  return;
}


// FUNC 0x15003e90 main_menu::MainMenu_TopPage::vfunc_0x30 (MainMenu)
//   size 0x30 | file MainMenu+0x3e90 | callers(0) | datarefs 1

void main_menu::MainMenu_TopPage::vfunc_0x30(int param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(0x753c,*(MemAlcBase **)(param_1 + 0x18),(char *)0x0,0);
  uVar2 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_15003c14(pvVar1,param_1);
  }
  *(undefined4 *)(param_1 + 0x20) = uVar2;
  return;
}


// FUNC 0x15003ec4 main_menu::MainMenu_TopPage::vfunc_0x24 (MainMenu)
//   size 0x8 | file MainMenu+0x3ec4 | callers(0) | datarefs 1

undefined4 main_menu::MainMenu_TopPage::vfunc_0x24(void)

{
  return 0;
}


// FUNC 0x15003ecc main_menu::MainMenu_TopPage::vfunc_0x4 (MainMenu)
//   size 0x10 | file MainMenu+0x3ecc | callers(0) | datarefs 1

void main_menu::MainMenu_TopPage::vfunc_0x4(void)

{
  void *pvVar1;
  
  pvVar1 = (void *)MainMenuPageBase::vfunc_0x0();
  operator_delete(pvVar1);
  return;
}


// FUNC 0x15003edc FUN_15003edc (MainMenu)
//   size 0x46c | file MainMenu+0x3edc | callers(1) 0x15004cb4

void FUN_15003edc(int param_1)

{
  void *pvVar1;
  MLyt *this;
  int iVar2;
  MPaneRef *pMVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined4 *puVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  Resource *pRVar10;
  int iVar11;
  undefined4 *puVar12;
  
  if (*(int *)(param_1 + 8) == 0) {
    *(undefined4 *)(param_1 + 8) = msys::MComSys::_sys;
  }
  iVar7 = *(int *)(param_1 + 8);
  ad::lyt::LytResourceMan::init((LytResourceMan *)(param_1 + 0x58));
  pvVar1 = (void *)ad::fw::Resource::getFileData((Resource *)(param_1 + 0xcc));
  ad::lyt::LytResourceMan::registerArc((LytResourceMan *)(param_1 + 0x58),pvVar1,".");
  msys::MLyt::build((MLyt *)(param_1 + 0x110),*(MemAlcBase **)(*(int *)(param_1 + 4) + 0x18),
                    (AnimeName *)&PTR_s_FADE_OUT_150245a4,7);
  iVar7 = iVar7 + 0xd3000;
  msys::MLyt::init((MLyt *)(param_1 + 0x110),iVar7,1);
  msys::MLyt::createLyt
            ((MLyt *)(param_1 + 0x110),(LytResourceMan *)(param_1 + 0x58),"MENU_ITEM_U.bflyt");
  MoveVBase::stop((MoveVBase *)(param_1 + 0x1dc));
  *(undefined4 *)(param_1 + 0x1f8) = 0;
  *(undefined4 *)(param_1 + 0x1fc) = 0;
  *(undefined4 *)(param_1 + 0x200) = 0xc347e666;
  *(undefined4 *)(param_1 + 0x1e0) = *(undefined4 *)(param_1 + 0x1f8);
  *(undefined4 *)(param_1 + 0x1e4) = 0;
  *(undefined4 *)(param_1 + 0x1e8) = 0xc347e666;
  *(undefined4 *)(param_1 + 0x24c) = 0x400;
  this = (MLyt *)(param_1 + 0x4b8);
  msys::MLyt::build(this,*(MemAlcBase **)(*(int *)(param_1 + 4) + 0x18),
                    (AnimeName *)&PTR_s_FADE_OUT_150245dc,5);
  msys::MLyt::init(this,iVar7,1);
  msys::MLyt::createLyt
            (this,(LytResourceMan *)(param_1 + 0x58),"MENU_ITEM_L.bflyt",
             (ButtonGroup *)(param_1 + 0x3c),(MCursorBase *)(param_1 + 0x874));
  MoveVBase::stop((MoveVBase *)(param_1 + 0x584));
  *(undefined4 *)(param_1 + 0x5a0) = 0;
  *(undefined4 *)(param_1 + 0x5a4) = 0;
  *(undefined4 *)(param_1 + 0x5a8) = 0xc347e666;
  *(undefined4 *)(param_1 + 0x588) = *(undefined4 *)(param_1 + 0x5a0);
  *(undefined4 *)(param_1 + 0x58c) = 0;
  *(undefined4 *)(param_1 + 0x590) = 0xc347e666;
  uVar8 = 0;
  *(undefined4 *)(param_1 + 0x5f4) = 0x401;
  do {
    iVar7 = param_1 + uVar8 * 0x27c;
    pRVar10 = (Resource *)(param_1 + uVar8 * 0x44 + 0x99c);
    msys::MCellAnime::init((MCellAnime *)(iVar7 + 0x1d868),pRVar10);
    CellAnime::play((CellAnime *)(iVar7 + 0x1d9b4),'\0',0,1.0);
    msys::MCellAnime::init((MCellAnime *)(iVar7 + 0x1dfdc),pRVar10);
    CellAnime::play((CellAnime *)(iVar7 + 0x1e128),'\0',0,1.0);
    uVar8 = uVar8 + 1 & 0xff;
  } while (uVar8 < 3);
  FUN_1500479c((MChrBase *)(param_1 + 0x1e778),param_1 + 0x58,*(undefined4 *)(param_1 + 0x868),
               param_1,param_1 + 0x914);
  MoveVBase::stop((MoveVBase *)(param_1 + 0x1e844));
  *(undefined4 *)(param_1 + 0x1e860) = 0;
  *(undefined4 *)(param_1 + 0x1e864) = 0;
  *(undefined4 *)(param_1 + 0x1e868) = 0xc3480000;
  *(undefined4 *)(param_1 + 0x1e848) = *(undefined4 *)(param_1 + 0x1e860);
  *(undefined4 *)(param_1 + 0x1e84c) = 0;
  *(undefined4 *)(param_1 + 0x1e850) = 0xc3480000;
  msys::MLyt::attachMChr
            (this,(MChrBase *)(param_1 + 0x1e778),"INS_LIST_ITEM",(char *)0x0,(char *)0x0,
             (char *)0x0);
  FUN_1500674c(param_1 + 0xa334,param_1);
  uVar8 = 0;
  do {
    iVar7 = param_1 + uVar8 * 0x27c;
    uVar9 = 0;
    do {
      if (*(int *)(param_1 + 8) == 0) {
        *(undefined4 *)(param_1 + 8) = msys::MComSys::_sys;
      }
      iVar2 = *(int *)(param_1 + 8);
      if (iVar2 == 0) {
        *(undefined4 *)(param_1 + 8) = msys::MComSys::_sys;
      }
      iVar11 = param_1 + uVar8 * 0xed8 + uVar9 * 0x17c;
      msys::MDfxChr::init((MDfxChr *)(iVar11 + 0x76ac),
                          *(MemAlcBase **)(*(int *)(param_1 + 4) + 0x18),
                          *(MDfxSys **)(*(int *)(param_1 + 8) + 0xe64f0),(Scene *)(iVar2 + 0x4aba4),
                          0x401);
      MoveVBase::stop((MoveVBase *)(iVar11 + 0x7778));
      *(undefined4 *)(iVar11 + 0x7794) = 0;
      piVar5 = (int *)(iVar11 + 0x76b0);
      *(undefined4 *)(iVar11 + 0x7798) = 0;
      *(undefined4 *)(iVar11 + 0x779c) = 0x4171999a;
      *(undefined4 *)(iVar11 + 0x777c) = 0;
      *(undefined4 *)(iVar11 + 0x7780) = 0;
      *(undefined4 *)(iVar11 + 0x7784) = 0x4171999a;
      puVar12 = *(undefined4 **)(iVar11 + 0x76b4);
      *(undefined4 **)(*piVar5 + 4) = puVar12;
      *puVar12 = *(undefined4 *)(iVar11 + 0x76b0);
      if (piVar5 != (int *)0x0) {
        *piVar5 = iVar7 + 0x1e120;
        puVar12 = *(undefined4 **)(iVar7 + 0x1e124);
        *(undefined4 **)(iVar11 + 0x76b4) = puVar12;
        *puVar12 = piVar5;
        *(int **)(iVar7 + 0x1e124) = piVar5;
      }
      msys::MChrBaseCore::setParent((MChrBaseCore *)(iVar11 + 0x76ac),(MChrBase *)(iVar7 + 0x1dfdc))
      ;
      uVar9 = uVar9 + 1 & 0xff;
    } while (uVar9 < 10);
    uVar8 = uVar8 + 1 & 0xff;
  } while (uVar8 < 3);
  uVar4 = *(undefined4 *)(*(int *)(param_1 + 4) + 0x18);
  *(undefined4 *)(param_1 + 0x76a8) = 0x400;
  *(undefined4 *)(param_1 + 0x769c) = uVar4;
  *(undefined4 *)(param_1 + 0x76a0) = 0;
  *(undefined4 *)(param_1 + 0x76a4) = 0;
  MessageSimple::init((MessageSimple *)(param_1 + 0xbb4));
  FUN_150142ec((MChrBaseCore *)(param_1 + 0xa68));
  *(undefined1 *)(param_1 + 0x6670) = 1;
  *(undefined1 *)(param_1 + 0x768d) = 1;
  *(undefined1 *)(param_1 + 0x768c) = 4;
  *(undefined **)(param_1 + 0x63dc) = &DAT_003fc140;
  MessageWriter::setFontColor((MessageWriter *)(param_1 + 0xbb4),0x373737ff,true);
  pMVar3 = (MPaneRef *)
           msys::MLyt::getMPaneRef
                     ((MLyt *)(param_1 + 0x110),"INS_TOP_PANEL_TEXT","EXP_PNL_U",(char *)0x0,
                      (char *)0x0);
  puVar12 = *(undefined4 **)(param_1 + 0xa70);
  *(undefined4 **)(*(int *)(param_1 + 0xa6c) + 4) = puVar12;
  *puVar12 = *(undefined4 *)(param_1 + 0xa6c);
  puVar12 = (undefined4 *)(param_1 + 0xa6c);
  if (puVar12 != (undefined4 *)0x0) {
    *puVar12 = pMVar3 + 0x10;
    puVar6 = *(undefined4 **)(pMVar3 + 0x14);
    *(undefined4 **)(param_1 + 0xa70) = puVar6;
    *puVar6 = puVar12;
    *(undefined4 **)(pMVar3 + 0x14) = puVar12;
  }
  msys::MChrBaseCore::setParent((MChrBaseCore *)(param_1 + 0xa68),pMVar3);
  *(undefined1 **)(param_1 + 0x10) = &LAB_1500571c;
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}


// FUNC 0x150043e4 FUN_150043e4 (MainMenu)
//   size 0x374 | file MainMenu+0x43e4 | callers(1) 0x15013bb0

int FUN_150043e4(MListWndPBase *param_1,MListWndPBase *param_2)

{
  ushort uVar1;
  MListWndPBase *pMVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  ushort *puVar8;
  uint uVar9;
  uint unaff_r7;
  ushort *puVar10;
  undefined4 uVar11;
  uint uVar12;
  undefined4 local_70;
  MListWndPBase *local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  MListWndPBase *pMStack_2c;
  MListWndPBase *local_28;
  
  iVar7 = 0;
  pMStack_2c = param_1;
  local_28 = param_2;
  if (param_2 < (MListWndPBase *)0x2) {
    iVar5 = msys::MListWndPBase::getListWnd(param_1);
    *(MListWndPBase **)(iVar5 + 0xc) = param_1 + 0x76c4;
    puVar3 = (undefined4 *)ad::db::GetUseItemIdList();
    puVar8 = (ushort *)*puVar3;
    iVar5 = ad::db::GetUseItemIdList();
    puVar10 = *(ushort **)(iVar5 + 4);
    for (; puVar8 != puVar10; puVar8 = puVar8 + 1) {
      iVar5 = GameWork::getItemNum((GameWork *)&gGameWork,*puVar8);
      if (iVar5 != 0) {
        iVar6 = ad::db::GetUseItem(*puVar8);
        if ((*(byte *)(iVar6 + 0x6a) & 0x40) == 0) {
          if (local_28 == (MListWndPBase *)&DAT_00000001) goto LAB_1500448c;
        }
        else if (local_28 == (MListWndPBase *)0x0) {
LAB_1500448c:
          local_6c = param_1 + iVar7 * 0x1c + 0x6000;
          param_1[iVar7 * 0x1c + 0x6f8b] = (MListWndPBase)(*(char *)(iVar6 + 0x60) + '\x01');
          *(short *)(param_1 + iVar7 * 0x1c + 0x6f84) = (short)iVar5;
          *(uint *)(param_1 + iVar7 * 0x1c + 0x6f80) = (uint)*puVar8;
          pMVar2 = param_1 + iVar7 * 0x1c + 0x6f80;
          if (local_28 != (MListWndPBase *)0x0) {
            pMVar2 = local_28;
          }
          if (local_28 == (MListWndPBase *)0x0 || pMVar2 == (MListWndPBase *)&DAT_00000001) {
            uVar1 = *(ushort *)(iVar6 + 0x6a) >> 9;
            if (uVar1 == 0) {
              unaff_r7 = 0;
            }
            local_70 = 0;
            if (uVar1 == 0) {
              do {
                iVar4 = FUN_15013eb8(*(undefined4 *)(param_1 + 0x75a0),iVar6,unaff_r7);
                if (iVar4 != 0) goto LAB_150045cc;
                unaff_r7 = unaff_r7 + 1 & 0xff;
              } while (unaff_r7 < 3);
            }
            else if (uVar1 == 1) {
              iVar4 = FUN_15013eb8(*(undefined4 *)(param_1 + 0x75a0),iVar6,0);
              if (iVar4 == 0) {
                iVar4 = FUN_15013eb8(*(undefined4 *)(param_1 + 0x75a0),iVar6,1);
                goto joined_r0x15004588;
              }
LAB_150045cc:
              local_70 = 1;
            }
            else if (uVar1 == 2) {
              iVar4 = FUN_15013eb8(*(undefined4 *)(param_1 + 0x75a0),iVar6,2);
joined_r0x15004588:
              if (iVar4 != 0) goto LAB_150045cc;
            }
            local_6c[0xf8e] = SUB41(local_70,0);
          }
          else {
            param_1[iVar7 * 0x1c + 0x6f8e] = (MListWndPBase)0x1;
          }
          unaff_r7 = ad::db::GetItemMsgAcs();
          if (iVar5 != 1) {
            iVar6 = iVar6 + 0x18;
          }
          uVar11 = LMS_GetTextIndexByLabel(unaff_r7 + 8,iVar6);
          uVar11 = LMS_GetText(unaff_r7 + 8,uVar11);
          iVar7 = (int)(short)((short)iVar7 + 1);
          *(undefined4 *)(local_6c + 0xf90) = uVar11;
        }
      }
    }
  }
  else if (param_2 == (MListWndPBase *)0x2) {
    iVar5 = msys::MListWndPBase::getListWnd(param_1);
    uVar9 = 0;
    *(MListWndPBase **)(iVar5 + 0xc) = param_1 + 0x77f0;
    do {
      uVar11 = GetRegFlag((&DAT_15024c70)[uVar9 * 10],(GlobalEvent *)0x0,(LocalEvent *)0x0);
      uVar12 = VectorFloatToUnsigned(uVar11,3);
      uVar12 = uVar12 & 0xff;
      if (uVar12 != 0) {
        if ((&DAT_15024c74)[uVar9 * 10] == 0) {
          uVar12 = 1;
        }
        *(short *)(param_1 + iVar7 * 0x1c + 0x6f84) = (short)uVar12;
        *(uint *)(param_1 + iVar7 * 0x1c + 0x6f80) = uVar9;
        param_1[iVar7 * 0x1c + 0x6f8b] = (MListWndPBase)0x0;
        param_1[iVar7 * 0x1c + 0x6f8e] = (MListWndPBase)0x1;
        local_70 = 0;
        local_6c = (MListWndPBase *)0x0;
        local_68 = 0;
        local_64 = 0;
        local_60 = 0;
        local_5c = 0;
        local_58 = 0;
        local_54 = 0;
        local_50 = 0;
        local_4c = 0;
        local_48 = 0;
        local_44 = 0;
        local_40 = 0;
        local_3c = 0;
        local_38 = 0;
        local_34 = 0;
        if (uVar12 == 1) {
          __2sprintf(&local_70,"MES_MenuMes_EventItem%s",(&DAT_15024c68)[uVar9 * 5]);
        }
        else {
          __2sprintf(&local_70,"MES_MenuMes_EventItemNs%s",(&DAT_15024c68)[uVar9 * 5] + 1);
        }
        iVar5 = msys::MComSys::_sys;
        iVar6 = *(int *)(*(int *)(param_1 + 0x75a0) + 8);
        if (iVar6 == 0) {
          *(int *)(*(int *)(param_1 + 0x75a0) + 8) = msys::MComSys::_sys;
          iVar6 = iVar5;
        }
        uVar11 = LMS_GetTextIndexByLabel(iVar6 + 0xeae90,&local_70);
        uVar11 = LMS_GetText(iVar6 + 0xeae90,uVar11);
        *(undefined4 *)(param_1 + iVar7 * 0x1c + 0x6f90) = uVar11;
        iVar7 = (int)(short)((short)iVar7 + 1);
      }
      uVar9 = uVar9 + 1 & 0xff;
    } while (uVar9 < 0x21);
  }
  return iVar7;
}


// FUNC 0x1500479c FUN_1500479c (MainMenu)
//   size 0x364 | file MainMenu+0x479c | callers(1) 0x15003edc

void FUN_1500479c(MListWndPBase *param_1,LytResourceMan *param_2,undefined4 param_3,int param_4,
                 Resource *param_5)

{
  int iVar1;
  void *pvVar2;
  undefined4 *puVar3;
  void *pvVar4;
  int iVar5;
  Layout *pLVar6;
  Layout *pLVar7;
  MListWndPBase *pMVar8;
  void *local_1b8 [2];
  CellAnime *local_1b0;
  undefined4 local_198;
  undefined4 local_18c;
  undefined4 local_188;
  undefined4 local_180;
  LytAnim *local_168;
  LytAnim *local_164;
  LytAnim *local_160;
  LytAnim *local_15c;
  LytAnim *local_158;
  undefined4 local_104;
  undefined4 uStack_100;
  undefined4 local_fc;
  undefined4 uStack_f8;
  MListWndPBase *local_7c;
  undefined1 local_78;
  LytAnim *local_40;
  LytAnim *local_3c;
  LytAnim *local_38;
  LytAnim *local_34;
  LytAnim *local_30;
  
  *(undefined2 *)(param_1 + 0x791c) = 0;
  Mem::Fill(param_1 + 0x791e,0,6);
  Mem::Fill(param_1 + 0x7924,0,6);
  pLVar6 = (Layout *)(param_1 + 0x75a4);
  ad::lyt::LytResourceMan::buildLayout
            (param_2,pLVar6,"MENU_ITEM_L_LIST.bflyt",(ControlCreator *)0x0,(TextSearcher *)0x0);
  local_30 = (LytAnim *)(param_1 + 0x75e0);
  ad::lyt::LytAnim::init(local_30,pLVar6,"touch","");
  pLVar7 = (Layout *)(param_1 + 0x7618);
  ad::lyt::LytResourceMan::buildLayout
            (param_2,pLVar7,"NUM_G_s.bflyt",(ControlCreator *)0x0,(TextSearcher *)0x0);
  local_34 = (LytAnim *)(param_1 + 0x7654);
  ad::lyt::LytAnim::init(local_34,pLVar7,"num_set_U","");
  local_38 = (LytAnim *)(param_1 + 0x7670);
  ad::lyt::LytAnim::init(local_38,pLVar7,"col_00","");
  local_3c = (LytAnim *)(param_1 + 0x768c);
  ad::lyt::LytAnim::init(local_3c,pLVar7,"col_s06","");
  local_40 = (LytAnim *)(param_1 + 0x75fc);
  ad::lyt::LytAnim::init(local_40,pLVar6,"ATTENTION","");
  ad::lyt::LytAnim::playAuto(local_40,1.0);
  ad::lyt::LytAnim::init
            ((LytAnim *)(param_1 + 0x76a8),*(Layout **)(param_4 + 0x260),"EXP_PANEL_ON","EXP_PNL_U")
  ;
  pvVar2 = (void *)ad::fw::Resource::getCA_anm(param_5);
  puVar3 = (undefined4 *)ad::fw::Resource::getCA_tex(param_5);
  pvVar4 = (void *)ad::fw::Resource::getCA_canm(param_5);
  CellAnime::init((CellAnime *)(param_1 + 0x76c4),pvVar2,(void *)*puVar3,pvVar4,'\0',0,1.0);
  param_5 = param_5 + 0x44;
  param_1[0x7767] = (MListWndPBase)((byte)param_1[0x7767] | 3);
  param_1[0x775c] = (MListWndPBase)0x0;
  param_1[0x775d] = (MListWndPBase)0x0;
  local_1b8[0] = (void *)ad::fw::Resource::getCA_anm(param_5);
  puVar3 = (undefined4 *)ad::fw::Resource::getCA_tex(param_5);
  pvVar2 = (void *)ad::fw::Resource::getCA_canm(param_5);
  CellAnime::init((CellAnime *)(param_1 + 0x77f0),local_1b8[0],(void *)*puVar3,pvVar2,'\0',0,1.0);
  param_1[0x7893] = (MListWndPBase)((byte)param_1[0x7893] | 3);
  param_1[0x7888] = (MListWndPBase)0x0;
  param_1[0x7889] = (MListWndPBase)0x0;
  *(int *)(param_1 + 0x75a0) = param_4;
  iVar1 = msys::MComSys::_sys;
  iVar5 = *(int *)(param_4 + 8);
  if (*(int *)(param_4 + 8) == 0) {
    *(int *)(param_4 + 8) = msys::MComSys::_sys;
    iVar5 = iVar1;
  }
  pMVar8 = param_1 + 0x6f80;
  do {
    pMVar8[8] = (MListWndPBase)0xff;
    pMVar8[6] = (MListWndPBase)0xff;
    pMVar8[0xf] = (MListWndPBase)0x0;
    *(undefined4 *)(pMVar8 + 0x14) = 0;
    pMVar8 = pMVar8 + 0x1c;
  } while (pMVar8 != param_1 + 0x75a0);
  ad::ui::UIListWindowPlusLyt::InitParam::InitParam((InitParam *)local_1b8);
  msys::SetMListWndInitParam(local_1b8,0);
  local_fc = local_104;
  uStack_f8 = uStack_100;
  local_1b8[0] = (void *)(iVar5 + 0x4af6c);
  local_1b0 = (CellAnime *)(param_1 + 0x76c4);
  local_180 = (**(code **)(**(int **)(param_1 + 0x75b4) + 0x2c))
                        (*(int **)(param_1 + 0x75b4),"FRAME",1);
  local_188 = (**(code **)(**(int **)(param_1 + 0x75b4) + 0x2c))
                        (*(int **)(param_1 + 0x75b4),"list_cursor",1);
  local_18c = (**(code **)(**(int **)(param_1 + 0x75b4) + 0x2c))
                        (*(int **)(param_1 + 0x75b4),"list_scroll",1);
  local_15c = local_30;
  local_198 = *(undefined4 *)(param_1 + 0x7628);
  local_168 = local_34;
  local_164 = local_38;
  local_78 = 0;
  local_160 = local_3c;
  local_158 = local_40;
  local_7c = param_1 + 0x6f80;
  msys::MListWndPBase::init
            (param_1,(InitParam *)local_1b8,(LytDrawData *)(iVar5 + 0xd3000),
             (Prim *)(iVar5 + 0xd3100),(MessageDrawer *)(iVar5 + 0x1487c),
             (ApplyingSceneInfo *)(iVar5 + 0x4af54));
  *(undefined4 *)(param_1 + 0x13c) = 0x401;
  *(undefined4 *)(param_1 + 0x168) = 0x401;
  return;
}


// FUNC 0x15004bac main_menu::MainMenu_ItemPage::Core::MListWndItem::vfunc_0x4 (MainMenu)
//   size 0x74 | file MainMenu+0x4bac | callers(0) | datarefs 1

void main_menu::MainMenu_ItemPage::Core::MListWndItem::vfunc_0x4(undefined4 *param_1)

{
  int iVar1;
  void *pvVar2;
  
  *param_1 = &vtable;
  iVar1 = CellAnime::~CellAnime((CellAnime *)(param_1 + 0x1dfc));
  iVar1 = CellAnime::~CellAnime((CellAnime *)(iVar1 + -300));
  *(undefined4 *)(iVar1 + -0x10) = 0;
  *(undefined4 *)(iVar1 + -0x2c) = 0;
  *(undefined4 *)(iVar1 + -0x48) = 0;
  *(undefined4 *)(iVar1 + -100) = 0;
  iVar1 = ad::lyt::Layout::~Layout((Layout *)(iVar1 + -0xac));
  *(undefined4 *)(iVar1 + -0x10) = 0;
  *(undefined4 *)(iVar1 + -0x2c) = 0;
  iVar1 = ad::lyt::Layout::~Layout((Layout *)(iVar1 + -0x74));
  *(undefined ***)(iVar1 + -0x75a4) = &vtable_for_N4msys9MListWndPILi56EEE;
  iVar1 = ad::ui::UIListWindowPlusLyt::~UIListWindowPlusLyt
                    ((UIListWindowPlusLyt *)(iVar1 + -0x73a8));
  pvVar2 = (void *)msys::MListWndPBase::~MListWndPBase((MListWndPBase *)(iVar1 + -0x1fc));
  operator_delete(pvVar2);
  return;
}


// FUNC 0x15004c2c main_menu::MainMenu_ItemPage::Core::MListWndItem::vfunc_0x0 (MainMenu)
//   size 0x70 | file MainMenu+0x4c2c | callers(0) | datarefs 1

void main_menu::MainMenu_ItemPage::Core::MListWndItem::vfunc_0x0(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &vtable;
  iVar1 = CellAnime::~CellAnime((CellAnime *)(param_1 + 0x1dfc));
  iVar1 = CellAnime::~CellAnime((CellAnime *)(iVar1 + -300));
  *(undefined4 *)(iVar1 + -0x10) = 0;
  *(undefined4 *)(iVar1 + -0x2c) = 0;
  *(undefined4 *)(iVar1 + -0x48) = 0;
  *(undefined4 *)(iVar1 + -100) = 0;
  iVar1 = ad::lyt::Layout::~Layout((Layout *)(iVar1 + -0xac));
  *(undefined4 *)(iVar1 + -0x10) = 0;
  *(undefined4 *)(iVar1 + -0x2c) = 0;
  iVar1 = ad::lyt::Layout::~Layout((Layout *)(iVar1 + -0x74));
  *(undefined ***)(iVar1 + -0x75a4) = &vtable_for_N4msys9MListWndPILi56EEE;
  iVar1 = ad::ui::UIListWindowPlusLyt::~UIListWindowPlusLyt
                    ((UIListWindowPlusLyt *)(iVar1 + -0x73a8));
  msys::MListWndPBase::~MListWndPBase((MListWndPBase *)(iVar1 + -0x1fc));
  return;
}


// FUNC 0x15004cbc FUN_15004cbc (MainMenu)
//   size 0xe4 | file MainMenu+0x4cbc | callers(0) | datarefs 1

void FUN_15004cbc(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  MListWndPBase *this;
  int iVar2;
  undefined2 *puVar3;
  
  if (param_3 != 4) {
    return;
  }
  FUN_1501580c(msys::MComSys::_sys + 0x49368,0x110015,0,0);
  (**(code **)(**(int **)(param_4 + *(char *)(param_4 + 0x870) * 4 + 0x1e750) + 0x18))();
  this = (MListWndPBase *)(param_4 + 0x1e778);
  *(undefined1 *)(param_4 + 0x870) = *(undefined1 *)(param_1 + 0x48);
  FUN_15013bb0();
  iVar1 = msys::MComSys::_sys;
  iVar2 = *(int *)(param_4 + 8);
  if (*(int *)(param_4 + 8) == 0) {
    *(int *)(param_4 + 8) = msys::MComSys::_sys;
    iVar2 = iVar1;
  }
  *(undefined1 *)(iVar2 + 0xe6508) = 1;
  iVar2 = msys::MListWndPBase::getListWnd(this);
  if (*(char *)(iVar2 + 0x144) != '\0') {
    msys::MListWndPBase::getListWnd(this);
    puVar3 = (undefined2 *)ad::ui::UIListWindowPlusLyt::getCurItem();
    FUN_15013ad0(param_4,*puVar3);
  }
  iVar2 = msys::MListWndPBase::getListWnd(this);
  *(undefined1 *)(param_4 + 0x872) = *(undefined1 *)(iVar2 + 0x149);
  FUN_150138ec(param_4);
  return;
}


// FUNC 0x1500549c FUN_1500549c (MainMenu)
//   size 0xec | file MainMenu+0x549c | callers(0) | datarefs 2

void FUN_1500549c(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  
  iVar2 = msys::MLyt::isBusyAnime((MLyt *)(param_1 + 0x110));
  if ((iVar2 == 0) && (iVar2 = msys::MLyt::isBusyAnime((MLyt *)(param_1 + 0x4b8)), iVar2 == 0)) {
    *(undefined1 *)(param_1 + 0x1e8b8) = 1;
    msys::MListWndPBase::setEnableInput((MListWndPBase *)(param_1 + 0x1e778),true);
    iVar1 = msys::MComSys::_sys;
    uVar4 = 0;
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
    do {
      piVar3 = *(int **)(param_1 + uVar4 * 4 + 0x1e750);
      (**(code **)(*piVar3 + 0x28))(piVar3,1);
      uVar4 = uVar4 + 1 & 0xff;
    } while (uVar4 < 3);
    uVar4 = 0;
    do {
      piVar3 = *(int **)(param_1 + uVar4 * 4 + 0x1e75c);
      (**(code **)(*piVar3 + 0x28))(piVar3,0);
      uVar4 = uVar4 + 1 & 0xff;
    } while (uVar4 < 7);
    *(code **)(param_1 + 0x20) = FUN_15006d44;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x15005590 main_menu::MainMenu_ItemPage::Core::vfunc_0x10 (MainMenu)
//   size 0x100 | file MainMenu+0x5590 | callers(0) | datarefs 1

void main_menu::MainMenu_ItemPage::Core::vfunc_0x10(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_2 == 4) {
    FUN_1501580c(msys::MComSys::_sys + 0x49368,0x110017,0,0,0);
    iVar1 = msys::MComSys::_sys;
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar1;
    }
    *(undefined1 *)(iVar2 + 0xe6508) = 0;
    return;
  }
  if (param_2 == 5) {
    iVar2 = *(int *)(*(int *)(param_1 + 0x860) + 0x48);
    if (iVar2 == 0) {
      *(undefined1 *)(param_1 + 0x873) = 0;
      msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x4b8),1,1,(char *)0x0,(char *)0x0);
      msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x110),1,1,(char *)0x0,(char *)0x0);
      iVar2 = msys::MListWndPBase::getListWnd((MListWndPBase *)(param_1 + 0x1e778));
      if (*(char *)(iVar2 + 0x144) != '\0') {
        msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x110),5,0,"EXP_PNL_U",(char *)0x0);
      }
      *(code **)(param_1 + 0x20) = FUN_15005848;
      *(undefined4 *)(param_1 + 0x24) = 0;
      return;
    }
    if (iVar2 == 1) {
      *(code **)(param_1 + 0x20) = FUN_15006534;
      *(undefined4 *)(param_1 + 0x24) = 0;
    }
  }
  return;
}


// FUNC 0x150056ac FUN_150056ac (MainMenu)
//   size 0x68 | file MainMenu+0x56ac | callers(0) | datarefs 1

void FUN_150056ac(int param_1)

{
  MComSys *pMVar1;
  int iVar2;
  MComSys *this;
  
  iVar2 = msys::MLyt::isBusyAnime((MLyt *)(param_1 + 0x4b8));
  if ((iVar2 == 0) &&
     (iVar2 = msys::MLyt::isBusyAnime((MLyt *)(param_1 + 0x110)), pMVar1 = msys::MComSys::_sys,
     iVar2 == 0)) {
    this = *(MComSys **)(param_1 + 8);
    if (*(MComSys **)(param_1 + 8) == (MComSys *)0x0) {
      *(MComSys **)(param_1 + 8) = msys::MComSys::_sys;
      this = pMVar1;
    }
    iVar2 = msys::MComSys::getNextPage(this);
    if (*(char *)(iVar2 + 0x14) != '\0') {
      *(undefined1 **)(param_1 + 0x18) = &LAB_15006a50;
      *(undefined4 *)(param_1 + 0x1c) = 0;
    }
  }
  return;
}


// FUNC 0x15005730 FUN_15005730 (MainMenu)
//   size 0x10c | file MainMenu+0x5730 | callers(1) 0x1500590c

void FUN_15005730(int param_1)

{
  int iVar1;
  int iVar2;
  StatusPanel *pSVar3;
  uint uVar4;
  int iVar5;
  
  uVar4 = 0;
  do {
    iVar2 = msys::MComSys::_sys;
    iVar1 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar1 = iVar2;
    }
    iVar5 = param_1 + uVar4 * 0x2034;
    pSVar3 = (StatusPanel *)(iVar5 + 0x11730);
    msys::StatusPanel::setParam(pSVar3,(DataPc *)(iVar1 + uVar4 * 0xb0 + 0xeac64));
    iVar2 = msys::MComSys::_sys;
    iVar1 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar1 = iVar2;
    }
    msys::StatusPanel::setParam(pSVar3,(DataPc *)(iVar1 + uVar4 * 0xb0 + 0xeac64));
    iVar2 = msys::MComSys::_sys;
    iVar1 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar1 = iVar2;
    }
    msys::StatusPanel::setParam(pSVar3,(DataPc *)(iVar1 + uVar4 * 0xb0 + 0xeac64));
    iVar2 = msys::MComSys::_sys;
    iVar1 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar1 = iVar2;
    }
    pSVar3 = (StatusPanel *)(iVar5 + 0x177cc);
    msys::StatusPanel::setParam(pSVar3,(DataPc *)(iVar1 + uVar4 * 0xb0 + 0xeac64));
    iVar2 = msys::MComSys::_sys;
    iVar1 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar1 = iVar2;
    }
    msys::StatusPanel::setParam(pSVar3,(DataPc *)(iVar1 + uVar4 * 0xb0 + 0xeac64));
    iVar2 = msys::MComSys::_sys;
    iVar1 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar1 = iVar2;
    }
    msys::StatusPanel::setParam(pSVar3,(DataPc *)(iVar1 + uVar4 * 0xb0 + 0xeac64));
    uVar4 = uVar4 + 1 & 0xff;
  } while (uVar4 < 3);
  return;
}


// FUNC 0x15005848 FUN_15005848 (MainMenu)
//   size 0x94 | file MainMenu+0x5848 | callers(0) | datarefs 2

void FUN_15005848(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = msys::MComSys::_sys;
  if (*(int *)(param_1 + 8) == 0) {
    *(undefined4 *)(param_1 + 8) = msys::MComSys::_sys;
  }
  iVar2 = *(int *)(param_1 + 8);
  if (*(float *)(iVar2 + 0x4ad44) <= *(float *)(iVar2 + 0x4ad40)) {
    if (iVar2 == 0) {
      *(undefined4 *)(param_1 + 8) = uVar1;
    }
    if (((*(float *)(*(int *)(param_1 + 8) + 0x4ad04) <= *(float *)(*(int *)(param_1 + 8) + 0x4ad00)
         ) && (iVar2 = msys::MLyt::isBusyAnime((MLyt *)(param_1 + 0x110)), iVar2 == 0)) &&
       (iVar2 = msys::MLyt::isBusyAnime((MLyt *)(param_1 + 0x4b8)), iVar2 == 0)) {
      *(undefined1 *)(param_1 + 0x865) = *(undefined1 *)(param_1 + 0x873);
    }
  }
  return;
}


// FUNC 0x1500590c FUN_1500590c (MainMenu)
//   size 0x5b0 | file MainMenu+0x590c | callers(0) | datarefs 2

void FUN_1500590c(int param_1)

{
  char cVar1;
  bool bVar2;
  undefined1 uVar3;
  MListWndPBase *this;
  ushort *puVar4;
  char *pcVar5;
  int iVar6;
  undefined4 uVar7;
  wchar_t *pwVar8;
  int iVar9;
  code *pcVar10;
  ushort uVar11;
  undefined4 unaff_r5;
  ushort *puVar12;
  uint uVar13;
  char *pcVar14;
  
  this = (MListWndPBase *)(param_1 + 0x1e778);
  msys::MListWndPBase::getListWnd(this);
  puVar4 = (ushort *)ad::ui::UIListWindowPlusLyt::getCurItem();
  pcVar5 = (char *)ad::db::GetUseItem(*puVar4);
  uVar11 = *(ushort *)(pcVar5 + 0x6a);
  bVar2 = false;
  pcVar14 = &DAT_003f9690 + (*puVar4 & 0xfff);
  if ((uVar11 & 0xfe00) == 0) {
    cVar1 = *(char *)(param_1 + 0x871);
    if (cVar1 == '\x04') {
      unaff_r5 = 1;
    }
    else if (cVar1 == '\x05') {
      unaff_r5 = 0;
    }
    else if (cVar1 == '\x06') {
      unaff_r5 = 2;
    }
    iVar6 = FUN_15013eb8(param_1,pcVar5,unaff_r5);
joined_r0x15005a10:
    if (iVar6 != 0) {
      FUN_15013468(param_1,pcVar5,unaff_r5);
LAB_15005aa0:
      puVar4[2] = puVar4[2] - 1;
      cVar1 = *pcVar14;
      *pcVar14 = cVar1 + -1;
      if ((char)(cVar1 + -1) == '\x01') {
        uVar7 = ad::db::GetItemMsgCore(pcVar5);
        *(undefined4 *)(puVar4 + 8) = uVar7;
        iVar6 = ad::db::GetItemMsgAcs();
        uVar7 = LMS_GetTextIndexByLabel(iVar6 + 8,pcVar5);
        pwVar8 = (wchar_t *)LMS_GetText(iVar6 + 8,uVar7);
        msys::MMsg::playStr((MMsg *)(param_1 + 0xa5d8),pwVar8,(InsParam *)0x0,false);
      }
      FUN_15005730(param_1);
      iVar6 = param_1 + 0x1121c;
      if (*(byte *)(param_1 + 0x870) < 2) {
        *(undefined1 *)(param_1 + 0x1135d) = 1;
        *(undefined1 *)(param_1 + 0x115d9) = 0;
      }
      else {
        *(undefined1 *)(param_1 + 0x1135d) = 0;
        *(undefined1 *)(param_1 + 0x115d9) = 1;
        iVar6 = param_1 + 0x11498;
      }
      CellAnime::play((CellAnime *)(iVar6 + 0x14c),*(uchar *)((int)puVar4 + 0xb),0,1.0);
      ad::lyt::LytNumReel3::setValueInstant((LytNumReel3 *)(param_1 + 0xa4f8),(uint)puVar4[2]);
      msys::MMsg::playStr((MMsg *)(param_1 + 0xa5d8),*(wchar_t **)(puVar4 + 8),(InsParam *)0x0,false
                         );
      if (*(char *)(param_1 + 0x870) == '\0') {
        FUN_1501580c(msys::MComSys::_sys + 0x49368,0x110019,0,0,0);
      }
      else {
        FUN_1501580c(msys::MComSys::_sys + 0x49368,0x11001a,0,0,0);
      }
      iVar6 = msys::MListWndPBase::getListWnd(this);
      puVar12 = *(ushort **)(iVar6 + 0x140);
      iVar6 = msys::MListWndPBase::getListWnd(this);
      for (uVar13 = (uint)*(byte *)(iVar6 + 0x144); uVar13 != 0; uVar13 = uVar13 - 1) {
        iVar6 = ad::db::GetUseItem(*puVar12);
        uVar11 = *(ushort *)(iVar6 + 0x6a) >> 9;
        if (uVar11 == 0) {
          uVar7 = ad::db::GetUseItem(*puVar12);
          iVar6 = FUN_15013eb8(param_1,uVar7,0);
          if (iVar6 == 0) {
            uVar7 = ad::db::GetUseItem(*puVar12);
            iVar6 = FUN_15013eb8(param_1,uVar7,1);
            if (iVar6 == 0) {
              uVar7 = ad::db::GetUseItem(*puVar12);
              iVar6 = FUN_15013eb8(param_1,uVar7,2);
              uVar3 = 0;
              if (iVar6 == 0) goto LAB_15005c80;
            }
          }
          goto LAB_15005d68;
        }
        if (uVar11 == 1) {
          uVar7 = ad::db::GetUseItem(*puVar12);
          iVar6 = FUN_15013eb8(param_1,uVar7,0);
          if (iVar6 == 0) {
            uVar7 = ad::db::GetUseItem(*puVar12);
            iVar6 = FUN_15013eb8(param_1,uVar7,1);
            uVar3 = 0;
            if (iVar6 != 0) goto LAB_15005d68;
          }
          else {
LAB_15005d68:
            uVar3 = 1;
          }
LAB_15005c80:
          *(undefined1 *)(puVar12 + 7) = uVar3;
        }
        else if (uVar11 == 2) {
          uVar7 = ad::db::GetUseItem(*puVar12);
          uVar3 = FUN_15013eb8(param_1,uVar7,2);
          *(undefined1 *)(puVar12 + 7) = uVar3;
        }
        puVar12 = puVar12 + 0xe;
      }
      iVar6 = ad::db::GetUseItem(*puVar4);
      if (*pcVar14 != '\0') {
        uVar11 = *(ushort *)(iVar6 + 0x6a) >> 9;
        if (uVar11 == 0) {
          iVar9 = FUN_15013eb8(param_1,iVar6,0);
          if ((iVar9 != 0) || (iVar9 = FUN_15013eb8(param_1,iVar6,1), iVar9 != 0))
          goto LAB_15005e20;
          iVar6 = FUN_15013eb8(param_1,iVar6,2);
        }
        else if (uVar11 == 1) {
          iVar9 = FUN_15013eb8(param_1,iVar6,0);
          if (iVar9 != 0) goto LAB_15005e20;
          iVar6 = FUN_15013eb8(param_1,iVar6,1);
        }
        else {
          if (uVar11 != 2) goto LAB_15005e68;
          iVar6 = FUN_15013eb8(param_1,iVar6,2);
        }
        if (iVar6 != 0) {
LAB_15005e20:
          iVar9 = msys::MComSys::_sys;
          iVar6 = *(int *)(param_1 + 8);
          if (*(int *)(param_1 + 8) == 0) {
            *(int *)(param_1 + 8) = msys::MComSys::_sys;
            iVar6 = iVar9;
          }
          *(undefined1 *)(iVar6 + 0xe6508) = 1;
          *(code **)(param_1 + 0x20) = FUN_15005ee0;
          *(undefined4 *)(param_1 + 0x24) = 0;
          return;
        }
      }
LAB_15005e68:
      Frm::play((Frm *)(param_1 + 0x8c0),20.0);
      pcVar10 = FUN_15006534;
      goto LAB_15005ec8;
    }
  }
  else if (uVar11 >> 9 == 1) {
    if ((uVar11 & 0x100) == 0) {
      if (*(char *)(param_1 + 0x871) == '\0') {
        unaff_r5 = 1;
      }
      else if (*(char *)(param_1 + 0x871) == '\x01') {
        unaff_r5 = 0;
      }
      iVar6 = FUN_15013eb8(param_1,pcVar5,unaff_r5);
      goto joined_r0x15005a10;
    }
    uVar11 = 0;
    do {
      iVar6 = FUN_15013eb8(param_1,pcVar5,uVar11 & 0xff);
      if (iVar6 != 0) {
        bVar2 = true;
        FUN_15013468(param_1,pcVar5,uVar11 & 0xff);
      }
      uVar11 = uVar11 + 1;
    } while ((short)uVar11 < 2);
    if (bVar2) goto LAB_15005aa0;
  }
  else if ((uVar11 >> 9 == 2) && (iVar6 = FUN_15013eb8(param_1,pcVar5,2), iVar6 != 0)) {
    FUN_15013468(param_1,pcVar5,2);
    goto LAB_15005aa0;
  }
  FUN_1501580c(msys::MComSys::_sys + 0x49368,0x110018,0,0,0);
  iVar9 = msys::MComSys::_sys;
  iVar6 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar6 = iVar9;
  }
  *(undefined1 *)(iVar6 + 0xe6508) = 1;
  pcVar10 = FUN_15005ee0;
LAB_15005ec8:
  *(code **)(param_1 + 0x20) = pcVar10;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


// FUNC 0x15005ee0 FUN_15005ee0 (MainMenu)
//   size 0x1dc | file MainMenu+0x5ee0 | callers(0) | datarefs 6

void FUN_15005ee0(int param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  char in_OV;
  bool bVar4;
  
  uVar1 = *param_2;
  iVar2 = (int)*(char *)(param_1 + 0x871);
  if ((uVar1 & 0x401) != 0) {
    (**(code **)(**(int **)(param_1 + iVar2 * 4 + 0x1e75c) + 0x18))();
    (**(code **)(**(int **)(param_1 + *(char *)(param_1 + 0x871) * 4 + 0x1e75c) + 0x10))();
    (**(code **)(**(int **)(param_1 + *(char *)(param_1 + 0x871) * 4 + 0x1e75c) + 0xc))();
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
    goto LAB_150060b0;
  }
  if ((uVar1 & 0x802) != 0) {
    (**(code **)(**(int **)(param_1 + 0x860) + 0x10))();
    iVar3 = msys::MComSys::_sys;
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar3;
    }
    *(undefined1 *)(iVar2 + 0xe6508) = 0;
    goto LAB_150060b0;
  }
  if ((uVar1 & 0x30) == 0) goto LAB_150060b0;
  iVar3 = iVar2;
  if ((uVar1 & 0x10) == 0) {
    bVar4 = (uVar1 & 0x20) != 0;
    if (bVar4) {
      uVar1 = iVar2 - 1;
      in_OV = SCARRY4(uVar1,1);
    }
    if ((bVar4 && uVar1 != 0xffffffff) && (bVar4 && (int)(uVar1 + 1) < 0) == (bool)in_OV) {
      do {
        if ((*(byte *)(*(int *)(param_1 + uVar1 * 4 + 0x1e75c) + 8) & 0x10) != 0) goto LAB_15006048;
        uVar1 = (uint)(short)((short)uVar1 + -1);
      } while (uVar1 < 0x80000000);
    }
  }
  else {
    for (uVar1 = iVar2 + 1; (int)uVar1 < 7; uVar1 = (uint)(short)((short)uVar1 + 1)) {
      if ((*(byte *)(*(int *)(param_1 + uVar1 * 4 + 0x1e75c) + 8) & 0x10) != 0) goto LAB_15006048;
    }
  }
  goto LAB_15006060;
LAB_15006048:
  iVar3 = (int)(char)uVar1;
LAB_15006060:
  if (iVar2 != iVar3) {
    FUN_1501580c(msys::MComSys::_sys + 0x49368,0x110015,0,0,0);
    (**(code **)(**(int **)(param_1 + *(char *)(param_1 + 0x871) * 4 + 0x1e75c) + 0xc))();
    *(char *)(param_1 + 0x871) = (char)iVar3;
    *(char *)(param_1 + 0x88c) = (char)iVar3;
  }
LAB_150060b0:
  FUN_150131d0(param_1 + 0x874);
  return;
}


// FUNC 0x150060cc FUN_150060cc (MainMenu)
//   size 0xb4 | file MainMenu+0x60cc | callers(0) | datarefs 2

void FUN_150060cc(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  
  iVar1 = msys::MLyt::isBusyAnime((MLyt *)(param_1 + 0x110));
  if ((iVar1 == 0) &&
     (iVar2 = msys::MLyt::isBusyAnime((MLyt *)(param_1 + 0x4b8)), iVar1 = msys::MComSys::_sys,
     iVar2 == 0)) {
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar1;
    }
    *(undefined1 *)(iVar2 + 0xe6508) = 1;
    msys::MListWndPBase::setEnableInput((MListWndPBase *)(param_1 + 0x1e778),true);
    uVar4 = 0;
    do {
      piVar3 = *(int **)(param_1 + uVar4 * 4 + 0x1e750);
      (**(code **)(*piVar3 + 0x28))(piVar3,1);
      uVar4 = uVar4 + 1 & 0xff;
    } while (uVar4 < 3);
    *(undefined4 *)(*(int *)(param_1 + 0x860) + 0x48) = 0;
    FUN_150138ec(param_1);
    *(code **)(param_1 + 0x20) = FUN_15006d44;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x15006188 FUN_15006188 (MainMenu)
//   size 0x140 | file MainMenu+0x6188 | callers(0) | datarefs 2

void FUN_15006188(int param_1)

{
  MLyt *this;
  MListWndPBase *this_00;
  int iVar1;
  undefined2 *puVar2;
  int *piVar3;
  uint uVar4;
  
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x110),2,0,(char *)0x0,(char *)0x0);
  this = (MLyt *)(param_1 + 0x4b8);
  msys::MLyt::playAnimeFromNo(this,2,0,(char *)0x0,(char *)0x0);
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x110),4,0,(char *)0x0,(char *)0x0);
  msys::MLyt::playAnimeFromNo(this,4,0,(char *)0x0,(char *)0x0);
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x110),3,0,(char *)0x0,(char *)0x0);
  msys::MLyt::playAnimeFromNo(this,3,0,(char *)0x0,(char *)0x0);
  this_00 = (MListWndPBase *)(param_1 + 0x1e778);
  iVar1 = msys::MListWndPBase::getListWnd(this_00);
  *(undefined1 *)(iVar1 + 0x6d79) = 1;
  iVar1 = msys::MListWndPBase::getListWnd(this_00);
  if (*(char *)(iVar1 + 0x144) != '\0') {
    msys::MListWndPBase::getListWnd(this_00);
    puVar2 = (undefined2 *)ad::ui::UIListWindowPlusLyt::getCurItem();
    FUN_15013ad0(param_1,*puVar2);
  }
  uVar4 = 0;
  do {
    piVar3 = *(int **)(param_1 + uVar4 * 4 + 0x1e75c);
    (**(code **)(*piVar3 + 0x28))(piVar3,0);
    uVar4 = uVar4 + 1 & 0xff;
  } while (uVar4 < 7);
  msys::MCursorBase::setVisible((MCursorBase *)(param_1 + 0x874),false);
  *(code **)(param_1 + 0x20) = FUN_150060cc;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


// FUNC 0x150062cc FUN_150062cc (MainMenu)
//   size 0xd4 | file MainMenu+0x62cc | callers(0) | datarefs 1

void FUN_150062cc(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  float fVar8;
  
  iVar1 = msys::MComSys::_sys;
  fVar8 = 1.0;
  if ((*(byte *)(param_1 + 0xa34a) & 1) == 0) {
    iVar2 = *(int *)(param_1 + 0xa334);
    iVar7 = *(int *)(param_1 + 0xa338);
    iVar4 = *(int *)(iVar2 + 8);
    if (iVar4 == 0) {
      *(int *)(iVar2 + 8) = msys::MComSys::_sys;
      iVar4 = iVar1;
    }
    iVar1 = ad::fw::TaskBase::isFps30(*(TaskBase **)(iVar4 + 4));
    if (iVar1 != 0) {
      fVar8 = 2.0;
    }
    puVar3 = (undefined4 *)MoveVBase::update((MoveVBase *)(param_1 + 0xa34c),fVar8);
    uVar5 = puVar3[1];
    uVar6 = puVar3[2];
    *(undefined4 *)(iVar7 + 0x1c) = *puVar3;
    *(undefined4 *)(iVar7 + 0x20) = uVar5;
    *(undefined4 *)(iVar7 + 0x24) = uVar6;
    *(byte *)(iVar7 + 0x44) = *(byte *)(iVar7 + 0x44) & 0xef | 0x10;
    *(undefined1 *)(*(int *)(param_1 + 0xa334) + 0x82c) = 1;
  }
  else {
    Frm::update(1.0);
  }
  iVar1 = msys::MLyt::isBusyAnime((MLyt *)(param_1 + 0x4b8));
  if ((iVar1 == 0) && (iVar1 = MoveVBase::isBusy((MoveVBase *)(param_1 + 0xa34c)), iVar1 == 0)) {
    *(code **)(param_1 + 0x20) = FUN_150063b0;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x150063b0 FUN_150063b0 (MainMenu)
//   size 0x17c | file MainMenu+0x63b0 | callers(0) | datarefs 2

void FUN_150063b0(int param_1)

{
  ushort uVar1;
  ushort *puVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  puVar2 = (ushort *)msys::MListWndPBase::getCurItem();
  iVar3 = ad::db::GetUseItem(*puVar2);
  iVar5 = 0;
  do {
    piVar4 = *(int **)(param_1 + iVar5 * 4 + 0x1e75c);
    (**(code **)(*piVar4 + 0x28))(piVar4,0);
    iVar5 = (int)(short)((short)iVar5 + 1);
  } while (iVar5 < 7);
  uVar1 = *(ushort *)(iVar3 + 0x6a) >> 9;
  if (uVar1 == 0) {
    (**(code **)(**(int **)(param_1 + 0x1e76c) + 0x28))(*(int **)(param_1 + 0x1e76c),1);
    (**(code **)(**(int **)(param_1 + 0x1e770) + 0x28))(*(int **)(param_1 + 0x1e770),1);
    (**(code **)(**(int **)(param_1 + 0x1e774) + 0x28))(*(int **)(param_1 + 0x1e774),1);
  }
  else if (uVar1 == 1) {
    if ((*(ushort *)(iVar3 + 0x6a) & 0x100) == 0) {
      (**(code **)(**(int **)(param_1 + 0x1e75c) + 0x28))(*(int **)(param_1 + 0x1e75c),1);
      (**(code **)(**(int **)(param_1 + 0x1e760) + 0x28))(*(int **)(param_1 + 0x1e760),1);
    }
    else {
      (**(code **)(**(int **)(param_1 + 0x1e764) + 0x28))(*(int **)(param_1 + 0x1e764),1);
    }
  }
  else if (uVar1 == 2) {
    (**(code **)(**(int **)(param_1 + 0x1e768) + 0x28))(*(int **)(param_1 + 0x1e768),1);
  }
  *(undefined4 *)(*(int *)(param_1 + 0x860) + 0x48) = 1;
  *(undefined1 *)(param_1 + 0x88c) = *(undefined1 *)(param_1 + 0x871);
  msys::MCursorBase::setVisible((MCursorBase *)(param_1 + 0x874),true);
  FUN_150131d0((MCursorBase *)(param_1 + 0x874));
  iVar3 = msys::MComSys::_sys;
  iVar5 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar5 = iVar3;
  }
  *(undefined1 *)(iVar5 + 0xe6508) = 1;
  *(code **)(param_1 + 0x20) = FUN_15005ee0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


// FUNC 0x15006534 FUN_15006534 (MainMenu)
//   size 0x10c | file MainMenu+0x6534 | callers(0) | datarefs 4

void FUN_15006534(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint in_fpscr;
  float fVar5;
  
  iVar2 = msys::MComSys::_sys;
  uVar1 = 0;
  do {
    iVar4 = param_1 + uVar1 * 0x17c;
    if (*(int *)(iVar4 + 0x7800) != 0) {
      return;
    }
    if (*(int *)(iVar4 + 0x86d8) != 0) {
      return;
    }
    if (*(int *)(iVar4 + 0x95b0) != 0) {
      return;
    }
    uVar1 = uVar1 + 1 & 0xff;
  } while (uVar1 < 10);
  iVar4 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar4 = iVar2;
  }
  iVar2 = ad::fw::TaskBase::isFps30(*(TaskBase **)(iVar4 + 4));
  if (iVar2 == 0) {
    uVar3 = 1;
  }
  else {
    uVar3 = 2;
  }
  fVar5 = (float)VectorUnsignedToFloat(uVar3,(byte)(in_fpscr >> 0x16) & 3);
  Frm::update(fVar5);
  if ((*(byte *)(param_1 + 0x8ce) & 1) == 0) {
    FUN_15013bb0(param_1 + 0x1e778,(int)*(char *)(param_1 + 0x870));
    uVar1 = 0;
    do {
      iVar2 = param_1 + uVar1 * 0x17c;
      msys::MDfxChr::term((MDfxChr *)(iVar2 + 0x76ac));
      msys::MDfxChr::term((MDfxChr *)(iVar2 + 0x8584));
      msys::MDfxChr::term((MDfxChr *)(iVar2 + 0x945c));
      uVar1 = uVar1 + 1 & 0xff;
    } while (uVar1 < 10);
    *(code **)(param_1 + 0x20) = FUN_15006188;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x1500664c main_menu::MainMenu_ItemPage::Core::vfunc_0x8 (MainMenu)
//   size 0xfc | file MainMenu+0x664c | callers(0) | datarefs 1

int main_menu::MainMenu_ItemPage::Core::vfunc_0x8(int *param_1,MInput *param_2)

{
  MInput MVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  code *extraout_r2;
  code *pcVar6;
  VEC2 *pVVar7;
  bool bVar8;
  uint in_fpscr;
  undefined4 local_20;
  undefined4 local_1c;
  
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
  iVar4 = msys::MListWndPBase::isTpNeutral((MListWndPBase *)(param_1 + 0x79de));
  MVar1 = param_2[0x11];
  bVar8 = MVar1 == (MInput)0x0;
  if (bVar8) {
    MVar1 = param_2[0x12];
  }
  pVVar7 = (VEC2 *)0x0;
  if ((!bVar8 || MVar1 != (MInput)0x0) && iVar4 != 0) {
    local_20 = VectorSignedToFloat(*(ushort *)(param_2 + 0x14) - 0xa0,(byte)(in_fpscr >> 0x16) & 3);
    local_1c = VectorSignedToFloat(0x78 - (uint)*(ushort *)(param_2 + 0x16),
                                   (byte)(in_fpscr >> 0x16) & 3);
    pVVar7 = (VEC2 *)&local_20;
  }
  bVar8 = (bool)(**(code **)(*param_1 + 0xc))(param_1,param_2);
  iVar2 = msys::MComSys::_sys;
  iVar5 = param_1[2];
  if (param_1[2] == 0) {
    param_1[2] = msys::MComSys::_sys;
    iVar5 = iVar2;
  }
  ad::ctrl::ButtonGroup::Update
            ((ButtonGroup *)(param_1 + 0xf),pVVar7,
             (bool)(*(byte *)(iVar5 + 0xe6508) & bVar8 & (byte)iVar4),bVar8);
  return (int)*(char *)((int)param_1 + 0x865);
}


// FUNC 0x1500674c FUN_1500674c (MainMenu)
//   size 0x2c4 | file MainMenu+0x674c | callers(1) 0x15003edc

void FUN_1500674c(int *param_1,int param_2)

{
  int iVar1;
  MLyt *this;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  InitParam aIStack_80 [72];
  
  *param_1 = param_2;
  iVar1 = msys::MListWndPBase::getListWnd((MListWndPBase *)(param_2 + 0x1e778));
  fVar4 = *(float *)(iVar1 + 0xec);
  fVar6 = *(float *)(iVar1 + 0xe8);
  fVar8 = *(float *)(iVar1 + 0xe8);
  fVar7 = *(float *)(iVar1 + 0xd0);
  fVar3 = *(float *)(iVar1 + 0xd4);
  fVar5 = *(float *)(iVar1 + 0xec);
  fVar9 = *(float *)(iVar1 + 0xb8) - fVar8;
  fVar10 = *(float *)(iVar1 + 0xbc) - fVar5;
  this = (MLyt *)(param_2 + 0x4b8);
  iVar1 = msys::MLyt::getPane(this,"NAME_BAR",(char *)0x0,(char *)0x0);
  param_1[1] = iVar1;
  iVar1 = *(int *)(*(int *)(param_2 + 4) + 0x18);
  param_1[0x1bb9] = 0x401;
  param_1[0x1bb6] = iVar1;
  param_1[0x1bb7] = 0;
  param_1[0x1bb8] = 0;
  MessageSimple::init((MessageSimple *)(param_1 + 0xfc));
  FUN_150142ec(param_1 + 0xa9);
  msys::MLyt::attachMChr
            (this,(MChrBase *)(param_1 + 0xa9),"list_text",(char *)0x0,(char *)0x0,(char *)0x0);
  if ((char)param_1[0xad] == '\x02') {
    iVar1 = param_1[0xac];
  }
  else {
    iVar1 = 0;
  }
  iVar1 = *(int *)(iVar1 + 8);
  *(undefined4 *)(iVar1 + 0x24) = 0;
  *(float *)(iVar1 + 0x1c) = -fVar6;
  *(float *)(iVar1 + 0x20) = -fVar4 - 1.0;
  *(byte *)(iVar1 + 0x44) = *(byte *)(iVar1 + 0x44) & 0xef | 0x10;
  MessageWriter::setFontColor((MessageWriter *)(param_1 + 0xfc),0xe6e6e6ff,true);
  ad::lyt::LytNumReel3::InitParam::InitParam(aIStack_80);
  iVar2 = msys::MComSys::_sys;
  iVar1 = *(int *)(param_2 + 8);
  if (*(int *)(param_2 + 8) == 0) {
    *(int *)(param_2 + 8) = msys::MComSys::_sys;
    iVar1 = iVar2;
  }
  msys::MLytNumRes::set((MLytNumRes *)(iVar1 + 0x844),aIStack_80,0,0,0xff);
  iVar2 = *(int *)(param_2 + 8);
  iVar1 = iVar2;
  if (iVar2 == 0) {
    iVar1 = msys::MComSys::_sys;
  }
  if (iVar2 == 0) {
    *(int *)(param_2 + 8) = iVar1;
  }
  msys::MLytNum::init((MLytNum *)(param_1 + 0x1d),aIStack_80,(LytDrawData *)(iVar1 + 0xd3000),this,
                      "COUNT",(char *)0x0,(char *)0x0,(char *)0x0);
  if ((char)param_1[0x21] == '\x02') {
    iVar1 = param_1[0x20];
  }
  else {
    iVar1 = 0;
  }
  iVar1 = *(int *)(iVar1 + 8);
  *(undefined4 *)(iVar1 + 0x24) = 0;
  *(float *)(iVar1 + 0x1c) = fVar7 - fVar8;
  *(float *)(iVar1 + 0x20) = fVar3 - fVar5;
  *(byte *)(iVar1 + 0x44) = *(byte *)(iVar1 + 0x44) & 0xef | 0x10;
  msys::MCellAnime::init((MCellAnime *)(param_1 + 0x1bba),(Resource *)(param_2 + 0x914));
  msys::MLyt::attachMChr
            (this,(MChrBase *)(param_1 + 0x1bba),"ICON_ITEM",(char *)0x0,(char *)0x0,(char *)0x0);
  if ((char)param_1[0x1bbe] == '\x02') {
    iVar1 = param_1[0x1bbd];
  }
  else {
    iVar1 = 0;
  }
  iVar1 = *(int *)(iVar1 + 8);
  *(undefined4 *)(iVar1 + 0x24) = 0;
  *(float *)(iVar1 + 0x1c) = fVar9;
  *(float *)(iVar1 + 0x20) = fVar10;
  *(byte *)(iVar1 + 0x44) = *(byte *)(iVar1 + 0x44) & 0xef | 0x10;
  *(byte *)((int)param_1 + 0x70d7) = *(byte *)((int)param_1 + 0x70d7) | 3;
  msys::MCellAnime::init((MCellAnime *)(param_1 + 0x1c59),(Resource *)(param_2 + 0x958));
  msys::MLyt::attachMChr
            (this,(MChrBase *)(param_1 + 0x1c59),"ICON_ITEM",(char *)0x0,(char *)0x0,(char *)0x0);
  if ((char)param_1[0x1c5d] == '\x02') {
    iVar1 = param_1[0x1c5c];
  }
  else {
    iVar1 = 0;
  }
  iVar1 = *(int *)(iVar1 + 8);
  *(undefined4 *)(iVar1 + 0x24) = 0;
  *(float *)(iVar1 + 0x1c) = fVar9;
  *(float *)(iVar1 + 0x20) = fVar10;
  *(byte *)(iVar1 + 0x44) = *(byte *)(iVar1 + 0x44) & 0xef | 0x10;
  *(byte *)((int)param_1 + 0x7353) = *(byte *)((int)param_1 + 0x7353) | 3;
  return;
}


// FUNC 0x15006a60 FUN_15006a60 (MainMenu)
//   size 0x278 | file MainMenu+0x6a60 | callers(0) | datarefs 1

void FUN_15006a60(int param_1)

{
  MemAlcBase *pMVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  
  FUN_150144d8();
  iVar4 = msys::MComSys::_sys;
  iVar2 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar2 = iVar4;
  }
  iVar4 = msys::MComSys::_sys;
  pMVar1 = (MemAlcBase *)(param_1 + 0x28);
  if (iVar2 == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  else {
    iVar4 = iVar2;
  }
  FUN_15012fe8(*(undefined4 *)(iVar4 + 4),param_1 + 0x914,*(int *)(iVar2 + 0x278) + 0xa8,
               "m_item_all",pMVar1,0x7f,0,0,0);
  iVar4 = msys::MComSys::_sys;
  iVar2 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar2 = iVar4;
  }
  iVar4 = msys::MComSys::_sys;
  if (iVar2 == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  else {
    iVar4 = iVar2;
  }
  FUN_15012fe8(*(undefined4 *)(iVar4 + 4),param_1 + 0x958,*(int *)(iVar2 + 0x278) + 0xa8,
               "m_daiji_icon",pMVar1,0x7f,0,0,0);
  iVar4 = msys::MComSys::_sys;
  iVar2 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar2 = iVar4;
  }
  iVar4 = msys::MComSys::_sys;
  if (iVar2 == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  else {
    iVar4 = iVar2;
  }
  FUN_15012fe8(*(undefined4 *)(iVar4 + 4),param_1 + 0x99c,*(int *)(iVar2 + 0x278) + 0xa8,
               "menu_mario",pMVar1,0x7f,0,0,0);
  iVar4 = msys::MComSys::_sys;
  iVar2 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar2 = iVar4;
  }
  iVar4 = msys::MComSys::_sys;
  if (iVar2 == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  else {
    iVar4 = iVar2;
  }
  FUN_15012fe8(*(undefined4 *)(iVar4 + 4),param_1 + 0x9e0,*(int *)(iVar2 + 0x278) + 0xa8,
               "menu_luigi",pMVar1,0x7f,0,0,0);
  iVar4 = msys::MComSys::_sys;
  iVar2 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar2 = iVar4;
  }
  iVar4 = msys::MComSys::_sys;
  if (iVar2 == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  else {
    iVar4 = iVar2;
  }
  FUN_15012fe8(*(undefined4 *)(iVar4 + 4),param_1 + 0xa24,*(int *)(iVar2 + 0x278) + 0xa8,
               "menu_koopa",pMVar1,0x7f,0,0,0);
  iVar4 = msys::MComSys::_sys;
  iVar2 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar2 = iVar4;
  }
  iVar4 = msys::MComSys::_sys;
  if (iVar2 == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  else {
    iVar4 = iVar2;
  }
  ad::fw::TaskBase::readLyt
            (*(TaskBase **)(iVar4 + 4),(Resource *)(param_1 + 0xcc),
             (FileContext *)(*(int *)(iVar2 + 0x278) + 0x150),"?MENU_ITEM_Lyt",pMVar1,0x7f,
             (ResCacheArg *)0x0);
  puVar3 = operator_new(0x20,*(MemAlcBase **)(*(int *)(param_1 + 4) + 0x18),"ParamMainItem",0);
  if (puVar3 != (undefined4 *)0x0) {
    *puVar3 = 0xc;
    puVar3[1] = 1;
    puVar3[2] = 0x3c;
    puVar3[3] = 0x3c;
    puVar3[4] = 0x19;
    puVar3[5] = 5;
    puVar3[6] = 5;
    puVar3[7] = 0x28;
  }
  *(undefined4 **)(param_1 + 0x868) = puVar3;
  *(undefined1 **)(param_1 + 0x10) = &LAB_15004ca8;
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}


// FUNC 0x15006d44 FUN_15006d44 (MainMenu)
//   size 0x820 | file MainMenu+0x6d44 | callers(0) | datarefs 4

void FUN_15006d44(int param_1,uint *param_2)

{
  char cVar1;
  ushort uVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  short sVar8;
  short sVar9;
  short sVar10;
  MListWndPBase *this;
  int iVar11;
  UIListWindowPlusLyt *this_00;
  int iVar12;
  undefined4 *puVar13;
  int iVar14;
  ushort *puVar15;
  MLyt *this_01;
  undefined4 uVar16;
  undefined4 uVar17;
  int *piVar18;
  uint uVar19;
  int iVar20;
  undefined1 uVar21;
  undefined1 uVar22;
  bool bVar23;
  uint in_fpscr;
  float fVar24;
  undefined8 uVar25;
  float fVar26;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 local_40;
  
  this = (MListWndPBase *)(param_1 + 0x1e778);
  iVar11 = msys::MListWndPBase::getSelectItem(this);
  if (iVar11 != 0) {
    iVar11 = msys::MListWndPBase::getSelectItem(this);
    bVar23 = *(char *)(iVar11 + 0xe) != '\0';
    cVar1 = '\0';
    if (bVar23) {
      cVar1 = *(char *)(param_1 + 0x870);
    }
    if (bVar23 && cVar1 != '\x02') {
      uVar21 = 0;
      FUN_1501580c(msys::MComSys::_sys + 0x49368,0x110016,0,0,0);
      iVar14 = msys::MComSys::_sys;
      iVar11 = *(int *)(param_1 + 8);
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar11 = iVar14;
      }
      *(undefined1 *)(iVar11 + 0xe6508) = 0;
      msys::MListWndPBase::setEnableInput(this,false);
      uVar19 = 0;
      do {
        piVar18 = *(int **)(param_1 + uVar19 * 4 + 0x1e750);
        (**(code **)(*piVar18 + 0x28))(piVar18,0);
        uVar19 = uVar19 + 1 & 0xff;
      } while (uVar19 < 3);
      this_00 = (UIListWindowPlusLyt *)msys::MListWndPBase::getListWnd(this);
      uVar25 = ad::ui::UIListWindowPlusLyt::getCurPos(this_00);
      MoveVBase::stop((MoveVBase *)(param_1 + 0xa34c));
      *(undefined8 *)(param_1 + 0xa368) = uVar25;
      *(undefined4 *)(param_1 + 0xa370) = 0;
      *(undefined8 *)(param_1 + 0xa350) = uVar25;
      *(undefined4 *)(param_1 + 0xa358) = 0;
      iVar14 = msys::MComSys::_sys;
      iVar12 = *(int *)(param_1 + 0xa334);
      iVar20 = *(int *)(param_1 + 0xa338);
      iVar11 = *(int *)(iVar12 + 8);
      if (iVar11 == 0) {
        *(int *)(iVar12 + 8) = msys::MComSys::_sys;
        iVar11 = iVar14;
      }
      iVar11 = ad::fw::TaskBase::isFps30(*(TaskBase **)(iVar11 + 4));
      fVar24 = 2.0;
      if (iVar11 == 0) {
        fVar24 = 1.0;
      }
      puVar13 = (undefined4 *)MoveVBase::update((MoveVBase *)(param_1 + 0xa34c),fVar24);
      uVar16 = puVar13[1];
      uVar17 = puVar13[2];
      *(undefined4 *)(iVar20 + 0x1c) = *puVar13;
      *(undefined4 *)(iVar20 + 0x20) = uVar16;
      *(undefined4 *)(iVar20 + 0x24) = uVar17;
      *(byte *)(iVar20 + 0x44) = *(byte *)(iVar20 + 0x44) & 0xef | 0x10;
      *(undefined1 *)(*(int *)(param_1 + 0xa334) + 0x82c) = 1;
      fVar24 = (float)VectorSignedToFloat((*(undefined4 **)(param_1 + 0x868))[1],
                                          (byte)(in_fpscr >> 0x16) & 3);
      fVar26 = (float)VectorSignedToFloat(**(undefined4 **)(param_1 + 0x868),
                                          (byte)(in_fpscr >> 0x16) & 3);
      Frm::play((Frm *)(param_1 + 0xa33c),fVar24);
      local_48 = 0;
      uStack_44 = 0x42d00000;
      local_40 = 0;
      MoveVBase::moveAbs((MoveVBase *)(param_1 + 0xa34c),(VEC3 *)&local_48,fVar26);
      iVar14 = msys::MListWndPBase::getSelectItem(this);
      iVar11 = param_1 + 0x1121c;
      if (*(byte *)(param_1 + 0x870) < 2) {
        *(undefined1 *)(param_1 + 0x1135d) = 1;
        *(undefined1 *)(param_1 + 0x115d9) = 0;
      }
      else {
        *(undefined1 *)(param_1 + 0x1135d) = 0;
        *(undefined1 *)(param_1 + 0x115d9) = 1;
        iVar11 = param_1 + 0x11498;
      }
      CellAnime::play((CellAnime *)(iVar11 + 0x14c),*(uchar *)(iVar14 + 0xb),0,1.0);
      ad::lyt::LytNumReel3::setValueInstant
                ((LytNumReel3 *)(param_1 + 0xa4f8),(uint)*(ushort *)(iVar14 + 4));
      msys::MMsg::playStr((MMsg *)(param_1 + 0xa5d8),*(wchar_t **)(iVar14 + 0x10),(InsParam *)0x0,
                          false);
      iVar11 = msys::MListWndPBase::getListWnd(this);
      *(undefined1 *)(iVar11 + 0x6d79) = 0;
      puVar15 = (ushort *)msys::MListWndPBase::getSelectItem(this);
      iVar11 = ad::db::GetUseItem(*puVar15);
      this_01 = (MLyt *)(param_1 + 0x4b8);
      uVar2 = *(ushort *)(iVar11 + 0x6a);
      uVar22 = 2;
      if (uVar2 >> 9 == 1) {
        msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x110),2,1,(char *)0x0,(char *)0x0);
        msys::MLyt::playAnimeFromNo(this_01,2,1,(char *)0x0,(char *)0x0);
        msys::StatusPanel::setType((StatusPanel *)(param_1 + 0x177cc),1);
        msys::StatusPanel::setType((StatusPanel *)(param_1 + 0x19800),1);
        iVar14 = msys::MComSys::_sys;
        if ((*(ushort *)(iVar11 + 0x6a) & 0x100) != 0) goto LAB_150073f0;
        switch(*(ushort *)(iVar11 + 0x6a) & 0x1f) {
        default:
          goto switchD_15007040_caseD_0;
        case 1:
          iVar11 = *(int *)(param_1 + 8);
          if (*(int *)(param_1 + 8) == 0) {
            *(int *)(param_1 + 8) = msys::MComSys::_sys;
            iVar11 = iVar14;
          }
          sVar3 = DataPc::getHpMax((DataPc *)(iVar11 + 0xeac64));
          iVar14 = msys::MComSys::_sys;
          iVar11 = *(int *)(param_1 + 8);
          if (*(int *)(param_1 + 8) == 0) {
            *(int *)(param_1 + 8) = msys::MComSys::_sys;
            iVar11 = iVar14;
          }
          sVar4 = DataPc::getHpNow((DataPc *)(iVar11 + 0xeac64));
          iVar14 = msys::MComSys::_sys;
          iVar11 = *(int *)(param_1 + 8);
          if (*(int *)(param_1 + 8) == 0) {
            *(int *)(param_1 + 8) = msys::MComSys::_sys;
            iVar11 = iVar14;
          }
          sVar5 = DataPc::getHpMax((DataPc *)(iVar11 + 0xead14));
          iVar14 = msys::MComSys::_sys;
          iVar11 = *(int *)(param_1 + 8);
          if (*(int *)(param_1 + 8) == 0) {
            *(int *)(param_1 + 8) = msys::MComSys::_sys;
            iVar11 = iVar14;
          }
          sVar6 = DataPc::getHpNow((DataPc *)(iVar11 + 0xead14));
          if ((ushort)(sVar3 - sVar4) < (ushort)(sVar5 - sVar6)) {
LAB_15007124:
            *(undefined1 *)(param_1 + 0x871) = uVar21;
            goto switchD_15007040_caseD_0;
          }
          break;
        case 2:
          iVar11 = *(int *)(param_1 + 8);
          if (*(int *)(param_1 + 8) == 0) {
            *(int *)(param_1 + 8) = msys::MComSys::_sys;
            iVar11 = iVar14;
          }
          sVar3 = DataPc::getBpMax((DataPc *)(iVar11 + 0xeac64));
          iVar14 = msys::MComSys::_sys;
          iVar11 = *(int *)(param_1 + 8);
          if (*(int *)(param_1 + 8) == 0) {
            *(int *)(param_1 + 8) = msys::MComSys::_sys;
            iVar11 = iVar14;
          }
          sVar4 = DataPc::getBpNow((DataPc *)(iVar11 + 0xeac64));
          iVar14 = msys::MComSys::_sys;
          iVar11 = *(int *)(param_1 + 8);
          if (*(int *)(param_1 + 8) == 0) {
            *(int *)(param_1 + 8) = msys::MComSys::_sys;
            iVar11 = iVar14;
          }
          sVar5 = DataPc::getBpMax((DataPc *)(iVar11 + 0xead14));
          iVar14 = msys::MComSys::_sys;
          iVar11 = *(int *)(param_1 + 8);
          if (*(int *)(param_1 + 8) == 0) {
            *(int *)(param_1 + 8) = msys::MComSys::_sys;
            iVar11 = iVar14;
          }
          sVar6 = DataPc::getBpNow((DataPc *)(iVar11 + 0xead14));
          if ((ushort)(sVar3 - sVar4) < (ushort)(sVar5 - sVar6)) goto LAB_15007124;
          break;
        case 5:
          iVar11 = *(int *)(param_1 + 8);
          if (*(int *)(param_1 + 8) == 0) {
            *(int *)(param_1 + 8) = msys::MComSys::_sys;
            iVar11 = iVar14;
          }
          sVar3 = DataPc::getHpMax((DataPc *)(iVar11 + 0xeac64));
          iVar14 = msys::MComSys::_sys;
          iVar11 = *(int *)(param_1 + 8);
          if (*(int *)(param_1 + 8) == 0) {
            *(int *)(param_1 + 8) = msys::MComSys::_sys;
            iVar11 = iVar14;
          }
          sVar4 = DataPc::getHpNow((DataPc *)(iVar11 + 0xeac64));
          iVar14 = msys::MComSys::_sys;
          iVar11 = *(int *)(param_1 + 8);
          if (*(int *)(param_1 + 8) == 0) {
            *(int *)(param_1 + 8) = msys::MComSys::_sys;
            iVar11 = iVar14;
          }
          sVar5 = DataPc::getHpMax((DataPc *)(iVar11 + 0xead14));
          iVar14 = msys::MComSys::_sys;
          iVar11 = *(int *)(param_1 + 8);
          if (*(int *)(param_1 + 8) == 0) {
            *(int *)(param_1 + 8) = msys::MComSys::_sys;
            iVar11 = iVar14;
          }
          sVar6 = DataPc::getHpNow((DataPc *)(iVar11 + 0xead14));
          iVar14 = msys::MComSys::_sys;
          iVar11 = *(int *)(param_1 + 8);
          if (*(int *)(param_1 + 8) == 0) {
            *(int *)(param_1 + 8) = msys::MComSys::_sys;
            iVar11 = iVar14;
          }
          sVar7 = DataPc::getBpMax((DataPc *)(iVar11 + 0xeac64));
          iVar14 = msys::MComSys::_sys;
          iVar11 = *(int *)(param_1 + 8);
          if (*(int *)(param_1 + 8) == 0) {
            *(int *)(param_1 + 8) = msys::MComSys::_sys;
            iVar11 = iVar14;
          }
          sVar8 = DataPc::getBpNow((DataPc *)(iVar11 + 0xeac64));
          iVar14 = msys::MComSys::_sys;
          iVar11 = *(int *)(param_1 + 8);
          if (*(int *)(param_1 + 8) == 0) {
            *(int *)(param_1 + 8) = msys::MComSys::_sys;
            iVar11 = iVar14;
          }
          sVar9 = DataPc::getBpMax((DataPc *)(iVar11 + 0xead14));
          iVar14 = msys::MComSys::_sys;
          iVar11 = *(int *)(param_1 + 8);
          if (*(int *)(param_1 + 8) == 0) {
            *(int *)(param_1 + 8) = msys::MComSys::_sys;
            iVar11 = iVar14;
          }
          sVar10 = DataPc::getBpNow((DataPc *)(iVar11 + 0xead14));
          if ((ushort)((sVar7 - sVar8) + (sVar3 - sVar4)) <
              (ushort)((sVar9 - sVar10) + (sVar5 - sVar6))) goto LAB_15007124;
          break;
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 0xb:
        case 0xc:
          iVar11 = FUN_15013eb8(param_1,iVar11,0);
          if (iVar11 == 0) goto LAB_15007124;
        }
        *(undefined1 *)(param_1 + 0x871) = 1;
      }
      else if ((uVar2 & 0xfe00) == 0) {
        msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x110),4,1,(char *)0x0,(char *)0x0);
        msys::MLyt::playAnimeFromNo(this_01,4,1,(char *)0x0,(char *)0x0);
        msys::StatusPanel::setType((StatusPanel *)(param_1 + 0x177cc),2);
        msys::StatusPanel::setType((StatusPanel *)(param_1 + 0x19800),2);
        msys::StatusPanel::setType((StatusPanel *)(param_1 + 0x1b834),2);
        uVar22 = 5;
        uVar21 = 6;
        if ((char)DAT_003fbea4 == '\x02') {
          iVar14 = FUN_15013eb8(param_1,iVar11,2);
          if (iVar14 != 0) goto LAB_15007124;
          iVar11 = FUN_15013eb8(param_1,iVar11,0);
          if (iVar11 == 0) goto LAB_15007414;
        }
        else {
          iVar14 = FUN_15013eb8(param_1,iVar11,0);
          if (iVar14 == 0) {
            iVar11 = FUN_15013eb8(param_1,iVar11,1);
            if (iVar11 == 0) goto LAB_15007124;
LAB_15007414:
            *(undefined1 *)(param_1 + 0x871) = 4;
            goto switchD_15007040_caseD_0;
          }
        }
LAB_150073f0:
        *(undefined1 *)(param_1 + 0x871) = uVar22;
      }
      else if (uVar2 >> 9 == 2) {
        msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x110),3,1,(char *)0x0,(char *)0x0);
        msys::MLyt::playAnimeFromNo(this_01,3,1,(char *)0x0,(char *)0x0);
        msys::StatusPanel::setType((StatusPanel *)(param_1 + 0x1b834),1);
        *(undefined1 *)(param_1 + 0x871) = 3;
      }
switchD_15007040_caseD_0:
      *(code **)(param_1 + 0x20) = FUN_150062cc;
      *(undefined4 *)(param_1 + 0x24) = 0;
      goto LAB_15007540;
    }
  }
  iVar11 = msys::MListWndPBase::isBusyAnime(this);
  if ((iVar11 == 0) &&
     (iVar14 = msys::MListWndPBase::getListWnd(this), iVar11 = msys::MComSys::_sys,
     *(int *)(iVar14 + 0x1cc) == 0)) {
    iVar14 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar14 = iVar11;
    }
    ad::fw::TaskBase::isFps30(*(TaskBase **)(iVar14 + 4));
    uVar19 = *param_2;
    if ((uVar19 & 0x802) == 0) {
      if ((uVar19 & 0x330) == 0) goto LAB_15007540;
      cVar1 = *(char *)(param_1 + 0x870);
      iVar11 = (int)cVar1;
      if ((uVar19 & 0x220) == 0) {
        if (((uVar19 & 0x110) != 0) && (iVar11 = (int)(char)(cVar1 + '\x01'), 2 < iVar11)) {
          iVar11 = 0;
        }
      }
      else {
        iVar11 = (int)(char)(cVar1 + -1);
        if (iVar11 < 0) {
          iVar11 = 2;
        }
      }
      (**(code **)(**(int **)(param_1 + iVar11 * 4 + 0x1e750) + 0x10))();
      iVar11 = *(int *)(param_1 + 8);
    }
    else {
      (**(code **)(**(int **)(param_1 + 0x860) + 0x10))();
      iVar11 = *(int *)(param_1 + 8);
    }
    iVar14 = msys::MComSys::_sys;
    if (iVar11 == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar11 = iVar14;
    }
    *(undefined1 *)(iVar11 + 0xe6508) = 0;
  }
LAB_15007540:
  iVar11 = msys::MListWndPBase::getListWnd(this);
  if (((*(char *)(iVar11 + 0x144) == '\0') ||
      (iVar11 = msys::MListWndPBase::getListWnd(this), *(int *)(iVar11 + 0x1cc) != 0)) ||
     (iVar11 = msys::MListWndPBase::getListWnd(this),
     (int)*(char *)(param_1 + 0x872) == (uint)*(byte *)(iVar11 + 0x149))) {
    return;
  }
  iVar11 = msys::MListWndPBase::getListWnd(this);
  *(undefined1 *)(param_1 + 0x872) = *(undefined1 *)(iVar11 + 0x149);
  FUN_150138ec(param_1);
  return;
}


// FUNC 0x150075c4 FUN_150075c4 (MainMenu)
//   size 0xcc | file MainMenu+0x75c4 | callers(0) | datarefs 1

void FUN_150075c4(int param_1)

{
  int iVar1;
  
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x110),1,0,(char *)0x0,(char *)0x0);
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x4b8),1,0,(char *)0x0,(char *)0x0);
  iVar1 = msys::MListWndPBase::getListWnd((MListWndPBase *)(param_1 + 0x1e778));
  if (*(char *)(iVar1 + 0x144) != '\0') {
    FUN_15013ad0(param_1,*(uint *)(param_1 + 0x256f8) & 0xffff);
    msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x110),5,1,"EXP_PNL_U",(char *)0x0);
  }
  *(undefined1 *)(param_1 + 0x870) = 0;
  (**(code **)(**(int **)(param_1 + 0x1e750) + 0x20))();
  FUN_15013bb0((MListWndPBase *)(param_1 + 0x1e778),(int)*(char *)(param_1 + 0x870));
  FUN_150138ec(param_1);
  *(code **)(param_1 + 0x20) = FUN_1500549c;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


// FUNC 0x150076c0 FUN_150076c0 (MainMenu)
//   size 0x25c | file MainMenu+0x76c0 | callers(1) 0x15007bc0

int FUN_150076c0(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)FUN_15014438();
  *puVar1 = &main_menu::MainMenu_ItemPage::Core::vtable;
  *(undefined1 *)(puVar1 + 0x21c) = 0;
  *(undefined1 *)((int)puVar1 + 0x871) = 1;
  *(undefined1 *)((int)puVar1 + 0x872) = 0xff;
  *(undefined1 *)((int)puVar1 + 0x873) = 0xff;
  puVar1 = (undefined4 *)msys::MCursorBase::MCursorBase((MCursorBase *)(puVar1 + 0x21d));
  *puVar1 = &vtable_for_N4msys7MCursorILj7EEE;
  puVar1[0xc] = 0;
  puVar1[0xd] = 0;
  puVar1[0xe] = 0;
  puVar1[0xf] = 0;
  puVar1[0x10] = 0;
  puVar1[0x11] = 0;
  puVar1[0x12] = 0;
  puVar1[0x13] = 0;
  puVar1[0x14] = 0x3f800000;
  puVar1[0x15] = 0;
  *(undefined2 *)(puVar1 + 0x16) = 1;
  *(undefined2 *)((int)puVar1 + 0x5a) = 0;
  iVar2 = ad::fw::Resource::Resource((Resource *)(puVar1 + 0x17));
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(iVar2 + 0x44,ad::fw::Resource::Resource,0x44,5);
  iVar2 = FUN_15012fa0(iVar2 + 0x154);
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(iVar2 + 0x6c44,msys::MDfxChr::MDfxChr,0x17c,0x1e);
  *(undefined4 *)(iVar2 + 0x2c88) = 0;
  *(undefined4 *)(iVar2 + 0x2c8c) = 0;
  *(undefined4 *)(iVar2 + 0x2c90) = 0;
  *(undefined4 *)(iVar2 + 0x2c94) = 0x3f800000;
  *(undefined4 *)(iVar2 + 0x2c98) = 0;
  *(undefined2 *)(iVar2 + 0x2c9c) = 1;
  *(undefined2 *)(iVar2 + 0x2c9e) = 0;
  puVar1 = (undefined4 *)MoveVBase::MoveVBase((MoveVBase *)(iVar2 + 0x2ca0));
  *puVar1 = &vtable_for_5MoveVILj1EE;
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(puVar1 + 0xc,FUN_150012f0,0x2c,1);
  *(int *)(iVar2 + -8) = iVar2;
  *(undefined1 *)(iVar2 + -4) = 1;
  iVar2 = msys::MLytNum::MLytNum((MLytNum *)(iVar2 + 0x2c));
  iVar2 = FUN_15012fa0(iVar2 + 0x230);
  iVar2 = FUN_15012f6c(iVar2 + 0x6c44);
  iVar2 = FUN_15012f6c(iVar2 + 0x27c);
  iVar2 = FUN_15012f30(iVar2 + 0x27c);
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(iVar2 + 0x1c,msys::StatusPanel::StatusPanel,0x2034,3);
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(iVar2 + 0x609c,msys::StatusPanel::StatusPanel,0x2034,3);
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(iVar2 + 0x609c,FUN_15012f6c,0x27c,3);
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(iVar2 + 0x774,FUN_15012f6c,0x27c,3);
  puVar1 = (undefined4 *)
           msys::MListWndPBase::MListWndPBase
                     ((MListWndPBase *)(iVar2 + 0x79c),(MListWndPCore *)(iVar2 + 0x998));
  *puVar1 = &vtable_for_N4msys9MListWndPILi56EEE;
  puVar1 = (undefined4 *)
           ad::ui::UIListWindowPlusLyt::UIListWindowPlusLyt((UIListWindowPlusLyt *)(puVar1 + 0x7f));
  *puVar1 = &msys::MListWndPCore::vtable;
  puVar1[-0x7f] = &main_menu::MainMenu_ItemPage::Core::MListWndItem::vtable;
  iVar2 = ad::lyt::Layout::Layout((Layout *)(puVar1 + 0x1cea));
  iVar2 = FUN_15012f30(iVar2 + 0x3c);
  iVar2 = FUN_15012f30(iVar2 + 0x1c);
  iVar2 = ad::lyt::Layout::Layout((Layout *)(iVar2 + 0x1c));
  iVar2 = FUN_15012f30(iVar2 + 0x3c);
  iVar2 = FUN_15012f30(iVar2 + 0x1c);
  iVar2 = FUN_15012f30(iVar2 + 0x1c);
  iVar2 = FUN_15012f30(iVar2 + 0x1c);
  iVar2 = CellAnime::CellAnime((CellAnime *)(iVar2 + 0x1c));
  iVar2 = CellAnime::CellAnime((CellAnime *)(iVar2 + 300));
  Mem::Fill((void *)(iVar2 + -0x780c),0,0x1c);
  *(code **)(iVar2 + -0x25f58) = FUN_15006a60;
  *(undefined4 *)(iVar2 + -0x25f54) = 0;
  *(undefined1 **)(iVar2 + -0x25f50) = &LAB_150076a8;
  *(undefined4 *)(iVar2 + -0x25f4c) = 0;
  *(code **)(iVar2 + -0x25f48) = FUN_150075c4;
  *(undefined4 *)(iVar2 + -0x25f44) = 0;
  return iVar2 + -0x25f68;
}


// FUNC 0x15007958 main_menu::MainMenu_ItemPage::Core::vfunc_0x4 (MainMenu)
//   size 0x10 | file MainMenu+0x7958 | callers(0) | datarefs 1

void main_menu::MainMenu_ItemPage::Core::vfunc_0x4(void)

{
  void *pvVar1;
  
  pvVar1 = (void *)vfunc_0x0();
  operator_delete(pvVar1);
  return;
}


// FUNC 0x15007968 main_menu::MainMenu_ItemPage::Core::vfunc_0x0 (MainMenu)
//   size 0x224 | file MainMenu+0x7968 | callers(1) 0x15007958 | datarefs 1

void main_menu::MainMenu_ItemPage::Core::vfunc_0x0(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &vtable;
  msys::MCursorBase::term((MCursorBase *)(param_1 + 0x21d));
  operator_delete((void *)param_1[0x21a]);
  param_1[0x21a] = 0;
  param_1[0x79de] = &MListWndItem::vtable;
  iVar1 = CellAnime::~CellAnime((CellAnime *)(param_1 + 0x97da));
  iVar1 = CellAnime::~CellAnime((CellAnime *)(iVar1 + -300));
  *(undefined4 *)(iVar1 + -0x10) = 0;
  *(undefined4 *)(iVar1 + -0x2c) = 0;
  *(undefined4 *)(iVar1 + -0x48) = 0;
  *(undefined4 *)(iVar1 + -100) = 0;
  iVar1 = ad::lyt::Layout::~Layout((Layout *)(iVar1 + -0xac));
  *(undefined4 *)(iVar1 + -0x10) = 0;
  *(undefined4 *)(iVar1 + -0x2c) = 0;
  iVar1 = ad::lyt::Layout::~Layout((Layout *)(iVar1 + -0x74));
  *(undefined ***)(iVar1 + -0x75a4) = &vtable_for_N4msys9MListWndPILi56EEE;
  iVar1 = ad::ui::UIListWindowPlusLyt::~UIListWindowPlusLyt
                    ((UIListWindowPlusLyt *)(iVar1 + -0x73a8));
  iVar1 = msys::MListWndPBase::~MListWndPBase((MListWndPBase *)(iVar1 + -0x1fc));
  __aeabi_vec_dtor(iVar1 + -0x79c,&LAB_15000e9c,0x27c,3);
  __aeabi_vec_dtor(iVar1 + -0xf10,&LAB_15000e9c,0x27c,3);
  __aeabi_vec_dtor(iVar1 + -0x6fac,msys::StatusPanel::~StatusPanel,0x2034,3);
  __aeabi_vec_dtor(iVar1 + -0xd048,msys::StatusPanel::~StatusPanel,0x2034,3);
  *(undefined4 *)(iVar1 + -0xd058) = 0;
  *(undefined ***)(iVar1 + -0xd2e0) = &msys::MCellAnime::vtable;
  iVar1 = CellAnime::~CellAnime((CellAnime *)(iVar1 + -0xd194));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  *(undefined ***)(iVar1 + -0x27c) = &msys::MCellAnime::vtable;
  iVar1 = CellAnime::~CellAnime((CellAnime *)(iVar1 + -0x130));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  *(undefined ***)(iVar1 + -0x6c44) = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar1 = MessageSimple::~MessageSimple((MessageSimple *)(iVar1 + -0x6af8));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  iVar1 = msys::MLytNum::~MLytNum((MLytNum *)(iVar1 + -0x230));
  *(undefined ***)(iVar1 + -0x5c) = &vtable_for_5MoveVILj1EE;
  __aeabi_vec_dtor(iVar1 + -0x2c,MoveWorkF::~MoveWorkF,0x2c,1);
  iVar1 = MoveVBase::~MoveVBase((MoveVBase *)(iVar1 + -0x5c));
  *(undefined4 *)(iVar1 + -8) = 0;
  __aeabi_vec_dtor(iVar1 + -0x2ca0,msys::MDfxChr::~MDfxChr,0x17c,0x1e);
  *(undefined ***)(iVar1 + -0x98e4) = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar1 = MessageSimple::~MessageSimple((MessageSimple *)(iVar1 + -0x9798));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  __aeabi_vec_dtor(iVar1 + -0x154,ad::fw::Resource::~Resource,0x44,5);
  iVar1 = ad::fw::Resource::~Resource((Resource *)(iVar1 + -0x198));
  *(undefined4 *)(iVar1 + -8) = 0;
  iVar1 = msys::MCursorBase::~MCursorBase((MCursorBase *)(iVar1 + -0x5c));
  MainMenuPageBase::Core::vfunc_0x0(iVar1 + -0x874);
  return;
}


// FUNC 0x15007bc0 main_menu::MainMenu_ItemPage::vfunc_0x30 (MainMenu)
//   size 0x30 | file MainMenu+0x7bc0 | callers(0) | datarefs 1

void main_menu::MainMenu_ItemPage::vfunc_0x30(int param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(0x260a4,*(MemAlcBase **)(param_1 + 0x18),(char *)0x0,0x1f);
  uVar2 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_150076c0(pvVar1,param_1);
  }
  *(undefined4 *)(param_1 + 0x20) = uVar2;
  return;
}


// FUNC 0x15007bf4 main_menu::MainMenu_ItemPage::vfunc_0x24 (MainMenu)
//   size 0x8 | file MainMenu+0x7bf4 | callers(0) | datarefs 1

undefined4 main_menu::MainMenu_ItemPage::vfunc_0x24(void)

{
  return 1;
}


// FUNC 0x15007bfc main_menu::MainMenu_ItemPage::vfunc_0x4 (MainMenu)
//   size 0x10 | file MainMenu+0x7bfc | callers(0) | datarefs 1

void main_menu::MainMenu_ItemPage::vfunc_0x4(void)

{
  void *pvVar1;
  
  pvVar1 = (void *)MainMenuPageBase::vfunc_0x0();
  operator_delete(pvVar1);
  return;
}


// FUNC 0x15007c0c ->main_menu::MainMenuPageBase::vfunc_0x0 (MainMenu)
//   size 0x4 | file MainMenu+0x7c0c | callers(0) | datarefs 1
// veneer/thunk -> 0x15015174 main_menu::MainMenuPageBase::vfunc_0x0 (MainMenu)

// FUNC 0x15007c10 FUN_15007c10 (MainMenu)
//   size 0x2b0 | file MainMenu+0x7c10 | callers(1) 0x15007f18

void FUN_15007c10(int param_1)

{
  void *pvVar1;
  MLyt *pMVar2;
  ChangeBadgeUlcd *pCVar3;
  undefined4 uVar4;
  MCtrUserDataListAcs *pMVar5;
  ChangeBadgeLlcd *pCVar6;
  MemAlcBase *pMVar7;
  int iVar8;
  LytLocalize aLStack_78 [32];
  undefined4 local_58;
  ButtonGroup *pBStack_54;
  int local_50;
  undefined4 local_4c;
  undefined4 local_48;
  
  if (*(int *)(param_1 + 8) == 0) {
    *(undefined4 *)(param_1 + 8) = msys::MComSys::_sys;
  }
  iVar8 = *(int *)(param_1 + 8);
  ad::lyt::LytResourceMan::init((LytResourceMan *)(param_1 + 0x58));
  pvVar1 = (void *)ad::fw::Resource::getFileData((Resource *)(param_1 + 0xcc));
  ad::lyt::LytResourceMan::registerArc((LytResourceMan *)(param_1 + 0x58),pvVar1,".");
  pMVar7 = *(MemAlcBase **)(*(int *)(param_1 + 4) + 0x18);
  if (*(int *)(param_1 + 8) == 0) {
    *(undefined4 *)(param_1 + 8) = msys::MComSys::_sys;
  }
  iVar8 = iVar8 + 0xd3000;
  pMVar2 = (MLyt *)(param_1 + 0x8e8);
  msys::MLyt::init(pMVar2,iVar8,0);
  *(undefined1 *)(param_1 + 0xa29) = 1;
  MoveVBase::stop((MoveVBase *)(param_1 + 0x9b4));
  *(undefined4 *)(param_1 + 0x9d0) = 0;
  *(undefined4 *)(param_1 + 0x9d4) = 0;
  *(undefined4 *)(param_1 + 0x9d8) = 0xc347e666;
  *(undefined4 *)(param_1 + 0x9b8) = *(undefined4 *)(param_1 + 0x9d0);
  *(undefined4 *)(param_1 + 0x9bc) = 0;
  *(undefined4 *)(param_1 + 0x9c0) = 0xc347e666;
  *(int *)(param_1 + 0xc90) = param_1;
  msys::MLyt::createLyt(pMVar2,(LytResourceMan *)(param_1 + 0x58),"MENU_BADGE_U.bflyt");
  *(undefined4 *)(param_1 + 0xc98) = *(undefined4 *)(param_1 + 0xc90);
  *(MLyt **)(param_1 + 0xc9c) = pMVar2;
  badge::ChangeBadgeUlcd::InitParam::InitParam((InitParam *)&local_58);
  local_58 = *(undefined4 *)(param_1 + 0xa38);
  pBStack_54 = (ButtonGroup *)(param_1 + 0xc94);
  local_50 = 0x43470000;
  pCVar3 = operator_new(0xd5dc,pMVar7,"ChangeBadgeLlcd",0);
  uVar4 = 0;
  if (pCVar3 != (ChangeBadgeUlcd *)0x0) {
    uVar4 = badge::ChangeBadgeUlcd::ChangeBadgeUlcd(pCVar3,(InitParam *)&local_58);
  }
  pCVar3 = *(ChangeBadgeUlcd **)(param_1 + 0xca0);
  *(undefined4 *)(param_1 + 0xca0) = uVar4;
  if (pCVar3 != (ChangeBadgeUlcd *)0x0) {
    pvVar1 = (void *)badge::ChangeBadgeUlcd::~ChangeBadgeUlcd(pCVar3);
    operator_delete(pvVar1);
  }
  pMVar7 = *(MemAlcBase **)(*(int *)(param_1 + 4) + 0x18);
  pMVar5 = (MCtrUserDataListAcs *)(param_1 + 0x1060);
  if (*(int *)(param_1 + 8) == 0) {
    *(undefined4 *)(param_1 + 8) = msys::MComSys::_sys;
  }
  pMVar2 = (MLyt *)(param_1 + 0xca4);
  msys::MLyt::init(pMVar2,iVar8,0);
  *(undefined1 *)(param_1 + 0xde5) = 0;
  MoveVBase::stop((MoveVBase *)(param_1 + 0xd70));
  *(undefined4 *)(param_1 + 0xd8c) = 0;
  *(undefined4 *)(param_1 + 0xd90) = 0;
  *(undefined4 *)(param_1 + 0xd94) = 0xc347e666;
  *(undefined4 *)(param_1 + 0xd74) = *(undefined4 *)(param_1 + 0xd8c);
  *(undefined4 *)(param_1 + 0xd78) = 0;
  *(undefined4 *)(param_1 + 0xd7c) = 0xc347e666;
  *(int *)(param_1 + 0x104c) = param_1;
  msys::MLyt::createLyt
            (pMVar2,(LytResourceMan *)(param_1 + 0x58),"MENU_BADGE_L.bflyt",
             (ButtonGroup *)(param_1 + 0x8cc),pMVar5);
  *(undefined4 *)(param_1 + 0x1054) = *(undefined4 *)(param_1 + 0x104c);
  *(MLyt **)(param_1 + 0x1058) = pMVar2;
  badge::ChangeBadgeLlcd::InitParam::InitParam((InitParam *)&local_58);
  local_58 = *(undefined4 *)(param_1 + 0xdf4);
  local_50 = param_1 + 0x1050;
  local_4c = 0x43470000;
  local_48 = *(undefined4 *)(param_1 + 0xca0);
  pBStack_54 = (ButtonGroup *)(param_1 + 0x8cc);
  pCVar6 = operator_new(0x14170,pMVar7,"ChangeBadgeLlcd",0);
  uVar4 = 0;
  if (pCVar6 != (ChangeBadgeLlcd *)0x0) {
    uVar4 = badge::ChangeBadgeLlcd::ChangeBadgeLlcd(pCVar6,(InitParam *)&local_58);
  }
  pCVar6 = *(ChangeBadgeLlcd **)(param_1 + 0x105c);
  *(undefined4 *)(param_1 + 0x105c) = uVar4;
  if (pCVar6 != (ChangeBadgeLlcd *)0x0) {
    pvVar1 = (void *)badge::ChangeBadgeLlcd::~ChangeBadgeLlcd(pCVar6);
    operator_delete(pvVar1);
  }
  ad::lyt::LytLocalize::LytLocalize(aLStack_78);
  ad::lyt::LytLocalize::localize(aLStack_78,*(Layout **)(param_1 + 0xa38));
  ad::lyt::LytLocalize::localize(aLStack_78,*(Layout **)(param_1 + 0xdf4));
  *(undefined1 **)(param_1 + 0x10) = &LAB_150081c8;
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}


// FUNC 0x15007f20 FUN_15007f20 (MainMenu)
//   size 0x2c | file MainMenu+0x7f20 | callers(0) | datarefs 1

void FUN_15007f20(int param_1)

{
  badge::ChangeBadgeUlcd::appear(*(ChangeBadgeUlcd **)(param_1 + 0xca0));
  badge::ChangeBadgeLlcd::appear(*(ChangeBadgeLlcd **)(param_1 + 0x105c));
  *(code **)(param_1 + 0x20) = FUN_15008af0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


// FUNC 0x15007f54 main_menu::MainMenu_BadgePage::Core::MBadgeLytCtrl::vfunc_0x3c (MainMenu)
//   size 0x2c | file MainMenu+0x7f54 | callers(0) | datarefs 1

void main_menu::MainMenu_BadgePage::Core::MBadgeLytCtrl::vfunc_0x3c(void)

{
  FUN_1501580c(msys::MComSys::_sys + 0x49368,0x110017,0,0,0);
  return;
}


// FUNC 0x15007f88 main_menu::MainMenu_BadgePage::Core::MBadgeLytCtrl::vfunc_0x44 (MainMenu)
//   size 0x40 | file MainMenu+0x7f88 | callers(0) | datarefs 1

void main_menu::MainMenu_BadgePage::Core::MBadgeLytCtrl::vfunc_0x44(undefined4 param_1)

{
  undefined4 local_10;
  undefined4 local_c;
  
  local_c = 0;
  local_10 = param_1;
  FUN_1501580c(msys::MComSys::_sys + 0x49368,0x110015,0,&local_10,0);
  return;
}


// FUNC 0x15007fd4 main_menu::MainMenu_BadgePage::Core::MBadgeLytCtrl::vfunc_0x10 (MainMenu)
//   size 0x18 | file MainMenu+0x7fd4 | callers(0) | datarefs 1

void main_menu::MainMenu_BadgePage::Core::MBadgeLytCtrl::vfunc_0x10
               (int *param_1,undefined4 param_2,undefined4 param_3)

{
                    /* WARNING: Could not recover jumptable at 0x15007fe8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x14))(param_1,param_2,*(undefined4 *)(param_1[2] + 0x150),param_3);
  return;
}


// FUNC 0x15007fec main_menu::MainMenu_BadgePage::Core::MBadgeLytCtrl::vfunc_0x14 (MainMenu)
//   size 0x50 | file MainMenu+0x7fec | callers(0) | datarefs 1

void main_menu::MainMenu_BadgePage::Core::MBadgeLytCtrl::vfunc_0x14
               (float param_1,int param_2,short param_3,Layout *param_4,char *param_5)

{
  LytAnim *this;
  
  this = (LytAnim *)msys::MLyt::getAnim(*(MLyt **)(param_2 + 8),param_3);
  ad::lyt::LytAnim::term(this,true);
  ad::lyt::LytAnim::init(this,param_4,param_5,"");
  ad::lyt::LytAnim::stopAndSetFrm(this,param_1);
  return;
}


// FUNC 0x15008040 main_menu::MainMenu_BadgePage::Core::MBadgeLytCtrl::vfunc_0x40 (MainMenu)
//   size 0x2c | file MainMenu+0x8040 | callers(0) | datarefs 1

void main_menu::MainMenu_BadgePage::Core::MBadgeLytCtrl::vfunc_0x40(void)

{
  FUN_1501580c(msys::MComSys::_sys + 0x49368,0x110016,0,0,0);
  return;
}


// FUNC 0x15008074 main_menu::MainMenu_BadgePage::Core::MBadgeLytCtrl::vfunc_0x8 (MainMenu)
//   size 0x74 | file MainMenu+0x8074 | callers(0) | datarefs 1

void main_menu::MainMenu_BadgePage::Core::MBadgeLytCtrl::vfunc_0x8
               (float param_1,int param_2,short param_3,Layout *param_4,char *param_5,int param_6)

{
  LytAnim *this;
  
  this = (LytAnim *)msys::MLyt::getAnim(*(MLyt **)(param_2 + 8),param_3);
  ad::lyt::LytAnim::term(this,true);
  ad::lyt::LytAnim::init(this,param_4,param_5,"");
  if (param_6 < 0) {
    ad::lyt::LytAnim::playAuto(this,param_1);
    return;
  }
  ad::lyt::LytAnim::play(this,param_1,(short)param_6);
  return;
}


// FUNC 0x150080ec main_menu::MainMenu_BadgePage::Core::MBadgeLytCtrl::vfunc_0xc (MainMenu)
//   size 0x38 | file MainMenu+0x80ec | callers(0) | datarefs 1

void main_menu::MainMenu_BadgePage::Core::MBadgeLytCtrl::vfunc_0xc(int param_1,short param_2)

{
  int iVar1;
  LytAnim *this;
  
  iVar1 = msys::MLyt::getAnim(*(MLyt **)(param_1 + 8),param_2);
  if (*(int *)(iVar1 + 0x14) == 0) {
    return;
  }
  this = (LytAnim *)msys::MLyt::getAnim(*(MLyt **)(param_1 + 8),param_2);
  ad::lyt::LytAnim::stop(this);
  return;
}


// FUNC 0x15008124 main_menu::MainMenu_BadgePage::Core::MBadgeLytCtrl::vfunc_0x34 (MainMenu)
//   size 0x50 | file MainMenu+0x8124 | callers(0) | datarefs 1

void main_menu::MainMenu_BadgePage::Core::MBadgeLytCtrl::vfunc_0x34
               (float param_1,int param_2,short param_3)

{
  int iVar1;
  
  iVar1 = msys::MLyt::getAnim(*(MLyt **)(param_2 + 8),param_3);
  if (*(int *)(iVar1 + 0x14) == 0) {
    return;
  }
  msys::MLyt::getAnim(*(MLyt **)(param_2 + 8),param_3);
  Frm::setFrm(param_1);
  return;
}


// FUNC 0x15008174 ->operator.delete (MainMenu)
//   size 0x4 | file MainMenu+0x8174 | callers(0) | datarefs 1
// veneer/thunk -> 0x00286514 operator.delete (static)

// FUNC 0x15008178 main_menu::MainMenu_BadgePage::Core::MBadgeLytCtrl::vfunc_0x0 (MainMenu)
//   size 0x4 | file MainMenu+0x8178 | callers(0) | datarefs 1

void main_menu::MainMenu_BadgePage::Core::MBadgeLytCtrl::vfunc_0x0(void)

{
  return;
}


// FUNC 0x1500817c main_menu::MainMenu_BadgePage::Core::vfunc_0x10 (MainMenu)
//   size 0x4 | file MainMenu+0x817c | callers(0) | datarefs 1

void main_menu::MainMenu_BadgePage::Core::vfunc_0x10(void)

{
  return;
}


// FUNC 0x15008180 FUN_15008180 (MainMenu)
//   size 0x40 | file MainMenu+0x8180 | callers(0) | datarefs 1

void FUN_15008180(int param_1)

{
  MComSys *this;
  int iVar1;
  
  this = msys::MComSys::_sys;
  if (*(int *)(param_1 + 8) == 0) {
    *(MComSys **)(param_1 + 8) = msys::MComSys::_sys;
  }
  else {
    this = *(MComSys **)(param_1 + 8);
  }
  iVar1 = msys::MComSys::getNextPage(this);
  if (*(char *)(iVar1 + 0x14) != '\0') {
    *(undefined1 **)(param_1 + 0x18) = &LAB_15009364;
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
  return;
}


// FUNC 0x150082b4 FUN_150082b4 (MainMenu)
//   size 0x44 | file MainMenu+0x82b4 | callers(0) | datarefs 2

void FUN_150082b4(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = msys::MComSys::_sys;
  if (*(int *)(param_1 + 8) == 0) {
    *(undefined4 *)(param_1 + 8) = msys::MComSys::_sys;
  }
  else {
    uVar1 = *(undefined4 *)(param_1 + 8);
  }
  FUN_150148b0(0,0x41200000,uVar1,0,2);
  *(code **)(param_1 + 0x20) = FUN_15008308;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


// FUNC 0x15008308 FUN_15008308 (MainMenu)
//   size 0x7c | file MainMenu+0x8308 | callers(0) | datarefs 2

void FUN_15008308(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = msys::MComSys::_sys;
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  else {
    iVar1 = *(int *)(param_1 + 8);
  }
  iVar2 = FUN_150147a8(iVar1);
  iVar1 = msys::MComSys::_sys;
  if (iVar2 == 0) {
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar1;
    }
    CellAnime::play((CellAnime *)(iVar2 + 0xf2010),'\x14',0,1.0);
    iVar2 = msys::MComSys::_sys;
    iVar1 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar1 = iVar2;
    }
    FUN_15014558(iVar1,"MES_menu_tuto_badge_change_badge_change_menu");
    *(code **)(param_1 + 0x20) = FUN_150083c0;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x150083c0 FUN_150083c0 (MainMenu)
//   size 0x7c | file MainMenu+0x83c0 | callers(0) | datarefs 2

void FUN_150083c0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = msys::MComSys::_sys;
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  iVar2 = *(int *)(param_1 + 8);
  if (*(int *)(iVar2 + 0xf1bc0) == 0) {
    if (iVar2 == 0) {
      *(int *)(param_1 + 8) = iVar1;
      iVar2 = iVar1;
    }
    CellAnime::play((CellAnime *)(iVar2 + 0xf2010),'\x16',0,1.0);
    iVar2 = msys::MComSys::_sys;
    iVar1 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar1 = iVar2;
    }
    FUN_15014558(iVar1,"MES_menu_tuto_badge_change_badge_change_l");
    *(undefined1 **)(param_1 + 0x20) = &LAB_15008bd4;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x15008478 FUN_15008478 (MainMenu)
//   size 0x60 | file MainMenu+0x8478 | callers(0) | datarefs 2

void FUN_15008478(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = msys::MComSys::_sys;
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  else {
    iVar2 = *(int *)(param_1 + 8);
  }
  CellAnime::play((CellAnime *)(iVar2 + 0xf2010),'\x12',0,1.0);
  iVar1 = msys::MComSys::_sys;
  iVar2 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar2 = iVar1;
  }
  FUN_15014558(iVar2,"MES_menu_tuto_badge_change_badge_change_m");
  *(undefined1 **)(param_1 + 0x20) = &LAB_15008cdc;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


// FUNC 0x15008510 FUN_15008510 (MainMenu)
//   size 0x60 | file MainMenu+0x8510 | callers(0) | datarefs 2

void FUN_15008510(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = msys::MComSys::_sys;
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  else {
    iVar2 = *(int *)(param_1 + 8);
  }
  CellAnime::play((CellAnime *)(iVar2 + 0xf2010),'\x14',0,1.0);
  iVar1 = msys::MComSys::_sys;
  iVar2 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar2 = iVar1;
  }
  FUN_15014558(iVar2,"MES_menu_tuto_badge_change_badge_effect");
  *(code **)(param_1 + 0x20) = FUN_150085a4;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


// FUNC 0x150085a4 FUN_150085a4 (MainMenu)
//   size 0x60 | file MainMenu+0x85a4 | callers(0) | datarefs 2

void FUN_150085a4(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = msys::MComSys::_sys;
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  iVar2 = *(int *)(param_1 + 8);
  if (*(int *)(iVar2 + 0xf1bc0) == 0) {
    if (iVar2 == 0) {
      *(int *)(param_1 + 8) = iVar1;
      iVar2 = iVar1;
    }
    FUN_150148b0(0x42c80000,0x42340000,iVar2,1,2);
    *(code **)(param_1 + 0x20) = FUN_15008618;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x15008618 FUN_15008618 (MainMenu)
//   size 0x7c | file MainMenu+0x8618 | callers(0) | datarefs 2

void FUN_15008618(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = msys::MComSys::_sys;
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  else {
    iVar1 = *(int *)(param_1 + 8);
  }
  iVar2 = FUN_150147a8(iVar1);
  iVar1 = msys::MComSys::_sys;
  if (iVar2 == 0) {
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar1;
    }
    CellAnime::play((CellAnime *)(iVar2 + 0xf2010),'\x14',0,1.0);
    iVar2 = msys::MComSys::_sys;
    iVar1 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar1 = iVar2;
    }
    FUN_15014558(iVar1,"MES_menu_tuto_badge_change_badge_effect2");
    *(code **)(param_1 + 0x20) = FUN_150086cc;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x150086cc FUN_150086cc (MainMenu)
//   size 0x60 | file MainMenu+0x86cc | callers(0) | datarefs 2

void FUN_150086cc(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = msys::MComSys::_sys;
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  iVar2 = *(int *)(param_1 + 8);
  if (*(int *)(iVar2 + 0xf1bc0) == 0) {
    if (iVar2 == 0) {
      *(int *)(param_1 + 8) = iVar1;
      iVar2 = iVar1;
    }
    FUN_150148b0(0x42200000,0xc2f00000,iVar2,5,2);
    *(code **)(param_1 + 0x20) = FUN_15008740;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x15008740 FUN_15008740 (MainMenu)
//   size 0x7c | file MainMenu+0x8740 | callers(0) | datarefs 2

void FUN_15008740(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = msys::MComSys::_sys;
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  else {
    iVar1 = *(int *)(param_1 + 8);
  }
  iVar2 = FUN_150147a8(iVar1);
  iVar1 = msys::MComSys::_sys;
  if (iVar2 == 0) {
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar1;
    }
    CellAnime::play((CellAnime *)(iVar2 + 0xf2010),'\x14',0,1.0);
    iVar2 = msys::MComSys::_sys;
    iVar1 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar1 = iVar2;
    }
    FUN_15014558(iVar1,"MES_menu_tuto_badge_change_badge_change_ok");
    *(code **)(param_1 + 0x20) = FUN_15008de4;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x150087f4 FUN_150087f4 (MainMenu)
//   size 0x60 | file MainMenu+0x87f4 | callers(0) | datarefs 2

void FUN_150087f4(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = msys::MComSys::_sys;
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  iVar2 = *(int *)(param_1 + 8);
  if (*(int *)(iVar2 + 0xf1bc0) == 0) {
    if (iVar2 == 0) {
      *(int *)(param_1 + 8) = iVar1;
      iVar2 = iVar1;
    }
    FUN_150148b0(0xc3340000,0xc2f00000,iVar2,6,0);
    *(code **)(param_1 + 0x20) = FUN_15008868;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x15008868 FUN_15008868 (MainMenu)
//   size 0x60 | file MainMenu+0x8868 | callers(0) | datarefs 2

void FUN_15008868(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = msys::MComSys::_sys;
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  else {
    iVar1 = *(int *)(param_1 + 8);
  }
  iVar2 = FUN_150147a8(iVar1);
  iVar1 = msys::MComSys::_sys;
  if (iVar2 == 0) {
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar1;
    }
    FUN_150148b0(0xc3020000,0xc2f00000,iVar2,2);
    *(code **)(param_1 + 0x20) = FUN_150088d8;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x150088d8 FUN_150088d8 (MainMenu)
//   size 0x7c | file MainMenu+0x88d8 | callers(0) | datarefs 2

void FUN_150088d8(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = msys::MComSys::_sys;
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  else {
    iVar1 = *(int *)(param_1 + 8);
  }
  iVar2 = FUN_150147a8(iVar1);
  iVar1 = msys::MComSys::_sys;
  if (iVar2 == 0) {
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar1;
    }
    CellAnime::play((CellAnime *)(iVar2 + 0xf2010),'\x14',0,1.0);
    iVar2 = msys::MComSys::_sys;
    iVar1 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar1 = iVar2;
    }
    FUN_15014558(iVar1,"MES_menu_tuto_badge_change_caution");
    *(code **)(param_1 + 0x20) = FUN_15008984;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x15008984 FUN_15008984 (MainMenu)
//   size 0x60 | file MainMenu+0x8984 | callers(0) | datarefs 2

void FUN_15008984(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = msys::MComSys::_sys;
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  iVar2 = *(int *)(param_1 + 8);
  if (*(int *)(iVar2 + 0xf1bc0) == 0) {
    if (iVar2 == 0) {
      *(int *)(param_1 + 8) = iVar1;
      iVar2 = iVar1;
    }
    FUN_150148b0(0xc3340000,0xc2f00000,iVar2,6,0);
    *(code **)(param_1 + 0x20) = FUN_150089f8;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x150089f8 FUN_150089f8 (MainMenu)
//   size 0xdc | file MainMenu+0x89f8 | callers(0) | datarefs 2

void FUN_150089f8(int param_1)

{
  int iVar1;
  int iVar2;
  BootInfo *pBVar3;
  undefined4 local_20 [2];
  
  iVar2 = msys::MComSys::_sys;
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  else {
    iVar2 = *(int *)(param_1 + 8);
  }
  iVar2 = FUN_150147a8(iVar2);
  if (iVar2 == 0) {
    iVar2 = main_menu::GetBootInfo();
    *(undefined1 *)(iVar2 + 0x2c) = 0;
    pBVar3 = (BootInfo *)main_menu::GetBootInfo();
    main_menu::BootInfo::setBootPage(pBVar3,0);
    iVar1 = msys::MComSys::_sys;
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar1;
    }
    *(undefined1 *)(iVar2 + 0xe6508) = 0;
    local_20[0] = 0xff000000;
    MoveC::moveFrm((MoveC *)(iVar2 + 0x4acd4),(Color8 *)local_20,16.0);
    MoveC::moveFrm((MoveC *)(iVar2 + 0x4ad14),(Color8 *)local_20,16.0);
    pBVar3 = (BootInfo *)main_menu::GetBootInfo();
    main_menu::BootInfo::stopRcordBgm(pBVar3);
    pBVar3 = (BootInfo *)main_menu::GetBootInfo();
    main_menu::BootInfo::restoreBgm(pBVar3);
    *(undefined1 *)(iVar2 + 0xe904b) = 4;
    *(undefined **)(param_1 + 0x20) = &DAT_15008aec;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x15008af0 FUN_15008af0 (MainMenu)
//   size 0xb4 | file MainMenu+0x8af0 | callers(0) | datarefs 2

void FUN_15008af0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = msys::MComSys::_sys;
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  *(undefined1 *)(*(int *)(param_1 + 8) + 0xe6508) = 1;
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = iVar1;
  }
  *(undefined1 *)(*(int *)(param_1 + 8) + 0xe650a) = 1;
  *(undefined1 *)(param_1 + 0xde5) = 1;
  *(undefined1 **)(param_1 + 0x20) = &LAB_150092d0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  iVar2 = main_menu::GetBootInfo();
  iVar1 = msys::MComSys::_sys;
  if (*(char *)(iVar2 + 0x2c) == '\x01') {
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar1;
    }
    *(undefined1 *)(iVar2 + 0xe6508) = 0;
    iVar2 = msys::MComSys::_sys;
    iVar1 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar1 = iVar2;
    }
    *(undefined1 *)(iVar1 + 0xe650a) = 1;
    *(code **)(param_1 + 0x20) = FUN_150082b4;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x15008c24 FUN_15008c24 (MainMenu)
//   size 0xa4 | file MainMenu+0x8c24 | callers(0) | datarefs 1

void FUN_15008c24(int param_1)

{
  int iVar1;
  int iVar2;
  float fVar3;
  
  iVar2 = msys::MComSys::_sys;
  if ((*(byte *)(param_1 + 0x886) & 1) != 0) {
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
  if (*(int *)(param_1 + 0x874) == 0) {
    *(code **)(param_1 + 0x20) = FUN_15008478;
    *(undefined4 *)(param_1 + 0x24) = 0;
    return;
  }
  *(int *)(param_1 + 0x874) = *(int *)(param_1 + 0x874) + -1;
  Frm::play((Frm *)(param_1 + 0x878),40.0);
  iVar1 = msys::MComSys::_sys;
  iVar2 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar2 = iVar1;
  }
  *(undefined4 *)(iVar2 + 0xe6518) = 0x200;
  return;
}


// FUNC 0x15008d2c FUN_15008d2c (MainMenu)
//   size 0xa4 | file MainMenu+0x8d2c | callers(0) | datarefs 1

void FUN_15008d2c(int param_1)

{
  int iVar1;
  int iVar2;
  float fVar3;
  
  iVar2 = msys::MComSys::_sys;
  if ((*(byte *)(param_1 + 0x886) & 1) != 0) {
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
  if (*(int *)(param_1 + 0x874) == 0) {
    *(code **)(param_1 + 0x20) = FUN_15008510;
    *(undefined4 *)(param_1 + 0x24) = 0;
    return;
  }
  *(int *)(param_1 + 0x874) = *(int *)(param_1 + 0x874) + -1;
  Frm::play((Frm *)(param_1 + 0x878),40.0);
  iVar1 = msys::MComSys::_sys;
  iVar2 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar2 = iVar1;
  }
  *(undefined4 *)(iVar2 + 0xe6518) = 0x100;
  return;
}


// FUNC 0x15008de4 FUN_15008de4 (MainMenu)
//   size 0x7c | file MainMenu+0x8de4 | callers(0) | datarefs 2

void FUN_15008de4(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = msys::MComSys::_sys;
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  iVar2 = *(int *)(param_1 + 8);
  if (*(int *)(iVar2 + 0xf1bc0) == 0) {
    if (iVar2 == 0) {
      *(int *)(param_1 + 8) = iVar1;
      iVar2 = iVar1;
    }
    CellAnime::play((CellAnime *)(iVar2 + 0xf2010),'\x14',0,1.0);
    iVar2 = msys::MComSys::_sys;
    iVar1 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar1 = iVar2;
    }
    FUN_15014558(iVar1,"MES_menu_tuto_badge_change_tuto_end");
    *(code **)(param_1 + 0x20) = FUN_150087f4;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x15008e94 ->msys::MLyt::applyAnime (MainMenu)
//   size 0x4 | file MainMenu+0x8e94 | callers(0) | datarefs 1
// veneer/thunk -> 0x0032b70c msys::MLyt::applyAnime (static)

// FUNC 0x15008e98 main_menu::MainMenu_BadgePage::Core::MBadgeL::vfunc_0xc (MainMenu)
//   size 0x88 | file MainMenu+0x8e98 | callers(0) | datarefs 1

void main_menu::MainMenu_BadgePage::Core::MBadgeL::vfunc_0xc(MLyt *param_1,MInput *param_2)

{
  undefined4 local_20;
  undefined2 local_1c;
  undefined2 local_1a;
  undefined1 local_18;
  undefined1 local_17;
  undefined1 local_16;
  undefined4 local_14;
  undefined4 local_10;
  
  msys::MLyt::updateInput(param_1,param_2);
  badge::ChangeBadgeLlcd::UpdateParam::UpdateParam((UpdateParam *)&local_20);
  local_20 = 0x40000000;
  local_1c = *(undefined2 *)(param_2 + 0x14);
  local_1a = *(undefined2 *)(param_2 + 0x16);
  local_18 = param_2[0x11] != (MInput)0x0;
  local_17 = param_2[0x10] != (MInput)0x0;
  local_16 = param_2[0x12] != (MInput)0x0;
  local_14 = *(undefined4 *)(param_2 + 4);
  local_10 = *(undefined4 *)param_2;
  badge::ChangeBadgeLlcd::update(*(ChangeBadgeLlcd **)(param_1 + 0x3b8),(UpdateParam *)&local_20);
  return;
}


// FUNC 0x15008f24 ->msys::MLyt::updateAnimeFrm (MainMenu)
//   size 0x4 | file MainMenu+0x8f24 | callers(0) | datarefs 1
// veneer/thunk -> 0x0032be0c msys::MLyt::updateAnimeFrm (static)

// FUNC 0x15008f28 FUN_15008f28 (MainMenu)
//   size 0xb4 | file MainMenu+0x8f28 | callers(0)

void FUN_15008f28(MLyt *param_1,undefined4 param_2,LytResourceMan *param_3,char *param_4,
                 ButtonGroup *param_5,MCtrUserDataListAcs *param_6,int param_7,MemAlcBase *param_8)

{
  ChangeBadgeLlcd *pCVar1;
  undefined4 uVar2;
  void *pvVar3;
  undefined4 local_3c;
  ButtonGroup *pBStack_38;
  MLyt *local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  *(undefined4 *)(param_1 + 0x3a8) = param_2;
  msys::MLyt::createLyt(param_1,param_3,param_4,param_5,param_6);
  *(undefined4 *)(param_1 + 0x3b0) = *(undefined4 *)(param_1 + 0x3a8);
  *(MLyt **)(param_1 + 0x3b4) = param_1;
  badge::ChangeBadgeLlcd::InitParam::InitParam((InitParam *)&local_3c);
  local_3c = *(undefined4 *)(param_1 + 0x150);
  local_34 = param_1 + 0x3ac;
  pBStack_38 = param_5;
  local_30 = 0x43470000;
  local_2c = *(undefined4 *)(param_7 + 0x3b8);
  pCVar1 = operator_new(0x14170,param_8,"ChangeBadgeLlcd",0);
  uVar2 = 0;
  if (pCVar1 != (ChangeBadgeLlcd *)0x0) {
    uVar2 = badge::ChangeBadgeLlcd::ChangeBadgeLlcd(pCVar1,(InitParam *)&local_3c);
  }
  pCVar1 = *(ChangeBadgeLlcd **)(param_1 + 0x3b8);
  *(undefined4 *)(param_1 + 0x3b8) = uVar2;
  if (pCVar1 != (ChangeBadgeLlcd *)0x0) {
    pvVar3 = (void *)badge::ChangeBadgeLlcd::~ChangeBadgeLlcd(pCVar1);
    operator_delete(pvVar3);
  }
  return;
}


// FUNC 0x15008ff4 main_menu::MainMenu_BadgePage::Core::MBadgeL::vfunc_0x14 (MainMenu)
//   size 0x4c | file MainMenu+0x8ff4 | callers(0) | datarefs 1

void main_menu::MainMenu_BadgePage::Core::MBadgeL::vfunc_0x14
               (MLyt *param_1,MRenderQueueBase *param_2,uchar param_3)

{
  int iVar1;
  int iVar2;
  
  msys::MLyt::enqueue(param_1,param_2,param_3);
  iVar1 = msys::MComSys::_sys;
  iVar2 = *(int *)(*(int *)(param_1 + 0x3a8) + 8);
  if (iVar2 == 0) {
    *(int *)(*(int *)(param_1 + 0x3a8) + 8) = msys::MComSys::_sys;
    iVar2 = iVar1;
  }
  badge::ChangeBadgeLlcd::drawOverlayMsg
            (*(ChangeBadgeLlcd **)(param_1 + 0x3b8),(RenderQueue *)param_2,
             (MessageDrawer *)(iVar2 + 0xac2d8));
  return;
}


// FUNC 0x15009048 main_menu::MainMenu_BadgePage::Core::MBadgeL::vfunc_0x4 (MainMenu)
//   size 0x74 | file MainMenu+0x9048 | callers(0) | datarefs 1

void main_menu::MainMenu_BadgePage::Core::MBadgeL::vfunc_0x4(MLyt *param_1)

{
  void *pvVar1;
  
  *(undefined ***)param_1 = &vtable;
  if (*(ChangeBadgeLlcd **)(param_1 + 0x3b8) != (ChangeBadgeLlcd *)0x0) {
    pvVar1 = (void *)badge::ChangeBadgeLlcd::~ChangeBadgeLlcd
                               (*(ChangeBadgeLlcd **)(param_1 + 0x3b8));
    operator_delete(pvVar1);
  }
  *(undefined ***)param_1 = &msys::MLyt::vtable;
  msys::MLyt::term(param_1);
  __aeabi_vec_dtor(param_1 + 0x2b0,&LAB_15000e80,0x10,0xc);
  __aeabi_vec_dtor(param_1 + 0x154,&LAB_15000d18,0x1c,0xc);
  pvVar1 = (void *)msys::MChrBase::vfunc_0x0(param_1);
  operator_delete(pvVar1);
  return;
}


// FUNC 0x150090cc main_menu::MainMenu_BadgePage::Core::MBadgeL::vfunc_0x0 (MainMenu)
//   size 0x6c | file MainMenu+0x90cc | callers(0) | datarefs 1

void main_menu::MainMenu_BadgePage::Core::MBadgeL::vfunc_0x0(MLyt *param_1)

{
  void *pvVar1;
  
  *(undefined ***)param_1 = &vtable;
  if (*(ChangeBadgeLlcd **)(param_1 + 0x3b8) != (ChangeBadgeLlcd *)0x0) {
    pvVar1 = (void *)badge::ChangeBadgeLlcd::~ChangeBadgeLlcd
                               (*(ChangeBadgeLlcd **)(param_1 + 0x3b8));
    operator_delete(pvVar1);
  }
  *(undefined ***)param_1 = &msys::MLyt::vtable;
  msys::MLyt::term(param_1);
  __aeabi_vec_dtor(param_1 + 0x2b0,&LAB_15000e80,0x10,0xc);
  __aeabi_vec_dtor(param_1 + 0x154,&LAB_15000d18,0x1c,0xc);
  msys::MChrBase::vfunc_0x0(param_1);
  return;
}


// FUNC 0x15009148 ->msys::MLyt::applyAnime (MainMenu)
//   size 0x4 | file MainMenu+0x9148 | callers(0) | datarefs 1
// veneer/thunk -> 0x0032b70c msys::MLyt::applyAnime (static)

// FUNC 0x1500914c main_menu::MainMenu_BadgePage::Core::MBadgeU::vfunc_0xc (MainMenu)
//   size 0x2c | file MainMenu+0x914c | callers(0) | datarefs 1

void main_menu::MainMenu_BadgePage::Core::MBadgeU::vfunc_0xc
               (MLyt *param_1,MInput *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_10;
  
  local_10 = param_4;
  msys::MLyt::updateInput(param_1,param_2);
  badge::ChangeBadgeUlcd::UpdateParam::UpdateParam((UpdateParam *)&local_10);
  local_10 = 0x40000000;
  badge::ChangeBadgeUlcd::update(*(UpdateParam **)(param_1 + 0x3b8));
  return;
}


// FUNC 0x1500917c ->msys::MLyt::updateAnimeFrm (MainMenu)
//   size 0x4 | file MainMenu+0x917c | callers(0) | datarefs 1
// veneer/thunk -> 0x0032be0c msys::MLyt::updateAnimeFrm (static)

// FUNC 0x15009180 main_menu::MainMenu_BadgePage::Core::MBadgeU::vfunc_0x14 (MainMenu)
//   size 0x48 | file MainMenu+0x9180 | callers(0) | datarefs 1

void main_menu::MainMenu_BadgePage::Core::MBadgeU::vfunc_0x14
               (MLyt *param_1,MRenderQueueBase *param_2,uchar param_3)

{
  int iVar1;
  int iVar2;
  
  msys::MLyt::enqueue(param_1,param_2,param_3);
  iVar1 = msys::MComSys::_sys;
  iVar2 = *(int *)(*(int *)(param_1 + 0x3a8) + 8);
  if (iVar2 == 0) {
    *(int *)(*(int *)(param_1 + 0x3a8) + 8) = msys::MComSys::_sys;
    iVar2 = iVar1;
  }
  badge::ChangeBadgeUlcd::drawOverlayMsg
            (*(ChangeBadgeUlcd **)(param_1 + 0x3b8),(RenderQueue *)param_2,
             (MessageDrawer *)(iVar2 + 0x98a34));
  return;
}


// FUNC 0x150091d0 main_menu::MainMenu_BadgePage::Core::MBadgeU::vfunc_0x4 (MainMenu)
//   size 0x74 | file MainMenu+0x91d0 | callers(0) | datarefs 1

void main_menu::MainMenu_BadgePage::Core::MBadgeU::vfunc_0x4(MLyt *param_1)

{
  void *pvVar1;
  
  *(undefined ***)param_1 = &vtable;
  if (*(ChangeBadgeUlcd **)(param_1 + 0x3b8) != (ChangeBadgeUlcd *)0x0) {
    pvVar1 = (void *)badge::ChangeBadgeUlcd::~ChangeBadgeUlcd
                               (*(ChangeBadgeUlcd **)(param_1 + 0x3b8));
    operator_delete(pvVar1);
  }
  *(undefined ***)param_1 = &msys::MLyt::vtable;
  msys::MLyt::term(param_1);
  __aeabi_vec_dtor(param_1 + 0x2b0,&LAB_15000e80,0x10,0xc);
  __aeabi_vec_dtor(param_1 + 0x154,&LAB_15000d18,0x1c,0xc);
  pvVar1 = (void *)msys::MChrBase::vfunc_0x0(param_1);
  operator_delete(pvVar1);
  return;
}


// FUNC 0x15009254 main_menu::MainMenu_BadgePage::Core::MBadgeU::vfunc_0x0 (MainMenu)
//   size 0x6c | file MainMenu+0x9254 | callers(0) | datarefs 1

void main_menu::MainMenu_BadgePage::Core::MBadgeU::vfunc_0x0(MLyt *param_1)

{
  void *pvVar1;
  
  *(undefined ***)param_1 = &vtable;
  if (*(ChangeBadgeUlcd **)(param_1 + 0x3b8) != (ChangeBadgeUlcd *)0x0) {
    pvVar1 = (void *)badge::ChangeBadgeUlcd::~ChangeBadgeUlcd
                               (*(ChangeBadgeUlcd **)(param_1 + 0x3b8));
    operator_delete(pvVar1);
  }
  *(undefined ***)param_1 = &msys::MLyt::vtable;
  msys::MLyt::term(param_1);
  __aeabi_vec_dtor(param_1 + 0x2b0,&LAB_15000e80,0x10,0xc);
  __aeabi_vec_dtor(param_1 + 0x154,&LAB_15000d18,0x1c,0xc);
  msys::MChrBase::vfunc_0x0(param_1);
  return;
}


// FUNC 0x15009374 FUN_15009374 (MainMenu)
//   size 0xa4 | file MainMenu+0x9374 | callers(0) | datarefs 1

void FUN_15009374(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  FUN_150144d8();
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
  ad::fw::TaskBase::readLyt
            (*(TaskBase **)(iVar3 + 4),(Resource *)(param_1 + 0xcc),
             (FileContext *)(*(int *)(iVar1 + 0x278) + 0x150),"?MENU_BADGE",
             (MemAlcBase *)(param_1 + 0x28),0x7f,(ResCacheArg *)0x0);
  puVar2 = operator_new(8,*(MemAlcBase **)(*(int *)(param_1 + 4) + 0x18),"ParamMainBadge",0);
  if (puVar2 != (undefined4 *)0x0) {
    *puVar2 = 0;
    puVar2[1] = 0;
  }
  *(undefined4 **)(param_1 + 0x868) = puVar2;
  *(undefined1 **)(param_1 + 0x10) = &LAB_15007f0c;
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}


// FUNC 0x15009458 FUN_15009458 (MainMenu)
//   size 0xc4 | file MainMenu+0x9458 | callers(1) 0x150096f0

void FUN_15009458(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)FUN_15014438();
  *puVar1 = &main_menu::MainMenu_BadgePage::Core::vtable;
  puVar1[0x21e] = 0;
  puVar1[0x21f] = 0x3f800000;
  puVar1[0x220] = 0;
  *(undefined2 *)(puVar1 + 0x221) = 1;
  *(undefined2 *)((int)puVar1 + 0x886) = 0;
  iVar2 = ad::fw::Resource::Resource((Resource *)(puVar1 + 0x222));
  iVar2 = ad::ctrl::ButtonGroup::ButtonGroup((ButtonGroup *)(iVar2 + 0x44));
  puVar1 = (undefined4 *)FUN_150153d8(iVar2 + 0x1c);
  *puVar1 = &main_menu::MainMenu_BadgePage::Core::MBadgeU::vtable;
  puVar1[0xeb] = &main_menu::MainMenu_BadgePage::Core::MBadgeLytCtrl::vtable;
  puVar1[0xee] = 0;
  puVar1 = (undefined4 *)FUN_150153d8(puVar1 + 0xef);
  *puVar1 = &main_menu::MainMenu_BadgePage::Core::MBadgeL::vtable;
  puVar1[0xeb] = &main_menu::MainMenu_BadgePage::Core::MBadgeLytCtrl::vtable;
  puVar1[0xee] = 0;
  puVar1[0xf0] = puVar1 + 0xf0;
  puVar1[0xef] = 0;
  puVar1[0xf1] = puVar1 + 0xf0;
  puVar1[-0x325] = FUN_15009374;
  puVar1[-0x324] = 0;
  puVar1[-0x323] = &LAB_15009440;
  puVar1[-0x322] = 0;
  puVar1[-0x321] = FUN_15007f20;
  puVar1[-800] = 0;
  return;
}


// FUNC 0x15009538 main_menu::MainMenu_BadgePage::Core::vfunc_0x4 (MainMenu)
//   size 0x10 | file MainMenu+0x9538 | callers(0) | datarefs 1

void main_menu::MainMenu_BadgePage::Core::vfunc_0x4(void)

{
  void *pvVar1;
  
  pvVar1 = (void *)vfunc_0x0();
  operator_delete(pvVar1);
  return;
}


// FUNC 0x15009548 main_menu::MainMenu_BadgePage::Core::vfunc_0x0 (MainMenu)
//   size 0x18c | file MainMenu+0x9548 | callers(1) 0x15009538 | datarefs 1

void main_menu::MainMenu_BadgePage::Core::vfunc_0x0(undefined4 *param_1)

{
  void *pvVar1;
  int iVar2;
  MLyt *pMVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  *param_1 = &vtable;
  ad::ctrl::ButtonGroup::FreeAll((ButtonGroup *)(param_1 + 0x233));
  msys::MLyt::term((MLyt *)(param_1 + 0x23a));
  msys::MLyt::term((MLyt *)(param_1 + 0x329));
  operator_delete((void *)param_1[0x21a]);
  param_1[0x21a] = 0;
  puVar4 = (undefined4 *)param_1[0x419];
  if ((undefined4 *)param_1[0x419] != param_1 + 0x419) {
    do {
      puVar5 = (undefined4 *)*puVar4;
      nw::ut::internal::LinkListImpl::erase((LinkListImpl *)(param_1 + 0x418));
      if (puVar4 != (undefined4 *)0x0) {
        ad::lyt::Layout::FreeMemory(puVar4);
      }
      puVar4 = puVar5;
    } while (puVar5 != param_1 + 0x419);
  }
  param_1[0x329] = &MBadgeL::vtable;
  if ((ChangeBadgeLlcd *)param_1[0x417] != (ChangeBadgeLlcd *)0x0) {
    pvVar1 = (void *)badge::ChangeBadgeLlcd::~ChangeBadgeLlcd((ChangeBadgeLlcd *)param_1[0x417]);
    operator_delete(pvVar1);
  }
  pMVar3 = (MLyt *)(param_1 + 0x329);
  *(undefined ***)pMVar3 = &msys::MLyt::vtable;
  msys::MLyt::term(pMVar3);
  __aeabi_vec_dtor(param_1 + 0x3d5,&LAB_15000e80,0x10,0xc);
  __aeabi_vec_dtor(param_1 + 0x37e,&LAB_15000d18,0x1c,0xc);
  iVar2 = msys::MChrBase::vfunc_0x0(pMVar3);
  *(undefined ***)(iVar2 + -0x3bc) = &MBadgeU::vtable;
  if (*(ChangeBadgeUlcd **)(iVar2 + -4) != (ChangeBadgeUlcd *)0x0) {
    pvVar1 = (void *)badge::ChangeBadgeUlcd::~ChangeBadgeUlcd(*(ChangeBadgeUlcd **)(iVar2 + -4));
    operator_delete(pvVar1);
  }
  pMVar3 = (MLyt *)(iVar2 + -0x3bc);
  *(undefined ***)pMVar3 = &msys::MLyt::vtable;
  msys::MLyt::term(pMVar3);
  __aeabi_vec_dtor(iVar2 + -0x10c,&LAB_15000e80,0x10,0xc);
  __aeabi_vec_dtor(iVar2 + -0x268,&LAB_15000d18,0x1c,0xc);
  iVar2 = msys::MChrBase::vfunc_0x0(pMVar3);
  iVar2 = ad::ctrl::ButtonGroup::~ButtonGroup((ButtonGroup *)(iVar2 + -0x1c));
  iVar2 = ad::fw::Resource::~Resource((Resource *)(iVar2 + -0x44));
  *(undefined4 *)(iVar2 + -8) = 0;
  MainMenuPageBase::Core::vfunc_0x0(iVar2 + -0x888);
  return;
}


// FUNC 0x150096f0 main_menu::MainMenu_BadgePage::vfunc_0x30 (MainMenu)
//   size 0x30 | file MainMenu+0x96f0 | callers(0) | datarefs 1

void main_menu::MainMenu_BadgePage::vfunc_0x30(int param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(0x106c,*(MemAlcBase **)(param_1 + 0x18),(char *)0x0,0x1f);
  uVar2 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_15009458(pvVar1,param_1);
  }
  *(undefined4 *)(param_1 + 0x20) = uVar2;
  return;
}


// FUNC 0x15009724 main_menu::MainMenu_BadgePage::vfunc_0x24 (MainMenu)
//   size 0x8 | file MainMenu+0x9724 | callers(0) | datarefs 1

undefined4 main_menu::MainMenu_BadgePage::vfunc_0x24(void)

{
  return 5;
}


// FUNC 0x1500972c main_menu::MainMenu_BadgePage::vfunc_0x4 (MainMenu)
//   size 0x10 | file MainMenu+0x972c | callers(0) | datarefs 1

void main_menu::MainMenu_BadgePage::vfunc_0x4(void)

{
  void *pvVar1;
  
  pvVar1 = (void *)MainMenuPageBase::vfunc_0x0();
  operator_delete(pvVar1);
  return;
}


// FUNC 0x1500973c ->main_menu::MainMenuPageBase::vfunc_0x0 (MainMenu)
//   size 0x4 | file MainMenu+0x973c | callers(0) | datarefs 1
// veneer/thunk -> 0x15015174 main_menu::MainMenuPageBase::vfunc_0x0 (MainMenu)

// FUNC 0x1500a480 FUN_1500a480 (MainMenu)
//   size 0x130 | file MainMenu+0xa480 | callers(0)

void FUN_1500a480(int param_1,int param_2,int param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  
  cVar1 = *(char *)(param_1 + 0x875);
  uVar5 = 0;
  if ((DAT_150360e2 != cVar1) && (uVar5 = (uint)(DAT_150360e3 == cVar1), DAT_150360e3 != cVar1)) {
    if (DAT_150360e4 == cVar1) {
      uVar5 = 2;
    }
    else {
      uVar5 = 3;
    }
  }
  if (param_3 == 4) {
    FUN_1501580c(msys::MComSys::_sys + 0x49368,0x110016,0,0,0);
    iVar3 = msys::MComSys::_sys;
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar3;
    }
    *(undefined1 *)(iVar2 + 0xe6508) = 0;
                    /* WARNING: Could not recover jumptable at 0x1500a5ac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(param_1 + uVar5 * 4 + 0x44e98) + 0x18))();
    return;
  }
  if (param_3 == 5) {
    FUN_15012af4(param_1,(&DAT_150360e2)[*(byte *)(param_2 + 0x48)],0,
                 (uint)*(byte *)(param_2 + 0x48),param_4);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
    }
    uVar4 = DataPc::getEquip((DataPc *)
                             (*(int *)(param_1 + 8) + (uint)*(byte *)(param_1 + 0x875) * 0xb0 +
                             0xeac64),*(uchar *)(param_1 + 0x874));
    FUN_15012a2c(param_1 + 0x968,uVar4);
    iVar3 = msys::MComSys::_sys;
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar3;
    }
    *(undefined1 *)(iVar2 + 0xe6508) = 1;
  }
  return;
}


// FUNC 0x1500a5c0 main_menu::MainMenu_EquipPage::Core::MoveListCur::vfunc_0x8 (MainMenu)
//   size 0x184 | file MainMenu+0xa5c0 | callers(1) 0x15009ad0 | datarefs 1

void main_menu::MainMenu_EquipPage::Core::MoveListCur::vfunc_0x8(int param_1,int param_2)

{
  MLyt *this;
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  InitParam aIStack_60 [72];
  
  *(int *)(param_1 + 4) = param_2;
  msys::MCellAnime::init((MCellAnime *)(param_1 + 0x6cac),(Resource *)(param_2 + 0x836c));
  *(byte *)(param_1 + 0x6e9b) = *(byte *)(param_1 + 0x6e9b) | 3;
  msys::MListWndPBase::getListWnd((MListWndPBase *)(param_2 + 0x44eac));
  this = (MLyt *)(param_2 + 0x4b8);
  iVar1 = msys::MLyt::getPane(this,"NAME_BAR",(char *)0x0,(char *)0x0);
  *(int *)(param_1 + 8) = iVar1;
  *(byte *)(iVar1 + 0x44) = *(byte *)(iVar1 + 0x44) & 0xfe;
  msys::MLyt::attachMChr
            (this,(MChrBase *)(param_1 + 0x6cac),"INS_ICON_OBJ",(char *)0x0,(char *)0x0,(char *)0x0)
  ;
  uVar3 = *(undefined4 *)(*(int *)(param_2 + 0x86c) + 0x18);
  *(undefined4 *)(param_1 + 0x6ca8) = 0x401;
  *(undefined4 *)(param_1 + 0x6c9c) = uVar3;
  *(undefined4 *)(param_1 + 0x6ca0) = 0;
  *(undefined4 *)(param_1 + 0x6ca4) = 0;
  MessageSimple::init((MessageSimple *)(param_1 + 0x1b4));
  FUN_150142ec(param_1 + 0x68);
  msys::MLyt::attachMChr
            (this,(MChrBase *)(param_1 + 0x68),"INS_list_text",(char *)0x0,(char *)0x0,(char *)0x0);
  MessageWriter::setFontColor((MessageWriter *)(param_1 + 0x1b4),0xe6e6e6ff,true);
  ad::lyt::LytNumReel3::InitParam::InitParam(aIStack_60);
  iVar2 = msys::MComSys::_sys;
  iVar1 = *(int *)(param_2 + 8);
  if (*(int *)(param_2 + 8) == 0) {
    *(int *)(param_2 + 8) = msys::MComSys::_sys;
    iVar1 = iVar2;
  }
  msys::MLytNumRes::set((MLytNumRes *)(iVar1 + 0x844),aIStack_60,0,0,0xff);
  iVar2 = *(int *)(param_2 + 8);
  iVar1 = iVar2;
  if (iVar2 == 0) {
    iVar1 = msys::MComSys::_sys;
  }
  if (iVar2 == 0) {
    *(int *)(param_2 + 8) = iVar1;
  }
  msys::MLytNum::init((MLytNum *)(param_1 + 0x6f28),aIStack_60,(LytDrawData *)(iVar1 + 0xd3000),this
                      ,"INS_COUNT",(char *)0x0,(char *)0x0,(char *)0x0);
  return;
}


// FUNC 0x1500a790 main_menu::MainMenu_EquipPage::Core::MoveListCur::vfunc_0xc (MainMenu)
//   size 0x90 | file MainMenu+0xa790 | callers(0) | datarefs 1

void main_menu::MainMenu_EquipPage::Core::MoveListCur::vfunc_0xc(int param_1,int *param_2)

{
  *(undefined1 *)(param_1 + 0x7069) = 1;
  ad::lyt::LytNumReel3::setValueInstant
            ((LytNumReel3 *)(param_1 + 0x7078),(uint)*(ushort *)(param_2 + 1));
  msys::MMsg::playStr((MMsg *)(param_1 + 0x68),(wchar_t *)param_2[4],(InsParam *)0x0,false);
  if (*(char *)((int)param_2 + 0xb) == -1) {
    *(undefined1 *)(param_1 + 0x6ded) = 0;
  }
  else {
    *(undefined1 *)(param_1 + 0x6ded) = 1;
    CellAnime::play((CellAnime *)(param_1 + 0x6df8),*(uchar *)((int)param_2 + 0xb),0,1.0);
  }
  *(bool *)(param_1 + 0x7069) = *param_2 != 0;
  return;
}


// FUNC 0x1500a824 main_menu::MainMenu_EquipPage::Core::MoveListCur::vfunc_0x4 (MainMenu)
//   size 0x9c | file MainMenu+0xa824 | callers(0) | datarefs 1

void main_menu::MainMenu_EquipPage::Core::MoveListCur::vfunc_0x4(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &vtable;
  iVar1 = msys::MLytNum::~MLytNum((MLytNum *)(param_1 + 0x1bca));
  *(undefined ***)(iVar1 + -0x6f28) = &MoveNameBarBase::vtable;
  *(undefined ***)(iVar1 + -0x27c) = &msys::MCellAnime::vtable;
  iVar1 = CellAnime::~CellAnime((CellAnime *)(iVar1 + -0x130));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  *(undefined ***)(iVar1 + -0x6c44) = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar1 = MessageSimple::~MessageSimple((MessageSimple *)(iVar1 + -0x6af8));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  *(undefined ***)(iVar1 + -0x5c) = &vtable_for_5MoveVILj1EE;
  __aeabi_vec_dtor(iVar1 + -0x2c,MoveWorkF::~MoveWorkF,0x2c,1);
  iVar1 = MoveVBase::~MoveVBase((MoveVBase *)(iVar1 + -0x5c));
  operator_delete((void *)(iVar1 + -0xc));
  return;
}


// FUNC 0x1500a8d8 main_menu::MainMenu_EquipPage::Core::MoveListCur::vfunc_0x0 (MainMenu)
//   size 0x98 | file MainMenu+0xa8d8 | callers(0) | datarefs 1

int main_menu::MainMenu_EquipPage::Core::MoveListCur::vfunc_0x0(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &vtable;
  iVar1 = msys::MLytNum::~MLytNum((MLytNum *)(param_1 + 0x1bca));
  *(undefined ***)(iVar1 + -0x6f28) = &MoveNameBarBase::vtable;
  *(undefined ***)(iVar1 + -0x27c) = &msys::MCellAnime::vtable;
  iVar1 = CellAnime::~CellAnime((CellAnime *)(iVar1 + -0x130));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  *(undefined ***)(iVar1 + -0x6c44) = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar1 = MessageSimple::~MessageSimple((MessageSimple *)(iVar1 + -0x6af8));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  *(undefined ***)(iVar1 + -0x5c) = &vtable_for_5MoveVILj1EE;
  __aeabi_vec_dtor(iVar1 + -0x2c,MoveWorkF::~MoveWorkF,0x2c,1);
  iVar1 = MoveVBase::~MoveVBase((MoveVBase *)(iVar1 + -0x5c));
  return iVar1 + -0xc;
}


// FUNC 0x1500a994 FUN_1500a994 (MainMenu)
//   size 0x370 | file MainMenu+0xa994 | callers(0)

void FUN_1500a994(int param_1,int param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  undefined4 extraout_r1;
  undefined4 uVar5;
  undefined4 extraout_r1_00;
  int iVar6;
  MCursorBase *this;
  bool bVar7;
  uint in_fpscr;
  float fVar8;
  LytAnim local_4c [4];
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined2 local_3c;
  undefined2 local_3a;
  undefined4 local_38;
  undefined4 local_34;
  
  iVar2 = msys::MComSys::_sys;
  bVar1 = *(byte *)(param_2 + 0x48);
  uVar3 = (uint)bVar1;
  this = (MCursorBase *)(param_1 + 0x87c);
  if (param_3 == 1) {
    if ((int)*(char *)(param_1 + 0x874) != uVar3) {
      *(byte *)(param_1 + 0x874) = bVar1;
      iVar6 = *(int *)(param_1 + 8);
      if (iVar6 == 0) {
        *(int *)(param_1 + 8) = iVar2;
        iVar6 = iVar2;
      }
      uVar5 = DataPc::getEquip((DataPc *)(iVar6 + 0xeac64),bVar1);
      FUN_15012a2c(param_1 + 0x968,uVar5);
      FUN_1501580c(msys::MComSys::_sys + 0x49368,0x110015,0,0,0);
      *(undefined1 *)(param_1 + 0x894) = *(undefined1 *)(param_1 + 0x874);
      FUN_150121ac(this);
      FUN_15012444(param_1 + 0x8bc,*(undefined1 *)(param_1 + 0x874));
      return;
    }
  }
  else {
    if (param_3 == 4) {
      FUN_1501580c(msys::MComSys::_sys + 0x49368,0x110016,0,0,0);
      iVar6 = msys::MComSys::_sys;
      iVar2 = *(int *)(param_1 + 8);
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar2 = iVar6;
      }
      *(undefined1 *)(iVar2 + 0xe6508) = 0;
      return;
    }
    if (param_3 == 5) {
      local_4c[0] = (LytAnim)0x0;
      local_48 = 0;
      local_44 = 0x3f800000;
      local_40 = 0;
      local_3c = 1;
      local_3a = 0;
      local_38 = 0;
      local_34 = 0;
      ad::lyt::LytAnim::init(local_4c,*(Layout **)(param_1 + 0x608),"SET_TAB_EQUIP","");
      fVar8 = (float)VectorUnsignedToFloat((uint)(uVar3 != 0),(byte)(in_fpscr >> 0x16) & 3);
      ad::lyt::LytAnim::stopAndSetFrm(local_4c,fVar8);
      if (uVar3 != 0) {
        (**(code **)(**(int **)(param_1 + 0x44ea4) + 0x18))();
        (**(code **)(**(int **)(param_1 + 0x44ea8) + 0x18))();
        (**(code **)(**(int **)(param_1 + uVar3 * 4 + 0x44ea0) + 0x20))();
      }
      msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x110),1,0,(char *)0x0,(char *)0x0);
      msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x4b8),1,0,(char *)0x0,(char *)0x0);
      *(undefined1 *)(param_1 + 0x44fed) = 1;
      *(byte *)(*(int *)(param_1 + 0x32c04) + 0x44) =
           *(byte *)(*(int *)(param_1 + 0x32c04) + 0x44) & 0xfe;
      *(undefined2 *)(param_1 + 0x4dc9a) = 0xffff;
      *(undefined2 *)(param_1 + 0x4dc9c) = 0xffff;
      FUN_150124a8(param_1 + 0x44eac,*(undefined1 *)(param_1 + 0x875),
                   *(undefined1 *)(param_1 + 0x875),*(undefined1 *)(param_1 + 0x874),1);
      FUN_15012af4(param_1,*(undefined1 *)(param_1 + 0x875),0);
      (**(code **)(**(int **)(param_1 + 0x860) + 0x28))(*(int **)(param_1 + 0x860),1);
      uVar3 = 0;
      *(undefined4 *)(*(int *)(param_1 + 0x860) + 0x48) = 1;
      do {
        piVar4 = *(int **)(param_1 + uVar3 * 4 + 0x44e84);
        (**(code **)(*piVar4 + 0x28))(piVar4,0);
        uVar3 = uVar3 + 1 & 0xff;
      } while (uVar3 < 2);
      uVar3 = 0;
      do {
        piVar4 = *(int **)(param_1 + uVar3 * 4 + 0x44e8c);
        (**(code **)(*piVar4 + 0x28))(piVar4,0);
        uVar3 = uVar3 + 1 & 0xff;
      } while (uVar3 < 3);
      uVar3 = 0;
      do {
        piVar4 = *(int **)(param_1 + uVar3 * 4 + 0x44e98);
        (**(code **)(*piVar4 + 0x28))(piVar4,0);
        uVar3 = uVar3 + 1 & 0xff;
      } while (uVar3 < 3);
      uVar3 = 0;
      uVar5 = extraout_r1;
      do {
        bVar7 = *(char *)(param_1 + 0x874) != '\0';
        if (bVar7) {
          uVar5 = 1;
        }
        piVar4 = *(int **)(param_1 + uVar3 * 4 + 0x44ea4);
        if (!bVar7) {
          uVar5 = 0;
        }
        (**(code **)(*piVar4 + 0x28))(piVar4,uVar5);
        uVar3 = uVar3 + 1 & 0xff;
        uVar5 = extraout_r1_00;
      } while (uVar3 < 2);
      FUN_15012444(param_1 + 0x8bc,*(undefined1 *)(param_1 + 0x874));
      msys::MCursorBase::setVisible(this,false);
      FUN_150121ac(this);
      *(code **)(param_1 + 0x20) = FUN_1500d700;
      *(undefined4 *)(param_1 + 0x24) = 0;
    }
  }
  return;
}


// FUNC 0x1500ad54 FUN_1500ad54 (MainMenu)
//   size 0xdc | file MainMenu+0xad54 | callers(0) | datarefs 1

void FUN_1500ad54(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  char cVar3;
  
  if (param_3 == 4) {
    FUN_1501580c(msys::MComSys::_sys + 0x49368,0x110016,0,0,0);
    iVar2 = msys::MComSys::_sys;
    iVar1 = *(int *)(param_4 + 8);
    if (*(int *)(param_4 + 8) == 0) {
      *(int *)(param_4 + 8) = msys::MComSys::_sys;
      iVar1 = iVar2;
    }
    *(undefined1 *)(iVar1 + 0xe6508) = 0;
                    /* WARNING: Could not recover jumptable at 0x1500ae2c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(param_4 + *(char *)(param_4 + 0x874) * 4 + 0x44ea0) + 0x18))();
    return;
  }
  if (param_3 == 5) {
    cVar3 = *(char *)(param_1 + 0x48) + '\x01';
    FUN_150124a8(param_4 + 0x44eac,*(undefined1 *)(param_4 + 0x875),*(undefined1 *)(param_4 + 0x875)
                 ,cVar3,0);
    *(char *)(param_4 + 0x874) = cVar3;
    FUN_15012444(param_4 + 0x8bc,cVar3);
    iVar2 = msys::MComSys::_sys;
    iVar1 = *(int *)(param_4 + 8);
    if (*(int *)(param_4 + 8) == 0) {
      *(int *)(param_4 + 8) = msys::MComSys::_sys;
      iVar1 = iVar2;
    }
    *(undefined1 *)(iVar1 + 0xe6508) = 1;
  }
  return;
}


// FUNC 0x1500ae40 FUN_1500ae40 (MainMenu)
//   size 0x60c | file MainMenu+0xae40 | callers(1) 0x150124a8

int FUN_1500ae40(int param_1,uint param_2,int param_3,uint param_4)

{
  bool bVar1;
  undefined1 uVar2;
  byte bVar3;
  DataPc *this;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  ushort *puVar13;
  int iVar14;
  byte bVar15;
  int local_58;
  undefined1 local_4c;
  
  iVar6 = msys::MComSys::_sys;
  iVar11 = *(int *)(*(int *)(param_1 + 0x8b80) + 8);
  if (iVar11 == 0) {
    *(int *)(*(int *)(param_1 + 0x8b80) + 8) = msys::MComSys::_sys;
    iVar11 = iVar6;
  }
  local_58 = 0;
  this = (DataPc *)(iVar11 + param_2 * 0xb0 + 0xeac64);
  if (0 < param_3) {
    *(undefined1 *)(*(int *)(param_1 + 0x8e08) + 0xb) = 0xff;
    *(undefined2 *)(*(int *)(param_1 + 0x8e08) + 4) = 0xffff;
    **(undefined4 **)(param_1 + 0x8e08) = 0;
    *(undefined1 *)(*(int *)(param_1 + 0x8e08) + 8) = 0xff;
    iVar11 = DataPc::getEquip(this,(uchar)param_3);
    *(bool *)(*(int *)(param_1 + 0x8e08) + 0xe) = iVar11 != 0;
    *(undefined1 *)(*(int *)(param_1 + 0x8e08) + 0xf) = 0;
    iVar6 = msys::MComSys::_sys;
    iVar11 = *(int *)(*(int *)(param_1 + 0x8b80) + 8);
    if (iVar11 == 0) {
      *(int *)(*(int *)(param_1 + 0x8b80) + 8) = msys::MComSys::_sys;
      iVar11 = iVar6;
    }
    uVar4 = LMS_GetTextIndexByLabel(iVar11 + 0xeae90,"Menu_Sys_rem_equip");
    uVar4 = LMS_GetText(iVar11 + 0xeae90,uVar4);
    local_58 = 1;
    *(undefined4 *)(*(int *)(param_1 + 0x8e08) + 0x10) = uVar4;
    *(undefined4 *)(*(int *)(param_1 + 0x8e08) + 0x14) = 0;
  }
  bVar3 = 0;
  do {
    puVar5 = (undefined4 *)ad::db::GetEquipIdList();
    puVar13 = (ushort *)*puVar5;
    iVar11 = ad::db::GetEquipIdList();
    if (*(ushort **)(iVar11 + 4) != puVar13) {
      do {
        iVar11 = GameWork::getItemNum((GameWork *)&gGameWork,*puVar13);
        if (iVar11 != 0) {
          iVar6 = ad::db::GetEquip(*puVar13);
          iVar14 = *(int *)(param_1 + 0x8b80);
          if (bVar3 == 0) {
            uVar7 = msys::GetEquipCheckedFlagNo(*puVar13);
            iVar8 = msys::MComSys::_sys;
            iVar12 = *(int *)(iVar14 + 8);
            if (*(int *)(iVar14 + 8) == 0) {
              *(int *)(iVar14 + 8) = msys::MComSys::_sys;
              iVar12 = iVar8;
            }
            if ((*(uint *)(iVar12 + (uVar7 >> 5) * 4 + 0xeaf60) >> (uVar7 & 0x1f) & 1) == 0)
            goto LAB_1500b024;
            goto LAB_1500b45c;
          }
          uVar7 = msys::GetEquipCheckedFlagNo(*puVar13);
          iVar8 = msys::MComSys::_sys;
          iVar12 = *(int *)(iVar14 + 8);
          if (iVar12 == 0) {
            *(int *)(iVar14 + 8) = msys::MComSys::_sys;
            iVar12 = iVar8;
          }
          if ((*(uint *)(iVar12 + (uVar7 >> 5) * 4 + 0xeaf60) >> (uVar7 & 0x1f) & 1) == 0)
          goto LAB_1500b45c;
LAB_1500b024:
          if (*(char *)(iVar6 + 0x6b) == '\0') {
            if (param_2 < 2) goto LAB_1500b05c;
            goto LAB_1500b45c;
          }
          if ((*(char *)(iVar6 + 0x6b) == '\x01') && (param_2 != 2)) goto LAB_1500b45c;
LAB_1500b05c:
          switch(*(undefined1 *)(iVar6 + 0x6a)) {
          case 0:
            uVar7 = param_4 & 1;
            break;
          case 1:
          case 2:
          case 3:
          case 4:
            uVar7 = param_4 & 0x1e;
            break;
          case 5:
            uVar7 = param_4 & 0x20;
            break;
          case 6:
          case 7:
          case 8:
            uVar7 = param_4 & 0x1c0;
            break;
          default:
            goto switchD_1500b064_default;
          }
          if (uVar7 != 0) {
switchD_1500b064_default:
            iVar14 = ad::db::GetEquip(*puVar13);
            local_4c = 1;
            *(char *)(*(int *)(param_1 + 0x8e08) + local_58 * 0x1c + 0xb) =
                 *(char *)(iVar14 + 0x60) + '\x01';
            uVar7 = 0;
            bVar1 = false;
            *(short *)(*(int *)(param_1 + 0x8e08) + local_58 * 0x1c + 4) = (short)iVar11;
            *(uint *)(*(int *)(param_1 + 0x8e08) + local_58 * 0x1c) = (uint)*puVar13;
            iVar8 = ad::db::GetEquip(*puVar13);
            if (*(char *)(iVar8 + 0x6b) == '\0') {
              if (1 < param_2) goto LAB_1500b16c;
            }
            else if ((*(char *)(iVar8 + 0x6b) == '\x01') && (param_2 != 2)) {
LAB_1500b16c:
              local_4c = 0;
            }
            uVar9 = (uint)*(byte *)(iVar6 + 0x6a);
            if ((uVar9 != 0 && uVar9 != 5) && ((1 << uVar9 & param_4) == 0)) {
              local_4c = 0;
            }
            iVar12 = *(int *)(param_1 + 0x8b80);
            uVar9 = msys::GetEquipCheckedFlagNo(*puVar13);
            iVar6 = msys::MComSys::_sys;
            iVar8 = *(int *)(iVar12 + 8);
            if (iVar8 == 0) {
              *(int *)(iVar12 + 8) = msys::MComSys::_sys;
              iVar8 = iVar6;
            }
            bVar15 = 0;
            if ((*(uint *)(iVar8 + (uVar9 >> 5) * 4 + 0xeaf60) >> (uVar9 & 0x1f) & 1) == 0) {
              bVar1 = true;
            }
            do {
              uVar9 = DataPc::getEquip(this,bVar15);
              if (uVar9 == *puVar13) {
                uVar7 = 1 << (param_2 & 0xff) & 0xffU | uVar7;
                local_4c = 0;
              }
              bVar15 = bVar15 + 1;
            } while (bVar15 < 3);
            iVar6 = GameWork::getItemNum((GameWork *)&gGameWork,*puVar13);
            uVar9 = 0;
            do {
              iVar8 = msys::MComSys::_sys;
              iVar12 = *(int *)(*(int *)(param_1 + 0x8b80) + 8);
              if (iVar12 == 0) {
                *(int *)(*(int *)(param_1 + 0x8b80) + 8) = msys::MComSys::_sys;
                iVar12 = iVar8;
              }
              bVar15 = 0;
              do {
                uVar10 = DataPc::getEquip((DataPc *)(iVar12 + uVar9 * 0xb0 + 0xeac64),bVar15);
                if (uVar10 == *puVar13) {
                  iVar6 = (int)(short)((short)iVar6 + -1);
                  uVar7 = 1 << uVar9 & 0xffU | uVar7;
                }
                bVar15 = bVar15 + 1;
              } while (bVar15 < 3);
              uVar9 = uVar9 + 1 & 0xff;
            } while (uVar9 < 3);
            if (iVar6 == 0) {
              local_4c = 0;
            }
            if (uVar7 == 0) {
              if (bVar1) {
                *(undefined1 *)(*(int *)(param_1 + 0x8e08) + local_58 * 0x1c + 8) = 0;
              }
              else {
LAB_1500b3b4:
                *(undefined1 *)(*(int *)(param_1 + 0x8e08) + local_58 * 0x1c + 8) = 0xff;
              }
            }
            else if (uVar7 == 1) {
              iVar6 = *(int *)(param_1 + 0x8e08);
              uVar2 = 1;
LAB_1500b384:
              *(undefined1 *)(iVar6 + local_58 * 0x1c + 8) = uVar2;
            }
            else if (uVar7 == 2) {
              *(undefined1 *)(*(int *)(param_1 + 0x8e08) + local_58 * 0x1c + 8) = 2;
            }
            else {
              if (uVar7 != 3) {
                if (uVar7 != 4) goto LAB_1500b3b4;
                iVar6 = *(int *)(param_1 + 0x8e08);
                uVar2 = 4;
                goto LAB_1500b384;
              }
              *(undefined1 *)(*(int *)(param_1 + 0x8e08) + local_58 * 0x1c + 8) = 3;
            }
            *(undefined1 *)(*(int *)(param_1 + 0x8e08) + local_58 * 0x1c + 0xe) = local_4c;
            *(undefined1 *)(*(int *)(param_1 + 0x8e08) + local_58 * 0x1c + 0xf) = 0;
            iVar6 = ad::db::GetItemMsgAcs();
            if (iVar11 != 1) {
              iVar14 = iVar14 + 0x18;
            }
            uVar4 = LMS_GetTextIndexByLabel(iVar6 + 8,iVar14);
            uVar4 = LMS_GetText(iVar6 + 8,uVar4);
            iVar11 = local_58 * 0x1c;
            *(undefined4 *)(*(int *)(param_1 + 0x8e08) + local_58 * 0x1c + 0x10) = uVar4;
            local_58 = (int)(short)((short)local_58 + 1);
            *(undefined4 *)(*(int *)(param_1 + 0x8e08) + iVar11 + 0x14) = 0;
          }
        }
LAB_1500b45c:
        puVar13 = puVar13 + 1;
        iVar11 = ad::db::GetEquipIdList();
      } while (*(ushort **)(iVar11 + 4) != puVar13);
    }
    bVar3 = bVar3 + 1;
    if (1 < bVar3) {
      return local_58;
    }
  } while( true );
}


// FUNC 0x1500b494 FUN_1500b494 (MainMenu)
//   size 0x414 | file MainMenu+0xb494 | callers(1) 0x15009a64

void FUN_1500b494(MListWndPBase *param_1,LytResourceMan *param_2,undefined4 param_3,int param_4)

{
  Resource *this;
  void *pvVar1;
  undefined4 *puVar2;
  void *pvVar3;
  LytAnim *this_00;
  LytAnim *this_01;
  int *piVar4;
  int iVar5;
  Layout *pLVar6;
  Layout *pLVar7;
  int iVar8;
  LytAnim local_1f8 [4];
  undefined4 local_1f4;
  undefined4 uStack_1f0;
  undefined4 local_1ec;
  undefined2 local_1e8;
  undefined2 local_1e6;
  undefined4 local_1e4;
  undefined4 local_1e0;
  LytAnim *local_1dc;
  int local_1d8 [2];
  CellAnime *local_1d0;
  int local_1c4;
  undefined4 local_1b8;
  undefined4 local_1ac;
  undefined4 local_1a8;
  undefined4 local_1a0;
  LytAnim *local_19c;
  LytAnim *local_188;
  LytAnim *local_184;
  LytAnim *local_180;
  LytAnim *local_17c;
  LytAnim *local_178;
  undefined1 local_170;
  undefined4 local_9c;
  undefined1 local_98;
  LytLocalize aLStack_60 [32];
  LytAnim *local_40;
  LytAnim *local_3c;
  CellAnime *local_38;
  LytAnim *local_34;
  
  this = (Resource *)(param_4 + 0x836c);
  pvVar1 = (void *)ad::fw::Resource::getCA_anm(this);
  puVar2 = (undefined4 *)ad::fw::Resource::getCA_tex(this);
  pvVar3 = (void *)ad::fw::Resource::getCA_canm(this);
  local_38 = (CellAnime *)(param_1 + 0x8cc0);
  CellAnime::init(local_38,pvVar1,(void *)*puVar2,pvVar3,'\0',0,1.0);
  param_1[0x8d63] = (MListWndPBase)((byte)param_1[0x8d63] | 3);
  *(undefined2 *)(param_1 + 0x8dec) = 0;
  Mem::Fill(param_1 + 0x8dee,0,4);
  Mem::Fill(param_1 + 0x8df2,0,4);
  pLVar6 = (Layout *)(param_1 + 0x8b84);
  ad::lyt::LytResourceMan::buildLayout
            (param_2,pLVar6,"MENU_EQUIP_L_LIST.bflyt",(ControlCreator *)0x0,(TextSearcher *)0x0);
  ad::lyt::LytLocalize::LytLocalize(aLStack_60);
  ad::lyt::LytLocalize::localize(aLStack_60,pLVar6);
  this_00 = (LytAnim *)(param_1 + 0x8bc0);
  ad::lyt::LytAnim::init(this_00,pLVar6,"touch","");
  pLVar7 = (Layout *)(param_1 + 0x8bf8);
  ad::lyt::LytResourceMan::buildLayout
            (param_2,pLVar7,"NUM_G_s.bflyt",(ControlCreator *)0x0,(TextSearcher *)0x0);
  local_3c = (LytAnim *)(param_1 + 0x8c34);
  ad::lyt::LytAnim::init(local_3c,pLVar7,"num_set_U","");
  local_40 = (LytAnim *)(param_1 + 0x8c50);
  ad::lyt::LytAnim::init(local_40,pLVar7,"col_00","");
  local_1dc = (LytAnim *)(param_1 + 0x8c6c);
  ad::lyt::LytAnim::init(local_1dc,pLVar7,"col_s06","");
  this_01 = (LytAnim *)(param_1 + 0x8bdc);
  ad::lyt::LytAnim::init(this_01,pLVar6,"ATTENTION","");
  ad::lyt::LytAnim::playAuto(this_01,1.0);
  local_1f8[0] = (LytAnim)0x0;
  local_1f4 = 0;
  uStack_1f0 = 0x3f800000;
  local_1ec = 0;
  local_1e8 = 1;
  local_1e6 = 0;
  local_1e4 = 0;
  local_1e0 = 0;
  ad::lyt::LytAnim::init(local_1f8,pLVar6,"ICON_OnOff","");
  ad::lyt::LytAnim::stopAndSetFrm(local_1f8,0.0);
  ad::lyt::LytAnim::term(local_1f8,true);
  ad::lyt::LytAnim::init
            ((LytAnim *)(param_1 + 0x8ca4),*(Layout **)(param_4 + 0x260),"EXP_PANEL_ON","EXP_PNL_U")
  ;
  local_34 = (LytAnim *)(param_1 + 0x8c88);
  ad::lyt::LytAnim::init(local_34,pLVar6,"SET_ICON","");
  *(int *)(param_1 + 0x8b80) = param_4;
  piVar4 = (int *)ad::db::GetEquipIdList();
  iVar8 = (piVar4[1] - *piVar4 >> 1) + 1;
  *(int *)(param_1 + 0x8e04) = iVar8;
  pvVar1 = operator_new__(iVar8 * 0x1c,*(MemAlcBase **)(*(int *)(param_4 + 4) + 0x18),(char *)0x0,0)
  ;
  *(void **)(param_1 + 0x8e08) = pvVar1;
  if ((void *)((int)pvVar1 + *(int *)(param_1 + 0x8e04) * 0x1c) != pvVar1) {
    do {
      *(undefined1 *)((int)pvVar1 + 8) = 0xff;
      *(undefined1 *)((int)pvVar1 + 0xf) = 0;
      *(undefined4 *)((int)pvVar1 + 0x14) = 0;
      pvVar1 = (void *)((int)pvVar1 + 0x1c);
    } while ((void *)(*(int *)(param_1 + 0x8e08) + *(int *)(param_1 + 0x8e04) * 0x1c) != pvVar1);
  }
  iVar8 = msys::MComSys::_sys;
  iVar5 = *(int *)(param_4 + 8);
  if (*(int *)(param_4 + 8) == 0) {
    *(int *)(param_4 + 8) = msys::MComSys::_sys;
    iVar5 = iVar8;
  }
  ad::ui::UIListWindowPlusLyt::InitParam::InitParam((InitParam *)local_1d8);
  msys::SetMListWndInitParam(local_1d8,0);
  local_1d8[0] = iVar5 + 0x4af6c;
  local_1a0 = (**(code **)(**(int **)(param_1 + 0x8b94) + 0x2c))
                        (*(int **)(param_1 + 0x8b94),"FRAME",1);
  local_1d0 = local_38;
  local_1c4 = (**(code **)(**(int **)(param_1 + 0x8b94) + 0x2c))
                        (*(int **)(param_1 + 0x8b94),"ICONL",1);
  *(byte *)(local_1c4 + 0x44) = *(byte *)(local_1c4 + 0x44) & 0xfe | 1;
  local_19c = local_34;
  local_1b8 = *(undefined4 *)(param_1 + 0x8c08);
  local_188 = local_3c;
  local_184 = local_40;
  local_180 = local_1dc;
  local_1a8 = (**(code **)(**(int **)(param_1 + 0x8b94) + 0x2c))
                        (*(int **)(param_1 + 0x8b94),"list_cursor",1);
  local_170 = 0;
  local_1ac = (**(code **)(**(int **)(param_1 + 0x8b94) + 0x2c))
                        (*(int **)(param_1 + 0x8b94),"list_scroll",1);
  local_9c = *(undefined4 *)(param_1 + 0x8e08);
  local_98 = 0;
  local_17c = this_00;
  local_178 = this_01;
  msys::MListWndPBase::init
            (param_1,(InitParam *)local_1d8,(LytDrawData *)(iVar5 + 0xd3000),
             (Prim *)(iVar5 + 0xd3100),(MessageDrawer *)(iVar5 + 0x1487c),
             (ApplyingSceneInfo *)(iVar5 + 0x4af54));
  *(undefined4 *)(param_1 + 0x13c) = 0x401;
  *(undefined2 *)(param_1 + 0x8dee) = 0xffff;
  *(undefined2 *)(param_1 + 0x8df0) = 0xffff;
  *(undefined4 *)(param_1 + 0x168) = 0x401;
  return;
}


// FUNC 0x1500b978 main_menu::MainMenu_EquipPage::Core::MListWndEquip::vfunc_0x4 (MainMenu)
//   size 0x10 | file MainMenu+0xb978 | callers(0) | datarefs 1

void main_menu::MainMenu_EquipPage::Core::MListWndEquip::vfunc_0x4(void)

{
  void *pvVar1;
  
  pvVar1 = (void *)vfunc_0x0();
  operator_delete(pvVar1);
  return;
}


// FUNC 0x1500b988 FUN_1500b988 (MainMenu)
//   size 0x208 | file MainMenu+0xb988 | callers(1) 0x1500c370

void FUN_1500b988(int param_1)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  LytLocalize aLStack_38 [16];
  undefined4 local_28;
  
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  ad::lyt::LytLocalize::LytLocalize(aLStack_38);
  ad::lyt::LytLocalize::localize(aLStack_38,*(Layout **)(param_1 + 0x260));
  ad::lyt::LytLocalize::localize(aLStack_38,*(Layout **)(param_1 + 0x608));
  local_28 = 0;
  piVar4 = (int *)(*(int *)(param_1 + 4) + 4);
  puVar6 = *(undefined4 **)(param_1 + 0x118);
  *(undefined4 **)(*(int *)(param_1 + 0x114) + 4) = puVar6;
  *puVar6 = *(undefined4 *)(param_1 + 0x114);
  piVar2 = (int *)(param_1 + 0x114);
  if (piVar2 != (int *)0x0) {
    iVar5 = *piVar4;
    *(int **)(param_1 + 0x118) = piVar4;
    *piVar2 = iVar5;
    *(int **)(iVar5 + 4) = piVar2;
    *piVar4 = (int)piVar2;
  }
  *(undefined4 *)(param_1 + 0x24c) = 0x400;
  piVar4 = (int *)(*(int *)(param_1 + 4) + 0xc);
  puVar6 = *(undefined4 **)(param_1 + 0x4c0);
  *(undefined4 **)(*(int *)(param_1 + 0x4bc) + 4) = puVar6;
  *puVar6 = *(undefined4 *)(param_1 + 0x4bc);
  piVar2 = (int *)(param_1 + 0x4bc);
  if (piVar2 != (int *)0x0) {
    iVar5 = *piVar4;
    *(int **)(param_1 + 0x4c0) = piVar4;
    *piVar2 = iVar5;
    *(int **)(iVar5 + 4) = piVar2;
    *piVar4 = (int)piVar2;
  }
  *(undefined4 *)(param_1 + 0x5f4) = 0x401;
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x110),3,0,"EXP_PNL_U",(char *)0x0);
  uVar1 = (uint)(byte)DAT_003fbea4;
  if (uVar1 != 2) {
    uVar1 = 0;
  }
  *(char *)(param_1 + 0x875) = (char)uVar1;
  iVar3 = *(int *)(param_1 + 8);
  iVar5 = iVar3;
  if (iVar3 == 0) {
    iVar5 = msys::MComSys::_sys;
  }
  if (iVar3 == 0) {
    *(int *)(param_1 + 8) = iVar5;
  }
  iVar5 = DataPc::getEquip((DataPc *)(iVar5 + uVar1 * 0xb0 + 0xeac64),*(uchar *)(param_1 + 0x874));
  if (iVar5 == 0) {
    msys::MLyt::stopAnimeAndSetEnd((MLyt *)(param_1 + 0x110),2,1,"EXP_PNL_U",(char *)0x0);
    *(byte *)(*(int *)(param_1 + 0x75b0) + 0x44) =
         *(byte *)(*(int *)(param_1 + 0x75b0) + 0x44) & 0xfe;
  }
  else {
    msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x110),2,1,"EXP_PNL_U",(char *)0x0);
  }
  FUN_15012a2c(param_1 + 0x968,iVar5);
  msys::MLyt::stopAnimeAndSetSt((MLyt *)(param_1 + 0x110),0,0,(char *)0x0,(char *)0x0);
  msys::MLyt::stopAnimeAndSetSt((MLyt *)(param_1 + 0x4b8),0,0,(char *)0x0,(char *)0x0);
  *(undefined1 *)(param_1 + 0x894) = *(undefined1 *)(param_1 + 0x874);
  msys::MCursorBase::setVisible((MCursorBase *)(param_1 + 0x87c),false);
  FUN_15012444(param_1 + 0x8bc,*(undefined1 *)(param_1 + 0x874));
  FUN_15012af4(param_1,*(undefined1 *)(param_1 + 0x875),0);
  *(undefined1 **)(param_1 + 0x10) = &LAB_1500c654;
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}


// FUNC 0x1500bbb8 main_menu::MainMenu_EquipPage::Core::vfunc_0x10 (MainMenu)
//   size 0x2b0 | file MainMenu+0xbbb8 | callers(0) | datarefs 1

void main_menu::MainMenu_EquipPage::Core::vfunc_0x10(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  
  uVar5 = 0;
  if (param_2 == 4) {
    FUN_1501580c(msys::MComSys::_sys + 0x49368,0x110017,0,0,0);
    iVar2 = msys::MComSys::_sys;
    iVar3 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar3 = iVar2;
    }
    *(undefined1 *)(iVar3 + 0xe6508) = 0;
  }
  else if (param_2 == 5) {
    iVar3 = *(int *)(*(int *)(param_1 + 0x860) + 0x48);
    if (iVar3 == 0) {
      *(undefined1 *)(param_1 + 0x878) = 0;
      msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x4b8),0,1,(char *)0x0,(char *)0x0);
      msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x110),0,1,(char *)0x0,(char *)0x0);
      msys::MCursorBase::setVisible((MCursorBase *)(param_1 + 0x87c),false);
      if ((*(byte *)(*(int *)(param_1 + 0x75b0) + 0x44) & 1) != 0) {
        msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x110),2,0,"EXP_PNL_U",(char *)0x0);
      }
      *(code **)(param_1 + 0x20) = FUN_1500c5b4;
      *(undefined4 *)(param_1 + 0x24) = 0;
      return;
    }
    if (iVar3 == 1) {
      msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x110),1,1,(char *)0x0,(char *)0x0);
      msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x4b8),1,1,(char *)0x0,(char *)0x0);
      *(undefined1 *)(param_1 + 0x894) = *(undefined1 *)(param_1 + 0x874);
      FUN_15012444(param_1 + 0x8bc,*(undefined1 *)(param_1 + 0x874));
      (**(code **)(**(int **)(param_1 + 0x860) + 0x28))(*(int **)(param_1 + 0x860),1);
      *(undefined4 *)(*(int *)(param_1 + 0x860) + 0x48) = 0;
      do {
        piVar4 = *(int **)(param_1 + uVar5 * 4 + 0x44e84);
        (**(code **)(*piVar4 + 0x28))(piVar4,1);
        uVar5 = uVar5 + 1 & 0xff;
      } while (uVar5 < 2);
      uVar5 = 0;
      do {
        piVar4 = *(int **)(param_1 + uVar5 * 4 + 0x44e8c);
        (**(code **)(*piVar4 + 0x28))(piVar4,1);
        uVar5 = uVar5 + 1 & 0xff;
      } while (uVar5 < 3);
      uVar5 = 0;
      do {
        iVar3 = param_1 + uVar5 * 4;
        (**(code **)(**(int **)(iVar3 + 0x44e98) + 0x18))();
        piVar4 = *(int **)(iVar3 + 0x44e98);
        (**(code **)(*piVar4 + 0x28))(piVar4,1);
        uVar5 = uVar5 + 1 & 0xff;
      } while (uVar5 < 3);
      uVar5 = 0;
      do {
        piVar4 = *(int **)(param_1 + uVar5 * 4 + 0x44ea4);
        (**(code **)(*piVar4 + 0x28))(piVar4,0);
        uVar5 = uVar5 + 1 & 0xff;
      } while (uVar5 < 2);
      cVar1 = *(char *)(param_1 + 0x875);
      if (cVar1 == '\0') {
        (**(code **)(**(int **)(param_1 + 0x44e9c) + 0x20))();
      }
      else if (cVar1 == '\x01') {
        (**(code **)(**(int **)(param_1 + 0x44e98) + 0x20))();
      }
      else if (cVar1 == '\x02') {
        (**(code **)(**(int **)(param_1 + 0x44ea0) + 0x20))();
      }
      FUN_15012af4(param_1,*(undefined1 *)(param_1 + 0x875),0);
      *(code **)(param_1 + 0x20) = FUN_1500d5fc;
      *(undefined4 *)(param_1 + 0x24) = 0;
      return;
    }
  }
  return;
}


// FUNC 0x1500be88 FUN_1500be88 (MainMenu)
//   size 0x68 | file MainMenu+0xbe88 | callers(0) | datarefs 1

void FUN_1500be88(int param_1)

{
  MComSys *pMVar1;
  int iVar2;
  MComSys *this;
  
  iVar2 = msys::MLyt::isBusyAnime((MLyt *)(param_1 + 0x4b8));
  if ((iVar2 == 0) &&
     (iVar2 = msys::MLyt::isBusyAnime((MLyt *)(param_1 + 0x110)), pMVar1 = msys::MComSys::_sys,
     iVar2 == 0)) {
    this = *(MComSys **)(param_1 + 8);
    if (*(MComSys **)(param_1 + 8) == (MComSys *)0x0) {
      *(MComSys **)(param_1 + 8) = msys::MComSys::_sys;
      this = pMVar1;
    }
    iVar2 = msys::MComSys::getNextPage(this);
    if (*(char *)(iVar2 + 0x14) != '\0') {
      *(undefined1 **)(param_1 + 0x18) = &LAB_1500d8ac;
      *(undefined4 *)(param_1 + 0x1c) = 0;
    }
  }
  return;
}


// FUNC 0x1500bef8 main_menu::MainMenu_EquipPage::Core::MovePnlNameBar::vfunc_0x8 (MainMenu)
//   size 0x1bc | file MainMenu+0xbef8 | callers(1) 0x15009ac0 | datarefs 1

void main_menu::MainMenu_EquipPage::Core::MovePnlNameBar::vfunc_0x8(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  undefined4 *puVar7;
  
  *(int *)(param_1 + 4) = param_2;
  msys::MCellAnime::init((MCellAnime *)(param_1 + 0x6cac),(Resource *)(param_2 + 0x836c));
  *(byte *)(param_1 + 0x6e9b) = *(byte *)(param_1 + 0x6e9b) | 3;
  msys::MListWndPBase::getListWnd((MListWndPBase *)(param_2 + 0x44eac));
  uVar3 = msys::MLyt::getPane((MLyt *)(param_2 + 0x110),"NAME_BAR",(char *)0x0,(char *)0x0);
  *(undefined4 *)(param_1 + 8) = uVar3;
  msys::MLyt::attachMChr
            ((MLyt *)(param_2 + 0x110),(MChrBase *)(param_1 + 0x6cac),"INS_ICON_OBJ",(char *)0x0,
             (char *)0x0,(char *)0x0);
  uVar3 = *(undefined4 *)(*(int *)(param_2 + 0x86c) + 0x18);
  *(undefined4 *)(param_1 + 0x6ca8) = 0x400;
  *(undefined4 *)(param_1 + 0x6c9c) = uVar3;
  *(undefined4 *)(param_1 + 0x6ca0) = 0;
  *(undefined4 *)(param_1 + 0x6ca4) = 0;
  MessageSimple::init((MessageSimple *)(param_1 + 0x1b4));
  FUN_150142ec(param_1 + 0x68);
  msys::MLyt::attachMChr
            ((MLyt *)(param_2 + 0x110),(MChrBase *)(param_1 + 0x68),"INS_list_text_top",(char *)0x0,
             (char *)0x0,(char *)0x0);
  MessageWriter::setFontColor((MessageWriter *)(param_1 + 0x1b4),0xe6e6e6ff,true);
  iVar1 = msys::MComSys::_sys;
  iVar6 = *(int *)(param_2 + 8);
  if (*(int *)(param_2 + 8) == 0) {
    *(int *)(param_2 + 8) = msys::MComSys::_sys;
    iVar6 = iVar1;
  }
  iVar2 = msys::MComSys::_sys;
  iVar1 = iVar6;
  if (iVar6 == 0) {
    *(int *)(param_2 + 8) = msys::MComSys::_sys;
    iVar1 = iVar2;
  }
  msys::MDfxChr::init((MDfxChr *)(param_1 + 0x6f28),
                      *(MemAlcBase **)(*(int *)(param_2 + 0x86c) + 0x18),
                      *(MDfxSys **)(iVar1 + 0xe64f0),(Scene *)(iVar6 + 0x4aaa0),0x400);
  MoveVBase::stop((MoveVBase *)(param_1 + 0x6f98));
  *(undefined4 *)(param_1 + 0x6fb4) = 0;
  *(undefined4 *)(param_1 + 0x6fb8) = 0;
  *(undefined4 *)(param_1 + 0x6fbc) = 0;
  *(undefined4 *)(param_1 + 0x6f9c) = *(undefined4 *)(param_1 + 0x6fb4);
  *(undefined4 *)(param_1 + 0x6fa0) = *(undefined4 *)(param_1 + 0x6fb8);
  *(undefined4 *)(param_1 + 0x6fa4) = 0;
  piVar5 = (int *)(*(int *)(param_2 + 0x86c) + 4);
  puVar7 = *(undefined4 **)(param_1 + 0x6f30);
  *(undefined4 **)(*(int *)(param_1 + 0x6f2c) + 4) = puVar7;
  *puVar7 = *(undefined4 *)(param_1 + 0x6f2c);
  piVar4 = (int *)(param_1 + 0x6f2c);
  if (piVar4 != (int *)0x0) {
    iVar6 = *piVar5;
    *(int **)(param_1 + 0x6f30) = piVar5;
    *piVar4 = iVar6;
    *(int **)(iVar6 + 4) = piVar4;
    *piVar5 = (int)piVar4;
  }
  *(undefined4 *)(param_1 + 0x7064) = 0x400;
  return;
}


// FUNC 0x1500c0e0 main_menu::MainMenu_EquipPage::Core::MovePnlNameBar::vfunc_0x10 (MainMenu)
//   size 0xb4 | file MainMenu+0xc0e0 | callers(0) | datarefs 1

void main_menu::MainMenu_EquipPage::Core::MovePnlNameBar::vfunc_0x10(int param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  
  uVar1 = MoveVBase::isBusy((MoveVBase *)(param_1 + 0xc));
  iVar6 = *(int *)(param_1 + 8);
  puVar2 = (undefined4 *)MoveVBase::update((MoveVBase *)(param_1 + 0xc),1.0);
  uVar4 = puVar2[1];
  uVar5 = puVar2[2];
  *(undefined4 *)(iVar6 + 0x1c) = *puVar2;
  *(undefined4 *)(iVar6 + 0x20) = uVar4;
  *(undefined4 *)(iVar6 + 0x24) = uVar5;
  *(byte *)(iVar6 + 0x44) = *(byte *)(iVar6 + 0x44) & 0xef | 0x10;
  *(undefined1 *)(*(int *)(param_1 + 4) + 0x82c) = 1;
  uVar3 = MoveVBase::isBusy((MoveVBase *)(param_1 + 0xc));
  if ((uVar1 & ~uVar3) == 0) {
    return;
  }
  uVar4 = *(undefined4 *)(param_1 + 0x10);
  uVar5 = *(undefined4 *)(param_1 + 0x14);
  MoveVBase::stop((MoveVBase *)(param_1 + 0x6ff4));
  *(undefined4 *)(param_1 + 0x7018) = 0x43340000;
  *(undefined4 *)(param_1 + 0x7010) = uVar4;
  *(undefined4 *)(param_1 + 0x7014) = uVar5;
  *(undefined4 *)(param_1 + 0x7000) = 0x43340000;
  *(undefined4 *)(param_1 + 0x6ff8) = uVar4;
  *(undefined4 *)(param_1 + 0x6ffc) = uVar5;
  msys::MDfxChr::playDfx((MDfxChr *)(param_1 + 0x6f28),0x13);
  return;
}


// FUNC 0x1500c19c main_menu::MainMenu_EquipPage::Core::MovePnlNameBar::vfunc_0xc (MainMenu)
//   size 0x60 | file MainMenu+0xc19c | callers(0) | datarefs 1

void main_menu::MainMenu_EquipPage::Core::MovePnlNameBar::vfunc_0xc(int param_1,int param_2)

{
  if (*(char *)(param_2 + 0xb) == -1) {
    *(undefined1 *)(param_1 + 0x6ded) = 0;
  }
  else {
    *(undefined1 *)(param_1 + 0x6ded) = 1;
    CellAnime::play((CellAnime *)(param_1 + 0x6df8),*(uchar *)(param_2 + 0xb),0,1.0);
  }
  msys::MMsg::playStr((MMsg *)(param_1 + 0x68),*(wchar_t **)(param_2 + 0x10),(InsParam *)0x0,false);
  return;
}


// FUNC 0x1500c200 main_menu::MainMenu_EquipPage::Core::MovePnlNameBar::vfunc_0x4 (MainMenu)
//   size 0x9c | file MainMenu+0xc200 | callers(0) | datarefs 1

void main_menu::MainMenu_EquipPage::Core::MovePnlNameBar::vfunc_0x4(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &vtable;
  iVar1 = msys::MDfxChr::~MDfxChr((MDfxChr *)(param_1 + 0x1bca));
  *(undefined ***)(iVar1 + -0x6f28) = &MoveNameBarBase::vtable;
  *(undefined ***)(iVar1 + -0x27c) = &msys::MCellAnime::vtable;
  iVar1 = CellAnime::~CellAnime((CellAnime *)(iVar1 + -0x130));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  *(undefined ***)(iVar1 + -0x6c44) = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar1 = MessageSimple::~MessageSimple((MessageSimple *)(iVar1 + -0x6af8));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  *(undefined ***)(iVar1 + -0x5c) = &vtable_for_5MoveVILj1EE;
  __aeabi_vec_dtor(iVar1 + -0x2c,MoveWorkF::~MoveWorkF,0x2c,1);
  iVar1 = MoveVBase::~MoveVBase((MoveVBase *)(iVar1 + -0x5c));
  operator_delete((void *)(iVar1 + -0xc));
  return;
}


// FUNC 0x1500c2b4 main_menu::MainMenu_EquipPage::Core::MovePnlNameBar::vfunc_0x0 (MainMenu)
//   size 0x98 | file MainMenu+0xc2b4 | callers(0) | datarefs 1

int main_menu::MainMenu_EquipPage::Core::MovePnlNameBar::vfunc_0x0(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &vtable;
  iVar1 = msys::MDfxChr::~MDfxChr((MDfxChr *)(param_1 + 0x1bca));
  *(undefined ***)(iVar1 + -0x6f28) = &MoveNameBarBase::vtable;
  *(undefined ***)(iVar1 + -0x27c) = &msys::MCellAnime::vtable;
  iVar1 = CellAnime::~CellAnime((CellAnime *)(iVar1 + -0x130));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  *(undefined ***)(iVar1 + -0x6c44) = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar1 = MessageSimple::~MessageSimple((MessageSimple *)(iVar1 + -0x6af8));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  *(undefined ***)(iVar1 + -0x5c) = &vtable_for_5MoveVILj1EE;
  __aeabi_vec_dtor(iVar1 + -0x2c,MoveWorkF::~MoveWorkF,0x2c,1);
  iVar1 = MoveVBase::~MoveVBase((MoveVBase *)(iVar1 + -0x5c));
  return iVar1 + -0xc;
}


// FUNC 0x1500c378 FUN_1500c378 (MainMenu)
//   size 0x80 | file MainMenu+0xc378 | callers(0)

void FUN_1500c378(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = 0;
  *param_1 = param_2;
  do {
    ad::lyt::LytAnim::init
              ((LytAnim *)(param_1 + iVar1 * 7 + 1),*(Layout **)(*param_1 + 0x260),"SET_COL",
               (char *)(&DAT_15036298)[iVar1]);
    ad::lyt::LytAnim::stopAndSetFrm((LytAnim *)(param_1 + iVar1 * 7 + 1),0.0);
    ad::lyt::LytAnim::init
              ((LytAnim *)(param_1 + iVar1 * 7 + 0x16),*(Layout **)(*param_1 + 0x608),"SET_COL",
               (char *)(&DAT_15036298)[iVar1]);
    ad::lyt::LytAnim::stopAndSetFrm((LytAnim *)(param_1 + iVar1 * 7 + 0x16),0.0);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 3);
  return;
}


// FUNC 0x1500c408 main_menu::MainMenu_EquipPage::Core::MoveNameBarBase::vfunc_0x8 (MainMenu)
//   size 0x38 | file MainMenu+0xc408 | callers(0) | datarefs 1

void main_menu::MainMenu_EquipPage::Core::MoveNameBarBase::vfunc_0x8(int param_1,int param_2)

{
  *(int *)(param_1 + 4) = param_2;
  msys::MCellAnime::init((MCellAnime *)(param_1 + 0x6cac),(Resource *)(param_2 + 0x836c));
  *(byte *)(param_1 + 0x6e9b) = *(byte *)(param_1 + 0x6e9b) | 3;
  return;
}


// FUNC 0x1500c440 main_menu::MainMenu_EquipPage::Core::MoveNameBarBase::vfunc_0x10 (MainMenu)
//   size 0x44 | file MainMenu+0xc440 | callers(0) | datarefs 2

void main_menu::MainMenu_EquipPage::Core::MoveNameBarBase::vfunc_0x10(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 8);
  puVar1 = (undefined4 *)MoveVBase::update((MoveVBase *)(param_1 + 0xc),1.0);
  uVar2 = puVar1[1];
  uVar3 = puVar1[2];
  *(undefined4 *)(iVar4 + 0x1c) = *puVar1;
  *(undefined4 *)(iVar4 + 0x20) = uVar2;
  *(undefined4 *)(iVar4 + 0x24) = uVar3;
  *(byte *)(iVar4 + 0x44) = *(byte *)(iVar4 + 0x44) & 0xef | 0x10;
  *(undefined1 *)(*(int *)(param_1 + 4) + 0x82c) = 1;
  return;
}


// FUNC 0x1500c488 main_menu::MainMenu_EquipPage::Core::MoveNameBarBase::vfunc_0x4 (MainMenu)
//   size 0x84 | file MainMenu+0xc488 | callers(0) | datarefs 1

void main_menu::MainMenu_EquipPage::Core::MoveNameBarBase::vfunc_0x4(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &vtable;
  param_1[0x1b2b] = &msys::MCellAnime::vtable;
  iVar1 = CellAnime::~CellAnime((CellAnime *)(param_1 + 0x1b7e));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  *(undefined ***)(iVar1 + -0x6c44) = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar1 = MessageSimple::~MessageSimple((MessageSimple *)(iVar1 + -0x6af8));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  *(undefined ***)(iVar1 + -0x5c) = &vtable_for_5MoveVILj1EE;
  __aeabi_vec_dtor(iVar1 + -0x2c,MoveWorkF::~MoveWorkF,0x2c,1);
  iVar1 = MoveVBase::~MoveVBase((MoveVBase *)(iVar1 + -0x5c));
  operator_delete((void *)(iVar1 + -0xc));
  return;
}


// FUNC 0x1500c520 main_menu::MainMenu_EquipPage::Core::MoveNameBarBase::vfunc_0x0 (MainMenu)
//   size 0x80 | file MainMenu+0xc520 | callers(0) | datarefs 1

int main_menu::MainMenu_EquipPage::Core::MoveNameBarBase::vfunc_0x0(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &vtable;
  param_1[0x1b2b] = &msys::MCellAnime::vtable;
  iVar1 = CellAnime::~CellAnime((CellAnime *)(param_1 + 0x1b7e));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  *(undefined ***)(iVar1 + -0x6c44) = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar1 = MessageSimple::~MessageSimple((MessageSimple *)(iVar1 + -0x6af8));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  *(undefined ***)(iVar1 + -0x5c) = &vtable_for_5MoveVILj1EE;
  __aeabi_vec_dtor(iVar1 + -0x2c,MoveWorkF::~MoveWorkF,0x2c,1);
  iVar1 = MoveVBase::~MoveVBase((MoveVBase *)(iVar1 + -0x5c));
  return iVar1 + -0xc;
}


// FUNC 0x1500c5b4 FUN_1500c5b4 (MainMenu)
//   size 0x94 | file MainMenu+0xc5b4 | callers(0) | datarefs 2

void FUN_1500c5b4(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = msys::MComSys::_sys;
  if (*(int *)(param_1 + 8) == 0) {
    *(undefined4 *)(param_1 + 8) = msys::MComSys::_sys;
  }
  iVar2 = *(int *)(param_1 + 8);
  if (*(float *)(iVar2 + 0x4ad44) <= *(float *)(iVar2 + 0x4ad40)) {
    if (iVar2 == 0) {
      *(undefined4 *)(param_1 + 8) = uVar1;
    }
    if (((*(float *)(*(int *)(param_1 + 8) + 0x4ad04) <= *(float *)(*(int *)(param_1 + 8) + 0x4ad00)
         ) && (iVar2 = msys::MLyt::isBusyAnime((MLyt *)(param_1 + 0x110)), iVar2 == 0)) &&
       (iVar2 = msys::MLyt::isBusyAnime((MLyt *)(param_1 + 0x4b8)), iVar2 == 0)) {
      *(undefined1 *)(param_1 + 0x865) = *(undefined1 *)(param_1 + 0x878);
    }
  }
  return;
}


// FUNC 0x1500c678 FUN_1500c678 (MainMenu)
//   size 0x334 | file MainMenu+0xc678 | callers(0) | datarefs 2

void FUN_1500c678(int param_1,uint *param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  
  if ((*param_2 & 0x401) != 0) {
    (**(code **)(**(int **)(param_1 + *(char *)(param_1 + 0x874) * 4 + 0x44e8c) + 0x10))();
    iVar2 = msys::MComSys::_sys;
    iVar3 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar3 = iVar2;
    }
    *(undefined1 *)(iVar3 + 0xe6508) = 0;
  }
  uVar6 = *param_2;
  if ((uVar6 & 0x802) == 0) {
    if ((uVar6 & 0xc0) != 0) {
      cVar1 = *(char *)(param_1 + 0x874);
      if ((uVar6 & 0x40) == 0) {
        uVar4 = (int)cVar1;
        if (((uVar6 & 0x80) != 0) && (uVar4 = (uint)(char)(cVar1 + '\x01'), 2 < (int)uVar4)) {
          uVar4 = 0;
        }
      }
      else {
        uVar4 = (uint)(char)(cVar1 + -1);
        if ((int)uVar4 < 0) {
          uVar4 = 2;
        }
      }
      if ((int)cVar1 != uVar4) {
        *(char *)(param_1 + 0x894) = (char)uVar4;
        *(char *)(param_1 + 0x874) = (char)uVar4;
        FUN_15012444(param_1 + 0x8bc,uVar4 & 0xff);
        iVar2 = msys::MComSys::_sys;
        iVar3 = *(int *)(param_1 + 8);
        if (*(int *)(param_1 + 8) == 0) {
          *(int *)(param_1 + 8) = msys::MComSys::_sys;
          iVar3 = iVar2;
        }
        uVar5 = DataPc::getEquip((DataPc *)
                                 (iVar3 + (uint)*(byte *)(param_1 + 0x875) * 0xb0 + 0xeac64),
                                 *(uchar *)(param_1 + 0x874));
        FUN_15012a2c(param_1 + 0x968,uVar5);
        FUN_1501580c(msys::MComSys::_sys + 0x49368,0x110015,0,0,0);
      }
      goto LAB_1500c9a0;
    }
    if ((uVar6 & 0x300) == 0) {
      if ((uVar6 & 0x30) == 0) goto LAB_1500c9a0;
      cVar1 = *(char *)(param_1 + 0x875);
      uVar4 = 0;
      if (DAT_150360dc != cVar1) {
        if (DAT_150360dd == cVar1) {
          uVar4 = 1;
        }
        else if (DAT_150360de == cVar1) {
          uVar4 = 2;
        }
        else {
          uVar4 = 3;
        }
      }
      if ((uVar6 & 0x20) == 0) {
        if (((uVar6 & 0x10) != 0) && (uVar4 = uVar4 + 1, 2 < uVar4)) {
          uVar4 = 0;
        }
      }
      else {
        uVar4 = uVar4 - 1;
        if ((int)uVar4 < 0) {
          uVar4 = 2;
        }
      }
      iVar3 = param_1 + uVar4 * 4;
      (**(code **)(**(int **)(iVar3 + 0x44e98) + 0x10))();
      (**(code **)(**(int **)(iVar3 + 0x44e98) + 0xc))();
      iVar3 = *(int *)(param_1 + 8);
      iVar2 = msys::MComSys::_sys;
      goto joined_r0x1500c8f0;
    }
    if ((uVar6 & 0x200) == 0) {
      if ((uVar6 & 0x100) != 0) {
        (**(code **)(**(int **)(param_1 + 0x44e88) + 0x10))();
        (**(code **)(**(int **)(param_1 + 0x44e88) + 0xc))();
        iVar2 = msys::MComSys::_sys;
        iVar3 = *(int *)(param_1 + 8);
        if (*(int *)(param_1 + 8) == 0) {
          *(int *)(param_1 + 8) = msys::MComSys::_sys;
          iVar3 = iVar2;
        }
        *(undefined1 *)(iVar3 + 0xe6508) = 0;
        iVar3 = *(int *)(param_1 + 8);
        goto joined_r0x1500c8d8;
      }
    }
    else {
      (**(code **)(**(int **)(param_1 + 0x44e84) + 0x10))();
      (**(code **)(**(int **)(param_1 + 0x44e84) + 0xc))();
      iVar2 = msys::MComSys::_sys;
      iVar3 = *(int *)(param_1 + 8);
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar3 = iVar2;
      }
      *(undefined1 *)(iVar3 + 0xe6508) = 0;
      iVar3 = *(int *)(param_1 + 8);
joined_r0x1500c8d8:
      iVar2 = msys::MComSys::_sys;
      if (iVar3 == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar3 = iVar2;
      }
      *(undefined1 *)(iVar3 + 0xe650a) = 1;
    }
    iVar3 = *(int *)(param_1 + 8);
    iVar2 = msys::MComSys::_sys;
  }
  else {
    if ((*(byte *)(*(int **)(param_1 + 0x860) + 2) & 4) == 0) {
      FUN_1501580c(msys::MComSys::_sys + 0x49368,0x110018,0,0,0);
      goto LAB_1500c9a0;
    }
    (**(code **)(**(int **)(param_1 + 0x860) + 0x10))();
    iVar3 = *(int *)(param_1 + 8);
    iVar2 = msys::MComSys::_sys;
  }
joined_r0x1500c8f0:
  msys::MComSys::_sys = iVar2;
  if (iVar3 == 0) {
    *(int *)(param_1 + 8) = iVar2;
    iVar3 = iVar2;
  }
  *(undefined1 *)(iVar3 + 0xe6508) = 0;
LAB_1500c9a0:
  FUN_150121ac(param_1 + 0x87c);
  return;
}


// FUNC 0x1500c9c8 FUN_1500c9c8 (MainMenu)
//   size 0x464 | file MainMenu+0xc9c8 | callers(0) | datarefs 2

void FUN_1500c9c8(int param_1)

{
  int iVar1;
  short sVar2;
  ushort uVar3;
  short sVar4;
  ushort uVar5;
  int iVar6;
  uint uVar7;
  undefined4 *puVar8;
  uint uVar9;
  MListWndPBase *this;
  ushort *puVar10;
  undefined2 *puVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  
  iVar6 = msys::MLyt::isBusyAnime((MLyt *)(param_1 + 0x110));
  if (((iVar6 != 0) || (iVar6 = MoveVBase::isBusy((MoveVBase *)(param_1 + 0x39d60)), iVar6 != 0)) ||
     (iVar6 = MoveVBase::isBusy((MoveVBase *)(param_1 + 0x32c08)), iVar6 != 0)) {
    uVar7 = MoveVBase::isBusy((MoveVBase *)(param_1 + 0x39d60));
    iVar6 = *(int *)(param_1 + 0x39d5c);
    puVar8 = (undefined4 *)MoveVBase::update((MoveVBase *)(param_1 + 0x39d60),1.0);
    uVar12 = puVar8[1];
    uVar13 = puVar8[2];
    *(undefined4 *)(iVar6 + 0x1c) = *puVar8;
    *(undefined4 *)(iVar6 + 0x20) = uVar12;
    *(undefined4 *)(iVar6 + 0x24) = uVar13;
    *(byte *)(iVar6 + 0x44) = *(byte *)(iVar6 + 0x44) & 0xef | 0x10;
    *(undefined1 *)(*(int *)(param_1 + 0x39d58) + 0x82c) = 1;
    uVar9 = MoveVBase::isBusy((MoveVBase *)(param_1 + 0x39d60));
    if ((uVar7 & ~uVar9) != 0) {
      uVar12 = *(undefined4 *)(param_1 + 0x39d64);
      uVar13 = *(undefined4 *)(param_1 + 0x39d68);
      MoveVBase::stop((MoveVBase *)(param_1 + 0x40d48));
      *(undefined4 *)(param_1 + 0x40d64) = uVar12;
      *(undefined4 *)(param_1 + 0x40d68) = uVar13;
      *(undefined4 *)(param_1 + 0x40d6c) = 0x43340000;
      *(undefined4 *)(param_1 + 0x40d4c) = uVar12;
      *(undefined4 *)(param_1 + 0x40d50) = uVar13;
      *(undefined4 *)(param_1 + 0x40d54) = 0x43340000;
      msys::MDfxChr::playDfx((MDfxChr *)(param_1 + 0x40c7c),0x13);
    }
    iVar6 = *(int *)(param_1 + 0x32c04);
    puVar8 = (undefined4 *)MoveVBase::update((MoveVBase *)(param_1 + 0x32c08),1.0);
    uVar12 = puVar8[1];
    uVar13 = puVar8[2];
    *(undefined4 *)(iVar6 + 0x1c) = *puVar8;
    *(undefined4 *)(iVar6 + 0x20) = uVar12;
    *(undefined4 *)(iVar6 + 0x24) = uVar13;
    *(byte *)(iVar6 + 0x44) = *(byte *)(iVar6 + 0x44) & 0xef | 0x10;
    *(undefined1 *)(*(int *)(param_1 + 0x32c00) + 0x82c) = 1;
    return;
  }
  FUN_1501580c(msys::MComSys::_sys + 0x49368,0x11001b,0,0,0);
  *(byte *)(*(int *)(param_1 + 0x32c04) + 0x44) =
       *(byte *)(*(int *)(param_1 + 0x32c04) + 0x44) & 0xfe;
  *(byte *)(*(int *)(param_1 + 0x39d5c) + 0x44) =
       *(byte *)(*(int *)(param_1 + 0x39d5c) + 0x44) & 0xfe;
  this = (MListWndPBase *)(param_1 + 0x44eac);
  iVar6 = msys::MListWndPBase::getListWnd(this);
  *(undefined1 *)(iVar6 + 0x6d79) = 1;
  msys::MListWndPBase::getListWnd(this);
  puVar10 = (ushort *)ad::ui::UIListWindowPlusLyt::getCurItem();
  iVar1 = msys::MComSys::_sys;
  uVar3 = *puVar10;
  iVar6 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar6 = iVar1;
  }
  DataPc::setEquip((DataPc *)(iVar6 + (uint)*(byte *)(param_1 + 0x875) * 0xb0 + 0xeac64),uVar3,
                   *(uchar *)(param_1 + 0x874));
  iVar1 = msys::MComSys::_sys;
  iVar6 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar6 = iVar1;
  }
  sVar2 = DataPc::getHpNow((DataPc *)(iVar6 + (uint)*(byte *)(param_1 + 0x875) * 0xb0 + 0xeac64));
  iVar1 = msys::MComSys::_sys;
  iVar6 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar6 = iVar1;
  }
  uVar3 = DataPc::getHpMax((DataPc *)(iVar6 + (uint)*(byte *)(param_1 + 0x875) * 0xb0 + 0xeac64));
  iVar1 = msys::MComSys::_sys;
  iVar6 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar6 = iVar1;
  }
  sVar4 = DataPc::getBpNow((DataPc *)(iVar6 + (uint)*(byte *)(param_1 + 0x875) * 0xb0 + 0xeac64));
  iVar1 = msys::MComSys::_sys;
  iVar6 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar6 = iVar1;
  }
  uVar5 = DataPc::getBpMax((DataPc *)(iVar6 + (uint)*(byte *)(param_1 + 0x875) * 0xb0 + 0xeac64));
  iVar6 = msys::MComSys::_sys;
  if ((short)uVar3 < sVar2) {
    iVar1 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar1 = iVar6;
    }
    DataPc::setHpNow((DataPc *)(iVar1 + (uint)*(byte *)(param_1 + 0x875) * 0xb0 + 0xeac64),uVar3);
  }
  iVar6 = msys::MComSys::_sys;
  if ((short)uVar5 < sVar4) {
    iVar1 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar1 = iVar6;
    }
    DataPc::setBpNow((DataPc *)(iVar1 + (uint)*(byte *)(param_1 + 0x875) * 0xb0 + 0xeac64),uVar5);
  }
  iVar1 = msys::MComSys::_sys;
  iVar6 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar6 = iVar1;
  }
  DataPc::write((DataPc *)(iVar6 + (uint)*(byte *)(param_1 + 0x875) * 0xb0 + 0xeac64),
                (DataPcPOD *)(&gGameWork + (uint)*(byte *)(param_1 + 0x875) * 0x34));
  iVar1 = msys::MComSys::_sys;
  iVar6 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar6 = iVar1;
  }
  msys::StatusPanel::setParam
            ((StatusPanel *)(param_1 + 0x40df8),
             (DataPc *)(iVar6 + (uint)*(byte *)(param_1 + 0x875) * 0xb0 + 0xeac64));
  iVar1 = msys::MComSys::_sys;
  iVar6 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar6 = iVar1;
  }
  msys::StatusPanel::setParam
            ((StatusPanel *)(param_1 + 0x42e2c),
             (DataPc *)(iVar6 + (uint)*(byte *)(param_1 + 0x875) * 0xb0 + 0xeac64));
  msys::MListWndPBase::getListWnd(this);
  puVar11 = (undefined2 *)ad::ui::UIListWindowPlusLyt::getCurItem();
  FUN_1501204c(param_1 + (short)*(char *)(param_1 + 0x874) * 0x6ec4 + 0x9364,*puVar11);
  FUN_1501204c(param_1 + (short)*(char *)(param_1 + 0x874) * 0x6ec4 + 0x1dfb0,*puVar11);
  FUN_150124a8(this,*(undefined1 *)(param_1 + 0x875),*(undefined1 *)(param_1 + 0x875),
               *(undefined1 *)(param_1 + 0x874),0);
  iVar1 = msys::MComSys::_sys;
  iVar6 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar6 = iVar1;
  }
  *(undefined1 *)(iVar6 + 0xe6508) = 1;
  iVar1 = msys::MComSys::_sys;
  iVar6 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar6 = iVar1;
  }
  *(undefined1 *)(iVar6 + 0xe650a) = 1;
  *(code **)(param_1 + 0x20) = FUN_1500d000;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


// FUNC 0x1500ce58 FUN_1500ce58 (MainMenu)
//   size 0x1a4 | file MainMenu+0xce58 | callers(0) | datarefs 1

void FUN_1500ce58(int param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = 0;
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x110),0,0,(char *)0x0,(char *)0x0);
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x4b8),0,0,(char *)0x0,(char *)0x0);
  FUN_15012444(param_1 + 0x8bc,*(undefined1 *)(param_1 + 0x874));
  (**(code **)(**(int **)(param_1 + 0x860) + 0x28))(*(int **)(param_1 + 0x860),1);
  *(undefined4 *)(*(int *)(param_1 + 0x860) + 0x48) = 0;
  do {
    piVar2 = *(int **)(param_1 + uVar4 * 4 + 0x44e84);
    (**(code **)(*piVar2 + 0x28))(piVar2,1);
    uVar4 = uVar4 + 1 & 0xff;
  } while (uVar4 < 2);
  uVar4 = 0;
  do {
    piVar2 = *(int **)(param_1 + uVar4 * 4 + 0x44e8c);
    (**(code **)(*piVar2 + 0x28))(piVar2,1);
    uVar4 = uVar4 + 1 & 0xff;
  } while (uVar4 < 3);
  uVar4 = 0;
  do {
    iVar3 = param_1 + uVar4 * 4;
    (**(code **)(**(int **)(iVar3 + 0x44e98) + 0x18))();
    piVar2 = *(int **)(iVar3 + 0x44e98);
    (**(code **)(*piVar2 + 0x28))(piVar2,1);
    uVar4 = uVar4 + 1 & 0xff;
  } while (uVar4 < 3);
  uVar4 = 0;
  do {
    piVar2 = *(int **)(param_1 + uVar4 * 4 + 0x44ea4);
    (**(code **)(*piVar2 + 0x28))(piVar2,0);
    uVar4 = uVar4 + 1 & 0xff;
  } while (uVar4 < 2);
  cVar1 = *(char *)(param_1 + 0x875);
  if (cVar1 == '\0') {
    (**(code **)(**(int **)(param_1 + 0x44e9c) + 0x20))();
  }
  else if (cVar1 == '\x01') {
    (**(code **)(**(int **)(param_1 + 0x44e98) + 0x20))();
  }
  else if (cVar1 == '\x02') {
    (**(code **)(**(int **)(param_1 + 0x44ea0) + 0x20))();
  }
  *(code **)(param_1 + 0x20) = FUN_1500d5fc;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


// FUNC 0x1500d000 FUN_1500d000 (MainMenu)
//   size 0x5cc | file MainMenu+0xd000 | callers(0) | datarefs 4

void FUN_1500d000(int param_1,uint *param_2)

{
  char cVar1;
  MListWndPBase *this;
  int iVar2;
  UIListWindowPlusLyt *this_00;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  undefined2 *puVar6;
  undefined4 uVar7;
  uint uVar8;
  undefined4 uVar9;
  undefined1 uVar10;
  undefined8 uVar11;
  float fVar12;
  
  this = (MListWndPBase *)(param_1 + 0x44eac);
  iVar2 = msys::MListWndPBase::getSelectItem(this);
  uVar10 = 1;
  if ((iVar2 != 0) &&
     (iVar2 = msys::MListWndPBase::getSelectItem(this), *(char *)(iVar2 + 0xe) != '\0')) {
    FUN_1501580c(msys::MComSys::_sys + 0x49368,0x110016,0,0,0);
    iVar5 = msys::MComSys::_sys;
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar5;
    }
    *(undefined1 *)(iVar2 + 0xe6508) = 0;
    this_00 = (UIListWindowPlusLyt *)msys::MListWndPBase::getListWnd(this);
    uVar11 = ad::ui::UIListWindowPlusLyt::getCurPos(this_00);
    msys::MLyt::getPane((MLyt *)(param_1 + 0x110),"ALL",
                        *(char **)(&DAT_1503628c + *(char *)(param_1 + 0x874) * 4),(char *)0x0);
    MoveVBase::stop((MoveVBase *)(param_1 + 0x32c08));
    *(undefined8 *)(param_1 + 0x32c24) = uVar11;
    *(undefined4 *)(param_1 + 0x32c2c) = 0;
    *(undefined8 *)(param_1 + 0x32c0c) = uVar11;
    *(undefined4 *)(param_1 + 0x32c14) = 0;
    iVar2 = *(int *)(param_1 + 0x32c04);
    puVar3 = (undefined4 *)MoveVBase::update((MoveVBase *)(param_1 + 0x32c08),1.0);
    uVar7 = puVar3[1];
    uVar9 = puVar3[2];
    *(undefined4 *)(iVar2 + 0x1c) = *puVar3;
    *(undefined4 *)(iVar2 + 0x20) = uVar7;
    *(undefined4 *)(iVar2 + 0x24) = uVar9;
    fVar12 = (float)((ulonglong)uVar11 >> 0x20) - 240.0;
    *(byte *)(iVar2 + 0x44) = *(byte *)(iVar2 + 0x44) & 0xef | 0x10;
    *(undefined1 *)(*(int *)(param_1 + 0x32c00) + 0x82c) = 1;
    *(byte *)(*(int *)(param_1 + 0x32c04) + 0x44) =
         *(byte *)(*(int *)(param_1 + 0x32c04) + 0x44) & 0xfe | 1;
    MoveVBase::stop((MoveVBase *)(param_1 + 0x39d60));
    *(int *)(param_1 + 0x39d7c) = (int)uVar11;
    *(float *)(param_1 + 0x39d80) = fVar12;
    *(undefined4 *)(param_1 + 0x39d84) = 0;
    *(int *)(param_1 + 0x39d64) = (int)uVar11;
    *(float *)(param_1 + 0x39d68) = fVar12;
    *(undefined4 *)(param_1 + 0x39d6c) = 0;
    iVar2 = *(int *)(param_1 + 0x39d5c);
    puVar3 = (undefined4 *)MoveVBase::update((MoveVBase *)(param_1 + 0x39d60),1.0);
    uVar7 = puVar3[1];
    uVar9 = puVar3[2];
    *(undefined4 *)(iVar2 + 0x1c) = *puVar3;
    *(undefined4 *)(iVar2 + 0x20) = uVar7;
    *(undefined4 *)(iVar2 + 0x24) = uVar9;
    *(byte *)(iVar2 + 0x44) = *(byte *)(iVar2 + 0x44) & 0xef | 0x10;
    *(undefined1 *)(*(int *)(param_1 + 0x39d58) + 0x82c) = 1;
    *(byte *)(*(int *)(param_1 + 0x39d5c) + 0x44) =
         *(byte *)(*(int *)(param_1 + 0x39d5c) + 0x44) & 0xfe | 1;
    MoveVBase::moveSinAbs((VEC3 *)(param_1 + 0x32c08),16.0);
    MoveVBase::moveSinAbs((VEC3 *)(param_1 + 0x39d60),16.0);
    piVar4 = (int *)msys::MListWndPBase::getSelectItem(this);
    *(undefined1 *)(param_1 + 0x39c65) = 1;
    ad::lyt::LytNumReel3::setValueInstant
              ((LytNumReel3 *)(param_1 + 0x39c74),(uint)*(ushort *)(piVar4 + 1));
    msys::MMsg::playStr((MMsg *)(param_1 + 0x32c64),(wchar_t *)piVar4[4],(InsParam *)0x0,false);
    if (*(char *)((int)piVar4 + 0xb) == -1) {
      *(undefined1 *)(param_1 + 0x399e9) = 0;
    }
    else {
      *(undefined1 *)(param_1 + 0x399e9) = 1;
      CellAnime::play((CellAnime *)(param_1 + 0x399f4),*(uchar *)((int)piVar4 + 0xb),0,1.0);
    }
    *(bool *)(param_1 + 0x39c65) = *piVar4 != 0;
    iVar2 = msys::MListWndPBase::getSelectItem(this);
    if (*(char *)(iVar2 + 0xb) == -1) {
      *(undefined1 *)(param_1 + 0x40b41) = 0;
    }
    else {
      *(undefined1 *)(param_1 + 0x40b41) = 1;
      CellAnime::play((CellAnime *)(param_1 + 0x40b4c),*(uchar *)(iVar2 + 0xb),0,1.0);
    }
    msys::MMsg::playStr((MMsg *)(param_1 + 0x39dbc),*(wchar_t **)(iVar2 + 0x10),(InsParam *)0x0,
                        false);
    iVar2 = msys::MListWndPBase::getListWnd(this);
    *(undefined1 *)(iVar2 + 0x6d79) = 0;
    *(code **)(param_1 + 0x20) = FUN_1500c9c8;
    *(undefined4 *)(param_1 + 0x24) = 0;
    return;
  }
  iVar2 = msys::MListWndPBase::isBusyAnime(this);
  if (iVar2 != 0) {
    return;
  }
  iVar5 = msys::MListWndPBase::getListWnd(this);
  iVar2 = msys::MComSys::_sys;
  if (*(int *)(iVar5 + 0x1cc) != 0) {
    return;
  }
  uVar8 = *param_2;
  if ((uVar8 & 0x802) != 0) {
    iVar5 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar5 = iVar2;
    }
    *(undefined1 *)(iVar5 + 0xe6508) = 0;
    iVar5 = msys::MComSys::_sys;
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar5;
    }
    *(undefined1 *)(iVar2 + 0xe650a) = 1;
    (**(code **)(**(int **)(param_1 + 0x860) + 0x18))();
    (**(code **)(**(int **)(param_1 + 0x860) + 0x10))();
    (**(code **)(**(int **)(param_1 + 0x860) + 0xc))();
    goto LAB_1500d544;
  }
  if ((uVar8 & 0x30) != 0) {
    cVar1 = *(char *)(param_1 + 0x874);
    iVar2 = (int)cVar1;
    if ((uVar8 & 0x20) == 0) {
      if (((uVar8 & 0x10) != 0) && (iVar2 = (int)(char)(cVar1 + '\x01'), 2 < iVar2)) {
        iVar2 = 1;
      }
    }
    else {
      iVar2 = (int)(char)(cVar1 + -1);
      if (iVar2 < 1) {
        iVar2 = 2;
      }
    }
    iVar2 = param_1 + iVar2 * 4;
    piVar4 = *(int **)(iVar2 + 0x44ea0);
    if ((*(byte *)(piVar4 + 2) & 0x10) != 0) {
      (**(code **)(*piVar4 + 0x18))();
      (**(code **)(**(int **)(iVar2 + 0x44ea0) + 0x10))();
      iVar5 = msys::MComSys::_sys;
      iVar2 = *(int *)(param_1 + 8);
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar2 = iVar5;
      }
      *(undefined1 *)(iVar2 + 0xe6508) = 0;
    }
    goto LAB_1500d544;
  }
  if ((uVar8 & 0x300) == 0) goto LAB_1500d544;
  cVar1 = *(char *)(param_1 + 0x875);
  iVar2 = 0;
  if (DAT_150360df != cVar1) {
    if (DAT_150360e0 == cVar1) {
      iVar2 = 1;
    }
    else if (DAT_150360e1 == cVar1) {
      iVar2 = 2;
    }
    else {
      iVar2 = 3;
    }
  }
  if ((uVar8 & 0x200) == 0) {
    if ((uVar8 & 0x100) != 0) {
      uVar8 = iVar2 + 1;
      if (2 < uVar8) {
        uVar8 = 0;
      }
      goto LAB_1500d4e8;
    }
  }
  else {
    uVar8 = iVar2 - 1;
    if ((int)uVar8 < 0) {
      uVar8 = 2;
    }
LAB_1500d4e8:
    uVar10 = (&DAT_150360df)[uVar8];
  }
  FUN_1501580c(msys::MComSys::_sys + 0x49368,0x110016,0,0,0);
  FUN_15012af4(param_1,uVar10,1);
  msys::MListWndPBase::getListWnd(this);
  puVar6 = (undefined2 *)ad::ui::UIListWindowPlusLyt::getCurItem();
  FUN_15011f6c(param_1,*puVar6);
LAB_1500d544:
  iVar2 = msys::MListWndPBase::getListWnd(this);
  if ((*(char *)(iVar2 + 0x144) != '\0') &&
     (iVar2 = msys::MListWndPBase::getListWnd(this), *(int *)(iVar2 + 0x1cc) == 0)) {
    msys::MListWndPBase::getListWnd(this);
    piVar4 = (int *)ad::ui::UIListWindowPlusLyt::getCurItem();
    iVar2 = msys::MListWndPBase::getListWnd(this);
    if (*(ushort *)(param_1 + 0x876) != (ushort)*(byte *)(iVar2 + 0x149)) {
      if (piVar4 == (int *)0x0) {
        FUN_15011f6c(param_1,0);
      }
      else {
        FUN_15011f6c(param_1,(short)*piVar4);
      }
    }
    if (((param_2[1] & 0xc0) == 0) && (*piVar4 != 0)) {
      msys::PutEquipCheckedFlag((ushort)*piVar4);
      return;
    }
  }
  return;
}


// FUNC 0x1500d5fc FUN_1500d5fc (MainMenu)
//   size 0xf4 | file MainMenu+0xd5fc | callers(0) | datarefs 4

void FUN_1500d5fc(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = msys::MLyt::isBusyAnime((MLyt *)(param_1 + 0x110));
  if ((iVar2 == 0) && (iVar2 = msys::MLyt::isBusyAnime((MLyt *)(param_1 + 0x4b8)), iVar2 == 0)) {
    *(undefined1 *)(param_1 + 0x44fec) = 1;
    msys::MListWndPBase::setEnableInput((MListWndPBase *)(param_1 + 0x44eac),false);
    *(undefined1 *)(param_1 + 0x894) = *(undefined1 *)(param_1 + 0x874);
    msys::MCursorBase::setVisible((MCursorBase *)(param_1 + 0x87c),true);
    FUN_150121ac((MCursorBase *)(param_1 + 0x87c));
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
    iVar1 = msys::MComSys::_sys;
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar1;
    }
    uVar3 = DataPc::getEquip((DataPc *)(iVar2 + (uint)*(byte *)(param_1 + 0x875) * 0xb0 + 0xeac64),
                             *(uchar *)(param_1 + 0x874));
    FUN_15012a2c(param_1 + 0x968,uVar3);
    *(code **)(param_1 + 0x20) = FUN_1500c678;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x1500d700 FUN_1500d700 (MainMenu)
//   size 0x98 | file MainMenu+0xd700 | callers(0) | datarefs 2

void FUN_1500d700(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = msys::MLyt::isBusyAnime((MLyt *)(param_1 + 0x110));
  if ((iVar2 == 0) && (iVar2 = msys::MLyt::isBusyAnime((MLyt *)(param_1 + 0x4b8)), iVar2 == 0)) {
    *(undefined1 *)(param_1 + 0x44fec) = 1;
    msys::MListWndPBase::setEnableInput((MListWndPBase *)(param_1 + 0x44eac),true);
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
    *(undefined2 *)(param_1 + 0x876) = 0xffff;
    *(code **)(param_1 + 0x20) = FUN_1500d000;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x1500d7a8 main_menu::MainMenu_EquipPage::Core::vfunc_0x8 (MainMenu)
//   size 0xfc | file MainMenu+0xd7a8 | callers(0) | datarefs 1

int main_menu::MainMenu_EquipPage::Core::vfunc_0x8(int *param_1,MInput *param_2)

{
  MInput MVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  code *extraout_r2;
  code *pcVar6;
  VEC2 *pVVar7;
  bool bVar8;
  uint in_fpscr;
  undefined4 local_20;
  undefined4 local_1c;
  
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
  iVar4 = msys::MListWndPBase::isTpNeutral((MListWndPBase *)(param_1 + 0x113ab));
  MVar1 = param_2[0x11];
  bVar8 = MVar1 == (MInput)0x0;
  if (bVar8) {
    MVar1 = param_2[0x12];
  }
  pVVar7 = (VEC2 *)0x0;
  if ((!bVar8 || MVar1 != (MInput)0x0) && iVar4 != 0) {
    local_20 = VectorSignedToFloat(*(ushort *)(param_2 + 0x14) - 0xa0,(byte)(in_fpscr >> 0x16) & 3);
    local_1c = VectorSignedToFloat(0x78 - (uint)*(ushort *)(param_2 + 0x16),
                                   (byte)(in_fpscr >> 0x16) & 3);
    pVVar7 = (VEC2 *)&local_20;
  }
  bVar8 = (bool)(**(code **)(*param_1 + 0xc))(param_1,param_2);
  iVar2 = msys::MComSys::_sys;
  iVar5 = param_1[2];
  if (param_1[2] == 0) {
    param_1[2] = msys::MComSys::_sys;
    iVar5 = iVar2;
  }
  ad::ctrl::ButtonGroup::Update
            ((ButtonGroup *)(param_1 + 0xf),pVVar7,
             (bool)(*(byte *)(iVar5 + 0xe6508) & bVar8 & (byte)iVar4),bVar8);
  return (int)*(char *)((int)param_1 + 0x865);
}


// FUNC 0x1500d8bc FUN_1500d8bc (MainMenu)
//   size 0x228 | file MainMenu+0xd8bc | callers(0) | datarefs 1

void FUN_1500d8bc(int param_1)

{
  MemAlcBase *pMVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  
  FUN_150144d8();
  iVar4 = msys::MComSys::_sys;
  iVar2 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar2 = iVar4;
  }
  iVar4 = msys::MComSys::_sys;
  pMVar1 = (MemAlcBase *)(param_1 + 0x28);
  if (iVar2 == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  else {
    iVar4 = iVar2;
  }
  FUN_15012fe8(*(undefined4 *)(iVar4 + 4),param_1 + 0x836c,*(int *)(iVar2 + 0x278) + 0xa8,
               "m_item_all",pMVar1,0x7f,0,0,0);
  iVar4 = msys::MComSys::_sys;
  iVar2 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar2 = iVar4;
  }
  iVar4 = msys::MComSys::_sys;
  if (iVar2 == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  else {
    iVar4 = iVar2;
  }
  FUN_15012fe8(*(undefined4 *)(iVar4 + 4),param_1 + 0x83b0,*(int *)(iVar2 + 0x278) + 0xa8,
               "menu_mario",pMVar1,0x7f,0,0,0);
  iVar4 = msys::MComSys::_sys;
  iVar2 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar2 = iVar4;
  }
  iVar4 = msys::MComSys::_sys;
  if (iVar2 == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  else {
    iVar4 = iVar2;
  }
  FUN_15012fe8(*(undefined4 *)(iVar4 + 4),param_1 + 0x83f4,*(int *)(iVar2 + 0x278) + 0xa8,
               "menu_luigi",pMVar1,0x7f,0,0,0);
  iVar4 = msys::MComSys::_sys;
  iVar2 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar2 = iVar4;
  }
  iVar4 = msys::MComSys::_sys;
  if (iVar2 == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  else {
    iVar4 = iVar2;
  }
  FUN_15012fe8(*(undefined4 *)(iVar4 + 4),param_1 + 0x8438,*(int *)(iVar2 + 0x278) + 0xa8,
               "menu_koopa",pMVar1,0x7f,0,0,0);
  iVar4 = msys::MComSys::_sys;
  iVar2 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar2 = iVar4;
  }
  iVar4 = msys::MComSys::_sys;
  if (iVar2 == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  else {
    iVar4 = iVar2;
  }
  ad::fw::TaskBase::readLyt
            (*(TaskBase **)(iVar4 + 4),(Resource *)(param_1 + 0xcc),
             (FileContext *)(*(int *)(iVar2 + 0x278) + 0x150),"?MENU_EQUIP",pMVar1,0x7f,
             (ResCacheArg *)0x0);
  puVar3 = operator_new(0xc,*(MemAlcBase **)(*(int *)(param_1 + 4) + 0x18),"ParamMainEquip",0);
  if (puVar3 != (undefined4 *)0x0) {
    *puVar3 = 0x37;
    puVar3[1] = 0x37;
    puVar3[2] = 0x19;
  }
  *(undefined4 **)(param_1 + 0x868) = puVar3;
  iVar4 = msys::MComSys::_sys;
  iVar2 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar2 = iVar4;
  }
  Mem::Copy((void *)(iVar2 + 0xeaf60),&DAT_003f98e8,0x18);
  *(undefined1 **)(param_1 + 0x10) = &LAB_1500ad40;
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}


// FUNC 0x1500db40 FUN_1500db40 (MainMenu)
//   size 0x23c | file MainMenu+0xdb40 | callers(1) 0x15009e38

void FUN_1500db40(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  MPaneRef *pMVar3;
  undefined4 uVar4;
  uint uVar5;
  int *piVar6;
  undefined4 *puVar7;
  uint in_fpscr;
  float fVar8;
  LytAnim local_a8 [4];
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined2 local_98;
  undefined2 local_96;
  AnimTransform *local_94;
  undefined4 local_90;
  InitParam aIStack_88 [72];
  char *local_40 [6];
  
  *param_1 = param_2;
  iVar2 = *(int *)(*(int *)(param_2 + 4) + 0x18);
  param_1[0x1b11] = 0x400;
  param_1[0x1b0e] = iVar2;
  param_1[0x1b0f] = 0;
  param_1[0x1b10] = 0;
  MessageSimple::init((MessageSimple *)(param_1 + 0x54));
  FUN_150142ec(param_1 + 1);
  *(undefined1 *)(param_1 + 0x1703) = 1;
  *(undefined1 *)((int)param_1 + 0x6c29) = 1;
  *(undefined1 *)(param_1 + 0x1b0a) = 4;
  param_1[0x165e] = (int)&DAT_003fc140;
  MessageWriter::setFontColor((MessageWriter *)(param_1 + 0x54),0x373737ff,true);
  pMVar3 = (MPaneRef *)
           msys::MLyt::getMPaneRef
                     ((MLyt *)(*param_1 + 0x110),"INS_TOP_PANEL_TEXT","EXP_PNL_U",(char *)0x0,
                      (char *)0x0);
  piVar6 = (int *)param_1[3];
  *(int **)(param_1[2] + 4) = piVar6;
  *piVar6 = param_1[2];
  piVar6 = param_1 + 2;
  if (piVar6 != (int *)0x0) {
    *piVar6 = (int)(pMVar3 + 0x10);
    puVar7 = *(undefined4 **)(pMVar3 + 0x14);
    param_1[3] = (int)puVar7;
    *puVar7 = piVar6;
    *(int **)(pMVar3 + 0x14) = piVar6;
  }
  msys::MChrBaseCore::setParent((MChrBaseCore *)(param_1 + 1),pMVar3);
  iVar2 = msys::MLyt::getPane((MLyt *)(*param_1 + 0x110),"EXP_PNL_U",(char *)0x0,(char *)0x0);
  param_1[0x1b12] = iVar2;
  local_a8[0] = (LytAnim)0x0;
  local_a4 = 0;
  local_a0 = 0x3f800000;
  local_9c = 0;
  local_98 = 1;
  local_96 = 0;
  local_94 = (AnimTransform *)0x0;
  local_90 = 0;
  ad::lyt::LytAnim::init(local_a8,*(Layout **)(*param_1 + 0x260),"SET_PANEL_STATUS","EXP_PNL_U");
  uVar4 = ad::lyt::AnimTransform::GetFrameSize(local_94);
  fVar8 = (float)VectorUnsignedToFloat(uVar4,(byte)(in_fpscr >> 0x16) & 3);
  ad::lyt::LytAnim::stopAndSetFrm(local_a8,fVar8);
  ad::lyt::LytAnim::term(local_a8,true);
  local_40[0] = "SNUM_HP";
  local_40[1] = "SNUM_BP";
  local_40[2] = "SNUM_POW";
  local_40[3] = "SNUM_DEF";
  local_40[4] = "SNUM_SPEED";
  local_40[5] = "SNUM_HT";
  ad::lyt::LytNumReel3::InitParam::InitParam(aIStack_88);
  uVar5 = 0;
  do {
    iVar1 = msys::MComSys::_sys;
    iVar2 = *(int *)(param_2 + 8);
    if (*(int *)(param_2 + 8) == 0) {
      *(int *)(param_2 + 8) = msys::MComSys::_sys;
      iVar2 = iVar1;
    }
    msys::MLytNumRes::set((MLytNumRes *)(iVar2 + 0x844),aIStack_88,0,0,0xff);
    iVar1 = msys::MComSys::_sys;
    iVar2 = *(int *)(*param_1 + 8);
    if (iVar2 == 0) {
      *(int *)(*param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar1;
    }
    msys::MLytNum::init((MLytNum *)(param_1 + uVar5 * 0x8c + 0x1b13),aIStack_88,
                        (LytDrawData *)(iVar2 + 0xd3000),(MLyt *)(*param_1 + 0x110),local_40[uVar5],
                        "PNL_STATUS_SET","EXP_PNL_U",(char *)0x0);
    uVar5 = uVar5 + 1;
  } while (uVar5 < 6);
  return;
}


// FUNC 0x1500ddf0 FUN_1500ddf0 (MainMenu)
//   size 0x174 | file MainMenu+0xddf0 | callers(0)

void FUN_1500ddf0(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  undefined1 uVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  undefined1 unaff_r7;
  
  if (param_3 == 4) {
    FUN_1501580c(msys::MComSys::_sys + 0x49368,0x110016,0,0,0);
    iVar2 = msys::MComSys::_sys;
    iVar6 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar6 = iVar2;
    }
    uVar3 = 0;
    goto LAB_1500df5c;
  }
  if (param_3 != 5) {
    return;
  }
  cVar1 = *(char *)(param_1 + 0x875);
  uVar4 = 0;
  if (DAT_150360e5 != cVar1) {
    if (DAT_150360e6 == cVar1) {
      uVar4 = 1;
    }
    else if (DAT_150360e7 == cVar1) {
      uVar4 = 2;
    }
    else {
      uVar4 = 3;
    }
  }
  if (*(char *)(param_2 + 0x48) == '\0') {
    uVar7 = uVar4 - 1;
    if ((int)uVar7 < 0) {
      uVar7 = 2;
    }
LAB_1500debc:
    unaff_r7 = (&DAT_150360e5)[uVar7];
  }
  else {
    uVar7 = uVar4;
    if (*(char *)(param_2 + 0x48) == '\x01') {
      uVar7 = uVar4 + 1;
      if (2 < uVar7) {
        uVar7 = 0;
      }
      goto LAB_1500debc;
    }
  }
  (**(code **)(**(int **)(param_1 + uVar4 * 4 + 0x44e98) + 0x18))();
  (**(code **)(**(int **)(param_1 + uVar7 * 4 + 0x44e98) + 0x20))();
  FUN_15012af4(param_1,unaff_r7,0);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  uVar5 = DataPc::getEquip((DataPc *)
                           (*(int *)(param_1 + 8) + (uint)*(byte *)(param_1 + 0x875) * 0xb0 +
                           0xeac64),*(uchar *)(param_1 + 0x874));
  FUN_15012a2c(param_1 + 0x968,uVar5);
  iVar2 = msys::MComSys::_sys;
  iVar6 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar6 = iVar2;
  }
  uVar3 = 1;
LAB_1500df5c:
  *(undefined1 *)(iVar6 + 0xe6508) = uVar3;
  return;
}


// FUNC 0x1500df8c FUN_1500df8c (MainMenu)
//   size 0x2ec | file MainMenu+0xdf8c | callers(1) 0x1500e660

void FUN_1500df8c(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)FUN_15014438();
  *puVar1 = &main_menu::MainMenu_EquipPage::Core::vtable;
  puVar1[0x21b] = param_2;
  *(undefined1 *)(puVar1 + 0x21d) = 0;
  *(undefined1 *)((int)puVar1 + 0x875) = 0;
  *(undefined1 *)(puVar1 + 0x21e) = 0xff;
  puVar1 = (undefined4 *)msys::MCursorBase::MCursorBase((MCursorBase *)(puVar1 + 0x21f));
  *puVar1 = &vtable_for_N4msys7MCursorILj4EEE;
  puVar1[0xc] = 0;
  puVar1[0xd] = 0;
  puVar1[0xe] = 0;
  puVar1[0xf] = 0;
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(puVar1 + 0x11,FUN_15012f30,0x1c,3);
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(iVar2 + 0x54,FUN_15012f30,0x1c,3);
  iVar2 = FUN_15012fa0(iVar2 + 0x58);
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(iVar2 + 0x6c48,msys::MLytNum::MLytNum,0x230,6);
  *(undefined4 *)(iVar2 + 0xd20) = 0;
  *(undefined4 *)(iVar2 + 0xd24) = 0x3f800000;
  *(undefined4 *)(iVar2 + 0xd28) = 0;
  *(undefined2 *)(iVar2 + 0xd2c) = 1;
  *(undefined2 *)(iVar2 + 0xd2e) = 0;
  iVar2 = ad::fw::Resource::Resource((Resource *)(iVar2 + 0xd30));
  iVar2 = ad::fw::Resource::Resource((Resource *)(iVar2 + 0x44));
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(iVar2 + 0x44,ad::fw::Resource::Resource,0x44,4);
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(iVar2 + 0x110,FUN_15012f6c,0x27c,3);
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(iVar2 + 0x774,FUN_15012f6c,0x27c,3);
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(iVar2 + 0x774,&LAB_15009740,0x6ec4,3);
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(iVar2 + 0x14c4c,&LAB_15009740,0x6ec4,3);
  *(undefined ***)(iVar2 + 0x14c4c) = &main_menu::MainMenu_EquipPage::Core::MoveNameBarBase::vtable;
  *(undefined4 *)(iVar2 + 0x14c50) = 0;
  *(undefined4 *)(iVar2 + 0x14c54) = 0;
  puVar1 = (undefined4 *)MoveVBase::MoveVBase((MoveVBase *)(iVar2 + 0x14c58));
  *puVar1 = &vtable_for_5MoveVILj1EE;
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(puVar1 + 0xc,FUN_150012f0,0x2c,1);
  *(int *)(iVar2 + -8) = iVar2;
  *(undefined1 *)(iVar2 + -4) = 1;
  iVar2 = FUN_15012fa0(iVar2 + 0x2c);
  iVar2 = FUN_15012f6c(iVar2 + 0x6c44);
  *(undefined ***)(iVar2 + -0x6cac) = &main_menu::MainMenu_EquipPage::Core::MoveListCur::vtable;
  iVar2 = msys::MLytNum::MLytNum((MLytNum *)(iVar2 + 0x27c));
  *(undefined ***)(iVar2 + 0x230) = &main_menu::MainMenu_EquipPage::Core::MoveNameBarBase::vtable;
  *(undefined4 *)(iVar2 + 0x234) = 0;
  *(undefined4 *)(iVar2 + 0x238) = 0;
  puVar1 = (undefined4 *)MoveVBase::MoveVBase((MoveVBase *)(iVar2 + 0x23c));
  *puVar1 = &vtable_for_5MoveVILj1EE;
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(puVar1 + 0xc,FUN_150012f0,0x2c,1);
  *(int *)(iVar2 + -8) = iVar2;
  *(undefined1 *)(iVar2 + -4) = 1;
  iVar2 = FUN_15012fa0(iVar2 + 0x2c);
  iVar2 = FUN_15012f6c(iVar2 + 0x6c44);
  *(undefined ***)(iVar2 + -0x6cac) = &main_menu::MainMenu_EquipPage::Core::MovePnlNameBar::vtable;
  iVar2 = msys::MDfxChr::MDfxChr((MDfxChr *)(iVar2 + 0x27c));
  iVar2 = msys::StatusPanel::StatusPanel((StatusPanel *)(iVar2 + 0x17c));
  iVar2 = msys::StatusPanel::StatusPanel((StatusPanel *)(iVar2 + 0x2034));
  puVar1 = (undefined4 *)
           msys::MListWndPBase::MListWndPBase
                     ((MListWndPBase *)(iVar2 + 0x2080),(MListWndPCore *)(iVar2 + 0x227c));
  *puVar1 = &vtable_for_N4msys9MListWndPILi256EEE;
  puVar1 = (undefined4 *)
           ad::ui::UIListWindowPlusLyt::UIListWindowPlusLyt((UIListWindowPlusLyt *)(puVar1 + 0x7f));
  *puVar1 = &msys::MListWndPCore::vtable;
  puVar1[-0x7f] = &main_menu::MainMenu_EquipPage::Core::MListWndEquip::vtable;
  iVar2 = ad::lyt::Layout::Layout((Layout *)(puVar1 + 0x2262));
  iVar2 = FUN_15012f30(iVar2 + 0x3c);
  iVar2 = FUN_15012f30(iVar2 + 0x1c);
  iVar2 = ad::lyt::Layout::Layout((Layout *)(iVar2 + 0x1c));
  iVar2 = FUN_15012f30(iVar2 + 0x3c);
  iVar2 = FUN_15012f30(iVar2 + 0x1c);
  iVar2 = FUN_15012f30(iVar2 + 0x1c);
  iVar2 = FUN_15012f30(iVar2 + 0x1c);
  iVar2 = FUN_15012f30(iVar2 + 0x1c);
  iVar2 = CellAnime::CellAnime((CellAnime *)(iVar2 + 0x1c));
  *(undefined4 *)(iVar2 + 0x148) = 0;
  *(code **)(iVar2 + -0x4db5c) = FUN_1500d8bc;
  *(undefined4 *)(iVar2 + -0x4db58) = 0;
  *(undefined1 **)(iVar2 + -0x4db54) = &LAB_1500df74;
  *(undefined4 *)(iVar2 + -0x4db50) = 0;
  *(code **)(iVar2 + -0x4db4c) = FUN_1500ce58;
  *(undefined4 *)(iVar2 + -0x4db48) = 0;
  return;
}


// FUNC 0x1500e2dc main_menu::MainMenu_EquipPage::Core::vfunc_0x4 (MainMenu)
//   size 0x10 | file MainMenu+0xe2dc | callers(0) | datarefs 1

void main_menu::MainMenu_EquipPage::Core::vfunc_0x4(void)

{
  void *pvVar1;
  
  pvVar1 = (void *)vfunc_0x0();
  operator_delete(pvVar1);
  return;
}


// FUNC 0x1500e2ec main_menu::MainMenu_EquipPage::Core::vfunc_0x0 (MainMenu)
//   size 0x320 | file MainMenu+0xe2ec | callers(1) 0x1500e2dc | datarefs 1

void main_menu::MainMenu_EquipPage::Core::vfunc_0x0(undefined4 *param_1)

{
  int iVar1;
  uint uVar2;
  
  *param_1 = &vtable;
  *(undefined1 *)((int)param_1 + 0x875) = 0;
  *(undefined1 *)(param_1 + 0x21d) = 0;
  ad::fw::Resource::term((Resource *)(param_1 + 0x20b9));
  ad::fw::Resource::term((Resource *)(param_1 + 0x20ca));
  uVar2 = 0;
  do {
    ad::fw::Resource::term((Resource *)(param_1 + uVar2 * 0x11 + 0x20db));
    uVar2 = uVar2 + 1 & 0xff;
  } while (uVar2 < 4);
  msys::MCursorBase::term((MCursorBase *)(param_1 + 0x21f));
  operator_delete((void *)param_1[0x21a]);
  param_1[0x21a] = 0;
  iVar1 = MListWndEquip::vfunc_0x0(param_1 + 0x113ab);
  iVar1 = msys::StatusPanel::~StatusPanel((StatusPanel *)(iVar1 + -0x2080));
  iVar1 = msys::StatusPanel::~StatusPanel((StatusPanel *)(iVar1 + -0x2034));
  *(undefined ***)(iVar1 + -0x70a4) = &MovePnlNameBar::vtable;
  iVar1 = msys::MDfxChr::~MDfxChr((MDfxChr *)(iVar1 + -0x17c));
  *(undefined ***)(iVar1 + -0x6f28) = &MoveNameBarBase::vtable;
  *(undefined ***)(iVar1 + -0x27c) = &msys::MCellAnime::vtable;
  iVar1 = CellAnime::~CellAnime((CellAnime *)(iVar1 + -0x130));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  *(undefined ***)(iVar1 + -0x6c44) = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar1 = MessageSimple::~MessageSimple((MessageSimple *)(iVar1 + -0x6af8));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  *(undefined ***)(iVar1 + -0x5c) = &vtable_for_5MoveVILj1EE;
  __aeabi_vec_dtor(iVar1 + -0x2c,MoveWorkF::~MoveWorkF,0x2c,1);
  iVar1 = MoveVBase::~MoveVBase((MoveVBase *)(iVar1 + -0x5c));
  *(undefined ***)(iVar1 + -0x7164) = &MoveListCur::vtable;
  iVar1 = msys::MLytNum::~MLytNum((MLytNum *)(iVar1 + -0x23c));
  *(undefined ***)(iVar1 + -0x6f28) = &MoveNameBarBase::vtable;
  *(undefined ***)(iVar1 + -0x27c) = &msys::MCellAnime::vtable;
  iVar1 = CellAnime::~CellAnime((CellAnime *)(iVar1 + -0x130));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  *(undefined ***)(iVar1 + -0x6c44) = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar1 = MessageSimple::~MessageSimple((MessageSimple *)(iVar1 + -0x6af8));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  *(undefined ***)(iVar1 + -0x5c) = &vtable_for_5MoveVILj1EE;
  __aeabi_vec_dtor(iVar1 + -0x2c,MoveWorkF::~MoveWorkF,0x2c,1);
  iVar1 = MoveVBase::~MoveVBase((MoveVBase *)(iVar1 + -0x5c));
  __aeabi_vec_dtor(iVar1 + -0x14c58,&LAB_15009764,0x6ec4,3);
  __aeabi_vec_dtor(iVar1 + -0x298a4,&LAB_15009764,0x6ec4,3);
  __aeabi_vec_dtor(iVar1 + -0x2a018,&LAB_15000e9c,0x27c,3);
  __aeabi_vec_dtor(iVar1 + -0x2a78c,&LAB_15000e9c,0x27c,3);
  __aeabi_vec_dtor(iVar1 + -0x2a89c,ad::fw::Resource::~Resource,0x44,4);
  iVar1 = ad::fw::Resource::~Resource((Resource *)(iVar1 + -0x2a8e0));
  iVar1 = ad::fw::Resource::~Resource((Resource *)(iVar1 + -0x44));
  *(undefined4 *)(iVar1 + -8) = 0;
  __aeabi_vec_dtor(iVar1 + -0xd30,msys::MLytNum::~MLytNum,0x230,6);
  *(undefined ***)(iVar1 + -0x7978) = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar1 = MessageSimple::~MessageSimple((MessageSimple *)(iVar1 + -0x782c));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  __aeabi_vec_dtor(iVar1 + -0x58,&LAB_15000d18,0x1c,3);
  __aeabi_vec_dtor(iVar1 + -0xac,&LAB_15000d18,0x1c,3);
  iVar1 = msys::MCursorBase::~MCursorBase((MCursorBase *)(iVar1 + -0xf0));
  MainMenuPageBase::Core::vfunc_0x0(iVar1 + -0x87c);
  return;
}


// FUNC 0x1500e660 main_menu::MainMenu_EquipPage::vfunc_0x30 (MainMenu)
//   size 0x30 | file MainMenu+0xe660 | callers(0) | datarefs 1

void main_menu::MainMenu_EquipPage::vfunc_0x30(int param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(0x4dcb8,*(MemAlcBase **)(param_1 + 0x18),(char *)0x0,0x1f);
  uVar2 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_1500df8c(pvVar1,param_1);
  }
  *(undefined4 *)(param_1 + 0x20) = uVar2;
  return;
}


// FUNC 0x1500e694 main_menu::MainMenu_EquipPage::vfunc_0x24 (MainMenu)
//   size 0x8 | file MainMenu+0xe694 | callers(0) | datarefs 1

undefined4 main_menu::MainMenu_EquipPage::vfunc_0x24(void)

{
  return 2;
}


// FUNC 0x1500e69c main_menu::MainMenu_EquipPage::vfunc_0x4 (MainMenu)
//   size 0x10 | file MainMenu+0xe69c | callers(0) | datarefs 1

void main_menu::MainMenu_EquipPage::vfunc_0x4(void)

{
  void *pvVar1;
  
  pvVar1 = (void *)MainMenuPageBase::vfunc_0x0();
  operator_delete(pvVar1);
  return;
}


// FUNC 0x1500e6ac ->main_menu::MainMenuPageBase::vfunc_0x0 (MainMenu)
//   size 0x4 | file MainMenu+0xe6ac | callers(0) | datarefs 1
// veneer/thunk -> 0x15015174 main_menu::MainMenuPageBase::vfunc_0x0 (MainMenu)

// FUNC 0x1500e6b0 FUN_1500e6b0 (MainMenu)
//   size 0x8f4 | file MainMenu+0xe6b0 | callers(1) 0x15015ea8

void FUN_1500e6b0(void *param_1)

{
  char cVar1;
  MCursorBase *this;
  int iVar2;
  void *pvVar3;
  int iVar4;
  MLyt *this_00;
  undefined4 uVar5;
  undefined4 *puVar6;
  AnimButton *pAVar7;
  int *piVar8;
  LytAnim *this_01;
  MChrBase *this_02;
  BootInfo *this_03;
  BootInfo *this_04;
  int iVar9;
  int iVar10;
  MChrBase *this_05;
  float fVar11;
  float fVar12;
  LytAnim local_60 [4];
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined2 local_50;
  undefined2 local_4e;
  undefined4 local_4c;
  undefined4 local_48;
  int local_44;
  
  if (*(int *)((int)param_1 + 8) == 0) {
    *(int *)((int)param_1 + 8) = msys::MComSys::_sys;
  }
  iVar10 = *(int *)((int)param_1 + 8);
  ad::lyt::LytResourceMan::init((LytResourceMan *)((int)param_1 + 0x58));
  pvVar3 = (void *)ad::fw::Resource::getFileData((Resource *)((int)param_1 + 0xcc));
  ad::lyt::LytResourceMan::registerArc((LytResourceMan *)((int)param_1 + 0x58),pvVar3,".");
  iVar4 = msys::MComSys::_sys;
  iVar9 = *(int *)((int)param_1 + 8);
  if (*(int *)((int)param_1 + 8) == 0) {
    *(int *)((int)param_1 + 8) = msys::MComSys::_sys;
    iVar9 = iVar4;
  }
  iVar2 = msys::MComSys::_sys;
  this = (MCursorBase *)((int)param_1 + 0xe584);
  iVar4 = iVar9;
  if (iVar9 == 0) {
    *(int *)((int)param_1 + 8) = msys::MComSys::_sys;
    iVar4 = iVar2;
  }
  iVar4 = ad::fw::TaskBase::isFps30(*(TaskBase **)(iVar4 + 4));
  fVar12 = 1.0;
  if (iVar4 == 0) {
    fVar11 = fVar12;
  }
  else {
    fVar11 = 2.0;
  }
  msys::MCursorBase::init(this,(MLyt *)(iVar9 + 0xe9a9c),fVar11);
  iVar9 = 6;
  puVar6 = (undefined4 *)((int)param_1 + 0xe5b4);
  do {
    iVar9 = iVar9 + -1;
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  } while (iVar9 != 0);
  this_00 = (MLyt *)((int)param_1 + 0x4b8);
  msys::MLyt::build(this_00,*(MemAlcBase **)(*(int *)((int)param_1 + 4) + 0x18),
                    (AnimeName *)&PTR_s_FADE_IN_15024c20,4);
  msys::MLyt::init(this_00,iVar10 + 0xd3000,1);
  msys::MLyt::createLyt
            (this_00,(LytResourceMan *)((int)param_1 + 0x58),"MENU_GUIDE_L.bflyt",
             (ButtonGroup *)((int)param_1 + 0x3c),this);
  MoveVBase::stop((MoveVBase *)((int)param_1 + 0x584));
  *(undefined4 *)((int)param_1 + 0x5a0) = 0;
  *(undefined4 *)((int)param_1 + 0x5a4) = 0;
  *(undefined4 *)((int)param_1 + 0x5a8) = 0xc347e666;
  *(undefined4 *)((int)param_1 + 0x588) = *(undefined4 *)((int)param_1 + 0x5a0);
  *(undefined4 *)((int)param_1 + 0x58c) = 0;
  *(undefined4 *)((int)param_1 + 0x590) = 0xc347e666;
  this_05 = (MChrBase *)((int)param_1 + 0x74b4);
  *(undefined4 *)((int)param_1 + 0x5f4) = 0x401;
  uVar5 = *(undefined4 *)(*(int *)((int)param_1 + 4) + 0x18);
  *(undefined4 *)((int)param_1 + 0xe0f4) = 0x401;
  *(undefined4 *)((int)param_1 + 0xe0e8) = uVar5;
  *(undefined4 *)((int)param_1 + 0xe0ec) = 0;
  *(undefined4 *)((int)param_1 + 0xe0f0) = 0;
  MessageSimple::init((MessageSimple *)((int)param_1 + 0x7600));
  FUN_150142ec(this_05);
  *(undefined1 *)((int)param_1 + 0xd0bc) = 1;
  *(undefined1 *)((int)param_1 + 0xd0bd) = 1;
  *(undefined1 *)((int)param_1 + 0xe0d9) = 1;
  MessageWriter::setFontColor((MessageWriter *)((int)param_1 + 0x7600),0xe6e6e6ff,false);
  *(undefined1 *)((int)param_1 + 0xe0d8) = 3;
  *(undefined **)((int)param_1 + 0xce28) = &DAT_003fc0f8;
  MoveVBase::stop((MoveVBase *)((int)param_1 + 0x7580));
  *(undefined4 *)((int)param_1 + 0x759c) = 0;
  *(undefined4 *)((int)param_1 + 0x75a0) = 0;
  *(undefined4 *)((int)param_1 + 0x75a4) = 0x3c23d70a;
  *(undefined4 *)((int)param_1 + 0x7584) = 0;
  *(undefined4 *)((int)param_1 + 0x7588) = 0;
  *(undefined4 *)((int)param_1 + 0x758c) = 0x3c23d70a;
  msys::MLyt::attachMChr(this_00,this_05,"INS_TITLE_TEXT","GUIDE_TXT_base",(char *)0x0,(char *)0x0);
  uVar5 = *(undefined4 *)(*(int *)((int)param_1 + 4) + 0x18);
  *(undefined4 *)((int)param_1 + 0x74b0) = 0x401;
  *(undefined4 *)((int)param_1 + 0x74a4) = uVar5;
  *(undefined4 *)((int)param_1 + 0x74a8) = 0;
  *(undefined4 *)((int)param_1 + 0x74ac) = 0;
  MessageSimple::init((MessageSimple *)((int)param_1 + 0x9bc));
  FUN_150142ec((int)param_1 + 0x870);
  *(undefined1 *)((int)param_1 + 0x6478) = 0;
  *(undefined1 *)((int)param_1 + 0x6479) = 1;
  *(undefined1 *)((int)param_1 + 0x7495) = 1;
  MessageWriter::setFontColor((MessageWriter *)((int)param_1 + 0x9bc),0x373737ff,false);
  *(undefined1 *)((int)param_1 + 0x7494) = 4;
  *(undefined **)((int)param_1 + 0x61e4) = &DAT_003fc140;
  MoveVBase::stop((MoveVBase *)((int)param_1 + 0x93c));
  *(undefined4 *)((int)param_1 + 0x958) = 0;
  *(undefined4 *)((int)param_1 + 0x95c) = 0;
  *(undefined4 *)((int)param_1 + 0x960) = 0x3c23d70a;
  *(undefined4 *)((int)param_1 + 0x940) = *(undefined4 *)((int)param_1 + 0x958);
  *(undefined4 *)((int)param_1 + 0x944) = 0;
  *(undefined4 *)((int)param_1 + 0x948) = 0x3c23d70a;
  iVar9 = msys::MLyt::getPane(this_00,"INS_TEXT_GUIDE","GUIDE_TXT_base",(char *)0x0);
  fVar11 = *(float *)(iVar9 + 0x1c);
  if (fVar11 == 0.0) {
    fVar11 = **(float **)((int)param_1 + 0x868);
  }
  *(float *)(iVar9 + 0x1c) = fVar11;
  *(byte *)(iVar9 + 0x44) = *(byte *)(iVar9 + 0x44) & 0xef | 0x10;
  msys::MLyt::attachMChr
            (this_00,(MChrBase *)((int)param_1 + 0x870),"INS_TEXT_GUIDE","GUIDE_TXT_base",
             (char *)0x0,(char *)0x0);
  iVar4 = msys::MComSys::_sys;
  iVar9 = *(int *)((int)param_1 + 8);
  if (*(int *)((int)param_1 + 8) == 0) {
    *(int *)((int)param_1 + 8) = msys::MComSys::_sys;
    iVar9 = iVar4;
  }
  local_44 = (int)param_1 + 0xe0f8;
  FUN_15015ae0(local_44,iVar9,this_00,(int)param_1 + 0x870);
  iVar4 = msys::MComSys::_sys;
  iVar9 = *(int *)((int)param_1 + 8);
  if (*(int *)((int)param_1 + 8) == 0) {
    *(int *)((int)param_1 + 8) = msys::MComSys::_sys;
    iVar9 = iVar4;
  }
  iVar10 = msys::MComSys::_sys;
  iVar4 = iVar9;
  if (iVar9 == 0) {
    *(int *)((int)param_1 + 8) = msys::MComSys::_sys;
    iVar4 = iVar10;
  }
  iVar4 = ad::fw::TaskBase::isFps30(*(TaskBase **)(iVar4 + 4));
  if (iVar4 != 0) {
    fVar12 = 2.0;
  }
  msys::MCursorBase::init(this,(MLyt *)(iVar9 + 0xe9a9c),fVar12);
  iVar9 = 6;
  puVar6 = (undefined4 *)((int)param_1 + 0xe5b4);
  do {
    iVar9 = iVar9 + -1;
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  } while (iVar9 != 0);
  iVar9 = 0;
  do {
    pAVar7 = (AnimButton *)
             ad::ctrl::ButtonGroup::FindButtonByName
                       ((ButtonGroup *)((int)param_1 + 0x3c),(char *)(&DAT_15036398)[iVar9]);
    *(AnimButton **)((int)param_1 + iVar9 * 4 + 0xe600) = pAVar7;
    ad::ctrl::AnimButton::SetStateChangeCallback
              (pAVar7,(_func_void_AnimButton_ptr_State_State_void_ptr *)&DAT_1500f0b8,param_1);
    *(int *)(*(int *)((int)param_1 + iVar9 * 4 + 0xe600) + 0x48) = iVar9;
    piVar8 = *(int **)((int)param_1 + iVar9 * 4 + 0xe600);
    (**(code **)(*piVar8 + 0x28))(piVar8,0);
    iVar9 = iVar9 + 1;
  } while (iVar9 < 4);
  iVar9 = 0;
  do {
    cVar1 = (char)iVar9;
    uVar5 = msys::MLyt::getParts(this_00,(char *)(&DAT_15036398)[iVar9],(char *)0x0,(char *)0x0);
    iVar9 = iVar9 + 1;
    *(undefined4 *)((int)param_1 + cVar1 * 4 + 0xe5b4) = uVar5;
  } while (iVar9 < 4);
  iVar9 = 0;
  do {
    pAVar7 = (AnimButton *)
             ad::ctrl::ButtonGroup::FindButtonByName
                       ((ButtonGroup *)((int)param_1 + 0x3c),(char *)(&DAT_15036110)[iVar9]);
    *(AnimButton **)((int)param_1 + iVar9 * 4 + 0xe610) = pAVar7;
    ad::ctrl::AnimButton::SetStateChangeCallback
              (pAVar7,(_func_void_AnimButton_ptr_State_State_void_ptr *)&DAT_15016640,param_1);
    *(int *)(*(int *)((int)param_1 + iVar9 * 4 + 0xe610) + 0x48) = iVar9;
    piVar8 = *(int **)((int)param_1 + iVar9 * 4 + 0xe610);
    (**(code **)(*piVar8 + 0x28))(piVar8,0);
    iVar9 = iVar9 + 1;
  } while (iVar9 < 2);
  pAVar7 = (AnimButton *)
           ad::ctrl::ButtonGroup::FindButtonByName
                     ((ButtonGroup *)((int)param_1 + 0x3c),"btn_RETURN");
  *(AnimButton **)((int)param_1 + 0x860) = pAVar7;
  ad::ctrl::AnimButton::SetStateChangeCallback
            (pAVar7,(_func_void_AnimButton_ptr_State_State_void_ptr *)&LAB_150013dc,param_1);
  *(uint *)(*(int *)((int)param_1 + 0x860) + 8) =
       *(uint *)(*(int *)((int)param_1 + 0x860) + 8) & 0xffffffdf;
  *(undefined4 *)(*(int *)((int)param_1 + 0x860) + 0x48) = 0;
  (**(code **)(**(int **)((int)param_1 + 0x860) + 0x28))(*(int **)((int)param_1 + 0x860),1);
  pAVar7 = (AnimButton *)
           ad::ctrl::ButtonGroup::FindButtonByName((ButtonGroup *)((int)param_1 + 0x3c),"btn_L");
  *(AnimButton **)((int)param_1 + 0xe5f8) = pAVar7;
  ad::ctrl::AnimButton::SetStateChangeCallback(pAVar7,FUN_1500f1dc,param_1);
  (**(code **)(**(int **)((int)param_1 + 0xe5f8) + 0x28))(*(int **)((int)param_1 + 0xe5f8),0);
  *(uint *)(*(int *)((int)param_1 + 0xe5f8) + 8) =
       *(uint *)(*(int *)((int)param_1 + 0xe5f8) + 8) & 0xffffffdf;
  pAVar7 = (AnimButton *)
           ad::ctrl::ButtonGroup::FindButtonByName((ButtonGroup *)((int)param_1 + 0x3c),"btn_R");
  *(AnimButton **)((int)param_1 + 0xe5fc) = pAVar7;
  ad::ctrl::AnimButton::SetStateChangeCallback(pAVar7,FUN_1500f1dc,param_1);
  (**(code **)(**(int **)((int)param_1 + 0xe5fc) + 0x28))(*(int **)((int)param_1 + 0xe5fc),0);
  *(uint *)(*(int *)((int)param_1 + 0xe5fc) + 8) =
       *(uint *)(*(int *)((int)param_1 + 0xe5fc) + 8) & 0xffffffdf;
  uVar5 = *(undefined4 *)((int)param_1 + 0xe5fc);
  *(undefined4 *)(local_44 + 0x478) = *(undefined4 *)((int)param_1 + 0xe5f8);
  *(undefined4 *)(local_44 + 0x47c) = uVar5;
  this_01 = (LytAnim *)((int)param_1 + 0xe5dc);
  ad::lyt::LytAnim::init
            (this_01,*(Layout **)((int)param_1 + 0x608),"SET_GUIDE_L_BTN","GUIDE_TXT_base");
  iVar4 = msys::MComSys::_sys;
  iVar9 = *(int *)((int)param_1 + 8);
  if (*(int *)((int)param_1 + 8) == 0) {
    *(int *)((int)param_1 + 8) = msys::MComSys::_sys;
    iVar9 = iVar4;
  }
  this_02 = (MChrBase *)((int)param_1 + 0xe618);
  FUN_15015ef8(this_02,iVar9,*(undefined4 *)((int)param_1 + 0x868),param_1);
  MoveVBase::stop((MoveVBase *)((int)param_1 + 0xe6e4));
  *(undefined4 *)((int)param_1 + 0xe700) = 0;
  *(undefined4 *)((int)param_1 + 0xe704) = 0;
  *(undefined4 *)((int)param_1 + 0xe708) = 0xc3480000;
  *(undefined4 *)((int)param_1 + 0xe6e8) = *(undefined4 *)((int)param_1 + 0xe700);
  *(undefined4 *)((int)param_1 + 0xe6ec) = 0;
  *(undefined4 *)((int)param_1 + 0xe6f0) = 0xc3480000;
  *(undefined1 *)((int)param_1 + 0xe758) = 1;
  msys::MLyt::attachMChr
            (this_00,this_02,"INS_MENU_GUIDE_L_LIST",(char *)0x0,(char *)0x0,(char *)0x0);
  this_03 = (BootInfo *)main_menu::GetBootInfo();
  main_menu::BootInfo::restoreBgm(this_03);
  iVar9 = main_menu::GetBootInfo();
  if (*(char *)(iVar9 + 0x2b) != '\0') {
    local_60[0] = (LytAnim)0x0;
    local_5c = 0;
    local_58 = 0x3f800000;
    local_54 = 0;
    local_50 = 1;
    local_4e = 0;
    local_4c = 0;
    local_48 = 0;
    ad::lyt::LytAnim::init(local_60,*(Layout **)((int)param_1 + 0x608),"SET_LIST_TYPE","");
    msys::MLyt::stopAnimeAndSetEnd(this_00,0,0,(char *)0x0,(char *)0x0);
    msys::MLyt::stopAnimeAndSetEnd(this_00,0,0,(char *)0x0,(char *)0x0);
    msys::MLyt::stopAnimeAndSetEnd(this_00,1,0,(char *)0x0,(char *)0x0);
    iVar9 = main_menu::GetBootInfo();
    if (*(byte *)(iVar9 + 0x2a) < 2) {
      ad::lyt::LytAnim::stopAndSetFrm(local_60,3.0);
      FUN_15011e78(this_02);
      *(undefined1 *)((int)param_1 + 0xe580) = 3;
      ad::lyt::LytAnim::stopAndSetFrm(this_01,2.0);
      msys::MLyt::stopAnimeAndSetEnd(this_00,3,0,(char *)0x0,(char *)0x0);
    }
    else if (*(byte *)(iVar9 + 0x2a) == 2) {
      ad::lyt::LytAnim::stopAndSetFrm(local_60,1.0);
      FUN_15011d88(this_02);
      *(undefined1 *)((int)param_1 + 0xe580) = 2;
      ad::lyt::LytAnim::stopAndSetFrm(this_01,1.0);
      msys::MLyt::stopAnimeAndSetEnd(this_00,3,0,(char *)0x0,(char *)0x0);
      GameMain::popStack(gGameMain);
      GameMain::popStack(gGameMain);
      this_04 = (BootInfo *)fld::GetBootInfo();
      fld::BootInfo::backScenarioMode(this_04);
    }
    ad::lyt::LytAnim::term(local_60,true);
    iVar9 = main_menu::GetBootInfo();
    Mem::Copy((void *)((int)param_1 + 0x15c98),(void *)(iVar9 + 0x20),8);
    iVar9 = msys::MListWndPBase::getListWnd((MListWndPBase *)this_02);
    Mem::Copy((void *)(iVar9 + 0x148),(void *)((int)param_1 + 0x15c98),8);
    msys::MListWndPBase::normalizeState((MListWndPBase *)this_02,*(uint *)((int)param_1 + 0x15c9c));
    msys::MListWndPBase::getListWnd((MListWndPBase *)this_02);
    iVar9 = ad::ui::UIListWindowPlusLyt::getCurItem();
    msys::MMsg::playStr((MMsg *)this_05,*(wchar_t **)(iVar9 + 0x10),(InsParam *)0x0,false);
    FUN_15011be4(local_44,iVar9);
    *(char *)((int)param_1 + 0xe59c) = *(char *)((int)param_1 + 0xe580);
    if (*(char *)((int)param_1 + 0xe580) == '\x03') {
      ad::lyt::LytAnim::stopAndSetFrm(this_01,2.0);
    }
    else {
      ad::lyt::LytAnim::stopAndSetFrm(this_01,0.0);
    }
    iVar9 = main_menu::GetBootInfo();
    Mem::Fill((void *)(iVar9 + 0x20),0,0xc);
    if (*(char *)((int)param_1 + 0x864) == '\x04') {
      *(undefined1 *)((int)param_1 + 0x5f9) = 0;
      *(undefined1 *)((int)param_1 + 0x251) = 0;
      *(code **)((int)param_1 + 0x20) = FUN_15016bb8;
      *(undefined4 *)((int)param_1 + 0x24) = 0;
    }
    else {
      *(code **)((int)param_1 + 0x20) = FUN_150169a0;
      *(undefined4 *)((int)param_1 + 0x24) = 0;
    }
  }
  *(undefined1 **)((int)param_1 + 0x10) = &LAB_15016464;
  *(undefined4 *)((int)param_1 + 0x14) = 0;
  return;
}


// FUNC 0x1500f0c4 FUN_1500f0c4 (MainMenu)
//   size 0x104 | file MainMenu+0xf0c4 | callers(0)

void FUN_1500f0c4(int param_1,int param_2,int param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  int iVar3;
  MCursorBase *this;
  
  cVar1 = *(char *)(param_2 + 0x48);
  this = (MCursorBase *)(param_1 + 0xe584);
  if (param_3 != 1) {
    if (param_3 != 4) {
      if (param_3 == 5) {
        *(char *)(param_1 + 0xe580) = cVar1;
        FUN_15017348(param_1,cVar1,5,param_4,param_4);
        msys::MListWndPBase::resetCur((MListWndPBase *)(param_1 + 0xe618));
        msys::MCursorBase::setVisible(this,false);
        FUN_15014e10(this);
        return;
      }
      return;
    }
    FUN_1501580c(msys::MComSys::_sys + 0x49368,0x110016,0,0,0);
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
  if (*(char *)(param_1 + 0xe59c) == cVar1) {
    return;
  }
  *(char *)(param_1 + 0xe59c) = cVar1;
  FUN_15014e10(this);
  FUN_1501580c(msys::MComSys::_sys + 0x49368,0x110015,0,0,0);
  return;
}


// FUNC 0x1500f1dc FUN_1500f1dc (MainMenu)
//   size 0xa4 | file MainMenu+0xf1dc | callers(0) | datarefs 2

void FUN_1500f1dc(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = msys::MComSys::_sys;
  if (param_3 == 4) {
    if (*(int *)(param_4 + 8) == 0) {
      *(int *)(param_4 + 8) = msys::MComSys::_sys;
    }
    *(undefined1 *)(*(int *)(param_4 + 8) + 0xe6508) = 0;
    FUN_1501580c(iVar1 + 0x49368,0x11001c,0,0,0);
    return;
  }
  if (param_3 == 5) {
    if (*(int *)(param_4 + 0xe5f8) == param_1) {
      uVar3 = 0xffffffff;
    }
    else {
      uVar3 = 1;
    }
    FUN_15015c5c(param_4 + 0xe0f8,uVar3,*(int *)(param_4 + 0xe5f8),param_4,param_4);
    iVar2 = msys::MComSys::_sys;
    iVar1 = *(int *)(param_4 + 8);
    if (*(int *)(param_4 + 8) == 0) {
      *(int *)(param_4 + 8) = msys::MComSys::_sys;
      iVar1 = iVar2;
    }
    *(undefined1 *)(iVar1 + 0xe6508) = 1;
  }
  return;
}


// FUNC 0x1500f28c FUN_1500f28c (MainMenu)
//   size 0x38 | file MainMenu+0xf28c | callers(1) 0x150231f4

void FUN_1500f28c(undefined4 *param_1)

{
  param_1[1] = param_1 + 1;
  param_1[2] = param_1 + 1;
  param_1[3] = param_1 + 3;
  param_1[4] = param_1 + 3;
  *(undefined1 *)(param_1 + 5) = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  *param_1 = &main_menu::MainMenuPageBase::vtable;
  param_1[8] = 0;
  return;
}


// FUNC 0x1500f2c8 FUN_1500f2c8 (MainMenu)
//   size 0x180 | file MainMenu+0xf2c8 | callers(3) 0x1500f5d8 0x15020134 0x1501fd94

undefined4 FUN_1500f2c8(MListWndPBase *param_1,int param_2)

{
  char cVar1;
  MListWndPBase MVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  MListWndPBase *pMVar8;
  int iVar9;
  int iVar10;
  DataPc *this;
  DataPcPOD aDStack_60 [44];
  char local_34 [8];
  MListWndPBase *local_2c;
  int iStack_28;
  
  iVar4 = msys::MComSys::_sys;
  iVar3 = *(int *)(param_2 + 8);
  if (*(int *)(param_2 + 8) == 0) {
    *(int *)(param_2 + 8) = msys::MComSys::_sys;
    iVar3 = iVar4;
  }
  iVar4 = iVar3 + *(char *)(param_2 + 0x2560) * 0xb0;
  this = (DataPc *)(iVar4 + 0xeac64);
  local_2c = param_1;
  iStack_28 = param_2;
  iVar5 = DataPc::getAcquireRankUpBonusNum(this);
  uVar7 = 0;
  if (iVar5 != 0) {
    pMVar8 = local_2c + 0x6f80;
    *(char *)(*(int *)(local_2c + 0x154) + 0x144) = (char)iVar5;
    DataPc::write(this,aDStack_60);
    iVar9 = 0;
    iVar6 = 0;
    if (0 < iVar5) {
      do {
        iVar10 = iVar6;
        cVar1 = local_34[iVar10];
        if (cVar1 == '\0') goto joined_r0x1500f390;
        do {
          iVar6 = ad::db::GetPcRankUpBonus(cVar1);
          iVar9 = iVar9 + 1;
          pMVar8[9] = SUB41(iVar9,0);
          uVar7 = LMS_GetTextIndexByLabel(iVar3 + 0xeaefc,*(undefined4 *)(iVar6 + 4));
          uVar7 = LMS_GetText(iVar3 + 0xeaefc,uVar7);
          *(undefined4 *)(pMVar8 + 0x10) = uVar7;
          *(undefined4 *)(pMVar8 + 0x14) = 0;
          uVar7 = LMS_GetTextIndexByLabel(iVar3 + 0xeaefc,*(undefined4 *)(iVar6 + 8));
          uVar7 = LMS_GetText(iVar3 + 0xeaefc,uVar7);
          *(undefined4 *)(pMVar8 + 0x18) = uVar7;
          pMVar8[0xe] = (MListWndPBase)0x1;
          pMVar8[0xf] = (MListWndPBase)0x0;
          if (*(byte *)(iVar4 + 0xeac98) < 2) {
            if (5 < iVar9) {
              MVar2 = (MListWndPBase)0x5;
              goto LAB_1500f414;
            }
          }
          else {
            if (4 < iVar9) {
              pMVar8[9] = (MListWndPBase)0x4;
            }
            MVar2 = (MListWndPBase)((char)pMVar8[9] + '\x06');
LAB_1500f414:
            pMVar8[9] = MVar2;
          }
          pMVar8 = pMVar8 + 0x1c;
          if (iVar5 <= iVar9) goto LAB_1500f424;
joined_r0x1500f390:
          cVar1 = '\0';
          iVar6 = iVar10 + 1;
        } while (5 < iVar6);
      } while( true );
    }
LAB_1500f424:
    msys::MListWndPBase::resetCur(local_2c);
    uVar7 = 1;
  }
  return uVar7;
}


// FUNC 0x1500f458 FUN_1500f458 (MainMenu)
//   size 0x170 | file MainMenu+0xf458 | callers(2) 0x1501ece8 0x1500fb18

void FUN_1500f458(MMsg *param_1,uint param_2)

{
  wchar_t *pwVar1;
  LytAnim *this;
  int iVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  uint in_fpscr;
  float fVar6;
  
  if (param_2 == 0) {
    iVar2 = msys::MLyt::getPane((MLyt *)(*(int *)(param_1 + 0x6c44) + 0x4b8),"EXP_PNL_U",(char *)0x0
                                ,(char *)0x0);
    bVar3 = *(byte *)(iVar2 + 0x44) & 0xfe;
  }
  else {
    if ((param_2 & 0xf000) == 0x2000) {
      iVar2 = ad::db::GetEquip((ushort)param_2);
      pwVar1 = (wchar_t *)ad::db::GetItemMsgCore((char *)(iVar2 + 0x30));
      msys::MMsg::playStr(param_1,pwVar1,(InsParam *)0x0,false);
      iVar5 = 0;
      do {
        iVar4 = (int)*(short *)(iVar2 + iVar5 * 2 + 0x6c);
        if (iVar4 == 0) {
          *(undefined4 *)(param_1 + iVar5 * 0x230 + 0x6e28) = 0xb;
          *(undefined4 *)(param_1 + iVar5 * 0x230 + 0x6e34) = 0xb;
          *(undefined4 *)(param_1 + iVar5 * 0x230 + 0x6e40) = 0xb;
        }
        else {
          ad::lyt::LytNumReel3::setValueInstant
                    ((LytNumReel3 *)(param_1 + iVar5 * 0x230 + 0x6e08),iVar4);
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < 6);
      fVar6 = (float)VectorUnsignedToFloat
                               ((uint)*(byte *)(iVar2 + 0x6b),(byte)(in_fpscr >> 0x16) & 3);
      ad::lyt::LytAnim::stopAndSetFrm((LytAnim *)(param_1 + 0x6c9c),fVar6);
      this = (LytAnim *)(param_1 + 0x6c48);
    }
    else {
      pwVar1 = (wchar_t *)ad::db::GetItemMsg(param_2,2);
      msys::MMsg::playStr(param_1,pwVar1,(InsParam *)0x0,false);
      this = (LytAnim *)(param_1 + 0x6c64);
    }
    ad::lyt::LytAnim::stopAndSetFrm(this,0.0);
    iVar2 = msys::MLyt::getPane((MLyt *)(*(int *)(param_1 + 0x6c44) + 0x4b8),"EXP_PNL_U",(char *)0x0
                                ,(char *)0x0);
    bVar3 = *(byte *)(iVar2 + 0x44) & 0xfe | 1;
  }
  *(byte *)(iVar2 + 0x44) = bVar3;
  return;
}


// FUNC 0x1500f5d8 FUN_1500f5d8 (MainMenu)
//   size 0x3c4 | file MainMenu+0xf5d8 | callers(4) 0x1501ece8 0x15020134 0x1501fd94 0x1501f68c

void FUN_1500f5d8(int param_1)

{
  char *pcVar1;
  wchar_t *pwVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  byte bVar6;
  int iVar7;
  int iVar8;
  uint in_fpscr;
  float fVar9;
  MLyt *local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined2 local_3c;
  undefined2 local_3a;
  
  iVar8 = (int)*(char *)(param_1 + 0x2560);
  local_4c = 0;
  local_48 = 0x3f800000;
  local_44 = 0;
  local_40 = 1;
  ad::lyt::LytAnim::init((LytAnim *)&local_50,*(Layout **)(param_1 + 0x608),"SET_MLK","");
  fVar9 = (float)VectorSignedToFloat(iVar8,(byte)(in_fpscr >> 0x16) & 3);
  ad::lyt::LytAnim::stopAndSetFrm((LytAnim *)&local_50,fVar9);
  ad::lyt::LytAnim::term((LytAnim *)&local_50,true);
  *(undefined1 *)(param_1 + 0x2c9a1) = 0xff;
  local_44 = 0;
  local_50 = (MLyt *)(param_1 + 0x4b8);
  iVar7 = 0;
  do {
    if ((&DAT_003f9610)[iVar7 + iVar8 * 0x1a] == 0) {
      pwVar2 = (wchar_t *)ad::db::GetItemMsgCore("N_None");
      msys::MMsg::playStr((MMsg *)(param_1 + iVar7 * 0x6c44 + 0x1185c),pwVar2,(InsParam *)0x0,false)
      ;
      iVar3 = msys::MLyt::getPane(local_50,"INS_ICON_OBJ",(char *)(&DAT_150361dc)[iVar7],(char *)0x0
                                 );
      bVar6 = *(byte *)(iVar3 + 0x44) & 0xfe;
    }
    else {
      pcVar1 = (char *)ad::db::GetEquip((&DAT_003f9610)[iVar7 + iVar8 * 0x1a]);
      pwVar2 = (wchar_t *)ad::db::GetItemMsgCore(pcVar1);
      msys::MMsg::playStr((MMsg *)(param_1 + iVar7 * 0x6c44 + 0x1185c),pwVar2,(InsParam *)0x0,false)
      ;
      CellAnime::play((CellAnime *)(param_1 + iVar7 * 0x27c + 0x11234),pcVar1[0x60] + '\x01',0,1.0);
      iVar3 = msys::MLyt::getPane(local_50,"INS_ICON_OBJ",(char *)(&DAT_150361dc)[iVar7],(char *)0x0
                                 );
      bVar6 = *(byte *)(iVar3 + 0x44) & 0xfe | 1;
    }
    *(byte *)(iVar3 + 0x44) = bVar6;
    piVar4 = *(int **)(param_1 + iVar7 * 4 + 0x2c96c);
    (**(code **)(*piVar4 + 0x28))(piVar4,1);
    iVar7 = iVar7 + 1;
  } while (iVar7 < 3);
  if (iVar8 == 2) {
    if (*(char *)(param_1 + 0x2c9a0) == '\x03') {
      *(undefined1 *)(param_1 + 0x2c9a0) = 2;
    }
    (**(code **)(**(int **)(param_1 + 0x2c978) + 0x28))(*(int **)(param_1 + 0x2c978),0);
  }
  else {
    if (*(int *)(param_1 + 8) == 0) {
      *(undefined4 *)(param_1 + 8) = msys::MComSys::_sys;
    }
    fVar9 = (float)GetRegFlag(0xd00c,(GlobalEvent *)0x0,(LocalEvent *)0x0);
    in_fpscr = in_fpscr & 0xfffffff;
    if (fVar9 == 0.0) {
      if (*(char *)(param_1 + 0x2c9a0) == '\x03') {
        *(undefined1 *)(param_1 + 0x2c9a0) = 2;
      }
      (**(code **)(**(int **)(param_1 + 0x2c978) + 0x28))(*(int **)(param_1 + 0x2c978),0);
      iVar7 = msys::MLyt::getParts(local_50,DAT_150361e8,(char *)0x0,(char *)0x0);
      *(byte *)(iVar7 + 0x44) = *(byte *)(iVar7 + 0x44) & 0xfe;
      iVar7 = msys::MLyt::getPane(local_50,"SET_BADGE",(char *)0x0,(char *)0x0);
      *(byte *)(iVar7 + 0x44) = *(byte *)(iVar7 + 0x44) & 0xfe;
    }
    else {
      pwVar2 = (wchar_t *)ad::db::GetItemMsg((&DAT_003f9616)[iVar8 * 0x1a],0);
      msys::MMsg::playStr((MMsg *)(param_1 + 0x25d28),pwVar2,(InsParam *)0x0,false);
      local_48 = 0;
      local_44 = 0x3f800000;
      local_40 = 0;
      local_3c = 1;
      local_3a = 0;
      ad::lyt::LytAnim::init((LytAnim *)&local_4c,*(Layout **)(param_1 + 0x608),"SET_BADGE","");
      fVar9 = (float)VectorUnsignedToFloat
                               ((ushort)(&DAT_003f9616)[iVar8 * 0x1a] & 0xffff0fff,
                                (byte)(in_fpscr >> 0x16) & 3);
      ad::lyt::LytAnim::stopAndSetFrm((LytAnim *)&local_4c,fVar9);
      ad::lyt::LytAnim::term((LytAnim *)&local_4c,true);
      local_40 = 0;
      (**(code **)(**(int **)(param_1 + 0x2c978) + 0x28))(*(int **)(param_1 + 0x2c978),1);
      iVar7 = msys::MLyt::getParts(local_50,DAT_150361e8,(char *)0x0,(char *)0x0);
      *(byte *)(iVar7 + 0x44) = *(byte *)(iVar7 + 0x44) & 0xfe | 1;
      iVar7 = msys::MLyt::getPane(local_50,"SET_BADGE",(char *)0x0,(char *)0x0);
      *(byte *)(iVar7 + 0x44) = *(byte *)(iVar7 + 0x44) & 0xfe | 1;
    }
  }
  FUN_1500fb18(param_1);
  uVar5 = FUN_1500f2c8(param_1 + 0x9f3c,param_1);
  iVar7 = msys::MLyt::getParts(local_50,DAT_150361f4,(char *)0x0,(char *)0x0);
  *(byte *)(iVar7 + 0x44) = *(byte *)(iVar7 + 0x44) & 0xfe | (byte)uVar5;
                    /* WARNING: Could not recover jumptable at 0x1500f9e8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(param_1 + 0x2c984) + 0x28))(*(int **)(param_1 + 0x2c984),uVar5);
  return;
}


// FUNC 0x1500f9ec FUN_1500f9ec (MainMenu)
//   size 0x118 | file MainMenu+0xf9ec | callers(2) 0x1501f68c 0x1501fd94

undefined4 FUN_1500f9ec(int param_1,uint *param_2,int param_3)

{
  char cVar1;
  char cVar2;
  undefined4 local_30 [4];
  
  if ((*param_2 & 0x200) == 0) {
    if ((*param_2 & 0x100) == 0 || param_3 == 0) {
      return 0;
    }
    if (DAT_003fbea4 >> 8 < 20000) {
      cVar1 = '\x02';
    }
    else {
      cVar1 = '\x03';
    }
    local_30[0] = 1;
    local_30[1] = 0;
    local_30[2] = 2;
    cVar2 = *(char *)(param_1 + 0x1cf9) + '\x01';
    *(char *)(param_1 + 0x1cf9) = cVar2;
    if (-1 < cVar2) {
      if (cVar2 < cVar1) goto LAB_1500fabc;
      goto LAB_1500fa70;
    }
  }
  else {
    if (param_3 == 0) {
      return 0;
    }
    if (DAT_003fbea4 >> 8 < 20000) {
      cVar1 = '\x02';
    }
    else {
      cVar1 = '\x03';
    }
    local_30[0] = 1;
    local_30[1] = 0;
    local_30[2] = 2;
    cVar2 = *(char *)(param_1 + 0x1cf9) + -1;
    *(char *)(param_1 + 0x1cf9) = cVar2;
    if (-1 < cVar2) {
      if (cVar2 < cVar1) goto LAB_1500fabc;
LAB_1500fa70:
      *(undefined1 *)(param_1 + 0x1cf9) = 0;
      goto LAB_1500fabc;
    }
  }
  *(char *)(param_1 + 0x1cf9) = cVar1 + -1;
LAB_1500fabc:
  local_30[2] = 2;
  local_30[1] = 0;
  local_30[0] = 1;
  *(undefined1 *)(param_1 + 0x1cf8) = *(undefined1 *)(local_30 + *(char *)(param_1 + 0x1cf9));
  FUN_1500fc98();
  local_30[0] = 0;
  FUN_1501580c(msys::MComSys::_sys + 0x49368,0x110016,0,0);
  return 1;
}


// FUNC 0x1500fb18 FUN_1500fb18 (MainMenu)
//   size 0xf0 | file MainMenu+0xfb18 | callers(3) 0x1500f5d8 0x15020134 0x1501f68c

void FUN_1500fb18(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint in_fpscr;
  float fVar5;
  LytAnim aLStack_48 [4];
  undefined4 local_44;
  undefined4 uStack_40;
  undefined4 local_3c;
  undefined2 local_38;
  undefined2 local_36;
  
  iVar3 = 0;
  iVar4 = (int)*(char *)(param_1 + 0x2c9a0);
  do {
    iVar2 = msys::MLyt::getParts
                      ((MLyt *)(param_1 + 0x4b8),(char *)(&DAT_150361dc)[iVar3],(char *)0x0,
                       (char *)0x0);
    local_44 = 0;
    uStack_40 = 0x3f800000;
    local_3c = 0;
    local_38 = 1;
    local_36 = 0;
    ad::lyt::LytAnim::init(aLStack_48,*(Layout **)(iVar2 + 0xac),"SET_COL","");
    fVar5 = (float)VectorUnsignedToFloat((uint)(iVar4 == iVar3),(byte)(in_fpscr >> 0x16) & 3);
    ad::lyt::LytAnim::stopAndSetFrm(aLStack_48,fVar5);
    ad::lyt::LytAnim::term(aLStack_48,true);
    iVar3 = iVar3 + 1;
    local_3c = 0;
  } while (iVar3 < 4);
  if (iVar4 < 3) {
    uVar1 = (&DAT_003f9610)[iVar4 + *(char *)(param_1 + 0x2560) * 0x1a];
  }
  else {
    uVar1 = (&DAT_003f9616)[*(char *)(param_1 + 0x2560) * 0x1a];
  }
  FUN_1500f458(param_1 + 0x2564,uVar1);
  return;
}


// FUNC 0x1500fc2c FUN_1500fc2c (MainMenu)
//   size 0x64 | file MainMenu+0xfc2c | callers(6) 0x1501ece8 0x15020134 0x1501fd00 0x1501ff48 0x1501f68c 0x1501fd94

void FUN_1500fc2c(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = msys::MComSys::_sys;
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  *(bool *)(*(int *)(param_1 + 8) + 0xe6508) = SUB41(param_2,0);
  iVar2 = *(int *)(param_1 + 8);
  if (iVar2 == 0) {
    *(int *)(param_1 + 8) = iVar1;
    iVar2 = iVar1;
  }
  *(undefined1 *)(iVar2 + 0xe650a) = 1;
  if ((param_2 == 0) || (*(char *)(param_1 + 0xa07d) != '\0')) {
    msys::MListWndPBase::setEnableInput((MListWndPBase *)(param_1 + 0x9f3c),SUB41(param_2,0));
    return;
  }
  return;
}


// FUNC 0x1500fc98 FUN_1500fc98 (MainMenu)
//   size 0x3e4 | file MainMenu+0xfc98 | callers(2) 0x1500f9ec 0x1501f198

void FUN_1500fc98(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  DataPc *this;
  uint in_fpscr;
  float fVar7;
  LytAnim local_48 [4];
  undefined4 local_44;
  undefined4 uStack_40;
  undefined4 local_3c;
  undefined2 local_38;
  undefined2 local_36;
  undefined4 local_34;
  undefined4 local_30;
  
  iVar1 = msys::MComSys::_sys;
  iVar4 = *(int *)(*param_1 + 8);
  if (iVar4 == 0) {
    *(int *)(*param_1 + 8) = msys::MComSys::_sys;
    iVar4 = iVar1;
  }
  this = (DataPc *)(iVar4 + (char)param_1[0x73e] * 0xb0 + 0xeac64);
  iVar1 = DataPc::getLv(this);
  iVar4 = DataPc::getExpNextLv(this);
  local_48[0] = (LytAnim)0x0;
  local_44 = 0;
  uStack_40 = 0x3f800000;
  local_3c = 0;
  local_38 = 1;
  local_36 = 0;
  local_34 = 0;
  local_30 = 0;
  ad::lyt::LytAnim::init(local_48,*(Layout **)(*param_1 + 0x260),"SET_MLK","");
  fVar7 = (float)VectorSignedToFloat((int)(char)param_1[0x73e],(byte)(in_fpscr >> 0x16) & 3);
  ad::lyt::LytAnim::stopAndSetFrm(local_48,fVar7);
  ad::lyt::LytAnim::term(local_48,true);
  ad::lyt::LytAnim::init(local_48,*(Layout **)(*param_1 + 0x260),"SET_LV_DIGIT","");
  fVar7 = (float)VectorUnsignedToFloat((uint)(9 < iVar1),(byte)(in_fpscr >> 0x16) & 3);
  ad::lyt::LytAnim::stopAndSetFrm(local_48,fVar7);
  ad::lyt::LytAnim::term(local_48,true);
  ad::lyt::LytAnim::init(local_48,*(Layout **)(*param_1 + 0x260),"SET_RANK","");
  uVar2 = DataPc::getRank(this);
  fVar7 = (float)VectorUnsignedToFloat(uVar2,(byte)(in_fpscr >> 0x16) & 3);
  ad::lyt::LytAnim::stopAndSetFrm(local_48,fVar7);
  ad::lyt::LytAnim::term(local_48,true);
  iVar3 = msys::MLyt::getParts((MLyt *)(*param_1 + 0x110),"CHARA_PANEL",(char *)0x0,(char *)0x0);
  ad::lyt::LytAnim::init
            (local_48,*(Layout **)(iVar3 + 0xac),
             *(char **)(&DAT_150363d8 + (char)param_1[0x73e] * 4),"");
  ad::lyt::LytAnim::stopAndSetFrm(local_48,0.0);
  ad::lyt::LytAnim::term(local_48,true);
  local_3c = 0;
  CellAnime::term((CellAnime *)(param_1 + 0x6e4));
  msys::MCellAnime::init
            ((MCellAnime *)(param_1 + 0x691),
             (Resource *)((char)param_1[0x73e] * 0x44 + 0x10fd8 + *param_1));
  CellAnime::play((CellAnime *)(param_1 + 0x6e4),(&DAT_15037014)[(char)param_1[0x73e] * 4],0,1.0);
  iVar3 = VectorSignedToFloat(*(undefined4 *)(&DAT_15037008 + (char)param_1[0x73e] * 4),
                              (byte)(in_fpscr >> 0x16) & 3);
  MoveVBase::stop((MoveVBase *)(param_1 + 0x6c4));
  param_1[0x6cb] = 0;
  param_1[0x6cc] = iVar3;
  param_1[0x6cd] = 0;
  param_1[0x6c5] = param_1[0x6cb];
  param_1[0x6c6] = iVar3;
  param_1[0x6c7] = 0;
  ad::lyt::LytNumReel3::setValueInstant((LytNumReel3 *)(param_1 + 0x55),iVar1 % 10);
  ad::lyt::LytNumReel3::setValueInstant((LytNumReel3 *)(param_1 + 0xe1),iVar1 / 10);
  *(bool *)((int)param_1 + 0x375) = 0 < param_1[0x100];
  iVar1 = DataPc::getHpNow(this);
  ad::lyt::LytNumReel3::setValueInstant((LytNumReel3 *)(param_1 + 0x16d),iVar1);
  iVar1 = DataPc::getHpMax(this);
  ad::lyt::LytNumReel3::setValueInstant((LytNumReel3 *)(param_1 + 0x1f9),iVar1);
  iVar1 = DataPc::getBpNow(this);
  ad::lyt::LytNumReel3::setValueInstant((LytNumReel3 *)(param_1 + 0x285),iVar1);
  iVar1 = DataPc::getBpMax(this);
  ad::lyt::LytNumReel3::setValueInstant((LytNumReel3 *)(param_1 + 0x311),iVar1);
  iVar1 = DataPc::getPow(this);
  ad::lyt::LytNumReel3::setValueInstant((LytNumReel3 *)(param_1 + 0x39d),iVar1);
  iVar1 = DataPc::getDef(this);
  ad::lyt::LytNumReel3::setValueInstant((LytNumReel3 *)(param_1 + 0x429),iVar1);
  iVar1 = DataPc::getSpd(this);
  ad::lyt::LytNumReel3::setValueInstant((LytNumReel3 *)(param_1 + 0x4b5),iVar1);
  iVar1 = DataPc::getHige(this);
  ad::lyt::LytNumReel3::setValueInstant((LytNumReel3 *)(param_1 + 0x541),iVar1);
  iVar1 = DataPc::getExpNow(this);
  ad::lyt::LytNumReel3::setValueInstant((LytNumReel3 *)(param_1 + 0x5cd),iVar1);
  if (iVar4 != 0) {
    ad::lyt::LytNumReel3::setValueInstant((LytNumReel3 *)(param_1 + 0x659),iVar4);
    return;
  }
  uVar5 = 1;
  do {
    uVar6 = uVar5 & 0xff;
    uVar5 = uVar5 + 1;
    param_1[uVar6 * 3 + 0x661] = 10;
  } while ((int)uVar5 < 8);
  param_1[0x661] = 0xb;
  return;
}


// FUNC 0x15010740 FUN_15010740 (MainMenu)
//   size 0x94 | file MainMenu+0x10740 | callers(2) 0x150231f4 0x1501e420

int FUN_15010740(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)FUN_150159f4();
  *puVar1 = &msys::MMsgWnd::vtable;
  iVar2 = Message::Message((Message *)(puVar1 + 0x53));
  *(undefined4 *)(iVar2 + 28000) = 0;
  *(undefined4 *)(iVar2 + 0x6d64) = 0x400;
  *(undefined4 *)(iVar2 + 0x6d68) = 0;
  *(undefined4 *)(iVar2 + 0x6d6c) = 0;
  *(undefined4 *)(iVar2 + 0x6d70) = 0;
  *(undefined4 *)(iVar2 + 0x6d74) = 0;
  *(undefined4 *)(iVar2 + 0x6d78) = 6;
  *(undefined4 *)(iVar2 + 0x6d7c) = 0;
  *(undefined1 *)(iVar2 + 0x6d80) = 0;
  *(undefined4 *)(iVar2 + 0x6d84) = 0;
  *(undefined4 *)(iVar2 + 0x6d88) = 0;
  *(undefined1 *)(iVar2 + 0x6d8c) = 1;
  *(undefined1 *)(iVar2 + 0x6d8d) = 0;
  *(undefined1 *)(iVar2 + 0x6d8e) = 0;
  *(undefined4 *)(iVar2 + 0x6d98) = 0x110004;
  *(undefined4 *)(iVar2 + 0x6d90) = 0;
  *(undefined4 *)(iVar2 + 0x6d94) = 0x110003;
  *(undefined4 *)(iVar2 + 0x6da0) = 0;
  *(undefined4 *)(iVar2 + 0x6da4) = 0;
  *(undefined4 *)(iVar2 + 0x6da8) = 0x400;
  return iVar2 + -0x14c;
}


// FUNC 0x150107e0 main_menu::MainMenu_RecordPage::Core::MListWndRecord::vfunc_0x0 (MainMenu)
//   size 0x88 | file MainMenu+0x107e0 | callers(2) 0x1501c058 0x1501e89c | datarefs 1

void main_menu::MainMenu_RecordPage::Core::MListWndRecord::vfunc_0x0(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &vtable;
  iVar1 = CellAnime::~CellAnime((CellAnime *)(param_1 + 0x1df4));
  iVar1 = CellAnime::~CellAnime((CellAnime *)(iVar1 + -300));
  iVar1 = CellAnime::~CellAnime((CellAnime *)(iVar1 + -300));
  *(undefined4 *)(iVar1 + -0x90) = 0;
  *(undefined4 *)(iVar1 + -0xac) = 0;
  *(undefined4 *)(iVar1 + -200) = 0;
  iVar1 = ad::lyt::Layout::~Layout((Layout *)(iVar1 + -0x110));
  *(undefined4 *)(iVar1 + -0x10) = 0;
  *(undefined4 *)(iVar1 + -0x2c) = 0;
  *(undefined4 *)(iVar1 + -0x48) = 0;
  *(undefined4 *)(iVar1 + -100) = 0;
  *(undefined4 *)(iVar1 + -0x80) = 0;
  iVar1 = ad::lyt::Layout::~Layout((Layout *)(iVar1 + -200));
  iVar1 = ad::lyt::Layout::~Layout((Layout *)(iVar1 + -0x3c));
  *(undefined ***)(iVar1 + -0x7364) = &vtable_for_N4msys17MListWndPFractionILi32EEE;
  iVar1 = ad::ui::UIListWindowPlusLyt::~UIListWindowPlusLyt
                    ((UIListWindowPlusLyt *)(iVar1 + -0x7168));
  msys::MListWndPBase::~MListWndPBase((MListWndPBase *)(iVar1 + -0x1fc));
  return;
}


// FUNC 0x15010874 FUN_15010874 (MainMenu)
//   size 0x20c | file MainMenu+0x10874 | callers(2) 0x1501b024 0x1501b204

void FUN_15010874(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  wchar_t *pwVar5;
  uint in_fpscr;
  undefined4 uVar6;
  undefined4 uVar7;
  MessageSimple *local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 uStack_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 local_60;
  undefined1 local_5c;
  undefined1 local_5b;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined1 local_48;
  undefined1 local_47;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined1 local_38;
  undefined1 local_37;
  undefined4 local_34;
  
  uVar6 = *(undefined4 *)(param_1 + 0x3f10c);
  uVar7 = *(undefined4 *)(param_1 + 0x3f110);
  local_8c = 0;
  local_88 = 0;
  local_78 = 0;
  local_74 = 0;
  local_70 = 0;
  local_84 = 0xc1000000;
  local_80 = 0x42000000;
  local_7c = 0x41000000;
  local_60 = 0;
  local_6c = 0xc1000000;
  uStack_68 = 0x42000000;
  uStack_64 = 0x41000000;
  local_9c = 0xc3480000;
  local_98 = 0x42f00000;
  local_94 = 0x43480000;
  uStack_90 = 0xc2f00000;
  local_5c = 5;
  local_5b = 8;
  local_58 = 0x45800000;
  local_54 = 0xc1a00000;
  local_50 = 0;
  local_4c = 0;
  local_48 = 0;
  local_47 = 0;
  local_a0 = (MessageSimple *)(param_1 + 0x38250);
  uVar2 = Grp::GetLcdWidth(0x401);
  uVar3 = Grp::GetLcdHeight(0x401);
  local_9c = VectorSignedToFloat((int)-uVar2 / 2,(byte)(in_fpscr >> 0x16) & 3);
  local_98 = VectorUnsignedToFloat(uVar3 >> 1,(byte)(in_fpscr >> 0x16) & 3);
  uStack_90 = VectorSignedToFloat((int)-uVar3 / 2,(byte)(in_fpscr >> 0x16) & 3);
  local_94 = VectorUnsignedToFloat(uVar2 >> 1,(byte)(in_fpscr >> 0x16) & 3);
  local_84 = 0xc1700000;
  local_80 = 0x42200000;
  local_7c = 0x41700000;
  local_78 = 0;
  local_48 = 0;
  local_8c = uVar6;
  local_88 = uVar7;
  MsgWndPosCalculator::calc((MsgWndPosCalculator *)&local_a0,(Result *)&local_40);
  uVar6 = *(undefined4 *)(param_1 + 0x381dc);
  MoveVBase::stop((MoveVBase *)(param_1 + 0x381d0));
  *(undefined4 *)(param_1 + 0x381f4) = uVar6;
  *(undefined4 *)(param_1 + 0x381ec) = local_40;
  *(undefined4 *)(param_1 + 0x381f0) = uStack_3c;
  *(undefined4 *)(param_1 + 0x381dc) = uVar6;
  *(undefined4 *)(param_1 + 0x381d4) = local_40;
  *(undefined4 *)(param_1 + 0x381d8) = uStack_3c;
  *(undefined1 *)(param_1 + 0x3da92) = local_37;
  iVar1 = msys::MComSys::_sys;
  iVar4 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar4 = iVar1;
  }
  uVar6 = LMS_GetTextIndexByLabel(iVar4 + 0xeae90,*(undefined4 *)(param_1 + 0x3effc));
  pwVar5 = (wchar_t *)LMS_GetText(iVar4 + 0xeae90,uVar6);
  uVar6 = MessageSimple::getMsgHeight((MessageSimple *)(param_1 + 0x38250),pwVar5);
  uVar2 = VectorFloatToUnsigned(uVar6,3);
  if (uVar2 < 0x47) {
    *(undefined4 *)(param_1 + 0x3da94) = local_34;
  }
  else {
    *(undefined4 *)(param_1 + 0x3da94) = 0x42200000;
    local_38 = 3;
  }
  *(undefined1 *)(param_1 + 0x3da91) = local_38;
  return;
}


// FUNC 0x15010ac4 FUN_15010ac4 (MainMenu)
//   size 0xcc | file MainMenu+0x10ac4 | callers(3) 0x1501aac0 0x1501a650 0x1501ccd8

void FUN_15010ac4(int param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint in_fpscr;
  uint uVar4;
  float fVar5;
  
  fVar5 = (float)VectorUnsignedToFloat(param_2 >> 0xc,(byte)(in_fpscr >> 0x16) & 3);
  ad::lyt::LytAnim::stopAndSetFrm((LytAnim *)(param_1 + 0x3f5b0),fVar5);
  fVar5 = (float)GetRegFlag((&DAT_15024a2c)[(param_2 >> 0xc) * 0xc],(GlobalEvent *)0x0,
                            (LocalEvent *)0x0);
  uVar4 = in_fpscr & 0xfffffff;
  if ((fVar5 == 0.0) &&
     (((param_2 & 0x3ff) != 0x3ff ||
      (iVar1 = main_menu::GetBootInfo(), *(char *)(iVar1 + 0x2c) != '\0')))) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  fVar5 = (float)VectorUnsignedToFloat(uVar2,(byte)(uVar4 >> 0x16) & 3);
  ad::lyt::LytAnim::stopAndSetFrm((LytAnim *)(param_1 + 0x3f5cc),fVar5);
  uVar3 = 0;
  do {
    fVar5 = (float)VectorUnsignedToFloat(param_2 >> uVar3 & 1,(byte)(uVar4 >> 0x16) & 3);
    ad::lyt::LytAnim::stopAndSetFrm((LytAnim *)(param_1 + uVar3 * 0x1c + 0x3f5e8),fVar5);
    uVar3 = uVar3 + 1 & 0xff;
  } while (uVar3 < 10);
  return;
}


// FUNC 0x15010b9c FUN_15010b9c (MainMenu)
//   size 0x934 | file MainMenu+0x10b9c | callers(3) 0x1501a650 0x1501aac0 0x1501afac

undefined4 FUN_15010b9c(MListWndPBase *param_1,int param_2)

{
  uint uVar1;
  char cVar2;
  byte bVar3;
  ushort uVar4;
  bool bVar5;
  MListWndPBase MVar6;
  short sVar7;
  short sVar8;
  ushort *puVar9;
  ushort *puVar10;
  int iVar11;
  short *psVar12;
  undefined4 *puVar13;
  uint uVar14;
  undefined4 uVar15;
  int iVar16;
  undefined **ppuVar17;
  ushort uVar18;
  int iVar19;
  MListWndPBase *pMVar20;
  MListWndPBase *pMVar21;
  ushort *puVar22;
  MListWndPBase *pMVar23;
  undefined ***pppuVar24;
  uint uVar25;
  uint uVar26;
  float fVar27;
  uint local_48;
  undefined **local_44;
  MListWndPBase *local_40;
  undefined4 local_3c;
  undefined4 local_38;
  int local_34;
  
  local_38 = 0;
  Mem::Fill(param_1 + 0x74f8,0,0x40);
  Mem::Fill(param_1 + 0x7538,0,0x40);
  pMVar20 = param_1 + 0x6fa0;
  pMVar23 = param_1 + 0x7320;
  switch(param_2) {
  case 0:
  case 1:
    uVar14 = 0;
    iVar11 = msys::GetRecodAreaNoListNum();
    if (iVar11 != 0) {
      do {
        iVar11 = msys::GetRecodAreaNoList();
        iVar11 = msys::GetBlkHlwFlagNoList
                           (param_1 + uVar14 * 2 + 0x74f8,*(undefined1 *)(iVar11 + uVar14),
                            param_2 != 0);
        uVar25 = 0;
        if (*(short *)(param_1 + uVar14 * 2 + 0x74f8) != 0) {
          do {
            fVar27 = (float)GetRegFlag(*(short *)(iVar11 + uVar25 * 2) + 0xd060,(GlobalEvent *)0x0,
                                       (LocalEvent *)0x0);
            if (fVar27 != 0.0) {
              *(short *)(param_1 + uVar14 * 2 + 0x7538) =
                   *(short *)(param_1 + uVar14 * 2 + 0x7538) + 1;
            }
            uVar25 = uVar25 + 1;
          } while (uVar25 < *(ushort *)(param_1 + uVar14 * 2 + 0x74f8));
        }
        uVar14 = uVar14 + 1;
        uVar25 = msys::GetRecodAreaNoListNum();
      } while (uVar14 < uVar25);
    }
    iVar11 = msys::MListWndPBase::getListWnd(param_1);
    uVar14 = 0;
    *(undefined1 *)(iVar11 + 0x144) = 0;
    iVar11 = msys::GetRecodAreaNoListNum();
    if (iVar11 == 0) {
      return local_38;
    }
    do {
      iVar11 = msys::GetRecodAreaNoList();
      bVar3 = *(byte *)(iVar11 + uVar14);
      iVar11 = msys::MListWndPBase::getListWnd(param_1);
      uVar25 = (uint)*(byte *)(iVar11 + 0x144);
      param_1[uVar25 * 0x1c + 0x6fab] = (MListWndPBase)0xff;
      param_1[uVar25 * 0x1c + 0x6fac] = (MListWndPBase)0xff;
      if ((((&DAT_15024b0c)[uVar14] == 0) ||
          (fVar27 = (float)GetRegFlag((ushort)(&DAT_15024b0c)[uVar14],(GlobalEvent *)0x0,
                                      (LocalEvent *)0x0), fVar27 != 0.0)) &&
         (*(short *)(param_1 + uVar14 * 2 + 0x74f8) != 0)) {
        param_1[uVar25 * 0x1c + 0x6fae] = (MListWndPBase)0x1;
        *(uint *)(param_1 + uVar25 * 0x1c + 0x6fa0) = (uint)bVar3;
        *(undefined2 *)(param_1 + uVar25 * 0x1c + 0x6fa4) =
             *(undefined2 *)(param_1 + uVar14 * 2 + 0x74f8);
        *(undefined2 *)(param_1 + uVar25 * 2 + 0x7320) =
             *(undefined2 *)(param_1 + uVar14 * 2 + 0x7538);
        iVar11 = msys::MComSys::_sys;
        iVar19 = *(int *)(*(int *)(param_1 + 0x7360) + 8);
        if (iVar19 == 0) {
          *(int *)(*(int *)(param_1 + 0x7360) + 8) = msys::MComSys::_sys;
          iVar19 = iVar11;
        }
        uVar15 = LMS_GetTextIndexByLabel
                           (iVar19 + 0xeae90,(&PTR_s_MES_EMesPlace_place2_15036138)[uVar14]);
        uVar15 = LMS_GetText(iVar19 + 0xeae90,uVar15);
        *(undefined4 *)(param_1 + uVar25 * 0x1c + 0x6fb0) = uVar15;
        if (*(short *)(param_1 + uVar14 * 2 + 0x74f8) == *(short *)(param_1 + uVar14 * 2 + 0x7538))
        {
          MVar6 = (MListWndPBase)0x0;
        }
        else if (param_2 == 0) {
          MVar6 = (MListWndPBase)0xb;
        }
        else {
          MVar6 = (MListWndPBase)0xa;
        }
        param_1[uVar25 * 0x1c + 0x6fa9] = MVar6;
        iVar11 = msys::MListWndPBase::getListWnd(param_1);
        *(char *)(iVar11 + 0x144) = *(char *)(iVar11 + 0x144) + '\x01';
      }
      uVar14 = uVar14 + 1 & 0xff;
      uVar25 = msys::GetRecodAreaNoListNum();
    } while (uVar14 < uVar25);
    return local_38;
  case 2:
    uVar14 = 0;
    local_48 = 0;
    break;
  case 3:
    local_40 = (MListWndPBase *)&DAT_003f9dc0;
    local_44 = (undefined **)&DAT_003f9dd4;
    iVar11 = msys::MListWndPBase::getListWnd(param_1);
    iVar19 = 0;
    *(undefined1 *)(iVar11 + 0x144) = 10;
    do {
      psVar12 = (short *)((int)local_40 + iVar19 * 2);
      iVar11 = iVar19;
      while( true ) {
        cVar2 = *(char *)(*(int *)(param_1 + 0x7360) + iVar11 + 0x874);
        *(undefined2 *)pMVar23 = 0xffff;
        pMVar20[0xb] = (MListWndPBase)0xff;
        pMVar20[8] = (MListWndPBase)0xff;
        pMVar20[9] = (MListWndPBase)0xff;
        puVar13 = (undefined4 *)ad::db::GetPcAttack((&DAT_1502463a)[iVar11 * 4]);
        pMVar20[0xe] = (MListWndPBase)0x1;
        if ((*(uint *)(&DAT_003f97fc + (*(ushort *)((int)puVar13 + 0xe) >> 5 & 0x7fff87f) * 4) >>
             (*(ushort *)((int)puVar13 + 0xe) & 0x1f) & 1) == 0) {
          pMVar20[0xc] = (MListWndPBase)0xff;
          iVar19 = msys::MComSys::_sys;
          iVar16 = *(int *)(*(int *)(param_1 + 0x7360) + 8);
          if (iVar16 == 0) {
            *(int *)(*(int *)(param_1 + 0x7360) + 8) = msys::MComSys::_sys;
            iVar16 = iVar19;
          }
          uVar15 = LMS_GetTextIndexByLabel(iVar16 + 0xeae90,"MES_EMesColosseum_class_0");
          uVar15 = LMS_GetText(iVar16 + 0xeae90,uVar15);
          *(undefined4 *)(pMVar20 + 0x10) = uVar15;
          *(undefined2 *)(pMVar20 + 4) = 0xffff;
        }
        else {
          pMVar20[0xc] = *(MListWndPBase *)(puVar13 + 2);
          iVar19 = ad::db::GetItemMsgAcs();
          uVar15 = LMS_GetTextIndexByLabel(iVar19 + 8,*puVar13);
          uVar15 = LMS_GetText(iVar19 + 8,uVar15);
          *(undefined4 *)(pMVar20 + 0x10) = uVar15;
          if ((cVar2 == '\0') || (sVar8 = *psVar12, *psVar12 < 0)) {
            sVar8 = -1;
          }
          *(short *)(pMVar20 + 4) = sVar8;
        }
        *(int *)pMVar20 = iVar11;
        pMVar21 = pMVar20 + 0x14;
        pMVar20[0xf] = (MListWndPBase)0x0;
        iVar19 = iVar11 + 1;
        pMVar23 = pMVar23 + 2;
        pMVar20 = pMVar20 + 0x1c;
        *(undefined4 *)pMVar21 = 0;
        if (9 < iVar19) {
          return local_38;
        }
        if (iVar19 < 6) break;
        psVar12 = (short *)((int)local_44 + (iVar11 + -5) * 2);
        iVar11 = iVar19;
      }
    } while( true );
  case 4:
    uVar25 = 0;
    local_3c = &DAT_003f9de0;
    local_34 = 0xb;
    *(undefined1 *)(*(int *)(param_1 + 0x154) + 0x144) = 0xb;
    uVar14 = 0;
    local_40 = (MListWndPBase *)&DAT_003f9df4;
    do {
      bVar5 = true;
      local_44 = (undefined **)(local_3c + uVar14);
      bVar3 = *(byte *)(*(int *)(param_1 + 0x7360) + 0x31194);
      uVar26 = uVar25;
      while( true ) {
        *(undefined2 *)pMVar23 = 0xffff;
        pMVar20[0xb] = (MListWndPBase)0xff;
        pMVar20[0xc] = (MListWndPBase)0xff;
        pMVar20[8] = (MListWndPBase)0xff;
        pMVar20[9] = (MListWndPBase)0xff;
        pMVar20[9] = (MListWndPBase)((char)uVar14 + '\x03');
        iVar11 = msys::MComSys::_sys;
        if (bVar5) {
          iVar19 = 0;
        }
        else {
          iVar19 = 10;
        }
        ppuVar17 = local_44;
        if (bVar5) {
          ppuVar17 = &PTR_s_MES_EMesColosseum_class_1_15024684;
        }
        if (!bVar5) {
          ppuVar17 = &PTR_s_MES_EMesColosseum_class_1_150246a0;
        }
        uVar25 = (&DAT_003f9e00)[iVar19 + uVar14 >> 5];
        if (((uint)bVar3 & 1 << uVar14) == 0) {
          pMVar20[9] = (MListWndPBase)0xff;
          iVar11 = msys::MComSys::_sys;
          iVar19 = *(int *)(*(int *)(param_1 + 0x7360) + 8);
          if (iVar19 == 0) {
            *(int *)(*(int *)(param_1 + 0x7360) + 8) = msys::MComSys::_sys;
            iVar19 = iVar11;
          }
          uVar15 = LMS_GetTextIndexByLabel(iVar19 + 0xeae90,"MES_EMesColosseum_class_0");
          uVar15 = LMS_GetText(iVar19 + 0xeae90,uVar15);
          *(undefined4 *)(pMVar20 + 0x10) = uVar15;
          *(undefined2 *)(pMVar20 + 4) = 0xffff;
        }
        else {
          iVar16 = *(int *)(*(int *)(param_1 + 0x7360) + 8);
          if (iVar16 == 0) {
            *(int *)(*(int *)(param_1 + 0x7360) + 8) = msys::MComSys::_sys;
            iVar16 = iVar11;
          }
          uVar15 = LMS_GetTextIndexByLabel(iVar16 + 0xeae90,ppuVar17[uVar14]);
          uVar15 = LMS_GetText(iVar16 + 0xeae90,uVar15);
          *(undefined4 *)(pMVar20 + 0x10) = uVar15;
          if (((!bVar5) || (*(short *)local_44 < 0)) ||
             (sVar8 = *(short *)local_44, (uVar25 & 1 << (iVar19 + uVar14 & 0x1f)) == 0)) {
            sVar8 = -1;
          }
          *(short *)(pMVar20 + 4) = sVar8;
        }
        pMVar20[0xe] = (MListWndPBase)0x1;
        *(uint *)pMVar20 = uVar26;
        pMVar21 = pMVar20 + 0x14;
        pMVar20[0xf] = (MListWndPBase)0x0;
        uVar25 = uVar26 + 1;
        pMVar20 = pMVar20 + 0x1c;
        *(undefined4 *)pMVar21 = 0;
        pMVar23 = pMVar23 + 2;
        if (local_34 <= (int)uVar25) {
          return local_38;
        }
        if ((int)uVar25 < 7) break;
        bVar5 = false;
        uVar14 = uVar26 - 6 & 0xff;
        bVar3 = *(byte *)(*(int *)(param_1 + 0x7360) + 0x31196);
        local_44 = (undefined **)((int)local_40 + uVar14 * 2);
        uVar26 = uVar25;
      }
      uVar14 = uVar25 & 0xff;
    } while( true );
  default:
    return local_38;
  }
LAB_15010e4c:
  puVar22 = (ushort *)&local_3c;
  iVar11 = local_48 * 0x1c;
  local_40 = param_1 + local_48 * 2 + 0x7320;
  param_1[local_48 * 0x1c + 0x6fa8] = (MListWndPBase)0xff;
  param_1[local_48 * 0x1c + 0x6fa9] = (MListWndPBase)0xff;
  local_3c = (undefined2 *)((uint)local_3c & 0xffff0000);
  uVar15 = GetRegFlag((&DAT_15024a28)[uVar14 * 0xc],(GlobalEvent *)0x0,(LocalEvent *)0x0);
  uVar26 = VectorFloatToUnsigned(uVar15,3);
  local_44 = (undefined **)((uint)local_44 & 0xffff0000);
  uVar25 = 0;
  do {
    uVar1 = uVar25 & 0xff;
    puVar10 = (ushort *)((int)&local_44 + (uVar25 >> 4) * 2);
    uVar18 = (ushort)(1 << (uVar25 & 0xf));
    uVar4 = *puVar10;
    uVar25 = uVar25 + 1;
    if ((uVar26 & 0x3f & 1 << uVar1) == 0) {
      uVar18 = uVar4 & ~uVar18;
    }
    else {
      uVar18 = uVar18 | uVar4;
    }
    *puVar10 = uVar18;
  } while (uVar25 < 10);
  puVar10 = puVar22;
  pppuVar24 = &local_44;
  if (puVar22 < (ushort *)((int)&local_3c + 2)) {
    local_3c = (undefined2 *)CONCAT22(local_3c._2_2_,(ushort)local_3c | (ushort)local_44);
  }
  else {
    do {
      puVar9 = puVar10 + 1;
      *puVar10 = *puVar10 | *(ushort *)pppuVar24;
      puVar10 = puVar9;
      pppuVar24 = (undefined ***)((int)pppuVar24 + 2);
    } while (puVar9 != (ushort *)((int)&local_3c + 2));
  }
  uVar15 = GetRegFlag((&DAT_15024a28)[uVar14 * 0xc] + 1,(GlobalEvent *)0x0,(LocalEvent *)0x0);
  uVar26 = VectorFloatToUnsigned(uVar15,3);
  uVar25 = 0;
  local_44 = (undefined **)((uint)local_44 & 0xffff0000);
  do {
    uVar1 = uVar25 & 0xff;
    puVar10 = (ushort *)((int)&local_44 + (uVar25 >> 4) * 2);
    uVar18 = (ushort)(1 << (uVar25 & 0xf));
    uVar4 = *puVar10;
    uVar25 = uVar25 + 1;
    if (((uVar26 & 0x3f) << 5 & 1 << uVar1) == 0) {
      uVar18 = uVar4 & ~uVar18;
    }
    else {
      uVar18 = uVar18 | uVar4;
    }
    *puVar10 = uVar18;
  } while (uVar25 < 10);
  puVar10 = puVar22;
  pppuVar24 = &local_44;
  if (puVar22 < (ushort *)((int)&local_3c + 2)) {
    local_3c = (undefined2 *)CONCAT22(local_3c._2_2_,(ushort)local_44 | (ushort)local_3c);
  }
  else {
    do {
      puVar9 = puVar10 + 1;
      *puVar10 = *puVar10 | *(ushort *)pppuVar24;
      puVar10 = puVar9;
      pppuVar24 = (undefined ***)((int)pppuVar24 + 2);
    } while (puVar9 != (ushort *)((int)&local_3c + 2));
  }
  param_1[local_48 * 0x1c + 0x6fae] = (MListWndPBase)0x1;
  fVar27 = (float)GetRegFlag((&DAT_15024a2c)[uVar14 * 0xc],(GlobalEvent *)0x0,(LocalEvent *)0x0);
  iVar19 = msys::MComSys::_sys;
  if (fVar27 == 0.0) {
    puVar9 = (ushort *)((int)&local_3c + 2);
    puVar10 = puVar22;
    if (puVar22 < puVar9) {
      iVar16 = 1;
      do {
        if (*puVar10 != 0) goto LAB_150110c4;
        iVar16 = iVar16 + 1;
        puVar10 = puVar10 + 1;
      } while (iVar16 < ((int)puVar9 - (int)puVar22 >> 1) + 1);
    }
    else {
      do {
        if (*puVar10 != 0) goto LAB_150110c4;
        puVar10 = puVar10 + 1;
      } while (puVar10 != puVar9);
    }
  }
  else {
    iVar19 = ad::db::GetItemMsgAcs();
    uVar15 = LMS_GetTextIndexByLabel(iVar19 + 8,(&DAT_15024a1c)[uVar14 * 6]);
    uVar15 = LMS_GetText(iVar19 + 8,uVar15);
    *(undefined4 *)(param_1 + local_48 * 0x1c + 0x6fb0) = uVar15;
    param_1[local_48 * 0x1c + 0x6fab] = (MListWndPBase)0xff;
    param_1[local_48 * 0x1c + 0x6fac] = *(MListWndPBase *)(&DAT_15024a30 + uVar14 * 0x18);
    *(undefined2 *)(param_1 + local_48 * 0x1c + 0x6fa4) = 0xffff;
    *(undefined2 *)local_40 = 0xffff;
    *(uint *)(param_1 + iVar11 + 0x6fa0) = uVar14 << 0xc | 0x3ff;
    local_48 = local_48 + 1 & 0xff;
  }
  goto LAB_15011184;
LAB_150110c4:
  iVar16 = *(int *)(*(int *)(param_1 + 0x7360) + 8);
  if (iVar16 == 0) {
    *(int *)(*(int *)(param_1 + 0x7360) + 8) = msys::MComSys::_sys;
    iVar16 = iVar19;
  }
  uVar15 = LMS_GetTextIndexByLabel(iVar16 + 0xeae90,(&DAT_15024a20)[uVar14 * 6]);
  uVar15 = LMS_GetText(iVar16 + 0xeae90,uVar15);
  *(undefined4 *)(param_1 + local_48 * 0x1c + 0x6fb0) = uVar15;
  param_1[local_48 * 0x1c + 0x6fab] = (MListWndPBase)0xb;
  param_1[local_48 * 0x1c + 0x6fac] = (MListWndPBase)0xff;
  sVar8 = 0;
  *(undefined2 *)(param_1 + local_48 * 0x1c + 0x6fa4) = 10;
  do {
    sVar7 = nn::math::CntBit1((uint)*puVar22);
    puVar22 = puVar22 + 1;
    sVar8 = sVar8 + sVar7;
  } while (puVar22 != (ushort *)((int)&local_3c + 2));
  *(short *)local_40 = sVar8;
  local_48 = local_48 + 1 & 0xff;
  *(uint *)(param_1 + iVar11 + 0x6fa0) = (uint)local_3c & 0x3ff | uVar14 << 0xc;
LAB_15011184:
  uVar14 = uVar14 + 1 & 0xff;
  if (9 < uVar14) {
    iVar11 = msys::MListWndPBase::getListWnd(param_1);
    *(char *)(iVar11 + 0x144) = (char)local_48;
    return local_38;
  }
  goto LAB_15010e4c;
}


// FUNC 0x1501153c FUN_1501153c (MainMenu)
//   size 0xf4 | file MainMenu+0x1153c | callers(2) 0x1501cf00 0x1501a400

void FUN_1501153c(int param_1,int param_2)

{
  int iVar1;
  
  if (*(char *)(param_1 + 0x7ea5) != -1) {
    *(undefined1 *)(param_1 + *(char *)(param_1 + 0x7ea5) * 0x1c + 0x6f89) = 0xff;
  }
  iVar1 = param_1 + param_2 * 0x1c;
  if (DAT_003fbfa0 == 0) {
    if ((*(char *)(param_1 + 0x7ead) != '\0') ||
       (Frm::update(1.0), (*(byte *)(param_1 + 0x7d8e) & 1) == 0)) {
      *(undefined1 *)(iVar1 + 0x6f89) = 1;
      SndSys::start((SndSys *)&gSndSys,*(uint *)(iVar1 + 0x6f80),(SoundHandle *)&DAT_003fbfa0);
      *(char *)(param_1 + 0x7ea5) = (char)param_2;
      *(undefined4 *)(param_1 + 0x7ea8) = 0;
      *(undefined1 *)(param_1 + 0x7ead) = 1;
      return;
    }
  }
  else if (*(char *)(param_1 + 0x7ead) != '\0') {
    SndSys::stop((SndSys *)&gSndSys,(SoundHandle *)&DAT_003fbfa0,8);
    *(ushort *)(param_1 + 0x7d8e) = *(ushort *)(param_1 + 0x7d8e) & 0xfffe;
    Frm::play((Frm *)(param_1 + 0x7d80),7.0);
    *(undefined1 *)(param_1 + 0x7ead) = 0;
  }
  *(undefined1 *)(iVar1 + 0x6f89) = 1;
  *(char *)(param_1 + 0x7ea5) = (char)param_2;
  return;
}


// FUNC 0x1501163c FUN_1501163c (MainMenu)
//   size 0x1bc | file MainMenu+0x1163c | callers(2) 0x15019e44 0x1501cf00

void FUN_1501163c(int param_1)

{
  byte bVar1;
  char cVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  ushort uVar7;
  uint uVar8;
  char *pcVar9;
  ushort uVar10;
  char cVar11;
  
  cVar11 = *(char *)(*(int *)(param_1 + 0x154) + 0x144);
  if (cVar11 != '\0') {
    iVar5 = 0;
    do {
      cVar11 = cVar11 + -1;
      *(char *)(param_1 + iVar5 + 0x7e24) = (char)iVar5;
      iVar5 = iVar5 + 1;
    } while (cVar11 != '\0');
  }
  cVar11 = *(char *)(param_1 + 0x7ea5);
  pcVar9 = (char *)(param_1 + 0x7e24);
  if (cVar11 == -1) {
    cVar11 = '\0';
  }
  *(char *)(param_1 + 0x7ea4) = cVar11;
  *(undefined1 *)(param_1 + 0x7eac) = 0;
  bVar1 = *(byte *)(*(int *)(param_1 + 0x154) + 0x144);
  uVar10 = (ushort)bVar1;
  if (uVar10 != 0) {
    cVar11 = (bVar1 & 1) != 0;
    pcVar6 = (char *)(param_1 + 0x7e23);
    if ((bool)cVar11) {
      *pcVar9 = '\0';
      pcVar6 = pcVar9;
    }
    for (uVar7 = (ushort)(bVar1 >> 1); uVar7 != 0; uVar7 = uVar7 - 1) {
      cVar2 = cVar11 + '\x01';
      pcVar6[1] = cVar11;
      cVar11 = cVar11 + '\x02';
      pcVar6 = pcVar6 + 2;
      *pcVar6 = cVar2;
    }
    if (1 < uVar10) {
      uVar4 = RandSys::get((RandSys *)&gRand);
      cVar11 = *(char *)(param_1 + 0x7e25);
      *(char *)(param_1 + 0x7e25) = pcVar9[(uVar4 & 0x7fffffff) >> 0xf];
      pcVar9[(uVar4 & 0x7fffffff) >> 0xf] = cVar11;
      uVar3 = gRand;
      uVar7 = 2;
      pcVar6 = (char *)(param_1 + 0x7e26);
      if (2 < uVar10) {
        do {
          uVar7 = uVar7 + 1;
          iVar5 = RandSys::get((RandSys *)&gRand);
          cVar11 = *pcVar6;
          *pcVar6 = pcVar9[iVar5 * (uint)uVar7 >> 0x10];
          pcVar9[iVar5 * (uint)uVar7 >> 0x10] = cVar11;
          pcVar6 = pcVar6 + 1;
        } while (uVar7 < uVar10);
      }
      gRand = uVar3;
    }
  }
  if ((int)*(char *)(param_1 + 0x7ea5) != 0xffffffff) {
    uVar4 = 0;
    uVar8 = (uint)*(byte *)(*(int *)(param_1 + 0x154) + 0x144);
    if (uVar8 != 0) {
      do {
        if ((uint)*(byte *)(param_1 + uVar4 + 0x7e24) == (int)*(char *)(param_1 + 0x7ea5)) {
          pcVar6 = (char *)(uVar4 + param_1 + 0x7e24);
          cVar11 = *pcVar9;
          *pcVar9 = *pcVar6;
          *pcVar6 = cVar11;
          break;
        }
        uVar4 = uVar4 + 1 & 0xff;
      } while (uVar4 < uVar8);
    }
  }
  *(undefined1 *)(param_1 + 0x7ea4) = 0;
  *(undefined1 *)(param_1 + 0x7eac) = 2;
  return;
}


// FUNC 0x15011800 FUN_15011800 (MainMenu)
//   size 0x1a8 | file MainMenu+0x11800 | callers(2) 0x1501dfd0 0x15018f6c

void FUN_15011800(int param_1)

{
  void *pvVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  float fVar5;
  
  pvVar1 = (void *)(param_1 + 0x6f80);
  Mem::Fill(pvVar1,0,0xe00);
  Mem::Fill((void *)(param_1 + 0x7e24),0,0x80);
  *(undefined1 *)(param_1 + 0x7eac) = 0;
  *(undefined1 *)(param_1 + 0x7ea5) = 0xff;
  uVar4 = 0;
  *(undefined1 *)(*(int *)(param_1 + 0x154) + 0x144) = 0;
  do {
    if (((&DAT_150246b8)[uVar4 * 3] == 0) ||
       (fVar5 = (float)GetRegFlag((ushort)(&DAT_150246b8)[uVar4 * 3],(GlobalEvent *)0x0,
                                  (LocalEvent *)0x0), fVar5 != 0.0)) {
      *(undefined1 *)(param_1 + (uint)*(byte *)(*(int *)(param_1 + 0x154) + 0x144) * 0x1c + 0x6f8e)
           = 1;
      *(undefined4 *)(param_1 + (uint)*(byte *)(*(int *)(param_1 + 0x154) + 0x144) * 0x1c + 0x6f80)
           = (&DAT_150246b0)[uVar4 * 3];
      iVar2 = *(int *)(param_1 + 0x7d90);
      uVar3 = LMS_GetTextIndexByLabel(iVar2 + 0xeae90,(&DAT_150246b4)[uVar4 * 3]);
      uVar3 = LMS_GetText(iVar2 + 0xeae90,uVar3);
      *(undefined4 *)(param_1 + (uint)*(byte *)(*(int *)(param_1 + 0x154) + 0x144) * 0x1c + 0x6f90)
           = uVar3;
      *(undefined1 *)(param_1 + (uint)*(byte *)(*(int *)(param_1 + 0x154) + 0x144) * 0x1c + 0x6f88)
           = 0xff;
      *(undefined1 *)(param_1 + (uint)*(byte *)(*(int *)(param_1 + 0x154) + 0x144) * 0x1c + 0x6f89)
           = 0xff;
      *(char *)(*(int *)(param_1 + 0x154) + 0x144) =
           *(char *)(*(int *)(param_1 + 0x154) + 0x144) + '\x01';
    }
    uVar4 = uVar4 + 1 & 0xff;
  } while (uVar4 < 0x49);
  *(void **)(*(int *)(param_1 + 0x154) + 0x140) = pvVar1;
  if (*(char *)(*(int *)(param_1 + 0x154) + 0x144) != '\0') {
    *(undefined4 *)(*(int *)(param_1 + 0x154) + 0x14c) = *(undefined4 *)(param_1 + 0x6f80);
    iVar2 = *(int *)(param_1 + 0x154);
    FUN_15013d30(iVar2 + 0x148,pvVar1,*(undefined1 *)(iVar2 + 0x144),*(undefined1 *)(iVar2 + 0x6b));
  }
  return;
}


// FUNC 0x150119b8 FUN_150119b8 (MainMenu)
//   size 0xe4 | file MainMenu+0x119b8 | callers(2) 0x15016204 0x150169a0

void FUN_150119b8(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  uVar7 = 0;
  uVar6 = 0;
  uVar5 = 0;
  uVar4 = 0;
  uVar3 = 0;
  uVar2 = 0;
  uVar1 = 0;
  switch(param_2) {
  case 0:
    uVar7 = 1;
    uVar6 = 1;
    uVar5 = 1;
    uVar4 = 1;
    break;
  case 1:
  case 2:
  case 3:
    break;
  case 4:
    uVar3 = 1;
    uVar2 = 1;
    break;
  default:
    goto switchD_150119e4_default;
  }
  uVar1 = 1;
switchD_150119e4_default:
  (**(code **)(**(int **)(param_1 + 0x860) + 0x28))(*(int **)(param_1 + 0x860),uVar1);
  (**(code **)(**(int **)(param_1 + 0xe600) + 0x28))(*(int **)(param_1 + 0xe600),uVar7);
  (**(code **)(**(int **)(param_1 + 0xe604) + 0x28))(*(int **)(param_1 + 0xe604),uVar6);
  (**(code **)(**(int **)(param_1 + 0xe608) + 0x28))(*(int **)(param_1 + 0xe608),uVar5);
  (**(code **)(**(int **)(param_1 + 0xe60c) + 0x28))(*(int **)(param_1 + 0xe60c),uVar4);
  (**(code **)(**(int **)(param_1 + 0xe614) + 0x28))(*(int **)(param_1 + 0xe614),uVar3);
                    /* WARNING: Could not recover jumptable at 0x15011aac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(param_1 + 0xe610) + 0x28))(*(int **)(param_1 + 0xe610),uVar2);
  return;
}


// FUNC 0x15011ab0 FUN_15011ab0 (MainMenu)
//   size 0x128 | file MainMenu+0x11ab0 | callers(2) 0x15015c5c 0x15011be4

void FUN_15011ab0(int *param_1)

{
  ushort uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int *piVar5;
  char acStack_50 [68];
  
  uVar1 = *(ushort *)param_1[3] & 0xf000;
  if (uVar1 == 0x1000) {
    iVar2 = ad::db::GetFldGuideList((uint *)0x0);
    puVar3 = (undefined4 *)(iVar2 + (*(ushort *)param_1[3] & 0xfff) * 0x10);
  }
  else {
    if (uVar1 == 0x2000) {
      iVar2 = ad::db::GetBtlGuideList((uint *)0x0);
      uVar4 = *(undefined4 *)(iVar2 + (*(ushort *)param_1[3] & 0xfff) * 0x10);
      goto LAB_15011aec;
    }
    if (uVar1 != 0x3000) {
      if (uVar1 == 0x4000) {
        iVar2 = ad::db::GetAtkGuideList((uint *)0x0);
        uVar4 = *(undefined4 *)(iVar2 + (*(ushort *)param_1[3] & 0xfff) * 0x10);
      }
      else {
        uVar4 = 0;
      }
      goto LAB_15011aec;
    }
    iVar2 = ad::db::GetFldActGuideList((uint *)0x0);
    puVar3 = (undefined4 *)(iVar2 + (*(ushort *)param_1[3] & 0xfff) * 0x10);
  }
  uVar4 = *puVar3;
LAB_15011aec:
  nn::nstd::TSPrintf(acStack_50,"%s_%d",uVar4,param_1[1]);
  iVar2 = *param_1;
  piVar5 = (int *)param_1[5];
  uVar4 = LMS_GetTextIndexByLabel(iVar2 + 0xeae90,acStack_50);
  uVar4 = LMS_GetText(iVar2 + 0xeae90,uVar4);
  (**(code **)(*piVar5 + 0x3c))(piVar5,uVar4,0);
  return;
}


// FUNC 0x15011be4 FUN_15011be4 (MainMenu)
//   size 0x184 | file MainMenu+0x11be4 | callers(2) 0x15016ff0 0x1500e6b0

void FUN_15011be4(int param_1,ushort *param_2)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  
  *(undefined4 *)(param_1 + 4) = 0;
  *(ushort **)(param_1 + 0xc) = param_2;
  uVar1 = *param_2 & 0xf000;
  if (uVar1 == 0x1000) {
    iVar2 = ad::db::GetFldGuideList((uint *)0x0);
    uVar3 = *(byte *)(iVar2 + (**(ushort **)(param_1 + 0xc) & 0xfff) * 0x10 + 4) & 0xf;
  }
  else if (uVar1 == 0x2000) {
    iVar2 = ad::db::GetBtlGuideList((uint *)0x0);
    uVar3 = *(byte *)(iVar2 + (**(ushort **)(param_1 + 0xc) & 0xfff) * 0x10 + 4) & 0xf;
  }
  else if (uVar1 == 0x3000) {
    iVar2 = ad::db::GetFldActGuideList((uint *)0x0);
    uVar3 = *(byte *)(iVar2 + (**(ushort **)(param_1 + 0xc) & 0xfff) * 0x10 + 4) & 0xf;
  }
  else if (uVar1 == 0x4000) {
    iVar2 = ad::db::GetAtkGuideList((uint *)0x0);
    uVar3 = *(byte *)(iVar2 + (**(ushort **)(param_1 + 0xc) & 0xfff) * 0x10 + 4) & 0xf;
  }
  else {
    uVar3 = 0;
  }
  iVar2 = msys::MLyt::getPane(*(MLyt **)(param_1 + 0x10),"btn_L","GUIDE_TXT_base",(char *)0x0);
  *(byte *)(iVar2 + 0x44) = *(byte *)(iVar2 + 0x44) & 0xfe;
  iVar2 = msys::MLyt::getPane(*(MLyt **)(param_1 + 0x10),"btn_R","GUIDE_TXT_base",(char *)0x0);
  *(byte *)(iVar2 + 0x44) = 1 < uVar3 | *(byte *)(iVar2 + 0x44) & 0xfe;
  (**(code **)(**(int **)(param_1 + 0x478) + 0x28))(*(int **)(param_1 + 0x478),0);
  (**(code **)(**(int **)(param_1 + 0x47c) + 0x28))(*(int **)(param_1 + 0x47c),1 < uVar3);
  ad::lyt::LytNumReel3::setValueInstant((LytNumReel3 *)(param_1 + 0x168),1);
  ad::lyt::LytNumReel3::setValueInstant((LytNumReel3 *)(param_1 + 0x398),uVar3);
  FUN_15011ab0(param_1);
  return;
}


// FUNC 0x15011d88 FUN_15011d88 (MainMenu)
//   size 0xf0 | file MainMenu+0x11d88 | callers(2) 0x15017348 0x1500e6b0

void FUN_15011d88(MListWndPBase *param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  MListWndPBase MVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 *puVar7;
  MListWndPBase *unaff_r10;
  MListWndPBase unaff_r11;
  bool bVar8;
  uint local_28;
  
  local_28 = param_4;
  Mem::Fill(param_1 + 0x6f80,0,0x700);
  puVar3 = (undefined4 *)ad::db::GetFldActGuideList(&local_28);
  puVar7 = puVar3 + local_28 * 4;
  bVar8 = puVar3 < puVar7;
  uVar6 = 0;
  if (bVar8) {
    unaff_r10 = param_1 + 0x7000;
    unaff_r11 = (MListWndPBase)0x1;
  }
  local_28 = 0;
  while (bVar8) {
    iVar4 = ActGuideAcs::IsExistGuide(uVar6);
    uVar1 = local_28;
    if (iVar4 != 0) {
      *(uint *)(param_1 + local_28 * 0x1c + 0x6f80) = uVar6 | 0x3000;
      iVar4 = ActGuideAcs::IsReadedGuide(uVar6);
      if (iVar4 == 0) {
        MVar2 = (MListWndPBase)0x1;
      }
      else {
        MVar2 = (MListWndPBase)0xff;
      }
      param_1[uVar1 * 0x1c + 0x6f88] = MVar2;
      iVar4 = *(int *)(unaff_r10 + 0x688);
      uVar5 = LMS_GetTextIndexByLabel(iVar4 + 8,*puVar3);
      uVar5 = LMS_GetText(iVar4 + 8,uVar5);
      *(undefined4 *)(param_1 + uVar1 * 0x1c + 0x6f90) = uVar5;
      param_1[uVar1 * 0x1c + 0x6f8e] = unaff_r11;
      local_28 = local_28 + 1;
    }
    puVar3 = puVar3 + 4;
    bVar8 = puVar3 < puVar7;
    uVar6 = uVar6 + 1;
  }
  iVar4 = msys::MListWndPBase::getListWnd(param_1);
  *(char *)(iVar4 + 0x144) = (char)local_28;
  msys::MListWndPBase::resetCur(param_1);
  return;
}


// FUNC 0x15011e78 FUN_15011e78 (MainMenu)
//   size 0xf4 | file MainMenu+0x11e78 | callers(2) 0x15017348 0x1500e6b0

void FUN_15011e78(MListWndPBase *param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  MListWndPBase MVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 *puVar7;
  MListWndPBase *unaff_r10;
  MListWndPBase unaff_r11;
  bool bVar8;
  uint local_28;
  
  local_28 = param_4;
  Mem::Fill(param_1 + 0x6f80,0,0x700);
  puVar3 = (undefined4 *)ad::db::GetAtkGuideList(&local_28);
  puVar7 = puVar3 + local_28 * 4;
  bVar8 = puVar3 < puVar7;
  uVar6 = 0;
  if (bVar8) {
    unaff_r10 = param_1 + 0x7000;
    unaff_r11 = (MListWndPBase)0x1;
  }
  local_28 = 0;
  while (bVar8) {
    iVar4 = BattleAttackGuideDataAcs::IsExistGuide(uVar6,true);
    uVar1 = local_28;
    if (iVar4 != 0) {
      *(uint *)(param_1 + local_28 * 0x1c + 0x6f80) = uVar6 | 0x4000;
      iVar4 = BattleAttackGuideDataAcs::IsReadedGuide(uVar6);
      if (iVar4 == 0) {
        MVar2 = (MListWndPBase)0x1;
      }
      else {
        MVar2 = (MListWndPBase)0xff;
      }
      param_1[uVar1 * 0x1c + 0x6f88] = MVar2;
      iVar4 = *(int *)(unaff_r10 + 0x688);
      uVar5 = LMS_GetTextIndexByLabel(iVar4 + 8,*puVar3);
      uVar5 = LMS_GetText(iVar4 + 8,uVar5);
      *(undefined4 *)(param_1 + uVar1 * 0x1c + 0x6f90) = uVar5;
      param_1[uVar1 * 0x1c + 0x6f8e] = unaff_r11;
      local_28 = local_28 + 1;
    }
    puVar3 = puVar3 + 4;
    bVar8 = puVar3 < puVar7;
    uVar6 = uVar6 + 1;
  }
  iVar4 = msys::MListWndPBase::getListWnd(param_1);
  *(char *)(iVar4 + 0x144) = (char)local_28;
  msys::MListWndPBase::resetCur(param_1);
  return;
}


// FUNC 0x15011f6c FUN_15011f6c (MainMenu)
//   size 0xc8 | file MainMenu+0x11f6c | callers(1) 0x1500d000

void FUN_15011f6c(int param_1,ushort param_2)

{
  int iVar1;
  int iVar2;
  DataPc aDStack_c8 [180];
  
  FUN_15012a2c(param_1 + 0x968);
  iVar2 = msys::MListWndPBase::getListWnd((MListWndPBase *)(param_1 + 0x44eac));
  *(ushort *)(param_1 + 0x876) = (ushort)*(byte *)(iVar2 + 0x149);
  iVar1 = msys::MComSys::_sys;
  iVar2 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar2 = iVar1;
  }
  __aeabi_memcpy4(aDStack_c8,iVar2 + (uint)*(byte *)(param_1 + 0x875) * 0xb0 + 0xeac64,0xb0);
  DataPc::setEquip(aDStack_c8,param_2,*(uchar *)(param_1 + 0x874));
  iVar1 = msys::MComSys::_sys;
  iVar2 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar2 = iVar1;
  }
  msys::StatusPanel::setNewEquipParam
            ((StatusPanel *)(param_1 + 0x40df8),
             (DataPc *)(iVar2 + (uint)*(byte *)(param_1 + 0x875) * 0xb0 + 0xeac64),aDStack_c8);
  msys::StatusPanel::setParam((StatusPanel *)(param_1 + 0x42e2c),aDStack_c8);
  return;
}


// FUNC 0x1501204c FUN_1501204c (MainMenu)
//   size 0xa8 | file MainMenu+0x1204c | callers(1) 0x1500c9c8

void FUN_1501204c(int *param_1,int param_2)

{
  int iVar1;
  wchar_t *pwVar2;
  undefined4 uVar3;
  
  if (param_2 == 0) {
    *(undefined1 *)((int)param_1 + 0x6d89) = 0;
    iVar1 = *param_1;
    uVar3 = LMS_GetTextIndexByLabel(iVar1 + 8,"Menu_Sys_invalid_equip_name");
    pwVar2 = (wchar_t *)LMS_GetText(iVar1 + 8,uVar3);
    msys::MMsg::playStr((MMsg *)(param_1 + 1),pwVar2,(InsParam *)0x0,false);
    return;
  }
  *(undefined1 *)((int)param_1 + 0x6d89) = 1;
  iVar1 = ad::db::GetItemData((ushort)param_2);
  CellAnime::play((CellAnime *)(param_1 + 0x1b65),*(char *)(iVar1 + 0x60) + '\x01',0,1.0);
  pwVar2 = (wchar_t *)ad::db::GetItemMsg(param_2,0);
  msys::MMsg::playStr((MMsg *)(param_1 + 1),pwVar2,(InsParam *)0x0,false);
  return;
}


// FUNC 0x15012114 main_menu::MainMenu_EquipPage::Core::MListWndEquip::vfunc_0x0 (MainMenu)
//   size 0x8c | file MainMenu+0x12114 | callers(2) 0x1500b978 0x1500e2ec | datarefs 1

void main_menu::MainMenu_EquipPage::Core::MListWndEquip::vfunc_0x0(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &vtable;
  operator_delete__((void *)param_1[0x2382]);
  param_1[0x2382] = 0;
  iVar1 = CellAnime::~CellAnime((CellAnime *)(param_1 + 0x2330));
  *(undefined4 *)(iVar1 + -0x10) = 0;
  *(undefined4 *)(iVar1 + -0x2c) = 0;
  *(undefined4 *)(iVar1 + -0x48) = 0;
  *(undefined4 *)(iVar1 + -100) = 0;
  *(undefined4 *)(iVar1 + -0x80) = 0;
  iVar1 = ad::lyt::Layout::~Layout((Layout *)(iVar1 + -200));
  *(undefined4 *)(iVar1 + -0x10) = 0;
  *(undefined4 *)(iVar1 + -0x2c) = 0;
  iVar1 = ad::lyt::Layout::~Layout((Layout *)(iVar1 + -0x74));
  *(undefined ***)(iVar1 + -0x8b84) = &vtable_for_N4msys9MListWndPILi256EEE;
  iVar1 = ad::ui::UIListWindowPlusLyt::~UIListWindowPlusLyt
                    ((UIListWindowPlusLyt *)(iVar1 + -0x8988));
  msys::MListWndPBase::~MListWndPBase((MListWndPBase *)(iVar1 + -0x1fc));
  return;
}


// FUNC 0x150121ac FUN_150121ac (MainMenu)
//   size 0x280 | file MainMenu+0x121ac | callers(5) 0x1500a994 0x1500d5fc 0x1501fd00 0x1500c678 0x1501f68c

void FUN_150121ac(int param_1)

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
                        (this,(char *)&msys::MCursor<4u>::update()::string_literal);
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
      local_50[0] = msys::MCursor<4u>::update()::string_literal;
      local_50[1] = msys::MCursor<4u>::update()::string_literal;
      local_50[2] = msys::MCursor<4u>::update()::string_literal;
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


// FUNC 0x15012444 FUN_15012444 (MainMenu)
//   size 0x64 | file MainMenu+0x12444 | callers(6) 0x1500bbb8 0x1500a994 0x1500ad54 0x1500b988 0x1500ce58 0x1500c678

void FUN_15012444(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint in_fpscr;
  float fVar3;
  
  uVar1 = 0;
  do {
    iVar2 = param_1 + uVar1 * 0x1c;
    fVar3 = (float)VectorUnsignedToFloat((uint)(param_2 == uVar1),(byte)(in_fpscr >> 0x16) & 3);
    ad::lyt::LytAnim::stopAndSetFrm((LytAnim *)(iVar2 + 4),fVar3);
    fVar3 = (float)VectorUnsignedToFloat((uint)(param_2 == uVar1),(byte)(in_fpscr >> 0x16) & 3);
    ad::lyt::LytAnim::stopAndSetFrm((LytAnim *)(iVar2 + 0x58),fVar3);
    uVar1 = uVar1 + 1 & 0xff;
  } while (uVar1 < 3);
  return;
}


// FUNC 0x150124a8 FUN_150124a8 (MainMenu)
//   size 0x574 | file MainMenu+0x124a8 | callers(4) 0x15012af4 0x1500a994 0x1500ad54 0x1500c9c8

void FUN_150124a8(MListWndPBase *param_1,int param_2,int param_3,uint param_4,int param_5)

{
  byte bVar1;
  undefined1 uVar2;
  MListWndPBase *pMVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uchar uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  ushort auStack_52 [5];
  DataPc *local_48;
  MListWndPBase *local_34;
  int iStack_30;
  int iStack_2c;
  uint uStack_28;
  
  iVar5 = msys::MComSys::_sys;
  uVar11 = (uint)(param_2 == 2);
  uVar6 = (uint)(param_3 == 2);
  iVar4 = *(int *)(param_1 + 0x8b80);
  if (*(int *)(iVar4 + 8) == 0) {
    *(int *)(iVar4 + 8) = msys::MComSys::_sys;
  }
  local_48 = (DataPc *)(*(int *)(iVar4 + 8) + param_2 * 0xb0 + 0xeac64);
  local_34 = param_1;
  iStack_30 = param_2;
  iStack_2c = param_3;
  uStack_28 = param_4;
  if (param_4 == 0) {
    if (param_2 == 2) {
      uVar10 = 0x20;
    }
    else {
      uVar10 = 1;
    }
  }
  else {
    if (param_4 == 1) {
      iVar4 = *(int *)(param_1 + 0x8b80);
      if (*(int *)(iVar4 + 8) == 0) {
        *(int *)(iVar4 + 8) = iVar5;
      }
      iVar4 = *(int *)(iVar4 + 8) + param_2 * 0xb0;
      uVar8 = '\x02';
    }
    else {
      if (param_4 != 2) {
        uVar10 = 0;
        goto LAB_1501252c;
      }
      iVar4 = *(int *)(*(int *)(param_1 + 0x8b80) + 8);
      if (iVar4 == 0) {
        *(int *)(*(int *)(param_1 + 0x8b80) + 8) = iVar5;
        iVar4 = iVar5;
      }
      iVar4 = iVar4 + param_2 * 0xb0;
      uVar8 = '\x01';
    }
    iVar5 = DataPc::getEquip((DataPc *)(iVar4 + 0xeac64),uVar8);
    if (param_2 == 2) {
      uVar10 = 0x1c0;
    }
    else {
      uVar10 = 0x1e;
    }
    if (iVar5 != 0) {
      iVar5 = ad::db::GetEquip((ushort)iVar5);
      uVar10 = uVar10 & ~(1 << *(sbyte *)(iVar5 + 0x6a));
    }
  }
LAB_1501252c:
  if ((uVar11 != uVar6) && (param_5 == 0)) {
    iVar5 = msys::MListWndPBase::getListWnd(local_34);
    pMVar3 = local_34;
    bVar1 = *(byte *)(iVar5 + 0x149);
    *(ushort *)(*(int *)(param_1 + 0x8b80) + 0x876) = (ushort)bVar1;
    *(short *)(local_34 + uVar6 * 2 + 0x8dee) =
         (short)*(undefined4 *)(*(int *)(param_1 + 0x8e08) + (uint)bVar1 * 0x1c);
    iVar5 = msys::MListWndPBase::getListWnd(local_34);
    *(ushort *)(pMVar3 + uVar6 * 2 + 0x8df2) = (ushort)*(byte *)(iVar5 + 0x148);
  }
  uVar10 = FUN_1500ae40(local_34,param_2,param_4,uVar10);
  iVar5 = msys::MListWndPBase::getListWnd(local_34);
  *(char *)(iVar5 + 0x144) = (char)uVar10;
  iVar5 = DataPc::getEquip(local_48,(uchar)param_4);
  pMVar3 = local_34;
  if ((iVar5 == 0) && (*(short *)(local_34 + uVar11 * 2 + 0x8dee) == 0)) {
    *(undefined2 *)(local_34 + uVar11 * 2 + 0x8dee) = 0xffff;
  }
  if (uVar11 == uVar6 && param_5 == 0) goto LAB_15012910;
  if (*(short *)(local_34 + uVar11 * 2 + 0x8dee) == -1) {
    iVar5 = 0;
    if (param_5 == 2) {
      if (0 < (int)uVar10) {
        do {
          iVar4 = *(int *)(*(int *)(param_1 + 0x8e08) + iVar5 * 0x1c);
          if ((iVar4 != 0) &&
             (iVar4 = ad::db::GetEquip((ushort)iVar4),
             *(char *)(iVar4 + 0x6a) == *(char *)(*(int *)(param_1 + 0x8b80) + 0x879))) {
            uVar6 = *(uint *)(*(int *)(param_1 + 0x8e08) + iVar5 * 0x1c) & 0xffff;
            goto LAB_150126b8;
          }
          iVar5 = (int)(short)((short)iVar5 + 1);
        } while (iVar5 < (int)uVar10);
      }
    }
    else {
      uVar6 = DataPc::getEquip(local_48,(uchar)param_4);
LAB_150126b8:
      if (uVar6 != 0) {
        if (iVar5 < (int)uVar10) {
          uVar9 = uVar10 - iVar5 & 1;
        }
        else {
          uVar9 = 0;
        }
        iVar4 = uVar9 + iVar5;
        if (iVar5 < iVar4) {
          do {
            if (*(uint *)(*(int *)(param_1 + 0x8e08) + iVar5 * 0x1c) == uVar6) goto LAB_150127e8;
            iVar5 = (int)(short)((short)iVar5 + 1);
          } while (iVar5 < iVar4);
        }
        iVar5 = (int)(short)iVar4;
        if (iVar5 < (int)uVar10) {
          do {
            if (*(uint *)(*(int *)(param_1 + 0x8e08) + iVar5 * 0x1c) == uVar6) break;
            if (*(uint *)(*(int *)(param_1 + 0x8e08) + iVar5 * 0x1c + 0x1c) == uVar6) {
              iVar5 = (int)(short)((short)iVar5 + 1);
              break;
            }
            iVar5 = (int)(short)((short)iVar5 + 2);
          } while (iVar5 < (int)uVar10);
        }
LAB_150127e8:
        iVar4 = msys::MListWndPBase::getListWnd(local_34);
        *(undefined1 *)(iVar4 + 0x149) = 0;
        iVar4 = msys::MListWndPBase::getListWnd(local_34);
        *(undefined4 *)(iVar4 + 0x14c) = *(undefined4 *)(*(int *)(param_1 + 0x8e08) + iVar5 * 0x1c);
        iVar4 = msys::MListWndPBase::getListWnd(local_34);
        *(char *)(iVar4 + 0x148) = (char)iVar5;
        goto LAB_150128c8;
      }
    }
    uVar9 = 0;
    uVar6 = 1;
    auStack_52[1] = 0;
    auStack_52[2] = 0;
    do {
      iVar5 = msys::MComSys::_sys;
      if (param_4 != uVar6) {
        iVar4 = *(int *)(*(int *)(param_1 + 0x8b80) + 8);
        if (iVar4 == 0) {
          *(int *)(*(int *)(param_1 + 0x8b80) + 8) = msys::MComSys::_sys;
          iVar4 = iVar5;
        }
        iVar5 = DataPc::getEquip((DataPc *)(iVar4 + param_2 * 0xb0 + 0xeac64),(uchar)uVar6);
        auStack_52[uVar6] = (ushort)iVar5;
        if (iVar5 != 0) {
          iVar5 = ad::db::GetEquip((ushort)iVar5);
          uVar7 = (uint)*(byte *)(iVar5 + 0x6a);
          if (uVar7 != 0 && uVar7 != 5) {
            uVar9 = 1 << uVar7 & 0xffff;
            break;
          }
        }
      }
      uVar6 = uVar6 + 1 & 0xff;
    } while (uVar6 < 3);
    if (auStack_52[param_4] == 0) {
      uVar6 = 1;
      if (1 < (int)uVar10) {
        do {
          iVar5 = ad::db::GetEquip((ushort)*(undefined4 *)
                                            (*(int *)(param_1 + 0x8e08) + uVar6 * 0x1c));
          if ((*(char *)(iVar5 + 0x6a) != '\0' && *(char *)(iVar5 + 0x6a) != '\x05') &&
             ((uVar9 & 0xffff01de) == 0)) {
            iVar5 = msys::MListWndPBase::getListWnd(local_34);
            uVar9 = (uint)*(byte *)(iVar5 + 0x6b);
            uVar7 = *(uint *)(*(int *)(param_1 + 0x8e08) + uVar6 * 0x1c);
            if ((int)uVar10 <= (int)uVar9) {
              uVar6 = 0;
            }
            if ((int)uVar9 < (int)uVar10) {
              if ((int)(uVar10 - uVar9) < (int)uVar6) {
                uVar6 = uVar10 - uVar9;
              }
            }
            *(short *)(pMVar3 + uVar11 * 2 + 0x8dee) = (short)uVar7;
            *(short *)(pMVar3 + uVar11 * 2 + 0x8df2) = (short)uVar6;
            iVar5 = msys::MListWndPBase::getListWnd(local_34);
            *(undefined1 *)(iVar5 + 0x149) = 0;
            iVar5 = msys::MListWndPBase::getListWnd(local_34);
            *(uint *)(iVar5 + 0x14c) = uVar7 & 0xffff;
            iVar5 = msys::MListWndPBase::getListWnd(local_34);
            *(char *)(iVar5 + 0x148) = (char)uVar6;
            goto LAB_150128c8;
          }
          uVar6 = uVar6 + 1 & 0xffff;
        } while ((int)uVar6 < (int)uVar10);
      }
      iVar5 = msys::MListWndPBase::getListWnd(local_34);
      *(undefined1 *)(iVar5 + 0x149) = 0;
      iVar5 = msys::MListWndPBase::getListWnd(local_34);
      *(undefined4 *)(iVar5 + 0x14c) = 0;
      iVar5 = msys::MListWndPBase::getListWnd(local_34);
      *(undefined1 *)(iVar5 + 0x148) = 0;
    }
    else {
      iVar5 = msys::MListWndPBase::getListWnd(local_34);
      *(undefined1 *)(iVar5 + 0x149) = 0;
      iVar5 = msys::MListWndPBase::getListWnd(local_34);
      *(uint *)(iVar5 + 0x14c) = (uint)auStack_52[param_4];
      iVar5 = msys::MListWndPBase::getListWnd(local_34);
      *(undefined1 *)(iVar5 + 0x148) = 0;
    }
  }
  else {
    iVar5 = msys::MListWndPBase::getListWnd(local_34);
    *(uint *)(iVar5 + 0x14c) = (uint)*(ushort *)(pMVar3 + uVar11 * 2 + 0x8dee);
  }
LAB_150128c8:
  iVar5 = msys::MListWndPBase::getListWnd(local_34);
  uVar2 = *(undefined1 *)(iVar5 + 0x6b);
  iVar5 = msys::MListWndPBase::getListWnd(local_34);
  FUN_15013d30(iVar5 + 0x148,*(undefined4 *)(param_1 + 0x8e08),uVar10 & 0xff,uVar2);
  if (*(short *)(pMVar3 + uVar11 * 2 + 0x8dee) != -1) {
    iVar5 = msys::MListWndPBase::getListWnd(local_34);
    *(MListWndPBase *)(iVar5 + 0x148) = pMVar3[uVar11 * 2 + 0x8df2];
  }
LAB_15012910:
  iVar5 = msys::MListWndPBase::getListWnd(local_34);
  *(ushort *)(*(int *)(param_1 + 0x8b80) + 0x876) = (ushort)*(byte *)(iVar5 + 0x149);
  return;
}


// FUNC 0x15012a2c FUN_15012a2c (MainMenu)
//   size 0xc8 | file MainMenu+0x12a2c | callers(7) 0x1500a480 0x1500a994 0x1500ddf0 0x15011f6c 0x1500b988 0x1500d5fc 0x1500c678

void FUN_15012a2c(int param_1,int param_2)

{
  int iVar1;
  wchar_t *pwVar2;
  int iVar3;
  byte bVar4;
  int iVar5;
  uint uVar6;
  
  iVar1 = *(int *)(param_1 + 0x6c48);
  bVar4 = *(byte *)(iVar1 + 0x44) & 0xfe;
  if (param_2 == 0) {
    *(byte *)(iVar1 + 0x44) = bVar4;
  }
  else {
    *(byte *)(iVar1 + 0x44) = bVar4 | 1;
    pwVar2 = (wchar_t *)ad::db::GetItemMsg(param_2,2);
    msys::MMsg::playStr((MMsg *)(param_1 + 4),pwVar2,(InsParam *)0x0,false);
    iVar1 = ad::db::GetEquip((ushort)param_2);
    uVar6 = 0;
    do {
      iVar5 = (int)*(short *)(iVar1 + uVar6 * 2 + 0x6c);
      iVar3 = param_1 + uVar6 * 0x230;
      if (iVar5 == 0) {
        *(undefined4 *)(iVar3 + 0x6dbc) = 0xb;
        *(undefined4 *)(iVar3 + 0x6dc8) = 0xb;
        *(undefined4 *)(iVar3 + 0x6dd4) = 0xb;
      }
      else {
        ad::lyt::LytNumReel3::setValueInstant((LytNumReel3 *)(iVar3 + 0x6d9c),iVar5);
      }
      uVar6 = uVar6 + 1 & 0xff;
    } while (uVar6 < 6);
  }
  return;
}


// FUNC 0x15012af4 FUN_15012af4 (MainMenu)
//   size 0x300 | file MainMenu+0x12af4 | callers(6) 0x1500bbb8 0x1500a480 0x1500a994 0x1500ddf0 0x1500b988 0x1500d000

void FUN_15012af4(int param_1,int param_2,int param_3)

{
  ushort uVar1;
  ushort *puVar2;
  int iVar3;
  wchar_t *pwVar4;
  undefined4 uVar5;
  uchar uVar6;
  uint uVar7;
  int iVar8;
  StatusPanel *this;
  DataPc *this_00;
  int iVar9;
  undefined8 uVar10;
  undefined4 local_e0 [45];
  
  local_e0[0] = 0;
  FUN_150124a8(param_1 + 0x44eac,param_2,*(undefined1 *)(param_1 + 0x875),
               *(undefined1 *)(param_1 + 0x874));
  iVar8 = msys::MComSys::_sys;
  iVar9 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar9 = iVar8;
  }
  this_00 = (DataPc *)(iVar9 + param_2 * 0xb0 + 0xeac64);
  this = (StatusPanel *)(param_1 + 0x40df8);
  if (param_3 != 0) {
    uVar10 = msys::MListWndPBase::getCurItem();
    uVar7 = (uint)((ulonglong)uVar10 >> 0x20);
    puVar2 = (ushort *)uVar10;
    if (puVar2 != (ushort *)0x0) {
      uVar7 = (uint)(byte)puVar2[7];
    }
    if (puVar2 != (ushort *)0x0 && uVar7 != 0) {
      uVar1 = *puVar2;
      __aeabi_memcpy4(local_e0,this_00,0xb0);
      DataPc::setEquip((DataPc *)local_e0,uVar1,*(uchar *)(param_1 + 0x874));
      msys::StatusPanel::setNewEquipParam(this,this_00,(DataPc *)local_e0);
      goto LAB_15012bd0;
    }
  }
  msys::StatusPanel::setParam(this,this_00);
LAB_15012bd0:
  msys::StatusPanel::setParam((StatusPanel *)(param_1 + 0x42e2c),this_00);
  uVar6 = (uchar)param_2;
  msys::StatusPanel::setChr(this,uVar6);
  msys::StatusPanel::setChr((StatusPanel *)(param_1 + 0x42e2c),uVar6);
  uVar7 = 0;
  *(undefined1 *)(param_1 + (uint)*(byte *)(param_1 + 0x875) * 0x27c + 0x85bd) = 0;
  *(undefined1 *)(param_1 + (uint)*(byte *)(param_1 + 0x875) * 0x27c + 0x8d31) = 0;
  iVar8 = param_1 + param_2 * 0x27c;
  *(undefined1 *)(iVar8 + 0x85bd) = 1;
  *(undefined1 *)(iVar8 + 0x8d31) = 1;
  do {
    iVar8 = DataPc::getEquip(this_00,(uchar)uVar7);
    iVar9 = param_1 + uVar7 * 0x6ec4;
    if (iVar8 == 0) {
      *(undefined1 *)(iVar9 + 0x100ed) = 0;
      iVar8 = *(int *)(iVar9 + 0x9364);
      uVar5 = LMS_GetTextIndexByLabel(iVar8 + 8,"Menu_Sys_invalid_equip_name");
      pwVar4 = (wchar_t *)LMS_GetText(iVar8 + 8,uVar5);
      msys::MMsg::playStr((MMsg *)(iVar9 + 0x9368),pwVar4,(InsParam *)0x0,false);
      *(undefined1 *)(iVar9 + 0x24d39) = 0;
      iVar8 = *(int *)(iVar9 + 0x1dfb0);
      uVar5 = LMS_GetTextIndexByLabel(iVar8 + 8,"Menu_Sys_invalid_equip_name");
      pwVar4 = (wchar_t *)LMS_GetText(iVar8 + 8,uVar5);
      msys::MMsg::playStr((MMsg *)(iVar9 + 0x1dfb4),pwVar4,(InsParam *)0x0,false);
    }
    else {
      *(undefined1 *)(iVar9 + 0x100ed) = 1;
      iVar3 = ad::db::GetItemData((ushort)iVar8);
      CellAnime::play((CellAnime *)(iVar9 + 0x100f8),*(char *)(iVar3 + 0x60) + '\x01',0,1.0);
      pwVar4 = (wchar_t *)ad::db::GetItemMsg(iVar8,0);
      msys::MMsg::playStr((MMsg *)(iVar9 + 0x9368),pwVar4,(InsParam *)0x0,false);
      *(undefined1 *)(iVar9 + 0x24d39) = 1;
      iVar3 = ad::db::GetItemData((ushort)iVar8);
      CellAnime::play((CellAnime *)(iVar9 + 0x24d44),*(char *)(iVar3 + 0x60) + '\x01',0,1.0);
      pwVar4 = (wchar_t *)ad::db::GetItemMsg(iVar8,0);
      msys::MMsg::playStr((MMsg *)(iVar9 + 0x1dfb4),pwVar4,(InsParam *)0x0,false);
    }
    uVar7 = uVar7 + 1 & 0xff;
  } while (uVar7 < 3);
  *(uchar *)(param_1 + 0x875) = uVar6;
  return;
}


// FUNC 0x15012e20 FUN_15012e20 (MainMenu)
//   size 0xe8 | file MainMenu+0x12e20 | callers(6) 0x15009b20 0x15009b5c 0x15009b98 0x15009c94 0x15009cd0 0x15009d0c

void FUN_15012e20(undefined4 *param_1,undefined4 param_2,undefined4 param_3,Resource *param_4,
                 MLyt *param_5,char *param_6,undefined4 param_7)

{
  *param_1 = param_3;
  msys::MLyt::getParts(param_5,param_6,(char *)0x0,(char *)0x0);
  msys::MCellAnime::init((MCellAnime *)(param_1 + 0x1b12),param_4);
  *(byte *)((int)param_1 + 0x6e37) = *(byte *)((int)param_1 + 0x6e37) | 3;
  msys::MLyt::attachMChr
            (param_5,(MChrBase *)(param_1 + 0x1b12),"INS_ICON_OBJ",param_6,(char *)0x0,(char *)0x0);
  param_1[0x1b11] = param_7;
  param_1[0x1b0e] = param_2;
  param_1[0x1b0f] = 0;
  param_1[0x1b10] = 0;
  MessageSimple::init((MessageSimple *)(param_1 + 0x54));
  FUN_150142ec(param_1 + 1);
  MessageWriter::setFontColor((MessageWriter *)(param_1 + 0x54),0xe6e6e6ff,true);
  msys::MLyt::attachMChr
            (param_5,(MChrBase *)(param_1 + 1),"list_text_top",param_6,(char *)0x0,(char *)0x0);
  return;
}


// FUNC 0x15012f30 FUN_15012f30 (MainMenu)
//   size 0x34 | file MainMenu+0x12f30 | callers(9) 0x150231f4 0x150076c0 0x1500df8c 0x150176ac 0x1501e420 0x150207d8 0x15021310 0x15018480 ... | datarefs 11

void FUN_15012f30(undefined1 *param_1)

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


// FUNC 0x15012f6c FUN_15012f6c (MainMenu)
//   size 0x30 | file MainMenu+0x12f6c | callers(6) 0x150231f4 0x150076c0 0x1500df8c 0x1501e420 0x150207d8 0x15009754 | datarefs 6

int FUN_15012f6c(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)FUN_150159f4();
  *puVar1 = &msys::MCellAnime::vtable;
  iVar2 = CellAnime::CellAnime((CellAnime *)(puVar1 + 0x53));
  *(undefined1 *)(iVar2 + 300) = 0xff;
  *(undefined1 *)(iVar2 + 0x12d) = 0xff;
  *(undefined1 *)(iVar2 + 0x12e) = 0xff;
  *(undefined1 *)(iVar2 + 0x12f) = 0xff;
  return iVar2 + -0x14c;
}


// FUNC 0x15012fa0 FUN_15012fa0 (MainMenu)
//   size 0x44 | file MainMenu+0x12fa0 | callers(7) 0x150076c0 0x1500df8c 0x150176ac 0x1501e420 0x150207d8 0x15021ccc 0x15009748 | datarefs 2

int FUN_15012fa0(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)FUN_150159f4();
  *puVar1 = &msys::MMsg::vtable;
  iVar2 = MessageSimple::MessageSimple((MessageSimple *)(puVar1 + 0x53));
  *(undefined4 *)(iVar2 + 0x6ae0) = 0;
  *(undefined1 *)(iVar2 + 0x6ae4) = 0;
  *(undefined1 *)(iVar2 + 0x6ae5) = 0;
  *(undefined4 *)(iVar2 + 0x6ae8) = 0;
  *(undefined4 *)(iVar2 + 0x6aec) = 0;
  *(undefined4 *)(iVar2 + 0x6af4) = 0x400;
  return iVar2 + -0x14c;
}


// FUNC 0x15012fe8 FUN_15012fe8 (MainMenu)
//   size 0xa0 | file MainMenu+0x12fe8 | callers(4) 0x15006a60 0x1500d8bc 0x1501dd60 0x15022040

void FUN_15012fe8(TaskBase *param_1,Resource *param_2,FileContext *param_3,char *param_4,
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


// FUNC 0x15013088 FUN_15013088 (MainMenu)
//   size 0x140 | file MainMenu+0x13088 | callers(1) 0x15013468

void FUN_15013088(int param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  bool bVar8;
  uint in_fpscr;
  undefined4 local_30 [3];
  
  uVar3 = 0;
  iVar1 = *(int *)(param_1 + 0x868);
  iVar7 = param_1 + (short)param_2 * 0xed8;
  local_30[0] = VectorSignedToFloat(*(undefined4 *)(iVar1 + 0x14),(byte)(in_fpscr >> 0x16) & 3);
  local_30[1] = VectorSignedToFloat(*(undefined4 *)(iVar1 + 0x18),(byte)(in_fpscr >> 0x16) & 3);
  local_30[2] = VectorSignedToFloat(*(undefined4 *)(iVar1 + 0x1c),(byte)(in_fpscr >> 0x16) & 3);
  do {
    iVar5 = iVar7 + uVar3 * 0x17c;
    piVar6 = (int *)(iVar5 + 0x76ac);
    iVar1 = (**(code **)(*piVar6 + 0x24))(piVar6);
    if (iVar1 == 0) {
      uVar2 = *(uint *)(iVar5 + 0x7800);
      if (uVar2 == 0) {
LAB_15013150:
        uVar4 = local_30[param_2];
        iVar7 = iVar7 + uVar3 * 0x17c;
        MoveVBase::stop((MoveVBase *)(iVar7 + 0x7778));
        *(undefined4 *)(iVar7 + 0x7794) = 0;
        *(undefined4 *)(iVar7 + 0x7798) = uVar4;
        *(undefined4 *)(iVar7 + 0x779c) = 0;
        *(undefined4 *)(iVar7 + 0x777c) = 0;
        *(undefined4 *)(iVar7 + 0x7780) = uVar4;
        *(undefined4 *)(iVar7 + 0x7784) = 0;
        msys::MDfxChr::setCA
                  ((MDfxChr *)(iVar7 + 0x76ac),(CellAnime *)(param_1 + param_2 * 0x27c + 0x1e128));
        msys::MDfxChr::playDfx((MDfxChr *)(iVar7 + 0x76ac),param_3);
        return;
      }
      bVar8 = *(int *)(uVar2 + 4) == uVar2 + 4;
      if (bVar8) {
        uVar2 = (uint)*(byte *)(uVar2 + 0x172);
      }
      if (bVar8 && uVar2 == 0) goto LAB_15013150;
    }
    uVar3 = uVar3 + 1 & 0xff;
    if (9 < uVar3) {
      return;
    }
  } while( true );
}


// FUNC 0x150131d0 FUN_150131d0 (MainMenu)
//   size 0x280 | file MainMenu+0x131d0 | callers(5) 0x1502166c 0x15021818 0x15005ee0 0x15021a04 0x150063b0

void FUN_150131d0(int param_1)

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
      iVar3 = msys::MCtrlUserData::findExtUserDataByName(this,&DAT_003f7ffd);
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
      local_50[0] = s_SQ_CURSOR_S_003f8001;
      local_50[1] = s_SQ_CURSOR_L_003f800d;
      local_50[2] = s_SQ_CURSOR_SS_003f8019;
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


// FUNC 0x15013468 FUN_15013468 (MainMenu)
//   size 0x440 | file MainMenu+0x13468 | callers(1) 0x1500590c

void FUN_15013468(int param_1,int param_2,int param_3,undefined4 param_4)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  DataPc *this;
  
  iVar2 = msys::MComSys::_sys;
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  else {
    iVar2 = *(int *)(param_1 + 8);
  }
  this = (DataPc *)(iVar2 + param_3 * 0xb0 + 0xeac64);
  switch(*(undefined2 *)(param_2 + 0x66)) {
  case 0x1000:
    if (*(short *)(param_2 + 0x68) == 0) {
      uVar3 = DataPc::getHpMax(this);
    }
    else {
      iVar2 = DataPc::getHpNow(this);
      uVar3 = iVar2 + (uint)*(ushort *)(param_2 + 0x68);
    }
    uVar3 = uVar3 & 0xffff;
    uVar4 = DataPc::getHpMax(this);
    if (uVar4 < uVar3) {
      uVar3 = DataPc::getHpMax(this);
    }
    DataPc::setHpNow(this,(ushort)uVar3);
    FUN_1501580c(msys::MComSys::_sys + 0x49368,0x110019,0,0,0);
    uVar3 = (uint)*(ushort *)(param_2 + 0x68);
    if (uVar3 == 0) {
LAB_15013598:
      uVar5 = 4;
    }
    else if (DAT_003f887c < uVar3) {
      if (DAT_003f8880 < uVar3) {
        if (DAT_003f8884 < uVar3) goto LAB_15013598;
        uVar5 = 3;
      }
      else {
        uVar5 = 2;
      }
    }
    else {
      uVar5 = 1;
    }
    goto LAB_1501359c;
  case 0x1001:
    if (*(short *)(param_2 + 0x68) == 0) {
      uVar3 = DataPc::getBpMax(this);
    }
    else {
      iVar2 = DataPc::getBpNow(this);
      uVar3 = iVar2 + (uint)*(ushort *)(param_2 + 0x68);
    }
    uVar3 = uVar3 & 0xffff;
    uVar4 = DataPc::getBpMax(this);
    if (uVar4 < uVar3) {
      uVar3 = DataPc::getBpMax(this);
    }
    DataPc::setBpNow(this,(ushort)uVar3);
    FUN_1501580c(msys::MComSys::_sys + 0x49368,0x110019,0,0,0);
    uVar3 = (uint)*(ushort *)(param_2 + 0x68);
    if (uVar3 == 0) {
LAB_15013668:
      uVar5 = 8;
    }
    else if (DAT_003f888c < uVar3) {
      if (DAT_003f8890 < uVar3) {
        if (DAT_003f8894 < uVar3) goto LAB_15013668;
        uVar5 = 7;
      }
      else {
        uVar5 = 6;
      }
    }
    else {
      uVar5 = 5;
    }
    goto LAB_1501359c;
  case 0x1004:
    uVar1 = DataPc::getHpMax(this);
    DataPc::setHpNow(this,uVar1);
    uVar1 = DataPc::getBpMax(this);
    DataPc::setBpNow(this,uVar1);
    FUN_1501580c(msys::MComSys::_sys + 0x49368,0x110019,0,0,0);
    uVar5 = 9;
LAB_1501359c:
    FUN_15013088(param_1,param_3,uVar5);
    break;
  case 0x1005:
    DataPc::addStatus(this,(int)*(short *)(param_2 + 0x68),0,0,param_4);
    FUN_15013088(param_1,param_3,10);
    FUN_1501580c(msys::MComSys::_sys + 0x49368,0x11001a,0,0,0);
    break;
  case 0x1006:
    DataPc::addStatus(this,(int)*(short *)(param_2 + 0x68),1,0,param_4);
    FUN_15013088(param_1,param_3,0xb);
    FUN_1501580c(msys::MComSys::_sys + 0x49368,0x11001a,0,0,0);
    break;
  case 0x1007:
    DataPc::addStatus(this,(int)*(short *)(param_2 + 0x68),2,0,param_4);
    FUN_15013088(param_1,param_3,0xe);
    FUN_1501580c(msys::MComSys::_sys + 0x49368,0x11001a,0,0,0);
    break;
  case 0x1008:
    DataPc::addStatus(this,(int)*(short *)(param_2 + 0x68),3,0,param_4);
    FUN_15013088(param_1,param_3,0xf);
    FUN_1501580c(msys::MComSys::_sys + 0x49368,0x11001a,0,0,0);
    break;
  case 0x1009:
    DataPc::addStatus(this,(int)*(short *)(param_2 + 0x68),4,0,param_4);
    FUN_15013088(param_1,param_3,0xc);
    FUN_1501580c(msys::MComSys::_sys + 0x49368,0x11001a,0,0,0);
    break;
  case 0x100a:
    DataPc::addStatus(this,(int)*(short *)(param_2 + 0x68),5,0,param_4);
    FUN_15013088(param_1,param_3,0xd);
    FUN_1501580c(msys::MComSys::_sys + 0x49368,0x11001a,0,0,0);
  }
  DataPc::write(this,(DataPcPOD *)(&gGameWork + param_3 * 0x34));
  return;
}


// FUNC 0x150138ec FUN_150138ec (MainMenu)
//   size 0x1e4 | file MainMenu+0x138ec | callers(4) 0x150075c4 0x15004cbc 0x15006d44 0x150060cc

void FUN_150138ec(int param_1)

{
  ushort uVar1;
  ushort uVar2;
  undefined2 *puVar3;
  ushort *puVar4;
  int iVar5;
  StatusPanel *this;
  StatusPanel *this_00;
  StatusPanel *this_01;
  StatusPanel *this_02;
  StatusPanel *this_03;
  
  msys::MListWndPBase::getListWnd((MListWndPBase *)(param_1 + 0x1e778));
  puVar3 = (undefined2 *)ad::ui::UIListWindowPlusLyt::getCurItem();
  this_03 = (StatusPanel *)(param_1 + 0x11730);
  this_02 = (StatusPanel *)(param_1 + 0x13764);
  this_01 = (StatusPanel *)(param_1 + 0x15798);
  this_00 = (StatusPanel *)(param_1 + 0x177cc);
  this = (StatusPanel *)(param_1 + 0x1b834);
  if ((puVar3 != (undefined2 *)0x0) &&
     (FUN_15013ad0(param_1,*puVar3), *(char *)(param_1 + 0x870) != '\x02')) {
    puVar4 = (ushort *)msys::MListWndPBase::getCurItem();
    iVar5 = ad::db::GetUseItem(*puVar4);
    uVar1 = *(ushort *)(iVar5 + 0x6a);
    if ((uVar1 & 0x20) != 0) {
      uVar2 = uVar1 >> 9;
      if (uVar2 == 0) {
        msys::StatusPanel::setHi(this_03,uVar1 & 0x1f);
        msys::StatusPanel::setHi(this_02,*(byte *)(iVar5 + 0x6a) & 0x1f);
        msys::StatusPanel::setHi(this_01,*(byte *)(iVar5 + 0x6a) & 0x1f);
        msys::StatusPanel::setHi(this_00,*(byte *)(iVar5 + 0x6a) & 0x1f);
        msys::StatusPanel::setHi((StatusPanel *)(param_1 + 0x19800),*(byte *)(iVar5 + 0x6a) & 0x1f);
        msys::StatusPanel::setHi(this,*(byte *)(iVar5 + 0x6a) & 0x1f);
        return;
      }
      if (uVar2 == 1) {
        msys::StatusPanel::setHi(this_03,uVar1 & 0x1f);
        msys::StatusPanel::setHi(this_02,*(byte *)(iVar5 + 0x6a) & 0x1f);
        msys::StatusPanel::setLow(this_01);
        msys::StatusPanel::setHi(this_00,*(byte *)(iVar5 + 0x6a) & 0x1f);
        msys::StatusPanel::setHi((StatusPanel *)(param_1 + 0x19800),*(byte *)(iVar5 + 0x6a) & 0x1f);
        msys::StatusPanel::setLow(this);
        return;
      }
      if (uVar2 == 2) {
        msys::StatusPanel::setLow(this_03);
        msys::StatusPanel::setLow(this_02);
        msys::StatusPanel::setHi(this_01,*(byte *)(iVar5 + 0x6a) & 0x1f);
        msys::StatusPanel::setLow(this_00);
        msys::StatusPanel::setLow((StatusPanel *)(param_1 + 0x19800));
        msys::StatusPanel::setHi(this,*(byte *)(iVar5 + 0x6a) & 0x1f);
        return;
      }
      return;
    }
  }
  msys::StatusPanel::resetHi(this_03);
  msys::StatusPanel::resetHi(this_02);
  msys::StatusPanel::resetHi(this_01);
  msys::StatusPanel::resetHi(this_00);
  msys::StatusPanel::resetHi((StatusPanel *)(param_1 + 0x19800));
  msys::StatusPanel::resetHi(this);
  return;
}


// FUNC 0x15013ad0 FUN_15013ad0 (MainMenu)
//   size 0xbc | file MainMenu+0x13ad0 | callers(4) 0x15004cbc 0x150138ec 0x150075c4 0x15006188

void FUN_15013ad0(int param_1,int param_2)

{
  int iVar1;
  wchar_t *pwVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 auStack_50 [68];
  
  if (*(char *)(param_1 + 0x870) != '\x02') {
    pwVar2 = (wchar_t *)ad::db::GetItemMsg(param_2,2);
    msys::MMsg::playStr((MMsg *)(param_1 + 0xa68),pwVar2,(InsParam *)0x0,false);
    return;
  }
  __2sprintf(auStack_50,"MES_MenuMes_EventItem%s",*(undefined4 *)(&DAT_15024c6c + param_2 * 0x14));
  iVar1 = msys::MComSys::_sys;
  iVar3 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar3 = iVar1;
  }
  uVar4 = LMS_GetTextIndexByLabel(iVar3 + 0xeae90,auStack_50);
  pwVar2 = (wchar_t *)LMS_GetText(iVar3 + 0xeae90,uVar4);
  msys::MMsg::playStr((MMsg *)(param_1 + 0xa68),pwVar2,(InsParam *)0x0,false);
  return;
}


// FUNC 0x15013bb0 FUN_15013bb0 (MainMenu)
//   size 0x17c | file MainMenu+0x13bb0 | callers(3) 0x15004cbc 0x15006534 0x150075c4

void FUN_15013bb0(MListWndPBase *param_1,undefined4 param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  UIListWindowPlusLyt *this;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uint in_fpscr;
  float fVar6;
  
  this = (UIListWindowPlusLyt *)msys::MListWndPBase::getListWnd(param_1);
  ad::ui::UIListWindowPlusLyt::updateInstant(this);
  iVar3 = msys::MListWndPBase::getListWnd(param_1);
  *(ushort *)(param_1 + *(short *)(param_1 + 0x791c) * 2 + 0x791e) =
       (ushort)*(byte *)(iVar3 + 0x149);
  iVar3 = msys::MListWndPBase::getListWnd(param_1);
  *(ushort *)(param_1 + *(short *)(param_1 + 0x791c) * 2 + 0x7924) =
       (ushort)*(byte *)(iVar3 + 0x148);
  *(short *)(param_1 + 0x791c) = (short)param_2;
  iVar3 = FUN_150043e4(param_1,param_2);
  iVar4 = msys::MListWndPBase::getListWnd(param_1);
  *(char *)(iVar4 + 0x144) = (char)iVar3;
  if (0 < iVar3) {
    if (iVar3 <= *(short *)(param_1 + *(short *)(param_1 + 0x791c) * 2 + 0x791e)) {
      *(short *)(param_1 + *(short *)(param_1 + 0x791c) * 2 + 0x791e) = (short)iVar3 + -1;
    }
    if (iVar3 <= *(short *)(param_1 + *(short *)(param_1 + 0x791c) * 2 + 0x7924)) {
      *(short *)(param_1 + *(short *)(param_1 + 0x791c) * 2 + 0x7924) = (short)iVar3 + -1;
    }
  }
  iVar4 = msys::MListWndPBase::getListWnd(param_1);
  *(MListWndPBase *)(iVar4 + 0x148) = param_1[*(short *)(param_1 + 0x791c) * 2 + 0x7924];
  iVar4 = msys::MListWndPBase::getListWnd(param_1);
  *(undefined4 *)(iVar4 + 0x14c) =
       *(undefined4 *)
        (param_1 + *(short *)(param_1 + *(short *)(param_1 + 0x791c) * 2 + 0x791e) * 0x1c + 0x6f80);
  iVar4 = msys::MListWndPBase::getListWnd(param_1);
  *(undefined1 *)(iVar4 + 0x149) = 0;
  iVar4 = msys::MListWndPBase::getListWnd(param_1);
  uVar1 = *(undefined1 *)(iVar4 + 0x6b);
  iVar4 = msys::MListWndPBase::getListWnd(param_1);
  uVar2 = *(undefined1 *)(iVar4 + 0x144);
  iVar4 = msys::MListWndPBase::getListWnd(param_1);
  FUN_15013d30(iVar4 + 0x148,param_1 + 0x6f80,uVar2,uVar1);
  if (iVar3 == 0) {
    ad::lyt::LytAnim::stopAndSetFrm((LytAnim *)(param_1 + 0x76a8),0.0);
    return;
  }
  uVar5 = ad::lyt::AnimTransform::GetFrameSize(*(AnimTransform **)(param_1 + 0x76bc));
  fVar6 = (float)VectorUnsignedToFloat(uVar5,(byte)(in_fpscr >> 0x16) & 3);
  ad::lyt::LytAnim::stopAndSetFrm((LytAnim *)(param_1 + 0x76a8),fVar6);
  return;
}


// FUNC 0x15013d30 FUN_15013d30 (MainMenu)
//   size 0x184 | file MainMenu+0x13d30 | callers(3) 0x150124a8 0x15013bb0 0x15011800

void FUN_15013d30(byte *param_1,int *param_2,uint param_3,uint param_4)

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
        if (*piVar7 == *(int *)(param_1 + 4)) goto LAB_15013dc4;
        iVar6 = iVar6 + 1;
        piVar7 = piVar7 + 7;
        iVar8 = (int)((longlong)(int)uVar4 * -0x6db6db6d + ((ulonglong)uVar4 << 0x20) >> 0x20);
      } while (iVar6 < ((iVar8 >> 4) - (iVar8 >> 0x1f)) + 1);
    }
  }
  else if (param_2 != piVar5) {
    do {
      if (*piVar7 == *(int *)(param_1 + 4)) goto LAB_15013dc4;
      piVar7 = piVar7 + 7;
    } while (piVar7 != piVar5);
  }
LAB_15013e58:
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
LAB_15013dc4:
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
  goto LAB_15013e58;
}


// FUNC 0x15013eb8 FUN_15013eb8 (MainMenu)
//   size 0x3f4 | file MainMenu+0x13eb8 | callers(3) 0x150043e4 0x1500590c 0x15006d44

/* WARNING: Type propagation algorithm not settling */

byte FUN_15013eb8(int param_1,int param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  ushort uVar7;
  
  iVar4 = msys::MComSys::_sys;
  if ((*(byte *)(param_2 + 0x6a) & 0x20) == 0) {
    return *(byte *)(param_2 + 0x6a) & 0x20;
  }
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  bVar1 = *(byte *)(*(int *)(param_1 + 8) + param_3 * 0xb0 + 0xeac9a);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = iVar4;
  }
  iVar4 = *(int *)(param_1 + 8) + param_3 * 0xb0;
  *(ushort *)(iVar4 + 0xeac9a) = *(ushort *)(iVar4 + 0xeac9a) & 0xfffb;
  *(undefined4 *)(iVar4 + 0xeac9c) = 0;
  iVar4 = msys::MComSys::_sys;
  switch(*(byte *)(param_2 + 0x6a) & 0x1f) {
  default:
    goto switchD_15013f38_caseD_0;
  case 1:
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar4;
    }
    uVar6 = DataPc::getHpNow((DataPc *)(iVar2 + param_3 * 0xb0 + 0xeac64));
    iVar2 = msys::MComSys::_sys;
    iVar4 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar4 = iVar2;
    }
    uVar5 = DataPc::getHpMax((DataPc *)(iVar4 + param_3 * 0xb0 + 0xeac64));
    if (uVar6 < uVar5) goto switchD_15013f38_caseD_0;
    goto LAB_150142a0;
  case 2:
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar4;
    }
    uVar6 = DataPc::getBpNow((DataPc *)(iVar2 + param_3 * 0xb0 + 0xeac64));
    iVar2 = msys::MComSys::_sys;
    iVar4 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar4 = iVar2;
    }
    uVar5 = DataPc::getBpMax((DataPc *)(iVar4 + param_3 * 0xb0 + 0xeac64));
    if (uVar5 <= uVar6) goto LAB_150142a0;
    goto switchD_15013f38_caseD_0;
  case 5:
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar4;
    }
    uVar6 = DataPc::getHpNow((DataPc *)(iVar2 + param_3 * 0xb0 + 0xeac64));
    iVar2 = msys::MComSys::_sys;
    iVar4 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar4 = iVar2;
    }
    uVar5 = DataPc::getHpMax((DataPc *)(iVar4 + param_3 * 0xb0 + 0xeac64));
    iVar4 = msys::MComSys::_sys;
    if (uVar5 <= uVar6) {
      iVar2 = *(int *)(param_1 + 8);
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar2 = iVar4;
      }
      uVar6 = DataPc::getBpNow((DataPc *)(iVar2 + param_3 * 0xb0 + 0xeac64));
      iVar2 = msys::MComSys::_sys;
      iVar4 = *(int *)(param_1 + 8);
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar4 = iVar2;
      }
      uVar5 = DataPc::getBpMax((DataPc *)(iVar4 + param_3 * 0xb0 + 0xeac64));
      if (uVar5 <= uVar6) goto LAB_150142a0;
    }
    goto switchD_15013f38_caseD_0;
  case 6:
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar4;
    }
    uVar6 = DataPc::getHpMax((DataPc *)(iVar2 + param_3 * 0xb0 + 0xeac64));
    break;
  case 7:
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar4;
    }
    uVar6 = DataPc::getBpMax((DataPc *)(iVar2 + param_3 * 0xb0 + 0xeac64));
    break;
  case 8:
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar4;
    }
    uVar6 = DataPc::getPow((DataPc *)(iVar2 + param_3 * 0xb0 + 0xeac64));
    break;
  case 9:
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar4;
    }
    uVar6 = DataPc::getDef((DataPc *)(iVar2 + param_3 * 0xb0 + 0xeac64));
    break;
  case 10:
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar4;
    }
    uVar6 = DataPc::getSpd((DataPc *)(iVar2 + param_3 * 0xb0 + 0xeac64));
    break;
  case 0xb:
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar4;
    }
    uVar6 = DataPc::getHige((DataPc *)(iVar2 + param_3 * 0xb0 + 0xeac64));
    break;
  case 0xc:
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar4;
    }
    uVar6 = DataPc::getHpMax((DataPc *)(iVar2 + param_3 * 0xb0 + 0xeac64));
    iVar4 = msys::MComSys::_sys;
    if (0x3e6 < uVar6) {
      iVar2 = *(int *)(param_1 + 8);
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar2 = iVar4;
      }
      uVar6 = DataPc::getBpMax((DataPc *)(iVar2 + param_3 * 0xb0 + 0xeac64));
      iVar4 = msys::MComSys::_sys;
      if (0x3e6 < uVar6) {
        iVar2 = *(int *)(param_1 + 8);
        if (*(int *)(param_1 + 8) == 0) {
          *(int *)(param_1 + 8) = msys::MComSys::_sys;
          iVar2 = iVar4;
        }
        uVar6 = DataPc::getPow((DataPc *)(iVar2 + param_3 * 0xb0 + 0xeac64));
        iVar4 = msys::MComSys::_sys;
        if (0x3e6 < uVar6) {
          iVar2 = *(int *)(param_1 + 8);
          if (*(int *)(param_1 + 8) == 0) {
            *(int *)(param_1 + 8) = msys::MComSys::_sys;
            iVar2 = iVar4;
          }
          uVar6 = DataPc::getDef((DataPc *)(iVar2 + param_3 * 0xb0 + 0xeac64));
          iVar4 = msys::MComSys::_sys;
          if (0x3e6 < uVar6) {
            iVar2 = *(int *)(param_1 + 8);
            if (*(int *)(param_1 + 8) == 0) {
              *(int *)(param_1 + 8) = msys::MComSys::_sys;
              iVar2 = iVar4;
            }
            uVar6 = DataPc::getSpd((DataPc *)(iVar2 + param_3 * 0xb0 + 0xeac64));
            iVar4 = msys::MComSys::_sys;
            if (0x3e6 < uVar6) {
              iVar2 = *(int *)(param_1 + 8);
              if (*(int *)(param_1 + 8) == 0) {
                *(int *)(param_1 + 8) = msys::MComSys::_sys;
                iVar2 = iVar4;
              }
              uVar6 = DataPc::getHige((DataPc *)(iVar2 + param_3 * 0xb0 + 0xeac64));
              break;
            }
          }
        }
      }
    }
    goto switchD_15013f38_caseD_0;
  }
  if (uVar6 < 999) {
switchD_15013f38_caseD_0:
    bVar3 = 1;
  }
  else {
LAB_150142a0:
    bVar3 = 0;
  }
  iVar2 = msys::MComSys::_sys;
  iVar4 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar4 = iVar2;
  }
  iVar4 = iVar4 + param_3 * 0xb0;
  if ((bVar1 & 7) >> 2 == 0) {
    uVar7 = *(ushort *)(iVar4 + 0xeac9a) & 0xfffb;
  }
  else {
    uVar7 = *(ushort *)(iVar4 + 0xeac9a) | 4;
  }
  *(ushort *)(iVar4 + 0xeac9a) = uVar7;
  *(undefined4 *)(iVar4 + 0xeac9c) = 0;
  return bVar3;
}


// FUNC 0x150142ec FUN_150142ec (MainMenu)
//   size 0x134 | file MainMenu+0x142ec | callers(13) 0x1500a5c0 0x1500bef8 0x1500db40 0x15020394 0x15003edc 0x1500674c 0x1500e6b0 0x15020be8 ...

void FUN_150142ec(int param_1)

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


// FUNC 0x15014438 FUN_15014438 (MainMenu)
//   size 0x94 | file MainMenu+0x14438 | callers(8) 0x15003c14 0x150076c0 0x15009458 0x1500df8c 0x150176ac 0x1501e420 0x150207d8 0x15021ccc

int FUN_15014438(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  
  *param_1 = &main_menu::MainMenuPageBase::Core::vtable;
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
  iVar1 = FUN_150153d8(iVar1 + 0x44);
  iVar1 = FUN_150153d8(iVar1 + 0x3a8);
  *(undefined1 *)(iVar1 + 0x3ac) = 0xff;
  *(undefined1 *)(iVar1 + 0x3ad) = 0xff;
  return iVar1 + -0x4b8;
}


// FUNC 0x150144d8 FUN_150144d8 (MainMenu)
//   size 0x7c | file MainMenu+0x144d8 | callers(8) 0x15003510 0x15006a60 0x15009374 0x1500d8bc 0x15016f28 0x1501dd60 0x15020358 0x1502178c

void FUN_150144d8(int param_1)

{
  int *piVar1;
  void *pvVar2;
  int iVar3;
  IAllocator *pIVar4;
  undefined4 uVar5;
  
  piVar1 = *(int **)(*(int *)(param_1 + 4) + 0x18);
  pvVar2 = (void *)(**(code **)(*piVar1 + 0xc))(piVar1,0x400000,0);
  MemAlc::initCore((MemAlc *)(param_1 + 0x28),pvVar2,0x400000);
  iVar3 = ad::lyt::LytDrawSys::GetInst();
  uVar5 = *(undefined4 *)(*(int *)(param_1 + 4) + 0x18);
  pIVar4 = (IAllocator *)(iVar3 + 0x5f4);
  if (ad::lyt::Layout::s_pAllocator != pIVar4) {
    ad::lyt::Initialize(pIVar4,pIVar4);
  }
  *(undefined4 *)(iVar3 + 0x5f8) = uVar5;
  iVar3 = ad::lyt::LytDrawSys::GetInst();
  *(undefined4 *)(iVar3 + 0x5fc) = 0x10000;
  return;
}


// FUNC 0x15014558 FUN_15014558 (MainMenu)
//   size 0x210 | file MainMenu+0x14558 | callers(10) 0x15002d7c 0x150030a0 0x15008308 0x150083c0 0x15008478 0x15008510 0x15008618 0x15008740 ...

void FUN_15014558(int param_1,undefined4 param_2)

{
  Message *this;
  int iVar1;
  uint uVar2;
  uint uVar3;
  wchar_t *pwVar4;
  uint in_fpscr;
  undefined4 uVar5;
  undefined4 uVar6;
  Message *local_d8;
  undefined4 local_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 local_98;
  undefined1 local_94;
  undefined1 local_93;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined1 local_80;
  undefined1 local_7f;
  undefined4 local_78;
  undefined4 uStack_74;
  undefined1 local_70;
  undefined1 local_6f;
  undefined4 local_6c;
  MTX34 aMStack_68 [48];
  
  *(undefined4 *)(param_1 + 0xf1e70) = param_2;
  this = (Message *)(param_1 + 0xeb0c4);
  Message::play(this,(PlayParam *)(param_1 + 0xf1e70));
  iVar1 = msys::MChrBaseCore::getGlbMtx((MChrBaseCore *)(param_1 + 0xf1ec4),aMStack_68);
  uVar5 = *(undefined4 *)(iVar1 + 0xc);
  uVar6 = *(undefined4 *)(iVar1 + 0x1c);
  local_c4 = 0;
  local_c0 = 0;
  local_b0 = 0;
  local_ac = 0;
  local_a8 = 0;
  local_bc = 0xc1000000;
  local_b8 = 0x42000000;
  local_b4 = 0x41000000;
  local_98 = 0;
  local_a4 = 0xc1000000;
  uStack_a0 = 0x42000000;
  uStack_9c = 0x41000000;
  local_d4 = 0xc3480000;
  uStack_d0 = 0x42f00000;
  uStack_cc = 0x43480000;
  uStack_c8 = 0xc2f00000;
  local_94 = 5;
  local_93 = 8;
  local_90 = 0x45800000;
  local_8c = 0xc1a00000;
  local_88 = 0;
  local_84 = 0;
  local_80 = 0;
  local_7f = 0;
  local_d8 = this;
  uVar2 = Grp::GetLcdWidth(0x401);
  uVar3 = Grp::GetLcdHeight(0x401);
  uStack_c8 = VectorSignedToFloat((int)-uVar3 / 2,(byte)(in_fpscr >> 0x16) & 3);
  local_b8 = 0x42200000;
  local_b4 = 0x41700000;
  local_d4 = VectorSignedToFloat((int)-uVar2 / 2,(byte)(in_fpscr >> 0x16) & 3);
  uStack_d0 = VectorUnsignedToFloat(uVar3 >> 1,(byte)(in_fpscr >> 0x16) & 3);
  uStack_cc = VectorUnsignedToFloat(uVar2 >> 1,(byte)(in_fpscr >> 0x16) & 3);
  local_b0 = 0;
  local_bc = 0xc1700000;
  local_80 = 0;
  local_c4 = uVar5;
  local_c0 = uVar6;
  MsgWndPosCalculator::calc((MsgWndPosCalculator *)&local_d8,(Result *)&local_78);
  uVar5 = *(undefined4 *)(param_1 + 0xeb050);
  MoveVBase::stop((MoveVBase *)(param_1 + 0xeb044));
  *(undefined4 *)(param_1 + 0xeb068) = uVar5;
  *(undefined4 *)(param_1 + 0xeb060) = local_78;
  *(undefined4 *)(param_1 + 0xeb064) = uStack_74;
  *(undefined4 *)(param_1 + 0xeb050) = uVar5;
  *(undefined4 *)(param_1 + 0xeb048) = local_78;
  *(undefined4 *)(param_1 + 0xeb04c) = uStack_74;
  *(undefined1 *)(param_1 + 0xf0906) = local_6f;
  uVar5 = LMS_GetTextIndexByLabel(param_1 + 0xeae90,param_2);
  pwVar4 = (wchar_t *)LMS_GetText(param_1 + 0xeae90,uVar5);
  uVar5 = MessageSimple::getMsgHeight((MessageSimple *)this,pwVar4);
  uVar2 = VectorFloatToUnsigned(uVar5,3);
  if (uVar2 < 0x47) {
    *(undefined4 *)(param_1 + 0xf0908) = local_6c;
  }
  else {
    *(undefined4 *)(param_1 + 0xf0908) = 0x42200000;
    local_70 = 3;
  }
  *(undefined1 *)(param_1 + 0xf0905) = local_70;
  *(undefined1 *)(param_1 + 0xf1bca) = 1;
  return;
}


// FUNC 0x150147a8 FUN_150147a8 (MainMenu)
//   size 0xec | file MainMenu+0x147a8 | callers(7) 0x150030a0 0x15008308 0x15008618 0x15008740 0x15008868 0x150088d8 0x150089f8

undefined4 FUN_150147a8(int param_1)

{
  int iVar1;
  float fVar2;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  iVar1 = msys::MChrBaseCore::isBusySRTMov((MChrBaseCore *)(param_1 + 0xf1ec4));
  if (iVar1 != 0) {
    return 1;
  }
  fVar2 = 1.0;
  if (*(int *)(param_1 + 0xf1eb0) != 0) {
    *(int *)(param_1 + 0xf1eb0) = *(int *)(param_1 + 0xf1eb0) + -1;
    CellAnime::play((CellAnime *)(param_1 + 0xf2010),'\f',0,1.0);
    local_20 = 0;
    local_1c = 0x3f800000;
    local_18 = 0;
    msys::MChrBaseCore::jumpFT((MChrBaseCore *)(param_1 + 0xf1ec4),0.0,20.0,20.0,(VEC3 *)&local_20);
    return 1;
  }
  if ((*(byte *)(param_1 + 0xf1ec2) & 1) != 0) {
    iVar1 = ad::fw::TaskBase::isFps30(*(TaskBase **)(param_1 + 4));
    if (iVar1 != 0) {
      fVar2 = 2.0;
    }
    iVar1 = Frm::update(fVar2);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}


// FUNC 0x150148b0 FUN_150148b0 (MainMenu)
//   size 0x78 | file MainMenu+0x148b0 | callers(7) 0x15002fd4 0x150082b4 0x150085a4 0x150086cc 0x150087f4 0x15008868 0x15008984

void FUN_150148b0(undefined4 param_1,undefined4 param_2,int param_3,uchar param_4,undefined4 param_5
                 )

{
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 local_18;
  
  CellAnime::play((CellAnime *)(param_3 + 0xf2010),param_4,0,1.0);
  local_18 = 0xc2c60000;
  local_20 = param_1;
  uStack_1c = param_2;
  MoveVBase::moveAbs((MoveVBase *)(param_3 + 0xf1f90),(VEC3 *)&local_20,2.0);
  Frm::play((Frm *)(param_3 + 0xf1eb4),30.0);
  *(undefined4 *)(param_3 + 0xf1eb0) = param_5;
  return;
}


// FUNC 0x15014940 FUN_15014940 (MainMenu)
//   size 0x36c | file MainMenu+0x14940 | callers(6) 0x1500359c 0x1500387c 0x15002f40 0x15002a04 0x150032a4 0x15002a9c

bool FUN_15014940(uint *param_1,byte param_2)

{
  short sVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint in_fpscr;
  float fVar8;
  float fVar9;
  float fVar10;
  
  sVar1 = *(short *)((int)param_1 + 6);
  uVar2 = *param_1;
  fVar10 = 1.0;
  if (sVar1 == 0) {
    uVar6 = 0;
    if (*(char *)(uVar2 + 0x864) == -1) {
      if (param_1[2] == param_1[3]) {
        while( true ) {
          iVar5 = (int)(short)param_1[1];
          if (param_1[iVar5 * 7 + 10] != 0) break;
          if (5 < iVar5) goto LAB_15014a08;
          *(short *)(param_1 + 1) = (short)param_1[1] + 1;
        }
        if (5 < (short)param_1[1]) {
LAB_15014a08:
          sVar1 = 1;
          goto LAB_15014a0c;
        }
        ad::lyt::LytAnim::playAuto((LytAnim *)(param_1 + iVar5 * 7 + 5),1.0);
        param_1[2] = 0;
        *(short *)(param_1 + 1) = (short)param_1[1] + 1;
      }
      param_1[2] = param_1[2] + 1;
      goto LAB_15014b98;
    }
    do {
      if (param_1[uVar6 * 7 + 10] != 0) {
        ad::lyt::LytAnim::playAuto((LytAnim *)(param_1 + uVar6 * 7 + 5),1.0);
      }
      uVar6 = uVar6 + 1 & 0xff;
    } while (uVar6 < 6);
LAB_150149cc:
    sVar1 = *(short *)((int)param_1 + 6) + 1;
  }
  else {
    if (sVar1 == 1) {
      if ((float)param_1[0x2b] != 0.0) {
        param_2 = *(byte *)((int)param_1 + 0xb2);
      }
      if ((float)param_1[0x2b] != 0.0 && (param_2 & 1) != 0) goto LAB_15014b98;
      uVar6 = 0;
      if (*(char *)(uVar2 + 0x864) == -1) {
        do {
          if ((uVar6 != 4) ||
             (fVar9 = (float)GetRegFlag(0xd00c,(GlobalEvent *)0x0,(LocalEvent *)0x0), fVar9 != 0.0))
          {
            ad::lyt::LytAnim::playAuto((LytAnim *)(param_1 + uVar6 * 7 + 0x2f),1.0);
          }
          uVar6 = uVar6 + 1 & 0xff;
        } while (uVar6 < 6);
      }
      goto LAB_150149cc;
    }
    if (sVar1 == 2) {
      puVar3 = param_1 + 0x52;
      uVar2 = in_fpscr & 0xfffffff;
      if ((float)param_1[0x55] != 0.0) {
        puVar3 = (uint *)(uint)*(byte *)((int)param_1 + 0x15a);
      }
      uVar6 = 0;
      if ((float)param_1[0x55] == 0.0 || ((uint)puVar3 & 1) == 0) {
        do {
          uVar7 = 0;
          do {
            if (uVar6 == 4) {
              fVar9 = (float)GetRegFlag(0xd00c,(GlobalEvent *)0x0,(LocalEvent *)0x0);
              uVar2 = uVar2 & 0xfffffff;
              if (fVar9 != 0.0) goto LAB_15014b28;
            }
            else {
LAB_15014b28:
              ad::lyt::LytAnim::playAuto((LytAnim *)(param_1 + uVar6 * 0x2a + uVar7 * 7 + 0xad),1.0)
              ;
              iVar5 = ad::lyt::AnimTransform::GetFrameSize
                                ((AnimTransform *)param_1[uVar6 * 0x2a + uVar7 * 7 + 0xb2]);
              iVar4 = RandSys::get((RandSys *)&gRand);
              fVar9 = (float)VectorUnsignedToFloat
                                       ((uint)(iVar4 * iVar5) >> 0x10,(byte)(uVar2 >> 0x16) & 3);
              Frm::setFrm(fVar9);
            }
            uVar7 = uVar7 + 1 & 0xff;
          } while (uVar7 < 6);
          uVar6 = uVar6 + 1 & 0xff;
        } while (uVar6 < 6);
        *(undefined2 *)((int)param_1 + 6) = 100;
      }
      goto LAB_15014b98;
    }
    if (sVar1 != 0x32) goto LAB_15014b98;
    if ((float)param_1[0x2b] != 0.0) {
      uVar2 = (uint)*(byte *)((int)param_1 + 0xb2);
    }
    if ((float)param_1[0x2b] != 0.0 && (uVar2 & 1) != 0) goto LAB_15014b98;
    sVar1 = 100;
  }
LAB_15014a0c:
  *(short *)((int)param_1 + 6) = sVar1;
LAB_15014b98:
  fVar9 = 2.0;
  uVar2 = 0;
  do {
    iVar4 = msys::MComSys::_sys;
    iVar5 = *(int *)(*param_1 + 8);
    if (iVar5 == 0) {
      *(int *)(*param_1 + 8) = msys::MComSys::_sys;
      iVar5 = iVar4;
    }
    iVar5 = ad::fw::TaskBase::isFps30(*(TaskBase **)(iVar5 + 4));
    if (iVar5 == 0) {
      fVar8 = fVar10;
    }
    else {
      fVar8 = fVar9;
    }
    ad::lyt::LytAnim::update((LytAnim *)(param_1 + uVar2 * 7 + 5),fVar8);
    iVar4 = msys::MComSys::_sys;
    iVar5 = *(int *)(*param_1 + 8);
    if (iVar5 == 0) {
      *(int *)(*param_1 + 8) = msys::MComSys::_sys;
      iVar5 = iVar4;
    }
    iVar5 = ad::fw::TaskBase::isFps30(*(TaskBase **)(iVar5 + 4));
    if (iVar5 == 0) {
      fVar8 = fVar10;
    }
    else {
      fVar8 = fVar9;
    }
    ad::lyt::LytAnim::update((LytAnim *)(param_1 + uVar2 * 7 + 0x2f),fVar8);
    uVar6 = 0;
    do {
      iVar4 = msys::MComSys::_sys;
      iVar5 = *(int *)(*param_1 + 8);
      if (iVar5 == 0) {
        *(int *)(*param_1 + 8) = msys::MComSys::_sys;
        iVar5 = iVar4;
      }
      iVar5 = ad::fw::TaskBase::isFps30(*(TaskBase **)(iVar5 + 4));
      if (iVar5 == 0) {
        fVar8 = fVar10;
      }
      else {
        fVar8 = fVar9;
      }
      ad::lyt::LytAnim::update((LytAnim *)(param_1 + uVar2 * 0x2a + uVar6 * 7 + 0xad),fVar8);
      uVar6 = uVar6 + 1 & 0xff;
    } while (uVar6 < 6);
    uVar2 = uVar2 + 1 & 0xff;
  } while (uVar2 < 6);
  return *(short *)((int)param_1 + 6) != 100;
}


// FUNC 0x15014cc4 FUN_15014cc4 (MainMenu)
//   size 0xd0 | file MainMenu+0x14cc4 | callers(3) 0x15001f6c 0x1500359c 0x15002a9c

void FUN_15014cc4(int param_1)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  ad::dfx::Unit::kill(*(Unit **)(param_1 + (uint)*(byte *)(param_1 + 0x8b0) * 0x17c + 0xa08));
  bVar3 = *(char *)(param_1 + 0x8b0) == '\0';
  *(bool *)(param_1 + 0x8b0) = bVar3;
  msys::MDfxChr::playDfx((MDfxChr *)(param_1 + (uint)bVar3 * 0x17c + 0x8b4),0x12);
  *(undefined2 *)(*(int *)(param_1 + (uint)*(byte *)(param_1 + 0x8b0) * 0x17c + 0xa08) + 0xf2) = 0;
  iVar1 = msys::MComSys::_sys;
  iVar2 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar2 = iVar1;
  }
  uVar4 = *(undefined4 *)(iVar2 + 0xe9b6c);
  uVar5 = *(undefined4 *)(iVar2 + 0xe9b70);
  param_1 = param_1 + (uint)*(byte *)(param_1 + 0x8b0) * 0x17c;
  MoveVBase::stop((MoveVBase *)(param_1 + 0x980));
  *(undefined4 *)(param_1 + 0x99c) = uVar4;
  *(undefined4 *)(param_1 + 0x9a0) = uVar5;
  *(undefined4 *)(param_1 + 0x9a4) = 0x43480000;
  *(undefined4 *)(param_1 + 0x984) = uVar4;
  *(undefined4 *)(param_1 + 0x988) = uVar5;
  *(undefined4 *)(param_1 + 0x98c) = 0x43480000;
  return;
}


// FUNC 0x15014da0 FUN_15014da0 (MainMenu)
//   size 0x70 | file MainMenu+0x14da0 | callers(4) 0x15001f6c 0x1500359c 0x1500297c 0x15002a9c

void FUN_15014da0(int param_1,short param_2)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  uint in_fpscr;
  float fVar4;
  
  sVar1 = *(short *)(param_1 + 0x10);
  *(short *)(param_1 + 0x10) = param_2;
  if ((int)param_2 == (int)sVar1) {
    return;
  }
  iVar2 = param_1 + sVar1 * 0x1c;
  uVar3 = ad::lyt::AnimTransform::GetFrameSize(*(AnimTransform **)(iVar2 + 0x220));
  fVar4 = (float)VectorUnsignedToFloat(uVar3,(byte)(in_fpscr >> 0x16) & 3);
  ad::lyt::LytAnim::stopAndSetFrm((LytAnim *)(iVar2 + 0x20c),fVar4);
  param_1 = param_1 + *(short *)(param_1 + 0x10) * 0x1c;
  uVar3 = ad::lyt::AnimTransform::GetFrameSize(*(AnimTransform **)(param_1 + 0x178));
  fVar4 = (float)VectorUnsignedToFloat(uVar3,(byte)(in_fpscr >> 0x16) & 3);
  ad::lyt::LytAnim::stopAndSetFrm((LytAnim *)(param_1 + 0x164),fVar4);
  return;
}


// FUNC 0x15014e10 FUN_15014e10 (MainMenu)
//   size 0x280 | file MainMenu+0x14e10 | callers(15) 0x1501629c 0x1501b504 0x15001d68 0x15001f6c 0x1500359c 0x1500f0c4 0x1501a650 0x1500387c ...

void FUN_15014e10(int param_1)

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
      iVar3 = msys::MCtrlUserData::findExtUserDataByName(this,&DAT_1503645a);
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
      local_50[0] = s_SQ_CURSOR_S_1503645e;
      local_50[1] = s_SQ_CURSOR_L_1503646a;
      local_50[2] = s_SQ_CURSOR_SS_15036476;
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


// FUNC 0x15015170 main_menu::MainMenu_TopPage::vfunc_0x0 (MainMenu)
//   size 0x4 | file MainMenu+0x15170 | callers(0) | datarefs 1

undefined4 * main_menu::MainMenu_TopPage::vfunc_0x0(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  undefined4 *puVar5;
  int *piVar6;
  
  *param_1 = &MainMenuPageBase::vtable;
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


// FUNC 0x15015174 main_menu::MainMenuPageBase::vfunc_0x0 (MainMenu)
//   size 0x124 | file MainMenu+0x15174 | callers(17) 0x15015468 0x15001650 0x15003ecc 0x15007bfc 0x15007c0c 0x1500972c 0x1500973c 0x1500e69c ... | datarefs 1

undefined4 * main_menu::MainMenuPageBase::vfunc_0x0(undefined4 *param_1)

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


// FUNC 0x150152a0 main_menu::MainMenuPageBase::Core::vfunc_0x0 (MainMenu)
//   size 0x120 | file MainMenu+0x152a0 | callers(10) 0x150014d8 0x15021b60 0x15003d48 0x15007968 0x15009548 0x1500e2ec 0x1501783c 0x1501e89c ... | datarefs 1

int main_menu::MainMenuPageBase::Core::vfunc_0x0(undefined4 *param_1)

{
  int iVar1;
  MLyt *pMVar2;
  
  *param_1 = &vtable;
  msys::MLyt::term((MLyt *)(param_1 + 0x44));
  pMVar2 = (MLyt *)(param_1 + 0x12e);
  msys::MLyt::term(pMVar2);
  ad::ctrl::ButtonGroup::FreeAll((ButtonGroup *)(param_1 + 0xf));
  ad::fw::Resource::term((Resource *)(param_1 + 0x33));
  ad::lyt::LytResourceMan::term((LytResourceMan *)(param_1 + 0x16));
  Mem::Free((void *)param_1[0xd]);
  param_1[0xd] = 0;
  *(undefined ***)pMVar2 = &msys::MLyt::vtable;
  msys::MLyt::term(pMVar2);
  __aeabi_vec_dtor(param_1 + 0x1da,&LAB_15000e80,0x10,0xc);
  __aeabi_vec_dtor(param_1 + 0x183,&LAB_15000d18,0x1c,0xc);
  iVar1 = msys::MChrBase::vfunc_0x0(pMVar2);
  pMVar2 = (MLyt *)(iVar1 + -0x3a8);
  *(undefined ***)pMVar2 = &msys::MLyt::vtable;
  msys::MLyt::term(pMVar2);
  __aeabi_vec_dtor(iVar1 + -0xf8,&LAB_15000e80,0x10,0xc);
  __aeabi_vec_dtor(iVar1 + -0x254,&LAB_15000d18,0x1c,0xc);
  iVar1 = msys::MChrBase::vfunc_0x0(pMVar2);
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


// FUNC 0x150153d8 FUN_150153d8 (MainMenu)
//   size 0x84 | file MainMenu+0x153d8 | callers(3) 0x150231f4 0x15014438 0x15009458

int FUN_150153d8(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)FUN_150159f4();
  *puVar1 = &msys::MLyt::vtable;
  *(undefined1 *)(puVar1 + 0x53) = 0xff;
  *(undefined2 *)((int)puVar1 + 0x14e) = 0;
  puVar1[0x54] = 0;
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(puVar1 + 0x55,FUN_15012f30,0x1c,0xc);
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(iVar2 + 0x15c,&LAB_15000e50,0x10,0xc);
  *(undefined4 *)(iVar2 + 0xc0) = 0;
  *(undefined1 *)(iVar2 + 0xc4) = 1;
  *(undefined4 *)(iVar2 + 200) = 0;
  *(undefined4 *)(iVar2 + 0xcc) = 0;
  *(undefined1 *)(iVar2 + 0xd0) = 0;
  *(undefined4 *)(iVar2 + 0xd4) = 0;
  *(undefined4 *)(iVar2 + 0xd8) = 0;
  FUN_1502374c(iVar2 + -0xc,0xffffffff);
  return iVar2 + -0x2b0;
}


// FUNC 0x15015468 main_menu::MainMenu::vfunc_0x0 (MainMenu)
//   size 0x374 | file MainMenu+0x15468 | callers(3) 0x15001390 0x150013b8 0x150234f0 | datarefs 1

void main_menu::MainMenu::vfunc_0x0(undefined4 *param_1)

{
  int iVar1;
  MLyt *pMVar2;
  uint uVar3;
  
  *param_1 = &vtable;
  operator_delete((void *)param_1[0x3a4d2]);
  param_1[0x3a4d2] = 0;
  ad::guide::Man::Term();
  msys::MMapIconMan::term((MMapIconMan *)(param_1 + 0x3a85d));
  ad::fw::TaskBase::term((TaskBase *)param_1[1],0);
  MsgDataAcsrBase::term((MsgDataAcsrBase *)(param_1 + 0x3aba2));
  MsgDataAcsrBase::term((MsgDataAcsrBase *)(param_1 + 0x3abbd));
  uVar3 = 0;
  do {
    iVar1 = uVar3 + 0x3ab9f;
    operator_delete((void *)param_1[iVar1]);
    uVar3 = uVar3 + 1;
    param_1[iVar1] = 0;
  } while (uVar3 < 3);
  msys::MLytNumRes::term((MLytNumRes *)(param_1 + 0x211));
  ad::lyt::LytResourceMan::term((LytResourceMan *)(param_1 + 500));
  ad::fw::Resource::term((Resource *)(param_1 + 0x3a46c));
  ad::fw::Resource::term((Resource *)(param_1 + 0x3a47d));
  ad::fw::Resource::term((Resource *)(param_1 + 0x3a48e));
  ad::fw::Resource::term((Resource *)(param_1 + 0x3a49f));
  ad::fw::Resource::term((Resource *)(param_1 + 0x3a4b0));
  param_1[0x3c7b1] = &msys::MCellAnime::vtable;
  iVar1 = CellAnime::~CellAnime((CellAnime *)(param_1 + 0x3c804));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  *(undefined4 *)(iVar1 + -8) = 0;
  *(undefined ***)(iVar1 + -0x6f4c) = &msys::MMsgWnd::vtable;
  Message::term((Message *)(iVar1 + -0x6e00));
  iVar1 = Message::~Message((Message *)(iVar1 + -0x6e00));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  iVar1 = MsgDataAcsrBase::~MsgDataAcsrBase((MsgDataAcsrBase *)(iVar1 + -0x84));
  iVar1 = MsgDataAcsrBase::~MsgDataAcsrBase((MsgDataAcsrBase *)(iVar1 + -0x6c));
  *(undefined ***)(iVar1 + -0x4a0) = &msys::MCellAnime::vtable;
  iVar1 = CellAnime::~CellAnime((CellAnime *)(iVar1 + -0x354));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  __aeabi_vec_dtor(iVar1 + -0x774,&LAB_15000e9c,0x27c,3);
  iVar1 = msys::MDfxChr::~MDfxChr((MDfxChr *)(iVar1 + -0x9f0));
  iVar1 = msys::MDfxChr::~MDfxChr((MDfxChr *)(iVar1 + -0x17c));
  *(undefined4 *)(iVar1 + -0x10) = 0;
  *(undefined4 *)(iVar1 + -0x2c) = 0;
  pMVar2 = (MLyt *)(iVar1 + -0x3e0);
  *(undefined ***)pMVar2 = &msys::MLyt::vtable;
  msys::MLyt::term(pMVar2);
  __aeabi_vec_dtor(iVar1 + -0x130,&LAB_15000e80,0x10,0xc);
  __aeabi_vec_dtor(iVar1 + -0x28c,&LAB_15000d18,0x1c,0xc);
  iVar1 = msys::MChrBase::vfunc_0x0(pMVar2);
  pMVar2 = (MLyt *)(iVar1 + -0x3a8);
  *(undefined ***)pMVar2 = &msys::MLyt::vtable;
  msys::MLyt::term(pMVar2);
  __aeabi_vec_dtor(iVar1 + -0xf8,&LAB_15000e80,0x10,0xc);
  __aeabi_vec_dtor(iVar1 + -0x254,&LAB_15000d18,0x1c,0xc);
  iVar1 = msys::MChrBase::vfunc_0x0(pMVar2);
  *(undefined ***)(iVar1 + -0x3a8) = &msys::MLyt::vtable;
  msys::MLyt::term((MLyt *)(iVar1 + -0x3a8));
  __aeabi_vec_dtor(iVar1 + -0xf8,&LAB_15000e80,0x10,0xc);
  __aeabi_vec_dtor(iVar1 + -0x254,&LAB_15000d18,0x1c,0xc);
  iVar1 = msys::MChrBase::vfunc_0x0((MLyt *)(iVar1 + -0x3a8));
  iVar1 = ad::fw::Resource::~Resource((Resource *)(iVar1 + -0x48));
  iVar1 = ad::fw::Resource::~Resource((Resource *)(iVar1 + -0x44));
  iVar1 = ad::fw::Resource::~Resource((Resource *)(iVar1 + -0x44));
  iVar1 = ad::fw::Resource::~Resource((Resource *)(iVar1 + -0x44));
  iVar1 = ad::fw::Resource::~Resource((Resource *)(iVar1 + -0x44));
  iVar1 = ad::fw::Resource::~Resource((Resource *)(iVar1 + -0x44));
  iVar1 = ad::fw::Resource::~Resource((Resource *)(iVar1 + -0x44));
  iVar1 = MainMenuPageBase::vfunc_0x0(iVar1 + -0x24);
  iVar1 = MainMenuPageBase::vfunc_0x0(iVar1 + -0x24);
  iVar1 = MainMenuPageBase::vfunc_0x0(iVar1 + -0x24);
  iVar1 = MainMenuPageBase::vfunc_0x0(iVar1 + -0x24);
  iVar1 = MainMenuPageBase::vfunc_0x0(iVar1 + -0x24);
  iVar1 = MainMenuPageBase::vfunc_0x0(iVar1 + -0x24);
  iVar1 = MainMenuPageBase::vfunc_0x0(iVar1 + -0x24);
  iVar1 = MainMenuPageBase::vfunc_0x0(iVar1 + -0x24);
  msys::MComSys::~MComSys((MComSys *)(iVar1 + -0xe904c));
  return;
}


// FUNC 0x1501580c FUN_1501580c (MainMenu)
//   size 0x8c | file MainMenu+0x1580c | callers(47) 0x15000edc 0x15000f10 0x15000f44 0x15000f78 0x15000fac 0x15002d7c 0x15005590 0x15007f54 ...

MSndSe * FUN_1501580c(int param_1,uint param_2,MChrBase *param_3,VEC2 *param_4,bool param_5)

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


// FUNC 0x15015898 msys::MChrBase::vfunc_0x0 (MainMenu)
//   size 0x14c | file MainMenu+0x15898 | callers(27) 0x15001108 0x15015468 0x150152a0 0x15007968 0x15009048 0x150090cc 0x150091d0 0x15009254 ... | datarefs 1

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


// FUNC 0x150159f4 FUN_150159f4 (MainMenu)
//   size 0xdc | file MainMenu+0x159f4 | callers(4) 0x15010740 0x15012f6c 0x150153d8 0x15012fa0

void FUN_150159f4(undefined4 *param_1)

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
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(puVar1 + 0xc,FUN_150012f0,0x2c,1);
  *(int *)(iVar2 + -8) = iVar2;
  *(undefined1 *)(iVar2 + -4) = 1;
  puVar1 = (undefined4 *)MoveVBase::MoveVBase((MoveVBase *)(iVar2 + 0x2c));
  *puVar1 = &vtable_for_5MoveVILj1EE;
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(puVar1 + 0xc,FUN_150012f0,0x2c,1);
  *(int *)(iVar2 + -8) = iVar2;
  *(undefined1 *)(iVar2 + -4) = 1;
  puVar1 = (undefined4 *)MoveVBase::MoveVBase((MoveVBase *)(iVar2 + 0x2c));
  *puVar1 = &vtable_for_5MoveVILj1EE;
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(puVar1 + 0xc,FUN_150012f0,0x2c,1);
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


// FUNC 0x15015ae0 FUN_15015ae0 (MainMenu)
//   size 0x13c | file MainMenu+0x15ae0 | callers(1) 0x1500e6b0

void FUN_15015ae0(int *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  InitParam aIStack_80 [72];
  LytAnim local_38 [4];
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined2 local_28;
  undefined2 local_26;
  undefined4 local_24;
  undefined4 local_20;
  
  *param_1 = param_2;
  param_1[4] = param_3;
  param_1[5] = param_4;
  ad::lyt::LytNumReel3::InitParam::InitParam(aIStack_80);
  msys::MLytNumRes::set((MLytNumRes *)(param_2 + 0x844),aIStack_80,0,0xf,0xff);
  *(undefined1 *)((int)param_1 + 0x159) = 1;
  msys::MLytNum::init((MLytNum *)(param_1 + 6),aIStack_80,(LytDrawData *)(param_2 + 0xd3000),
                      (MLyt *)param_1[4],"NUM_L","GUIDE_TXT_base",(char *)0x0,(char *)0x0);
  *(undefined1 *)((int)param_1 + 0x389) = 1;
  msys::MLytNum::init((MLytNum *)(param_1 + 0x92),aIStack_80,(LytDrawData *)(param_2 + 0xd3000),
                      (MLyt *)param_1[4],"NUM_R","GUIDE_TXT_base",(char *)0x0,(char *)0x0);
  param_1[0x10f] = param_1[0x10f] & 0xfffffff3U | 4;
  local_38[0] = (LytAnim)0x0;
  local_34 = 0;
  local_30 = 0x3f800000;
  local_2c = 0;
  local_28 = 1;
  local_26 = 0;
  local_24 = 0;
  local_20 = 0;
  iVar1 = msys::MLyt::getParts((MLyt *)param_1[4],"num_slash","GUIDE_TXT_base",(char *)0x0);
  ad::lyt::LytAnim::init(local_38,*(Layout **)(iVar1 + 0xac),"col_15","");
  ad::lyt::LytAnim::stopAndSetFrm(local_38,0.0);
  ad::lyt::LytAnim::term(local_38,true);
  return;
}


// FUNC 0x15015c5c FUN_15015c5c (MainMenu)
//   size 0x220 | file MainMenu+0x15c5c | callers(1) 0x1500f1dc

void FUN_15015c5c(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  code *pcVar5;
  uint uVar6;
  
  iVar2 = *(int *)(param_1 + 4) + param_2;
  *(int *)(param_1 + 4) = iVar2;
  ad::lyt::LytNumReel3::setValueInstant((LytNumReel3 *)(param_1 + 0x168),iVar2 + 1);
  FUN_15011ab0(param_1);
  uVar1 = **(ushort **)(param_1 + 0xc) & 0xf000;
  if (uVar1 == 0x1000) {
    iVar2 = ad::db::GetFldGuideList((uint *)0x0);
    uVar6 = *(byte *)(iVar2 + (**(ushort **)(param_1 + 0xc) & 0xfff) * 0x10 + 4) & 0xf;
  }
  else if (uVar1 == 0x2000) {
    iVar2 = ad::db::GetBtlGuideList((uint *)0x0);
    uVar6 = *(byte *)(iVar2 + (**(ushort **)(param_1 + 0xc) & 0xfff) * 0x10 + 4) & 0xf;
  }
  else if (uVar1 == 0x3000) {
    iVar2 = ad::db::GetFldActGuideList((uint *)0x0);
    uVar6 = *(byte *)(iVar2 + (**(ushort **)(param_1 + 0xc) & 0xfff) * 0x10 + 4) & 0xf;
  }
  else if (uVar1 == 0x4000) {
    iVar2 = ad::db::GetAtkGuideList((uint *)0x0);
    uVar6 = *(byte *)(iVar2 + (**(ushort **)(param_1 + 0xc) & 0xfff) * 0x10 + 4) & 0xf;
  }
  else {
    uVar6 = 0;
  }
  if (*(int *)(param_1 + 4) == 0) {
    iVar2 = msys::MLyt::getPane(*(MLyt **)(param_1 + 0x10),"btn_L","GUIDE_TXT_base",(char *)0x0);
    *(byte *)(iVar2 + 0x44) = *(byte *)(iVar2 + 0x44) & 0xfe;
    piVar3 = *(int **)(param_1 + 0x478);
    pcVar5 = *(code **)(*piVar3 + 0x28);
    uVar4 = 0;
  }
  else {
    if ((param_2 < 1) || (*(int *)(param_1 + 4) != param_2)) goto LAB_15015d0c;
    iVar2 = msys::MLyt::getPane(*(MLyt **)(param_1 + 0x10),"btn_L","GUIDE_TXT_base",(char *)0x0);
    *(byte *)(iVar2 + 0x44) = *(byte *)(iVar2 + 0x44) & 0xfe | 1;
    piVar3 = *(int **)(param_1 + 0x478);
    pcVar5 = *(code **)(*piVar3 + 0x28);
    uVar4 = 1;
  }
  (*pcVar5)(piVar3,uVar4);
LAB_15015d0c:
  if (uVar6 - 1 <= *(uint *)(param_1 + 4)) {
    iVar2 = msys::MLyt::getPane(*(MLyt **)(param_1 + 0x10),"btn_R","GUIDE_TXT_base",(char *)0x0);
    *(byte *)(iVar2 + 0x44) = *(byte *)(iVar2 + 0x44) & 0xfe;
                    /* WARNING: Could not recover jumptable at 0x15015d50. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(param_1 + 0x47c) + 0x28))(*(int **)(param_1 + 0x47c),0);
    return;
  }
  if ((param_2 < 0) && (uVar6 - 1 <= *(uint *)(param_1 + 4) - param_2)) {
    iVar2 = msys::MLyt::getPane(*(MLyt **)(param_1 + 0x10),"btn_R","GUIDE_TXT_base",(char *)0x0);
    *(byte *)(iVar2 + 0x44) = *(byte *)(iVar2 + 0x44) & 0xfe | 1;
                    /* WARNING: Could not recover jumptable at 0x15015e74. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(param_1 + 0x47c) + 0x28))(*(int **)(param_1 + 0x47c),1);
    return;
  }
  return;
}


// FUNC 0x15015eb0 FUN_15015eb0 (MainMenu)
//   size 0x40 | file MainMenu+0x15eb0 | callers(0) | datarefs 1

void FUN_15015eb0(int param_1)

{
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x4b8),1,0,(char *)0x0,(char *)0x0);
  *(undefined1 *)(param_1 + 0xe580) = 0;
  *(code **)(param_1 + 0x20) = FUN_1501687c;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


// FUNC 0x15015ef8 FUN_15015ef8 (MainMenu)
//   size 0x1a8 | file MainMenu+0x15ef8 | callers(1) 0x1500e6b0

void FUN_15015ef8(MListWndPBase *param_1,int param_2,undefined4 param_3,int param_4)

{
  Layout *pLVar1;
  InitParam aIStack_198 [20];
  undefined4 local_184;
  undefined4 local_16c;
  undefined4 local_168;
  undefined4 local_160;
  LytAnim *local_15c;
  LytAnim *local_13c;
  MListWndPBase *local_138;
  undefined1 local_130;
  MListWndPBase *local_5c;
  undefined1 local_58;
  
  *(int *)(param_1 + 0x7688) = param_2 + 0xeae88;
  BattleGuideDataAcs::loadFromGameWork((BattleGuideDataAcs *)(param_1 + 0x771c));
  BattleGuideDataAcs::checkGuideAppear((BattleGuideDataAcs *)(param_1 + 0x771c),true);
  pLVar1 = (Layout *)(param_1 + 0x768c);
  ad::lyt::LytResourceMan::buildLayout
            ((LytResourceMan *)(param_4 + 0x58),pLVar1,"MENU_GUIDE_L_LIST.bflyt",
             (ControlCreator *)0x0,(TextSearcher *)0x0);
  ad::lyt::LytAnim::init((LytAnim *)(param_1 + 0x76c8),pLVar1,"touch","");
  ad::lyt::LytAnim::init((LytAnim *)(param_1 + 0x76e4),pLVar1,"NEW","");
  ad::lyt::LytAnim::init((LytAnim *)(param_1 + 0x7700),pLVar1,"ATTENTION","");
  ad::lyt::LytAnim::playAuto((LytAnim *)(param_1 + 0x7700),1.0);
  ad::ui::UIListWindowPlusLyt::InitParam::InitParam(aIStack_198);
  msys::SetMListWndInitParam(aIStack_198,1);
  local_160 = (**(code **)(**(int **)(param_1 + 0x769c) + 0x2c))
                        (*(int **)(param_1 + 0x769c),"FRAME",1);
  local_184 = (**(code **)(**(int **)(param_1 + 0x769c) + 0x2c))
                        (*(int **)(param_1 + 0x769c),"ICON_L",1);
  local_168 = (**(code **)(**(int **)(param_1 + 0x769c) + 0x2c))
                        (*(int **)(param_1 + 0x769c),"list_cursor",1);
  local_16c = (**(code **)(**(int **)(param_1 + 0x769c) + 0x2c))
                        (*(int **)(param_1 + 0x769c),"list_scroll",1);
  local_138 = param_1 + 0x7700;
  local_5c = param_1 + 0x6f80;
  local_130 = 0;
  local_58 = 0;
  local_15c = (LytAnim *)(param_1 + 0x76e4);
  local_13c = (LytAnim *)(param_1 + 0x76c8);
  msys::MListWndPBase::init
            (param_1,aIStack_198,(LytDrawData *)(param_2 + 0xd3000),(Prim *)(param_2 + 0xd3100),
             (MessageDrawer *)(param_2 + 0x1487c),(ApplyingSceneInfo *)(param_2 + 0x4af54));
  *(undefined4 *)(param_1 + 0x168) = 0x401;
  *(undefined4 *)(param_1 + 0x13c) = 0x401;
  return;
}


// FUNC 0x15016110 main_menu::MainMenu_GuidePage::Core::MListWndGuide::vfunc_0x4 (MainMenu)
//   size 0x70 | file MainMenu+0x16110 | callers(0) | datarefs 1

void main_menu::MainMenu_GuidePage::Core::MListWndGuide::vfunc_0x4(undefined4 *param_1)

{
  int iVar1;
  void *pvVar2;
  
  *param_1 = &vtable;
  BattleGuideDataAcs::saveToGameWork((BattleGuideDataAcs *)(param_1 + 0x1dc7));
  param_1[0x1dc3] = 0;
  param_1[0x1dbc] = 0;
  param_1[0x1db5] = 0;
  iVar1 = ad::lyt::Layout::~Layout((Layout *)(param_1 + 0x1da3));
  *(undefined ***)(iVar1 + -0x768c) = &vtable_for_N4msys9MListWndPILi64EEE;
  iVar1 = ad::ui::UIListWindowPlusLyt::~UIListWindowPlusLyt
                    ((UIListWindowPlusLyt *)(iVar1 + -0x7490));
  pvVar2 = (void *)msys::MListWndPBase::~MListWndPBase((MListWndPBase *)(iVar1 + -0x1fc));
  operator_delete(pvVar2);
  return;
}


// FUNC 0x1501618c main_menu::MainMenu_GuidePage::Core::MListWndGuide::vfunc_0x0 (MainMenu)
//   size 0x6c | file MainMenu+0x1618c | callers(0) | datarefs 1

void main_menu::MainMenu_GuidePage::Core::MListWndGuide::vfunc_0x0(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &vtable;
  BattleGuideDataAcs::saveToGameWork((BattleGuideDataAcs *)(param_1 + 0x1dc7));
  param_1[0x1dc3] = 0;
  param_1[0x1dbc] = 0;
  param_1[0x1db5] = 0;
  iVar1 = ad::lyt::Layout::~Layout((Layout *)(param_1 + 0x1da3));
  *(undefined ***)(iVar1 + -0x768c) = &vtable_for_N4msys9MListWndPILi64EEE;
  iVar1 = ad::ui::UIListWindowPlusLyt::~UIListWindowPlusLyt
                    ((UIListWindowPlusLyt *)(iVar1 + -0x7490));
  msys::MListWndPBase::~MListWndPBase((MListWndPBase *)(iVar1 + -0x1fc));
  return;
}


// FUNC 0x15016204 FUN_15016204 (MainMenu)
//   size 0x90 | file MainMenu+0x16204 | callers(0) | datarefs 3

void FUN_15016204(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = msys::MLyt::isBusyAnime((MLyt *)(param_1 + 0x4b8));
  if (iVar2 == 0) {
    msys::MListWndPBase::setEnableInput((MListWndPBase *)(param_1 + 0xe618),true);
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
    FUN_150119b8(param_1,1);
    *(undefined4 *)(*(int *)(param_1 + 0x860) + 0x48) = 1;
    *(code **)(param_1 + 0x20) = FUN_15016ff0;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x1501629c main_menu::MainMenu_GuidePage::Core::vfunc_0x10 (MainMenu)
//   size 0x154 | file MainMenu+0x1629c | callers(0) | datarefs 1

void main_menu::MainMenu_GuidePage::Core::vfunc_0x10(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  MLyt *this;
  
  if (param_2 == 4) {
    FUN_1501580c(msys::MComSys::_sys + 0x49368,0x110017,0,0,0);
    iVar1 = msys::MComSys::_sys;
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar1;
    }
    *(undefined1 *)(iVar2 + 0xe6508) = 0;
    return;
  }
  if (param_2 == 5) {
    this = (MLyt *)(param_1 + 0x4b8);
    iVar2 = *(int *)(*(int *)(param_1 + 0x860) + 0x48);
    if (iVar2 == 0) {
      *(undefined1 *)(param_1 + 0xe582) = 0;
      msys::MLyt::playAnimeFromNo(this,1,1,(char *)0x0,(char *)0x0);
      msys::MCursorBase::setVisible((MCursorBase *)(param_1 + 0xe584),false);
      FUN_15014e10((MCursorBase *)(param_1 + 0xe584));
      *(code **)(param_1 + 0x20) = FUN_150167f0;
      *(undefined4 *)(param_1 + 0x24) = 0;
      return;
    }
    if (iVar2 == 1) {
      msys::MLyt::playAnimeFromNo(this,2,1,(char *)0x0,(char *)0x0);
      *(code **)(param_1 + 0x20) = FUN_1501687c;
      *(undefined4 *)(param_1 + 0x24) = 0;
      return;
    }
    if (iVar2 == 2) {
      msys::MLyt::playAnimeFromNo(this,3,1,(char *)0x0,(char *)0x0);
      (**(code **)(**(int **)(param_1 + 0xe5f8) + 0x28))(*(int **)(param_1 + 0xe5f8),0);
      (**(code **)(**(int **)(param_1 + 0xe5fc) + 0x28))(*(int **)(param_1 + 0xe5fc),0);
      *(code **)(param_1 + 0x20) = FUN_15016548;
      *(undefined4 *)(param_1 + 0x24) = 0;
    }
  }
  return;
}


// FUNC 0x15016404 FUN_15016404 (MainMenu)
//   size 0x58 | file MainMenu+0x16404 | callers(0) | datarefs 1

void FUN_15016404(int param_1)

{
  MComSys *pMVar1;
  int iVar2;
  MComSys *this;
  
  iVar2 = msys::MLyt::isBusyAnime((MLyt *)(param_1 + 0x4b8));
  pMVar1 = msys::MComSys::_sys;
  if (iVar2 == 0) {
    this = *(MComSys **)(param_1 + 8);
    if (*(MComSys **)(param_1 + 8) == (MComSys *)0x0) {
      *(MComSys **)(param_1 + 8) = msys::MComSys::_sys;
      this = pMVar1;
    }
    iVar2 = msys::MComSys::getNextPage(this);
    if (*(char *)(iVar2 + 0x14) != '\0') {
      *(undefined1 **)(param_1 + 0x18) = &LAB_15016f18;
      *(undefined4 *)(param_1 + 0x1c) = 0;
    }
  }
  return;
}


// FUNC 0x15016548 FUN_15016548 (MainMenu)
//   size 0xf4 | file MainMenu+0x16548 | callers(0) | datarefs 2

void FUN_15016548(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = msys::MLyt::isBusyAnime((MLyt *)(param_1 + 0x4b8));
  if (iVar1 == 0) {
    iVar1 = msys::MListWndPBase::getCurNo((MListWndPBase *)(param_1 + 0xe618));
    iVar1 = param_1 + iVar1 * 0x1c;
    uVar2 = *(uint *)(iVar1 + 0x15598);
    *(undefined1 *)(iVar1 + 0x155a0) = 0xff;
    uVar3 = uVar2 & 0xf000;
    if (uVar3 == 0x1000) {
      FldGuideAcs::MarkReadedGuide(uVar2 & 0xfff);
    }
    else if (uVar3 == 0x2000) {
      uVar3 = (uVar2 & 0xfff) >> 5;
      uVar2 = 1 << (uVar2 & 0x1f);
      *(uint *)(param_1 + 0x15d38 + uVar3 * 4) = *(uint *)(param_1 + 0x15d38 + uVar3 * 4) | uVar2;
      *(uint *)(param_1 + 0x15d3c + uVar3 * 4) = *(uint *)(param_1 + 0x15d3c + uVar3 * 4) | uVar2;
    }
    else if (uVar3 == 0x3000) {
      ActGuideAcs::MarkReadedGuide(uVar2 & 0xfff);
    }
    else if (uVar3 == 0x4000) {
      BattleAttackGuideDataAcs::MarkReadedGuide(uVar2 & 0xfff);
    }
    *(code **)(param_1 + 0x20) = FUN_15016204;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x1501664c FUN_1501664c (MainMenu)
//   size 0x188 | file MainMenu+0x1664c | callers(0)

void FUN_1501664c(int param_1,int param_2,int param_3)

{
  ushort uVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  BootInfo *pBVar5;
  undefined4 local_28;
  
  iVar4 = msys::MComSys::_sys;
  if (param_3 == 4) {
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
    }
    *(undefined1 *)(*(int *)(param_1 + 8) + 0xe6508) = 0;
    local_28 = 0;
    FUN_1501580c(iVar4 + 0x49368,0x110016,0,0);
    return;
  }
  if (param_3 == 5) {
    puVar3 = (undefined1 *)main_menu::GetBootInfo();
    *puVar3 = 6;
    iVar4 = ad::db::GetAtkGuideList((uint *)0x0);
    uVar1 = *(ushort *)(iVar4 + (**(ushort **)(param_1 + 0xe104) & 0xfff) * 0x10 + 0xc);
    if (*(int *)(param_2 + 0x48) == 1) {
      puVar3 = (undefined1 *)main_menu::GetBootInfo();
      *puVar3 = 6;
      pBVar5 = (BootInfo *)btl::GetBootInfo();
      btl::BootInfo::setModePcAtkExample(pBVar5,uVar1);
      iVar4 = main_menu::GetBootInfo();
      *(undefined1 *)(iVar4 + 0x2a) = 0;
      iVar4 = *(int *)(param_1 + 8);
    }
    else {
      if (*(char *)(param_1 + 0xe59c) != '\x03') {
        return;
      }
      pBVar5 = (BootInfo *)btl::GetBootInfo();
      btl::BootInfo::setModePcAtkPractice(pBVar5,uVar1);
      iVar4 = main_menu::GetBootInfo();
      *(undefined1 *)(iVar4 + 0x2a) = 1;
      iVar4 = *(int *)(param_1 + 8);
    }
    iVar2 = msys::MComSys::_sys;
    if (iVar4 == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar4 = iVar2;
    }
    local_28 = 0xff000000;
    MoveC::moveFrm((MoveC *)(iVar4 + 0x4acd4),(Color8 *)&local_28,16.0);
    MoveC::moveFrm((MoveC *)(iVar4 + 0x4ad14),(Color8 *)&local_28,16.0);
    *(code **)(param_1 + 0x20) = FUN_15016ac8;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x150167f0 FUN_150167f0 (MainMenu)
//   size 0x80 | file MainMenu+0x167f0 | callers(0) | datarefs 2

void FUN_150167f0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = msys::MComSys::_sys;
  if (*(int *)(param_1 + 8) == 0) {
    *(undefined4 *)(param_1 + 8) = msys::MComSys::_sys;
  }
  iVar2 = *(int *)(param_1 + 8);
  if (*(float *)(iVar2 + 0x4ad44) <= *(float *)(iVar2 + 0x4ad40)) {
    if (iVar2 == 0) {
      *(undefined4 *)(param_1 + 8) = uVar1;
    }
    if ((*(float *)(*(int *)(param_1 + 8) + 0x4ad04) <= *(float *)(*(int *)(param_1 + 8) + 0x4ad00))
       && (iVar2 = msys::MLyt::isBusyAnime((MLyt *)(param_1 + 0x4b8)), iVar2 == 0)) {
      *(undefined1 *)(param_1 + 0x865) = 0;
    }
  }
  return;
}


// FUNC 0x1501687c FUN_1501687c (MainMenu)
//   size 0xe0 | file MainMenu+0x1687c | callers(0) | datarefs 4

void FUN_1501687c(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  
  iVar2 = msys::MLyt::isBusyAnime((MLyt *)(param_1 + 0x4b8));
  if (iVar2 == 0) {
    msys::MListWndPBase::setEnableInput((MListWndPBase *)(param_1 + 0xe618),false);
    iVar1 = msys::MComSys::_sys;
    uVar4 = 0;
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
    do {
      piVar3 = *(int **)(param_1 + uVar4 * 4 + 0xe600);
      (**(code **)(*piVar3 + 0x28))(piVar3,1);
      uVar4 = uVar4 + 1 & 0xff;
    } while (uVar4 < 4);
    *(undefined1 *)(param_1 + 0xe59c) = *(undefined1 *)(param_1 + 0xe580);
    msys::MCursorBase::setVisible((MCursorBase *)(param_1 + 0xe584),true);
    FUN_15014e10((MCursorBase *)(param_1 + 0xe584));
    *(undefined4 *)(*(int *)(param_1 + 0x860) + 0x48) = 0;
    *(code **)(param_1 + 0x20) = FUN_15016d6c;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x15016968 FUN_15016968 (MainMenu)
//   size 0x34 | file MainMenu+0x16968 | callers(0) | datarefs 2

void FUN_15016968(int param_1)

{
  BootInfo *this;
  int iVar1;
  
  this = (BootInfo *)main_menu::GetBootInfo();
  iVar1 = main_menu::BootInfo::playBgm(this);
  if (iVar1 != 0) {
    *(undefined1 *)(*(int *)(param_1 + 4) + 0x14) = 1;
    *(undefined **)(param_1 + 0x10) = &DAT_15016fec;
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  return;
}


// FUNC 0x150169a0 FUN_150169a0 (MainMenu)
//   size 0x114 | file MainMenu+0x169a0 | callers(0) | datarefs 4

void FUN_150169a0(int param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = msys::MComSys::_sys;
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  iVar2 = *(int *)(param_1 + 8);
  if (*(float *)(iVar2 + 0x4ad44) <= *(float *)(iVar2 + 0x4ad40)) {
    if (iVar2 == 0) {
      *(int *)(param_1 + 8) = iVar3;
    }
    if ((*(float *)(*(int *)(param_1 + 8) + 0x4ad04) <= *(float *)(*(int *)(param_1 + 8) + 0x4ad00))
       && (iVar3 = msys::MLyt::isBusyAnime((MLyt *)(param_1 + 0x4b8)), iVar3 == 0)) {
      msys::MListWndPBase::setEnableInput((MListWndPBase *)(param_1 + 0xe618),false);
      iVar2 = msys::MComSys::_sys;
      iVar3 = *(int *)(param_1 + 8);
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar3 = iVar2;
      }
      *(undefined1 *)(iVar3 + 0xe6508) = 1;
      iVar2 = msys::MComSys::_sys;
      iVar3 = *(int *)(param_1 + 8);
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar3 = iVar2;
      }
      *(undefined1 *)(iVar3 + 0xe650a) = 1;
      uVar4 = 5;
      bVar1 = *(byte *)(param_1 + 0xe59c);
      if (bVar1 < 2) {
        uVar4 = 2;
      }
      else if (bVar1 == 2) {
        uVar4 = 3;
      }
      else if (bVar1 == 3) {
        uVar4 = 4;
      }
      FUN_150119b8(param_1,uVar4);
      *(undefined4 *)(*(int *)(param_1 + 0x860) + 0x48) = 2;
      *(code **)(param_1 + 0x20) = FUN_150171c8;
      *(undefined4 *)(param_1 + 0x24) = 0;
    }
  }
  return;
}


// FUNC 0x15016ac8 FUN_15016ac8 (MainMenu)
//   size 0xe0 | file MainMenu+0x16ac8 | callers(0) | datarefs 2

void FUN_15016ac8(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  BootInfo *this;
  undefined4 uVar4;
  
  iVar2 = msys::MComSys::_sys;
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  else {
    iVar2 = *(int *)(param_1 + 8);
  }
  if (*(float *)(iVar2 + 0x4ad00) < *(float *)(iVar2 + 0x4ad04)) {
    return;
  }
  iVar2 = msys::MListWndPBase::getListWnd((MListWndPBase *)(param_1 + 0xe618));
  Mem::Copy((void *)(param_1 + 0x15c98),(void *)(iVar2 + 0x148),8);
  iVar2 = main_menu::GetBootInfo();
  Mem::Copy((void *)(iVar2 + 0x20),(void *)(param_1 + 0x15c98),8);
  puVar3 = (undefined4 *)msys::MListWndPBase::getCurItem();
  uVar4 = *puVar3;
  iVar2 = main_menu::GetBootInfo();
  *(undefined4 *)(iVar2 + 0x24) = uVar4;
  iVar2 = main_menu::GetBootInfo();
  *(undefined2 *)(iVar2 + 0x28) = *(undefined2 *)(param_1 + 0xe0fc);
  iVar2 = main_menu::GetBootInfo();
  *(undefined1 *)(iVar2 + 0x2b) = 1;
  this = (BootInfo *)main_menu::GetBootInfo();
  main_menu::BootInfo::saveBgm(this);
  SndSys::stopAllBgm((SndSys *)&gSndSys,0x10);
  iVar1 = msys::MComSys::_sys;
  iVar2 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar2 = iVar1;
  }
  GameMain::Change(10,*(undefined4 *)(iVar2 + 4));
  return;
}


// FUNC 0x15016bb8 FUN_15016bb8 (MainMenu)
//   size 0x94 | file MainMenu+0x16bb8 | callers(0) | datarefs 1

void FUN_15016bb8(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 local_20 [2];
  
  *(undefined1 *)(param_1 + 0x5f9) = 1;
  *(undefined1 *)(param_1 + 0x251) = 1;
  iVar1 = msys::MComSys::_sys;
  iVar2 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar2 = iVar1;
  }
  local_20[0] = 0;
  MoveC::moveFrm((MoveC *)(iVar2 + 0x4acd4),(Color8 *)local_20,16.0);
  MoveC::moveFrm((MoveC *)(iVar2 + 0x4ad14),(Color8 *)local_20,16.0);
  *(code **)(param_1 + 0x20) = FUN_150169a0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


// FUNC 0x15016c60 main_menu::MainMenu_GuidePage::Core::vfunc_0x8 (MainMenu)
//   size 0x108 | file MainMenu+0x16c60 | callers(0) | datarefs 1

int main_menu::MainMenu_GuidePage::Core::vfunc_0x8(int *param_1,MInput *param_2)

{
  MInput MVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  code *extraout_r2;
  code *pcVar5;
  VEC2 *pVVar6;
  bool bVar7;
  bool bVar8;
  uint in_fpscr;
  undefined4 local_20;
  undefined4 local_1c;
  
  msys::MPageBase::updateInputAllChr((MPageBase *)param_1[1],param_2);
  bVar7 = (param_1[9] & 1U) == 0;
  pcVar5 = extraout_r2;
  if (bVar7) {
    pcVar5 = (code *)param_1[8];
  }
  piVar2 = (int *)((int)param_1 + (param_1[9] >> 1));
  if (!bVar7) {
    pcVar5 = *(code **)(*piVar2 + param_1[8]);
  }
  (*pcVar5)(piVar2,param_2);
  iVar3 = msys::MListWndPBase::getListWnd((MListWndPBase *)(param_1 + 0x3986));
  bVar7 = *(int *)(iVar3 + 0x1cc) == 0;
  MVar1 = param_2[0x11];
  bVar8 = MVar1 == (MInput)0x0;
  if (bVar8) {
    MVar1 = param_2[0x12];
  }
  pVVar6 = (VEC2 *)0x0;
  if ((!bVar8 || MVar1 != (MInput)0x0) && bVar7) {
    local_20 = VectorSignedToFloat(*(ushort *)(param_2 + 0x14) - 0xa0,(byte)(in_fpscr >> 0x16) & 3);
    local_1c = VectorSignedToFloat(0x78 - (uint)*(ushort *)(param_2 + 0x16),
                                   (byte)(in_fpscr >> 0x16) & 3);
    pVVar6 = (VEC2 *)&local_20;
  }
  bVar8 = (bool)(**(code **)(*param_1 + 0xc))(param_1,param_2);
  iVar3 = msys::MComSys::_sys;
  iVar4 = param_1[2];
  if (param_1[2] == 0) {
    param_1[2] = msys::MComSys::_sys;
    iVar4 = iVar3;
  }
  ad::ctrl::ButtonGroup::Update
            ((ButtonGroup *)(param_1 + 0xf),pVVar6,
             (bool)(*(byte *)(iVar4 + 0xe6508) & bVar7 & bVar8),bVar8);
  return (int)*(char *)((int)param_1 + 0x865);
}


// FUNC 0x15016d6c FUN_15016d6c (MainMenu)
//   size 0x198 | file MainMenu+0x16d6c | callers(0) | datarefs 2

void FUN_15016d6c(int param_1,uint *param_2)

{
  int iVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  uVar5 = *param_2;
  cVar3 = *(char *)(param_1 + 0xe59c);
  iVar6 = (int)cVar3;
  cVar2 = cVar3 % '\x02';
  cVar3 = cVar3 / '\x02';
  if ((uVar5 & 0x20) == 0) {
    if ((uVar5 & 0x10) == 0) {
      if ((uVar5 & 0x40) == 0) {
        if ((uVar5 & 0x80) == 0) {
          iVar7 = iVar6;
          if ((uVar5 & 0x401) == 0) {
            if ((uVar5 & 0x802) == 0) goto LAB_15016ecc;
            (**(code **)(**(int **)(param_1 + 0x860) + 0x10))();
            iVar1 = msys::MComSys::_sys;
            iVar4 = *(int *)(param_1 + 8);
            if (*(int *)(param_1 + 8) == 0) {
              *(int *)(param_1 + 8) = msys::MComSys::_sys;
              iVar4 = iVar1;
            }
            *(undefined1 *)(iVar4 + 0xe6508) = 0;
            iVar4 = *(int *)(param_1 + 8);
          }
          else {
            (**(code **)(**(int **)(param_1 + iVar6 * 4 + 0xe600) + 0x10))();
            iVar1 = msys::MComSys::_sys;
            iVar4 = *(int *)(param_1 + 8);
            if (*(int *)(param_1 + 8) == 0) {
              *(int *)(param_1 + 8) = msys::MComSys::_sys;
              iVar4 = iVar1;
            }
            *(undefined1 *)(iVar4 + 0xe6508) = 0;
            iVar4 = *(int *)(param_1 + 8);
          }
          iVar1 = msys::MComSys::_sys;
          if (iVar4 == 0) {
            *(int *)(param_1 + 8) = msys::MComSys::_sys;
            iVar4 = iVar1;
          }
          *(undefined1 *)(iVar4 + 0xe650a) = 1;
          goto LAB_15016ecc;
        }
        cVar3 = cVar3 + '\x01';
        if ('\x01' < cVar3) {
          cVar3 = '\0';
        }
      }
      else {
        cVar3 = cVar3 + -1;
        if (cVar3 < '\0') {
          cVar3 = '\x01';
        }
      }
      cVar2 = cVar2 + cVar3 * '\x02';
    }
    else {
      cVar2 = cVar2 + '\x01';
      if ('\x01' < cVar2) {
        cVar2 = '\0';
      }
      cVar2 = cVar2 + cVar3 * '\x02';
    }
    iVar7 = (int)cVar2;
  }
  else {
    cVar2 = cVar2 + -1;
    if (cVar2 < '\0') {
      cVar2 = '\x01';
    }
    iVar7 = (int)(char)(cVar2 + cVar3 * '\x02');
  }
LAB_15016ecc:
  if (iVar6 != iVar7) {
    FUN_1501580c(msys::MComSys::_sys + 0x49368,0x110015,0,0,0);
    *(char *)(param_1 + 0xe59c) = (char)iVar7;
  }
  FUN_15014e10(param_1 + 0xe584);
  return;
}


// FUNC 0x15016f28 FUN_15016f28 (MainMenu)
//   size 0x9c | file MainMenu+0x16f28 | callers(0) | datarefs 1

void FUN_15016f28(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  FUN_150144d8();
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
  ad::fw::TaskBase::readLyt
            (*(TaskBase **)(iVar3 + 4),(Resource *)(param_1 + 0xcc),
             (FileContext *)(*(int *)(iVar1 + 0x278) + 0x150),"?MENU_GUIDE",
             (MemAlcBase *)(param_1 + 0x28),0x7f,(ResCacheArg *)0x0);
  puVar2 = operator_new(4,*(MemAlcBase **)(*(int *)(param_1 + 4) + 0x18),"ParamMainGuide",0);
  if (puVar2 != (undefined4 *)0x0) {
    *puVar2 = 0xc30c0000;
  }
  *(undefined4 **)(param_1 + 0x868) = puVar2;
  *(undefined1 **)(param_1 + 0x10) = &LAB_15015e9c;
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}


// FUNC 0x15016ff0 FUN_15016ff0 (MainMenu)
//   size 0x1bc | file MainMenu+0x16ff0 | callers(0) | datarefs 2

void FUN_15016ff0(int param_1,uint *param_2)

{
  int iVar1;
  MListWndPBase *this;
  int iVar2;
  int iVar3;
  float fVar4;
  
  this = (MListWndPBase *)(param_1 + 0xe618);
  msys::MListWndPBase::getListWnd(this);
  iVar2 = ad::ui::UIListWindowPlusLyt::getCurItem();
  iVar3 = msys::MListWndPBase::getSelectItem(this);
  if ((iVar3 == 0) ||
     (iVar3 = msys::MListWndPBase::getSelectItem(this), *(char *)(iVar3 + 0xe) == '\0')) {
    iVar3 = msys::MListWndPBase::isBusyAnime(this);
    if ((iVar3 == 0) &&
       ((iVar3 = msys::MListWndPBase::getListWnd(this), *(int *)(iVar3 + 0x1cc) == 0 &&
        ((*param_2 & 0x802) != 0)))) {
      (**(code **)(**(int **)(param_1 + 0x860) + 0x10))();
      iVar1 = msys::MComSys::_sys;
      iVar3 = *(int *)(param_1 + 8);
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar3 = iVar1;
      }
      *(undefined1 *)(iVar3 + 0xe6508) = 0;
    }
  }
  else {
    FUN_1501580c(msys::MComSys::_sys + 0x49368,0x110016,0,0,0);
    iVar1 = msys::MComSys::_sys;
    iVar3 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar3 = iVar1;
    }
    *(undefined1 *)(iVar3 + 0xe6508) = 0;
    msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x4b8),3,0,(char *)0x0,(char *)0x0);
    if (*(char *)(param_1 + 0xe59c) == '\x03') {
      fVar4 = 2.0;
    }
    else {
      fVar4 = 0.0;
    }
    ad::lyt::LytAnim::stopAndSetFrm((LytAnim *)(param_1 + 0xe5dc),fVar4);
    msys::MMsg::playStr((MMsg *)(param_1 + 0x74b4),*(wchar_t **)(iVar2 + 0x10),(InsParam *)0x0,false
                       );
    FUN_15011be4(param_1 + 0xe0f8,iVar2);
    *(code **)(param_1 + 0x20) = FUN_150169a0;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  iVar3 = msys::MListWndPBase::getListWnd(this);
  if (((*(char *)(iVar3 + 0x144) != '\0') &&
      (iVar3 = msys::MListWndPBase::getListWnd(this), *(int *)(iVar3 + 0x1cc) == 0)) &&
     (iVar3 = msys::MListWndPBase::getListWnd(this),
     (int)*(char *)(param_1 + 0xe581) != (uint)*(byte *)(iVar3 + 0x149) && iVar2 != 0)) {
    iVar2 = msys::MListWndPBase::getListWnd(this);
    *(undefined1 *)(param_1 + 0xe581) = *(undefined1 *)(iVar2 + 0x149);
  }
  return;
}


// FUNC 0x150171c8 FUN_150171c8 (MainMenu)
//   size 0x158 | file MainMenu+0x171c8 | callers(0) | datarefs 2

void FUN_150171c8(int param_1,uint *param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  
  if ((*param_2 & 0x802) != 0) {
    (**(code **)(**(int **)(param_1 + 0x860) + 0x10))();
    iVar2 = msys::MComSys::_sys;
    iVar3 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar3 = iVar2;
    }
    *(undefined1 *)(iVar3 + 0xe6508) = 0;
    return;
  }
  iVar3 = msys::MLyt::getParts((MLyt *)(param_1 + 0x4b8),"btn_L","GUIDE_TXT_base",(char *)0x0);
  bVar1 = *(byte *)(iVar3 + 0x44);
  bVar4 = (bVar1 & 1) == 0;
  if (!bVar4) {
    bVar1 = (byte)*param_2;
  }
  if (bVar4 || (bVar1 & 0x20) == 0) {
    iVar3 = msys::MLyt::getParts((MLyt *)(param_1 + 0x4b8),"btn_R","GUIDE_TXT_base",(char *)0x0);
    bVar1 = *(byte *)(iVar3 + 0x44);
    bVar4 = (bVar1 & 1) == 0;
    if (!bVar4) {
      bVar1 = (byte)*param_2;
    }
    if (bVar4 || (bVar1 & 0x10) == 0) {
      return;
    }
    (**(code **)(**(int **)(param_1 + 0xe5fc) + 0x10))();
    (**(code **)(**(int **)(param_1 + 0xe5fc) + 0xc))();
    iVar2 = msys::MComSys::_sys;
    iVar3 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar3 = iVar2;
    }
    *(undefined1 *)(iVar3 + 0xe6508) = 0;
    iVar3 = *(int *)(param_1 + 8);
  }
  else {
    (**(code **)(**(int **)(param_1 + 0xe5f8) + 0x10))();
    (**(code **)(**(int **)(param_1 + 0xe5f8) + 0xc))();
    iVar2 = msys::MComSys::_sys;
    iVar3 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar3 = iVar2;
    }
    *(undefined1 *)(iVar3 + 0xe6508) = 0;
    iVar3 = *(int *)(param_1 + 8);
  }
  iVar2 = msys::MComSys::_sys;
  if (iVar3 == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar3 = iVar2;
  }
  *(undefined1 *)(iVar3 + 0xe650a) = 1;
  return;
}


// FUNC 0x15017348 FUN_15017348 (MainMenu)
//   size 0x324 | file MainMenu+0x17348 | callers(1) 0x1500f0c4

void FUN_15017348(int param_1,int param_2)

{
  uint uVar1;
  MListWndPBase MVar2;
  MListWndPBase *this;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 *puVar7;
  int iVar8;
  int unaff_r11;
  bool bVar9;
  uint auStackY_258 [128];
  undefined1 uVar10;
  int in_stack_ffffffa8;
  int iVar11;
  LytAnim local_54 [4];
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined4 local_48;
  undefined2 local_44;
  undefined2 local_42;
  undefined4 local_40;
  undefined4 local_3c;
  int local_38;
  
  local_54[0] = (LytAnim)0x0;
  local_50 = 0;
  uStack_4c = 0x3f800000;
  local_48 = 0;
  local_44 = 1;
  local_42 = 0;
  local_40 = 0;
  local_3c = 0;
  ad::lyt::LytAnim::init(local_54,*(Layout **)(param_1 + 0x608),"SET_LIST_TYPE","");
  this = (MListWndPBase *)(param_1 + 0xe618);
  if (param_2 == 0) {
    Mem::Fill((void *)(param_1 + 0x15598),0,0x700);
    puVar4 = (undefined4 *)ad::db::GetFldGuideList(auStackY_258 + 0x80);
    puVar7 = puVar4 + in_stack_ffffffa8 * 4;
    bVar9 = puVar4 < puVar7;
    uVar6 = 0;
    if (bVar9) {
      unaff_r11 = param_1 + 0x15618;
    }
    iVar11 = 0;
    while (bVar9) {
      iVar3 = FldGuideAcs::IsExistGuide(uVar6);
      if (iVar3 != 0) {
        *(uint *)(this + iVar11 * 0x1c + 0x6f80) = uVar6 | 0x1000;
        iVar3 = iVar11;
        iVar8 = FldGuideAcs::IsReadedGuide(uVar6);
        if (iVar8 == 0) {
          MVar2 = (MListWndPBase)0x1;
        }
        else {
          MVar2 = (MListWndPBase)0xff;
        }
        this[iVar11 * 0x1c + 0x6f88] = MVar2;
        iVar8 = *(int *)(unaff_r11 + 0x688);
        uVar5 = LMS_GetTextIndexByLabel(iVar8 + 8,*puVar4);
        uVar5 = LMS_GetText(iVar8 + 8,uVar5);
        *(undefined4 *)(this + iVar11 * 0x1c + 0x6f90) = uVar5;
        this[iVar11 * 0x1c + 0x6f8e] = (MListWndPBase)0x1;
        iVar11 = iVar3 + 1;
      }
      puVar4 = puVar4 + 4;
      bVar9 = puVar4 < puVar7;
      uVar6 = uVar6 + 1;
    }
    iVar3 = msys::MListWndPBase::getListWnd(this);
    *(char *)(iVar3 + 0x144) = (char)iVar11;
    msys::MListWndPBase::resetCur(this);
    ad::lyt::LytAnim::stopAndSetFrm(local_54,0.0);
  }
  else if (param_2 == 1) {
    Mem::Fill((void *)(param_1 + 0x15598),0,0x700);
    puVar4 = (undefined4 *)ad::db::GetBtlGuideList(auStackY_258 + 0x80);
    puVar7 = puVar4 + in_stack_ffffffa8 * 4;
    uVar6 = 0;
    iVar11 = 0;
    if (puVar4 < puVar7) {
      local_38 = param_1 + 0x15618;
      do {
        uVar1 = 1 << (uVar6 & 0x1f);
        if ((*(uint *)(param_1 + 0x15d34 + (uVar6 >> 5) * 4) & uVar1) != 0) {
          *(uint *)(this + iVar11 * 0x1c + 0x6f80) = uVar6 | 0x2000;
          if ((*(uint *)(param_1 + 0x15d3c + (uVar6 >> 5) * 4) & uVar1) == 0) {
            MVar2 = (MListWndPBase)0x1;
          }
          else {
            MVar2 = (MListWndPBase)0xff;
          }
          this[iVar11 * 0x1c + 0x6f88] = MVar2;
          iVar8 = *(int *)(local_38 + 0x688);
          iVar3 = iVar11;
          uVar5 = LMS_GetTextIndexByLabel(iVar8 + 8,*puVar4);
          uVar5 = LMS_GetText(iVar8 + 8,uVar5);
          *(undefined4 *)(this + iVar11 * 0x1c + 0x6f90) = uVar5;
          this[iVar11 * 0x1c + 0x6f8e] = (MListWndPBase)0x1;
          iVar11 = iVar3 + 1;
        }
        puVar4 = puVar4 + 4;
        uVar6 = uVar6 + 1;
      } while (puVar4 < puVar7);
    }
    uVar10 = (undefined1)iVar11;
    iVar11 = msys::MListWndPBase::getListWnd(this);
    *(undefined1 *)(iVar11 + 0x144) = uVar10;
    msys::MListWndPBase::resetCur(this);
    ad::lyt::LytAnim::stopAndSetFrm(local_54,2.0);
  }
  else if (param_2 == 2) {
    FUN_15011d88();
    ad::lyt::LytAnim::stopAndSetFrm(local_54,1.0);
  }
  else if (param_2 == 3) {
    FUN_15011e78();
    ad::lyt::LytAnim::stopAndSetFrm(local_54,3.0);
  }
  ad::lyt::LytAnim::term(local_54,true);
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x4b8),2,0,(char *)0x0,(char *)0x0);
  *(code **)(param_1 + 0x20) = FUN_15016204;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


// FUNC 0x150176ac FUN_150176ac (MainMenu)
//   size 0x15c | file MainMenu+0x176ac | callers(1) 0x1501796c

int FUN_150176ac(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  
  puVar3 = (undefined4 *)FUN_15014438();
  *puVar3 = &main_menu::MainMenu_GuidePage::Core::vtable;
  iVar4 = FUN_15012fa0(puVar3 + 0x21c);
  iVar4 = FUN_15012fa0(iVar4 + 0x6c44);
  *(undefined4 *)(iVar4 + 0x6c54) = 0;
  *(undefined4 *)(iVar4 + 0x6c58) = 0;
  iVar4 = msys::MLytNum::MLytNum((MLytNum *)(iVar4 + 0x6c5c));
  iVar4 = msys::MLytNum::MLytNum((MLytNum *)(iVar4 + 0x230));
  *(undefined1 *)(iVar4 + 0x241) = 0xff;
  *(undefined1 *)(iVar4 + 0x242) = 0xff;
  puVar3 = (undefined4 *)msys::MCursorBase::MCursorBase((MCursorBase *)(iVar4 + 0x244));
  *puVar3 = &vtable_for_N4msys7MCursorILj6EEE;
  puVar3[0xc] = 0;
  puVar3[0xd] = 0;
  puVar3[0xe] = 0;
  puVar3[0xf] = 0;
  puVar3[0x10] = 0;
  puVar3[0x11] = 0;
  puVar3[0x12] = 0;
  puVar3[0x13] = 0x3f800000;
  puVar3[0x14] = 0;
  *(undefined2 *)(puVar3 + 0x15) = 1;
  *(undefined2 *)((int)puVar3 + 0x56) = 0;
  iVar4 = FUN_15012f30(puVar3 + 0x16);
  puVar3 = (undefined4 *)
           msys::MListWndPBase::MListWndPBase
                     ((MListWndPBase *)(iVar4 + 0x3c),(MListWndPCore *)(iVar4 + 0x238));
  *puVar3 = &vtable_for_N4msys9MListWndPILi64EEE;
  puVar3 = (undefined4 *)
           ad::ui::UIListWindowPlusLyt::UIListWindowPlusLyt((UIListWindowPlusLyt *)(puVar3 + 0x7f));
  *puVar3 = &msys::MListWndPCore::vtable;
  puVar3[-0x7f] = &main_menu::MainMenu_GuidePage::Core::MListWndGuide::vtable;
  *(undefined1 *)(puVar3 + 0x1d21) = 0;
  *(undefined1 *)((int)puVar3 + 0x7485) = 0;
  puVar3[0x1d22] = 0;
  iVar4 = ad::lyt::Layout::Layout((Layout *)(puVar3 + 0x1d24));
  iVar4 = FUN_15012f30(iVar4 + 0x3c);
  iVar4 = FUN_15012f30(iVar4 + 0x1c);
  iVar4 = FUN_15012f30(iVar4 + 0x1c);
  uVar2 = DAT_003f9cbc;
  uVar1 = DAT_003f9cb8;
  *(undefined4 *)(iVar4 + 0x1c) = DAT_003f9cb4;
  *(undefined4 *)(iVar4 + 0x20) = uVar1;
  *(undefined4 *)(iVar4 + 0x24) = uVar2;
  Mem::Fill((void *)(iVar4 + -0x7718),0,0x10);
  *(code **)(iVar4 + -0x15d08) = FUN_15016f28;
  *(undefined4 *)(iVar4 + -0x15d04) = 0;
  *(undefined1 **)(iVar4 + -0x15d00) = &LAB_15017694;
  *(undefined4 *)(iVar4 + -0x15cfc) = 0;
  *(code **)(iVar4 + -0x15cf8) = FUN_15015eb0;
  *(undefined4 *)(iVar4 + -0x15cf4) = 0;
  return iVar4 + -0x15d18;
}


// FUNC 0x1501782c main_menu::MainMenu_GuidePage::Core::vfunc_0x4 (MainMenu)
//   size 0x10 | file MainMenu+0x1782c | callers(0) | datarefs 1

void main_menu::MainMenu_GuidePage::Core::vfunc_0x4(void)

{
  void *pvVar1;
  
  pvVar1 = (void *)vfunc_0x0();
  operator_delete(pvVar1);
  return;
}


// FUNC 0x1501783c main_menu::MainMenu_GuidePage::Core::vfunc_0x0 (MainMenu)
//   size 0x11c | file MainMenu+0x1783c | callers(1) 0x1501782c | datarefs 1

void main_menu::MainMenu_GuidePage::Core::vfunc_0x0(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &vtable;
  msys::MCursorBase::term((MCursorBase *)(param_1 + 0x3961));
  operator_delete((void *)param_1[0x21a]);
  param_1[0x21a] = 0;
  param_1[0x3986] = &MListWndGuide::vtable;
  BattleGuideDataAcs::saveToGameWork((BattleGuideDataAcs *)(param_1 + 0x574d));
  param_1[0x5749] = 0;
  param_1[0x5742] = 0;
  param_1[0x573b] = 0;
  iVar1 = ad::lyt::Layout::~Layout((Layout *)(param_1 + 0x5729));
  *(undefined ***)(iVar1 + -0x768c) = &vtable_for_N4msys9MListWndPILi64EEE;
  iVar1 = ad::ui::UIListWindowPlusLyt::~UIListWindowPlusLyt
                    ((UIListWindowPlusLyt *)(iVar1 + -0x7490));
  iVar1 = msys::MListWndPBase::~MListWndPBase((MListWndPBase *)(iVar1 + -0x1fc));
  *(undefined4 *)(iVar1 + -0x30) = 0;
  *(undefined4 *)(iVar1 + -0x44) = 0;
  iVar1 = msys::MCursorBase::~MCursorBase((MCursorBase *)(iVar1 + -0x94));
  iVar1 = msys::MLytNum::~MLytNum((MLytNum *)(iVar1 + -0x244));
  iVar1 = msys::MLytNum::~MLytNum((MLytNum *)(iVar1 + -0x230));
  *(undefined ***)(iVar1 + -0x6c5c) = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar1 = MessageSimple::~MessageSimple((MessageSimple *)(iVar1 + -0x6b10));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  *(undefined ***)(iVar1 + -0x6c44) = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar1 = MessageSimple::~MessageSimple((MessageSimple *)(iVar1 + -0x6af8));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  MainMenuPageBase::Core::vfunc_0x0(iVar1 + -0x870);
  return;
}


// FUNC 0x1501796c main_menu::MainMenu_GuidePage::vfunc_0x30 (MainMenu)
//   size 0x30 | file MainMenu+0x1796c | callers(0) | datarefs 1

void main_menu::MainMenu_GuidePage::vfunc_0x30(int param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(0x15d40,*(MemAlcBase **)(param_1 + 0x18),(char *)0x0,0x1f);
  uVar2 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_150176ac(pvVar1,param_1);
  }
  *(undefined4 *)(param_1 + 0x20) = uVar2;
  return;
}


// FUNC 0x150179a0 main_menu::MainMenu_GuidePage::vfunc_0x24 (MainMenu)
//   size 0x8 | file MainMenu+0x179a0 | callers(0) | datarefs 1

undefined4 main_menu::MainMenu_GuidePage::vfunc_0x24(void)

{
  return 6;
}


// FUNC 0x150179a8 main_menu::MainMenu_GuidePage::vfunc_0x4 (MainMenu)
//   size 0x10 | file MainMenu+0x179a8 | callers(0) | datarefs 1

void main_menu::MainMenu_GuidePage::vfunc_0x4(void)

{
  void *pvVar1;
  
  pvVar1 = (void *)MainMenuPageBase::vfunc_0x0();
  operator_delete(pvVar1);
  return;
}


// FUNC 0x150179b8 ->main_menu::MainMenuPageBase::vfunc_0x0 (MainMenu)
//   size 0x4 | file MainMenu+0x179b8 | callers(0) | datarefs 1
// veneer/thunk -> 0x15015174 main_menu::MainMenuPageBase::vfunc_0x0 (MainMenu)

// FUNC 0x150179bc FUN_150179bc (MainMenu)
//   size 0x1d8 | file MainMenu+0x179bc | callers(1) 0x1501cf00

undefined8 FUN_150179bc(int param_1,short *param_2,int param_3)

{
  uint uVar1;
  short sVar2;
  byte bVar3;
  short *psVar4;
  float *pfVar5;
  int iVar6;
  uint uVar7;
  uint in_fpscr;
  uint uVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float local_50 [4];
  float local_40 [6];
  
  iVar6 = 2;
  pfVar5 = local_40;
  fVar11 = 0.0;
  do {
    iVar6 = iVar6 + -1;
    *pfVar5 = 0.0;
    pfVar5 = pfVar5 + 1;
  } while (iVar6 != 0);
  if (param_3 != 0) {
    local_50[1] = 0.0;
    local_50[0] = 0.0;
    iVar6 = param_3;
    do {
      psVar4 = param_2 + 1;
      sVar2 = *param_2;
      iVar6 = iVar6 + -1;
      param_2 = param_2 + 2;
      uVar7 = (int)sVar2 >> 0x1f;
      uVar1 = (int)*psVar4 >> 0x1f;
      fVar10 = (float)VectorUnsignedToFloat((int)sVar2 + uVar7 ^ uVar7,(byte)(in_fpscr >> 0x16) & 3)
      ;
      fVar9 = (float)VectorUnsignedToFloat
                               (uVar1 ^ (int)*psVar4 + uVar1,(byte)(in_fpscr >> 0x16) & 3);
      local_50[0] = local_50[0] + fVar10 * 1.5259022e-05;
      local_50[1] = local_50[1] + fVar9 * 1.5259022e-05;
    } while (iVar6 != 0);
    fVar9 = 1.0;
    if (*(char *)(param_1 + 0xa18) == '\0') {
      fVar10 = (float)VectorUnsignedToFloat(param_3,(byte)(in_fpscr >> 0x16) & 3);
      local_40[0] = (local_50[0] / fVar10) * 4.5454545;
      if ((int)local_40[0] < 0x3f800000) {
        uVar7 = in_fpscr & 0xfffffff | (uint)(local_40[0] < 0.0) << 0x1f |
                (uint)(local_40[0] == 0.0) << 0x1e;
        in_fpscr = uVar7 | (uint)NAN(local_40[0]) << 0x1c;
        bVar3 = (byte)(uVar7 >> 0x18);
        if ((bool)(bVar3 >> 6 & 1) || bVar3 >> 7 != ((byte)(in_fpscr >> 0x1c) & 1)) {
          local_40[0] = fVar11;
        }
      }
      else {
        local_40[0] = fVar9;
      }
      fVar10 = (float)VectorUnsignedToFloat(param_3,(byte)(in_fpscr >> 0x16) & 3);
      local_40[1] = (local_50[1] / fVar10) * 4.5454545;
      if ((int)local_40[1] < 0x3f800000) {
        if (local_40[1] <= 0.0) {
          local_40[1] = fVar11;
        }
      }
      else {
        local_40[1] = fVar9;
      }
    }
    else if (*(char *)(param_1 + 0xa18) == '\x01') {
      uVar7 = 0;
      do {
        pfVar5 = local_40 + uVar7;
        fVar10 = (float)VectorUnsignedToFloat(param_3,(byte)(in_fpscr >> 0x16) & 3);
        fVar10 = local_50[uVar7] / fVar10;
        *pfVar5 = fVar10;
        uVar1 = in_fpscr & 0xfffffff | (uint)(fVar10 < 0.0) << 0x1f | (uint)(fVar10 == 0.0) << 0x1e;
        uVar8 = uVar1 | (uint)NAN(fVar10) << 0x1c;
        bVar3 = (byte)(uVar1 >> 0x18);
        fVar10 = fVar11;
        if (!(bool)(bVar3 >> 6 & 1) && bVar3 >> 7 == ((byte)(uVar8 >> 0x1c) & 1)) {
          fVar10 = (float)__hardfp_log10f();
        }
        *pfVar5 = fVar10;
        in_fpscr = uVar8 & 0xfffffff;
        if (fVar10 != 0.0) {
          fVar10 = fVar10 + 2.5;
          *pfVar5 = fVar10;
        }
        fVar10 = fVar10 * 0.45;
        *pfVar5 = fVar10;
        if ((int)fVar10 < 0x3f800000) {
          uVar1 = in_fpscr | (uint)(fVar10 == 0.0) << 0x1e;
          in_fpscr = uVar1 | (uint)(0.0 <= fVar10) << 0x1d;
          if (!(bool)((byte)(in_fpscr >> 0x1d) & 1) || SUB41(uVar1 >> 0x1e,0)) {
            fVar10 = fVar11;
          }
        }
        else {
          fVar10 = fVar9;
        }
        uVar7 = uVar7 + 1;
        *pfVar5 = fVar10;
      } while (uVar7 < 2);
    }
  }
  return CONCAT44(local_40[1],local_40[0]);
}


// FUNC 0x15019ce0 FUN_15019ce0 (MainMenu)
//   size 0x144 | file MainMenu+0x19ce0 | callers(0) | datarefs 2

void FUN_15019ce0(int param_1,uint *param_2)

{
  uchar uVar1;
  MListWndPBase *this;
  int iVar2;
  int iVar3;
  uchar *puVar4;
  Layout *pLVar5;
  
  this = (MListWndPBase *)(param_1 + 0x4220c);
  iVar2 = msys::MListWndPBase::isBusyAnime(this);
  if ((iVar2 == 0) &&
     (iVar3 = msys::MListWndPBase::getListWnd(this), iVar2 = msys::MComSys::_sys,
     *(int *)(iVar3 + 0x1cc) == 0)) {
    iVar3 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar3 = iVar2;
    }
    ad::fw::TaskBase::isFps30(*(TaskBase **)(iVar3 + 4));
    if ((*param_2 & 0x802) != 0) {
      (**(code **)(**(int **)(param_1 + 0x860) + 0x10))();
      iVar3 = msys::MComSys::_sys;
      iVar2 = *(int *)(param_1 + 8);
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar2 = iVar3;
      }
      *(undefined1 *)(iVar2 + 0xe6508) = 0;
    }
  }
  iVar2 = msys::MListWndPBase::getListWnd(this);
  if (((*(char *)(iVar2 + 0x144) == '\0') ||
      (iVar2 = msys::MListWndPBase::getListWnd(this), *(int *)(iVar2 + 0x1cc) != 0)) ||
     (iVar2 = msys::MListWndPBase::getListWnd(this),
     (int)*(char *)(param_1 + 0x871) == (uint)*(byte *)(iVar2 + 0x149))) {
    return;
  }
  iVar2 = msys::MListWndPBase::getListWnd(this);
  *(undefined1 *)(param_1 + 0x871) = *(undefined1 *)(iVar2 + 0x149);
  puVar4 = (uchar *)msys::MListWndPBase::getCurItem();
  iVar3 = msys::MComSys::_sys;
  uVar1 = *puVar4;
  iVar2 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar2 = iVar3;
  }
  iVar2 = msys::MLyt::getParts((MLyt *)(iVar2 + 0xe934c),"MAP_ALL",(char *)0x0,(char *)0x0);
  iVar3 = msys::MComSys::_sys;
  pLVar5 = *(Layout **)(iVar2 + 0xac);
  iVar2 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar2 = iVar3;
  }
  msys::MMapIconMan::setRecordArea((MMapIconMan *)(iVar2 + 0xea174),pLVar5,uVar1);
  return;
}


// FUNC 0x15019e44 FUN_15019e44 (MainMenu)
//   size 0x138 | file MainMenu+0x19e44 | callers(0)

void FUN_15019e44(int param_1,int param_2,int param_3)

{
  int iVar1;
  char cVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_2 + 0x48);
  if (param_3 == 4) {
    *(char *)(param_1 + 0x873) = (char)iVar3;
    FUN_1501580c(msys::MComSys::_sys + 0x49368,0x110016,0,0,0);
    (**(code **)(**(int **)(param_1 + (uint)*(byte *)(param_1 + 0x519b4) * 4 + 0x3f718) + 0x18))();
    (**(code **)(**(int **)(param_1 + (uint)*(byte *)(param_1 + 0x519b4) * 4 + 0x3f718) + 0xc))();
    if (iVar3 == 0) {
      cVar2 = *(char *)(*(int *)(param_1 + 0x49c5c) + 0x144);
      if (cVar2 != '\0') {
        iVar3 = 0;
        do {
          cVar2 = cVar2 + -1;
          *(char *)(param_1 + 0x49b08 + iVar3 + 0x7e24) = (char)iVar3;
          iVar3 = iVar3 + 1;
        } while (cVar2 != '\0');
      }
      cVar2 = *(char *)(param_1 + 0x519ad);
      if (cVar2 == -1) {
        cVar2 = '\0';
      }
      *(char *)(param_1 + 0x519ac) = cVar2;
      *(undefined1 *)(param_1 + 0x519b4) = 0;
    }
    else if (iVar3 == 1) {
      *(undefined1 *)(param_1 + 0x519b4) = 1;
      *(undefined1 *)(param_1 + 0x519ac) = 0;
      *(undefined1 *)(param_1 + 0x5192c) = *(undefined1 *)(param_1 + 0x519ad);
    }
    else if (iVar3 == 2) {
      FUN_1501163c(param_1 + 0x49b08);
    }
    iVar1 = msys::MComSys::_sys;
    iVar3 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar3 = iVar1;
    }
    *(undefined1 *)(iVar3 + 0xe6508) = 1;
  }
  return;
}


// FUNC 0x15019f90 FUN_15019f90 (MainMenu)
//   size 0x1cc | file MainMenu+0x19f90 | callers(1) 0x1501a400

void FUN_15019f90(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  ushort uVar7;
  char *pcVar8;
  ushort uVar9;
  char cVar10;
  
  cVar10 = *(char *)(*(int *)(param_1 + 0x154) + 0x144);
  if (cVar10 != '\0') {
    iVar5 = 0;
    do {
      cVar10 = cVar10 + -1;
      *(char *)(param_1 + iVar5 + 0x7e24) = (char)iVar5;
      iVar5 = iVar5 + 1;
    } while (cVar10 != '\0');
  }
  cVar10 = *(char *)(param_1 + 0x7ea5);
  pcVar8 = (char *)(param_1 + 0x7e24);
  if (cVar10 == -1) {
    cVar10 = '\0';
  }
  *(char *)(param_1 + 0x7ea4) = cVar10;
  *(undefined1 *)(param_1 + 0x7eac) = 0;
  bVar3 = *(byte *)(*(int *)(param_1 + 0x154) + 0x144);
  uVar9 = (ushort)bVar3;
  if (uVar9 != 0) {
    cVar10 = (bVar3 & 1) != 0;
    pcVar6 = (char *)(param_1 + 0x7e23);
    if ((bool)cVar10) {
      *pcVar8 = '\0';
      pcVar6 = pcVar8;
    }
    for (uVar7 = (ushort)(bVar3 >> 1); uVar7 != 0; uVar7 = uVar7 - 1) {
      cVar1 = cVar10 + '\x01';
      pcVar6[1] = cVar10;
      cVar10 = cVar10 + '\x02';
      pcVar6 = pcVar6 + 2;
      *pcVar6 = cVar1;
    }
    if (1 < uVar9) {
      uVar4 = RandSys::get((RandSys *)&gRand);
      cVar10 = *(char *)(param_1 + 0x7e25);
      *(char *)(param_1 + 0x7e25) = pcVar8[(uVar4 & 0x7fffffff) >> 0xf];
      pcVar8[(uVar4 & 0x7fffffff) >> 0xf] = cVar10;
      uVar2 = gRand;
      uVar7 = 2;
      pcVar6 = (char *)(param_1 + 0x7e26);
      if (2 < uVar9) {
        do {
          uVar7 = uVar7 + 1;
          iVar5 = RandSys::get((RandSys *)&gRand);
          cVar10 = *pcVar6;
          *pcVar6 = pcVar8[iVar5 * (uint)uVar7 >> 0x10];
          pcVar8[iVar5 * (uint)uVar7 >> 0x10] = cVar10;
          pcVar6 = pcVar6 + 1;
        } while (uVar7 < uVar9);
      }
      gRand = uVar2;
    }
  }
  if (((int)*(char *)(param_1 + 0x7ea5) != 0xffffffff) &&
     ((uint)*(byte *)(param_1 + 0x7e24) == (int)*(char *)(param_1 + 0x7ea5))) {
    bVar3 = *(byte *)(*(int *)(param_1 + 0x154) + 0x144);
    iVar5 = RandSys::get((RandSys *)&gRand);
    cVar10 = *pcVar8;
    pcVar6 = (char *)((iVar5 * (bVar3 - 1 & 0xffff) >> 0x10) + param_1 + 0x7e25);
    *pcVar8 = *pcVar6;
    *pcVar6 = cVar10;
    for (bVar3 = 0; bVar3 < *(byte *)(*(int *)(param_1 + 0x154) + 0x144); bVar3 = bVar3 + 1) {
    }
  }
  *(undefined1 *)(param_1 + 0x7ea4) = 0;
  *(undefined1 *)(param_1 + 0x7eac) = 2;
  return;
}


// FUNC 0x1501a164 FUN_1501a164 (MainMenu)
//   size 0x224 | file MainMenu+0x1a164 | callers(1) 0x15018f60

void FUN_1501a164(MListWndPBase *param_1,LytResourceMan *param_2,undefined4 param_3,int param_4)

{
  LytAnim *this;
  int iVar1;
  Layout *pLVar2;
  InitParam aIStack_1a8 [24];
  undefined4 local_190;
  undefined4 local_188;
  undefined4 local_17c;
  undefined4 local_178;
  undefined4 local_174;
  undefined4 local_170;
  LytAnim *local_168;
  LytAnim *local_14c;
  LytAnim *local_148;
  undefined1 local_144;
  undefined1 local_142;
  undefined1 local_140;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 uStack_74;
  undefined4 uStack_70;
  MListWndPBase *local_6c;
  undefined1 local_68;
  
  param_1[0x7ea4] = (MListWndPBase)0x0;
  param_1[0x7ea5] = (MListWndPBase)0xff;
  *(undefined4 *)(param_1 + 0x7ea8) = 0;
  param_1[0x7eac] = (MListWndPBase)0x0;
  param_1[0x7ead] = (MListWndPBase)0x0;
  *(int *)(param_1 + 0x7d90) = param_4;
  pLVar2 = (Layout *)(param_1 + 0x7d94);
  ad::lyt::LytResourceMan::buildLayout
            (param_2,pLVar2,"MENU_RECORD_L_LIST.bflyt",(ControlCreator *)0x0,(TextSearcher *)0x0);
  ad::lyt::LytAnim::init((LytAnim *)(param_1 + 0x7dd0),pLVar2,"touch","");
  ad::lyt::LytAnim::init((LytAnim *)(param_1 + 0x7dec),pLVar2,"SET_ICON","");
  this = (LytAnim *)(param_1 + 0x7e08);
  ad::lyt::LytAnim::init(this,pLVar2,"ATTENTION","");
  ad::lyt::LytAnim::playAuto(this,1.0);
  ad::ui::UIListWindowPlusLyt::InitParam::InitParam(aIStack_1a8);
  local_188 = 0;
  local_174 = 0;
  local_144 = 1;
  if (((nn::math::VEC2::One()::one & 1) == 0) &&
     (iVar1 = __cxa_guard_acquire(&nn::math::VEC2::One()::one), iVar1 != 0)) {
    nn::math::VEC2::One()::one = 0x3f800000;
    DAT_003f7ed8 = 0x3f800000;
    __cxa_guard_release(&nn::math::VEC2::One()::one);
  }
  uStack_74 = nn::math::VEC2::One()::one;
  uStack_70 = DAT_003f7ed8;
  msys::SetMListWndInitParam(aIStack_1a8,0);
  local_170 = (**(code **)(**(int **)(param_1 + 0x7da4) + 0x2c))
                        (*(int **)(param_1 + 0x7da4),"FRAME",1);
  local_190 = (**(code **)(**(int **)(param_1 + 0x7da4) + 0x2c))
                        (*(int **)(param_1 + 0x7da4),"ICON_L",1);
  local_178 = (**(code **)(**(int **)(param_1 + 0x7da4) + 0x2c))
                        (*(int **)(param_1 + 0x7da4),"list_cursor",1);
  local_17c = (**(code **)(**(int **)(param_1 + 0x7da4) + 0x2c))
                        (*(int **)(param_1 + 0x7da4),"list_scroll",1);
  local_144 = 1;
  local_142 = 0;
  local_140 = 0;
  local_84 = 0x3f800000;
  local_6c = param_1 + 0x6f80;
  local_80 = 0x3f800000;
  local_68 = 0;
  local_168 = (LytAnim *)(param_1 + 0x7dec);
  local_14c = (LytAnim *)(param_1 + 0x7dd0);
  local_148 = this;
  msys::MListWndPBase::init
            (param_1,aIStack_1a8,(LytDrawData *)(param_4 + 0xd3000),(Prim *)(param_4 + 0xd3100),
             (MessageDrawer *)(param_4 + 0x1487c),(ApplyingSceneInfo *)(param_4 + 0x4af54));
  *(undefined4 *)(param_1 + 0x13c) = 0x401;
  *(undefined4 *)(param_1 + 0x168) = 0x401;
  Mem::Fill(param_1 + 0x7e24,0,0x80);
  return;
}


// FUNC 0x1501a400 FUN_1501a400 (MainMenu)
//   size 0x144 | file MainMenu+0x1a400 | callers(1) 0x1501cf00

void FUN_1501a400(uint param_1,undefined4 param_2,undefined4 param_3,StreamSound *param_4)

{
  uint uVar1;
  byte bVar2;
  uint uVar3;
  bool bVar4;
  StreamSound *local_18;
  
  if (*(char *)(param_1 + 0x7ea5) != -1) {
    local_18 = param_4;
    if (DAT_003fbfa0 == 0) {
      if (*(char *)(param_1 + 0x7ead) == '\0') {
        FUN_1501153c(param_1,(int)*(char *)(param_1 + 0x7ea5),param_3,param_4);
        return;
      }
      uVar3 = (uint)*(byte *)(param_1 + 0x7eac);
      if ((uVar3 != 1) &&
         (bVar2 = *(char *)(param_1 + 0x7ea4) + 1, *(byte *)(param_1 + 0x7ea4) = bVar2,
         *(byte *)(*(int *)(param_1 + 0x154) + 0x144) <= bVar2)) {
        uVar1 = uVar3;
        if (uVar3 == 2) {
          uVar1 = param_1;
        }
        *(undefined1 *)(param_1 + 0x7ea4) = 0;
        if (uVar3 == 2) {
          FUN_15019f90(uVar1);
        }
      }
      *(ushort *)(param_1 + 0x7d8e) = *(ushort *)(param_1 + 0x7d8e) & 0xfffe;
      Frm::play((Frm *)(param_1 + 0x7d80),7.0);
      *(undefined1 *)(param_1 + 0x7ead) = 0;
      FUN_1501153c(param_1,(int)*(char *)((uint)*(byte *)(param_1 + 0x7ea4) + param_1 + 0x7e24));
                    /* WARNING: Could not recover jumptable at 0x1501a534. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(**(int **)(param_1 + 0x154) + 0x28))
                (*(int **)(param_1 + 0x154),*(undefined1 *)(param_1 + 0x7ea5));
      return;
    }
    nw::snd::StreamSoundHandle::StreamSoundHandle
              ((StreamSoundHandle *)&local_18,(SoundHandle *)&DAT_003fbfa0);
    if (local_18 == (StreamSound *)0x0) {
      uVar3 = 0xffffffff;
    }
    else {
      uVar3 = nw::snd::internal::StreamSound::GetPlaySamplePosition(local_18,true);
    }
    bVar4 = *(char *)(param_1 + 0x7ead) != '\0';
    uVar1 = 0;
    if (bVar4) {
      uVar1 = *(uint *)(param_1 + 0x7ea8);
    }
    if ((bVar4 && uVar3 < uVar1) && (*(char *)(param_1 + 0x7eac) != '\x01')) {
      SndSys::stop((SndSys *)&gSndSys,(SoundHandle *)&DAT_003fbfa0,0xad);
    }
    *(uint *)(param_1 + 0x7ea8) = uVar3;
    nw::snd::StreamSoundHandle::DetachSound((StreamSoundHandle *)&local_18);
  }
  return;
}


// FUNC 0x1501a550 main_menu::MainMenu_RecordPage::Core::MListWndBgm::vfunc_0x4 (MainMenu)
//   size 0x70 | file MainMenu+0x1a550 | callers(0) | datarefs 1

void main_menu::MainMenu_RecordPage::Core::MListWndBgm::vfunc_0x4(undefined4 *param_1)

{
  int iVar1;
  void *pvVar2;
  
  *param_1 = &vtable;
  param_1[0x1f85] = 0;
  param_1[0x1f7e] = 0;
  param_1[0x1f77] = 0;
  iVar1 = ad::lyt::Layout::~Layout((Layout *)(param_1 + 0x1f65));
  *(undefined4 *)(iVar1 + -0xc) = 0;
  *(undefined ***)(iVar1 + -0x7d94) = &vtable_for_N4msys9MListWndPILi128EEE;
  iVar1 = ad::ui::UIListWindowPlusLyt::~UIListWindowPlusLyt
                    ((UIListWindowPlusLyt *)(iVar1 + -0x7b98));
  pvVar2 = (void *)msys::MListWndPBase::~MListWndPBase((MListWndPBase *)(iVar1 + -0x1fc));
  operator_delete(pvVar2);
  return;
}


// FUNC 0x1501a5cc main_menu::MainMenu_RecordPage::Core::MListWndBgm::vfunc_0x0 (MainMenu)
//   size 0x6c | file MainMenu+0x1a5cc | callers(0) | datarefs 1

void main_menu::MainMenu_RecordPage::Core::MListWndBgm::vfunc_0x0(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &vtable;
  param_1[0x1f85] = 0;
  param_1[0x1f7e] = 0;
  param_1[0x1f77] = 0;
  iVar1 = ad::lyt::Layout::~Layout((Layout *)(param_1 + 0x1f65));
  *(undefined4 *)(iVar1 + -0xc) = 0;
  *(undefined ***)(iVar1 + -0x7d94) = &vtable_for_N4msys9MListWndPILi128EEE;
  iVar1 = ad::ui::UIListWindowPlusLyt::~UIListWindowPlusLyt
                    ((UIListWindowPlusLyt *)(iVar1 + -0x7b98));
  msys::MListWndPBase::~MListWndPBase((MListWndPBase *)(iVar1 + -0x1fc));
  return;
}


// FUNC 0x1501a650 FUN_1501a650 (MainMenu)
//   size 0x598 | file MainMenu+0x1a650 | callers(0)

void FUN_1501a650(int param_1,int param_2,int param_3)

{
  char cVar1;
  uchar uVar2;
  int iVar3;
  MListWndPBase *this;
  undefined2 *puVar4;
  int iVar5;
  uchar *puVar6;
  Layout *pLVar7;
  int iVar8;
  MCursorBase *this_00;
  MLyt *this_01;
  
  iVar5 = msys::MComSys::_sys;
  cVar1 = *(char *)(param_2 + 0x48);
  this_00 = (MCursorBase *)(param_1 + 0x88c);
  iVar8 = (int)cVar1;
  if (param_3 != 1) {
    if (param_3 != 4) {
      if (param_3 != 5) {
        return;
      }
      if (*(char *)(param_1 + iVar8 + 0x42206) == '\0') {
        if (*(int *)(param_1 + 8) == 0) {
          *(int *)(param_1 + 8) = msys::MComSys::_sys;
        }
        *(undefined1 *)(*(int *)(param_1 + 8) + 0xe6508) = 1;
        if (*(int *)(param_1 + 8) == 0) {
          *(int *)(param_1 + 8) = iVar5;
        }
        *(undefined1 *)(*(int *)(param_1 + 8) + 0xe650a) = 1;
        return;
      }
      msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x110),10,1,"pnl_RECORD",(char *)0x0);
      *(undefined4 *)(*(int *)(param_1 + 0x860) + 0x48) = 1;
      this = (MListWndPBase *)(param_1 + 0x4220c);
      *(char *)(param_1 + 0x870) = cVar1;
      FUN_15010b9c(this,iVar8);
      msys::MListWndPBase::resetCur(this);
      msys::MCursorBase::setVisible(this_00,false);
      FUN_15014e10(this_00);
      this_01 = (MLyt *)(param_1 + 0x4b8);
      switch(cVar1) {
      case '\0':
        msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x110),2,0,(char *)0x0,(char *)0x0);
        msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x4b8),2,0,(char *)0x0,(char *)0x0);
        iVar8 = msys::MComSys::_sys;
        iVar5 = *(int *)(param_1 + 8);
        if (*(int *)(param_1 + 8) == 0) {
          *(int *)(param_1 + 8) = msys::MComSys::_sys;
          iVar5 = iVar8;
        }
        ad::lyt::LytAnim::playAuto((LytAnim *)(iVar5 + 0xe9e60),1.0);
        *(undefined1 *)(param_1 + 0x4234d) = 1;
        msys::MListWndPBase::setEnableInput((MListWndPBase *)(param_1 + 0x4220c),true);
        *(undefined1 *)(param_1 + 0x49c49) = 0;
        msys::MListWndPBase::setEnableInput((MListWndPBase *)(param_1 + 0x4220c),false);
        puVar6 = (uchar *)msys::MListWndPBase::getCurItem();
        iVar8 = msys::MComSys::_sys;
        uVar2 = *puVar6;
        iVar5 = *(int *)(param_1 + 8);
        if (*(int *)(param_1 + 8) == 0) {
          *(int *)(param_1 + 8) = msys::MComSys::_sys;
          iVar5 = iVar8;
        }
        iVar5 = msys::MLyt::getParts((MLyt *)(iVar5 + 0xe934c),"MAP_ALL",(char *)0x0,(char *)0x0);
        iVar8 = msys::MComSys::_sys;
        pLVar7 = *(Layout **)(iVar5 + 0xac);
        iVar5 = *(int *)(param_1 + 8);
        if (*(int *)(param_1 + 8) == 0) {
          *(int *)(param_1 + 8) = msys::MComSys::_sys;
          iVar5 = iVar8;
        }
        msys::MMapIconMan::setRecordArea((MMapIconMan *)(iVar5 + 0xea174),pLVar7,uVar2);
        *(code **)(param_1 + 0x20) = FUN_1501cac4;
        *(undefined4 *)(param_1 + 0x24) = 0;
        return;
      case '\x01':
        msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x110),3,0,(char *)0x0,(char *)0x0);
        msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x4b8),3,0,(char *)0x0,(char *)0x0);
        puVar6 = (uchar *)msys::MListWndPBase::getCurItem();
        iVar8 = msys::MComSys::_sys;
        uVar2 = *puVar6;
        iVar5 = *(int *)(param_1 + 8);
        if (*(int *)(param_1 + 8) == 0) {
          *(int *)(param_1 + 8) = msys::MComSys::_sys;
          iVar5 = iVar8;
        }
        iVar5 = msys::MLyt::getParts((MLyt *)(iVar5 + 0xe934c),"MAP_ALL",(char *)0x0,(char *)0x0);
        iVar8 = msys::MComSys::_sys;
        pLVar7 = *(Layout **)(iVar5 + 0xac);
        iVar5 = *(int *)(param_1 + 8);
        if (*(int *)(param_1 + 8) == 0) {
          *(int *)(param_1 + 8) = msys::MComSys::_sys;
          iVar5 = iVar8;
        }
        msys::MMapIconMan::setRecordArea((MMapIconMan *)(iVar5 + 0xea174),pLVar7,uVar2);
        iVar8 = msys::MComSys::_sys;
        iVar5 = *(int *)(param_1 + 8);
        if (*(int *)(param_1 + 8) == 0) {
          *(int *)(param_1 + 8) = msys::MComSys::_sys;
          iVar5 = iVar8;
        }
        ad::lyt::LytAnim::playAuto((LytAnim *)(iVar5 + 0xe9e60),1.0);
        *(undefined1 *)(param_1 + 0x4234d) = 1;
        msys::MListWndPBase::setEnableInput((MListWndPBase *)(param_1 + 0x4220c),true);
        *(undefined1 *)(param_1 + 0x49c49) = 0;
        msys::MListWndPBase::setEnableInput((MListWndPBase *)(param_1 + 0x4220c),false);
        *(code **)(param_1 + 0x20) = FUN_1501cac4;
        *(undefined4 *)(param_1 + 0x24) = 0;
        return;
      case '\x02':
        msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x110),4,0,(char *)0x0,(char *)0x0);
        msys::MLyt::playAnimeFromNo(this_01,4,0,(char *)0x0,(char *)0x0);
        puVar4 = (undefined2 *)msys::MListWndPBase::getCurItem();
        FUN_15010ac4(param_1,*puVar4);
        iVar5 = msys::MListWndPBase::getCurItem();
        msys::MMsg::playStr((MMsg *)(param_1 + 0x767c),*(wchar_t **)(iVar5 + 0x10),(InsParam *)0x0,
                            false);
        *(undefined1 *)(param_1 + 0x4234d) = 1;
        msys::MListWndPBase::setEnableInput(this,true);
        *(undefined1 *)(param_1 + 0x49c49) = 0;
        msys::MListWndPBase::setEnableInput(this,false);
        *(code **)(param_1 + 0x20) = FUN_1501c07c;
        *(undefined4 *)(param_1 + 0x24) = 0;
        return;
      case '\x03':
        msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x110),6,0,(char *)0x0,(char *)0x0);
        msys::MLyt::playAnimeFromNo(this_01,5,0,(char *)0x0,(char *)0x0);
        *(undefined1 *)(param_1 + 0x4234d) = 1;
        msys::MListWndPBase::setEnableInput(this,true);
        *(undefined1 *)(param_1 + 0x49c49) = 0;
        msys::MListWndPBase::setEnableInput(this,false);
        *(code **)(param_1 + 0x20) = FUN_1501c71c;
        *(undefined4 *)(param_1 + 0x24) = 0;
        return;
      case '\x04':
        msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x110),7,0,(char *)0x0,(char *)0x0);
        msys::MLyt::playAnimeFromNo
                  ((MLyt *)(param_1 + 0x110),8,0,"pnl_COLISEUM_TOROPHY",(char *)0x0);
        msys::MLyt::playAnimeFromNo(this_01,6,0,(char *)0x0,(char *)0x0);
        *(undefined1 *)(param_1 + 0x4234d) = 1;
        msys::MListWndPBase::setEnableInput(this,true);
        *(undefined1 *)(param_1 + 0x49c49) = 0;
        msys::MListWndPBase::setEnableInput(this,false);
        *(code **)(param_1 + 0x20) = FUN_1501c528;
        *(undefined4 *)(param_1 + 0x24) = 0;
        return;
      case '\x05':
        FUN_1501dfd0(param_1);
        return;
      default:
        return;
      }
    }
    if (*(char *)(param_1 + iVar8 + 0x42206) == '\0') {
      FUN_1501580c(msys::MComSys::_sys + 0x49368,0x110018,0,0,0);
    }
    else {
      FUN_1501580c(msys::MComSys::_sys + 0x49368,0x110016,0,0,0);
    }
    iVar3 = msys::MComSys::_sys;
    iVar5 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar5 = iVar3;
    }
    *(undefined1 *)(iVar5 + 0xe6508) = 0;
    iVar3 = msys::MComSys::_sys;
    iVar5 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar5 = iVar3;
    }
    *(undefined1 *)(iVar5 + 0xe650a) = 1;
  }
  if (*(char *)(param_1 + 0x8a4) != iVar8) {
    *(char *)(param_1 + 0x8a4) = cVar1;
    FUN_15014e10(this_00);
    FUN_1501580c(msys::MComSys::_sys + 0x49368,0x110015,0,0,0);
  }
  return;
}


// FUNC 0x1501aa44 FUN_1501aa44 (MainMenu)
//   size 0x6c | file MainMenu+0x1aa44 | callers(0) | datarefs 1

void FUN_1501aa44(int param_1)

{
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x110),1,0,(char *)0x0,(char *)0x0);
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x110),10,0,"pnl_RECORD",(char *)0x0);
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x4b8),1,0,(char *)0x0,(char *)0x0);
  *(undefined1 *)(param_1 + 0x870) = 0;
  *(code **)(param_1 + 0x20) = FUN_1501c968;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


// FUNC 0x1501aac0 FUN_1501aac0 (MainMenu)
//   size 0x330 | file MainMenu+0x1aac0 | callers(0)

void FUN_1501aac0(void *param_1)

{
  int *piVar1;
  AnimButton *this;
  uint uVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  MLyt *this_00;
  MListWndPBase *this_01;
  uint uVar6;
  undefined4 *puVar7;
  LytLocalize aLStack_38 [16];
  undefined4 local_28;
  
  if (*(int *)((int)param_1 + 8) == 0) {
    *(undefined4 *)((int)param_1 + 8) = msys::MComSys::_sys;
  }
  ad::lyt::LytLocalize::LytLocalize(aLStack_38);
  ad::lyt::LytLocalize::localize(aLStack_38,*(Layout **)((int)param_1 + 0x260));
  ad::lyt::LytLocalize::localize(aLStack_38,*(Layout **)((int)param_1 + 0x608));
  local_28 = 0;
  piVar3 = (int *)(*(int *)((int)param_1 + 4) + 4);
  puVar7 = *(undefined4 **)((int)param_1 + 0x118);
  *(undefined4 **)(*(int *)((int)param_1 + 0x114) + 4) = puVar7;
  *puVar7 = *(undefined4 *)((int)param_1 + 0x114);
  piVar1 = (int *)((int)param_1 + 0x114);
  if (piVar1 != (int *)0x0) {
    iVar4 = *piVar3;
    *(int **)((int)param_1 + 0x118) = piVar3;
    *piVar1 = iVar4;
    *(int **)(iVar4 + 4) = piVar1;
    *piVar3 = (int)piVar1;
  }
  *(undefined4 *)((int)param_1 + 0x24c) = 0x400;
  this = (AnimButton *)
         ad::ctrl::ButtonGroup::FindButtonByName((ButtonGroup *)((int)param_1 + 0x3c),"btn_RETURN");
  *(AnimButton **)((int)param_1 + 0x860) = this;
  ad::ctrl::AnimButton::SetStateChangeCallback
            (this,(_func_void_AnimButton_ptr_State_State_void_ptr *)&LAB_150013dc,param_1);
  *(uint *)(*(int *)((int)param_1 + 0x860) + 8) =
       *(uint *)(*(int *)((int)param_1 + 0x860) + 8) & 0xffffffdf;
  *(undefined4 *)(*(int *)((int)param_1 + 0x860) + 0x48) = 0;
  (**(code **)(**(int **)((int)param_1 + 0x860) + 0x28))(*(int **)((int)param_1 + 0x860),1);
  this_00 = (MLyt *)((int)param_1 + 0x4b8);
  piVar3 = (int *)(*(int *)((int)param_1 + 4) + 0xc);
  puVar7 = *(undefined4 **)((int)param_1 + 0x4c0);
  *(undefined4 **)(*(int *)((int)param_1 + 0x4bc) + 4) = puVar7;
  *puVar7 = *(undefined4 *)((int)param_1 + 0x4bc);
  piVar1 = (int *)((int)param_1 + 0x4bc);
  if (piVar1 != (int *)0x0) {
    iVar4 = *piVar3;
    *(int **)((int)param_1 + 0x4c0) = piVar3;
    *piVar1 = iVar4;
    *(int **)(iVar4 + 4) = piVar1;
    *piVar3 = (int)piVar1;
  }
  uVar5 = 0;
  *(undefined4 *)((int)param_1 + 0x5f4) = 0x401;
  msys::MLyt::stopAnimeAndSetSt((MLyt *)((int)param_1 + 0x110),1,0,(char *)0x0,(char *)0x0);
  msys::MLyt::stopAnimeAndSetSt((MLyt *)((int)param_1 + 0x110),10,0,"pnl_RECORD",(char *)0x0);
  msys::MLyt::stopAnimeAndSetSt(this_00,1,0,(char *)0x0,(char *)0x0);
  iVar4 = main_menu::GetBootInfo();
  if (0x13 < *(byte *)(iVar4 + 0x2c)) {
    msys::MLyt::stopAnimeAndSetEnd((MLyt *)((int)param_1 + 0x110),1,0,(char *)0x0,(char *)0x0);
    msys::MLyt::stopAnimeAndSetEnd((MLyt *)((int)param_1 + 0x110),10,1,"pnl_RECORD",(char *)0x0);
    msys::MLyt::stopAnimeAndSetEnd(this_00,1,1,(char *)0x0,(char *)0x0);
    msys::MLyt::stopAnimeAndSetEnd((MLyt *)((int)param_1 + 0x110),4,0,(char *)0x0,(char *)0x0);
    msys::MLyt::stopAnimeAndSetEnd(this_00,4,0,(char *)0x0,(char *)0x0);
    this_01 = (MListWndPBase *)((int)param_1 + 0x4220c);
    *(undefined1 *)((int)param_1 + 0x4234d) = 1;
    *(undefined1 *)((int)param_1 + 0x49c49) = 0;
    *(undefined4 *)(*(int *)((int)param_1 + 0x860) + 0x48) = 1;
    *(undefined1 *)((int)param_1 + 0x870) = 2;
    FUN_15010b9c(this_01);
    iVar4 = main_menu::GetBootInfo();
    uVar6 = *(byte *)(iVar4 + 0x2c) - 0x14 & 0xff;
    uVar2 = msys::MListWndPBase::getItemNum(this_01);
    if (uVar2 != 0) {
      do {
        if (*(uint *)((int)param_1 + uVar5 * 0x1c + 0x491ac) == (uVar6 << 0xc | 0x3ff)) break;
        uVar5 = uVar5 + 1 & 0xff;
      } while (uVar5 < uVar2);
    }
    piVar1 = (int *)msys::MListWndPBase::getListWnd(this_01);
    (**(code **)(*piVar1 + 0x28))(piVar1,uVar5);
    FUN_15010ac4(param_1,*(uint *)((int)param_1 + uVar5 * 0x1c + 0x491ac) & 0xffff);
    msys::MMsg::playStr((MMsg *)((int)param_1 + 0x767c),
                        *(wchar_t **)((int)param_1 + uVar5 * 0x1c + 0x491bc),(InsParam *)0x0,false);
    PutRegFlag((&DAT_15024a2c)[uVar6 * 0xc],1.0,(GlobalEvent *)0x0,(LocalEvent *)0x0);
    *(code **)((int)param_1 + 0x20) = FUN_1501c07c;
    *(undefined4 *)((int)param_1 + 0x24) = 0;
  }
  msys::MCursorBase::setVisible((MCursorBase *)((int)param_1 + 0x88c),false);
  *(undefined1 **)((int)param_1 + 0x10) = &LAB_1501caa0;
  *(undefined4 *)((int)param_1 + 0x14) = 0;
  return;
}


// FUNC 0x1501ae30 FUN_1501ae30 (MainMenu)
//   size 0x15c | file MainMenu+0x1ae30 | callers(0) | datarefs 2

void FUN_1501ae30(int param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  uint in_fpscr;
  undefined4 extraout_s1;
  float fVar4;
  
  iVar1 = msys::MChrBaseCore::isBusySRTMov((MChrBaseCore *)(param_1 + 0x3f03c));
  if (iVar1 == 0) {
    msys::MListWndPBase::getCurPos((MListWndPBase *)(param_1 + 0x4220c));
    piVar2 = (int *)(*(int *)(param_1 + 4) + 0xc);
    piVar3 = *(int **)(param_1 + 0x3f2c0);
    *(int **)(*(int *)(param_1 + 0x3f2bc) + 4) = piVar3;
    *piVar3 = *(int *)(param_1 + 0x3f2bc);
    piVar3 = (int *)(param_1 + 0x3f2bc);
    if (piVar3 != (int *)0x0) {
      iVar1 = *piVar2;
      *(int **)(param_1 + 0x3f2c0) = piVar2;
      *piVar3 = iVar1;
      *(int **)(iVar1 + 4) = piVar3;
      *piVar2 = (int)piVar3;
    }
    *(undefined4 *)(param_1 + 0x3f3f4) = 0x401;
    MoveVBase::stop((MoveVBase *)(param_1 + 0x3f384));
    *(undefined4 *)(param_1 + 0x3f3a0) = 0;
    *(undefined4 *)(param_1 + 0x3f388) = 0;
    *(undefined4 *)(param_1 + 0x3f3a4) = extraout_s1;
    *(undefined4 *)(param_1 + 0x3f3a8) = 0x43340000;
    *(undefined4 *)(param_1 + 0x3f38c) = extraout_s1;
    *(undefined4 *)(param_1 + 0x3f390) = 0x43340000;
    msys::MDfxChr::playDfx((MDfxChr *)(param_1 + 0x3f2b8),0x15);
    fVar4 = (float)VectorSignedToFloat((int)*(short *)(*(int *)(param_1 + 0x3f40c) + 0xf4),
                                       (byte)(in_fpscr >> 0x16) & 3);
    FUN_1501580c(msys::MComSys::_sys + 0x49368,0x11001d,0,0,0);
    MoveVBase::moveCosSinAbs((VEC3 *)(param_1 + 0x3f108),fVar4);
    MoveVBase::moveCosSinAbs((VEC3 *)(param_1 + 0x3f500),fVar4);
    *(code **)(param_1 + 0x20) = FUN_1501afac;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x1501afac FUN_1501afac (MainMenu)
//   size 0x6c | file MainMenu+0x1afac | callers(0) | datarefs 2

void FUN_1501afac(int param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x3f40c);
  cVar1 = '\0';
  if (iVar2 != 0) {
    cVar1 = *(char *)(iVar2 + 0x172);
  }
  if (iVar2 == 0 || cVar1 == '\0') {
    CellAnime::play((CellAnime *)(param_1 + 0x3f188),'\x0e',0,1.0);
    if (*(Unit **)(param_1 + 0x3f588) != (Unit *)0x0) {
      ad::dfx::Unit::kill(*(Unit **)(param_1 + 0x3f588));
    }
    FUN_15010b9c(param_1 + 0x4220c,2);
    *(code **)(param_1 + 0x20) = FUN_1501b024;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x1501b024 FUN_1501b024 (MainMenu)
//   size 0x1ac | file MainMenu+0x1b024 | callers(0) | datarefs 2

void FUN_1501b024(int param_1)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  bool bVar5;
  undefined4 auStackY_98 [18];
  
  uVar1 = *(uint *)(param_1 + 0x3f40c);
  if (uVar1 != 0) {
    bVar5 = *(int *)(uVar1 + 4) != uVar1 + 4;
    if (!bVar5) {
      uVar1 = (uint)*(byte *)(uVar1 + 0x172);
    }
    if (bVar5 || uVar1 != 0) {
      return;
    }
  }
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x110),5,0,"pnl_ATTACK_PARTS",(char *)0x0);
  iVar2 = msys::MListWndPBase::getCurItem();
  msys::MMsg::playStr((MMsg *)(param_1 + 0x767c),*(wchar_t **)(iVar2 + 0x10),(InsParam *)0x0,false);
  CellAnime::play((CellAnime *)(param_1 + 0x3f188),'\x14',0,1.0);
  piVar3 = (int *)(*(int *)(param_1 + 4) + 0xc);
  piVar4 = *(int **)(param_1 + 0x3810c);
  *(int **)(*(int *)(param_1 + 0x38108) + 4) = piVar4;
  *piVar4 = *(int *)(param_1 + 0x38108);
  piVar4 = (int *)(param_1 + 0x38108);
  if (piVar4 != (int *)0x0) {
    iVar2 = *piVar3;
    *(int **)(param_1 + 0x3810c) = piVar3;
    *piVar4 = iVar2;
    *(int **)(iVar2 + 4) = piVar4;
    *piVar3 = (int)piVar4;
  }
  *(undefined4 *)(param_1 + 0x38240) = 0x401;
  MoveVBase::stop((MoveVBase *)(param_1 + 0x381d0));
  *(undefined4 *)(param_1 + 0x381ec) = 0;
  *(undefined4 *)(param_1 + 0x381f0) = 0;
  *(undefined4 *)(param_1 + 0x381f4) = 0xc347cccd;
  *(undefined4 *)(param_1 + 0x381d4) = *(undefined4 *)(param_1 + 0x381ec);
  *(undefined4 *)(param_1 + 0x381d8) = 0;
  *(undefined4 *)(param_1 + 0x381dc) = 0xc347cccd;
  iVar2 = main_menu::GetBootInfo();
  *(undefined4 *)(param_1 + 0x3effc) = auStackY_98[*(byte *)(iVar2 + 0x2c)];
  *(undefined4 *)(param_1 + 0x3f034) = 0x11000a;
  *(undefined4 *)(param_1 + 0x3f030) = 0x110009;
  *(int *)(param_1 + 0x3f020) = param_1 + 0x3f038;
  *(undefined4 *)(param_1 + 0x3f000) = 0x401;
  *(undefined1 *)(param_1 + 0x3f028) = 0;
  *(undefined4 *)(param_1 + 0x3f024) = 1;
  Message::play((Message *)(param_1 + 0x38250),(PlayParam *)(param_1 + 0x3effc));
  FUN_15010874(param_1);
  *(code **)(param_1 + 0x20) = FUN_1501b204;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


// FUNC 0x1501b204 FUN_1501b204 (MainMenu)
//   size 0x4c | file MainMenu+0x1b204 | callers(0) | datarefs 2

void FUN_1501b204(int param_1)

{
  if (*(int *)(param_1 + 0x3ed4c) == 0) {
    *(char **)(param_1 + 0x3effc) = "MES_spatk_00_yo_test_play2";
    Message::play((Message *)(param_1 + 0x38250),(PlayParam *)(param_1 + 0x3effc));
    FUN_15010874(param_1);
    *(code **)(param_1 + 0x20) = FUN_1501b270;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x1501b270 FUN_1501b270 (MainMenu)
//   size 0x274 | file MainMenu+0x1b270 | callers(0) | datarefs 2

void FUN_1501b270(int param_1)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  BootInfo *pBVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined4 local_38;
  uint local_34 [2];
  
  iVar2 = msys::MComSys::_sys;
  if (*(int *)(param_1 + 0x3f038) == 0) {
    iVar5 = *(int *)(param_1 + 8);
    if (iVar5 == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar5 = iVar2;
    }
    *(undefined1 *)(iVar5 + 0xe6508) = 0;
    iVar2 = main_menu::GetBootInfo();
    *(undefined1 *)(iVar2 + 0x2c) = 0;
    pBVar4 = (BootInfo *)main_menu::GetBootInfo();
    main_menu::BootInfo::setBootPage(pBVar4,0);
    iVar5 = msys::MComSys::_sys;
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar5;
    }
    *(undefined1 *)(iVar2 + 0xe6508) = 0;
    local_38 = 0xff000000;
    MoveC::moveFrm((MoveC *)(iVar2 + 0x4acd4),(Color8 *)&local_38,16.0);
    MoveC::moveFrm((MoveC *)(iVar2 + 0x4ad14),(Color8 *)&local_38,16.0);
    pBVar4 = (BootInfo *)main_menu::GetBootInfo();
    main_menu::BootInfo::stopRcordBgm(pBVar4);
    pBVar4 = (BootInfo *)main_menu::GetBootInfo();
    main_menu::BootInfo::restoreBgm(pBVar4);
    *(undefined1 *)(iVar2 + 0xe904b) = 4;
    *(undefined **)(param_1 + 0x20) = &DAT_1501b500;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  else if (*(int *)(param_1 + 0x3f038) == 1) {
    iVar5 = *(int *)(param_1 + 8);
    if (iVar5 == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar5 = iVar2;
    }
    *(undefined1 *)(iVar5 + 0xe6508) = 0;
    puVar1 = (uint *)msys::MListWndPBase::getCurItem();
    iVar2 = main_menu::GetBootInfo();
    uVar6 = *puVar1;
    uVar7 = 0;
    uVar3 = ad::db::GetAtkGuideList(local_34);
    uVar8 = uVar3 + local_34[0] * 0x10;
    for (; (uVar3 < uVar8 &&
           ((iVar5 = BattleAttackGuideDataAcs::IsExistGuide(uVar7,true), iVar5 == 0 ||
            ((uint)*(ushort *)(uVar3 + 0xc) != (uVar6 >> 0xc) + 0xb000)))); uVar3 = uVar3 + 0x10) {
      uVar7 = uVar7 + 1;
    }
    *(undefined1 *)(iVar2 + 0x2b) = 1;
    *(undefined2 *)(iVar2 + 0x28) = 0;
    *(undefined1 *)(iVar2 + 0x2a) = 0;
    *(undefined1 *)(iVar2 + 0x20) = 0xff;
    *(undefined1 *)(iVar2 + 0x21) = 0xff;
    *(uint *)(iVar2 + 0x24) = uVar7 | 0x4000;
    iVar2 = main_menu::GetBootInfo();
    *(undefined1 *)(iVar2 + 0x2c) = 0;
    pBVar4 = (BootInfo *)main_menu::GetBootInfo();
    main_menu::BootInfo::setBootPage(pBVar4,0);
    iVar5 = msys::MComSys::_sys;
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar5;
    }
    local_38 = 0xff000000;
    MoveC::moveFrm((MoveC *)(iVar2 + 0x4acd4),(Color8 *)&local_38,16.0);
    MoveC::moveFrm((MoveC *)(iVar2 + 0x4ad14),(Color8 *)&local_38,16.0);
    iVar5 = msys::MComSys::_sys;
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar5;
    }
    ad::lyt::LytAnim::playAuto((LytAnim *)(iVar2 + 0xe9e60),1.0);
    *(undefined1 *)(param_1 + 0x865) = 6;
    return;
  }
  return;
}


// FUNC 0x1501b504 main_menu::MainMenu_RecordPage::Core::vfunc_0x10 (MainMenu)
//   size 0x4ac | file MainMenu+0x1b504 | callers(0) | datarefs 1

void main_menu::MainMenu_RecordPage::Core::vfunc_0x10(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  LytAnim *pLVar4;
  BootInfo *this;
  code *pcVar5;
  Layout *pLVar6;
  uint uVar7;
  
  if (param_2 == 4) {
    FUN_1501580c(msys::MComSys::_sys + 0x49368,0x110017,0,0,0);
    iVar2 = msys::MComSys::_sys;
    iVar3 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar3 = iVar2;
    }
    *(undefined1 *)(iVar3 + 0xe6508) = 0;
  }
  else if (param_2 == 5) {
    iVar3 = *(int *)(*(int *)(param_1 + 0x860) + 0x48);
    if (iVar3 == 0) {
      *(undefined1 *)(param_1 + 0x872) = 0;
      msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x110),1,1,(char *)0x0,(char *)0x0);
      msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x110),10,1,"pnl_RECORD",(char *)0x0);
      msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x4b8),1,1,(char *)0x0,(char *)0x0);
      iVar2 = msys::MComSys::_sys;
      iVar3 = *(int *)(param_1 + 8);
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar3 = iVar2;
      }
      iVar3 = msys::MLyt::getParts((MLyt *)(iVar3 + 0xe934c),"MAP_ALL",(char *)0x0,(char *)0x0);
      iVar2 = msys::MComSys::_sys;
      pLVar6 = *(Layout **)(iVar3 + 0xac);
      iVar3 = *(int *)(param_1 + 8);
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar3 = iVar2;
      }
      msys::MMapIconMan::setUp((MMapIconMan *)(iVar3 + 0xea174),pLVar6,(GameWorkPOD *)&gGameWork);
      msys::MCursorBase::setVisible((MCursorBase *)(param_1 + 0x88c),false);
      FUN_15014e10((MCursorBase *)(param_1 + 0x88c));
      pcVar5 = FUN_1501c67c;
    }
    else {
      if (iVar3 != 1) {
        return;
      }
      msys::MLyt::playAnimeFromNo
                ((MLyt *)(param_1 + 0x110),
                 (uint)(byte)(&DAT_15024f38)[*(char *)(param_1 + 0x870) * 2],1,(char *)0x0,
                 (char *)0x0);
      if ((&DAT_15024f38)[*(char *)(param_1 + 0x870) * 2] == '\a') {
        msys::MLyt::playAnimeFromNo
                  ((MLyt *)(param_1 + 0x110),8,1,"pnl_COLISEUM_TOROPHY",(char *)0x0);
      }
      iVar3 = msys::MComSys::_sys;
      if (*(char *)(param_1 + 0x870) < '\x02') {
        iVar2 = *(int *)(param_1 + 8);
        if (*(int *)(param_1 + 8) == 0) {
          *(int *)(param_1 + 8) = msys::MComSys::_sys;
          iVar2 = iVar3;
        }
        ad::lyt::LytAnim::playAuto((LytAnim *)(iVar2 + 0xe9e44),1.0);
      }
      msys::MLyt::playAnimeFromNo
                ((MLyt *)(param_1 + 0x4b8),
                 (uint)(byte)(&DAT_15024f39)[*(char *)(param_1 + 0x870) * 2],1,(char *)0x0,
                 (char *)0x0);
      msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x110),10,0,"pnl_RECORD",(char *)0x0);
      cVar1 = *(char *)(param_1 + 0x870);
      if (cVar1 == '\x02') {
        if ((*(int *)(param_1 + 0x37e18) != 0) || ((*(byte *)(param_1 + 0x36b58) & 1) != 0)) {
          Message::close((Message *)(param_1 + 0x3131c));
        }
      }
      else if (cVar1 == '\x03') {
        if (-1 < *(int *)(param_1 + 0x421ec)) {
          pLVar4 = (LytAnim *)
                   msys::MLyt::getAnim((MLyt *)(param_1 + 0x110),
                                       (ushort)*(int *)(param_1 + 0x421ec) & 0xff);
          ad::lyt::LytAnim::stopAndSetFrm(pLVar4,0.0);
        }
        *(undefined4 *)(param_1 + 0x421ec) = 0xffffffff;
        *(undefined4 *)(param_1 + 0x421e8) = 0;
        uVar7 = 0;
        do {
          iVar3 = param_1 + uVar7 * 0x17c;
          if (*(int *)(iVar3 + 0x41464) != 0) {
            msys::MDfxChr::term((MDfxChr *)(iVar3 + 0x41310));
          }
          uVar7 = uVar7 + 1 & 0xff;
        } while (uVar7 < 6);
        uVar7 = 0;
        do {
          iVar3 = param_1 + uVar7 * 0x17c;
          if (*(int *)(iVar3 + 0x41d4c) != 0) {
            msys::MDfxChr::term((MDfxChr *)(iVar3 + 0x41bf8));
          }
          uVar7 = uVar7 + 1 & 0xff;
        } while (uVar7 < 4);
      }
      else if (cVar1 == '\x04') {
        if (-1 < *(int *)(param_1 + 0x421ec)) {
          pLVar4 = (LytAnim *)
                   msys::MLyt::getAnim((MLyt *)(param_1 + 0x110),
                                       (ushort)*(int *)(param_1 + 0x421ec) & 0xff);
          ad::lyt::LytAnim::stopAndSetFrm(pLVar4,0.0);
        }
        *(undefined4 *)(param_1 + 0x421e8) = 0;
        *(undefined4 *)(param_1 + 0x421ec) = 0xffffffff;
        uVar7 = 0;
        do {
          iVar3 = param_1 + uVar7 * 0x17c;
          if (*(int *)(iVar3 + 0x40410) != 0) {
            msys::MDfxChr::term((MDfxChr *)(iVar3 + 0x402bc));
          }
          uVar7 = uVar7 + 1 & 0xff;
        } while (uVar7 < 6);
        if (*(int *)(param_1 + 0x40cf8) != 0) {
          msys::MDfxChr::term((MDfxChr *)(param_1 + 0x40ba4));
        }
        uVar7 = 0;
        do {
          iVar3 = param_1 + uVar7 * 0x17c;
          if (*(int *)(iVar3 + 0x40e74) != 0) {
            msys::MDfxChr::term((MDfxChr *)(iVar3 + 0x40d20));
          }
          uVar7 = uVar7 + 1 & 0xff;
        } while (uVar7 < 4);
      }
      else if (cVar1 == '\x05') {
        DAT_003f4053 = 0;
        nn::applet::CTR::EnableSleep(true);
        if (-1 < *(int *)(param_1 + 0x42200)) {
          pLVar4 = (LytAnim *)
                   msys::MLyt::getAnim((MLyt *)(param_1 + 0x110),(short)*(int *)(param_1 + 0x42200))
          ;
          ad::lyt::LytAnim::stop(pLVar4);
        }
        *(undefined4 *)(param_1 + 0x42200) = 0xffffffff;
        msys::MDfxChr::term((MDfxChr *)(param_1 + 0x40140));
        if ((DAT_003fbfa0 != 0) && (*(char *)(param_1 + 0x519b5) != '\0')) {
          SndSys::stop((SndSys *)&gSndSys,(SoundHandle *)&DAT_003fbfa0,0);
          *(undefined1 *)(param_1 + 0x519b5) = 0;
        }
        *(undefined1 *)(param_1 + 0x519ad) = 0xff;
        this = (BootInfo *)GetBootInfo();
        BootInfo::restoreBgm(this);
      }
      pcVar5 = FUN_1501cb84;
    }
    *(code **)(param_1 + 0x20) = pcVar5;
    *(undefined4 *)(param_1 + 0x24) = 0;
    return;
  }
  return;
}


// FUNC 0x1501ba2c FUN_1501ba2c (MainMenu)
//   size 0x94 | file MainMenu+0x1ba2c | callers(0) | datarefs 1

void FUN_1501ba2c(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = msys::MLyt::isBusyAnime((MLyt *)(param_1 + 0x4b8));
  if ((iVar1 == 0) && (iVar1 = msys::MLyt::isBusyAnime((MLyt *)(param_1 + 0x110)), iVar1 == 0)) {
    iVar2 = *(int *)(param_1 + 8);
    iVar1 = iVar2;
    if (iVar2 == 0) {
      iVar1 = msys::MComSys::_sys;
    }
    if (iVar2 == 0) {
      *(int *)(param_1 + 8) = iVar1;
    }
    iVar2 = msys::MComSys::_sys;
    if (*(float *)(iVar1 + 0x4ad04) <= *(float *)(iVar1 + 0x4ad00)) {
      if (iVar1 == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar1 = iVar2;
      }
      if (*(float *)(iVar1 + 0x4ad44) <= *(float *)(iVar1 + 0x4ad40)) {
        *(undefined1 **)(param_1 + 0x18) = &LAB_1501dd50;
        *(undefined4 *)(param_1 + 0x1c) = 0;
      }
    }
  }
  return;
}


// FUNC 0x1501bad0 FUN_1501bad0 (MainMenu)
//   size 0x4c0 | file MainMenu+0x1bad0 | callers(1) 0x15018ed8

void FUN_1501bad0(MListWndPBase *param_1,LytResourceMan *param_2,undefined4 param_3,int param_4,
                 Resource *param_5)

{
  int iVar1;
  void *pvVar2;
  undefined4 *puVar3;
  void *pvVar4;
  int iVar5;
  MListWndPBase *pMVar6;
  Layout *pLVar7;
  Resource *this;
  int local_208 [2];
  CellAnime *local_200;
  CellAnime *local_1fc;
  undefined4 local_1f4;
  undefined4 local_1f0;
  undefined4 local_1e8;
  undefined4 local_1dc;
  undefined4 local_1d8;
  undefined4 local_1d0;
  undefined4 local_1cc;
  LytAnim *local_1c8;
  LytAnim *local_1b8;
  LytAnim *local_1b4;
  LytAnim *local_1b0;
  LytAnim *local_1ac;
  LytAnim *local_1a8;
  undefined1 local_1a0;
  float local_18c;
  undefined4 local_154;
  undefined4 uStack_150;
  undefined4 local_14c;
  undefined4 uStack_148;
  float local_13c;
  float local_138;
  MListWndPBase *local_cc;
  undefined1 local_c8;
  Layout *local_88;
  LytAnim *local_84;
  LytAnim *local_80;
  float local_7c;
  float fStack_78;
  float local_74;
  float local_70;
  MListWndPBase *local_6c;
  LytAnim *local_68;
  Layout *local_64;
  LytAnim *local_60;
  Layout *local_5c;
  LytAnim *local_58;
  LytAnim *local_54;
  LytAnim *local_50;
  LytAnim *local_4c;
  LytAnim *local_48;
  LytAnim *local_40;
  MListWndPBase *local_38;
  
  pLVar7 = (Layout *)(param_1 + 0x7364);
  ad::lyt::LytResourceMan::buildLayout
            (param_2,pLVar7,"MENU_RECORD_L_LIST.bflyt",(ControlCreator *)0x0,(TextSearcher *)0x0);
  local_40 = (LytAnim *)(param_1 + 0x73dc);
  ad::lyt::LytAnim::init(local_40,pLVar7,"touch","");
  local_68 = (LytAnim *)(param_1 + 0x7414);
  ad::lyt::LytAnim::init(local_68,pLVar7,"SET_ICON","");
  local_64 = (Layout *)(param_1 + 0x7468);
  ad::lyt::LytResourceMan::buildLayout
            (param_2,local_64,"NUM_G_s.bflyt",(ControlCreator *)0x0,(TextSearcher *)0x0);
  local_48 = (LytAnim *)(param_1 + 0x74a4);
  ad::lyt::LytAnim::init(local_48,local_64,"num_set_U","");
  local_4c = (LytAnim *)(param_1 + 0x74c0);
  ad::lyt::LytAnim::init(local_4c,local_64,"col_00","");
  local_50 = (LytAnim *)(param_1 + 0x74dc);
  ad::lyt::LytAnim::init(local_50,local_64,"col_s06","");
  local_5c = (Layout *)(param_1 + 0x73a0);
  ad::lyt::LytResourceMan::buildLayout
            (param_2,local_5c,"NUM_G_s_slash.bflyt",(ControlCreator *)0x0,(TextSearcher *)0x0);
  local_58 = (LytAnim *)(param_1 + 0x7430);
  ad::lyt::LytAnim::init(local_58,local_5c,"col_00","");
  local_60 = (LytAnim *)(param_1 + 0x744c);
  ad::lyt::LytAnim::init(local_60,local_5c,"col_s06","");
  local_54 = (LytAnim *)(param_1 + 0x73f8);
  ad::lyt::LytAnim::init(local_54,pLVar7,"ATTENTION","");
  ad::lyt::LytAnim::playAuto(local_54,1.0);
  pvVar2 = (void *)ad::fw::Resource::getCA_anm(param_5);
  puVar3 = (undefined4 *)ad::fw::Resource::getCA_tex(param_5);
  pvVar4 = (void *)ad::fw::Resource::getCA_canm(param_5);
  CellAnime::init((CellAnime *)(param_1 + 0x7578),pvVar2,(void *)*puVar3,pvVar4,'\0',0,1.0);
  this = param_5 + 0x44;
  param_1[0x761b] = (MListWndPBase)((byte)param_1[0x761b] | 3);
  param_1[0x7610] = (MListWndPBase)0x0;
  param_1[0x7611] = (MListWndPBase)0x0;
  pvVar2 = (void *)ad::fw::Resource::getCA_anm(this);
  puVar3 = (undefined4 *)ad::fw::Resource::getCA_tex(this);
  pvVar4 = (void *)ad::fw::Resource::getCA_canm(this);
  CellAnime::init((CellAnime *)(param_1 + 0x76a4),pvVar2,(void *)*puVar3,pvVar4,'\0',0,1.0);
  param_5 = param_5 + 0x88;
  param_1[0x7747] = (MListWndPBase)((byte)param_1[0x7747] | 3);
  param_1[0x773c] = (MListWndPBase)0x0;
  param_1[0x773d] = (MListWndPBase)0x0;
  pvVar2 = (void *)ad::fw::Resource::getCA_anm(param_5);
  puVar3 = (undefined4 *)ad::fw::Resource::getCA_tex(param_5);
  pvVar4 = (void *)ad::fw::Resource::getCA_canm(param_5);
  CellAnime::init((CellAnime *)(param_1 + 0x77d0),pvVar2,(void *)*puVar3,pvVar4,'\0',0,1.0);
  param_1[0x7873] = (MListWndPBase)((byte)param_1[0x7873] | 3);
  param_1[0x7868] = (MListWndPBase)0x0;
  param_1[0x7869] = (MListWndPBase)0x0;
  *(int *)(param_1 + 0x7360) = param_4;
  iVar1 = msys::MComSys::_sys;
  iVar5 = *(int *)(param_4 + 8);
  if (*(int *)(param_4 + 8) == 0) {
    *(int *)(param_4 + 8) = msys::MComSys::_sys;
    iVar5 = iVar1;
  }
  local_38 = param_1 + 0x6fa0;
  pMVar6 = local_38;
  do {
    pMVar6[8] = (MListWndPBase)0xff;
    pMVar6[9] = (MListWndPBase)0xff;
    pMVar6[10] = (MListWndPBase)0xff;
    pMVar6[0xb] = (MListWndPBase)0xff;
    pMVar6[0xc] = (MListWndPBase)0xff;
    pMVar6[0xd] = (MListWndPBase)0xff;
    pMVar6[6] = (MListWndPBase)0xff;
    pMVar6[0xf] = (MListWndPBase)0x0;
    *(undefined4 *)(pMVar6 + 0x14) = 0;
    pMVar6 = pMVar6 + 0x1c;
  } while (pMVar6 != param_1 + 0x7320);
  ad::ui::UIListWindowPlusLyt::InitParam::InitParam((InitParam *)local_208);
  msys::SetMListWndInitParam(local_208,0);
  local_14c = local_154;
  uStack_148 = uStack_150;
  local_208[0] = iVar5 + 0x4af6c;
  local_200 = (CellAnime *)(param_1 + 0x76a4);
  local_1fc = (CellAnime *)(param_1 + 0x77d0);
  local_1d0 = (**(code **)(**(int **)(param_1 + 0x7374) + 0x2c))
                        (*(int **)(param_1 + 0x7374),"FRAME",1);
  local_1f4 = 0;
  local_1f0 = (**(code **)(**(int **)(param_1 + 0x7374) + 0x2c))
                        (*(int **)(param_1 + 0x7374),"ICON_L",1);
  local_1d8 = (**(code **)(**(int **)(param_1 + 0x7374) + 0x2c))
                        (*(int **)(param_1 + 0x7374),"list_cursor",1);
  local_1dc = (**(code **)(**(int **)(param_1 + 0x7374) + 0x2c))
                        (*(int **)(param_1 + 0x7374),"list_scroll",1);
  local_1cc = 0;
  local_1ac = local_40;
  local_1c8 = local_68;
  local_1a0 = 0;
  local_1e8 = *(undefined4 *)(local_64 + 0x10);
  local_1b8 = local_48;
  local_1b4 = local_4c;
  local_c8 = 0;
  local_1b0 = local_50;
  local_1a8 = local_54;
  local_cc = local_38;
  msys::MListWndPFractionCore::InitParamEx::InitParamEx((InitParamEx *)&local_88);
  local_70 = local_138 - 0.0;
  local_74 = local_13c - local_18c * 3.0;
  local_88 = local_5c;
  fStack_78 = local_138 + 9.0;
  local_7c = local_13c - local_18c * 2.0;
  local_84 = local_58;
  local_80 = local_60;
  local_6c = param_1 + 0x7320;
  msys::MListWndPBase::init
            (param_1,(InitParam *)local_208,(LytDrawData *)(iVar5 + 0xd3000),
             (Prim *)(iVar5 + 0xd3100),(MessageDrawer *)(iVar5 + 0x1487c),
             (ApplyingSceneInfo *)(iVar5 + 0x4af54));
  msys::MListWndPFractionCore::initEx
            ((MListWndPFractionCore *)(param_1 + 0x1fc),(InitParamEx *)&local_88);
  *(undefined4 *)(param_1 + 0x13c) = 0x401;
  *(undefined4 *)(param_1 + 0x168) = 0x401;
  return;
}


// FUNC 0x1501c058 main_menu::MainMenu_RecordPage::Core::MListWndRecord::vfunc_0x4 (MainMenu)
//   size 0x10 | file MainMenu+0x1c058 | callers(0) | datarefs 1

void main_menu::MainMenu_RecordPage::Core::MListWndRecord::vfunc_0x4(void)

{
  void *pvVar1;
  
  pvVar1 = (void *)vfunc_0x0();
  operator_delete(pvVar1);
  return;
}


// FUNC 0x1501c07c FUN_1501c07c (MainMenu)
//   size 0x1b0 | file MainMenu+0x1c07c | callers(0) | datarefs 3

void FUN_1501c07c(int param_1)

{
  ushort uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  ushort *puVar5;
  uint uVar6;
  float fVar7;
  
  iVar2 = msys::MLyt::isBusyAnime((MLyt *)(param_1 + 0x110));
  if ((iVar2 == 0) && (iVar2 = msys::MLyt::isBusyAnime((MLyt *)(param_1 + 0x4b8)), iVar2 == 0)) {
    uVar6 = 0;
    do {
      piVar3 = *(int **)(param_1 + uVar6 * 4 + 0x3f700);
      (**(code **)(*piVar3 + 0x28))(piVar3,0);
      uVar6 = uVar6 + 1 & 0xff;
    } while (uVar6 < 6);
    iVar4 = main_menu::GetBootInfo();
    iVar2 = msys::MComSys::_sys;
    if (*(byte *)(iVar4 + 0x2c) < 0x14) {
      iVar4 = *(int *)(param_1 + 8);
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar4 = iVar2;
      }
      *(undefined1 *)(iVar4 + 0xe6508) = 1;
      iVar4 = msys::MComSys::_sys;
      iVar2 = *(int *)(param_1 + 8);
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar2 = iVar4;
      }
      *(undefined1 *)(iVar2 + 0xe650a) = 1;
      msys::MListWndPBase::setEnableInput((MListWndPBase *)(param_1 + 0x4220c),true);
      *(code **)(param_1 + 0x20) = FUN_1501ccd8;
      *(undefined4 *)(param_1 + 0x24) = 0;
      puVar5 = (ushort *)msys::MListWndPBase::getCurItem();
      uVar1 = *puVar5;
      uVar6 = (uint)(uVar1 >> 0xc);
      fVar7 = (float)GetRegFlag((&DAT_15024a2c)[uVar6 * 0xc],(GlobalEvent *)0x0,(LocalEvent *)0x0);
      if ((fVar7 != 0.0) || ((uVar1 & 0x3ff) == 0x3ff)) {
        uVar6 = 0xffffffff;
      }
      if (-1 < (int)uVar6) {
        *(undefined4 *)(param_1 + 0x380c8) = *(undefined4 *)(&UNK_15024a24 + uVar6 * 0x18);
        *(undefined4 *)(param_1 + 0x380cc) = 0x400;
        *(undefined1 *)(param_1 + 0x380f4) = 1;
        *(undefined4 *)(param_1 + 0x380fc) = 0xffffffff;
        *(undefined4 *)(param_1 + 0x38100) = 0xffffffff;
        Message::play((Message *)(param_1 + 0x3131c),(PlayParam *)(param_1 + 0x380c8));
        *(uint *)(param_1 + 0x37eec) = *(uint *)(param_1 + 0x37eec) | 0x10;
        return;
      }
      if ((*(int *)(param_1 + 0x37e18) != 0) || ((*(byte *)(param_1 + 0x36b58) & 1) != 0)) {
        Message::close((Message *)(param_1 + 0x3131c));
        return;
      }
    }
    else {
      *(code **)(param_1 + 0x20) = FUN_1501c24c;
      *(undefined4 *)(param_1 + 0x24) = 0;
    }
  }
  return;
}


// FUNC 0x1501c24c FUN_1501c24c (MainMenu)
//   size 0x1bc | file MainMenu+0x1c24c | callers(0) | datarefs 2

void FUN_1501c24c(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  float extraout_s1;
  float fVar4;
  
  piVar1 = (int *)(*(int *)(param_1 + 4) + 0xc);
  piVar3 = *(int **)(param_1 + 0x3f044);
  *(int **)(*(int *)(param_1 + 0x3f040) + 4) = piVar3;
  *piVar3 = *(int *)(param_1 + 0x3f040);
  piVar3 = (int *)(param_1 + 0x3f040);
  if (piVar3 != (int *)0x0) {
    iVar2 = *piVar1;
    *(int **)(param_1 + 0x3f044) = piVar1;
    *piVar3 = iVar2;
    *(int **)(iVar2 + 4) = piVar3;
    *piVar1 = (int)piVar3;
  }
  *(undefined4 *)(param_1 + 0x3f178) = 0x401;
  CellAnime::play((CellAnime *)(param_1 + 0x3f188),'\x02',0,1.0);
  CellAnime::playEvColorAnm((CellAnime *)(param_1 + 0x3f188),0,0,0,1.0);
  piVar1 = (int *)(*(int *)(param_1 + 4) + 0xc);
  piVar3 = *(int **)(param_1 + 0x3f43c);
  *(int **)(*(int *)(param_1 + 0x3f438) + 4) = piVar3;
  *piVar3 = *(int *)(param_1 + 0x3f438);
  piVar3 = (int *)(param_1 + 0x3f438);
  if (piVar3 != (int *)0x0) {
    iVar2 = *piVar1;
    *(int **)(param_1 + 0x3f43c) = piVar1;
    *piVar3 = iVar2;
    *(int **)(iVar2 + 4) = piVar3;
    *piVar1 = (int)piVar3;
  }
  *(undefined4 *)(param_1 + 0x3f570) = 0x401;
  msys::MDfxChr::playDfx((MDfxChr *)(param_1 + 0x3f434),0x14);
  *(undefined2 *)(*(int *)(param_1 + 0x3f588) + 0xf2) = 0xffff;
  msys::MListWndPBase::getCurPos((MListWndPBase *)(param_1 + 0x4220c));
  fVar4 = extraout_s1 - 10.0;
  MoveVBase::stop((MoveVBase *)(param_1 + 0x3f108));
  *(undefined4 *)(param_1 + 0x3f12c) = 0xc347cccd;
  *(undefined4 *)(param_1 + 0x3f124) = 0xc33e0000;
  *(float *)(param_1 + 0x3f128) = fVar4;
  *(undefined4 *)(param_1 + 0x3f114) = 0xc347cccd;
  *(undefined4 *)(param_1 + 0x3f10c) = 0xc33e0000;
  *(float *)(param_1 + 0x3f110) = fVar4;
  MoveVBase::stop((MoveVBase *)(param_1 + 0x3f500));
  *(undefined4 *)(param_1 + 0x3f51c) = 0xc33e0000;
  *(float *)(param_1 + 0x3f520) = fVar4;
  *(undefined4 *)(param_1 + 0x3f524) = 0x4347cccd;
  *(undefined4 *)(param_1 + 0x3f504) = 0xc33e0000;
  *(float *)(param_1 + 0x3f508) = fVar4;
  *(undefined4 *)(param_1 + 0x3f50c) = 0x4347cccd;
  MoveVBase::moveCosSinAbs((VEC3 *)(param_1 + 0x3f108),30.0);
  MoveVBase::moveCosSinAbs((VEC3 *)(param_1 + 0x3f500),30.0);
  *(code **)(param_1 + 0x20) = FUN_1501ae30;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


// FUNC 0x1501c42c FUN_1501c42c (MainMenu)
//   size 0xf0 | file MainMenu+0x1c42c | callers(0) | datarefs 2

void FUN_1501c42c(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  
  iVar1 = msys::MLyt::isBusyAnime((MLyt *)(param_1 + 0x110));
  if ((iVar1 == 0) &&
     (iVar2 = msys::MLyt::isBusyAnime((MLyt *)(param_1 + 0x4b8)), iVar1 = msys::MComSys::_sys,
     iVar2 == 0)) {
    uVar4 = 0;
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
    do {
      piVar3 = *(int **)(param_1 + uVar4 * 4 + 0x3f700);
      (**(code **)(*piVar3 + 0x28))(piVar3,0);
      uVar4 = uVar4 + 1 & 0xff;
    } while (uVar4 < 6);
    uVar4 = 0;
    do {
      piVar3 = *(int **)(param_1 + uVar4 * 4 + 0x3f718);
      (**(code **)(*piVar3 + 0x28))(piVar3,1);
      uVar4 = uVar4 + 1 & 0xff;
    } while (uVar4 < 3);
    *(undefined1 *)(param_1 + 0x873) = 0;
    *(undefined1 *)(param_1 + 0x871) = 0;
    DAT_003f4053 = 1;
    *(code **)(param_1 + 0x20) = FUN_1501cf00;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x1501c528 FUN_1501c528 (MainMenu)
//   size 0x144 | file MainMenu+0x1c528 | callers(0) | datarefs 4

void FUN_1501c528(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  
  iVar1 = msys::MLyt::isBusyAnime((MLyt *)(param_1 + 0x110));
  if ((iVar1 != 0) ||
     (iVar2 = msys::MLyt::isBusyAnime((MLyt *)(param_1 + 0x4b8)), iVar1 = msys::MComSys::_sys,
     iVar2 != 0)) {
    return;
  }
  uVar4 = 0;
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
  do {
    piVar3 = *(int **)(param_1 + uVar4 * 4 + 0x3f700);
    (**(code **)(*piVar3 + 0x28))(piVar3,0);
    uVar4 = uVar4 + 1 & 0xff;
  } while (uVar4 < 6);
  uVar4 = 0;
  do {
    iVar1 = param_1 + uVar4 * 0x17c;
    msys::MDfxChr::playDfx((MDfxChr *)(iVar1 + 0x402bc),0x29);
    iVar1 = *(int *)(iVar1 + 0x40410);
    while( true ) {
      *(undefined2 *)(iVar1 + 0xf2) = 0xffff;
      uVar4 = uVar4 + 1 & 0xff;
      if (6 < uVar4) {
        *(undefined4 *)(param_1 + 0x421e8) = 0;
        *(undefined4 *)(param_1 + 0x421ec) = 0xffffffff;
        msys::MListWndPBase::setEnableInput((MListWndPBase *)(param_1 + 0x4220c),true);
        *(code **)(param_1 + 0x20) = FUN_1501d53c;
        *(undefined4 *)(param_1 + 0x24) = 0;
        return;
      }
      if (uVar4 < 6) break;
      msys::MDfxChr::playDfx((MDfxChr *)(param_1 + 0x40ba4),0x2b);
      iVar1 = *(int *)(param_1 + 0x40cf8);
    }
  } while( true );
}


// FUNC 0x1501c67c FUN_1501c67c (MainMenu)
//   size 0x94 | file MainMenu+0x1c67c | callers(0) | datarefs 2

void FUN_1501c67c(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = msys::MComSys::_sys;
  if (*(int *)(param_1 + 8) == 0) {
    *(undefined4 *)(param_1 + 8) = msys::MComSys::_sys;
  }
  iVar2 = *(int *)(param_1 + 8);
  if (*(float *)(iVar2 + 0x4ad44) <= *(float *)(iVar2 + 0x4ad40)) {
    if (iVar2 == 0) {
      *(undefined4 *)(param_1 + 8) = uVar1;
    }
    if (((*(float *)(*(int *)(param_1 + 8) + 0x4ad04) <= *(float *)(*(int *)(param_1 + 8) + 0x4ad00)
         ) && (iVar2 = msys::MLyt::isBusyAnime((MLyt *)(param_1 + 0x110)), iVar2 == 0)) &&
       (iVar2 = msys::MLyt::isBusyAnime((MLyt *)(param_1 + 0x4b8)), iVar2 == 0)) {
      *(undefined1 *)(param_1 + 0x865) = *(undefined1 *)(param_1 + 0x872);
    }
  }
  return;
}


// FUNC 0x1501c71c FUN_1501c71c (MainMenu)
//   size 0x240 | file MainMenu+0x1c71c | callers(0) | datarefs 2

void FUN_1501c71c(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  
  iVar2 = msys::MLyt::isBusyAnime((MLyt *)(param_1 + 0x110));
  if ((iVar2 == 0) &&
     (iVar3 = msys::MLyt::isBusyAnime((MLyt *)(param_1 + 0x4b8)), iVar2 = msys::MComSys::_sys,
     iVar3 == 0)) {
    uVar5 = 0;
    iVar3 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar3 = iVar2;
    }
    *(undefined1 *)(iVar3 + 0xe6508) = 1;
    iVar3 = msys::MComSys::_sys;
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar3;
    }
    *(undefined1 *)(iVar2 + 0xe650a) = 1;
    do {
      piVar4 = *(int **)(param_1 + uVar5 * 4 + 0x3f700);
      (**(code **)(*piVar4 + 0x28))(piVar4,0);
      uVar5 = uVar5 + 1 & 0xff;
    } while (uVar5 < 6);
    iVar2 = 0;
    do {
      cVar1 = *(char *)(param_1 + iVar2 + 0x874);
      if (cVar1 != '\0') {
        if (cVar1 == '\x01') {
          msys::MDfxChr::playDfx((MDfxChr *)(param_1 + iVar2 * 0x17c + 0x41310),0x32);
        }
        else if (cVar1 == '\x02') {
          msys::MDfxChr::playDfx((MDfxChr *)(param_1 + iVar2 * 0x17c + 0x41310),0x31);
        }
        else if (cVar1 == '\x03') {
          msys::MDfxChr::playDfx((MDfxChr *)(param_1 + iVar2 * 0x17c + 0x41310),0x30);
        }
      }
      iVar3 = iVar2 + 1;
      iVar2 = *(int *)(param_1 + iVar2 * 0x17c + 0x41464);
      if (iVar2 != 0) {
        *(undefined2 *)(iVar2 + 0xf2) = 0xffff;
      }
      iVar2 = iVar3;
    } while (iVar3 < 6);
    iVar2 = 0;
    do {
      cVar1 = *(char *)(param_1 + iVar2 + 0x87a);
      if (cVar1 != '\0') {
        if (cVar1 == '\x01') {
          uVar5 = 0x32;
        }
        else {
          if (cVar1 != '\x02') {
            if (cVar1 == '\x03') {
              msys::MDfxChr::playDfx((MDfxChr *)(param_1 + iVar2 * 0x17c + 0x41bf8),0x30);
            }
            goto LAB_1501c8fc;
          }
          uVar5 = 0x31;
        }
        msys::MDfxChr::playDfx((MDfxChr *)(param_1 + iVar2 * 0x17c + 0x41bf8),uVar5);
      }
LAB_1501c8fc:
      iVar3 = iVar2 + 1;
      iVar2 = *(int *)(param_1 + iVar2 * 0x17c + 0x41d4c);
      if (iVar2 != 0) {
        *(undefined2 *)(iVar2 + 0xf2) = 0xffff;
      }
      iVar2 = iVar3;
    } while (iVar3 < 4);
    *(undefined4 *)(param_1 + 0x421e8) = 0;
    *(undefined4 *)(param_1 + 0x421ec) = 0xffffffff;
    msys::MListWndPBase::setEnableInput((MListWndPBase *)(param_1 + 0x4220c),true);
    *(code **)(param_1 + 0x20) = FUN_1501d920;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x1501c968 FUN_1501c968 (MainMenu)
//   size 0x12c | file MainMenu+0x1c968 | callers(0) | datarefs 4

void FUN_1501c968(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  
  iVar2 = msys::MLyt::isBusyAnime((MLyt *)(param_1 + 0x110));
  if ((iVar2 == 0) && (iVar2 = msys::MLyt::isBusyAnime((MLyt *)(param_1 + 0x4b8)), iVar2 == 0)) {
    msys::MListWndPBase::setEnableInput((MListWndPBase *)(param_1 + 0x4220c),false);
    msys::MListWndPBase::setEnableInput((MListWndPBase *)(param_1 + 0x49b08),false);
    iVar1 = msys::MComSys::_sys;
    uVar4 = 0;
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
    do {
      piVar3 = *(int **)(param_1 + uVar4 * 4 + 0x3f700);
      (**(code **)(*piVar3 + 0x28))(piVar3,1);
      uVar4 = uVar4 + 1 & 0xff;
    } while (uVar4 < 6);
    uVar4 = 0;
    do {
      piVar3 = *(int **)(param_1 + uVar4 * 4 + 0x3f718);
      (**(code **)(*piVar3 + 0x28))(piVar3,0);
      uVar4 = uVar4 + 1 & 0xff;
    } while (uVar4 < 3);
    *(undefined1 *)(param_1 + 0x8a4) = *(undefined1 *)(param_1 + 0x870);
    msys::MCursorBase::setVisible((MCursorBase *)(param_1 + 0x88c),true);
    FUN_15014e10((MCursorBase *)(param_1 + 0x88c));
    *(undefined4 *)(*(int *)(param_1 + 0x860) + 0x48) = 0;
    *(code **)(param_1 + 0x20) = FUN_1501db7c;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x1501cac4 FUN_1501cac4 (MainMenu)
//   size 0xb8 | file MainMenu+0x1cac4 | callers(0) | datarefs 4

void FUN_1501cac4(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  
  iVar2 = msys::MLyt::isBusyAnime((MLyt *)(param_1 + 0x110));
  if ((iVar2 == 0) && (iVar2 = msys::MLyt::isBusyAnime((MLyt *)(param_1 + 0x4b8)), iVar2 == 0)) {
    msys::MListWndPBase::setEnableInput((MListWndPBase *)(param_1 + 0x4220c),true);
    iVar1 = msys::MComSys::_sys;
    uVar4 = 0;
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
    do {
      piVar3 = *(int **)(param_1 + uVar4 * 4 + 0x3f700);
      (**(code **)(*piVar3 + 0x28))(piVar3,0);
      uVar4 = uVar4 + 1 & 0xff;
    } while (uVar4 < 6);
    *(code **)(param_1 + 0x20) = FUN_15019ce0;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x1501cb84 FUN_1501cb84 (MainMenu)
//   size 0x28 | file MainMenu+0x1cb84 | callers(0) | datarefs 2

void FUN_1501cb84(int param_1)

{
  BootInfo *this;
  int iVar1;
  
  this = (BootInfo *)main_menu::GetBootInfo();
  iVar1 = main_menu::BootInfo::playBgm(this);
  if (iVar1 != 0) {
    *(code **)(param_1 + 0x20) = FUN_1501c968;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x1501cbb0 main_menu::MainMenu_RecordPage::Core::vfunc_0x8 (MainMenu)
//   size 0x120 | file MainMenu+0x1cbb0 | callers(0) | datarefs 1

int main_menu::MainMenu_RecordPage::Core::vfunc_0x8(int *param_1,MInput *param_2)

{
  MInput MVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  code *extraout_r2;
  code *pcVar5;
  VEC2 *pVVar6;
  bool bVar7;
  bool bVar8;
  uint in_fpscr;
  undefined4 local_20;
  undefined4 local_1c;
  
  msys::MPageBase::updateInputAllChr((MPageBase *)param_1[1],param_2);
  bVar7 = (param_1[9] & 1U) == 0;
  pcVar5 = extraout_r2;
  if (bVar7) {
    pcVar5 = (code *)param_1[8];
  }
  piVar2 = (int *)((int)param_1 + (param_1[9] >> 1));
  if (!bVar7) {
    pcVar5 = *(code **)(*piVar2 + param_1[8]);
  }
  (*pcVar5)(piVar2,param_2);
  iVar3 = msys::MListWndPBase::isTpNeutral((MListWndPBase *)(param_1 + 0x10883));
  if ((iVar3 == 0) ||
     (iVar3 = msys::MListWndPBase::isTpNeutral((MListWndPBase *)(param_1 + 0x126c2)), iVar3 == 0)) {
    bVar7 = false;
  }
  else {
    bVar7 = true;
  }
  MVar1 = param_2[0x11];
  bVar8 = MVar1 == (MInput)0x0;
  if (bVar8) {
    MVar1 = param_2[0x12];
  }
  pVVar6 = (VEC2 *)0x0;
  if ((!bVar8 || MVar1 != (MInput)0x0) && bVar7) {
    local_20 = VectorSignedToFloat(*(ushort *)(param_2 + 0x14) - 0xa0,(byte)(in_fpscr >> 0x16) & 3);
    local_1c = VectorSignedToFloat(0x78 - (uint)*(ushort *)(param_2 + 0x16),
                                   (byte)(in_fpscr >> 0x16) & 3);
    pVVar6 = (VEC2 *)&local_20;
  }
  bVar8 = (bool)(**(code **)(*param_1 + 0xc))(param_1,param_2);
  iVar3 = msys::MComSys::_sys;
  iVar4 = param_1[2];
  if (param_1[2] == 0) {
    param_1[2] = msys::MComSys::_sys;
    iVar4 = iVar3;
  }
  ad::ctrl::ButtonGroup::Update
            ((ButtonGroup *)(param_1 + 0xf),pVVar6,
             (bool)(*(byte *)(iVar4 + 0xe6508) & bVar8 & bVar7),bVar8);
  return (int)*(char *)((int)param_1 + 0x865);
}


// FUNC 0x1501ccd8 FUN_1501ccd8 (MainMenu)
//   size 0x208 | file MainMenu+0x1ccd8 | callers(0) | datarefs 1

void FUN_1501ccd8(int param_1,uint *param_2)

{
  ushort uVar1;
  MListWndPBase *this;
  int iVar2;
  int iVar3;
  ushort *puVar4;
  uint uVar5;
  float fVar6;
  
  this = (MListWndPBase *)(param_1 + 0x4220c);
  msys::MListWndPBase::getSelectItem(this);
  iVar2 = msys::MListWndPBase::isBusyAnime(this);
  if ((iVar2 == 0) &&
     (iVar3 = msys::MListWndPBase::getListWnd(this), iVar2 = msys::MComSys::_sys,
     *(int *)(iVar3 + 0x1cc) == 0)) {
    iVar3 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar3 = iVar2;
    }
    ad::fw::TaskBase::isFps30(*(TaskBase **)(iVar3 + 4));
    if ((*param_2 & 0x802) != 0) {
      (**(code **)(**(int **)(param_1 + 0x860) + 0x10))();
      iVar3 = msys::MComSys::_sys;
      iVar2 = *(int *)(param_1 + 8);
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar2 = iVar3;
      }
      *(undefined1 *)(iVar2 + 0xe6508) = 0;
    }
  }
  iVar2 = msys::MListWndPBase::getListWnd(this);
  if (((*(char *)(iVar2 + 0x144) != '\0') &&
      (iVar2 = msys::MListWndPBase::getListWnd(this), *(int *)(iVar2 + 0x1cc) == 0)) &&
     (iVar2 = msys::MListWndPBase::getListWnd(this),
     (int)*(char *)(param_1 + 0x871) != (uint)*(byte *)(iVar2 + 0x149))) {
    puVar4 = (ushort *)msys::MListWndPBase::getCurItem();
    uVar1 = *puVar4;
    uVar5 = (uint)(uVar1 >> 0xc);
    fVar6 = (float)GetRegFlag((&DAT_15024a2c)[uVar5 * 0xc],(GlobalEvent *)0x0,(LocalEvent *)0x0);
    if ((fVar6 != 0.0) || ((uVar1 & 0x3ff) == 0x3ff)) {
      uVar5 = 0xffffffff;
    }
    if ((int)uVar5 < 0) {
      if ((*(int *)(param_1 + 0x37e18) != 0) || ((*(byte *)(param_1 + 0x36b58) & 1) != 0)) {
        Message::close((Message *)(param_1 + 0x3131c));
      }
    }
    else {
      *(undefined4 *)(param_1 + 0x380c8) = *(undefined4 *)(&UNK_15024a24 + uVar5 * 0x18);
      *(undefined4 *)(param_1 + 0x380cc) = 0x400;
      *(undefined1 *)(param_1 + 0x380f4) = 1;
      *(undefined4 *)(param_1 + 0x380fc) = 0xffffffff;
      *(undefined4 *)(param_1 + 0x38100) = 0xffffffff;
      Message::play((Message *)(param_1 + 0x3131c),(PlayParam *)(param_1 + 0x380c8));
      *(uint *)(param_1 + 0x37eec) = *(uint *)(param_1 + 0x37eec) | 0x10;
    }
    FUN_15010ac4(param_1,uVar1);
    iVar2 = msys::MListWndPBase::getCurItem();
    msys::MMsg::playStr((MMsg *)(param_1 + 0x767c),*(wchar_t **)(iVar2 + 0x10),(InsParam *)0x0,false
                       );
    iVar2 = msys::MListWndPBase::getListWnd(this);
    *(undefined1 *)(param_1 + 0x871) = *(undefined1 *)(iVar2 + 0x149);
  }
  return;
}


// FUNC 0x1501cf00 FUN_1501cf00 (MainMenu)
//   size 0x5f0 | file MainMenu+0x1cf00 | callers(0) | datarefs 2

void FUN_1501cf00(int param_1,uint *param_2)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  MListWndPBase *this;
  MDfxChr *this_00;
  uint uVar5;
  uint uVar6;
  LytAnim *pLVar7;
  undefined4 uVar8;
  undefined8 uVar9;
  float fVar10;
  float fVar11;
  
  iVar3 = nn::snd::CTR::OutputCapture::Read
                    ((OutputCapture *)&main_menu::BootInfo::output_capture,
                     (short *)(param_1 + 0x3f72c),0x280);
  if (iVar3 != 0) {
    uVar9 = FUN_150179bc(param_1 + 0x3f724,param_1 + 0x3f72c);
    fVar11 = (float)((ulonglong)uVar9 >> 0x20);
    *(undefined8 *)(param_1 + 0x4012c) = uVar9;
    if (*(float *)(param_1 + 0x40134) < (float)uVar9) {
      *(float *)(param_1 + 0x40134) = (float)uVar9;
    }
    if (*(float *)(param_1 + 0x40138) < fVar11) {
      *(float *)(param_1 + 0x40138) = fVar11;
    }
  }
  iVar3 = *(int *)(param_1 + 0x421f0);
  if (*(char *)(param_1 + 0x519ad) == -1) {
    *(undefined4 *)(iVar3 + 0x28) = 0;
    *(undefined4 *)(iVar3 + 0x2c) = 0;
    *(undefined4 *)(iVar3 + 0x30) = 0x41800000;
    *(byte *)(iVar3 + 0x44) = *(byte *)(iVar3 + 0x44) & 0xef | 0x10;
    iVar3 = *(int *)(param_1 + 0x421f4);
    *(undefined4 *)(iVar3 + 0x28) = 0;
    *(undefined4 *)(iVar3 + 0x2c) = 0;
    *(undefined4 *)(iVar3 + 0x30) = 0x41800000;
    *(byte *)(iVar3 + 0x44) = *(byte *)(iVar3 + 0x44) & 0xef | 0x10;
    iVar3 = *(int *)(param_1 + 0x421f8);
    if (((nn::math::VEC2::One()::one & 1) == 0) &&
       (iVar4 = __cxa_guard_acquire(&nn::math::VEC2::One()::one), iVar4 != 0)) {
      nn::math::VEC2::One()::one = 1.0;
      DAT_003f7ed8 = 1.0;
      __cxa_guard_release(&nn::math::VEC2::One()::one);
    }
    fVar11 = DAT_003f7ed8;
    *(float *)(iVar3 + 0x34) = nn::math::VEC2::One()::one;
    *(float *)(iVar3 + 0x38) = fVar11;
    *(byte *)(iVar3 + 0x44) = *(byte *)(iVar3 + 0x44) & 0xef | 0x10;
    iVar3 = *(int *)(param_1 + 0x421fc);
    if (((nn::math::VEC2::One()::one & 1) == 0) &&
       (iVar4 = __cxa_guard_acquire(&nn::math::VEC2::One()::one), iVar4 != 0)) {
      nn::math::VEC2::One()::one = 1.0;
      DAT_003f7ed8 = 1.0;
      __cxa_guard_release(&nn::math::VEC2::One()::one);
    }
    fVar11 = DAT_003f7ed8;
    *(float *)(iVar3 + 0x34) = nn::math::VEC2::One()::one;
    *(float *)(iVar3 + 0x38) = fVar11;
    *(byte *)(iVar3 + 0x44) = *(byte *)(iVar3 + 0x44) & 0xef | 0x10;
  }
  else {
    fVar11 = *(float *)(param_1 + 0x4012c);
    *(undefined4 *)(iVar3 + 0x28) = 0;
    *(undefined4 *)(iVar3 + 0x2c) = 0;
    *(float *)(iVar3 + 0x30) = fVar11 * -36.0 + 16.0;
    *(byte *)(iVar3 + 0x44) = *(byte *)(iVar3 + 0x44) & 0xef | 0x10;
    fVar11 = *(float *)(param_1 + 0x40130);
    iVar3 = *(int *)(param_1 + 0x421f4);
    *(undefined4 *)(iVar3 + 0x28) = 0;
    *(undefined4 *)(iVar3 + 0x2c) = 0;
    *(float *)(iVar3 + 0x30) = fVar11 * -36.0 + 16.0;
    *(byte *)(iVar3 + 0x44) = *(byte *)(iVar3 + 0x44) & 0xef | 0x10;
    iVar3 = *(int *)(param_1 + 0x421f8);
    if (((nn::math::VEC2::One()::one & 1) == 0) &&
       (iVar4 = __cxa_guard_acquire(&nn::math::VEC2::One()::one), iVar4 != 0)) {
      nn::math::VEC2::One()::one = 1.0;
      DAT_003f7ed8 = 1.0;
      __cxa_guard_release(&nn::math::VEC2::One()::one);
    }
    fVar11 = *(float *)(param_1 + 0x4012c) * 0.03 + 1.0;
    fVar10 = DAT_003f7ed8 * fVar11;
    *(float *)(iVar3 + 0x34) = nn::math::VEC2::One()::one * fVar11;
    *(float *)(iVar3 + 0x38) = fVar10;
    *(byte *)(iVar3 + 0x44) = *(byte *)(iVar3 + 0x44) & 0xef | 0x10;
    iVar3 = *(int *)(param_1 + 0x421fc);
    if (((nn::math::VEC2::One()::one & 1) == 0) &&
       (iVar4 = __cxa_guard_acquire(&nn::math::VEC2::One()::one), iVar4 != 0)) {
      nn::math::VEC2::One()::one = 1.0;
      DAT_003f7ed8 = 1.0;
      __cxa_guard_release(&nn::math::VEC2::One()::one);
    }
    fVar10 = *(float *)(param_1 + 0x40130) * 0.03 + 1.0;
    fVar11 = DAT_003f7ed8 * fVar10;
    *(float *)(iVar3 + 0x34) = nn::math::VEC2::One()::one * fVar10;
    *(float *)(iVar3 + 0x38) = fVar11;
    *(byte *)(iVar3 + 0x44) = *(byte *)(iVar3 + 0x44) & 0xef | 0x10;
  }
  this = (MListWndPBase *)(param_1 + 0x49b08);
  cVar2 = *(char *)(param_1 + 0x873);
  iVar4 = (int)cVar2;
  iVar3 = msys::MListWndPBase::getSelectItem(this);
  if (iVar3 != 0) {
    FUN_1501580c(msys::MComSys::_sys + 0x49368,0x110016,0,0,0);
    iVar3 = msys::MListWndPBase::getListWnd(this);
    this_00 = (MDfxChr *)(param_1 + 0x40140);
    uVar5 = (uint)*(char *)(param_1 + 0x519ad);
    if (*(byte *)(iVar3 + 0x149) == uVar5) {
      uVar6 = param_1 + 0x51908;
      this[uVar5 * 0x1c + 0x6f89] = (MListWndPBase)0xff;
      if (DAT_003fbfa0 != 0) {
        uVar6 = (uint)*(byte *)(param_1 + 0x519b5);
      }
      if (DAT_003fbfa0 != 0 && uVar6 != 0) {
        SndSys::stop((SndSys *)&gSndSys,(SoundHandle *)&DAT_003fbfa0,8);
        *(ushort *)(param_1 + 0x51896) = *(ushort *)(param_1 + 0x51896) & 0xfffe;
        Frm::play((Frm *)(param_1 + 0x51888),7.0);
        *(undefined1 *)(param_1 + 0x519b5) = 0;
      }
      *(undefined1 *)(param_1 + 0x519ad) = 0xff;
      msys::MDfxChr::term(this_00);
      if (-1 < *(int *)(param_1 + 0x42200)) {
        pLVar7 = (LytAnim *)
                 msys::MLyt::getAnim((MLyt *)(param_1 + 0x110),(short)*(int *)(param_1 + 0x42200));
        ad::lyt::LytAnim::stop(pLVar7);
      }
      *(undefined4 *)(param_1 + 0x42200) = 0xffffffff;
    }
    else {
      if (uVar5 == 0xffffffff) {
        msys::MDfxChr::playDfx(this_00,0x23);
        *(undefined2 *)(*(int *)(param_1 + 0x40294) + 0xf2) = 0;
        uVar8 = msys::MLyt::createAnimeAutoSlot
                          ((MLyt *)(param_1 + 0x110),"tape_anim",(char *)0x0,(char *)0x0);
        *(undefined4 *)(param_1 + 0x42200) = uVar8;
        pLVar7 = (LytAnim *)msys::MLyt::getAnim((MLyt *)(param_1 + 0x110),(short)uVar8);
        ad::lyt::LytAnim::playAuto(pLVar7,0.1);
      }
      iVar3 = msys::MListWndPBase::getListWnd(this);
      FUN_1501153c(this,(int)*(char *)(iVar3 + 0x149));
      cVar2 = *(char *)(param_1 + 0x519b4);
      if (cVar2 == '\0') {
        *(undefined1 *)(param_1 + 0x519ac) = *(undefined1 *)(param_1 + 0x519ad);
      }
      else if (cVar2 == '\x01') {
        *(undefined1 *)(param_1 + 0x519ac) = 0;
        *(undefined1 *)(param_1 + 0x5192c) = *(undefined1 *)(param_1 + 0x519ad);
      }
      else if (cVar2 == '\x02') {
        FUN_1501163c();
      }
    }
    goto LAB_1501d45c;
  }
  iVar3 = msys::MListWndPBase::getListWnd(this);
  if (*(int *)(iVar3 + 0x1cc) != 0) goto LAB_1501d45c;
  uVar5 = *param_2;
  if ((uVar5 & 0x802) != 0) {
    (**(code **)(**(int **)(param_1 + 0x860) + 0x10))();
    iVar1 = msys::MComSys::_sys;
    iVar3 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar3 = iVar1;
    }
    *(undefined1 *)(iVar3 + 0xe6508) = 0;
    goto LAB_1501d45c;
  }
  if ((uVar5 & 0x30) == 0) goto LAB_1501d45c;
  if ((uVar5 & 0x20) == 0) {
    if ((uVar5 & 0x10) != 0) {
      cVar2 = cVar2 + '\x01';
      goto LAB_1501d444;
    }
  }
  else {
    cVar2 = cVar2 + -1;
LAB_1501d444:
    iVar4 = (int)cVar2;
  }
  if (iVar4 < 0) {
    iVar4 = 2;
  }
  else if (2 < iVar4) {
    iVar4 = 0;
  }
LAB_1501d45c:
  FUN_1501a400(this);
  if (*(char *)(param_1 + 0x873) != iVar4) {
    (**(code **)(**(int **)(param_1 + iVar4 * 4 + 0x3f718) + 0x10))();
    iVar4 = msys::MComSys::_sys;
    iVar3 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar3 = iVar4;
    }
    *(undefined1 *)(iVar3 + 0xe6508) = 0;
  }
  iVar3 = msys::MListWndPBase::isBusyAnime(this);
  if ((((iVar3 == 0) &&
       (iVar3 = msys::MListWndPBase::getListWnd(this), *(int *)(iVar3 + 0x1cc) == 0)) &&
      (iVar3 = msys::MListWndPBase::getListWnd(this), *(char *)(iVar3 + 0x144) != '\0')) &&
     (iVar3 = msys::MListWndPBase::getListWnd(this),
     (int)*(char *)(param_1 + 0x871) != (uint)*(byte *)(iVar3 + 0x149))) {
    iVar3 = msys::MListWndPBase::getListWnd(this);
    *(undefined1 *)(param_1 + 0x871) = *(undefined1 *)(iVar3 + 0x149);
  }
  return;
}


// FUNC 0x1501d53c FUN_1501d53c (MainMenu)
//   size 0x3ac | file MainMenu+0x1d53c | callers(0) | datarefs 2

void FUN_1501d53c(int param_1,uint *param_2)

{
  char cVar1;
  MListWndPBase *this;
  int iVar2;
  int iVar3;
  uint *puVar4;
  LytAnim *this_00;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  uint in_fpscr;
  float fVar8;
  
  this = (MListWndPBase *)(param_1 + 0x4220c);
  iVar2 = msys::MListWndPBase::isBusyAnime(this);
  if ((iVar2 == 0) &&
     (iVar3 = msys::MListWndPBase::getListWnd(this), iVar2 = msys::MComSys::_sys,
     *(int *)(iVar3 + 0x1cc) == 0)) {
    iVar3 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar3 = iVar2;
    }
    ad::fw::TaskBase::isFps30(*(TaskBase **)(iVar3 + 4));
    if ((*param_2 & 0x802) != 0) {
      (**(code **)(**(int **)(param_1 + 0x860) + 0x10))();
      iVar3 = msys::MComSys::_sys;
      iVar2 = *(int *)(param_1 + 8);
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar2 = iVar3;
      }
      *(undefined1 *)(iVar2 + 0xe6508) = 0;
    }
  }
  iVar2 = msys::MListWndPBase::getListWnd(this);
  if ((*(char *)(iVar2 + 0x144) != '\0') &&
     (iVar2 = msys::MListWndPBase::getListWnd(this), *(int *)(iVar2 + 0x1cc) == 0)) {
    iVar2 = msys::MListWndPBase::getListWnd(this);
    uVar7 = (uint)*(char *)(param_1 + 0x871);
    if (uVar7 != *(byte *)(iVar2 + 0x149)) {
      iVar2 = msys::MListWndPBase::getListWnd(this);
      cVar1 = *(char *)(iVar2 + 0x149);
      *(char *)(param_1 + 0x871) = cVar1;
      if (cVar1 < '\a') {
        if (6 < (int)uVar7) {
          fVar8 = (float)VectorSignedToFloat((int)*(char *)(param_1 + 0x889),
                                             (byte)(in_fpscr >> 0x16) & 3);
          ad::lyt::LytAnim::stopAndSetFrm((LytAnim *)(param_1 + 0x311b4),fVar8);
          ad::lyt::LytAnim::stopAndSetFrm((LytAnim *)(param_1 + 0x31198),0.0);
          uVar7 = 0;
          do {
            msys::MDfxChr::term((MDfxChr *)(param_1 + uVar7 * 0x17c + 0x40d20));
            uVar7 = uVar7 + 1 & 0xff;
          } while (uVar7 < 4);
          uVar7 = 0;
          do {
            iVar2 = param_1 + uVar7 * 0x17c;
            msys::MDfxChr::playDfx((MDfxChr *)(iVar2 + 0x402bc),0x29);
            iVar2 = *(int *)(iVar2 + 0x40410);
            while( true ) {
              *(undefined2 *)(iVar2 + 0xf2) = 0xffff;
              uVar7 = uVar7 + 1 & 0xff;
              if (6 < uVar7) goto LAB_1501d7b4;
              if (uVar7 < 6) break;
              msys::MDfxChr::playDfx((MDfxChr *)(param_1 + 0x40ba4),0x2b);
              iVar2 = *(int *)(param_1 + 0x40cf8);
            }
          } while( true );
        }
      }
      else if ((int)uVar7 < 7) {
        fVar8 = (float)VectorSignedToFloat((int)*(char *)(param_1 + 0x88a),
                                           (byte)(in_fpscr >> 0x16) & 3);
        ad::lyt::LytAnim::stopAndSetFrm((LytAnim *)(param_1 + 0x311b4),fVar8);
        ad::lyt::LytAnim::stopAndSetFrm((LytAnim *)(param_1 + 0x31198),1.0);
        uVar7 = 0;
        do {
          msys::MDfxChr::term((MDfxChr *)(param_1 + uVar7 * 0x17c + 0x402bc));
          uVar7 = uVar7 + 1 & 0xff;
        } while (uVar7 < 6);
        msys::MDfxChr::term((MDfxChr *)(param_1 + 0x40ba4));
        uVar7 = 0;
        do {
          iVar2 = param_1 + uVar7 * 0x17c;
          msys::MDfxChr::playDfx((MDfxChr *)(iVar2 + 0x40d20),0x2e);
          uVar7 = uVar7 + 1 & 0xff;
          *(undefined2 *)(*(int *)(iVar2 + 0x40e74) + 0xf2) = 0xffff;
        } while (uVar7 < 4);
      }
    }
  }
LAB_1501d7b4:
  puVar4 = (uint *)msys::MListWndPBase::getCurItem();
  if ((puVar4 != (uint *)0x0) && (*(uint **)(param_1 + 0x421e8) != puVar4)) {
    if (-1 < *(int *)(param_1 + 0x421ec)) {
      this_00 = (LytAnim *)
                msys::MLyt::getAnim((MLyt *)(param_1 + 0x110),
                                    (ushort)*(int *)(param_1 + 0x421ec) & 0xff);
      ad::lyt::LytAnim::stopAndSetFrm(this_00,0.0);
    }
    if ((short)puVar4[1] == -1) {
      *(undefined4 *)(param_1 + 0x421ec) = 0xffffffff;
    }
    else {
      uVar7 = *puVar4;
      uVar6 = *(uint *)(param_1 + 0x421ec);
      if ((int)uVar6 < 0) {
        if (uVar7 < 7) {
          uVar5 = msys::MLyt::createAnimeAutoSlot
                            ((MLyt *)(param_1 + 0x110),(&PTR_s_LOOP_TROPHY_ML_01_15036344)[uVar7],
                             "pnl_COLISEUM_TOROPHY",(char *)0x0);
        }
        else {
          uVar5 = msys::MLyt::createAnimeAutoSlot
                            ((MLyt *)(param_1 + 0x110),(&PTR_s_LOOP_TROPHY_ML_01_15036344)[uVar7],
                             "pnl_COLISEUM_TOROPHY",(char *)0x0);
        }
        *(undefined4 *)(param_1 + 0x421ec) = uVar5;
      }
      else if (uVar7 < 7) {
        msys::MLyt::createAnime
                  ((MLyt *)(param_1 + 0x110),uVar6 & 0xff,(&PTR_s_LOOP_TROPHY_ML_01_15036344)[uVar7]
                   ,"pnl_COLISEUM_TOROPHY",1,0xffffffff);
      }
      else {
        msys::MLyt::createAnime
                  ((MLyt *)(param_1 + 0x110),uVar6 & 0xff,(&PTR_s_LOOP_TROPHY_ML_01_15036344)[uVar7]
                   ,"pnl_COLISEUM_TOROPHY",1,0xffffffff);
      }
    }
    *(uint **)(param_1 + 0x421e8) = puVar4;
  }
  return;
}


// FUNC 0x1501d920 FUN_1501d920 (MainMenu)
//   size 0x218 | file MainMenu+0x1d920 | callers(0) | datarefs 2

void FUN_1501d920(int param_1,uint *param_2)

{
  MListWndPBase *this;
  int iVar1;
  int iVar2;
  uint *puVar3;
  LytAnim *this_00;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  
  this = (MListWndPBase *)(param_1 + 0x4220c);
  iVar1 = msys::MListWndPBase::isBusyAnime(this);
  if ((iVar1 == 0) &&
     (iVar2 = msys::MListWndPBase::getListWnd(this), iVar1 = msys::MComSys::_sys,
     *(int *)(iVar2 + 0x1cc) == 0)) {
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar1;
    }
    ad::fw::TaskBase::isFps30(*(TaskBase **)(iVar2 + 4));
    if ((*param_2 & 0x802) != 0) {
      (**(code **)(**(int **)(param_1 + 0x860) + 0x10))();
      iVar2 = msys::MComSys::_sys;
      iVar1 = *(int *)(param_1 + 8);
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar1 = iVar2;
      }
      *(undefined1 *)(iVar1 + 0xe6508) = 0;
    }
  }
  iVar1 = msys::MListWndPBase::getListWnd(this);
  if (((*(char *)(iVar1 + 0x144) != '\0') &&
      (iVar1 = msys::MListWndPBase::getListWnd(this), *(int *)(iVar1 + 0x1cc) == 0)) &&
     (iVar1 = msys::MListWndPBase::getListWnd(this),
     (int)*(char *)(param_1 + 0x871) != (uint)*(byte *)(iVar1 + 0x149))) {
    iVar1 = msys::MListWndPBase::getListWnd(this);
    *(undefined1 *)(param_1 + 0x871) = *(undefined1 *)(iVar1 + 0x149);
  }
  puVar3 = (uint *)msys::MListWndPBase::getCurItem();
  if ((puVar3 != (uint *)0x0) && (*(uint **)(param_1 + 0x421e8) != puVar3)) {
    if (-1 < *(int *)(param_1 + 0x421ec)) {
      this_00 = (LytAnim *)
                msys::MLyt::getAnim((MLyt *)(param_1 + 0x110),
                                    (ushort)*(int *)(param_1 + 0x421ec) & 0xff);
      ad::lyt::LytAnim::stopAndSetFrm(this_00,0.0);
    }
    if ((short)puVar3[1] == -1) {
      *(undefined4 *)(param_1 + 0x421ec) = 0xffffffff;
    }
    else {
      uVar4 = *puVar3;
      uVar6 = *(uint *)(param_1 + 0x421ec);
      if ((int)uVar6 < 0) {
        if (uVar4 < 6) {
          uVar5 = msys::MLyt::createAnimeAutoSlot
                            ((MLyt *)(param_1 + 0x110),(&PTR_s_LOOP_MEDAL_ML_01_15036370)[uVar4],
                             "pnl_MINIGAME_MEDAL_BRO",(char *)0x0);
        }
        else {
          uVar5 = msys::MLyt::createAnimeAutoSlot
                            ((MLyt *)(param_1 + 0x110),(&PTR_s_LOOP_MEDAL_ML_01_15036370)[uVar4],
                             "pnl_MINIGAME_MEDAL_BOKO",(char *)0x0);
        }
        *(undefined4 *)(param_1 + 0x421ec) = uVar5;
      }
      else if (uVar4 < 6) {
        msys::MLyt::createAnime
                  ((MLyt *)(param_1 + 0x110),uVar6 & 0xff,(&PTR_s_LOOP_MEDAL_ML_01_15036370)[uVar4],
                   "pnl_MINIGAME_MEDAL_BRO",1,0xffffffff);
      }
      else {
        msys::MLyt::createAnime
                  ((MLyt *)(param_1 + 0x110),uVar6 & 0xff,(&PTR_s_LOOP_MEDAL_ML_01_15036370)[uVar4],
                   "pnl_MINIGAME_MEDAL_BOKO",1,0xffffffff);
      }
    }
    *(uint **)(param_1 + 0x421e8) = puVar3;
  }
  return;
}


// FUNC 0x1501db7c FUN_1501db7c (MainMenu)
//   size 0x1bc | file MainMenu+0x1db7c | callers(0) | datarefs 2

void FUN_1501db7c(int param_1,uint *param_2)

{
  int iVar1;
  char cVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  cVar3 = *(char *)(param_1 + 0x8a4);
  iVar6 = (int)cVar3;
  cVar2 = cVar3 % '\x03';
  uVar4 = *param_2;
  cVar3 = (char)((uint)((short)cVar3 * 0x56) >> 8) - (char)((short)cVar3 * 0x56 >> 0x1f);
  if ((uVar4 & 0x20) == 0) {
    if ((uVar4 & 0x10) == 0) {
      if ((uVar4 & 0x40) == 0) {
        if ((uVar4 & 0x80) == 0) {
          iVar7 = iVar6;
          if ((uVar4 & 0x401) == 0) {
            if ((uVar4 & 0x802) == 0) goto LAB_1501dd00;
            (**(code **)(**(int **)(param_1 + 0x860) + 0x10))();
            iVar1 = msys::MComSys::_sys;
            iVar5 = *(int *)(param_1 + 8);
            if (*(int *)(param_1 + 8) == 0) {
              *(int *)(param_1 + 8) = msys::MComSys::_sys;
              iVar5 = iVar1;
            }
            *(undefined1 *)(iVar5 + 0xe6508) = 0;
            iVar5 = *(int *)(param_1 + 8);
          }
          else {
            (**(code **)(**(int **)(param_1 + iVar6 * 4 + 0x3f700) + 0x10))();
            iVar1 = msys::MComSys::_sys;
            iVar5 = *(int *)(param_1 + 8);
            if (*(int *)(param_1 + 8) == 0) {
              *(int *)(param_1 + 8) = msys::MComSys::_sys;
              iVar5 = iVar1;
            }
            *(undefined1 *)(iVar5 + 0xe6508) = 0;
            iVar5 = *(int *)(param_1 + 8);
          }
          iVar1 = msys::MComSys::_sys;
          if (iVar5 == 0) {
            *(int *)(param_1 + 8) = msys::MComSys::_sys;
            iVar5 = iVar1;
          }
          *(undefined1 *)(iVar5 + 0xe650a) = 1;
          goto LAB_1501dd00;
        }
        cVar3 = cVar3 + '\x01';
        if ('\x01' < cVar3) {
          cVar3 = '\0';
        }
      }
      else {
        cVar3 = cVar3 + -1;
        if (cVar3 < '\0') {
          cVar3 = '\x01';
        }
      }
      cVar2 = cVar3 * '\x03' + cVar2;
    }
    else {
      cVar2 = cVar2 + '\x01';
      if ('\x02' < cVar2) {
        cVar2 = '\0';
      }
      cVar2 = cVar2 + cVar3 * '\x03';
    }
    iVar7 = (int)cVar2;
  }
  else {
    cVar2 = cVar2 + -1;
    if (cVar2 < '\0') {
      cVar2 = '\x02';
    }
    iVar7 = (int)(char)(cVar2 + cVar3 * '\x03');
  }
LAB_1501dd00:
  if (iVar6 != iVar7) {
    FUN_1501580c(msys::MComSys::_sys + 0x49368,0x110015,0,0,0);
    *(char *)(param_1 + 0x8a4) = (char)iVar7;
  }
  FUN_15014e10(param_1 + 0x88c);
  return;
}


// FUNC 0x1501dd60 FUN_1501dd60 (MainMenu)
//   size 0x210 | file MainMenu+0x1dd60 | callers(0) | datarefs 1

void FUN_1501dd60(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  FUN_150144d8();
  uVar3 = *(undefined4 *)(*(int *)(param_1 + 4) + 0x18);
  if (*(int *)(param_1 + 8) == 0) {
    *(undefined4 *)(param_1 + 8) = msys::MComSys::_sys;
  }
  iVar1 = *(int *)(param_1 + 8);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 8) = msys::MComSys::_sys;
  }
  FUN_15012fe8(*(undefined4 *)(*(int *)(param_1 + 8) + 4),param_1 + 0x928,
               *(int *)(iVar1 + 0x278) + 0xa8,"m_item_all",uVar3,0x7f,0,0,0);
  uVar3 = *(undefined4 *)(*(int *)(param_1 + 4) + 0x18);
  if (*(int *)(param_1 + 8) == 0) {
    *(undefined4 *)(param_1 + 8) = msys::MComSys::_sys;
  }
  iVar1 = *(int *)(param_1 + 8);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 8) = msys::MComSys::_sys;
  }
  FUN_15012fe8(*(undefined4 *)(*(int *)(param_1 + 8) + 4),param_1 + 0x96c,
               *(int *)(iVar1 + 0x278) + 0xa8,"m_item_ev_all",uVar3,0x7f,0,0,0);
  uVar3 = *(undefined4 *)(*(int *)(param_1 + 4) + 0x18);
  if (*(int *)(param_1 + 8) == 0) {
    *(undefined4 *)(param_1 + 8) = msys::MComSys::_sys;
  }
  iVar1 = *(int *)(param_1 + 8);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 8) = msys::MComSys::_sys;
  }
  FUN_15012fe8(*(undefined4 *)(*(int *)(param_1 + 8) + 4),param_1 + 0x9b0,
               *(int *)(iVar1 + 0x278) + 0xa8,"m_item_bra",uVar3,0x7f,0,0,0);
  uVar3 = *(undefined4 *)(*(int *)(param_1 + 4) + 0x18);
  if (*(int *)(param_1 + 8) == 0) {
    *(undefined4 *)(param_1 + 8) = msys::MComSys::_sys;
  }
  iVar1 = *(int *)(param_1 + 8);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 8) = msys::MComSys::_sys;
  }
  FUN_15012fe8(*(undefined4 *)(*(int *)(param_1 + 8) + 4),param_1 + 0x9f4,
               *(int *)(iVar1 + 0x278) + 0xa8,"m_ystar",uVar3,0x7f,0,0,0);
  if (*(int *)(param_1 + 8) == 0) {
    *(undefined4 *)(param_1 + 8) = msys::MComSys::_sys;
  }
  iVar1 = *(int *)(param_1 + 8);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 8) = msys::MComSys::_sys;
  }
  ad::fw::TaskBase::readLyt
            (*(TaskBase **)(*(int *)(param_1 + 8) + 4),(Resource *)(param_1 + 0xcc),
             (FileContext *)(*(int *)(iVar1 + 0x278) + 0x150),"?MENU_RECORD",
             (MemAlcBase *)(param_1 + 0x28),0x7f,(ResCacheArg *)0x0);
  puVar2 = operator_new(4,*(MemAlcBase **)(*(int *)(param_1 + 4) + 0x18),"ParamMainRecord",0);
  if (puVar2 != (undefined4 *)0x0) {
    *puVar2 = 0x41800000;
  }
  *(undefined4 **)(param_1 + 0x868) = puVar2;
  *(undefined1 **)(param_1 + 0x10) = &LAB_1501aa30;
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}


// FUNC 0x1501dfd0 FUN_1501dfd0 (MainMenu)
//   size 0x13c | file MainMenu+0x1dfd0 | callers(1) 0x1501a650

void FUN_1501dfd0(int param_1)

{
  BootInfo *this;
  char cVar1;
  int iVar2;
  MListWndPBase *this_00;
  
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x110),9,0,(char *)0x0,(char *)0x0);
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x4b8),7,0,(char *)0x0,(char *)0x0);
  *(undefined1 *)(param_1 + 0x4234d) = 0;
  msys::MListWndPBase::setEnableInput((MListWndPBase *)(param_1 + 0x4220c),false);
  this_00 = (MListWndPBase *)(param_1 + 0x49b08);
  *(undefined1 *)(param_1 + 0x49c49) = 1;
  msys::MListWndPBase::setEnableInput(this_00,true);
  FUN_15011800(this_00);
  cVar1 = *(char *)(*(int *)(param_1 + 0x49c5c) + 0x144);
  if (cVar1 != '\0') {
    iVar2 = 0;
    do {
      cVar1 = cVar1 + -1;
      this_00[iVar2 + 0x7e24] = SUB41(iVar2,0);
      iVar2 = iVar2 + 1;
    } while (cVar1 != '\0');
  }
  cVar1 = *(char *)(param_1 + 0x519ad);
  if (cVar1 == -1) {
    cVar1 = '\0';
  }
  *(char *)(param_1 + 0x519ac) = cVar1;
  *(undefined1 *)(param_1 + 0x519b4) = 0;
  (**(code **)(**(int **)(param_1 + 0x3f718) + 0x20))();
  (**(code **)(**(int **)(param_1 + 0x3f71c) + 0x18))();
  (**(code **)(**(int **)(param_1 + 0x3f720) + 0x18))();
  this = (BootInfo *)main_menu::GetBootInfo();
  main_menu::BootInfo::saveBgm(this);
  SndSys::stopAllBgm((SndSys *)&gSndSys,(int)**(float **)(param_1 + 0x868));
  *(code **)(param_1 + 0x20) = FUN_1501c42c;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


// FUNC 0x1501e234 FUN_1501e234 (MainMenu)
//   size 0x9c | file MainMenu+0x1e234 | callers(0)

void FUN_1501e234(int param_1)

{
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x110),7,0,(char *)0x0,(char *)0x0);
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x110),8,0,"pnl_COLISEUM_TOROPHY",(char *)0x0);
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x4b8),6,0,(char *)0x0,(char *)0x0);
  *(undefined1 *)(param_1 + 0x4234d) = 1;
  msys::MListWndPBase::setEnableInput((MListWndPBase *)(param_1 + 0x4220c),true);
  *(undefined1 *)(param_1 + 0x49c49) = 0;
  msys::MListWndPBase::setEnableInput((MListWndPBase *)(param_1 + 0x4220c),false);
  *(code **)(param_1 + 0x20) = FUN_1501c528;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


// FUNC 0x1501e420 FUN_1501e420 (MainMenu)
//   size 0x408 | file MainMenu+0x1e420 | callers(1) 0x1501ec98

int FUN_1501e420(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)FUN_15014438();
  *puVar1 = &main_menu::MainMenu_RecordPage::Core::vtable;
  *(undefined1 *)((int)puVar1 + 0x871) = 0xff;
  *(undefined1 *)((int)puVar1 + 0x872) = 0xff;
  puVar1 = (undefined4 *)msys::MCursorBase::MCursorBase((MCursorBase *)(puVar1 + 0x223));
  *puVar1 = &vtable_for_N4msys7MCursorILj6EEE;
  puVar1[0xc] = 0;
  puVar1[0xd] = 0;
  puVar1[0xe] = 0;
  puVar1[0xf] = 0;
  puVar1[0x10] = 0;
  puVar1[0x11] = 0;
  puVar1[0x12] = 0;
  puVar1[0x13] = 0x3f800000;
  puVar1[0x14] = 0;
  *(undefined2 *)(puVar1 + 0x15) = 1;
  *(undefined2 *)((int)puVar1 + 0x56) = 0;
  iVar2 = ad::fw::Resource::Resource((Resource *)(puVar1 + 0x16));
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(iVar2 + 0x44,ad::fw::Resource::Resource,0x44,4);
  iVar2 = FUN_15012fa0(iVar2 + 0x110);
  iVar2 = FUN_15012fa0(iVar2 + 0x6c44);
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(iVar2 + 0x6c44,FUN_15012fa0,0x6c44,5);
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(iVar2 + 0x21d54,msys::MLytNum::MLytNum,0x230,5);
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(iVar2 + 0xaf0,msys::MLytNum::MLytNum,0x230,3);
  iVar2 = FUN_15012f30(iVar2 + 0x694);
  iVar2 = FUN_15012f30(iVar2 + 0x1c);
  iVar2 = FUN_15010740(iVar2 + 0x1c);
  *(undefined4 *)(iVar2 + 0x6ef8) = 0;
  *(undefined4 *)(iVar2 + 0x6efc) = 0x400;
  *(undefined4 *)(iVar2 + 0x6f00) = 0;
  *(undefined4 *)(iVar2 + 0x6f04) = 0;
  *(undefined4 *)(iVar2 + 0x6f08) = 0;
  *(undefined4 *)(iVar2 + 0x6f0c) = 0;
  *(undefined4 *)(iVar2 + 0x6f10) = 6;
  *(undefined4 *)(iVar2 + 0x6f14) = 0;
  *(undefined1 *)(iVar2 + 0x6f18) = 0;
  *(undefined4 *)(iVar2 + 0x6f1c) = 0;
  *(undefined4 *)(iVar2 + 0x6f20) = 0;
  *(undefined1 *)(iVar2 + 0x6f24) = 1;
  *(undefined1 *)(iVar2 + 0x6f25) = 0;
  *(undefined1 *)(iVar2 + 0x6f26) = 0;
  *(undefined4 *)(iVar2 + 0x6f28) = 0;
  *(undefined4 *)(iVar2 + 0x6f2c) = 0x110003;
  *(undefined4 *)(iVar2 + 0x6f30) = 0x110004;
  iVar2 = FUN_15010740(iVar2 + 0x6f34);
  *(undefined4 *)(iVar2 + 0x6ef8) = 0;
  *(undefined4 *)(iVar2 + 0x6efc) = 0x400;
  *(undefined4 *)(iVar2 + 0x6f00) = 0;
  *(undefined4 *)(iVar2 + 0x6f04) = 0;
  *(undefined4 *)(iVar2 + 0x6f08) = 0;
  *(undefined4 *)(iVar2 + 0x6f0c) = 0;
  *(undefined4 *)(iVar2 + 0x6f10) = 6;
  *(undefined4 *)(iVar2 + 0x6f14) = 0;
  *(undefined1 *)(iVar2 + 0x6f18) = 0;
  *(undefined4 *)(iVar2 + 0x6f1c) = 0;
  *(undefined4 *)(iVar2 + 0x6f20) = 0;
  *(undefined1 *)(iVar2 + 0x6f24) = 1;
  *(undefined1 *)(iVar2 + 0x6f25) = 0;
  *(undefined1 *)(iVar2 + 0x6f26) = 0;
  *(undefined4 *)(iVar2 + 0x6f28) = 0;
  *(undefined4 *)(iVar2 + 0x6f2c) = 0x110003;
  *(undefined4 *)(iVar2 + 0x6f30) = 0x110004;
  iVar2 = FUN_15012f6c(iVar2 + 0x6f38);
  iVar2 = msys::MDfxChr::MDfxChr((MDfxChr *)(iVar2 + 0x27c));
  iVar2 = msys::MDfxChr::MDfxChr((MDfxChr *)(iVar2 + 0x17c));
  iVar2 = FUN_15012f30(iVar2 + 0x17c);
  iVar2 = FUN_15012f30(iVar2 + 0x1c);
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(iVar2 + 0x1c,FUN_15012f30,0x1c,10);
  *(undefined1 *)(iVar2 + 0x13c) = 0;
  *(undefined4 *)(iVar2 + 0x140) = 0;
  iVar2 = msys::MDfxChr::MDfxChr((MDfxChr *)(iVar2 + 0xb58));
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(iVar2 + 0x17c,msys::MDfxChr::MDfxChr,0x17c,6);
  iVar2 = msys::MDfxChr::MDfxChr((MDfxChr *)(iVar2 + 0x8e8));
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(iVar2 + 0x17c,msys::MDfxChr::MDfxChr,0x17c,4);
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(iVar2 + 0x5f0,msys::MDfxChr::MDfxChr,0x17c,6);
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(iVar2 + 0x8e8,msys::MDfxChr::MDfxChr,0x17c,4);
  *(undefined4 *)(iVar2 + 0x608) = 0xffffffff;
  puVar1 = (undefined4 *)
           msys::MListWndPBase::MListWndPBase
                     ((MListWndPBase *)(iVar2 + 0x614),(MListWndPCore *)(iVar2 + 0x810));
  *puVar1 = &vtable_for_N4msys17MListWndPFractionILi32EEE;
  puVar1 = (undefined4 *)
           ad::ui::UIListWindowPlusLyt::UIListWindowPlusLyt((UIListWindowPlusLyt *)(puVar1 + 0x7f));
  *puVar1 = &msys::MListWndPFractionCore::vtable;
  iVar2 = msys::MListWndPFractionCore::InitParamEx::InitParamEx((InitParamEx *)(puVar1 + 0x1b61));
  *(undefined ***)(iVar2 + -0x6f80) = &main_menu::MainMenu_RecordPage::Core::MListWndRecord::vtable;
  iVar2 = ad::lyt::Layout::Layout((Layout *)(iVar2 + 0x3e4));
  iVar2 = ad::lyt::Layout::Layout((Layout *)(iVar2 + 0x3c));
  iVar2 = FUN_15012f30(iVar2 + 0x3c);
  iVar2 = FUN_15012f30(iVar2 + 0x1c);
  iVar2 = FUN_15012f30(iVar2 + 0x1c);
  iVar2 = FUN_15012f30(iVar2 + 0x1c);
  iVar2 = FUN_15012f30(iVar2 + 0x1c);
  iVar2 = ad::lyt::Layout::Layout((Layout *)(iVar2 + 0x1c));
  iVar2 = FUN_15012f30(iVar2 + 0x3c);
  iVar2 = FUN_15012f30(iVar2 + 0x1c);
  iVar2 = FUN_15012f30(iVar2 + 0x1c);
  iVar2 = CellAnime::CellAnime((CellAnime *)(iVar2 + 0x9c));
  iVar2 = CellAnime::CellAnime((CellAnime *)(iVar2 + 300));
  iVar2 = CellAnime::CellAnime((CellAnime *)(iVar2 + 300));
  puVar1 = (undefined4 *)
           msys::MListWndPBase::MListWndPBase
                     ((MListWndPBase *)(iVar2 + 300),(MListWndPCore *)(iVar2 + 0x328));
  *puVar1 = &vtable_for_N4msys9MListWndPILi128EEE;
  puVar1 = (undefined4 *)
           ad::ui::UIListWindowPlusLyt::UIListWindowPlusLyt((UIListWindowPlusLyt *)(puVar1 + 0x7f));
  *puVar1 = &msys::MListWndPCore::vtable;
  puVar1[-0x7f] = &main_menu::MainMenu_RecordPage::Core::MListWndBgm::vtable;
  puVar1[0x1ee1] = 0;
  puVar1[0x1ee2] = 0x3f800000;
  puVar1[0x1ee3] = 0;
  *(undefined2 *)(puVar1 + 0x1ee4) = 1;
  *(undefined2 *)((int)puVar1 + 0x7b92) = 0;
  iVar2 = ad::lyt::Layout::Layout((Layout *)(puVar1 + 0x1ee6));
  iVar2 = FUN_15012f30(iVar2 + 0x3c);
  iVar2 = FUN_15012f30(iVar2 + 0x1c);
  iVar2 = FUN_15012f30(iVar2 + 0x1c);
  Mem::Fill((void *)(iVar2 + -0x12210),0,0x18);
  *(code **)(iVar2 + -0x51900) = FUN_1501dd60;
  *(undefined4 *)(iVar2 + -0x518fc) = 0;
  *(undefined1 **)(iVar2 + -0x518f8) = &LAB_1501e408;
  *(undefined4 *)(iVar2 + -0x518f4) = 0;
  *(code **)(iVar2 + -0x518f0) = FUN_1501aa44;
  *(undefined4 *)(iVar2 + -0x518ec) = 0;
  return iVar2 + -0x51910;
}


// FUNC 0x1501e88c main_menu::MainMenu_RecordPage::Core::vfunc_0x4 (MainMenu)
//   size 0x10 | file MainMenu+0x1e88c | callers(0) | datarefs 1

void main_menu::MainMenu_RecordPage::Core::vfunc_0x4(void)

{
  void *pvVar1;
  
  pvVar1 = (void *)vfunc_0x0();
  operator_delete(pvVar1);
  return;
}


// FUNC 0x1501e89c main_menu::MainMenu_RecordPage::Core::vfunc_0x0 (MainMenu)
//   size 0x3ac | file MainMenu+0x1e89c | callers(1) 0x1501e88c | datarefs 1

void main_menu::MainMenu_RecordPage::Core::vfunc_0x0(undefined4 *param_1)

{
  BootInfo *pBVar1;
  int iVar2;
  void *pvVar3;
  
  *param_1 = &vtable;
  msys::MCursorBase::term((MCursorBase *)(param_1 + 0x223));
  operator_delete((void *)param_1[0x21a]);
  param_1[0x21a] = 0;
  if (*(char *)(param_1 + 0xfdc9) != '\0') {
    nn::snd::CTR::OutputCapture::Enable((OutputCapture *)&BootInfo::output_capture,false);
    nn::snd::CTR::OutputCapture::Finalize((OutputCapture *)&BootInfo::output_capture);
    pvVar3 = (void *)param_1[0xfdca];
    param_1[0xfdca] = 0;
    if (pvVar3 != (void *)0x0) {
      operator_delete(pvVar3);
    }
    *(char *)(param_1 + 0xfdc9) = '\0';
  }
  ad::fw::Resource::term((Resource *)(param_1 + 0x239));
  pBVar1 = (BootInfo *)GetBootInfo();
  BootInfo::stopRcordBgm(pBVar1);
  pBVar1 = (BootInfo *)GetBootInfo();
  BootInfo::restoreBgm(pBVar1);
  DAT_003f4053 = 0;
  nn::applet::CTR::EnableSleep(true);
  param_1[0x126c2] = &MListWndBgm::vtable;
  param_1[0x14647] = 0;
  param_1[0x14640] = 0;
  param_1[0x14639] = 0;
  iVar2 = ad::lyt::Layout::~Layout((Layout *)(param_1 + 0x14627));
  *(undefined4 *)(iVar2 + -0xc) = 0;
  *(undefined ***)(iVar2 + -0x7d94) = &vtable_for_N4msys9MListWndPILi128EEE;
  iVar2 = ad::ui::UIListWindowPlusLyt::~UIListWindowPlusLyt
                    ((UIListWindowPlusLyt *)(iVar2 + -0x7b98));
  iVar2 = msys::MListWndPBase::~MListWndPBase((MListWndPBase *)(iVar2 + -0x1fc));
  iVar2 = MListWndRecord::vfunc_0x0(iVar2 + -0x78fc);
  __aeabi_vec_dtor(iVar2 + -0x614,msys::MDfxChr::~MDfxChr,0x17c,4);
  __aeabi_vec_dtor(iVar2 + -0xefc,msys::MDfxChr::~MDfxChr,0x17c,6);
  __aeabi_vec_dtor(iVar2 + -0x14ec,msys::MDfxChr::~MDfxChr,0x17c,4);
  iVar2 = msys::MDfxChr::~MDfxChr((MDfxChr *)(iVar2 + -0x1668));
  __aeabi_vec_dtor(iVar2 + -0x8e8,msys::MDfxChr::~MDfxChr,0x17c,6);
  iVar2 = msys::MDfxChr::~MDfxChr((MDfxChr *)(iVar2 + -0xa64));
  if (*(char *)(iVar2 + -0xa1c) != '\0') {
    nn::snd::CTR::OutputCapture::Enable((OutputCapture *)&BootInfo::output_capture,false);
    nn::snd::CTR::OutputCapture::Finalize((OutputCapture *)&BootInfo::output_capture);
    pvVar3 = *(void **)(iVar2 + -0xa18);
    *(undefined4 *)(iVar2 + -0xa18) = 0;
    if (pvVar3 != (void *)0x0) {
      operator_delete(pvVar3);
    }
    *(undefined1 *)(iVar2 + -0xa1c) = 0;
  }
  if (*(void **)(iVar2 + -0xa18) != (void *)0x0) {
    operator_delete(*(void **)(iVar2 + -0xa18));
  }
  __aeabi_vec_dtor(iVar2 + -0xb58,&LAB_15000d18,0x1c,10);
  *(undefined4 *)(iVar2 + -0xb68) = 0;
  *(undefined4 *)(iVar2 + -0xb84) = 0;
  iVar2 = msys::MDfxChr::~MDfxChr((MDfxChr *)(iVar2 + -0xd0c));
  iVar2 = msys::MDfxChr::~MDfxChr((MDfxChr *)(iVar2 + -0x17c));
  *(undefined ***)(iVar2 + -0x27c) = &msys::MCellAnime::vtable;
  iVar2 = CellAnime::~CellAnime((CellAnime *)(iVar2 + -0x130));
  iVar2 = msys::MChrBase::vfunc_0x0(iVar2 + -0x14c);
  *(undefined ***)(iVar2 + -0x6f38) = &msys::MMsgWnd::vtable;
  Message::term((Message *)(iVar2 + -0x6dec));
  iVar2 = Message::~Message((Message *)(iVar2 + -0x6dec));
  iVar2 = msys::MChrBase::vfunc_0x0(iVar2 + -0x14c);
  *(undefined ***)(iVar2 + -0x6f34) = &msys::MMsgWnd::vtable;
  Message::term((Message *)(iVar2 + -0x6de8));
  iVar2 = Message::~Message((Message *)(iVar2 + -0x6de8));
  iVar2 = msys::MChrBase::vfunc_0x0(iVar2 + -0x14c);
  *(undefined4 *)(iVar2 + -0x10) = 0;
  *(undefined4 *)(iVar2 + -0x2c) = 0;
  __aeabi_vec_dtor(iVar2 + -0x6cc,msys::MLytNum::~MLytNum,0x230,3);
  __aeabi_vec_dtor(iVar2 + -0x11bc,msys::MLytNum::~MLytNum,0x230,5);
  __aeabi_vec_dtor(iVar2 + -0x22f10,FUN_150010d0,0x6c44,5);
  *(undefined ***)(iVar2 + -0x29b54) = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar2 = MessageSimple::~MessageSimple((MessageSimple *)(iVar2 + -0x29a08));
  iVar2 = msys::MChrBase::vfunc_0x0(iVar2 + -0x14c);
  *(undefined ***)(iVar2 + -0x6c44) = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar2 = MessageSimple::~MessageSimple((MessageSimple *)(iVar2 + -0x6af8));
  iVar2 = msys::MChrBase::vfunc_0x0(iVar2 + -0x14c);
  __aeabi_vec_dtor(iVar2 + -0x110,ad::fw::Resource::~Resource,0x44,4);
  iVar2 = ad::fw::Resource::~Resource((Resource *)(iVar2 + -0x154));
  *(undefined4 *)(iVar2 + -8) = 0;
  iVar2 = msys::MCursorBase::~MCursorBase((MCursorBase *)(iVar2 + -0x58));
  MainMenuPageBase::Core::vfunc_0x0(iVar2 + -0x88c);
  return;
}


// FUNC 0x1501ec98 main_menu::MainMenu_RecordPage::vfunc_0x30 (MainMenu)
//   size 0x30 | file MainMenu+0x1ec98 | callers(0) | datarefs 1

void main_menu::MainMenu_RecordPage::vfunc_0x30(int param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(0x519b8,*(MemAlcBase **)(param_1 + 0x18),(char *)0x0,0x1f);
  uVar2 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_1501e420(pvVar1,param_1);
  }
  *(undefined4 *)(param_1 + 0x20) = uVar2;
  return;
}


// FUNC 0x1501eccc main_menu::MainMenu_RecordPage::vfunc_0x24 (MainMenu)
//   size 0x8 | file MainMenu+0x1eccc | callers(0) | datarefs 1

undefined4 main_menu::MainMenu_RecordPage::vfunc_0x24(void)

{
  return 4;
}


// FUNC 0x1501ecd4 main_menu::MainMenu_RecordPage::vfunc_0x4 (MainMenu)
//   size 0x10 | file MainMenu+0x1ecd4 | callers(0) | datarefs 1

void main_menu::MainMenu_RecordPage::vfunc_0x4(void)

{
  void *pvVar1;
  
  pvVar1 = (void *)MainMenuPageBase::vfunc_0x0();
  operator_delete(pvVar1);
  return;
}


// FUNC 0x1501ece4 ->main_menu::MainMenuPageBase::vfunc_0x0 (MainMenu)
//   size 0x4 | file MainMenu+0x1ece4 | callers(0) | datarefs 1
// veneer/thunk -> 0x15015174 main_menu::MainMenuPageBase::vfunc_0x0 (MainMenu)

// FUNC 0x1501ece8 FUN_1501ece8 (MainMenu)
//   size 0x79c | file MainMenu+0x1ece8 | callers(1) 0x1501f7f8

void FUN_1501ece8(void *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined4 uVar6;
  int iVar7;
  AnimButton *this;
  uint uVar8;
  void *pvVar9;
  MLyt *pMVar10;
  int *piVar11;
  char cVar12;
  int iVar13;
  uint uVar14;
  Layout *pLVar15;
  undefined4 *puVar16;
  uint in_fpscr;
  float fVar17;
  float fVar18;
  LytLocalize aLStack_70 [16];
  undefined4 local_60;
  LytAnim local_50 [4];
  undefined *local_4c;
  undefined4 uStack_48;
  undefined4 local_44;
  undefined2 local_40;
  undefined2 local_3e;
  undefined4 local_3c;
  undefined4 local_38;
  
  if (*(int *)((int)param_1 + 8) == 0) {
    *(int *)((int)param_1 + 8) = msys::MComSys::_sys;
  }
  iVar13 = *(int *)((int)param_1 + 8);
  ad::lyt::LytResourceMan::init((LytResourceMan *)((int)param_1 + 0x58));
  pvVar9 = (void *)ad::fw::Resource::getFileData((Resource *)((int)param_1 + 0xcc));
  ad::lyt::LytResourceMan::registerArc((LytResourceMan *)((int)param_1 + 0x58),pvVar9,".");
  msys::MLyt::build((MLyt *)((int)param_1 + 0x110),
                    *(MemAlcBase **)(*(int *)((int)param_1 + 4) + 0x18),(AnimeName *)&DAT_15024c40,2
                   );
  iVar13 = iVar13 + 0xd3000;
  msys::MLyt::init((MLyt *)((int)param_1 + 0x110),iVar13,1);
  msys::MLyt::createLyt
            ((MLyt *)((int)param_1 + 0x110),(LytResourceMan *)((int)param_1 + 0x58),
             "MENU_STATUS_U.bflyt");
  MoveVBase::stop((MoveVBase *)((int)param_1 + 0x1dc));
  *(undefined4 *)((int)param_1 + 0x1f8) = 0;
  *(undefined4 *)((int)param_1 + 0x1fc) = 0;
  *(undefined4 *)((int)param_1 + 0x200) = 0xc3480000;
  *(undefined4 *)((int)param_1 + 0x1e0) = *(undefined4 *)((int)param_1 + 0x1f8);
  *(undefined4 *)((int)param_1 + 0x1e4) = 0;
  *(undefined4 *)((int)param_1 + 0x1e8) = 0xc3480000;
  *(undefined4 *)((int)param_1 + 0x24c) = 0x400;
  pMVar10 = (MLyt *)((int)param_1 + 0x4b8);
  msys::MLyt::build(pMVar10,*(MemAlcBase **)(*(int *)((int)param_1 + 4) + 0x18),
                    (AnimeName *)&PTR_s_FADE_OUT_15024c50,3);
  msys::MLyt::init(pMVar10,iVar13,1);
  msys::MLyt::createLyt
            (pMVar10,(LytResourceMan *)((int)param_1 + 0x58),"MENU_STATUS_L.bflyt",
             (ButtonGroup *)((int)param_1 + 0x3c),(MCursorBase *)((int)param_1 + 0x2c988));
  MoveVBase::stop((MoveVBase *)((int)param_1 + 0x584));
  *(undefined4 *)((int)param_1 + 0x5a0) = 0;
  *(undefined4 *)((int)param_1 + 0x5a4) = 0;
  *(undefined4 *)((int)param_1 + 0x5a8) = 0xc3480000;
  *(undefined4 *)((int)param_1 + 0x588) = *(undefined4 *)((int)param_1 + 0x5a0);
  *(undefined4 *)((int)param_1 + 0x58c) = 0;
  *(undefined4 *)((int)param_1 + 0x590) = 0xc3480000;
  *(undefined4 *)((int)param_1 + 0x5f4) = 0x401;
  FUN_1501f9ac((int)param_1 + 0x9f3c,param_1);
  MoveVBase::stop((MoveVBase *)((int)param_1 + 0xa008));
  *(undefined4 *)((int)param_1 + 0xa024) = 0;
  *(undefined4 *)((int)param_1 + 41000) = 0;
  *(undefined4 *)((int)param_1 + 0xa02c) = 0xc3480000;
  *(undefined4 *)((int)param_1 + 0xa00c) = *(undefined4 *)((int)param_1 + 0xa024);
  *(undefined4 *)((int)param_1 + 0xa010) = 0;
  *(undefined4 *)((int)param_1 + 0xa014) = 0xc3480000;
  *(undefined **)((int)param_1 + 0x10) = &DAT_1501f97c;
  *(undefined4 *)((int)param_1 + 0x14) = 0;
  if (*(char *)((int)param_1 + 0x838) == '\0') {
    return;
  }
  ad::lyt::LytLocalize::LytLocalize(aLStack_70);
  ad::lyt::LytLocalize::localize(aLStack_70,*(Layout **)((int)param_1 + 0x260));
  ad::lyt::LytLocalize::localize(aLStack_70,*(Layout **)((int)param_1 + 0x608));
  local_60 = 0;
  puVar16 = *(undefined4 **)((int)param_1 + 0x118);
  iVar13 = *(int *)((int)param_1 + 4);
  *(undefined4 **)(*(int *)((int)param_1 + 0x114) + 4) = puVar16;
  piVar5 = (int *)(iVar13 + 4);
  *puVar16 = *(undefined4 *)((int)param_1 + 0x114);
  piVar11 = (int *)((int)param_1 + 0x114);
  if (piVar11 != (int *)0x0) {
    iVar13 = *piVar5;
    *(int **)((int)param_1 + 0x118) = piVar5;
    *piVar11 = iVar13;
    *(int **)(iVar13 + 4) = piVar11;
    *piVar5 = (int)piVar11;
  }
  *(undefined4 *)((int)param_1 + 0x24c) = 0x400;
  *(undefined1 *)((int)param_1 + 0x251) = 0;
  pMVar10 = (MLyt *)((int)param_1 + 0x4b8);
  piVar11 = (int *)(*(int *)((int)param_1 + 4) + 0xc);
  puVar16 = *(undefined4 **)((int)param_1 + 0x4c0);
  *(undefined4 **)(*(int *)((int)param_1 + 0x4bc) + 4) = puVar16;
  *puVar16 = *(undefined4 *)((int)param_1 + 0x4bc);
  piVar5 = (int *)((int)param_1 + 0x4bc);
  if (piVar5 != (int *)0x0) {
    iVar13 = *piVar11;
    *(int **)((int)param_1 + 0x4c0) = piVar11;
    *piVar5 = iVar13;
    *(int **)(iVar13 + 4) = piVar5;
    *piVar11 = (int)piVar5;
  }
  *(undefined4 *)((int)param_1 + 0x5f4) = 0x401;
  iVar13 = 0;
  *(undefined1 *)((int)param_1 + 0x5f9) = 0;
  do {
    msys::MCellAnime::init
              ((MCellAnime *)((int)param_1 + iVar13 * 0x27c + 0x110e8),
               (Resource *)((int)param_1 + 0x110a4));
    iVar13 = iVar13 + 1;
  } while (iVar13 < 3);
  iVar13 = 0;
  fVar18 = 1.0;
  cVar12 = '\0';
  local_4c = &DAT_003fc140;
  do {
    uVar6 = *(undefined4 *)(*(int *)((int)param_1 + 4) + 0x18);
    *(undefined4 *)((int)param_1 + iVar13 * 0x6c44 + 0x1849c) = 0x401;
    *(undefined4 *)((int)param_1 + iVar13 * 0x6c44 + 0x18490) = uVar6;
    *(undefined4 *)((int)param_1 + iVar13 * 0x6c44 + 0x18494) = 0;
    *(undefined4 *)((int)param_1 + iVar13 * 0x6c44 + 0x18498) = 0;
    MessageSimple::init((MessageSimple *)((int)param_1 + iVar13 * 0x6c44 + 0x119a8));
    if (((nn::math::VEC3::One()::one & 1) == 0) &&
       (iVar7 = __cxa_guard_acquire(&nn::math::VEC3::One()::one), iVar7 != 0)) {
      nn::math::VEC3::One()::one = 0x3f800000;
      DAT_00434c40 = 0x3f800000;
      DAT_00434c44 = 0x3f800000;
      __cxa_guard_release(&nn::math::VEC3::One()::one);
    }
    MoveVBase::stop((MoveVBase *)((int)param_1 + iVar13 * 0x6c44 + 0x11870));
    uVar4 = DAT_00434c44;
    uVar3 = DAT_00434c40;
    uVar6 = nn::math::VEC3::One()::one;
    *(undefined4 *)((int)param_1 + iVar13 * 0x6c44 + 0x1188c) = nn::math::VEC3::One()::one;
    *(undefined4 *)((int)param_1 + iVar13 * 0x6c44 + 0x11890) = uVar3;
    *(undefined4 *)((int)param_1 + iVar13 * 0x6c44 + 0x11894) = uVar4;
    *(undefined4 *)((int)param_1 + iVar13 * 0x6c44 + 0x11874) = uVar6;
    *(undefined4 *)((int)param_1 + iVar13 * 0x6c44 + 0x11878) = uVar3;
    *(undefined4 *)((int)param_1 + iVar13 * 0x6c44 + 0x1187c) = uVar4;
    if ((((byte)nn::math::VEC3::Zero()::zero & 1) == 0) &&
       (iVar7 = __cxa_guard_acquire(&nn::math::VEC3::Zero()::zero), iVar7 != 0)) {
      nn::math::VEC3::Zero()::zero = 0;
      DAT_00434c4c = 0;
      DAT_00434c50 = 0;
      __cxa_guard_release(&nn::math::VEC3::Zero()::zero);
    }
    MoveVBase::stop((MoveVBase *)((int)param_1 + iVar13 * 0x6c44 + 0x118cc));
    uVar4 = DAT_00434c50;
    uVar3 = DAT_00434c4c;
    uVar6 = nn::math::VEC3::Zero()::zero;
    *(undefined4 *)((int)param_1 + iVar13 * 0x6c44 + 0x118e8) = nn::math::VEC3::Zero()::zero;
    *(undefined4 *)((int)param_1 + iVar13 * 0x6c44 + 0x118ec) = uVar3;
    *(undefined4 *)((int)param_1 + iVar13 * 0x6c44 + 0x118f0) = uVar4;
    *(undefined4 *)((int)param_1 + iVar13 * 0x6c44 + 0x118d0) = uVar6;
    *(undefined4 *)((int)param_1 + iVar13 * 0x6c44 + 0x118d4) = uVar3;
    *(undefined4 *)((int)param_1 + iVar13 * 0x6c44 + 0x118d8) = uVar4;
    if ((((byte)nn::math::VEC3::Zero()::zero & 1) == 0) &&
       (iVar7 = __cxa_guard_acquire(&nn::math::VEC3::Zero()::zero), iVar7 != 0)) {
      nn::math::VEC3::Zero()::zero = 0;
      DAT_00434c4c = 0;
      DAT_00434c50 = 0;
      __cxa_guard_release(&nn::math::VEC3::Zero()::zero);
    }
    MoveVBase::stop((MoveVBase *)((int)param_1 + iVar13 * 0x6c44 + 0x11928));
    uVar4 = DAT_00434c50;
    uVar3 = DAT_00434c4c;
    uVar6 = nn::math::VEC3::Zero()::zero;
    *(undefined4 *)((int)param_1 + iVar13 * 0x6c44 + 0x11944) = nn::math::VEC3::Zero()::zero;
    *(undefined4 *)((int)param_1 + iVar13 * 0x6c44 + 0x11948) = uVar3;
    *(undefined4 *)((int)param_1 + iVar13 * 0x6c44 + 0x1194c) = uVar4;
    *(undefined4 *)((int)param_1 + iVar13 * 0x6c44 + 0x1192c) = uVar6;
    *(undefined4 *)((int)param_1 + iVar13 * 0x6c44 + 0x11930) = uVar3;
    *(undefined4 *)((int)param_1 + iVar13 * 0x6c44 + 0x11934) = uVar4;
    *(undefined1 *)((int)param_1 + iVar13 * 0x6c44 + 0x17464) = 0;
    *(undefined1 *)((int)param_1 + iVar13 * 0x6c44 + 0x17465) = 1;
    *(undefined1 *)((int)param_1 + iVar13 * 0x6c44 + 0x18481) = 1;
    *(undefined1 *)((int)param_1 + iVar13 * 0x6c44 + 0x18480) = 4;
    *(undefined **)((int)param_1 + iVar13 * 0x6c44 + 0x171d0) = local_4c;
    MessageWriter::setFontColor
              ((MessageWriter *)((int)param_1 + iVar13 * 0x6c44 + 0x119a8),0xe6e6e6ff,true);
    msys::MLyt::attachMChr
              (pMVar10,(MChrBase *)((int)param_1 + iVar13 * 0x6c44 + 0x1185c),"list_text_top",
               (char *)(&DAT_150361dc)[iVar13],(char *)0x0,(char *)0x0);
    iVar13 = iVar13 + 1;
  } while (iVar13 < 4);
  FUN_1501f198((int)param_1 + 0x868);
  FUN_15020394();
  FUN_1500f458((int)param_1 + 0x2564,DAT_003f9610);
  msys::MLyt::attachMChr
            (pMVar10,(MChrBase *)((int)param_1 + 0x9f3c),"INS_LIST_STATUS",(char *)0x0,(char *)0x0,
             (char *)0x0);
  *(undefined1 *)((int)param_1 + 0xa07d) = 0;
  uVar14 = 0;
  do {
    this = (AnimButton *)
           ad::ctrl::ButtonGroup::FindButtonByName
                     ((ButtonGroup *)((int)param_1 + 0x3c),(char *)(&DAT_150361dc)[uVar14]);
    *(AnimButton **)((int)param_1 + uVar14 * 4 + 0x2c96c) = this;
    ad::ctrl::AnimButton::SetStateChangeCallback
              (this,(_func_void_AnimButton_ptr_State_State_void_ptr *)&DAT_15020128,param_1);
    iVar13 = *(int *)((int)param_1 + uVar14 * 4 + 0x2c96c);
    *(uint *)(iVar13 + 8) = *(uint *)(iVar13 + 8) & 0xffffffdf;
    *(uint *)(*(int *)((int)param_1 + uVar14 * 4 + 0x2c96c) + 0x48) = uVar14;
    piVar5 = *(int **)((int)param_1 + uVar14 * 4 + 0x2c96c);
    (**(code **)(*piVar5 + 0x28))(piVar5,0);
    if (uVar14 < 4) {
      iVar13 = msys::MLyt::getParts(pMVar10,(char *)(&DAT_150361dc)[uVar14],(char *)0x0,(char *)0x0)
      ;
      pLVar15 = *(Layout **)(iVar13 + 0xac);
      local_50[0] = (LytAnim)0x0;
      local_4c = (undefined *)0x0;
      uStack_48 = 0x3f800000;
      local_44 = 0;
      local_40 = 1;
      local_3e = 0;
      local_3c = 0;
      local_38 = 0;
      ad::lyt::LytAnim::init(local_50,pLVar15,"SET_COL","");
      ad::lyt::LytAnim::stopAndSetFrm(local_50,0.0);
      ad::lyt::LytAnim::term(local_50,true);
      ad::lyt::LytAnim::init(local_50,pLVar15,"SET_ICON","");
      if (uVar14 - 1 < 2) {
        uVar8 = uVar14;
      }
      else {
        uVar8 = 0;
      }
      fVar17 = (float)VectorSignedToFloat(uVar8,(byte)(in_fpscr >> 0x16) & 3);
      ad::lyt::LytAnim::stopAndSetFrm(local_50,fVar17);
      ad::lyt::LytAnim::term(local_50,true);
      if ((int)uVar14 < 3) {
        msys::MLyt::attachMChr
                  (pMVar10,(MChrBase *)((int)param_1 + uVar14 * 0x27c + 0x110e8),"INS_ICON_OBJ",
                   (char *)(&DAT_150361dc)[uVar14],(char *)0x0,(char *)0x0);
      }
      local_44 = 0;
    }
    iVar13 = msys::MComSys::_sys;
    uVar14 = uVar14 + 1;
  } while ((int)uVar14 < 7);
  iVar7 = *(int *)((int)param_1 + 8);
  if (*(int *)((int)param_1 + 8) == 0) {
    *(int *)((int)param_1 + 8) = msys::MComSys::_sys;
    iVar7 = iVar13;
  }
  iVar2 = msys::MComSys::_sys;
  iVar13 = iVar7;
  if (iVar7 == 0) {
    *(int *)((int)param_1 + 8) = msys::MComSys::_sys;
    iVar13 = iVar2;
  }
  iVar13 = ad::fw::TaskBase::isFps30(*(TaskBase **)(iVar13 + 4));
  if (iVar13 != 0) {
    fVar18 = 2.0;
  }
  msys::MCursorBase::init((MCursorBase *)((int)param_1 + 0x2c988),(MLyt *)(iVar7 + 0xe9a9c),fVar18);
  iVar13 = 4;
  puVar16 = (undefined4 *)((int)param_1 + 0x2c9b8);
  do {
    iVar13 = iVar13 + -1;
    *puVar16 = 0;
    puVar16 = puVar16 + 1;
  } while (iVar13 != 0);
  uVar14 = 0;
  if (*(int *)((int)param_1 + 0x2c9b8) != 0) {
    if (*(int *)((int)param_1 + 0x2c9bc) == 0) {
      cVar12 = '\x01';
    }
    else if (*(int *)((int)param_1 + 0x2c9c0) == 0) {
      cVar12 = '\x02';
    }
    else if (*(int *)((int)param_1 + 0x2c9c4) == 0) {
      cVar12 = '\x03';
    }
    else {
      cVar12 = -1;
    }
  }
  do {
    cVar1 = (char)uVar14;
    uVar6 = msys::MLyt::getParts(pMVar10,(char *)(&DAT_150361dc)[uVar14],(char *)0x0,(char *)0x0);
    uVar14 = uVar14 + 1;
    *(undefined4 *)((int)param_1 + (char)(cVar12 + cVar1) * 4 + 0x2c9b8) = uVar6;
  } while (uVar14 < 4);
  *(undefined1 *)((int)param_1 + 0x2c9a0) = 0;
  msys::MCursorBase::setVisible((MCursorBase *)((int)param_1 + 0x2c988),false);
  FUN_1500f5d8(param_1);
  FUN_1500fc2c(param_1,0);
  *(undefined1 *)(*(int *)((int)param_1 + 4) + 0x14) = 1;
  *(undefined **)((int)param_1 + 0x10) = &DAT_15020390;
  *(undefined4 *)((int)param_1 + 0x14) = 0;
  return;
}


// FUNC 0x1501f0e4 FUN_1501f0e4 (MainMenu)
//   size 0x9c | file MainMenu+0x1f0e4 | callers(0) | datarefs 1

void FUN_1501f0e4(int param_1)

{
  int iVar1;
  int iVar2;
  MemAlcBase *pMVar3;
  
  iVar1 = msys::MComSys::_sys;
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  else {
    iVar1 = *(int *)(param_1 + 8);
  }
  iVar2 = ad::fw::TaskBase::isReadable(*(TaskBase **)(iVar1 + 4));
  iVar1 = msys::MComSys::_sys;
  if (iVar2 != 0) {
    pMVar3 = *(MemAlcBase **)(*(int *)(param_1 + 4) + 0x18);
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar1;
    }
    iVar1 = msys::MComSys::_sys;
    if (iVar2 == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
    }
    else {
      iVar1 = iVar2;
    }
    ad::fw::TaskBase::readLyt
              (*(TaskBase **)(iVar1 + 4),(Resource *)(param_1 + 0xcc),
               (FileContext *)(*(int *)(iVar2 + 0x278) + 0x150),"?MENU_STATUS",pMVar3,0x7f,
               (ResCacheArg *)0x0);
    *(undefined1 **)(param_1 + 0x10) = &LAB_1501f7ec;
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  return;
}


// FUNC 0x1501f198 FUN_1501f198 (MainMenu)
//   size 0x44c | file MainMenu+0x1f198 | callers(1) 0x1501ece8

void FUN_1501f198(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  Layout *pLVar4;
  LytAnim aLStackY_100 [128];
  undefined2 local_70;
  undefined2 local_6e;
  undefined4 local_6c;
  undefined4 local_68;
  
  iVar3 = 0;
  do {
    iVar1 = msys::MLyt::getParts
                      ((MLyt *)(*param_1 + 0x110),(char *)(&DAT_15036118)[iVar3],(char *)0x0,
                       (char *)0x0);
    pLVar4 = *(Layout **)(iVar1 + 0xac);
    ad::lyt::LytAnim::init
              ((LytAnim *)(param_1 + iVar3 * 7 + 0x730),pLVar4,(char *)(&DAT_15036120)[iVar3],"");
    ad::lyt::LytAnim::stopAndSetFrm((LytAnim *)(param_1 + iVar3 * 7 + 0x730),0.0);
    ad::lyt::LytAnim::term((LytAnim *)(param_1 + iVar3 * 7 + 0x730),true);
    ad::lyt::LytAnim::init((LytAnim *)(param_1 + iVar3 * 7 + 0x730),pLVar4,"SET_VISIBLE","");
    ad::lyt::LytAnim::stopAndSetFrm((LytAnim *)(param_1 + iVar3 * 7 + 0x730),0.0);
    ad::lyt::LytAnim::term((LytAnim *)(param_1 + iVar3 * 7 + 0x730),true);
    ad::lyt::LytAnim::init((LytAnim *)(param_1 + iVar3 * 7 + 0x730),pLVar4,"OnOff","");
    ad::lyt::LytAnim::stopAndSetFrm((LytAnim *)(param_1 + iVar3 * 7 + 0x730),0.0);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 2);
  ad::lyt::LytNumReel3::InitParam::InitParam((InitParam *)&local_70);
  iVar1 = msys::MComSys::_sys;
  iVar3 = *(int *)(*param_1 + 8);
  if (iVar3 == 0) {
    *(int *)(*param_1 + 8) = msys::MComSys::_sys;
    iVar3 = iVar1;
  }
  msys::MLytNumRes::set((MLytNumRes *)(iVar3 + 0x844),&local_70,2,4);
  iVar3 = 0;
  do {
    iVar2 = msys::MComSys::_sys;
    iVar1 = *(int *)(*param_1 + 8);
    if (iVar1 == 0) {
      *(int *)(*param_1 + 8) = msys::MComSys::_sys;
      iVar1 = iVar2;
    }
    msys::MLytNum::init((MLytNum *)(param_1 + iVar3 * 0x8c + 1),(InitParam *)&local_70,
                        (LytDrawData *)(iVar1 + 0xd3000),(MLyt *)(*param_1 + 0x110),
                        (char *)(&DAT_15036128)[iVar3],(char *)0x0,(char *)0x0,(char *)0x0);
    msys::MLyt::attachMChr
              ((MLyt *)(*param_1 + 0x110),(MChrBase *)(param_1 + iVar3 * 0x8c + 1),
               (char *)(&DAT_15036128)[iVar3],(char *)0x0,(char *)0x0,(char *)0x0);
    iVar1 = msys::MComSys::_sys;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 2);
  iVar3 = *(int *)(*param_1 + 8);
  if (iVar3 == 0) {
    *(int *)(*param_1 + 8) = msys::MComSys::_sys;
    iVar3 = iVar1;
  }
  msys::MLytNumRes::set((MLytNumRes *)(iVar3 + 0x844),&local_70,0,0);
  iVar3 = 0;
  do {
    iVar2 = *(int *)(*param_1 + 8);
    iVar1 = iVar2;
    if (iVar2 == 0) {
      iVar1 = msys::MComSys::_sys;
    }
    if (iVar2 == 0) {
      *(int *)(*param_1 + 8) = iVar1;
    }
    msys::MLytNum::init((MLytNum *)(param_1 + iVar3 * 0x8c + 0x119),(InitParam *)&local_70,
                        (LytDrawData *)(iVar1 + 0xd3000),(MLyt *)(*param_1 + 0x110),
                        (char *)(&DAT_150363b8)[iVar3],"STATUS_SET","CHARA_PANEL",(char *)0x0);
    msys::MLyt::attachMChr
              ((MLyt *)(*param_1 + 0x110),(MChrBase *)(param_1 + iVar3 * 0x8c + 0x119),
               (char *)(&DAT_150363b8)[iVar3],"STATUS_SET","CHARA_PANEL",(char *)0x0);
    iVar1 = msys::MComSys::_sys;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 8);
  iVar3 = *(int *)(*param_1 + 8);
  if (iVar3 == 0) {
    *(int *)(*param_1 + 8) = msys::MComSys::_sys;
    iVar3 = iVar1;
  }
  msys::MLytNumRes::set((MLytNumRes *)(iVar3 + 0x844),&local_70,0,0);
  iVar3 = 0;
  do {
    iVar2 = msys::MComSys::_sys;
    iVar1 = *(int *)(*param_1 + 8);
    if (iVar1 == 0) {
      *(int *)(*param_1 + 8) = msys::MComSys::_sys;
      iVar1 = iVar2;
    }
    msys::MLytNum::init((MLytNum *)(param_1 + iVar3 * 0x8c + 0x579),(InitParam *)&local_70,
                        (LytDrawData *)(iVar1 + 0xd3000),(MLyt *)(*param_1 + 0x110),
                        (char *)(&DAT_15036130)[iVar3],"STATUS_EXPNEXT",(char *)0x0,(char *)0x0);
    msys::MLyt::attachMChr
              ((MLyt *)(*param_1 + 0x110),(MChrBase *)(param_1 + iVar3 * 0x8c + 0x579),
               (char *)(&DAT_15036130)[iVar3],"STATUS_EXPNEXT",(char *)0x0,(char *)0x0);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 2);
  local_70 = 1;
  local_6e = 0;
  local_6c = 0;
  local_68 = 0;
  iVar3 = msys::MLyt::getParts((MLyt *)(*param_1 + 0x110),"CHARA_PANEL",(char *)0x0,(char *)0x0);
  pLVar4 = *(Layout **)(iVar3 + 0xac);
  ad::lyt::LytAnim::init(aLStackY_100 + 0x80,pLVar4,"SET_SIZE","");
  ad::lyt::LytAnim::stopAndSetFrm(aLStackY_100 + 0x80,4.0);
  ad::lyt::LytAnim::term(aLStackY_100 + 0x80,true);
  ad::lyt::LytAnim::init(aLStackY_100 + 0x80,pLVar4,"VIS_MLK_OBJ","");
  ad::lyt::LytAnim::stopAndSetFrm(aLStackY_100 + 0x80,0.0);
  ad::lyt::LytAnim::term(aLStackY_100 + 0x80,true);
  ad::lyt::LytAnim::init(aLStackY_100 + 0x80,pLVar4,"LOW_HT","");
  ad::lyt::LytAnim::stopAndSetFrm(aLStackY_100 + 0x80,0.0);
  ad::lyt::LytAnim::term(aLStackY_100 + 0x80,true);
  iVar3 = ad::lyt::Layout::FindPartsPaneByName(pLVar4,"STATUS_SET");
  ad::lyt::LytAnim::init(aLStackY_100 + 0x80,*(Layout **)(iVar3 + 0xac),"SET_ALL_STATUS","");
  ad::lyt::LytAnim::stopAndSetFrm(aLStackY_100 + 0x80,0.0);
  ad::lyt::LytAnim::term(aLStackY_100 + 0x80,true);
  msys::MLyt::attachMChr
            ((MLyt *)(*param_1 + 0x110),(MChrBase *)(param_1 + 0x691),"INS_STATUS_CHARA_OBJ",
             "CHARA_PANEL",(char *)0x0,(char *)0x0);
  FUN_1500fc98(param_1);
  return;
}


// FUNC 0x1501f68c FUN_1501f68c (MainMenu)
//   size 0x14c | file MainMenu+0x1f68c | callers(0) | datarefs 2

void FUN_1501f68c(int param_1,uint *param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  char cVar5;
  bool bVar6;
  
  FUN_150121ac();
  uVar3 = *param_2;
  bVar6 = false;
  if ((uVar3 & 0x802) == 0) {
    bVar6 = (uVar3 & 0xc0) == 0;
    if (bVar6) goto LAB_1501f780;
    if ((uVar3 & 0x40) == 0) {
      cVar5 = *(char *)(param_1 + 0x2c9a0) + '\x01';
      if ((*(byte *)(*(int *)(param_1 + 0x2c978) + 8) & 0x10) == 0) {
        cVar1 = '\x02';
      }
      else {
        cVar1 = '\x03';
      }
      if (cVar1 < cVar5) {
        cVar5 = '\0';
      }
    }
    else {
      cVar5 = *(char *)(param_1 + 0x2c9a0) + -1;
      if (cVar5 < '\0') {
        if ((*(byte *)(*(int *)(param_1 + 0x2c978) + 8) & 0x10) == 0) {
          cVar5 = '\x02';
        }
        else {
          cVar5 = '\x03';
        }
      }
    }
    *(char *)(param_1 + 0x2c9a0) = cVar5;
    FUN_1500fb18(param_1);
    uVar4 = 0x110015;
  }
  else {
    if ((*(byte *)(*(int **)(param_1 + 0x2c97c) + 2) & 4) != 0) {
      (**(code **)(**(int **)(param_1 + 0x2c97c) + 0x10))();
      FUN_1500fc2c(param_1,0);
      goto LAB_1501f780;
    }
    uVar4 = 0x110018;
  }
  FUN_1501580c(msys::MComSys::_sys + 0x49368,uVar4,0,0);
LAB_1501f780:
  iVar2 = FUN_1500f9ec(param_1 + 0x868,param_2,bVar6);
  if (iVar2 == 0) {
    return;
  }
  FUN_1500f5d8(param_1);
  return;
}


// FUNC 0x1501f800 FUN_1501f800 (MainMenu)
//   size 0x30 | file MainMenu+0x1f800 | callers(0) | datarefs 2

void FUN_1501f800(int param_1)

{
  int iVar1;
  
  iVar1 = msys::MLyt::isBusyAnime((MLyt *)(param_1 + 0x110));
  if ((iVar1 == 0) && (iVar1 = msys::MLyt::isBusyAnime((MLyt *)(param_1 + 0x4b8)), iVar1 == 0)) {
    *(undefined1 *)(param_1 + 0x865) = 0;
  }
  return;
}


// FUNC 0x1501f830 FUN_1501f830 (MainMenu)
//   size 0xac | file MainMenu+0x1f830 | callers(0) | datarefs 1

void FUN_1501f830(int param_1)

{
  MLyt *this;
  
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x110),1,1,(char *)0x0,(char *)0x0);
  this = (MLyt *)(param_1 + 0x4b8);
  msys::MLyt::setAnimeInfo(this,2,0);
  msys::MLyt::createAnimeAutoSlot(this,"0_to_1",(char *)0x0,(char *)0x0);
  msys::MLyt::createAnimeAutoSlot(this,"EXP_PANEL_ON","EXP_PNL_U",(char *)0x0);
  msys::MLyt::createAnimeAutoSlot(this,"EXP_arrow_loop","EXP_PNL_U",(char *)0x0);
  *(undefined1 *)(param_1 + 0x251) = 1;
  *(undefined1 *)(param_1 + 0x5f9) = 1;
  (**(code **)(**(int **)(param_1 + 0x2c97c) + 0x28))(*(int **)(param_1 + 0x2c97c),1);
  *(code **)(param_1 + 0x20) = FUN_1501fd00;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


// FUNC 0x1501f918 main_menu::MainMenu_StatusPage::Core::vfunc_0x10 (MainMenu)
//   size 0x4 | file MainMenu+0x1f918 | callers(0) | datarefs 1

void main_menu::MainMenu_StatusPage::Core::vfunc_0x10(void)

{
  return;
}


// FUNC 0x1501f91c FUN_1501f91c (MainMenu)
//   size 0x58 | file MainMenu+0x1f91c | callers(0) | datarefs 1

void FUN_1501f91c(int param_1)

{
  MComSys *pMVar1;
  int iVar2;
  MComSys *this;
  
  iVar2 = msys::MLyt::isBusyAnime((MLyt *)(param_1 + 0x4b8));
  pMVar1 = msys::MComSys::_sys;
  if (iVar2 == 0) {
    this = *(MComSys **)(param_1 + 8);
    if (*(MComSys **)(param_1 + 8) == (MComSys *)0x0) {
      *(MComSys **)(param_1 + 8) = msys::MComSys::_sys;
      this = pMVar1;
    }
    iVar2 = msys::MComSys::getNextPage(this);
    if (*(char *)(iVar2 + 0x14) != '\0') {
      *(undefined1 **)(param_1 + 0x18) = &LAB_15020348;
      *(undefined4 *)(param_1 + 0x1c) = 0;
    }
  }
  return;
}


// FUNC 0x1501f990 main_menu::MainMenu_StatusPage::Core::RankupBonusInfo::vfunc_0x10 (MainMenu)
//   size 0x1c | file MainMenu+0x1f990 | callers(0) | datarefs 1

void main_menu::MainMenu_StatusPage::Core::RankupBonusInfo::vfunc_0x10(MListWndPBase *param_1)

{
  msys::MListWndPBase::applyAnime(param_1);
  ad::lyt::Layout::Animate((Layout *)(param_1 + 0x7028));
  return;
}


// FUNC 0x1501f9ac FUN_1501f9ac (MainMenu)
//   size 0x20c | file MainMenu+0x1f9ac | callers(1) 0x1501ece8

void FUN_1501f9ac(MListWndPBase *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  Layout *pLVar4;
  uint in_fpscr;
  float fVar5;
  LytAnim aLStackY_260 [128];
  InitParam aIStack_1c0 [24];
  int local_1a8;
  undefined4 local_194;
  undefined4 local_190;
  undefined4 local_188;
  LytAnim *local_180;
  LytAnim *local_164;
  undefined1 local_158;
  MListWndPBase *local_84;
  undefined1 local_80;
  LytLocalize aLStack_48 [16];
  undefined4 local_38;
  
  iVar1 = msys::MComSys::_sys;
  iVar2 = *(int *)(param_2 + 8);
  if (*(int *)(param_2 + 8) == 0) {
    *(int *)(param_2 + 8) = msys::MComSys::_sys;
    iVar2 = iVar1;
  }
  pLVar4 = (Layout *)(param_1 + 0x7028);
  ad::lyt::LytResourceMan::buildLayout
            ((LytResourceMan *)(param_2 + 0x58),pLVar4,"MENU_STATUS_L_LIST.bflyt",
             (ControlCreator *)0x0,(TextSearcher *)0x0);
  ad::lyt::LytLocalize::LytLocalize(aLStack_48);
  ad::lyt::LytLocalize::localize(aLStack_48,pLVar4);
  local_38 = 0;
  ad::lyt::LytAnim::init((LytAnim *)(param_1 + 0x7064),pLVar4,"SET_ICON","");
  ad::lyt::LytAnim::init((LytAnim *)(param_1 + 0x7080),pLVar4,"touch","");
  ad::ui::UIListWindowPlusLyt::InitParam::InitParam(aIStack_1c0);
  msys::SetMListWndInitParam(aIStack_1c0,2);
  local_1a8 = (**(code **)(**(int **)(param_1 + 0x7038) + 0x2c))
                        (*(int **)(param_1 + 0x7038),"ICONL",1);
  *(byte *)(local_1a8 + 0x44) = *(byte *)(local_1a8 + 0x44) & 0xfe | 1;
  local_180 = (LytAnim *)(param_1 + 0x7064);
  local_188 = (**(code **)(**(int **)(param_1 + 0x7038) + 0x2c))
                        (*(int **)(param_1 + 0x7038),"FRAME",1);
  local_190 = (**(code **)(**(int **)(param_1 + 0x7038) + 0x2c))
                        (*(int **)(param_1 + 0x7038),"list_cursor_Coliseum",1);
  local_194 = (**(code **)(**(int **)(param_1 + 0x7038) + 0x2c))
                        (*(int **)(param_1 + 0x7038),"list_scroll",1);
  local_84 = param_1 + 0x6f80;
  local_158 = 0;
  local_80 = 0;
  local_164 = (LytAnim *)(param_1 + 0x7080);
  ad::lyt::LytAnim::init(aLStackY_260 + 0x80,pLVar4,"SET_CURSOR_HIL","");
  uVar3 = ad::lyt::AnimTransform::GetFrameSize((AnimTransform *)0x0);
  fVar5 = (float)VectorUnsignedToFloat(uVar3,(byte)(in_fpscr >> 0x16) & 3);
  ad::lyt::LytAnim::stopAndSetFrm(aLStackY_260 + 0x80,fVar5);
  ad::lyt::LytAnim::term(aLStackY_260 + 0x80,true);
  msys::MListWndPBase::init
            (param_1,aIStack_1c0,(LytDrawData *)(iVar2 + 0xd3000),(Prim *)(iVar2 + 0xd3100),
             (MessageDrawer *)(iVar2 + 0x1487c),(ApplyingSceneInfo *)(iVar2 + 0x4af54));
  *(undefined4 *)(param_1 + 0x13c) = 0x401;
  return;
}


// FUNC 0x1501fc3c main_menu::MainMenu_StatusPage::Core::RankupBonusInfo::vfunc_0x4 (MainMenu)
//   size 0x58 | file MainMenu+0x1fc3c | callers(0) | datarefs 1

void main_menu::MainMenu_StatusPage::Core::RankupBonusInfo::vfunc_0x4(undefined4 *param_1)

{
  int iVar1;
  void *pvVar2;
  
  *param_1 = &vtable;
  param_1[0x1c23] = 0;
  param_1[0x1c1c] = 0;
  iVar1 = ad::lyt::Layout::~Layout((Layout *)(param_1 + 0x1c0a));
  *(undefined ***)(iVar1 + -0x7028) = &vtable_for_N4msys9MListWndPILi6EEE;
  iVar1 = ad::ui::UIListWindowPlusLyt::~UIListWindowPlusLyt
                    ((UIListWindowPlusLyt *)(iVar1 + -0x6e2c));
  pvVar2 = (void *)msys::MListWndPBase::~MListWndPBase((MListWndPBase *)(iVar1 + -0x1fc));
  operator_delete(pvVar2);
  return;
}


// FUNC 0x1501fca0 main_menu::MainMenu_StatusPage::Core::RankupBonusInfo::vfunc_0x0 (MainMenu)
//   size 0x54 | file MainMenu+0x1fca0 | callers(0) | datarefs 1

void main_menu::MainMenu_StatusPage::Core::RankupBonusInfo::vfunc_0x0(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &vtable;
  param_1[0x1c23] = 0;
  param_1[0x1c1c] = 0;
  iVar1 = ad::lyt::Layout::~Layout((Layout *)(param_1 + 0x1c0a));
  *(undefined ***)(iVar1 + -0x7028) = &vtable_for_N4msys9MListWndPILi6EEE;
  iVar1 = ad::ui::UIListWindowPlusLyt::~UIListWindowPlusLyt
                    ((UIListWindowPlusLyt *)(iVar1 + -0x6e2c));
  msys::MListWndPBase::~MListWndPBase((MListWndPBase *)(iVar1 + -0x1fc));
  return;
}


// FUNC 0x1501fd00 FUN_1501fd00 (MainMenu)
//   size 0x88 | file MainMenu+0x1fd00 | callers(0) | datarefs 6

void FUN_1501fd00(int param_1)

{
  int iVar1;
  
  iVar1 = msys::MLyt::isBusyAnime((MLyt *)(param_1 + 0x110));
  if ((iVar1 == 0) && (iVar1 = msys::MLyt::isBusyAnime((MLyt *)(param_1 + 0x4b8)), iVar1 == 0)) {
    *(undefined1 *)(param_1 + 0xa07d) = 0;
    (**(code **)(**(int **)(param_1 + 0x2c980) + 0x28))(*(int **)(param_1 + 0x2c980),0);
    msys::MCursorBase::setVisible((MCursorBase *)(param_1 + 0x2c988),true);
    FUN_150121ac((MCursorBase *)(param_1 + 0x2c988));
    FUN_1500fc2c(param_1,1);
    *(code **)(param_1 + 0x20) = FUN_1501f68c;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x1501fd94 FUN_1501fd94 (MainMenu)
//   size 0x198 | file MainMenu+0x1fd94 | callers(0) | datarefs 2

void FUN_1501fd94(int param_1,uint *param_2)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  undefined8 uVar4;
  
  iVar1 = msys::MListWndPBase::isTpNeutral((MListWndPBase *)(param_1 + 0x9f3c));
  if (iVar1 != 0) {
    uVar4 = msys::MListWndPBase::getCurItem();
    iVar2 = (int)((ulonglong)uVar4 >> 0x20);
    iVar1 = (int)uVar4;
    if (iVar1 != 0) {
      iVar2 = *(int *)(param_1 + 0x2c9c8);
    }
    bVar3 = false;
    if (iVar1 == 0 || iVar2 == iVar1) {
      bVar3 = (*param_2 & 0x802) == 0;
      if (!bVar3) {
        if ((*(byte *)(*(int **)(param_1 + 0x2c97c) + 2) & 4) == 0) {
          FUN_1501580c(msys::MComSys::_sys + 0x49368,0x110018,0,0,0);
        }
        else {
          (**(code **)(**(int **)(param_1 + 0x2c97c) + 0x10))();
          FUN_1500fc2c(param_1,0);
        }
      }
    }
    else {
      *(int *)(param_1 + 0x2c9c8) = iVar1;
      msys::MMsg::playStr((MMsg *)(param_1 + 0x2564),*(wchar_t **)(iVar1 + 0x18),(InsParam *)0x0,
                          false);
      ad::lyt::LytAnim::stopAndSetFrm((LytAnim *)(param_1 + 0x91e4),0.0);
      iVar1 = msys::MLyt::getPane((MLyt *)(*(int *)(param_1 + 0x91a8) + 0x4b8),"EXP_PNL_U",
                                  (char *)0x0,(char *)0x0);
      *(byte *)(iVar1 + 0x44) = *(byte *)(iVar1 + 0x44) & 0xfe | 1;
    }
    iVar1 = FUN_1500f9ec(param_1 + 0x868,param_2,bVar3);
    if (iVar1 != 0) {
      iVar1 = FUN_1500f2c8((MListWndPBase *)(param_1 + 0x9f3c),param_1);
      if (iVar1 == 0) {
        msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x4b8),2,0,(char *)0x0,(char *)0x0);
        FUN_1500f5d8(param_1);
        FUN_1500fc2c(param_1,0);
        *(code **)(param_1 + 0x20) = FUN_1501fd00;
        *(undefined4 *)(param_1 + 0x24) = 0;
      }
      *(undefined4 *)(param_1 + 0x2c9c8) = 0;
    }
  }
  return;
}


// FUNC 0x1501ff48 FUN_1501ff48 (MainMenu)
//   size 0xc0 | file MainMenu+0x1ff48 | callers(0) | datarefs 2

void FUN_1501ff48(int param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar1 = msys::MLyt::isBusyAnime((MLyt *)(param_1 + 0x110));
  if (iVar1 == 0) {
    iVar1 = msys::MLyt::isBusyAnime((MLyt *)(param_1 + 0x4b8));
    if (iVar1 == 0) {
      iVar1 = msys::MLyt::getParts((MLyt *)(param_1 + 0x4b8),DAT_150361f4,(char *)0x0,(char *)0x0);
      iVar4 = 0;
      *(byte *)(iVar1 + 0x44) = *(byte *)(iVar1 + 0x44) & 0xfe;
      do {
        uVar3 = 0;
        while( true ) {
          piVar2 = *(int **)(param_1 + iVar4 * 4 + 0x2c96c);
          (**(code **)(*piVar2 + 0x28))(piVar2,uVar3);
          iVar4 = iVar4 + 1;
          if (6 < iVar4) {
            *(undefined4 *)(param_1 + 0x2c9c8) = 0;
            FUN_1500fc2c(param_1,1);
            *(code **)(param_1 + 0x20) = FUN_1501fd94;
            *(undefined4 *)(param_1 + 0x24) = 0;
            return;
          }
          if (iVar4 != 5 && iVar4 != 4) break;
          uVar3 = 1;
        }
      } while( true );
    }
  }
  return;
}


// FUNC 0x15020014 main_menu::MainMenu_StatusPage::Core::vfunc_0x8 (MainMenu)
//   size 0x110 | file MainMenu+0x20014 | callers(0) | datarefs 1

int main_menu::MainMenu_StatusPage::Core::vfunc_0x8(int *param_1,MInput *param_2)

{
  MInput MVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  code *extraout_r2;
  code *pcVar6;
  VEC2 *pVVar7;
  bool bVar8;
  uint in_fpscr;
  undefined4 local_28;
  undefined4 local_24;
  
  msys::MPageBase::updateInputAllChr((MPageBase *)param_1[1],param_2);
  bVar8 = (param_1[9] & 1U) == 0;
  pcVar6 = extraout_r2;
  if (bVar8) {
    pcVar6 = (code *)param_1[8];
  }
  piVar2 = (int *)((int)param_1 + (param_1[9] >> 1));
  if (!bVar8) {
    pcVar6 = *(code **)(*piVar2 + param_1[8]);
  }
  (*pcVar6)(piVar2,param_2);
  iVar3 = msys::MListWndPBase::isTpNeutral((MListWndPBase *)(param_1 + 0x27cf));
  iVar4 = msys::MListWndPBase::isEnableInput((MListWndPBase *)(param_1 + 0x27cf));
  MVar1 = param_2[0x11];
  if (iVar4 == 0) {
    iVar3 = 1;
  }
  bVar8 = MVar1 == (MInput)0x0;
  if (bVar8) {
    MVar1 = param_2[0x12];
  }
  pVVar7 = (VEC2 *)0x0;
  if ((!bVar8 || MVar1 != (MInput)0x0) && iVar3 != 0) {
    local_28 = VectorSignedToFloat(*(ushort *)(param_2 + 0x14) - 0xa0,(byte)(in_fpscr >> 0x16) & 3);
    local_24 = VectorSignedToFloat(0x78 - (uint)*(ushort *)(param_2 + 0x16),
                                   (byte)(in_fpscr >> 0x16) & 3);
    pVVar7 = (VEC2 *)&local_28;
  }
  bVar8 = (bool)(**(code **)(*param_1 + 0xc))(param_1,param_2);
  iVar4 = msys::MComSys::_sys;
  iVar5 = param_1[2];
  if (param_1[2] == 0) {
    param_1[2] = msys::MComSys::_sys;
    iVar5 = iVar4;
  }
  ad::ctrl::ButtonGroup::Update
            ((ButtonGroup *)(param_1 + 0xf),pVVar7,
             (bool)(*(byte *)(iVar5 + 0xe6508) & bVar8 & (byte)iVar3),bVar8);
  return (int)*(char *)((int)param_1 + 0x865);
}


// FUNC 0x15020134 FUN_15020134 (MainMenu)
//   size 0x1c4 | file MainMenu+0x20134 | callers(0)

void FUN_15020134(int param_1,int param_2,int param_3,undefined4 param_4)

{
  byte bVar1;
  uint uVar2;
  code *pcVar3;
  undefined4 uVar4;
  MLyt *this;
  
  bVar1 = *(byte *)(param_2 + 0x48);
  uVar2 = (uint)bVar1;
  if (param_3 != 1) {
    if (param_3 != 4) {
      if (param_3 != 5) {
        return;
      }
      this = (MLyt *)(param_1 + 0x4b8);
      switch(uVar2) {
      case 0:
      case 1:
      case 2:
      case 3:
        FUN_1500fc2c(param_1,1,5,param_4);
        return;
      case 4:
        msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x110),1,0,(char *)0x0,(char *)0x0);
        msys::MLyt::playAnimeFromNo
                  (this,1,(uint)*(ushort *)(*(int *)(param_1 + 0x840) + 8),(char *)0x0,(char *)0x0);
        msys::MLyt::createAnimeAutoSlot(this,"EXP_PANEL_OFF","EXP_PNL_U",(char *)0x0);
        msys::MCursorBase::setVisible((MCursorBase *)(param_1 + 0x2c988),false);
        pcVar3 = FUN_1501f800;
        break;
      case 5:
        msys::MLyt::playAnimeFromNo(this,2,0,(char *)0x0,(char *)0x0);
        FUN_1500f5d8(param_1);
        FUN_1500fc2c(param_1,0);
        pcVar3 = FUN_1501fd00;
        break;
      case 6:
        msys::MLyt::playAnimeFromNo(this,2,1,(char *)0x0,(char *)0x0);
        FUN_1500f2c8(param_1 + 0x9f3c,param_1);
        *(undefined1 *)(param_1 + 0xa07d) = 1;
        msys::MCursorBase::setVisible((MCursorBase *)(param_1 + 0x2c988),false);
        *(code **)(param_1 + 0x20) = FUN_1501ff48;
        *(undefined4 *)(param_1 + 0x24) = 0;
        return;
      default:
        return;
      }
      *(code **)(param_1 + 0x20) = pcVar3;
      *(undefined4 *)(param_1 + 0x24) = 0;
      return;
    }
    if (uVar2 == 4) {
      uVar4 = 0x110017;
    }
    else {
      uVar4 = 0x110016;
    }
    FUN_1501580c(msys::MComSys::_sys + 0x49368,uVar4,0,0,0);
    FUN_1500fc2c(param_1,0);
  }
  if ((uVar2 < 4) && ((int)*(char *)(param_1 + 0x2c9a0) != uVar2)) {
    FUN_1501580c(msys::MComSys::_sys + 0x49368,0x110015,0,0);
    *(byte *)(param_1 + 0x2c9a0) = bVar1;
    FUN_1500fb18(param_1);
    return;
  }
  return;
}


// FUNC 0x15020358 FUN_15020358 (MainMenu)
//   size 0x218 | file MainMenu+0x20358 | callers(0) | datarefs 1

void FUN_15020358(int param_1)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  TaskBase *this;
  char *pcVar5;
  MemAlcBase *pMVar6;
  TransMultiSymbol aTStack_60 [48];
  uint *local_30 [2];
  MemAlcBase *local_28;
  
  FUN_150144d8();
  *(undefined4 *)(param_1 + 0x2c9c8) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0x1501eeec;
  *(undefined4 *)(param_1 + 0x14) = 0;
  iVar1 = *(int *)(param_1 + 0x2c9c8);
  while( true ) {
    iVar2 = msys::MComSys::_sys;
    if (3 < iVar1) {
      *(code **)(param_1 + 0x10) = FUN_1501f0e4;
      *(undefined4 *)(param_1 + 0x14) = 0;
      iVar1 = msys::MComSys::_sys;
      iVar2 = *(int *)(param_1 + 8);
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar2 = iVar1;
      }
      iVar2 = ad::fw::TaskBase::isReadable(*(TaskBase **)(iVar2 + 4));
      iVar1 = msys::MComSys::_sys;
      if (iVar2 != 0) {
        pMVar6 = *(MemAlcBase **)(*(int *)(param_1 + 4) + 0x18);
        iVar2 = *(int *)(param_1 + 8);
        if (*(int *)(param_1 + 8) == 0) {
          *(int *)(param_1 + 8) = msys::MComSys::_sys;
          iVar2 = iVar1;
        }
        iVar1 = msys::MComSys::_sys;
        iVar4 = iVar2;
        if (iVar2 == 0) {
          *(int *)(param_1 + 8) = msys::MComSys::_sys;
          iVar4 = iVar1;
        }
        ad::fw::TaskBase::readLyt
                  (*(TaskBase **)(iVar4 + 4),(Resource *)(param_1 + 0xcc),
                   (FileContext *)(*(int *)(iVar2 + 0x278) + 0x150),"?MENU_STATUS",pMVar6,0x7f,
                   (ResCacheArg *)0x0);
        *(undefined1 **)(param_1 + 0x10) = &LAB_1501f7ec;
        *(undefined4 *)(param_1 + 0x14) = 0;
      }
      return;
    }
    iVar1 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar1 = iVar2;
    }
    iVar2 = ad::fw::TaskBase::isReadable(*(TaskBase **)(iVar1 + 4));
    iVar1 = msys::MComSys::_sys;
    if (iVar2 == 0) break;
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar1;
    }
    iVar1 = msys::MComSys::_sys;
    if (iVar2 == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
    }
    else {
      iVar1 = iVar2;
    }
    iVar2 = *(int *)(iVar2 + 0x278);
    this = *(TaskBase **)(iVar1 + 4);
    local_28 = (MemAlcBase *)(param_1 + 0x28);
    iVar1 = *(int *)(param_1 + 0x2c9c8);
    pcVar5 = *(char **)(&DAT_150363a8 + iVar1 * 4);
    ad::TransMultiSymbol::init(aTStack_60,pcVar5);
    BinGlu4Acs::getEntryAcs((char *)local_30);
    pcVar3 = (char *)(*(int *)(iVar2 + 0xcc) + (*local_30[0] & 0x3fffffff));
    ad::fw::TaskBase::readCA
              (this,(Resource *)(param_1 + iVar1 * 0x44 + 0x10fd8),(FileContext *)(iVar2 + 0xa8),
               pcVar5,pcVar3,pcVar3 + 4,pcVar3 + 8,pcVar3 + 0xc,local_28,0x7f,(VramAlcBase *)0x0,0,
               (ResCacheArg *)0x0);
    iVar1 = *(int *)(param_1 + 0x2c9c8) + 1;
    *(int *)(param_1 + 0x2c9c8) = iVar1;
  }
  return;
}


// FUNC 0x15020394 FUN_15020394 (MainMenu)
//   size 0x278 | file MainMenu+0x20394 | callers(1) 0x1501ece8

void FUN_15020394(MChrBase *param_1)

{
  int iVar1;
  undefined4 uVar2;
  LytAnim *this;
  int iVar3;
  int iVar4;
  Layout *pLVar5;
  InitParam aIStack_70 [72];
  
  uVar2 = *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x6c44) + 4) + 0x18);
  *(undefined4 *)(param_1 + 0x6c40) = 0x401;
  *(undefined4 *)(param_1 + 0x6c34) = uVar2;
  *(undefined4 *)(param_1 + 0x6c38) = 0;
  *(undefined4 *)(param_1 + 0x6c3c) = 0;
  MessageSimple::init((MessageSimple *)(param_1 + 0x14c));
  FUN_150142ec(param_1);
  param_1[0x5c08] = (MChrBase)0x1;
  param_1[0x5c09] = (MChrBase)0x1;
  param_1[0x6c25] = (MChrBase)0x1;
  param_1[0x6c24] = (MChrBase)0x4;
  *(undefined **)(param_1 + 0x5974) = &DAT_003fc140;
  MessageWriter::setFontColor((MessageWriter *)(param_1 + 0x14c),0x373737ff,true);
  msys::MLyt::attachMChr
            ((MLyt *)(*(int *)(param_1 + 0x6c44) + 0x4b8),param_1,"INS_TOP_PANEL_TEXT","EXP_PNL_U",
             (char *)0x0,(char *)0x0);
  ad::lyt::LytNumReel3::InitParam::InitParam(aIStack_70);
  iVar4 = msys::MComSys::_sys;
  iVar3 = *(int *)(*(int *)(param_1 + 0x6c44) + 8);
  if (iVar3 == 0) {
    *(int *)(*(int *)(param_1 + 0x6c44) + 8) = msys::MComSys::_sys;
    iVar3 = iVar4;
  }
  msys::MLytNumRes::set((MLytNumRes *)(iVar3 + 0x844),aIStack_70,0,0,0xff);
  iVar3 = 0;
  do {
    iVar1 = msys::MComSys::_sys;
    iVar4 = *(int *)(*(int *)(param_1 + 0x6c44) + 8);
    if (iVar4 == 0) {
      *(int *)(*(int *)(param_1 + 0x6c44) + 8) = msys::MComSys::_sys;
      iVar4 = iVar1;
    }
    msys::MLytNum::init((MLytNum *)(param_1 + iVar3 * 0x230 + 0x6cb8),aIStack_70,
                        (LytDrawData *)(iVar4 + 0xd3000),
                        (MLyt *)(*(int *)(param_1 + 0x6c44) + 0x4b8),(char *)(&DAT_150363e4)[iVar3],
                        "PNL_STATUS_SET","EXP_PNL_U",(char *)0x0);
    msys::MLyt::attachMChr
              ((MLyt *)(*(int *)(param_1 + 0x6c44) + 0x4b8),param_1 + iVar3 * 0x230 + 0x6cb8,
               (char *)(&DAT_150363e4)[iVar3],"PNL_STATUS_SET","EXP_PNL_U",(char *)0x0);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 6);
  iVar3 = msys::MLyt::getParts
                    ((MLyt *)(*(int *)(param_1 + 0x6c44) + 0x4b8),"EXP_PNL_U",(char *)0x0,
                     (char *)0x0);
  pLVar5 = *(Layout **)(iVar3 + 0xac);
  ad::lyt::LytAnim::init((LytAnim *)(param_1 + 0x6c48),pLVar5,"SET_PANEL_STATUS","");
  ad::lyt::LytAnim::init((LytAnim *)(param_1 + 0x6c64),pLVar5,"SET_PANEL_COLOR","");
  ad::lyt::LytAnim::init((LytAnim *)(param_1 + 0x6c80),pLVar5,"SET_PANEL_PLANE","");
  iVar3 = msys::MLyt::getParts
                    ((MLyt *)(*(int *)(param_1 + 0x6c44) + 0x4b8),"PNL_STATUS_SET","EXP_PNL_U",
                     (char *)0x0);
  pLVar5 = *(Layout **)(iVar3 + 0xac);
  this = (LytAnim *)(param_1 + 0x6c9c);
  ad::lyt::LytAnim::init(this,pLVar5,"SET_vALL","");
  ad::lyt::LytAnim::stopAndSetFrm(this,0.0);
  ad::lyt::LytAnim::term(this,true);
  ad::lyt::LytAnim::init(this,pLVar5,"SET_HIGE_TSUNO","");
  ad::lyt::LytAnim::stopAndSetFrm(this,0.0);
  return;
}


// FUNC 0x150206ac main_menu::MainMenu_StatusPage::Core::ExpMsgWnd::vfunc_0x4 (MainMenu)
//   size 0x78 | file MainMenu+0x206ac | callers(0) | datarefs 1

void main_menu::MainMenu_StatusPage::Core::ExpMsgWnd::vfunc_0x4(undefined4 *param_1)

{
  int iVar1;
  void *pvVar2;
  
  *param_1 = &vtable;
  __aeabi_vec_dtor(param_1 + 0x1b2e,msys::MLytNum::~MLytNum,0x230,6);
  param_1[0x1b2a] = 0;
  __aeabi_vec_dtor(param_1 + 0x1b12,&LAB_15000d18,0x1c,3);
  *param_1 = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar1 = MessageSimple::~MessageSimple((MessageSimple *)(param_1 + 0x53));
  pvVar2 = (void *)msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  operator_delete(pvVar2);
  return;
}


// FUNC 0x15020738 main_menu::MainMenu_StatusPage::Core::ExpMsgWnd::vfunc_0x0 (MainMenu)
//   size 0x74 | file MainMenu+0x20738 | callers(0) | datarefs 1

void main_menu::MainMenu_StatusPage::Core::ExpMsgWnd::vfunc_0x0(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &vtable;
  __aeabi_vec_dtor(param_1 + 0x1b2e,msys::MLytNum::~MLytNum,0x230,6);
  param_1[0x1b2a] = 0;
  __aeabi_vec_dtor(param_1 + 0x1b12,&LAB_15000d18,0x1c,3);
  *param_1 = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar1 = MessageSimple::~MessageSimple((MessageSimple *)(param_1 + 0x53));
  msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  return;
}


// FUNC 0x150207d8 FUN_150207d8 (MainMenu)
//   size 0x1b0 | file MainMenu+0x207d8 | callers(1) 0x15020b98

void FUN_150207d8(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined1 uVar3;
  char cVar4;
  
  puVar1 = (undefined4 *)FUN_15014438();
  *puVar1 = &main_menu::MainMenu_StatusPage::Core::vtable;
  puVar1[0x21a] = puVar1;
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(puVar1 + 0x21b,msys::MLytNum::MLytNum,0x230,0xc);
  iVar2 = FUN_15012f6c(iVar2 + 0x1a40);
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(iVar2 + 0x27c,FUN_15012f30,0x1c,2);
  if ((char)DAT_003fbea4 == '\x02') {
    uVar3 = 2;
  }
  else {
    uVar3 = 0;
  }
  *(undefined1 *)(iVar2 + 0x38) = uVar3;
  cVar4 = (char)DAT_003fbea4;
  if ((char)DAT_003fbea4 != '\x02') {
    cVar4 = '\x01';
  }
  *(char *)(iVar2 + 0x39) = cVar4;
  puVar1 = (undefined4 *)FUN_15012fa0(iVar2 + 0x3c);
  *puVar1 = &main_menu::MainMenu_StatusPage::Core::ExpMsgWnd::vtable;
  puVar1[0x1b11] = iVar2 + -0x2528;
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(puVar1 + 0x1b12,FUN_15012f30,0x1c,3);
  iVar2 = FUN_15012f30(iVar2 + 0x54);
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(iVar2 + 0x1c,msys::MLytNum::MLytNum,0x230,6);
  puVar1 = (undefined4 *)
           msys::MListWndPBase::MListWndPBase
                     ((MListWndPBase *)(iVar2 + 0xd20),(MListWndPCore *)(iVar2 + 0xf1c));
  *puVar1 = &vtable_for_N4msys9MListWndPILi6EEE;
  puVar1 = (undefined4 *)
           ad::ui::UIListWindowPlusLyt::UIListWindowPlusLyt((UIListWindowPlusLyt *)(puVar1 + 0x7f));
  *puVar1 = &msys::MListWndPCore::vtable;
  puVar1[-0x7f] = &main_menu::MainMenu_StatusPage::Core::RankupBonusInfo::vtable;
  iVar2 = ad::lyt::Layout::Layout((Layout *)(puVar1 + 0x1b8b));
  iVar2 = FUN_15012f30(iVar2 + 0x3c);
  iVar2 = FUN_15012f30(iVar2 + 0x1c);
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(iVar2 + 0x1c,ad::fw::Resource::Resource,0x44,4);
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(iVar2 + 0x110,FUN_15012f6c,0x27c,3);
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(iVar2 + 0x774,FUN_15012fa0,0x6c44,4);
  puVar1 = (undefined4 *)msys::MCursorBase::MCursorBase((MCursorBase *)(iVar2 + 0x1b12c));
  puVar1[0xc] = 0;
  *puVar1 = &vtable_for_N4msys7MCursorILj4EEE;
  puVar1[0xd] = 0;
  puVar1[0xe] = 0;
  puVar1[0xf] = 0;
  puVar1[-0xb25e] = FUN_15020358;
  puVar1[-0xb25d] = 0;
  puVar1[-0xb25c] = &LAB_150207c0;
  puVar1[-0xb25b] = 0;
  puVar1[-0xb25a] = FUN_1501f830;
  puVar1[-0xb259] = 0;
  return;
}


// FUNC 0x150209c0 main_menu::MainMenu_StatusPage::Core::vfunc_0x4 (MainMenu)
//   size 0x10 | file MainMenu+0x209c0 | callers(0) | datarefs 1

void main_menu::MainMenu_StatusPage::Core::vfunc_0x4(void)

{
  void *pvVar1;
  
  pvVar1 = (void *)vfunc_0x0();
  operator_delete(pvVar1);
  return;
}


// FUNC 0x150209d0 main_menu::MainMenu_StatusPage::Core::vfunc_0x0 (MainMenu)
//   size 0x194 | file MainMenu+0x209d0 | callers(1) 0x150209c0 | datarefs 1

void main_menu::MainMenu_StatusPage::Core::vfunc_0x0(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &vtable;
  msys::MCursorBase::term((MCursorBase *)(param_1 + 0xb262));
  iVar1 = msys::MCursorBase::~MCursorBase((MCursorBase *)(param_1 + 0xb262));
  __aeabi_vec_dtor(iVar1 + -0x1b12c,FUN_150010d0,0x6c44,4);
  __aeabi_vec_dtor(iVar1 + -0x1b8a0,&LAB_15000e9c,0x27c,3);
  __aeabi_vec_dtor(iVar1 + -0x1b9b0,ad::fw::Resource::~Resource,0x44,4);
  *(undefined ***)(iVar1 + -0x22a4c) = &RankupBonusInfo::vtable;
  *(undefined4 *)(iVar1 + -0x1b9c0) = 0;
  *(undefined4 *)(iVar1 + -0x1b9dc) = 0;
  iVar1 = ad::lyt::Layout::~Layout((Layout *)(iVar1 + -0x1ba24));
  *(undefined ***)(iVar1 + -0x7028) = &vtable_for_N4msys9MListWndPILi6EEE;
  iVar1 = ad::ui::UIListWindowPlusLyt::~UIListWindowPlusLyt
                    ((UIListWindowPlusLyt *)(iVar1 + -0x6e2c));
  iVar1 = msys::MListWndPBase::~MListWndPBase((MListWndPBase *)(iVar1 + -0x1fc));
  *(undefined ***)(iVar1 + -0x79d8) = &ExpMsgWnd::vtable;
  __aeabi_vec_dtor(iVar1 + -0xd20,msys::MLytNum::~MLytNum,0x230,6);
  *(undefined4 *)(iVar1 + -0xd30) = 0;
  __aeabi_vec_dtor(iVar1 + -0xd90,&LAB_15000d18,0x1c,3);
  *(undefined ***)(iVar1 + -0x79d8) = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar1 = MessageSimple::~MessageSimple((MessageSimple *)(iVar1 + -0x788c));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  __aeabi_vec_dtor(iVar1 + -0x3c,&LAB_15000d18,0x1c,2);
  *(undefined ***)(iVar1 + -0x2b8) = &msys::MCellAnime::vtable;
  iVar1 = CellAnime::~CellAnime((CellAnime *)(iVar1 + -0x16c));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  __aeabi_vec_dtor(iVar1 + -0x1a40,msys::MLytNum::~MLytNum,0x230,0xc);
  MainMenuPageBase::Core::vfunc_0x0(iVar1 + -0x22ac);
  return;
}


// FUNC 0x15020b98 main_menu::MainMenu_StatusPage::vfunc_0x30 (MainMenu)
//   size 0x30 | file MainMenu+0x20b98 | callers(0) | datarefs 1

void main_menu::MainMenu_StatusPage::vfunc_0x30(int param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(0x2c9cc,*(MemAlcBase **)(param_1 + 0x18),(char *)0x0,0x1f);
  uVar2 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_150207d8(pvVar1,param_1);
  }
  *(undefined4 *)(param_1 + 0x20) = uVar2;
  return;
}


// FUNC 0x15020bcc main_menu::MainMenu_StatusPage::vfunc_0x24 (MainMenu)
//   size 0x8 | file MainMenu+0x20bcc | callers(0) | datarefs 1

undefined4 main_menu::MainMenu_StatusPage::vfunc_0x24(void)

{
  return 3;
}


// FUNC 0x15020bd4 main_menu::MainMenu_StatusPage::vfunc_0x4 (MainMenu)
//   size 0x10 | file MainMenu+0x20bd4 | callers(0) | datarefs 1

void main_menu::MainMenu_StatusPage::vfunc_0x4(void)

{
  void *pvVar1;
  
  pvVar1 = (void *)MainMenuPageBase::vfunc_0x0();
  operator_delete(pvVar1);
  return;
}


// FUNC 0x15020be4 ->main_menu::MainMenuPageBase::vfunc_0x0 (MainMenu)
//   size 0x4 | file MainMenu+0x20be4 | callers(0) | datarefs 1
// veneer/thunk -> 0x15015174 main_menu::MainMenuPageBase::vfunc_0x0 (MainMenu)

// FUNC 0x15020be8 FUN_15020be8 (MainMenu)
//   size 0x3ec | file MainMenu+0x20be8 | callers(1) 0x15021308

void FUN_15020be8(int param_1)

{
  void *pvVar1;
  int iVar2;
  MLyt *this;
  wchar_t *pwVar3;
  undefined4 uVar4;
  int iVar5;
  MChrBase *pMVar6;
  float fVar7;
  
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  iVar5 = *(int *)(param_1 + 8);
  ad::lyt::LytResourceMan::init((LytResourceMan *)(param_1 + 0x58));
  pvVar1 = (void *)ad::fw::Resource::getFileData((Resource *)(param_1 + 0xcc));
  ad::lyt::LytResourceMan::registerArc((LytResourceMan *)(param_1 + 0x58),pvVar1,".");
  iVar2 = ad::GetRegion();
  *(bool *)(param_1 + 0x866) = iVar2 == 0;
  *(char *)(param_1 + 0x867) = (char)((DAT_003fbea0 & 0xf) >> 3);
  fVar7 = (float)GetRegFlag(0xd033,(GlobalEvent *)0x0,(LocalEvent *)0x0);
  *(bool *)(param_1 + 0x868) = fVar7 != 0.0;
  fVar7 = (float)GetRegFlag(0xd034,(GlobalEvent *)0x0,(LocalEvent *)0x0);
  *(bool *)(param_1 + 0x869) = fVar7 != 0.0;
  this = (MLyt *)(param_1 + 0x4b8);
  msys::MLyt::build(this,*(MemAlcBase **)(*(int *)(param_1 + 4) + 0x18),(AnimeName *)&DAT_1502452c,1
                   );
  msys::MLyt::init(this,iVar5 + 0xd3000,1);
  msys::MLyt::createLyt
            (this,(LytResourceMan *)(param_1 + 0x58),"MENU_SET_L.bflyt",
             (ButtonGroup *)(param_1 + 0x3c),(MCursorBase *)(param_1 + 0x14d3c));
  MoveVBase::stop((MoveVBase *)(param_1 + 0x584));
  *(undefined4 *)(param_1 + 0x5a0) = 0;
  *(undefined4 *)(param_1 + 0x5a4) = 0;
  *(undefined4 *)(param_1 + 0x5a8) = 0xc3480000;
  *(undefined4 *)(param_1 + 0x588) = *(undefined4 *)(param_1 + 0x5a0);
  *(undefined4 *)(param_1 + 0x58c) = 0;
  *(undefined4 *)(param_1 + 0x590) = 0xc3480000;
  *(undefined4 *)(param_1 + 0x5f4) = 0x401;
  if (*(char *)(param_1 + 0x866) != '\0') {
    pMVar6 = (MChrBase *)(param_1 + 0x86c);
    uVar4 = *(undefined4 *)(*(int *)(param_1 + 4) + 0x18);
    *(undefined4 *)(param_1 + 0x74ac) = 0x401;
    *(undefined4 *)(param_1 + 0x74a0) = uVar4;
    *(undefined4 *)(param_1 + 0x74a4) = 0;
    *(undefined4 *)(param_1 + 0x74a8) = 0;
    MessageSimple::init((MessageSimple *)(param_1 + 0x9b8));
    FUN_150142ec(pMVar6);
    *(undefined1 *)(param_1 + 0x6474) = 1;
    *(undefined1 *)(param_1 + 0x7490) = 4;
    *(undefined **)(param_1 + 0x61e0) = &DAT_003fc140;
    MessageWriter::setFontColor((MessageWriter *)(param_1 + 0x9b8),0xe6e6e6ff,true);
    msys::MLyt::attachMChr(this,pMVar6,"INS_text_hurigana",(char *)0x0,(char *)0x0,(char *)0x0);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
    }
    iVar2 = *(int *)(param_1 + 8);
    uVar4 = LMS_GetTextIndexByLabel(iVar2 + 0xeae90,"MES_setting_ruby");
    pwVar3 = (wchar_t *)LMS_GetText(iVar2 + 0xeae90,uVar4);
    msys::MMsg::playStr((MMsg *)pMVar6,pwVar3,(InsParam *)0x0,false);
  }
  pMVar6 = (MChrBase *)(param_1 + 0x74b0);
  uVar4 = *(undefined4 *)(*(int *)(param_1 + 4) + 0x18);
  *(undefined4 *)(param_1 + 0xe0f0) = 0x401;
  *(undefined4 *)(param_1 + 0xe0e4) = uVar4;
  *(undefined4 *)(param_1 + 0xe0e8) = 0;
  *(undefined4 *)(param_1 + 0xe0ec) = 0;
  MessageSimple::init((MessageSimple *)(param_1 + 0x75fc));
  FUN_150142ec(pMVar6);
  *(undefined1 *)(param_1 + 0xd0b8) = 1;
  *(undefined1 *)(param_1 + 0xe0d4) = 4;
  *(undefined **)(param_1 + 0xce24) = &DAT_003fc140;
  MessageWriter::setFontColor((MessageWriter *)(param_1 + 0x75fc),0xe6e6e6ff,true);
  msys::MLyt::attachMChr(this,pMVar6,"INS_text_easymode",(char *)0x0,(char *)0x0,(char *)0x0);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  iVar2 = *(int *)(param_1 + 8);
  uVar4 = LMS_GetTextIndexByLabel(iVar2 + 0xeae90,"MES_setting_easy");
  pwVar3 = (wchar_t *)LMS_GetText(iVar2 + 0xeae90,uVar4);
  msys::MMsg::playStr((MMsg *)pMVar6,pwVar3,(InsParam *)0x0,false);
  uVar4 = *(undefined4 *)(*(int *)(param_1 + 4) + 0x18);
  *(undefined4 *)(param_1 + 0x14d34) = 0x401;
  *(undefined4 *)(param_1 + 0x14d28) = uVar4;
  *(undefined4 *)(param_1 + 0x14d2c) = 0;
  pMVar6 = (MChrBase *)(param_1 + 0xe0f4);
  *(undefined4 *)(param_1 + 0x14d30) = 0;
  MessageSimple::init((MessageSimple *)(param_1 + 0xe240));
  FUN_150142ec(pMVar6);
  *(undefined1 *)(param_1 + 0x13cfc) = 1;
  *(undefined1 *)(param_1 + 0x14d18) = 4;
  *(undefined **)(param_1 + 0x13a68) = &DAT_003fc140;
  MessageWriter::setFontColor((MessageWriter *)(param_1 + 0xe240),0xe6e6e6ff,true);
  msys::MLyt::attachMChr(this,pMVar6,"INS_text_ASSIST",(char *)0x0,(char *)0x0,(char *)0x0);
  iVar5 = msys::MComSys::_sys;
  iVar2 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar2 = iVar5;
  }
  uVar4 = LMS_GetTextIndexByLabel(iVar2 + 0xeae90,"MES_setting_assist");
  pwVar3 = (wchar_t *)LMS_GetText(iVar2 + 0xeae90,uVar4);
  msys::MMsg::playStr((MMsg *)pMVar6,pwVar3,(InsParam *)0x0,false);
  *(undefined **)(param_1 + 0x10) = &DAT_15021744;
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}


// FUNC 0x150210c0 FUN_150210c0 (MainMenu)
//   size 0x204 | file MainMenu+0x210c0 | callers(0)

void FUN_150210c0(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  code *pcVar4;
  uint in_fpscr;
  float fVar5;
  
  iVar2 = msys::MComSys::_sys;
  pcVar3 = *(code **)(param_1 + 0x20);
  pcVar4 = FUN_15021818;
  if (pcVar3 == FUN_15021818) {
    pcVar4 = *(code **)(param_1 + 0x24);
  }
  if ((((pcVar3 == FUN_15021818 && pcVar4 == (code *)0x0) ||
       ((pcVar3 == (code *)0x0 &&
        ((*(uint *)(param_1 + 0x24) & 1) == 0 || *(uint *)(param_1 + 0x24) == 0)))) &&
      (param_3 != 1)) && (param_3 == 4)) {
    switch(*(undefined1 *)(param_2 + 0x48)) {
    case 0:
      *(undefined1 *)(param_1 + 0x867) = 0;
      (**(code **)(**(int **)(param_1 + 0x14d8c) + 0x18))();
      (**(code **)(**(int **)(param_1 + 0x14d8c) + 0xc))();
      break;
    case 1:
      *(undefined1 *)(param_1 + 0x867) = 1;
      (**(code **)(**(int **)(param_1 + 0x14d88) + 0x18))();
      (**(code **)(**(int **)(param_1 + 0x14d88) + 0xc))();
      break;
    case 2:
      *(undefined1 *)(param_1 + 0x868) = 0;
      (**(code **)(**(int **)(param_1 + 0x14d94) + 0x18))();
      (**(code **)(**(int **)(param_1 + 0x14d94) + 0xc))();
      break;
    case 3:
      *(undefined1 *)(param_1 + 0x868) = 1;
      (**(code **)(**(int **)(param_1 + 0x14d90) + 0x18))();
      (**(code **)(**(int **)(param_1 + 0x14d90) + 0xc))();
      break;
    case 4:
      *(undefined1 *)(param_1 + 0x869) = 0;
      (**(code **)(**(int **)(param_1 + 0x14d9c) + 0x18))();
      (**(code **)(**(int **)(param_1 + 0x14d9c) + 0xc))();
      break;
    case 5:
      *(undefined1 *)(param_1 + 0x869) = 1;
      (**(code **)(**(int **)(param_1 + 0x14d98) + 0x18))();
      (**(code **)(**(int **)(param_1 + 0x14d98) + 0xc))();
      break;
    case 6:
      iVar1 = *(int *)(param_1 + 8);
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar1 = iVar2;
      }
      *(undefined1 *)(iVar1 + 0xe6508) = 0;
      DAT_003fbea0 = (*(byte *)(param_1 + 0x867) & 1) << 3 | DAT_003fbea0 & 0xf7;
      DAT_003f4051 = *(undefined1 *)(param_1 + 0x867);
      fVar5 = (float)VectorSignedToFloat((int)*(char *)(param_1 + 0x868),
                                         (byte)(in_fpscr >> 0x16) & 3);
      PutRegFlag(0xd033,fVar5,(GlobalEvent *)0x0,(LocalEvent *)0x0);
      fVar5 = (float)VectorSignedToFloat((int)*(char *)(param_1 + 0x869),
                                         (byte)(in_fpscr >> 0x16) & 3);
      PutRegFlag(0xd034,fVar5,(GlobalEvent *)0x0,(LocalEvent *)0x0);
      *(undefined1 *)(param_1 + 0x865) = 0;
    }
    FUN_1501580c(msys::MComSys::_sys + 0x49368,0x110016,0,0,0);
  }
  return;
}


// FUNC 0x15021310 FUN_15021310 (MainMenu)
//   size 0x2e4 | file MainMenu+0x21310 | callers(0)

void FUN_15021310(void *param_1)

{
  char cVar1;
  int iVar2;
  AnimButton *pAVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  int iVar7;
  int *piVar8;
  undefined4 *puVar9;
  uint in_fpscr;
  float fVar10;
  LytAnim aLStack_64 [28];
  LytLocalize aLStack_48 [16];
  undefined4 local_38;
  
  if (*(int *)((int)param_1 + 8) == 0) {
    *(int *)((int)param_1 + 8) = msys::MComSys::_sys;
  }
  ad::lyt::LytLocalize::LytLocalize(aLStack_48);
  ad::lyt::LytLocalize::localize(aLStack_48,*(Layout **)((int)param_1 + 0x608));
  local_38 = 0;
  pAVar3 = (AnimButton *)
           ad::ctrl::ButtonGroup::FindButtonByName
                     ((ButtonGroup *)((int)param_1 + 0x3c),"btn_RETURN");
  *(AnimButton **)((int)param_1 + 0x860) = pAVar3;
  ad::ctrl::AnimButton::SetStateChangeCallback
            (pAVar3,(_func_void_AnimButton_ptr_State_State_void_ptr *)&LAB_150013dc,param_1);
  *(undefined4 *)(*(int *)((int)param_1 + 0x860) + 0x48) = 0;
  (**(code **)(**(int **)((int)param_1 + 0x860) + 0x28))(*(int **)((int)param_1 + 0x860),1);
  iVar4 = msys::MComSys::_sys;
  iVar7 = *(int *)((int)param_1 + 8);
  if (*(int *)((int)param_1 + 8) == 0) {
    *(int *)((int)param_1 + 8) = msys::MComSys::_sys;
    iVar7 = iVar4;
  }
  iVar2 = msys::MComSys::_sys;
  iVar4 = iVar7;
  if (iVar7 == 0) {
    *(int *)((int)param_1 + 8) = msys::MComSys::_sys;
    iVar4 = iVar2;
  }
  iVar4 = ad::fw::TaskBase::isFps30(*(TaskBase **)(iVar4 + 4));
  if (iVar4 == 0) {
    fVar10 = 1.0;
  }
  else {
    fVar10 = 2.0;
  }
  msys::MCursorBase::init((MCursorBase *)((int)param_1 + 0x14d3c),(MLyt *)(iVar7 + 0xe9a9c),fVar10);
  iVar7 = 7;
  puVar9 = (undefined4 *)((int)param_1 + 0x14d6c);
  do {
    iVar7 = iVar7 + -1;
    *puVar9 = 0;
    puVar9 = puVar9 + 1;
  } while (iVar7 != 0);
  iVar7 = 0;
  do {
    pAVar3 = (AnimButton *)
             ad::ctrl::ButtonGroup::FindButtonByName
                       ((ButtonGroup *)((int)param_1 + 0x3c),(char *)(&DAT_150363fc)[iVar7]);
    *(AnimButton **)((int)param_1 + iVar7 * 4 + 0x14d88) = pAVar3;
    ad::ctrl::AnimButton::SetStateChangeCallback
              (pAVar3,(_func_void_AnimButton_ptr_State_State_void_ptr *)&DAT_150210b4,param_1);
    *(int *)(*(int *)((int)param_1 + iVar7 * 4 + 0x14d88) + 0x48) = iVar7;
    iVar4 = *(int *)((int)param_1 + iVar7 * 4 + 0x14d88);
    *(uint *)(iVar4 + 8) = *(uint *)(iVar4 + 8) & 0xffffffdf;
    piVar5 = *(int **)((int)param_1 + iVar7 * 4 + 0x14d88);
    (**(code **)(*piVar5 + 0x28))(piVar5,1);
    iVar7 = iVar7 + 1;
  } while (iVar7 < 7);
  iVar7 = 0;
  do {
    cVar1 = (char)iVar7;
    uVar6 = msys::MLyt::getParts
                      ((MLyt *)((int)param_1 + 0x4b8),(char *)(&DAT_150363fc)[iVar7],(char *)0x0,
                       (char *)0x0);
    iVar7 = iVar7 + 1;
    *(undefined4 *)((int)param_1 + cVar1 * 4 + 0x14d6c) = uVar6;
  } while (iVar7 < 7);
  if (*(char *)((int)param_1 + 0x867) == '\0') {
    (**(code **)(**(int **)((int)param_1 + 0x14d88) + 0x20))();
  }
  else {
    (**(code **)(**(int **)((int)param_1 + 0x14d8c) + 0x20))();
  }
  if (*(char *)((int)param_1 + 0x868) == '\0') {
    (**(code **)(**(int **)((int)param_1 + 0x14d90) + 0x20))();
  }
  else {
    (**(code **)(**(int **)((int)param_1 + 0x14d94) + 0x20))();
  }
  if (*(char *)((int)param_1 + 0x869) == '\0') {
    (**(code **)(**(int **)((int)param_1 + 0x14d98) + 0x20))();
  }
  else {
    (**(code **)(**(int **)((int)param_1 + 0x14d9c) + 0x20))();
  }
  piVar8 = (int *)(*(int *)((int)param_1 + 4) + 0xc);
  puVar9 = *(undefined4 **)((int)param_1 + 0x4c0);
  *(undefined4 **)(*(int *)((int)param_1 + 0x4bc) + 4) = puVar9;
  *puVar9 = *(undefined4 *)((int)param_1 + 0x4bc);
  piVar5 = (int *)((int)param_1 + 0x4bc);
  if (piVar5 != (int *)0x0) {
    iVar7 = *piVar8;
    *(int **)((int)param_1 + 0x4c0) = piVar8;
    *piVar5 = iVar7;
    *(int **)(iVar7 + 4) = piVar5;
    *piVar8 = (int)piVar5;
  }
  *(undefined4 *)((int)param_1 + 0x5f4) = 0x401;
  msys::MLyt::playAnimeFromNo((MLyt *)((int)param_1 + 0x4b8),0,0,(char *)0x0,(char *)0x0);
  FUN_15012f30(aLStack_64);
  fVar10 = (float)VectorUnsignedToFloat
                            ((uint)(*(char *)((int)param_1 + 0x866) == '\0'),
                             (byte)(in_fpscr >> 0x16) & 3);
  ad::lyt::LytAnim::init(aLStack_64,*(Layout **)((int)param_1 + 0x608),"SET_PNL_hurigana","");
  ad::lyt::LytAnim::stopAndSetFrm(aLStack_64,fVar10);
  ad::lyt::LytAnim::term(aLStack_64,true);
  *(undefined1 **)((int)param_1 + 0x10) = &LAB_15021758;
  *(undefined4 *)((int)param_1 + 0x14) = 0;
  return;
}


// FUNC 0x1502166c main_menu::MainMenu_SettingPage::Core::vfunc_0x10 (MainMenu)
//   size 0xa0 | file MainMenu+0x2166c | callers(0) | datarefs 1

void main_menu::MainMenu_SettingPage::Core::vfunc_0x10(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_2 == 4) {
    FUN_1501580c(msys::MComSys::_sys + 0x49368,0x110017,0,0,0);
    iVar2 = msys::MComSys::_sys;
    iVar1 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar1 = iVar2;
    }
    *(undefined1 *)(iVar1 + 0xe6508) = 0;
    return;
  }
  if (param_2 == 5) {
    msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x4b8),0,1,(char *)0x0,(char *)0x0);
    msys::MCursorBase::setVisible((MCursorBase *)(param_1 + 0x14d3c),false);
    FUN_150131d0((MCursorBase *)(param_1 + 0x14d3c));
    *(undefined1 *)(param_1 + 0x865) = 0;
  }
  return;
}


// FUNC 0x15021714 FUN_15021714 (MainMenu)
//   size 0x2c | file MainMenu+0x21714 | callers(0) | datarefs 2

void FUN_15021714(int param_1)

{
  int iVar1;
  
  iVar1 = msys::MLyt::isBusyAnime((MLyt *)(param_1 + 0x4b8));
  if (iVar1 == 0) {
    *(undefined1 **)(param_1 + 0x18) = &LAB_1502177c;
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
  return;
}


// FUNC 0x1502178c FUN_1502178c (MainMenu)
//   size 0x74 | file MainMenu+0x2178c | callers(0) | datarefs 1

void FUN_1502178c(int param_1)

{
  int iVar1;
  int iVar2;
  
  FUN_150144d8();
  iVar2 = msys::MComSys::_sys;
  iVar1 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar1 = iVar2;
  }
  iVar2 = msys::MComSys::_sys;
  if (iVar1 == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  else {
    iVar2 = iVar1;
  }
  ad::fw::TaskBase::readLyt
            (*(TaskBase **)(iVar2 + 4),(Resource *)(param_1 + 0xcc),
             (FileContext *)(*(int *)(iVar1 + 0x278) + 0x150),"?MENU_SET",
             (MemAlcBase *)(param_1 + 0x28),0x7f,(ResCacheArg *)0x0);
  *(undefined1 **)(param_1 + 0x10) = &LAB_150212fc;
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}


// FUNC 0x15021818 FUN_15021818 (MainMenu)
//   size 0x1dc | file MainMenu+0x21818 | callers(0) | datarefs 2

void FUN_15021818(int param_1,uint *param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  cVar1 = *(char *)(param_1 + 0x14d39);
  iVar5 = (int)(char)(*(char *)(param_1 + 0x14d38) + cVar1 * '\x02');
  uVar3 = *param_2;
  if (6 < iVar5) {
    iVar5 = 6;
  }
  if ((uVar3 & 0x30) == 0) {
    if ((uVar3 & 0x40) == 0) {
      if ((uVar3 & 0x80) == 0) {
        if ((uVar3 & 0x401) == 0) {
          if ((uVar3 & 0x802) != 0) {
            (**(code **)(**(int **)(param_1 + 0x860) + 0x10))();
            iVar2 = msys::MComSys::_sys;
            iVar4 = *(int *)(param_1 + 8);
            if (*(int *)(param_1 + 8) == 0) {
              *(int *)(param_1 + 8) = msys::MComSys::_sys;
              iVar4 = iVar2;
            }
            *(undefined1 *)(iVar4 + 0xe6508) = 0;
            iVar2 = msys::MComSys::_sys;
            iVar4 = *(int *)(param_1 + 8);
            if (*(int *)(param_1 + 8) == 0) {
              *(int *)(param_1 + 8) = msys::MComSys::_sys;
              iVar4 = iVar2;
            }
            *(undefined1 *)(iVar4 + 0xe650a) = 1;
          }
        }
        else {
          (**(code **)(**(int **)(param_1 + iVar5 * 4 + 0x14d88) + 0x10))();
        }
      }
      else {
        *(char *)(param_1 + 0x14d39) = cVar1 + '\x01';
        if ('\x03' < (char)(cVar1 + '\x01')) {
          *(bool *)(param_1 + 0x14d39) = *(char *)(param_1 + 0x866) == '\0';
        }
      }
    }
    else {
      *(char *)(param_1 + 0x14d39) = cVar1 + -1;
      if ((char)(cVar1 + -1) < (*(char *)(param_1 + 0x866) == '\0')) {
        *(undefined1 *)(param_1 + 0x14d39) = 3;
      }
    }
  }
  else {
    *(bool *)(param_1 + 0x14d38) = *(char *)(param_1 + 0x14d38) == '\0';
  }
  iVar4 = 0;
  do {
    if (*(int *)(param_1 + iVar4 * 4 + 0x14d88) == *(int *)(param_1 + 0x4c)) {
      cVar1 = *(char *)(*(int *)(param_1 + 0x4c) + 0x48);
      *(char *)(param_1 + 0x14d38) = cVar1 % '\x02';
      *(char *)(param_1 + 0x14d39) = cVar1 / '\x02';
      break;
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 7);
  iVar4 = (int)(char)(*(char *)(param_1 + 0x14d38) + *(char *)(param_1 + 0x14d39) * '\x02');
  if (6 < iVar4) {
    iVar4 = 6;
  }
  if (iVar5 != iVar4) {
    FUN_1501580c(msys::MComSys::_sys + 0x49368,0x110015,0,0,0);
    *(char *)(param_1 + 0x14d54) = (char)iVar4;
  }
  FUN_150131d0(param_1 + 0x14d3c);
  return;
}


// FUNC 0x15021a04 FUN_15021a04 (MainMenu)
//   size 0x118 | file MainMenu+0x21a04 | callers(0) | datarefs 2

void FUN_15021a04(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  
  iVar2 = msys::MLyt::isBusyAnime((MLyt *)(param_1 + 0x4b8));
  iVar1 = msys::MComSys::_sys;
  if (iVar2 == 0) {
    uVar4 = 0;
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
    do {
      piVar3 = *(int **)(param_1 + uVar4 * 4 + 0x14d88);
      (**(code **)(*piVar3 + 0x28))(piVar3,1);
      uVar4 = uVar4 + 1 & 0xff;
    } while (uVar4 < 7);
    if (*(char *)(param_1 + 0x866) == '\0') {
      *(undefined1 *)(param_1 + 0x14d38) = 0;
      *(undefined1 *)(param_1 + 0x14d39) = 1;
      *(undefined1 *)(param_1 + 0x14d54) = 2;
      (**(code **)(**(int **)(param_1 + 0x14d8c) + 0x28))(*(int **)(param_1 + 0x14d8c),0);
      (**(code **)(**(int **)(param_1 + 0x14d88) + 0x28))(*(int **)(param_1 + 0x14d88),0);
    }
    else {
      *(undefined1 *)(param_1 + 0x14d38) = 0;
      *(undefined1 *)(param_1 + 0x14d39) = 0;
      *(undefined1 *)(param_1 + 0x14d54) = 0;
    }
    msys::MCursorBase::setVisible((MCursorBase *)(param_1 + 0x14d3c),true);
    FUN_150131d0((MCursorBase *)(param_1 + 0x14d3c));
    *(code **)(param_1 + 0x20) = FUN_15021818;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x15021b24 FUN_15021b24 (MainMenu)
//   size 0x38 | file MainMenu+0x21b24 | callers(0) | datarefs 1

void FUN_15021b24(int param_1)

{
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x4b8),0,1,(char *)0x0,(char *)0x0);
  *(code **)(param_1 + 0x18) = FUN_15021714;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  return;
}


// FUNC 0x15021b60 main_menu::MainMenu_SettingPage::Core::vfunc_0x4 (MainMenu)
//   size 0xb0 | file MainMenu+0x21b60 | callers(0) | datarefs 1

void main_menu::MainMenu_SettingPage::Core::vfunc_0x4(undefined4 *param_1)

{
  int iVar1;
  void *pvVar2;
  
  *param_1 = &vtable;
  msys::MCursorBase::term((MCursorBase *)(param_1 + 0x534f));
  iVar1 = msys::MCursorBase::~MCursorBase((MCursorBase *)(param_1 + 0x534f));
  *(undefined ***)(iVar1 + -0x6c48) = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar1 = MessageSimple::~MessageSimple((MessageSimple *)(iVar1 + -0x6afc));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  *(undefined ***)(iVar1 + -0x6c44) = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar1 = MessageSimple::~MessageSimple((MessageSimple *)(iVar1 + -0x6af8));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  *(undefined ***)(iVar1 + -0x6c44) = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar1 = MessageSimple::~MessageSimple((MessageSimple *)(iVar1 + -0x6af8));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  pvVar2 = (void *)MainMenuPageBase::Core::vfunc_0x0(iVar1 + -0x86c);
  operator_delete(pvVar2);
  return;
}


// FUNC 0x15021c18 main_menu::MainMenu_SettingPage::Core::vfunc_0x0 (MainMenu)
//   size 0xac | file MainMenu+0x21c18 | callers(0) | datarefs 1

void main_menu::MainMenu_SettingPage::Core::vfunc_0x0(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &vtable;
  msys::MCursorBase::term((MCursorBase *)(param_1 + 0x534f));
  iVar1 = msys::MCursorBase::~MCursorBase((MCursorBase *)(param_1 + 0x534f));
  *(undefined ***)(iVar1 + -0x6c48) = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar1 = MessageSimple::~MessageSimple((MessageSimple *)(iVar1 + -0x6afc));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  *(undefined ***)(iVar1 + -0x6c44) = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar1 = MessageSimple::~MessageSimple((MessageSimple *)(iVar1 + -0x6af8));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  *(undefined ***)(iVar1 + -0x6c44) = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar1 = MessageSimple::~MessageSimple((MessageSimple *)(iVar1 + -0x6af8));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  MainMenuPageBase::Core::vfunc_0x0(iVar1 + -0x86c);
  return;
}


// FUNC 0x15021ccc main_menu::MainMenu_SettingPage::vfunc_0x30 (MainMenu)
//   size 0xb4 | file MainMenu+0x21ccc | callers(0) | datarefs 1

void main_menu::MainMenu_SettingPage::vfunc_0x30(int param_1)

{
  void *pvVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  pvVar1 = operator_new(0x14da4,*(MemAlcBase **)(param_1 + 0x18),(char *)0x0,0);
  if (pvVar1 == (void *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    puVar4 = (undefined4 *)FUN_15014438(pvVar1,param_1);
    *puVar4 = &Core::vtable;
    iVar2 = FUN_15012fa0(puVar4 + 0x21b);
    iVar2 = FUN_15012fa0(iVar2 + 0x6c44);
    iVar2 = FUN_15012fa0(iVar2 + 0x6c44);
    puVar3 = (undefined4 *)msys::MCursorBase::MCursorBase((MCursorBase *)(iVar2 + 0x6c48));
    puVar3[0xc] = 0;
    *puVar3 = &vtable_for_N4msys7MCursorILj7EEE;
    puVar3[0xd] = 0;
    puVar3[0xe] = 0;
    puVar3[0xf] = 0;
    puVar3[0x10] = 0;
    puVar3[0x11] = 0;
    puVar3[0x12] = 0;
    puVar3[-0x534b] = FUN_1502178c;
    puVar3[-0x534a] = 0;
    puVar3[-0x5349] = FUN_15021b24;
    puVar3[-0x5348] = 0;
    puVar4 = puVar3 + -0x534f;
    puVar3[-0x5347] = FUN_15021a04;
    puVar3[-0x5346] = 0;
  }
  *(undefined4 **)(param_1 + 0x20) = puVar4;
  return;
}


// FUNC 0x15021d90 main_menu::MainMenu_SettingPage::vfunc_0x24 (MainMenu)
//   size 0x8 | file MainMenu+0x21d90 | callers(0) | datarefs 1

undefined4 main_menu::MainMenu_SettingPage::vfunc_0x24(void)

{
  return 7;
}


// FUNC 0x15021d98 main_menu::MainMenu_SettingPage::vfunc_0x4 (MainMenu)
//   size 0x10 | file MainMenu+0x21d98 | callers(0) | datarefs 1

void main_menu::MainMenu_SettingPage::vfunc_0x4(void)

{
  void *pvVar1;
  
  pvVar1 = (void *)MainMenuPageBase::vfunc_0x0();
  operator_delete(pvVar1);
  return;
}


// FUNC 0x15021da8 ->main_menu::MainMenuPageBase::vfunc_0x0 (MainMenu)
//   size 0x4 | file MainMenu+0x21da8 | callers(0) | datarefs 1
// veneer/thunk -> 0x15015174 main_menu::MainMenuPageBase::vfunc_0x0 (MainMenu)

// FUNC 0x15021dac FUN_15021dac (MainMenu)
//   size 0x260 | file MainMenu+0x21dac | callers(0) | datarefs 4

void FUN_15021dac(MComSys *param_1)

{
  MComSys MVar1;
  MCamera *this;
  MTX34 *pMVar2;
  uint uVar3;
  BootInfo *pBVar4;
  int iVar5;
  float fVar6;
  float fVar7;
  undefined4 local_d0 [2];
  MTX44 aMStack_c8 [64];
  MTX34 aMStack_88 [48];
  MTX34 aMStack_58 [52];
  
  MVar1 = param_1[0xe904b];
  if (MVar1 == (MComSys)0x3) {
    this = (MCamera *)(param_1 + 0x4ad54);
    msys::MCamera::getProjMtx(this,aMStack_c8,0x400);
    msys::MCamera::getViewMtx(this,aMStack_88);
    ad::fw::TaskBase::setULcdCameraInfoBase(*(TaskBase **)(param_1 + 4),aMStack_88,aMStack_c8,1);
    pMVar2 = (MTX34 *)msys::MCamera::getViewMtx(this,aMStack_58);
    ad::h3d::Scene::updateLight((Scene *)(param_1 + 0x4aaa0),pMVar2);
    pMVar2 = (MTX34 *)msys::MCamera::getViewMtx((MCamera *)(param_1 + 0x4ae34),aMStack_58);
    ad::h3d::Scene::updateLight((Scene *)(param_1 + 0x4aba4),pMVar2);
    msys::MComSys::funcCalcMainNomal(param_1);
    iVar5 = ad::fw::TaskBase::isFps30(*(TaskBase **)(param_1 + 4));
    fVar7 = 1.0;
    fVar6 = 2.0;
    if (iVar5 != 0) {
      fVar7 = 2.0;
    }
    ad::lyt::LytAnim::update((LytAnim *)(param_1 + 0xe9e60),fVar7);
    iVar5 = ad::fw::TaskBase::isFps30(*(TaskBase **)(param_1 + 4));
    if (iVar5 == 0) {
      fVar6 = 1.0;
    }
    ad::lyt::LytAnim::update((LytAnim *)(param_1 + 0xe9e44),fVar6);
    if ((((param_1[0xe904a] != (MComSys)0x0) && (param_1[0xe6508] != (MComSys)0x0)) &&
        (((byte)param_1[0xe650c] & (byte)param_1[0xe6510] & 8) != 0)) &&
       (uVar3 = CtrBtn::get((CtrBtn *)&gBtn,2), (uVar3 & 8) != 0)) {
      local_d0[0] = 0;
      FUN_1501580c(param_1 + 0x49368,0x110017,0);
      param_1[0xe6508] = (MComSys)0x0;
      local_d0[0] = 0xff000000;
      MoveC::moveFrm((MoveC *)(param_1 + 0x4acd4),(Color8 *)local_d0,16.0);
      MoveC::moveFrm((MoveC *)(param_1 + 0x4ad14),(Color8 *)local_d0,16.0);
      pBVar4 = (BootInfo *)main_menu::GetBootInfo();
      main_menu::BootInfo::stopRcordBgm(pBVar4);
      pBVar4 = (BootInfo *)main_menu::GetBootInfo();
      main_menu::BootInfo::restoreBgm(pBVar4);
      MVar1 = (MComSys)0x4;
LAB_15021fa4:
      param_1[0xe904b] = MVar1;
      return;
    }
  }
  else if (MVar1 == (MComSys)0x4) {
    pBVar4 = (BootInfo *)main_menu::GetBootInfo();
    iVar5 = main_menu::BootInfo::playBgm(pBVar4);
    if ((iVar5 != 0) && (*(float *)(param_1 + 0x4ad04) <= *(float *)(param_1 + 0x4ad00))) {
      if (*(float *)(param_1 + 0x4ad40) < *(float *)(param_1 + 0x4ad44)) {
        return;
      }
      MVar1 = (MComSys)0x5;
      goto LAB_15021fa4;
    }
  }
  else if (MVar1 == (MComSys)0x5) {
    param_1[0xe9049] = (MComSys)0x1;
  }
  return;
}


// FUNC 0x15022038 ->msys::MComSys::funcDrawLower (MainMenu)
//   size 0x4 | file MainMenu+0x22038 | callers(0) | datarefs 1
// veneer/thunk -> 0x0032e2b8 msys::MComSys::funcDrawLower (static)

// FUNC 0x1502203c ->msys::MComSys::funcDrawUpper (MainMenu)
//   size 0x4 | file MainMenu+0x2203c | callers(0) | datarefs 1
// veneer/thunk -> 0x0032e760 msys::MComSys::funcDrawUpper (static)

// FUNC 0x15022040 FUN_15022040 (MainMenu)
//   size 0xbc8 | file MainMenu+0x22040 | callers(0) | datarefs 2

void FUN_15022040(MComSys *param_1)

{
  MComSys MVar1;
  int iVar2;
  IAllocator *pIVar3;
  void *pvVar4;
  MComSys *pMVar5;
  MLyt *this;
  undefined4 uVar6;
  MPaneRef *pMVar7;
  MPaneRef *pMVar8;
  MLyt *pMVar9;
  MDfxChr *pMVar10;
  MComSys *pMVar11;
  undefined4 uVar12;
  int iVar13;
  undefined4 *puVar14;
  undefined4 uVar15;
  MComSys *pMVar16;
  int *piVar17;
  MemAlcBase *pMVar18;
  uint in_r12;
  bool bVar19;
  uint in_fpscr;
  float fVar20;
  ulonglong uVar21;
  void *apvStackY_468 [128];
  uint uVar22;
  Color8 aCStack_25a [10];
  MComSys *local_250;
  MComSys *local_24c;
  MComSys *local_248 [2];
  MComSys *local_240;
  MComSys *local_238;
  
  iVar13 = *(int *)(param_1 + 0x278);
  iVar2 = iVar13;
  while( true ) {
    bVar19 = iVar2 != iVar13 + 0x348;
    if (bVar19) {
      in_r12 = (uint)*(byte *)(iVar2 + 4);
    }
    if (!bVar19 || in_r12 == 0) break;
    iVar2 = iVar2 + 0xa8;
  }
  if (iVar2 == iVar13 + 0x348) {
    MVar1 = param_1[0xe904b];
    local_250 = param_1 + 0xe9238;
    local_24c = param_1 + 0xe9304;
    local_248[0] = param_1 + 0xe92c0;
    pMVar18 = (MemAlcBase *)(param_1 + 0xc);
    if (MVar1 == (MComSys)0x0) {
      iVar2 = ad::lyt::LytDrawSys::GetInst();
      pIVar3 = (IAllocator *)(iVar2 + 0x5f4);
      if (ad::lyt::Layout::s_pAllocator != pIVar3) {
        ad::lyt::Initialize(pIVar3,pIVar3);
      }
      *(MComSys **)(iVar2 + 0x5f8) = param_1 + 0xc;
      iVar2 = ad::lyt::LytDrawSys::GetInst();
      *(undefined4 *)(iVar2 + 0x5fc) = 0x10000;
      (**(code **)(**(int **)(*(int *)(param_1 + 0xe64f0) + 0x44) + 0xc))
                (*(int **)(*(int *)(param_1 + 0xe64f0) + 0x44),"MDFXMenuArchive");
      msys::MComSys::readLytNum
                (param_1,(FileContext *)(*(int *)(param_1 + 0x278) + 0x150),
                 (MemAlcBase *)(param_1 + 0xc));
      ad::fw::TaskBase::readLyt
                (*(TaskBase **)(param_1 + 4),(Resource *)(param_1 + 0xe91b0),
                 (FileContext *)(*(int *)(param_1 + 0x278) + 0x150),"MENU_BG",pMVar18,0x7f,
                 (ResCacheArg *)0x0);
      ad::fw::TaskBase::readLyt
                (*(TaskBase **)(param_1 + 4),(Resource *)(param_1 + 0xe91f4),
                 (FileContext *)(*(int *)(param_1 + 0x278) + 0x150),"SQ_CURSOR_SET",pMVar18,0x7f,
                 (ResCacheArg *)0x0);
      FUN_15012fe8(*(undefined4 *)(param_1 + 4),local_250,*(int *)(param_1 + 0x278) + 0xa8,
                   "m_map_icon");
      FUN_15012fe8(*(undefined4 *)(param_1 + 4),(Resource *)(param_1 + 0xe927c),
                   *(int *)(param_1 + 0x278) + 0xa8,"m_map_icon_ev");
      iVar2 = main_menu::GetBootInfo();
      if (*(char *)(iVar2 + 0x2c) == '\x01') {
        FUN_15012fe8(*(undefined4 *)(param_1 + 4),local_24c,*(int *)(param_1 + 0x278) + 0xa8,
                     "m_kinopio_rd_idl");
      }
      ad::fw::TaskBase::readArcFile
                (*(TaskBase **)(param_1 + 4),(Resource *)local_248[0],
                 (FileContext *)(*(int *)(param_1 + 0x278) + 0x2a0),"b_sys",pMVar18,0,
                 (ResCacheArg *)0x0);
      puVar14 = operator_new(4,(MemAlcBase *)(param_1 + 0xc),"ParamMainSys",0);
      if (puVar14 != (undefined4 *)0x0) {
        *puVar14 = 0x3f000000;
      }
      *(undefined4 **)(param_1 + 0xe9348) = puVar14;
      MessageSys::GetPath((wchar_t *)local_248,(wchar_t *)L"Menu.msbt",false);
      uVar22 = 0;
      uVar21 = nn::fs::CTR::MPCore::detail::UserFileSystem::TryOpenFile
                         (apvStackY_468 + 0x81,(wchar_t *)local_248,1);
      uVar6 = (undefined4)(uVar21 >> 0x20);
      bVar19 = (uVar21 & 0x80000000) != 0;
      if (bVar19) {
        uVar6 = 0x150223d0;
      }
      if (bVar19 && (int)uVar21 < 0) {
        nn::err::CTR::ThrowFatalErrAll((int)uVar21,uVar6);
      }
      iVar2 = nn::fs::detail::FileBase::TryGetSize
                        ((FileBase *)(apvStackY_468 + 0x81),(longlong *)&local_250);
      if (iVar2 < 0) {
        nn::err::CTR::ThrowFatalErrAll(iVar2,0x15022400);
      }
      pMVar5 = local_250;
      pvVar4 = (void *)(**(code **)(*(int *)(param_1 + 0xc) + 0xc))(param_1 + 0xc,local_250,0);
      *(void **)(param_1 + 0xeae7c) = pvVar4;
      iVar2 = nn::fs::detail::FileBase::TryRead
                        ((FileBase *)(apvStackY_468 + 0x81),(int *)&local_24c,pvVar4,(uint)pMVar5);
      if (iVar2 < 0) {
        nn::err::CTR::ThrowFatalErrAll(iVar2,0x150224e8);
      }
      MsgDataAcsrBase::init((MsgDataAcsrBase *)(param_1 + 0xeae88),*(void **)(param_1 + 0xeae7c));
      if ((uVar22 & 0xfffffffe) != 0) {
        if ((uVar22 & 1) != 0) {
          nndbgPanic();
        }
        nn::fs::CTR::MPCore::detail::UserFileSystem::CloseFile((void *)(uVar22 & 0xfffffffe));
        uVar22 = 0;
      }
      if ((uVar22 & 0xfffffffe) != 0) {
        if ((uVar22 & 1) != 0) {
          nndbgPanic();
        }
        nn::fs::CTR::MPCore::detail::UserFileSystem::CloseFile((void *)(uVar22 & 0xfffffffe));
      }
      MVar1 = (MComSys)0x1;
LAB_15022d70:
      param_1[0xe904b] = MVar1;
      return;
    }
    local_238 = param_1 + 0xfcd;
    local_240 = param_1 + 0xf00;
    if (MVar1 == (MComSys)0x1) {
      if ((param_1[0xe9280] != (MComSys)0x0) &&
         (iVar2 = (**(code **)(**(int **)(*(int *)(param_1 + 0xe64f0) + 0x44) + 0x10))(), iVar2 == 0
         )) {
        Message::setMsgDat((Message *)(param_1 + 0x28120),*(void **)(param_1 + 0xeae7c));
        Message::setMsgDat((Message *)(param_1 + 0x2ee80),*(void **)(param_1 + 0xeae7c));
        Message::setMsgDat((Message *)(param_1 + 0x35be0),*(void **)(param_1 + 0xeae7c));
        Message::setMsgDat((Message *)(param_1 + 0x3c940),*(void **)(param_1 + 0xeae7c));
        pvVar4 = (void *)ad::fw::Resource::getFileData((Resource *)local_248[0]);
        MsgDataAcsrBase::init((MsgDataAcsrBase *)(param_1 + 0xeaef4),pvVar4);
        ad::lyt::LytResourceMan::init((LytResourceMan *)(param_1 + 2000));
        pvVar4 = (void *)ad::fw::Resource::getFileData((Resource *)(param_1 + 0xe91b0));
        ad::lyt::LytResourceMan::registerArc((LytResourceMan *)(param_1 + 2000),pvVar4,".");
        pvVar4 = (void *)ad::fw::Resource::getFileData((Resource *)(param_1 + 0xe91f4));
        ad::lyt::LytResourceMan::registerArc((LytResourceMan *)(param_1 + 2000),pvVar4,".");
        pvVar4 = (void *)ad::fw::Resource::getFileData((Resource *)(param_1 + 0x844));
        ad::lyt::LytResourceMan::registerArc((LytResourceMan *)(param_1 + 2000),pvVar4,".");
        msys::MLytNumRes::init((MLytNumRes *)(param_1 + 0x844),(LytResourceMan *)(param_1 + 2000),5)
        ;
        pMVar11 = param_1 + 0xd3000;
        msys::MLyt::init((MLyt *)(param_1 + 0xe9a9c),pMVar11,0);
        msys::MLyt::createLyt
                  ((MLyt *)(param_1 + 0xe9a9c),(LytResourceMan *)(param_1 + 2000),"SQ_CURSOR.bflyt")
        ;
        MoveVBase::stop((MoveVBase *)(param_1 + 0xe9b68));
        *(undefined4 *)(param_1 + 0xe9b84) = 0;
        *(undefined4 *)(param_1 + 0xe9b88) = 0;
        *(undefined4 *)(param_1 + 0xe9b8c) = 0xc347cccd;
        *(undefined4 *)(param_1 + 0xe9b6c) = *(undefined4 *)(param_1 + 0xe9b84);
        *(undefined4 *)(param_1 + 0xe9b70) = 0;
        *(undefined4 *)(param_1 + 0xe9b74) = 0xc347cccd;
        param_1[0xe9bdd] = (MComSys)0x0;
        *(undefined4 *)(param_1 + 0xe9bd8) = 0x401;
        pMVar16 = param_1 + 0xe64e0;
        puVar14 = *(undefined4 **)(param_1 + 0xe9aa4);
        *(undefined4 **)(*(int *)(param_1 + 0xe9aa0) + 4) = puVar14;
        *puVar14 = *(undefined4 *)(param_1 + 0xe9aa0);
        pMVar5 = param_1 + 0xe9aa0;
        if (pMVar5 != (MComSys *)0x0) {
          *(int *)pMVar5 = *(int *)pMVar16;
          *(MComSys **)(param_1 + 0xe9aa4) = pMVar16;
          *(MComSys **)(*(int *)pMVar16 + 4) = pMVar5;
          *(MComSys **)pMVar16 = pMVar5;
        }
        this = (MLyt *)(param_1 + 0xe934c);
        msys::MLyt::init(this,pMVar11,1);
        msys::MLyt::createLyt(this,(LytResourceMan *)(param_1 + 2000),"MENU_BG_U.bflyt");
        MoveVBase::stop((MoveVBase *)(param_1 + 0xe9418));
        *(undefined4 *)(param_1 + 0xe9434) = 0;
        *(undefined4 *)(param_1 + 0xe9438) = 0;
        *(undefined4 *)(param_1 + 0xe943c) = 0xc3480000;
        *(undefined4 *)(param_1 + 0xe941c) = *(undefined4 *)(param_1 + 0xe9434);
        *(undefined4 *)(param_1 + 0xe9420) = 0;
        *(undefined4 *)(param_1 + 0xe9424) = 0xc3480000;
        if (((nn::math::VEC3::One()::one & 1) == 0) &&
           (iVar2 = __cxa_guard_acquire(&nn::math::VEC3::One()::one), iVar2 != 0)) {
          nn::math::VEC3::One()::one = 0x3f800000;
          DAT_00434c40 = 0x3f800000;
          DAT_00434c44 = 0x3f800000;
          __cxa_guard_release(&nn::math::VEC3::One()::one);
        }
        puVar14 = &nn::math::VEC3::One()::one;
        MoveVBase::stop((MoveVBase *)(param_1 + 0xe9360));
        uVar6 = *puVar14;
        uVar12 = puVar14[1];
        uVar15 = puVar14[2];
        *(undefined4 *)(param_1 + 0xe937c) = uVar6;
        *(undefined4 *)(param_1 + 0xe9380) = uVar12;
        *(undefined4 *)(param_1 + 0xe9384) = uVar15;
        *(undefined4 *)(param_1 + 0xe9364) = uVar6;
        *(undefined4 *)(param_1 + 0xe9368) = uVar12;
        *(undefined4 *)(param_1 + 0xe936c) = uVar15;
        msys::MLyt::createAnime
                  (this,0,"FADE_IN",
                   &msys::MLyt::createAnime(unsigned_char,char_const*,bool,signed)::string_literal);
        msys::MLyt::createAnime
                  (this,1,"FADE_OUT",
                   &msys::MLyt::createAnime(unsigned_char,char_const*,bool,signed)::string_literal);
        msys::MLyt::createAnime(this,2,"CLOUD_LOOP","MAP_ALL");
        iVar2 = msys::MLyt::getAnim(this,2);
        Frm::setSpd((Frm *)(iVar2 + 4),0.5);
        ad::lyt::LytAnim::init
                  ((LytAnim *)(param_1 + 0xe9e44),*(Layout **)(this + 0x150),"MAP_OUT","MAP_ALL");
        if (local_238[(char)local_240[0xd7]] != (MComSys)0x0) {
          uVar6 = ad::lyt::AnimTransform::GetFrameSize(*(AnimTransform **)(param_1 + 0xe9e58));
          fVar20 = (float)VectorUnsignedToFloat(uVar6,(byte)(in_fpscr >> 0x16) & 3);
          ad::lyt::LytAnim::stopAndSetFrm((LytAnim *)(param_1 + 0xe9e44),fVar20);
        }
        ad::lyt::LytAnim::init
                  ((LytAnim *)(param_1 + 0xe9e60),*(Layout **)(this + 0x150),"MAP_IN","MAP_ALL");
        pMVar7 = (MPaneRef *)
                 msys::MLyt::getMPaneRef(this,"INS_OBJ_DEST","MAP_ALL",(char *)0x0,(char *)0x0);
        pMVar8 = (MPaneRef *)
                 msys::MLyt::getMPaneRef(this,"INS_OBJ_CRNT","MAP_ALL",(char *)0x0,(char *)0x0);
        msys::MMapIconMan::init
                  ((MMapIconMan *)(param_1 + 0xea174),(Resource *)local_250,
                   (Resource *)(param_1 + 0xe927c),pMVar8,pMVar7);
        iVar2 = msys::MLyt::getParts(this,"MAP_ALL",(char *)0x0,(char *)0x0);
        msys::MMapIconMan::setUp
                  ((MMapIconMan *)(param_1 + 0xea174),*(Layout **)(iVar2 + 0xac),
                   (GameWorkPOD *)&gGameWork);
        *(undefined4 *)(this + 0x13c) = 0x400;
        puVar14 = *(undefined4 **)(this + 8);
        *(undefined4 **)(*(int *)(this + 4) + 4) = puVar14;
        pMVar9 = this + 4;
        pMVar5 = param_1 + 0xe64d8;
        *puVar14 = *(undefined4 *)(this + 4);
        if (pMVar9 != (MLyt *)0x0) {
          iVar2 = *(int *)pMVar5;
          *(MComSys **)(this + 8) = pMVar5;
          *(int *)pMVar9 = iVar2;
          *(MLyt **)(iVar2 + 4) = pMVar9;
          *(MLyt **)pMVar5 = pMVar9;
        }
        pMVar9 = (MLyt *)(param_1 + 0xe96f4);
        msys::MLyt::init(pMVar9,pMVar11,1);
        msys::MLyt::createLyt(pMVar9,(LytResourceMan *)(param_1 + 2000),"MENU_BG_L.bflyt");
        MoveVBase::stop((MoveVBase *)(param_1 + 0xe97c0));
        *(undefined4 *)(param_1 + 0xe97dc) = 0;
        *(undefined4 *)(param_1 + 0xe97e0) = 0;
        *(undefined4 *)(param_1 + 0xe97e4) = 0xc3480000;
        *(undefined4 *)(param_1 + 0xe97c4) = *(undefined4 *)(param_1 + 0xe97dc);
        *(undefined4 *)(param_1 + 0xe97c8) = 0;
        *(undefined4 *)(param_1 + 0xe97cc) = 0xc3480000;
        if (((nn::math::VEC3::One()::one & 1) == 0) &&
           (iVar2 = __cxa_guard_acquire(&nn::math::VEC3::One()::one), iVar2 != 0)) {
          nn::math::VEC3::One()::one = 0x3f800000;
          DAT_00434c40 = 0x3f800000;
          DAT_00434c44 = 0x3f800000;
          __cxa_guard_release(&nn::math::VEC3::One()::one);
        }
        puVar14 = &nn::math::VEC3::One()::one;
        MoveVBase::stop((MoveVBase *)(param_1 + 0xe9708));
        uVar6 = *puVar14;
        uVar12 = puVar14[1];
        uVar15 = puVar14[2];
        *(undefined4 *)(param_1 + 0xe9724) = uVar6;
        *(undefined4 *)(param_1 + 0xe9728) = uVar12;
        *(undefined4 *)(param_1 + 0xe972c) = uVar15;
        *(undefined4 *)(param_1 + 0xe970c) = uVar6;
        *(undefined4 *)(param_1 + 0xe9710) = uVar12;
        *(undefined4 *)(param_1 + 0xe9714) = uVar15;
        *(undefined4 *)(param_1 + 0xe9830) = 0x401;
        puVar14 = *(undefined4 **)(param_1 + 0xe96fc);
        *(undefined4 **)(*(int *)(param_1 + 0xe96f8) + 4) = puVar14;
        *puVar14 = *(undefined4 *)(param_1 + 0xe96f8);
        pMVar5 = param_1 + 0xe96f8;
        if (pMVar5 != (MComSys *)0x0) {
          *(int *)pMVar5 = *(int *)pMVar16;
          *(MComSys **)(param_1 + 0xe96fc) = pMVar16;
          *(MComSys **)(*(int *)pMVar16 + 4) = pMVar5;
          *(MComSys **)pMVar16 = pMVar5;
        }
        pMVar10 = (MDfxChr *)(param_1 + 0xe9e7c);
        msys::MDfxChr::init(pMVar10,gMemAlc,*(MDfxSys **)(param_1 + 0xe64f0),
                            (Scene *)(param_1 + 0x4aaa0),0x400);
        msys::MLyt::attachMChr
                  (this,(MChrBase *)pMVar10,"INS_EFFECT_STAR_U",(char *)0x0,(char *)0x0,(char *)0x0)
        ;
        msys::MDfxChr::playDfx(pMVar10,0x10);
        *(undefined2 *)(*(int *)(param_1 + 0xe9fd0) + 0xf2) = 0;
        pMVar10 = (MDfxChr *)(param_1 + 0xe9ff8);
        msys::MDfxChr::init(pMVar10,gMemAlc,*(MDfxSys **)(param_1 + 0xe64f0),
                            (Scene *)(param_1 + 0x4aba4),0x401);
        msys::MLyt::attachMChr
                  (pMVar9,(MChrBase *)pMVar10,"INS_EFFECT_STAR_L",(char *)0x0,(char *)0x0,
                   (char *)0x0);
        msys::MDfxChr::playDfx(pMVar10,0x11);
        *(undefined2 *)(*(int *)(param_1 + 0xea14c) + 0xf2) = 0;
        iVar2 = main_menu::GetBootInfo();
        if (*(char *)(iVar2 + 0x2c) == '\x01') {
          msys::MCellAnime::init((MCellAnime *)(param_1 + 0xf1ec4),(Resource *)local_24c);
          param_1[0xf2005] = (MComSys)0x0;
          *(undefined4 *)(param_1 + 0xf2000) = 0x401;
          puVar14 = *(undefined4 **)(param_1 + 0xf1ecc);
          pMVar5 = param_1 + 0xf1ec8;
          *(undefined4 **)(*(int *)(param_1 + 0xf1ec8) + 4) = puVar14;
          *puVar14 = *(undefined4 *)(param_1 + 0xf1ec8);
          if (pMVar5 != (MComSys *)0x0) {
            *(int *)pMVar5 = *(int *)pMVar16;
            *(MComSys **)(param_1 + 0xf1ecc) = pMVar16;
            *(MComSys **)(*(int *)pMVar16 + 4) = pMVar5;
            *(MComSys **)pMVar16 = pMVar5;
          }
          pvVar4 = *(void **)(param_1 + 0xeae7c);
          *(MemAlcBase **)(param_1 + 0xf1e64) = pMVar18;
          *(undefined4 *)(param_1 + 0xf1e68) = 0;
          *(undefined4 *)(param_1 + 0xf1e6c) = 0x401;
          *(undefined4 *)(param_1 + 0xf1e28) = 0x401;
          *(undefined4 *)(param_1 + 0xf1e2c) = 0;
          *(undefined4 *)(param_1 + 0xf1e30) = 0;
          param_1[0xf1e50] = (MComSys)0x1;
          param_1[0xf1e51] = (MComSys)0x0;
          *(undefined4 *)(param_1 + 0xf1e58) = 0xffffffff;
          *(MComSys **)(param_1 + 0xf1e48) = param_1 + 0xf1e60;
          *(undefined4 *)(param_1 + 0xf1e4c) = 0;
          *(undefined4 *)(param_1 + 0xf1e5c) = 0xffffffff;
          Message::init((Message *)(param_1 + 0xeb0c4));
          Message::setMsgDat((Message *)(param_1 + 0xeb0c4),pvVar4);
          FUN_150142ec(param_1 + 0xeaf78);
          MoveVBase::stop((MoveVBase *)(param_1 + 0xeb044));
          *(undefined4 *)(param_1 + 0xeb060) = 0;
          *(undefined4 *)(param_1 + 0xeb064) = 0;
          *(undefined4 *)(param_1 + 0xeb068) = 0xc2c60000;
          *(undefined4 *)(param_1 + 0xeb048) = *(undefined4 *)(param_1 + 0xeb060);
          *(undefined4 *)(param_1 + 0xeb04c) = 0;
          *(undefined4 *)(param_1 + 0xeb050) = 0xc2c60000;
          *(undefined4 *)(param_1 + 0xeb0b4) = 0x401;
          puVar14 = *(undefined4 **)(param_1 + 0xeaf80);
          *(undefined4 **)(*(int *)(param_1 + 0xeaf7c) + 4) = puVar14;
          pMVar5 = param_1 + 0xeaf7c;
          *puVar14 = *(undefined4 *)(param_1 + 0xeaf7c);
          if (pMVar5 != (MComSys *)0x0) {
            *(int *)pMVar5 = *(int *)pMVar16;
            *(MComSys **)(param_1 + 0xeaf80) = pMVar16;
            *(MComSys **)(*(int *)pMVar16 + 4) = pMVar5;
            *(MComSys **)pMVar16 = pMVar5;
          }
          *(MComSys **)(param_1 + 0xf1e94) = param_1 + 0xf1eac;
          *(undefined4 *)(param_1 + 0xf1e74) = 0x401;
          param_1[0xf1e9c] = (MComSys)0x0;
          *(undefined4 *)(param_1 + 0xf1ea4) = 0x110003;
          *(undefined4 *)(param_1 + 0xf1ea8) = 0x110004;
        }
        MVar1 = (MComSys)0x2;
        goto LAB_15022d70;
      }
    }
    else if (MVar1 == (MComSys)0x2) {
      *(code **)(param_1 + 0xf84) = FUN_15022dd8;
      *(undefined4 *)(param_1 + 0xf88) = 0;
      piVar17 = *(int **)(param_1 + (char)local_238[(char)param_1[0xfd7]] * 4 + 0xf8c);
      (**(code **)(*piVar17 + 8))(piVar17,0xffffffff);
      if ((char)piVar17[5] != '\0') {
        MoveC::moveFrm((MoveC *)(param_1 + 0x4acd4),aCStack_25a + -6,16.0);
        MoveC::moveFrm((MoveC *)(param_1 + 0x4ad14),aCStack_25a + -6,16.0);
        param_1[0x4af14] = (MComSys)0x1;
        param_1[0xe904b] = (MComSys)0x3;
        *(code **)(param_1 + 0xf84) = FUN_15021dac;
        *(undefined4 *)(param_1 + 0xf88) = 0;
      }
    }
  }
  return;
}


// FUNC 0x15022dd8 FUN_15022dd8 (MainMenu)
//   size 0xc0 | file MainMenu+0x22dd8 | callers(0) | datarefs 1

void FUN_15022dd8(int param_1)

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
    *(undefined1 *)(param_1 + 0xe904b) = 3;
    *(code **)(param_1 + 0xf84) = FUN_15021dac;
    *(undefined4 *)(param_1 + 0xf88) = 0;
  }
  return;
}


// FUNC 0x15022eb0 FUN_15022eb0 (MainMenu)
//   size 0x318 | file MainMenu+0x22eb0 | callers(1) 0x15001354

void FUN_15022eb0(MComSys *param_1,MTaskBase *param_2)

{
  byte bVar1;
  uchar *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  Job *pJVar6;
  uchar uVar7;
  uint uVar8;
  uint uVar9;
  undefined4 uVar10;
  uint auStackY_248 [128];
  int in_stack_ffffffb8;
  
  Mem::Fill(param_1 + 0xeae7c,0,0xc);
  puVar2 = (uchar *)main_menu::GetBootInfo();
  uVar7 = *puVar2;
  ad::guide::Man::Init(0);
  iVar3 = main_menu::GetBootInfo();
  if ((*(byte *)(iVar3 + 0x2c) < 0x14) ||
     (iVar3 = main_menu::GetBootInfo(), 0x1d < *(byte *)(iVar3 + 0x2c))) {
    iVar3 = main_menu::GetBootInfo();
    if (0x1d < *(byte *)(iVar3 + 0x2c)) {
      iVar3 = main_menu::GetBootInfo();
      iVar4 = main_menu::GetBootInfo();
      bVar1 = *(byte *)(iVar4 + 0x2c);
      uVar9 = 0;
      uVar5 = ad::db::GetAtkGuideList(auStackY_248 + 0x80);
      uVar8 = uVar5 + in_stack_ffffffb8 * 0x10;
      for (; (uVar5 < uVar8 &&
             ((iVar4 = BattleAttackGuideDataAcs::IsExistGuide(uVar9,true), iVar4 == 0 ||
              ((uint)*(ushort *)(uVar5 + 0xc) != bVar1 + 0xafec)))); uVar5 = uVar5 + 0x10) {
        uVar9 = uVar9 + 1;
      }
      iVar4 = main_menu::GetBootInfo();
      *(undefined1 *)(iVar4 + 0x2c) = 0;
      *(undefined1 *)(iVar3 + 0x2b) = 1;
      *(undefined2 *)(iVar3 + 0x28) = 0;
      *(undefined1 *)(iVar3 + 0x2a) = 0;
      *(undefined1 *)(iVar3 + 0x20) = 0xff;
      *(undefined1 *)(iVar3 + 0x21) = 0xff;
      uVar7 = '\x06';
      *(uint *)(iVar3 + 0x24) = uVar9 | 0x4000;
    }
  }
  else {
    uVar7 = '\x04';
  }
  msys::MComSys::initBaseSys
            (param_1,param_2,0x400000,0x600000,0x600000,0x100000,0x180000,8,uVar7,false);
  msys::MComSys::entryPage(param_1,(MPageBase *)(param_1 + 0xe904c));
  msys::MComSys::entryPage(param_1,(MPageBase *)(param_1 + 0xe90dc));
  msys::MComSys::entryPage(param_1,(MPageBase *)(param_1 + 0xe9100));
  msys::MComSys::entryPage(param_1,(MPageBase *)(param_1 + 0xe90b8));
  msys::MComSys::entryPage(param_1,(MPageBase *)(param_1 + 0xe9124));
  msys::MComSys::entryPage(param_1,(MPageBase *)(param_1 + 0xe9094));
  msys::MComSys::entryPage(param_1,(MPageBase *)(param_1 + 0xe9148));
  msys::MComSys::entryPage(param_1,(MPageBase *)(param_1 + 0xe9070));
  iVar3 = *(int *)(param_1 + 4);
  uVar10 = *(undefined4 *)(param_1 + 0x278);
  pJVar6 = operator_new(0x20,(MemAlcBase *)(iVar3 + 0x55c),(char *)0x0,0);
  if (pJVar6 != (Job *)0x0) {
    *(undefined ***)pJVar6 = &vtable_for_N2ad2fw11FileContext7InitJobIPS1_EE;
    *(undefined4 *)(pJVar6 + 4) = 0;
    *(undefined4 *)(pJVar6 + 8) = uVar10;
    *(MComSys **)(pJVar6 + 0xc) = param_1 + 0xc;
    *(undefined **)(pJVar6 + 0x10) = &DAT_150250fc;
    *(undefined4 *)(pJVar6 + 0x14) = 5;
    uVar10 = *(undefined4 *)(iVar3 + 0x4d8);
    *(undefined4 *)(pJVar6 + 0x18) = *(undefined4 *)(iVar3 + 0x4d4);
    *(undefined4 *)(pJVar6 + 0x1c) = uVar10;
  }
  CtrJobMan::enqueue((CtrJobMan *)(iVar3 + 0x4dc),pJVar6);
  param_1[0xd30e0] = (MComSys)0x0;
  param_1[0xd30e1] = (MComSys)0x0;
  param_1[0xd30e2] = (MComSys)0x1;
  param_1[0xd2fe0] = (MComSys)0x1;
  param_1[0xd2fe1] = (MComSys)0x1;
  param_1[0xd2fe2] = (MComSys)0x1;
  param_1[0xbfb78] = (MComSys)0x0;
  Prim::disableDepthTest((Prim *)(param_1 + 0xac2d8));
  msys::MComSys::setupCamU(param_1);
  msys::MComSys::setupCamL(param_1);
  param_1[0xd30c9] = (MComSys)0x1;
  param_1[0xd2fc9] = (MComSys)0x1;
  uVar9 = 0;
  do {
    DataPc::init((DataPc *)(param_1 + uVar9 * 0xb0 + 0xeac64),(uchar)uVar9,
                 (DataPcPOD *)(&gGameWork + uVar9 * 0x34),(DataPcEquipFxParam *)(param_1 + 0xeae74))
    ;
    uVar9 = uVar9 + 1 & 0xff;
  } while (uVar9 < 3);
  param_1[0xe6508] = (MComSys)0x0;
  *(code **)(param_1 + 0xf84) = FUN_15022040;
  *(undefined4 *)(param_1 + 0xf88) = 0;
  return;
}


// FUNC 0x150231f4 FUN_150231f4 (MainMenu)
//   size 0x294 | file MainMenu+0x231f4 | callers(1) 0x15001354

int FUN_150231f4(MComSys *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_18;
  
  local_18 = param_4;
  puVar1 = (undefined4 *)msys::MComSys::MComSys(param_1);
  *puVar1 = &main_menu::MainMenu::vtable;
  *(undefined1 *)((int)puVar1 + 0xe904a) = 1;
  *(undefined1 *)((int)puVar1 + 0xe904b) = 0;
  puVar1 = (undefined4 *)FUN_1500f28c(puVar1 + 0x3a413);
  *puVar1 = &main_menu::MainMenu_TopPage::vtable;
  puVar1 = (undefined4 *)FUN_1500f28c(puVar1 + 9);
  *puVar1 = &main_menu::MainMenu_SettingPage::vtable;
  puVar1 = (undefined4 *)FUN_1500f28c(puVar1 + 9);
  *puVar1 = &main_menu::MainMenu_GuidePage::vtable;
  puVar1 = (undefined4 *)FUN_1500f28c(puVar1 + 9);
  *puVar1 = &main_menu::MainMenu_RecordPage::vtable;
  puVar1 = (undefined4 *)FUN_1500f28c(puVar1 + 9);
  *puVar1 = &main_menu::MainMenu_ItemPage::vtable;
  puVar1 = (undefined4 *)FUN_1500f28c(puVar1 + 9);
  *puVar1 = &main_menu::MainMenu_EquipPage::vtable;
  puVar1 = (undefined4 *)FUN_1500f28c(puVar1 + 9);
  *puVar1 = &main_menu::MainMenu_BadgePage::vtable;
  puVar1 = (undefined4 *)FUN_1500f28c(puVar1 + 9);
  *puVar1 = &main_menu::MainMenu_StatusPage::vtable;
  iVar2 = ad::fw::Resource::Resource((Resource *)(puVar1 + 9));
  iVar2 = ad::fw::Resource::Resource((Resource *)(iVar2 + 0x44));
  iVar2 = ad::fw::Resource::Resource((Resource *)(iVar2 + 0x44));
  iVar2 = ad::fw::Resource::Resource((Resource *)(iVar2 + 0x44));
  iVar2 = ad::fw::Resource::Resource((Resource *)(iVar2 + 0x44));
  iVar2 = ad::fw::Resource::Resource((Resource *)(iVar2 + 0x44));
  iVar2 = ad::fw::Resource::Resource((Resource *)(iVar2 + 0x44));
  *(undefined4 *)(iVar2 + 0x44) = 0;
  iVar2 = FUN_150153d8(iVar2 + 0x48);
  iVar2 = FUN_150153d8(iVar2 + 0x3a8);
  iVar2 = FUN_150153d8(iVar2 + 0x3a8);
  iVar2 = FUN_15012f30(iVar2 + 0x3a8);
  iVar2 = FUN_15012f30(iVar2 + 0x1c);
  iVar2 = msys::MDfxChr::MDfxChr((MDfxChr *)(iVar2 + 0x1c));
  iVar2 = msys::MDfxChr::MDfxChr((MDfxChr *)(iVar2 + 0x17c));
  iVar2 = menu_map::ParamMapPlacePos::ParamMapPlacePos((ParamMapPlacePos *)(iVar2 + 0x17c));
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(iVar2 + 0x100,FUN_15012f6c,0x27c,3);
  iVar2 = FUN_15012f6c(iVar2 + 0x774);
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(iVar2 + 0x27c,DataPc::DataPc,0xb0,3);
  iVar2 = DataPcEquipFxParam::DataPcEquipFxParam((DataPcEquipFxParam *)(iVar2 + 0x210));
  puVar1 = (undefined4 *)
           MsgDataAcsrBase::MsgDataAcsrBase
                     ((MsgDataAcsrBase *)(iVar2 + 0x14),(LMSBlockInfo *)(iVar2 + 0x40),4);
  *puVar1 = &vtable_for_20MsgDataAcsrTmplFixedILh4EE;
  puVar1 = (undefined4 *)
           MsgDataAcsrBase::MsgDataAcsrBase
                     ((MsgDataAcsrBase *)(puVar1 + 0x1b),(LMSBlockInfo *)(puVar1 + 0x26),4);
  *puVar1 = &vtable_for_20MsgDataAcsrTmplFixedILh4EE;
  iVar2 = FUN_15010740(puVar1 + 0x21);
  *(undefined4 *)(iVar2 + 0x6efc) = 0x400;
  *(undefined4 *)(iVar2 + 0x6ef8) = 0;
  *(undefined4 *)(iVar2 + 0x6f00) = 0;
  *(undefined4 *)(iVar2 + 0x6f04) = 0;
  *(undefined4 *)(iVar2 + 0x6f08) = 0;
  *(undefined4 *)(iVar2 + 0x6f10) = 6;
  *(undefined4 *)(iVar2 + 0x6f0c) = 0;
  *(undefined4 *)(iVar2 + 0x6f14) = 0;
  *(undefined1 *)(iVar2 + 0x6f18) = 0;
  *(undefined4 *)(iVar2 + 0x6f1c) = 0;
  *(undefined4 *)(iVar2 + 0x6f20) = 0;
  *(undefined1 *)(iVar2 + 0x6f24) = 1;
  *(undefined1 *)(iVar2 + 0x6f25) = 0;
  *(undefined1 *)(iVar2 + 0x6f26) = 0;
  *(undefined4 *)(iVar2 + 0x6f28) = 0;
  *(undefined4 *)(iVar2 + 0x6f2c) = 0x110003;
  *(undefined4 *)(iVar2 + 0x6f30) = 0x110004;
  *(undefined4 *)(iVar2 + 0x6f3c) = 0;
  *(undefined4 *)(iVar2 + 0x6f40) = 0x3f800000;
  *(undefined4 *)(iVar2 + 0x6f44) = 0;
  *(undefined2 *)(iVar2 + 0x6f48) = 1;
  *(undefined2 *)(iVar2 + 0x6f4a) = 0;
  iVar2 = FUN_15012f6c(iVar2 + 0x6f4c);
  local_18 = 0xff888888;
  FrameBuf::setClearColor((FrameBuf *)&gFrameBuf,&local_18);
  return iVar2 + -0xf1ec4;
}


// FUNC 0x150234f0 main_menu::MainMenu::vfunc_0x4 (MainMenu)
//   size 0x10 | file MainMenu+0x234f0 | callers(0) | datarefs 1

void main_menu::MainMenu::vfunc_0x4(void)

{
  void *pvVar1;
  
  pvVar1 = (void *)vfunc_0x0();
  operator_delete(pvVar1);
  return;
}


// FUNC 0x15023500 MemAlcH::vfunc_0x10 (MainMenu)
//   size 0x4 | file MainMenu+0x23500 | callers(0) | datarefs 1

void MemAlcH::vfunc_0x10(void)

{
  return;
}


// FUNC 0x15023504 MemAlcH::vfunc_0x14 (MainMenu)
//   size 0x4 | file MainMenu+0x23504 | callers(0) | datarefs 1

void MemAlcH::vfunc_0x14(void)

{
  return;
}


// FUNC 0x15023508 nn::fs::FileInputStream::vfunc_0x20 (MainMenu)
//   size 0x8 | file MainMenu+0x23508 | callers(0) | datarefs 1

void nn::fs::FileInputStream::vfunc_0x20(int param_1,longlong *param_2)

{
  detail::FileBase::TryGetSize((FileBase *)(param_1 + 4),param_2);
  return;
}


// FUNC 0x15023510 nn::fs::FileInputStream::vfunc_0x14 (MainMenu)
//   size 0x8 | file MainMenu+0x23510 | callers(0) | datarefs 1

undefined8 nn::fs::FileInputStream::vfunc_0x14(int param_1)

{
  return *(undefined8 *)(param_1 + 8);
}


// FUNC 0x15023518 nn::fs::FileInputStream::vfunc_0x10 (MainMenu)
//   size 0x14 | file MainMenu+0x23518 | callers(0) | datarefs 1

undefined4 nn::fs::FileInputStream::vfunc_0x10(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 0xc);
  *param_2 = *(undefined4 *)(param_1 + 8);
  param_2[1] = uVar1;
  return 0;
}


// FUNC 0x1502352c nn::fs::FileInputStream::vfunc_0x24 (MainMenu)
//   size 0x2c | file MainMenu+0x2352c | callers(0) | datarefs 1

longlong nn::fs::FileInputStream::vfunc_0x24(int param_1)

{
  int iVar1;
  longlong local_10;
  
  iVar1 = detail::FileBase::TryGetSize((FileBase *)(param_1 + 4),&local_10);
  if (iVar1 < 0) {
    err::CTR::ThrowFatalErrAll(iVar1,0x15023548);
  }
  return local_10;
}


// FUNC 0x15023558 FUN_15023558 (MainMenu)
//   size 0x2c | file MainMenu+0x23558 | callers(0) | datarefs 1

bool FUN_15023558(int *param_1,uint param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 8))();
  return (uVar1 & param_3) == param_2;
}


// FUNC 0x15023584 FUN_15023584 (MainMenu)
//   size 0x8 | file MainMenu+0x23584 | callers(0) | datarefs 1

undefined4 FUN_15023584(void)

{
  return 0;
}


// FUNC 0x1502358c FUN_1502358c (MainMenu)
//   size 0x8 | file MainMenu+0x2358c | callers(0) | datarefs 12

undefined4 FUN_1502358c(void)

{
  return 2;
}


// FUNC 0x15023594 FUN_15023594 (MainMenu)
//   size 0x8 | file MainMenu+0x23594 | callers(0) | datarefs 2

undefined4 FUN_15023594(void)

{
  return 1;
}


// FUNC 0x1502359c main_menu::MainMenu_StatusPage::Core::ExpMsgWnd::vfunc_0x1c (MainMenu)
//   size 0x8 | file MainMenu+0x2359c | callers(0) | datarefs 1

undefined4 main_menu::MainMenu_StatusPage::Core::ExpMsgWnd::vfunc_0x1c(void)

{
  return 7;
}


// FUNC 0x150235a4 main_menu::MainMenuPageBase::Core::vfunc_0xc (MainMenu)
//   size 0x10 | file MainMenu+0x235a4 | callers(0) | datarefs 9

bool main_menu::MainMenuPageBase::Core::vfunc_0xc(undefined4 param_1,int param_2)

{
  return *(char *)(param_2 + 0x12) != '\0';
}


// FUNC 0x150235b4 main_menu::MainMenu_ItemPage::vfunc_0x34 (MainMenu)
//   size 0x1c | file MainMenu+0x235b4 | callers(0) | datarefs 1

bool main_menu::MainMenu_ItemPage::vfunc_0x34(int param_1,int param_2)

{
  bool bVar1;
  
  bVar1 = *(char *)(param_2 + 0x12) != '\0';
  if (bVar1) {
    param_1 = *(int *)(param_1 + 0x20);
  }
  return bVar1 && param_1 != 0;
}


// FUNC 0x150235d0 main_menu::MainMenu_BadgePage::Core::MBadgeLytCtrl::vfunc_0x20 (MainMenu)
//   size 0x28 | file MainMenu+0x235d0 | callers(0) | datarefs 1

bool main_menu::MainMenu_BadgePage::Core::MBadgeLytCtrl::vfunc_0x20(int param_1,short param_2)

{
  char cVar1;
  int iVar2;
  
  iVar2 = msys::MLyt::getAnim(*(MLyt **)(param_1 + 8),param_2);
  iVar2 = *(int *)(iVar2 + 0x14);
  cVar1 = '\0';
  if (iVar2 != 0) {
    cVar1 = *(char *)(iVar2 + 0x14);
  }
  return iVar2 != 0 && cVar1 != '\0';
}


// FUNC 0x150235f8 main_menu::MainMenu_BadgePage::Core::MBadgeLytCtrl::vfunc_0x24 (MainMenu)
//   size 0x8 | file MainMenu+0x235f8 | callers(0) | datarefs 1

void main_menu::MainMenu_BadgePage::Core::MBadgeLytCtrl::vfunc_0x24(int param_1)

{
  msys::MLyt::isEnableAnime(*(MLyt **)(param_1 + 8));
  return;
}


// FUNC 0x15023600 main_menu::MainMenu_BadgePage::Core::MBadgeLytCtrl::vfunc_0x2c (MainMenu)
//   size 0x44 | file MainMenu+0x23600 | callers(0) | datarefs 1

undefined4 main_menu::MainMenu_BadgePage::Core::MBadgeLytCtrl::vfunc_0x2c(int param_1,short param_2)

{
  int iVar1;
  uint in_fpscr;
  undefined4 uVar2;
  
  iVar1 = msys::MLyt::getAnim(*(MLyt **)(param_1 + 8),param_2);
  if (*(int *)(iVar1 + 0x14) == 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = msys::MLyt::getAnim(*(MLyt **)(param_1 + 8),param_2);
    uVar2 = ad::lyt::AnimTransform::GetFrameSize(*(AnimTransform **)(iVar1 + 0x14));
    uVar2 = VectorUnsignedToFloat(uVar2,(byte)(in_fpscr >> 0x16) & 3);
  }
  return uVar2;
}


// FUNC 0x15023648 main_menu::MainMenu_BadgePage::Core::MBadgeLytCtrl::vfunc_0x38 (MainMenu)
//   size 0x38 | file MainMenu+0x23648 | callers(0) | datarefs 1

undefined4 main_menu::MainMenu_BadgePage::Core::MBadgeLytCtrl::vfunc_0x38(int param_1,short param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = msys::MLyt::getAnim(*(MLyt **)(param_1 + 8),param_2);
  if (*(int *)(iVar1 + 0x14) == 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = msys::MLyt::getAnim(*(MLyt **)(param_1 + 8),param_2);
    uVar2 = *(undefined4 *)(iVar1 + 8);
  }
  return uVar2;
}


// FUNC 0x15023684 main_menu::MainMenu_BadgePage::Core::MBadgeLytCtrl::vfunc_0x28 (MainMenu)
//   size 0x48 | file MainMenu+0x23684 | callers(0) | datarefs 1

byte main_menu::MainMenu_BadgePage::Core::MBadgeLytCtrl::vfunc_0x28(int *param_1)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = 0;
  do {
    iVar2 = (**(code **)(*param_1 + 0x20))(param_1,bVar1);
    if (iVar2 != 0) {
      return bVar1;
    }
    bVar1 = bVar1 + 1;
  } while (bVar1 < 0xc);
  return 0;
}


// FUNC 0x150236cc main_menu::MainMenu_BadgePage::Core::MBadgeLytCtrl::vfunc_0x30 (MainMenu)
//   size 0x38 | file MainMenu+0x236cc | callers(0) | datarefs 1

undefined4 main_menu::MainMenu_BadgePage::Core::MBadgeLytCtrl::vfunc_0x30(int param_1,short param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = msys::MLyt::getAnim(*(MLyt **)(param_1 + 8),param_2);
  if (*(int *)(iVar1 + 0x14) == 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = msys::MLyt::getAnim(*(MLyt **)(param_1 + 8),param_2);
    uVar2 = *(undefined4 *)(iVar1 + 4);
  }
  return uVar2;
}


// FUNC 0x15023708 main_menu::MainMenu_BadgePage::Core::MBadgeLytCtrl::vfunc_0x18 (MainMenu)
//   size 0x30 | file MainMenu+0x23708 | callers(0) | datarefs 1

bool main_menu::MainMenu_BadgePage::Core::MBadgeLytCtrl::vfunc_0x18(int param_1,short param_2)

{
  bool bVar1;
  uint uVar2;
  
  uVar2 = msys::MLyt::getAnim(*(MLyt **)(param_1 + 8),param_2);
  bVar1 = *(float *)(uVar2 + 0xc) != 0.0;
  if (bVar1) {
    uVar2 = (uint)*(byte *)(uVar2 + 0x12);
  }
  return bVar1 && (uVar2 & 1) != 0;
}


// FUNC 0x1502373c main_menu::MainMenu_BadgePage::Core::MBadgeLytCtrl::vfunc_0x1c (MainMenu)
//   size 0x10 | file MainMenu+0x2373c | callers(0) | datarefs 1

void main_menu::MainMenu_BadgePage::Core::MBadgeLytCtrl::vfunc_0x1c(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x15023748. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(param_1 + 8) + 0x20))();
  return;
}


// FUNC 0x1502374c FUN_1502374c (MainMenu)
//   size 0x1c | file MainMenu+0x2374c | callers(1) 0x150153d8

void FUN_1502374c(uint *param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = param_2 & 0xff | (param_2 & 0xff) << 8;
  uVar1 = uVar1 | uVar1 << 0x10;
  *param_1 = uVar1;
  param_1[1] = uVar1;
  param_1[2] = uVar1;
  return;
}


// FUNC 0x150237b0 MainMenu::nnroControlObject_ (MainMenu)
//   size 0x74 | file MainMenu+0x237b0 | callers(0)

undefined4 MainMenu::nnroControlObject_(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined *puVar2;
  
  switch(param_2) {
  case 0:
    uVar1 = 0;
    break;
  case 1:
    DAT_15036418 = param_1;
    return 0;
  case 2:
    uVar1 = DAT_15036418;
    break;
  case 3:
    *param_1 = &DAT_150239c8;
    puVar2 = &DAT_150239cc;
    goto LAB_15023810;
  case 4:
    *param_1 = &DAT_1502848c;
    puVar2 = &DAT_1502848c;
LAB_15023810:
    param_1[1] = puVar2;
    return 0;
  default:
    return 0xd8e12c21;
  }
  *param_1 = uVar1;
  return 0;
}


// FUNC 0x15023860 FUN_15023860 (MainMenu)
//   size 0xac | file MainMenu+0x23860 | callers(0) | datarefs 1

void FUN_15023860(int param_1)

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


// FUNC 0x1502390c ->operator.delete (MainMenu)
//   size 0x4 | file MainMenu+0x2390c | callers(0) | datarefs 1
// veneer/thunk -> 0x00286514 operator.delete (static)

// FUNC 0x15023910 FUN_15023910 (MainMenu)
//   size 0x4 | file MainMenu+0x23910 | callers(0) | datarefs 1

void FUN_15023910(void)

{
  return;
}


// FUNC 0x15023914 FUN_15023914 (MainMenu)
//   size 0x28 | file MainMenu+0x23914 | callers(0) | datarefs 1

void FUN_15023914(float param_1,MCursorBase *param_2,MLyt *param_3)

{
  MCursorBase *pMVar1;
  int iVar2;
  
  msys::MCursorBase::init(param_2,param_3,param_1);
  iVar2 = 4;
  pMVar1 = param_2 + 0x30;
  do {
    iVar2 = iVar2 + -1;
    *(undefined4 *)pMVar1 = 0;
    pMVar1 = pMVar1 + 4;
  } while (iVar2 != 0);
  return;
}


// FUNC 0x1502393c FUN_1502393c (MainMenu)
//   size 0x10 | file MainMenu+0x2393c | callers(0) | datarefs 1

void FUN_1502393c(MCursorBase *param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)msys::MCursorBase::~MCursorBase(param_1);
  operator_delete(pvVar1);
  return;
}


// FUNC 0x1502394c ->msys::MCursorBase::~MCursorBase (MainMenu)
//   size 0x4 | file MainMenu+0x2394c | callers(0) | datarefs 1
// veneer/thunk -> 0x00324600 msys::MCursorBase::~MCursorBase (static)

// FUNC 0x15023950 FUN_15023950 (MainMenu)
//   size 0x28 | file MainMenu+0x23950 | callers(0) | datarefs 1

void FUN_15023950(float param_1,MCursorBase *param_2,MLyt *param_3)

{
  MCursorBase *pMVar1;
  int iVar2;
  
  msys::MCursorBase::init(param_2,param_3,param_1);
  iVar2 = 6;
  pMVar1 = param_2 + 0x30;
  do {
    iVar2 = iVar2 + -1;
    *(undefined4 *)pMVar1 = 0;
    pMVar1 = pMVar1 + 4;
  } while (iVar2 != 0);
  return;
}


// FUNC 0x15023978 FUN_15023978 (MainMenu)
//   size 0x10 | file MainMenu+0x23978 | callers(0) | datarefs 1

void FUN_15023978(MCursorBase *param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)msys::MCursorBase::~MCursorBase(param_1);
  operator_delete(pvVar1);
  return;
}


// FUNC 0x15023988 ->msys::MCursorBase::~MCursorBase (MainMenu)
//   size 0x4 | file MainMenu+0x23988 | callers(0) | datarefs 1
// veneer/thunk -> 0x00324600 msys::MCursorBase::~MCursorBase (static)

// FUNC 0x1502398c FUN_1502398c (MainMenu)
//   size 0x28 | file MainMenu+0x2398c | callers(0) | datarefs 1

void FUN_1502398c(float param_1,MCursorBase *param_2,MLyt *param_3)

{
  MCursorBase *pMVar1;
  int iVar2;
  
  msys::MCursorBase::init(param_2,param_3,param_1);
  iVar2 = 7;
  pMVar1 = param_2 + 0x30;
  do {
    iVar2 = iVar2 + -1;
    *(undefined4 *)pMVar1 = 0;
    pMVar1 = pMVar1 + 4;
  } while (iVar2 != 0);
  return;
}


// FUNC 0x150239b4 FUN_150239b4 (MainMenu)
//   size 0x10 | file MainMenu+0x239b4 | callers(0) | datarefs 1

void FUN_150239b4(MCursorBase *param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)msys::MCursorBase::~MCursorBase(param_1);
  operator_delete(pvVar1);
  return;
}


// FUNC 0x150239c4 ->msys::MCursorBase::~MCursorBase (MainMenu)
//   size 0x4 | file MainMenu+0x239c4 | callers(0) | datarefs 1
// veneer/thunk -> 0x00324600 msys::MCursorBase::~MCursorBase (static)

