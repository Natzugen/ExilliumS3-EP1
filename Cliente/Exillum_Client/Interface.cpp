#include "stdafx.h"
#include "Interface.h"
#include "Define.h"
#include "TMemory.h"

//---------------------------------------------------------------------------
pDrawInterface		MU_DrawInterface	= (pDrawInterface)	(iDraw_Interface);
pDrawToolTip		MU_DrawToolTip		= (pDrawToolTip)	(iDraw_ToolTip);
pSendChatText		MU_SendChatText		= (pSendChatText)	(iSend_ChatText);
pDrawText			MU_DrawTextOut		= (pDrawText)		(iDraw_Text);
pDrawText2			MU_DrawTextOut2		= (pDrawText2)		(iDraw_Text2);
pDrawInfoBox		MU_DrawInfoBox		= (pDrawInfoBox)	(iDraw_InfoBox);
pDrawDialogBox		MU_DrawDialogBox	= (pDrawDialogBox)	(iDraw_DialogBox);
pDrawQuestBox		MU_DrawQuestBox		= (pDrawQuestBox)	(iDraw_QuestBox);
pBlendDisable		MU_BlendDisable		= (pBlendDisable)	(iBlend_Disable);
pBlendEnable		MU_BlendEnable		= (pBlendEnable)	(iBlend_Enable);
pLoadImage			MU_LoadImage		= (pLoadImage)		(iLoad_Image);
pLoadImage			MU_LoadAlpha		= (pLoadImage)		(iLoad_Alpha);
pDrawImage			MU_DrawImage		= (pDrawImage)		(iDraw_Image);
//---------------------------------------------------------------------------

void cInterfaceLoad()
{
	SetHook((LPVOID)MU_DrawInterface, (LPVOID)iDraw_Interface_Call,  ASM::CALL);
}