#pragma once
#include "08_ObjC.h"

//__imp_TransparentBlt 사용
#pragma comment(lib, "msimg32.lib")

ObjC::ObjC()
{
	m_pos.x = 0;
	m_pos.y = 0;
	m_pColorBmp = nullptr;
	m_pMaskBmp = nullptr;
}

void ObjC::Set(dPointC pos)
{
	m_pos = pos;
}

void ObjC::Set(double x, double y, DWORD left, DWORD top, DWORD right, DWORD bottom)
{
	m_pos.x = x;
	m_pos.y = y;
	m_rtDraw.left = left;
	m_rtDraw.top = top;
	m_rtDraw.right = right;
	m_rtDraw.bottom = bottom;
}

bool ObjC::Load(const TCHAR* pszColor, const TCHAR* pszMask)
{
	
	m_pColorBmp = I_Bmp.loadBmp(pszColor);
	if (pszMask != nullptr) {
		m_pMaskBmp = I_Bmp.loadBmp(pszMask);
	}
	return true;
}

bool ObjC::Draw(short sType, RECT* pRt)
{
	RECT rtDraw = m_rtDraw;
	if (pRt != nullptr) {
		rtDraw = *pRt;
	}

	switch (sType) {
		case LR_ROTATION: {
			StretchBlt(g_hOffScreenDC,
				m_pos.x + rtDraw.right, m_pos.y,
				-rtDraw.right, rtDraw.bottom,
				m_pColorBmp->m_hMemDC,
				rtDraw.left, rtDraw.top,
				rtDraw.right, rtDraw.bottom,
				SRCCOPY
			);
		}break;

		case TB_ROTATION: {
			StretchBlt(g_hOffScreenDC,
				m_pos.x, m_pos.y + rtDraw.bottom,
				rtDraw.right, -rtDraw.bottom,
				m_pColorBmp->m_hMemDC,
				rtDraw.left, rtDraw.top,
				rtDraw.right, rtDraw.bottom,
				SRCCOPY
			);
		}break;

		case LRTB_ROTATION: {
			StretchBlt(g_hOffScreenDC,
				m_pos.x + rtDraw.right, m_pos.y + rtDraw.bottom,
				-rtDraw.right, -rtDraw.bottom,
				m_pColorBmp->m_hMemDC,
				rtDraw.left, rtDraw.top,
				rtDraw.right, rtDraw.bottom,
				SRCCOPY
			);
		}break;

		default: {
			StretchBlt(g_hOffScreenDC,
				m_pos.x, m_pos.y,
				rtDraw.right, rtDraw.bottom,
				m_pColorBmp->m_hMemDC,
				rtDraw.left, rtDraw.top,
				rtDraw.right, rtDraw.bottom,
				SRCCOPY
			);
		}break;

	}
	return true;
}
bool ObjC::DrawColorKey(DWORD maskColor)
{
	TransparentBlt(g_hOffScreenDC,
		m_pos.x, m_pos.y,
		m_rtDraw.right, m_rtDraw.bottom,
		m_pColorBmp->m_hMemDC,
		m_rtDraw.left, m_rtDraw.top,
		m_rtDraw.right, m_rtDraw.bottom,
		maskColor
	);
	return true;
}


bool ObjC::Init()
{
	return true;
}
bool ObjC::Frame()
{
	if (I_Input.Key('W')) {
		m_pos.y += -1 * g_dSecPerFrame * 300.0;
	}

	if (I_Input.Key('S')) {
		m_pos.y += 1 * g_dSecPerFrame * 300.0;
	}

	if (I_Input.Key('A')) {
		m_pos.x += -1 * g_dSecPerFrame * 300.0;
	}

	if (I_Input.Key('D')) {
		m_pos.x += 1 * g_dSecPerFrame * 300.0;
	}

	return true;
}
bool ObjC::Render()
{
	if (m_pMaskBmp == nullptr) {
		BitBlt(g_hOffScreenDC,
			m_pos.x, m_pos.y,
			m_rtDraw.right, m_rtDraw.bottom,
			m_pColorBmp->m_hMemDC,
			m_rtDraw.left, m_rtDraw.top,
			SRCCOPY
		);

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
	else {
		TransparentBlt(g_hOffScreenDC,
			m_pos.x, m_pos.y,
			m_rtDraw.right, m_rtDraw.bottom,
			m_pColorBmp->m_hMemDC,
			m_rtDraw.left, m_rtDraw.top,
			m_rtDraw.right, m_rtDraw.bottom,
			RGB(255, 255, 255)
		);



			BitBlt(g_hOffScreenDC,
				m_pos.x, m_pos.y,
				m_rtDraw.right, m_rtDraw.bottom,
				m_pMaskBmp->m_hMemDC,
				m_rtDraw.left, m_rtDraw.top,
				SRCAND
			); //AND연산

			BitBlt(g_hOffScreenDC,
				m_pos.x, m_pos.y,
				m_rtDraw.right, m_rtDraw.bottom,
				m_pColorBmp->m_hMemDC,
				m_rtDraw.left, m_rtDraw.top,
				SRCINVERT
			); //XOR연산

			BitBlt(g_hOffScreenDC,
				m_pos.x, m_pos.y,
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