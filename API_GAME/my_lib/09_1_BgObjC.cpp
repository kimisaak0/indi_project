#include "09_1_BgObjC.h"

BgObjC::BgObjC()
{
}

bool BgObjC::Render()
{
	int MaxX = GetSystemMetrics(SM_CXFULLSCREEN);
	int MaxY = GetSystemMetrics(SM_CYFULLSCREEN);

	for (int iX = 0; iX <= MaxX; iX += 50) {
		for (int iY = 0; iY <= MaxY; iY += 50) {
			BitBlt(g_hOffScreenDC, iX, iY, 50, 50, m_pColorBmp->m_hMemDC, m_rtDraw.left, m_rtDraw.top, SRCCOPY);
		}
	}

	return true;
}


BgObjC::~BgObjC()
{
}
