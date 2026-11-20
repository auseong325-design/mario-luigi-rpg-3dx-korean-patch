// fps60 TG decompiled C: 3dx_v12.code.bin module KJGuide part 1 (Ghidra 12.2, ARM:LE:32:v6:hardfp)
// Addresses: static = runtime address; CRO = fixed analysis base (crolink.py), NOT runtime.

// FUNC 0x13000180 KJGuide::nnroControlObject_ (KJGuide)
//   size 0x74 | file KJGuide+0x180 | callers(0)

undefined4 KJGuide::nnroControlObject_(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined *puVar2;
  
  switch(param_2) {
  case 0:
    uVar1 = 0;
    break;
  case 1:
    DAT_130025a8 = param_1;
    return 0;
  case 2:
    uVar1 = DAT_130025a8;
    break;
  case 3:
    *param_1 = &DAT_1300022c;
    puVar2 = &DAT_1300022c;
    goto LAB_130001e0;
  case 4:
    *param_1 = &DAT_13001984;
    puVar2 = &DAT_13001984;
LAB_130001e0:
    param_1[1] = puVar2;
    return 0;
  default:
    return 0xd8e12c21;
  }
  *param_1 = uVar1;
  return 0;
}


