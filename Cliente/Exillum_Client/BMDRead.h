#pragma once
// -------------------------------------------------------------------

#define iLoadModel			0x0069BBF3
#define iLoadTexture		0x0069B777
// ----
#define iLoadModel_Call		0x006B3B29
#define iLoadTexture_Call	0x006B3B3E
// ----
#define iLoadModel_Void		0x0069EE17
#define iLoadTexture_Void	0x006A121D
//---------------------------------------------------------------------------

#define LoadModel	( ( void(*) () ) iLoadModel_Void)
#define LoadTexture ( ( void(*) () ) iLoadTexture_Void)
// ----
typedef void (* pLoadTexture) (int TextureID, char * Folder, int GLREPEAT, int GLNEAREST, int GLTRUE);
extern pLoadTexture Texture;
// ----
typedef void (* pLoadModel) (int ModelID, char * Folder, char * Name, int ModelType);
extern pLoadModel Model;
//---------------------------------------------------------------------------

void cBMDLoad();
//---------------------------------------------------------------------------
