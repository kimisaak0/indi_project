#pragma once
#include "11_CollisionObjC.h"

class NpcObjC : public CollisionObjC
{
protected:
	double      m_dSpriteSpeed;
	int         m_iSpriteIndex;

	double      m_dDirChgSpeed;
	Direction   m_dirRand;
	
	

public:
	bool Frame() override;
	bool Render() override;

public:
	NpcObjC();
	virtual ~NpcObjC();
};