#pragma once
#include "14_2_Rock1MOC.h"

bool Rock1MOC::Frame()
{
	if (I_Input.Key('9') == KEY_DOWN) {
		m_bDebugRect = !m_bDebugRect;
	}


	m_ptDrawPosition.x = m_ptPosition.x + (m_rtDraw.right / 2);
	m_ptDrawPosition.y = m_ptPosition.y + (m_rtDraw.bottom / 2);

	m_rtCollision.left = m_ptDrawPosition.x - m_rtDraw.right / 2;
	m_rtCollision.top = m_ptDrawPosition.y - m_rtDraw.bottom / 2;
	m_rtCollision.right = m_ptDrawPosition.x + m_rtDraw.right / 2;
	m_rtCollision.bottom = m_ptDrawPosition.y + m_rtDraw.bottom / 2;



	return true;
}