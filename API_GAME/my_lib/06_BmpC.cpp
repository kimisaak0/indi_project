#pragma once
#include "06_BmpC.h"


BmpC::BmpC()
{
}


bool    BmpC::Load(T_STR szLoadFile)
{
	HDC hdc = GetDC(g_hWnd);

	m_hBitmap = (HBITMAP)LoadImage(
		g_hInst,
		szLoadFile.c_str(),
		IMAGE_BITMAP,
		0, 0,
		LR_DEFAULTSIZE | LR_LOADFROMFILE
	);

	if (m_hBitmap == NULL) {
		MessageBox(g_hWnd, L"이미지 로드 실패", L"이미지 로드 실패", MB_OK);
		return false;
	}
	else {
		GetObject(m_hBitmap, sizeof(BITMAP), &m_bmpInfo);
		m_hMemDC = CreateCompatibleDC(hdc);
		m_hOldBmp = (HBITMAP)SelectObject(m_hMemDC, m_hBitmap);
		m_szName = szLoadFile;
		ReleaseDC(g_hWnd, hdc);
		return true;
	}

	ReleaseDC(g_hWnd, hdc);
	return false;

}

bool    BmpC::Init()
{
	return true;
}

bool    BmpC::Frame()
{
	return true;
}

bool    BmpC::Render()
{
	return true;
}

bool    BmpC::Release()
{
	DeleteObject(m_hBitmap);
	ReleaseDC(g_hWnd, m_hMemDC);

	return true;
}

BmpC::~BmpC()
{
}
