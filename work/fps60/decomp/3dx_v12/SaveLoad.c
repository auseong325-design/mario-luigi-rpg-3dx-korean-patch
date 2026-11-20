// fps60 TG decompiled C: 3dx_v12.code.bin module SaveLoad part 1 (Ghidra 12.2, ARM:LE:32:v6:hardfp)
// Addresses: static = runtime address; CRO = fixed analysis base (crolink.py), NOT runtime.

// FUNC 0x16000180 FUN_16000180 (SaveLoad)
//   size 0x4 | file SaveLoad+0x180 | callers(0) | datarefs 1

void FUN_16000180(MsgDataAcsrBase *param_1)

{
  MsgDataAcsrBase::~MsgDataAcsrBase(param_1);
  return;
}


// FUNC 0x16000184 ->MsgDataAcsrBase::~MsgDataAcsrBase (SaveLoad)
//   size 0x4 | file SaveLoad+0x184 | callers(2) 0x16000464 0x16001648
// veneer/thunk -> 0x0026fdb4 MsgDataAcsrBase::~MsgDataAcsrBase (static)

// FUNC 0x1600018c ->operator.delete (SaveLoad)
//   size 0x4 | file SaveLoad+0x18c | callers(8) 0x160004c0 0x16000464 0x1600056c 0x1600068c 0x16000784 0x1600082c 0x16001638 0x16001ee8
// veneer/thunk -> 0x00286514 operator.delete (static)

// FUNC 0x16000194 ->nn::fs::detail::FileBase::TrySetPosition (SaveLoad)
//   size 0x4 | file SaveLoad+0x194 | callers(2) 0x160004c8 0x160004ec
// veneer/thunk -> 0x0027ec28 nn::fs::detail::FileBase::TrySetPosition (static)

// FUNC 0x1600019c ->nn::err::CTR::ThrowFatalErrAll (SaveLoad)
//   size 0x4 | file SaveLoad+0x19c | callers(5) 0x160004f4 0x16000918 0x160025a4 0x160004c8 0x16000520
// veneer/thunk -> 0x00286530 nn::err::CTR::ThrowFatalErrAll (static)

// FUNC 0x160001a4 ->nn::fs::detail::FileBase::TryRead (SaveLoad)
//   size 0x4 | file SaveLoad+0x1a4 | callers(3) 0x160004f4 0x16000918 0x1600054c
// veneer/thunk -> 0x00286488 nn::fs::detail::FileBase::TryRead (static)

// FUNC 0x160001ac ->nn::fs::detail::FileBase::TrySeek (SaveLoad)
//   size 0x4 | file SaveLoad+0x1ac | callers(2) 0x16000520 0x16000554
// veneer/thunk -> 0x002854d0 nn::fs::detail::FileBase::TrySeek (static)

// FUNC 0x160001b4 ->nndbgPanic (SaveLoad)
//   size 0x4 | file SaveLoad+0x1b4 | callers(3) 0x1600056c 0x160005ac 0x16000918
// veneer/thunk -> 0x0028642c nndbgPanic (static)

// FUNC 0x160001bc ->nn::fs::CTR::MPCore::detail::UserFileSystem::CloseFile (SaveLoad)
//   size 0x4 | file SaveLoad+0x1bc | callers(3) 0x1600056c 0x160005ac 0x16000918
// veneer/thunk -> 0x00286410 nn::fs::CTR::MPCore::detail::UserFileSystem::CloseFile (static)

// FUNC 0x160001c4 ->msys::MRenderQueueBase::enqueueMsg (SaveLoad)
//   size 0x4 | file SaveLoad+0x1c4 | callers(1) 0x16000654
// veneer/thunk -> 0x00328df0 msys::MRenderQueueBase::enqueueMsg (static)

// FUNC 0x160001cc ->msys::MMsg::applyAnime (SaveLoad)
//   size 0x4 | file SaveLoad+0x1cc | callers(1) 0x1600069c
// veneer/thunk -> 0x0032cbb8 msys::MMsg::applyAnime (static)

// FUNC 0x160001d4 ->msys::MMsg::playStr (SaveLoad)
//   size 0x4 | file SaveLoad+0x1d4 | callers(2) 0x160006f8 0x16001ddc
// veneer/thunk -> 0x0032ce0c msys::MMsg::playStr (static)

// FUNC 0x160001dc ->__cxa_guard_acquire (SaveLoad)
//   size 0x4 | file SaveLoad+0x1dc | callers(3) 0x160006f8 0x16001040 0x16001ddc
// veneer/thunk -> 0x00288110 __cxa_guard_acquire (static)

// FUNC 0x160001e4 ->__cxa_guard_release (SaveLoad)
//   size 0x4 | file SaveLoad+0x1e4 | callers(3) 0x160006f8 0x16001040 0x16001ddc
// veneer/thunk -> 0x001018a8 __cxa_guard_release (static)

// FUNC 0x160001ec ->__aeabi_vec_dtor (SaveLoad)
//   size 0x4 | file SaveLoad+0x1ec | callers(6) 0x160012e8 0x16000784 0x160007c0 0x16001648 0x16001ee8 0x16001f58
// veneer/thunk -> 0x00288230 __aeabi_vec_dtor (static)

// FUNC 0x160001f4 ->MoveVBase::~MoveVBase (SaveLoad)
//   size 0x4 | file SaveLoad+0x1f4 | callers(3) 0x160012e8 0x16000784 0x160007c0
// veneer/thunk -> 0x002535e8 MoveVBase::~MoveVBase (static)

// FUNC 0x160001fc ->MoveWorkF::MoveWorkF (SaveLoad)
//   size 0x4 | file SaveLoad+0x1fc | callers(1) 0x160007f8
// veneer/thunk -> 0x00278cc0 MoveWorkF::MoveWorkF (static)

// FUNC 0x16000204 ->MoveWorkF::~MoveWorkF (SaveLoad)
//   size 0x4 | file SaveLoad+0x204 | callers(2) 0x1600082c 0x1600083c
// veneer/thunk -> 0x00340694 MoveWorkF::~MoveWorkF (static)

// FUNC 0x1600020c ->Backup::format (SaveLoad)
//   size 0x4 | file SaveLoad+0x20c | callers(1) 0x16000840
// veneer/thunk -> 0x00339d34 Backup::format (static)

// FUNC 0x16000214 ->msys::MCamera::getProjMtx (SaveLoad)
//   size 0x4 | file SaveLoad+0x214 | callers(2) 0x160008d4 0x16000860
// veneer/thunk -> 0x00206718 msys::MCamera::getProjMtx (static)

// FUNC 0x1600021c ->msys::MCamera::getViewMtx (SaveLoad)
//   size 0x4 | file SaveLoad+0x21c | callers(1) 0x16000860
// veneer/thunk -> 0x002068e4 msys::MCamera::getViewMtx (static)

// FUNC 0x16000224 ->ad::fw::TaskBase::setULcdCameraInfoBase (SaveLoad)
//   size 0x4 | file SaveLoad+0x224 | callers(1) 0x16000860
// veneer/thunk -> 0x0010b438 ad::fw::TaskBase::setULcdCameraInfoBase (static)

// FUNC 0x1600022c ->Grp::SetupProjLcdOrtho (SaveLoad)
//   size 0x4 | file SaveLoad+0x22c | callers(1) 0x16000860
// veneer/thunk -> 0x00284fc0 Grp::SetupProjLcdOrtho (static)

// FUNC 0x16000234 ->msys::MComSys::funcCalcMainNomal (SaveLoad)
//   size 0x4 | file SaveLoad+0x234 | callers(1) 0x16000860
// veneer/thunk -> 0x0032f13c msys::MComSys::funcCalcMainNomal (static)

// FUNC 0x1600023c ->msys::MComSys::funcDrawLower (SaveLoad)
//   size 0x4 | file SaveLoad+0x23c | callers(1) 0x160008d4
// veneer/thunk -> 0x0032e2b8 msys::MComSys::funcDrawLower (static)

// FUNC 0x16000244 ->msys::MComSys::funcDrawUpper (SaveLoad)
//   size 0x4 | file SaveLoad+0x244 | callers(1) 0x16000914
// veneer/thunk -> 0x0032e760 msys::MComSys::funcDrawUpper (static)

// FUNC 0x1600024c ->ad::lyt::LytDrawSys::GetInst (SaveLoad)
//   size 0x4 | file SaveLoad+0x24c | callers(1) 0x16000918
// veneer/thunk -> 0x00287f58 ad::lyt::LytDrawSys::GetInst (static)

// FUNC 0x16000254 ->ad::lyt::Initialize (SaveLoad)
//   size 0x4 | file SaveLoad+0x254 | callers(1) 0x16000918
// veneer/thunk -> 0x002855e0 ad::lyt::Initialize (static)

// FUNC 0x1600025c ->ad::TransMultiSymbol::init (SaveLoad)
//   size 0x4 | file SaveLoad+0x25c | callers(1) 0x16000918
// veneer/thunk -> 0x0026d7f8 ad::TransMultiSymbol::init (static)

// FUNC 0x16000264 ->BinGlu4Acs::getEntryAcs (SaveLoad)
//   size 0x4 | file SaveLoad+0x264 | callers(1) 0x16000918
// veneer/thunk -> 0x00285268 BinGlu4Acs::getEntryAcs (static)

// FUNC 0x1600026c ->ad::fw::TaskBase::readCA (SaveLoad)
//   size 0x4 | file SaveLoad+0x26c | callers(1) 0x16000918
// veneer/thunk -> 0x0026daf8 ad::fw::TaskBase::readCA (static)

// FUNC 0x16000274 ->msys::MComSys::readLytNum (SaveLoad)
//   size 0x4 | file SaveLoad+0x274 | callers(1) 0x16000918
// veneer/thunk -> 0x0032db14 msys::MComSys::readLytNum (static)

// FUNC 0x1600027c ->ad::fw::TaskBase::readLyt (SaveLoad)
//   size 0x4 | file SaveLoad+0x27c | callers(1) 0x16000918
// veneer/thunk -> 0x00249e48 ad::fw::TaskBase::readLyt (static)

// FUNC 0x16000284 ->operator.new[] (SaveLoad)
//   size 0x4 | file SaveLoad+0x284 | callers(1) 0x16000918
// veneer/thunk -> 0x00283558 operator.new[] (static)

// FUNC 0x1600028c ->MessageSys::GetPath (SaveLoad)
//   size 0x4 | file SaveLoad+0x28c | callers(1) 0x16000918
// veneer/thunk -> 0x00132a2c MessageSys::GetPath (static)

// FUNC 0x16000294 ->nn::fs::CTR::MPCore::detail::UserFileSystem::TryOpenFile (SaveLoad)
//   size 0x4 | file SaveLoad+0x294 | callers(1) 0x16000918
// veneer/thunk -> 0x0028598c nn::fs::CTR::MPCore::detail::UserFileSystem::TryOpenFile (static)

// FUNC 0x1600029c ->nn::fs::detail::FileBase::TryGetSize (SaveLoad)
//   size 0x4 | file SaveLoad+0x29c | callers(3) 0x16000918 0x160025a4 0x16002580
// veneer/thunk -> 0x00286568 nn::fs::detail::FileBase::TryGetSize (static)

// FUNC 0x160002a4 ->MsgDataAcsrBase::init (SaveLoad)
//   size 0x4 | file SaveLoad+0x2a4 | callers(1) 0x16000918
// veneer/thunk -> 0x00285b88 MsgDataAcsrBase::init (static)

// FUNC 0x160002ac ->operator.delete[] (SaveLoad)
//   size 0x4 | file SaveLoad+0x2ac | callers(1) 0x16000918
// veneer/thunk -> 0x0028829c operator.delete[] (static)

