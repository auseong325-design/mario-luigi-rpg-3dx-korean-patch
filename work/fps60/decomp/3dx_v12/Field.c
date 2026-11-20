// fps60 TG decompiled C: 3dx_v12.code.bin module Field part 1 (Ghidra 12.2, ARM:LE:32:v6:hardfp)
// Addresses: static = runtime address; CRO = fixed analysis base (crolink.py), NOT runtime.

// FUNC 0x12000180 ->operator.new (Field)
//   size 0x4 | file Field+0x180 | callers(1) 0x12000240
// veneer/thunk -> 0x00287d40 operator.new (static)

// FUNC 0x12000188 ->operator.delete (Field)
//   size 0x4 | file Field+0x188 | callers(4) 0x12000280 0x120003a8 0x1200032c 0x12000e44
// veneer/thunk -> 0x00286514 operator.delete (static)

// FUNC 0x12000190 ->nn::fs::detail::FileBase::TrySetPosition (Field)
//   size 0x4 | file Field+0x190 | callers(2) 0x12000288 0x120002ac
// veneer/thunk -> 0x0027ec28 nn::fs::detail::FileBase::TrySetPosition (static)

// FUNC 0x12000198 ->nn::err::CTR::ThrowFatalErrAll (Field)
//   size 0x4 | file Field+0x198 | callers(5) 0x120002b4 0x120003a8 0x12000fd4 0x12000288 0x120002e0
// veneer/thunk -> 0x00286530 nn::err::CTR::ThrowFatalErrAll (static)

// FUNC 0x120001a0 ->nn::fs::detail::FileBase::TryRead (Field)
//   size 0x4 | file Field+0x1a0 | callers(3) 0x120002b4 0x120003a8 0x1200030c
// veneer/thunk -> 0x00286488 nn::fs::detail::FileBase::TryRead (static)

// FUNC 0x120001a8 ->nn::fs::detail::FileBase::TrySeek (Field)
//   size 0x4 | file Field+0x1a8 | callers(3) 0x120002e0 0x12000314 0x120003a8
// veneer/thunk -> 0x002854d0 nn::fs::detail::FileBase::TrySeek (static)

// FUNC 0x120001b0 ->nndbgPanic (Field)
//   size 0x4 | file Field+0x1b0 | callers(3) 0x1200032c 0x1200036c 0x120003a8
// veneer/thunk -> 0x0028642c nndbgPanic (static)

// FUNC 0x120001b8 ->nn::fs::CTR::MPCore::detail::UserFileSystem::CloseFile (Field)
//   size 0x4 | file Field+0x1b8 | callers(3) 0x1200032c 0x1200036c 0x120003a8
// veneer/thunk -> 0x00286410 nn::fs::CTR::MPCore::detail::UserFileSystem::CloseFile (static)

// FUNC 0x120001c0 ->fld::GetParamStaffroll (Field)
//   size 0x4 | file Field+0x1c0 | callers(2) 0x120003a8 0x1200098c
// veneer/thunk -> 0x002d4758 fld::GetParamStaffroll (static)

// FUNC 0x120001c8 ->mbsinit (Field)
//   size 0x4 | file Field+0x1c8 | callers(1) 0x120003a8
// veneer/thunk -> 0x001000a4 mbsinit (static)

// FUNC 0x120001d0 ->mbrlen (Field)
//   size 0x4 | file Field+0x1d0 | callers(1) 0x120003a8
// veneer/thunk -> 0x001000b6 mbrlen (static)

// FUNC 0x120001d8 ->mbrtowc (Field)
//   size 0x4 | file Field+0x1d8 | callers(1) 0x120003a8
// veneer/thunk -> 0x001001f8 mbrtowc (static)

// FUNC 0x120001e0 ->nn::fs::CTR::MPCore::detail::UserFileSystem::TryOpenFile (Field)
//   size 0x4 | file Field+0x1e0 | callers(1) 0x120003a8
// veneer/thunk -> 0x0028598c nn::fs::CTR::MPCore::detail::UserFileSystem::TryOpenFile (static)

// FUNC 0x120001e8 ->nn::fs::detail::FileBase::TryGetSize (Field)
//   size 0x4 | file Field+0x1e8 | callers(3) 0x120003a8 0x12000fd4 0x12000fb0
// veneer/thunk -> 0x00286568 nn::fs::detail::FileBase::TryGetSize (static)

// FUNC 0x120001f0 ->nn::cx::UncompressBLZ (Field)
//   size 0x4 | file Field+0x1f0 | callers(1) 0x120003a8
// veneer/thunk -> 0x0010c198 nn::cx::UncompressBLZ (static)

// FUNC 0x120001f8 ->nw::font::ResFont::RemoveResource (Field)
//   size 0x4 | file Field+0x1f8 | callers(3) 0x120003a8 0x12000e44 0x12000efc
// veneer/thunk -> 0x00109280 nw::font::ResFont::RemoveResource (static)

