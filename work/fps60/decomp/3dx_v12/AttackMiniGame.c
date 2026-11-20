// fps60 TG decompiled C: 3dx_v12.code.bin module AttackMiniGame part 1 (Ghidra 12.2, ARM:LE:32:v6:hardfp)
// Addresses: static = runtime address; CRO = fixed analysis base (crolink.py), NOT runtime.

// FUNC 0x10000180 ->operator.new (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x180 | callers(3) 0x100007a8 0x100011f4 0x100074e0
// veneer/thunk -> 0x00287d40 operator.new (static)

// FUNC 0x10000188 ->TaskMan::entry (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x188 | callers(1) 0x100007a8
// veneer/thunk -> 0x00287b18 TaskMan::entry (static)

// FUNC 0x10000190 ->MsgDataAcsrBase::~MsgDataAcsrBase (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x190 | callers(3) 0x100007e8 0x100007f8 0x10003e74
// veneer/thunk -> 0x0026fdb4 MsgDataAcsrBase::~MsgDataAcsrBase (static)

// FUNC 0x10000198 ->operator.delete (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x198 | callers(16) 0x10000860 0x10007ae0 0x100007e8 0x1000090c 0x10000a58 0x10000b88 0x10000b98 0x10000bec ...
// veneer/thunk -> 0x00286514 operator.delete (static)

// FUNC 0x100001a0 ->nn::fs::detail::FileBase::TrySetPosition (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x1a0 | callers(2) 0x10000868 0x1000088c
// veneer/thunk -> 0x0027ec28 nn::fs::detail::FileBase::TrySetPosition (static)

// FUNC 0x100001a8 ->nn::err::CTR::ThrowFatalErrAll (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x1a8 | callers(5) 0x10000894 0x10007908 0x10000868 0x100008c0 0x10000d18
// veneer/thunk -> 0x00286530 nn::err::CTR::ThrowFatalErrAll (static)

// FUNC 0x100001b0 ->nn::fs::detail::FileBase::TryRead (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x1b0 | callers(3) 0x10000894 0x100008ec 0x10000d18
// veneer/thunk -> 0x00286488 nn::fs::detail::FileBase::TryRead (static)

// FUNC 0x100001b8 ->nn::fs::detail::FileBase::TrySeek (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x1b8 | callers(2) 0x100008c0 0x100008f4
// veneer/thunk -> 0x002854d0 nn::fs::detail::FileBase::TrySeek (static)

// FUNC 0x100001c0 ->nndbgPanic (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x1c0 | callers(3) 0x1000090c 0x1000094c 0x10000d18
// veneer/thunk -> 0x0028642c nndbgPanic (static)

// FUNC 0x100001c8 ->nn::fs::CTR::MPCore::detail::UserFileSystem::CloseFile (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x1c8 | callers(3) 0x1000090c 0x1000094c 0x10000d18
// veneer/thunk -> 0x00286410 nn::fs::CTR::MPCore::detail::UserFileSystem::CloseFile (static)

// FUNC 0x100001d0 ->ad::ui::UIListWindowPlusLyt::~UIListWindowPlusLyt (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x1d0 | callers(7) 0x10000a58 0x10000a68 0x10000b98 0x10000bbc 0x10005ec4 0x10005f30 0x1000719c
// veneer/thunk -> 0x0025a3fc ad::ui::UIListWindowPlusLyt::~UIListWindowPlusLyt (static)

// FUNC 0x100001d8 ->MoveVBase::update (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x1d8 | callers(1) 0x10000a7c
// veneer/thunk -> 0x002597d4 MoveVBase::update (static)

// FUNC 0x100001e0 ->CtrBtn::get (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x1e0 | callers(1) 0x10000a7c
// veneer/thunk -> 0x003627f0 CtrBtn::get (static)

// FUNC 0x100001e8 ->Message::func (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x1e8 | callers(1) 0x10000a7c
// veneer/thunk -> 0x00273be0 Message::func (static)

// FUNC 0x100001f0 ->msys::MRenderQueueBase::enqueueMsg (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x1f0 | callers(1) 0x10000b58
// veneer/thunk -> 0x00328df0 msys::MRenderQueueBase::enqueueMsg (static)

// FUNC 0x100001f8 ->msys::MListWndPBase::~MListWndPBase (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x1f8 | callers(5) 0x10000b98 0x10005ec4 0x1000719c 0x10000bbc 0x10005f30
// veneer/thunk -> 0x003288a0 msys::MListWndPBase::~MListWndPBase (static)

// FUNC 0x10000200 ->msys::MPageBase::enqueueLowerChr (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x200 | callers(1) 0x10000bdc
// veneer/thunk -> 0x00334104 msys::MPageBase::enqueueLowerChr (static)

// FUNC 0x10000208 ->msys::MPageBase::enqueueUpperChr (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x208 | callers(1) 0x10000be4
// veneer/thunk -> 0x00334184 msys::MPageBase::enqueueUpperChr (static)

// FUNC 0x10000210 ->__aeabi_vec_dtor (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x210 | callers(5) 0x100040e4 0x10000bec 0x10000c28 0x10003e74 0x1000719c
// veneer/thunk -> 0x00288230 __aeabi_vec_dtor (static)

// FUNC 0x10000218 ->MoveVBase::~MoveVBase (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x218 | callers(3) 0x100040e4 0x10000bec 0x10000c28
// veneer/thunk -> 0x002535e8 MoveVBase::~MoveVBase (static)

// FUNC 0x10000220 ->msys::MCamera::getProjMtx (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x220 | callers(2) 0x10000cd4 0x10000c60
// veneer/thunk -> 0x00206718 msys::MCamera::getProjMtx (static)

// FUNC 0x10000228 ->msys::MCamera::getViewMtx (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x228 | callers(1) 0x10000c60
// veneer/thunk -> 0x002068e4 msys::MCamera::getViewMtx (static)

// FUNC 0x10000230 ->ad::fw::TaskBase::setULcdCameraInfoBase (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x230 | callers(1) 0x10000c60
// veneer/thunk -> 0x0010b438 ad::fw::TaskBase::setULcdCameraInfoBase (static)

// FUNC 0x10000238 ->Grp::SetupProjLcdOrtho (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x238 | callers(1) 0x10000c60
// veneer/thunk -> 0x00284fc0 Grp::SetupProjLcdOrtho (static)

// FUNC 0x10000240 ->msys::MComSys::funcCalcMainNomal (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x240 | callers(1) 0x10000c60
// veneer/thunk -> 0x0032f13c msys::MComSys::funcCalcMainNomal (static)

// FUNC 0x10000248 ->msys::MComSys::funcDrawLower (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x248 | callers(1) 0x10000cd4
// veneer/thunk -> 0x0032e2b8 msys::MComSys::funcDrawLower (static)

// FUNC 0x10000250 ->msys::MComSys::funcDrawUpper (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x250 | callers(1) 0x10000d14
// veneer/thunk -> 0x0032e760 msys::MComSys::funcDrawUpper (static)

// FUNC 0x10000258 ->ad::lyt::LytDrawSys::GetInst (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x258 | callers(2) 0x10000d18 0x10006788
// veneer/thunk -> 0x00287f58 ad::lyt::LytDrawSys::GetInst (static)

// FUNC 0x10000260 ->ad::lyt::Initialize (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x260 | callers(2) 0x10000d18 0x10006788
// veneer/thunk -> 0x002855e0 ad::lyt::Initialize (static)

// FUNC 0x10000268 ->msys::MComSys::readLytNum (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x268 | callers(1) 0x10000d18
// veneer/thunk -> 0x0032db14 msys::MComSys::readLytNum (static)

// FUNC 0x10000270 ->ad::fw::TaskBase::readLyt (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x270 | callers(2) 0x10000d18 0x10006788
// veneer/thunk -> 0x00249e48 ad::fw::TaskBase::readLyt (static)

// FUNC 0x10000278 ->operator.new[] (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x278 | callers(1) 0x10000d18
// veneer/thunk -> 0x00283558 operator.new[] (static)

// FUNC 0x10000280 ->MessageSys::GetPath (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x280 | callers(1) 0x10000d18
// veneer/thunk -> 0x00132a2c MessageSys::GetPath (static)

// FUNC 0x10000288 ->nn::fs::CTR::MPCore::detail::UserFileSystem::TryOpenFile (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x288 | callers(1) 0x10000d18
// veneer/thunk -> 0x0028598c nn::fs::CTR::MPCore::detail::UserFileSystem::TryOpenFile (static)

// FUNC 0x10000290 ->nn::fs::detail::FileBase::TryGetSize (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x290 | callers(3) 0x10007908 0x100078e4 0x10000d18
// veneer/thunk -> 0x00286568 nn::fs::detail::FileBase::TryGetSize (static)

// FUNC 0x10000298 ->MsgDataAcsrBase::init (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x298 | callers(1) 0x10000d18
// veneer/thunk -> 0x00285b88 MsgDataAcsrBase::init (static)

// FUNC 0x100002a0 ->operator.delete[] (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x2a0 | callers(1) 0x10000d18
// veneer/thunk -> 0x0028829c operator.delete[] (static)

// FUNC 0x100002a8 ->ad::lyt::LytResourceMan::init (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x2a8 | callers(3) 0x10006cb0 0x1000149c 0x10000fb4
// veneer/thunk -> 0x00250d1c ad::lyt::LytResourceMan::init (static)

// FUNC 0x100002b0 ->ad::fw::Resource::getFileData (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x2b0 | callers(2) 0x1000149c 0x10000fb4
// veneer/thunk -> 0x00251d10 ad::fw::Resource::getFileData (static)

// FUNC 0x100002b8 ->ad::lyt::LytResourceMan::registerArc (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x2b8 | callers(2) 0x1000149c 0x10000fb4
// veneer/thunk -> 0x0015c910 ad::lyt::LytResourceMan::registerArc (static)

// FUNC 0x100002c0 ->msys::MLytNumRes::init (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x2c0 | callers(1) 0x10000fb4
// veneer/thunk -> 0x003240f4 msys::MLytNumRes::init (static)

// FUNC 0x100002c8 ->msys::MLyt::init (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x2c8 | callers(2) 0x1000149c 0x10000fb4
// veneer/thunk -> 0x0032c3a0 msys::MLyt::init (static)

// FUNC 0x100002d0 ->msys::MLyt::createLyt (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x2d0 | callers(2) 0x1000149c 0x10000fb4
// veneer/thunk -> 0x0032c78c msys::MLyt::createLyt (static)

// FUNC 0x100002d8 ->MoveVBase::stop (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x2d8 | callers(10) 0x10003648 0x10006944 0x1000149c 0x100039d8 0x10003b24 0x10000fb4 0x100053bc 0x10003178 ...
// veneer/thunk -> 0x00259dd8 MoveVBase::stop (static)

// FUNC 0x100002e0 ->MoveC::moveFrm (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x2e0 | callers(4) 0x10004818 0x10003320 0x1000112c 0x10002bec
// veneer/thunk -> 0x0026bc74 MoveC::moveFrm (static)

// FUNC 0x100002e8 ->msys::MComSys::initBaseSys (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x2e8 | callers(1) 0x100011f4
// veneer/thunk -> 0x0032db84 msys::MComSys::initBaseSys (static)

// FUNC 0x100002f0 ->msys::MComSys::entryPage (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x2f0 | callers(1) 0x100011f4
// veneer/thunk -> 0x0032f548 msys::MComSys::entryPage (static)

// FUNC 0x100002f8 ->Prim::enableDepthTest (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x2f8 | callers(1) 0x100011f4
// veneer/thunk -> 0x0026cce8 Prim::enableDepthTest (static)

// FUNC 0x10000300 ->CtrJobMan::enqueue (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x300 | callers(1) 0x100011f4
// veneer/thunk -> 0x0026dbe8 CtrJobMan::enqueue (static)

// FUNC 0x10000308 ->msys::MComSys::setupCamU (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x308 | callers(1) 0x100011f4
// veneer/thunk -> 0x0032f674 msys::MComSys::setupCamU (static)

// FUNC 0x10000310 ->msys::MComSys::setupCamL (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x310 | callers(1) 0x100011f4
// veneer/thunk -> 0x0032f570 msys::MComSys::setupCamL (static)

// FUNC 0x10000318 ->msys::MComSys::MComSys (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x318 | callers(1) 0x10001380
// veneer/thunk -> 0x0032f7a4 msys::MComSys::MComSys (static)

// FUNC 0x10000320 ->MsgDataAcsrBase::MsgDataAcsrBase (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x320 | callers(1) 0x10001380
// veneer/thunk -> 0x0024b3b8 MsgDataAcsrBase::MsgDataAcsrBase (static)

// FUNC 0x10000328 ->ad::fw::Resource::Resource (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x328 | callers(2) 0x10001380 0x10006cb0
// veneer/thunk -> 0x00250588 ad::fw::Resource::Resource (static)

// FUNC 0x10000330 ->__aeabi_vec_ctor_nocookie_nodtor (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x330 | callers(3) 0x10001380 0x10003ff8 0x10006cb0
// veneer/thunk -> 0x0028771c __aeabi_vec_ctor_nocookie_nodtor (static)

// FUNC 0x10000338 ->msys::MLyt::build (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x338 | callers(1) 0x1000149c
// veneer/thunk -> 0x0032c460 msys::MLyt::build (static)

// FUNC 0x10000340 ->msys::MLyt::createLyt (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x340 | callers(1) 0x1000149c
// veneer/thunk -> 0x0032c8c0 msys::MLyt::createLyt (static)

// FUNC 0x10000348 ->Backup::errorCode (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x348 | callers(2) 0x10001c08 0x100016d4
// veneer/thunk -> 0x002063b8 Backup::errorCode (static)

// FUNC 0x10000350 ->Backup::isBusyFormat (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x350 | callers(1) 0x100016d4
// veneer/thunk -> 0x00339378 Backup::isBusyFormat (static)

// FUNC 0x10000358 ->Backup::mount (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x358 | callers(1) 0x100016d4
// veneer/thunk -> 0x00339d0c Backup::mount (static)

// FUNC 0x10000360 ->Backup::rewriteSaveData (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x360 | callers(1) 0x100016d4
// veneer/thunk -> 0x00339c0c Backup::rewriteSaveData (static)

// FUNC 0x10000368 ->CtrFS::unmountSaveData (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x368 | callers(1) 0x100016d4
// veneer/thunk -> 0x00207f3c CtrFS::unmountSaveData (static)

// FUNC 0x10000370 ->Backup::format (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x370 | callers(2) 0x10005318 0x100016d4
// veneer/thunk -> 0x00339d34 Backup::format (static)

// FUNC 0x10000378 ->GameMain::Back (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x378 | callers(2) 0x100077f8 0x100017d8
// veneer/thunk -> 0x0033e354 GameMain::Back (static)

// FUNC 0x10000380 ->msys::MListWndPBase::isTpNeutral (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x380 | callers(2) 0x1000755c 0x100017e0
// veneer/thunk -> 0x003620c8 msys::MListWndPBase::isTpNeutral (static)

// FUNC 0x10000388 ->msys::MListWndPBase::getCurNo (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x388 | callers(3) 0x1000149c 0x100051c0 0x100017e0
// veneer/thunk -> 0x003620e0 msys::MListWndPBase::getCurNo (static)

// FUNC 0x10000390 ->ad::db::GetPcAttack (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x390 | callers(6) 0x10006944 0x1000149c 0x10003b24 0x10005918 0x10005f98 0x100017e0
// veneer/thunk -> 0x00237260 ad::db::GetPcAttack (static)

// FUNC 0x10000398 ->msys::MListWndPBase::getCurItem (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x398 | callers(1) 0x100017e0
// veneer/thunk -> 0x0025a0bc msys::MListWndPBase::getCurItem (static)

// FUNC 0x100003a0 ->msys::MListWndPBase::getSelectItem (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x3a0 | callers(1) 0x100017e0
// veneer/thunk -> 0x003285f0 msys::MListWndPBase::getSelectItem (static)

// FUNC 0x100003a8 ->msys::MLyt::getAnim (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x3a8 | callers(4) 0x100065ec 0x100017e0 0x100042dc 0x10004594
// veneer/thunk -> 0x0032c678 msys::MLyt::getAnim (static)

// FUNC 0x100003b0 ->ad::lyt::LytAnim::stopAndSetFrm (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x3b0 | callers(6) 0x10006944 0x1000149c 0x10003b24 0x10005918 0x100065ec 0x100017e0
// veneer/thunk -> 0x0026fe44 ad::lyt::LytAnim::stopAndSetFrm (static)

// FUNC 0x100003b8 ->msys::MLyt::createAnime (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x3b8 | callers(1) 0x100017e0
// veneer/thunk -> 0x00206c48 msys::MLyt::createAnime (static)

// FUNC 0x100003c0 ->msys::MLyt::createAnimeAutoSlot (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x3c0 | callers(10) 0x10004818 0x1000149c 0x100065ec 0x100030c0 0x10004614 0x100053bc 0x100017e0 0x100042dc ...
// veneer/thunk -> 0x0032c308 msys::MLyt::createAnimeAutoSlot (static)

// FUNC 0x100003c8 ->msys::MLyt::getAnime (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x3c8 | callers(5) 0x100065ec 0x100053bc 0x10003178 0x100017e0 0x10001d24
// veneer/thunk -> 0x0032c738 msys::MLyt::getAnime (static)

// FUNC 0x100003d0 ->LMS_GetTextIndexByLabel (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x3d0 | callers(6) 0x1000149c 0x10003b24 0x10005918 0x10005f98 0x100017e0 0x10001d24
// veneer/thunk -> 0x0027616c LMS_GetTextIndexByLabel (static)

// FUNC 0x100003d8 ->LMS_GetText (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x3d8 | callers(6) 0x1000149c 0x10003b24 0x10005918 0x10005f98 0x100017e0 0x10001d24
// veneer/thunk -> 0x0027660c LMS_GetText (static)

// FUNC 0x100003e0 ->msys::MMsg::playStr (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x3e0 | callers(4) 0x1000149c 0x10003b24 0x100017e0 0x10001d24
// veneer/thunk -> 0x0032ce0c msys::MMsg::playStr (static)

// FUNC 0x100003e8 ->msys::MLyt::playAnimeFromNo (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x3e8 | callers(16) 0x100044dc 0x100065ec 0x10003320 0x100053bc 0x10002b28 0x10003044 0x100046d0 0x100017e0 ...
// veneer/thunk -> 0x0032bf98 msys::MLyt::playAnimeFromNo (static)

// FUNC 0x100003f0 ->Backup::isBusyWriting (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x3f0 | callers(1) 0x10001c08
// veneer/thunk -> 0x00339558 Backup::isBusyWriting (static)

// FUNC 0x100003f8 ->Backup::term (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x3f8 | callers(1) 0x10001c08
// veneer/thunk -> 0x00339c84 Backup::term (static)

// FUNC 0x10000400 ->Message::close (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x400 | callers(2) 0x10001c08 0x10002a3c
// veneer/thunk -> 0x0024dcc8 Message::close (static)

// FUNC 0x10000408 ->ad::lyt::LytLocalize::LytLocalize (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x408 | callers(2) 0x1000149c 0x10005918
// veneer/thunk -> 0x002563d4 ad::lyt::LytLocalize::LytLocalize (static)

// FUNC 0x10000410 ->ad::lyt::LytLocalize::localize (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x410 | callers(2) 0x1000149c 0x10005918
// veneer/thunk -> 0x00264e08 ad::lyt::LytLocalize::localize (static)

// FUNC 0x10000418 ->Message::init (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x418 | callers(1) 0x1000149c
// veneer/thunk -> 0x0033dc2c Message::init (static)

// FUNC 0x10000420 ->Message::setMsgDat (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x420 | callers(1) 0x1000149c
// veneer/thunk -> 0x0033ddc8 Message::setMsgDat (static)

// FUNC 0x10000428 ->msys::MLyt::attachMChr (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x428 | callers(6) 0x10006944 0x1000149c 0x10002cec 0x100053bc 0x10003178 0x10004a28
// veneer/thunk -> 0x00207468 msys::MLyt::attachMChr (static)

// FUNC 0x10000430 ->MessageSimple::init (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x430 | callers(2) 0x1000149c 0x10002cec
// veneer/thunk -> 0x002736b4 MessageSimple::init (static)

// FUNC 0x10000438 ->ad::ctrl::ButtonGroup::FindButtonByName (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x438 | callers(1) 0x1000149c
// veneer/thunk -> 0x00256680 ad::ctrl::ButtonGroup::FindButtonByName (static)

// FUNC 0x10000440 ->ad::ctrl::AnimButton::SetStateChangeCallback (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x440 | callers(1) 0x1000149c
// veneer/thunk -> 0x00256674 ad::ctrl::AnimButton::SetStateChangeCallback (static)

// FUNC 0x10000448 ->msys::MLyt::getParts (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x448 | callers(1) 0x1000149c
// veneer/thunk -> 0x002073ec msys::MLyt::getParts (static)

// FUNC 0x10000450 ->ad::fw::TaskBase::isFps30 (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x450 | callers(1) 0x1000149c
// veneer/thunk -> 0x0025edd0 ad::fw::TaskBase::isFps30 (static)

// FUNC 0x10000458 ->msys::MCursorBase::setVisible (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x458 | callers(4) 0x1000649c 0x1000149c 0x100056e4 0x100057b0
// veneer/thunk -> 0x00324454 msys::MCursorBase::setVisible (static)

// FUNC 0x10000460 ->msys::MLyt::setAnimeInfo (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x460 | callers(3) 0x1000149c 0x100030c0 0x10005280
// veneer/thunk -> 0x0032bc40 msys::MLyt::setAnimeInfo (static)

// FUNC 0x10000468 ->ad::lyt::LytAnim::init (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x468 | callers(5) 0x10006944 0x1000149c 0x10002cec 0x10005918 0x100065ec
// veneer/thunk -> 0x00264f04 ad::lyt::LytAnim::init (static)

// FUNC 0x10000470 ->ad::lyt::AnimTransform::GetFrameSize (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x470 | callers(4) 0x10006944 0x1000149c 0x10003b24 0x10005918
// veneer/thunk -> 0x0026fe38 ad::lyt::AnimTransform::GetFrameSize (static)

// FUNC 0x10000478 ->ad::lyt::LytAnim::term (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x478 | callers(6) 0x10006944 0x1000149c 0x10005918 0x100065ec 0x10004484 0x1000348c
// veneer/thunk -> 0x00264e90 ad::lyt::LytAnim::term (static)

// FUNC 0x10000480 ->msys::MLyt::stopAnimeAndSetEnd (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x480 | callers(1) 0x1000149c
// veneer/thunk -> 0x0032c27c msys::MLyt::stopAnimeAndSetEnd (static)

// FUNC 0x10000488 ->GameMain::GameModeOld (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x488 | callers(1) 0x1000149c
// veneer/thunk -> 0x0033e320 GameMain::GameModeOld (static)

// FUNC 0x10000490 ->atk_mg::GetBootInfo (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x490 | callers(4) 0x10006cb0 0x1000149c 0x100030c0 0x10005154
// veneer/thunk -> 0x0033c8c4 atk_mg::GetBootInfo (static)

// FUNC 0x10000498 ->atk_mg::BootInfo::saveBgm (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x498 | callers(1) 0x1000149c
// veneer/thunk -> 0x0033ca90 atk_mg::BootInfo::saveBgm (static)

// FUNC 0x100004a0 ->btl::GetBootInfo (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x4a0 | callers(3) 0x1000149c 0x100053bc 0x100051c0
// veneer/thunk -> 0x00217ff8 btl::GetBootInfo (static)

// FUNC 0x100004a8 ->msys::MListWndPBase::getListWnd (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x4a8 | callers(1) 0x1000149c
// veneer/thunk -> 0x003620c0 msys::MListWndPBase::getListWnd (static)

// FUNC 0x100004b0 ->ad::lyt::LytNumReel3::InitParam::InitParam (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x4b0 | callers(2) 0x1000149c 0x10002cec
// veneer/thunk -> 0x00256194 ad::lyt::LytNumReel3::InitParam::InitParam (static)

// FUNC 0x100004b8 ->msys::MLytNumRes::set (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x4b8 | callers(2) 0x1000149c 0x10002cec
// veneer/thunk -> 0x00207594 msys::MLytNumRes::set (static)

// FUNC 0x100004c0 ->msys::MLytNum::init (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x4c0 | callers(2) 0x1000149c 0x10002cec
// veneer/thunk -> 0x003316b8 msys::MLytNum::init (static)

// FUNC 0x100004c8 ->SndSys::start (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x4c8 | callers(1) 0x1000149c
// veneer/thunk -> 0x0033c77c SndSys::start (static)

// FUNC 0x100004d0 ->msys::MLyt::isEnableAnime (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x4d0 | callers(9) 0x100056e4 0x10005154 0x100042dc 0x1000453c 0x10004594 0x10004484 0x100057b0 0x10002a3c ...
// veneer/thunk -> 0x0032bc6c msys::MLyt::isEnableAnime (static)

// FUNC 0x100004d8 ->msys::MDfxChr::term (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x4d8 | callers(2) 0x1000436c 0x10002a3c
// veneer/thunk -> 0x00330c68 msys::MDfxChr::term (static)

// FUNC 0x100004e0 ->msys::MLyt::detachMChr (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x4e0 | callers(2) 0x1000436c 0x10002a3c
// veneer/thunk -> 0x0032b8c0 msys::MLyt::detachMChr (static)

// FUNC 0x100004e8 ->Mem::Free (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x4e8 | callers(2) 0x10005f98 0x10002a3c
// veneer/thunk -> 0x00285d3c Mem::Free (static)

// FUNC 0x100004f0 ->Backup::GetSaveData1 (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x4f0 | callers(1) 0x10002b70
// veneer/thunk -> 0x00339284 Backup::GetSaveData1 (static)

// FUNC 0x100004f8 ->Mem::Copy (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x4f8 | callers(2) 0x10002b70 0x10004a28
// veneer/thunk -> 0x0027fd08 Mem::Copy (static)

// FUNC 0x10000500 ->Backup::init (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x500 | callers(1) 0x10002b70
// veneer/thunk -> 0x00339c54 Backup::init (static)

// FUNC 0x10000508 ->Backup::writeSaveData0 (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x508 | callers(1) 0x10002b70
// veneer/thunk -> 0x00339aa0 Backup::writeSaveData0 (static)

// FUNC 0x10000510 ->msys::MCellAnime::init (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x510 | callers(1) 0x10002cec
// veneer/thunk -> 0x002079d8 msys::MCellAnime::init (static)

// FUNC 0x10000518 ->MessageWriter::setFontColor (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x518 | callers(1) 0x10002cec
// veneer/thunk -> 0x00270f0c MessageWriter::setFontColor (static)

// FUNC 0x10000520 ->SndSys::stopAllBgm (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x520 | callers(3) 0x10004818 0x100030c0 0x10003320
// veneer/thunk -> 0x0033c450 SndSys::stopAllBgm (static)

// FUNC 0x10000528 ->atk_mg::BootInfo::restoreBgm (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x528 | callers(1) 0x100030c0
// veneer/thunk -> 0x0033c910 atk_mg::BootInfo::restoreBgm (static)

// FUNC 0x10000530 ->msys::MLyt::isBusyTblAnime (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x530 | callers(1) 0x10003178
// veneer/thunk -> 0x0032bd94 msys::MLyt::isBusyTblAnime (static)

// FUNC 0x10000538 ->msys::MDfxChr::init (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x538 | callers(4) 0x10006944 0x100053bc 0x10003178 0x10004a28
// veneer/thunk -> 0x003309c0 msys::MDfxChr::init (static)

// FUNC 0x10000540 ->msys::MDfxChr::playDfx (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x540 | callers(6) 0x10006944 0x100065ec 0x100053bc 0x1000394c 0x10003178 0x10004a28
// veneer/thunk -> 0x00330d64 msys::MDfxChr::playDfx (static)

// FUNC 0x10000548 ->__cxa_guard_acquire (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x548 | callers(5) 0x10006944 0x100039d8 0x100053bc 0x10003178 0x10004a28
// veneer/thunk -> 0x00288110 __cxa_guard_acquire (static)

// FUNC 0x10000550 ->__cxa_guard_release (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x550 | callers(5) 0x10006944 0x100039d8 0x100053bc 0x10003178 0x10004a28
// veneer/thunk -> 0x001018a8 __cxa_guard_release (static)

// FUNC 0x10000558 ->ad::lyt::LytAnim::stop (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x558 | callers(2) 0x10004484 0x1000348c
// veneer/thunk -> 0x00251878 ad::lyt::LytAnim::stop (static)

// FUNC 0x10000560 ->__c89vswprintf (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x560 | callers(1) 0x1000361c
// veneer/thunk -> 0x0010005c __c89vswprintf (static)

// FUNC 0x10000568 ->strcmp (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x568 | callers(1) 0x10003648
// veneer/thunk -> 0x002833b8 strcmp (static)

