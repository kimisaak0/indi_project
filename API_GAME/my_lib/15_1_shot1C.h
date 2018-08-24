#pragma once

#include "11_CollisionObjC.h"

class shot1C : public CollisionObjC
{
protected:
	double m_dSpriteSpeed;
	int    m_iSpriteDir;

public:
	void setSpeed(double sx, double sy);

	bool Frame() override;
	bool Render() override;

};