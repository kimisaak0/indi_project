#pragma once

#include "08_ObjC.h"

class EffectC : public ObjC
{
public:
	virtual void PlayPos(double x, double y);

	bool Init() override;
	bool Frame() override;
	bool Render() override;
	bool Release() override;

	virtual bool getExist();
};