// FUNC 0x10000570 ->msys::MCtrlUserData::findExtUserDataByName (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x570 | callers(1) 0x10003648
// veneer/thunk -> 0x0036203c msys::MCtrlUserData::findExtUserDataByName (static)

// FUNC 0x10000578 ->Message::play (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x578 | callers(1) 0x100038e0
// veneer/thunk -> 0x00259970 Message::play (static)

// FUNC 0x10000580 ->ad::lyt::LytNumReel3::setValueInstant (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x580 | callers(1) 0x10003b24
// veneer/thunk -> 0x0020785c ad::lyt::LytNumReel3::setValueInstant (static)

// FUNC 0x10000588 ->CellAnime::play (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x588 | callers(1) 0x10003b24
// veneer/thunk -> 0x0027bee0 CellAnime::play (static)

// FUNC 0x10000590 ->ad::db::GetItemMsgAcs (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x590 | callers(3) 0x10003b24 0x10005918 0x10005f98
// veneer/thunk -> 0x0013a30c ad::db::GetItemMsgAcs (static)

// FUNC 0x10000598 ->MessageSimple::getLineWidth (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x598 | callers(1) 0x10003b24
// veneer/thunk -> 0x00271378 MessageSimple::getLineWidth (static)

// FUNC 0x100005a0 ->msys::MListWndPBase::setEnableInput (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x5a0 | callers(1) 0x10003d68
// veneer/thunk -> 0x00328638 msys::MListWndPBase::setEnableInput (static)

// FUNC 0x100005a8 ->msys::MSndSe::play (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x5a8 | callers(2) 0x10004240 0x10003dd4
// veneer/thunk -> 0x0032d844 msys::MSndSe::play (static)

// FUNC 0x100005b0 ->ad::fw::TaskBase::term (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x5b0 | callers(1) 0x10003e74
// veneer/thunk -> 0x0024a358 ad::fw::TaskBase::term (static)

// FUNC 0x100005b8 ->msys::MLyt::term (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x5b8 | callers(2) 0x10003e74 0x1000719c
// veneer/thunk -> 0x0032c3c8 msys::MLyt::term (static)

// FUNC 0x100005c0 ->ad::fw::Resource::term (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x5c0 | callers(2) 0x10003e74 0x1000719c
// veneer/thunk -> 0x00233340 ad::fw::Resource::term (static)

// FUNC 0x100005c8 ->ad::fw::Resource::~Resource (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x5c8 | callers(2) 0x10003e74 0x1000719c
// veneer/thunk -> 0x0024a104 ad::fw::Resource::~Resource (static)

// FUNC 0x100005d0 ->msys::MComSys::~MComSys (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x5d0 | callers(1) 0x10003e74
// veneer/thunk -> 0x003300e8 msys::MComSys::~MComSys (static)

// FUNC 0x100005d8 ->MoveVBase::MoveVBase (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x5d8 | callers(1) 0x10003ff8
// veneer/thunk -> 0x00259740 MoveVBase::MoveVBase (static)

// FUNC 0x100005e0 ->msys::MLyt::getPane (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x5e0 | callers(3) 0x100046d0 0x100056e4 0x10004a28
// veneer/thunk -> 0x0032c688 msys::MLyt::getPane (static)

// FUNC 0x100005e8 ->__aeabi_uidivmod (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x5e8 | callers(1) 0x10004a28
// veneer/thunk -> 0x00281628 __aeabi_uidivmod (static)

// FUNC 0x100005f0 ->atk_mg::BootInfo::playBgm (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x5f0 | callers(1) 0x10005154
// veneer/thunk -> 0x0033c994 atk_mg::BootInfo::playBgm (static)

// FUNC 0x100005f8 ->btl::BootInfo::setModePcAtkMiniGame (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x5f8 | callers(1) 0x100051c0
// veneer/thunk -> 0x0029d1c0 btl::BootInfo::setModePcAtkMiniGame (static)

// FUNC 0x10000600 ->GameMain::Change (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x600 | callers(1) 0x100051c0
// veneer/thunk -> 0x0033e7fc GameMain::Change (static)

// FUNC 0x10000608 ->Message::term (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x608 | callers(3) 0x10005898 0x100058cc 0x1000719c
// veneer/thunk -> 0x0033dc68 Message::term (static)

// FUNC 0x10000610 ->Message::~Message (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x610 | callers(3) 0x10005898 0x100058cc 0x1000719c
// veneer/thunk -> 0x00206538 Message::~Message (static)

// FUNC 0x10000618 ->msys::MListWndPBase::applyAnime (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x618 | callers(1) 0x100058fc
// veneer/thunk -> 0x0032844c msys::MListWndPBase::applyAnime (static)

// FUNC 0x10000620 ->ad::lyt::Layout::Animate (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x620 | callers(1) 0x100058fc
// veneer/thunk -> 0x00161aec ad::lyt::Layout::Animate (static)

// FUNC 0x10000628 ->ad::lyt::LytResourceMan::buildLayout (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x628 | callers(1) 0x10005918
// veneer/thunk -> 0x00256490 ad::lyt::LytResourceMan::buildLayout (static)

// FUNC 0x10000630 ->ad::lyt::LytAnim::playAuto (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x630 | callers(1) 0x10005918
// veneer/thunk -> 0x0025620c ad::lyt::LytAnim::playAuto (static)

// FUNC 0x10000638 ->ad::fw::Resource::getCA_anm (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x638 | callers(1) 0x10005918
// veneer/thunk -> 0x0025abfc ad::fw::Resource::getCA_anm (static)

// FUNC 0x10000640 ->ad::fw::Resource::getCA_tex (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x640 | callers(1) 0x10005918
// veneer/thunk -> 0x0025ac08 ad::fw::Resource::getCA_tex (static)

// FUNC 0x10000648 ->ad::fw::Resource::getCA_canm (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x648 | callers(1) 0x10005918
// veneer/thunk -> 0x0025ac14 ad::fw::Resource::getCA_canm (static)

// FUNC 0x10000650 ->CellAnime::init (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x650 | callers(1) 0x10005918
// veneer/thunk -> 0x0027fa28 CellAnime::init (static)

// FUNC 0x10000658 ->ad::ui::UIListWindowPlusLyt::InitParam::InitParam (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x658 | callers(1) 0x10005918
// veneer/thunk -> 0x00146398 ad::ui::UIListWindowPlusLyt::InitParam::InitParam (static)

// FUNC 0x10000660 ->msys::SetMListWndInitParam (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x660 | callers(1) 0x10005918
// veneer/thunk -> 0x00329e60 msys::SetMListWndInitParam (static)

// FUNC 0x10000668 ->msys::MListWndPBase::init (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x668 | callers(1) 0x10005918
// veneer/thunk -> 0x00328698 msys::MListWndPBase::init (static)

// FUNC 0x10000670 ->CellAnime::~CellAnime (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x670 | callers(3) 0x10005ec4 0x10005f30 0x1000719c
// veneer/thunk -> 0x0024fc94 CellAnime::~CellAnime (static)

// FUNC 0x10000678 ->ad::lyt::Layout::~Layout (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x678 | callers(3) 0x10005ec4 0x10005f30 0x1000719c
// veneer/thunk -> 0x00262eec ad::lyt::Layout::~Layout (static)

// FUNC 0x10000680 ->Mem::Fill (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x680 | callers(1) 0x10005f98
// veneer/thunk -> 0x002849e8 Mem::Fill (static)

// FUNC 0x10000688 ->GameWork::addItem (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x688 | callers(1) 0x10005f98
// veneer/thunk -> 0x0033edc8 GameWork::addItem (static)

// FUNC 0x10000690 ->GameWork::addCoin (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x690 | callers(1) 0x10005f98
// veneer/thunk -> 0x0022ec84 GameWork::addCoin (static)

// FUNC 0x10000698 ->ad::TransMultiSymbol::init (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x698 | callers(1) 0x10006788
// veneer/thunk -> 0x0026d7f8 ad::TransMultiSymbol::init (static)

// FUNC 0x100006a0 ->BinGlu4Acs::getEntryAcs (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x6a0 | callers(1) 0x10006788
// veneer/thunk -> 0x00285268 BinGlu4Acs::getEntryAcs (static)

// FUNC 0x100006a8 ->ad::fw::TaskBase::readCA (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x6a8 | callers(1) 0x10006788
// veneer/thunk -> 0x0026daf8 ad::fw::TaskBase::readCA (static)

// FUNC 0x100006b0 ->Backup::Backup (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x6b0 | callers(1) 0x10006cb0
// veneer/thunk -> 0x00110c64 Backup::Backup (static)

// FUNC 0x100006b8 ->ad::ctrl::ButtonGroup::ButtonGroup (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x6b8 | callers(1) 0x10006cb0
// veneer/thunk -> 0x001667d8 ad::ctrl::ButtonGroup::ButtonGroup (static)

// FUNC 0x100006c0 ->ad::font::ResFont::ResFont (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x6c0 | callers(1) 0x10006cb0
// veneer/thunk -> 0x0027542c ad::font::ResFont::ResFont (static)

// FUNC 0x100006c8 ->msys::MCursorBase::MCursorBase (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x6c8 | callers(1) 0x10006cb0
// veneer/thunk -> 0x00324550 msys::MCursorBase::MCursorBase (static)

// FUNC 0x100006d0 ->MessageSimple::MessageSimple (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x6d0 | callers(1) 0x10006cb0
// veneer/thunk -> 0x0027ceec MessageSimple::MessageSimple (static)

// FUNC 0x100006d8 ->msys::MLytNum::MLytNum (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x6d8 | callers(1) 0x10006cb0
// veneer/thunk -> 0x003317a4 msys::MLytNum::MLytNum (static)

// FUNC 0x100006e0 ->Message::Message (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x6e0 | callers(1) 0x10006cb0
// veneer/thunk -> 0x00110d5c Message::Message (static)

// FUNC 0x100006e8 ->msys::MListWndPBase::MListWndPBase (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x6e8 | callers(1) 0x10006cb0
// veneer/thunk -> 0x00328800 msys::MListWndPBase::MListWndPBase (static)

// FUNC 0x100006f0 ->ad::ui::UIListWindowPlusLyt::UIListWindowPlusLyt (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x6f0 | callers(1) 0x10006cb0
// veneer/thunk -> 0x00146984 ad::ui::UIListWindowPlusLyt::UIListWindowPlusLyt (static)

// FUNC 0x100006f8 ->ad::lyt::Layout::Layout (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x6f8 | callers(1) 0x10006cb0
// veneer/thunk -> 0x00264ccc ad::lyt::Layout::Layout (static)

// FUNC 0x10000700 ->CellAnime::CellAnime (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x700 | callers(1) 0x10006cb0
// veneer/thunk -> 0x0026be18 CellAnime::CellAnime (static)

// FUNC 0x10000708 ->msys::MCursorBase::term (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x708 | callers(1) 0x1000719c
// veneer/thunk -> 0x003244f0 msys::MCursorBase::term (static)

// FUNC 0x10000710 ->ad::ctrl::ButtonGroup::FreeAll (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x710 | callers(1) 0x1000719c
// veneer/thunk -> 0x002509d0 ad::ctrl::ButtonGroup::FreeAll (static)

// FUNC 0x10000718 ->ad::lyt::LytResourceMan::term (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x718 | callers(1) 0x1000719c
// veneer/thunk -> 0x00250938 ad::lyt::LytResourceMan::term (static)

// FUNC 0x10000720 ->MessageSimple::term (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x720 | callers(1) 0x1000719c
// veneer/thunk -> 0x00137090 MessageSimple::term (static)

// FUNC 0x10000728 ->MessageSimple::~MessageSimple (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x728 | callers(1) 0x1000719c
// veneer/thunk -> 0x00256578 MessageSimple::~MessageSimple (static)

// FUNC 0x10000730 ->msys::MLytNum::~MLytNum (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x730 | callers(1) 0x1000719c
// veneer/thunk -> 0x00331840 msys::MLytNum::~MLytNum (static)

// FUNC 0x10000738 ->msys::MCursorBase::~MCursorBase (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x738 | callers(3) 0x1000719c 0x10007b10 0x10007b20
// veneer/thunk -> 0x00324600 msys::MCursorBase::~MCursorBase (static)

// FUNC 0x10000740 ->ad::font::ResFont::~ResFont (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x740 | callers(1) 0x1000719c
// veneer/thunk -> 0x002508a8 ad::font::ResFont::~ResFont (static)

// FUNC 0x10000748 ->ad::ctrl::ButtonGroup::~ButtonGroup (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x748 | callers(1) 0x1000719c
// veneer/thunk -> 0x00250928 ad::ctrl::ButtonGroup::~ButtonGroup (static)

// FUNC 0x10000750 ->Backup::~Backup (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x750 | callers(1) 0x1000719c
// veneer/thunk -> 0x00339f34 Backup::~Backup (static)

// FUNC 0x10000758 ->msys::MPageBase::updateInputAllChr (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x758 | callers(1) 0x1000755c
// veneer/thunk -> 0x00334204 msys::MPageBase::updateInputAllChr (static)

// FUNC 0x10000760 ->ad::ctrl::ButtonGroup::Update (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x760 | callers(1) 0x1000755c
// veneer/thunk -> 0x00250a40 ad::ctrl::ButtonGroup::Update (static)

// FUNC 0x10000768 ->msys::MTaskBase::MTaskBase (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x768 | callers(1) 0x10007814
// veneer/thunk -> 0x00334688 msys::MTaskBase::MTaskBase (static)

// FUNC 0x10000770 ->ad::fw::TaskBase::~TaskBase (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x770 | callers(2) 0x10007850 0x10007878
// veneer/thunk -> 0x0026d590 ad::fw::TaskBase::~TaskBase (static)

// FUNC 0x10000778 ->MoveWorkF::MoveWorkF (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x778 | callers(1) 0x1000789c
// veneer/thunk -> 0x00278cc0 MoveWorkF::MoveWorkF (static)

// FUNC 0x10000780 ->MoveWorkF::~MoveWorkF (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x780 | callers(2) 0x100078d0 0x100078e0
// veneer/thunk -> 0x00340694 MoveWorkF::~MoveWorkF (static)

// FUNC 0x10000788 ->ad::fw::FileContext::initSingleFile (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x788 | callers(1) 0x10007a34
// veneer/thunk -> 0x0013ad54 ad::fw::FileContext::initSingleFile (static)

// FUNC 0x10000790 ->ad::fw::FileContext::initArcFile (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x790 | callers(1) 0x10007a34
// veneer/thunk -> 0x0013aca8 ad::fw::FileContext::initArcFile (static)

// FUNC 0x10000798 ->ad::fw::FileContext::initCAArcFile (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x798 | callers(1) 0x10007a34
// veneer/thunk -> 0x0013acc0 ad::fw::FileContext::initCAArcFile (static)

// FUNC 0x100007a0 ->msys::MCursorBase::init (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x7a0 | callers(1) 0x10007ae8
// veneer/thunk -> 0x00324464 msys::MCursorBase::init (static)

// FUNC 0x100007a8 AttackMiniGame::EntryTask (AttackMiniGame)
//   size 0x34 | file AttackMiniGame+0x7a8 | callers(0)

void AttackMiniGame::EntryTask(void)

{
  void *pvVar1;
  Task *pTVar2;
  
  pvVar1 = operator_new(0xe9a50,gMemAlc,(char *)0x0,0);
  pTVar2 = (Task *)0x0;
  if (pvVar1 != (void *)0x0) {
    pTVar2 = (Task *)FUN_10007814();
  }
  TaskMan::entry((TaskMan *)&gTaskMainMan,pTVar2);
  return;
}


// FUNC 0x100007e8 FUN_100007e8 (AttackMiniGame)
//   size 0x10 | file AttackMiniGame+0x7e8 | callers(0) | datarefs 1

void FUN_100007e8(MsgDataAcsrBase *param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)MsgDataAcsrBase::~MsgDataAcsrBase(param_1);
  operator_delete(pvVar1);
  return;
}


// FUNC 0x100007f8 ->MsgDataAcsrBase::~MsgDataAcsrBase (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x7f8 | callers(0) | datarefs 1
// veneer/thunk -> 0x0026fdb4 MsgDataAcsrBase::~MsgDataAcsrBase (static)

// FUNC 0x100007fc FUN_100007fc (AttackMiniGame)
//   size 0xc | file AttackMiniGame+0x7fc | callers(0) | datarefs 1

void FUN_100007fc(int *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10000804. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x14))();
  return;
}


// FUNC 0x10000808 atk_mg::AttackMiniGameTask::vfunc_0x1c (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x808 | callers(0) | datarefs 1

void atk_mg::AttackMiniGameTask::vfunc_0x1c(void)

{
  return;
}


// FUNC 0x1000080c atk_mg::AttackMiniGameTask::vfunc_0x4c (AttackMiniGame)
//   size 0x8 | file AttackMiniGame+0x80c | callers(0) | datarefs 1

undefined4 * atk_mg::AttackMiniGameTask::vfunc_0x4c(void)

{
  return &gFrameBuf;
}


// FUNC 0x10000818 atk_mg::AttackMiniGameTask::vfunc_0x3c (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x818 | callers(0) | datarefs 1

void atk_mg::AttackMiniGameTask::vfunc_0x3c(void)

{
  return;
}


// FUNC 0x1000081c atk_mg::AttackMiniGameTask::vfunc_0x40 (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x81c | callers(0) | datarefs 1

void atk_mg::AttackMiniGameTask::vfunc_0x40(void)

{
  return;
}


// FUNC 0x10000820 atk_mg::AttackMiniGameTask::vfunc_0x30 (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x820 | callers(0) | datarefs 1

void atk_mg::AttackMiniGameTask::vfunc_0x30(void)

{
  return;
}


// FUNC 0x10000824 atk_mg::AttackMiniGameTask::vfunc_0x20 (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x824 | callers(0) | datarefs 1

void atk_mg::AttackMiniGameTask::vfunc_0x20(void)

{
  return;
}


// FUNC 0x10000828 atk_mg::AttackMiniGameTask::vfunc_0x38 (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x828 | callers(0) | datarefs 1

void atk_mg::AttackMiniGameTask::vfunc_0x38(void)

{
  return;
}


// FUNC 0x1000082c atk_mg::AttackMiniGameTask::vfunc_0x28 (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x82c | callers(0) | datarefs 1

void atk_mg::AttackMiniGameTask::vfunc_0x28(void)

{
  return;
}


// FUNC 0x10000830 msys::MListWndPCore::vfunc_0x1c (AttackMiniGame)
//   size 0x20 | file AttackMiniGame+0x830 | callers(0) | datarefs 1

void msys::MListWndPCore::vfunc_0x1c(int *param_1,undefined4 param_2,undefined4 *param_3)

{
  (**(code **)(*param_1 + 0x18))(param_1,param_2,*param_3,param_3[1],param_3[2]);
  return;
}


// FUNC 0x10000860 ->operator.delete (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x860 | callers(0) | datarefs 1
// veneer/thunk -> 0x00286514 operator.delete (static)

// FUNC 0x10000864 nn::fs::IInputStream::vfunc_0x0 (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x864 | callers(0) | datarefs 1

void nn::fs::IInputStream::vfunc_0x0(void)

{
  return;
}


// FUNC 0x10000868 nn::fs::FileInputStream::vfunc_0x1c (AttackMiniGame)
//   size 0x24 | file AttackMiniGame+0x868 | callers(0) | datarefs 1

void nn::fs::FileInputStream::vfunc_0x1c(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = detail::FileBase::TrySetPosition(CONCAT44(param_2,param_1 + 4));
  if (iVar1 < 0) {
    err::CTR::ThrowFatalErrAll(iVar1,0x1000087c);
    return;
  }
  return;
}


// FUNC 0x1000088c nn::fs::FileInputStream::vfunc_0x18 (AttackMiniGame)
//   size 0x8 | file AttackMiniGame+0x88c | callers(0) | datarefs 1

void nn::fs::FileInputStream::vfunc_0x18(int param_1,undefined4 param_2)

{
  detail::FileBase::TrySetPosition(CONCAT44(param_2,param_1 + 4));
  return;
}


// FUNC 0x10000894 nn::fs::FileInputStream::vfunc_0x2c (AttackMiniGame)
//   size 0x2c | file AttackMiniGame+0x894 | callers(0) | datarefs 1

int nn::fs::FileInputStream::vfunc_0x2c(int param_1,void *param_2,uint param_3,int param_4)

{
  int iVar1;
  int local_8;
  
  local_8 = param_4;
  iVar1 = detail::FileBase::TryRead((FileBase *)(param_1 + 4),&local_8,param_2,param_3);
  if (iVar1 < 0) {
    err::CTR::ThrowFatalErrAll(iVar1,0x100008b4);
  }
  return local_8;
}


// FUNC 0x100008c0 nn::fs::FileInputStream::vfunc_0xc (AttackMiniGame)
//   size 0x2c | file AttackMiniGame+0x8c0 | callers(0) | datarefs 1

void nn::fs::FileInputStream::vfunc_0xc(int param_1)

{
  int iVar1;
  undefined4 in_stack_00000000;
  
  iVar1 = detail::FileBase::TrySeek(param_1 + 4);
  if (-(iVar1 >> 0x1f) == 0) {
    return;
  }
  err::CTR::ThrowFatalErrAll(iVar1,0x100008dc,-(iVar1 >> 0x1f),in_stack_00000000);
  return;
}


// FUNC 0x100008ec nn::fs::FileInputStream::vfunc_0x28 (AttackMiniGame)
//   size 0x8 | file AttackMiniGame+0x8ec | callers(0) | datarefs 1

void nn::fs::FileInputStream::vfunc_0x28(int param_1,int *param_2,void *param_3,uint param_4)

{
  detail::FileBase::TryRead((FileBase *)(param_1 + 4),param_2,param_3,param_4);
  return;
}


// FUNC 0x100008f4 nn::fs::FileInputStream::vfunc_0x8 (AttackMiniGame)
//   size 0x18 | file AttackMiniGame+0x8f4 | callers(0) | datarefs 1

void nn::fs::FileInputStream::vfunc_0x8(int param_1)

{
  detail::FileBase::TrySeek(param_1 + 4);
  return;
}


// FUNC 0x1000090c nn::fs::FileInputStream::vfunc_0x4 (AttackMiniGame)
//   size 0x40 | file AttackMiniGame+0x90c | callers(0) | datarefs 1

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


// FUNC 0x1000094c nn::fs::FileInputStream::vfunc_0x0 (AttackMiniGame)
//   size 0x3c | file AttackMiniGame+0x94c | callers(0) | datarefs 1

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


// FUNC 0x100009c8 atk_mg::AttackMiniGameTask::vfunc_0xc (AttackMiniGame)
//   size 0xc | file AttackMiniGame+0x9c8 | callers(0) | datarefs 1

void atk_mg::AttackMiniGameTask::vfunc_0xc(int *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x100009d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 8))();
  return;
}


// FUNC 0x100009d4 msys::MChrBase::vfunc_0x10 (AttackMiniGame)
//   size 0xc | file AttackMiniGame+0x9d4 | callers(0) | datarefs 1

void msys::MChrBase::vfunc_0x10(int param_1)

{
  *(undefined1 *)(param_1 + 0x142) = 0;
  return;
}


// FUNC 0x100009e0 FUN_100009e0 (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x9e0 | callers(0) | datarefs 2

void FUN_100009e0(void)

{
  return;
}


// FUNC 0x100009e4 msys::MChrBase::vfunc_0x8 (AttackMiniGame)
//   size 0xc | file AttackMiniGame+0x9e4 | callers(0) | datarefs 1

void msys::MChrBase::vfunc_0x8(int param_1)

{
  *(undefined1 *)(param_1 + 0x142) = 1;
  return;
}


// FUNC 0x100009f0 FUN_100009f0 (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x9f0 | callers(0) | datarefs 4

void FUN_100009f0(void)

{
  return;
}


// FUNC 0x100009f4 msys::MListWndPCore::vfunc_0x30 (AttackMiniGame)
//   size 0x10 | file AttackMiniGame+0x9f4 | callers(0) | datarefs 1

void msys::MListWndPCore::vfunc_0x30(undefined4 param_1)

{
  FUN_10004240(param_1,0x110015);
  return;
}


// FUNC 0x10000a08 msys::MListWndPCore::vfunc_0x2c (AttackMiniGame)
//   size 0x10 | file AttackMiniGame+0xa08 | callers(0) | datarefs 1

void msys::MListWndPCore::vfunc_0x2c(undefined4 param_1)

{
  FUN_10004240(param_1,0x110015);
  return;
}


// FUNC 0x10000a1c msys::MListWndPCore::vfunc_0x34 (AttackMiniGame)
//   size 0x10 | file AttackMiniGame+0xa1c | callers(0) | datarefs 1

void msys::MListWndPCore::vfunc_0x34(undefined4 param_1)

{
  FUN_10004240(param_1,0x110015);
  return;
}


// FUNC 0x10000a30 msys::MListWndPCore::vfunc_0x38 (AttackMiniGame)
//   size 0x10 | file AttackMiniGame+0xa30 | callers(0) | datarefs 1

void msys::MListWndPCore::vfunc_0x38(undefined4 param_1)

{
  FUN_10004240(param_1,0x110015);
  return;
}


// FUNC 0x10000a44 msys::MListWndPCore::vfunc_0x3c (AttackMiniGame)
//   size 0x10 | file AttackMiniGame+0xa44 | callers(0) | datarefs 1

void msys::MListWndPCore::vfunc_0x3c(undefined4 param_1)

{
  FUN_10004240(param_1,0x110018);
  return;
}


// FUNC 0x10000a58 msys::MListWndPCore::vfunc_0x44 (AttackMiniGame)
//   size 0x10 | file AttackMiniGame+0xa58 | callers(0) | datarefs 1

void msys::MListWndPCore::vfunc_0x44(UIListWindowPlusLyt *param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)ad::ui::UIListWindowPlusLyt::~UIListWindowPlusLyt(param_1);
  operator_delete(pvVar1);
  return;
}


// FUNC 0x10000a68 ->ad::ui::UIListWindowPlusLyt::~UIListWindowPlusLyt (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0xa68 | callers(0) | datarefs 1
// veneer/thunk -> 0x0025a3fc ad::ui::UIListWindowPlusLyt::~UIListWindowPlusLyt (static)

// FUNC 0x10000a6c atk_mg::AttackMiniGame::vfunc_0x14 (AttackMiniGame)
//   size 0x8 | file AttackMiniGame+0xa6c | callers(0) | datarefs 1

undefined4 atk_mg::AttackMiniGame::vfunc_0x14(void)

{
  return 0;
}


// FUNC 0x10000a74 atk_mg::AttackMiniGamePage::Core::MsgWnd::vfunc_0x20 (AttackMiniGame)
//   size 0x8 | file AttackMiniGame+0xa74 | callers(0) | datarefs 1

undefined4 atk_mg::AttackMiniGamePage::Core::MsgWnd::vfunc_0x20(void)

{
  return 0;
}


// FUNC 0x10000a7c atk_mg::AttackMiniGamePage::Core::MsgWnd::vfunc_0x8 (AttackMiniGame)
//   size 0xd0 | file AttackMiniGame+0xa7c | callers(0) | datarefs 1

void atk_mg::AttackMiniGamePage::Core::MsgWnd::vfunc_0x8(float param_1,int *param_2)

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


// FUNC 0x10000b54 atk_mg::AttackMiniGamePage::Core::MsgWnd::vfunc_0x38 (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0xb54 | callers(0) | datarefs 1

void atk_mg::AttackMiniGamePage::Core::MsgWnd::vfunc_0x38(void)

{
  return;
}


// FUNC 0x10000b58 atk_mg::AttackMiniGamePage::Core::MsgWnd::vfunc_0x14 (AttackMiniGame)
//   size 0x2c | file AttackMiniGame+0xb58 | callers(0) | datarefs 1

void atk_mg::AttackMiniGamePage::Core::MsgWnd::vfunc_0x14(int param_1,MRenderQueueBase *param_2)

{
  if (*(char *)(param_1 + 0x141) == '\0') {
    return;
  }
  msys::MRenderQueueBase::enqueueMsg
            (param_2,(MessageSimple *)(param_1 + 0x14c),*(uint *)(param_1 + 0x6ef4),'\n');
  return;
}


// FUNC 0x10000b88 msys::MChrBase::vfunc_0x4 (AttackMiniGame)
//   size 0x10 | file AttackMiniGame+0xb88 | callers(0) | datarefs 1

void msys::MChrBase::vfunc_0x4(void)

{
  void *pvVar1;
  
  pvVar1 = (void *)vfunc_0x0();
  operator_delete(pvVar1);
  return;
}


// FUNC 0x10000b98 FUN_10000b98 (AttackMiniGame)
//   size 0x20 | file AttackMiniGame+0xb98 | callers(0) | datarefs 1

