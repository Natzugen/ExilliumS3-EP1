#include "StdAfx.h"
#include "Define.h"
#include "Other.h"
#include "BMDRead.h"
#include "Item.h"
#include "Glow.h"
#include "Protocol.h"
#include "WeaponFloat.h"
#include "TMemory.h"
#include "TDebugLog.h"

#include "detours.h"
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "detours.lib")

int FogStatus = GetPrivateProfileIntA("EXILLUM", "FogOnOff", 1, "./Settings.ini");
int SmoothingStatus = GetPrivateProfileIntA("EXILLUM", "SmoothingOnOff", 1, "./Settings.ini");

int *CMAIN_STATE = (int*)iGameState;

void APIENTRY glEnable_Hooked(GLenum); 
typedef void (APIENTRY *ptr_glEnable)(GLenum);
ptr_glEnable glEnable_Real = (ptr_glEnable)&glEnable;
typedef void (APIENTRY *ptr_glClearColor)(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
ptr_glClearColor glClearColor_Real = (ptr_glClearColor)&glClearColor;

//---------------------------------------------------------------------------
void APIENTRY glEnable_Hooked(GLenum cap)
{		
	GLfloat rgba[4] = { 0.0f, 0.0f, 0.0f, 1.0f };

	if(SmoothingStatus == 1)
	{
		if (*CMAIN_STATE != SELECT_SERVER)
		{
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		}
	}

	if(FogStatus == 1)
	{
		if (*CMAIN_STATE == SELECT_GAME)
		{
			if (cap == GL_BLEND || cap == GL_TEXTURE_2D || cap == GL_DEPTH_TEST)
			{
				glDisable(GL_FOG);  
			}

			glEnable_Real(GL_FOG);
			glFogi(GL_FOG_MODE, GL_LINEAR);
			glFogf(GL_FOG_DENSITY, 0.25f);
			glFogfv(GL_FOG_COLOR, rgba);
			glFogf(GL_FOG_START, 1650.0f);
			glFogf(GL_FOG_END, 2100.0f);
			glHint(GL_FOG_HINT, GL_NICEST);
		}
		else if (*CMAIN_STATE == SELECT_CHARACTER)
		{
			glEnable_Real(GL_FOG);
			glFogi(GL_FOG_MODE, GL_LINEAR);
			glFogf(GL_FOG_DENSITY, 0.25f);
			glFogfv(GL_FOG_COLOR, rgba);
			glFogf(GL_FOG_START, 1850.0f);
			glFogf(GL_FOG_END, 2100.0f);
			glHint(GL_FOG_HINT, GL_NICEST);
		}
	}

	glEnable_Real(cap);
}
// -------------------------------------------------------------------

BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
	switch(dwReason)
	{	
	case DLL_PROCESS_ATTACH: 
		{
			cBMDLoad();
			cItemPropertiesLoad();
			cGlowLoad();
			cProtocolLoad();
			cWeaponFloatLoad();
			CustomsLoad();

			DisableThreadLibraryCalls(hModule);
			DetourTransactionBegin();
			DetourUpdateThread(GetCurrentThread());
			DetourAttach(&(PVOID&)glEnable_Real, glEnable_Hooked);
			DetourTransactionCommit();
		}
		break;
		
	case DLL_PROCESS_DETACH:
		{
			DetourTransactionBegin();
			DetourUpdateThread(GetCurrentThread());
			DetourDetach(&(PVOID&)glEnable_Real, glEnable_Hooked); 
			DetourTransactionCommit();
		}
		break;	
	}

	return true;
}
// -------------------------------------------------------------------