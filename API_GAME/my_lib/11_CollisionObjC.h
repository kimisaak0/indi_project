#pragma once

#include "08_ObjC.h"
#include "10_CollisionC.h"

class CollisionObjC : public ObjC
{
protected:
	RECT      m_rtCollision;
	
	double    m_dDirX;        //x ���Ⱚ : ��(-1), ��(+1)
	double    m_dDirY;        //y ���Ⱚ : ��(-1), ��(+1)
	
	double    m_dSpeedX;       //X �ӵ���
	double    m_dSpeedY;       //Y �ӵ���

	bool      m_bDebugRect;   //����� ��Ʈ

	bool      m_bMapCls;      //�� ������Ʈ�� �浹
	//bool      m_bVetCls;      //���� �浹
	//bool      m_bHorCls;       //���� �浹

	RECT      m_rtMapObj;     //�浹�� �簢��
	RECT      m_rtOverlap;    //������ �簢��

public:
	virtual void Set(double x, double y, DWORD left, DWORD top, DWORD right, DWORD bottom) override;
	virtual bool Frame() override;
	virtual bool Render() override;

public:
	virtual RECT    getRtCls();
	virtual bool    getExist();

	virtual void    setExist(bool bExist);
	virtual void    setMapCls(bool bMapCls, RECT objRect);

public:
	CollisionObjC();
	virtual ~CollisionObjC();

};
