#pragma once
//---------------------------------------------------------------------------

struct RBGColor
{
	float r, g, b;
};
//---------------------------------------------------------------------------

#define vGlowEffect1	( (void(*) (int ITEM2, float a2, float a3, RBGColor * Color, int a5) ) 0x0068BD20)
#define vGlowEffect2	( (void(*) (int ITEM2, float a2, float a3, RBGColor * Color, int a5) ) 0x0068C857)
// -----
#define iGlowEffect_Main1	0x0053B8F5
#define	iGlowEffect_Main2	0x00693879
#define iGlowEffect_Second	0x00693B27

//---------------------------------------------------------------------------

void cSetGlowEffect_Main(int ITEM2, float Arg2, float Arg3, RBGColor * Color, int Arg5);
void cSetGlowEffect_Second(int ITEM2, float Arg2, float Arg3, RBGColor * Color, int Arg5);
void cGlowLoad();
//---------------------------------------------------------------------------