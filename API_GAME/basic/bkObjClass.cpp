#include "bkObjClass.h"



bkObjClass::bkObjClass()
{
}

bool bkObjClass::Render()
{
	for (int iX = 0; iX <= 800; iX += 50) {
		for (int iY = 0; iY <= 600; iY += 50) {
			BitBlt(g_hOffScreenDC, iX, iY, 50, 50, m_pColorBmp->m_hMemDC, m_rtDraw.left, m_rtDraw.top, SRCCOPY);
		}
	}

	return true;
}


bkObjClass::~bkObjClass()
{
}
