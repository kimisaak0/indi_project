#pragma once
#include "14_1_StatueMOC.h"

StatueMOC::StatueMOC()
{
	m_iHP = 10000;
}

int StatueMOC::Hit()
{
	return --m_iHP;
}

bool StatueMOC::Frame()
{
	if (m_bExist) {

		if (I_Input.Key('9') == KEY_DOWN) {
			m_bDebugRect = !m_bDebugRect;
		}

		//중점 잡아주기
		m_ptDrawPosition.x = m_ptPosition.x + (m_rtDraw.right / 2);
		m_ptDrawPosition.y = m_ptPosition.y + (m_rtDraw.bottom / 2);

		//충돌영역 그리기 
		m_rtCollision.left = m_ptDrawPosition.x - m_rtDraw.right / 3;
		m_rtCollision.top = m_ptDrawPosition.y;
		m_rtCollision.right = m_ptDrawPosition.x;
		m_rtCollision.bottom = m_ptDrawPosition.y + m_rtDraw.bottom / 2;

		if (m_iHP <= 0) {
			m_bExist = false;
		}
	}
	return true;

}

bool StatueMOC::Render()
{
	if (m_bExist) {

		//HP바 그리기
		HBRUSH myBrush = (HBRUSH)GetStockObject(RGB(255,0,0));
		HBRUSH oldBrush = (HBRUSH)SelectObject(g_hOffScreenDC, myBrush);

		Rectangle(g_hOffScreenDC,
			m_rtDraw.left,
			m_rtDraw.top - 20,
			m_rtDraw.left + 10 * m_iHP,
			m_rtDraw.top - 5
		);

		SelectObject(g_hOffScreenDC, oldBrush);
		DeleteObject(myBrush);

		//이미지 그리기
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

	return true;

}