#ifndef __MAPPING_H__
#define __MAPPING_H__

// Function Definitions

typedef int (*pDataSend) (int,unsigned char*,DWORD);
extern pDataSend DataSend;

typedef void (*pProtocolCore) (BYTE,unsigned char*,int,int,int,int);
extern pProtocolCore ProtocolCore;

typedef void (*pLogAddFuncColor)(BYTE,char*,...);
extern pLogAddFuncColor LogAddFuncColor;

typedef void (*pCloseClient) (int);
extern pCloseClient CloseClient;

typedef void (*pGCServerMsgStringSend)(char*,int,BYTE);
extern pGCServerMsgStringSend GCServerMsgStringSend;

typedef int (*pgObjMonsterTopHitDamageUser)(OBJECTSTRUCT*);
extern pgObjMonsterTopHitDamageUser gObjMonsterTopHitDamageUser;

typedef void (*pItemSerialCreateSend)(int,BYTE,BYTE,BYTE,int,BYTE,BYTE,BYTE,BYTE,BYTE,int,BYTE,BYTE);
extern pItemSerialCreateSend ItemSerialCreateSend;

typedef void (*pGCStateInfoSend) (OBJECTSTRUCT*,unsigned char,int);
extern pGCStateInfoSend GCStateInfoSend;

typedef void (*pGCMoneySend)(int,unsigned long);
extern pGCMoneySend GCMoneySend;

typedef void (*pChatTargetSend) (OBJECTSTRUCT*,char*,int);
extern pChatTargetSend ChatTargetSend;

typedef int (*pgObjSetMonster) (int,int);
extern pgObjSetMonster gObjSetMonster;

typedef BYTE (*pgObjInventoryDeleteItem) (int,int);
extern pgObjInventoryDeleteItem gObjInventoryDeleteItem;

typedef void (*pGCInventoryItemDeleteSend) (int,BYTE,unsigned char);
extern pGCInventoryItemDeleteSend GCInventoryItemDeleteSend;

typedef int (*pCGLevelUpPointAdd) (unsigned char*,int);
extern pCGLevelUpPointAdd CGLevelUpPointAdd;

typedef void (*pReadCommonServerInfo) ();
extern pReadCommonServerInfo ReadCommonServerInfo;

typedef void (*pgObjTeleport) (int,int,int,int);
extern pgObjTeleport gObjTeleport;

typedef void (*pGameMonsterAllCloseAndReLoad) ();
extern pGameMonsterAllCloseAndReLoad GameMonsterAllCloseAndReLoad;

typedef int (*pgObjMonsterDieGiveItem) (OBJECTSTRUCT*, OBJECTSTRUCT*);
extern pgObjMonsterDieGiveItem gObjMonsterDieGiveItem;

typedef void (*pgObjInventoryItemSet) (int,int,BYTE);
extern pgObjInventoryItemSet gObjInventoryItemSet;

typedef void (*pGCInventoryItemOneSend) (int, int);
extern pGCInventoryItemOneSend GCInventoryItemOneSend;

typedef int (*pgObjAddMonster) (unsigned char);
extern pgObjAddMonster gObjAddMonster;

typedef void (*pgObjDel) (int);
extern pgObjDel gObjDel;

typedef void (*pgObjPlayerKiller) (OBJECTSTRUCT*, OBJECTSTRUCT*);
extern pgObjPlayerKiller gObjPlayerKiller;

typedef void (*pGJPUserClose) (LPSTR);
extern pGJPUserClose GJPUserClose;

typedef void (*pCGPShopAnsClose) (int,BYTE);
extern pCGPShopAnsClose CGPShopAnsClose;

typedef BOOL (*pPkCheck) (OBJECTSTRUCT*, OBJECTSTRUCT*);
extern pPkCheck PkCheck;

typedef void (*pgObjCloseSet) (int, int);
extern pgObjCloseSet gObjCloseSet;

typedef void (*pGCMagicAttackNumberSend) (OBJECTSTRUCT*, int, int, int);
extern pGCMagicAttackNumberSend GCMagicAttackNumberSend;

typedef void (*pCGGuildMasterInfoSave) (int, PMSG_GUILDINFOSAVE*);
extern pCGGuildMasterInfoSave CGGuildMasterInfoSave;

typedef bool (*pChaosBoxInit)(int);
extern pChaosBoxInit ChaosBoxInit;

typedef void (*pGCUserChaosBoxSend)(int,int);
extern pGCUserChaosBoxSend GCUserChaosBoxSend;

typedef int (*pGDUserItemSave)(OBJECTSTRUCT*);
extern pGDUserItemSave GDUserItemSave;

typedef bool (*pgEventMonsterItemDrop)(OBJECTSTRUCT*,OBJECTSTRUCT*);
extern pgEventMonsterItemDrop gEventMonsterItemDrop;

typedef void (*pGCLevelUpMsgSend)(int,int);
extern pGCLevelUpMsgSend GCLevelUpMsgSend;

#endif