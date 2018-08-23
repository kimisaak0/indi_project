#pragma once

#include "11_CollisionObjC.h"

class shot1C : public CollisionObjC
{
public:
	void setSpeed(double sx, double sy);

	bool Frame() override;
	bool Render() override;

};