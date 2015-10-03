#include "StdAfx.h"

// Plugin Initializer
extern "C" _declspec(dllexport) void Load()
{
	DWORD OldProtect;
	if(VirtualProtect(LPVOID(0x401000), 0x00746FFF,PAGE_EXECUTE_READWRITE,&OldProtect))
	{
		// Security
		Security.Init();
			
		// SQL Connection
		MySQL.Load();

		// Fixes
		MiscellaneousFixes();

		// GameServer Load Addon
		ReadCommonServerInfoEx();

		// Protocol Core Addon
		*(DWORD*)(0x00403BA7+1) = (DWORD)&ProtocolCoreEx - (0x00403BA7+5);

		// Monster Item Drop
		*(DWORD*)((0x00405402+1)) = (DWORD)&MygEventMonsterItemDrop - (0x00405402+5);

		// Protocol Converter
		_asm
		{
			MOV DWORD PTR DS:[00700000H],Offset ServerProtocol;
			MOV DWORD PTR DS:[00700004H],Offset ClientProtocol;
		}
	}
	else
	{
		MessageBoxA(NULL,"Unable to initialize Exillum.dll","Error",MB_OK);
		ExitProcess(0);
	}
}