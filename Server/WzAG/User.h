#ifndef __USER_H__
#define __USER_H__

// GameServer Object Info
#define OBJECT_BASE		0xB692D60
#define OBJECT_SIZE		0x19A0
#define OBJECT_MIN		0x20D0
#define OBJECT_MAX		0x24B8

// Player Structures
#define gObjCtl			0x1C4 // gObj->Authority
#define gObjLvl			0xA0 // gObj->Level
#define gObjExp			0xAC // gObj->Experience
#define gObjZen			0xB4 // gObj->Money
#define gObjNick		0x73 // gObj->Name
#define gObjPK			0x101 // gObj->m_PK_Level
#define gObjClass		0x9C // gObj->Class
#define gObjInventory	0xCAC // gObj->pInventory

#define gObjStrength	0xB8 // gObj->Strength
#define gObjAgility		0xBA // gObj->Dexterity
#define gObjVitality	0xBC // gObj->Vitality
#define gObjEnergy		0xBE // gObj->Energy
#define gObjCommand		0xDC // gObj->Leadership

// Chaos Machine
#define gObjItemSize	0xB0
#define gObjChaosMixBox	0xCFC

// Custom Variables
#define PLAYER_EMPTY  0
#define PLAYER_CONNECTED 1
#define PLAYER_LOGGED 2
#define PLAYER_PLAYING 3

// Custom Player Variables
extern char Character[11]; // Commands

// Custom Objects
#define OBJECT_POINTER(aIndex) ((aIndex * OBJECT_SIZE) + OBJECT_BASE)
#define OBJECT_TABINDEX(lpObj) ((lpObj - OBJECT_BASE) / OBJECT_SIZE)
#define MAKE_NUMBERW(x,y)  ((WORD)(((BYTE)((y)&0xFF)) | ((BYTE)((x)&0xFF)<<8 ))) 

// Custom Variables
#define Max_IP 1000
#define PLAYER_EMPTY 0
#define PLAYER_CONNECTED 1
#define PLAYER_LOGGED 2
#define PLAYER_PLAYING 3

struct VIEWPORT_STRUCT // Size 0xC
{
  /*<thisrel this+0x0>*/ /*|0x1|*/ char state;
  /*<thisrel this+0x2>*/ /*|0x2|*/ short number;
  /*<thisrel this+0x4>*/ /*|0x1|*/ unsigned char type;
  /*<thisrel this+0x6>*/ /*|0x2|*/ short index;
  /*<thisrel this+0x8>*/ /*|0x4|*/ int dis;
};

struct VIEWPORT_PLAYER_STRUCT // Size 0xC
{
  /*<thisrel this+0x0>*/ /*|0x1|*/ char state;
  /*<thisrel this+0x2>*/ /*|0x2|*/ short number;
  /*<thisrel this+0x4>*/ /*|0x1|*/ unsigned char type;
  /*<thisrel this+0x6>*/ /*|0x2|*/ short index;
  /*<thisrel this+0x8>*/ /*|0x4|*/ int dis;
};

struct tagInterfaceState // Size 0x4
{
  /*<bitfield this+0x0>*/ /*|0x4|*/ unsigned long use:2;
  /*<bitfield this+0x0>*/ /*|0x4|*/ unsigned long state:4;
  /*<bitfield this+0x0>*/ /*|0x4|*/ unsigned long type:10;
};

struct PBMSG_HEAD // Size 0x3
{
  /*<thisrel this+0x0>*/ /*|0x1|*/ unsigned char c;
  /*<thisrel this+0x1>*/ /*|0x1|*/ unsigned char size;
  /*<thisrel this+0x2>*/ /*|0x1|*/ unsigned char headcode;
};

struct PMSG_GUILDINFOSAVE // Size 0x2c
{
  /*<thisrel this+0x0>*/ /*|0x3|*/ struct PBMSG_HEAD h;
  /*<thisrel this+0x3>*/ /*|0x1|*/ unsigned char btGuildType;
  /*<thisrel this+0x4>*/ /*|0x8|*/ char GuildName[8];
  /*<thisrel this+0xc>*/ /*|0x20|*/ unsigned char Mark[32];
};

struct PMSG_PARTYREQUEST // Size 0x5
{
  /*<thisrel this+0x0>*/ /*|0x3|*/ struct PBMSG_HEAD h;
  /*<thisrel this+0x3>*/ /*|0x1|*/ unsigned char NumberH;
  /*<thisrel this+0x4>*/ /*|0x1|*/ unsigned char NumberL;
};

