#ifndef __GUILDSYSTEM_H__
#define __GUILDSYSTEM_H__


// Guild System
class CGuildSystem
{
public:

	void Init();
	void Check(int aIndex, PMSG_GUILDINFOSAVE *lpMsg);

private:

	int m_Enabled;
	int m_Price;
	int m_MaxGuilds;
};

extern CGuildSystem GuildSystem;

#endif