void FUN_10000b98(undefined4 *param_1)

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


// FUNC 0x10000bbc FUN_10000bbc (AttackMiniGame)
//   size 0x1c | file AttackMiniGame+0xbbc | callers(0) | datarefs 1

void FUN_10000bbc(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &vtable_for_N4msys9MListWndPILi8EEE;
  iVar1 = ad::ui::UIListWindowPlusLyt::~UIListWindowPlusLyt((UIListWindowPlusLyt *)(param_1 + 0x7f))
  ;
  msys::MListWndPBase::~MListWndPBase((MListWndPBase *)(iVar1 + -0x1fc));
  return;
}


// FUNC 0x10000bdc atk_mg::AttackMiniGamePage::vfunc_0x20 (AttackMiniGame)
//   size 0x8 | file AttackMiniGame+0xbdc | callers(0) | datarefs 1

void atk_mg::AttackMiniGamePage::vfunc_0x20
               (MPageBase *param_1,undefined4 param_2,MRenderQueue *param_3)

{
  msys::MPageBase::enqueueLowerChr(param_1,param_3);
  return;
}


// FUNC 0x10000be4 atk_mg::AttackMiniGamePage::vfunc_0x1c (AttackMiniGame)
//   size 0x8 | file AttackMiniGame+0xbe4 | callers(0) | datarefs 1

void atk_mg::AttackMiniGamePage::vfunc_0x1c
               (MPageBase *param_1,undefined4 param_2,MRenderQueue *param_3)

{
  msys::MPageBase::enqueueUpperChr(param_1,param_3);
  return;
}


// FUNC 0x10000bec FUN_10000bec (AttackMiniGame)
//   size 0x34 | file AttackMiniGame+0xbec | callers(0) | datarefs 1

void FUN_10000bec(MoveVBase *param_1)

{
  void *pvVar1;
  
  *(undefined ***)param_1 = &vtable_for_5MoveVILj1EE;
  __aeabi_vec_dtor(param_1 + 0x30,MoveWorkF::~MoveWorkF,0x2c,1);
  pvVar1 = (void *)MoveVBase::~MoveVBase(param_1);
  operator_delete(pvVar1);
  return;
}


// FUNC 0x10000c28 FUN_10000c28 (AttackMiniGame)
//   size 0x30 | file AttackMiniGame+0xc28 | callers(0) | datarefs 1

void FUN_10000c28(MoveVBase *param_1)

{
  *(undefined ***)param_1 = &vtable_for_5MoveVILj1EE;
  __aeabi_vec_dtor(param_1 + 0x30,MoveWorkF::~MoveWorkF,0x2c,1);
  MoveVBase::~MoveVBase(param_1);
  return;
}


// FUNC 0x10000c60 FUN_10000c60 (AttackMiniGame)
//   size 0x70 | file AttackMiniGame+0xc60 | callers(0) | datarefs 2

void FUN_10000c60(MComSys *param_1)

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


// FUNC 0x10000cd4 atk_mg::AttackMiniGame::vfunc_0x10 (AttackMiniGame)
//   size 0x38 | file AttackMiniGame+0xcd4 | callers(0) | datarefs 1

void atk_mg::AttackMiniGame::vfunc_0x10(MComSys *param_1,CmdList *param_2)

{
  MTX44 aMStack_50 [68];
  
  msys::MCamera::getProjMtx((MCamera *)(param_1 + 0x4ae34),aMStack_50,0x401);
  msys::MComSys::funcDrawLower(param_1,param_2);
  return;
}


// FUNC 0x10000d14 ->msys::MComSys::funcDrawUpper (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0xd14 | callers(0) | datarefs 1
// veneer/thunk -> 0x0032e760 msys::MComSys::funcDrawUpper (static)

// FUNC 0x10000d18 FUN_10000d18 (AttackMiniGame)
//   size 0x258 | file AttackMiniGame+0xd18 | callers(0) | datarefs 1

void FUN_10000d18(MComSys *param_1)

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
      uVar5 = 0x10000e74;
    }
    if (bVar7 && (int)uVar8 < 0) {
      nn::err::CTR::ThrowFatalErrAll((int)uVar8,uVar5);
    }
    iVar1 = nn::fs::detail::FileBase::TryGetSize
                      ((FileBase *)(apvStackY_238 + 0x81),(longlong *)local_20);
    if (iVar1 < 0) {
      nn::err::CTR::ThrowFatalErrAll(iVar1,0x10000ea4);
    }
    pvVar4 = (void *)(**(code **)(*(int *)(param_1 + 0xc) + 0xc))(param_1 + 0xc,local_20[0],0);
    *(void **)(param_1 + 0xe904c) = pvVar4;
    iVar1 = nn::fs::detail::FileBase::TryRead
                      ((FileBase *)(apvStackY_238 + 0x81),(int *)local_20,pvVar4,local_20[0]);
    if (iVar1 < 0) {
      nn::err::CTR::ThrowFatalErrAll(iVar1,0x10000ee8);
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
    *(code **)(param_1 + 0xf84) = FUN_10000fb4;
    *(undefined4 *)(param_1 + 0xf88) = 0;
  }
  return;
}


// FUNC 0x10000fb4 FUN_10000fb4 (AttackMiniGame)
//   size 0x14c | file AttackMiniGame+0xfb4 | callers(0) | datarefs 2

void FUN_10000fb4(int param_1)

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
    msys::MLytNumRes::init((MLytNumRes *)(param_1 + 0x844),(LytResourceMan *)(param_1 + 2000),6);
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
    *(code **)(param_1 + 0xf84) = FUN_1000112c;
    *(undefined4 *)(param_1 + 0xf88) = 0;
  }
  return;
}


// FUNC 0x1000112c FUN_1000112c (AttackMiniGame)
//   size 0xb4 | file AttackMiniGame+0x112c | callers(0) | datarefs 2

void FUN_1000112c(int param_1)

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
    *(code **)(param_1 + 0xf84) = FUN_10000c60;
    *(undefined4 *)(param_1 + 0xf88) = 0;
  }
  return;
}


// FUNC 0x100011f4 FUN_100011f4 (AttackMiniGame)
//   size 0x16c | file AttackMiniGame+0x11f4 | callers(1) 0x10007814

void FUN_100011f4(MComSys *param_1,MTaskBase *param_2)

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
    *(undefined **)(pJVar1 + 0x10) = &DAT_10008318;
    *(undefined4 *)(pJVar1 + 0x14) = 3;
    uVar2 = *(undefined4 *)(param_2 + 0x4d8);
    *(undefined4 *)(pJVar1 + 0x18) = *(undefined4 *)(param_2 + 0x4d4);
    *(undefined4 *)(pJVar1 + 0x1c) = uVar2;
  }
  CtrJobMan::enqueue((CtrJobMan *)(param_2 + 0x4dc),pJVar1);
  *(code **)(param_1 + 0xf84) = FUN_10000d18;
  *(undefined4 *)(param_1 + 0xf88) = 0;
  msys::MComSys::setupCamU(param_1);
  msys::MComSys::setupCamL(param_1);
  param_1[0x4ad85] = (MComSys)0x1;
  param_1[0x4ae65] = (MComSys)0x1;
  return;
}


// FUNC 0x10001380 FUN_10001380 (AttackMiniGame)
//   size 0xf4 | file AttackMiniGame+0x1380 | callers(1) 0x10007814

int FUN_10001380(MComSys *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar1 = (undefined4 *)msys::MComSys::MComSys(param_1);
  *puVar1 = &atk_mg::AttackMiniGame::vtable;
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
  puVar1[0x1b] = &atk_mg::AttackMiniGamePage::vtable;
  puVar1[0x22] = 0;
  puVar1[0x23] = 0;
  iVar3 = ad::fw::Resource::Resource((Resource *)(puVar1 + 0x24));
  puVar1 = (undefined4 *)FUN_10003ff8(iVar3 + 0x44);
  *puVar1 = &msys::MLyt::vtable;
  *(undefined1 *)(puVar1 + 0x53) = 0xff;
  *(undefined2 *)((int)puVar1 + 0x14e) = 0;
  puVar1[0x54] = 0;
  iVar3 = __aeabi_vec_ctor_nocookie_nodtor(puVar1 + 0x55,FUN_100035e0,0x1c,0xc);
  iVar3 = __aeabi_vec_ctor_nocookie_nodtor(iVar3 + 0x15c,&LAB_10000988,0x10,0xc);
  *(undefined4 *)(iVar3 + 0xc0) = 0;
  *(undefined1 *)(iVar3 + 0xc4) = 1;
  *(undefined4 *)(iVar3 + 200) = 0;
  *(undefined4 *)(iVar3 + 0xcc) = 0;
  *(undefined1 *)(iVar3 + 0xd0) = 0;
  *(undefined4 *)(iVar3 + 0xd4) = 0;
  *(undefined4 *)(iVar3 + 0xd8) = 0;
  FUN_10003fdc(iVar3 + -0xc,0xffffffff);
  return iVar3 + -0xe93d4;
}


// FUNC 0x1000148c atk_mg::AttackMiniGame::vfunc_0x4 (AttackMiniGame)
//   size 0x10 | file AttackMiniGame+0x148c | callers(0) | datarefs 1

void atk_mg::AttackMiniGame::vfunc_0x4(void)

{
  void *pvVar1;
  
  pvVar1 = (void *)vfunc_0x0();
  operator_delete(pvVar1);
  return;
}


// FUNC 0x1000149c FUN_1000149c (AttackMiniGame)
//   size 0xce0 | file AttackMiniGame+0x149c | callers(1) 0x10001bfc

void FUN_1000149c(void *param_1)

{
  ushort uVar1;
  char cVar2;
  short sVar3;
  LytResourceMan *this;
  void *pvVar4;
  MLyt *pMVar5;
  int *piVar6;
  undefined4 uVar7;
  wchar_t *pwVar8;
  AnimButton *this_00;
  BootInfo *this_01;
  short *psVar9;
  code *pcVar10;
  int *piVar11;
  MLyt *pMVar12;
  undefined4 *puVar13;
  int iVar14;
  MMsg *this_02;
  uint uVar15;
  int iVar16;
  MCursorBase *pMVar17;
  int iVar18;
  undefined2 *puVar19;
  short *psVar20;
  char cVar21;
  uint in_fpscr;
  undefined4 extraout_s0;
  float fVar22;
  float fVar23;
  short sVar24;
  int local_f8;
  MCursorBase *local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined2 local_e8;
  undefined2 local_e6;
  AnimTransform *local_e4;
  LytAnim local_dc [4];
  undefined4 local_d8;
  undefined4 uStack_d4;
  undefined4 local_d0;
  undefined2 local_cc;
  undefined2 local_ca;
  AnimTransform *local_c8;
  undefined4 local_c4;
  MLyt *local_c0;
  LytLocalize aLStack_b0 [16];
  undefined4 local_a0;
  int local_90;
  MChrBase *local_8c;
  char *local_88 [5];
  int local_74;
  undefined1 local_57;
  MChrBase *local_40;
  
  if (*(int *)((int)param_1 + 8) == 0) {
    *(int *)((int)param_1 + 8) = msys::MComSys::_sys;
  }
  this = (LytResourceMan *)((int)param_1 + 0x12a30);
  iVar14 = *(int *)((int)param_1 + 8);
  ad::lyt::LytResourceMan::init(this);
  pvVar4 = (void *)ad::fw::Resource::getFileData((Resource *)((int)param_1 + 0x12aa4));
  ad::lyt::LytResourceMan::registerArc(this,pvVar4,".");
  pMVar5 = (MLyt *)((int)param_1 + 0x12b2c);
  msys::MLyt::build(pMVar5,*(MemAlcBase **)(*(int *)((int)param_1 + 4) + 0x18),
                    (AnimeName *)&PTR_s_1_to_0_100081b4,4);
  iVar14 = iVar14 + 0xd3000;
  msys::MLyt::init(pMVar5,iVar14,1);
  msys::MLyt::createLyt(pMVar5,this,"MINIGAME_ATTACK_U.bflyt");
  MoveVBase::stop((MoveVBase *)((int)param_1 + 0x12bf8));
  *(undefined4 *)((int)param_1 + 0x12c14) = 0;
  *(undefined4 *)((int)param_1 + 0x12c18) = 0;
  *(undefined4 *)((int)param_1 + 0x12c1c) = 0xc3480000;
  *(undefined4 *)((int)param_1 + 0x12bfc) = *(undefined4 *)((int)param_1 + 0x12c14);
  *(undefined4 *)((int)param_1 + 0x12c00) = 0;
  *(undefined4 *)((int)param_1 + 0x12c04) = 0xc3480000;
  *(undefined4 *)((int)param_1 + 0x12c68) = 0x400;
  pMVar5 = (MLyt *)((int)param_1 + 0x12ed4);
  msys::MLyt::build(pMVar5,*(MemAlcBase **)(*(int *)((int)param_1 + 4) + 0x18),
                    (AnimeName *)&PTR_s_1_to_0_100081d4,7);
  msys::MLyt::init(pMVar5,iVar14,1);
  msys::MLyt::createLyt
            (pMVar5,this,"MINIGAME_ATTACK_L_n.bflyt",(ButtonGroup *)((int)param_1 + 0x12a14),
             (MCursorBase *)((int)param_1 + 0x1327c));
  MoveVBase::stop((MoveVBase *)((int)param_1 + 0x12fa0));
  *(undefined4 *)((int)param_1 + 0x12fbc) = 0;
  *(undefined4 *)((int)param_1 + 0x12fc0) = 0;
  *(undefined4 *)((int)param_1 + 0x12fc4) = 0xc3480000;
  *(undefined4 *)((int)param_1 + 0x12fa4) = *(undefined4 *)((int)param_1 + 0x12fbc);
  *(undefined4 *)((int)param_1 + 0x12fa8) = 0;
  *(undefined4 *)((int)param_1 + 0x12fac) = 0xc3480000;
  *(undefined4 *)((int)param_1 + 0x13010) = 0x401;
  FUN_10005918((int)param_1 + 0x28b90,param_1);
  MoveVBase::stop((MoveVBase *)((int)param_1 + 0x28c5c));
  *(undefined4 *)((int)param_1 + 0x28c78) = 0;
  *(undefined4 *)((int)param_1 + 0x28c7c) = 0;
  *(undefined4 *)((int)param_1 + 0x28c80) = 0xc3480000;
  *(undefined4 *)((int)param_1 + 0x28c60) = *(undefined4 *)((int)param_1 + 0x28c78);
  *(undefined4 *)((int)param_1 + 0x28c64) = 0;
  *(undefined4 *)((int)param_1 + 0x28c68) = 0xc3480000;
  *(undefined **)((int)param_1 + 0x129fc) = &DAT_10003028;
  *(undefined4 *)((int)param_1 + 0x12a00) = 0;
  if (*(char *)((int)param_1 + 0x13254) == '\0') {
    return;
  }
  ad::lyt::LytLocalize::LytLocalize(aLStack_b0);
  pMVar5 = (MLyt *)((int)param_1 + 0x12b2c);
  ad::lyt::LytLocalize::localize(aLStack_b0,*(Layout **)((int)param_1 + 0x12c7c));
  local_c0 = (MLyt *)((int)param_1 + 0x12ed4);
  ad::lyt::LytLocalize::localize(aLStack_b0,*(Layout **)((int)param_1 + 0x13024));
  fVar23 = 0.0;
  local_a0 = 0;
  piVar11 = (int *)(*(int *)((int)param_1 + 4) + 4);
  puVar13 = *(undefined4 **)((int)param_1 + 0x12b34);
  *(undefined4 **)(*(int *)((int)param_1 + 0x12b30) + 4) = puVar13;
  *puVar13 = *(undefined4 *)((int)param_1 + 0x12b30);
  piVar6 = (int *)((int)param_1 + 0x12b30);
  if (piVar6 != (int *)0x0) {
    iVar14 = *piVar11;
    *(int **)((int)param_1 + 0x12b34) = piVar11;
    *piVar6 = iVar14;
    *(int **)(iVar14 + 4) = piVar6;
    *piVar11 = (int)piVar6;
  }
  *(undefined4 *)((int)param_1 + 0x12c68) = 0x400;
  piVar6 = (int *)(*(int *)((int)param_1 + 4) + 0xc);
  puVar13 = *(undefined4 **)(local_c0 + 8);
  *(undefined4 **)(*(int *)(local_c0 + 4) + 4) = puVar13;
  *puVar13 = *(undefined4 *)(local_c0 + 4);
  pMVar12 = local_c0 + 4;
  if (pMVar12 != (MLyt *)0x0) {
    iVar14 = *piVar6;
    *(int **)(local_c0 + 8) = piVar6;
    *(int *)pMVar12 = iVar14;
    *(MLyt **)(iVar14 + 4) = pMVar12;
    *piVar6 = (int)pMVar12;
  }
  *(undefined4 *)(local_c0 + 0x13c) = 0x401;
  iVar14 = msys::MComSys::_sys;
  local_f8 = *(int *)((int)param_1 + 4);
  iVar16 = *(int *)((int)param_1 + 8);
  if (*(int *)((int)param_1 + 8) == 0) {
    *(int *)((int)param_1 + 8) = msys::MComSys::_sys;
    iVar16 = iVar14;
  }
  pvVar4 = *(void **)(iVar16 + 0xe904c);
  *(undefined4 *)((int)param_1 + 0x28b44) = *(undefined4 *)(local_f8 + 0x18);
  *(undefined4 *)((int)param_1 + 0x28b48) = 0;
  *(undefined4 *)((int)param_1 + 0x28b4c) = 0x401;
  *(undefined4 *)((int)param_1 + 0x28b08) = 0x401;
  *(undefined4 *)((int)param_1 + 0x28b0c) = 0;
  *(undefined4 *)((int)param_1 + 0x28b10) = 0;
  *(undefined1 *)((int)param_1 + 0x28b30) = 1;
  *(undefined1 *)((int)param_1 + 0x28b31) = 0;
  *(undefined4 *)((int)param_1 + 0x28b38) = 0xffffffff;
  *(undefined4 *)((int)param_1 + 0x28b3c) = 0xffffffff;
  *(int *)((int)param_1 + 0x28b28) = (int)param_1 + 0x28b40;
  *(undefined4 *)((int)param_1 + 0x28b2c) = 0;
  Message::init((Message *)((int)param_1 + 0x21da4));
  Message::setMsgDat((Message *)((int)param_1 + 0x21da4),pvVar4);
  FUN_100039d8((int)param_1 + 0x21c58);
  *(undefined4 *)((int)param_1 + 0x28b54) = 0x401;
  *(undefined4 *)((int)param_1 + 0x28b58) = 0;
  *(undefined4 *)((int)param_1 + 0x28b5c) = 0;
  *(undefined1 *)((int)param_1 + 0x28b7c) = 1;
  *(undefined1 *)((int)param_1 + 0x28b7d) = 0;
  *(undefined4 *)((int)param_1 + 0x28b84) = 0xffffffff;
  *(undefined4 *)((int)param_1 + 0x28b88) = 0xffffffff;
  *(int *)((int)param_1 + 0x28b74) = (int)param_1 + 0x28b8c;
  *(undefined4 *)((int)param_1 + 0x28b78) = 0;
  piVar11 = (int *)(local_f8 + 0xc);
  puVar13 = *(undefined4 **)((int)param_1 + 0x21c60);
  *(undefined4 **)(*(int *)((int)param_1 + 0x21c5c) + 4) = puVar13;
  *puVar13 = *(undefined4 *)((int)param_1 + 0x21c5c);
  piVar6 = (int *)((int)param_1 + 0x21c5c);
  if (piVar6 != (int *)0x0) {
    iVar14 = *piVar11;
    *(int **)((int)param_1 + 0x21c60) = piVar11;
    *piVar6 = iVar14;
    *(int **)(iVar14 + 4) = piVar6;
    *piVar11 = (int)piVar6;
  }
  *(undefined4 *)((int)param_1 + 0x21d94) = 0x401;
  local_40 = (MChrBase *)((int)param_1 + 0x28b90);
  msys::MLyt::attachMChr(local_c0,local_40,"INS_LIST_MINIGAME",(char *)0x0,(char *)0x0,(char *)0x0);
  local_40[0x141] = (MChrBase)0x0;
  local_90 = (int)param_1 + 0x2fe28;
  FUN_10002cec(local_90,param_1);
  this_02 = (MMsg *)((int)param_1 + 0x19f0c);
  *(undefined4 *)((int)param_1 + 0x20b40) = *(undefined4 *)(*(int *)((int)param_1 + 4) + 0x18);
  *(undefined4 *)((int)param_1 + 0x20b44) = 0;
  *(undefined4 *)((int)param_1 + 0x20b4c) = 0x401;
  *(undefined4 *)((int)param_1 + 0x20b48) = 0;
  MessageSimple::init((MessageSimple *)((int)param_1 + 0x1a058));
  FUN_100039d8(this_02);
  *(undefined1 *)((int)param_1 + 0x1fb14) = 1;
  *(undefined1 *)((int)param_1 + 0x1fb15) = 1;
  iVar14 = msys::MComSys::_sys;
  iVar16 = *(int *)((int)param_1 + 8);
  if (*(int *)((int)param_1 + 8) == 0) {
    *(int *)((int)param_1 + 8) = msys::MComSys::_sys;
    iVar16 = iVar14;
  }
  uVar7 = LMS_GetTextIndexByLabel(iVar16 + 0xe9058,"MES_MesDat_MiniGame_end_info3");
  pwVar8 = (wchar_t *)LMS_GetText(iVar16 + 0xe9058,uVar7);
  msys::MMsg::playStr(this_02,pwVar8,(InsParam *)0x0,false);
  msys::MLyt::attachMChr
            (local_c0,(MChrBase *)this_02,"INS_RECHARANGE_TEXT",(char *)0x0,(char *)0x0,(char *)0x0)
  ;
  iVar14 = 0;
  local_88[0] = "btn_MINIGAME_DONT";
  local_88[1] = "btn_MINIGAME_RESTART";
  local_88[2] = "btn_MINIGAME_BSTART";
  local_88[3] = "btn_RETURN";
  do {
    this_00 = (AnimButton *)
              ad::ctrl::ButtonGroup::FindButtonByName
                        ((ButtonGroup *)((int)param_1 + 0x12a14),local_88[iVar14]);
    *(AnimButton **)((int)param_1 + iVar14 * 4 + 0x132b8) = this_00;
    ad::ctrl::AnimButton::SetStateChangeCallback
              (this_00,(_func_void_AnimButton_ptr_State_State_void_ptr *)&DAT_10006490,param_1);
    *(int *)(*(int *)((int)param_1 + iVar14 * 4 + 0x132b8) + 0x48) = iVar14;
    piVar6 = *(int **)((int)param_1 + iVar14 * 4 + 0x132b8);
    (**(code **)(*piVar6 + 0x28))(piVar6,0);
    iVar14 = iVar14 + 1;
  } while (iVar14 < 4);
  iVar14 = msys::MLyt::getParts(local_c0,"btn_GUIDE",(char *)0x0,(char *)0x0);
  *(byte *)(iVar14 + 0x44) = *(byte *)(iVar14 + 0x44) & 0xfe;
  iVar14 = msys::MComSys::_sys;
  iVar16 = *(int *)((int)param_1 + 8);
  if (*(int *)((int)param_1 + 8) == 0) {
    *(int *)((int)param_1 + 8) = msys::MComSys::_sys;
    iVar16 = iVar14;
  }
  pMVar17 = (MCursorBase *)((int)param_1 + 0x1327c);
  local_f4 = pMVar17;
  iVar14 = ad::fw::TaskBase::isFps30(*(TaskBase **)(iVar16 + 4));
  uVar7 = extraout_s0;
  if (iVar14 != 0) {
    uVar7 = 0x40000000;
  }
  if (iVar14 == 0) {
    uVar7 = 0x3f800000;
  }
  (**(code **)(*(int *)pMVar17 + 8))(uVar7,pMVar17,iVar16 + 0xe9124);
  pMVar17 = local_f4;
  uVar15 = 0;
  pMVar12 = local_c0;
  if (*(int *)(local_f4 + 0x30) == 0) {
    cVar21 = '\0';
  }
  else if (*(int *)(local_f4 + 0x34) == 0) {
    cVar21 = '\x01';
  }
  else if (*(int *)(local_f4 + 0x38) == 0) {
    cVar21 = '\x02';
  }
  else {
    cVar21 = -1;
  }
  do {
    cVar2 = (char)uVar15;
    uVar7 = msys::MLyt::getParts(pMVar12,local_88[uVar15],(char *)0x0,(char *)0x0);
    uVar15 = uVar15 + 1;
    *(undefined4 *)(pMVar17 + (char)(cVar21 + cVar2) * 4 + 0x30) = uVar7;
  } while (uVar15 < 3);
  msys::MCursorBase::setVisible(local_f4,false);
  if (*(char *)((int)param_1 + 0x44c70) == '\0') {
    iVar14 = 0;
  }
  else {
    iVar14 = 10;
  }
  puVar19 = &DAT_003f9dc0 + iVar14;
  msys::MLyt::setAnimeInfo(local_c0,3,0);
  msys::MLyt::setAnimeInfo(local_c0,4,0);
  msys::MLyt::setAnimeInfo(local_c0,5,0);
  local_dc[0] = (LytAnim)0x0;
  local_d8 = 0;
  uStack_d4 = 0x3f800000;
  local_d0 = 0;
  local_cc = 1;
  local_ca = 0;
  local_c8 = (AnimTransform *)0x0;
  local_c4 = 0;
  ad::lyt::LytAnim::init(local_dc,*(Layout **)((int)param_1 + 0x12c7c),"FADE_IN","");
  uVar7 = ad::lyt::AnimTransform::GetFrameSize(local_c8);
  fVar22 = (float)VectorUnsignedToFloat(uVar7,(byte)(in_fpscr >> 0x16) & 3);
  ad::lyt::LytAnim::stopAndSetFrm(local_dc,fVar22);
  ad::lyt::LytAnim::term(local_dc,true);
  ad::lyt::LytAnim::init(local_dc,*(Layout **)((int)param_1 + 0x12c7c),"SET_MINIGAME","");
  fVar22 = (float)VectorSignedToFloat((int)*(char *)((int)param_1 + 0x44c70),
                                      (byte)(in_fpscr >> 0x16) & 3);
  ad::lyt::LytAnim::stopAndSetFrm(local_dc,fVar22);
  ad::lyt::LytAnim::term(local_dc,true);
  ad::lyt::LytAnim::init(local_dc,*(Layout **)(local_c0 + 0x150),"FADE_IN","");
  uVar7 = ad::lyt::AnimTransform::GetFrameSize(local_c8);
  fVar22 = (float)VectorUnsignedToFloat(uVar7,(byte)(in_fpscr >> 0x16) & 3);
  ad::lyt::LytAnim::stopAndSetFrm(local_dc,fVar22);
  ad::lyt::LytAnim::term(local_dc,true);
  ad::lyt::LytAnim::init(local_dc,*(Layout **)(local_c0 + 0x150),"SET_MINIGAME","");
  fVar22 = (float)VectorSignedToFloat((int)*(char *)((int)param_1 + 0x44c70),
                                      (byte)(in_fpscr >> 0x16) & 3);
  ad::lyt::LytAnim::stopAndSetFrm(local_dc,fVar22);
  ad::lyt::LytAnim::term(local_dc,true);
  if (*(char *)((int)param_1 + 0x44c70) == '\0') {
    FUN_10006944(param_1,puVar19,"pnl_MINIGAME_MEDAL_ML",&DAT_1000e5b8,6);
    ad::lyt::LytAnim::init
              (local_dc,*(Layout **)((int)param_1 + 0x12c7c),"SET_BASE","pnl_MINIGAME_MEDAL_ML");
    ad::lyt::LytAnim::stopAndSetFrm(local_dc,0.0);
    ad::lyt::LytAnim::term(local_dc,true);
  }
  else {
    FUN_10006944(param_1,puVar19,"pnl_MINIGAME_MEDAL_K",&DAT_1000e618,4);
    ad::lyt::LytAnim::init
              (local_dc,*(Layout **)((int)param_1 + 0x12c7c),"SET_BASE","pnl_MINIGAME_MEDAL_K");
    ad::lyt::LytAnim::stopAndSetFrm(local_dc,0.0);
    ad::lyt::LytAnim::term(local_dc,true);
  }
  uVar7 = *(undefined4 *)(*(int *)((int)param_1 + 4) + 0x18);
  *(undefined4 *)((int)param_1 + 0x19f08) = 0x400;
  *(undefined4 *)((int)param_1 + 0x19efc) = uVar7;
  *(undefined4 *)((int)param_1 + 0x19f00) = 0;
  *(undefined4 *)((int)param_1 + 0x19f04) = 0;
  MessageSimple::init((MessageSimple *)((int)param_1 + 0x13414));
  FUN_100039d8((MChrBase *)((int)param_1 + 0x132c8));
  *(undefined1 *)((int)param_1 + 0x18ed0) = 1;
  *(undefined1 *)((int)param_1 + 0x18ed1) = 1;
  msys::MLyt::attachMChr
            (pMVar5,(MChrBase *)((int)param_1 + 0x132c8),"INS_TOP_PANEL_TEXT","EXP_PNL_U",
             (char *)0x0,(char *)0x0);
  msys::MLyt::createAnimeAutoSlot(pMVar5,"EXP_arrow_loop","EXP_PNL_U",(char *)0x0);
  ad::lyt::LytAnim::init
            (local_dc,*(Layout **)((int)param_1 + 0x12c7c),"SET_PANEL_PLANE","EXP_PNL_U");
  uVar7 = ad::lyt::AnimTransform::GetFrameSize(local_c8);
  fVar22 = (float)VectorUnsignedToFloat(uVar7,(byte)(in_fpscr >> 0x16) & 3);
  ad::lyt::LytAnim::stopAndSetFrm(local_dc,fVar22);
  ad::lyt::LytAnim::term(local_dc,true);
  msys::MLyt::stopAnimeAndSetEnd(pMVar5,3,0,"EXP_PNL_U",(char *)0x0);
  local_d0 = 0;
  iVar14 = GameMain::GameModeOld();
  if (iVar14 == 10) {
    uVar15 = 0;
    while( true ) {
      iVar14 = btl::GetBootInfo();
      fVar22 = (float)VectorUnsignedToFloat
                                ((uint)*(ushort *)
                                        (*(int *)((int)param_1 + 0x44c68) + uVar15 * 0x18 + 0x12),
                                 (byte)(in_fpscr >> 0x16) & 3);
      in_fpscr = in_fpscr & 0xfffffff;
      if (*(float *)(iVar14 + 0x114) == fVar22) break;
      uVar15 = uVar15 + 1;
    }
    iVar14 = btl::GetBootInfo();
    iVar18 = *(int *)(iVar14 + 0x124);
    piVar6 = (int *)msys::MListWndPBase::getListWnd((MListWndPBase *)local_40);
    (**(code **)(*piVar6 + 0x28))(piVar6,uVar15 & 0xff);
    ad::lyt::LytNumReel3::InitParam::InitParam((InitParam *)local_88);
    iVar14 = msys::MComSys::_sys;
    iVar16 = *(int *)((int)param_1 + 8);
    if (*(int *)((int)param_1 + 8) == 0) {
      *(int *)((int)param_1 + 8) = msys::MComSys::_sys;
      iVar16 = iVar14;
    }
    msys::MLytNumRes::set((MLytNumRes *)(iVar16 + 0x844),local_88,2,2,0xff);
    iVar14 = msys::MComSys::_sys;
    local_57 = 2;
    iVar16 = *(int *)((int)param_1 + 8);
    if (*(int *)((int)param_1 + 8) == 0) {
      *(int *)((int)param_1 + 8) = msys::MComSys::_sys;
      iVar16 = iVar14;
    }
    local_8c = (MChrBase *)((int)param_1 + 0x20b50);
    local_74 = iVar18;
    msys::MLytNum::init((MLytNum *)local_8c,(InitParam *)local_88,(LytDrawData *)(iVar16 + 0xd3000),
                        local_c0,"NUM",(char *)0x0,(char *)0x0,(char *)0x0);
    msys::MLyt::attachMChr(local_c0,local_8c,"NUM",(char *)0x0,(char *)0x0,(char *)0x0);
    sVar3 = (short)uVar15;
    sVar24 = sVar3 * 3;
    psVar20 = puVar19 + uVar15;
    psVar9 = (short *)(*(int *)((int)param_1 + 0x44c68) + uVar15 * 0x18);
    iVar14 = (int)*psVar20;
    if (iVar14 < *psVar9) {
      iVar14 = -1;
    }
    else if (iVar14 < psVar9[1]) {
      iVar14 = 0;
    }
    else if (iVar14 < psVar9[2]) {
      iVar14 = 1;
    }
    else {
      iVar14 = 2;
    }
    if (iVar18 < *psVar9) {
      iVar16 = -1;
    }
    else if (iVar18 < psVar9[1]) {
      iVar16 = 0;
    }
    else if (iVar18 < psVar9[2]) {
      iVar16 = 1;
    }
    else {
      iVar16 = 2;
    }
    local_f4 = (MCursorBase *)0x0;
    local_f0 = 0x3f800000;
    local_ec = 0;
    local_e8 = 1;
    local_e6 = 0;
    ad::lyt::LytAnim::init
              ((LytAnim *)&local_f8,*(Layout **)(local_c0 + 0x150),"CONGRATULATIONS_ONOFF","");
    if (*psVar20 < iVar18) {
      if (0 < iVar18) {
        if (iVar14 < iVar16) {
          sVar24 = sVar24 + (short)iVar16;
          if (*(char *)((int)param_1 + 0x44c70) == '\0') {
            FUN_100065ec(param_1,"pnl_MINIGAME_MEDAL_ML",&DAT_1000e5b8 + uVar15 * 0x10,(int)sVar3,
                         iVar16,(int)(short)(sVar24 + 0xc));
          }
          else {
            FUN_100065ec(param_1,"pnl_MINIGAME_MEDAL_K",&DAT_1000e618 + uVar15 * 0x10,(int)sVar3,
                         iVar16,(int)sVar24);
          }
        }
        uVar7 = ad::lyt::AnimTransform::GetFrameSize(local_e4);
        fVar23 = (float)VectorUnsignedToFloat(uVar7,(byte)(in_fpscr >> 0x16) & 3);
      }
      ad::lyt::LytAnim::stopAndSetFrm((LytAnim *)&local_f8,fVar23);
      *psVar20 = (short)iVar18;
      *(short *)((int)param_1 + uVar15 * 0x1c + 0x2fb14) = (short)iVar18;
      pcVar10 = FUN_10002b70;
    }
    else {
      ad::lyt::LytAnim::stopAndSetFrm((LytAnim *)&local_f8,0.0);
      pcVar10 = FUN_10004614;
    }
    *(code **)((int)param_1 + 0x12a0c) = pcVar10;
    *(undefined4 *)((int)param_1 + 0x12a10) = 0;
    ad::lyt::LytAnim::term((LytAnim *)&local_f8,true);
    SndSys::start((SndSys *)&gSndSys,0x100035b,(SoundHandle *)&gSndSys);
    *(code **)((int)param_1 + 0x12a04) = FUN_100044dc;
    *(undefined4 *)((int)param_1 + 0x12a08) = 0;
    local_ec = 0;
  }
  else {
    this_01 = (BootInfo *)atk_mg::GetBootInfo();
    atk_mg::BootInfo::saveBgm(this_01);
    *(code **)((int)param_1 + 0x12a04) = FUN_10001cbc;
    *(undefined4 *)((int)param_1 + 0x12a08) = 0;
  }
  FUN_10003d68(param_1,0);
  iVar14 = msys::MListWndPBase::getCurNo((MListWndPBase *)local_40);
  iVar14 = ad::db::GetPcAttack(*(ushort *)(*(int *)((int)param_1 + 0x44c68) + iVar14 * 0x18 + 0x12))
  ;
  uVar1 = *(ushort *)(iVar14 + 0xe);
  uVar15 = *(uint *)(&DAT_003f97fc + (uVar1 >> 5 & 0x7fff87f) * 4);
  iVar14 = msys::MListWndPBase::getCurNo((MListWndPBase *)local_40);
  FUN_10003b24(local_90,*(int *)((int)param_1 + 0x44c68) + iVar14 * 0x18,
               (uVar15 >> (uVar1 & 0x1f) & 1) != 0);
  *(undefined1 **)((int)param_1 + 0x129fc) = &LAB_10004770;
  *(undefined4 *)((int)param_1 + 0x12a00) = 0;
  return;
}


