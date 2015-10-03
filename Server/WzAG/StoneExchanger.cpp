#include "StdAfx.h"

// Stone Exchanger
CExchanger Exchanger;

void CExchanger::Init()
{
	this->m_Enabled = GetPrivateProfileInt("StoneExchanger","Enabled",1,CUSTOM_PATH);
	this->m_Count = GetPrivateProfileInt("StoneExchanger","StonesCount",3,CUSTOM_PATH);
}

int CExchanger::CheckStones(int aIndex)
{
	int Count = 0;

	for(int i = 12; i < 76; i++)
	{
		if(gObj[aIndex].pInventory[i].m_Type == 0x1C15 && gObj[aIndex].pInventory[i].m_Level == 1)
		{
			Count++;
		}
	}

	return Count;
}

void CExchanger::Talk(int aIndex,int Monster)
{
	if(gObj[Monster].Class == 501) // Stone Exchanger
	{
		ChatTargetSend(&gObj[Monster],"I am collecting Stones, bring them to me if you find one.",aIndex);

		if(this->m_Enabled == 0)
		{
			return;
		}

		if(OnlineStatus(aIndex) == 0)
		{
			return;
		}
		
		int Stones = CheckStones(aIndex);

		if(Stones < this->m_Count)
		{
			char Need[50];
			sprintf(Need,"You neeed more %d Stones to exchange.", this->m_Count - Stones);
			ChatTargetSend(&gObj[Monster],Need,aIndex);
			return;
		}

		int Count = 1;

		for(int i = 12; i < 76; i++)
		{

			if(gObj[aIndex].pInventory[i].m_Type == 0x1C15 && gObj[aIndex].pInventory[i].m_Level == 1)
			{
				if(Count <= 3)
				{
					Count += 1;
					gObjInventoryDeleteItem(aIndex, i);
					GCInventoryItemDeleteSend(aIndex, i, 1);
				}
			}
		}

		GCLevelUpMsgSend(aIndex,1);
		ChatTargetSend(&gObj[Monster], "Thank you for stones! Take my credit.", aIndex);
		MySQL.Execute("UPDATE [MuOnline].[dbo].[MEMB_CREDITS] SET Credits = Credits + 1  WHERE memb___id = '%s'", gObj[aIndex].AccountID);
		Log.AddTime("[StoneExchanger] (%s)(%s) Exchanged Stones, Map:[%d]", gObj[aIndex].AccountID, gObj[aIndex].Name, gObj[aIndex].MapNumber);
	}
}