// FUNC 0x160002b4 ->ad::lyt::LytResourceMan::init (SaveLoad)
//   size 0x4 | file SaveLoad+0x2b4 | callers(1) 0x16000c58
// veneer/thunk -> 0x00250d1c ad::lyt::LytResourceMan::init (static)

// FUNC 0x160002bc ->ad::fw::Resource::getFileData (SaveLoad)
//   size 0x4 | file SaveLoad+0x2bc | callers(1) 0x16000c58
// veneer/thunk -> 0x00251d10 ad::fw::Resource::getFileData (static)

// FUNC 0x160002c4 ->ad::lyt::LytResourceMan::registerArc (SaveLoad)
//   size 0x4 | file SaveLoad+0x2c4 | callers(1) 0x16000c58
// veneer/thunk -> 0x0015c910 ad::lyt::LytResourceMan::registerArc (static)

// FUNC 0x160002cc ->msys::MLyt::init (SaveLoad)
//   size 0x4 | file SaveLoad+0x2cc | callers(1) 0x16000c58
// veneer/thunk -> 0x0032c3a0 msys::MLyt::init (static)

// FUNC 0x160002d4 ->msys::MLyt::createLyt (SaveLoad)
//   size 0x4 | file SaveLoad+0x2d4 | callers(1) 0x16000c58
// veneer/thunk -> 0x0032c78c msys::MLyt::createLyt (static)

// FUNC 0x160002dc ->MoveVBase::stop (SaveLoad)
//   size 0x4 | file SaveLoad+0x2dc | callers(6) 0x16000c58 0x16001040 0x16001b9c 0x16001cbc 0x16001fc4 0x160023dc
// veneer/thunk -> 0x00259dd8 MoveVBase::stop (static)

// FUNC 0x160002e4 ->msys::MDfxChr::init (SaveLoad)
//   size 0x4 | file SaveLoad+0x2e4 | callers(1) 0x16000c58
// veneer/thunk -> 0x003309c0 msys::MDfxChr::init (static)

// FUNC 0x160002ec ->msys::MDfxChr::playDfx (SaveLoad)
//   size 0x4 | file SaveLoad+0x2ec | callers(1) 0x16000c58
// veneer/thunk -> 0x00330d64 msys::MDfxChr::playDfx (static)

// FUNC 0x160002f4 ->msys::MLyt::attachMChr (SaveLoad)
//   size 0x4 | file SaveLoad+0x2f4 | callers(4) 0x16000c58 0x1600187c 0x16001fc4 0x160023dc
// veneer/thunk -> 0x00207468 msys::MLyt::attachMChr (static)

// FUNC 0x160002fc ->Backup::isBusyWriting (SaveLoad)
//   size 0x4 | file SaveLoad+0x2fc | callers(1) 0x16000fc4
// veneer/thunk -> 0x00339558 Backup::isBusyWriting (static)

// FUNC 0x16000304 ->Backup::term (SaveLoad)
//   size 0x4 | file SaveLoad+0x304 | callers(1) 0x16000fc4
// veneer/thunk -> 0x00339c84 Backup::term (static)

// FUNC 0x1600030c ->Backup::mount (SaveLoad)
//   size 0x4 | file SaveLoad+0x30c | callers(1) 0x16000ff4
// veneer/thunk -> 0x00339d0c Backup::mount (static)

// FUNC 0x16000314 ->Backup::writeInitData (SaveLoad)
//   size 0x4 | file SaveLoad+0x314 | callers(1) 0x16000ff4
// veneer/thunk -> 0x0028464c Backup::writeInitData (static)

// FUNC 0x1600031c ->CtrFS::unmountSaveData (SaveLoad)
//   size 0x4 | file SaveLoad+0x31c | callers(1) 0x16000ff4
// veneer/thunk -> 0x00207f3c CtrFS::unmountSaveData (static)

// FUNC 0x16000324 ->MoveC::moveFrm (SaveLoad)
//   size 0x4 | file SaveLoad+0x324 | callers(1) 0x16001444
// veneer/thunk -> 0x0026bc74 MoveC::moveFrm (static)

// FUNC 0x1600032c ->msys::MComSys::MComSys (SaveLoad)
//   size 0x4 | file SaveLoad+0x32c | callers(1) 0x1600150c
// veneer/thunk -> 0x0032f7a4 msys::MComSys::MComSys (static)

// FUNC 0x16000334 ->Backup::Backup (SaveLoad)
//   size 0x4 | file SaveLoad+0x334 | callers(1) 0x1600150c
// veneer/thunk -> 0x00110c64 Backup::Backup (static)

// FUNC 0x1600033c ->MsgDataAcsrBase::MsgDataAcsrBase (SaveLoad)
//   size 0x4 | file SaveLoad+0x33c | callers(1) 0x1600150c
// veneer/thunk -> 0x0024b3b8 MsgDataAcsrBase::MsgDataAcsrBase (static)

// FUNC 0x16000344 ->ad::fw::Resource::Resource (SaveLoad)
//   size 0x4 | file SaveLoad+0x344 | callers(1) 0x1600150c
// veneer/thunk -> 0x00250588 ad::fw::Resource::Resource (static)

// FUNC 0x1600034c ->__aeabi_vec_ctor_nocookie_nodtor (SaveLoad)
//   size 0x4 | file SaveLoad+0x34c | callers(2) 0x1600150c 0x1600118c
// veneer/thunk -> 0x0028771c __aeabi_vec_ctor_nocookie_nodtor (static)

// FUNC 0x16000354 ->msys::MDfxChr::MDfxChr (SaveLoad)
//   size 0x4 | file SaveLoad+0x354 | callers(1) 0x1600150c
// veneer/thunk -> 0x0033137c msys::MDfxChr::MDfxChr (static)

// FUNC 0x1600035c ->FrameBuf::setClearColor (SaveLoad)
//   size 0x4 | file SaveLoad+0x35c | callers(1) 0x1600150c
// veneer/thunk -> 0x0024c8d4 FrameBuf::setClearColor (static)

// FUNC 0x16000364 ->MoveVBase::MoveVBase (SaveLoad)
//   size 0x4 | file SaveLoad+0x364 | callers(1) 0x1600118c
// veneer/thunk -> 0x00259740 MoveVBase::MoveVBase (static)

// FUNC 0x1600036c ->ad::fw::TaskBase::term (SaveLoad)
//   size 0x4 | file SaveLoad+0x36c | callers(1) 0x16001648
// veneer/thunk -> 0x0024a358 ad::fw::TaskBase::term (static)

// FUNC 0x16000374 ->msys::MLyt::term (SaveLoad)
//   size 0x4 | file SaveLoad+0x374 | callers(1) 0x16001648
// veneer/thunk -> 0x0032c3c8 msys::MLyt::term (static)

// FUNC 0x1600037c ->ad::fw::Resource::term (SaveLoad)
//   size 0x4 | file SaveLoad+0x37c | callers(1) 0x16001648
// veneer/thunk -> 0x00233340 ad::fw::Resource::term (static)

// FUNC 0x16000384 ->msys::MDfxChr::~MDfxChr (SaveLoad)
//   size 0x4 | file SaveLoad+0x384 | callers(1) 0x16001648
// veneer/thunk -> 0x003313cc msys::MDfxChr::~MDfxChr (static)

// FUNC 0x1600038c ->ad::fw::Resource::~Resource (SaveLoad)
//   size 0x4 | file SaveLoad+0x38c | callers(1) 0x16001648
// veneer/thunk -> 0x0024a104 ad::fw::Resource::~Resource (static)

// FUNC 0x16000394 ->Backup::~Backup (SaveLoad)
//   size 0x4 | file SaveLoad+0x394 | callers(1) 0x16001648
// veneer/thunk -> 0x00339f34 Backup::~Backup (static)

// FUNC 0x1600039c ->msys::MComSys::~MComSys (SaveLoad)
//   size 0x4 | file SaveLoad+0x39c | callers(1) 0x16001648
// veneer/thunk -> 0x003300e8 msys::MComSys::~MComSys (static)

// FUNC 0x160003a4 ->ad::lyt::LytNumReel3::InitParam::InitParam (SaveLoad)
//   size 0x4 | file SaveLoad+0x3a4 | callers(3) 0x1600187c 0x16001fc4 0x160023dc
// veneer/thunk -> 0x00256194 ad::lyt::LytNumReel3::InitParam::InitParam (static)

// FUNC 0x160003ac ->msys::MLytNumRes::set (SaveLoad)
//   size 0x4 | file SaveLoad+0x3ac | callers(3) 0x1600187c 0x16001fc4 0x160023dc
// veneer/thunk -> 0x00207594 msys::MLytNumRes::set (static)

// FUNC 0x160003b4 ->msys::MLytNum::init (SaveLoad)
//   size 0x4 | file SaveLoad+0x3b4 | callers(3) 0x1600187c 0x16001fc4 0x160023dc
// veneer/thunk -> 0x003316b8 msys::MLytNum::init (static)

// FUNC 0x160003bc ->ad::lyt::LytNumReel3::setValueInstant (SaveLoad)
//   size 0x4 | file SaveLoad+0x3bc | callers(2) 0x16001948 0x1600220c
// veneer/thunk -> 0x0020785c ad::lyt::LytNumReel3::setValueInstant (static)

// FUNC 0x160003c4 ->Message::init (SaveLoad)
//   size 0x4 | file SaveLoad+0x3c4 | callers(1) 0x16001a40
// veneer/thunk -> 0x0033dc2c Message::init (static)

// FUNC 0x160003cc ->Message::setMsgDat (SaveLoad)
//   size 0x4 | file SaveLoad+0x3cc | callers(1) 0x16001a40
// veneer/thunk -> 0x0033ddc8 Message::setMsgDat (static)

// FUNC 0x160003d4 ->Message::play (SaveLoad)
//   size 0x4 | file SaveLoad+0x3d4 | callers(1) 0x16001b9c
// veneer/thunk -> 0x00259970 Message::play (static)

// FUNC 0x160003dc ->ad::lyt::LytAnim::stopAndSetFrm (SaveLoad)
//   size 0x4 | file SaveLoad+0x3dc | callers(5) 0x16001c04 0x16001cbc 0x16001fc4 0x1600220c 0x160023dc
// veneer/thunk -> 0x0026fe44 ad::lyt::LytAnim::stopAndSetFrm (static)

// FUNC 0x160003e4 ->MessageSimple::init (SaveLoad)
//   size 0x4 | file SaveLoad+0x3e4 | callers(1) 0x16001cbc
// veneer/thunk -> 0x002736b4 MessageSimple::init (static)

// FUNC 0x160003ec ->ad::lyt::Layout::FindPartsPaneByName (SaveLoad)
//   size 0x4 | file SaveLoad+0x3ec | callers(1) 0x16001cbc
// veneer/thunk -> 0x00264d90 ad::lyt::Layout::FindPartsPaneByName (static)

// FUNC 0x160003f4 ->ad::lyt::LytAnim::init (SaveLoad)
//   size 0x4 | file SaveLoad+0x3f4 | callers(4) 0x16001cbc 0x16001fc4 0x1600220c 0x160023dc
// veneer/thunk -> 0x00264f04 ad::lyt::LytAnim::init (static)

// FUNC 0x160003fc ->ad::lyt::LytAnim::term (SaveLoad)
//   size 0x4 | file SaveLoad+0x3fc | callers(4) 0x16001cbc 0x16001fc4 0x1600220c 0x160023dc
// veneer/thunk -> 0x00264e90 ad::lyt::LytAnim::term (static)

// FUNC 0x16000404 ->LMS_GetTextIndexByLabel (SaveLoad)
//   size 0x4 | file SaveLoad+0x404 | callers(1) 0x16001ddc
// veneer/thunk -> 0x0027616c LMS_GetTextIndexByLabel (static)