// FUNC 0x12000200 ->MessageDrawer::SetFontEx (Field)
//   size 0x4 | file Field+0x200 | callers(1) 0x120003a8
// veneer/thunk -> 0x00136ef8 MessageDrawer::SetFontEx (static)

// FUNC 0x12000208 ->nw::font::ResFontBase::GetLineFeed (Field)
//   size 0x4 | file Field+0x208 | callers(1) 0x12000874
// veneer/thunk -> 0x003500b4 nw::font::ResFontBase::GetLineFeed (static)

// FUNC 0x12000210 ->wcslen (Field)
//   size 0x4 | file Field+0x210 | callers(1) 0x12000874
// veneer/thunk -> 0x00283544 wcslen (static)

// FUNC 0x12000218 ->Mem::Copy (Field)
//   size 0x4 | file Field+0x218 | callers(1) 0x12000874
// veneer/thunk -> 0x0027fd08 Mem::Copy (static)

// FUNC 0x12000220 ->fld::MsgSys::getComMsgSys (Field)
//   size 0x4 | file Field+0x220 | callers(3) 0x1200098c 0x12000e44 0x12000efc
// veneer/thunk -> 0x002fbe48 fld::MsgSys::getComMsgSys (static)

// FUNC 0x12000228 ->__aeabi_uidivmod (Field)
//   size 0x4 | file Field+0x228 | callers(1) 0x1200098c
// veneer/thunk -> 0x00281628 __aeabi_uidivmod (static)

// FUNC 0x12000230 ->MessageSimple::play (Field)
//   size 0x4 | file Field+0x230 | callers(1) 0x1200098c
// veneer/thunk -> 0x00275444 MessageSimple::play (static)

// FUNC 0x12000238 ->Mem::Free (Field)
//   size 0x4 | file Field+0x238 | callers(2) 0x12000e44 0x12000efc
// veneer/thunk -> 0x00285d3c Mem::Free (static)

// FUNC 0x12000240 Field::CreateStaffrollCtrl (Field)
//   size 0x3c | file Field+0x240 | callers(1) 0x00131790 | datarefs 1

void Field::CreateStaffrollCtrl(MemAlcBase *param_1,uint param_2)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x2c,param_1,(char *)0x0,param_2);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = &fld::StaffrollCtrl::vtable;
    *(undefined1 *)(puVar1 + 6) = 0;
    puVar1[7] = 0;
    puVar1[8] = 0;
  }
  return;
}


// FUNC 0x12000280 ->operator.delete (Field)
//   size 0x4 | file Field+0x280 | callers(0) | datarefs 1
// veneer/thunk -> 0x00286514 operator.delete (static)

// FUNC 0x12000284 nn::fs::IInputStream::vfunc_0x0 (Field)
//   size 0x4 | file Field+0x284 | callers(0) | datarefs 1

void nn::fs::IInputStream::vfunc_0x0(void)

{
  return;
}


// FUNC 0x12000288 nn::fs::FileInputStream::vfunc_0x1c (Field)
//   size 0x24 | file Field+0x288 | callers(0) | datarefs 1

void nn::fs::FileInputStream::vfunc_0x1c(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = detail::FileBase::TrySetPosition(CONCAT44(param_2,param_1 + 4));
  if (iVar1 < 0) {
    err::CTR::ThrowFatalErrAll(iVar1,0x1200029c);
    return;
  }
  return;
}


// FUNC 0x120002ac nn::fs::FileInputStream::vfunc_0x18 (Field)
//   size 0x8 | file Field+0x2ac | callers(0) | datarefs 1

void nn::fs::FileInputStream::vfunc_0x18(int param_1,undefined4 param_2)

{
  detail::FileBase::TrySetPosition(CONCAT44(param_2,param_1 + 4));
  return;
}


// FUNC 0x120002b4 nn::fs::FileInputStream::vfunc_0x2c (Field)
//   size 0x2c | file Field+0x2b4 | callers(0) | datarefs 1

int nn::fs::FileInputStream::vfunc_0x2c(int param_1,void *param_2,uint param_3,int param_4)

{
  int iVar1;
  int local_8;
  
  local_8 = param_4;
  iVar1 = detail::FileBase::TryRead((FileBase *)(param_1 + 4),&local_8,param_2,param_3);
  if (iVar1 < 0) {
    err::CTR::ThrowFatalErrAll(iVar1,0x120002d4);
  }
  return local_8;
}


// FUNC 0x120002e0 nn::fs::FileInputStream::vfunc_0xc (Field)
//   size 0x2c | file Field+0x2e0 | callers(0) | datarefs 1

void nn::fs::FileInputStream::vfunc_0xc(int param_1)

