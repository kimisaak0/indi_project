#pragma once

#include "08_ObjC.h"

class SpriteDead1C : public ObjC
{
protected:
	double m_dSpriteSpeed;

public:
	bool Frame() override;
	bool Render() override;

public:
	SpriteDead1C();
	~SpriteDead1C();
};