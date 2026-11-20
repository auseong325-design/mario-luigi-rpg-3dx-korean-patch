// fps60 TG decompiled C: 3dx_v12.code.bin module MenuGuide part 1 (Ghidra 12.2, ARM:LE:32:v6:hardfp)
// Addresses: static = runtime address; CRO = fixed analysis base (crolink.py), NOT runtime.

// FUNC 0x15800180 MenuGuide::nnroControlObject_ (MenuGuide)
//   size 0x74 | file MenuGuide+0x180 | callers(0)

undefined4 MenuGuide::nnroControlObject_(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined *puVar2;
  
  switch(param_2) {
  case 0:
    uVar1 = 0;
    break;
  case 1:
    DAT_15802594 = param_1;
    return 0;
  case 2:
    uVar1 = DAT_15802594;
    break;
  case 3:
    *param_1 = &DAT_1580022c;
    puVar2 = &DAT_1580022c;
    goto LAB_158001e0;
  case 4:
    *param_1 = &DAT_15801880;
    puVar2 = &DAT_15801880;
LAB_158001e0:
    param_1[1] = puVar2;
    return 0;
  default:
    return 0xd8e12c21;
  }
  *param_1 = uVar1;
  return 0;
}


