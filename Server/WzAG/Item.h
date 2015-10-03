#ifndef __ITEM_H__
#define __ITEM_H__

// Item Macros
#define ITEMGET(x,y) ((x) * 512 + (y))

// Item Info
struct ITEMSTRUCT 
{
	/*0x0>	|0x4|*/ unsigned long m_Number;
	/*0x4>	|0x1|*/ char m_serial;
	/*0x6>	|0x2|*/ short m_Type;
	/*0x8>	|0x2|*/ short m_Level;
	/*0xa>	|0x1|*/ unsigned char m_Part;
	/*0xb>	|0x1|*/ unsigned char m_Class;
	/*0xc>	|0x1|*/ unsigned char m_TwoHand;
	/*0xd>	|0x1|*/ unsigned char m_AttackSpeed;
	/*0xe>	|0x1|*/ unsigned char m_WalkSpeed;
	/*0x10>	|0x2|*/ unsigned short m_DamageMin;
	/*0x12>	|0x2|*/ unsigned short m_DamageMax;
	/*0x14>	|0x1|*/ unsigned char m_SuccessfulBlocking;
	/*0x16>	|0x2|*/ unsigned short m_Defense;
	/*0x18>	|0x2|*/ unsigned short m_MagicDefense;
	/*0x1a>	|0x1|*/ unsigned char m_Speed;
	/*0x1c>	|0x2|*/ unsigned short m_DamageMinOrigin;
	/*0x1e>	|0x2|*/ unsigned short m_DefenseOrigin;
	/*0x20>	|0x2|*/ unsigned short m_Magic;
	/*0x24>	|0x4|*/ float m_Durability;
	/*0x28>	|0x2|*/ unsigned short m_DurabilitySmall;
	/*0x2c>	|0x4|*/ float m_BaseDurability;
	/*0x30>	|0x1|*/ unsigned char m_SpecialNum;
	/*0x31>	|0x8|*/ unsigned char m_Special[8];
	/*0x39>	|0x8|*/ unsigned char m_SpecialValue[8];
	/*0x42>	|0x2|*/ unsigned short m_RequireStrength;
	/*0x44>	|0x2|*/ unsigned short m_RequireDexterity;
	/*0x46>	|0x2|*/ unsigned short m_RequireEnergy;
	/*0x48>	|0x2|*/ unsigned short m_RequireLevel;
	/*0x4a>	|0x2|*/ unsigned short m_RequireVitality;
	/*0x4c>	|0x2|*/ unsigned short m_RequireLeaderShip;
	/*0x4e>	|0x2|*/ unsigned short m_Leadership;
	/*0x50>	|0x5|*/ unsigned char m_RequireClass[5];
	/*0x55>	|0x7|*/ unsigned char m_Resistance[7];
	/*0x5c>	|0x4|*/ int m_Value;
	/*0x60>	|0x4|*/ unsigned long m_SellMoney;
	/*0x64>	|0x4|*/ unsigned long m_BuyMoney;
	/*0x68>	|0x4|*/ int m_iPShopValue;
	/*0x6c>	|0x1|*/ unsigned char m_bItemExist;
	/*0x70>	|0x4|*/ int m_OldSellMoney;
	/*0x74>	|0x4|*/ int m_OldBuyMoney;
	/*0x78>	|0x1|*/ unsigned char m_Option1;
	/*0x79>	|0x1|*/ unsigned char m_Option2;
	/*0x7a>	|0x1|*/ unsigned char m_Option3;
	/*0x7b>	|0x1|*/ unsigned char m_NewOption;
	/*0x7c>	|0x10|*/float m_DurabilityState[4];
	/*0x8c>	|0x4|*/ float m_CurrentDurabilityState;
	/*0x90>	|0x1|*/ unsigned char m_SkillChange;
	/*0x91>	|0x1|*/ unsigned char m_QuestItem;
	/*0x92>	|0x1|*/ unsigned char m_SetOption;
	/*0x93>	|0x1|*/ unsigned char m_SetAddStat;
	/*0x94>	|0x1|*/ unsigned char m_IsValidItem;
	/*0x95>	|0x7|*/ unsigned char m_SkillResistance[7];
	/*0x9c>	|0x4|*/ int m_IsLoadPetItemInfo;
	/*0xa0>	|0x4|*/ int m_PetItem_Level;
	/*0xa4>	|0x4|*/ int m_PetItem_Exp;
	/*0xa8>	|0x1|*/ unsigned char m_JewelOfHarmonyOption;
	/*0xaa>	|0x2|*/ unsigned short m_HJOpStrength;
	/*0xac>	|0x2|*/ unsigned short m_HJOpDexterity;
	/*0xae>	|0x1|*/ unsigned char m_ItemOptionEx;
};

#endif