{
  int iVar1;
  undefined4 in_stack_00000000;
  
  iVar1 = detail::FileBase::TrySeek(param_1 + 4);
  if (-(iVar1 >> 0x1f) == 0) {
    return;
  }
  err::CTR::ThrowFatalErrAll(iVar1,0x120002fc,-(iVar1 >> 0x1f),in_stack_00000000);
  return;
}


// FUNC 0x1200030c nn::fs::FileInputStream::vfunc_0x28 (Field)
//   size 0x8 | file Field+0x30c | callers(0) | datarefs 1

void nn::fs::FileInputStream::vfunc_0x28(int param_1,int *param_2,void *param_3,uint param_4)

{
  detail::FileBase::TryRead((FileBase *)(param_1 + 4),param_2,param_3,param_4);
  return;
}


// FUNC 0x12000314 nn::fs::FileInputStream::vfunc_0x8 (Field)
//   size 0x18 | file Field+0x314 | callers(0) | datarefs 1

void nn::fs::FileInputStream::vfunc_0x8(int param_1)

{
  detail::FileBase::TrySeek(param_1 + 4);
  return;
}


// FUNC 0x1200032c nn::fs::FileInputStream::vfunc_0x4 (Field)
//   size 0x40 | file Field+0x32c | callers(0) | datarefs 1

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


// FUNC 0x1200036c nn::fs::FileInputStream::vfunc_0x0 (Field)
//   size 0x3c | file Field+0x36c | callers(0) | datarefs 1

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


// FUNC 0x120003a8 fld::StaffrollCtrl::init (Field)
//   sym _ZN3fld13StaffrollCtrl4initEPNS_6SystemEP10MemAlcBasej | size 0x478 | file Field+0x3a8 | callers(1) 0x00131798 | datarefs 1

/* fld::StaffrollCtrl::init(fld::System*, MemAlcBase*, unsigned int) */

void __thiscall
fld::StaffrollCtrl::init(StaffrollCtrl *this,System *param_1,MemAlcBase *param_2,uint param_3)

