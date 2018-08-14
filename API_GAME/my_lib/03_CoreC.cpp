#include "03_CoreC.h"

HDC g_hOnScreenDC;
HDC g_hOffScreenDC;


CoreC::CoreC(LPCWSTR LWndName) : WndC(LWndName)
{
	gameInit();

	m_hOnScreenDC = GetDC(m_hWnd);
	m_hOffScreenDC = CreateCompatibleDC(m_hOnScreenDC);

	g_hOnScreenDC = m_hOnScreenDC;
	g_hOffScreenDC = m_hOffScreenDC;
}


//GetDC() <-> ReleaseDC()
//CreateCompatibleDC() <-> DeleteDC()
// DC의 특성을 대부분 가지고 있지만 출력 장치와는 연결이 안 된 DC를 생성.
// DC와 연결된 비트맵 객체에는 그림이 그려지지만 화면에는 출력되지 않음.
// 이 함수로 만든 DC를 Memory DC라고 함.

bool CoreC::gameInit()
{
	I_Timer.Init();
	I_Input.Init();

	return true;
}

bool CoreC::gameFrame()
{
	I_Timer.Frame();
	I_Input.Frame();


	/*if (I_Input.Key(VK_LBUTTON) == KEY_DOWN) {
		MessageBox(NULL, L"윈도우가 떴다.", L"윈도우생성", MB_OK);
	}*/

	return true;
}

bool CoreC::GamePreRender()
{
	return true;
}

bool CoreC::gameRender()
{

	I_Timer.Render();

	I_Input.Render();


	return true;
}

bool CoreC::GamePostRender()
{
	return true;
}

bool CoreC::gameRelease()
{
	I_Timer.Release();
	I_Input.Release();

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