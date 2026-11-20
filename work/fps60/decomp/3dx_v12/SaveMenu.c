// fps60 TG decompiled C: 3dx_v12.code.bin module SaveMenu part 1 (Ghidra 12.2, ARM:LE:32:v6:hardfp)
// Addresses: static = runtime address; CRO = fixed analysis base (crolink.py), NOT runtime.

// FUNC 0x16800180 ->operator.new (SaveMenu)
//   size 0x4 | file SaveMenu+0x180 | callers(3) 0x168005c0 0x16803fbc 0x16803a54
// veneer/thunk -> 0x00287d40 operator.new (static)

// FUNC 0x16800188 ->TaskMan::entry (SaveMenu)
//   size 0x4 | file SaveMenu+0x188 | callers(1) 0x168005c0
// veneer/thunk -> 0x00287b18 TaskMan::entry (static)

// FUNC 0x16800190 ->CellAnime::CellAnime (SaveMenu)
//   size 0x4 | file SaveMenu+0x190 | callers(3) 0x16803454 0x168006cc 0x16800bc0
// veneer/thunk -> 0x0026be18 CellAnime::CellAnime (static)

// FUNC 0x16800198 ->CellAnime::~CellAnime (SaveMenu)
//   size 0x4 | file SaveMenu+0x198 | callers(3) 0x16803798 0x1680070c 0x16800bf8
// veneer/thunk -> 0x0024fc94 CellAnime::~CellAnime (static)

// FUNC 0x168001a0 ->MoveVBase::update (SaveMenu)
//   size 0x4 | file SaveMenu+0x1a0 | callers(2) 0x16800748 0x16800958
// veneer/thunk -> 0x002597d4 MoveVBase::update (static)

// FUNC 0x168001a8 ->MessageSimple::init (SaveMenu)
//   size 0x4 | file SaveMenu+0x1a8 | callers(1) 0x168007a4
// veneer/thunk -> 0x002736b4 MessageSimple::init (static)

// FUNC 0x168001b0 ->__cxa_guard_acquire (SaveMenu)
//   size 0x4 | file SaveMenu+0x1b0 | callers(2) 0x168031f4 0x168007a4
// veneer/thunk -> 0x00288110 __cxa_guard_acquire (static)

// FUNC 0x168001b8 ->__cxa_guard_release (SaveMenu)
//   size 0x4 | file SaveMenu+0x1b8 | callers(2) 0x168031f4 0x168007a4
// veneer/thunk -> 0x001018a8 __cxa_guard_release (static)

// FUNC 0x168001c0 ->MoveVBase::stop (SaveMenu)
//   size 0x4 | file SaveMenu+0x1c0 | callers(6) 0x168021a0 0x168007a4 0x16800cc8 0x16800d50 0x1680179c 0x1680304c
// veneer/thunk -> 0x00259dd8 MoveVBase::stop (static)

// FUNC 0x168001c8 ->msys::MRenderQueueBase::enqueueMsg (SaveMenu)
//   size 0x4 | file SaveMenu+0x1c8 | callers(2) 0x16800918 0x16800a34
// veneer/thunk -> 0x00328df0 msys::MRenderQueueBase::enqueueMsg (static)

// FUNC 0x168001d0 ->CtrBtn::get (SaveMenu)
//   size 0x4 | file SaveMenu+0x1d0 | callers(1) 0x16800958
// veneer/thunk -> 0x003627f0 CtrBtn::get (static)

// FUNC 0x168001d8 ->Message::func (SaveMenu)
//   size 0x4 | file SaveMenu+0x1d8 | callers(1) 0x16800958
// veneer/thunk -> 0x00273be0 Message::func (static)

// FUNC 0x168001e0 ->operator.delete (SaveMenu)
//   size 0x4 | file SaveMenu+0x1e0 | callers(11) 0x16804324 0x16800a64 0x16800a84 0x16800b2c 0x16800b40 0x16803168 0x16803788 0x16803aec ...
// veneer/thunk -> 0x00286514 operator.delete (static)

// FUNC 0x168001e8 ->msys::MPageBase::enqueueLowerChr (SaveMenu)
//   size 0x4 | file SaveMenu+0x1e8 | callers(1) 0x16800a74
// veneer/thunk -> 0x00334104 msys::MPageBase::enqueueLowerChr (static)

// FUNC 0x168001f0 ->msys::MPageBase::enqueueUpperChr (SaveMenu)
//   size 0x4 | file SaveMenu+0x1f0 | callers(1) 0x16800a7c
// veneer/thunk -> 0x00334184 msys::MPageBase::enqueueUpperChr (static)

// FUNC 0x168001f8 ->__aeabi_vec_dtor (SaveMenu)
//   size 0x4 | file SaveMenu+0x1f8 | callers(5) 0x168024d8 0x16800a84 0x16800ac0 0x16802070 0x16803798
// veneer/thunk -> 0x00288230 __aeabi_vec_dtor (static)

// FUNC 0x16800200 ->MoveVBase::~MoveVBase (SaveMenu)
//   size 0x4 | file SaveMenu+0x200 | callers(3) 0x168024d8 0x16800a84 0x16800ac0
// veneer/thunk -> 0x002535e8 MoveVBase::~MoveVBase (static)

// FUNC 0x16800208 ->MoveWorkF::MoveWorkF (SaveMenu)
//   size 0x4 | file SaveMenu+0x208 | callers(1) 0x16800af8
// veneer/thunk -> 0x00278cc0 MoveWorkF::MoveWorkF (static)

// FUNC 0x16800210 ->MoveWorkF::~MoveWorkF (SaveMenu)
//   size 0x4 | file SaveMenu+0x210 | callers(2) 0x16800b2c 0x16800b3c
// veneer/thunk -> 0x00340694 MoveWorkF::~MoveWorkF (static)

// FUNC 0x16800218 ->Message::term (SaveMenu)
//   size 0x4 | file SaveMenu+0x218 | callers(3) 0x16800b40 0x16800b74 0x16803798
// veneer/thunk -> 0x0033dc68 Message::term (static)

// FUNC 0x16800220 ->Message::~Message (SaveMenu)
//   size 0x4 | file SaveMenu+0x220 | callers(3) 0x16800b40 0x16800b74 0x16803798
// veneer/thunk -> 0x00206538 Message::~Message (static)

// FUNC 0x16800228 ->msys::MLytNum::MLytNum (SaveMenu)
//   size 0x4 | file SaveMenu+0x228 | callers(2) 0x168031f4 0x16800bac
// veneer/thunk -> 0x003317a4 msys::MLytNum::MLytNum (static)

// FUNC 0x16800230 ->msys::MLytNum::~MLytNum (SaveMenu)
//   size 0x4 | file SaveMenu+0x230 | callers(2) 0x16803798 0x16800c08
// veneer/thunk -> 0x00331840 msys::MLytNum::~MLytNum (static)

// FUNC 0x16800238 ->ad::lyt::LytResourceMan::init (SaveMenu)
//   size 0x4 | file SaveMenu+0x238 | callers(2) 0x16803454 0x16800c50
// veneer/thunk -> 0x00250d1c ad::lyt::LytResourceMan::init (static)

// FUNC 0x16800240 ->ad::fw::Resource::getFileData (SaveMenu)
//   size 0x4 | file SaveMenu+0x240 | callers(1) 0x16800c5c
// veneer/thunk -> 0x00251d10 ad::fw::Resource::getFileData (static)

// FUNC 0x16800248 ->ad::lyt::LytResourceMan::registerArc (SaveMenu)
//   size 0x4 | file SaveMenu+0x248 | callers(1) 0x16800c6c
// veneer/thunk -> 0x0015c910 ad::lyt::LytResourceMan::registerArc (static)

// FUNC 0x16800250 ->msys::MLyt::build (SaveMenu)
//   size 0x4 | file SaveMenu+0x250 | callers(2) 0x16800c8c 0x16800d0c
// veneer/thunk -> 0x0032c460 msys::MLyt::build (static)

// FUNC 0x16800258 ->msys::MLyt::init (SaveMenu)
//   size 0x4 | file SaveMenu+0x258 | callers(2) 0x16800ca0 0x16800d1c
// veneer/thunk -> 0x0032c3a0 msys::MLyt::init (static)

// FUNC 0x16800260 ->msys::MLyt::createLyt (SaveMenu)
//   size 0x4 | file SaveMenu+0x260 | callers(1) 0x16800cb0
// veneer/thunk -> 0x0032c78c msys::MLyt::createLyt (static)

// FUNC 0x16800268 ->msys::MLyt::createLyt (SaveMenu)
//   size 0x4 | file SaveMenu+0x268 | callers(1) 0x16800d40
// veneer/thunk -> 0x0032c8c0 msys::MLyt::createLyt (static)

// FUNC 0x16800270 ->Backup::errorCode (SaveMenu)
//   size 0x4 | file SaveMenu+0x270 | callers(3) 0x168010ac 0x16800e08 0x16800f7c
// veneer/thunk -> 0x002063b8 Backup::errorCode (static)

// FUNC 0x16800278 ->save_load::SaveLoadSys::saveFormat (SaveMenu)
//   size 0x4 | file SaveMenu+0x278 | callers(3) 0x16801f44 0x16800e08 0x16800f7c
// veneer/thunk -> 0x16000840 save_load::SaveLoadSys::saveFormat (SaveLoad)

// FUNC 0x16800280 ->Backup::isBusyFormat (SaveMenu)
//   size 0x4 | file SaveMenu+0x280 | callers(1) 0x16800e08
// veneer/thunk -> 0x00339378 Backup::isBusyFormat (static)

// FUNC 0x16800288 ->save_load::SaveLoadSys::saveWriteInitData (SaveMenu)
//   size 0x4 | file SaveMenu+0x288 | callers(1) 0x16800e08
// veneer/thunk -> 0x16000ff4 save_load::SaveLoadSys::saveWriteInitData (SaveLoad)

// FUNC 0x16800290 ->GameMain::Back (SaveMenu)
//   size 0x4 | file SaveMenu+0x290 | callers(2) 0x16803c80 0x16800ef4
// veneer/thunk -> 0x0033e354 GameMain::Back (static)

// FUNC 0x16800298 ->Backup::GetSaveData1 (SaveMenu)
//   size 0x4 | file SaveMenu+0x298 | callers(5) 0x16802e64 0x16801390 0x16801430 0x168010ac 0x16800efc
// veneer/thunk -> 0x00339284 Backup::GetSaveData1 (static)

// FUNC 0x168002a0 ->msys::MLyt::getParts (SaveMenu)
//   size 0x4 | file SaveMenu+0x2a0 | callers(4) 0x168013a8 0x16801598 0x168010ac 0x16800efc
// veneer/thunk -> 0x002073ec msys::MLyt::getParts (static)

// FUNC 0x168002a8 ->msys::MMapIconMan::setUp (SaveMenu)
//   size 0x4 | file SaveMenu+0x2a8 | callers(3) 0x168013b8 0x168010ac 0x16800efc
// veneer/thunk -> 0x00324a90 msys::MMapIconMan::setUp (static)

// FUNC 0x168002b0 ->Backup::isBusyWriting (SaveMenu)
//   size 0x4 | file SaveMenu+0x2b0 | callers(1) 0x16800f7c
// veneer/thunk -> 0x00339558 Backup::isBusyWriting (static)

// FUNC 0x168002b8 ->GameWork::preSaveGameWork (SaveMenu)
//   size 0x4 | file SaveMenu+0x2b8 | callers(2) 0x16801db8 0x16800f7c
// veneer/thunk -> 0x0033eb48 GameWork::preSaveGameWork (static)

// FUNC 0x168002c0 ->Backup::writeSaveData (SaveMenu)
//   size 0x4 | file SaveMenu+0x2c0 | callers(2) 0x16801db8 0x16800f7c
// veneer/thunk -> 0x00339878 Backup::writeSaveData (static)

// FUNC 0x168002c8 ->SndSys::StopAll (SaveMenu)
//   size 0x4 | file SaveMenu+0x2c8 | callers(1) 0x16801064
// veneer/thunk -> 0x0033c7e0 SndSys::StopAll (static)

// FUNC 0x168002d0 ->SndSys::RebuildSeHeap (SaveMenu)
//   size 0x4 | file SaveMenu+0x2d0 | callers(1) 0x16801064
// veneer/thunk -> 0x0033c4b0 SndSys::RebuildSeHeap (static)

// FUNC 0x168002d8 ->GameMain::Start (SaveMenu)
//   size 0x4 | file SaveMenu+0x2d8 | callers(1) 0x16801064
// veneer/thunk -> 0x0033e67c GameMain::Start (static)

// FUNC 0x168002e0 ->save_load::SaveLoadSys::saveIsBusyWriting (SaveMenu)
//   size 0x4 | file SaveMenu+0x2e0 | callers(1) 0x168010ac
// veneer/thunk -> 0x16000fc4 save_load::SaveLoadSys::saveIsBusyWriting (SaveLoad)

// FUNC 0x168002e8 ->save_load::FilePanel::build (SaveMenu)
//   size 0x4 | file SaveMenu+0x2e8 | callers(2) 0x1680143c 0x168010ac
// veneer/thunk -> 0x1600220c save_load::FilePanel::build (SaveLoad)

// FUNC 0x168002f0 ->msys::MLyt::playAnimeFromNo (SaveMenu)
//   size 0x4 | file SaveMenu+0x2f0 | callers(5) 0x16801cc8 0x16801884 0x16801ae0 0x168033cc 0x168010ac
// veneer/thunk -> 0x0032bf98 msys::MLyt::playAnimeFromNo (static)

// FUNC 0x168002f8 ->Message::close (SaveMenu)
//   size 0x4 | file SaveMenu+0x2f8 | callers(1) 0x168010ac
// veneer/thunk -> 0x0024dcc8 Message::close (static)

// FUNC 0x16800300 ->ad::lyt::LytLocalize::LytLocalize (SaveMenu)
//   size 0x4 | file SaveMenu+0x300 | callers(1) 0x16801234
// veneer/thunk -> 0x002563d4 ad::lyt::LytLocalize::LytLocalize (static)

// FUNC 0x16800308 ->ad::lyt::LytLocalize::localize (SaveMenu)
//   size 0x4 | file SaveMenu+0x308 | callers(2) 0x1680124c 0x16801260
// veneer/thunk -> 0x00264e08 ad::lyt::LytLocalize::localize (static)

// FUNC 0x16800310 ->msys::MLyt::getMPaneRef (SaveMenu)
//   size 0x4 | file SaveMenu+0x310 | callers(2) 0x16801308 0x16801324
// veneer/thunk -> 0x0032ba20 msys::MLyt::getMPaneRef (static)

// FUNC 0x16800318 ->msys::MMapIconMan::init (SaveMenu)
//   size 0x4 | file SaveMenu+0x318 | callers(1) 0x16801370
// veneer/thunk -> 0x00324930 msys::MMapIconMan::init (static)

// FUNC 0x16800320 ->save_load::FilePanel::init (SaveMenu)
//   size 0x4 | file SaveMenu+0x320 | callers(1) 0x16801410
// veneer/thunk -> 0x16001fc4 save_load::FilePanel::init (SaveLoad)

// FUNC 0x16800328 ->save_load::MsgWnd::init (SaveMenu)
//   size 0x4 | file SaveMenu+0x328 | callers(1) 0x16801478
// veneer/thunk -> 0x16001a40 save_load::MsgWnd::init (SaveLoad)

// FUNC 0x16800330 ->ad::ctrl::ButtonGroup::FindButtonByName (SaveMenu)
//   size 0x4 | file SaveMenu+0x330 | callers(1) 0x168014a0
// veneer/thunk -> 0x00256680 ad::ctrl::ButtonGroup::FindButtonByName (static)

