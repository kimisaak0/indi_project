#pragma once
#include "11_CollisionObjC.h"

#include "15_1_shot1C.h"
#include "21_sonaC.h"

class HeroObjC : public CollisionObjC
{
protected:
	double m_dSpriteSpeed;

	double m_dSpeedX;
	double m_dSpeedY;

	double m_dShotDelay;

	
	bool   m_bSonaSw;

public:
	sonaC  m_sona;

	bool Init() override;
	bool Frame() override;
	bool Render() override;
	bool Release() override;

	void addShort1(POINT mousePos);

	bool getSonaSw();

	list<shot1C> shot1_list;

public:
	HeroObjC();
	virtual ~HeroObjC();
};