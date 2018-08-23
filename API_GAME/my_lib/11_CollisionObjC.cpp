#include "11_CollisionObjC.h"

CollisionObjC::CollisionObjC() 
{
	ObjC::ObjC();

	m_dDirX = 1.0f;
	m_dDirY = 1.0f;

	m_dSpeedX = 0;
	m_dSpeedY = 0;

	m_bDebugRect = false;
	m_bExist = true;

	m_bMapCls = false;
	//m_bHorCls = false;
	//m_bVetCls = false;
}


void CollisionObjC::Set(double x, double y, DWORD left, DWORD top, DWORD right, DWORD bottom)
{
	ObjC::Set(x,y,left, top, right, bottom);

	m_rtCollision.left = m_ptDrawPosition.x - m_rtDraw.right / 2;
	m_rtCollision.top = m_ptDrawPosition.y - m_rtDraw.bottom / 2;
	m_rtCollision.right = m_ptDrawPosition.x + m_rtDraw.right / 2;
	m_rtCollision.bottom = m_ptDrawPosition.y + m_rtDraw.bottom / 2;


}


bool CollisionObjC::Frame()
{
	if (I_Input.Key('9') == KEY_DOWN) {
		m_bDebugRect = !m_bDebugRect;
	}


	m_ptDrawPosition.x = m_ptPosition.x + (m_rtDraw.right / 2);
	m_ptDrawPosition.y = m_ptPosition.y + (m_rtDraw.bottom / 2);

	m_rtCollision.left = m_ptDrawPosition.x - m_rtDraw.right / 2;
	m_rtCollision.top = m_ptDrawPosition.y - m_rtDraw.bottom / 2;
	m_rtCollision.right = m_ptDrawPosition.x + m_rtDraw.right / 2;
	m_rtCollision.bottom = m_ptDrawPosition.y + m_rtDraw.bottom / 2;



	return true;

}

bool CollisionObjC::Render()
{

	if (m_bDebugRect)
	{
		//int prevMode = SetROP2(g_hOffScreenDC, R2_XORPEN);
		Rectangle(g_hOffScreenDC,
			m_rtCollision.left,
			m_rtCollision.top,
			m_rtCollision.right,
			m_rtCollision.bottom);
		//SetROP2(g_hOffScreenDC, prevMode);
	}
	return true;

}


RECT    CollisionObjC::getRtCls()
{
	return m_rtCollision;
}

void    CollisionObjC::setExist(bool bExist)
{
	m_bExist = bExist;
}

void    CollisionObjC::setMapCls(bool bMapCls, RECT objRect)
{
	m_bMapCls = bMapCls;

	m_rtMapObj = objRect;

	m_rtOverlap.left = (m_rtCollision.left > objRect.left) ? m_rtCollision.left : objRect.left;
	m_rtOverlap.right = (m_rtCollision.right < objRect.right) ? m_rtCollision.right : objRect.right;
	m_rtOverlap.top = (m_rtCollision.top > objRect.top) ? m_rtCollision.top : objRect.top;
	m_rtOverlap.bottom = (m_rtCollision.bottom < objRect.bottom) ? m_rtCollision.bottom : objRect.bottom;

	//충돌영역 구했음
}

CollisionObjC::~CollisionObjC()
{

}