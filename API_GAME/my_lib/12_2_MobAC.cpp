#pragma once
#include "12_2_MobAC.h"

int MobAC::g_maxId = 0;

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

	m_iId = g_maxId++;

	m_dead.Load(L"../z_INPUT/data/50x50/explosion01.bmp");
}

bool MobAC::Init()
{
	CollisionObjC::Init();
	m_rtDraw.left = 0;
	m_dSpriteSpeed = 0;
	m_iSpriteIndex = 0;

	m_dDirChg = 0;
	m_dMoveCycleSpeed = 0;

	m_dDirX = (rand() % 2) ? +1 : -1;
	m_dDirY = (rand() % 2) ? +1 : -1;

	m_dSpeedX = rand() % 30 + 15;
	m_dSpeedY = rand() % 30 + 15;

	m_iId = g_maxId++;

	m_dead.Load(L"../z_INPUT/data/50x50/explosion01.bmp");

	return true;
}

bool MobAC::Frame()
{
	if (m_bExist) {

		//³¯°³Áþ ÆÄ´ÚÆÄ´Ú
		m_dSpriteSpeed += g_dSecPerFrame * 0.1;

		if (m_dSpriteSpeed > 0.01) {
			m_dSpriteSpeed = 0;

			m_rtDraw.left += 32;
			if (m_rtDraw.left >= 65) {
				m_rtDraw.left = 0;
			}
		}

		//¹æÇâ ÀüÈ¯ 8¹æÇâ!
		m_dDirChg += g_dSecPerFrame * 0.1;
		if (m_dDirChg > 0.5) {
			m_dDirChg = 0;

			m_dDirX = (rand() % 2) ? +1 : -1;
			m_dDirY = (rand() % 2) ? +1 : -1;

			if (m_dDirX == 1) {
				if (m_dDirY == 1) {
					m_dSpeedX <= m_dSpeedY ? m_rtDraw.top = 64 : m_rtDraw.top = 0;
				}
				else {
					m_dSpeedX <= m_dSpeedY ? m_rtDraw.top = 64 : m_rtDraw.top = 96;
				}
			}
			else {
				if (m_dDirY == 1) {
					m_dSpeedX <= m_dSpeedY ? m_rtDraw.top = 32 : m_rtDraw.top = 0;
				}
				else {
					m_dSpeedX <= m_dSpeedY ? m_rtDraw.top = 32 : m_rtDraw.top = 96;
				}
			}

			m_dSpeedX = rand() % 30 + 15;
			m_dSpeedY = rand() % 30 + 15;
		}

		m_ptPosition.x += m_dDirX * m_dSpeedX * g_dSecPerFrame;
		m_ptPosition.y += m_dDirY * m_dSpeedY * g_dSecPerFrame;


		//È­¸é ¹ÛÀ¸·Î ³ª°¡Áö¸¶!
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


		//¸Ê ¿ÀºêÁ§Æ®¶û ºÎµúÇû´Ù! ¹Ð¾î³»±â (»ìÂ¦ ¹ö±× ÀÖÀ½)
		if (m_bMapCls) {
			int iOverW = m_rtOverlap.right - m_rtOverlap.left; //Ãæµ¹ÇÑ ³ÐÀÌ
			int iOverH = m_rtOverlap.bottom - m_rtOverlap.top; //Ãæµ¹ÇÑ ³ôÀÌ
			//OK

		
			if (m_rtCollision.right >= m_rtMapObj.left && m_rtCollision.left <= m_rtMapObj.right) {
				if (m_dDirY > 0) { //À§¿¡¼­ ºÎµúÈû

					m_ptPosition.y -= iOverH;
				}
				else {             //¾Æ·¡¿¡¼­ ºÎµúÈû.
					m_ptPosition.y += iOverH;
				}
			}
			
			if (m_rtCollision.bottom >= m_rtMapObj.top && m_rtCollision.top <= m_rtMapObj.bottom) {
				if (m_dDirX > 0) { //¿ÞÂÊ¿¡¼­ ºÎµúÈû
					m_ptPosition.x -= iOverW;
				}
				else {             //¿À¸¥ÂÊ¿¡¼­ ºÎµúÈû
					m_ptPosition.x += iOverW;
				}
			}

  			m_dDirX *= -1.0f;
			m_dDirY *= -1.0f;


			m_bMapCls = false;
		}

		Set(m_ptPosition.x, m_ptPosition.y, m_rtDraw.left, m_rtDraw.top, 32, 32);

		CollisionObjC::Frame();

	}
	else {
		
		m_dead.Frame();
	}

	return true;
}

bool MobAC::Render()
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

		CollisionObjC::Render();
	}
	else {
		m_dead.Set(m_ptPosition.x, m_ptPosition.y, 0, 0, 150, 150);
		m_dead.Render();
	}
	return true;
}


dPointC MobAC::getPt()
{
	return m_ptPosition;
}



MobAC::~MobAC()
{
	m_dead.Release();
}