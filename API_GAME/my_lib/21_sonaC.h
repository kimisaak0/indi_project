#pragma once
#include "11_CollisionObjC.h"

class sonaC : public CollisionObjC
{
protected:
	double m_dSpriteSpeed;
	double m_dRad;

public:
	bool Frame() override;
	bool Render() override;

	void setPos(dPointC pt);

public:
	sonaC();
	virtual ~sonaC();
};