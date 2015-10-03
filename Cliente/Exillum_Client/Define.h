#pragma once
// -------------------------------------------------------------------

#define SERVER_ADRESS	"127.0.0.1"
#define MAIN_SERIAL		"rPVessXV1Xr2as11"
#define MAIN_VERSION	"22346"
#define VERSION			"1.02.11 JPN"
//---------------------------------------------------------------------------

BOOL APIENTRY DllMain_PROCESS_ATTACH(HMODULE hModule, DWORD dwReason);
BOOL APIENTRY DllMain_PROCESS_DETACH(HMODULE hModule, DWORD dwReason);
//---------------------------------------------------------------------------

#define Naked(Function) void __declspec(naked) Function()
#define ItemStartIndex	635
#define ITEM(x, y)		((x * 512) + y)
#define ITEM2(x, y)		((x * 512) + y + ItemStartIndex)
//---------------------------------------------------------------------------

namespace ItemColor
{
	enum T
	{
		White		= 0x00,
		Blue		= 0x01,
		Red			= 0x02,
		Gold		= 0x03,
		Green		= 0x04,
		WhiteRed	= 0x05,
		Violet		= 0x06,
		WhiteBlue	= 0x07,
		WhiteBeige	= 0x08,
		GreenBlue	= 0x09,
		Gray		= 0x0A,
		DarkViolet	= 0x0B,
	};
};
//---------------------------------------------------------------------------

enum BlendType
{
	JPG		= 0x2600,
	TGA		= 0x2601,
};
//---------------------------------------------------------------------------

enum ChatColor
{
	Blue		= 0x01,
	Red			= 0x02,
	Chocolate	= 0x0A,
	Gold		= 0x09,
	Green		= 0x0B,
};
//---------------------------------------------------------------------------

enum ASM
{
	JMP	 = 0xE9,
	JE	 = 0x74,
	JNE  = 0x75,
	JGE  = 0x7D,
	NOP	 = 0x90,
	CALL = 0xE8,
};
//---------------------------------------------------------------------------

enum ItemWeight
{
	Bold	= 0x01,
	Normal  = 0x00,
};
//---------------------------------------------------------------------------

enum IndexState
{
	Loading			= 1,
	SelectServer 	= 2,
	SwitchCharacter	= 4,
	InGame			= 5,
};
//---------------------------------------------------------------------------

enum MAINSTATE
{
	SELECT_SERVER		= 2,
	SELECT_CHARACTER	= 4,
	SELECT_GAME			= 5,
};
//---------------------------------------------------------------------------