// FUNC 0x16800338 ->ad::ctrl::AnimButton::SetStateChangeCallback (SaveMenu)
//   size 0x4 | file SaveMenu+0x338 | callers(1) 0x168014b8
// veneer/thunk -> 0x00256674 ad::ctrl::AnimButton::SetStateChangeCallback (static)

// FUNC 0x16800340 ->ad::fw::TaskBase::isFps30 (SaveMenu)
//   size 0x4 | file SaveMenu+0x340 | callers(1) 0x16801510
// veneer/thunk -> 0x0025edd0 ad::fw::TaskBase::isFps30 (static)

// FUNC 0x16800348 ->msys::MCursorBase::setVisible (SaveMenu)
//   size 0x4 | file SaveMenu+0x348 | callers(4) 0x168029c4 0x168015b8 0x168018f4 0x168010ac
// veneer/thunk -> 0x00324454 msys::MCursorBase::setVisible (static)

// FUNC 0x16800350 ->ad::lyt::LytAnim::init (SaveMenu)
//   size 0x4 | file SaveMenu+0x350 | callers(3) 0x168015f8 0x168016a4 0x1680304c
// veneer/thunk -> 0x00264f04 ad::lyt::LytAnim::init (static)

// FUNC 0x16800358 ->ad::lyt::AnimTransform::GetFrameSize (SaveMenu)
//   size 0x4 | file SaveMenu+0x358 | callers(2) 0x16801674 0x168016b0
// veneer/thunk -> 0x0026fe38 ad::lyt::AnimTransform::GetFrameSize (static)

// FUNC 0x16800360 ->ad::lyt::LytAnim::stopAndSetFrm (SaveMenu)
//   size 0x4 | file SaveMenu+0x360 | callers(3) 0x16802e64 0x16801684 0x168016c0
// veneer/thunk -> 0x0026fe44 ad::lyt::LytAnim::stopAndSetFrm (static)

// FUNC 0x16800368 ->ad::lyt::LytAnim::term (SaveMenu)
//   size 0x4 | file SaveMenu+0x368 | callers(2) 0x16801690 0x168016cc
// veneer/thunk -> 0x00264e90 ad::lyt::LytAnim::term (static)

// FUNC 0x16800370 ->msys::MLyt::createAnimeAutoSlot (SaveMenu)
//   size 0x4 | file SaveMenu+0x370 | callers(1) 0x168016e4
// veneer/thunk -> 0x0032c308 msys::MLyt::createAnimeAutoSlot (static)

// FUNC 0x16800378 ->msys::MLyt::getAnim (SaveMenu)
//   size 0x4 | file SaveMenu+0x378 | callers(1) 0x168016f0
// veneer/thunk -> 0x0032c678 msys::MLyt::getAnim (static)

// FUNC 0x16800380 ->Frm::setSpd (SaveMenu)
//   size 0x4 | file SaveMenu+0x380 | callers(1) 0x168016fc
// veneer/thunk -> 0x0027a2a4 Frm::setSpd (static)

// FUNC 0x16800388 ->msys::MLyt::stopAnimeAndSetEnd (SaveMenu)
//   size 0x4 | file SaveMenu+0x388 | callers(2) 0x16801714 0x1680172c
// veneer/thunk -> 0x0032c27c msys::MLyt::stopAnimeAndSetEnd (static)

// FUNC 0x16800390 ->msys::MLyt::setAnimeInfo (SaveMenu)
//   size 0x4 | file SaveMenu+0x390 | callers(2) 0x1680173c 0x1680174c
// veneer/thunk -> 0x0032bc40 msys::MLyt::setAnimeInfo (static)

// FUNC 0x16800398 ->MessageWriter::setFontColor (SaveMenu)
//   size 0x4 | file SaveMenu+0x398 | callers(2) 0x16801788 0x1680304c
// veneer/thunk -> 0x00270f0c MessageWriter::setFontColor (static)

// FUNC 0x168003a0 ->LMS_GetTextIndexByLabel (SaveMenu)
//   size 0x4 | file SaveMenu+0x3a0 | callers(2) 0x16802e64 0x168017e4
// veneer/thunk -> 0x0027616c LMS_GetTextIndexByLabel (static)

// FUNC 0x168003a8 ->LMS_GetText (SaveMenu)
//   size 0x4 | file SaveMenu+0x3a8 | callers(2) 0x16802e64 0x168017f0
// veneer/thunk -> 0x0027660c LMS_GetText (static)

// FUNC 0x168003b0 ->msys::MMsg::playStr (SaveMenu)
//   size 0x4 | file SaveMenu+0x3b0 | callers(1) 0x16801804
// veneer/thunk -> 0x0032ce0c msys::MMsg::playStr (static)

// FUNC 0x168003b8 ->msys::MLyt::attachMChr (SaveMenu)
//   size 0x4 | file SaveMenu+0x3b8 | callers(3) 0x16801820 0x16802cd4 0x1680304c
// veneer/thunk -> 0x00207468 msys::MLyt::attachMChr (static)

// FUNC 0x168003c0 ->msys::MLyt::isEnableAnime (SaveMenu)
//   size 0x4 | file SaveMenu+0x3c0 | callers(3) 0x168018f4 0x16801db8 0x168010ac
// veneer/thunk -> 0x0032bc6c msys::MLyt::isEnableAnime (static)

// FUNC 0x168003c8 ->save_load::MsgWnd::play (SaveMenu)
//   size 0x4 | file SaveMenu+0x3c8 | callers(3) 0x168019f4 0x16801e60 0x16801f44
// veneer/thunk -> 0x16001b9c save_load::MsgWnd::play (SaveLoad)

// FUNC 0x168003d0 ->msys::MLyt::getPane (SaveMenu)
//   size 0x4 | file SaveMenu+0x3d0 | callers(5) 0x16802e64 0x168010ac 0x168019f4 0x16801e60 0x16801f44
// veneer/thunk -> 0x0032c688 msys::MLyt::getPane (static)

// FUNC 0x168003d8 ->MoveC::moveFrm (SaveMenu)
//   size 0x4 | file SaveMenu+0x3d8 | callers(2) 0x16801cc8 0x16801ae0
// veneer/thunk -> 0x0026bc74 MoveC::moveFrm (static)

// FUNC 0x168003e0 ->Backup::init (SaveMenu)
//   size 0x4 | file SaveMenu+0x3e0 | callers(1) 0x16801db8
// veneer/thunk -> 0x00339c54 Backup::init (static)

// FUNC 0x168003e8 ->msys::MPageBase::updateInputAllChr (SaveMenu)
//   size 0x4 | file SaveMenu+0x3e8 | callers(1) 0x168028d4
// veneer/thunk -> 0x00334204 msys::MPageBase::updateInputAllChr (static)

// FUNC 0x168003f0 ->ad::ctrl::ButtonGroup::Update (SaveMenu)
//   size 0x4 | file SaveMenu+0x3f0 | callers(1) 0x168028d4
// veneer/thunk -> 0x00250a40 ad::ctrl::ButtonGroup::Update (static)

// FUNC 0x168003f8 ->ad::fw::Resource::term (SaveMenu)
//   size 0x4 | file SaveMenu+0x3f8 | callers(2) 0x16802070 0x16803798
// veneer/thunk -> 0x00233340 ad::fw::Resource::term (static)

// FUNC 0x16800400 ->save_load::SaveLoadSys::~SaveLoadSys (SaveMenu)
//   size 0x4 | file SaveMenu+0x400 | callers(1) 0x16802070
// veneer/thunk -> 0x16001648 save_load::SaveLoadSys::~SaveLoadSys (SaveLoad)

// FUNC 0x16800408 ->strcmp (SaveMenu)
//   size 0x4 | file SaveMenu+0x408 | callers(1) 0x168021a0
// veneer/thunk -> 0x002833b8 strcmp (static)

// FUNC 0x16800410 ->msys::MCtrlUserData::findExtUserDataByName (SaveMenu)
//   size 0x4 | file SaveMenu+0x410 | callers(1) 0x168021a0
// veneer/thunk -> 0x0036203c msys::MCtrlUserData::findExtUserDataByName (static)

// FUNC 0x16800418 ->msys::MSndSe::play (SaveMenu)
//   size 0x4 | file SaveMenu+0x418 | callers(1) 0x16802438
// veneer/thunk -> 0x0032d844 msys::MSndSe::play (static)

// FUNC 0x16800420 ->MoveVBase::MoveVBase (SaveMenu)
//   size 0x4 | file SaveMenu+0x420 | callers(1) 0x16802634
// veneer/thunk -> 0x00259740 MoveVBase::MoveVBase (static)

// FUNC 0x16800428 ->__aeabi_vec_ctor_nocookie_nodtor (SaveMenu)
//   size 0x4 | file SaveMenu+0x428 | callers(4) 0x16803c9c 0x16803454 0x16802634 0x168031f4
// veneer/thunk -> 0x0028771c __aeabi_vec_ctor_nocookie_nodtor (static)

// FUNC 0x16800430 ->ad::lyt::LytDrawSys::GetInst (SaveMenu)
//   size 0x4 | file SaveMenu+0x430 | callers(1) 0x16802b20
// veneer/thunk -> 0x00287f58 ad::lyt::LytDrawSys::GetInst (static)

// FUNC 0x16800438 ->ad::lyt::Initialize (SaveMenu)
//   size 0x4 | file SaveMenu+0x438 | callers(1) 0x16802b20
// veneer/thunk -> 0x002855e0 ad::lyt::Initialize (static)

// FUNC 0x16800440 ->ad::fw::TaskBase::readLyt (SaveMenu)
//   size 0x4 | file SaveMenu+0x440 | callers(1) 0x16802b20
// veneer/thunk -> 0x00249e48 ad::fw::TaskBase::readLyt (static)

// FUNC 0x16800448 ->save_load::Summary::init (SaveMenu)
//   size 0x4 | file SaveMenu+0x448 | callers(1) 0x16802cd4
// veneer/thunk -> 0x16001cbc save_load::Summary::init (SaveLoad)

// FUNC 0x16800450 ->save_load::SaveDateTime::init (SaveMenu)
//   size 0x4 | file SaveMenu+0x450 | callers(1) 0x16802cd4
// veneer/thunk -> 0x1600187c save_load::SaveDateTime::init (SaveLoad)

// FUNC 0x16800458 ->ad::lyt::LytNumReel3::InitParam::InitParam (SaveMenu)
//   size 0x4 | file SaveMenu+0x458 | callers(1) 0x16802cd4
// veneer/thunk -> 0x00256194 ad::lyt::LytNumReel3::InitParam::InitParam (static)

// FUNC 0x16800460 ->msys::MLytNumRes::set (SaveMenu)
//   size 0x4 | file SaveMenu+0x460 | callers(1) 0x16802cd4
// veneer/thunk -> 0x00207594 msys::MLytNumRes::set (static)

// FUNC 0x16800468 ->msys::MLytNum::init (SaveMenu)
//   size 0x4 | file SaveMenu+0x468 | callers(1) 0x16802cd4
// veneer/thunk -> 0x003316b8 msys::MLytNum::init (static)

// FUNC 0x16800470 ->__aeabi_memcpy4 (SaveMenu)
//   size 0x4 | file SaveMenu+0x470 | callers(1) 0x16802e64
// veneer/thunk -> 0x00286f4c __aeabi_memcpy4 (static)

// FUNC 0x16800478 ->save_load::Summary::build (SaveMenu)
//   size 0x4 | file SaveMenu+0x478 | callers(1) 0x16802e64
// veneer/thunk -> 0x16001ddc save_load::Summary::build (SaveLoad)

// FUNC 0x16800480 ->save_load::SaveDateTime::build (SaveMenu)
//   size 0x4 | file SaveMenu+0x480 | callers(1) 0x16802e64
// veneer/thunk -> 0x16001948 save_load::SaveDateTime::build (SaveLoad)

// FUNC 0x16800488 ->ad::lyt::LytNumReel3::setValueInstant (SaveMenu)
//   size 0x4 | file SaveMenu+0x488 | callers(1) 0x16802e64
// veneer/thunk -> 0x0020785c ad::lyt::LytNumReel3::setValueInstant (static)

// FUNC 0x16800490 ->MessageSimple::term (SaveMenu)
//   size 0x4 | file SaveMenu+0x490 | callers(3) 0x16803168 0x168031b0 0x16803798
// veneer/thunk -> 0x00137090 MessageSimple::term (static)

// FUNC 0x16800498 ->MessageSimple::~MessageSimple (SaveMenu)
//   size 0x4 | file SaveMenu+0x498 | callers(3) 0x16803168 0x168031b0 0x16803798
// veneer/thunk -> 0x00256578 MessageSimple::~MessageSimple (static)

// FUNC 0x168004a0 ->MessageSimple::MessageSimple (SaveMenu)
//   size 0x4 | file SaveMenu+0x4a0 | callers(2) 0x16803454 0x168031f4
// veneer/thunk -> 0x0027ceec MessageSimple::MessageSimple (static)

// FUNC 0x168004a8 ->menu_map::ParamMapPlacePos::ParamMapPlacePos (SaveMenu)
//   size 0x4 | file SaveMenu+0x4a8 | callers(1) 0x16803454
// veneer/thunk -> 0x0033f3e8 menu_map::ParamMapPlacePos::ParamMapPlacePos (static)

// FUNC 0x168004b0 ->Message::Message (SaveMenu)
//   size 0x4 | file SaveMenu+0x4b0 | callers(1) 0x16803454
// veneer/thunk -> 0x00110d5c Message::Message (static)

// FUNC 0x168004b8 ->ad::ctrl::ButtonGroup::ButtonGroup (SaveMenu)
//   size 0x4 | file SaveMenu+0x4b8 | callers(1) 0x16803454
// veneer/thunk -> 0x001667d8 ad::ctrl::ButtonGroup::ButtonGroup (static)

// FUNC 0x168004c0 ->ad::font::ResFont::ResFont (SaveMenu)
//   size 0x4 | file SaveMenu+0x4c0 | callers(1) 0x16803454
// veneer/thunk -> 0x0027542c ad::font::ResFont::ResFont (static)

// FUNC 0x168004c8 ->ad::fw::Resource::Resource (SaveMenu)
//   size 0x4 | file SaveMenu+0x4c8 | callers(1) 0x16803454
// veneer/thunk -> 0x00250588 ad::fw::Resource::Resource (static)

// FUNC 0x168004d0 ->msys::MCursorBase::MCursorBase (SaveMenu)
//   size 0x4 | file SaveMenu+0x4d0 | callers(1) 0x16803454
// veneer/thunk -> 0x00324550 msys::MCursorBase::MCursorBase (static)

// FUNC 0x168004d8 ->msys::MMapIconMan::term (SaveMenu)
//   size 0x4 | file SaveMenu+0x4d8 | callers(1) 0x16803798
// veneer/thunk -> 0x00324a54 msys::MMapIconMan::term (static)

// FUNC 0x168004e0 ->msys::MCursorBase::term (SaveMenu)
//   size 0x4 | file SaveMenu+0x4e0 | callers(1) 0x16803798
// veneer/thunk -> 0x003244f0 msys::MCursorBase::term (static)

// FUNC 0x168004e8 ->msys::MLyt::term (SaveMenu)
//   size 0x4 | file SaveMenu+0x4e8 | callers(1) 0x16803798
// veneer/thunk -> 0x0032c3c8 msys::MLyt::term (static)