// FUNC 0x1600040c ->LMS_GetText (SaveLoad)
//   size 0x4 | file SaveLoad+0x40c | callers(1) 0x16001ddc
// veneer/thunk -> 0x0027660c LMS_GetText (static)

// FUNC 0x16000414 ->Frm::play (SaveLoad)
//   size 0x4 | file SaveLoad+0x414 | callers(1) 0x16001ddc
// veneer/thunk -> 0x0027a324 Frm::play (static)

// FUNC 0x1600041c ->MessageSimple::term (SaveLoad)
//   size 0x4 | file SaveLoad+0x41c | callers(2) 0x16001ee8 0x16001f58
// veneer/thunk -> 0x00137090 MessageSimple::term (static)

// FUNC 0x16000424 ->MessageSimple::~MessageSimple (SaveLoad)
//   size 0x4 | file SaveLoad+0x424 | callers(2) 0x16001ee8 0x16001f58
// veneer/thunk -> 0x00256578 MessageSimple::~MessageSimple (static)

// FUNC 0x1600042c ->msys::MLyt::getParts (SaveLoad)
//   size 0x4 | file SaveLoad+0x42c | callers(2) 0x16001fc4 0x160023dc
// veneer/thunk -> 0x002073ec msys::MLyt::getParts (static)

// FUNC 0x16000434 ->msys::MCellAnime::init (SaveLoad)
//   size 0x4 | file SaveLoad+0x434 | callers(2) 0x16001fc4 0x160023dc
// veneer/thunk -> 0x002079d8 msys::MCellAnime::init (static)

// FUNC 0x1600043c ->CellAnime::play (SaveLoad)
//   size 0x4 | file SaveLoad+0x43c | callers(2) 0x16001fc4 0x160023dc
// veneer/thunk -> 0x0027bee0 CellAnime::play (static)

// FUNC 0x16000444 ->DataPcEquipFxParam::DataPcEquipFxParam (SaveLoad)
//   size 0x4 | file SaveLoad+0x444 | callers(1) 0x1600220c
// veneer/thunk -> 0x0027cb24 DataPcEquipFxParam::DataPcEquipFxParam (static)

// FUNC 0x1600044c ->DataPc::DataPc (SaveLoad)
//   size 0x4 | file SaveLoad+0x44c | callers(1) 0x1600220c
// veneer/thunk -> 0x0027ca84 DataPc::DataPc (static)

// FUNC 0x16000454 ->DataPc::getLv (SaveLoad)
//   size 0x4 | file SaveLoad+0x454 | callers(1) 0x1600220c
// veneer/thunk -> 0x00362bec DataPc::getLv (static)

// FUNC 0x1600045c ->DataPc::getRank (SaveLoad)
//   size 0x4 | file SaveLoad+0x45c | callers(1) 0x1600220c
// veneer/thunk -> 0x00362c00 DataPc::getRank (static)

// FUNC 0x16000464 FUN_16000464 (SaveLoad)
//   size 0x10 | file SaveLoad+0x464 | callers(0) | datarefs 1

void FUN_16000464(MsgDataAcsrBase *param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)MsgDataAcsrBase::~MsgDataAcsrBase(param_1);
  operator_delete(pvVar1);
  return;
}


// FUNC 0x160004c0 ->operator.delete (SaveLoad)
//   size 0x4 | file SaveLoad+0x4c0 | callers(0) | datarefs 1
// veneer/thunk -> 0x00286514 operator.delete (static)

// FUNC 0x160004c4 nn::fs::IInputStream::vfunc_0x0 (SaveLoad)
//   size 0x4 | file SaveLoad+0x4c4 | callers(0) | datarefs 1

void nn::fs::IInputStream::vfunc_0x0(void)

{
  return;
}


// FUNC 0x160004c8 nn::fs::FileInputStream::vfunc_0x1c (SaveLoad)
//   size 0x24 | file SaveLoad+0x4c8 | callers(0) | datarefs 1

void nn::fs::FileInputStream::vfunc_0x1c(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = detail::FileBase::TrySetPosition(CONCAT44(param_2,param_1 + 4));
  if (iVar1 < 0) {
    err::CTR::ThrowFatalErrAll(iVar1,0x160004dc);
    return;
  }
  return;
}


// FUNC 0x160004ec nn::fs::FileInputStream::vfunc_0x18 (SaveLoad)
//   size 0x8 | file SaveLoad+0x4ec | callers(0) | datarefs 1

void nn::fs::FileInputStream::vfunc_0x18(int param_1,undefined4 param_2)

{
  detail::FileBase::TrySetPosition(CONCAT44(param_2,param_1 + 4));
  return;
}


// FUNC 0x160004f4 nn::fs::FileInputStream::vfunc_0x2c (SaveLoad)
//   size 0x2c | file SaveLoad+0x4f4 | callers(0) | datarefs 1

int nn::fs::FileInputStream::vfunc_0x2c(int param_1,void *param_2,uint param_3,int param_4)

{
  int iVar1;
  int local_8;
  
  local_8 = param_4;
  iVar1 = detail::FileBase::TryRead((FileBase *)(param_1 + 4),&local_8,param_2,param_3);
  if (iVar1 < 0) {
    err::CTR::ThrowFatalErrAll(iVar1,0x16000514);
  }
  return local_8;
}


// FUNC 0x16000520 nn::fs::FileInputStream::vfunc_0xc (SaveLoad)
//   size 0x2c | file SaveLoad+0x520 | callers(0) | datarefs 1

void nn::fs::FileInputStream::vfunc_0xc(int param_1)

{
  int iVar1;
  undefined4 in_stack_00000000;
  
  iVar1 = detail::FileBase::TrySeek(param_1 + 4);
  if (-(iVar1 >> 0x1f) == 0) {
    return;
  }
  err::CTR::ThrowFatalErrAll(iVar1,0x1600053c,-(iVar1 >> 0x1f),in_stack_00000000);
  return;
}


// FUNC 0x1600054c nn::fs::FileInputStream::vfunc_0x28 (SaveLoad)
//   size 0x8 | file SaveLoad+0x54c | callers(0) | datarefs 1

void nn::fs::FileInputStream::vfunc_0x28(int param_1,int *param_2,void *param_3,uint param_4)

{
  detail::FileBase::TryRead((FileBase *)(param_1 + 4),param_2,param_3,param_4);
  return;
}


// FUNC 0x16000554 nn::fs::FileInputStream::vfunc_0x8 (SaveLoad)
//   size 0x18 | file SaveLoad+0x554 | callers(0) | datarefs 1

void nn::fs::FileInputStream::vfunc_0x8(int param_1)

{
  detail::FileBase::TrySeek(param_1 + 4);
  return;
}


// FUNC 0x1600056c nn::fs::FileInputStream::vfunc_0x4 (SaveLoad)
//   size 0x40 | file SaveLoad+0x56c | callers(0) | datarefs 1

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


// FUNC 0x160005ac nn::fs::FileInputStream::vfunc_0x0 (SaveLoad)
//   size 0x3c | file SaveLoad+0x5ac | callers(0) | datarefs 1

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


// FUNC 0x16000628 msys::MChrBase::vfunc_0x10 (SaveLoad)
//   size 0xc | file SaveLoad+0x628 | callers(0) | datarefs 1

void msys::MChrBase::vfunc_0x10(int param_1)

{
  *(undefined1 *)(param_1 + 0x142) = 0;
  return;
}


// FUNC 0x16000634 msys::MChrBase::vfunc_0xc (SaveLoad)
//   size 0x4 | file SaveLoad+0x634 | callers(0) | datarefs 1

void msys::MChrBase::vfunc_0xc(void)

{
  return;
}


// FUNC 0x16000638 msys::MChrBase::vfunc_0x8 (SaveLoad)
//   size 0xc | file SaveLoad+0x638 | callers(0) | datarefs 1

void msys::MChrBase::vfunc_0x8(int param_1)

{
  *(undefined1 *)(param_1 + 0x142) = 1;
  return;
}


// FUNC 0x16000644 FUN_16000644 (SaveLoad)
//   size 0x4 | file SaveLoad+0x644 | callers(0) | datarefs 2

void FUN_16000644(void)

{
  return;
}


// FUNC 0x16000648 save_load::Summary::vfunc_0x20 (SaveLoad)
//   size 0x8 | file SaveLoad+0x648 | callers(0) | datarefs 1

undefined4 save_load::Summary::vfunc_0x20(void)

{
  return 0;
}


// FUNC 0x16000650 save_load::Summary::vfunc_0x38 (SaveLoad)
//   size 0x4 | file SaveLoad+0x650 | callers(0) | datarefs 1

void save_load::Summary::vfunc_0x38(void)

{
  return;
}


// FUNC 0x16000654 save_load::Summary::vfunc_0x14 (SaveLoad)
//   size 0x2c | file SaveLoad+0x654 | callers(0) | datarefs 1

void save_load::Summary::vfunc_0x14(int param_1,MRenderQueueBase *param_2)

{
  if (*(char *)(param_1 + 0x141) == '\0') {
    return;
  }
  msys::MRenderQueueBase::enqueueMsg
            (param_2,(MessageSimple *)(param_1 + 0x14c),*(uint *)(param_1 + 0x6c40),'\n');
  return;
}


// FUNC 0x16000684 save_load::SaveLoadSys::vfunc_0x14 (SaveLoad)
//   size 0x8 | file SaveLoad+0x684 | callers(0) | datarefs 1

undefined4 save_load::SaveLoadSys::vfunc_0x14(void)

{
  return 0;
}


// FUNC 0x1600068c msys::MChrBase::vfunc_0x4 (SaveLoad)
//   size 0x10 | file SaveLoad+0x68c | callers(0) | datarefs 1

void msys::MChrBase::vfunc_0x4(void)

{
  void *pvVar1;
  
  pvVar1 = (void *)vfunc_0x0();
  operator_delete(pvVar1);
  return;
}


// FUNC 0x1600069c save_load::Summary::vfunc_0x10 (SaveLoad)
//   size 0x58 | file SaveLoad+0x69c | callers(0) | datarefs 1

void save_load::Summary::vfunc_0x10(MMsg *param_1)

{
  msys::MMsg::applyAnime(param_1);
  *(float *)(param_1 + 0x5c00) = *(float *)(param_1 + 0x5c00) + *(float *)(param_1 + 0x6c58);
  *(float *)(param_1 + 0x5c04) = *(float *)(param_1 + 0x5c04) + *(float *)(param_1 + 0x6c5c);
  if (((byte)param_1[0x5988] & 1) == 0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x160006ec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)(param_1 + 0x14c) + 0x28))();
  return;
}


// FUNC 0x160006f8 save_load::Summary::vfunc_0x3c (SaveLoad)
//   size 0x7c | file SaveLoad+0x6f8 | callers(0) | datarefs 1

void save_load::Summary::vfunc_0x3c(MMsg *param_1,wchar_t *param_2,InsParam *param_3,bool param_4)

{
  int iVar1;
  
  msys::MMsg::playStr(param_1,param_2,param_3,param_4);
  if ((((byte)nn::math::VEC3::Zero()::zero & 1) == 0) &&
     (iVar1 = __cxa_guard_acquire(&nn::math::VEC3::Zero()::zero), iVar1 != 0)) {
    nn::math::VEC3::Zero()::zero = 0;
    DAT_00434c4c = 0;
    DAT_00434c50 = 0;
    __cxa_guard_release(&nn::math::VEC3::Zero()::zero);
  }
  *(undefined4 *)(param_1 + 0x6c58) = nn::math::VEC3::Zero()::zero;
  *(undefined4 *)(param_1 + 0x6c5c) = DAT_00434c4c;
  *(undefined4 *)(param_1 + 0x6c60) = DAT_00434c50;
  param_1[0x5c08] = (MMsg)0x0;
  return;
}


// FUNC 0x16000784 FUN_16000784 (SaveLoad)
//   size 0x34 | file SaveLoad+0x784 | callers(0) | datarefs 1

