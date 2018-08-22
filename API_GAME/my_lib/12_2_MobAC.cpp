#include "12_2_MobAC.h"

MobAC::MobAC()
{
	m_rtDraw.left = 0;
	m_dSpriteSpeed = 0;
	m_iSpriteIndex = 0;
	
	m_dDirChg = 0;
	m_dMoveCycleSpeed = 0;

	m_dDirX = (rand() % 2) ? +1 : -1;
	m_dDirY = (rand() % 2) ? +1 : -1;

	m_dSpeedX = rand() % 30 + 15;
	m_dSpeedY = rand() % 30 + 15;
}

bool MobAC::Frame()
{
	//날개짓 파닥파닥
	m_dSpriteSpeed += g_dSecPerFrame * 0.1;

	if (m_dSpriteSpeed > 0.01) {
		m_dSpriteSpeed = 0;

		m_rtDraw.left += 32;
		if (m_rtDraw.left >= 65) {
			m_rtDraw.left = 0;
		}
	}

	//방향 전환 8방향!
	m_dDirChg += g_dSecPerFrame * 0.1;
	if (m_dDirChg > 0.5) {
		m_dDirChg = 0;

		m_dDirX = (rand() % 2) ? +1 : -1;
		m_dDirY = (rand() % 2) ? +1 : -1;

	if (m_dDirX == 1) {
		if (m_dDirY == 1) {
			m_dSpeedX >= m_dSpeedY ? m_rtDraw.top = 64 : m_rtDraw.top = 0;
		}
		else {
			m_dSpeedX >= m_dSpeedY ? m_rtDraw.top = 64 : m_rtDraw.top = 96;
		}
	}
	else {
		if (m_dDirY == 1) {
			m_dSpeedX >= m_dSpeedY ? m_rtDraw.top = 32 : m_rtDraw.top = 0;
		}
		else {
			m_dSpeedX >= m_dSpeedY ? m_rtDraw.top = 32 : m_rtDraw.top = 96;
		}
	}

		m_dSpeedX = rand() % 30 + 15;
		m_dSpeedY = rand() % 30 + 15;
	}

		m_ptPosition.x += m_dDirX * m_dSpeedX * g_dSecPerFrame;
		m_ptPosition.y += m_dDirY * m_dSpeedY * g_dSecPerFrame;





	//화면 밖으로 나가지마!
	if (m_rtCollision.right > g_rtClient.right)
	{
		m_dDirX *= -1.0f;
		m_ptPosition.x = g_rtClient.right - m_rtDraw.right;
	}
	if (m_rtCollision.bottom > g_rtClient.bottom)
	{
		m_dDirY *= -1.0f;
		m_ptPosition.y = g_rtClient.bottom - m_rtDraw.bottom;
	}
	if (m_rtCollision.left < g_rtClient.left)
	{
		m_dDirX *= -1.0f;
		m_ptPosition.x = g_rtClient.left;
	}
	if (m_rtCollision.top < g_rtClient.top)
	{
		m_dDirY *= -1.0f;
		m_ptPosition.y = g_rtClient.top;
	}

	Set(m_ptPosition.x, m_ptPosition.y, m_rtDraw.left, m_rtDraw.top, 32, 32);

	CollisionObjC::Frame();


	return true;
}

bool MobAC::Render()
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



MobAC::~MobAC()
{

}