// FUNC 0x168004f0 ->ad::ctrl::ButtonGroup::FreeAll (SaveMenu)
//   size 0x4 | file SaveMenu+0x4f0 | callers(1) 0x16803798
// veneer/thunk -> 0x002509d0 ad::ctrl::ButtonGroup::FreeAll (static)

// FUNC 0x168004f8 ->ad::lyt::LytResourceMan::term (SaveMenu)
//   size 0x4 | file SaveMenu+0x4f8 | callers(1) 0x16803798
// veneer/thunk -> 0x00250938 ad::lyt::LytResourceMan::term (static)

// FUNC 0x16800500 ->msys::MCursorBase::~MCursorBase (SaveMenu)
//   size 0x4 | file SaveMenu+0x500 | callers(3) 0x16803798 0x16804354 0x16804364
// veneer/thunk -> 0x00324600 msys::MCursorBase::~MCursorBase (static)

// FUNC 0x16800508 ->ad::fw::Resource::~Resource (SaveMenu)
//   size 0x4 | file SaveMenu+0x508 | callers(1) 0x16803798
// veneer/thunk -> 0x0024a104 ad::fw::Resource::~Resource (static)

// FUNC 0x16800510 ->ad::font::ResFont::~ResFont (SaveMenu)
//   size 0x4 | file SaveMenu+0x510 | callers(1) 0x16803798
// veneer/thunk -> 0x002508a8 ad::font::ResFont::~ResFont (static)

// FUNC 0x16800518 ->ad::ctrl::ButtonGroup::~ButtonGroup (SaveMenu)
//   size 0x4 | file SaveMenu+0x518 | callers(1) 0x16803798
// veneer/thunk -> 0x00250928 ad::ctrl::ButtonGroup::~ButtonGroup (static)

// FUNC 0x16800520 ->msys::MTaskBase::MTaskBase (SaveMenu)
//   size 0x4 | file SaveMenu+0x520 | callers(1) 0x16803c9c
// veneer/thunk -> 0x00334688 msys::MTaskBase::MTaskBase (static)

// FUNC 0x16800528 ->save_load::SaveLoadSys::SaveLoadSys (SaveMenu)
//   size 0x4 | file SaveMenu+0x528 | callers(1) 0x16803c9c
// veneer/thunk -> 0x1600150c save_load::SaveLoadSys::SaveLoadSys (SaveLoad)

// FUNC 0x16800530 ->ad::fw::TaskBase::~TaskBase (SaveMenu)
//   size 0x4 | file SaveMenu+0x530 | callers(2) 0x16803d58 0x16803d80
// veneer/thunk -> 0x0026d590 ad::fw::TaskBase::~TaskBase (static)

// FUNC 0x16800538 ->save_load::SaveLoadSys::funcCalcLoadData (SaveMenu)
//   size 0x4 | file SaveMenu+0x538 | callers(1) 0x16803da4
// veneer/thunk -> 0x16000918 save_load::SaveLoadSys::funcCalcLoadData (SaveLoad)

// FUNC 0x16800540 ->save_load::SaveLoadSys::funcCalcCreateChr (SaveMenu)
//   size 0x4 | file SaveMenu+0x540 | callers(1) 0x16803e18
// veneer/thunk -> 0x16000c58 save_load::SaveLoadSys::funcCalcCreateChr (SaveLoad)

// FUNC 0x16800548 ->msys::MLytNumRes::init (SaveMenu)
//   size 0x4 | file SaveMenu+0x548 | callers(1) 0x16803e18
// veneer/thunk -> 0x003240f4 msys::MLytNumRes::init (static)

// FUNC 0x16800550 ->ad::fw::TaskBase::isReadable (SaveMenu)
//   size 0x4 | file SaveMenu+0x550 | callers(1) 0x16803ea8
// veneer/thunk -> 0x00222f44 ad::fw::TaskBase::isReadable (static)

// FUNC 0x16800558 ->ad::TransMultiSymbol::init (SaveMenu)
//   size 0x4 | file SaveMenu+0x558 | callers(1) 0x16803ea8
// veneer/thunk -> 0x0026d7f8 ad::TransMultiSymbol::init (static)

// FUNC 0x16800560 ->BinGlu4Acs::getEntryAcs (SaveMenu)
//   size 0x4 | file SaveMenu+0x560 | callers(1) 0x16803ea8
// veneer/thunk -> 0x00285268 BinGlu4Acs::getEntryAcs (static)

// FUNC 0x16800568 ->ad::fw::TaskBase::readCA (SaveMenu)
//   size 0x4 | file SaveMenu+0x568 | callers(1) 0x16803ea8
// veneer/thunk -> 0x0026daf8 ad::fw::TaskBase::readCA (static)

// FUNC 0x16800570 ->msys::MComSys::initBaseSys (SaveMenu)
//   size 0x4 | file SaveMenu+0x570 | callers(1) 0x16803fbc
// veneer/thunk -> 0x0032db84 msys::MComSys::initBaseSys (static)

// FUNC 0x16800578 ->msys::MComSys::entryPage (SaveMenu)
//   size 0x4 | file SaveMenu+0x578 | callers(1) 0x16803fbc
// veneer/thunk -> 0x0032f548 msys::MComSys::entryPage (static)

// FUNC 0x16800580 ->Prim::enableDepthTest (SaveMenu)
//   size 0x4 | file SaveMenu+0x580 | callers(1) 0x16803fbc
// veneer/thunk -> 0x0026cce8 Prim::enableDepthTest (static)

// FUNC 0x16800588 ->CtrJobMan::enqueue (SaveMenu)
//   size 0x4 | file SaveMenu+0x588 | callers(1) 0x16803fbc
// veneer/thunk -> 0x0026dbe8 CtrJobMan::enqueue (static)

// FUNC 0x16800590 ->msys::MComSys::setupCamU (SaveMenu)
//   size 0x4 | file SaveMenu+0x590 | callers(1) 0x16803fbc
// veneer/thunk -> 0x0032f674 msys::MComSys::setupCamU (static)

// FUNC 0x16800598 ->msys::MComSys::setupCamL (SaveMenu)
//   size 0x4 | file SaveMenu+0x598 | callers(1) 0x16803fbc
// veneer/thunk -> 0x0032f570 msys::MComSys::setupCamL (static)

// FUNC 0x168005a0 ->ad::fw::FileContext::initSingleFile (SaveMenu)
//   size 0x4 | file SaveMenu+0x5a0 | callers(1) 0x16804278
// veneer/thunk -> 0x0013ad54 ad::fw::FileContext::initSingleFile (static)

// FUNC 0x168005a8 ->ad::fw::FileContext::initArcFile (SaveMenu)
//   size 0x4 | file SaveMenu+0x5a8 | callers(1) 0x16804278
// veneer/thunk -> 0x0013aca8 ad::fw::FileContext::initArcFile (static)

// FUNC 0x168005b0 ->ad::fw::FileContext::initCAArcFile (SaveMenu)
//   size 0x4 | file SaveMenu+0x5b0 | callers(1) 0x16804278
// veneer/thunk -> 0x0013acc0 ad::fw::FileContext::initCAArcFile (static)

// FUNC 0x168005b8 ->msys::MCursorBase::init (SaveMenu)
//   size 0x4 | file SaveMenu+0x5b8 | callers(1) 0x1680432c
// veneer/thunk -> 0x00324464 msys::MCursorBase::init (static)

// FUNC 0x168005c0 SaveMenu::EntryTask (SaveMenu)
//   size 0x34 | file SaveMenu+0x5c0 | callers(0)

void SaveMenu::EntryTask(void)

{
  void *pvVar1;
  Task *pTVar2;
  
  pvVar1 = operator_new(0xfd028,gMemAlc,(char *)0x0,0);
  pTVar2 = (Task *)0x0;
  if (pvVar1 != (void *)0x0) {
    pTVar2 = (Task *)FUN_16803c9c();
  }
  TaskMan::entry((TaskMan *)&gTaskMainMan,pTVar2);
  return;
}


// FUNC 0x16800600 FUN_16800600 (SaveMenu)
//   size 0xc | file SaveMenu+0x600 | callers(0) | datarefs 1

void FUN_16800600(int *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x16800608. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x14))();
  return;
}


// FUNC 0x1680060c save_menu::SaveMenuTask::vfunc_0x1c (SaveMenu)
//   size 0x4 | file SaveMenu+0x60c | callers(0) | datarefs 1

void save_menu::SaveMenuTask::vfunc_0x1c(void)

{
  return;
}


// FUNC 0x16800610 save_menu::SaveMenuTask::vfunc_0x4c (SaveMenu)
//   size 0x8 | file SaveMenu+0x610 | callers(0) | datarefs 1

undefined4 * save_menu::SaveMenuTask::vfunc_0x4c(void)

{
  return &gFrameBuf;
}


// FUNC 0x1680061c save_menu::SaveMenuTask::vfunc_0x3c (SaveMenu)
//   size 0x4 | file SaveMenu+0x61c | callers(0) | datarefs 1

void save_menu::SaveMenuTask::vfunc_0x3c(void)

{
  return;
}


// FUNC 0x16800620 save_menu::SaveMenuTask::vfunc_0x40 (SaveMenu)
//   size 0x4 | file SaveMenu+0x620 | callers(0) | datarefs 1

void save_menu::SaveMenuTask::vfunc_0x40(void)

{
  return;
}


// FUNC 0x16800624 save_menu::SaveMenuTask::vfunc_0x30 (SaveMenu)
//   size 0x4 | file SaveMenu+0x624 | callers(0) | datarefs 1

void save_menu::SaveMenuTask::vfunc_0x30(void)

{
  return;
}


// FUNC 0x16800628 save_menu::SaveMenuTask::vfunc_0x20 (SaveMenu)
//   size 0x4 | file SaveMenu+0x628 | callers(0) | datarefs 1

void save_menu::SaveMenuTask::vfunc_0x20(void)

{
  return;
}


// FUNC 0x1680062c save_menu::SaveMenuTask::vfunc_0x38 (SaveMenu)
//   size 0x4 | file SaveMenu+0x62c | callers(0) | datarefs 1

void save_menu::SaveMenuTask::vfunc_0x38(void)

{
  return;
}


// FUNC 0x16800630 save_menu::SaveMenuTask::vfunc_0x28 (SaveMenu)
//   size 0x4 | file SaveMenu+0x630 | callers(0) | datarefs 1

void save_menu::SaveMenuTask::vfunc_0x28(void)

{
  return;
}


// FUNC 0x168006c0 save_menu::SaveMenuTask::vfunc_0xc (SaveMenu)
//   size 0xc | file SaveMenu+0x6c0 | callers(0) | datarefs 1

void save_menu::SaveMenuTask::vfunc_0xc(int *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x168006c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 8))();
  return;
}


// FUNC 0x168006cc FUN_168006cc (SaveMenu)
//   size 0x30 | file SaveMenu+0x6cc | callers(0) | datarefs 1

int FUN_168006cc(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)FUN_16802634();
  *puVar1 = &msys::MCellAnime::vtable;
  iVar2 = CellAnime::CellAnime((CellAnime *)(puVar1 + 0x53));
  *(undefined1 *)(iVar2 + 300) = 0xff;
  *(undefined1 *)(iVar2 + 0x12d) = 0xff;
  *(undefined1 *)(iVar2 + 0x12e) = 0xff;
  *(undefined1 *)(iVar2 + 0x12f) = 0xff;
  return iVar2 + -0x14c;
}


// FUNC 0x16800720 msys::MChrBase::vfunc_0x10 (SaveMenu)
//   size 0xc | file SaveMenu+0x720 | callers(0) | datarefs 1

void msys::MChrBase::vfunc_0x10(int param_1)

{
  *(undefined1 *)(param_1 + 0x142) = 0;
  return;
}


// FUNC 0x1680072c FUN_1680072c (SaveMenu)
//   size 0x4 | file SaveMenu+0x72c | callers(0) | datarefs 3

void FUN_1680072c(void)

{
  return;
}


// FUNC 0x16800730 msys::MChrBase::vfunc_0x8 (SaveMenu)
//   size 0xc | file SaveMenu+0x730 | callers(0) | datarefs 1

void msys::MChrBase::vfunc_0x8(int param_1)

{
  *(undefined1 *)(param_1 + 0x142) = 1;
  return;
}


// FUNC 0x1680073c FUN_1680073c (SaveMenu)
//   size 0x4 | file SaveMenu+0x73c | callers(0) | datarefs 3

void FUN_1680073c(void)

{
  return;
}


// FUNC 0x16800740 save_menu::SaveMenuPage::Core::InfoPanel::AreaName::vfunc_0x20 (SaveMenu)
//   size 0x8 | file SaveMenu+0x740 | callers(0) | datarefs 1

undefined4 save_menu::SaveMenuPage::Core::InfoPanel::AreaName::vfunc_0x20(void)

{
  return 0;
}


// FUNC 0x16800748 save_menu::SaveMenuPage::Core::InfoPanel::AreaName::vfunc_0x8 (SaveMenu)
//   size 0x5c | file SaveMenu+0x748 | callers(0) | datarefs 1

void save_menu::SaveMenuPage::Core::InfoPanel::AreaName::vfunc_0x8(float param_1,int *param_2)

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


// FUNC 0x168007a4 FUN_168007a4 (SaveMenu)
//   size 0x158 | file SaveMenu+0x7a4 | callers(2) 0x16801768 0x1680304c

