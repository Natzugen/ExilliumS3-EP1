#ifndef __PROTOCOL_H__
#define __PROTOCOL_H__

// Function Headers
__declspec (dllexport) BYTE ServerProtocol(BYTE protoNum);
__declspec (dllexport) BYTE ClientProtocol(BYTE protoNum);
void __cdecl ProtocolCoreEx(BYTE protoNum,unsigned char* aRecv,int aLen,int aIndex,int Encrypt,int serial);

#endif