{
  int iVar1;
  wchar_t wVar2;
  int iVar3;
  size_t sVar4;
  size_t sVar5;
  void *pvVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  char *pcVar10;
  wchar_t *__pwc;
  wchar_t *__pwc_00;
  bool bVar11;
  float fVar12;
  float fVar13;
  ulonglong uVar14;
  wchar_t local_278 [131];
  char *local_6c;
  undefined **local_68;
  void *local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  mbstate_t local_50;
  mbstate_t mStack_48;
  
  pcVar10 = "rom:/Staffroll/JP/Staffroll.bin";
  __pwc = local_278;
  __pwc_00 = local_278;
  local_6c = "rom:/Staffroll/mario_font.bffnt";
  *(System **)(this + 0x10) = param_1;
  *(undefined4 *)(this + 0x14) = 0;
  iVar3 = GetParamStaffroll();
  *(undefined4 *)(this + 0x28) = *(undefined4 *)(iVar3 + 0x18);
  local_68 = &nn::fs::IInputStream::vtable;
  local_64 = (void *)0x0;
  local_50.__value.__wch = 1;
  mStack_48.__count = 0;
  mStack_48.__value.__wch = 0;
  mbsinit(&mStack_48);
  while ((sVar4 = mbrlen(pcVar10,0x105,&mStack_48), sVar4 != 0 &&
         (sVar5 = mbrtowc(__pwc,pcVar10,sVar4,&mStack_48), sVar5 != 0))) {
    pcVar10 = pcVar10 + sVar4;
    __pwc = (wchar_t *)((int)__pwc + 2);
  }
  *(undefined2 *)__pwc = 0;
  local_58 = 0;
  local_54 = 0;
  local_60 = 0;
  local_5c = 0;
  uVar14 = nn::fs::CTR::MPCore::detail::UserFileSystem::TryOpenFile
                     (&local_64,local_278,local_50.__value.__wch);
  uVar7 = (undefined4)(uVar14 >> 0x20);
  bVar11 = (uVar14 & 0x80000000) != 0;
  if (bVar11) {
    uVar7 = 0x12000494;
  }
  if (bVar11 && (int)uVar14 < 0) {
    nn::err::CTR::ThrowFatalErrAll((int)uVar14,uVar7);
  }
  local_68 = &nn::fs::FileInputStream::vtable;
  iVar3 = nn::fs::detail::FileBase::TryGetSize((FileBase *)&local_64,(longlong *)local_278);
  if (iVar3 < 0) {
    nn::err::CTR::ThrowFatalErrAll(iVar3,0x120004c0);
  }
  wVar2 = local_278[0];
  local_278[0] = L'\x02';
  iVar3 = nn::fs::detail::FileBase::TrySeek(&local_64,2,0xfffffffc,0xffffffff);
  if (iVar3 < 0) {
    nn::err::CTR::ThrowFatalErrAll(iVar3,0x120004e8);
  }
  iVar3 = nn::fs::detail::FileBase::TryRead((FileBase *)&local_64,local_278,&local_50,4);
  if (iVar3 < 0) {
    nn::err::CTR::ThrowFatalErrAll(iVar3,0x12000508);
  }
  local_50.__count = local_50.__count + wVar2;
  uVar7 = (**(code **)(*(int *)param_2 + 0xc))(param_2,local_50.__count,param_3);
  *(undefined4 *)(this + 0xc) = uVar7;
  local_278[0] = L'\0';
  iVar3 = nn::fs::detail::FileBase::TrySeek(&local_64,0,0,0);
  if (iVar3 < 0) {
    nn::err::CTR::ThrowFatalErrAll(iVar3,0x12000554);
  }
  iVar3 = nn::fs::detail::FileBase::TryRead
                    ((FileBase *)&local_64,local_278,*(void **)(this + 0xc),wVar2);
  if (iVar3 < 0) {
    nn::err::CTR::ThrowFatalErrAll(iVar3,0x12000574);
  }
  nn::cx::UncompressBLZ(*(void **)(this + 0xc),wVar2,local_50.__count);
  uVar7 = **(undefined4 **)(this + 0xc);
  *(undefined4 **)(this + 0x20) = *(undefined4 **)(this + 0xc) + 1;
  *(undefined4 *)(this + 0x1c) = uVar7;
  if (((uint)local_64 & 0xfffffffe) != 0) {
    if (((uint)local_64 & 1) != 0) {
      nndbgPanic();
    }
    nn::fs::CTR::MPCore::detail::UserFileSystem::CloseFile((void *)((uint)local_64 & 0xfffffffe));
  }
  pcVar10 = local_6c;
  local_68 = &nn::fs::IInputStream::vtable;
  local_6c = (char *)0x1;
  local_64 = (void *)0x0;
  local_50.__count = 0;
  local_50.__value.__wch = 0;
  mbsinit(&local_50);
  while ((sVar4 = mbrlen(pcVar10,0x105,&local_50), sVar4 != 0 &&
         (sVar5 = mbrtowc(__pwc_00,pcVar10,sVar4,&local_50), sVar5 != 0))) {
    pcVar10 = pcVar10 + sVar4;
    __pwc_00 = (wchar_t *)((int)__pwc_00 + 2);
  }
  *(undefined2 *)__pwc_00 = 0;
  local_58 = 0;
  local_54 = 0;
  local_60 = 0;
  local_5c = 0;
  uVar14 = nn::fs::CTR::MPCore::detail::UserFileSystem::TryOpenFile
                     (&local_64,local_278,(uint)local_6c);
  uVar7 = (undefined4)(uVar14 >> 0x20);
  bVar11 = (uVar14 & 0x80000000) != 0;
  if (bVar11) {
    uVar7 = 0x12000678;
  }
  if (bVar11 && (int)uVar14 < 0) {
    nn::err::CTR::ThrowFatalErrAll((int)uVar14,uVar7);
  }
  local_68 = &nn::fs::FileInputStream::vtable;
  iVar3 = nn::fs::detail::FileBase::TryGetSize((FileBase *)&local_64,(longlong *)local_278);
  if (iVar3 < 0) {
    nn::err::CTR::ThrowFatalErrAll(iVar3,0x120006a4);
  }
  wVar2 = local_278[0];
  pvVar6 = (void *)(**(code **)(*(int *)param_2 + 0xc))(param_2,local_278[0],param_3);
  *(void **)(this + 8) = pvVar6;
  iVar3 = nn::fs::detail::FileBase::TryRead((FileBase *)&local_64,local_278,pvVar6,wVar2);
  if (iVar3 < 0) {
    nn::err::CTR::ThrowFatalErrAll(iVar3,0x120006ec);
  }
  if (((uint)local_64 & 0xfffffffe) != 0) {
    if (((uint)local_64 & 1) != 0) {
      nndbgPanic();
    }
    nn::fs::CTR::MPCore::detail::UserFileSystem::CloseFile((void *)((uint)local_64 & 0xfffffffe));
    local_64 = (void *)0x0;
  }
  pvVar6 = (void *)nw::font::ResFont::RemoveResource((ResFont *)&DAT_003fc260);
  if (pvVar6 != (void *)0x0) {
    operator_delete(pvVar6);
  }
  MessageDrawer::SetFontEx(*(void **)(this + 8));
  if (((uint)local_64 & 0xfffffffe) != 0) {
    if (((uint)local_64 & 1) != 0) {
      nndbgPanic();
    }
    nn::fs::CTR::MPCore::detail::UserFileSystem::CloseFile((void *)((uint)local_64 & 0xfffffffe));
    local_64 = (void *)0x0;
  }
  fVar12 = 0.0;
  uVar9 = *(uint *)(this + 0x1c);
  if (uVar9 != 0) {
    bVar11 = (uVar9 & 1) != 0;
    fVar13 = fVar12;
    if (bVar11) {
      fVar13 = *(float *)(*(int *)(this + 0x20) + 0x5c) + 0.0;
    }
    uVar8 = (uint)bVar11;
    uVar9 = uVar9 >> 1;
    if (uVar9 != 0) {
      do {
        uVar9 = uVar9 - 1;
        iVar3 = uVar8 * 0x60;
        iVar1 = uVar8 * 0x60;
        uVar8 = uVar8 + 2;
        fVar13 = *(float *)(iVar3 + 0x5c + *(int *)(this + 0x20)) + fVar13;
        fVar12 = *(float *)(iVar1 + 0xbc + *(int *)(this + 0x20)) + fVar12;
      } while (uVar9 != 0);
    }
    fVar12 = fVar13 + fVar12;
  }
  iVar3 = GetParamStaffroll();
  *(float *)(this + 0x24) = (fVar12 - 480.0) - *(float *)(iVar3 + 0x14);
  this[0x18] = (StaffrollCtrl)0x1;
  return;
}


