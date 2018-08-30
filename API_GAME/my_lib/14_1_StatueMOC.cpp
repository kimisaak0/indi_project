#pragma once
#include "14_1_StatueMOC.h"

StatueMOC::StatueMOC()
{
	m_iMaxHp = 1000;
	m_iCurrentHP = m_iMaxHp;
}

int StatueMOC::Hit()
{
	if (m_iCurrentHP > 0) {
		return --m_iCurrentHP;
	}
	else {
		return 0;
	}
}

bool StatueMOC::Frame()
{
	if (I_Input.Key('9') == KEY_DOWN) {
		m_bDebugRect = !m_bDebugRect;
	}


	m_ptDrawPosition.x = m_ptPosition.x + (m_rtDraw.right / 2);
	m_ptDrawPosition.y = m_ptPosition.y + (m_rtDraw.bottom / 2);

	m_rtCollision.left = m_ptDrawPosition.x - m_rtDraw.right / 3;
	m_rtCollision.top = m_ptDrawPosition.y;
	m_rtCollision.right = m_ptDrawPosition.x;
	m_rtCollision.bottom = m_ptDrawPosition.y + m_rtDraw.bottom / 2;

	//테스트용
	//m_rtCollision.left = m_ptDrawPosition.x - 10;
	//m_rtCollision.top = m_ptDrawPosition.y - m_rtDraw.bottom / 2;
	//m_rtCollision.right = m_ptDrawPosition.x + 10;
	//m_rtCollision.bottom = m_ptDrawPosition.y + m_rtDraw.bottom / 2;

	return true;
}

bool StatueMOC::Render()
{
	if (m_bExist) {
		//HP바 그리기
		HBRUSH myBrush = (HBRUSH)GetStockObject(DC_BRUSH);
		HBRUSH oldBrush = (HBRUSH)SelectObject(g_hOffScreenDC, myBrush);


		SetDCBrushColor(g_hOffScreenDC, RGB(0, 0, 0));
		Rectangle(g_hOffScreenDC, m_ptPosition.x, m_ptPosition.y - 7, m_ptPosition.x + 100, m_ptPosition.y - 2);

		SetDCBrushColor(g_hOffScreenDC, RGB(255,0,0));
		Rectangle(g_hOffScreenDC, m_ptPosition.x, m_ptPosition.y-7, m_ptPosition.x+(m_iCurrentHP*100/m_iMaxHp), m_ptPosition.y - 2);

		SelectObject(g_hOffScreenDC, oldBrush);
		DeleteObject(myBrush);

		//물체 그리기
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