void FUN_168007a4(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  
  *(undefined4 *)(param_1 + 0x6c40) = param_3;
  *(undefined4 *)(param_1 + 0x6c34) = param_2;
  *(undefined4 *)(param_1 + 0x6c38) = 0;
  *(undefined4 *)(param_1 + 0x6c3c) = 0;
  MessageSimple::init((MessageSimple *)(param_1 + 0x14c));
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


// FUNC 0x16800914 save_menu::SaveMenuPage::Core::InfoPanel::AreaName::vfunc_0x38 (SaveMenu)
//   size 0x4 | file SaveMenu+0x914 | callers(0) | datarefs 1

void save_menu::SaveMenuPage::Core::InfoPanel::AreaName::vfunc_0x38(void)

{
  return;
}


// FUNC 0x16800918 save_menu::SaveMenuPage::Core::InfoPanel::AreaName::vfunc_0x14 (SaveMenu)
//   size 0x2c | file SaveMenu+0x918 | callers(0) | datarefs 1

void save_menu::SaveMenuPage::Core::InfoPanel::AreaName::vfunc_0x14
               (int param_1,MRenderQueueBase *param_2)

{
  if (*(char *)(param_1 + 0x141) == '\0') {
    return;
  }
  msys::MRenderQueueBase::enqueueMsg
            (param_2,(MessageSimple *)(param_1 + 0x14c),*(uint *)(param_1 + 0x6c40),'\n');
  return;
}


// FUNC 0x16800948 save_menu::SaveMenu::vfunc_0x14 (SaveMenu)
//   size 0x8 | file SaveMenu+0x948 | callers(0) | datarefs 1

undefined4 save_menu::SaveMenu::vfunc_0x14(void)

{
  return 0;
}


// FUNC 0x16800950 save_load::MsgWnd::vfunc_0x20 (SaveMenu)
//   size 0x8 | file SaveMenu+0x950 | callers(0) | datarefs 1

undefined4 save_load::MsgWnd::vfunc_0x20(void)

{
  return 0;
}


// FUNC 0x16800958 save_load::MsgWnd::vfunc_0x8 (SaveMenu)
//   size 0xd0 | file SaveMenu+0x958 | callers(0) | datarefs 1

void save_load::MsgWnd::vfunc_0x8(float param_1,int *param_2)

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


// FUNC 0x16800a30 save_load::MsgWnd::vfunc_0x38 (SaveMenu)
//   size 0x4 | file SaveMenu+0xa30 | callers(0) | datarefs 1

void save_load::MsgWnd::vfunc_0x38(void)

{
  return;
}


// FUNC 0x16800a34 save_load::MsgWnd::vfunc_0x14 (SaveMenu)
//   size 0x2c | file SaveMenu+0xa34 | callers(0) | datarefs 1

void save_load::MsgWnd::vfunc_0x14(int param_1,MRenderQueueBase *param_2)

{
  if (*(char *)(param_1 + 0x141) == '\0') {
    return;
  }
  msys::MRenderQueueBase::enqueueMsg
            (param_2,(MessageSimple *)(param_1 + 0x14c),*(uint *)(param_1 + 0x6ef4),'\n');
  return;
}


// FUNC 0x16800a64 msys::MChrBase::vfunc_0x4 (SaveMenu)
//   size 0x10 | file SaveMenu+0xa64 | callers(0) | datarefs 1

void msys::MChrBase::vfunc_0x4(void)

{
  void *pvVar1;
  
  pvVar1 = (void *)vfunc_0x0();
  operator_delete(pvVar1);
  return;
}


// FUNC 0x16800a74 save_menu::SaveMenuPage::vfunc_0x20 (SaveMenu)
//   size 0x8 | file SaveMenu+0xa74 | callers(0) | datarefs 1

void save_menu::SaveMenuPage::vfunc_0x20
               (MPageBase *param_1,undefined4 param_2,MRenderQueue *param_3)

{
  msys::MPageBase::enqueueLowerChr(param_1,param_3);
  return;
}


// FUNC 0x16800a7c save_menu::SaveMenuPage::vfunc_0x1c (SaveMenu)
//   size 0x8 | file SaveMenu+0xa7c | callers(0) | datarefs 1

void save_menu::SaveMenuPage::vfunc_0x1c
               (MPageBase *param_1,undefined4 param_2,MRenderQueue *param_3)

{
  msys::MPageBase::enqueueUpperChr(param_1,param_3);
  return;
}


// FUNC 0x16800a84 FUN_16800a84 (SaveMenu)
//   size 0x34 | file SaveMenu+0xa84 | callers(0) | datarefs 1

void FUN_16800a84(MoveVBase *param_1)

{
  void *pvVar1;
  
  *(undefined ***)param_1 = &vtable_for_5MoveVILj1EE;
  __aeabi_vec_dtor(param_1 + 0x30,MoveWorkF::~MoveWorkF,0x2c,1);
  pvVar1 = (void *)MoveVBase::~MoveVBase(param_1);
  operator_delete(pvVar1);
  return;
}


// FUNC 0x16800ac0 FUN_16800ac0 (SaveMenu)
//   size 0x30 | file SaveMenu+0xac0 | callers(0) | datarefs 1

void FUN_16800ac0(MoveVBase *param_1)

{
  *(undefined ***)param_1 = &vtable_for_5MoveVILj1EE;
  __aeabi_vec_dtor(param_1 + 0x30,MoveWorkF::~MoveWorkF,0x2c,1);
  MoveVBase::~MoveVBase(param_1);
  return;
}


// FUNC 0x16800af8 FUN_16800af8 (SaveMenu)
//   size 0x2c | file SaveMenu+0xaf8 | callers(0) | datarefs 3

undefined4 * FUN_16800af8(MoveWorkF *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)MoveWorkF::MoveWorkF(param_1);
  *puVar1 = &MoveWorkV::vtable;
  puVar1[8] = 0;
  puVar1[9] = 0;
  puVar1[10] = 0;
  return puVar1;
}


// FUNC 0x16800b2c MoveWorkV::vfunc_0x4 (SaveMenu)
//   size 0x10 | file SaveMenu+0xb2c | callers(0) | datarefs 1

void MoveWorkV::vfunc_0x4(MoveWorkF *param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)MoveWorkF::~MoveWorkF(param_1);
  operator_delete(pvVar1);
  return;
}


// FUNC 0x16800b3c ->MoveWorkF::~MoveWorkF (SaveMenu)
//   size 0x4 | file SaveMenu+0xb3c | callers(0) | datarefs 6
// veneer/thunk -> 0x00340694 MoveWorkF::~MoveWorkF (static)

// FUNC 0x16800b40 save_load::MsgWnd::vfunc_0x4 (SaveMenu)
//   size 0x30 | file SaveMenu+0xb40 | callers(0) | datarefs 1

void save_load::MsgWnd::vfunc_0x4(undefined4 *param_1)

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


// FUNC 0x16800b74 save_load::MsgWnd::vfunc_0x0 (SaveMenu)
//   size 0x2c | file SaveMenu+0xb74 | callers(0) | datarefs 1

void save_load::MsgWnd::vfunc_0x0(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &msys::MMsgWnd::vtable;
  Message::term((Message *)(param_1 + 0x53));
  iVar1 = Message::~Message((Message *)(param_1 + 0x53));
  msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  return;
}


// FUNC 0x16800e08 FUN_16800e08 (SaveMenu)
//   size 0xc8 | file SaveMenu+0xe08 | callers(0) | datarefs 4

void FUN_16800e08(int param_1)

{
  SaveLoadSys *this;
  SaveLoadSys *pSVar1;
  int iVar2;
  code *pcVar3;
  
  if (*(int *)(param_1 + 8) == 0) {
    *(SaveLoadSys **)(param_1 + 8) = msys::MComSys::_sys;
  }
  iVar2 = Backup::errorCode();
  if (iVar2 == 0) {
    if (*(int *)(param_1 + 8) == 0) {
      *(SaveLoadSys **)(param_1 + 8) = msys::MComSys::_sys;
    }
    iVar2 = Backup::isBusyFormat();
    pSVar1 = msys::MComSys::_sys;
    if (iVar2 == 0) {
      this = *(SaveLoadSys **)(param_1 + 8);
      if (*(SaveLoadSys **)(param_1 + 8) == (SaveLoadSys *)0x0) {
        *(SaveLoadSys **)(param_1 + 8) = msys::MComSys::_sys;
        this = pSVar1;
      }
      iVar2 = save_load::SaveLoadSys::saveWriteInitData(this);
      if (iVar2 == 0) {
        pcVar3 = FUN_16801e60;
      }
      else {
        pcVar3 = FUN_16800f7c;
      }
      *(code **)(param_1 + 0x1dac0) = pcVar3;
      *(undefined4 *)(param_1 + 0x1dac4) = 0;
    }
  }
  else {
    if ((iVar2 - 0x2001U < 2) || (iVar2 - 0x2001U == 2)) {
      if (*(int *)(param_1 + 8) == 0) {
        *(SaveLoadSys **)(param_1 + 8) = msys::MComSys::_sys;
      }
      save_load::SaveLoadSys::saveFormat();
      return;
    }
    *(code **)(param_1 + 0x1dac0) = FUN_16801e60;
    *(undefined4 *)(param_1 + 0x1dac4) = 0;
  }
  return;
}


// FUNC 0x16800efc FUN_16800efc (SaveMenu)
//   size 0x58 | file SaveMenu+0xefc | callers(0)

void FUN_16800efc(int param_1)

{
  GameWorkPOD *pGVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 8) == 0) {
    *(undefined4 *)(param_1 + 8) = msys::MComSys::_sys;
  }
  pGVar1 = (GameWorkPOD *)Backup::GetSaveData1(-1);
  iVar2 = msys::MLyt::getParts((MLyt *)(param_1 + 0x1db9c),"MAP_ALL",(char *)0x0,(char *)0x0);
  msys::MMapIconMan::setUp((MMapIconMan *)(param_1 + 0xc),*(Layout **)(iVar2 + 0xac),pGVar1);
  return;
}


// FUNC 0x16800f7c FUN_16800f7c (SaveMenu)
//   size 0xdc | file SaveMenu+0xf7c | callers(0) | datarefs 2

void FUN_16800f7c(int param_1)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  iVar1 = Backup::errorCode();
  iVar3 = msys::MComSys::_sys;
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar1 = iVar3;
    }
    iVar3 = Backup::isBusyWriting((Backup *)(iVar1 + 0xe9050));
    if (iVar3 == 0) {
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
      }
      GameWork::preSaveGameWork((GameWork *)&gGameWork);
      Backup::writeSaveData();
      *(code **)(param_1 + 0x1dac0) = FUN_168010ac;
      *(undefined4 *)(param_1 + 0x1dac4) = 0;
    }
    return;
  }
  if ((iVar1 - 0x2001U < 2) || (iVar1 - 0x2001U == 2)) {
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
    }
    save_load::SaveLoadSys::saveFormat();
    pcVar2 = FUN_16800e08;
  }
  else {
    pcVar2 = FUN_16801e60;
  }
  *(code **)(param_1 + 0x1dac0) = pcVar2;
  *(undefined4 *)(param_1 + 0x1dac4) = 0;
  return;
}


// FUNC 0x16801064 FUN_16801064 (SaveMenu)
//   size 0x44 | file SaveMenu+0x1064 | callers(0) | datarefs 2

void FUN_16801064(int param_1)

{
  int iVar1;
  int iVar2;
  
  SndSys::StopAll();
  SndSys::RebuildSeHeap(0x380000,0,0);
  iVar1 = msys::MComSys::_sys;
  iVar2 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar2 = iVar1;
  }
  GameMain::Start(0xc,*(undefined4 *)(iVar2 + 4));
  return;
}


// FUNC 0x168010ac FUN_168010ac (SaveMenu)
//   size 0x254 | file SaveMenu+0x10ac | callers(0) | datarefs 4

void FUN_168010ac(int param_1)

{
  SaveLoadSys *pSVar1;
  SaveLoadSys *pSVar2;
  int iVar3;
  code *pcVar4;
  GameWorkPOD *pGVar5;
  
  if (*(int *)(param_1 + 8) == 0) {
    *(SaveLoadSys **)(param_1 + 8) = msys::MComSys::_sys;
  }
  iVar3 = Backup::errorCode();
  pSVar2 = msys::MComSys::_sys;
  if (iVar3 == 0) {
    pSVar1 = *(SaveLoadSys **)(param_1 + 8);
    if (*(SaveLoadSys **)(param_1 + 8) == (SaveLoadSys *)0x0) {
      *(SaveLoadSys **)(param_1 + 8) = msys::MComSys::_sys;
      pSVar1 = pSVar2;
    }
    iVar3 = save_load::SaveLoadSys::saveIsBusyWriting(pSVar1);
    if (iVar3 == 0) {
      if (*(int *)(param_1 + 8) == 0) {
        *(SaveLoadSys **)(param_1 + 8) = msys::MComSys::_sys;
      }
      pGVar5 = (GameWorkPOD *)Backup::GetSaveData1(-1);
      iVar3 = msys::MLyt::getParts((MLyt *)(param_1 + 0x1db9c),"MAP_ALL",(char *)0x0,(char *)0x0);
      msys::MMapIconMan::setUp((MMapIconMan *)(param_1 + 0xc),*(Layout **)(iVar3 + 0xac),pGVar5);
      FUN_16802e64(param_1 + 0xafc);
      if (*(int *)(param_1 + 8) == 0) {
        *(SaveLoadSys **)(param_1 + 8) = msys::MComSys::_sys;
      }
      pGVar5 = (GameWorkPOD *)Backup::GetSaveData1(-1);
      save_load::FilePanel::build((FilePanel *)(param_1 + 0xf124),pGVar5);
      msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x1df44),2,1,(char *)0x0,(char *)0x0);
      FUN_16802438(param_1,0x11003b,0,0,0);
      Message::close((Message *)(param_1 + 0x10084));
      *(undefined4 *)(param_1 + 0x1dac0) = 0x16802778;
      *(undefined4 *)(param_1 + 0x1dac4) = 0;
      iVar3 = msys::MLyt::isEnableAnime((MLyt *)(param_1 + 0x1df44));
      if (iVar3 == 0) {
        *(undefined1 *)(param_1 + 0x1e304) = 0;
        *(undefined1 *)(param_1 + 0x1e305) = 0xff;
        msys::MCursorBase::setVisible((MCursorBase *)(param_1 + 0x1e2ec),true);
        FUN_168021a0((MCursorBase *)(param_1 + 0x1e2ec));
        (**(code **)(**(int **)(param_1 + 0x1e328) + 0x28))(*(int **)(param_1 + 0x1e328),1);
        (**(code **)(**(int **)(param_1 + 0x1e32c) + 0x28))(*(int **)(param_1 + 0x1e32c),1);
        iVar3 = msys::MLyt::getPane((MLyt *)(param_1 + 0x1df44),"CHECK_pnl",(char *)0x0,(char *)0x0)
        ;
        *(byte *)(iVar3 + 0x44) = *(byte *)(iVar3 + 0x44) & 0xfe | 1;
        pSVar1 = msys::MComSys::_sys;
        pSVar2 = *(SaveLoadSys **)(param_1 + 8);
        if (*(SaveLoadSys **)(param_1 + 8) == (SaveLoadSys *)0x0) {
          *(SaveLoadSys **)(param_1 + 8) = msys::MComSys::_sys;
          pSVar2 = pSVar1;
        }
        pSVar2[0xe6508] = (SaveLoadSys)0x1;
        pSVar1 = msys::MComSys::_sys;
        pSVar2 = *(SaveLoadSys **)(param_1 + 8);
        if (*(SaveLoadSys **)(param_1 + 8) == (SaveLoadSys *)0x0) {
          *(SaveLoadSys **)(param_1 + 8) = msys::MComSys::_sys;
          pSVar2 = pSVar1;
        }
        pSVar2[0xe650a] = (SaveLoadSys)0x1;
        *(code **)(param_1 + 0x1dac0) = FUN_16801bd0;
        *(undefined4 *)(param_1 + 0x1dac4) = 0;
      }
      return;
    }
  }
  else {
    if ((iVar3 - 0x2001U < 2) || (iVar3 - 0x2001U == 2)) {
      pcVar4 = FUN_168019f4;
    }
    else {
      pcVar4 = FUN_16801e60;
    }
    *(code **)(param_1 + 0x1dac0) = pcVar4;
    *(undefined4 *)(param_1 + 0x1dac4) = 0;
  }
  return;
}


// FUNC 0x16801884 FUN_16801884 (SaveMenu)
//   size 0x6c | file SaveMenu+0x1884 | callers(0) | datarefs 2

void FUN_16801884(int param_1)

{
  int *piVar1;
  int iVar2;
  
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x1df44),1,1,(char *)0x0,(char *)0x0);
  iVar2 = 0;
  do {
    piVar1 = *(int **)(param_1 + iVar2 * 4 + 0x1e328);
    (**(code **)(*piVar1 + 0x28))(piVar1,0);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 4);
  *(code **)(param_1 + 0x1dac0) = FUN_16801db8;
  *(undefined4 *)(param_1 + 0x1dac4) = 0;
  return;
}


// FUNC 0x168018f4 FUN_168018f4 (SaveMenu)
//   size 0xdc | file SaveMenu+0x18f4 | callers(0) | datarefs 2

void FUN_168018f4(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = msys::MLyt::isEnableAnime((MLyt *)(param_1 + 0x1db9c));
  if ((iVar2 == 0) && (iVar2 = msys::MLyt::isEnableAnime((MLyt *)(param_1 + 0x1df44)), iVar2 == 0))
  {
    *(undefined1 *)(param_1 + 0x1e304) = 2;
    *(undefined1 *)(param_1 + 0x1e305) = 0xff;
    msys::MCursorBase::setVisible((MCursorBase *)(param_1 + 0x1e2ec),true);
    FUN_168021a0((MCursorBase *)(param_1 + 0x1e2ec));
    (**(code **)(**(int **)(param_1 + 0x1e334) + 0x28))(*(int **)(param_1 + 0x1e334),1);
    (**(code **)(**(int **)(param_1 + 0x1e330) + 0x28))(*(int **)(param_1 + 0x1e330),1);
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
    *(code **)(param_1 + 0x1dac0) = FUN_16802c04;
    *(undefined4 *)(param_1 + 0x1dac4) = 0;
  }
  return;
}


