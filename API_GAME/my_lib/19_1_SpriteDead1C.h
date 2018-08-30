#pragma once

#include "19_0_EffectC.h"

class SpriteDead1C : public EffectC
{
protected:
	double m_dSpriteSpeed;

public:
	EffectC * Clone() override;

	bool Frame() override;
	bool Render() override;
	

public:
	SpriteDead1C();
	~SpriteDead1C();
};