#pragma once

#include "21_sonaC.h"

sonaC::sonaC()
{
	m_dRad = 0;
}

void sonaC::setPos(dPointC pt)
{
	m_ptPosition.x = pt.x;
	m_ptPosition.y = pt.y;
}

bool sonaC::Frame()
{
	if (I_Input.Key('9') == KEY_DOWN) {
		m_bDebugRect = !m_bDebugRect;
	}

	m_ptDrawPosition.x = m_ptPosition.x;
	m_ptDrawPosition.y = m_ptPosition.y;

	m_dSpriteSpeed += g_dSecPerFrame * 0.1;

	if (m_dSpriteSpeed > 0.01) {
		m_dSpriteSpeed = 0;

		m_rtDraw.left += 250;
		if (m_rtDraw.left >= 751) {
			m_rtDraw.left = 0;
		}
	}

	switch (m_rtDraw.left) {
		case 0: {
			m_dRad = 40;
		}break;

		case 250: {
			m_dRad = 70;
		}break;

		case 500: {
			m_dRad = 90;
		}break;
	}

	m_rtCollision.left = m_ptDrawPosition.x - m_dRad;
	m_rtCollision.top = m_ptDrawPosition.y - m_dRad;
	m_rtCollision.right = m_ptDrawPosition.x + m_dRad;
	m_rtCollision.bottom = m_ptDrawPosition.y + m_dRad;

	return true;
}

bool sonaC::Render()
{
	TransparentBlt(g_hOffScreenDC,
		m_ptPosition.x-125, m_ptPosition.y-125,
		m_rtDraw.right, m_rtDraw.bottom,
		m_pColorBmp->m_hMemDC,
		m_rtDraw.left, m_rtDraw.top,
		m_rtDraw.right, m_rtDraw.bottom,
		RGB(255, 255, 255)
	);

	CollisionObjC::Render();

	return true;
}

sonaC::~sonaC()
{

}