// FUNC 0x168019f4 FUN_168019f4 (SaveMenu)
//   size 0xc4 | file SaveMenu+0x19f4 | callers(0) | datarefs 2

void FUN_168019f4(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  save_load::MsgWnd::play((MsgWnd *)(param_1 + 0xff38),"menu_save_err_01",(InsParam *)0x0);
  iVar1 = msys::MLyt::getPane((MLyt *)(param_1 + 0x1df44),"CHECK_pnl",(char *)0x0,(char *)0x0);
  iVar3 = 0;
  *(byte *)(iVar1 + 0x44) = *(byte *)(iVar1 + 0x44) & 0xfe;
  do {
    piVar2 = *(int **)(param_1 + iVar3 * 4 + 0x1e328);
    (**(code **)(*piVar2 + 0x28))(piVar2,0);
    iVar1 = msys::MComSys::_sys;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 4);
  iVar3 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar3 = iVar1;
  }
  *(undefined1 *)(iVar3 + 0xe6508) = 0;
  iVar3 = msys::MComSys::_sys;
  iVar1 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar1 = iVar3;
  }
  *(undefined1 *)(iVar1 + 0xe650a) = 1;
  *(code **)(param_1 + 0x1dac0) = FUN_16801f44;
  *(undefined4 *)(param_1 + 0x1dac4) = 0;
  return;
}


// FUNC 0x16801ae0 FUN_16801ae0 (SaveMenu)
//   size 0xd8 | file SaveMenu+0x1ae0 | callers(0) | datarefs 2

void FUN_16801ae0(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 local_1c;
  
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x1db9c),0,0,(char *)0x0,(char *)0x0);
  if (*(short *)(*(int *)(param_1 + 0x1e2cc) + 8) == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = 2;
  }
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x1df44),uVar3,0,(char *)0x0,(char *)0x0);
  iVar1 = msys::MComSys::_sys;
  iVar2 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar2 = iVar1;
  }
  local_1c = 0xff000000;
  MoveC::moveFrm((MoveC *)(iVar2 + 0x4acd4),(Color8 *)&local_1c,16.0);
  MoveC::moveFrm((MoveC *)(iVar2 + 0x4ad14),(Color8 *)&local_1c,16.0);
  *(undefined1 **)(param_1 + 0x1dac0) = &LAB_16802720;
  *(undefined4 *)(param_1 + 0x1dac4) = 0;
  return;
}


// FUNC 0x16801bd0 FUN_16801bd0 (SaveMenu)
//   size 0xc0 | file SaveMenu+0x1bd0 | callers(0) | datarefs 2

void FUN_16801bd0(int param_1,uint *param_2)

{
  int iVar1;
  int iVar2;
  
  if ((*param_2 & 0x401) == 0) {
    if ((*param_2 & 0xc0) != 0) {
      FUN_16802438(param_1,0x110015,0,0,0);
      *(bool *)(param_1 + 0x1e304) = *(char *)(param_1 + 0x1e304) == '\0';
    }
  }
  else {
    (**(code **)(**(int **)(param_1 + *(char *)(param_1 + 0x1e304) * 4 + 0x1e328) + 0x10))();
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
  FUN_168021a0(param_1 + 0x1e2ec);
  return;
}


// FUNC 0x16801cc8 FUN_16801cc8 (SaveMenu)
//   size 0xd8 | file SaveMenu+0x1cc8 | callers(0) | datarefs 2

void FUN_16801cc8(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 local_1c;
  
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x1db9c),0,0,(char *)0x0,(char *)0x0);
  if (*(short *)(*(int *)(param_1 + 0x1e2cc) + 8) == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = 2;
  }
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x1df44),uVar3,0,(char *)0x0,(char *)0x0);
  iVar1 = msys::MComSys::_sys;
  iVar2 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar2 = iVar1;
  }
  local_1c = 0xff000000;
  MoveC::moveFrm((MoveC *)(iVar2 + 0x4acd4),(Color8 *)&local_1c,16.0);
  MoveC::moveFrm((MoveC *)(iVar2 + 0x4ad14),(Color8 *)&local_1c,16.0);
  *(undefined1 **)(param_1 + 0x1dac0) = &LAB_1680287c;
  *(undefined4 *)(param_1 + 0x1dac4) = 0;
  return;
}


// FUNC 0x16801db8 FUN_16801db8 (SaveMenu)
//   size 0x98 | file SaveMenu+0x1db8 | callers(0) | datarefs 2

void FUN_16801db8(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = msys::MLyt::isEnableAnime((MLyt *)(param_1 + 0x1df44));
  iVar1 = msys::MComSys::_sys;
  if (iVar2 == 0) {
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar1;
    }
    Backup::init((Backup *)(iVar2 + 0xe9050),(CtrFS *)(*(int *)(iVar2 + 4) + 0x518));
    DAT_003fbea0 = DAT_003fbea0 & 0xfe;
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
    }
    GameWork::preSaveGameWork((GameWork *)&gGameWork);
    Backup::writeSaveData();
    *(code **)(param_1 + 0x1dac0) = FUN_168010ac;
    *(undefined4 *)(param_1 + 0x1dac4) = 0;
  }
  return;
}


// FUNC 0x16801e60 FUN_16801e60 (SaveMenu)
//   size 0xc4 | file SaveMenu+0x1e60 | callers(0) | datarefs 8

void FUN_16801e60(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  save_load::MsgWnd::play((MsgWnd *)(param_1 + 0xff38),"menu_save_err_03",(InsParam *)0x0);
  iVar1 = msys::MLyt::getPane((MLyt *)(param_1 + 0x1df44),"CHECK_pnl",(char *)0x0,(char *)0x0);
  iVar3 = 0;
  *(byte *)(iVar1 + 0x44) = *(byte *)(iVar1 + 0x44) & 0xfe;
  do {
    piVar2 = *(int **)(param_1 + iVar3 * 4 + 0x1e328);
    (**(code **)(*piVar2 + 0x28))(piVar2,0);
    iVar1 = msys::MComSys::_sys;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 4);
  iVar3 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar3 = iVar1;
  }
  *(undefined1 *)(iVar3 + 0xe6508) = 0;
  iVar3 = msys::MComSys::_sys;
  iVar1 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar1 = iVar3;
  }
  *(undefined1 *)(iVar1 + 0xe650a) = 1;
  *(undefined **)(param_1 + 0x1dac0) = &DAT_16801cc4;
  *(undefined4 *)(param_1 + 0x1dac4) = 0;
  return;
}


// FUNC 0x16801f44 FUN_16801f44 (SaveMenu)
//   size 0x108 | file SaveMenu+0x1f44 | callers(0) | datarefs 2

void FUN_16801f44(int param_1)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  if (*(int *)(param_1 + 0x16b80) == 0) {
    if (*(int *)(param_1 + 0x16e6c) == 0) {
      save_load::MsgWnd::play((MsgWnd *)(param_1 + 0xff38),"menu_save_err_03",(InsParam *)0x0);
      iVar2 = msys::MLyt::getPane((MLyt *)(param_1 + 0x1df44),"CHECK_pnl",(char *)0x0,(char *)0x0);
      iVar4 = 0;
      *(byte *)(iVar2 + 0x44) = *(byte *)(iVar2 + 0x44) & 0xfe;
      do {
        piVar3 = *(int **)(param_1 + iVar4 * 4 + 0x1e328);
        (**(code **)(*piVar3 + 0x28))(piVar3,0);
        iVar2 = msys::MComSys::_sys;
        iVar4 = iVar4 + 1;
      } while (iVar4 < 4);
      iVar4 = *(int *)(param_1 + 8);
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar4 = iVar2;
      }
      *(undefined1 *)(iVar4 + 0xe6508) = 0;
      iVar4 = msys::MComSys::_sys;
      iVar2 = *(int *)(param_1 + 8);
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar2 = iVar4;
      }
      *(undefined1 *)(iVar2 + 0xe650a) = 1;
      pcVar1 = (code *)&DAT_16801cc4;
    }
    else {
      save_load::MsgWnd::play((MsgWnd *)(param_1 + 0xff38),"menu_save_err_02",(InsParam *)0x0);
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
      }
      save_load::SaveLoadSys::saveFormat();
      pcVar1 = FUN_16800e08;
    }
    *(code **)(param_1 + 0x1dac0) = pcVar1;
    *(undefined4 *)(param_1 + 0x1dac4) = 0;
  }
  return;
}


// FUNC 0x16802070 save_menu::SaveMenu::vfunc_0x0 (SaveMenu)
//   size 0x118 | file SaveMenu+0x2070 | callers(3) 0x16803d58 0x16803d80 0x1680414c | datarefs 1

void save_menu::SaveMenu::vfunc_0x0(SaveLoadSys *param_1)

{
  SaveLoadSys *pSVar1;
  undefined4 *puVar2;
  SaveLoadSys *pSVar3;
  int iVar4;
  SaveLoadSys *pSVar5;
  
  iVar4 = 0;
  *(undefined ***)param_1 = &vtable;
  do {
    ad::fw::Resource::term((Resource *)(param_1 + iVar4 * 0x44 + 0xfca10));
    iVar4 = iVar4 + 1;
  } while (iVar4 < 2);
  __aeabi_vec_dtor(param_1 + 0xfca10,ad::fw::Resource::~Resource,0x44,2);
  *(undefined ***)(param_1 + 0xfc9ec) = &SaveMenuPage::vtable;
  if (*(int **)(param_1 + 0xfca0c) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0xfca0c) + 4))();
  }
  *(undefined4 *)(param_1 + 0xfca0c) = 0;
  *(undefined ***)(param_1 + 0xfc9ec) = &msys::MPageBase::vtable;
  pSVar5 = param_1 + 0xfc9f8;
  pSVar1 = *(SaveLoadSys **)(param_1 + 0xfc9fc);
  while (pSVar1 != pSVar5) {
    pSVar3 = *(SaveLoadSys **)(pSVar1 + 4);
    *(SaveLoadSys **)(pSVar1 + 4) = pSVar1;
    *(SaveLoadSys **)pSVar1 = pSVar1;
    pSVar1 = pSVar3;
  }
  *(SaveLoadSys **)(param_1 + 0xfc9fc) = pSVar5;
  *(SaveLoadSys **)pSVar5 = pSVar5;
  puVar2 = *(undefined4 **)(param_1 + 0xfc9fc);
  *(undefined4 **)(param_1 + 0xfc9fc) = puVar2;
  *puVar2 = *(undefined4 *)(param_1 + 0xfc9f8);
  pSVar5 = param_1 + 0xfc9f0;
  pSVar1 = *(SaveLoadSys **)(param_1 + 0xfc9f4);
  while (pSVar1 != pSVar5) {
    pSVar3 = *(SaveLoadSys **)(pSVar1 + 4);
    *(SaveLoadSys **)(pSVar1 + 4) = pSVar1;
    *(SaveLoadSys **)pSVar1 = pSVar1;
    pSVar1 = pSVar3;
  }
  *(SaveLoadSys **)(param_1 + 0xfc9f4) = pSVar5;
  *(SaveLoadSys **)pSVar5 = pSVar5;
  puVar2 = *(undefined4 **)(param_1 + 0xfc9f4);
  *(undefined4 **)(*(int *)pSVar5 + 4) = puVar2;
  *puVar2 = *(undefined4 *)pSVar5;
  save_load::SaveLoadSys::~SaveLoadSys(param_1);
  return;
}


// FUNC 0x168021a0 FUN_168021a0 (SaveMenu)
//   size 0x280 | file SaveMenu+0x21a0 | callers(4) 0x16802c04 0x168018f4 0x168010ac 0x16801bd0

void FUN_168021a0(int param_1)

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


// FUNC 0x16802438 FUN_16802438 (SaveMenu)
//   size 0x9c | file SaveMenu+0x2438 | callers(3) 0x168029c4 0x168010ac 0x16801bd0

MSndSe * FUN_16802438(undefined4 param_1,uint param_2,MChrBase *param_3,VEC2 *param_4,bool param_5)

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


// FUNC 0x168024d8 msys::MChrBase::vfunc_0x0 (SaveMenu)
//   size 0x14c | file SaveMenu+0x24d8 | callers(8) 0x16800a64 0x16800b40 0x16800b74 0x16803168 0x168031b0 0x16803798 0x16800714 0x16800c00 | datarefs 1

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


// FUNC 0x16802634 FUN_16802634 (SaveMenu)
//   size 0xdc | file SaveMenu+0x2634 | callers(4) 0x16803454 0x168031f4 0x168006cc 0x16800bb4

void FUN_16802634(undefined4 *param_1)

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
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(puVar1 + 0xc,FUN_16800af8,0x2c,1);
  *(int *)(iVar2 + -8) = iVar2;
  *(undefined1 *)(iVar2 + -4) = 1;
  puVar1 = (undefined4 *)MoveVBase::MoveVBase((MoveVBase *)(iVar2 + 0x2c));
  *puVar1 = &vtable_for_5MoveVILj1EE;
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(puVar1 + 0xc,FUN_16800af8,0x2c,1);
  *(int *)(iVar2 + -8) = iVar2;
  *(undefined1 *)(iVar2 + -4) = 1;
  puVar1 = (undefined4 *)MoveVBase::MoveVBase((MoveVBase *)(iVar2 + 0x2c));
  *puVar1 = &vtable_for_5MoveVILj1EE;
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(puVar1 + 0xc,FUN_16800af8,0x2c,1);
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


// FUNC 0x168028d4 save_menu::SaveMenuPage::Core::vfunc_0x8 (SaveMenu)
//   size 0xe0 | file SaveMenu+0x28d4 | callers(0) | datarefs 1

undefined4 save_menu::SaveMenuPage::Core::vfunc_0x8(int *param_1,MInput *param_2)

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
  undefined4 local_18;
  undefined4 uStack_14;
  
  msys::MPageBase::updateInputAllChr((MPageBase *)param_1[1],param_2);
  bVar7 = (param_1[0x76b1] & 1U) == 0;
  pcVar5 = extraout_r2;
  if (bVar7) {
    pcVar5 = (code *)param_1[0x76b0];
  }
  piVar3 = (int *)((int)param_1 + (param_1[0x76b1] >> 1));
  if (!bVar7) {
    pcVar5 = *(code **)(*piVar3 + param_1[0x76b0]);
  }
  (*pcVar5)(piVar3,param_2);
  MVar1 = param_2[0x11];
  bVar7 = MVar1 == (MInput)0x0;
  if (bVar7) {
    MVar1 = param_2[0x12];
  }
  pVVar6 = (VEC2 *)0x0;
  if (!bVar7 || MVar1 != (MInput)0x0) {
    uStack_14 = VectorSignedToFloat(0x78 - (uint)*(ushort *)(param_2 + 0x16),
                                    (byte)(in_fpscr >> 0x16) & 3);
    local_18 = VectorSignedToFloat(*(ushort *)(param_2 + 0x14) - 0xa0,(byte)(in_fpscr >> 0x16) & 3);
    pVVar6 = (VEC2 *)&local_18;
  }
  bVar7 = (bool)(**(code **)(*param_1 + 0xc))(param_1,param_2);
  iVar2 = msys::MComSys::_sys;
  iVar4 = param_1[2];
  if (param_1[2] == 0) {
    param_1[2] = msys::MComSys::_sys;
    iVar4 = iVar2;
  }
  ad::ctrl::ButtonGroup::Update
            ((ButtonGroup *)(param_1 + 0x76b2),pVVar6,(bool)(*(byte *)(iVar4 + 0xe6508) & bVar7),
             bVar7);
  return 0xffffffff;
}


