#include "stdafx.h"
#include "Item.h"
#include "Define.h"
#include "TMemory.h"
// -------------------------------------------------------------------

WORD	ItemTitleColor_Pointer;
DWORD	ItemTitleColor_Set;
DWORD	ItemTitleColor_Buff;
// ----
DWORD	ItemDescriptionText_Pointer;
DWORD	ItemDescriptionText_Buff;
DWORD	ItemDescriptionText_OperandBuff;
// ----
WORD	ItemDropTitleColor_Pointer;
bool	ItemDropTitleColor_Set;
// ----
DWORD	ItemPrice_Pointer;
DWORD	ItemPrice_Money;
// ----
DWORD	ItemShineEffect_Pointer;
DWORD	ItemShineEffect_Level;
bool	ItemShineEffect_Set;
// -------------------------------------------------------------------

ItemAddText gItemAddText = (ItemAddText)0x00791CF0;
// -------------------------------------------------------------------

void ItemAddTextLine(char * Text, int Color, int Weight)
{
	*( &*(DWORD*)iItemDescriptionText_Color + *(DWORD*)iItemDescriptionText_Line )	= Color;
	*( &*(DWORD*)iItemDesctiptionText_Weight + *(DWORD*)iItemDescriptionText_Line )	= Weight;
	gItemAddText(100 * (*(DWORD*)iItemDescriptionText_Line) + iItemDescriptionText_Point, Text);
	*(DWORD*)iItemDescriptionText_Line += 1;
}
// -------------------------------------------------------------------

Naked (cItemTitleColor)
{
	ItemTitleColor_Set = ItemColor::White;
	// ----
	_asm
	{
		mov ItemTitleColor_Pointer, ax
	}
	// ----
	if ( ItemTitleColor_Pointer == ITEM(12, 15) || ItemTitleColor_Pointer == ITEM(13, 60) )
	{
		ItemTitleColor_Set = ItemColor::Gold;
	}
	// ----
	_asm
	{
		je ColorSet
		mov edx, iItemTitleColor_Next
		jmp edx
		// ----
		ColorSet:
		mov ecx, ItemTitleColor_Set
		mov dword ptr ss:[esp+0x1c], ecx
		mov edx, iItemTitleColor_Stack
		jmp edx
	}
}
// -------------------------------------------------------------------

Naked(cItemDescriptionText)
{
	_asm
	{
		mov esi, dword ptr ss:[ebp]
		mov ItemDescriptionText_Pointer, esi
	}
	// ----
	if (ItemDescriptionText_Pointer == ITEM(12, 15))
	{
		ItemAddTextLine("It is used to combine Chaos items.", ItemColor::White, ItemWeight::Normal);
	}
	else if (ItemDescriptionText_Pointer == ITEM(14, 101))
	{
		ItemAddTextLine("It is used to make your item to luck item.", ItemColor::White, ItemWeight::Normal);
	}
	// ----
	_asm
	{
		mov esi, iItemDescriptionText_Next
		jmp esi
	}
}
// -------------------------------------------------------------------

Naked (cItemDropTitleColor)
{
	ItemDropTitleColor_Set = false;
	// ----
	_asm
	{
		mov ItemDropTitleColor_Pointer, ax
	}
	// ----
	if( ItemDropTitleColor_Pointer == ITEM2(14, 13) || ItemDropTitleColor_Pointer == ITEM2(13, 60))
	{
		ItemDropTitleColor_Set = true;
	}
	else if( ItemDropTitleColor_Pointer <= ITEM2(14, 99) && ItemTitleColor_Pointer >= ITEM2(14, 101))
	{
		ItemDropTitleColor_Set = true;
	}
	// ----
	if( ItemDropTitleColor_Set == true )
	{
		_asm
		{
			mov esi, iItemDropTitleColor_Stack
			jmp esi
		}
	}
	else
	{
		_asm
		{
			mov esi, iItemDropTitleColor_Next
			jmp esi
		}
	}
}
// -------------------------------------------------------------------

Naked (cItemPrice)
{
	ItemPrice_Money = 0;
	// ----
	_asm
	{
		mov ecx, dword ptr ss:[ebp+0x8]
		movsx edx, word ptr ds:[ecx]
		mov ItemPrice_Pointer, edx
	}
	// ----
	if( ItemPrice_Pointer == ITEM(14, 13) ) 
	{
		ItemPrice_Money = 1000000;
	}
	else if( ItemPrice_Pointer == ITEM(14, 84) || ItemPrice_Pointer == ITEM(14, 85) || ItemPrice_Pointer == ITEM(14, 86) || ItemPrice_Pointer == ITEM(14, 87) || ItemPrice_Pointer == ITEM(14, 88))
	{
		ItemPrice_Money = 1000000;
	}
	else if( ItemPrice_Pointer == ITEM(14, 99) || ItemPrice_Pointer == ITEM(14, 100) || ItemPrice_Pointer == ITEM(14, 101))
	{
		ItemPrice_Money = 1000000;
	}
	// ----
	if( ItemPrice_Money == 0 )
	{
		_asm
		{
			mov edx, iItemPrice_Next
			jmp edx
		}
	}
	else
	{
		_asm
		{
			mov eax, ItemPrice_Money
			mov dword ptr ss:[ebp-0x8], eax
			mov dword ptr ss:[ebp-0x4], 0x0
			mov eax, iItemPrice_Stack
			jmp eax
		}
	}
}
// -------------------------------------------------------------------

Naked (cItemShineEffect)
{
	ItemShineEffect_Set = false;
	ItemShineEffect_Level = 0;
	// ----
	_asm
	{
		mov ItemShineEffect_Pointer, ecx
	}
	// ----
	if( ItemShineEffect_Pointer >= ITEM2(14, 99) && ItemShineEffect_Pointer <= ITEM2(14, 101))
	{
		ItemShineEffect_Set = true;
		ItemShineEffect_Level = 9;
	}
	else if( ItemShineEffect_Pointer >= ITEM2(14, 84)  && ItemShineEffect_Pointer <= ITEM2(14, 88) )
	{
		ItemShineEffect_Set = true;
		ItemShineEffect_Level = 7;
	}
	// ----
	if( ItemShineEffect_Set == true )
	{
		_asm
		{
			mov eax, ItemShineEffect_Level
			mov dword ptr ss:[ebp-8], eax
			mov esi, iItemShineEffect_Stack
			jmp esi
		}
	}
	// ----
	_asm
	{
		mov esi, iItemShineEffect_Next
		jmp esi
	}
}
// -------------------------------------------------------------------

void cItemPropertiesLoad()
{
	SetRange((LPVOID)iItemTitleColor, 10, ASM::NOP);
	SetJmp((LPVOID)iItemTitleColor, cItemTitleColor);
	// ----
	//SetRange((LPVOID)iItemDropTitleColor, 10, ASM::NOP);
	//SetJmp((LPVOID)iItemDropTitleColor, cItemDropTitleColor);
	// ----
	SetRange((LPVOID)iItemPrice, 33, ASM::NOP);
	SetJmp((LPVOID)iItemPrice, cItemPrice);
	// ----
	SetRange((LPVOID)iItemShineEffect, 6, ASM::NOP);
	SetJg((LPVOID)iItemShineEffect, cItemShineEffect);
	// ----
	SetRange((LPVOID)iItemDescriptionText, 60, ASM::NOP);
	SetJmp((LPVOID)iItemDescriptionText, cItemDescriptionText);
}
// -------------------------------------------------------------------