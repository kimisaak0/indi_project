#include "15_1_shot1C.h"

void shot1C::setSpeed(double sx, double sy)
{
	m_dSpeedX = sx;
	m_dSpeedY = sy;

	m_bExist = true;
}


bool shot1C::Frame()
{
	if (m_bExist) {
		m_ptPosition.x += m_dSpeedX * g_dSecPerFrame * 500;
		m_ptPosition.y += m_dSpeedY * g_dSecPerFrame * 500;

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

bool shot1C::Render()
{
	if (m_bExist) {
		TransparentBlt(g_hOffScreenDC,
			m_ptPosition.x, m_ptPosition.y,
			m_rtDraw.right, m_rtDraw.bottom,
			m_pColorBmp->m_hMemDC,
			m_rtDraw.left, m_rtDraw.top,
			m_rtDraw.right, m_rtDraw.bottom,
			RGB(255, 255, 255)
		);
	}
	return true;
}