void FUN_16000784(MoveVBase *param_1)

{
  void *pvVar1;
  
  *(undefined ***)param_1 = &vtable_for_5MoveVILj1EE;
  __aeabi_vec_dtor(param_1 + 0x30,MoveWorkF::~MoveWorkF,0x2c,1);
  pvVar1 = (void *)MoveVBase::~MoveVBase(param_1);
  operator_delete(pvVar1);
  return;
}


// FUNC 0x160007c0 FUN_160007c0 (SaveLoad)
//   size 0x30 | file SaveLoad+0x7c0 | callers(0) | datarefs 1

void FUN_160007c0(MoveVBase *param_1)

{
  *(undefined ***)param_1 = &vtable_for_5MoveVILj1EE;
  __aeabi_vec_dtor(param_1 + 0x30,MoveWorkF::~MoveWorkF,0x2c,1);
  MoveVBase::~MoveVBase(param_1);
  return;
}


// FUNC 0x160007f8 FUN_160007f8 (SaveLoad)
//   size 0x2c | file SaveLoad+0x7f8 | callers(0) | datarefs 3

undefined4 * FUN_160007f8(MoveWorkF *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)MoveWorkF::MoveWorkF(param_1);
  *puVar1 = &MoveWorkV::vtable;
  puVar1[8] = 0;
  puVar1[9] = 0;
  puVar1[10] = 0;
  return puVar1;
}


// FUNC 0x1600082c MoveWorkV::vfunc_0x4 (SaveLoad)
//   size 0x10 | file SaveLoad+0x82c | callers(0) | datarefs 1

void MoveWorkV::vfunc_0x4(MoveWorkF *param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)MoveWorkF::~MoveWorkF(param_1);
  operator_delete(pvVar1);
  return;
}


// FUNC 0x1600083c ->MoveWorkF::~MoveWorkF (SaveLoad)
//   size 0x4 | file SaveLoad+0x83c | callers(0) | datarefs 6
// veneer/thunk -> 0x00340694 MoveWorkF::~MoveWorkF (static)

// FUNC 0x16000840 save_load::SaveLoadSys::saveFormat (SaveLoad)
//   sym _ZN9save_load11SaveLoadSys10saveFormatEv | size 0x1c | file SaveLoad+0x840 | callers(2) 0x148005a0 0x16800278 | datarefs 2

/* save_load::SaveLoadSys::saveFormat() */

void save_load::SaveLoadSys::saveFormat(void)

{
  *(undefined2 *)(Backup::_fs + 0x24) = 0;
  Backup::format();
  return;
}


// FUNC 0x16000860 FUN_16000860 (SaveLoad)
//   size 0x70 | file SaveLoad+0x860 | callers(0) | datarefs 2

void FUN_16000860(MComSys *param_1)

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


// FUNC 0x160008d4 save_load::SaveLoadSys::funcDrawLower (SaveLoad)
//   sym _ZN9save_load11SaveLoadSys13funcDrawLowerEP7CmdList | size 0x38 | file SaveLoad+0x8d4 | callers(0) | datarefs 3

/* save_load::SaveLoadSys::funcDrawLower(CmdList*) */

void __thiscall save_load::SaveLoadSys::funcDrawLower(SaveLoadSys *this,CmdList *param_1)

{
  MTX44 aMStack_50 [68];
  
  msys::MCamera::getProjMtx((MCamera *)(this + 0x4ae34),aMStack_50,0x401);
  msys::MComSys::funcDrawLower((MComSys *)this,param_1);
  return;
}


// FUNC 0x16000914 save_load::SaveLoadSys::funcDrawUpper (SaveLoad)
//   sym _ZN9save_load11SaveLoadSys13funcDrawUpperEP7CmdList | size 0x4 | file SaveLoad+0x914 | callers(0) | datarefs 3

/* save_load::SaveLoadSys::funcDrawUpper(CmdList*) */

void save_load::SaveLoadSys::funcDrawUpper(CmdList *param_1)

{
  CmdList *in_r1;
  
  msys::MComSys::funcDrawUpper((MComSys *)param_1,in_r1);
  return;
}


// FUNC 0x16000918 save_load::SaveLoadSys::funcCalcLoadData (SaveLoad)
//   sym _ZN9save_load11SaveLoadSys16funcCalcLoadDataEv | size 0x2f8 | file SaveLoad+0x918 | callers(2) 0x14800808 0x16800538 | datarefs 2

/* save_load::SaveLoadSys::funcCalcLoadData() */

void __thiscall save_load::SaveLoadSys::funcCalcLoadData(SaveLoadSys *this)

{
  int iVar1;
  IAllocator *pIVar2;
  char *pcVar3;
  wchar_t *pwVar4;
  void *pvVar5;
  undefined4 uVar6;
  FileContext *pFVar7;
  char *pcVar8;
  bool bVar9;
  ulonglong uVar10;
  void *apvStackY_2a8 [128];
  uint uVar11;
  uint uVar12;
  uint *apuStack_80 [2];
  uint *local_78 [2];
  TaskBase *local_70;
  TransMultiSymbol aTStack_6c [44];
  undefined4 local_40;
  char *local_38 [4];
  SaveLoadSys *local_28;
  
  iVar1 = ad::lyt::LytDrawSys::GetInst();
  pIVar2 = (IAllocator *)(iVar1 + 0x5f4);
  if (ad::lyt::Layout::s_pAllocator != pIVar2) {
    ad::lyt::Initialize(pIVar2,pIVar2);
  }
  *(SaveLoadSys **)(iVar1 + 0x5f8) = this + 0xc;
  iVar1 = ad::lyt::LytDrawSys::GetInst();
  *(undefined4 *)(iVar1 + 0x5fc) = 0x10000;
  (**(code **)(**(int **)(*(int *)(this + 0xe64f0) + 0x44) + 0xc))
            (*(int **)(*(int *)(this + 0xe64f0) + 0x44),"MDFXMenuArchive");
  iVar1 = 0;
  local_38[0] = "menu_mario";
  local_38[1] = "menu_luigi";
  local_38[2] = "menu_koopa";
  do {
    local_70 = *(TaskBase **)(this + 4);
    pFVar7 = *(FileContext **)(this + 0x278);
    local_28 = this + 0xc;
    pcVar8 = local_38[iVar1];
    local_40 = *(undefined4 *)(pFVar7 + 0x24);
    ad::TransMultiSymbol::init(aTStack_6c,pcVar8);
    BinGlu4Acs::getEntryAcs((char *)local_78);
    pcVar3 = (char *)(*(int *)(pFVar7 + 0x24) + (*local_78[0] & 0x3fffffff));
    uVar12 = 0;
    ad::fw::TaskBase::readCA
              (local_70,(Resource *)(this + iVar1 * 0x44 + 0xfbb30),pFVar7,pcVar8,pcVar3,pcVar3 + 4,
               pcVar3 + 8,pcVar3 + 0xc,(MemAlcBase *)local_28,0x7f,(VramAlcBase *)0x0,0,
               (ResCacheArg *)0x0);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 3);
  msys::MComSys::readLytNum
            ((MComSys *)this,(FileContext *)(*(int *)(this + 0x278) + 0xa8),(MemAlcBase *)0x0);
  ad::fw::TaskBase::readLyt
            (*(TaskBase **)(this + 4),(Resource *)(this + 0xfbaa8),
             (FileContext *)(*(int *)(this + 0x278) + 0xa8),"MENU_BG",(MemAlcBase *)(this + 0xc),
             0x7f,(ResCacheArg *)0x0);
  ad::fw::TaskBase::readLyt
            (*(TaskBase **)(this + 4),(Resource *)(this + 0xfbaec),
             (FileContext *)(*(int *)(this + 0x278) + 0xa8),"SQ_CURSOR_SET",
             (MemAlcBase *)(this + 0xc),0x7f,(ResCacheArg *)0x0);
  pwVar4 = operator_new__(0x200,(MemAlcBase *)(this + 0xc),(char *)0x0,0x800000);
  MessageSys::GetPath(pwVar4,(wchar_t *)L"Menu.msbt",false);
  uVar11 = 0;
  uVar10 = nn::fs::CTR::MPCore::detail::UserFileSystem::TryOpenFile(apvStackY_2a8 + 0x81,pwVar4,1);
  uVar6 = (undefined4)(uVar10 >> 0x20);
  bVar9 = (uVar10 & 0x80000000) != 0;
  if (bVar9) {
    uVar6 = 0x16000b24;
  }
  if (bVar9 && (int)uVar10 < 0) {
    nn::err::CTR::ThrowFatalErrAll((int)uVar10,uVar6);
  }
  iVar1 = nn::fs::detail::FileBase::TryGetSize
                    ((FileBase *)(apvStackY_2a8 + 0x81),(longlong *)(local_78 + -6));
  if (iVar1 < 0) {
    nn::err::CTR::ThrowFatalErrAll(iVar1,0x16000b54);
  }
  pvVar5 = (void *)(**(code **)(*(int *)(this + 0xc) + 0xc))(this + 0xc,uVar12,0);
  *(void **)(this + 0xfba38) = pvVar5;
  iVar1 = nn::fs::detail::FileBase::TryRead
                    ((FileBase *)(apvStackY_2a8 + 0x81),(int *)(local_78 + -5),pvVar5,uVar12);
  if (iVar1 < 0) {
    nn::err::CTR::ThrowFatalErrAll(iVar1,0x16000b9c);
  }
  MsgDataAcsrBase::init((MsgDataAcsrBase *)(this + 0xfba3c),*(void **)(this + 0xfba38));
  if ((uVar11 & 0xfffffffe) != 0) {
    if ((uVar11 & 1) != 0) {
      nndbgPanic();
    }
    nn::fs::CTR::MPCore::detail::UserFileSystem::CloseFile((void *)(uVar11 & 0xfffffffe));
    uVar11 = 0;
  }
  if ((uVar11 & 0xfffffffe) != 0) {
    if ((uVar11 & 1) != 0) {
      nndbgPanic();
    }
    nn::fs::CTR::MPCore::detail::UserFileSystem::CloseFile((void *)(uVar11 & 0xfffffffe));
  }
  operator_delete__(pwVar4);
  return;
}


// FUNC 0x16000c58 save_load::SaveLoadSys::funcCalcCreateChr (SaveLoad)
//   sym _ZN9save_load11SaveLoadSys17funcCalcCreateChrEv | size 0x310 | file SaveLoad+0xc58 | callers(2) 0x14800820 0x16800540 | datarefs 2

/* save_load::SaveLoadSys::funcCalcCreateChr() */

void __thiscall save_load::SaveLoadSys::funcCalcCreateChr(SaveLoadSys *this)