// FUNC 0x12000874 FUN_12000874 (Field)
//   size 0x110 | file Field+0x874 | callers(1) 0x1200098c

void FUN_12000874(int param_1,undefined2 *param_2,uint param_3,uint param_4,short param_5)

{
  undefined4 uVar1;
  size_t sVar2;
  int iVar3;
  undefined2 *puVar4;
  uint uVar5;
  wchar_t *__s;
  uint in_fpscr;
  float fVar6;
  undefined8 unaff_d8;
  float fVar7;
  
  fVar7 = (float)((ulonglong)unaff_d8 >> 0x20);
  uVar1 = nw::font::ResFontBase::GetLineFeed((ResFontBase *)&DAT_003fc260);
  if (param_3 <= param_4) {
    fVar7 = 100.0;
  }
  fVar6 = (float)VectorSignedToFloat(uVar1,(byte)(in_fpscr >> 0x16) & 3);
  for (uVar5 = param_3; uVar5 <= param_4; uVar5 = uVar5 + 1) {
    iVar3 = *(int *)(param_1 + 0x20);
    *param_2 = 0xe;
    param_2[1] = 0;
    param_2[2] = 2;
    __s = (wchar_t *)(iVar3 + uVar5 * 0x60);
    param_2[3] = 2;
    uVar1 = VectorFloatToUnsigned(((float)__s[0x17] * fVar7) / fVar6,3);
    param_2[4] = (short)uVar1;
    param_2[5] = 0xe;
    param_2[6] = 0;
    param_2[7] = 3;
    param_2[8] = 4;
    param_2[9] = (short)((uint)__s[0x16] >> 0x10);
    param_2[10] = (ushort)(byte)__s[0x16] + param_5 * 0x100;
    puVar4 = param_2 + 0xb;
    if (uVar5 != param_3) {
      puVar4 = param_2 + 0xc;
      param_2[0xb] = 10;
    }
    sVar2 = wcslen(__s);
    if (sVar2 == 0) {
      param_2 = puVar4 + 1;
      *puVar4 = 0x20;
    }
    else {
      Mem::Copy(puVar4,__s,sVar2 << 1);
      param_2 = puVar4 + sVar2;
    }
  }
  *param_2 = 0;
  return;
}


// FUNC 0x1200098c fld::StaffrollCtrl::update (Field)
//   sym _ZN3fld13StaffrollCtrl6updateEv | size 0x4a4 | file Field+0x98c | callers(1) 0x001317a0 | datarefs 1

/* fld::StaffrollCtrl::update() */

void __thiscall fld::StaffrollCtrl::update(StaffrollCtrl *this)

