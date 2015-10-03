#pragma once
//---------------------------------------------------------------------------

#define iDataRecvCustom		0x00509F6D
#define iDataRecvOriginal	0x0050A070
// ----
#define iFrameSpeed			0x007B3A4C
//---------------------------------------------------------------------------

#define DataRecv ( ( void(*) (DWORD protoNum, BYTE * aRecv, int aLen, int aIndex) ) iDataRecvOriginal)
//---------------------------------------------------------------------------

 struct PBMSG_HEAD   
{
	BYTE c;
	BYTE size;
	BYTE headcode;
};
//---------------------------------------------------------------------------

struct PBMSG_HEAD2
{
	BYTE c;
	BYTE size;
	BYTE headcode;
	BYTE subcode;
};
//---------------------------------------------------------------------------

void cProtocolLoad();
void cDataRecv(DWORD protoNum, BYTE *aRecv, int aLen, int aIndex);
//---------------------------------------------------------------------------