{
  void *pvVar1;
  MLyt *this_00;
  SaveLoadSys *pSVar2;
  MLyt *this_01;
  MDfxChr *pMVar3;
  SaveLoadSys *pSVar4;
  SaveLoadSys *pSVar5;
  undefined4 *puVar6;
  
  ad::lyt::LytResourceMan::init((LytResourceMan *)(this + 2000));
  pvVar1 = (void *)ad::fw::Resource::getFileData((Resource *)(this + 0x844));
  ad::lyt::LytResourceMan::registerArc((LytResourceMan *)(this + 2000),pvVar1,".");
  pvVar1 = (void *)ad::fw::Resource::getFileData((Resource *)(this + 0xfbaa8));
  ad::lyt::LytResourceMan::registerArc((LytResourceMan *)(this + 2000),pvVar1,".");
  pvVar1 = (void *)ad::fw::Resource::getFileData((Resource *)(this + 0xfbaec));
  ad::lyt::LytResourceMan::registerArc((LytResourceMan *)(this + 2000),pvVar1,".");
  pSVar4 = this + 0xd3000;
  this_00 = (MLyt *)(this + 0xfbbfc);
  msys::MLyt::init(this_00,pSVar4,1);
  msys::MLyt::createLyt(this_00,(LytResourceMan *)(this + 2000),"MENU_BG_U.bflyt");
  MoveVBase::stop((MoveVBase *)(this + 0xfbcc8));
  *(undefined4 *)(this + 0xfbce4) = 0;
  *(undefined4 *)(this + 0xfbce8) = 0;
  *(undefined4 *)(this + 0xfbcec) = 0xc3520000;
  *(undefined4 *)(this + 0xfbccc) = *(undefined4 *)(this + 0xfbce4);
  pSVar2 = this + 0xfbc00;
  *(undefined4 *)(this + 0xfbcd0) = 0;
  *(undefined4 *)(this + 0xfbcd4) = 0xc3520000;
  *(undefined4 *)(this + 0xfbd38) = 0x400;
  puVar6 = *(undefined4 **)(this + 0xfbc04);
  *(undefined4 **)(*(int *)(this + 0xfbc00) + 4) = puVar6;
  pSVar5 = this + 0xe64d8;
  *puVar6 = *(undefined4 *)(this + 0xfbc00);
  if (pSVar2 != (SaveLoadSys *)0x0) {
    *(SaveLoadSys **)(this + 0xfbc04) = pSVar5;
    *(int *)pSVar2 = *(int *)pSVar5;
    *(SaveLoadSys **)(*(int *)pSVar5 + 4) = pSVar2;
    *(SaveLoadSys **)pSVar5 = pSVar2;
  }
  this_01 = (MLyt *)(this + 0xfbfa4);
  msys::MLyt::init(this_01,pSVar4,1);
  msys::MLyt::createLyt(this_01,(LytResourceMan *)(this + 2000),"MENU_BG_L.bflyt");
  MoveVBase::stop((MoveVBase *)(this + 0xfc070));
  *(undefined4 *)(this + 0xfc08c) = 0;
  *(undefined4 *)(this + 0xfc090) = 0;
  *(undefined4 *)(this + 0xfc094) = 0xc3520000;
  *(undefined4 *)(this + 0xfc074) = *(undefined4 *)(this + 0xfc08c);
  pSVar2 = this + 0xfbfa8;
  *(undefined4 *)(this + 0xfc078) = 0;
  *(undefined4 *)(this + 0xfc07c) = 0xc3520000;
  *(undefined4 *)(this + 0xfc0e0) = 0x401;
  puVar6 = *(undefined4 **)(this + 0xfbfac);
  pSVar5 = this + 0xe64e0;
  *(undefined4 **)(*(int *)(this + 0xfbfa8) + 4) = puVar6;
  *puVar6 = *(undefined4 *)(this + 0xfbfa8);
  if (pSVar2 != (SaveLoadSys *)0x0) {
    *(int *)pSVar2 = *(int *)pSVar5;
    *(SaveLoadSys **)(this + 0xfbfac) = pSVar5;
    *(SaveLoadSys **)(*(int *)pSVar5 + 4) = pSVar2;
    *(SaveLoadSys **)pSVar5 = pSVar2;
  }
  msys::MLyt::init((MLyt *)(this + 0xfc34c),pSVar4,0);
  msys::MLyt::createLyt((MLyt *)(this + 0xfc34c),(LytResourceMan *)(this + 2000),"SQ_CURSOR.bflyt");
  MoveVBase::stop((MoveVBase *)(this + 0xfc418));
  *(undefined4 *)(this + 0xfc434) = 0;
  *(undefined4 *)(this + 0xfc438) = 0;
  *(undefined4 *)(this + 0xfc43c) = 0xc347cccd;
  *(undefined4 *)(this + 0xfc41c) = *(undefined4 *)(this + 0xfc434);
  *(undefined4 *)(this + 0xfc420) = 0;
  *(undefined4 *)(this + 0xfc424) = 0xc347cccd;
  this[0xfc48d] = (SaveLoadSys)0x0;
  *(undefined4 *)(this + 0xfc488) = 0x401;
  puVar6 = *(undefined4 **)(this + 0xfc354);
  *(undefined4 **)(*(int *)(this + 0xfc350) + 4) = puVar6;
  *puVar6 = *(undefined4 *)(this + 0xfc350);
  pSVar2 = this + 0xfc350;
  if (pSVar2 != (SaveLoadSys *)0x0) {
    *(int *)pSVar2 = *(int *)pSVar5;
    *(SaveLoadSys **)(this + 0xfc354) = pSVar5;
    *(SaveLoadSys **)(*(int *)pSVar5 + 4) = pSVar2;
    *(SaveLoadSys **)pSVar5 = pSVar2;
  }
  pMVar3 = (MDfxChr *)(this + 0xfc6f4);
  msys::MDfxChr::init(pMVar3,(MemAlcBase *)(this + 0xc),*(MDfxSys **)(this + 0xe64f0),
                      (Scene *)(this + 0x4aaa0),0x400);
  msys::MDfxChr::playDfx(pMVar3,0x16);
  *(undefined2 *)(*(int *)(this + 0xfc848) + 0xf2) = 0;
  msys::MLyt::attachMChr
            (this_00,(MChrBase *)pMVar3,"INS_EFFECT_STAR_U",(char *)0x0,(char *)0x0,(char *)0x0);
  pMVar3 = (MDfxChr *)(this + 0xfc870);
  msys::MDfxChr::init(pMVar3,(MemAlcBase *)(this + 0xc),*(MDfxSys **)(this + 0xe64f0),
                      (Scene *)(this + 0x4aba4),0x401);
  msys::MDfxChr::playDfx(pMVar3,0x17);
  *(undefined2 *)(*(int *)(this + 0xfc9c4) + 0xf2) = 0;
  msys::MLyt::attachMChr
            (this_01,(MChrBase *)pMVar3,"INS_EFFECT_STAR_L",(char *)0x0,(char *)0x0,(char *)0x0);
  *(code **)(this + 0xf84) = FUN_16001444;
  *(undefined4 *)(this + 0xf88) = 0;
  return;
}


// FUNC 0x16000fc4 save_load::SaveLoadSys::saveIsBusyWriting (SaveLoad)
//   sym _ZN9save_load11SaveLoadSys17saveIsBusyWritingEv | size 0x30 | file SaveLoad+0xfc4 | callers(2) 0x148004d0 0x168002e0 | datarefs 2

/* save_load::SaveLoadSys::saveIsBusyWriting() */

bool __thiscall save_load::SaveLoadSys::saveIsBusyWriting(SaveLoadSys *this)

{
  int iVar1;
  
  iVar1 = Backup::isBusyWriting((Backup *)(this + 0xe9050));
  if (iVar1 == 0) {
    Backup::term();
  }
  return iVar1 != 0;
}


// FUNC 0x16000ff4 save_load::SaveLoadSys::saveWriteInitData (SaveLoad)
//   sym _ZN9save_load11SaveLoadSys17saveWriteInitDataEv | size 0x4c | file SaveLoad+0xff4 | callers(2) 0x148005b0 0x16800288 | datarefs 2

/* save_load::SaveLoadSys::saveWriteInitData() */

undefined4 __thiscall save_load::SaveLoadSys::saveWriteInitData(SaveLoadSys *this)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Backup::mount();
  uVar2 = 0;
  if (iVar1 != 0) {
    iVar1 = Backup::writeInitData((Backup *)(this + 0xe9050));
    if (iVar1 == 0) {
      CtrFS::unmountSaveData((CtrFS *)(*(int *)(this + 4) + 0x518));
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  return uVar2;
}


// FUNC 0x16001040 FUN_16001040 (SaveLoad)
//   size 0x134 | file SaveLoad+0x1040 | callers(2) 0x16001a40 0x16001cbc

void FUN_16001040(int param_1)

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


// FUNC 0x1600118c FUN_1600118c (SaveLoad)
//   size 0x144 | file SaveLoad+0x118c | callers(1) 0x1600150c

int FUN_1600118c(undefined4 *param_1)

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
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(puVar1 + 0xc,FUN_160007f8,0x2c,1);
  *(int *)(iVar2 + -8) = iVar2;
  *(undefined1 *)(iVar2 + -4) = 1;
  puVar1 = (undefined4 *)MoveVBase::MoveVBase((MoveVBase *)(iVar2 + 0x2c));
  *puVar1 = &vtable_for_5MoveVILj1EE;
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(puVar1 + 0xc,FUN_160007f8,0x2c,1);
  *(int *)(iVar2 + -8) = iVar2;
  *(undefined1 *)(iVar2 + -4) = 1;
  puVar1 = (undefined4 *)MoveVBase::MoveVBase((MoveVBase *)(iVar2 + 0x2c));
  *puVar1 = &vtable_for_5MoveVILj1EE;
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(puVar1 + 0xc,FUN_160007f8,0x2c,1);
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
  *(int *)(iVar2 + 0x48) = iVar2 + 0x48;
  *(int *)(iVar2 + 0x4c) = iVar2 + 0x48;
  *(undefined ***)(iVar2 + -0xfc) = &msys::MLyt::vtable;
  *(undefined1 *)(iVar2 + 0x50) = 0xff;
  *(undefined2 *)(iVar2 + 0x52) = 0;
  *(undefined4 *)(iVar2 + 0x54) = 0;
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(iVar2 + 0x58,&LAB_16000474,0x1c,0xc);
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(iVar2 + 0x15c,&LAB_160005e8,0x10,0xc);
  *(undefined4 *)(iVar2 + 0xc0) = 0;
  *(undefined1 *)(iVar2 + 0xc4) = 1;
  *(undefined4 *)(iVar2 + 200) = 0;
  *(undefined4 *)(iVar2 + 0xcc) = 0;
  *(undefined1 *)(iVar2 + 0xd0) = 0;
  *(undefined4 *)(iVar2 + 0xd4) = 0;
  *(undefined4 *)(iVar2 + 0xd8) = 0;
  FUN_160025d8(iVar2 + -0xc,0xffffffff);
  return iVar2 + -0x2b0;
}


// FUNC 0x160012e8 msys::MChrBase::vfunc_0x0 (SaveLoad)
//   size 0x14c | file SaveLoad+0x12e8 | callers(4) 0x1600068c 0x16001648 0x16001ee8 0x16001f58 | datarefs 1

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


// FUNC 0x16001444 FUN_16001444 (SaveLoad)
//   size 0xb4 | file SaveLoad+0x1444 | callers(0) | datarefs 2

void FUN_16001444(int param_1)

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
    *(code **)(param_1 + 0xf84) = FUN_16000860;
    *(undefined4 *)(param_1 + 0xf88) = 0;
  }
  return;
}


// FUNC 0x1600150c save_load::SaveLoadSys::SaveLoadSys (SaveLoad)
//   sym _ZN9save_load11SaveLoadSysC1Ev | size 0xfc | file SaveLoad+0x150c | callers(2) 0x14800868 0x16800528 | datarefs 2

/* save_load::SaveLoadSys::SaveLoadSys() */

int __thiscall save_load::SaveLoadSys::SaveLoadSys(SaveLoadSys *this)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_10;
  
  puVar1 = (undefined4 *)msys::MComSys::MComSys((MComSys *)this);
  *puVar1 = &vtable;
  iVar2 = Backup::Backup((Backup *)(puVar1 + 0x3a414));
  puVar1 = (undefined4 *)
           MsgDataAcsrBase::MsgDataAcsrBase
                     ((MsgDataAcsrBase *)(iVar2 + 0x129ec),(LMSBlockInfo *)(iVar2 + 0x12a18),4);
  *puVar1 = &vtable_for_20MsgDataAcsrTmplFixedILh4EE;
  iVar2 = ad::fw::Resource::Resource((Resource *)(puVar1 + 0x1b));
  iVar2 = ad::fw::Resource::Resource((Resource *)(iVar2 + 0x44));
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(iVar2 + 0x44,ad::fw::Resource::Resource,0x44,3);
  iVar2 = FUN_1600118c(iVar2 + 0xcc);
  iVar2 = FUN_1600118c(iVar2 + 0x3a8);
  iVar2 = FUN_1600118c(iVar2 + 0x3a8);
  iVar2 = msys::MDfxChr::MDfxChr((MDfxChr *)(iVar2 + 0x3a8));
  iVar2 = msys::MDfxChr::MDfxChr((MDfxChr *)(iVar2 + 0x17c));
  local_10 = 0xff808080;
  FrameBuf::setClearColor((FrameBuf *)&gFrameBuf,&local_10);
  return iVar2 + -0xfc870;
}


