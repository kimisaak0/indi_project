#pragma once
#include "11_CollisionObjC.h"

class ShotLaserC : public CollisionObjC
{
protected:
	double m_dSpriteSpeed;
	int    m_iSpriteDir;

	double m_dAngle;

	dPointC m_ptSpawnPos;

public:
	void setSpeed(double sx, double sy);
	void setSpawn(double sx, double sy);

	bool Frame() override;
	bool Render() override;

	dPointC getSpawn();
};