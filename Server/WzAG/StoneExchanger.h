#ifndef __EXCHANGER_H__
#define __EXCHANGER_H__

// Stone Exchanger
class CExchanger
{
public:

	void Init();
	int CheckStones(int aIndex);
	void Talk(int aIndex,int Monster);

private:

	int m_Enabled;
	int m_Count;
};

extern CExchanger Exchanger;

#endif