#include "StdAfx.h"

// Guild System
CGuildSystem GuildSystem;

void CGuildSystem::Init()
{
	this->m_Enabled = GetPrivateProfileInt("GuildSystem","Enabled",1,CUSTOM_PATH);
	this->m_Price = GetPrivateProfileInt("GuildSystem","CreatePrice",100000000,CUSTOM_PATH);
	this->m_MaxGuilds = GetPrivateProfileInt("GuildSystem","MaxGuildCount",15,CUSTOM_PATH);
}

void CGuildSystem::Check(int aIndex, PMSG_GUILDINFOSAVE *lpMsg)
{
	OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);

	MySQL.Execute("SELECT count(*) FROM Guild");
	int Count = MySQL.GetInt();

	if(Count >= this->m_MaxGuilds)
	{
		MsgOutputSystem(aIndex,"Извини но на сервере и так достаточно гильдий!");
		return;
	}

	if(gObj->Money < this->m_Price)
	{
		MsgOutputSystem(aIndex,"Для создания гильдии требуется %d Zen.",this->m_Price);
		return;
	}

	gObjWrite(aIndex,gObjZen,gObjGetInt(aIndex,gObjZen) - this->m_Price);
	GCMoneySend(aIndex,gObjGetInt(aIndex,gObjZen));
	CGGuildMasterInfoSave(aIndex, lpMsg);
}