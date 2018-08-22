#include "12_1_HeroObjC.h"

HeroObjC::HeroObjC()
{
	m_rtDraw.left = 0;
	m_dSpriteSpeed = 0;
}

bool HeroObjC::Frame()
{

	m_dSpriteSpeed += g_dSecPerFrame * 0.1;

	if (m_dSpriteSpeed > 0.01) {
		m_dSpriteSpeed = 0;

		m_rtDraw.left += 32;
		if (m_rtDraw.left >= 65) {
			m_rtDraw.left = 0;
		}
	}

	Set(m_ptPosition.x, m_ptPosition.y, m_rtDraw.left, m_rtDraw.top, 32, 30);

	if (I_Input.Key('W'))
	{
		m_rtDraw.top = 102;
		m_ptPosition.y += -1 * g_dSecPerFrame*300.0f;
	}
	if (I_Input.Key('S'))
	{
		m_rtDraw.top = 0;
		m_ptPosition.y += 1 * g_dSecPerFrame*300.0f;
	}
	if (I_Input.Key('A'))
	{
		m_rtDraw.top = 36;
		m_ptPosition.x += -1 * g_dSecPerFrame*300.0f;
	}
	if (I_Input.Key('D'))
	{
		m_rtDraw.top = 69;
		m_ptPosition.x += 1 * g_dSecPerFrame*300.0f;
	}

	CollisionObjC::Frame();

	return true;
}

bool HeroObjC::Render()
{
	TransparentBlt(g_hOffScreenDC,
		m_ptPosition.x, m_ptPosition.y,
		m_rtDraw.right, m_rtDraw.bottom,
		m_pColorBmp->m_hMemDC,
		m_rtDraw.left, m_rtDraw.top,
		m_rtDraw.right, m_rtDraw.bottom,
		RGB(255, 255, 255)
	);

	return true;
}



HeroObjC::~HeroObjC()
{

}