// FUNC 0x168029c4 FUN_168029c4 (SaveMenu)
//   size 0x144 | file SaveMenu+0x29c4 | callers(0)

void FUN_168029c4(int param_1,int param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  code *pcVar5;
  undefined4 uVar6;
  MCursorBase *this;
  
  bVar1 = *(byte *)(param_2 + 0x48);
  uVar4 = (uint)bVar1;
  this = (MCursorBase *)(param_1 + 0x1e2ec);
  if (param_3 != 1) {
    if (param_3 != 4) {
      if (param_3 != 5) {
        return;
      }
      if (uVar4 == 0) {
        msys::MCursorBase::setVisible(this,false);
LAB_16802afc:
        *(code **)(param_1 + 0x1dac0) = FUN_16801ae0;
        *(undefined4 *)(param_1 + 0x1dac4) = 0;
        return;
      }
      if (uVar4 == 1) {
        msys::MCursorBase::setVisible(this,false);
        pcVar5 = FUN_16801cc8;
      }
      else {
        if (uVar4 != 2) {
          if (uVar4 != 3) {
            return;
          }
          goto LAB_16802afc;
        }
        msys::MCursorBase::setVisible(this,false);
        pcVar5 = FUN_16801884;
      }
      *(code **)(param_1 + 0x1dac0) = pcVar5;
      *(undefined4 *)(param_1 + 0x1dac4) = 0;
      return;
    }
    if (uVar4 == 3) {
      uVar6 = 0x110017;
    }
    else {
      uVar6 = 0x110016;
    }
    FUN_16802438(param_1,uVar6,0,0,0);
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
  if ((uVar4 < 2) && ((int)*(char *)(param_1 + 0x1e304) != uVar4)) {
    FUN_16802438(param_1,0x110015,0,0,0);
    *(byte *)(param_1 + 0x1e304) = bVar1;
    return;
  }
  return;
}


// FUNC 0x16802b20 FUN_16802b20 (SaveMenu)
//   size 0xc4 | file SaveMenu+0x2b20 | callers(0) | datarefs 1

void FUN_16802b20(int param_1)

{
  int iVar1;
  IAllocator *pIVar2;
  MemAlcBase *pMVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar1 = ad::lyt::LytDrawSys::GetInst();
  uVar5 = *(undefined4 *)(*(int *)(param_1 + 4) + 0x18);
  pIVar2 = (IAllocator *)(iVar1 + 0x5f4);
  if (ad::lyt::Layout::s_pAllocator != pIVar2) {
    ad::lyt::Initialize(pIVar2,pIVar2);
  }
  *(undefined4 *)(iVar1 + 0x5f8) = uVar5;
  iVar1 = ad::lyt::LytDrawSys::GetInst();
  *(undefined4 *)(iVar1 + 0x5fc) = 0x10000;
  iVar4 = msys::MComSys::_sys;
  pMVar3 = *(MemAlcBase **)(*(int *)(param_1 + 4) + 0x18);
  iVar1 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar1 = iVar4;
  }
  iVar4 = msys::MComSys::_sys;
  if (iVar1 == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  else {
    iVar4 = iVar1;
  }
  ad::fw::TaskBase::readLyt
            (*(TaskBase **)(iVar4 + 4),(Resource *)(param_1 + 0x1db58),
             (FileContext *)(*(int *)(iVar1 + 0x278) + 0xa8),"?MENU_FILE_SAVE",pMVar3,0x7f,
             (ResCacheArg *)0x0);
  *(undefined1 **)(param_1 + 0x1dab8) = &LAB_16800f60;
  *(undefined4 *)(param_1 + 0x1dabc) = 0;
  return;
}


// FUNC 0x16802c04 FUN_16802c04 (SaveMenu)
//   size 0xc4 | file SaveMenu+0x2c04 | callers(0) | datarefs 2

void FUN_16802c04(int param_1,uint *param_2)

{
  int iVar1;
  int iVar2;
  
  if ((*param_2 & 0x802) == 0) {
    if ((*param_2 & 0x401) == 0) goto LAB_16802cb8;
    (**(code **)(**(int **)(param_1 + 0x1e330) + 0x10))();
    iVar1 = msys::MComSys::_sys;
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar1;
    }
    *(undefined1 *)(iVar2 + 0xe6508) = 0;
    iVar2 = *(int *)(param_1 + 8);
  }
  else {
    (**(code **)(**(int **)(param_1 + 0x1e334) + 0x10))();
    iVar1 = msys::MComSys::_sys;
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar1;
    }
    *(undefined1 *)(iVar2 + 0xe6508) = 0;
    iVar2 = *(int *)(param_1 + 8);
  }
  iVar1 = msys::MComSys::_sys;
  if (iVar2 == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar2 = iVar1;
  }
  *(undefined1 *)(iVar2 + 0xe650a) = 1;
LAB_16802cb8:
  FUN_168021a0(param_1 + 0x1e2ec);
  return;
}


// FUNC 0x16802cd4 FUN_16802cd4 (SaveMenu)
//   size 0x158 | file SaveMenu+0x2cd4 | callers(1) 0x168013c8

void FUN_16802cd4(int *param_1)

{
  SaveLoadSys *pSVar1;
  SaveLoadSys *pSVar2;
  InitParam aIStack_58 [72];
  
  FUN_1680304c(param_1 + 1,*param_1);
  save_load::Summary::init
            ((Summary *)(param_1 + 0x1b1a),*(MemAlcBase **)(*(int *)(*param_1 + 4) + 0x18),
             *(Layout **)(*param_1 + 0x1dcec),(char **)&DAT_16809abc);
  msys::MLyt::attachMChr
            ((MLyt *)(*param_1 + 0x1db9c),(MChrBase *)(param_1 + 0x1b1a),"INS_SUMMARY",(char *)0x0,
             (char *)0x0,(char *)0x0);
  pSVar1 = msys::MComSys::_sys;
  pSVar2 = *(SaveLoadSys **)(*param_1 + 8);
  if (pSVar2 == (SaveLoadSys *)0x0) {
    *(SaveLoadSys **)(*param_1 + 8) = msys::MComSys::_sys;
    pSVar2 = pSVar1;
  }
  save_load::SaveDateTime::init
            ((SaveDateTime *)(param_1 + 0x3642),pSVar2,(MLyt *)(*param_1 + 0x1df44),"DATE",
             (char *)0x0);
  ad::lyt::LytNumReel3::InitParam::InitParam(aIStack_58);
  pSVar1 = msys::MComSys::_sys;
  pSVar2 = *(SaveLoadSys **)(*param_1 + 8);
  if (pSVar2 == (SaveLoadSys *)0x0) {
    *(SaveLoadSys **)(*param_1 + 8) = msys::MComSys::_sys;
    pSVar2 = pSVar1;
  }
  msys::MLytNumRes::set((MLytNumRes *)(pSVar2 + 0x844),aIStack_58,0,2,0x11);
  pSVar1 = msys::MComSys::_sys;
  pSVar2 = *(SaveLoadSys **)(*param_1 + 8);
  if (pSVar2 == (SaveLoadSys *)0x0) {
    *(SaveLoadSys **)(*param_1 + 8) = msys::MComSys::_sys;
    pSVar2 = pSVar1;
  }
  msys::MLytNum::init((MLytNum *)(param_1 + 0x38fe),aIStack_58,(LytDrawData *)(pSVar2 + 0xd3000),
                      (MLyt *)(*param_1 + 0x1db9c),"INS_COUNT","COIN_all",(char *)0x0,(char *)0x0);
  msys::MLyt::attachMChr
            ((MLyt *)(*param_1 + 0x1db9c),(MChrBase *)(param_1 + 0x38fe),"INS_COUNT","COIN_all",
             (char *)0x0,(char *)0x0);
  return;
}


// FUNC 0x16802e64 FUN_16802e64 (SaveMenu)
//   size 0x1c8 | file SaveMenu+0x2e64 | callers(2) 0x168013d4 0x168010ac

void FUN_16802e64(int *param_1)

{
  GameWorkPOD GVar1;
  SaveLoadSys *pSVar2;
  GameWorkPOD *pGVar3;
  int iVar4;
  undefined4 uVar5;
  SaveLoadSys *pSVar6;
  undefined4 auStack_140 [36];
  float afStack_b0 [36];
  
  if (*(int *)(*param_1 + 8) == 0) {
    *(SaveLoadSys **)(*param_1 + 8) = msys::MComSys::_sys;
  }
  pGVar3 = (GameWorkPOD *)Backup::GetSaveData1(-1);
  if (((byte)pGVar3[0x28b0] & 1) != 0) {
    iVar4 = msys::MLyt::getPane((MLyt *)(*param_1 + 0x1db9c),"LOW",(char *)0x0,(char *)0x0);
    *(byte *)(iVar4 + 0x44) = *(byte *)(iVar4 + 0x44) & 0xfe;
    iVar4 = msys::MLyt::getPane((MLyt *)(*param_1 + 0x1df44),"DATE",(char *)0x0,(char *)0x0);
    *(byte *)(iVar4 + 0x44) = *(byte *)(iVar4 + 0x44) & 0xfe;
    return;
  }
  iVar4 = msys::MLyt::getPane((MLyt *)(*param_1 + 0x1db9c),"LOW",(char *)0x0,(char *)0x0);
  *(byte *)(iVar4 + 0x44) = *(byte *)(iVar4 + 0x44) & 0xfe | 1;
  iVar4 = msys::MLyt::getPane((MLyt *)(*param_1 + 0x1df44),"DATE",(char *)0x0,(char *)0x0);
  *(byte *)(iVar4 + 0x44) = *(byte *)(iVar4 + 0x44) & 0xfe | 1;
  GVar1 = pGVar3[(*(uint *)(pGVar3 + 0x28b4) & 0xff) + 0x28b1];
  __aeabi_memcpy4(auStack_140,&PTR_DAT_16805118,0x90);
  __aeabi_memcpy4(afStack_b0,&DAT_168051a8,0x90);
  if (*(char *)auStack_140[(byte)GVar1] != '\0') {
    iVar4 = param_1[0x1b12];
    uVar5 = LMS_GetTextIndexByLabel();
    uVar5 = LMS_GetText(iVar4 + 0xfba44,uVar5);
    (**(code **)(param_1[1] + 0x3c))(param_1 + 1,uVar5,0);
    ad::lyt::LytAnim::stopAndSetFrm((LytAnim *)(param_1 + 0x1b13),afStack_b0[(byte)GVar1]);
  }
  pSVar2 = msys::MComSys::_sys;
  pSVar6 = *(SaveLoadSys **)(*param_1 + 8);
  if (pSVar6 == (SaveLoadSys *)0x0) {
    *(SaveLoadSys **)(*param_1 + 8) = msys::MComSys::_sys;
    pSVar6 = pSVar2;
  }
  save_load::Summary::build((Summary *)(param_1 + 0x1b1a),pSVar6,*(uint *)(pGVar3 + 0x28b4) >> 8);
  save_load::SaveDateTime::build((SaveDateTime *)(param_1 + 0x3642),pGVar3);
  ad::lyt::LytNumReel3::setValueInstant((LytNumReel3 *)(param_1 + 0x3952),*(int *)(pGVar3 + 0x9c));
  return;
}


// FUNC 0x1680304c FUN_1680304c (SaveMenu)
//   size 0xe4 | file SaveMenu+0x304c | callers(1) 0x16802cd4

void FUN_1680304c(MChrBase *param_1,int param_2)

{
  FUN_168007a4(param_1,*(undefined4 *)(*(int *)(param_2 + 4) + 0x18),0x400);
  param_1[0x5c08] = (MChrBase)0x1;
  param_1[0x5c09] = (MChrBase)0x1;
  param_1[0x6c24] = (MChrBase)0x4;
  *(undefined **)(param_1 + 0x5974) = &DAT_003fc140;
  MessageWriter::setFontColor((MessageWriter *)(param_1 + 0x14c),0xe6e6e6ff,false);
  param_1[0x6c25] = (MChrBase)0x1;
  MoveVBase::stop((MoveVBase *)(param_1 + 0xcc));
  *(undefined4 *)(param_1 + 0xe8) = 0;
  *(undefined4 *)(param_1 + 0xec) = 0;
  *(undefined4 *)(param_1 + 0xf0) = 0x3c23d70a;
  *(undefined4 *)(param_1 + 0xd0) = *(undefined4 *)(param_1 + 0xe8);
  *(undefined4 *)(param_1 + 0xd4) = 0;
  *(undefined4 *)(param_1 + 0xd8) = 0x3c23d70a;
  msys::MLyt::attachMChr
            ((MLyt *)(param_2 + 0x1db9c),param_1,"INS_NOW_AREA_BAR_text",(char *)0x0,(char *)0x0,
             (char *)0x0);
  ad::lyt::LytAnim::init
            ((LytAnim *)(param_1 + 0x6c48),*(Layout **)(param_2 + 0x1dcec),"SET_AREA","");
  return;
}


// FUNC 0x16803168 save_menu::SaveMenuPage::Core::InfoPanel::AreaName::vfunc_0x4 (SaveMenu)
//   size 0x40 | file SaveMenu+0x3168 | callers(0) | datarefs 1

void save_menu::SaveMenuPage::Core::InfoPanel::AreaName::vfunc_0x4(undefined4 *param_1)

{
  int iVar1;
  void *pvVar2;
  
  param_1[0x1b15] = 0;
  *param_1 = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar1 = MessageSimple::~MessageSimple((MessageSimple *)(param_1 + 0x53));
  pvVar2 = (void *)msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  operator_delete(pvVar2);
  return;
}


// FUNC 0x168031b0 save_menu::SaveMenuPage::Core::InfoPanel::AreaName::vfunc_0x0 (SaveMenu)
//   size 0x3c | file SaveMenu+0x31b0 | callers(0) | datarefs 1

void save_menu::SaveMenuPage::Core::InfoPanel::AreaName::vfunc_0x0(undefined4 *param_1)

{
  int iVar1;
  
  param_1[0x1b15] = 0;
  *param_1 = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar1 = MessageSimple::~MessageSimple((MessageSimple *)(param_1 + 0x53));
  msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  return;
}


// FUNC 0x168031f4 FUN_168031f4 (SaveMenu)
//   size 0x1ac | file SaveMenu+0x31f4 | callers(1) 0x16803454

