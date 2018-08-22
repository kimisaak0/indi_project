#include "11_CollisionObjC.h"

CollisionObjC::CollisionObjC() 
{
	ObjC::ObjC();

	m_dDirX = 1.0f;
	m_dDirY = 1.0f;

	m_dSpeedX = 0;
	m_dSpeedY = 0;

	m_bDebugRect = false;
	m_bExist = false;
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
	ObjC::Render();

	if (m_bDebugRect)
	{
		int prevMode = SetROP2(g_hOffScreenDC, R2_XORPEN);
		Rectangle(g_hOffScreenDC,
			m_rtCollision.left,
			m_rtCollision.top,
			m_rtCollision.left + m_rtDraw.right,
			m_rtCollision.top + m_rtDraw.bottom);
		SetROP2(g_hOffScreenDC, prevMode);
	}
	return true;

}


RECT    CollisionObjC::getRtCls()
{
	return m_rtCollision;
}

CollisionObjC::~CollisionObjC()
{

}