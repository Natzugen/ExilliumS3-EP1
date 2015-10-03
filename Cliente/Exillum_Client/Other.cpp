#include "stdafx.h"
#include "Other.h"
#include "Define.h"
#include "AntiHack.h"
#include "TMemory.h"

DWORD dwChatColorSet_Pointer;
DWORD dwChatColorSet_Color;
DWORD dwChatColorSet_Background;
DWORD dwChatColorSet_Stack;
DWORD dwObjectPointer_Pointer;

int * GameState	= (int*) (iGameState);
int * Object_Char = (int*) (ObjectType_Player);
int * Object_NPC = (int*) (ObjectType_NPC);

Naked(cFrameView)
{
	Sleep(1);

	_asm
	{
		mov esi, iFrameView_Return
		jmp esi
	}
}

Naked (cChatColorSet)
{
	_asm
	{
		mov dwChatColorSet_Pointer, ecx
	}
	// ----
	switch ( dwChatColorSet_Pointer )
	{
		case 10: // Chocolate
			dwChatColorSet_Color		= 0xff1e69d2;
			dwChatColorSet_Background	= 0x92000000;
		break;
		// ----
		case 9: // Gold
			dwChatColorSet_Color		= 0xFF20A5DA;
			dwChatColorSet_Background	= 0x92000000;
		break;
		// ----
		case 11: // Green
			dwChatColorSet_Color		= 0xff14F0BE;
			dwChatColorSet_Background	= 0x92000000;
		break;
	}
	// ----
	_asm
	{
		JNE Exit
		mov esi, dwChatColorSet_Color
		mov dword ptr ds:[iChatColor], esi
		mov esi, dwChatColorSet_Background
		mov dword ptr ds:[iChatBackground], esi
		// ----
		Exit:
		mov dwChatColorSet_Stack, iChatAllow
		jmp dwChatColorSet_Stack
	}
}

Naked (cObjectPointer)
{
	_asm
	{
		mov dwObjectPointer_Pointer, ebp
	}
	// ----
	if( * GameState == IndexState::SwitchCharacter )
	{
		_asm
		{
			je Return	
		}
	}
	// ----
	if( dwObjectPointer_Pointer == * Object_Char )
	{
		_asm
		{
			je NotDirect
		}
	}
	// ----
	_asm
	{
		Return:
		mov al, byte ptr ss:[ebp + 0x46c]
		mov esi, iObjectPointer_Return
		jmp esi
		// ----
		NotDirect:
		mov esi, iObjectPointer_Skip
		jmp esi
	}
}

void Changer()
{
	BYTE MoveListFix[] = { 0xEB, 0x28 };
	WriteMemory( (PVOID) iMoveListFix, & MoveListFix, sizeof( MoveListFix ) );
	// ----
	BYTE NewCharSet[] = { 0xD4 };
	WriteMemory( (PVOID) CharSet1, & NewCharSet, sizeof( NewCharSet ) );
	WriteMemory( (PVOID) CharSet2, & NewCharSet, sizeof( NewCharSet ) );
	WriteMemory( (PVOID) CharSet3, & NewCharSet, sizeof( NewCharSet ) );
	WriteMemory( (PVOID) CharSet4, & NewCharSet, sizeof( NewCharSet ) );
	WriteMemory( (PVOID) CharSet5, & NewCharSet, sizeof( NewCharSet ) );
	WriteMemory( (PVOID) CharSet6, & NewCharSet, sizeof( NewCharSet ) );
	// ----
	SetByte( (PVOID) iCSkill_Unlock1, 0x2B);
	SetByte( (PVOID) iCSkill_Unlock2, 0x26);
	SetByte( (PVOID) iCSkill_Unlock3, 0x21);
	SetByte( (PVOID) iCSkill_Unlock4, 0x1C);
	SetByte( (PVOID) iCSkill_Unlock5, 0x17);
	SetByte( (PVOID) iCSkill_Unlock6, 0xEB);
	// ----
	SetByte( (PVOID) iCSkill_RemoveMsg1, 0x00);
	SetByte( (PVOID) iCSkill_RemoveMsg2, 0x00);
	SetByte( (PVOID) iCSkill_RemoveMsg3, 0x00);
	SetByte( (PVOID) iCSkill_RemoveMsg4, 0x00);
	SetByte( (PVOID) iCSkill_RemoveMsg5, 0x00);
	SetByte( (PVOID) iCSkill_RemoveMsg6, 0x00);
	// ----
	SetByte( (PVOID) iCSkill_SetIcon1, 0x3C);
	SetByte( (PVOID) iCSkill_SetIcon2, 0x37);
	SetByte( (PVOID) iCSkill_SetIcon3, 0x32);
	SetByte( (PVOID) iCSkill_SetIcon4, 0x2D);
	SetByte( (PVOID) iCSkill_SetIcon5, 0x28);
	SetByte( (PVOID) iCSkill_SetIcon6, 0xEB);	
	// ----
	char cWindowName[18] = {"EXILLUM.RU - MAIN"};
	WriteMemory( (PVOID) WindowName, cWindowName, sizeof( cWindowName ) );
	// ----
	char cAdress[20];
	sprintf(cAdress, "%s", SERVER_ADRESS);
	WriteMemory( (PVOID) ConnectAdress, cAdress, sizeof( cAdress ) );
	// ----
	char cSerial[17];
	sprintf(cSerial, "%s", MAIN_SERIAL);
	WriteMemory( (PVOID) ClientExeSerial, cSerial, sizeof( cSerial ) );
	// ----
	*(BYTE*)(0x006CA535 + 1) = 9;
	*(BYTE*)(0x006BEF2E)  = 0xEB;
}

void FindHacks()
{
	while (true)
	{
		SystemProcessesScan();
		Sleep(2000);
	}
}

void CustomsLoad()
{
/*	char * Temp = GetCommandLineA();
	if(!strstr(Temp,"connect"))
	{
		MessageBoxA(0,"Please use lancher!","Error",0);
		ExitProcess(0);
	}*/

	Changer();
	// ----
	SetRange((LPVOID) iChatSetColor, 6, ASM::NOP);
	SetJa((LPVOID) iChatSetColor, cChatColorSet);
	// ----
	SetByte((PVOID) iFrameView_Jmp, 0xD1);
	SetRange((LPVOID) iFrameView_Sleep, 18, ASM::NOP);
	SetJmp((LPVOID) iFrameView_Sleep, cFrameView);
	// ----
	SetJmp((LPVOID) iObjectPointer, cObjectPointer);
	
/*	SystemProcessesScan();
	DWORD MyId;
	CreateThread(NULL,NULL,(LPTHREAD_START_ROUTINE)FindHacks,NULL,0,&MyId);*/
}