#include "12_2_NpcObjC.h"

NpcObjC::NpcObjC()
{
	m_rtDraw.left = 96;
	m_dSpriteSpeed = 0;
	m_iSpriteIndex = 0;
	
	m_dirRand = Direction_N;
}

bool NpcObjC::Frame()
{

	m_dSpriteSpeed += g_dSecPerFrame * 0.1;


	if (m_dSpriteSpeed > 0.01) {
		m_dSpriteSpeed = 0;

		m_rtDraw.left += 32;
		if (m_rtDraw.left >= 161) {
			m_rtDraw.left = 96;
		}
	}




	m_dDirChgSpeed += g_dSecPerFrame * 0.1;
	if (m_dDirChgSpeed > 0.5) {
		m_dDirChgSpeed = 0;
		m_dirRand = (Direction) (rand() % 4);
	}
	

	Set(m_ptPosition.x, m_ptPosition.y, m_rtDraw.left, m_rtDraw.top, 32,  32);

	if (m_dirRand == Direction_N)
	{
		m_rtDraw.top = 96;
		m_ptPosition.y += -1 * g_dSecPerFrame*30.0f;
	}
	if (m_dirRand == Direction_S)
	{
		m_rtDraw.top = 0;
		m_ptPosition.y += 1 * g_dSecPerFrame*30.0f;
	}
	if (m_dirRand == Direction_W)
	{
		m_rtDraw.top = 32;
		m_ptPosition.x += -1 * g_dSecPerFrame*30.0f;
	}
	if (m_dirRand == Direction_E)
	{
		m_rtDraw.top = 64;
		m_ptPosition.x += 1 * g_dSecPerFrame*30.0f;
	}

	CollisionObjC::Frame();

	return true;
}

bool NpcObjC::Render()
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



NpcObjC::~NpcObjC()
{

}