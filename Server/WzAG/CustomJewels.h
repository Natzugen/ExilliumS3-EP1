#ifndef __CUSTOMJEWELS_H__
#define __CUSTOMJEWELS_H__
#define MAX_ITEM_INFO 12

// Cutom Jewels
struct PSBMSG_HEAD_Le
{
    BYTE type;
	BYTE size;
	BYTE head;
	BYTE subh;
};

struct PMSG_ITEM_MODIFY_SEND 
{
    PSBMSG_HEAD_Le header;
    BYTE slot;
    BYTE ItemInfo[MAX_ITEM_INFO];
};

struct PBMSG_HEAD_it
{
    BYTE type;
	BYTE size;
	BYTE head;
};

struct PMSG_USEITEM
{
	PBMSG_HEAD_it h;
	BYTE inventoryPos;
	BYTE inventoryTarget;
	BYTE btItemUseType;
};

class CCustomJewels
{
public:

	void CGUseItemRecv(PMSG_USEITEM *lpMsg, int aIndex);
	void ItemClear(int aIndex,int Pos);
};

extern CCustomJewels CustomJewels;

#endif