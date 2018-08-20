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

	I_Timer.Render();
	I_Input.Render();

	HBITMAP old;

	BmpC* testBmp = new BmpC;

	testBmp->Load(L"../z_INPUT/data/50x50/topVeiw_Water_1.bmp");

	//I_Bmp.addBmp(L"test", testBmp);
	//I_Bmp.getBmp(L"test");

	BitBlt(g_hOffScreenDC,
		100, 100,
		50, 50,
		testBmp->m_hMemDC,
		0, 0,
		SRCCOPY
	);

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