// FUNC 0x16001638 save_load::SaveLoadSys::vfunc_0x4 (SaveLoad)
//   size 0x10 | file SaveLoad+0x1638 | callers(0) | datarefs 1

void save_load::SaveLoadSys::vfunc_0x4(SaveLoadSys *param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)~SaveLoadSys(param_1);
  operator_delete(pvVar1);
  return;
}


// FUNC 0x16001648 save_load::SaveLoadSys::~SaveLoadSys (SaveLoad)
//   sym _ZN9save_load11SaveLoadSysD1Ev | size 0x1f8 | file SaveLoad+0x1648 | callers(3) 0x16001638 0x14800898 0x16800400 | datarefs 3

/* save_load::SaveLoadSys::~SaveLoadSys() */

void __thiscall save_load::SaveLoadSys::~SaveLoadSys(SaveLoadSys *this)

{
  MLyt *pMVar1;
  int iVar2;
  
  *(undefined ***)this = &vtable;
  ad::fw::TaskBase::term(*(TaskBase **)(this + 4),0);
  msys::MLyt::term((MLyt *)(this + 0xfbbfc));
  msys::MLyt::term((MLyt *)(this + 0xfbfa4));
  msys::MLyt::term((MLyt *)(this + 0xfc34c));
  ad::fw::Resource::term((Resource *)(this + 0xfbaa8));
  ad::fw::Resource::term((Resource *)(this + 0xfbaec));
  iVar2 = 0;
  do {
    ad::fw::Resource::term((Resource *)(this + iVar2 * 0x44 + 0xfbb30));
    iVar2 = iVar2 + 1;
  } while (iVar2 < 3);
  iVar2 = msys::MDfxChr::~MDfxChr((MDfxChr *)(this + 0xfc870));
  iVar2 = msys::MDfxChr::~MDfxChr((MDfxChr *)(iVar2 + -0x17c));
  pMVar1 = (MLyt *)(iVar2 + -0x3a8);
  *(undefined ***)pMVar1 = &msys::MLyt::vtable;
  msys::MLyt::term(pMVar1);
  __aeabi_vec_dtor(iVar2 + -0xf8,&LAB_16000618,0x10,0xc);
  __aeabi_vec_dtor(iVar2 + -0x254,&LAB_160004b0,0x1c,0xc);
  iVar2 = msys::MChrBase::vfunc_0x0(pMVar1);
  pMVar1 = (MLyt *)(iVar2 + -0x3a8);
  *(undefined ***)pMVar1 = &msys::MLyt::vtable;
  msys::MLyt::term(pMVar1);
  __aeabi_vec_dtor(iVar2 + -0xf8,&LAB_16000618,0x10,0xc);
  __aeabi_vec_dtor(iVar2 + -0x254,&LAB_160004b0,0x1c,0xc);
  iVar2 = msys::MChrBase::vfunc_0x0(pMVar1);
  pMVar1 = (MLyt *)(iVar2 + -0x3a8);
  *(undefined ***)pMVar1 = &msys::MLyt::vtable;
  msys::MLyt::term(pMVar1);
  __aeabi_vec_dtor(iVar2 + -0xf8,&LAB_16000618,0x10,0xc);
  __aeabi_vec_dtor(iVar2 + -0x254,&LAB_160004b0,0x1c,0xc);
  iVar2 = msys::MChrBase::vfunc_0x0(pMVar1);
  __aeabi_vec_dtor(iVar2 + -0xcc,ad::fw::Resource::~Resource,0x44,3);
  iVar2 = ad::fw::Resource::~Resource((Resource *)(iVar2 + -0x110));
  iVar2 = ad::fw::Resource::~Resource((Resource *)(iVar2 + -0x44));
  iVar2 = MsgDataAcsrBase::~MsgDataAcsrBase((MsgDataAcsrBase *)(iVar2 + -0x6c));
  iVar2 = Backup::~Backup((Backup *)(iVar2 + -0x129ec));
  msys::MComSys::~MComSys((MComSys *)(iVar2 + -0xe9050));
  return;
}


// FUNC 0x1600187c save_load::SaveDateTime::init (SaveLoad)
//   sym _ZN9save_load12SaveDateTime4initERNS_11SaveLoadSysERN4msys4MLytEPKcS7_ | size 0xc4 | file SaveLoad+0x187c | callers(2) 0x148006c8 0x16800450 | datarefs 2

/* save_load::SaveDateTime::init(save_load::SaveLoadSys&, msys::MLyt&, char const*, char const*) */

void __thiscall
save_load::SaveDateTime::init
          (SaveDateTime *this,SaveLoadSys *param_1,MLyt *param_2,char *param_3,char *param_4)

{
  int iVar1;
  InitParam aIStack_88 [52];
  uint local_54;
  
  ad::lyt::LytNumReel3::InitParam::InitParam(aIStack_88);
  msys::MLytNumRes::set((MLytNumRes *)(param_1 + 0x844),aIStack_88,0,0,0xff);
  iVar1 = 0;
  do {
    local_54 = (uint)(byte)(&DAT_16003000)[iVar1];
    msys::MLytNum::init((MLytNum *)(this + iVar1 * 0x230),aIStack_88,
                        (LytDrawData *)(param_1 + 0xd3000),param_2,(char *)(&DAT_16006a08)[iVar1],
                        param_3,param_4,(char *)0x0);
    msys::MLyt::attachMChr
              (param_2,(MChrBase *)(this + iVar1 * 0x230),(char *)(&DAT_16006a08)[iVar1],param_3,
               param_4,(char *)0x0);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 5);
  return;
}


// FUNC 0x16001948 save_load::SaveDateTime::build (SaveLoad)
//   sym _ZN9save_load12SaveDateTime5buildERK11GameWorkPOD | size 0xec | file SaveLoad+0x1948 | callers(2) 0x16800480 0x148006d0 | datarefs 2

/* save_load::SaveDateTime::build(GameWorkPOD const&) */

void __thiscall save_load::SaveDateTime::build(SaveDateTime *this,GameWorkPOD *param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0x28b8);
  if (9999 < uVar1) {
    uVar1 = uVar1 % 10000;
  }
  ad::lyt::LytNumReel3::setValueInstant((LytNumReel3 *)(this + 0x150),uVar1);
  uVar1 = (uint)(char)param_1[0x28bc];
  if (99 < uVar1) {
    uVar1 = uVar1 % 100;
  }
  ad::lyt::LytNumReel3::setValueInstant((LytNumReel3 *)(this + 0x380),uVar1);
  uVar1 = (uint)(char)param_1[0x28bd];
  if (99 < uVar1) {
    uVar1 = uVar1 % 100;
  }
  ad::lyt::LytNumReel3::setValueInstant((LytNumReel3 *)(this + 0x5b0),uVar1);
  uVar1 = (uint)(char)param_1[0x28be];
  if (99 < uVar1) {
    uVar1 = uVar1 % 100;
  }
  ad::lyt::LytNumReel3::setValueInstant((LytNumReel3 *)(this + 0x7e0),uVar1);
  uVar1 = (uint)(char)param_1[0x28bf];
  if (99 < uVar1) {
    uVar1 = uVar1 % 100;
  }
  ad::lyt::LytNumReel3::setValueInstant((LytNumReel3 *)(this + 0xa10),uVar1);
  return;
}


// FUNC 0x16001a40 save_load::MsgWnd::init (SaveLoad)
//   sym _ZN9save_load6MsgWnd4initERN4msys9MPageBaseEPKvP10MemAlcBasej | size 0x154 | file SaveLoad+0x1a40 | callers(2) 0x14800420 0x16800328 | datarefs 2

/* save_load::MsgWnd::init(msys::MPageBase&, void const*, MemAlcBase*, unsigned int) */

void __thiscall
save_load::MsgWnd::init
          (MsgWnd *this,MPageBase *param_1,void *param_2,MemAlcBase *param_3,uint param_4)

{
  MsgWnd *pMVar1;
  undefined4 uVar2;
  MPageBase *pMVar3;
  int iVar4;
  undefined4 *puVar5;
  
  *(uint *)(this + 0x6ef4) = param_4;
  *(uint *)(this + 0x6eb0) = param_4;
  *(MemAlcBase **)(this + 0x6eec) = param_3;
  *(undefined4 *)(this + 0x6ef0) = 0;
  *(undefined4 *)(this + 0x6eb4) = 0;
  *(undefined4 *)(this + 0x6eb8) = 0;
  this[0x6ed8] = (MsgWnd)0x1;
  this[0x6ed9] = (MsgWnd)0x0;
  *(undefined4 *)(this + 0x6ee0) = 0xffffffff;
  *(undefined4 *)(this + 0x6ee4) = 0xffffffff;
  *(MsgWnd **)(this + 0x6ed0) = this + 0x6ee8;
  *(undefined4 *)(this + 0x6ed4) = 0;
  Message::init((Message *)(this + 0x14c));
  Message::setMsgDat((Message *)(this + 0x14c),param_2);
  FUN_16001040(this);
  *(uint *)(this + 0x6efc) = param_4;
  *(undefined4 *)(this + 0x6f00) = 0;
  *(undefined4 *)(this + 0x6f04) = 0;
  this[0x6f24] = (MsgWnd)0x1;
  this[0x6f25] = (MsgWnd)0x0;
  *(undefined4 *)(this + 0x6f2c) = 0xffffffff;
  *(undefined4 *)(this + 0x6f30) = 0xffffffff;
  *(MsgWnd **)(this + 0x6f1c) = this + 0x6f34;
  *(undefined4 *)(this + 0x6f20) = 0;
  if (param_4 == 0x400) {
    pMVar3 = param_1 + 4;
    puVar5 = *(undefined4 **)(this + 8);
    *(undefined4 **)(*(int *)(this + 4) + 4) = puVar5;
    *puVar5 = *(undefined4 *)(this + 4);
    pMVar1 = this + 4;
    if (pMVar1 != (MsgWnd *)0x0) {
      iVar4 = *(int *)pMVar3;
      *(MPageBase **)(this + 8) = pMVar3;
      *(int *)pMVar1 = iVar4;
      *(MsgWnd **)(iVar4 + 4) = pMVar1;
      *(MsgWnd **)pMVar3 = pMVar1;
    }
    uVar2 = 0x400;
  }
  else {
    if (param_4 != 0x401) {
      return;
    }
    pMVar3 = param_1 + 0xc;
    puVar5 = *(undefined4 **)(this + 8);
    *(undefined4 **)(*(int *)(this + 4) + 4) = puVar5;
    *puVar5 = *(undefined4 *)(this + 4);
    pMVar1 = this + 4;
    if (pMVar1 != (MsgWnd *)0x0) {
      iVar4 = *(int *)pMVar3;
      *(MPageBase **)(this + 8) = pMVar3;
      *(int *)pMVar1 = iVar4;
      *(MsgWnd **)(iVar4 + 4) = pMVar1;
      *(MsgWnd **)pMVar3 = pMVar1;
    }
    uVar2 = 0x401;
  }
  *(undefined4 *)(this + 0x13c) = uVar2;
  return;
}


