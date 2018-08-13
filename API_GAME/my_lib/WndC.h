#pragma once

#include "header.h"

class wndC
{
private:
	WNDCLASSEX   m_wndC;        //윈도우 클래스
	HWND         m_hWnd;        //윈도우 핸들
	LPCWSTR      m_lWndName;    //윈도우 이름

private:
	RECT         m_rtClient;    //생성된 윈도우의 작업영역 크기.
	RECT         m_rtWindow;    //생성된 윈도우의 전체영역 크기

	//메시지 처리 함수
	static LRESULT CALLBACK MsgProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
	bool registWnd(LPCWSTR LWndName);   //윈도우 등록 ... 생성자에서 호출함.

public:
	bool runWindow();                   //내용 돌리기

public:
	virtual bool Init();
	virtual bool Frame();
	virtual bool Render();
	virtual bool Release();

public:
	HWND getHandle();                   //윈도우 핸들 반환
	RECT getClient();
	RECT getWindow();

public:
	wndC(LPCWSTR LWndName);
	virtual ~wndC();
};