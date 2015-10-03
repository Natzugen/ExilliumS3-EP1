#include "StdAfx.h"

// Custom Jewels
CCustomJewels CustomJewels;

void CCustomJewels::CGUseItemRecv(PMSG_USEITEM *lpMsg, int aIndex)
{
	OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);

	// Jewel Of Wind [Luck in weapons]
	if (gObj->pInventory[lpMsg->inventoryPos].m_Type == ITEMGET(14,101))
	{
		if(gObj->pInventory[lpMsg->inventoryTarget].m_Option2 != 1)
		{
			gObj->pInventory[lpMsg->inventoryTarget].m_Option2 = 1;
			gObjInventoryItemSet(aIndex,lpMsg->inventoryPos, -1);
			ItemClear(aIndex,lpMsg->inventoryPos);
			GCInventoryItemOneSend(aIndex, lpMsg->inventoryTarget);
			GCInventoryItemDeleteSend(aIndex, lpMsg->inventoryPos, 1);	
		}

		return;
	}
}

void CCustomJewels::ItemClear(int aIndex, int Pos)	
{	
	OBJECTSTRUCT * gObj = (OBJECTSTRUCT*) OBJECT_POINTER (aIndex);

	memset(gObj->pInventory[Pos].m_Special, 0, sizeof(gObj->pInventory[Pos].m_Special));
	memset(gObj->pInventory[Pos].m_SpecialValue, 0, sizeof(gObj->pInventory[Pos].m_SpecialValue));
	memset(gObj->pInventory[Pos].m_Resistance, 0, sizeof(gObj->pInventory[Pos].m_Resistance));

	gObj->pInventory[Pos].m_Type =-1;
	gObj->pInventory[Pos].m_Level =0;
	gObj->pInventory[Pos].m_Part=0;
	gObj->pInventory[Pos].m_Class=0;
	gObj->pInventory[Pos].m_TwoHand=0;
	gObj->pInventory[Pos].m_AttackSpeed=0;
	gObj->pInventory[Pos].m_DamageMin=0;
	gObj->pInventory[Pos].m_DamageMax=0;
	gObj->pInventory[Pos].m_SuccessfulBlocking=0;
	gObj->pInventory[Pos].m_Defense=0;
	gObj->pInventory[Pos].m_MagicDefense =0;
	gObj->pInventory[Pos].m_Durability=0;
	gObj->pInventory[Pos].m_SpecialNum=0;
	gObj->pInventory[Pos].m_Value=0;
	gObj->pInventory[Pos].m_Option1 =0;      
	gObj->pInventory[Pos].m_Option2 =0;  
	gObj->pInventory[Pos].m_SetOption =0;   
	gObj->pInventory[Pos].m_Number =0;
	gObj->pInventory[Pos].m_DurabilitySmall =0;
	gObj->pInventory[Pos].m_iPShopValue=-1;
	gObj->pInventory[Pos].m_bItemExist=true;
	gObj->pInventory[Pos].m_CurrentDurabilityState=-1;
	gObj->pInventory[Pos].m_SetOption=0;
	gObj->pInventory[Pos].m_QuestItem=false;
	gObj->pInventory[Pos].m_IsLoadPetItemInfo=0;
	gObj->pInventory[Pos].m_PetItem_Level =1;
	gObj->pInventory[Pos].m_PetItem_Exp =0;
	gObj->pInventory[Pos].m_Leadership=0;
	gObj->pInventory[Pos].m_JewelOfHarmonyOption = 0;
	gObj->pInventory[Pos].m_ItemOptionEx = 0;
}