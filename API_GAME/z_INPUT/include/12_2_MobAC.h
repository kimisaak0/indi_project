#pragma once
#include "11_CollisionObjC.h"
#include "19_1_SpriteDead1C.h"

class MobAC : public CollisionObjC
{
protected:
	static int  g_maxId;
	int         m_iId;

	double      m_dSpriteSpeed;
	int         m_iSpriteIndex;

	double      m_dDirChg;
	double      m_dMoveCycleSpeed;

	SpriteDead1C m_dead;

public:
	bool Init() override;
	bool Frame() override;
	bool Render() override;

	dPointC getPt();


public:
	MobAC();
	virtual ~MobAC();
};