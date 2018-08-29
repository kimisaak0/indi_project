#pragma once
#include "01_header.h"
#include "19_0_EffectC.h"

class EffectMgrC : public SingleMgr<EffectMgrC>
{
	friend class SingleMgr<EffectMgrC>;

private:
	vector<EffectC*> m_Effect_vector;

public:
	bool Load(EffectC* ef);

	bool Play(int iIndex, double x, double y);
};

#define I_EffectMgr EffectMgrC::GetInstance()