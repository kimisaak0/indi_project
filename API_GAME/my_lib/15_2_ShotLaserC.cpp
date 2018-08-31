#include "15_2_ShotLaserC.h"

#define PI          3.141592654  

void ShotLaserC::setSpeed(double sx, double sy)
{
	m_dSpeedX = sx;
	m_dSpeedY = sy;

	m_bExist = true;

	m_dSpriteSpeed = 0;
	m_iSpriteDir = 1;

	m_dAngle = acos(sx / sqrt(sx*sx+sy*sy));

	m_dMaxDistance = sqrt(pow(m_rtDraw.right, 2) + pow(m_rtDraw.bottom, 2));
}

void ShotLaserC::setSpawn(double sx, double sy)
{
	m_ptSpawnPos.x = sx;
	m_ptSpawnPos.y = sy;
}

void	ShotLaserC::RotateBlt(float fAngle, HBITMAP hBitmap,
	BmpC* pSrcBitmap)
{
	HBRUSH hbrBack = CreateSolidBrush(RGB(255, 255, 255));

	double dRadian = m_dAngle * 3.141592f / 180.0f;
	double dCosine = cos(dRadian);
	double dSine = sin(dRadian);

	HBITMAP hOldBitmap = (HBITMAP)SelectObject(m_hRotationDC, hBitmap);
	HBRUSH hOldBrush = (HBRUSH)SelectObject(m_hRotationDC, hbrBack);
	PatBlt(m_hRotationDC, 0, 0, m_dMaxDistance, m_dMaxDistance, PATCOPY);
	SelectObject(m_hRotationDC, hOldBrush);

	int iOldGraphic = SetGraphicsMode(m_hRotationDC, GM_ADVANCED);

	XFORM xform;// x,y,1 * 3by2 = x,y,1, 동차
	xform.eM11 = dCosine; xform.eM12 = -dSine;
	xform.eM21 = dSine;	xform.eM22 = dCosine;
	xform.eDx = m_dMaxDistance / 2;
	xform.eDy = m_dMaxDistance / 2;

	SetWorldTransform(m_hRotationDC, &xform);

	BitBlt(m_hRotationDC,
		-(m_rtDraw.right / 2),
		-(m_rtDraw.bottom / 2),
		m_rtDraw.right,
		m_rtDraw.bottom,
		pSrcBitmap->m_hMemDC,
		m_rtDraw.left,
		m_rtDraw.top,
		SRCCOPY);

	BitBlt(pSrcBitmap->m_hMemDC,
		m_rtDraw.left, m_rtDraw.top,
		m_rtDraw.right, m_rtDraw.bottom,
		m_hRotationDC,
		m_rtDraw.left,
		m_rtDraw.top,
		SRCCOPY);


	//되돌려놓는 부분
	SelectObject(m_hRotationDC, hOldBitmap);
	SelectObject(m_hRotationDC, hOldBrush);
	xform.eM11 = 1; xform.eM12 = 0;
	xform.eM21 = 0;	xform.eM22 = 1;
	xform.eDx = 0;
	xform.eDy = 0;

	SetWorldTransform(m_hRotationDC, &xform);
	SetGraphicsMode(m_hRotationDC, iOldGraphic);

	

	DeleteObject(hbrBack);
}

bool ShotLaserC::Frame()
{

	if (m_bExist) {
		m_ptPosition.x += m_dSpeedX * g_dSecPerFrame * 400;
		m_ptPosition.y += m_dSpeedY * g_dSecPerFrame * 400;

		CollisionObjC::Frame();

		if (m_rtCollision.right > g_rtClient.right ||
			m_rtCollision.bottom > g_rtClient.bottom ||
			m_rtCollision.left < g_rtClient.left ||
			m_rtCollision.top < g_rtClient.top) {
			m_bExist = false;
		}
	}
	return true;
}

bool ShotLaserC::Render()
{	
	RotateBlt(m_dAngle, m_hRoateionBMP, m_pColorBmp);
	

	TransparentBlt(g_hOffScreenDC,
		m_ptPosition.x, m_ptPosition.y,
		m_rtDraw.right, m_rtDraw.bottom,
		m_pColorBmp->m_hMemDC,
		m_rtDraw.left, m_rtDraw.top,
		m_rtDraw.right, m_rtDraw.bottom,
		RGB(0, 0, 0)
	);

	return true;
}

dPointC ShotLaserC::getSpawn()
{
	return m_ptSpawnPos;
}