#pragma once
#include "11_CollisionObjC.h"

#include "15_1_shot1C.h"
#include "15_2_ShotLaserC.h"

#include "21_sonaC.h"

class HeroObjC : public CollisionObjC
{
protected:
	double m_dSpriteSpeed;

	double m_dSpeedX;
	double m_dSpeedY;

	double m_dShotDelay;

	int    m_iShotNum;
	
	bool   m_bSonaSw;

public:
	sonaC  m_sona;
	list<shot1C> shot1_list;
	list<ShotLaserC> shotLaser_list;

	bool Init() override;
	bool Frame() override;
	bool Render() override;
	bool Release() override;

	void addShort1(POINT mousePos);
	void addLaserShort(POINT mousePos);

	bool getSonaSw();


public:
	HeroObjC();
	virtual ~HeroObjC();
};