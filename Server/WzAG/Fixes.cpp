#include "StdAfx.h"

void MiscellaneousFixes()
{
	// Max Zen
	*(DWORD*)(0x0055CAD7 + 3) = 2000000000;
	*(DWORD*)(0x00564B06 + 3) = 2000000000;
	*(DWORD*)(0x00564B32 + 2) = 2000000000;
	*(DWORD*)(0x00564BFC + 3) = 2000000000;
	*(DWORD*)(0x00596F64 + 3) = 2000000000;

	// Anc + Exc
	SetJMP(0x005F31B6); 

	// GameServer Title
	char cTemp[30] = "[EXILLUM GAMESERVER]";
    DWORD *offsetGSTitle = (DWORD*)(0x0076C708);
    memset(&offsetGSTitle[0],0,30);
    memcpy(&offsetGSTitle[0],cTemp,strlen(cTemp));

	// GameServer Title Color
	*(unsigned int*)(0x005A43B7+1) = 0x0074CF;
}

// GameServer Load Addon
void ReadCommonServerInfoEx()
{
	// Chaos Machine
	ChaosMachine.Init();

	// Stone Exchanger
	Exchanger.Init();

	// Guild System
	GuildSystem.Init();
}

bool MygEventMonsterItemDrop(OBJECTSTRUCT* gObj, OBJECTSTRUCT* gTargetObj)
{
	// Multi Drop System
	if (gObj->Class == 54 || gObj->Class == 81 || gObj->Class == 83 || gObj->Class == 80 || gObj->Class == 82)	// Golden Soldier,Vepar,Wheel
	{
		int MaxHitUser = gObjMonsterTopHitDamageUser(gObj);
		unsigned int Rena = 14 * 512 + 21;

		// Drop
		ItemSerialCreateSend (gObj->m_Index,gObj->MapNumber,gObj->X-1,gObj->Y,Rena,0,0,0,0,0,MaxHitUser,0,0);

		// Log
		Log.Add("[MultiDrop] (%s)(%s) Killed Golden Soldier (%d)!",gTargetObj->AccountID,gTargetObj->Name,gObj->Class);
		return true;
	}

	// Zen Drop
	if(gObj->Money > 0)
    {
		DWORD SubMoney = 0;

		if(gObj->Level > 10 && gObj->Level <= 99)
		{
			SubMoney = (DWORD)(gObj->Money) / 100;
		}
		else if(gObj->Level >= 100 && gObj->Level <= 199)
		{
			SubMoney = (DWORD)(gObj->Money * 2) / 100;
		}
		else if(gObj->Level > 200)
		{
			SubMoney = (DWORD)(gObj->Money * 3) / 100;
		}

		gObj->Money = (gObj->Money - SubMoney) * 0.1;
	}

	return gEventMonsterItemDrop(gObj,gTargetObj);
}