#pragma once
#include "01_header.h"
#include "19_0_EffectC.h"

class EffectMgrC : public SingleMgr<EffectMgrC>
{
	friend class SingleMgr<EffectMgrC>;

private:
	vector<vector<EffectC*>> m_Effect_vector;
	vector<int> m_Effect_amount;
	vector<int> m_Effect_current_Number;

public:
	bool RegisterEffect(EffectC* ef, int index, int i);

	bool Play(int iIndex, double x, double y);
};

#define I_EffectMgr EffectMgrC::GetInstance()