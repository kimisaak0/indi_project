#include "11_CollisionObjC.h"

CollisionObjC::CollisionObjC() 
{
	ObjC::ObjC();

	m_fDirX = 1.0f;
	m_fDirY = 1.0f;

	m_fSpeed = 100.0f;

	m_bDebugRect = false;
	m_bExist = false;
}


void CollisionObjC::Set(double x, double y, DWORD left, DWORD top, DWORD right, DWORD bottom)
{
	ObjC::Set(x,y,left, top, right, bottom);

	m_fDirX = (rand() % 2) ? 1.0f : -1.0f;
	m_fDirY = (rand() % 2) ? 1.0f : -1.0f;

	m_rtCollision.left = m_ptDrawPostion.x;
	m_rtCollision.top = m_ptDrawPostion.y;
	m_rtCollision.right = m_rtCollision.left + m_rtDraw.right;
	m_rtCollision.bottom = m_rtCollision.top + m_rtDraw.bottom;


}


bool CollisionObjC::Frame()
{

	m_ptDrawPostion.x = m_ptPosition.x - (m_rtDraw.right / 2);
	m_ptDrawPostion.y = m_ptPosition.y - (m_rtDraw.bottom / 2);

	m_rtCollision.left = m_ptDrawPostion.x;
	m_rtCollision.top = m_ptDrawPostion.y;
	m_rtCollision.right = m_rtCollision.left + m_rtDraw.right;
	m_rtCollision.bottom = m_rtCollision.top + m_rtDraw.bottom;

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


CollisionObjC::~CollisionObjC()
{

}