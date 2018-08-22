#pragma once
#include "11_CollisionObjC.h"

class MobAC : public CollisionObjC
{
protected:
	double      m_dSpriteSpeed;
	int         m_iSpriteIndex;

	double      m_dDirChg;
	double      m_dMoveCycleSpeed;

public:
	bool Frame() override;
	bool Render() override;

public:
	MobAC();
	virtual ~MobAC();
};