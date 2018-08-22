#pragma once

#include "08_ObjC.h"
#include "10_CollisionC.h"

class CollisionObjC : public ObjC
{
protected:
	RECT     m_rtCollision;
	
	double    m_dDirX;        //x 방향값 : 좌(-1), 우(+1)
	double    m_dDirY;        //y 방향값 : 상(-1), 하(+1)
	
	double    m_dSpeedX;       //X 속도값
	double    m_dSpeedY;       //Y 속도값

	bool     m_bDebugRect;   //디버그 렉트

public:
	virtual void Set(double x, double y, DWORD left, DWORD top, DWORD right, DWORD bottom) override;
	virtual bool Frame() override;
	virtual bool Render() override;

public:
	virtual RECT    getRtCls();

public:
	CollisionObjC();
	virtual ~CollisionObjC();

};
