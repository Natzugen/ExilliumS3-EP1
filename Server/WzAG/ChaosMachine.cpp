#include "StdAfx.h"

// Chaos Machine
CChaosMachine ChaosMachine;

void CChaosMachine::Init()
{
	this->m_MixRate = GetPrivateProfileInt("Customs","GoldenFenrirMixRate",80,CUSTOM_PATH);
}

void CChaosMachine::ChaosMixFailSend(int aIndex)
{
	ChaosBoxInit(OBJECT_BASE + (OBJECT_SIZE * aIndex));
	GCUserChaosBoxSend(OBJECT_BASE + (OBJECT_SIZE * aIndex),0);

	char Buffer[11] = {0xC1,0x0B,0x86,0,0,0,0,0,0,0,0};
	DataSend(aIndex,(PBYTE)Buffer,Buffer[1]);
}

int CChaosMachine::GetChaosItemLevel(int aIndex,int Item)
{
	DWORD * Inventory = (DWORD*) (OBJECT_BASE + (OBJECT_SIZE * aIndex) + gObjChaosMixBox);

	for(BYTE i = 0; i < 32; i++)
	{
		WORD * pItem = (WORD*) ((i * gObjItemSize) + *Inventory + 6);
		
		if(*pItem == Item) 
		{
			WORD * pItemByte = (WORD*) ((i * gObjItemSize) + *Inventory + 8);
			return *pItemByte;
		}
	}

	return 0xFF;
}

int CChaosMachine::CheckChaosItem(int aIndex,int Item)
{
	DWORD * Inventory = (DWORD*) (OBJECT_BASE + (OBJECT_SIZE * aIndex) + gObjChaosMixBox);

	for(BYTE i = 0; i < 32; i++)
	{
		WORD * pItem = (WORD*) ((i * gObjItemSize) + *Inventory + 6);

		if(*pItem == Item) 
		{
			return 1;
		}
	}

	return 0;
}

int CChaosMachine::CheckChaosItemRange(int aIndex,int ItemMin,int ItemMax)
{
	DWORD * Inventory = (DWORD*) (OBJECT_BASE + (OBJECT_SIZE * aIndex) + gObjChaosMixBox);

	for(BYTE i = 0; i < 32; i++)
	{
		WORD * pItem = (WORD*) ((i * gObjItemSize) + *Inventory + 6);

		if((*pItem >= ItemMin) && (*pItem <= ItemMax))
		{
			return 1;
		}
	}

	return 0;
}

int CChaosMachine::GetChaosItemRange(int aIndex,int ItemMin,int ItemMax)
{
	DWORD * Inventory = (DWORD*) (OBJECT_BASE + (OBJECT_SIZE * aIndex) + gObjChaosMixBox);

	for(BYTE i = 0; i < 32; i++)
	{
		WORD * pItem = (WORD*) ((i * gObjItemSize) + *Inventory + 6);

		if((*pItem >= ItemMin) && (*pItem <= ItemMax))
		{
			return *pItem;
		}
	}

	return -1;
}

int CChaosMachine::GetChaosItemCount(int aIndex,int Item)
{
	DWORD * Inventory = (DWORD*) (OBJECT_BASE + (OBJECT_SIZE * aIndex) + gObjChaosMixBox);
	int Count = 0;

	for(BYTE i = 0; i < 32; i++)
	{
		WORD * pItem = (WORD*) ((i * gObjItemSize) + *Inventory + 6);

		if(*pItem == Item) 
		{
			Count++;
		}
	}

	return Count;
}


void CChaosMachine::ChaosBoxHook(int aIndex,int MixNumber) 
{
	OBJECTSTRUCT* gObj = (OBJECTSTRUCT*)(aIndex * OBJECT_SIZE + OBJECT_BASE);

	switch(MixNumber)
	{
		// Golden Fenrir
		case 0x87:
		{
			int Success = this->m_MixRate;

			if(Success < 0)
			{
				Success = 0;
			}

			int CombinationPrice = 500000000;

			if(CombinationPrice < 0)
			{
				CombinationPrice = 0;
			}

			int CheckChaosJewel = CheckChaosItem(aIndex,0x180F);
			int CheckCreationJewel = CheckChaosItem(aIndex,0x1C16);
			int CheckSoulPack = CheckChaosItem(aIndex,0x181F);
			int CheckBlessPack = CheckChaosItem(aIndex,0x181E);
			int CheckFenrir = CheckChaosItem(aIndex,0x1A25);

			int CombinationCheckSum = CheckChaosJewel + CheckCreationJewel + CheckSoulPack + CheckBlessPack + CheckFenrir;

			if(CombinationCheckSum >= 5)
			{
				Log.Add("[GoldenFenrir] Chaos Mix Start");
				srand(static_cast < int > (time(NULL)));

				if(gObj->Money < CombinationPrice)
				{
					Log.AddTime("[GoldenFenrir] [%s][%s] CBMix Not Enough Money [%d] need zen [%d]", gObj->AccountID, gObj->Name, gObj->Money, CombinationPrice);
					return;
				}
	
				if ((rand() % 100) < Success)
				{
					gObjWrite(aIndex,gObjZen,gObjGetInt(aIndex,gObjZen) - CombinationPrice);
					GCMoneySend(aIndex,gObjGetInt(aIndex,gObjZen));
					ItemSerialCreateSend(aIndex,0xFF,0,0,0x1A25,0,255,1,0,0,-1,4,0);

					Log.AddTime("[GoldenFenrir] [%s][%s] CBMix Success %d Money : %d", gObj->AccountID, gObj->Name, Success, gObj->Money);
				}
				else
				{
					gObjWrite(aIndex,gObjZen,gObjGetInt(aIndex,gObjZen) - CombinationPrice);
					GCMoneySend(aIndex,gObjGetInt(aIndex,gObjZen));
					ChaosMixFailSend(aIndex);
					
					Log.AddTime("[GoldenFenrir] [%s][%s] CBMix Fail %d Money : %d", gObj->AccountID, gObj->Name, Success, gObj->Money);
				}
			}
			else
			{
				GCMoneySend(aIndex,gObjGetInt(aIndex,gObjZen));
				ChaosMixFailSend(aIndex);
			}
		}
		break;
	}
}