// FUNC 0x16001b9c save_load::MsgWnd::play (SaveLoad)
//   sym _ZN9save_load6MsgWnd4playEPKcPKN13MessageSimple8InsParamE | size 0x60 | file SaveLoad+0x1b9c | callers(2) 0x148005c0 0x168003c8 | datarefs 2

/* save_load::MsgWnd::play(char const*, MessageSimple::InsParam const*) */

void __thiscall save_load::MsgWnd::play(MsgWnd *this,char *param_1,InsParam *param_2)

{
  *(char **)(this + 0x6ef8) = param_1;
  *(InsParam **)(this + 0x6f28) = param_2;
  Message::play((Message *)(this + 0x14c),(PlayParam *)(this + 0x6ef8));
  MoveVBase::stop((MoveVBase *)(this + 0xcc));
  *(undefined4 *)(this + 0xe8) = 0;
  *(undefined4 *)(this + 0xec) = 0;
  *(undefined4 *)(this + 0xf0) = 0xc3340000;
  *(undefined4 *)(this + 0xd0) = *(undefined4 *)(this + 0xe8);
  *(undefined4 *)(this + 0xd4) = 0;
  *(undefined4 *)(this + 0xd8) = 0xc3340000;
  return;
}


// FUNC 0x16001c04 save_load::Summary::updateInput (SaveLoad)
//   sym _ZN9save_load7Summary11updateInputEPKN4msys6MInputE | size 0xa4 | file SaveLoad+0x1c04 | callers(0) | datarefs 2

/* save_load::Summary::updateInput(msys::MInput const*) */

void __thiscall save_load::Summary::updateInput(Summary *this,MInput *param_1)

{
  LytAnim *this_00;
  LytAnim *this_01;
  undefined4 uVar1;
  
  this_00 = (LytAnim *)(this + 0x6c68);
  this_01 = (LytAnim *)(this + 0x6c84);
  if ((*(uint *)(param_1 + 4) & 0x200) == 0) {
    if ((*(uint *)(param_1 + 4) & 0x100) != 0) {
      ad::lyt::LytAnim::stopAndSetFrm(this_00,0.0);
      ad::lyt::LytAnim::stopAndSetFrm(this_01,1.0);
      *(undefined4 *)(this + 0x6c64) = 0x40000000;
      return;
    }
    ad::lyt::LytAnim::stopAndSetFrm(this_00,0.0);
    ad::lyt::LytAnim::stopAndSetFrm(this_01,0.0);
    uVar1 = 0xbf800000;
  }
  else {
    ad::lyt::LytAnim::stopAndSetFrm(this_00,1.0);
    ad::lyt::LytAnim::stopAndSetFrm(this_01,0.0);
    uVar1 = 0xc0000000;
  }
  *(undefined4 *)(this + 0x6c64) = uVar1;
  return;
}


// FUNC 0x16001cbc save_load::Summary::init (SaveLoad)
//   sym _ZN9save_load7Summary4initEP10MemAlcBaseRN2ad3lyt6LayoutEPPKc | size 0x10c | file SaveLoad+0x1cbc | callers(2) 0x14800418 0x16800448 | datarefs 2

/* save_load::Summary::init(MemAlcBase*, ad::lyt::Layout&, char const**) */

void __thiscall
save_load::Summary::init(Summary *this,MemAlcBase *param_1,Layout *param_2,char **param_3)

{
  int iVar1;
  LytAnim *this_00;
  int iVar2;
  Layout *pLVar3;
  
  *(undefined4 *)(this + 0x6c40) = 0x400;
  *(MemAlcBase **)(this + 0x6c34) = param_1;
  *(undefined4 *)(this + 0x6c38) = 0;
  *(undefined4 *)(this + 0x6c3c) = 0;
  MessageSimple::init((MessageSimple *)(this + 0x14c));
  FUN_16001040(this);
  this[0x5c08] = (Summary)0x1;
  this[0x5c09] = (Summary)0x1;
  MoveVBase::stop((MoveVBase *)(this + 0xcc));
  *(undefined4 *)(this + 0xe8) = 0;
  iVar2 = 0;
  *(undefined4 *)(this + 0xec) = 0;
  *(undefined4 *)(this + 0xf0) = 0x3c23d70a;
  *(undefined4 *)(this + 0xd0) = *(undefined4 *)(this + 0xe8);
  *(undefined4 *)(this + 0xd4) = 0;
  *(undefined4 *)(this + 0xd8) = 0x3c23d70a;
  do {
    iVar1 = ad::lyt::Layout::FindPartsPaneByName(param_2,param_3[iVar2]);
    pLVar3 = *(Layout **)(iVar1 + 0xac);
    this_00 = (LytAnim *)(this + iVar2 * 0x1c + 0x6c68);
    ad::lyt::LytAnim::init(this_00,pLVar3,(char *)(&DAT_160069f4)[iVar2],"");
    ad::lyt::LytAnim::stopAndSetFrm(this_00,0.0);
    ad::lyt::LytAnim::term(this_00,true);
    ad::lyt::LytAnim::init(this_00,pLVar3,"OnOff","");
    ad::lyt::LytAnim::stopAndSetFrm(this_00,0.0);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 2);
  return;
}


// FUNC 0x16001ddc save_load::Summary::build (SaveLoad)
//   sym _ZN9save_load7Summary5buildERNS_11SaveLoadSysEj | size 0xec | file SaveLoad+0x1ddc | callers(2) 0x148006c0 0x16800478 | datarefs 2

/* save_load::Summary::build(save_load::SaveLoadSys&, unsigned int) */

void __thiscall save_load::Summary::build(Summary *this,SaveLoadSys *param_1,uint param_2)

{
  uint *puVar2;
  uint *puVar1;
  undefined4 uVar3;
  wchar_t *pwVar4;
  int iVar5;
  bool bVar6;
  bool bVar7;
  
  puVar1 = &DAT_16003210;
  do {
    puVar2 = puVar1;
    puVar1 = puVar2 + -2;
    bVar7 = (uint *)0x160030cf < puVar1;
    bVar6 = puVar1 == (uint *)&UNK_160030d0;
    if (&UNK_160030d0 < puVar1) {
      bVar7 = param_2 <= *puVar1;
      bVar6 = *puVar1 == param_2;
    }
  } while (bVar7 && !bVar6);
  uVar3 = LMS_GetTextIndexByLabel(param_1 + 0xfba44,puVar2[-1]);
  pwVar4 = (wchar_t *)LMS_GetText(param_1 + 0xfba44,uVar3);
  msys::MMsg::playStr((MMsg *)this,pwVar4,(InsParam *)0x0,false);
  if ((((byte)nn::math::VEC3::Zero()::zero & 1) == 0) &&
     (iVar5 = __cxa_guard_acquire(&nn::math::VEC3::Zero()::zero), iVar5 != 0)) {
    nn::math::VEC3::Zero()::zero = 0;
    DAT_00434c4c = 0;
    DAT_00434c50 = 0;
    __cxa_guard_release(&nn::math::VEC3::Zero()::zero);
  }
  *(undefined4 *)(this + 0x6c58) = nn::math::VEC3::Zero()::zero;
  *(undefined4 *)(this + 0x6c5c) = DAT_00434c4c;
  *(undefined4 *)(this + 0x6c60) = DAT_00434c50;
  this[0x5c08] = (Summary)0x0;
  Frm::play((Frm *)(this + 0x6c44),30.0);
  this[0x6c54] = (Summary)0x1;
  return;
}


// FUNC 0x16001ee8 save_load::Summary::vfunc_0x4 (SaveLoad)
//   size 0x60 | file SaveLoad+0x1ee8 | callers(0) | datarefs 1

void save_load::Summary::vfunc_0x4(undefined4 *param_1)

{
  int iVar1;
  void *pvVar2;
  
  *param_1 = &vtable;
  __aeabi_vec_dtor(param_1 + 0x1b1a,&LAB_160004b0,0x1c,2);
  param_1[0x1b13] = 0;
  *param_1 = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar1 = MessageSimple::~MessageSimple((MessageSimple *)(param_1 + 0x53));
  pvVar2 = (void *)msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  operator_delete(pvVar2);
  return;
}


// FUNC 0x16001f58 save_load::Summary::vfunc_0x0 (SaveLoad)
//   size 0x5c | file SaveLoad+0x1f58 | callers(0) | datarefs 1

void save_load::Summary::vfunc_0x0(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &vtable;
  __aeabi_vec_dtor(param_1 + 0x1b1a,&LAB_160004b0,0x1c,2);
  param_1[0x1b13] = 0;
  *param_1 = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar1 = MessageSimple::~MessageSimple((MessageSimple *)(param_1 + 0x53));
  msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  return;
}


// FUNC 0x16001fc4 save_load::FilePanel::init (SaveLoad)
//   sym _ZN9save_load9FilePanel4initENS0_5eModeERNS_11SaveLoadSysERN4msys4MLytEPKc | size 0x21c | file SaveLoad+0x1fc4 | callers(2) 0x16800320 0x148003c0 | datarefs 2

/* save_load::FilePanel::init(save_load::FilePanel::eMode, save_load::SaveLoadSys&, msys::MLyt&,
   char const*) */

void __thiscall
save_load::FilePanel::init(FilePanel *this,int param_2,int param_3,MLyt *param_4,char *param_5)

{
  int iVar1;
  Layout *pLVar2;
  uint uVar3;
  FilePanel *pFVar4;
  uint uVar5;
  uint in_fpscr;
  float fVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  LytAnim aLStack_e8 [4];
  undefined4 local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined2 local_d8;
  undefined2 local_d6;
  MLyt *local_c8;
  LytAnim aLStack_c0 [4];
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined2 local_b0;
  undefined2 local_ae;
  InitParam aIStack_a0 [72];
  MLytNumRes *local_58;
  LytDrawData *local_4c;
  
  iVar1 = msys::MLyt::getParts(param_4,param_5,(char *)0x0,(char *)0x0);
  pLVar2 = *(Layout **)(iVar1 + 0xac);
  uVar7 = 0;
  *(Layout **)(this + 0xe10) = pLVar2;
  local_bc = 0;
  local_b8 = 0x3f800000;
  local_b4 = 0;
  local_b0 = 1;
  local_ae = 0;
  ad::lyt::LytAnim::init(aLStack_c0,pLVar2,*(char **)(&DAT_160069ec + param_2 * 4),"");
  ad::lyt::LytAnim::stopAndSetFrm(aLStack_c0,0.0);
  ad::lyt::LytAnim::term(aLStack_c0,true);
  local_b4 = 0;
  local_58 = (MLytNumRes *)(param_3 + 0x844);
  local_4c = (LytDrawData *)(param_3 + 0xd3000);
  uVar5 = 0;
  do {
    uVar3 = uVar5 & 0xff;
    pFVar4 = this + uVar5 * 0x4b0;
    local_c8 = param_4;
    iVar1 = msys::MLyt::getParts(param_4,(char *)(&DAT_160069fc)[uVar3],param_5,(char *)0x0);
    *(undefined4 *)pFVar4 = *(undefined4 *)(iVar1 + 0xac);
    ad::lyt::LytNumReel3::InitParam::InitParam(aIStack_a0);
    msys::MLytNumRes::set(local_58,aIStack_a0,2,1,0xff);
    msys::MLytNum::init((MLytNum *)(pFVar4 + 4),aIStack_a0,local_4c,local_c8,"NUM_POS",
                        (char *)(&DAT_160069fc)[uVar3],param_5,(char *)0x0);
    msys::MLyt::attachMChr
              (local_c8,(MChrBase *)(pFVar4 + 4),"NUM_POS",(char *)(&DAT_160069fc)[uVar3],param_5,
               (char *)0x0);
    msys::MCellAnime::init
              ((MCellAnime *)(pFVar4 + 0x234),(Resource *)(param_3 + uVar3 * 0x44 + 0xfbb30));
    uVar8 = (&DAT_1600321c)[uVar3 * 2];
    uVar9 = (&DAT_16003220)[uVar3 * 2];
    MoveVBase::stop((MoveVBase *)(pFVar4 + 0x300));
    *(undefined4 *)(pFVar4 + 0x324) = 0;
    *(undefined4 *)(pFVar4 + 0x31c) = uVar8;
    *(undefined4 *)(pFVar4 + 800) = uVar9;
    *(undefined4 *)(pFVar4 + 0x30c) = 0;
    *(undefined4 *)(pFVar4 + 0x304) = uVar8;
    *(undefined4 *)(pFVar4 + 0x308) = uVar9;
    CellAnime::play((CellAnime *)(pFVar4 + 0x380),(&DAT_1600300c)[uVar3 * 2],0,1.0);
    msys::MLyt::attachMChr
              (local_c8,(MChrBase *)(pFVar4 + 0x234),"INS_FILE_CHARA_OBJ",
               (char *)(&DAT_160069fc)[uVar3],param_5,(char *)0x0);
    local_e0 = 0x3f800000;
    local_d8 = 1;
    local_d6 = 0;
    local_e4 = uVar7;
    local_dc = uVar7;
    ad::lyt::LytAnim::init(aLStack_e8,*(Layout **)pFVar4,"SET_MLK","");
    fVar6 = (float)VectorUnsignedToFloat(uVar3,(byte)(in_fpscr >> 0x16) & 3);
    ad::lyt::LytAnim::stopAndSetFrm(aLStack_e8,fVar6);
    ad::lyt::LytAnim::term(aLStack_e8,true);
    uVar5 = uVar5 + 1;
    local_dc = uVar7;
  } while ((int)uVar5 < 3);
  return;
}


