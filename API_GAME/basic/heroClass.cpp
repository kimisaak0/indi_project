#include "heroClass.h"



heroClass::heroClass()
{
	m_rtDraw.left = 0;
}

bool heroClass::Frame()
{
	m_rtDraw.left += 32;
	if (m_rtDraw.left >= 65) {
		m_rtDraw.left = 0;
	}

	Set(m_pos.x, m_pos.y, m_rtDraw.left, m_rtDraw.top, 32, 30);

	if (I_Input.Key('W')) {
		m_rtDraw.top = 102;
		m_pos.y += -1 * g_dSecPerFrame * 300.0;
	}

	if (I_Input.Key('S')) {
		m_rtDraw.top = 0;
		m_pos.y += 1 * g_dSecPerFrame * 300.0;
	}

	if (I_Input.Key('A')) {
		m_rtDraw.top = 36;
		m_pos.x += -1 * g_dSecPerFrame * 300.0;
	}

	if (I_Input.Key('D')) {
		m_rtDraw.top = 69;
		m_pos.x += 1 * g_dSecPerFrame * 300.0;
	}

	if (I_Input.Key(VK_LBUTTON) == KEY_DOWN) {

	}
	return true;
}

bool heroClass::Render()
{
	TransparentBlt(g_hOffScreenDC,
		m_pos.x, m_pos.y,
		m_rtDraw.right, m_rtDraw.bottom,
		m_pColorBmp->m_hMemDC,
		m_rtDraw.left, m_rtDraw.top,
		m_rtDraw.right, m_rtDraw.bottom,
		RGB(255, 255, 255)
	);

	return true;
}


heroClass::~heroClass()
{
}
