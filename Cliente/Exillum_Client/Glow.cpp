#include "stdafx.h"
#include "Glow.h"
#include "Define.h"
#include "TMemory.h"
//---------------------------------------------------------------------------

void cGlowLoad()
{
	SetHook((LPVOID)cSetGlowEffect_Main, (LPVOID)iGlowEffect_Main1, ASM::CALL);
	SetHook((LPVOID)cSetGlowEffect_Main, (LPVOID)iGlowEffect_Main2, ASM::CALL);
	SetHook((LPVOID)cSetGlowEffect_Second, (LPVOID)iGlowEffect_Second, ASM::CALL);
}
//---------------------------------------------------------------------------

void cSetGlowEffect_Main(int ITEM2, float Arg2, float Arg3, RBGColor * Color, int Arg5)
{
	switch(ITEM2)
	{
	case ITEM2(0, 26):
		{
			Color->r = 0.0f, Color->g = 30.0f, Color->b = 0.0f;
		}
		break;
	case ITEM2(2, 16):
		{
			Color->r = 50.0f, Color->g = 160.0f, Color->b = 150.0f;
		}
		break;
	case ITEM2(7, 39):
		{
			Color->r = 0.0f, Color->g = 30.0f, Color->b = 0.0f;
		}
		break;
	case ITEM2(8, 39):
		{
			Color->r = 0.0f, Color->g = 30.0f, Color->b = 0.0f;
		}
		break;
	case ITEM2(9, 39):
		{
			Color->r = 0.0f, Color->g = 30.0f, Color->b = 0.0f;
		}
		break;
	case ITEM2(10, 39):
		{
			Color->r = 0.0f, Color->g = 30.0f, Color->b = 0.0f;
		}
		break;
	case ITEM2(11 , 39):
		{
			Color->r = 0.0f, Color->g = 30.0f, Color->b = 0.0f;
		}
		break;
	case ITEM2(12, 32):
		{
			Color->r = 70.0f, Color->g = 0.0f, Color->b = 0.0f;
		}
		break;
	case ITEM2(12, 33):
		{
			Color->r = 0.0f, Color->g = 70.0f, Color->b = 0.0f;
		}
		break;
	case ITEM2(12, 34):
		{
			Color->r = 0.0f, Color->g = 0.0f, Color->b = 70.0f;
		}
		break;
	case ITEM2(14, 84):
		{
			Color->r = 50.0f, Color->g = 50.0f, Color->b = 50.0f;
		}
		break;
	case ITEM2(14, 85):
		{
			Color->r = 50.0f, Color->g = 50.0f, Color->b = 50.0f;
		}
		break;
	case ITEM2(14, 86):
		{
			Color->r = 50.0f, Color->g = 50.0f, Color->b = 50.0f;
		}
		break;
	case ITEM2(14, 87):
		{
			Color->r = 50.0f, Color->g = 50.0f, Color->b = 50.0f;
		}
		break;
	case ITEM2(14, 88):
		{
			Color->r = 50.0f, Color->g = 50.0f, Color->b = 50.0f;
		}
		break;
	case ITEM2(14, 99):
		{
			Color->r = 70.0f, Color->g = 0.0f, Color->b = 0.0f;
		}
		break;
	case ITEM2(14, 100):
		{
			Color->r = 70.0f, Color->g = 70.0f, Color->b = 70.0f;
		}
		break;
	case ITEM2(14, 101):
		{
			Color->r = 0.0f, Color->g = 70.0f, Color->b = 0.0f;
		}
		break;
		// --
	default: 
		{ 
			vGlowEffect1(ITEM2, Arg2, Arg3, Color, Arg5); 
		}
		break;
	};	
}
//---------------------------------------------------------------------------

void cSetGlowEffect_Second(int ITEM2, float Arg2, float Arg3, RBGColor * Color, int Arg5)
{
	switch(ITEM2)
	{
	case ITEM2(0, 26):
		{
			Color->r = 30.0f, Color->g = 0.0f, Color->b = 0.0f;
		}
		break;
	case ITEM2(2, 16):
		{
			Color->r = 50.0f, Color->g = 160.0f, Color->b = 150.0f;
		}
		break;
	case ITEM2(7, 39):
		{
			Color->r = 30.0f, Color->g = 0.0f, Color->b = 0.0f;
		}
		break;
	case ITEM2(8, 39):
		{
			Color->r = 30.0f, Color->g = 0.0f, Color->b = 0.0f;
		}
		break;
	case ITEM2(9, 39):
		{
			Color->r = 30.0f, Color->g = 0.0f, Color->b = 0.0f;
		}
		break;
	case ITEM2(10, 39):
		{
			Color->r = 30.0f, Color->g = 0.0f, Color->b = 0.0f;
		}
		break;
	case ITEM2(11 , 39):
		{
			Color->r = 30.0f, Color->g = 0.0f, Color->b = 0.0f;
		}
		break;
	case ITEM2(12, 32):
		{
			Color->r = 70.0f, Color->g = 0.0f, Color->b = 0.0f;
		}
		break;
	case ITEM2(12, 33):
		{
			Color->r = 0.0f, Color->g = 70.0f, Color->b = 0.0f;
		}
		break;
	case ITEM2(12, 34):
		{
			Color->r = 0.0f, Color->g = 0.0f, Color->b = 70.0f;
		}
		break;
	case ITEM2(14, 84):
		{
			Color->r = 50.0f, Color->g = 50.0f, Color->b = 50.0f;
		}
		break;
	case ITEM2(14, 85):
		{
			Color->r = 50.0f, Color->g = 50.0f, Color->b = 50.0f;
		}
		break;
	case ITEM2(14, 86):
		{
			Color->r = 50.0f, Color->g = 50.0f, Color->b = 50.0f;
		}
		break;
	case ITEM2(14, 87):
		{
			Color->r = 50.0f, Color->g = 50.0f, Color->b = 50.0f;
		}
		break;
	case ITEM2(14, 88):
		{
			Color->r = 50.0f, Color->g = 50.0f, Color->b = 50.0f;
		}
		break;
	case ITEM2(14, 99):
		{
			Color->r = 70.0f, Color->g = 0.0f, Color->b = 0.0f;
		}
		break;
	case ITEM2(14, 100):
		{
			Color->r = 70.0f, Color->g = 70.0f, Color->b = 70.0f;
		}
		break;
	case ITEM2(14, 101):
		{
			Color->r = 0.0f, Color->g = 70.0f, Color->b = 0.0f;
		}
		break;
		// --
	default: 
		{ 
			vGlowEffect2(ITEM2, Arg2, Arg3, Color, Arg5); 
		}
		break;
	};
}
//---------------------------------------------------------------------------