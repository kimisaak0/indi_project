#include "02_WndC.h"

//�����ڿ��� ����
HWND   g_hWnd;
RECT   g_rtWindow;
RECT   g_rtClient;


WndC::WndC(LPCWSTR LWndName)
{
	//������ ��� �� ������ �����ϸ� ����
	//assert() ���� true�� �Ѿ��, false�� ������ ����.
	bool debug = registWnd(LWndName);
	assert(debug); 

	GetWindowRect(m_hWnd, &m_rtWindow);
	GetWindowRect(m_hWnd, &m_rtClient);

	g_hWnd = m_hWnd;
	g_rtWindow = m_rtWindow;
	g_rtClient = m_rtClient;

}

//�޽��� ó�� �Լ�
LRESULT CALLBACK WndC::MsgProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	switch (iMsg) {
		case WM_CREATE: {

		}break;

		case WM_DESTROY: {
			PostQuitMessage(0);
		}break;
	}

	return DefWindowProc(hWnd, iMsg, wParam, lParam);
}

//������ ��� �� ����
bool WndC::registWnd(LPCWSTR LWndName)
{
	ZeroMemory(&m_wndC, sizeof(WNDCLASSEX));

	m_wndC.cbSize = sizeof(WNDCLASSEX);
	m_wndC.hInstance = g_hInst;
	m_wndC.lpfnWndProc = MsgProc;
	m_wndC.lpszClassName = LWndName;
	m_wndC.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);

	if (!RegisterClassEx(&m_wndC)) {
		return false;
	}

	m_hWnd = CreateWindowEx(WS_EX_APPWINDOW,
		m_wndC.lpszClassName, m_wndC.lpszClassName,
		WS_OVERLAPPEDWINDOW,
		0, 0,
		GetSystemMetrics(SM_CXFULLSCREEN),
		GetSystemMetrics(SM_CYFULLSCREEN),
		NULL, NULL, g_hInst, NULL
	);

	if (m_hWnd == NULL) {
		return false;
	}

	ShowWindow(m_hWnd, SW_SHOW);

	return true;
}

//������ ������
bool WndC::runWindow()
{
	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));

	while (true) {
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);

			if (msg.message == WM_QUIT) {
				break;
			}
		}
		else {
			gameRun();
		}
	}

	return gameRelease();
}

//
////�ڵ��� ��ȯ
//HWND WndC::getHandle()
//{
//	return m_hWnd;
//}
//
//RECT WndC::getClient()
//{
//	GetWindowRect(m_hWnd, &m_rtClient);
//	return m_rtClient;
//}
//
//RECT WndC::getWindow()
//{
//	GetWindowRect(m_hWnd, &m_rtWindow);
//	return m_rtWindow;
//}


WndC::~WndC()
{

}