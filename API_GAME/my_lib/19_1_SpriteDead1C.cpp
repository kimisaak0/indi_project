#pragma once

#include "19_1_SpriteDead1C.h"

SpriteDead1C::SpriteDead1C()
{
	m_rtDraw.left = 0;
	m_dSpriteSpeed = 0;

	m_bExist = true;

}

bool SpriteDead1C::Frame()
{
	if (m_bExist) {
		m_dSpriteSpeed += g_dSecPerFrame * 0.1;

		if (m_dSpriteSpeed > 0.1) {
			m_dSpriteSpeed = 0;

			m_rtDraw.left += 150;
			if (m_rtDraw.left >= 600) {
				m_bExist = false;
			}
		}
	}

	return true;

}

bool SpriteDead1C::Render()
{
	TransparentBlt(g_hOffScreenDC,
		m_ptPosition.x, m_ptPosition.y,
		100, 100,
		m_pColorBmp->m_hMemDC,
		m_rtDraw.left, m_rtDraw.top,
		m_rtDraw.right, m_rtDraw.bottom,
		RGB(255, 255, 255)
	);

	return true;

}


SpriteDead1C::~SpriteDead1C()
{

}