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
	// DC�� Ư���� ��κ� ������ ������ ��� ��ġ�ʹ� ������ �� �� DC�� ����.
	// DC�� ����� ��Ʈ�� ��ü���� �׸��� �׷������� ȭ�鿡�� ��µ��� ����.
	// �� �Լ��� ���� DC�� Memory DC��� ��.
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