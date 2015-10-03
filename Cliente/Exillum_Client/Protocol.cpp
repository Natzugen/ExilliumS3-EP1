#include "stdafx.h"
#include "Protocol.h"
#include "Interface.h"
#include "Define.h"
#include "TMemory.h"
//---------------------------------------------------------------------------

void cProtocolLoad()
{
	SetOp((LPVOID)iDataRecvCustom, (LPVOID)cDataRecv, ASM::CALL);
}
//---------------------------------------------------------------------------

void cDataRecv(DWORD protoNum, BYTE * aRecv, int aLen, int aIndex)
{
	BYTE ProtocolType = aRecv[0];
	// ----
	switch(ProtocolType)
	{
		case 0xC1:
		{
			switch(BYTE(protoNum))
			{
				case 0x03: // Login
				{
					MU_DrawInfoBox("����� ���������� �� ������ Exillum. \n ������� ������ ���� �� ��� ������ � ������� 10 W Coin �� �����. \n ��� ���� ����� ������� � �������, ��� ���� � ����� ������ ������ ����� � �� ����������.");
				}
				break;
			}
		}
		break;
	}

	DataRecv(protoNum, aRecv, aLen, aIndex);
}
//---------------------------------------------------------------------------