{
  ushort uVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  MessageSimple *pMVar8;
  uint uVar9;
  bool bVar10;
  uint in_fpscr;
  float fVar11;
  float fVar12;
  undefined4 uVar13;
  float fVar14;
  undefined8 unaff_d9;
  float fVar15;
  uint local_1074 [3];
  float local_1068 [4];
  undefined4 local_1058;
  ushort local_1054 [1022];
  undefined4 local_858;
  ushort local_854 [1038];
  
  iVar2 = MsgSys::getComMsgSys();
  puVar3 = (uint *)GetParamStaffroll();
  uVar7 = *puVar3;
  iVar4 = GetParamStaffroll();
  uVar6 = *(uint *)(this + 0x14);
  fVar12 = (float)VectorUnsignedToFloat(uVar6,(byte)(in_fpscr >> 0x16) & 3);
  fVar11 = (float)VectorUnsignedToFloat(*(int *)(iVar4 + 4) + uVar7,(byte)(in_fpscr >> 0x16) & 3);
  uVar13 = VectorFloatToUnsigned(fVar12 * *(float *)(this + 0x28) - fVar11,3);
  fVar11 = (float)VectorUnsignedToFloat(uVar13,(byte)(in_fpscr >> 0x16) & 3);
  in_fpscr = in_fpscr & 0xfffffff;
  if (*(float *)(this + 0x24) < fVar11) {
    uVar13 = VectorFloatToUnsigned(*(float *)(this + 0x24),3);
  }
  if (uVar6 < uVar7) {
    uVar6 = __aeabi_uidivmod(uVar6 * 0xff,uVar7);
  }
  else {
    uVar6 = 0xff;
  }
  fVar11 = (float)VectorUnsignedToFloat(uVar13,(byte)(in_fpscr >> 0x16) & 3);
  uVar6 = uVar6 & 0xff;
  uVar7 = 0;
  if (*(int *)(this + 0x1c) != 0) {
    unaff_d9 = 0x4370000000000000;
  }
  uVar9 = 0;
  uVar5 = 0;
  fVar12 = 0.0;
  if (*(int *)(this + 0x1c) != 0) {
    do {
      fVar15 = (float)((ulonglong)unaff_d9 >> 0x20);
      fVar14 = fVar12 + *(float *)(*(int *)(this + 0x20) + uVar9 * 0x60 + 0x5c);
      unaff_d9 = CONCAT44(fVar15,fVar14);
      if (fVar11 < fVar14) {
        local_1074[uVar7] = uVar9;
        local_1068[uVar7] = fVar11 - fVar12;
        if (uVar7 == 0) {
          iVar4 = GetParamStaffroll();
          fVar11 = *(float *)(iVar4 + 0x14) + fVar11 + fVar15;
        }
        else {
          if (uVar7 != 1) goto LAB_12000abc;
          fVar11 = fVar11 + fVar15;
        }
        uVar7 = uVar7 + 1 & 0xff;
      }
      uVar5 = *(uint *)(this + 0x1c);
      uVar9 = uVar9 + 1;
      fVar12 = fVar14;
    } while (uVar9 < uVar5);
  }
  local_1074[2] = uVar5 - 1;
LAB_12000abc:
  FUN_12000874(this,&local_1058,local_1074[0],local_1074[1] + -1,uVar6);
  pMVar8 = (MessageSimple *)(iVar2 + 0x2dea8);
  (*(code *)**(undefined4 **)pMVar8)(pMVar8);
  *(undefined4 *)(iVar2 + 0x34b68) = 0x400;
  *(uint *)(iVar2 + 0x336e4) = *(uint *)(iVar2 + 0x336e4) | 0x10;
  *(undefined1 *)(iVar2 + 0x33965) = 0;
  iVar4 = GetParamStaffroll();
  *(undefined4 *)(iVar2 + 0x3395c) = *(undefined4 *)(iVar4 + 8);
  *(float *)(iVar2 + 0x33960) = local_1068[0] + 120.0;
  if ((*(byte *)(iVar2 + 0x336e4) & 1) != 0) {
    (**(code **)(*(int *)pMVar8 + 0x28))(pMVar8);
  }
  *(undefined1 *)(iVar2 + 0x34980) = 8;
  *(undefined **)(iVar2 + 0x336d0) = &DAT_003fc260;
  MessageSimple::play(pMVar8,&local_1058,(InsParam *)0x0,false);
  iVar4 = 0;
  do {
    if (*(short *)((int)&local_1058 + iVar4 * 2) == 0xe) {
      uVar1 = local_1054[iVar4 + -1];
      bVar10 = uVar1 == 0;
      if (bVar10) {
        uVar1 = local_1054[iVar4];
      }
      if (bVar10 && uVar1 == 3) {
        local_1054[iVar4 + 3] = (ushort)(uVar6 << 8);
        local_1054[iVar4 + 2] = 0;
      }
      iVar4 = iVar4 + (uint)(local_1054[iVar4 + 1] >> 1) + 2;
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 0x400);
  pMVar8 = (MessageSimple *)(iVar2 + 0x27148);
  (*(code *)**(undefined4 **)pMVar8)(pMVar8);
  *(undefined4 *)(iVar2 + 0x2de08) = 0x400;
  *(uint *)(iVar2 + 0x2c984) = *(uint *)(iVar2 + 0x2c984) | 0x10;
  *(undefined1 *)(iVar2 + 0x2cc05) = 0;
  iVar4 = GetParamStaffroll();
  fVar14 = *(float *)(iVar4 + 8);
  iVar4 = GetParamStaffroll();
  fVar11 = *(float *)(iVar4 + 0xc);
  iVar4 = GetParamStaffroll();
  fVar12 = *(float *)(iVar4 + 0x10);
  *(float *)(iVar2 + 0x2cbfc) = fVar14 + fVar11;
  *(float *)(iVar2 + 0x2cc00) = fVar12 + local_1068[0] + 120.0;
  if ((*(byte *)(iVar2 + 0x2c984) & 1) != 0) {
    (**(code **)(*(int *)pMVar8 + 0x28))(pMVar8);
  }
  *(undefined1 *)(iVar2 + 0x2dc20) = 8;
  *(undefined **)(iVar2 + 0x2c970) = &DAT_003fc260;
  MessageSimple::play(pMVar8,&local_1058,(InsParam *)0x0,false);
  FUN_12000874(this,&local_858,local_1074[1],local_1074[2],uVar6);
  pMVar8 = (MessageSimple *)(iVar2 + 0x3b968);
  (*(code *)**(undefined4 **)pMVar8)(pMVar8);
  *(undefined4 *)(iVar2 + 0x42628) = 0x401;
  *(uint *)(iVar2 + 0x411a4) = *(uint *)(iVar2 + 0x411a4) | 0x10;
  *(undefined1 *)(iVar2 + 0x41425) = 0;
  iVar4 = GetParamStaffroll();
  *(undefined4 *)(iVar2 + 0x4141c) = *(undefined4 *)(iVar4 + 8);
  *(float *)(iVar2 + 0x41420) = local_1068[1] + 120.0;
  if ((*(byte *)(iVar2 + 0x411a4) & 1) != 0) {
    (**(code **)(*(int *)pMVar8 + 0x28))(pMVar8);
  }
  *(undefined1 *)(iVar2 + 0x42440) = 8;
  *(undefined **)(iVar2 + 0x41190) = &DAT_003fc260;
  MessageSimple::play(pMVar8,&local_858,(InsParam *)0x0,false);
  iVar4 = 0;
  do {
    if (*(short *)((int)&local_858 + iVar4 * 2) == 0xe) {
      uVar1 = local_854[iVar4 + -1];
      bVar10 = uVar1 == 0;
      if (bVar10) {
        uVar1 = local_854[iVar4];
      }
      if (bVar10 && uVar1 == 3) {
        local_854[iVar4 + 3] = (ushort)(uVar6 << 8);
        local_854[iVar4 + 2] = 0;
      }
      iVar4 = iVar4 + (uint)(local_854[iVar4 + 1] >> 1) + 2;
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 0x400);
  pMVar8 = (MessageSimple *)(iVar2 + 0x34c08);
  (*(code *)**(undefined4 **)pMVar8)(pMVar8);
  *(undefined4 *)(iVar2 + 0x3b8c8) = 0x401;
  *(uint *)(iVar2 + 0x3a444) = *(uint *)(iVar2 + 0x3a444) | 0x10;
  *(undefined1 *)(iVar2 + 0x3a6c5) = 0;
  iVar4 = GetParamStaffroll();
  fVar14 = *(float *)(iVar4 + 8);
  iVar4 = GetParamStaffroll();
  fVar11 = *(float *)(iVar4 + 0xc);
  iVar4 = GetParamStaffroll();
  fVar12 = *(float *)(iVar4 + 0x10);
  *(float *)(iVar2 + 0x3a6bc) = fVar14 + fVar11;
  *(float *)(iVar2 + 0x3a6c0) = fVar12 + local_1068[1] + 120.0;
  if ((*(byte *)(iVar2 + 0x3a444) & 1) != 0) {
    (**(code **)(*(int *)pMVar8 + 0x28))(pMVar8);
  }
  *(undefined1 *)(iVar2 + 0x3b6e0) = 8;
  *(undefined **)(iVar2 + 0x3a430) = &DAT_003fc260;
  MessageSimple::play(pMVar8,&local_858,(InsParam *)0x0,false);
  *(int *)(this + 0x14) = *(int *)(this + 0x14) + 1;
  return;
}


// FUNC 0x12000e44 fld::StaffrollCtrl::vfunc_0x4 (Field)
//   size 0xb0 | file Field+0xe44 | callers(0) | datarefs 1

void fld::StaffrollCtrl::vfunc_0x4(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &vtable;
  if (*(char *)(param_1 + 6) != '\0') {
    iVar1 = MsgSys::getComMsgSys();
    if (iVar1 != 0) {
      *(uint *)(iVar1 + 0x2c984) = *(uint *)(iVar1 + 0x2c984) & 0xffffffef;
      *(uint *)(iVar1 + 0x336e4) = *(uint *)(iVar1 + 0x336e4) & 0xffffffef;
      *(uint *)(iVar1 + 0x3a444) = *(uint *)(iVar1 + 0x3a444) & 0xffffffef;
      *(uint *)(iVar1 + 0x411a4) = *(uint *)(iVar1 + 0x411a4) & 0xffffffef;
    }
    nw::font::ResFont::RemoveResource((ResFont *)&DAT_003fc260);
    Mem::Free((void *)param_1[2]);
    param_1[2] = 0;
    Mem::Free((void *)param_1[3]);
    param_1[3] = 0;
    param_1[2] = 0;
    *(undefined1 *)(param_1 + 6) = 0;
  }
  operator_delete(param_1);
  return;
}


// FUNC 0x12000efc fld::StaffrollCtrl::vfunc_0x0 (Field)
//   size 0xac | file Field+0xefc | callers(0) | datarefs 1

undefined4 * fld::StaffrollCtrl::vfunc_0x0(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &vtable;
  if (*(char *)(param_1 + 6) != '\0') {
    iVar1 = MsgSys::getComMsgSys();
    if (iVar1 != 0) {
      *(uint *)(iVar1 + 0x2c984) = *(uint *)(iVar1 + 0x2c984) & 0xffffffef;
      *(uint *)(iVar1 + 0x336e4) = *(uint *)(iVar1 + 0x336e4) & 0xffffffef;
      *(uint *)(iVar1 + 0x3a444) = *(uint *)(iVar1 + 0x3a444) & 0xffffffef;
      *(uint *)(iVar1 + 0x411a4) = *(uint *)(iVar1 + 0x411a4) & 0xffffffef;
    }
    nw::font::ResFont::RemoveResource((ResFont *)&DAT_003fc260);
    Mem::Free((void *)param_1[2]);
    param_1[2] = 0;
    Mem::Free((void *)param_1[3]);
    param_1[3] = 0;
    param_1[2] = 0;
    *(undefined1 *)(param_1 + 6) = 0;
  }
  return param_1;
}


// FUNC 0x12000fb0 nn::fs::FileInputStream::vfunc_0x20 (Field)
//   size 0x8 | file Field+0xfb0 | callers(0) | datarefs 1

void nn::fs::FileInputStream::vfunc_0x20(int param_1,longlong *param_2)

{
  detail::FileBase::TryGetSize((FileBase *)(param_1 + 4),param_2);
  return;
}


// FUNC 0x12000fb8 nn::fs::FileInputStream::vfunc_0x14 (Field)
//   size 0x8 | file Field+0xfb8 | callers(0) | datarefs 1

undefined8 nn::fs::FileInputStream::vfunc_0x14(int param_1)

{
  return *(undefined8 *)(param_1 + 8);
}


// FUNC 0x12000fc0 nn::fs::FileInputStream::vfunc_0x10 (Field)
//   size 0x14 | file Field+0xfc0 | callers(0) | datarefs 1

undefined4 nn::fs::FileInputStream::vfunc_0x10(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 0xc);
  *param_2 = *(undefined4 *)(param_1 + 8);
  param_2[1] = uVar1;
  return 0;
}


// FUNC 0x12000fd4 nn::fs::FileInputStream::vfunc_0x24 (Field)
//   size 0x2c | file Field+0xfd4 | callers(0) | datarefs 1

longlong nn::fs::FileInputStream::vfunc_0x24(int param_1)

{
  int iVar1;
  longlong local_10;
  
  iVar1 = detail::FileBase::TryGetSize((FileBase *)(param_1 + 4),&local_10);
  if (iVar1 < 0) {
    err::CTR::ThrowFatalErrAll(iVar1,0x12000ff0);
  }
  return local_10;
}


// FUNC 0x12001000 fld::StaffrollCtrl::isFinish (Field)
//   sym _ZNK3fld13StaffrollCtrl8isFinishEv | size 0x28 | file Field+0x1000 | callers(1) 0x001317a8 | datarefs 1

/* fld::StaffrollCtrl::isFinish() const */

bool __thiscall fld::StaffrollCtrl::isFinish(StaffrollCtrl *this)

{
  uint in_fpscr;
  float fVar1;
  
  fVar1 = (float)VectorUnsignedToFloat(*(undefined4 *)(this + 0x14),(byte)(in_fpscr >> 0x16) & 3);
  return *(float *)(this + 0x24) < fVar1 * *(float *)(this + 0x28);
}


// FUNC 0x12001028 Field::nnroControlObject_ (Field)
//   size 0x74 | file Field+0x1028 | callers(0)

undefined4 Field::nnroControlObject_(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined *puVar2;
  
  switch(param_2) {
  case 0:
    uVar1 = 0;
    break;
  case 1:
    DAT_12003a2c = param_1;
    return 0;
  case 2:
    uVar1 = DAT_12003a2c;
    break;
  case 3:
    *param_1 = &DAT_120010d4;
    puVar2 = &DAT_120010d4;
    goto LAB_12001088;
  case 4:
    *param_1 = &DAT_1200227c;
    puVar2 = &DAT_1200227c;
LAB_12001088:
    param_1[1] = puVar2;
    return 0;
  default:
    return 0xd8e12c21;
  }
  *param_1 = uVar1;
  return 0;
}


