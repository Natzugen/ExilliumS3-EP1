#ifndef __FIXES_H__
#define __FIXES_H__

// Function Headers
void MiscellaneousFixes();
void ReadCommonServerInfoEx();

bool MygEventMonsterItemDrop(OBJECTSTRUCT* gObj, OBJECTSTRUCT* gTargetObj);
bool CGPartyRequestRecv(PMSG_PARTYREQUEST * lpMsg, int aIndex);

#endif