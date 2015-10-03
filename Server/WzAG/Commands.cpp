#include "StdAfx.h"

// Custom Commands
void MakeCommand(int aIndex,char* Message)
{
	if(!_strcmpi("/make",Message))
	{
		GCServerMsgStringSend("Usage: /make <type> <index> <lvl> <skill> <luck> <opt> <exc>",aIndex,1);
		return;
	}

	if(strlen(Message) < 1)
	{
		GCServerMsgStringSend("Usage: /make <type> <index> <lvl> <skill> <luck> <opt> <exc>",aIndex,1);
		return;
	}

	int Spaces = 0;

	for(int i = 0; i < strlen(Message); i++)
	{
		if(Message[i] == ' ')
		{
			Spaces++;
		}
	}

	if(Spaces < 6)
	{
		GCServerMsgStringSend("Please re-check the code string you gave.",aIndex,1);
		return;
	}

	int ItemType,ItemNr,ItemLevel,ItemSkill,ItemLuck,ItemOpt,ItemExc;
	sscanf(Message,"%d %d %d %d %d %d %d",&ItemType,&ItemNr,&ItemLevel,&ItemSkill,&ItemLuck,&ItemOpt,&ItemExc);

	DWORD Item = ItemType * 512 + ItemNr;

	ItemSerialCreateSend(aIndex,gObj[aIndex].MapNumber,gObj[aIndex].X,gObj[aIndex].Y,Item,ItemLevel,0,ItemSkill,ItemLuck,ItemOpt,aIndex,ItemExc,0);
	
	GCServerMsgStringSend("Item created successfully.",aIndex,1);
}

void InitCommands(int aIndex,unsigned char* Protocol)
{
	/*char CommandMake[] = "/make";
	if(!memcmp(&Protocol[13],CommandMake,strlen(CommandMake)))
	{
		MakeCommand(aIndex,(char*)Protocol+13+strlen(CommandMake));
	}*/
}