// FUNC 0x1600220c save_load::FilePanel::build (SaveLoad)
//   sym _ZN9save_load9FilePanel5buildERK11GameWorkPOD | size 0x1b0 | file SaveLoad+0x220c | callers(2) 0x168002e8 0x148002f8 | datarefs 2

/* save_load::FilePanel::build(GameWorkPOD const&) */

void __thiscall save_load::FilePanel::build(FilePanel *this,GameWorkPOD *param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  FilePanel *pFVar5;
  uint in_fpscr;
  float fVar6;
  DataPc aDStack_130 [176];
  LytAnim aLStack_80 [4];
  undefined4 local_7c;
  undefined4 uStack_78;
  undefined4 local_74;
  undefined2 local_70;
  undefined2 local_6e;
  LytAnim local_64 [4];
  undefined4 local_60;
  undefined4 uStack_5c;
  undefined4 local_58;
  undefined2 local_54;
  undefined2 local_52;
  undefined4 local_50;
  undefined4 local_4c;
  DataPcEquipFxParam aDStack_38 [12];
  
  local_7c = 0;
  uStack_78 = 0x3f800000;
  local_74 = 0;
  local_70 = 1;
  local_6e = 0;
  ad::lyt::LytAnim::init(aLStack_80,*(Layout **)(this + 0xe10),"SET_DATA","");
  if (((byte)param_1[0x28b0] & 1) == 0) {
    if (*(uint *)(param_1 + 0x28b4) >> 8 < 20000) {
      uVar1 = 1;
    }
    else {
      uVar1 = 2;
    }
    fVar6 = (float)VectorUnsignedToFloat(uVar1,(byte)(in_fpscr >> 0x16) & 3);
    ad::lyt::LytAnim::stopAndSetFrm(aLStack_80,fVar6);
    DataPcEquipFxParam::DataPcEquipFxParam(aDStack_38);
    iVar4 = 0;
    do {
      DataPc::DataPc(aDStack_130,(uchar)iVar4,(DataPcPOD *)(param_1 + iVar4 * 0x34),aDStack_38);
      pFVar5 = this + iVar4 * 0x4b0;
      iVar2 = DataPc::getLv(aDStack_130);
      ad::lyt::LytNumReel3::setValueInstant((LytNumReel3 *)(pFVar5 + 0x154),iVar2);
      local_64[0] = (LytAnim)0x0;
      local_60 = 0;
      uStack_5c = 0x3f800000;
      local_58 = 0;
      local_54 = 1;
      local_52 = 0;
      local_50 = 0;
      local_4c = 0;
      ad::lyt::LytAnim::init(local_64,*(Layout **)pFVar5,"SET_LV_DIGIT","");
      uVar3 = DataPc::getLv(aDStack_130);
      fVar6 = (float)VectorUnsignedToFloat((uint)(9 < uVar3),(byte)(in_fpscr >> 0x16) & 3);
      ad::lyt::LytAnim::stopAndSetFrm(local_64,fVar6);
      ad::lyt::LytAnim::term(local_64,true);
      ad::lyt::LytAnim::init(local_64,*(Layout **)pFVar5,"SET_RANK","");
      uVar1 = DataPc::getRank(aDStack_130);
      fVar6 = (float)VectorUnsignedToFloat(uVar1,(byte)(in_fpscr >> 0x16) & 3);
      ad::lyt::LytAnim::stopAndSetFrm(local_64,fVar6);
      ad::lyt::LytAnim::term(local_64,true);
      iVar4 = iVar4 + 1;
      local_58 = 0;
    } while (iVar4 < 3);
  }
  else {
    ad::lyt::LytAnim::stopAndSetFrm(aLStack_80,0.0);
  }
  ad::lyt::LytAnim::term(aLStack_80,true);
  return;
}


// FUNC 0x160023dc FUN_160023dc (SaveLoad)
//   size 0x180 | file SaveLoad+0x23dc | callers(0)

void FUN_160023dc(undefined4 *param_1,int param_2,int param_3,MLyt *param_4,char *param_5)

{
  int iVar1;
  uint in_fpscr;
  float fVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  LytAnim aLStack_98 [4];
  undefined4 local_94;
  undefined4 uStack_90;
  undefined4 local_8c;
  undefined2 local_88;
  undefined2 local_86;
  InitParam aIStack_78 [72];
  
  iVar1 = msys::MLyt::getParts(param_4,(char *)(&DAT_160069fc)[param_2],param_5,(char *)0x0);
  *param_1 = *(undefined4 *)(iVar1 + 0xac);
  ad::lyt::LytNumReel3::InitParam::InitParam(aIStack_78);
  msys::MLytNumRes::set((MLytNumRes *)(param_3 + 0x844),aIStack_78,2,1,0xff);
  msys::MLytNum::init((MLytNum *)(param_1 + 1),aIStack_78,(LytDrawData *)(param_3 + 0xd3000),param_4
                      ,"NUM_POS",(char *)(&DAT_160069fc)[param_2],param_5,(char *)0x0);
  msys::MLyt::attachMChr
            (param_4,(MChrBase *)(param_1 + 1),"NUM_POS",(char *)(&DAT_160069fc)[param_2],param_5,
             (char *)0x0);
  msys::MCellAnime::init
            ((MCellAnime *)(param_1 + 0x8d),(Resource *)(param_3 + param_2 * 0x44 + 0xfbb30));
  uVar3 = (&DAT_1600321c)[param_2 * 2];
  uVar4 = (&DAT_16003220)[param_2 * 2];
  MoveVBase::stop((MoveVBase *)(param_1 + 0xc0));
  param_1[0xc9] = 0;
  param_1[199] = uVar3;
  param_1[200] = uVar4;
  param_1[0xc3] = 0;
  param_1[0xc1] = uVar3;
  param_1[0xc2] = uVar4;
  CellAnime::play((CellAnime *)(param_1 + 0xe0),(&DAT_1600300c)[param_2 * 2],0,1.0);
  msys::MLyt::attachMChr
            (param_4,(MChrBase *)(param_1 + 0x8d),"INS_FILE_CHARA_OBJ",
             (char *)(&DAT_160069fc)[param_2],param_5,(char *)0x0);
  local_94 = 0;
  uStack_90 = 0x3f800000;
  local_8c = 0;
  local_88 = 1;
  local_86 = 0;
  ad::lyt::LytAnim::init(aLStack_98,(Layout *)*param_1,"SET_MLK","");
  fVar2 = (float)VectorUnsignedToFloat(param_2,(byte)(in_fpscr >> 0x16) & 3);
  ad::lyt::LytAnim::stopAndSetFrm(aLStack_98,fVar2);
  ad::lyt::LytAnim::term(aLStack_98,true);
  return;
}


// FUNC 0x16002580 nn::fs::FileInputStream::vfunc_0x20 (SaveLoad)
//   size 0x8 | file SaveLoad+0x2580 | callers(0) | datarefs 1

void nn::fs::FileInputStream::vfunc_0x20(int param_1,longlong *param_2)

{
  detail::FileBase::TryGetSize((FileBase *)(param_1 + 4),param_2);
  return;
}


// FUNC 0x16002588 nn::fs::FileInputStream::vfunc_0x14 (SaveLoad)
//   size 0x8 | file SaveLoad+0x2588 | callers(0) | datarefs 1

undefined8 nn::fs::FileInputStream::vfunc_0x14(int param_1)

{
  return *(undefined8 *)(param_1 + 8);
}


// FUNC 0x16002590 nn::fs::FileInputStream::vfunc_0x10 (SaveLoad)
//   size 0x14 | file SaveLoad+0x2590 | callers(0) | datarefs 1

undefined4 nn::fs::FileInputStream::vfunc_0x10(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 0xc);
  *param_2 = *(undefined4 *)(param_1 + 8);
  param_2[1] = uVar1;
  return 0;
}


// FUNC 0x160025a4 nn::fs::FileInputStream::vfunc_0x24 (SaveLoad)
//   size 0x2c | file SaveLoad+0x25a4 | callers(0) | datarefs 1

longlong nn::fs::FileInputStream::vfunc_0x24(int param_1)

{
  int iVar1;
  longlong local_10;
  
  iVar1 = detail::FileBase::TryGetSize((FileBase *)(param_1 + 4),&local_10);
  if (iVar1 < 0) {
    err::CTR::ThrowFatalErrAll(iVar1,0x160025c0);
  }
  return local_10;
}


// FUNC 0x160025d0 save_load::Summary::vfunc_0x1c (SaveLoad)
//   size 0x8 | file SaveLoad+0x25d0 | callers(0) | datarefs 1

undefined4 save_load::Summary::vfunc_0x1c(void)

{
  return 7;
}


// FUNC 0x160025d8 FUN_160025d8 (SaveLoad)
//   size 0x1c | file SaveLoad+0x25d8 | callers(1) 0x1600118c

void FUN_160025d8(uint *param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = param_2 & 0xff | (param_2 & 0xff) << 8;
  uVar1 = uVar1 | uVar1 << 0x10;
  *param_1 = uVar1;
  param_1[1] = uVar1;
  param_1[2] = uVar1;
  return;
}


// FUNC 0x160025f4 SaveLoad::nnroControlObject_ (SaveLoad)
//   size 0x74 | file SaveLoad+0x25f4 | callers(0)

undefined4 SaveLoad::nnroControlObject_(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined *puVar2;
  
  switch(param_2) {
  case 0:
    uVar1 = 0;
    break;
  case 1:
    DAT_16006a1c = param_1;
    return 0;
  case 2:
    uVar1 = DAT_16006a1c;
    break;
  case 3:
    *param_1 = &DAT_160026a0;
    puVar2 = &DAT_160026a0;
    goto LAB_16002654;
  case 4:
    *param_1 = &DAT_16003a7c;
    puVar2 = &DAT_16003a7c;
LAB_16002654:
    param_1[1] = puVar2;
    return 0;
  default:
    return 0xd8e12c21;
  }
  *param_1 = uVar1;
  return 0;
}