struct OBJECTSTRUCT // Size 0x1968
{
	  /*<thisrel this+0x0>*/ /*|0x4|*/ int m_Index;
	  /*<thisrel this+0x4>*/ /*|0x4|*/ int Connected;
	  /*<thisrel this+0x8>*/ /*|0x1|*/ char LoginMsgSnd;
	  /*<thisrel this+0x9>*/ /*|0x1|*/ char LoginMsgCount;
	  /*<thisrel this+0xa>*/ /*|0x1|*/ char CloseCount;
	  /*<thisrel this+0xb>*/ /*|0x1|*/ char CloseType;
	  /*<thisrel this+0xc>*/ /*|0x4|*/ int bEnableDelCharacter;
	  /*<thisrel this+0x10>*/ /*|0x4|*/ struct _PER_SOCKET_CONTEXT* PerSocketContext;
	  /*<thisrel this+0x14>*/ /*|0x4|*/ unsigned int m_socket;
	  /*<thisrel this+0x18>*/ /*|0x10|*/ char Ip_addr[16];
	  /*<thisrel this+0x28>*/ /*|0x4|*/ int UserNumber;
	  /*<thisrel this+0x2c>*/ /*|0x4|*/ int DBNumber;
	  /*<thisrel this+0x30>*/ /*|0x1|*/ unsigned char Magumsa;
	  /*<thisrel this+0x34>*/ /*|0x4|*/ unsigned long AutoSaveTime;
	  /*<thisrel this+0x38>*/ /*|0x4|*/ unsigned long ConnectCheckTime;
	  /*<thisrel this+0x3c>*/ /*|0x4|*/ unsigned long CheckTick;
	  /*<thisrel this+0x40>*/ /*|0x1|*/ unsigned char CheckSpeedHack;
	  /*<thisrel this+0x44>*/ /*|0x4|*/ unsigned long CheckTick2;
	  /*<thisrel this+0x48>*/ /*|0x1|*/ unsigned char CheckTickCount;
	  /*<thisrel this+0x4c>*/ /*|0x4|*/ unsigned long SaveTimeForStatics;
	  /*<thisrel this+0x50>*/ /*|0x4|*/ int iPingTime;
	  /*<thisrel this+0x54>*/ /*|0x1|*/ unsigned char m_TimeCount;
	  /*<thisrel this+0x58>*/ /*|0x4|*/ unsigned long m_dwPKTimer;
	  /*<thisrel this+0x5c>*/ /*|0x2|*/ short CheckSumTableNum;
	  /*<thisrel this+0x60>*/ /*|0x4|*/ unsigned long CheckSumTime;
	  /*<thisrel this+0x64>*/ /*|0x2|*/ unsigned short Type;
	  /*<thisrel this+0x66>*/ /*|0x1|*/ unsigned char Live;
	  /*<thisrel this+0x67>*/ /*|0x1|*/ char CharacterPos;
	  /*<thisrel this+0x68>*/ /*|0xb|*/ char AccountID[11];
	  /*<thisrel this+0x73>*/ /*|0xb|*/ char Name[11];
	  /*<thisrel this+0x7e>*/ /*|0xe|*/ char LastJoominNumber[14];
	  /*<thisrel this+0x8c>*/ /*|0x1|*/ unsigned char PlusStatQuestClear;
	  /*<thisrel this+0x8d>*/ /*|0x1|*/ unsigned char ComboSkillquestClear;
	  /*<thisrel this+0x8e>*/ /*|0x2|*/ short m_Filler0x8e;
	  /*<thisrel this+0x90>*/ /*|0xc|*/ /*struct ComboSkillData comboSkill;*/ char comboSkill[0xc];
	  /*<thisrel this+0x9c>*/ /*|0x2|*/ unsigned short Class;
	  /*<thisrel this+0x9e>*/ /*|0x1|*/ unsigned char DbClass;
	  /*<thisrel this+0x9f>*/ /*|0x1|*/ unsigned char ChangeUP;
	  /*<thisrel this+0xa0>*/ /*|0x2|*/ short Level;
	  /*<thisrel this+0xa4>*/ /*|0x4|*/ int LevelUpPoint;
	  /*<thisrel this+0xa8>*/ /*|0x4|*/ int iFruitPoint;
	  /*<thisrel this+0xac>*/ /*|0x4|*/ unsigned long Experience;
	  /*<thisrel this+0xb0>*/ /*|0x4|*/ unsigned long NextExp;
	  /*<thisrel this+0xb4>*/ /*|0x4|*/ int Money;
	  /*<thisrel this+0xb8>*/ /*|0x2|*/ short Strength;
	  /*<thisrel this+0xba>*/ /*|0x2|*/ short Dexterity;
	  /*<thisrel this+0xbc>*/ /*|0x2|*/ short Vitality;
	  /*<thisrel this+0xbe>*/ /*|0x2|*/ short Energy;
	  /*<thisrel this+0xc0>*/ /*|0x4|*/ float Life;
	  /*<thisrel this+0xc4>*/ /*|0x4|*/ float MaxLife;
	  /*<thisrel this+0xc8>*/ /*|0x4|*/ int m_iScriptMaxLife;
	  /*<thisrel this+0xcc>*/ /*|0x4|*/ float FillLife;
	  /*<thisrel this+0xd0>*/ /*|0x4|*/ float FillLifeMax;
	  /*<thisrel this+0xd4>*/ /*|0x4|*/ float Mana;
	  /*<thisrel this+0xd8>*/ /*|0x4|*/ float MaxMana;
	  /*<thisrel this+0xdc>*/ /*|0x2|*/ unsigned short Leadership;
	  /*<thisrel this+0xde>*/ /*|0x2|*/ unsigned short AddLeadership;
	  /*<thisrel this+0xe0>*/ /*|0x2|*/ unsigned short ChatLitmitTime;
	  /*<thisrel this+0xe2>*/ /*|0x1|*/ unsigned char ChatLimitTimeSec;
	  /*<thisrel this+0xe3>*/ /*|0x1|*/ unsigned char FillLifeCount;
	  /*<thisrel this+0xe4>*/ /*|0x2|*/ short AddStrength;
	  /*<thisrel this+0xe6>*/ /*|0x2|*/ short AddDexterity;
	  /*<thisrel this+0xe8>*/ /*|0x2|*/ short AddVitality;
	  /*<thisrel this+0xea>*/ /*|0x2|*/ short AddEnergy;
	  /*<thisrel this+0xec>*/ /*|0x4|*/ int BP;
	  /*<thisrel this+0xf0>*/ /*|0x4|*/ int MaxBP;
	  /*<thisrel this+0xf4>*/ /*|0x4|*/ int AddBP;
	  /*<thisrel this+0xf8>*/ /*|0x4|*/ float VitalityToLife;
	  /*<thisrel this+0xfc>*/ /*|0x4|*/ float EnergyToMana;
	  /*<thisrel this+0x100>*/ /*|0x1|*/ char m_PK_Count;
	  /*<thisrel this+0x101>*/ /*|0x1|*/ char m_PK_Level;
	  /*<thisrel this+0x104>*/ /*|0x4|*/ int m_PK_Time;
	  /*<thisrel this+0x108>*/ /*|0x2|*/ short X;
	  /*<thisrel this+0x10a>*/ /*|0x2|*/ short Y;
	  /*<thisrel this+0x10c>*/ /*|0x1|*/ unsigned char Dir;
	  /*<thisrel this+0x10d>*/ /*|0x1|*/ unsigned char MapNumber;
	  /*<thisrel this+0x110>*/ /*|0x4|*/ int AddLife;
	  /*<thisrel this+0x114>*/ /*|0x4|*/ int AddMana;
	  /*<thisrel this+0x118>*/ /*|0x4|*/ int iShield;
	  /*<thisrel this+0x11c>*/ /*|0x4|*/ int iMaxShield;
	  /*<thisrel this+0x120>*/ /*|0x4|*/ int iAddShield;
	  /*<thisrel this+0x124>*/ /*|0x4|*/ int iFillShieldMax;
	  /*<thisrel this+0x128>*/ /*|0x4|*/ int iFillShield;
	  /*<thisrel this+0x12c>*/ /*|0x4|*/ int iFillShieldCount;
	  /*<thisrel this+0x130>*/ /*|0x4|*/ unsigned long dwShieldAutoRefillTimer;
	  /*<thisrel this+0x134>*/ /*|0x1|*/ unsigned char DamageMinus;
	  /*<thisrel this+0x135>*/ /*|0x1|*/ unsigned char DamageReflect;
	  /*<thisrel this+0x136>*/ /*|0x2|*/ short MonsterDieGetMoney;
	  /*<thisrel this+0x138>*/ /*|0x1|*/ unsigned char MonsterDieGetLife;
	  /*<thisrel this+0x139>*/ /*|0x1|*/ unsigned char MonsterDieGetMana;
	  /*<thisrel this+0x13a>*/ /*|0x1|*/ unsigned char StartX;
	  /*<thisrel this+0x13b>*/ /*|0x1|*/ unsigned char StartY;
	  /*<thisrel this+0x13c>*/ /*|0x2|*/ short m_OldX;
	  /*<thisrel this+0x13e>*/ /*|0x2|*/ short m_OldY;
	  /*<thisrel this+0x140>*/ /*|0x2|*/ short TX;
	  /*<thisrel this+0x142>*/ /*|0x2|*/ short TY;
	  /*<thisrel this+0x144>*/ /*|0x2|*/ short MTX;
	  /*<thisrel this+0x146>*/ /*|0x2|*/ short MTY;
	  /*<thisrel this+0x148>*/ /*|0x4|*/ int PathCount;
	  /*<thisrel this+0x14c>*/ /*|0x4|*/ int PathCur;
	  /*<thisrel this+0x150>*/ /*|0x1|*/ char PathStartEnd;
	  /*<thisrel this+0x152>*/ /*|0x1e|*/ short PathOri[15];
	  /*<thisrel this+0x170>*/ /*|0x1e|*/ short PathX[15];
	  /*<thisrel this+0x18e>*/ /*|0x1e|*/ short PathY[15];
	  /*<thisrel this+0x1ac>*/ /*|0xf|*/ char PathDir[15];
	  /*<thisrel this+0x1bc>*/ /*|0x4|*/ unsigned long PathTime;
	  /*<thisrel this+0x1c0>*/ /*|0x1|*/ char m_MoveGateNumber;
	  /*<thisrel this+0x1c4>*/ /*|0x4|*/ unsigned long Authority;
	  /*<thisrel this+0x1c8>*/ /*|0x4|*/ unsigned long AuthorityCode;
	  /*<thisrel this+0x1cc>*/ /*|0x4|*/ unsigned long Penalty;
	  /*<thisrel this+0x1d0>*/ /*|0x1|*/ unsigned char m_cAccountItemBlock;
	  /*<thisrel this+0x1d4>*/ /*|0x4|*/ /*struct tagActionState m_ActState;*/ int m_ActState;
	  /*<thisrel this+0x1d8>*/ /*|0x1|*/ unsigned char m_ActionNumber;
	  /*<thisrel this+0x1dc>*/ /*|0x4|*/ unsigned long m_State;
	  /*<thisrel this+0x1e0>*/ /*|0x1|*/ char m_StateSub;
	  /*<thisrel this+0x1e1>*/ /*|0x1|*/ unsigned char m_Rest;
	  /*<thisrel this+0x1e2>*/ /*|0x1|*/ char m_ViewState;
	  /*<thisrel this+0x1e4>*/ /*|0x4|*/ int m_ViewSkillState;
	  /*<thisrel this+0x1e8>*/ /*|0x4|*/ unsigned long m_LastMoveTime;
	  /*<thisrel this+0x1ec>*/ /*|0x4|*/ unsigned long m_LastAttackTime;
	  /*<thisrel this+0x1f0>*/ /*|0x1|*/ unsigned char m_FriendServerOnline;
	  /*<thisrel this+0x1f4>*/ /*|0x4|*/ int m_DetectSpeedHackTime;
	  /*<thisrel this+0x1f8>*/ /*|0x4|*/ unsigned long m_SumLastAttackTime;
	  /*<thisrel this+0x1fc>*/ /*|0x4|*/ unsigned long m_DetectCount;
	  /*<thisrel this+0x200>*/ /*|0x4|*/ int m_DetectedHackKickCount;
	  /*<thisrel this+0x204>*/ /*|0x4|*/ int m_SpeedHackPenalty;
	  /*<thisrel this+0x208>*/ /*|0x1|*/ unsigned char m_AttackSpeedHackDetectedCount;
	  /*<thisrel this+0x20c>*/ /*|0x4|*/ unsigned long m_PacketCheckTime;
	  /*<thisrel this+0x210>*/ /*|0x1|*/ unsigned char m_ShopTime;
	  /*<thisrel this+0x214>*/ /*|0x4|*/ unsigned long m_TotalAttackTime;
	  /*<thisrel this+0x218>*/ /*|0x4|*/ int m_TotalAttackCount;
	  /*<thisrel this+0x21c>*/ /*|0x4|*/ unsigned long TeleportTime;
	  /*<thisrel this+0x220>*/ /*|0x1|*/ char Teleport;
	  /*<thisrel this+0x221>*/ /*|0x1|*/ char KillerType;
	  /*<thisrel this+0x222>*/ /*|0x1|*/ char DieRegen;
	  /*<thisrel this+0x223>*/ /*|0x1|*/ char RegenOk;
	  /*<thisrel this+0x224>*/ /*|0x1|*/ unsigned char RegenMapNumber;
	  /*<thisrel this+0x225>*/ /*|0x1|*/ unsigned char RegenMapX;
	  /*<thisrel this+0x226>*/ /*|0x1|*/ unsigned char RegenMapY;
	  /*<thisrel this+0x228>*/ /*|0x4|*/ unsigned long RegenTime;
	  /*<thisrel this+0x22c>*/ /*|0x4|*/ unsigned long MaxRegenTime;
	  /*<thisrel this+0x230>*/ /*|0x2|*/ short m_PosNum;
	  /*<thisrel this+0x234>*/ /*|0x4|*/ unsigned long LifeRefillTimer;
	  /*<thisrel this+0x238>*/ /*|0x4|*/ unsigned long CurActionTime;
	  /*<thisrel this+0x23c>*/ /*|0x4|*/ unsigned long NextActionTime;
	  /*<thisrel this+0x240>*/ /*|0x4|*/ unsigned long DelayActionTime;
	  /*<thisrel this+0x244>*/ /*|0x1|*/ char DelayLevel;
	  /*<thisrel this+0x245>*/ /*|0x1|*/ char m_PoisonType;
	  /*<thisrel this+0x246>*/ /*|0x1|*/ char m_IceType;
	  /*<thisrel this+0x247>*/ /*|0x1|*/ char m_PoisonBeattackCount;
	  /*<thisrel this+0x248>*/ /*|0x1|*/ char m_ColdBeattackCount;
	  /*<thisrel this+0x249>*/ /*|0x1|*/ char m_ImmuneToMagicCount;
	  /*<thisrel this+0x24a>*/ /*|0x1|*/ char m_ImmuneToHarmCount;
	  /*<thisrel this+0x24b>*/ /*|0x1|*/ char m_iMonsterBattleDelay;
	  /*<thisrel this+0x24c>*/ /*|0x1|*/ char m_cKalimaGateExist;
	  /*<thisrel this+0x250>*/ /*|0x4|*/ int m_iKalimaGateIndex;
	  /*<thisrel this+0x254>*/ /*|0x1|*/ char m_cKalimaGateEnterCount;
	  /*<thisrel this+0x258>*/ /*|0x4|*/ struct OBJECTSTRUCT* lpAttackObj;
	  /*<thisrel this+0x25c>*/ /*|0x2|*/ short m_SkillNumber;
	  /*<thisrel this+0x260>*/ /*|0x4|*/ unsigned long m_SkillTime;
	  /*<thisrel this+0x264>*/ /*|0x1|*/ unsigned char m_bAttackerKilled;
	  /*<thisrel this+0x265>*/ /*|0x1|*/ char m_ManaFillCount;
	  /*<thisrel this+0x266>*/ /*|0x1|*/ char m_LifeFillCount;
	  /*<thisrel this+0x268>*/ /*|0x14|*/ int SelfDefense[5];
	  /*<thisrel this+0x27c>*/ /*|0x14|*/ unsigned long SelfDefenseTime[5];
	  /*<thisrel this+0x290>*/ /*|0x4|*/ unsigned long MySelfDefenseTime;
	  /*<thisrel this+0x294>*/ /*|0x1|*/ char m_Drink;
	  /*<thisrel this+0x298>*/ /*|0x4|*/ int m_SkillDefense;
	  /*<thisrel this+0x29c>*/ /*|0x1|*/ char m_SkillDefenseTime;
	  /*<thisrel this+0x2a0>*/ /*|0x4|*/ int m_SkillAttack;
	  /*<thisrel this+0x2a4>*/ /*|0x1|*/ char m_SkillAttackTime;
	  /*<thisrel this+0x2a8>*/ /*|0x4|*/ int m_SkillAttack2;
	  /*<thisrel this+0x2ac>*/ /*|0x1|*/ char m_SkillAttackTime2;
	  /*<thisrel this+0x2b0>*/ /*|0x4|*/ int m_SkillAddLife;
	  /*<thisrel this+0x2b4>*/ /*|0x4|*/ int m_SkillAddLifeTime;
	  /*<thisrel this+0x2b8>*/ /*|0x4|*/ int m_SkillHarden;
	  /*<thisrel this+0x2bc>*/ /*|0x4|*/ int m_SkillHardenTime;
	  /*<thisrel this+0x2c0>*/ /*|0x4|*/ int m_SkillMagumReduceDefense;
	  /*<thisrel this+0x2c4>*/ /*|0x4|*/ int m_SkillMagumReduceDefenseTime;
	  /*<thisrel this+0x2c8>*/ /*|0x4|*/ int PartyNumber;
	  /*<thisrel this+0x2cc>*/ /*|0x4|*/ int PartyTargetUser;
	  /*<thisrel this+0x2d0>*/ /*|0x4|*/ int GuildNumber;
	  /*<thisrel this+0x2d4>*/ /*|0x4|*/ /*struct _GUILD_INFO_STRUCT* lpGuild;*/ int lpGuild;
	  /*<thisrel this+0x2d8>*/ /*|0xb|*/ char GuildName[11];
	  /*<thisrel this+0x2e4>*/ /*|0x4|*/ int GuildStatus;
	  /*<thisrel this+0x2e8>*/ /*|0x4|*/ int iGuildUnionTimeStamp;
	  /*<thisrel this+0x2ec>*/ /*|0x4|*/ int m_RecallMon;
	  /*<thisrel this+0x2f0>*/ /*|0x4|*/ int m_Change;
	  /*<thisrel this+0x2f4>*/ /*|0x2|*/ short TargetNumber;
	  /*<thisrel this+0x2f6>*/ /*|0x2|*/ short TargetShopNumber;
	  /*<thisrel this+0x2f8>*/ /*|0x2|*/ short ShopNumber;
	  /*<thisrel this+0x2fa>*/ /*|0x2|*/ short LastAttackerID;
	  /*<thisrel this+0x2fc>*/ /*|0x4|*/ int m_AttackDamageMin;
	  /*<thisrel this+0x300>*/ /*|0x4|*/ int m_AttackDamageMax;
	  /*<thisrel this+0x304>*/ /*|0x4|*/ int m_MagicDamageMin;
	  /*<thisrel this+0x308>*/ /*|0x4|*/ int m_MagicDamageMax;
	  /*<thisrel this+0x30c>*/ /*|0x4|*/ int m_AttackDamageLeft;
	  /*<thisrel this+0x310>*/ /*|0x4|*/ int m_AttackDamageRight;
	  /*<thisrel this+0x314>*/ /*|0x4|*/ int m_AttackDamageMaxLeft;
	  /*<thisrel this+0x318>*/ /*|0x4|*/ int m_AttackDamageMinLeft;
	  /*<thisrel this+0x31c>*/ /*|0x4|*/ int m_AttackDamageMaxRight;
	  /*<thisrel this+0x320>*/ /*|0x4|*/ int m_AttackDamageMinRight;
	  /*<thisrel this+0x324>*/ /*|0x4|*/ int m_AttackRating;
	  /*<thisrel this+0x328>*/ /*|0x4|*/ int m_AttackSpeed;
	  /*<thisrel this+0x32c>*/ /*|0x4|*/ int m_MagicSpeed;
	  /*<thisrel this+0x330>*/ /*|0x4|*/ int m_Defense;
	  /*<thisrel this+0x334>*/ /*|0x4|*/ int m_MagicDefense;
	  /*<thisrel this+0x338>*/ /*|0x4|*/ int m_SuccessfulBlocking;
	  /*<thisrel this+0x33c>*/ /*|0x2|*/ short m_MoveSpeed;
	  /*<thisrel this+0x33e>*/ /*|0x2|*/ short m_MoveRange;
	  /*<thisrel this+0x340>*/ /*|0x2|*/ short m_AttackRange;
	  /*<thisrel this+0x342>*/ /*|0x2|*/ short m_AttackType;
	  /*<thisrel this+0x344>*/ /*|0x2|*/ short m_ViewRange;
	  /*<thisrel this+0x346>*/ /*|0x2|*/ short m_Attribute;
	  /*<thisrel this+0x348>*/ /*|0x2|*/ short m_ItemRate;
	  /*<thisrel this+0x34a>*/ /*|0x2|*/ short m_MoneyRate;
	  /*<thisrel this+0x34c>*/ /*|0x4|*/ int m_CriticalDamage;
	  /*<thisrel this+0x350>*/ /*|0x4|*/ int m_ExcelentDamage;
	  /*<thisrel this+0x354>*/ /*|0x4|*/ /*class CMagicInf* m_lpMagicBack;*/ int m_lpMagicBack;
	  /*<thisrel this+0x358>*/ /*|0x4|*/ /*class CMagicInf* Magic;*/ int Magic;
	  /*<thisrel this+0x35c>*/ /*|0x1|*/ char MagicCount;
	  /*<thisrel this+0x35d>*/ /*|0x1|*/ unsigned char UseMagicNumber;
	  /*<thisrel this+0x360>*/ /*|0x4|*/ unsigned long UseMagicTime;
	  /*<thisrel this+0x364>*/ /*|0x1|*/ char UseMagicCount;
	  /*<thisrel this+0x366>*/ /*|0x2|*/ short OSAttackSerial;
	  /*<thisrel this+0x368>*/ /*|0x1|*/ unsigned char SASCount;
	  /*<thisrel this+0x36c>*/ /*|0x4|*/ unsigned long SkillAttackTime;
	  /*<thisrel this+0x370>*/ /*|0x12|*/ unsigned char CharSet[18];
	  /*<thisrel this+0x382>*/ /*|0x7|*/ unsigned char m_Resistance[7];
	  /*<thisrel this+0x389>*/ /*|0x7|*/ unsigned char m_AddResistance[7];
	  /*<thisrel this+0x390>*/ /*|0x10|*/ int FrustrumX[4];
	  /*<thisrel this+0x3a0>*/ /*|0x10|*/ int FrustrumY[4];
	  /*<thisrel this+0x3b0>*/ /*|0x384|*/ /*struct VIEWPORT_STRUCT VpPlayer[75];*/ char VpPlayer[0x384];
	  /*<thisrel this+0x734>*/ /*|0x384|*/ /*struct VIEWPORT_PLAYER_STRUCT VpPlayer2[75];*/ char VpPlayer2[0x384];
	  /*<thisrel this+0xab8>*/ /*|0x4|*/ int VPCount;
	  /*<thisrel this+0xabc>*/ /*|0x4|*/ int VPCount2;
	  /*<thisrel this+0xac0>*/ /*|0x1e0|*/ /*struct HITDAMAGE_STRUCT sHD[40];*/ char sHD[0x1e0];
	  /*<thisrel this+0xca0>*/ /*|0x2|*/ short sHDCount;
	  /*<thisrel this+0xca4>*/ /*|0x4|*/ struct tagInterfaceState m_IfState;
	  /*<thisrel this+0xca8>*/ /*|0x4|*/ unsigned long m_InterfaceTime;
	  /*<thisrel this+0xcac>*/ /*|0x4|*/ /*class CItem* pInventory;*/ ITEMSTRUCT *pInventory;
	  /*<thisrel this+0xcb0>*/ /*|0x4|*/ unsigned char* pInventoryMap;
	  /*<thisrel this+0xcb4>*/ /*|0x4|*/ char* pInventoryCount;
	  /*<thisrel this+0xcb8>*/ /*|0x1|*/ char pTransaction;
	  /*<thisrel this+0xcbc>*/ /*|0x4|*/ ITEMSTRUCT *pInventory1; /*ITEMSTRUCT *pInventory;*/
	  /*<thisrel this+0xcc0>*/ /*|0x4|*/ unsigned char* InventoryMap1;
	  /*<thisrel this+0xcc4>*/ /*|0x1|*/ char InventoryCount1;
	  /*<thisrel this+0xcc8>*/ /*|0x4|*/ class CItem* pInventory2; /*ITEMSTRUCT *pInventory;*/
	  /*<thisrel this+0xccc>*/ /*|0x4|*/ unsigned char* InventoryMap2;
	  /*<thisrel this+0xcd0>*/ /*|0x1|*/ char InventoryCount2;
	  /*<thisrel this+0xcd4>*/ /*|0x4|*/ class CItem* pTrade; /*ITEMSTRUCT *pInventory;*/
	  /*<thisrel this+0xcd8>*/ /*|0x4|*/ unsigned char* TradeMap;
	  /*<thisrel this+0xcdc>*/ /*|0x4|*/ int TradeMoney;
	  /*<thisrel this+0xce0>*/ /*|0x1|*/ unsigned char TradeOk;
	  /*<thisrel this+0xce4>*/ /*|0x4|*/ class CItem* pWarehouse; /*ITEMSTRUCT *pInventory;*/
	  /*<thisrel this+0xce8>*/ /*|0x4|*/ unsigned char* pWarehouseMap;
	  /*<thisrel this+0xcec>*/ /*|0x1|*/ char WarehouseCount;
	  /*<thisrel this+0xced>*/ /*|0x1|*/ char m_Filler0xced;
	  /*<thisrel this+0xcee>*/ /*|0x2|*/ short WarehousePW;
	  /*<thisrel this+0xcf0>*/ /*|0x1|*/ unsigned char WarehouseLock;
	  /*<thisrel this+0xcf1>*/ /*|0x1|*/ unsigned char WarehouseUnfailLock;
	  /*<thisrel this+0xcf4>*/ /*|0x4|*/ int WarehouseMoney;
	  /*<thisrel this+0xcf8>*/ /*|0x4|*/ int WarehouseSave;
	  /*<thisrel this+0xcfc>*/ /*|0x4|*/ class CItem* pChaosBox; /*ITEMSTRUCT *pInventory;*/
	  /*<thisrel this+0xd00>*/ /*|0x4|*/ unsigned char* pChaosBoxMap;
	  /*<thisrel this+0xd04>*/ /*|0x4|*/ int ChaosMoney;
	  /*<thisrel this+0xd08>*/ /*|0x4|*/ int ChaosSuccessRate;
	  /*<thisrel this+0xd0c>*/ /*|0x4|*/ int ChaosLock;
	  /*<thisrel this+0xd10>*/ /*|0x4|*/ unsigned long m_Option;
	  /*<thisrel this+0xd14>*/ /*|0x4|*/ int m_nEventScore;
	  /*<thisrel this+0xd18>*/ /*|0x4|*/ int m_nEventExp;
	  /*<thisrel this+0xd1c>*/ /*|0x4|*/ int m_nEventMoney;
	  /*<thisrel this+0xd20>*/ /*|0x1|*/ unsigned char m_bDevilSquareIndex;
	  /*<thisrel this+0xd21>*/ /*|0x1|*/ unsigned char m_bDevilSquareAuth;
	  /*<thisrel this+0xd22>*/ /*|0x1|*/ char m_cBloodCastleIndex;
	  /*<thisrel this+0xd23>*/ /*|0x1|*/ char m_cBloodCastleSubIndex;
	  /*<thisrel this+0xd24>*/ /*|0x4|*/ int m_iBloodCastleEXP;
	  /*<thisrel this+0xd28>*/ /*|0x1|*/ unsigned char m_bBloodCastleComplete;
	  /*<thisrel this+0xd29>*/ /*|0x1|*/ char m_cChaosCastleIndex;
	  /*<thisrel this+0xd2a>*/ /*|0x1|*/ char m_cChaosCastleSubIndex;
	  /*<thisrel this+0xd2c>*/ /*|0x4|*/ int m_iChaosCastleBlowTime;
	  /*<thisrel this+0xd30>*/ /*|0x1|*/ char m_cKillUserCount;
	  /*<thisrel this+0xd31>*/ /*|0x1|*/ char m_cKillMonsterCount;
	  /*<thisrel this+0xd34>*/ /*|0x4|*/ int m_iDuelUserReserved;
	  /*<thisrel this+0xd38>*/ /*|0x4|*/ int m_iDuelUserRequested;
	  /*<thisrel this+0xd3c>*/ /*|0x4|*/ int m_iDuelUser;
	  /*<thisrel this+0xd40>*/ /*|0x1|*/ unsigned char m_btDuelScore;
	  /*<thisrel this+0xd44>*/ /*|0x4|*/ int m_iDuelTickCount;
	  /*<thisrel this+0xd48>*/ /*|0x1|*/ unsigned char m_bPShopOpen;
	  /*<thisrel this+0xd49>*/ /*|0x1|*/ unsigned char m_bPShopTransaction;
	  /*<thisrel this+0xd4a>*/ /*|0x1|*/ unsigned char m_bPShopItemChange;
	  /*<thisrel this+0xd4b>*/ /*|0x1|*/ unsigned char m_bPShopRedrawAbs;
	  /*<thisrel this+0xd4c>*/ /*|0x24|*/ char m_szPShopText[36];
	  /*<thisrel this+0xd70>*/ /*|0x1|*/ unsigned char m_bPShopWantDeal;
	  /*<thisrel this+0xd74>*/ /*|0x4|*/ int m_iPShopDealerIndex;
	  /*<thisrel this+0xd78>*/ /*|0xa|*/ char m_szPShopDealerName[10];
	  /*<thisrel this+0xd84>*/ /*|0x18|*/ struct _RTL_CRITICAL_SECTION m_critPShopTrade;
	  /*<thisrel this+0xd9c>*/ /*|0x12c|*/ int m_iVpPShopPlayer[75];
	  /*<thisrel this+0xec8>*/ /*|0x2|*/ unsigned short m_wVpPShopPlayerCount;
	  /*<thisrel this+0xeca>*/ /*|0x1|*/ unsigned char IsInBattleGround;
	  /*<thisrel this+0xecb>*/ /*|0x1|*/ unsigned char HaveWeaponInHand;
	  /*<thisrel this+0xecc>*/ /*|0x2|*/ short EventChipCount;
	  /*<thisrel this+0xed0>*/ /*|0x4|*/ int MutoNumber;
	  /*<thisrel this+0xed4>*/ /*|0x4|*/ int UseEventServer;
	  /*<thisrel this+0xed8>*/ /*|0x1|*/ unsigned char LoadWareHouseInfo;
	  /*<thisrel this+0xedc>*/ /*|0x4|*/ int iStoneCount;
	  /*<thisrel this+0xee0>*/ /*|0x32|*/ unsigned char m_Quest[50];
	  /*<thisrel this+0xf12>*/ /*|0x1|*/ unsigned char m_SendQuestInfo;
	  /*<thisrel this+0xf14>*/ /*|0x4|*/ int m_SkyBossMonSheildLinkIndex;
	  /*<thisrel this+0xf18>*/ /*|0x4|*/ int m_SkyBossMonSheild;
	  /*<thisrel this+0xf1c>*/ /*|0x4|*/ int m_SkyBossMonSheildTime;
	  /*<thisrel this+0xf20>*/ /*|0x4|*/ int m_MaxLifePower;
	  /*<thisrel this+0xf24>*/ /*|0x4|*/ int m_WizardSkillDefense;
	  /*<thisrel this+0xf28>*/ /*|0x4|*/ int m_WizardSkillDefenseTime;
	  /*<thisrel this+0xf2c>*/ /*|0x4|*/ int m_PacketChecksumTime;
	  /*<thisrel this+0xf30>*/ /*|0x4|*/ int m_CheckLifeTime;
	  /*<thisrel this+0xf34>*/ /*|0x1|*/ unsigned char m_MoveOtherServer;
	  /*<thisrel this+0xf35>*/ /*|0xb|*/ char BackName[11];
	  /*<thisrel this+0xf40>*/ /*|0x1|*/ char m_BossGoldDerconMapNumber;
	  /*<thisrel this+0xf41>*/ /*|0x1|*/ unsigned char m_InWebzen;
	  /*<thisrel this+0xf42>*/ /*|0x1|*/ char m_LastTeleportTime;
	  /*<thisrel this+0xf43>*/ /*|0x1|*/ unsigned char m_ClientHackLogCount;
	  /*<thisrel this+0xf44>*/ /*|0x4|*/ int m_bIsInMonsterHerd;
	  /*<thisrel this+0xf48>*/ /*|0x4|*/ int m_bIsMonsterAttackFirst;
	  /*<thisrel this+0xf4c>*/ /*|0x4|*/ /*class MonsterHerd* m_lpMonsterHerd;*/ int m_lpMonsterHerd;
	  /*<thisrel this+0xf50>*/ /*|0x2c|*/ /*class CCSAuth2 NPggCSAuth;*/ char NPggCSAuth[0x2c];
	  /*<thisrel this+0xf7c>*/ /*|0x1|*/ unsigned char m_bSentGGAuth;
	  /*<thisrel this+0xf80>*/ /*|0x4|*/ unsigned long m_NPggCheckSumSendTime;
	  /*<thisrel this+0xf84>*/ /*|0x10|*/ int fSkillFrustrumX[4];
	  /*<thisrel this+0xf94>*/ /*|0x10|*/ int fSkillFrustrumY[4];
	  /*<thisrel this+0xfa4>*/ /*|0x1|*/ unsigned char SkillHellFire2State;
	  /*<thisrel this+0xfa5>*/ /*|0x1|*/ unsigned char SkillHellFire2Count;
	  /*<thisrel this+0xfa8>*/ /*|0x4|*/ unsigned long SkillHellFire2Time;
	  /*<thisrel this+0xfac>*/ /*|0x1|*/ unsigned char m_ReqWarehouseOpen;
	  /*<thisrel this+0xfb0>*/ /*|0x4|*/ int m_NotAttackAreaCount;
	  /*<thisrel this+0xfb4>*/ /*|0x2|*/ short SetOpAddSkillAttack;
	  /*<thisrel this+0xfb6>*/ /*|0x2|*/ short SetOpAddExDamage;
	  /*<thisrel this+0xfb8>*/ /*|0x2|*/ short SetOpAddExDamageSuccessRate;
	  /*<thisrel this+0xfba>*/ /*|0x2|*/ short SetOpAddCriticalDamage;
	  /*<thisrel this+0xfbc>*/ /*|0x2|*/ short SetOpAddCriticalDamageSuccessRate;
	  /*<thisrel this+0xfbe>*/ /*|0x2|*/ short SetOpIncAGValue;
	  /*<thisrel this+0xfc0>*/ /*|0x2|*/ short SetOpAddDamage;
	  /*<thisrel this+0xfc2>*/ /*|0x2|*/ short SetOpAddMinAttackDamage;
	  /*<thisrel this+0xfc4>*/ /*|0x2|*/ short SetOpAddMaxAttackDamage;
	  /*<thisrel this+0xfc6>*/ /*|0x2|*/ short SetOpAddAttackDamage;
	  /*<thisrel this+0xfc8>*/ /*|0x2|*/ short SetOpAddDefence;
	  /*<thisrel this+0xfca>*/ /*|0x2|*/ short SetOpAddDefenceRate;
	  /*<thisrel this+0xfcc>*/ /*|0x2|*/ short SetOpAddMagicPower;
	  /*<thisrel this+0xfce>*/ /*|0x1|*/ unsigned char SetOpIgnoreDefense;
	  /*<thisrel this+0xfcf>*/ /*|0x1|*/ unsigned char SetOpDoubleDamage;
	  /*<thisrel this+0xfd0>*/ /*|0x1|*/ unsigned char SetOpTwoHandSwordImproveDamage;
	  /*<thisrel this+0xfd1>*/ /*|0x1|*/ unsigned char SetOpImproveSuccessAttackRate;
	  /*<thisrel this+0xfd2>*/ /*|0x1|*/ unsigned char SetOpReflectionDamage;
	  /*<thisrel this+0xfd3>*/ /*|0x1|*/ unsigned char SetOpImproveSheldDefence;
	  /*<thisrel this+0xfd4>*/ /*|0x1|*/ unsigned char SetOpDecreaseAG;
	  /*<thisrel this+0xfd5>*/ /*|0x1|*/ unsigned char SetOpImproveItemDropRate;
	  /*<thisrel this+0xfd6>*/ /*|0x1|*/ unsigned char IsFullSetItem;
	  /*<thisrel this+0xfd8>*/ /*|0x12c|*/ /*class TDurMagicKeyChecker DurMagicKeyChecker;*/ char DurMagicKeyChecker[0x12c];
	  /*<thisrel this+0x1104>*/ /*|0x2|*/ unsigned short SkillRecallParty_Time;
	  /*<thisrel this+0x1106>*/ /*|0x1|*/ unsigned char SkillRecallParty_MapNumber;
	  /*<thisrel this+0x1107>*/ /*|0x1|*/ unsigned char SkillRecallParty_X;
	  /*<thisrel this+0x1108>*/ /*|0x1|*/ unsigned char SkillRecallParty_Y;
	  /*<thisrel this+0x110a>*/ /*|0x2|*/ unsigned short SkillAddCriticalDamageTime;
	  /*<thisrel this+0x110c>*/ /*|0x2|*/ unsigned short SkillAddCriticalDamage;
	  /*<thisrel this+0x110e>*/ /*|0x1|*/ unsigned char bIsChaosMixCompleted;
	  /*<thisrel this+0x110f>*/ /*|0x1|*/ unsigned char SkillLongSpearChange;
	  /*<thisrel this+0x1110>*/ /*|0x404|*/ /*class CSkillDelay SkillDelay;*/ char SkillDelay[0x404];
	  /*<thisrel this+0x1514>*/ /*|0x4|*/ int iObjectSecTimer;
	  /*<thisrel this+0x1518>*/ /*|0x1|*/ unsigned char m_bMapSvrMoveQuit;
	  /*<thisrel this+0x1519>*/ /*|0x1|*/ unsigned char m_bMapSvrMoveReq;
	  /*<thisrel this+0x151c>*/ /*|0x4|*/ unsigned long m_dwMapSvrQuitTick;
	  /*<thisrel this+0x1520>*/ /*|0x2|*/ short m_sPrevMapSvrCode;
	  /*<thisrel this+0x1522>*/ /*|0x2|*/ short m_sDestMapNumber;
	  /*<thisrel this+0x1524>*/ /*|0x1|*/ unsigned char m_btDestX;
	  /*<thisrel this+0x1525>*/ /*|0x1|*/ unsigned char m_btDestY;
	  /*<thisrel this+0x1526>*/ /*|0x1|*/ unsigned char m_bIsCastleNPCUpgradeCompleted;
	  /*<thisrel this+0x1527>*/ /*|0x1|*/ unsigned char m_btWeaponState;
	  /*<thisrel this+0x1528>*/ /*|0x4|*/ int m_iWeaponUser;
	  /*<thisrel this+0x152c>*/ /*|0x1|*/ unsigned char m_btKillCount;
	  /*<thisrel this+0x1530>*/ /*|0x4|*/ int m_iSkillStunTime;
	  /*<thisrel this+0x1534>*/ /*|0x4|*/ int m_iSkillBrandOfSkillTime;
	  /*<thisrel this+0x1538>*/ /*|0x4|*/ int m_iSkillInvisibleTime;
	  /*<thisrel this+0x153c>*/ /*|0x4|*/ int m_iSkillManaSwellTime;
	  /*<thisrel this+0x1540>*/ /*|0x4|*/ int m_iSkillManaSwell;
	  /*<thisrel this+0x1544>*/ /*|0x4|*/ int m_iAccumulatedDamage;
	  /*<thisrel this+0x1548>*/ /*|0x4|*/ int m_iPotionBlessTime;
	  /*<thisrel this+0x154c>*/ /*|0x4|*/ int m_iPotionSoulTime;
	  /*<thisrel this+0x1550>*/ /*|0x4|*/ int m_iAccumulatedCrownAccessTime;
	  /*<thisrel this+0x1554>*/ /*|0x50|*/ /*class TMonsterSkillElementInfo m_MonsterSkillElementInfo;*/ char m_MonsterSkillElementInfo[0x50];
	  /*<thisrel this+0x15a4>*/ /*|0x4|*/ int m_iBasicAI;
	  /*<thisrel this+0x15a8>*/ /*|0x4|*/ int m_iCurrentAI;
	  /*<thisrel this+0x15ac>*/ /*|0x4|*/ int m_iCurrentAIState;
	  /*<thisrel this+0x15b0>*/ /*|0x4|*/ int m_iLastAIRunTime;
	  /*<thisrel this+0x15b4>*/ /*|0x4|*/ int m_iGroupNumber;
	  /*<thisrel this+0x15b8>*/ /*|0x4|*/ int m_iSubGroupNumber;
	  /*<thisrel this+0x15bc>*/ /*|0x4|*/ int m_iGroupMemberGuid;
	  /*<thisrel this+0x15c0>*/ /*|0x4|*/ int m_iRegenType;
	  /*<thisrel this+0x15c4>*/ /*|0x324|*/ /*class TMonsterAIAgro m_Agro;*/ char m_Agro[0x324];
	  /*<thisrel this+0x18e8>*/ /*|0x4|*/ int m_iLastAutomataRuntime;
	  /*<thisrel this+0x18ec>*/ /*|0x4|*/ int m_iLastAutomataDelay;
	  /*<thisrel this+0x18f0>*/ /*|0x4|*/ int m_iCrywolfMVPScore;
	  /*<thisrel this+0x18f4>*/ /*|0x4|*/ unsigned long m_dwLastCheckTick;
	  /*<thisrel this+0x18f8>*/ /*|0x4|*/ int m_iAutoRecuperationTime;
	  /*<thisrel this+0x18fc>*/ /*|0x4|*/ int m_iSkillNPCHelpTime;
	  /*<thisrel this+0x1900>*/ /*|0x4|*/ int m_iSkillNPCDefense;
	  /*<thisrel this+0x1904>*/ /*|0x4|*/ int m_iSkillNPCAttack;
	  /*<thisrel this+0x1908>*/ /*|0x4|*/ int m_iMuseElfInfinityArrowSkillTime;
	  /*<thisrel this+0x190c>*/ /*|0x4|*/ int m_iSkillDistanceErrorCount;
	  /*<thisrel this+0x1910>*/ /*|0x4|*/ unsigned long m_dwSkillDistanceErrorTick;
	  /*<thisrel this+0x1914>*/ /*|0x26|*/ /*struct JEWELOFHARMONY_ITEM_EFFECT m_JewelOfHarmonyEffect;*/ char m_JewelOfHarmonyEffect[0x26];
	  /*<thisrel this+0x193a>*/ /*|0x10|*/ /*struct ITEMOPTION_FOR380ITEM_EFFECT m_ItemOptionExFor380;*/ char m_ItemOptionExFor380[0x10];
	  /*<thisrel this+0x194c>*/ /*|0x4|*/ int m_bKanturuEntranceByNPC;
	  /*<thisrel this+0x1950>*/ /*|0x2|*/ unsigned short m_wItemEffectType;
	  /*<thisrel this+0x1954>*/ /*|0x4|*/ int m_iItemEffectValidTime;
	  /*<thisrel this+0x1958>*/ /*|0x2|*/ unsigned short m_wCashPoint;
	  /*<thisrel this+0x195c>*/ /*|0x4|*/ int m_iPeriodItemEffectIndex;
	  /*<thisrel this+0x1960>*/ /*|0x2|*/ unsigned short m_wExprienceRate;
	  /*<thisrel this+0x1962>*/ /*|0x2|*/ unsigned short m_wItemDropRate;
	  /*<thisrel this+0x1964>*/ /*|0x1|*/ unsigned char m_btMoveMapBound;
	  /*<thisrel this+0x1965>*/ /*|0x3B|*/ unsigned char m_Filler0x1965[0x3B];
};

// Expand Player Structure
extern OBJECTSTRUCT* gObj;

#endif