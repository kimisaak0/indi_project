#pragma once
#include "03_CoreC.h"

HDC g_hOnScreenDC;
HDC g_hOffScreenDC;

CoreC::CoreC(LPCWSTR LWndName) : WndC(LWndName)
{

	m_hOnScreenDC = GetDC(m_hWnd);
	m_hOffScreenDC = CreateCompatibleDC(m_hOnScreenDC);


	g_hOnScreenDC = m_hOnScreenDC;
	g_hOffScreenDC = m_hOffScreenDC;

	m_TimerSw = false;
}


//GetDC() <-> ReleaseDC()
//CreateCompatibleDC() <-> DeleteDC()
// DC의 특성을 대부분 가지고 있지만 출력 장치와는 연결이 안 된 DC를 생성.
// DC와 연결된 비트맵 객체에는 그림이 그려지지만 화면에는 출력되지 않음.
// 이 함수로 만든 DC를 Memory DC라고 함.

bool CoreC::gameInit()
{
	I_SoundMgr.Init();
	I_Timer.Init();
	I_Input.Init();
	Init();

	m_hOffBmp = CreateCompatibleBitmap(g_hOnScreenDC, m_rtClient.right, m_rtClient.bottom);
	SelectObject(m_hOffScreenDC, m_hOffBmp);

	COLORREF bgColor = RGB(0, 0, 0);
	m_hBrBack = CreateSolidBrush(bgColor);
	SelectObject(m_hOffScreenDC, m_hBrBack);

	I_SoundMgr.Load("../z_INPUT/data/sound/ui_sound8.ogg", false);
	I_SoundMgr.Load("../z_INPUT/data/sound/weapon_sound2.ogg", false);
	I_SoundMgr.Load("../z_INPUT/data/sound/Vampire_Bite.mp3",false);

	I_SoundMgr.Load("../z_INPUT/data/sound/Yung_Kartz_10_1400.mp3", false);

	return true;
}

bool CoreC::gameFrame()
{
	I_SoundMgr.Frame();
	I_Timer.Frame();
	I_Input.Frame();
	Frame();

	if (I_Input.Key('0') == KEY_DOWN) {
		m_TimerSw = !m_TimerSw;
	}

	return true;
}

bool CoreC::GamePreRender()
{
	PatBlt(m_hOffScreenDC, 0, 0, m_rtClient.right, m_rtClient.bottom, PATCOPY);
	return true;
}

bool CoreC::gameRender()
{
	GamePreRender();

	I_Input.Render();

	if (m_TimerSw) { 
		I_Timer.Render();
	}


	Render();

	GamePostRender();

	return true;
}

bool CoreC::GamePostRender()
{
	BitBlt(m_hOnScreenDC, 0, 0, m_rtClient.right, m_rtClient.bottom, m_hOffScreenDC, 0, 0, SRCCOPY);
	return true;
}

bool CoreC::gameRelease()
{
	I_SoundMgr.Release();
	I_Timer.Release();
	I_Input.Release();
	Release();

	DeleteObject(m_hBrBack);
	DeleteObject(m_hOffBmp);
	ReleaseDC(m_hWnd, m_hOnScreenDC);
	ReleaseDC(m_hWnd, m_hOffScreenDC);

	return true;
}

bool CoreC::gameRun()
{
	
	gameFrame();
	gameRender();

	return true;
}

//HDC     CoreC::getOnDC()
//{
//	return m_hOnScreenDC;
//}
//
//HDC     CoreC::getOffDC()
//{
//	return m_hOffScreenDC;
//}

CoreC::~CoreC()
{

}