// FUNC 0x100016d4 FUN_100016d4 (AttackMiniGame)
//   size 0xd8 | file AttackMiniGame+0x16d4 | callers(0) | datarefs 2

void FUN_100016d4(int param_1)

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
        *(code **)(param_1 + 0x12a04) = FUN_10001c08;
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
  *(code **)(param_1 + 0x12a04) = FUN_100049dc;
  *(undefined4 *)(param_1 + 0x12a08) = 0;
  return;
}


// FUNC 0x100017e0 FUN_100017e0 (AttackMiniGame)
//   size 0x360 | file AttackMiniGame+0x17e0 | callers(0) | datarefs 1

void FUN_100017e0(int param_1,uint *param_2)

{
  MListWndPBase *this;
  int iVar1;
  int *piVar2;
  MLyt *this_00;
  LytAnim *this_01;
  int iVar3;
  undefined4 uVar4;
  wchar_t *pwVar5;
  uint uVar6;
  char *pcVar7;
  bool bVar8;
  
  this = (MListWndPBase *)(param_1 + 0x28b90);
  iVar1 = msys::MListWndPBase::isTpNeutral(this);
  if (iVar1 != 0) {
    iVar1 = msys::MListWndPBase::getCurNo(this);
    iVar1 = ad::db::GetPcAttack(*(ushort *)(*(int *)(param_1 + 0x44c68) + iVar1 * 0x18 + 0x12));
    bVar8 = (*(uint *)(&DAT_003f97fc + (*(ushort *)(iVar1 + 0xe) >> 5 & 0x7fff87f) * 4) >>
             (*(ushort *)(iVar1 + 0xe) & 0x1f) & 1) != 0;
    piVar2 = (int *)msys::MListWndPBase::getCurItem();
    if ((piVar2 == (int *)0x0) || (iVar1 = msys::MListWndPBase::getSelectItem(this), iVar1 == 0)) {
      if ((*param_2 & 0x802) != 0) {
        (**(code **)(**(int **)(param_1 + 0x132c4) + 0x10))();
        FUN_10003d68(param_1,0);
      }
    }
    else if (bVar8) {
      FUN_10003dd4(param_1,0x110016,0,0,0);
      FUN_10003d68(param_1,0);
      *(code **)(param_1 + 0x12a04) = FUN_10004954;
      *(undefined4 *)(param_1 + 0x12a08) = 0;
    }
    else {
      FUN_10003dd4(param_1,0x110018,0,0,0);
    }
    iVar1 = msys::MListWndPBase::getCurNo(this);
    FUN_10003b24(param_1 + 0x2fe28,*(int *)(param_1 + 0x44c68) + iVar1 * 0x18,bVar8);
    this_00 = (MLyt *)(param_1 + 0x12b2c);
    if ((piVar2 != (int *)0x0) && (*(int **)(param_1 + 0x2fe20) != piVar2)) {
      if (-1 < *(int *)(param_1 + 0x2fe24)) {
        this_01 = (LytAnim *)msys::MLyt::getAnim(this_00,(ushort)*(int *)(param_1 + 0x2fe24) & 0xff)
        ;
        ad::lyt::LytAnim::stopAndSetFrm(this_01,0.0);
      }
      if ((*(ushort *)(piVar2 + 1) == 0xffff) ||
         (iVar1 = *piVar2,
         (int)(uint)*(ushort *)(piVar2 + 1) <
         (int)*(short *)(*(int *)(param_1 + 0x44c68) + iVar1 * 0x18))) {
        *(undefined4 *)(param_1 + 0x2fe24) = 0xffffffff;
      }
      else if ((int)*(uint *)(param_1 + 0x2fe24) < 0) {
        if (*(char *)(param_1 + 0x44c70) == '\0') {
          uVar4 = msys::MLyt::createAnimeAutoSlot
                            (this_00,(&PTR_s_LOOP_MEDAL_ML_01_1000e658)[iVar1],
                             "pnl_MINIGAME_MEDAL_ML",(char *)0x0);
        }
        else {
          uVar4 = msys::MLyt::createAnimeAutoSlot
                            (this_00,*(char **)(&DAT_1000e670 + iVar1 * 4),"pnl_MINIGAME_MEDAL_K",
                             (char *)0x0);
        }
        *(undefined4 *)(param_1 + 0x2fe24) = uVar4;
      }
      else {
        uVar6 = *(uint *)(param_1 + 0x2fe24) & 0xff;
        if (*(char *)(param_1 + 0x44c70) == '\0') {
          msys::MLyt::createAnime
                    (this_00,uVar6,(&PTR_s_LOOP_MEDAL_ML_01_1000e658)[iVar1],"pnl_MINIGAME_MEDAL_ML"
                     ,1,0xffffffff);
        }
        else {
          msys::MLyt::createAnime
                    (this_00,uVar6,*(undefined4 *)(&DAT_1000e670 + iVar1 * 4),"pnl_MINIGAME_MEDAL_K"
                     ,1,0xffffffff);
        }
      }
      *(int **)(param_1 + 0x2fe20) = piVar2;
    }
    if (bVar8) {
      if (*(char *)(param_1 + 0x44c70) == '\0') {
        uVar6 = msys::MListWndPBase::getCurNo(this);
        if (uVar6 < 5) {
          pcVar7 = "MES_MiniGame_Mg05";
        }
        else {
          pcVar7 = "MES_MiniGame_Mg06";
        }
      }
      else {
        pcVar7 = "MES_MiniGame_Mg07";
      }
    }
    else {
      pcVar7 = "MES_MiniGame_Mg08";
    }
    iVar3 = msys::MLyt::getAnime(this_00,3);
    iVar1 = msys::MComSys::_sys;
    bVar8 = iVar3 == 0;
    if (!bVar8) {
      bVar8 = *(float *)(iVar3 + 0xc) == 0.0;
    }
    if (!bVar8) {
      bVar8 = (*(byte *)(iVar3 + 0x12) & 1) == 0;
    }
    if (bVar8) {
      iVar3 = *(int *)(param_1 + 8);
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar3 = iVar1;
      }
      uVar4 = LMS_GetTextIndexByLabel(iVar3 + 0xe9058,pcVar7);
      pwVar5 = (wchar_t *)LMS_GetText(iVar3 + 0xe9058,uVar4);
      msys::MMsg::playStr((MMsg *)(param_1 + 0x132c8),pwVar5,(InsParam *)0x0,false);
      msys::MLyt::playAnimeFromNo(this_00,3,1,"EXP_PNL_U",(char *)0x0);
    }
  }
  return;
}


// FUNC 0x10001c08 FUN_10001c08 (AttackMiniGame)
//   size 0xa4 | file AttackMiniGame+0x1c08 | callers(0) | datarefs 4

void FUN_10001c08(int param_1)

{
  int iVar1;
  code *pcVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  iVar1 = Backup::errorCode();
  if (iVar1 == 0) {
    iVar1 = Backup::isBusyWriting((Backup *)(param_1 + 0x10));
    if (iVar1 != 0) {
      return;
    }
    Backup::term();
    Message::close((Message *)(param_1 + 0x21da4));
    *(code **)(param_1 + 0x12a0c) = FUN_10004614;
    *(undefined4 *)(param_1 + 0x12a10) = 0;
    iVar1 = FUN_10005f98(param_1);
    if (iVar1 == 0) {
      puVar4 = &DAT_1000816c;
    }
    else {
      puVar4 = &DAT_10008164;
    }
    pcVar2 = (code *)*puVar4;
    uVar3 = puVar4[1];
  }
  else if (iVar1 - 0x2001U < 2 || iVar1 == 0x2003) {
    pcVar2 = FUN_10003408;
    uVar3 = 0;
  }
  else {
    pcVar2 = FUN_100049dc;
    uVar3 = 0;
  }
  *(code **)(param_1 + 0x12a04) = pcVar2;
  *(undefined4 *)(param_1 + 0x12a08) = uVar3;
  return;
}


// FUNC 0x10001cbc FUN_10001cbc (AttackMiniGame)
//   size 0x64 | file AttackMiniGame+0x1cbc | callers(0) | datarefs 1

void FUN_10001cbc(int param_1)

{
  int iVar1;
  code *pcVar2;
  
  iVar1 = FUN_10005f98();
  if (iVar1 == 0) {
    pcVar2 = FUN_100046d0;
  }
  else {
    FUN_10003b24(param_1 + 0x2fe28,
                 *(int *)(param_1 + 0x44c68) + *(char *)(*(int *)(param_1 + 0x44c6c) + 8) * 0x18,1);
    *(code **)(param_1 + 0x12a0c) = FUN_100046d0;
    *(undefined4 *)(param_1 + 0x12a10) = 0;
    pcVar2 = FUN_10003044;
  }
  *(code **)(param_1 + 0x12a04) = pcVar2;
  *(undefined4 *)(param_1 + 0x12a08) = 0;
  return;
}


// FUNC 0x10001d24 FUN_10001d24 (AttackMiniGame)
//   size 0xc0 | file AttackMiniGame+0x1d24 | callers(0)

void FUN_10001d24(int param_1,undefined4 param_2,uint param_3)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  wchar_t *pwVar6;
  
  uVar3 = msys::MLyt::getAnime((MLyt *)(param_1 + 0x12b2c),3);
  iVar2 = msys::MComSys::_sys;
  if (uVar3 != 0) {
    bVar1 = *(float *)(uVar3 + 0xc) != 0.0;
    if (bVar1) {
      uVar3 = (uint)*(byte *)(uVar3 + 0x12);
    }
    if (bVar1 && (uVar3 & 1) != 0) {
      return;
    }
  }
  if (param_3 != 0) {
    iVar4 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar4 = iVar2;
    }
    uVar5 = LMS_GetTextIndexByLabel(iVar4 + 0xe9058,param_2);
    pwVar6 = (wchar_t *)LMS_GetText(iVar4 + 0xe9058,uVar5);
    msys::MMsg::playStr((MMsg *)(param_1 + 0x132c8),pwVar6,(InsParam *)0x0,false);
  }
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x12b2c),3,param_3,"EXP_PNL_U",(char *)0x0);
  return;
}


// FUNC 0x10002a3c FUN_10002a3c (AttackMiniGame)
//   size 0xe0 | file AttackMiniGame+0x2a3c | callers(0)

void FUN_10002a3c(int param_1)

{
  int iVar1;
  code *pcVar2;
  
  iVar1 = msys::MLyt::isEnableAnime((MLyt *)(param_1 + 0x12b2c));
  if ((iVar1 == 0) && (*(int *)(param_1 + 0x288a0) == 0)) {
    if (*(ushort *)(*(int *)(param_1 + 0x44c6c) + 0x7a) <
        *(ushort *)(*(int *)(param_1 + 0x44c6c) + 0x78)) {
      pcVar2 = FUN_10004a28;
    }
    else {
      msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x12ed4),6,0,(char *)0x0,(char *)0x0);
      if (*(int *)(*(int *)(param_1 + 0x44c6c) +
                  (uint)*(ushort *)(*(int *)(param_1 + 0x44c6c) + 0x7a) * 0xc + -8) == 0) {
        msys::MDfxChr::term((MDfxChr *)(param_1 + 0x21078));
        msys::MLyt::detachMChr((MLyt *)(param_1 + 0x12b2c),(MChrBase *)(param_1 + 0x21078));
      }
      Mem::Free(*(void **)(param_1 + 0x44c6c));
      *(undefined4 *)(param_1 + 0x44c6c) = 0;
      Message::close((Message *)(param_1 + 0x21da4));
      pcVar2 = FUN_1000348c;
    }
    *(code **)(param_1 + 0x12a04) = pcVar2;
    *(undefined4 *)(param_1 + 0x12a08) = 0;
  }
  return;
}


// FUNC 0x10002b28 FUN_10002b28 (AttackMiniGame)
//   size 0x44 | file AttackMiniGame+0x2b28 | callers(0) | datarefs 4

void FUN_10002b28(int param_1)

{
  FUN_1000394c();
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x12ed4),6,1,(char *)0x0,(char *)0x0);
  *(code **)(param_1 + 0x12a04) = FUN_100042dc;
  *(undefined4 *)(param_1 + 0x12a08) = 0;
  return;
}


// FUNC 0x10002b70 FUN_10002b70 (AttackMiniGame)
//   size 0x70 | file AttackMiniGame+0x2b70 | callers(0) | datarefs 2

void FUN_10002b70(int param_1)

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
  *(code **)(param_1 + 0x12a04) = FUN_10001c08;
  *(undefined4 *)(param_1 + 0x12a08) = 0;
  return;
}


// FUNC 0x10002bec FUN_10002bec (AttackMiniGame)
//   size 0xe0 | file AttackMiniGame+0x2bec | callers(0) | datarefs 2

void FUN_10002bec(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 local_1c;
  
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x12b2c),3,0,"EXP_PNL_U",(char *)0x0);
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x12b2c),0,0,(char *)0x0,(char *)0x0);
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x12ed4),0,0,(char *)0x0,(char *)0x0);
  iVar1 = msys::MComSys::_sys;
  iVar2 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar2 = iVar1;
  }
  local_1c = 0xff000000;
  MoveC::moveFrm((MoveC *)(iVar2 + 0x4acd4),(Color8 *)&local_1c,16.0);
  MoveC::moveFrm((MoveC *)(iVar2 + 0x4ad14),(Color8 *)&local_1c,16.0);
  *(undefined1 **)(param_1 + 0x12a04) = &LAB_100048fc;
  *(undefined4 *)(param_1 + 0x12a08) = 0;
  return;
}


// FUNC 0x10002cec FUN_10002cec (AttackMiniGame)
//   size 0x2b8 | file AttackMiniGame+0x2cec | callers(1) 0x1000149c

void FUN_10002cec(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  MLyt *this;
  undefined4 uVar3;
  int iVar4;
  MLytNum *this_00;
  MLyt *this_01;
  InitParam aIStack_78 [49];
  undefined1 local_47;
  
  ad::lyt::LytNumReel3::InitParam::InitParam(aIStack_78);
  iVar2 = msys::MComSys::_sys;
  iVar4 = *(int *)(param_2 + 8);
  if (*(int *)(param_2 + 8) == 0) {
    *(int *)(param_2 + 8) = msys::MComSys::_sys;
    iVar4 = iVar2;
  }
  msys::MLytNumRes::set((MLytNumRes *)(iVar4 + 0x844),aIStack_78,1,0xe,0x11);
  iVar4 = 0;
  this_01 = (MLyt *)(param_2 + 0x12ed4);
  local_47 = 2;
  do {
    iVar1 = *(int *)(param_2 + 8);
    iVar2 = iVar1;
    if (iVar1 == 0) {
      iVar2 = msys::MComSys::_sys;
    }
    if (iVar1 == 0) {
      *(int *)(param_2 + 8) = iVar2;
    }
    this_00 = (MLytNum *)(param_1 + iVar4 * 0x230);
    msys::MLytNum::init(this_00,aIStack_78,(LytDrawData *)(iVar2 + 0xd3000),this_01,
                        (char *)(&DAT_1000e680)[iVar4],"pnl_MINIGAME_MSCORE",(char *)0x0,(char *)0x0
                       );
    msys::MLyt::attachMChr
              (this_01,(MChrBase *)this_00,(char *)(&DAT_1000e680)[iVar4],"pnl_MINIGAME_MSCORE",
               (char *)0x0,(char *)0x0);
    iVar4 = iVar4 + 1;
  } while (iVar4 < 3);
  this = (MLyt *)(param_2 + 0x12b2c);
  ad::lyt::LytAnim::init
            ((LytAnim *)(param_1 + 0x6c8),*(Layout **)(param_2 + 0x12c7c),"SET_IMG",
             "pnl_MLK_SPECIAL");
  ad::lyt::LytAnim::init
            ((LytAnim *)(param_1 + 0x690),*(Layout **)(param_2 + 0x13024),"SET_MEDAL",
             "pnl_MINIGAME_MSCORE");
  ad::lyt::LytAnim::init
            ((LytAnim *)(param_1 + 0x6ac),*(Layout **)(param_2 + 0x13024),"MEDAL_ONOFF",
             "pnl_MINIGAME_MSCORE");
  msys::MCellAnime::init((MCellAnime *)(param_1 + 0x6e4),(Resource *)(param_2 + 0x12ae8));
  msys::MLyt::attachMChr
            (this_01,(MChrBase *)(param_1 + 0x6e4),"INS_TITLE",(char *)0x0,(char *)0x0,(char *)0x0);
  uVar3 = *(undefined4 *)(*(int *)(param_2 + 4) + 0x18);
  *(undefined4 *)(param_1 + 0x75a0) = 0x400;
  *(undefined4 *)(param_1 + 0x7594) = uVar3;
  *(undefined4 *)(param_1 + 0x7598) = 0;
  *(undefined4 *)(param_1 + 0x759c) = 0;
  MessageSimple::init((MessageSimple *)(param_1 + 0xaac));
  FUN_100039d8(param_1 + 0x960);
  *(undefined1 *)(param_1 + 0x7584) = 3;
  *(undefined **)(param_1 + 0x62d4) = &DAT_003fc0f8;
  MessageWriter::setFontColor((MessageWriter *)(param_1 + 0xaac),0xffffffff,true);
  *(undefined1 *)(param_1 + 0x6568) = 1;
  *(undefined1 *)(param_1 + 0x6569) = 1;
  *(undefined1 *)(param_1 + 0x7585) = 1;
  msys::MLyt::attachMChr
            (this,(MChrBase *)(param_1 + 0x960),"INS_ATTACK_TITLE","pnl_MLK_SPECIAL",(char *)0x0,
             (char *)0x0);
  uVar3 = *(undefined4 *)(*(int *)(param_2 + 4) + 0x18);
  *(undefined4 *)(param_1 + 0xe1e4) = 0x401;
  *(undefined4 *)(param_1 + 0xe1d8) = uVar3;
  *(undefined4 *)(param_1 + 0xe1dc) = 0;
  *(undefined4 *)(param_1 + 0xe1e0) = 0;
  MessageSimple::init((MessageSimple *)(param_1 + 0x76f0));
  FUN_100039d8((MChrBase *)(param_1 + 0x75a4));
  *(undefined1 *)(param_1 + 0xe1c8) = 3;
  *(undefined **)(param_1 + 0xcf18) = &DAT_003fc0f8;
  MessageWriter::setFontColor((MessageWriter *)(param_1 + 0x76f0),0xe6e6e6ff,true);
  *(undefined1 *)(param_1 + 0xd1ac) = 0;
  *(undefined1 *)(param_1 + 0xd1ad) = 1;
  *(undefined1 *)(param_1 + 0xe1c9) = 1;
  msys::MLyt::attachMChr
            (this_01,(MChrBase *)(param_1 + 0x75a4),"INS_TITLE",(char *)0x0,(char *)0x0,(char *)0x0)
  ;
  *(undefined2 *)(param_1 + 0x14e2c) = 0;
  *(undefined1 *)(param_1 + 0x14e2e) = 1;
  return;
}


// FUNC 0x10003044 FUN_10003044 (AttackMiniGame)
//   size 0x78 | file AttackMiniGame+0x3044 | callers(0) | datarefs 2

void FUN_10003044(int param_1)

{
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x12b2c),2,0,(char *)0x0,(char *)0x0);
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x12ed4),2,0,(char *)0x0,(char *)0x0);
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x12ed4),5,1,(char *)0x0,(char *)0x0);
  *(code **)(param_1 + 0x12a04) = FUN_1000453c;
  *(undefined4 *)(param_1 + 0x12a08) = 0;
  return;
}


// FUNC 0x100030c0 FUN_100030c0 (AttackMiniGame)
//   size 0xa4 | file AttackMiniGame+0x30c0 | callers(0) | datarefs 1

void FUN_100030c0(int param_1)

{
  BootInfo *this;
  
  msys::MLyt::createAnimeAutoSlot((MLyt *)(param_1 + 0x12b2c),"5_to_1",(char *)0x0,(char *)0x0);
  msys::MLyt::createAnimeAutoSlot((MLyt *)(param_1 + 0x12ed4),"5_to_1",(char *)0x0,(char *)0x0);
  msys::MLyt::setAnimeInfo((MLyt *)(param_1 + 0x12b2c),0,1);
  msys::MLyt::setAnimeInfo((MLyt *)(param_1 + 0x12ed4),0,1);
  SndSys::stopAllBgm((SndSys *)&gSndSys,0x10);
  this = (BootInfo *)atk_mg::GetBootInfo();
  atk_mg::BootInfo::restoreBgm(this);
  *(undefined1 *)(param_1 + 0x28cd1) = 1;
  FUN_10003d68(param_1,0);
  *(code **)(param_1 + 0x12a04) = FUN_10005154;
  *(undefined4 *)(param_1 + 0x12a08) = 0;
  return;
}


// FUNC 0x10003178 FUN_10003178 (AttackMiniGame)
//   size 0x1cc | file AttackMiniGame+0x3178 | callers(0) | datarefs 2

/* WARNING: Removing unreachable block (ram,0x100032cc) */