int FUN_168031f4(int *param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  
  *param_1 = param_2;
  iVar4 = msys::MComSys::_sys;
  iVar5 = *(int *)(param_2 + 8);
  if (*(int *)(param_2 + 8) == 0) {
    *(int *)(param_2 + 8) = msys::MComSys::_sys;
    iVar5 = iVar4;
  }
  puVar3 = (undefined4 *)FUN_16802634(param_1 + 1);
  *puVar3 = &msys::MMsg::vtable;
  iVar4 = MessageSimple::MessageSimple((MessageSimple *)(puVar3 + 0x53));
  *(undefined4 *)(iVar4 + 0x6ae0) = 0;
  *(undefined1 *)(iVar4 + 0x6ae4) = 0;
  *(undefined1 *)(iVar4 + 0x6ae5) = 0;
  *(undefined4 *)(iVar4 + 0x6ae8) = 0;
  *(undefined4 *)(iVar4 + 0x6aec) = 0;
  *(undefined4 *)(iVar4 + 0x6af4) = 0x400;
  *(undefined ***)(iVar4 + -0x14c) = &save_menu::SaveMenuPage::Core::InfoPanel::AreaName::vtable;
  *(int *)(iVar4 + 0x6af8) = iVar5;
  *(undefined1 *)(iVar4 + 0x6afc) = 0;
  *(undefined4 *)(iVar4 + 0x6b00) = 0;
  *(undefined4 *)(iVar4 + 0x6b04) = 0x3f800000;
  *(undefined4 *)(iVar4 + 0x6b08) = 0;
  *(undefined2 *)(iVar4 + 0x6b0c) = 1;
  *(undefined2 *)(iVar4 + 0x6b0e) = 0;
  *(undefined4 *)(iVar4 + 0x6b10) = 0;
  *(undefined4 *)(iVar4 + 0x6b14) = 0;
  puVar3 = (undefined4 *)FUN_16802634(iVar4 + 0x6b18);
  *puVar3 = &msys::MMsg::vtable;
  iVar4 = MessageSimple::MessageSimple((MessageSimple *)(puVar3 + 0x53));
  *(undefined4 *)(iVar4 + 0x6ae0) = 0;
  *(undefined1 *)(iVar4 + 0x6ae4) = 0;
  *(undefined1 *)(iVar4 + 0x6ae5) = 0;
  *(undefined4 *)(iVar4 + 0x6ae8) = 0;
  *(undefined4 *)(iVar4 + 0x6aec) = 0;
  *(undefined4 *)(iVar4 + 0x6af4) = 0x400;
  *(undefined4 *)(iVar4 + -0x14c) = &msys::MMoveMsg::vtable;
  *(undefined4 *)(iVar4 + 0x6af8) = 0;
  *(undefined4 *)(iVar4 + 0x6afc) = 0x3f800000;
  *(undefined4 *)(iVar4 + 0x6b00) = 0;
  *(undefined2 *)(iVar4 + 0x6b04) = 1;
  *(undefined2 *)(iVar4 + 0x6b06) = 0;
  *(undefined1 *)(iVar4 + 0x6b08) = 0;
  if ((((byte)nn::math::VEC3::Zero()::zero & 1) == 0) &&
     (iVar5 = __cxa_guard_acquire(&nn::math::VEC3::Zero()::zero), iVar5 != 0)) {
    nn::math::VEC3::Zero()::zero = 0;
    DAT_00434c4c = 0;
    DAT_00434c50 = 0;
    __cxa_guard_release(&nn::math::VEC3::Zero()::zero);
  }
  uVar2 = DAT_00434c50;
  uVar1 = DAT_00434c4c;
  *(undefined4 *)(iVar4 + 0x6b0c) = nn::math::VEC3::Zero()::zero;
  *(undefined4 *)(iVar4 + 0x6b10) = uVar1;
  *(undefined4 *)(iVar4 + 0x6b14) = uVar2;
  *(undefined4 *)(iVar4 + 0x6b18) = 0;
  *(undefined4 *)(iVar4 + -0x14c) = &save_load::Summary::vtable;
  iVar4 = __aeabi_vec_ctor_nocookie_nodtor(iVar4 + 0x6b1c,&LAB_16800634,0x1c,2);
  iVar4 = __aeabi_vec_ctor_nocookie_nodtor(iVar4 + 0x38,msys::MLytNum::MLytNum,0x230,5);
  iVar4 = msys::MLytNum::MLytNum((MLytNum *)(iVar4 + 0xaf0));
  return iVar4 + -0xe3f8;
}


// FUNC 0x168033cc FUN_168033cc (SaveMenu)
//   size 0x84 | file SaveMenu+0x33cc | callers(0) | datarefs 1

void FUN_168033cc(int param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x1db9c),0,1,(char *)0x0,(char *)0x0);
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x1df44),0,1,(char *)0x0,(char *)0x0);
  do {
    piVar1 = *(int **)(param_1 + iVar2 * 4 + 0x1e328);
    (**(code **)(*piVar1 + 0x28))(piVar1,0);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 4);
  *(code **)(param_1 + 0x1dac0) = FUN_168018f4;
  *(undefined4 *)(param_1 + 0x1dac4) = 0;
  return;
}


// FUNC 0x16803454 FUN_16803454 (SaveMenu)
//   size 0x2fc | file SaveMenu+0x3454 | callers(1) 0x16803a54

undefined4 * FUN_16803454(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  *param_1 = &save_menu::SaveMenuPage::Core::vtable;
  param_1[1] = param_2;
  param_1[2] = 0;
  iVar1 = menu_map::ParamMapPlacePos::ParamMapPlacePos((ParamMapPlacePos *)(param_1 + 3));
  iVar1 = __aeabi_vec_ctor_nocookie_nodtor(iVar1 + 0x100,FUN_168006cc,0x27c,3);
  puVar2 = (undefined4 *)FUN_16802634(iVar1 + 0x774);
  *puVar2 = &msys::MCellAnime::vtable;
  iVar1 = CellAnime::CellAnime((CellAnime *)(puVar2 + 0x53));
  *(undefined1 *)(iVar1 + 300) = 0xff;
  *(undefined1 *)(iVar1 + 0x12d) = 0xff;
  *(undefined1 *)(iVar1 + 0x12e) = 0xff;
  *(undefined1 *)(iVar1 + 0x12f) = 0xff;
  iVar1 = FUN_168031f4(iVar1 + 0x130,iVar1 + -0x9cc);
  iVar1 = __aeabi_vec_ctor_nocookie_nodtor(iVar1 + 0xe628,&LAB_16800ba4,0x4b0,3);
  puVar2 = (undefined4 *)FUN_16802634(iVar1 + 0xe14);
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
  *(undefined ***)(iVar1 + -0x14c) = &save_load::MsgWnd::vtable;
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
  puVar2 = (undefined4 *)FUN_16802634(iVar1 + 0x6dec);
  *puVar2 = &msys::MMsg::vtable;
  iVar1 = MessageSimple::MessageSimple((MessageSimple *)(puVar2 + 0x53));
  *(undefined4 *)(iVar1 + 0x6ae0) = 0;
  *(undefined1 *)(iVar1 + 0x6ae4) = 0;
  *(undefined1 *)(iVar1 + 0x6ae5) = 0;
  *(undefined4 *)(iVar1 + 0x6ae8) = 0;
  *(undefined4 *)(iVar1 + 0x6aec) = 0;
  *(undefined4 *)(iVar1 + 0x6af4) = 0x400;
  iVar1 = ad::ctrl::ButtonGroup::ButtonGroup((ButtonGroup *)(iVar1 + 0x6b0c));
  *(undefined4 *)(iVar1 + 0x1c) = 0;
  iVar1 = ad::font::ResFont::ResFont((ResFont *)(iVar1 + 0x20));
  ad::lyt::LytResourceMan::init((LytResourceMan *)(iVar1 + -4));
  iVar1 = ad::fw::Resource::Resource((Resource *)(iVar1 + 0x70));
  puVar2 = (undefined4 *)FUN_16802634(iVar1 + 0x44);
  *puVar2 = &msys::MLyt::vtable;
  *(undefined1 *)(puVar2 + 0x53) = 0xff;
  *(undefined2 *)((int)puVar2 + 0x14e) = 0;
  puVar2[0x54] = 0;
  iVar1 = __aeabi_vec_ctor_nocookie_nodtor(puVar2 + 0x55,&LAB_16800634,0x1c,0xc);
  iVar1 = __aeabi_vec_ctor_nocookie_nodtor(iVar1 + 0x15c,&LAB_16800680,0x10,0xc);
  *(undefined4 *)(iVar1 + 0xc0) = 0;
  *(undefined1 *)(iVar1 + 0xc4) = 1;
  *(undefined4 *)(iVar1 + 200) = 0;
  *(undefined4 *)(iVar1 + 0xcc) = 0;
  *(undefined1 *)(iVar1 + 0xd0) = 0;
  *(undefined4 *)(iVar1 + 0xd4) = 0;
  *(undefined4 *)(iVar1 + 0xd8) = 0;
  FUN_168041b0(iVar1 + -0xc,0xffffffff);
  puVar2 = (undefined4 *)FUN_16802634(iVar1 + 0xf8);
  *puVar2 = &msys::MLyt::vtable;
  *(undefined1 *)(puVar2 + 0x53) = 0xff;
  *(undefined2 *)((int)puVar2 + 0x14e) = 0;
  puVar2[0x54] = 0;
  iVar1 = __aeabi_vec_ctor_nocookie_nodtor(puVar2 + 0x55,&LAB_16800634,0x1c,0xc);
  iVar1 = __aeabi_vec_ctor_nocookie_nodtor(iVar1 + 0x15c,&LAB_16800680,0x10,0xc);
  *(undefined4 *)(iVar1 + 0xc0) = 0;
  *(undefined1 *)(iVar1 + 0xc4) = 1;
  *(undefined4 *)(iVar1 + 200) = 0;
  *(undefined4 *)(iVar1 + 0xcc) = 0;
  *(undefined1 *)(iVar1 + 0xd0) = 0;
  *(undefined4 *)(iVar1 + 0xd4) = 0;
  *(undefined4 *)(iVar1 + 0xd8) = 0;
  FUN_168041b0(iVar1 + -0xc,0xffffffff);
  puVar2 = (undefined4 *)msys::MCursorBase::MCursorBase((MCursorBase *)(iVar1 + 0xf8));
  *puVar2 = &vtable_for_N4msys7MCursorILj3EEE;
  puVar2[0xc] = 0;
  puVar2[0xd] = 0;
  puVar2[0xe] = 0;
  puVar2[-0x20d] = FUN_16802b20;
  puVar2[-0x20c] = 0;
  puVar2[-0x20b] = FUN_168033cc;
  puVar2[-0x20a] = 0;
  return puVar2 + -0x78bb;
}


// FUNC 0x16803788 save_menu::SaveMenuPage::Core::vfunc_0x4 (SaveMenu)
//   size 0x10 | file SaveMenu+0x3788 | callers(0) | datarefs 1

void save_menu::SaveMenuPage::Core::vfunc_0x4(void)

{
  void *pvVar1;
  
  pvVar1 = (void *)vfunc_0x0();
  operator_delete(pvVar1);
  return;
}


// FUNC 0x16803798 save_menu::SaveMenuPage::Core::vfunc_0x0 (SaveMenu)
//   size 0x274 | file SaveMenu+0x3798 | callers(1) 0x16803788 | datarefs 1

int save_menu::SaveMenuPage::Core::vfunc_0x0(undefined4 *param_1)

{
  int iVar1;
  MLyt *pMVar2;
  
  *param_1 = &vtable;
  msys::MMapIconMan::term((MMapIconMan *)(param_1 + 3));
  msys::MCursorBase::term((MCursorBase *)(param_1 + 0x78bb));
  msys::MLyt::term((MLyt *)(param_1 + 0x76e7));
  msys::MLyt::term((MLyt *)(param_1 + 0x77d1));
  ad::ctrl::ButtonGroup::FreeAll((ButtonGroup *)(param_1 + 0x76b2));
  ad::fw::Resource::term((Resource *)(param_1 + 0x76d6));
  ad::lyt::LytResourceMan::term((LytResourceMan *)(param_1 + 0x76b9));
  iVar1 = msys::MCursorBase::~MCursorBase((MCursorBase *)(param_1 + 0x78bb));
  pMVar2 = (MLyt *)(iVar1 + -0x3a8);
  *(undefined ***)pMVar2 = &msys::MLyt::vtable;
  msys::MLyt::term(pMVar2);
  __aeabi_vec_dtor(iVar1 + -0xf8,&LAB_168006b0,0x10,0xc);
  __aeabi_vec_dtor(iVar1 + -0x254,&LAB_16800670,0x1c,0xc);
  iVar1 = msys::MChrBase::vfunc_0x0(pMVar2);
  pMVar2 = (MLyt *)(iVar1 + -0x3a8);
  *(undefined ***)pMVar2 = &msys::MLyt::vtable;
  msys::MLyt::term(pMVar2);
  __aeabi_vec_dtor(iVar1 + -0xf8,&LAB_168006b0,0x10,0xc);
  __aeabi_vec_dtor(iVar1 + -0x254,&LAB_16800670,0x1c,0xc);
  iVar1 = msys::MChrBase::vfunc_0x0(pMVar2);
  iVar1 = ad::fw::Resource::~Resource((Resource *)(iVar1 + -0x44));
  ad::lyt::LytResourceMan::term((LytResourceMan *)(iVar1 + -0x74));
  iVar1 = ad::font::ResFont::~ResFont((ResFont *)(iVar1 + -0x70));
  iVar1 = ad::ctrl::ButtonGroup::~ButtonGroup((ButtonGroup *)(iVar1 + -0x20));
  *(undefined ***)(iVar1 + -0x6c58) = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar1 = MessageSimple::~MessageSimple((MessageSimple *)(iVar1 + -0x6b0c));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  *(undefined ***)(iVar1 + -0x6f38) = &msys::MMsgWnd::vtable;
  Message::term((Message *)(iVar1 + -0x6dec));
  iVar1 = Message::~Message((Message *)(iVar1 + -0x6dec));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  __aeabi_vec_dtor(iVar1 + -0xe14,&LAB_16800be8,0x4b0,3);
  iVar1 = msys::MLytNum::~MLytNum((MLytNum *)(iVar1 + -0x1044));
  __aeabi_vec_dtor(iVar1 + -0xaf0,msys::MLytNum::~MLytNum,0x230,5);
  *(undefined4 *)(iVar1 + -0x7790) = &save_load::Summary::vtable;
  __aeabi_vec_dtor(iVar1 + -0xb28,&LAB_16800670,0x1c,2);
  *(undefined4 *)(iVar1 + -0xb44) = 0;
  *(undefined4 *)(iVar1 + -0x7790) = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar1 = MessageSimple::~MessageSimple((MessageSimple *)(iVar1 + -0x7644));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  *(undefined4 *)(iVar1 + -0x10) = 0;
  *(undefined ***)(iVar1 + -0x6c64) = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar1 = MessageSimple::~MessageSimple((MessageSimple *)(iVar1 + -0x6b18));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  *(undefined ***)(iVar1 + -0x280) = &msys::MCellAnime::vtable;
  iVar1 = CellAnime::~CellAnime((CellAnime *)(iVar1 + -0x134));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  __aeabi_vec_dtor(iVar1 + -0x774,&LAB_16800700,0x27c,3);
  return iVar1 + -0x880;
}


// FUNC 0x16803a3c save_menu::SaveMenuPage::vfunc_0x28 (SaveMenu)
//   size 0x14 | file SaveMenu+0x3a3c | callers(0) | datarefs 1

int save_menu::SaveMenuPage::vfunc_0x28(int param_1,int param_2)

{
  return *(int *)(param_1 + 0x20) + param_2 * 4 + 0x1dab4;
}


// FUNC 0x16803a54 save_menu::SaveMenuPage::vfunc_0x8 (SaveMenu)
//   size 0x78 | file SaveMenu+0x3a54 | callers(0) | datarefs 1

void save_menu::SaveMenuPage::vfunc_0x8(int *param_1)

