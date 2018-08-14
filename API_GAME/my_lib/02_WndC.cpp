#include "02_WndC.h"

//생성자에서 대입
HWND   g_hWnd;
RECT   g_rtWindow;
RECT   g_rtClient;


WndC::WndC(LPCWSTR LWndName)
{
	//윈도우 등록 및 생성에 실패하면 종료
	//assert() 값이 true면 넘어가고, false면 에러를 띄운다.
	bool debug = registWnd(LWndName);
	assert(debug); 

	GetWindowRect(m_hWnd, &m_rtWindow);
	GetWindowRect(m_hWnd, &m_rtClient);

	g_hWnd = m_hWnd;
	g_rtWindow = m_rtWindow;
	g_rtClient = m_rtClient;

}

//메시지 처리 함수
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

//윈도우 등록 및 생성
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

//윈도우 돌리기
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
////핸들을 반환
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