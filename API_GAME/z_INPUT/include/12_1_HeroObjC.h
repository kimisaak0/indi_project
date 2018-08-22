#pragma once

#include "11_CollisionObjC.h"

class HeroObjC : public CollisionObjC
{
protected:
	double m_dSpriteSpeed;

public:
	bool Frame() override;
	bool Render() override;

public:
	HeroObjC();
	virtual ~HeroObjC();
};