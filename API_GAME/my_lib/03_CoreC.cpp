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
// DC�� Ư���� ��κ� ������ ������ ��� ��ġ�ʹ� ������ �� �� DC�� ����.
// DC�� ����� ��Ʈ�� ��ü���� �׸��� �׷������� ȭ�鿡�� ��µ��� ����.
// �� �Լ��� ���� DC�� Memory DC��� ��.

bool CoreC::gameInit()
{
	I_Timer.Init();
	I_Input.Init();



	//nowBmp.Load(L"../z_INPUT/data/50x50/topVeiw_Water_1.bmp");

	//if (nowBmp.m_hBitmap == NULL) {
	//	MessageBox(g_hWnd, L"�̹��� �ε� ����", L"�̹��� �ε� ����", MB_OK);
	//	return false;
	//}




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

	nowBmp.m_hBitmap = (HBITMAP)LoadImage(g_hInst, L"../z_INPUT/data/50x50/topVeiw_Water_1.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

	if (nowBmp.m_hBitmap == NULL) {
		MessageBox(g_hWnd, L"�̹��� �ε� ����", L"�̹��� �ε� ����", MB_OK);
		return false;
	}

	I_Bmp.addBmp(L"1", &nowBmp);

	HBITMAP oldBmp = (HBITMAP)SelectObject(g_hOffScreenDC, I_Bmp.getBmp(L"1")->m_hBitmap);

	BitBlt(g_hOnScreenDC, 20, 20, 50, 50, g_hOffScreenDC, 0, 0, SRCCOPY);

	GamePostRender();

	return true;
}

bool CoreC::GamePostRender()
{
	BitBlt(m_hOnScreenDC, 20, 20, m_rtClient.right, m_rtClient.bottom, m_hOffScreenDC, 0, 0, SRCCOPY);
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