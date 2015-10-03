#include "StdAfx.h"
#include "WeaponFloat.h"
#include "Define.h"
#include "TMemory.h"
//---------------------------------------------------------------------------

DWORD SecondWeaponFixVal	= 0;
DWORD IsShield				= 0;
DWORD s_eax, s_ecx, s_edx;
//---------------------------------------------------------------------------

void cWeaponFloatLoad()
{
	SetJmp((LPVOID)WeaponViewCheck_Hook, WeaponViewCheck);
	SetJmp((LPVOID)SecondWeaponViewFix_Hook, SecondWeaponViewFix);
	SetJmp((LPVOID)SecondWeaponViewCheckReplacedCode_Hook, SecondWeaponViewCheckReplacedCode);
	// ----
	HookThis((DWORD)SecondWeaponViewCheck, SecondWeaponViewCheck_Hook1);
	HookThis((DWORD)SecondWeaponViewCheck, SecondWeaponViewCheck_Hook2);
}
//---------------------------------------------------------------------------

Naked (WeaponViewCheck)
{
	_asm
	{
		MOV BYTE PTR SS:[EBP+WeaponViewFlagFixup], 0
		CMP DWORD PTR SS:[EBP+SafeZoneFlagFixup], 0
		JE WEAPON_CHECK
		MOV BYTE PTR SS:[EBP+WeaponViewFlagFixup], 1	
		// ----
		WEAPON_CHECK:
		MOV EAX, DWORD PTR SS:[EBP+8]
		CMP DWORD PTR SS:[EBP+HandFlagFixup], 0
		JNZ LEFT_HAND
		// ----
		MOVSX ECX, WORD PTR DS:[EAX+RightHandFixup]
		CMP ECX, ITEM(7, 0) + OBJ_OFFS
		JGE NO_DISPLAY
		// ----
		CMP ECX, ITEM(4, 15) + OBJ_OFFS
		JE DISPLAY_WEAPON
		JMP END_CHECK
		// ----
		LEFT_HAND:
		MOVSX ECX, WORD PTR DS:[EAX+LeftHandFixup]
		// ----
		CMP ECX, ITEM(7, 0) + OBJ_OFFS
		JGE NO_DISPLAY
		// ----
		CMP ECX, ITEM(4, 7) + OBJ_OFFS
		JE DISPLAY_WEAPON
		JMP END_CHECK
		// ----
		DISPLAY_WEAPON:
		MOV BYTE PTR SS:[EBP+WeaponViewFlagFixup], 1
		JMP END_CHECK
		// ----
		NO_DISPLAY:
		MOV BYTE PTR SS:[EBP+WeaponViewFlagFixup], 0
		// ----
		END_CHECK:
		jmp WeaponViewCheck_Ret
	}
}
//---------------------------------------------------------------------------

Naked (SecondWeaponViewCheck)
{
	_asm
	{
		CMP DWORD PTR SS:[EBP+HandFlagFixup], 0
		JNZ END_CHECK
		// ----
		MOV DWORD PTR SS:[EBP+HandFlagFixup], 1
		MOV SecondWeaponFixVal, 1
		// ----
		JMP WeaponViewCheck
		// ----
		END_CHECK:
		MOV SecondWeaponFixVal, 0
		jmp SecondWeaponViewCheck_Ret
	}
}
//---------------------------------------------------------------------------

Naked (SecondWeaponViewCheckReplacedCode)
{
	_asm
	{
		MOV EDX, DWORD PTR SS:[EBP+SomeVal1Fixup]
		MOV EAX, DWORD PTR SS:[EBP+SomeVal2Fixup]
		MOV DWORD PTR DS:[EDX+SomeVal3Fixup], EAX
		JMP SecondWeaponViewCheck
	}
}
//---------------------------------------------------------------------------

