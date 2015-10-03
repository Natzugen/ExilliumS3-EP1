#include "StdAfx.h"

// Client Login Addon
void CGClientMsgEx(int aIndex)
{
	if(OnlineStatus(aIndex) == true)
	{
		// Connect Message
		SYSTEMTIME t;
		GetLocalTime(&t); 

		// Get Online
		int TotalPlayers = GetPlayerCount();

		// Get Resets
		MySQL.Execute("SELECT Resets FROM Character WHERE Name = '%s'", gObj[aIndex].Name);
		AddTab[aIndex].m_Resets = MySQL.GetInt();

		// Messages
		MsgOutputSystem(aIndex,"[SYSTEM] Online: %d", TotalPlayers);
		MsgOutputSystem(aIndex,"[SYSTEM] Server Time: %02d:%02d", t.wHour, t.wMinute);
		MsgOutputSystem(aIndex,"[SYSTEM] Resets: %d", AddTab[aIndex].m_Resets);
	}
}