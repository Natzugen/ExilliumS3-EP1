#include "StdAfx.h"



void InitCommands(int aIndex,unsigned char* Protocol)
{
	char CommandMake[] = "/Item";
	
	if(!memcmp(&Protocol[13],CommandMake,strlen(CommandMake)))
	{
		ChatDrop(aIndex,(char*)Protocol+13+strlen(CommandMake));
	}
}

// Custom Commands
void ChatDrop(DWORD gObjId, char* msg)
{
	OBJECTSTRUCT * gObj = (OBJECTSTRUCT*)OBJECT_POINTER(gObjId);

	//========================================================================================================================
	if (gObj->Authority != 32)
	{
		MsgOutput(gObjId, "[Item] : Command only for GM's");
		return;
	}

	//========================================================================================================================

	int ItemType = 0, ItemNr = 0, ItemLevel = 0, ItemSkill = 0, ItemLuck = 0, ItemOpt = 0, ItemExc = 0, ItemDur = 0, ItemAncient = 0;
	sscanf_s(msg, "%d %d %d %d %d %d %d %d %d", &ItemType, &ItemNr, &ItemLevel, &ItemDur, &ItemSkill, &ItemLuck, &ItemOpt, &ItemExc, &ItemAncient);

	DWORD Item = ItemType * 512 + ItemNr;

	ItemSerialCreateSend(gObjId, gObj->MapNumber, gObj->X, gObj->Y, Item, ItemLevel, ItemDur, ItemSkill, ItemLuck, ItemOpt, gObjId, ItemExc, 0);
	MsgOutput(gObjId, "[Item] : Created %d %d %d %d %d %d %d %d %d", ItemType, ItemNr, ItemLevel, ItemDur, ItemSkill, ItemLuck, ItemOpt, ItemExc, ItemAncient);
}
