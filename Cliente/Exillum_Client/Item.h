#pragma once
// -------------------------------------------------------------------

typedef int (* ItemAddText)(int Arg1, const char * Arg2, ...);
extern ItemAddText gItemAddText;
// -------------------------------------------------------------------

#define iItemTitleColor				0x00615345
#define iItemTitleColor_Next		0x0061534F
#define iItemTitleColor_Stack		0x00615446
// ----
#define iItemDescriptionText		0x00619240
#define iItemDescriptionText_Next	0x0061927C
#define iItemDescriptionText_Crypt	0x00791CF0
#define iItemDescriptionText_Color	0x079FBECC
#define iItemDesctiptionText_Weight	0x07A2AEC8
#define iItemDescriptionText_Line	0x07A2DA28
#define iItemDescriptionText_Point	0x079FAD30
// ----
#define iItemDropTitleColor			0x0061E694
#define iItemDropTitleColor_Next	0x0061E69E
#define iItemDropTitleColor_Stack	0x0061F873
// ----
#define iItemPrice					0x005994EC
#define iItemPrice_Next				0x0059950D
#define iItemPrice_Stack			0x0059A4E5
// ----
#define iItemShineEffect			0x00693EAF
#define iItemShineEffect_Next		0x006940AE
#define iItemShineEffect_Stack		0x00694409
// -------------------------------------------------------------------

void cItemPropertiesLoad();
// -------------------------------------------------------------------