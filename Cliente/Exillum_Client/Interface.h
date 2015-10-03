#include   <windows.h> 
//---------------------------------------------------------------------------

// TODO
// ----
// 'pDrawQuestBox', 'SwitchCode' varibles:
// ----
// [163]: jewel mix, [168]: chaos mix test, [169]: question box - yellow-bold,
// [171] & [172]: question box - white-normal, [148]: question box - orange-bold,
// [150]: question box - chaos mix test, [154]: question box - chaos castle
//---------------------------------------------------------------------------


#define iDraw_ToolTip			0x005A0980
#define iDraw_Interface			0x00603810
#define iDraw_Interface_Call	0x006015CD
#define iDraw_Image				0x006BA05A
#define iSend_ChatText			0x005A1810
#define iDraw_Text				0x005A07C0
#define iDraw_Text2				0x005A0930
#define iDraw_InfoBox			0x006CCAA0
#define iDraw_DialogBox			0x006CCC10
#define iDraw_QuestBox			0x006CCFE0
#define iLoad_Image				0x006D5CFB
#define iLoad_Alpha				0x006D624C
#define iBlend_Enable			0x006B8419
#define iBlend_Disable			0x006B84B4
#define iThis_Pointer			0x00791AFC

//---------------------------------------------------------------------------

typedef void (__cdecl *pDrawInterface) (void);
extern pDrawInterface MU_DrawInterface;
// ----
typedef void (*pDrawToolTip) (int x, int y, char * Text);
extern pDrawToolTip MU_DrawToolTip;
// ----
typedef void (__cdecl *pSendChatText) (const char * szSender, const char * szText, BYTE Color);
extern pSendChatText MU_SendChatText;
// ----
typedef char * (__cdecl *pDrawText) (int x, int y, char * Text, int BackgroundWidth, int AlignCenter, int a6);
extern pDrawText MU_DrawTextOut;
// ----
typedef double (__cdecl *pDrawText2) (int x, int y, char * Text, int a4, int a5, int a6);
extern pDrawText2 MU_DrawTextOut2;
// ----
typedef void (__cdecl *pDrawInfoBox) (const char * Text);
extern pDrawInfoBox MU_DrawInfoBox;
// ----
typedef void (__cdecl *pDrawDialogBox) (int TextID);
extern pDrawDialogBox MU_DrawDialogBox;
// ----
typedef void (__cdecl *pDrawQuestBox) (int LineCount, int TextID, int SwitchCode); 
extern pDrawQuestBox MU_DrawQuestBox;
// ----
typedef void (*pBlendEnable) (bool Mask);
extern pBlendEnable MU_BlendEnable;
// ----
typedef void (*pBlendDisable) (void);
extern pBlendDisable MU_BlendDisable;
// ----
typedef void (*pDrawImage) (int ImageID, float PosX, float PosY, float Width, float Height, int a6, int a7, float ScaleX, float ScaleY, int a11, int a12, int a13);
extern pDrawImage DrawImage;
// ---- 
typedef void (*pLoadImage) (char * Folder, int ImageID, int BlendType, int a4, int a5, int a6);
extern pLoadImage MU_LoadImage, MU_LoadAlpha;
//---------------------------------------------------------------------------

void cInterfaceLoad();
void __cdecl cDrawInterface();
//---------------------------------------------------------------------------