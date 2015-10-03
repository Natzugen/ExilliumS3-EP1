#include "StdAfx.h"

void SetByte(DWORD NewOffset,BYTE NewByte)
{
	*(BYTE*)(NewOffset) = NewByte;
}

void SetJNZ(DWORD NewOffset)
{
	*(BYTE*)(NewOffset) = 0x75;
}

void SetJE(DWORD NewOffset)
{
	*(BYTE*)(NewOffset) = 0x74;
}

void SetJMP(DWORD NewOffset)
{
	*(BYTE*)(NewOffset) = 0xEB;
}

void SetNop(DWORD NewOffset,int Size)
{
	for(int n = 0; n < Size; n++)
	{
		*(BYTE*)(NewOffset+n) = 0x90;
	}
}

void SetRetn(DWORD NewOffset)
{
	*(BYTE*)(NewOffset) = 0xC3;
}

void FunctionHook(DWORD NewOffset,DWORD JumpOffset)
{
	*(DWORD*)(JumpOffset+1) = NewOffset - (JumpOffset+5);
}

void gObjGetNick(int aIndex,char* Nick)
{
	memcpy(Nick,(char*)(OBJECT_BASE + (OBJECT_SIZE * aIndex) + gObjNick),11);
}

long int gObjGetInt(int aIndex,int gObjParam)
{
	return *(long int*)(aIndex * OBJECT_SIZE + OBJECT_BASE + gObjParam);
}

void gObjWrite(int aIndex,int gObjParam,long int Value)
{
	*(long int*)(aIndex * OBJECT_SIZE + OBJECT_BASE + gObjParam) = Value;
}

void MsgOutput(int aIndex,char* Message,...)
{
	char Packet[512]="";
	va_list pArguments;
	va_start(pArguments,Message);
	vsprintf(&Packet[0],Message,pArguments);
	va_end(pArguments);
	GCServerMsgStringSend(&Packet[0],aIndex,1);
}

void MsgOutputSystem(int aIndex,char* Message,...)
{
	char szPacket[1024];
	va_list pArguments;
	va_start(pArguments,Message);
	vsprintf(szPacket,Message,pArguments);
	va_end(pArguments);
	BYTE Packet[0xFF] = {0};
	BYTE Len = (strlen(szPacket) + 0x13);
	Packet[0] = 0xC1;
	Packet[1] = Len+15;
	Packet[2] = 0x00;
	Packet[13] = 0x40;
	strncpy((char*)&Packet[14],szPacket,strlen(szPacket));
	DataSend(aIndex,Packet,Packet[1]);
/*

	char szPacket[1024];
	va_list pArguments;
	va_start(pArguments,Message);
	vsprintf(szPacket,Message,pArguments);
	va_end(pArguments);
	BYTE Packet[0xFF] = {0};
	BYTE Len = (strlen(szPacket) + 0x13);
	Packet[0] = 0xC1;
	Packet[1] = Len+15;
	Packet[2] = 0x00;
	Packet[13] = 0x7E;
	strncpy((char*)&Packet[14],szPacket,strlen(szPacket));
	DataSend(aIndex,Packet,Packet[1]);*/
}

int OnlineStatus(int aIndex)
{
	if(aIndex >= OBJECT_MIN && aIndex < OBJECT_MAX)
	{
		if(gObj[aIndex].Connected == 3)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

int VerifyGM(int aIndex)
{
	if(*(short int*)(aIndex * OBJECT_SIZE + OBJECT_BASE + gObjCtl) == 32 || *(short int*)(aIndex * OBJECT_SIZE + OBJECT_BASE + gObjCtl) == 8)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int GetPlayerCount()
{
	int Players = 0;
	
	for(int i = OBJECT_MIN; i < OBJECT_MAX; i++)
	{
		if(OnlineStatus(i))
		{
			Players++;
		}
	}
	return Players;
}

int GetGMCount()
{
	int GameMasters = 0;

	for(int i = OBJECT_MIN; i < OBJECT_MAX; i++)
	{
		if(OnlineStatus(i))
		{
			if(VerifyGM(i))
			{
				GameMasters++;
			}
		}
	}
	return GameMasters;
}