Naked (SecondWeaponViewFix)
{
	_asm
	{
		MOV IsShield, 0
		// ----
		CMP WEAPON_ID_CONTAINER, ITEM(6, 0) + OBJ_OFFS
		JL FLIP_CHECK
		CMP WEAPON_ID_CONTAINER, ITEM(7, 0) + OBJ_OFFS
		JGE FLIP_CHECK
		// ----
		MOV IsShield, 1
		// ----
		CMP WEAPON_ID_CONTAINER, ITEM(6, 16) + OBJ_OFFS
		JNZ CHECK_SHIELD_14_15
		// ----
		MOV DWORD PTR SS:[STACK_PTR+RotFixup], 0x41F00000
		MOV DWORD PTR SS:[STACK_PTR+RotFixup+4], 0
		MOV DWORD PTR SS:[STACK_PTR+RotFixup+8], 0x42B40000
		LEA EDX, DWORD PTR SS:[STACK_PTR+TransFixup]
		LEA EAX, DWORD PTR SS:[STACK_PTR+RotFixup]
		PUSH EDX
		PUSH EAX
		CALL RotateFunc
		ADD ESP, 8
		MOV DWORD PTR SS:[STACK_PTR+TransFixup+0x0C], 0xC1A00000
		MOV DWORD PTR SS:[STACK_PTR+TransFixup+0x1C], 0
		MOV DWORD PTR SS:[STACK_PTR+TransFixup+0x2C], 0xC1A00000
		// ----
		JMP FLIP_CHECK
		// ----
		CHECK_SHIELD_14_15:
		CMP WEAPON_ID_CONTAINER, ITEM(6, 15) + OBJ_OFFS
		JE SHIELD_14_15
		CMP WEAPON_ID_CONTAINER, ITEM(6, 14) + OBJ_OFFS
		JNZ CHECK_SHIELD_6
		// ----
		SHIELD_14_15:
		MOV DWORD PTR SS:[STACK_PTR+RotFixup], 0x42480000
		MOV DWORD PTR SS:[STACK_PTR+RotFixup+4], 0
		MOV DWORD PTR SS:[STACK_PTR+RotFixup+8], 0x42B40000
		LEA EDX, DWORD PTR SS:[STACK_PTR+TransFixup]
		LEA EAX, DWORD PTR SS:[STACK_PTR+RotFixup]
		PUSH EDX
		PUSH EAX
		CALL RotateFunc
		ADD ESP, 8
		MOV DWORD PTR SS:[STACK_PTR+TransFixup+0x0C], 0xC1E00000
		MOV DWORD PTR SS:[STACK_PTR+TransFixup+0x1C], 0
		MOV DWORD PTR SS:[STACK_PTR+TransFixup+0x2C], 0xC1C80000
		// ----
		JMP FLIP_CHECK
		// ----
		CHECK_SHIELD_6:
		// ----
		CMP WEAPON_ID_CONTAINER, ITEM(6, 6) + OBJ_OFFS
		JNZ SET_SHIELD
		// ----
		MOV DWORD PTR SS:[STACK_PTR+RotFixup], 0x41F00000
		MOV DWORD PTR SS:[STACK_PTR+RotFixup+4], 0
		MOV DWORD PTR SS:[STACK_PTR+RotFixup+8], 0x42B40000
		LEA EDX, DWORD PTR SS:[STACK_PTR+TransFixup]
		LEA EAX, DWORD PTR SS:[STACK_PTR+RotFixup]
		PUSH EDX
		PUSH EAX
		CALL RotateFunc
		ADD ESP, 8
		MOV DWORD PTR SS:[STACK_PTR+TransFixup+0x0C], 0xC1700000
		MOV DWORD PTR SS:[STACK_PTR+TransFixup+0x1C], 0
		MOV DWORD PTR SS:[STACK_PTR+TransFixup+0x2C], 0xC1C80000
		// ----
		JMP FLIP_CHECK
		// ----
		SET_SHIELD:
		// ----
		MOV DWORD PTR SS:[STACK_PTR+TransFixup+0x0C], 0xC1200000
		MOV DWORD PTR SS:[STACK_PTR+TransFixup+0x1C], 0
		MOV DWORD PTR SS:[STACK_PTR+TransFixup+0x2C], 0
		// ----
		FLIP_CHECK:
		CMP IsShield, 1
		JE EXIT
		CMP SecondWeaponFixVal, 0
		JE EXIT
		SUB ESP, 0x3C
		MOV DWORD PTR SS:[ESP+0x30], 0x43110000
		MOV DWORD PTR SS:[ESP+0x34], 0
		MOV DWORD PTR SS:[ESP+0x38], 0x43898000
		LEA EAX, DWORD PTR SS:[ESP]
		LEA ECX, DWORD PTR SS:[ESP+0x30]
		PUSH EAX
		PUSH ECX
		CALL RotateFunc
		ADD ESP, 8
		// ----
		MOV DWORD PTR SS:[ESP+0x0C], 0
		MOV DWORD PTR SS:[ESP+0x1C], 0x41200000
		MOV DWORD PTR SS:[ESP+0x2C], 0xC1F00000
		LEA EDX, DWORD PTR SS:[STACK_PTR+TransFixup]
		LEA EAX, DWORD PTR SS:[ESP]
		LEA ECX, DWORD PTR SS:[STACK_PTR+TransFixup]
		PUSH EDX
		PUSH EAX
		PUSH ECX
		CALL TransFunc
		ADD ESP, 0x48
		// ----
		EXIT:
		PUSH SomeVal4
		JMP SecondWeaponViewFix_Ret
	}
}
//---------------------------------------------------------------------------


