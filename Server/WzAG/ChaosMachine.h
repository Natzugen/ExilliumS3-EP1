#ifndef __CHAOSMACHINE_H__
#define __CHAOSMACHINE_H__

// Chaos Machine
class CChaosMachine
{
public:

	void Init();
	void ChaosMixFailSend(int aIndex);
	int GetChaosItemLevel(int aIndex,int Item);
	int CheckChaosItem(int aIndex,int Item);
	int CheckChaosItemRange(int aIndex,int ItemMin,int ItemMax);
	int GetChaosItemRange(int aIndex,int ItemMin,int ItemMax);
	int GetChaosItemCount(int aIndex,int Item);
	void ChaosBoxHook(int aIndex,int MixNumber);

private:

	int m_MixRate;
};

extern CChaosMachine ChaosMachine;

#endif