// fps60 TG decompiled C: 3dx_v12.code.bin module LoadMenu part 1 (Ghidra 12.2, ARM:LE:32:v6:hardfp)
// Addresses: static = runtime address; CRO = fixed analysis base (crolink.py), NOT runtime.

// FUNC 0x14800180 ->operator.new (LoadMenu)
//   size 0x4 | file LoadMenu+0x180 | callers(6) 0x148008c0 0x1480d430 0x14800b14 0x1480610c 0x1480cab0 0x14809c1c
// veneer/thunk -> 0x00287d40 operator.new (static)

// FUNC 0x14800188 ->TaskMan::entry (LoadMenu)
//   size 0x4 | file LoadMenu+0x188 | callers(1) 0x148008c0
// veneer/thunk -> 0x00287b18 TaskMan::entry (static)

// FUNC 0x14800190 ->operator.delete (LoadMenu)
//   size 0x4 | file LoadMenu+0x190 | callers(24) 0x14800b14 0x148064a4 0x1480daf0 0x1480136c 0x14801844 0x14801904 0x14801b20 0x14801b8c ...
// veneer/thunk -> 0x00286514 operator.delete (static)

// FUNC 0x14800198 ->MsgDataAcsrBase::~MsgDataAcsrBase (LoadMenu)
//   size 0x4 | file LoadMenu+0x198 | callers(3) 0x1480136c 0x1480137c 0x1480d720
// veneer/thunk -> 0x0026fdb4 MsgDataAcsrBase::~MsgDataAcsrBase (static)

// FUNC 0x148001a0 ->CellAnime::term (LoadMenu)
//   size 0x4 | file LoadMenu+0x1a0 | callers(6) 0x1480b7d8 0x1480be7c 0x14801478 0x14802444 0x14806ac8 0x1480b7f4
// veneer/thunk -> 0x00259f88 CellAnime::term (static)

// FUNC 0x148001a8 ->msys::MRenderQueueBase::enqueueMsg (LoadMenu)
//   size 0x4 | file LoadMenu+0x1a8 | callers(2) 0x148014c4 0x14801814
// veneer/thunk -> 0x00328df0 msys::MRenderQueueBase::enqueueMsg (static)

// FUNC 0x148001b0 ->MessageSimple::MessageSimple (LoadMenu)
//   size 0x4 | file LoadMenu+0x1b0 | callers(3) 0x14805c80 0x1480c720 0x148014f4
// veneer/thunk -> 0x0027ceec MessageSimple::MessageSimple (static)

// FUNC 0x148001b8 ->MessageSimple::term (LoadMenu)
//   size 0x4 | file LoadMenu+0x1b8 | callers(7) 0x14801ea8 0x14801f40 0x14805e70 0x14805fc0 0x1480c910 0x1480c9e4 0x1480153c
// veneer/thunk -> 0x00137090 MessageSimple::term (static)

// FUNC 0x148001c0 ->MessageSimple::~MessageSimple (LoadMenu)
//   size 0x4 | file LoadMenu+0x1c0 | callers(7) 0x14801ea8 0x14801f40 0x14805e70 0x14805fc0 0x1480c910 0x1480c9e4 0x1480153c
// veneer/thunk -> 0x00256578 MessageSimple::~MessageSimple (static)

// FUNC 0x148001c8 ->MoveVBase::update (LoadMenu)
//   size 0x4 | file LoadMenu+0x1c8 | callers(3) 0x14801654 0x14801738 0x1480b664
// veneer/thunk -> 0x002597d4 MoveVBase::update (static)

// FUNC 0x148001d0 ->msys::MChrBaseCore::getDisplayID (LoadMenu)
//   size 0x4 | file LoadMenu+0x1d0 | callers(2) 0x14801698 0x14806608
// veneer/thunk -> 0x00207084 msys::MChrBaseCore::getDisplayID (static)

// FUNC 0x148001d8 ->msys::MDfxSys::run_and_package (LoadMenu)
//   size 0x4 | file LoadMenu+0x1d8 | callers(1) 0x14801698
// veneer/thunk -> 0x003315ac msys::MDfxSys::run_and_package (static)

// FUNC 0x148001e0 ->CtrBtn::get (LoadMenu)
//   size 0x4 | file LoadMenu+0x1e0 | callers(1) 0x14801738
// veneer/thunk -> 0x003627f0 CtrBtn::get (static)

// FUNC 0x148001e8 ->Message::func (LoadMenu)
//   size 0x4 | file LoadMenu+0x1e8 | callers(1) 0x14801738
// veneer/thunk -> 0x00273be0 Message::func (static)

// FUNC 0x148001f0 ->msys::MMsg::applyAnime (LoadMenu)
//   size 0x4 | file LoadMenu+0x1f0 | callers(1) 0x14801854
// veneer/thunk -> 0x0032cbb8 msys::MMsg::applyAnime (static)

// FUNC 0x148001f8 ->msys::MMsg::playStr (LoadMenu)
//   size 0x4 | file LoadMenu+0x1f8 | callers(15) 0x148018b0 0x14806720 0x14809654 0x14808344 0x14803548 0x14803584 0x148035c0 0x148035fc ...
// veneer/thunk -> 0x0032ce0c msys::MMsg::playStr (static)

// FUNC 0x14800200 ->msys::MPageBase::enqueueLowerChr (LoadMenu)
//   size 0x4 | file LoadMenu+0x200 | callers(1) 0x148018f4
// veneer/thunk -> 0x00334104 msys::MPageBase::enqueueLowerChr (static)

// FUNC 0x14800208 ->msys::MPageBase::enqueueUpperChr (LoadMenu)
//   size 0x4 | file LoadMenu+0x208 | callers(1) 0x148018fc
// veneer/thunk -> 0x00334184 msys::MPageBase::enqueueUpperChr (static)

// FUNC 0x14800210 ->__aeabi_vec_dtor (LoadMenu)
//   size 0x4 | file LoadMenu+0x210 | callers(21) 0x14808e00 0x14801904 0x14801940 0x1480d720 0x14801ea8 0x14801f40 0x14802910 0x14802958 ...
// veneer/thunk -> 0x00288230 __aeabi_vec_dtor (static)

// FUNC 0x14800218 ->MoveVBase::~MoveVBase (LoadMenu)
//   size 0x4 | file LoadMenu+0x218 | callers(6) 0x14808e00 0x14801904 0x1480b9d8 0x1480ba40 0x1480be7c 0x14801940
// veneer/thunk -> 0x002535e8 MoveVBase::~MoveVBase (static)

// FUNC 0x14800220 ->ad::nfp::GetNewResult (LoadMenu)
//   size 0x4 | file LoadMenu+0x220 | callers(3) 0x148067e4 0x14801978 0x1480ad78
// veneer/thunk -> 0x001653d0 ad::nfp::GetNewResult (static)

// FUNC 0x14800228 ->ad::nfp::GetState (LoadMenu)
//   size 0x4 | file LoadMenu+0x228 | callers(6) 0x1480c224 0x148080bc 0x14809874 0x1480a424 0x1480b1f0 0x14801978
// veneer/thunk -> 0x0027efc4 ad::nfp::GetState (static)

// FUNC 0x14800230 ->ad::nfp::IsStartDetection (LoadMenu)
//   size 0x4 | file LoadMenu+0x230 | callers(1) 0x14801978
// veneer/thunk -> 0x0016554c ad::nfp::IsStartDetection (static)

// FUNC 0x14800238 ->ad::nfp::IsStopDetection (LoadMenu)
//   size 0x4 | file LoadMenu+0x238 | callers(2) 0x1480c224 0x14801978
// veneer/thunk -> 0x001654e8 ad::nfp::IsStopDetection (static)

// FUNC 0x14800240 ->ad::nfp::StartDetection (LoadMenu)
//   size 0x4 | file LoadMenu+0x240 | callers(3) 0x1480b07c 0x14801978 0x14809c1c
// veneer/thunk -> 0x00165430 ad::nfp::StartDetection (static)

// FUNC 0x14800248 ->ad::nfp::GetTagData (LoadMenu)
//   size 0x4 | file LoadMenu+0x248 | callers(1) 0x14801978
// veneer/thunk -> 0x0016516c ad::nfp::GetTagData (static)

// FUNC 0x14800250 ->ad::nfp::GetCharacterIDBase (LoadMenu)
//   size 0x4 | file LoadMenu+0x250 | callers(1) 0x14801978
// veneer/thunk -> 0x0016559c ad::nfp::GetCharacterIDBase (static)

// FUNC 0x14800258 ->MoveWorkF::MoveWorkF (LoadMenu)
//   size 0x4 | file LoadMenu+0x258 | callers(1) 0x14801aec
// veneer/thunk -> 0x00278cc0 MoveWorkF::MoveWorkF (static)

// FUNC 0x14800260 ->MoveWorkF::~MoveWorkF (LoadMenu)
//   size 0x4 | file LoadMenu+0x260 | callers(2) 0x14801b20 0x14801b30
// veneer/thunk -> 0x00340694 MoveWorkF::~MoveWorkF (static)

// FUNC 0x14800268 ->GameMain::Back (LoadMenu)
//   size 0x4 | file LoadMenu+0x268 | callers(1) 0x14801b34
// veneer/thunk -> 0x0033e354 GameMain::Back (static)

// FUNC 0x14800270 ->msys::MTaskBase::MTaskBase (LoadMenu)
//   size 0x4 | file LoadMenu+0x270 | callers(1) 0x14801b50
// veneer/thunk -> 0x00334688 msys::MTaskBase::MTaskBase (static)

// FUNC 0x14800278 ->ad::fw::TaskBase::~TaskBase (LoadMenu)
//   size 0x4 | file LoadMenu+0x278 | callers(2) 0x14801b8c 0x14801bb4
// veneer/thunk -> 0x0026d590 ad::fw::TaskBase::~TaskBase (static)

// FUNC 0x14800280 ->ad::lyt::LytResourceMan::init (LoadMenu)
//   size 0x4 | file LoadMenu+0x280 | callers(3) 0x1480925c 0x14809654 0x14801c08
// veneer/thunk -> 0x00250d1c ad::lyt::LytResourceMan::init (static)

// FUNC 0x14800288 ->ad::fw::Resource::getFileData (LoadMenu)
//   size 0x4 | file LoadMenu+0x288 | callers(4) 0x14809654 0x14801c14 0x1480cf38 0x1480ce54
// veneer/thunk -> 0x00251d10 ad::fw::Resource::getFileData (static)

// FUNC 0x14800290 ->ad::lyt::LytResourceMan::registerArc (LoadMenu)
//   size 0x4 | file LoadMenu+0x290 | callers(2) 0x14809654 0x14801c24
// veneer/thunk -> 0x0015c910 ad::lyt::LytResourceMan::registerArc (static)

// FUNC 0x14800298 ->msys::MLyt::build (LoadMenu)
//   size 0x4 | file LoadMenu+0x298 | callers(3) 0x14809654 0x14801c3c 0x14801cb0
// veneer/thunk -> 0x0032c460 msys::MLyt::build (static)

// FUNC 0x148002a0 ->msys::MLyt::init (LoadMenu)
//   size 0x4 | file LoadMenu+0x2a0 | callers(3) 0x14809654 0x14801c50 0x14801cc0
// veneer/thunk -> 0x0032c3a0 msys::MLyt::init (static)

// FUNC 0x148002a8 ->msys::MLyt::createLyt (LoadMenu)
//   size 0x4 | file LoadMenu+0x2a8 | callers(2) 0x14809654 0x14801c60
// veneer/thunk -> 0x0032c78c msys::MLyt::createLyt (static)

// FUNC 0x148002b0 ->MoveVBase::stop (LoadMenu)
//   size 0x4 | file LoadMenu+0x2b0 | callers(12) 0x1480891c 0x148022c0 0x14806ac8 0x14806608 0x14809654 0x1480b2b8 0x14801c74 0x14801cf4 ...
// veneer/thunk -> 0x00259dd8 MoveVBase::stop (static)

// FUNC 0x148002b8 ->msys::MLyt::createLyt (LoadMenu)
//   size 0x4 | file LoadMenu+0x2b8 | callers(1) 0x14801ce4
// veneer/thunk -> 0x0032c8c0 msys::MLyt::createLyt (static)

// FUNC 0x148002c0 ->Frm::update (LoadMenu)
//   size 0x4 | file LoadMenu+0x2c0 | callers(5) 0x14801d9c 0x1480bfe0 0x14805ae0 0x14806ac8 0x1480ab9c
// veneer/thunk -> 0x0026aed4 Frm::update (static)

// FUNC 0x148002c8 ->ad::lyt::LytAnim::update (LoadMenu)
//   size 0x4 | file LoadMenu+0x2c8 | callers(2) 0x14801d9c 0x1480bfe0
// veneer/thunk -> 0x0025631c ad::lyt::LytAnim::update (static)

// FUNC 0x148002d0 ->RandSys::get (LoadMenu)
//   size 0x4 | file LoadMenu+0x2d0 | callers(3) 0x14801d9c 0x1480bfe0 0x1480baa4
// veneer/thunk -> 0x00273054 RandSys::get (static)

// FUNC 0x148002d8 ->ad::lyt::LytAnim::play (LoadMenu)
//   size 0x4 | file LoadMenu+0x2d8 | callers(2) 0x14801d9c 0x1480bfe0
// veneer/thunk -> 0x0025629c ad::lyt::LytAnim::play (static)

// FUNC 0x148002e0 ->Frm::play (LoadMenu)
//   size 0x4 | file LoadMenu+0x2e0 | callers(9) 0x14801d9c 0x1480bfe0 0x14806ac8 0x14808344 0x14809874 0x1480a424 0x1480ab28 0x14803f30 ...
// veneer/thunk -> 0x0027a324 Frm::play (static)

// FUNC 0x148002e8 ->msys::MMoveMsg::updateAnimeFrm (LoadMenu)
//   size 0x4 | file LoadMenu+0x2e8 | callers(1) 0x14801d9c
// veneer/thunk -> 0x00331e98 msys::MMoveMsg::updateAnimeFrm (static)

// FUNC 0x148002f0 ->Backup::GetSaveData1 (LoadMenu)
//   size 0x4 | file LoadMenu+0x2f0 | callers(13) 0x14805ae0 0x148088a4 0x1480c5c4 0x1480cb00 0x148055fc 0x148036d4 0x1480299c 0x1480417c ...
// veneer/thunk -> 0x00339284 Backup::GetSaveData1 (static)

// FUNC 0x148002f8 ->save_load::FilePanel::build (LoadMenu)
//   size 0x4 | file LoadMenu+0x2f8 | callers(7) 0x14805ae0 0x148055fc 0x1480299c 0x1480417c 0x14804254 0x14801fd4 0x148051d4
// veneer/thunk -> 0x1600220c save_load::FilePanel::build (SaveLoad)

// FUNC 0x14800300 ->msys::MLyt::getParts (LoadMenu)
//   size 0x4 | file LoadMenu+0x300 | callers(3) 0x148087d4 0x148032a8 0x148020cc
// veneer/thunk -> 0x002073ec msys::MLyt::getParts (static)

// FUNC 0x14800308 ->ad::lyt::LytAnim::init (LoadMenu)
//   size 0x4 | file LoadMenu+0x308 | callers(10) 0x14805ae0 0x14808bb4 0x148087d4 0x14809654 0x14808344 0x14803118 0x1480371c 0x148037bc ...
// veneer/thunk -> 0x00264f04 ad::lyt::LytAnim::init (static)

// FUNC 0x14800310 ->ad::lyt::LytAnim::stopAndSetFrm (LoadMenu)
//   size 0x4 | file LoadMenu+0x310 | callers(9) 0x14805ae0 0x148088a4 0x14808bb4 0x14809654 0x14808344 0x14803728 0x148037fc 0x148020cc ...
// veneer/thunk -> 0x0026fe44 ad::lyt::LytAnim::stopAndSetFrm (static)

// FUNC 0x14800318 ->ad::lyt::LytAnim::term (LoadMenu)
//   size 0x4 | file LoadMenu+0x318 | callers(8) 0x14805ae0 0x14808bb4 0x14809654 0x14808344 0x14803734 0x14803808 0x148020cc 0x14804604
// veneer/thunk -> 0x00264e90 ad::lyt::LytAnim::term (static)

// FUNC 0x14800320 ->ad::lyt::LytNumReel3::InitParam::InitParam (LoadMenu)
//   size 0x4 | file LoadMenu+0x320 | callers(1) 0x148020cc
// veneer/thunk -> 0x00256194 ad::lyt::LytNumReel3::InitParam::InitParam (static)

// FUNC 0x14800328 ->msys::MLytNumRes::set (LoadMenu)
//   size 0x4 | file LoadMenu+0x328 | callers(1) 0x148020cc
// veneer/thunk -> 0x00207594 msys::MLytNumRes::set (static)

// FUNC 0x14800330 ->msys::MLytNum::init (LoadMenu)
//   size 0x4 | file LoadMenu+0x330 | callers(1) 0x148020cc
// veneer/thunk -> 0x003316b8 msys::MLytNum::init (static)

// FUNC 0x14800338 ->msys::MLyt::attachMChr (LoadMenu)
//   size 0x4 | file LoadMenu+0x338 | callers(7) 0x14806ac8 0x14806608 0x14809654 0x1480b2b8 0x14803144 0x14803500 0x148020cc
// veneer/thunk -> 0x00207468 msys::MLyt::attachMChr (static)

// FUNC 0x14800340 ->msys::MCellAnime::init (LoadMenu)
//   size 0x4 | file LoadMenu+0x340 | callers(2) 0x14806ac8 0x148020cc
// veneer/thunk -> 0x002079d8 msys::MCellAnime::init (static)

// FUNC 0x14800348 ->msys::MCellAnimeListSimple::init (LoadMenu)
//   size 0x4 | file LoadMenu+0x348 | callers(1) 0x148020cc
// veneer/thunk -> 0x00329cb0 msys::MCellAnimeListSimple::init (static)

// FUNC 0x14800350 ->ad::fw::Resource::getCA_anm (LoadMenu)
//   size 0x4 | file LoadMenu+0x350 | callers(3) 0x14802444 0x1480b7f4 0x148020cc
// veneer/thunk -> 0x0025abfc ad::fw::Resource::getCA_anm (static)

// FUNC 0x14800358 ->ad::fw::Resource::getCA_tex (LoadMenu)
//   size 0x4 | file LoadMenu+0x358 | callers(3) 0x14802444 0x1480b7f4 0x148020cc
// veneer/thunk -> 0x0025ac08 ad::fw::Resource::getCA_tex (static)

// FUNC 0x14800360 ->ad::fw::Resource::getCA_canm (LoadMenu)
//   size 0x4 | file LoadMenu+0x360 | callers(3) 0x14802444 0x1480b7f4 0x148020cc
// veneer/thunk -> 0x0025ac14 ad::fw::Resource::getCA_canm (static)

// FUNC 0x14800368 ->CellAnime::init (LoadMenu)
//   size 0x4 | file LoadMenu+0x368 | callers(3) 0x14802444 0x1480b7f4 0x148020cc
// veneer/thunk -> 0x0027fa28 CellAnime::init (static)

// FUNC 0x14800370 ->KJDB::Chr::getData (LoadMenu)
//   size 0x4 | file LoadMenu+0x370 | callers(3) 0x148022c0 0x14802444 0x1480baa4
// veneer/thunk -> 0x0020502c KJDB::Chr::getData (static)

// FUNC 0x14800378 ->strcmp (LoadMenu)
//   size 0x4 | file LoadMenu+0x378 | callers(4) 0x1480891c 0x148022c0 0x14802444 0x1480cb00
// veneer/thunk -> 0x002833b8 strcmp (static)

// FUNC 0x14800380 ->CellAnime::~CellAnime (LoadMenu)
//   size 0x4 | file LoadMenu+0x380 | callers(7) 0x148023ec 0x14802410 0x1480b9d8 0x1480ba40 0x1480be7c 0x14802b48 0x1480d8ec
// veneer/thunk -> 0x0024fc94 CellAnime::~CellAnime (static)

// FUNC 0x14800388 ->Mem::Fill (LoadMenu)
//   size 0x4 | file LoadMenu+0x388 | callers(1) 0x14802444
// veneer/thunk -> 0x002849e8 Mem::Fill (static)

// FUNC 0x14800390 ->Mem::Copy (LoadMenu)
//   size 0x4 | file LoadMenu+0x390 | callers(7) 0x14802444 0x14806ac8 0x1480c5c4 0x148036e4 0x14809c1c 0x1480baa4 0x14803ae0
// veneer/thunk -> 0x0027fd08 Mem::Copy (static)

// FUNC 0x14800398 ->CellAnime::setConstColor (LoadMenu)
//   size 0x4 | file LoadMenu+0x398 | callers(1) 0x14802718
// veneer/thunk -> 0x0025caa0 CellAnime::setConstColor (static)

// FUNC 0x148003a0 ->nn::math::ARMv6::MTX34CopyAsm (LoadMenu)
//   size 0x4 | file LoadMenu+0x3a0 | callers(1) 0x14802718
// veneer/thunk -> 0x0027d1d0 nn::math::ARMv6::MTX34CopyAsm (static)

// FUNC 0x148003a8 ->CellAnime::setWldMtx (LoadMenu)
//   size 0x4 | file LoadMenu+0x3a8 | callers(1) 0x14802718
// veneer/thunk -> 0x00270874 CellAnime::setWldMtx (static)

// FUNC 0x148003b0 ->CellAnime::play (LoadMenu)
//   size 0x4 | file LoadMenu+0x3b0 | callers(3) 0x14802718 0x14806ac8 0x1480b724
// veneer/thunk -> 0x0027bee0 CellAnime::play (static)

// FUNC 0x148003b8 ->CellAnime::draw (LoadMenu)
//   size 0x4 | file LoadMenu+0x3b8 | callers(1) 0x14802718
// veneer/thunk -> 0x00270764 CellAnime::draw (static)

// FUNC 0x148003c0 ->save_load::FilePanel::init (LoadMenu)
//   size 0x4 | file LoadMenu+0x3c0 | callers(1) 0x1480299c
// veneer/thunk -> 0x16001fc4 save_load::FilePanel::init (SaveLoad)

// FUNC 0x148003c8 ->__aeabi_vec_ctor_nocookie_nodtor (LoadMenu)
//   size 0x4 | file LoadMenu+0x3c8 | callers(9) 0x1480d5e8 0x14805c80 0x14808f5c 0x1480925c 0x1480c720 0x1480b8a8 0x14802aa4 0x14802ac8 ...
// veneer/thunk -> 0x0028771c __aeabi_vec_ctor_nocookie_nodtor (static)

// FUNC 0x148003d0 ->msys::MCellAnimeListSimple::MCellAnimeListSimple (LoadMenu)
//   size 0x4 | file LoadMenu+0x3d0 | callers(1) 0x14802ab0
// veneer/thunk -> 0x00329df4 msys::MCellAnimeListSimple::MCellAnimeListSimple (static)

// FUNC 0x148003d8 ->CellAnime::CellAnime (LoadMenu)
//   size 0x4 | file LoadMenu+0x3d8 | callers(4) 0x1480c720 0x1480b8a8 0x14802ae0 0x1480d8b4
// veneer/thunk -> 0x0026be18 CellAnime::CellAnime (static)

// FUNC 0x148003e0 ->msys::MLytNum::MLytNum (LoadMenu)
//   size 0x4 | file LoadMenu+0x3e0 | callers(2) 0x14802b08 0x1480d8a0
// veneer/thunk -> 0x003317a4 msys::MLytNum::MLytNum (static)

// FUNC 0x148003e8 ->msys::MLytNum::~MLytNum (LoadMenu)
//   size 0x4 | file LoadMenu+0x3e8 | callers(2) 0x14802b38 0x1480d8fc
// veneer/thunk -> 0x00331840 msys::MLytNum::~MLytNum (static)

// FUNC 0x148003f0 ->Backup::IsNew (LoadMenu)
//   size 0x4 | file LoadMenu+0x3f0 | callers(8) 0x148088a4 0x148055fc 0x148037e4 0x14804254 0x14804ab0 0x14802d5c 0x14804604 0x14803ae0
// veneer/thunk -> 0x00339ca8 Backup::IsNew (static)

// FUNC 0x148003f8 ->msys::MLyt::playAnimeFromNo (LoadMenu)
//   size 0x4 | file LoadMenu+0x3f8 | callers(27) 0x1480c224 0x14806720 0x148067e4 0x148069e0 0x148039b0 0x14805ae0 0x148080bc 0x14806a54 ...
// veneer/thunk -> 0x0032bf98 msys::MLyt::playAnimeFromNo (static)

// FUNC 0x14800400 ->ad::lyt::LytLocalize::LytLocalize (LoadMenu)
//   size 0x4 | file LoadMenu+0x400 | callers(2) 0x14809654 0x14802f80
// veneer/thunk -> 0x002563d4 ad::lyt::LytLocalize::LytLocalize (static)

// FUNC 0x14800408 ->ad::lyt::LytLocalize::localize (LoadMenu)
//   size 0x4 | file LoadMenu+0x408 | callers(3) 0x14809654 0x14802f8c 0x14802f98
// veneer/thunk -> 0x00264e08 ad::lyt::LytLocalize::localize (static)

// FUNC 0x14800410 ->msys::MLyt::setAnimeInfo (LoadMenu)
//   size 0x4 | file LoadMenu+0x410 | callers(10) 0x1480b2b8 0x148055fc 0x14802fb4 0x14803018 0x14803854 0x14803864 0x14803880 0x14804f1c ...
// veneer/thunk -> 0x0032bc40 msys::MLyt::setAnimeInfo (static)

// FUNC 0x14800418 ->save_load::Summary::init (LoadMenu)
//   size 0x4 | file LoadMenu+0x418 | callers(1) 0x148030ec
// veneer/thunk -> 0x16001cbc save_load::Summary::init (SaveLoad)

// FUNC 0x14800420 ->save_load::MsgWnd::init (LoadMenu)
//   size 0x4 | file LoadMenu+0x420 | callers(2) 0x1480b2b8 0x14803180
// veneer/thunk -> 0x16001a40 save_load::MsgWnd::init (SaveLoad)

// FUNC 0x14800428 ->ad::ctrl::ButtonGroup::FindButtonByName (LoadMenu)
//   size 0x4 | file LoadMenu+0x428 | callers(1) 0x148031b4
// veneer/thunk -> 0x00256680 ad::ctrl::ButtonGroup::FindButtonByName (static)

// FUNC 0x14800430 ->ad::ctrl::AnimButton::SetStateChangeCallback (LoadMenu)
//   size 0x4 | file LoadMenu+0x430 | callers(1) 0x148031cc
// veneer/thunk -> 0x00256674 ad::ctrl::AnimButton::SetStateChangeCallback (static)

// FUNC 0x14800438 ->ad::fw::TaskBase::isFps30 (LoadMenu)
//   size 0x4 | file LoadMenu+0x438 | callers(4) 0x14805ae0 0x14806ac8 0x14803220 0x1480ab9c
// veneer/thunk -> 0x0025edd0 ad::fw::TaskBase::isFps30 (static)

// FUNC 0x14800440 ->msys::MCursorBase::setVisible (LoadMenu)
//   size 0x4 | file LoadMenu+0x440 | callers(3) 0x148055fc 0x148032cc 0x14808728
// veneer/thunk -> 0x00324454 msys::MCursorBase::setVisible (static)

// FUNC 0x14800448 ->MessageSimple::init (LoadMenu)
//   size 0x4 | file LoadMenu+0x448 | callers(3) 0x14809654 0x1480b2b8 0x14803328
// veneer/thunk -> 0x002736b4 MessageSimple::init (static)

// FUNC 0x14800450 ->__cxa_guard_acquire (LoadMenu)
//   size 0x4 | file LoadMenu+0x450 | callers(8) 0x14809048 0x1480b8a8 0x14806ac8 0x14809654 0x1480b2b8 0x14803344 0x148033f4 0x14803450
// veneer/thunk -> 0x00288110 __cxa_guard_acquire (static)

// FUNC 0x14800458 ->__cxa_guard_release (LoadMenu)
//   size 0x4 | file LoadMenu+0x458 | callers(8) 0x14809048 0x1480b8a8 0x14806ac8 0x14809654 0x1480b2b8 0x14803368 0x14803418 0x14803474
// veneer/thunk -> 0x001018a8 __cxa_guard_release (static)

// FUNC 0x14800460 ->MessageWriter::setFontColor (LoadMenu)
//   size 0x4 | file LoadMenu+0x460 | callers(1) 0x148034b8
// veneer/thunk -> 0x00270f0c MessageWriter::setFontColor (static)

// FUNC 0x14800468 ->msys::MLyt::stopAnimeAndSetEnd (LoadMenu)
//   size 0x4 | file LoadMenu+0x468 | callers(11) 0x148067e4 0x14809654 0x1480b2b8 0x14803684 0x1480369c 0x1480382c 0x14803844 0x14809874 ...
// veneer/thunk -> 0x0032c27c msys::MLyt::stopAnimeAndSetEnd (static)

// FUNC 0x14800470 ->GameWork::initGameWork (LoadMenu)
//   size 0x4 | file LoadMenu+0x470 | callers(2) 0x148036c8 0x14803ae0
// veneer/thunk -> 0x0027ffa0 GameWork::initGameWork (static)

// FUNC 0x14800478 ->GameWork::postLoadGameWork (LoadMenu)
//   size 0x4 | file LoadMenu+0x478 | callers(2) 0x148036f0 0x14803ae0
// veneer/thunk -> 0x00207d74 GameWork::postLoadGameWork (static)

// FUNC 0x14800480 ->msys::MLyt::getPane (LoadMenu)
//   size 0x4 | file LoadMenu+0x480 | callers(5) 0x148087d4 0x14808344 0x14803894 0x1480cf38 0x1480ce54
// veneer/thunk -> 0x0032c688 msys::MLyt::getPane (static)

// FUNC 0x14800488 ->Backup::init (LoadMenu)
//   size 0x4 | file LoadMenu+0x488 | callers(4) 0x1480c5c4 0x14804f1c 0x14805104 0x14803ae0
// veneer/thunk -> 0x00339c54 Backup::init (static)

// FUNC 0x14800490 ->Backup::readSaveData2 (LoadMenu)
//   size 0x4 | file LoadMenu+0x490 | callers(1) 0x14803ae0
// veneer/thunk -> 0x00339778 Backup::readSaveData2 (static)

// FUNC 0x14800498 ->Backup::errorCode (LoadMenu)
//   size 0x4 | file LoadMenu+0x498 | callers(7) 0x14809874 0x14803f30 0x148044d0 0x14806294 0x14806360 0x14804604 0x14803ae0
// veneer/thunk -> 0x002063b8 Backup::errorCode (static)

// FUNC 0x148004a0 ->Backup::isBusyReading (LoadMenu)
//   size 0x4 | file LoadMenu+0x4a0 | callers(2) 0x14804604 0x14803ae0
// veneer/thunk -> 0x00339488 Backup::isBusyReading (static)

// FUNC 0x148004a8 ->Backup::term (LoadMenu)
//   size 0x4 | file LoadMenu+0x4a8 | callers(3) 0x14803f30 0x14804604 0x14803ae0
// veneer/thunk -> 0x00339c84 Backup::term (static)

// FUNC 0x148004b0 ->msys::MLyt::isBusyAnime (LoadMenu)
//   size 0x4 | file LoadMenu+0x4b0 | callers(2) 0x14803cd0 0x1480acb0
// veneer/thunk -> 0x0032bb14 msys::MLyt::isBusyAnime (static)

// FUNC 0x148004b8 ->msys::MComSys::getNextPage (LoadMenu)
//   size 0x4 | file LoadMenu+0x4b8 | callers(2) 0x14803cd0 0x1480acb0
// veneer/thunk -> 0x0032db64 msys::MComSys::getNextPage (static)

// FUNC 0x148004c0 ->Backup::isBusyCopying (LoadMenu)
//   size 0x4 | file LoadMenu+0x4c0 | callers(1) 0x14803f30
// veneer/thunk -> 0x003393c0 Backup::isBusyCopying (static)

// FUNC 0x148004c8 ->msys::MLyt::createAnimeAutoSlot (LoadMenu)
//   size 0x4 | file LoadMenu+0x4c8 | callers(4) 0x1480c170 0x14809654 0x14804254 0x1480487c
// veneer/thunk -> 0x0032c308 msys::MLyt::createAnimeAutoSlot (static)

// FUNC 0x148004d0 ->save_load::SaveLoadSys::saveIsBusyWriting (LoadMenu)
//   size 0x4 | file LoadMenu+0x4d0 | callers(3) 0x14809874 0x148044d0 0x14806360
// veneer/thunk -> 0x16000fc4 save_load::SaveLoadSys::saveIsBusyWriting (SaveLoad)

// FUNC 0x148004d8 ->msys::MLyt::isEnableAnime (LoadMenu)
//   size 0x4 | file LoadMenu+0x4d8 | callers(12) 0x148049c0 0x14804a44 0x14804ab0 0x14804e44 0x14804eb0 0x14804f1c 0x14805098 0x14805104 ...
// veneer/thunk -> 0x0032bc6c msys::MLyt::isEnableAnime (static)

// FUNC 0x148004e0 ->msys::MLyt::applyAnime (LoadMenu)
//   size 0x4 | file LoadMenu+0x4e0 | callers(1) 0x148049c0
// veneer/thunk -> 0x0032b70c msys::MLyt::applyAnime (static)

// FUNC 0x148004e8 ->kj_menu::GetBootInfo (LoadMenu)
//   size 0x4 | file LoadMenu+0x4e8 | callers(1) 0x14804ba4
// veneer/thunk -> 0x0033df34 kj_menu::GetBootInfo (static)

// FUNC 0x148004f0 ->kj_menu::BootInfo::reset (LoadMenu)
//   size 0x4 | file LoadMenu+0x4f0 | callers(1) 0x14804ba4
// veneer/thunk -> 0x0033df98 kj_menu::BootInfo::reset (static)

// FUNC 0x148004f8 ->GameMain::Change (LoadMenu)
//   size 0x4 | file LoadMenu+0x4f8 | callers(1) 0x14804ba4
// veneer/thunk -> 0x0033e7fc GameMain::Change (static)

// FUNC 0x14800500 ->fld::GetBootInfo (LoadMenu)
//   size 0x4 | file LoadMenu+0x500 | callers(1) 0x14804ba4
// veneer/thunk -> 0x002a8d3c fld::GetBootInfo (static)

// FUNC 0x14800508 ->fld::BootInfo::startScenarioModeForProd (LoadMenu)
//   size 0x4 | file LoadMenu+0x508 | callers(1) 0x14804ba4
// veneer/thunk -> 0x0030dd50 fld::BootInfo::startScenarioModeForProd (static)

// FUNC 0x14800510 ->Backup::GetSaveData2 (LoadMenu)
//   size 0x4 | file LoadMenu+0x510 | callers(1) 0x14804ba4
// veneer/thunk -> 0x003392b8 Backup::GetSaveData2 (static)

// FUNC 0x14800518 ->fld::GetSaveData (LoadMenu)
//   size 0x4 | file LoadMenu+0x518 | callers(1) 0x14804ba4
// veneer/thunk -> 0x002a8d48 fld::GetSaveData (static)

// FUNC 0x14800520 ->fld::SaveData::load (LoadMenu)
//   size 0x4 | file LoadMenu+0x520 | callers(1) 0x14804ba4
// veneer/thunk -> 0x0031cad0 fld::SaveData::load (static)

// FUNC 0x14800528 ->fld::BootInfo::startScenarioModeForLoad (LoadMenu)
//   size 0x4 | file LoadMenu+0x528 | callers(1) 0x14804ba4
// veneer/thunk -> 0x0030dd30 fld::BootInfo::startScenarioModeForLoad (static)

// FUNC 0x14800530 ->Backup::copySaveData (LoadMenu)
//   size 0x4 | file LoadMenu+0x530 | callers(1) 0x14804f1c
// veneer/thunk -> 0x003392c4 Backup::copySaveData (static)

// FUNC 0x14800538 ->Backup::deleteSaveData (LoadMenu)
//   size 0x4 | file LoadMenu+0x538 | callers(1) 0x14805104
// veneer/thunk -> 0x003399a8 Backup::deleteSaveData (static)

// FUNC 0x14800540 ->MoveC::moveFrm (LoadMenu)
//   size 0x4 | file LoadMenu+0x540 | callers(1) 0x148053dc
// veneer/thunk -> 0x0026bc74 MoveC::moveFrm (static)

// FUNC 0x14800548 ->msys::MPageBase::updateInputAllChr (LoadMenu)
//   size 0x4 | file LoadMenu+0x548 | callers(3) 0x14805510 0x1480920c 0x1480b25c
// veneer/thunk -> 0x00334204 msys::MPageBase::updateInputAllChr (static)

// FUNC 0x14800550 ->ad::ctrl::ButtonGroup::Update (LoadMenu)
//   size 0x4 | file LoadMenu+0x550 | callers(1) 0x14805510
// veneer/thunk -> 0x00250a40 ad::ctrl::ButtonGroup::Update (static)

// FUNC 0x14800558 ->ad::lyt::LytDrawSys::GetInst (LoadMenu)
//   size 0x4 | file LoadMenu+0x558 | callers(2) 0x14805a08 0x1480c498
// veneer/thunk -> 0x00287f58 ad::lyt::LytDrawSys::GetInst (static)

// FUNC 0x14800560 ->ad::lyt::Initialize (LoadMenu)
//   size 0x4 | file LoadMenu+0x560 | callers(2) 0x14805a08 0x1480c498
// veneer/thunk -> 0x002855e0 ad::lyt::Initialize (static)

// FUNC 0x14800568 ->ad::fw::TaskBase::readLyt (LoadMenu)
//   size 0x4 | file LoadMenu+0x568 | callers(2) 0x14805a08 0x1480c498
// veneer/thunk -> 0x00249e48 ad::fw::TaskBase::readLyt (static)

// FUNC 0x14800570 ->ad::ctrl::ButtonGroup::ButtonGroup (LoadMenu)
//   size 0x4 | file LoadMenu+0x570 | callers(1) 0x14805c80
// veneer/thunk -> 0x001667d8 ad::ctrl::ButtonGroup::ButtonGroup (static)

// FUNC 0x14800578 ->msys::MCursorBase::MCursorBase (LoadMenu)
//   size 0x4 | file LoadMenu+0x578 | callers(1) 0x14805c80
// veneer/thunk -> 0x00324550 msys::MCursorBase::MCursorBase (static)

// FUNC 0x14800580 ->ad::ctrl::ButtonGroup::FreeAll (LoadMenu)
//   size 0x4 | file LoadMenu+0x580 | callers(2) 0x14805e70 0x14805fc0
// veneer/thunk -> 0x002509d0 ad::ctrl::ButtonGroup::FreeAll (static)

// FUNC 0x14800588 ->msys::MCursorBase::term (LoadMenu)
//   size 0x4 | file LoadMenu+0x588 | callers(2) 0x14805e70 0x14805fc0
// veneer/thunk -> 0x003244f0 msys::MCursorBase::term (static)

// FUNC 0x14800590 ->msys::MCursorBase::~MCursorBase (LoadMenu)
//   size 0x4 | file LoadMenu+0x590 | callers(4) 0x14805e70 0x14805fc0 0x1480db20 0x1480db30
// veneer/thunk -> 0x00324600 msys::MCursorBase::~MCursorBase (static)

// FUNC 0x14800598 ->ad::ctrl::ButtonGroup::~ButtonGroup (LoadMenu)
//   size 0x4 | file LoadMenu+0x598 | callers(2) 0x14805e70 0x14805fc0
// veneer/thunk -> 0x00250928 ad::ctrl::ButtonGroup::~ButtonGroup (static)

// FUNC 0x148005a0 ->save_load::SaveLoadSys::saveFormat (LoadMenu)
//   size 0x4 | file LoadMenu+0x5a0 | callers(3) 0x1480910c 0x14806294 0x14806360
// veneer/thunk -> 0x16000840 save_load::SaveLoadSys::saveFormat (SaveLoad)

// FUNC 0x148005a8 ->Backup::isBusyFormat (LoadMenu)
//   size 0x4 | file LoadMenu+0x5a8 | callers(1) 0x14806294
// veneer/thunk -> 0x00339378 Backup::isBusyFormat (static)

// FUNC 0x148005b0 ->save_load::SaveLoadSys::saveWriteInitData (LoadMenu)
//   size 0x4 | file LoadMenu+0x5b0 | callers(1) 0x14806294
// veneer/thunk -> 0x16000ff4 save_load::SaveLoadSys::saveWriteInitData (SaveLoad)

// FUNC 0x148005b8 ->Message::close (LoadMenu)
//   size 0x4 | file LoadMenu+0x5b8 | callers(3) 0x14806720 0x14806a54 0x14806360
// veneer/thunk -> 0x0024dcc8 Message::close (static)

// FUNC 0x148005c0 ->save_load::MsgWnd::play (LoadMenu)
//   size 0x4 | file LoadMenu+0x5c0 | callers(4) 0x148069e0 0x148090a0 0x14806438 0x1480910c
// veneer/thunk -> 0x16001b9c save_load::MsgWnd::play (SaveLoad)

// FUNC 0x148005c8 ->msys::MDfxChr::~MDfxChr (LoadMenu)
//   size 0x4 | file LoadMenu+0x5c8 | callers(5) 0x14809194 0x148091a4 0x1480c910 0x1480be7c 0x1480c9e4
// veneer/thunk -> 0x003313cc msys::MDfxChr::~MDfxChr (static)

// FUNC 0x148005d0 ->msys::MDfxChr::term (LoadMenu)
//   size 0x4 | file LoadMenu+0x5d0 | callers(3) 0x148064a4 0x1480c224 0x148080bc
// veneer/thunk -> 0x00330c68 msys::MDfxChr::term (static)

// FUNC 0x148005d8 ->msys::MDfxChr::init (LoadMenu)
//   size 0x4 | file LoadMenu+0x5d8 | callers(1) 0x14806608
// veneer/thunk -> 0x003309c0 msys::MDfxChr::init (static)

// FUNC 0x148005e0 ->ad::dfx::Unit::forceDeletable (LoadMenu)
//   size 0x4 | file LoadMenu+0x5e0 | callers(3) 0x148067e4 0x14806ac8 0x14809c1c
// veneer/thunk -> 0x0014f6e4 ad::dfx::Unit::forceDeletable (static)

// FUNC 0x148005e8 ->msys::MDfxChr::playDfx (LoadMenu)
//   size 0x4 | file LoadMenu+0x5e8 | callers(3) 0x148067e4 0x14806ac8 0x14809c1c
// veneer/thunk -> 0x00330d64 msys::MDfxChr::playDfx (static)

// FUNC 0x148005f0 ->msys::MLyt::createAnime (LoadMenu)
//   size 0x4 | file LoadMenu+0x5f0 | callers(1) 0x148067e4
// veneer/thunk -> 0x00206c48 msys::MLyt::createAnime (static)

// FUNC 0x148005f8 ->ad::nfp::IsConnected (LoadMenu)
//   size 0x4 | file LoadMenu+0x5f8 | callers(2) 0x148067e4 0x1480c224
// veneer/thunk -> 0x001652d4 ad::nfp::IsConnected (static)

// FUNC 0x14800600 ->ad::fw::TaskBase::isReadable (LoadMenu)
//   size 0x4 | file LoadMenu+0x600 | callers(4) 0x14806ac8 0x1480cb00 0x1480cd44 0x1480cf38
// veneer/thunk -> 0x00222f44 ad::fw::TaskBase::isReadable (static)

// FUNC 0x14800608 ->ad::TransMultiSymbol::init (LoadMenu)
//   size 0x4 | file LoadMenu+0x608 | callers(4) 0x14806ac8 0x1480b4c4 0x1480cb00 0x1480cf38
// veneer/thunk -> 0x0026d7f8 ad::TransMultiSymbol::init (static)

// FUNC 0x14800610 ->BinGlu4Acs::getEntryAcs (LoadMenu)
//   size 0x4 | file LoadMenu+0x610 | callers(4) 0x14806ac8 0x1480b4c4 0x1480cb00 0x1480cf38
// veneer/thunk -> 0x00285268 BinGlu4Acs::getEntryAcs (static)

// FUNC 0x14800618 ->ad::fw::TaskBase::readCA (LoadMenu)
//   size 0x4 | file LoadMenu+0x618 | callers(3) 0x14806ac8 0x1480cb00 0x1480cf38
// veneer/thunk -> 0x0026daf8 ad::fw::TaskBase::readCA (static)

// FUNC 0x14800620 ->MoveVBase::moveFrmAbs (LoadMenu)
//   size 0x4 | file LoadMenu+0x620 | callers(1) 0x14806ac8
// veneer/thunk -> 0x0025cd30 MoveVBase::moveFrmAbs (static)

// FUNC 0x14800628 ->MoveVBase::jumpFT (LoadMenu)
//   size 0x4 | file LoadMenu+0x628 | callers(2) 0x1480b664 0x14806ac8
// veneer/thunk -> 0x0025d1c8 MoveVBase::jumpFT (static)

// FUNC 0x14800630 ->MoveVBase::isBusy (LoadMenu)
//   size 0x4 | file LoadMenu+0x630 | callers(2) 0x1480b664 0x14806ac8
// veneer/thunk -> 0x0025d230 MoveVBase::isBusy (static)

// FUNC 0x14800638 ->MoveVBase::moveAbs (LoadMenu)
//   size 0x4 | file LoadMenu+0x638 | callers(1) 0x14806ac8
// veneer/thunk -> 0x002344bc MoveVBase::moveAbs (static)

// FUNC 0x14800640 ->msys::MDfxChr::setCA (LoadMenu)
//   size 0x4 | file LoadMenu+0x640 | callers(1) 0x14806ac8
// veneer/thunk -> 0x00330c7c msys::MDfxChr::setCA (static)

// FUNC 0x14800648 ->msys::MLyt::detachMChr (LoadMenu)
//   size 0x4 | file LoadMenu+0x648 | callers(1) 0x14806ac8
// veneer/thunk -> 0x0032b8c0 msys::MLyt::detachMChr (static)

// FUNC 0x14800650 ->ad::db::GetItemMsg (LoadMenu)
//   size 0x4 | file LoadMenu+0x650 | callers(1) 0x14806ac8
// veneer/thunk -> 0x0013a194 ad::db::GetItemMsg (static)

// FUNC 0x14800658 ->ad::db::GetUseItem (LoadMenu)
//   size 0x4 | file LoadMenu+0x658 | callers(1) 0x14806ac8
// veneer/thunk -> 0x00236398 ad::db::GetUseItem (static)

// FUNC 0x14800660 ->KJDB::Item::getData (LoadMenu)
//   size 0x4 | file LoadMenu+0x660 | callers(1) 0x14806ac8
// veneer/thunk -> 0x00361f94 KJDB::Item::getData (static)

// FUNC 0x14800668 ->MoveVBase::moveSinAbs (LoadMenu)
//   size 0x4 | file LoadMenu+0x668 | callers(1) 0x14806ac8
// veneer/thunk -> 0x0025d0a8 MoveVBase::moveSinAbs (static)

// FUNC 0x14800670 ->msys::MChrBaseCore::setParent (LoadMenu)
//   size 0x4 | file LoadMenu+0x670 | callers(1) 0x14806ac8
// veneer/thunk -> 0x003261b0 msys::MChrBaseCore::setParent (static)

// FUNC 0x14800678 ->ad::nfp::StopDetection (LoadMenu)
//   size 0x4 | file LoadMenu+0x678 | callers(5) 0x148080bc 0x14809874 0x1480a424 0x14809c1c 0x1480ad78
// veneer/thunk -> 0x0016541c ad::nfp::StopDetection (static)

// FUNC 0x14800680 ->msys::MLyt::term (LoadMenu)
//   size 0x4 | file LoadMenu+0x680 | callers(1) 0x14808224
// veneer/thunk -> 0x0032c3c8 msys::MLyt::term (static)

// FUNC 0x14800688 ->ad::fw::Resource::term (LoadMenu)
//   size 0x4 | file LoadMenu+0x688 | callers(4) 0x1480d720 0x14808224 0x1480be7c 0x1480baa4
// veneer/thunk -> 0x00233340 ad::fw::Resource::term (static)

// FUNC 0x14800690 ->ad::lyt::LytResourceMan::term (LoadMenu)
//   size 0x4 | file LoadMenu+0x690 | callers(1) 0x14808224
// veneer/thunk -> 0x00250938 ad::lyt::LytResourceMan::term (static)

// FUNC 0x14800698 ->Message::term (LoadMenu)
//   size 0x4 | file LoadMenu+0x698 | callers(3) 0x14808224 0x1480d834 0x1480d868
// veneer/thunk -> 0x0033dc68 Message::term (static)

// FUNC 0x148006a0 ->Message::~Message (LoadMenu)
//   size 0x4 | file LoadMenu+0x6a0 | callers(3) 0x14808224 0x1480d834 0x1480d868
// veneer/thunk -> 0x00206538 Message::~Message (static)

// FUNC 0x148006a8 ->ad::fw::Resource::~Resource (LoadMenu)
//   size 0x4 | file LoadMenu+0x6a8 | callers(2) 0x1480d720 0x14808224
// veneer/thunk -> 0x0024a104 ad::fw::Resource::~Resource (static)

// FUNC 0x148006b0 ->ad::font::ResFont::~ResFont (LoadMenu)
//   size 0x4 | file LoadMenu+0x6b0 | callers(1) 0x14808224
// veneer/thunk -> 0x002508a8 ad::font::ResFont::~ResFont (static)

// FUNC 0x148006b8 ->GameWork::getScenarioFlag (LoadMenu)
//   size 0x4 | file LoadMenu+0x6b8 | callers(1) 0x14808344
// veneer/thunk -> 0x002164c0 GameWork::getScenarioFlag (static)

// FUNC 0x148006c0 ->save_load::Summary::build (LoadMenu)
//   size 0x4 | file LoadMenu+0x6c0 | callers(1) 0x14808344
// veneer/thunk -> 0x16001ddc save_load::Summary::build (SaveLoad)

// FUNC 0x148006c8 ->save_load::SaveDateTime::init (LoadMenu)
//   size 0x4 | file LoadMenu+0x6c8 | callers(1) 0x148087d4
// veneer/thunk -> 0x1600187c save_load::SaveDateTime::init (SaveLoad)

// FUNC 0x148006d0 ->save_load::SaveDateTime::build (LoadMenu)
//   size 0x4 | file LoadMenu+0x6d0 | callers(1) 0x148088a4
// veneer/thunk -> 0x16001948 save_load::SaveDateTime::build (SaveLoad)

// FUNC 0x148006d8 ->msys::MCtrlUserData::findExtUserDataByName (LoadMenu)
//   size 0x4 | file LoadMenu+0x6d8 | callers(1) 0x1480891c
// veneer/thunk -> 0x0036203c msys::MCtrlUserData::findExtUserDataByName (static)

// FUNC 0x148006e0 ->ad::lyt::LytNumReel3::setValueInstant (LoadMenu)
//   size 0x4 | file LoadMenu+0x6e0 | callers(1) 0x14808bb4
// veneer/thunk -> 0x0020785c ad::lyt::LytNumReel3::setValueInstant (static)

// FUNC 0x148006e8 ->msys::MSndSe::play (LoadMenu)
//   size 0x4 | file LoadMenu+0x6e8 | callers(1) 0x14808d08
// veneer/thunk -> 0x0032d844 msys::MSndSe::play (static)

// FUNC 0x148006f0 ->LMS_GetTextIndexByLabel (LoadMenu)
//   size 0x4 | file LoadMenu+0x6f0 | callers(1) 0x14808da8
// veneer/thunk -> 0x0027616c LMS_GetTextIndexByLabel (static)

// FUNC 0x148006f8 ->LMS_GetText (LoadMenu)
//   size 0x4 | file LoadMenu+0x6f8 | callers(1) 0x14808da8
// veneer/thunk -> 0x0027660c LMS_GetText (static)

// FUNC 0x14800700 ->MoveVBase::MoveVBase (LoadMenu)
//   size 0x4 | file LoadMenu+0x700 | callers(1) 0x14808f5c
// veneer/thunk -> 0x00259740 MoveVBase::MoveVBase (static)

// FUNC 0x14800708 ->ad::font::ResFont::ResFont (LoadMenu)
//   size 0x4 | file LoadMenu+0x708 | callers(1) 0x1480925c
// veneer/thunk -> 0x0027542c ad::font::ResFont::ResFont (static)

// FUNC 0x14800710 ->ad::fw::Resource::Resource (LoadMenu)
//   size 0x4 | file LoadMenu+0x710 | callers(2) 0x1480d5e8 0x1480925c
// veneer/thunk -> 0x00250588 ad::fw::Resource::Resource (static)

// FUNC 0x14800718 ->Message::Message (LoadMenu)
//   size 0x4 | file LoadMenu+0x718 | callers(1) 0x1480925c
// veneer/thunk -> 0x00110d5c Message::Message (static)

// FUNC 0x14800720 ->VramAlcRange::merge (LoadMenu)
//   size 0x4 | file LoadMenu+0x720 | callers(1) 0x1480956c
// veneer/thunk -> 0x00102874 VramAlcRange::merge (static)

// FUNC 0x14800728 ->ad::nfp::IsValid (LoadMenu)
//   size 0x4 | file LoadMenu+0x728 | callers(6) 0x148099f8 0x14809654 0x1480c498 0x1480a3b8 0x1480b07c 0x1480ad0c
// veneer/thunk -> 0x00165940 ad::nfp::IsValid (static)

// FUNC 0x14800730 ->ad::nfp::IsInitialized (LoadMenu)
//   size 0x4 | file LoadMenu+0x730 | callers(5) 0x148099f8 0x14809654 0x1480c498 0x1480a3b8 0x1480ad0c
// veneer/thunk -> 0x001653e4 ad::nfp::IsInitialized (static)

// FUNC 0x14800738 ->nn::fnd::DateTime::GetNow (LoadMenu)
//   size 0x4 | file LoadMenu+0x738 | callers(1) 0x14809c1c
// veneer/thunk -> 0x00284cd8 nn::fnd::DateTime::GetNow (static)

// FUNC 0x14800740 ->nn::fnd::DateTime::GetParameters (LoadMenu)
//   size 0x4 | file LoadMenu+0x740 | callers(1) 0x14809c1c
// veneer/thunk -> 0x0027fe00 nn::fnd::DateTime::GetParameters (static)

// FUNC 0x14800748 ->GameWork::cmpNfpDate (LoadMenu)
//   size 0x4 | file LoadMenu+0x748 | callers(1) 0x14809c1c
// veneer/thunk -> 0x0033eaa0 GameWork::cmpNfpDate (static)

// FUNC 0x14800750 ->GameWork::setNfpDate (LoadMenu)
//   size 0x4 | file LoadMenu+0x750 | callers(1) 0x14809c1c
// veneer/thunk -> 0x0033eb18 GameWork::setNfpDate (static)

// FUNC 0x14800758 ->GameWork::isTimeFalsification (LoadMenu)
//   size 0x4 | file LoadMenu+0x758 | callers(1) 0x14809c1c
// veneer/thunk -> 0x0033ebb8 GameWork::isTimeFalsification (static)

// FUNC 0x14800760 ->nn::cfg::CTR::GetTransferableId (LoadMenu)
//   size 0x4 | file LoadMenu+0x760 | callers(1) 0x14809c1c
// veneer/thunk -> 0x001a39b0 nn::cfg::CTR::GetTransferableId (static)

// FUNC 0x14800768 ->strncmp (LoadMenu)
//   size 0x4 | file LoadMenu+0x768 | callers(1) 0x14809c1c
// veneer/thunk -> 0x0027848c strncmp (static)

// FUNC 0x14800770 ->nn::os::CTR::IsRunOnSnake (LoadMenu)
//   size 0x4 | file LoadMenu+0x770 | callers(2) 0x1480c720 0x14809654
// veneer/thunk -> 0x002844ac nn::os::CTR::IsRunOnSnake (static)

// FUNC 0x14800778 ->msys::MLyt::getAnim (LoadMenu)
//   size 0x4 | file LoadMenu+0x778 | callers(2) 0x1480c170 0x14809654
// veneer/thunk -> 0x0032c678 msys::MLyt::getAnim (static)

// FUNC 0x14800780 ->ad::lyt::LytAnim::stop (LoadMenu)
//   size 0x4 | file LoadMenu+0x780 | callers(2) 0x1480c170 0x14809654
// veneer/thunk -> 0x00251878 ad::lyt::LytAnim::stop (static)

// FUNC 0x14800788 ->ad::nfp::StartAmiiboSetting (LoadMenu)
//   size 0x4 | file LoadMenu+0x788 | callers(1) 0x1480b1c4
// veneer/thunk -> 0x001655fc ad::nfp::StartAmiiboSetting (static)

// FUNC 0x14800790 ->msys::MCAChr::applyAnime (LoadMenu)
//   size 0x4 | file LoadMenu+0x790 | callers(1) 0x1480b5bc
// veneer/thunk -> 0x0032cf0c msys::MCAChr::applyAnime (static)

// FUNC 0x14800798 ->msys::MCellAnime::updateAnimeFrm (LoadMenu)
//   size 0x4 | file LoadMenu+0x798 | callers(1) 0x1480b664
// veneer/thunk -> 0x00323e68 msys::MCellAnime::updateAnimeFrm (static)

// FUNC 0x148007a0 ->msys::MCAChr::init (LoadMenu)
//   size 0x4 | file LoadMenu+0x7a0 | callers(1) 0x1480b724
// veneer/thunk -> 0x0032d3b8 msys::MCAChr::init (static)

// FUNC 0x148007a8 ->MoveVBase::MoveVBase (LoadMenu)
//   size 0x4 | file LoadMenu+0x7a8 | callers(1) 0x1480b8a8
// veneer/thunk -> 0x00254838 MoveVBase::MoveVBase (static)

// FUNC 0x148007b0 ->__aeabi_memcpy4 (LoadMenu)
//   size 0x4 | file LoadMenu+0x7b0 | callers(1) 0x1480baa4
// veneer/thunk -> 0x00286f4c __aeabi_memcpy4 (static)

// FUNC 0x148007b8 ->operator.new[] (LoadMenu)
//   size 0x4 | file LoadMenu+0x7b8 | callers(1) 0x1480baa4
// veneer/thunk -> 0x00283558 operator.new[] (static)

// FUNC 0x148007c0 ->GameWork::addItem (LoadMenu)
//   size 0x4 | file LoadMenu+0x7c0 | callers(1) 0x1480baa4
// veneer/thunk -> 0x0033edc8 GameWork::addItem (static)

// FUNC 0x148007c8 ->operator.delete[] (LoadMenu)
//   size 0x4 | file LoadMenu+0x7c8 | callers(1) 0x1480baa4
// veneer/thunk -> 0x0028829c operator.delete[] (static)

// FUNC 0x148007d0 ->GameWork::preSaveGameWork (LoadMenu)
//   size 0x4 | file LoadMenu+0x7d0 | callers(2) 0x1480c5c4 0x1480c658
// veneer/thunk -> 0x0033eb48 GameWork::preSaveGameWork (static)

// FUNC 0x148007d8 ->Backup::writeSaveData1 (LoadMenu)
//   size 0x4 | file LoadMenu+0x7d8 | callers(1) 0x1480c5c4
// veneer/thunk -> 0x00339b44 Backup::writeSaveData1 (static)

// FUNC 0x148007e0 ->Backup::writeSaveData (LoadMenu)
//   size 0x4 | file LoadMenu+0x7e0 | callers(1) 0x1480c658
// veneer/thunk -> 0x00339878 Backup::writeSaveData (static)

// FUNC 0x148007e8 ->ad::nfp::Initialize (LoadMenu)
//   size 0x4 | file LoadMenu+0x7e8 | callers(1) 0x1480c720
// veneer/thunk -> 0x001651a8 ad::nfp::Initialize (static)

// FUNC 0x148007f0 ->msys::MDfxChr::MDfxChr (LoadMenu)
//   size 0x4 | file LoadMenu+0x7f0 | callers(1) 0x1480c720
// veneer/thunk -> 0x0033137c msys::MDfxChr::MDfxChr (static)

// FUNC 0x148007f8 ->ad::nfp::Finalize (LoadMenu)
//   size 0x4 | file LoadMenu+0x7f8 | callers(2) 0x1480c910 0x1480c9e4
// veneer/thunk -> 0x00165964 ad::nfp::Finalize (static)

// FUNC 0x14800800 ->KJDB::Chr::getData (LoadMenu)
//   size 0x4 | file LoadMenu+0x800 | callers(1) 0x1480cb00
// veneer/thunk -> 0x002529a8 KJDB::Chr::getData (static)

// FUNC 0x14800808 ->save_load::SaveLoadSys::funcCalcLoadData (LoadMenu)
//   size 0x4 | file LoadMenu+0x808 | callers(1) 0x1480cd44
// veneer/thunk -> 0x16000918 save_load::SaveLoadSys::funcCalcLoadData (SaveLoad)

// FUNC 0x14800810 ->ad::fw::TaskBase::readArcFile (LoadMenu)
//   size 0x4 | file LoadMenu+0x810 | callers(2) 0x1480cd44 0x1480cf38
// veneer/thunk -> 0x00251e8c ad::fw::TaskBase::readArcFile (static)

// FUNC 0x14800818 ->MsgDataAcsrBase::init (LoadMenu)
//   size 0x4 | file LoadMenu+0x818 | callers(2) 0x1480cf38 0x1480ce54
// veneer/thunk -> 0x00285b88 MsgDataAcsrBase::init (static)

// FUNC 0x14800820 ->save_load::SaveLoadSys::funcCalcCreateChr (LoadMenu)
//   size 0x4 | file LoadMenu+0x820 | callers(2) 0x1480cf38 0x1480ce54
// veneer/thunk -> 0x16000c58 save_load::SaveLoadSys::funcCalcCreateChr (SaveLoad)

// FUNC 0x14800828 ->msys::MLytNumRes::init (LoadMenu)
//   size 0x4 | file LoadMenu+0x828 | callers(2) 0x1480cf38 0x1480ce54
// veneer/thunk -> 0x003240f4 msys::MLytNumRes::init (static)

// FUNC 0x14800830 ->msys::MComSys::initBaseSys (LoadMenu)
//   size 0x4 | file LoadMenu+0x830 | callers(1) 0x1480d430
// veneer/thunk -> 0x0032db84 msys::MComSys::initBaseSys (static)

// FUNC 0x14800838 ->SndSys::start (LoadMenu)
//   size 0x4 | file LoadMenu+0x838 | callers(1) 0x1480d430
// veneer/thunk -> 0x0033c77c SndSys::start (static)

// FUNC 0x14800840 ->msys::MComSys::entryPage (LoadMenu)
//   size 0x4 | file LoadMenu+0x840 | callers(1) 0x1480d430
// veneer/thunk -> 0x0032f548 msys::MComSys::entryPage (static)

// FUNC 0x14800848 ->Prim::enableDepthTest (LoadMenu)
//   size 0x4 | file LoadMenu+0x848 | callers(1) 0x1480d430
// veneer/thunk -> 0x0026cce8 Prim::enableDepthTest (static)

// FUNC 0x14800850 ->CtrJobMan::enqueue (LoadMenu)
//   size 0x4 | file LoadMenu+0x850 | callers(1) 0x1480d430
// veneer/thunk -> 0x0026dbe8 CtrJobMan::enqueue (static)

// FUNC 0x14800858 ->msys::MComSys::setupCamU (LoadMenu)
//   size 0x4 | file LoadMenu+0x858 | callers(1) 0x1480d430
// veneer/thunk -> 0x0032f674 msys::MComSys::setupCamU (static)

// FUNC 0x14800860 ->msys::MComSys::setupCamL (LoadMenu)
//   size 0x4 | file LoadMenu+0x860 | callers(1) 0x1480d430
// veneer/thunk -> 0x0032f570 msys::MComSys::setupCamL (static)

// FUNC 0x14800868 ->save_load::SaveLoadSys::SaveLoadSys (LoadMenu)
//   size 0x4 | file LoadMenu+0x868 | callers(1) 0x1480d5e8
// veneer/thunk -> 0x1600150c save_load::SaveLoadSys::SaveLoadSys (SaveLoad)

// FUNC 0x14800870 ->MsgDataAcsrBase::MsgDataAcsrBase (LoadMenu)
//   size 0x4 | file LoadMenu+0x870 | callers(1) 0x1480d5e8
// veneer/thunk -> 0x0024b3b8 MsgDataAcsrBase::MsgDataAcsrBase (static)

// FUNC 0x14800878 ->KJDB::Create (LoadMenu)
//   size 0x4 | file LoadMenu+0x878 | callers(1) 0x1480d5e8
// veneer/thunk -> 0x003234e8 KJDB::Create (static)

// FUNC 0x14800880 ->SndSys::stop (LoadMenu)
//   size 0x4 | file LoadMenu+0x880 | callers(1) 0x1480d720
// veneer/thunk -> 0x0024dd04 SndSys::stop (static)

// FUNC 0x14800888 ->GameMain::NowInfo (LoadMenu)
//   size 0x4 | file LoadMenu+0x888 | callers(1) 0x1480d720
// veneer/thunk -> 0x0033e954 GameMain::NowInfo (static)

// FUNC 0x14800890 ->KJDB::Destroy (LoadMenu)
//   size 0x4 | file LoadMenu+0x890 | callers(1) 0x1480d720
// veneer/thunk -> 0x003235cc KJDB::Destroy (static)

// FUNC 0x14800898 ->save_load::SaveLoadSys::~SaveLoadSys (LoadMenu)
//   size 0x4 | file LoadMenu+0x898 | callers(1) 0x1480d720
// veneer/thunk -> 0x16001648 save_load::SaveLoadSys::~SaveLoadSys (SaveLoad)

// FUNC 0x148008a0 ->ad::fw::FileContext::initSingleFile (LoadMenu)
//   size 0x4 | file LoadMenu+0x8a0 | callers(1) 0x1480da44
// veneer/thunk -> 0x0013ad54 ad::fw::FileContext::initSingleFile (static)

// FUNC 0x148008a8 ->ad::fw::FileContext::initArcFile (LoadMenu)
//   size 0x4 | file LoadMenu+0x8a8 | callers(1) 0x1480da44
// veneer/thunk -> 0x0013aca8 ad::fw::FileContext::initArcFile (static)

// FUNC 0x148008b0 ->ad::fw::FileContext::initCAArcFile (LoadMenu)
//   size 0x4 | file LoadMenu+0x8b0 | callers(1) 0x1480da44
// veneer/thunk -> 0x0013acc0 ad::fw::FileContext::initCAArcFile (static)

// FUNC 0x148008b8 ->msys::MCursorBase::init (LoadMenu)
//   size 0x4 | file LoadMenu+0x8b8 | callers(1) 0x1480daf8
// veneer/thunk -> 0x00324464 msys::MCursorBase::init (static)

// FUNC 0x148008c0 LoadMenu::EntryTask (LoadMenu)
//   size 0x34 | file LoadMenu+0x8c0 | callers(0)

void LoadMenu::EntryTask(void)

{
  void *pvVar1;
  Task *pTVar2;
  
  pvVar1 = operator_new(0xfd690,gMemAlc,(char *)0x0,0);
  pTVar2 = (Task *)0x0;
  if (pvVar1 != (void *)0x0) {
    pTVar2 = (Task *)FUN_14801b50();
  }
  TaskMan::entry((TaskMan *)&gTaskMainMan,pTVar2);
  return;
}


// FUNC 0x14800900 FUN_14800900 (LoadMenu)
//   size 0x200 | file LoadMenu+0x900 | callers(2) 0x14801480 0x148015c8

undefined1 * FUN_14800900(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  float fVar7;
  
  uVar1 = param_2 + 0x20;
  uVar5 = (param_3 & 0xf) << 0x1b;
  uVar4 = *(uint *)(param_2 + 4);
  bVar6 = *(char *)(param_2 + 0x9d) == '\0';
  if ((*(byte *)(param_2 + 0xa3) & 1) == 0) {
    if (bVar6) {
      FUN_14809048();
      uVar1 = 0;
    }
    else {
      fVar7 = *(float *)(param_1 + 0x4da1c) +
              *(float *)(param_2 + 0x2c) * *(float *)(param_1 + 0x4da10) +
              *(float *)(param_2 + 0x3c) * *(float *)(param_1 + 0x4da14) +
              *(float *)(param_2 + 0x4c) * *(float *)(param_1 + 0x4da18);
      fVar7 = (*(float *)(param_1 + 0x4da4c) + fVar7 * *(float *)(param_1 + 0x4da48)) /
              (*(float *)(param_1 + 0x4da5c) + fVar7 * *(float *)(param_1 + 0x4da58));
      if ((uint)fVar7 < 0xbf800001) {
        if (0.0 < fVar7) {
          fVar7 = 0.0;
        }
      }
      else {
        fVar7 = -1.0;
      }
      uVar1 = VectorFloatToUnsigned((fVar7 + 1.0) * 16777215.0,3);
    }
  }
  else {
    if (bVar6) {
      uVar1 = 0;
    }
    if (!bVar6) {
      fVar7 = (*(float *)(param_1 + 0x4da4c) +
              -*(float *)(param_2 + 0x4c) * *(float *)(param_1 + 0x4da48)) /
              (*(float *)(param_1 + 0x4da5c) +
              -*(float *)(param_2 + 0x4c) * *(float *)(param_1 + 0x4da58));
      if ((uint)fVar7 < 0xbf800001) {
        if (0.0 < fVar7) {
          fVar7 = 0.0;
        }
      }
      else {
        fVar7 = -1.0;
      }
      uVar1 = VectorFloatToUnsigned((fVar7 + 1.0) * 16777215.0,3);
    }
  }
  if (bVar6) {
    uVar1 = uVar5 | 0x1000000 | uVar4 & 0xffffff;
  }
  else {
    uVar1 = (uVar1 & 0xffffff) << 3 | uVar5 | 0x80000000 | 1;
  }
  puVar2 = (undefined1 *)FUN_14800b14(param_1);
  uVar3 = (**(code **)(**(int **)(param_1 + 0xe0) + 0x10))();
  *puVar2 = 1;
  *(undefined4 *)(puVar2 + 0x18) = uVar3;
  *(uint *)(puVar2 + 4) = uVar1;
  *(int *)(puVar2 + 8) = param_2;
  *(undefined4 *)(puVar2 + 0x14) = 0;
  *(undefined4 *)(puVar2 + 0x10) = 0;
  *(undefined4 *)(puVar2 + 0xc) = 0;
  return puVar2;
}


// FUNC 0x14800b14 FUN_14800b14 (LoadMenu)
//   size 0x850 | file LoadMenu+0xb14 | callers(1) 0x14800900

/* WARNING: Removing unreachable block (ram,0x14801140) */
/* WARNING: Removing unreachable block (ram,0x14801144) */
/* WARNING: Removing unreachable block (ram,0x14801150) */
/* WARNING: Removing unreachable block (ram,0x14800c8c) */
/* WARNING: Removing unreachable block (ram,0x14800c54) */
/* WARNING: Removing unreachable block (ram,0x14800c5c) */
/* WARNING: Removing unreachable block (ram,0x14800c68) */
/* WARNING: Removing unreachable block (ram,0x14800d34) */
/* WARNING: Removing unreachable block (ram,0x14800d3c) */
/* WARNING: Removing unreachable block (ram,0x14800d48) */
/* WARNING: Removing unreachable block (ram,0x14800d68) */
/* WARNING: Removing unreachable block (ram,0x14800e2c) */
/* WARNING: Removing unreachable block (ram,0x14801070) */
/* WARNING: Removing unreachable block (ram,0x148011f0) */
/* WARNING: Removing unreachable block (ram,0x148011f4) */
/* WARNING: Removing unreachable block (ram,0x14801200) */
/* WARNING: Removing unreachable block (ram,0x14801350) */
/* WARNING: Removing unreachable block (ram,0x14800e78) */
/* WARNING: Removing unreachable block (ram,0x1480108c) */
/* WARNING: Removing unreachable block (ram,0x14800cb0) */
/* WARNING: Removing unreachable block (ram,0x14800d90) */
/* WARNING: Removing unreachable block (ram,0x14801360) */
/* WARNING: Removing unreachable block (ram,0x14801328) */
/* WARNING: Removing unreachable block (ram,0x14801174) */
/* WARNING: Removing unreachable block (ram,0x14801228) */
/* WARNING: Removing unreachable block (ram,0x14800f98) */
/* WARNING: Removing unreachable block (ram,0x14800e8c) */
/* WARNING: Removing unreachable block (ram,0x14800f70) */
/* WARNING: Removing unreachable block (ram,0x14800dfc) */
/* WARNING: Removing unreachable block (ram,0x14800e60) */
/* WARNING: Removing unreachable block (ram,0x14800e4c) */

int FUN_14800b14(int param_1)

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
    goto LAB_14801090;
  }
  pMVar5 = *(MemAlcBase **)(param_1 + 4);
  pcVar6 = *(char **)(param_1 + 8);
  uVar2 = *(uint *)(param_1 + 0xc);
  local_2c = (undefined4 *)0x0;
  local_28 = 0;
  if (uVar9 == 0) goto LAB_14800d94;
  uVar11 = *(int *)(param_1 + 0x1c) * 2;
  if (uVar9 < uVar11) {
    if (pMVar5 == (MemAlcBase *)0x0) {
      if (uVar11 != 0) goto LAB_14800cbc;
    }
    else {
      uVar11 = *(int *)(param_1 + 0x1c) * 0x38;
      local_2c = operator_new(uVar11,pMVar5,pcVar6,uVar2);
      if (local_2c == (undefined4 *)0x0) goto LAB_14800cbc;
      local_28 = (uint)((ulonglong)uVar11 * 0x49249249 + 0x49249249 >> 0x23);
    }
LAB_14800d94:
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
LAB_14800cbc:
    if (pMVar5 != (MemAlcBase *)0x0) {
      local_2c = operator_new(uVar9 * 0x1c,pMVar5,pcVar6,uVar2);
      if (local_2c != (undefined4 *)0x0) {
        local_28 = (uint)((ulonglong)(uVar9 * 0x1c) * 0x49249249 + 0x49249249 >> 0x23);
        goto LAB_14800d94;
      }
    }
  }
LAB_14801090:
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
  if (uVar2 == 0) goto LAB_1480122c;
  if (uVar2 < uVar9 * 2) {
    if (pMVar5 == (MemAlcBase *)0x0) {
      if (uVar9 * 2 == 0) goto LAB_1480122c;
    }
    else {
      local_2c = operator_new(uVar9 << 3,pMVar5,pcVar6,uVar11);
      if (local_2c != (int *)0x0) {
        local_28 = (uVar9 & 0x1fffffff) << 1;
        goto LAB_1480122c;
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
LAB_1480122c:
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


// FUNC 0x1480136c FUN_1480136c (LoadMenu)
//   size 0x10 | file LoadMenu+0x136c | callers(0) | datarefs 1

void FUN_1480136c(MsgDataAcsrBase *param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)MsgDataAcsrBase::~MsgDataAcsrBase(param_1);
  operator_delete(pvVar1);
  return;
}


// FUNC 0x1480137c ->MsgDataAcsrBase::~MsgDataAcsrBase (LoadMenu)
//   size 0x4 | file LoadMenu+0x137c | callers(0) | datarefs 1
// veneer/thunk -> 0x0026fdb4 MsgDataAcsrBase::~MsgDataAcsrBase (static)

// FUNC 0x14801380 FUN_14801380 (LoadMenu)
//   size 0xc | file LoadMenu+0x1380 | callers(0) | datarefs 1

void FUN_14801380(int *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x14801388. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x14))();
  return;
}


// FUNC 0x1480138c load_menu::LoadMenuTask::vfunc_0x1c (LoadMenu)
//   size 0x4 | file LoadMenu+0x138c | callers(0) | datarefs 1

void load_menu::LoadMenuTask::vfunc_0x1c(void)

{
  return;
}


// FUNC 0x14801390 load_menu::LoadMenuTask::vfunc_0x4c (LoadMenu)
//   size 0x8 | file LoadMenu+0x1390 | callers(0) | datarefs 1

undefined4 * load_menu::LoadMenuTask::vfunc_0x4c(void)

{
  return &gFrameBuf;
}


// FUNC 0x1480139c load_menu::LoadMenuTask::vfunc_0x3c (LoadMenu)
//   size 0x4 | file LoadMenu+0x139c | callers(0) | datarefs 1

void load_menu::LoadMenuTask::vfunc_0x3c(void)

{
  return;
}


// FUNC 0x148013a0 load_menu::LoadMenuTask::vfunc_0x40 (LoadMenu)
//   size 0x4 | file LoadMenu+0x13a0 | callers(0) | datarefs 1

void load_menu::LoadMenuTask::vfunc_0x40(void)

{
  return;
}


// FUNC 0x148013a4 load_menu::LoadMenuTask::vfunc_0x30 (LoadMenu)
//   size 0x4 | file LoadMenu+0x13a4 | callers(0) | datarefs 1

void load_menu::LoadMenuTask::vfunc_0x30(void)

{
  return;
}


// FUNC 0x148013a8 load_menu::LoadMenuTask::vfunc_0x20 (LoadMenu)
//   size 0x4 | file LoadMenu+0x13a8 | callers(0) | datarefs 1

void load_menu::LoadMenuTask::vfunc_0x20(void)

{
  return;
}


// FUNC 0x148013ac load_menu::LoadMenuTask::vfunc_0x38 (LoadMenu)
//   size 0x4 | file LoadMenu+0x13ac | callers(0) | datarefs 1

void load_menu::LoadMenuTask::vfunc_0x38(void)

{
  return;
}


// FUNC 0x148013b0 load_menu::LoadMenuTask::vfunc_0x28 (LoadMenu)
//   size 0x4 | file LoadMenu+0x13b0 | callers(0) | datarefs 1

void load_menu::LoadMenuTask::vfunc_0x28(void)

{
  return;
}


// FUNC 0x14801440 load_menu::LoadMenuTask::vfunc_0xc (LoadMenu)
//   size 0xc | file LoadMenu+0x1440 | callers(0) | datarefs 1

void load_menu::LoadMenuTask::vfunc_0xc(int *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x14801448. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 8))();
  return;
}


// FUNC 0x1480144c FUN_1480144c (LoadMenu)
//   size 0xc | file LoadMenu+0x144c | callers(0) | datarefs 2

byte FUN_1480144c(int param_1)

{
  return *(byte *)(param_1 + 0x16a) & 1;
}


// FUNC 0x14801458 load_menu::LoadMenuTopPage::Core::SaveGameInfo::FilePanelKJ::KJObj::vfunc_0x3c (LoadMenu)
//   size 0x20 | file LoadMenu+0x1458 | callers(0) | datarefs 1

void load_menu::LoadMenuTopPage::Core::SaveGameInfo::FilePanelKJ::KJObj::vfunc_0x3c
               (int param_1,int param_2)

{
  byte bVar1;
  byte *pbVar2;
  byte bVar3;
  
  pbVar2 = (byte *)(param_1 + 0x1ef);
  bVar1 = *pbVar2;
  if (param_2 == 0) {
    bVar3 = bVar1 & 0xfd | 1;
  }
  else {
    bVar3 = bVar1 | 3;
  }
  *pbVar2 = bVar1 | 1;
  *pbVar2 = bVar3;
  return;
}


// FUNC 0x14801478 load_menu::LoadMenuTopPage::Core::SaveGameInfo::FilePanelKJ::KJObj::vfunc_0x38 (LoadMenu)
//   size 0x8 | file LoadMenu+0x1478 | callers(0) | datarefs 1

void load_menu::LoadMenuTopPage::Core::SaveGameInfo::FilePanelKJ::KJObj::vfunc_0x38(int param_1)

{
  CellAnime::term((CellAnime *)(param_1 + 0x14c));
  return;
}


// FUNC 0x14801480 load_menu::LoadMenuTopPage::Core::SaveGameInfo::FilePanelKJ::KJObj::vfunc_0x14 (LoadMenu)
//   size 0x18 | file LoadMenu+0x1480 | callers(0) | datarefs 1

void load_menu::LoadMenuTopPage::Core::SaveGameInfo::FilePanelKJ::KJObj::vfunc_0x14
               (int param_1,undefined4 param_2)

{
  FUN_14800900(param_2,param_1 + 0x14c);
  return;
}


// FUNC 0x14801498 msys::MChrBase::vfunc_0x10 (LoadMenu)
//   size 0xc | file LoadMenu+0x1498 | callers(0) | datarefs 2

void msys::MChrBase::vfunc_0x10(int param_1)

{
  *(undefined1 *)(param_1 + 0x142) = 0;
  return;
}


// FUNC 0x148014a4 FUN_148014a4 (LoadMenu)
//   size 0x4 | file LoadMenu+0x14a4 | callers(0) | datarefs 7

void FUN_148014a4(void)

{
  return;
}


// FUNC 0x148014a8 msys::MChrBase::vfunc_0x8 (LoadMenu)
//   size 0xc | file LoadMenu+0x14a8 | callers(0) | datarefs 1

void msys::MChrBase::vfunc_0x8(int param_1)

{
  *(undefined1 *)(param_1 + 0x142) = 1;
  return;
}


// FUNC 0x148014b4 FUN_148014b4 (LoadMenu)
//   size 0x4 | file LoadMenu+0x14b4 | callers(0) | datarefs 7

void FUN_148014b4(void)

{
  return;
}


// FUNC 0x148014b8 load_menu::LoadMenuTopPage::Core::GameSelectU::vfunc_0x20 (LoadMenu)
//   size 0x8 | file LoadMenu+0x14b8 | callers(0) | datarefs 1

undefined4 load_menu::LoadMenuTopPage::Core::GameSelectU::vfunc_0x20(void)

{
  return 0;
}


// FUNC 0x148014c0 load_menu::LoadMenuTopPage::Core::GameSelectU::vfunc_0x38 (LoadMenu)
//   size 0x4 | file LoadMenu+0x14c0 | callers(0) | datarefs 1

void load_menu::LoadMenuTopPage::Core::GameSelectU::vfunc_0x38(void)

{
  return;
}


// FUNC 0x148014c4 load_menu::LoadMenuTopPage::Core::GameSelectU::vfunc_0x14 (LoadMenu)
//   size 0x2c | file LoadMenu+0x14c4 | callers(0) | datarefs 1

void load_menu::LoadMenuTopPage::Core::GameSelectU::vfunc_0x14
               (int param_1,MRenderQueueBase *param_2)

{
  if (*(char *)(param_1 + 0x141) == '\0') {
    return;
  }
  msys::MRenderQueueBase::enqueueMsg
            (param_2,(MessageSimple *)(param_1 + 0x14c),*(uint *)(param_1 + 0x6c40),'\n');
  return;
}


// FUNC 0x148014f4 FUN_148014f4 (LoadMenu)
//   size 0x44 | file LoadMenu+0x14f4 | callers(0) | datarefs 1

int FUN_148014f4(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)FUN_14808f5c();
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


// FUNC 0x1480153c FUN_1480153c (LoadMenu)
//   size 0x2c | file LoadMenu+0x153c | callers(0) | datarefs 2

void FUN_1480153c(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar1 = MessageSimple::~MessageSimple((MessageSimple *)(param_1 + 0x53));
  msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  return;
}


// FUNC 0x1480156c load_menu::LoadMenuAmiiboPage::Core::ItemMan::CAChr::vfunc_0x3c (LoadMenu)
//   size 0x40 | file LoadMenu+0x156c | callers(0) | datarefs 1

void load_menu::LoadMenuAmiiboPage::Core::ItemMan::CAChr::vfunc_0x3c(int param_1,int param_2)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  
  bVar3 = *(byte *)(param_1 + 0x1ef);
  if (param_2 != 0) {
    bVar2 = bVar3 | 3;
  }
  else {
    bVar2 = bVar3 & 0xfd | 1;
  }
  *(byte *)(param_1 + 0x1ef) = bVar3 | 1;
  *(byte *)(param_1 + 0x1ef) = bVar2;
  pbVar1 = (byte *)(param_1 + 0x39f);
  bVar3 = *pbVar1;
  *pbVar1 = bVar3 | 1;
  if (param_2 != 0) {
    bVar3 = bVar3 | 3;
  }
  else {
    bVar3 = bVar3 & 0xfd | 1;
  }
  *pbVar1 = bVar3;
  return;
}


// FUNC 0x148015ac load_menu::LoadMenuAmiiboPage::Core::ItemMan::CAChr::vfunc_0x44 (LoadMenu)
//   size 0x1c | file LoadMenu+0x15ac | callers(0) | datarefs 1

void load_menu::LoadMenuAmiiboPage::Core::ItemMan::CAChr::vfunc_0x44(int param_1)

{
  *(byte *)(param_1 + 0x1ef) = *(byte *)(param_1 + 0x1ef) & 0xfc;
  *(byte *)(param_1 + 0x39f) = *(byte *)(param_1 + 0x39f) & 0xfc;
  return;
}


// FUNC 0x148015c8 load_menu::LoadMenuAmiiboPage::Core::ItemMan::CAChr::vfunc_0x14 (LoadMenu)
//   size 0x30 | file LoadMenu+0x15c8 | callers(0) | datarefs 1

void load_menu::LoadMenuAmiiboPage::Core::ItemMan::CAChr::vfunc_0x14
               (int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_14800900(param_2,param_1 + 0x2fc);
  FUN_14800900(param_2,param_1 + 0x14c,param_3);
  return;
}


// FUNC 0x148015f8 load_menu::LoadMenu::vfunc_0x14 (LoadMenu)
//   size 0x8 | file LoadMenu+0x15f8 | callers(0) | datarefs 1

undefined4 load_menu::LoadMenu::vfunc_0x14(void)

{
  return 0;
}


// FUNC 0x14801600 load_menu::LoadMenuPageBase::Core::Dfx::vfunc_0x20 (LoadMenu)
//   size 0x54 | file LoadMenu+0x1600 | callers(0) | datarefs 1

undefined4 load_menu::LoadMenuPageBase::Core::Dfx::vfunc_0x20(int *param_1)

{
  int iVar1;
  uint uVar2;
  bool bVar3;
  
  iVar1 = (**(code **)(*param_1 + 0x24))(param_1);
  if (iVar1 != 0) {
    return 1;
  }
  uVar2 = param_1[0x55];
  if (uVar2 != 0) {
    bVar3 = *(int *)(uVar2 + 4) == uVar2 + 4;
    if (bVar3) {
      uVar2 = (uint)*(byte *)(uVar2 + 0x172);
    }
    if (!bVar3 || uVar2 != 0) {
      return 1;
    }
  }
  return 0;
}


// FUNC 0x14801654 load_menu::LoadMenuPageBase::Core::Dfx::vfunc_0x8 (LoadMenu)
//   size 0x40 | file LoadMenu+0x1654 | callers(0) | datarefs 1

void load_menu::LoadMenuPageBase::Core::Dfx::vfunc_0x8(float param_1,int param_2)

{
  MoveVBase::update((MoveVBase *)(param_2 + 0x14),param_1);
  MoveVBase::update((MoveVBase *)(param_2 + 0x70),param_1);
  MoveVBase::update((MoveVBase *)(param_2 + 0xcc),param_1);
  *(undefined1 *)(param_2 + 0x142) = 1;
  return;
}


// FUNC 0x14801694 load_menu::LoadMenuPageBase::Core::Dfx::vfunc_0x18 (LoadMenu)
//   size 0x4 | file LoadMenu+0x1694 | callers(0) | datarefs 1

void load_menu::LoadMenuPageBase::Core::Dfx::vfunc_0x18(void)

{
  return;
}


// FUNC 0x14801698 load_menu::LoadMenuPageBase::Core::Dfx::vfunc_0x14 (LoadMenu)
//   size 0x98 | file LoadMenu+0x1698 | callers(0) | datarefs 1

void load_menu::LoadMenuPageBase::Core::Dfx::vfunc_0x14(MChrBaseCore *param_1,int *param_2)

{
  uint uVar1;
  
  if (*(int *)(param_1 + 0x154) == 0) {
    return;
  }
  uVar1 = msys::MChrBaseCore::getDisplayID(param_1);
  msys::MDfxSys::run_and_package
            (*(MDfxSys **)(param_1 + 0x164),*(MDfxUnit **)(param_1 + 0x154),
             *(TRenderingInfoPackager **)(param_1 + 0x174),
             *(TRenderingInfoPackager **)(param_1 + 0x178),(MTX34 *)(param_2 + 0x1367c),
             (MTX44 *)(param_2 + 0x13688),uVar1);
  (**(code **)(*param_2 + 0xc))(param_2,*(undefined4 *)(param_1 + 0x174),10);
                    /* WARNING: Could not recover jumptable at 0x14801724. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_2 + 0x10))(param_2,*(undefined4 *)(param_1 + 0x178),0,10);
  return;
}


// FUNC 0x14801730 save_load::MsgWnd::vfunc_0x20 (LoadMenu)
//   size 0x8 | file LoadMenu+0x1730 | callers(0) | datarefs 1

undefined4 save_load::MsgWnd::vfunc_0x20(void)

{
  return 0;
}


// FUNC 0x14801738 save_load::MsgWnd::vfunc_0x8 (LoadMenu)
//   size 0xd0 | file LoadMenu+0x1738 | callers(0) | datarefs 1

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


// FUNC 0x14801810 save_load::MsgWnd::vfunc_0x38 (LoadMenu)
//   size 0x4 | file LoadMenu+0x1810 | callers(0) | datarefs 1

void save_load::MsgWnd::vfunc_0x38(void)

{
  return;
}


// FUNC 0x14801814 save_load::MsgWnd::vfunc_0x14 (LoadMenu)
//   size 0x2c | file LoadMenu+0x1814 | callers(0) | datarefs 1

void save_load::MsgWnd::vfunc_0x14(int param_1,MRenderQueueBase *param_2)

{
  if (*(char *)(param_1 + 0x141) == '\0') {
    return;
  }
  msys::MRenderQueueBase::enqueueMsg
            (param_2,(MessageSimple *)(param_1 + 0x14c),*(uint *)(param_1 + 0x6ef4),'\n');
  return;
}


// FUNC 0x14801844 msys::MChrBase::vfunc_0x4 (LoadMenu)
//   size 0x10 | file LoadMenu+0x1844 | callers(0) | datarefs 1

void msys::MChrBase::vfunc_0x4(void)

{
  void *pvVar1;
  
  pvVar1 = (void *)vfunc_0x0();
  operator_delete(pvVar1);
  return;
}


// FUNC 0x14801854 load_menu::LoadMenuTopPage::Core::GameSelectU::vfunc_0x10 (LoadMenu)
//   size 0x58 | file LoadMenu+0x1854 | callers(0) | datarefs 1

void load_menu::LoadMenuTopPage::Core::GameSelectU::vfunc_0x10(MMsg *param_1)

{
  msys::MMsg::applyAnime(param_1);
  *(float *)(param_1 + 0x5c00) = *(float *)(param_1 + 0x5c00) + *(float *)(param_1 + 0x6c58);
  *(float *)(param_1 + 0x5c04) = *(float *)(param_1 + 0x5c04) + *(float *)(param_1 + 0x6c5c);
  if (((byte)param_1[0x5988] & 1) == 0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x148018a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)(param_1 + 0x14c) + 0x28))();
  return;
}


// FUNC 0x148018b0 load_menu::LoadMenuTopPage::Core::GameSelectU::vfunc_0x3c (LoadMenu)
//   size 0x40 | file LoadMenu+0x18b0 | callers(0) | datarefs 1

void load_menu::LoadMenuTopPage::Core::GameSelectU::vfunc_0x3c
               (MMsg *param_1,wchar_t *param_2,InsParam *param_3,bool param_4)

{
  undefined4 *puVar1;
  
  msys::MMsg::playStr(param_1,param_2,param_3,param_4);
  puVar1 = (undefined4 *)FUN_14809048();
  *(undefined4 *)(param_1 + 0x6c58) = *puVar1;
  *(undefined4 *)(param_1 + 0x6c5c) = puVar1[1];
  *(undefined4 *)(param_1 + 0x6c60) = puVar1[2];
  param_1[0x5c08] = (MMsg)0x0;
  return;
}


// FUNC 0x148018f4 load_menu::LoadMenuPageBase::vfunc_0x20 (LoadMenu)
//   size 0x8 | file LoadMenu+0x18f4 | callers(0) | datarefs 3

void load_menu::LoadMenuPageBase::vfunc_0x20
               (MPageBase *param_1,undefined4 param_2,MRenderQueue *param_3)

{
  msys::MPageBase::enqueueLowerChr(param_1,param_3);
  return;
}


// FUNC 0x148018fc load_menu::LoadMenuPageBase::vfunc_0x1c (LoadMenu)
//   size 0x8 | file LoadMenu+0x18fc | callers(0) | datarefs 3

void load_menu::LoadMenuPageBase::vfunc_0x1c
               (MPageBase *param_1,undefined4 param_2,MRenderQueue *param_3)

{
  msys::MPageBase::enqueueUpperChr(param_1,param_3);
  return;
}


// FUNC 0x14801904 FUN_14801904 (LoadMenu)
//   size 0x34 | file LoadMenu+0x1904 | callers(0) | datarefs 1

void FUN_14801904(MoveVBase *param_1)

{
  void *pvVar1;
  
  *(undefined ***)param_1 = &vtable_for_5MoveVILj1EE;
  __aeabi_vec_dtor(param_1 + 0x30,MoveWorkF::~MoveWorkF,0x2c,1);
  pvVar1 = (void *)MoveVBase::~MoveVBase(param_1);
  operator_delete(pvVar1);
  return;
}


// FUNC 0x14801940 FUN_14801940 (LoadMenu)
//   size 0x30 | file LoadMenu+0x1940 | callers(0) | datarefs 1

void FUN_14801940(MoveVBase *param_1)

{
  *(undefined ***)param_1 = &vtable_for_5MoveVILj1EE;
  __aeabi_vec_dtor(param_1 + 0x30,MoveWorkF::~MoveWorkF,0x2c,1);
  MoveVBase::~MoveVBase(param_1);
  return;
}


// FUNC 0x14801978 FUN_14801978 (LoadMenu)
//   size 0x174 | file LoadMenu+0x1978 | callers(1) 0x14809c1c

undefined4 FUN_14801978(TagData *param_1)

{
  TagData TVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar2 = ad::nfp::GetNewResult();
  if (iVar2 != 0) {
    return 6;
  }
  iVar2 = ad::nfp::GetState();
  if (param_1[0x21d] != (TagData)0x0) goto LAB_14801a98;
  iVar3 = ad::nfp::IsStartDetection();
  if (iVar3 != 0) {
    return 0;
  }
  iVar3 = ad::nfp::IsStopDetection();
  if (iVar3 != 0) {
    param_1[0x21d] = (TagData)0x0;
    ad::nfp::StartDetection(1);
    return 0;
  }
  ad::nfp::GetTagData(param_1);
  if (*param_1 == (TagData)0x3) {
    return 0;
  }
  if (*param_1 != (TagData)0x0) {
    iVar3 = ad::nfp::GetCharacterIDBase(param_1);
    if (iVar3 == 6) {
      iVar3 = 5;
LAB_14801a74:
      param_1[0x21c] = SUB41(iVar3,0);
    }
    else {
      if (6 < iVar3) {
        if (iVar3 == 10) {
          iVar3 = 3;
        }
        else if (iVar3 == 0x15) {
          iVar3 = 6;
        }
        else if (iVar3 == 0x17) {
          iVar3 = 8;
        }
        else {
          if (iVar3 != 0x23) goto LAB_14801a70;
          iVar3 = 7;
        }
        goto LAB_14801a74;
      }
      if (iVar3 == 0) {
        param_1[0x21c] = (TagData)0x0;
      }
      else {
        if (iVar3 != 1) {
          if (iVar3 != 2) {
            if (iVar3 == 5) {
              iVar3 = 4;
            }
            else {
LAB_14801a70:
              iVar3 = -1;
            }
          }
          goto LAB_14801a74;
        }
        param_1[0x21c] = (TagData)0x1;
      }
    }
    param_1[0x21d] = (TagData)0x1;
  }
  iVar3 = ad::nfp::GetNewResult();
  if (iVar3 != 0) {
    return 6;
  }
LAB_14801a98:
  TVar1 = *param_1;
  if (TVar1 != (TagData)0x0) {
    if (TVar1 == (TagData)0x1) {
      if (param_1[0x21c] == (TagData)0xff) {
        uVar4 = 2;
      }
      else {
        uVar4 = 1;
      }
      return uVar4;
    }
    if (TVar1 == (TagData)0x6) {
      return 3;
    }
    if (TVar1 == (TagData)0x7) {
      return 4;
    }
  }
  if (iVar2 == 4) {
    return 5;
  }
  return 0;
}


// FUNC 0x14801aec FUN_14801aec (LoadMenu)
//   size 0x2c | file LoadMenu+0x1aec | callers(0) | datarefs 4

undefined4 * FUN_14801aec(MoveWorkF *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)MoveWorkF::MoveWorkF(param_1);
  *puVar1 = &MoveWorkV::vtable;
  puVar1[8] = 0;
  puVar1[9] = 0;
  puVar1[10] = 0;
  return puVar1;
}


// FUNC 0x14801b20 MoveWorkV::vfunc_0x4 (LoadMenu)
//   size 0x10 | file LoadMenu+0x1b20 | callers(0) | datarefs 1

void MoveWorkV::vfunc_0x4(MoveWorkF *param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)MoveWorkF::~MoveWorkF(param_1);
  operator_delete(pvVar1);
  return;
}


// FUNC 0x14801b30 ->MoveWorkF::~MoveWorkF (LoadMenu)
//   size 0x4 | file LoadMenu+0x1b30 | callers(0) | datarefs 10
// veneer/thunk -> 0x00340694 MoveWorkF::~MoveWorkF (static)

// FUNC 0x14801b34 load_menu::LoadMenuTask::vfunc_0x10 (LoadMenu)
//   size 0x1c | file LoadMenu+0x1b34 | callers(0) | datarefs 1

void load_menu::LoadMenuTask::vfunc_0x10(TaskMainBase *param_1)

{
  if (*(char *)(*(int *)(param_1 + 0x580) + 0xe9049) == '\0') {
    return;
  }
  GameMain::Back(param_1);
  return;
}


// FUNC 0x14801b50 FUN_14801b50 (LoadMenu)
//   size 0x38 | file LoadMenu+0x1b50 | callers(1) 0x148008c0

int FUN_14801b50(MTaskBase *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)msys::MTaskBase::MTaskBase(param_1);
  *puVar1 = &load_menu::LoadMenuTask::vtable;
  iVar2 = FUN_1480d5e8(puVar1 + 0x162);
  FUN_1480d430(iVar2,iVar2 + -0x588);
  *(int *)(iVar2 + -8) = iVar2;
  return iVar2 + -0x588;
}


// FUNC 0x14801b8c load_menu::LoadMenuTask::vfunc_0x8 (LoadMenu)
//   size 0x24 | file LoadMenu+0x1b8c | callers(0) | datarefs 1

void load_menu::LoadMenuTask::vfunc_0x8(undefined4 *param_1)

{
  int iVar1;
  void *pvVar2;
  
  *param_1 = &vtable;
  iVar1 = LoadMenu::vfunc_0x0(param_1 + 0x162);
  pvVar2 = (void *)ad::fw::TaskBase::~TaskBase((TaskBase *)(iVar1 + -0x588));
  operator_delete(pvVar2);
  return;
}


// FUNC 0x14801bb4 load_menu::LoadMenuTask::vfunc_0x4 (LoadMenu)
//   size 0x20 | file LoadMenu+0x1bb4 | callers(0) | datarefs 1

void load_menu::LoadMenuTask::vfunc_0x4(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &vtable;
  iVar1 = LoadMenu::vfunc_0x0(param_1 + 0x162);
  ad::fw::TaskBase::~TaskBase((TaskBase *)(iVar1 + -0x588));
  return;
}


// FUNC 0x14801d9c load_menu::LoadMenuTopPage::Core::GameSelectU::vfunc_0x8 (LoadMenu)
//   size 0xf4 | file LoadMenu+0x1d9c | callers(0) | datarefs 1

void load_menu::LoadMenuTopPage::Core::GameSelectU::vfunc_0x8(float param_1,MMoveMsg *param_2)

{
  MMoveMsg MVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint in_fpscr;
  float fVar5;
  
  iVar4 = 0;
  do {
    MVar1 = param_2[iVar4 * 0x2c + 0x6cca];
    if (((byte)MVar1 & 1) == 0) {
      in_fpscr = in_fpscr & 0xfffffff;
      if (*(float *)(param_2 + iVar4 * 0x2c + 0x6cac) != 0.0) {
        MVar1 = param_2[iVar4 * 0x2c + 0x6cb2];
      }
      if (*(float *)(param_2 + iVar4 * 0x2c + 0x6cac) == 0.0 || ((byte)MVar1 & 1) == 0) {
        iVar2 = RandSys::get((RandSys *)&gRand);
        ad::lyt::LytAnim::play
                  ((LytAnim *)(param_2 + iVar4 * 0x2c + 0x6ca0),1.0,
                   (short)((uint)(iVar2 * 3) >> 0x10) + 2);
        uVar3 = RandSys::get((RandSys *)&gRand);
        fVar5 = (float)VectorUnsignedToFloat(uVar3,(byte)(in_fpscr >> 0x16) & 3);
        Frm::play((Frm *)(param_2 + iVar4 * 0x2c + 0x6cbc),fVar5 * 1.5258789e-05 * 60.0 + 180.0);
      }
      else {
        ad::lyt::LytAnim::update((LytAnim *)(param_2 + iVar4 * 0x2c + 0x6ca0),param_1);
      }
    }
    else {
      Frm::update(param_1);
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 8);
  msys::MMoveMsg::updateAnimeFrm(param_2,param_1);
  return;
}


// FUNC 0x14801ea8 load_menu::LoadMenuTopPage::Core::GameSelectU::vfunc_0x4 (LoadMenu)
//   size 0x80 | file LoadMenu+0x1ea8 | callers(0) | datarefs 1

void load_menu::LoadMenuTopPage::Core::GameSelectU::vfunc_0x4(undefined4 *param_1)

{
  int iVar1;
  void *pvVar2;
  
  *param_1 = &vtable;
  __aeabi_vec_dtor(param_1 + 0x1b28,&LAB_148091f8,0x2c,8);
  *param_1 = &save_load::Summary::vtable;
  __aeabi_vec_dtor(param_1 + 0x1b1a,&LAB_148013f0,0x1c,2);
  param_1[0x1b13] = 0;
  *param_1 = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar1 = MessageSimple::~MessageSimple((MessageSimple *)(param_1 + 0x53));
  pvVar2 = (void *)msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  operator_delete(pvVar2);
  return;
}


// FUNC 0x14801f40 load_menu::LoadMenuTopPage::Core::GameSelectU::vfunc_0x0 (LoadMenu)
//   size 0x7c | file LoadMenu+0x1f40 | callers(0) | datarefs 1

void load_menu::LoadMenuTopPage::Core::GameSelectU::vfunc_0x0(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &vtable;
  __aeabi_vec_dtor(param_1 + 0x1b28,&LAB_148091f8,0x2c,8);
  *param_1 = &save_load::Summary::vtable;
  __aeabi_vec_dtor(param_1 + 0x1b1a,&LAB_148013f0,0x1c,2);
  param_1[0x1b13] = 0;
  *param_1 = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar1 = MessageSimple::~MessageSimple((MessageSimple *)(param_1 + 0x53));
  msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  return;
}


// FUNC 0x14801fd4 FUN_14801fd4 (LoadMenu)
//   size 0xec | file LoadMenu+0x1fd4 | callers(0) | datarefs 2

void FUN_14801fd4(int param_1,uint *param_2)

{
  int iVar1;
  int iVar2;
  GameWorkPOD *pGVar3;
  bool bVar4;
  
  if ((*param_2 & 0x401) == 0) {
    if ((*param_2 & 0xc0) != 0) {
      FUN_14808d08(param_1,0x110015,0,0,0);
      bVar4 = *(char *)(param_1 + 0x77b8) == '\0';
      *(bool *)(param_1 + 0x77b8) = bVar4;
      iVar2 = msys::MComSys::_sys;
      iVar1 = *(int *)(param_1 + 8);
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar1 = iVar2;
      }
      pGVar3 = (GameWorkPOD *)Backup::GetSaveData1((ushort)bVar4);
      save_load::FilePanel::build((FilePanel *)(param_1 + 0x780c),pGVar3);
      FUN_14808bb4(param_1 + 0x8620,iVar1,pGVar3 + 0x828);
    }
  }
  else {
    (**(code **)(**(int **)(param_1 + *(char *)(param_1 + 0x77b8) * 4 + 0x1453c) + 0x10))();
    iVar2 = msys::MComSys::_sys;
    iVar1 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar1 = iVar2;
    }
    *(undefined1 *)(iVar1 + 0xe6508) = 0;
  }
  FUN_1480891c(param_1 + 0x77a0);
  return;
}


// FUNC 0x148020cc FUN_148020cc (LoadMenu)
//   size 0x1a4 | file LoadMenu+0x20cc | callers(1) 0x1480299c

void FUN_148020cc(undefined4 *param_1,int param_2,MLyt *param_3,char *param_4)

{
  int iVar1;
  void *pvVar2;
  undefined4 *puVar3;
  void *pvVar4;
  Layout *pLVar5;
  Resource *this;
  LytAnim aLStackY_108 [128];
  undefined2 local_78;
  undefined2 local_76;
  
  iVar1 = msys::MLyt::getParts(param_3,param_4,(char *)0x0,(char *)0x0);
  pLVar5 = *(Layout **)(iVar1 + 0xac);
  *param_1 = pLVar5;
  local_78 = 1;
  local_76 = 0;
  ad::lyt::LytAnim::init(aLStackY_108 + 0x80,pLVar5,"SET_SIZE_LOAD_U","");
  ad::lyt::LytAnim::stopAndSetFrm(aLStackY_108 + 0x80,0.0);
  ad::lyt::LytAnim::term(aLStackY_108 + 0x80,true);
  ad::lyt::LytNumReel3::InitParam::InitParam((InitParam *)&local_78);
  msys::MLytNumRes::set((MLytNumRes *)(param_2 + 0x844),&local_78,2,1);
  msys::MLytNum::init((MLytNum *)(param_1 + 0x3ad),(InitParam *)&local_78,
                      (LytDrawData *)(param_2 + 0xd3000),param_3,"NUM_POS",param_4,(char *)0x0,
                      (char *)0x0);
  msys::MLyt::attachMChr
            (param_3,(MChrBase *)(param_1 + 0x3ad),"NUM_POS",param_4,(char *)0x0,(char *)0x0);
  this = (Resource *)(param_2 + 0xfca34);
  msys::MCellAnime::init((MCellAnime *)(param_1 + 0x30d),this);
  msys::MLyt::attachMChr
            (param_3,(MChrBase *)(param_1 + 0x30d),"INS_FILE_CHARA_OBJ",param_4,(char *)0x0,
             (char *)0x0);
  msys::MCellAnimeListSimple::init();
  pvVar2 = (void *)ad::fw::Resource::getCA_anm(this);
  puVar3 = (undefined4 *)ad::fw::Resource::getCA_tex(this);
  pvVar4 = (void *)ad::fw::Resource::getCA_canm(this);
  CellAnime::init((CellAnime *)(param_1 + 0x6a),pvVar2,(void *)*puVar3,pvVar4,'\0',0,1.0);
  msys::MLyt::attachMChr
            (param_3,(MChrBase *)(param_1 + 1),"INS_FILE_PARTY_OBJ",param_4,(char *)0x0,(char *)0x0)
  ;
  return;
}


// FUNC 0x148022c0 FUN_148022c0 (LoadMenu)
//   size 0x118 | file LoadMenu+0x22c0 | callers(1) 0x14808bb4

undefined1 FUN_148022c0(int *param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  KJChrData aKStack_e8 [52];
  char acStack_b4 [111];
  undefined1 local_45;
  
  KJDB::Chr::getData((Chr *)(KJDB::_inst + 8),aKStack_e8,(KJMemberPOD *)(param_3 + 0x1b8));
  cVar1 = *(char *)(param_3 + (uint)*(byte *)(param_3 + 0x1cda) * 0x2c + 0x2b);
  if ((char)param_1[0x9f] != cVar1) {
    *(char *)(param_1 + 0x9f) = cVar1;
    (**(code **)(*param_1 + 0x38))(param_1);
    iVar3 = 0;
    do {
      iVar2 = param_2 + iVar3 * 0x44;
      if (*(char *)(iVar2 + 0xfca38) == '\0') break;
      iVar2 = strcmp(acStack_b4,(char *)(iVar2 + 0xfca40));
      if (iVar2 == 0) {
        iVar3 = param_2 + iVar3 * 0x44 + 0xfca34;
        goto LAB_14802378;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 0x15);
    iVar3 = 0;
LAB_14802378:
    (**(code **)(*param_1 + 0x40))(param_1,iVar3);
    MoveVBase::stop((MoveVBase *)(param_1 + 0x33));
    param_1[0x3a] = 0;
    param_1[0x3b] = -0x3e000000;
    param_1[0x3c] = 0;
    param_1[0x34] = param_1[0x3a];
    param_1[0x35] = -0x3e000000;
    param_1[0x36] = 0;
  }
  return local_45;
}


// FUNC 0x148023ec load_menu::LoadMenuTopPage::Core::SaveGameInfo::FilePanelKJ::KJObj::vfunc_0x4 (LoadMenu)
//   size 0x20 | file LoadMenu+0x23ec | callers(0) | datarefs 1

void load_menu::LoadMenuTopPage::Core::SaveGameInfo::FilePanelKJ::KJObj::vfunc_0x4
               (undefined4 *param_1)

{
  int iVar1;
  void *pvVar2;
  
  *param_1 = &msys::MCellAnime::vtable;
  iVar1 = CellAnime::~CellAnime((CellAnime *)(param_1 + 0x53));
  pvVar2 = (void *)msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  operator_delete(pvVar2);
  return;
}


// FUNC 0x14802410 load_menu::LoadMenuTopPage::Core::SaveGameInfo::FilePanelKJ::KJObj::vfunc_0x0 (LoadMenu)
//   size 0x1c | file LoadMenu+0x2410 | callers(0) | datarefs 1

void load_menu::LoadMenuTopPage::Core::SaveGameInfo::FilePanelKJ::KJObj::vfunc_0x0
               (undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &msys::MCellAnime::vtable;
  iVar1 = CellAnime::~CellAnime((CellAnime *)(param_1 + 0x53));
  msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  return;
}


// FUNC 0x14802430 load_menu::LoadMenuTopPage::Core::SaveGameInfo::FilePanelKJ::IconObj::vfunc_0x44 (LoadMenu)
//   size 0x14 | file LoadMenu+0x2430 | callers(0) | datarefs 1

int load_menu::LoadMenuTopPage::Core::SaveGameInfo::FilePanelKJ::IconObj::vfunc_0x44
              (int param_1,int param_2)

{
  return param_1 + param_2 * 300 + 0x1a4;
}


// FUNC 0x14802444 FUN_14802444 (LoadMenu)
//   size 0x2c8 | file LoadMenu+0x2444 | callers(1) 0x14808bb4

int FUN_14802444(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  void *pvVar6;
  uint uVar7;
  uint extraout_r1;
  int iVar8;
  short *psVar9;
  undefined4 uVar10;
  int iVar11;
  int iVar12;
  Resource *this;
  float unaff_s16;
  char *__s1;
  KJChrData aKStack_110 [18];
  ushort local_fe;
  char acStack_c4 [80];
  byte local_74;
  byte local_6d;
  byte local_54;
  int local_4c;
  int local_48;
  int local_44;
  void *local_40;
  
  Mem::Fill((void *)(param_1 + 0x184),0,0x20);
  iVar8 = 0;
  iVar11 = 0;
  local_48 = 0;
  local_4c = 1;
  iVar12 = param_3 + (uint)*(byte *)(param_3 + 0x1cda) * 0x2c;
  iVar1 = *(byte *)(iVar12 + 0x2a) - 1;
  if (*(byte *)(iVar12 + 0x2a) != 1 && -1 < iVar1) {
    unaff_s16 = 1.0;
  }
  if (0 < iVar1) {
    do {
      psVar9 = (short *)(iVar12 + iVar11 * 4);
      iVar1 = (int)*psVar9;
      if (0 < iVar1) {
        KJDB::Chr::getData((Chr *)(KJDB::_inst + 8),aKStack_110,
                           (KJMemberPOD *)(param_3 + iVar1 * 0x10 + 0x1b8));
        iVar1 = param_1 + iVar8 * 4;
        local_48 = local_48 + (uint)local_6d;
        uVar2 = (uint)*(ushort *)(param_1 + iVar8 * 4 + 0x184);
        if ((*(byte *)(psVar9 + 1) & 0x1f) == 0xf) {
          uVar2 = uVar2 & 0xfffffffe;
        }
        else {
          uVar2 = uVar2 | 1;
        }
        *(short *)(iVar1 + 0x184) = (short)uVar2;
        if ((local_54 & 0xc0) == 0) {
          uVar2 = uVar2 | 2;
        }
        else {
          uVar2 = uVar2 & 0xfffffffd;
        }
        *(ushort *)(iVar1 + 0x184) = (ushort)uVar2;
        iVar3 = 0;
        uVar7 = (local_74 & 7) << 2;
        *(ushort *)(iVar1 + 0x184) = (ushort)uVar7 | (ushort)uVar2 & 0xffe3;
        uVar2 = uVar7 | uVar2 & 3 | (local_fe & 0x7ff07ff) << 5;
        *(short *)(iVar1 + 0x184) = (short)uVar2;
        while( true ) {
          local_44 = iVar1;
          if ((0 < iVar8) &&
             ((local_fe & 0x7ff07ff) == (uint)(*(ushort *)(param_1 + iVar3 * 4 + 0x184) >> 5))) {
            *(undefined2 *)(iVar1 + 0x186) = *(undefined2 *)(param_1 + iVar3 * 4 + 0x186);
            goto LAB_14802674;
          }
          if (iVar8 <= iVar3 + 1) break;
          iVar3 = iVar3 + 1;
        }
        __s1 = acStack_c4;
        iVar3 = 0;
        do {
          iVar4 = param_2 + iVar3 * 0x44;
          if (*(char *)(iVar4 + 0xfca38) == '\0') break;
          iVar4 = strcmp(__s1,(char *)(iVar4 + 0xfca40));
          if (iVar4 == 0) {
            this = (Resource *)(param_2 + iVar3 * 0x44 + 0xfca34);
            goto LAB_14802600;
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < 0x15);
        this = (Resource *)0x0;
LAB_14802600:
        iVar3 = param_1 + local_4c * 300;
        CellAnime::term((CellAnime *)(iVar3 + 0x1a4));
        local_40 = (void *)ad::fw::Resource::getCA_anm(this);
        puVar5 = (undefined4 *)ad::fw::Resource::getCA_tex(this);
        pvVar6 = (void *)ad::fw::Resource::getCA_canm(this);
        CellAnime::init((CellAnime *)(iVar3 + 0x1a4),local_40,(void *)*puVar5,pvVar6,'\0',0,
                        unaff_s16);
        *(short *)(iVar1 + 0x186) = (short)local_4c;
        local_4c = local_4c + 1;
        uVar2 = extraout_r1;
LAB_14802674:
        if (0 < iVar8) {
          uVar2 = (uint)*(ushort *)(iVar1 + 0x184);
        }
        iVar1 = 0;
        if (0 < iVar8) {
          do {
            if (uVar2 < *(ushort *)(param_1 + iVar1 * 4 + 0x184)) {
              iVar3 = param_1 + iVar1 * 4;
              uVar10 = *(undefined4 *)(local_44 + 0x184);
              Mem::Copy((void *)(iVar3 + 0x188),(void *)(iVar3 + 0x184),(iVar8 - iVar1) * 4);
              *(undefined4 *)(iVar3 + 0x184) = uVar10;
              break;
            }
            iVar1 = iVar1 + 1;
          } while (iVar1 < iVar8);
        }
        iVar8 = iVar8 + 1;
      }
      iVar11 = iVar11 + 1;
    } while (iVar8 < (int)(*(byte *)(iVar12 + 0x2a) - 1));
  }
  return local_48;
}


// FUNC 0x14802718 load_menu::LoadMenuTopPage::Core::SaveGameInfo::FilePanelKJ::IconObj::vfunc_0x3c (LoadMenu)
//   size 0x1dc | file LoadMenu+0x2718 | callers(0) | datarefs 1

void load_menu::LoadMenuTopPage::Core::SaveGameInfo::FilePanelKJ::IconObj::vfunc_0x3c
               (int param_1,CmdListBase *param_2,CellAnimeState *param_3,ApplyingSceneInfo *param_4)

{
  MTX34 *pMVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  undefined4 local_d4 [3];
  MTX34 aMStack_c8 [12];
  float local_bc;
  float local_ac;
  MTX34 aMStack_98 [4];
  undefined4 local_94 [2];
  float local_8c;
  float local_7c;
  
  iVar2 = 0;
  fVar4 = 0.0;
  fVar5 = fVar4;
  fVar6 = fVar4;
  do {
    iVar3 = param_1 + iVar2 * 4;
    if (*(int *)(iVar3 + 0x184) == 0) {
      return;
    }
    pMVar1 = (MTX34 *)(param_1 + 0x1a4);
    *(byte *)(param_1 + 0x230) = *(byte *)(param_1 + 0x230) & 0xfe;
    *(undefined1 *)(param_1 + 0x23c) = 0;
    *(undefined1 *)(param_1 + 0x23d) = 0;
    local_94[0] = *(undefined4 *)(param_1 + 0x17c);
    CellAnime::setConstColor((CellAnime *)pMVar1,0,local_94);
    nn::math::ARMv6::MTX34CopyAsm(aMStack_c8,(MTX34 *)(param_1 + 0x14c));
    local_bc = local_bc + -60.0 + fVar5;
    local_ac = local_ac + 20.0 + fVar6;
    CellAnime::setWldMtx(pMVar1,SUB41(aMStack_c8,0));
    CellAnime::play((CellAnime *)pMVar1,(uchar)((*(byte *)(iVar3 + 0x184) & 0x1f) >> 2),0,1.0);
    CellAnime::draw((CellAnime *)pMVar1,param_2,param_3,param_4);
    iVar3 = param_1 + (uint)*(ushort *)(iVar3 + 0x186) * 300;
    pMVar1 = (MTX34 *)(iVar3 + 0x1a4);
    *(byte *)(iVar3 + 0x230) = *(byte *)(iVar3 + 0x230) & 0xfe;
    *(undefined1 *)(iVar3 + 0x23c) = 0;
    *(undefined1 *)(iVar3 + 0x23d) = 0;
    local_d4[0] = *(undefined4 *)(param_1 + 0x17c);
    CellAnime::setConstColor((CellAnime *)pMVar1,0,local_d4);
    nn::math::ARMv6::MTX34CopyAsm(aMStack_98,(MTX34 *)(param_1 + 0x14c));
    local_8c = local_8c + -60.0 + fVar5;
    local_7c = local_7c + 20.0 + fVar6;
    CellAnime::setWldMtx(pMVar1,SUB41(aMStack_98,0));
    CellAnime::play((CellAnime *)pMVar1,'\0',0,1.0);
    CellAnime::draw((CellAnime *)pMVar1,param_2,param_3,param_4);
    iVar2 = iVar2 + 1;
    if ((int)fVar5 < 0x42f00000) {
      fVar5 = fVar5 + 40.0;
    }
    else {
      fVar6 = fVar6 + -40.0;
      fVar5 = fVar4;
    }
  } while (iVar2 < 8);
  return;
}


// FUNC 0x14802910 load_menu::LoadMenuTopPage::Core::SaveGameInfo::FilePanelKJ::IconObj::vfunc_0x4 (LoadMenu)
//   size 0x3c | file LoadMenu+0x2910 | callers(0) | datarefs 1

void load_menu::LoadMenuTopPage::Core::SaveGameInfo::FilePanelKJ::IconObj::vfunc_0x4
               (undefined4 *param_1)

{
  void *pvVar1;
  
  *param_1 = &vtable;
  __aeabi_vec_dtor(param_1 + 0x69,CellAnime::~CellAnime,300,9);
  *param_1 = &msys::MCellAnimeListSimple::vtable;
  pvVar1 = (void *)msys::MChrBase::vfunc_0x0(param_1);
  operator_delete(pvVar1);
  return;
}


// FUNC 0x14802958 load_menu::LoadMenuTopPage::Core::SaveGameInfo::FilePanelKJ::IconObj::vfunc_0x0 (LoadMenu)
//   size 0x38 | file LoadMenu+0x2958 | callers(0) | datarefs 1

void load_menu::LoadMenuTopPage::Core::SaveGameInfo::FilePanelKJ::IconObj::vfunc_0x0
               (undefined4 *param_1)

{
  *param_1 = &vtable;
  __aeabi_vec_dtor(param_1 + 0x69,CellAnime::~CellAnime,300,9);
  *param_1 = &msys::MCellAnimeListSimple::vtable;
  msys::MChrBase::vfunc_0x0(param_1);
  return;
}


// FUNC 0x1480299c FUN_1480299c (LoadMenu)
//   size 0xc4 | file LoadMenu+0x299c | callers(2) 0x1480307c 0x1480308c

void FUN_1480299c(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  GameWorkPOD *pGVar4;
  char *pcVar5;
  
  iVar2 = msys::MComSys::_sys;
  iVar1 = *(int *)(param_2 + 8);
  if (*(int *)(param_2 + 8) == 0) {
    *(int *)(param_2 + 8) = msys::MComSys::_sys;
    iVar1 = iVar2;
  }
  if (param_2 + 0x7808 == param_1) {
    pcVar3 = "FILE_MLK";
  }
  else {
    pcVar3 = "FILE_ML_sub";
  }
  save_load::FilePanel::init((FilePanel *)(param_1 + 4),1,iVar1,param_2 + 0xe8);
  iVar2 = msys::MComSys::_sys;
  iVar1 = *(int *)(param_2 + 8);
  if (*(int *)(param_2 + 8) == 0) {
    *(int *)(param_2 + 8) = msys::MComSys::_sys;
    iVar1 = iVar2;
  }
  if (param_2 + 0x7808 == param_1) {
    pcVar5 = "FILE_KJ";
  }
  else {
    pcVar5 = "FILE_KJ_sub";
  }
  FUN_148020cc(param_1 + 0xe18,iVar1,param_2 + 0xe8,pcVar5);
  iVar2 = msys::MComSys::_sys;
  iVar1 = *(int *)(param_2 + 8);
  if (*(int *)(param_2 + 8) == 0) {
    *(int *)(param_2 + 8) = msys::MComSys::_sys;
    iVar1 = iVar2;
  }
  pGVar4 = (GameWorkPOD *)Backup::GetSaveData1(-1);
  save_load::FilePanel::build((FilePanel *)(param_1 + 4),pGVar4);
  FUN_14808bb4(param_1 + 0xe18,iVar1,pGVar4 + 0x828,pcVar3);
  return;
}


// FUNC 0x14802c18 FUN_14802c18 (LoadMenu)
//   size 0x30 | file LoadMenu+0x2c18 | callers(0) | datarefs 2

int FUN_14802c18(int param_1)

{
  *(undefined4 *)(param_1 + 0xafc) = 0;
  __aeabi_vec_dtor(param_1,msys::MLytNum::~MLytNum,0x230,5);
  return param_1;
}


// FUNC 0x14802c64 FUN_14802c64 (LoadMenu)
//   size 0xe4 | file LoadMenu+0x2c64 | callers(0) | datarefs 2

void FUN_14802c64(int param_1,uint *param_2)

{
  int iVar1;
  undefined1 uVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = *param_2;
  if (((uVar3 & 0x802) == 0) || (*(char *)(param_1 + 0x77b8) == '\r')) {
    if ((uVar3 & 0x401) == 0) {
      if ((uVar3 & 0x30) != 0) {
        FUN_14808d08(param_1,0x110015,0,0,0);
        if (*(char *)(param_1 + 0x77b8) == '\r') {
          uVar2 = 0xc;
        }
        else {
          uVar2 = 0xd;
        }
        *(undefined1 *)(param_1 + 0x77b8) = uVar2;
      }
    }
    else {
      (**(code **)(**(int **)(param_1 + *(char *)(param_1 + 0x77b8) * 4 + 0x1453c) + 0x10))();
      iVar1 = msys::MComSys::_sys;
      iVar4 = *(int *)(param_1 + 8);
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar4 = iVar1;
      }
      *(undefined1 *)(iVar4 + 0xe6508) = 0;
    }
  }
  else {
    FUN_14808d08(param_1,0x110015,0,0,0);
    *(undefined1 *)(param_1 + 0x77b8) = 0xd;
  }
  FUN_1480891c(param_1 + 0x77a0);
  return;
}


// FUNC 0x14802d5c FUN_14802d5c (LoadMenu)
//   size 0x178 | file LoadMenu+0x2d5c | callers(0) | datarefs 2

void FUN_14802d5c(int param_1,uint *param_2)

{
  char cVar1;
  int iVar2;
  undefined1 uVar3;
  uint uVar4;
  char cVar5;
  int iVar6;
  bool bVar7;
  
  if ((*param_2 & 0x802) == 0) {
    if ((*param_2 & 0x401) == 0) {
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
      }
      iVar6 = Backup::IsNew((short)((DAT_003fbea0 & 3) >> 1));
      if (iVar6 == 0) {
        uVar4 = *param_2;
        if ((uVar4 & 0xc0) == 0) {
          bVar7 = (uVar4 & 0x30) != 0;
          if (bVar7) {
            uVar4 = (uint)*(byte *)(param_1 + 0x77b8);
          }
          if (bVar7 && uVar4 != 2) {
            FUN_14808d08(param_1,0x110015,0,0,0);
            if (*(char *)(param_1 + 0x77b8) == '\x03') {
              uVar3 = 4;
            }
            else {
              uVar3 = 3;
            }
            *(undefined1 *)(param_1 + 0x4a799) = uVar3;
            *(undefined1 *)(param_1 + 0x77b8) = uVar3;
          }
        }
        else {
          FUN_14808d08(param_1,0x110015,0,0,0);
          cVar1 = *(char *)(param_1 + 0x77b8);
          if (cVar1 == '\x02') {
            cVar5 = *(char *)(param_1 + 0x4a799);
            if (cVar5 != '\x03') {
              cVar5 = '\x04';
            }
          }
          else {
            cVar5 = '\x02';
          }
          *(char *)(param_1 + 0x77b8) = cVar5;
          *(char *)(param_1 + 0x4a799) = cVar1;
        }
      }
      goto LAB_14802ec8;
    }
    (**(code **)(**(int **)(param_1 + *(char *)(param_1 + 0x77b8) * 4 + 0x1453c) + 0x10))();
    iVar6 = *(int *)(param_1 + 8);
  }
  else {
    (**(code **)(**(int **)(param_1 + 0x14574) + 0x10))();
    iVar6 = *(int *)(param_1 + 8);
  }
  iVar2 = msys::MComSys::_sys;
  if (iVar6 == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar6 = iVar2;
  }
  *(undefined1 *)(iVar6 + 0xe6508) = 0;
LAB_14802ec8:
  FUN_1480891c(param_1 + 0x77a0);
  return;
}


// FUNC 0x14802eec FUN_14802eec (LoadMenu)
//   size 0x7c | file LoadMenu+0x2eec | callers(0) | datarefs 3

void FUN_14802eec(int param_1)

{
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0xe8),0,1,(char *)0x0,(char *)0x0);
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0xe8),1,1,(char *)0x0,(char *)0x0);
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x490),0,1,(char *)0x0,(char *)0x0);
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x490),1,1,(char *)0x0,(char *)0x0);
  *(code **)(param_1 + 0x20) = FUN_148049c0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


// FUNC 0x148039b0 FUN_148039b0 (LoadMenu)
//   size 0x34 | file LoadMenu+0x39b0 | callers(0) | datarefs 2

void FUN_148039b0(int param_1)

{
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x490),8,1,(char *)0x0,(char *)0x0);
  *(code **)(param_1 + 0x20) = FUN_14804a44;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


// FUNC 0x148039e8 FUN_148039e8 (LoadMenu)
//   size 0xe4 | file LoadMenu+0x39e8 | callers(0) | datarefs 2

void FUN_148039e8(int param_1,uint *param_2)

{
  int iVar1;
  undefined1 uVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = *param_2;
  if (((uVar3 & 0x802) == 0) || (*(char *)(param_1 + 0x77b8) == '\x05')) {
    if ((uVar3 & 0x401) == 0) {
      if ((uVar3 & 0x30) != 0) {
        FUN_14808d08(param_1,0x110015,0,0,0);
        if (*(char *)(param_1 + 0x77b8) == '\x05') {
          uVar2 = 9;
        }
        else {
          uVar2 = 5;
        }
        *(undefined1 *)(param_1 + 0x77b8) = uVar2;
      }
    }
    else {
      (**(code **)(**(int **)(param_1 + *(char *)(param_1 + 0x77b8) * 4 + 0x1453c) + 0x10))();
      iVar1 = msys::MComSys::_sys;
      iVar4 = *(int *)(param_1 + 8);
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar4 = iVar1;
      }
      *(undefined1 *)(iVar4 + 0xe6508) = 0;
    }
  }
  else {
    FUN_14808d08(param_1,0x110015,0,0,0);
    *(undefined1 *)(param_1 + 0x77b8) = 5;
  }
  FUN_1480891c(param_1 + 0x77a0);
  return;
}


// FUNC 0x14803ae0 FUN_14803ae0 (LoadMenu)
//   size 0x180 | file LoadMenu+0x3ae0 | callers(0)

void FUN_14803ae0(int param_1)

{
  uint uVar1;
  void *pvVar2;
  int iVar3;
  code *pcVar4;
  wchar_t *pwVar5;
  int iVar6;
  char *pcVar7;
  ushort uVar8;
  uint in_fpscr;
  float fVar9;
  LytAnim aLStackY_b8 [128];
  
  uVar8 = (ushort)(*(char *)(param_1 + 0x77b8) == '\x01');
  GameWork::initGameWork((GameWork *)&gGameWork);
  pvVar2 = (void *)Backup::GetSaveData1(uVar8);
  Mem::Copy(&gGameWork,pvVar2,0x28c0);
  GameWork::postLoadGameWork((GameWork *)&gGameWork);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  iVar3 = Backup::IsNew(uVar8);
  iVar6 = msys::MComSys::_sys;
  if (iVar3 != 0) {
LAB_14803b50:
    *(undefined4 *)(param_1 + 0x20) = 0x148046e8;
    *(undefined4 *)(param_1 + 0x24) = 0;
    iVar3 = msys::MComSys::_sys;
    uVar1 = (DAT_003fbea0 & 3) >> 1;
    iVar6 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar6 = iVar3;
    }
    if (uVar1 == 0) {
      pcVar7 = "menu_load_06";
    }
    else {
      pcVar7 = "menu_load_07";
    }
    pwVar5 = (wchar_t *)FUN_14808da8(iVar6,0,pcVar7);
    msys::MMsg::playStr((MMsg *)(param_1 + 0x2f688),pwVar5,(InsParam *)0x0,false);
    ad::lyt::LytAnim::init(aLStackY_b8 + 0x80,*(Layout **)(param_1 + 0x5e0),"SET_NEW_DATA_btn","");
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
    }
    iVar6 = Backup::IsNew((short)uVar1);
    fVar9 = (float)VectorUnsignedToFloat((uint)(iVar6 != 0),(byte)(in_fpscr >> 0x16) & 3);
    ad::lyt::LytAnim::stopAndSetFrm(aLStackY_b8 + 0x80,fVar9);
    ad::lyt::LytAnim::term(aLStackY_b8 + 0x80,true);
    msys::MLyt::playAnimeFromNo
              ((MLyt *)(param_1 + 0x490),*(uint *)(&DAT_1480e2e4 + uVar1 * 4),1,(char *)0x0,
               (char *)0x0);
    *(code **)(param_1 + 0x20) = FUN_14804ab0;
    *(undefined4 *)(param_1 + 0x24) = 0;
    return;
  }
  iVar3 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar3 = iVar6;
  }
  Backup::init((Backup *)(iVar3 + 0xe9050),(CtrFS *)(*(int *)(iVar3 + 4) + 0x518));
  Backup::readSaveData2((Backup *)(iVar3 + 0xe9050),(short)((DAT_003fbea0 & 3) >> 1));
  *(code **)(param_1 + 0x20) = FUN_14804604;
  *(undefined4 *)(param_1 + 0x24) = 0;
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  iVar3 = Backup::errorCode();
  iVar6 = msys::MComSys::_sys;
  if (iVar3 == 0) {
    iVar3 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar3 = iVar6;
    }
    iVar6 = Backup::isBusyReading((Backup *)(iVar3 + 0xe9050));
    if (iVar6 == 0) {
      Backup::term();
      goto LAB_14803b50;
    }
  }
  else {
    if ((iVar3 - 0x2001U < 2) || (iVar3 - 0x2001U == 2)) {
      *(code **)(param_1 + 0x28) = FUN_14804970;
      *(undefined4 *)(param_1 + 0x2c) = 0;
      pcVar4 = FUN_14806438;
    }
    else {
      pcVar4 = FUN_148090a0;
    }
    *(code **)(param_1 + 0x20) = pcVar4;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x14803c80 FUN_14803c80 (LoadMenu)
//   size 0x4c | file LoadMenu+0x3c80 | callers(0)

void FUN_14803c80(int param_1)

{
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x490),2,0,(char *)0x0,(char *)0x0);
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x490),3,0,(char *)0x0,(char *)0x0);
  *(code **)(param_1 + 0x20) = FUN_148049c0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


// FUNC 0x14803cd0 FUN_14803cd0 (LoadMenu)
//   size 0x54 | file LoadMenu+0x3cd0 | callers(0) | datarefs 1

void FUN_14803cd0(int param_1)

{
  MComSys *pMVar1;
  int iVar2;
  MComSys *this;
  
  iVar2 = msys::MLyt::isBusyAnime((MLyt *)(param_1 + 0x490));
  pMVar1 = msys::MComSys::_sys;
  if (iVar2 == 0) {
    this = *(MComSys **)(param_1 + 8);
    if (*(MComSys **)(param_1 + 8) == (MComSys *)0x0) {
      *(MComSys **)(param_1 + 8) = msys::MComSys::_sys;
      this = pMVar1;
    }
    iVar2 = msys::MComSys::getNextPage(this);
    if (*(char *)(iVar2 + 0x14) != '\0') {
      *(undefined1 **)(param_1 + 0x18) = &LAB_148059f8;
      *(undefined4 *)(param_1 + 0x1c) = 0;
    }
  }
  return;
}


// FUNC 0x14803d40 FUN_14803d40 (LoadMenu)
//   size 0xe4 | file LoadMenu+0x3d40 | callers(0) | datarefs 2

void FUN_14803d40(int param_1,uint *param_2)

{
  int iVar1;
  undefined1 uVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = *param_2;
  if (((uVar3 & 0x802) == 0) || (*(char *)(param_1 + 0x77b8) == '\x05')) {
    if ((uVar3 & 0x401) == 0) {
      if ((uVar3 & 0x30) != 0) {
        FUN_14808d08(param_1,0x110015,0,0,0);
        if (*(char *)(param_1 + 0x77b8) == '\x05') {
          uVar2 = 0xb;
        }
        else {
          uVar2 = 5;
        }
        *(undefined1 *)(param_1 + 0x77b8) = uVar2;
      }
    }
    else {
      (**(code **)(**(int **)(param_1 + *(char *)(param_1 + 0x77b8) * 4 + 0x1453c) + 0x10))();
      iVar1 = msys::MComSys::_sys;
      iVar4 = *(int *)(param_1 + 8);
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar4 = iVar1;
      }
      *(undefined1 *)(iVar4 + 0xe6508) = 0;
    }
  }
  else {
    FUN_14808d08(param_1,0x110015,0,0,0);
    *(undefined1 *)(param_1 + 0x77b8) = 5;
  }
  FUN_1480891c(param_1 + 0x77a0);
  return;
}


// FUNC 0x14803e38 FUN_14803e38 (LoadMenu)
//   size 0xe4 | file LoadMenu+0x3e38 | callers(0) | datarefs 2

void FUN_14803e38(int param_1,uint *param_2)

{
  int iVar1;
  undefined1 uVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = *param_2;
  if (((uVar3 & 0x802) == 0) || (*(char *)(param_1 + 0x77b8) == '\x05')) {
    if ((uVar3 & 0x401) == 0) {
      if ((uVar3 & 0x30) != 0) {
        FUN_14808d08(param_1,0x110015,0,0,0);
        if (*(char *)(param_1 + 0x77b8) == '\x05') {
          uVar2 = 0xb;
        }
        else {
          uVar2 = 5;
        }
        *(undefined1 *)(param_1 + 0x77b8) = uVar2;
      }
    }
    else {
      (**(code **)(**(int **)(param_1 + *(char *)(param_1 + 0x77b8) * 4 + 0x1453c) + 0x10))();
      iVar1 = msys::MComSys::_sys;
      iVar4 = *(int *)(param_1 + 8);
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar4 = iVar1;
      }
      *(undefined1 *)(iVar4 + 0xe6508) = 0;
    }
  }
  else {
    FUN_14808d08(param_1,0x110015,0,0,0);
    *(undefined1 *)(param_1 + 0x77b8) = 5;
  }
  FUN_1480891c(param_1 + 0x77a0);
  return;
}


// FUNC 0x14803f30 FUN_14803f30 (LoadMenu)
//   size 0x120 | file LoadMenu+0x3f30 | callers(0) | datarefs 2

void FUN_14803f30(int param_1)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  wchar_t *pwVar4;
  
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  iVar1 = Backup::errorCode();
  iVar3 = msys::MComSys::_sys;
  if (iVar1 != 0) {
    if ((iVar1 - 0x2001U < 2) || (iVar1 - 0x2001U == 2)) {
      *(code **)(param_1 + 0x28) = FUN_14804970;
      *(undefined4 *)(param_1 + 0x2c) = 0;
      pcVar2 = FUN_14806438;
    }
    else {
      pcVar2 = FUN_148090a0;
    }
    *(code **)(param_1 + 0x20) = pcVar2;
    *(undefined4 *)(param_1 + 0x24) = 0;
    return;
  }
  iVar1 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar1 = iVar3;
  }
  iVar3 = Backup::isBusyCopying((Backup *)(iVar1 + 0xe9050));
  if (iVar3 == 0) {
    Backup::term();
    iVar1 = msys::MComSys::_sys;
    iVar3 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar3 = iVar1;
    }
    pwVar4 = (wchar_t *)FUN_14808da8(iVar3,0,"menu_load_10");
    msys::MMsg::playStr((MMsg *)(param_1 + 0x3cf10),pwVar4,(InsParam *)0x0,false);
    Frm::play((Frm *)(param_1 + 0x7770),120.0);
    FUN_14808d08(param_1,0x11003b,0,0,0);
    *(code **)(param_1 + 0x20) = FUN_14805ae0;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x1480407c FUN_1480407c (LoadMenu)
//   size 0x34 | file LoadMenu+0x407c | callers(0)

void FUN_1480407c(int param_1)

{
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x490),5,1,(char *)0x0,(char *)0x0);
  *(code **)(param_1 + 0x20) = FUN_14804c98;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


// FUNC 0x148040b4 FUN_148040b4 (LoadMenu)
//   size 0xc4 | file LoadMenu+0x40b4 | callers(0) | datarefs 3

void FUN_148040b4(int param_1)

{
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0xe8),2,0,(char *)0x0,(char *)0x0);
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x490),4,0,(char *)0x0,(char *)0x0);
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x490),5,0,(char *)0x0,(char *)0x0);
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x490),6,0,(char *)0x0,(char *)0x0);
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x490),8,0,(char *)0x0,(char *)0x0);
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x490),9,0,(char *)0x0,(char *)0x0);
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x490),10,0,(char *)0x0,(char *)0x0);
  *(code **)(param_1 + 0x20) = FUN_14804ab0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


// FUNC 0x1480417c FUN_1480417c (LoadMenu)
//   size 0x94 | file LoadMenu+0x417c | callers(0) | datarefs 2

void FUN_1480417c(int param_1)

{
  int iVar1;
  int iVar2;
  GameWorkPOD *pGVar3;
  
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x490),9,1,(char *)0x0,(char *)0x0);
  iVar1 = msys::MComSys::_sys;
  iVar2 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar2 = iVar1;
  }
  pGVar3 = (GameWorkPOD *)Backup::GetSaveData1(~(ushort)(DAT_003fbea0 >> 1) & 1);
  save_load::FilePanel::build((FilePanel *)(param_1 + 0x780c),pGVar3);
  FUN_14808bb4(param_1 + 0x8620,iVar2,pGVar3 + 0x828);
  *(code **)(param_1 + 0x20) = FUN_14804e44;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


// FUNC 0x1480421c FUN_1480421c (LoadMenu)
//   size 0x34 | file LoadMenu+0x421c | callers(0) | datarefs 2

void FUN_1480421c(int param_1)

{
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x490),10,1,(char *)0x0,(char *)0x0);
  *(code **)(param_1 + 0x20) = FUN_14804eb0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


// FUNC 0x14804254 FUN_14804254 (LoadMenu)
//   size 0x160 | file LoadMenu+0x4254 | callers(0) | datarefs 2

void FUN_14804254(int param_1)

{
  int iVar1;
  int iVar2;
  GameWorkPOD *pGVar3;
  wchar_t *pwVar4;
  
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  iVar2 = Backup::IsNew(~(ushort)(DAT_003fbea0 >> 1) & 1);
  if (iVar2 == 0) {
    msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x490),0xb,1,(char *)0x0,(char *)0x0);
  }
  else {
    msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x490),0xc,1,(char *)0x0,(char *)0x0);
    iVar1 = msys::MComSys::_sys;
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar1;
    }
    pGVar3 = (GameWorkPOD *)Backup::GetSaveData1(~(ushort)(DAT_003fbea0 >> 1) & 1);
    save_load::FilePanel::build((FilePanel *)(param_1 + 0x780c),pGVar3);
    FUN_14808bb4(param_1 + 0x8620,iVar2,pGVar3 + 0x828);
  }
  msys::MLyt::createAnimeAutoSlot((MLyt *)(param_1 + 0xe8),"COPY",(char *)0x0,(char *)0x0);
  iVar1 = msys::MComSys::_sys;
  iVar2 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar2 = iVar1;
  }
  pGVar3 = (GameWorkPOD *)Backup::GetSaveData1((short)((DAT_003fbea0 & 3) >> 1));
  save_load::FilePanel::build((FilePanel *)(param_1 + 0x9708),pGVar3);
  FUN_14808bb4(param_1 + 0xa51c,iVar2,pGVar3 + 0x828);
  iVar1 = msys::MComSys::_sys;
  iVar2 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar2 = iVar1;
  }
  pwVar4 = (wchar_t *)FUN_14808da8(iVar2,0,"menu_load_09");
  msys::MMsg::playStr((MMsg *)(param_1 + 0x3cf10),pwVar4,(InsParam *)0x0,false);
  *(code **)(param_1 + 0x20) = FUN_14804f1c;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


// FUNC 0x148043d8 FUN_148043d8 (LoadMenu)
//   size 0xe4 | file LoadMenu+0x43d8 | callers(0) | datarefs 2

void FUN_148043d8(int param_1,uint *param_2)

{
  int iVar1;
  undefined1 uVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = *param_2;
  if (((uVar3 & 0x802) == 0) || (*(char *)(param_1 + 0x77b8) == '\x05')) {
    if ((uVar3 & 0x401) == 0) {
      if ((uVar3 & 0x30) != 0) {
        FUN_14808d08(param_1,0x110015,0,0,0);
        if (*(char *)(param_1 + 0x77b8) == '\x05') {
          uVar2 = 10;
        }
        else {
          uVar2 = 5;
        }
        *(undefined1 *)(param_1 + 0x77b8) = uVar2;
      }
    }
    else {
      (**(code **)(**(int **)(param_1 + *(char *)(param_1 + 0x77b8) * 4 + 0x1453c) + 0x10))();
      iVar1 = msys::MComSys::_sys;
      iVar4 = *(int *)(param_1 + 8);
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar4 = iVar1;
      }
      *(undefined1 *)(iVar4 + 0xe6508) = 0;
    }
  }
  else {
    FUN_14808d08(param_1,0x110015,0,0,0);
    *(undefined1 *)(param_1 + 0x77b8) = 5;
  }
  FUN_1480891c(param_1 + 0x77a0);
  return;
}


// FUNC 0x148044d0 FUN_148044d0 (LoadMenu)
//   size 0x108 | file LoadMenu+0x44d0 | callers(0) | datarefs 2

void FUN_148044d0(int param_1)

{
  SaveLoadSys *pSVar1;
  SaveLoadSys *pSVar2;
  int iVar3;
  code *pcVar4;
  wchar_t *pwVar5;
  
  if (*(int *)(param_1 + 8) == 0) {
    *(SaveLoadSys **)(param_1 + 8) = msys::MComSys::_sys;
  }
  iVar3 = Backup::errorCode();
  pSVar2 = msys::MComSys::_sys;
  if (iVar3 != 0) {
    if ((iVar3 - 0x2001U < 2) || (iVar3 - 0x2001U == 2)) {
      *(code **)(param_1 + 0x28) = FUN_14804970;
      *(undefined4 *)(param_1 + 0x2c) = 0;
      pcVar4 = FUN_14806438;
    }
    else {
      pcVar4 = FUN_148090a0;
    }
    *(code **)(param_1 + 0x20) = pcVar4;
    *(undefined4 *)(param_1 + 0x24) = 0;
    return;
  }
  pSVar1 = *(SaveLoadSys **)(param_1 + 8);
  if (*(SaveLoadSys **)(param_1 + 8) == (SaveLoadSys *)0x0) {
    *(SaveLoadSys **)(param_1 + 8) = msys::MComSys::_sys;
    pSVar1 = pSVar2;
  }
  iVar3 = save_load::SaveLoadSys::saveIsBusyWriting(pSVar1);
  pSVar2 = msys::MComSys::_sys;
  if (iVar3 == 0) {
    pSVar1 = *(SaveLoadSys **)(param_1 + 8);
    if (*(SaveLoadSys **)(param_1 + 8) == (SaveLoadSys *)0x0) {
      *(SaveLoadSys **)(param_1 + 8) = msys::MComSys::_sys;
      pSVar1 = pSVar2;
    }
    pwVar5 = (wchar_t *)FUN_14808da8(pSVar1,0,"menu_load_04");
    msys::MMsg::playStr((MMsg *)(param_1 + 0x21e00),pwVar5,(InsParam *)0x0,false);
    Frm::play((Frm *)(param_1 + 0x7770),120.0);
    FUN_14808d08(param_1,0x11003c,0,0,0);
    *(code **)(param_1 + 0x20) = FUN_14805ae0;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x14804604 FUN_14804604 (LoadMenu)
//   size 0x1dc | file LoadMenu+0x4604 | callers(0) | datarefs 1

void FUN_14804604(int param_1)

{
  uint uVar1;
  int iVar2;
  code *pcVar3;
  int iVar4;
  wchar_t *pwVar5;
  char *pcVar6;
  uint in_fpscr;
  float fVar7;
  LytAnim aLStackY_b8 [128];
  
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  iVar2 = Backup::errorCode();
  iVar4 = msys::MComSys::_sys;
  if (iVar2 == 0) {
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar4;
    }
    iVar4 = Backup::isBusyReading((Backup *)(iVar2 + 0xe9050));
    if (iVar4 == 0) {
      Backup::term();
      *(undefined4 *)(param_1 + 0x20) = 0x148046e8;
      *(undefined4 *)(param_1 + 0x24) = 0;
      iVar2 = msys::MComSys::_sys;
      uVar1 = (DAT_003fbea0 & 3) >> 1;
      iVar4 = *(int *)(param_1 + 8);
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar4 = iVar2;
      }
      if (uVar1 == 0) {
        pcVar6 = "menu_load_06";
      }
      else {
        pcVar6 = "menu_load_07";
      }
      pwVar5 = (wchar_t *)FUN_14808da8(iVar4,0,pcVar6);
      msys::MMsg::playStr((MMsg *)(param_1 + 0x2f688),pwVar5,(InsParam *)0x0,false);
      ad::lyt::LytAnim::init(aLStackY_b8 + 0x80,*(Layout **)(param_1 + 0x5e0),"SET_NEW_DATA_btn","")
      ;
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
      }
      iVar4 = Backup::IsNew((short)uVar1);
      fVar7 = (float)VectorUnsignedToFloat((uint)(iVar4 != 0),(byte)(in_fpscr >> 0x16) & 3);
      ad::lyt::LytAnim::stopAndSetFrm(aLStackY_b8 + 0x80,fVar7);
      ad::lyt::LytAnim::term(aLStackY_b8 + 0x80,true);
      msys::MLyt::playAnimeFromNo
                ((MLyt *)(param_1 + 0x490),*(uint *)(&DAT_1480e2e4 + uVar1 * 4),1,(char *)0x0,
                 (char *)0x0);
      *(code **)(param_1 + 0x20) = FUN_14804ab0;
      *(undefined4 *)(param_1 + 0x24) = 0;
      return;
    }
  }
  else {
    if ((iVar2 - 0x2001U < 2) || (iVar2 - 0x2001U == 2)) {
      *(code **)(param_1 + 0x28) = FUN_14804970;
      *(undefined4 *)(param_1 + 0x2c) = 0;
      pcVar3 = FUN_14806438;
    }
    else {
      pcVar3 = FUN_148090a0;
    }
    *(code **)(param_1 + 0x20) = pcVar3;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x14804844 FUN_14804844 (LoadMenu)
//   size 0x34 | file LoadMenu+0x4844 | callers(0) | datarefs 2

void FUN_14804844(int param_1)

{
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x490),6,1,(char *)0x0,(char *)0x0);
  *(code **)(param_1 + 0x20) = FUN_14805098;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


// FUNC 0x1480487c FUN_1480487c (LoadMenu)
//   size 0xb8 | file LoadMenu+0x487c | callers(0) | datarefs 2

void FUN_1480487c(int param_1)

{
  int iVar1;
  int iVar2;
  wchar_t *pwVar3;
  
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x490),7,1,(char *)0x0,(char *)0x0);
  if ((DAT_003fbea0 & 1) == 0) {
    msys::MLyt::createAnimeAutoSlot((MLyt *)(param_1 + 0xe8),"ERASE","FILE_MLK",(char *)0x0);
  }
  if (DAT_003fbaf0 != 0) {
    msys::MLyt::createAnimeAutoSlot((MLyt *)(param_1 + 0xe8),"ERASE","FILE_KJ",(char *)0x0);
  }
  iVar1 = msys::MComSys::_sys;
  iVar2 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar2 = iVar1;
  }
  pwVar3 = (wchar_t *)FUN_14808da8(iVar2,0,"menu_load_03");
  msys::MMsg::playStr((MMsg *)(param_1 + 0x21e00),pwVar3,(InsParam *)0x0,false);
  *(code **)(param_1 + 0x20) = FUN_14805104;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


// FUNC 0x14804970 FUN_14804970 (LoadMenu)
//   size 0x4c | file LoadMenu+0x4970 | callers(0) | datarefs 4

void FUN_14804970(int param_1)

{
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0xe8),0,0,(char *)0x0,(char *)0x0);
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x490),0,0,(char *)0x0,(char *)0x0);
  *(code **)(param_1 + 0x20) = FUN_148051d4;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


// FUNC 0x148049c0 FUN_148049c0 (LoadMenu)
//   size 0x74 | file LoadMenu+0x49c0 | callers(0) | datarefs 6

void FUN_148049c0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = msys::MLyt::isEnableAnime((MLyt *)(param_1 + 0x490));
  if (iVar1 == 0) {
    msys::MLyt::applyAnime((MLyt *)(param_1 + 0x490));
    FUN_14808728(param_1,&DAT_1480e000,2,(DAT_003fbea0 & 3) >> 1);
    iVar1 = msys::MComSys::_sys;
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar1;
    }
    *(undefined1 *)(iVar2 + 0xe6508) = 1;
    *(code **)(param_1 + 0x20) = FUN_14801fd4;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x14804a44 FUN_14804a44 (LoadMenu)
//   size 0x60 | file LoadMenu+0x4a44 | callers(0) | datarefs 2

void FUN_14804a44(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = msys::MLyt::isEnableAnime((MLyt *)(param_1 + 0x490));
  if (iVar1 == 0) {
    FUN_14808728(param_1,&DAT_1480e006,2,0);
    iVar1 = msys::MComSys::_sys;
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar1;
    }
    *(undefined1 *)(iVar2 + 0xe6508) = 1;
    *(code **)(param_1 + 0x20) = FUN_14802c64;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x14804ab0 FUN_14804ab0 (LoadMenu)
//   size 0xe0 | file LoadMenu+0x4ab0 | callers(0) | datarefs 4

void FUN_14804ab0(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 uVar5;
  
  iVar3 = msys::MLyt::isEnableAnime((MLyt *)(param_1 + 0x490));
  if (iVar3 == 0) {
    uVar5 = 0;
    cVar1 = *(char *)(param_1 + 0x77b8);
    if ((cVar1 != '\x02') && (uVar5 = cVar1 == '\x0e', !(bool)uVar5)) {
      if (cVar1 == '\x03') {
        uVar5 = 2;
      }
      else if (cVar1 == '\x04') {
        uVar5 = 3;
      }
    }
    *(undefined1 *)(param_1 + 0x4a799) = 0xff;
    FUN_148088a4(param_1 + 0xcc28,(DAT_003fbea0 & 3) >> 1);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
    }
    iVar3 = Backup::IsNew((short)((DAT_003fbea0 & 3) >> 1));
    if (iVar3 == 0) {
      uVar4 = 4;
    }
    else {
      uVar4 = 2;
    }
    FUN_14808728(param_1,&DAT_1480e00c,uVar4,uVar5);
    iVar2 = msys::MComSys::_sys;
    iVar3 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar3 = iVar2;
    }
    *(undefined1 *)(iVar3 + 0xe6508) = 1;
    *(code **)(param_1 + 0x20) = FUN_14802d5c;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x14804ba4 FUN_14804ba4 (LoadMenu)
//   size 0xec | file LoadMenu+0x4ba4 | callers(0) | datarefs 1

void FUN_14804ba4(int param_1)

{
  int iVar1;
  int iVar2;
  BootInfo *this;
  BootInfo *pBVar3;
  void *pvVar4;
  SaveData *this_00;
  
  if (*(char *)(param_1 + 0x77b8) != '\x06') {
    this = (BootInfo *)kj_menu::GetBootInfo();
    kj_menu::BootInfo::reset(this);
    iVar2 = msys::MComSys::_sys;
    DAT_003fbea0 = DAT_003fbea0 | 0x20;
    iVar1 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar1 = iVar2;
    }
    GameMain::Change(2,*(undefined4 *)(iVar1 + 4));
    return;
  }
  if ((DAT_003fbea0 & 1) == 0) {
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
    }
    pvVar4 = (void *)Backup::GetSaveData2();
    this_00 = (SaveData *)fld::GetSaveData();
    fld::SaveData::load(this_00,pvVar4);
    pBVar3 = (BootInfo *)fld::GetBootInfo();
    fld::BootInfo::startScenarioModeForLoad(pBVar3);
  }
  else {
    pBVar3 = (BootInfo *)fld::GetBootInfo();
    fld::BootInfo::startScenarioModeForProd(pBVar3);
  }
  iVar2 = msys::MComSys::_sys;
  DAT_003fbea0 = DAT_003fbea0 & 0xdf;
  iVar1 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar1 = iVar2;
  }
  GameMain::Change(9,*(undefined4 *)(iVar1 + 4));
  return;
}


// FUNC 0x14804c98 FUN_14804c98 (LoadMenu)
//   size 0x60 | file LoadMenu+0x4c98 | callers(0) | datarefs 2

void FUN_14804c98(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = msys::MLyt::isEnableAnime((MLyt *)(param_1 + 0x490));
  if (iVar1 == 0) {
    FUN_14808728(param_1,&DAT_1480e002,2,0);
    iVar1 = msys::MComSys::_sys;
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar1;
    }
    *(undefined1 *)(iVar2 + 0xe6508) = 1;
    *(code **)(param_1 + 0x20) = FUN_148039e8;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x14804d04 FUN_14804d04 (LoadMenu)
//   size 0x12c | file LoadMenu+0x4d04 | callers(0) | datarefs 2

void FUN_14804d04(int param_1,uint *param_2)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = *param_2;
  if ((uVar3 & 0x802) == 0) {
    if ((uVar3 & 0x401) == 0) {
      if ((uVar3 & 0x40) == 0) {
        if ((uVar3 & 0x80) == 0) goto LAB_14804df0;
        FUN_14808d08(param_1,0x110015,0,0,0);
        if (*(char *)(param_1 + 0x77b8) < '\b') {
          cVar2 = *(char *)(param_1 + 0x77b8) + '\x01';
        }
        else {
          cVar2 = '\x06';
        }
      }
      else {
        FUN_14808d08(param_1,0x110015,0,0,0);
        if (*(char *)(param_1 + 0x77b8) < '\a') {
          cVar2 = '\b';
        }
        else {
          cVar2 = *(char *)(param_1 + 0x77b8) + -1;
        }
      }
      *(char *)(param_1 + 0x77b8) = cVar2;
      FUN_14808344(param_1 + 0xd73c,param_1,0xffffffff);
      goto LAB_14804df0;
    }
    (**(code **)(**(int **)(param_1 + *(char *)(param_1 + 0x77b8) * 4 + 0x1453c) + 0x10))();
    iVar4 = *(int *)(param_1 + 8);
  }
  else {
    (**(code **)(**(int **)(param_1 + 0x14574) + 0x10))();
    iVar4 = *(int *)(param_1 + 8);
  }
  iVar1 = msys::MComSys::_sys;
  if (iVar4 == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar4 = iVar1;
  }
  *(undefined1 *)(iVar4 + 0xe6508) = 0;
LAB_14804df0:
  FUN_1480891c(param_1 + 0x77a0);
  return;
}


// FUNC 0x14804e44 FUN_14804e44 (LoadMenu)
//   size 0x60 | file LoadMenu+0x4e44 | callers(0) | datarefs 2

void FUN_14804e44(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = msys::MLyt::isEnableAnime((MLyt *)(param_1 + 0x490));
  if (iVar1 == 0) {
    FUN_14808728(param_1,&DAT_1480e008,2,0);
    iVar1 = msys::MComSys::_sys;
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar1;
    }
    *(undefined1 *)(iVar2 + 0xe6508) = 1;
    *(code **)(param_1 + 0x20) = FUN_14803d40;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x14804eb0 FUN_14804eb0 (LoadMenu)
//   size 0x60 | file LoadMenu+0x4eb0 | callers(0) | datarefs 2

void FUN_14804eb0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = msys::MLyt::isEnableAnime((MLyt *)(param_1 + 0x490));
  if (iVar1 == 0) {
    FUN_14808728(param_1,&DAT_1480e00a,2,0);
    iVar1 = msys::MComSys::_sys;
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar1;
    }
    *(undefined1 *)(iVar2 + 0xe6508) = 1;
    *(code **)(param_1 + 0x20) = FUN_14803e38;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x14804f1c FUN_14804f1c (LoadMenu)
//   size 0xdc | file LoadMenu+0x4f1c | callers(0) | datarefs 2

void FUN_14804f1c(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = msys::MLyt::isEnableAnime((MLyt *)(param_1 + 0xe8));
  if ((iVar1 == 0) && (iVar1 = msys::MLyt::isEnableAnime((MLyt *)(param_1 + 0x490)), iVar1 == 0)) {
    msys::MLyt::setAnimeInfo((MLyt *)(param_1 + 0x490),2,0);
    msys::MLyt::setAnimeInfo((MLyt *)(param_1 + 0x490),3,0);
    msys::MLyt::setAnimeInfo((MLyt *)(param_1 + 0x490),8,0);
    msys::MLyt::setAnimeInfo((MLyt *)(param_1 + 0x490),9,0);
    msys::MLyt::setAnimeInfo((MLyt *)(param_1 + 0x490),10,0);
    iVar1 = msys::MComSys::_sys;
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar1;
    }
    Backup::init((Backup *)(iVar2 + 0xe9050),(CtrFS *)(*(int *)(iVar2 + 4) + 0x518));
    Backup::copySaveData((short)(Backup *)(iVar2 + 0xe9050),~(ushort)(DAT_003fbea0 >> 1) & 1);
    *(code **)(param_1 + 0x20) = FUN_14803f30;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x14805004 FUN_14805004 (LoadMenu)
//   size 0x8c | file LoadMenu+0x5004 | callers(0) | datarefs 1

void FUN_14805004(int param_1)

{
  if (*(char *)(param_1 + 0x4a798) != '\x01') {
    msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0xe8),2,1,(char *)0x0,(char *)0x0);
    msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x490),4,1,(char *)0x0,(char *)0x0);
  }
  FUN_14808344(param_1 + 0xd73c,param_1);
  *(code **)(param_1 + 0x20) = FUN_14805470;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


// FUNC 0x14805098 FUN_14805098 (LoadMenu)
//   size 0x60 | file LoadMenu+0x5098 | callers(0) | datarefs 2

void FUN_14805098(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = msys::MLyt::isEnableAnime((MLyt *)(param_1 + 0x490));
  if (iVar1 == 0) {
    FUN_14808728(param_1,&DAT_1480e004,2,0);
    iVar1 = msys::MComSys::_sys;
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar1;
    }
    *(undefined1 *)(iVar2 + 0xe6508) = 1;
    *(code **)(param_1 + 0x20) = FUN_148043d8;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x14805104 FUN_14805104 (LoadMenu)
//   size 0xc4 | file LoadMenu+0x5104 | callers(0) | datarefs 2

void FUN_14805104(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = msys::MLyt::isEnableAnime((MLyt *)(param_1 + 0xe8));
  if ((iVar1 == 0) && (iVar1 = msys::MLyt::isEnableAnime((MLyt *)(param_1 + 0x490)), iVar1 == 0)) {
    msys::MLyt::setAnimeInfo((MLyt *)(param_1 + 0x490),2,0);
    msys::MLyt::setAnimeInfo((MLyt *)(param_1 + 0x490),3,0);
    msys::MLyt::setAnimeInfo((MLyt *)(param_1 + 0x490),5,0);
    msys::MLyt::setAnimeInfo((MLyt *)(param_1 + 0x490),6,0);
    iVar1 = msys::MComSys::_sys;
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar1;
    }
    Backup::init((Backup *)(iVar2 + 0xe9050),(CtrFS *)(*(int *)(iVar2 + 4) + 0x518));
    Backup::deleteSaveData((Backup *)(iVar2 + 0xe9050),(short)((DAT_003fbea0 & 3) >> 1));
    *(code **)(param_1 + 0x20) = FUN_148044d0;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x148051d4 FUN_148051d4 (LoadMenu)
//   size 0x1ac | file LoadMenu+0x51d4 | callers(0) | datarefs 2

void FUN_148051d4(int param_1)

{
  int iVar1;
  int iVar2;
  GameWorkPOD *pGVar3;
  
  iVar1 = msys::MLyt::isEnableAnime((MLyt *)(param_1 + 0x490));
  if (iVar1 == 0) {
    msys::MLyt::setAnimeInfo((MLyt *)(param_1 + 0xe8),1,0);
    msys::MLyt::setAnimeInfo((MLyt *)(param_1 + 0xe8),2,0);
    msys::MLyt::setAnimeInfo((MLyt *)(param_1 + 0x490),1,0);
    msys::MLyt::setAnimeInfo((MLyt *)(param_1 + 0x490),2,0);
    msys::MLyt::setAnimeInfo((MLyt *)(param_1 + 0x490),3,0);
    msys::MLyt::setAnimeInfo((MLyt *)(param_1 + 0x490),4,0);
    msys::MLyt::setAnimeInfo((MLyt *)(param_1 + 0x490),5,0);
    msys::MLyt::setAnimeInfo((MLyt *)(param_1 + 0x490),6,0);
    msys::MLyt::setAnimeInfo((MLyt *)(param_1 + 0x490),7,0);
    msys::MLyt::setAnimeInfo((MLyt *)(param_1 + 0x490),8,0);
    msys::MLyt::setAnimeInfo((MLyt *)(param_1 + 0x490),9,0);
    msys::MLyt::setAnimeInfo((MLyt *)(param_1 + 0x490),10,0);
    msys::MLyt::setAnimeInfo((MLyt *)(param_1 + 0x490),0xb,0);
    msys::MLyt::setAnimeInfo((MLyt *)(param_1 + 0x490),0xc,0);
    msys::MLyt::stopAnimeAndSetEnd((MLyt *)(param_1 + 0xe8),1,0,(char *)0x0,(char *)0x0);
    msys::MLyt::stopAnimeAndSetEnd((MLyt *)(param_1 + 0x490),1,0,(char *)0x0,(char *)0x0);
    iVar1 = msys::MComSys::_sys;
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar1;
    }
    pGVar3 = (GameWorkPOD *)Backup::GetSaveData1(-1);
    save_load::FilePanel::build((FilePanel *)(param_1 + 0x780c),pGVar3);
    FUN_14808bb4(param_1 + 0x8620,iVar2,pGVar3 + 0x828);
    FUN_148088a4(param_1 + 0xb600,0xffffffff);
    FUN_148088a4(param_1 + 0xc114,0xffffffff);
    *(code **)(param_1 + 0x20) = FUN_14802eec;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x148053dc FUN_148053dc (LoadMenu)
//   size 0x80 | file LoadMenu+0x53dc | callers(0) | datarefs 3

void FUN_148053dc(int param_1)

{
  int iVar1;
  undefined4 local_20 [2];
  
  if (*(int *)(param_1 + 8) == 0) {
    *(undefined4 *)(param_1 + 8) = msys::MComSys::_sys;
  }
  iVar1 = *(int *)(param_1 + 8);
  local_20[0] = 0xff000000;
  MoveC::moveFrm((MoveC *)(iVar1 + 0x4acd4),(Color8 *)local_20,16.0);
  MoveC::moveFrm((MoveC *)(iVar1 + 0x4ad14),(Color8 *)local_20,16.0);
  *(undefined1 **)(param_1 + 0x20) = &LAB_14805388;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


// FUNC 0x14805470 FUN_14805470 (LoadMenu)
//   size 0x8c | file LoadMenu+0x5470 | callers(0) | datarefs 2

void FUN_14805470(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = msys::MLyt::isEnableAnime((MLyt *)(param_1 + 0x490));
  if (iVar1 == 0) {
    if (*(char *)(param_1 + 0x4a798) == '\x01') {
      uVar3 = 2;
    }
    else {
      uVar3 = (DAT_003fbea0 & 0x3f) >> 5;
    }
    FUN_14808728(param_1,&DAT_1480e010,4,uVar3);
    *(undefined1 *)(param_1 + 0x4a798) = 0xff;
    iVar1 = msys::MComSys::_sys;
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar1;
    }
    *(undefined1 *)(iVar2 + 0xe6508) = 1;
    *(code **)(param_1 + 0x20) = FUN_14804d04;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x14805510 load_menu::LoadMenuTopPage::Core::vfunc_0x8 (LoadMenu)
//   size 0xd8 | file LoadMenu+0x5510 | callers(0) | datarefs 1

int load_menu::LoadMenuTopPage::Core::vfunc_0x8(int param_1,MInput *param_2)

{
  MInput MVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  VEC2 *pVVar6;
  code *extraout_r2;
  code *pcVar7;
  bool bVar8;
  uint in_fpscr;
  undefined4 local_18;
  undefined4 uStack_14;
  
  msys::MPageBase::updateInputAllChr(*(MPageBase **)(param_1 + 4),param_2);
  bVar8 = (*(uint *)(param_1 + 0x24) & 1) == 0;
  cVar2 = *(char *)(param_1 + 0x7780);
  pcVar7 = extraout_r2;
  if (bVar8) {
    pcVar7 = *(code **)(param_1 + 0x20);
  }
  piVar4 = (int *)(param_1 + ((int)*(uint *)(param_1 + 0x24) >> 1));
  if (!bVar8) {
    pcVar7 = *(code **)(*piVar4 + *(int *)(param_1 + 0x20));
  }
  (*pcVar7)(piVar4,param_2);
  iVar3 = msys::MComSys::_sys;
  MVar1 = param_2[0x11];
  bVar8 = MVar1 == (MInput)0x0;
  if (bVar8) {
    MVar1 = param_2[0x12];
  }
  pVVar6 = (VEC2 *)0x0;
  if (!bVar8 || MVar1 != (MInput)0x0) {
    uStack_14 = VectorSignedToFloat(0x78 - (uint)*(ushort *)(param_2 + 0x16),
                                    (byte)(in_fpscr >> 0x16) & 3);
    local_18 = VectorSignedToFloat(*(ushort *)(param_2 + 0x14) - 0xa0,(byte)(in_fpscr >> 0x16) & 3);
    pVVar6 = (VEC2 *)&local_18;
  }
  MVar1 = param_2[0x12];
  iVar5 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar5 = iVar3;
  }
  ad::ctrl::ButtonGroup::Update
            ((ButtonGroup *)(param_1 + 0x7784),pVVar6,
             (bool)(*(byte *)(iVar5 + 0xe6508) & MVar1 != (MInput)0x0),MVar1 != (MInput)0x0);
  return (int)cVar2;
}


// FUNC 0x148055fc FUN_148055fc (LoadMenu)
//   size 0x35c | file LoadMenu+0x55fc | callers(0)

void FUN_148055fc(int param_1,int param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  undefined1 uVar3;
  uint uVar4;
  code *pcVar5;
  GameWorkPOD *pGVar6;
  undefined4 *puVar7;
  int iVar8;
  code *pcVar9;
  undefined4 uVar10;
  bool bVar11;
  
  bVar1 = *(byte *)(param_2 + 0x48);
  uVar4 = (uint)bVar1;
  if (param_3 == 1) {
LAB_148056dc:
    if ((uVar4 < 0xe) && ((int)*(char *)(param_1 + 0x77b8) != uVar4)) {
      uVar10 = 0;
      FUN_14808d08(param_1,0x110015,0);
      *(byte *)(param_1 + 0x77b8) = bVar1;
      iVar8 = msys::MComSys::_sys;
      switch(uVar4) {
      case 0:
      case 1:
        iVar2 = *(int *)(param_1 + 8);
        if (*(int *)(param_1 + 8) == 0) {
          *(int *)(param_1 + 8) = msys::MComSys::_sys;
          iVar2 = iVar8;
        }
        pGVar6 = (GameWorkPOD *)Backup::GetSaveData1((ushort)bVar1);
        save_load::FilePanel::build((FilePanel *)(param_1 + 0x780c),pGVar6);
        FUN_14808bb4(param_1 + 0x8620,iVar2,pGVar6 + 0x828,uVar10);
        return;
      case 3:
      case 4:
        *(byte *)(param_1 + 0x4a799) = bVar1;
        break;
      case 6:
      case 7:
      case 8:
        FUN_14808344(param_1 + 0xd73c,param_1,0xffffffff,uVar10);
        return;
      }
    }
switchD_14805658_default:
    return;
  }
  if (param_3 == 4) {
    if (uVar4 == 0xe || uVar4 == 5) {
      uVar10 = 0x110017;
    }
    else {
      uVar10 = 0x110016;
    }
    FUN_14808d08(param_1,uVar10,0,0,0);
    iVar2 = msys::MComSys::_sys;
    iVar8 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar8 = iVar2;
    }
    *(undefined1 *)(iVar8 + 0xe6508) = 0;
    goto LAB_148056dc;
  }
  if (param_3 != 5) {
    return;
  }
  msys::MCursorBase::setVisible((MCursorBase *)(param_1 + 0x77a0),false);
  switch(uVar4) {
  case 0:
  case 1:
    puVar7 = &DAT_1480e07c;
    goto LAB_148057c4;
  case 2:
    puVar7 = &DAT_1480e084;
    goto LAB_148057c4;
  case 3:
    pcVar9 = FUN_148039b0;
    uVar10 = 0;
    break;
  case 4:
    puVar7 = &DAT_1480e094;
    goto LAB_148057c4;
  case 5:
    pcVar9 = FUN_148039e8;
    pcVar5 = *(code **)(param_1 + 0x20);
    if (pcVar5 == FUN_148039e8) {
      pcVar9 = *(code **)(param_1 + 0x24);
    }
    if (pcVar5 == FUN_148039e8 && pcVar9 == (code *)0x0) {
      *(undefined1 *)(param_1 + 0x77b8) = 4;
      *(undefined1 *)(param_1 + 0x4a799) = 4;
    }
    else {
      pcVar9 = FUN_148043d8;
      if (pcVar5 == FUN_148043d8) {
        pcVar9 = *(code **)(param_1 + 0x24);
      }
      if (pcVar5 == FUN_148043d8 && pcVar9 == (code *)0x0) {
        msys::MLyt::setAnimeInfo((MLyt *)(param_1 + 0x490),5,0);
        uVar3 = 4;
        *(undefined1 *)(param_1 + 0x77b8) = 4;
      }
      else {
        bVar11 = pcVar5 == FUN_14803d40;
        if (bVar11) {
          pcVar5 = *(code **)(param_1 + 0x24);
        }
        if (bVar11 && pcVar5 == (code *)0x0) {
          msys::MLyt::setAnimeInfo((MLyt *)(param_1 + 0x490),8,0);
          iVar8 = *(int *)(param_1 + 8);
        }
        else {
          msys::MLyt::setAnimeInfo((MLyt *)(param_1 + 0x490),8,0);
          msys::MLyt::setAnimeInfo((MLyt *)(param_1 + 0x490),9,0);
          iVar8 = *(int *)(param_1 + 8);
        }
        iVar2 = msys::MComSys::_sys;
        if (iVar8 == 0) {
          *(int *)(param_1 + 8) = msys::MComSys::_sys;
          iVar8 = iVar2;
        }
        pGVar6 = (GameWorkPOD *)Backup::GetSaveData1((short)((DAT_003fbea0 & 3) >> 1));
        save_load::FilePanel::build((FilePanel *)(param_1 + 0x780c),pGVar6);
        FUN_14808bb4(param_1 + 0x8620,iVar8,pGVar6 + 0x828);
        uVar3 = 3;
        *(undefined1 *)(param_1 + 0x77b8) = 3;
      }
      *(undefined1 *)(param_1 + 0x4a799) = uVar3;
    }
    pcVar9 = FUN_148040b4;
    uVar10 = 0;
    break;
  case 6:
    pcVar9 = FUN_148053dc;
    uVar10 = 0;
    break;
  case 7:
    puVar7 = &DAT_1480e0a4;
LAB_148057c4:
    pcVar9 = (code *)*puVar7;
    uVar10 = puVar7[1];
    break;
  case 8:
    *(undefined1 *)(param_1 + 0x7780) = 1;
    return;
  case 9:
    pcVar9 = FUN_14804844;
    uVar10 = 0;
    break;
  case 10:
    pcVar9 = FUN_1480487c;
    uVar10 = 0;
    break;
  case 0xb:
    pcVar9 = *(code **)(param_1 + 0x20);
    bVar11 = pcVar9 == FUN_14803d40;
    if (bVar11) {
      pcVar9 = *(code **)(param_1 + 0x24);
    }
    if (bVar11 && pcVar9 == (code *)0x0) {
      pcVar9 = FUN_1480421c;
      uVar10 = 0;
      break;
    }
    goto LAB_1480596c;
  case 0xc:
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
    }
    iVar8 = Backup::IsNew(~(ushort)(DAT_003fbea0 >> 1) & 1);
    if (iVar8 == 0) {
      pcVar9 = FUN_1480417c;
      uVar10 = 0;
      break;
    }
LAB_1480596c:
    pcVar9 = FUN_14804254;
    uVar10 = 0;
    break;
  case 0xd:
    *(undefined1 *)(param_1 + 0x77b8) = 3;
    *(undefined1 *)(param_1 + 0x4a799) = 3;
    pcVar9 = FUN_148040b4;
    uVar10 = 0;
    break;
  case 0xe:
    pcVar9 = *(code **)(param_1 + 0x20);
    bVar11 = pcVar9 == FUN_14802d5c;
    if (bVar11) {
      pcVar9 = *(code **)(param_1 + 0x24);
    }
    if (bVar11 && pcVar9 == (code *)0x0) {
      pcVar9 = FUN_14803c80;
    }
    else {
      pcVar9 = FUN_148040b4;
    }
    uVar10 = 0;
    break;
  default:
    goto switchD_14805658_default;
  }
  *(code **)(param_1 + 0x20) = pcVar9;
  *(undefined4 *)(param_1 + 0x24) = uVar10;
  return;
}


// FUNC 0x14805a08 FUN_14805a08 (LoadMenu)
//   size 0xb8 | file LoadMenu+0x5a08 | callers(0) | datarefs 1

void FUN_14805a08(int param_1)

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
            (*(TaskBase **)(iVar4 + 4),(Resource *)(param_1 + 0xa4),
             (FileContext *)(*(int *)(iVar1 + 0x278) + 0xa8),"?MENU_FILE_LOAD",pMVar3,0x7f,
             (ResCacheArg *)0x0);
  *(undefined1 **)(param_1 + 0x10) = &LAB_14802c50;
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}


// FUNC 0x14805ae0 FUN_14805ae0 (LoadMenu)
//   size 0x16c | file LoadMenu+0x5ae0 | callers(0) | datarefs 4

void FUN_14805ae0(int param_1)

{
  int iVar1;
  int iVar2;
  GameWorkPOD *pGVar3;
  float fVar4;
  LytAnim aLStackY_c0 [128];
  
  iVar2 = msys::MComSys::_sys;
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  else {
    iVar2 = *(int *)(param_1 + 8);
  }
  iVar2 = ad::fw::TaskBase::isFps30(*(TaskBase **)(iVar2 + 4));
  fVar4 = 1.0;
  if (iVar2 != 0) {
    fVar4 = 2.0;
  }
  iVar2 = Frm::update(fVar4);
  if (iVar2 == 0) {
    msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x490),7,0,(char *)0x0,(char *)0x0);
    msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x490),0xb,0,(char *)0x0,(char *)0x0);
    msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x490),0xc,0,(char *)0x0,(char *)0x0);
    iVar1 = msys::MComSys::_sys;
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar1;
    }
    pGVar3 = (GameWorkPOD *)Backup::GetSaveData1(-1);
    save_load::FilePanel::build((FilePanel *)(param_1 + 0x780c),pGVar3);
    FUN_14808bb4(param_1 + 0x8620,iVar2,pGVar3 + 0x828);
    FUN_148088a4(param_1 + 0xb600,0xffffffff);
    FUN_148088a4(param_1 + 0xc114,0xffffffff);
    ad::lyt::LytAnim::init(aLStackY_c0 + 0x80,*(Layout **)(param_1 + 0x238),"COPY","");
    ad::lyt::LytAnim::stopAndSetFrm(aLStackY_c0 + 0x80,0.0);
    ad::lyt::LytAnim::term(aLStackY_c0 + 0x80,true);
    *(code **)(param_1 + 0x20) = FUN_148049c0;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x14805c80 FUN_14805c80 (LoadMenu)
//   size 0x1ac | file LoadMenu+0x5c80 | callers(1) 0x1480610c

void FUN_14805c80(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  puVar1 = (undefined4 *)FUN_1480925c();
  *puVar1 = &load_menu::LoadMenuTopPage::Core::vtable;
  iVar2 = ad::ctrl::ButtonGroup::ButtonGroup((ButtonGroup *)(puVar1 + 0x1de1));
  puVar1 = (undefined4 *)msys::MCursorBase::MCursorBase((MCursorBase *)(iVar2 + 0x1c));
  *puVar1 = &vtable_for_N4msys7MCursorILj14EEE;
  puVar1[0xc] = 0;
  puVar1[0xd] = 0;
  puVar1[0xe] = 0;
  puVar1[0xf] = 0;
  puVar1[0x10] = 0;
  puVar1[0x11] = 0;
  puVar1[0x12] = 0;
  puVar1[0x13] = 0;
  puVar1[0x14] = 0;
  puVar1[0x15] = 0;
  puVar1[0x16] = 0;
  puVar1[0x17] = 0;
  puVar1[0x18] = 0;
  puVar1[0x19] = 0;
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(puVar1 + 0x1a,&LAB_14802a90,0x1efc,2);
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(iVar2 + 0x3df8,&LAB_14802bc0,0xb14,3);
  puVar1 = (undefined4 *)FUN_14808f5c(iVar2 + 0x213c);
  *puVar1 = &msys::MMsg::vtable;
  iVar2 = MessageSimple::MessageSimple((MessageSimple *)(puVar1 + 0x53));
  *(undefined4 *)(iVar2 + 0x6ae0) = 0;
  *(undefined1 *)(iVar2 + 0x6ae4) = 0;
  *(undefined1 *)(iVar2 + 0x6ae5) = 0;
  *(undefined4 *)(iVar2 + 0x6ae8) = 0;
  *(undefined4 *)(iVar2 + 0x6af4) = 0x400;
  *(undefined4 *)(iVar2 + 0x6aec) = 0;
  *(undefined4 *)(iVar2 + -0x14c) = &msys::MMoveMsg::vtable;
  *(undefined4 *)(iVar2 + 0x6af8) = 0;
  *(undefined4 *)(iVar2 + 0x6afc) = 0x3f800000;
  *(undefined4 *)(iVar2 + 0x6b00) = 0;
  *(undefined2 *)(iVar2 + 0x6b04) = 1;
  *(undefined2 *)(iVar2 + 0x6b06) = 0;
  *(undefined1 *)(iVar2 + 0x6b08) = 0;
  puVar1 = (undefined4 *)FUN_14809048();
  uVar3 = puVar1[1];
  uVar4 = puVar1[2];
  *(undefined4 *)(iVar2 + 0x6b0c) = *puVar1;
  *(undefined4 *)(iVar2 + 0x6b10) = uVar3;
  *(undefined4 *)(iVar2 + 0x6b14) = uVar4;
  *(undefined4 *)(iVar2 + 0x6b18) = 0;
  *(undefined4 *)(iVar2 + -0x14c) = &save_load::Summary::vtable;
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(iVar2 + 0x6b1c,&LAB_148013b4,0x1c,2);
  *(undefined ***)(iVar2 + -0x6c68) = &load_menu::LoadMenuTopPage::Core::GameSelectU::vtable;
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(iVar2 + 0x38,&LAB_148091a8,0x2c,8);
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(iVar2 + 0x19c,FUN_148014f4,0x6c44,8);
  *(code **)(iVar2 + -0x14568) = FUN_14805a08;
  *(undefined4 *)(iVar2 + -0x14564) = 0;
  *(undefined1 **)(iVar2 + -0x14560) = &LAB_14805c68;
  *(undefined4 *)(iVar2 + -0x1455c) = 0;
  *(code **)(iVar2 + -0x14558) = FUN_14802eec;
  *(undefined4 *)(iVar2 + -0x14554) = 0;
  return;
}


// FUNC 0x14805e70 load_menu::LoadMenuTopPage::Core::vfunc_0x4 (LoadMenu)
//   size 0x11c | file LoadMenu+0x5e70 | callers(0) | datarefs 1

void load_menu::LoadMenuTopPage::Core::vfunc_0x4(undefined4 *param_1)

{
  int iVar1;
  void *pvVar2;
  undefined4 *puVar3;
  
  *param_1 = &vtable;
  ad::ctrl::ButtonGroup::FreeAll((ButtonGroup *)(param_1 + 0x1de1));
  msys::MCursorBase::term((MCursorBase *)(param_1 + 0x1de8));
  __aeabi_vec_dtor(param_1 + 0x515e,FUN_1480153c,0x6c44,8);
  puVar3 = param_1 + 0x35cf;
  *puVar3 = &GameSelectU::vtable;
  __aeabi_vec_dtor(param_1 + 0x50f7,&LAB_148091f8,0x2c,8);
  *puVar3 = &save_load::Summary::vtable;
  __aeabi_vec_dtor(param_1 + 0x50e9,&LAB_148013f0,0x1c,2);
  param_1[0x50e2] = 0;
  *puVar3 = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar1 = MessageSimple::~MessageSimple((MessageSimple *)(param_1 + 0x3622));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  __aeabi_vec_dtor(iVar1 + -0x213c,FUN_14802c18,0xb14,3);
  __aeabi_vec_dtor(iVar1 + -0x5f34,&LAB_14802b2c,0x1efc,2);
  iVar1 = msys::MCursorBase::~MCursorBase((MCursorBase *)(iVar1 + -0x5f9c));
  iVar1 = ad::ctrl::ButtonGroup::~ButtonGroup((ButtonGroup *)(iVar1 + -0x1c));
  pvVar2 = (void *)LoadMenuPageBase::Core::vfunc_0x0(iVar1 + -0x7784);
  operator_delete(pvVar2);
  return;
}


// FUNC 0x14805fc0 load_menu::LoadMenuTopPage::Core::vfunc_0x0 (LoadMenu)
//   size 0x118 | file LoadMenu+0x5fc0 | callers(0) | datarefs 1

void load_menu::LoadMenuTopPage::Core::vfunc_0x0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  *param_1 = &vtable;
  ad::ctrl::ButtonGroup::FreeAll((ButtonGroup *)(param_1 + 0x1de1));
  msys::MCursorBase::term((MCursorBase *)(param_1 + 0x1de8));
  __aeabi_vec_dtor(param_1 + 0x515e,FUN_1480153c,0x6c44,8);
  puVar2 = param_1 + 0x35cf;
  *puVar2 = &GameSelectU::vtable;
  __aeabi_vec_dtor(param_1 + 0x50f7,&LAB_148091f8,0x2c,8);
  *puVar2 = &save_load::Summary::vtable;
  __aeabi_vec_dtor(param_1 + 0x50e9,&LAB_148013f0,0x1c,2);
  param_1[0x50e2] = 0;
  *puVar2 = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar1 = MessageSimple::~MessageSimple((MessageSimple *)(param_1 + 0x3622));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  __aeabi_vec_dtor(iVar1 + -0x213c,FUN_14802c18,0xb14,3);
  __aeabi_vec_dtor(iVar1 + -0x5f34,&LAB_14802b2c,0x1efc,2);
  iVar1 = msys::MCursorBase::~MCursorBase((MCursorBase *)(iVar1 + -0x5f9c));
  iVar1 = ad::ctrl::ButtonGroup::~ButtonGroup((ButtonGroup *)(iVar1 + -0x1c));
  LoadMenuPageBase::Core::vfunc_0x0(iVar1 + -0x7784);
  return;
}


// FUNC 0x1480610c load_menu::LoadMenuTopPage::vfunc_0x30 (LoadMenu)
//   size 0x30 | file LoadMenu+0x610c | callers(0) | datarefs 1

void load_menu::LoadMenuTopPage::vfunc_0x30(int param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(0x4a79c,*(MemAlcBase **)(param_1 + 0x18),(char *)0x0,0);
  uVar2 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_14805c80(pvVar1,param_1);
  }
  *(undefined4 *)(param_1 + 0x20) = uVar2;
  return;
}


// FUNC 0x14806140 load_menu::LoadMenuTopPage::vfunc_0x24 (LoadMenu)
//   size 0x8 | file LoadMenu+0x6140 | callers(0) | datarefs 1

undefined4 load_menu::LoadMenuTopPage::vfunc_0x24(void)

{
  return 0;
}


// FUNC 0x14806148 load_menu::LoadMenuTopPage::vfunc_0x4 (LoadMenu)
//   size 0x10 | file LoadMenu+0x6148 | callers(0) | datarefs 1

void load_menu::LoadMenuTopPage::vfunc_0x4(void)

{
  void *pvVar1;
  
  pvVar1 = (void *)LoadMenuPageBase::vfunc_0x0();
  operator_delete(pvVar1);
  return;
}


// FUNC 0x14806294 FUN_14806294 (LoadMenu)
//   size 0xc4 | file LoadMenu+0x6294 | callers(0) | datarefs 4

void FUN_14806294(int param_1)

{
  int iVar1;
  code *pcVar2;
  
  if (*(int *)(param_1 + 8) == 0) {
    *(undefined4 *)(param_1 + 8) = msys::MComSys::_sys;
  }
  iVar1 = Backup::errorCode();
  if (iVar1 == 0) {
    if (*(int *)(param_1 + 8) == 0) {
      *(undefined4 *)(param_1 + 8) = msys::MComSys::_sys;
    }
    iVar1 = Backup::isBusyFormat();
    if (iVar1 == 0) {
      if (*(int *)(param_1 + 8) == 0) {
        *(undefined4 *)(param_1 + 8) = msys::MComSys::_sys;
      }
      iVar1 = save_load::SaveLoadSys::saveWriteInitData(*(SaveLoadSys **)(param_1 + 8));
      if (iVar1 == 0) {
        pcVar2 = FUN_148090a0;
      }
      else {
        pcVar2 = FUN_14806360;
      }
      *(code **)(param_1 + 0x20) = pcVar2;
      *(undefined4 *)(param_1 + 0x24) = 0;
    }
  }
  else {
    if ((iVar1 - 0x2001U < 2) || (iVar1 - 0x2001U == 2)) {
      if (*(int *)(param_1 + 8) == 0) {
        *(undefined4 *)(param_1 + 8) = msys::MComSys::_sys;
      }
      save_load::SaveLoadSys::saveFormat();
      return;
    }
    *(code **)(param_1 + 0x20) = FUN_148090a0;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x14806360 FUN_14806360 (LoadMenu)
//   size 0xd0 | file LoadMenu+0x6360 | callers(0) | datarefs 2

void FUN_14806360(int param_1,undefined4 param_2)

{
  SaveLoadSys *this;
  SaveLoadSys *pSVar1;
  int iVar2;
  code *UNRECOVERED_JUMPTABLE;
  int *piVar3;
  uint uVar4;
  
  if (*(int *)(param_1 + 8) == 0) {
    *(SaveLoadSys **)(param_1 + 8) = msys::MComSys::_sys;
  }
  iVar2 = Backup::errorCode();
  pSVar1 = msys::MComSys::_sys;
  if (iVar2 == 0) {
    this = *(SaveLoadSys **)(param_1 + 8);
    if (*(SaveLoadSys **)(param_1 + 8) == (SaveLoadSys *)0x0) {
      *(SaveLoadSys **)(param_1 + 8) = msys::MComSys::_sys;
      this = pSVar1;
    }
    iVar2 = save_load::SaveLoadSys::saveIsBusyWriting(this);
    if (iVar2 == 0) {
      Message::close((Message *)(param_1 + 0x984));
      UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x28);
      uVar4 = *(uint *)(param_1 + 0x2c);
      piVar3 = (int *)(param_1 + ((int)uVar4 >> 1));
      *(code **)(param_1 + 0x20) = UNRECOVERED_JUMPTABLE;
      *(uint *)(param_1 + 0x24) = uVar4;
      if ((uVar4 & 1) != 0) {
        UNRECOVERED_JUMPTABLE = *(code **)(UNRECOVERED_JUMPTABLE + *piVar3);
      }
                    /* WARNING: Could not recover jumptable at 0x1480640c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE)(piVar3,param_2);
      return;
    }
  }
  else {
    if ((iVar2 - 0x2001U < 2) || (iVar2 - 0x2001U == 2)) {
      if (*(int *)(param_1 + 8) == 0) {
        *(SaveLoadSys **)(param_1 + 8) = msys::MComSys::_sys;
      }
      save_load::SaveLoadSys::saveFormat();
      UNRECOVERED_JUMPTABLE = FUN_14806294;
    }
    else {
      UNRECOVERED_JUMPTABLE = FUN_148090a0;
    }
    *(code **)(param_1 + 0x20) = UNRECOVERED_JUMPTABLE;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x14806438 FUN_14806438 (LoadMenu)
//   size 0x50 | file LoadMenu+0x6438 | callers(0) | datarefs 8

void FUN_14806438(int param_1)

{
  int iVar1;
  int iVar2;
  
  save_load::MsgWnd::play((MsgWnd *)(param_1 + 0x838),"menu_save_err_01",(InsParam *)0x0);
  iVar1 = msys::MComSys::_sys;
  iVar2 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar2 = iVar1;
  }
  *(undefined1 *)(iVar2 + 0xe6508) = 0;
  *(code **)(param_1 + 0x20) = FUN_1480910c;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


// FUNC 0x148064a4 load_menu::LoadMenuPageBase::Core::Dfx::vfunc_0x38 (LoadMenu)
//   size 0x164 | file LoadMenu+0x64a4 | callers(1) 0x14806ac8 | datarefs 1

void load_menu::LoadMenuPageBase::Core::Dfx::vfunc_0x38(MDfxChr *param_1)

{
  void *pvVar1;
  uint uVar2;
  void *pvVar3;
  
  msys::MDfxChr::term(param_1);
  pvVar1 = *(void **)(param_1 + 0x174);
  if (pvVar1 != (void *)0x0) {
    *(undefined4 *)((int)pvVar1 + 0x34) = 0;
    uVar2 = *(uint *)((int)pvVar1 + 0x30);
    if (uVar2 < *(uint *)((int)pvVar1 + 0x2c)) {
      do {
        uVar2 = uVar2 - 0xc;
      } while (*(uint *)((int)pvVar1 + 0x2c) != uVar2);
    }
    *(undefined4 *)((int)pvVar1 + 0x2c) = 0;
    *(undefined4 *)((int)pvVar1 + 0x30) = 0;
    pvVar3 = *(void **)((int)pvVar1 + 0x28);
    *(undefined4 *)((int)pvVar1 + 0x28) = 0;
    if (pvVar3 != (void *)0x0) {
      operator_delete(pvVar3);
    }
    uVar2 = *(uint *)((int)pvVar1 + 0x30);
    if (uVar2 < *(uint *)((int)pvVar1 + 0x2c)) {
      do {
        uVar2 = uVar2 - 0xc;
      } while (*(uint *)((int)pvVar1 + 0x2c) != uVar2);
    }
    if (*(void **)((int)pvVar1 + 0x28) != (void *)0x0) {
      operator_delete(*(void **)((int)pvVar1 + 0x28));
    }
    *(undefined4 *)((int)pvVar1 + 0x18) = 0;
    *(undefined4 *)((int)pvVar1 + 0x10) = 0;
    *(undefined4 *)((int)pvVar1 + 0x14) = 0;
    pvVar3 = *(void **)((int)pvVar1 + 0xc);
    *(undefined4 *)((int)pvVar1 + 0xc) = 0;
    if (pvVar3 != (void *)0x0) {
      operator_delete(pvVar3);
    }
    if (*(void **)((int)pvVar1 + 0xc) != (void *)0x0) {
      operator_delete(*(void **)((int)pvVar1 + 0xc));
    }
    operator_delete(pvVar1);
  }
  *(undefined4 *)(param_1 + 0x174) = 0;
  pvVar1 = *(void **)(param_1 + 0x178);
  if (pvVar1 != (void *)0x0) {
    *(undefined4 *)((int)pvVar1 + 0x34) = 0;
    uVar2 = *(uint *)((int)pvVar1 + 0x30);
    if (uVar2 < *(uint *)((int)pvVar1 + 0x2c)) {
      do {
        uVar2 = uVar2 - 0xc;
      } while (*(uint *)((int)pvVar1 + 0x2c) != uVar2);
    }
    *(undefined4 *)((int)pvVar1 + 0x2c) = 0;
    *(undefined4 *)((int)pvVar1 + 0x30) = 0;
    pvVar3 = *(void **)((int)pvVar1 + 0x28);
    *(undefined4 *)((int)pvVar1 + 0x28) = 0;
    if (pvVar3 != (void *)0x0) {
      operator_delete(pvVar3);
    }
    uVar2 = *(uint *)((int)pvVar1 + 0x30);
    if (uVar2 < *(uint *)((int)pvVar1 + 0x2c)) {
      do {
        uVar2 = uVar2 - 0xc;
      } while (*(uint *)((int)pvVar1 + 0x2c) != uVar2);
    }
    if (*(void **)((int)pvVar1 + 0x28) != (void *)0x0) {
      operator_delete(*(void **)((int)pvVar1 + 0x28));
    }
    *(undefined4 *)((int)pvVar1 + 0x18) = 0;
    *(undefined4 *)((int)pvVar1 + 0x10) = 0;
    *(undefined4 *)((int)pvVar1 + 0x14) = 0;
    pvVar3 = *(void **)((int)pvVar1 + 0xc);
    *(undefined4 *)((int)pvVar1 + 0xc) = 0;
    if (pvVar3 != (void *)0x0) {
      operator_delete(pvVar3);
    }
    if (*(void **)((int)pvVar1 + 0xc) != (void *)0x0) {
      operator_delete(*(void **)((int)pvVar1 + 0xc));
    }
    operator_delete(pvVar1);
  }
  *(undefined4 *)(param_1 + 0x178) = 0;
  return;
}


// FUNC 0x14806608 FUN_14806608 (LoadMenu)
//   size 0x10c | file LoadMenu+0x6608 | callers(3) 0x14806ac8 0x1480c170 0x14809654

void FUN_14806608(MDfxChr *param_1,int param_2,MChrBaseCore *param_3,char *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  iVar2 = msys::MChrBaseCore::getDisplayID(param_3);
  iVar1 = msys::MComSys::_sys;
  iVar3 = *(int *)(param_2 + 8);
  if (iVar2 == 0x400) {
    if (iVar3 == 0) {
      *(int *)(param_2 + 8) = msys::MComSys::_sys;
      iVar3 = iVar1;
    }
    iVar2 = msys::MComSys::_sys;
    iVar1 = iVar3;
    if (iVar3 == 0) {
      *(int *)(param_2 + 8) = msys::MComSys::_sys;
      iVar1 = iVar2;
    }
    msys::MDfxChr::init(param_1,*(MemAlcBase **)(*(int *)(param_2 + 4) + 0x18),
                        *(MDfxSys **)(iVar1 + 0xe64f0),(Scene *)(iVar3 + 0x4aaa0),0x400);
  }
  else {
    if (iVar3 == 0) {
      *(int *)(param_2 + 8) = msys::MComSys::_sys;
      iVar3 = iVar1;
    }
    iVar2 = msys::MComSys::_sys;
    iVar1 = iVar3;
    if (iVar3 == 0) {
      *(int *)(param_2 + 8) = msys::MComSys::_sys;
      iVar1 = iVar2;
    }
    msys::MDfxChr::init(param_1,*(MemAlcBase **)(*(int *)(param_2 + 4) + 0x18),
                        *(MDfxSys **)(iVar1 + 0xe64f0),(Scene *)(iVar3 + 0x4aba4),0x401);
  }
  if (param_4 != (char *)0x0) {
    msys::MLyt::attachMChr
              ((MLyt *)param_3,(MChrBase *)param_1,param_4,(char *)0x0,(char *)0x0,(char *)0x0);
  }
  puVar4 = (undefined4 *)FUN_14809048();
  MoveVBase::stop((MoveVBase *)(param_1 + 0xcc));
  uVar5 = *puVar4;
  uVar6 = puVar4[1];
  uVar7 = puVar4[2];
  *(undefined4 *)(param_1 + 0xe8) = uVar5;
  *(undefined4 *)(param_1 + 0xec) = uVar6;
  *(undefined4 *)(param_1 + 0xf0) = uVar7;
  *(undefined4 *)(param_1 + 0xd0) = uVar5;
  *(undefined4 *)(param_1 + 0xd4) = uVar6;
  *(undefined4 *)(param_1 + 0xd8) = uVar7;
  return;
}


// FUNC 0x14806720 FUN_14806720 (LoadMenu)
//   size 0xc0 | file LoadMenu+0x6720 | callers(5) 0x1480c224 0x14806ac8 0x14809874 0x1480b07c 0x1480baa4

void FUN_14806720(int *param_1,int param_2,InsParam *param_3,undefined4 param_4)

{
  int iVar1;
  wchar_t *pwVar2;
  int iVar3;
  
  iVar1 = msys::MComSys::_sys;
  if (param_2 != 0) {
    iVar3 = *(int *)(*param_1 + 8);
    if (iVar3 == 0) {
      *(int *)(*param_1 + 8) = msys::MComSys::_sys;
      iVar3 = iVar1;
    }
    pwVar2 = (wchar_t *)FUN_14808da8(iVar3,0,param_2,param_4,param_4);
    msys::MMsg::playStr((MMsg *)(param_1 + 1),pwVar2,param_3,false);
  }
  Message::close((Message *)(*param_1 + 0x984));
  msys::MLyt::playAnimeFromNo((MLyt *)(*param_1 + 0xe8),2,1,(char *)0x0,(char *)0x0);
  msys::MLyt::playAnimeFromNo((MLyt *)(*param_1 + 0xe8),1,0,(char *)0x0,(char *)0x0);
  msys::MLyt::playAnimeFromNo((MLyt *)(*param_1 + 0x490),1,0,(char *)0x0,(char *)0x0);
  return;
}


// FUNC 0x148067e4 FUN_148067e4 (LoadMenu)
//   size 0x1a8 | file LoadMenu+0x67e4 | callers(5) 0x1480c224 0x14809874 0x1480b07c 0x1480ad78 0x14809c1c

void FUN_148067e4(int *param_1,int param_2)

{
  undefined1 uVar1;
  ushort uVar2;
  Unit *this;
  MLyt *pMVar3;
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  
  if (*(char *)((int)param_1 + 0x183) == '\0') {
    if (param_2 == 0) {
      iVar4 = ad::nfp::IsConnected();
      *(char *)(param_1 + 0x61) = (char)iVar4;
      if (iVar4 == 0) {
        pcVar6 = "AMB_wave";
      }
      else {
        pcVar6 = "AMB_put";
      }
      msys::MLyt::createAnime
                ((MLyt *)(*param_1 + 0x490),*(undefined1 *)((int)param_1 + 0x182),pcVar6,
                 "AMB_L_guidance",1,0xffffffff);
      if (((char)param_1[0x61] == '\0') && (iVar4 = ad::nfp::GetNewResult(), iVar4 == 0)) {
        FUN_148069e0(*param_1 + 0x8bc8,"amiibo_sys_err_04",0);
        msys::MLyt::stopAnimeAndSetEnd((MLyt *)(*param_1 + 0x490),1,0,(char *)0x0,(char *)0x0);
      }
      goto LAB_148068f0;
    }
    if ((char)param_1[0x61] == '\0') goto LAB_148068f0;
    uVar1 = *(undefined1 *)((int)param_1 + 0x182);
    uVar5 = *(undefined4 *)(&DAT_148175d8 + param_2 * 4);
    pcVar6 = "AMB_L_guidance";
    pMVar3 = (MLyt *)(*param_1 + 0x490);
  }
  else {
    this = (Unit *)param_1[0x56];
    if ((this == (Unit *)0x0) ||
       (((*(Unit **)(this + 4) == this + 4 && (this[0x172] == (Unit)0x0)) ||
        (*(uint *)(this + 0x250) != (uint)*(ushort *)(&DAT_1480e2ec + param_2 * 2))))) {
      uVar2 = *(ushort *)(&DAT_1480e2ec + param_2 * 2);
      if (this != (Unit *)0x0) {
        ad::dfx::Unit::forceDeletable(this);
      }
      msys::MDfxChr::playDfx((MDfxChr *)(param_1 + 1),(uint)uVar2);
      *(undefined2 *)(param_1[0x56] + 0xf2) = 0;
    }
    msys::MLyt::playAnimeFromNo((MLyt *)(*param_1 + 0xe8),3,1,(char *)0x0,(char *)0x0);
    uVar5 = *(undefined4 *)(&DAT_148175c8 + param_2 * 4);
    uVar1 = *(undefined1 *)((int)param_1 + 0x182);
    pcVar6 = "AMB_U_guidance";
    pMVar3 = (MLyt *)(*param_1 + 0xe8);
  }
  msys::MLyt::createAnime(pMVar3,uVar1,uVar5,pcVar6,1,0xffffffff);
LAB_148068f0:
  *(char *)(param_1 + 0x60) = (char)param_2;
  return;
}


// FUNC 0x148069e0 FUN_148069e0 (LoadMenu)
//   size 0x74 | file LoadMenu+0x69e0 | callers(4) 0x148067e4 0x14809874 0x1480ad78 0x14809c1c

void FUN_148069e0(int *param_1,char *param_2,InsParam *param_3)

{
  save_load::MsgWnd::play((MsgWnd *)(*param_1 + 0x838),param_2,param_3);
  msys::MLyt::playAnimeFromNo((MLyt *)(*param_1 + 0xe8),2,0,(char *)0x0,(char *)0x0);
  msys::MLyt::playAnimeFromNo((MLyt *)(*param_1 + 0xe8),1,1,(char *)0x0,(char *)0x0);
  msys::MLyt::playAnimeFromNo((MLyt *)(*param_1 + 0x490),1,1,(char *)0x0,(char *)0x0);
  return;
}


// FUNC 0x14806a54 FUN_14806a54 (LoadMenu)
//   size 0x74 | file LoadMenu+0x6a54 | callers(6) 0x14809874 0x1480c6ac 0x1480b1f0 0x1480b040 0x1480b194 0x1480b1ac

void FUN_14806a54(int *param_1)

{
  Message::close((Message *)(*param_1 + 0x984));
  msys::MLyt::playAnimeFromNo((MLyt *)(*param_1 + 0xe8),2,0,(char *)0x0,(char *)0x0);
  msys::MLyt::playAnimeFromNo((MLyt *)(*param_1 + 0xe8),1,0,(char *)0x0,(char *)0x0);
  msys::MLyt::playAnimeFromNo((MLyt *)(*param_1 + 0x490),1,0,(char *)0x0,(char *)0x0);
  return;
}


// FUNC 0x14806ac8 FUN_14806ac8 (LoadMenu)
//   size 0x152c | file LoadMenu+0x6ac8 | callers(6) 0x14809874 0x1480a424 0x1480ab28 0x1480ab9c 0x14809c1c 0x14809840

undefined4 FUN_14806ac8(int *param_1)

{
  ushort uVar1;
  short sVar2;
  byte bVar3;
  char cVar4;
  int iVar5;
  TaskBase *this;
  char *pcVar6;
  int *piVar7;
  short *psVar8;
  int iVar9;
  int iVar10;
  char *pcVar11;
  int *piVar12;
  int iVar13;
  MDfxChr *this_00;
  FileContext *pFVar14;
  MoveVBase *this_01;
  CellAnime *this_02;
  uint uVar15;
  MCellAnime *this_03;
  bool bVar16;
  float fVar17;
  MemAlcBase *pMVar18;
  float fVar19;
  float fVar20;
  undefined1 uStack00000000;
  VEC3 aVStackY_3a0 [128];
  int in_stack_fffffcf4;
  uint *in_stack_fffffcf8;
  int in_stack_fffffcfc;
  VEC3 aVStack_2fa [18];
  FileContext *local_2e8;
  TransMultiSymbol aTStack_2e4 [76];
  undefined2 local_298;
  undefined2 local_218;
  undefined2 local_198;
  uint local_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined4 local_10c;
  Frm *local_108;
  float local_f8;
  float local_f4;
  undefined4 local_f0;
  KJItemData aKStack_e8 [72];
  uchar local_a0;
  float local_94;
  float local_90;
  undefined4 local_8c;
  int local_88;
  float local_84;
  int local_80;
  int local_78;
  float local_74;
  int local_70;
  TransMultiSymbol aTStack_6c [44];
  uint *local_40 [2];
  undefined4 local_38;
  
  iVar5 = msys::MComSys::_sys;
  iVar9 = *(int *)(*param_1 + 8);
  if (iVar9 == 0) {
    *(int *)(*param_1 + 8) = msys::MComSys::_sys;
    iVar9 = iVar5;
  }
  iVar5 = param_1[0x3c0];
  pMVar18 = (MemAlcBase *)(param_1 + 0x153);
  local_108 = (Frm *)(param_1 + 0x3c1);
  fVar20 = 2.0;
  fVar19 = 1.0;
  iVar10 = iVar5 + -0x10009;
  this_02 = (CellAnime *)(param_1 + 0x1a6);
  this_01 = (MoveVBase *)(param_1 + 0x186);
  if (iVar5 == 0x10009) {
LAB_14807814:
    iVar5 = ad::fw::TaskBase::isFps30(*(TaskBase **)(iVar9 + 4));
    if (iVar5 != 0) {
      fVar19 = fVar20;
    }
    iVar5 = Frm::update(fVar19);
    if (iVar5 != 0) {
      return 0;
    }
    param_1[0x3c0] = param_1[0x3c0] + 1;
LAB_14807864:
    iVar5 = MoveVBase::isBusy(this_01);
joined_r0x14807874:
    if (iVar5 != 0) {
      return 0;
    }
  }
  else {
    if (0x10008 < iVar5) {
      this_03 = (MCellAnime *)(param_1 + 0x261);
      this_00 = (MDfxChr *)(param_1 + 0x301);
      iVar5 = iVar5 + -0x20005;
      if (iVar10 == 0xfffc) {
LAB_14807dfc:
        iVar5 = ad::fw::TaskBase::isFps30(*(TaskBase **)(iVar9 + 4));
        if (iVar5 == 0) {
          fVar17 = fVar19;
        }
        else {
          fVar17 = fVar20;
        }
        iVar5 = Frm::update(fVar17);
        if (iVar5 != 0) {
          return 0;
        }
        piVar12 = (int *)param_1[0x303];
        piVar7 = param_1 + 0x302;
        if (piVar12 != piVar7) {
          *(int **)(*piVar7 + 4) = piVar12;
          *piVar12 = *piVar7;
          if (piVar7 != (int *)0x0) {
            *piVar7 = (int)piVar7;
            param_1[0x303] = (int)piVar7;
          }
        }
        msys::MChrBaseCore::setParent((MChrBaseCore *)this_00,(MChrBase *)0x0);
        FUN_14808d08(*param_1,0x110044,0,0,0);
        if ((Unit *)param_1[0x356] != (Unit *)0x0) {
          ad::dfx::Unit::forceDeletable((Unit *)param_1[0x356]);
        }
        msys::MDfxChr::playDfx(this_00,0x1f);
        MoveVBase::stop((MoveVBase *)(param_1 + 0x334));
        param_1[0x33b] = param_1[0x295];
        param_1[0x33c] = param_1[0x296];
        param_1[0x33d] = param_1[0x297];
        param_1[0x335] = param_1[0x295];
        param_1[0x336] = param_1[0x296];
        param_1[0x337] = param_1[0x297];
        CellAnime::term((CellAnime *)(param_1 + 0x2b4));
        msys::MLyt::detachMChr((MLyt *)(*param_1 + 0xe8),(MChrBase *)this_03);
        msys::MLyt::attachMChr
                  ((MLyt *)(*param_1 + 0xe8),(MChrBase *)this_00,"INS_OBJ_CHARA",(char *)0x0,
                   (char *)0x0,(char *)0x0);
        param_1[0x3c0] = param_1[0x3c0] + 1;
LAB_14807f00:
        uVar15 = param_1[0x356];
        if (uVar15 != 0) {
          bVar16 = *(int *)(uVar15 + 4) == uVar15 + 4;
          if (bVar16) {
            uVar15 = (uint)*(byte *)(uVar15 + 0x172);
          }
          if (!bVar16 || uVar15 != 0) {
            return 0;
          }
        }
        load_menu::LoadMenuPageBase::Core::Dfx::vfunc_0x38(this_00);
        msys::MLyt::detachMChr((MLyt *)(*param_1 + 0xe8),(MChrBase *)this_00);
        Frm::play(local_108,DAT_148180ac);
        param_1[0x3c0] = param_1[0x3c0] + 1;
LAB_14807f6c:
        iVar5 = ad::fw::TaskBase::isFps30(*(TaskBase **)(iVar9 + 4));
        if (iVar5 == 0) {
          fVar17 = fVar19;
        }
        else {
          fVar17 = fVar20;
        }
        iVar5 = Frm::update(fVar17);
        if (iVar5 != 0) {
          return 0;
        }
        cVar4 = *(char *)((int)param_1 + 0xf1a);
        *(char *)((int)param_1 + 0xf1a) = cVar4 + -1;
        if (cVar4 != '\0') {
          param_1[0x3c0] = 0x20003;
          return 0;
        }
        Frm::play(local_108,DAT_148180b8);
        param_1[0x3c0] = param_1[0x3c0] + 1;
      }
      else {
        if (iVar10 < 0xfffc) {
          if (iVar10 == 0xfff8) {
LAB_14807920:
            if ((char)param_1[0x152] != '\0') {
              return 0;
            }
            FUN_14808d08(*param_1,0x110043,0,0,0);
            CellAnime::play(this_02,(char)param_1[0x1cd] + '\x01',1,1.0);
            FUN_14806608(this_00,*param_1,*param_1 + 0xe8,"INS_OBJ_CHARA");
            msys::MDfxChr::setCA(this_00,this_02);
            uVar15 = *(uint *)(&DAT_1480e4cc + (uint)*(byte *)((int)param_1 + 0xf1a) * 4);
            if ((Unit *)param_1[0x356] != (Unit *)0x0) {
              ad::dfx::Unit::forceDeletable((Unit *)param_1[0x356]);
            }
            msys::MDfxChr::playDfx(this_00,uVar15);
            MoveVBase::stop((MoveVBase *)(param_1 + 0x334));
            param_1[0x33b] = param_1[0x187];
            param_1[0x33c] = param_1[0x188];
            param_1[0x33d] = param_1[0x189];
            param_1[0x335] = param_1[0x187];
            param_1[0x336] = param_1[0x188];
            param_1[0x337] = param_1[0x189];
            param_1[0x3c0] = param_1[0x3c0] + 1;
LAB_148079d8:
            iVar5 = MoveVBase::isBusy(this_01);
            if (iVar5 != 0) {
              return 0;
            }
            uVar15 = param_1[0x356];
            if (uVar15 != 0) {
              bVar16 = *(int *)(uVar15 + 4) != uVar15 + 4;
              if (!bVar16) {
                uVar15 = (uint)*(byte *)(uVar15 + 0x172);
              }
              if (bVar16 || uVar15 != 0) {
                return 0;
              }
            }
            load_menu::LoadMenuPageBase::Core::Dfx::vfunc_0x38(this_00);
            msys::MLyt::detachMChr((MLyt *)(*param_1 + 0xe8),(MChrBase *)this_00);
            param_1[0x3c0] = param_1[0x3c0] + 1;
LAB_14807a34:
            uVar1 = *(ushort *)((int)param_1 + (uint)*(byte *)((int)param_1 + 0xf1a) * 2 + 0xf14);
            local_118 = 0;
            local_298 = 0;
            local_114 = 0;
            local_218 = 0;
            local_110 = 0;
            local_198 = 0;
            local_10c = 0;
            if ((uVar1 & 0xf000) == 0) {
              KJDB::Item::getData((Item *)(KJDB::_inst + 0x8c),aKStack_e8,(uint)uVar1);
              psVar8 = (short *)FUN_14808da8(iVar9,1,aKStack_e8);
              uVar15 = 0;
              do {
                sVar2 = psVar8[uVar15];
                if (sVar2 == 0) break;
                if (sVar2 == 0xe) {
                  uVar15 = uVar15 + ((ushort)(psVar8 + uVar15)[3] >> 1) + 3;
                }
                uVar15 = uVar15 + 1;
              } while (uVar15 < 0x40);
              sVar2 = *psVar8;
              bVar16 = sVar2 == 0xe;
              if (bVar16) {
                sVar2 = psVar8[1];
              }
              if (bVar16 && sVar2 == 9) {
                uVar15 = uVar15 - 5;
                psVar8 = psVar8 + 5;
              }
              Mem::Copy(aVStackY_3a0 + 0x88,psVar8,uVar15 << 1);
              local_118 = uVar15;
              msys::MCellAnime::init(this_03,(Resource *)(iVar9 + 0xfca78));
              CellAnime::play((CellAnime *)(param_1 + 0x2b4),local_a0,0,1.0);
            }
            else {
              psVar8 = (short *)ad::db::GetItemMsg((uint)uVar1,0);
              uVar15 = 0;
              do {
                sVar2 = psVar8[uVar15];
                if (sVar2 == 0) break;
                if (sVar2 == 0xe) {
                  uVar15 = uVar15 + ((ushort)(psVar8 + uVar15)[3] >> 1) + 3;
                }
                uVar15 = uVar15 + 1;
              } while (uVar15 < 0x40);
              sVar2 = *psVar8;
              bVar16 = sVar2 == 0xe;
              if (bVar16) {
                sVar2 = psVar8[1];
              }
              if (bVar16 && sVar2 == 9) {
                uVar15 = uVar15 - 5;
                psVar8 = psVar8 + 5;
              }
              Mem::Copy(aVStackY_3a0 + 0x88,psVar8,uVar15 << 1);
              local_118 = uVar15;
              msys::MCellAnime::init(this_03,(Resource *)(iVar9 + 0xfd00c));
              iVar5 = ad::db::GetUseItem(uVar1);
              CellAnime::play((CellAnime *)(param_1 + 0x2b4),*(char *)(iVar5 + 0x60) + '\x01',0,1.0)
              ;
            }
            local_78 = DAT_14818094;
            local_74 = DAT_14818098 + DAT_14818000;
            local_70 = 0;
            MoveVBase::stop((MoveVBase *)(param_1 + 0x294));
            param_1[0x29b] = local_78;
            param_1[0x29c] = (int)local_74;
            param_1[0x29d] = local_70;
            param_1[0x295] = local_78;
            param_1[0x296] = (int)local_74;
            param_1[0x297] = local_70;
            local_78 = DAT_1481809c;
            local_74 = DAT_148180a0 + DAT_14818000;
            local_70 = 0;
            MoveVBase::moveSinAbs((VEC3 *)(param_1 + 0x294),DAT_148180a4);
            local_78 = DAT_148180b0;
            local_70 = 0x3f800000;
            local_74 = (float)local_78;
            MoveVBase::stop((MoveVBase *)(param_1 + 0x266));
            param_1[0x26d] = local_78;
            param_1[0x26e] = (int)local_74;
            param_1[0x26f] = local_70;
            param_1[0x267] = local_78;
            param_1[0x268] = (int)local_74;
            param_1[0x269] = local_70;
            if (((nn::math::VEC3::One()::one & 1) == 0) &&
               (iVar5 = __cxa_guard_acquire(&nn::math::VEC3::One()::one), iVar5 != 0)) {
              nn::math::VEC3::One()::one = 0x3f800000;
              DAT_00434c40 = 0x3f800000;
              DAT_00434c44 = 0x3f800000;
              __cxa_guard_release(&nn::math::VEC3::One()::one);
            }
            MoveVBase::moveAbs((MoveVBase *)(param_1 + 0x266),(VEC3 *)&nn::math::VEC3::One()::one,
                               DAT_148180b4);
            msys::MLyt::attachMChr
                      ((MLyt *)(*param_1 + 0xe8),(MChrBase *)this_03,"INS_OBJ_CHARA",(char *)0x0,
                       (char *)0x0,(char *)0x0);
            FUN_14806608(this_00,*param_1,*param_1 + 0xe8,0);
            msys::MDfxChr::setCA(this_00,(CellAnime *)(param_1 + 0x2b4));
            if ((Unit *)param_1[0x356] != (Unit *)0x0) {
              ad::dfx::Unit::forceDeletable((Unit *)param_1[0x356]);
            }
            msys::MDfxChr::playDfx(this_00,0x1e);
            *(undefined2 *)(param_1[0x356] + 0xf2) = 0;
            piVar7 = (int *)param_1[0x303];
            *(int **)(param_1[0x302] + 4) = piVar7;
            *piVar7 = param_1[0x302];
            piVar7 = param_1 + 0x302;
            if (piVar7 != (int *)0x0) {
              *piVar7 = (int)(param_1 + 0x2b2);
              param_1[0x303] = param_1[0x2b3];
              *(int **)param_1[0x2b3] = piVar7;
              param_1[0x2b3] = (int)piVar7;
            }
            msys::MChrBaseCore::setParent((MChrBaseCore *)this_00,(MChrBase *)this_03);
            FUN_14806720(*param_1 + 0x8bc8,"amiibo_seq_06",aVStackY_3a0 + 0x88);
            param_1[0x3c0] = param_1[0x3c0] + 1;
          }
          else {
            if (iVar10 < 0xfff8) {
              if (iVar10 == 1) goto LAB_14807864;
              if (iVar10 == 2) {
                return 1;
              }
              if (iVar10 != 0xfff7) {
                return 1;
              }
              switch(*(undefined1 *)((int)param_1 + 0xf1b)) {
              case 0:
              case 1:
              case 4:
              case 5:
                FUN_1480b7f4(param_1 + 0x45,param_1 + 0x12);
                CellAnime::play((CellAnime *)(param_1 + 0x98),'\x02',0,1.0);
                break;
              case 3:
              case 6:
              case 7:
                MoveVBase::jumpFT((MoveVBase *)(param_1 + 0xe4),0.0,DAT_14818070,DAT_14818074,
                                  aVStack_2fa + -0x12);
                *(undefined1 *)(param_1 + 0x152) = 2;
              }
              param_1[0x3c0] = param_1[0x3c0] + 1;
              goto LAB_14807920;
            }
            if (iVar10 == 0xfff9) goto LAB_148079d8;
            if (iVar10 == 0xfffa) goto LAB_14807a34;
            if (iVar10 != 0xfffb) {
              return 1;
            }
          }
          iVar5 = MoveVBase::isBusy((MoveVBase *)(param_1 + 0x294));
          if (iVar5 != 0) {
            return 0;
          }
          Frm::play(local_108,DAT_148180a8);
          param_1[0x3c0] = param_1[0x3c0] + 1;
          goto LAB_14807dfc;
        }
        if (iVar5 == 4) {
          return 1;
        }
        if (4 < iVar5) {
          if (iVar5 != 0xfffb) {
            return 1;
          }
          CellAnime::term((CellAnime *)(param_1 + 0x98));
          CellAnime::term((CellAnime *)(param_1 + 0x104));
          load_menu::LoadMenuPageBase::Core::Dfx::vfunc_0x38(param_1 + 0x360);
          msys::MLyt::detachMChr((MLyt *)(*param_1 + 0xe8),(MChrBase *)(param_1 + 0x45));
          msys::MLyt::detachMChr((MLyt *)(*param_1 + 0xe8),(MChrBase *)pMVar18);
          msys::MLyt::detachMChr((MLyt *)(*param_1 + 0xe8),(MChrBase *)(param_1 + 0x360));
          goto LAB_14808004;
        }
        if (iVar5 == 1) goto LAB_14807f00;
        if (iVar5 == 2) goto LAB_14807f6c;
        if (iVar5 != 3) {
          return 1;
        }
      }
      iVar5 = ad::fw::TaskBase::isFps30(*(TaskBase **)(iVar9 + 4));
      if (iVar5 != 0) {
        fVar19 = fVar20;
      }
      iVar5 = Frm::update(fVar19);
      goto joined_r0x14807874;
    }
    if (iVar5 == 0x10002) {
LAB_14807278:
      iVar5 = ad::fw::TaskBase::isFps30(*(TaskBase **)(iVar9 + 4));
      if (iVar5 == 0) {
        fVar17 = fVar19;
      }
      else {
        fVar17 = fVar20;
      }
      iVar5 = Frm::update(fVar17);
      if (iVar5 != 0) {
        return 0;
      }
      if (*(byte *)((int)param_1 + 0xf1b) < 2) {
        CellAnime::play((CellAnime *)(param_1 + 0x98),'\f',0,1.0);
      }
      else {
        CellAnime::play((CellAnime *)(param_1 + 0x98),'\x06',0,1.0);
      }
      local_90 = DAT_14818040 + DAT_14818000;
      local_94 = DAT_1481803c -
                 *(float *)(&DAT_14818008 + (uint)*(byte *)((int)param_1 + 0xf1b) * 4);
      local_8c = 0;
      MoveVBase::moveAbs((MoveVBase *)(param_1 + 0x78),(VEC3 *)&local_94,DAT_14818050);
      param_1[0x3c0] = param_1[0x3c0] + 1;
switchD_14806bb0_caseD_10003:
      iVar5 = MoveVBase::isBusy((MoveVBase *)(param_1 + 0x78));
      if (iVar5 != 0) {
        return 0;
      }
      *(undefined1 *)((int)param_1 + 0x255) = 0;
      Frm::play(local_108,DAT_1481808c);
      param_1[0x3c0] = param_1[0x3c0] + 1;
      goto switchD_14806bb0_caseD_10004;
    }
    if (0x10001 < iVar5) {
      switch(iVar5) {
      default:
        goto switchD_14806bb0_caseD_10002;
      case 0x10003:
        goto switchD_14806bb0_caseD_10003;
      case 0x10004:
switchD_14806bb0_caseD_10004:
        iVar5 = ad::fw::TaskBase::isFps30(*(TaskBase **)(iVar9 + 4));
        if (iVar5 == 0) {
          fVar17 = fVar19;
        }
        else {
          fVar17 = fVar20;
        }
        iVar5 = Frm::update(fVar17);
        if (iVar5 != 0) {
          return 0;
        }
        FUN_14808d08(*param_1,0x110041,0,0,0);
        cVar4 = *(char *)((int)param_1 + 0xf1a) + -1;
        *(char *)((int)param_1 + 0xf1a) = cVar4;
        CellAnime::play(this_02,cVar4 * '\x02',0,1.0);
        local_88 = DAT_14818078;
        local_84 = DAT_1481807c + DAT_14818000;
        local_80 = 0;
        MoveVBase::stop(this_01);
        param_1[0x18d] = local_88;
        param_1[0x18e] = (int)local_84;
        param_1[399] = local_80;
        param_1[0x187] = local_88;
        param_1[0x188] = (int)local_84;
        param_1[0x189] = local_80;
        local_88 = DAT_14818080;
        local_84 = DAT_14818084 + DAT_14818000;
        local_80 = 0;
        MoveVBase::moveFrmAbs((VEC3 *)this_01,DAT_14818090);
        piVar7 = (int *)FUN_14809048();
        MoveVBase::stop((MoveVBase *)(param_1 + 0x1f2));
        iVar5 = *piVar7;
        iVar10 = piVar7[1];
        iVar13 = piVar7[2];
        param_1[0x1f9] = iVar5;
        param_1[0x1fa] = iVar10;
        param_1[0x1fb] = iVar13;
        param_1[499] = iVar5;
        param_1[500] = iVar10;
        param_1[0x1f5] = iVar13;
        local_88 = 0;
        local_84 = 1.0;
        local_80 = 0;
        MoveVBase::jumpFT((MoveVBase *)(param_1 + 0x1f2),0.0,DAT_14818090,DAT_14818088,
                          (VEC3 *)&local_88);
        msys::MLyt::attachMChr
                  ((MLyt *)(*param_1 + 0xe8),(MChrBase *)pMVar18,"INS_OBJ_CHARA",(char *)0x0,
                   (char *)0x0,(char *)0x0);
        Frm::play(local_108,DAT_14818060);
        *(undefined1 *)(param_1 + 0x3c7) = 1;
        param_1[0x3c0] = param_1[0x3c0] + 1;
      case 0x10005:
        if (((char)param_1[0x3c7] != '\0') && (iVar5 = MoveVBase::isBusy(this_01), iVar5 == 0)) {
          FUN_14808d08(*param_1,0x110042,0,0,0);
          *(undefined1 *)(param_1 + 0x3c7) = 0;
        }
        iVar5 = ad::fw::TaskBase::isFps30(*(TaskBase **)(iVar9 + 4));
        if (iVar5 == 0) {
          fVar17 = fVar19;
        }
        else {
          fVar17 = fVar20;
        }
        iVar5 = Frm::update(fVar17);
        if (iVar5 != 0) {
          return 0;
        }
        if (*(byte *)((int)param_1 + 0xf1b) < 2) {
          CellAnime::play((CellAnime *)(param_1 + 0x98),'\x04',0,1.0);
        }
        else {
          CellAnime::play((CellAnime *)(param_1 + 0x98),'\x02',0,1.0);
        }
        local_f8 = DAT_14818044 -
                   *(float *)(&DAT_14818008 + (uint)*(byte *)((int)param_1 + 0xf1b) * 4);
        local_f4 = DAT_14818048 + DAT_14818000;
        local_f0 = 0;
        MoveVBase::moveAbs((MoveVBase *)(param_1 + 0x78),(VEC3 *)&local_f8,DAT_14818050);
        *(undefined1 *)((int)param_1 + 0x255) = 1;
        param_1[0x3c0] = param_1[0x3c0] + 1;
      case 0x10006:
        if (((char)param_1[0x3c7] != '\0') && (iVar5 = MoveVBase::isBusy(this_01), iVar5 == 0)) {
          FUN_14808d08(*param_1,0x110042,0,0,0);
          *(undefined1 *)(param_1 + 0x3c7) = 0;
        }
        iVar5 = MoveVBase::isBusy((MoveVBase *)(param_1 + 0x78));
        if (iVar5 != 0) {
          return 0;
        }
        if (*(byte *)((int)param_1 + 0xf1b) < 2) {
          CellAnime::play((CellAnime *)(param_1 + 0x98),'\x14',0,1.0);
        }
        else {
          CellAnime::play((CellAnime *)(param_1 + 0x98),'\n',0,1.0);
        }
        Frm::play(local_108,DAT_14818064);
        param_1[0x3c0] = param_1[0x3c0] + 1;
      case 0x10007:
        if (((char)param_1[0x3c7] != '\0') && (iVar5 = MoveVBase::isBusy(this_01), iVar5 == 0)) {
          FUN_14808d08(*param_1,0x110042,0,0,0);
          *(undefined1 *)(param_1 + 0x3c7) = 0;
        }
        iVar5 = ad::fw::TaskBase::isFps30(*(TaskBase **)(iVar9 + 4));
        if (iVar5 == 0) {
          fVar17 = fVar19;
        }
        else {
          fVar17 = fVar20;
        }
        iVar5 = Frm::update(fVar17);
        if (iVar5 != 0) {
          return 0;
        }
        if (*(byte *)((int)param_1 + 0xf1b) < 2) {
          CellAnime::play((CellAnime *)(param_1 + 0x98),'\x16',0,1.0);
        }
        else {
          CellAnime::play((CellAnime *)(param_1 + 0x98),'\v',0,1.0);
        }
        Frm::play(local_108,DAT_14818068);
        param_1[0x3c0] = param_1[0x3c0] + 1;
      case 0x10008:
        iVar5 = ad::fw::TaskBase::isFps30(*(TaskBase **)(iVar9 + 4));
        if (iVar5 == 0) {
          fVar17 = fVar19;
        }
        else {
          fVar17 = fVar20;
        }
        iVar5 = Frm::update(fVar17);
        if (iVar5 != 0) {
          return 0;
        }
        if (*(byte *)((int)param_1 + 0xf1b) < 2) {
          CellAnime::play((CellAnime *)(param_1 + 0x98),'\x18',0,1.0);
        }
        else {
          CellAnime::play((CellAnime *)(param_1 + 0x98),'\f',0,1.0);
        }
        Frm::play(local_108,DAT_1481806c);
        param_1[0x3c0] = param_1[0x3c0] + 1;
      }
      goto LAB_14807814;
    }
    if (iVar5 != 3) {
      if (3 < iVar5) {
        if (iVar5 == 4) {
          return 1;
        }
        if (iVar5 == 0x10000) {
          if (*(byte *)((int)param_1 + 0xf1b) < 2) {
            CellAnime::play((CellAnime *)(param_1 + 0x98),'\x1a',0,1.0);
          }
          else {
            CellAnime::play((CellAnime *)(param_1 + 0x98),'\r',0,1.0);
          }
          Frm::play(local_108,DAT_14818058);
          param_1[0x3c0] = param_1[0x3c0] + 1;
        }
        else if (iVar5 != 0x10001) {
          return 1;
        }
        iVar5 = ad::fw::TaskBase::isFps30(*(TaskBase **)(iVar9 + 4));
        if (iVar5 == 0) {
          fVar17 = fVar19;
        }
        else {
          fVar17 = fVar20;
        }
        iVar5 = Frm::update(fVar17);
        if (iVar5 != 0) {
          return 0;
        }
        if (*(byte *)((int)param_1 + 0xf1b) < 2) {
          CellAnime::play((CellAnime *)(param_1 + 0x98),'\x1c',0,1.0);
        }
        else {
          CellAnime::play((CellAnime *)(param_1 + 0x98),'\x0e',0,1.0);
        }
        Frm::play(local_108,DAT_1481805c);
        param_1[0x3c0] = param_1[0x3c0] + 1;
        goto LAB_14807278;
      }
      if (iVar5 == 0) {
        do {
          iVar5 = ad::fw::TaskBase::isReadable(*(TaskBase **)(iVar9 + 4));
          if (iVar5 == 0) {
            return 0;
          }
          iVar5 = *(int *)(iVar9 + 0x278);
          ad::TransMultiSymbol::init(aTStack_2e4,*(char **)(param_1[0x300] + param_1[0x3bf] * 4));
          for (pFVar14 = (FileContext *)(iVar5 + 0x150); pFVar14 != (FileContext *)(iVar5 + 0x3f0);
              pFVar14 = pFVar14 + 0xa8) {
            if ((pFVar14[4] == (FileContext)0x13) &&
               (BinGlu4Acs::getEntryAcs((char *)(aVStackY_3a0 + 0x90)), pMVar18 != (MemAlcBase *)0x0
               )) {
              if (in_stack_fffffcf4 == 2) {
                bVar3 = (byte)pMVar18[7] >> 7;
              }
              else {
                bVar3 = (byte)pMVar18[7] >> 6;
              }
              if ((~bVar3 & 1) != 0) {
                if (&uStack00000000 != (undefined1 *)0x2e8) {
                  local_2e8 = pFVar14;
                }
                break;
              }
            }
          }
          pFVar14 = local_2e8;
          iVar5 = param_1[0x3bf];
          this = *(TaskBase **)(iVar9 + 4);
          pMVar18 = *(MemAlcBase **)(*(int *)(*param_1 + 4) + 0x18);
          pcVar11 = *(char **)(param_1[0x300] + iVar5 * 4);
          local_38 = *(undefined4 *)(local_2e8 + 0x24);
          ad::TransMultiSymbol::init(aTStack_6c,pcVar11);
          BinGlu4Acs::getEntryAcs((char *)local_40);
          pcVar6 = (char *)((*local_40[0] & 0x3fffffff) + *(int *)(pFVar14 + 0x24));
          in_stack_fffffcf4 = 0x7f;
          in_stack_fffffcf8 = (uint *)0x0;
          in_stack_fffffcfc = 0;
          ad::fw::TaskBase::readCA
                    (this,(Resource *)(param_1 + iVar5 * 0x11 + 1),pFVar14,pcVar11,pcVar6,pcVar6 + 4
                     ,pcVar6 + 8,pcVar6 + 0xc,pMVar18,0x7f,(VramAlcBase *)0x0,0,(ResCacheArg *)0x0);
          iVar5 = param_1[0x3bf];
          param_1[0x3bf] = iVar5 + -1;
        } while (-1 < iVar5 + -1);
        param_1[0x3c0] = param_1[0x3c0] + 1;
LAB_14806dfc:
        if ((char)param_1[2] == '\0') {
          return 0;
        }
        FUN_14806608(param_1 + 0x360,*param_1,*param_1 + 0xe8,"INS_EFFECT_STAR_LOAD");
        if ((Unit *)param_1[0x3b5] != (Unit *)0x0) {
          ad::dfx::Unit::forceDeletable((Unit *)param_1[0x3b5]);
        }
        msys::MDfxChr::playDfx((MDfxChr *)(param_1 + 0x360),0x22);
        *(undefined2 *)(param_1[0x3b5] + 0xf2) = 0;
        iVar10 = *(int *)(iVar9 + 0x278);
        ad::TransMultiSymbol::init((TransMultiSymbol *)&local_2e8,(char *)(param_1 + 4));
        for (iVar5 = iVar10 + 0x150; iVar5 != iVar10 + 0x3f0; iVar5 = iVar5 + 0xa8) {
          if ((*(char *)(iVar5 + 4) == '\x13') &&
             (BinGlu4Acs::getEntryAcs((char *)(aVStack_2fa + -0xe)),
             in_stack_fffffcf8 != (uint *)0x0)) {
            if (in_stack_fffffcfc == 2) {
              bVar3 = *(byte *)((int)in_stack_fffffcf8 + 7) >> 7;
            }
            else {
              bVar3 = *(byte *)((int)in_stack_fffffcf8 + 7) >> 6;
            }
            if ((~bVar3 & 1) != 0) {
              iVar5 = *(int *)(iVar5 + 0x24) + (*in_stack_fffffcf8 & 0x3fffffff);
              goto LAB_14806f14;
            }
          }
        }
        iVar5 = 0;
LAB_14806f14:
        FUN_1480b724(param_1 + 0x45,iVar5,param_1 + 1,iVar9 + 0xfcabc);
        if (*(byte *)((int)param_1 + 0xf1b) < 2) {
          CellAnime::play((CellAnime *)(param_1 + 0x98),'(',0,1.0);
        }
        else if (*(byte *)((int)param_1 + 0xf1b) == 4) {
          CellAnime::play((CellAnime *)(param_1 + 0x98),'\x04',1,1.0);
          *(ushort *)((int)param_1 + 0x27e) = *(ushort *)((int)param_1 + 0x27e) | 2;
        }
        else {
          CellAnime::play((CellAnime *)(param_1 + 0x98),'\f',0,1.0);
        }
        fVar19 = DAT_14818030 + DAT_14818000;
        iVar9 = 0;
        iVar5 = DAT_1481802c;
        MoveVBase::stop((MoveVBase *)(param_1 + 0x78));
        param_1[0x7f] = iVar5;
        param_1[0x80] = (int)fVar19;
        param_1[0x81] = iVar9;
        param_1[0x79] = iVar5;
        param_1[0x7a] = (int)fVar19;
        param_1[0x7b] = iVar9;
        MoveVBase::moveFrmAbs((VEC3 *)(param_1 + 0x78),DAT_14818054);
        piVar7 = (int *)FUN_14809048();
        MoveVBase::stop((MoveVBase *)(param_1 + 0xe4));
        iVar5 = *piVar7;
        iVar9 = piVar7[1];
        iVar10 = piVar7[2];
        param_1[0xeb] = iVar5;
        param_1[0xec] = iVar9;
        param_1[0xed] = iVar10;
        param_1[0xe5] = iVar5;
        param_1[0xe6] = iVar9;
        param_1[0xe7] = iVar10;
        MoveVBase::jumpFT((MoveVBase *)(param_1 + 0xe4),0.0,DAT_14818054,DAT_1481804c,
                          aVStackY_3a0 + 0x88);
        msys::MLyt::attachMChr
                  ((MLyt *)(*param_1 + 0xe8),(MChrBase *)(param_1 + 0x45),"INS_OBJ_CHARA",
                   (char *)0x0,(char *)0x0,(char *)0x0);
        FUN_14808d08(*param_1,0x110040,0,0,0);
        param_1[0x3c0] = param_1[0x3c0] + 1;
      }
      else {
        if (iVar5 == 1) goto LAB_14806dfc;
        if (iVar5 != 2) {
          return 1;
        }
      }
      iVar5 = MoveVBase::isBusy((MoveVBase *)(param_1 + 0x78));
      if (iVar5 != 0) {
        return 0;
      }
      if (*(byte *)((int)param_1 + 0xf1b) < 2) {
        CellAnime::play((CellAnime *)(param_1 + 0x98),'H',1,1.0);
      }
      else if (*(byte *)((int)param_1 + 0xf1b) == 4) {
        *(ushort *)((int)param_1 + 0x27e) = *(ushort *)((int)param_1 + 0x27e) & 0xfffd;
      }
      param_1[0x3c0] = param_1[0x3c0] + 1;
    }
    if (*(byte *)((int)param_1 + 0xf1b) < 2) {
      if ((*(byte *)((int)param_1 + 0x27e) & 1) != 0) {
        return 0;
      }
      CellAnime::play((CellAnime *)(param_1 + 0x98),'\x18',0,1.0);
    }
    else if (*(byte *)((int)param_1 + 0xf1b) == 4) {
      if ((*(byte *)((int)param_1 + 0x27e) & 1) != 0) {
        return 0;
      }
      FUN_1480b7f4(param_1 + 0x45,param_1 + 0x23);
      CellAnime::play((CellAnime *)(param_1 + 0x98),'\f',0,1.0);
    }
  }
LAB_14808004:
  param_1[0x3c0] = param_1[0x3c0] + 1;
switchD_14806bb0_caseD_10002:
  return 1;
}


// FUNC 0x148080bc FUN_148080bc (LoadMenu)
//   size 0x9c | file LoadMenu+0x80bc | callers(4) 0x1480c5c4 0x14809874 0x14809c1c 0x14809840

void FUN_148080bc(int param_1)

{
  int iVar1;
  
  iVar1 = ad::nfp::GetState();
  if ((iVar1 != 4 && iVar1 != 5) && iVar1 != 6) {
    ad::nfp::StopDetection();
    iVar1 = *(int *)(param_1 + 0x7afc);
    if ((iVar1 != 0) && ((*(int *)(iVar1 + 4) != iVar1 + 4 || (*(char *)(iVar1 + 0x172) != '\0'))))
    {
      msys::MDfxChr::term((MDfxChr *)(param_1 + 0x79a8));
    }
    msys::MLyt::playAnimeFromNo
              ((MLyt *)(*(int *)(param_1 + 0x79a4) + 0xe8),3,0,(char *)0x0,(char *)0x0);
    *(undefined1 *)(param_1 + 0x7b24) = 4;
    msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x490),2,0,(char *)0x0,(char *)0x0);
  }
  return;
}


// FUNC 0x14808158 load_menu::LoadMenuTopPage::vfunc_0x0 (LoadMenu)
//   size 0x4 | file LoadMenu+0x8158 | callers(0) | datarefs 1

undefined4 * load_menu::LoadMenuTopPage::vfunc_0x0(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  undefined4 *puVar6;
  
  *param_1 = &LoadMenuPageBase::vtable;
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


// FUNC 0x1480815c load_menu::LoadMenuPageBase::vfunc_0x0 (LoadMenu)
//   size 0xc0 | file LoadMenu+0x815c | callers(5) 0x1480d720 0x14806148 0x14809644 0x1480caec 0x1480cafc | datarefs 1

undefined4 * load_menu::LoadMenuPageBase::vfunc_0x0(undefined4 *param_1)

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


// FUNC 0x14808224 load_menu::LoadMenuPageBase::Core::vfunc_0x0 (LoadMenu)
//   size 0x108 | file LoadMenu+0x8224 | callers(5) 0x14805e70 0x148094d8 0x1480c910 0x14805fc0 0x1480c9e4 | datarefs 1

int load_menu::LoadMenuPageBase::Core::vfunc_0x0(undefined4 *param_1)

{
  int iVar1;
  MLyt *pMVar2;
  
  *param_1 = &vtable;
  msys::MLyt::term((MLyt *)(param_1 + 0x3a));
  msys::MLyt::term((MLyt *)(param_1 + 0x124));
  ad::fw::Resource::term((Resource *)(param_1 + 0x29));
  ad::lyt::LytResourceMan::term((LytResourceMan *)(param_1 + 0xc));
  param_1[0x1dde] = 0;
  param_1[0x20e] = &msys::MMsgWnd::vtable;
  Message::term((Message *)(param_1 + 0x261));
  iVar1 = Message::~Message((Message *)(param_1 + 0x261));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  pMVar2 = (MLyt *)(iVar1 + -0x3a8);
  *(undefined ***)pMVar2 = &msys::MLyt::vtable;
  msys::MLyt::term(pMVar2);
  __aeabi_vec_dtor(iVar1 + -0xf8,&LAB_14801430,0x10,0xc);
  __aeabi_vec_dtor(iVar1 + -0x254,&LAB_148013f0,0x1c,0xc);
  iVar1 = msys::MChrBase::vfunc_0x0(pMVar2);
  pMVar2 = (MLyt *)(iVar1 + -0x3a8);
  *(undefined ***)pMVar2 = &msys::MLyt::vtable;
  msys::MLyt::term(pMVar2);
  __aeabi_vec_dtor(iVar1 + -0xf8,&LAB_14801430,0x10,0xc);
  __aeabi_vec_dtor(iVar1 + -0x254,&LAB_148013f0,0x1c,0xc);
  iVar1 = msys::MChrBase::vfunc_0x0(pMVar2);
  iVar1 = ad::fw::Resource::~Resource((Resource *)(iVar1 + -0x44));
  ad::lyt::LytResourceMan::term((LytResourceMan *)(iVar1 + -0x74));
  iVar1 = ad::font::ResFont::~ResFont((ResFont *)(iVar1 + -0x70));
  return iVar1 + -0x34;
}


// FUNC 0x14808344 FUN_14808344 (LoadMenu)
//   size 0x364 | file LoadMenu+0x8344 | callers(3) 0x14805004 0x148055fc 0x14804d04

void FUN_14808344(MMsg *param_1,int param_2,int param_3)

{
  SaveLoadSys *pSVar1;
  SaveLoadSys *pSVar2;
  wchar_t *pwVar3;
  undefined4 *puVar4;
  int iVar5;
  uint *puVar7;
  uint *puVar6;
  uint uVar8;
  byte bVar9;
  MMsg *pMVar10;
  uint in_fpscr;
  float fVar11;
  MMsg *local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined2 local_38;
  undefined2 local_36;
  
  if (param_3 < 0) {
    param_3 = (int)*(char *)(param_2 + 0x77b8);
  }
  local_44 = 0;
  local_40 = 0x3f800000;
  local_3c = 0;
  local_38 = 1;
  local_36 = 0;
  ad::lyt::LytAnim::init((LytAnim *)&local_48,*(Layout **)(param_2 + 0x238),"SET_GAME","");
  fVar11 = (float)VectorUnsignedToFloat((uint)(param_3 == 7),(byte)(in_fpscr >> 0x16) & 3);
  ad::lyt::LytAnim::stopAndSetFrm((LytAnim *)&local_48,fVar11);
  ad::lyt::LytAnim::term((LytAnim *)&local_48,true);
  pSVar1 = msys::MComSys::_sys;
  local_3c = 0;
  local_48 = param_1 + 0x6c44;
  pMVar10 = param_1 + 0x6c58;
  if (param_3 != 7) {
    if (param_3 == 8) {
      iVar5 = msys::MLyt::getPane((MLyt *)(param_2 + 0xe8),"SUMMARY",(char *)0x0,(char *)0x0);
      *(byte *)(iVar5 + 0x44) = *(byte *)(iVar5 + 0x44) & 0xfe;
      iVar5 = msys::MLyt::getPane((MLyt *)(param_2 + 0xe8),"PAGE_2",(char *)0x0,(char *)0x0);
      bVar9 = *(byte *)(iVar5 + 0x44) & 0xfe;
    }
    else {
      if ((DAT_003fbea0 & 1) == 0) {
        uVar8 = GameWork::getScenarioFlag((GameWork *)&gGameWork);
        pSVar2 = msys::MComSys::_sys;
        pSVar1 = *(SaveLoadSys **)(param_2 + 8);
        if (*(SaveLoadSys **)(param_2 + 8) == (SaveLoadSys *)0x0) {
          *(SaveLoadSys **)(param_2 + 8) = msys::MComSys::_sys;
          pSVar1 = pSVar2;
        }
        save_load::Summary::build((Summary *)param_1,pSVar1,uVar8);
      }
      else {
        pSVar2 = *(SaveLoadSys **)(param_2 + 8);
        if (*(SaveLoadSys **)(param_2 + 8) == (SaveLoadSys *)0x0) {
          *(SaveLoadSys **)(param_2 + 8) = msys::MComSys::_sys;
          pSVar2 = pSVar1;
        }
        pwVar3 = (wchar_t *)FUN_14808da8(pSVar2,0,"MES_EMesOutline_story_def");
        msys::MMsg::playStr(param_1,pwVar3,(InsParam *)0x0,false);
        puVar4 = (undefined4 *)FUN_14809048();
        *(undefined4 *)pMVar10 = *puVar4;
        *(undefined4 *)(param_1 + 0x6c5c) = puVar4[1];
        *(undefined4 *)(param_1 + 0x6c60) = puVar4[2];
        param_1[0x5c08] = (MMsg)0x0;
        Frm::play((Frm *)local_48,30.0);
        param_1[0x6c54] = (MMsg)0x1;
      }
      iVar5 = msys::MLyt::getPane((MLyt *)(param_2 + 0xe8),"SUMMARY",(char *)0x0,(char *)0x0);
      *(byte *)(iVar5 + 0x44) = *(byte *)(iVar5 + 0x44) & 0xfe | 1;
      iVar5 = msys::MLyt::getPane((MLyt *)(param_2 + 0xe8),"PAGE_2",(char *)0x0,(char *)0x0);
      bVar9 = *(byte *)(iVar5 + 0x44) & 0xfe | 1;
    }
    *(byte *)(iVar5 + 0x44) = bVar9;
    return;
  }
  if (DAT_003fbaf0 == 0) {
    pSVar2 = *(SaveLoadSys **)(param_2 + 8);
    if (*(SaveLoadSys **)(param_2 + 8) == (SaveLoadSys *)0x0) {
      *(SaveLoadSys **)(param_2 + 8) = msys::MComSys::_sys;
      pSVar2 = pSVar1;
    }
    pwVar3 = (wchar_t *)FUN_14808da8(pSVar2,0,"MES_EMesOutline_story_kj_def");
    msys::MMsg::playStr(param_1,pwVar3,(InsParam *)0x0,false);
    puVar4 = (undefined4 *)FUN_14809048();
    *(undefined4 *)pMVar10 = *puVar4;
    *(undefined4 *)(param_1 + 0x6c5c) = puVar4[1];
    *(undefined4 *)(param_1 + 0x6c60) = puVar4[2];
    param_1[0x5c08] = (MMsg)0x0;
    Frm::play((Frm *)local_48,30.0);
    param_1[0x6c54] = (MMsg)0x1;
  }
  else {
    puVar6 = &DAT_1480e43c;
    do {
      puVar7 = puVar6;
      puVar6 = puVar7 + -2;
      if (puVar6 < &UNK_1480e3c5) break;
    } while (((&DAT_003fbb78)[*puVar6 >> 5] & 1 << (*puVar6 & 0x1f)) == 0);
    pSVar2 = *(SaveLoadSys **)(param_2 + 8);
    if (*(SaveLoadSys **)(param_2 + 8) == (SaveLoadSys *)0x0) {
      *(SaveLoadSys **)(param_2 + 8) = msys::MComSys::_sys;
      pSVar2 = pSVar1;
    }
    pwVar3 = (wchar_t *)FUN_14808da8(pSVar2,0,puVar7[-1]);
    msys::MMsg::playStr(param_1,pwVar3,(InsParam *)0x0,false);
    puVar4 = (undefined4 *)FUN_14809048();
    *(undefined4 *)pMVar10 = *puVar4;
    *(undefined4 *)(param_1 + 0x6c5c) = puVar4[1];
    *(undefined4 *)(param_1 + 0x6c60) = puVar4[2];
    param_1[0x5c08] = (MMsg)0x0;
    Frm::play((Frm *)local_48,30.0);
    param_1[0x6c54] = (MMsg)0x1;
  }
  iVar5 = msys::MLyt::getPane((MLyt *)(param_2 + 0xe8),"SUMMARY",(char *)0x0,(char *)0x0);
  *(byte *)(iVar5 + 0x44) = *(byte *)(iVar5 + 0x44) & 0xfe | 1;
  iVar5 = msys::MLyt::getPane((MLyt *)(param_2 + 0xe8),"PAGE_2",(char *)0x0,(char *)0x0);
  *(byte *)(iVar5 + 0x44) = *(byte *)(iVar5 + 0x44) & 0xfe | 1;
  return;
}


// FUNC 0x14808728 FUN_14808728 (LoadMenu)
//   size 0xac | file LoadMenu+0x8728 | callers(8) 0x148049c0 0x14804a44 0x14804ab0 0x14804e44 0x14804eb0 0x14805098 0x14805470 0x14804c98

void FUN_14808728(int param_1,int param_2,uint param_3,int param_4)

{
  undefined1 uVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = 0;
  do {
    piVar2 = *(int **)(param_1 + iVar3 * 4 + 0x1453c);
    (**(code **)(*piVar2 + 0x28))(piVar2,0);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0xf);
  uVar4 = 0;
  if (param_3 != 0) {
    do {
      piVar2 = *(int **)(param_1 + (uint)*(byte *)(param_2 + uVar4) * 4 + 0x1453c);
      (**(code **)(*piVar2 + 0x28))(piVar2,1);
      uVar4 = uVar4 + 1;
    } while (uVar4 < param_3);
  }
  uVar1 = *(undefined1 *)(param_2 + param_4);
  *(undefined1 *)(param_1 + 0x77b9) = 0xff;
  *(undefined1 *)(param_1 + 0x77b8) = uVar1;
  msys::MCursorBase::setVisible((MCursorBase *)(param_1 + 0x77a0),true);
  FUN_1480891c((MCursorBase *)(param_1 + 0x77a0));
  return;
}


// FUNC 0x148087d4 FUN_148087d4 (LoadMenu)
//   size 0xa4 | file LoadMenu+0x87d4 | callers(3) 0x1480309c 0x148030b0 0x148030c8

void FUN_148087d4(SaveDateTime *param_1,int param_2,int param_3)

{
  SaveLoadSys *pSVar1;
  undefined4 uVar2;
  int iVar3;
  SaveLoadSys *pSVar4;
  char *pcVar5;
  
  pcVar5 = *(char **)(&DAT_148175a0 + param_3 * 4);
  uVar2 = msys::MLyt::getPane((MLyt *)(param_2 + 0x490),"SAVE_DATE",pcVar5,(char *)0x0);
  *(undefined4 *)(param_1 + 0xb0c) = uVar2;
  *(short *)(param_1 + 0xb10) = (short)param_3;
  iVar3 = msys::MLyt::getParts((MLyt *)(param_2 + 0x490),pcVar5,(char *)0x0,(char *)0x0);
  ad::lyt::LytAnim::init((LytAnim *)(param_1 + 0xaf0),*(Layout **)(iVar3 + 0xac),"SET_FILEnum","");
  pSVar1 = msys::MComSys::_sys;
  pSVar4 = *(SaveLoadSys **)(param_2 + 8);
  if (*(SaveLoadSys **)(param_2 + 8) == (SaveLoadSys *)0x0) {
    *(SaveLoadSys **)(param_2 + 8) = msys::MComSys::_sys;
    pSVar4 = pSVar1;
  }
  save_load::SaveDateTime::init(param_1,pSVar4,(MLyt *)(param_2 + 0x490),"DATE",pcVar5);
  FUN_148088a4(param_1,param_3);
  return;
}


// FUNC 0x148088a4 FUN_148088a4 (LoadMenu)
//   size 0x78 | file LoadMenu+0x88a4 | callers(5) 0x14805ae0 0x148087d4 0x148038b4 0x14804ab0 0x148051d4

void FUN_148088a4(SaveDateTime *param_1,int param_2)

{
  int iVar1;
  GameWorkPOD *pGVar2;
  byte bVar3;
  uint in_fpscr;
  float fVar4;
  
  if (-1 < param_2) {
    fVar4 = (float)VectorSignedToFloat(param_2,(byte)(in_fpscr >> 0x16) & 3);
    ad::lyt::LytAnim::stopAndSetFrm((LytAnim *)(param_1 + 0xaf0),fVar4);
    *(short *)(param_1 + 0xb10) = (short)param_2;
  }
  iVar1 = Backup::IsNew(*(short *)(param_1 + 0xb10));
  if (iVar1 == 0) {
    pGVar2 = (GameWorkPOD *)Backup::GetSaveData1(*(short *)(param_1 + 0xb10));
    save_load::SaveDateTime::build(param_1,pGVar2);
    iVar1 = *(int *)(param_1 + 0xb0c);
    bVar3 = *(byte *)(iVar1 + 0x44) & 0xfe | 1;
  }
  else {
    iVar1 = *(int *)(param_1 + 0xb0c);
    bVar3 = *(byte *)(iVar1 + 0x44) & 0xfe;
  }
  *(byte *)(iVar1 + 0x44) = bVar3;
  return;
}


// FUNC 0x1480891c FUN_1480891c (LoadMenu)
//   size 0x280 | file LoadMenu+0x891c | callers(9) 0x14802c64 0x14803d40 0x14808728 0x14801fd4 0x14802d5c 0x14803e38 0x148043d8 0x14804d04 ...

void FUN_1480891c(int param_1)

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
                        (this,(char *)((int)&msys::MLyt::
                                             createAnime(unsigned_char,char_const*,bool,signed)::
                                             string_literal + 1));
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
      local_50[0] = s_SQ_CURSOR_S_003f7f5d;
      local_50[1] = s_SQ_CURSOR_L_003f7f69;
      local_50[2] = s_SQ_CURSOR_SS_003f7f75;
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


// FUNC 0x14808bb4 FUN_14808bb4 (LoadMenu)
//   size 0x128 | file LoadMenu+0x8bb4 | callers(7) 0x14805ae0 0x148055fc 0x1480417c 0x14804254 0x1480299c 0x14801fd4 0x148051d4

void FUN_14808bb4(undefined4 *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint in_fpscr;
  float fVar3;
  LytAnim aLStack_38 [4];
  undefined4 local_34;
  undefined4 uStack_30;
  undefined4 local_2c;
  undefined2 local_28;
  undefined2 local_26;
  
  local_34 = 0;
  uStack_30 = 0x3f800000;
  local_2c = 0;
  local_28 = 1;
  local_26 = 0;
  ad::lyt::LytAnim::init(aLStack_38,(Layout *)*param_1,"SET_DATA","");
  if (*(short *)(param_3 + 0x1cd8) == 0) {
    ad::lyt::LytAnim::stopAndSetFrm(aLStack_38,0.0);
  }
  else {
    ad::lyt::LytAnim::stopAndSetFrm(aLStack_38,1.0);
    iVar1 = FUN_148022c0(param_1 + 0x30d,param_2,param_3);
    iVar2 = FUN_14802444(param_1 + 1,param_2,param_3);
    iVar1 = (iVar2 + iVar1 + 4) / 9;
    if (iVar1 == 0) {
      iVar2 = 1;
    }
    else {
      iVar2 = iVar1;
    }
    ad::lyt::LytNumReel3::setValueInstant((LytNumReel3 *)(param_1 + 0x401),iVar2);
    ad::lyt::LytAnim::term(aLStack_38,true);
    ad::lyt::LytAnim::init(aLStack_38,(Layout *)*param_1,"SET_LV_DIGIT","");
    fVar3 = (float)VectorUnsignedToFloat((uint)(9 < iVar1),(byte)(in_fpscr >> 0x16) & 3);
    ad::lyt::LytAnim::stopAndSetFrm(aLStack_38,fVar3);
  }
  ad::lyt::LytAnim::term(aLStack_38,true);
  return;
}


// FUNC 0x14808d08 FUN_14808d08 (LoadMenu)
//   size 0x9c | file LoadMenu+0x8d08 | callers(14) 0x1480c224 0x14802c64 0x14803d40 0x148055fc 0x14806ac8 0x14801fd4 0x14802d5c 0x14803e38 ...

MSndSe * FUN_14808d08(undefined4 param_1,uint param_2,MChrBase *param_3,VEC2 *param_4,bool param_5)

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


// FUNC 0x14808da8 FUN_14808da8 (LoadMenu)
//   size 0x54 | file LoadMenu+0x8da8 | callers(15) 0x14806720 0x14806ac8 0x14809654 0x14808344 0x14803530 0x1480356c 0x148035a8 0x148035e4 ...

void FUN_14808da8(int param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if (param_2 == 1) {
    uVar1 = LMS_GetTextIndexByLabel(param_1 + 0xfd09c,param_3);
    LMS_GetText(param_1 + 0xfd09c,uVar1);
    return;
  }
  uVar1 = LMS_GetTextIndexByLabel(param_1 + 0xfba44,param_3);
  LMS_GetText(param_1 + 0xfba44,uVar1);
  return;
}


// FUNC 0x14808e00 msys::MChrBase::vfunc_0x0 (LoadMenu)
//   size 0x14c | file LoadMenu+0x8e00 | callers(23) 0x14801844 0x14801ea8 0x14801f40 0x148023ec 0x14802410 0x14802910 0x14802958 0x14805e70 ... | datarefs 1

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


// FUNC 0x14808f5c FUN_14808f5c (LoadMenu)
//   size 0xdc | file LoadMenu+0x8f5c | callers(7) 0x14805c80 0x1480925c 0x1480c720 0x1480b8a8 0x148014f4 0x14802ad4 0x1480d8a8

void FUN_14808f5c(undefined4 *param_1)

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
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(puVar1 + 0xc,FUN_14801aec,0x2c,1);
  *(int *)(iVar2 + -8) = iVar2;
  *(undefined1 *)(iVar2 + -4) = 1;
  puVar1 = (undefined4 *)MoveVBase::MoveVBase((MoveVBase *)(iVar2 + 0x2c));
  *puVar1 = &vtable_for_5MoveVILj1EE;
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(puVar1 + 0xc,FUN_14801aec,0x2c,1);
  *(int *)(iVar2 + -8) = iVar2;
  *(undefined1 *)(iVar2 + -4) = 1;
  puVar1 = (undefined4 *)MoveVBase::MoveVBase((MoveVBase *)(iVar2 + 0x2c));
  *puVar1 = &vtable_for_5MoveVILj1EE;
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(puVar1 + 0xc,FUN_14801aec,0x2c,1);
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


// FUNC 0x14809048 FUN_14809048 (LoadMenu)
//   size 0x48 | file LoadMenu+0x9048 | callers(9) 0x14800900 0x148018b0 0x14805c80 0x1480b8a8 0x14806ac8 0x14806608 0x14809654 0x1480b2b8 ...

undefined4 * FUN_14809048(void)

{
  int iVar1;
  
  if ((((byte)nn::math::VEC3::Zero()::zero & 1) == 0) &&
     (iVar1 = __cxa_guard_acquire(&nn::math::VEC3::Zero()::zero), iVar1 != 0)) {
    nn::math::VEC3::Zero()::zero = 0;
    DAT_00434c4c = 0;
    DAT_00434c50 = 0;
    __cxa_guard_release(&nn::math::VEC3::Zero()::zero);
  }
  return &nn::math::VEC3::Zero()::zero;
}


// FUNC 0x148090a0 FUN_148090a0 (LoadMenu)
//   size 0x50 | file LoadMenu+0x90a0 | callers(0) | datarefs 18

void FUN_148090a0(int param_1)

{
  int iVar1;
  int iVar2;
  
  save_load::MsgWnd::play((MsgWnd *)(param_1 + 0x838),"menu_save_err_03",(InsParam *)0x0);
  iVar1 = msys::MComSys::_sys;
  iVar2 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar2 = iVar1;
  }
  *(undefined1 *)(iVar2 + 0xe6508) = 0;
  *(undefined **)(param_1 + 0x20) = &DAT_1480909c;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


// FUNC 0x1480910c FUN_1480910c (LoadMenu)
//   size 0x6c | file LoadMenu+0x910c | callers(0) | datarefs 2

void FUN_1480910c(int param_1)

{
  code *pcVar1;
  
  if (*(int *)(param_1 + 0x7480) == 0) {
    if (*(int *)(param_1 + 0x776c) == 0) {
      pcVar1 = FUN_148090a0;
    }
    else {
      save_load::MsgWnd::play((MsgWnd *)(param_1 + 0x838),"menu_save_err_02",(InsParam *)0x0);
      if (*(int *)(param_1 + 8) == 0) {
        *(undefined4 *)(param_1 + 8) = msys::MComSys::_sys;
      }
      save_load::SaveLoadSys::saveFormat();
      pcVar1 = FUN_14806294;
    }
    *(code **)(param_1 + 0x20) = pcVar1;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x14809194 load_menu::LoadMenuPageBase::Core::Dfx::vfunc_0x4 (LoadMenu)
//   size 0x10 | file LoadMenu+0x9194 | callers(0) | datarefs 1

void load_menu::LoadMenuPageBase::Core::Dfx::vfunc_0x4(MDfxChr *param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)msys::MDfxChr::~MDfxChr(param_1);
  operator_delete(pvVar1);
  return;
}


// FUNC 0x148091a4 ->msys::MDfxChr::~MDfxChr (LoadMenu)
//   size 0x4 | file LoadMenu+0x91a4 | callers(0) | datarefs 1
// veneer/thunk -> 0x003313cc msys::MDfxChr::~MDfxChr (static)

// FUNC 0x1480920c load_menu::LoadMenuPageBase::Core::vfunc_0x8 (LoadMenu)
//   size 0x4c | file LoadMenu+0x920c | callers(0) | datarefs 1

int load_menu::LoadMenuPageBase::Core::vfunc_0x8(int param_1,MInput *param_2)

{
  char cVar1;
  int *piVar2;
  code *extraout_r2;
  code *pcVar3;
  bool bVar4;
  
  msys::MPageBase::updateInputAllChr(*(MPageBase **)(param_1 + 4),param_2);
  bVar4 = (*(uint *)(param_1 + 0x24) & 1) == 0;
  cVar1 = *(char *)(param_1 + 0x7780);
  pcVar3 = extraout_r2;
  if (bVar4) {
    pcVar3 = *(code **)(param_1 + 0x20);
  }
  piVar2 = (int *)(param_1 + ((int)*(uint *)(param_1 + 0x24) >> 1));
  if (!bVar4) {
    pcVar3 = *(code **)(*piVar2 + *(int *)(param_1 + 0x20));
  }
  (*pcVar3)(piVar2,param_2);
  return (int)cVar1;
}


// FUNC 0x1480925c FUN_1480925c (LoadMenu)
//   size 0x250 | file LoadMenu+0x925c | callers(2) 0x14805c80 0x1480c720

void FUN_1480925c(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  *param_1 = &load_menu::LoadMenuPageBase::Core::vtable;
  param_1[1] = param_2;
  param_1[2] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[0xc] = 0;
  iVar1 = ad::font::ResFont::ResFont((ResFont *)(param_1 + 0xd));
  ad::lyt::LytResourceMan::init((LytResourceMan *)(iVar1 + -4));
  iVar1 = ad::fw::Resource::Resource((Resource *)(iVar1 + 0x70));
  puVar2 = (undefined4 *)FUN_14808f5c(iVar1 + 0x44);
  *puVar2 = &msys::MLyt::vtable;
  *(undefined1 *)(puVar2 + 0x53) = 0xff;
  *(undefined2 *)((int)puVar2 + 0x14e) = 0;
  puVar2[0x54] = 0;
  iVar1 = __aeabi_vec_ctor_nocookie_nodtor(puVar2 + 0x55,&LAB_148013b4,0x1c,0xc);
  iVar1 = __aeabi_vec_ctor_nocookie_nodtor(iVar1 + 0x15c,&LAB_14801400,0x10,0xc);
  *(undefined4 *)(iVar1 + 0xc0) = 0;
  *(undefined1 *)(iVar1 + 0xc4) = 1;
  *(undefined4 *)(iVar1 + 200) = 0;
  *(undefined4 *)(iVar1 + 0xcc) = 0;
  *(undefined1 *)(iVar1 + 0xd0) = 0;
  *(undefined4 *)(iVar1 + 0xd4) = 0;
  *(undefined4 *)(iVar1 + 0xd8) = 0;
  FUN_1480d970(iVar1 + -0xc,0xffffffff);
  puVar2 = (undefined4 *)FUN_14808f5c(iVar1 + 0xf8);
  *puVar2 = &msys::MLyt::vtable;
  *(undefined1 *)(puVar2 + 0x53) = 0xff;
  *(undefined2 *)((int)puVar2 + 0x14e) = 0;
  puVar2[0x54] = 0;
  iVar1 = __aeabi_vec_ctor_nocookie_nodtor(puVar2 + 0x55,&LAB_148013b4,0x1c,0xc);
  iVar1 = __aeabi_vec_ctor_nocookie_nodtor(iVar1 + 0x15c,&LAB_14801400,0x10,0xc);
  *(undefined4 *)(iVar1 + 0xc0) = 0;
  *(undefined1 *)(iVar1 + 0xc4) = 1;
  *(undefined4 *)(iVar1 + 200) = 0;
  *(undefined4 *)(iVar1 + 0xcc) = 0;
  *(undefined1 *)(iVar1 + 0xd0) = 0;
  *(undefined4 *)(iVar1 + 0xd4) = 0;
  *(undefined4 *)(iVar1 + 0xd8) = 0;
  FUN_1480d970(iVar1 + -0xc,0xffffffff);
  puVar2 = (undefined4 *)FUN_14808f5c(iVar1 + 0xf8);
  *puVar2 = &msys::MMsgWnd::vtable;
  iVar1 = Message::Message((Message *)(puVar2 + 0x53));
  *(undefined4 *)(iVar1 + 0x6d64) = 0x400;
  *(undefined4 *)(iVar1 + 28000) = 0;
  *(undefined4 *)(iVar1 + 0x6d68) = 0;
  *(undefined4 *)(iVar1 + 0x6d6c) = 0;
  *(undefined4 *)(iVar1 + 0x6d70) = 0;
  *(undefined4 *)(iVar1 + 0x6d74) = 0;
  *(undefined4 *)(iVar1 + 0x6d78) = 6;
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
  *(undefined4 *)(iVar1 + 0x6db0) = 0x400;
  *(undefined4 *)(iVar1 + 0x6dac) = 0;
  *(undefined4 *)(iVar1 + 0x6db4) = 0;
  *(undefined4 *)(iVar1 + 0x6db8) = 0;
  *(undefined4 *)(iVar1 + 0x6dbc) = 0;
  *(undefined4 *)(iVar1 + 0x6dc0) = 0;
  *(undefined4 *)(iVar1 + 0x6dc4) = 6;
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
  *(undefined4 *)(iVar1 + 0x6dec) = 0;
  *(undefined4 *)(iVar1 + 0x6df0) = 0x3f800000;
  *(undefined4 *)(iVar1 + 0x6df4) = 0;
  *(undefined2 *)(iVar1 + 0x6df8) = 1;
  *(undefined2 *)(iVar1 + 0x6dfa) = 0;
  *(undefined1 *)(iVar1 + 0x6dfc) = 0xff;
  return;
}


// FUNC 0x148094d8 load_menu::LoadMenuPageBase::Core::vfunc_0x4 (LoadMenu)
//   size 0x10 | file LoadMenu+0x94d8 | callers(0) | datarefs 1

void load_menu::LoadMenuPageBase::Core::vfunc_0x4(void)

{
  void *pvVar1;
  
  pvVar1 = (void *)vfunc_0x0();
  operator_delete(pvVar1);
  return;
}


// FUNC 0x148094e8 load_menu::LoadMenuPageBase::vfunc_0x28 (LoadMenu)
//   size 0x14 | file LoadMenu+0x94e8 | callers(0) | datarefs 3

int load_menu::LoadMenuPageBase::vfunc_0x28(int param_1,int param_2)

{
  return *(int *)(param_1 + 0x20) + param_2 * 4 + 0xc;
}


// FUNC 0x148094fc load_menu::LoadMenuPageBase::vfunc_0x8 (LoadMenu)
//   size 0x60 | file LoadMenu+0x94fc | callers(0) | datarefs 3

void load_menu::LoadMenuPageBase::vfunc_0x8(int *param_1)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  if (param_1[8] == 0) {
    (**(code **)(*param_1 + 0x2c))(param_1);
    (**(code **)(*param_1 + 0x30))(param_1);
  }
  iVar1 = param_1[8];
  if ((*(uint *)(iVar1 + 0x14) & 1) == 0) {
    UNRECOVERED_JUMPTABLE = *(code **)(iVar1 + 0x10);
  }
  else {
    UNRECOVERED_JUMPTABLE =
         *(code **)(*(int *)(iVar1 + ((int)*(uint *)(iVar1 + 0x14) >> 1)) + *(int *)(iVar1 + 0x10));
  }
                    /* WARNING: Could not recover jumptable at 0x14809558. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// FUNC 0x1480955c load_menu::LoadMenuPageBase::vfunc_0x14 (LoadMenu)
//   size 0x10 | file LoadMenu+0x955c | callers(0) | datarefs 3

void load_menu::LoadMenuPageBase::vfunc_0x14(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x14809568. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(param_1 + 0x20) + 8))();
  return;
}


// FUNC 0x1480956c load_menu::LoadMenuPageBase::vfunc_0xc (LoadMenu)
//   size 0xd8 | file LoadMenu+0x956c | callers(0) | datarefs 3

void load_menu::LoadMenuPageBase::vfunc_0xc(int param_1)

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


// FUNC 0x14809644 load_menu::LoadMenuPageBase::vfunc_0x4 (LoadMenu)
//   size 0x10 | file LoadMenu+0x9644 | callers(0) | datarefs 1

void load_menu::LoadMenuPageBase::vfunc_0x4(void)

{
  void *pvVar1;
  
  pvVar1 = (void *)vfunc_0x0();
  operator_delete(pvVar1);
  return;
}


// FUNC 0x14809654 FUN_14809654 (LoadMenu)
//   size 0x6c0 | file LoadMenu+0x9654 | callers(1) 0x1480a3b8

void FUN_14809654(int param_1)

{
  int iVar1;
  undefined1 uVar2;
  byte bVar3;
  void *pvVar4;
  int *piVar5;
  undefined4 uVar6;
  wchar_t *pwVar7;
  LytAnim *this;
  int *piVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  int iVar11;
  undefined4 *puVar12;
  uint in_fpscr;
  float fVar13;
  LytAnim aLStackY_f8 [128];
  LytLocalize aLStack_50 [16];
  undefined4 local_40;
  
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
  }
  iVar11 = *(int *)(param_1 + 8);
  ad::lyt::LytResourceMan::init((LytResourceMan *)(param_1 + 0x30));
  pvVar4 = (void *)ad::fw::Resource::getFileData((Resource *)(param_1 + 0xa4));
  ad::lyt::LytResourceMan::registerArc((LytResourceMan *)(param_1 + 0x30),pvVar4,".");
  msys::MLyt::build((MLyt *)(param_1 + 0xe8),*(MemAlcBase **)(*(int *)(param_1 + 4) + 0x18),
                    (AnimeName *)&PTR_s_FADE_OUT_1480e374,6);
  iVar11 = iVar11 + 0xd3000;
  msys::MLyt::init((MLyt *)(param_1 + 0xe8),iVar11,1);
  msys::MLyt::createLyt
            ((MLyt *)(param_1 + 0xe8),(LytResourceMan *)(param_1 + 0x30),"AMIIBO_U.bflyt");
  MoveVBase::stop((MoveVBase *)(param_1 + 0x1b4));
  *(undefined4 *)(param_1 + 0x1d0) = 0;
  *(undefined4 *)(param_1 + 0x1d4) = 0;
  *(undefined4 *)(param_1 + 0x1d8) = 0xc3480000;
  *(undefined4 *)(param_1 + 0x1b8) = *(undefined4 *)(param_1 + 0x1d0);
  *(undefined4 *)(param_1 + 0x1bc) = 0;
  *(undefined4 *)(param_1 + 0x1c0) = 0xc3480000;
  *(undefined4 *)(param_1 + 0x224) = 0x400;
  msys::MLyt::build((MLyt *)(param_1 + 0x490),*(MemAlcBase **)(*(int *)(param_1 + 4) + 0x18),
                    (AnimeName *)&PTR_s_FADE_OUT_1480e3a4,4);
  msys::MLyt::init((MLyt *)(param_1 + 0x490),iVar11,1);
  msys::MLyt::createLyt
            ((MLyt *)(param_1 + 0x490),(LytResourceMan *)(param_1 + 0x30),"AMIIBO_L.bflyt");
  MoveVBase::stop((MoveVBase *)(param_1 + 0x55c));
  *(undefined4 *)(param_1 + 0x578) = 0;
  *(undefined4 *)(param_1 + 0x57c) = 0;
  *(undefined4 *)(param_1 + 0x580) = 0xc3480000;
  *(undefined4 *)(param_1 + 0x560) = *(undefined4 *)(param_1 + 0x578);
  *(undefined4 *)(param_1 + 0x564) = 0;
  *(undefined4 *)(param_1 + 0x568) = 0xc3480000;
  *(undefined4 *)(param_1 + 0x5cc) = 0x401;
  *(code **)(param_1 + 0x10) = FUN_1480ad0c;
  *(undefined4 *)(param_1 + 0x14) = 0;
  if (((*(int *)(param_1 + 0x20) == 0) &&
      ((*(uint *)(param_1 + 0x24) & 1) == 0 || *(uint *)(param_1 + 0x24) == 0)) &&
     ((iVar11 = ad::nfp::IsValid(), iVar11 == 0 || (iVar11 = ad::nfp::IsInitialized(), iVar11 != 0))
     )) {
    *(code **)(param_1 + 0x20) = FUN_1480a51c;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  if (*(char *)(param_1 + 0x810) == '\0') {
    return;
  }
  ad::lyt::LytLocalize::LytLocalize(aLStack_50);
  ad::lyt::LytLocalize::localize(aLStack_50,*(Layout **)(param_1 + 0x238));
  ad::lyt::LytLocalize::localize(aLStack_50,*(Layout **)(param_1 + 0x5e0));
  local_40 = 0;
  uVar2 = nn::os::CTR::IsRunOnSnake();
  *(undefined1 *)(param_1 + 0x16968) = uVar2;
  piVar8 = (int *)(*(int *)(param_1 + 4) + 4);
  puVar12 = *(undefined4 **)(param_1 + 0xf0);
  *(undefined4 **)(*(int *)(param_1 + 0xec) + 4) = puVar12;
  *puVar12 = *(undefined4 *)(param_1 + 0xec);
  piVar5 = (int *)(param_1 + 0xec);
  if (piVar5 != (int *)0x0) {
    iVar11 = *piVar8;
    *(int **)(param_1 + 0xf0) = piVar8;
    *piVar5 = iVar11;
    *(int **)(iVar11 + 4) = piVar5;
    *piVar8 = (int)piVar5;
  }
  *(undefined4 *)(param_1 + 0x224) = 0x400;
  puVar12 = *(undefined4 **)(param_1 + 0x498);
  piVar5 = (int *)(*(int *)(param_1 + 4) + 0xc);
  *(undefined4 **)(*(int *)(param_1 + 0x494) + 4) = puVar12;
  *puVar12 = *(undefined4 *)(param_1 + 0x494);
  piVar8 = (int *)(param_1 + 0x494);
  if (piVar8 != (int *)0x0) {
    iVar11 = *piVar5;
    *(int **)(param_1 + 0x498) = piVar5;
    *piVar8 = iVar11;
    *(int **)(iVar11 + 4) = piVar8;
    *piVar5 = (int)piVar8;
  }
  *(undefined4 *)(param_1 + 0x5cc) = 0x401;
  FUN_1480b2b8(param_1 + 0x8bc8,param_1);
  uVar6 = *(undefined4 *)(*(int *)(param_1 + 4) + 0x18);
  *(undefined4 *)(param_1 + 0x16450) = 0x401;
  *(undefined4 *)(param_1 + 0x16444) = uVar6;
  *(undefined4 *)(param_1 + 0x16448) = 0;
  *(undefined4 *)(param_1 + 0x1644c) = 0;
  MessageSimple::init((MessageSimple *)(param_1 + 0xf95c));
  if (((nn::math::VEC3::One()::one & 1) == 0) &&
     (iVar11 = __cxa_guard_acquire(&nn::math::VEC3::One()::one), iVar11 != 0)) {
    nn::math::VEC3::One()::one = 0x3f800000;
    DAT_00434c40 = 0x3f800000;
    DAT_00434c44 = 0x3f800000;
    __cxa_guard_release(&nn::math::VEC3::One()::one);
  }
  MoveVBase::stop((MoveVBase *)(param_1 + 0xf824));
  uVar10 = DAT_00434c44;
  uVar9 = DAT_00434c40;
  uVar6 = nn::math::VEC3::One()::one;
  *(undefined4 *)(param_1 + 0xf840) = nn::math::VEC3::One()::one;
  *(undefined4 *)(param_1 + 0xf844) = uVar9;
  *(undefined4 *)(param_1 + 0xf848) = uVar10;
  *(undefined4 *)(param_1 + 0xf828) = uVar6;
  *(undefined4 *)(param_1 + 0xf82c) = uVar9;
  *(undefined4 *)(param_1 + 0xf830) = uVar10;
  puVar12 = (undefined4 *)FUN_14809048();
  MoveVBase::stop((MoveVBase *)(param_1 + 0xf880));
  uVar6 = *puVar12;
  uVar9 = puVar12[1];
  uVar10 = puVar12[2];
  *(undefined4 *)(param_1 + 0xf89c) = uVar6;
  *(undefined4 *)(param_1 + 0xf8a0) = uVar9;
  *(undefined4 *)(param_1 + 0xf8a4) = uVar10;
  *(undefined4 *)(param_1 + 0xf884) = uVar6;
  *(undefined4 *)(param_1 + 0xf888) = uVar9;
  *(undefined4 *)(param_1 + 0xf88c) = uVar10;
  puVar12 = (undefined4 *)FUN_14809048();
  MoveVBase::stop((MoveVBase *)(param_1 + 0xf8dc));
  uVar6 = *puVar12;
  uVar9 = puVar12[1];
  uVar10 = puVar12[2];
  *(undefined4 *)(param_1 + 0xf8f8) = uVar6;
  *(undefined4 *)(param_1 + 0xf8fc) = uVar9;
  *(undefined4 *)(param_1 + 0xf900) = uVar10;
  *(undefined4 *)(param_1 + 0xf8e0) = uVar6;
  *(undefined4 *)(param_1 + 0xf8e4) = uVar9;
  *(undefined4 *)(param_1 + 0xf8e8) = uVar10;
  *(undefined1 *)(param_1 + 0x15418) = 1;
  *(undefined1 *)(param_1 + 0x15419) = 1;
  MoveVBase::stop((MoveVBase *)(param_1 + 0xf8dc));
  *(undefined4 *)(param_1 + 0xf8f8) = 0;
  *(undefined4 *)(param_1 + 0xf8fc) = 0;
  *(undefined4 *)(param_1 + 0xf900) = 0x3c23d70a;
  *(undefined4 *)(param_1 + 0xf8e0) = *(undefined4 *)(param_1 + 0xf8f8);
  *(undefined4 *)(param_1 + 0xf8e4) = 0;
  *(undefined4 *)(param_1 + 0xf8e8) = 0x3c23d70a;
  iVar1 = msys::MComSys::_sys;
  iVar11 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar11 = iVar1;
  }
  pwVar7 = (wchar_t *)FUN_14808da8(iVar11,0,"amiibo_btn_pnl");
  msys::MMsg::playStr((MMsg *)(param_1 + 0xf810),pwVar7,(InsParam *)0x0,false);
  msys::MLyt::attachMChr
            ((MLyt *)(param_1 + 0x490),(MChrBase *)(param_1 + 0xf810),"INS_LABEL_B_TXT","lbl_B_00",
             (char *)0x0,(char *)0x0);
  piVar5 = (int *)(param_1 + 0x79a4);
  FUN_14806608(param_1 + 0x79a8,*piVar5,*piVar5 + 0x490,"INS_EFFECT");
  if (*(char *)(param_1 + 0x7b27) == '\0') {
    bVar3 = msys::MLyt::createAnimeAutoSlot
                      ((MLyt *)(*piVar5 + 0x490),"AMB_wave","AMB_L_guidance",(char *)0x0);
    *(byte *)(param_1 + 0x7b26) = bVar3;
    this = (LytAnim *)msys::MLyt::getAnim((MLyt *)(*piVar5 + 0x490),(ushort)bVar3);
    ad::lyt::LytAnim::stop(this);
  }
  else {
    uVar2 = msys::MLyt::createAnimeAutoSlot
                      ((MLyt *)(*piVar5 + 0xe8),"AMB_put","AMB_U_guidance",(char *)0x0);
    *(undefined1 *)(param_1 + 0x7b26) = uVar2;
  }
  FUN_14806608(param_1 + 0x7b2c,param_1,param_1 + 0x490,"INS_EFFECT");
  FUN_1480b4c4(param_1 + 0x7ca8);
  iVar11 = 0;
  do {
    ad::lyt::LytAnim::init
              ((LytAnim *)(param_1 + iVar11 * 0x2c + 0x165a0),*(Layout **)(param_1 + 0x238),
               "TWINCLE",(char *)(&DAT_14817630)[iVar11]);
    iVar11 = iVar11 + 1;
  } while (iVar11 < 0x16);
  piVar8 = (int *)(*(int *)(param_1 + 4) + 4);
  puVar12 = *(undefined4 **)(param_1 + 0x1645c);
  *(undefined4 **)(*(int *)(param_1 + 0x16458) + 4) = puVar12;
  *puVar12 = *(undefined4 *)(param_1 + 0x16458);
  piVar5 = (int *)(param_1 + 0x16458);
  if (piVar5 != (int *)0x0) {
    iVar11 = *piVar8;
    *(int **)(param_1 + 0x1645c) = piVar8;
    *piVar5 = iVar11;
    *(int **)(iVar11 + 4) = piVar5;
    *piVar8 = (int)piVar5;
  }
  *(undefined4 *)(param_1 + 0x16590) = 0x400;
  msys::MLyt::stopAnimeAndSetEnd((MLyt *)(param_1 + 0xe8),0,1,(char *)0x0,(char *)0x0);
  msys::MLyt::stopAnimeAndSetEnd((MLyt *)(param_1 + 0xe8),3,0,(char *)0x0,(char *)0x0);
  msys::MLyt::stopAnimeAndSetEnd((MLyt *)(param_1 + 0xe8),4,0,(char *)0x0,(char *)0x0);
  msys::MLyt::stopAnimeAndSetEnd((MLyt *)(param_1 + 0xe8),5,0,(char *)0x0,(char *)0x0);
  msys::MLyt::stopAnimeAndSetEnd((MLyt *)(param_1 + 0x490),0,1,(char *)0x0,(char *)0x0);
  ad::lyt::LytAnim::init(aLStackY_f8 + 0x80,*(Layout **)(param_1 + 0x5e0),"SET_3DStype","");
  fVar13 = (float)VectorUnsignedToFloat
                            ((uint)(*(char *)(param_1 + 0x16968) == '\0'),
                             (byte)(in_fpscr >> 0x16) & 3);
  ad::lyt::LytAnim::stopAndSetFrm(aLStackY_f8 + 0x80,fVar13);
  ad::lyt::LytAnim::term(aLStackY_f8 + 0x80,true);
  *(code **)(param_1 + 0x10) = FUN_148099f8;
  *(undefined4 *)(param_1 + 0x14) = 0;
  if ((*(int *)(param_1 + 0x20) == 0) &&
     ((*(uint *)(param_1 + 0x24) & 1) == 0 || *(uint *)(param_1 + 0x24) == 0)) {
    iVar11 = ad::nfp::IsValid();
    if ((iVar11 == 0) || (iVar11 = ad::nfp::IsInitialized(), iVar11 != 0)) {
      *(code **)(param_1 + 0x20) = FUN_1480a51c;
      *(undefined4 *)(param_1 + 0x24) = 0;
    }
    if ((*(int *)(param_1 + 0x20) == 0) &&
       ((*(uint *)(param_1 + 0x24) & 1) == 0 || *(uint *)(param_1 + 0x24) == 0)) {
      return;
    }
  }
  iVar1 = msys::MComSys::_sys;
  iVar11 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar11 = iVar1;
  }
  *(undefined1 *)(iVar11 + 0xe650a) = 0;
  *(undefined1 *)(*(int *)(param_1 + 4) + 0x14) = 1;
  *(undefined **)(param_1 + 0x10) = &DAT_1480c5c0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}


// FUNC 0x14809840 FUN_14809840 (LoadMenu)
//   size 0x30 | file LoadMenu+0x9840 | callers(0) | datarefs 1

void FUN_14809840(int param_1)

{
  int iVar1;
  
  FUN_148080bc();
  iVar1 = FUN_14806ac8(param_1 + 0x7ca8);
  if (iVar1 != 0) {
    *(code **)(param_1 + 0x20) = FUN_1480c5c4;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x14809874 FUN_14809874 (LoadMenu)
//   size 0x290 | file LoadMenu+0x9874 | callers(0) | datarefs 2

void FUN_14809874(int param_1,undefined4 param_2)

{
  SaveLoadSys *pSVar1;
  int iVar2;
  code *pcVar3;
  int iVar4;
  SaveLoadSys *pSVar5;
  bool bVar6;
  
  if (*(int *)(param_1 + 8) == 0) {
    *(SaveLoadSys **)(param_1 + 8) = msys::MComSys::_sys;
  }
  iVar2 = Backup::errorCode();
  pSVar1 = msys::MComSys::_sys;
  if (iVar2 != 0) {
    if ((iVar2 - 0x2001U < 2) || (iVar2 - 0x2001U == 2)) {
      *(code **)(param_1 + 0x28) = FUN_1480c658;
      *(undefined4 *)(param_1 + 0x2c) = 0;
      pcVar3 = FUN_14806438;
    }
    else {
      pcVar3 = FUN_148090a0;
    }
    *(code **)(param_1 + 0x20) = pcVar3;
    *(undefined4 *)(param_1 + 0x24) = 0;
    return;
  }
  pSVar5 = *(SaveLoadSys **)(param_1 + 8);
  if (*(SaveLoadSys **)(param_1 + 8) == (SaveLoadSys *)0x0) {
    *(SaveLoadSys **)(param_1 + 8) = msys::MComSys::_sys;
    pSVar5 = pSVar1;
  }
  iVar2 = save_load::SaveLoadSys::saveIsBusyWriting(pSVar5);
  if (iVar2 != 0) {
    FUN_148080bc(param_1);
    return;
  }
  if (*(char *)(param_1 + 0x16969) != '\0') {
    if (*(short *)(*(int *)(param_1 + 0x818) + 4) == 1) {
      FUN_148069e0(param_1 + 0x8bc8,"amiibo_seq_01_03",0);
      msys::MLyt::stopAnimeAndSetEnd((MLyt *)(param_1 + 0x490),1,0,(char *)0x0,(char *)0x0);
    }
    *(code **)(param_1 + 0x20) = FUN_1480b1f0;
    *(undefined4 *)(param_1 + 0x24) = 0;
    return;
  }
  FUN_14806a54(param_1 + 0x8bc8);
  *(uint *)(param_1 + 0x8ba8) = (*(uint *)(param_1 + 0x8ba8) & 0xff0000) + 0x10000;
  *(undefined4 *)(param_1 + 0x20) = 0x14809ab4;
  *(undefined4 *)(param_1 + 0x24) = 0;
  FUN_148080bc(param_1,param_2);
  iVar2 = FUN_14806ac8();
  if (iVar2 != 0) {
    iVar2 = ad::nfp::GetState();
    if ((iVar2 != 3 && iVar2 != 5) && iVar2 != 6) {
      ad::nfp::StopDetection();
      *(undefined1 *)(param_1 + 0x79a1) = 0;
      msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x490),2,0,(char *)0x0,(char *)0x0);
      *(uint *)(param_1 + 0x8ba8) = (*(uint *)(param_1 + 0x8ba8) & 0xff0000) + 0x10000;
      *(code **)(param_1 + 0x20) = FUN_1480ab28;
      *(undefined4 *)(param_1 + 0x24) = 0;
      iVar2 = FUN_14806ac8((int *)(param_1 + 0x7ca8));
      if (iVar2 != 0) {
        Frm::play((Frm *)(param_1 + 0x7770),DAT_148180bc);
        pSVar1 = msys::MComSys::_sys;
        pSVar5 = *(SaveLoadSys **)(param_1 + 8);
        if (*(SaveLoadSys **)(param_1 + 8) == (SaveLoadSys *)0x0) {
          *(SaveLoadSys **)(param_1 + 8) = msys::MComSys::_sys;
          pSVar5 = pSVar1;
        }
        pSVar5[0xe6508] = (SaveLoadSys)0x1;
        *(code **)(param_1 + 0x20) = FUN_1480ab9c;
        *(undefined4 *)(param_1 + 0x24) = 0;
      }
    }
    iVar2 = *(int *)(param_1 + 0x20);
    bVar6 = iVar2 == 0x14809ab4;
    if (bVar6) {
      iVar2 = *(int *)(param_1 + 0x24);
    }
    if (bVar6 && iVar2 == 0) {
      FUN_148067e4(param_1 + 0x79a4,1);
      iVar4 = *(int *)(param_1 + 0x7ca8);
      iVar2 = 0;
      if (*(char *)(iVar4 + 0x16968) != '\0') {
        iVar2 = 9;
      }
      FUN_14806720(iVar4 + 0x8bc8,
                   (&PTR_s_amiibo_seq_05_a_1_148175e8)[(uint)*(byte *)(param_1 + 0x8bc3) + iVar2],0)
      ;
      *(code **)(param_1 + 0x20) = FUN_1480a424;
      *(undefined4 *)(param_1 + 0x24) = 0;
    }
  }
  return;
}


// FUNC 0x148099f8 FUN_148099f8 (LoadMenu)
//   size 0xb0 | file LoadMenu+0x99f8 | callers(0) | datarefs 1

void FUN_148099f8(int param_1)

{
  int iVar1;
  int iVar2;
  
  if ((*(int *)(param_1 + 0x20) == 0) &&
     ((*(uint *)(param_1 + 0x24) & 1) == 0 || *(uint *)(param_1 + 0x24) == 0)) {
    iVar1 = ad::nfp::IsValid();
    if ((iVar1 == 0) || (iVar1 = ad::nfp::IsInitialized(), iVar1 != 0)) {
      *(code **)(param_1 + 0x20) = FUN_1480a51c;
      *(undefined4 *)(param_1 + 0x24) = 0;
    }
    if ((*(int *)(param_1 + 0x20) == 0) &&
       ((*(uint *)(param_1 + 0x24) & 1) == 0 || *(uint *)(param_1 + 0x24) == 0)) {
      return;
    }
  }
  iVar1 = msys::MComSys::_sys;
  iVar2 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar2 = iVar1;
  }
  *(undefined1 *)(iVar2 + 0xe650a) = 0;
  *(undefined1 *)(*(int *)(param_1 + 4) + 0x14) = 1;
  *(undefined **)(param_1 + 0x10) = &DAT_1480c5c0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}


// FUNC 0x14809c1c FUN_14809c1c (LoadMenu)
//   size 0x6c8 | file LoadMenu+0x9c1c | callers(0) | datarefs 2

void FUN_14809c1c(int param_1,uint *param_2)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  GameWork *this;
  void *pvVar4;
  int iVar5;
  code *pcVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  char *pcVar10;
  uint unaff_r6;
  void *unaff_r9;
  bool bVar11;
  longlong lVar12;
  undefined4 uVar13;
  undefined4 local_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  char acStack_4c [12];
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 local_30;
  undefined4 uStack_2c;
  
  if ((*param_2 & 0x802) != 0) {
    ad::nfp::StopDetection();
    *(undefined1 *)(param_1 + 0x79a1) = 0;
    iVar7 = msys::MComSys::_sys;
    iVar3 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar3 = iVar7;
    }
    *(undefined1 *)(iVar3 + 0xe6508) = 0;
    FUN_14808d08(param_1,0x110017,0,0,0);
    *(undefined1 *)(param_1 + 0x7780) = 0;
    return;
  }
  uVar2 = FUN_14801978(param_1 + 0x7784);
  iVar3 = msys::MComSys::_sys;
  iVar7 = param_1 + 0x8bc8;
  iVar8 = param_1 + 0x79a4;
  switch(uVar2) {
  case 1:
    bVar11 = *(char *)(param_1 + 0x79a1) == '\0';
    if (!bVar11) {
      unaff_r6 = (uint)*(byte *)(param_1 + 0x778f);
      unaff_r9 = (void *)(param_1 + 0x7785);
      bVar11 = unaff_r9 == (void *)0x0;
    }
    if (((bVar11) || (10 < unaff_r6)) || (unaff_r6 == 0)) {
      ad::nfp::StopDetection();
      goto switchD_14809cc0_caseD_5;
    }
    if (*(char *)(param_1 + 0x16968) != '\0') {
      if (*(Unit **)(param_1 + 0x7c80) != (Unit *)0x0) {
        ad::dfx::Unit::forceDeletable(*(Unit **)(param_1 + 0x7c80));
      }
      msys::MDfxChr::playDfx((MDfxChr *)(param_1 + 0x7b2c),0x1a);
    }
    Mem::Copy(acStack_4c,unaff_r9,10);
    iVar5 = msys::MComSys::_sys;
    cVar1 = *(char *)(param_1 + 0x79a0);
    iVar3 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar3 = iVar5;
    }
    *(undefined1 *)(iVar3 + 0xe6508) = 0;
    msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x490),3,0,(char *)0x0,(char *)0x0);
    nn::fnd::DateTime::GetNow((DateTime *)&local_30);
    nn::fnd::DateTime::GetParameters();
    local_64 = local_40;
    uStack_60 = uStack_3c;
    uStack_5c = uStack_38;
    iVar3 = GameWork::cmpNfpDate((GameWork *)&gGameWork,(DateTimeParameters *)&local_64);
    GameWork::setNfpDate((GameWork *)&gGameWork,(DateTimeParameters *)&local_64);
    if (iVar3 < 1) {
      if (0x3f < DAT_003fbe9e) {
        FUN_148069e0(iVar7,"amiibo_seq_01_03",0);
        msys::MLyt::stopAnimeAndSetEnd((MLyt *)(param_1 + 0x490),1,0,(char *)0x0,(char *)0x0);
        FUN_14808d08(param_1,0x11003e,0,0,0);
        FUN_148067e4(iVar8,1);
        if (DAT_003fbe9e == 0xff) {
          this = operator_new(0x2918,*(MemAlcBase **)(*(int *)(param_1 + 4) + 0x18),(char *)0x0,0);
          pvVar4 = (void *)Backup::GetSaveData1(-1);
          Mem::Copy(this,pvVar4,0x28c0);
          iVar3 = GameWork::isTimeFalsification(this);
          if ((iVar3 != 0) ||
             (lVar12 = nn::cfg::CTR::GetTransferableId(0x1ca9),
             lVar12 != *(longlong *)(this + 0x25d8))) {
            *(undefined1 *)(param_1 + 0x16969) = 1;
          }
          operator_delete(this);
        }
        if (*(char *)(param_1 + 0x16969) == '\0') {
          puVar9 = &DAT_1480e24c;
        }
        else {
          puVar9 = &DAT_1480e244;
        }
        uVar2 = puVar9[1];
        *(undefined4 *)(param_1 + 0x20) = *puVar9;
        *(undefined4 *)(param_1 + 0x24) = uVar2;
        break;
      }
    }
    else {
      DAT_003fbe9e = 0;
    }
    iVar3 = 0;
    uVar2 = local_30;
    uVar13 = uStack_2c;
    if (DAT_003fbe9e != 0) {
      do {
        if (((byte)(&DAT_003fbbe8)[iVar3 * 0xb] == unaff_r6) &&
           (iVar5 = strncmp(acStack_4c,&DAT_003fbbde + iVar3 * 0xb,unaff_r6), iVar5 == 0))
        goto LAB_1480a03c;
        iVar3 = iVar3 + 1;
      } while (iVar3 < (int)(uint)DAT_003fbe9e);
    }
    if (unaff_r6 != 0) {
      FUN_14808d08(param_1,0x11003d,0,0,0,iVar7,uVar2,uVar13);
      FUN_1480baa4(param_1 + 0x7ca8,(short)cVar1);
      Mem::Copy(&DAT_003fbbde + (uint)DAT_003fbe9e * 0xb,acStack_4c,10);
      (&DAT_003fbbe8)[(uint)DAT_003fbe9e * 0xb] = (char)unaff_r6;
      DAT_003fbe9e = DAT_003fbe9e + 1;
      msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0xe8),4,0,(char *)0x0,(char *)0x0);
      msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0xe8),5,1,(char *)0x0,(char *)0x0);
      *(code **)(param_1 + 0x20) = FUN_14809840;
      *(undefined4 *)(param_1 + 0x24) = 0;
      FUN_148080bc(param_1);
      iVar3 = FUN_14806ac8(param_1 + 0x7ca8);
      if (iVar3 != 0) {
        *(code **)(param_1 + 0x20) = FUN_1480c5c4;
        *(undefined4 *)(param_1 + 0x24) = 0;
      }
      break;
    }
LAB_1480a03c:
    FUN_148069e0(iVar7,"amiibo_seq_01_02",0);
    msys::MLyt::stopAnimeAndSetEnd((MLyt *)(param_1 + 0x490),1,0,(char *)0x0,(char *)0x0);
    FUN_14808d08(param_1,0x11003e,0,0,0);
    FUN_148067e4(iVar8,1);
    goto LAB_1480a11c;
  case 2:
    iVar5 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar5 = iVar3;
    }
    *(undefined1 *)(iVar5 + 0xe6508) = 0;
    msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x490),3,0,(char *)0x0,(char *)0x0);
    FUN_148069e0(iVar7,"amiibo_sys_err_08",0);
    msys::MLyt::stopAnimeAndSetEnd((MLyt *)(param_1 + 0x490),1,0,(char *)0x0,(char *)0x0);
    FUN_14808d08(param_1,0x11003e,0,0,0);
    FUN_148067e4(iVar8,1);
LAB_1480a11c:
    *(code **)(param_1 + 0x20) = FUN_1480b1f0;
    *(undefined4 *)(param_1 + 0x24) = 0;
    break;
  case 3:
    iVar5 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar5 = iVar3;
    }
    *(undefined1 *)(iVar5 + 0xe6508) = 0;
    msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x490),3,0,(char *)0x0,(char *)0x0);
    if (*(char *)(param_1 + 0x16968) == '\0') {
      pcVar10 = "amiibo_sys_err_09a";
    }
    else {
      pcVar10 = "amiibo_sys_err_09b";
    }
    FUN_148069e0(iVar7,pcVar10,0);
    msys::MLyt::stopAnimeAndSetEnd((MLyt *)(param_1 + 0x490),1,0,(char *)0x0,(char *)0x0);
    FUN_14808d08(param_1,0x11003e,0,0,0);
    FUN_148067e4(iVar8,1);
    *(code **)(param_1 + 0x20) = FUN_1480b1f0;
    *(undefined4 *)(param_1 + 0x24) = 0;
    break;
  case 4:
    iVar5 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar5 = iVar3;
    }
    *(undefined1 *)(iVar5 + 0xe6508) = 0;
    msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x490),3,0,(char *)0x0,(char *)0x0);
    FUN_148069e0(iVar7,"amiibo_sys_err_01",0);
    msys::MLyt::stopAnimeAndSetEnd((MLyt *)(param_1 + 0x490),1,0,(char *)0x0,(char *)0x0);
    FUN_14808d08(param_1,0x11003e,0,0,0);
    FUN_148067e4(iVar8,1);
    *(code **)(param_1 + 0x20) = FUN_1480b1f0;
    *(undefined4 *)(param_1 + 0x24) = 0;
    break;
  case 5:
    goto switchD_14809cc0_caseD_5;
  case 6:
    iVar7 = FUN_1480ad78(param_1);
    iVar3 = msys::MComSys::_sys;
    if (iVar7 != 0) {
      iVar7 = *(int *)(param_1 + 8);
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar7 = iVar3;
      }
      *(undefined1 *)(iVar7 + 0xe6508) = 0;
      msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x490),3,0,(char *)0x0,(char *)0x0);
      FUN_14808d08(param_1,0x11003e,0,0,0);
      break;
    }
    goto switchD_14809cc0_caseD_5;
  }
switchD_14809cc0_caseD_0:
  pcVar6 = *(code **)(param_1 + 0x20);
  bVar11 = pcVar6 == FUN_14809c1c;
  if (bVar11) {
    pcVar6 = *(code **)(param_1 + 0x24);
  }
  if (bVar11 && pcVar6 == (code *)0x0) {
    return;
  }
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0xe8),3,0,(char *)0x0,(char *)0x0);
  return;
switchD_14809cc0_caseD_5:
  *(undefined1 *)(param_1 + 0x79a1) = 0;
  ad::nfp::StartDetection(1);
  goto switchD_14809cc0_caseD_0;
}


// FUNC 0x1480a3b8 FUN_1480a3b8 (LoadMenu)
//   size 0x68 | file LoadMenu+0xa3b8 | callers(0) | datarefs 2

void FUN_1480a3b8(int param_1)

{
  int iVar1;
  
  if (((*(int *)(param_1 + 0x20) == 0) &&
      ((*(uint *)(param_1 + 0x24) & 1) == 0 || *(uint *)(param_1 + 0x24) == 0)) &&
     ((iVar1 = ad::nfp::IsValid(), iVar1 == 0 || (iVar1 = ad::nfp::IsInitialized(), iVar1 != 0)))) {
    *(code **)(param_1 + 0x20) = FUN_1480a51c;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  if (*(char *)(param_1 + 0xa8) == '\0') {
    return;
  }
  FUN_14809654(param_1);
  return;
}


// FUNC 0x1480a424 FUN_1480a424 (LoadMenu)
//   size 0xc8 | file LoadMenu+0xa424 | callers(0) | datarefs 2

void FUN_1480a424(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = ad::nfp::GetState();
  if ((iVar1 != 3 && iVar1 != 5) && iVar1 != 6) {
    ad::nfp::StopDetection();
    *(undefined1 *)(param_1 + 0x79a1) = 0;
    msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x490),2,0,(char *)0x0,(char *)0x0);
    *(uint *)(param_1 + 0x8ba8) = (*(uint *)(param_1 + 0x8ba8) & 0xff0000) + 0x10000;
    *(code **)(param_1 + 0x20) = FUN_1480ab28;
    *(undefined4 *)(param_1 + 0x24) = 0;
    iVar1 = FUN_14806ac8();
    if (iVar1 != 0) {
      Frm::play((Frm *)(param_1 + 0x7770),DAT_148180bc);
      iVar1 = msys::MComSys::_sys;
      iVar2 = *(int *)(param_1 + 8);
      if (*(int *)(param_1 + 8) == 0) {
        *(int *)(param_1 + 8) = msys::MComSys::_sys;
        iVar2 = iVar1;
      }
      *(undefined1 *)(iVar2 + 0xe6508) = 1;
      *(code **)(param_1 + 0x20) = FUN_1480ab9c;
      *(undefined4 *)(param_1 + 0x24) = 0;
    }
  }
  return;
}


// FUNC 0x1480a51c FUN_1480a51c (LoadMenu)
//   size 0x64 | file LoadMenu+0xa51c | callers(0) | datarefs 9

void FUN_1480a51c(int param_1)

{
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0xe8),4,1,(char *)0x0,(char *)0x0);
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x490),2,1,(char *)0x0,(char *)0x0);
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x490),3,1,(char *)0x0,(char *)0x0);
  *(code **)(param_1 + 0x20) = FUN_1480b07c;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


// FUNC 0x1480ab28 FUN_1480ab28 (LoadMenu)
//   size 0x68 | file LoadMenu+0xab28 | callers(0) | datarefs 4

void FUN_1480ab28(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_14806ac8(param_1 + 0x7ca8);
  if (iVar1 != 0) {
    Frm::play((Frm *)(param_1 + 0x7770),DAT_148180bc);
    iVar1 = msys::MComSys::_sys;
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar2 = iVar1;
    }
    *(undefined1 *)(iVar2 + 0xe6508) = 1;
    *(code **)(param_1 + 0x20) = FUN_1480ab9c;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x1480ab9c FUN_1480ab9c (LoadMenu)
//   size 0x100 | file LoadMenu+0xab9c | callers(0) | datarefs 6

void FUN_1480ab9c(int param_1,uint *param_2)

{
  int iVar1;
  int iVar2;
  float fVar3;
  
  iVar2 = msys::MComSys::_sys;
  if ((*param_2 & 0xc03) == 0) {
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
  *(uint *)(param_1 + 0x8ba8) = (*(uint *)(param_1 + 0x8ba8) & 0xff0000) + 0x10000;
  FUN_14806ac8();
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0xe8),5,0,(char *)0x0,(char *)0x0);
  iVar1 = msys::MComSys::_sys;
  iVar2 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar2 = iVar1;
  }
  *(undefined1 *)(iVar2 + 0xe6508) = 0;
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0xe8),4,1,(char *)0x0,(char *)0x0);
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x490),2,1,(char *)0x0,(char *)0x0);
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x490),3,1,(char *)0x0,(char *)0x0);
  *(code **)(param_1 + 0x20) = FUN_1480b07c;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


// FUNC 0x1480acb0 FUN_1480acb0 (LoadMenu)
//   size 0x54 | file LoadMenu+0xacb0 | callers(0) | datarefs 2

void FUN_1480acb0(int param_1)

{
  MComSys *pMVar1;
  int iVar2;
  MComSys *this;
  
  iVar2 = msys::MLyt::isBusyAnime((MLyt *)(param_1 + 0x490));
  pMVar1 = msys::MComSys::_sys;
  if (iVar2 == 0) {
    this = *(MComSys **)(param_1 + 8);
    if (*(MComSys **)(param_1 + 8) == (MComSys *)0x0) {
      *(MComSys **)(param_1 + 8) = msys::MComSys::_sys;
      this = pMVar1;
    }
    iVar2 = msys::MComSys::getNextPage(this);
    if (*(char *)(iVar2 + 0x14) != '\0') {
      *(undefined1 **)(param_1 + 0x18) = &LAB_1480c160;
      *(undefined4 *)(param_1 + 0x1c) = 0;
    }
  }
  return;
}


// FUNC 0x1480ad0c FUN_1480ad0c (LoadMenu)
//   size 0x68 | file LoadMenu+0xad0c | callers(0) | datarefs 1

void FUN_1480ad0c(int param_1)

{
  int iVar1;
  undefined1 uVar2;
  byte bVar3;
  int *piVar4;
  undefined4 uVar5;
  wchar_t *pwVar6;
  LytAnim *this;
  int iVar7;
  int *piVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 *puVar11;
  uint in_fpscr;
  float fVar12;
  LytAnim aLStackY_f8 [128];
  LytLocalize aLStack_50 [16];
  undefined4 uStack_40;
  
  if (((*(int *)(param_1 + 0x20) == 0) &&
      ((*(uint *)(param_1 + 0x24) & 1) == 0 || *(uint *)(param_1 + 0x24) == 0)) &&
     ((iVar7 = ad::nfp::IsValid(), iVar7 == 0 || (iVar7 = ad::nfp::IsInitialized(), iVar7 != 0)))) {
    *(code **)(param_1 + 0x20) = FUN_1480a51c;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  if (*(char *)(param_1 + 0x810) == '\0') {
    return;
  }
  ad::lyt::LytLocalize::LytLocalize(aLStack_50);
  ad::lyt::LytLocalize::localize(aLStack_50,*(Layout **)(param_1 + 0x238));
  ad::lyt::LytLocalize::localize(aLStack_50,*(Layout **)(param_1 + 0x5e0));
  uStack_40 = 0;
  uVar2 = nn::os::CTR::IsRunOnSnake();
  *(undefined1 *)(param_1 + 0x16968) = uVar2;
  piVar8 = (int *)(*(int *)(param_1 + 4) + 4);
  puVar11 = *(undefined4 **)(param_1 + 0xf0);
  *(undefined4 **)(*(int *)(param_1 + 0xec) + 4) = puVar11;
  *puVar11 = *(undefined4 *)(param_1 + 0xec);
  piVar4 = (int *)(param_1 + 0xec);
  if (piVar4 != (int *)0x0) {
    iVar7 = *piVar8;
    *(int **)(param_1 + 0xf0) = piVar8;
    *piVar4 = iVar7;
    *(int **)(iVar7 + 4) = piVar4;
    *piVar8 = (int)piVar4;
  }
  *(undefined4 *)(param_1 + 0x224) = 0x400;
  puVar11 = *(undefined4 **)(param_1 + 0x498);
  piVar4 = (int *)(*(int *)(param_1 + 4) + 0xc);
  *(undefined4 **)(*(int *)(param_1 + 0x494) + 4) = puVar11;
  *puVar11 = *(undefined4 *)(param_1 + 0x494);
  piVar8 = (int *)(param_1 + 0x494);
  if (piVar8 != (int *)0x0) {
    iVar7 = *piVar4;
    *(int **)(param_1 + 0x498) = piVar4;
    *piVar8 = iVar7;
    *(int **)(iVar7 + 4) = piVar8;
    *piVar4 = (int)piVar8;
  }
  *(undefined4 *)(param_1 + 0x5cc) = 0x401;
  FUN_1480b2b8(param_1 + 0x8bc8,param_1);
  uVar5 = *(undefined4 *)(*(int *)(param_1 + 4) + 0x18);
  *(undefined4 *)(param_1 + 0x16450) = 0x401;
  *(undefined4 *)(param_1 + 0x16444) = uVar5;
  *(undefined4 *)(param_1 + 0x16448) = 0;
  *(undefined4 *)(param_1 + 0x1644c) = 0;
  MessageSimple::init((MessageSimple *)(param_1 + 0xf95c));
  if (((nn::math::VEC3::One()::one & 1) == 0) &&
     (iVar7 = __cxa_guard_acquire(&nn::math::VEC3::One()::one), iVar7 != 0)) {
    nn::math::VEC3::One()::one = 0x3f800000;
    DAT_00434c40 = 0x3f800000;
    DAT_00434c44 = 0x3f800000;
    __cxa_guard_release(&nn::math::VEC3::One()::one);
  }
  MoveVBase::stop((MoveVBase *)(param_1 + 0xf824));
  uVar10 = DAT_00434c44;
  uVar9 = DAT_00434c40;
  uVar5 = nn::math::VEC3::One()::one;
  *(undefined4 *)(param_1 + 0xf840) = nn::math::VEC3::One()::one;
  *(undefined4 *)(param_1 + 0xf844) = uVar9;
  *(undefined4 *)(param_1 + 0xf848) = uVar10;
  *(undefined4 *)(param_1 + 0xf828) = uVar5;
  *(undefined4 *)(param_1 + 0xf82c) = uVar9;
  *(undefined4 *)(param_1 + 0xf830) = uVar10;
  puVar11 = (undefined4 *)FUN_14809048();
  MoveVBase::stop((MoveVBase *)(param_1 + 0xf880));
  uVar5 = *puVar11;
  uVar9 = puVar11[1];
  uVar10 = puVar11[2];
  *(undefined4 *)(param_1 + 0xf89c) = uVar5;
  *(undefined4 *)(param_1 + 0xf8a0) = uVar9;
  *(undefined4 *)(param_1 + 0xf8a4) = uVar10;
  *(undefined4 *)(param_1 + 0xf884) = uVar5;
  *(undefined4 *)(param_1 + 0xf888) = uVar9;
  *(undefined4 *)(param_1 + 0xf88c) = uVar10;
  puVar11 = (undefined4 *)FUN_14809048();
  MoveVBase::stop((MoveVBase *)(param_1 + 0xf8dc));
  uVar5 = *puVar11;
  uVar9 = puVar11[1];
  uVar10 = puVar11[2];
  *(undefined4 *)(param_1 + 0xf8f8) = uVar5;
  *(undefined4 *)(param_1 + 0xf8fc) = uVar9;
  *(undefined4 *)(param_1 + 0xf900) = uVar10;
  *(undefined4 *)(param_1 + 0xf8e0) = uVar5;
  *(undefined4 *)(param_1 + 0xf8e4) = uVar9;
  *(undefined4 *)(param_1 + 0xf8e8) = uVar10;
  *(undefined1 *)(param_1 + 0x15418) = 1;
  *(undefined1 *)(param_1 + 0x15419) = 1;
  MoveVBase::stop((MoveVBase *)(param_1 + 0xf8dc));
  *(undefined4 *)(param_1 + 0xf8f8) = 0;
  *(undefined4 *)(param_1 + 0xf8fc) = 0;
  *(undefined4 *)(param_1 + 0xf900) = 0x3c23d70a;
  *(undefined4 *)(param_1 + 0xf8e0) = *(undefined4 *)(param_1 + 0xf8f8);
  *(undefined4 *)(param_1 + 0xf8e4) = 0;
  *(undefined4 *)(param_1 + 0xf8e8) = 0x3c23d70a;
  iVar1 = msys::MComSys::_sys;
  iVar7 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar7 = iVar1;
  }
  pwVar6 = (wchar_t *)FUN_14808da8(iVar7,0,"amiibo_btn_pnl");
  msys::MMsg::playStr((MMsg *)(param_1 + 0xf810),pwVar6,(InsParam *)0x0,false);
  msys::MLyt::attachMChr
            ((MLyt *)(param_1 + 0x490),(MChrBase *)(param_1 + 0xf810),"INS_LABEL_B_TXT","lbl_B_00",
             (char *)0x0,(char *)0x0);
  piVar4 = (int *)(param_1 + 0x79a4);
  FUN_14806608(param_1 + 0x79a8,*piVar4,*piVar4 + 0x490,"INS_EFFECT");
  if (*(char *)(param_1 + 0x7b27) == '\0') {
    bVar3 = msys::MLyt::createAnimeAutoSlot
                      ((MLyt *)(*piVar4 + 0x490),"AMB_wave","AMB_L_guidance",(char *)0x0);
    *(byte *)(param_1 + 0x7b26) = bVar3;
    this = (LytAnim *)msys::MLyt::getAnim((MLyt *)(*piVar4 + 0x490),(ushort)bVar3);
    ad::lyt::LytAnim::stop(this);
  }
  else {
    uVar2 = msys::MLyt::createAnimeAutoSlot
                      ((MLyt *)(*piVar4 + 0xe8),"AMB_put","AMB_U_guidance",(char *)0x0);
    *(undefined1 *)(param_1 + 0x7b26) = uVar2;
  }
  FUN_14806608(param_1 + 0x7b2c,param_1,param_1 + 0x490,"INS_EFFECT");
  FUN_1480b4c4(param_1 + 0x7ca8);
  iVar7 = 0;
  do {
    ad::lyt::LytAnim::init
              ((LytAnim *)(param_1 + iVar7 * 0x2c + 0x165a0),*(Layout **)(param_1 + 0x238),"TWINCLE"
               ,(char *)(&DAT_14817630)[iVar7]);
    iVar7 = iVar7 + 1;
  } while (iVar7 < 0x16);
  piVar8 = (int *)(*(int *)(param_1 + 4) + 4);
  puVar11 = *(undefined4 **)(param_1 + 0x1645c);
  *(undefined4 **)(*(int *)(param_1 + 0x16458) + 4) = puVar11;
  *puVar11 = *(undefined4 *)(param_1 + 0x16458);
  piVar4 = (int *)(param_1 + 0x16458);
  if (piVar4 != (int *)0x0) {
    iVar7 = *piVar8;
    *(int **)(param_1 + 0x1645c) = piVar8;
    *piVar4 = iVar7;
    *(int **)(iVar7 + 4) = piVar4;
    *piVar8 = (int)piVar4;
  }
  *(undefined4 *)(param_1 + 0x16590) = 0x400;
  msys::MLyt::stopAnimeAndSetEnd((MLyt *)(param_1 + 0xe8),0,1,(char *)0x0,(char *)0x0);
  msys::MLyt::stopAnimeAndSetEnd((MLyt *)(param_1 + 0xe8),3,0,(char *)0x0,(char *)0x0);
  msys::MLyt::stopAnimeAndSetEnd((MLyt *)(param_1 + 0xe8),4,0,(char *)0x0,(char *)0x0);
  msys::MLyt::stopAnimeAndSetEnd((MLyt *)(param_1 + 0xe8),5,0,(char *)0x0,(char *)0x0);
  msys::MLyt::stopAnimeAndSetEnd((MLyt *)(param_1 + 0x490),0,1,(char *)0x0,(char *)0x0);
  ad::lyt::LytAnim::init(aLStackY_f8 + 0x80,*(Layout **)(param_1 + 0x5e0),"SET_3DStype","");
  fVar12 = (float)VectorUnsignedToFloat
                            ((uint)(*(char *)(param_1 + 0x16968) == '\0'),
                             (byte)(in_fpscr >> 0x16) & 3);
  ad::lyt::LytAnim::stopAndSetFrm(aLStackY_f8 + 0x80,fVar12);
  ad::lyt::LytAnim::term(aLStackY_f8 + 0x80,true);
  *(code **)(param_1 + 0x10) = FUN_148099f8;
  *(undefined4 *)(param_1 + 0x14) = 0;
  if ((*(int *)(param_1 + 0x20) == 0) &&
     ((*(uint *)(param_1 + 0x24) & 1) == 0 || *(uint *)(param_1 + 0x24) == 0)) {
    iVar7 = ad::nfp::IsValid();
    if ((iVar7 == 0) || (iVar7 = ad::nfp::IsInitialized(), iVar7 != 0)) {
      *(code **)(param_1 + 0x20) = FUN_1480a51c;
      *(undefined4 *)(param_1 + 0x24) = 0;
    }
    if ((*(int *)(param_1 + 0x20) == 0) &&
       ((*(uint *)(param_1 + 0x24) & 1) == 0 || *(uint *)(param_1 + 0x24) == 0)) {
      return;
    }
  }
  iVar1 = msys::MComSys::_sys;
  iVar7 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar7 = iVar1;
  }
  *(undefined1 *)(iVar7 + 0xe650a) = 0;
  *(undefined1 *)(*(int *)(param_1 + 4) + 0x14) = 1;
  *(undefined **)(param_1 + 0x10) = &DAT_1480c5c0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}


// FUNC 0x1480ad78 FUN_1480ad78 (LoadMenu)
//   size 0x1f8 | file LoadMenu+0xad78 | callers(2) 0x1480a504 0x14809c1c

undefined4 FUN_1480ad78(int param_1)

{
  undefined4 uVar1;
  char *pcVar2;
  
  uVar1 = ad::nfp::GetNewResult();
  switch(uVar1) {
  case 0:
  case 1:
    return 0;
  case 2:
  case 6:
  case 8:
  case 0xc:
    ad::nfp::StopDetection();
    *(undefined1 *)(param_1 + 0x79a1) = 0;
    FUN_148069e0(param_1 + 0x8bc8,"amiibo_sys_err_03",0);
    goto LAB_1480af48;
  case 3:
    ad::nfp::StopDetection();
    *(undefined1 *)(param_1 + 0x79a1) = 0;
    FUN_148069e0(param_1 + 0x8bc8,"amiibo_sys_err_02",0);
LAB_1480af48:
    *(code **)(param_1 + 0x20) = FUN_1480b040;
    *(undefined4 *)(param_1 + 0x24) = 0;
    break;
  case 4:
  case 7:
    FUN_148069e0(param_1 + 0x8bc8,"amiibo_sys_err_03",0);
    msys::MLyt::stopAnimeAndSetEnd((MLyt *)(param_1 + 0x490),1,0,(char *)0x0,(char *)0x0);
    FUN_148067e4(param_1 + 0x79a4,1);
    *(code **)(param_1 + 0x20) = FUN_1480b1f0;
    *(undefined4 *)(param_1 + 0x24) = 0;
    break;
  case 5:
    ad::nfp::StopDetection();
    *(undefined1 *)(param_1 + 0x79a1) = 0;
    if (*(char *)(param_1 + 0x16968) == '\0') {
      pcVar2 = "amiibo_sys_err_09a";
    }
    else {
      pcVar2 = "amiibo_sys_err_09b";
    }
    FUN_148069e0(param_1 + 0x8bc8,pcVar2,0);
    msys::MLyt::stopAnimeAndSetEnd((MLyt *)(param_1 + 0x490),1,0,(char *)0x0,(char *)0x0);
    FUN_148067e4(param_1 + 0x79a4,1);
    *(code **)(param_1 + 0x20) = FUN_1480b1f0;
    *(undefined4 *)(param_1 + 0x24) = 0;
    break;
  case 9:
    ad::nfp::StopDetection();
    *(undefined1 *)(param_1 + 0x79a1) = 0;
    FUN_148069e0(param_1 + 0x8bc8,"amiibo_sys_err_05",0);
    *(undefined1 **)(param_1 + 0x20) = &LAB_1480b16c;
    *(undefined4 *)(param_1 + 0x24) = 0;
    break;
  case 10:
    ad::nfp::StopDetection();
    *(undefined1 *)(param_1 + 0x79a1) = 0;
    FUN_148069e0(param_1 + 0x8bc8,"amiibo_sys_err_07",0);
    *(code **)(param_1 + 0x20) = FUN_1480b040;
    *(undefined4 *)(param_1 + 0x24) = 0;
    break;
  case 0xb:
    ad::nfp::StopDetection();
    *(undefined1 *)(param_1 + 0x79a1) = 0;
    FUN_148069e0(param_1 + 0x8bc8,"amiibo_sys_err_06",0);
    *(code **)(param_1 + 0x20) = FUN_1480b040;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return 1;
}


// FUNC 0x1480b040 FUN_1480b040 (LoadMenu)
//   size 0x38 | file LoadMenu+0xb040 | callers(0) | datarefs 5

void FUN_1480b040(int param_1)

{
  if (*(int *)(param_1 + 0x7480) == 0) {
    FUN_14806a54(param_1 + 0x8bc8);
    *(undefined1 **)(param_1 + 0x20) = &LAB_148099e8;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x1480b07c FUN_1480b07c (LoadMenu)
//   size 0xb8 | file LoadMenu+0xb07c | callers(0) | datarefs 8

void FUN_1480b07c(int param_1)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  
  iVar1 = msys::MLyt::isEnableAnime((MLyt *)(param_1 + 0x490));
  if (iVar1 == 0) {
    *(undefined1 *)(param_1 + 0x16969) = 0;
    iVar1 = ad::nfp::IsValid();
    if (iVar1 == 0) {
      *(undefined1 **)(param_1 + 0x20) = &LAB_1480a4fc;
      *(undefined4 *)(param_1 + 0x24) = 0;
      return;
    }
    if (*(char *)(param_1 + 0x16968) == '\0') {
      pcVar2 = "amiibo_seq_01_a";
    }
    else {
      pcVar2 = "amiibo_seq_01_b";
    }
    FUN_14806720(param_1 + 0x8bc8,pcVar2,0);
    *(undefined1 *)(param_1 + 0x79a1) = 0;
    ad::nfp::StartDetection(1);
    FUN_148067e4(param_1 + 0x79a4,0);
    iVar1 = msys::MComSys::_sys;
    iVar3 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = msys::MComSys::_sys;
      iVar3 = iVar1;
    }
    *(undefined1 *)(iVar3 + 0xe6508) = 1;
    *(code **)(param_1 + 0x20) = FUN_14809c1c;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x1480b1c4 FUN_1480b1c4 (LoadMenu)
//   size 0x28 | file LoadMenu+0xb1c4 | callers(0) | datarefs 2

void FUN_1480b1c4(int param_1)

{
  ad::nfp::StartAmiiboSetting(3,0,1);
  *(code **)(param_1 + 0x20) = FUN_1480b07c;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


// FUNC 0x1480b1f0 FUN_1480b1f0 (LoadMenu)
//   size 0x68 | file LoadMenu+0xb1f0 | callers(0) | datarefs 9

void FUN_1480b1f0(int param_1)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 0x7480) == 0) &&
     (iVar1 = ad::nfp::GetState(), (iVar1 != 3 && iVar1 != 5) && iVar1 != 6)) {
    FUN_14806a54(param_1 + 0x8bc8);
    msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x490),3,1,(char *)0x0,(char *)0x0);
    *(code **)(param_1 + 0x20) = FUN_1480b07c;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}


// FUNC 0x1480b25c load_menu::LoadMenuAmiiboPage::Core::vfunc_0x8 (LoadMenu)
//   size 0x58 | file LoadMenu+0xb25c | callers(0) | datarefs 1

int load_menu::LoadMenuAmiiboPage::Core::vfunc_0x8(int param_1,MInput *param_2)

{
  char cVar1;
  int *piVar2;
  code *extraout_r2;
  code *pcVar3;
  bool bVar4;
  
  msys::MPageBase::updateInputAllChr(*(MPageBase **)(param_1 + 4),param_2);
  bVar4 = (*(uint *)(param_1 + 0x24) & 1) == 0;
  cVar1 = *(char *)(param_1 + 0x7780);
  pcVar3 = extraout_r2;
  if (bVar4) {
    pcVar3 = *(code **)(param_1 + 0x20);
  }
  piVar2 = (int *)(param_1 + ((int)*(uint *)(param_1 + 0x24) >> 1));
  if (!bVar4) {
    pcVar3 = *(code **)(*piVar2 + *(int *)(param_1 + 0x20));
  }
  (*pcVar3)(piVar2,param_2);
  FUN_1480c224(param_1 + 0x79a4);
  return (int)cVar1;
}


// FUNC 0x1480b2b8 FUN_1480b2b8 (LoadMenu)
//   size 0x1d8 | file LoadMenu+0xb2b8 | callers(1) 0x14809654

void FUN_1480b2b8(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  MemAlcBase *pMVar5;
  
  *param_1 = param_2;
  iVar2 = *(int *)(*(int *)(param_2 + 4) + 0x18);
  param_1[0x1b11] = 0x400;
  param_1[0x1b0e] = iVar2;
  param_1[0x1b0f] = 0;
  param_1[0x1b10] = 0;
  MessageSimple::init((MessageSimple *)(param_1 + 0x54));
  if (((nn::math::VEC3::One()::one & 1) == 0) &&
     (iVar2 = __cxa_guard_acquire(&nn::math::VEC3::One()::one), iVar2 != 0)) {
    nn::math::VEC3::One()::one = 0x3f800000;
    DAT_00434c40 = 0x3f800000;
    DAT_00434c44 = 0x3f800000;
    __cxa_guard_release(&nn::math::VEC3::One()::one);
  }
  MoveVBase::stop((MoveVBase *)(param_1 + 6));
  iVar4 = DAT_00434c44;
  iVar3 = DAT_00434c40;
  iVar2 = nn::math::VEC3::One()::one;
  param_1[0xd] = nn::math::VEC3::One()::one;
  param_1[0xe] = iVar3;
  param_1[0xf] = iVar4;
  param_1[7] = iVar2;
  param_1[8] = iVar3;
  param_1[9] = iVar4;
  piVar1 = (int *)FUN_14809048();
  MoveVBase::stop((MoveVBase *)(param_1 + 0x1d));
  iVar2 = *piVar1;
  iVar3 = piVar1[1];
  iVar4 = piVar1[2];
  param_1[0x24] = iVar2;
  param_1[0x25] = iVar3;
  param_1[0x26] = iVar4;
  param_1[0x1e] = iVar2;
  param_1[0x1f] = iVar3;
  param_1[0x20] = iVar4;
  piVar1 = (int *)FUN_14809048();
  MoveVBase::stop((MoveVBase *)(param_1 + 0x34));
  iVar2 = *piVar1;
  iVar3 = piVar1[1];
  iVar4 = piVar1[2];
  param_1[0x3b] = iVar2;
  param_1[0x3c] = iVar3;
  param_1[0x3d] = iVar4;
  param_1[0x35] = iVar2;
  param_1[0x36] = iVar3;
  param_1[0x37] = iVar4;
  *(undefined1 *)(param_1 + 0x1703) = 1;
  *(undefined1 *)((int)param_1 + 0x5c0d) = 1;
  MoveVBase::stop((MoveVBase *)(param_1 + 0x34));
  param_1[0x3b] = 0;
  param_1[0x3c] = 0;
  param_1[0x3d] = 0x3c23d70a;
  param_1[0x35] = param_1[0x3b];
  param_1[0x36] = 0;
  param_1[0x37] = 0x3c23d70a;
  msys::MLyt::attachMChr
            ((MLyt *)(param_2 + 0xe8),(MChrBase *)(param_1 + 1),"INS_EXP_UPPER_CURSOR_txt",
             (char *)0x0,(char *)0x0,(char *)0x0);
  iVar2 = msys::MComSys::_sys;
  pMVar5 = *(MemAlcBase **)(*(MPageBase **)(param_2 + 4) + 0x18);
  iVar3 = *(int *)(param_2 + 8);
  if (*(int *)(param_2 + 8) == 0) {
    *(int *)(param_2 + 8) = msys::MComSys::_sys;
    iVar3 = iVar2;
  }
  save_load::MsgWnd::init
            ((MsgWnd *)(param_2 + 0x838),*(MPageBase **)(param_2 + 4),*(void **)(iVar3 + 0xfba38),
             pMVar5,0x400);
  msys::MLyt::stopAnimeAndSetEnd((MLyt *)(param_2 + 0xe8),2,0,(char *)0x0,(char *)0x0);
  msys::MLyt::setAnimeInfo((MLyt *)(param_2 + 0xe8),1,0);
  msys::MLyt::setAnimeInfo((MLyt *)(param_2 + 0x490),1,0);
  return;
}


// FUNC 0x1480b4c4 FUN_1480b4c4 (LoadMenu)
//   size 0xec | file LoadMenu+0xb4c4 | callers(1) 0x14809654

void FUN_1480b4c4(int *param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint *local_60;
  int local_5c;
  TransMultiSymbol aTStack_58 [52];
  undefined4 local_24;
  
  iVar4 = msys::MComSys::_sys;
  iVar3 = *(int *)(*param_1 + 8);
  if (iVar3 == 0) {
    *(int *)(*param_1 + 8) = msys::MComSys::_sys;
    iVar3 = iVar4;
  }
  iVar2 = *(int *)(iVar3 + 0x278);
  iVar4 = iVar2 + 0x150;
  ad::TransMultiSymbol::init(aTStack_58,(char *)(iVar3 + 0xfcfd4));
  do {
    if (iVar4 == iVar2 + 0x3f0) {
      iVar4 = 0;
LAB_1480b590:
      FUN_1480b724(param_1 + 0x153,iVar4,iVar3 + 0xfcfc8,iVar3 + 0xfcabc);
      return;
    }
    if (*(char *)(iVar4 + 4) == '\x13') {
      local_24 = *(undefined4 *)(iVar4 + 0x24);
      BinGlu4Acs::getEntryAcs((char *)&local_60);
      if (local_60 != (uint *)0x0) {
        if (local_5c == 2) {
          bVar1 = *(byte *)((int)local_60 + 7) >> 7;
        }
        else {
          bVar1 = *(byte *)((int)local_60 + 7) >> 6;
        }
        if ((~bVar1 & 1) != 0) {
          iVar4 = *(int *)(iVar4 + 0x24) + (*local_60 & 0x3fffffff);
          goto LAB_1480b590;
        }
      }
    }
    iVar4 = iVar4 + 0xa8;
  } while( true );
}


// FUNC 0x1480b5bc load_menu::LoadMenuAmiiboPage::Core::ItemMan::CAChr::vfunc_0x10 (LoadMenu)
//   size 0x94 | file LoadMenu+0xb5bc | callers(0) | datarefs 1

void load_menu::LoadMenuAmiiboPage::Core::ItemMan::CAChr::vfunc_0x10(MCAChr *param_1)

{
  float fVar1;
  float fVar2;
  
  fVar1 = *(float *)(param_1 + 0x284);
  fVar2 = 1.0;
  if ((0.0 < fVar1) && (fVar2 = 0.0, (int)fVar1 < 0x43820000)) {
    fVar2 = (260.0 - fVar1) * 0.0038461538;
  }
  *(float *)(param_1 + 0x2d8) = *(float *)(param_1 + 0x428) * fVar2;
  *(float *)(param_1 + 0x2dc) = *(float *)(param_1 + 0x42c) * fVar2;
  *(undefined4 *)(param_1 + 0x2e0) = 0x3f800000;
  *(float *)(param_1 + 0x284) = fVar1 + *(float *)(param_1 + 0x430);
  msys::MCAChr::applyAnime(param_1);
  *(float *)(param_1 + 0x284) = *(float *)(param_1 + 0x284) - *(float *)(param_1 + 0x430);
  return;
}


// FUNC 0x1480b664 load_menu::LoadMenuAmiiboPage::Core::ItemMan::CAChr::vfunc_0x8 (LoadMenu)
//   size 0xb4 | file LoadMenu+0xb664 | callers(0) | datarefs 1

void load_menu::LoadMenuAmiiboPage::Core::ItemMan::CAChr::vfunc_0x8
               (float param_1,MCellAnime *param_2)

{
  int iVar1;
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 local_18;
  
  if (param_2[0x434] == (MCellAnime)0x1) {
    iVar1 = MoveVBase::isBusy((MoveVBase *)(param_2 + 0x27c));
    if (iVar1 == 0) {
      param_2[0x434] = (MCellAnime)0x0;
    }
  }
  else if ((param_2[0x434] == (MCellAnime)0x2) &&
          (iVar1 = MoveVBase::isBusy((MoveVBase *)(param_2 + 0x27c)), iVar1 == 0)) {
    local_20 = 0;
    uStack_1c = 0x3f800000;
    local_18 = 0;
    MoveVBase::jumpFT((MoveVBase *)(param_2 + 0x27c),0.0,DAT_14818070,DAT_14818074,(VEC3 *)&local_20
                     );
    param_2[0x434] = (MCellAnime)0x1;
  }
  msys::MCellAnime::updateAnimeFrm(param_2,param_1);
  MoveVBase::update((MoveVBase *)(param_2 + 0x27c),param_1);
  return;
}


// FUNC 0x1480b724 FUN_1480b724 (LoadMenu)
//   size 0xa0 | file LoadMenu+0xb724 | callers(2) 0x14806ac8 0x1480b4c4

void FUN_1480b724(MCAChr *param_1,int param_2,Resource *param_3,Resource *param_4)

{
  char cVar1;
  uint in_fpscr;
  undefined4 uVar2;
  float fVar3;
  float fVar4;
  
  msys::MCAChr::init(param_1,param_3,param_4);
  CellAnime::play((CellAnime *)(param_1 + 0x2fc),*(uchar *)(param_2 + 0x18),0,1.0);
  if (param_2 != 0) {
    cVar1 = *(char *)(param_2 + 0x1c);
    uVar2 = VectorSignedToFloat((int)*(char *)(param_2 + 0x1b),(byte)(in_fpscr >> 0x16) & 3);
    *(undefined4 *)(param_1 + 0x2f0) = uVar2;
    fVar3 = (float)VectorSignedToFloat((int)cVar1,(byte)(in_fpscr >> 0x16) & 3);
    *(float *)(param_1 + 0x2f4) = fVar3 * -1.5;
    *(undefined4 *)(param_1 + 0x2f8) = 0;
    fVar3 = (float)VectorUnsignedToFloat
                             ((uint)*(byte *)(param_2 + 0x19),(byte)(in_fpscr >> 0x16) & 3);
    fVar4 = (float)VectorUnsignedToFloat
                             ((uint)*(byte *)(param_2 + 0x1a),(byte)(in_fpscr >> 0x16) & 3);
    *(float *)(param_1 + 0x428) = fVar3 * 0.03125;
    *(float *)(param_1 + 0x42c) = fVar4 * 0.03125;
  }
  return;
}


// FUNC 0x1480b7d4 load_menu::LoadMenuAmiiboPage::Core::ItemMan::CAChr::vfunc_0x40 (LoadMenu)
//   size 0x4 | file LoadMenu+0xb7d4 | callers(0) | datarefs 1

void load_menu::LoadMenuAmiiboPage::Core::ItemMan::CAChr::vfunc_0x40(void)

{
  return;
}


// FUNC 0x1480b7d8 load_menu::LoadMenuAmiiboPage::Core::ItemMan::CAChr::vfunc_0x38 (LoadMenu)
//   size 0x1c | file LoadMenu+0xb7d8 | callers(0) | datarefs 1

void load_menu::LoadMenuAmiiboPage::Core::ItemMan::CAChr::vfunc_0x38(int param_1)

{
  CellAnime::term((CellAnime *)(param_1 + 0x14c));
  CellAnime::term((CellAnime *)(param_1 + 0x2fc));
  return;
}


// FUNC 0x1480b7f4 FUN_1480b7f4 (LoadMenu)
//   size 0xb0 | file LoadMenu+0xb7f4 | callers(1) 0x14806ac8

void FUN_1480b7f4(int param_1,Resource *param_2)

{
  void *pvVar1;
  undefined4 *puVar2;
  void *pvVar3;
  
  CellAnime::term((CellAnime *)(param_1 + 0x14c));
  pvVar1 = (void *)ad::fw::Resource::getCA_anm(param_2);
  puVar2 = (undefined4 *)ad::fw::Resource::getCA_tex(param_2);
  pvVar3 = (void *)ad::fw::Resource::getCA_canm(param_2);
  CellAnime::init((CellAnime *)(param_1 + 0x14c),pvVar1,(void *)*puVar2,pvVar3,'\0',0,1.0);
  *(byte *)(param_1 + 0x1ef) = *(byte *)(param_1 + 0x1ef) & 0xef;
  *(undefined1 *)(param_1 + 0x1e9) = 1;
  *(undefined1 *)(param_1 + 0x1e4) = 1;
  *(undefined1 *)(param_1 + 0x1e6) = 4;
  *(undefined1 *)(param_1 + 0x1e5) = 0;
  *(undefined2 *)(param_1 + 0x1ec) = 0xffff;
  *(byte *)(param_1 + 0x1ef) = *(byte *)(param_1 + 0x1ef) & 0xfd | 1;
  return;
}


// FUNC 0x1480b8a8 FUN_1480b8a8 (LoadMenu)
//   size 0x10c | file LoadMenu+0xb8a8 | callers(1) 0x1480c720

undefined4 * FUN_1480b8a8(void)

{
  undefined4 *puVar1;
  int iVar2;
  VEC3 *pVVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  puVar1 = (undefined4 *)FUN_14808f5c();
  *puVar1 = &msys::MCellAnime::vtable;
  iVar2 = CellAnime::CellAnime((CellAnime *)(puVar1 + 0x53));
  *(undefined1 *)(iVar2 + 300) = 0xff;
  *(undefined1 *)(iVar2 + 0x12d) = 0xff;
  *(undefined1 *)(iVar2 + 0x12e) = 0xff;
  *(undefined1 *)(iVar2 + 0x12f) = 0xff;
  *(undefined ***)(iVar2 + -0x14c) = &msys::MCAChr::vtable;
  pVVar3 = (VEC3 *)FUN_14809048();
  puVar1 = (undefined4 *)MoveVBase::MoveVBase((MoveVBase *)(iVar2 + 0x130),pVVar3);
  *puVar1 = &vtable_for_5MoveVILj1EE;
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(puVar1 + 0xc,FUN_14801aec,0x2c,1);
  *(int *)(iVar2 + -8) = iVar2;
  *(undefined1 *)(iVar2 + -4) = 1;
  puVar1 = (undefined4 *)FUN_14809048();
  uVar5 = puVar1[1];
  uVar6 = puVar1[2];
  *(undefined4 *)(iVar2 + 0x38) = *puVar1;
  *(undefined4 *)(iVar2 + 0x3c) = uVar5;
  *(undefined4 *)(iVar2 + 0x40) = uVar6;
  *(undefined4 *)(iVar2 + 0x44) = 0;
  *(undefined4 *)(iVar2 + 0x48) = 0xc1c00000;
  *(undefined4 *)(iVar2 + 0x4c) = 0;
  iVar2 = CellAnime::CellAnime((CellAnime *)(iVar2 + 0x50));
  *(undefined4 *)(iVar2 + -0x2fc) = &load_menu::LoadMenuAmiiboPage::Core::ItemMan::CAChr::vtable;
  if ((((byte)nn::math::VEC2::Zero()::zero & 1) == 0) &&
     (iVar4 = __cxa_guard_acquire(&nn::math::VEC2::Zero()::zero), iVar4 != 0)) {
    nn::math::VEC2::Zero()::zero = 0;
    DAT_003f7ee4 = 0;
    __cxa_guard_release(&nn::math::VEC2::Zero()::zero);
  }
  uVar5 = DAT_003f7ee4;
  *(undefined4 *)(iVar2 + 300) = nn::math::VEC2::Zero()::zero;
  *(undefined4 *)(iVar2 + 0x130) = uVar5;
  *(undefined4 *)(iVar2 + 0x134) = 0;
  *(undefined1 *)(iVar2 + 0x138) = 0;
  return (undefined4 *)(iVar2 + -0x2fc);
}


// FUNC 0x1480b9d8 load_menu::LoadMenuAmiiboPage::Core::ItemMan::CAChr::vfunc_0x4 (LoadMenu)
//   size 0x58 | file LoadMenu+0xb9d8 | callers(0) | datarefs 1

void load_menu::LoadMenuAmiiboPage::Core::ItemMan::CAChr::vfunc_0x4(undefined4 *param_1)

{
  int iVar1;
  void *pvVar2;
  
  *param_1 = &msys::MCAChr::vtable;
  iVar1 = CellAnime::~CellAnime((CellAnime *)(param_1 + 0xbf));
  *(undefined ***)(iVar1 + -0x80) = &vtable_for_5MoveVILj1EE;
  __aeabi_vec_dtor(iVar1 + -0x50,MoveWorkF::~MoveWorkF,0x2c,1);
  iVar1 = MoveVBase::~MoveVBase((MoveVBase *)(iVar1 + -0x80));
  *(undefined ***)(iVar1 + -0x27c) = &msys::MCellAnime::vtable;
  iVar1 = CellAnime::~CellAnime((CellAnime *)(iVar1 + -0x130));
  pvVar2 = (void *)msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  operator_delete(pvVar2);
  return;
}


// FUNC 0x1480ba40 load_menu::LoadMenuAmiiboPage::Core::ItemMan::CAChr::vfunc_0x0 (LoadMenu)
//   size 0x54 | file LoadMenu+0xba40 | callers(0) | datarefs 1

void load_menu::LoadMenuAmiiboPage::Core::ItemMan::CAChr::vfunc_0x0(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &msys::MCAChr::vtable;
  iVar1 = CellAnime::~CellAnime((CellAnime *)(param_1 + 0xbf));
  *(undefined ***)(iVar1 + -0x80) = &vtable_for_5MoveVILj1EE;
  __aeabi_vec_dtor(iVar1 + -0x50,MoveWorkF::~MoveWorkF,0x2c,1);
  iVar1 = MoveVBase::~MoveVBase((MoveVBase *)(iVar1 + -0x80));
  *(undefined ***)(iVar1 + -0x27c) = &msys::MCellAnime::vtable;
  iVar1 = CellAnime::~CellAnime((CellAnime *)(iVar1 + -0x130));
  msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  return;
}


// FUNC 0x1480baa4 FUN_1480baa4 (LoadMenu)
//   size 0x344 | file LoadMenu+0xbaa4 | callers(1) 0x14809c1c

void FUN_1480baa4(int *param_1,int param_2)

{
  ushort *puVar1;
  int iVar2;
  uint uVar3;
  ushort *puVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  int iVar8;
  ushort *puVar9;
  int iVar10;
  byte bVar11;
  uint uVar12;
  int iStack_140;
  ushort auStack_13c [34];
  KJChrData aKStack_f8 [163];
  byte local_55;
  int *piStack_2c;
  int local_28;
  
  piStack_2c = param_1;
  local_28 = param_2;
  __aeabi_memcpy4(&iStack_140,&DAT_1480e484,0x48);
  iVar2 = RandSys::get((RandSys *)&gRand);
  *(undefined1 *)((int)param_1 + 0xf1a) = 0;
  uVar3 = (uint)(iVar2 * 100) >> 0x10;
  if (0x27 < uVar3) {
    do {
      uVar12 = *(byte *)((int)param_1 + 0xf1a) + 1;
      iVar2 = (&DAT_1480e478)[*(byte *)((int)param_1 + 0xf1a)];
      *(char *)((int)param_1 + 0xf1a) = (char)uVar12;
      uVar3 = uVar3 - iVar2;
    } while ((uint)(&DAT_1480e478)[uVar12 & 0xff] <= uVar3);
  }
  *(char *)((int)param_1 + 0xf1a) = *(char *)((int)param_1 + 0xf1a) + '\x01';
  bVar11 = 1;
  if (DAT_003fbaf0 != 0) {
    KJDB::Chr::getData((Chr *)(KJDB::_inst + 8),aKStack_f8,(KJMemberPOD *)&DAT_003f9fd0);
    bVar11 = local_55;
  }
  iVar6 = local_28;
  iVar2 = local_28 * 4;
  puVar4 = operator_new__((uint)auStack_13c[local_28 * 4] << 2,
                          *(MemAlcBase **)(*(int *)(*param_1 + 4) + 0x18),(char *)0x0,0);
  uVar3 = 0;
  iVar10 = 0;
  iVar8 = 0;
  if (auStack_13c[iVar6 * 4] != 0) {
    do {
      iVar5 = *(int *)(auStack_13c + iVar2 + -2);
      if (*(byte *)(iVar5 + iVar8 * 4 + 3) <= bVar11) {
        uVar3 = uVar3 + *(byte *)(iVar5 + iVar8 * 4 + 2);
        Mem::Copy(puVar4 + iVar10 * 2,(void *)(iVar5 + iVar8 * 4),4);
        iVar10 = iVar10 + 1;
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < (int)(uint)auStack_13c[iVar6 * 4]);
  }
  iVar2 = 0;
  if (*(char *)((int)param_1 + 0xf1a) != '\0') {
    do {
      iVar6 = RandSys::get((RandSys *)&gRand);
      uVar12 = iVar6 * (uVar3 & 0xffff) >> 0x10;
      puVar9 = puVar4;
      if ((byte)puVar4[1] <= uVar12) {
        do {
          puVar1 = puVar9 + 3;
          uVar12 = uVar12 - (byte)puVar9[1];
          puVar9 = puVar9 + 2;
        } while ((byte)*puVar1 <= uVar12);
      }
      *(ushort *)((int)param_1 + iVar2 * 2 + 0xf14) = *puVar9;
      uVar12 = (uint)*puVar9;
      if ((*puVar9 & 0xf000) == 0) {
        if ((byte)(&DAT_003fbad0)[uVar12] < 99) {
          (&DAT_003fbad0)[uVar12] = (&DAT_003fbad0)[uVar12] + 1;
        }
      }
      else {
        GameWork::addItem((GameWork *)&gGameWork,uVar12,1);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)(uint)*(byte *)((int)param_1 + 0xf1a));
  }
  operator_delete__(puVar4);
  if (*(char *)(*param_1 + 0x16968) == '\0') {
    pcVar7 = "amiibo_seq_02_a";
  }
  else {
    pcVar7 = "amiibo_seq_02_b";
  }
  FUN_14806720(*param_1 + 0x8bc8,pcVar7,0);
  param_1[0x3c0] = 0;
  iVar2 = 0;
  *(char *)((int)param_1 + 0xf1b) = (char)local_28;
  do {
    ad::fw::Resource::term((Resource *)(param_1 + iVar2 * 0x11 + 1));
    iVar2 = iVar2 + 1;
  } while (iVar2 < 4);
  switch(local_28) {
  case 0:
    param_1[0x151] = 0;
    param_1[0x300] = (int)&DAT_14817540;
    param_1[0x3bf] = 1;
    break;
  case 1:
    param_1[0x151] = 0;
    param_1[0x300] = (int)&DAT_14817548;
    param_1[0x3bf] = 1;
    return;
  case 2:
    param_1[0x151] = 0;
    param_1[0x300] = (int)&DAT_14817528;
    param_1[0x3bf] = 0;
    return;
  case 3:
    param_1[0x151] = 0;
    param_1[0x300] = (int)&DAT_1481752c;
    param_1[0x3bf] = 0;
    return;
  case 4:
    param_1[0x151] = 0;
    param_1[0x300] = (int)&DAT_14817570;
    param_1[0x3bf] = 2;
    return;
  case 5:
    param_1[0x151] = 0;
    param_1[0x300] = (int)&DAT_14817550;
    param_1[0x3bf] = 1;
    return;
  case 6:
    param_1[0x151] = 0;
    param_1[0x300] = (int)&DAT_14817530;
    param_1[0x3bf] = 0;
    return;
  case 7:
    param_1[0x151] = 0;
    param_1[0x300] = (int)&DAT_14817534;
    param_1[0x3bf] = 0;
    return;
  case 8:
    param_1[0x151] = DAT_14818004;
    param_1[0x300] = (int)&DAT_14817538;
    param_1[0x3bf] = 0;
    return;
  }
  return;
}


// FUNC 0x1480be7c FUN_1480be7c (LoadMenu)
//   size 0x144 | file LoadMenu+0xbe7c | callers(2) 0x1480c910 0x1480c9e4

int FUN_1480be7c(int param_1)

{
  int iVar1;
  
  CellAnime::term((CellAnime *)(param_1 + 0x698));
  CellAnime::term((CellAnime *)(param_1 + 0x848));
  iVar1 = 0;
  do {
    ad::fw::Resource::term((Resource *)(param_1 + iVar1 * 0x44 + 4));
    iVar1 = iVar1 + 1;
  } while (iVar1 < 4);
  *(undefined4 *)(param_1 + 0xf0c) = 0;
  iVar1 = msys::MDfxChr::~MDfxChr((MDfxChr *)(param_1 + 0xd80));
  iVar1 = msys::MDfxChr::~MDfxChr((MDfxChr *)(iVar1 + -0x17c));
  *(undefined ***)(iVar1 + -0x280) = &msys::MCellAnime::vtable;
  iVar1 = CellAnime::~CellAnime((CellAnime *)(iVar1 + -0x134));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  *(undefined ***)(iVar1 + -0x438) = &msys::MCAChr::vtable;
  iVar1 = CellAnime::~CellAnime((CellAnime *)(iVar1 + -0x13c));
  *(undefined ***)(iVar1 + -0x80) = &vtable_for_5MoveVILj1EE;
  __aeabi_vec_dtor(iVar1 + -0x50,MoveWorkF::~MoveWorkF,0x2c,1);
  iVar1 = MoveVBase::~MoveVBase((MoveVBase *)(iVar1 + -0x80));
  *(undefined ***)(iVar1 + -0x27c) = &msys::MCellAnime::vtable;
  iVar1 = CellAnime::~CellAnime((CellAnime *)(iVar1 + -0x130));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  *(undefined ***)(iVar1 + -0x438) = &msys::MCAChr::vtable;
  iVar1 = CellAnime::~CellAnime((CellAnime *)(iVar1 + -0x13c));
  *(undefined ***)(iVar1 + -0x80) = &vtable_for_5MoveVILj1EE;
  __aeabi_vec_dtor(iVar1 + -0x50,MoveWorkF::~MoveWorkF,0x2c,1);
  iVar1 = MoveVBase::~MoveVBase((MoveVBase *)(iVar1 + -0x80));
  *(undefined ***)(iVar1 + -0x27c) = &msys::MCellAnime::vtable;
  iVar1 = CellAnime::~CellAnime((CellAnime *)(iVar1 + -0x130));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  __aeabi_vec_dtor(iVar1 + -0x110,ad::fw::Resource::~Resource,0x44,4);
  return iVar1 + -0x114;
}


// FUNC 0x1480bfd8 load_menu::LoadMenuAmiiboPage::Core::StarMan::vfunc_0x20 (LoadMenu)
//   size 0x8 | file LoadMenu+0xbfd8 | callers(0) | datarefs 1

undefined4 load_menu::LoadMenuAmiiboPage::Core::StarMan::vfunc_0x20(void)

{
  return 1;
}


// FUNC 0x1480bfe0 load_menu::LoadMenuAmiiboPage::Core::StarMan::vfunc_0x8 (LoadMenu)
//   size 0xec | file LoadMenu+0xbfe0 | callers(0) | datarefs 1

void load_menu::LoadMenuAmiiboPage::Core::StarMan::vfunc_0x8(float param_1,int param_2)

{
  bool bVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  uint in_fpscr;
  float fVar7;
  
  iVar6 = 0;
  do {
    iVar3 = param_2 + iVar6 * 0x2c;
    bVar2 = *(byte *)(iVar3 + 0x176);
    if ((bVar2 & 1) == 0) {
      bVar1 = *(float *)(iVar3 + 0x158) == 0.0;
      in_fpscr = in_fpscr & 0xfffffff;
      if (!bVar1) {
        bVar2 = *(byte *)(iVar3 + 0x15e);
      }
      if (bVar1 || (bVar2 & 1) == 0) {
        iVar4 = RandSys::get((RandSys *)&gRand);
        ad::lyt::LytAnim::play
                  ((LytAnim *)(iVar3 + 0x14c),1.0,(short)((uint)(iVar4 * 3) >> 0x10) + 2);
        uVar5 = RandSys::get((RandSys *)&gRand);
        fVar7 = (float)VectorUnsignedToFloat(uVar5,(byte)(in_fpscr >> 0x16) & 3);
        Frm::play((Frm *)(iVar3 + 0x168),fVar7 * 1.5258789e-05 * 60.0 + 180.0);
      }
      else {
        ad::lyt::LytAnim::update((LytAnim *)(iVar3 + 0x14c),param_1);
      }
    }
    else {
      Frm::update(param_1);
    }
    iVar6 = iVar6 + 1;
  } while (iVar6 < 0x16);
  *(undefined1 *)(param_2 + 0x142) = 1;
  return;
}


// FUNC 0x1480c0e4 load_menu::LoadMenuAmiiboPage::Core::StarMan::vfunc_0x38 (LoadMenu)
//   size 0x4 | file LoadMenu+0xc0e4 | callers(0) | datarefs 1

void load_menu::LoadMenuAmiiboPage::Core::StarMan::vfunc_0x38(void)

{
  return;
}


// FUNC 0x1480c0e8 load_menu::LoadMenuAmiiboPage::Core::StarMan::vfunc_0x14 (LoadMenu)
//   size 0x4 | file LoadMenu+0xc0e8 | callers(0) | datarefs 1

void load_menu::LoadMenuAmiiboPage::Core::StarMan::vfunc_0x14(void)

{
  return;
}


// FUNC 0x1480c0ec load_menu::LoadMenuAmiiboPage::Core::StarMan::vfunc_0x4 (LoadMenu)
//   size 0x34 | file LoadMenu+0xc0ec | callers(0) | datarefs 1

void load_menu::LoadMenuAmiiboPage::Core::StarMan::vfunc_0x4(undefined4 *param_1)

{
  void *pvVar1;
  
  *param_1 = &vtable;
  __aeabi_vec_dtor(param_1 + 0x53,&LAB_148091f8,0x2c,0x16);
  pvVar1 = (void *)msys::MChrBase::vfunc_0x0(param_1);
  operator_delete(pvVar1);
  return;
}


// FUNC 0x1480c128 load_menu::LoadMenuAmiiboPage::Core::StarMan::vfunc_0x0 (LoadMenu)
//   size 0x30 | file LoadMenu+0xc128 | callers(0) | datarefs 1

void load_menu::LoadMenuAmiiboPage::Core::StarMan::vfunc_0x0(undefined4 *param_1)

{
  *param_1 = &vtable;
  __aeabi_vec_dtor(param_1 + 0x53,&LAB_148091f8,0x2c,0x16);
  msys::MChrBase::vfunc_0x0(param_1);
  return;
}


// FUNC 0x1480c170 FUN_1480c170 (LoadMenu)
//   size 0x74 | file LoadMenu+0xc170 | callers(0)

void FUN_1480c170(int *param_1)

{
  undefined1 uVar1;
  byte bVar2;
  LytAnim *this;
  
  FUN_14806608(param_1 + 1,*param_1,*param_1 + 0x490,"INS_EFFECT");
  if (*(char *)((int)param_1 + 0x183) == '\0') {
    bVar2 = msys::MLyt::createAnimeAutoSlot
                      ((MLyt *)(*param_1 + 0x490),"AMB_wave","AMB_L_guidance",(char *)0x0);
    *(byte *)((int)param_1 + 0x182) = bVar2;
    this = (LytAnim *)msys::MLyt::getAnim((MLyt *)(*param_1 + 0x490),(ushort)bVar2);
    ad::lyt::LytAnim::stop(this);
    return;
  }
  uVar1 = msys::MLyt::createAnimeAutoSlot
                    ((MLyt *)(*param_1 + 0xe8),"AMB_put","AMB_U_guidance",(char *)0x0);
  *(undefined1 *)((int)param_1 + 0x182) = uVar1;
  return;
}


// FUNC 0x1480c224 FUN_1480c224 (LoadMenu)
//   size 0x254 | file LoadMenu+0xc224 | callers(1) 0x1480b25c

void FUN_1480c224(int *param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  bool bVar5;
  
  uVar2 = ad::nfp::GetState();
  if (*(byte *)((int)param_1 + 0x181) == uVar2) goto switchD_1480c250_default;
  switch(uVar2) {
  case 0:
  case 1:
    iVar3 = ad::nfp::IsConnected();
    if ((iVar3 != 0) || (*(char *)((int)param_1 + 0x183) != '\0')) break;
    bVar5 = (char)param_1[0x61] == '\0';
    cVar1 = '\0';
    if (!bVar5) {
      cVar1 = (char)param_1[0x60];
    }
    if (bVar5 || cVar1 == '\x04') break;
    *(undefined1 *)(param_1 + 0x61) = 0;
    FUN_148067e4(param_1,(char)param_1[0x60]);
    cVar1 = (char)param_1[0x61];
    goto joined_r0x1480c318;
  case 2:
    iVar3 = ad::nfp::IsStopDetection();
    if (iVar3 != 0) {
      uVar4 = param_1[0x56];
      if (uVar4 != 0) {
        bVar5 = *(int *)(uVar4 + 4) == uVar4 + 4;
        if (bVar5) {
          uVar4 = (uint)*(byte *)(uVar4 + 0x172);
        }
        if (!bVar5 || uVar4 != 0) goto LAB_1480c2ac;
      }
      goto LAB_1480c3f8;
    }
    if (1 < *(byte *)(param_1 + 0x60)) {
      FUN_148067e4(param_1,0);
    }
    if (*(char *)((int)param_1 + 0x183) != '\0') break;
    bVar5 = (char)param_1[0x61] == '\x01';
    cVar1 = '\x01';
    if (!bVar5) {
      cVar1 = (char)param_1[0x60];
    }
    if (bVar5 || cVar1 == '\x04') break;
    *(undefined1 *)(param_1 + 0x61) = 1;
    FUN_148067e4(param_1,(char)param_1[0x60]);
    cVar1 = (char)param_1[0x61];
joined_r0x1480c318:
    if (cVar1 != '\0') {
      FUN_14806720(*param_1 + 0x8bc8,0);
    }
    break;
  case 3:
    if ((char)param_1[0x60] != '\x01') {
      if ((*(char *)((int)param_1 + 0x183) == '\0') &&
         ((char)param_1[0x61] != '\x01' && (char)param_1[0x60] != '\x04')) {
        *(undefined1 *)(param_1 + 0x61) = 1;
        FUN_148067e4(param_1,(char)param_1[0x60]);
        if ((char)param_1[0x61] != '\0') {
          FUN_14806720(*param_1 + 0x8bc8,0);
        }
      }
      FUN_148067e4(param_1,2);
    }
    break;
  case 4:
    FUN_14808d08(*param_1,0x11003f,0,0,0);
    uVar4 = param_1[0x56];
    if (uVar4 != 0) {
      bVar5 = *(int *)(uVar4 + 4) != uVar4 + 4;
      if (!bVar5) {
        uVar4 = (uint)*(byte *)(uVar4 + 0x172);
      }
      if (bVar5 || uVar4 != 0) {
LAB_1480c2ac:
        msys::MDfxChr::term((MDfxChr *)(param_1 + 1));
      }
    }
LAB_1480c3f8:
    msys::MLyt::playAnimeFromNo((MLyt *)(*param_1 + 0xe8),3,0,(char *)0x0,(char *)0x0);
    *(undefined1 *)(param_1 + 0x60) = 4;
    break;
  case 5:
  case 6:
    if ((char)param_1[0x60] != '\x01') {
      FUN_148067e4(param_1,3);
    }
  }
switchD_1480c250_default:
  *(char *)((int)param_1 + 0x181) = (char)uVar2;
  return;
}


// FUNC 0x1480c498 FUN_1480c498 (LoadMenu)
//   size 0x104 | file LoadMenu+0xc498 | callers(0) | datarefs 1

void FUN_1480c498(int param_1)

{
  int iVar1;
  IAllocator *pIVar2;
  MemAlcBase *pMVar3;
  int iVar4;
  undefined4 uVar5;
  
  if (((*(int *)(param_1 + 0x20) == 0) &&
      ((*(uint *)(param_1 + 0x24) & 1) == 0 || *(uint *)(param_1 + 0x24) == 0)) &&
     ((iVar1 = ad::nfp::IsValid(), iVar1 == 0 || (iVar1 = ad::nfp::IsInitialized(), iVar1 != 0)))) {
    *(code **)(param_1 + 0x20) = FUN_1480a51c;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
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
            (*(TaskBase **)(iVar4 + 4),(Resource *)(param_1 + 0xa4),
             (FileContext *)(*(int *)(iVar1 + 0x278) + 0xa8),"MENU_FILE_amiibo",pMVar3,0x7f,
             (ResCacheArg *)0x0);
  *(code **)(param_1 + 0x10) = FUN_1480a3b8;
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}


// FUNC 0x1480c5c4 FUN_1480c5c4 (LoadMenu)
//   size 0x88 | file LoadMenu+0xc5c4 | callers(0) | datarefs 6

void FUN_1480c5c4(int param_1)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  
  FUN_148080bc();
  iVar2 = msys::MComSys::_sys;
  iVar1 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar1 = iVar2;
  }
  Backup::init((Backup *)(iVar1 + 0xe9050),(CtrFS *)(*(int *)(iVar1 + 4) + 0x518));
  iVar2 = msys::MComSys::_sys;
  iVar1 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = msys::MComSys::_sys;
    iVar1 = iVar2;
  }
  GameWork::preSaveGameWork((GameWork *)&gGameWork);
  pvVar3 = (void *)Backup::GetSaveData1(-1);
  Mem::Copy(pvVar3,&gGameWork,0x28c0);
  Backup::writeSaveData1((short)iVar1 + -0x6fb0);
  *(code **)(param_1 + 0x20) = FUN_14809874;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


// FUNC 0x1480c658 FUN_1480c658 (LoadMenu)
//   size 0x48 | file LoadMenu+0xc658 | callers(0) | datarefs 1

void FUN_1480c658(int param_1)

{
  if (*(int *)(param_1 + 8) == 0) {
    *(undefined4 *)(param_1 + 8) = msys::MComSys::_sys;
  }
  GameWork::preSaveGameWork((GameWork *)&gGameWork);
  Backup::writeSaveData();
  *(code **)(param_1 + 0x20) = FUN_1480c5c4;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


// FUNC 0x1480c6ac FUN_1480c6ac (LoadMenu)
//   size 0x70 | file LoadMenu+0xc6ac | callers(0) | datarefs 1

void FUN_1480c6ac(int param_1)

{
  FUN_14806a54(param_1 + 0x8bc8);
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0xe8),4,0,(char *)0x0,(char *)0x0);
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x490),2,0,(char *)0x0,(char *)0x0);
  msys::MLyt::playAnimeFromNo((MLyt *)(param_1 + 0x490),3,0,(char *)0x0,(char *)0x0);
  *(code **)(param_1 + 0x18) = FUN_1480acb0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  return;
}


// FUNC 0x1480c720 FUN_1480c720 (LoadMenu)
//   size 0x1c4 | file LoadMenu+0xc720 | callers(1) 0x1480cab0

void FUN_1480c720(void)

{
  undefined1 uVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar2 = (undefined4 *)FUN_1480925c();
  *puVar2 = &load_menu::LoadMenuAmiiboPage::Core::vtable;
  ad::nfp::Initialize(gMemAlc,0);
  puVar2[0x1e69] = puVar2;
  puVar2 = (undefined4 *)msys::MDfxChr::MDfxChr((MDfxChr *)(puVar2 + 0x1e6a));
  *puVar2 = &load_menu::LoadMenuPageBase::Core::Dfx::vtable;
  *(undefined1 *)(puVar2 + 0x5f) = 4;
  *(undefined1 *)((int)puVar2 + 0x17d) = 0;
  uVar1 = nn::os::CTR::IsRunOnSnake();
  *(undefined1 *)((int)puVar2 + 0x17f) = uVar1;
  *(undefined1 *)(puVar2 + 0x60) = 0;
  puVar2 = (undefined4 *)msys::MDfxChr::MDfxChr((MDfxChr *)(puVar2 + 0x61));
  *puVar2 = &load_menu::LoadMenuPageBase::Core::Dfx::vtable;
  puVar2[0x5f] = puVar2 + -0x1ecb;
  iVar3 = __aeabi_vec_ctor_nocookie_nodtor(puVar2 + 0x60,ad::fw::Resource::Resource,0x44,4);
  iVar3 = FUN_1480b8a8(iVar3 + 0x110);
  iVar3 = FUN_1480b8a8(iVar3 + 0x438);
  puVar2 = (undefined4 *)FUN_14808f5c(iVar3 + 0x438);
  *puVar2 = &msys::MCellAnime::vtable;
  iVar3 = CellAnime::CellAnime((CellAnime *)(puVar2 + 0x53));
  *(undefined1 *)(iVar3 + 300) = 0xff;
  *(undefined1 *)(iVar3 + 0x12d) = 0xff;
  *(undefined1 *)(iVar3 + 0x12e) = 0xff;
  *(undefined1 *)(iVar3 + 0x12f) = 0xff;
  puVar2 = (undefined4 *)msys::MDfxChr::MDfxChr((MDfxChr *)(iVar3 + 0x134));
  *puVar2 = &load_menu::LoadMenuPageBase::Core::Dfx::vtable;
  puVar2 = (undefined4 *)msys::MDfxChr::MDfxChr((MDfxChr *)(puVar2 + 0x5f));
  *puVar2 = &load_menu::LoadMenuPageBase::Core::Dfx::vtable;
  puVar2[0x61] = 0;
  puVar2[0x62] = 0x3f800000;
  puVar2[99] = 0;
  *(undefined2 *)(puVar2 + 100) = 1;
  *(undefined2 *)((int)puVar2 + 0x192) = 0;
  puVar2 = (undefined4 *)FUN_14808f5c(puVar2 + 0x69);
  *puVar2 = &msys::MMsg::vtable;
  iVar3 = MessageSimple::MessageSimple((MessageSimple *)(puVar2 + 0x53));
  *(undefined4 *)(iVar3 + 0x6ae0) = 0;
  *(undefined1 *)(iVar3 + 0x6ae4) = 0;
  *(undefined1 *)(iVar3 + 0x6ae5) = 0;
  *(undefined4 *)(iVar3 + 0x6ae8) = 0;
  *(undefined4 *)(iVar3 + 0x6aec) = 0;
  *(undefined4 *)(iVar3 + 0x6af4) = 0x400;
  puVar2 = (undefined4 *)FUN_14808f5c(iVar3 + 0x6af8);
  *puVar2 = &msys::MMsg::vtable;
  iVar3 = MessageSimple::MessageSimple((MessageSimple *)(puVar2 + 0x53));
  *(undefined4 *)(iVar3 + 0x6ae0) = 0;
  *(undefined1 *)(iVar3 + 0x6ae4) = 0;
  *(undefined1 *)(iVar3 + 0x6ae5) = 0;
  *(undefined4 *)(iVar3 + 0x6ae8) = 0;
  *(undefined4 *)(iVar3 + 0x6aec) = 0;
  *(undefined4 *)(iVar3 + 0x6af4) = 0x400;
  puVar2 = (undefined4 *)FUN_14808f5c(iVar3 + 0x6af8);
  *puVar2 = &load_menu::LoadMenuAmiiboPage::Core::StarMan::vtable;
  iVar3 = __aeabi_vec_ctor_nocookie_nodtor(puVar2 + 0x53,&LAB_148091a8,0x2c,0x16);
  *(code **)(iVar3 + -0x16590) = FUN_1480c498;
  *(undefined4 *)(iVar3 + -0x1658c) = 0;
  *(code **)(iVar3 + -0x16588) = FUN_1480c6ac;
  *(undefined4 *)(iVar3 + -0x16584) = 0;
  return;
}


// FUNC 0x1480c910 load_menu::LoadMenuAmiiboPage::Core::vfunc_0x4 (LoadMenu)
//   size 0xc4 | file LoadMenu+0xc910 | callers(0) | datarefs 1

void load_menu::LoadMenuAmiiboPage::Core::vfunc_0x4(undefined4 *param_1)

{
  int iVar1;
  void *pvVar2;
  
  *param_1 = &vtable;
  param_1[0x5915] = &StarMan::vtable;
  __aeabi_vec_dtor(param_1 + 0x5968,&LAB_148091f8,0x2c,0x16);
  iVar1 = msys::MChrBase::vfunc_0x0(param_1 + 0x5915);
  *(undefined ***)(iVar1 + -0x6c44) = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar1 = MessageSimple::~MessageSimple((MessageSimple *)(iVar1 + -0x6af8));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  *(undefined ***)(iVar1 + -0x6c44) = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar1 = MessageSimple::~MessageSimple((MessageSimple *)(iVar1 + -0x6af8));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  iVar1 = FUN_1480be7c(iVar1 + -0xf24);
  iVar1 = msys::MDfxChr::~MDfxChr((MDfxChr *)(iVar1 + -0x17c));
  iVar1 = msys::MDfxChr::~MDfxChr((MDfxChr *)(iVar1 + -0x184));
  ad::nfp::Finalize();
  pvVar2 = (void *)LoadMenuPageBase::Core::vfunc_0x0(iVar1 + -0x79a8);
  operator_delete(pvVar2);
  return;
}


// FUNC 0x1480c9e4 load_menu::LoadMenuAmiiboPage::Core::vfunc_0x0 (LoadMenu)
//   size 0xbc | file LoadMenu+0xc9e4 | callers(0) | datarefs 1

void load_menu::LoadMenuAmiiboPage::Core::vfunc_0x0(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &vtable;
  param_1[0x5915] = &StarMan::vtable;
  __aeabi_vec_dtor(param_1 + 0x5968,&LAB_148091f8,0x2c,0x16);
  iVar1 = msys::MChrBase::vfunc_0x0(param_1 + 0x5915);
  *(undefined ***)(iVar1 + -0x6c44) = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar1 = MessageSimple::~MessageSimple((MessageSimple *)(iVar1 + -0x6af8));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  *(undefined ***)(iVar1 + -0x6c44) = &msys::MMsg::vtable;
  MessageSimple::term();
  iVar1 = MessageSimple::~MessageSimple((MessageSimple *)(iVar1 + -0x6af8));
  iVar1 = msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  iVar1 = FUN_1480be7c(iVar1 + -0xf24);
  iVar1 = msys::MDfxChr::~MDfxChr((MDfxChr *)(iVar1 + -0x17c));
  iVar1 = msys::MDfxChr::~MDfxChr((MDfxChr *)(iVar1 + -0x184));
  ad::nfp::Finalize();
  LoadMenuPageBase::Core::vfunc_0x0(iVar1 + -0x79a8);
  return;
}


// FUNC 0x1480cab0 load_menu::LoadMenuAmiiboPage::vfunc_0x30 (LoadMenu)
//   size 0x30 | file LoadMenu+0xcab0 | callers(0) | datarefs 1

void load_menu::LoadMenuAmiiboPage::vfunc_0x30(int param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(0x1696c,*(MemAlcBase **)(param_1 + 0x18),(char *)0x0,0);
  uVar2 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_1480c720(pvVar1,param_1);
  }
  *(undefined4 *)(param_1 + 0x20) = uVar2;
  return;
}


// FUNC 0x1480cae4 load_menu::LoadMenuAmiiboPage::vfunc_0x24 (LoadMenu)
//   size 0x8 | file LoadMenu+0xcae4 | callers(0) | datarefs 1

undefined4 load_menu::LoadMenuAmiiboPage::vfunc_0x24(void)

{
  return 1;
}


// FUNC 0x1480caec load_menu::LoadMenuAmiiboPage::vfunc_0x4 (LoadMenu)
//   size 0x10 | file LoadMenu+0xcaec | callers(0) | datarefs 1

void load_menu::LoadMenuAmiiboPage::vfunc_0x4(void)

{
  void *pvVar1;
  
  pvVar1 = (void *)LoadMenuPageBase::vfunc_0x0();
  operator_delete(pvVar1);
  return;
}


// FUNC 0x1480cafc ->load_menu::LoadMenuPageBase::vfunc_0x0 (LoadMenu)
//   size 0x4 | file LoadMenu+0xcafc | callers(0) | datarefs 1
// veneer/thunk -> 0x1480815c load_menu::LoadMenuPageBase::vfunc_0x0 (LoadMenu)

// FUNC 0x1480cb00 FUN_1480cb00 (LoadMenu)
//   size 0x23c | file LoadMenu+0xcb00 | callers(1) 0x1480cf38

undefined4 FUN_1480cb00(int param_1,short param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  Resource *__s2;
  int iVar5;
  Resource *pRVar6;
  VramAlcBase *pVVar7;
  uint uVar8;
  KJChrData aKStack_14c [52];
  char acStack_118 [24];
  char acStack_100 [120];
  TransMultiSymbol aTStack_88 [44];
  Resource *local_5c;
  uint *local_58 [2];
  FileContext *local_50;
  char *local_4c;
  TaskBase *local_48;
  undefined4 local_38;
  MemAlcBase *local_2c;
  
  iVar1 = Backup::GetSaveData1(param_2);
LAB_1480cb38:
  uVar2 = (uint)*(byte *)(param_1 + 0xfd100);
  iVar5 = iVar1 + 0x828 + (uint)*(byte *)(iVar1 + 0x2502) * 0x2c;
  if (*(byte *)(iVar5 + 0x2a) <= uVar2) {
    return 1;
  }
  iVar3 = 0;
  do {
    if (*(ushort *)(iVar5 + iVar3 * 4) < *(ushort *)(iVar1 + 0x2500)) {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
    }
    iVar3 = iVar3 + 1;
    if (8 < iVar3) {
      return 1;
    }
  } while( true );
  KJDB::Chr::getData((Chr *)(KJDB::_inst + 8),aKStack_14c,
                     (uint)*(byte *)(iVar1 + 0x828 + *(short *)(iVar5 + iVar3 * 4) * 0x10 + 0x1bc),0
                     ,false);
  if (*(char *)(param_1 + 0xfd100) == '\0') {
    pcVar4 = acStack_118;
  }
  else {
    pcVar4 = acStack_100;
  }
  iVar5 = strcmp(pcVar4,(char *)(param_1 + 0xfcb0c));
  pRVar6 = (Resource *)(param_1 + 0xfcb00);
  while (iVar5 != 0) {
    if (pRVar6[0xc] == (Resource)0x0) {
      iVar5 = ad::fw::TaskBase::isReadable(*(TaskBase **)(param_1 + 4));
      if (iVar5 == 0) {
        return 0;
      }
      if (*(char *)(param_1 + 0xfd100) == '\0') {
        iVar5 = 7;
      }
      else {
        iVar5 = 6;
      }
      local_48 = *(TaskBase **)(param_1 + 4);
      local_2c = (MemAlcBase *)(param_1 + 0xc);
      local_50 = (FileContext *)(*(int *)(param_1 + 0x278) + iVar5 * 0xa8);
      pVVar7 = (VramAlcBase *)0x0;
      uVar2 = 0;
      uVar8 = 0x7f;
      local_38 = *(undefined4 *)(local_50 + 0x24);
      local_5c = pRVar6;
      local_4c = pcVar4;
      ad::TransMultiSymbol::init(aTStack_88,pcVar4);
      BinGlu4Acs::getEntryAcs((char *)local_58);
      pcVar4 = (char *)(*(int *)(local_50 + 0x24) + (*local_58[0] & 0x3fffffff));
      ad::fw::TaskBase::readCA
                (local_48,local_5c,local_50,local_4c,pcVar4,pcVar4 + 4,pcVar4 + 8,pcVar4 + 0xc,
                 local_2c,uVar8,pVVar7,uVar2,(ResCacheArg *)0x0);
      break;
    }
    __s2 = pRVar6 + 0x50;
    pRVar6 = pRVar6 + 0x44;
    iVar5 = strcmp(pcVar4,(char *)__s2);
  }
  *(int *)(param_1 + 0xfd100) = *(int *)(param_1 + 0xfd100) + 1;
  goto LAB_1480cb38;
}


// FUNC 0x1480cd44 FUN_1480cd44 (LoadMenu)
//   size 0xf0 | file LoadMenu+0xcd44 | callers(0) | datarefs 1

void FUN_1480cd44(SaveLoadSys *param_1)

{
  SaveLoadSys SVar1;
  int iVar2;
  uint uVar3;
  TaskBase *pTVar4;
  char *pcVar5;
  SaveLoadSys *pSVar6;
  void *pvVar7;
  int iVar8;
  char *pcVar9;
  uint in_r12;
  bool bVar10;
  TransMultiSymbol aTStack_d0 [44];
  TransMultiSymbol aTStack_a4 [44];
  TransMultiSymbol aTStack_78 [44];
  undefined4 uStack_4c;
  uint *apuStack_48 [2];
  uint *apuStack_40 [2];
  uint *apuStack_38 [2];
  undefined4 uStack_30;
  undefined4 uStack_2c;
  SaveLoadSys *pSStack_28;
  
  iVar2 = *(int *)(param_1 + 0x278);
  iVar8 = iVar2;
  while( true ) {
    bVar10 = iVar8 != iVar2 + 0x5e8;
    if (bVar10) {
      in_r12 = (uint)*(byte *)(iVar8 + 4);
    }
    if (!bVar10 || in_r12 == 0) break;
    iVar8 = iVar8 + 0xa8;
  }
  if (iVar8 != iVar2 + 0x5e8) {
    return;
  }
  save_load::SaveLoadSys::funcCalcLoadData(param_1);
  (**(code **)(**(int **)(*(int *)(param_1 + 0xe64f0) + 0x44) + 0xc))
            (*(int **)(*(int *)(param_1 + 0xe64f0) + 0x44),"MDFXMenuArchive");
  *(code **)(param_1 + 0xf84) = FUN_1480cf38;
  *(undefined4 *)(param_1 + 0xf88) = 0;
  iVar8 = ad::fw::TaskBase::isReadable(*(TaskBase **)(param_1 + 4));
  if (iVar8 == 0) {
    return;
  }
  ad::fw::TaskBase::readArcFile
            (*(TaskBase **)(param_1 + 4),(Resource *)(param_1 + 0xfd050),
             (FileContext *)(*(int *)(param_1 + 0x278) + 0x540),"b_sys",
             (MemAlcBase *)(param_1 + 0xc),0,(ResCacheArg *)0x0);
  *(undefined4 *)(param_1 + 0xf84) = 0x1480cfc4;
  *(undefined4 *)(param_1 + 0xf88) = 0;
  *(undefined4 *)(param_1 + 0xfd100) = 0;
  uVar3 = *(uint *)(param_1 + 0xfd100) & 0xff00;
  if (uVar3 == 0x200) {
LAB_1480d1f4:
    do {
      iVar8 = ad::fw::TaskBase::isReadable(*(TaskBase **)(param_1 + 4));
      if (iVar8 == 0) {
        return;
      }
      SVar1 = param_1[0xfd100];
      pTVar4 = *(TaskBase **)(param_1 + 4);
      iVar8 = *(int *)(param_1 + 0x278);
      pSStack_28 = param_1 + 0xc;
      pcVar9 = *(char **)(&DAT_14817568 + (uint)(byte)SVar1 * 4);
      uStack_2c = *(undefined4 *)(iVar8 + 0x36c);
      ad::TransMultiSymbol::init(aTStack_78,pcVar9);
      BinGlu4Acs::getEntryAcs((char *)apuStack_48);
      pcVar5 = (char *)(*(int *)(iVar8 + 0x36c) + (*apuStack_48[0] & 0x3fffffff));
      ad::fw::TaskBase::readCA
                (pTVar4,(Resource *)(param_1 + (uint)(byte)SVar1 * 0x44 + 0xfcfc8),
                 (FileContext *)(iVar8 + 0x348),pcVar9,pcVar5,pcVar5 + 4,pcVar5 + 8,pcVar5 + 0xc,
                 (MemAlcBase *)pSStack_28,0x7f,(VramAlcBase *)0x0,0,(ResCacheArg *)0x0);
      iVar8 = *(int *)(param_1 + 0xfd100);
      *(uint *)(param_1 + 0xfd100) = iVar8 + 1U;
    } while ((iVar8 + 1U & 0xff) < 2);
    *(undefined4 *)(param_1 + 0xfd100) = 0x300;
LAB_1480d2e8:
    iVar8 = FUN_1480cb00(param_1,0);
    if (iVar8 == 0) {
      return;
    }
    *(undefined4 *)(param_1 + 0xfd100) = 0x400;
  }
  else {
    if (uVar3 < 0x201) {
      if (uVar3 == 0) {
        do {
          iVar8 = ad::fw::TaskBase::isReadable(*(TaskBase **)(param_1 + 4));
          if (iVar8 == 0) {
            return;
          }
          SVar1 = param_1[0xfd100];
          pTVar4 = *(TaskBase **)(param_1 + 4);
          iVar8 = *(int *)(param_1 + 0x278);
          pSStack_28 = param_1 + 0xc;
          pcVar9 = *(char **)(&DAT_14817560 + (uint)(byte)SVar1 * 4);
          uStack_4c = *(undefined4 *)(iVar8 + 0x414);
          ad::TransMultiSymbol::init(aTStack_a4,pcVar9);
          BinGlu4Acs::getEntryAcs((char *)apuStack_38);
          pcVar5 = (char *)((*apuStack_38[0] & 0x3fffffff) + *(int *)(iVar8 + 0x414));
          ad::fw::TaskBase::readCA
                    (pTVar4,(Resource *)(param_1 + (uint)(byte)SVar1 * 0x44 + 0xfca34),
                     (FileContext *)(iVar8 + 0x3f0),pcVar9,pcVar5,pcVar5 + 4,pcVar5 + 8,pcVar5 + 0xc
                     ,(MemAlcBase *)pSStack_28,0x7f,(VramAlcBase *)0x0,0,(ResCacheArg *)0x0);
          iVar8 = *(int *)(param_1 + 0xfd100);
          *(uint *)(param_1 + 0xfd100) = iVar8 + 1U;
        } while ((iVar8 + 1U & 0xff) < 2);
        *(undefined4 *)(param_1 + 0xfd100) = 0x100;
      }
      else if (uVar3 != 0x100) goto LAB_1480d31c;
      do {
        iVar8 = ad::fw::TaskBase::isReadable(*(TaskBase **)(param_1 + 4));
        if (iVar8 == 0) {
          return;
        }
        SVar1 = param_1[0xfd100];
        pTVar4 = *(TaskBase **)(param_1 + 4);
        iVar8 = *(int *)(param_1 + 0x278);
        pSStack_28 = param_1 + 0xc;
        pcVar9 = *(char **)(&DAT_1481753c + (uint)(byte)SVar1 * 4);
        uStack_30 = *(undefined4 *)(iVar8 + 0x4bc);
        ad::TransMultiSymbol::init(aTStack_d0,pcVar9);
        BinGlu4Acs::getEntryAcs((char *)apuStack_40);
        pcVar5 = (char *)((*apuStack_40[0] & 0x3fffffff) + *(int *)(iVar8 + 0x4bc));
        ad::fw::TaskBase::readCA
                  (pTVar4,(Resource *)(param_1 + (uint)(byte)SVar1 * 0x44 + 0xfcabc),
                   (FileContext *)(iVar8 + 0x498),pcVar9,pcVar5,pcVar5 + 4,pcVar5 + 8,pcVar5 + 0xc,
                   (MemAlcBase *)pSStack_28,0x7f,(VramAlcBase *)0x0,0,(ResCacheArg *)0x0);
        iVar8 = *(int *)(param_1 + 0xfd100);
        *(uint *)(param_1 + 0xfd100) = iVar8 + 1U;
      } while ((iVar8 + 1U & 0xff) == 0);
      *(undefined4 *)(param_1 + 0xfd100) = 0x200;
      goto LAB_1480d1f4;
    }
    if (uVar3 == 0x300) goto LAB_1480d2e8;
    if (uVar3 != 0x400) goto LAB_1480d31c;
  }
  iVar8 = FUN_1480cb00(param_1,1);
  if (iVar8 == 0) {
    return;
  }
LAB_1480d31c:
  *(code **)(param_1 + 0xf84) = FUN_1480ce54;
  *(undefined4 *)(param_1 + 0xf88) = 0;
  if ((param_1[0xfbaf0] != (SaveLoadSys)0x0) &&
     (iVar8 = (**(code **)(**(int **)(*(int *)(param_1 + 0xe64f0) + 0x44) + 0x10))(), iVar8 == 0)) {
    for (pSVar6 = param_1 + 0xfcf84; pSVar6[0xc] == (SaveLoadSys)0x0; pSVar6 = pSVar6 + -0x44) {
    }
    if ((pSVar6[4] != (SaveLoadSys)0x0) && (param_1[0xfd054] != (SaveLoadSys)0x0)) {
      pvVar7 = (void *)ad::fw::Resource::getFileData((Resource *)(param_1 + 0xfd050));
      MsgDataAcsrBase::init((MsgDataAcsrBase *)(param_1 + 0xfd094),pvVar7);
      save_load::SaveLoadSys::funcCalcCreateChr(param_1);
      msys::MLytNumRes::init((MLytNumRes *)(param_1 + 0x844),(LytResourceMan *)(param_1 + 2000),5);
      iVar8 = msys::MLyt::getPane((MLyt *)(param_1 + 0xfbbfc),s_MAP_ALL_148176c9,(char *)0x0,
                                  (char *)0x0);
      *(byte *)(iVar8 + 0x44) = *(byte *)(iVar8 + 0x44) & 0xfe;
    }
  }
  return;
}


// FUNC 0x1480ce54 FUN_1480ce54 (LoadMenu)
//   size 0xd0 | file LoadMenu+0xce54 | callers(0) | datarefs 1

void FUN_1480ce54(SaveLoadSys *param_1)

{
  int iVar1;
  SaveLoadSys *pSVar2;
  void *pvVar3;
  
  if ((param_1[0xfbaf0] != (SaveLoadSys)0x0) &&
     (iVar1 = (**(code **)(**(int **)(*(int *)(param_1 + 0xe64f0) + 0x44) + 0x10))(), iVar1 == 0)) {
    for (pSVar2 = param_1 + 0xfcf84; pSVar2[0xc] == (SaveLoadSys)0x0; pSVar2 = pSVar2 + -0x44) {
    }
    if ((pSVar2[4] != (SaveLoadSys)0x0) && (param_1[0xfd054] != (SaveLoadSys)0x0)) {
      pvVar3 = (void *)ad::fw::Resource::getFileData((Resource *)(param_1 + 0xfd050));
      MsgDataAcsrBase::init((MsgDataAcsrBase *)(param_1 + 0xfd094),pvVar3);
      save_load::SaveLoadSys::funcCalcCreateChr(param_1);
      msys::MLytNumRes::init((MLytNumRes *)(param_1 + 0x844),(LytResourceMan *)(param_1 + 2000),5);
      iVar1 = msys::MLyt::getPane((MLyt *)(param_1 + 0xfbbfc),s_MAP_ALL_148176c9,(char *)0x0,
                                  (char *)0x0);
      *(byte *)(iVar1 + 0x44) = *(byte *)(iVar1 + 0x44) & 0xfe;
    }
  }
  return;
}


// FUNC 0x1480cf38 FUN_1480cf38 (LoadMenu)
//   size 0x4b8 | file LoadMenu+0xcf38 | callers(0) | datarefs 1

void FUN_1480cf38(SaveLoadSys *param_1)

{
  SaveLoadSys SVar1;
  int iVar2;
  uint uVar3;
  TaskBase *pTVar4;
  char *pcVar5;
  SaveLoadSys *pSVar6;
  void *pvVar7;
  char *pcVar8;
  TransMultiSymbol aTStack_d0 [44];
  TransMultiSymbol aTStack_a4 [44];
  TransMultiSymbol aTStack_78 [44];
  undefined4 local_4c;
  uint *local_48 [2];
  uint *local_40 [2];
  uint *local_38 [2];
  undefined4 local_30;
  undefined4 local_2c;
  SaveLoadSys *local_28;
  
  iVar2 = ad::fw::TaskBase::isReadable(*(TaskBase **)(param_1 + 4));
  if (iVar2 == 0) {
    return;
  }
  ad::fw::TaskBase::readArcFile
            (*(TaskBase **)(param_1 + 4),(Resource *)(param_1 + 0xfd050),
             (FileContext *)(*(int *)(param_1 + 0x278) + 0x540),"b_sys",
             (MemAlcBase *)(param_1 + 0xc),0,(ResCacheArg *)0x0);
  *(undefined4 *)(param_1 + 0xf84) = 0x1480cfc4;
  *(undefined4 *)(param_1 + 0xf88) = 0;
  *(undefined4 *)(param_1 + 0xfd100) = 0;
  uVar3 = *(uint *)(param_1 + 0xfd100) & 0xff00;
  if (uVar3 == 0x200) {
LAB_1480d1f4:
    do {
      iVar2 = ad::fw::TaskBase::isReadable(*(TaskBase **)(param_1 + 4));
      if (iVar2 == 0) {
        return;
      }
      SVar1 = param_1[0xfd100];
      pTVar4 = *(TaskBase **)(param_1 + 4);
      iVar2 = *(int *)(param_1 + 0x278);
      local_28 = param_1 + 0xc;
      pcVar8 = *(char **)(&DAT_14817568 + (uint)(byte)SVar1 * 4);
      local_2c = *(undefined4 *)(iVar2 + 0x36c);
      ad::TransMultiSymbol::init(aTStack_78,pcVar8);
      BinGlu4Acs::getEntryAcs((char *)local_48);
      pcVar5 = (char *)(*(int *)(iVar2 + 0x36c) + (*local_48[0] & 0x3fffffff));
      ad::fw::TaskBase::readCA
                (pTVar4,(Resource *)(param_1 + (uint)(byte)SVar1 * 0x44 + 0xfcfc8),
                 (FileContext *)(iVar2 + 0x348),pcVar8,pcVar5,pcVar5 + 4,pcVar5 + 8,pcVar5 + 0xc,
                 (MemAlcBase *)local_28,0x7f,(VramAlcBase *)0x0,0,(ResCacheArg *)0x0);
      iVar2 = *(int *)(param_1 + 0xfd100);
      *(uint *)(param_1 + 0xfd100) = iVar2 + 1U;
    } while ((iVar2 + 1U & 0xff) < 2);
    *(undefined4 *)(param_1 + 0xfd100) = 0x300;
LAB_1480d2e8:
    iVar2 = FUN_1480cb00(param_1,0);
    if (iVar2 == 0) {
      return;
    }
    *(undefined4 *)(param_1 + 0xfd100) = 0x400;
  }
  else {
    if (uVar3 < 0x201) {
      if (uVar3 == 0) {
        do {
          iVar2 = ad::fw::TaskBase::isReadable(*(TaskBase **)(param_1 + 4));
          if (iVar2 == 0) {
            return;
          }
          SVar1 = param_1[0xfd100];
          pTVar4 = *(TaskBase **)(param_1 + 4);
          iVar2 = *(int *)(param_1 + 0x278);
          local_28 = param_1 + 0xc;
          pcVar8 = *(char **)(&DAT_14817560 + (uint)(byte)SVar1 * 4);
          local_4c = *(undefined4 *)(iVar2 + 0x414);
          ad::TransMultiSymbol::init(aTStack_a4,pcVar8);
          BinGlu4Acs::getEntryAcs((char *)local_38);
          pcVar5 = (char *)((*local_38[0] & 0x3fffffff) + *(int *)(iVar2 + 0x414));
          ad::fw::TaskBase::readCA
                    (pTVar4,(Resource *)(param_1 + (uint)(byte)SVar1 * 0x44 + 0xfca34),
                     (FileContext *)(iVar2 + 0x3f0),pcVar8,pcVar5,pcVar5 + 4,pcVar5 + 8,pcVar5 + 0xc
                     ,(MemAlcBase *)local_28,0x7f,(VramAlcBase *)0x0,0,(ResCacheArg *)0x0);
          iVar2 = *(int *)(param_1 + 0xfd100);
          *(uint *)(param_1 + 0xfd100) = iVar2 + 1U;
        } while ((iVar2 + 1U & 0xff) < 2);
        *(undefined4 *)(param_1 + 0xfd100) = 0x100;
      }
      else if (uVar3 != 0x100) goto LAB_1480d31c;
      do {
        iVar2 = ad::fw::TaskBase::isReadable(*(TaskBase **)(param_1 + 4));
        if (iVar2 == 0) {
          return;
        }
        SVar1 = param_1[0xfd100];
        pTVar4 = *(TaskBase **)(param_1 + 4);
        iVar2 = *(int *)(param_1 + 0x278);
        local_28 = param_1 + 0xc;
        pcVar8 = *(char **)(&DAT_1481753c + (uint)(byte)SVar1 * 4);
        local_30 = *(undefined4 *)(iVar2 + 0x4bc);
        ad::TransMultiSymbol::init(aTStack_d0,pcVar8);
        BinGlu4Acs::getEntryAcs((char *)local_40);
        pcVar5 = (char *)((*local_40[0] & 0x3fffffff) + *(int *)(iVar2 + 0x4bc));
        ad::fw::TaskBase::readCA
                  (pTVar4,(Resource *)(param_1 + (uint)(byte)SVar1 * 0x44 + 0xfcabc),
                   (FileContext *)(iVar2 + 0x498),pcVar8,pcVar5,pcVar5 + 4,pcVar5 + 8,pcVar5 + 0xc,
                   (MemAlcBase *)local_28,0x7f,(VramAlcBase *)0x0,0,(ResCacheArg *)0x0);
        iVar2 = *(int *)(param_1 + 0xfd100);
        *(uint *)(param_1 + 0xfd100) = iVar2 + 1U;
      } while ((iVar2 + 1U & 0xff) == 0);
      *(undefined4 *)(param_1 + 0xfd100) = 0x200;
      goto LAB_1480d1f4;
    }
    if (uVar3 == 0x300) goto LAB_1480d2e8;
    if (uVar3 != 0x400) goto LAB_1480d31c;
  }
  iVar2 = FUN_1480cb00(param_1,1);
  if (iVar2 == 0) {
    return;
  }
LAB_1480d31c:
  *(code **)(param_1 + 0xf84) = FUN_1480ce54;
  *(undefined4 *)(param_1 + 0xf88) = 0;
  if ((param_1[0xfbaf0] != (SaveLoadSys)0x0) &&
     (iVar2 = (**(code **)(**(int **)(*(int *)(param_1 + 0xe64f0) + 0x44) + 0x10))(), iVar2 == 0)) {
    for (pSVar6 = param_1 + 0xfcf84; pSVar6[0xc] == (SaveLoadSys)0x0; pSVar6 = pSVar6 + -0x44) {
    }
    if ((pSVar6[4] != (SaveLoadSys)0x0) && (param_1[0xfd054] != (SaveLoadSys)0x0)) {
      pvVar7 = (void *)ad::fw::Resource::getFileData((Resource *)(param_1 + 0xfd050));
      MsgDataAcsrBase::init((MsgDataAcsrBase *)(param_1 + 0xfd094),pvVar7);
      save_load::SaveLoadSys::funcCalcCreateChr(param_1);
      msys::MLytNumRes::init((MLytNumRes *)(param_1 + 0x844),(LytResourceMan *)(param_1 + 2000),5);
      iVar2 = msys::MLyt::getPane((MLyt *)(param_1 + 0xfbbfc),s_MAP_ALL_148176c9,(char *)0x0,
                                  (char *)0x0);
      *(byte *)(iVar2 + 0x44) = *(byte *)(iVar2 + 0x44) & 0xfe;
    }
  }
  return;
}


// FUNC 0x1480d430 FUN_1480d430 (LoadMenu)
//   size 0x18c | file LoadMenu+0xd430 | callers(1) 0x14801b50

void FUN_1480d430(MComSys *param_1,MTaskBase *param_2)

{
  Job *pJVar1;
  undefined4 uVar2;
  
  msys::MComSys::initBaseSys
            (param_1,param_2,0x600000,0x400000,0x400000,0x100000,0x180000,9,'\0',false);
  SndSys::start((SndSys *)&gSndSys,0x100032a,(SoundHandle *)&gSndSys);
  msys::MComSys::entryPage(param_1,(MPageBase *)(param_1 + 0xfc9ec));
  msys::MComSys::entryPage(param_1,(MPageBase *)(param_1 + 0xfca10));
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
    *(undefined **)(pJVar1 + 0x10) = &DAT_1480e4d8;
    *(undefined4 *)(pJVar1 + 0x14) = 9;
    uVar2 = *(undefined4 *)(param_2 + 0x4d8);
    *(undefined4 *)(pJVar1 + 0x18) = *(undefined4 *)(param_2 + 0x4d4);
    *(undefined4 *)(pJVar1 + 0x1c) = uVar2;
  }
  CtrJobMan::enqueue((CtrJobMan *)(param_2 + 0x4dc),pJVar1);
  *(code **)(param_1 + 0xf84) = FUN_1480cd44;
  *(undefined4 *)(param_1 + 0xf88) = 0;
  msys::MComSys::setupCamU(param_1);
  msys::MComSys::setupCamL(param_1);
  param_1[0x4ad85] = (MComSys)0x1;
  param_1[0x4ae65] = (MComSys)0x1;
  return;
}


// FUNC 0x1480d5e8 FUN_1480d5e8 (LoadMenu)
//   size 0x100 | file LoadMenu+0xd5e8 | callers(1) 0x14801b50

undefined4 * FUN_1480d5e8(SaveLoadSys *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)save_load::SaveLoadSys::SaveLoadSys(param_1);
  *puVar1 = &load_menu::LoadMenu::vtable;
  puVar1[0x3f27c] = puVar1 + 0x3f27c;
  puVar1[0x3f27d] = puVar1 + 0x3f27c;
  puVar1[0x3f27e] = puVar1 + 0x3f27e;
  puVar1[0x3f27f] = puVar1 + 0x3f27e;
  *(undefined1 *)(puVar1 + 0x3f280) = 0;
  puVar1[0x3f281] = 0;
  puVar1[0x3f282] = 0;
  puVar1[0x3f27b] = &load_menu::LoadMenuTopPage::vtable;
  puVar1[0x3f283] = 0;
  puVar1[0x3f285] = puVar1 + 0x3f285;
  puVar1[0x3f286] = puVar1 + 0x3f285;
  puVar1[0x3f287] = puVar1 + 0x3f287;
  puVar1[0x3f288] = puVar1 + 0x3f287;
  *(undefined1 *)(puVar1 + 0x3f289) = 0;
  puVar1[0x3f28a] = 0;
  puVar1[0x3f28b] = 0;
  puVar1[0x3f284] = &load_menu::LoadMenuAmiiboPage::vtable;
  puVar1[0x3f28c] = 0;
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(puVar1 + 0x3f28d,ad::fw::Resource::Resource,0x44,0x15);
  iVar2 = __aeabi_vec_ctor_nocookie_nodtor(iVar2 + 0x594,ad::fw::Resource::Resource,0x44,2);
  iVar2 = ad::fw::Resource::Resource((Resource *)(iVar2 + 0x88));
  puVar1 = (undefined4 *)
           MsgDataAcsrBase::MsgDataAcsrBase
                     ((MsgDataAcsrBase *)(iVar2 + 0x44),(LMSBlockInfo *)(iVar2 + 0x70),4);
  *puVar1 = &vtable_for_20MsgDataAcsrTmplFixedILh4EE;
  KJDB::Create();
  return puVar1 + -0x3f425;
}


// FUNC 0x1480d710 load_menu::LoadMenu::vfunc_0x4 (LoadMenu)
//   size 0x10 | file LoadMenu+0xd710 | callers(0) | datarefs 1

void load_menu::LoadMenu::vfunc_0x4(void)

{
  void *pvVar1;
  
  pvVar1 = (void *)vfunc_0x0();
  operator_delete(pvVar1);
  return;
}


// FUNC 0x1480d720 load_menu::LoadMenu::vfunc_0x0 (LoadMenu)
//   size 0xfc | file LoadMenu+0xd720 | callers(3) 0x14801b8c 0x14801bb4 0x1480d710 | datarefs 1

void load_menu::LoadMenu::vfunc_0x0(undefined4 *param_1)

{
  char *pcVar1;
  int iVar2;
  
  *param_1 = &vtable;
  SndSys::stop((SndSys *)&gSndSys,(SoundHandle *)&gSndSys,0x10);
  iVar2 = 0;
  do {
    ad::fw::Resource::term((Resource *)(param_1 + iVar2 * 0x11 + 0x3f28d));
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x15);
  iVar2 = 0;
  do {
    ad::fw::Resource::term((Resource *)(param_1 + iVar2 * 0x11 + 0x3f3f2));
    iVar2 = iVar2 + 1;
  } while (iVar2 < 2);
  ad::fw::Resource::term((Resource *)(param_1 + 0x3f414));
  pcVar1 = (char *)GameMain::NowInfo();
  if (*pcVar1 != '\x02') {
    KJDB::Destroy();
  }
  iVar2 = MsgDataAcsrBase::~MsgDataAcsrBase((MsgDataAcsrBase *)(param_1 + 0x3f425));
  iVar2 = ad::fw::Resource::~Resource((Resource *)(iVar2 + -0x44));
  __aeabi_vec_dtor(iVar2 + -0x88,ad::fw::Resource::~Resource,0x44,2);
  __aeabi_vec_dtor(iVar2 + -0x61c,ad::fw::Resource::~Resource,0x44,0x15);
  iVar2 = LoadMenuPageBase::vfunc_0x0(iVar2 + -0x640);
  iVar2 = LoadMenuPageBase::vfunc_0x0(iVar2 + -0x24);
  save_load::SaveLoadSys::~SaveLoadSys((SaveLoadSys *)(iVar2 + -0xfc9ec));
  return;
}


// FUNC 0x1480d834 save_load::MsgWnd::vfunc_0x4 (LoadMenu)
//   size 0x30 | file LoadMenu+0xd834 | callers(0) | datarefs 1

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


// FUNC 0x1480d868 save_load::MsgWnd::vfunc_0x0 (LoadMenu)
//   size 0x2c | file LoadMenu+0xd868 | callers(0) | datarefs 1

void save_load::MsgWnd::vfunc_0x0(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &msys::MMsgWnd::vtable;
  Message::term((Message *)(param_1 + 0x53));
  iVar1 = Message::~Message((Message *)(param_1 + 0x53));
  msys::MChrBase::vfunc_0x0(iVar1 + -0x14c);
  return;
}


// FUNC 0x1480d90c FUN_1480d90c (LoadMenu)
//   size 0x2c | file LoadMenu+0xd90c | callers(0) | datarefs 1

bool FUN_1480d90c(int *param_1,uint param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 8))();
  return (uVar1 & param_3) == param_2;
}


// FUNC 0x1480d938 FUN_1480d938 (LoadMenu)
//   size 0x8 | file LoadMenu+0xd938 | callers(0) | datarefs 1

undefined4 FUN_1480d938(void)

{
  return 0;
}


// FUNC 0x1480d940 load_menu::LoadMenuTopPage::Core::SaveGameInfo::FilePanelKJ::KJObj::vfunc_0x1c (LoadMenu)
//   size 0x8 | file LoadMenu+0xd940 | callers(0) | datarefs 1

undefined4 load_menu::LoadMenuTopPage::Core::SaveGameInfo::FilePanelKJ::KJObj::vfunc_0x1c(void)

{
  return 0;
}


// FUNC 0x1480d948 load_menu::LoadMenuTopPage::Core::GameSelectU::vfunc_0x1c (LoadMenu)
//   size 0x8 | file LoadMenu+0xd948 | callers(0) | datarefs 1

undefined4 load_menu::LoadMenuTopPage::Core::GameSelectU::vfunc_0x1c(void)

{
  return 7;
}


// FUNC 0x1480d950 load_menu::LoadMenuAmiiboPage::Core::ItemMan::CAChr::vfunc_0x1c (LoadMenu)
//   size 0x8 | file LoadMenu+0xd950 | callers(0) | datarefs 1

undefined4 load_menu::LoadMenuAmiiboPage::Core::ItemMan::CAChr::vfunc_0x1c(void)

{
  return 6;
}


// FUNC 0x1480d958 load_menu::LoadMenuPageBase::Core::Dfx::vfunc_0x1c (LoadMenu)
//   size 0x8 | file LoadMenu+0xd958 | callers(0) | datarefs 1

undefined4 load_menu::LoadMenuPageBase::Core::Dfx::vfunc_0x1c(void)

{
  return 9;
}


// FUNC 0x1480d960 save_load::MsgWnd::vfunc_0x1c (LoadMenu)
//   size 0x8 | file LoadMenu+0xd960 | callers(0) | datarefs 1

undefined4 save_load::MsgWnd::vfunc_0x1c(void)

{
  return 7;
}


// FUNC 0x1480d968 load_menu::LoadMenuAmiiboPage::Core::StarMan::vfunc_0x1c (LoadMenu)
//   size 0x8 | file LoadMenu+0xd968 | callers(0) | datarefs 1

undefined4 load_menu::LoadMenuAmiiboPage::Core::StarMan::vfunc_0x1c(void)

{
  return 10;
}


// FUNC 0x1480d970 FUN_1480d970 (LoadMenu)
//   size 0x1c | file LoadMenu+0xd970 | callers(1) 0x1480925c

void FUN_1480d970(uint *param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = param_2 & 0xff | (param_2 & 0xff) << 8;
  uVar1 = uVar1 | uVar1 << 0x10;
  *param_1 = uVar1;
  param_1[1] = uVar1;
  param_1[2] = uVar1;
  return;
}


// FUNC 0x1480d998 LoadMenu::nnroControlObject_ (LoadMenu)
//   size 0x74 | file LoadMenu+0xd998 | callers(0)

undefined4 LoadMenu::nnroControlObject_(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined *puVar2;
  
  switch(param_2) {
  case 0:
    uVar1 = 0;
    break;
  case 1:
    DAT_14817688 = param_1;
    return 0;
  case 2:
    uVar1 = DAT_14817688;
    break;
  case 3:
    *param_1 = &DAT_1480db34;
    puVar2 = &DAT_1480db38;
    goto LAB_1480d9f8;
  case 4:
    *param_1 = &DAT_1480f9b4;
    puVar2 = &DAT_1480f9b4;
LAB_1480d9f8:
    param_1[1] = puVar2;
    return 0;
  default:
    return 0xd8e12c21;
  }
  *param_1 = uVar1;
  return 0;
}


// FUNC 0x1480da44 FUN_1480da44 (LoadMenu)
//   size 0xac | file LoadMenu+0xda44 | callers(0) | datarefs 1

void FUN_1480da44(int param_1)

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


// FUNC 0x1480daf0 ->operator.delete (LoadMenu)
//   size 0x4 | file LoadMenu+0xdaf0 | callers(0) | datarefs 1
// veneer/thunk -> 0x00286514 operator.delete (static)

// FUNC 0x1480daf4 FUN_1480daf4 (LoadMenu)
//   size 0x4 | file LoadMenu+0xdaf4 | callers(0) | datarefs 1

void FUN_1480daf4(void)

{
  return;
}


// FUNC 0x1480daf8 FUN_1480daf8 (LoadMenu)
//   size 0x28 | file LoadMenu+0xdaf8 | callers(0) | datarefs 1

void FUN_1480daf8(float param_1,MCursorBase *param_2,MLyt *param_3)

{
  MCursorBase *pMVar1;
  int iVar2;
  
  msys::MCursorBase::init(param_2,param_3,param_1);
  iVar2 = 0xe;
  pMVar1 = param_2 + 0x30;
  do {
    iVar2 = iVar2 + -1;
    *(undefined4 *)pMVar1 = 0;
    pMVar1 = pMVar1 + 4;
  } while (iVar2 != 0);
  return;
}


// FUNC 0x1480db20 FUN_1480db20 (LoadMenu)
//   size 0x10 | file LoadMenu+0xdb20 | callers(0) | datarefs 1

void FUN_1480db20(MCursorBase *param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)msys::MCursorBase::~MCursorBase(param_1);
  operator_delete(pvVar1);
  return;
}


// FUNC 0x1480db30 ->msys::MCursorBase::~MCursorBase (LoadMenu)
//   size 0x4 | file LoadMenu+0xdb30 | callers(0) | datarefs 1
// veneer/thunk -> 0x00324600 msys::MCursorBase::~MCursorBase (static)

