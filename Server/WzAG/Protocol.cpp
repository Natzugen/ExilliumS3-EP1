#include "StdAfx.h"

// Server Protocol Converter
BYTE ServerProtocol(BYTE protoNum)
{
	switch(protoNum)
	{
	case 0x1D: // Walk (Jpn)
		return 0x1D; // Walk (Kor)
	case 0xD6: // Damage (Jpn)
		return 0xD6; // Damage (Kor)
	case 0xDC: // Attack (Jpn)
		return 0xDC; // Attack (Kor)
	}

	return protoNum; // New Protocol
}

// Client Protocol Converter
BYTE ClientProtocol(BYTE protoNum)
{
	switch(protoNum)
	{
	case 0x1D: // Walk (Kor)
		return 0x1D; // Walk (Jpn)
	case 0xD6: // Damage (Kor)
		return 0xD6; // Damage (Jpn)
	case 0xDC: // Attack (Kor)
		return 0xDC; // Attack (Jpn)
	}

	return protoNum; // New Protocol
}

// GameServer Protocol Core
void ProtocolCoreEx(BYTE protoNum,unsigned char* aRecv,int aLen,int aIndex,int Encrypt,int serial)
{
	// Protocol Cases
	switch(protoNum)
	{
		// PChatProc
		// Commands
		case 0x00:
			InitCommands(aIndex,aRecv);
		break;
		// CGClientMsg
		// Connect Notice
		case 0x03:													  
			CGClientMsgEx(aIndex);
		break;
		// CGUseItemRecv
		// New Jewels
		case 0x26:
			CustomJewels.CGUseItemRecv((PMSG_USEITEM*)aRecv,aIndex);
			break;
		// CGTalkRequestRecv
		// Stone Exchanger
		case 0x30:
			Exchanger.Talk(aIndex,(aRecv[4] + aRecv[3] * 256));
		break;
		// CGTradeResponseRecv
		// NPC Trade Fix
		case 0x37:
			if(gObj[gObj[aIndex].TargetNumber].Type != 1)
			{
				Log.AddTime("[Anti-Hack][Crash Attempt] [NPC Trade] (%s)(%s)",gObj[aIndex].AccountID,gObj[aIndex].Name);
				return;
			}
			break;
		// CGGuildMasterInfoSave
		// Guild System
		case 0x55:
			GuildSystem.Check(aIndex, (PMSG_GUILDINFOSAVE *)aRecv);
			return;
			break;
		// ChaosBoxMix
		// New Mixes
		case 0x86:
			ChaosMachine.ChaosBoxHook(aIndex,aRecv[3]);
			break;
		// CGReqJewelMix
		// CGReqJewelUnMix
		// Duping Fix
		case 0xBC:
			if(gObj[aIndex].TargetNumber != -1 && gObj[aIndex].pTransaction == 1)
			{
				Log.AddTime("[Anti-Hack][Dupe Attempt] [Trade] (%s)(%s)",gObj[aIndex].AccountID,gObj[aIndex].Name);
				GCServerMsgStringSend("[SYSTEM]: Duping is not allowed here.",aIndex,0);
				CloseClient(aIndex);
				return;
			}
			else if(gObj[aIndex].m_IfState.use > 0 && gObj[aIndex].m_IfState.type != 12)
			{
				Log.AddTime("[Anti-Hack][Dupe Attempt] [Lahap] (%s)(%s)",gObj[aIndex].AccountID,gObj[aIndex].Name);
				GCServerMsgStringSend("[SYSTEM]: Duping is not allowed here.",aIndex,0);
				CloseClient(aIndex);
				return;
			}
			break;

	}

	// Jump to Original Function
	ProtocolCore(protoNum,aRecv,aLen,aIndex,Encrypt,serial);
}