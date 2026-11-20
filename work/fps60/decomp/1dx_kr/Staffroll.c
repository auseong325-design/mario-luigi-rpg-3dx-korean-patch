// fps60 TG decompiled C: 1dx_kr.code.bin module Staffroll part 1 (Ghidra 12.2, ARM:LE:32:v6:hardfp)
// Addresses: static = runtime address; CRO = fixed analysis base (crolink.py), NOT runtime.

// FUNC 0x11000180 ->SetMinigameWorkForStaffroll (Staffroll)
//   size 0x4 | file Staffroll+0x180 | callers(1) 0x110001a0
// veneer/thunk -> 0x001353e4 SetMinigameWorkForStaffroll (static)

// FUNC 0x11000188 ->operator.new (Staffroll)
//   size 0x4 | file Staffroll+0x188 | callers(1) 0x110001a0
// veneer/thunk -> 0x002f1528 operator.new (static)

// FUNC 0x11000190 ->mg::MGSystem::MGSystem (Staffroll)
//   size 0x4 | file Staffroll+0x190 | callers(1) 0x110001a0
// veneer/thunk -> 0x1004723c mg::MGSystem::MGSystem (EtcSys)

// FUNC 0x11000198 ->TaskMan::entry (Staffroll)
//   size 0x4 | file Staffroll+0x198 | callers(1) 0x110001a0
// veneer/thunk -> 0x002f12b4 TaskMan::entry (static)

// FUNC 0x110001a0 Staffroll::EntryTask (Staffroll)
//   size 0x38 | file Staffroll+0x1a0 | callers(0)

void Staffroll::EntryTask(void)

{
  MGSystem *this;
  Task *pTVar1;
  
  SetMinigameWorkForStaffroll();
  this = operator_new(0x96ae8,gMemAlc,(char *)0x0,0);
  pTVar1 = (Task *)0x0;
  if (this != (MGSystem *)0x0) {
    pTVar1 = (Task *)mg::MGSystem::MGSystem(this);
  }
  TaskMan::entry((TaskMan *)&gTaskMainMan,pTVar1);
  return;
}


// FUNC 0x110001e4 Staffroll::nnroControlObject_ (Staffroll)
//   size 0x74 | file Staffroll+0x1e4 | callers(0)

undefined4 Staffroll::nnroControlObject_(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  char *pcVar2;
  
  switch(param_2) {
  case 0:
    uVar1 = 0;
    break;
  case 1:
    DAT_110011f4 = param_1;
    return 0;
  case 2:
    uVar1 = DAT_110011f4;
    break;
  case 3:
    *param_1 = &DAT_11000290;
    pcVar2 = "";
    goto LAB_11000244;
  case 4:
    *param_1 = "Staffroll";
    pcVar2 = "Staffroll";
LAB_11000244:
    param_1[1] = pcVar2;
    return 0;
  default:
    return 0xd8e12c21;
  }
  *param_1 = uVar1;
  return 0;
}


