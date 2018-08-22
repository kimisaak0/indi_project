#pragma once
#include "08_ObjC.h"

//__imp_TransparentBlt 사용
#pragma comment(lib, "msimg32.lib")

ObjC::ObjC()
{
	m_ptPosition.x = 0;
	m_ptPosition.y = 0;
	m_pColorBmp = nullptr;
	m_pMaskBmp = nullptr;
}

void ObjC::Set(double x, double y, DWORD left, DWORD top, DWORD right, DWORD bottom)
{

	m_rtDraw.left = left;
	m_rtDraw.top = top;
	m_rtDraw.right = right;
	m_rtDraw.bottom = bottom;

	m_ptPosition.x = x;
	m_ptPosition.y = y;

	m_ptDrawPostion.x = m_ptPosition.x - (m_rtDraw.right / 2);
	m_ptDrawPostion.y = m_ptPosition.y - (m_rtDraw.bottom / 2);
}

bool ObjC::Load(const TCHAR* pszColor, const TCHAR* pszMask)
{
	
	m_pColorBmp = I_Bmp.loadBmp(pszColor);
	if (pszMask != nullptr) {
		m_pMaskBmp = I_Bmp.loadBmp(pszMask);
	}
	return true;
}



bool ObjC::Init()
{
	return true;
}
bool ObjC::Frame()
{
	return true;
}
bool ObjC::Render()
{
	if (m_pMaskBmp == nullptr) {
		BitBlt(g_hOffScreenDC,
			m_ptPosition.x, m_ptPosition.y,
			m_rtDraw.right, m_rtDraw.bottom,
			m_pColorBmp->m_hMemDC,
			m_rtDraw.left, m_rtDraw.top,
			SRCCOPY
		);

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
	else {
		TransparentBlt(g_hOffScreenDC,
			m_ptPosition.x, m_ptPosition.y,
			m_rtDraw.right, m_rtDraw.bottom,
			m_pColorBmp->m_hMemDC,
			m_rtDraw.left, m_rtDraw.top,
			m_rtDraw.right, m_rtDraw.bottom,
			RGB(255, 255, 255)
		);



			BitBlt(g_hOffScreenDC,
				m_ptPosition.x, m_ptPosition.y,
				m_rtDraw.right, m_rtDraw.bottom,
				m_pMaskBmp->m_hMemDC,
				m_rtDraw.left, m_rtDraw.top,
				SRCAND
			); //AND연산

			BitBlt(g_hOffScreenDC,
				m_ptPosition.x, m_ptPosition.y,
				m_rtDraw.right, m_rtDraw.bottom,
				m_pColorBmp->m_hMemDC,
				m_rtDraw.left, m_rtDraw.top,
				SRCINVERT
			); //XOR연산

			BitBlt(g_hOffScreenDC,
				m_ptPosition.x, m_ptPosition.y,
				m_rtDraw.right, m_rtDraw.bottom,
				m_pMaskBmp->m_hMemDC,
				m_rtDraw.left, m_rtDraw.top,
				SRCINVERT
			); //XOR연산
	}
	return true;
}

bool ObjC::Release()
{
	return true;
}


ObjC::~ObjC()
{

}