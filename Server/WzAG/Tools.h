#ifndef __TOOLS_H__
#define __TOOLS_H__

// Function Headers
void SetByte(DWORD NewOffset,BYTE NewByte);
void SetJNZ(DWORD NewOffset);
void SetJE(DWORD NewOffset);
void SetJMP(DWORD NewOffset);
void SetNop(DWORD NewOffset,int Size);
void SetRetn(DWORD NewOffset);
void FunctionHook(DWORD NewOffset,DWORD JumpOffset);
void gObjGetNick(int aIndex,char* Nick);
long int gObjGetInt(int aIndex,int gObjParam);
void gObjWrite(int aIndex,int gObjParam,long int Value);
void MsgOutput(int aIndex,char* Message,...);
void MsgOutputSystem(int aIndex,char* Message,...);
int OnlineStatus(int aIndex);
int VerifyGM(int aIndex);
int GetPlayerCount();
int GetGMCount();
#endif