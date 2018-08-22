#pragma once

#include "08_ObjC.h"
#include "10_CollisionC.h"

class CollisionObjC : public ObjC
{
protected:
	RECT     m_rtCollision;
	
	float    m_fDirX;        //x ���Ⱚ : ��(-1), ��(+1)
	float    m_fDirY;        //y ���Ⱚ : ��(-1), ��(+1)

	float    m_fSpeed;       //�ӵ���

	bool     m_bDebugRect;   //����� ��Ʈ

public:
	virtual void Set(double x, double y, DWORD left, DWORD top, DWORD right, DWORD bottom) override;

	virtual bool Frame() override;
	virtual bool Render() override;

public:
	CollisionObjC();
	virtual ~CollisionObjC();

};
