#include "StdAfx.h"

// Experience System
CExpSystem ExpSystem;

long ExpCalculator(OBJECTSTRUCT* gObj,int Experience)
{
	double BonusExperience = 0;

	if(AddTab[gObj->m_Index].m_Resets >= 0 && AddTab[gObj->m_Index].m_Resets <= 10)
	{				
		BonusExperience = 1;
	}
	else if(AddTab[gObj->m_Index].m_Resets > 10 && AddTab[gObj->m_Index].m_Resets <= 20)
	{				
		BonusExperience = 0.9;
	}
	else if(AddTab[gObj->m_Index].m_Resets > 30 && AddTab[gObj->m_Index].m_Resets <= 40)
	{				
		BonusExperience = 0.8;
	}
	else if(AddTab[gObj->m_Index].m_Resets > 40 && AddTab[gObj->m_Index].m_Resets <= 50)
	{				
		BonusExperience = 0.7;
	}
	else if(AddTab[gObj->m_Index].m_Resets > 50 && AddTab[gObj->m_Index].m_Resets <= 60)
	{				
		BonusExperience = 0.6;
	}
	else if(AddTab[gObj->m_Index].m_Resets > 60 && AddTab[gObj->m_Index].m_Resets <= 70)
	{				
		BonusExperience = 0.5;
	}
	else if(AddTab[gObj->m_Index].m_Resets > 70 && AddTab[gObj->m_Index].m_Resets <= 80)
	{				
		BonusExperience = 0.4;
	}
	else if(AddTab[gObj->m_Index].m_Resets > 80 && AddTab[gObj->m_Index].m_Resets <= 90)
	{				
		BonusExperience = 0.3;
	}
	else if(AddTab[gObj->m_Index].m_Resets > 90 && AddTab[gObj->m_Index].m_Resets <= 95)
	{				
		BonusExperience = 0.2;
	}
	else if(AddTab[gObj->m_Index].m_Resets > 95 && AddTab[gObj->m_Index].m_Resets <= 100)
	{				
		BonusExperience = 0.1;
	}

	return (Experience * BonusExperience);
}

__declspec(naked) void MonsterExpSingleEx()
{
    _asm
	{
		MOV EAX,DWORD PTR SS:[EBP-0x04];
		PUSH EAX;
		MOV EDX,DWORD PTR SS:[EBP+0x08];
		PUSH EDX;
		CALL [ExpCalculator];
		MOV DWORD PTR SS:[EBP-0x04],EAX;
		MOV EBX,0x004E2C66;
        JMP EBX;
	}
}

__declspec(naked) void MonsterExpPartyEx()
{
    _asm
	{
        MOV EAX,DWORD PTR SS:[EBP-0x08];
		PUSH EAX;
		MOV EDX,DWORD PTR SS:[EBP-0x54];
		PUSH EDX;
		CALL [ExpCalculator];
		MOV DWORD PTR SS:[EBP-0x08],EAX;
		MOV EBX,0x004E335B;
		JMP EBX;
	}
}