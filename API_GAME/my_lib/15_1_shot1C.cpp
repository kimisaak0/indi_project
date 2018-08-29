#pragma once
#include "15_1_shot1C.h"

void shot1C::setSpeed(double sx, double sy)
{
	m_dSpeedX = sx;
	m_dSpeedY = sy;

	m_bExist = true;

	m_dSpriteSpeed = 0;
	m_iSpriteDir = 1;

}

void shot1C::setSpawn(double sx, double sy)
{
	m_ptSpawnPos.x = sx;
	m_ptSpawnPos.y = sy;
}





bool shot1C::Frame()
{
	m_dSpriteSpeed += g_dSecPerFrame * 0.1;

	if (m_dSpriteSpeed > 0.01) {
		m_dSpriteSpeed = 0;

		m_rtDraw.left += m_iSpriteDir * 30;
		if (m_rtDraw.left > 50 || m_rtDraw.left <= 20) {
			m_rtDraw.left = 20;
			//m_iSpriteDir *= -1;
		}
	}

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

dPointC shot1C::getSpawn()
{
	return m_ptSpawnPos;
}