void FUN_10003178(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  MDfxChr *this;
  int iVar6;
  
  if (*(short *)(*(int *)(param_1 + 0x1325c) + 0x10) == 1) {
    iVar5 = msys::MLyt::isBusyTblAnime((MLyt *)(param_1 + 0x12ed4),4);
    iVar6 = msys::MComSys::_sys;
    if (iVar5 != 0) {
      return;
    }
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
    this = (MDfxChr *)(param_1 + 0x211f4);
    msys::MDfxChr::init(this,*(MemAlcBase **)(*(int *)(param_1 + 4) + 0x18),
                        *(MDfxSys **)(iVar6 + 0xe64f0),(Scene *)(iVar5 + 0x4aba4),0x401);
    msys::MDfxChr::playDfx(this,0x2f);
    if ((((byte)nn::math::VEC3::Zero()::zero & 1) == 0) &&
       (iVar6 = __cxa_guard_acquire(&nn::math::VEC3::Zero()::zero), iVar6 != 0)) {
      nn::math::VEC3::Zero()::zero = 0;
      DAT_00434c4c = 0;
      DAT_00434c50 = 0;
      __cxa_guard_release(&nn::math::VEC3::Zero()::zero);
    }
    MoveVBase::stop((MoveVBase *)(param_1 + 0x212c0));
    uVar4 = DAT_00434c50;
    uVar3 = DAT_00434c4c;
    uVar2 = nn::math::VEC3::Zero()::zero;
    *(undefined4 *)(param_1 + 0x212dc) = nn::math::VEC3::Zero()::zero;
    *(undefined4 *)(param_1 + 0x212e0) = uVar3;
    *(undefined4 *)(param_1 + 0x212e4) = uVar4;
    *(undefined4 *)(param_1 + 0x212c4) = uVar2;
    *(undefined4 *)(param_1 + 0x212c8) = uVar3;
    *(undefined4 *)(param_1 + 0x212cc) = uVar4;
    msys::MLyt::attachMChr
              ((MLyt *)(param_1 + 0x12ed4),(MChrBase *)this,"INS_MEDAL_EFFECT_TOP",(char *)0x0,
               (char *)0x0,(char *)0x0);
  }
  *(undefined4 *)(param_1 + 0x12a04) = 0x10004670;
  *(undefined4 *)(param_1 + 0x12a08) = 0;
                    /* WARNING: Could not recover jumptable at 0x100032e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(param_1 + 0x12a04))(param_1,param_2);
  return;
}


// FUNC 0x10003320 FUN_10003320 (AttackMiniGame)
//   size 0xd0 | file AttackMiniGame+0x3320 | callers(0) | datarefs 1

void FUN_10003320(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 local_1c;
  
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x12b2c),2,1,(char *)0x0,(char *)0x0);
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x12ed4),2,1,(char *)0x0,(char *)0x0);
  SndSys::stopAllBgm((SndSys *)&gSndSys,0x10);
  iVar1 = msys::MComSys::_sys;
  iVar2 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar2 = iVar1;
  }
  local_1c = 0xff000000;
  MoveC::moveFrm((MoveC *)(iVar2 + 0x4acd4),(Color8 *)&local_1c,16.0);
  MoveC::moveFrm((MoveC *)(iVar2 + 0x4ad14),(Color8 *)&local_1c,16.0);
  *(undefined1 **)(param_1 + 0x12a04) = &LAB_10005228;
  *(undefined4 *)(param_1 + 0x12a08) = 0;
  return;
}


// FUNC 0x10003408 FUN_10003408 (AttackMiniGame)
//   size 0x6c | file AttackMiniGame+0x3408 | callers(0) | datarefs 2

void FUN_10003408(int param_1)

{
  int *piVar1;
  int iVar2;
  
  FUN_100038e0(param_1 + 0x21c58,"menu_save_err_01",0);
  iVar2 = 0;
  do {
    piVar1 = *(int **)(param_1 + iVar2 * 4 + 0x132b8);
    (**(code **)(*piVar1 + 0x28))(piVar1,0);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 4);
  FUN_10003d68(param_1,0);
  *(code **)(param_1 + 0x12a04) = FUN_10005318;
  *(undefined4 *)(param_1 + 0x12a08) = 0;
  return;
}


// FUNC 0x1000348c FUN_1000348c (AttackMiniGame)
//   size 0x74 | file AttackMiniGame+0x348c | callers(0) | datarefs 2

void FUN_1000348c(int param_1)

{
  int iVar1;
  
  iVar1 = msys::MLyt::isEnableAnime((MLyt *)(param_1 + 0x12ed4));
  if (iVar1 == 0) {
    msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x12ed4),5,0,(char *)0x0,(char *)0x0);
    ad::lyt::LytAnim::stop(*(LytAnim **)(param_1 + 0x44c5c));
    ad::lyt::LytAnim::term(*(LytAnim **)(param_1 + 0x44c5c),true);
    *(undefined4 *)(param_1 + 0x44c5c) = 0;
    *(undefined4 *)(param_1 + 0x12a04) = *(undefined4 *)(param_1 + 0x12a0c);
    *(undefined4 *)(param_1 + 0x12a08) = *(undefined4 *)(param_1 + 0x12a10);
  }
  return;
}


// FUNC 0x10003500 FUN_10003500 (AttackMiniGame)
//   size 0xd0 | file AttackMiniGame+0x3500 | callers(0) | datarefs 2

void FUN_10003500(int param_1,uint *param_2)

{
  uint uVar1;
  
  uVar1 = *param_2;
  if (((uVar1 & 0x802) == 0) || (*(char *)(param_1 + 0x13294) == '\0')) {
    if ((uVar1 & 0x401) == 0) {
      if ((uVar1 & 0x30) != 0) {
        FUN_10003dd4(param_1,0x110015,0,0,0);
        *(bool *)(param_1 + 0x13294) = *(char *)(param_1 + 0x13294) == '\0';
      }
    }
    else {
      (**(code **)(**(int **)(param_1 + *(char *)(param_1 + 0x13294) * 4 + 0x132b8) + 0x10))();
      FUN_10003d68(param_1,0);
    }
  }
  else {
    FUN_10003dd4(param_1,0x110015,0,0,0);
    *(undefined1 *)(param_1 + 0x13294) = 0;
  }
  FUN_10003648(param_1 + 0x1327c);
  return;
}


// FUNC 0x100035e0 FUN_100035e0 (AttackMiniGame)
//   size 0x34 | file AttackMiniGame+0x35e0 | callers(1) 0x10006cb0 | datarefs 3

void FUN_100035e0(undefined1 *param_1)

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


// FUNC 0x1000361c FUN_1000361c (AttackMiniGame)
//   size 0x2c | file AttackMiniGame+0x361c | callers(1) 0x10004a28

void FUN_1000361c(undefined4 param_1,uint param_2,int param_3,undefined4 param_4,undefined1 param_5)

{
  undefined1 uStack00000000;
  
  if (param_3 + 1U < param_2) {
    param_2 = param_3 + 1U;
  }
  __c89vswprintf(param_1,param_2,param_4,&param_5);
  return;
}


// FUNC 0x10003648 FUN_10003648 (AttackMiniGame)
//   size 0x280 | file AttackMiniGame+0x3648 | callers(4) 0x10003500 0x100056e4 0x100057b0 0x10004798

void FUN_10003648(int param_1)

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


// FUNC 0x100038e0 FUN_100038e0 (AttackMiniGame)
//   size 0x60 | file AttackMiniGame+0x38e0 | callers(4) 0x10003408 0x100049dc 0x10005318 0x10004a28

void FUN_100038e0(int param_1,undefined4 param_2,undefined4 param_3)

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


// FUNC 0x1000394c FUN_1000394c (AttackMiniGame)
//   size 0x84 | file AttackMiniGame+0x394c | callers(4) 0x10002b28 0x10003178 0x100042dc 0x1000436c

void FUN_1000394c(int param_1)

{
  int iVar1;
  uint uVar2;
  MDfxChr *this;
  bool bVar3;
  
  if (*(short *)(*(int *)(param_1 + 0x1325c) + 0x10) == 1) {
    this = (MDfxChr *)(param_1 + 0x211f4);
    iVar1 = (**(code **)(*(int *)this + 0x24))(this);
    if (iVar1 == 0) {
      uVar2 = *(uint *)(param_1 + 0x21348);
      if (uVar2 != 0) {
        bVar3 = *(int *)(uVar2 + 4) != uVar2 + 4;
        if (!bVar3) {
          uVar2 = (uint)*(byte *)(uVar2 + 0x172);
        }
        if (bVar3 || uVar2 != 0) {
          return;
        }
      }
      msys::MDfxChr::playDfx(this,*(uint *)(param_1 + 0x44c64));
      *(undefined2 *)(*(int *)(param_1 + 0x21348) + 0xf2) = 0;
    }
  }
  return;
}


// FUNC 0x100039d8 FUN_100039d8 (AttackMiniGame)
//   size 0x134 | file AttackMiniGame+0x39d8 | callers(2) 0x1000149c 0x10002cec

void FUN_100039d8(int param_1)

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


// FUNC 0x10003b24 FUN_10003b24 (AttackMiniGame)
//   size 0x228 | file AttackMiniGame+0x3b24 | callers(4) 0x1000149c 0x10001cbc 0x100017e0 0x10004a28

void FUN_10003b24(int param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  wchar_t *pwVar3;
  int iVar4;
  int iVar5;
  uint in_fpscr;
  float fVar6;
  float fVar7;
  
  if (*(char *)(param_1 + 0x14e2e) == param_3) {
    if (param_3 == 0) {
      return;
    }
    if (*(short *)(param_1 + 0x14e2c) == *(short *)(param_2 + 0x12)) {
      return;
    }
  }
  else if (param_3 == 0) {
    *(undefined1 *)(param_1 + 0x141) = 0;
    *(undefined1 *)(param_1 + 0x371) = 0;
    *(undefined1 *)(param_1 + 0x5a1) = 0;
    uVar2 = ad::lyt::AnimTransform::GetFrameSize(*(AnimTransform **)(param_1 + 0x6c0));
    fVar6 = (float)VectorUnsignedToFloat(uVar2,(byte)(in_fpscr >> 0x16) & 3);
    ad::lyt::LytAnim::stopAndSetFrm((LytAnim *)(param_1 + 0x6ac),fVar6);
    goto LAB_10003d30;
  }
  iVar4 = 0;
  do {
    iVar5 = param_1 + iVar4 * 0x230;
    ad::lyt::LytNumReel3::setValueInstant
              ((LytNumReel3 *)(iVar5 + 0x150),(int)*(short *)(param_2 + iVar4 * 2));
    iVar4 = iVar4 + 1;
    *(undefined1 *)(iVar5 + 0x141) = 1;
  } while (iVar4 < 3);
  fVar6 = (float)VectorUnsignedToFloat((uint)*(byte *)(param_2 + 0x14),(byte)(in_fpscr >> 0x16) & 3)
  ;
  ad::lyt::LytAnim::stopAndSetFrm((LytAnim *)(param_1 + 0x6c8),fVar6);
  fVar6 = (float)VectorUnsignedToFloat((uint)*(byte *)(param_2 + 0x15),(byte)(in_fpscr >> 0x16) & 3)
  ;
  ad::lyt::LytAnim::stopAndSetFrm((LytAnim *)(param_1 + 0x690),fVar6);
  ad::lyt::LytAnim::stopAndSetFrm((LytAnim *)(param_1 + 0x6ac),0.0);
  puVar1 = (undefined4 *)ad::db::GetPcAttack(*(ushort *)(param_2 + 0x12));
  CellAnime::play((CellAnime *)(param_1 + 0x830),*(uchar *)(puVar1 + 2),0,1.0);
  iVar4 = ad::db::GetItemMsgAcs();
  uVar2 = LMS_GetTextIndexByLabel(iVar4 + 8,*puVar1);
  pwVar3 = (wchar_t *)LMS_GetText(iVar4 + 8,uVar2);
  fVar6 = (float)MessageSimple::getLineWidth
                           ((MessageSimple *)(param_1 + 0x76f0),pwVar3,(wchar_t **)0x0,(bool *)0x0,
                            (float *)0x0,(Font **)0x0);
  fVar6 = (23.0 - fVar6) * 0.5;
  msys::MMsg::playStr((MMsg *)(param_1 + 0x960),pwVar3,(InsParam *)0x0,false);
  msys::MMsg::playStr((MMsg *)(param_1 + 0x75a4),pwVar3,(InsParam *)0x0,false);
  MoveVBase::stop((MoveVBase *)(param_1 + 0x7670));
  *(float *)(param_1 + 0x768c) = fVar6;
  *(undefined4 *)(param_1 + 0x7690) = 0;
  *(undefined4 *)(param_1 + 0x7694) = 0;
  *(float *)(param_1 + 0x7674) = fVar6;
  *(undefined4 *)(param_1 + 0x7678) = *(undefined4 *)(param_1 + 0x7690);
  *(undefined4 *)(param_1 + 0x767c) = 0;
  fVar6 = *(float *)(param_1 + 0x7674) + -13.0;
  fVar7 = *(float *)(param_1 + 0x7678) + -1.0;
  MoveVBase::stop((MoveVBase *)(param_1 + 0x7b0));
  *(float *)(param_1 + 0x7cc) = fVar6;
  *(float *)(param_1 + 2000) = fVar7;
  *(undefined4 *)(param_1 + 0x7d4) = 0;
  *(float *)(param_1 + 0x7b4) = fVar6;
  *(float *)(param_1 + 0x7b8) = fVar7;
  *(undefined4 *)(param_1 + 0x7bc) = 0;
LAB_10003d30:
  *(undefined2 *)(param_1 + 0x14e2c) = *(undefined2 *)(param_2 + 0x12);
  *(char *)(param_1 + 0x14e2e) = (char)param_3;
  return;
}


// FUNC 0x10003d68 FUN_10003d68 (AttackMiniGame)
//   size 0x64 | file AttackMiniGame+0x3d68 | callers(12) 0x10003500 0x1000649c 0x1000149c 0x100030c0 0x100056e4 0x10005154 0x100017e0 0x10003408 ...

void FUN_10003d68(int param_1,int param_2)

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
  if ((param_2 == 0) || (*(char *)(param_1 + 0x28cd1) != '\0')) {
    msys::MListWndPBase::setEnableInput((MListWndPBase *)(param_1 + 0x28b90),SUB41(param_2,0));
    return;
  }
  return;
}


// FUNC 0x10003dd4 FUN_10003dd4 (AttackMiniGame)
//   size 0x9c | file AttackMiniGame+0x3dd4 | callers(6) 0x10003500 0x1000649c 0x100053bc 0x100017e0 0x1000436c 0x10004a28

MSndSe * FUN_10003dd4(undefined4 param_1,uint param_2,MChrBase *param_3,VEC2 *param_4,bool param_5)

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


// FUNC 0x10003e74 atk_mg::AttackMiniGame::vfunc_0x0 (AttackMiniGame)
//   size 0x150 | file AttackMiniGame+0x3e74 | callers(3) 0x1000148c 0x10007850 0x10007878 | datarefs 1

void atk_mg::AttackMiniGame::vfunc_0x0(undefined4 *param_1)

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
  __aeabi_vec_dtor(param_1 + 0x3a4f5,&LAB_100009b8,0x10,0xc);
  __aeabi_vec_dtor(param_1 + 0x3a49e,&LAB_10000850,0x1c,0xc);
  iVar3 = msys::MChrBase::vfunc_0x0(this);
  iVar3 = ad::fw::Resource::~Resource((Resource *)(iVar3 + -0x44));
  *(undefined4 *)(iVar3 + -0x24) = &AttackMiniGamePage::vtable;
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


// FUNC 0x10003fdc FUN_10003fdc (AttackMiniGame)
//   size 0x1c | file AttackMiniGame+0x3fdc | callers(2) 0x10001380 0x10006cb0

void FUN_10003fdc(uint *param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = param_2 & 0xff | (param_2 & 0xff) << 8;
  uVar1 = uVar1 | uVar1 << 0x10;
  *param_1 = uVar1;
  param_1[1] = uVar1;
  param_1[2] = uVar1;
  return;
}


// FUNC 0x10003ff8 FUN_10003ff8 (AttackMiniGame)
//   size 0xdc | file AttackMiniGame+0x3ff8 | callers(2) 0x10001380 0x10006cb0

void FUN_10003ff8(undefined4 *param_1)

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
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(puVar1 + 0xc,FUN_1000789c,0x2c,1);
  *(int *)(iVar2 + -8) = iVar2;
  *(undefined1 *)(iVar2 + -4) = 1;
  puVar1 = (undefined4 *)MoveVBase::MoveVBase((MoveVBase *)(iVar2 + 0x2c));
  *puVar1 = &vtable_for_5MoveVILj1EE;
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(puVar1 + 0xc,FUN_1000789c,0x2c,1);
  *(int *)(iVar2 + -8) = iVar2;
  *(undefined1 *)(iVar2 + -4) = 1;
  puVar1 = (undefined4 *)MoveVBase::MoveVBase((MoveVBase *)(iVar2 + 0x2c));
  *puVar1 = &vtable_for_5MoveVILj1EE;
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(puVar1 + 0xc,FUN_1000789c,0x2c,1);
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


// FUNC 0x100040e4 msys::MChrBase::vfunc_0x0 (AttackMiniGame)
//   size 0x14c | file AttackMiniGame+0x40e4 | callers(5) 0x10000b88 0x10003e74 0x10005898 0x100058cc 0x1000719c | datarefs 1

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


// FUNC 0x10004240 FUN_10004240 (AttackMiniGame)
//   size 0x98 | file AttackMiniGame+0x4240 | callers(5) 0x100009f4 0x10000a08 0x10000a1c 0x10000a30 0x10000a44

void FUN_10004240(undefined4 param_1,uint param_2)

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


// FUNC 0x100042dc FUN_100042dc (AttackMiniGame)
//   size 0x70 | file AttackMiniGame+0x42dc | callers(0) | datarefs 2

void FUN_100042dc(int param_1)

{
  short sVar1;
  MLyt *this;
  int iVar2;
  undefined4 uVar3;
  
  FUN_1000394c();
  this = (MLyt *)(param_1 + 0x12ed4);
  iVar2 = msys::MLyt::isEnableAnime(this);
  if (iVar2 == 0) {
    sVar1 = msys::MLyt::createAnimeAutoSlot(this,"LOOP","btn_NEXTpage",(char *)0x0);
    uVar3 = msys::MLyt::getAnim(this,sVar1);
    *(undefined4 *)(param_1 + 0x44c5c) = uVar3;
    FUN_10003d68(param_1,1);
    *(code **)(param_1 + 0x12a04) = FUN_1000436c;
    *(undefined4 *)(param_1 + 0x12a08) = 0;
  }
  return;
}


// FUNC 0x1000436c FUN_1000436c (AttackMiniGame)
//   size 0x108 | file AttackMiniGame+0x436c | callers(0) | datarefs 2

void FUN_1000436c(int param_1,uint *param_2,undefined4 param_3,undefined4 param_4)

{
  MLyt *this;
  
  if ((*param_2 & 0xc03) == 0) {
    FUN_1000394c(param_1,0xc03,param_3,param_4);
    return;
  }
  this = (MLyt *)(param_1 + 0x12ed4);
  msys::MLyt::playAnimeFromNo(this,3,0,(char *)0x0,(char *)0x0);
  msys::MLyt::playAnimeFromNo(this,6,0,(char *)0x0,(char *)0x0);
  FUN_10003dd4(param_1,0x110016,0,0,0);
  FUN_10003d68(param_1,0);
  if (*(short *)(*(int *)(param_1 + 0x1325c) + 0x10) == 1) {
    msys::MLyt::playAnimeFromNo(this,4,0,(char *)0x0,(char *)0x0);
    *(ushort *)(*(int *)(param_1 + 0x44c58) + 0x12) =
         *(ushort *)(*(int *)(param_1 + 0x44c58) + 0x12) & 0xfffd;
    msys::MDfxChr::term((MDfxChr *)(param_1 + 0x211f4));
    msys::MLyt::detachMChr(this,(MChrBase *)(param_1 + 0x211f4));
    *(undefined1 *)(*(int *)(*(int *)(param_1 + 0x44c60) + 0x154) + 0x170) = 1;
  }
  *(code **)(param_1 + 0x12a04) = FUN_10004484;
  *(undefined4 *)(param_1 + 0x12a08) = 0;
  return;
}


// FUNC 0x10004484 FUN_10004484 (AttackMiniGame)
//   size 0x58 | file AttackMiniGame+0x4484 | callers(0) | datarefs 2

void FUN_10004484(int param_1)

{
  int iVar1;
  
  iVar1 = msys::MLyt::isEnableAnime((MLyt *)(param_1 + 0x12ed4));
  if (iVar1 == 0) {
    ad::lyt::LytAnim::stop(*(LytAnim **)(param_1 + 0x44c5c));
    ad::lyt::LytAnim::term(*(LytAnim **)(param_1 + 0x44c5c),true);
    *(undefined4 *)(param_1 + 0x44c5c) = 0;
    *(undefined4 *)(param_1 + 0x12a04) = *(undefined4 *)(param_1 + 0x12a0c);
    *(undefined4 *)(param_1 + 0x12a08) = *(undefined4 *)(param_1 + 0x12a10);
  }
  return;
}


// FUNC 0x100044dc FUN_100044dc (AttackMiniGame)
//   size 0x5c | file AttackMiniGame+0x44dc | callers(0) | datarefs 1

void FUN_100044dc(int param_1)

{
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x12b2c),2,0,(char *)0x0,(char *)0x0);
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x12ed4),2,0,(char *)0x0,(char *)0x0);
  *(code **)(param_1 + 0x12a04) = FUN_100053bc;
  *(undefined4 *)(param_1 + 0x12a08) = 0;
  return;
}


// FUNC 0x1000453c FUN_1000453c (AttackMiniGame)
//   size 0x54 | file AttackMiniGame+0x453c | callers(0) | datarefs 2

void FUN_1000453c(int param_1)

{
  int iVar1;
  
  iVar1 = msys::MLyt::isEnableAnime((MLyt *)(param_1 + 0x12ed4));
  if (iVar1 == 0) {
    msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x12ed4),6,1,(char *)0x0,(char *)0x0);
    *(code **)(param_1 + 0x12a04) = FUN_10004594;
    *(undefined4 *)(param_1 + 0x12a08) = 0;
  }
  return;
}


// FUNC 0x10004594 FUN_10004594 (AttackMiniGame)
//   size 0x60 | file AttackMiniGame+0x4594 | callers(0) | datarefs 2

void FUN_10004594(int param_1)

{
  short sVar1;
  MLyt *this;
  int iVar2;
  undefined4 uVar3;
  
  this = (MLyt *)(param_1 + 0x12ed4);
  iVar2 = msys::MLyt::isEnableAnime(this);
  if (iVar2 == 0) {
    sVar1 = msys::MLyt::createAnimeAutoSlot(this,"LOOP","btn_NEXTpage",(char *)0x0);
    uVar3 = msys::MLyt::getAnim(this,sVar1);
    *(undefined4 *)(param_1 + 0x44c5c) = uVar3;
    *(code **)(param_1 + 0x12a04) = FUN_10004a28;
    *(undefined4 *)(param_1 + 0x12a08) = 0;
  }
  return;
}


// FUNC 0x10004614 FUN_10004614 (AttackMiniGame)
//   size 0x50 | file AttackMiniGame+0x4614 | callers(0) | datarefs 2

void FUN_10004614(int param_1)

{
  msys::MLyt::createAnimeAutoSlot((MLyt *)(param_1 + 0x12b2c),"4_to_5",(char *)0x0,(char *)0x0);
  msys::MLyt::createAnimeAutoSlot((MLyt *)(param_1 + 0x12ed4),"4_to_5",(char *)0x0,(char *)0x0);
  *(code **)(param_1 + 0x12a04) = FUN_100056e4;
  *(undefined4 *)(param_1 + 0x12a08) = 0;
  return;
}


// FUNC 0x100046d0 FUN_100046d0 (AttackMiniGame)
//   size 0x90 | file AttackMiniGame+0x46d0 | callers(0) | datarefs 5

void FUN_100046d0(int param_1)

{
  int iVar1;
  
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x12b2c),0,1,(char *)0x0,(char *)0x0);
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x12ed4),0,1,(char *)0x0,(char *)0x0);
  iVar1 = msys::MLyt::getPane((MLyt *)(param_1 + 0x12ed4),"PAGE_2",(char *)0x0,(char *)0x0);
  *(byte *)(iVar1 + 0x44) = *(byte *)(iVar1 + 0x44) & 0xfe | 1;
  *(undefined1 *)(param_1 + 0x28cd1) = 1;
  *(undefined4 *)(param_1 + 0x12a04) = 0x100050a8;
  *(undefined4 *)(param_1 + 0x12a08) = 0;
  return;
}


// FUNC 0x10004798 FUN_10004798 (AttackMiniGame)
//   size 0x74 | file AttackMiniGame+0x4798 | callers(0) | datarefs 1

void FUN_10004798(int param_1,uint *param_2)

{
  if ((*param_2 & 0x802) == 0) {
    if ((*param_2 & 0x401) != 0) {
      (**(code **)(**(int **)(param_1 + 0x132c0) + 0x10))();
      FUN_10003d68(param_1,0);
    }
  }
  else {
    (**(code **)(**(int **)(param_1 + 0x132c4) + 0x10))();
    FUN_10003d68(param_1,0);
  }
  FUN_10003648(param_1 + 0x1327c);
  return;
}


// FUNC 0x10004818 FUN_10004818 (AttackMiniGame)
//   size 0xc4 | file AttackMiniGame+0x4818 | callers(0) | datarefs 1

void FUN_10004818(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 local_20 [2];
  
  msys::MLyt::createAnimeAutoSlot((MLyt *)(param_1 + 0x12b2c),"5_to_3",(char *)0x0,(char *)0x0);
  msys::MLyt::createAnimeAutoSlot((MLyt *)(param_1 + 0x12ed4),"5_to_3",(char *)0x0,(char *)0x0);
  iVar1 = msys::MComSys::_sys;
  iVar2 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar2 = iVar1;
  }
  local_20[0] = 0xff000000;
  MoveC::moveFrm((MoveC *)(iVar2 + 0x4acd4),(Color8 *)local_20,16.0);
  MoveC::moveFrm((MoveC *)(iVar2 + 0x4ad14),(Color8 *)local_20,16.0);
  SndSys::stopAllBgm((SndSys *)&gSndSys,0x10);
  *(undefined1 **)(param_1 + 0x12a04) = &LAB_10005228;
  *(undefined4 *)(param_1 + 0x12a08) = 0;
  return;
}


// FUNC 0x10004954 FUN_10004954 (AttackMiniGame)
//   size 0x78 | file AttackMiniGame+0x4954 | callers(0) | datarefs 1

void FUN_10004954(int param_1)

{
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x12b2c),3,0,"EXP_PNL_U",(char *)0x0);
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x12b2c),1,1,(char *)0x0,(char *)0x0);
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x12ed4),1,1,(char *)0x0,(char *)0x0);
  *(code **)(param_1 + 0x12a04) = FUN_100057b0;
  *(undefined4 *)(param_1 + 0x12a08) = 0;
  return;
}


// FUNC 0x100049dc FUN_100049dc (AttackMiniGame)
//   size 0x34 | file AttackMiniGame+0x49dc | callers(0) | datarefs 4

void FUN_100049dc(int param_1)

{
  FUN_100038e0(param_1 + 0x21c58,"menu_save_err_03",0);
  *(undefined **)(param_1 + 0x12a04) = &DAT_10004814;
  *(undefined4 *)(param_1 + 0x12a08) = 0;
  return;
}


// FUNC 0x10004a28 FUN_10004a28 (AttackMiniGame)
//   size 0x5c8 | file AttackMiniGame+0x4a28 | callers(0) | datarefs 4

void FUN_10004a28(int param_1)

{
  char cVar1;
  short sVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  MDfxChr *this;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  short *psVar10;
  uint uVar11;
  undefined4 uVar12;
  short *psVar13;
  bool bVar14;
  short local_238 [64];
  short local_1b8 [64];
  undefined2 local_138;
  undefined2 local_b8;
  uint local_38;
  uint local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  iVar5 = *(int *)(param_1 + 0x44c6c);
  iVar8 = param_1 + 0x21c58;
  if (*(int *)(iVar5 + (uint)*(ushort *)(iVar5 + 0x7a) * 0xc + 4) == 0) {
    FUN_100038e0(iVar8,*(undefined4 *)(iVar5 + (uint)*(ushort *)(iVar5 + 0x7a) * 0xc),0);
    msys::MLyt::createAnimeAutoSlot
              ((MLyt *)(param_1 + 0x12b2c),"COMPLETE_IN",(char *)0x0,(char *)0x0);
    iVar8 = msys::MComSys::_sys;
    iVar5 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar5 = iVar8;
    }
    iVar6 = msys::MComSys::_sys;
    iVar8 = iVar5;
    if (iVar5 == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar8 = iVar6;
    }
    this = (MDfxChr *)(param_1 + 0x21078);
    msys::MDfxChr::init(this,*(MemAlcBase **)(*(int *)(param_1 + 4) + 0x18),
                        *(MDfxSys **)(iVar8 + 0xe64f0),(Scene *)(iVar5 + 0x4aaa0),0x400);
    msys::MDfxChr::playDfx(this,0x33);
    if ((((byte)nn::math::VEC3::Zero()::zero & 1) == 0) &&
       (iVar5 = __cxa_guard_acquire(&nn::math::VEC3::Zero()::zero), iVar5 != 0)) {
      nn::math::VEC3::Zero()::zero = 0;
      DAT_00434c4c = 0;
      DAT_00434c50 = 0;
      __cxa_guard_release(&nn::math::VEC3::Zero()::zero);
    }
    MoveVBase::stop((MoveVBase *)(param_1 + 0x21144));
    uVar4 = DAT_00434c50;
    uVar3 = DAT_00434c4c;
    uVar12 = nn::math::VEC3::Zero()::zero;
    *(undefined4 *)(param_1 + 0x21160) = nn::math::VEC3::Zero()::zero;
    *(undefined4 *)(param_1 + 0x21164) = uVar3;
    *(undefined4 *)(param_1 + 0x21168) = uVar4;
    *(undefined4 *)(param_1 + 0x21148) = uVar12;
    *(undefined4 *)(param_1 + 0x2114c) = uVar3;
    *(undefined4 *)(param_1 + 0x21150) = uVar4;
    msys::MLyt::attachMChr
              ((MLyt *)(param_1 + 0x12b2c),(MChrBase *)this,"INS_COMPLETE_EFFECT",(char *)0x0,
               (char *)0x0,(char *)0x0);
    iVar5 = msys::MLyt::getPane((MLyt *)(param_1 + 0x12ed4),"PAGE_2",(char *)0x0,(char *)0x0);
    *(byte *)(iVar5 + 0x44) = *(byte *)(iVar5 + 0x44) & 0xfe;
  }
  else {
    local_238[0] = 0;
    local_38 = 0;
    local_1b8[0] = 0;
    local_34 = 0;
    local_138 = 0;
    local_30 = 0;
    local_b8 = 0;
    local_2c = 0;
    iVar5 = *(int *)(param_1 + 0x44c6c);
    uVar9 = (uint)*(ushort *)(iVar5 + 0x7a);
    cVar1 = *(char *)(iVar5 + uVar9 * 0xc + 9);
    if (cVar1 == '\0') {
      psVar10 = *(short **)(iVar5 + uVar9 * 0xc);
      uVar9 = 0;
      do {
        sVar2 = psVar10[uVar9];
        if (sVar2 == 0) break;
        if (sVar2 == 0xe) {
          uVar9 = uVar9 + ((ushort)(psVar10 + uVar9)[3] >> 1) + 3;
        }
        uVar9 = uVar9 + 1;
      } while (uVar9 < 0x40);
      sVar2 = *psVar10;
      bVar14 = sVar2 == 0xe;
      if (bVar14) {
        sVar2 = psVar10[1];
      }
      if (bVar14 && sVar2 == 9) {
        uVar9 = uVar9 - 5;
        psVar10 = psVar10 + 5;
      }
      Mem::Copy(local_238,psVar10,uVar9 << 1);
      iVar5 = 10;
      uVar7 = 1;
      uVar12 = *(undefined4 *)
                (*(int *)(param_1 + 0x44c6c) +
                (uint)*(ushort *)(*(int *)(param_1 + 0x44c6c) + 0x7a) * 0xc + 4);
      local_38 = uVar9;
      do {
        iVar6 = __aeabi_uidivmod(uVar12,iVar5);
        if (iVar6 == 0) break;
        uVar7 = uVar7 + 1;
        iVar5 = iVar5 * 10;
      } while (uVar7 < 0x40);
      FUN_1000361c(local_1b8,0x40,0x3f,
                   &MessageSimple::InsParam::setNum(unsigned_char,int,bool)::string_literal,uVar12);
      if (uVar7 != 0) {
        uVar9 = uVar7 & 1;
        if (uVar9 != 0) {
          local_1b8[0] = local_1b8[0] + -0x120;
        }
        uVar11 = (uint)(uVar9 != 0);
        for (; uVar9 < uVar7; uVar9 = uVar9 + 2) {
          psVar13 = local_1b8 + uVar11;
          psVar10 = local_1b8 + uVar11 + 1;
          *psVar13 = *psVar13 + -0x120;
          uVar11 = uVar11 + 2;
          *psVar10 = *psVar10 + -0x120;
        }
      }
      local_34 = uVar7;
      FUN_100038e0(iVar8,"MES_MesDat_MiniGame_end_info10_add",local_238);
    }
    else if (cVar1 == '\x01') {
      psVar10 = *(short **)(iVar5 + uVar9 * 0xc);
      uVar9 = 0;
      do {
        sVar2 = psVar10[uVar9];
        if (sVar2 == 0) break;
        if (sVar2 == 0xe) {
          uVar9 = uVar9 + ((ushort)(psVar10 + uVar9)[3] >> 1) + 3;
        }
        uVar9 = uVar9 + 1;
      } while (uVar9 < 0x40);
      sVar2 = *psVar10;
      bVar14 = sVar2 == 0xe;
      if (bVar14) {
        sVar2 = psVar10[1];
      }
      if (bVar14 && sVar2 == 9) {
        uVar9 = uVar9 - 5;
        psVar10 = psVar10 + 5;
      }
      Mem::Copy(local_238,psVar10,uVar9 << 1);
      iVar5 = 10;
      uVar7 = 1;
      uVar12 = *(undefined4 *)
                (*(int *)(param_1 + 0x44c6c) +
                (uint)*(ushort *)(*(int *)(param_1 + 0x44c6c) + 0x7a) * 0xc + 4);
      local_38 = uVar9;
      do {
        iVar6 = __aeabi_uidivmod(uVar12,iVar5);
        if (iVar6 == 0) break;
        uVar7 = uVar7 + 1;
        iVar5 = iVar5 * 10;
      } while (uVar7 < 0x40);
      FUN_1000361c(local_1b8,0x40,0x3f,
                   &MessageSimple::InsParam::setNum(unsigned_char,int,bool)::string_literal,uVar12);
      if (uVar7 != 0) {
        uVar9 = uVar7 & 1;
        if (uVar9 != 0) {
          local_1b8[0] = local_1b8[0] + -0x120;
        }
        uVar11 = (uint)(uVar9 != 0);
        for (; uVar9 < uVar7; uVar9 = uVar9 + 2) {
          psVar10 = local_1b8 + uVar11;
          psVar13 = local_1b8 + uVar11 + 1;
          *psVar10 = *psVar10 + -0x120;
          uVar11 = uVar11 + 2;
          *psVar13 = *psVar13 + -0x120;
        }
      }
      local_34 = uVar7;
      FUN_100038e0(iVar8,"MES_MesDat_MiniGame_end_info10",local_238);
    }
    else if (cVar1 == '\x02') {
      uVar12 = *(undefined4 *)(iVar5 + uVar9 * 0xc + 4);
      iVar5 = 10;
      uVar9 = 1;
      do {
        iVar6 = __aeabi_uidivmod(uVar12,iVar5);
        if (iVar6 == 0) break;
        uVar9 = uVar9 + 1;
        iVar5 = iVar5 * 10;
      } while (uVar9 < 0x40);
      FUN_1000361c(local_238,0x40,0x3f,
                   &MessageSimple::InsParam::setNum(unsigned_char,int,bool)::string_literal,uVar12);
      if (uVar9 != 0) {
        uVar7 = uVar9 & 1;
        if (uVar7 != 0) {
          local_238[0] = local_238[0] + -0x120;
        }
        uVar11 = (uint)(uVar7 != 0);
        for (; uVar7 < uVar9; uVar7 = uVar7 + 2) {
          psVar10 = local_238 + uVar11;
          psVar13 = local_238 + uVar11 + 1;
          *psVar10 = *psVar10 + -0x120;
          uVar11 = uVar11 + 2;
          *psVar13 = *psVar13 + -0x120;
        }
      }
      local_38 = uVar9;
      FUN_100038e0(iVar8,*(undefined4 *)
                          (*(int *)(param_1 + 0x44c6c) +
                          (uint)*(ushort *)(*(int *)(param_1 + 0x44c6c) + 0x7a) * 0xc),local_238);
    }
    FUN_10003b24(param_1 + 0x2fe28,
                 *(int *)(param_1 + 0x44c68) +
                 *(char *)(*(int *)(param_1 + 0x44c6c) +
                          (uint)*(ushort *)(*(int *)(param_1 + 0x44c6c) + 0x7a) * 0xc + 8) * 0x18,1)
    ;
  }
  FUN_10003dd4(param_1,0x110025,0,0,0);
  *(short *)(*(int *)(param_1 + 0x44c6c) + 0x7a) =
       *(short *)(*(int *)(param_1 + 0x44c6c) + 0x7a) + 1;
  *(code **)(param_1 + 0x12a04) = FUN_10002a3c;
  *(undefined4 *)(param_1 + 0x12a08) = 0;
  return;
}


// FUNC 0x10005154 FUN_10005154 (AttackMiniGame)
//   size 0x10c | file AttackMiniGame+0x5154 | callers(0) | datarefs 2

/* WARNING: Removing unreachable block (ram,0x100051a4) */

void FUN_10005154(int param_1,undefined4 param_2)

{
  BootInfo *this;
  int iVar1;
  
  this = (BootInfo *)atk_mg::GetBootInfo();
  iVar1 = atk_mg::BootInfo::playBgm(this);
  if (iVar1 == 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x12a04) = 0x100050a8;
  *(undefined4 *)(param_1 + 0x12a08) = 0;
                    /* WARNING: Could not recover jumptable at 0x100051b4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(param_1 + 0x12a04))(param_1,param_2);
  return;
}


// FUNC 0x100051c0 FUN_100051c0 (AttackMiniGame)
//   size 0x60 | file AttackMiniGame+0x51c0 | callers(0) | datarefs 2

void FUN_100051c0(int param_1)

{
  ushort uVar1;
  int iVar2;
  BootInfo *this;
  int iVar3;
  
  iVar2 = msys::MListWndPBase::getCurNo((MListWndPBase *)(param_1 + 0x28b90));
  uVar1 = *(ushort *)(*(int *)(param_1 + 0x44c68) + iVar2 * 0x18 + 0x12);
  this = (BootInfo *)btl::GetBootInfo();
  btl::BootInfo::setModePcAtkMiniGame(this,uVar1);
  iVar2 = msys::MComSys::_sys;
  iVar3 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar3 = iVar2;
  }
  GameMain::Change(10,*(undefined4 *)(iVar3 + 4));
  return;
}


// FUNC 0x10005280 FUN_10005280 (AttackMiniGame)
//   size 0x90 | file AttackMiniGame+0x5280 | callers(0) | datarefs 1

void FUN_10005280(int param_1)

{
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x12b2c),1,0,(char *)0x0,(char *)0x0);
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x12ed4),1,0,(char *)0x0,(char *)0x0);
  msys::MLyt::setAnimeInfo((MLyt *)(param_1 + 0x12b2c),0,1);
  msys::MLyt::setAnimeInfo((MLyt *)(param_1 + 0x12ed4),0,1);
  *(undefined1 *)(param_1 + 0x28cd1) = 1;
  *(code **)(param_1 + 0x12a04) = FUN_100046d0;
  *(undefined4 *)(param_1 + 0x12a08) = 0;
  return;
}


// FUNC 0x10005318 FUN_10005318 (AttackMiniGame)
//   size 0x80 | file AttackMiniGame+0x5318 | callers(0) | datarefs 2

void FUN_10005318(int param_1)

{
  if (*(int *)(param_1 + 0x288a0) == 0) {
    if (*(int *)(param_1 + 0x28b8c) == 0) {
      FUN_100038e0(param_1 + 0x21c58,"menu_save_err_03",0);
      *(undefined **)(param_1 + 0x12a04) = &DAT_10004814;
      *(undefined4 *)(param_1 + 0x12a08) = 0;
      return;
    }
    FUN_100038e0(param_1 + 0x21c58,"menu_save_err_02",0);
    *(undefined2 *)(Backup::_fs + 0x24) = 0;
    Backup::format();
    *(code **)(param_1 + 0x12a04) = FUN_100016d4;
    *(undefined4 *)(param_1 + 0x12a08) = 0;
  }
  return;
}


// FUNC 0x100053bc FUN_100053bc (AttackMiniGame)
//   size 0x2e0 | file AttackMiniGame+0x53bc | callers(0) | datarefs 2

void FUN_100053bc(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  MLyt *this;
  int iVar6;
  MDfxChr *pMVar7;
  bool bVar8;
  
  this = (MLyt *)(param_1 + 0x12ed4);
  iVar6 = msys::MLyt::getAnime(this,2);
  bVar8 = iVar6 == 0;
  if (!bVar8) {
    bVar8 = *(float *)(iVar6 + 0xc) == 0.0;
  }
  if (!bVar8) {
    bVar8 = (*(byte *)(iVar6 + 0x12) & 1) == 0;
  }
  if (bVar8) {
    msys::MLyt::playAnimeFromNo(this,3,1,(char *)0x0,(char *)0x0);
    iVar6 = param_1 + 0x12000;
    bVar8 = *(code **)(param_1 + 0x12a0c) == FUN_10002b70;
    if (bVar8) {
      iVar6 = *(int *)(param_1 + 0x12a10);
    }
    if (bVar8 && iVar6 == 0) {
      iVar6 = btl::GetBootInfo();
      if (*(int *)(iVar6 + 0x124) != 0) {
        if (*(short *)(*(int *)(param_1 + 0x1325c) + 0x10) == 1) {
          iVar6 = msys::MLyt::getAnime(this,4);
          if (iVar6 != 0) {
            *(ushort *)(iVar6 + 0x12) = *(ushort *)(iVar6 + 0x12) & 0xfffd;
          }
          FUN_10003dd4(param_1,0x110024,0,0,0);
        }
        msys::MLyt::createAnimeAutoSlot(this,"BSCORE_IN",(char *)0x0,(char *)0x0);
        iVar1 = msys::MComSys::_sys;
        iVar6 = *(int *)(param_1 + 8);
        if (*(int *)(param_1 + 8) == 0) {
          *(int *)(param_1 + 8) = msys::MComSys::_sys;
          iVar6 = iVar1;
        }
        iVar2 = msys::MComSys::_sys;
        iVar1 = iVar6;
        if (iVar6 == 0) {
          *(int *)(param_1 + 8) = msys::MComSys::_sys;
          iVar1 = iVar2;
        }
        pMVar7 = (MDfxChr *)(param_1 + 0x20d80);
        msys::MDfxChr::init(pMVar7,*(MemAlcBase **)(*(int *)(param_1 + 4) + 0x18),
                            *(MDfxSys **)(iVar1 + 0xe64f0),(Scene *)(iVar6 + 0x4aaa0),0x400);
        msys::MDfxChr::playDfx(pMVar7,0x26);
        if ((((byte)nn::math::VEC3::Zero()::zero & 1) == 0) &&
           (iVar6 = __cxa_guard_acquire(&nn::math::VEC3::Zero()::zero), iVar6 != 0)) {
          nn::math::VEC3::Zero()::zero = 0;
          DAT_00434c4c = 0;
          DAT_00434c50 = 0;
          __cxa_guard_release(&nn::math::VEC3::Zero()::zero);
        }
        MoveVBase::stop((MoveVBase *)(param_1 + 0x20e4c));
        uVar5 = DAT_00434c50;
        uVar4 = DAT_00434c4c;
        uVar3 = nn::math::VEC3::Zero()::zero;
        *(undefined4 *)(param_1 + 0x20e68) = nn::math::VEC3::Zero()::zero;
        *(undefined4 *)(param_1 + 0x20e6c) = uVar4;
        *(undefined4 *)(param_1 + 0x20e70) = uVar5;
        *(undefined4 *)(param_1 + 0x20e50) = uVar3;
        *(undefined4 *)(param_1 + 0x20e54) = uVar4;
        *(undefined4 *)(param_1 + 0x20e58) = uVar5;
        msys::MLyt::attachMChr
                  ((MLyt *)(param_1 + 0x12b2c),(MChrBase *)pMVar7,"INS_BG_EFFECT",(char *)0x0,
                   (char *)0x0,(char *)0x0);
        iVar1 = msys::MComSys::_sys;
        iVar6 = *(int *)(param_1 + 8);
        if (*(int *)(param_1 + 8) == 0) {
          *(int *)(param_1 + 8) = msys::MComSys::_sys;
          iVar6 = iVar1;
        }
        iVar2 = msys::MComSys::_sys;
        iVar1 = iVar6;
        if (iVar6 == 0) {
          *(int *)(param_1 + 8) = msys::MComSys::_sys;
          iVar1 = iVar2;
        }
        pMVar7 = (MDfxChr *)(param_1 + 0x20efc);
        msys::MDfxChr::init(pMVar7,*(MemAlcBase **)(*(int *)(param_1 + 4) + 0x18),
                            *(MDfxSys **)(iVar1 + 0xe64f0),(Scene *)(iVar6 + 0x4aba4),0x401);
        msys::MDfxChr::playDfx(pMVar7,0x27);
        if ((((byte)nn::math::VEC3::Zero()::zero & 1) == 0) &&
           (iVar6 = __cxa_guard_acquire(&nn::math::VEC3::Zero()::zero), iVar6 != 0)) {
          nn::math::VEC3::Zero()::zero = 0;
          DAT_00434c4c = 0;
          DAT_00434c50 = 0;
          __cxa_guard_release(&nn::math::VEC3::Zero()::zero);
        }
        MoveVBase::stop((MoveVBase *)(param_1 + 0x20fc8));
        uVar5 = DAT_00434c50;
        uVar4 = DAT_00434c4c;
        uVar3 = nn::math::VEC3::Zero()::zero;
        *(undefined4 *)(param_1 + 0x20fe4) = nn::math::VEC3::Zero()::zero;
        *(undefined4 *)(param_1 + 0x20fe8) = uVar4;
        *(undefined4 *)(param_1 + 0x20fec) = uVar5;
        *(undefined4 *)(param_1 + 0x20fcc) = uVar3;
        *(undefined4 *)(param_1 + 0x20fd0) = uVar4;
        *(undefined4 *)(param_1 + 0x20fd4) = uVar5;
        msys::MLyt::attachMChr
                  (this,(MChrBase *)pMVar7,"INS_BG_EFFECT",(char *)0x0,(char *)0x0,(char *)0x0);
      }
      *(code **)(param_1 + 0x12a04) = FUN_10003178;
      *(undefined4 *)(param_1 + 0x12a08) = 0;
      return;
    }
    *(code **)(param_1 + 0x12a04) = FUN_10002b28;
    *(undefined4 *)(param_1 + 0x12a08) = 0;
  }
  return;
}


// FUNC 0x100056e4 FUN_100056e4 (AttackMiniGame)
//   size 0xc0 | file AttackMiniGame+0x56e4 | callers(0) | datarefs 2

void FUN_100056e4(int param_1)

{
  int iVar1;
  
  iVar1 = msys::MLyt::isEnableAnime((MLyt *)(param_1 + 0x12ed4));
  if (iVar1 == 0) {
    *(undefined1 *)(param_1 + 0x13294) = 0;
    *(undefined1 *)(param_1 + 0x13295) = 0xff;
    msys::MCursorBase::setVisible((MCursorBase *)(param_1 + 0x1327c),true);
    FUN_10003648((MCursorBase *)(param_1 + 0x1327c));
    iVar1 = msys::MLyt::getPane((MLyt *)(param_1 + 0x12ed4),"PAGE_2",(char *)0x0,(char *)0x0);
    *(byte *)(iVar1 + 0x44) = *(byte *)(iVar1 + 0x44) & 0xfe | 1;
    (**(code **)(**(int **)(param_1 + 0x132b8) + 0x28))(*(int **)(param_1 + 0x132b8),1);
    (**(code **)(**(int **)(param_1 + 0x132bc) + 0x28))(*(int **)(param_1 + 0x132bc),1);
    FUN_10003d68(param_1,1);
    *(code **)(param_1 + 0x12a04) = FUN_10003500;
    *(undefined4 *)(param_1 + 0x12a08) = 0;
  }
  return;
}


// FUNC 0x100057b0 FUN_100057b0 (AttackMiniGame)
//   size 0xe0 | file AttackMiniGame+0x57b0 | callers(0) | datarefs 2

void FUN_100057b0(int param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = msys::MLyt::isEnableAnime((MLyt *)(param_1 + 0x12ed4));
  if (iVar1 == 0) {
    *(undefined1 *)(param_1 + 0x13294) = 2;
    *(undefined1 *)(param_1 + 0x13295) = 0xff;
    msys::MCursorBase::setVisible((MCursorBase *)(param_1 + 0x1327c),true);
    FUN_10003648((MCursorBase *)(param_1 + 0x1327c));
    iVar1 = 0;
    do {
      piVar2 = *(int **)(param_1 + iVar1 * 4 + 0x132b8);
      (**(code **)(*piVar2 + 0x28))(piVar2,0);
      iVar1 = iVar1 + 1;
    } while (iVar1 < 4);
    (**(code **)(**(int **)(param_1 + 0x132c0) + 0x28))(*(int **)(param_1 + 0x132c0),1);
    (**(code **)(**(int **)(param_1 + 0x132c4) + 0x28))(*(int **)(param_1 + 0x132c4),1);
    *(undefined1 *)(param_1 + 0x28cd1) = 0;
    FUN_10003d68(param_1,1);
    *(code **)(param_1 + 0x12a04) = FUN_10004798;
    *(undefined4 *)(param_1 + 0x12a08) = 0;
    *(code **)(param_1 + 0x12a0c) = FUN_10005280;
    *(undefined4 *)(param_1 + 0x12a10) = 0;
  }
  return;
}


// FUNC 0x10005898 atk_mg::AttackMiniGamePage::Core::MsgWnd::vfunc_0x4 (AttackMiniGame)
//   size 0x30 | file AttackMiniGame+0x5898 | callers(0) | datarefs 1

void atk_mg::AttackMiniGamePage::Core::MsgWnd::vfunc_0x4(undefined4 *param_1)

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


// FUNC 0x100058cc atk_mg::AttackMiniGamePage::Core::MsgWnd::vfunc_0x0 (AttackMiniGame)
//   size 0x2c | file AttackMiniGame+0x58cc | callers(0) | datarefs 1

void atk_mg::AttackMiniGamePage::Core::MsgWnd::vfunc_0x0(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &msys::MMsgWnd::vtable;
  Message::term((Message *)(param_1 + 0x53));
  iVar1 = Message::~Message((Message *)(param_1 + 0x53));
  msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  return;
}


// FUNC 0x100058fc atk_mg::AttackMiniGamePage::Core::ListWnd::vfunc_0x10 (AttackMiniGame)
//   size 0x1c | file AttackMiniGame+0x58fc | callers(0) | datarefs 1

void atk_mg::AttackMiniGamePage::Core::ListWnd::vfunc_0x10(MListWndPBase *param_1)

{
  msys::MListWndPBase::applyAnime(param_1);
  ad::lyt::Layout::Animate((Layout *)(param_1 + 0x7060));
  return;
}


// FUNC 0x10005918 FUN_10005918 (AttackMiniGame)
//   size 0x4a8 | file AttackMiniGame+0x5918 | callers(1) 0x1000149c

void FUN_10005918(MListWndPBase *param_1,int param_2)

{
  short sVar1;
  int iVar2;
  Resource *this;
  undefined4 *puVar3;
  void *pvVar4;
  undefined4 uVar5;
  Layout *pLVar6;
  Layout *pLVar7;
  char *pcVar8;
  int iVar9;
  int iVar10;
  short *psVar11;
  MListWndPBase *pMVar12;
  uint in_fpscr;
  float fVar13;
  LytAnim local_210 [4];
  undefined4 local_20c;
  undefined4 uStack_208;
  undefined4 local_204;
  undefined2 local_200;
  undefined2 local_1fe;
  AnimTransform *local_1fc;
  undefined4 local_1f8;
  int local_1f0 [2];
  CellAnime *local_1e8;
  undefined4 local_1d0;
  undefined4 local_1c4;
  undefined4 local_1c0;
  undefined4 local_1b8;
  LytAnim *local_1a0;
  LytAnim *local_19c;
  LytAnim *local_198;
  LytAnim *local_194;
  LytAnim *local_190;
  undefined1 local_188;
  MListWndPBase *local_b4;
  byte local_b0;
  void *local_78;
  LytLocalize aLStack_70 [16];
  undefined4 local_60;
  int local_50;
  LytAnim *local_44;
  LytAnim *local_40;
  LytAnim *local_3c;
  LytAnim *local_34;
  LytAnim *local_30;
  
  iVar10 = msys::MComSys::_sys;
  iVar2 = *(int *)(param_2 + 8);
  if (*(int *)(param_2 + 8) == 0) {
    *(int *)(param_2 + 8) = msys::MComSys::_sys;
    iVar2 = iVar10;
  }
  pLVar6 = (Layout *)(param_1 + 0x7060);
  iVar10 = (int)*(char *)(param_2 + 0x44c70);
  ad::lyt::LytResourceMan::buildLayout
            ((LytResourceMan *)(param_2 + 0x12a30),pLVar6,"MINIGAME_L_LIST.bflyt",
             (ControlCreator *)0x0,(TextSearcher *)0x0);
  ad::lyt::LytLocalize::LytLocalize(aLStack_70);
  ad::lyt::LytLocalize::localize(aLStack_70,pLVar6);
  local_60 = 0;
  local_34 = (LytAnim *)(param_1 + 0x70d8);
  ad::lyt::LytAnim::init(local_34,pLVar6,"touch","");
  local_30 = (LytAnim *)(param_1 + 29000);
  ad::lyt::LytAnim::init(local_30,pLVar6,"ATTENTION","");
  ad::lyt::LytAnim::playAuto(local_30,1.0);
  pLVar7 = (Layout *)(param_1 + 0x709c);
  ad::lyt::LytResourceMan::buildLayout
            ((LytResourceMan *)(iVar2 + 2000),pLVar7,"NUM_G_s.bflyt",(ControlCreator *)0x0,
             (TextSearcher *)0x0);
  local_3c = (LytAnim *)(param_1 + 0x70f4);
  ad::lyt::LytAnim::init(local_3c,pLVar7,"num_set_U","");
  local_40 = (LytAnim *)(param_1 + 0x7110);
  ad::lyt::LytAnim::init(local_40,pLVar7,"col_s06","");
  local_44 = (LytAnim *)(param_1 + 0x712c);
  ad::lyt::LytAnim::init(local_44,pLVar7,"col_02","");
  this = (Resource *)(param_2 + 0x12ae8);
  local_78 = (void *)ad::fw::Resource::getCA_anm(this);
  puVar3 = (undefined4 *)ad::fw::Resource::getCA_tex(this);
  pvVar4 = (void *)ad::fw::Resource::getCA_canm(this);
  CellAnime::init((CellAnime *)(param_1 + 0x7164),local_78,(void *)*puVar3,pvVar4,'\0',0,1.0);
  param_1[0x7207] = (MListWndPBase)((byte)param_1[0x7207] | 3);
  param_1[0x71fc] = (MListWndPBase)0x0;
  param_1[0x71fd] = (MListWndPBase)0x0;
  ad::ui::UIListWindowPlusLyt::InitParam::InitParam((InitParam *)local_1f0);
  msys::SetMListWndInitParam(local_1f0,2);
  local_50 = iVar2 + 0x4af18;
  local_1f0[0] = iVar2 + 0x4af6c;
  local_1e8 = (CellAnime *)(param_1 + 0x7164);
  local_1b8 = (**(code **)(**(int **)(param_1 + 0x7070) + 0x2c))
                        (*(int **)(param_1 + 0x7070),"FRAME",1);
  if (iVar10 == 0) {
    pcVar8 = "list_cursor_Choleste";
  }
  else {
    pcVar8 = "list_cursor_Bli";
  }
  local_1c0 = (**(code **)(**(int **)(param_1 + 0x7070) + 0x2c))
                        (*(int **)(param_1 + 0x7070),pcVar8,1);
  local_1c4 = (**(code **)(**(int **)(param_1 + 0x7070) + 0x2c))
                        (*(int **)(param_1 + 0x7070),"list_scroll",1);
  local_190 = local_30;
  local_188 = 0;
  pMVar12 = param_1 + 0x6f80;
  local_194 = local_34;
  local_1d0 = *(undefined4 *)(param_1 + 0x70ac);
  local_1a0 = local_3c;
  local_19c = local_40;
  local_198 = local_44;
  if (iVar10 == 0) {
    local_b0 = 6;
  }
  else {
    local_b0 = 4;
  }
  local_210[0] = (LytAnim)0x0;
  local_20c = 0;
  uStack_208 = 0x3f800000;
  local_204 = 0;
  local_200 = 1;
  local_1fe = 0;
  local_1fc = (AnimTransform *)0x0;
  local_1f8 = 0;
  local_b4 = pMVar12;
  ad::lyt::LytAnim::init(local_210,pLVar6,"SET_LIST_COL","");
  fVar13 = (float)VectorUnsignedToFloat(iVar10,(byte)(in_fpscr >> 0x16) & 3);
  ad::lyt::LytAnim::stopAndSetFrm(local_210,fVar13);
  ad::lyt::LytAnim::term(local_210,true);
  ad::lyt::LytAnim::init(local_210,pLVar6,"ICON_offon","");
  ad::lyt::LytAnim::stopAndSetFrm(local_210,0.0);
  ad::lyt::LytAnim::term(local_210,true);
  ad::lyt::LytAnim::init(local_210,pLVar6,"SET_CURSOR_HIL","");
  uVar5 = ad::lyt::AnimTransform::GetFrameSize(local_1fc);
  fVar13 = (float)VectorUnsignedToFloat(uVar5,(byte)(in_fpscr >> 0x16) & 3);
  ad::lyt::LytAnim::stopAndSetFrm(local_210,fVar13);
  ad::lyt::LytAnim::term(local_210,true);
  local_204 = 0;
  if (iVar10 == 0) {
    iVar10 = 0;
  }
  else {
    iVar10 = 10;
  }
  if (local_b0 != 0) {
    pLVar7 = (Layout *)(param_2 + 0x44000);
    param_2 = iVar2 + 0xe9000;
  }
  iVar9 = 0;
  psVar11 = &DAT_003f9dc0 + iVar10;
  if (local_b0 != 0) {
    do {
      puVar3 = (undefined4 *)
               ad::db::GetPcAttack(*(ushort *)(*(int *)(pLVar7 + 0xc68) + iVar9 * 0x18 + 0x12));
      if ((*(uint *)(&DAT_003f97fc + (*(ushort *)((int)puVar3 + 0xe) >> 5 & 0x7fff87f) * 4) >>
           (*(ushort *)((int)puVar3 + 0xe) & 0x1f) & 1) == 0) {
        pMVar12[0xb] = (MListWndPBase)0xff;
        uVar5 = LMS_GetTextIndexByLabel(param_2 + 0x58,"MES_EMesColosseum_class_0");
        uVar5 = LMS_GetText(param_2 + 0x58,uVar5);
        *(undefined4 *)(pMVar12 + 0x10) = uVar5;
        *(undefined2 *)(pMVar12 + 4) = 0xffff;
      }
      else {
        pMVar12[0xb] = *(MListWndPBase *)(puVar3 + 2);
        iVar10 = ad::db::GetItemMsgAcs();
        uVar5 = LMS_GetTextIndexByLabel(iVar10 + 8,*puVar3);
        uVar5 = LMS_GetText(iVar10 + 8,uVar5);
        *(undefined4 *)(pMVar12 + 0x10) = uVar5;
        sVar1 = *psVar11;
        if (sVar1 < 0) {
          sVar1 = -1;
        }
        *(short *)(pMVar12 + 4) = sVar1;
      }
      *(int *)pMVar12 = iVar9;
      pMVar12[0xe] = (MListWndPBase)0x1;
      pMVar12[0xf] = (MListWndPBase)0x0;
      *(undefined4 *)(pMVar12 + 0x14) = 0;
      iVar9 = iVar9 + 1;
      psVar11 = psVar11 + 1;
      pMVar12 = pMVar12 + 0x1c;
    } while (iVar9 < (int)(uint)local_b0);
  }
  msys::MListWndPBase::init
            (param_1,(InitParam *)local_1f0,(LytDrawData *)(iVar2 + 0xd3000),
             (Prim *)(iVar2 + 0xd3100),(MessageDrawer *)(iVar2 + 0x1487c),
             (ApplyingSceneInfo *)(local_50 + 0x3c));
  *(undefined4 *)(param_1 + 0x13c) = 0x401;
  *(undefined4 *)(param_1 + 0x168) = 0x401;
  return;
}


// FUNC 0x10005ec4 atk_mg::AttackMiniGamePage::Core::ListWnd::vfunc_0x4 (AttackMiniGame)
//   size 0x60 | file AttackMiniGame+0x5ec4 | callers(0) | datarefs 1

void atk_mg::AttackMiniGamePage::Core::ListWnd::vfunc_0x4(undefined4 *param_1)

{
  int iVar1;
  void *pvVar2;
  
  *param_1 = &vtable;
  iVar1 = CellAnime::~CellAnime((CellAnime *)(param_1 + 0x1c59));
  *(undefined4 *)(iVar1 + -0x10) = 0;
  *(undefined4 *)(iVar1 + -0x2c) = 0;
  *(undefined4 *)(iVar1 + -0x48) = 0;
  *(undefined4 *)(iVar1 + -100) = 0;
  *(undefined4 *)(iVar1 + -0x80) = 0;
  iVar1 = ad::lyt::Layout::~Layout((Layout *)(iVar1 + -200));
  iVar1 = ad::lyt::Layout::~Layout((Layout *)(iVar1 + -0x3c));
  *(undefined ***)(iVar1 + -0x7060) = &vtable_for_N4msys9MListWndPILi8EEE;
  iVar1 = ad::ui::UIListWindowPlusLyt::~UIListWindowPlusLyt
                    ((UIListWindowPlusLyt *)(iVar1 + -0x6e64));
  pvVar2 = (void *)msys::MListWndPBase::~MListWndPBase((MListWndPBase *)(iVar1 + -0x1fc));
  operator_delete(pvVar2);
  return;
}


// FUNC 0x10005f30 atk_mg::AttackMiniGamePage::Core::ListWnd::vfunc_0x0 (AttackMiniGame)
//   size 0x5c | file AttackMiniGame+0x5f30 | callers(0) | datarefs 1

void atk_mg::AttackMiniGamePage::Core::ListWnd::vfunc_0x0(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &vtable;
  iVar1 = CellAnime::~CellAnime((CellAnime *)(param_1 + 0x1c59));
  *(undefined4 *)(iVar1 + -0x10) = 0;
  *(undefined4 *)(iVar1 + -0x2c) = 0;
  *(undefined4 *)(iVar1 + -0x48) = 0;
  *(undefined4 *)(iVar1 + -100) = 0;
  *(undefined4 *)(iVar1 + -0x80) = 0;
  iVar1 = ad::lyt::Layout::~Layout((Layout *)(iVar1 + -200));
  iVar1 = ad::lyt::Layout::~Layout((Layout *)(iVar1 + -0x3c));
  *(undefined ***)(iVar1 + -0x7060) = &vtable_for_N4msys9MListWndPILi8EEE;
  iVar1 = ad::ui::UIListWindowPlusLyt::~UIListWindowPlusLyt
                    ((UIListWindowPlusLyt *)(iVar1 + -0x6e64));
  msys::MListWndPBase::~MListWndPBase((MListWndPBase *)(iVar1 + -0x1fc));
  return;
}


// FUNC 0x10005f98 FUN_10005f98 (AttackMiniGame)
//   size 0x4a4 | file AttackMiniGame+0x5f98 | callers(2) 0x10001cbc 0x10001c08

undefined4 FUN_10005f98(int param_1)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  void *pvVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  char *pcVar10;
  uint uVar11;
  short *psVar12;
  int iVar13;
  uint local_30;
  
  if (*(char *)(param_1 + 0x44c70) == '\0') {
    uVar2 = 0x2d;
  }
  else {
    uVar2 = 0x3f;
  }
  if (((&DAT_003f9e00)[uVar2 >> 5] & 1 << (uVar2 & 0x1f)) == 0) {
    piVar3 = *(int **)(*(int *)(param_1 + 4) + 0x18);
    pvVar4 = (void *)(**(code **)(*piVar3 + 0xc))(piVar3,0x7c,0);
    *(void **)(param_1 + 0x44c6c) = pvVar4;
    Mem::Fill(pvVar4,0,0x7c);
    uVar2 = 0;
    if (*(char *)(param_1 + 0x44c70) == '\0') {
      iVar5 = 0;
      uVar11 = 0x10;
    }
    else {
      iVar5 = 10;
      uVar11 = 0x2e;
    }
    psVar12 = &DAT_003f9dc0 + iVar5;
    local_30 = 0;
    do {
      iVar13 = uVar2 * 0x18 + 0x12;
      iVar5 = ad::db::GetPcAttack(*(ushort *)(*(int *)(param_1 + 0x44c68) + iVar13));
      if (((*(uint *)(&DAT_003f97fc + (*(ushort *)(iVar5 + 0xe) >> 5 & 0x7fff87f) * 4) >>
            (*(ushort *)(iVar5 + 0xe) & 0x1f) & 1) != 0) &&
         (*(short *)(*(int *)(param_1 + 0x44c68) + uVar2 * 0x18) <= *psVar12)) {
        uVar8 = 1 << (uVar11 & 0x1f);
        if (((&DAT_003f9e00)[uVar11 >> 5] & uVar8) == 0) {
          (&DAT_003f9e00)[uVar11 >> 5] = (&DAT_003f9e00)[uVar11 >> 5] | uVar8;
          iVar5 = *(int *)(param_1 + 0x44c6c);
          iVar9 = (uint)*(ushort *)(iVar5 + 0x78) * 0xc + 4;
          *(int *)(iVar5 + iVar9) =
               *(int *)(iVar5 + iVar9) +
               (int)*(short *)(*(int *)(param_1 + 0x44c68) + uVar2 * 0x18 + 6);
          *(undefined1 *)
           (*(int *)(param_1 + 0x44c6c) +
           (uint)*(ushort *)(*(int *)(param_1 + 0x44c6c) + 0x78) * 0xc + 9) = 0;
        }
        if (*(short *)(*(int *)(param_1 + 0x44c68) + uVar2 * 0x18 + 2) <= *psVar12) {
          uVar8 = uVar11 + 1 >> 5;
          uVar1 = 1 << (uVar11 + 1 & 0x1f);
          if (((&DAT_003f9e00)[uVar8] & uVar1) == 0) {
            (&DAT_003f9e00)[uVar8] = (&DAT_003f9e00)[uVar8] | uVar1;
            iVar5 = *(int *)(param_1 + 0x44c6c);
            iVar9 = (uint)*(ushort *)(iVar5 + 0x78) * 0xc + 4;
            *(int *)(iVar5 + iVar9) =
                 *(int *)(iVar5 + iVar9) +
                 (int)*(short *)(*(int *)(param_1 + 0x44c68) + uVar2 * 0x18 + 8);
            *(undefined1 *)
             (*(int *)(param_1 + 0x44c6c) +
             (uint)*(ushort *)(*(int *)(param_1 + 0x44c6c) + 0x78) * 0xc + 9) = 1;
          }
          if (*(short *)(*(int *)(param_1 + 0x44c68) + uVar2 * 0x18 + 4) <= *psVar12) {
            uVar8 = uVar11 + 2 >> 5;
            uVar1 = 1 << (uVar11 + 2 & 0x1f);
            if (((&DAT_003f9e00)[uVar8] & uVar1) == 0) {
              (&DAT_003f9e00)[uVar8] = (&DAT_003f9e00)[uVar8] | uVar1;
              GameWork::addItem((GameWork *)&gGameWork,
                                *(undefined2 *)(*(int *)(param_1 + 0x44c68) + uVar2 * 0x18 + 0x10),1
                               );
              iVar5 = *(int *)(param_1 + 0x44c6c);
              iVar9 = (uint)*(ushort *)(iVar5 + 0x78) * 0xc + 4;
              *(int *)(iVar5 + iVar9) =
                   (int)*(short *)(*(int *)(param_1 + 0x44c68) + uVar2 * 0x18 + 10) +
                   *(int *)(iVar5 + iVar9);
              *(undefined4 *)
               (*(int *)(param_1 + 0x44c6c) +
               (uint)*(ushort *)(*(int *)(param_1 + 0x44c6c) + 0x78) * 0xc) =
                   *(undefined4 *)(*(int *)(param_1 + 0x44c68) + uVar2 * 0x18 + 0xc);
              *(undefined1 *)
               (*(int *)(param_1 + 0x44c6c) +
               (uint)*(ushort *)(*(int *)(param_1 + 0x44c6c) + 0x78) * 0xc + 9) = 2;
            }
            local_30 = local_30 + 1;
          }
        }
        iVar5 = *(int *)(*(int *)(param_1 + 0x44c6c) +
                        (uint)*(ushort *)(*(int *)(param_1 + 0x44c6c) + 0x78) * 0xc + 4);
        if (iVar5 != 0) {
          GameWork::addCoin((GameWork *)&gGameWork,iVar5);
          if (*(int *)(*(int *)(param_1 + 0x44c6c) +
                      (uint)*(ushort *)(*(int *)(param_1 + 0x44c6c) + 0x78) * 0xc) == 0) {
            iVar5 = ad::db::GetItemMsgAcs();
            puVar6 = (undefined4 *)
                     ad::db::GetPcAttack(*(ushort *)(*(int *)(param_1 + 0x44c68) + iVar13));
            uVar7 = LMS_GetTextIndexByLabel(iVar5 + 8,*puVar6);
            uVar7 = LMS_GetText(iVar5 + 8,uVar7);
            *(undefined4 *)
             (*(int *)(param_1 + 0x44c6c) +
             (uint)*(ushort *)(*(int *)(param_1 + 0x44c6c) + 0x78) * 0xc) = uVar7;
          }
          *(char *)(*(int *)(param_1 + 0x44c6c) +
                   (uint)*(ushort *)(*(int *)(param_1 + 0x44c6c) + 0x78) * 0xc + 8) = (char)uVar2;
          *(short *)(*(int *)(param_1 + 0x44c6c) + 0x78) =
               *(short *)(*(int *)(param_1 + 0x44c6c) + 0x78) + 1;
        }
      }
      uVar2 = uVar2 + 1;
      uVar11 = uVar11 + 3;
      if (*(char *)(param_1 + 0x44c70) == '\0') {
        uVar8 = 6;
      }
      else {
        uVar8 = 4;
      }
      psVar12 = psVar12 + 1;
    } while (uVar2 < uVar8);
    if (*(char *)(param_1 + 0x44c70) == '\0') {
      uVar2 = 6;
    }
    else {
      uVar2 = 4;
    }
    if (uVar2 <= local_30) {
      if (*(char *)(param_1 + 0x44c70) == '\0') {
        uVar2 = 0x2d;
      }
      else {
        uVar2 = 0x3f;
      }
      (&DAT_003f9e00)[uVar2 >> 5] = (&DAT_003f9e00)[uVar2 >> 5] | 1 << (uVar2 & 0x1f);
      GameWork::addItem((GameWork *)&gGameWork,
                        *(undefined2 *)(&DAT_10008000 + *(char *)(param_1 + 0x44c70) * 2),1);
      if (*(char *)(param_1 + 0x44c70) == '\0') {
        pcVar10 = "MES_MesDat_MiniGame_end_info4";
      }
      else {
        pcVar10 = "MES_MesDat_MiniGame_end_info20";
      }
      *(char **)(*(int *)(param_1 + 0x44c6c) +
                (uint)*(ushort *)(*(int *)(param_1 + 0x44c6c) + 0x78) * 0xc) = pcVar10;
      *(undefined1 *)
       (*(int *)(param_1 + 0x44c6c) +
       (uint)*(ushort *)(*(int *)(param_1 + 0x44c6c) + 0x78) * 0xc + 8) = 0xff;
      *(short *)(*(int *)(param_1 + 0x44c6c) + 0x78) =
           *(short *)(*(int *)(param_1 + 0x44c6c) + 0x78) + 1;
    }
    if (*(short *)((int)*(void **)(param_1 + 0x44c6c) + 0x78) != 0) {
      return 1;
    }
    Mem::Free(*(void **)(param_1 + 0x44c6c));
    *(undefined4 *)(param_1 + 0x44c6c) = 0;
  }
  return 0;
}


// FUNC 0x1000649c FUN_1000649c (AttackMiniGame)
//   size 0x13c | file AttackMiniGame+0x649c | callers(0)

void FUN_1000649c(int param_1,int param_2,int param_3)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = *(byte *)(param_2 + 0x48);
  uVar2 = (uint)bVar1;
  if (param_3 != 1) {
    if (param_3 != 4) {
      if (param_3 != 5) {
        return;
      }
      msys::MCursorBase::setVisible((MCursorBase *)(param_1 + 0x1327c),false);
      if (uVar2 == 0) {
        *(code **)(param_1 + 0x12a04) = FUN_100030c0;
        *(undefined4 *)(param_1 + 0x12a08) = 0;
        return;
      }
      if (uVar2 == 1) {
        *(code **)(param_1 + 0x12a04) = FUN_10004818;
        *(undefined4 *)(param_1 + 0x12a08) = 0;
        return;
      }
      if (uVar2 == 2) {
        *(code **)(param_1 + 0x12a04) = FUN_10003320;
        *(undefined4 *)(param_1 + 0x12a08) = 0;
        return;
      }
      if (uVar2 == 3) {
        *(undefined4 *)(param_1 + 0x12a04) = *(undefined4 *)(param_1 + 0x12a0c);
        *(undefined4 *)(param_1 + 0x12a08) = *(undefined4 *)(param_1 + 0x12a10);
        return;
      }
      return;
    }
    if (uVar2 == 0 || uVar2 == 3) {
      FUN_10003dd4(param_1,0x110017,0,0,0);
    }
    else {
      FUN_10003dd4(param_1,0x110016,0,0,0);
    }
    FUN_10003d68(param_1,0);
  }
  if ((uVar2 < 3) && ((int)*(char *)(param_1 + 0x13294) != uVar2)) {
    FUN_10003dd4(param_1,0x110015,0,0,0);
    *(byte *)(param_1 + 0x13294) = bVar1;
    return;
  }
  return;
}


// FUNC 0x100065ec FUN_100065ec (AttackMiniGame)
//   size 0x180 | file AttackMiniGame+0x65ec | callers(1) 0x1000149c

void FUN_100065ec(int param_1,char *param_2,undefined4 *param_3,int param_4,int param_5,
                 undefined4 param_6)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  uint in_fpscr;
  float fVar4;
  LytAnim aLStackY_c8 [128];
  
  uVar2 = (&DAT_1000820c)[param_5];
  *(uint *)(param_1 + 0x44c64) = uVar2;
  iVar3 = param_1 + param_4 * 0x17c;
  msys::MDfxChr::playDfx((MDfxChr *)(iVar3 + 0x21370),uVar2);
  *(undefined2 *)(*(int *)(iVar3 + 0x214c4) + 0xf2) = 0;
  *(undefined1 *)(*(int *)(iVar3 + 0x214c4) + 0x170) = 0;
  *(MDfxChr **)(param_1 + 0x44c60) = (MDfxChr *)(iVar3 + 0x21370);
  sVar1 = msys::MLyt::createAnimeAutoSlot
                    ((MLyt *)(param_1 + 0x12b2c),(char *)param_3[2],param_2,(char *)0x0);
  iVar3 = msys::MLyt::getAnim((MLyt *)(param_1 + 0x12b2c),sVar1);
  *(int *)(param_1 + 0x44c58) = iVar3;
  *(ushort *)(iVar3 + 0x12) = *(ushort *)(iVar3 + 0x12) | 2;
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x12ed4),4,1,(char *)0x0,(char *)0x0);
  iVar3 = msys::MLyt::getAnime((MLyt *)(param_1 + 0x12ed4),4);
  if (iVar3 != 0) {
    *(ushort *)(iVar3 + 0x12) = *(ushort *)(iVar3 + 0x12) | 2;
  }
  ad::lyt::LytAnim::init
            (aLStackY_c8 + 0x80,*(Layout **)(param_1 + 0x12c7c),(char *)*param_3,param_2);
  fVar4 = (float)VectorSignedToFloat(param_5,(byte)(in_fpscr >> 0x16) & 3);
  ad::lyt::LytAnim::stopAndSetFrm(aLStackY_c8 + 0x80,fVar4);
  ad::lyt::LytAnim::term(aLStackY_c8 + 0x80,true);
  ad::lyt::LytAnim::init(aLStackY_c8 + 0x80,*(Layout **)(param_1 + 0x13024),"SET_MEDAL","");
  fVar4 = (float)VectorSignedToFloat(param_6,(byte)(in_fpscr >> 0x16) & 3);
  ad::lyt::LytAnim::stopAndSetFrm(aLStackY_c8 + 0x80,fVar4);
  ad::lyt::LytAnim::term(aLStackY_c8 + 0x80,true);
  return;
}


// FUNC 0x10006788 FUN_10006788 (AttackMiniGame)
//   size 0x194 | file AttackMiniGame+0x6788 | callers(0) | datarefs 1

void FUN_10006788(int param_1)

{
  int iVar1;
  IAllocator *pIVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  FileContext *pFVar6;
  MemAlcBase *pMVar7;
  char acStackY_108 [128];
  uint *in_stack_ffffff78;
  TransMultiSymbol aTStack_64 [44];
  Resource *local_38;
  TaskBase *local_34;
  undefined4 local_30;
  
  iVar1 = ad::lyt::LytDrawSys::GetInst();
  uVar5 = *(undefined4 *)(*(int *)(param_1 + 4) + 0x18);
  pIVar2 = (IAllocator *)(iVar1 + 0x5f4);
  if (ad::lyt::Layout::s_pAllocator != pIVar2) {
    ad::lyt::Initialize(pIVar2,pIVar2);
  }
  *(undefined4 *)(iVar1 + 0x5f8) = uVar5;
  iVar1 = ad::lyt::LytDrawSys::GetInst();
  *(undefined4 *)(iVar1 + 0x5fc) = 0x10000;
  iVar3 = msys::MComSys::_sys;
  iVar1 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar1 = iVar3;
  }
  iVar3 = msys::MComSys::_sys;
  local_34 = *(TaskBase **)(iVar1 + 4);
  local_38 = (Resource *)(param_1 + 0x12ae8);
  if (iVar1 == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  else {
    iVar3 = *(int *)(param_1 + 8);
  }
  pFVar6 = *(FileContext **)(iVar3 + 0x278);
  pMVar7 = *(MemAlcBase **)(*(int *)(param_1 + 4) + 0x18);
  local_30 = *(undefined4 *)(pFVar6 + 0x24);
  ad::TransMultiSymbol::init(aTStack_64,"m_item_bra");
  BinGlu4Acs::getEntryAcs(acStackY_108 + 0x80);
  pcVar4 = (char *)((*in_stack_ffffff78 & 0x3fffffff) + *(int *)(pFVar6 + 0x24));
  ad::fw::TaskBase::readCA
            (local_34,local_38,pFVar6,"m_item_bra",pcVar4,pcVar4 + 4,pcVar4 + 8,pcVar4 + 0xc,pMVar7,
             0x7f,(VramAlcBase *)0x0,0,(ResCacheArg *)0x0);
  iVar3 = msys::MComSys::_sys;
  pMVar7 = *(MemAlcBase **)(*(int *)(param_1 + 4) + 0x18);
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
             (FileContext *)(*(int *)(iVar1 + 0x278) + 0xa8),"?MINIGAME",pMVar7,0x7f,
             (ResCacheArg *)0x0);
  *(undefined1 **)(param_1 + 0x129fc) = &LAB_10001bec;
  *(undefined4 *)(param_1 + 0x12a00) = 0;
  return;
}


// FUNC 0x10006944 FUN_10006944 (AttackMiniGame)
//   size 0x32c | file AttackMiniGame+0x6944 | callers(1) 0x1000149c

void FUN_10006944(int param_1,short *param_2,char *param_3,int param_4,uint param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  MDfxChr *this;
  int iVar4;
  undefined4 uVar5;
  short *psVar6;
  uint uVar7;
  int iVar8;
  undefined4 *puVar9;
  uint in_fpscr;
  float fVar10;
  LytAnim local_60 [4];
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined2 local_50;
  undefined2 local_4e;
  AnimTransform *local_4c;
  undefined4 local_48;
  int local_44;
  
  local_60[0] = (LytAnim)0x0;
  local_5c = 0;
  local_58 = 0x3f800000;
  local_54 = 0;
  local_50 = 1;
  local_4e = 0;
  local_4c = (AnimTransform *)0x0;
  local_48 = 0;
  psVar6 = *(short **)(param_1 + 0x44c68);
  uVar7 = 0;
  if (param_5 != 0) {
    do {
      iVar8 = msys::MComSys::_sys;
      iVar4 = *(int *)(param_1 + 8);
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar4 = iVar8;
      }
      iVar8 = msys::MComSys::_sys;
      iVar3 = iVar4;
      if (iVar4 == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar3 = iVar8;
      }
      iVar8 = param_1 + uVar7 * 0x17c;
      this = (MDfxChr *)(iVar8 + 0x21370);
      local_44 = iVar8;
      msys::MDfxChr::init(this,*(MemAlcBase **)(*(int *)(param_1 + 4) + 0x18),
                          *(MDfxSys **)(iVar3 + 0xe64f0),(Scene *)(iVar4 + 0x4aaa0),0x400);
      if ((((byte)nn::math::VEC3::Zero()::zero & 1) == 0) &&
         (iVar4 = __cxa_guard_acquire(&nn::math::VEC3::Zero()::zero), iVar4 != 0)) {
        nn::math::VEC3::Zero()::zero = 0;
        DAT_00434c4c = 0;
        DAT_00434c50 = 0;
        __cxa_guard_release(&nn::math::VEC3::Zero()::zero);
      }
      MoveVBase::stop((MoveVBase *)(iVar8 + 0x2143c));
      uVar2 = DAT_00434c50;
      uVar1 = DAT_00434c4c;
      uVar5 = nn::math::VEC3::Zero()::zero;
      *(undefined4 *)(iVar8 + 0x21458) = nn::math::VEC3::Zero()::zero;
      *(undefined4 *)(iVar8 + 0x2145c) = uVar1;
      *(undefined4 *)(iVar8 + 0x21460) = uVar2;
      *(undefined4 *)(iVar8 + 0x21440) = uVar5;
      *(undefined4 *)(iVar8 + 0x21444) = uVar1;
      *(undefined4 *)(iVar8 + 0x21448) = uVar2;
      puVar9 = (undefined4 *)(param_4 + uVar7 * 0x10);
      msys::MLyt::attachMChr
                ((MLyt *)(param_1 + 0x12b2c),(MChrBase *)this,(char *)puVar9[3],param_3,(char *)0x0,
                 (char *)0x0);
      ad::lyt::LytAnim::init(local_60,*(Layout **)(param_1 + 0x12c7c),(char *)puVar9[2],param_3);
      iVar8 = ad::db::GetPcAttack(psVar6[9]);
      if (((*(uint *)(&DAT_003f97fc + (*(ushort *)(iVar8 + 0xe) >> 5 & 0x7fff87f) * 4) >>
            (*(ushort *)(iVar8 + 0xe) & 0x1f) & 1) == 0) || (*param_2 < *psVar6)) {
        ad::lyt::LytAnim::stopAndSetFrm(local_60,0.0);
      }
      else {
        uVar5 = ad::lyt::AnimTransform::GetFrameSize(local_4c);
        fVar10 = (float)VectorUnsignedToFloat(uVar5,(byte)(in_fpscr >> 0x16) & 3);
        ad::lyt::LytAnim::stopAndSetFrm(local_60,fVar10);
        ad::lyt::LytAnim::term(local_60,true);
        ad::lyt::LytAnim::init(local_60,*(Layout **)(param_1 + 0x12c7c),(char *)*puVar9,param_3);
        if (*param_2 < psVar6[2]) {
          if (*param_2 < psVar6[1]) {
            iVar8 = 0;
          }
          else {
            iVar8 = 1;
          }
        }
        else {
          iVar8 = 2;
        }
        fVar10 = (float)VectorUnsignedToFloat(iVar8,(byte)(in_fpscr >> 0x16) & 3);
        ad::lyt::LytAnim::stopAndSetFrm(local_60,fVar10);
        msys::MDfxChr::playDfx(this,(&DAT_1000820c)[iVar8]);
        *(undefined2 *)(*(int *)(local_44 + 0x214c4) + 0xf2) = 0;
      }
      ad::lyt::LytAnim::term(local_60,true);
      ad::lyt::LytAnim::init(local_60,*(Layout **)(param_1 + 0x12c7c),(char *)puVar9[1],param_3);
      uVar5 = ad::lyt::AnimTransform::GetFrameSize(local_4c);
      fVar10 = (float)VectorUnsignedToFloat(uVar5,(byte)(in_fpscr >> 0x16) & 3);
      ad::lyt::LytAnim::stopAndSetFrm(local_60,fVar10);
      ad::lyt::LytAnim::term(local_60,true);
      uVar7 = uVar7 + 1;
      psVar6 = psVar6 + 0xc;
      param_2 = param_2 + 1;
    } while (uVar7 < param_5);
  }
  ad::lyt::LytAnim::init(local_60,*(Layout **)(param_1 + 0x12c7c),"SET_COMPLETE","");
  if (*(char *)(param_1 + 0x44c70) == '\0') {
    uVar7 = 0x2d;
  }
  else {
    uVar7 = 0x3f;
  }
  fVar10 = (float)VectorUnsignedToFloat
                            ((uint)(((&DAT_003f9e00)[uVar7 >> 5] & 1 << (uVar7 & 0x1f)) != 0),
                             (byte)(in_fpscr >> 0x16) & 3);
  ad::lyt::LytAnim::stopAndSetFrm(local_60,fVar10);
  ad::lyt::LytAnim::term(local_60,true);
  return;
}


// FUNC 0x10006cb0 FUN_10006cb0 (AttackMiniGame)
//   size 0x498 | file AttackMiniGame+0x6cb0 | callers(1) 0x100074e0

int FUN_10006cb0(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  bool bVar4;
  
  *param_1 = &atk_mg::AttackMiniGamePage::Core::vtable;
  param_1[1] = param_2;
  param_1[2] = 0;
  iVar1 = Backup::Backup((Backup *)(param_1 + 4));
  iVar1 = ad::ctrl::ButtonGroup::ButtonGroup((ButtonGroup *)(iVar1 + 0x12a04));
  *(undefined4 *)(iVar1 + 0x1c) = 0;
  iVar1 = ad::font::ResFont::ResFont((ResFont *)(iVar1 + 0x20));
  ad::lyt::LytResourceMan::init((LytResourceMan *)(iVar1 + -4));
  iVar1 = ad::fw::Resource::Resource((Resource *)(iVar1 + 0x70));
  iVar1 = ad::fw::Resource::Resource((Resource *)(iVar1 + 0x44));
  puVar2 = (undefined4 *)FUN_10003ff8(iVar1 + 0x44);
  *puVar2 = &msys::MLyt::vtable;
  *(undefined1 *)(puVar2 + 0x53) = 0xff;
  *(undefined2 *)((int)puVar2 + 0x14e) = 0;
  puVar2[0x54] = 0;
  iVar1 = __aeabi_vec_ctor_nocookie_nodtor(puVar2 + 0x55,FUN_100035e0,0x1c,0xc);
  iVar1 = __aeabi_vec_ctor_nocookie_nodtor(iVar1 + 0x15c,&LAB_10000988,0x10,0xc);
  *(undefined4 *)(iVar1 + 0xc0) = 0;
  *(undefined1 *)(iVar1 + 0xc4) = 1;
  *(undefined4 *)(iVar1 + 200) = 0;
  *(undefined4 *)(iVar1 + 0xcc) = 0;
  *(undefined1 *)(iVar1 + 0xd0) = 0;
  *(undefined4 *)(iVar1 + 0xd4) = 0;
  *(undefined4 *)(iVar1 + 0xd8) = 0;
  FUN_10003fdc(iVar1 + -0xc,0xffffffff);
  puVar2 = (undefined4 *)FUN_10003ff8(iVar1 + 0xf8);
  *puVar2 = &msys::MLyt::vtable;
  *(undefined1 *)(puVar2 + 0x53) = 0xff;
  *(undefined2 *)((int)puVar2 + 0x14e) = 0;
  puVar2[0x54] = 0;
  iVar1 = __aeabi_vec_ctor_nocookie_nodtor(puVar2 + 0x55,FUN_100035e0,0x1c,0xc);
  iVar1 = __aeabi_vec_ctor_nocookie_nodtor(iVar1 + 0x15c,&LAB_10000988,0x10,0xc);
  *(undefined4 *)(iVar1 + 0xc0) = 0;
  *(undefined1 *)(iVar1 + 0xc4) = 1;
  *(undefined4 *)(iVar1 + 200) = 0;
  *(undefined4 *)(iVar1 + 0xcc) = 0;
  *(undefined1 *)(iVar1 + 0xd0) = 0;
  *(undefined4 *)(iVar1 + 0xd4) = 0;
  *(undefined4 *)(iVar1 + 0xd8) = 0;
  FUN_10003fdc(iVar1 + -0xc,0xffffffff);
  puVar2 = (undefined4 *)msys::MCursorBase::MCursorBase((MCursorBase *)(iVar1 + 0xf8));
  *puVar2 = &vtable_for_N4msys7MCursorILj3EEE;
  puVar2[0xc] = 0;
  puVar2[0xd] = 0;
  puVar2[0xe] = 0;
  puVar2 = (undefined4 *)FUN_10003ff8(puVar2 + 0x13);
  *puVar2 = &msys::MMsg::vtable;
  iVar1 = MessageSimple::MessageSimple((MessageSimple *)(puVar2 + 0x53));
  *(undefined4 *)(iVar1 + 0x6ae0) = 0;
  *(undefined1 *)(iVar1 + 0x6ae4) = 0;
  *(undefined1 *)(iVar1 + 0x6ae5) = 0;
  *(undefined4 *)(iVar1 + 0x6ae8) = 0;
  *(undefined4 *)(iVar1 + 0x6aec) = 0;
  *(undefined4 *)(iVar1 + 0x6af4) = 0x400;
  puVar2 = (undefined4 *)FUN_10003ff8(iVar1 + 0x6af8);
  *puVar2 = &msys::MMsg::vtable;
  iVar1 = MessageSimple::MessageSimple((MessageSimple *)(puVar2 + 0x53));
  *(undefined4 *)(iVar1 + 0x6ae0) = 0;
  *(undefined1 *)(iVar1 + 0x6ae4) = 0;
  *(undefined1 *)(iVar1 + 0x6ae5) = 0;
  *(undefined4 *)(iVar1 + 0x6ae8) = 0;
  *(undefined4 *)(iVar1 + 0x6aec) = 0;
  *(undefined4 *)(iVar1 + 0x6af4) = 0x400;
  iVar1 = msys::MLytNum::MLytNum((MLytNum *)(iVar1 + 0x6af8));
  iVar1 = __aeabi_vec_ctor_nocookie_nodtor(iVar1 + 0x230,msys::MDfxChr::MDfxChr,0x17c,4);
  iVar1 = __aeabi_vec_ctor_nocookie_nodtor(iVar1 + 0x5f0,msys::MDfxChr::MDfxChr,0x17c,6);
  puVar2 = (undefined4 *)FUN_10003ff8(iVar1 + 0x8e8);
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
  *(undefined ***)(iVar1 + -0x14c) = &atk_mg::AttackMiniGamePage::Core::MsgWnd::vtable;
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
  puVar2[-0x7f] = &atk_mg::AttackMiniGamePage::Core::ListWnd::vtable;
  iVar1 = ad::lyt::Layout::Layout((Layout *)(puVar2 + 0x1b99));
  iVar1 = ad::lyt::Layout::Layout((Layout *)(iVar1 + 0x3c));
  iVar1 = FUN_100035e0(iVar1 + 0x3c);
  iVar1 = FUN_100035e0(iVar1 + 0x1c);
  iVar1 = FUN_100035e0(iVar1 + 0x1c);
  iVar1 = FUN_100035e0(iVar1 + 0x1c);
  iVar1 = FUN_100035e0(iVar1 + 0x1c);
  iVar1 = CellAnime::CellAnime((CellAnime *)(iVar1 + 0x1c));
  iVar1 = __aeabi_vec_ctor_nocookie_nodtor(iVar1 + 0x134,msys::MLytNum::MLytNum,0x230,3);
  iVar1 = FUN_100035e0(iVar1 + 0x690);
  iVar1 = FUN_100035e0(iVar1 + 0x1c);
  iVar1 = FUN_100035e0(iVar1 + 0x1c);
  puVar2 = (undefined4 *)FUN_10003ff8(iVar1 + 0x1c);
  *puVar2 = &msys::MCellAnime::vtable;
  iVar1 = CellAnime::CellAnime((CellAnime *)(puVar2 + 0x53));
  *(undefined1 *)(iVar1 + 300) = 0xff;
  *(undefined1 *)(iVar1 + 0x12d) = 0xff;
  *(undefined1 *)(iVar1 + 0x12e) = 0xff;
  *(undefined1 *)(iVar1 + 0x12f) = 0xff;
  puVar2 = (undefined4 *)FUN_10003ff8(iVar1 + 0x130);
  *puVar2 = &msys::MMsg::vtable;
  iVar1 = MessageSimple::MessageSimple((MessageSimple *)(puVar2 + 0x53));
  *(undefined4 *)(iVar1 + 0x6ae0) = 0;
  *(undefined1 *)(iVar1 + 0x6ae4) = 0;
  *(undefined1 *)(iVar1 + 0x6ae5) = 0;
  *(undefined4 *)(iVar1 + 0x6ae8) = 0;
  *(undefined4 *)(iVar1 + 0x6aec) = 0;
  *(undefined4 *)(iVar1 + 0x6af4) = 0x400;
  puVar2 = (undefined4 *)FUN_10003ff8(iVar1 + 0x6af8);
  *puVar2 = &msys::MMsg::vtable;
  iVar1 = MessageSimple::MessageSimple((MessageSimple *)(puVar2 + 0x53));
  *(undefined4 *)(iVar1 + 0x6ae0) = 0;
  *(undefined1 *)(iVar1 + 0x6ae4) = 0;
  *(undefined1 *)(iVar1 + 0x6ae5) = 0;
  *(undefined4 *)(iVar1 + 0x6ae8) = 0;
  *(undefined4 *)(iVar1 + 0x6aec) = 0;
  *(undefined4 *)(iVar1 + 0x6af4) = 0x400;
  puVar2 = (undefined4 *)FUN_10003ff8(iVar1 + 0x6af8);
  *puVar2 = &msys::MMsg::vtable;
  iVar3 = MessageSimple::MessageSimple((MessageSimple *)(puVar2 + 0x53));
  *(undefined4 *)(iVar3 + 0x6ae0) = 0;
  *(undefined1 *)(iVar3 + 0x6ae4) = 0;
  *(undefined1 *)(iVar3 + 0x6ae5) = 0;
  *(undefined4 *)(iVar3 + 0x6ae8) = 0;
  *(undefined4 *)(iVar3 + 0x6aec) = 0;
  *(undefined4 *)(iVar3 + 0x6af4) = 0x400;
  *(undefined4 *)(iVar3 + 0x6afc) = 0;
  *(undefined4 *)(iVar3 + 0x6b10) = 0;
  iVar1 = atk_mg::GetBootInfo();
  bVar4 = *(char *)(iVar1 + 0x10) != '\0';
  *(bool *)(iVar3 + 0x6b14) = bVar4;
  iVar1 = 0;
  if (bVar4) {
    iVar1 = 6;
  }
  *(undefined **)(iVar3 + 0x6b0c) = &UNK_10008218 + iVar1 * 0x18;
  *(code **)(iVar3 + -0x2b760) = FUN_10006788;
  *(undefined4 *)(iVar3 + -0x2b75c) = 0;
  return iVar3 + -0x3e15c;
}


// FUNC 0x1000718c atk_mg::AttackMiniGamePage::Core::vfunc_0x4 (AttackMiniGame)
//   size 0x10 | file AttackMiniGame+0x718c | callers(0) | datarefs 1

void atk_mg::AttackMiniGamePage::Core::vfunc_0x4(void)

{
  void *pvVar1;
  
  pvVar1 = (void *)vfunc_0x0();
  operator_delete(pvVar1);
  return;
}


// FUNC 0x1000719c atk_mg::AttackMiniGamePage::Core::vfunc_0x0 (AttackMiniGame)
//   size 0x2fc | file AttackMiniGame+0x719c | callers(1) 0x1000718c | datarefs 1

int atk_mg::AttackMiniGamePage::Core::vfunc_0x0(undefined4 *param_1)

{
  int iVar1;
  MLyt *pMVar2;
  
  *param_1 = &vtable;
  msys::MCursorBase::term((MCursorBase *)(param_1 + 0x4c9f));
  msys::MLyt::term((MLyt *)(param_1 + 0x4acb));
  msys::MLyt::term((MLyt *)(param_1 + 0x4bb5));
  ad::ctrl::ButtonGroup::FreeAll((ButtonGroup *)(param_1 + 0x4a85));
  ad::fw::Resource::term((Resource *)(param_1 + 0x4aa9));
  ad::lyt::LytResourceMan::term((LytResourceMan *)(param_1 + 0x4a8c));
  param_1[0xf804] = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar1 = MessageSimple::~MessageSimple((MessageSimple *)(param_1 + 0xf857));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  *(undefined ***)(iVar1 + -0x6c44) = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar1 = MessageSimple::~MessageSimple((MessageSimple *)(iVar1 + -0x6af8));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  *(undefined ***)(iVar1 + -0x6c44) = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar1 = MessageSimple::~MessageSimple((MessageSimple *)(iVar1 + -0x6af8));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  *(undefined ***)(iVar1 + -0x27c) = &msys::MCellAnime::vtable;
  iVar1 = CellAnime::~CellAnime((CellAnime *)(iVar1 + -0x130));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  *(undefined4 *)(iVar1 + -0x10) = 0;
  *(undefined4 *)(iVar1 + -0x2c) = 0;
  *(undefined4 *)(iVar1 + -0x48) = 0;
  __aeabi_vec_dtor(iVar1 + -0x6e4,msys::MLytNum::~MLytNum,0x230,3);
  *(undefined ***)(iVar1 + -0x797c) = &ListWnd::vtable;
  iVar1 = CellAnime::~CellAnime((CellAnime *)(iVar1 + -0x818));
  *(undefined4 *)(iVar1 + -0x10) = 0;
  *(undefined4 *)(iVar1 + -0x2c) = 0;
  *(undefined4 *)(iVar1 + -0x48) = 0;
  *(undefined4 *)(iVar1 + -100) = 0;
  *(undefined4 *)(iVar1 + -0x80) = 0;
  iVar1 = ad::lyt::Layout::~Layout((Layout *)(iVar1 + -200));
  iVar1 = ad::lyt::Layout::~Layout((Layout *)(iVar1 + -0x3c));
  *(undefined ***)(iVar1 + -0x7060) = &vtable_for_N4msys9MListWndPILi8EEE;
  iVar1 = ad::ui::UIListWindowPlusLyt::~UIListWindowPlusLyt
                    ((UIListWindowPlusLyt *)(iVar1 + -0x6e64));
  iVar1 = msys::MListWndPBase::~MListWndPBase((MListWndPBase *)(iVar1 + -0x1fc));
  *(undefined ***)(iVar1 + -0x6f38) = &msys::MMsgWnd::vtable;
  Message::term((Message *)(iVar1 + -0x6dec));
  iVar1 = Message::~Message((Message *)(iVar1 + -0x6dec));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  __aeabi_vec_dtor(iVar1 + -0x8e8,msys::MDfxChr::~MDfxChr,0x17c,6);
  __aeabi_vec_dtor(iVar1 + -0xed8,msys::MDfxChr::~MDfxChr,0x17c,4);
  iVar1 = msys::MLytNum::~MLytNum((MLytNum *)(iVar1 + -0x1108));
  *(undefined ***)(iVar1 + -0x6c44) = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar1 = MessageSimple::~MessageSimple((MessageSimple *)(iVar1 + -0x6af8));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  *(undefined ***)(iVar1 + -0x6c44) = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar1 = MessageSimple::~MessageSimple((MessageSimple *)(iVar1 + -0x6af8));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  iVar1 = msys::MCursorBase::~MCursorBase((MCursorBase *)(iVar1 + -0x4c));
  pMVar2 = (MLyt *)(iVar1 + -0x3a8);
  *(undefined ***)pMVar2 = &msys::MLyt::vtable;
  msys::MLyt::term(pMVar2);
  __aeabi_vec_dtor(iVar1 + -0xf8,&LAB_100009b8,0x10,0xc);
  __aeabi_vec_dtor(iVar1 + -0x254,&LAB_10000850,0x1c,0xc);
  iVar1 = msys::MChrBase::vfunc_0x0(pMVar2);
  pMVar2 = (MLyt *)(iVar1 + -0x3a8);
  *(undefined ***)pMVar2 = &msys::MLyt::vtable;
  msys::MLyt::term(pMVar2);
  __aeabi_vec_dtor(iVar1 + -0xf8,&LAB_100009b8,0x10,0xc);
  __aeabi_vec_dtor(iVar1 + -0x254,&LAB_10000850,0x1c,0xc);
  iVar1 = msys::MChrBase::vfunc_0x0(pMVar2);
  iVar1 = ad::fw::Resource::~Resource((Resource *)(iVar1 + -0x44));
  iVar1 = ad::fw::Resource::~Resource((Resource *)(iVar1 + -0x44));
  ad::lyt::LytResourceMan::term((LytResourceMan *)(iVar1 + -0x74));
  iVar1 = ad::font::ResFont::~ResFont((ResFont *)(iVar1 + -0x70));
  iVar1 = ad::ctrl::ButtonGroup::~ButtonGroup((ButtonGroup *)(iVar1 + -0x20));
  iVar1 = Backup::~Backup((Backup *)(iVar1 + -0x12a04));
  return iVar1 + -0x10;
}


// FUNC 0x100074c8 atk_mg::AttackMiniGamePage::vfunc_0x28 (AttackMiniGame)
//   size 0x14 | file AttackMiniGame+0x74c8 | callers(0) | datarefs 1

int atk_mg::AttackMiniGamePage::vfunc_0x28(int param_1,int param_2)

{
  return *(int *)(param_1 + 0x20) + param_2 * 4 + 0x129f8;
}


// FUNC 0x100074e0 atk_mg::AttackMiniGamePage::vfunc_0x8 (AttackMiniGame)
//   size 0x78 | file AttackMiniGame+0x74e0 | callers(0) | datarefs 1

void atk_mg::AttackMiniGamePage::vfunc_0x8(int *param_1)

{
  int iVar1;
  void *pvVar2;
  code *UNRECOVERED_JUMPTABLE;
  bool bVar3;
  
  if (param_1[8] == 0) {
    (**(code **)(*param_1 + 0x2c))(param_1);
    pvVar2 = operator_new(0x44c78,(MemAlcBase *)param_1[6],(char *)0x0,0);
    iVar1 = 0;
    if (pvVar2 != (void *)0x0) {
      iVar1 = FUN_10006cb0(pvVar2,param_1);
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
                    /* WARNING: Could not recover jumptable at 0x10007554. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// FUNC 0x1000755c atk_mg::AttackMiniGamePage::vfunc_0x14 (AttackMiniGame)
//   size 0xf8 | file AttackMiniGame+0x755c | callers(0) | datarefs 1

undefined4 atk_mg::AttackMiniGamePage::vfunc_0x14(int param_1,MInput *param_2)

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
  iVar4 = msys::MListWndPBase::isTpNeutral((MListWndPBase *)(piVar7 + 0xa2e4));
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


// FUNC 0x10007658 atk_mg::AttackMiniGamePage::vfunc_0xc (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x7658 | callers(0) | datarefs 1

void atk_mg::AttackMiniGamePage::vfunc_0xc(void)

{
  return;
}


// FUNC 0x1000765c atk_mg::AttackMiniGamePage::vfunc_0x24 (AttackMiniGame)
//   size 0x8 | file AttackMiniGame+0x765c | callers(0) | datarefs 1

undefined4 atk_mg::AttackMiniGamePage::vfunc_0x24(void)

{
  return 0;
}


// FUNC 0x10007664 atk_mg::AttackMiniGamePage::vfunc_0x4 (AttackMiniGame)
//   size 0xc4 | file AttackMiniGame+0x7664 | callers(0) | datarefs 1

void atk_mg::AttackMiniGamePage::vfunc_0x4(undefined4 *param_1)

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


// FUNC 0x10007730 atk_mg::AttackMiniGamePage::vfunc_0x0 (AttackMiniGame)
//   size 0xc0 | file AttackMiniGame+0x7730 | callers(0) | datarefs 1

undefined4 * atk_mg::AttackMiniGamePage::vfunc_0x0(undefined4 *param_1)

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


// FUNC 0x100077f8 atk_mg::AttackMiniGameTask::vfunc_0x10 (AttackMiniGame)
//   size 0x1c | file AttackMiniGame+0x77f8 | callers(0) | datarefs 1

void atk_mg::AttackMiniGameTask::vfunc_0x10(TaskMainBase *param_1)

{
  if (*(char *)(*(int *)(param_1 + 0x580) + 0xe9049) == '\0') {
    return;
  }
  GameMain::Back(param_1);
  return;
}


// FUNC 0x10007814 FUN_10007814 (AttackMiniGame)
//   size 0x38 | file AttackMiniGame+0x7814 | callers(1) 0x100007a8

int FUN_10007814(MTaskBase *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)msys::MTaskBase::MTaskBase(param_1);
  *puVar1 = &atk_mg::AttackMiniGameTask::vtable;
  iVar2 = FUN_10001380(puVar1 + 0x161);
  FUN_100011f4(iVar2,iVar2 + -0x584);
  *(int *)(iVar2 + -4) = iVar2;
  return iVar2 + -0x584;
}


// FUNC 0x10007850 atk_mg::AttackMiniGameTask::vfunc_0x8 (AttackMiniGame)
//   size 0x24 | file AttackMiniGame+0x7850 | callers(0) | datarefs 1

void atk_mg::AttackMiniGameTask::vfunc_0x8(undefined4 *param_1)

{
  int iVar1;
  void *pvVar2;
  
  *param_1 = &vtable;
  iVar1 = AttackMiniGame::vfunc_0x0(param_1 + 0x161);
  pvVar2 = (void *)ad::fw::TaskBase::~TaskBase((TaskBase *)(iVar1 + -0x584));
  operator_delete(pvVar2);
  return;
}


// FUNC 0x10007878 atk_mg::AttackMiniGameTask::vfunc_0x4 (AttackMiniGame)
//   size 0x20 | file AttackMiniGame+0x7878 | callers(0) | datarefs 1

void atk_mg::AttackMiniGameTask::vfunc_0x4(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &vtable;
  iVar1 = AttackMiniGame::vfunc_0x0(param_1 + 0x161);
  ad::fw::TaskBase::~TaskBase((TaskBase *)(iVar1 + -0x584));
  return;
}


// FUNC 0x1000789c FUN_1000789c (AttackMiniGame)
//   size 0x2c | file AttackMiniGame+0x789c | callers(0) | datarefs 3

undefined4 * FUN_1000789c(MoveWorkF *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)MoveWorkF::MoveWorkF(param_1);
  *puVar1 = &MoveWorkV::vtable;
  puVar1[8] = 0;
  puVar1[9] = 0;
  puVar1[10] = 0;
  return puVar1;
}


// FUNC 0x100078d0 MoveWorkV::vfunc_0x4 (AttackMiniGame)
//   size 0x10 | file AttackMiniGame+0x78d0 | callers(0) | datarefs 1

void MoveWorkV::vfunc_0x4(MoveWorkF *param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)MoveWorkF::~MoveWorkF(param_1);
  operator_delete(pvVar1);
  return;
}


// FUNC 0x100078e0 ->MoveWorkF::~MoveWorkF (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x78e0 | callers(0) | datarefs 6
// veneer/thunk -> 0x00340694 MoveWorkF::~MoveWorkF (static)

// FUNC 0x100078e4 nn::fs::FileInputStream::vfunc_0x20 (AttackMiniGame)
//   size 0x8 | file AttackMiniGame+0x78e4 | callers(0) | datarefs 1

void nn::fs::FileInputStream::vfunc_0x20(int param_1,longlong *param_2)

{
  detail::FileBase::TryGetSize((FileBase *)(param_1 + 4),param_2);
  return;
}


// FUNC 0x100078ec nn::fs::FileInputStream::vfunc_0x14 (AttackMiniGame)
//   size 0x8 | file AttackMiniGame+0x78ec | callers(0) | datarefs 1

undefined8 nn::fs::FileInputStream::vfunc_0x14(int param_1)

{
  return *(undefined8 *)(param_1 + 8);
}


// FUNC 0x100078f4 nn::fs::FileInputStream::vfunc_0x10 (AttackMiniGame)
//   size 0x14 | file AttackMiniGame+0x78f4 | callers(0) | datarefs 1

undefined4 nn::fs::FileInputStream::vfunc_0x10(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 0xc);
  *param_2 = *(undefined4 *)(param_1 + 8);
  param_2[1] = uVar1;
  return 0;
}


// FUNC 0x10007908 nn::fs::FileInputStream::vfunc_0x24 (AttackMiniGame)
//   size 0x2c | file AttackMiniGame+0x7908 | callers(0) | datarefs 1

longlong nn::fs::FileInputStream::vfunc_0x24(int param_1)

{
  int iVar1;
  longlong local_10;
  
  iVar1 = detail::FileBase::TryGetSize((FileBase *)(param_1 + 4),&local_10);
  if (iVar1 < 0) {
    err::CTR::ThrowFatalErrAll(iVar1,0x10007924);
  }
  return local_10;
}


// FUNC 0x10007934 FUN_10007934 (AttackMiniGame)
//   size 0x2c | file AttackMiniGame+0x7934 | callers(0) | datarefs 1

bool FUN_10007934(int *param_1,uint param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 8))();
  return (uVar1 & param_3) == param_2;
}


// FUNC 0x10007960 FUN_10007960 (AttackMiniGame)
//   size 0x8 | file AttackMiniGame+0x7960 | callers(0) | datarefs 1

undefined4 FUN_10007960(void)

{
  return 0;
}


// FUNC 0x10007968 FUN_10007968 (AttackMiniGame)
//   size 0x8 | file AttackMiniGame+0x7968 | callers(0) | datarefs 2

undefined4 FUN_10007968(void)

{
  return 2;
}


// FUNC 0x10007970 atk_mg::AttackMiniGamePage::Core::MsgWnd::vfunc_0x1c (AttackMiniGame)
//   size 0x8 | file AttackMiniGame+0x7970 | callers(0) | datarefs 1

undefined4 atk_mg::AttackMiniGamePage::Core::MsgWnd::vfunc_0x1c(void)

{
  return 7;
}


// FUNC 0x10007978 atk_mg::AttackMiniGamePage::Core::vfunc_0x8 (AttackMiniGame)
//   size 0x10 | file AttackMiniGame+0x7978 | callers(0) | datarefs 1

bool atk_mg::AttackMiniGamePage::Core::vfunc_0x8(undefined4 param_1,int param_2)

{
  return *(char *)(param_2 + 0x12) != '\0';
}


// FUNC 0x10007988 AttackMiniGame::nnroControlObject_ (AttackMiniGame)
//   size 0x74 | file AttackMiniGame+0x7988 | callers(0)

undefined4 AttackMiniGame::nnroControlObject_(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined *puVar2;
  
  switch(param_2) {
  case 0:
    uVar1 = 0;
    break;
  case 1:
    DAT_1000e68c = param_1;
    return 0;
  case 2:
    uVar1 = DAT_1000e68c;
    break;
  case 3:
    *param_1 = &DAT_10007b24;
    puVar2 = &DAT_10007b24;
    goto LAB_100079e8;
  case 4:
    *param_1 = &DAT_10008ffc;
    puVar2 = &DAT_10008ffc;
LAB_100079e8:
    param_1[1] = puVar2;
    return 0;
  default:
    return 0xd8e12c21;
  }
  *param_1 = uVar1;
  return 0;
}


// FUNC 0x10007a34 FUN_10007a34 (AttackMiniGame)
//   size 0xac | file AttackMiniGame+0x7a34 | callers(0) | datarefs 1

void FUN_10007a34(int param_1)

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


// FUNC 0x10007ae0 ->operator.delete (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x7ae0 | callers(0) | datarefs 1
// veneer/thunk -> 0x00286514 operator.delete (static)

// FUNC 0x10007ae4 FUN_10007ae4 (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x7ae4 | callers(0) | datarefs 1

void FUN_10007ae4(void)

{
  return;
}


// FUNC 0x10007ae8 FUN_10007ae8 (AttackMiniGame)
//   size 0x28 | file AttackMiniGame+0x7ae8 | callers(0) | datarefs 1

void FUN_10007ae8(float param_1,MCursorBase *param_2,MLyt *param_3)

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


// FUNC 0x10007b10 FUN_10007b10 (AttackMiniGame)
//   size 0x10 | file AttackMiniGame+0x7b10 | callers(0) | datarefs 1

void FUN_10007b10(MCursorBase *param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)msys::MCursorBase::~MCursorBase(param_1);
  operator_delete(pvVar1);
  return;
}


// FUNC 0x10007b20 ->msys::MCursorBase::~MCursorBase (AttackMiniGame)
//   size 0x4 | file AttackMiniGame+0x7b20 | callers(0) | datarefs 1
// veneer/thunk -> 0x00324600 msys::MCursorBase::~MCursorBase (static)

