// fps60 TG decompiled C: 1dx_kr.code.bin module MiniGame part 1 (Ghidra 12.2, ARM:LE:32:v6:hardfp)
// Addresses: static = runtime address; CRO = fixed analysis base (crolink.py), NOT runtime.

// FUNC 0x10800180 ->operator.new (MiniGame)
//   size 0x4 | file MiniGame+0x180 | callers(1) 0x10800198
// veneer/thunk -> 0x002f1528 operator.new (static)

// FUNC 0x10800188 ->mg::MGSystem::MGSystem (MiniGame)
//   size 0x4 | file MiniGame+0x188 | callers(1) 0x10800198
// veneer/thunk -> 0x1004723c mg::MGSystem::MGSystem (EtcSys)

// FUNC 0x10800190 ->TaskMan::entry (MiniGame)
//   size 0x4 | file MiniGame+0x190 | callers(1) 0x10800198
// veneer/thunk -> 0x002f12b4 TaskMan::entry (static)

// FUNC 0x10800198 MiniGame::EntryTask (MiniGame)
//   size 0x34 | file MiniGame+0x198 | callers(0)

void MiniGame::EntryTask(void)

{
  MGSystem *this;
  Task *pTVar1;
  
  this = operator_new(0x96ae8,gMemAlc,(char *)0x0,0);
  pTVar1 = (Task *)0x0;
  if (this != (MGSystem *)0x0) {
    pTVar1 = (Task *)mg::MGSystem::MGSystem(this);
  }
  TaskMan::entry((TaskMan *)&gTaskMainMan,pTVar1);
  return;
}


// FUNC 0x108001d8 MiniGame::nnroControlObject_ (MiniGame)
//   size 0x74 | file MiniGame+0x1d8 | callers(0)

undefined4 MiniGame::nnroControlObject_(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  char *pcVar2;
  
  switch(param_2) {
  case 0:
    uVar1 = 0;
    break;
  case 1:
    DAT_108011c0 = param_1;
    return 0;
  case 2:
    uVar1 = DAT_108011c0;
    break;
  case 3:
    *param_1 = &DAT_10800284;
    pcVar2 = "";
    goto LAB_10800238;
  case 4:
    *param_1 = "MiniGame";
    pcVar2 = "MiniGame";
LAB_10800238:
    param_1[1] = pcVar2;
    return 0;
  default:
    return 0xd8e12c21;
  }
  *param_1 = uVar1;
  return 0;
}