{
  int iVar1;
  void *pvVar2;
  code *UNRECOVERED_JUMPTABLE;
  bool bVar3;
  
  if (param_1[8] == 0) {
    (**(code **)(*param_1 + 0x2c))(param_1);
    pvVar2 = operator_new(0x1e338,(MemAlcBase *)param_1[6],(char *)0x0,0);
    iVar1 = 0;
    if (pvVar2 != (void *)0x0) {
      iVar1 = FUN_16803454(pvVar2,param_1);
    }
    param_1[8] = iVar1;
  }
  else {
    iVar1 = param_1[8];
  }
  UNRECOVERED_JUMPTABLE = (code *)(iVar1 + 0x1d000);
  bVar3 = (*(uint *)(iVar1 + 0x1dabc) & 1) == 0;
  if (bVar3) {
    UNRECOVERED_JUMPTABLE = *(code **)(iVar1 + 0x1dab8);
  }
  if (!bVar3) {
    UNRECOVERED_JUMPTABLE =
         *(code **)(*(int *)(iVar1 + ((int)*(uint *)(iVar1 + 0x1dabc) >> 1)) +
                   *(int *)(UNRECOVERED_JUMPTABLE + 0xab8));
  }
                    /* WARNING: Could not recover jumptable at 0x16803ac8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// FUNC 0x16803ad0 save_menu::SaveMenuPage::vfunc_0x14 (SaveMenu)
//   size 0x10 | file SaveMenu+0x3ad0 | callers(0) | datarefs 1

void save_menu::SaveMenuPage::vfunc_0x14(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x16803adc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(param_1 + 0x20) + 8))();
  return;
}


// FUNC 0x16803ae0 save_menu::SaveMenuPage::vfunc_0xc (SaveMenu)
//   size 0x4 | file SaveMenu+0x3ae0 | callers(0) | datarefs 1

void save_menu::SaveMenuPage::vfunc_0xc(void)

{
  return;
}


// FUNC 0x16803ae4 save_menu::SaveMenuPage::vfunc_0x24 (SaveMenu)
//   size 0x8 | file SaveMenu+0x3ae4 | callers(0) | datarefs 1

undefined4 save_menu::SaveMenuPage::vfunc_0x24(void)

{
  return 0;
}


// FUNC 0x16803aec save_menu::SaveMenuPage::vfunc_0x4 (SaveMenu)
//   size 0xc4 | file SaveMenu+0x3aec | callers(0) | datarefs 1

void save_menu::SaveMenuPage::vfunc_0x4(undefined4 *param_1)

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


// FUNC 0x16803bb8 save_menu::SaveMenuPage::vfunc_0x0 (SaveMenu)
//   size 0xc0 | file SaveMenu+0x3bb8 | callers(0) | datarefs 1

undefined4 * save_menu::SaveMenuPage::vfunc_0x0(undefined4 *param_1)

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


// FUNC 0x16803c80 save_menu::SaveMenuTask::vfunc_0x10 (SaveMenu)
//   size 0x1c | file SaveMenu+0x3c80 | callers(0) | datarefs 1

void save_menu::SaveMenuTask::vfunc_0x10(TaskMainBase *param_1)

{
  if (*(char *)(*(int *)(param_1 + 0x580) + 0xe9049) == '\0') {
    return;
  }
  GameMain::Back(param_1);
  return;
}


// FUNC 0x16803c9c FUN_16803c9c (SaveMenu)
//   size 0xa4 | file SaveMenu+0x3c9c | callers(1) 0x168005c0

int FUN_16803c9c(MTaskBase *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)msys::MTaskBase::MTaskBase(param_1);
  *puVar1 = &save_menu::SaveMenuTask::vtable;
  puVar1 = (undefined4 *)save_load::SaveLoadSys::SaveLoadSys((SaveLoadSys *)(puVar1 + 0x162));
  *puVar1 = &save_menu::SaveMenu::vtable;
  puVar1[0x3f27c] = puVar1 + 0x3f27c;
  puVar1[0x3f27d] = puVar1 + 0x3f27c;
  puVar1[0x3f27e] = puVar1 + 0x3f27e;
  puVar1[0x3f27f] = puVar1 + 0x3f27e;
  *(undefined1 *)(puVar1 + 0x3f280) = 0;
  puVar1[0x3f281] = 0;
  puVar1[0x3f27b] = &save_menu::SaveMenuPage::vtable;
  puVar1[0x3f282] = 0;
  puVar1[0x3f283] = 0;
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(puVar1 + 0x3f284,ad::fw::Resource::Resource,0x44,2);
  FUN_16803fbc(iVar2 + -0xfca10,iVar2 + -0xfcf98);
  *(int *)(iVar2 + -0xfca18) = iVar2 + -0xfca10;
  return iVar2 + -0xfcf98;
}


// FUNC 0x16803d58 save_menu::SaveMenuTask::vfunc_0x8 (SaveMenu)
//   size 0x24 | file SaveMenu+0x3d58 | callers(0) | datarefs 1

void save_menu::SaveMenuTask::vfunc_0x8(undefined4 *param_1)

{
  int iVar1;
  void *pvVar2;
  
  *param_1 = &vtable;
  iVar1 = SaveMenu::vfunc_0x0(param_1 + 0x162);
  pvVar2 = (void *)ad::fw::TaskBase::~TaskBase((TaskBase *)(iVar1 + -0x588));
  operator_delete(pvVar2);
  return;
}


// FUNC 0x16803d80 save_menu::SaveMenuTask::vfunc_0x4 (SaveMenu)
//   size 0x20 | file SaveMenu+0x3d80 | callers(0) | datarefs 1

void save_menu::SaveMenuTask::vfunc_0x4(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &vtable;
  iVar1 = SaveMenu::vfunc_0x0(param_1 + 0x162);
  ad::fw::TaskBase::~TaskBase((TaskBase *)(iVar1 + -0x588));
  return;
}


// FUNC 0x16803da4 FUN_16803da4 (SaveMenu)
//   size 0x6c | file SaveMenu+0x3da4 | callers(0) | datarefs 1

void FUN_16803da4(SaveLoadSys *param_1)

{
  int iVar1;
  int iVar2;
  uint in_r12;
  bool bVar3;
  
  iVar1 = *(int *)(param_1 + 0x278);
  iVar2 = iVar1;
  while( true ) {
    bVar3 = iVar2 != iVar1 + 0x150;
    if (bVar3) {
      in_r12 = (uint)*(byte *)(iVar2 + 4);
    }
    if (!bVar3 || in_r12 == 0) break;
    iVar2 = iVar2 + 0xa8;
  }
  if (iVar2 == iVar1 + 0x150) {
    save_load::SaveLoadSys::funcCalcLoadData(param_1);
    *(undefined4 *)(param_1 + 0xfca98) = 0;
    *(code **)(param_1 + 0xf84) = FUN_16803ea8;
    *(undefined4 *)(param_1 + 0xf88) = 0;
  }
  return;
}


// FUNC 0x16803e18 FUN_16803e18 (SaveMenu)
//   size 0x84 | file SaveMenu+0x3e18 | callers(0) | datarefs 2

void FUN_16803e18(SaveLoadSys *param_1)

{
  int iVar1;
  SaveLoadSys *pSVar2;
  
  if ((param_1[0xfbaf0] != (SaveLoadSys)0x0) &&
     (iVar1 = (**(code **)(**(int **)(*(int *)(param_1 + 0xe64f0) + 0x44) + 0x10))(), iVar1 == 0)) {
    for (pSVar2 = param_1 + 0xfca54; pSVar2[0xc] == (SaveLoadSys)0x0; pSVar2 = pSVar2 + -0x44) {
    }
    if (pSVar2[4] != (SaveLoadSys)0x0) {
      save_load::SaveLoadSys::funcCalcCreateChr(param_1);
      msys::MLytNumRes::init((MLytNumRes *)(param_1 + 0x844),(LytResourceMan *)(param_1 + 2000),5);
      return;
    }
  }
  return;
}


// FUNC 0x16803ea8 FUN_16803ea8 (SaveMenu)
//   size 0x10c | file SaveMenu+0x3ea8 | callers(0) | datarefs 2

void FUN_16803ea8(int param_1)

{
  int iVar1;
  TaskBase *this;
  char *pcVar2;
  uint uVar3;
  char *pcVar4;
  FileContext *pFVar5;
  uint *local_60 [2];
  TransMultiSymbol aTStack_58 [44];
  undefined4 local_2c;
  MemAlcBase *local_28;
  
  do {
    iVar1 = ad::fw::TaskBase::isReadable(*(TaskBase **)(param_1 + 4));
    if (iVar1 == 0) {
      return;
    }
    iVar1 = *(int *)(param_1 + 0xfca98);
    this = *(TaskBase **)(param_1 + 4);
    pFVar5 = *(FileContext **)(param_1 + 0x278);
    local_28 = (MemAlcBase *)(param_1 + 0xc);
    pcVar4 = *(char **)(&DAT_16809ac4 + iVar1 * 4);
    local_2c = *(undefined4 *)(pFVar5 + 0x24);
    ad::TransMultiSymbol::init(aTStack_58,pcVar4);
    BinGlu4Acs::getEntryAcs((char *)local_60);
    pcVar2 = (char *)(*(int *)(pFVar5 + 0x24) + (*local_60[0] & 0x3fffffff));
    ad::fw::TaskBase::readCA
              (this,(Resource *)(param_1 + iVar1 * 0x44 + 0xfca10),pFVar5,pcVar4,pcVar2,pcVar2 + 4,
               pcVar2 + 8,pcVar2 + 0xc,local_28,0x7f,(VramAlcBase *)0x0,0,(ResCacheArg *)0x0);
    uVar3 = *(int *)(param_1 + 0xfca98) + 1;
    *(uint *)(param_1 + 0xfca98) = uVar3;
  } while (uVar3 < 2);
  *(code **)(param_1 + 0xf84) = FUN_16803e18;
  *(undefined4 *)(param_1 + 0xf88) = 0;
  return;
}


// FUNC 0x16803fbc FUN_16803fbc (SaveMenu)
//   size 0x16c | file SaveMenu+0x3fbc | callers(1) 0x16803c9c

void FUN_16803fbc(MComSys *param_1,MTaskBase *param_2)

{
  Job *pJVar1;
  undefined4 uVar2;
  
  msys::MComSys::initBaseSys(param_1,param_2,0x600000,0x400000,0,0x100000,0x180000,2,'\0',false);
  msys::MComSys::entryPage(param_1,(MPageBase *)(param_1 + 0xfc9ec));
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
    *(undefined **)(pJVar1 + 0x10) = &DAT_16805238;
    *(undefined4 *)(pJVar1 + 0x14) = 2;
    uVar2 = *(undefined4 *)(param_2 + 0x4d8);
    *(undefined4 *)(pJVar1 + 0x18) = *(undefined4 *)(param_2 + 0x4d4);
    *(undefined4 *)(pJVar1 + 0x1c) = uVar2;
  }
  CtrJobMan::enqueue((CtrJobMan *)(param_2 + 0x4dc),pJVar1);
  *(code **)(param_1 + 0xf84) = FUN_16803da4;
  *(undefined4 *)(param_1 + 0xf88) = 0;
  msys::MComSys::setupCamU(param_1);
  msys::MComSys::setupCamL(param_1);
  param_1[0x4ad85] = (MComSys)0x1;
  param_1[0x4ae65] = (MComSys)0x1;
  return;
}


// FUNC 0x1680414c save_menu::SaveMenu::vfunc_0x4 (SaveMenu)
//   size 0x10 | file SaveMenu+0x414c | callers(0) | datarefs 1

void save_menu::SaveMenu::vfunc_0x4(void)

{
  void *pvVar1;
  
  pvVar1 = (void *)vfunc_0x0();
  operator_delete(pvVar1);
  return;
}


// FUNC 0x1680415c FUN_1680415c (SaveMenu)
//   size 0x2c | file SaveMenu+0x415c | callers(0) | datarefs 1

bool FUN_1680415c(int *param_1,uint param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 8))();
  return (uVar1 & param_3) == param_2;
}


// FUNC 0x16804188 FUN_16804188 (SaveMenu)
//   size 0x8 | file SaveMenu+0x4188 | callers(0) | datarefs 1

undefined4 FUN_16804188(void)

{
  return 0;
}


// FUNC 0x16804190 save_menu::SaveMenuPage::Core::InfoPanel::AreaName::vfunc_0x1c (SaveMenu)
//   size 0x8 | file SaveMenu+0x4190 | callers(0) | datarefs 1

undefined4 save_menu::SaveMenuPage::Core::InfoPanel::AreaName::vfunc_0x1c(void)

{
  return 7;
}


// FUNC 0x16804198 save_load::MsgWnd::vfunc_0x1c (SaveMenu)
//   size 0x8 | file SaveMenu+0x4198 | callers(0) | datarefs 1

undefined4 save_load::MsgWnd::vfunc_0x1c(void)

{
  return 7;
}


// FUNC 0x168041a0 save_menu::SaveMenuPage::Core::vfunc_0xc (SaveMenu)
//   size 0x10 | file SaveMenu+0x41a0 | callers(0) | datarefs 1

bool save_menu::SaveMenuPage::Core::vfunc_0xc(undefined4 param_1,int param_2)

{
  return *(char *)(param_2 + 0x12) != '\0';
}


// FUNC 0x168041b0 FUN_168041b0 (SaveMenu)
//   size 0x1c | file SaveMenu+0x41b0 | callers(1) 0x16803454

void FUN_168041b0(uint *param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = param_2 & 0xff | (param_2 & 0xff) << 8;
  uVar1 = uVar1 | uVar1 << 0x10;
  *param_1 = uVar1;
  param_1[1] = uVar1;
  param_1[2] = uVar1;
  return;
}


// FUNC 0x168041cc SaveMenu::nnroControlObject_ (SaveMenu)
//   size 0x74 | file SaveMenu+0x41cc | callers(0)

undefined4 SaveMenu::nnroControlObject_(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined *puVar2;
  
  switch(param_2) {
  case 0:
    uVar1 = 0;
    break;
  case 1:
    DAT_16809acc = param_1;
    return 0;
  case 2:
    uVar1 = DAT_16809acc;
    break;
  case 3:
    *param_1 = &DAT_16804368;
    puVar2 = &DAT_16804368;
    goto LAB_1680422c;
  case 4:
    *param_1 = &DAT_16805a00;
    puVar2 = &DAT_16805a00;
LAB_1680422c:
    param_1[1] = puVar2;
    return 0;
  default:
    return 0xd8e12c21;
  }
  *param_1 = uVar1;
  return 0;
}


// FUNC 0x16804278 FUN_16804278 (SaveMenu)
//   size 0xac | file SaveMenu+0x4278 | callers(0) | datarefs 1

void FUN_16804278(int param_1)

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


// FUNC 0x16804324 ->operator.delete (SaveMenu)
//   size 0x4 | file SaveMenu+0x4324 | callers(0) | datarefs 1
// veneer/thunk -> 0x00286514 operator.delete (static)

// FUNC 0x16804328 FUN_16804328 (SaveMenu)
//   size 0x4 | file SaveMenu+0x4328 | callers(0) | datarefs 1

void FUN_16804328(void)

{
  return;
}


// FUNC 0x1680432c FUN_1680432c (SaveMenu)
//   size 0x28 | file SaveMenu+0x432c | callers(0) | datarefs 1

void FUN_1680432c(float param_1,MCursorBase *param_2,MLyt *param_3)

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


// FUNC 0x16804354 FUN_16804354 (SaveMenu)
//   size 0x10 | file SaveMenu+0x4354 | callers(0) | datarefs 1

void FUN_16804354(MCursorBase *param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)msys::MCursorBase::~MCursorBase(param_1);
  operator_delete(pvVar1);
  return;
}


// FUNC 0x16804364 ->msys::MCursorBase::~MCursorBase (SaveMenu)
//   size 0x4 | file SaveMenu+0x4364 | callers(0) | datarefs 1
// veneer/thunk -> 0x00324600 msys::MCursorBase::~MCursorBase (static)

