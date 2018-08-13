#include "CoreC.h"


CoreC::CoreC(LPCWSTR LWndName) : WndC(LWndName)
{
	m_hOnScreenDC = GetDC(m_hWnd);

}

bool CoreC::gameInit()
{
	m_Timer.Init();

	//GetDC() <-> ReleaseDC()
	m_hOnScreenDC = GetDC(m_hWnd);

	//CreateCompatibleDC() <-> DeleteDC()
	// DC의 특성을 대부분 가지고 있지만 출력 장치와는 연결이 안 된 DC를 생성.
	// DC와 연결된 비트맵 객체에는 그림이 그려지지만 화면에는 출력되지 않음.
	// 이 함수로 만든 DC를 Memory DC라고 함.
	m_hOffScreenDC = CreateCompatibleDC(m_hOnScreenDC);

	return true;
}

bool CoreC::gameRun()
{
	return true;
}

bool CoreC::gameFrame()
{
	return true;
}

bool CoreC::gameRender()
{
	return true;
}

bool CoreC::gameRelease()
{
	return true;
}

bool CoreC::GamePreRender()
{
	return true;
}

bool CoreC::GamePostRender()
{
	return true;
}

HDC     CoreC::getOnDC()
{
	return m_hOnScreenDC;
}

HDC     CoreC::getOffDC()
{
	return m_hOffScreenDC;
}

CoreC::~CoreC()
{

}