#include "09_1_BgObjC.h"

BgObjC::BgObjC()
{

}

bool BgObjC::FadeIn()
{
	m_dAlpha = 0;

	m_dAlpha += g_dSecPerFrame * 30;
	if (m_dAlpha > 255) return true;

	static BLENDFUNCTION blend;
	blend.BlendOp = AC_SRC_OVER;
	blend.BlendFlags = 0;
	blend.SourceConstantAlpha = m_dAlpha;
	blend.AlphaFormat = AC_SRC_OVER;

	::AlphaBlend(g_hOffScreenDC,
		m_ptDrawPosition.x, m_ptDrawPosition.y,
		m_rtDraw.right, m_rtDraw.bottom,
		m_pColorBmp->m_hMemDC,
		m_rtDraw.left,
		m_rtDraw.top,
		m_rtDraw.right,
		m_rtDraw.bottom,
		blend);
	return false;
}

bool BgObjC::FadeOut()
{
	m_dAlpha = 255;
	m_dAlpha -= g_dSecPerFrame * 30;
	if (m_dAlpha < 0) return true;

	static BLENDFUNCTION blend;
	blend.BlendOp = AC_SRC_OVER;
	blend.BlendFlags = 0;
	blend.SourceConstantAlpha = m_dAlpha;
	blend.AlphaFormat = AC_SRC_OVER;

	::AlphaBlend(g_hOffScreenDC,
		m_ptDrawPosition.x, m_ptDrawPosition.y,
		m_rtDraw.right, m_rtDraw.bottom,
		m_pColorBmp->m_hMemDC,
		m_rtDraw.left,
		m_rtDraw.top,
		m_rtDraw.right,
		m_rtDraw.bottom,
		blend);
	return false;
}


bool BgObjC::Render()
{
	int MaxX = GetSystemMetrics(SM_CXFULLSCREEN);
	int MaxY = GetSystemMetrics(SM_CYFULLSCREEN);

	switch (m_iID) {
		case 0: {
			TransparentBlt(g_hOffScreenDC,
				0, 0,
				MaxX, MaxY,
				m_pColorBmp->m_hMemDC,
				m_rtDraw.left, m_rtDraw.top,
				m_rtDraw.right, m_rtDraw.bottom,
				RGB(255, 255, 255)
			);

		} break;

		case 1: {

			for (int iX = 0; iX <= MaxX; iX += 50) {
				for (int iY = 0; iY <= MaxY; iY += 50) {
					BitBlt(g_hOffScreenDC, iX, iY, 50, 50, m_pColorBmp->m_hMemDC, m_rtDraw.left, m_rtDraw.top, SRCCOPY);
				}
			}
		} break;
	}

	return true;
}


BgObjC::~BgObjC()
{
}
