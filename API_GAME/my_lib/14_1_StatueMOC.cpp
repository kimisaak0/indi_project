#pragma once
#include "14_1_StatueMOC.h"

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



	return true;
}
