#include "StdAfx.h"

// Security
CSecurity Security;

bool CSecurity::Init()
{
	unsigned char MACData[6];
	UUID uuid;
	UuidCreateSequential( &uuid ); 

	for (int i=2; i<8; i++) 
		MACData[i - 2] = uuid.Data4[i];

	char MACADDR[18];
	sprintf(MACADDR, "%02X-%02X-%02X-%02X-%02X-%02X", MACData[0], MACData[1], MACData[2], MACData[3], MACData[4], MACData[5]);

	if(Checking(MACADDR))
	{
		return true;
	}
	else
	{
		MessageBoxA(NULL,"You don't have license to use these files!","Error!",MB_OK);
		::ExitProcess(0);
	}
	return false;
}

bool CSecurity::Checking(LPCSTR MacID)
{
	char ClientsMacs[MacCount][18] =
	{
		"6C-F0-49-0B-05-35", // NexT
		"00-50-56-3C-14-3C" // Windows Server 2008
	};

	for(int x=0; x<MacCount; x++)
	{
		if(!strcmp(MacID,ClientsMacs[x]))
		{
			return true;
		}
	}
	return false;
}