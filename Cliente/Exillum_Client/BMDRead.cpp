#include "stdafx.h"
#include "BMDRead.h"
#include "Define.h"
#include "TMemory.h"
// -------------------------------------------------------------------

char * ModelsFolder		= "Data\\Item\\";
char * TexFolder		= "Item\\";
// -------------------------------------------------------------------

pLoadModel Model		= (pLoadModel) (iLoadModel);
pLoadTexture Texture	= (pLoadTexture) (iLoadTexture);
// -------------------------------------------------------------------
void cModelLoad()
{
	LoadModel();
	// ----
	Model(ITEM2(14, 101), ModelsFolder, "j_luck01", -1);
}
// --------------------------------------------------------------------

void cTextureLoad()
{
	LoadTexture();
	// ----
	Texture(ITEM2(14, 101), TexFolder, GL_REPEAT, GL_NEAREST, GL_TRUE);
}
// -------------------------------------------------------------------

void cBMDLoad()
{
	SetHook((LPVOID)cTextureLoad, (LPVOID)iLoadTexture_Call, ASM::CALL);
	SetHook((LPVOID)cModelLoad, (LPVOID)iLoadModel_Call, ASM::CALL);
}
// -------------------------------------------------------------------