#ifndef __SECURITY_H__
#define __SECURITY_H__

#pragma comment(lib, "rpcrt4.lib")
#define MacCount 2

// Security
class CSecurity
{
public:
	bool Init();
	bool Checking(LPCSTR MacID);
};

extern CSecurity Security;

#endif