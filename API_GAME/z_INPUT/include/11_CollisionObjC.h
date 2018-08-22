#pragma once

#include "08_ObjC.h"
#include "10_CollisionC.h"

class CollisionObjC : public ObjC
{
protected:
	RECT     m_rtCollision;
	
	double    m_dDirX;        //x ���Ⱚ : ��(-1), ��(+1)
	double    m_dDirY;        //y ���Ⱚ : ��(-1), ��(+1)
	
	double    m_dSpeedX;       //X �ӵ���
	double    m_dSpeedY;       //Y �ӵ���

	bool     m_bDebugRect;   //����� ��Ʈ

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
