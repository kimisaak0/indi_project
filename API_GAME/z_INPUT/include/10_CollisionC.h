#pragma once
#include "01_header.h"


struct sphere
{
	POINT pCenter;
	double dRadius;
};

class collisionC : public  SingleMgr<collisionC>
{
	friend class SingleMgr<collisionC>;

public:
	bool RectInRect(RECT rtDesk, RECT rtSrc);
	bool RectInPt(RECT rtDesk, POINT pt);
	bool SphereInSphere(RECT rtDesk, RECT rtSrc);
	bool SphereInPt(RECT rtDesk, POINT pt);
	//bool SphereInPt(double Radius, POINT pt);


protected:
	collisionC();

public:
	virtual ~collisionC();
};

#define I_ClsMgr collisionC::GetInstance()

