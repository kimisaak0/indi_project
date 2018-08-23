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

	return true;
}

bool CoreC::gameFrame()
{
	I_Timer.Frame();
	I_Input.Frame();


	/*if (I_Input.Key(VK_LBUTTON) == KEY_DOWN) {
		MessageBox(NULL, L"�����찡 ����.", L"���������", MB_OK);
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